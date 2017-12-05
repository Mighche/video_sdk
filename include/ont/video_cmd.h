
#ifndef _ONT_VIDEO_CMD_H_
#define _ONT_VIDEO_CMD_H_

# ifdef __cplusplus
extern "C" {
# endif


/**��̨���� */
typedef enum _t_ont_video_ptz_cmd
{
    C_ONT_VIDEO_ZOOM_IN = 1,        /**<������(���ʱ��)?*/
    C_ONT_VIDEO_ZOOM_OUT = 2,       /**<�����С(���ʱ�С)?*/
    C_ONT_VIDEO_FOCUS_IN = 3,       /**<����ǰ��*/
    C_ONT_VIDEO_FOCUS_OUT = 4,      /**<������*/
    C_ONT_VIDEO_IRIS_ENLARGE = 5,   /**<��Ȧ����*/
    C_ONT_VIDEO_IRIS_SHRINK = 6,    /**<��Ȧ��С*/
    C_ONT_VIDEO_TILT_UP = 11,       /**<��̨����*/
    C_ONT_VIDEO_TILT_DOWN = 12,     /**<��̨����*/
    C_ONT_VIDEO_PAN_LEFT = 13,      /**<��̨��ת*/
    C_ONT_VIDEO_PAN_RIGHT = 14,     /**<��̨��ת*/
    C_ONT_VIDEO_PAN_AUTO = 22       /**<��̨��SS���ٶ������Զ�ɨ��*/
}t_ont_video_ptz_cmd;



/************************************************************************/
/*@brief ��ʼֱ��                                                      */
/*@param dev        �豸ָ��                                           */
/*@param channel    ͨ����                                             */
/*@param push_url   ���͵�ַ                                           */
/*@param deviceid   �豸ID                                             */
/************************************************************************/
typedef int(*t_ont_video_live_stream_start)(void *dev, int channel, const char *push_url, const char* deviceid);

/************************************************************************/
/*@brief ����ֱ����������                                                  */
/*@param dev        �豸ָ��                                           */
/*@param channel    ͨ����                                             */
/*@param stream     1 ������2 ���壬3 ���壬 4 ����                    */
/************************************************************************/
typedef int(*t_ont_video_live_stream_ctrl)(void *dev, int channel, int stream);

  
/*************************************************************************/
/*@brief ָ֪ͨ����ͨ�����ɹؼ�֡                                       */
/*@param dev        �豸ָ��                                           */
/*@param channel    ͨ����                                             */
/************************************************************************/
typedef int(*t_ont_video_stream_make_keyframe)(void *dev, int channel);



/*************************************************************************/
/*@brief ��̨����                                       */
/*@param dev        �豸ָ��                                           */
/*@param channel    ͨ����                                             */
/*@param stop   0 ��ʼ���ƣ�1 ֹͣ����, 2 ����                         */
/*@param cmd    ��������                                               */   
/*@param speed  speed ��̨�ٶ� [1-7], 1��ʾ���                        */   
typedef int(*t_ont_video_dev_ptz_ctrl)(void *dev, int channel, int mode, t_ont_video_ptz_cmd cmd, int speed);


/*************************************************************************/
/*@brief Զ���ļ���ѯ                                                    */
/*@param dev        �豸ָ��                                             */
/*@param channel    ͨ����                                               */
/*@param pageindex  ҳ��, ��1��ʼ                                        */
/*@param max        ��ҳ���ص��������                                   */   
typedef int(*t_ont_video_dev_query_files)(void *dev, int channel, int startindex, int max, t_ont_video_file **files, int *filenum, int *totalnum);


/************************************************************************/
/*@brief ��ʼһ·��Ƶ�ط�                                              */
/*@param dev        �豸ָ��                                           */
/*@param channel    ͨ����                                             */
/*@param fileinfo   ָʾһ����ʼʱ��ͽ���ʱ����ļ���Ϣ                 */
/*@param playflag   �ļ��Ļطű�ʾ                                       */
/*@return 0         �ҵ��ط��ļ��������ط�����                           */
/************************************************************************/
typedef int(*t_ont_video_vod_start_notify)(void *dev, t_ont_video_file *fileinfo, const char *playflag, const char*pushurl);


typedef struct _t_ont_dev_video_callbacks
{
    t_ont_video_live_stream_ctrl      stream_ctrl;
    t_ont_video_live_stream_start     live_start;
    t_ont_video_stream_make_keyframe  make_keyframe;
    t_ont_video_dev_ptz_ctrl          ptz_ctrl;
    t_ont_video_vod_start_notify      vod_start;
    t_ont_video_dev_query_files       query;
}t_ont_dev_video_callbacks;



int ont_videocmd_handle(void *dev, void*cmd, t_ont_dev_video_callbacks *cb);



# ifdef __cplusplus
}
# endif


#endif /*_ONT_VIDEO_CMD_H_*/


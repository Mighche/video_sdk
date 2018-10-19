#ifndef ONT_INCLUDE_PLATFORM_CMD_H_
#define ONT_INCLUDE_PLATFORM_CMD_H_

# ifdef __cplusplus
extern "C" {
# endif


/**��̨���� */
typedef enum _t_ont_video_ptz_cmd {
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
} t_ont_video_ptz_cmd;


/************************************************************************/
/*@brief ����ֱ����������,                                                */
/*@param dev        �豸ָ��                                           */
/*@param channel    ͨ����                                             */
/*@param stream     1 ������2 ���壬3 ���壬 4 ����                    */
/************************************************************************/
typedef int32_t(*t_ont_cmd_live_stream_ctrl)(void *dev, int32_t channel, int32_t stream);



/*************************************************************************/
/*@brief ��̨����                                       */
/*@param dev        �豸ָ��                                           */
/*@param channel    ͨ����                                             */
/*@param stop   0 ��ʼ���ƣ�1 ֹͣ����, 2 ����                         */
/*@param cmd    ��������                                               */
/*@param speed  speed ��̨�ٶ� [1-7], 1��ʾ���                        */
typedef int32_t(*t_ont_cmd_dev_ptz_ctrl)(void *dev, int32_t channel, int32_t mode, t_ont_video_ptz_cmd ptz, int32_t speed);


/*************************************************************************/
/*@brief Զ���ļ���ѯ                                                    */
/*@param dev        �豸ָ��                                             */
/*@param channel    ͨ����                                               */
/*@param pageindex  ҳ��, ��1��ʼ                                        */
/*@param max        ��Ҳ���ص��������                                   */
typedef int32_t(*t_ont_cmd_dev_query_files)(void *dev, int32_t channel, int32_t startindex, int32_t max, const char *starTime, const char *endTime, ont_video_file_t **files, int32_t *filenum, int32_t *totalnum);




struct _ont_cmd_callbacks_t {
	t_ont_cmd_live_stream_ctrl      stream_ctrl;
	t_ont_cmd_dev_ptz_ctrl          ptz_ctrl;
	t_ont_cmd_dev_query_files       query;
};


int32_t ont_videocmd_handle(void *dev, ont_device_cmd_t *cmd);



# ifdef __cplusplus
}
# endif


#endif /*ONT_INCLUDE_PLATFORM_CMD_H_*/


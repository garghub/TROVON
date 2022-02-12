int
pipe_write_header(int pipe_fd, char indicator, int length)
{
guchar header[1+3];
g_assert(length <= SP_MAX_MSG_LEN);
header[0] = indicator;
header[1] = (length >> 16) & 0xFF;
header[2] = (length >> 8) & 0xFF;
header[3] = (length >> 0) & 0xFF;
return write(pipe_fd, header, sizeof header);
}
void
pipe_write_block(int pipe_fd, char indicator, const char *msg)
{
int ret;
int len;
if(msg != NULL) {
len = (int) strlen(msg) + 1;
} else {
len = 0;
}
ret = pipe_write_header(pipe_fd, indicator, len);
if(ret == -1) {
return;
}
if(len) {
ret = (int) write(pipe_fd, msg, len);
if(ret == -1) {
return;
}
} else {
}
}
void
sync_pipe_errmsg_to_parent(int pipe_fd, const char *error_msg,
const char *secondary_error_msg)
{
pipe_write_header(pipe_fd, SP_ERROR_MSG, (int) (strlen(error_msg) + 1 + 4 + strlen(secondary_error_msg) + 1 + 4));
pipe_write_block(pipe_fd, SP_ERROR_MSG, error_msg);
pipe_write_block(pipe_fd, SP_ERROR_MSG, secondary_error_msg);
}

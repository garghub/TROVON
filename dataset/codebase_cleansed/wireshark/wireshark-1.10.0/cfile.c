void
cap_file_init(capture_file *cf)
{
memset(cf, 0, sizeof(capture_file));
cf->snap = WTAP_MAX_PACKET_SIZE;
}

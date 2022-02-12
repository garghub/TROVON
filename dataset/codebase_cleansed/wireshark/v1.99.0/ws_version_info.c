const char *
get_ws_vcs_version_info(void)
{
#ifdef GITVERSION
return VERSION " (" GITVERSION " from " GITBRANCH ")";
#else
return VERSION;
#endif
}

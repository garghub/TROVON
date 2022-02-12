enum ia_css_err
ia_css_get_version(char *version, int max_size)
{
if (max_size <= (int)strlen(CSS_VERSION_STRING) + (int)strlen(sh_css_get_fw_version()) + 5)
return IA_CSS_ERR_INVALID_ARGUMENTS;
strcpy(version, CSS_VERSION_STRING);
strcat(version, "FW:");
strcat(version, sh_css_get_fw_version());
strcat(version, "; ");
return IA_CSS_SUCCESS;
}

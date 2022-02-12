const char *AES_options(void) {
#ifdef FULL_UNROLL
return "aes(full)";
#else
return "aes(partial)";
#endif
}

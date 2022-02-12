int cmd_version(int argc __maybe_unused, const char **argv __maybe_unused,\r\nconst char *prefix __maybe_unused)\r\n{\r\nprintf("perf version %s\n", perf_version_string);\r\nreturn 0;\r\n}

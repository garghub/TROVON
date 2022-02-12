u32 aa_alloc_sid(void)\r\n{\r\nu32 sid;\r\nspin_lock(&sid_lock);\r\nsid = (++global_sid);\r\nspin_unlock(&sid_lock);\r\nreturn sid;\r\n}\r\nvoid aa_free_sid(u32 sid)\r\n{\r\n;\r\n}

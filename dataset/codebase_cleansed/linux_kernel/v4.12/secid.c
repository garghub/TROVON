u32 aa_alloc_secid(void)\r\n{\r\nu32 secid;\r\nspin_lock(&secid_lock);\r\nsecid = (++global_secid);\r\nspin_unlock(&secid_lock);\r\nreturn secid;\r\n}\r\nvoid aa_free_secid(u32 secid)\r\n{\r\n;\r\n}

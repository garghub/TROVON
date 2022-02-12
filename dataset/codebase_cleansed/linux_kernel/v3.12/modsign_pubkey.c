static __init int module_verify_init(void)
{
pr_notice("Initialise module verification\n");
modsign_keyring = keyring_alloc(".module_sign",
KUIDT_INIT(0), KGIDT_INIT(0),
current_cred(),
((KEY_POS_ALL & ~KEY_POS_SETATTR) |
KEY_USR_VIEW | KEY_USR_READ),
KEY_ALLOC_NOT_IN_QUOTA, NULL);
if (IS_ERR(modsign_keyring))
panic("Can't allocate module signing keyring\n");
return 0;
}
static __init int load_module_signing_keys(void)
{
key_ref_t key;
const u8 *p, *end;
size_t plen;
pr_notice("Loading module verification certificates\n");
end = modsign_certificate_list_end;
p = modsign_certificate_list;
while (p < end) {
if (end - p < 4)
goto dodgy_cert;
if (p[0] != 0x30 &&
p[1] != 0x82)
goto dodgy_cert;
plen = (p[2] << 8) | p[3];
plen += 4;
if (plen > end - p)
goto dodgy_cert;
key = key_create_or_update(make_key_ref(modsign_keyring, 1),
"asymmetric",
NULL,
p,
plen,
(KEY_POS_ALL & ~KEY_POS_SETATTR) |
KEY_USR_VIEW,
KEY_ALLOC_NOT_IN_QUOTA);
if (IS_ERR(key))
pr_err("MODSIGN: Problem loading in-kernel X.509 certificate (%ld)\n",
PTR_ERR(key));
else
pr_notice("MODSIGN: Loaded cert '%s'\n",
key_ref_to_ptr(key)->description);
p += plen;
}
return 0;
dodgy_cert:
pr_err("MODSIGN: Problem parsing in-kernel X.509 certificate list\n");
return 0;
}

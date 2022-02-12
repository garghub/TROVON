char *qeth_get_ipa_msg(enum qeth_ipa_return_codes rc)
{
int x = 0;
qeth_ipa_rc_msg[sizeof(qeth_ipa_rc_msg) /
sizeof(struct ipa_rc_msg) - 1].rc = rc;
while (qeth_ipa_rc_msg[x].rc != rc)
x++;
return qeth_ipa_rc_msg[x].msg;
}
char *qeth_get_ipa_cmd_name(enum qeth_ipa_cmds cmd)
{
int x = 0;
qeth_ipa_cmd_names[
sizeof(qeth_ipa_cmd_names) /
sizeof(struct ipa_cmd_names)-1].cmd = cmd;
while (qeth_ipa_cmd_names[x].cmd != cmd)
x++;
return qeth_ipa_cmd_names[x].name;
}

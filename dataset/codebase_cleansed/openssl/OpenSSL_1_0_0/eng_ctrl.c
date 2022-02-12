static int int_ctrl_cmd_is_null(const ENGINE_CMD_DEFN *defn)
{
if((defn->cmd_num == 0) || (defn->cmd_name == NULL))
return 1;
return 0;
}
static int int_ctrl_cmd_by_name(const ENGINE_CMD_DEFN *defn, const char *s)
{
int idx = 0;
while(!int_ctrl_cmd_is_null(defn) && (strcmp(defn->cmd_name, s) != 0))
{
idx++;
defn++;
}
if(int_ctrl_cmd_is_null(defn))
return -1;
return idx;
}
static int int_ctrl_cmd_by_num(const ENGINE_CMD_DEFN *defn, unsigned int num)
{
int idx = 0;
while(!int_ctrl_cmd_is_null(defn) && (defn->cmd_num < num))
{
idx++;
defn++;
}
if(defn->cmd_num == num)
return idx;
return -1;
}
static int int_ctrl_helper(ENGINE *e, int cmd, long i, void *p,
void (*f)(void))
{
int idx;
char *s = (char *)p;
if(cmd == ENGINE_CTRL_GET_FIRST_CMD_TYPE)
{
if((e->cmd_defns == NULL) || int_ctrl_cmd_is_null(e->cmd_defns))
return 0;
return e->cmd_defns->cmd_num;
}
if((cmd == ENGINE_CTRL_GET_CMD_FROM_NAME) ||
(cmd == ENGINE_CTRL_GET_NAME_FROM_CMD) ||
(cmd == ENGINE_CTRL_GET_DESC_FROM_CMD))
{
if(s == NULL)
{
ENGINEerr(ENGINE_F_INT_CTRL_HELPER,
ERR_R_PASSED_NULL_PARAMETER);
return -1;
}
}
if(cmd == ENGINE_CTRL_GET_CMD_FROM_NAME)
{
if((e->cmd_defns == NULL) || ((idx = int_ctrl_cmd_by_name(
e->cmd_defns, s)) < 0))
{
ENGINEerr(ENGINE_F_INT_CTRL_HELPER,
ENGINE_R_INVALID_CMD_NAME);
return -1;
}
return e->cmd_defns[idx].cmd_num;
}
if((e->cmd_defns == NULL) || ((idx = int_ctrl_cmd_by_num(e->cmd_defns,
(unsigned int)i)) < 0))
{
ENGINEerr(ENGINE_F_INT_CTRL_HELPER,
ENGINE_R_INVALID_CMD_NUMBER);
return -1;
}
switch(cmd)
{
case ENGINE_CTRL_GET_NEXT_CMD_TYPE:
idx++;
if(int_ctrl_cmd_is_null(e->cmd_defns + idx))
return 0;
else
return e->cmd_defns[idx].cmd_num;
case ENGINE_CTRL_GET_NAME_LEN_FROM_CMD:
return strlen(e->cmd_defns[idx].cmd_name);
case ENGINE_CTRL_GET_NAME_FROM_CMD:
return BIO_snprintf(s,strlen(e->cmd_defns[idx].cmd_name) + 1,
"%s", e->cmd_defns[idx].cmd_name);
case ENGINE_CTRL_GET_DESC_LEN_FROM_CMD:
if(e->cmd_defns[idx].cmd_desc)
return strlen(e->cmd_defns[idx].cmd_desc);
return strlen(int_no_description);
case ENGINE_CTRL_GET_DESC_FROM_CMD:
if(e->cmd_defns[idx].cmd_desc)
return BIO_snprintf(s,
strlen(e->cmd_defns[idx].cmd_desc) + 1,
"%s", e->cmd_defns[idx].cmd_desc);
return BIO_snprintf(s, strlen(int_no_description) + 1,"%s",
int_no_description);
case ENGINE_CTRL_GET_CMD_FLAGS:
return e->cmd_defns[idx].cmd_flags;
}
ENGINEerr(ENGINE_F_INT_CTRL_HELPER,ENGINE_R_INTERNAL_LIST_ERROR);
return -1;
}
int ENGINE_ctrl(ENGINE *e, int cmd, long i, void *p, void (*f)(void))
{
int ctrl_exists, ref_exists;
if(e == NULL)
{
ENGINEerr(ENGINE_F_ENGINE_CTRL,ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
CRYPTO_w_lock(CRYPTO_LOCK_ENGINE);
ref_exists = ((e->struct_ref > 0) ? 1 : 0);
CRYPTO_w_unlock(CRYPTO_LOCK_ENGINE);
ctrl_exists = ((e->ctrl == NULL) ? 0 : 1);
if(!ref_exists)
{
ENGINEerr(ENGINE_F_ENGINE_CTRL,ENGINE_R_NO_REFERENCE);
return 0;
}
switch(cmd)
{
case ENGINE_CTRL_HAS_CTRL_FUNCTION:
return ctrl_exists;
case ENGINE_CTRL_GET_FIRST_CMD_TYPE:
case ENGINE_CTRL_GET_NEXT_CMD_TYPE:
case ENGINE_CTRL_GET_CMD_FROM_NAME:
case ENGINE_CTRL_GET_NAME_LEN_FROM_CMD:
case ENGINE_CTRL_GET_NAME_FROM_CMD:
case ENGINE_CTRL_GET_DESC_LEN_FROM_CMD:
case ENGINE_CTRL_GET_DESC_FROM_CMD:
case ENGINE_CTRL_GET_CMD_FLAGS:
if(ctrl_exists && !(e->flags & ENGINE_FLAGS_MANUAL_CMD_CTRL))
return int_ctrl_helper(e,cmd,i,p,f);
if(!ctrl_exists)
{
ENGINEerr(ENGINE_F_ENGINE_CTRL,ENGINE_R_NO_CONTROL_FUNCTION);
return -1;
}
default:
break;
}
if(!ctrl_exists)
{
ENGINEerr(ENGINE_F_ENGINE_CTRL,ENGINE_R_NO_CONTROL_FUNCTION);
return 0;
}
return e->ctrl(e, cmd, i, p, f);
}
int ENGINE_cmd_is_executable(ENGINE *e, int cmd)
{
int flags;
if((flags = ENGINE_ctrl(e, ENGINE_CTRL_GET_CMD_FLAGS, cmd, NULL, NULL)) < 0)
{
ENGINEerr(ENGINE_F_ENGINE_CMD_IS_EXECUTABLE,
ENGINE_R_INVALID_CMD_NUMBER);
return 0;
}
if(!(flags & ENGINE_CMD_FLAG_NO_INPUT) &&
!(flags & ENGINE_CMD_FLAG_NUMERIC) &&
!(flags & ENGINE_CMD_FLAG_STRING))
return 0;
return 1;
}
int ENGINE_ctrl_cmd(ENGINE *e, const char *cmd_name,
long i, void *p, void (*f)(void), int cmd_optional)
{
int num;
if((e == NULL) || (cmd_name == NULL))
{
ENGINEerr(ENGINE_F_ENGINE_CTRL_CMD,
ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
if((e->ctrl == NULL) || ((num = ENGINE_ctrl(e,
ENGINE_CTRL_GET_CMD_FROM_NAME,
0, (void *)cmd_name, NULL)) <= 0))
{
if(cmd_optional)
{
ERR_clear_error();
return 1;
}
ENGINEerr(ENGINE_F_ENGINE_CTRL_CMD,
ENGINE_R_INVALID_CMD_NAME);
return 0;
}
if (ENGINE_ctrl(e, num, i, p, f) > 0)
return 1;
return 0;
}
int ENGINE_ctrl_cmd_string(ENGINE *e, const char *cmd_name, const char *arg,
int cmd_optional)
{
int num, flags;
long l;
char *ptr;
if((e == NULL) || (cmd_name == NULL))
{
ENGINEerr(ENGINE_F_ENGINE_CTRL_CMD_STRING,
ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
if((e->ctrl == NULL) || ((num = ENGINE_ctrl(e,
ENGINE_CTRL_GET_CMD_FROM_NAME,
0, (void *)cmd_name, NULL)) <= 0))
{
if(cmd_optional)
{
ERR_clear_error();
return 1;
}
ENGINEerr(ENGINE_F_ENGINE_CTRL_CMD_STRING,
ENGINE_R_INVALID_CMD_NAME);
return 0;
}
if(!ENGINE_cmd_is_executable(e, num))
{
ENGINEerr(ENGINE_F_ENGINE_CTRL_CMD_STRING,
ENGINE_R_CMD_NOT_EXECUTABLE);
return 0;
}
if((flags = ENGINE_ctrl(e, ENGINE_CTRL_GET_CMD_FLAGS, num, NULL, NULL)) < 0)
{
ENGINEerr(ENGINE_F_ENGINE_CTRL_CMD_STRING,
ENGINE_R_INTERNAL_LIST_ERROR);
return 0;
}
if(flags & ENGINE_CMD_FLAG_NO_INPUT)
{
if(arg != NULL)
{
ENGINEerr(ENGINE_F_ENGINE_CTRL_CMD_STRING,
ENGINE_R_COMMAND_TAKES_NO_INPUT);
return 0;
}
if(ENGINE_ctrl(e, num, 0, (void *)arg, NULL) > 0)
return 1;
return 0;
}
if(arg == NULL)
{
ENGINEerr(ENGINE_F_ENGINE_CTRL_CMD_STRING,
ENGINE_R_COMMAND_TAKES_INPUT);
return 0;
}
if(flags & ENGINE_CMD_FLAG_STRING)
{
if(ENGINE_ctrl(e, num, 0, (void *)arg, NULL) > 0)
return 1;
return 0;
}
if(!(flags & ENGINE_CMD_FLAG_NUMERIC))
{
ENGINEerr(ENGINE_F_ENGINE_CTRL_CMD_STRING,
ENGINE_R_INTERNAL_LIST_ERROR);
return 0;
}
l = strtol(arg, &ptr, 10);
if((arg == ptr) || (*ptr != '\0'))
{
ENGINEerr(ENGINE_F_ENGINE_CTRL_CMD_STRING,
ENGINE_R_ARGUMENT_IS_NOT_A_NUMBER);
return 0;
}
if(ENGINE_ctrl(e, num, l, NULL, NULL) > 0)
return 1;
return 0;
}

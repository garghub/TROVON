static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_6 ;
int V_7 = 0 ;
char * V_8 ;
char * V_9 = V_5 ;
T_2 V_10 = V_11 ;
unsigned long V_12 ;
F_2 ( & V_13 . V_14 , V_12 ) ;
* V_9 = '\0' ;
for ( V_6 = 0 ; V_6 < 256 ; V_6 ++ ) {
if ( V_10 <= 1 )
break;
if ( strcmp ( L_1 , V_4 -> V_4 . V_15 ) == 0 ) {
V_7 = F_3 ( V_9 , V_10 , L_2 ,
V_6 , V_16 [ V_6 ] ) ;
} else {
if ( F_4 ( V_6 , V_17 ) )
V_8 = L_3 ;
else if ( F_4 ( V_6 , V_18 ) )
V_8 = L_4 ;
else if ( F_4 ( V_6 , V_19 ) )
V_8 = L_5 ;
else if ( F_4 ( V_6 , V_20 ) )
V_8 = L_6 ;
else if ( F_4 ( V_6 , V_21 ) )
V_8 = L_7 ;
else if ( F_4 ( V_6 , V_22 ) )
V_8 = L_8 ;
else if ( F_4 ( V_6 , V_23 ) )
V_8 = L_9 ;
else if ( F_4 ( V_6 , V_24 ) )
V_8 = L_10 ;
else if ( F_4 ( V_6 , V_25 ) )
V_8 = L_11 ;
else
V_8 = L_12 ;
V_7 =
F_3 ( V_9 , V_10 , L_2 , V_6 , V_8 ) ;
}
V_10 -= V_7 ;
V_9 += V_7 ;
}
F_5 ( & V_13 . V_14 , V_12 ) ;
return V_9 - V_5 ;
}
static void F_6 ( int V_26 , int V_27 , int V_28 ,
int V_29 , int V_30 )
{
char * V_31 [] = {
L_13 ,
L_14 ,
} ;
int V_7 ;
char V_5 [ 80 ] ;
if ( V_26 ) {
F_7 ( L_15 , V_31 [ V_30 ] ) ;
} else if ( V_27 ) {
V_7 = snprintf ( V_5 , sizeof( V_5 ) ,
L_16 ,
V_28 , V_27 , V_31 [ V_30 ] ) ;
if ( V_29 )
snprintf ( V_5 + ( V_7 - 1 ) , sizeof( V_5 ) - ( V_7 - 1 ) ,
L_17 ,
V_29 , V_29 > 1 ? L_18 : L_19 ) ;
F_8 ( V_5 ) ;
}
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_32 )
{
char * V_8 = ( char * ) V_5 ;
char * V_33 = V_8 + V_32 ;
char * V_34 = NULL ;
char V_35 [ V_36 + 1 ] ;
char * V_37 = NULL ;
char * V_38 = NULL ;
char * V_39 = NULL ;
T_1 V_40 = V_32 ;
unsigned long V_12 ;
unsigned long V_41 = 0 ;
int V_42 = 0 ;
int V_27 = 0 ;
int V_28 = 0 ;
int V_29 = 0 ;
int V_26 = 0 ;
int V_30 = ! strcmp ( V_4 -> V_4 . V_15 , L_1 ) ;
T_2 V_43 = 0 ;
int V_6 ;
F_2 ( & V_13 . V_14 , V_12 ) ;
while ( V_8 < V_33 ) {
while ( ( V_8 < V_33 ) && ( * V_8 == ' ' || * V_8 == '\t' ) )
V_8 ++ ;
if ( V_8 == V_33 )
break;
if ( ( * V_8 == '\n' ) || strchr ( L_20 , * V_8 ) ) {
V_26 = 1 ;
break;
}
V_27 ++ ;
V_34 = strchr ( V_8 , '\n' ) ;
if ( ! V_34 ) {
V_29 ++ ;
break;
}
if ( ! isdigit ( * V_8 ) ) {
V_29 ++ ;
V_8 = V_34 + 1 ;
continue;
}
V_41 = F_10 ( V_8 , & V_38 , 10 ) ;
if ( V_41 > 255 ) {
V_29 ++ ;
V_8 = V_34 + 1 ;
continue;
}
while ( ( V_38 < V_34 ) && ( * V_38 == ' ' || * V_38 == '\t' ) )
V_38 ++ ;
V_43 = V_34 - V_38 ;
if ( V_43 > V_36 ) {
V_29 ++ ;
V_8 = V_34 + 1 ;
continue;
}
if ( V_30 ) {
V_39 = F_11 ( V_43 + 1 , V_44 ) ;
if ( ! V_39 ) {
V_40 = - V_45 ;
V_26 = 1 ;
break;
}
V_37 = V_39 ;
} else {
V_37 = V_35 ;
}
for ( V_6 = 0 ; V_6 < V_43 ; V_6 ++ )
V_37 [ V_6 ] = V_38 [ V_6 ] ;
V_37 [ V_43 ] = '\0' ;
if ( V_30 ) {
if ( V_16 [ V_41 ] != V_46 [ V_41 ] )
F_12 ( V_16 [ V_41 ] ) ;
V_16 [ V_41 ] = V_39 ;
V_28 ++ ;
} else {
V_42 = F_13 ( V_35 ) ;
if ( V_42 == 0 ) {
V_29 ++ ;
V_8 = V_34 + 1 ;
continue;
}
if ( V_42 != V_47 [ V_41 ] ) {
V_47 [ V_41 ] = V_42 ;
V_28 ++ ;
}
}
V_8 = V_34 + 1 ;
}
if ( V_26 ) {
if ( V_30 )
F_14 () ;
else
F_15 () ;
}
F_5 ( & V_13 . V_14 , V_12 ) ;
F_6 ( V_26 , V_27 , V_28 , V_29 ,
V_30 ) ;
return V_40 ;
}
static T_1 F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
char * V_8 = V_5 ;
int V_6 ;
int V_48 ;
int V_49 ;
int V_50 ;
T_3 * V_51 ;
T_3 V_52 ;
unsigned long V_12 ;
F_2 ( & V_13 . V_14 , V_12 ) ;
V_51 = V_53 + V_54 ;
V_49 = ( int ) ( * V_51 ) ;
V_50 = ( int ) V_51 [ 1 ] ;
V_8 += sprintf ( V_8 , L_21 , V_55 , V_49 , V_50 ) ;
V_51 += 2 ;
for ( V_48 = 0 ; V_48 <= V_49 ; V_48 ++ ) {
for ( V_6 = 0 ; V_6 <= V_50 ; V_6 ++ ) {
V_52 = * V_51 ++ ;
V_8 += sprintf ( V_8 , L_22 , ( int ) V_52 ) ;
* V_8 ++ = ( V_6 < V_50 ) ? V_56 : '\n' ;
}
}
V_8 += sprintf ( V_8 , L_23 , V_55 ) ;
F_5 ( & V_13 . V_14 , V_12 ) ;
return ( int ) ( V_8 - V_5 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_32 )
{
int V_6 ;
T_1 V_57 = V_32 ;
char * V_58 = NULL ;
char * V_8 ;
T_3 * V_51 ;
unsigned long V_12 ;
F_2 ( & V_13 . V_14 , V_12 ) ;
V_58 = F_18 ( V_5 , V_32 + 1 , V_44 ) ;
if ( ! V_58 ) {
F_5 ( & V_13 . V_14 , V_12 ) ;
return - V_45 ;
}
if ( strchr ( L_20 , * V_58 ) ) {
F_19 ( V_59 , V_53 ) ;
F_7 ( L_24 ) ;
F_12 ( V_58 ) ;
F_5 ( & V_13 . V_14 , V_12 ) ;
return V_32 ;
}
if ( V_58 [ V_32 - 1 ] == '\n' )
V_58 [ V_32 - 1 ] = '\0' ;
V_8 = V_58 ;
V_51 = ( T_3 * ) V_58 ;
for ( V_6 = 0 ; V_6 < 3 ; V_6 ++ ) {
V_8 = F_20 ( V_8 , V_51 ) ;
V_51 ++ ;
}
V_6 = ( int ) V_51 [ - 2 ] + 1 ;
V_6 *= ( int ) V_51 [ - 1 ] + 1 ;
V_6 += 2 ;
if ( V_51 [ - 3 ] != V_55 || V_51 [ - 1 ] > 10 ||
V_6 + V_54 + 4 >= sizeof( V_53 ) ) {
F_21 ( L_25 , V_6 ,
( int ) V_51 [ - 3 ] , ( int ) V_51 [ - 2 ] , ( int ) V_51 [ - 1 ] ) ;
F_12 ( V_58 ) ;
F_5 ( & V_13 . V_14 , V_12 ) ;
return - V_60 ;
}
while ( -- V_6 >= 0 ) {
V_8 = F_20 ( V_8 , V_51 ) ;
V_51 ++ ;
if ( ! ( * V_8 ) )
break;
}
if ( V_6 != 0 || V_51 [ - 1 ] != V_55 || V_51 [ - 2 ] != 0 ) {
V_57 = - V_60 ;
F_21 ( L_26 , V_6 ,
( int ) V_51 [ - 3 ] , ( int ) V_51 [ - 2 ] , ( int ) V_51 [ - 1 ] ) ;
} else {
if ( F_19 ( V_58 , V_53 ) ) {
F_19 ( V_59 , V_53 ) ;
V_57 = - V_60 ;
F_21 ( L_27 ) ;
}
}
F_12 ( V_58 ) ;
F_5 ( & V_13 . V_14 , V_12 ) ;
return V_57 ;
}
static T_1 F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_32 )
{
int V_7 ;
struct V_61 * V_62 = V_63 [ V_64 ] . V_65 ;
char V_52 = 0 ;
char V_66 ;
unsigned long V_12 ;
V_7 = strlen ( V_5 ) ;
if ( V_7 > 0 && V_7 < 3 ) {
V_52 = V_5 [ 0 ] ;
if ( V_52 == '\n' )
V_52 = '0' ;
}
if ( V_52 < '0' || V_52 > '7' ) {
F_21 ( L_28 , V_52 ) ;
return - V_60 ;
}
F_2 ( & V_13 . V_14 , V_12 ) ;
if ( V_52 & 2 ) {
V_66 = 1 ;
F_23 () ;
} else {
V_66 = 0 ;
}
if ( V_52 & 4 )
V_66 |= 0x40 ;
if ( V_52 & 1 )
V_67 |= V_66 ;
else
V_67 &= ~ V_66 ;
F_5 ( & V_13 . V_14 , V_12 ) ;
return V_32 ;
}
static T_1 F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_68 ;
if ( V_69 == NULL )
V_68 = sprintf ( V_5 , L_29 , L_30 ) ;
else
V_68 = sprintf ( V_5 , L_29 , V_69 -> V_15 ) ;
return V_68 ;
}
static T_1 F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_32 )
{
int V_7 ;
char V_70 [ 10 ] ;
V_7 = strlen ( V_5 ) ;
if ( V_7 < 2 || V_7 > 9 )
return - V_60 ;
strncpy ( V_70 , V_5 , V_7 ) ;
if ( V_70 [ V_7 - 1 ] == '\n' )
V_7 -- ;
V_70 [ V_7 ] = '\0' ;
F_26 ( V_70 ) ;
if ( ( V_69 != NULL ) && ( ! strcmp ( V_70 , V_69 -> V_15 ) ) ) {
F_21 ( L_31 , V_70 ) ;
} else if ( F_27 ( V_70 ) != 0 ) {
F_21 ( L_32 , V_70 ) ;
return - V_71 ;
}
return V_32 ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_32 )
{
T_3 V_72 [ 256 ] ;
int V_7 ;
int V_73 ;
const char * V_74 = V_5 ;
if ( ! V_69 )
return - V_75 ;
V_7 = strlen ( V_5 ) ;
while ( V_7 > 0 ) {
V_73 = F_29 ( T_2 , V_7 , 250 ) ;
strncpy ( V_72 , V_74 , V_73 ) ;
V_72 [ V_73 ] = '\0' ;
F_30 ( V_72 ) ;
F_31 ( L_33 , V_72 ) ;
V_74 += V_73 ;
V_7 -= V_73 ;
}
return V_32 ;
}
static T_1 F_32 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
char * V_8 ;
V_8 = V_5 ;
V_8 += sprintf ( V_8 , L_34 , V_76 ) ;
if ( V_69 )
V_8 += sprintf ( V_8 , L_35 ,
V_69 -> V_15 , V_69 -> V_77 ) ;
return V_8 - V_5 ;
}
static T_1 F_33 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_6 ;
char * V_8 = V_5 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
struct V_82 * V_83 ;
short V_84 ;
unsigned long V_12 ;
V_79 = F_34 ( V_4 -> V_4 . V_15 ) ;
if ( V_79 == NULL ) {
F_21 ( L_36 ,
V_4 -> V_4 . V_15 ) ;
return - V_60 ;
}
V_81 = F_35 ( V_79 -> V_85 ) ;
if ( V_81 == NULL ) {
F_21 ( L_37 ,
V_79 -> V_85 ) ;
return - V_60 ;
}
F_2 ( & V_13 . V_14 , V_12 ) ;
V_83 = (struct V_82 * ) & V_86 [ V_81 -> V_87 ] ;
V_84 = V_83 -> V_84 ;
for ( V_6 = 33 ; V_6 < 128 ; V_6 ++ ) {
if ( ! ( V_47 [ V_6 ] & V_84 ) )
continue;
* V_8 ++ = ( char ) V_6 ;
}
F_5 ( & V_13 . V_14 , V_12 ) ;
return V_8 - V_5 ;
}
static T_1 F_36 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_32 )
{
int V_88 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
char V_89 [ 100 ] ;
unsigned long V_12 ;
V_88 = strlen ( V_5 ) ;
if ( V_88 < 1 || V_88 > 99 )
return - V_60 ;
V_79 = F_34 ( V_4 -> V_4 . V_15 ) ;
if ( V_79 == NULL ) {
F_21 ( L_36 ,
V_4 -> V_4 . V_15 ) ;
return - V_60 ;
}
V_81 = F_35 ( V_79 -> V_85 ) ;
if ( V_81 == NULL ) {
F_21 ( L_37 ,
V_79 -> V_85 ) ;
return - V_60 ;
}
strncpy ( V_89 , V_5 , V_88 ) ;
while ( V_88 && V_89 [ V_88 - 1 ] == '\n' )
V_88 -- ;
V_89 [ V_88 ] = '\0' ;
F_2 ( & V_13 . V_14 , V_12 ) ;
if ( * V_89 == 'd' || * V_89 == 'r' )
V_88 = F_37 ( NULL , V_81 -> V_87 , 3 ) ;
else
V_88 = F_37 ( V_89 , V_81 -> V_87 , 3 ) ;
F_5 ( & V_13 . V_14 , V_12 ) ;
return V_32 ;
}
T_1 F_38 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_68 = 0 ;
struct V_78 * V_90 ;
struct V_91 * V_81 ;
char * V_51 ;
char * V_8 ;
char V_52 ;
unsigned long V_12 ;
V_90 = F_34 ( V_4 -> V_4 . V_15 ) ;
if ( V_90 == NULL )
return - V_60 ;
F_2 ( & V_13 . V_14 , V_12 ) ;
V_81 = (struct V_91 * ) V_90 -> V_92 ;
switch ( V_90 -> V_93 ) {
case V_94 :
case V_95 :
if ( V_81 )
V_68 = sprintf ( V_5 , L_38 , V_81 -> V_96 . V_48 . V_87 ) ;
else
V_68 = sprintf ( V_5 , L_39 ) ;
break;
case V_97 :
if ( V_81 ) {
V_51 = V_5 ;
* V_51 ++ = '"' ;
for ( V_8 = ( char * ) V_90 -> V_98 ; ( V_52 = * V_8 ) ; V_8 ++ ) {
if ( V_52 >= ' ' && V_52 < '~' )
* V_51 ++ = V_52 ;
else
V_51 += sprintf (cp1, L_40x%02x L_41 ';
*cp1++ = '\n';
*cp1 = '\0 ';
rv = cp1-buf;
} else {
rv = sprintf(buf, "\"\"\n");
}
break;
default:
rv = sprintf(buf, "Bad parameter %s, type %i\n",
param->name, param->var_type);
break;
}
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
return rv;
}
EXPORT_SYMBOL_GPL(spk_var_show);
/*
* Used to reset either default_pitch or default_vol.
*/
static inline void spk_reset_default_value(char *header_name,
int *synth_default_value, int idx)
{
struct st_var_header *param;
if (synth && synth_default_value) {
param = spk_var_header_by_name(header_name);
if (param) {
spk_set_num_var(synth_default_value[idx],
param, E_NEW_DEFAULT);
spk_set_num_var(0, param, E_DEFAULT);
pr_info("%s reset to default value\n", param->name);
}
}
}
/*
* This function is called when a user echos a value to one of the
* variable parameters.
*/
ssize_t spk_var_store(struct kobject *kobj, struct kobj_attribute *attr,
const char *buf, size_t count)
{
struct st_var_header *param;
int ret;
int len;
char *cp;
struct var_t *var_data;
long value;
unsigned long flags;
param = spk_var_header_by_name(attr->attr.name);
if (param == NULL)
return -EINVAL;
if (param->data == NULL)
return 0;
ret = 0;
cp = (char *)buf;
string_unescape_any_inplace(cp);
spin_lock_irqsave(&speakup_info.spinlock, flags);
switch (param->var_type) {
case VAR_NUM:
case VAR_TIME:
if (*cp == 'd' || *cp == 'r' || *cp == '\0 ')
len = E_DEFAULT;
else if (*cp == '+' || *cp == '-')
len = E_INC;
else
len = E_SET;
if (kstrtol(cp, 10, &value) == 0)
ret = spk_set_num_var(value, param, len);
else
pr_warn("overflow or parsing error has occurred");
if (ret == -ERANGE) {
var_data = param->data;
pr_warn("value for %s out of range, expect %d to %d\n",
param->name,
var_data->u.n.low, var_data->u.n.high);
}
/*
* If voice was just changed, we might need to reset our default
* pitch and volume.
*/
if (param->var_id == VOICE && synth &&
(ret == 0 || ret == -ERESTART)) {
var_data = param->data;
value = var_data->u.n.value;
spk_reset_default_value("pitch", synth->default_pitch,
value);
spk_reset_default_value("vol", synth->default_vol,
value);
}
break;
case VAR_STRING:
len = strlen(cp);
if ((len >= 1) && (cp[len - 1] == '\n'))
--len;
if ((len >= 2) && (cp[0] == ' L_42 ')) {
++cp;
len -= 2;
}
cp[len] = '\0 ';
ret = spk_set_string_var(cp, param, len);
if (ret == -E2BIG)
pr_warn("value too long for %s\n",
param->name);
break;
default:
pr_warn("%s unknown type %d\n",
param->name, (int)param->var_type);
break;
}
spin_unlock_irqrestore(&speakup_info.spinlock, flags);
if (ret == -ERESTART)
pr_info("%s reset to default value\n", param->name);
return count;
}
EXPORT_SYMBOL_GPL(spk_var_store);
/*
* Functions for reading and writing lists of i18n messages. Incomplete.
*/
static ssize_t message_show_helper(char *buf, enum msg_index_t first,
enum msg_index_t last)
{
size_t bufsize = PAGE_SIZE;
char *buf_pointer = buf;
int printed;
enum msg_index_t cursor;
int index = 0;
*buf_pointer = '\0 '; /* buf_pointer always looking at a NUL byte. */
for (cursor = first; cursor <= last; cursor++, index++) {
if (bufsize <= 1)
break;
printed = scnprintf(buf_pointer, bufsize, "%d\t%s\n",
index, spk_msg_get(cursor));
buf_pointer += printed;
bufsize -= printed;
}
return buf_pointer - buf;
}
static void report_msg_status(int reset, int received, int used,
int rejected, char *groupname)
{
int len;
char buf[160];
if (reset) {
pr_info("i18n messages from group %s reset to defaults\n",
groupname);
} else if (received) {
len = snprintf(buf, sizeof(buf),
" updated %d of %d i18n messages from group %s\n",
used, received, groupname);
if (rejected)
snprintf(buf + (len - 1), sizeof(buf) - (len - 1),
" with %d reject%s\n",
rejected, rejected > 1 ? "s" : "");
printk(buf);
}
}
static ssize_t message_store_helper(const char *buf, size_t count,
struct msg_group_t *group)
{
char *cp = (char *) buf;
char *end = cp + count;
char *linefeed = NULL;
char *temp = NULL;
ssize_t msg_stored = 0;
ssize_t retval = count;
size_t desc_length = 0;
unsigned long index = 0;
int received = 0;
int used = 0;
int rejected = 0;
int reset = 0;
enum msg_index_t firstmessage = group->start;
enum msg_index_t lastmessage = group->end;
enum msg_index_t curmessage;
while (cp < end) {
while ((cp < end) && (*cp == ' ' || *cp == '\t'))
cp++;
if (cp == end)
break;
if (strchr("dDrR", *cp)) {
reset = 1;
break;
}
received++;
linefeed = strchr(cp, '\n');
if (!linefeed) {
rejected++;
break;
}
if (!isdigit(*cp)) {
rejected++;
cp = linefeed + 1;
continue;
}
index = simple_strtoul(cp, &temp, 10);
while ((temp < linefeed) && (*temp == ' ' || *temp == '\t'

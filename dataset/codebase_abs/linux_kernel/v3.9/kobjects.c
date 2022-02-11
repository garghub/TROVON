static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_6 ;
int V_7 = 0 ;
char * V_8 ;
char * V_9 = V_5 ;
T_2 V_10 = V_11 ;
unsigned long V_12 ;
F_2 ( V_12 ) ;
* V_9 = '\0' ;
for ( V_6 = 0 ; V_6 < 256 ; V_6 ++ ) {
if ( V_10 <= 1 )
break;
if ( strcmp ( L_1 , V_4 -> V_4 . V_13 ) == 0 ) {
V_7 = F_3 ( V_9 , V_10 , L_2 ,
V_6 , V_14 [ V_6 ] ) ;
} else {
if ( F_4 ( V_6 , V_15 ) )
V_8 = L_3 ;
else if ( F_4 ( V_6 , V_16 ) )
V_8 = L_4 ;
else if ( F_4 ( V_6 , V_17 ) )
V_8 = L_5 ;
else if ( F_4 ( V_6 , V_18 ) )
V_8 = L_6 ;
else if ( F_4 ( V_6 , V_19 ) )
V_8 = L_7 ;
else if ( F_4 ( V_6 , V_20 ) )
V_8 = L_8 ;
else if ( F_4 ( V_6 , V_21 ) )
V_8 = L_9 ;
else if ( F_4 ( V_6 , V_22 ) )
V_8 = L_10 ;
else if ( F_4 ( V_6 , V_23 ) )
V_8 = L_11 ;
else
V_8 = L_12 ;
V_7 =
F_3 ( V_9 , V_10 , L_2 , V_6 , V_8 ) ;
}
V_10 -= V_7 ;
V_9 += V_7 ;
}
F_5 ( V_12 ) ;
return V_9 - V_5 ;
}
static void F_6 ( int V_24 , int V_25 , int V_26 ,
int V_27 , int V_28 )
{
char * V_29 [] = {
L_13 ,
L_14 ,
} ;
int V_7 ;
char V_5 [ 80 ] ;
if ( V_24 ) {
F_7 ( L_15 , V_29 [ V_28 ] ) ;
} else if ( V_25 ) {
V_7 = snprintf ( V_5 , sizeof( V_5 ) ,
L_16 ,
V_26 , V_25 , V_29 [ V_28 ] ) ;
if ( V_27 )
snprintf ( V_5 + ( V_7 - 1 ) , sizeof( V_5 ) - ( V_7 - 1 ) ,
L_17 ,
V_27 , V_27 > 1 ? L_18 : L_19 ) ;
F_8 ( V_5 ) ;
}
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_30 )
{
char * V_8 = ( char * ) V_5 ;
char * V_31 = V_8 + V_30 ;
char * V_32 = NULL ;
char V_33 [ V_34 + 1 ] ;
char * V_35 = NULL ;
char * V_36 = NULL ;
char * V_37 = NULL ;
T_1 V_38 = V_30 ;
unsigned long V_12 ;
unsigned long V_39 = 0 ;
int V_40 = 0 ;
int V_25 = 0 ;
int V_26 = 0 ;
int V_27 = 0 ;
int V_24 = 0 ;
int V_28 = ! strcmp ( V_4 -> V_4 . V_13 , L_1 ) ;
T_2 V_41 = 0 ;
int V_6 ;
F_2 ( V_12 ) ;
while ( V_8 < V_31 ) {
while ( ( V_8 < V_31 ) && ( * V_8 == ' ' || * V_8 == '\t' ) )
V_8 ++ ;
if ( V_8 == V_31 )
break;
if ( ( * V_8 == '\n' ) || strchr ( L_20 , * V_8 ) ) {
V_24 = 1 ;
break;
}
V_25 ++ ;
V_32 = strchr ( V_8 , '\n' ) ;
if ( ! V_32 ) {
V_27 ++ ;
break;
}
if ( ! isdigit ( * V_8 ) ) {
V_27 ++ ;
V_8 = V_32 + 1 ;
continue;
}
V_39 = F_10 ( V_8 , & V_36 , 10 ) ;
if ( V_39 > 255 ) {
V_27 ++ ;
V_8 = V_32 + 1 ;
continue;
}
while ( ( V_36 < V_32 ) && ( * V_36 == ' ' || * V_36 == '\t' ) )
V_36 ++ ;
V_41 = V_32 - V_36 ;
if ( V_41 > V_34 ) {
V_27 ++ ;
V_8 = V_32 + 1 ;
continue;
}
if ( V_28 ) {
V_37 = F_11 ( V_41 + 1 , V_42 ) ;
if ( ! V_37 ) {
V_38 = - V_43 ;
V_24 = 1 ;
break;
}
V_35 = V_37 ;
} else {
V_35 = V_33 ;
}
for ( V_6 = 0 ; V_6 < V_41 ; V_6 ++ )
V_35 [ V_6 ] = V_36 [ V_6 ] ;
V_35 [ V_41 ] = '\0' ;
if ( V_28 ) {
if ( V_14 [ V_39 ] != V_44 [ V_39 ] )
F_12 ( V_14 [ V_39 ] ) ;
V_14 [ V_39 ] = V_37 ;
V_26 ++ ;
} else {
V_40 = F_13 ( V_33 ) ;
if ( V_40 == 0 ) {
V_27 ++ ;
V_8 = V_32 + 1 ;
continue;
}
if ( V_40 != V_45 [ V_39 ] ) {
V_45 [ V_39 ] = V_40 ;
V_26 ++ ;
}
}
V_8 = V_32 + 1 ;
}
if ( V_24 ) {
if ( V_28 )
F_14 () ;
else
F_15 () ;
}
F_5 ( V_12 ) ;
F_6 ( V_24 , V_25 , V_26 , V_27 ,
V_28 ) ;
return V_38 ;
}
static T_1 F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
char * V_8 = V_5 ;
int V_6 ;
int V_46 ;
int V_47 ;
int V_48 ;
T_3 * V_49 ;
T_3 V_50 ;
unsigned long V_12 ;
F_2 ( V_12 ) ;
V_49 = V_51 + V_52 ;
V_47 = ( int ) ( * V_49 ) ;
V_48 = ( int ) V_49 [ 1 ] ;
V_8 += sprintf ( V_8 , L_21 , V_53 , V_47 , V_48 ) ;
V_49 += 2 ;
for ( V_46 = 0 ; V_46 <= V_47 ; V_46 ++ ) {
for ( V_6 = 0 ; V_6 <= V_48 ; V_6 ++ ) {
V_50 = * V_49 ++ ;
V_8 += sprintf ( V_8 , L_22 , ( int ) V_50 ) ;
* V_8 ++ = ( V_6 < V_48 ) ? V_54 : '\n' ;
}
}
V_8 += sprintf ( V_8 , L_23 , V_53 ) ;
F_5 ( V_12 ) ;
return ( int ) ( V_8 - V_5 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_30 )
{
int V_6 ;
T_1 V_55 = V_30 ;
char * V_56 = NULL ;
char * V_8 ;
T_3 * V_49 ;
unsigned long V_12 ;
F_2 ( V_12 ) ;
V_56 = F_18 ( V_5 , V_30 + 1 , V_42 ) ;
if ( ! V_56 ) {
F_5 ( V_12 ) ;
return - V_43 ;
}
if ( strchr ( L_20 , * V_56 ) ) {
F_19 ( V_57 , V_51 ) ;
F_7 ( L_24 ) ;
F_12 ( V_56 ) ;
F_5 ( V_12 ) ;
return V_30 ;
}
if ( V_56 [ V_30 - 1 ] == '\n' )
V_56 [ V_30 - 1 ] = '\0' ;
V_8 = V_56 ;
V_49 = ( T_3 * ) V_56 ;
for ( V_6 = 0 ; V_6 < 3 ; V_6 ++ ) {
V_8 = F_20 ( V_8 , V_49 ) ;
V_49 ++ ;
}
V_6 = ( int ) V_49 [ - 2 ] + 1 ;
V_6 *= ( int ) V_49 [ - 1 ] + 1 ;
V_6 += 2 ;
if ( V_49 [ - 3 ] != V_53 || V_49 [ - 1 ] > 10 ||
V_6 + V_52 + 4 >= sizeof( V_51 ) ) {
F_21 ( L_25 , V_6 ,
( int ) V_49 [ - 3 ] , ( int ) V_49 [ - 2 ] , ( int ) V_49 [ - 1 ] ) ;
F_12 ( V_56 ) ;
F_5 ( V_12 ) ;
return - V_58 ;
}
while ( -- V_6 >= 0 ) {
V_8 = F_20 ( V_8 , V_49 ) ;
V_49 ++ ;
if ( ! ( * V_8 ) )
break;
}
if ( V_6 != 0 || V_49 [ - 1 ] != V_53 || V_49 [ - 2 ] != 0 ) {
V_55 = - V_58 ;
F_21 ( L_26 , V_6 ,
( int ) V_49 [ - 3 ] , ( int ) V_49 [ - 2 ] , ( int ) V_49 [ - 1 ] ) ;
} else {
if ( F_19 ( V_56 , V_51 ) ) {
F_19 ( V_57 , V_51 ) ;
V_55 = - V_58 ;
F_21 ( L_27 ) ;
}
}
F_12 ( V_56 ) ;
F_5 ( V_12 ) ;
return V_55 ;
}
static T_1 F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_30 )
{
int V_7 ;
struct V_59 * V_60 = V_61 [ V_62 ] . V_63 ;
char V_50 = 0 ;
char V_64 ;
unsigned long V_12 ;
V_7 = strlen ( V_5 ) ;
if ( V_7 > 0 && V_7 < 3 ) {
V_50 = V_5 [ 0 ] ;
if ( V_50 == '\n' )
V_50 = '0' ;
}
if ( V_50 < '0' || V_50 > '7' ) {
F_21 ( L_28 , V_50 ) ;
return - V_58 ;
}
F_2 ( V_12 ) ;
if ( V_50 & 2 ) {
V_64 = 1 ;
F_23 () ;
} else {
V_64 = 0 ;
}
if ( V_50 & 4 )
V_64 |= 0x40 ;
if ( V_50 & 1 )
V_65 |= V_64 ;
else
V_65 &= ~ V_64 ;
F_5 ( V_12 ) ;
return V_30 ;
}
static T_1 F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_66 ;
if ( V_67 == NULL )
V_66 = sprintf ( V_5 , L_29 , L_30 ) ;
else
V_66 = sprintf ( V_5 , L_29 , V_67 -> V_13 ) ;
return V_66 ;
}
static T_1 F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_30 )
{
int V_7 ;
char V_68 [ 10 ] ;
V_7 = strlen ( V_5 ) ;
if ( V_7 < 2 || V_7 > 9 )
return - V_58 ;
strncpy ( V_68 , V_5 , V_7 ) ;
if ( V_68 [ V_7 - 1 ] == '\n' )
V_7 -- ;
V_68 [ V_7 ] = '\0' ;
F_26 ( V_68 ) ;
if ( ( V_67 != NULL ) && ( ! strcmp ( V_68 , V_67 -> V_13 ) ) ) {
F_21 ( L_31 , V_68 ) ;
} else if ( F_27 ( V_68 ) != 0 ) {
F_21 ( L_32 , V_68 ) ;
return - V_69 ;
}
return V_30 ;
}
static T_1 F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_30 )
{
T_3 V_70 [ 256 ] ;
int V_7 ;
int V_71 ;
const char * V_72 = V_5 ;
if ( ! V_67 )
return - V_73 ;
V_7 = strlen ( V_5 ) ;
while ( V_7 > 0 ) {
V_71 = F_29 ( T_2 , V_7 , 250 ) ;
strncpy ( V_70 , V_72 , V_71 ) ;
V_70 [ V_71 ] = '\0' ;
F_30 ( V_70 ) ;
F_31 ( L_33 , V_70 ) ;
V_72 += V_71 ;
V_7 -= V_71 ;
}
return V_30 ;
}
static T_1 F_32 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
char * V_8 ;
V_8 = V_5 ;
V_8 += sprintf ( V_8 , L_34 , V_74 ) ;
if ( V_67 )
V_8 += sprintf ( V_8 , L_35 ,
V_67 -> V_13 , V_67 -> V_75 ) ;
return V_8 - V_5 ;
}
static T_1 F_33 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_6 ;
char * V_8 = V_5 ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
short V_82 ;
unsigned long V_12 ;
V_77 = F_34 ( V_4 -> V_4 . V_13 ) ;
if ( V_77 == NULL ) {
F_21 ( L_36 ,
V_4 -> V_4 . V_13 ) ;
return - V_58 ;
}
V_79 = F_35 ( V_77 -> V_83 ) ;
if ( V_79 == NULL ) {
F_21 ( L_37 ,
V_77 -> V_83 ) ;
return - V_58 ;
}
F_2 ( V_12 ) ;
V_81 = (struct V_80 * ) & V_84 [ V_79 -> V_85 ] ;
V_82 = V_81 -> V_82 ;
for ( V_6 = 33 ; V_6 < 128 ; V_6 ++ ) {
if ( ! ( V_45 [ V_6 ] & V_82 ) )
continue;
* V_8 ++ = ( char ) V_6 ;
}
F_5 ( V_12 ) ;
return V_8 - V_5 ;
}
static T_1 F_36 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_30 )
{
int V_86 ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
char V_87 [ 100 ] ;
unsigned long V_12 ;
V_86 = strlen ( V_5 ) ;
if ( V_86 < 1 || V_86 > 99 )
return - V_58 ;
V_77 = F_34 ( V_4 -> V_4 . V_13 ) ;
if ( V_77 == NULL ) {
F_21 ( L_36 ,
V_4 -> V_4 . V_13 ) ;
return - V_58 ;
}
V_79 = F_35 ( V_77 -> V_83 ) ;
if ( V_79 == NULL ) {
F_21 ( L_37 ,
V_77 -> V_83 ) ;
return - V_58 ;
}
strncpy ( V_87 , V_5 , V_86 ) ;
while ( V_86 && V_87 [ V_86 - 1 ] == '\n' )
V_86 -- ;
V_87 [ V_86 ] = '\0' ;
F_2 ( V_12 ) ;
if ( * V_87 == 'd' || * V_87 == 'r' )
V_86 = F_37 ( 0 , V_79 -> V_85 , 3 ) ;
else
V_86 = F_37 ( V_87 , V_79 -> V_85 , 3 ) ;
F_5 ( V_12 ) ;
return V_30 ;
}
T_1 F_38 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_66 = 0 ;
struct V_76 * V_88 ;
struct V_89 * V_79 ;
char * V_49 ;
char * V_8 ;
char V_50 ;
unsigned long V_12 ;
V_88 = F_34 ( V_4 -> V_4 . V_13 ) ;
if ( V_88 == NULL )
return - V_58 ;
F_2 ( V_12 ) ;
V_79 = (struct V_89 * ) V_88 -> V_90 ;
switch ( V_88 -> V_91 ) {
case V_92 :
case V_93 :
if ( V_79 )
V_66 = sprintf ( V_5 , L_38 , V_79 -> V_94 . V_46 . V_85 ) ;
else
V_66 = sprintf ( V_5 , L_39 ) ;
break;
case V_95 :
if ( V_79 ) {
V_49 = V_5 ;
* V_49 ++ = '"' ;
for ( V_8 = ( char * ) V_88 -> V_96 ; ( V_50 = * V_8 ) ; V_8 ++ ) {
if ( V_50 >= ' ' && V_50 < '~' )
* V_49 ++ = V_50 ;
else
V_49 += sprintf (cp1, L_40x%02x L_41 ';
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
spk_unlock(flags);
return rv;
}
EXPORT_SYMBOL_GPL(spk_var_show);
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
int value;
unsigned long flags;
param = spk_var_header_by_name(attr->attr.name);
if (param == NULL)
return -EINVAL;
if (param->data == NULL)
return 0;
ret = 0;
cp = spk_xlate((char *) buf);
spk_lock(flags);
switch (param->var_type) {
case VAR_NUM:
case VAR_TIME:
if (*cp == 'd' || *cp == 'r' || *cp == '\0 ')
len = E_DEFAULT;
else if (*cp == '+' || *cp == '-')
len = E_INC;
else
len = E_SET;
speakup_s2i(cp, &value);
ret = spk_set_num_var(value, param, len);
if (ret == E_RANGE) {
var_data = param->data;
pr_warn("value for %s out of range, expect %d to %d\n",
attr->attr.name,
var_data->u.n.low, var_data->u.n.high);
}
break;
case VAR_STRING:
len = strlen(buf);
if ((len >= 1) && (buf[len - 1] == '\n'))
--len;
if ((len >= 2) && (buf[0] == ' L_42 ')) {
++buf;
len -= 2;
}
cp = (char *) buf;
cp[len] = '\0 ';
ret = spk_set_string_var(buf, param, len);
if (ret == E_TOOLONG)
pr_warn("value too long for %s\n",
attr->attr.name);
break;
default:
pr_warn("%s unknown type %d\n",
param->name, (int)param->var_type);
break;
}
/*
* If voice was just changed, we might need to reset our default
* pitch and volume.
*/
if (strcmp(attr->attr.name, "voice") == 0) {
if (synth && synth->default_pitch) {
param = spk_var_header_by_name("pitch");
if (param) {
spk_set_num_var(synth->default_pitch[value],
param, E_NEW_DEFAULT);
spk_set_num_var(0, param, E_DEFAULT);
}
}
if (synth && synth->default_vol) {
param = spk_var_header_by_name("vol");
if (param) {
spk_set_num_var(synth->default_vol[value],
param, E_NEW_DEFAULT);
spk_set_num_var(0, param, E_DEFAULT);
}
}
}
spk_unlock(flags);
if (ret == SET_DEFAULT)
pr_info("%s reset to default value\n", attr->attr.name);
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

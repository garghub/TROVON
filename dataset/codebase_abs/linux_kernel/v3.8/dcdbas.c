static void F_1 ( void )
{
if ( ! V_1 )
return;
F_2 ( & V_2 -> V_3 , L_1 ,
V_4 , V_5 , V_6 ) ;
F_3 ( & V_2 -> V_3 , V_6 , V_1 ,
V_7 ) ;
V_1 = NULL ;
V_7 = 0 ;
V_5 = 0 ;
V_6 = 0 ;
}
static int F_4 ( unsigned long V_8 )
{
void * V_9 ;
T_1 V_10 ;
if ( V_6 >= V_8 )
return 0 ;
if ( V_8 > V_11 )
return - V_12 ;
V_9 = F_5 ( & V_2 -> V_3 , V_8 , & V_10 , V_13 ) ;
if ( ! V_9 ) {
F_2 ( & V_2 -> V_3 ,
L_2 ,
V_4 , V_8 ) ;
return - V_14 ;
}
if ( V_1 )
memcpy ( V_9 , V_1 , V_6 ) ;
F_1 () ;
V_1 = V_9 ;
V_7 = V_10 ;
V_5 = ( V_15 ) F_6 ( V_9 ) ;
V_6 = V_8 ;
F_2 ( & V_2 -> V_3 , L_1 ,
V_4 , V_5 , V_6 ) ;
return 0 ;
}
static T_2 F_7 ( struct V_16 * V_3 ,
struct V_17 * V_18 ,
char * V_9 )
{
return sprintf ( V_9 , L_3 , V_5 ) ;
}
static T_2 F_8 ( struct V_16 * V_3 ,
struct V_17 * V_18 ,
char * V_9 )
{
return sprintf ( V_9 , L_4 , V_6 ) ;
}
static T_2 F_9 ( struct V_16 * V_3 ,
struct V_17 * V_18 ,
const char * V_9 , T_3 V_19 )
{
unsigned long V_20 ;
T_2 V_21 ;
V_20 = F_10 ( V_9 , NULL , 10 ) ;
F_11 ( & V_22 ) ;
V_21 = F_4 ( V_20 ) ;
F_12 ( & V_22 ) ;
if ( V_21 )
return V_21 ;
return V_19 ;
}
static T_2 F_13 ( struct V_23 * V_24 , struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_9 , T_4 V_29 , T_3 V_19 )
{
T_2 V_21 ;
F_11 ( & V_22 ) ;
V_21 = F_14 ( V_9 , V_19 , & V_29 , V_1 ,
V_6 ) ;
F_12 ( & V_22 ) ;
return V_21 ;
}
static T_2 F_15 ( struct V_23 * V_24 , struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_9 , T_4 V_29 , T_3 V_19 )
{
T_2 V_21 ;
if ( ( V_29 + V_19 ) > V_11 )
return - V_12 ;
F_11 ( & V_22 ) ;
V_21 = F_4 ( V_29 + V_19 ) ;
if ( V_21 )
goto V_30;
memcpy ( V_1 + V_29 , V_9 , V_19 ) ;
V_21 = V_19 ;
V_30:
F_12 ( & V_22 ) ;
return V_21 ;
}
static T_2 F_16 ( struct V_16 * V_3 ,
struct V_17 * V_18 ,
char * V_9 )
{
return sprintf ( V_9 , L_5 , V_31 ) ;
}
static T_2 F_17 ( struct V_16 * V_3 ,
struct V_17 * V_18 ,
const char * V_9 , T_3 V_19 )
{
T_2 V_21 ;
F_11 ( & V_22 ) ;
V_21 = F_4 ( sizeof( struct V_32 ) ) ;
F_12 ( & V_22 ) ;
if ( V_21 )
return V_21 ;
V_31 = F_10 ( V_9 , NULL , 10 ) ;
return V_19 ;
}
static T_2 F_18 ( struct V_16 * V_3 ,
struct V_17 * V_18 ,
char * V_9 )
{
return sprintf ( V_9 , L_5 , V_33 ) ;
}
static T_2 F_19 ( struct V_16 * V_3 ,
struct V_17 * V_18 ,
const char * V_9 , T_3 V_19 )
{
V_33 = F_10 ( V_9 , NULL , 10 ) ;
return V_19 ;
}
static T_2 F_20 ( struct V_16 * V_3 ,
struct V_17 * V_18 ,
char * V_9 )
{
return sprintf ( V_9 , L_5 , V_34 ) ;
}
static T_2 F_21 ( struct V_16 * V_3 ,
struct V_17 * V_18 ,
const char * V_9 , T_3 V_19 )
{
V_34 = F_10 ( V_9 , NULL , 10 ) ;
return V_19 ;
}
int F_22 ( struct V_35 * V_35 )
{
T_5 V_36 ;
int V_21 = 0 ;
if ( V_35 -> V_37 != V_38 ) {
F_23 ( & V_2 -> V_3 , L_6 ,
V_4 ) ;
return - V_39 ;
}
if ( ! F_24 ( & V_36 , V_13 ) )
return - V_14 ;
F_25 ( V_36 , & V_40 -> V_41 ) ;
F_26 ( V_40 , F_27 ( 0 ) ) ;
if ( F_28 () != 0 ) {
F_2 ( & V_2 -> V_3 , L_7 ,
V_4 ) ;
V_21 = - V_42 ;
goto V_30;
}
asm volatile (
"outb %b0,%w1\n"
"inb %w1"
:
: "a" (smi_cmd->command_code),
"d" (smi_cmd->command_address),
"b" (smi_cmd->ebx),
"c" (smi_cmd->ecx)
: "memory"
);
V_30:
F_26 ( V_40 , V_36 ) ;
F_29 ( V_36 ) ;
return V_21 ;
}
static T_2 F_30 ( struct V_16 * V_3 ,
struct V_17 * V_18 ,
const char * V_9 , T_3 V_19 )
{
struct V_35 * V_35 ;
unsigned long V_43 = F_10 ( V_9 , NULL , 10 ) ;
T_2 V_21 ;
F_11 ( & V_22 ) ;
if ( V_6 < sizeof( struct V_35 ) ) {
V_21 = - V_44 ;
goto V_30;
}
V_35 = (struct V_35 * ) V_1 ;
switch ( V_43 ) {
case 2 :
V_21 = F_22 ( V_35 ) ;
if ( ! V_21 )
V_21 = V_19 ;
break;
case 1 :
V_35 -> V_45 = ( V_15 ) F_6 ( V_35 -> V_46 ) ;
V_21 = F_22 ( V_35 ) ;
if ( ! V_21 )
V_21 = V_19 ;
break;
case 0 :
memset ( V_1 , 0 , V_6 ) ;
V_21 = V_19 ;
break;
default:
V_21 = - V_12 ;
break;
}
V_30:
F_12 ( & V_22 ) ;
return V_21 ;
}
static int F_31 ( void )
{
struct V_32 * V_32 ;
T_6 * V_47 ;
unsigned long V_48 ;
V_15 V_49 ;
T_7 V_50 ;
T_6 V_51 ;
V_32 = (struct V_32 * ) V_1 ;
V_32 -> V_52 = V_53 ;
switch ( V_33 ) {
case V_54 :
F_32 ( & V_55 , V_48 ) ;
V_47 = ( T_6 * ) & V_5 ;
for ( V_51 = V_56 ;
V_51 < ( V_56 + 4 ) ;
V_51 ++ , V_47 ++ ) {
F_33 ( V_51 ,
( V_57 + V_58 ) ) ;
F_33 ( * V_47 ,
( V_57 + V_59 ) ) ;
}
V_50 = V_53 ;
F_33 ( ( T_6 ) V_50 , V_60 ) ;
F_33 ( V_61 , V_62 ) ;
F_34 ( & V_55 , V_48 ) ;
V_49 = V_63 ;
while ( ( V_50 = F_35 ( V_60 ) )
== V_53 ) {
V_49 -- ;
if ( V_49 == V_64 )
return - V_65 ;
}
break;
case V_66 :
case V_67 :
F_32 ( & V_55 , V_48 ) ;
V_47 = ( T_6 * ) & V_5 ;
for ( V_51 = V_68 ;
V_51 < ( V_68 + 4 ) ;
V_51 ++ , V_47 ++ ) {
F_33 ( V_51 , ( V_57 + V_69 ) ) ;
F_33 ( * V_47 , ( V_57 + V_70 ) ) ;
}
if ( V_33 == V_67 )
F_33 ( V_61 , V_62 ) ;
else
F_33 ( V_61 , V_71 ) ;
F_36 ( V_72 ) ;
F_34 ( & V_55 , V_48 ) ;
V_50 = F_35 ( V_71 ) ;
V_49 = V_63 ;
while ( V_32 -> V_52 == V_53 ) {
V_49 -- ;
if ( V_49 == V_64 )
return - V_65 ;
}
break;
default:
F_2 ( & V_2 -> V_3 , L_8 ,
V_4 , V_33 ) ;
return - V_73 ;
}
return 0 ;
}
static void F_37 ( void )
{
struct V_32 * V_32 ;
T_6 V_74 ;
if ( V_31 == V_75 )
return;
V_74 = V_31 ;
V_31 = V_75 ;
if ( ! V_1 ) {
F_2 ( & V_2 -> V_3 , L_9 , V_4 ) ;
return;
}
if ( V_6 < sizeof( struct V_32 ) ) {
F_2 ( & V_2 -> V_3 , L_10 ,
V_4 ) ;
return;
}
V_32 = (struct V_32 * ) V_1 ;
if ( V_74 & V_76 ) {
V_32 -> V_77 = V_78 ;
V_32 -> V_79 = 0 ;
* ( ( V_80 * ) & V_32 -> V_81 . V_82 . V_83 [ 0 ] ) = ( V_80 ) 0 ;
F_31 () ;
} else if ( V_74 & V_84 ) {
V_32 -> V_77 = V_78 ;
V_32 -> V_79 = 0 ;
* ( ( V_80 * ) & V_32 -> V_81 . V_82 . V_83 [ 0 ] ) = ( V_80 ) 20 ;
F_31 () ;
}
}
static int F_38 ( struct V_85 * V_86 , unsigned long V_87 ,
void * V_88 )
{
switch ( V_87 ) {
case V_89 :
case V_90 :
case V_91 :
if ( V_34 ) {
F_39 ( V_92 L_11
L_12 ) ;
F_37 () ;
}
break;
}
return V_93 ;
}
static int F_40 ( struct V_94 * V_3 )
{
int V_95 , error ;
V_31 = V_75 ;
V_33 = V_96 ;
V_2 -> V_3 . V_97 = F_41 ( 32 ) ;
V_2 -> V_3 . V_98 = & V_2 -> V_3 . V_97 ;
error = F_42 ( & V_3 -> V_3 . V_26 , & V_99 ) ;
if ( error )
return error ;
for ( V_95 = 0 ; V_100 [ V_95 ] ; V_95 ++ ) {
error = F_43 ( & V_3 -> V_3 . V_26 ,
V_100 [ V_95 ] ) ;
if ( error ) {
while ( -- V_95 >= 0 )
F_44 ( & V_3 -> V_3 . V_26 ,
V_100 [ V_95 ] ) ;
F_45 ( & V_3 -> V_3 . V_26 , & V_99 ) ;
return error ;
}
}
F_46 ( & V_101 ) ;
F_23 ( & V_3 -> V_3 , L_13 ,
V_102 , V_103 ) ;
return 0 ;
}
static int F_47 ( struct V_94 * V_3 )
{
int V_95 ;
F_48 ( & V_101 ) ;
for ( V_95 = 0 ; V_100 [ V_95 ] ; V_95 ++ )
F_44 ( & V_3 -> V_3 . V_26 , V_100 [ V_95 ] ) ;
F_45 ( & V_3 -> V_3 . V_26 , & V_99 ) ;
return 0 ;
}
static int T_8 F_49 ( void )
{
int error ;
error = F_50 ( & V_104 ) ;
if ( error )
return error ;
V_2 = F_51 ( V_105 , - 1 ) ;
if ( ! V_2 ) {
error = - V_14 ;
goto V_106;
}
error = F_52 ( V_2 ) ;
if ( error )
goto V_107;
return 0 ;
V_107:
F_53 ( V_2 ) ;
V_106:
F_54 ( & V_104 ) ;
return error ;
}
static void T_9 F_55 ( void )
{
F_48 ( & V_101 ) ;
F_1 () ;
F_56 ( V_2 ) ;
F_54 ( & V_104 ) ;
}

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
static int F_22 ( void * V_35 )
{
struct V_36 * V_36 = V_35 ;
if ( F_23 () != 0 ) {
F_2 ( & V_2 -> V_3 , L_6 ,
V_4 ) ;
return - V_37 ;
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
return 0 ;
}
int F_24 ( struct V_36 * V_36 )
{
int V_21 ;
if ( V_36 -> V_38 != V_39 ) {
F_25 ( & V_2 -> V_3 , L_7 ,
V_4 ) ;
return - V_40 ;
}
F_26 () ;
V_21 = F_27 ( 0 , F_22 , V_36 , true ) ;
F_28 () ;
return V_21 ;
}
static T_2 F_29 ( struct V_16 * V_3 ,
struct V_17 * V_18 ,
const char * V_9 , T_3 V_19 )
{
struct V_36 * V_36 ;
unsigned long V_41 = F_10 ( V_9 , NULL , 10 ) ;
T_2 V_21 ;
F_11 ( & V_22 ) ;
if ( V_6 < sizeof( struct V_36 ) ) {
V_21 = - V_42 ;
goto V_30;
}
V_36 = (struct V_36 * ) V_1 ;
switch ( V_41 ) {
case 2 :
V_21 = F_24 ( V_36 ) ;
if ( ! V_21 )
V_21 = V_19 ;
break;
case 1 :
V_36 -> V_43 = ( V_15 ) F_6 ( V_36 -> V_44 ) ;
V_21 = F_24 ( V_36 ) ;
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
static int F_30 ( void )
{
struct V_32 * V_32 ;
T_5 * V_45 ;
unsigned long V_46 ;
V_15 V_47 ;
T_6 V_48 ;
T_5 V_49 ;
V_32 = (struct V_32 * ) V_1 ;
V_32 -> V_50 = V_51 ;
switch ( V_33 ) {
case V_52 :
F_31 ( & V_53 , V_46 ) ;
V_45 = ( T_5 * ) & V_5 ;
for ( V_49 = V_54 ;
V_49 < ( V_54 + 4 ) ;
V_49 ++ , V_45 ++ ) {
F_32 ( V_49 ,
( V_55 + V_56 ) ) ;
F_32 ( * V_45 ,
( V_55 + V_57 ) ) ;
}
V_48 = V_51 ;
F_32 ( ( T_5 ) V_48 , V_58 ) ;
F_32 ( V_59 , V_60 ) ;
F_33 ( & V_53 , V_46 ) ;
V_47 = V_61 ;
while ( ( V_48 = F_34 ( V_58 ) )
== V_51 ) {
V_47 -- ;
if ( V_47 == V_62 )
return - V_63 ;
}
break;
case V_64 :
case V_65 :
F_31 ( & V_53 , V_46 ) ;
V_45 = ( T_5 * ) & V_5 ;
for ( V_49 = V_66 ;
V_49 < ( V_66 + 4 ) ;
V_49 ++ , V_45 ++ ) {
F_32 ( V_49 , ( V_55 + V_67 ) ) ;
F_32 ( * V_45 , ( V_55 + V_68 ) ) ;
}
if ( V_33 == V_65 )
F_32 ( V_59 , V_60 ) ;
else
F_32 ( V_59 , V_69 ) ;
F_35 ( V_70 ) ;
F_33 ( & V_53 , V_46 ) ;
V_48 = F_34 ( V_69 ) ;
V_47 = V_61 ;
while ( V_32 -> V_50 == V_51 ) {
V_47 -- ;
if ( V_47 == V_62 )
return - V_63 ;
}
break;
default:
F_2 ( & V_2 -> V_3 , L_8 ,
V_4 , V_33 ) ;
return - V_71 ;
}
return 0 ;
}
static void F_36 ( void )
{
struct V_32 * V_32 ;
T_5 V_72 ;
if ( V_31 == V_73 )
return;
V_72 = V_31 ;
V_31 = V_73 ;
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
if ( V_72 & V_74 ) {
V_32 -> V_75 = V_76 ;
V_32 -> V_77 = 0 ;
* ( ( V_78 * ) & V_32 -> V_79 . V_80 . V_81 [ 0 ] ) = ( V_78 ) 0 ;
F_30 () ;
} else if ( V_72 & V_82 ) {
V_32 -> V_75 = V_76 ;
V_32 -> V_77 = 0 ;
* ( ( V_78 * ) & V_32 -> V_79 . V_80 . V_81 [ 0 ] ) = ( V_78 ) 20 ;
F_30 () ;
}
}
static int F_37 ( struct V_83 * V_84 , unsigned long V_85 ,
void * V_86 )
{
switch ( V_85 ) {
case V_87 :
case V_88 :
case V_89 :
if ( V_34 ) {
F_38 ( V_90 L_11
L_12 ) ;
F_36 () ;
}
break;
}
return V_91 ;
}
static int F_39 ( struct V_92 * V_3 )
{
int error ;
V_31 = V_73 ;
V_33 = V_93 ;
V_2 = V_3 ;
error = F_40 ( & V_2 -> V_3 , F_41 ( 32 ) ) ;
if ( error )
return error ;
error = F_42 ( & V_3 -> V_3 . V_26 , & V_94 ) ;
if ( error )
return error ;
F_43 ( & V_95 ) ;
F_25 ( & V_3 -> V_3 , L_13 ,
V_96 , V_97 ) ;
return 0 ;
}
static int F_44 ( struct V_92 * V_3 )
{
F_45 ( & V_95 ) ;
F_46 ( & V_3 -> V_3 . V_26 , & V_94 ) ;
return 0 ;
}
static int T_7 F_47 ( void )
{
int error ;
error = F_48 ( & V_98 ) ;
if ( error )
return error ;
V_99 = F_49 ( & V_100 ) ;
if ( F_50 ( V_99 ) ) {
error = F_51 ( V_99 ) ;
goto V_101;
}
return 0 ;
V_101:
F_52 ( & V_98 ) ;
return error ;
}
static void T_8 F_53 ( void )
{
F_45 ( & V_95 ) ;
if ( V_2 )
F_1 () ;
F_54 ( V_99 ) ;
F_52 ( & V_98 ) ;
}

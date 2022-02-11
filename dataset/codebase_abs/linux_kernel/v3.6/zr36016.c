static T_1
F_1 ( struct V_1 * V_2 ,
T_2 V_3 )
{
T_1 V_4 = 0 ;
if ( V_2 -> V_5 -> V_6 -> V_7 )
V_4 =
( V_2 -> V_5 -> V_6 ->
V_7 ( V_2 -> V_5 , V_3 ) ) & 0xFF ;
else
F_2 ( 1 ,
V_8 L_1 ,
V_2 -> V_9 ) ;
F_2 ( 4 , L_2 , V_2 -> V_9 , V_3 ,
V_4 ) ;
return V_4 ;
}
static void
F_3 ( struct V_1 * V_2 ,
T_2 V_3 ,
T_1 V_4 )
{
F_2 ( 4 , L_3 , V_2 -> V_9 , V_4 ,
V_3 ) ;
if ( V_2 -> V_5 -> V_6 -> V_10 ) {
V_2 -> V_5 -> V_6 -> V_10 ( V_2 -> V_5 , V_3 , V_4 ) ;
} else
F_2 ( 1 ,
V_8
L_4 ,
V_2 -> V_9 ) ;
}
static T_1
F_4 ( struct V_1 * V_2 ,
T_2 V_3 )
{
T_1 V_4 = 0 ;
if ( ( V_2 -> V_5 -> V_6 -> V_10 ) &&
( V_2 -> V_5 -> V_6 -> V_7 ) ) {
V_2 -> V_5 -> V_6 -> V_10 ( V_2 -> V_5 , V_11 , V_3 & 0x0F ) ;
V_4 = ( V_2 -> V_5 -> V_6 -> V_7 ( V_2 -> V_5 , V_12 ) ) & 0xFF ;
} else
F_2 ( 1 ,
V_8
L_5 ,
V_2 -> V_9 ) ;
F_2 ( 4 , L_6 , V_2 -> V_9 ,
V_3 , V_4 ) ;
return V_4 ;
}
static void
F_5 ( struct V_1 * V_2 ,
T_2 V_3 ,
T_1 V_4 )
{
F_2 ( 4 , L_7 , V_2 -> V_9 ,
V_4 , V_3 ) ;
if ( V_2 -> V_5 -> V_6 -> V_10 ) {
V_2 -> V_5 -> V_6 -> V_10 ( V_2 -> V_5 , V_11 , V_3 & 0x0F ) ;
V_2 -> V_5 -> V_6 -> V_10 ( V_2 -> V_5 , V_12 , V_4 & 0x0FF ) ;
} else
F_2 ( 1 ,
V_8
L_8 ,
V_2 -> V_9 ) ;
}
static T_1
F_6 ( struct V_1 * V_2 )
{
V_2 -> V_13 = F_1 ( V_2 , 0 ) >> 4 ;
return V_2 -> V_13 ;
}
static int
F_7 ( struct V_1 * V_2 )
{
if ( V_14 ) {
int V_15 ;
F_5 ( V_2 , V_16 , 0x55 ) ;
F_2 ( 1 , V_17 L_9 , V_2 -> V_9 ) ;
for ( V_15 = 0 ; V_15 <= 0x0b ; V_15 ++ )
F_2 ( 1 , L_10 , F_4 ( V_2 , V_15 ) ) ;
F_2 ( 1 , L_11 ) ;
}
F_5 ( V_2 , V_16 , 0x00 ) ;
if ( F_4 ( V_2 , V_16 ) != 0x0 ) {
F_2 ( 1 ,
V_8
L_12 ,
V_2 -> V_9 ) ;
return - V_18 ;
}
F_5 ( V_2 , V_16 , 0x0d0 ) ;
if ( F_4 ( V_2 , V_16 ) != 0x0d0 ) {
F_2 ( 1 ,
V_8
L_12 ,
V_2 -> V_9 ) ;
return - V_18 ;
}
F_6 ( V_2 ) ;
if ( V_2 -> V_13 & 0x0c ) {
F_2 ( 1 ,
V_8
L_13 ,
V_2 -> V_9 , V_2 -> V_13 ) ;
return - V_18 ;
}
return 0 ;
}
static void
F_8 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_19 , 0 ) ;
F_3 ( V_2 , V_20 ,
V_21 | V_22 |
( V_2 -> V_23 == V_24 ?
V_25 : V_26 ) ) ;
F_5 ( V_2 , V_27 ,
( V_2 -> V_28 ? ( V_29 | V_30 ) : 0 ) |
( V_2 -> V_31 ? V_32 : 0 ) | V_33 ) ;
F_5 ( V_2 , V_34 , V_35 ) ;
F_5 ( V_2 , V_36 , V_2 -> V_37 >> 8 ) ;
F_5 ( V_2 , V_16 , V_2 -> V_37 & 0xFF ) ;
F_5 ( V_2 , V_38 , V_2 -> V_39 >> 8 ) ;
F_5 ( V_2 , V_40 , V_2 -> V_39 & 0xFF ) ;
F_5 ( V_2 , V_41 , V_2 -> V_42 >> 8 ) ;
F_5 ( V_2 , V_43 , V_2 -> V_42 & 0xFF ) ;
F_5 ( V_2 , V_44 , V_2 -> V_45 >> 8 ) ;
F_5 ( V_2 , V_46 , V_2 -> V_45 & 0xFF ) ;
F_3 ( V_2 , V_19 , 1 ) ;
}
static int
F_9 ( struct V_47 * V_5 ,
int V_23 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 -> V_48 ;
F_2 ( 2 , L_14 , V_2 -> V_9 , V_23 ) ;
if ( ( V_23 != V_49 ) && ( V_23 != V_24 ) )
return - V_50 ;
V_2 -> V_23 = V_23 ;
F_8 ( V_2 ) ;
return 0 ;
}
static int
F_10 ( struct V_47 * V_5 ,
struct V_51 * V_52 ,
struct V_53 * V_54 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 -> V_48 ;
F_2 ( 2 , L_15 ,
V_2 -> V_9 , V_52 -> V_57 , V_52 -> V_58 ,
V_54 -> V_59 , V_54 -> V_60 , V_54 -> V_37 , V_54 -> V_39 ,
V_54 -> V_61 ) ;
V_2 -> V_37 = V_54 -> V_37 ;
V_2 -> V_39 = V_54 -> V_39 ;
V_2 -> V_42 = ( V_52 -> V_57 ? V_52 -> V_57 : 1 ) + V_54 -> V_59 ;
V_2 -> V_45 = V_52 -> V_58 + V_54 -> V_60 ;
V_2 -> V_28 = ( ( V_54 -> V_61 & 0xff ) == 1 ) ? 0 : 1 ;
V_2 -> V_31 = ( ( ( V_54 -> V_61 >> 8 ) & 0xff ) == 1 ) ? 0 : 1 ;
return 0 ;
}
static int
F_11 ( struct V_47 * V_5 ,
int type ,
int V_62 ,
void * V_48 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 -> V_48 ;
int * V_63 = ( int * ) V_48 ;
F_2 ( 2 , L_16 , V_2 -> V_9 , type ,
V_62 ) ;
switch ( type ) {
case V_64 :
if ( V_62 != sizeof( int ) )
return - V_65 ;
* V_63 = 0 ;
break;
case V_66 :
if ( V_62 != sizeof( int ) )
return - V_65 ;
* V_63 = 0 ;
break;
case V_67 :
if ( V_62 != sizeof( int ) )
return - V_65 ;
if ( * V_63 != 0 )
return - V_50 ;
return 0 ;
case V_68 :
case V_69 :
return 0 ;
case V_70 :
return - V_18 ;
default:
return - V_50 ;
}
return V_62 ;
}
static int
F_12 ( struct V_47 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_48 ;
if ( V_2 ) {
F_2 ( 1 , L_17 , V_2 -> V_9 ,
V_2 -> V_71 ) ;
F_13 ( V_2 ) ;
V_5 -> V_48 = NULL ;
V_72 -- ;
return 0 ;
}
return - V_65 ;
}
static int
F_14 ( struct V_47 * V_5 )
{
struct V_1 * V_2 ;
int V_73 ;
F_2 ( 2 , L_18 ,
V_72 ) ;
if ( V_72 == V_74 ) {
F_2 ( 1 ,
V_8 L_19 ) ;
return - V_75 ;
}
V_5 -> V_48 = V_2 = F_15 ( sizeof( struct V_1 ) , V_76 ) ;
if ( NULL == V_2 ) {
F_2 ( 1 , V_8 L_20 ) ;
return - V_77 ;
}
snprintf ( V_2 -> V_9 , sizeof( V_2 -> V_9 ) , L_21 ,
V_72 ) ;
V_2 -> V_71 = V_72 ++ ;
V_2 -> V_5 = V_5 ;
V_73 = F_7 ( V_2 ) ;
if ( V_73 < 0 ) {
F_12 ( V_5 ) ;
return V_73 ;
}
V_2 -> V_23 = V_24 ;
V_2 -> V_37 = 768 ;
V_2 -> V_39 = 288 ;
V_2 -> V_28 = 1 ;
V_2 -> V_31 = 0 ;
F_8 ( V_2 ) ;
F_2 ( 1 , V_17 L_22 ,
V_2 -> V_9 , V_2 -> V_13 ) ;
return 0 ;
}
static int T_3
F_16 ( void )
{
V_72 = 0 ;
return F_17 ( & V_78 ) ;
}
static void T_4
F_18 ( void )
{
if ( V_72 ) {
F_2 ( 1 ,
L_23 ,
V_72 ) ;
}
F_19 ( & V_78 ) ;
}

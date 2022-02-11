static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 ;
V_3 = F_2 ( V_2 -> V_5 ,
F_3 ( V_2 -> V_5 , 0 ) ,
V_6 ,
V_7 | V_8 | V_9 ,
0x00 , 0xC7 , V_2 -> V_10 , 8 , 300 ) ;
if ( V_3 < 0 ) {
V_4 = V_6 ;
goto V_11;
}
V_3 = F_2 ( V_2 -> V_5 ,
F_3 ( V_2 -> V_5 , 0 ) ,
V_12 ,
V_7 | V_8 | V_9 ,
0x01 , 0x00 , V_2 -> V_10 , 8 , 300 ) ;
if ( V_3 < 0 ) {
V_4 = V_12 ;
goto V_11;
}
V_2 -> V_13 = V_14 ;
return ( V_2 -> V_10 ) [ 0 ] ;
V_11:
F_4 ( & V_2 -> V_5 -> V_15 ,
L_1 ,
V_16 , V_3 , V_4 ) ;
return V_3 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 ;
V_3 = F_2 ( V_2 -> V_5 ,
F_3 ( V_2 -> V_5 , 0 ) ,
V_6 ,
V_7 | V_8 | V_9 ,
0x16 , 0x1C , V_2 -> V_10 , 8 , 300 ) ;
if ( V_3 < 0 ) {
V_4 = V_6 ;
goto V_11;
}
V_3 = F_2 ( V_2 -> V_5 ,
F_3 ( V_2 -> V_5 , 0 ) ,
V_12 ,
V_7 | V_8 | V_9 ,
0x00 , 0x00 , V_2 -> V_10 , 8 , 300 ) ;
if ( V_3 < 0 ) {
V_4 = V_12 ;
goto V_11;
}
V_2 -> V_13 = V_17 ;
return ( V_2 -> V_10 ) [ 0 ] ;
V_11:
F_4 ( & V_2 -> V_5 -> V_15 ,
L_1 ,
V_16 , V_3 , V_4 ) ;
return V_3 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 ;
int V_18 = ( V_2 -> V_19 / 16 * 80 ) / 1000 + 856 ;
V_3 = F_2 ( V_2 -> V_5 ,
F_3 ( V_2 -> V_5 , 0 ) ,
V_20 ,
V_7 | V_8 | V_9 ,
( V_18 >> 8 ) & 0x00ff , V_18 & 0xff ,
V_2 -> V_10 , 8 , 300 ) ;
if ( V_3 < 0 ) {
V_4 = V_20 ;
goto V_11;
}
V_3 = F_2 ( V_2 -> V_5 ,
F_3 ( V_2 -> V_5 , 0 ) ,
V_6 ,
V_7 | V_8 | V_9 ,
0x96 , 0xB7 , V_2 -> V_10 , 8 , 300 ) ;
if ( V_3 < 0 ) {
V_4 = V_6 ;
goto V_11;
}
V_3 = F_2 ( V_2 -> V_5 ,
F_3 ( V_2 -> V_5 , 0 ) ,
V_6 ,
V_7 | V_8 | V_9 ,
0x00 , 0x24 , V_2 -> V_10 , 8 , 300 ) ;
if ( V_3 < 0 ) {
V_4 = V_6 ;
goto V_11;
}
V_2 -> V_21 = ! ( ( V_2 -> V_10 ) [ 0 ] & 0x01 ) ;
return ( V_2 -> V_10 ) [ 0 ] ;
V_11:
V_2 -> V_21 = - 1 ;
F_4 ( & V_2 -> V_5 -> V_15 ,
L_1 ,
V_16 , V_3 , V_4 ) ;
return V_3 ;
}
static void F_7 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_5 ,
F_3 ( V_2 -> V_5 , 0 ) ,
V_6 ,
V_7 | V_8 | V_9 ,
0x00 , 0x24 , V_2 -> V_10 , 8 , 300 ) ;
if ( V_3 < 0 ) {
V_2 -> V_21 = - 1 ;
F_4 ( & V_2 -> V_5 -> V_15 ,
L_1 ,
V_16 , V_3 , V_6 ) ;
} else {
V_2 -> V_21 = ! ( V_2 -> V_10 [ 0 ] & 0x01 ) ;
}
}
static int F_8 ( struct V_22 * V_22 , void * V_23 ,
struct V_24 * V_25 )
{
struct V_1 * V_2 = F_9 ( V_22 ) ;
F_10 ( V_25 -> V_26 , L_2 , sizeof( V_25 -> V_26 ) ) ;
F_10 ( V_25 -> V_27 , L_3 , sizeof( V_25 -> V_27 ) ) ;
F_11 ( V_2 -> V_5 , V_25 -> V_28 , sizeof( V_25 -> V_28 ) ) ;
V_25 -> V_29 = V_30 ;
return 0 ;
}
static int F_12 ( struct V_22 * V_22 , void * V_23 ,
struct V_31 * V_25 )
{
struct V_1 * V_2 = F_9 ( V_22 ) ;
if ( V_25 -> V_32 > 0 )
return - V_33 ;
F_7 ( V_2 ) ;
strcpy ( V_25 -> V_34 , L_4 ) ;
V_25 -> type = V_35 ;
V_25 -> V_36 = V_37 * V_38 ;
V_25 -> V_39 = V_40 * V_38 ;
V_25 -> V_41 = V_42 | V_43 ;
V_25 -> V_44 = V_45 ;
if( V_2 -> V_21 )
V_25 -> V_46 = V_47 ;
else
V_25 -> V_46 = V_48 ;
V_25 -> signal = 0xffff ;
return 0 ;
}
static int F_13 ( struct V_22 * V_22 , void * V_23 ,
struct V_31 * V_25 )
{
return V_25 -> V_32 ? - V_33 : 0 ;
}
static int F_14 ( struct V_22 * V_22 , void * V_23 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 = F_9 ( V_22 ) ;
int V_3 ;
V_2 -> V_19 = V_50 -> V_51 ;
V_3 = F_6 ( V_2 ) ;
if ( V_3 < 0 )
F_15 ( & V_2 -> V_5 -> V_15 , L_5 ) ;
return 0 ;
}
static int F_16 ( struct V_22 * V_22 , void * V_23 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 = F_9 ( V_22 ) ;
V_50 -> type = V_35 ;
V_50 -> V_51 = V_2 -> V_19 ;
return 0 ;
}
static int F_17 ( struct V_22 * V_22 , void * V_23 ,
struct V_52 * V_53 )
{
switch ( V_53 -> V_54 ) {
case V_55 :
return F_18 ( V_53 , 0 , 1 , 1 , 1 ) ;
}
return - V_33 ;
}
static int F_19 ( struct V_22 * V_22 , void * V_23 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = F_9 ( V_22 ) ;
switch ( V_57 -> V_54 ) {
case V_55 :
V_57 -> V_58 = V_2 -> V_13 ;
return 0 ;
}
return - V_33 ;
}
static int F_20 ( struct V_22 * V_22 , void * V_23 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = F_9 ( V_22 ) ;
int V_3 ;
switch ( V_57 -> V_54 ) {
case V_55 :
if ( V_57 -> V_58 ) {
V_3 = F_5 ( V_2 ) ;
if ( V_3 < 0 ) {
F_15 ( & V_2 -> V_5 -> V_15 ,
L_6 ) ;
return - V_59 ;
}
} else {
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_15 ( & V_2 -> V_5 -> V_15 ,
L_6 ) ;
return - V_59 ;
}
}
return 0 ;
}
return - V_33 ;
}
static int F_21 ( struct V_22 * V_22 , void * V_23 ,
struct V_60 * V_61 )
{
if ( V_61 -> V_32 > 1 )
return - V_33 ;
strcpy ( V_61 -> V_34 , L_7 ) ;
V_61 -> V_44 = V_62 ;
return 0 ;
}
static int F_22 ( struct V_22 * V_63 , void * V_23 , unsigned int * V_64 )
{
* V_64 = 0 ;
return 0 ;
}
static int F_23 ( struct V_22 * V_63 , void * V_23 , unsigned int V_64 )
{
return V_64 ? - V_33 : 0 ;
}
static int F_24 ( struct V_22 * V_22 , void * V_23 ,
struct V_60 * V_61 )
{
return V_61 -> V_32 ? - V_33 : 0 ;
}
static void F_25 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_26 ( V_66 ) ;
F_27 ( & V_2 -> V_67 ) ;
F_28 ( & V_2 -> V_68 ) ;
F_29 ( V_66 , NULL ) ;
F_30 ( & V_2 -> V_69 ) ;
F_31 ( & V_2 -> V_67 ) ;
F_32 ( & V_2 -> V_68 ) ;
F_33 ( & V_2 -> V_67 ) ;
}
static int F_34 ( struct V_65 * V_66 , T_1 V_70 )
{
struct V_1 * V_2 = F_26 ( V_66 ) ;
int V_3 ;
F_28 ( & V_2 -> V_68 ) ;
if ( V_2 -> V_13 == V_14 ) {
V_3 = F_5 ( V_2 ) ;
if ( V_3 < 0 )
F_15 ( & V_66 -> V_15 , L_8 ) ;
V_2 -> V_13 = V_14 ;
}
F_32 ( & V_2 -> V_68 ) ;
F_35 ( & V_66 -> V_15 , L_9 ) ;
return 0 ;
}
static int F_36 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_26 ( V_66 ) ;
int V_3 ;
F_28 ( & V_2 -> V_68 ) ;
if ( V_2 -> V_13 == V_14 ) {
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
F_15 ( & V_66 -> V_15 , L_10 ) ;
}
F_32 ( & V_2 -> V_68 ) ;
F_35 ( & V_66 -> V_15 , L_11 ) ;
return 0 ;
}
static void F_37 ( struct V_71 * V_67 )
{
struct V_1 * V_2 = F_38 ( V_67 ) ;
F_39 ( & V_2 -> V_67 ) ;
F_40 ( V_2 -> V_10 ) ;
F_40 ( V_2 ) ;
}
static int F_41 ( struct V_65 * V_66 ,
const struct V_72 * V_54 )
{
struct V_1 * V_2 ;
struct V_71 * V_67 ;
int V_3 ;
V_2 = F_42 ( sizeof( struct V_1 ) , V_73 ) ;
if ( ! V_2 )
return - V_74 ;
V_2 -> V_10 = F_43 ( V_75 , V_73 ) ;
if ( ! ( V_2 -> V_10 ) ) {
F_40 ( V_2 ) ;
return - V_74 ;
}
V_67 = & V_2 -> V_67 ;
V_67 -> V_76 = F_37 ;
V_3 = F_44 ( & V_66 -> V_15 , V_67 ) ;
if ( V_3 < 0 ) {
F_45 ( V_67 , L_12 ) ;
F_40 ( V_2 -> V_10 ) ;
F_40 ( V_2 ) ;
return V_3 ;
}
F_46 ( & V_2 -> V_68 ) ;
F_10 ( V_2 -> V_69 . V_34 , V_67 -> V_34 , sizeof( V_2 -> V_69 . V_34 ) ) ;
V_2 -> V_69 . V_67 = V_67 ;
V_2 -> V_69 . V_77 = & V_78 ;
V_2 -> V_69 . V_79 = & V_80 ;
V_2 -> V_69 . V_76 = V_81 ;
V_2 -> V_69 . V_82 = & V_2 -> V_68 ;
V_2 -> V_5 = F_47 ( V_66 ) ;
V_2 -> V_19 = V_37 * V_38 ;
V_2 -> V_13 = V_17 ;
F_48 ( & V_2 -> V_69 , V_2 ) ;
V_3 = F_49 ( & V_2 -> V_69 , V_83 , V_84 ) ;
if ( V_3 < 0 ) {
F_45 ( V_67 , L_13 ) ;
F_39 ( V_67 ) ;
F_40 ( V_2 -> V_10 ) ;
F_40 ( V_2 ) ;
return - V_85 ;
}
F_29 ( V_66 , V_2 ) ;
return 0 ;
}
static int T_2 F_50 ( void )
{
int V_3 = F_51 ( & V_86 ) ;
F_52 (KERN_INFO KBUILD_MODNAME L_14 DRIVER_VERSION L_15
DRIVER_DESC L_16 ) ;
return V_3 ;
}
static void T_3 F_53 ( void )
{
F_54 ( & V_86 ) ;
}

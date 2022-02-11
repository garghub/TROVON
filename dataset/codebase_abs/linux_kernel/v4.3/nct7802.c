static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_4 ) ;
unsigned int V_10 ;
int V_11 ;
V_11 = F_4 ( V_7 -> V_12 , V_13 , & V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
return sprintf ( V_5 , L_1 , ( V_10 >> ( 2 * V_9 -> V_14 ) & 3 ) + 2 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_15 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_4 ) ;
unsigned int type ;
int V_16 ;
V_16 = F_6 ( V_5 , 0 , & type ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_9 -> V_14 == 2 && type != 4 )
return - V_17 ;
if ( type < 3 || type > 4 )
return - V_17 ;
V_16 = F_7 ( V_7 -> V_12 , V_13 ,
3 << 2 * V_9 -> V_14 , ( type - 2 ) << 2 * V_9 -> V_14 ) ;
return V_16 ? : V_15 ;
}
static T_1 F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_8 * V_9 = F_3 ( V_4 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_18 ;
int V_11 ;
if ( V_9 -> V_14 > 1 )
return sprintf ( V_5 , L_2 ) ;
V_11 = F_4 ( V_7 -> V_12 , 0x5E , & V_18 ) ;
if ( V_11 < 0 )
return V_11 ;
return sprintf ( V_5 , L_1 , ! ( V_18 & ( 1 << V_9 -> V_14 ) ) ) ;
}
static T_1 F_9 ( struct V_1 * V_2 , struct V_3 * V_19 ,
char * V_5 )
{
struct V_8 * V_4 = F_3 ( V_19 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_20 ;
int V_11 ;
if ( ! V_4 -> V_14 )
return sprintf ( V_5 , L_3 ) ;
V_11 = F_4 ( V_7 -> V_12 , V_4 -> V_14 , & V_20 ) ;
if ( V_11 < 0 )
return V_11 ;
return sprintf ( V_5 , L_4 , V_20 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 , struct V_3 * V_19 ,
const char * V_5 , T_2 V_15 )
{
struct V_8 * V_4 = F_3 ( V_19 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_16 ;
T_3 V_20 ;
V_16 = F_11 ( V_5 , 0 , & V_20 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_12 ( V_7 -> V_12 , V_4 -> V_14 , V_20 ) ;
return V_16 ? : V_15 ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_4 ) ;
unsigned int V_21 , V_22 ;
int V_11 ;
V_11 = F_4 ( V_7 -> V_12 , F_14 ( V_9 -> V_14 ) , & V_21 ) ;
if ( V_11 < 0 )
return V_11 ;
V_22 = V_21 >> F_15 ( V_9 -> V_14 ) & 1 ;
return sprintf ( V_5 , L_1 , V_22 + 1 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_15 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_4 ) ;
T_3 V_20 ;
int V_11 ;
V_11 = F_11 ( V_5 , 0 , & V_20 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_20 < 1 || V_20 > 2 )
return - V_17 ;
V_11 = F_7 ( V_7 -> V_12 , F_14 ( V_9 -> V_14 ) ,
1 << F_15 ( V_9 -> V_14 ) ,
( V_20 - 1 ) << F_15 ( V_9 -> V_14 ) ) ;
return V_11 ? : V_15 ;
}
static int F_17 ( struct V_6 * V_7 ,
T_3 V_23 , T_3 V_24 , int * V_25 )
{
unsigned int V_26 , V_27 = 0 ;
int V_16 ;
* V_25 = 0 ;
F_18 ( & V_7 -> V_28 ) ;
V_16 = F_4 ( V_7 -> V_12 , V_23 , & V_26 ) ;
if ( V_16 < 0 )
goto abort;
V_26 <<= 8 ;
if ( V_24 ) {
V_16 = F_4 ( V_7 -> V_12 , V_24 , & V_27 ) ;
if ( V_16 < 0 )
goto abort;
}
V_26 |= V_27 & 0xe0 ;
* V_25 = ( V_29 ) V_26 / 32 * 125 ;
abort:
F_19 ( & V_7 -> V_28 ) ;
return V_16 ;
}
static int F_20 ( struct V_6 * V_7 , T_3 V_30 )
{
unsigned int V_31 , V_32 ;
int V_11 ;
F_18 ( & V_7 -> V_28 ) ;
V_11 = F_4 ( V_7 -> V_12 , V_30 , & V_31 ) ;
if ( V_11 < 0 )
goto abort;
V_11 = F_4 ( V_7 -> V_12 , V_33 , & V_32 ) ;
if ( V_11 < 0 )
goto abort;
V_11 = ( V_31 << 5 ) | ( V_32 >> 3 ) ;
if ( V_11 == 0x1fff )
V_11 = 0 ;
else if ( V_11 )
V_11 = F_21 ( 1350000U , V_11 ) ;
abort:
F_19 ( & V_7 -> V_28 ) ;
return V_11 ;
}
static int F_22 ( struct V_6 * V_7 , T_3 V_34 ,
T_3 V_35 )
{
unsigned int V_31 , V_32 ;
int V_11 ;
F_18 ( & V_7 -> V_28 ) ;
V_11 = F_4 ( V_7 -> V_12 , V_34 , & V_31 ) ;
if ( V_11 < 0 )
goto abort;
V_11 = F_4 ( V_7 -> V_12 , V_35 , & V_32 ) ;
if ( V_11 < 0 )
goto abort;
V_11 = V_31 | ( ( V_32 & 0xf8 ) << 5 ) ;
if ( V_11 == 0x1fff )
V_11 = 0 ;
else if ( V_11 )
V_11 = F_21 ( 1350000U , V_11 ) ;
abort:
F_19 ( & V_7 -> V_28 ) ;
return V_11 ;
}
static int F_23 ( struct V_6 * V_7 , T_3 V_34 ,
T_3 V_35 , unsigned int V_36 )
{
int V_16 ;
if ( V_36 )
V_36 = F_21 ( 1350000U , V_36 ) ;
else
V_36 = 0x1fff ;
V_36 = F_24 ( V_36 , 0 , 0x1fff ) ;
F_18 ( & V_7 -> V_28 ) ;
V_16 = F_12 ( V_7 -> V_12 , V_34 , V_36 & 0xff ) ;
if ( V_16 < 0 )
goto abort;
V_16 = F_12 ( V_7 -> V_12 , V_35 , ( V_36 & 0x1f00 ) >> 5 ) ;
abort:
F_19 ( & V_7 -> V_28 ) ;
return V_16 ;
}
static int F_25 ( struct V_6 * V_7 , int V_37 , int V_14 )
{
unsigned int V_38 , V_39 ;
int V_11 ;
F_18 ( & V_7 -> V_28 ) ;
if ( V_14 == 0 ) {
V_11 = F_4 ( V_7 -> V_12 , V_40 [ V_37 ] , & V_38 ) ;
if ( V_11 < 0 )
goto abort;
V_11 = F_4 ( V_7 -> V_12 , V_41 , & V_39 ) ;
if ( V_11 < 0 )
goto abort;
V_11 = ( ( V_38 << 2 ) | ( V_39 >> 6 ) ) * V_42 [ V_37 ] ;
} else {
int V_43 = 8 - V_44 [ V_14 - 1 ] [ V_37 ] ;
V_11 = F_4 ( V_7 -> V_12 ,
V_45 [ V_14 - 1 ] [ V_37 ] , & V_38 ) ;
if ( V_11 < 0 )
goto abort;
V_11 = F_4 ( V_7 -> V_12 , V_46 [ V_37 ] ,
& V_39 ) ;
if ( V_11 < 0 )
goto abort;
V_11 = ( V_38 | ( ( V_39 << V_43 ) & 0x300 ) ) * V_42 [ V_37 ] ;
}
abort:
F_19 ( & V_7 -> V_28 ) ;
return V_11 ;
}
static int F_26 ( struct V_6 * V_7 , int V_37 , int V_14 ,
unsigned long V_47 )
{
int V_43 = 8 - V_44 [ V_14 - 1 ] [ V_37 ] ;
int V_16 ;
V_47 = F_21 ( V_47 , V_42 [ V_37 ] ) ;
V_47 = F_24 ( V_47 , 0 , 0x3ff ) ;
F_18 ( & V_7 -> V_28 ) ;
V_16 = F_12 ( V_7 -> V_12 ,
V_45 [ V_14 - 1 ] [ V_37 ] ,
V_47 & 0xff ) ;
if ( V_16 < 0 )
goto abort;
V_16 = F_7 ( V_7 -> V_12 , V_46 [ V_37 ] ,
0x0300 >> V_43 , ( V_47 & 0x0300 ) >> V_43 ) ;
abort:
F_19 ( & V_7 -> V_28 ) ;
return V_16 ;
}
static T_1 F_27 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_48 * V_9 = F_28 ( V_4 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_47 ;
V_47 = F_25 ( V_7 , V_9 -> V_37 , V_9 -> V_14 ) ;
if ( V_47 < 0 )
return V_47 ;
return sprintf ( V_5 , L_4 , V_47 ) ;
}
static T_1 F_29 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_15 )
{
struct V_48 * V_9 = F_28 ( V_4 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_14 = V_9 -> V_14 ;
int V_37 = V_9 -> V_37 ;
unsigned long V_20 ;
int V_16 ;
V_16 = F_30 ( V_5 , 10 , & V_20 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_26 ( V_7 , V_37 , V_14 , V_20 ) ;
return V_16 ? : V_15 ;
}
static T_1 F_31 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_48 * V_9 = F_28 ( V_4 ) ;
int V_16 , V_25 ;
V_16 = F_17 ( V_7 , V_9 -> V_37 , V_9 -> V_14 , & V_25 ) ;
if ( V_16 < 0 )
return V_16 ;
return sprintf ( V_5 , L_4 , V_25 ) ;
}
static T_1 F_32 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_15 )
{
struct V_48 * V_9 = F_28 ( V_4 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_37 = V_9 -> V_37 ;
long V_20 ;
int V_16 ;
V_16 = F_33 ( V_5 , 10 , & V_20 ) ;
if ( V_16 < 0 )
return V_16 ;
V_20 = F_24 ( F_21 ( V_20 , 1000 ) , - 128 , 127 ) ;
V_16 = F_12 ( V_7 -> V_12 , V_37 , V_20 & 0xff ) ;
return V_16 ? : V_15 ;
}
static T_1 F_34 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_8 * V_9 = F_3 ( V_4 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_49 ;
V_49 = F_20 ( V_7 , V_9 -> V_14 ) ;
if ( V_49 < 0 )
return V_49 ;
return sprintf ( V_5 , L_4 , V_49 ) ;
}
static T_1 F_35 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_48 * V_9 = F_28 ( V_4 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_49 ;
V_49 = F_22 ( V_7 , V_9 -> V_37 , V_9 -> V_14 ) ;
if ( V_49 < 0 )
return V_49 ;
return sprintf ( V_5 , L_4 , V_49 ) ;
}
static T_1 F_36 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_15 )
{
struct V_48 * V_9 = F_28 ( V_4 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned long V_20 ;
int V_16 ;
V_16 = F_30 ( V_5 , 10 , & V_20 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_23 ( V_7 , V_9 -> V_37 , V_9 -> V_14 , V_20 ) ;
return V_16 ? : V_15 ;
}
static T_1 F_37 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_48 * V_9 = F_28 ( V_4 ) ;
int V_50 = V_9 -> V_14 ;
unsigned int V_20 ;
int V_11 ;
V_11 = F_4 ( V_7 -> V_12 , V_9 -> V_37 , & V_20 ) ;
if ( V_11 < 0 )
return V_11 ;
return sprintf ( V_5 , L_1 , ! ! ( V_20 & ( 1 << V_50 ) ) ) ;
}
static T_1
F_38 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_48 * V_9 = F_28 ( V_4 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_18 ;
int V_16 ;
V_16 = F_4 ( V_7 -> V_12 , V_9 -> V_37 , & V_18 ) ;
if ( V_16 )
return V_16 ;
return sprintf ( V_5 , L_1 , ! ! ( V_18 & ( 1 << V_9 -> V_14 ) ) ) ;
}
static T_1
F_39 ( struct V_1 * V_2 , struct V_3 * V_4 , const char * V_5 ,
T_2 V_15 )
{
struct V_48 * V_9 = F_28 ( V_4 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned long V_20 ;
int V_16 ;
V_16 = F_30 ( V_5 , 10 , & V_20 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_20 > 1 )
return - V_17 ;
V_16 = F_7 ( V_7 -> V_12 , V_9 -> V_37 , 1 << V_9 -> V_14 ,
V_20 ? 1 << V_9 -> V_14 : 0 ) ;
return V_16 ? : V_15 ;
}
static T_4 F_40 ( struct V_51 * V_52 ,
struct V_53 * V_4 , int V_14 )
{
struct V_1 * V_2 = F_41 ( V_52 , struct V_1 , V_52 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_21 ;
int V_16 ;
V_16 = F_4 ( V_7 -> V_12 , V_13 , & V_21 ) ;
if ( V_16 < 0 )
return 0 ;
if ( V_14 < 10 &&
( V_21 & 03 ) != 0x01 && ( V_21 & 0x03 ) != 0x02 )
return 0 ;
if ( V_14 >= 10 && V_14 < 20 &&
( V_21 & 0x0c ) != 0x04 && ( V_21 & 0x0c ) != 0x08 )
return 0 ;
if ( V_14 >= 20 && V_14 < 30 && ( V_21 & 0x30 ) != 0x20 )
return 0 ;
if ( V_14 >= 30 && V_14 < 38 )
return V_4 -> V_10 ;
V_16 = F_4 ( V_7 -> V_12 , V_54 , & V_21 ) ;
if ( V_16 < 0 )
return 0 ;
if ( V_14 >= 38 && V_14 < 46 && ! ( V_21 & 0x01 ) )
return 0 ;
if ( V_14 >= 0x46 && ( ! ( V_21 & 0x02 ) ) )
return 0 ;
return V_4 -> V_10 ;
}
static T_4 F_42 ( struct V_51 * V_52 ,
struct V_53 * V_4 , int V_14 )
{
struct V_1 * V_2 = F_41 ( V_52 , struct V_1 , V_52 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned int V_21 ;
int V_16 ;
if ( V_14 < 6 )
return V_4 -> V_10 ;
V_16 = F_4 ( V_7 -> V_12 , V_13 , & V_21 ) ;
if ( V_16 < 0 )
return 0 ;
if ( V_14 >= 6 && V_14 < 11 && ( V_21 & 0x03 ) != 0x03 )
return 0 ;
if ( V_14 >= 11 && V_14 < 17 && ( V_21 & 0x0c ) != 0x0c )
return 0 ;
if ( V_14 >= 17 && ( V_21 & 0x30 ) != 0x30 )
return 0 ;
return V_4 -> V_10 ;
}
static T_4 F_43 ( struct V_51 * V_52 ,
struct V_53 * V_4 , int V_14 )
{
struct V_1 * V_2 = F_41 ( V_52 , struct V_1 , V_52 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_55 = V_14 / 4 ;
unsigned int V_21 ;
int V_16 ;
V_16 = F_4 ( V_7 -> V_12 , V_56 , & V_21 ) ;
if ( V_16 < 0 || ! ( V_21 & ( 1 << V_55 ) ) )
return 0 ;
return V_4 -> V_10 ;
}
static int F_44 ( struct V_57 * V_58 ,
struct V_59 * V_60 )
{
int V_21 ;
V_21 = F_45 ( V_58 , V_61 ) ;
if ( V_21 != 0x00 )
return - V_62 ;
V_21 = F_45 ( V_58 , V_63 ) ;
if ( V_21 != 0x50 )
return - V_62 ;
V_21 = F_45 ( V_58 , V_64 ) ;
if ( V_21 != 0xc3 )
return - V_62 ;
V_21 = F_45 ( V_58 , V_65 ) ;
if ( V_21 < 0 || ( V_21 & 0xf0 ) != 0x20 )
return - V_62 ;
V_21 = F_45 ( V_58 , V_66 ) ;
if ( V_21 < 0 || ( V_21 & 0x1f ) )
return - V_62 ;
V_21 = F_45 ( V_58 , V_67 ) ;
if ( V_21 < 0 || ( V_21 & 0x3f ) )
return - V_62 ;
V_21 = F_45 ( V_58 , V_41 ) ;
if ( V_21 < 0 || ( V_21 & 0x3f ) )
return - V_62 ;
F_46 ( V_60 -> type , L_5 , V_68 ) ;
return 0 ;
}
static bool F_47 ( struct V_1 * V_2 , unsigned int V_21 )
{
return ( V_21 != V_61 && V_21 <= 0x20 ) ||
( V_21 >= F_48 ( 0 ) && V_21 <= F_48 ( 2 ) ) ;
}
static int F_49 ( struct V_6 * V_7 )
{
int V_16 ;
V_16 = F_7 ( V_7 -> V_12 , V_69 , 0x01 , 0x01 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_7 ( V_7 -> V_12 , V_13 , 0x40 , 0x40 ) ;
if ( V_16 )
return V_16 ;
return F_7 ( V_7 -> V_12 , V_70 , 0x03 , 0x03 ) ;
}
static int F_50 ( struct V_57 * V_58 ,
const struct V_71 * V_72 )
{
struct V_1 * V_2 = & V_58 -> V_2 ;
struct V_6 * V_7 ;
struct V_1 * V_73 ;
int V_11 ;
V_7 = F_51 ( V_2 , sizeof( * V_7 ) , V_74 ) ;
if ( V_7 == NULL )
return - V_75 ;
V_7 -> V_12 = F_52 ( V_58 , & V_76 ) ;
if ( F_53 ( V_7 -> V_12 ) )
return F_54 ( V_7 -> V_12 ) ;
F_55 ( & V_7 -> V_28 ) ;
V_11 = F_49 ( V_7 ) ;
if ( V_11 < 0 )
return V_11 ;
V_73 = F_56 ( V_2 , V_58 -> V_77 ,
V_7 ,
V_78 ) ;
return F_57 ( V_73 ) ;
}

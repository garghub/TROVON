static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , int * V_5 )
{
unsigned int V_6 , V_7 = 0 ;
int V_8 ;
* V_5 = 0 ;
F_2 ( & V_2 -> V_9 ) ;
V_8 = F_3 ( V_2 -> V_10 , V_3 , & V_6 ) ;
if ( V_8 < 0 )
goto abort;
V_6 <<= 8 ;
if ( V_4 ) {
V_8 = F_3 ( V_2 -> V_10 , V_4 , & V_7 ) ;
if ( V_8 < 0 )
goto abort;
}
V_6 |= V_7 & 0xe0 ;
* V_5 = ( V_11 ) V_6 / 32 * 125 ;
abort:
F_4 ( & V_2 -> V_9 ) ;
return V_8 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_12 )
{
unsigned int V_13 , V_14 ;
int V_15 ;
F_2 ( & V_2 -> V_9 ) ;
V_15 = F_3 ( V_2 -> V_10 , V_12 , & V_13 ) ;
if ( V_15 < 0 )
goto abort;
V_15 = F_3 ( V_2 -> V_10 , V_16 , & V_14 ) ;
if ( V_15 < 0 )
goto abort;
V_15 = ( V_13 << 5 ) | ( V_14 >> 3 ) ;
if ( V_15 == 0x1fff )
V_15 = 0 ;
else if ( V_15 )
V_15 = F_6 ( 1350000U , V_15 ) ;
abort:
F_4 ( & V_2 -> V_9 ) ;
return V_15 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_17 ,
T_1 V_18 )
{
unsigned int V_13 , V_14 ;
int V_15 ;
F_2 ( & V_2 -> V_9 ) ;
V_15 = F_3 ( V_2 -> V_10 , V_17 , & V_13 ) ;
if ( V_15 < 0 )
goto abort;
V_15 = F_3 ( V_2 -> V_10 , V_18 , & V_14 ) ;
if ( V_15 < 0 )
goto abort;
V_15 = V_13 | ( ( V_14 & 0xf8 ) << 5 ) ;
if ( V_15 == 0x1fff )
V_15 = 0 ;
else if ( V_15 )
V_15 = F_6 ( 1350000U , V_15 ) ;
abort:
F_4 ( & V_2 -> V_9 ) ;
return V_15 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_17 ,
T_1 V_18 , unsigned int V_19 )
{
int V_8 ;
if ( V_19 )
V_19 = F_6 ( 1350000U , V_19 ) ;
else
V_19 = 0x1fff ;
V_19 = F_9 ( V_19 , 0 , 0x1fff ) ;
F_2 ( & V_2 -> V_9 ) ;
V_8 = F_10 ( V_2 -> V_10 , V_17 , V_19 & 0xff ) ;
if ( V_8 < 0 )
goto abort;
V_8 = F_10 ( V_2 -> V_10 , V_18 , ( V_19 & 0x1f00 ) >> 5 ) ;
abort:
F_4 ( & V_2 -> V_9 ) ;
return V_8 ;
}
static int F_11 ( struct V_1 * V_2 , int V_20 , int V_21 )
{
unsigned int V_22 , V_23 ;
int V_15 ;
F_2 ( & V_2 -> V_9 ) ;
if ( V_21 == 0 ) {
V_15 = F_3 ( V_2 -> V_10 , V_24 [ V_20 ] , & V_22 ) ;
if ( V_15 < 0 )
goto abort;
V_15 = F_3 ( V_2 -> V_10 , V_25 , & V_23 ) ;
if ( V_15 < 0 )
goto abort;
V_15 = ( ( V_22 << 2 ) | ( V_23 >> 6 ) ) * V_26 [ V_20 ] ;
} else {
int V_27 = 8 - V_28 [ V_21 - 1 ] [ V_20 ] ;
V_15 = F_3 ( V_2 -> V_10 ,
V_29 [ V_21 - 1 ] [ V_20 ] , & V_22 ) ;
if ( V_15 < 0 )
goto abort;
V_15 = F_3 ( V_2 -> V_10 , V_30 [ V_20 ] ,
& V_23 ) ;
if ( V_15 < 0 )
goto abort;
V_15 = ( V_22 | ( ( V_23 << V_27 ) & 0x300 ) ) * V_26 [ V_20 ] ;
}
abort:
F_4 ( & V_2 -> V_9 ) ;
return V_15 ;
}
static int F_12 ( struct V_1 * V_2 , int V_20 , int V_21 ,
unsigned int V_31 )
{
int V_27 = 8 - V_28 [ V_21 - 1 ] [ V_20 ] ;
int V_8 ;
V_31 = F_6 ( V_31 , V_26 [ V_20 ] ) ;
V_31 = F_9 ( V_31 , 0 , 0x3ff ) ;
F_2 ( & V_2 -> V_9 ) ;
V_8 = F_10 ( V_2 -> V_10 ,
V_29 [ V_21 - 1 ] [ V_20 ] ,
V_31 & 0xff ) ;
if ( V_8 < 0 )
goto abort;
V_8 = F_13 ( V_2 -> V_10 , V_30 [ V_20 ] ,
0x0300 >> V_27 , ( V_31 & 0x0300 ) >> V_27 ) ;
abort:
F_4 ( & V_2 -> V_9 ) ;
return V_8 ;
}
static T_2 F_14 ( struct V_32 * V_33 , struct V_34 * V_35 ,
char * V_36 )
{
struct V_37 * V_38 = F_15 ( V_35 ) ;
struct V_1 * V_2 = F_16 ( V_33 ) ;
int V_31 ;
V_31 = F_11 ( V_2 , V_38 -> V_20 , V_38 -> V_21 ) ;
if ( V_31 < 0 )
return V_31 ;
return sprintf ( V_36 , L_1 , V_31 ) ;
}
static T_2 F_17 ( struct V_32 * V_33 , struct V_34 * V_35 ,
const char * V_36 , T_3 V_39 )
{
struct V_37 * V_38 = F_15 ( V_35 ) ;
struct V_1 * V_2 = F_16 ( V_33 ) ;
int V_21 = V_38 -> V_21 ;
int V_20 = V_38 -> V_20 ;
unsigned long V_40 ;
int V_8 ;
V_8 = F_18 ( V_36 , 10 , & V_40 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_12 ( V_2 , V_20 , V_21 , V_40 ) ;
return V_8 ? : V_39 ;
}
static T_2 F_19 ( struct V_32 * V_33 , struct V_34 * V_35 ,
char * V_36 )
{
struct V_1 * V_2 = F_16 ( V_33 ) ;
struct V_37 * V_38 = F_15 ( V_35 ) ;
int V_8 , V_5 ;
V_8 = F_1 ( V_2 , V_38 -> V_20 , V_38 -> V_21 , & V_5 ) ;
if ( V_8 < 0 )
return V_8 ;
return sprintf ( V_36 , L_1 , V_5 ) ;
}
static T_2 F_20 ( struct V_32 * V_33 , struct V_34 * V_35 ,
const char * V_36 , T_3 V_39 )
{
struct V_37 * V_38 = F_15 ( V_35 ) ;
struct V_1 * V_2 = F_16 ( V_33 ) ;
int V_20 = V_38 -> V_20 ;
long V_40 ;
int V_8 ;
V_8 = F_21 ( V_36 , 10 , & V_40 ) ;
if ( V_8 < 0 )
return V_8 ;
V_40 = F_9 ( F_6 ( V_40 , 1000 ) , - 128 , 127 ) ;
V_8 = F_10 ( V_2 -> V_10 , V_20 , V_40 & 0xff ) ;
return V_8 ? : V_39 ;
}
static T_2 F_22 ( struct V_32 * V_33 , struct V_34 * V_35 ,
char * V_36 )
{
struct V_41 * V_38 = F_23 ( V_35 ) ;
struct V_1 * V_2 = F_16 ( V_33 ) ;
int V_42 ;
V_42 = F_5 ( V_2 , V_38 -> V_21 ) ;
if ( V_42 < 0 )
return V_42 ;
return sprintf ( V_36 , L_1 , V_42 ) ;
}
static T_2 F_24 ( struct V_32 * V_33 , struct V_34 * V_35 ,
char * V_36 )
{
struct V_37 * V_38 = F_15 ( V_35 ) ;
struct V_1 * V_2 = F_16 ( V_33 ) ;
int V_42 ;
V_42 = F_7 ( V_2 , V_38 -> V_20 , V_38 -> V_21 ) ;
if ( V_42 < 0 )
return V_42 ;
return sprintf ( V_36 , L_1 , V_42 ) ;
}
static T_2 F_25 ( struct V_32 * V_33 , struct V_34 * V_35 ,
const char * V_36 , T_3 V_39 )
{
struct V_37 * V_38 = F_15 ( V_35 ) ;
struct V_1 * V_2 = F_16 ( V_33 ) ;
unsigned long V_40 ;
int V_8 ;
V_8 = F_18 ( V_36 , 10 , & V_40 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_8 ( V_2 , V_38 -> V_20 , V_38 -> V_21 , V_40 ) ;
return V_8 ? : V_39 ;
}
static T_2 F_26 ( struct V_32 * V_33 , struct V_34 * V_35 ,
char * V_36 )
{
struct V_1 * V_2 = F_16 ( V_33 ) ;
struct V_37 * V_38 = F_15 ( V_35 ) ;
int V_43 = V_38 -> V_21 ;
unsigned int V_40 ;
int V_15 ;
V_15 = F_3 ( V_2 -> V_10 , V_38 -> V_20 , & V_40 ) ;
if ( V_15 < 0 )
return V_15 ;
return sprintf ( V_36 , L_2 , ! ! ( V_40 & ( 1 << V_43 ) ) ) ;
}
static T_2
F_27 ( struct V_32 * V_33 , struct V_34 * V_35 , char * V_36 )
{
struct V_37 * V_38 = F_15 ( V_35 ) ;
struct V_1 * V_2 = F_16 ( V_33 ) ;
unsigned int V_44 ;
int V_8 ;
V_8 = F_3 ( V_2 -> V_10 , V_38 -> V_20 , & V_44 ) ;
if ( V_8 )
return V_8 ;
return sprintf ( V_36 , L_2 , ! ! ( V_44 & ( 1 << V_38 -> V_21 ) ) ) ;
}
static T_2
F_28 ( struct V_32 * V_33 , struct V_34 * V_35 , const char * V_36 ,
T_3 V_39 )
{
struct V_37 * V_38 = F_15 ( V_35 ) ;
struct V_1 * V_2 = F_16 ( V_33 ) ;
unsigned long V_40 ;
int V_8 ;
V_8 = F_18 ( V_36 , 10 , & V_40 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_40 > 1 )
return - V_45 ;
V_8 = F_13 ( V_2 -> V_10 , V_38 -> V_20 , 1 << V_38 -> V_21 ,
V_40 ? 1 << V_38 -> V_21 : 0 ) ;
return V_8 ? : V_39 ;
}
static T_4 F_29 ( struct V_46 * V_47 ,
struct V_48 * V_35 , int V_21 )
{
struct V_32 * V_33 = F_30 ( V_47 , struct V_32 , V_47 ) ;
struct V_1 * V_2 = F_16 ( V_33 ) ;
unsigned int V_49 ;
int V_8 ;
V_8 = F_3 ( V_2 -> V_10 , V_50 , & V_49 ) ;
if ( V_8 < 0 )
return 0 ;
if ( V_21 < 9 &&
( V_49 & 03 ) != 0x01 && ( V_49 & 0x03 ) != 0x02 )
return 0 ;
if ( V_21 >= 9 && V_21 < 18 &&
( V_49 & 0x0c ) != 0x04 && ( V_49 & 0x0c ) != 0x08 )
return 0 ;
if ( V_21 >= 18 && V_21 < 27 && ( V_49 & 0x30 ) != 0x10 )
return 0 ;
if ( V_21 >= 27 && V_21 < 35 )
return V_35 -> V_51 ;
V_8 = F_3 ( V_2 -> V_10 , V_52 , & V_49 ) ;
if ( V_8 < 0 )
return 0 ;
if ( V_21 >= 35 && V_21 < 43 && ! ( V_49 & 0x01 ) )
return 0 ;
if ( V_21 >= 0x43 && ( ! ( V_49 & 0x02 ) ) )
return 0 ;
return V_35 -> V_51 ;
}
static T_4 F_31 ( struct V_46 * V_47 ,
struct V_48 * V_35 , int V_21 )
{
struct V_32 * V_33 = F_30 ( V_47 , struct V_32 , V_47 ) ;
struct V_1 * V_2 = F_16 ( V_33 ) ;
unsigned int V_49 ;
int V_8 ;
if ( V_21 < 6 )
return V_35 -> V_51 ;
V_8 = F_3 ( V_2 -> V_10 , V_50 , & V_49 ) ;
if ( V_8 < 0 )
return 0 ;
if ( V_21 >= 6 && V_21 < 11 && ( V_49 & 0x03 ) != 0x03 )
return 0 ;
if ( V_21 >= 11 && V_21 < 17 && ( V_49 & 0x0c ) != 0x0c )
return 0 ;
if ( V_21 >= 17 && ( V_49 & 0x30 ) != 0x30 )
return 0 ;
return V_35 -> V_51 ;
}
static T_4 F_32 ( struct V_46 * V_47 ,
struct V_48 * V_35 , int V_21 )
{
struct V_32 * V_33 = F_30 ( V_47 , struct V_32 , V_47 ) ;
struct V_1 * V_2 = F_16 ( V_33 ) ;
int V_53 = V_21 / 4 ;
unsigned int V_49 ;
int V_8 ;
V_8 = F_3 ( V_2 -> V_10 , V_54 , & V_49 ) ;
if ( V_8 < 0 || ! ( V_49 & ( 1 << V_53 ) ) )
return 0 ;
return V_35 -> V_51 ;
}
static int F_33 ( struct V_55 * V_56 ,
struct V_57 * V_58 )
{
int V_49 ;
V_49 = F_34 ( V_56 , V_59 ) ;
if ( V_49 != 0x00 )
return - V_60 ;
V_49 = F_34 ( V_56 , V_61 ) ;
if ( V_49 != 0x50 )
return - V_60 ;
V_49 = F_34 ( V_56 , V_62 ) ;
if ( V_49 != 0xc3 )
return - V_60 ;
V_49 = F_34 ( V_56 , V_63 ) ;
if ( V_49 < 0 || ( V_49 & 0xf0 ) != 0x20 )
return - V_60 ;
V_49 = F_34 ( V_56 , V_64 ) ;
if ( V_49 < 0 || ( V_49 & 0x1f ) )
return - V_60 ;
V_49 = F_34 ( V_56 , V_65 ) ;
if ( V_49 < 0 || ( V_49 & 0x3f ) )
return - V_60 ;
V_49 = F_34 ( V_56 , V_25 ) ;
if ( V_49 < 0 || ( V_49 & 0x3f ) )
return - V_60 ;
F_35 ( V_58 -> type , L_3 , V_66 ) ;
return 0 ;
}
static bool F_36 ( struct V_32 * V_33 , unsigned int V_49 )
{
return V_49 != V_59 && V_49 <= 0x20 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_13 ( V_2 -> V_10 , V_67 , 0x01 , 0x01 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_13 ( V_2 -> V_10 , V_50 , 0x40 , 0x40 ) ;
if ( V_8 )
return V_8 ;
return F_13 ( V_2 -> V_10 , V_68 , 0x03 , 0x03 ) ;
}
static int F_38 ( struct V_55 * V_56 ,
const struct V_69 * V_70 )
{
struct V_32 * V_33 = & V_56 -> V_33 ;
struct V_1 * V_2 ;
struct V_32 * V_71 ;
int V_15 ;
V_2 = F_39 ( V_33 , sizeof( * V_2 ) , V_72 ) ;
if ( V_2 == NULL )
return - V_73 ;
V_2 -> V_10 = F_40 ( V_56 , & V_74 ) ;
if ( F_41 ( V_2 -> V_10 ) )
return F_42 ( V_2 -> V_10 ) ;
F_43 ( & V_2 -> V_9 ) ;
V_15 = F_37 ( V_2 ) ;
if ( V_15 < 0 )
return V_15 ;
V_71 = F_44 ( V_33 , V_56 -> V_75 ,
V_2 ,
V_76 ) ;
return F_45 ( V_71 ) ;
}

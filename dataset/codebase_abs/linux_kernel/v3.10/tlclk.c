static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
int V_4 ;
F_2 ( & V_5 ) ;
if ( F_3 ( 0 , & V_6 ) ) {
V_4 = - V_7 ;
goto V_8;
}
F_4 ( V_9 ) ;
V_4 = F_5 ( V_10 , & V_11 ,
V_12 , L_1 , V_11 ) ;
if ( V_4 == - V_7 )
F_6 ( V_13 L_2 ) ;
else
F_4 ( V_9 ) ;
V_8:
F_7 ( & V_5 ) ;
return V_4 ;
}
static int F_8 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
F_9 ( V_10 , V_11 ) ;
F_10 ( 0 , & V_6 ) ;
return 0 ;
}
static T_1 F_11 ( struct V_2 * V_3 , char T_2 * V_14 , T_3 V_15 ,
T_4 * V_16 )
{
if ( V_15 < sizeof( struct V_17 ) )
return - V_18 ;
if ( F_12 ( & V_5 ) )
return - V_19 ;
F_13 ( V_20 , V_21 ) ;
if ( F_14 ( V_14 , V_22 , sizeof( struct V_17 ) ) ) {
F_7 ( & V_5 ) ;
return - V_23 ;
}
memset ( V_22 , 0 , sizeof( struct V_17 ) ) ;
V_21 = 0 ;
F_7 ( & V_5 ) ;
return sizeof( struct V_17 ) ;
}
static T_1 F_15 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_14 )
{
unsigned long V_28 ;
unsigned long V_29 ;
F_16 ( & V_30 , V_29 ) ;
V_28 = ( ( F_4 ( V_31 ) & 0x08 ) >> 3 ) ;
F_17 ( & V_30 , V_29 ) ;
return sprintf ( V_14 , L_3 , V_28 ) ;
}
static T_1 F_18 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_14 )
{
unsigned long V_28 ;
unsigned long V_29 ;
F_16 ( & V_30 , V_29 ) ;
V_28 = F_4 ( V_32 ) ;
F_17 ( & V_30 , V_29 ) ;
return sprintf ( V_14 , L_3 , V_28 ) ;
}
static T_1 F_19 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_14 )
{
unsigned long V_28 ;
unsigned long V_29 ;
F_16 ( & V_30 , V_29 ) ;
V_28 = ( F_4 ( V_33 ) & 0xf0 ) ;
F_17 ( & V_30 , V_29 ) ;
return sprintf ( V_14 , L_3 , V_28 ) ;
}
static T_1 F_20 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_14 , T_3 V_15 )
{
unsigned long V_34 ;
unsigned char V_35 ;
unsigned long V_29 ;
sscanf ( V_14 , L_4 , & V_34 ) ;
F_21 ( V_25 , L_5 , V_34 ) ;
V_35 = ( unsigned char ) V_34 ;
F_16 ( & V_30 , V_29 ) ;
F_22 ( V_31 , 0xef , V_35 ) ;
F_17 ( & V_30 , V_29 ) ;
return F_23 ( V_14 , V_15 ) ;
}
static T_1 F_24 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_14 , T_3 V_15 )
{
unsigned long V_34 ;
unsigned char V_35 ;
unsigned long V_29 ;
sscanf ( V_14 , L_4 , & V_34 ) ;
F_21 ( V_25 , L_5 , V_34 ) ;
V_35 = ( unsigned char ) V_34 ;
F_16 ( & V_30 , V_29 ) ;
F_22 ( V_31 , 0xdf , V_35 << 1 ) ;
F_17 ( & V_30 , V_29 ) ;
return F_23 ( V_14 , V_15 ) ;
}
static T_1 F_25 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_14 , T_3 V_15 )
{
unsigned long V_34 ;
unsigned char V_35 ;
unsigned long V_29 ;
sscanf ( V_14 , L_4 , & V_34 ) ;
F_21 ( V_25 , L_5 , V_34 ) ;
V_35 = ( unsigned char ) V_34 ;
F_16 ( & V_30 , V_29 ) ;
F_22 ( V_36 , 0x7f , V_35 << 7 ) ;
F_17 ( & V_30 , V_29 ) ;
return F_23 ( V_14 , V_15 ) ;
}
static T_1 F_26 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_14 , T_3 V_15 )
{
unsigned long V_29 ;
unsigned long V_34 ;
unsigned char V_35 ;
sscanf ( V_14 , L_4 , & V_34 ) ;
F_21 ( V_25 , L_6 , V_34 ) ;
V_35 = ( unsigned char ) V_34 ;
F_16 ( & V_30 , V_29 ) ;
F_22 ( V_36 , 0xbf , V_35 << 6 ) ;
F_17 ( & V_30 , V_29 ) ;
return F_23 ( V_14 , V_15 ) ;
}
static T_1 F_27 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_14 , T_3 V_15 )
{
unsigned long V_29 ;
unsigned long V_34 ;
unsigned char V_35 ;
sscanf ( V_14 , L_4 , & V_34 ) ;
F_21 ( V_25 , L_6 , V_34 ) ;
V_35 = ( unsigned char ) V_34 ;
F_16 ( & V_30 , V_29 ) ;
F_22 ( V_33 , 0xf7 , V_35 << 3 ) ;
F_17 ( & V_30 , V_29 ) ;
return F_23 ( V_14 , V_15 ) ;
}
static T_1 F_28 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_14 , T_3 V_15 )
{
unsigned long V_29 ;
unsigned long V_34 ;
unsigned char V_35 ;
sscanf ( V_14 , L_4 , & V_34 ) ;
F_21 ( V_25 , L_6 , V_34 ) ;
V_35 = ( unsigned char ) V_34 ;
F_16 ( & V_30 , V_29 ) ;
F_22 ( V_33 , 0xfb , V_35 << 2 ) ;
F_17 ( & V_30 , V_29 ) ;
return F_23 ( V_14 , V_15 ) ;
}
static T_1 F_29 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_14 , T_3 V_15 )
{
unsigned long V_29 ;
unsigned long V_34 ;
unsigned char V_35 ;
sscanf ( V_14 , L_4 , & V_34 ) ;
F_21 ( V_25 , L_6 , V_34 ) ;
V_35 = ( unsigned char ) V_34 ;
F_16 ( & V_30 , V_29 ) ;
F_22 ( V_33 , 0xfd , V_35 << 1 ) ;
F_17 ( & V_30 , V_29 ) ;
return F_23 ( V_14 , V_15 ) ;
}
static T_1 F_30 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_14 , T_3 V_15 )
{
unsigned long V_29 ;
unsigned long V_34 ;
unsigned char V_35 ;
sscanf ( V_14 , L_4 , & V_34 ) ;
F_21 ( V_25 , L_6 , V_34 ) ;
V_35 = ( unsigned char ) V_34 ;
F_16 ( & V_30 , V_29 ) ;
F_22 ( V_33 , 0xfe , V_35 ) ;
F_17 ( & V_30 , V_29 ) ;
return F_23 ( V_14 , V_15 ) ;
}
static T_1 F_31 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_14 , T_3 V_15 )
{
unsigned long V_29 ;
unsigned long V_34 ;
unsigned char V_35 ;
sscanf ( V_14 , L_4 , & V_34 ) ;
F_21 ( V_25 , L_6 , V_34 ) ;
V_35 = ( unsigned char ) V_34 ;
F_16 ( & V_30 , V_29 ) ;
if ( ( V_35 == V_37 ) || ( V_35 == V_38 ) ) {
F_22 ( V_36 , 0xc7 , 0x28 ) ;
F_22 ( V_31 , 0xfb , ~ V_35 ) ;
} else if ( V_35 >= V_39 ) {
F_22 ( V_36 , 0xc7 , 0x38 ) ;
switch ( V_35 ) {
case V_39 :
F_22 ( V_40 , 0xfc , 2 ) ;
break;
case V_41 :
F_22 ( V_40 , 0xfc , 0 ) ;
break;
case V_42 :
F_22 ( V_40 , 0xfc , 3 ) ;
break;
case V_43 :
F_22 ( V_40 , 0xfc , 1 ) ;
break;
}
} else
F_22 ( V_36 , 0xc7 , V_35 << 3 ) ;
F_17 ( & V_30 , V_29 ) ;
return F_23 ( V_14 , V_15 ) ;
}
static T_1 F_32 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_14 , T_3 V_15 )
{
unsigned long V_34 ;
unsigned char V_35 ;
unsigned long V_29 ;
sscanf ( V_14 , L_4 , & V_34 ) ;
F_21 ( V_25 , L_6 , V_34 ) ;
V_35 = ( unsigned char ) V_34 ;
F_16 ( & V_30 , V_29 ) ;
if ( ( V_35 == V_37 ) || ( V_35 == V_38 ) ) {
F_22 ( V_36 , 0xf8 , 0x5 ) ;
F_22 ( V_31 , 0xfb , ~ V_35 ) ;
} else if ( V_35 >= V_39 ) {
F_22 ( V_36 , 0xf8 , 0x7 ) ;
switch ( V_35 ) {
case V_39 :
F_22 ( V_40 , 0xfc , 2 ) ;
break;
case V_41 :
F_22 ( V_40 , 0xfc , 0 ) ;
break;
case V_42 :
F_22 ( V_40 , 0xfc , 3 ) ;
break;
case V_43 :
F_22 ( V_40 , 0xfc , 1 ) ;
break;
}
} else
F_22 ( V_36 , 0xf8 , V_35 ) ;
F_17 ( & V_30 , V_29 ) ;
return F_23 ( V_14 , V_15 ) ;
}
static T_1 F_33 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_14 , T_3 V_15 )
{
unsigned long V_34 ;
unsigned char V_35 ;
unsigned long V_29 ;
sscanf ( V_14 , L_4 , & V_34 ) ;
F_21 ( V_25 , L_6 , V_34 ) ;
V_35 = ( unsigned char ) V_34 ;
F_16 ( & V_30 , V_29 ) ;
F_22 ( V_31 , 0xfe , V_35 ) ;
F_17 ( & V_30 , V_29 ) ;
return F_23 ( V_14 , V_15 ) ;
}
static T_1 F_34 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_14 , T_3 V_15 )
{
unsigned long V_34 ;
unsigned char V_35 ;
unsigned long V_29 ;
sscanf ( V_14 , L_4 , & V_34 ) ;
F_21 ( V_25 , L_6 , V_34 ) ;
V_35 = ( unsigned char ) V_34 ;
F_16 ( & V_30 , V_29 ) ;
F_22 ( V_31 , 0xfd , V_35 ) ;
F_17 ( & V_30 , V_29 ) ;
return F_23 ( V_14 , V_15 ) ;
}
static T_1 F_35 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_14 , T_3 V_15 )
{
unsigned long V_34 ;
unsigned char V_35 ;
unsigned long V_29 ;
sscanf ( V_14 , L_4 , & V_34 ) ;
F_21 ( V_25 , L_6 , V_34 ) ;
V_35 = ( unsigned char ) V_34 ;
F_16 ( & V_30 , V_29 ) ;
F_22 ( V_40 , 0xfb , V_35 ) ;
F_17 ( & V_30 , V_29 ) ;
return F_23 ( V_14 , V_15 ) ;
}
static T_1 F_36 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_14 , T_3 V_15 )
{
unsigned long V_34 ;
unsigned char V_35 ;
unsigned long V_29 ;
sscanf ( V_14 , L_4 , & V_34 ) ;
F_21 ( V_25 , L_6 , V_34 ) ;
V_35 = ( unsigned char ) V_34 ;
F_16 ( & V_30 , V_29 ) ;
F_22 ( V_40 , 0xbf , V_35 ) ;
F_17 ( & V_30 , V_29 ) ;
return F_23 ( V_14 , V_15 ) ;
}
static T_1 F_37 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_14 , T_3 V_15 )
{
unsigned long V_34 ;
unsigned char V_35 ;
unsigned long V_29 ;
sscanf ( V_14 , L_4 , & V_34 ) ;
F_21 ( V_25 , L_6 , V_34 ) ;
V_35 = ( unsigned char ) V_34 ;
F_16 ( & V_30 , V_29 ) ;
F_22 ( V_40 , 0x7f , V_35 ) ;
F_17 ( & V_30 , V_29 ) ;
return F_23 ( V_14 , V_15 ) ;
}
static T_1 F_38 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_14 , T_3 V_15 )
{
unsigned long V_34 ;
unsigned long V_29 ;
sscanf ( V_14 , L_4 , & V_34 ) ;
F_21 ( V_25 , L_6 , V_34 ) ;
F_16 ( & V_30 , V_29 ) ;
F_22 ( V_40 , 0xf7 , 0 ) ;
F_22 ( V_40 , 0xf7 , 0x08 ) ;
F_22 ( V_40 , 0xf7 , 0 ) ;
F_17 ( & V_30 , V_29 ) ;
return F_23 ( V_14 , V_15 ) ;
}
static T_1 F_39 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_14 , T_3 V_15 )
{
unsigned long V_34 ;
unsigned char V_35 ;
unsigned long V_29 ;
sscanf ( V_14 , L_4 , & V_34 ) ;
F_21 ( V_25 , L_6 , V_34 ) ;
V_35 = ( unsigned char ) V_34 ;
F_16 ( & V_30 , V_29 ) ;
F_22 ( V_40 , 0xcf , V_35 ) ;
F_17 ( & V_30 , V_29 ) ;
return F_23 ( V_14 , V_15 ) ;
}
static T_1 F_40 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_14 , T_3 V_15 )
{
unsigned long V_34 ;
unsigned char V_35 ;
unsigned long V_29 ;
sscanf ( V_14 , L_4 , & V_34 ) ;
F_21 ( V_25 , L_6 , V_34 ) ;
V_35 = ( unsigned char ) V_34 ;
F_16 ( & V_30 , V_29 ) ;
F_22 ( V_44 , 0xfd , V_35 ) ;
F_17 ( & V_30 , V_29 ) ;
return F_23 ( V_14 , V_15 ) ;
}
static int T_5 F_41 ( void )
{
int V_45 ;
V_45 = F_42 ( V_46 , L_1 , & V_47 ) ;
if ( V_45 < 0 ) {
F_6 ( V_13 L_7 , V_46 ) ;
return V_45 ;
}
V_46 = V_45 ;
V_22 = F_43 ( sizeof( struct V_17 ) , V_48 ) ;
if ( ! V_22 ) {
V_45 = - V_49 ;
goto V_50;
}
if ( ! F_44 ( V_51 , 8 , L_1 ) ) {
F_6 ( V_13 L_8 ,
V_51 ) ;
V_45 = - V_7 ;
goto V_52;
}
V_10 = ( F_4 ( V_53 ) & 0x0f ) ;
if ( 0x0F == V_10 ) {
F_6 ( V_13 L_9 ,
V_10 ) ;
V_45 = - V_54 ;
goto V_55;
}
F_45 ( & V_56 ) ;
V_45 = F_46 ( & V_57 ) ;
if ( V_45 < 0 ) {
F_6 ( V_13 L_10 , V_45 ) ;
goto V_55;
}
V_58 = F_47 ( L_1 ,
- 1 , NULL , 0 ) ;
if ( F_48 ( V_58 ) ) {
F_6 ( V_13 L_11 ) ;
V_45 = F_49 ( V_58 ) ;
goto V_59;
}
V_45 = F_50 ( & V_58 -> V_60 . V_61 ,
& V_62 ) ;
if ( V_45 ) {
F_6 ( V_13 L_12 ) ;
goto V_63;
}
return 0 ;
V_63:
F_51 ( V_58 ) ;
V_59:
F_52 ( & V_57 ) ;
V_55:
F_53 ( V_51 , 8 ) ;
V_52:
F_54 ( V_22 ) ;
V_50:
F_55 ( V_46 , L_1 ) ;
return V_45 ;
}
static void T_6 F_56 ( void )
{
F_57 ( & V_58 -> V_60 . V_61 , & V_62 ) ;
F_51 ( V_58 ) ;
F_52 ( & V_57 ) ;
F_55 ( V_46 , L_1 ) ;
F_53 ( V_51 , 8 ) ;
F_58 ( & V_56 ) ;
F_54 ( V_22 ) ;
}
static void F_59 ( unsigned long V_64 )
{
unsigned long V_29 = * ( unsigned long * ) V_64 ;
if ( ( V_29 & 1 ) ) {
if ( ( F_4 ( V_31 ) & 0x08 ) != ( V_29 & 0x08 ) )
V_22 -> V_65 ++ ;
} else {
if ( ( F_4 ( V_31 ) & 0x08 ) != ( V_29 & 0x08 ) )
V_22 -> V_66 ++ ;
}
F_60 ( & V_56 ) ;
V_21 = 1 ;
F_61 ( & V_20 ) ;
}
static T_7 V_11 ( int V_67 , void * V_68 )
{
unsigned long V_29 ;
F_16 ( & V_30 , V_29 ) ;
V_69 = F_4 ( V_9 ) ;
if ( V_69 & V_70 ) {
if ( F_4 ( V_33 ) & V_71 )
V_22 -> V_72 ++ ;
else
V_22 -> V_73 ++ ;
}
if ( V_69 & V_74 ) {
V_22 -> V_75 ++ ;
F_22 ( V_31 , 0xFE , 1 ) ;
}
if ( V_69 & V_76 ) {
if ( F_4 ( V_33 ) & V_77 )
V_22 -> V_72 ++ ;
else
V_22 -> V_78 ++ ;
}
if ( V_69 & V_79 ) {
V_22 -> V_80 ++ ;
F_22 ( V_31 , 0xFE , 0 ) ;
}
if ( V_69 & V_81 )
V_22 -> V_82 ++ ;
if ( V_69 & V_83 )
V_22 -> V_84 ++ ;
if ( V_69 & V_85 )
V_22 -> V_86 ++ ;
if ( V_69 & V_87 ) {
V_22 -> V_88 ++ ;
V_56 . V_89 = V_90 + F_62 ( 10 ) ;
V_91 = F_4 ( V_31 ) ;
V_56 . V_64 = ( unsigned long ) & V_91 ;
F_63 ( & V_56 , V_56 . V_89 ) ;
} else {
V_21 = 1 ;
F_61 ( & V_20 ) ;
}
F_17 ( & V_30 , V_29 ) ;
return V_92 ;
}

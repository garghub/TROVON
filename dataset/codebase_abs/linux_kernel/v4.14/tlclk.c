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
0 , L_1 , V_11 ) ;
if ( V_4 == - V_7 )
F_6 ( V_12 L_2 ) ;
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
static T_1 F_11 ( struct V_2 * V_3 , char T_2 * V_13 , T_3 V_14 ,
T_4 * V_15 )
{
if ( V_14 < sizeof( struct V_16 ) )
return - V_17 ;
if ( F_12 ( & V_5 ) )
return - V_18 ;
F_13 ( V_19 , V_20 ) ;
if ( F_14 ( V_13 , V_21 , sizeof( struct V_16 ) ) ) {
F_7 ( & V_5 ) ;
return - V_22 ;
}
memset ( V_21 , 0 , sizeof( struct V_16 ) ) ;
V_20 = 0 ;
F_7 ( & V_5 ) ;
return sizeof( struct V_16 ) ;
}
static T_1 F_15 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_13 )
{
unsigned long V_27 ;
unsigned long V_28 ;
F_16 ( & V_29 , V_28 ) ;
V_27 = ( ( F_4 ( V_30 ) & 0x08 ) >> 3 ) ;
F_17 ( & V_29 , V_28 ) ;
return sprintf ( V_13 , L_3 , V_27 ) ;
}
static T_1 F_18 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_13 )
{
unsigned long V_27 ;
unsigned long V_28 ;
F_16 ( & V_29 , V_28 ) ;
V_27 = F_4 ( V_31 ) ;
F_17 ( & V_29 , V_28 ) ;
return sprintf ( V_13 , L_3 , V_27 ) ;
}
static T_1 F_19 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_13 )
{
unsigned long V_27 ;
unsigned long V_28 ;
F_16 ( & V_29 , V_28 ) ;
V_27 = ( F_4 ( V_32 ) & 0xf0 ) ;
F_17 ( & V_29 , V_28 ) ;
return sprintf ( V_13 , L_3 , V_27 ) ;
}
static T_1 F_20 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_13 , T_3 V_14 )
{
unsigned long V_33 ;
unsigned char V_34 ;
unsigned long V_28 ;
sscanf ( V_13 , L_4 , & V_33 ) ;
F_21 ( V_24 , L_5 , V_33 ) ;
V_34 = ( unsigned char ) V_33 ;
F_16 ( & V_29 , V_28 ) ;
F_22 ( V_30 , 0xef , V_34 ) ;
F_17 ( & V_29 , V_28 ) ;
return F_23 ( V_13 , V_14 ) ;
}
static T_1 F_24 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_13 , T_3 V_14 )
{
unsigned long V_33 ;
unsigned char V_34 ;
unsigned long V_28 ;
sscanf ( V_13 , L_4 , & V_33 ) ;
F_21 ( V_24 , L_5 , V_33 ) ;
V_34 = ( unsigned char ) V_33 ;
F_16 ( & V_29 , V_28 ) ;
F_22 ( V_30 , 0xdf , V_34 << 1 ) ;
F_17 ( & V_29 , V_28 ) ;
return F_23 ( V_13 , V_14 ) ;
}
static T_1 F_25 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_13 , T_3 V_14 )
{
unsigned long V_33 ;
unsigned char V_34 ;
unsigned long V_28 ;
sscanf ( V_13 , L_4 , & V_33 ) ;
F_21 ( V_24 , L_5 , V_33 ) ;
V_34 = ( unsigned char ) V_33 ;
F_16 ( & V_29 , V_28 ) ;
F_22 ( V_35 , 0x7f , V_34 << 7 ) ;
F_17 ( & V_29 , V_28 ) ;
return F_23 ( V_13 , V_14 ) ;
}
static T_1 F_26 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_13 , T_3 V_14 )
{
unsigned long V_28 ;
unsigned long V_33 ;
unsigned char V_34 ;
sscanf ( V_13 , L_4 , & V_33 ) ;
F_21 ( V_24 , L_6 , V_33 ) ;
V_34 = ( unsigned char ) V_33 ;
F_16 ( & V_29 , V_28 ) ;
F_22 ( V_35 , 0xbf , V_34 << 6 ) ;
F_17 ( & V_29 , V_28 ) ;
return F_23 ( V_13 , V_14 ) ;
}
static T_1 F_27 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_13 , T_3 V_14 )
{
unsigned long V_28 ;
unsigned long V_33 ;
unsigned char V_34 ;
sscanf ( V_13 , L_4 , & V_33 ) ;
F_21 ( V_24 , L_6 , V_33 ) ;
V_34 = ( unsigned char ) V_33 ;
F_16 ( & V_29 , V_28 ) ;
F_22 ( V_32 , 0xf7 , V_34 << 3 ) ;
F_17 ( & V_29 , V_28 ) ;
return F_23 ( V_13 , V_14 ) ;
}
static T_1 F_28 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_13 , T_3 V_14 )
{
unsigned long V_28 ;
unsigned long V_33 ;
unsigned char V_34 ;
sscanf ( V_13 , L_4 , & V_33 ) ;
F_21 ( V_24 , L_6 , V_33 ) ;
V_34 = ( unsigned char ) V_33 ;
F_16 ( & V_29 , V_28 ) ;
F_22 ( V_32 , 0xfb , V_34 << 2 ) ;
F_17 ( & V_29 , V_28 ) ;
return F_23 ( V_13 , V_14 ) ;
}
static T_1 F_29 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_13 , T_3 V_14 )
{
unsigned long V_28 ;
unsigned long V_33 ;
unsigned char V_34 ;
sscanf ( V_13 , L_4 , & V_33 ) ;
F_21 ( V_24 , L_6 , V_33 ) ;
V_34 = ( unsigned char ) V_33 ;
F_16 ( & V_29 , V_28 ) ;
F_22 ( V_32 , 0xfd , V_34 << 1 ) ;
F_17 ( & V_29 , V_28 ) ;
return F_23 ( V_13 , V_14 ) ;
}
static T_1 F_30 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_13 , T_3 V_14 )
{
unsigned long V_28 ;
unsigned long V_33 ;
unsigned char V_34 ;
sscanf ( V_13 , L_4 , & V_33 ) ;
F_21 ( V_24 , L_6 , V_33 ) ;
V_34 = ( unsigned char ) V_33 ;
F_16 ( & V_29 , V_28 ) ;
F_22 ( V_32 , 0xfe , V_34 ) ;
F_17 ( & V_29 , V_28 ) ;
return F_23 ( V_13 , V_14 ) ;
}
static T_1 F_31 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_13 , T_3 V_14 )
{
unsigned long V_28 ;
unsigned long V_33 ;
unsigned char V_34 ;
sscanf ( V_13 , L_4 , & V_33 ) ;
F_21 ( V_24 , L_6 , V_33 ) ;
V_34 = ( unsigned char ) V_33 ;
F_16 ( & V_29 , V_28 ) ;
if ( ( V_34 == V_36 ) || ( V_34 == V_37 ) ) {
F_22 ( V_35 , 0xc7 , 0x28 ) ;
F_22 ( V_30 , 0xfb , ~ V_34 ) ;
} else if ( V_34 >= V_38 ) {
F_22 ( V_35 , 0xc7 , 0x38 ) ;
switch ( V_34 ) {
case V_38 :
F_22 ( V_39 , 0xfc , 2 ) ;
break;
case V_40 :
F_22 ( V_39 , 0xfc , 0 ) ;
break;
case V_41 :
F_22 ( V_39 , 0xfc , 3 ) ;
break;
case V_42 :
F_22 ( V_39 , 0xfc , 1 ) ;
break;
}
} else
F_22 ( V_35 , 0xc7 , V_34 << 3 ) ;
F_17 ( & V_29 , V_28 ) ;
return F_23 ( V_13 , V_14 ) ;
}
static T_1 F_32 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_13 , T_3 V_14 )
{
unsigned long V_33 ;
unsigned char V_34 ;
unsigned long V_28 ;
sscanf ( V_13 , L_4 , & V_33 ) ;
F_21 ( V_24 , L_6 , V_33 ) ;
V_34 = ( unsigned char ) V_33 ;
F_16 ( & V_29 , V_28 ) ;
if ( ( V_34 == V_36 ) || ( V_34 == V_37 ) ) {
F_22 ( V_35 , 0xf8 , 0x5 ) ;
F_22 ( V_30 , 0xfb , ~ V_34 ) ;
} else if ( V_34 >= V_38 ) {
F_22 ( V_35 , 0xf8 , 0x7 ) ;
switch ( V_34 ) {
case V_38 :
F_22 ( V_39 , 0xfc , 2 ) ;
break;
case V_40 :
F_22 ( V_39 , 0xfc , 0 ) ;
break;
case V_41 :
F_22 ( V_39 , 0xfc , 3 ) ;
break;
case V_42 :
F_22 ( V_39 , 0xfc , 1 ) ;
break;
}
} else
F_22 ( V_35 , 0xf8 , V_34 ) ;
F_17 ( & V_29 , V_28 ) ;
return F_23 ( V_13 , V_14 ) ;
}
static T_1 F_33 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_13 , T_3 V_14 )
{
unsigned long V_33 ;
unsigned char V_34 ;
unsigned long V_28 ;
sscanf ( V_13 , L_4 , & V_33 ) ;
F_21 ( V_24 , L_6 , V_33 ) ;
V_34 = ( unsigned char ) V_33 ;
F_16 ( & V_29 , V_28 ) ;
F_22 ( V_30 , 0xfe , V_34 ) ;
F_17 ( & V_29 , V_28 ) ;
return F_23 ( V_13 , V_14 ) ;
}
static T_1 F_34 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_13 , T_3 V_14 )
{
unsigned long V_33 ;
unsigned char V_34 ;
unsigned long V_28 ;
sscanf ( V_13 , L_4 , & V_33 ) ;
F_21 ( V_24 , L_6 , V_33 ) ;
V_34 = ( unsigned char ) V_33 ;
F_16 ( & V_29 , V_28 ) ;
F_22 ( V_30 , 0xfd , V_34 ) ;
F_17 ( & V_29 , V_28 ) ;
return F_23 ( V_13 , V_14 ) ;
}
static T_1 F_35 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_13 , T_3 V_14 )
{
unsigned long V_33 ;
unsigned char V_34 ;
unsigned long V_28 ;
sscanf ( V_13 , L_4 , & V_33 ) ;
F_21 ( V_24 , L_6 , V_33 ) ;
V_34 = ( unsigned char ) V_33 ;
F_16 ( & V_29 , V_28 ) ;
F_22 ( V_39 , 0xfb , V_34 ) ;
F_17 ( & V_29 , V_28 ) ;
return F_23 ( V_13 , V_14 ) ;
}
static T_1 F_36 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_13 , T_3 V_14 )
{
unsigned long V_33 ;
unsigned char V_34 ;
unsigned long V_28 ;
sscanf ( V_13 , L_4 , & V_33 ) ;
F_21 ( V_24 , L_6 , V_33 ) ;
V_34 = ( unsigned char ) V_33 ;
F_16 ( & V_29 , V_28 ) ;
F_22 ( V_39 , 0xbf , V_34 ) ;
F_17 ( & V_29 , V_28 ) ;
return F_23 ( V_13 , V_14 ) ;
}
static T_1 F_37 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_13 , T_3 V_14 )
{
unsigned long V_33 ;
unsigned char V_34 ;
unsigned long V_28 ;
sscanf ( V_13 , L_4 , & V_33 ) ;
F_21 ( V_24 , L_6 , V_33 ) ;
V_34 = ( unsigned char ) V_33 ;
F_16 ( & V_29 , V_28 ) ;
F_22 ( V_39 , 0x7f , V_34 ) ;
F_17 ( & V_29 , V_28 ) ;
return F_23 ( V_13 , V_14 ) ;
}
static T_1 F_38 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_13 , T_3 V_14 )
{
unsigned long V_33 ;
unsigned long V_28 ;
sscanf ( V_13 , L_4 , & V_33 ) ;
F_21 ( V_24 , L_6 , V_33 ) ;
F_16 ( & V_29 , V_28 ) ;
F_22 ( V_39 , 0xf7 , 0 ) ;
F_22 ( V_39 , 0xf7 , 0x08 ) ;
F_22 ( V_39 , 0xf7 , 0 ) ;
F_17 ( & V_29 , V_28 ) ;
return F_23 ( V_13 , V_14 ) ;
}
static T_1 F_39 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_13 , T_3 V_14 )
{
unsigned long V_33 ;
unsigned char V_34 ;
unsigned long V_28 ;
sscanf ( V_13 , L_4 , & V_33 ) ;
F_21 ( V_24 , L_6 , V_33 ) ;
V_34 = ( unsigned char ) V_33 ;
F_16 ( & V_29 , V_28 ) ;
F_22 ( V_39 , 0xcf , V_34 ) ;
F_17 ( & V_29 , V_28 ) ;
return F_23 ( V_13 , V_14 ) ;
}
static T_1 F_40 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_13 , T_3 V_14 )
{
unsigned long V_33 ;
unsigned char V_34 ;
unsigned long V_28 ;
sscanf ( V_13 , L_4 , & V_33 ) ;
F_21 ( V_24 , L_6 , V_33 ) ;
V_34 = ( unsigned char ) V_33 ;
F_16 ( & V_29 , V_28 ) ;
F_22 ( V_43 , 0xfd , V_34 ) ;
F_17 ( & V_29 , V_28 ) ;
return F_23 ( V_13 , V_14 ) ;
}
static int T_5 F_41 ( void )
{
int V_44 ;
V_44 = F_42 ( V_45 , L_1 , & V_46 ) ;
if ( V_44 < 0 ) {
F_6 ( V_12 L_7 , V_45 ) ;
return V_44 ;
}
V_45 = V_44 ;
V_21 = F_43 ( sizeof( struct V_16 ) , V_47 ) ;
if ( ! V_21 ) {
V_44 = - V_48 ;
goto V_49;
}
if ( ! F_44 ( V_50 , 8 , L_1 ) ) {
F_6 ( V_12 L_8 ,
V_50 ) ;
V_44 = - V_7 ;
goto V_51;
}
V_10 = ( F_4 ( V_52 ) & 0x0f ) ;
if ( 0x0F == V_10 ) {
F_6 ( V_12 L_9 ,
V_10 ) ;
V_44 = - V_53 ;
goto V_54;
}
F_45 ( & V_55 ) ;
V_44 = F_46 ( & V_56 ) ;
if ( V_44 < 0 ) {
F_6 ( V_12 L_10 , V_44 ) ;
goto V_54;
}
V_57 = F_47 ( L_1 ,
- 1 , NULL , 0 ) ;
if ( F_48 ( V_57 ) ) {
F_6 ( V_12 L_11 ) ;
V_44 = F_49 ( V_57 ) ;
goto V_58;
}
V_44 = F_50 ( & V_57 -> V_59 . V_60 ,
& V_61 ) ;
if ( V_44 ) {
F_6 ( V_12 L_12 ) ;
goto V_62;
}
return 0 ;
V_62:
F_51 ( V_57 ) ;
V_58:
F_52 ( & V_56 ) ;
V_54:
F_53 ( V_50 , 8 ) ;
V_51:
F_54 ( V_21 ) ;
V_49:
F_55 ( V_45 , L_1 ) ;
return V_44 ;
}
static void T_6 F_56 ( void )
{
F_57 ( & V_57 -> V_59 . V_60 , & V_61 ) ;
F_51 ( V_57 ) ;
F_52 ( & V_56 ) ;
F_55 ( V_45 , L_1 ) ;
F_53 ( V_50 , 8 ) ;
F_58 ( & V_55 ) ;
F_54 ( V_21 ) ;
}
static void F_59 ( unsigned long V_63 )
{
unsigned long V_28 = * ( unsigned long * ) V_63 ;
if ( ( V_28 & 1 ) ) {
if ( ( F_4 ( V_30 ) & 0x08 ) != ( V_28 & 0x08 ) )
V_21 -> V_64 ++ ;
} else {
if ( ( F_4 ( V_30 ) & 0x08 ) != ( V_28 & 0x08 ) )
V_21 -> V_65 ++ ;
}
F_60 ( & V_55 ) ;
V_20 = 1 ;
F_61 ( & V_19 ) ;
}
static T_7 V_11 ( int V_66 , void * V_67 )
{
unsigned long V_28 ;
F_16 ( & V_29 , V_28 ) ;
V_68 = F_4 ( V_9 ) ;
if ( V_68 & V_69 ) {
if ( F_4 ( V_32 ) & V_70 )
V_21 -> V_71 ++ ;
else
V_21 -> V_72 ++ ;
}
if ( V_68 & V_73 ) {
V_21 -> V_74 ++ ;
F_22 ( V_30 , 0xFE , 1 ) ;
}
if ( V_68 & V_75 ) {
if ( F_4 ( V_32 ) & V_76 )
V_21 -> V_71 ++ ;
else
V_21 -> V_77 ++ ;
}
if ( V_68 & V_78 ) {
V_21 -> V_79 ++ ;
F_22 ( V_30 , 0xFE , 0 ) ;
}
if ( V_68 & V_80 )
V_21 -> V_81 ++ ;
if ( V_68 & V_82 )
V_21 -> V_83 ++ ;
if ( V_68 & V_84 )
V_21 -> V_85 ++ ;
if ( V_68 & V_86 ) {
V_21 -> V_87 ++ ;
V_55 . V_88 = V_89 + F_62 ( 10 ) ;
V_90 = F_4 ( V_30 ) ;
V_55 . V_63 = ( unsigned long ) & V_90 ;
F_63 ( & V_55 , V_55 . V_88 ) ;
} else {
V_20 = 1 ;
F_61 ( & V_19 ) ;
}
F_17 ( & V_29 , V_28 ) ;
return V_91 ;
}

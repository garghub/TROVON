static void F_1 ( int V_1 , int V_2 )
{
V_1 <<= 6 ;
V_1 |= 0x30 ;
V_1 |= ( V_2 << 1 ) ;
F_2 ( V_1 , V_3 ) ;
}
static void F_3 ( int V_1 , int V_4 )
{
F_2 ( V_4 & 0xFF , V_5 + V_1 ) ;
F_2 ( V_4 >> 8 , V_5 + V_1 ) ;
}
static int F_4 ( void )
{
unsigned long V_6 ;
F_5 ( & V_7 , V_6 ) ;
F_6 ( V_8 ) ;
F_1 ( 0 , 3 ) ;
F_1 ( 1 , 2 ) ;
F_1 ( 2 , 0 ) ;
F_3 ( 0 , 8948 ) ;
F_3 ( 1 , V_9 ) ;
F_3 ( 2 , 65535 ) ;
F_2 ( 0 , V_8 ) ;
F_7 ( & V_7 , V_6 ) ;
return 0 ;
}
static int F_8 ( void )
{
unsigned long V_6 ;
F_5 ( & V_7 , V_6 ) ;
F_6 ( V_8 ) ;
F_3 ( 2 , 0 ) ;
F_7 ( & V_7 , V_6 ) ;
return 0 ;
}
static void F_9 ( void )
{
unsigned long V_6 ;
F_5 ( & V_7 , V_6 ) ;
F_6 ( V_8 ) ;
F_1 ( 1 , 2 ) ;
F_3 ( 1 , V_9 ) ;
F_2 ( 0 , V_8 ) ;
F_7 ( & V_7 , V_6 ) ;
}
static int F_10 ( int V_10 )
{
if ( V_10 < 1 || V_10 > 65535 )
return - V_11 ;
V_12 = V_10 ;
V_9 = V_10 * 100 ;
return 0 ;
}
static int F_11 ( void )
{
unsigned char V_13 ;
int V_14 = 0 ;
unsigned long V_6 ;
F_5 ( & V_7 , V_6 ) ;
V_13 = F_6 ( V_15 ) ;
F_7 ( & V_7 , V_6 ) ;
if ( V_13 & V_16 )
V_14 |= V_17 ;
if ( V_13 & V_18 )
V_14 |= V_19 ;
if ( type == 501 ) {
if ( ! ( V_13 & V_20 ) )
V_14 |= V_21 ;
if ( ! ( V_13 & V_22 ) )
V_14 |= V_23 ;
if ( ! ( V_13 & V_24 ) )
V_14 |= V_25 ;
if ( V_26 ) {
if ( ! ( V_13 & V_27 ) )
V_14 |= V_28 ;
}
}
return V_14 ;
}
static int F_12 ( void )
{
unsigned short V_29 ;
unsigned long V_6 ;
F_5 ( & V_7 , V_6 ) ;
V_29 = F_6 ( V_30 ) ;
F_7 ( & V_7 , V_6 ) ;
return ( V_29 * 11 / 15 ) + 7 ;
}
static void F_13 ( int V_14 )
{
if ( ! ( V_14 & V_20 ) )
F_14 ( V_31 L_1 , F_6 ( V_30 ) ) ;
if ( ! ( V_14 & V_22 ) )
F_14 ( V_31 L_2 ) ;
if ( ! ( V_14 & V_24 ) )
F_14 ( V_31 L_3 ) ;
}
static T_1 F_15 ( int V_32 , void * V_33 )
{
unsigned char V_14 ;
F_16 ( & V_7 ) ;
V_14 = F_6 ( V_15 ) ;
F_14 ( V_31 L_4 , V_14 ) ;
if ( type == 501 ) {
F_13 ( V_14 ) ;
if ( V_26 ) {
if ( ! ( V_14 & V_27 ) )
F_14 ( V_31 L_5 ) ;
}
}
if ( ! ( V_14 & V_34 ) ) {
#ifdef F_17
#ifdef F_18
F_14 ( V_31 L_6 ) ;
#else
F_14 ( V_31 L_7 ) ;
F_19 () ;
#endif
#else
F_14 ( V_31 L_8 ) ;
#endif
}
F_20 ( & V_7 ) ;
return V_35 ;
}
static T_2 F_21 ( struct V_36 * V_36 , const char T_3 * V_37 ,
T_4 V_38 , T_5 * V_39 )
{
if ( V_38 ) {
if ( ! V_40 ) {
T_4 V_41 ;
V_42 = 0 ;
for ( V_41 = 0 ; V_41 != V_38 ; V_41 ++ ) {
char V_29 ;
if ( F_22 ( V_29 , V_37 + V_41 ) )
return - V_43 ;
if ( V_29 == 'V' )
V_42 = 42 ;
}
}
F_9 () ;
}
return V_38 ;
}
static long F_23 ( struct V_36 * V_36 , unsigned int V_44 , unsigned long V_45 )
{
void T_3 * V_46 = ( void T_3 * ) V_45 ;
int T_3 * V_47 = V_46 ;
int V_48 ;
int V_14 ;
struct V_49 V_50 = {
. V_51 = V_52 |
V_53 |
V_54 ,
. V_55 = 1 ,
. V_56 = L_9 ,
} ;
V_50 . V_51 |= ( V_17 | V_19 ) ;
if ( type == 501 ) {
V_50 . V_51 |= ( V_21 | V_25 |
V_23 ) ;
if ( V_26 )
V_50 . V_51 |= V_28 ;
}
switch ( V_44 ) {
case V_57 :
return F_24 ( V_46 , & V_50 , sizeof( V_50 ) ) ? - V_43 : 0 ;
case V_58 :
V_14 = F_11 () ;
return F_25 ( V_14 , V_47 ) ;
case V_59 :
return F_25 ( 0 , V_47 ) ;
case V_60 :
F_9 () ;
return 0 ;
case V_61 :
if ( F_22 ( V_48 , V_47 ) )
return - V_43 ;
if ( F_10 ( V_48 ) )
return - V_11 ;
F_9 () ;
case V_62 :
return F_25 ( V_12 , V_47 ) ;
default:
return - V_63 ;
}
}
static int F_26 ( struct V_64 * V_64 , struct V_36 * V_36 )
{
if ( F_27 ( 0 , & V_65 ) )
return - V_66 ;
F_4 () ;
return F_28 ( V_64 , V_36 ) ;
}
static int F_29 ( struct V_64 * V_64 , struct V_36 * V_36 )
{
if ( V_42 == 42 ) {
F_8 () ;
F_30 ( 0 , & V_65 ) ;
} else {
F_14 ( V_31
L_10 ) ;
F_9 () ;
}
V_42 = 0 ;
return 0 ;
}
static T_2 F_31 ( struct V_36 * V_36 , char T_3 * V_37 ,
T_4 V_38 , T_5 * V_67 )
{
int V_68 = F_12 () ;
if ( F_24 ( V_37 , & V_68 , 1 ) )
return - V_43 ;
return 1 ;
}
static int F_32 ( struct V_64 * V_64 , struct V_36 * V_36 )
{
return F_28 ( V_64 , V_36 ) ;
}
static int F_33 ( struct V_64 * V_64 , struct V_36 * V_36 )
{
return 0 ;
}
static int F_34 ( struct V_69 * V_70 , unsigned long V_71 ,
void * V_72 )
{
if ( V_71 == V_73 || V_71 == V_74 )
F_8 () ;
return V_75 ;
}
static void T_6 F_35 ( void )
{
F_36 ( & V_76 ) ;
if ( type == 501 )
F_36 ( & V_77 ) ;
F_37 ( & V_78 ) ;
F_38 ( V_32 , NULL ) ;
F_39 ( V_79 , 8 ) ;
}
static int T_7 F_40 ( void )
{
int V_80 ;
if ( type != 500 && type != 501 ) {
F_14 ( V_81 L_11 , type ) ;
return - V_82 ;
}
if ( F_10 ( V_12 ) ) {
F_10 ( V_83 ) ;
F_14 ( V_84 L_12
L_13 , V_83 ) ;
}
if ( ! F_41 ( V_79 , 8 , L_14 ) ) {
F_14 ( V_81
L_15 , V_79 ) ;
V_80 = - V_66 ;
goto V_85;
}
V_80 = F_42 ( V_32 , F_15 , 0 , L_14 , NULL ) ;
if ( V_80 ) {
F_14 ( V_81 L_16 , V_32 ) ;
goto V_86;
}
V_80 = F_43 ( & V_78 ) ;
if ( V_80 ) {
F_14 ( V_81
L_17 , V_80 ) ;
goto V_87;
}
if ( type == 501 ) {
V_80 = F_44 ( & V_77 ) ;
if ( V_80 ) {
F_14 ( V_81 L_18
L_19 , V_88 , V_80 ) ;
goto V_89;
}
}
V_80 = F_44 ( & V_76 ) ;
if ( V_80 ) {
F_14 ( V_81
L_20 ,
V_90 , V_80 ) ;
goto V_91;
}
F_14 ( V_84 L_21
L_22 ,
V_79 , V_32 , V_12 , V_40 ) ;
if ( type == 501 )
F_14 ( V_84 L_23 ,
( V_26 ? L_24 : L_25 ) ) ;
return 0 ;
V_91:
if ( type == 501 )
F_36 ( & V_77 ) ;
V_89:
F_37 ( & V_78 ) ;
V_87:
F_38 ( V_32 , NULL ) ;
V_86:
F_39 ( V_79 , 8 ) ;
V_85:
return V_80 ;
}

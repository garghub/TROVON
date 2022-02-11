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
F_14 ( L_1 , F_6 ( V_30 ) ) ;
if ( ! ( V_14 & V_22 ) )
F_14 ( L_2 ) ;
if ( ! ( V_14 & V_24 ) )
F_14 ( L_3 ) ;
}
static T_1 F_15 ( int V_31 , void * V_32 )
{
unsigned char V_14 ;
F_16 ( & V_7 ) ;
V_14 = F_6 ( V_15 ) ;
F_14 ( L_4 , V_14 ) ;
if ( type == 501 ) {
F_13 ( V_14 ) ;
if ( V_26 ) {
if ( ! ( V_14 & V_27 ) )
F_14 ( L_5 ) ;
}
}
if ( ! ( V_14 & V_33 ) ) {
#ifdef F_17
#ifdef F_18
F_14 ( L_6 ) ;
#else
F_14 ( L_7 ) ;
F_19 () ;
#endif
#else
F_14 ( L_8 ) ;
#endif
}
F_20 ( & V_7 ) ;
return V_34 ;
}
static T_2 F_21 ( struct V_35 * V_35 , const char T_3 * V_36 ,
T_4 V_37 , T_5 * V_38 )
{
if ( V_37 ) {
if ( ! V_39 ) {
T_4 V_40 ;
V_41 = 0 ;
for ( V_40 = 0 ; V_40 != V_37 ; V_40 ++ ) {
char V_29 ;
if ( F_22 ( V_29 , V_36 + V_40 ) )
return - V_42 ;
if ( V_29 == 'V' )
V_41 = 42 ;
}
}
F_9 () ;
}
return V_37 ;
}
static long F_23 ( struct V_35 * V_35 , unsigned int V_43 , unsigned long V_44 )
{
void T_3 * V_45 = ( void T_3 * ) V_44 ;
int T_3 * V_46 = V_45 ;
int V_47 ;
int V_14 ;
struct V_48 V_49 = {
. V_50 = V_51 |
V_52 |
V_53 ,
. V_54 = 1 ,
. V_55 = L_9 ,
} ;
V_49 . V_50 |= ( V_17 | V_19 ) ;
if ( type == 501 ) {
V_49 . V_50 |= ( V_21 | V_25 |
V_23 ) ;
if ( V_26 )
V_49 . V_50 |= V_28 ;
}
switch ( V_43 ) {
case V_56 :
return F_24 ( V_45 , & V_49 , sizeof( V_49 ) ) ? - V_42 : 0 ;
case V_57 :
V_14 = F_11 () ;
return F_25 ( V_14 , V_46 ) ;
case V_58 :
return F_25 ( 0 , V_46 ) ;
case V_59 :
F_9 () ;
return 0 ;
case V_60 :
if ( F_22 ( V_47 , V_46 ) )
return - V_42 ;
if ( F_10 ( V_47 ) )
return - V_11 ;
F_9 () ;
case V_61 :
return F_25 ( V_12 , V_46 ) ;
default:
return - V_62 ;
}
}
static int F_26 ( struct V_63 * V_63 , struct V_35 * V_35 )
{
if ( F_27 ( 0 , & V_64 ) )
return - V_65 ;
F_4 () ;
return F_28 ( V_63 , V_35 ) ;
}
static int F_29 ( struct V_63 * V_63 , struct V_35 * V_35 )
{
if ( V_41 == 42 ) {
F_8 () ;
F_30 ( 0 , & V_64 ) ;
} else {
F_14 ( L_10 ) ;
F_9 () ;
}
V_41 = 0 ;
return 0 ;
}
static T_2 F_31 ( struct V_35 * V_35 , char T_3 * V_36 ,
T_4 V_37 , T_5 * V_66 )
{
int V_67 = F_12 () ;
if ( F_24 ( V_36 , & V_67 , 1 ) )
return - V_42 ;
return 1 ;
}
static int F_32 ( struct V_63 * V_63 , struct V_35 * V_35 )
{
return F_28 ( V_63 , V_35 ) ;
}
static int F_33 ( struct V_63 * V_63 , struct V_35 * V_35 )
{
return 0 ;
}
static int F_34 ( struct V_68 * V_69 , unsigned long V_70 ,
void * V_71 )
{
if ( V_70 == V_72 || V_70 == V_73 )
F_8 () ;
return V_74 ;
}
static void T_6 F_35 ( void )
{
F_36 ( & V_75 ) ;
if ( type == 501 )
F_36 ( & V_76 ) ;
F_37 ( & V_77 ) ;
F_38 ( V_31 , NULL ) ;
F_39 ( V_78 , 8 ) ;
}
static int T_7 F_40 ( void )
{
int V_79 ;
if ( type != 500 && type != 501 ) {
F_41 ( L_11 , type ) ;
return - V_80 ;
}
if ( F_10 ( V_12 ) ) {
F_10 ( V_81 ) ;
F_42 ( L_12 ,
V_81 ) ;
}
if ( ! F_43 ( V_78 , 8 , L_13 ) ) {
F_41 ( L_14 , V_78 ) ;
V_79 = - V_65 ;
goto V_82;
}
V_79 = F_44 ( V_31 , F_15 , 0 , L_13 , NULL ) ;
if ( V_79 ) {
F_41 ( L_15 , V_31 ) ;
goto V_83;
}
V_79 = F_45 ( & V_77 ) ;
if ( V_79 ) {
F_41 ( L_16 , V_79 ) ;
goto V_84;
}
if ( type == 501 ) {
V_79 = F_46 ( & V_76 ) ;
if ( V_79 ) {
F_41 ( L_17 ,
V_85 , V_79 ) ;
goto V_86;
}
}
V_79 = F_46 ( & V_75 ) ;
if ( V_79 ) {
F_41 ( L_17 ,
V_87 , V_79 ) ;
goto V_88;
}
F_42 ( L_18 ,
V_78 , V_31 , V_12 , V_39 ) ;
if ( type == 501 )
F_42 ( L_19 ,
V_26 ? L_20 : L_21 ) ;
return 0 ;
V_88:
if ( type == 501 )
F_36 ( & V_76 ) ;
V_86:
F_37 ( & V_77 ) ;
V_84:
F_38 ( V_31 , NULL ) ;
V_83:
F_39 ( V_78 , 8 ) ;
V_82:
return V_79 ;
}

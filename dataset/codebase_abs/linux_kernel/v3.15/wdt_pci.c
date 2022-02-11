static void F_1 ( int V_1 , int V_2 )
{
V_1 <<= 6 ;
V_1 |= 0x30 ;
V_1 |= ( V_2 << 1 ) ;
F_2 ( V_1 , V_3 ) ;
F_3 ( 8 ) ;
}
static void F_4 ( int V_1 , int V_4 )
{
F_2 ( V_4 & 0xFF , V_5 + V_1 ) ;
F_3 ( 8 ) ;
F_2 ( V_4 >> 8 , V_5 + V_1 ) ;
F_3 ( 8 ) ;
}
static int F_5 ( void )
{
unsigned long V_6 ;
F_6 ( & V_7 , V_6 ) ;
F_7 ( V_8 ) ;
F_3 ( 8 ) ;
F_1 ( 2 , 0 ) ;
F_2 ( 0 , V_8 ) ;
F_3 ( 8 ) ;
F_7 ( V_8 ) ;
F_3 ( 8 ) ;
F_2 ( 0 , V_9 ) ;
F_3 ( 8 ) ;
F_7 ( V_10 ) ;
F_3 ( 8 ) ;
F_7 ( V_11 ) ;
F_3 ( 8 ) ;
F_7 ( V_12 ) ;
F_3 ( 8 ) ;
F_7 ( V_13 ) ;
F_3 ( 8 ) ;
F_1 ( 0 , 3 ) ;
F_1 ( 1 , 2 ) ;
F_1 ( 2 , 1 ) ;
F_4 ( 0 , 20833 ) ;
F_4 ( 1 , V_14 ) ;
F_2 ( 0 , V_8 ) ;
F_3 ( 8 ) ;
F_8 ( & V_7 , V_6 ) ;
return 0 ;
}
static int F_9 ( void )
{
unsigned long V_6 ;
F_6 ( & V_7 , V_6 ) ;
F_7 ( V_8 ) ;
F_3 ( 8 ) ;
F_4 ( 2 , 0 ) ;
F_8 ( & V_7 , V_6 ) ;
return 0 ;
}
static int F_10 ( void )
{
unsigned long V_6 ;
F_6 ( & V_7 , V_6 ) ;
F_7 ( V_8 ) ;
F_3 ( 8 ) ;
F_1 ( 1 , 2 ) ;
F_4 ( 1 , V_14 ) ;
F_2 ( 0 , V_8 ) ;
F_3 ( 8 ) ;
F_8 ( & V_7 , V_6 ) ;
return 0 ;
}
static int F_11 ( int V_15 )
{
if ( V_15 < 1 || V_15 > 65535 )
return - V_16 ;
V_17 = V_15 ;
V_14 = V_15 * 100 ;
return 0 ;
}
static int F_12 ( int * V_18 )
{
unsigned char V_19 ;
unsigned long V_6 ;
F_6 ( & V_7 , V_6 ) ;
V_19 = F_7 ( V_20 ) ;
F_8 ( & V_7 , V_6 ) ;
* V_18 = 0 ;
if ( V_19 & V_21 )
* V_18 |= V_22 ;
if ( V_19 & V_23 )
* V_18 |= V_24 ;
if ( type == 501 ) {
if ( ! ( V_19 & V_25 ) )
* V_18 |= V_26 ;
if ( ! ( V_19 & V_27 ) )
* V_18 |= V_28 ;
if ( ! ( V_19 & V_29 ) )
* V_18 |= V_30 ;
if ( V_31 ) {
if ( ! ( V_19 & V_32 ) )
* V_18 |= V_33 ;
}
}
return 0 ;
}
static int F_13 ( int * V_34 )
{
unsigned short V_35 ;
unsigned long V_6 ;
F_6 ( & V_7 , V_6 ) ;
V_35 = F_7 ( V_36 ) ;
F_3 ( 8 ) ;
F_8 ( & V_7 , V_6 ) ;
* V_34 = ( V_35 * 11 / 15 ) + 7 ;
return 0 ;
}
static T_1 F_14 ( int V_37 , void * V_38 )
{
unsigned char V_18 ;
F_15 ( & V_7 ) ;
V_18 = F_7 ( V_20 ) ;
F_3 ( 8 ) ;
F_16 ( L_1 , V_18 ) ;
if ( type == 501 ) {
if ( ! ( V_18 & V_25 ) ) {
F_16 ( L_2 , F_7 ( V_36 ) ) ;
F_3 ( 8 ) ;
}
if ( ! ( V_18 & V_27 ) )
F_16 ( L_3 ) ;
if ( ! ( V_18 & V_29 ) )
F_16 ( L_4 ) ;
if ( V_31 ) {
if ( ! ( V_18 & V_32 ) )
F_16 ( L_5 ) ;
}
}
if ( ! ( V_18 & V_39 ) ) {
#ifdef F_17
#ifdef F_18
F_16 ( L_6 ) ;
#else
F_16 ( L_7 ) ;
F_19 ( NULL ) ;
#endif
#else
F_16 ( L_8 ) ;
#endif
}
F_20 ( & V_7 ) ;
return V_40 ;
}
static T_2 F_21 ( struct V_41 * V_41 , const char T_3 * V_42 ,
T_4 V_43 , T_5 * V_44 )
{
if ( V_43 ) {
if ( ! V_45 ) {
T_4 V_46 ;
V_47 = 0 ;
for ( V_46 = 0 ; V_46 != V_43 ; V_46 ++ ) {
char V_35 ;
if ( F_22 ( V_35 , V_42 + V_46 ) )
return - V_48 ;
if ( V_35 == 'V' )
V_47 = 42 ;
}
}
F_10 () ;
}
return V_43 ;
}
static long F_23 ( struct V_41 * V_41 , unsigned int V_49 ,
unsigned long V_50 )
{
void T_3 * V_51 = ( void T_3 * ) V_50 ;
int T_3 * V_52 = V_51 ;
int V_53 ;
int V_18 ;
struct V_54 V_55 = {
. V_56 = V_57 |
V_58 |
V_59 ,
. V_60 = 1 ,
. V_61 = L_9 ,
} ;
V_55 . V_56 |= ( V_22 | V_24 ) ;
if ( type == 501 ) {
V_55 . V_56 |= ( V_26 | V_30 |
V_28 ) ;
if ( V_31 )
V_55 . V_56 |= V_33 ;
}
switch ( V_49 ) {
case V_62 :
return F_24 ( V_51 , & V_55 , sizeof( V_55 ) ) ? - V_48 : 0 ;
case V_63 :
F_12 ( & V_18 ) ;
return F_25 ( V_18 , V_52 ) ;
case V_64 :
return F_25 ( 0 , V_52 ) ;
case V_65 :
F_10 () ;
return 0 ;
case V_66 :
if ( F_22 ( V_53 , V_52 ) )
return - V_48 ;
if ( F_11 ( V_53 ) )
return - V_16 ;
F_10 () ;
case V_67 :
return F_25 ( V_17 , V_52 ) ;
default:
return - V_68 ;
}
}
static int F_26 ( struct V_69 * V_69 , struct V_41 * V_41 )
{
if ( F_27 ( 0 , & V_70 ) )
return - V_71 ;
if ( V_45 )
F_28 ( V_72 ) ;
F_5 () ;
return F_29 ( V_69 , V_41 ) ;
}
static int F_30 ( struct V_69 * V_69 , struct V_41 * V_41 )
{
if ( V_47 == 42 ) {
F_9 () ;
} else {
F_16 ( L_10 ) ;
F_10 () ;
}
V_47 = 0 ;
F_31 ( 0 , & V_70 ) ;
return 0 ;
}
static T_2 F_32 ( struct V_41 * V_41 , char T_3 * V_42 ,
T_4 V_43 , T_5 * V_73 )
{
int V_34 ;
if ( F_13 ( & V_34 ) )
return - V_48 ;
if ( F_24 ( V_42 , & V_34 , 1 ) )
return - V_48 ;
return 1 ;
}
static int F_33 ( struct V_69 * V_69 , struct V_41 * V_41 )
{
return F_29 ( V_69 , V_41 ) ;
}
static int F_34 ( struct V_69 * V_69 , struct V_41 * V_41 )
{
return 0 ;
}
static int F_35 ( struct V_74 * V_75 , unsigned long V_76 ,
void * V_77 )
{
if ( V_76 == V_78 || V_76 == V_79 )
F_9 () ;
return V_80 ;
}
static int F_36 ( struct V_81 * V_82 ,
const struct V_83 * V_84 )
{
int V_85 = - V_86 ;
V_87 ++ ;
if ( V_87 > 1 ) {
F_37 ( L_11 ) ;
return - V_88 ;
}
if ( type != 500 && type != 501 ) {
F_37 ( L_12 , type ) ;
return - V_88 ;
}
if ( F_38 ( V_82 ) ) {
F_37 ( L_13 ) ;
return - V_88 ;
}
if ( F_39 ( V_82 , 2 ) == 0x0000 ) {
F_37 ( L_14 ) ;
V_85 = - V_88 ;
goto V_89;
}
if ( F_40 ( V_82 , 2 , L_15 ) ) {
F_37 ( L_16 ,
( unsigned long long ) F_39 ( V_82 , 2 ) ) ;
goto V_89;
}
V_37 = V_82 -> V_37 ;
V_90 = F_39 ( V_82 , 2 ) ;
if ( F_41 ( V_37 , F_14 , V_91 ,
L_15 , & V_92 ) ) {
F_37 ( L_17 , V_37 ) ;
goto V_93;
}
F_42 ( L_18 ,
( unsigned long long ) V_90 , V_37 ) ;
if ( F_11 ( V_17 ) ) {
F_11 ( V_94 ) ;
F_42 ( L_19 ,
V_94 ) ;
}
V_85 = F_43 ( & V_95 ) ;
if ( V_85 ) {
F_37 ( L_20 , V_85 ) ;
goto V_96;
}
if ( type == 501 ) {
V_85 = F_44 ( & V_97 ) ;
if ( V_85 ) {
F_37 ( L_21 ,
V_98 , V_85 ) ;
goto V_99;
}
}
V_85 = F_44 ( & V_92 ) ;
if ( V_85 ) {
F_37 ( L_21 ,
V_100 , V_85 ) ;
goto V_101;
}
F_42 ( L_22 ,
V_17 , V_45 ) ;
if ( type == 501 )
F_42 ( L_23 ,
V_31 ? L_24 : L_25 ) ;
V_85 = 0 ;
V_102:
return V_85 ;
V_101:
if ( type == 501 )
F_45 ( & V_97 ) ;
V_99:
F_46 ( & V_95 ) ;
V_96:
F_47 ( V_37 , & V_92 ) ;
V_93:
F_48 ( V_82 , 2 ) ;
V_89:
F_49 ( V_82 ) ;
goto V_102;
}
static void F_50 ( struct V_81 * V_103 )
{
F_45 ( & V_92 ) ;
if ( type == 501 )
F_45 ( & V_97 ) ;
F_46 ( & V_95 ) ;
F_47 ( V_37 , & V_92 ) ;
F_48 ( V_103 , 2 ) ;
F_49 ( V_103 ) ;
V_87 -- ;
}

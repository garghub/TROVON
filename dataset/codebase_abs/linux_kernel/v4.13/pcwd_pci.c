static int F_1 ( int V_1 , int * V_2 , int * V_3 )
{
int V_4 , V_5 ;
if ( V_6 >= V_7 )
F_2 ( L_1 ,
V_1 , * V_2 , * V_3 ) ;
F_3 ( & V_8 . V_9 ) ;
F_4 ( * V_3 , V_8 . V_10 + 4 ) ;
F_4 ( * V_2 , V_8 . V_10 + 5 ) ;
F_4 ( V_1 , V_8 . V_10 + 6 ) ;
V_4 = F_5 ( V_8 . V_10 + 2 ) & V_11 ;
for ( V_5 = 0 ; ( V_5 < V_12 ) && ( ! V_4 ) ;
V_5 ++ ) {
F_6 ( 1 ) ;
V_4 = F_5 ( V_8 . V_10 + 2 ) & V_11 ;
}
if ( V_6 >= V_7 ) {
if ( V_4 ) {
F_2 ( L_2 ,
V_5 ) ;
} else {
F_2 ( L_3 ) ;
}
}
if ( V_4 ) {
* V_3 = F_5 ( V_8 . V_10 + 4 ) ;
* V_2 = F_5 ( V_8 . V_10 + 5 ) ;
F_5 ( V_8 . V_10 + 6 ) ;
if ( V_6 >= V_7 )
F_2 ( L_4 ,
V_1 , * V_2 , * V_3 ) ;
}
F_7 ( & V_8 . V_9 ) ;
return V_4 ;
}
static inline void F_8 ( void )
{
if ( F_5 ( V_8 . V_10 ) != 0xF0 )
V_8 . V_13 = 1 ;
}
static int F_9 ( void )
{
int V_14 ;
V_14 = F_5 ( V_8 . V_10 + 3 ) ;
return V_14 ;
}
static void F_10 ( void )
{
int V_15 , V_16 , V_17 ;
char V_18 [ 20 ] ;
int V_14 ;
V_15 = F_1 ( V_19 , & V_16 ,
& V_17 ) ;
if ( V_15 )
sprintf ( V_18 , L_5 , V_16 , V_17 ) ;
else
sprintf ( V_18 , L_6 ) ;
V_14 = F_9 () ;
F_11 ( L_7 ,
( int ) V_8 . V_10 , V_18 ,
( V_8 . V_13 ? L_8 : L_9 ) ) ;
F_11 ( L_10 ,
V_14 ,
( ( V_14 & 0x10 ) ? L_11 : L_12 ) ,
( ( V_14 & 0x08 ) ? L_11 : L_12 ) ) ;
if ( V_8 . V_20 & V_21 )
F_11 ( L_13 ) ;
if ( V_8 . V_20 & V_22 )
F_11 ( L_14 ) ;
if ( V_8 . V_20 == 0 )
F_11 ( L_15 ) ;
}
static int F_12 ( void )
{
int V_23 ;
F_3 ( & V_8 . V_9 ) ;
F_4 ( 0x00 , V_8 . V_10 + 3 ) ;
F_13 ( 1000 ) ;
V_23 = F_5 ( V_8 . V_10 + 2 ) ;
F_7 ( & V_8 . V_9 ) ;
if ( V_23 & V_24 ) {
F_14 ( L_16 ) ;
return - 1 ;
}
if ( V_6 >= V_25 )
F_2 ( L_17 ) ;
return 0 ;
}
static int F_15 ( void )
{
int V_23 ;
F_3 ( & V_8 . V_9 ) ;
F_4 ( 0xA5 , V_8 . V_10 + 3 ) ;
F_13 ( 1000 ) ;
F_4 ( 0xA5 , V_8 . V_10 + 3 ) ;
F_13 ( 1000 ) ;
V_23 = F_5 ( V_8 . V_10 + 2 ) ;
F_7 ( & V_8 . V_9 ) ;
if ( ! ( V_23 & V_24 ) ) {
F_14 ( L_18 ) ;
return - 1 ;
}
if ( V_6 >= V_25 )
F_2 ( L_19 ) ;
return 0 ;
}
static int F_16 ( void )
{
F_3 ( & V_8 . V_9 ) ;
F_4 ( 0x42 , V_8 . V_10 ) ;
F_7 ( & V_8 . V_9 ) ;
if ( V_6 >= V_7 )
F_2 ( L_20 ) ;
return 0 ;
}
static int F_17 ( int V_26 )
{
int V_27 = V_26 / 256 ;
int V_28 = V_26 % 256 ;
if ( ( V_26 < 0x0001 ) || ( V_26 > 0xFFFF ) )
return - V_29 ;
F_1 ( V_30 , & V_27 , & V_28 ) ;
V_31 = V_26 ;
if ( V_6 >= V_25 )
F_2 ( L_21 , V_31 ) ;
return 0 ;
}
static int F_18 ( int * V_32 )
{
int V_33 ;
* V_32 = 0 ;
V_33 = F_5 ( V_8 . V_10 + 1 ) ;
if ( V_33 & V_34 )
* V_32 |= V_21 ;
if ( V_33 & V_35 ) {
* V_32 |= V_22 ;
if ( V_36 )
F_19 ( V_37 L_22 ) ;
}
if ( V_6 >= V_7 )
F_2 ( L_23 , V_33 ) ;
return 0 ;
}
static int F_20 ( void )
{
int V_33 ;
int V_2 ;
int V_38 ;
if ( V_6 >= V_25 )
F_11 ( L_24 ) ;
V_33 = F_5 ( V_8 . V_10 + 1 ) ;
if ( V_6 >= V_7 ) {
F_2 ( L_25 , V_33 ) ;
F_2 ( L_26 ,
( V_33 & V_39 ) | V_34 ) ;
}
F_4 ( ( V_33 & V_39 ) | V_34 ,
V_8 . V_10 + 1 ) ;
V_2 = 0 ;
V_38 = 0xff ;
F_1 ( V_40 , & V_2 , & V_38 ) ;
if ( V_6 >= V_7 ) {
F_2 ( L_27 , V_38 ) ;
}
return 0 ;
}
static int F_21 ( int * V_41 )
{
* V_41 = 0 ;
if ( ! V_8 . V_13 )
return - V_42 ;
F_3 ( & V_8 . V_9 ) ;
* V_41 = F_5 ( V_8 . V_10 ) ;
F_7 ( & V_8 . V_9 ) ;
* V_41 = ( * V_41 * 9 / 5 ) + 32 ;
if ( V_6 >= V_7 ) {
F_2 ( L_28 , * V_41 ) ;
}
return 0 ;
}
static int F_22 ( int * V_43 )
{
int V_2 ;
int V_3 ;
F_1 ( V_44 , & V_2 , & V_3 ) ;
* V_43 = ( V_2 << 8 ) + V_3 ;
if ( V_6 >= V_25 )
F_2 ( L_29 , * V_43 ) ;
return 0 ;
}
static T_1 F_23 ( struct V_45 * V_45 , const char T_2 * V_46 ,
T_3 V_47 , T_4 * V_48 )
{
if ( V_47 ) {
if ( ! V_49 ) {
T_3 V_50 ;
V_51 = 0 ;
for ( V_50 = 0 ; V_50 != V_47 ; V_50 ++ ) {
char V_52 ;
if ( F_24 ( V_52 , V_46 + V_50 ) )
return - V_53 ;
if ( V_52 == 'V' )
V_51 = 42 ;
}
}
F_16 () ;
}
return V_47 ;
}
static long F_25 ( struct V_45 * V_45 , unsigned int V_1 ,
unsigned long V_54 )
{
void T_2 * V_55 = ( void T_2 * ) V_54 ;
int T_2 * V_56 = V_55 ;
static const struct V_57 V_58 = {
. V_59 = V_22 |
V_21 |
V_60 |
V_61 |
V_62 ,
. V_63 = 1 ,
. V_64 = V_65 ,
} ;
switch ( V_1 ) {
case V_66 :
return F_26 ( V_55 , & V_58 , sizeof( V_58 ) ) ? - V_53 : 0 ;
case V_67 :
{
int V_32 ;
F_18 ( & V_32 ) ;
return F_27 ( V_32 , V_56 ) ;
}
case V_68 :
return F_27 ( V_8 . V_20 , V_56 ) ;
case V_69 :
{
int V_41 ;
if ( F_21 ( & V_41 ) )
return - V_53 ;
return F_27 ( V_41 , V_56 ) ;
}
case V_70 :
{
int V_71 , V_72 = - V_29 ;
if ( F_24 ( V_71 , V_56 ) )
return - V_53 ;
if ( V_71 & V_73 ) {
if ( F_15 () )
return - V_74 ;
V_72 = 0 ;
}
if ( V_71 & V_75 ) {
if ( F_12 () )
return - V_74 ;
V_72 = 0 ;
}
if ( V_71 & V_76 ) {
V_36 = 1 ;
V_72 = 0 ;
}
return V_72 ;
}
case V_77 :
F_16 () ;
return 0 ;
case V_78 :
{
int V_79 ;
if ( F_24 ( V_79 , V_56 ) )
return - V_53 ;
if ( F_17 ( V_79 ) )
return - V_29 ;
F_16 () ;
}
case V_80 :
return F_27 ( V_31 , V_56 ) ;
case V_81 :
{
int V_43 ;
if ( F_22 ( & V_43 ) )
return - V_53 ;
return F_27 ( V_43 , V_56 ) ;
}
default:
return - V_82 ;
}
}
static int F_28 ( struct V_83 * V_83 , struct V_45 * V_45 )
{
if ( F_29 ( 0 , & V_84 ) ) {
if ( V_6 >= V_25 )
F_14 ( L_30 ) ;
return - V_85 ;
}
F_12 () ;
F_16 () ;
return F_30 ( V_83 , V_45 ) ;
}
static int F_31 ( struct V_83 * V_83 , struct V_45 * V_45 )
{
if ( V_51 == 42 ) {
F_15 () ;
} else {
F_32 ( L_31 ) ;
F_16 () ;
}
V_51 = 0 ;
F_33 ( 0 , & V_84 ) ;
return 0 ;
}
static T_1 F_34 ( struct V_45 * V_45 , char T_2 * V_46 ,
T_3 V_47 , T_4 * V_48 )
{
int V_41 ;
if ( F_21 ( & V_41 ) )
return - V_53 ;
if ( F_26 ( V_46 , & V_41 , 1 ) )
return - V_53 ;
return 1 ;
}
static int F_35 ( struct V_83 * V_83 , struct V_45 * V_45 )
{
if ( ! V_8 . V_13 )
return - V_42 ;
return F_30 ( V_83 , V_45 ) ;
}
static int F_36 ( struct V_83 * V_83 , struct V_45 * V_45 )
{
return 0 ;
}
static int F_37 ( struct V_86 * V_87 , unsigned long V_88 ,
void * V_89 )
{
if ( V_88 == V_90 || V_88 == V_91 )
F_15 () ;
return V_92 ;
}
static int F_38 ( struct V_93 * V_94 ,
const struct V_95 * V_96 )
{
int V_97 = - V_74 ;
V_98 ++ ;
if ( V_98 == 1 )
F_11 ( L_32 , V_99 ) ;
if ( V_98 > 1 ) {
F_14 ( L_33 ) ;
return - V_42 ;
}
if ( F_39 ( V_94 ) ) {
F_14 ( L_34 ) ;
return - V_42 ;
}
if ( F_40 ( V_94 , 0 ) == 0x0000 ) {
F_14 ( L_35 ) ;
V_97 = - V_42 ;
goto V_100;
}
F_41 ( & V_8 . V_9 ) ;
V_8 . V_94 = V_94 ;
V_8 . V_10 = F_40 ( V_94 , 0 ) ;
if ( F_42 ( V_94 , V_101 ) ) {
F_14 ( L_36 ,
( int ) V_8 . V_10 ) ;
V_97 = - V_74 ;
goto V_100;
}
F_18 ( & V_8 . V_20 ) ;
F_20 () ;
F_15 () ;
F_8 () ;
F_10 () ;
if ( V_31 == 0 )
V_31 =
V_102 [ ( F_9 () & 0x07 ) ] ;
if ( F_17 ( V_31 ) ) {
F_17 ( V_103 ) ;
F_11 ( L_37 ,
V_103 ) ;
}
V_97 = F_43 ( & V_104 ) ;
if ( V_97 != 0 ) {
F_14 ( L_38 , V_97 ) ;
goto V_105;
}
if ( V_8 . V_13 ) {
V_97 = F_44 ( & V_106 ) ;
if ( V_97 != 0 ) {
F_14 ( L_39 ,
V_107 , V_97 ) ;
goto V_108;
}
}
V_97 = F_44 ( & V_109 ) ;
if ( V_97 != 0 ) {
F_14 ( L_39 ,
V_110 , V_97 ) ;
goto V_111;
}
F_11 ( L_40 ,
V_31 , V_49 ) ;
return 0 ;
V_111:
if ( V_8 . V_13 )
F_45 ( & V_106 ) ;
V_108:
F_46 ( & V_104 ) ;
V_105:
F_47 ( V_94 ) ;
V_100:
F_48 ( V_94 ) ;
return V_97 ;
}
static void F_49 ( struct V_93 * V_94 )
{
if ( ! V_49 )
F_15 () ;
F_45 ( & V_109 ) ;
if ( V_8 . V_13 )
F_45 ( & V_106 ) ;
F_46 ( & V_104 ) ;
F_47 ( V_94 ) ;
F_48 ( V_94 ) ;
V_98 -- ;
}

static inline void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline unsigned int F_3 ( struct V_1 * V_2 , unsigned int V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_6 ( V_2 ,
struct V_6 ,
V_7 ) ;
V_6 -> V_8 &= ~ V_9 ;
F_1 ( V_2 , V_6 -> V_8 , V_10 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_6 ( V_2 ,
struct V_6 ,
V_7 ) ;
V_6 -> V_8 &= ~ V_11 ;
F_1 ( V_2 , V_6 -> V_8 , V_10 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_6 ( V_2 ,
struct V_6 ,
V_7 ) ;
V_6 -> V_8 |= V_12 ;
F_1 ( V_2 , V_6 -> V_8 , V_10 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_10 ( & V_2 -> V_15 -> V_2 ) ;
if ( ! V_14 ) {
int V_16 = ( F_3 ( V_2 , V_17 ) & 0x1f00 ) >> 8 ;
T_1 V_18 ;
while ( V_16 -- )
V_18 = F_11 ( V_2 -> V_5 + V_19 ) ;
return;
}
if ( ( F_3 ( V_2 , V_20 ) & V_21 ) ) {
V_2 -> V_22 . V_23 ++ ;
F_12 ( V_14 , 0 , V_24 ) ;
}
while ( F_3 ( V_2 , V_17 ) & 0x1f00 ) {
unsigned int V_25 ;
char V_26 = V_27 ;
V_25 = F_11 ( V_2 -> V_5 + V_19 ) & 0x3ff ;
V_25 &= ~ V_2 -> V_28 ;
if ( V_25 & V_29 ) {
V_2 -> V_22 . V_30 ++ ;
V_26 = V_31 ;
} else if ( V_25 & V_32 ) {
V_2 -> V_22 . V_33 ++ ;
V_26 = V_34 ;
}
V_2 -> V_22 . V_35 ++ ;
if ( ! F_13 ( V_2 , V_25 ) )
F_12 ( V_14 , V_25 , V_26 ) ;
}
F_14 ( V_14 ) ;
F_15 ( V_14 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = & V_2 -> V_15 -> V_37 ;
if ( V_2 -> V_38 ) {
F_17 ( V_2 -> V_38 , V_2 -> V_5 + V_39 ) ;
V_2 -> V_22 . V_40 ++ ;
V_2 -> V_38 = 0 ;
}
if ( F_18 ( V_37 ) || F_19 ( V_2 ) ) {
F_5 ( V_2 ) ;
return;
}
while ( ( F_3 ( V_2 , V_17 ) & 0x1f ) < 16 ) {
if ( F_18 ( V_37 ) )
break;
F_17 ( V_37 -> V_41 [ V_37 -> V_42 ] , V_2 -> V_5 + V_39 ) ;
V_37 -> V_42 = ( V_37 -> V_42 + 1 ) & ( V_43 - 1 ) ;
V_2 -> V_22 . V_40 ++ ;
}
if ( F_20 ( V_37 ) < V_44 )
F_21 ( V_2 ) ;
if ( F_18 ( V_37 ) )
F_5 ( V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_6 ( V_2 ,
struct V_6 ,
V_7 ) ;
V_6 -> V_8 &= ~ V_9 ;
F_1 ( V_2 , V_6 -> V_8 , V_10 ) ;
F_16 ( V_2 ) ;
V_6 -> V_8 |= V_9 ;
F_1 ( V_2 , V_6 -> V_8 , V_10 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_45 ++ ;
F_24 ( & V_2 -> V_15 -> V_2 . V_46 ) ;
}
static T_2 F_25 ( int V_47 , void * V_48 )
{
struct V_1 * V_2 = V_48 ;
unsigned long V_49 ;
F_26 ( & V_2 -> V_50 ) ;
V_49 = F_3 ( V_2 , V_20 ) ;
F_1 ( V_2 , V_49 , V_20 ) ;
if ( V_49 & V_11 )
F_9 ( V_2 ) ;
if ( V_49 & V_9 )
F_16 ( V_2 ) ;
if ( V_49 & V_12 )
F_23 ( V_2 ) ;
F_27 ( & V_2 -> V_50 ) ;
return V_51 ;
}
static unsigned int F_28 ( struct V_1 * V_2 )
{
return ( F_3 ( V_2 , V_17 ) & 0x1f ) < 16 ?
V_52 : 0 ;
}
static unsigned int F_29 ( struct V_1 * V_2 )
{
unsigned int V_53 ;
V_53 = F_3 ( V_2 , V_54 ) ;
if ( V_53 & ( 1 << 4 ) )
return V_55 ;
else
return 0 ;
}
static void F_30 ( struct V_1 * V_2 , unsigned int V_56 )
{
}
static void F_31 ( struct V_1 * V_2 , int V_57 )
{
if ( V_57 )
F_1 ( V_2 , F_3 ( V_2 , V_58 ) | ( 1 << 9 ) ,
V_58 ) ;
}
static int F_32 ( struct V_1 * V_2 , unsigned int V_59 )
{
unsigned long div ;
unsigned int V_60 = 1000 ;
div = F_3 ( V_2 , V_61 ) & ~ ( 0x3ff ) ;
if ( F_33 ( ( V_59 < 900 ) || ( V_59 > 921600 ) ) )
div |= 7 ;
else
div |= ( 921600 / V_59 ) - 1 ;
while ( ( F_3 ( V_2 , V_54 ) & ( 1 << 5 ) ) && -- V_60 )
F_34 () ;
F_1 ( V_2 , div , V_61 ) ;
return V_59 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_6 * V_6 =
F_6 ( V_2 , struct V_6 , V_7 ) ;
int V_62 ;
snprintf ( V_6 -> V_63 , sizeof( V_6 -> V_63 ) ,
L_1 , V_2 -> line ) ;
V_62 = F_36 ( V_2 -> V_47 , F_25 , V_64 ,
V_6 -> V_63 , V_2 ) ;
if ( F_33 ( V_62 ) )
return V_62 ;
F_1 ( V_2 , 0x03 , V_58 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_6 * V_6 =
F_6 ( V_2 , struct V_6 , V_7 ) ;
V_6 -> V_8 = 0 ;
F_1 ( & V_6 -> V_7 , 0 , V_10 ) ;
F_1 ( & V_6 -> V_7 , 0x880 , V_65 ) ;
F_38 ( V_2 -> V_47 , V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_66 * V_67 ,
struct V_66 * V_68 )
{
struct V_6 * V_6 =
F_6 ( V_2 , struct V_6 , V_7 ) ;
unsigned long V_69 ;
unsigned int V_59 , V_70 ;
unsigned int V_60 = 1000 ;
F_40 ( & V_2 -> V_50 , V_69 ) ;
V_59 = F_41 ( V_2 , V_67 , V_68 , 900 , 921600 ) ;
V_59 = F_32 ( V_2 , V_59 ) ;
if ( F_42 ( V_67 ) )
F_43 ( V_67 , V_59 , V_59 ) ;
V_70 = F_3 ( & V_6 -> V_7 , V_58 ) ;
V_70 &= ~ ( ( 1 << 5 ) | ( 1 << 4 ) ) ;
if ( V_67 -> V_71 & V_72 ) {
V_70 |= ( 1 << 4 ) ;
V_67 -> V_71 &= ~ V_73 ;
if ( V_67 -> V_71 & V_74 )
V_70 |= ( 1 << 5 ) ;
}
V_70 &= ~ ( 1 << 2 ) ;
switch ( V_67 -> V_71 & V_75 ) {
case V_76 :
break;
case V_77 :
default:
V_70 |= ( 1 << 2 ) ;
V_67 -> V_71 &= ~ V_75 ;
V_67 -> V_71 |= V_77 ;
break;
}
V_70 &= ~ ( 1 << 3 ) ;
if ( V_67 -> V_71 & V_78 )
V_70 |= ( 1 << 3 ) ;
F_1 ( & V_6 -> V_7 , V_70 , V_58 ) ;
V_2 -> V_28 = 0 ;
if ( V_67 -> V_79 & V_80 )
V_2 -> V_28 = V_29 | V_32 ;
F_44 ( V_2 , V_67 -> V_71 , V_59 ) ;
F_1 ( & V_6 -> V_7 , 0x88c , V_65 ) ;
while ( ( F_3 ( & V_6 -> V_7 , V_65 ) & 0xc )
&& -- V_60 )
F_34 () ;
V_6 -> V_8 = V_11 | V_9 ;
if ( F_45 ( & V_6 -> V_7 , V_67 -> V_71 ) )
V_6 -> V_8 |= V_12 ;
F_1 ( & V_6 -> V_7 , 0x881 , V_65 ) ;
F_1 ( & V_6 -> V_7 , V_6 -> V_8 , V_10 ) ;
F_46 ( & V_2 -> V_50 , V_69 ) ;
}
static const char * F_47 ( struct V_1 * V_2 )
{
struct V_6 * V_6 =
F_6 ( V_2 , struct V_6 , V_7 ) ;
return V_6 -> V_63 ;
}
static void F_48 ( struct V_1 * V_2 )
{
}
static int F_49 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_50 ( struct V_1 * V_2 , int V_69 )
{
V_2 -> type = V_81 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_82 * V_83 )
{
if ( F_33 ( V_83 -> type != V_84 && V_83 -> type != V_81 ) )
return - V_85 ;
if ( F_33 ( V_2 -> V_47 != V_83 -> V_47 ) )
return - V_85 ;
return 0 ;
}
static inline void F_52 ( struct V_1 * V_2 )
{
unsigned int V_86 , V_87 = 10000 ;
do {
V_86 = F_3 ( V_2 , V_17 ) ;
if ( -- V_87 == 0 )
break;
F_53 ( 1 ) ;
} while ( V_86 & 0x10 );
}
static void F_54 ( struct V_1 * V_2 , int V_25 )
{
F_52 ( V_2 ) ;
F_17 ( V_25 , V_2 -> V_5 + V_39 ) ;
}
static void F_55 ( struct V_88 * V_89 , const char * V_90 ,
unsigned int V_16 )
{
struct V_6 * V_6 = V_91 [ V_89 -> V_92 ] ;
unsigned long V_8 ;
F_56 ( V_89 -> V_92 < 0 || V_89 -> V_92 >= V_93 . V_94 ) ;
V_8 = F_3 ( & V_6 -> V_7 , V_10 ) ;
F_1 ( & V_6 -> V_7 , V_10 , 0 ) ;
F_57 ( & V_6 -> V_7 , V_90 , V_16 ,
F_54 ) ;
F_52 ( & V_6 -> V_7 ) ;
F_1 ( & V_6 -> V_7 , V_10 , V_8 ) ;
}
static int T_3 F_58 ( struct V_88 * V_89 , char * V_95 )
{
struct V_6 * V_6 ;
int V_59 = 9600 ;
int V_96 = 8 ;
int V_33 = 'n' ;
int V_97 = 'n' ;
if ( F_33 ( V_89 -> V_92 >= V_93 . V_94 || V_89 -> V_92 < 0 ) )
return - V_98 ;
V_6 = V_91 [ V_89 -> V_92 ] ;
if ( ! V_6 )
return - V_99 ;
if ( V_95 )
F_59 ( V_95 , & V_59 , & V_33 , & V_96 , & V_97 ) ;
return F_60 ( & V_6 -> V_7 ,
V_89 , V_59 , V_33 , V_96 , V_97 ) ;
}
static int T_3 F_61 ( struct V_100 * V_101 )
{
struct V_6 * V_6 ;
struct V_102 * V_103 , * V_104 ;
int V_62 ;
V_103 = F_62 ( V_101 , V_105 , 0 ) ;
V_104 = F_62 ( V_101 , V_106 , 0 ) ;
if ( ! V_103 || ! V_104 )
return - V_99 ;
V_6 = F_63 ( sizeof( struct V_6 ) , V_107 ) ;
if ( ! V_6 )
return - V_108 ;
V_6 -> V_7 . type = V_81 ;
V_6 -> V_7 . V_109 = V_110 ;
V_6 -> V_7 . V_111 = V_103 -> V_112 ;
V_6 -> V_7 . V_47 = V_104 -> V_112 ;
V_6 -> V_7 . V_113 = 16 ;
V_6 -> V_7 . V_114 = & V_115 ;
V_6 -> V_7 . line = V_101 -> V_116 ;
V_6 -> V_7 . V_117 = & V_101 -> V_117 ;
V_6 -> V_7 . V_69 = V_118 | V_119 ;
V_6 -> V_7 . V_120 = 24000000 ;
snprintf ( V_6 -> V_63 , sizeof( V_6 -> V_63 ) ,
L_2 , V_101 -> V_116 ) ;
V_6 -> V_7 . V_5 = F_64 ( V_103 -> V_112 , F_65 ( V_103 ) ) ;
if ( ! V_6 -> V_7 . V_5 ) {
V_62 = - V_108 ;
goto V_121;
}
V_91 [ V_101 -> V_116 ] = V_6 ;
F_66 ( & V_93 , & V_6 -> V_7 ) ;
F_67 ( V_101 , V_6 ) ;
return 0 ;
V_121:
F_68 ( V_6 ) ;
return V_62 ;
}
static int T_4 F_69 ( struct V_100 * V_101 )
{
struct V_6 * V_6 = F_70 ( V_101 ) ;
F_67 ( V_101 , NULL ) ;
F_71 ( & V_93 , & V_6 -> V_7 ) ;
F_68 ( V_6 ) ;
return 0 ;
}
static int T_3 F_72 ( void )
{
int V_62 ;
V_62 = F_73 ( & V_93 ) ;
if ( F_33 ( V_62 ) )
return V_62 ;
V_62 = F_74 ( & V_122 ) ;
if ( F_33 ( V_62 ) )
F_75 ( & V_93 ) ;
return V_62 ;
}
static void T_5 F_76 ( void )
{
#ifdef F_77
F_78 ( & V_123 ) ;
#endif
F_79 ( & V_122 ) ;
F_75 ( & V_93 ) ;
}

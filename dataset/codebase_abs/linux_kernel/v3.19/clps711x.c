static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
if ( V_4 -> V_6 ) {
F_3 ( V_2 -> V_7 ) ;
V_4 -> V_6 = 0 ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
if ( ! V_4 -> V_6 ) {
V_4 -> V_6 = 1 ;
F_5 ( V_2 -> V_7 ) ;
}
}
static T_1 F_6 ( int V_7 , void * V_8 )
{
struct V_1 * V_2 = V_8 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
unsigned int V_9 , V_10 ;
T_2 V_11 ;
for (; ; ) {
T_3 V_12 = 0 ;
F_7 ( V_4 -> V_13 , V_14 , & V_12 ) ;
if ( V_12 & V_15 )
break;
V_11 = F_8 ( V_2 -> V_16 + V_17 ) ;
V_9 = V_11 & ( V_18 | V_19 | V_20 ) ;
V_11 &= 0xff ;
V_2 -> V_21 . V_22 ++ ;
V_10 = V_23 ;
if ( F_9 ( V_9 ) ) {
if ( V_9 & V_19 )
V_2 -> V_21 . V_24 ++ ;
else if ( V_9 & V_18 )
V_2 -> V_21 . V_25 ++ ;
else if ( V_9 & V_20 )
V_2 -> V_21 . V_26 ++ ;
V_9 &= V_2 -> V_27 ;
if ( V_9 & V_19 )
V_10 = V_28 ;
else if ( V_9 & V_18 )
V_10 = V_29 ;
else if ( V_9 & V_20 )
V_10 = V_30 ;
}
if ( F_10 ( V_2 , V_11 ) )
continue;
if ( V_9 & V_2 -> V_31 )
continue;
F_11 ( V_2 , V_9 , V_20 , V_11 , V_10 ) ;
}
F_12 ( & V_2 -> V_32 -> V_2 ) ;
return V_33 ;
}
static T_1 F_13 ( int V_7 , void * V_8 )
{
struct V_1 * V_2 = V_8 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_34 * V_35 = & V_2 -> V_32 -> V_35 ;
if ( V_2 -> V_36 ) {
F_14 ( V_2 -> V_36 , V_2 -> V_16 + V_17 ) ;
V_2 -> V_21 . V_37 ++ ;
V_2 -> V_36 = 0 ;
return V_33 ;
}
if ( F_15 ( V_35 ) || F_16 ( V_2 ) ) {
if ( V_4 -> V_6 ) {
F_17 ( V_2 -> V_7 ) ;
V_4 -> V_6 = 0 ;
}
return V_33 ;
}
while ( ! F_15 ( V_35 ) ) {
T_3 V_12 = 0 ;
F_14 ( V_35 -> V_38 [ V_35 -> V_39 ] , V_2 -> V_16 + V_17 ) ;
V_35 -> V_39 = ( V_35 -> V_39 + 1 ) & ( V_40 - 1 ) ;
V_2 -> V_21 . V_37 ++ ;
F_7 ( V_4 -> V_13 , V_14 , & V_12 ) ;
if ( V_12 & V_41 )
break;
}
if ( F_18 ( V_35 ) < V_42 )
F_19 ( V_2 ) ;
return V_33 ;
}
static unsigned int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
T_3 V_12 = 0 ;
F_7 ( V_4 -> V_13 , V_14 , & V_12 ) ;
return ( V_12 & V_43 ) ? 0 : V_44 ;
}
static unsigned int F_21 ( struct V_1 * V_2 )
{
unsigned int V_45 = V_46 | V_47 | V_48 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
return F_22 ( V_4 -> V_49 , & V_45 ) ;
}
static void F_23 ( struct V_1 * V_2 , unsigned int V_50 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
F_24 ( V_4 -> V_49 , V_50 ) ;
}
static void F_25 ( struct V_1 * V_2 , int V_51 )
{
unsigned int V_52 ;
V_52 = F_26 ( V_2 -> V_16 + V_53 ) ;
if ( V_51 )
V_52 |= V_54 ;
else
V_52 &= ~ V_54 ;
F_27 ( V_52 , V_2 -> V_16 + V_53 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
if ( ! V_2 -> line ) {
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
F_29 ( V_4 -> V_13 , V_57 , V_58 ,
( V_56 -> V_59 == V_60 ) ? V_58 : 0 ) ;
}
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
F_27 ( F_26 ( V_2 -> V_16 + V_53 ) & ~ V_54 ,
V_2 -> V_16 + V_53 ) ;
return F_29 ( V_4 -> V_13 , V_57 ,
V_61 , V_61 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
F_29 ( V_4 -> V_13 , V_57 , V_61 , 0 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
struct V_55 * V_62 )
{
T_3 V_52 ;
unsigned int V_63 , V_64 ;
V_56 -> V_65 &= ~ V_66 ;
V_56 -> V_67 &= ~ ( V_68 | V_69 ) ;
V_63 = F_33 ( V_2 , V_56 , V_62 , V_2 -> V_70 / 4096 ,
V_2 -> V_70 / 16 ) ;
V_64 = F_34 ( V_2 , V_63 ) ;
switch ( V_56 -> V_65 & V_71 ) {
case V_72 :
V_52 = V_73 ;
break;
case V_74 :
V_52 = V_75 ;
break;
case V_76 :
V_52 = V_77 ;
break;
case V_78 :
default:
V_52 = V_79 ;
break;
}
if ( V_56 -> V_65 & V_80 )
V_52 |= V_81 ;
if ( V_56 -> V_65 & V_82 ) {
V_52 |= V_83 ;
if ( ! ( V_56 -> V_65 & V_84 ) )
V_52 |= V_85 ;
}
V_52 |= V_86 ;
V_2 -> V_27 = V_20 ;
if ( V_56 -> V_67 & V_87 )
V_2 -> V_27 |= V_19 | V_18 ;
V_2 -> V_31 = 0 ;
if ( ! ( V_56 -> V_65 & V_88 ) )
V_2 -> V_31 |= V_20 | V_19 |
V_18 ;
F_35 ( V_2 , V_56 -> V_65 , V_63 ) ;
F_27 ( V_52 | ( V_64 - 1 ) , V_2 -> V_16 + V_53 ) ;
}
static const char * F_36 ( struct V_1 * V_2 )
{
return ( V_2 -> type == V_89 ) ? L_1 : NULL ;
}
static void F_37 ( struct V_1 * V_2 , int V_90 )
{
if ( V_90 & V_91 )
V_2 -> type = V_89 ;
}
static void F_38 ( struct V_1 * V_2 )
{
}
static int F_39 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_40 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
T_3 V_12 = 0 ;
do {
F_7 ( V_4 -> V_13 , V_14 , & V_12 ) ;
} while ( V_12 & V_41 );
F_14 ( V_11 , V_2 -> V_16 + V_17 ) ;
}
static void F_41 ( struct V_92 * V_93 , const char * V_94 ,
unsigned V_95 )
{
struct V_1 * V_2 = V_96 . V_32 [ V_93 -> V_97 ] . V_1 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
T_3 V_12 = 0 ;
F_42 ( V_2 , V_94 , V_95 , F_40 ) ;
do {
F_7 ( V_4 -> V_13 , V_14 , & V_12 ) ;
} while ( V_12 & V_43 );
}
static int F_43 ( struct V_92 * V_93 , char * V_98 )
{
int V_63 = 38400 , V_99 = 8 , V_24 = 'n' , V_100 = 'n' ;
int V_101 , V_97 = V_93 -> V_97 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
unsigned int V_64 ;
T_3 V_52 ;
if ( V_97 < 0 || V_97 >= V_102 )
return - V_103 ;
V_2 = V_96 . V_32 [ V_97 ] . V_1 ;
if ( ! V_2 )
return - V_104 ;
V_4 = F_2 ( V_2 -> V_5 ) ;
if ( ! V_98 ) {
T_3 V_13 = 0 ;
F_7 ( V_4 -> V_13 , V_57 , & V_13 ) ;
if ( V_13 & V_61 ) {
V_52 = F_26 ( V_2 -> V_16 + V_53 ) ;
if ( V_52 & V_83 ) {
if ( V_52 & V_85 )
V_24 = 'e' ;
else
V_24 = 'o' ;
}
if ( ( V_52 & V_105 ) == V_77 )
V_99 = 7 ;
V_64 = V_52 & V_106 ;
V_63 = V_2 -> V_70 / ( 16 * ( V_64 + 1 ) ) ;
}
} else
F_44 ( V_98 , & V_63 , & V_24 , & V_99 , & V_100 ) ;
V_101 = F_45 ( V_2 , V_93 , V_63 , V_24 , V_99 , V_100 ) ;
if ( V_101 )
return V_101 ;
return F_29 ( V_4 -> V_13 , V_57 ,
V_61 , V_61 ) ;
}
static int F_46 ( struct V_107 * V_108 )
{
struct V_109 * V_110 = V_108 -> V_5 . V_111 ;
int V_101 , V_97 = V_110 ? F_47 ( V_110 , L_2 ) : V_108 -> V_112 ;
struct V_3 * V_4 ;
struct V_113 * V_114 ;
struct V_115 * V_116 ;
if ( V_97 < 0 || V_97 >= V_102 )
return - V_103 ;
V_4 = F_48 ( & V_108 -> V_5 , sizeof( * V_4 ) , V_117 ) ;
if ( ! V_4 )
return - V_118 ;
V_116 = F_49 ( & V_108 -> V_5 , NULL ) ;
if ( F_50 ( V_116 ) )
return F_51 ( V_116 ) ;
V_114 = F_52 ( V_108 , V_119 , 0 ) ;
V_4 -> V_2 . V_16 = F_53 ( & V_108 -> V_5 , V_114 ) ;
if ( F_50 ( V_4 -> V_2 . V_16 ) )
return F_51 ( V_4 -> V_2 . V_16 ) ;
V_4 -> V_2 . V_7 = F_54 ( V_108 , 0 ) ;
if ( F_55 ( V_4 -> V_2 . V_7 ) )
return V_4 -> V_2 . V_7 ;
V_4 -> V_120 = F_54 ( V_108 , 1 ) ;
if ( F_55 ( V_4 -> V_120 ) )
return V_4 -> V_120 ;
if ( ! V_110 ) {
char V_121 [ 9 ] ;
sprintf ( V_121 , L_3 , V_97 + 1 ) ;
V_4 -> V_13 = F_56 ( V_121 ) ;
if ( F_50 ( V_4 -> V_13 ) )
return F_51 ( V_4 -> V_13 ) ;
} else {
V_4 -> V_13 = F_57 ( V_110 , L_4 ) ;
if ( F_50 ( V_4 -> V_13 ) )
return F_51 ( V_4 -> V_13 ) ;
}
V_4 -> V_2 . line = V_97 ;
V_4 -> V_2 . V_5 = & V_108 -> V_5 ;
V_4 -> V_2 . V_122 = V_123 ;
V_4 -> V_2 . V_124 = V_114 -> V_125 ;
V_4 -> V_2 . type = V_89 ;
V_4 -> V_2 . V_126 = 16 ;
V_4 -> V_2 . V_90 = V_127 | V_128 ;
V_4 -> V_2 . V_70 = F_58 ( V_116 ) ;
V_4 -> V_2 . V_129 = & V_130 ;
F_59 ( V_108 , V_4 ) ;
V_4 -> V_49 = F_60 ( & V_108 -> V_5 , 0 ) ;
V_101 = F_61 ( & V_96 , & V_4 -> V_2 ) ;
if ( V_101 )
return V_101 ;
if ( ! F_62 ( & V_4 -> V_2 ) )
F_29 ( V_4 -> V_13 , V_57 , V_61 , 0 ) ;
V_4 -> V_6 = 1 ;
V_101 = F_63 ( & V_108 -> V_5 , V_4 -> V_2 . V_7 , F_13 , 0 ,
F_64 ( & V_108 -> V_5 ) , & V_4 -> V_2 ) ;
if ( V_101 ) {
F_65 ( & V_96 , & V_4 -> V_2 ) ;
return V_101 ;
}
V_101 = F_63 ( & V_108 -> V_5 , V_4 -> V_120 , F_6 , 0 ,
F_64 ( & V_108 -> V_5 ) , & V_4 -> V_2 ) ;
if ( V_101 )
F_65 ( & V_96 , & V_4 -> V_2 ) ;
return V_101 ;
}
static int F_66 ( struct V_107 * V_108 )
{
struct V_3 * V_4 = F_67 ( V_108 ) ;
return F_65 ( & V_96 , & V_4 -> V_2 ) ;
}
static int T_4 F_68 ( void )
{
int V_101 ;
#ifdef F_69
V_96 . V_131 = & V_132 ;
V_132 . V_133 = & V_96 ;
#endif
V_101 = F_70 ( & V_96 ) ;
if ( V_101 )
return V_101 ;
return F_71 ( & V_134 ) ;
}
static void T_5 F_72 ( void )
{
F_73 ( & V_134 ) ;
F_74 ( & V_96 ) ;
}

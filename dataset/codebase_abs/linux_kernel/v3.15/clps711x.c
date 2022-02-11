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
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
unsigned int V_45 = 0 ;
if ( V_4 -> V_46 ) {
T_3 V_12 = 0 ;
F_7 ( V_4 -> V_13 , V_14 , & V_12 ) ;
if ( V_12 & V_47 )
V_45 |= V_48 ;
if ( V_12 & V_49 )
V_45 |= V_50 ;
if ( V_12 & V_51 )
V_45 |= V_52 ;
} else
V_45 = V_50 | V_52 | V_48 ;
return V_45 ;
}
static void F_22 ( struct V_1 * V_2 , unsigned int V_53 )
{
}
static void F_23 ( struct V_1 * V_2 , int V_54 )
{
unsigned int V_55 ;
V_55 = F_24 ( V_2 -> V_16 + V_56 ) ;
if ( V_54 )
V_55 |= V_57 ;
else
V_55 &= ~ V_57 ;
F_25 ( V_55 , V_2 -> V_16 + V_56 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_58 )
{
if ( ! V_2 -> line ) {
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
F_27 ( V_4 -> V_13 , V_59 , V_60 ,
( V_58 == V_61 ) ? V_60 : 0 ) ;
}
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
F_25 ( F_24 ( V_2 -> V_16 + V_56 ) & ~ V_57 ,
V_2 -> V_16 + V_56 ) ;
return F_27 ( V_4 -> V_13 , V_59 ,
V_62 , V_62 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
F_27 ( V_4 -> V_13 , V_59 , V_62 , 0 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_63 * V_64 ,
struct V_63 * V_65 )
{
T_3 V_55 ;
unsigned int V_66 , V_67 ;
V_64 -> V_68 &= ~ V_69 ;
V_64 -> V_70 &= ~ ( V_71 | V_72 ) ;
V_66 = F_31 ( V_2 , V_64 , V_65 , V_2 -> V_73 / 4096 ,
V_2 -> V_73 / 16 ) ;
V_67 = F_32 ( V_2 , V_66 ) ;
switch ( V_64 -> V_68 & V_74 ) {
case V_75 :
V_55 = V_76 ;
break;
case V_77 :
V_55 = V_78 ;
break;
case V_79 :
V_55 = V_80 ;
break;
case V_81 :
default:
V_55 = V_82 ;
break;
}
if ( V_64 -> V_68 & V_83 )
V_55 |= V_84 ;
if ( V_64 -> V_68 & V_85 ) {
V_55 |= V_86 ;
if ( ! ( V_64 -> V_68 & V_87 ) )
V_55 |= V_88 ;
}
V_55 |= V_89 ;
V_2 -> V_27 = V_20 ;
if ( V_64 -> V_70 & V_90 )
V_2 -> V_27 |= V_19 | V_18 ;
V_2 -> V_31 = 0 ;
if ( ! ( V_64 -> V_68 & V_91 ) )
V_2 -> V_31 |= V_20 | V_19 |
V_18 ;
F_33 ( V_2 , V_64 -> V_68 , V_66 ) ;
F_25 ( V_55 | ( V_67 - 1 ) , V_2 -> V_16 + V_56 ) ;
}
static const char * F_34 ( struct V_1 * V_2 )
{
return ( V_2 -> type == V_92 ) ? L_1 : NULL ;
}
static void F_35 ( struct V_1 * V_2 , int V_93 )
{
if ( V_93 & V_94 )
V_2 -> type = V_92 ;
}
static void F_36 ( struct V_1 * V_2 )
{
}
static int F_37 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
T_3 V_12 = 0 ;
do {
F_7 ( V_4 -> V_13 , V_14 , & V_12 ) ;
} while ( V_12 & V_41 );
F_14 ( V_11 , V_2 -> V_16 + V_17 ) ;
}
static void F_39 ( struct V_95 * V_96 , const char * V_97 ,
unsigned V_98 )
{
struct V_1 * V_2 = V_99 . V_32 [ V_96 -> V_100 ] . V_1 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
T_3 V_12 = 0 ;
F_40 ( V_2 , V_97 , V_98 , F_38 ) ;
do {
F_7 ( V_4 -> V_13 , V_14 , & V_12 ) ;
} while ( V_12 & V_43 );
}
static int F_41 ( struct V_95 * V_96 , char * V_101 )
{
int V_66 = 38400 , V_102 = 8 , V_24 = 'n' , V_103 = 'n' ;
int V_104 , V_100 = V_96 -> V_100 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
unsigned int V_67 ;
T_3 V_55 ;
if ( V_100 < 0 || V_100 >= V_105 )
return - V_106 ;
V_2 = V_99 . V_32 [ V_100 ] . V_1 ;
if ( ! V_2 )
return - V_107 ;
V_4 = F_2 ( V_2 -> V_5 ) ;
if ( ! V_101 ) {
T_3 V_13 = 0 ;
F_7 ( V_4 -> V_13 , V_59 , & V_13 ) ;
if ( V_13 & V_62 ) {
V_55 = F_24 ( V_2 -> V_16 + V_56 ) ;
if ( V_55 & V_86 ) {
if ( V_55 & V_88 )
V_24 = 'e' ;
else
V_24 = 'o' ;
}
if ( ( V_55 & V_108 ) == V_80 )
V_102 = 7 ;
V_67 = V_55 & V_109 ;
V_66 = V_2 -> V_73 / ( 16 * ( V_67 + 1 ) ) ;
}
} else
F_42 ( V_101 , & V_66 , & V_24 , & V_102 , & V_103 ) ;
V_104 = F_43 ( V_2 , V_96 , V_66 , V_24 , V_102 , V_103 ) ;
if ( V_104 )
return V_104 ;
return F_27 ( V_4 -> V_13 , V_59 ,
V_62 , V_62 ) ;
}
static int F_44 ( struct V_110 * V_111 )
{
struct V_112 * V_113 = V_111 -> V_5 . V_114 ;
int V_104 , V_100 = V_113 ? F_45 ( V_113 , L_2 ) : V_111 -> V_115 ;
struct V_3 * V_4 ;
struct V_116 * V_117 ;
struct V_118 * V_119 ;
if ( V_100 < 0 || V_100 >= V_105 )
return - V_106 ;
V_4 = F_46 ( & V_111 -> V_5 , sizeof( * V_4 ) , V_120 ) ;
if ( ! V_4 )
return - V_121 ;
V_119 = F_47 ( & V_111 -> V_5 , NULL ) ;
if ( F_48 ( V_119 ) )
return F_49 ( V_119 ) ;
V_117 = F_50 ( V_111 , V_122 , 0 ) ;
V_4 -> V_2 . V_16 = F_51 ( & V_111 -> V_5 , V_117 ) ;
if ( F_48 ( V_4 -> V_2 . V_16 ) )
return F_49 ( V_4 -> V_2 . V_16 ) ;
V_4 -> V_2 . V_7 = F_52 ( V_111 , 0 ) ;
if ( F_53 ( V_4 -> V_2 . V_7 ) )
return V_4 -> V_2 . V_7 ;
V_4 -> V_123 = F_52 ( V_111 , 1 ) ;
if ( F_53 ( V_4 -> V_123 ) )
return V_4 -> V_123 ;
if ( ! V_113 ) {
char V_124 [ 9 ] ;
sprintf ( V_124 , L_3 , V_100 + 1 ) ;
V_4 -> V_13 = F_54 ( V_124 ) ;
if ( F_48 ( V_4 -> V_13 ) )
return F_49 ( V_4 -> V_13 ) ;
V_4 -> V_46 = ! V_100 ;
} else {
V_4 -> V_13 = F_55 ( V_113 , L_4 ) ;
if ( F_48 ( V_4 -> V_13 ) )
return F_49 ( V_4 -> V_13 ) ;
if ( ! V_100 )
V_4 -> V_46 = F_56 ( V_113 , L_5 ) ;
}
V_4 -> V_2 . line = V_100 ;
V_4 -> V_2 . V_5 = & V_111 -> V_5 ;
V_4 -> V_2 . V_125 = V_126 ;
V_4 -> V_2 . V_127 = V_117 -> V_128 ;
V_4 -> V_2 . type = V_92 ;
V_4 -> V_2 . V_129 = 16 ;
V_4 -> V_2 . V_93 = V_130 | V_131 ;
V_4 -> V_2 . V_73 = F_57 ( V_119 ) ;
V_4 -> V_2 . V_132 = & V_133 ;
F_58 ( V_111 , V_4 ) ;
V_104 = F_59 ( & V_99 , & V_4 -> V_2 ) ;
if ( V_104 )
return V_104 ;
if ( ! F_60 ( & V_4 -> V_2 ) )
F_27 ( V_4 -> V_13 , V_59 , V_62 , 0 ) ;
V_4 -> V_6 = 1 ;
V_104 = F_61 ( & V_111 -> V_5 , V_4 -> V_2 . V_7 , F_13 , 0 ,
F_62 ( & V_111 -> V_5 ) , & V_4 -> V_2 ) ;
if ( V_104 ) {
F_63 ( & V_99 , & V_4 -> V_2 ) ;
return V_104 ;
}
V_104 = F_61 ( & V_111 -> V_5 , V_4 -> V_123 , F_6 , 0 ,
F_62 ( & V_111 -> V_5 ) , & V_4 -> V_2 ) ;
if ( V_104 )
F_63 ( & V_99 , & V_4 -> V_2 ) ;
return V_104 ;
}
static int F_64 ( struct V_110 * V_111 )
{
struct V_3 * V_4 = F_65 ( V_111 ) ;
return F_63 ( & V_99 , & V_4 -> V_2 ) ;
}
static int T_4 F_66 ( void )
{
int V_104 ;
#ifdef F_67
V_99 . V_134 = & V_135 ;
V_135 . V_136 = & V_99 ;
#endif
V_104 = F_68 ( & V_99 ) ;
if ( V_104 )
return V_104 ;
return F_69 ( & V_137 ) ;
}
static void T_5 F_70 ( void )
{
F_71 ( & V_137 ) ;
F_72 ( & V_99 ) ;
}

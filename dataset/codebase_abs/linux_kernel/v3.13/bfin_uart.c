static unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( V_4 -> V_5 < 0 )
return V_6 | V_7 | V_8 ;
if ( F_2 ( V_4 ) )
return V_6 | V_7 | V_8 ;
else
return V_7 | V_8 ;
}
static void F_3 ( struct V_1 * V_2 , unsigned int V_9 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( V_4 -> V_10 < 0 )
return;
if ( V_9 & V_11 )
F_4 ( V_4 ) ;
else
F_5 ( V_4 ) ;
}
static T_1 F_6 ( int V_12 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
unsigned int V_14 = F_1 ( & V_4 -> V_2 ) ;
#ifdef F_7
struct V_15 * V_16 = V_4 -> V_2 . V_17 -> V_2 . V_16 ;
F_8 ( V_4 ) ;
if ( V_16 -> V_18 ) {
if ( V_14 ) {
V_16 -> V_18 = 0 ;
F_9 ( & V_4 -> V_2 ) ;
}
} else {
if ( ! V_14 )
V_16 -> V_18 = 1 ;
}
#endif
F_10 ( & V_4 -> V_2 , V_14 & V_6 ) ;
return V_19 ;
}
static unsigned int F_1 ( struct V_1 * V_2 )
{
return V_6 | V_7 | V_8 ;
}
static void F_3 ( struct V_1 * V_2 , unsigned int V_9 )
{
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
#ifdef F_12
struct V_20 * V_21 = & V_4 -> V_2 . V_17 -> V_21 ;
#endif
while ( ! ( F_13 ( V_4 ) & V_22 ) )
F_14 () ;
#ifdef F_12
F_15 ( V_4 -> V_23 ) ;
V_21 -> V_24 = ( V_21 -> V_24 + V_4 -> V_25 ) & ( V_26 - 1 ) ;
V_4 -> V_2 . V_27 . V_28 += V_4 -> V_25 ;
V_4 -> V_25 = 0 ;
V_4 -> V_29 = 1 ;
#else
#if F_16 ( V_30 ) || F_16 ( V_31 )
F_17 ( V_4 , V_32 ) ;
#endif
F_18 ( V_4 , V_33 ) ;
#endif
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_15 * V_16 = V_4 -> V_2 . V_17 -> V_2 . V_16 ;
if ( V_16 -> V_34 . V_35 == V_36 )
F_20 ( V_2 ) ;
#ifdef F_12
if ( V_4 -> V_29 )
F_21 ( V_4 ) ;
#else
F_22 ( V_4 , V_33 ) ;
F_23 ( V_4 ) ;
#endif
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
F_18 ( V_4 , V_37 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
}
static void F_26 ( struct V_3 * V_4 )
{
unsigned int V_14 , V_38 , V_39 ;
static struct V_40 V_41 = { . V_42 = 0 } ;
V_14 = F_13 ( V_4 ) ;
F_27 ( V_4 ) ;
V_38 = F_28 ( V_4 ) ;
V_4 -> V_2 . V_27 . V_43 ++ ;
#if F_16 ( V_44 ) || \
F_16 ( V_45 )
if ( V_46 && V_47 == V_4 -> V_2 . line
&& V_48 )
if ( V_38 == 0x3 ) {
F_29 () ;
return;
}
if ( ! V_4 -> V_2 . V_17 )
return;
#endif
if ( V_49 ) {
if ( V_41 . V_42 ) {
struct V_40 V_50 ;
T_2 V_51 ;
if ( ( ~ V_38 & ( ~ V_38 + 1 ) ) & 0xff )
goto V_52;
F_30 ( & V_50 ) ;
if ( V_50 . V_42 - V_41 . V_42 > 1 )
goto V_52;
V_51 = 0 ;
if ( V_50 . V_42 != V_41 . V_42 )
V_51 += V_53 ;
V_51 += V_50 . V_54 - V_41 . V_54 ;
if ( V_51 > F_31 ( V_4 ) )
goto V_52;
if ( V_38 )
V_41 . V_42 = 0 ;
else
V_41 = V_50 ;
return;
V_52:
V_14 &= ~ V_55 ;
V_41 . V_42 = 0 ;
}
}
if ( V_14 & V_55 ) {
if ( V_49 )
if ( F_32 () < 5 )
F_30 ( & V_41 ) ;
V_4 -> V_2 . V_27 . V_56 ++ ;
if ( F_33 ( & V_4 -> V_2 ) )
goto V_57;
V_14 &= ~ ( V_58 | V_59 ) ;
}
if ( V_14 & V_58 )
V_4 -> V_2 . V_27 . V_60 ++ ;
if ( V_14 & V_61 )
V_4 -> V_2 . V_27 . V_62 ++ ;
if ( V_14 & V_59 )
V_4 -> V_2 . V_27 . V_63 ++ ;
V_14 &= V_4 -> V_2 . V_64 ;
if ( V_14 & V_55 )
V_39 = V_65 ;
else if ( V_14 & V_58 )
V_39 = V_66 ;
else if ( V_14 & V_59 )
V_39 = V_67 ;
else
V_39 = V_68 ;
if ( F_34 ( & V_4 -> V_2 , V_38 ) )
goto V_57;
F_35 ( & V_4 -> V_2 , V_14 , V_61 , V_38 , V_39 ) ;
V_57:
F_36 ( & V_4 -> V_2 . V_17 -> V_2 ) ;
}
static void F_23 ( struct V_3 * V_4 )
{
struct V_20 * V_21 = & V_4 -> V_2 . V_17 -> V_21 ;
if ( F_37 ( V_21 ) || F_38 ( & V_4 -> V_2 ) ) {
#if F_16 ( V_30 ) || F_16 ( V_31 )
F_17 ( V_4 , V_32 ) ;
#endif
F_18 ( V_4 , V_33 ) ;
return;
}
if ( V_4 -> V_2 . V_69 ) {
F_39 ( V_4 , V_4 -> V_2 . V_69 ) ;
V_4 -> V_2 . V_27 . V_28 ++ ;
V_4 -> V_2 . V_69 = 0 ;
}
while ( ( F_13 ( V_4 ) & V_70 ) && V_21 -> V_24 != V_21 -> V_71 ) {
F_39 ( V_4 , V_21 -> V_72 [ V_21 -> V_24 ] ) ;
V_21 -> V_24 = ( V_21 -> V_24 + 1 ) & ( V_26 - 1 ) ;
V_4 -> V_2 . V_27 . V_28 ++ ;
}
if ( F_40 ( V_21 ) < V_73 )
F_9 ( & V_4 -> V_2 ) ;
}
static T_1 F_41 ( int V_12 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
while ( F_13 ( V_4 ) & V_74 )
F_26 ( V_4 ) ;
return V_19 ;
}
static T_1 F_42 ( int V_12 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
F_43 ( & V_4 -> V_2 . V_75 ) ;
if ( F_13 ( V_4 ) & V_70 )
F_23 ( V_4 ) ;
F_44 ( & V_4 -> V_2 . V_75 ) ;
return V_19 ;
}
static void F_21 ( struct V_3 * V_4 )
{
struct V_20 * V_21 = & V_4 -> V_2 . V_17 -> V_21 ;
V_4 -> V_29 = 0 ;
if ( F_37 ( V_21 ) || F_38 ( & V_4 -> V_2 ) ) {
V_4 -> V_25 = 0 ;
V_4 -> V_29 = 1 ;
return;
}
if ( V_4 -> V_2 . V_69 ) {
F_39 ( V_4 , V_4 -> V_2 . V_69 ) ;
V_4 -> V_2 . V_27 . V_28 ++ ;
V_4 -> V_2 . V_69 = 0 ;
}
V_4 -> V_25 = F_45 ( V_21 -> V_71 , V_21 -> V_24 , V_26 ) ;
if ( V_4 -> V_25 > ( V_26 - V_21 -> V_24 ) )
V_4 -> V_25 = V_26 - V_21 -> V_24 ;
F_46 ( ( unsigned long ) ( V_21 -> V_72 + V_21 -> V_24 ) ,
( unsigned long ) ( V_21 -> V_72 + V_21 -> V_24 + V_4 -> V_25 ) ) ;
F_47 ( V_4 -> V_23 ,
F_48 ( V_76 , V_77 ,
V_78 ,
V_79 ,
V_80 ,
V_81 ) ) ;
F_49 ( V_4 -> V_23 , ( unsigned long ) ( V_21 -> V_72 + V_21 -> V_24 ) ) ;
F_50 ( V_4 -> V_23 , V_4 -> V_25 ) ;
F_51 ( V_4 -> V_23 , 1 ) ;
F_52 () ;
F_53 ( V_4 -> V_23 ) ;
F_22 ( V_4 , V_33 ) ;
}
static void F_54 ( struct V_3 * V_4 )
{
int V_82 , V_39 , V_14 ;
V_14 = F_13 ( V_4 ) ;
F_27 ( V_4 ) ;
V_4 -> V_2 . V_27 . V_43 +=
F_45 ( V_4 -> V_83 . V_71 , V_4 -> V_83 . V_24 ,
V_26 ) ;
if ( V_14 & V_55 ) {
V_4 -> V_2 . V_27 . V_56 ++ ;
if ( F_33 ( & V_4 -> V_2 ) )
goto V_84;
V_14 &= ~ ( V_58 | V_59 ) ;
}
if ( V_14 & V_58 )
V_4 -> V_2 . V_27 . V_60 ++ ;
if ( V_14 & V_61 )
V_4 -> V_2 . V_27 . V_62 ++ ;
if ( V_14 & V_59 )
V_4 -> V_2 . V_27 . V_63 ++ ;
V_14 &= V_4 -> V_2 . V_64 ;
if ( V_14 & V_55 )
V_39 = V_65 ;
else if ( V_14 & V_58 )
V_39 = V_66 ;
else if ( V_14 & V_59 )
V_39 = V_67 ;
else
V_39 = V_68 ;
for ( V_82 = V_4 -> V_83 . V_24 ; ; V_82 ++ ) {
if ( V_82 >= V_26 )
V_82 = 0 ;
if ( V_82 == V_4 -> V_83 . V_71 )
break;
if ( ! F_34 ( & V_4 -> V_2 , V_4 -> V_83 . V_72 [ V_82 ] ) )
F_35 ( & V_4 -> V_2 , V_14 , V_61 ,
V_4 -> V_83 . V_72 [ V_82 ] , V_39 ) ;
}
V_84:
F_36 ( & V_4 -> V_2 . V_17 -> V_2 ) ;
}
void F_55 ( struct V_3 * V_4 )
{
int V_85 , V_86 ;
unsigned long V_87 ;
F_56 ( & V_4 -> V_88 , V_87 ) ;
V_4 -> V_89 = F_57 ( V_4 -> V_90 ) ;
V_85 = F_58 ( V_4 -> V_90 ) ;
V_4 -> V_89 = V_91 - V_4 -> V_89 ;
if ( V_4 -> V_89 == V_91 || V_85 == 0 )
V_4 -> V_89 = 0 ;
V_85 = V_92 - V_85 ;
if ( V_85 == V_92 )
V_85 = 0 ;
V_86 = V_4 -> V_89 * V_92 + V_85 ;
if ( V_86 > V_4 -> V_83 . V_24 ||
V_4 -> V_89 < ( V_4 -> V_83 . V_24 / V_92 ) ) {
V_4 -> V_83 . V_71 = V_86 ;
F_54 ( V_4 ) ;
V_4 -> V_83 . V_24 = V_4 -> V_83 . V_71 ;
}
F_59 ( & V_4 -> V_88 , V_87 ) ;
F_60 ( & ( V_4 -> V_93 ) , V_94 + V_95 ) ;
}
static T_1 F_61 ( int V_12 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
struct V_20 * V_21 = & V_4 -> V_2 . V_17 -> V_21 ;
F_43 ( & V_4 -> V_2 . V_75 ) ;
if ( ! ( F_62 ( V_4 -> V_23 ) & V_96 ) ) {
F_15 ( V_4 -> V_23 ) ;
F_63 ( V_4 -> V_23 ) ;
F_18 ( V_4 , V_33 ) ;
V_4 -> V_2 . V_27 . V_28 += V_4 -> V_25 ;
if ( ! ( V_21 -> V_24 == 0 && V_21 -> V_71 == 0 ) ) {
V_21 -> V_24 = ( V_21 -> V_24 + V_4 -> V_25 ) & ( V_26 - 1 ) ;
if ( F_40 ( V_21 ) < V_73 )
F_9 ( & V_4 -> V_2 ) ;
}
F_21 ( V_4 ) ;
}
F_44 ( & V_4 -> V_2 . V_75 ) ;
return V_19 ;
}
static T_1 F_64 ( int V_12 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
unsigned int V_97 ;
int V_85 , V_86 ;
F_43 ( & V_4 -> V_88 ) ;
V_97 = F_62 ( V_4 -> V_90 ) ;
F_63 ( V_4 -> V_90 ) ;
V_4 -> V_89 = F_57 ( V_4 -> V_90 ) ;
V_85 = F_58 ( V_4 -> V_90 ) ;
V_4 -> V_89 = V_91 - V_4 -> V_89 ;
if ( V_4 -> V_89 == V_91 || V_85 == 0 )
V_4 -> V_89 = 0 ;
V_86 = V_4 -> V_89 * V_92 ;
if ( V_86 > V_4 -> V_83 . V_24 ||
V_4 -> V_89 < ( V_4 -> V_83 . V_24 / V_92 ) ) {
V_4 -> V_83 . V_71 = V_86 ;
F_54 ( V_4 ) ;
V_4 -> V_83 . V_24 = V_4 -> V_83 . V_71 ;
}
F_44 ( & V_4 -> V_88 ) ;
return V_19 ;
}
static unsigned int F_65 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_98 ;
V_98 = F_13 ( V_4 ) ;
if ( V_98 & V_22 )
return V_99 ;
else
return 0 ;
}
static void F_66 ( struct V_1 * V_2 , int V_100 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
T_3 V_101 = F_67 ( V_4 ) ;
if ( V_100 )
V_101 |= V_102 ;
else
V_101 &= ~ V_102 ;
F_68 ( V_4 , V_101 ) ;
F_52 () ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
#ifdef F_12
T_4 V_103 ;
if ( F_70 ( V_4 -> V_90 , L_1 ) < 0 ) {
F_71 ( V_104 L_2 ) ;
return - V_105 ;
}
if ( F_70 ( V_4 -> V_23 , L_3 ) < 0 ) {
F_71 ( V_104 L_4 ) ;
F_72 ( V_4 -> V_90 ) ;
return - V_105 ;
}
F_73 ( V_4 -> V_90 , F_64 , V_4 ) ;
F_73 ( V_4 -> V_23 , F_61 , V_4 ) ;
V_4 -> V_83 . V_72 = ( unsigned char * ) F_74 ( NULL , V_106 , & V_103 , V_107 ) ;
V_4 -> V_83 . V_71 = 0 ;
V_4 -> V_83 . V_24 = 0 ;
V_4 -> V_89 = 0 ;
F_47 ( V_4 -> V_90 ,
F_48 ( V_108 , V_109 ,
V_110 , V_111 ,
V_80 ,
V_81 ) ) ;
F_50 ( V_4 -> V_90 , V_92 ) ;
F_51 ( V_4 -> V_90 , 1 ) ;
F_75 ( V_4 -> V_90 , V_91 ) ;
F_76 ( V_4 -> V_90 , 1 ) ;
F_49 ( V_4 -> V_90 , ( unsigned long ) V_4 -> V_83 . V_72 ) ;
F_53 ( V_4 -> V_90 ) ;
V_4 -> V_93 . V_112 = ( unsigned long ) ( V_4 ) ;
V_4 -> V_93 . V_113 = ( void * ) F_55 ;
V_4 -> V_93 . V_114 = V_94 + V_95 ;
F_77 ( & ( V_4 -> V_93 ) ) ;
#else
# if F_16 ( V_44 ) || \
F_16 ( V_45 )
if ( V_47 == V_4 -> V_2 . line && V_48 )
V_48 = 0 ;
else {
# endif
if ( F_78 ( V_4 -> V_115 , F_41 , 0 ,
L_1 , V_4 ) ) {
F_71 ( V_104 L_5 ) ;
return - V_105 ;
}
if ( F_78
( V_4 -> V_116 , F_42 , 0 ,
L_3 , V_4 ) ) {
F_71 ( V_104 L_6 ) ;
F_79 ( V_4 -> V_115 , V_4 ) ;
return - V_105 ;
}
# ifdef V_30
{
unsigned V_117 , V_118 ;
switch ( V_4 -> V_115 ) {
case V_119 :
V_117 = V_120 ;
V_118 = V_121 ;
break;
case V_122 :
V_117 = V_123 ;
V_118 = V_124 ;
break;
default:
V_117 = V_118 = 0 ;
break;
}
if ( V_117 &&
F_70 ( V_117 , L_1 ) < 0 ) {
F_71 ( V_104 L_7 ) ;
F_79 ( V_4 -> V_115 , V_4 ) ;
F_79 ( V_4 -> V_116 , V_4 ) ;
return - V_105 ;
}
if ( V_118 &&
F_70 ( V_118 , L_3 ) < 0 ) {
F_71 ( V_104 L_7 ) ;
F_72 ( V_117 ) ;
F_79 ( V_4 -> V_115 , V_4 ) ;
F_79 ( V_4 -> V_116 , V_4 ) ;
return - V_105 ;
}
}
# endif
# if F_16 ( V_44 ) || \
F_16 ( V_45 )
}
# endif
#endif
#ifdef F_80
if ( V_4 -> V_5 >= 0 ) {
if ( F_78 ( F_81 ( V_4 -> V_5 ) ,
F_6 ,
V_125 | V_126 |
0 , L_8 , V_4 ) ) {
V_4 -> V_5 = - 1 ;
F_82 ( L_9 ) ;
}
}
if ( V_4 -> V_10 >= 0 ) {
if ( F_83 ( V_4 -> V_10 , V_127 ) ) {
F_82 ( L_10 , V_4 -> V_10 ) ;
V_4 -> V_10 = - 1 ;
} else
F_84 ( V_4 -> V_10 , 0 ) ;
}
#endif
#ifdef F_7
if ( V_4 -> V_5 >= 0 ) {
if ( F_78 ( V_4 -> V_128 , F_6 ,
0 , L_11 , V_4 ) ) {
V_4 -> V_5 = - 1 ;
F_85 ( V_2 -> V_129 , L_12 ) ;
}
F_86 ( V_4 , F_87 ( V_4 ) | V_130 ) ;
F_22 ( V_4 , V_131 ) ;
}
#endif
F_22 ( V_4 , V_37 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
#ifdef F_12
F_15 ( V_4 -> V_23 ) ;
F_72 ( V_4 -> V_23 ) ;
F_15 ( V_4 -> V_90 ) ;
F_72 ( V_4 -> V_90 ) ;
F_89 ( & ( V_4 -> V_93 ) ) ;
F_90 ( NULL , V_106 , V_4 -> V_83 . V_72 , 0 ) ;
#else
#ifdef V_30
switch ( V_4 -> V_2 . V_12 ) {
case V_119 :
F_72 ( V_120 ) ;
F_72 ( V_121 ) ;
break;
case V_122 :
F_72 ( V_123 ) ;
F_72 ( V_124 ) ;
break;
default:
break;
}
#endif
F_79 ( V_4 -> V_115 , V_4 ) ;
F_79 ( V_4 -> V_116 , V_4 ) ;
#endif
#ifdef F_80
if ( V_4 -> V_5 >= 0 )
F_79 ( F_81 ( V_4 -> V_5 ) , V_4 ) ;
if ( V_4 -> V_10 >= 0 )
F_91 ( V_4 -> V_10 ) ;
#endif
#ifdef F_7
if ( V_4 -> V_5 >= 0 )
F_79 ( V_4 -> V_128 , V_4 ) ;
#endif
}
static void
F_92 ( struct V_1 * V_2 , struct V_132 * V_34 ,
struct V_132 * V_133 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned long V_87 ;
unsigned int V_134 , V_135 ;
unsigned int V_136 , V_101 = 0 ;
unsigned long V_137 ;
switch ( V_34 -> V_138 & V_139 ) {
case V_140 :
V_101 = F_93 ( 8 ) ;
break;
case V_141 :
V_101 = F_93 ( 7 ) ;
break;
case V_142 :
V_101 = F_93 ( 6 ) ;
break;
case V_143 :
V_101 = F_93 ( 5 ) ;
break;
default:
F_71 ( V_144 L_13 ,
V_145 ) ;
}
if ( V_34 -> V_138 & V_146 ) {
if ( V_147 )
F_71 ( V_148 L_14
L_15 ) ;
else
V_101 |= V_149 ;
}
if ( V_34 -> V_138 & V_150 )
V_101 |= V_151 ;
if ( ! ( V_34 -> V_138 & V_152 ) )
V_101 |= V_153 ;
if ( V_34 -> V_138 & V_154 )
V_101 |= V_155 ;
F_56 ( & V_4 -> V_2 . V_75 , V_87 ) ;
V_2 -> V_64 = V_61 ;
if ( V_34 -> V_156 & V_157 )
V_2 -> V_64 |= ( V_59 | V_58 ) ;
if ( V_34 -> V_156 & ( V_158 | V_159 ) )
V_2 -> V_64 |= V_55 ;
V_2 -> V_160 = 0 ;
if ( V_34 -> V_156 & V_161 )
V_2 -> V_160 |= V_59 | V_58 ;
if ( V_34 -> V_156 & V_162 ) {
V_2 -> V_160 |= V_55 ;
if ( V_34 -> V_156 & V_161 )
V_2 -> V_160 |= V_61 ;
}
V_134 = F_94 ( V_2 , V_34 , V_133 , 0 , V_2 -> V_163 / 16 ) ;
V_135 = F_95 ( V_2 , V_134 ) ;
if ( V_34 -> V_35 != V_36 )
V_135 -= V_164 ;
F_96 ( V_4 , V_53 / V_134 * 15 ) ;
V_137 = V_94 + F_97 ( 10 ) ;
while ( F_98 ( V_4 ) & V_165 && ! ( F_13 ( V_4 ) & V_22 ) )
if ( F_99 ( V_94 , V_137 ) ) {
F_100 ( V_2 -> V_129 , L_16 ) ;
break;
}
V_136 = F_101 ( V_4 ) ;
F_102 ( V_4 , F_98 ( V_4 ) & ~ V_165 ) ;
F_103 ( V_4 ) ;
F_104 ( V_4 ) ;
F_105 ( V_4 , V_135 ) ;
F_52 () ;
F_106 ( V_4 ) ;
F_68 ( V_4 , ( F_67 ( V_4 ) & ~ V_166 ) | V_101 ) ;
F_107 ( V_4 , V_136 ) ;
F_102 ( V_4 , F_98 ( V_4 ) | V_165 ) ;
F_108 ( V_2 , V_34 -> V_138 , V_134 ) ;
F_59 ( & V_4 -> V_2 . V_75 , V_87 ) ;
}
static const char * F_109 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
return V_4 -> V_2 . type == V_167 ? L_17 : NULL ;
}
static void F_110 ( struct V_1 * V_2 )
{
}
static int F_111 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_112 ( struct V_1 * V_2 , int V_87 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( V_87 & V_168 &&
F_111 ( & V_4 -> V_2 ) == 0 )
V_4 -> V_2 . type = V_167 ;
}
static int
F_113 ( struct V_1 * V_2 , struct V_169 * V_170 )
{
return 0 ;
}
static void F_114 ( struct V_1 * V_2 , int V_171 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_172 ;
switch ( V_171 ) {
case V_36 :
V_172 = F_98 ( V_4 ) ;
V_172 |= ( V_173 | V_174 ) ;
F_102 ( V_4 , V_172 ) ;
break;
default:
V_172 = F_98 ( V_4 ) ;
V_172 &= ~ ( V_175 | V_174 ) ;
F_102 ( V_4 , V_172 ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_172 ;
V_172 = F_98 ( V_4 ) ;
V_172 &= ~ ( V_175 | V_174 ) ;
F_102 ( V_4 , V_172 ) ;
F_52 () ;
V_172 |= ( V_173 | V_174 ) ;
F_102 ( V_4 , V_172 ) ;
F_52 () ;
}
static void F_115 ( struct V_1 * V_2 , unsigned char V_176 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
while ( ! ( F_13 ( V_4 ) & V_70 ) )
F_14 () ;
F_106 ( V_4 ) ;
F_39 ( V_4 , ( unsigned char ) V_176 ) ;
}
static int F_116 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned char V_176 ;
while ( ! ( F_13 ( V_4 ) & V_74 ) )
F_14 () ;
F_106 ( V_4 ) ;
V_176 = F_28 ( V_4 ) ;
return V_176 ;
}
static void T_5
F_117 ( struct V_3 * V_4 , int * V_134 ,
int * V_60 , int * V_177 )
{
unsigned int V_14 ;
V_14 = F_101 ( V_4 ) & ( V_37 | V_33 ) ;
if ( V_14 == ( V_37 | V_33 ) ) {
T_3 V_101 , V_178 ;
V_101 = F_67 ( V_4 ) ;
* V_60 = 'n' ;
if ( V_101 & V_151 ) {
if ( V_101 & V_153 )
* V_60 = 'e' ;
else
* V_60 = 'o' ;
}
* V_177 = ( ( V_101 & V_179 ) >> V_180 ) + 5 ;
F_104 ( V_4 ) ;
V_178 = F_118 ( V_4 ) ;
F_106 ( V_4 ) ;
* V_134 = F_119 () / ( 16 * V_178 ) ;
}
F_120 ( L_18 , V_145 , * V_134 , * V_60 , * V_177 ) ;
}
static void F_121 ( struct V_1 * V_2 , int V_38 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
while ( ! ( F_13 ( V_4 ) & V_70 ) )
F_122 () ;
F_39 ( V_4 , V_38 ) ;
}
static void
F_123 ( struct V_181 * V_182 , const char * V_183 , unsigned int V_184 )
{
struct V_3 * V_4 = V_185 [ V_182 -> V_186 ] ;
unsigned long V_87 ;
F_56 ( & V_4 -> V_2 . V_75 , V_87 ) ;
F_124 ( & V_4 -> V_2 , V_183 , V_184 , F_121 ) ;
F_59 ( & V_4 -> V_2 . V_75 , V_87 ) ;
}
static int T_5
F_125 ( struct V_181 * V_182 , char * V_187 )
{
struct V_3 * V_4 ;
int V_134 = 57600 ;
int V_177 = 8 ;
int V_60 = 'n' ;
# if F_16 ( F_80 ) || \
F_16 ( F_7 )
int V_188 = 'r' ;
# else
int V_188 = 'n' ;
# endif
if ( V_182 -> V_186 < 0 || V_182 -> V_186 >= V_189 )
return - V_190 ;
V_4 = V_185 [ V_182 -> V_186 ] ;
if ( ! V_4 )
return - V_190 ;
if ( V_187 )
F_126 ( V_187 , & V_134 , & V_60 , & V_177 , & V_188 ) ;
else
F_117 ( V_4 , & V_134 , & V_60 , & V_177 ) ;
return F_127 ( & V_4 -> V_2 , V_182 , V_134 , V_60 , V_177 , V_188 ) ;
}
static void
F_128 ( struct V_181 * V_182 , const char * V_183 , unsigned int V_184 )
{
unsigned long V_87 ;
if ( V_191 . V_2 . line != V_182 -> V_186 )
return;
F_56 ( & V_191 . V_2 . V_75 , V_87 ) ;
F_124 ( & V_191 . V_2 , V_183 , V_184 ,
F_121 ) ;
F_59 ( & V_191 . V_2 . V_75 , V_87 ) ;
}
static int F_129 ( struct V_192 * V_193 , T_6 V_17 )
{
struct V_3 * V_4 = F_130 ( V_193 ) ;
return F_131 ( & V_194 , & V_4 -> V_2 ) ;
}
static int F_132 ( struct V_192 * V_193 )
{
struct V_3 * V_4 = F_130 ( V_193 ) ;
return F_133 ( & V_194 , & V_4 -> V_2 ) ;
}
static int F_134 ( struct V_192 * V_193 )
{
struct V_195 * V_196 ;
struct V_3 * V_4 = NULL ;
int V_197 = 0 ;
if ( V_193 -> V_198 < 0 || V_193 -> V_198 >= V_189 ) {
F_135 ( & V_193 -> V_129 , L_19 ) ;
return - V_199 ;
}
if ( V_185 [ V_193 -> V_198 ] == NULL ) {
V_4 = F_136 ( sizeof( * V_4 ) , V_200 ) ;
if ( ! V_4 ) {
F_135 ( & V_193 -> V_129 ,
L_20 ) ;
return - V_201 ;
}
V_185 [ V_193 -> V_198 ] = V_4 ;
#ifdef F_137
if ( ! ( V_191 . V_2 . V_202
&& V_191 . V_2 . line == V_193 -> V_198 ) ) {
#endif
V_197 = F_138 (
F_139 ( & V_193 -> V_129 ) ,
V_127 ) ;
if ( V_197 ) {
F_135 ( & V_193 -> V_129 ,
L_21 ) ;
goto V_203;
}
#ifdef F_137
}
#endif
F_140 ( & V_4 -> V_2 . V_75 ) ;
V_4 -> V_2 . V_163 = F_119 () ;
V_4 -> V_2 . V_204 = V_205 ;
V_4 -> V_2 . V_206 = & V_207 ;
V_4 -> V_2 . line = V_193 -> V_198 ;
V_4 -> V_2 . V_208 = V_209 ;
V_4 -> V_2 . V_87 = V_210 ;
V_196 = F_141 ( V_193 , V_211 , 0 ) ;
if ( V_196 == NULL ) {
F_135 ( & V_193 -> V_129 , L_22 ) ;
V_197 = - V_199 ;
goto V_212;
}
V_4 -> V_2 . V_202 = F_142 ( V_196 -> V_213 , F_143 ( V_196 ) ) ;
if ( ! V_4 -> V_2 . V_202 ) {
F_135 ( & V_193 -> V_129 , L_23 ) ;
V_197 = - V_214 ;
goto V_212;
}
V_4 -> V_2 . V_215 = V_196 -> V_213 ;
V_4 -> V_116 = F_144 ( V_193 , 0 ) ;
if ( V_4 -> V_116 < 0 ) {
F_135 ( & V_193 -> V_129 , L_24 ) ;
V_197 = - V_199 ;
goto V_216;
}
V_4 -> V_115 = F_144 ( V_193 , 1 ) ;
if ( V_4 -> V_115 < 0 ) {
F_135 ( & V_193 -> V_129 , L_25 ) ;
V_197 = - V_199 ;
goto V_216;
}
V_4 -> V_2 . V_12 = V_4 -> V_115 ;
V_4 -> V_128 = F_144 ( V_193 , 2 ) ;
if ( V_4 -> V_128 < 0 ) {
F_135 ( & V_193 -> V_129 , L_26 ) ;
V_197 = - V_199 ;
goto V_216;
}
#ifdef F_12
F_140 ( & V_4 -> V_88 ) ;
V_4 -> V_29 = 1 ;
V_4 -> V_25 = 0 ;
V_196 = F_141 ( V_193 , V_217 , 0 ) ;
if ( V_196 == NULL ) {
F_135 ( & V_193 -> V_129 , L_27 ) ;
V_197 = - V_199 ;
goto V_216;
}
V_4 -> V_23 = V_196 -> V_213 ;
V_196 = F_141 ( V_193 , V_217 , 1 ) ;
if ( V_196 == NULL ) {
F_135 ( & V_193 -> V_129 , L_28 ) ;
V_197 = - V_199 ;
goto V_216;
}
V_4 -> V_90 = V_196 -> V_213 ;
F_145 ( & ( V_4 -> V_93 ) ) ;
#endif
#if F_16 ( F_80 ) || \
F_16 ( F_7 )
V_196 = F_141 ( V_193 , V_218 , 0 ) ;
if ( V_196 == NULL )
V_4 -> V_5 = - 1 ;
else {
V_4 -> V_5 = V_196 -> V_213 ;
#ifdef F_80
V_4 -> V_2 . V_87 |= V_219 ;
#endif
}
V_196 = F_141 ( V_193 , V_218 , 1 ) ;
if ( V_196 == NULL )
V_4 -> V_10 = - 1 ;
else
V_4 -> V_10 = V_196 -> V_213 ;
#endif
}
#ifdef F_146
if ( ! F_147 ( V_193 ) ) {
#endif
V_4 = V_185 [ V_193 -> V_198 ] ;
V_4 -> V_2 . V_129 = & V_193 -> V_129 ;
F_148 ( & V_193 -> V_129 , V_4 ) ;
V_197 = F_149 ( & V_194 , & V_4 -> V_2 ) ;
#ifdef F_146
}
#endif
if ( ! V_197 )
return 0 ;
if ( V_4 ) {
V_216:
F_150 ( V_4 -> V_2 . V_202 ) ;
V_212:
F_151 ( F_139 ( & V_193 -> V_129 ) ) ;
V_203:
F_152 ( V_4 ) ;
V_185 [ V_193 -> V_198 ] = NULL ;
}
return V_197 ;
}
static int F_153 ( struct V_192 * V_193 )
{
struct V_3 * V_4 = F_130 ( V_193 ) ;
F_148 ( & V_193 -> V_129 , NULL ) ;
if ( V_4 ) {
F_154 ( & V_194 , & V_4 -> V_2 ) ;
F_150 ( V_4 -> V_2 . V_202 ) ;
F_151 ( F_139 ( & V_193 -> V_129 ) ) ;
F_152 ( V_4 ) ;
V_185 [ V_193 -> V_198 ] = NULL ;
}
return 0 ;
}
static int T_5 F_155 ( void )
{
F_156 ( & V_220 , V_127 ) ;
F_157 ( V_221 , V_189 , 0 ) ;
F_158 ( & V_222 ) ;
return 0 ;
}
static int F_159 ( struct V_192 * V_193 )
{
struct V_195 * V_196 ;
int V_197 ;
if ( V_193 -> V_198 < 0 || V_193 -> V_198 >= V_189 ) {
F_135 ( & V_193 -> V_129 , L_29 ) ;
return - V_199 ;
}
V_197 = F_138 ( F_139 ( & V_193 -> V_129 ) ,
V_127 ) ;
if ( V_197 ) {
F_135 ( & V_193 -> V_129 ,
L_21 ) ;
return V_197 ;
}
V_196 = F_141 ( V_193 , V_211 , 0 ) ;
if ( V_196 == NULL ) {
F_135 ( & V_193 -> V_129 , L_22 ) ;
V_197 = - V_199 ;
goto V_212;
}
V_191 . V_2 . V_202 = F_142 ( V_196 -> V_213 ,
F_143 ( V_196 ) ) ;
if ( ! V_191 . V_2 . V_202 ) {
F_135 ( & V_193 -> V_129 , L_23 ) ;
V_197 = - V_214 ;
goto V_212;
}
V_191 . V_2 . V_215 = V_196 -> V_213 ;
V_191 . V_2 . line = V_193 -> V_198 ;
V_191 . V_2 . V_163 = F_119 () ;
V_191 . V_2 . V_204 = V_205 ;
F_140 ( & V_191 . V_2 . V_75 ) ;
return 0 ;
V_212:
F_151 ( F_139 ( & V_193 -> V_129 ) ) ;
return V_197 ;
}
struct V_181 T_5 * F_160 ( unsigned int V_2 ,
unsigned int V_223 )
{
struct V_132 V_224 ;
char V_225 [ 20 ] ;
if ( V_2 < 0 || V_2 >= V_189 )
return NULL ;
snprintf ( V_225 , 20 , V_127 L_30 , V_2 ) ;
F_156 ( & V_226 ,
V_225 ) ;
F_157 ( V_227 , 1 , 0 ) ;
if ( ! V_191 . V_2 . V_202 )
return NULL ;
#ifdef F_146
V_222 . V_87 &= ~ V_228 ;
#endif
V_229 . V_186 = V_2 ;
V_224 . V_138 = V_223 ;
V_224 . V_156 = 0 ;
V_224 . V_230 = 0 ;
V_224 . V_231 = V_232 ;
V_224 . V_35 = V_2 ;
F_92 ( & V_191 . V_2 , & V_224 , & V_224 ) ;
return & V_229 ;
}
static int T_5 F_161 ( void )
{
int V_197 ;
F_82 ( L_31 ) ;
V_197 = F_162 ( & V_194 ) ;
if ( V_197 ) {
F_163 ( L_32 ,
V_194 . V_233 , V_197 ) ;
}
V_197 = F_164 ( & V_234 ) ;
if ( V_197 ) {
F_163 ( L_33 ) ;
F_165 ( & V_194 ) ;
}
return V_197 ;
}
static void T_7 F_166 ( void )
{
F_167 ( & V_234 ) ;
F_165 ( & V_194 ) ;
}

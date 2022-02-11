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
} ;
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
V_129 , L_11 , V_4 ) ) {
V_4 -> V_5 = - 1 ;
F_85 ( V_2 -> V_130 , L_12 ) ;
}
F_86 ( V_4 , F_87 ( V_4 ) | V_131 ) ;
F_22 ( V_4 , V_132 ) ;
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
} ;
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
F_92 ( struct V_1 * V_2 , struct V_133 * V_34 ,
struct V_133 * V_134 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned long V_87 ;
unsigned int V_135 , V_136 ;
unsigned int V_137 , V_101 = 0 ;
unsigned long V_138 ;
switch ( V_34 -> V_139 & V_140 ) {
case V_141 :
V_101 = F_93 ( 8 ) ;
break;
case V_142 :
V_101 = F_93 ( 7 ) ;
break;
case V_143 :
V_101 = F_93 ( 6 ) ;
break;
case V_144 :
V_101 = F_93 ( 5 ) ;
break;
default:
F_71 ( V_145 L_13 ,
V_146 ) ;
}
if ( V_34 -> V_139 & V_147 ) {
if ( V_148 )
F_71 ( V_149 L_14
L_15 ) ;
else
V_101 |= V_150 ;
}
if ( V_34 -> V_139 & V_151 )
V_101 |= V_152 ;
if ( ! ( V_34 -> V_139 & V_153 ) )
V_101 |= V_154 ;
if ( V_34 -> V_139 & V_155 )
V_101 |= V_156 ;
F_56 ( & V_4 -> V_2 . V_75 , V_87 ) ;
V_2 -> V_64 = V_61 ;
if ( V_34 -> V_157 & V_158 )
V_2 -> V_64 |= ( V_59 | V_58 ) ;
if ( V_34 -> V_157 & ( V_159 | V_160 ) )
V_2 -> V_64 |= V_55 ;
V_2 -> V_161 = 0 ;
if ( V_34 -> V_157 & V_162 )
V_2 -> V_161 |= V_59 | V_58 ;
if ( V_34 -> V_157 & V_163 ) {
V_2 -> V_161 |= V_55 ;
if ( V_34 -> V_157 & V_162 )
V_2 -> V_161 |= V_61 ;
}
V_135 = F_94 ( V_2 , V_34 , V_134 , 0 , V_2 -> V_164 / 16 ) ;
V_136 = F_95 ( V_2 , V_135 ) ;
if ( V_34 -> V_35 != V_36 )
V_136 -= V_165 ;
F_96 ( V_4 , V_53 / V_135 * 15 ) ;
V_138 = V_94 + F_97 ( 10 ) ;
while ( F_98 ( V_4 ) & V_166 && ! ( F_13 ( V_4 ) & V_22 ) )
if ( F_99 ( V_94 , V_138 ) ) {
F_100 ( V_2 -> V_130 , L_16 ) ;
break;
}
V_137 = F_101 ( V_4 ) ;
F_102 ( V_4 , F_98 ( V_4 ) & ~ V_166 ) ;
F_103 ( V_4 ) ;
F_104 ( V_4 ) ;
F_105 ( V_4 , V_136 ) ;
F_52 () ;
F_106 ( V_4 ) ;
F_68 ( V_4 , ( F_67 ( V_4 ) & ~ V_167 ) | V_101 ) ;
F_107 ( V_4 , V_137 ) ;
F_102 ( V_4 , F_98 ( V_4 ) | V_166 ) ;
F_108 ( V_2 , V_34 -> V_139 , V_135 ) ;
F_59 ( & V_4 -> V_2 . V_75 , V_87 ) ;
}
static const char * F_109 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
return V_4 -> V_2 . type == V_168 ? L_17 : NULL ;
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
if ( V_87 & V_169 &&
F_111 ( & V_4 -> V_2 ) == 0 )
V_4 -> V_2 . type = V_168 ;
}
static int
F_113 ( struct V_1 * V_2 , struct V_170 * V_171 )
{
return 0 ;
}
static void F_114 ( struct V_1 * V_2 , int V_172 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_173 ;
switch ( V_172 ) {
case V_36 :
V_173 = F_98 ( V_4 ) ;
V_173 |= ( V_174 | V_175 ) ;
F_102 ( V_4 , V_173 ) ;
break;
default:
V_173 = F_98 ( V_4 ) ;
V_173 &= ~ ( V_176 | V_175 ) ;
F_102 ( V_4 , V_173 ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_173 ;
V_173 = F_98 ( V_4 ) ;
V_173 &= ~ ( V_176 | V_175 ) ;
F_102 ( V_4 , V_173 ) ;
F_52 () ;
V_173 |= ( V_174 | V_175 ) ;
F_102 ( V_4 , V_173 ) ;
F_52 () ;
}
static void F_115 ( struct V_1 * V_2 , unsigned char V_177 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
while ( ! ( F_13 ( V_4 ) & V_70 ) )
F_14 () ;
F_106 ( V_4 ) ;
F_39 ( V_4 , ( unsigned char ) V_177 ) ;
}
static int F_116 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned char V_177 ;
while ( ! ( F_13 ( V_4 ) & V_74 ) )
F_14 () ;
F_106 ( V_4 ) ;
V_177 = F_28 ( V_4 ) ;
return V_177 ;
}
static void T_5
F_117 ( struct V_3 * V_4 , int * V_135 ,
int * V_60 , int * V_178 )
{
unsigned int V_14 ;
V_14 = F_101 ( V_4 ) & ( V_37 | V_33 ) ;
if ( V_14 == ( V_37 | V_33 ) ) {
T_3 V_101 , V_179 ;
V_101 = F_67 ( V_4 ) ;
* V_60 = 'n' ;
if ( V_101 & V_152 ) {
if ( V_101 & V_154 )
* V_60 = 'e' ;
else
* V_60 = 'o' ;
}
* V_178 = ( ( V_101 & V_180 ) >> V_181 ) + 5 ;
F_104 ( V_4 ) ;
V_179 = F_118 ( V_4 ) ;
F_106 ( V_4 ) ;
* V_135 = F_119 () / ( 16 * V_179 ) ;
}
F_120 ( L_18 , V_146 , * V_135 , * V_60 , * V_178 ) ;
}
static void F_121 ( struct V_1 * V_2 , int V_38 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
while ( ! ( F_13 ( V_4 ) & V_70 ) )
F_122 () ;
F_39 ( V_4 , V_38 ) ;
}
static void
F_123 ( struct V_182 * V_183 , const char * V_184 , unsigned int V_185 )
{
struct V_3 * V_4 = V_186 [ V_183 -> V_187 ] ;
unsigned long V_87 ;
F_56 ( & V_4 -> V_2 . V_75 , V_87 ) ;
F_124 ( & V_4 -> V_2 , V_184 , V_185 , F_121 ) ;
F_59 ( & V_4 -> V_2 . V_75 , V_87 ) ;
}
static int T_5
F_125 ( struct V_182 * V_183 , char * V_188 )
{
struct V_3 * V_4 ;
int V_135 = 57600 ;
int V_178 = 8 ;
int V_60 = 'n' ;
# if F_16 ( F_80 ) || \
F_16 ( F_7 )
int V_189 = 'r' ;
# else
int V_189 = 'n' ;
# endif
if ( V_183 -> V_187 < 0 || V_183 -> V_187 >= V_190 )
return - V_191 ;
V_4 = V_186 [ V_183 -> V_187 ] ;
if ( ! V_4 )
return - V_191 ;
if ( V_188 )
F_126 ( V_188 , & V_135 , & V_60 , & V_178 , & V_189 ) ;
else
F_117 ( V_4 , & V_135 , & V_60 , & V_178 ) ;
return F_127 ( & V_4 -> V_2 , V_183 , V_135 , V_60 , V_178 , V_189 ) ;
}
static void
F_128 ( struct V_182 * V_183 , const char * V_184 , unsigned int V_185 )
{
unsigned long V_87 ;
if ( V_192 . V_2 . line != V_183 -> V_187 )
return;
F_56 ( & V_192 . V_2 . V_75 , V_87 ) ;
F_124 ( & V_192 . V_2 , V_184 , V_185 ,
F_121 ) ;
F_59 ( & V_192 . V_2 . V_75 , V_87 ) ;
}
static int F_129 ( struct V_193 * V_194 , T_6 V_17 )
{
struct V_3 * V_4 = F_130 ( V_194 ) ;
return F_131 ( & V_195 , & V_4 -> V_2 ) ;
}
static int F_132 ( struct V_193 * V_194 )
{
struct V_3 * V_4 = F_130 ( V_194 ) ;
return F_133 ( & V_195 , & V_4 -> V_2 ) ;
}
static int F_134 ( struct V_193 * V_194 )
{
struct V_196 * V_197 ;
struct V_3 * V_4 = NULL ;
int V_198 = 0 ;
if ( V_194 -> V_199 < 0 || V_194 -> V_199 >= V_190 ) {
F_135 ( & V_194 -> V_130 , L_19 ) ;
return - V_200 ;
}
if ( V_186 [ V_194 -> V_199 ] == NULL ) {
V_4 = F_136 ( sizeof( * V_4 ) , V_201 ) ;
if ( ! V_4 ) {
F_135 ( & V_194 -> V_130 ,
L_20 ) ;
return - V_202 ;
}
V_186 [ V_194 -> V_199 ] = V_4 ;
#ifdef F_137
if ( ! ( V_192 . V_2 . V_203
&& V_192 . V_2 . line == V_194 -> V_199 ) ) {
#endif
V_198 = F_138 (
( unsigned short * ) V_194 -> V_130 . V_204 , V_127 ) ;
if ( V_198 ) {
F_135 ( & V_194 -> V_130 ,
L_21 ) ;
goto V_205;
}
#ifdef F_137
}
#endif
F_139 ( & V_4 -> V_2 . V_75 ) ;
V_4 -> V_2 . V_164 = F_119 () ;
V_4 -> V_2 . V_206 = V_207 ;
V_4 -> V_2 . V_208 = & V_209 ;
V_4 -> V_2 . line = V_194 -> V_199 ;
V_4 -> V_2 . V_210 = V_211 ;
V_4 -> V_2 . V_87 = V_212 ;
V_197 = F_140 ( V_194 , V_213 , 0 ) ;
if ( V_197 == NULL ) {
F_135 ( & V_194 -> V_130 , L_22 ) ;
V_198 = - V_200 ;
goto V_214;
}
V_4 -> V_2 . V_203 = F_141 ( V_197 -> V_215 , F_142 ( V_197 ) ) ;
if ( ! V_4 -> V_2 . V_203 ) {
F_135 ( & V_194 -> V_130 , L_23 ) ;
V_198 = - V_216 ;
goto V_214;
}
V_4 -> V_2 . V_217 = V_197 -> V_215 ;
V_4 -> V_116 = F_143 ( V_194 , 0 ) ;
if ( V_4 -> V_116 < 0 ) {
F_135 ( & V_194 -> V_130 , L_24 ) ;
V_198 = - V_200 ;
goto V_218;
}
V_4 -> V_115 = F_143 ( V_194 , 1 ) ;
if ( V_4 -> V_115 < 0 ) {
F_135 ( & V_194 -> V_130 , L_25 ) ;
V_198 = - V_200 ;
goto V_218;
}
V_4 -> V_2 . V_12 = V_4 -> V_115 ;
V_4 -> V_128 = F_143 ( V_194 , 2 ) ;
if ( V_4 -> V_128 < 0 ) {
F_135 ( & V_194 -> V_130 , L_26 ) ;
V_198 = - V_200 ;
goto V_218;
}
#ifdef F_12
F_139 ( & V_4 -> V_88 ) ;
V_4 -> V_29 = 1 ;
V_4 -> V_25 = 0 ;
V_197 = F_140 ( V_194 , V_219 , 0 ) ;
if ( V_197 == NULL ) {
F_135 ( & V_194 -> V_130 , L_27 ) ;
V_198 = - V_200 ;
goto V_218;
}
V_4 -> V_23 = V_197 -> V_215 ;
V_197 = F_140 ( V_194 , V_219 , 1 ) ;
if ( V_197 == NULL ) {
F_135 ( & V_194 -> V_130 , L_28 ) ;
V_198 = - V_200 ;
goto V_218;
}
V_4 -> V_90 = V_197 -> V_215 ;
F_144 ( & ( V_4 -> V_93 ) ) ;
#endif
#if F_16 ( F_80 ) || \
F_16 ( F_7 )
V_197 = F_140 ( V_194 , V_220 , 0 ) ;
if ( V_197 == NULL )
V_4 -> V_5 = - 1 ;
else {
V_4 -> V_5 = V_197 -> V_215 ;
#ifdef F_80
V_4 -> V_2 . V_87 |= V_221 ;
#endif
}
V_197 = F_140 ( V_194 , V_220 , 1 ) ;
if ( V_197 == NULL )
V_4 -> V_10 = - 1 ;
else
V_4 -> V_10 = V_197 -> V_215 ;
#endif
}
#ifdef F_145
if ( ! F_146 ( V_194 ) ) {
#endif
V_4 = V_186 [ V_194 -> V_199 ] ;
V_4 -> V_2 . V_130 = & V_194 -> V_130 ;
F_147 ( & V_194 -> V_130 , V_4 ) ;
V_198 = F_148 ( & V_195 , & V_4 -> V_2 ) ;
#ifdef F_145
}
#endif
if ( ! V_198 )
return 0 ;
if ( V_4 ) {
V_218:
F_149 ( V_4 -> V_2 . V_203 ) ;
V_214:
F_150 (
( unsigned short * ) V_194 -> V_130 . V_204 ) ;
V_205:
F_151 ( V_4 ) ;
V_186 [ V_194 -> V_199 ] = NULL ;
}
return V_198 ;
}
static int F_152 ( struct V_193 * V_194 )
{
struct V_3 * V_4 = F_130 ( V_194 ) ;
F_147 ( & V_194 -> V_130 , NULL ) ;
if ( V_4 ) {
F_153 ( & V_195 , & V_4 -> V_2 ) ;
F_149 ( V_4 -> V_2 . V_203 ) ;
F_150 (
( unsigned short * ) V_194 -> V_130 . V_204 ) ;
F_151 ( V_4 ) ;
V_186 [ V_194 -> V_199 ] = NULL ;
}
return 0 ;
}
static int T_5 F_154 ( void )
{
F_155 ( & V_222 , V_127 ) ;
F_156 ( V_223 , V_190 , 0 ) ;
F_157 ( & V_224 ) ;
return 0 ;
}
static int F_158 ( struct V_193 * V_194 )
{
struct V_196 * V_197 ;
int V_198 ;
if ( V_194 -> V_199 < 0 || V_194 -> V_199 >= V_190 ) {
F_135 ( & V_194 -> V_130 , L_29 ) ;
return - V_200 ;
}
V_198 = F_138 (
( unsigned short * ) V_194 -> V_130 . V_204 , V_127 ) ;
if ( V_198 ) {
F_135 ( & V_194 -> V_130 ,
L_21 ) ;
return V_198 ;
}
V_197 = F_140 ( V_194 , V_213 , 0 ) ;
if ( V_197 == NULL ) {
F_135 ( & V_194 -> V_130 , L_22 ) ;
V_198 = - V_200 ;
goto V_214;
}
V_192 . V_2 . V_203 = F_141 ( V_197 -> V_215 ,
F_142 ( V_197 ) ) ;
if ( ! V_192 . V_2 . V_203 ) {
F_135 ( & V_194 -> V_130 , L_23 ) ;
V_198 = - V_216 ;
goto V_214;
}
V_192 . V_2 . V_217 = V_197 -> V_215 ;
V_192 . V_2 . line = V_194 -> V_199 ;
V_192 . V_2 . V_164 = F_119 () ;
V_192 . V_2 . V_206 = V_207 ;
F_139 ( & V_192 . V_2 . V_75 ) ;
return 0 ;
V_214:
F_150 (
( unsigned short * ) V_194 -> V_130 . V_204 ) ;
return V_198 ;
}
struct V_182 T_5 * F_159 ( unsigned int V_2 ,
unsigned int V_225 )
{
struct V_133 V_226 ;
char V_227 [ 20 ] ;
if ( V_2 < 0 || V_2 >= V_190 )
return NULL ;
snprintf ( V_227 , 20 , V_127 L_30 , V_2 ) ;
F_155 ( & V_228 ,
V_227 ) ;
F_156 ( V_229 , 1 , 0 ) ;
if ( ! V_192 . V_2 . V_203 )
return NULL ;
#ifdef F_145
V_224 . V_87 &= ~ V_230 ;
#endif
V_231 . V_187 = V_2 ;
V_226 . V_139 = V_225 ;
V_226 . V_157 = 0 ;
V_226 . V_232 = 0 ;
V_226 . V_233 = V_234 ;
V_226 . V_35 = V_2 ;
F_92 ( & V_192 . V_2 , & V_226 , & V_226 ) ;
return & V_231 ;
}
static int T_5 F_160 ( void )
{
int V_198 ;
F_82 ( L_31 ) ;
V_198 = F_161 ( & V_195 ) ;
if ( V_198 ) {
F_162 ( L_32 ,
V_195 . V_235 , V_198 ) ;
}
V_198 = F_163 ( & V_236 ) ;
if ( V_198 ) {
F_162 ( L_33 ) ;
F_164 ( & V_195 ) ;
}
return V_198 ;
}
static void T_7 F_165 ( void )
{
F_166 ( & V_236 ) ;
F_164 ( & V_195 ) ;
}

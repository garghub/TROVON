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
struct V_1 * V_14 = & V_4 -> V_2 ;
unsigned int V_15 = F_1 ( V_14 ) ;
#ifdef F_7
F_8 ( V_4 ) ;
if ( V_14 -> V_16 ) {
if ( V_15 ) {
V_14 -> V_16 = 0 ;
F_9 ( V_14 ) ;
}
} else {
if ( ! V_15 )
V_14 -> V_16 = 1 ;
}
#else
F_10 ( V_14 , V_15 & V_6 ) ;
#endif
return V_17 ;
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
struct V_18 * V_19 = & V_4 -> V_2 . V_20 -> V_19 ;
#endif
while ( ! ( F_13 ( V_4 ) & V_21 ) )
F_14 () ;
#ifdef F_12
F_15 ( V_4 -> V_22 ) ;
V_19 -> V_23 = ( V_19 -> V_23 + V_4 -> V_24 ) & ( V_25 - 1 ) ;
V_4 -> V_2 . V_26 . V_27 += V_4 -> V_24 ;
V_4 -> V_24 = 0 ;
V_4 -> V_28 = 1 ;
#else
#if F_16 ( V_29 ) || F_16 ( V_30 )
F_17 ( V_4 , V_31 ) ;
#endif
F_18 ( V_4 , V_32 ) ;
#endif
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_33 * V_34 = V_4 -> V_2 . V_20 -> V_2 . V_34 ;
if ( V_34 -> V_35 . V_36 == V_37 )
F_20 ( V_2 ) ;
#ifdef F_12
if ( V_4 -> V_28 )
F_21 ( V_4 ) ;
#else
F_22 ( V_4 , V_32 ) ;
F_23 ( V_4 ) ;
#endif
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
F_18 ( V_4 , V_38 ) ;
}
static void F_25 ( struct V_3 * V_4 )
{
unsigned int V_15 , V_39 , V_40 ;
static struct V_41 V_42 = { . V_43 = 0 } ;
V_15 = F_13 ( V_4 ) ;
F_26 ( V_4 ) ;
V_39 = F_27 ( V_4 ) ;
V_4 -> V_2 . V_26 . V_44 ++ ;
#if F_16 ( V_45 ) || \
F_16 ( V_46 )
if ( V_47 && V_48 == V_4 -> V_2 . line
&& V_49 )
if ( V_39 == 0x3 ) {
F_28 () ;
return;
}
if ( ! V_4 -> V_2 . V_20 )
return;
#endif
if ( V_50 ) {
if ( V_42 . V_43 ) {
struct V_41 V_51 ;
T_2 V_52 ;
if ( ( ~ V_39 & ( ~ V_39 + 1 ) ) & 0xff )
goto V_53;
F_29 ( & V_51 ) ;
if ( V_51 . V_43 - V_42 . V_43 > 1 )
goto V_53;
V_52 = 0 ;
if ( V_51 . V_43 != V_42 . V_43 )
V_52 += V_54 ;
V_52 += V_51 . V_55 - V_42 . V_55 ;
if ( V_52 > F_30 ( V_4 ) )
goto V_53;
if ( V_39 )
V_42 . V_43 = 0 ;
else
V_42 = V_51 ;
return;
V_53:
V_15 &= ~ V_56 ;
V_42 . V_43 = 0 ;
}
}
if ( V_15 & V_56 ) {
if ( V_50 )
if ( F_31 () < 5 )
F_29 ( & V_42 ) ;
V_4 -> V_2 . V_26 . V_57 ++ ;
if ( F_32 ( & V_4 -> V_2 ) )
goto V_58;
V_15 &= ~ ( V_59 | V_60 ) ;
}
if ( V_15 & V_59 )
V_4 -> V_2 . V_26 . V_61 ++ ;
if ( V_15 & V_62 )
V_4 -> V_2 . V_26 . V_63 ++ ;
if ( V_15 & V_60 )
V_4 -> V_2 . V_26 . V_64 ++ ;
V_15 &= V_4 -> V_2 . V_65 ;
if ( V_15 & V_56 )
V_40 = V_66 ;
else if ( V_15 & V_59 )
V_40 = V_67 ;
else if ( V_15 & V_60 )
V_40 = V_68 ;
else
V_40 = V_69 ;
if ( F_33 ( & V_4 -> V_2 , V_39 ) )
goto V_58;
F_34 ( & V_4 -> V_2 , V_15 , V_62 , V_39 , V_40 ) ;
V_58:
F_35 ( & V_4 -> V_2 . V_20 -> V_2 ) ;
}
static void F_23 ( struct V_3 * V_4 )
{
struct V_18 * V_19 = & V_4 -> V_2 . V_20 -> V_19 ;
if ( F_36 ( V_19 ) || F_37 ( & V_4 -> V_2 ) ) {
#if F_16 ( V_29 ) || F_16 ( V_30 )
F_17 ( V_4 , V_31 ) ;
#endif
F_18 ( V_4 , V_32 ) ;
return;
}
if ( V_4 -> V_2 . V_70 ) {
F_38 ( V_4 , V_4 -> V_2 . V_70 ) ;
V_4 -> V_2 . V_26 . V_27 ++ ;
V_4 -> V_2 . V_70 = 0 ;
}
while ( ( F_13 ( V_4 ) & V_71 ) && V_19 -> V_23 != V_19 -> V_72 ) {
F_38 ( V_4 , V_19 -> V_73 [ V_19 -> V_23 ] ) ;
V_19 -> V_23 = ( V_19 -> V_23 + 1 ) & ( V_25 - 1 ) ;
V_4 -> V_2 . V_26 . V_27 ++ ;
}
if ( F_39 ( V_19 ) < V_74 )
F_9 ( & V_4 -> V_2 ) ;
}
static T_1 F_40 ( int V_12 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
while ( F_13 ( V_4 ) & V_75 )
F_25 ( V_4 ) ;
return V_17 ;
}
static T_1 F_41 ( int V_12 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
F_42 ( & V_4 -> V_2 . V_76 ) ;
if ( F_13 ( V_4 ) & V_71 )
F_23 ( V_4 ) ;
F_43 ( & V_4 -> V_2 . V_76 ) ;
return V_17 ;
}
static void F_21 ( struct V_3 * V_4 )
{
struct V_18 * V_19 = & V_4 -> V_2 . V_20 -> V_19 ;
V_4 -> V_28 = 0 ;
if ( F_36 ( V_19 ) || F_37 ( & V_4 -> V_2 ) ) {
V_4 -> V_24 = 0 ;
V_4 -> V_28 = 1 ;
return;
}
if ( V_4 -> V_2 . V_70 ) {
F_38 ( V_4 , V_4 -> V_2 . V_70 ) ;
V_4 -> V_2 . V_26 . V_27 ++ ;
V_4 -> V_2 . V_70 = 0 ;
}
V_4 -> V_24 = F_44 ( V_19 -> V_72 , V_19 -> V_23 , V_25 ) ;
if ( V_4 -> V_24 > ( V_25 - V_19 -> V_23 ) )
V_4 -> V_24 = V_25 - V_19 -> V_23 ;
F_45 ( ( unsigned long ) ( V_19 -> V_73 + V_19 -> V_23 ) ,
( unsigned long ) ( V_19 -> V_73 + V_19 -> V_23 + V_4 -> V_24 ) ) ;
F_46 ( V_4 -> V_22 ,
F_47 ( V_77 , V_78 ,
V_79 ,
V_80 ,
V_81 ,
V_82 ) ) ;
F_48 ( V_4 -> V_22 , ( unsigned long ) ( V_19 -> V_73 + V_19 -> V_23 ) ) ;
F_49 ( V_4 -> V_22 , V_4 -> V_24 ) ;
F_50 ( V_4 -> V_22 , 1 ) ;
F_51 () ;
F_52 ( V_4 -> V_22 ) ;
F_22 ( V_4 , V_32 ) ;
}
static void F_53 ( struct V_3 * V_4 )
{
int V_83 , V_40 , V_15 ;
V_15 = F_13 ( V_4 ) ;
F_26 ( V_4 ) ;
V_4 -> V_2 . V_26 . V_44 +=
F_44 ( V_4 -> V_84 . V_72 , V_4 -> V_84 . V_23 ,
V_25 ) ;
if ( V_15 & V_56 ) {
V_4 -> V_2 . V_26 . V_57 ++ ;
if ( F_32 ( & V_4 -> V_2 ) )
goto V_85;
V_15 &= ~ ( V_59 | V_60 ) ;
}
if ( V_15 & V_59 )
V_4 -> V_2 . V_26 . V_61 ++ ;
if ( V_15 & V_62 )
V_4 -> V_2 . V_26 . V_63 ++ ;
if ( V_15 & V_60 )
V_4 -> V_2 . V_26 . V_64 ++ ;
V_15 &= V_4 -> V_2 . V_65 ;
if ( V_15 & V_56 )
V_40 = V_66 ;
else if ( V_15 & V_59 )
V_40 = V_67 ;
else if ( V_15 & V_60 )
V_40 = V_68 ;
else
V_40 = V_69 ;
for ( V_83 = V_4 -> V_84 . V_23 ; ; V_83 ++ ) {
if ( V_83 >= V_25 )
V_83 = 0 ;
if ( V_83 == V_4 -> V_84 . V_72 )
break;
if ( ! F_33 ( & V_4 -> V_2 , V_4 -> V_84 . V_73 [ V_83 ] ) )
F_34 ( & V_4 -> V_2 , V_15 , V_62 ,
V_4 -> V_84 . V_73 [ V_83 ] , V_40 ) ;
}
V_85:
F_35 ( & V_4 -> V_2 . V_20 -> V_2 ) ;
}
void F_54 ( struct V_3 * V_4 )
{
int V_86 , V_87 ;
unsigned long V_88 ;
F_55 ( & V_4 -> V_89 , V_88 ) ;
V_4 -> V_90 = F_56 ( V_4 -> V_91 ) ;
V_86 = F_57 ( V_4 -> V_91 ) ;
V_4 -> V_90 = V_92 - V_4 -> V_90 ;
if ( V_4 -> V_90 == V_92 || V_86 == 0 )
V_4 -> V_90 = 0 ;
V_86 = V_93 - V_86 ;
if ( V_86 == V_93 )
V_86 = 0 ;
V_87 = V_4 -> V_90 * V_93 + V_86 ;
if ( V_87 > V_4 -> V_84 . V_23 ||
V_4 -> V_90 < ( V_4 -> V_84 . V_23 / V_93 ) ) {
V_4 -> V_84 . V_72 = V_87 ;
F_53 ( V_4 ) ;
V_4 -> V_84 . V_23 = V_4 -> V_84 . V_72 ;
}
F_58 ( & V_4 -> V_89 , V_88 ) ;
F_59 ( & ( V_4 -> V_94 ) , V_95 + V_96 ) ;
}
static T_1 F_60 ( int V_12 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
struct V_18 * V_19 = & V_4 -> V_2 . V_20 -> V_19 ;
F_42 ( & V_4 -> V_2 . V_76 ) ;
if ( ! ( F_61 ( V_4 -> V_22 ) & V_97 ) ) {
F_15 ( V_4 -> V_22 ) ;
F_62 ( V_4 -> V_22 ) ;
F_18 ( V_4 , V_32 ) ;
V_4 -> V_2 . V_26 . V_27 += V_4 -> V_24 ;
if ( ! ( V_19 -> V_23 == 0 && V_19 -> V_72 == 0 ) ) {
V_19 -> V_23 = ( V_19 -> V_23 + V_4 -> V_24 ) & ( V_25 - 1 ) ;
if ( F_39 ( V_19 ) < V_74 )
F_9 ( & V_4 -> V_2 ) ;
}
F_21 ( V_4 ) ;
}
F_43 ( & V_4 -> V_2 . V_76 ) ;
return V_17 ;
}
static T_1 F_63 ( int V_12 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
unsigned int V_98 ;
int V_86 , V_87 ;
F_42 ( & V_4 -> V_89 ) ;
V_98 = F_61 ( V_4 -> V_91 ) ;
F_62 ( V_4 -> V_91 ) ;
V_4 -> V_90 = F_56 ( V_4 -> V_91 ) ;
V_86 = F_57 ( V_4 -> V_91 ) ;
V_4 -> V_90 = V_92 - V_4 -> V_90 ;
if ( V_4 -> V_90 == V_92 || V_86 == 0 )
V_4 -> V_90 = 0 ;
V_87 = V_4 -> V_90 * V_93 ;
if ( V_87 > V_4 -> V_84 . V_23 ||
V_4 -> V_90 < ( V_4 -> V_84 . V_23 / V_93 ) ) {
V_4 -> V_84 . V_72 = V_87 ;
F_53 ( V_4 ) ;
V_4 -> V_84 . V_23 = V_4 -> V_84 . V_72 ;
}
F_43 ( & V_4 -> V_89 ) ;
return V_17 ;
}
static unsigned int F_64 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_99 ;
V_99 = F_13 ( V_4 ) ;
if ( V_99 & V_21 )
return V_100 ;
else
return 0 ;
}
static void F_65 ( struct V_1 * V_2 , int V_101 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
T_3 V_102 = F_66 ( V_4 ) ;
if ( V_101 )
V_102 |= V_103 ;
else
V_102 &= ~ V_103 ;
F_67 ( V_4 , V_102 ) ;
F_51 () ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
#ifdef F_12
T_4 V_104 ;
if ( F_69 ( V_4 -> V_91 , L_1 ) < 0 ) {
F_70 ( V_105 L_2 ) ;
return - V_106 ;
}
if ( F_69 ( V_4 -> V_22 , L_3 ) < 0 ) {
F_70 ( V_105 L_4 ) ;
F_71 ( V_4 -> V_91 ) ;
return - V_106 ;
}
F_72 ( V_4 -> V_91 , F_63 , V_4 ) ;
F_72 ( V_4 -> V_22 , F_60 , V_4 ) ;
V_4 -> V_84 . V_73 = ( unsigned char * ) F_73 ( NULL , V_107 , & V_104 , V_108 ) ;
V_4 -> V_84 . V_72 = 0 ;
V_4 -> V_84 . V_23 = 0 ;
V_4 -> V_90 = 0 ;
F_46 ( V_4 -> V_91 ,
F_47 ( V_109 , V_110 ,
V_111 , V_112 ,
V_81 ,
V_82 ) ) ;
F_49 ( V_4 -> V_91 , V_93 ) ;
F_50 ( V_4 -> V_91 , 1 ) ;
F_74 ( V_4 -> V_91 , V_92 ) ;
F_75 ( V_4 -> V_91 , 1 ) ;
F_48 ( V_4 -> V_91 , ( unsigned long ) V_4 -> V_84 . V_73 ) ;
F_52 ( V_4 -> V_91 ) ;
V_4 -> V_94 . V_113 = ( unsigned long ) ( V_4 ) ;
V_4 -> V_94 . V_114 = ( void * ) F_54 ;
V_4 -> V_94 . V_115 = V_95 + V_96 ;
F_76 ( & ( V_4 -> V_94 ) ) ;
#else
# if F_16 ( V_45 ) || \
F_16 ( V_46 )
if ( V_48 == V_4 -> V_2 . line && V_49 )
V_49 = 0 ;
else {
# endif
if ( F_77 ( V_4 -> V_116 , F_40 , 0 ,
L_1 , V_4 ) ) {
F_70 ( V_105 L_5 ) ;
return - V_106 ;
}
if ( F_77
( V_4 -> V_117 , F_41 , 0 ,
L_3 , V_4 ) ) {
F_70 ( V_105 L_6 ) ;
F_78 ( V_4 -> V_116 , V_4 ) ;
return - V_106 ;
}
# ifdef V_29
{
unsigned V_118 , V_119 ;
switch ( V_4 -> V_116 ) {
case V_120 :
V_118 = V_121 ;
V_119 = V_122 ;
break;
case V_123 :
V_118 = V_124 ;
V_119 = V_125 ;
break;
default:
V_118 = V_119 = 0 ;
break;
}
if ( V_118 &&
F_69 ( V_118 , L_1 ) < 0 ) {
F_70 ( V_105 L_7 ) ;
F_78 ( V_4 -> V_116 , V_4 ) ;
F_78 ( V_4 -> V_117 , V_4 ) ;
return - V_106 ;
}
if ( V_119 &&
F_69 ( V_119 , L_3 ) < 0 ) {
F_70 ( V_105 L_7 ) ;
F_71 ( V_118 ) ;
F_78 ( V_4 -> V_116 , V_4 ) ;
F_78 ( V_4 -> V_117 , V_4 ) ;
return - V_106 ;
}
}
# endif
# if F_16 ( V_45 ) || \
F_16 ( V_46 )
}
# endif
#endif
#ifdef F_79
if ( V_4 -> V_5 >= 0 ) {
if ( F_77 ( F_80 ( V_4 -> V_5 ) ,
F_6 ,
V_126 | V_127 |
0 , L_8 , V_4 ) ) {
V_4 -> V_5 = - 1 ;
F_81 ( L_9 ) ;
}
}
if ( V_4 -> V_10 >= 0 ) {
if ( F_82 ( V_4 -> V_10 , V_128 ) ) {
F_81 ( L_10 , V_4 -> V_10 ) ;
V_4 -> V_10 = - 1 ;
} else
F_83 ( V_4 -> V_10 , 0 ) ;
}
#endif
#ifdef F_7
if ( V_4 -> V_5 >= 0 ) {
if ( F_77 ( V_4 -> V_129 , F_6 ,
0 , L_11 , V_4 ) ) {
V_4 -> V_5 = - 1 ;
F_84 ( V_2 -> V_130 , L_12 ) ;
}
F_85 ( V_4 , F_86 ( V_4 ) | V_131 ) ;
F_22 ( V_4 , V_132 ) ;
}
#endif
F_22 ( V_4 , V_38 ) ;
return 0 ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
#ifdef F_12
F_15 ( V_4 -> V_22 ) ;
F_71 ( V_4 -> V_22 ) ;
F_15 ( V_4 -> V_91 ) ;
F_71 ( V_4 -> V_91 ) ;
F_88 ( & ( V_4 -> V_94 ) ) ;
F_89 ( NULL , V_107 , V_4 -> V_84 . V_73 , 0 ) ;
#else
#ifdef V_29
switch ( V_4 -> V_2 . V_12 ) {
case V_120 :
F_71 ( V_121 ) ;
F_71 ( V_122 ) ;
break;
case V_123 :
F_71 ( V_124 ) ;
F_71 ( V_125 ) ;
break;
default:
break;
}
#endif
F_78 ( V_4 -> V_116 , V_4 ) ;
F_78 ( V_4 -> V_117 , V_4 ) ;
#endif
#ifdef F_79
if ( V_4 -> V_5 >= 0 )
F_78 ( F_80 ( V_4 -> V_5 ) , V_4 ) ;
if ( V_4 -> V_10 >= 0 )
F_90 ( V_4 -> V_10 ) ;
#endif
#ifdef F_7
if ( V_4 -> V_5 >= 0 )
F_78 ( V_4 -> V_129 , V_4 ) ;
#endif
}
static void
F_91 ( struct V_1 * V_2 , struct V_133 * V_35 ,
struct V_133 * V_134 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned long V_88 ;
unsigned int V_135 , V_136 ;
unsigned int V_137 , V_102 = 0 ;
unsigned long V_138 ;
#ifdef F_79
if ( V_134 == NULL && V_4 -> V_5 != - 1 )
V_35 -> V_139 |= V_140 ;
else if ( V_4 -> V_5 == - 1 )
V_35 -> V_139 &= ~ V_140 ;
#endif
switch ( V_35 -> V_139 & V_141 ) {
case V_142 :
V_102 = F_92 ( 8 ) ;
break;
case V_143 :
V_102 = F_92 ( 7 ) ;
break;
case V_144 :
V_102 = F_92 ( 6 ) ;
break;
case V_145 :
V_102 = F_92 ( 5 ) ;
break;
default:
F_70 ( V_146 L_13 ,
V_147 ) ;
}
if ( V_35 -> V_139 & V_148 ) {
if ( V_149 )
F_70 ( V_150 L_14
L_15 ) ;
else
V_102 |= V_151 ;
}
if ( V_35 -> V_139 & V_152 )
V_102 |= V_153 ;
if ( ! ( V_35 -> V_139 & V_154 ) )
V_102 |= V_155 ;
if ( V_35 -> V_139 & V_156 )
V_102 |= V_157 ;
F_55 ( & V_4 -> V_2 . V_76 , V_88 ) ;
V_2 -> V_65 = V_62 ;
if ( V_35 -> V_158 & V_159 )
V_2 -> V_65 |= ( V_60 | V_59 ) ;
if ( V_35 -> V_158 & ( V_160 | V_161 | V_162 ) )
V_2 -> V_65 |= V_56 ;
V_2 -> V_163 = 0 ;
if ( V_35 -> V_158 & V_164 )
V_2 -> V_163 |= V_60 | V_59 ;
if ( V_35 -> V_158 & V_160 ) {
V_2 -> V_163 |= V_56 ;
if ( V_35 -> V_158 & V_164 )
V_2 -> V_163 |= V_62 ;
}
V_135 = F_93 ( V_2 , V_35 , V_134 , 0 , V_2 -> V_165 / 16 ) ;
V_136 = F_94 ( V_2 , V_135 ) ;
if ( V_35 -> V_36 != V_37 )
V_136 -= V_166 ;
F_95 ( V_4 , V_54 / V_135 * 15 ) ;
V_138 = V_95 + F_96 ( 10 ) ;
while ( F_97 ( V_4 ) & V_167 && ! ( F_13 ( V_4 ) & V_21 ) )
if ( F_98 ( V_95 , V_138 ) ) {
F_99 ( V_2 -> V_130 , L_16 ) ;
break;
}
V_137 = F_100 ( V_4 ) ;
F_101 ( V_4 , F_97 ( V_4 ) & ~ V_167 ) ;
F_102 ( V_4 ) ;
F_103 ( V_4 ) ;
F_104 ( V_4 , V_136 ) ;
F_51 () ;
F_105 ( V_4 ) ;
F_67 ( V_4 , ( F_66 ( V_4 ) & ~ V_168 ) | V_102 ) ;
F_106 ( V_4 , V_137 ) ;
F_101 ( V_4 , F_97 ( V_4 ) | V_167 ) ;
F_107 ( V_2 , V_35 -> V_139 , V_135 ) ;
F_58 ( & V_4 -> V_2 . V_76 , V_88 ) ;
}
static const char * F_108 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
return V_4 -> V_2 . type == V_169 ? L_17 : NULL ;
}
static void F_109 ( struct V_1 * V_2 )
{
}
static int F_110 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_111 ( struct V_1 * V_2 , int V_88 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( V_88 & V_170 &&
F_110 ( & V_4 -> V_2 ) == 0 )
V_4 -> V_2 . type = V_169 ;
}
static int
F_112 ( struct V_1 * V_2 , struct V_171 * V_172 )
{
return 0 ;
}
static void F_113 ( struct V_1 * V_2 , int V_173 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_174 ;
switch ( V_173 ) {
case V_37 :
V_174 = F_97 ( V_4 ) ;
V_174 |= ( V_175 | V_176 ) ;
F_101 ( V_4 , V_174 ) ;
break;
default:
V_174 = F_97 ( V_4 ) ;
V_174 &= ~ ( V_177 | V_176 ) ;
F_101 ( V_4 , V_174 ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_174 ;
V_174 = F_97 ( V_4 ) ;
V_174 &= ~ ( V_177 | V_176 ) ;
F_101 ( V_4 , V_174 ) ;
F_51 () ;
V_174 |= ( V_175 | V_176 ) ;
F_101 ( V_4 , V_174 ) ;
F_51 () ;
}
static void F_114 ( struct V_1 * V_2 , unsigned char V_178 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
while ( ! ( F_13 ( V_4 ) & V_71 ) )
F_14 () ;
F_105 ( V_4 ) ;
F_38 ( V_4 , ( unsigned char ) V_178 ) ;
}
static int F_115 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned char V_178 ;
while ( ! ( F_13 ( V_4 ) & V_75 ) )
F_14 () ;
F_105 ( V_4 ) ;
V_178 = F_27 ( V_4 ) ;
return V_178 ;
}
static void T_5
F_116 ( struct V_3 * V_4 , int * V_135 ,
int * V_61 , int * V_179 )
{
unsigned int V_15 ;
V_15 = F_100 ( V_4 ) & ( V_38 | V_32 ) ;
if ( V_15 == ( V_38 | V_32 ) ) {
T_3 V_102 , V_180 ;
V_102 = F_66 ( V_4 ) ;
* V_61 = 'n' ;
if ( V_102 & V_153 ) {
if ( V_102 & V_155 )
* V_61 = 'e' ;
else
* V_61 = 'o' ;
}
* V_179 = ( ( V_102 & V_181 ) >> V_182 ) + 5 ;
F_103 ( V_4 ) ;
V_180 = F_117 ( V_4 ) ;
F_105 ( V_4 ) ;
* V_135 = F_118 () / ( 16 * V_180 ) ;
}
F_119 ( L_18 , V_147 , * V_135 , * V_61 , * V_179 ) ;
}
static void F_120 ( struct V_1 * V_2 , int V_39 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
while ( ! ( F_13 ( V_4 ) & V_71 ) )
F_121 () ;
F_38 ( V_4 , V_39 ) ;
}
static void
F_122 ( struct V_183 * V_184 , const char * V_185 , unsigned int V_186 )
{
struct V_3 * V_4 = V_187 [ V_184 -> V_188 ] ;
unsigned long V_88 ;
F_55 ( & V_4 -> V_2 . V_76 , V_88 ) ;
F_123 ( & V_4 -> V_2 , V_185 , V_186 , F_120 ) ;
F_58 ( & V_4 -> V_2 . V_76 , V_88 ) ;
}
static int T_5
F_124 ( struct V_183 * V_184 , char * V_189 )
{
struct V_3 * V_4 ;
int V_135 = 57600 ;
int V_179 = 8 ;
int V_61 = 'n' ;
# if F_16 ( F_79 ) || \
F_16 ( F_7 )
int V_190 = 'r' ;
# else
int V_190 = 'n' ;
# endif
if ( V_184 -> V_188 < 0 || V_184 -> V_188 >= V_191 )
return - V_192 ;
V_4 = V_187 [ V_184 -> V_188 ] ;
if ( ! V_4 )
return - V_192 ;
if ( V_189 )
F_125 ( V_189 , & V_135 , & V_61 , & V_179 , & V_190 ) ;
else
F_116 ( V_4 , & V_135 , & V_61 , & V_179 ) ;
return F_126 ( & V_4 -> V_2 , V_184 , V_135 , V_61 , V_179 , V_190 ) ;
}
static void
F_127 ( struct V_183 * V_184 , const char * V_185 , unsigned int V_186 )
{
unsigned long V_88 ;
if ( V_193 . V_2 . line != V_184 -> V_188 )
return;
F_55 ( & V_193 . V_2 . V_76 , V_88 ) ;
F_123 ( & V_193 . V_2 , V_185 , V_186 ,
F_120 ) ;
F_58 ( & V_193 . V_2 . V_76 , V_88 ) ;
}
static int F_128 ( struct V_194 * V_195 , T_6 V_20 )
{
struct V_3 * V_4 = F_129 ( V_195 ) ;
return F_130 ( & V_196 , & V_4 -> V_2 ) ;
}
static int F_131 ( struct V_194 * V_195 )
{
struct V_3 * V_4 = F_129 ( V_195 ) ;
return F_132 ( & V_196 , & V_4 -> V_2 ) ;
}
static int F_133 ( struct V_194 * V_195 )
{
struct V_197 * V_198 ;
struct V_3 * V_4 = NULL ;
int V_199 = 0 ;
if ( V_195 -> V_200 < 0 || V_195 -> V_200 >= V_191 ) {
F_134 ( & V_195 -> V_130 , L_19 ) ;
return - V_201 ;
}
if ( V_187 [ V_195 -> V_200 ] == NULL ) {
V_4 = F_135 ( sizeof( * V_4 ) , V_202 ) ;
if ( ! V_4 ) {
F_134 ( & V_195 -> V_130 ,
L_20 ) ;
return - V_203 ;
}
V_187 [ V_195 -> V_200 ] = V_4 ;
#ifdef F_136
if ( ! ( V_193 . V_2 . V_204
&& V_193 . V_2 . line == V_195 -> V_200 ) ) {
#endif
V_199 = F_137 (
F_138 ( & V_195 -> V_130 ) ,
V_128 ) ;
if ( V_199 ) {
F_134 ( & V_195 -> V_130 ,
L_21 ) ;
goto V_205;
}
#ifdef F_136
}
#endif
F_139 ( & V_4 -> V_2 . V_76 ) ;
V_4 -> V_2 . V_165 = F_118 () ;
V_4 -> V_2 . V_206 = V_207 ;
V_4 -> V_2 . V_208 = & V_209 ;
V_4 -> V_2 . line = V_195 -> V_200 ;
V_4 -> V_2 . V_210 = V_211 ;
V_4 -> V_2 . V_88 = V_212 ;
V_198 = F_140 ( V_195 , V_213 , 0 ) ;
if ( V_198 == NULL ) {
F_134 ( & V_195 -> V_130 , L_22 ) ;
V_199 = - V_201 ;
goto V_214;
}
V_4 -> V_2 . V_204 = F_141 ( V_198 -> V_215 , F_142 ( V_198 ) ) ;
if ( ! V_4 -> V_2 . V_204 ) {
F_134 ( & V_195 -> V_130 , L_23 ) ;
V_199 = - V_216 ;
goto V_214;
}
V_4 -> V_2 . V_217 = V_198 -> V_215 ;
V_4 -> V_117 = F_143 ( V_195 , 0 ) ;
if ( V_4 -> V_117 < 0 ) {
F_134 ( & V_195 -> V_130 , L_24 ) ;
V_199 = - V_201 ;
goto V_218;
}
V_4 -> V_116 = F_143 ( V_195 , 1 ) ;
if ( V_4 -> V_116 < 0 ) {
F_134 ( & V_195 -> V_130 , L_25 ) ;
V_199 = - V_201 ;
goto V_218;
}
V_4 -> V_2 . V_12 = V_4 -> V_116 ;
V_4 -> V_129 = F_143 ( V_195 , 2 ) ;
if ( V_4 -> V_129 < 0 ) {
F_134 ( & V_195 -> V_130 , L_26 ) ;
V_199 = - V_201 ;
goto V_218;
}
#ifdef F_12
F_139 ( & V_4 -> V_89 ) ;
V_4 -> V_28 = 1 ;
V_4 -> V_24 = 0 ;
V_198 = F_140 ( V_195 , V_219 , 0 ) ;
if ( V_198 == NULL ) {
F_134 ( & V_195 -> V_130 , L_27 ) ;
V_199 = - V_201 ;
goto V_218;
}
V_4 -> V_22 = V_198 -> V_215 ;
V_198 = F_140 ( V_195 , V_219 , 1 ) ;
if ( V_198 == NULL ) {
F_134 ( & V_195 -> V_130 , L_28 ) ;
V_199 = - V_201 ;
goto V_218;
}
V_4 -> V_91 = V_198 -> V_215 ;
F_144 ( & ( V_4 -> V_94 ) ) ;
#endif
#if F_16 ( F_79 ) || \
F_16 ( F_7 )
V_198 = F_140 ( V_195 , V_220 , 0 ) ;
if ( V_198 == NULL )
V_4 -> V_5 = - 1 ;
else
V_4 -> V_5 = V_198 -> V_215 ;
V_198 = F_140 ( V_195 , V_220 , 1 ) ;
if ( V_198 == NULL )
V_4 -> V_10 = - 1 ;
else
V_4 -> V_10 = V_198 -> V_215 ;
#endif
}
#ifdef F_145
if ( ! F_146 ( V_195 ) ) {
#endif
V_4 = V_187 [ V_195 -> V_200 ] ;
V_4 -> V_2 . V_130 = & V_195 -> V_130 ;
F_147 ( & V_195 -> V_130 , V_4 ) ;
V_199 = F_148 ( & V_196 , & V_4 -> V_2 ) ;
#ifdef F_145
}
#endif
if ( ! V_199 )
return 0 ;
if ( V_4 ) {
V_218:
F_149 ( V_4 -> V_2 . V_204 ) ;
V_214:
F_150 ( F_138 ( & V_195 -> V_130 ) ) ;
V_205:
F_151 ( V_4 ) ;
V_187 [ V_195 -> V_200 ] = NULL ;
}
return V_199 ;
}
static int F_152 ( struct V_194 * V_195 )
{
struct V_3 * V_4 = F_129 ( V_195 ) ;
F_147 ( & V_195 -> V_130 , NULL ) ;
if ( V_4 ) {
F_153 ( & V_196 , & V_4 -> V_2 ) ;
F_149 ( V_4 -> V_2 . V_204 ) ;
F_150 ( F_138 ( & V_195 -> V_130 ) ) ;
F_151 ( V_4 ) ;
V_187 [ V_195 -> V_200 ] = NULL ;
}
return 0 ;
}
static int T_5 F_154 ( void )
{
F_155 ( & V_221 , V_128 ) ;
F_156 ( V_222 , V_191 , 0 ) ;
F_157 ( & V_223 ) ;
return 0 ;
}
static int F_158 ( struct V_194 * V_195 )
{
struct V_197 * V_198 ;
int V_199 ;
if ( V_195 -> V_200 < 0 || V_195 -> V_200 >= V_191 ) {
F_134 ( & V_195 -> V_130 , L_29 ) ;
return - V_201 ;
}
V_199 = F_137 ( F_138 ( & V_195 -> V_130 ) ,
V_128 ) ;
if ( V_199 ) {
F_134 ( & V_195 -> V_130 ,
L_21 ) ;
return V_199 ;
}
V_198 = F_140 ( V_195 , V_213 , 0 ) ;
if ( V_198 == NULL ) {
F_134 ( & V_195 -> V_130 , L_22 ) ;
V_199 = - V_201 ;
goto V_214;
}
V_193 . V_2 . V_204 = F_141 ( V_198 -> V_215 ,
F_142 ( V_198 ) ) ;
if ( ! V_193 . V_2 . V_204 ) {
F_134 ( & V_195 -> V_130 , L_23 ) ;
V_199 = - V_216 ;
goto V_214;
}
V_193 . V_2 . V_217 = V_198 -> V_215 ;
V_193 . V_2 . line = V_195 -> V_200 ;
V_193 . V_2 . V_165 = F_118 () ;
V_193 . V_2 . V_206 = V_207 ;
F_139 ( & V_193 . V_2 . V_76 ) ;
return 0 ;
V_214:
F_150 ( F_138 ( & V_195 -> V_130 ) ) ;
return V_199 ;
}
struct V_183 T_5 * F_159 ( unsigned int V_2 ,
unsigned int V_224 )
{
struct V_133 V_225 ;
char V_226 [ 20 ] ;
if ( V_2 < 0 || V_2 >= V_191 )
return NULL ;
snprintf ( V_226 , 20 , V_128 L_30 , V_2 ) ;
F_155 ( & V_227 ,
V_226 ) ;
F_156 ( V_228 , 1 , 0 ) ;
if ( ! V_193 . V_2 . V_204 )
return NULL ;
#ifdef F_145
V_223 . V_88 &= ~ V_229 ;
#endif
V_230 . V_188 = V_2 ;
V_225 . V_139 = V_224 ;
V_225 . V_158 = 0 ;
V_225 . V_231 = 0 ;
V_225 . V_232 = V_233 ;
V_225 . V_36 = V_2 ;
F_91 ( & V_193 . V_2 , & V_225 , & V_225 ) ;
return & V_230 ;
}
static int T_5 F_160 ( void )
{
int V_199 ;
F_81 ( L_31 ) ;
V_199 = F_161 ( & V_196 ) ;
if ( V_199 ) {
F_162 ( L_32 ,
V_196 . V_234 , V_199 ) ;
}
V_199 = F_163 ( & V_235 ) ;
if ( V_199 ) {
F_162 ( L_33 ) ;
F_164 ( & V_196 ) ;
}
return V_199 ;
}
static void T_7 F_165 ( void )
{
F_166 ( & V_235 ) ;
F_164 ( & V_196 ) ;
}

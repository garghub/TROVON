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
static T_2 V_41 ;
V_15 = F_13 ( V_4 ) ;
F_26 ( V_4 ) ;
V_39 = F_27 ( V_4 ) ;
V_4 -> V_2 . V_26 . V_42 ++ ;
#if F_16 ( V_43 ) || \
F_16 ( V_44 )
if ( V_45 && V_46 == V_4 -> V_2 . line
&& V_47 )
if ( V_39 == 0x3 ) {
F_28 () ;
return;
}
if ( ! V_4 -> V_2 . V_20 )
return;
#endif
if ( V_48 ) {
if ( V_41 > 0 ) {
T_2 V_49 , V_50 , V_51 ;
if ( ( ~ V_39 & ( ~ V_39 + 1 ) ) & 0xff )
goto V_52;
V_49 = F_29 () ;
V_50 = V_49 - V_41 ;
if ( V_50 >> 32 )
goto V_52;
V_51 = F_30 ( V_4 )
* V_53 ;
if ( V_50 > V_51 )
goto V_52;
if ( V_39 )
V_41 = 0 ;
else
V_41 = V_49 ;
return;
V_52:
V_15 &= ~ V_54 ;
V_41 = 0 ;
}
}
if ( V_15 & V_54 ) {
if ( V_48 )
if ( F_31 () < 5 )
V_41 = F_29 () ;
V_4 -> V_2 . V_26 . V_55 ++ ;
if ( F_32 ( & V_4 -> V_2 ) )
goto V_56;
V_15 &= ~ ( V_57 | V_58 ) ;
}
if ( V_15 & V_57 )
V_4 -> V_2 . V_26 . V_59 ++ ;
if ( V_15 & V_60 )
V_4 -> V_2 . V_26 . V_61 ++ ;
if ( V_15 & V_58 )
V_4 -> V_2 . V_26 . V_62 ++ ;
V_15 &= V_4 -> V_2 . V_63 ;
if ( V_15 & V_54 )
V_40 = V_64 ;
else if ( V_15 & V_57 )
V_40 = V_65 ;
else if ( V_15 & V_58 )
V_40 = V_66 ;
else
V_40 = V_67 ;
if ( F_33 ( & V_4 -> V_2 , V_39 ) )
goto V_56;
F_34 ( & V_4 -> V_2 , V_15 , V_60 , V_39 , V_40 ) ;
V_56:
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
if ( V_4 -> V_2 . V_68 ) {
F_38 ( V_4 , V_4 -> V_2 . V_68 ) ;
V_4 -> V_2 . V_26 . V_27 ++ ;
V_4 -> V_2 . V_68 = 0 ;
}
while ( ( F_13 ( V_4 ) & V_69 ) && V_19 -> V_23 != V_19 -> V_70 ) {
F_38 ( V_4 , V_19 -> V_71 [ V_19 -> V_23 ] ) ;
V_19 -> V_23 = ( V_19 -> V_23 + 1 ) & ( V_25 - 1 ) ;
V_4 -> V_2 . V_26 . V_27 ++ ;
}
if ( F_39 ( V_19 ) < V_72 )
F_9 ( & V_4 -> V_2 ) ;
}
static T_1 F_40 ( int V_12 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
while ( F_13 ( V_4 ) & V_73 )
F_25 ( V_4 ) ;
return V_17 ;
}
static T_1 F_41 ( int V_12 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
F_42 ( & V_4 -> V_2 . V_74 ) ;
if ( F_13 ( V_4 ) & V_69 )
F_23 ( V_4 ) ;
F_43 ( & V_4 -> V_2 . V_74 ) ;
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
if ( V_4 -> V_2 . V_68 ) {
F_38 ( V_4 , V_4 -> V_2 . V_68 ) ;
V_4 -> V_2 . V_26 . V_27 ++ ;
V_4 -> V_2 . V_68 = 0 ;
}
V_4 -> V_24 = F_44 ( V_19 -> V_70 , V_19 -> V_23 , V_25 ) ;
if ( V_4 -> V_24 > ( V_25 - V_19 -> V_23 ) )
V_4 -> V_24 = V_25 - V_19 -> V_23 ;
F_45 ( ( unsigned long ) ( V_19 -> V_71 + V_19 -> V_23 ) ,
( unsigned long ) ( V_19 -> V_71 + V_19 -> V_23 + V_4 -> V_24 ) ) ;
F_46 ( V_4 -> V_22 ,
F_47 ( V_75 , V_76 ,
V_77 ,
V_78 ,
V_79 ,
V_80 ) ) ;
F_48 ( V_4 -> V_22 , ( unsigned long ) ( V_19 -> V_71 + V_19 -> V_23 ) ) ;
F_49 ( V_4 -> V_22 , V_4 -> V_24 ) ;
F_50 ( V_4 -> V_22 , 1 ) ;
F_51 () ;
F_52 ( V_4 -> V_22 ) ;
F_22 ( V_4 , V_32 ) ;
}
static void F_53 ( struct V_3 * V_4 )
{
int V_81 , V_40 , V_15 ;
V_15 = F_13 ( V_4 ) ;
F_26 ( V_4 ) ;
V_4 -> V_2 . V_26 . V_42 +=
F_44 ( V_4 -> V_82 . V_70 , V_4 -> V_82 . V_23 ,
V_25 ) ;
if ( V_15 & V_54 ) {
V_4 -> V_2 . V_26 . V_55 ++ ;
if ( F_32 ( & V_4 -> V_2 ) )
goto V_83;
V_15 &= ~ ( V_57 | V_58 ) ;
}
if ( V_15 & V_57 )
V_4 -> V_2 . V_26 . V_59 ++ ;
if ( V_15 & V_60 )
V_4 -> V_2 . V_26 . V_61 ++ ;
if ( V_15 & V_58 )
V_4 -> V_2 . V_26 . V_62 ++ ;
V_15 &= V_4 -> V_2 . V_63 ;
if ( V_15 & V_54 )
V_40 = V_64 ;
else if ( V_15 & V_57 )
V_40 = V_65 ;
else if ( V_15 & V_58 )
V_40 = V_66 ;
else
V_40 = V_67 ;
for ( V_81 = V_4 -> V_82 . V_23 ; ; V_81 ++ ) {
if ( V_81 >= V_25 )
V_81 = 0 ;
if ( V_81 == V_4 -> V_82 . V_70 )
break;
if ( ! F_33 ( & V_4 -> V_2 , V_4 -> V_82 . V_71 [ V_81 ] ) )
F_34 ( & V_4 -> V_2 , V_15 , V_60 ,
V_4 -> V_82 . V_71 [ V_81 ] , V_40 ) ;
}
V_83:
F_35 ( & V_4 -> V_2 . V_20 -> V_2 ) ;
}
void F_54 ( struct V_3 * V_4 )
{
int V_84 , V_85 ;
unsigned long V_86 ;
F_55 ( V_4 -> V_87 ) ;
F_56 ( & V_4 -> V_88 , V_86 ) ;
V_4 -> V_89 = F_57 ( V_4 -> V_87 ) ;
V_84 = F_58 ( V_4 -> V_87 ) ;
V_4 -> V_89 = V_90 - V_4 -> V_89 ;
if ( V_4 -> V_89 == V_90 || V_84 == 0 )
V_4 -> V_89 = 0 ;
V_84 = V_91 - V_84 ;
if ( V_84 == V_91 )
V_84 = 0 ;
V_85 = V_4 -> V_89 * V_91 + V_84 ;
if ( V_85 > V_4 -> V_82 . V_23 ||
V_4 -> V_89 < ( V_4 -> V_82 . V_23 / V_91 ) ) {
V_4 -> V_82 . V_70 = V_85 ;
F_53 ( V_4 ) ;
V_4 -> V_82 . V_23 = V_4 -> V_82 . V_70 ;
}
F_59 ( & V_4 -> V_88 , V_86 ) ;
F_60 ( V_4 -> V_87 ) ;
F_61 ( & ( V_4 -> V_92 ) , V_93 + V_94 ) ;
}
static T_1 F_62 ( int V_12 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
struct V_18 * V_19 = & V_4 -> V_2 . V_20 -> V_19 ;
F_42 ( & V_4 -> V_2 . V_74 ) ;
if ( ! ( F_63 ( V_4 -> V_22 ) & V_95 ) ) {
F_15 ( V_4 -> V_22 ) ;
F_64 ( V_4 -> V_22 ) ;
F_18 ( V_4 , V_32 ) ;
V_4 -> V_2 . V_26 . V_27 += V_4 -> V_24 ;
if ( ! ( V_19 -> V_23 == 0 && V_19 -> V_70 == 0 ) ) {
V_19 -> V_23 = ( V_19 -> V_23 + V_4 -> V_24 ) & ( V_25 - 1 ) ;
if ( F_39 ( V_19 ) < V_72 )
F_9 ( & V_4 -> V_2 ) ;
}
F_21 ( V_4 ) ;
}
F_43 ( & V_4 -> V_2 . V_74 ) ;
return V_17 ;
}
static T_1 F_65 ( int V_12 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
unsigned int V_96 ;
int V_84 , V_85 ;
F_42 ( & V_4 -> V_88 ) ;
V_96 = F_63 ( V_4 -> V_87 ) ;
F_64 ( V_4 -> V_87 ) ;
V_4 -> V_89 = F_57 ( V_4 -> V_87 ) ;
V_84 = F_58 ( V_4 -> V_87 ) ;
V_4 -> V_89 = V_90 - V_4 -> V_89 ;
if ( V_4 -> V_89 == V_90 || V_84 == 0 )
V_4 -> V_89 = 0 ;
V_85 = V_4 -> V_89 * V_91 ;
if ( V_85 > V_4 -> V_82 . V_23 ||
V_4 -> V_89 < ( V_4 -> V_82 . V_23 / V_91 ) ) {
V_4 -> V_82 . V_70 = V_85 ;
F_53 ( V_4 ) ;
V_4 -> V_82 . V_23 = V_4 -> V_82 . V_70 ;
}
F_43 ( & V_4 -> V_88 ) ;
return V_17 ;
}
static unsigned int F_66 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_97 ;
V_97 = F_13 ( V_4 ) ;
if ( V_97 & V_21 )
return V_98 ;
else
return 0 ;
}
static void F_67 ( struct V_1 * V_2 , int V_99 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
T_3 V_100 = F_68 ( V_4 ) ;
if ( V_99 )
V_100 |= V_101 ;
else
V_100 &= ~ V_101 ;
F_69 ( V_4 , V_100 ) ;
F_51 () ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
#ifdef F_12
T_4 V_102 ;
if ( F_71 ( V_4 -> V_87 , L_1 ) < 0 ) {
F_72 ( V_103 L_2 ) ;
return - V_104 ;
}
if ( F_71 ( V_4 -> V_22 , L_3 ) < 0 ) {
F_72 ( V_103 L_4 ) ;
F_73 ( V_4 -> V_87 ) ;
return - V_104 ;
}
F_74 ( V_4 -> V_87 , F_65 , V_4 ) ;
F_74 ( V_4 -> V_22 , F_62 , V_4 ) ;
V_4 -> V_82 . V_71 = ( unsigned char * ) F_75 ( NULL , V_105 , & V_102 , V_106 ) ;
V_4 -> V_82 . V_70 = 0 ;
V_4 -> V_82 . V_23 = 0 ;
V_4 -> V_89 = 0 ;
F_46 ( V_4 -> V_87 ,
F_47 ( V_107 , V_108 ,
V_109 , V_110 ,
V_79 ,
V_80 ) ) ;
F_49 ( V_4 -> V_87 , V_91 ) ;
F_50 ( V_4 -> V_87 , 1 ) ;
F_76 ( V_4 -> V_87 , V_90 ) ;
F_77 ( V_4 -> V_87 , 1 ) ;
F_48 ( V_4 -> V_87 , ( unsigned long ) V_4 -> V_82 . V_71 ) ;
F_52 ( V_4 -> V_87 ) ;
V_4 -> V_92 . V_111 = ( unsigned long ) ( V_4 ) ;
V_4 -> V_92 . V_112 = ( void * ) F_54 ;
V_4 -> V_92 . V_113 = V_93 + V_94 ;
F_78 ( & ( V_4 -> V_92 ) ) ;
#else
# if F_16 ( V_43 ) || \
F_16 ( V_44 )
if ( V_46 == V_4 -> V_2 . line && V_47 )
V_47 = 0 ;
else {
# endif
if ( F_79 ( V_4 -> V_114 , F_40 , 0 ,
L_1 , V_4 ) ) {
F_72 ( V_103 L_5 ) ;
return - V_104 ;
}
if ( F_79
( V_4 -> V_115 , F_41 , 0 ,
L_3 , V_4 ) ) {
F_72 ( V_103 L_6 ) ;
F_80 ( V_4 -> V_114 , V_4 ) ;
return - V_104 ;
}
# ifdef V_29
{
unsigned V_116 , V_117 ;
switch ( V_4 -> V_114 ) {
case V_118 :
V_116 = V_119 ;
V_117 = V_120 ;
break;
case V_121 :
V_116 = V_122 ;
V_117 = V_123 ;
break;
default:
V_116 = V_117 = 0 ;
break;
}
if ( V_116 &&
F_71 ( V_116 , L_1 ) < 0 ) {
F_72 ( V_103 L_7 ) ;
F_80 ( V_4 -> V_114 , V_4 ) ;
F_80 ( V_4 -> V_115 , V_4 ) ;
return - V_104 ;
}
if ( V_117 &&
F_71 ( V_117 , L_3 ) < 0 ) {
F_72 ( V_103 L_7 ) ;
F_73 ( V_116 ) ;
F_80 ( V_4 -> V_114 , V_4 ) ;
F_80 ( V_4 -> V_115 , V_4 ) ;
return - V_104 ;
}
}
# endif
# if F_16 ( V_43 ) || \
F_16 ( V_44 )
}
# endif
#endif
#ifdef F_81
if ( V_4 -> V_5 >= 0 ) {
if ( F_79 ( F_82 ( V_4 -> V_5 ) ,
F_6 ,
V_124 | V_125 |
0 , L_8 , V_4 ) ) {
V_4 -> V_5 = - 1 ;
F_83 ( L_9 ) ;
}
}
if ( V_4 -> V_10 >= 0 ) {
if ( F_84 ( V_4 -> V_10 , V_126 ) ) {
F_83 ( L_10 , V_4 -> V_10 ) ;
V_4 -> V_10 = - 1 ;
} else
F_85 ( V_4 -> V_10 , 0 ) ;
}
#endif
#ifdef F_7
if ( V_4 -> V_5 >= 0 ) {
if ( F_79 ( V_4 -> V_127 , F_6 ,
0 , L_11 , V_4 ) ) {
V_4 -> V_5 = - 1 ;
F_86 ( V_2 -> V_128 , L_12 ) ;
}
F_87 ( V_4 , F_88 ( V_4 ) | V_129 ) ;
F_22 ( V_4 , V_130 ) ;
}
#endif
F_22 ( V_4 , V_38 ) ;
return 0 ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
#ifdef F_12
F_15 ( V_4 -> V_22 ) ;
F_73 ( V_4 -> V_22 ) ;
F_15 ( V_4 -> V_87 ) ;
F_73 ( V_4 -> V_87 ) ;
F_90 ( & ( V_4 -> V_92 ) ) ;
F_91 ( NULL , V_105 , V_4 -> V_82 . V_71 , 0 ) ;
#else
#ifdef V_29
switch ( V_4 -> V_2 . V_12 ) {
case V_118 :
F_73 ( V_119 ) ;
F_73 ( V_120 ) ;
break;
case V_121 :
F_73 ( V_122 ) ;
F_73 ( V_123 ) ;
break;
default:
break;
}
#endif
F_80 ( V_4 -> V_114 , V_4 ) ;
F_80 ( V_4 -> V_115 , V_4 ) ;
#endif
#ifdef F_81
if ( V_4 -> V_5 >= 0 )
F_80 ( F_82 ( V_4 -> V_5 ) , V_4 ) ;
if ( V_4 -> V_10 >= 0 )
F_92 ( V_4 -> V_10 ) ;
#endif
#ifdef F_7
if ( V_4 -> V_5 >= 0 )
F_80 ( V_4 -> V_127 , V_4 ) ;
#endif
}
static void
F_93 ( struct V_1 * V_2 , struct V_131 * V_35 ,
struct V_131 * V_132 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned long V_86 ;
unsigned int V_133 , V_134 ;
unsigned int V_135 , V_100 = 0 ;
unsigned long V_136 ;
#ifdef F_81
if ( V_132 == NULL && V_4 -> V_5 != - 1 )
V_35 -> V_137 |= V_138 ;
else if ( V_4 -> V_5 == - 1 )
V_35 -> V_137 &= ~ V_138 ;
#endif
switch ( V_35 -> V_137 & V_139 ) {
case V_140 :
V_100 = F_94 ( 8 ) ;
break;
case V_141 :
V_100 = F_94 ( 7 ) ;
break;
case V_142 :
V_100 = F_94 ( 6 ) ;
break;
case V_143 :
V_100 = F_94 ( 5 ) ;
break;
default:
F_72 ( V_144 L_13 ,
V_145 ) ;
}
if ( V_35 -> V_137 & V_146 ) {
if ( V_147 )
F_72 ( V_148 L_14
L_15 ) ;
else
V_100 |= V_149 ;
}
if ( V_35 -> V_137 & V_150 )
V_100 |= V_151 ;
if ( ! ( V_35 -> V_137 & V_152 ) )
V_100 |= V_153 ;
if ( V_35 -> V_137 & V_154 )
V_100 |= V_155 ;
F_56 ( & V_4 -> V_2 . V_74 , V_86 ) ;
V_2 -> V_63 = V_60 ;
if ( V_35 -> V_156 & V_157 )
V_2 -> V_63 |= ( V_58 | V_57 ) ;
if ( V_35 -> V_156 & ( V_158 | V_159 | V_160 ) )
V_2 -> V_63 |= V_54 ;
V_2 -> V_161 = 0 ;
if ( V_35 -> V_156 & V_162 )
V_2 -> V_161 |= V_58 | V_57 ;
if ( V_35 -> V_156 & V_158 ) {
V_2 -> V_161 |= V_54 ;
if ( V_35 -> V_156 & V_162 )
V_2 -> V_161 |= V_60 ;
}
V_133 = F_95 ( V_2 , V_35 , V_132 , 0 , V_2 -> V_163 / 16 ) ;
V_134 = F_96 ( V_2 , V_133 ) ;
if ( V_35 -> V_36 != V_37 )
V_134 -= V_164 ;
F_97 ( V_4 , V_165 / V_133 * 15 ) ;
V_136 = V_93 + F_98 ( 10 ) ;
while ( F_99 ( V_4 ) & V_166 && ! ( F_13 ( V_4 ) & V_21 ) )
if ( F_100 ( V_93 , V_136 ) ) {
F_101 ( V_2 -> V_128 , L_16 ) ;
break;
}
V_135 = F_102 ( V_4 ) ;
F_103 ( V_4 , F_99 ( V_4 ) & ~ V_166 ) ;
F_104 ( V_4 ) ;
F_105 ( V_4 ) ;
F_106 ( V_4 , V_134 ) ;
F_51 () ;
F_107 ( V_4 ) ;
F_69 ( V_4 , ( F_68 ( V_4 ) & ~ V_167 ) | V_100 ) ;
F_108 ( V_4 , V_135 ) ;
F_103 ( V_4 , F_99 ( V_4 ) | V_166 ) ;
F_109 ( V_2 , V_35 -> V_137 , V_133 ) ;
F_59 ( & V_4 -> V_2 . V_74 , V_86 ) ;
}
static const char * F_110 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
return V_4 -> V_2 . type == V_168 ? L_17 : NULL ;
}
static void F_111 ( struct V_1 * V_2 )
{
}
static int F_112 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_113 ( struct V_1 * V_2 , int V_86 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( V_86 & V_169 &&
F_112 ( & V_4 -> V_2 ) == 0 )
V_4 -> V_2 . type = V_168 ;
}
static int
F_114 ( struct V_1 * V_2 , struct V_170 * V_171 )
{
return 0 ;
}
static void F_115 ( struct V_1 * V_2 ,
struct V_131 * V_35 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_172 ;
switch ( V_35 -> V_36 ) {
case V_37 :
V_172 = F_99 ( V_4 ) ;
V_172 |= ( V_173 | V_174 ) ;
F_103 ( V_4 , V_172 ) ;
break;
default:
V_172 = F_99 ( V_4 ) ;
V_172 &= ~ ( V_175 | V_174 ) ;
F_103 ( V_4 , V_172 ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_172 ;
V_172 = F_99 ( V_4 ) ;
V_172 &= ~ ( V_175 | V_174 ) ;
F_103 ( V_4 , V_172 ) ;
F_51 () ;
V_172 |= ( V_173 | V_174 ) ;
F_103 ( V_4 , V_172 ) ;
F_51 () ;
}
static void F_116 ( struct V_1 * V_2 , unsigned char V_176 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
while ( ! ( F_13 ( V_4 ) & V_69 ) )
F_14 () ;
F_107 ( V_4 ) ;
F_38 ( V_4 , ( unsigned char ) V_176 ) ;
}
static int F_117 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned char V_176 ;
while ( ! ( F_13 ( V_4 ) & V_73 ) )
F_14 () ;
F_107 ( V_4 ) ;
V_176 = F_27 ( V_4 ) ;
return V_176 ;
}
static void T_5
F_118 ( struct V_3 * V_4 , int * V_133 ,
int * V_59 , int * V_177 )
{
unsigned int V_15 ;
V_15 = F_102 ( V_4 ) & ( V_38 | V_32 ) ;
if ( V_15 == ( V_38 | V_32 ) ) {
T_3 V_100 , V_178 ;
V_100 = F_68 ( V_4 ) ;
* V_59 = 'n' ;
if ( V_100 & V_151 ) {
if ( V_100 & V_153 )
* V_59 = 'e' ;
else
* V_59 = 'o' ;
}
* V_177 = ( ( V_100 & V_179 ) >> V_180 ) + 5 ;
F_105 ( V_4 ) ;
V_178 = F_119 ( V_4 ) ;
F_107 ( V_4 ) ;
* V_133 = F_120 () / ( 16 * V_178 ) ;
}
F_121 ( L_18 , V_145 , * V_133 , * V_59 , * V_177 ) ;
}
static void F_122 ( struct V_1 * V_2 , int V_39 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
while ( ! ( F_13 ( V_4 ) & V_69 ) )
F_123 () ;
F_38 ( V_4 , V_39 ) ;
}
static void
F_124 ( struct V_181 * V_182 , const char * V_183 , unsigned int V_184 )
{
struct V_3 * V_4 = V_185 [ V_182 -> V_186 ] ;
unsigned long V_86 ;
F_56 ( & V_4 -> V_2 . V_74 , V_86 ) ;
F_125 ( & V_4 -> V_2 , V_183 , V_184 , F_122 ) ;
F_59 ( & V_4 -> V_2 . V_74 , V_86 ) ;
}
static int T_5
F_126 ( struct V_181 * V_182 , char * V_187 )
{
struct V_3 * V_4 ;
int V_133 = 57600 ;
int V_177 = 8 ;
int V_59 = 'n' ;
# if F_16 ( F_81 ) || \
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
F_127 ( V_187 , & V_133 , & V_59 , & V_177 , & V_188 ) ;
else
F_118 ( V_4 , & V_133 , & V_59 , & V_177 ) ;
return F_128 ( & V_4 -> V_2 , V_182 , V_133 , V_59 , V_177 , V_188 ) ;
}
static void
F_129 ( struct V_181 * V_182 , const char * V_183 , unsigned int V_184 )
{
unsigned long V_86 ;
if ( V_191 . V_2 . line != V_182 -> V_186 )
return;
F_56 ( & V_191 . V_2 . V_74 , V_86 ) ;
F_125 ( & V_191 . V_2 , V_183 , V_184 ,
F_122 ) ;
F_59 ( & V_191 . V_2 . V_74 , V_86 ) ;
}
static int F_130 ( struct V_192 * V_193 , T_6 V_20 )
{
struct V_3 * V_4 = F_131 ( V_193 ) ;
return F_132 ( & V_194 , & V_4 -> V_2 ) ;
}
static int F_133 ( struct V_192 * V_193 )
{
struct V_3 * V_4 = F_131 ( V_193 ) ;
return F_134 ( & V_194 , & V_4 -> V_2 ) ;
}
static int F_135 ( struct V_192 * V_193 )
{
struct V_195 * V_196 ;
struct V_3 * V_4 = NULL ;
int V_197 = 0 ;
if ( V_193 -> V_198 < 0 || V_193 -> V_198 >= V_189 ) {
F_136 ( & V_193 -> V_128 , L_19 ) ;
return - V_199 ;
}
if ( V_185 [ V_193 -> V_198 ] == NULL ) {
V_4 = F_137 ( sizeof( * V_4 ) , V_200 ) ;
if ( ! V_4 ) {
F_136 ( & V_193 -> V_128 ,
L_20 ) ;
return - V_201 ;
}
V_185 [ V_193 -> V_198 ] = V_4 ;
#ifdef F_138
if ( ! ( V_191 . V_2 . V_202
&& V_191 . V_2 . line == V_193 -> V_198 ) ) {
#endif
V_197 = F_139 (
F_140 ( & V_193 -> V_128 ) ,
V_126 ) ;
if ( V_197 ) {
F_136 ( & V_193 -> V_128 ,
L_21 ) ;
goto V_203;
}
#ifdef F_138
}
#endif
F_141 ( & V_4 -> V_2 . V_74 ) ;
V_4 -> V_2 . V_163 = F_120 () ;
V_4 -> V_2 . V_204 = V_205 ;
V_4 -> V_2 . V_206 = & V_207 ;
V_4 -> V_2 . line = V_193 -> V_198 ;
V_4 -> V_2 . V_208 = V_209 ;
V_4 -> V_2 . V_86 = V_210 ;
V_196 = F_142 ( V_193 , V_211 , 0 ) ;
if ( V_196 == NULL ) {
F_136 ( & V_193 -> V_128 , L_22 ) ;
V_197 = - V_199 ;
goto V_212;
}
V_4 -> V_2 . V_202 = F_143 ( V_196 -> V_213 , F_144 ( V_196 ) ) ;
if ( ! V_4 -> V_2 . V_202 ) {
F_136 ( & V_193 -> V_128 , L_23 ) ;
V_197 = - V_214 ;
goto V_212;
}
V_4 -> V_2 . V_215 = V_196 -> V_213 ;
V_4 -> V_115 = F_145 ( V_193 , 0 ) ;
if ( V_4 -> V_115 < 0 ) {
F_136 ( & V_193 -> V_128 , L_24 ) ;
V_197 = - V_199 ;
goto V_216;
}
V_4 -> V_114 = F_145 ( V_193 , 1 ) ;
if ( V_4 -> V_114 < 0 ) {
F_136 ( & V_193 -> V_128 , L_25 ) ;
V_197 = - V_199 ;
goto V_216;
}
V_4 -> V_2 . V_12 = V_4 -> V_114 ;
V_4 -> V_127 = F_145 ( V_193 , 2 ) ;
if ( V_4 -> V_127 < 0 ) {
F_136 ( & V_193 -> V_128 , L_26 ) ;
V_197 = - V_199 ;
goto V_216;
}
#ifdef F_12
F_141 ( & V_4 -> V_88 ) ;
V_4 -> V_28 = 1 ;
V_4 -> V_24 = 0 ;
V_196 = F_142 ( V_193 , V_217 , 0 ) ;
if ( V_196 == NULL ) {
F_136 ( & V_193 -> V_128 , L_27 ) ;
V_197 = - V_199 ;
goto V_216;
}
V_4 -> V_22 = V_196 -> V_213 ;
V_196 = F_142 ( V_193 , V_217 , 1 ) ;
if ( V_196 == NULL ) {
F_136 ( & V_193 -> V_128 , L_28 ) ;
V_197 = - V_199 ;
goto V_216;
}
V_4 -> V_87 = V_196 -> V_213 ;
F_146 ( & ( V_4 -> V_92 ) ) ;
#endif
#if F_16 ( F_81 ) || \
F_16 ( F_7 )
V_196 = F_142 ( V_193 , V_218 , 0 ) ;
if ( V_196 == NULL )
V_4 -> V_5 = - 1 ;
else
V_4 -> V_5 = V_196 -> V_213 ;
V_196 = F_142 ( V_193 , V_218 , 1 ) ;
if ( V_196 == NULL )
V_4 -> V_10 = - 1 ;
else
V_4 -> V_10 = V_196 -> V_213 ;
#endif
}
#ifdef F_147
if ( ! F_148 ( V_193 ) ) {
#endif
V_4 = V_185 [ V_193 -> V_198 ] ;
V_4 -> V_2 . V_128 = & V_193 -> V_128 ;
F_149 ( & V_193 -> V_128 , V_4 ) ;
V_197 = F_150 ( & V_194 , & V_4 -> V_2 ) ;
#ifdef F_147
}
#endif
if ( ! V_197 )
return 0 ;
if ( V_4 ) {
V_216:
F_151 ( V_4 -> V_2 . V_202 ) ;
V_212:
F_152 ( F_140 ( & V_193 -> V_128 ) ) ;
V_203:
F_153 ( V_4 ) ;
V_185 [ V_193 -> V_198 ] = NULL ;
}
return V_197 ;
}
static int F_154 ( struct V_192 * V_193 )
{
struct V_3 * V_4 = F_131 ( V_193 ) ;
F_149 ( & V_193 -> V_128 , NULL ) ;
if ( V_4 ) {
F_155 ( & V_194 , & V_4 -> V_2 ) ;
F_151 ( V_4 -> V_2 . V_202 ) ;
F_152 ( F_140 ( & V_193 -> V_128 ) ) ;
F_153 ( V_4 ) ;
V_185 [ V_193 -> V_198 ] = NULL ;
}
return 0 ;
}
static int T_5 F_156 ( void )
{
F_157 ( & V_219 , V_126 ) ;
F_158 ( V_220 , V_189 , 0 ) ;
F_159 ( & V_221 ) ;
return 0 ;
}
static int F_160 ( struct V_192 * V_193 )
{
struct V_195 * V_196 ;
int V_197 ;
if ( V_193 -> V_198 < 0 || V_193 -> V_198 >= V_189 ) {
F_136 ( & V_193 -> V_128 , L_29 ) ;
return - V_199 ;
}
V_197 = F_139 ( F_140 ( & V_193 -> V_128 ) ,
V_126 ) ;
if ( V_197 ) {
F_136 ( & V_193 -> V_128 ,
L_21 ) ;
return V_197 ;
}
V_196 = F_142 ( V_193 , V_211 , 0 ) ;
if ( V_196 == NULL ) {
F_136 ( & V_193 -> V_128 , L_22 ) ;
V_197 = - V_199 ;
goto V_212;
}
V_191 . V_2 . V_202 = F_143 ( V_196 -> V_213 ,
F_144 ( V_196 ) ) ;
if ( ! V_191 . V_2 . V_202 ) {
F_136 ( & V_193 -> V_128 , L_23 ) ;
V_197 = - V_214 ;
goto V_212;
}
V_191 . V_2 . V_215 = V_196 -> V_213 ;
V_191 . V_2 . line = V_193 -> V_198 ;
V_191 . V_2 . V_163 = F_120 () ;
V_191 . V_2 . V_204 = V_205 ;
F_141 ( & V_191 . V_2 . V_74 ) ;
return 0 ;
V_212:
F_152 ( F_140 ( & V_193 -> V_128 ) ) ;
return V_197 ;
}
struct V_181 T_5 * F_161 ( unsigned int V_2 ,
unsigned int V_222 )
{
struct V_131 V_223 ;
char V_224 [ 20 ] ;
if ( V_2 < 0 || V_2 >= V_189 )
return NULL ;
snprintf ( V_224 , 20 , V_126 L_30 , V_2 ) ;
F_157 ( & V_225 ,
V_224 ) ;
F_158 ( V_226 , 1 , 0 ) ;
if ( ! V_191 . V_2 . V_202 )
return NULL ;
#ifdef F_147
V_221 . V_86 &= ~ V_227 ;
#endif
V_228 . V_186 = V_2 ;
V_223 . V_137 = V_222 ;
V_223 . V_156 = 0 ;
V_223 . V_229 = 0 ;
V_223 . V_230 = V_231 ;
V_223 . V_36 = V_2 ;
F_93 ( & V_191 . V_2 , & V_223 , & V_223 ) ;
return & V_228 ;
}
static int T_5 F_162 ( void )
{
int V_197 ;
F_83 ( L_31 ) ;
V_197 = F_163 ( & V_194 ) ;
if ( V_197 ) {
F_164 ( L_32 ,
V_194 . V_232 , V_197 ) ;
}
V_197 = F_165 ( & V_233 ) ;
if ( V_197 ) {
F_164 ( L_33 ) ;
F_166 ( & V_194 ) ;
}
return V_197 ;
}
static void T_7 F_167 ( void )
{
F_168 ( & V_233 ) ;
F_166 ( & V_194 ) ;
}

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
#ifdef F_16
F_17 ( V_4 , V_30 ) ;
#endif
F_18 ( V_4 , V_31 ) ;
#endif
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_15 * V_16 = V_4 -> V_2 . V_17 -> V_2 . V_16 ;
if ( V_16 -> V_32 -> V_33 == V_34 )
F_20 ( V_2 ) ;
#ifdef F_12
if ( V_4 -> V_29 )
F_21 ( V_4 ) ;
#else
F_22 ( V_4 , V_31 ) ;
F_23 ( V_4 ) ;
#endif
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
F_18 ( V_4 , V_35 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
}
static void F_26 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = NULL ;
unsigned int V_14 , V_36 , V_37 ;
static struct V_38 V_39 = { . V_40 = 0 } ;
V_14 = F_13 ( V_4 ) ;
F_27 ( V_4 ) ;
V_36 = F_28 ( V_4 ) ;
V_4 -> V_2 . V_27 . V_41 ++ ;
#if F_29 ( V_42 ) || \
F_29 ( V_43 )
if ( V_44 && V_45 == V_4 -> V_2 . line
&& V_46 )
if ( V_36 == 0x3 ) {
F_30 () ;
return;
}
if ( ! V_4 -> V_2 . V_17 || ! V_4 -> V_2 . V_17 -> V_2 . V_16 )
return;
#endif
V_16 = V_4 -> V_2 . V_17 -> V_2 . V_16 ;
if ( V_47 ) {
if ( V_39 . V_40 ) {
struct V_38 V_48 ;
T_2 V_49 ;
if ( ( ~ V_36 & ( ~ V_36 + 1 ) ) & 0xff )
goto V_50;
F_31 ( & V_48 ) ;
if ( V_48 . V_40 - V_39 . V_40 > 1 )
goto V_50;
V_49 = 0 ;
if ( V_48 . V_40 != V_39 . V_40 )
V_49 += V_51 ;
V_49 += V_48 . V_52 - V_39 . V_52 ;
if ( V_49 > F_32 ( V_4 ) )
goto V_50;
if ( V_36 )
V_39 . V_40 = 0 ;
else
V_39 = V_48 ;
return;
V_50:
V_14 &= ~ V_53 ;
V_39 . V_40 = 0 ;
}
}
if ( V_14 & V_53 ) {
if ( V_47 )
if ( F_33 () < 5 )
F_31 ( & V_39 ) ;
V_4 -> V_2 . V_27 . V_54 ++ ;
if ( F_34 ( & V_4 -> V_2 ) )
goto V_55;
V_14 &= ~ ( V_56 | V_57 ) ;
}
if ( V_14 & V_56 )
V_4 -> V_2 . V_27 . V_58 ++ ;
if ( V_14 & V_59 )
V_4 -> V_2 . V_27 . V_60 ++ ;
if ( V_14 & V_57 )
V_4 -> V_2 . V_27 . V_61 ++ ;
V_14 &= V_4 -> V_2 . V_62 ;
if ( V_14 & V_53 )
V_37 = V_63 ;
else if ( V_14 & V_56 )
V_37 = V_64 ;
else if ( V_14 & V_57 )
V_37 = V_65 ;
else
V_37 = V_66 ;
if ( F_35 ( & V_4 -> V_2 , V_36 ) )
goto V_55;
F_36 ( & V_4 -> V_2 , V_14 , V_59 , V_36 , V_37 ) ;
V_55:
F_37 ( V_16 ) ;
}
static void F_23 ( struct V_3 * V_4 )
{
struct V_20 * V_21 = & V_4 -> V_2 . V_17 -> V_21 ;
if ( F_38 ( V_21 ) || F_39 ( & V_4 -> V_2 ) ) {
#ifdef F_16
F_17 ( V_4 , V_30 ) ;
#endif
F_18 ( V_4 , V_31 ) ;
return;
}
if ( V_4 -> V_2 . V_67 ) {
F_40 ( V_4 , V_4 -> V_2 . V_67 ) ;
V_4 -> V_2 . V_27 . V_28 ++ ;
V_4 -> V_2 . V_67 = 0 ;
}
while ( ( F_13 ( V_4 ) & V_68 ) && V_21 -> V_24 != V_21 -> V_69 ) {
F_40 ( V_4 , V_21 -> V_70 [ V_21 -> V_24 ] ) ;
V_21 -> V_24 = ( V_21 -> V_24 + 1 ) & ( V_26 - 1 ) ;
V_4 -> V_2 . V_27 . V_28 ++ ;
}
if ( F_41 ( V_21 ) < V_71 )
F_9 ( & V_4 -> V_2 ) ;
}
static T_1 F_42 ( int V_12 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
while ( F_13 ( V_4 ) & V_72 )
F_26 ( V_4 ) ;
return V_19 ;
}
static T_1 F_43 ( int V_12 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
F_44 ( & V_4 -> V_2 . V_73 ) ;
if ( F_13 ( V_4 ) & V_68 )
F_23 ( V_4 ) ;
F_45 ( & V_4 -> V_2 . V_73 ) ;
return V_19 ;
}
static void F_21 ( struct V_3 * V_4 )
{
struct V_20 * V_21 = & V_4 -> V_2 . V_17 -> V_21 ;
V_4 -> V_29 = 0 ;
if ( F_38 ( V_21 ) || F_39 ( & V_4 -> V_2 ) ) {
V_4 -> V_25 = 0 ;
V_4 -> V_29 = 1 ;
return;
}
if ( V_4 -> V_2 . V_67 ) {
F_40 ( V_4 , V_4 -> V_2 . V_67 ) ;
V_4 -> V_2 . V_27 . V_28 ++ ;
V_4 -> V_2 . V_67 = 0 ;
}
V_4 -> V_25 = F_46 ( V_21 -> V_69 , V_21 -> V_24 , V_26 ) ;
if ( V_4 -> V_25 > ( V_26 - V_21 -> V_24 ) )
V_4 -> V_25 = V_26 - V_21 -> V_24 ;
F_47 ( ( unsigned long ) ( V_21 -> V_70 + V_21 -> V_24 ) ,
( unsigned long ) ( V_21 -> V_70 + V_21 -> V_24 + V_4 -> V_25 ) ) ;
F_48 ( V_4 -> V_23 ,
F_49 ( V_74 , V_75 ,
V_76 ,
V_77 ,
V_78 ,
V_79 ) ) ;
F_50 ( V_4 -> V_23 , ( unsigned long ) ( V_21 -> V_70 + V_21 -> V_24 ) ) ;
F_51 ( V_4 -> V_23 , V_4 -> V_25 ) ;
F_52 ( V_4 -> V_23 , 1 ) ;
F_53 () ;
F_54 ( V_4 -> V_23 ) ;
F_22 ( V_4 , V_31 ) ;
}
static void F_55 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = V_4 -> V_2 . V_17 -> V_2 . V_16 ;
int V_80 , V_37 , V_14 ;
V_14 = F_13 ( V_4 ) ;
F_27 ( V_4 ) ;
V_4 -> V_2 . V_27 . V_41 +=
F_46 ( V_4 -> V_81 . V_69 , V_4 -> V_81 . V_24 ,
V_26 ) ;
if ( V_14 & V_53 ) {
V_4 -> V_2 . V_27 . V_54 ++ ;
if ( F_34 ( & V_4 -> V_2 ) )
goto V_82;
V_14 &= ~ ( V_56 | V_57 ) ;
}
if ( V_14 & V_56 )
V_4 -> V_2 . V_27 . V_58 ++ ;
if ( V_14 & V_59 )
V_4 -> V_2 . V_27 . V_60 ++ ;
if ( V_14 & V_57 )
V_4 -> V_2 . V_27 . V_61 ++ ;
V_14 &= V_4 -> V_2 . V_62 ;
if ( V_14 & V_53 )
V_37 = V_63 ;
else if ( V_14 & V_56 )
V_37 = V_64 ;
else if ( V_14 & V_57 )
V_37 = V_65 ;
else
V_37 = V_66 ;
for ( V_80 = V_4 -> V_81 . V_24 ; ; V_80 ++ ) {
if ( V_80 >= V_26 )
V_80 = 0 ;
if ( V_80 == V_4 -> V_81 . V_69 )
break;
if ( ! F_35 ( & V_4 -> V_2 , V_4 -> V_81 . V_70 [ V_80 ] ) )
F_36 ( & V_4 -> V_2 , V_14 , V_59 ,
V_4 -> V_81 . V_70 [ V_80 ] , V_37 ) ;
}
V_82:
F_37 ( V_16 ) ;
}
void F_56 ( struct V_3 * V_4 )
{
int V_83 , V_84 ;
F_57 ( V_4 -> V_85 ) ;
F_58 ( & V_4 -> V_86 ) ;
V_4 -> V_87 = F_59 ( V_4 -> V_85 ) ;
V_83 = F_60 ( V_4 -> V_85 ) ;
V_4 -> V_87 = V_88 - V_4 -> V_87 ;
if ( V_4 -> V_87 == V_88 || V_83 == 0 )
V_4 -> V_87 = 0 ;
V_83 = V_89 - V_83 ;
if ( V_83 == V_89 )
V_83 = 0 ;
V_84 = V_4 -> V_87 * V_89 + V_83 ;
if ( V_84 > V_4 -> V_81 . V_24 ||
V_4 -> V_87 < ( V_4 -> V_81 . V_24 / V_89 ) ) {
V_4 -> V_81 . V_69 = V_84 ;
F_55 ( V_4 ) ;
V_4 -> V_81 . V_24 = V_4 -> V_81 . V_69 ;
}
F_61 ( & V_4 -> V_86 ) ;
F_62 ( V_4 -> V_85 ) ;
F_63 ( & ( V_4 -> V_90 ) , V_91 + V_92 ) ;
}
static T_1 F_64 ( int V_12 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
struct V_20 * V_21 = & V_4 -> V_2 . V_17 -> V_21 ;
F_44 ( & V_4 -> V_2 . V_73 ) ;
if ( ! ( F_65 ( V_4 -> V_23 ) & V_93 ) ) {
F_15 ( V_4 -> V_23 ) ;
F_66 ( V_4 -> V_23 ) ;
F_18 ( V_4 , V_31 ) ;
V_4 -> V_2 . V_27 . V_28 += V_4 -> V_25 ;
if ( ! F_38 ( V_21 ) ) {
V_21 -> V_24 = ( V_21 -> V_24 + V_4 -> V_25 ) & ( V_26 - 1 ) ;
if ( F_41 ( V_21 ) < V_71 )
F_9 ( & V_4 -> V_2 ) ;
}
F_21 ( V_4 ) ;
}
F_45 ( & V_4 -> V_2 . V_73 ) ;
return V_19 ;
}
static T_1 F_67 ( int V_12 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
unsigned short V_94 ;
int V_83 , V_84 ;
F_44 ( & V_4 -> V_86 ) ;
V_94 = F_65 ( V_4 -> V_85 ) ;
F_66 ( V_4 -> V_85 ) ;
V_4 -> V_87 = F_59 ( V_4 -> V_85 ) ;
V_83 = F_60 ( V_4 -> V_85 ) ;
V_4 -> V_87 = V_88 - V_4 -> V_87 ;
if ( V_4 -> V_87 == V_88 || V_83 == 0 )
V_4 -> V_87 = 0 ;
V_84 = V_4 -> V_87 * V_89 ;
if ( V_84 > V_4 -> V_81 . V_24 ||
V_4 -> V_87 < ( V_4 -> V_81 . V_24 / V_89 ) ) {
V_4 -> V_81 . V_69 = V_84 ;
F_55 ( V_4 ) ;
V_4 -> V_81 . V_24 = V_4 -> V_81 . V_69 ;
}
F_45 ( & V_4 -> V_86 ) ;
return V_19 ;
}
static unsigned int F_68 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned short V_95 ;
V_95 = F_13 ( V_4 ) ;
if ( V_95 & V_22 )
return V_96 ;
else
return 0 ;
}
static void F_69 ( struct V_1 * V_2 , int V_97 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
T_3 V_98 = F_70 ( V_4 ) ;
if ( V_97 )
V_98 |= V_99 ;
else
V_98 &= ~ V_99 ;
F_71 ( V_4 , V_98 ) ;
F_53 () ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
#ifdef F_12
T_4 V_100 ;
if ( F_73 ( V_4 -> V_85 , L_1 ) < 0 ) {
F_74 ( V_101 L_2 ) ;
return - V_102 ;
}
if ( F_73 ( V_4 -> V_23 , L_3 ) < 0 ) {
F_74 ( V_101 L_4 ) ;
F_75 ( V_4 -> V_85 ) ;
return - V_102 ;
}
F_76 ( V_4 -> V_85 , F_67 , V_4 ) ;
F_76 ( V_4 -> V_23 , F_64 , V_4 ) ;
V_4 -> V_81 . V_70 = ( unsigned char * ) F_77 ( NULL , V_103 , & V_100 , V_104 ) ;
V_4 -> V_81 . V_69 = 0 ;
V_4 -> V_81 . V_24 = 0 ;
V_4 -> V_87 = 0 ;
F_48 ( V_4 -> V_85 ,
F_49 ( V_105 , V_106 ,
V_107 , V_108 ,
V_78 ,
V_79 ) ) ;
F_51 ( V_4 -> V_85 , V_89 ) ;
F_52 ( V_4 -> V_85 , 1 ) ;
F_78 ( V_4 -> V_85 , V_88 ) ;
F_79 ( V_4 -> V_85 , 1 ) ;
F_50 ( V_4 -> V_85 , ( unsigned long ) V_4 -> V_81 . V_70 ) ;
F_54 ( V_4 -> V_85 ) ;
V_4 -> V_90 . V_109 = ( unsigned long ) ( V_4 ) ;
V_4 -> V_90 . V_110 = ( void * ) F_56 ;
V_4 -> V_90 . V_111 = V_91 + V_92 ;
F_80 ( & ( V_4 -> V_90 ) ) ;
#else
# if F_29 ( V_42 ) || \
F_29 ( V_43 )
if ( V_45 == V_4 -> V_2 . line && V_46 )
V_46 = 0 ;
else {
# endif
if ( F_81 ( V_4 -> V_112 , F_42 , 0 ,
L_1 , V_4 ) ) {
F_74 ( V_101 L_5 ) ;
return - V_102 ;
}
if ( F_81
( V_4 -> V_113 , F_43 , 0 ,
L_3 , V_4 ) ) {
F_74 ( V_101 L_6 ) ;
F_82 ( V_4 -> V_112 , V_4 ) ;
return - V_102 ;
}
# ifdef F_16
{
unsigned V_114 , V_115 ;
switch ( V_4 -> V_112 ) {
case V_116 :
V_114 = V_117 ;
V_115 = V_118 ;
break;
case V_119 :
V_114 = V_120 ;
V_115 = V_121 ;
break;
default:
V_114 = V_115 = 0 ;
break;
} ;
if ( V_114 &&
F_73 ( V_114 , L_1 ) < 0 ) {
F_74 ( V_101 L_7 ) ;
F_82 ( V_4 -> V_112 , V_4 ) ;
F_82 ( V_4 -> V_113 , V_4 ) ;
return - V_102 ;
}
if ( V_115 &&
F_73 ( V_115 , L_3 ) < 0 ) {
F_74 ( V_101 L_7 ) ;
F_75 ( V_114 ) ;
F_82 ( V_4 -> V_112 , V_4 ) ;
F_82 ( V_4 -> V_113 , V_4 ) ;
return - V_102 ;
}
}
# endif
# if F_29 ( V_42 ) || \
F_29 ( V_43 )
}
# endif
#endif
#ifdef F_83
if ( V_4 -> V_5 >= 0 ) {
if ( F_81 ( F_84 ( V_4 -> V_5 ) ,
F_6 ,
V_122 | V_123 |
0 , L_8 , V_4 ) ) {
V_4 -> V_5 = - 1 ;
F_85 ( L_9 ) ;
}
}
if ( V_4 -> V_10 >= 0 ) {
if ( F_86 ( V_4 -> V_10 , V_124 ) ) {
F_85 ( L_10 , V_4 -> V_10 ) ;
V_4 -> V_10 = - 1 ;
} else
F_87 ( V_4 -> V_10 , 0 ) ;
}
#endif
#ifdef F_7
if ( V_4 -> V_5 >= 0 ) {
if ( F_81 ( V_4 -> V_125 , F_6 ,
V_126 , L_11 , V_4 ) ) {
V_4 -> V_5 = - 1 ;
F_88 ( V_2 -> V_127 , L_12 ) ;
}
F_89 ( V_4 , V_128 ) ;
F_22 ( V_4 , V_129 ) ;
}
#endif
F_22 ( V_4 , V_35 ) ;
return 0 ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
#ifdef F_12
F_15 ( V_4 -> V_23 ) ;
F_75 ( V_4 -> V_23 ) ;
F_15 ( V_4 -> V_85 ) ;
F_75 ( V_4 -> V_85 ) ;
F_91 ( & ( V_4 -> V_90 ) ) ;
F_92 ( NULL , V_103 , V_4 -> V_81 . V_70 , 0 ) ;
#else
#ifdef F_16
switch ( V_4 -> V_2 . V_12 ) {
case V_116 :
F_75 ( V_117 ) ;
F_75 ( V_118 ) ;
break;
case V_119 :
F_75 ( V_120 ) ;
F_75 ( V_121 ) ;
break;
default:
break;
} ;
#endif
F_82 ( V_4 -> V_112 , V_4 ) ;
F_82 ( V_4 -> V_113 , V_4 ) ;
#endif
#ifdef F_83
if ( V_4 -> V_5 >= 0 )
F_82 ( F_84 ( V_4 -> V_5 ) , V_4 ) ;
if ( V_4 -> V_10 >= 0 )
F_93 ( V_4 -> V_10 ) ;
#endif
#ifdef F_7
if ( V_4 -> V_5 >= 0 )
F_82 ( V_4 -> V_125 , V_4 ) ;
#endif
}
static void
F_94 ( struct V_1 * V_2 , struct V_130 * V_32 ,
struct V_130 * V_131 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned long V_132 ;
unsigned int V_133 , V_134 ;
unsigned short V_135 , V_136 , V_98 = 0 ;
switch ( V_32 -> V_137 & V_138 ) {
case V_139 :
V_98 = F_95 ( 8 ) ;
break;
case V_140 :
V_98 = F_95 ( 7 ) ;
break;
case V_141 :
V_98 = F_95 ( 6 ) ;
break;
case V_142 :
V_98 = F_95 ( 5 ) ;
break;
default:
F_74 ( V_143 L_13 ,
V_144 ) ;
}
if ( V_32 -> V_137 & V_145 ) {
if ( V_146 )
F_74 ( V_147 L_14
L_15 ) ;
else
V_98 |= V_148 ;
}
if ( V_32 -> V_137 & V_149 )
V_98 |= V_150 ;
if ( ! ( V_32 -> V_137 & V_151 ) )
V_98 |= V_152 ;
if ( V_32 -> V_137 & V_153 )
V_98 |= V_154 ;
F_96 ( & V_4 -> V_2 . V_73 , V_132 ) ;
V_2 -> V_62 = V_59 ;
if ( V_32 -> V_155 & V_156 )
V_2 -> V_62 |= ( V_57 | V_56 ) ;
if ( V_32 -> V_155 & ( V_157 | V_158 ) )
V_2 -> V_62 |= V_53 ;
V_2 -> V_159 = 0 ;
if ( V_32 -> V_155 & V_160 )
V_2 -> V_159 |= V_57 | V_56 ;
if ( V_32 -> V_155 & V_161 ) {
V_2 -> V_159 |= V_53 ;
if ( V_32 -> V_155 & V_160 )
V_2 -> V_159 |= V_59 ;
}
V_133 = F_97 ( V_2 , V_32 , V_131 , 0 , V_2 -> V_162 / 16 ) ;
V_134 = F_98 ( V_2 , V_133 ) ;
if ( V_32 -> V_33 != V_34 )
V_134 -= V_163 ;
F_99 ( V_4 , V_51 / V_133 * 15 ) ;
V_136 = F_100 ( V_4 ) ;
F_101 ( V_4 ) ;
F_102 ( V_4 ) ;
F_103 ( V_4 , V_134 & 0xFF ) ;
F_104 ( V_4 , ( V_134 >> 8 ) & 0xFF ) ;
F_53 () ;
F_105 ( V_4 ) ;
F_71 ( V_4 , V_98 ) ;
F_106 ( V_4 , V_136 ) ;
V_135 = F_107 ( V_4 ) ;
V_135 |= V_164 ;
F_108 ( V_4 , V_135 ) ;
F_109 ( V_2 , V_32 -> V_137 , V_133 ) ;
F_110 ( & V_4 -> V_2 . V_73 , V_132 ) ;
}
static const char * F_111 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
return V_4 -> V_2 . type == V_165 ? L_16 : NULL ;
}
static void F_112 ( struct V_1 * V_2 )
{
}
static int F_113 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_114 ( struct V_1 * V_2 , int V_132 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( V_132 & V_166 &&
F_113 ( & V_4 -> V_2 ) == 0 )
V_4 -> V_2 . type = V_165 ;
}
static int
F_115 ( struct V_1 * V_2 , struct V_167 * V_168 )
{
return 0 ;
}
static void F_116 ( struct V_1 * V_2 , int V_169 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned short V_135 ;
switch ( V_169 ) {
case V_34 :
V_135 = F_107 ( V_4 ) ;
V_135 |= ( V_170 | V_171 ) ;
F_108 ( V_4 , V_135 ) ;
break;
default:
V_135 = F_107 ( V_4 ) ;
V_135 &= ~ ( V_170 | V_171 ) ;
F_108 ( V_4 , V_135 ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned short V_135 ;
V_135 = F_107 ( V_4 ) ;
V_135 &= ~ ( V_170 | V_171 ) ;
F_108 ( V_4 , V_135 ) ;
F_53 () ;
V_135 |= ( V_170 | V_171 ) ;
F_108 ( V_4 , V_135 ) ;
F_53 () ;
}
static void F_117 ( struct V_1 * V_2 , unsigned char V_172 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
while ( ! ( F_13 ( V_4 ) & V_68 ) )
F_14 () ;
F_105 ( V_4 ) ;
F_40 ( V_4 , ( unsigned char ) V_172 ) ;
}
static int F_118 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned char V_172 ;
while ( ! ( F_13 ( V_4 ) & V_72 ) )
F_14 () ;
F_105 ( V_4 ) ;
V_172 = F_28 ( V_4 ) ;
return V_172 ;
}
static void F_119 ( struct V_1 * V_2 )
{
if ( V_46 ) {
V_46 = 0 ;
F_90 ( V_2 ) ;
}
}
static int F_120 ( struct V_1 * V_2 )
{
V_45 = V_2 -> line ;
V_46 = ! F_72 ( V_2 ) ;
return 0 ;
}
static void T_5
F_121 ( struct V_3 * V_4 , int * V_133 ,
int * V_58 , int * V_173 )
{
unsigned short V_14 ;
V_14 = F_100 ( V_4 ) & ( V_35 | V_31 ) ;
if ( V_14 == ( V_35 | V_31 ) ) {
T_3 V_98 , V_174 , V_175 ;
V_98 = F_70 ( V_4 ) ;
* V_58 = 'n' ;
if ( V_98 & V_150 ) {
if ( V_98 & V_152 )
* V_58 = 'e' ;
else
* V_58 = 'o' ;
}
switch ( V_98 & 0x03 ) {
case 0 :
* V_173 = 5 ;
break;
case 1 :
* V_173 = 6 ;
break;
case 2 :
* V_173 = 7 ;
break;
case 3 :
* V_173 = 8 ;
break;
}
F_102 ( V_4 ) ;
V_175 = F_122 ( V_4 ) ;
V_174 = F_123 ( V_4 ) ;
F_105 ( V_4 ) ;
* V_133 = F_124 () / ( 16 * ( V_175 | V_174 << 8 ) ) ;
}
F_125 ( L_17 , V_144 , * V_133 , * V_58 , * V_173 ) ;
}
static void F_126 ( struct V_1 * V_2 , int V_36 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
while ( ! ( F_13 ( V_4 ) & V_68 ) )
F_127 () ;
F_40 ( V_4 , V_36 ) ;
}
static void
F_128 ( struct V_176 * V_177 , const char * V_178 , unsigned int V_179 )
{
struct V_3 * V_4 = V_180 [ V_177 -> V_181 ] ;
unsigned long V_132 ;
F_96 ( & V_4 -> V_2 . V_73 , V_132 ) ;
F_129 ( & V_4 -> V_2 , V_178 , V_179 , F_126 ) ;
F_110 ( & V_4 -> V_2 . V_73 , V_132 ) ;
}
static int T_5
F_130 ( struct V_176 * V_177 , char * V_182 )
{
struct V_3 * V_4 ;
int V_133 = 57600 ;
int V_173 = 8 ;
int V_58 = 'n' ;
# if F_29 ( F_83 ) || \
F_29 ( F_7 )
int V_183 = 'r' ;
# else
int V_183 = 'n' ;
# endif
if ( V_177 -> V_181 < 0 || V_177 -> V_181 >= V_184 )
return - V_185 ;
V_4 = V_180 [ V_177 -> V_181 ] ;
if ( ! V_4 )
return - V_185 ;
if ( V_182 )
F_131 ( V_182 , & V_133 , & V_58 , & V_173 , & V_183 ) ;
else
F_121 ( V_4 , & V_133 , & V_58 , & V_173 ) ;
return F_132 ( & V_4 -> V_2 , V_177 , V_133 , V_58 , V_173 , V_183 ) ;
}
static void
F_133 ( struct V_176 * V_177 , const char * V_178 , unsigned int V_179 )
{
unsigned long V_132 ;
if ( V_186 . V_2 . line != V_177 -> V_181 )
return;
F_96 ( & V_186 . V_2 . V_73 , V_132 ) ;
F_129 ( & V_186 . V_2 , V_178 , V_179 ,
F_126 ) ;
F_110 ( & V_186 . V_2 . V_73 , V_132 ) ;
}
static int F_134 ( struct V_187 * V_188 , T_6 V_17 )
{
struct V_3 * V_4 = F_135 ( V_188 ) ;
return F_136 ( & V_189 , & V_4 -> V_2 ) ;
}
static int F_137 ( struct V_187 * V_188 )
{
struct V_3 * V_4 = F_135 ( V_188 ) ;
return F_138 ( & V_189 , & V_4 -> V_2 ) ;
}
static int F_139 ( struct V_187 * V_188 )
{
struct V_190 * V_191 ;
struct V_3 * V_4 = NULL ;
int V_192 = 0 ;
if ( V_188 -> V_193 < 0 || V_188 -> V_193 >= V_184 ) {
F_140 ( & V_188 -> V_127 , L_18 ) ;
return - V_194 ;
}
if ( V_180 [ V_188 -> V_193 ] == NULL ) {
V_4 = F_141 ( sizeof( * V_4 ) , V_195 ) ;
if ( ! V_4 ) {
F_140 ( & V_188 -> V_127 ,
L_19 ) ;
return - V_196 ;
}
V_180 [ V_188 -> V_193 ] = V_4 ;
#ifdef F_142
if ( ! ( V_186 . V_2 . V_197
&& V_186 . V_2 . line == V_188 -> V_193 ) ) {
#endif
V_192 = F_143 (
( unsigned short * ) V_188 -> V_127 . V_198 , V_124 ) ;
if ( V_192 ) {
F_140 ( & V_188 -> V_127 ,
L_20 ) ;
goto V_199;
}
#ifdef F_142
}
#endif
F_144 ( & V_4 -> V_2 . V_73 ) ;
V_4 -> V_2 . V_162 = F_124 () ;
V_4 -> V_2 . V_200 = V_201 ;
V_4 -> V_2 . V_202 = & V_203 ;
V_4 -> V_2 . line = V_188 -> V_193 ;
V_4 -> V_2 . V_204 = V_205 ;
V_4 -> V_2 . V_132 = V_206 ;
V_191 = F_145 ( V_188 , V_207 , 0 ) ;
if ( V_191 == NULL ) {
F_140 ( & V_188 -> V_127 , L_21 ) ;
V_192 = - V_194 ;
goto V_208;
}
V_4 -> V_2 . V_197 = F_146 ( V_191 -> V_209 , F_147 ( V_191 ) ) ;
if ( ! V_4 -> V_2 . V_197 ) {
F_140 ( & V_188 -> V_127 , L_22 ) ;
V_192 = - V_210 ;
goto V_208;
}
V_4 -> V_2 . V_211 = V_191 -> V_209 ;
V_4 -> V_113 = F_148 ( V_188 , 0 ) ;
if ( V_4 -> V_113 < 0 ) {
F_140 ( & V_188 -> V_127 , L_23 ) ;
V_192 = - V_194 ;
goto V_212;
}
V_4 -> V_112 = F_148 ( V_188 , 1 ) ;
if ( V_4 -> V_112 < 0 ) {
F_140 ( & V_188 -> V_127 , L_24 ) ;
V_192 = - V_194 ;
goto V_212;
}
V_4 -> V_2 . V_12 = V_4 -> V_112 ;
V_4 -> V_125 = F_148 ( V_188 , 2 ) ;
if ( V_4 -> V_125 < 0 ) {
F_140 ( & V_188 -> V_127 , L_25 ) ;
V_192 = - V_194 ;
goto V_212;
}
#ifdef F_12
F_144 ( & V_4 -> V_86 ) ;
V_4 -> V_29 = 1 ;
V_4 -> V_25 = 0 ;
V_191 = F_145 ( V_188 , V_213 , 0 ) ;
if ( V_191 == NULL ) {
F_140 ( & V_188 -> V_127 , L_26 ) ;
V_192 = - V_194 ;
goto V_212;
}
V_4 -> V_23 = V_191 -> V_209 ;
V_191 = F_145 ( V_188 , V_213 , 1 ) ;
if ( V_191 == NULL ) {
F_140 ( & V_188 -> V_127 , L_27 ) ;
V_192 = - V_194 ;
goto V_212;
}
V_4 -> V_85 = V_191 -> V_209 ;
F_149 ( & ( V_4 -> V_90 ) ) ;
#endif
#if F_29 ( F_83 ) || \
F_29 ( F_7 )
V_191 = F_145 ( V_188 , V_214 , 0 ) ;
if ( V_191 == NULL )
V_4 -> V_5 = - 1 ;
else {
V_4 -> V_5 = V_191 -> V_209 ;
#ifdef F_83
V_4 -> V_2 . V_132 |= V_215 ;
#endif
}
V_191 = F_145 ( V_188 , V_214 , 1 ) ;
if ( V_191 == NULL )
V_4 -> V_10 = - 1 ;
else
V_4 -> V_10 = V_191 -> V_209 ;
#endif
}
#ifdef F_150
if ( ! F_151 ( V_188 ) ) {
#endif
V_4 = V_180 [ V_188 -> V_193 ] ;
V_4 -> V_2 . V_127 = & V_188 -> V_127 ;
F_152 ( & V_188 -> V_127 , V_4 ) ;
V_192 = F_153 ( & V_189 , & V_4 -> V_2 ) ;
#ifdef F_150
}
#endif
if ( ! V_192 )
return 0 ;
if ( V_4 ) {
V_212:
F_154 ( V_4 -> V_2 . V_197 ) ;
V_208:
F_155 (
( unsigned short * ) V_188 -> V_127 . V_198 ) ;
V_199:
F_156 ( V_4 ) ;
V_180 [ V_188 -> V_193 ] = NULL ;
}
return V_192 ;
}
static int T_7 F_157 ( struct V_187 * V_188 )
{
struct V_3 * V_4 = F_135 ( V_188 ) ;
F_152 ( & V_188 -> V_127 , NULL ) ;
if ( V_4 ) {
F_158 ( & V_189 , & V_4 -> V_2 ) ;
F_154 ( V_4 -> V_2 . V_197 ) ;
F_155 (
( unsigned short * ) V_188 -> V_127 . V_198 ) ;
F_156 ( V_4 ) ;
V_180 [ V_188 -> V_193 ] = NULL ;
}
return 0 ;
}
static int T_5 F_159 ( void )
{
F_160 ( & V_216 , V_124 ) ;
F_161 ( V_217 , V_184 , 0 ) ;
F_162 ( & V_218 ) ;
return 0 ;
}
static int F_163 ( struct V_187 * V_188 )
{
struct V_190 * V_191 ;
int V_192 ;
if ( V_188 -> V_193 < 0 || V_188 -> V_193 >= V_184 ) {
F_140 ( & V_188 -> V_127 , L_28 ) ;
return - V_194 ;
}
V_192 = F_143 (
( unsigned short * ) V_188 -> V_127 . V_198 , V_124 ) ;
if ( V_192 ) {
F_140 ( & V_188 -> V_127 ,
L_20 ) ;
return V_192 ;
}
V_191 = F_145 ( V_188 , V_207 , 0 ) ;
if ( V_191 == NULL ) {
F_140 ( & V_188 -> V_127 , L_21 ) ;
V_192 = - V_194 ;
goto V_208;
}
V_186 . V_2 . V_197 = F_146 ( V_191 -> V_209 ,
F_147 ( V_191 ) ) ;
if ( ! V_186 . V_2 . V_197 ) {
F_140 ( & V_188 -> V_127 , L_22 ) ;
V_192 = - V_210 ;
goto V_208;
}
V_186 . V_2 . V_211 = V_191 -> V_209 ;
V_186 . V_2 . line = V_188 -> V_193 ;
V_186 . V_2 . V_162 = F_124 () ;
V_186 . V_2 . V_200 = V_201 ;
F_144 ( & V_186 . V_2 . V_73 ) ;
return 0 ;
V_208:
F_155 (
( unsigned short * ) V_188 -> V_127 . V_198 ) ;
return V_192 ;
}
struct V_176 T_5 * F_164 ( unsigned int V_2 ,
unsigned int V_219 )
{
struct V_130 V_220 ;
char V_221 [ 20 ] ;
if ( V_2 < 0 || V_2 >= V_184 )
return NULL ;
snprintf ( V_221 , 20 , V_124 L_29 , V_2 ) ;
F_160 ( & V_222 ,
V_221 ) ;
F_161 ( V_223 , 1 , 0 ) ;
if ( ! V_186 . V_2 . V_197 )
return NULL ;
#ifdef F_150
V_218 . V_132 &= ~ V_224 ;
#endif
V_225 . V_181 = V_2 ;
V_220 . V_137 = V_219 ;
V_220 . V_155 = 0 ;
V_220 . V_226 = 0 ;
V_220 . V_227 = V_228 ;
V_220 . V_33 = V_2 ;
F_94 ( & V_186 . V_2 , & V_220 , & V_220 ) ;
return & V_225 ;
}
static int T_5 F_165 ( void )
{
int V_192 ;
F_85 ( L_30 ) ;
V_192 = F_166 ( & V_189 ) ;
if ( V_192 ) {
F_167 ( L_31 ,
V_189 . V_229 , V_192 ) ;
}
V_192 = F_168 ( & V_230 ) ;
if ( V_192 ) {
F_167 ( L_32 ) ;
F_169 ( & V_189 ) ;
}
return V_192 ;
}
static void T_8 F_170 ( void )
{
F_171 ( & V_230 ) ;
F_169 ( & V_189 ) ;
}

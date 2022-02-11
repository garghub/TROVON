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
unsigned int V_14 ;
V_14 = F_1 ( & V_4 -> V_2 ) ;
F_7 ( & V_4 -> V_2 , V_14 & V_6 ) ;
#ifdef F_8
V_4 -> V_15 = 1 ;
F_9 ( V_4 ) ;
F_10 ( V_4 , V_16 ) ;
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
#ifdef F_16
F_17 ( V_4 , V_29 ) ;
#endif
F_10 ( V_4 , V_30 ) ;
#endif
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_31 * V_32 = V_4 -> V_2 . V_20 -> V_2 . V_32 ;
#ifdef F_8
if ( V_4 -> V_15 && ! ( F_1 ( & V_4 -> V_2 ) & V_6 ) ) {
V_4 -> V_15 = 0 ;
F_7 ( & V_4 -> V_2 , V_4 -> V_15 ) ;
}
#endif
if ( V_32 -> V_33 -> V_34 == V_35 )
F_19 ( V_2 ) ;
#ifdef F_12
if ( V_4 -> V_28 )
F_20 ( V_4 ) ;
#else
F_21 ( V_4 , V_30 ) ;
F_22 ( V_4 ) ;
#endif
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
F_10 ( V_4 , V_36 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
}
static void F_25 ( struct V_3 * V_4 )
{
struct V_31 * V_32 = NULL ;
unsigned int V_14 , V_37 , V_38 ;
static struct V_39 V_40 = { . V_41 = 0 } ;
V_14 = F_13 ( V_4 ) ;
F_26 ( V_4 ) ;
V_37 = F_27 ( V_4 ) ;
V_4 -> V_2 . V_26 . V_42 ++ ;
#if F_28 ( V_43 ) || \
F_28 ( V_44 )
if ( V_45 && V_46 == V_4 -> V_2 . line
&& V_47 )
if ( V_37 == 0x3 ) {
F_29 () ;
return;
}
if ( ! V_4 -> V_2 . V_20 || ! V_4 -> V_2 . V_20 -> V_2 . V_32 )
return;
#endif
V_32 = V_4 -> V_2 . V_20 -> V_2 . V_32 ;
if ( V_48 ) {
if ( V_40 . V_41 ) {
struct V_39 V_49 ;
T_2 V_50 ;
if ( ( ~ V_37 & ( ~ V_37 + 1 ) ) & 0xff )
goto V_51;
F_30 ( & V_49 ) ;
if ( V_49 . V_41 - V_40 . V_41 > 1 )
goto V_51;
V_50 = 0 ;
if ( V_49 . V_41 != V_40 . V_41 )
V_50 += V_52 ;
V_50 += V_49 . V_53 - V_40 . V_53 ;
if ( V_50 > F_31 ( V_4 ) )
goto V_51;
if ( V_37 )
V_40 . V_41 = 0 ;
else
V_40 = V_49 ;
return;
V_51:
V_14 &= ~ V_54 ;
V_40 . V_41 = 0 ;
}
}
if ( V_14 & V_54 ) {
if ( V_48 )
if ( F_32 () < 5 )
F_30 ( & V_40 ) ;
V_4 -> V_2 . V_26 . V_55 ++ ;
if ( F_33 ( & V_4 -> V_2 ) )
goto V_56;
V_14 &= ~ ( V_57 | V_58 ) ;
}
if ( V_14 & V_57 )
V_4 -> V_2 . V_26 . V_59 ++ ;
if ( V_14 & V_60 )
V_4 -> V_2 . V_26 . V_61 ++ ;
if ( V_14 & V_58 )
V_4 -> V_2 . V_26 . V_62 ++ ;
V_14 &= V_4 -> V_2 . V_63 ;
if ( V_14 & V_54 )
V_38 = V_64 ;
else if ( V_14 & V_57 )
V_38 = V_65 ;
else if ( V_14 & V_58 )
V_38 = V_66 ;
else
V_38 = V_67 ;
if ( F_34 ( & V_4 -> V_2 , V_37 ) )
goto V_56;
F_35 ( & V_4 -> V_2 , V_14 , V_60 , V_37 , V_38 ) ;
V_56:
F_36 ( V_32 ) ;
}
static void F_22 ( struct V_3 * V_4 )
{
struct V_18 * V_19 = & V_4 -> V_2 . V_20 -> V_19 ;
if ( F_37 ( V_19 ) || F_38 ( & V_4 -> V_2 ) ) {
#ifdef F_16
F_17 ( V_4 , V_29 ) ;
#endif
F_10 ( V_4 , V_30 ) ;
return;
}
if ( V_4 -> V_2 . V_68 ) {
F_39 ( V_4 , V_4 -> V_2 . V_68 ) ;
V_4 -> V_2 . V_26 . V_27 ++ ;
V_4 -> V_2 . V_68 = 0 ;
}
while ( ( F_13 ( V_4 ) & V_69 ) && V_19 -> V_23 != V_19 -> V_70 ) {
F_39 ( V_4 , V_19 -> V_71 [ V_19 -> V_23 ] ) ;
V_19 -> V_23 = ( V_19 -> V_23 + 1 ) & ( V_25 - 1 ) ;
V_4 -> V_2 . V_26 . V_27 ++ ;
}
if ( F_40 ( V_19 ) < V_72 )
F_41 ( & V_4 -> V_2 ) ;
}
static T_1 F_42 ( int V_12 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
while ( F_13 ( V_4 ) & V_73 )
F_25 ( V_4 ) ;
return V_17 ;
}
static T_1 F_43 ( int V_12 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
#ifdef F_8
if ( V_4 -> V_15 && ! ( F_1 ( & V_4 -> V_2 ) & V_6 ) ) {
V_4 -> V_15 = 0 ;
F_7 ( & V_4 -> V_2 , V_4 -> V_15 ) ;
}
#endif
F_44 ( & V_4 -> V_2 . V_74 ) ;
if ( F_13 ( V_4 ) & V_69 )
F_22 ( V_4 ) ;
F_45 ( & V_4 -> V_2 . V_74 ) ;
return V_17 ;
}
static void F_20 ( struct V_3 * V_4 )
{
struct V_18 * V_19 = & V_4 -> V_2 . V_20 -> V_19 ;
V_4 -> V_28 = 0 ;
if ( F_37 ( V_19 ) || F_38 ( & V_4 -> V_2 ) ) {
V_4 -> V_24 = 0 ;
V_4 -> V_28 = 1 ;
return;
}
if ( V_4 -> V_2 . V_68 ) {
F_39 ( V_4 , V_4 -> V_2 . V_68 ) ;
V_4 -> V_2 . V_26 . V_27 ++ ;
V_4 -> V_2 . V_68 = 0 ;
}
V_4 -> V_24 = F_46 ( V_19 -> V_70 , V_19 -> V_23 , V_25 ) ;
if ( V_4 -> V_24 > ( V_25 - V_19 -> V_23 ) )
V_4 -> V_24 = V_25 - V_19 -> V_23 ;
F_47 ( ( unsigned long ) ( V_19 -> V_71 + V_19 -> V_23 ) ,
( unsigned long ) ( V_19 -> V_71 + V_19 -> V_23 + V_4 -> V_24 ) ) ;
F_48 ( V_4 -> V_22 ,
F_49 ( V_75 , V_76 ,
V_77 ,
V_78 ,
V_79 ,
V_80 ) ) ;
F_50 ( V_4 -> V_22 , ( unsigned long ) ( V_19 -> V_71 + V_19 -> V_23 ) ) ;
F_51 ( V_4 -> V_22 , V_4 -> V_24 ) ;
F_52 ( V_4 -> V_22 , 1 ) ;
F_53 () ;
F_54 ( V_4 -> V_22 ) ;
F_21 ( V_4 , V_30 ) ;
}
static void F_55 ( struct V_3 * V_4 )
{
struct V_31 * V_32 = V_4 -> V_2 . V_20 -> V_2 . V_32 ;
int V_81 , V_38 , V_14 ;
V_14 = F_13 ( V_4 ) ;
F_26 ( V_4 ) ;
V_4 -> V_2 . V_26 . V_42 +=
F_46 ( V_4 -> V_82 . V_70 , V_4 -> V_82 . V_23 ,
V_25 ) ;
if ( V_14 & V_54 ) {
V_4 -> V_2 . V_26 . V_55 ++ ;
if ( F_33 ( & V_4 -> V_2 ) )
goto V_83;
V_14 &= ~ ( V_57 | V_58 ) ;
}
if ( V_14 & V_57 )
V_4 -> V_2 . V_26 . V_59 ++ ;
if ( V_14 & V_60 )
V_4 -> V_2 . V_26 . V_61 ++ ;
if ( V_14 & V_58 )
V_4 -> V_2 . V_26 . V_62 ++ ;
V_14 &= V_4 -> V_2 . V_63 ;
if ( V_14 & V_54 )
V_38 = V_64 ;
else if ( V_14 & V_57 )
V_38 = V_65 ;
else if ( V_14 & V_58 )
V_38 = V_66 ;
else
V_38 = V_67 ;
for ( V_81 = V_4 -> V_82 . V_23 ; ; V_81 ++ ) {
if ( V_81 >= V_25 )
V_81 = 0 ;
if ( V_81 == V_4 -> V_82 . V_70 )
break;
if ( ! F_34 ( & V_4 -> V_2 , V_4 -> V_82 . V_71 [ V_81 ] ) )
F_35 ( & V_4 -> V_2 , V_14 , V_60 ,
V_4 -> V_82 . V_71 [ V_81 ] , V_38 ) ;
}
V_83:
F_36 ( V_32 ) ;
}
void F_56 ( struct V_3 * V_4 )
{
int V_84 , V_85 ;
F_57 ( V_4 -> V_86 ) ;
F_58 ( & V_4 -> V_87 ) ;
V_4 -> V_88 = F_59 ( V_4 -> V_86 ) ;
V_84 = F_60 ( V_4 -> V_86 ) ;
V_4 -> V_88 = V_89 - V_4 -> V_88 ;
if ( V_4 -> V_88 == V_89 || V_84 == 0 )
V_4 -> V_88 = 0 ;
V_84 = V_90 - V_84 ;
if ( V_84 == V_90 )
V_84 = 0 ;
V_85 = V_4 -> V_88 * V_90 + V_84 ;
if ( V_85 > V_4 -> V_82 . V_23 ||
V_4 -> V_88 < ( V_4 -> V_82 . V_23 / V_90 ) ) {
V_4 -> V_82 . V_70 = V_85 ;
F_55 ( V_4 ) ;
V_4 -> V_82 . V_23 = V_4 -> V_82 . V_70 ;
}
F_61 ( & V_4 -> V_87 ) ;
F_62 ( V_4 -> V_86 ) ;
F_63 ( & ( V_4 -> V_91 ) , V_92 + V_93 ) ;
}
static T_1 F_64 ( int V_12 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
struct V_18 * V_19 = & V_4 -> V_2 . V_20 -> V_19 ;
#ifdef F_8
if ( V_4 -> V_15 && ! ( F_1 ( & V_4 -> V_2 ) & V_6 ) ) {
V_4 -> V_15 = 0 ;
F_7 ( & V_4 -> V_2 , V_4 -> V_15 ) ;
}
#endif
F_44 ( & V_4 -> V_2 . V_74 ) ;
if ( ! ( F_65 ( V_4 -> V_22 ) & V_94 ) ) {
F_15 ( V_4 -> V_22 ) ;
F_66 ( V_4 -> V_22 ) ;
F_10 ( V_4 , V_30 ) ;
V_19 -> V_23 = ( V_19 -> V_23 + V_4 -> V_24 ) & ( V_25 - 1 ) ;
V_4 -> V_2 . V_26 . V_27 += V_4 -> V_24 ;
if ( F_40 ( V_19 ) < V_72 )
F_41 ( & V_4 -> V_2 ) ;
F_20 ( V_4 ) ;
}
F_45 ( & V_4 -> V_2 . V_74 ) ;
return V_17 ;
}
static T_1 F_67 ( int V_12 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
unsigned short V_95 ;
int V_84 , V_85 ;
F_44 ( & V_4 -> V_87 ) ;
V_95 = F_65 ( V_4 -> V_86 ) ;
F_66 ( V_4 -> V_86 ) ;
V_4 -> V_88 = F_59 ( V_4 -> V_86 ) ;
V_84 = F_60 ( V_4 -> V_86 ) ;
V_4 -> V_88 = V_89 - V_4 -> V_88 ;
if ( V_4 -> V_88 == V_89 || V_84 == 0 )
V_4 -> V_88 = 0 ;
V_85 = V_4 -> V_88 * V_90 ;
if ( V_85 > V_4 -> V_82 . V_23 ||
V_4 -> V_88 < ( V_4 -> V_82 . V_23 / V_90 ) ) {
V_4 -> V_82 . V_70 = V_85 ;
F_55 ( V_4 ) ;
V_4 -> V_82 . V_23 = V_4 -> V_82 . V_70 ;
}
F_45 ( & V_4 -> V_87 ) ;
return V_17 ;
}
static unsigned int F_68 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned short V_96 ;
V_96 = F_13 ( V_4 ) ;
if ( V_96 & V_21 )
return V_97 ;
else
return 0 ;
}
static void F_69 ( struct V_1 * V_2 , int V_98 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
T_3 V_99 = F_70 ( V_4 ) ;
if ( V_98 )
V_99 |= V_100 ;
else
V_99 &= ~ V_100 ;
F_71 ( V_4 , V_99 ) ;
F_53 () ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
#ifdef F_12
T_4 V_101 ;
if ( F_73 ( V_4 -> V_86 , L_1 ) < 0 ) {
F_74 ( V_102 L_2 ) ;
return - V_103 ;
}
if ( F_73 ( V_4 -> V_22 , L_3 ) < 0 ) {
F_74 ( V_102 L_4 ) ;
F_75 ( V_4 -> V_86 ) ;
return - V_103 ;
}
F_76 ( V_4 -> V_86 , F_67 , V_4 ) ;
F_76 ( V_4 -> V_22 , F_64 , V_4 ) ;
V_4 -> V_82 . V_71 = ( unsigned char * ) F_77 ( NULL , V_104 , & V_101 , V_105 ) ;
V_4 -> V_82 . V_70 = 0 ;
V_4 -> V_82 . V_23 = 0 ;
V_4 -> V_88 = 0 ;
F_48 ( V_4 -> V_86 ,
F_49 ( V_106 , V_107 ,
V_108 , V_109 ,
V_79 ,
V_80 ) ) ;
F_51 ( V_4 -> V_86 , V_90 ) ;
F_52 ( V_4 -> V_86 , 1 ) ;
F_78 ( V_4 -> V_86 , V_89 ) ;
F_79 ( V_4 -> V_86 , 1 ) ;
F_50 ( V_4 -> V_86 , ( unsigned long ) V_4 -> V_82 . V_71 ) ;
F_54 ( V_4 -> V_86 ) ;
V_4 -> V_91 . V_110 = ( unsigned long ) ( V_4 ) ;
V_4 -> V_91 . V_111 = ( void * ) F_56 ;
V_4 -> V_91 . V_112 = V_92 + V_93 ;
F_80 ( & ( V_4 -> V_91 ) ) ;
#else
# if F_28 ( V_43 ) || \
F_28 ( V_44 )
if ( V_46 == V_4 -> V_2 . line && V_47 )
V_47 = 0 ;
else {
# endif
if ( F_81 ( V_4 -> V_2 . V_12 , F_42 , V_113 ,
L_1 , V_4 ) ) {
F_74 ( V_102 L_5 ) ;
return - V_103 ;
}
if ( F_81
( V_4 -> V_2 . V_12 + 1 , F_43 , V_113 ,
L_3 , V_4 ) ) {
F_74 ( V_102 L_6 ) ;
F_82 ( V_4 -> V_2 . V_12 , V_4 ) ;
return - V_103 ;
}
# ifdef F_16
{
unsigned V_114 , V_115 ;
switch ( V_4 -> V_2 . V_12 ) {
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
F_74 ( V_102 L_7 ) ;
F_82 ( V_4 -> V_2 . V_12 , V_4 ) ;
F_82 ( V_4 -> V_2 . V_12 + 1 , V_4 ) ;
return - V_103 ;
}
if ( V_115 &&
F_73 ( V_115 , L_3 ) < 0 ) {
F_74 ( V_102 L_7 ) ;
F_75 ( V_114 ) ;
F_82 ( V_4 -> V_2 . V_12 , V_4 ) ;
F_82 ( V_4 -> V_2 . V_12 + 1 , V_4 ) ;
return - V_103 ;
}
}
# endif
# if F_28 ( V_43 ) || \
F_28 ( V_44 )
}
# endif
#endif
#ifdef F_83
if ( V_4 -> V_5 >= 0 ) {
if ( F_81 ( F_84 ( V_4 -> V_5 ) ,
F_6 ,
V_122 | V_123 |
V_113 , L_8 , V_4 ) ) {
V_4 -> V_5 = - 1 ;
F_85 ( L_9 ) ;
}
}
if ( V_4 -> V_10 >= 0 ) {
F_86 ( V_4 -> V_10 , 0 ) ;
}
#endif
#ifdef F_8
if ( V_4 -> V_5 >= 0 && F_81 ( V_4 -> V_124 ,
F_6 ,
V_113 , L_10 , V_4 ) ) {
V_4 -> V_5 = - 1 ;
F_85 ( L_11 ) ;
}
F_87 ( V_4 , V_125 ) ;
F_21 ( V_4 , V_16 ) ;
#endif
F_21 ( V_4 , V_36 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
#ifdef F_12
F_15 ( V_4 -> V_22 ) ;
F_75 ( V_4 -> V_22 ) ;
F_15 ( V_4 -> V_86 ) ;
F_75 ( V_4 -> V_86 ) ;
F_89 ( & ( V_4 -> V_91 ) ) ;
F_90 ( NULL , V_104 , V_4 -> V_82 . V_71 , 0 ) ;
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
F_82 ( V_4 -> V_2 . V_12 , V_4 ) ;
F_82 ( V_4 -> V_2 . V_12 + 1 , V_4 ) ;
#endif
#ifdef F_83
if ( V_4 -> V_5 >= 0 )
F_82 ( F_84 ( V_4 -> V_5 ) , V_4 ) ;
#endif
#ifdef F_8
if ( V_4 -> V_5 >= 0 )
F_82 ( V_4 -> V_124 , V_4 ) ;
#endif
}
static void
F_91 ( struct V_1 * V_2 , struct V_126 * V_33 ,
struct V_126 * V_127 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned long V_128 ;
unsigned int V_129 , V_130 ;
unsigned short V_131 , V_132 , V_99 = 0 ;
switch ( V_33 -> V_133 & V_134 ) {
case V_135 :
V_99 = F_92 ( 8 ) ;
break;
case V_136 :
V_99 = F_92 ( 7 ) ;
break;
case V_137 :
V_99 = F_92 ( 6 ) ;
break;
case V_138 :
V_99 = F_92 ( 5 ) ;
break;
default:
F_74 ( V_139 L_12 ,
V_140 ) ;
}
if ( V_33 -> V_133 & V_141 ) {
if ( V_142 )
F_74 ( V_143 L_13
L_14 ) ;
else
V_99 |= V_144 ;
}
if ( V_33 -> V_133 & V_145 )
V_99 |= V_146 ;
if ( ! ( V_33 -> V_133 & V_147 ) )
V_99 |= V_148 ;
if ( V_33 -> V_133 & V_149 )
V_99 |= V_150 ;
F_93 ( & V_4 -> V_2 . V_74 , V_128 ) ;
V_2 -> V_63 = V_60 ;
if ( V_33 -> V_151 & V_152 )
V_2 -> V_63 |= ( V_58 | V_57 ) ;
if ( V_33 -> V_151 & ( V_153 | V_154 ) )
V_2 -> V_63 |= V_54 ;
V_2 -> V_155 = 0 ;
if ( V_33 -> V_151 & V_156 )
V_2 -> V_155 |= V_58 | V_57 ;
if ( V_33 -> V_151 & V_157 ) {
V_2 -> V_155 |= V_54 ;
if ( V_33 -> V_151 & V_156 )
V_2 -> V_155 |= V_60 ;
}
V_129 = F_94 ( V_2 , V_33 , V_127 , 0 , V_2 -> V_158 / 16 ) ;
V_130 = F_95 ( V_2 , V_129 ) ;
if ( V_33 -> V_34 != V_35 )
V_130 -= V_159 ;
F_96 ( V_4 , V_52 / V_129 * 15 ) ;
V_132 = F_97 ( V_4 ) ;
F_98 ( V_4 ) ;
F_99 ( V_4 ) ;
F_100 ( V_4 , V_130 & 0xFF ) ;
F_101 ( V_4 , ( V_130 >> 8 ) & 0xFF ) ;
F_53 () ;
F_102 ( V_4 ) ;
F_71 ( V_4 , V_99 ) ;
F_103 ( V_4 , V_132 ) ;
V_131 = F_104 ( V_4 ) ;
V_131 |= V_160 ;
F_105 ( V_4 , V_131 ) ;
F_106 ( V_2 , V_33 -> V_133 , V_129 ) ;
F_107 ( & V_4 -> V_2 . V_74 , V_128 ) ;
}
static const char * F_108 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
return V_4 -> V_2 . type == V_161 ? L_15 : NULL ;
}
static void F_109 ( struct V_1 * V_2 )
{
}
static int F_110 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_111 ( struct V_1 * V_2 , int V_128 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( V_128 & V_162 &&
F_110 ( & V_4 -> V_2 ) == 0 )
V_4 -> V_2 . type = V_161 ;
}
static int
F_112 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
return 0 ;
}
static void F_113 ( struct V_1 * V_2 , int V_165 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned short V_131 ;
switch ( V_165 ) {
case V_35 :
V_131 = F_104 ( V_4 ) ;
V_131 |= ( V_166 | V_167 ) ;
F_105 ( V_4 , V_131 ) ;
break;
default:
V_131 = F_104 ( V_4 ) ;
V_131 &= ~ ( V_166 | V_167 ) ;
F_105 ( V_4 , V_131 ) ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned short V_131 ;
V_131 = F_104 ( V_4 ) ;
V_131 &= ~ ( V_166 | V_167 ) ;
F_105 ( V_4 , V_131 ) ;
F_53 () ;
V_131 |= ( V_166 | V_167 ) ;
F_105 ( V_4 , V_131 ) ;
F_53 () ;
}
static void F_114 ( struct V_1 * V_2 , unsigned char V_168 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
while ( ! ( F_13 ( V_4 ) & V_69 ) )
F_14 () ;
F_102 ( V_4 ) ;
F_39 ( V_4 , ( unsigned char ) V_168 ) ;
}
static int F_115 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned char V_168 ;
while ( ! ( F_13 ( V_4 ) & V_73 ) )
F_14 () ;
F_102 ( V_4 ) ;
V_168 = F_27 ( V_4 ) ;
return V_168 ;
}
static void F_116 ( struct V_1 * V_2 )
{
if ( V_47 ) {
V_47 = 0 ;
F_88 ( V_2 ) ;
}
}
static int F_117 ( struct V_1 * V_2 )
{
V_46 = V_2 -> line ;
V_47 = ! F_72 ( V_2 ) ;
return 0 ;
}
static void T_5
F_118 ( struct V_3 * V_4 , int * V_129 ,
int * V_59 , int * V_169 )
{
unsigned short V_14 ;
V_14 = F_97 ( V_4 ) & ( V_36 | V_30 ) ;
if ( V_14 == ( V_36 | V_30 ) ) {
T_3 V_99 , V_170 , V_171 ;
V_99 = F_70 ( V_4 ) ;
* V_59 = 'n' ;
if ( V_99 & V_146 ) {
if ( V_99 & V_148 )
* V_59 = 'e' ;
else
* V_59 = 'o' ;
}
switch ( V_99 & 0x03 ) {
case 0 : * V_169 = 5 ; break;
case 1 : * V_169 = 6 ; break;
case 2 : * V_169 = 7 ; break;
case 3 : * V_169 = 8 ; break;
}
F_99 ( V_4 ) ;
V_171 = F_119 ( V_4 ) ;
V_170 = F_120 ( V_4 ) ;
F_102 ( V_4 ) ;
* V_129 = F_121 () / ( 16 * ( V_171 | V_170 << 8 ) ) ;
}
F_122 ( L_16 , V_140 , * V_129 , * V_59 , * V_169 ) ;
}
static void F_123 ( struct V_1 * V_2 , int V_37 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
while ( ! ( F_13 ( V_4 ) & V_69 ) )
F_124 () ;
F_39 ( V_4 , V_37 ) ;
}
static void
F_125 ( struct V_172 * V_173 , const char * V_174 , unsigned int V_175 )
{
struct V_3 * V_4 = V_176 [ V_173 -> V_177 ] ;
unsigned long V_128 ;
F_93 ( & V_4 -> V_2 . V_74 , V_128 ) ;
F_126 ( & V_4 -> V_2 , V_174 , V_175 , F_123 ) ;
F_107 ( & V_4 -> V_2 . V_74 , V_128 ) ;
}
static int T_5
F_127 ( struct V_172 * V_173 , char * V_178 )
{
struct V_3 * V_4 ;
int V_129 = 57600 ;
int V_169 = 8 ;
int V_59 = 'n' ;
# if F_28 ( F_83 ) || \
F_28 ( F_8 )
int V_179 = 'r' ;
# else
int V_179 = 'n' ;
# endif
if ( V_173 -> V_177 < 0 || V_173 -> V_177 >= V_180 )
return - V_181 ;
V_4 = V_176 [ V_173 -> V_177 ] ;
if ( ! V_4 )
return - V_181 ;
if ( V_178 )
F_128 ( V_178 , & V_129 , & V_59 , & V_169 , & V_179 ) ;
else
F_118 ( V_4 , & V_129 , & V_59 , & V_169 ) ;
return F_129 ( & V_4 -> V_2 , V_173 , V_129 , V_59 , V_169 , V_179 ) ;
}
static void
F_130 ( struct V_172 * V_173 , const char * V_174 , unsigned int V_175 )
{
unsigned long V_128 ;
if ( V_182 . V_2 . line != V_173 -> V_177 )
return;
F_93 ( & V_182 . V_2 . V_74 , V_128 ) ;
F_126 ( & V_182 . V_2 , V_174 , V_175 ,
F_123 ) ;
F_107 ( & V_182 . V_2 . V_74 , V_128 ) ;
}
static int F_131 ( struct V_183 * V_184 , T_6 V_20 )
{
struct V_3 * V_4 = F_132 ( V_184 ) ;
return F_133 ( & V_185 , & V_4 -> V_2 ) ;
}
static int F_134 ( struct V_183 * V_184 )
{
struct V_3 * V_4 = F_132 ( V_184 ) ;
return F_135 ( & V_185 , & V_4 -> V_2 ) ;
}
static int F_136 ( struct V_183 * V_184 )
{
struct V_186 * V_187 ;
struct V_3 * V_4 = NULL ;
int V_188 = 0 ;
if ( V_184 -> V_189 < 0 || V_184 -> V_189 >= V_180 ) {
F_137 ( & V_184 -> V_190 , L_17 ) ;
return - V_191 ;
}
if ( V_176 [ V_184 -> V_189 ] == NULL ) {
V_4 = F_138 ( sizeof( * V_4 ) , V_192 ) ;
if ( ! V_4 ) {
F_137 ( & V_184 -> V_190 ,
L_18 ) ;
return - V_193 ;
}
V_176 [ V_184 -> V_189 ] = V_4 ;
#ifdef F_139
if ( ! ( V_182 . V_2 . V_194
&& V_182 . V_2 . line == V_184 -> V_189 ) ) {
#endif
V_188 = F_140 (
( unsigned short * ) V_184 -> V_190 . V_195 , V_196 ) ;
if ( V_188 ) {
F_137 ( & V_184 -> V_190 ,
L_19 ) ;
goto V_197;
}
#ifdef F_139
}
#endif
F_141 ( & V_4 -> V_2 . V_74 ) ;
V_4 -> V_2 . V_158 = F_121 () ;
V_4 -> V_2 . V_198 = V_199 ;
V_4 -> V_2 . V_200 = & V_201 ;
V_4 -> V_2 . line = V_184 -> V_189 ;
V_4 -> V_2 . V_202 = V_203 ;
V_4 -> V_2 . V_128 = V_204 ;
V_187 = F_142 ( V_184 , V_205 , 0 ) ;
if ( V_187 == NULL ) {
F_137 ( & V_184 -> V_190 , L_20 ) ;
V_188 = - V_191 ;
goto V_206;
}
V_4 -> V_2 . V_194 = F_143 ( V_187 -> V_207 , F_144 ( V_187 ) ) ;
if ( ! V_4 -> V_2 . V_194 ) {
F_137 ( & V_184 -> V_190 , L_21 ) ;
V_188 = - V_208 ;
goto V_206;
}
V_4 -> V_2 . V_209 = V_187 -> V_207 ;
V_4 -> V_2 . V_12 = F_145 ( V_184 , 0 ) ;
if ( V_4 -> V_2 . V_12 < 0 ) {
F_137 ( & V_184 -> V_190 , L_22 ) ;
V_188 = - V_191 ;
goto V_210;
}
V_4 -> V_124 = F_145 ( V_184 , 1 ) ;
if ( V_4 -> V_124 < 0 ) {
F_137 ( & V_184 -> V_190 , L_23 ) ;
V_188 = - V_191 ;
goto V_210;
}
#ifdef F_12
F_141 ( & V_4 -> V_87 ) ;
V_4 -> V_28 = 1 ;
V_4 -> V_24 = 0 ;
V_187 = F_142 ( V_184 , V_211 , 0 ) ;
if ( V_187 == NULL ) {
F_137 ( & V_184 -> V_190 , L_24 ) ;
V_188 = - V_191 ;
goto V_210;
}
V_4 -> V_22 = V_187 -> V_207 ;
V_187 = F_142 ( V_184 , V_211 , 1 ) ;
if ( V_187 == NULL ) {
F_137 ( & V_184 -> V_190 , L_25 ) ;
V_188 = - V_191 ;
goto V_210;
}
V_4 -> V_86 = V_187 -> V_207 ;
F_146 ( & ( V_4 -> V_91 ) ) ;
#endif
#if F_28 ( F_83 ) || \
F_28 ( F_8 )
V_187 = F_142 ( V_184 , V_212 , 0 ) ;
if ( V_187 == NULL )
V_4 -> V_5 = - 1 ;
else
V_4 -> V_5 = V_187 -> V_207 ;
V_187 = F_142 ( V_184 , V_212 , 1 ) ;
if ( V_187 == NULL )
V_4 -> V_10 = - 1 ;
else
V_4 -> V_10 = V_187 -> V_207 ;
# if F_28 ( F_83 )
if ( V_4 -> V_10 >= 0 )
F_147 ( V_4 -> V_10 , V_196 ) ;
# endif
#endif
}
#ifdef F_148
if ( ! F_149 ( V_184 ) ) {
#endif
V_4 = V_176 [ V_184 -> V_189 ] ;
V_4 -> V_2 . V_190 = & V_184 -> V_190 ;
F_150 ( & V_184 -> V_190 , V_4 ) ;
V_188 = F_151 ( & V_185 , & V_4 -> V_2 ) ;
#ifdef F_148
}
#endif
if ( ! V_188 )
return 0 ;
if ( V_4 ) {
V_210:
F_152 ( V_4 -> V_2 . V_194 ) ;
V_206:
F_153 (
( unsigned short * ) V_184 -> V_190 . V_195 ) ;
V_197:
F_154 ( V_4 ) ;
V_176 [ V_184 -> V_189 ] = NULL ;
}
return V_188 ;
}
static int T_7 F_155 ( struct V_183 * V_184 )
{
struct V_3 * V_4 = F_132 ( V_184 ) ;
F_150 ( & V_184 -> V_190 , NULL ) ;
if ( V_4 ) {
F_156 ( & V_185 , & V_4 -> V_2 ) ;
#ifdef F_83
if ( V_4 -> V_10 >= 0 )
F_157 ( V_4 -> V_10 ) ;
#endif
F_152 ( V_4 -> V_2 . V_194 ) ;
F_153 (
( unsigned short * ) V_184 -> V_190 . V_195 ) ;
F_154 ( V_4 ) ;
V_176 [ V_184 -> V_189 ] = NULL ;
}
return 0 ;
}
static int T_5 F_158 ( void )
{
F_159 ( & V_213 , V_196 ) ;
F_160 ( V_214 , V_180 , 0 ) ;
F_161 ( & V_215 ) ;
return 0 ;
}
static int F_162 ( struct V_183 * V_184 )
{
struct V_186 * V_187 ;
int V_188 ;
if ( V_184 -> V_189 < 0 || V_184 -> V_189 >= V_180 ) {
F_137 ( & V_184 -> V_190 , L_26 ) ;
return - V_191 ;
}
V_188 = F_140 (
( unsigned short * ) V_184 -> V_190 . V_195 , V_196 ) ;
if ( V_188 ) {
F_137 ( & V_184 -> V_190 ,
L_19 ) ;
return V_188 ;
}
V_187 = F_142 ( V_184 , V_205 , 0 ) ;
if ( V_187 == NULL ) {
F_137 ( & V_184 -> V_190 , L_20 ) ;
V_188 = - V_191 ;
goto V_206;
}
V_182 . V_2 . V_194 = F_143 ( V_187 -> V_207 ,
F_144 ( V_187 ) ) ;
if ( ! V_182 . V_2 . V_194 ) {
F_137 ( & V_184 -> V_190 , L_21 ) ;
V_188 = - V_208 ;
goto V_206;
}
V_182 . V_2 . V_209 = V_187 -> V_207 ;
V_182 . V_2 . line = V_184 -> V_189 ;
V_182 . V_2 . V_158 = F_121 () ;
V_182 . V_2 . V_198 = V_199 ;
F_141 ( & V_182 . V_2 . V_74 ) ;
return 0 ;
V_206:
F_153 (
( unsigned short * ) V_184 -> V_190 . V_195 ) ;
return V_188 ;
}
struct V_172 T_5 * F_163 ( unsigned int V_2 ,
unsigned int V_216 )
{
struct V_126 V_217 ;
char V_218 [ 20 ] ;
if ( V_2 < 0 || V_2 >= V_180 )
return NULL ;
snprintf ( V_218 , 20 , V_196 L_27 , V_2 ) ;
F_159 ( & V_219 ,
V_218 ) ;
F_160 ( V_220 , 1 , 0 ) ;
if ( ! V_182 . V_2 . V_194 )
return NULL ;
#ifdef F_148
V_215 . V_128 &= ~ V_221 ;
#endif
V_222 . V_177 = V_2 ;
V_217 . V_133 = V_216 ;
V_217 . V_151 = 0 ;
V_217 . V_223 = 0 ;
V_217 . V_224 = V_225 ;
V_217 . V_34 = V_2 ;
F_91 ( & V_182 . V_2 , & V_217 , & V_217 ) ;
return & V_222 ;
}
static int T_5 F_164 ( void )
{
int V_188 ;
F_85 ( L_28 ) ;
V_188 = F_165 ( & V_185 ) ;
if ( V_188 ) {
F_166 ( L_29 ,
V_185 . V_226 , V_188 ) ;
}
V_188 = F_167 ( & V_227 ) ;
if ( V_188 ) {
F_166 ( L_30 ) ;
F_168 ( & V_185 ) ;
}
return V_188 ;
}
static void T_8 F_169 ( void )
{
F_170 ( & V_227 ) ;
F_168 ( & V_185 ) ;
}

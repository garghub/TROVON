static inline unsigned F_1 ( unsigned V_1 )
{
switch ( V_1 ) {
case 0 :
return V_2 ;
break;
case 1 :
return V_3 ;
break;
default:
break;
}
F_2 () ;
return V_2 ;
}
static inline void F_3 ( struct V_4 * V_5 , int V_6 ,
unsigned V_7 , unsigned V_8 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_12 ;
F_4 ( & V_10 -> V_13 , V_12 ) ;
switch ( V_6 ) {
case V_14 :
V_10 -> V_15 &= ~ V_7 ;
V_10 -> V_15 |= V_8 & V_7 ;
V_10 -> V_16 ( V_5 , V_10 -> V_15 ,
V_14 ) ;
break;
case V_17 :
V_10 -> V_18 &= ~ V_7 ;
V_10 -> V_18 |= V_8 & V_7 ;
V_10 -> V_16 ( V_5 , V_10 -> V_18 ,
V_17 ) ;
break;
case V_19 :
V_10 -> V_20 &= ~ V_7 ;
V_10 -> V_20 |= V_8 & V_7 ;
V_10 -> V_16 ( V_5 , V_10 -> V_20 ,
V_19 ) ;
break;
case V_21 :
V_10 -> V_22 &= ~ V_7 ;
V_10 -> V_22 |= V_8 & V_7 ;
F_5 ( V_10 -> V_22 , V_21 ) ;
break;
case V_23 :
V_10 -> V_24 &= ~ V_7 ;
V_10 -> V_24 |= V_8 & V_7 ;
F_5 ( V_10 -> V_24 , V_23 ) ;
break;
default:
F_6 ( L_1 , V_25 ) ;
F_6 ( L_2 , V_6 ) ;
break;
}
F_7 () ;
F_8 ( & V_10 -> V_13 , V_12 ) ;
}
static inline void F_9 ( struct V_4 * V_5 , int V_26 )
{
unsigned V_27 ;
if ( V_26 >= 0 ) {
V_27 =
( F_10 ( V_26 ) <<
V_28 ) & V_29 ;
} else {
V_27 = 0 ;
}
F_3 ( V_5 , V_21 , V_29 , V_27 ) ;
}
static inline void F_11 ( struct V_4 * V_5 , int V_26 )
{
unsigned V_27 ;
if ( V_26 >= 0 ) {
V_27 =
( F_10 ( V_26 ) <<
V_30 ) & V_31 ;
} else {
V_27 = 0 ;
}
F_3 ( V_5 , V_21 , V_31 , V_27 ) ;
}
static inline void F_12 ( struct V_4 * V_5 ,
unsigned V_32 ,
int V_33 )
{
unsigned V_27 ;
if ( V_33 >= 0 )
V_27 = F_13 ( V_32 , V_33 ) ;
else
V_27 = 0 ;
F_3 ( V_5 , V_23 , F_14 ( V_32 ) ,
V_27 ) ;
}
static inline void F_15 ( struct V_4 * V_5 ,
int V_33 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_12 ;
F_4 ( & V_10 -> V_13 , V_12 ) ;
V_10 -> V_34 &= ~ V_35 ;
if ( V_33 >= 0 ) {
V_10 -> V_34 |=
( F_10 ( V_33 ) <<
V_36 ) & V_35 ;
}
F_5 ( V_10 -> V_34 , V_37 ) ;
F_7 () ;
F_8 ( & V_10 -> V_13 , V_12 ) ;
}
static int F_16 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_12 ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
F_17 ( V_10 -> V_39 ) ;
V_10 -> V_39 =
F_18 ( V_10 -> V_40 , V_10 -> V_41 ) ;
if ( V_10 -> V_39 == NULL ) {
F_8 ( & V_10 -> V_38 , V_12 ) ;
F_19 ( V_5 ,
L_3 ) ;
return - V_42 ;
}
V_10 -> V_39 -> V_43 = V_44 ;
F_9 ( V_5 , V_10 -> V_39 -> V_26 ) ;
F_8 ( & V_10 -> V_38 , V_12 ) ;
return 0 ;
}
static int F_20 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_12 ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
F_17 ( V_10 -> V_45 ) ;
V_10 -> V_45 =
F_18 ( V_10 -> V_40 , V_10 -> V_46 ) ;
if ( V_10 -> V_45 == NULL ) {
F_8 ( & V_10 -> V_38 , V_12 ) ;
F_19 ( V_5 ,
L_4 ) ;
return - V_42 ;
}
V_10 -> V_45 -> V_43 = V_47 ;
F_11 ( V_5 , V_10 -> V_45 -> V_26 ) ;
F_8 ( & V_10 -> V_38 , V_12 ) ;
return 0 ;
}
static int F_21 ( struct V_4 * V_5 ,
unsigned V_32 ,
enum V_48 V_49 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_12 ;
struct V_33 * V_50 ;
F_17 ( V_32 >= V_51 ) ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
F_17 ( V_10 -> V_52 -> V_53 [ V_32 ] . V_50 ) ;
V_50 =
F_18 ( V_10 -> V_40 ,
V_10 -> V_54 [ V_32 ] ) ;
if ( V_50 == NULL ) {
F_8 ( & V_10 -> V_38 , V_12 ) ;
F_19 ( V_5 ,
L_5 ) ;
return - V_42 ;
}
V_50 -> V_43 = V_49 ;
F_22 ( & V_10 -> V_52 -> V_53 [ V_32 ] ,
V_50 ) ;
F_12 ( V_5 , V_32 , V_50 -> V_26 ) ;
F_8 ( & V_10 -> V_38 , V_12 ) ;
return 0 ;
}
static int F_23 ( struct V_4 * V_5 )
{
#ifdef F_24
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_12 ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
F_17 ( V_10 -> V_55 ) ;
V_10 -> V_55 =
F_18 ( V_10 -> V_40 , V_10 -> V_56 ) ;
if ( V_10 -> V_55 == NULL ) {
F_8 ( & V_10 -> V_38 , V_12 ) ;
F_19 ( V_5 ,
L_6 ) ;
return - V_42 ;
}
V_10 -> V_55 -> V_43 = V_47 ;
F_15 ( V_5 , V_10 -> V_55 -> V_26 ) ;
F_8 ( & V_10 -> V_38 , V_12 ) ;
#endif
return 0 ;
}
static void F_25 ( struct V_4 * V_5 )
{
#ifdef F_24
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_12 ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_39 ) {
F_9 ( V_5 , - 1 ) ;
F_26 ( V_10 -> V_39 ) ;
V_10 -> V_39 = NULL ;
}
F_8 ( & V_10 -> V_38 , V_12 ) ;
#endif
}
static void F_27 ( struct V_4 * V_5 )
{
#ifdef F_24
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_12 ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_45 ) {
F_11 ( V_5 , - 1 ) ;
F_26 ( V_10 -> V_45 ) ;
V_10 -> V_45 = NULL ;
}
F_8 ( & V_10 -> V_38 , V_12 ) ;
#endif
}
static void F_28 ( struct V_4 * V_5 ,
unsigned V_32 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_12 ;
F_17 ( V_32 >= V_51 ) ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_52 -> V_53 [ V_32 ] . V_50 ) {
struct V_33 * V_50 =
V_10 -> V_52 -> V_53 [ V_32 ] . V_50 ;
F_12 ( V_5 , V_32 , - 1 ) ;
F_22 ( & V_10 ->
V_52 -> V_53 [ V_32 ] ,
NULL ) ;
F_26 ( V_50 ) ;
}
F_8 ( & V_10 -> V_38 , V_12 ) ;
}
static void F_29 ( struct V_4 * V_5 )
{
#ifdef F_24
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_12 ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_55 ) {
F_15 ( V_5 , - 1 ) ;
F_26 ( V_10 -> V_55 ) ;
V_10 -> V_55 = NULL ;
}
F_8 ( & V_10 -> V_38 , V_12 ) ;
#endif
}
static void F_30 ( struct V_4 * V_5 ,
unsigned V_32 , short V_57 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_59 -> V_60 & V_61 )
return;
switch ( V_32 ) {
case 0 :
if ( V_57 ) {
V_10 -> V_16 ( V_5 , V_62 ,
V_63 ) ;
} else {
V_10 -> V_16 ( V_5 , 0 ,
V_63 ) ;
}
break;
case 1 :
if ( V_57 ) {
V_10 -> V_16 ( V_5 , V_64 ,
V_65 ) ;
} else {
V_10 -> V_16 ( V_5 , 0 ,
V_65 ) ;
}
break;
default:
F_2 () ;
break;
}
}
static void F_32 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
static const int V_66 = 10000 ;
int V_67 ;
if ( V_59 -> V_60 == V_68 ) {
F_33 ( 0x10 , V_69 ) ;
F_33 ( 0x00 , V_69 ) ;
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
if ( ! ( F_34 ( V_70 ) & 0x10 ) )
break;
F_35 ( 1 ) ;
}
if ( V_67 == V_66 ) {
F_19 ( V_5 , L_7 ) ;
}
} else {
V_10 -> V_16 ( V_5 , 1 , V_71 ) ;
if ( V_59 -> V_60 == V_72 ) {
F_5 ( 0 , F_36 ( 0 ) ) ;
F_5 ( 1 , F_36 ( 0 ) ) ;
#if 0
devpriv->stc_writew(dev, AI_CONVERT_Pulse,
AI_Command_1_Register);
devpriv->stc_writew(dev, AI_CONVERT_Pulse,
AI_Command_1_Register);
devpriv->stc_writew(dev, AI_CONVERT_Pulse,
AI_Command_1_Register);
#endif
}
}
}
static void F_37 ( struct V_4 * V_5 , T_1 V_73 , int V_6 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_10 -> V_16 ( V_5 , V_73 >> 16 , V_6 ) ;
V_10 -> V_16 ( V_5 , V_73 & 0xffff , V_6 + 1 ) ;
}
static T_1 F_38 ( struct V_4 * V_5 , int V_6 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
T_1 V_74 ;
V_74 = V_10 -> V_75 ( V_5 , V_6 ) << 16 ;
V_74 |= V_10 -> V_75 ( V_5 , V_6 + 1 ) ;
return V_74 ;
}
static inline void F_39 ( struct V_4 * V_5 , T_2 V_73 ,
int V_76 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_12 ;
F_4 ( & V_10 -> V_77 , V_12 ) ;
F_40 ( V_76 , V_78 ) ;
F_40 ( V_73 , V_79 ) ;
F_8 ( & V_10 -> V_77 , V_12 ) ;
}
static inline void F_41 ( struct V_4 * V_5 , T_1 V_73 ,
int V_76 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_12 ;
F_4 ( & V_10 -> V_77 , V_12 ) ;
F_40 ( V_76 , V_78 ) ;
F_33 ( V_73 , V_79 ) ;
F_8 ( & V_10 -> V_77 , V_12 ) ;
}
static inline unsigned short F_42 ( struct V_4 * V_5 , int V_76 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_12 ;
unsigned short V_73 ;
F_4 ( & V_10 -> V_77 , V_12 ) ;
F_40 ( V_76 , V_78 ) ;
V_73 = F_43 ( V_79 ) ;
F_8 ( & V_10 -> V_77 , V_12 ) ;
return V_73 ;
}
static inline void F_44 ( struct V_4 * V_5 , int V_6 ,
unsigned V_74 , unsigned V_80 )
{
unsigned V_8 ;
if ( V_80 )
V_8 = V_74 ;
else
V_8 = 0 ;
F_3 ( V_5 , V_6 , V_74 , V_8 ) ;
}
static T_3 F_45 ( int V_81 , void * V_82 )
{
struct V_4 * V_5 = V_82 ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned short V_83 ;
unsigned short V_84 ;
unsigned int V_85 = 0 ;
unsigned int V_86 = 0 ;
unsigned long V_12 ;
#ifdef F_24
struct V_87 * V_40 = V_10 -> V_40 ;
#endif
if ( ! V_5 -> V_88 )
return V_89 ;
F_46 () ;
F_4 ( & V_5 -> V_90 , V_12 ) ;
V_83 = V_10 -> V_75 ( V_5 , V_91 ) ;
V_84 = V_10 -> V_75 ( V_5 , V_92 ) ;
#ifdef F_24
if ( V_40 ) {
unsigned long V_93 ;
F_4 ( & V_10 -> V_38 , V_93 ) ;
if ( V_10 -> V_39 ) {
V_85 = F_47 ( V_10 -> V_39 ) ;
if ( V_85 & V_94 )
F_48 ( V_95 ,
V_10 -> V_40 -> V_96 +
F_49 ( V_10 ->
V_39 -> V_26 ) ) ;
}
if ( V_10 -> V_45 ) {
V_86 = F_47 ( V_10 -> V_45 ) ;
if ( V_86 & V_94 )
F_48 ( V_95 ,
V_40 -> V_96 +
F_49 ( V_10 ->
V_45 -> V_26 ) ) ;
}
F_8 ( & V_10 -> V_38 , V_93 ) ;
}
#endif
F_50 ( V_5 , V_83 ) ;
F_51 ( V_5 , V_84 ) ;
if ( ( V_83 & V_97 ) || ( V_85 & V_98 ) )
F_52 ( V_5 , V_83 , V_85 ) ;
if ( ( V_84 & V_99 ) || ( V_86 & V_98 ) )
F_53 ( V_5 , V_84 , V_86 ) ;
F_54 ( V_5 , 0 ) ;
F_54 ( V_5 , 1 ) ;
F_55 ( V_5 ) ;
F_8 ( & V_5 -> V_90 , V_12 ) ;
return V_100 ;
}
static void F_56 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_101 * V_102 = & V_5 -> V_103 [ V_104 ] ;
unsigned long V_12 ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_39 )
F_57 ( V_10 -> V_39 , V_102 -> V_105 ) ;
F_8 ( & V_10 -> V_38 , V_12 ) ;
}
static void F_58 ( struct V_87 * V_40 ,
struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_101 * V_102 = & V_5 -> V_103 [ V_106 ] ;
unsigned long V_12 ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_45 )
F_59 ( V_10 -> V_45 , V_102 -> V_105 ) ;
F_8 ( & V_10 -> V_38 , V_12 ) ;
}
static int F_60 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
static const int V_66 = 10000 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
unsigned short V_84 ;
V_84 = V_10 -> V_75 ( V_5 , V_92 ) ;
if ( V_84 & V_107 )
break;
F_35 ( 10 ) ;
}
if ( V_67 == V_66 ) {
F_19 ( V_5 , L_8 ) ;
return - V_108 ;
}
return 0 ;
}
static void F_61 ( struct V_4 * V_5 , struct V_101 * V_102 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_10 -> V_109 == V_110 ) {
#ifdef F_24
static const int V_66 = 10 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
F_56 ( V_5 ) ;
if ( ( V_102 -> V_105 -> V_111 & V_112 ) )
break;
F_35 ( 1 ) ;
}
#else
F_62 ( V_5 ) ;
V_102 -> V_105 -> V_111 |= V_112 ;
#endif
}
if ( ( V_10 -> V_113 & V_114 ) )
F_63 ( V_5 ) ;
}
static void F_63 ( struct V_4 * V_5 )
{
struct V_101 * V_102 = & V_5 -> V_103 [ V_104 ] ;
#ifdef F_24
F_64 ( V_5 ) ;
#endif
F_62 ( V_5 ) ;
F_65 ( V_5 ) ;
F_66 ( V_5 ) ;
V_102 -> V_105 -> V_111 |= V_115 ;
}
static void F_54 ( struct V_4 * V_5 ,
unsigned short V_1 )
{
#ifdef F_24
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_101 * V_102 ;
V_102 = & V_5 -> V_103 [ F_1 ( V_1 ) ] ;
F_67 ( & V_10 -> V_52 -> V_53 [ V_1 ] ,
V_102 ) ;
F_68 ( V_5 , V_102 ) ;
#endif
}
static void F_50 ( struct V_4 * V_5 , unsigned short V_83 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned short V_116 = 0 ;
if ( V_83 & V_117 )
V_116 |= V_118 ;
if ( V_83 & V_119 )
V_116 |= V_120 ;
if ( V_83 & V_121 )
V_116 |= V_122 ;
if ( V_83 & V_123 )
V_116 |= V_124 ;
if ( V_116 )
V_10 -> V_16 ( V_5 , V_116 , V_125 ) ;
}
static void F_52 ( struct V_4 * V_5 , unsigned short V_126 ,
unsigned V_85 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_101 * V_102 = & V_5 -> V_103 [ V_104 ] ;
if ( V_102 -> type == V_127 )
return;
#ifdef F_24
if ( V_85 & V_94 )
F_56 ( V_5 ) ;
if ( V_85 & ~ ( V_98 | V_94 | V_128 | V_129 |
V_130 | V_131 | V_132 | V_133 |
V_134 | V_135 | V_136 ) ) {
F_6
( L_9 ,
V_85 ) ;
V_102 -> V_105 -> V_111 |= V_137 | V_115 ;
}
#endif
if ( V_126 & ( V_138 | V_139 | V_140 |
V_117 | V_119 ) ) {
if ( V_126 == 0xffff ) {
F_6
( L_10 ) ;
if ( F_69 ( V_102 ) ) {
V_102 -> V_105 -> V_111 |=
V_137 | V_115 ;
F_68 ( V_5 , V_102 ) ;
}
return;
}
if ( V_126 & ( V_138 | V_139 |
V_140 ) ) {
F_6 ( L_11 ,
V_126 ) ;
F_63 ( V_5 ) ;
V_102 -> V_105 -> V_111 |= V_137 ;
if ( V_126 & ( V_138 | V_139 ) )
V_102 -> V_105 -> V_111 |= V_141 ;
F_68 ( V_5 , V_102 ) ;
return;
}
if ( V_126 & V_117 ) {
if ( ! V_10 -> V_142 )
F_63 ( V_5 ) ;
}
}
#ifndef F_24
if ( V_126 & V_143 ) {
int V_67 ;
static const int V_66 = 10 ;
for ( V_67 = 0 ; V_67 < V_66 ; ++ V_67 ) {
F_70 ( V_5 ) ;
if ( ( V_10 -> V_75 ( V_5 ,
V_91 ) &
V_143 ) == 0 )
break;
}
}
#endif
if ( ( V_126 & V_123 ) )
F_61 ( V_5 , V_102 ) ;
F_68 ( V_5 , V_102 ) ;
}
static void F_51 ( struct V_4 * V_5 , unsigned short V_84 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned short V_116 = 0 ;
if ( V_84 & V_144 )
V_116 |= V_145 ;
if ( V_84 & V_146 )
V_116 |= V_147 ;
if ( V_84 & V_148 )
V_116 |= V_149 ;
if ( V_84 & V_150 )
V_116 |= V_151 ;
if ( V_84 & V_152 )
V_116 |= V_153 ;
if ( V_84 & V_154 )
V_116 |= V_155 ;
if ( V_84 & V_156 )
V_116 |= V_157 ;
if ( V_116 )
V_10 -> V_16 ( V_5 , V_116 , V_158 ) ;
}
static void F_53 ( struct V_4 * V_5 ,
unsigned short V_84 , unsigned V_86 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_101 * V_102 = & V_5 -> V_103 [ V_106 ] ;
#ifdef F_24
if ( V_86 & V_94 )
F_58 ( V_10 -> V_40 , V_5 ) ;
if ( V_86 & ~ ( V_98 | V_94 | V_128 | V_129 |
V_130 | V_131 | V_132 | V_133 |
V_134 | V_135 | V_136 ) ) {
F_6
( L_12 ,
V_86 ) ;
V_102 -> V_105 -> V_111 |= V_115 | V_137 ;
}
#endif
if ( V_84 == 0xffff )
return;
if ( V_84 & V_146 ) {
F_6
( L_13 ,
V_84 , V_10 -> V_75 ( V_5 , V_159 ) ) ;
V_102 -> V_105 -> V_111 |= V_141 ;
}
if ( V_84 & V_144 )
V_102 -> V_105 -> V_111 |= V_115 ;
#ifndef F_24
if ( V_84 & V_160 ) {
int V_161 ;
V_161 = F_71 ( V_5 , V_102 ) ;
if ( ! V_161 ) {
F_6 ( L_14 ) ;
F_44 ( V_5 , V_17 ,
V_162 |
V_163 , 0 ) ;
V_102 -> V_105 -> V_111 |= V_141 ;
}
}
#endif
F_68 ( V_5 , V_102 ) ;
}
static void F_72 ( struct V_4 * V_5 ,
struct V_101 * V_102 , int V_164 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_165 * V_105 = V_102 -> V_105 ;
struct V_166 * V_167 = & V_105 -> V_167 ;
int V_168 ;
int V_67 ;
unsigned short V_82 ;
T_4 V_169 ;
int V_170 ;
int V_171 = 1 ;
V_168 = V_105 -> V_172 ;
for ( V_67 = 0 ; V_67 < V_164 ; V_67 ++ ) {
V_171 &= F_73 ( V_105 , & V_82 ) ;
if ( V_171 == 0 )
break;
V_170 = F_74 ( V_167 -> V_173 [ V_168 ] ) ;
if ( V_59 -> V_60 & V_174 ) {
V_169 = V_82 & 0xffff ;
if ( V_59 -> V_60 != V_175 ) {
V_171 &= F_73 ( V_105 , & V_82 ) ;
if ( V_171 == 0 )
break;
V_168 ++ ;
V_67 ++ ;
V_169 |= ( V_82 << 16 ) & 0xffff0000 ;
}
F_33 ( V_169 , V_176 ) ;
} else {
F_40 ( V_82 , V_177 ) ;
}
V_168 ++ ;
V_168 %= V_167 -> V_178 ;
}
V_105 -> V_172 = V_168 ;
if ( V_171 == 0 )
V_105 -> V_111 |= V_141 ;
}
static int F_71 ( struct V_4 * V_5 ,
struct V_101 * V_102 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
int V_164 ;
V_164 = F_75 ( V_102 -> V_105 ) ;
if ( V_164 == 0 ) {
V_102 -> V_105 -> V_111 |= V_141 ;
return 0 ;
}
V_164 /= sizeof( short ) ;
if ( V_164 > V_59 -> V_179 / 2 )
V_164 = V_59 -> V_179 / 2 ;
F_72 ( V_5 , V_102 , V_164 ) ;
V_102 -> V_105 -> V_111 |= V_180 ;
return 1 ;
}
static int F_76 ( struct V_4 * V_5 ,
struct V_101 * V_102 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_164 ;
V_10 -> V_16 ( V_5 , 1 , V_181 ) ;
if ( V_59 -> V_60 & V_174 )
F_41 ( V_5 , 0x6 , V_182 ) ;
V_164 = F_75 ( V_102 -> V_105 ) ;
if ( V_164 == 0 )
return 0 ;
V_164 /= sizeof( short ) ;
if ( V_164 > V_59 -> V_179 )
V_164 = V_59 -> V_179 ;
F_72 ( V_5 , V_102 , V_164 ) ;
return V_164 ;
}
static void F_77 ( struct V_4 * V_5 ,
struct V_101 * V_102 , int V_164 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_165 * V_105 = V_102 -> V_105 ;
int V_67 ;
if ( V_59 -> V_60 == V_183 ) {
unsigned short V_73 [ 2 ] ;
T_4 V_184 ;
for ( V_67 = 0 ; V_67 < V_164 / 2 ; V_67 ++ ) {
V_184 = F_34 ( V_185 ) ;
V_73 [ 0 ] = ( V_184 >> 16 ) & 0xffff ;
V_73 [ 1 ] = V_184 & 0xffff ;
F_78 ( V_102 , V_73 , sizeof( V_73 ) ) ;
}
if ( V_164 % 2 ) {
V_184 = F_34 ( V_185 ) ;
V_73 [ 0 ] = V_184 & 0xffff ;
F_79 ( V_102 , V_73 [ 0 ] ) ;
}
} else if ( V_59 -> V_60 == V_68 ) {
unsigned short V_73 [ 2 ] ;
T_4 V_184 ;
for ( V_67 = 0 ; V_67 < V_164 / 2 ; V_67 ++ ) {
V_184 = F_34 ( V_186 ) ;
V_73 [ 0 ] = ( V_184 >> 16 ) & 0xffff ;
V_73 [ 1 ] = V_184 & 0xffff ;
F_78 ( V_102 , V_73 , sizeof( V_73 ) ) ;
}
if ( V_164 % 2 ) {
F_33 ( 0x01 , V_69 ) ;
V_184 = F_34 ( V_186 ) ;
V_73 [ 0 ] = ( V_184 >> 16 ) & 0xffff ;
F_79 ( V_102 , V_73 [ 0 ] ) ;
}
} else {
if ( V_164 > sizeof( V_10 -> V_187 ) /
sizeof( V_10 -> V_187 [ 0 ] ) ) {
F_19 ( V_5 , L_15 ) ;
V_105 -> V_111 |= V_137 ;
return;
}
for ( V_67 = 0 ; V_67 < V_164 ; V_67 ++ ) {
V_10 -> V_187 [ V_67 ] =
F_43 ( V_188 ) ;
}
F_78 ( V_102 , V_10 -> V_187 ,
V_164 *
sizeof( V_10 -> V_187 [ 0 ] ) ) ;
}
}
static void F_70 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_101 * V_102 = & V_5 -> V_103 [ V_104 ] ;
int V_164 ;
V_164 = V_59 -> V_189 / 2 ;
F_77 ( V_5 , V_102 , V_164 ) ;
}
static int F_64 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_67 ;
static const int V_66 = 10000 ;
unsigned long V_12 ;
int V_190 = 0 ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_39 ) {
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
if ( ( V_10 -> V_75 ( V_5 ,
V_91 ) &
V_191 )
&& F_80 ( V_10 -> V_39 ) ==
0 )
break;
F_35 ( 5 ) ;
}
if ( V_67 == V_66 ) {
F_6 ( L_16 ) ;
F_6
( L_17 ,
F_80 ( V_10 -> V_39 ) ,
V_10 -> V_75 ( V_5 , V_91 ) ) ;
V_190 = - 1 ;
}
}
F_8 ( & V_10 -> V_38 , V_12 ) ;
F_56 ( V_5 ) ;
return V_190 ;
}
static void F_62 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_101 * V_102 = & V_5 -> V_103 [ V_104 ] ;
unsigned short V_73 [ 2 ] ;
T_4 V_184 ;
unsigned short V_192 ;
int V_67 ;
if ( V_59 -> V_60 == V_183 ) {
while ( ( V_10 -> V_75 ( V_5 ,
V_91 ) &
V_191 ) == 0 ) {
V_184 = F_34 ( V_185 ) ;
V_73 [ 0 ] = ( V_184 >> 16 ) ;
V_73 [ 1 ] = ( V_184 & 0xffff ) ;
F_78 ( V_102 , V_73 , sizeof( V_73 ) ) ;
}
} else if ( V_59 -> V_60 == V_68 ) {
V_67 = 0 ;
while ( F_34 ( V_70 ) & 0x04 ) {
V_184 = F_34 ( V_186 ) ;
V_73 [ 0 ] = ( V_184 >> 16 ) ;
V_73 [ 1 ] = ( V_184 & 0xffff ) ;
F_78 ( V_102 , V_73 , sizeof( V_73 ) ) ;
V_67 += 2 ;
}
if ( F_34 ( V_70 ) & 0x01 ) {
F_33 ( 0x01 , V_69 ) ;
V_184 = F_34 ( V_186 ) ;
V_73 [ 0 ] = ( V_184 >> 16 ) & 0xffff ;
F_79 ( V_102 , V_73 [ 0 ] ) ;
}
} else {
V_192 =
V_10 -> V_75 ( V_5 ,
V_91 ) & V_191 ;
while ( V_192 == 0 ) {
for ( V_67 = 0 ;
V_67 <
sizeof( V_10 -> V_187 ) /
sizeof( V_10 -> V_187 [ 0 ] ) ; V_67 ++ ) {
V_192 =
V_10 -> V_75 ( V_5 ,
V_91 ) &
V_191 ;
if ( V_192 )
break;
V_10 -> V_187 [ V_67 ] =
F_43 ( V_188 ) ;
}
F_78 ( V_102 , V_10 -> V_187 ,
V_67 *
sizeof( V_10 ->
V_187 [ 0 ] ) ) ;
}
}
}
static void F_65 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 V_193 = V_5 -> V_11 ;
struct V_101 * V_102 = & V_5 -> V_103 [ V_104 ] ;
unsigned short V_73 ;
T_4 V_184 ;
if ( V_59 -> V_60 != V_183 )
return;
if ( F_81 ( V_194 ) & 0x80 ) {
V_184 = F_34 ( V_185 ) ;
V_73 = ( V_184 & 0xffff ) ;
F_79 ( V_102 , V_73 ) ;
}
}
static void F_66 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 V_193 = V_5 -> V_11 ;
struct V_101 * V_102 = & V_5 -> V_103 [ V_104 ] ;
unsigned short V_73 ;
T_4 V_184 ;
if ( V_59 -> V_60 != V_68 )
return;
if ( F_34 ( V_70 ) & 0x01 ) {
F_33 ( 0x01 , V_69 ) ;
V_184 = F_34 ( V_186 ) ;
V_73 = ( V_184 >> 16 ) & 0xffff ;
F_79 ( V_102 , V_73 ) ;
}
}
static void F_82 ( struct V_4 * V_5 , struct V_101 * V_102 ,
void * V_73 , unsigned int V_195 ,
unsigned int V_196 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_165 * V_105 = V_102 -> V_105 ;
unsigned int V_67 ;
unsigned int V_197 = V_195 / F_83 ( V_102 ) ;
unsigned short * V_198 = V_73 ;
unsigned int * V_199 = V_73 ;
for ( V_67 = 0 ; V_67 < V_197 ; V_67 ++ ) {
#ifdef F_24
if ( V_102 -> V_200 & V_201 )
V_199 [ V_67 ] = F_84 ( V_199 [ V_67 ] ) ;
else
V_198 [ V_67 ] = F_85 ( V_198 [ V_67 ] ) ;
#endif
if ( V_102 -> V_200 & V_201 )
V_199 [ V_67 ] += V_10 -> V_202 [ V_196 ] ;
else
V_198 [ V_67 ] += V_10 -> V_202 [ V_196 ] ;
V_196 ++ ;
V_196 %= V_105 -> V_167 . V_178 ;
}
}
static int F_86 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_101 * V_102 = & V_5 -> V_103 [ V_104 ] ;
int V_190 ;
unsigned long V_12 ;
V_190 = F_16 ( V_5 ) ;
if ( V_190 )
return V_190 ;
F_87 ( V_102 -> V_105 , V_102 -> V_105 -> V_203 ) ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_39 == NULL ) {
F_8 ( & V_10 -> V_38 , V_12 ) ;
return - V_204 ;
}
switch ( V_59 -> V_60 ) {
case V_183 :
case V_68 :
F_88 ( V_10 -> V_39 , 32 , 16 ) ;
break;
case V_205 :
F_88 ( V_10 -> V_39 , 32 , 32 ) ;
break;
default:
F_88 ( V_10 -> V_39 , 16 , 16 ) ;
break;
}
F_89 ( V_10 -> V_39 ) ;
F_8 ( & V_10 -> V_38 , V_12 ) ;
return 0 ;
}
static int F_90 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_101 * V_102 = & V_5 -> V_103 [ V_106 ] ;
int V_190 ;
unsigned long V_12 ;
V_190 = F_20 ( V_5 ) ;
if ( V_190 )
return V_190 ;
F_91 ( V_102 -> V_105 , V_102 -> V_105 -> V_203 ) ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_45 ) {
if ( V_59 -> V_60 & ( V_183 | V_206 ) ) {
F_88 ( V_10 -> V_45 , 32 , 32 ) ;
} else {
F_88 ( V_10 -> V_45 , 16 , 32 ) ;
}
F_89 ( V_10 -> V_45 ) ;
} else
V_190 = - V_204 ;
F_8 ( & V_10 -> V_38 , V_12 ) ;
return V_190 ;
}
static int F_92 ( struct V_4 * V_5 , struct V_101 * V_102 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
F_25 ( V_5 ) ;
V_10 -> V_16 ( V_5 , V_207 | V_208 ,
V_209 ) ;
F_44 ( V_5 , V_14 ,
V_210 | V_211 |
V_212 | V_213 |
V_214 | V_215 |
V_216 , 0 ) ;
F_32 ( V_5 ) ;
if ( V_59 -> V_60 != V_68 )
F_5 ( 0 , V_217 ) ;
V_10 -> V_16 ( V_5 , V_218 , V_219 ) ;
V_10 -> V_16 ( V_5 ,
V_220 | V_221
,
V_222 ) ;
V_10 -> V_16 ( V_5 , 0x0000 , V_223 ) ;
V_10 -> V_16 ( V_5 , ( 0 << 6 ) | 0x0000 , V_224 ) ;
if ( V_59 -> V_60 == V_183 ) {
V_10 -> V_16 ( V_5 , V_225 |
V_226 |
V_227 ,
V_228 ) ;
V_10 -> V_16 ( V_5 ,
F_93 ( 3 ) |
F_94 ( 0 ) |
F_95 ( 2 ) |
F_96 ( 3 ) |
F_97
( V_229 ) ,
V_230 ) ;
} else if ( V_59 -> V_60 == V_68 ) {
V_10 -> V_16 ( V_5 , V_225 |
V_226 |
V_227 ,
V_228 ) ;
V_10 -> V_16 ( V_5 ,
F_93 ( 3 ) |
F_94 ( 0 ) |
F_95 ( 2 ) |
F_96 ( 3 ) |
F_97
( V_231 ) ,
V_230 ) ;
} else {
unsigned V_232 ;
V_10 -> V_16 ( V_5 , V_225 |
V_226 |
V_233 |
V_227 ,
V_228 ) ;
V_232 =
F_93 ( 3 ) |
F_94 ( 0 ) |
F_95 ( 2 ) |
F_96 ( 3 ) ;
if ( V_59 -> V_60 == V_234 )
V_232 |=
F_97
( V_229 ) ;
else
V_232 |=
F_97
( V_231 ) ;
V_10 -> V_16 ( V_5 , V_232 ,
V_230 ) ;
}
V_10 -> V_16 ( V_5 , V_235 | V_122 | V_236 | V_120 | V_118 | V_237 | V_124 , V_125 ) ;
V_10 -> V_16 ( V_5 , V_238 , V_209 ) ;
return 0 ;
}
static int F_98 ( struct V_4 * V_5 , struct V_101 * V_102 )
{
unsigned long V_12 ;
int V_239 ;
F_4 ( & V_5 -> V_90 , V_12 ) ;
#ifndef F_24
F_62 ( V_5 ) ;
#else
F_56 ( V_5 ) ;
#endif
V_239 = V_102 -> V_105 -> V_240 - V_102 -> V_105 -> V_241 ;
F_8 ( & V_5 -> V_90 , V_12 ) ;
return V_239 ;
}
static int F_99 ( struct V_4 * V_5 ,
struct V_101 * V_102 , struct V_242 * V_243 ,
unsigned int * V_73 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_67 , V_164 ;
const unsigned int V_244 = ( 1 << V_59 -> V_245 ) - 1 ;
unsigned V_246 ;
unsigned short V_82 ;
unsigned long V_184 ;
F_100 ( V_5 , 1 , & V_243 -> V_247 ) ;
F_32 ( V_5 ) ;
V_246 = V_10 -> V_202 [ 0 ] ;
if ( V_59 -> V_60 == V_183 ) {
for ( V_164 = 0 ; V_164 < V_248 ; V_164 ++ ) {
V_10 -> V_16 ( V_5 , V_249 ,
V_219 ) ;
F_35 ( 1 ) ;
}
for ( V_164 = 0 ; V_164 < V_243 -> V_164 ; V_164 ++ ) {
V_10 -> V_16 ( V_5 , V_249 ,
V_219 ) ;
V_82 = 0 ;
for ( V_67 = 0 ; V_67 < V_250 ; V_67 ++ ) {
if ( F_81 ( V_194 ) & 0x80 ) {
V_82 = ( F_34 ( V_185 ) >> 16 )
& 0xffff ;
break;
}
if ( ! ( V_10 -> V_75 ( V_5 ,
V_91 ) &
V_191 ) ) {
V_82 = F_34 ( V_185 ) &
0xffff ;
break;
}
}
if ( V_67 == V_250 ) {
F_6
( L_18 ) ;
return - V_251 ;
}
V_82 += V_246 ;
V_73 [ V_164 ] = V_82 ;
}
} else if ( V_59 -> V_60 == V_68 ) {
for ( V_164 = 0 ; V_164 < V_243 -> V_164 ; V_164 ++ ) {
V_10 -> V_16 ( V_5 , V_249 ,
V_219 ) ;
V_184 = 0 ;
for ( V_67 = 0 ; V_67 < V_250 ; V_67 ++ ) {
if ( F_34 ( V_70 ) & 0x01 ) {
F_33 ( 0x01 , V_69 ) ;
V_184 = F_34 ( V_186 ) ;
break;
}
}
if ( V_67 == V_250 ) {
F_6
( L_19 ) ;
return - V_251 ;
}
V_73 [ V_164 ] = ( ( ( V_184 >> 16 ) & 0xFFFF ) + V_246 ) & 0xFFFF ;
}
} else {
for ( V_164 = 0 ; V_164 < V_243 -> V_164 ; V_164 ++ ) {
V_10 -> V_16 ( V_5 , V_249 ,
V_219 ) ;
for ( V_67 = 0 ; V_67 < V_250 ; V_67 ++ ) {
if ( ! ( V_10 -> V_75 ( V_5 ,
V_91 ) &
V_191 ) )
break;
}
if ( V_67 == V_250 ) {
F_6
( L_20 ) ;
return - V_251 ;
}
if ( V_59 -> V_60 & V_61 ) {
V_73 [ V_164 ] =
F_34 ( V_252 ) & V_244 ;
} else {
V_82 = F_43 ( V_188 ) ;
V_82 += V_246 ;
V_73 [ V_164 ] = V_82 ;
}
}
}
return V_243 -> V_164 ;
}
static void F_101 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_67 ;
V_10 -> V_16 ( V_5 , V_249 , V_219 ) ;
for ( V_67 = 0 ; V_67 < V_250 ; ++ V_67 ) {
if ( ! ( V_10 -> V_75 ( V_5 ,
V_91 ) &
V_191 ) ) {
V_10 -> V_16 ( V_5 , 1 , V_71 ) ;
return;
}
F_35 ( 1 ) ;
}
F_6 ( L_21 ) ;
}
static void F_102 ( struct V_4 * V_5 ,
unsigned int V_253 ,
unsigned int * V_254 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_168 , V_170 , V_255 ;
unsigned int V_67 ;
unsigned V_256 ;
unsigned int V_257 ;
unsigned V_258 ;
V_10 -> V_16 ( V_5 , 1 , V_259 ) ;
if ( ( V_254 [ 0 ] & V_260 ) ) {
unsigned V_261 ;
V_168 = F_103 ( V_254 [ 0 ] ) ;
V_170 = F_74 ( V_254 [ 0 ] ) ;
V_258 = V_262 [ V_59 -> V_263 ] [ V_170 ] ;
V_257 = ( ( V_254 [ 0 ] & V_264 ) != 0 ) ;
V_261 = V_265 ;
V_261 |= V_168 ;
V_261 |=
( V_10 -> V_266 ) &
( V_267 |
V_268 |
V_269 |
V_270 ) ;
V_261 |= F_104 ( V_258 ) ;
if ( V_257 )
V_261 |= V_271 ;
V_261 |= V_272 ;
F_33 ( V_261 , V_273 ) ;
} else {
F_33 ( 0 , V_273 ) ;
}
V_256 = 0 ;
for ( V_67 = 0 ; V_67 < V_253 ; V_67 ++ ) {
unsigned V_274 = 0 ;
V_168 = F_103 ( V_254 [ V_67 ] ) ;
V_255 = F_105 ( V_254 [ V_67 ] ) ;
V_170 = F_74 ( V_254 [ V_67 ] ) ;
V_257 = ( ( V_254 [ V_67 ] & V_264 ) != 0 ) ;
V_258 = V_262 [ V_59 -> V_263 ] [ V_170 ] ;
V_10 -> V_202 [ V_67 ] = V_256 ;
switch ( V_255 ) {
case V_275 :
V_274 |=
V_276 ;
break;
case V_277 :
V_274 |=
V_278 ;
break;
case V_279 :
V_274 |=
V_280 ;
break;
case V_281 :
break;
}
V_274 |= F_106 ( V_168 ) ;
V_274 |=
F_107 ( V_59 -> V_60 , V_168 ) ;
V_274 |= F_108 ( V_258 ) ;
if ( V_67 == V_253 - 1 )
V_274 |= V_282 ;
if ( V_257 )
V_274 |= V_283 ;
V_274 |= V_284 ;
F_40 ( V_274 , V_285 ) ;
}
F_101 ( V_5 ) ;
}
static void F_100 ( struct V_4 * V_5 ,
unsigned int V_253 , unsigned int * V_254 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_168 , V_170 , V_255 ;
unsigned int V_67 ;
unsigned int V_286 , V_287 ;
unsigned V_256 ;
unsigned int V_257 ;
if ( V_59 -> V_60 & V_61 ) {
F_102 ( V_5 , V_253 , V_254 ) ;
return;
}
if ( V_253 == 1 && ( V_59 -> V_60 != V_183 )
&& ( V_59 -> V_60 != V_68 ) ) {
if ( V_10 -> V_288
&& V_10 -> V_289 == V_254 [ 0 ] ) {
return;
}
V_10 -> V_288 = 1 ;
V_10 -> V_289 = V_254 [ 0 ] ;
} else {
V_10 -> V_288 = 0 ;
}
V_10 -> V_16 ( V_5 , 1 , V_259 ) ;
if ( V_59 -> V_60 == V_68 ) {
if ( ( V_254 [ 0 ] & V_260 )
&& ! V_10 -> V_290 ) {
F_40 ( V_10 -> V_266 |
V_291 ,
V_292 ) ;
F_40 ( V_10 -> V_266 ,
V_292 ) ;
V_10 -> V_290 = 1 ;
F_109 ( 100 ) ;
} else if ( ! ( V_254 [ 0 ] & V_260 )
&& V_10 -> V_290 ) {
F_40 ( V_10 -> V_266 |
V_293 ,
V_292 ) ;
F_40 ( V_10 -> V_266 ,
V_292 ) ;
V_10 -> V_290 = 0 ;
F_109 ( 100 ) ;
}
}
V_256 = 1 << ( V_59 -> V_245 - 1 ) ;
for ( V_67 = 0 ; V_67 < V_253 ; V_67 ++ ) {
if ( ( V_59 -> V_60 != V_68 )
&& ( V_254 [ V_67 ] & V_260 ) ) {
V_168 = V_10 -> V_266 ;
} else {
V_168 = F_103 ( V_254 [ V_67 ] ) ;
}
V_255 = F_105 ( V_254 [ V_67 ] ) ;
V_170 = F_74 ( V_254 [ V_67 ] ) ;
V_257 = ( ( V_254 [ V_67 ] & V_264 ) != 0 ) ;
V_170 = V_262 [ V_59 -> V_263 ] [ V_170 ] ;
if ( V_59 -> V_60 == V_183 )
V_10 -> V_202 [ V_67 ] = V_256 ;
else
V_10 -> V_202 [ V_67 ] = ( V_170 & 0x100 ) ? 0 : V_256 ;
V_286 = 0 ;
if ( ( V_254 [ V_67 ] & V_260 ) ) {
if ( V_59 -> V_60 == V_183 )
F_40 ( F_103 ( V_254 [ V_67 ] ) & 0x0003 ,
V_294 ) ;
} else {
if ( V_59 -> V_60 == V_183 )
V_255 = V_275 ;
else if ( V_59 -> V_60 == V_68 )
V_255 = V_281 ;
switch ( V_255 ) {
case V_275 :
V_286 |= V_295 ;
break;
case V_277 :
V_286 |= V_296 ;
break;
case V_279 :
V_286 |= V_297 ;
break;
case V_281 :
break;
}
}
V_286 |= F_110 ( V_168 ) ;
F_40 ( V_286 , V_298 ) ;
if ( V_59 -> V_60 != V_68 ) {
V_287 = V_170 ;
if ( V_67 == V_253 - 1 )
V_287 |= V_299 ;
if ( V_257 )
V_287 |= V_300 ;
F_40 ( V_287 , V_301 ) ;
}
}
if ( ( V_59 -> V_60 != V_183 )
&& ( V_59 -> V_60 != V_68 ) ) {
F_101 ( V_5 ) ;
}
}
static int F_111 ( const struct V_4 * V_5 , unsigned V_302 ,
int V_303 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_304 ;
switch ( V_303 ) {
case V_305 :
default:
V_304 = ( V_302 + V_10 -> V_306 / 2 ) / V_10 -> V_306 ;
break;
case V_307 :
V_304 = ( V_302 ) / V_10 -> V_306 ;
break;
case V_308 :
V_304 = ( V_302 + V_10 -> V_306 - 1 ) / V_10 -> V_306 ;
break;
}
return V_304 - 1 ;
}
static unsigned F_112 ( const struct V_4 * V_5 , int V_309 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
return V_10 -> V_306 * ( V_309 + 1 ) ;
}
static unsigned F_113 ( struct V_4 * V_5 ,
unsigned V_310 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
switch ( V_59 -> V_60 ) {
case V_183 :
case V_68 :
return V_59 -> V_311 ;
break;
default:
break;
}
return V_59 -> V_311 * V_310 ;
}
static int F_114 ( struct V_4 * V_5 , struct V_101 * V_102 ,
struct V_166 * V_167 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_171 = 0 ;
int V_312 ;
unsigned int V_313 ;
if ( ( V_167 -> V_12 & V_314 ) )
V_167 -> V_12 &= ~ V_314 ;
V_171 |= F_115 ( & V_167 -> V_315 ,
V_316 | V_317 | V_318 ) ;
V_171 |= F_115 ( & V_167 -> V_319 ,
V_320 | V_318 ) ;
V_313 = V_320 | V_318 ;
if ( V_59 -> V_60 == V_183 ||
V_59 -> V_60 == V_68 )
V_313 |= V_316 ;
V_171 |= F_115 ( & V_167 -> V_321 , V_313 ) ;
V_171 |= F_115 ( & V_167 -> V_322 , V_323 ) ;
V_171 |= F_115 ( & V_167 -> V_324 , V_323 | V_325 ) ;
if ( V_171 )
return 1 ;
V_171 |= F_116 ( V_167 -> V_315 ) ;
V_171 |= F_116 ( V_167 -> V_319 ) ;
V_171 |= F_116 ( V_167 -> V_321 ) ;
V_171 |= F_116 ( V_167 -> V_324 ) ;
if ( V_171 )
return 2 ;
if ( V_167 -> V_315 == V_318 ) {
unsigned int V_312 = F_103 ( V_167 -> V_326 ) ;
if ( V_312 > 16 )
V_312 = 16 ;
V_312 |= ( V_167 -> V_326 & ( V_327 | V_328 ) ) ;
V_171 |= F_117 ( & V_167 -> V_326 , V_312 ) ;
} else {
V_171 |= F_117 ( & V_167 -> V_326 , 0 ) ;
}
if ( V_167 -> V_319 == V_320 ) {
V_171 |= F_118 ( & V_167 -> V_329 ,
F_113 ( V_5 , V_167 -> V_178 ) ) ;
V_171 |= F_119 ( & V_167 -> V_329 ,
V_10 -> V_306 * 0xffffff ) ;
} else if ( V_167 -> V_319 == V_318 ) {
unsigned int V_312 = F_103 ( V_167 -> V_329 ) ;
if ( V_312 > 16 )
V_312 = 16 ;
V_312 |= ( V_167 -> V_329 & ( V_327 | V_328 ) ) ;
V_171 |= F_117 ( & V_167 -> V_329 , V_312 ) ;
} else {
V_171 |= F_117 ( & V_167 -> V_329 , 0 ) ;
}
if ( V_167 -> V_321 == V_320 ) {
if ( ( V_59 -> V_60 == V_183 )
|| ( V_59 -> V_60 == V_68 ) ) {
V_171 |= F_117 ( & V_167 -> V_330 , 0 ) ;
} else {
V_171 |= F_118 ( & V_167 -> V_330 ,
V_59 -> V_311 ) ;
V_171 |= F_119 ( & V_167 -> V_330 ,
V_10 -> V_306 * 0xffff ) ;
}
} else if ( V_167 -> V_321 == V_318 ) {
unsigned int V_312 = F_103 ( V_167 -> V_330 ) ;
if ( V_312 > 16 )
V_312 = 16 ;
V_312 |= ( V_167 -> V_330 & ( V_264 | V_327 ) ) ;
V_171 |= F_117 ( & V_167 -> V_330 , V_312 ) ;
} else if ( V_167 -> V_321 == V_316 ) {
V_171 |= F_117 ( & V_167 -> V_330 , 0 ) ;
}
V_171 |= F_117 ( & V_167 -> V_331 , V_167 -> V_178 ) ;
if ( V_167 -> V_324 == V_323 ) {
unsigned int V_332 = 0x01000000 ;
if ( V_59 -> V_60 == V_183 )
V_332 -= V_248 ;
V_171 |= F_119 ( & V_167 -> V_333 , V_332 ) ;
V_171 |= F_118 ( & V_167 -> V_333 , 1 ) ;
} else {
V_171 |= F_117 ( & V_167 -> V_333 , 0 ) ;
}
if ( V_171 )
return 3 ;
if ( V_167 -> V_319 == V_320 ) {
V_312 = V_167 -> V_329 ;
V_167 -> V_329 =
F_112 ( V_5 , F_111 ( V_5 ,
V_167 -> V_329 ,
V_167 ->
V_12 &
V_334 ) ) ;
if ( V_312 != V_167 -> V_329 )
V_171 ++ ;
}
if ( V_167 -> V_321 == V_320 ) {
if ( ( V_59 -> V_60 != V_183 )
&& ( V_59 -> V_60 != V_68 ) ) {
V_312 = V_167 -> V_330 ;
V_167 -> V_330 =
F_112 ( V_5 , F_111 ( V_5 ,
V_167 -> V_330 ,
V_167 ->
V_12 &
V_334 ) ) ;
if ( V_312 != V_167 -> V_330 )
V_171 ++ ;
if ( V_167 -> V_319 == V_320 &&
V_167 -> V_329 <
V_167 -> V_330 * V_167 -> V_331 ) {
V_167 -> V_329 =
V_167 -> V_330 * V_167 -> V_331 ;
V_171 ++ ;
}
}
}
if ( V_171 )
return 4 ;
return 0 ;
}
static int F_120 ( struct V_4 * V_5 , struct V_101 * V_102 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
const struct V_166 * V_167 = & V_102 -> V_105 -> V_167 ;
int V_309 ;
int V_335 = 0 ;
int V_336 = 0 ;
int V_337 = 0 ;
unsigned int V_338 ;
int V_339 = 0 ;
if ( V_5 -> V_81 == 0 ) {
F_19 ( V_5 , L_22 ) ;
return - V_204 ;
}
F_32 ( V_5 ) ;
F_100 ( V_5 , V_167 -> V_178 , V_167 -> V_173 ) ;
V_10 -> V_16 ( V_5 , V_207 , V_209 ) ;
V_10 -> V_340 &= ~ V_341 ;
V_10 -> V_16 ( V_5 , V_10 -> V_340 ,
V_342 ) ;
switch ( V_167 -> V_315 ) {
case V_317 :
case V_316 :
V_10 -> V_16 ( V_5 , F_121 ( 0 ) |
V_343 | V_344 |
F_122 ( 0 ) ,
V_345 ) ;
break;
case V_318 :
{
int V_168 = F_103 ( V_167 -> V_326 ) ;
unsigned int V_74 = F_121 ( 0 ) |
V_343 | F_122 ( V_168 + 1 ) ;
if ( V_167 -> V_326 & V_327 )
V_74 |= V_346 ;
if ( V_167 -> V_326 & V_328 )
V_74 |= V_344 ;
V_10 -> V_16 ( V_5 , V_74 ,
V_345 ) ;
break;
}
}
V_336 &= ~ V_347 ;
V_336 &= ~ V_348 ;
V_336 &= ~ V_349 ;
V_10 -> V_16 ( V_5 , V_336 , V_223 ) ;
if ( V_167 -> V_178 == 1 || ( V_59 -> V_60 == V_183 )
|| ( V_59 -> V_60 == V_68 ) ) {
V_337 |= V_350 ;
V_337 |= F_123 ( 31 ) ;
V_337 |= V_351 ;
} else {
V_337 |= F_123 ( 19 ) ;
}
V_10 -> V_16 ( V_5 , V_337 ,
V_352 ) ;
V_10 -> V_113 = 0 ;
switch ( V_167 -> V_324 ) {
case V_323 :
V_338 = V_167 -> V_333 - 1 ;
if ( V_59 -> V_60 == V_183 ) {
V_338 += V_248 ;
}
V_10 -> V_353 ( V_5 , V_338 , V_354 ) ;
V_335 |= V_220 | V_221 | V_355 ;
V_10 -> V_16 ( V_5 , V_335 , V_222 ) ;
V_10 -> V_16 ( V_5 , V_356 , V_219 ) ;
V_10 -> V_142 = 0 ;
if ( V_338 == 0 ) {
V_10 -> V_113 |= V_114 ;
V_339 |= V_214 ;
if ( V_167 -> V_178 > 1 )
V_337 |=
V_350 | V_357 ;
}
break;
case V_325 :
V_10 -> V_353 ( V_5 , 0 , V_354 ) ;
V_335 |= V_220 | V_221 | V_358 ;
V_10 -> V_16 ( V_5 , V_335 , V_222 ) ;
V_10 -> V_16 ( V_5 , V_356 , V_219 ) ;
V_10 -> V_142 = 1 ;
break;
}
switch ( V_167 -> V_319 ) {
case V_320 :
V_337 |= V_359 | V_360 ;
V_10 -> V_16 ( V_5 , V_337 ,
V_352 ) ;
V_336 |= F_124 ( 0 ) ;
V_336 &= ~ V_361 ;
V_10 -> V_16 ( V_5 , V_336 , V_223 ) ;
V_309 = F_111 ( V_5 , V_167 -> V_329 ,
V_305 ) ;
V_10 -> V_353 ( V_5 , V_309 , V_362 ) ;
V_10 -> V_16 ( V_5 , V_363 , V_219 ) ;
break;
case V_318 :
if ( V_167 -> V_329 & V_328 )
V_337 |= V_359 ;
if ( V_167 -> V_329 & V_327 )
V_337 |= V_364 ;
if ( V_167 -> V_319 != V_167 -> V_321 ||
( V_167 -> V_329 & ~ V_328 ) !=
( V_167 -> V_330 & ~ V_328 ) )
V_337 |= V_360 ;
V_337 |=
F_125 ( 1 + F_103 ( V_167 -> V_329 ) ) ;
V_10 -> V_16 ( V_5 , V_337 ,
V_352 ) ;
break;
}
switch ( V_167 -> V_321 ) {
case V_320 :
case V_316 :
if ( V_167 -> V_330 == 0 || V_167 -> V_321 == V_316 )
V_309 = 1 ;
else
V_309 = F_111 ( V_5 , V_167 -> V_330 ,
V_305 ) ;
V_10 -> V_16 ( V_5 , 1 , V_365 ) ;
V_10 -> V_16 ( V_5 , V_309 , V_366 ) ;
V_336 &= ~ V_367 ;
V_336 |= V_368 ;
V_10 -> V_16 ( V_5 , V_336 , V_223 ) ;
V_10 -> V_16 ( V_5 , V_369 , V_219 ) ;
V_336 |= V_368 ;
V_336 |= V_367 ;
V_10 -> V_16 ( V_5 , V_336 , V_223 ) ;
break;
case V_318 :
V_335 |= F_126 ( 1 + V_167 -> V_330 ) ;
if ( ( V_167 -> V_330 & V_327 ) == 0 )
V_335 |= V_370 ;
V_10 -> V_16 ( V_5 , V_335 , V_222 ) ;
V_336 |= V_371 | V_372 ;
V_10 -> V_16 ( V_5 , V_336 , V_223 ) ;
break;
}
if ( V_5 -> V_81 ) {
V_339 |= V_215 |
V_210 ;
#ifndef F_24
V_339 |= V_216 ;
#endif
if ( V_167 -> V_12 & V_373
|| ( V_10 -> V_113 & V_114 ) ) {
V_10 -> V_109 = V_110 ;
} else {
V_10 -> V_109 = V_374 ;
}
switch ( V_10 -> V_109 ) {
case V_374 :
#ifdef F_24
V_10 -> V_16 ( V_5 , V_375 ,
V_224 ) ;
#else
V_10 -> V_16 ( V_5 , V_376 ,
V_224 ) ;
#endif
break;
case V_377 :
V_10 -> V_16 ( V_5 , V_378 ,
V_224 ) ;
break;
case V_110 :
#ifdef F_24
V_10 -> V_16 ( V_5 , V_378 ,
V_224 ) ;
#else
V_10 -> V_16 ( V_5 , V_376 ,
V_224 ) ;
#endif
V_339 |= V_214 ;
break;
default:
break;
}
V_10 -> V_16 ( V_5 , V_237 | V_124 | V_122 | V_236 | V_120 | V_118 | V_235 , V_125 ) ;
F_44 ( V_5 , V_14 ,
V_339 , 1 ) ;
} else {
F_44 ( V_5 , V_14 , ~ 0 , 0 ) ;
}
V_10 -> V_16 ( V_5 , V_238 , V_209 ) ;
switch ( V_167 -> V_319 ) {
case V_320 :
V_10 -> V_16 ( V_5 ,
V_379 | V_380 | V_381 |
V_382 , V_219 ) ;
break;
case V_318 :
V_10 -> V_16 ( V_5 ,
V_379 | V_380 | V_381 |
V_382 , V_219 ) ;
break;
}
#ifdef F_24
{
int V_190 = F_86 ( V_5 ) ;
if ( V_190 )
return V_190 ;
}
#endif
switch ( V_167 -> V_315 ) {
case V_316 :
V_10 -> V_16 ( V_5 , V_383 | V_10 -> V_113 ,
V_384 ) ;
V_102 -> V_105 -> V_385 = NULL ;
break;
case V_318 :
V_102 -> V_105 -> V_385 = NULL ;
break;
case V_317 :
V_102 -> V_105 -> V_385 = & V_386 ;
break;
}
return 0 ;
}
static int V_386 ( struct V_4 * V_5 , struct V_101 * V_102 ,
unsigned int V_387 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_387 != 0 )
return - V_388 ;
V_10 -> V_16 ( V_5 , V_383 | V_10 -> V_113 ,
V_384 ) ;
V_102 -> V_105 -> V_385 = NULL ;
return 1 ;
}
static int F_127 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 , unsigned int * V_73 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_243 -> V_164 < 1 )
return - V_388 ;
switch ( V_73 [ 0 ] ) {
case V_389 :
return F_128 ( V_5 , V_102 , V_243 , V_73 ) ;
case V_390 :
if ( V_59 -> V_60 & V_61 ) {
if ( V_73 [ 1 ] & ~ ( V_267 |
V_268 |
V_269 |
V_270 ) ) {
return - V_388 ;
}
V_10 -> V_266 = V_73 [ 1 ] ;
} else if ( V_59 -> V_60 == V_68 ) {
unsigned int V_391 ;
V_391 = V_73 [ 1 ] & 0xf ;
if ( V_391 > 0xF )
return - V_388 ;
V_10 -> V_266 = V_391 ;
F_40 ( V_391 , V_292 ) ;
} else {
unsigned int V_391 ;
unsigned int V_392 ;
V_391 = V_73 [ 1 ] & 0xf ;
V_392 = ( V_73 [ 1 ] >> 4 ) & 0xff ;
if ( V_391 >= 8 )
return - V_388 ;
V_10 -> V_266 = V_391 ;
if ( V_59 -> V_60 == V_183 ) {
F_5 ( V_392 ,
V_393 ) ;
}
}
return 2 ;
default:
break;
}
return - V_388 ;
}
static int F_128 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 ,
unsigned int * V_73 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_394 , V_395 , V_396 ;
int V_171 = 0 ;
if ( ! V_59 -> V_397 )
return - V_388 ;
if ( ( V_73 [ 1 ] & 0xffff0000 ) != V_398 ) {
V_73 [ 1 ] &= ( V_398 | 0xffff ) ;
V_171 ++ ;
}
if ( V_73 [ 2 ] >= V_59 -> V_399 ) {
V_73 [ 2 ] = V_59 -> V_399 - 1 ;
V_171 ++ ;
}
if ( V_73 [ 3 ] > 255 ) {
V_73 [ 3 ] = 255 ;
V_171 ++ ;
}
if ( V_73 [ 4 ] > 255 ) {
V_73 [ 4 ] = 255 ;
V_171 ++ ;
}
V_394 = V_73 [ 3 ] ;
V_395 = V_73 [ 4 ] ;
V_396 = V_73 [ 1 ] & 0xff ;
if ( V_396 & 0xf0 ) {
if ( V_395 < V_394 ) {
V_394 = V_73 [ 4 ] ;
V_395 = V_73 [ 3 ] ;
V_396 =
( ( V_73 [ 1 ] & 0xf ) << 4 ) | ( ( V_73 [ 1 ] & 0xf0 ) >> 4 ) ;
}
V_10 -> V_400 = V_394 ;
V_10 -> V_401 = V_395 ;
switch ( V_396 ) {
case 0x81 :
V_10 -> V_402 = 6 ;
break;
case 0x42 :
V_10 -> V_402 = 3 ;
break;
case 0x96 :
V_10 -> V_402 = 2 ;
break;
default:
V_73 [ 1 ] &= ~ 0xff ;
V_171 ++ ;
}
} else {
if ( V_395 != 0 ) {
V_73 [ 4 ] = 0 ;
V_171 ++ ;
}
switch ( V_396 ) {
case 0x06 :
V_10 -> V_401 = V_394 ;
V_10 -> V_402 = 0 ;
break;
case 0x09 :
V_10 -> V_400 = V_394 ;
V_10 -> V_402 = 1 ;
break;
default:
V_73 [ 1 ] &= ~ 0xff ;
V_171 ++ ;
}
}
if ( V_171 )
return - V_403 ;
return 5 ;
}
static void F_129 ( struct V_4 * V_5 , struct V_101 * V_102 ,
void * V_73 , unsigned int V_195 ,
unsigned int V_196 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_165 * V_105 = V_102 -> V_105 ;
unsigned int V_170 ;
unsigned int V_67 ;
unsigned int V_256 ;
unsigned int V_197 = V_195 / sizeof( short ) ;
unsigned short * V_198 = V_73 ;
V_256 = 1 << ( V_59 -> V_404 - 1 ) ;
for ( V_67 = 0 ; V_67 < V_197 ; V_67 ++ ) {
V_170 = F_74 ( V_105 -> V_167 . V_173 [ V_196 ] ) ;
if ( V_59 -> V_405 == 0 || ( V_170 & 1 ) == 0 )
V_198 [ V_67 ] -= V_256 ;
#ifdef F_24
V_198 [ V_67 ] = F_130 ( V_198 [ V_67 ] ) ;
#endif
V_196 ++ ;
V_196 %= V_105 -> V_167 . V_178 ;
}
}
static int F_131 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
unsigned int V_247 [] ,
unsigned int V_406 , int V_407 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_170 ;
unsigned int V_168 ;
unsigned int V_408 ;
int V_67 ;
int V_409 = 0 ;
if ( V_407 ) {
for ( V_67 = 0 ; V_67 < V_59 -> V_410 ; ++ V_67 ) {
V_10 -> V_411 [ V_67 ] &= ~ V_412 ;
F_5 ( V_10 -> V_411 [ V_67 ] ,
F_132 ( V_67 ) ) ;
F_5 ( 0xf , F_133 ( V_67 ) ) ;
}
}
for ( V_67 = 0 ; V_67 < V_406 ; V_67 ++ ) {
const struct V_413 * V_414 ;
V_168 = F_103 ( V_247 [ V_67 ] ) ;
V_170 = F_74 ( V_247 [ V_67 ] ) ;
V_414 = V_102 -> V_415 -> V_170 + V_170 ;
V_409 = 0 ;
V_408 = 0 ;
switch ( V_414 -> V_416 - V_414 -> V_417 ) {
case 20000000 :
V_408 |= V_418 ;
F_5 ( 0 , F_134 ( V_168 ) ) ;
break;
case 10000000 :
V_408 |= V_419 ;
F_5 ( 0 , F_134 ( V_168 ) ) ;
break;
case 4000000 :
V_408 |= V_418 ;
F_5 ( V_420 ,
F_134 ( V_168 ) ) ;
break;
case 2000000 :
V_408 |= V_419 ;
F_5 ( V_420 ,
F_134 ( V_168 ) ) ;
break;
default:
F_6 ( L_23 ,
V_25 ) ;
break;
}
switch ( V_414 -> V_416 + V_414 -> V_417 ) {
case 0 :
V_408 |= V_421 ;
break;
case 10000000 :
V_408 |= V_422 ;
break;
default:
F_6 ( L_24 ,
V_25 ) ;
break;
}
if ( V_407 )
V_408 |= V_412 ;
F_5 ( V_408 , F_132 ( V_168 ) ) ;
V_10 -> V_411 [ V_168 ] = V_408 ;
F_5 ( V_67 , F_133 ( V_168 ) ) ;
}
return V_409 ;
}
static int F_135 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
unsigned int V_247 [] ,
unsigned int V_406 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_170 ;
unsigned int V_168 ;
unsigned int V_408 ;
int V_67 ;
int V_409 = 0 ;
for ( V_67 = 0 ; V_67 < V_406 ; V_67 ++ ) {
V_168 = F_103 ( V_247 [ V_67 ] ) ;
V_170 = F_74 ( V_247 [ V_67 ] ) ;
V_408 = F_136 ( V_168 ) ;
if ( V_59 -> V_405 ) {
if ( ( V_170 & 1 ) == 0 ) {
V_408 |= V_423 ;
V_409 = ( 1 << ( V_59 -> V_404 - 1 ) ) ;
} else {
V_409 = 0 ;
}
if ( V_170 & 2 )
V_408 |= V_424 ;
} else {
V_408 |= V_423 ;
V_409 = ( 1 << ( V_59 -> V_404 - 1 ) ) ;
}
if ( V_247 [ V_67 ] & V_425 )
V_408 |= V_426 ;
V_408 |= ( F_105 ( V_247 [ V_67 ] ) ==
V_281 ) ? V_427 : 0 ;
F_40 ( V_408 , V_428 ) ;
V_10 -> V_411 [ V_168 ] = V_408 ;
}
return V_409 ;
}
static int F_137 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
unsigned int V_247 [] , unsigned int V_406 ,
int V_407 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
if ( V_59 -> V_60 & V_61 )
return F_131 ( V_5 , V_102 , V_247 , V_406 ,
V_407 ) ;
else
return F_135 ( V_5 , V_102 , V_247 , V_406 ) ;
}
static int F_138 ( struct V_4 * V_5 ,
struct V_101 * V_102 , struct V_242 * V_243 ,
unsigned int * V_73 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_73 [ 0 ] = V_10 -> V_429 [ F_103 ( V_243 -> V_247 ) ] ;
return 1 ;
}
static int F_139 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 , unsigned int * V_73 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_168 = F_103 ( V_243 -> V_247 ) ;
unsigned int V_409 ;
V_409 = F_137 ( V_5 , V_102 , & V_243 -> V_247 , 1 , 0 ) ;
V_10 -> V_429 [ V_168 ] = V_73 [ 0 ] ;
if ( V_59 -> V_60 & V_61 ) {
F_40 ( V_73 [ 0 ] , F_140 ( V_168 ) ) ;
} else
F_40 ( V_73 [ 0 ] ^ V_409 ,
( V_168 ) ? V_430 : V_431 ) ;
return 1 ;
}
static int F_141 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 , unsigned int * V_73 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_168 = F_103 ( V_243 -> V_247 ) ;
unsigned int V_409 ;
F_142 ( 1 << V_168 , V_432 ) ;
V_409 = 1 << ( V_59 -> V_404 - 1 ) ;
F_137 ( V_5 , V_102 , & V_243 -> V_247 , 1 , 0 ) ;
V_10 -> V_429 [ V_168 ] = V_73 [ 0 ] ;
F_142 ( V_73 [ 0 ] ^ V_409 , F_143 ( V_168 ) ) ;
return 1 ;
}
static int F_144 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 , unsigned int * V_73 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
switch ( V_73 [ 0 ] ) {
case V_433 :
switch ( V_73 [ 1 ] ) {
case V_47 :
V_73 [ 2 ] = 1 + V_59 -> V_179 * sizeof( short ) ;
if ( V_10 -> V_40 )
V_73 [ 2 ] += V_10 -> V_40 -> V_434 ;
break;
case V_44 :
V_73 [ 2 ] = 0 ;
break;
default:
return - V_388 ;
break;
}
return 0 ;
default:
break;
}
return - V_388 ;
}
static int F_145 ( struct V_4 * V_5 , struct V_101 * V_102 ,
unsigned int V_387 )
{
const struct V_58 * V_59 V_193 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_161 ;
int V_435 ;
int V_67 ;
static const int V_66 = 1000 ;
if ( V_387 != 0 )
return - V_388 ;
V_102 -> V_105 -> V_385 = NULL ;
F_44 ( V_5 , V_17 ,
V_162 | V_163 , 0 ) ;
V_435 = V_163 ;
#ifdef F_24
V_10 -> V_16 ( V_5 , 1 , V_181 ) ;
if ( V_59 -> V_60 & V_174 )
F_41 ( V_5 , 0x6 , V_182 ) ;
V_161 = F_90 ( V_5 ) ;
if ( V_161 )
return V_161 ;
V_161 = F_60 ( V_5 ) ;
if ( V_161 < 0 )
return V_161 ;
#else
V_161 = F_76 ( V_5 , V_102 ) ;
if ( V_161 == 0 )
return - V_108 ;
V_435 |= V_162 ;
#endif
V_10 -> V_16 ( V_5 , V_10 -> V_436 | V_437 ,
V_438 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_436 , V_438 ) ;
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
F_35 ( 1 ) ;
if ( ( V_10 -> V_75 ( V_5 ,
V_439 ) &
V_440 ) == 0 )
break;
}
if ( V_67 == V_66 ) {
F_19 ( V_5 ,
L_25 ) ;
return - V_204 ;
}
V_10 -> V_16 ( V_5 , V_147 ,
V_158 ) ;
F_44 ( V_5 , V_17 , V_435 , 1 ) ;
V_10 -> V_16 ( V_5 ,
V_10 -> V_441 | V_442 | V_443 | V_444
| V_445 | V_446 ,
V_447 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_448 | V_449 ,
V_450 ) ;
return 0 ;
}
static int F_146 ( struct V_4 * V_5 , struct V_101 * V_102 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
const struct V_166 * V_167 = & V_102 -> V_105 -> V_167 ;
int V_74 ;
int V_67 ;
unsigned V_451 ;
if ( V_5 -> V_81 == 0 ) {
F_19 ( V_5 , L_22 ) ;
return - V_204 ;
}
V_10 -> V_16 ( V_5 , V_452 , V_209 ) ;
V_10 -> V_16 ( V_5 , V_453 , V_447 ) ;
if ( V_59 -> V_60 & V_174 ) {
F_142 ( V_454 , V_455 ) ;
V_74 = 0 ;
for ( V_67 = 0 ; V_67 < V_167 -> V_178 ; V_67 ++ ) {
int V_168 ;
V_168 = F_103 ( V_167 -> V_173 [ V_67 ] ) ;
V_74 |= 1 << V_168 ;
F_142 ( V_168 , V_456 ) ;
}
F_142 ( V_74 , V_457 ) ;
}
F_137 ( V_5 , V_102 , V_167 -> V_173 , V_167 -> V_178 , 1 ) ;
if ( V_167 -> V_324 == V_325 ) {
V_10 -> V_458 |= V_459 ;
V_10 -> V_458 &= ~ V_460 ;
} else {
V_10 -> V_458 &= ~ V_459 ;
V_10 -> V_458 |= V_460 ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_458 , V_461 ) ;
switch ( V_167 -> V_315 ) {
case V_317 :
case V_316 :
V_10 -> V_462 &=
~ ( V_463 | F_147 ( - 1 ) ) ;
V_10 -> V_462 |= V_464 | V_465 ;
V_10 -> V_16 ( V_5 , V_10 -> V_462 ,
V_466 ) ;
break;
case V_318 :
V_10 -> V_462 =
F_147 ( F_103 ( V_167 -> V_326 ) + 1 ) ;
if ( V_167 -> V_326 & V_327 )
V_10 -> V_462 |= V_463 ;
if ( V_167 -> V_326 & V_328 )
V_10 -> V_462 |= V_464 ;
V_10 -> V_16 ( V_5 , V_10 -> V_462 ,
V_466 ) ;
break;
default:
F_2 () ;
break;
}
V_10 -> V_436 &= ~ V_467 ;
V_10 -> V_16 ( V_5 , V_10 -> V_436 , V_438 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_458 , V_461 ) ;
V_10 -> V_468 &= ~ V_469 ;
V_10 -> V_16 ( V_5 , V_10 -> V_468 , V_470 ) ;
if ( V_167 -> V_324 == V_325 )
V_10 -> V_353 ( V_5 , 0xffffff , V_471 ) ;
else
V_10 -> V_353 ( V_5 , 0 , V_471 ) ;
V_10 -> V_16 ( V_5 , V_472 , V_447 ) ;
V_10 -> V_468 &= ~ V_473 ;
V_10 -> V_16 ( V_5 , V_10 -> V_468 , V_470 ) ;
switch ( V_167 -> V_324 ) {
case V_323 :
if ( V_59 -> V_60 & V_61 ) {
V_10 -> V_353 ( V_5 , V_167 -> V_333 - 1 ,
V_474 ) ;
V_10 -> V_16 ( V_5 , V_475 ,
V_447 ) ;
} else {
V_10 -> V_353 ( V_5 , V_167 -> V_333 ,
V_474 ) ;
V_10 -> V_16 ( V_5 , V_475 ,
V_447 ) ;
V_10 -> V_353 ( V_5 , V_167 -> V_333 - 1 ,
V_474 ) ;
}
break;
case V_325 :
V_10 -> V_353 ( V_5 , 0xffffff , V_474 ) ;
V_10 -> V_16 ( V_5 , V_475 , V_447 ) ;
V_10 -> V_353 ( V_5 , 0xffffff , V_474 ) ;
break;
default:
V_10 -> V_353 ( V_5 , 0 , V_474 ) ;
V_10 -> V_16 ( V_5 , V_475 , V_447 ) ;
V_10 -> V_353 ( V_5 , V_167 -> V_333 , V_474 ) ;
}
V_10 -> V_458 &=
~ ( F_148 ( 0x1f ) | V_476 |
F_149 ( 0x1f ) | V_477 ) ;
switch ( V_167 -> V_319 ) {
case V_320 :
V_10 -> V_448 &= ~ V_478 ;
V_451 =
F_111 ( V_5 , V_167 -> V_329 ,
V_305 ) ;
V_10 -> V_353 ( V_5 , 1 , V_479 ) ;
V_10 -> V_16 ( V_5 , V_480 , V_447 ) ;
V_10 -> V_353 ( V_5 , V_451 , V_479 ) ;
break;
case V_318 :
V_10 -> V_458 |=
F_149 ( V_167 -> V_329 ) ;
if ( V_167 -> V_329 & V_327 )
V_10 -> V_458 |= V_477 ;
V_10 -> V_448 |= V_478 ;
break;
default:
F_2 () ;
break;
}
V_10 -> V_16 ( V_5 , V_10 -> V_448 , V_450 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_458 , V_461 ) ;
V_10 -> V_468 &=
~ ( F_150 ( 3 ) | V_481 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_468 , V_470 ) ;
if ( V_167 -> V_331 > 1 ) {
V_10 -> V_458 |= V_482 ;
V_10 -> V_16 ( V_5 ,
F_151 ( V_167 -> V_331 -
1 ) |
F_152
( V_483 ) ,
V_484 ) ;
} else {
unsigned V_74 ;
V_10 -> V_458 &= ~ V_482 ;
V_74 = F_152 ( V_483 ) ;
if ( V_59 -> V_60 &
( V_61 | V_174 ) ) {
V_74 |= F_151 ( 0 ) ;
} else {
V_74 |=
F_151 ( F_103 ( V_167 -> V_173 [ 0 ] ) ) ;
}
V_10 -> V_16 ( V_5 , V_74 , V_484 ) ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_458 , V_461 ) ;
V_10 -> V_16 ( V_5 , V_446 | V_445 ,
V_447 ) ;
V_10 -> V_436 |= V_485 ;
V_10 -> V_16 ( V_5 , V_10 -> V_436 , V_438 ) ;
V_10 -> V_468 &= ~ V_486 ;
#ifdef F_24
V_10 -> V_468 |= V_487 ;
#else
V_10 -> V_468 |= V_488 ;
#endif
V_10 -> V_468 &= ~ V_489 ;
V_10 -> V_16 ( V_5 , V_10 -> V_468 , V_470 ) ;
V_74 = V_490 | V_491 |
V_492 ;
if ( V_59 -> V_179 )
V_74 |= V_493 ;
else
V_74 |= V_494 ;
#if 0
if (board->reg_type & ni_reg_m_series_mask)
bits |= AO_Number_Of_DAC_Packages;
#endif
V_10 -> V_16 ( V_5 , V_74 , V_495 ) ;
V_10 -> V_16 ( V_5 , V_496 , V_497 ) ;
V_10 -> V_16 ( V_5 , V_498 , V_209 ) ;
if ( V_167 -> V_324 == V_323 ) {
V_10 -> V_16 ( V_5 , V_145 ,
V_158 ) ;
F_44 ( V_5 , V_17 ,
V_499 , 1 ) ;
}
V_102 -> V_105 -> V_385 = & F_145 ;
return 0 ;
}
static int F_153 ( struct V_4 * V_5 , struct V_101 * V_102 ,
struct V_166 * V_167 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_171 = 0 ;
int V_312 ;
if ( ( V_167 -> V_12 & V_314 ) == 0 )
V_167 -> V_12 |= V_314 ;
V_171 |= F_115 ( & V_167 -> V_315 , V_317 | V_318 ) ;
V_171 |= F_115 ( & V_167 -> V_319 ,
V_320 | V_318 ) ;
V_171 |= F_115 ( & V_167 -> V_321 , V_316 ) ;
V_171 |= F_115 ( & V_167 -> V_322 , V_323 ) ;
V_171 |= F_115 ( & V_167 -> V_324 , V_323 | V_325 ) ;
if ( V_171 )
return 1 ;
V_171 |= F_116 ( V_167 -> V_315 ) ;
V_171 |= F_116 ( V_167 -> V_319 ) ;
V_171 |= F_116 ( V_167 -> V_324 ) ;
if ( V_171 )
return 2 ;
if ( V_167 -> V_315 == V_318 ) {
unsigned int V_312 = F_103 ( V_167 -> V_326 ) ;
if ( V_312 > 18 )
V_312 = 18 ;
V_312 |= ( V_167 -> V_326 & ( V_327 | V_328 ) ) ;
V_171 |= F_117 ( & V_167 -> V_326 , V_312 ) ;
} else {
V_171 |= F_117 ( & V_167 -> V_326 , 0 ) ;
}
if ( V_167 -> V_319 == V_320 ) {
V_171 |= F_118 ( & V_167 -> V_329 ,
V_59 -> V_500 ) ;
V_171 |= F_119 ( & V_167 -> V_329 ,
V_10 -> V_306 * 0xffffff ) ;
}
V_171 |= F_117 ( & V_167 -> V_330 , 0 ) ;
V_171 |= F_117 ( & V_167 -> V_331 , V_167 -> V_178 ) ;
if ( V_167 -> V_324 == V_323 )
V_171 |= F_119 ( & V_167 -> V_333 , 0x00ffffff ) ;
else
V_171 |= F_117 ( & V_167 -> V_333 , 0 ) ;
if ( V_171 )
return 3 ;
if ( V_167 -> V_319 == V_320 ) {
V_312 = V_167 -> V_329 ;
V_167 -> V_329 =
F_112 ( V_5 , F_111 ( V_5 ,
V_167 -> V_329 ,
V_167 ->
V_12 &
V_334 ) ) ;
if ( V_312 != V_167 -> V_329 )
V_171 ++ ;
}
if ( V_171 )
return 4 ;
if ( V_171 )
return 5 ;
return 0 ;
}
static int F_154 ( struct V_4 * V_5 , struct V_101 * V_102 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
F_27 ( V_5 ) ;
V_10 -> V_16 ( V_5 , V_452 , V_209 ) ;
V_10 -> V_16 ( V_5 , V_453 , V_447 ) ;
F_44 ( V_5 , V_17 , ~ 0 , 0 ) ;
V_10 -> V_16 ( V_5 , V_490 , V_495 ) ;
V_10 -> V_16 ( V_5 , 0x3f98 , V_158 ) ;
V_10 -> V_16 ( V_5 , V_490 | V_491 |
V_492 , V_495 ) ;
V_10 -> V_16 ( V_5 , 0 , V_484 ) ;
V_10 -> V_16 ( V_5 , 0 , V_497 ) ;
V_10 -> V_441 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_441 , V_447 ) ;
V_10 -> V_448 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_448 , V_450 ) ;
V_10 -> V_458 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_458 , V_461 ) ;
V_10 -> V_468 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_468 , V_470 ) ;
if ( V_59 -> V_60 & V_61 )
V_10 -> V_436 = V_501 ;
else
V_10 -> V_436 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_436 , V_438 ) ;
V_10 -> V_462 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_462 ,
V_466 ) ;
if ( V_59 -> V_60 & V_174 ) {
unsigned V_502 = 0 ;
unsigned V_67 ;
for ( V_67 = 0 ; V_67 < V_102 -> V_253 ; ++ V_67 )
V_502 |= 1 << V_67 ;
F_142 ( V_502 , V_432 ) ;
F_142 ( V_454 , V_455 ) ;
}
V_10 -> V_16 ( V_5 , V_498 , V_209 ) ;
return 0 ;
}
static int F_155 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 ,
unsigned int * V_73 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_161 ;
V_161 = F_156 ( V_5 , V_102 , V_243 , V_73 , 0 ) ;
if ( V_161 )
return V_161 ;
V_10 -> V_503 &= ~ V_504 ;
V_10 -> V_503 |= F_157 ( V_102 -> V_505 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_503 , V_506 ) ;
return V_243 -> V_164 ;
}
static int F_158 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 ,
unsigned int * V_73 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( ( V_73 [ 0 ] & ( V_507 | V_508 ) ) && V_10 -> V_509 )
return - V_42 ;
if ( F_159 ( V_102 , V_73 ) ) {
V_10 -> V_510 &= ~ V_511 ;
V_10 -> V_510 |= F_160 ( V_102 -> V_512 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_510 ,
V_513 ) ;
}
V_73 [ 1 ] = V_10 -> V_75 ( V_5 , V_514 ) ;
return V_243 -> V_164 ;
}
static int F_161 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 ,
unsigned int * V_73 )
{
struct V_9 * V_10 V_193 = V_5 -> V_11 ;
int V_161 ;
V_161 = F_156 ( V_5 , V_102 , V_243 , V_73 , 0 ) ;
if ( V_161 )
return V_161 ;
F_33 ( V_102 -> V_505 , V_515 ) ;
return V_243 -> V_164 ;
}
static int F_162 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 ,
unsigned int * V_73 )
{
struct V_9 * V_10 V_193 = V_5 -> V_11 ;
if ( F_159 ( V_102 , V_73 ) )
F_33 ( V_102 -> V_512 , V_516 ) ;
V_73 [ 1 ] = F_34 ( V_517 ) ;
return V_243 -> V_164 ;
}
static int F_163 ( struct V_4 * V_5 ,
struct V_101 * V_102 , struct V_166 * V_167 )
{
int V_171 = 0 ;
int V_312 ;
unsigned V_67 ;
V_171 |= F_115 ( & V_167 -> V_315 , V_317 ) ;
V_171 |= F_115 ( & V_167 -> V_319 , V_318 ) ;
V_171 |= F_115 ( & V_167 -> V_321 , V_316 ) ;
V_171 |= F_115 ( & V_167 -> V_322 , V_323 ) ;
V_171 |= F_115 ( & V_167 -> V_324 , V_325 ) ;
if ( V_171 )
return 1 ;
if ( V_171 )
return 2 ;
V_171 |= F_117 ( & V_167 -> V_326 , 0 ) ;
V_312 = V_167 -> V_329 ;
V_312 &= F_164 ( V_518 , 0 , 0 , V_327 ) ;
if ( V_312 != V_167 -> V_329 )
V_171 |= - V_388 ;
V_171 |= F_117 ( & V_167 -> V_330 , 0 ) ;
V_171 |= F_117 ( & V_167 -> V_331 , V_167 -> V_178 ) ;
V_171 |= F_117 ( & V_167 -> V_333 , 0 ) ;
if ( V_171 )
return 3 ;
if ( V_171 )
return 4 ;
for ( V_67 = 0 ; V_67 < V_167 -> V_178 ; ++ V_67 ) {
if ( V_167 -> V_173 [ V_67 ] != V_67 )
V_171 = 1 ;
}
if ( V_171 )
return 5 ;
return 0 ;
}
static int F_165 ( struct V_4 * V_5 , struct V_101 * V_102 )
{
struct V_9 * V_10 V_193 = V_5 -> V_11 ;
const struct V_166 * V_167 = & V_102 -> V_105 -> V_167 ;
unsigned V_519 = V_520 | V_521 ;
int V_190 ;
F_33 ( V_522 , V_523 ) ;
switch ( V_167 -> V_319 ) {
case V_318 :
V_519 |=
F_103 ( V_167 -> V_329 ) &
V_518 ;
break;
default:
F_2 () ;
break;
}
if ( V_167 -> V_329 & V_327 )
V_519 |= V_524 ;
F_33 ( V_519 , V_525 ) ;
if ( V_102 -> V_505 ) {
F_33 ( V_102 -> V_512 , V_526 ) ;
F_33 ( V_527 , V_523 ) ;
F_33 ( V_102 -> V_505 , V_528 ) ;
} else {
F_19 ( V_5 ,
L_26 ) ;
return - V_204 ;
}
V_190 = F_23 ( V_5 ) ;
if ( V_190 < 0 )
return V_190 ;
V_102 -> V_105 -> V_385 = & V_529 ;
return 0 ;
}
static int V_529 ( struct V_4 * V_5 , struct V_101 * V_102 ,
unsigned int V_387 )
{
#ifdef F_24
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_12 ;
#endif
int V_190 = 0 ;
unsigned V_67 ;
const unsigned V_66 = 1000 ;
V_102 -> V_105 -> V_385 = NULL ;
F_91 ( V_102 -> V_105 , V_102 -> V_105 -> V_203 ) ;
#ifdef F_24
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_55 ) {
F_88 ( V_10 -> V_55 , 32 , 32 ) ;
F_89 ( V_10 -> V_55 ) ;
} else {
F_19 ( V_5 , L_27 ) ;
V_190 = - V_204 ;
}
F_8 ( & V_10 -> V_38 , V_12 ) ;
if ( V_190 < 0 )
return V_190 ;
#endif
for ( V_67 = 0 ; V_67 < V_66 ; ++ V_67 ) {
if ( F_34 ( V_530 ) & V_531 )
break;
F_35 ( 10 ) ;
}
if ( V_67 == V_66 ) {
F_19 ( V_5 , L_28 ) ;
F_166 ( V_5 , V_102 ) ;
return - V_204 ;
}
F_33 ( V_532 | V_533 |
V_534 ,
V_523 ) ;
return V_190 ;
}
static int F_166 ( struct V_4 * V_5 , struct V_101 * V_102 )
{
struct V_9 * V_10 V_193 = V_5 -> V_11 ;
F_33 ( V_535 | V_536 |
V_537 |
V_538 ,
V_523 ) ;
F_33 ( 0 , V_528 ) ;
F_29 ( V_5 ) ;
return 0 ;
}
static void F_55 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 V_193 = V_5 -> V_11 ;
unsigned V_539 ;
struct V_101 * V_102 = & V_5 -> V_103 [ V_540 ] ;
#ifdef F_24
unsigned long V_12 ;
#endif
if ( ( V_59 -> V_60 & V_61 ) == 0 )
return;
#ifdef F_24
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_55 ) {
unsigned V_541 =
F_47 ( V_10 -> V_55 ) ;
if ( V_541 & V_94 ) {
F_48 ( V_95 ,
V_10 -> V_40 -> V_96 +
F_49 ( V_10 -> V_55 -> V_26 ) ) ;
}
F_59 ( V_10 -> V_55 , V_102 -> V_105 ) ;
}
F_8 ( & V_10 -> V_38 , V_12 ) ;
#endif
V_539 = F_34 ( V_530 ) ;
if ( V_539 & ( V_542 | V_543 ) ) {
F_33 ( V_544 , V_523 ) ;
V_102 -> V_105 -> V_111 |= V_141 ;
}
if ( V_539 & V_545 ) {
F_33 ( V_537 ,
V_523 ) ;
}
F_68 ( V_5 , V_102 ) ;
}
static int F_167 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 , unsigned int * V_73 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_171 = V_243 -> V_164 ;
unsigned char V_546 , V_547 = 0 ;
if ( V_243 -> V_164 != 2 )
return - V_388 ;
switch ( V_73 [ 0 ] ) {
case V_548 :
V_10 -> V_549 = 1 ;
V_10 -> V_503 |= V_550 ;
if ( V_73 [ 1 ] == V_551 ) {
V_10 -> V_549 = 0 ;
V_10 -> V_503 &= ~ ( V_550 |
V_552 ) ;
V_73 [ 1 ] = V_551 ;
V_10 -> V_509 = V_73 [ 1 ] ;
} else if ( V_73 [ 1 ] <= V_553 ) {
V_10 -> V_503 &= ~ V_554 ;
V_10 -> V_555 |= V_556 ;
V_10 -> V_555 &= ~ V_557 ;
V_73 [ 1 ] = V_553 ;
V_10 -> V_509 = V_73 [ 1 ] ;
} else if ( V_73 [ 1 ] <= V_558 ) {
V_10 -> V_503 &= ~ V_554 ;
V_10 -> V_555 |= V_556 |
V_557 ;
V_73 [ 1 ] = V_558 ;
V_10 -> V_509 = V_73 [ 1 ] ;
} else if ( V_73 [ 1 ] <= V_559 ) {
V_10 -> V_503 |= V_554 ;
V_10 -> V_555 |= V_556 |
V_557 ;
V_73 [ 1 ] = V_559 ;
V_10 -> V_509 = V_73 [ 1 ] ;
} else {
V_10 -> V_503 &= ~ ( V_550 |
V_552 ) ;
V_10 -> V_549 = 0 ;
V_73 [ 1 ] = ( V_73 [ 1 ] / 1000 ) * 1000 ;
V_10 -> V_509 = V_73 [ 1 ] ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_503 ,
V_506 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_555 ,
V_560 ) ;
return 1 ;
break;
case V_561 :
if ( V_10 -> V_509 == 0 )
return - V_388 ;
V_546 = V_73 [ 1 ] & 0xFF ;
if ( V_10 -> V_549 ) {
V_171 = F_168 ( V_5 , V_102 , V_546 ,
& V_547 ) ;
} else if ( V_10 -> V_509 > 0 ) {
V_171 = F_169 ( V_5 , V_102 , V_546 ,
& V_547 ) ;
} else {
F_6 ( L_29 ) ;
return - V_388 ;
}
if ( V_171 < 0 )
return V_171 ;
V_73 [ 1 ] = V_547 & 0xFF ;
return V_243 -> V_164 ;
break;
default:
return - V_388 ;
}
}
static int F_168 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
unsigned char V_562 ,
unsigned char * V_563 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_564 ;
int V_171 = 0 , V_239 = 20 ;
V_10 -> V_510 &= ~ V_565 ;
V_10 -> V_510 |= F_170 ( V_562 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_510 , V_513 ) ;
V_564 = V_10 -> V_75 ( V_5 , V_566 ) ;
if ( V_564 & V_567 ) {
V_171 = - V_42 ;
goto Error;
}
V_10 -> V_503 |= V_568 ;
V_10 -> V_16 ( V_5 , V_10 -> V_503 , V_506 ) ;
V_10 -> V_503 &= ~ V_568 ;
while ( ( V_564 =
V_10 -> V_75 ( V_5 ,
V_566 ) ) &
V_567 ) {
F_35 ( ( V_10 -> V_509 + 999 ) / 1000 ) ;
if ( -- V_239 < 0 ) {
F_6
( L_30 ) ;
V_171 = - V_251 ;
goto Error;
}
}
F_35 ( ( V_10 -> V_509 + 999 ) / 1000 ) ;
if ( V_563 != NULL )
* V_563 = V_10 -> V_75 ( V_5 , V_569 ) ;
Error:
V_10 -> V_16 ( V_5 , V_10 -> V_503 , V_506 ) ;
return V_171 ;
}
static int F_169 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
unsigned char V_562 ,
unsigned char * V_563 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned char V_244 , V_570 = 0 ;
F_35 ( ( V_10 -> V_509 + 999 ) / 1000 ) ;
for ( V_244 = 0x80 ; V_244 ; V_244 >>= 1 ) {
V_10 -> V_510 &= ~ V_508 ;
if ( V_562 & V_244 )
V_10 -> V_510 |= V_508 ;
V_10 -> V_16 ( V_5 , V_10 -> V_510 ,
V_513 ) ;
V_10 -> V_503 |= V_552 ;
V_10 -> V_16 ( V_5 , V_10 -> V_503 ,
V_506 ) ;
F_35 ( ( V_10 -> V_509 + 999 ) / 2000 ) ;
V_10 -> V_503 &= ~ V_552 ;
V_10 -> V_16 ( V_5 , V_10 -> V_503 ,
V_506 ) ;
F_35 ( ( V_10 -> V_509 + 999 ) / 2000 ) ;
if ( V_10 -> V_75 ( V_5 ,
V_514 ) & V_507 ) {
V_570 |= V_244 ;
}
}
if ( V_563 )
* V_563 = V_570 ;
return 0 ;
}
static void F_171 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_10 ) {
if ( V_10 -> V_52 )
F_172 ( V_10 -> V_52 ) ;
}
}
static void F_173 ( struct V_4 * V_5 , struct V_101 * V_102 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_102 -> V_253 ; V_67 ++ ) {
F_39 ( V_5 , F_136 ( V_67 ) | 0x0 ,
V_571 ) ;
}
F_142 ( 0x0 , V_572 ) ;
}
static unsigned F_174 ( enum V_573 V_6 )
{
unsigned V_574 ;
switch ( V_6 ) {
case V_575 :
V_574 = F_175 ( 0 ) ;
break;
case V_576 :
V_574 = F_175 ( 1 ) ;
break;
case V_577 :
V_574 = F_176 ( 0 ) ;
break;
case V_578 :
V_574 = F_176 ( 1 ) ;
break;
case V_579 :
V_574 = F_177 ( 0 ) ;
break;
case V_580 :
V_574 = F_177 ( 1 ) ;
break;
case V_581 :
V_574 = F_178 ( 0 ) ;
break;
case V_582 :
V_574 = F_178 ( 1 ) ;
break;
case V_583 :
V_574 = F_179 ( 0 ) ;
break;
case V_584 :
V_574 = F_179 ( 1 ) ;
break;
case V_585 :
V_574 = F_180 ( 0 ) ;
break;
case V_586 :
V_574 = F_180 ( 1 ) ;
break;
case V_587 :
V_574 = F_181 ( 0 ) ;
break;
case V_588 :
V_574 = F_181 ( 1 ) ;
break;
case V_589 :
V_574 = F_182 ( 0 ) ;
break;
case V_590 :
V_574 = F_182 ( 1 ) ;
break;
case V_591 :
V_574 = V_592 ;
break;
case V_593 :
V_574 = V_209 ;
break;
case V_594 :
V_574 = V_566 ;
break;
case V_595 :
V_574 = V_439 ;
break;
case V_596 :
V_574 = V_125 ;
break;
case V_597 :
V_574 = V_158 ;
break;
case V_598 :
V_574 = V_91 ;
break;
case V_599 :
V_574 = V_92 ;
break;
case V_600 :
V_574 = V_14 ;
break;
case V_601 :
V_574 = V_17 ;
break;
default:
F_6 ( L_31 ,
V_25 , V_6 ) ;
F_2 () ;
return 0 ;
break;
}
return V_574 ;
}
static void F_183 ( struct V_602 * V_603 , unsigned V_74 ,
enum V_573 V_6 )
{
struct V_4 * V_5 = V_603 -> V_52 -> V_5 ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned V_574 ;
static const unsigned V_604 = V_605 | V_606 ;
static const unsigned V_607 =
V_608 | V_609 ;
static const unsigned V_610 =
V_611 | V_612 ;
switch ( V_6 ) {
case V_613 :
F_40 ( V_74 , V_614 ) ;
break;
case V_615 :
F_40 ( V_74 , V_616 ) ;
break;
case V_617 :
F_40 ( V_74 , V_618 ) ;
break;
case V_619 :
F_40 ( V_74 , V_620 ) ;
break;
case V_621 :
F_40 ( V_74 , V_622 ) ;
break;
case V_623 :
F_40 ( V_74 , V_624 ) ;
break;
case V_625 :
F_40 ( V_74 , V_626 ) ;
break;
case V_627 :
F_40 ( V_74 , V_628 ) ;
break;
case V_585 :
case V_586 :
case V_587 :
case V_588 :
V_574 = F_174 ( V_6 ) ;
V_10 -> V_353 ( V_5 , V_74 , V_574 ) ;
break;
case V_600 :
F_17 ( V_74 & ~ V_607 ) ;
F_3 ( V_5 , V_14 ,
V_607 , V_74 ) ;
break;
case V_601 :
F_17 ( V_74 & ~ V_610 ) ;
F_3 ( V_5 , V_17 ,
V_610 , V_74 ) ;
break;
case V_593 :
F_17 ( V_74 & ~ V_604 ) ;
default:
V_574 = F_174 ( V_6 ) ;
V_10 -> V_16 ( V_5 , V_74 , V_574 ) ;
}
}
static unsigned F_184 ( struct V_602 * V_603 ,
enum V_573 V_6 )
{
struct V_4 * V_5 = V_603 -> V_52 -> V_5 ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned V_574 ;
switch ( V_6 ) {
case V_629 :
return F_43 ( V_630 ) ;
case V_631 :
return F_43 ( V_632 ) ;
case V_579 :
case V_580 :
case V_581 :
case V_582 :
V_574 = F_174 ( V_6 ) ;
return V_10 -> V_633 ( V_5 , V_574 ) ;
default:
V_574 = F_174 ( V_6 ) ;
return V_10 -> V_75 ( V_5 , V_574 ) ;
break;
}
return 0 ;
}
static int F_185 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 , unsigned int * V_73 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_73 [ 0 ] = V_10 -> V_555 & V_634 ;
return 1 ;
}
static int F_186 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 , unsigned int * V_73 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_10 -> V_555 &= ~ V_635 ;
V_10 -> V_16 ( V_5 , V_10 -> V_555 ,
V_560 ) ;
V_10 -> V_555 &= ~ V_634 ;
V_10 -> V_555 |= F_187 ( V_73 [ 0 ] ) ;
V_10 -> V_555 |= V_635 ;
V_10 -> V_16 ( V_5 , V_10 -> V_555 ,
V_560 ) ;
return V_243 -> V_164 ;
}
static int F_188 ( struct V_4 * V_5 ,
unsigned int V_636 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
switch ( V_636 ) {
case V_637 :
V_10 -> V_555 &= ~ V_638 ;
break;
case V_639 :
V_10 -> V_555 |= V_638 ;
break;
default:
return - V_388 ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_555 ,
V_560 ) ;
return 3 ;
}
static void F_189 ( struct V_4 * V_5 ,
unsigned int * V_636 ,
unsigned int * V_640 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_10 -> V_555 & V_638 ) {
* V_636 = V_639 ;
* V_640 = V_641 ;
} else {
* V_636 = V_637 ;
* V_640 = V_642 * 2 ;
}
}
static int F_190 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 , unsigned int * V_73 )
{
switch ( V_73 [ 0 ] ) {
case V_643 :
return F_188 ( V_5 , V_73 [ 1 ] ) ;
break;
case V_644 :
F_189 ( V_5 , & V_73 [ 1 ] , & V_73 [ 2 ] ) ;
return 3 ;
default:
break;
}
return - V_388 ;
}
static int F_191 ( struct V_4 * V_5 )
{
struct V_9 * V_10 ;
V_10 = F_192 ( V_5 , sizeof( * V_10 ) ) ;
if ( ! V_10 )
return - V_645 ;
F_193 ( & V_10 -> V_77 ) ;
F_193 ( & V_10 -> V_13 ) ;
F_193 ( & V_10 -> V_38 ) ;
return 0 ;
}
static int F_194 ( int V_43 , int V_646 , int V_73 , unsigned long V_647 )
{
struct V_4 * V_5 = (struct V_4 * ) V_647 ;
struct V_9 * V_10 V_193 = V_5 -> V_11 ;
if ( V_43 ) {
F_5 ( V_73 , V_648 + 2 * V_646 ) ;
return 0 ;
} else {
return F_81 ( V_648 + 2 * V_646 ) ;
}
}
static int F_195 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 , unsigned int * V_73 )
{
V_73 [ 0 ] = F_196 ( V_5 , F_103 ( V_243 -> V_247 ) ) ;
return 1 ;
}
static int F_196 ( struct V_4 * V_5 , int V_76 )
{
struct V_9 * V_10 V_193 = V_5 -> V_11 ;
int V_649 ;
int V_650 ;
V_650 = 0x0300 | ( ( V_76 & 0x100 ) << 3 ) | ( V_76 & 0xff ) ;
F_5 ( 0x04 , V_651 ) ;
for ( V_649 = 0x8000 ; V_649 ; V_649 >>= 1 ) {
F_5 ( 0x04 | ( ( V_649 & V_650 ) ? 0x02 : 0 ) ,
V_651 ) ;
F_5 ( 0x05 | ( ( V_649 & V_650 ) ? 0x02 : 0 ) ,
V_651 ) ;
}
V_650 = 0 ;
for ( V_649 = 0x80 ; V_649 ; V_649 >>= 1 ) {
F_5 ( 0x04 , V_651 ) ;
F_5 ( 0x05 , V_651 ) ;
V_650 |= ( ( F_81 ( V_194 ) & V_652 ) ? V_649 : 0 ) ;
}
F_5 ( 0x00 , V_651 ) ;
return V_650 ;
}
static int F_197 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 ,
unsigned int * V_73 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_73 [ 0 ] = V_10 -> V_653 [ F_103 ( V_243 -> V_247 ) ] ;
return 1 ;
}
static int F_198 ( struct V_4 * V_5 , unsigned int * V_73 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_73 [ 1 ] = V_10 -> V_654 * V_10 -> V_306 ;
V_73 [ 2 ] = V_10 -> V_655 * V_10 -> V_306 ;
return 3 ;
}
static int F_199 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 , unsigned int * V_73 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned V_656 , V_657 ;
switch ( V_73 [ 0 ] ) {
case V_658 :
switch ( V_73 [ 1 ] ) {
case V_305 :
V_656 =
( V_73 [ 2 ] +
V_10 -> V_306 / 2 ) / V_10 -> V_306 ;
break;
case V_307 :
V_656 = V_73 [ 2 ] / V_10 -> V_306 ;
break;
case V_308 :
V_656 =
( V_73 [ 2 ] + V_10 -> V_306 -
1 ) / V_10 -> V_306 ;
break;
default:
return - V_388 ;
break;
}
switch ( V_73 [ 3 ] ) {
case V_305 :
V_657 =
( V_73 [ 4 ] +
V_10 -> V_306 / 2 ) / V_10 -> V_306 ;
break;
case V_307 :
V_657 = V_73 [ 4 ] / V_10 -> V_306 ;
break;
case V_308 :
V_657 =
( V_73 [ 4 ] + V_10 -> V_306 -
1 ) / V_10 -> V_306 ;
break;
default:
return - V_388 ;
break;
}
if ( V_656 * V_10 -> V_306 != V_73 [ 2 ] ||
V_657 * V_10 -> V_306 != V_73 [ 4 ] ) {
V_73 [ 2 ] = V_656 * V_10 -> V_306 ;
V_73 [ 4 ] = V_657 * V_10 -> V_306 ;
return - V_403 ;
}
F_33 ( F_200 ( V_656 ) |
F_201 ( V_657 ) ,
V_659 ) ;
V_10 -> V_654 = V_656 ;
V_10 -> V_655 = V_657 ;
return 5 ;
break;
case V_660 :
return F_198 ( V_5 , V_73 ) ;
break;
default:
return - V_388 ;
break;
}
return 0 ;
}
static int F_202 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 , unsigned int * V_73 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned V_656 , V_657 ;
switch ( V_73 [ 0 ] ) {
case V_658 :
switch ( V_73 [ 1 ] ) {
case V_305 :
V_656 =
( V_73 [ 2 ] +
V_10 -> V_306 / 2 ) / V_10 -> V_306 ;
break;
case V_307 :
V_656 = V_73 [ 2 ] / V_10 -> V_306 ;
break;
case V_308 :
V_656 =
( V_73 [ 2 ] + V_10 -> V_306 -
1 ) / V_10 -> V_306 ;
break;
default:
return - V_388 ;
break;
}
switch ( V_73 [ 3 ] ) {
case V_305 :
V_657 =
( V_73 [ 4 ] +
V_10 -> V_306 / 2 ) / V_10 -> V_306 ;
break;
case V_307 :
V_657 = V_73 [ 4 ] / V_10 -> V_306 ;
break;
case V_308 :
V_657 =
( V_73 [ 4 ] + V_10 -> V_306 -
1 ) / V_10 -> V_306 ;
break;
default:
return - V_388 ;
break;
}
if ( V_656 * V_10 -> V_306 != V_73 [ 2 ] ||
V_657 * V_10 -> V_306 != V_73 [ 4 ] ) {
V_73 [ 2 ] = V_656 * V_10 -> V_306 ;
V_73 [ 4 ] = V_657 * V_10 -> V_306 ;
return - V_403 ;
}
F_33 ( V_656 , V_661 ) ;
V_10 -> V_654 = V_656 ;
F_33 ( V_657 , V_662 ) ;
V_10 -> V_655 = V_657 ;
return 5 ;
break;
case V_660 :
return F_198 ( V_5 , V_73 ) ;
default:
return - V_388 ;
break;
}
return 0 ;
}
static int F_203 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 , unsigned int * V_73 )
{
F_204 ( V_5 , F_103 ( V_243 -> V_247 ) , V_73 [ 0 ] ) ;
return 1 ;
}
static int F_205 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 , unsigned int * V_73 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_73 [ 0 ] = V_10 -> V_663 [ F_103 ( V_243 -> V_247 ) ] ;
return 1 ;
}
static void F_206 ( struct V_4 * V_5 , struct V_101 * V_102 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_67 , V_664 ;
int V_665 ;
int V_406 = 0 ;
int V_666 ;
int V_667 = 0 ;
int type ;
int V_168 ;
type = V_59 -> V_668 [ 0 ] ;
if ( type == V_669 )
return;
V_666 = V_663 [ type ] . V_666 ;
for ( V_67 = 0 ; V_67 < 3 ; V_67 ++ ) {
type = V_59 -> V_668 [ V_67 ] ;
if ( type == V_669 )
break;
if ( V_663 [ type ] . V_666 != V_666 )
V_667 = 1 ;
V_406 += V_663 [ type ] . V_406 ;
}
V_665 = V_67 ;
V_102 -> V_253 = V_406 ;
if ( V_667 ) {
unsigned int * V_670 ;
if ( V_406 > V_671 )
F_6 ( L_32 ) ;
V_102 -> V_670 = V_670 = V_10 -> V_672 ;
V_168 = 0 ;
for ( V_67 = 0 ; V_67 < V_665 ; V_67 ++ ) {
type = V_59 -> V_668 [ V_67 ] ;
for ( V_664 = 0 ; V_664 < V_663 [ type ] . V_406 ; V_664 ++ ) {
V_670 [ V_168 ] =
( 1 << V_663 [ type ] . V_666 ) - 1 ;
V_168 ++ ;
}
}
for ( V_168 = 0 ; V_168 < V_102 -> V_253 ; V_168 ++ )
F_204 ( V_5 , V_67 , V_102 -> V_670 [ V_67 ] / 2 ) ;
} else {
type = V_59 -> V_668 [ 0 ] ;
V_102 -> V_673 = ( 1 << V_663 [ type ] . V_666 ) - 1 ;
for ( V_168 = 0 ; V_168 < V_102 -> V_253 ; V_168 ++ )
F_204 ( V_5 , V_67 , V_102 -> V_673 / 2 ) ;
}
}
static void F_204 ( struct V_4 * V_5 , int V_76 , int V_674 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_675 = 0 , V_74 = 0 , V_649 , V_650 = 0 ;
int V_67 ;
int type ;
if ( V_10 -> V_663 [ V_76 ] == V_674 )
return;
V_10 -> V_663 [ V_76 ] = V_674 ;
for ( V_67 = 0 ; V_67 < 3 ; V_67 ++ ) {
type = V_59 -> V_668 [ V_67 ] ;
if ( type == V_669 )
break;
if ( V_76 < V_663 [ type ] . V_406 ) {
V_74 = V_663 [ type ] . F_207 ( V_76 , V_674 , & V_650 ) ;
V_675 = F_208 ( V_67 ) ;
break;
}
V_76 -= V_663 [ type ] . V_406 ;
}
for ( V_649 = 1 << ( V_74 - 1 ) ; V_649 ; V_649 >>= 1 ) {
F_5 ( ( ( V_649 & V_650 ) ? 0x02 : 0 ) , V_651 ) ;
F_35 ( 1 ) ;
F_5 ( 1 | ( ( V_649 & V_650 ) ? 0x02 : 0 ) , V_651 ) ;
F_35 ( 1 ) ;
}
F_5 ( V_675 , V_651 ) ;
F_35 ( 1 ) ;
F_5 ( 0 , V_651 ) ;
}
static int F_209 ( int V_76 , int V_674 , int * V_650 )
{
V_76 ++ ;
* V_650 = ( ( V_76 & 0x1 ) << 11 ) |
( ( V_76 & 0x2 ) << 9 ) |
( ( V_76 & 0x4 ) << 7 ) | ( ( V_76 & 0x8 ) << 5 ) | ( V_674 & 0xff ) ;
return 12 ;
}
static int F_210 ( int V_76 , int V_674 , int * V_650 )
{
* V_650 = ( ( V_76 & 0x7 ) << 8 ) | ( V_674 & 0xff ) ;
return 11 ;
}
static int F_211 ( int V_76 , int V_674 , int * V_650 )
{
* V_650 = V_674 & 0xfff ;
return 12 ;
}
static int F_212 ( int V_76 , int V_674 , int * V_650 )
{
* V_650 = ( V_674 & 0xfff ) | ( V_76 ? 0xc000 : 0xa000 ) ;
return 16 ;
}
static int F_213 ( int V_76 , int V_674 , int * V_650 )
{
* V_650 = ( ( V_76 & 0xf ) << 8 ) | ( V_674 & 0xff ) ;
return 12 ;
}
static int F_214 ( int V_76 , int V_674 , int * V_650 )
{
* V_650 = ( ( V_76 + 1 ) << 8 ) | ( V_674 & 0xff ) ;
return 12 ;
}
static int F_215 ( struct V_4 * V_5 , struct V_101 * V_102 )
{
struct V_602 * V_603 = V_102 -> V_11 ;
int V_190 ;
V_190 = F_21 ( V_5 , V_603 -> V_1 ,
V_44 ) ;
if ( V_190 ) {
F_19 ( V_5 ,
L_33 ) ;
return V_190 ;
}
F_216 ( V_603 , NULL , NULL , NULL , NULL ) ;
F_30 ( V_5 , V_603 -> V_1 , 1 ) ;
return F_217 ( V_5 , V_102 ) ;
}
static int F_218 ( struct V_4 * V_5 , struct V_101 * V_102 )
{
struct V_602 * V_603 = V_102 -> V_11 ;
int V_190 ;
V_190 = F_219 ( V_603 ) ;
F_30 ( V_5 , V_603 -> V_1 , 0 ) ;
F_28 ( V_5 , V_603 -> V_1 ) ;
return V_190 ;
}
static int F_220 ( struct V_4 * V_5 , unsigned V_168 ,
unsigned V_676 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned V_677 ;
unsigned V_678 ;
if ( ( V_676 & 0x1f ) != V_676 )
return - V_388 ;
V_677 = 1 + V_168 / 3 ;
V_678 = V_677 - 1 ;
V_10 -> V_679 [ V_678 ] &=
~ F_221 ( V_168 ) ;
V_10 -> V_679 [ V_678 ] |=
F_222 ( V_168 , V_676 ) ;
F_40 ( V_10 -> V_679 [ V_678 ] ,
F_223 ( V_677 ) ) ;
return 2 ;
}
static int F_224 ( struct V_4 * V_5 , unsigned V_168 ,
unsigned V_676 )
{
if ( V_676 != F_225 ( V_5 , V_168 ) )
return - V_388 ;
return 2 ;
}
static int F_226 ( struct V_4 * V_5 , unsigned V_168 ,
unsigned V_676 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
if ( V_59 -> V_60 & V_61 )
return F_220 ( V_5 , V_168 , V_676 ) ;
else
return F_224 ( V_5 , V_168 , V_676 ) ;
}
static unsigned F_227 ( struct V_4 * V_5 ,
unsigned V_168 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
const unsigned V_678 = V_168 / 3 ;
return F_228 ( V_168 ,
V_10 ->
V_679
[ V_678 ] ) ;
}
static unsigned F_225 ( struct V_4 * V_5 , unsigned V_168 )
{
switch ( V_168 ) {
case 0 :
return V_680 ;
break;
case 1 :
return V_681 ;
break;
case 2 :
return V_682 ;
break;
case 3 :
return V_683 ;
break;
case 4 :
return V_684 ;
break;
case 5 :
return V_685 ;
break;
case 6 :
return V_686 ;
break;
case 7 :
return V_687 ;
break;
case 8 :
return V_688 ;
break;
case 9 :
return V_689 ;
break;
default:
F_6 ( L_34 , V_25 ) ;
break;
}
return 0 ;
}
static unsigned F_229 ( struct V_4 * V_5 , unsigned V_168 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
if ( V_59 -> V_60 & V_61 )
return F_227 ( V_5 , V_168 ) ;
else
return F_225 ( V_5 , V_168 ) ;
}
static int F_230 ( struct V_4 * V_5 , unsigned V_690 ,
enum V_691 V_692 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 V_193 = V_5 -> V_11 ;
unsigned V_74 ;
if ( ( V_59 -> V_60 & V_61 ) == 0 )
return - V_693 ;
V_74 = F_34 ( V_694 ) ;
V_74 &= ~ F_231 ( V_690 ) ;
V_74 |= F_232 ( V_690 , V_692 ) ;
F_33 ( V_74 , V_694 ) ;
return 0 ;
}
static int F_233 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 ,
unsigned int * V_73 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 V_193 = V_5 -> V_11 ;
if ( ! ( V_59 -> V_60 & V_61 ) )
return - V_693 ;
if ( F_159 ( V_102 , V_73 ) )
F_40 ( V_102 -> V_512 , V_695 ) ;
V_73 [ 1 ] = F_43 ( V_696 ) ;
return V_243 -> V_164 ;
}
static int F_234 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 , unsigned int * V_73 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_168 ;
if ( V_243 -> V_164 < 1 )
return - V_388 ;
V_168 = F_103 ( V_243 -> V_247 ) ;
switch ( V_73 [ 0 ] ) {
case V_47 :
F_44 ( V_5 , V_19 , 1 << V_168 , 1 ) ;
break;
case V_44 :
F_44 ( V_5 , V_19 , 1 << V_168 , 0 ) ;
break;
case V_697 :
V_73 [ 1 ] =
( V_10 -> V_20 & ( 1 << V_168 ) ) ?
V_47 : V_44 ;
return 0 ;
break;
case V_698 :
return F_226 ( V_5 , V_168 , V_73 [ 1 ] ) ;
break;
case V_699 :
V_73 [ 1 ] = F_229 ( V_5 , V_168 ) ;
break;
case V_700 :
return F_230 ( V_5 , V_168 , V_73 [ 1 ] ) ;
break;
default:
return - V_388 ;
}
return 0 ;
}
static void F_235 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
V_10 -> V_701 = V_702 ;
if ( F_236 ( V_5 , V_703 , 0 ) < 0 )
F_6 ( L_35 ) ;
V_10 -> V_704 =
F_237 ( 0 ,
V_705 ) |
F_237 ( 1 ,
V_706 ) |
F_237 ( 2 ,
V_707 ) |
F_237 ( 3 , V_708 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_704 ,
V_709 ) ;
V_10 -> V_710 =
F_237 ( 4 ,
V_711 ) |
F_237 ( 5 ,
V_712 ) |
F_237 ( 6 , V_713 ) ;
if ( V_59 -> V_60 & V_61 )
V_10 -> V_710 |=
F_237 ( 7 , V_714 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_710 ,
V_715 ) ;
}
static int F_238 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 , unsigned int * V_73 )
{
V_73 [ 1 ] = 0 ;
return V_243 -> V_164 ;
}
static int F_239 ( unsigned V_716 ,
unsigned * V_717 ,
unsigned * V_718 ,
unsigned * V_719 )
{
unsigned div ;
unsigned V_720 = 1 ;
static const unsigned V_721 = 0x10 ;
unsigned V_722 ;
unsigned V_723 = 1 ;
static const unsigned V_724 = 0x100 ;
static const unsigned V_725 = 1000 ;
const unsigned V_726 = V_716 * V_725 ;
static const unsigned V_727 = 12500 ;
static const unsigned V_728 = 4 ;
int V_729 = 0 ;
for ( div = 1 ; div <= V_721 ; ++ div ) {
for ( V_722 = 1 ; V_722 <= V_724 ; ++ V_722 ) {
unsigned V_730 =
( V_726 * div ) / V_722 ;
if ( abs ( V_730 - V_727 ) <
abs ( V_729 - V_727 ) ) {
V_729 = V_730 ;
V_720 = div ;
V_723 = V_722 ;
}
}
}
if ( V_729 == 0 ) {
F_6 ( L_36 , V_25 ) ;
return - V_204 ;
}
* V_717 = V_720 ;
* V_718 = V_723 ;
* V_719 =
( V_729 * V_728 +
( V_725 / 2 ) ) / V_725 ;
return 0 ;
}
static inline unsigned F_240 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
if ( V_59 -> V_60 & V_61 )
return 8 ;
else
return 7 ;
}
static int F_241 ( struct V_4 * V_5 ,
unsigned V_676 , unsigned V_731 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
static const unsigned V_732 = 50 ;
static const unsigned V_733 = 1000 ;
static const unsigned V_66 = 1000 ;
unsigned V_734 ;
unsigned V_717 ;
unsigned V_718 ;
unsigned V_67 ;
int V_190 ;
if ( V_676 == V_735 )
V_731 = 100 ;
if ( V_731 < V_732 || V_731 > V_733 ) {
F_6
( L_37
L_38 , V_25 ,
V_732 , V_733 ) ;
return - V_388 ;
}
V_10 -> V_736 &= ~ V_737 ;
V_10 -> V_16 ( V_5 , V_10 -> V_736 ,
V_738 ) ;
V_734 =
V_739 | V_740 ;
V_10 -> V_701 |=
V_741 | V_742 ;
V_10 -> V_701 &= ~ V_743 ;
switch ( V_676 ) {
case V_744 :
V_10 -> V_701 |=
V_745 ;
V_190 = F_239 ( V_731 , & V_717 ,
& V_718 ,
& V_10 -> V_306 ) ;
if ( V_190 < 0 )
return V_190 ;
break;
case V_735 :
V_10 -> V_701 |=
V_746 ;
V_190 = F_239 ( V_731 , & V_717 ,
& V_718 ,
& V_10 -> V_306 ) ;
if ( V_190 < 0 )
return V_190 ;
break;
default:
{
unsigned V_747 ;
static const unsigned V_748 = 7 ;
for ( V_747 = 0 ; V_747 <= V_748 ;
++ V_747 ) {
if ( V_676 ==
F_242 ( V_747 ) ) {
V_10 -> V_701 |=
F_243
( V_747 ) ;
break;
}
}
if ( V_747 > V_748 )
return - V_388 ;
V_190 = F_239 ( V_731 ,
& V_717 ,
& V_718 ,
& V_10 ->
V_306 ) ;
if ( V_190 < 0 )
return V_190 ;
}
break;
}
F_40 ( V_10 -> V_701 , V_749 ) ;
V_734 |=
F_244 ( V_717 ) |
F_245 ( V_718 ) ;
F_40 ( V_734 , V_750 ) ;
V_10 -> V_636 = V_676 ;
for ( V_67 = 0 ; V_67 < V_66 ; ++ V_67 ) {
if ( F_43 ( V_751 ) & V_752 )
break;
F_35 ( 1 ) ;
}
if ( V_67 == V_66 ) {
F_6
( L_39 ,
V_25 , V_676 , V_731 ) ;
return - V_753 ;
}
return 3 ;
}
static int F_236 ( struct V_4 * V_5 , unsigned V_676 ,
unsigned V_731 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_676 == V_703 ) {
V_10 -> V_736 &= ~ V_737 ;
V_10 -> V_16 ( V_5 , V_10 -> V_736 ,
V_738 ) ;
V_10 -> V_306 = V_642 ;
if ( V_59 -> V_60 & V_61 ) {
V_10 -> V_701 &=
~ ( V_741 |
V_742 ) ;
F_40 ( V_10 -> V_701 ,
V_749 ) ;
F_40 ( 0 , V_750 ) ;
}
V_10 -> V_636 = V_676 ;
} else {
if ( V_59 -> V_60 & V_61 ) {
return F_241 ( V_5 , V_676 ,
V_731 ) ;
} else {
if ( V_676 == V_754 ) {
V_10 -> V_736 |=
V_737 ;
V_10 -> V_16 ( V_5 ,
V_10 ->
V_736 ,
V_738 ) ;
if ( V_731 == 0 ) {
F_6
( L_40 ,
V_25 ) ;
return - V_388 ;
} else {
V_10 -> V_306 = V_731 ;
}
V_10 -> V_636 = V_676 ;
} else
return - V_388 ;
}
}
return 3 ;
}
static int F_246 ( struct V_4 * V_5 , unsigned V_168 ,
unsigned V_676 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
if ( V_168 >= F_240 ( V_5 ) ) {
if ( V_168 == V_755 ) {
if ( V_676 == V_714 )
return 1 ;
else {
F_6
( L_41 ,
V_25 , V_168 , V_755 ) ;
return 0 ;
}
}
return 0 ;
}
switch ( V_676 ) {
case V_705 :
case V_706 :
case V_707 :
case V_708 :
case V_711 :
case V_712 :
case V_713 :
case V_756 :
case V_757 :
return 1 ;
break;
case V_714 :
if ( V_59 -> V_60 & V_61 )
return 1 ;
else
return 0 ;
break;
default:
return 0 ;
break;
}
}
static int F_247 ( struct V_4 * V_5 , unsigned V_168 ,
unsigned V_676 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( F_246 ( V_5 , V_168 , V_676 ) == 0 )
return - V_388 ;
if ( V_168 < 4 ) {
V_10 -> V_704 &= ~ F_248 ( V_168 ) ;
V_10 -> V_704 |=
F_237 ( V_168 , V_676 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_704 ,
V_709 ) ;
} else if ( V_168 < 8 ) {
V_10 -> V_710 &= ~ F_248 ( V_168 ) ;
V_10 -> V_710 |=
F_237 ( V_168 , V_676 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_710 ,
V_715 ) ;
}
return 2 ;
}
static unsigned F_249 ( struct V_4 * V_5 , unsigned V_168 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_168 < 4 ) {
return F_250 ( V_168 ,
V_10 -> V_704 ) ;
} else if ( V_168 < F_240 ( V_5 ) ) {
return F_250 ( V_168 ,
V_10 -> V_710 ) ;
} else {
if ( V_168 == V_755 )
return V_714 ;
F_6 ( L_42 , V_25 ) ;
return 0 ;
}
}
static int F_251 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 , unsigned int * V_73 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_168 = F_103 ( V_243 -> V_247 ) ;
switch ( V_73 [ 0 ] ) {
case V_758 :
if ( V_168 < F_240 ( V_5 ) ) {
V_10 -> V_736 |=
F_252 ( V_168 ,
( V_59 -> V_60 & V_61 ) != 0 ) ;
} else if ( V_168 == V_755 ) {
V_10 -> V_736 |=
V_759 ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_736 ,
V_738 ) ;
break;
case V_760 :
if ( V_168 < F_240 ( V_5 ) ) {
V_10 -> V_736 &=
~ F_252 ( V_168 ,
( V_59 -> V_60 & V_61 ) != 0 ) ;
} else if ( V_168 == V_755 ) {
V_10 -> V_736 &=
~ V_759 ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_736 ,
V_738 ) ;
break;
case V_697 :
if ( V_168 < F_240 ( V_5 ) ) {
V_73 [ 1 ] =
( V_10 -> V_736 &
F_252 ( V_168 ,
( V_59 -> V_60 & V_61 ) != 0 ) )
? V_758
: V_760 ;
} else if ( V_168 == V_755 ) {
V_73 [ 1 ] =
( V_10 -> V_736 &
V_759 )
? V_758 : V_760 ;
}
return 2 ;
break;
case V_643 :
return F_236 ( V_5 , V_73 [ 1 ] , V_73 [ 2 ] ) ;
break;
case V_644 :
V_73 [ 1 ] = V_10 -> V_636 ;
V_73 [ 2 ] = V_10 -> V_306 ;
return 3 ;
break;
case V_698 :
return F_247 ( V_5 , V_168 , V_73 [ 1 ] ) ;
break;
case V_699 :
V_73 [ 1 ] = F_249 ( V_5 , V_168 ) ;
return 2 ;
break;
default:
return - V_388 ;
break;
}
return 1 ;
}
static int F_253 ( struct V_4 * V_5 )
{
unsigned short V_126 ;
const int V_66 = V_761 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
V_126 = F_42 ( V_5 , V_762 ) ;
if ( ( V_126 & V_763 ) == 0 )
break;
F_254 ( V_764 ) ;
if ( F_255 ( 1 ) )
return - V_204 ;
}
if ( V_67 == V_66 ) {
F_6 ( L_43 , __FILE__ , V_25 ) ;
return - V_251 ;
}
return 0 ;
}
static void F_256 ( struct V_4 * V_5 , unsigned short V_80 )
{
static const int V_66 = 100 ;
int V_67 ;
F_39 ( V_5 , V_80 , V_765 ) ;
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
if ( ( F_42 ( V_5 , V_762 ) & V_763 ) )
break;
F_35 ( 1 ) ;
}
if ( V_67 == V_66 )
F_19 ( V_5 , L_44 ) ;
}
static void F_257 ( struct V_4 * V_5 , unsigned int V_80 ,
unsigned int V_766 )
{
F_39 ( V_5 , ( ( V_80 >> 16 ) & 0xff ) ,
V_767 ) ;
F_39 ( V_5 , ( V_80 & 0xffff ) ,
V_768 ) ;
V_766 &= V_769 ;
F_256 ( V_5 , V_770 | V_766 ) ;
if ( F_253 ( V_5 ) )
F_19 ( V_5 , L_45 ) ;
}
static int F_258 ( struct V_4 * V_5 , unsigned short * V_73 )
{
int V_190 ;
unsigned short V_126 ;
F_256 ( V_5 , V_770 | V_771 ) ;
V_190 = F_253 ( V_5 ) ;
if ( V_190 ) {
F_19 ( V_5 ,
L_46 ) ;
return - V_251 ;
}
V_126 = F_42 ( V_5 , V_762 ) ;
if ( V_126 & V_772 ) {
F_6
( L_47 ) ;
return - V_204 ;
}
if ( V_126 & V_773 ) {
F_6
( L_48 ) ;
}
if ( V_73 ) {
* V_73 = F_42 ( V_5 , V_774 ) ;
* V_73 ^= ( 1 << 15 ) ;
}
return 0 ;
}
static int F_259 ( struct V_4 * V_5 ,
struct V_101 * V_102 ,
struct V_242 * V_243 , unsigned int * V_73 )
{
int V_164 , V_190 ;
unsigned short V_775 ;
unsigned int V_776 ;
const unsigned int V_777 = 0x1000 ;
if ( V_243 -> V_247 & V_260 )
V_776 = V_777 ;
else
V_776 = F_103 ( V_243 -> V_247 ) ;
F_39 ( V_5 , V_776 , V_778 ) ;
for ( V_164 = 0 ; V_164 < V_243 -> V_164 ; V_164 ++ ) {
V_190 = F_258 ( V_5 , & V_775 ) ;
if ( V_190 < 0 )
return V_190 ;
V_73 [ V_164 ] = V_775 ;
}
return V_243 -> V_164 ;
}
static int F_260 ( struct V_4 * V_5 )
{
unsigned int V_274 =
V_779 | V_780 ;
#if 1
F_257 ( V_5 , V_274 | V_781 ,
V_782 ) ;
F_258 ( V_5 , NULL ) ;
#else
F_257 ( V_5 , 0x400000 , V_783 ) ;
F_257 ( V_5 , V_274 | V_784 ,
V_782 ) ;
if ( F_253 ( V_5 ) )
F_19 ( V_5 , L_49 ) ;
#endif
return 0 ;
}

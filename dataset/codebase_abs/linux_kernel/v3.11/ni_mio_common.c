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
if ( V_33 >= 0 ) {
V_27 = F_13 ( V_32 , V_33 ) ;
} else {
V_27 = 0 ;
}
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
if ( V_59 -> V_60 == V_66 ) {
F_33 ( 0x10 , V_67 ) ;
F_33 ( 0x00 , V_67 ) ;
while ( F_34 ( V_68 ) & 0x10 ) ;
} else {
V_10 -> V_16 ( V_5 , 1 , V_69 ) ;
if ( V_59 -> V_60 == V_70 ) {
F_5 ( 0 , F_35 ( 0 ) ) ;
F_5 ( 1 , F_35 ( 0 ) ) ;
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
static void F_36 ( struct V_4 * V_5 , T_1 V_71 , int V_6 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_10 -> V_16 ( V_5 , V_71 >> 16 , V_6 ) ;
V_10 -> V_16 ( V_5 , V_71 & 0xffff , V_6 + 1 ) ;
}
static T_1 F_37 ( struct V_4 * V_5 , int V_6 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
T_1 V_72 ;
V_72 = V_10 -> V_73 ( V_5 , V_6 ) << 16 ;
V_72 |= V_10 -> V_73 ( V_5 , V_6 + 1 ) ;
return V_72 ;
}
static inline void F_38 ( struct V_4 * V_5 , T_2 V_71 ,
int V_74 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_12 ;
F_4 ( & V_10 -> V_75 , V_12 ) ;
F_39 ( V_74 , V_76 ) ;
F_39 ( V_71 , V_77 ) ;
F_8 ( & V_10 -> V_75 , V_12 ) ;
}
static inline void F_40 ( struct V_4 * V_5 , T_1 V_71 ,
int V_74 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_12 ;
F_4 ( & V_10 -> V_75 , V_12 ) ;
F_39 ( V_74 , V_76 ) ;
F_33 ( V_71 , V_77 ) ;
F_8 ( & V_10 -> V_75 , V_12 ) ;
}
static inline unsigned short F_41 ( struct V_4 * V_5 , int V_74 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_12 ;
unsigned short V_71 ;
F_4 ( & V_10 -> V_75 , V_12 ) ;
F_39 ( V_74 , V_76 ) ;
V_71 = F_42 ( V_77 ) ;
F_8 ( & V_10 -> V_75 , V_12 ) ;
return V_71 ;
}
static inline void F_43 ( struct V_4 * V_5 , int V_6 ,
unsigned V_72 , unsigned V_78 )
{
unsigned V_8 ;
if ( V_78 )
V_8 = V_72 ;
else
V_8 = 0 ;
F_3 ( V_5 , V_6 , V_72 , V_8 ) ;
}
static T_3 F_44 ( int V_79 , void * V_80 )
{
struct V_4 * V_5 = V_80 ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned short V_81 ;
unsigned short V_82 ;
unsigned int V_83 = 0 ;
unsigned int V_84 = 0 ;
unsigned long V_12 ;
#ifdef F_24
struct V_85 * V_40 = V_10 -> V_40 ;
#endif
if ( ! V_5 -> V_86 )
return V_87 ;
F_45 () ;
F_4 ( & V_5 -> V_88 , V_12 ) ;
V_81 = V_10 -> V_73 ( V_5 , V_89 ) ;
V_82 = V_10 -> V_73 ( V_5 , V_90 ) ;
#ifdef F_24
if ( V_40 ) {
unsigned long V_91 ;
F_4 ( & V_10 -> V_38 , V_91 ) ;
if ( V_10 -> V_39 ) {
V_83 = F_46 ( V_10 -> V_39 ) ;
if ( V_83 & V_92 )
F_47 ( V_93 ,
V_10 -> V_40 -> V_94 +
F_48 ( V_10 ->
V_39 -> V_26 ) ) ;
}
if ( V_10 -> V_45 ) {
V_84 = F_46 ( V_10 -> V_45 ) ;
if ( V_84 & V_92 )
F_47 ( V_93 ,
V_40 -> V_94 +
F_48 ( V_10 ->
V_45 -> V_26 ) ) ;
}
F_8 ( & V_10 -> V_38 , V_91 ) ;
}
#endif
F_49 ( V_5 , V_81 ) ;
F_50 ( V_5 , V_82 ) ;
if ( ( V_81 & V_95 ) || ( V_83 & V_96 ) )
F_51 ( V_5 , V_81 , V_83 ) ;
if ( ( V_82 & V_97 ) || ( V_84 & V_96 ) )
F_52 ( V_5 , V_82 , V_84 ) ;
F_53 ( V_5 , 0 ) ;
F_53 ( V_5 , 1 ) ;
F_54 ( V_5 ) ;
F_8 ( & V_5 -> V_88 , V_12 ) ;
return V_98 ;
}
static void F_55 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_99 * V_100 = & V_5 -> V_101 [ V_102 ] ;
unsigned long V_12 ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_39 )
F_56 ( V_10 -> V_39 , V_100 -> V_103 ) ;
F_8 ( & V_10 -> V_38 , V_12 ) ;
}
static void F_57 ( struct V_85 * V_40 ,
struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_99 * V_100 = & V_5 -> V_101 [ V_104 ] ;
unsigned long V_12 ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_45 ) {
F_58 ( V_10 -> V_45 , V_100 -> V_103 ) ;
}
F_8 ( & V_10 -> V_38 , V_12 ) ;
}
static int F_59 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
static const int V_105 = 10000 ;
int V_106 ;
for ( V_106 = 0 ; V_106 < V_105 ; V_106 ++ ) {
unsigned short V_82 ;
V_82 = V_10 -> V_73 ( V_5 , V_90 ) ;
if ( V_82 & V_107 )
break;
F_60 ( 10 ) ;
}
if ( V_106 == V_105 ) {
F_19 ( V_5 , L_7 ) ;
return - V_108 ;
}
return 0 ;
}
static void F_61 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_10 -> V_109 == V_110 ) {
#ifdef F_24
static const int V_105 = 10 ;
int V_106 ;
for ( V_106 = 0 ; V_106 < V_105 ; V_106 ++ ) {
F_55 ( V_5 ) ;
if ( ( V_100 -> V_103 -> V_111 & V_112 ) )
break;
F_60 ( 1 ) ;
}
#else
F_62 ( V_5 ) ;
V_100 -> V_103 -> V_111 |= V_112 ;
#endif
}
if ( ( V_10 -> V_113 & V_114 ) ) {
F_63 ( V_5 ) ;
}
}
static void F_63 ( struct V_4 * V_5 )
{
struct V_99 * V_100 = & V_5 -> V_101 [ V_102 ] ;
#ifdef F_24
F_64 ( V_5 ) ;
#endif
F_62 ( V_5 ) ;
F_65 ( V_5 ) ;
F_66 ( V_5 ) ;
V_100 -> V_103 -> V_111 |= V_115 ;
}
static void F_67 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
if ( V_100 ->
V_103 -> V_111 & ( V_116 | V_117 |
V_115 ) ) {
switch ( V_100 -> V_118 ) {
case V_102 :
F_68 ( V_5 , V_100 ) ;
break;
case V_104 :
F_69 ( V_5 , V_100 ) ;
break;
case V_2 :
case V_3 :
F_70 ( V_5 , V_100 ) ;
break;
case V_119 :
F_71 ( V_5 , V_100 ) ;
break;
default:
break;
}
}
F_72 ( V_5 , V_100 ) ;
}
static void F_53 ( struct V_4 * V_5 ,
unsigned short V_1 )
{
#ifdef F_24
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_99 * V_100 ;
V_100 = & V_5 -> V_101 [ F_1 ( V_1 ) ] ;
F_73 ( & V_10 -> V_52 -> V_53 [ V_1 ] ,
V_100 ) ;
if ( V_100 -> V_103 -> V_111 )
F_67 ( V_5 , V_100 ) ;
#endif
}
static void F_49 ( struct V_4 * V_5 , unsigned short V_81 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned short V_120 = 0 ;
if ( V_81 & V_121 ) {
V_120 |= V_122 ;
}
if ( V_81 & V_123 ) {
V_120 |= V_124 ;
}
if ( V_81 & V_125 ) {
V_120 |= V_126 ;
}
if ( V_81 & V_127 ) {
V_120 |= V_128 ;
}
if ( V_120 )
V_10 -> V_16 ( V_5 , V_120 , V_129 ) ;
}
static void F_51 ( struct V_4 * V_5 , unsigned short V_130 ,
unsigned V_83 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_99 * V_100 = & V_5 -> V_101 [ V_102 ] ;
if ( V_100 -> type == V_131 )
return;
#ifdef F_74
F_6
( L_8 ,
V_130 , V_83 ) ;
F_75 ( V_130 ) ;
#endif
#ifdef F_24
if ( V_83 & V_92 ) {
F_55 ( V_5 ) ;
}
if ( V_83 & ~ ( V_96 | V_92 | V_132 | V_133 |
V_134 | V_135 | V_136 | V_137 |
V_138 | V_139 | V_140 ) ) {
F_6
( L_9 ,
V_83 ) ;
V_100 -> V_103 -> V_111 |= V_116 | V_115 ;
}
#endif
if ( V_130 & ( V_141 | V_142 | V_143 |
V_121 | V_123 ) ) {
if ( V_130 == 0xffff ) {
F_6
( L_10 ) ;
if ( F_76 ( V_100 ) ) {
V_100 -> V_103 -> V_111 |=
V_116 | V_115 ;
F_67 ( V_5 , V_100 ) ;
}
return;
}
if ( V_130 & ( V_141 | V_142 |
V_143 ) ) {
F_6 ( L_11 ,
V_130 ) ;
F_75 ( V_130 ) ;
F_63 ( V_5 ) ;
V_100 -> V_103 -> V_111 |= V_116 ;
if ( V_130 & ( V_141 | V_142 ) )
V_100 -> V_103 -> V_111 |= V_117 ;
F_67 ( V_5 , V_100 ) ;
return;
}
if ( V_130 & V_121 ) {
#ifdef F_74
F_6 ( L_12 ) ;
#endif
if ( ! V_10 -> V_144 ) {
F_63 ( V_5 ) ;
}
}
}
#ifndef F_24
if ( V_130 & V_145 ) {
int V_106 ;
static const int V_105 = 10 ;
for ( V_106 = 0 ; V_106 < V_105 ; ++ V_106 ) {
F_77 ( V_5 ) ;
if ( ( V_10 -> V_73 ( V_5 ,
V_89 ) &
V_145 ) == 0 )
break;
}
}
#endif
if ( ( V_130 & V_127 ) ) {
F_61 ( V_5 , V_100 ) ;
}
F_67 ( V_5 , V_100 ) ;
#ifdef F_74
V_130 = V_10 -> V_73 ( V_5 , V_89 ) ;
if ( V_130 & V_95 ) {
F_6
( L_13 ,
V_130 ) ;
}
#endif
}
static void F_50 ( struct V_4 * V_5 , unsigned short V_82 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned short V_120 = 0 ;
if ( V_82 & V_146 ) {
V_120 |= V_147 ;
}
if ( V_82 & V_148 ) {
V_120 |= V_149 ;
}
if ( V_82 & V_150 ) {
V_120 |= V_151 ;
}
if ( V_82 & V_152 ) {
V_120 |= V_153 ;
}
if ( V_82 & V_154 ) {
V_120 |= V_155 ;
}
if ( V_82 & V_156 ) {
V_120 |= V_157 ;
}
if ( V_82 & V_158 ) {
V_120 |= V_159 ;
}
if ( V_120 )
V_10 -> V_16 ( V_5 , V_120 , V_160 ) ;
}
static void F_52 ( struct V_4 * V_5 ,
unsigned short V_82 , unsigned V_84 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_99 * V_100 = & V_5 -> V_101 [ V_104 ] ;
#ifdef F_74
F_6 ( L_14 ,
V_82 , V_84 ) ;
F_78 ( V_82 ) ;
#endif
#ifdef F_24
if ( V_84 & V_92 ) {
F_57 ( V_10 -> V_40 , V_5 ) ;
}
if ( V_84 & ~ ( V_96 | V_92 | V_132 | V_133 |
V_134 | V_135 | V_136 | V_137 |
V_138 | V_139 | V_140 ) ) {
F_6
( L_15 ,
V_84 ) ;
V_100 -> V_103 -> V_111 |= V_115 | V_116 ;
}
#endif
if ( V_82 == 0xffff )
return;
if ( V_82 & V_148 ) {
F_6
( L_16 ,
V_82 , V_10 -> V_73 ( V_5 , V_161 ) ) ;
V_100 -> V_103 -> V_111 |= V_117 ;
}
if ( V_82 & V_146 ) {
F_79
( L_17 ,
V_82 , V_10 -> V_73 ( V_5 , V_161 ) ) ;
V_100 -> V_103 -> V_111 |= V_115 ;
}
#ifndef F_24
if ( V_82 & V_162 ) {
int V_163 ;
V_163 = F_80 ( V_5 , V_100 ) ;
if ( ! V_163 ) {
F_6 ( L_18 ) ;
F_43 ( V_5 , V_17 ,
V_164 |
V_165 , 0 ) ;
V_100 -> V_103 -> V_111 |= V_117 ;
}
}
#endif
F_67 ( V_5 , V_100 ) ;
}
static void F_75 ( int V_130 )
{
int V_106 ;
F_6 ( L_19 ) ;
for ( V_106 = 15 ; V_106 >= 0 ; V_106 -- ) {
if ( V_130 & ( 1 << V_106 ) ) {
F_6 ( L_20 , V_166 [ V_106 ] ) ;
}
}
F_6 ( L_21 ) ;
}
static void F_78 ( int V_130 )
{
int V_106 ;
F_6 ( L_22 ) ;
for ( V_106 = 15 ; V_106 >= 0 ; V_106 -- ) {
if ( V_130 & ( 1 << V_106 ) ) {
F_6 ( L_20 , V_167 [ V_106 ] ) ;
}
}
F_6 ( L_21 ) ;
}
static void F_81 ( struct V_4 * V_5 ,
struct V_99 * V_100 , int V_168 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_169 * V_103 = V_100 -> V_103 ;
struct V_170 * V_171 = & V_103 -> V_171 ;
int V_172 ;
int V_106 ;
short V_80 ;
T_4 V_173 ;
int V_174 ;
int V_175 = 1 ;
V_172 = V_103 -> V_176 ;
for ( V_106 = 0 ; V_106 < V_168 ; V_106 ++ ) {
V_175 &= F_82 ( V_103 , & V_80 ) ;
if ( V_175 == 0 )
break;
V_174 = F_83 ( V_171 -> V_177 [ V_172 ] ) ;
if ( V_59 -> V_60 & V_178 ) {
V_173 = V_80 & 0xffff ;
if ( V_59 -> V_60 != V_179 ) {
V_175 &= F_82 ( V_103 , & V_80 ) ;
if ( V_175 == 0 )
break;
V_172 ++ ;
V_106 ++ ;
V_173 |= ( V_80 << 16 ) & 0xffff0000 ;
}
F_33 ( V_173 , V_180 ) ;
} else {
F_39 ( V_80 , V_181 ) ;
}
V_172 ++ ;
V_172 %= V_171 -> V_182 ;
}
V_103 -> V_176 = V_172 ;
if ( V_175 == 0 ) {
V_103 -> V_111 |= V_117 ;
}
}
static int F_80 ( struct V_4 * V_5 ,
struct V_99 * V_100 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
int V_168 ;
V_168 = F_84 ( V_100 -> V_103 ) ;
if ( V_168 == 0 ) {
V_100 -> V_103 -> V_111 |= V_117 ;
return 0 ;
}
V_168 /= sizeof( short ) ;
if ( V_168 > V_59 -> V_183 / 2 )
V_168 = V_59 -> V_183 / 2 ;
F_81 ( V_5 , V_100 , V_168 ) ;
V_100 -> V_103 -> V_111 |= V_184 ;
return 1 ;
}
static int F_85 ( struct V_4 * V_5 ,
struct V_99 * V_100 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_168 ;
V_10 -> V_16 ( V_5 , 1 , V_185 ) ;
if ( V_59 -> V_60 & V_178 )
F_40 ( V_5 , 0x6 , V_186 ) ;
V_168 = F_84 ( V_100 -> V_103 ) ;
if ( V_168 == 0 )
return 0 ;
V_168 /= sizeof( short ) ;
if ( V_168 > V_59 -> V_183 )
V_168 = V_59 -> V_183 ;
F_81 ( V_5 , V_100 , V_168 ) ;
return V_168 ;
}
static void F_86 ( struct V_4 * V_5 ,
struct V_99 * V_100 , int V_168 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_169 * V_103 = V_100 -> V_103 ;
int V_106 ;
if ( V_59 -> V_60 == V_187 ) {
short V_71 [ 2 ] ;
T_4 V_188 ;
for ( V_106 = 0 ; V_106 < V_168 / 2 ; V_106 ++ ) {
V_188 = F_34 ( V_189 ) ;
V_71 [ 0 ] = ( V_188 >> 16 ) & 0xffff ;
V_71 [ 1 ] = V_188 & 0xffff ;
F_87 ( V_100 , V_71 , sizeof( V_71 ) ) ;
}
if ( V_168 % 2 ) {
V_188 = F_34 ( V_189 ) ;
V_71 [ 0 ] = V_188 & 0xffff ;
F_88 ( V_100 , V_71 [ 0 ] ) ;
}
} else if ( V_59 -> V_60 == V_66 ) {
short V_71 [ 2 ] ;
T_4 V_188 ;
for ( V_106 = 0 ; V_106 < V_168 / 2 ; V_106 ++ ) {
V_188 = F_34 ( V_190 ) ;
V_71 [ 0 ] = ( V_188 >> 16 ) & 0xffff ;
V_71 [ 1 ] = V_188 & 0xffff ;
F_87 ( V_100 , V_71 , sizeof( V_71 ) ) ;
}
if ( V_168 % 2 ) {
F_33 ( 0x01 , V_67 ) ;
V_188 = F_34 ( V_190 ) ;
V_71 [ 0 ] = ( V_188 >> 16 ) & 0xffff ;
F_88 ( V_100 , V_71 [ 0 ] ) ;
}
} else {
if ( V_168 > sizeof( V_10 -> V_191 ) /
sizeof( V_10 -> V_191 [ 0 ] ) ) {
F_19 ( V_5 , L_23 ) ;
V_103 -> V_111 |= V_116 ;
return;
}
for ( V_106 = 0 ; V_106 < V_168 ; V_106 ++ ) {
V_10 -> V_191 [ V_106 ] =
F_42 ( V_192 ) ;
}
F_87 ( V_100 , V_10 -> V_191 ,
V_168 *
sizeof( V_10 -> V_191 [ 0 ] ) ) ;
}
}
static void F_77 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_99 * V_100 = & V_5 -> V_101 [ V_102 ] ;
int V_168 ;
V_168 = V_59 -> V_193 / 2 ;
F_86 ( V_5 , V_100 , V_168 ) ;
}
static int F_64 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_106 ;
static const int V_105 = 10000 ;
unsigned long V_12 ;
int V_194 = 0 ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_39 ) {
for ( V_106 = 0 ; V_106 < V_105 ; V_106 ++ ) {
if ( ( V_10 -> V_73 ( V_5 ,
V_89 ) &
V_195 )
&& F_89 ( V_10 -> V_39 ) ==
0 )
break;
F_60 ( 5 ) ;
}
if ( V_106 == V_105 ) {
F_6 ( L_24 ) ;
F_6
( L_25 ,
F_89 ( V_10 -> V_39 ) ,
V_10 -> V_73 ( V_5 , V_89 ) ) ;
V_194 = - 1 ;
}
}
F_8 ( & V_10 -> V_38 , V_12 ) ;
F_55 ( V_5 ) ;
return V_194 ;
}
static void F_62 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_99 * V_100 = & V_5 -> V_101 [ V_102 ] ;
short V_71 [ 2 ] ;
T_4 V_188 ;
short V_196 ;
int V_106 ;
if ( V_59 -> V_60 == V_187 ) {
while ( ( V_10 -> V_73 ( V_5 ,
V_89 ) &
V_195 ) == 0 ) {
V_188 = F_34 ( V_189 ) ;
V_71 [ 0 ] = ( V_188 >> 16 ) ;
V_71 [ 1 ] = ( V_188 & 0xffff ) ;
F_87 ( V_100 , V_71 , sizeof( V_71 ) ) ;
}
} else if ( V_59 -> V_60 == V_66 ) {
V_106 = 0 ;
while ( F_34 ( V_68 ) & 0x04 ) {
V_188 = F_34 ( V_190 ) ;
V_71 [ 0 ] = ( V_188 >> 16 ) ;
V_71 [ 1 ] = ( V_188 & 0xffff ) ;
F_87 ( V_100 , V_71 , sizeof( V_71 ) ) ;
V_106 += 2 ;
}
if ( F_34 ( V_68 ) & 0x01 ) {
F_33 ( 0x01 , V_67 ) ;
V_188 = F_34 ( V_190 ) ;
V_71 [ 0 ] = ( V_188 >> 16 ) & 0xffff ;
F_88 ( V_100 , V_71 [ 0 ] ) ;
}
} else {
V_196 =
V_10 -> V_73 ( V_5 ,
V_89 ) & V_195 ;
while ( V_196 == 0 ) {
for ( V_106 = 0 ;
V_106 <
sizeof( V_10 -> V_191 ) /
sizeof( V_10 -> V_191 [ 0 ] ) ; V_106 ++ ) {
V_196 =
V_10 -> V_73 ( V_5 ,
V_89 ) &
V_195 ;
if ( V_196 )
break;
V_10 -> V_191 [ V_106 ] =
F_42 ( V_192 ) ;
}
F_87 ( V_100 , V_10 -> V_191 ,
V_106 *
sizeof( V_10 ->
V_191 [ 0 ] ) ) ;
}
}
}
static void F_65 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 V_197 = V_5 -> V_11 ;
struct V_99 * V_100 = & V_5 -> V_101 [ V_102 ] ;
short V_71 ;
T_4 V_188 ;
if ( V_59 -> V_60 != V_187 )
return;
if ( F_90 ( V_198 ) & 0x80 ) {
V_188 = F_34 ( V_189 ) ;
V_71 = ( V_188 & 0xffff ) ;
F_88 ( V_100 , V_71 ) ;
}
}
static void F_66 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 V_197 = V_5 -> V_11 ;
struct V_99 * V_100 = & V_5 -> V_101 [ V_102 ] ;
short V_71 ;
T_4 V_188 ;
if ( V_59 -> V_60 != V_66 )
return;
if ( F_34 ( V_68 ) & 0x01 ) {
F_33 ( 0x01 , V_67 ) ;
V_188 = F_34 ( V_190 ) ;
V_71 = ( V_188 >> 16 ) & 0xffff ;
F_88 ( V_100 , V_71 ) ;
}
}
static void F_91 ( struct V_4 * V_5 , struct V_99 * V_100 ,
void * V_71 , unsigned int V_199 ,
unsigned int V_200 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_169 * V_103 = V_100 -> V_103 ;
unsigned int V_106 ;
unsigned int V_201 = V_199 / F_92 ( V_100 ) ;
short * V_202 = V_71 ;
unsigned int * V_203 = V_71 ;
for ( V_106 = 0 ; V_106 < V_201 ; V_106 ++ ) {
#ifdef F_24
if ( V_100 -> V_204 & V_205 )
V_203 [ V_106 ] = F_93 ( V_203 [ V_106 ] ) ;
else
V_202 [ V_106 ] = F_94 ( V_202 [ V_106 ] ) ;
#endif
if ( V_100 -> V_204 & V_205 )
V_203 [ V_106 ] += V_10 -> V_206 [ V_200 ] ;
else
V_202 [ V_106 ] += V_10 -> V_206 [ V_200 ] ;
V_200 ++ ;
V_200 %= V_103 -> V_171 . V_182 ;
}
}
static int F_95 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_99 * V_100 = & V_5 -> V_101 [ V_102 ] ;
int V_194 ;
unsigned long V_12 ;
V_194 = F_16 ( V_5 ) ;
if ( V_194 )
return V_194 ;
F_96 ( V_100 -> V_103 , V_100 -> V_103 -> V_207 ) ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_39 == NULL ) {
F_8 ( & V_10 -> V_38 , V_12 ) ;
return - V_208 ;
}
switch ( V_59 -> V_60 ) {
case V_187 :
case V_66 :
F_97 ( V_10 -> V_39 , 32 , 16 ) ;
break;
case V_209 :
F_97 ( V_10 -> V_39 , 32 , 32 ) ;
break;
default:
F_97 ( V_10 -> V_39 , 16 , 16 ) ;
break;
}
F_98 ( V_10 -> V_39 ) ;
F_8 ( & V_10 -> V_38 , V_12 ) ;
return 0 ;
}
static int F_99 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_99 * V_100 = & V_5 -> V_101 [ V_104 ] ;
int V_194 ;
unsigned long V_12 ;
V_194 = F_20 ( V_5 ) ;
if ( V_194 )
return V_194 ;
F_100 ( V_100 -> V_103 , V_100 -> V_103 -> V_207 ) ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_45 ) {
if ( V_59 -> V_60 & ( V_187 | V_210 ) ) {
F_97 ( V_10 -> V_45 , 32 , 32 ) ;
} else {
F_97 ( V_10 -> V_45 , 16 , 32 ) ;
}
F_98 ( V_10 -> V_45 ) ;
} else
V_194 = - V_208 ;
F_8 ( & V_10 -> V_38 , V_12 ) ;
return V_194 ;
}
static int F_68 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
F_25 ( V_5 ) ;
V_10 -> V_16 ( V_5 , V_211 | V_212 ,
V_213 ) ;
F_43 ( V_5 , V_14 ,
V_214 | V_215 |
V_216 | V_217 |
V_218 | V_219 |
V_220 , 0 ) ;
F_32 ( V_5 ) ;
if ( V_59 -> V_60 != V_66 )
F_5 ( 0 , V_221 ) ;
V_10 -> V_16 ( V_5 , V_222 , V_223 ) ;
V_10 -> V_16 ( V_5 ,
V_224 | V_225
,
V_226 ) ;
V_10 -> V_16 ( V_5 , 0x0000 , V_227 ) ;
V_10 -> V_16 ( V_5 , ( 0 << 6 ) | 0x0000 , V_228 ) ;
if ( V_59 -> V_60 == V_187 ) {
V_10 -> V_16 ( V_5 , V_229 |
V_230 |
V_231 ,
V_232 ) ;
V_10 -> V_16 ( V_5 ,
F_101 ( 3 ) |
F_102 ( 0 ) |
F_103 ( 2 ) |
F_104 ( 3 ) |
F_105
( V_233 ) ,
V_234 ) ;
} else if ( V_59 -> V_60 == V_66 ) {
V_10 -> V_16 ( V_5 , V_229 |
V_230 |
V_231 ,
V_232 ) ;
V_10 -> V_16 ( V_5 ,
F_101 ( 3 ) |
F_102 ( 0 ) |
F_103 ( 2 ) |
F_104 ( 3 ) |
F_105
( V_235 ) ,
V_234 ) ;
} else {
unsigned V_236 ;
V_10 -> V_16 ( V_5 , V_229 |
V_230 |
V_237 |
V_231 ,
V_232 ) ;
V_236 =
F_101 ( 3 ) |
F_102 ( 0 ) |
F_103 ( 2 ) |
F_104 ( 3 ) ;
if ( V_59 -> V_60 == V_238 )
V_236 |=
F_105
( V_233 ) ;
else
V_236 |=
F_105
( V_235 ) ;
V_10 -> V_16 ( V_5 , V_236 ,
V_234 ) ;
}
V_10 -> V_16 ( V_5 , V_239 | V_126 | V_240 | V_124 | V_122 | V_241 | V_128 , V_129 ) ;
V_10 -> V_16 ( V_5 , V_242 , V_213 ) ;
return 0 ;
}
static int F_106 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
unsigned long V_12 ;
int V_243 ;
F_4 ( & V_5 -> V_88 , V_12 ) ;
#ifndef F_24
F_62 ( V_5 ) ;
#else
F_55 ( V_5 ) ;
#endif
V_243 = V_100 -> V_103 -> V_244 - V_100 -> V_103 -> V_245 ;
F_8 ( & V_5 -> V_88 , V_12 ) ;
return V_243 ;
}
static int F_107 ( struct V_4 * V_5 ,
struct V_99 * V_100 , struct V_246 * V_247 ,
unsigned int * V_71 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_106 , V_168 ;
const unsigned int V_248 = ( 1 << V_59 -> V_249 ) - 1 ;
unsigned V_250 ;
unsigned short V_80 ;
unsigned long V_188 ;
F_108 ( V_5 , 1 , & V_247 -> V_251 ) ;
F_32 ( V_5 ) ;
V_250 = V_10 -> V_206 [ 0 ] ;
if ( V_59 -> V_60 == V_187 ) {
for ( V_168 = 0 ; V_168 < V_252 ; V_168 ++ ) {
V_10 -> V_16 ( V_5 , V_253 ,
V_223 ) ;
F_60 ( 1 ) ;
}
for ( V_168 = 0 ; V_168 < V_247 -> V_168 ; V_168 ++ ) {
V_10 -> V_16 ( V_5 , V_253 ,
V_223 ) ;
V_80 = 0 ;
for ( V_106 = 0 ; V_106 < V_254 ; V_106 ++ ) {
if ( F_90 ( V_198 ) & 0x80 ) {
V_80 = ( F_34 ( V_189 ) >> 16 )
& 0xffff ;
break;
}
if ( ! ( V_10 -> V_73 ( V_5 ,
V_89 ) &
V_195 ) ) {
V_80 = F_34 ( V_189 ) &
0xffff ;
break;
}
}
if ( V_106 == V_254 ) {
F_6
( L_26 ) ;
return - V_255 ;
}
V_80 += V_250 ;
V_71 [ V_168 ] = V_80 ;
}
} else if ( V_59 -> V_60 == V_66 ) {
for ( V_168 = 0 ; V_168 < V_247 -> V_168 ; V_168 ++ ) {
V_10 -> V_16 ( V_5 , V_253 ,
V_223 ) ;
V_188 = 0 ;
for ( V_106 = 0 ; V_106 < V_254 ; V_106 ++ ) {
if ( F_34 ( V_68 ) & 0x01 ) {
F_33 ( 0x01 , V_67 ) ;
V_188 = F_34 ( V_190 ) ;
break;
}
}
if ( V_106 == V_254 ) {
F_6
( L_27 ) ;
return - V_255 ;
}
V_71 [ V_168 ] = ( ( ( V_188 >> 16 ) & 0xFFFF ) + V_250 ) & 0xFFFF ;
}
} else {
for ( V_168 = 0 ; V_168 < V_247 -> V_168 ; V_168 ++ ) {
V_10 -> V_16 ( V_5 , V_253 ,
V_223 ) ;
for ( V_106 = 0 ; V_106 < V_254 ; V_106 ++ ) {
if ( ! ( V_10 -> V_73 ( V_5 ,
V_89 ) &
V_195 ) )
break;
}
if ( V_106 == V_254 ) {
F_6
( L_28 ) ;
return - V_255 ;
}
if ( V_59 -> V_60 & V_61 ) {
V_71 [ V_168 ] =
F_34 ( V_256 ) & V_248 ;
} else {
V_80 = F_42 ( V_192 ) ;
V_80 += V_250 ;
V_71 [ V_168 ] = V_80 ;
}
}
}
return V_247 -> V_168 ;
}
static void F_109 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_106 ;
V_10 -> V_16 ( V_5 , V_253 , V_223 ) ;
for ( V_106 = 0 ; V_106 < V_254 ; ++ V_106 ) {
if ( ! ( V_10 -> V_73 ( V_5 ,
V_89 ) &
V_195 ) ) {
V_10 -> V_16 ( V_5 , 1 , V_69 ) ;
return;
}
F_60 ( 1 ) ;
}
F_6 ( L_29 ) ;
}
static void F_110 ( struct V_4 * V_5 ,
unsigned int V_257 ,
unsigned int * V_258 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_172 , V_174 , V_259 ;
unsigned int V_106 ;
unsigned V_260 ;
unsigned int V_261 ;
unsigned V_262 ;
V_10 -> V_16 ( V_5 , 1 , V_263 ) ;
if ( ( V_258 [ 0 ] & V_264 ) ) {
unsigned V_265 ;
V_172 = F_111 ( V_258 [ 0 ] ) ;
V_174 = F_83 ( V_258 [ 0 ] ) ;
V_262 = V_266 [ V_59 -> V_267 ] [ V_174 ] ;
V_261 = ( ( V_258 [ 0 ] & V_268 ) != 0 ) ;
V_265 = V_269 ;
V_265 |= V_172 ;
V_265 |=
( V_10 -> V_270 ) &
( V_271 |
V_272 |
V_273 |
V_274 ) ;
V_265 |= F_112 ( V_262 ) ;
if ( V_261 )
V_265 |= V_275 ;
V_265 |= V_276 ;
F_33 ( V_265 , V_277 ) ;
} else {
F_33 ( 0 , V_277 ) ;
}
V_260 = 0 ;
for ( V_106 = 0 ; V_106 < V_257 ; V_106 ++ ) {
unsigned V_278 = 0 ;
V_172 = F_111 ( V_258 [ V_106 ] ) ;
V_259 = F_113 ( V_258 [ V_106 ] ) ;
V_174 = F_83 ( V_258 [ V_106 ] ) ;
V_261 = ( ( V_258 [ V_106 ] & V_268 ) != 0 ) ;
V_262 = V_266 [ V_59 -> V_267 ] [ V_174 ] ;
V_10 -> V_206 [ V_106 ] = V_260 ;
switch ( V_259 ) {
case V_279 :
V_278 |=
V_280 ;
break;
case V_281 :
V_278 |=
V_282 ;
break;
case V_283 :
V_278 |=
V_284 ;
break;
case V_285 :
break;
}
V_278 |= F_114 ( V_172 ) ;
V_278 |=
F_115 ( V_59 -> V_60 , V_172 ) ;
V_278 |= F_116 ( V_262 ) ;
if ( V_106 == V_257 - 1 )
V_278 |= V_286 ;
if ( V_261 )
V_278 |= V_287 ;
V_278 |= V_288 ;
F_39 ( V_278 , V_289 ) ;
}
F_109 ( V_5 ) ;
}
static void F_108 ( struct V_4 * V_5 ,
unsigned int V_257 , unsigned int * V_258 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_172 , V_174 , V_259 ;
unsigned int V_106 ;
unsigned int V_290 , V_291 ;
unsigned V_260 ;
unsigned int V_261 ;
if ( V_59 -> V_60 & V_61 ) {
F_110 ( V_5 , V_257 , V_258 ) ;
return;
}
if ( V_257 == 1 && ( V_59 -> V_60 != V_187 )
&& ( V_59 -> V_60 != V_66 ) ) {
if ( V_10 -> V_292
&& V_10 -> V_293 == V_258 [ 0 ] ) {
return;
}
V_10 -> V_292 = 1 ;
V_10 -> V_293 = V_258 [ 0 ] ;
} else {
V_10 -> V_292 = 0 ;
}
V_10 -> V_16 ( V_5 , 1 , V_263 ) ;
if ( V_59 -> V_60 == V_66 ) {
if ( ( V_258 [ 0 ] & V_264 )
&& ! V_10 -> V_294 ) {
F_39 ( V_10 -> V_270 |
V_295 ,
V_296 ) ;
F_39 ( V_10 -> V_270 ,
V_296 ) ;
V_10 -> V_294 = 1 ;
F_117 ( 100 ) ;
} else if ( ! ( V_258 [ 0 ] & V_264 )
&& V_10 -> V_294 ) {
F_39 ( V_10 -> V_270 |
V_297 ,
V_296 ) ;
F_39 ( V_10 -> V_270 ,
V_296 ) ;
V_10 -> V_294 = 0 ;
F_117 ( 100 ) ;
}
}
V_260 = 1 << ( V_59 -> V_249 - 1 ) ;
for ( V_106 = 0 ; V_106 < V_257 ; V_106 ++ ) {
if ( ( V_59 -> V_60 != V_66 )
&& ( V_258 [ V_106 ] & V_264 ) ) {
V_172 = V_10 -> V_270 ;
} else {
V_172 = F_111 ( V_258 [ V_106 ] ) ;
}
V_259 = F_113 ( V_258 [ V_106 ] ) ;
V_174 = F_83 ( V_258 [ V_106 ] ) ;
V_261 = ( ( V_258 [ V_106 ] & V_268 ) != 0 ) ;
V_174 = V_266 [ V_59 -> V_267 ] [ V_174 ] ;
if ( V_59 -> V_60 == V_187 )
V_10 -> V_206 [ V_106 ] = V_260 ;
else
V_10 -> V_206 [ V_106 ] = ( V_174 & 0x100 ) ? 0 : V_260 ;
V_290 = 0 ;
if ( ( V_258 [ V_106 ] & V_264 ) ) {
if ( V_59 -> V_60 == V_187 )
F_39 ( F_111 ( V_258 [ V_106 ] ) & 0x0003 ,
V_298 ) ;
} else {
if ( V_59 -> V_60 == V_187 )
V_259 = V_279 ;
else if ( V_59 -> V_60 == V_66 )
V_259 = V_285 ;
switch ( V_259 ) {
case V_279 :
V_290 |= V_299 ;
break;
case V_281 :
V_290 |= V_300 ;
break;
case V_283 :
V_290 |= V_301 ;
break;
case V_285 :
break;
}
}
V_290 |= F_118 ( V_172 ) ;
F_39 ( V_290 , V_302 ) ;
if ( V_59 -> V_60 != V_66 ) {
V_291 = V_174 ;
if ( V_106 == V_257 - 1 )
V_291 |= V_303 ;
if ( V_261 )
V_291 |= V_304 ;
F_39 ( V_291 , V_305 ) ;
}
}
if ( ( V_59 -> V_60 != V_187 )
&& ( V_59 -> V_60 != V_66 ) ) {
F_109 ( V_5 ) ;
}
}
static int F_119 ( const struct V_4 * V_5 , unsigned V_306 ,
int V_307 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_308 ;
switch ( V_307 ) {
case V_309 :
default:
V_308 = ( V_306 + V_10 -> V_310 / 2 ) / V_10 -> V_310 ;
break;
case V_311 :
V_308 = ( V_306 ) / V_10 -> V_310 ;
break;
case V_312 :
V_308 = ( V_306 + V_10 -> V_310 - 1 ) / V_10 -> V_310 ;
break;
}
return V_308 - 1 ;
}
static unsigned F_120 ( const struct V_4 * V_5 , int V_313 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
return V_10 -> V_310 * ( V_313 + 1 ) ;
}
static unsigned F_121 ( struct V_4 * V_5 ,
unsigned V_314 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
switch ( V_59 -> V_60 ) {
case V_187 :
case V_66 :
return V_59 -> V_315 ;
break;
default:
break;
}
return V_59 -> V_315 * V_314 ;
}
static int F_122 ( struct V_4 * V_5 , struct V_99 * V_100 ,
struct V_170 * V_171 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_175 = 0 ;
int V_316 ;
unsigned int V_317 ;
if ( ( V_171 -> V_12 & V_318 ) )
V_171 -> V_12 &= ~ V_318 ;
V_175 |= F_123 ( & V_171 -> V_319 ,
V_320 | V_321 | V_322 ) ;
V_175 |= F_123 ( & V_171 -> V_323 ,
V_324 | V_322 ) ;
V_317 = V_324 | V_322 ;
if ( V_59 -> V_60 == V_187 ||
V_59 -> V_60 == V_66 )
V_317 |= V_320 ;
V_175 |= F_123 ( & V_171 -> V_325 , V_317 ) ;
V_175 |= F_123 ( & V_171 -> V_326 , V_327 ) ;
V_175 |= F_123 ( & V_171 -> V_328 , V_327 | V_329 ) ;
if ( V_175 )
return 1 ;
V_175 |= F_124 ( V_171 -> V_319 ) ;
V_175 |= F_124 ( V_171 -> V_323 ) ;
V_175 |= F_124 ( V_171 -> V_325 ) ;
V_175 |= F_124 ( V_171 -> V_328 ) ;
if ( V_175 )
return 2 ;
if ( V_171 -> V_319 == V_322 ) {
unsigned int V_316 = F_111 ( V_171 -> V_330 ) ;
if ( V_316 > 16 )
V_316 = 16 ;
V_316 |= ( V_171 -> V_330 & ( V_331 | V_332 ) ) ;
V_175 |= F_125 ( & V_171 -> V_330 , V_316 ) ;
} else {
V_175 |= F_125 ( & V_171 -> V_330 , 0 ) ;
}
if ( V_171 -> V_323 == V_324 ) {
V_175 |= F_126 ( & V_171 -> V_333 ,
F_121 ( V_5 , V_171 -> V_182 ) ) ;
V_175 |= F_127 ( & V_171 -> V_333 ,
V_10 -> V_310 * 0xffffff ) ;
} else if ( V_171 -> V_323 == V_322 ) {
unsigned int V_316 = F_111 ( V_171 -> V_333 ) ;
if ( V_316 > 16 )
V_316 = 16 ;
V_316 |= ( V_171 -> V_333 & ( V_331 | V_332 ) ) ;
V_175 |= F_125 ( & V_171 -> V_333 , V_316 ) ;
} else {
V_175 |= F_125 ( & V_171 -> V_333 , 0 ) ;
}
if ( V_171 -> V_325 == V_324 ) {
if ( ( V_59 -> V_60 == V_187 )
|| ( V_59 -> V_60 == V_66 ) ) {
V_175 |= F_125 ( & V_171 -> V_334 , 0 ) ;
} else {
V_175 |= F_126 ( & V_171 -> V_334 ,
V_59 -> V_315 ) ;
V_175 |= F_127 ( & V_171 -> V_334 ,
V_10 -> V_310 * 0xffff ) ;
}
} else if ( V_171 -> V_325 == V_322 ) {
unsigned int V_316 = F_111 ( V_171 -> V_334 ) ;
if ( V_316 > 16 )
V_316 = 16 ;
V_316 |= ( V_171 -> V_334 & ( V_268 | V_331 ) ) ;
V_175 |= F_125 ( & V_171 -> V_334 , V_316 ) ;
} else if ( V_171 -> V_325 == V_320 ) {
V_175 |= F_125 ( & V_171 -> V_334 , 0 ) ;
}
V_175 |= F_125 ( & V_171 -> V_335 , V_171 -> V_182 ) ;
if ( V_171 -> V_328 == V_327 ) {
unsigned int V_336 = 0x01000000 ;
if ( V_59 -> V_60 == V_187 )
V_336 -= V_252 ;
V_175 |= F_127 ( & V_171 -> V_337 , V_336 ) ;
V_175 |= F_126 ( & V_171 -> V_337 , 1 ) ;
} else {
V_175 |= F_125 ( & V_171 -> V_337 , 0 ) ;
}
if ( V_175 )
return 3 ;
if ( V_171 -> V_323 == V_324 ) {
V_316 = V_171 -> V_333 ;
V_171 -> V_333 =
F_120 ( V_5 , F_119 ( V_5 ,
V_171 -> V_333 ,
V_171 ->
V_12 &
V_338 ) ) ;
if ( V_316 != V_171 -> V_333 )
V_175 ++ ;
}
if ( V_171 -> V_325 == V_324 ) {
if ( ( V_59 -> V_60 != V_187 )
&& ( V_59 -> V_60 != V_66 ) ) {
V_316 = V_171 -> V_334 ;
V_171 -> V_334 =
F_120 ( V_5 , F_119 ( V_5 ,
V_171 -> V_334 ,
V_171 ->
V_12 &
V_338 ) ) ;
if ( V_316 != V_171 -> V_334 )
V_175 ++ ;
if ( V_171 -> V_323 == V_324 &&
V_171 -> V_333 <
V_171 -> V_334 * V_171 -> V_335 ) {
V_171 -> V_333 =
V_171 -> V_334 * V_171 -> V_335 ;
V_175 ++ ;
}
}
}
if ( V_175 )
return 4 ;
return 0 ;
}
static int F_128 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
const struct V_170 * V_171 = & V_100 -> V_103 -> V_171 ;
int V_313 ;
int V_339 = 0 ;
int V_340 = 0 ;
int V_341 = 0 ;
unsigned int V_342 ;
int V_343 = 0 ;
F_79 ( L_30 ) ;
if ( V_5 -> V_79 == 0 ) {
F_19 ( V_5 , L_31 ) ;
return - V_208 ;
}
F_32 ( V_5 ) ;
F_108 ( V_5 , V_171 -> V_182 , V_171 -> V_177 ) ;
V_10 -> V_16 ( V_5 , V_211 , V_213 ) ;
V_10 -> V_344 &= ~ V_345 ;
V_10 -> V_16 ( V_5 , V_10 -> V_344 ,
V_346 ) ;
switch ( V_171 -> V_319 ) {
case V_321 :
case V_320 :
V_10 -> V_16 ( V_5 , F_129 ( 0 ) |
V_347 | V_348 |
F_130 ( 0 ) ,
V_349 ) ;
break;
case V_322 :
{
int V_172 = F_111 ( V_171 -> V_330 ) ;
unsigned int V_72 = F_129 ( 0 ) |
V_347 | F_130 ( V_172 + 1 ) ;
if ( V_171 -> V_330 & V_331 )
V_72 |= V_350 ;
if ( V_171 -> V_330 & V_332 )
V_72 |= V_348 ;
V_10 -> V_16 ( V_5 , V_72 ,
V_349 ) ;
break;
}
}
V_340 &= ~ V_351 ;
V_340 &= ~ V_352 ;
V_340 &= ~ V_353 ;
V_10 -> V_16 ( V_5 , V_340 , V_227 ) ;
if ( V_171 -> V_182 == 1 || ( V_59 -> V_60 == V_187 )
|| ( V_59 -> V_60 == V_66 ) ) {
V_341 |= V_354 ;
V_341 |= F_131 ( 31 ) ;
V_341 |= V_355 ;
} else {
V_341 |= F_131 ( 19 ) ;
}
V_10 -> V_16 ( V_5 , V_341 ,
V_356 ) ;
V_10 -> V_113 = 0 ;
switch ( V_171 -> V_328 ) {
case V_327 :
V_342 = V_171 -> V_337 - 1 ;
if ( V_59 -> V_60 == V_187 ) {
V_342 += V_252 ;
}
V_10 -> V_357 ( V_5 , V_342 , V_358 ) ;
V_339 |= V_224 | V_225 | V_359 ;
V_10 -> V_16 ( V_5 , V_339 , V_226 ) ;
V_10 -> V_16 ( V_5 , V_360 , V_223 ) ;
V_10 -> V_144 = 0 ;
if ( V_342 == 0 ) {
V_10 -> V_113 |= V_114 ;
V_343 |= V_218 ;
if ( V_171 -> V_182 > 1 )
V_341 |=
V_354 | V_361 ;
}
break;
case V_329 :
V_10 -> V_357 ( V_5 , 0 , V_358 ) ;
V_339 |= V_224 | V_225 | V_362 ;
V_10 -> V_16 ( V_5 , V_339 , V_226 ) ;
V_10 -> V_16 ( V_5 , V_360 , V_223 ) ;
V_10 -> V_144 = 1 ;
break;
}
switch ( V_171 -> V_323 ) {
case V_324 :
V_341 |= V_363 | V_364 ;
V_10 -> V_16 ( V_5 , V_341 ,
V_356 ) ;
V_340 |= F_132 ( 0 ) ;
V_340 &= ~ V_365 ;
V_10 -> V_16 ( V_5 , V_340 , V_227 ) ;
V_313 = F_119 ( V_5 , V_171 -> V_333 ,
V_309 ) ;
V_10 -> V_357 ( V_5 , V_313 , V_366 ) ;
V_10 -> V_16 ( V_5 , V_367 , V_223 ) ;
break;
case V_322 :
if ( V_171 -> V_333 & V_332 )
V_341 |= V_363 ;
if ( V_171 -> V_333 & V_331 )
V_341 |= V_368 ;
if ( V_171 -> V_323 != V_171 -> V_325 ||
( V_171 -> V_333 & ~ V_332 ) !=
( V_171 -> V_334 & ~ V_332 ) )
V_341 |= V_364 ;
V_341 |=
F_133 ( 1 + F_111 ( V_171 -> V_333 ) ) ;
V_10 -> V_16 ( V_5 , V_341 ,
V_356 ) ;
break;
}
switch ( V_171 -> V_325 ) {
case V_324 :
case V_320 :
if ( V_171 -> V_334 == 0 || V_171 -> V_325 == V_320 )
V_313 = 1 ;
else
V_313 = F_119 ( V_5 , V_171 -> V_334 ,
V_309 ) ;
V_10 -> V_16 ( V_5 , 1 , V_369 ) ;
V_10 -> V_16 ( V_5 , V_313 , V_370 ) ;
V_340 &= ~ V_371 ;
V_340 |= V_372 ;
V_10 -> V_16 ( V_5 , V_340 , V_227 ) ;
V_10 -> V_16 ( V_5 , V_373 , V_223 ) ;
V_340 |= V_372 ;
V_340 |= V_371 ;
V_10 -> V_16 ( V_5 , V_340 , V_227 ) ;
break;
case V_322 :
V_339 |= F_134 ( 1 + V_171 -> V_334 ) ;
if ( ( V_171 -> V_334 & V_331 ) == 0 )
V_339 |= V_374 ;
V_10 -> V_16 ( V_5 , V_339 , V_226 ) ;
V_340 |= V_375 | V_376 ;
V_10 -> V_16 ( V_5 , V_340 , V_227 ) ;
break;
}
if ( V_5 -> V_79 ) {
V_343 |= V_219 |
V_214 ;
#ifndef F_24
V_343 |= V_220 ;
#endif
if ( V_171 -> V_12 & V_377
|| ( V_10 -> V_113 & V_114 ) ) {
V_10 -> V_109 = V_110 ;
} else {
V_10 -> V_109 = V_378 ;
}
switch ( V_10 -> V_109 ) {
case V_378 :
#ifdef F_24
V_10 -> V_16 ( V_5 , V_379 ,
V_228 ) ;
#else
V_10 -> V_16 ( V_5 , V_380 ,
V_228 ) ;
#endif
break;
case V_381 :
V_10 -> V_16 ( V_5 , V_382 ,
V_228 ) ;
break;
case V_110 :
#ifdef F_24
V_10 -> V_16 ( V_5 , V_382 ,
V_228 ) ;
#else
V_10 -> V_16 ( V_5 , V_380 ,
V_228 ) ;
#endif
V_343 |= V_218 ;
break;
default:
break;
}
V_10 -> V_16 ( V_5 , V_241 | V_128 | V_126 | V_240 | V_124 | V_122 | V_239 , V_129 ) ;
F_43 ( V_5 , V_14 ,
V_343 , 1 ) ;
F_79 ( L_32 ,
V_10 -> V_15 ) ;
} else {
F_43 ( V_5 , V_14 , ~ 0 , 0 ) ;
F_79 ( L_33 ) ;
}
V_10 -> V_16 ( V_5 , V_242 , V_213 ) ;
switch ( V_171 -> V_323 ) {
case V_324 :
V_10 -> V_16 ( V_5 ,
V_383 | V_384 | V_385 |
V_386 , V_223 ) ;
break;
case V_322 :
V_10 -> V_16 ( V_5 ,
V_383 | V_384 | V_385 |
V_386 , V_223 ) ;
break;
}
#ifdef F_24
{
int V_194 = F_95 ( V_5 ) ;
if ( V_194 )
return V_194 ;
}
#endif
switch ( V_171 -> V_319 ) {
case V_320 :
V_10 -> V_16 ( V_5 , V_387 | V_10 -> V_113 ,
V_388 ) ;
V_100 -> V_103 -> V_389 = NULL ;
break;
case V_322 :
V_100 -> V_103 -> V_389 = NULL ;
break;
case V_321 :
V_100 -> V_103 -> V_389 = & V_390 ;
break;
}
F_79 ( L_34 ) ;
return 0 ;
}
static int V_390 ( struct V_4 * V_5 , struct V_99 * V_100 ,
unsigned int V_391 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_391 != 0 )
return - V_392 ;
V_10 -> V_16 ( V_5 , V_387 | V_10 -> V_113 ,
V_388 ) ;
V_100 -> V_103 -> V_389 = NULL ;
return 1 ;
}
static int F_135 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 , unsigned int * V_71 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_247 -> V_168 < 1 )
return - V_392 ;
switch ( V_71 [ 0 ] ) {
case V_393 :
return F_136 ( V_5 , V_100 , V_247 , V_71 ) ;
case V_394 :
if ( V_59 -> V_60 & V_61 ) {
if ( V_71 [ 1 ] & ~ ( V_271 |
V_272 |
V_273 |
V_274 ) ) {
return - V_392 ;
}
V_10 -> V_270 = V_71 [ 1 ] ;
} else if ( V_59 -> V_60 == V_66 ) {
unsigned int V_395 ;
V_395 = V_71 [ 1 ] & 0xf ;
if ( V_395 > 0xF )
return - V_392 ;
V_10 -> V_270 = V_395 ;
F_39 ( V_395 , V_296 ) ;
} else {
unsigned int V_395 ;
unsigned int V_396 ;
V_395 = V_71 [ 1 ] & 0xf ;
V_396 = ( V_71 [ 1 ] >> 4 ) & 0xff ;
if ( V_395 >= 8 )
return - V_392 ;
V_10 -> V_270 = V_395 ;
if ( V_59 -> V_60 == V_187 ) {
F_5 ( V_396 ,
V_397 ) ;
}
}
return 2 ;
default:
break;
}
return - V_392 ;
}
static int F_136 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 ,
unsigned int * V_71 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_398 , V_399 , V_400 ;
int V_175 = 0 ;
if ( ! V_59 -> V_401 )
return - V_392 ;
if ( ( V_71 [ 1 ] & 0xffff0000 ) != V_402 ) {
V_71 [ 1 ] &= ( V_402 | 0xffff ) ;
V_175 ++ ;
}
if ( V_71 [ 2 ] >= V_59 -> V_403 ) {
V_71 [ 2 ] = V_59 -> V_403 - 1 ;
V_175 ++ ;
}
if ( V_71 [ 3 ] > 255 ) {
V_71 [ 3 ] = 255 ;
V_175 ++ ;
}
if ( V_71 [ 4 ] > 255 ) {
V_71 [ 4 ] = 255 ;
V_175 ++ ;
}
V_398 = V_71 [ 3 ] ;
V_399 = V_71 [ 4 ] ;
V_400 = V_71 [ 1 ] & 0xff ;
if ( V_400 & 0xf0 ) {
if ( V_399 < V_398 ) {
V_398 = V_71 [ 4 ] ;
V_399 = V_71 [ 3 ] ;
V_400 =
( ( V_71 [ 1 ] & 0xf ) << 4 ) | ( ( V_71 [ 1 ] & 0xf0 ) >> 4 ) ;
}
V_10 -> V_404 = V_398 ;
V_10 -> V_405 = V_399 ;
switch ( V_400 ) {
case 0x81 :
V_10 -> V_406 = 6 ;
break;
case 0x42 :
V_10 -> V_406 = 3 ;
break;
case 0x96 :
V_10 -> V_406 = 2 ;
break;
default:
V_71 [ 1 ] &= ~ 0xff ;
V_175 ++ ;
}
} else {
if ( V_399 != 0 ) {
V_71 [ 4 ] = 0 ;
V_175 ++ ;
}
switch ( V_400 ) {
case 0x06 :
V_10 -> V_405 = V_398 ;
V_10 -> V_406 = 0 ;
break;
case 0x09 :
V_10 -> V_404 = V_398 ;
V_10 -> V_406 = 1 ;
break;
default:
V_71 [ 1 ] &= ~ 0xff ;
V_175 ++ ;
}
}
if ( V_175 )
return - V_407 ;
return 5 ;
}
static void F_137 ( struct V_4 * V_5 , struct V_99 * V_100 ,
void * V_71 , unsigned int V_199 ,
unsigned int V_200 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_169 * V_103 = V_100 -> V_103 ;
unsigned int V_174 ;
unsigned int V_106 ;
unsigned int V_260 ;
unsigned int V_201 = V_199 / sizeof( short ) ;
short * V_202 = V_71 ;
V_260 = 1 << ( V_59 -> V_408 - 1 ) ;
for ( V_106 = 0 ; V_106 < V_201 ; V_106 ++ ) {
V_174 = F_83 ( V_103 -> V_171 . V_177 [ V_200 ] ) ;
if ( V_59 -> V_409 == 0 || ( V_174 & 1 ) == 0 )
V_202 [ V_106 ] -= V_260 ;
#ifdef F_24
V_202 [ V_106 ] = F_138 ( V_202 [ V_106 ] ) ;
#endif
V_200 ++ ;
V_200 %= V_103 -> V_171 . V_182 ;
}
}
static int F_139 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
unsigned int V_251 [] ,
unsigned int V_410 , int V_411 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_174 ;
unsigned int V_172 ;
unsigned int V_412 ;
int V_106 ;
int V_413 = 0 ;
if ( V_411 ) {
for ( V_106 = 0 ; V_106 < V_59 -> V_414 ; ++ V_106 ) {
V_10 -> V_415 [ V_106 ] &= ~ V_416 ;
F_5 ( V_10 -> V_415 [ V_106 ] ,
F_140 ( V_106 ) ) ;
F_5 ( 0xf , F_141 ( V_106 ) ) ;
}
}
for ( V_106 = 0 ; V_106 < V_410 ; V_106 ++ ) {
const struct V_417 * V_418 ;
V_172 = F_111 ( V_251 [ V_106 ] ) ;
V_174 = F_83 ( V_251 [ V_106 ] ) ;
V_418 = V_100 -> V_419 -> V_174 + V_174 ;
V_413 = 0 ;
V_412 = 0 ;
switch ( V_418 -> V_420 - V_418 -> V_421 ) {
case 20000000 :
V_412 |= V_422 ;
F_5 ( 0 , F_142 ( V_172 ) ) ;
break;
case 10000000 :
V_412 |= V_423 ;
F_5 ( 0 , F_142 ( V_172 ) ) ;
break;
case 4000000 :
V_412 |= V_422 ;
F_5 ( V_424 ,
F_142 ( V_172 ) ) ;
break;
case 2000000 :
V_412 |= V_423 ;
F_5 ( V_424 ,
F_142 ( V_172 ) ) ;
break;
default:
F_6 ( L_35 ,
V_25 ) ;
break;
}
switch ( V_418 -> V_420 + V_418 -> V_421 ) {
case 0 :
V_412 |= V_425 ;
break;
case 10000000 :
V_412 |= V_426 ;
break;
default:
F_6 ( L_36 ,
V_25 ) ;
break;
}
if ( V_411 )
V_412 |= V_416 ;
F_5 ( V_412 , F_140 ( V_172 ) ) ;
V_10 -> V_415 [ V_172 ] = V_412 ;
F_5 ( V_106 , F_141 ( V_172 ) ) ;
}
return V_413 ;
}
static int F_143 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
unsigned int V_251 [] ,
unsigned int V_410 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_174 ;
unsigned int V_172 ;
unsigned int V_412 ;
int V_106 ;
int V_413 = 0 ;
for ( V_106 = 0 ; V_106 < V_410 ; V_106 ++ ) {
V_172 = F_111 ( V_251 [ V_106 ] ) ;
V_174 = F_83 ( V_251 [ V_106 ] ) ;
V_412 = F_144 ( V_172 ) ;
if ( V_59 -> V_409 ) {
if ( ( V_174 & 1 ) == 0 ) {
V_412 |= V_427 ;
V_413 = ( 1 << ( V_59 -> V_408 - 1 ) ) ;
} else {
V_413 = 0 ;
}
if ( V_174 & 2 )
V_412 |= V_428 ;
} else {
V_412 |= V_427 ;
V_413 = ( 1 << ( V_59 -> V_408 - 1 ) ) ;
}
if ( V_251 [ V_106 ] & V_429 )
V_412 |= V_430 ;
V_412 |= ( F_113 ( V_251 [ V_106 ] ) ==
V_285 ) ? V_431 : 0 ;
F_39 ( V_412 , V_432 ) ;
V_10 -> V_415 [ V_172 ] = V_412 ;
}
return V_413 ;
}
static int F_145 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
unsigned int V_251 [] , unsigned int V_410 ,
int V_411 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
if ( V_59 -> V_60 & V_61 )
return F_139 ( V_5 , V_100 , V_251 , V_410 ,
V_411 ) ;
else
return F_143 ( V_5 , V_100 , V_251 , V_410 ) ;
}
static int F_146 ( struct V_4 * V_5 ,
struct V_99 * V_100 , struct V_246 * V_247 ,
unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_71 [ 0 ] = V_10 -> V_433 [ F_111 ( V_247 -> V_251 ) ] ;
return 1 ;
}
static int F_147 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 , unsigned int * V_71 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_172 = F_111 ( V_247 -> V_251 ) ;
unsigned int V_413 ;
V_413 = F_145 ( V_5 , V_100 , & V_247 -> V_251 , 1 , 0 ) ;
V_10 -> V_433 [ V_172 ] = V_71 [ 0 ] ;
if ( V_59 -> V_60 & V_61 ) {
F_39 ( V_71 [ 0 ] , F_148 ( V_172 ) ) ;
} else
F_39 ( V_71 [ 0 ] ^ V_413 ,
( V_172 ) ? V_434 : V_435 ) ;
return 1 ;
}
static int F_149 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 , unsigned int * V_71 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_172 = F_111 ( V_247 -> V_251 ) ;
unsigned int V_413 ;
F_150 ( 1 << V_172 , V_436 ) ;
V_413 = 1 << ( V_59 -> V_408 - 1 ) ;
F_145 ( V_5 , V_100 , & V_247 -> V_251 , 1 , 0 ) ;
V_10 -> V_433 [ V_172 ] = V_71 [ 0 ] ;
F_150 ( V_71 [ 0 ] ^ V_413 , F_151 ( V_172 ) ) ;
return 1 ;
}
static int F_152 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 , unsigned int * V_71 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
switch ( V_71 [ 0 ] ) {
case V_437 :
switch ( V_71 [ 1 ] ) {
case V_47 :
V_71 [ 2 ] = 1 + V_59 -> V_183 * sizeof( short ) ;
if ( V_10 -> V_40 )
V_71 [ 2 ] += V_10 -> V_40 -> V_438 ;
break;
case V_44 :
V_71 [ 2 ] = 0 ;
break;
default:
return - V_392 ;
break;
}
return 0 ;
default:
break;
}
return - V_392 ;
}
static int F_153 ( struct V_4 * V_5 , struct V_99 * V_100 ,
unsigned int V_391 )
{
const struct V_58 * V_59 V_197 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_163 ;
int V_439 ;
int V_106 ;
static const int V_105 = 1000 ;
if ( V_391 != 0 )
return - V_392 ;
V_100 -> V_103 -> V_389 = NULL ;
F_43 ( V_5 , V_17 ,
V_164 | V_165 , 0 ) ;
V_439 = V_165 ;
#ifdef F_24
V_10 -> V_16 ( V_5 , 1 , V_185 ) ;
if ( V_59 -> V_60 & V_178 )
F_40 ( V_5 , 0x6 , V_186 ) ;
V_163 = F_99 ( V_5 ) ;
if ( V_163 )
return V_163 ;
V_163 = F_59 ( V_5 ) ;
if ( V_163 < 0 )
return V_163 ;
#else
V_163 = F_85 ( V_5 , V_100 ) ;
if ( V_163 == 0 )
return - V_108 ;
V_439 |= V_164 ;
#endif
V_10 -> V_16 ( V_5 , V_10 -> V_440 | V_441 ,
V_442 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_440 , V_442 ) ;
for ( V_106 = 0 ; V_106 < V_105 ; V_106 ++ ) {
F_60 ( 1 ) ;
if ( ( V_10 -> V_73 ( V_5 ,
V_443 ) &
V_444 ) == 0 )
break;
}
if ( V_106 == V_105 ) {
F_19 ( V_5 ,
L_37 ) ;
return - V_208 ;
}
V_10 -> V_16 ( V_5 , V_149 ,
V_160 ) ;
F_43 ( V_5 , V_17 , V_439 , 1 ) ;
V_10 -> V_16 ( V_5 ,
V_10 -> V_445 | V_446 | V_447 | V_448
| V_449 | V_450 ,
V_451 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_452 | V_453 ,
V_454 ) ;
return 0 ;
}
static int F_154 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
const struct V_170 * V_171 = & V_100 -> V_103 -> V_171 ;
int V_72 ;
int V_106 ;
unsigned V_455 ;
if ( V_5 -> V_79 == 0 ) {
F_19 ( V_5 , L_31 ) ;
return - V_208 ;
}
V_10 -> V_16 ( V_5 , V_456 , V_213 ) ;
V_10 -> V_16 ( V_5 , V_457 , V_451 ) ;
if ( V_59 -> V_60 & V_178 ) {
F_150 ( V_458 , V_459 ) ;
V_72 = 0 ;
for ( V_106 = 0 ; V_106 < V_171 -> V_182 ; V_106 ++ ) {
int V_172 ;
V_172 = F_111 ( V_171 -> V_177 [ V_106 ] ) ;
V_72 |= 1 << V_172 ;
F_150 ( V_172 , V_460 ) ;
}
F_150 ( V_72 , V_461 ) ;
}
F_145 ( V_5 , V_100 , V_171 -> V_177 , V_171 -> V_182 , 1 ) ;
if ( V_171 -> V_328 == V_329 ) {
V_10 -> V_462 |= V_463 ;
V_10 -> V_462 &= ~ V_464 ;
} else {
V_10 -> V_462 &= ~ V_463 ;
V_10 -> V_462 |= V_464 ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_462 , V_465 ) ;
switch ( V_171 -> V_319 ) {
case V_321 :
case V_320 :
V_10 -> V_466 &=
~ ( V_467 | F_155 ( - 1 ) ) ;
V_10 -> V_466 |= V_468 | V_469 ;
V_10 -> V_16 ( V_5 , V_10 -> V_466 ,
V_470 ) ;
break;
case V_322 :
V_10 -> V_466 =
F_155 ( F_111 ( V_171 -> V_330 ) + 1 ) ;
if ( V_171 -> V_330 & V_331 )
V_10 -> V_466 |= V_467 ;
if ( V_171 -> V_330 & V_332 )
V_10 -> V_466 |= V_468 ;
V_10 -> V_16 ( V_5 , V_10 -> V_466 ,
V_470 ) ;
break;
default:
F_2 () ;
break;
}
V_10 -> V_440 &= ~ V_471 ;
V_10 -> V_16 ( V_5 , V_10 -> V_440 , V_442 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_462 , V_465 ) ;
V_10 -> V_472 &= ~ V_473 ;
V_10 -> V_16 ( V_5 , V_10 -> V_472 , V_474 ) ;
if ( V_171 -> V_328 == V_329 ) {
V_10 -> V_357 ( V_5 , 0xffffff , V_475 ) ;
} else {
V_10 -> V_357 ( V_5 , 0 , V_475 ) ;
}
V_10 -> V_16 ( V_5 , V_476 , V_451 ) ;
V_10 -> V_472 &= ~ V_477 ;
V_10 -> V_16 ( V_5 , V_10 -> V_472 , V_474 ) ;
switch ( V_171 -> V_328 ) {
case V_327 :
if ( V_59 -> V_60 & V_61 ) {
V_10 -> V_357 ( V_5 , V_171 -> V_337 - 1 ,
V_478 ) ;
V_10 -> V_16 ( V_5 , V_479 ,
V_451 ) ;
} else {
V_10 -> V_357 ( V_5 , V_171 -> V_337 ,
V_478 ) ;
V_10 -> V_16 ( V_5 , V_479 ,
V_451 ) ;
V_10 -> V_357 ( V_5 , V_171 -> V_337 - 1 ,
V_478 ) ;
}
break;
case V_329 :
V_10 -> V_357 ( V_5 , 0xffffff , V_478 ) ;
V_10 -> V_16 ( V_5 , V_479 , V_451 ) ;
V_10 -> V_357 ( V_5 , 0xffffff , V_478 ) ;
break;
default:
V_10 -> V_357 ( V_5 , 0 , V_478 ) ;
V_10 -> V_16 ( V_5 , V_479 , V_451 ) ;
V_10 -> V_357 ( V_5 , V_171 -> V_337 , V_478 ) ;
}
V_10 -> V_462 &=
~ ( F_156 ( 0x1f ) | V_480 |
F_157 ( 0x1f ) | V_481 ) ;
switch ( V_171 -> V_323 ) {
case V_324 :
V_10 -> V_452 &= ~ V_482 ;
V_455 =
F_119 ( V_5 , V_171 -> V_333 ,
V_309 ) ;
V_10 -> V_357 ( V_5 , 1 , V_483 ) ;
V_10 -> V_16 ( V_5 , V_484 , V_451 ) ;
V_10 -> V_357 ( V_5 , V_455 , V_483 ) ;
break;
case V_322 :
V_10 -> V_462 |=
F_157 ( V_171 -> V_333 ) ;
if ( V_171 -> V_333 & V_331 )
V_10 -> V_462 |= V_481 ;
V_10 -> V_452 |= V_482 ;
break;
default:
F_2 () ;
break;
}
V_10 -> V_16 ( V_5 , V_10 -> V_452 , V_454 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_462 , V_465 ) ;
V_10 -> V_472 &=
~ ( F_158 ( 3 ) | V_485 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_472 , V_474 ) ;
if ( V_171 -> V_335 > 1 ) {
V_10 -> V_462 |= V_486 ;
V_10 -> V_16 ( V_5 ,
F_159 ( V_171 -> V_335 -
1 ) |
F_160
( V_487 ) ,
V_488 ) ;
} else {
unsigned V_72 ;
V_10 -> V_462 &= ~ V_486 ;
V_72 = F_160 ( V_487 ) ;
if ( V_59 -> V_60 &
( V_61 | V_178 ) ) {
V_72 |= F_159 ( 0 ) ;
} else {
V_72 |=
F_159 ( F_111 ( V_171 -> V_177 [ 0 ] ) ) ;
}
V_10 -> V_16 ( V_5 , V_72 , V_488 ) ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_462 , V_465 ) ;
V_10 -> V_16 ( V_5 , V_450 | V_449 ,
V_451 ) ;
V_10 -> V_440 |= V_489 ;
V_10 -> V_16 ( V_5 , V_10 -> V_440 , V_442 ) ;
V_10 -> V_472 &= ~ V_490 ;
#ifdef F_24
V_10 -> V_472 |= V_491 ;
#else
V_10 -> V_472 |= V_492 ;
#endif
V_10 -> V_472 &= ~ V_493 ;
V_10 -> V_16 ( V_5 , V_10 -> V_472 , V_474 ) ;
V_72 = V_494 | V_495 |
V_496 ;
if ( V_59 -> V_183 )
V_72 |= V_497 ;
else
V_72 |= V_498 ;
#if 0
if (board->reg_type & ni_reg_m_series_mask)
bits |= AO_Number_Of_DAC_Packages;
#endif
V_10 -> V_16 ( V_5 , V_72 , V_499 ) ;
V_10 -> V_16 ( V_5 , V_500 , V_501 ) ;
V_10 -> V_16 ( V_5 , V_502 , V_213 ) ;
if ( V_171 -> V_328 == V_327 ) {
V_10 -> V_16 ( V_5 , V_147 ,
V_160 ) ;
F_43 ( V_5 , V_17 ,
V_503 , 1 ) ;
}
V_100 -> V_103 -> V_389 = & F_153 ;
return 0 ;
}
static int F_161 ( struct V_4 * V_5 , struct V_99 * V_100 ,
struct V_170 * V_171 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_175 = 0 ;
int V_316 ;
if ( ( V_171 -> V_12 & V_318 ) == 0 )
V_171 -> V_12 |= V_318 ;
V_175 |= F_123 ( & V_171 -> V_319 , V_321 | V_322 ) ;
V_175 |= F_123 ( & V_171 -> V_323 ,
V_324 | V_322 ) ;
V_175 |= F_123 ( & V_171 -> V_325 , V_320 ) ;
V_175 |= F_123 ( & V_171 -> V_326 , V_327 ) ;
V_175 |= F_123 ( & V_171 -> V_328 , V_327 | V_329 ) ;
if ( V_175 )
return 1 ;
V_175 |= F_124 ( V_171 -> V_319 ) ;
V_175 |= F_124 ( V_171 -> V_323 ) ;
V_175 |= F_124 ( V_171 -> V_328 ) ;
if ( V_175 )
return 2 ;
if ( V_171 -> V_319 == V_322 ) {
unsigned int V_316 = F_111 ( V_171 -> V_330 ) ;
if ( V_316 > 18 )
V_316 = 18 ;
V_316 |= ( V_171 -> V_330 & ( V_331 | V_332 ) ) ;
V_175 |= F_125 ( & V_171 -> V_330 , V_316 ) ;
} else {
V_175 |= F_125 ( & V_171 -> V_330 , 0 ) ;
}
if ( V_171 -> V_323 == V_324 ) {
V_175 |= F_126 ( & V_171 -> V_333 ,
V_59 -> V_504 ) ;
V_175 |= F_127 ( & V_171 -> V_333 ,
V_10 -> V_310 * 0xffffff ) ;
}
V_175 |= F_125 ( & V_171 -> V_334 , 0 ) ;
V_175 |= F_125 ( & V_171 -> V_335 , V_171 -> V_182 ) ;
if ( V_171 -> V_328 == V_327 )
V_175 |= F_127 ( & V_171 -> V_337 , 0x00ffffff ) ;
else
V_175 |= F_125 ( & V_171 -> V_337 , 0 ) ;
if ( V_175 )
return 3 ;
if ( V_171 -> V_323 == V_324 ) {
V_316 = V_171 -> V_333 ;
V_171 -> V_333 =
F_120 ( V_5 , F_119 ( V_5 ,
V_171 -> V_333 ,
V_171 ->
V_12 &
V_338 ) ) ;
if ( V_316 != V_171 -> V_333 )
V_175 ++ ;
}
if ( V_175 )
return 4 ;
if ( V_175 )
return 5 ;
return 0 ;
}
static int F_69 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
F_27 ( V_5 ) ;
V_10 -> V_16 ( V_5 , V_456 , V_213 ) ;
V_10 -> V_16 ( V_5 , V_457 , V_451 ) ;
F_43 ( V_5 , V_17 , ~ 0 , 0 ) ;
V_10 -> V_16 ( V_5 , V_494 , V_499 ) ;
V_10 -> V_16 ( V_5 , 0x3f98 , V_160 ) ;
V_10 -> V_16 ( V_5 , V_494 | V_495 |
V_496 , V_499 ) ;
V_10 -> V_16 ( V_5 , 0 , V_488 ) ;
V_10 -> V_16 ( V_5 , 0 , V_501 ) ;
V_10 -> V_445 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_445 , V_451 ) ;
V_10 -> V_452 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_452 , V_454 ) ;
V_10 -> V_462 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_462 , V_465 ) ;
V_10 -> V_472 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_472 , V_474 ) ;
if ( V_59 -> V_60 & V_61 )
V_10 -> V_440 = V_505 ;
else
V_10 -> V_440 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_440 , V_442 ) ;
V_10 -> V_466 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_466 ,
V_470 ) ;
if ( V_59 -> V_60 & V_178 ) {
unsigned V_506 = 0 ;
unsigned V_106 ;
for ( V_106 = 0 ; V_106 < V_100 -> V_257 ; ++ V_106 ) {
V_506 |= 1 << V_106 ;
}
F_150 ( V_506 , V_436 ) ;
F_150 ( V_458 , V_459 ) ;
}
V_10 -> V_16 ( V_5 , V_502 , V_213 ) ;
return 0 ;
}
static int F_162 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 , unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
#ifdef F_163
F_6 ( L_38 ,
F_111 ( V_247 -> V_251 ) , V_71 [ 0 ] ) ;
#endif
switch ( V_71 [ 0 ] ) {
case V_507 :
V_100 -> V_508 |= 1 << F_111 ( V_247 -> V_251 ) ;
break;
case V_509 :
V_100 -> V_508 &= ~ ( 1 << F_111 ( V_247 -> V_251 ) ) ;
break;
case V_510 :
V_71 [ 1 ] =
( V_100 ->
V_508 & ( 1 << F_111 ( V_247 -> V_251 ) ) ) ? V_47 :
V_44 ;
return V_247 -> V_168 ;
break;
default:
return - V_392 ;
}
V_10 -> V_511 &= ~ V_512 ;
V_10 -> V_511 |= F_164 ( V_100 -> V_508 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_511 , V_513 ) ;
return 1 ;
}
static int F_165 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 , unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
#ifdef F_163
F_6 ( L_39 , V_71 [ 0 ] , V_71 [ 1 ] ) ;
#endif
if ( V_71 [ 0 ] ) {
if ( ( V_71 [ 0 ] & ( V_514 | V_515 ) )
&& V_10 -> V_516 )
return - V_42 ;
V_100 -> V_517 &= ~ V_71 [ 0 ] ;
V_100 -> V_517 |= ( V_71 [ 0 ] & V_71 [ 1 ] ) ;
V_10 -> V_518 &= ~ V_519 ;
V_10 -> V_518 |= F_166 ( V_100 -> V_517 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_518 ,
V_520 ) ;
}
V_71 [ 1 ] = V_10 -> V_73 ( V_5 , V_521 ) ;
return V_247 -> V_168 ;
}
static int F_167 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 ,
unsigned int * V_71 )
{
struct V_9 * V_10 V_197 = V_5 -> V_11 ;
#ifdef F_163
F_6 ( L_40 ,
F_111 ( V_247 -> V_251 ) , V_71 [ 0 ] ) ;
#endif
switch ( V_71 [ 0 ] ) {
case V_507 :
V_100 -> V_508 |= 1 << F_111 ( V_247 -> V_251 ) ;
break;
case V_509 :
V_100 -> V_508 &= ~ ( 1 << F_111 ( V_247 -> V_251 ) ) ;
break;
case V_510 :
V_71 [ 1 ] =
( V_100 ->
V_508 & ( 1 << F_111 ( V_247 -> V_251 ) ) ) ? V_47 :
V_44 ;
return V_247 -> V_168 ;
break;
default:
return - V_392 ;
}
F_33 ( V_100 -> V_508 , V_522 ) ;
return 1 ;
}
static int F_168 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 ,
unsigned int * V_71 )
{
struct V_9 * V_10 V_197 = V_5 -> V_11 ;
#ifdef F_163
F_6 ( L_41 , V_71 [ 0 ] ,
V_71 [ 1 ] ) ;
#endif
if ( V_71 [ 0 ] ) {
V_100 -> V_517 &= ~ V_71 [ 0 ] ;
V_100 -> V_517 |= ( V_71 [ 0 ] & V_71 [ 1 ] ) ;
F_33 ( V_100 -> V_517 , V_523 ) ;
}
V_71 [ 1 ] = F_34 ( V_524 ) ;
return V_247 -> V_168 ;
}
static int F_169 ( struct V_4 * V_5 ,
struct V_99 * V_100 , struct V_170 * V_171 )
{
int V_175 = 0 ;
int V_316 ;
unsigned V_106 ;
V_175 |= F_123 ( & V_171 -> V_319 , V_321 ) ;
V_175 |= F_123 ( & V_171 -> V_323 , V_322 ) ;
V_175 |= F_123 ( & V_171 -> V_325 , V_320 ) ;
V_175 |= F_123 ( & V_171 -> V_326 , V_327 ) ;
V_175 |= F_123 ( & V_171 -> V_328 , V_329 ) ;
if ( V_175 )
return 1 ;
if ( V_175 )
return 2 ;
V_175 |= F_125 ( & V_171 -> V_330 , 0 ) ;
V_316 = V_171 -> V_333 ;
V_316 &= F_170 ( V_525 , 0 , 0 , V_331 ) ;
if ( V_316 != V_171 -> V_333 )
V_175 |= - V_392 ;
V_175 |= F_125 ( & V_171 -> V_334 , 0 ) ;
V_175 |= F_125 ( & V_171 -> V_335 , V_171 -> V_182 ) ;
V_175 |= F_125 ( & V_171 -> V_337 , 0 ) ;
if ( V_175 )
return 3 ;
if ( V_175 )
return 4 ;
for ( V_106 = 0 ; V_106 < V_171 -> V_182 ; ++ V_106 ) {
if ( V_171 -> V_177 [ V_106 ] != V_106 )
V_175 = 1 ;
}
if ( V_175 )
return 5 ;
return 0 ;
}
static int F_171 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
struct V_9 * V_10 V_197 = V_5 -> V_11 ;
const struct V_170 * V_171 = & V_100 -> V_103 -> V_171 ;
unsigned V_526 = V_527 | V_528 ;
int V_194 ;
F_33 ( V_529 , V_530 ) ;
switch ( V_171 -> V_323 ) {
case V_322 :
V_526 |=
F_111 ( V_171 -> V_333 ) &
V_525 ;
break;
default:
F_2 () ;
break;
}
if ( V_171 -> V_333 & V_331 )
V_526 |= V_531 ;
F_33 ( V_526 , V_532 ) ;
if ( V_100 -> V_508 ) {
F_33 ( V_100 -> V_517 , V_533 ) ;
F_33 ( V_534 , V_530 ) ;
F_33 ( V_100 -> V_508 , V_535 ) ;
} else {
F_19 ( V_5 ,
L_42 ) ;
return - V_208 ;
}
V_194 = F_23 ( V_5 ) ;
if ( V_194 < 0 ) {
return V_194 ;
}
V_100 -> V_103 -> V_389 = & V_536 ;
return 0 ;
}
static int V_536 ( struct V_4 * V_5 , struct V_99 * V_100 ,
unsigned int V_391 )
{
#ifdef F_24
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_12 ;
#endif
int V_194 = 0 ;
unsigned V_106 ;
const unsigned V_105 = 1000 ;
V_100 -> V_103 -> V_389 = NULL ;
F_100 ( V_100 -> V_103 , V_100 -> V_103 -> V_207 ) ;
#ifdef F_24
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_55 ) {
F_97 ( V_10 -> V_55 , 32 , 32 ) ;
F_98 ( V_10 -> V_55 ) ;
} else {
F_19 ( V_5 , L_43 ) ;
V_194 = - V_208 ;
}
F_8 ( & V_10 -> V_38 , V_12 ) ;
if ( V_194 < 0 )
return V_194 ;
#endif
for ( V_106 = 0 ; V_106 < V_105 ; ++ V_106 ) {
if ( F_34 ( V_537 ) & V_538 )
break;
F_60 ( 10 ) ;
}
if ( V_106 == V_105 ) {
F_19 ( V_5 , L_44 ) ;
F_71 ( V_5 , V_100 ) ;
return - V_208 ;
}
F_33 ( V_539 | V_540 |
V_541 ,
V_530 ) ;
return V_194 ;
}
static int F_71 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
struct V_9 * V_10 V_197 = V_5 -> V_11 ;
F_33 ( V_542 | V_543 |
V_544 |
V_545 ,
V_530 ) ;
F_33 ( 0 , V_535 ) ;
F_29 ( V_5 ) ;
return 0 ;
}
static void F_54 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 V_197 = V_5 -> V_11 ;
unsigned V_546 ;
struct V_99 * V_100 = & V_5 -> V_101 [ V_119 ] ;
#ifdef F_24
unsigned long V_12 ;
#endif
if ( ( V_59 -> V_60 & V_61 ) == 0 ) {
return;
}
#ifdef F_24
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_55 ) {
unsigned V_547 =
F_46 ( V_10 -> V_55 ) ;
if ( V_547 & V_92 ) {
F_47 ( V_93 ,
V_10 -> V_40 -> V_94 +
F_48 ( V_10 -> V_55 -> V_26 ) ) ;
}
F_58 ( V_10 -> V_55 , V_100 -> V_103 ) ;
}
F_8 ( & V_10 -> V_38 , V_12 ) ;
#endif
V_546 = F_34 ( V_537 ) ;
if ( V_546 & ( V_548 | V_549 ) ) {
F_33 ( V_550 , V_530 ) ;
V_100 -> V_103 -> V_111 |= V_117 ;
}
if ( V_546 & V_551 ) {
F_33 ( V_544 ,
V_530 ) ;
}
F_67 ( V_5 , V_100 ) ;
}
static int F_172 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 , unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_175 = V_247 -> V_168 ;
unsigned char V_552 , V_553 = 0 ;
if ( V_247 -> V_168 != 2 )
return - V_392 ;
switch ( V_71 [ 0 ] ) {
case V_554 :
#ifdef F_163
F_6 ( L_45 , V_71 [ 1 ] ) ;
#endif
V_10 -> V_555 = 1 ;
V_10 -> V_511 |= V_556 ;
if ( V_71 [ 1 ] == V_557 ) {
V_10 -> V_555 = 0 ;
V_10 -> V_511 &= ~ ( V_556 |
V_558 ) ;
V_71 [ 1 ] = V_557 ;
V_10 -> V_516 = V_71 [ 1 ] ;
} else if ( V_71 [ 1 ] <= V_559 ) {
V_10 -> V_511 &= ~ V_560 ;
V_10 -> V_561 |= V_562 ;
V_10 -> V_561 &= ~ V_563 ;
V_71 [ 1 ] = V_559 ;
V_10 -> V_516 = V_71 [ 1 ] ;
} else if ( V_71 [ 1 ] <= V_564 ) {
V_10 -> V_511 &= ~ V_560 ;
V_10 -> V_561 |= V_562 |
V_563 ;
V_71 [ 1 ] = V_564 ;
V_10 -> V_516 = V_71 [ 1 ] ;
} else if ( V_71 [ 1 ] <= V_565 ) {
V_10 -> V_511 |= V_560 ;
V_10 -> V_561 |= V_562 |
V_563 ;
V_71 [ 1 ] = V_565 ;
V_10 -> V_516 = V_71 [ 1 ] ;
} else {
V_10 -> V_511 &= ~ ( V_556 |
V_558 ) ;
V_10 -> V_555 = 0 ;
V_71 [ 1 ] = ( V_71 [ 1 ] / 1000 ) * 1000 ;
V_10 -> V_516 = V_71 [ 1 ] ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_511 ,
V_513 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_561 ,
V_566 ) ;
return 1 ;
break;
case V_567 :
if ( V_10 -> V_516 == 0 ) {
return - V_392 ;
}
V_552 = V_71 [ 1 ] & 0xFF ;
if ( V_10 -> V_555 ) {
V_175 = F_173 ( V_5 , V_100 , V_552 ,
& V_553 ) ;
} else if ( V_10 -> V_516 > 0 ) {
V_175 = F_174 ( V_5 , V_100 , V_552 ,
& V_553 ) ;
} else {
F_6 ( L_46 ) ;
return - V_392 ;
}
if ( V_175 < 0 )
return V_175 ;
V_71 [ 1 ] = V_553 & 0xFF ;
return V_247 -> V_168 ;
break;
default:
return - V_392 ;
}
}
static int F_173 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
unsigned char V_568 ,
unsigned char * V_569 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_570 ;
int V_175 = 0 , V_243 = 20 ;
#ifdef F_163
F_6 ( L_47 , V_568 ) ;
#endif
V_10 -> V_518 &= ~ V_571 ;
V_10 -> V_518 |= F_175 ( V_568 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_518 , V_520 ) ;
V_570 = V_10 -> V_73 ( V_5 , V_572 ) ;
if ( V_570 & V_573 ) {
V_175 = - V_42 ;
goto Error;
}
V_10 -> V_511 |= V_574 ;
V_10 -> V_16 ( V_5 , V_10 -> V_511 , V_513 ) ;
V_10 -> V_511 &= ~ V_574 ;
while ( ( V_570 =
V_10 -> V_73 ( V_5 ,
V_572 ) ) &
V_573 ) {
F_60 ( ( V_10 -> V_516 + 999 ) / 1000 ) ;
if ( -- V_243 < 0 ) {
F_6
( L_48 ) ;
V_175 = - V_255 ;
goto Error;
}
}
F_60 ( ( V_10 -> V_516 + 999 ) / 1000 ) ;
if ( V_569 != NULL ) {
* V_569 = V_10 -> V_73 ( V_5 , V_575 ) ;
#ifdef F_163
F_6 ( L_49 , * V_569 ) ;
#endif
}
Error:
V_10 -> V_16 ( V_5 , V_10 -> V_511 , V_513 ) ;
return V_175 ;
}
static int F_174 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
unsigned char V_568 ,
unsigned char * V_569 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned char V_248 , V_576 = 0 ;
#ifdef F_163
F_6 ( L_50 , V_568 ) ;
#endif
F_60 ( ( V_10 -> V_516 + 999 ) / 1000 ) ;
for ( V_248 = 0x80 ; V_248 ; V_248 >>= 1 ) {
V_10 -> V_518 &= ~ V_515 ;
if ( V_568 & V_248 ) {
V_10 -> V_518 |= V_515 ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_518 ,
V_520 ) ;
V_10 -> V_511 |= V_558 ;
V_10 -> V_16 ( V_5 , V_10 -> V_511 ,
V_513 ) ;
F_60 ( ( V_10 -> V_516 + 999 ) / 2000 ) ;
V_10 -> V_511 &= ~ V_558 ;
V_10 -> V_16 ( V_5 , V_10 -> V_511 ,
V_513 ) ;
F_60 ( ( V_10 -> V_516 + 999 ) / 2000 ) ;
if ( V_10 -> V_73 ( V_5 ,
V_521 ) & V_514 )
{
V_576 |= V_248 ;
}
}
#ifdef F_163
F_6 ( L_51 , V_576 ) ;
#endif
if ( V_569 )
* V_569 = V_576 ;
return 0 ;
}
static void F_176 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_10 ) {
if ( V_10 -> V_52 ) {
F_177 ( V_10 -> V_52 ) ;
}
}
}
static void F_178 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
int V_106 ;
for ( V_106 = 0 ; V_106 < V_100 -> V_257 ; V_106 ++ ) {
F_38 ( V_5 , F_144 ( V_106 ) | 0x0 ,
V_577 ) ;
}
F_150 ( 0x0 , V_578 ) ;
}
static unsigned F_179 ( enum V_579 V_6 )
{
unsigned V_580 ;
switch ( V_6 ) {
case V_581 :
V_580 = F_180 ( 0 ) ;
break;
case V_582 :
V_580 = F_180 ( 1 ) ;
break;
case V_583 :
V_580 = F_181 ( 0 ) ;
break;
case V_584 :
V_580 = F_181 ( 1 ) ;
break;
case V_585 :
V_580 = F_182 ( 0 ) ;
break;
case V_586 :
V_580 = F_182 ( 1 ) ;
break;
case V_587 :
V_580 = F_183 ( 0 ) ;
break;
case V_588 :
V_580 = F_183 ( 1 ) ;
break;
case V_589 :
V_580 = F_184 ( 0 ) ;
break;
case V_590 :
V_580 = F_184 ( 1 ) ;
break;
case V_591 :
V_580 = F_185 ( 0 ) ;
break;
case V_592 :
V_580 = F_185 ( 1 ) ;
break;
case V_593 :
V_580 = F_186 ( 0 ) ;
break;
case V_594 :
V_580 = F_186 ( 1 ) ;
break;
case V_595 :
V_580 = F_187 ( 0 ) ;
break;
case V_596 :
V_580 = F_187 ( 1 ) ;
break;
case V_597 :
V_580 = V_598 ;
break;
case V_599 :
V_580 = V_213 ;
break;
case V_600 :
V_580 = V_572 ;
break;
case V_601 :
V_580 = V_443 ;
break;
case V_602 :
V_580 = V_129 ;
break;
case V_603 :
V_580 = V_160 ;
break;
case V_604 :
V_580 = V_89 ;
break;
case V_605 :
V_580 = V_90 ;
break;
case V_606 :
V_580 = V_14 ;
break;
case V_607 :
V_580 = V_17 ;
break;
default:
F_6 ( L_52 ,
V_25 , V_6 ) ;
F_2 () ;
return 0 ;
break;
}
return V_580 ;
}
static void F_188 ( struct V_608 * V_609 , unsigned V_72 ,
enum V_579 V_6 )
{
struct V_4 * V_5 = V_609 -> V_52 -> V_5 ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned V_580 ;
static const unsigned V_610 = V_611 | V_612 ;
static const unsigned V_613 =
V_614 | V_615 ;
static const unsigned V_616 =
V_617 | V_618 ;
switch ( V_6 ) {
case V_619 :
F_39 ( V_72 , V_620 ) ;
break;
case V_621 :
F_39 ( V_72 , V_622 ) ;
break;
case V_623 :
F_39 ( V_72 , V_624 ) ;
break;
case V_625 :
F_39 ( V_72 , V_626 ) ;
break;
case V_627 :
F_39 ( V_72 , V_628 ) ;
break;
case V_629 :
F_39 ( V_72 , V_630 ) ;
break;
case V_631 :
F_39 ( V_72 , V_632 ) ;
break;
case V_633 :
F_39 ( V_72 , V_634 ) ;
break;
case V_591 :
case V_592 :
case V_593 :
case V_594 :
V_580 = F_179 ( V_6 ) ;
V_10 -> V_357 ( V_5 , V_72 , V_580 ) ;
break;
case V_606 :
F_17 ( V_72 & ~ V_613 ) ;
F_3 ( V_5 , V_14 ,
V_613 , V_72 ) ;
break;
case V_607 :
F_17 ( V_72 & ~ V_616 ) ;
F_3 ( V_5 , V_17 ,
V_616 , V_72 ) ;
break;
case V_599 :
F_17 ( V_72 & ~ V_610 ) ;
default:
V_580 = F_179 ( V_6 ) ;
V_10 -> V_16 ( V_5 , V_72 , V_580 ) ;
}
}
static unsigned F_189 ( struct V_608 * V_609 ,
enum V_579 V_6 )
{
struct V_4 * V_5 = V_609 -> V_52 -> V_5 ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned V_580 ;
switch ( V_6 ) {
case V_635 :
return F_42 ( V_636 ) ;
break;
case V_637 :
return F_42 ( V_638 ) ;
break;
case V_585 :
case V_586 :
case V_587 :
case V_588 :
V_580 = F_179 ( V_6 ) ;
return V_10 -> V_639 ( V_5 , V_580 ) ;
break;
default:
V_580 = F_179 ( V_6 ) ;
return V_10 -> V_73 ( V_5 , V_580 ) ;
break;
}
return 0 ;
}
static int F_190 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 , unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_71 [ 0 ] = V_10 -> V_561 & V_640 ;
return 1 ;
}
static int F_191 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 , unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_10 -> V_561 &= ~ V_641 ;
V_10 -> V_16 ( V_5 , V_10 -> V_561 ,
V_566 ) ;
V_10 -> V_561 &= ~ V_640 ;
V_10 -> V_561 |= F_192 ( V_71 [ 0 ] ) ;
V_10 -> V_561 |= V_641 ;
V_10 -> V_16 ( V_5 , V_10 -> V_561 ,
V_566 ) ;
return V_247 -> V_168 ;
}
static int F_193 ( struct V_4 * V_5 ,
unsigned int V_642 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
switch ( V_642 ) {
case V_643 :
V_10 -> V_561 &= ~ V_644 ;
break;
case V_645 :
V_10 -> V_561 |= V_644 ;
break;
default:
return - V_392 ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_561 ,
V_566 ) ;
return 3 ;
}
static void F_194 ( struct V_4 * V_5 ,
unsigned int * V_642 ,
unsigned int * V_646 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_10 -> V_561 & V_644 ) {
* V_642 = V_645 ;
* V_646 = V_647 ;
} else {
* V_642 = V_643 ;
* V_646 = V_648 * 2 ;
}
}
static int F_195 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 , unsigned int * V_71 )
{
switch ( V_71 [ 0 ] ) {
case V_649 :
return F_193 ( V_5 , V_71 [ 1 ] ) ;
break;
case V_650 :
F_194 ( V_5 , & V_71 [ 1 ] , & V_71 [ 2 ] ) ;
return 3 ;
default:
break;
}
return - V_392 ;
}
static int F_196 ( struct V_4 * V_5 )
{
struct V_9 * V_10 ;
V_10 = F_197 ( sizeof( * V_10 ) , V_651 ) ;
if ( ! V_10 )
return - V_652 ;
V_5 -> V_11 = V_10 ;
F_198 ( & V_10 -> V_75 ) ;
F_198 ( & V_10 -> V_13 ) ;
F_198 ( & V_10 -> V_38 ) ;
return 0 ;
}
static int F_199 ( int V_43 , int V_653 , int V_71 , unsigned long V_654 )
{
struct V_4 * V_5 = (struct V_4 * ) V_654 ;
struct V_9 * V_10 V_197 = V_5 -> V_11 ;
if ( V_43 ) {
F_5 ( V_71 , V_655 + 2 * V_653 ) ;
return 0 ;
} else {
return F_90 ( V_655 + 2 * V_653 ) ;
}
}
static int F_200 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 , unsigned int * V_71 )
{
V_71 [ 0 ] = F_201 ( V_5 , F_111 ( V_247 -> V_251 ) ) ;
return 1 ;
}
static int F_201 ( struct V_4 * V_5 , int V_74 )
{
struct V_9 * V_10 V_197 = V_5 -> V_11 ;
int V_656 ;
int V_657 ;
V_657 = 0x0300 | ( ( V_74 & 0x100 ) << 3 ) | ( V_74 & 0xff ) ;
F_5 ( 0x04 , V_658 ) ;
for ( V_656 = 0x8000 ; V_656 ; V_656 >>= 1 ) {
F_5 ( 0x04 | ( ( V_656 & V_657 ) ? 0x02 : 0 ) ,
V_658 ) ;
F_5 ( 0x05 | ( ( V_656 & V_657 ) ? 0x02 : 0 ) ,
V_658 ) ;
}
V_657 = 0 ;
for ( V_656 = 0x80 ; V_656 ; V_656 >>= 1 ) {
F_5 ( 0x04 , V_658 ) ;
F_5 ( 0x05 , V_658 ) ;
V_657 |= ( ( F_90 ( V_198 ) & V_659 ) ? V_656 : 0 ) ;
}
F_5 ( 0x00 , V_658 ) ;
return V_657 ;
}
static int F_202 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 ,
unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_71 [ 0 ] = V_10 -> V_660 [ F_111 ( V_247 -> V_251 ) ] ;
return 1 ;
}
static int F_203 ( struct V_4 * V_5 , unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_71 [ 1 ] = V_10 -> V_661 * V_10 -> V_310 ;
V_71 [ 2 ] = V_10 -> V_662 * V_10 -> V_310 ;
return 3 ;
}
static int F_204 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 , unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned V_663 , V_664 ;
switch ( V_71 [ 0 ] ) {
case V_665 :
switch ( V_71 [ 1 ] ) {
case V_309 :
V_663 =
( V_71 [ 2 ] +
V_10 -> V_310 / 2 ) / V_10 -> V_310 ;
break;
case V_311 :
V_663 = V_71 [ 2 ] / V_10 -> V_310 ;
break;
case V_312 :
V_663 =
( V_71 [ 2 ] + V_10 -> V_310 -
1 ) / V_10 -> V_310 ;
break;
default:
return - V_392 ;
break;
}
switch ( V_71 [ 3 ] ) {
case V_309 :
V_664 =
( V_71 [ 4 ] +
V_10 -> V_310 / 2 ) / V_10 -> V_310 ;
break;
case V_311 :
V_664 = V_71 [ 4 ] / V_10 -> V_310 ;
break;
case V_312 :
V_664 =
( V_71 [ 4 ] + V_10 -> V_310 -
1 ) / V_10 -> V_310 ;
break;
default:
return - V_392 ;
break;
}
if ( V_663 * V_10 -> V_310 != V_71 [ 2 ] ||
V_664 * V_10 -> V_310 != V_71 [ 4 ] ) {
V_71 [ 2 ] = V_663 * V_10 -> V_310 ;
V_71 [ 4 ] = V_664 * V_10 -> V_310 ;
return - V_407 ;
}
F_33 ( F_205 ( V_663 ) |
F_206 ( V_664 ) ,
V_666 ) ;
V_10 -> V_661 = V_663 ;
V_10 -> V_662 = V_664 ;
return 5 ;
break;
case V_667 :
return F_203 ( V_5 , V_71 ) ;
break;
default:
return - V_392 ;
break;
}
return 0 ;
}
static int F_207 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 , unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned V_663 , V_664 ;
switch ( V_71 [ 0 ] ) {
case V_665 :
switch ( V_71 [ 1 ] ) {
case V_309 :
V_663 =
( V_71 [ 2 ] +
V_10 -> V_310 / 2 ) / V_10 -> V_310 ;
break;
case V_311 :
V_663 = V_71 [ 2 ] / V_10 -> V_310 ;
break;
case V_312 :
V_663 =
( V_71 [ 2 ] + V_10 -> V_310 -
1 ) / V_10 -> V_310 ;
break;
default:
return - V_392 ;
break;
}
switch ( V_71 [ 3 ] ) {
case V_309 :
V_664 =
( V_71 [ 4 ] +
V_10 -> V_310 / 2 ) / V_10 -> V_310 ;
break;
case V_311 :
V_664 = V_71 [ 4 ] / V_10 -> V_310 ;
break;
case V_312 :
V_664 =
( V_71 [ 4 ] + V_10 -> V_310 -
1 ) / V_10 -> V_310 ;
break;
default:
return - V_392 ;
break;
}
if ( V_663 * V_10 -> V_310 != V_71 [ 2 ] ||
V_664 * V_10 -> V_310 != V_71 [ 4 ] ) {
V_71 [ 2 ] = V_663 * V_10 -> V_310 ;
V_71 [ 4 ] = V_664 * V_10 -> V_310 ;
return - V_407 ;
}
F_33 ( V_663 , V_668 ) ;
V_10 -> V_661 = V_663 ;
F_33 ( V_664 , V_669 ) ;
V_10 -> V_662 = V_664 ;
return 5 ;
break;
case V_667 :
return F_203 ( V_5 , V_71 ) ;
default:
return - V_392 ;
break;
}
return 0 ;
}
static int F_208 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 , unsigned int * V_71 )
{
F_209 ( V_5 , F_111 ( V_247 -> V_251 ) , V_71 [ 0 ] ) ;
return 1 ;
}
static int F_210 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 , unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_71 [ 0 ] = V_10 -> V_670 [ F_111 ( V_247 -> V_251 ) ] ;
return 1 ;
}
static void F_211 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_106 , V_671 ;
int V_672 ;
int V_410 = 0 ;
int V_673 ;
int V_674 = 0 ;
int type ;
int V_172 ;
type = V_59 -> V_675 [ 0 ] ;
if ( type == V_676 )
return;
V_673 = V_670 [ type ] . V_673 ;
for ( V_106 = 0 ; V_106 < 3 ; V_106 ++ ) {
type = V_59 -> V_675 [ V_106 ] ;
if ( type == V_676 )
break;
if ( V_670 [ type ] . V_673 != V_673 )
V_674 = 1 ;
V_410 += V_670 [ type ] . V_410 ;
}
V_672 = V_106 ;
V_100 -> V_257 = V_410 ;
if ( V_674 ) {
unsigned int * V_677 ;
if ( V_410 > V_678 ) {
F_6 ( L_53 ) ;
}
V_100 -> V_677 = V_677 = V_10 -> V_679 ;
V_172 = 0 ;
for ( V_106 = 0 ; V_106 < V_672 ; V_106 ++ ) {
type = V_59 -> V_675 [ V_106 ] ;
for ( V_671 = 0 ; V_671 < V_670 [ type ] . V_410 ; V_671 ++ ) {
V_677 [ V_172 ] =
( 1 << V_670 [ type ] . V_673 ) - 1 ;
V_172 ++ ;
}
}
for ( V_172 = 0 ; V_172 < V_100 -> V_257 ; V_172 ++ )
F_209 ( V_5 , V_106 , V_100 -> V_677 [ V_106 ] / 2 ) ;
} else {
type = V_59 -> V_675 [ 0 ] ;
V_100 -> V_680 = ( 1 << V_670 [ type ] . V_673 ) - 1 ;
for ( V_172 = 0 ; V_172 < V_100 -> V_257 ; V_172 ++ )
F_209 ( V_5 , V_106 , V_100 -> V_680 / 2 ) ;
}
}
static void F_209 ( struct V_4 * V_5 , int V_74 , int V_681 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_682 = 0 , V_72 = 0 , V_656 , V_657 = 0 ;
int V_106 ;
int type ;
if ( V_10 -> V_670 [ V_74 ] == V_681 )
return;
V_10 -> V_670 [ V_74 ] = V_681 ;
for ( V_106 = 0 ; V_106 < 3 ; V_106 ++ ) {
type = V_59 -> V_675 [ V_106 ] ;
if ( type == V_676 )
break;
if ( V_74 < V_670 [ type ] . V_410 ) {
V_72 = V_670 [ type ] . F_212 ( V_74 , V_681 , & V_657 ) ;
V_682 = F_213 ( V_106 ) ;
break;
}
V_74 -= V_670 [ type ] . V_410 ;
}
for ( V_656 = 1 << ( V_72 - 1 ) ; V_656 ; V_656 >>= 1 ) {
F_5 ( ( ( V_656 & V_657 ) ? 0x02 : 0 ) , V_658 ) ;
F_60 ( 1 ) ;
F_5 ( 1 | ( ( V_656 & V_657 ) ? 0x02 : 0 ) , V_658 ) ;
F_60 ( 1 ) ;
}
F_5 ( V_682 , V_658 ) ;
F_60 ( 1 ) ;
F_5 ( 0 , V_658 ) ;
}
static int F_214 ( int V_74 , int V_681 , int * V_657 )
{
V_74 ++ ;
* V_657 = ( ( V_74 & 0x1 ) << 11 ) |
( ( V_74 & 0x2 ) << 9 ) |
( ( V_74 & 0x4 ) << 7 ) | ( ( V_74 & 0x8 ) << 5 ) | ( V_681 & 0xff ) ;
return 12 ;
}
static int F_215 ( int V_74 , int V_681 , int * V_657 )
{
* V_657 = ( ( V_74 & 0x7 ) << 8 ) | ( V_681 & 0xff ) ;
return 11 ;
}
static int F_216 ( int V_74 , int V_681 , int * V_657 )
{
* V_657 = V_681 & 0xfff ;
return 12 ;
}
static int F_217 ( int V_74 , int V_681 , int * V_657 )
{
* V_657 = ( V_681 & 0xfff ) | ( V_74 ? 0xc000 : 0xa000 ) ;
return 16 ;
}
static int F_218 ( int V_74 , int V_681 , int * V_657 )
{
* V_657 = ( ( V_74 & 0xf ) << 8 ) | ( V_681 & 0xff ) ;
return 12 ;
}
static int F_219 ( int V_74 , int V_681 , int * V_657 )
{
* V_657 = ( ( V_74 + 1 ) << 8 ) | ( V_681 & 0xff ) ;
return 12 ;
}
static int F_220 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 , unsigned int * V_71 )
{
struct V_608 * V_609 = V_100 -> V_11 ;
return F_221 ( V_609 , V_247 , V_71 ) ;
}
static int F_222 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 , unsigned int * V_71 )
{
struct V_608 * V_609 = V_100 -> V_11 ;
return F_223 ( V_609 , V_247 , V_71 ) ;
}
static int F_224 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 , unsigned int * V_71 )
{
struct V_608 * V_609 = V_100 -> V_11 ;
return F_225 ( V_609 , V_247 , V_71 ) ;
}
static int F_226 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
int V_194 ;
struct V_608 * V_609 = V_100 -> V_11 ;
V_194 = F_21 ( V_5 , V_609 -> V_1 ,
V_44 ) ;
if ( V_194 ) {
F_19 ( V_5 ,
L_54 ) ;
return V_194 ;
}
F_227 ( V_609 , NULL , NULL , NULL , NULL ) ;
F_30 ( V_5 , V_609 -> V_1 , 1 ) ;
V_194 = F_228 ( V_609 , V_100 -> V_103 ) ;
return V_194 ;
}
static int F_229 ( struct V_4 * V_5 ,
struct V_99 * V_100 , struct V_170 * V_171 )
{
struct V_608 * V_609 = V_100 -> V_11 ;
return F_230 ( V_609 , V_171 ) ;
return - V_683 ;
}
static int F_70 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
#ifdef F_24
struct V_608 * V_609 = V_100 -> V_11 ;
int V_194 ;
V_194 = F_231 ( V_609 ) ;
F_30 ( V_5 , V_609 -> V_1 , 0 ) ;
F_28 ( V_5 , V_609 -> V_1 ) ;
return V_194 ;
#else
return 0 ;
#endif
}
static int F_232 ( struct V_4 * V_5 , unsigned V_172 ,
unsigned V_684 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned V_685 ;
unsigned V_686 ;
if ( ( V_684 & 0x1f ) != V_684 )
return - V_392 ;
V_685 = 1 + V_172 / 3 ;
V_686 = V_685 - 1 ;
V_10 -> V_687 [ V_686 ] &=
~ F_233 ( V_172 ) ;
V_10 -> V_687 [ V_686 ] |=
F_234 ( V_172 , V_684 ) ;
F_39 ( V_10 -> V_687 [ V_686 ] ,
F_235 ( V_685 ) ) ;
return 2 ;
}
static int F_236 ( struct V_4 * V_5 , unsigned V_172 ,
unsigned V_684 )
{
if ( V_684 != F_237 ( V_5 , V_172 ) )
return - V_392 ;
return 2 ;
}
static int F_238 ( struct V_4 * V_5 , unsigned V_172 ,
unsigned V_684 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
if ( V_59 -> V_60 & V_61 )
return F_232 ( V_5 , V_172 , V_684 ) ;
else
return F_236 ( V_5 , V_172 , V_684 ) ;
}
static unsigned F_239 ( struct V_4 * V_5 ,
unsigned V_172 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
const unsigned V_686 = V_172 / 3 ;
return F_240 ( V_172 ,
V_10 ->
V_687
[ V_686 ] ) ;
}
static unsigned F_237 ( struct V_4 * V_5 , unsigned V_172 )
{
switch ( V_172 ) {
case 0 :
return V_688 ;
break;
case 1 :
return V_689 ;
break;
case 2 :
return V_690 ;
break;
case 3 :
return V_691 ;
break;
case 4 :
return V_692 ;
break;
case 5 :
return V_693 ;
break;
case 6 :
return V_694 ;
break;
case 7 :
return V_695 ;
break;
case 8 :
return V_696 ;
break;
case 9 :
return V_697 ;
break;
default:
F_6 ( L_55 , V_25 ) ;
break;
}
return 0 ;
}
static unsigned F_241 ( struct V_4 * V_5 , unsigned V_172 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
if ( V_59 -> V_60 & V_61 )
return F_239 ( V_5 , V_172 ) ;
else
return F_237 ( V_5 , V_172 ) ;
}
static int F_242 ( struct V_4 * V_5 , unsigned V_698 ,
enum V_699 V_700 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 V_197 = V_5 -> V_11 ;
unsigned V_72 ;
if ( ( V_59 -> V_60 & V_61 ) == 0 ) {
return - V_683 ;
}
V_72 = F_34 ( V_701 ) ;
V_72 &= ~ F_243 ( V_698 ) ;
V_72 |= F_244 ( V_698 , V_700 ) ;
F_33 ( V_72 , V_701 ) ;
return 0 ;
}
static int F_245 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 , unsigned int * V_71 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 V_197 = V_5 -> V_11 ;
if ( ( V_59 -> V_60 & V_61 ) == 0 ) {
return - V_683 ;
}
if ( V_71 [ 0 ] ) {
V_100 -> V_517 &= ~ V_71 [ 0 ] ;
V_100 -> V_517 |= ( V_71 [ 0 ] & V_71 [ 1 ] ) ;
F_39 ( V_100 -> V_517 , V_702 ) ;
}
V_71 [ 1 ] = F_42 ( V_703 ) ;
return V_247 -> V_168 ;
}
static int F_246 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 , unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_172 ;
if ( V_247 -> V_168 < 1 )
return - V_392 ;
V_172 = F_111 ( V_247 -> V_251 ) ;
switch ( V_71 [ 0 ] ) {
case V_47 :
F_43 ( V_5 , V_19 , 1 << V_172 , 1 ) ;
break;
case V_44 :
F_43 ( V_5 , V_19 , 1 << V_172 , 0 ) ;
break;
case V_510 :
V_71 [ 1 ] =
( V_10 -> V_20 & ( 1 << V_172 ) ) ?
V_47 : V_44 ;
return 0 ;
break;
case V_704 :
return F_238 ( V_5 , V_172 , V_71 [ 1 ] ) ;
break;
case V_705 :
V_71 [ 1 ] = F_241 ( V_5 , V_172 ) ;
break;
case V_706 :
return F_242 ( V_5 , V_172 , V_71 [ 1 ] ) ;
break;
default:
return - V_392 ;
}
return 0 ;
}
static void F_247 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
V_10 -> V_707 = V_708 ;
if ( F_248 ( V_5 , V_709 , 0 ) < 0 ) {
F_6 ( L_56 ) ;
}
V_10 -> V_710 =
F_249 ( 0 ,
V_711 ) |
F_249 ( 1 ,
V_712 ) |
F_249 ( 2 ,
V_713 ) |
F_249 ( 3 , V_714 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_710 ,
V_715 ) ;
V_10 -> V_716 =
F_249 ( 4 ,
V_717 ) |
F_249 ( 5 ,
V_718 ) |
F_249 ( 6 , V_719 ) ;
if ( V_59 -> V_60 & V_61 )
V_10 -> V_716 |=
F_249 ( 7 , V_720 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_716 ,
V_721 ) ;
}
static int F_250 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 , unsigned int * V_71 )
{
V_71 [ 1 ] = 0 ;
return V_247 -> V_168 ;
}
static int F_251 ( unsigned V_722 ,
unsigned * V_723 ,
unsigned * V_724 ,
unsigned * V_725 )
{
unsigned div ;
unsigned V_726 = 1 ;
static const unsigned V_727 = 0x10 ;
unsigned V_728 ;
unsigned V_729 = 1 ;
static const unsigned V_730 = 0x100 ;
static const unsigned V_731 = 1000 ;
const unsigned V_732 = V_722 * V_731 ;
static const unsigned V_733 = 12500 ;
static const unsigned V_734 = 4 ;
int V_735 = 0 ;
for ( div = 1 ; div <= V_727 ; ++ div ) {
for ( V_728 = 1 ; V_728 <= V_730 ; ++ V_728 ) {
unsigned V_736 =
( V_732 * div ) / V_728 ;
if ( abs ( V_736 - V_733 ) <
abs ( V_735 - V_733 ) ) {
V_735 = V_736 ;
V_726 = div ;
V_729 = V_728 ;
}
}
}
if ( V_735 == 0 ) {
F_6 ( L_57 , V_25 ) ;
return - V_208 ;
}
* V_723 = V_726 ;
* V_724 = V_729 ;
* V_725 =
( V_735 * V_734 +
( V_731 / 2 ) ) / V_731 ;
return 0 ;
}
static inline unsigned F_252 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
if ( V_59 -> V_60 & V_61 )
return 8 ;
else
return 7 ;
}
static int F_253 ( struct V_4 * V_5 ,
unsigned V_684 , unsigned V_737 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
static const unsigned V_738 = 50 ;
static const unsigned V_739 = 1000 ;
static const unsigned V_105 = 1000 ;
unsigned V_740 ;
unsigned V_723 ;
unsigned V_724 ;
unsigned V_106 ;
int V_194 ;
if ( V_684 == V_741 )
V_737 = 100 ;
if ( V_737 < V_738 || V_737 > V_739 ) {
F_6
( L_58
L_59 , V_25 ,
V_738 , V_739 ) ;
return - V_392 ;
}
V_10 -> V_742 &= ~ V_743 ;
V_10 -> V_16 ( V_5 , V_10 -> V_742 ,
V_744 ) ;
V_740 =
V_745 | V_746 ;
V_10 -> V_707 |=
V_747 | V_748 ;
V_10 -> V_707 &= ~ V_749 ;
switch ( V_684 ) {
case V_750 :
V_10 -> V_707 |=
V_751 ;
V_194 = F_251 ( V_737 , & V_723 ,
& V_724 ,
& V_10 -> V_310 ) ;
if ( V_194 < 0 )
return V_194 ;
break;
case V_741 :
V_10 -> V_707 |=
V_752 ;
V_194 = F_251 ( V_737 , & V_723 ,
& V_724 ,
& V_10 -> V_310 ) ;
if ( V_194 < 0 )
return V_194 ;
break;
default:
{
unsigned V_753 ;
static const unsigned V_754 = 7 ;
for ( V_753 = 0 ; V_753 <= V_754 ;
++ V_753 ) {
if ( V_684 ==
F_254 ( V_753 ) ) {
V_10 -> V_707 |=
F_255
( V_753 ) ;
break;
}
}
if ( V_753 > V_754 )
return - V_392 ;
V_194 = F_251 ( V_737 ,
& V_723 ,
& V_724 ,
& V_10 ->
V_310 ) ;
if ( V_194 < 0 )
return V_194 ;
}
break;
}
F_39 ( V_10 -> V_707 , V_755 ) ;
V_740 |=
F_256 ( V_723 ) |
F_257 ( V_724 ) ;
F_39 ( V_740 , V_756 ) ;
V_10 -> V_642 = V_684 ;
for ( V_106 = 0 ; V_106 < V_105 ; ++ V_106 ) {
if ( F_42 ( V_757 ) & V_758 ) {
break;
}
F_60 ( 1 ) ;
}
if ( V_106 == V_105 ) {
F_6
( L_60 ,
V_25 , V_684 , V_737 ) ;
return - V_759 ;
}
return 3 ;
}
static int F_248 ( struct V_4 * V_5 , unsigned V_684 ,
unsigned V_737 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_684 == V_709 ) {
V_10 -> V_742 &= ~ V_743 ;
V_10 -> V_16 ( V_5 , V_10 -> V_742 ,
V_744 ) ;
V_10 -> V_310 = V_648 ;
if ( V_59 -> V_60 & V_61 ) {
V_10 -> V_707 &=
~ ( V_747 |
V_748 ) ;
F_39 ( V_10 -> V_707 ,
V_755 ) ;
F_39 ( 0 , V_756 ) ;
}
V_10 -> V_642 = V_684 ;
} else {
if ( V_59 -> V_60 & V_61 ) {
return F_253 ( V_5 , V_684 ,
V_737 ) ;
} else {
if ( V_684 == V_760 ) {
V_10 -> V_742 |=
V_743 ;
V_10 -> V_16 ( V_5 ,
V_10 ->
V_742 ,
V_744 ) ;
if ( V_737 == 0 ) {
F_6
( L_61 ,
V_25 ) ;
return - V_392 ;
} else {
V_10 -> V_310 = V_737 ;
}
V_10 -> V_642 = V_684 ;
} else
return - V_392 ;
}
}
return 3 ;
}
static int F_258 ( struct V_4 * V_5 , unsigned V_172 ,
unsigned V_684 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
if ( V_172 >= F_252 ( V_5 ) ) {
if ( V_172 == V_761 ) {
if ( V_684 == V_720 )
return 1 ;
else {
F_6
( L_62 ,
V_25 , V_172 , V_761 ) ;
return 0 ;
}
}
return 0 ;
}
switch ( V_684 ) {
case V_711 :
case V_712 :
case V_713 :
case V_714 :
case V_717 :
case V_718 :
case V_719 :
case V_762 :
case V_763 :
return 1 ;
break;
case V_720 :
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
static int F_259 ( struct V_4 * V_5 , unsigned V_172 ,
unsigned V_684 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( F_258 ( V_5 , V_172 , V_684 ) == 0 )
return - V_392 ;
if ( V_172 < 4 ) {
V_10 -> V_710 &= ~ F_260 ( V_172 ) ;
V_10 -> V_710 |=
F_249 ( V_172 , V_684 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_710 ,
V_715 ) ;
} else if ( V_172 < 8 ) {
V_10 -> V_716 &= ~ F_260 ( V_172 ) ;
V_10 -> V_716 |=
F_249 ( V_172 , V_684 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_716 ,
V_721 ) ;
}
return 2 ;
}
static unsigned F_261 ( struct V_4 * V_5 , unsigned V_172 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_172 < 4 ) {
return F_262 ( V_172 ,
V_10 -> V_710 ) ;
} else if ( V_172 < F_252 ( V_5 ) ) {
return F_262 ( V_172 ,
V_10 -> V_716 ) ;
} else {
if ( V_172 == V_761 )
return V_720 ;
F_6 ( L_63 , V_25 ) ;
return 0 ;
}
}
static int F_263 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 , unsigned int * V_71 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_172 = F_111 ( V_247 -> V_251 ) ;
switch ( V_71 [ 0 ] ) {
case V_507 :
if ( V_172 < F_252 ( V_5 ) ) {
V_10 -> V_742 |=
F_264 ( V_172 ,
( V_59 -> V_60 & V_61 ) != 0 ) ;
} else if ( V_172 == V_761 ) {
V_10 -> V_742 |=
V_764 ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_742 ,
V_744 ) ;
break;
case V_509 :
if ( V_172 < F_252 ( V_5 ) ) {
V_10 -> V_742 &=
~ F_264 ( V_172 ,
( V_59 -> V_60 & V_61 ) != 0 ) ;
} else if ( V_172 == V_761 ) {
V_10 -> V_742 &=
~ V_764 ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_742 ,
V_744 ) ;
break;
case V_510 :
if ( V_172 < F_252 ( V_5 ) ) {
V_71 [ 1 ] =
( V_10 -> V_742 &
F_264 ( V_172 ,
( V_59 -> V_60 & V_61 ) != 0 ) )
? V_507
: V_509 ;
} else if ( V_172 == V_761 ) {
V_71 [ 1 ] =
( V_10 -> V_742 &
V_764 )
? V_507 : V_509 ;
}
return 2 ;
break;
case V_649 :
return F_248 ( V_5 , V_71 [ 1 ] , V_71 [ 2 ] ) ;
break;
case V_650 :
V_71 [ 1 ] = V_10 -> V_642 ;
V_71 [ 2 ] = V_10 -> V_310 ;
return 3 ;
break;
case V_704 :
return F_259 ( V_5 , V_172 , V_71 [ 1 ] ) ;
break;
case V_705 :
V_71 [ 1 ] = F_261 ( V_5 , V_172 ) ;
return 2 ;
break;
default:
return - V_392 ;
break;
}
return 1 ;
}
static int F_265 ( struct V_4 * V_5 )
{
unsigned short V_130 ;
const int V_105 = V_765 ;
int V_106 ;
for ( V_106 = 0 ; V_106 < V_105 ; V_106 ++ ) {
V_130 = F_41 ( V_5 , V_766 ) ;
if ( ( V_130 & V_767 ) == 0 ) {
break;
}
F_266 ( V_768 ) ;
if ( F_267 ( 1 ) ) {
return - V_208 ;
}
}
if ( V_106 == V_105 ) {
F_6 ( L_64 , __FILE__ , V_25 ) ;
return - V_255 ;
}
return 0 ;
}
static void F_268 ( struct V_4 * V_5 , unsigned short V_78 )
{
static const int V_105 = 100 ;
int V_106 ;
F_38 ( V_5 , V_78 , V_769 ) ;
for ( V_106 = 0 ; V_106 < V_105 ; V_106 ++ ) {
if ( ( F_41 ( V_5 , V_766 ) & V_767 ) )
break;
F_60 ( 1 ) ;
}
if ( V_106 == V_105 ) {
F_19 ( V_5 , L_65 ) ;
}
}
static void F_269 ( struct V_4 * V_5 , unsigned int V_78 ,
unsigned int V_770 )
{
F_38 ( V_5 , ( ( V_78 >> 16 ) & 0xff ) ,
V_771 ) ;
F_38 ( V_5 , ( V_78 & 0xffff ) ,
V_772 ) ;
V_770 &= V_773 ;
F_268 ( V_5 , V_774 | V_770 ) ;
if ( F_265 ( V_5 ) )
F_19 ( V_5 , L_66 ) ;
}
static unsigned int F_270 ( struct V_4 * V_5 ,
unsigned int V_770 )
{
unsigned int V_78 ;
V_770 &= V_773 ;
F_268 ( V_5 , V_774 | V_775 | V_770 ) ;
if ( F_265 ( V_5 ) )
F_19 ( V_5 , L_67 ) ;
V_78 = ( F_41 ( V_5 ,
V_771 ) << 16 ) &
0xff0000 ;
V_78 |= F_41 ( V_5 , V_772 ) & 0xffff ;
return V_78 ;
}
static int F_271 ( struct V_4 * V_5 , unsigned short * V_71 )
{
int V_194 ;
unsigned short V_130 ;
F_268 ( V_5 , V_774 | V_776 ) ;
V_194 = F_265 ( V_5 ) ;
if ( V_194 ) {
F_19 ( V_5 ,
L_68 ) ;
return - V_255 ;
}
V_130 = F_41 ( V_5 , V_766 ) ;
if ( V_130 & V_777 ) {
F_6
( L_69 ) ;
return - V_208 ;
}
if ( V_130 & V_778 ) {
F_6
( L_70 ) ;
}
if ( V_71 ) {
* V_71 = F_41 ( V_5 , V_779 ) ;
* V_71 ^= ( 1 << 15 ) ;
}
return 0 ;
}
static int F_272 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_246 * V_247 , unsigned int * V_71 )
{
int V_168 , V_194 ;
unsigned short V_780 ;
unsigned int V_781 ;
const unsigned int V_782 = 0x1000 ;
if ( V_247 -> V_251 & V_264 )
V_781 = V_782 ;
else
V_781 = F_111 ( V_247 -> V_251 ) ;
F_38 ( V_5 , V_781 , V_783 ) ;
for ( V_168 = 0 ; V_168 < V_247 -> V_168 ; V_168 ++ ) {
V_194 = F_271 ( V_5 , & V_780 ) ;
if ( V_194 < 0 )
return V_194 ;
V_71 [ V_168 ] = V_780 ;
}
return V_247 -> V_168 ;
}
static int F_273 ( struct V_4 * V_5 )
{
unsigned int V_278 =
V_784 | V_785 ;
#if 1
F_269 ( V_5 , V_278 | V_786 ,
V_787 ) ;
F_271 ( V_5 , NULL ) ;
#else
F_269 ( V_5 , 0x400000 , V_788 ) ;
F_269 ( V_5 , V_278 | V_789 ,
V_787 ) ;
if ( F_265 ( V_5 ) )
F_19 ( V_5 , L_71 ) ;
#endif
#ifdef F_274
F_6 ( L_72 , F_270 ( V_5 ,
V_787 ) ) ;
F_6 ( L_73 , F_270 ( V_5 , V_788 ) ) ;
F_6 ( L_74 , F_270 ( V_5 ,
V_790 ) ) ;
#endif
return 0 ;
}

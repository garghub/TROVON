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
if ( V_10 -> V_45 )
F_58 ( V_10 -> V_45 , V_100 -> V_103 ) ;
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
if ( ( V_10 -> V_113 & V_114 ) )
F_63 ( V_5 ) ;
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
if ( V_81 & V_121 )
V_120 |= V_122 ;
if ( V_81 & V_123 )
V_120 |= V_124 ;
if ( V_81 & V_125 )
V_120 |= V_126 ;
if ( V_81 & V_127 )
V_120 |= V_128 ;
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
#ifdef F_24
if ( V_83 & V_92 )
F_55 ( V_5 ) ;
if ( V_83 & ~ ( V_96 | V_92 | V_132 | V_133 |
V_134 | V_135 | V_136 | V_137 |
V_138 | V_139 | V_140 ) ) {
F_6
( L_8 ,
V_83 ) ;
V_100 -> V_103 -> V_111 |= V_116 | V_115 ;
}
#endif
if ( V_130 & ( V_141 | V_142 | V_143 |
V_121 | V_123 ) ) {
if ( V_130 == 0xffff ) {
F_6
( L_9 ) ;
if ( F_74 ( V_100 ) ) {
V_100 -> V_103 -> V_111 |=
V_116 | V_115 ;
F_67 ( V_5 , V_100 ) ;
}
return;
}
if ( V_130 & ( V_141 | V_142 |
V_143 ) ) {
F_6 ( L_10 ,
V_130 ) ;
F_63 ( V_5 ) ;
V_100 -> V_103 -> V_111 |= V_116 ;
if ( V_130 & ( V_141 | V_142 ) )
V_100 -> V_103 -> V_111 |= V_117 ;
F_67 ( V_5 , V_100 ) ;
return;
}
if ( V_130 & V_121 ) {
if ( ! V_10 -> V_144 )
F_63 ( V_5 ) ;
}
}
#ifndef F_24
if ( V_130 & V_145 ) {
int V_106 ;
static const int V_105 = 10 ;
for ( V_106 = 0 ; V_106 < V_105 ; ++ V_106 ) {
F_75 ( V_5 ) ;
if ( ( V_10 -> V_73 ( V_5 ,
V_89 ) &
V_145 ) == 0 )
break;
}
}
#endif
if ( ( V_130 & V_127 ) )
F_61 ( V_5 , V_100 ) ;
F_67 ( V_5 , V_100 ) ;
}
static void F_50 ( struct V_4 * V_5 , unsigned short V_82 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned short V_120 = 0 ;
if ( V_82 & V_146 )
V_120 |= V_147 ;
if ( V_82 & V_148 )
V_120 |= V_149 ;
if ( V_82 & V_150 )
V_120 |= V_151 ;
if ( V_82 & V_152 )
V_120 |= V_153 ;
if ( V_82 & V_154 )
V_120 |= V_155 ;
if ( V_82 & V_156 )
V_120 |= V_157 ;
if ( V_82 & V_158 )
V_120 |= V_159 ;
if ( V_120 )
V_10 -> V_16 ( V_5 , V_120 , V_160 ) ;
}
static void F_52 ( struct V_4 * V_5 ,
unsigned short V_82 , unsigned V_84 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_99 * V_100 = & V_5 -> V_101 [ V_104 ] ;
#ifdef F_24
if ( V_84 & V_92 )
F_57 ( V_10 -> V_40 , V_5 ) ;
if ( V_84 & ~ ( V_96 | V_92 | V_132 | V_133 |
V_134 | V_135 | V_136 | V_137 |
V_138 | V_139 | V_140 ) ) {
F_6
( L_11 ,
V_84 ) ;
V_100 -> V_103 -> V_111 |= V_115 | V_116 ;
}
#endif
if ( V_82 == 0xffff )
return;
if ( V_82 & V_148 ) {
F_6
( L_12 ,
V_82 , V_10 -> V_73 ( V_5 , V_161 ) ) ;
V_100 -> V_103 -> V_111 |= V_117 ;
}
if ( V_82 & V_146 )
V_100 -> V_103 -> V_111 |= V_115 ;
#ifndef F_24
if ( V_82 & V_162 ) {
int V_163 ;
V_163 = F_76 ( V_5 , V_100 ) ;
if ( ! V_163 ) {
F_6 ( L_13 ) ;
F_43 ( V_5 , V_17 ,
V_164 |
V_165 , 0 ) ;
V_100 -> V_103 -> V_111 |= V_117 ;
}
}
#endif
F_67 ( V_5 , V_100 ) ;
}
static void F_77 ( struct V_4 * V_5 ,
struct V_99 * V_100 , int V_166 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_167 * V_103 = V_100 -> V_103 ;
struct V_168 * V_169 = & V_103 -> V_169 ;
int V_170 ;
int V_106 ;
unsigned short V_80 ;
T_4 V_171 ;
int V_172 ;
int V_173 = 1 ;
V_170 = V_103 -> V_174 ;
for ( V_106 = 0 ; V_106 < V_166 ; V_106 ++ ) {
V_173 &= F_78 ( V_103 , & V_80 ) ;
if ( V_173 == 0 )
break;
V_172 = F_79 ( V_169 -> V_175 [ V_170 ] ) ;
if ( V_59 -> V_60 & V_176 ) {
V_171 = V_80 & 0xffff ;
if ( V_59 -> V_60 != V_177 ) {
V_173 &= F_78 ( V_103 , & V_80 ) ;
if ( V_173 == 0 )
break;
V_170 ++ ;
V_106 ++ ;
V_171 |= ( V_80 << 16 ) & 0xffff0000 ;
}
F_33 ( V_171 , V_178 ) ;
} else {
F_39 ( V_80 , V_179 ) ;
}
V_170 ++ ;
V_170 %= V_169 -> V_180 ;
}
V_103 -> V_174 = V_170 ;
if ( V_173 == 0 )
V_103 -> V_111 |= V_117 ;
}
static int F_76 ( struct V_4 * V_5 ,
struct V_99 * V_100 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
int V_166 ;
V_166 = F_80 ( V_100 -> V_103 ) ;
if ( V_166 == 0 ) {
V_100 -> V_103 -> V_111 |= V_117 ;
return 0 ;
}
V_166 /= sizeof( short ) ;
if ( V_166 > V_59 -> V_181 / 2 )
V_166 = V_59 -> V_181 / 2 ;
F_77 ( V_5 , V_100 , V_166 ) ;
V_100 -> V_103 -> V_111 |= V_182 ;
return 1 ;
}
static int F_81 ( struct V_4 * V_5 ,
struct V_99 * V_100 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_166 ;
V_10 -> V_16 ( V_5 , 1 , V_183 ) ;
if ( V_59 -> V_60 & V_176 )
F_40 ( V_5 , 0x6 , V_184 ) ;
V_166 = F_80 ( V_100 -> V_103 ) ;
if ( V_166 == 0 )
return 0 ;
V_166 /= sizeof( short ) ;
if ( V_166 > V_59 -> V_181 )
V_166 = V_59 -> V_181 ;
F_77 ( V_5 , V_100 , V_166 ) ;
return V_166 ;
}
static void F_82 ( struct V_4 * V_5 ,
struct V_99 * V_100 , int V_166 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_167 * V_103 = V_100 -> V_103 ;
int V_106 ;
if ( V_59 -> V_60 == V_185 ) {
unsigned short V_71 [ 2 ] ;
T_4 V_186 ;
for ( V_106 = 0 ; V_106 < V_166 / 2 ; V_106 ++ ) {
V_186 = F_34 ( V_187 ) ;
V_71 [ 0 ] = ( V_186 >> 16 ) & 0xffff ;
V_71 [ 1 ] = V_186 & 0xffff ;
F_83 ( V_100 , V_71 , sizeof( V_71 ) ) ;
}
if ( V_166 % 2 ) {
V_186 = F_34 ( V_187 ) ;
V_71 [ 0 ] = V_186 & 0xffff ;
F_84 ( V_100 , V_71 [ 0 ] ) ;
}
} else if ( V_59 -> V_60 == V_66 ) {
unsigned short V_71 [ 2 ] ;
T_4 V_186 ;
for ( V_106 = 0 ; V_106 < V_166 / 2 ; V_106 ++ ) {
V_186 = F_34 ( V_188 ) ;
V_71 [ 0 ] = ( V_186 >> 16 ) & 0xffff ;
V_71 [ 1 ] = V_186 & 0xffff ;
F_83 ( V_100 , V_71 , sizeof( V_71 ) ) ;
}
if ( V_166 % 2 ) {
F_33 ( 0x01 , V_67 ) ;
V_186 = F_34 ( V_188 ) ;
V_71 [ 0 ] = ( V_186 >> 16 ) & 0xffff ;
F_84 ( V_100 , V_71 [ 0 ] ) ;
}
} else {
if ( V_166 > sizeof( V_10 -> V_189 ) /
sizeof( V_10 -> V_189 [ 0 ] ) ) {
F_19 ( V_5 , L_14 ) ;
V_103 -> V_111 |= V_116 ;
return;
}
for ( V_106 = 0 ; V_106 < V_166 ; V_106 ++ ) {
V_10 -> V_189 [ V_106 ] =
F_42 ( V_190 ) ;
}
F_83 ( V_100 , V_10 -> V_189 ,
V_166 *
sizeof( V_10 -> V_189 [ 0 ] ) ) ;
}
}
static void F_75 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_99 * V_100 = & V_5 -> V_101 [ V_102 ] ;
int V_166 ;
V_166 = V_59 -> V_191 / 2 ;
F_82 ( V_5 , V_100 , V_166 ) ;
}
static int F_64 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_106 ;
static const int V_105 = 10000 ;
unsigned long V_12 ;
int V_192 = 0 ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_39 ) {
for ( V_106 = 0 ; V_106 < V_105 ; V_106 ++ ) {
if ( ( V_10 -> V_73 ( V_5 ,
V_89 ) &
V_193 )
&& F_85 ( V_10 -> V_39 ) ==
0 )
break;
F_60 ( 5 ) ;
}
if ( V_106 == V_105 ) {
F_6 ( L_15 ) ;
F_6
( L_16 ,
F_85 ( V_10 -> V_39 ) ,
V_10 -> V_73 ( V_5 , V_89 ) ) ;
V_192 = - 1 ;
}
}
F_8 ( & V_10 -> V_38 , V_12 ) ;
F_55 ( V_5 ) ;
return V_192 ;
}
static void F_62 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_99 * V_100 = & V_5 -> V_101 [ V_102 ] ;
unsigned short V_71 [ 2 ] ;
T_4 V_186 ;
unsigned short V_194 ;
int V_106 ;
if ( V_59 -> V_60 == V_185 ) {
while ( ( V_10 -> V_73 ( V_5 ,
V_89 ) &
V_193 ) == 0 ) {
V_186 = F_34 ( V_187 ) ;
V_71 [ 0 ] = ( V_186 >> 16 ) ;
V_71 [ 1 ] = ( V_186 & 0xffff ) ;
F_83 ( V_100 , V_71 , sizeof( V_71 ) ) ;
}
} else if ( V_59 -> V_60 == V_66 ) {
V_106 = 0 ;
while ( F_34 ( V_68 ) & 0x04 ) {
V_186 = F_34 ( V_188 ) ;
V_71 [ 0 ] = ( V_186 >> 16 ) ;
V_71 [ 1 ] = ( V_186 & 0xffff ) ;
F_83 ( V_100 , V_71 , sizeof( V_71 ) ) ;
V_106 += 2 ;
}
if ( F_34 ( V_68 ) & 0x01 ) {
F_33 ( 0x01 , V_67 ) ;
V_186 = F_34 ( V_188 ) ;
V_71 [ 0 ] = ( V_186 >> 16 ) & 0xffff ;
F_84 ( V_100 , V_71 [ 0 ] ) ;
}
} else {
V_194 =
V_10 -> V_73 ( V_5 ,
V_89 ) & V_193 ;
while ( V_194 == 0 ) {
for ( V_106 = 0 ;
V_106 <
sizeof( V_10 -> V_189 ) /
sizeof( V_10 -> V_189 [ 0 ] ) ; V_106 ++ ) {
V_194 =
V_10 -> V_73 ( V_5 ,
V_89 ) &
V_193 ;
if ( V_194 )
break;
V_10 -> V_189 [ V_106 ] =
F_42 ( V_190 ) ;
}
F_83 ( V_100 , V_10 -> V_189 ,
V_106 *
sizeof( V_10 ->
V_189 [ 0 ] ) ) ;
}
}
}
static void F_65 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 V_195 = V_5 -> V_11 ;
struct V_99 * V_100 = & V_5 -> V_101 [ V_102 ] ;
unsigned short V_71 ;
T_4 V_186 ;
if ( V_59 -> V_60 != V_185 )
return;
if ( F_86 ( V_196 ) & 0x80 ) {
V_186 = F_34 ( V_187 ) ;
V_71 = ( V_186 & 0xffff ) ;
F_84 ( V_100 , V_71 ) ;
}
}
static void F_66 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 V_195 = V_5 -> V_11 ;
struct V_99 * V_100 = & V_5 -> V_101 [ V_102 ] ;
unsigned short V_71 ;
T_4 V_186 ;
if ( V_59 -> V_60 != V_66 )
return;
if ( F_34 ( V_68 ) & 0x01 ) {
F_33 ( 0x01 , V_67 ) ;
V_186 = F_34 ( V_188 ) ;
V_71 = ( V_186 >> 16 ) & 0xffff ;
F_84 ( V_100 , V_71 ) ;
}
}
static void F_87 ( struct V_4 * V_5 , struct V_99 * V_100 ,
void * V_71 , unsigned int V_197 ,
unsigned int V_198 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_167 * V_103 = V_100 -> V_103 ;
unsigned int V_106 ;
unsigned int V_199 = V_197 / F_88 ( V_100 ) ;
unsigned short * V_200 = V_71 ;
unsigned int * V_201 = V_71 ;
for ( V_106 = 0 ; V_106 < V_199 ; V_106 ++ ) {
#ifdef F_24
if ( V_100 -> V_202 & V_203 )
V_201 [ V_106 ] = F_89 ( V_201 [ V_106 ] ) ;
else
V_200 [ V_106 ] = F_90 ( V_200 [ V_106 ] ) ;
#endif
if ( V_100 -> V_202 & V_203 )
V_201 [ V_106 ] += V_10 -> V_204 [ V_198 ] ;
else
V_200 [ V_106 ] += V_10 -> V_204 [ V_198 ] ;
V_198 ++ ;
V_198 %= V_103 -> V_169 . V_180 ;
}
}
static int F_91 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_99 * V_100 = & V_5 -> V_101 [ V_102 ] ;
int V_192 ;
unsigned long V_12 ;
V_192 = F_16 ( V_5 ) ;
if ( V_192 )
return V_192 ;
F_92 ( V_100 -> V_103 , V_100 -> V_103 -> V_205 ) ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_39 == NULL ) {
F_8 ( & V_10 -> V_38 , V_12 ) ;
return - V_206 ;
}
switch ( V_59 -> V_60 ) {
case V_185 :
case V_66 :
F_93 ( V_10 -> V_39 , 32 , 16 ) ;
break;
case V_207 :
F_93 ( V_10 -> V_39 , 32 , 32 ) ;
break;
default:
F_93 ( V_10 -> V_39 , 16 , 16 ) ;
break;
}
F_94 ( V_10 -> V_39 ) ;
F_8 ( & V_10 -> V_38 , V_12 ) ;
return 0 ;
}
static int F_95 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_99 * V_100 = & V_5 -> V_101 [ V_104 ] ;
int V_192 ;
unsigned long V_12 ;
V_192 = F_20 ( V_5 ) ;
if ( V_192 )
return V_192 ;
F_96 ( V_100 -> V_103 , V_100 -> V_103 -> V_205 ) ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_45 ) {
if ( V_59 -> V_60 & ( V_185 | V_208 ) ) {
F_93 ( V_10 -> V_45 , 32 , 32 ) ;
} else {
F_93 ( V_10 -> V_45 , 16 , 32 ) ;
}
F_94 ( V_10 -> V_45 ) ;
} else
V_192 = - V_206 ;
F_8 ( & V_10 -> V_38 , V_12 ) ;
return V_192 ;
}
static int F_68 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
F_25 ( V_5 ) ;
V_10 -> V_16 ( V_5 , V_209 | V_210 ,
V_211 ) ;
F_43 ( V_5 , V_14 ,
V_212 | V_213 |
V_214 | V_215 |
V_216 | V_217 |
V_218 , 0 ) ;
F_32 ( V_5 ) ;
if ( V_59 -> V_60 != V_66 )
F_5 ( 0 , V_219 ) ;
V_10 -> V_16 ( V_5 , V_220 , V_221 ) ;
V_10 -> V_16 ( V_5 ,
V_222 | V_223
,
V_224 ) ;
V_10 -> V_16 ( V_5 , 0x0000 , V_225 ) ;
V_10 -> V_16 ( V_5 , ( 0 << 6 ) | 0x0000 , V_226 ) ;
if ( V_59 -> V_60 == V_185 ) {
V_10 -> V_16 ( V_5 , V_227 |
V_228 |
V_229 ,
V_230 ) ;
V_10 -> V_16 ( V_5 ,
F_97 ( 3 ) |
F_98 ( 0 ) |
F_99 ( 2 ) |
F_100 ( 3 ) |
F_101
( V_231 ) ,
V_232 ) ;
} else if ( V_59 -> V_60 == V_66 ) {
V_10 -> V_16 ( V_5 , V_227 |
V_228 |
V_229 ,
V_230 ) ;
V_10 -> V_16 ( V_5 ,
F_97 ( 3 ) |
F_98 ( 0 ) |
F_99 ( 2 ) |
F_100 ( 3 ) |
F_101
( V_233 ) ,
V_232 ) ;
} else {
unsigned V_234 ;
V_10 -> V_16 ( V_5 , V_227 |
V_228 |
V_235 |
V_229 ,
V_230 ) ;
V_234 =
F_97 ( 3 ) |
F_98 ( 0 ) |
F_99 ( 2 ) |
F_100 ( 3 ) ;
if ( V_59 -> V_60 == V_236 )
V_234 |=
F_101
( V_231 ) ;
else
V_234 |=
F_101
( V_233 ) ;
V_10 -> V_16 ( V_5 , V_234 ,
V_232 ) ;
}
V_10 -> V_16 ( V_5 , V_237 | V_126 | V_238 | V_124 | V_122 | V_239 | V_128 , V_129 ) ;
V_10 -> V_16 ( V_5 , V_240 , V_211 ) ;
return 0 ;
}
static int F_102 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
unsigned long V_12 ;
int V_241 ;
F_4 ( & V_5 -> V_88 , V_12 ) ;
#ifndef F_24
F_62 ( V_5 ) ;
#else
F_55 ( V_5 ) ;
#endif
V_241 = V_100 -> V_103 -> V_242 - V_100 -> V_103 -> V_243 ;
F_8 ( & V_5 -> V_88 , V_12 ) ;
return V_241 ;
}
static int F_103 ( struct V_4 * V_5 ,
struct V_99 * V_100 , struct V_244 * V_245 ,
unsigned int * V_71 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_106 , V_166 ;
const unsigned int V_246 = ( 1 << V_59 -> V_247 ) - 1 ;
unsigned V_248 ;
unsigned short V_80 ;
unsigned long V_186 ;
F_104 ( V_5 , 1 , & V_245 -> V_249 ) ;
F_32 ( V_5 ) ;
V_248 = V_10 -> V_204 [ 0 ] ;
if ( V_59 -> V_60 == V_185 ) {
for ( V_166 = 0 ; V_166 < V_250 ; V_166 ++ ) {
V_10 -> V_16 ( V_5 , V_251 ,
V_221 ) ;
F_60 ( 1 ) ;
}
for ( V_166 = 0 ; V_166 < V_245 -> V_166 ; V_166 ++ ) {
V_10 -> V_16 ( V_5 , V_251 ,
V_221 ) ;
V_80 = 0 ;
for ( V_106 = 0 ; V_106 < V_252 ; V_106 ++ ) {
if ( F_86 ( V_196 ) & 0x80 ) {
V_80 = ( F_34 ( V_187 ) >> 16 )
& 0xffff ;
break;
}
if ( ! ( V_10 -> V_73 ( V_5 ,
V_89 ) &
V_193 ) ) {
V_80 = F_34 ( V_187 ) &
0xffff ;
break;
}
}
if ( V_106 == V_252 ) {
F_6
( L_17 ) ;
return - V_253 ;
}
V_80 += V_248 ;
V_71 [ V_166 ] = V_80 ;
}
} else if ( V_59 -> V_60 == V_66 ) {
for ( V_166 = 0 ; V_166 < V_245 -> V_166 ; V_166 ++ ) {
V_10 -> V_16 ( V_5 , V_251 ,
V_221 ) ;
V_186 = 0 ;
for ( V_106 = 0 ; V_106 < V_252 ; V_106 ++ ) {
if ( F_34 ( V_68 ) & 0x01 ) {
F_33 ( 0x01 , V_67 ) ;
V_186 = F_34 ( V_188 ) ;
break;
}
}
if ( V_106 == V_252 ) {
F_6
( L_18 ) ;
return - V_253 ;
}
V_71 [ V_166 ] = ( ( ( V_186 >> 16 ) & 0xFFFF ) + V_248 ) & 0xFFFF ;
}
} else {
for ( V_166 = 0 ; V_166 < V_245 -> V_166 ; V_166 ++ ) {
V_10 -> V_16 ( V_5 , V_251 ,
V_221 ) ;
for ( V_106 = 0 ; V_106 < V_252 ; V_106 ++ ) {
if ( ! ( V_10 -> V_73 ( V_5 ,
V_89 ) &
V_193 ) )
break;
}
if ( V_106 == V_252 ) {
F_6
( L_19 ) ;
return - V_253 ;
}
if ( V_59 -> V_60 & V_61 ) {
V_71 [ V_166 ] =
F_34 ( V_254 ) & V_246 ;
} else {
V_80 = F_42 ( V_190 ) ;
V_80 += V_248 ;
V_71 [ V_166 ] = V_80 ;
}
}
}
return V_245 -> V_166 ;
}
static void F_105 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_106 ;
V_10 -> V_16 ( V_5 , V_251 , V_221 ) ;
for ( V_106 = 0 ; V_106 < V_252 ; ++ V_106 ) {
if ( ! ( V_10 -> V_73 ( V_5 ,
V_89 ) &
V_193 ) ) {
V_10 -> V_16 ( V_5 , 1 , V_69 ) ;
return;
}
F_60 ( 1 ) ;
}
F_6 ( L_20 ) ;
}
static void F_106 ( struct V_4 * V_5 ,
unsigned int V_255 ,
unsigned int * V_256 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_170 , V_172 , V_257 ;
unsigned int V_106 ;
unsigned V_258 ;
unsigned int V_259 ;
unsigned V_260 ;
V_10 -> V_16 ( V_5 , 1 , V_261 ) ;
if ( ( V_256 [ 0 ] & V_262 ) ) {
unsigned V_263 ;
V_170 = F_107 ( V_256 [ 0 ] ) ;
V_172 = F_79 ( V_256 [ 0 ] ) ;
V_260 = V_264 [ V_59 -> V_265 ] [ V_172 ] ;
V_259 = ( ( V_256 [ 0 ] & V_266 ) != 0 ) ;
V_263 = V_267 ;
V_263 |= V_170 ;
V_263 |=
( V_10 -> V_268 ) &
( V_269 |
V_270 |
V_271 |
V_272 ) ;
V_263 |= F_108 ( V_260 ) ;
if ( V_259 )
V_263 |= V_273 ;
V_263 |= V_274 ;
F_33 ( V_263 , V_275 ) ;
} else {
F_33 ( 0 , V_275 ) ;
}
V_258 = 0 ;
for ( V_106 = 0 ; V_106 < V_255 ; V_106 ++ ) {
unsigned V_276 = 0 ;
V_170 = F_107 ( V_256 [ V_106 ] ) ;
V_257 = F_109 ( V_256 [ V_106 ] ) ;
V_172 = F_79 ( V_256 [ V_106 ] ) ;
V_259 = ( ( V_256 [ V_106 ] & V_266 ) != 0 ) ;
V_260 = V_264 [ V_59 -> V_265 ] [ V_172 ] ;
V_10 -> V_204 [ V_106 ] = V_258 ;
switch ( V_257 ) {
case V_277 :
V_276 |=
V_278 ;
break;
case V_279 :
V_276 |=
V_280 ;
break;
case V_281 :
V_276 |=
V_282 ;
break;
case V_283 :
break;
}
V_276 |= F_110 ( V_170 ) ;
V_276 |=
F_111 ( V_59 -> V_60 , V_170 ) ;
V_276 |= F_112 ( V_260 ) ;
if ( V_106 == V_255 - 1 )
V_276 |= V_284 ;
if ( V_259 )
V_276 |= V_285 ;
V_276 |= V_286 ;
F_39 ( V_276 , V_287 ) ;
}
F_105 ( V_5 ) ;
}
static void F_104 ( struct V_4 * V_5 ,
unsigned int V_255 , unsigned int * V_256 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_170 , V_172 , V_257 ;
unsigned int V_106 ;
unsigned int V_288 , V_289 ;
unsigned V_258 ;
unsigned int V_259 ;
if ( V_59 -> V_60 & V_61 ) {
F_106 ( V_5 , V_255 , V_256 ) ;
return;
}
if ( V_255 == 1 && ( V_59 -> V_60 != V_185 )
&& ( V_59 -> V_60 != V_66 ) ) {
if ( V_10 -> V_290
&& V_10 -> V_291 == V_256 [ 0 ] ) {
return;
}
V_10 -> V_290 = 1 ;
V_10 -> V_291 = V_256 [ 0 ] ;
} else {
V_10 -> V_290 = 0 ;
}
V_10 -> V_16 ( V_5 , 1 , V_261 ) ;
if ( V_59 -> V_60 == V_66 ) {
if ( ( V_256 [ 0 ] & V_262 )
&& ! V_10 -> V_292 ) {
F_39 ( V_10 -> V_268 |
V_293 ,
V_294 ) ;
F_39 ( V_10 -> V_268 ,
V_294 ) ;
V_10 -> V_292 = 1 ;
F_113 ( 100 ) ;
} else if ( ! ( V_256 [ 0 ] & V_262 )
&& V_10 -> V_292 ) {
F_39 ( V_10 -> V_268 |
V_295 ,
V_294 ) ;
F_39 ( V_10 -> V_268 ,
V_294 ) ;
V_10 -> V_292 = 0 ;
F_113 ( 100 ) ;
}
}
V_258 = 1 << ( V_59 -> V_247 - 1 ) ;
for ( V_106 = 0 ; V_106 < V_255 ; V_106 ++ ) {
if ( ( V_59 -> V_60 != V_66 )
&& ( V_256 [ V_106 ] & V_262 ) ) {
V_170 = V_10 -> V_268 ;
} else {
V_170 = F_107 ( V_256 [ V_106 ] ) ;
}
V_257 = F_109 ( V_256 [ V_106 ] ) ;
V_172 = F_79 ( V_256 [ V_106 ] ) ;
V_259 = ( ( V_256 [ V_106 ] & V_266 ) != 0 ) ;
V_172 = V_264 [ V_59 -> V_265 ] [ V_172 ] ;
if ( V_59 -> V_60 == V_185 )
V_10 -> V_204 [ V_106 ] = V_258 ;
else
V_10 -> V_204 [ V_106 ] = ( V_172 & 0x100 ) ? 0 : V_258 ;
V_288 = 0 ;
if ( ( V_256 [ V_106 ] & V_262 ) ) {
if ( V_59 -> V_60 == V_185 )
F_39 ( F_107 ( V_256 [ V_106 ] ) & 0x0003 ,
V_296 ) ;
} else {
if ( V_59 -> V_60 == V_185 )
V_257 = V_277 ;
else if ( V_59 -> V_60 == V_66 )
V_257 = V_283 ;
switch ( V_257 ) {
case V_277 :
V_288 |= V_297 ;
break;
case V_279 :
V_288 |= V_298 ;
break;
case V_281 :
V_288 |= V_299 ;
break;
case V_283 :
break;
}
}
V_288 |= F_114 ( V_170 ) ;
F_39 ( V_288 , V_300 ) ;
if ( V_59 -> V_60 != V_66 ) {
V_289 = V_172 ;
if ( V_106 == V_255 - 1 )
V_289 |= V_301 ;
if ( V_259 )
V_289 |= V_302 ;
F_39 ( V_289 , V_303 ) ;
}
}
if ( ( V_59 -> V_60 != V_185 )
&& ( V_59 -> V_60 != V_66 ) ) {
F_105 ( V_5 ) ;
}
}
static int F_115 ( const struct V_4 * V_5 , unsigned V_304 ,
int V_305 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_306 ;
switch ( V_305 ) {
case V_307 :
default:
V_306 = ( V_304 + V_10 -> V_308 / 2 ) / V_10 -> V_308 ;
break;
case V_309 :
V_306 = ( V_304 ) / V_10 -> V_308 ;
break;
case V_310 :
V_306 = ( V_304 + V_10 -> V_308 - 1 ) / V_10 -> V_308 ;
break;
}
return V_306 - 1 ;
}
static unsigned F_116 ( const struct V_4 * V_5 , int V_311 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
return V_10 -> V_308 * ( V_311 + 1 ) ;
}
static unsigned F_117 ( struct V_4 * V_5 ,
unsigned V_312 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
switch ( V_59 -> V_60 ) {
case V_185 :
case V_66 :
return V_59 -> V_313 ;
break;
default:
break;
}
return V_59 -> V_313 * V_312 ;
}
static int F_118 ( struct V_4 * V_5 , struct V_99 * V_100 ,
struct V_168 * V_169 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_173 = 0 ;
int V_314 ;
unsigned int V_315 ;
if ( ( V_169 -> V_12 & V_316 ) )
V_169 -> V_12 &= ~ V_316 ;
V_173 |= F_119 ( & V_169 -> V_317 ,
V_318 | V_319 | V_320 ) ;
V_173 |= F_119 ( & V_169 -> V_321 ,
V_322 | V_320 ) ;
V_315 = V_322 | V_320 ;
if ( V_59 -> V_60 == V_185 ||
V_59 -> V_60 == V_66 )
V_315 |= V_318 ;
V_173 |= F_119 ( & V_169 -> V_323 , V_315 ) ;
V_173 |= F_119 ( & V_169 -> V_324 , V_325 ) ;
V_173 |= F_119 ( & V_169 -> V_326 , V_325 | V_327 ) ;
if ( V_173 )
return 1 ;
V_173 |= F_120 ( V_169 -> V_317 ) ;
V_173 |= F_120 ( V_169 -> V_321 ) ;
V_173 |= F_120 ( V_169 -> V_323 ) ;
V_173 |= F_120 ( V_169 -> V_326 ) ;
if ( V_173 )
return 2 ;
if ( V_169 -> V_317 == V_320 ) {
unsigned int V_314 = F_107 ( V_169 -> V_328 ) ;
if ( V_314 > 16 )
V_314 = 16 ;
V_314 |= ( V_169 -> V_328 & ( V_329 | V_330 ) ) ;
V_173 |= F_121 ( & V_169 -> V_328 , V_314 ) ;
} else {
V_173 |= F_121 ( & V_169 -> V_328 , 0 ) ;
}
if ( V_169 -> V_321 == V_322 ) {
V_173 |= F_122 ( & V_169 -> V_331 ,
F_117 ( V_5 , V_169 -> V_180 ) ) ;
V_173 |= F_123 ( & V_169 -> V_331 ,
V_10 -> V_308 * 0xffffff ) ;
} else if ( V_169 -> V_321 == V_320 ) {
unsigned int V_314 = F_107 ( V_169 -> V_331 ) ;
if ( V_314 > 16 )
V_314 = 16 ;
V_314 |= ( V_169 -> V_331 & ( V_329 | V_330 ) ) ;
V_173 |= F_121 ( & V_169 -> V_331 , V_314 ) ;
} else {
V_173 |= F_121 ( & V_169 -> V_331 , 0 ) ;
}
if ( V_169 -> V_323 == V_322 ) {
if ( ( V_59 -> V_60 == V_185 )
|| ( V_59 -> V_60 == V_66 ) ) {
V_173 |= F_121 ( & V_169 -> V_332 , 0 ) ;
} else {
V_173 |= F_122 ( & V_169 -> V_332 ,
V_59 -> V_313 ) ;
V_173 |= F_123 ( & V_169 -> V_332 ,
V_10 -> V_308 * 0xffff ) ;
}
} else if ( V_169 -> V_323 == V_320 ) {
unsigned int V_314 = F_107 ( V_169 -> V_332 ) ;
if ( V_314 > 16 )
V_314 = 16 ;
V_314 |= ( V_169 -> V_332 & ( V_266 | V_329 ) ) ;
V_173 |= F_121 ( & V_169 -> V_332 , V_314 ) ;
} else if ( V_169 -> V_323 == V_318 ) {
V_173 |= F_121 ( & V_169 -> V_332 , 0 ) ;
}
V_173 |= F_121 ( & V_169 -> V_333 , V_169 -> V_180 ) ;
if ( V_169 -> V_326 == V_325 ) {
unsigned int V_334 = 0x01000000 ;
if ( V_59 -> V_60 == V_185 )
V_334 -= V_250 ;
V_173 |= F_123 ( & V_169 -> V_335 , V_334 ) ;
V_173 |= F_122 ( & V_169 -> V_335 , 1 ) ;
} else {
V_173 |= F_121 ( & V_169 -> V_335 , 0 ) ;
}
if ( V_173 )
return 3 ;
if ( V_169 -> V_321 == V_322 ) {
V_314 = V_169 -> V_331 ;
V_169 -> V_331 =
F_116 ( V_5 , F_115 ( V_5 ,
V_169 -> V_331 ,
V_169 ->
V_12 &
V_336 ) ) ;
if ( V_314 != V_169 -> V_331 )
V_173 ++ ;
}
if ( V_169 -> V_323 == V_322 ) {
if ( ( V_59 -> V_60 != V_185 )
&& ( V_59 -> V_60 != V_66 ) ) {
V_314 = V_169 -> V_332 ;
V_169 -> V_332 =
F_116 ( V_5 , F_115 ( V_5 ,
V_169 -> V_332 ,
V_169 ->
V_12 &
V_336 ) ) ;
if ( V_314 != V_169 -> V_332 )
V_173 ++ ;
if ( V_169 -> V_321 == V_322 &&
V_169 -> V_331 <
V_169 -> V_332 * V_169 -> V_333 ) {
V_169 -> V_331 =
V_169 -> V_332 * V_169 -> V_333 ;
V_173 ++ ;
}
}
}
if ( V_173 )
return 4 ;
return 0 ;
}
static int F_124 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
const struct V_168 * V_169 = & V_100 -> V_103 -> V_169 ;
int V_311 ;
int V_337 = 0 ;
int V_338 = 0 ;
int V_339 = 0 ;
unsigned int V_340 ;
int V_341 = 0 ;
if ( V_5 -> V_79 == 0 ) {
F_19 ( V_5 , L_21 ) ;
return - V_206 ;
}
F_32 ( V_5 ) ;
F_104 ( V_5 , V_169 -> V_180 , V_169 -> V_175 ) ;
V_10 -> V_16 ( V_5 , V_209 , V_211 ) ;
V_10 -> V_342 &= ~ V_343 ;
V_10 -> V_16 ( V_5 , V_10 -> V_342 ,
V_344 ) ;
switch ( V_169 -> V_317 ) {
case V_319 :
case V_318 :
V_10 -> V_16 ( V_5 , F_125 ( 0 ) |
V_345 | V_346 |
F_126 ( 0 ) ,
V_347 ) ;
break;
case V_320 :
{
int V_170 = F_107 ( V_169 -> V_328 ) ;
unsigned int V_72 = F_125 ( 0 ) |
V_345 | F_126 ( V_170 + 1 ) ;
if ( V_169 -> V_328 & V_329 )
V_72 |= V_348 ;
if ( V_169 -> V_328 & V_330 )
V_72 |= V_346 ;
V_10 -> V_16 ( V_5 , V_72 ,
V_347 ) ;
break;
}
}
V_338 &= ~ V_349 ;
V_338 &= ~ V_350 ;
V_338 &= ~ V_351 ;
V_10 -> V_16 ( V_5 , V_338 , V_225 ) ;
if ( V_169 -> V_180 == 1 || ( V_59 -> V_60 == V_185 )
|| ( V_59 -> V_60 == V_66 ) ) {
V_339 |= V_352 ;
V_339 |= F_127 ( 31 ) ;
V_339 |= V_353 ;
} else {
V_339 |= F_127 ( 19 ) ;
}
V_10 -> V_16 ( V_5 , V_339 ,
V_354 ) ;
V_10 -> V_113 = 0 ;
switch ( V_169 -> V_326 ) {
case V_325 :
V_340 = V_169 -> V_335 - 1 ;
if ( V_59 -> V_60 == V_185 ) {
V_340 += V_250 ;
}
V_10 -> V_355 ( V_5 , V_340 , V_356 ) ;
V_337 |= V_222 | V_223 | V_357 ;
V_10 -> V_16 ( V_5 , V_337 , V_224 ) ;
V_10 -> V_16 ( V_5 , V_358 , V_221 ) ;
V_10 -> V_144 = 0 ;
if ( V_340 == 0 ) {
V_10 -> V_113 |= V_114 ;
V_341 |= V_216 ;
if ( V_169 -> V_180 > 1 )
V_339 |=
V_352 | V_359 ;
}
break;
case V_327 :
V_10 -> V_355 ( V_5 , 0 , V_356 ) ;
V_337 |= V_222 | V_223 | V_360 ;
V_10 -> V_16 ( V_5 , V_337 , V_224 ) ;
V_10 -> V_16 ( V_5 , V_358 , V_221 ) ;
V_10 -> V_144 = 1 ;
break;
}
switch ( V_169 -> V_321 ) {
case V_322 :
V_339 |= V_361 | V_362 ;
V_10 -> V_16 ( V_5 , V_339 ,
V_354 ) ;
V_338 |= F_128 ( 0 ) ;
V_338 &= ~ V_363 ;
V_10 -> V_16 ( V_5 , V_338 , V_225 ) ;
V_311 = F_115 ( V_5 , V_169 -> V_331 ,
V_307 ) ;
V_10 -> V_355 ( V_5 , V_311 , V_364 ) ;
V_10 -> V_16 ( V_5 , V_365 , V_221 ) ;
break;
case V_320 :
if ( V_169 -> V_331 & V_330 )
V_339 |= V_361 ;
if ( V_169 -> V_331 & V_329 )
V_339 |= V_366 ;
if ( V_169 -> V_321 != V_169 -> V_323 ||
( V_169 -> V_331 & ~ V_330 ) !=
( V_169 -> V_332 & ~ V_330 ) )
V_339 |= V_362 ;
V_339 |=
F_129 ( 1 + F_107 ( V_169 -> V_331 ) ) ;
V_10 -> V_16 ( V_5 , V_339 ,
V_354 ) ;
break;
}
switch ( V_169 -> V_323 ) {
case V_322 :
case V_318 :
if ( V_169 -> V_332 == 0 || V_169 -> V_323 == V_318 )
V_311 = 1 ;
else
V_311 = F_115 ( V_5 , V_169 -> V_332 ,
V_307 ) ;
V_10 -> V_16 ( V_5 , 1 , V_367 ) ;
V_10 -> V_16 ( V_5 , V_311 , V_368 ) ;
V_338 &= ~ V_369 ;
V_338 |= V_370 ;
V_10 -> V_16 ( V_5 , V_338 , V_225 ) ;
V_10 -> V_16 ( V_5 , V_371 , V_221 ) ;
V_338 |= V_370 ;
V_338 |= V_369 ;
V_10 -> V_16 ( V_5 , V_338 , V_225 ) ;
break;
case V_320 :
V_337 |= F_130 ( 1 + V_169 -> V_332 ) ;
if ( ( V_169 -> V_332 & V_329 ) == 0 )
V_337 |= V_372 ;
V_10 -> V_16 ( V_5 , V_337 , V_224 ) ;
V_338 |= V_373 | V_374 ;
V_10 -> V_16 ( V_5 , V_338 , V_225 ) ;
break;
}
if ( V_5 -> V_79 ) {
V_341 |= V_217 |
V_212 ;
#ifndef F_24
V_341 |= V_218 ;
#endif
if ( V_169 -> V_12 & V_375
|| ( V_10 -> V_113 & V_114 ) ) {
V_10 -> V_109 = V_110 ;
} else {
V_10 -> V_109 = V_376 ;
}
switch ( V_10 -> V_109 ) {
case V_376 :
#ifdef F_24
V_10 -> V_16 ( V_5 , V_377 ,
V_226 ) ;
#else
V_10 -> V_16 ( V_5 , V_378 ,
V_226 ) ;
#endif
break;
case V_379 :
V_10 -> V_16 ( V_5 , V_380 ,
V_226 ) ;
break;
case V_110 :
#ifdef F_24
V_10 -> V_16 ( V_5 , V_380 ,
V_226 ) ;
#else
V_10 -> V_16 ( V_5 , V_378 ,
V_226 ) ;
#endif
V_341 |= V_216 ;
break;
default:
break;
}
V_10 -> V_16 ( V_5 , V_239 | V_128 | V_126 | V_238 | V_124 | V_122 | V_237 , V_129 ) ;
F_43 ( V_5 , V_14 ,
V_341 , 1 ) ;
} else {
F_43 ( V_5 , V_14 , ~ 0 , 0 ) ;
}
V_10 -> V_16 ( V_5 , V_240 , V_211 ) ;
switch ( V_169 -> V_321 ) {
case V_322 :
V_10 -> V_16 ( V_5 ,
V_381 | V_382 | V_383 |
V_384 , V_221 ) ;
break;
case V_320 :
V_10 -> V_16 ( V_5 ,
V_381 | V_382 | V_383 |
V_384 , V_221 ) ;
break;
}
#ifdef F_24
{
int V_192 = F_91 ( V_5 ) ;
if ( V_192 )
return V_192 ;
}
#endif
switch ( V_169 -> V_317 ) {
case V_318 :
V_10 -> V_16 ( V_5 , V_385 | V_10 -> V_113 ,
V_386 ) ;
V_100 -> V_103 -> V_387 = NULL ;
break;
case V_320 :
V_100 -> V_103 -> V_387 = NULL ;
break;
case V_319 :
V_100 -> V_103 -> V_387 = & V_388 ;
break;
}
return 0 ;
}
static int V_388 ( struct V_4 * V_5 , struct V_99 * V_100 ,
unsigned int V_389 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_389 != 0 )
return - V_390 ;
V_10 -> V_16 ( V_5 , V_385 | V_10 -> V_113 ,
V_386 ) ;
V_100 -> V_103 -> V_387 = NULL ;
return 1 ;
}
static int F_131 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 , unsigned int * V_71 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_245 -> V_166 < 1 )
return - V_390 ;
switch ( V_71 [ 0 ] ) {
case V_391 :
return F_132 ( V_5 , V_100 , V_245 , V_71 ) ;
case V_392 :
if ( V_59 -> V_60 & V_61 ) {
if ( V_71 [ 1 ] & ~ ( V_269 |
V_270 |
V_271 |
V_272 ) ) {
return - V_390 ;
}
V_10 -> V_268 = V_71 [ 1 ] ;
} else if ( V_59 -> V_60 == V_66 ) {
unsigned int V_393 ;
V_393 = V_71 [ 1 ] & 0xf ;
if ( V_393 > 0xF )
return - V_390 ;
V_10 -> V_268 = V_393 ;
F_39 ( V_393 , V_294 ) ;
} else {
unsigned int V_393 ;
unsigned int V_394 ;
V_393 = V_71 [ 1 ] & 0xf ;
V_394 = ( V_71 [ 1 ] >> 4 ) & 0xff ;
if ( V_393 >= 8 )
return - V_390 ;
V_10 -> V_268 = V_393 ;
if ( V_59 -> V_60 == V_185 ) {
F_5 ( V_394 ,
V_395 ) ;
}
}
return 2 ;
default:
break;
}
return - V_390 ;
}
static int F_132 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 ,
unsigned int * V_71 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_396 , V_397 , V_398 ;
int V_173 = 0 ;
if ( ! V_59 -> V_399 )
return - V_390 ;
if ( ( V_71 [ 1 ] & 0xffff0000 ) != V_400 ) {
V_71 [ 1 ] &= ( V_400 | 0xffff ) ;
V_173 ++ ;
}
if ( V_71 [ 2 ] >= V_59 -> V_401 ) {
V_71 [ 2 ] = V_59 -> V_401 - 1 ;
V_173 ++ ;
}
if ( V_71 [ 3 ] > 255 ) {
V_71 [ 3 ] = 255 ;
V_173 ++ ;
}
if ( V_71 [ 4 ] > 255 ) {
V_71 [ 4 ] = 255 ;
V_173 ++ ;
}
V_396 = V_71 [ 3 ] ;
V_397 = V_71 [ 4 ] ;
V_398 = V_71 [ 1 ] & 0xff ;
if ( V_398 & 0xf0 ) {
if ( V_397 < V_396 ) {
V_396 = V_71 [ 4 ] ;
V_397 = V_71 [ 3 ] ;
V_398 =
( ( V_71 [ 1 ] & 0xf ) << 4 ) | ( ( V_71 [ 1 ] & 0xf0 ) >> 4 ) ;
}
V_10 -> V_402 = V_396 ;
V_10 -> V_403 = V_397 ;
switch ( V_398 ) {
case 0x81 :
V_10 -> V_404 = 6 ;
break;
case 0x42 :
V_10 -> V_404 = 3 ;
break;
case 0x96 :
V_10 -> V_404 = 2 ;
break;
default:
V_71 [ 1 ] &= ~ 0xff ;
V_173 ++ ;
}
} else {
if ( V_397 != 0 ) {
V_71 [ 4 ] = 0 ;
V_173 ++ ;
}
switch ( V_398 ) {
case 0x06 :
V_10 -> V_403 = V_396 ;
V_10 -> V_404 = 0 ;
break;
case 0x09 :
V_10 -> V_402 = V_396 ;
V_10 -> V_404 = 1 ;
break;
default:
V_71 [ 1 ] &= ~ 0xff ;
V_173 ++ ;
}
}
if ( V_173 )
return - V_405 ;
return 5 ;
}
static void F_133 ( struct V_4 * V_5 , struct V_99 * V_100 ,
void * V_71 , unsigned int V_197 ,
unsigned int V_198 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_167 * V_103 = V_100 -> V_103 ;
unsigned int V_172 ;
unsigned int V_106 ;
unsigned int V_258 ;
unsigned int V_199 = V_197 / sizeof( short ) ;
unsigned short * V_200 = V_71 ;
V_258 = 1 << ( V_59 -> V_406 - 1 ) ;
for ( V_106 = 0 ; V_106 < V_199 ; V_106 ++ ) {
V_172 = F_79 ( V_103 -> V_169 . V_175 [ V_198 ] ) ;
if ( V_59 -> V_407 == 0 || ( V_172 & 1 ) == 0 )
V_200 [ V_106 ] -= V_258 ;
#ifdef F_24
V_200 [ V_106 ] = F_134 ( V_200 [ V_106 ] ) ;
#endif
V_198 ++ ;
V_198 %= V_103 -> V_169 . V_180 ;
}
}
static int F_135 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
unsigned int V_249 [] ,
unsigned int V_408 , int V_409 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_172 ;
unsigned int V_170 ;
unsigned int V_410 ;
int V_106 ;
int V_411 = 0 ;
if ( V_409 ) {
for ( V_106 = 0 ; V_106 < V_59 -> V_412 ; ++ V_106 ) {
V_10 -> V_413 [ V_106 ] &= ~ V_414 ;
F_5 ( V_10 -> V_413 [ V_106 ] ,
F_136 ( V_106 ) ) ;
F_5 ( 0xf , F_137 ( V_106 ) ) ;
}
}
for ( V_106 = 0 ; V_106 < V_408 ; V_106 ++ ) {
const struct V_415 * V_416 ;
V_170 = F_107 ( V_249 [ V_106 ] ) ;
V_172 = F_79 ( V_249 [ V_106 ] ) ;
V_416 = V_100 -> V_417 -> V_172 + V_172 ;
V_411 = 0 ;
V_410 = 0 ;
switch ( V_416 -> V_418 - V_416 -> V_419 ) {
case 20000000 :
V_410 |= V_420 ;
F_5 ( 0 , F_138 ( V_170 ) ) ;
break;
case 10000000 :
V_410 |= V_421 ;
F_5 ( 0 , F_138 ( V_170 ) ) ;
break;
case 4000000 :
V_410 |= V_420 ;
F_5 ( V_422 ,
F_138 ( V_170 ) ) ;
break;
case 2000000 :
V_410 |= V_421 ;
F_5 ( V_422 ,
F_138 ( V_170 ) ) ;
break;
default:
F_6 ( L_22 ,
V_25 ) ;
break;
}
switch ( V_416 -> V_418 + V_416 -> V_419 ) {
case 0 :
V_410 |= V_423 ;
break;
case 10000000 :
V_410 |= V_424 ;
break;
default:
F_6 ( L_23 ,
V_25 ) ;
break;
}
if ( V_409 )
V_410 |= V_414 ;
F_5 ( V_410 , F_136 ( V_170 ) ) ;
V_10 -> V_413 [ V_170 ] = V_410 ;
F_5 ( V_106 , F_137 ( V_170 ) ) ;
}
return V_411 ;
}
static int F_139 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
unsigned int V_249 [] ,
unsigned int V_408 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_172 ;
unsigned int V_170 ;
unsigned int V_410 ;
int V_106 ;
int V_411 = 0 ;
for ( V_106 = 0 ; V_106 < V_408 ; V_106 ++ ) {
V_170 = F_107 ( V_249 [ V_106 ] ) ;
V_172 = F_79 ( V_249 [ V_106 ] ) ;
V_410 = F_140 ( V_170 ) ;
if ( V_59 -> V_407 ) {
if ( ( V_172 & 1 ) == 0 ) {
V_410 |= V_425 ;
V_411 = ( 1 << ( V_59 -> V_406 - 1 ) ) ;
} else {
V_411 = 0 ;
}
if ( V_172 & 2 )
V_410 |= V_426 ;
} else {
V_410 |= V_425 ;
V_411 = ( 1 << ( V_59 -> V_406 - 1 ) ) ;
}
if ( V_249 [ V_106 ] & V_427 )
V_410 |= V_428 ;
V_410 |= ( F_109 ( V_249 [ V_106 ] ) ==
V_283 ) ? V_429 : 0 ;
F_39 ( V_410 , V_430 ) ;
V_10 -> V_413 [ V_170 ] = V_410 ;
}
return V_411 ;
}
static int F_141 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
unsigned int V_249 [] , unsigned int V_408 ,
int V_409 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
if ( V_59 -> V_60 & V_61 )
return F_135 ( V_5 , V_100 , V_249 , V_408 ,
V_409 ) ;
else
return F_139 ( V_5 , V_100 , V_249 , V_408 ) ;
}
static int F_142 ( struct V_4 * V_5 ,
struct V_99 * V_100 , struct V_244 * V_245 ,
unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_71 [ 0 ] = V_10 -> V_431 [ F_107 ( V_245 -> V_249 ) ] ;
return 1 ;
}
static int F_143 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 , unsigned int * V_71 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_170 = F_107 ( V_245 -> V_249 ) ;
unsigned int V_411 ;
V_411 = F_141 ( V_5 , V_100 , & V_245 -> V_249 , 1 , 0 ) ;
V_10 -> V_431 [ V_170 ] = V_71 [ 0 ] ;
if ( V_59 -> V_60 & V_61 ) {
F_39 ( V_71 [ 0 ] , F_144 ( V_170 ) ) ;
} else
F_39 ( V_71 [ 0 ] ^ V_411 ,
( V_170 ) ? V_432 : V_433 ) ;
return 1 ;
}
static int F_145 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 , unsigned int * V_71 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_170 = F_107 ( V_245 -> V_249 ) ;
unsigned int V_411 ;
F_146 ( 1 << V_170 , V_434 ) ;
V_411 = 1 << ( V_59 -> V_406 - 1 ) ;
F_141 ( V_5 , V_100 , & V_245 -> V_249 , 1 , 0 ) ;
V_10 -> V_431 [ V_170 ] = V_71 [ 0 ] ;
F_146 ( V_71 [ 0 ] ^ V_411 , F_147 ( V_170 ) ) ;
return 1 ;
}
static int F_148 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 , unsigned int * V_71 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
switch ( V_71 [ 0 ] ) {
case V_435 :
switch ( V_71 [ 1 ] ) {
case V_47 :
V_71 [ 2 ] = 1 + V_59 -> V_181 * sizeof( short ) ;
if ( V_10 -> V_40 )
V_71 [ 2 ] += V_10 -> V_40 -> V_436 ;
break;
case V_44 :
V_71 [ 2 ] = 0 ;
break;
default:
return - V_390 ;
break;
}
return 0 ;
default:
break;
}
return - V_390 ;
}
static int F_149 ( struct V_4 * V_5 , struct V_99 * V_100 ,
unsigned int V_389 )
{
const struct V_58 * V_59 V_195 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_163 ;
int V_437 ;
int V_106 ;
static const int V_105 = 1000 ;
if ( V_389 != 0 )
return - V_390 ;
V_100 -> V_103 -> V_387 = NULL ;
F_43 ( V_5 , V_17 ,
V_164 | V_165 , 0 ) ;
V_437 = V_165 ;
#ifdef F_24
V_10 -> V_16 ( V_5 , 1 , V_183 ) ;
if ( V_59 -> V_60 & V_176 )
F_40 ( V_5 , 0x6 , V_184 ) ;
V_163 = F_95 ( V_5 ) ;
if ( V_163 )
return V_163 ;
V_163 = F_59 ( V_5 ) ;
if ( V_163 < 0 )
return V_163 ;
#else
V_163 = F_81 ( V_5 , V_100 ) ;
if ( V_163 == 0 )
return - V_108 ;
V_437 |= V_164 ;
#endif
V_10 -> V_16 ( V_5 , V_10 -> V_438 | V_439 ,
V_440 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_438 , V_440 ) ;
for ( V_106 = 0 ; V_106 < V_105 ; V_106 ++ ) {
F_60 ( 1 ) ;
if ( ( V_10 -> V_73 ( V_5 ,
V_441 ) &
V_442 ) == 0 )
break;
}
if ( V_106 == V_105 ) {
F_19 ( V_5 ,
L_24 ) ;
return - V_206 ;
}
V_10 -> V_16 ( V_5 , V_149 ,
V_160 ) ;
F_43 ( V_5 , V_17 , V_437 , 1 ) ;
V_10 -> V_16 ( V_5 ,
V_10 -> V_443 | V_444 | V_445 | V_446
| V_447 | V_448 ,
V_449 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_450 | V_451 ,
V_452 ) ;
return 0 ;
}
static int F_150 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
const struct V_168 * V_169 = & V_100 -> V_103 -> V_169 ;
int V_72 ;
int V_106 ;
unsigned V_453 ;
if ( V_5 -> V_79 == 0 ) {
F_19 ( V_5 , L_21 ) ;
return - V_206 ;
}
V_10 -> V_16 ( V_5 , V_454 , V_211 ) ;
V_10 -> V_16 ( V_5 , V_455 , V_449 ) ;
if ( V_59 -> V_60 & V_176 ) {
F_146 ( V_456 , V_457 ) ;
V_72 = 0 ;
for ( V_106 = 0 ; V_106 < V_169 -> V_180 ; V_106 ++ ) {
int V_170 ;
V_170 = F_107 ( V_169 -> V_175 [ V_106 ] ) ;
V_72 |= 1 << V_170 ;
F_146 ( V_170 , V_458 ) ;
}
F_146 ( V_72 , V_459 ) ;
}
F_141 ( V_5 , V_100 , V_169 -> V_175 , V_169 -> V_180 , 1 ) ;
if ( V_169 -> V_326 == V_327 ) {
V_10 -> V_460 |= V_461 ;
V_10 -> V_460 &= ~ V_462 ;
} else {
V_10 -> V_460 &= ~ V_461 ;
V_10 -> V_460 |= V_462 ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_460 , V_463 ) ;
switch ( V_169 -> V_317 ) {
case V_319 :
case V_318 :
V_10 -> V_464 &=
~ ( V_465 | F_151 ( - 1 ) ) ;
V_10 -> V_464 |= V_466 | V_467 ;
V_10 -> V_16 ( V_5 , V_10 -> V_464 ,
V_468 ) ;
break;
case V_320 :
V_10 -> V_464 =
F_151 ( F_107 ( V_169 -> V_328 ) + 1 ) ;
if ( V_169 -> V_328 & V_329 )
V_10 -> V_464 |= V_465 ;
if ( V_169 -> V_328 & V_330 )
V_10 -> V_464 |= V_466 ;
V_10 -> V_16 ( V_5 , V_10 -> V_464 ,
V_468 ) ;
break;
default:
F_2 () ;
break;
}
V_10 -> V_438 &= ~ V_469 ;
V_10 -> V_16 ( V_5 , V_10 -> V_438 , V_440 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_460 , V_463 ) ;
V_10 -> V_470 &= ~ V_471 ;
V_10 -> V_16 ( V_5 , V_10 -> V_470 , V_472 ) ;
if ( V_169 -> V_326 == V_327 )
V_10 -> V_355 ( V_5 , 0xffffff , V_473 ) ;
else
V_10 -> V_355 ( V_5 , 0 , V_473 ) ;
V_10 -> V_16 ( V_5 , V_474 , V_449 ) ;
V_10 -> V_470 &= ~ V_475 ;
V_10 -> V_16 ( V_5 , V_10 -> V_470 , V_472 ) ;
switch ( V_169 -> V_326 ) {
case V_325 :
if ( V_59 -> V_60 & V_61 ) {
V_10 -> V_355 ( V_5 , V_169 -> V_335 - 1 ,
V_476 ) ;
V_10 -> V_16 ( V_5 , V_477 ,
V_449 ) ;
} else {
V_10 -> V_355 ( V_5 , V_169 -> V_335 ,
V_476 ) ;
V_10 -> V_16 ( V_5 , V_477 ,
V_449 ) ;
V_10 -> V_355 ( V_5 , V_169 -> V_335 - 1 ,
V_476 ) ;
}
break;
case V_327 :
V_10 -> V_355 ( V_5 , 0xffffff , V_476 ) ;
V_10 -> V_16 ( V_5 , V_477 , V_449 ) ;
V_10 -> V_355 ( V_5 , 0xffffff , V_476 ) ;
break;
default:
V_10 -> V_355 ( V_5 , 0 , V_476 ) ;
V_10 -> V_16 ( V_5 , V_477 , V_449 ) ;
V_10 -> V_355 ( V_5 , V_169 -> V_335 , V_476 ) ;
}
V_10 -> V_460 &=
~ ( F_152 ( 0x1f ) | V_478 |
F_153 ( 0x1f ) | V_479 ) ;
switch ( V_169 -> V_321 ) {
case V_322 :
V_10 -> V_450 &= ~ V_480 ;
V_453 =
F_115 ( V_5 , V_169 -> V_331 ,
V_307 ) ;
V_10 -> V_355 ( V_5 , 1 , V_481 ) ;
V_10 -> V_16 ( V_5 , V_482 , V_449 ) ;
V_10 -> V_355 ( V_5 , V_453 , V_481 ) ;
break;
case V_320 :
V_10 -> V_460 |=
F_153 ( V_169 -> V_331 ) ;
if ( V_169 -> V_331 & V_329 )
V_10 -> V_460 |= V_479 ;
V_10 -> V_450 |= V_480 ;
break;
default:
F_2 () ;
break;
}
V_10 -> V_16 ( V_5 , V_10 -> V_450 , V_452 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_460 , V_463 ) ;
V_10 -> V_470 &=
~ ( F_154 ( 3 ) | V_483 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_470 , V_472 ) ;
if ( V_169 -> V_333 > 1 ) {
V_10 -> V_460 |= V_484 ;
V_10 -> V_16 ( V_5 ,
F_155 ( V_169 -> V_333 -
1 ) |
F_156
( V_485 ) ,
V_486 ) ;
} else {
unsigned V_72 ;
V_10 -> V_460 &= ~ V_484 ;
V_72 = F_156 ( V_485 ) ;
if ( V_59 -> V_60 &
( V_61 | V_176 ) ) {
V_72 |= F_155 ( 0 ) ;
} else {
V_72 |=
F_155 ( F_107 ( V_169 -> V_175 [ 0 ] ) ) ;
}
V_10 -> V_16 ( V_5 , V_72 , V_486 ) ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_460 , V_463 ) ;
V_10 -> V_16 ( V_5 , V_448 | V_447 ,
V_449 ) ;
V_10 -> V_438 |= V_487 ;
V_10 -> V_16 ( V_5 , V_10 -> V_438 , V_440 ) ;
V_10 -> V_470 &= ~ V_488 ;
#ifdef F_24
V_10 -> V_470 |= V_489 ;
#else
V_10 -> V_470 |= V_490 ;
#endif
V_10 -> V_470 &= ~ V_491 ;
V_10 -> V_16 ( V_5 , V_10 -> V_470 , V_472 ) ;
V_72 = V_492 | V_493 |
V_494 ;
if ( V_59 -> V_181 )
V_72 |= V_495 ;
else
V_72 |= V_496 ;
#if 0
if (board->reg_type & ni_reg_m_series_mask)
bits |= AO_Number_Of_DAC_Packages;
#endif
V_10 -> V_16 ( V_5 , V_72 , V_497 ) ;
V_10 -> V_16 ( V_5 , V_498 , V_499 ) ;
V_10 -> V_16 ( V_5 , V_500 , V_211 ) ;
if ( V_169 -> V_326 == V_325 ) {
V_10 -> V_16 ( V_5 , V_147 ,
V_160 ) ;
F_43 ( V_5 , V_17 ,
V_501 , 1 ) ;
}
V_100 -> V_103 -> V_387 = & F_149 ;
return 0 ;
}
static int F_157 ( struct V_4 * V_5 , struct V_99 * V_100 ,
struct V_168 * V_169 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_173 = 0 ;
int V_314 ;
if ( ( V_169 -> V_12 & V_316 ) == 0 )
V_169 -> V_12 |= V_316 ;
V_173 |= F_119 ( & V_169 -> V_317 , V_319 | V_320 ) ;
V_173 |= F_119 ( & V_169 -> V_321 ,
V_322 | V_320 ) ;
V_173 |= F_119 ( & V_169 -> V_323 , V_318 ) ;
V_173 |= F_119 ( & V_169 -> V_324 , V_325 ) ;
V_173 |= F_119 ( & V_169 -> V_326 , V_325 | V_327 ) ;
if ( V_173 )
return 1 ;
V_173 |= F_120 ( V_169 -> V_317 ) ;
V_173 |= F_120 ( V_169 -> V_321 ) ;
V_173 |= F_120 ( V_169 -> V_326 ) ;
if ( V_173 )
return 2 ;
if ( V_169 -> V_317 == V_320 ) {
unsigned int V_314 = F_107 ( V_169 -> V_328 ) ;
if ( V_314 > 18 )
V_314 = 18 ;
V_314 |= ( V_169 -> V_328 & ( V_329 | V_330 ) ) ;
V_173 |= F_121 ( & V_169 -> V_328 , V_314 ) ;
} else {
V_173 |= F_121 ( & V_169 -> V_328 , 0 ) ;
}
if ( V_169 -> V_321 == V_322 ) {
V_173 |= F_122 ( & V_169 -> V_331 ,
V_59 -> V_502 ) ;
V_173 |= F_123 ( & V_169 -> V_331 ,
V_10 -> V_308 * 0xffffff ) ;
}
V_173 |= F_121 ( & V_169 -> V_332 , 0 ) ;
V_173 |= F_121 ( & V_169 -> V_333 , V_169 -> V_180 ) ;
if ( V_169 -> V_326 == V_325 )
V_173 |= F_123 ( & V_169 -> V_335 , 0x00ffffff ) ;
else
V_173 |= F_121 ( & V_169 -> V_335 , 0 ) ;
if ( V_173 )
return 3 ;
if ( V_169 -> V_321 == V_322 ) {
V_314 = V_169 -> V_331 ;
V_169 -> V_331 =
F_116 ( V_5 , F_115 ( V_5 ,
V_169 -> V_331 ,
V_169 ->
V_12 &
V_336 ) ) ;
if ( V_314 != V_169 -> V_331 )
V_173 ++ ;
}
if ( V_173 )
return 4 ;
if ( V_173 )
return 5 ;
return 0 ;
}
static int F_69 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
F_27 ( V_5 ) ;
V_10 -> V_16 ( V_5 , V_454 , V_211 ) ;
V_10 -> V_16 ( V_5 , V_455 , V_449 ) ;
F_43 ( V_5 , V_17 , ~ 0 , 0 ) ;
V_10 -> V_16 ( V_5 , V_492 , V_497 ) ;
V_10 -> V_16 ( V_5 , 0x3f98 , V_160 ) ;
V_10 -> V_16 ( V_5 , V_492 | V_493 |
V_494 , V_497 ) ;
V_10 -> V_16 ( V_5 , 0 , V_486 ) ;
V_10 -> V_16 ( V_5 , 0 , V_499 ) ;
V_10 -> V_443 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_443 , V_449 ) ;
V_10 -> V_450 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_450 , V_452 ) ;
V_10 -> V_460 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_460 , V_463 ) ;
V_10 -> V_470 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_470 , V_472 ) ;
if ( V_59 -> V_60 & V_61 )
V_10 -> V_438 = V_503 ;
else
V_10 -> V_438 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_438 , V_440 ) ;
V_10 -> V_464 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_464 ,
V_468 ) ;
if ( V_59 -> V_60 & V_176 ) {
unsigned V_504 = 0 ;
unsigned V_106 ;
for ( V_106 = 0 ; V_106 < V_100 -> V_255 ; ++ V_106 )
V_504 |= 1 << V_106 ;
F_146 ( V_504 , V_434 ) ;
F_146 ( V_456 , V_457 ) ;
}
V_10 -> V_16 ( V_5 , V_500 , V_211 ) ;
return 0 ;
}
static int F_158 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 ,
unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_163 ;
V_163 = F_159 ( V_5 , V_100 , V_245 , V_71 , 0 ) ;
if ( V_163 )
return V_163 ;
V_10 -> V_505 &= ~ V_506 ;
V_10 -> V_505 |= F_160 ( V_100 -> V_507 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_505 , V_508 ) ;
return V_245 -> V_166 ;
}
static int F_161 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 ,
unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( ( V_71 [ 0 ] & ( V_509 | V_510 ) ) && V_10 -> V_511 )
return - V_42 ;
if ( F_162 ( V_100 , V_71 ) ) {
V_10 -> V_512 &= ~ V_513 ;
V_10 -> V_512 |= F_163 ( V_100 -> V_514 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_512 ,
V_515 ) ;
}
V_71 [ 1 ] = V_10 -> V_73 ( V_5 , V_516 ) ;
return V_245 -> V_166 ;
}
static int F_164 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 ,
unsigned int * V_71 )
{
struct V_9 * V_10 V_195 = V_5 -> V_11 ;
int V_163 ;
V_163 = F_159 ( V_5 , V_100 , V_245 , V_71 , 0 ) ;
if ( V_163 )
return V_163 ;
F_33 ( V_100 -> V_507 , V_517 ) ;
return V_245 -> V_166 ;
}
static int F_165 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 ,
unsigned int * V_71 )
{
struct V_9 * V_10 V_195 = V_5 -> V_11 ;
if ( F_162 ( V_100 , V_71 ) )
F_33 ( V_100 -> V_514 , V_518 ) ;
V_71 [ 1 ] = F_34 ( V_519 ) ;
return V_245 -> V_166 ;
}
static int F_166 ( struct V_4 * V_5 ,
struct V_99 * V_100 , struct V_168 * V_169 )
{
int V_173 = 0 ;
int V_314 ;
unsigned V_106 ;
V_173 |= F_119 ( & V_169 -> V_317 , V_319 ) ;
V_173 |= F_119 ( & V_169 -> V_321 , V_320 ) ;
V_173 |= F_119 ( & V_169 -> V_323 , V_318 ) ;
V_173 |= F_119 ( & V_169 -> V_324 , V_325 ) ;
V_173 |= F_119 ( & V_169 -> V_326 , V_327 ) ;
if ( V_173 )
return 1 ;
if ( V_173 )
return 2 ;
V_173 |= F_121 ( & V_169 -> V_328 , 0 ) ;
V_314 = V_169 -> V_331 ;
V_314 &= F_167 ( V_520 , 0 , 0 , V_329 ) ;
if ( V_314 != V_169 -> V_331 )
V_173 |= - V_390 ;
V_173 |= F_121 ( & V_169 -> V_332 , 0 ) ;
V_173 |= F_121 ( & V_169 -> V_333 , V_169 -> V_180 ) ;
V_173 |= F_121 ( & V_169 -> V_335 , 0 ) ;
if ( V_173 )
return 3 ;
if ( V_173 )
return 4 ;
for ( V_106 = 0 ; V_106 < V_169 -> V_180 ; ++ V_106 ) {
if ( V_169 -> V_175 [ V_106 ] != V_106 )
V_173 = 1 ;
}
if ( V_173 )
return 5 ;
return 0 ;
}
static int F_168 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
struct V_9 * V_10 V_195 = V_5 -> V_11 ;
const struct V_168 * V_169 = & V_100 -> V_103 -> V_169 ;
unsigned V_521 = V_522 | V_523 ;
int V_192 ;
F_33 ( V_524 , V_525 ) ;
switch ( V_169 -> V_321 ) {
case V_320 :
V_521 |=
F_107 ( V_169 -> V_331 ) &
V_520 ;
break;
default:
F_2 () ;
break;
}
if ( V_169 -> V_331 & V_329 )
V_521 |= V_526 ;
F_33 ( V_521 , V_527 ) ;
if ( V_100 -> V_507 ) {
F_33 ( V_100 -> V_514 , V_528 ) ;
F_33 ( V_529 , V_525 ) ;
F_33 ( V_100 -> V_507 , V_530 ) ;
} else {
F_19 ( V_5 ,
L_25 ) ;
return - V_206 ;
}
V_192 = F_23 ( V_5 ) ;
if ( V_192 < 0 )
return V_192 ;
V_100 -> V_103 -> V_387 = & V_531 ;
return 0 ;
}
static int V_531 ( struct V_4 * V_5 , struct V_99 * V_100 ,
unsigned int V_389 )
{
#ifdef F_24
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_12 ;
#endif
int V_192 = 0 ;
unsigned V_106 ;
const unsigned V_105 = 1000 ;
V_100 -> V_103 -> V_387 = NULL ;
F_96 ( V_100 -> V_103 , V_100 -> V_103 -> V_205 ) ;
#ifdef F_24
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_55 ) {
F_93 ( V_10 -> V_55 , 32 , 32 ) ;
F_94 ( V_10 -> V_55 ) ;
} else {
F_19 ( V_5 , L_26 ) ;
V_192 = - V_206 ;
}
F_8 ( & V_10 -> V_38 , V_12 ) ;
if ( V_192 < 0 )
return V_192 ;
#endif
for ( V_106 = 0 ; V_106 < V_105 ; ++ V_106 ) {
if ( F_34 ( V_532 ) & V_533 )
break;
F_60 ( 10 ) ;
}
if ( V_106 == V_105 ) {
F_19 ( V_5 , L_27 ) ;
F_71 ( V_5 , V_100 ) ;
return - V_206 ;
}
F_33 ( V_534 | V_535 |
V_536 ,
V_525 ) ;
return V_192 ;
}
static int F_71 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
struct V_9 * V_10 V_195 = V_5 -> V_11 ;
F_33 ( V_537 | V_538 |
V_539 |
V_540 ,
V_525 ) ;
F_33 ( 0 , V_530 ) ;
F_29 ( V_5 ) ;
return 0 ;
}
static void F_54 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 V_195 = V_5 -> V_11 ;
unsigned V_541 ;
struct V_99 * V_100 = & V_5 -> V_101 [ V_119 ] ;
#ifdef F_24
unsigned long V_12 ;
#endif
if ( ( V_59 -> V_60 & V_61 ) == 0 )
return;
#ifdef F_24
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_55 ) {
unsigned V_542 =
F_46 ( V_10 -> V_55 ) ;
if ( V_542 & V_92 ) {
F_47 ( V_93 ,
V_10 -> V_40 -> V_94 +
F_48 ( V_10 -> V_55 -> V_26 ) ) ;
}
F_58 ( V_10 -> V_55 , V_100 -> V_103 ) ;
}
F_8 ( & V_10 -> V_38 , V_12 ) ;
#endif
V_541 = F_34 ( V_532 ) ;
if ( V_541 & ( V_543 | V_544 ) ) {
F_33 ( V_545 , V_525 ) ;
V_100 -> V_103 -> V_111 |= V_117 ;
}
if ( V_541 & V_546 ) {
F_33 ( V_539 ,
V_525 ) ;
}
F_67 ( V_5 , V_100 ) ;
}
static int F_169 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 , unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_173 = V_245 -> V_166 ;
unsigned char V_547 , V_548 = 0 ;
if ( V_245 -> V_166 != 2 )
return - V_390 ;
switch ( V_71 [ 0 ] ) {
case V_549 :
V_10 -> V_550 = 1 ;
V_10 -> V_505 |= V_551 ;
if ( V_71 [ 1 ] == V_552 ) {
V_10 -> V_550 = 0 ;
V_10 -> V_505 &= ~ ( V_551 |
V_553 ) ;
V_71 [ 1 ] = V_552 ;
V_10 -> V_511 = V_71 [ 1 ] ;
} else if ( V_71 [ 1 ] <= V_554 ) {
V_10 -> V_505 &= ~ V_555 ;
V_10 -> V_556 |= V_557 ;
V_10 -> V_556 &= ~ V_558 ;
V_71 [ 1 ] = V_554 ;
V_10 -> V_511 = V_71 [ 1 ] ;
} else if ( V_71 [ 1 ] <= V_559 ) {
V_10 -> V_505 &= ~ V_555 ;
V_10 -> V_556 |= V_557 |
V_558 ;
V_71 [ 1 ] = V_559 ;
V_10 -> V_511 = V_71 [ 1 ] ;
} else if ( V_71 [ 1 ] <= V_560 ) {
V_10 -> V_505 |= V_555 ;
V_10 -> V_556 |= V_557 |
V_558 ;
V_71 [ 1 ] = V_560 ;
V_10 -> V_511 = V_71 [ 1 ] ;
} else {
V_10 -> V_505 &= ~ ( V_551 |
V_553 ) ;
V_10 -> V_550 = 0 ;
V_71 [ 1 ] = ( V_71 [ 1 ] / 1000 ) * 1000 ;
V_10 -> V_511 = V_71 [ 1 ] ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_505 ,
V_508 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_556 ,
V_561 ) ;
return 1 ;
break;
case V_562 :
if ( V_10 -> V_511 == 0 )
return - V_390 ;
V_547 = V_71 [ 1 ] & 0xFF ;
if ( V_10 -> V_550 ) {
V_173 = F_170 ( V_5 , V_100 , V_547 ,
& V_548 ) ;
} else if ( V_10 -> V_511 > 0 ) {
V_173 = F_171 ( V_5 , V_100 , V_547 ,
& V_548 ) ;
} else {
F_6 ( L_28 ) ;
return - V_390 ;
}
if ( V_173 < 0 )
return V_173 ;
V_71 [ 1 ] = V_548 & 0xFF ;
return V_245 -> V_166 ;
break;
default:
return - V_390 ;
}
}
static int F_170 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
unsigned char V_563 ,
unsigned char * V_564 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_565 ;
int V_173 = 0 , V_241 = 20 ;
V_10 -> V_512 &= ~ V_566 ;
V_10 -> V_512 |= F_172 ( V_563 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_512 , V_515 ) ;
V_565 = V_10 -> V_73 ( V_5 , V_567 ) ;
if ( V_565 & V_568 ) {
V_173 = - V_42 ;
goto Error;
}
V_10 -> V_505 |= V_569 ;
V_10 -> V_16 ( V_5 , V_10 -> V_505 , V_508 ) ;
V_10 -> V_505 &= ~ V_569 ;
while ( ( V_565 =
V_10 -> V_73 ( V_5 ,
V_567 ) ) &
V_568 ) {
F_60 ( ( V_10 -> V_511 + 999 ) / 1000 ) ;
if ( -- V_241 < 0 ) {
F_6
( L_29 ) ;
V_173 = - V_253 ;
goto Error;
}
}
F_60 ( ( V_10 -> V_511 + 999 ) / 1000 ) ;
if ( V_564 != NULL )
* V_564 = V_10 -> V_73 ( V_5 , V_570 ) ;
Error:
V_10 -> V_16 ( V_5 , V_10 -> V_505 , V_508 ) ;
return V_173 ;
}
static int F_171 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
unsigned char V_563 ,
unsigned char * V_564 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned char V_246 , V_571 = 0 ;
F_60 ( ( V_10 -> V_511 + 999 ) / 1000 ) ;
for ( V_246 = 0x80 ; V_246 ; V_246 >>= 1 ) {
V_10 -> V_512 &= ~ V_510 ;
if ( V_563 & V_246 )
V_10 -> V_512 |= V_510 ;
V_10 -> V_16 ( V_5 , V_10 -> V_512 ,
V_515 ) ;
V_10 -> V_505 |= V_553 ;
V_10 -> V_16 ( V_5 , V_10 -> V_505 ,
V_508 ) ;
F_60 ( ( V_10 -> V_511 + 999 ) / 2000 ) ;
V_10 -> V_505 &= ~ V_553 ;
V_10 -> V_16 ( V_5 , V_10 -> V_505 ,
V_508 ) ;
F_60 ( ( V_10 -> V_511 + 999 ) / 2000 ) ;
if ( V_10 -> V_73 ( V_5 ,
V_516 ) & V_509 ) {
V_571 |= V_246 ;
}
}
if ( V_564 )
* V_564 = V_571 ;
return 0 ;
}
static void F_173 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_10 ) {
if ( V_10 -> V_52 )
F_174 ( V_10 -> V_52 ) ;
}
}
static void F_175 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
int V_106 ;
for ( V_106 = 0 ; V_106 < V_100 -> V_255 ; V_106 ++ ) {
F_38 ( V_5 , F_140 ( V_106 ) | 0x0 ,
V_572 ) ;
}
F_146 ( 0x0 , V_573 ) ;
}
static unsigned F_176 ( enum V_574 V_6 )
{
unsigned V_575 ;
switch ( V_6 ) {
case V_576 :
V_575 = F_177 ( 0 ) ;
break;
case V_577 :
V_575 = F_177 ( 1 ) ;
break;
case V_578 :
V_575 = F_178 ( 0 ) ;
break;
case V_579 :
V_575 = F_178 ( 1 ) ;
break;
case V_580 :
V_575 = F_179 ( 0 ) ;
break;
case V_581 :
V_575 = F_179 ( 1 ) ;
break;
case V_582 :
V_575 = F_180 ( 0 ) ;
break;
case V_583 :
V_575 = F_180 ( 1 ) ;
break;
case V_584 :
V_575 = F_181 ( 0 ) ;
break;
case V_585 :
V_575 = F_181 ( 1 ) ;
break;
case V_586 :
V_575 = F_182 ( 0 ) ;
break;
case V_587 :
V_575 = F_182 ( 1 ) ;
break;
case V_588 :
V_575 = F_183 ( 0 ) ;
break;
case V_589 :
V_575 = F_183 ( 1 ) ;
break;
case V_590 :
V_575 = F_184 ( 0 ) ;
break;
case V_591 :
V_575 = F_184 ( 1 ) ;
break;
case V_592 :
V_575 = V_593 ;
break;
case V_594 :
V_575 = V_211 ;
break;
case V_595 :
V_575 = V_567 ;
break;
case V_596 :
V_575 = V_441 ;
break;
case V_597 :
V_575 = V_129 ;
break;
case V_598 :
V_575 = V_160 ;
break;
case V_599 :
V_575 = V_89 ;
break;
case V_600 :
V_575 = V_90 ;
break;
case V_601 :
V_575 = V_14 ;
break;
case V_602 :
V_575 = V_17 ;
break;
default:
F_6 ( L_30 ,
V_25 , V_6 ) ;
F_2 () ;
return 0 ;
break;
}
return V_575 ;
}
static void F_185 ( struct V_603 * V_604 , unsigned V_72 ,
enum V_574 V_6 )
{
struct V_4 * V_5 = V_604 -> V_52 -> V_5 ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned V_575 ;
static const unsigned V_605 = V_606 | V_607 ;
static const unsigned V_608 =
V_609 | V_610 ;
static const unsigned V_611 =
V_612 | V_613 ;
switch ( V_6 ) {
case V_614 :
F_39 ( V_72 , V_615 ) ;
break;
case V_616 :
F_39 ( V_72 , V_617 ) ;
break;
case V_618 :
F_39 ( V_72 , V_619 ) ;
break;
case V_620 :
F_39 ( V_72 , V_621 ) ;
break;
case V_622 :
F_39 ( V_72 , V_623 ) ;
break;
case V_624 :
F_39 ( V_72 , V_625 ) ;
break;
case V_626 :
F_39 ( V_72 , V_627 ) ;
break;
case V_628 :
F_39 ( V_72 , V_629 ) ;
break;
case V_586 :
case V_587 :
case V_588 :
case V_589 :
V_575 = F_176 ( V_6 ) ;
V_10 -> V_355 ( V_5 , V_72 , V_575 ) ;
break;
case V_601 :
F_17 ( V_72 & ~ V_608 ) ;
F_3 ( V_5 , V_14 ,
V_608 , V_72 ) ;
break;
case V_602 :
F_17 ( V_72 & ~ V_611 ) ;
F_3 ( V_5 , V_17 ,
V_611 , V_72 ) ;
break;
case V_594 :
F_17 ( V_72 & ~ V_605 ) ;
default:
V_575 = F_176 ( V_6 ) ;
V_10 -> V_16 ( V_5 , V_72 , V_575 ) ;
}
}
static unsigned F_186 ( struct V_603 * V_604 ,
enum V_574 V_6 )
{
struct V_4 * V_5 = V_604 -> V_52 -> V_5 ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned V_575 ;
switch ( V_6 ) {
case V_630 :
return F_42 ( V_631 ) ;
case V_632 :
return F_42 ( V_633 ) ;
case V_580 :
case V_581 :
case V_582 :
case V_583 :
V_575 = F_176 ( V_6 ) ;
return V_10 -> V_634 ( V_5 , V_575 ) ;
default:
V_575 = F_176 ( V_6 ) ;
return V_10 -> V_73 ( V_5 , V_575 ) ;
break;
}
return 0 ;
}
static int F_187 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 , unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_71 [ 0 ] = V_10 -> V_556 & V_635 ;
return 1 ;
}
static int F_188 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 , unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_10 -> V_556 &= ~ V_636 ;
V_10 -> V_16 ( V_5 , V_10 -> V_556 ,
V_561 ) ;
V_10 -> V_556 &= ~ V_635 ;
V_10 -> V_556 |= F_189 ( V_71 [ 0 ] ) ;
V_10 -> V_556 |= V_636 ;
V_10 -> V_16 ( V_5 , V_10 -> V_556 ,
V_561 ) ;
return V_245 -> V_166 ;
}
static int F_190 ( struct V_4 * V_5 ,
unsigned int V_637 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
switch ( V_637 ) {
case V_638 :
V_10 -> V_556 &= ~ V_639 ;
break;
case V_640 :
V_10 -> V_556 |= V_639 ;
break;
default:
return - V_390 ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_556 ,
V_561 ) ;
return 3 ;
}
static void F_191 ( struct V_4 * V_5 ,
unsigned int * V_637 ,
unsigned int * V_641 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_10 -> V_556 & V_639 ) {
* V_637 = V_640 ;
* V_641 = V_642 ;
} else {
* V_637 = V_638 ;
* V_641 = V_643 * 2 ;
}
}
static int F_192 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 , unsigned int * V_71 )
{
switch ( V_71 [ 0 ] ) {
case V_644 :
return F_190 ( V_5 , V_71 [ 1 ] ) ;
break;
case V_645 :
F_191 ( V_5 , & V_71 [ 1 ] , & V_71 [ 2 ] ) ;
return 3 ;
default:
break;
}
return - V_390 ;
}
static int F_193 ( struct V_4 * V_5 )
{
struct V_9 * V_10 ;
V_10 = F_194 ( V_5 , sizeof( * V_10 ) ) ;
if ( ! V_10 )
return - V_646 ;
F_195 ( & V_10 -> V_75 ) ;
F_195 ( & V_10 -> V_13 ) ;
F_195 ( & V_10 -> V_38 ) ;
return 0 ;
}
static int F_196 ( int V_43 , int V_647 , int V_71 , unsigned long V_648 )
{
struct V_4 * V_5 = (struct V_4 * ) V_648 ;
struct V_9 * V_10 V_195 = V_5 -> V_11 ;
if ( V_43 ) {
F_5 ( V_71 , V_649 + 2 * V_647 ) ;
return 0 ;
} else {
return F_86 ( V_649 + 2 * V_647 ) ;
}
}
static int F_197 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 , unsigned int * V_71 )
{
V_71 [ 0 ] = F_198 ( V_5 , F_107 ( V_245 -> V_249 ) ) ;
return 1 ;
}
static int F_198 ( struct V_4 * V_5 , int V_74 )
{
struct V_9 * V_10 V_195 = V_5 -> V_11 ;
int V_650 ;
int V_651 ;
V_651 = 0x0300 | ( ( V_74 & 0x100 ) << 3 ) | ( V_74 & 0xff ) ;
F_5 ( 0x04 , V_652 ) ;
for ( V_650 = 0x8000 ; V_650 ; V_650 >>= 1 ) {
F_5 ( 0x04 | ( ( V_650 & V_651 ) ? 0x02 : 0 ) ,
V_652 ) ;
F_5 ( 0x05 | ( ( V_650 & V_651 ) ? 0x02 : 0 ) ,
V_652 ) ;
}
V_651 = 0 ;
for ( V_650 = 0x80 ; V_650 ; V_650 >>= 1 ) {
F_5 ( 0x04 , V_652 ) ;
F_5 ( 0x05 , V_652 ) ;
V_651 |= ( ( F_86 ( V_196 ) & V_653 ) ? V_650 : 0 ) ;
}
F_5 ( 0x00 , V_652 ) ;
return V_651 ;
}
static int F_199 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 ,
unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_71 [ 0 ] = V_10 -> V_654 [ F_107 ( V_245 -> V_249 ) ] ;
return 1 ;
}
static int F_200 ( struct V_4 * V_5 , unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_71 [ 1 ] = V_10 -> V_655 * V_10 -> V_308 ;
V_71 [ 2 ] = V_10 -> V_656 * V_10 -> V_308 ;
return 3 ;
}
static int F_201 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 , unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned V_657 , V_658 ;
switch ( V_71 [ 0 ] ) {
case V_659 :
switch ( V_71 [ 1 ] ) {
case V_307 :
V_657 =
( V_71 [ 2 ] +
V_10 -> V_308 / 2 ) / V_10 -> V_308 ;
break;
case V_309 :
V_657 = V_71 [ 2 ] / V_10 -> V_308 ;
break;
case V_310 :
V_657 =
( V_71 [ 2 ] + V_10 -> V_308 -
1 ) / V_10 -> V_308 ;
break;
default:
return - V_390 ;
break;
}
switch ( V_71 [ 3 ] ) {
case V_307 :
V_658 =
( V_71 [ 4 ] +
V_10 -> V_308 / 2 ) / V_10 -> V_308 ;
break;
case V_309 :
V_658 = V_71 [ 4 ] / V_10 -> V_308 ;
break;
case V_310 :
V_658 =
( V_71 [ 4 ] + V_10 -> V_308 -
1 ) / V_10 -> V_308 ;
break;
default:
return - V_390 ;
break;
}
if ( V_657 * V_10 -> V_308 != V_71 [ 2 ] ||
V_658 * V_10 -> V_308 != V_71 [ 4 ] ) {
V_71 [ 2 ] = V_657 * V_10 -> V_308 ;
V_71 [ 4 ] = V_658 * V_10 -> V_308 ;
return - V_405 ;
}
F_33 ( F_202 ( V_657 ) |
F_203 ( V_658 ) ,
V_660 ) ;
V_10 -> V_655 = V_657 ;
V_10 -> V_656 = V_658 ;
return 5 ;
break;
case V_661 :
return F_200 ( V_5 , V_71 ) ;
break;
default:
return - V_390 ;
break;
}
return 0 ;
}
static int F_204 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 , unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned V_657 , V_658 ;
switch ( V_71 [ 0 ] ) {
case V_659 :
switch ( V_71 [ 1 ] ) {
case V_307 :
V_657 =
( V_71 [ 2 ] +
V_10 -> V_308 / 2 ) / V_10 -> V_308 ;
break;
case V_309 :
V_657 = V_71 [ 2 ] / V_10 -> V_308 ;
break;
case V_310 :
V_657 =
( V_71 [ 2 ] + V_10 -> V_308 -
1 ) / V_10 -> V_308 ;
break;
default:
return - V_390 ;
break;
}
switch ( V_71 [ 3 ] ) {
case V_307 :
V_658 =
( V_71 [ 4 ] +
V_10 -> V_308 / 2 ) / V_10 -> V_308 ;
break;
case V_309 :
V_658 = V_71 [ 4 ] / V_10 -> V_308 ;
break;
case V_310 :
V_658 =
( V_71 [ 4 ] + V_10 -> V_308 -
1 ) / V_10 -> V_308 ;
break;
default:
return - V_390 ;
break;
}
if ( V_657 * V_10 -> V_308 != V_71 [ 2 ] ||
V_658 * V_10 -> V_308 != V_71 [ 4 ] ) {
V_71 [ 2 ] = V_657 * V_10 -> V_308 ;
V_71 [ 4 ] = V_658 * V_10 -> V_308 ;
return - V_405 ;
}
F_33 ( V_657 , V_662 ) ;
V_10 -> V_655 = V_657 ;
F_33 ( V_658 , V_663 ) ;
V_10 -> V_656 = V_658 ;
return 5 ;
break;
case V_661 :
return F_200 ( V_5 , V_71 ) ;
default:
return - V_390 ;
break;
}
return 0 ;
}
static int F_205 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 , unsigned int * V_71 )
{
F_206 ( V_5 , F_107 ( V_245 -> V_249 ) , V_71 [ 0 ] ) ;
return 1 ;
}
static int F_207 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 , unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_71 [ 0 ] = V_10 -> V_664 [ F_107 ( V_245 -> V_249 ) ] ;
return 1 ;
}
static void F_208 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
int V_106 , V_665 ;
int V_666 ;
int V_408 = 0 ;
int V_667 ;
int V_668 = 0 ;
int type ;
int V_170 ;
type = V_59 -> V_669 [ 0 ] ;
if ( type == V_670 )
return;
V_667 = V_664 [ type ] . V_667 ;
for ( V_106 = 0 ; V_106 < 3 ; V_106 ++ ) {
type = V_59 -> V_669 [ V_106 ] ;
if ( type == V_670 )
break;
if ( V_664 [ type ] . V_667 != V_667 )
V_668 = 1 ;
V_408 += V_664 [ type ] . V_408 ;
}
V_666 = V_106 ;
V_100 -> V_255 = V_408 ;
if ( V_668 ) {
unsigned int * V_671 ;
if ( V_408 > V_672 )
F_6 ( L_31 ) ;
V_100 -> V_671 = V_671 = V_10 -> V_673 ;
V_170 = 0 ;
for ( V_106 = 0 ; V_106 < V_666 ; V_106 ++ ) {
type = V_59 -> V_669 [ V_106 ] ;
for ( V_665 = 0 ; V_665 < V_664 [ type ] . V_408 ; V_665 ++ ) {
V_671 [ V_170 ] =
( 1 << V_664 [ type ] . V_667 ) - 1 ;
V_170 ++ ;
}
}
for ( V_170 = 0 ; V_170 < V_100 -> V_255 ; V_170 ++ )
F_206 ( V_5 , V_106 , V_100 -> V_671 [ V_106 ] / 2 ) ;
} else {
type = V_59 -> V_669 [ 0 ] ;
V_100 -> V_674 = ( 1 << V_664 [ type ] . V_667 ) - 1 ;
for ( V_170 = 0 ; V_170 < V_100 -> V_255 ; V_170 ++ )
F_206 ( V_5 , V_106 , V_100 -> V_674 / 2 ) ;
}
}
static void F_206 ( struct V_4 * V_5 , int V_74 , int V_675 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_676 = 0 , V_72 = 0 , V_650 , V_651 = 0 ;
int V_106 ;
int type ;
if ( V_10 -> V_664 [ V_74 ] == V_675 )
return;
V_10 -> V_664 [ V_74 ] = V_675 ;
for ( V_106 = 0 ; V_106 < 3 ; V_106 ++ ) {
type = V_59 -> V_669 [ V_106 ] ;
if ( type == V_670 )
break;
if ( V_74 < V_664 [ type ] . V_408 ) {
V_72 = V_664 [ type ] . F_209 ( V_74 , V_675 , & V_651 ) ;
V_676 = F_210 ( V_106 ) ;
break;
}
V_74 -= V_664 [ type ] . V_408 ;
}
for ( V_650 = 1 << ( V_72 - 1 ) ; V_650 ; V_650 >>= 1 ) {
F_5 ( ( ( V_650 & V_651 ) ? 0x02 : 0 ) , V_652 ) ;
F_60 ( 1 ) ;
F_5 ( 1 | ( ( V_650 & V_651 ) ? 0x02 : 0 ) , V_652 ) ;
F_60 ( 1 ) ;
}
F_5 ( V_676 , V_652 ) ;
F_60 ( 1 ) ;
F_5 ( 0 , V_652 ) ;
}
static int F_211 ( int V_74 , int V_675 , int * V_651 )
{
V_74 ++ ;
* V_651 = ( ( V_74 & 0x1 ) << 11 ) |
( ( V_74 & 0x2 ) << 9 ) |
( ( V_74 & 0x4 ) << 7 ) | ( ( V_74 & 0x8 ) << 5 ) | ( V_675 & 0xff ) ;
return 12 ;
}
static int F_212 ( int V_74 , int V_675 , int * V_651 )
{
* V_651 = ( ( V_74 & 0x7 ) << 8 ) | ( V_675 & 0xff ) ;
return 11 ;
}
static int F_213 ( int V_74 , int V_675 , int * V_651 )
{
* V_651 = V_675 & 0xfff ;
return 12 ;
}
static int F_214 ( int V_74 , int V_675 , int * V_651 )
{
* V_651 = ( V_675 & 0xfff ) | ( V_74 ? 0xc000 : 0xa000 ) ;
return 16 ;
}
static int F_215 ( int V_74 , int V_675 , int * V_651 )
{
* V_651 = ( ( V_74 & 0xf ) << 8 ) | ( V_675 & 0xff ) ;
return 12 ;
}
static int F_216 ( int V_74 , int V_675 , int * V_651 )
{
* V_651 = ( ( V_74 + 1 ) << 8 ) | ( V_675 & 0xff ) ;
return 12 ;
}
static int F_217 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
struct V_603 * V_604 = V_100 -> V_11 ;
int V_192 ;
V_192 = F_21 ( V_5 , V_604 -> V_1 ,
V_44 ) ;
if ( V_192 ) {
F_19 ( V_5 ,
L_32 ) ;
return V_192 ;
}
F_218 ( V_604 , NULL , NULL , NULL , NULL ) ;
F_30 ( V_5 , V_604 -> V_1 , 1 ) ;
return F_219 ( V_5 , V_100 ) ;
}
static int F_70 ( struct V_4 * V_5 , struct V_99 * V_100 )
{
#ifdef F_24
struct V_603 * V_604 = V_100 -> V_11 ;
int V_192 ;
V_192 = F_220 ( V_604 ) ;
F_30 ( V_5 , V_604 -> V_1 , 0 ) ;
F_28 ( V_5 , V_604 -> V_1 ) ;
return V_192 ;
#else
return 0 ;
#endif
}
static int F_221 ( struct V_4 * V_5 , unsigned V_170 ,
unsigned V_677 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned V_678 ;
unsigned V_679 ;
if ( ( V_677 & 0x1f ) != V_677 )
return - V_390 ;
V_678 = 1 + V_170 / 3 ;
V_679 = V_678 - 1 ;
V_10 -> V_680 [ V_679 ] &=
~ F_222 ( V_170 ) ;
V_10 -> V_680 [ V_679 ] |=
F_223 ( V_170 , V_677 ) ;
F_39 ( V_10 -> V_680 [ V_679 ] ,
F_224 ( V_678 ) ) ;
return 2 ;
}
static int F_225 ( struct V_4 * V_5 , unsigned V_170 ,
unsigned V_677 )
{
if ( V_677 != F_226 ( V_5 , V_170 ) )
return - V_390 ;
return 2 ;
}
static int F_227 ( struct V_4 * V_5 , unsigned V_170 ,
unsigned V_677 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
if ( V_59 -> V_60 & V_61 )
return F_221 ( V_5 , V_170 , V_677 ) ;
else
return F_225 ( V_5 , V_170 , V_677 ) ;
}
static unsigned F_228 ( struct V_4 * V_5 ,
unsigned V_170 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
const unsigned V_679 = V_170 / 3 ;
return F_229 ( V_170 ,
V_10 ->
V_680
[ V_679 ] ) ;
}
static unsigned F_226 ( struct V_4 * V_5 , unsigned V_170 )
{
switch ( V_170 ) {
case 0 :
return V_681 ;
break;
case 1 :
return V_682 ;
break;
case 2 :
return V_683 ;
break;
case 3 :
return V_684 ;
break;
case 4 :
return V_685 ;
break;
case 5 :
return V_686 ;
break;
case 6 :
return V_687 ;
break;
case 7 :
return V_688 ;
break;
case 8 :
return V_689 ;
break;
case 9 :
return V_690 ;
break;
default:
F_6 ( L_33 , V_25 ) ;
break;
}
return 0 ;
}
static unsigned F_230 ( struct V_4 * V_5 , unsigned V_170 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
if ( V_59 -> V_60 & V_61 )
return F_228 ( V_5 , V_170 ) ;
else
return F_226 ( V_5 , V_170 ) ;
}
static int F_231 ( struct V_4 * V_5 , unsigned V_691 ,
enum V_692 V_693 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 V_195 = V_5 -> V_11 ;
unsigned V_72 ;
if ( ( V_59 -> V_60 & V_61 ) == 0 )
return - V_694 ;
V_72 = F_34 ( V_695 ) ;
V_72 &= ~ F_232 ( V_691 ) ;
V_72 |= F_233 ( V_691 , V_693 ) ;
F_33 ( V_72 , V_695 ) ;
return 0 ;
}
static int F_234 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 ,
unsigned int * V_71 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 V_195 = V_5 -> V_11 ;
if ( ! ( V_59 -> V_60 & V_61 ) )
return - V_694 ;
if ( F_162 ( V_100 , V_71 ) )
F_39 ( V_100 -> V_514 , V_696 ) ;
V_71 [ 1 ] = F_42 ( V_697 ) ;
return V_245 -> V_166 ;
}
static int F_235 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 , unsigned int * V_71 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_170 ;
if ( V_245 -> V_166 < 1 )
return - V_390 ;
V_170 = F_107 ( V_245 -> V_249 ) ;
switch ( V_71 [ 0 ] ) {
case V_47 :
F_43 ( V_5 , V_19 , 1 << V_170 , 1 ) ;
break;
case V_44 :
F_43 ( V_5 , V_19 , 1 << V_170 , 0 ) ;
break;
case V_698 :
V_71 [ 1 ] =
( V_10 -> V_20 & ( 1 << V_170 ) ) ?
V_47 : V_44 ;
return 0 ;
break;
case V_699 :
return F_227 ( V_5 , V_170 , V_71 [ 1 ] ) ;
break;
case V_700 :
V_71 [ 1 ] = F_230 ( V_5 , V_170 ) ;
break;
case V_701 :
return F_231 ( V_5 , V_170 , V_71 [ 1 ] ) ;
break;
default:
return - V_390 ;
}
return 0 ;
}
static void F_236 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
V_10 -> V_702 = V_703 ;
if ( F_237 ( V_5 , V_704 , 0 ) < 0 )
F_6 ( L_34 ) ;
V_10 -> V_705 =
F_238 ( 0 ,
V_706 ) |
F_238 ( 1 ,
V_707 ) |
F_238 ( 2 ,
V_708 ) |
F_238 ( 3 , V_709 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_705 ,
V_710 ) ;
V_10 -> V_711 =
F_238 ( 4 ,
V_712 ) |
F_238 ( 5 ,
V_713 ) |
F_238 ( 6 , V_714 ) ;
if ( V_59 -> V_60 & V_61 )
V_10 -> V_711 |=
F_238 ( 7 , V_715 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_711 ,
V_716 ) ;
}
static int F_239 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 , unsigned int * V_71 )
{
V_71 [ 1 ] = 0 ;
return V_245 -> V_166 ;
}
static int F_240 ( unsigned V_717 ,
unsigned * V_718 ,
unsigned * V_719 ,
unsigned * V_720 )
{
unsigned div ;
unsigned V_721 = 1 ;
static const unsigned V_722 = 0x10 ;
unsigned V_723 ;
unsigned V_724 = 1 ;
static const unsigned V_725 = 0x100 ;
static const unsigned V_726 = 1000 ;
const unsigned V_727 = V_717 * V_726 ;
static const unsigned V_728 = 12500 ;
static const unsigned V_729 = 4 ;
int V_730 = 0 ;
for ( div = 1 ; div <= V_722 ; ++ div ) {
for ( V_723 = 1 ; V_723 <= V_725 ; ++ V_723 ) {
unsigned V_731 =
( V_727 * div ) / V_723 ;
if ( abs ( V_731 - V_728 ) <
abs ( V_730 - V_728 ) ) {
V_730 = V_731 ;
V_721 = div ;
V_724 = V_723 ;
}
}
}
if ( V_730 == 0 ) {
F_6 ( L_35 , V_25 ) ;
return - V_206 ;
}
* V_718 = V_721 ;
* V_719 = V_724 ;
* V_720 =
( V_730 * V_729 +
( V_726 / 2 ) ) / V_726 ;
return 0 ;
}
static inline unsigned F_241 ( struct V_4 * V_5 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
if ( V_59 -> V_60 & V_61 )
return 8 ;
else
return 7 ;
}
static int F_242 ( struct V_4 * V_5 ,
unsigned V_677 , unsigned V_732 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
static const unsigned V_733 = 50 ;
static const unsigned V_734 = 1000 ;
static const unsigned V_105 = 1000 ;
unsigned V_735 ;
unsigned V_718 ;
unsigned V_719 ;
unsigned V_106 ;
int V_192 ;
if ( V_677 == V_736 )
V_732 = 100 ;
if ( V_732 < V_733 || V_732 > V_734 ) {
F_6
( L_36
L_37 , V_25 ,
V_733 , V_734 ) ;
return - V_390 ;
}
V_10 -> V_737 &= ~ V_738 ;
V_10 -> V_16 ( V_5 , V_10 -> V_737 ,
V_739 ) ;
V_735 =
V_740 | V_741 ;
V_10 -> V_702 |=
V_742 | V_743 ;
V_10 -> V_702 &= ~ V_744 ;
switch ( V_677 ) {
case V_745 :
V_10 -> V_702 |=
V_746 ;
V_192 = F_240 ( V_732 , & V_718 ,
& V_719 ,
& V_10 -> V_308 ) ;
if ( V_192 < 0 )
return V_192 ;
break;
case V_736 :
V_10 -> V_702 |=
V_747 ;
V_192 = F_240 ( V_732 , & V_718 ,
& V_719 ,
& V_10 -> V_308 ) ;
if ( V_192 < 0 )
return V_192 ;
break;
default:
{
unsigned V_748 ;
static const unsigned V_749 = 7 ;
for ( V_748 = 0 ; V_748 <= V_749 ;
++ V_748 ) {
if ( V_677 ==
F_243 ( V_748 ) ) {
V_10 -> V_702 |=
F_244
( V_748 ) ;
break;
}
}
if ( V_748 > V_749 )
return - V_390 ;
V_192 = F_240 ( V_732 ,
& V_718 ,
& V_719 ,
& V_10 ->
V_308 ) ;
if ( V_192 < 0 )
return V_192 ;
}
break;
}
F_39 ( V_10 -> V_702 , V_750 ) ;
V_735 |=
F_245 ( V_718 ) |
F_246 ( V_719 ) ;
F_39 ( V_735 , V_751 ) ;
V_10 -> V_637 = V_677 ;
for ( V_106 = 0 ; V_106 < V_105 ; ++ V_106 ) {
if ( F_42 ( V_752 ) & V_753 )
break;
F_60 ( 1 ) ;
}
if ( V_106 == V_105 ) {
F_6
( L_38 ,
V_25 , V_677 , V_732 ) ;
return - V_754 ;
}
return 3 ;
}
static int F_237 ( struct V_4 * V_5 , unsigned V_677 ,
unsigned V_732 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_677 == V_704 ) {
V_10 -> V_737 &= ~ V_738 ;
V_10 -> V_16 ( V_5 , V_10 -> V_737 ,
V_739 ) ;
V_10 -> V_308 = V_643 ;
if ( V_59 -> V_60 & V_61 ) {
V_10 -> V_702 &=
~ ( V_742 |
V_743 ) ;
F_39 ( V_10 -> V_702 ,
V_750 ) ;
F_39 ( 0 , V_751 ) ;
}
V_10 -> V_637 = V_677 ;
} else {
if ( V_59 -> V_60 & V_61 ) {
return F_242 ( V_5 , V_677 ,
V_732 ) ;
} else {
if ( V_677 == V_755 ) {
V_10 -> V_737 |=
V_738 ;
V_10 -> V_16 ( V_5 ,
V_10 ->
V_737 ,
V_739 ) ;
if ( V_732 == 0 ) {
F_6
( L_39 ,
V_25 ) ;
return - V_390 ;
} else {
V_10 -> V_308 = V_732 ;
}
V_10 -> V_637 = V_677 ;
} else
return - V_390 ;
}
}
return 3 ;
}
static int F_247 ( struct V_4 * V_5 , unsigned V_170 ,
unsigned V_677 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
if ( V_170 >= F_241 ( V_5 ) ) {
if ( V_170 == V_756 ) {
if ( V_677 == V_715 )
return 1 ;
else {
F_6
( L_40 ,
V_25 , V_170 , V_756 ) ;
return 0 ;
}
}
return 0 ;
}
switch ( V_677 ) {
case V_706 :
case V_707 :
case V_708 :
case V_709 :
case V_712 :
case V_713 :
case V_714 :
case V_757 :
case V_758 :
return 1 ;
break;
case V_715 :
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
static int F_248 ( struct V_4 * V_5 , unsigned V_170 ,
unsigned V_677 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( F_247 ( V_5 , V_170 , V_677 ) == 0 )
return - V_390 ;
if ( V_170 < 4 ) {
V_10 -> V_705 &= ~ F_249 ( V_170 ) ;
V_10 -> V_705 |=
F_238 ( V_170 , V_677 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_705 ,
V_710 ) ;
} else if ( V_170 < 8 ) {
V_10 -> V_711 &= ~ F_249 ( V_170 ) ;
V_10 -> V_711 |=
F_238 ( V_170 , V_677 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_711 ,
V_716 ) ;
}
return 2 ;
}
static unsigned F_250 ( struct V_4 * V_5 , unsigned V_170 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_170 < 4 ) {
return F_251 ( V_170 ,
V_10 -> V_705 ) ;
} else if ( V_170 < F_241 ( V_5 ) ) {
return F_251 ( V_170 ,
V_10 -> V_711 ) ;
} else {
if ( V_170 == V_756 )
return V_715 ;
F_6 ( L_41 , V_25 ) ;
return 0 ;
}
}
static int F_252 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 , unsigned int * V_71 )
{
const struct V_58 * V_59 = F_31 ( V_5 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_170 = F_107 ( V_245 -> V_249 ) ;
switch ( V_71 [ 0 ] ) {
case V_759 :
if ( V_170 < F_241 ( V_5 ) ) {
V_10 -> V_737 |=
F_253 ( V_170 ,
( V_59 -> V_60 & V_61 ) != 0 ) ;
} else if ( V_170 == V_756 ) {
V_10 -> V_737 |=
V_760 ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_737 ,
V_739 ) ;
break;
case V_761 :
if ( V_170 < F_241 ( V_5 ) ) {
V_10 -> V_737 &=
~ F_253 ( V_170 ,
( V_59 -> V_60 & V_61 ) != 0 ) ;
} else if ( V_170 == V_756 ) {
V_10 -> V_737 &=
~ V_760 ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_737 ,
V_739 ) ;
break;
case V_698 :
if ( V_170 < F_241 ( V_5 ) ) {
V_71 [ 1 ] =
( V_10 -> V_737 &
F_253 ( V_170 ,
( V_59 -> V_60 & V_61 ) != 0 ) )
? V_759
: V_761 ;
} else if ( V_170 == V_756 ) {
V_71 [ 1 ] =
( V_10 -> V_737 &
V_760 )
? V_759 : V_761 ;
}
return 2 ;
break;
case V_644 :
return F_237 ( V_5 , V_71 [ 1 ] , V_71 [ 2 ] ) ;
break;
case V_645 :
V_71 [ 1 ] = V_10 -> V_637 ;
V_71 [ 2 ] = V_10 -> V_308 ;
return 3 ;
break;
case V_699 :
return F_248 ( V_5 , V_170 , V_71 [ 1 ] ) ;
break;
case V_700 :
V_71 [ 1 ] = F_250 ( V_5 , V_170 ) ;
return 2 ;
break;
default:
return - V_390 ;
break;
}
return 1 ;
}
static int F_254 ( struct V_4 * V_5 )
{
unsigned short V_130 ;
const int V_105 = V_762 ;
int V_106 ;
for ( V_106 = 0 ; V_106 < V_105 ; V_106 ++ ) {
V_130 = F_41 ( V_5 , V_763 ) ;
if ( ( V_130 & V_764 ) == 0 )
break;
F_255 ( V_765 ) ;
if ( F_256 ( 1 ) )
return - V_206 ;
}
if ( V_106 == V_105 ) {
F_6 ( L_42 , __FILE__ , V_25 ) ;
return - V_253 ;
}
return 0 ;
}
static void F_257 ( struct V_4 * V_5 , unsigned short V_78 )
{
static const int V_105 = 100 ;
int V_106 ;
F_38 ( V_5 , V_78 , V_766 ) ;
for ( V_106 = 0 ; V_106 < V_105 ; V_106 ++ ) {
if ( ( F_41 ( V_5 , V_763 ) & V_764 ) )
break;
F_60 ( 1 ) ;
}
if ( V_106 == V_105 )
F_19 ( V_5 , L_43 ) ;
}
static void F_258 ( struct V_4 * V_5 , unsigned int V_78 ,
unsigned int V_767 )
{
F_38 ( V_5 , ( ( V_78 >> 16 ) & 0xff ) ,
V_768 ) ;
F_38 ( V_5 , ( V_78 & 0xffff ) ,
V_769 ) ;
V_767 &= V_770 ;
F_257 ( V_5 , V_771 | V_767 ) ;
if ( F_254 ( V_5 ) )
F_19 ( V_5 , L_44 ) ;
}
static int F_259 ( struct V_4 * V_5 , unsigned short * V_71 )
{
int V_192 ;
unsigned short V_130 ;
F_257 ( V_5 , V_771 | V_772 ) ;
V_192 = F_254 ( V_5 ) ;
if ( V_192 ) {
F_19 ( V_5 ,
L_45 ) ;
return - V_253 ;
}
V_130 = F_41 ( V_5 , V_763 ) ;
if ( V_130 & V_773 ) {
F_6
( L_46 ) ;
return - V_206 ;
}
if ( V_130 & V_774 ) {
F_6
( L_47 ) ;
}
if ( V_71 ) {
* V_71 = F_41 ( V_5 , V_775 ) ;
* V_71 ^= ( 1 << 15 ) ;
}
return 0 ;
}
static int F_260 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
struct V_244 * V_245 , unsigned int * V_71 )
{
int V_166 , V_192 ;
unsigned short V_776 ;
unsigned int V_777 ;
const unsigned int V_778 = 0x1000 ;
if ( V_245 -> V_249 & V_262 )
V_777 = V_778 ;
else
V_777 = F_107 ( V_245 -> V_249 ) ;
F_38 ( V_5 , V_777 , V_779 ) ;
for ( V_166 = 0 ; V_166 < V_245 -> V_166 ; V_166 ++ ) {
V_192 = F_259 ( V_5 , & V_776 ) ;
if ( V_192 < 0 )
return V_192 ;
V_71 [ V_166 ] = V_776 ;
}
return V_245 -> V_166 ;
}
static int F_261 ( struct V_4 * V_5 )
{
unsigned int V_276 =
V_780 | V_781 ;
#if 1
F_258 ( V_5 , V_276 | V_782 ,
V_783 ) ;
F_259 ( V_5 , NULL ) ;
#else
F_258 ( V_5 , 0x400000 , V_784 ) ;
F_258 ( V_5 , V_276 | V_785 ,
V_783 ) ;
if ( F_254 ( V_5 ) )
F_19 ( V_5 , L_48 ) ;
#endif
return 0 ;
}

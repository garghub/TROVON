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
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_58 . V_59 & V_60 )
return;
switch ( V_32 ) {
case 0 :
if ( V_57 ) {
V_10 -> V_16 ( V_5 , V_61 ,
V_62 ) ;
} else {
V_10 -> V_16 ( V_5 , 0 ,
V_62 ) ;
}
break;
case 1 :
if ( V_57 ) {
V_10 -> V_16 ( V_5 , V_63 ,
V_64 ) ;
} else {
V_10 -> V_16 ( V_5 , 0 ,
V_64 ) ;
}
break;
default:
F_2 () ;
break;
}
}
static void F_31 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_58 . V_59 == V_65 ) {
F_32 ( 0x10 , V_66 ) ;
F_32 ( 0x00 , V_66 ) ;
while ( F_33 ( V_67 ) & 0x10 ) ;
} else {
V_10 -> V_16 ( V_5 , 1 , V_68 ) ;
if ( V_58 . V_59 == V_69 ) {
F_5 ( 0 , F_34 ( 0 ) ) ;
F_5 ( 1 , F_34 ( 0 ) ) ;
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
static void F_35 ( struct V_4 * V_5 , T_1 V_70 , int V_6 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_10 -> V_16 ( V_5 , V_70 >> 16 , V_6 ) ;
V_10 -> V_16 ( V_5 , V_70 & 0xffff , V_6 + 1 ) ;
}
static T_1 F_36 ( struct V_4 * V_5 , int V_6 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
T_1 V_71 ;
V_71 = V_10 -> V_72 ( V_5 , V_6 ) << 16 ;
V_71 |= V_10 -> V_72 ( V_5 , V_6 + 1 ) ;
return V_71 ;
}
static inline void F_37 ( struct V_4 * V_5 , T_2 V_70 ,
int V_73 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_12 ;
F_4 ( & V_10 -> V_74 , V_12 ) ;
F_38 ( V_73 , V_75 ) ;
F_38 ( V_70 , V_76 ) ;
F_8 ( & V_10 -> V_74 , V_12 ) ;
}
static inline void F_39 ( struct V_4 * V_5 , T_1 V_70 ,
int V_73 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_12 ;
F_4 ( & V_10 -> V_74 , V_12 ) ;
F_38 ( V_73 , V_75 ) ;
F_32 ( V_70 , V_76 ) ;
F_8 ( & V_10 -> V_74 , V_12 ) ;
}
static inline unsigned short F_40 ( struct V_4 * V_5 , int V_73 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_12 ;
unsigned short V_70 ;
F_4 ( & V_10 -> V_74 , V_12 ) ;
F_38 ( V_73 , V_75 ) ;
V_70 = F_41 ( V_76 ) ;
F_8 ( & V_10 -> V_74 , V_12 ) ;
return V_70 ;
}
static inline void F_42 ( struct V_4 * V_5 , int V_6 ,
unsigned V_71 , unsigned V_77 )
{
unsigned V_8 ;
if ( V_77 )
V_8 = V_71 ;
else
V_8 = 0 ;
F_3 ( V_5 , V_6 , V_71 , V_8 ) ;
}
static T_3 F_43 ( int V_78 , void * V_79 )
{
struct V_4 * V_5 = V_79 ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned short V_80 ;
unsigned short V_81 ;
unsigned int V_82 = 0 ;
unsigned int V_83 = 0 ;
unsigned long V_12 ;
#ifdef F_24
struct V_84 * V_40 = V_10 -> V_40 ;
#endif
if ( V_5 -> V_85 == 0 )
return V_86 ;
F_44 () ;
F_4 ( & V_5 -> V_87 , V_12 ) ;
V_80 = V_10 -> V_72 ( V_5 , V_88 ) ;
V_81 = V_10 -> V_72 ( V_5 , V_89 ) ;
#ifdef F_24
if ( V_40 ) {
unsigned long V_90 ;
F_4 ( & V_10 -> V_38 , V_90 ) ;
if ( V_10 -> V_39 ) {
V_82 = F_45 ( V_10 -> V_39 ) ;
if ( V_82 & V_91 )
F_46 ( V_92 ,
V_10 -> V_40 -> V_93 +
F_47 ( V_10 ->
V_39 -> V_26 ) ) ;
}
if ( V_10 -> V_45 ) {
V_83 = F_45 ( V_10 -> V_45 ) ;
if ( V_83 & V_91 )
F_46 ( V_92 ,
V_40 -> V_93 +
F_47 ( V_10 ->
V_45 -> V_26 ) ) ;
}
F_8 ( & V_10 -> V_38 , V_90 ) ;
}
#endif
F_48 ( V_5 , V_80 ) ;
F_49 ( V_5 , V_81 ) ;
if ( ( V_80 & V_94 ) || ( V_82 & V_95 ) )
F_50 ( V_5 , V_80 , V_82 ) ;
if ( ( V_81 & V_96 ) || ( V_83 & V_95 ) )
F_51 ( V_5 , V_81 , V_83 ) ;
F_52 ( V_5 , 0 ) ;
F_52 ( V_5 , 1 ) ;
F_53 ( V_5 ) ;
F_8 ( & V_5 -> V_87 , V_12 ) ;
return V_97 ;
}
static void F_54 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_98 * V_99 = & V_5 -> V_100 [ V_101 ] ;
unsigned long V_12 ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_39 )
F_55 ( V_10 -> V_39 , V_99 -> V_102 ) ;
F_8 ( & V_10 -> V_38 , V_12 ) ;
}
static void F_56 ( struct V_84 * V_40 ,
struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_98 * V_99 = & V_5 -> V_100 [ V_103 ] ;
unsigned long V_12 ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_45 ) {
F_57 ( V_10 -> V_45 , V_99 -> V_102 ) ;
}
F_8 ( & V_10 -> V_38 , V_12 ) ;
}
static int F_58 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
static const int V_104 = 10000 ;
int V_105 ;
for ( V_105 = 0 ; V_105 < V_104 ; V_105 ++ ) {
unsigned short V_81 ;
V_81 = V_10 -> V_72 ( V_5 , V_89 ) ;
if ( V_81 & V_106 )
break;
F_59 ( 10 ) ;
}
if ( V_105 == V_104 ) {
F_19 ( V_5 , L_7 ) ;
return - V_107 ;
}
return 0 ;
}
static void F_60 ( struct V_4 * V_5 , struct V_98 * V_99 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_10 -> V_108 == V_109 ) {
#ifdef F_24
static const int V_104 = 10 ;
int V_105 ;
for ( V_105 = 0 ; V_105 < V_104 ; V_105 ++ ) {
F_54 ( V_5 ) ;
if ( ( V_99 -> V_102 -> V_110 & V_111 ) )
break;
F_59 ( 1 ) ;
}
#else
F_61 ( V_5 ) ;
V_99 -> V_102 -> V_110 |= V_111 ;
#endif
}
if ( ( V_10 -> V_112 & V_113 ) ) {
F_62 ( V_5 ) ;
}
}
static void F_62 ( struct V_4 * V_5 )
{
struct V_98 * V_99 = & V_5 -> V_100 [ V_101 ] ;
#ifdef F_24
F_63 ( V_5 ) ;
#endif
F_61 ( V_5 ) ;
F_64 ( V_5 ) ;
F_65 ( V_5 ) ;
V_99 -> V_102 -> V_110 |= V_114 ;
}
static void F_66 ( struct V_4 * V_5 , struct V_98 * V_99 )
{
if ( V_99 ->
V_102 -> V_110 & ( V_115 | V_116 |
V_114 ) ) {
switch ( V_99 - V_5 -> V_100 ) {
case V_101 :
F_67 ( V_5 , V_99 ) ;
break;
case V_103 :
F_68 ( V_5 , V_99 ) ;
break;
case V_2 :
case V_3 :
F_69 ( V_5 , V_99 ) ;
break;
case V_117 :
F_70 ( V_5 , V_99 ) ;
break;
default:
break;
}
}
F_71 ( V_5 , V_99 ) ;
}
static void F_52 ( struct V_4 * V_5 ,
unsigned short V_1 )
{
#ifdef F_24
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_98 * V_99 ;
V_99 = & V_5 -> V_100 [ F_1 ( V_1 ) ] ;
F_72 ( & V_10 -> V_52 -> V_53 [ V_1 ] ,
V_99 ) ;
if ( V_99 -> V_102 -> V_110 )
F_66 ( V_5 , V_99 ) ;
#endif
}
static void F_48 ( struct V_4 * V_5 , unsigned short V_80 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned short V_118 = 0 ;
if ( V_80 & V_119 ) {
V_118 |= V_120 ;
}
if ( V_80 & V_121 ) {
V_118 |= V_122 ;
}
if ( V_80 & V_123 ) {
V_118 |= V_124 ;
}
if ( V_80 & V_125 ) {
V_118 |= V_126 ;
}
if ( V_118 )
V_10 -> V_16 ( V_5 , V_118 , V_127 ) ;
}
static void F_50 ( struct V_4 * V_5 , unsigned short V_128 ,
unsigned V_82 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_98 * V_99 = & V_5 -> V_100 [ V_101 ] ;
if ( V_99 -> type == V_129 )
return;
#ifdef F_73
F_6
( L_8 ,
V_128 , V_82 ) ;
F_74 ( V_128 ) ;
#endif
#ifdef F_24
if ( V_82 & V_91 ) {
F_54 ( V_5 ) ;
}
if ( V_82 & ~ ( V_95 | V_91 | V_130 | V_131 |
V_132 | V_133 | V_134 | V_135 |
V_136 | V_137 | V_138 ) ) {
F_6
( L_9 ,
V_82 ) ;
V_99 -> V_102 -> V_110 |= V_115 | V_114 ;
}
#endif
if ( V_128 & ( V_139 | V_140 | V_141 |
V_119 | V_121 ) ) {
if ( V_128 == 0xffff ) {
F_6
( L_10 ) ;
if ( F_75 ( V_99 ) & V_142 ) {
V_99 -> V_102 -> V_110 |=
V_115 | V_114 ;
F_66 ( V_5 , V_99 ) ;
}
return;
}
if ( V_128 & ( V_139 | V_140 |
V_141 ) ) {
F_6 ( L_11 ,
V_128 ) ;
F_74 ( V_128 ) ;
F_62 ( V_5 ) ;
V_99 -> V_102 -> V_110 |= V_115 ;
if ( V_128 & ( V_139 | V_140 ) )
V_99 -> V_102 -> V_110 |= V_116 ;
F_66 ( V_5 , V_99 ) ;
return;
}
if ( V_128 & V_119 ) {
#ifdef F_73
F_6 ( L_12 ) ;
#endif
if ( ! V_10 -> V_143 ) {
F_62 ( V_5 ) ;
}
}
}
#ifndef F_24
if ( V_128 & V_144 ) {
int V_105 ;
static const int V_104 = 10 ;
for ( V_105 = 0 ; V_105 < V_104 ; ++ V_105 ) {
F_76 ( V_5 ) ;
if ( ( V_10 -> V_72 ( V_5 ,
V_88 ) &
V_144 ) == 0 )
break;
}
}
#endif
if ( ( V_128 & V_125 ) ) {
F_60 ( V_5 , V_99 ) ;
}
F_66 ( V_5 , V_99 ) ;
#ifdef F_73
V_128 = V_10 -> V_72 ( V_5 , V_88 ) ;
if ( V_128 & V_94 ) {
F_6
( L_13 ,
V_128 ) ;
}
#endif
}
static void F_49 ( struct V_4 * V_5 , unsigned short V_81 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned short V_118 = 0 ;
if ( V_81 & V_145 ) {
V_118 |= V_146 ;
}
if ( V_81 & V_147 ) {
V_118 |= V_148 ;
}
if ( V_81 & V_149 ) {
V_118 |= V_150 ;
}
if ( V_81 & V_151 ) {
V_118 |= V_152 ;
}
if ( V_81 & V_153 ) {
V_118 |= V_154 ;
}
if ( V_81 & V_155 ) {
V_118 |= V_156 ;
}
if ( V_81 & V_157 ) {
V_118 |= V_158 ;
}
if ( V_118 )
V_10 -> V_16 ( V_5 , V_118 , V_159 ) ;
}
static void F_51 ( struct V_4 * V_5 ,
unsigned short V_81 , unsigned V_83 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_98 * V_99 = & V_5 -> V_100 [ V_103 ] ;
#ifdef F_73
F_6 ( L_14 ,
V_81 , V_83 ) ;
F_77 ( V_81 ) ;
#endif
#ifdef F_24
if ( V_83 & V_91 ) {
F_56 ( V_10 -> V_40 , V_5 ) ;
}
if ( V_83 & ~ ( V_95 | V_91 | V_130 | V_131 |
V_132 | V_133 | V_134 | V_135 |
V_136 | V_137 | V_138 ) ) {
F_6
( L_15 ,
V_83 ) ;
V_99 -> V_102 -> V_110 |= V_114 | V_115 ;
}
#endif
if ( V_81 == 0xffff )
return;
if ( V_81 & V_147 ) {
F_6
( L_16 ,
V_81 , V_10 -> V_72 ( V_5 , V_160 ) ) ;
V_99 -> V_102 -> V_110 |= V_116 ;
}
if ( V_81 & V_145 ) {
F_78
( L_17 ,
V_81 , V_10 -> V_72 ( V_5 , V_160 ) ) ;
V_99 -> V_102 -> V_110 |= V_114 ;
}
#ifndef F_24
if ( V_81 & V_161 ) {
int V_162 ;
V_162 = F_79 ( V_5 , V_99 ) ;
if ( ! V_162 ) {
F_6 ( L_18 ) ;
F_42 ( V_5 , V_17 ,
V_163 |
V_164 , 0 ) ;
V_99 -> V_102 -> V_110 |= V_116 ;
}
}
#endif
F_66 ( V_5 , V_99 ) ;
}
static void F_74 ( int V_128 )
{
int V_105 ;
F_6 ( L_19 ) ;
for ( V_105 = 15 ; V_105 >= 0 ; V_105 -- ) {
if ( V_128 & ( 1 << V_105 ) ) {
F_6 ( L_20 , V_165 [ V_105 ] ) ;
}
}
F_6 ( L_21 ) ;
}
static void F_77 ( int V_128 )
{
int V_105 ;
F_6 ( L_22 ) ;
for ( V_105 = 15 ; V_105 >= 0 ; V_105 -- ) {
if ( V_128 & ( 1 << V_105 ) ) {
F_6 ( L_20 , V_166 [ V_105 ] ) ;
}
}
F_6 ( L_21 ) ;
}
static void F_80 ( struct V_4 * V_5 ,
struct V_98 * V_99 , int V_167 )
{
struct V_168 * V_102 = V_99 -> V_102 ;
struct V_169 * V_170 = & V_102 -> V_170 ;
int V_171 ;
int V_105 ;
short V_79 ;
T_4 V_172 ;
int V_173 ;
int V_174 = 1 ;
V_171 = V_102 -> V_175 ;
for ( V_105 = 0 ; V_105 < V_167 ; V_105 ++ ) {
V_174 &= F_81 ( V_102 , & V_79 ) ;
if ( V_174 == 0 )
break;
V_173 = F_82 ( V_170 -> V_176 [ V_171 ] ) ;
if ( V_58 . V_59 & V_177 ) {
V_172 = V_79 & 0xffff ;
if ( V_58 . V_59 != V_178 ) {
V_174 &= F_81 ( V_102 , & V_79 ) ;
if ( V_174 == 0 )
break;
V_171 ++ ;
V_105 ++ ;
V_172 |= ( V_79 << 16 ) & 0xffff0000 ;
}
F_32 ( V_172 , V_179 ) ;
} else {
F_38 ( V_79 , V_180 ) ;
}
V_171 ++ ;
V_171 %= V_170 -> V_181 ;
}
V_102 -> V_175 = V_171 ;
if ( V_174 == 0 ) {
V_102 -> V_110 |= V_116 ;
}
}
static int F_79 ( struct V_4 * V_5 ,
struct V_98 * V_99 )
{
int V_167 ;
V_167 = F_83 ( V_99 -> V_102 ) ;
if ( V_167 == 0 ) {
V_99 -> V_102 -> V_110 |= V_116 ;
return 0 ;
}
V_167 /= sizeof( short ) ;
if ( V_167 > V_58 . V_182 / 2 )
V_167 = V_58 . V_182 / 2 ;
F_80 ( V_5 , V_99 , V_167 ) ;
V_99 -> V_102 -> V_110 |= V_183 ;
return 1 ;
}
static int F_84 ( struct V_4 * V_5 ,
struct V_98 * V_99 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_167 ;
V_10 -> V_16 ( V_5 , 1 , V_184 ) ;
if ( V_58 . V_59 & V_177 )
F_39 ( V_5 , 0x6 , V_185 ) ;
V_167 = F_83 ( V_99 -> V_102 ) ;
if ( V_167 == 0 )
return 0 ;
V_167 /= sizeof( short ) ;
if ( V_167 > V_58 . V_182 )
V_167 = V_58 . V_182 ;
F_80 ( V_5 , V_99 , V_167 ) ;
return V_167 ;
}
static void F_85 ( struct V_4 * V_5 ,
struct V_98 * V_99 , int V_167 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_168 * V_102 = V_99 -> V_102 ;
int V_105 ;
if ( V_58 . V_59 == V_186 ) {
short V_70 [ 2 ] ;
T_4 V_187 ;
for ( V_105 = 0 ; V_105 < V_167 / 2 ; V_105 ++ ) {
V_187 = F_33 ( V_188 ) ;
V_70 [ 0 ] = ( V_187 >> 16 ) & 0xffff ;
V_70 [ 1 ] = V_187 & 0xffff ;
F_86 ( V_99 , V_70 , sizeof( V_70 ) ) ;
}
if ( V_167 % 2 ) {
V_187 = F_33 ( V_188 ) ;
V_70 [ 0 ] = V_187 & 0xffff ;
F_87 ( V_99 , V_70 [ 0 ] ) ;
}
} else if ( V_58 . V_59 == V_65 ) {
short V_70 [ 2 ] ;
T_4 V_187 ;
for ( V_105 = 0 ; V_105 < V_167 / 2 ; V_105 ++ ) {
V_187 = F_33 ( V_189 ) ;
V_70 [ 0 ] = ( V_187 >> 16 ) & 0xffff ;
V_70 [ 1 ] = V_187 & 0xffff ;
F_86 ( V_99 , V_70 , sizeof( V_70 ) ) ;
}
if ( V_167 % 2 ) {
F_32 ( 0x01 , V_66 ) ;
V_187 = F_33 ( V_189 ) ;
V_70 [ 0 ] = ( V_187 >> 16 ) & 0xffff ;
F_87 ( V_99 , V_70 [ 0 ] ) ;
}
} else {
if ( V_167 > sizeof( V_10 -> V_190 ) /
sizeof( V_10 -> V_190 [ 0 ] ) ) {
F_19 ( V_5 , L_23 ) ;
V_102 -> V_110 |= V_115 ;
return;
}
for ( V_105 = 0 ; V_105 < V_167 ; V_105 ++ ) {
V_10 -> V_190 [ V_105 ] =
F_41 ( V_191 ) ;
}
F_86 ( V_99 , V_10 -> V_190 ,
V_167 *
sizeof( V_10 -> V_190 [ 0 ] ) ) ;
}
}
static void F_76 ( struct V_4 * V_5 )
{
int V_167 ;
struct V_98 * V_99 = & V_5 -> V_100 [ V_101 ] ;
V_167 = V_58 . V_192 / 2 ;
F_85 ( V_5 , V_99 , V_167 ) ;
}
static int F_63 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_105 ;
static const int V_104 = 10000 ;
unsigned long V_12 ;
int V_193 = 0 ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_39 ) {
for ( V_105 = 0 ; V_105 < V_104 ; V_105 ++ ) {
if ( ( V_10 -> V_72 ( V_5 ,
V_88 ) &
V_194 )
&& F_88 ( V_10 -> V_39 ) ==
0 )
break;
F_59 ( 5 ) ;
}
if ( V_105 == V_104 ) {
F_6 ( L_24 ) ;
F_6
( L_25 ,
F_88 ( V_10 -> V_39 ) ,
V_10 -> V_72 ( V_5 , V_88 ) ) ;
V_193 = - 1 ;
}
}
F_8 ( & V_10 -> V_38 , V_12 ) ;
F_54 ( V_5 ) ;
return V_193 ;
}
static void F_61 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_98 * V_99 = & V_5 -> V_100 [ V_101 ] ;
short V_70 [ 2 ] ;
T_4 V_187 ;
short V_195 ;
int V_105 ;
if ( V_58 . V_59 == V_186 ) {
while ( ( V_10 -> V_72 ( V_5 ,
V_88 ) &
V_194 ) == 0 ) {
V_187 = F_33 ( V_188 ) ;
V_70 [ 0 ] = ( V_187 >> 16 ) ;
V_70 [ 1 ] = ( V_187 & 0xffff ) ;
F_86 ( V_99 , V_70 , sizeof( V_70 ) ) ;
}
} else if ( V_58 . V_59 == V_65 ) {
V_105 = 0 ;
while ( F_33 ( V_67 ) & 0x04 ) {
V_187 = F_33 ( V_189 ) ;
V_70 [ 0 ] = ( V_187 >> 16 ) ;
V_70 [ 1 ] = ( V_187 & 0xffff ) ;
F_86 ( V_99 , V_70 , sizeof( V_70 ) ) ;
V_105 += 2 ;
}
if ( F_33 ( V_67 ) & 0x01 ) {
F_32 ( 0x01 , V_66 ) ;
V_187 = F_33 ( V_189 ) ;
V_70 [ 0 ] = ( V_187 >> 16 ) & 0xffff ;
F_87 ( V_99 , V_70 [ 0 ] ) ;
}
} else {
V_195 =
V_10 -> V_72 ( V_5 ,
V_88 ) & V_194 ;
while ( V_195 == 0 ) {
for ( V_105 = 0 ;
V_105 <
sizeof( V_10 -> V_190 ) /
sizeof( V_10 -> V_190 [ 0 ] ) ; V_105 ++ ) {
V_195 =
V_10 -> V_72 ( V_5 ,
V_88 ) &
V_194 ;
if ( V_195 )
break;
V_10 -> V_190 [ V_105 ] =
F_41 ( V_191 ) ;
}
F_86 ( V_99 , V_10 -> V_190 ,
V_105 *
sizeof( V_10 ->
V_190 [ 0 ] ) ) ;
}
}
}
static void F_64 ( struct V_4 * V_5 )
{
struct V_9 * V_10 V_196 = V_5 -> V_11 ;
struct V_98 * V_99 = & V_5 -> V_100 [ V_101 ] ;
short V_70 ;
T_4 V_187 ;
if ( V_58 . V_59 != V_186 )
return;
if ( F_89 ( V_197 ) & 0x80 ) {
V_187 = F_33 ( V_188 ) ;
V_70 = ( V_187 & 0xffff ) ;
F_87 ( V_99 , V_70 ) ;
}
}
static void F_65 ( struct V_4 * V_5 )
{
struct V_9 * V_10 V_196 = V_5 -> V_11 ;
struct V_98 * V_99 = & V_5 -> V_100 [ V_101 ] ;
short V_70 ;
T_4 V_187 ;
if ( V_58 . V_59 != V_65 )
return;
if ( F_33 ( V_67 ) & 0x01 ) {
F_32 ( 0x01 , V_66 ) ;
V_187 = F_33 ( V_189 ) ;
V_70 = ( V_187 >> 16 ) & 0xffff ;
F_87 ( V_99 , V_70 ) ;
}
}
static void F_90 ( struct V_4 * V_5 , struct V_98 * V_99 ,
void * V_70 , unsigned int V_198 ,
unsigned int V_199 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_168 * V_102 = V_99 -> V_102 ;
unsigned int V_105 ;
unsigned int V_200 = V_198 / F_91 ( V_99 ) ;
short * V_201 = V_70 ;
unsigned int * V_202 = V_70 ;
for ( V_105 = 0 ; V_105 < V_200 ; V_105 ++ ) {
#ifdef F_24
if ( V_99 -> V_203 & V_204 )
V_202 [ V_105 ] = F_92 ( V_202 [ V_105 ] ) ;
else
V_201 [ V_105 ] = F_93 ( V_201 [ V_105 ] ) ;
#endif
if ( V_99 -> V_203 & V_204 )
V_202 [ V_105 ] += V_10 -> V_205 [ V_199 ] ;
else
V_201 [ V_105 ] += V_10 -> V_205 [ V_199 ] ;
V_199 ++ ;
V_199 %= V_102 -> V_170 . V_181 ;
}
}
static int F_94 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_98 * V_99 = & V_5 -> V_100 [ V_101 ] ;
int V_193 ;
unsigned long V_12 ;
V_193 = F_16 ( V_5 ) ;
if ( V_193 )
return V_193 ;
F_95 ( V_99 -> V_102 , V_99 -> V_102 -> V_206 ) ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_39 == NULL ) {
F_8 ( & V_10 -> V_38 , V_12 ) ;
return - V_207 ;
}
switch ( V_58 . V_59 ) {
case V_186 :
case V_65 :
F_96 ( V_10 -> V_39 , 32 , 16 ) ;
break;
case V_208 :
F_96 ( V_10 -> V_39 , 32 , 32 ) ;
break;
default:
F_96 ( V_10 -> V_39 , 16 , 16 ) ;
break;
}
F_97 ( V_10 -> V_39 ) ;
F_8 ( & V_10 -> V_38 , V_12 ) ;
return 0 ;
}
static int F_98 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_98 * V_99 = & V_5 -> V_100 [ V_103 ] ;
int V_193 ;
unsigned long V_12 ;
V_193 = F_20 ( V_5 ) ;
if ( V_193 )
return V_193 ;
F_99 ( V_99 -> V_102 , V_99 -> V_102 -> V_206 ) ;
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_45 ) {
if ( V_58 . V_59 & ( V_186 | V_209 ) ) {
F_96 ( V_10 -> V_45 , 32 , 32 ) ;
} else {
F_96 ( V_10 -> V_45 , 16 , 32 ) ;
}
F_97 ( V_10 -> V_45 ) ;
} else
V_193 = - V_207 ;
F_8 ( & V_10 -> V_38 , V_12 ) ;
return V_193 ;
}
static int F_67 ( struct V_4 * V_5 , struct V_98 * V_99 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
F_25 ( V_5 ) ;
V_10 -> V_16 ( V_5 , V_210 | V_211 ,
V_212 ) ;
F_42 ( V_5 , V_14 ,
V_213 | V_214 |
V_215 | V_216 |
V_217 | V_218 |
V_219 , 0 ) ;
F_31 ( V_5 ) ;
if ( V_58 . V_59 != V_65 )
F_5 ( 0 , V_220 ) ;
V_10 -> V_16 ( V_5 , V_221 , V_222 ) ;
V_10 -> V_16 ( V_5 ,
V_223 | V_224
,
V_225 ) ;
V_10 -> V_16 ( V_5 , 0x0000 , V_226 ) ;
V_10 -> V_16 ( V_5 , ( 0 << 6 ) | 0x0000 , V_227 ) ;
if ( V_58 . V_59 == V_186 ) {
V_10 -> V_16 ( V_5 , V_228 |
V_229 |
V_230 ,
V_231 ) ;
V_10 -> V_16 ( V_5 ,
F_100 ( 3 ) |
F_101 ( 0 ) |
F_102 ( 2 ) |
F_103 ( 3 ) |
F_104
( V_232 ) ,
V_233 ) ;
} else if ( V_58 . V_59 == V_65 ) {
V_10 -> V_16 ( V_5 , V_228 |
V_229 |
V_230 ,
V_231 ) ;
V_10 -> V_16 ( V_5 ,
F_100 ( 3 ) |
F_101 ( 0 ) |
F_102 ( 2 ) |
F_103 ( 3 ) |
F_104
( V_234 ) ,
V_233 ) ;
} else {
unsigned V_235 ;
V_10 -> V_16 ( V_5 , V_228 |
V_229 |
V_236 |
V_230 ,
V_231 ) ;
V_235 =
F_100 ( 3 ) |
F_101 ( 0 ) |
F_102 ( 2 ) |
F_103 ( 3 ) ;
if ( V_58 . V_59 == V_237 )
V_235 |=
F_104
( V_232 ) ;
else
V_235 |=
F_104
( V_234 ) ;
V_10 -> V_16 ( V_5 , V_235 ,
V_233 ) ;
}
V_10 -> V_16 ( V_5 , V_238 | V_124 | V_239 | V_122 | V_120 | V_240 | V_126 , V_127 ) ;
V_10 -> V_16 ( V_5 , V_241 , V_212 ) ;
return 0 ;
}
static int F_105 ( struct V_4 * V_5 , struct V_98 * V_99 )
{
unsigned long V_12 ;
int V_242 ;
F_4 ( & V_5 -> V_87 , V_12 ) ;
#ifndef F_24
F_61 ( V_5 ) ;
#else
F_54 ( V_5 ) ;
#endif
V_242 = V_99 -> V_102 -> V_243 - V_99 -> V_102 -> V_244 ;
F_8 ( & V_5 -> V_87 , V_12 ) ;
return V_242 ;
}
static int F_106 ( struct V_4 * V_5 ,
struct V_98 * V_99 , struct V_245 * V_246 ,
unsigned int * V_70 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_105 , V_167 ;
const unsigned int V_247 = ( 1 << V_58 . V_248 ) - 1 ;
unsigned V_249 ;
unsigned short V_79 ;
unsigned long V_187 ;
F_107 ( V_5 , 1 , & V_246 -> V_250 ) ;
F_31 ( V_5 ) ;
V_249 = V_10 -> V_205 [ 0 ] ;
if ( V_58 . V_59 == V_186 ) {
for ( V_167 = 0 ; V_167 < V_251 ; V_167 ++ ) {
V_10 -> V_16 ( V_5 , V_252 ,
V_222 ) ;
F_59 ( 1 ) ;
}
for ( V_167 = 0 ; V_167 < V_246 -> V_167 ; V_167 ++ ) {
V_10 -> V_16 ( V_5 , V_252 ,
V_222 ) ;
V_79 = 0 ;
for ( V_105 = 0 ; V_105 < V_253 ; V_105 ++ ) {
if ( F_89 ( V_197 ) & 0x80 ) {
V_79 = ( F_33 ( V_188 ) >> 16 )
& 0xffff ;
break;
}
if ( ! ( V_10 -> V_72 ( V_5 ,
V_88 ) &
V_194 ) ) {
V_79 = F_33 ( V_188 ) &
0xffff ;
break;
}
}
if ( V_105 == V_253 ) {
F_6
( L_26 ) ;
return - V_254 ;
}
V_79 += V_249 ;
V_70 [ V_167 ] = V_79 ;
}
} else if ( V_58 . V_59 == V_65 ) {
for ( V_167 = 0 ; V_167 < V_246 -> V_167 ; V_167 ++ ) {
V_10 -> V_16 ( V_5 , V_252 ,
V_222 ) ;
V_187 = 0 ;
for ( V_105 = 0 ; V_105 < V_253 ; V_105 ++ ) {
if ( F_33 ( V_67 ) & 0x01 ) {
F_32 ( 0x01 , V_66 ) ;
V_187 = F_33 ( V_189 ) ;
break;
}
}
if ( V_105 == V_253 ) {
F_6
( L_27 ) ;
return - V_254 ;
}
V_70 [ V_167 ] = ( ( ( V_187 >> 16 ) & 0xFFFF ) + V_249 ) & 0xFFFF ;
}
} else {
for ( V_167 = 0 ; V_167 < V_246 -> V_167 ; V_167 ++ ) {
V_10 -> V_16 ( V_5 , V_252 ,
V_222 ) ;
for ( V_105 = 0 ; V_105 < V_253 ; V_105 ++ ) {
if ( ! ( V_10 -> V_72 ( V_5 ,
V_88 ) &
V_194 ) )
break;
}
if ( V_105 == V_253 ) {
F_6
( L_28 ) ;
return - V_254 ;
}
if ( V_58 . V_59 & V_60 ) {
V_70 [ V_167 ] =
F_33 ( V_255 ) & V_247 ;
} else {
V_79 = F_41 ( V_191 ) ;
V_79 += V_249 ;
V_70 [ V_167 ] = V_79 ;
}
}
}
return V_246 -> V_167 ;
}
static void F_108 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_105 ;
V_10 -> V_16 ( V_5 , V_252 , V_222 ) ;
for ( V_105 = 0 ; V_105 < V_253 ; ++ V_105 ) {
if ( ! ( V_10 -> V_72 ( V_5 ,
V_88 ) &
V_194 ) ) {
V_10 -> V_16 ( V_5 , 1 , V_68 ) ;
return;
}
F_59 ( 1 ) ;
}
F_6 ( L_29 ) ;
}
static void F_109 ( struct V_4 * V_5 ,
unsigned int V_256 ,
unsigned int * V_257 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_171 , V_173 , V_258 ;
unsigned int V_105 ;
unsigned V_259 ;
unsigned int V_260 ;
unsigned V_261 ;
V_10 -> V_16 ( V_5 , 1 , V_262 ) ;
if ( ( V_257 [ 0 ] & V_263 ) ) {
unsigned V_264 ;
V_171 = F_110 ( V_257 [ 0 ] ) ;
V_173 = F_82 ( V_257 [ 0 ] ) ;
V_261 = V_265 [ V_58 . V_266 ] [ V_173 ] ;
V_260 = ( ( V_257 [ 0 ] & V_267 ) != 0 ) ;
V_264 = V_268 ;
V_264 |= V_171 ;
V_264 |=
( V_10 -> V_269 ) &
( V_270 |
V_271 |
V_272 |
V_273 ) ;
V_264 |= F_111 ( V_261 ) ;
if ( V_260 )
V_264 |= V_274 ;
V_264 |= V_275 ;
F_32 ( V_264 , V_276 ) ;
} else {
F_32 ( 0 , V_276 ) ;
}
V_259 = 0 ;
for ( V_105 = 0 ; V_105 < V_256 ; V_105 ++ ) {
unsigned V_277 = 0 ;
V_171 = F_110 ( V_257 [ V_105 ] ) ;
V_258 = F_112 ( V_257 [ V_105 ] ) ;
V_173 = F_82 ( V_257 [ V_105 ] ) ;
V_260 = ( ( V_257 [ V_105 ] & V_267 ) != 0 ) ;
V_261 = V_265 [ V_58 . V_266 ] [ V_173 ] ;
V_10 -> V_205 [ V_105 ] = V_259 ;
switch ( V_258 ) {
case V_278 :
V_277 |=
V_279 ;
break;
case V_280 :
V_277 |=
V_281 ;
break;
case V_282 :
V_277 |=
V_283 ;
break;
case V_284 :
break;
}
V_277 |= F_113 ( V_171 ) ;
V_277 |=
F_114 ( V_58 . V_59 , V_171 ) ;
V_277 |= F_115 ( V_261 ) ;
if ( V_105 == V_256 - 1 )
V_277 |= V_285 ;
if ( V_260 )
V_277 |= V_286 ;
V_277 |= V_287 ;
F_38 ( V_277 , V_288 ) ;
}
F_108 ( V_5 ) ;
}
static void F_107 ( struct V_4 * V_5 ,
unsigned int V_256 , unsigned int * V_257 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_171 , V_173 , V_258 ;
unsigned int V_105 ;
unsigned int V_289 , V_290 ;
unsigned V_259 ;
unsigned int V_260 ;
if ( V_58 . V_59 & V_60 ) {
F_109 ( V_5 , V_256 , V_257 ) ;
return;
}
if ( V_256 == 1 && ( V_58 . V_59 != V_186 )
&& ( V_58 . V_59 != V_65 ) ) {
if ( V_10 -> V_291
&& V_10 -> V_292 == V_257 [ 0 ] ) {
return;
}
V_10 -> V_291 = 1 ;
V_10 -> V_292 = V_257 [ 0 ] ;
} else {
V_10 -> V_291 = 0 ;
}
V_10 -> V_16 ( V_5 , 1 , V_262 ) ;
if ( V_58 . V_59 == V_65 ) {
if ( ( V_257 [ 0 ] & V_263 )
&& ! V_10 -> V_293 ) {
F_38 ( V_10 -> V_269 |
V_294 ,
V_295 ) ;
F_38 ( V_10 -> V_269 ,
V_295 ) ;
V_10 -> V_293 = 1 ;
F_116 ( 100 ) ;
} else if ( ! ( V_257 [ 0 ] & V_263 )
&& V_10 -> V_293 ) {
F_38 ( V_10 -> V_269 |
V_296 ,
V_295 ) ;
F_38 ( V_10 -> V_269 ,
V_295 ) ;
V_10 -> V_293 = 0 ;
F_116 ( 100 ) ;
}
}
V_259 = 1 << ( V_58 . V_248 - 1 ) ;
for ( V_105 = 0 ; V_105 < V_256 ; V_105 ++ ) {
if ( ( V_58 . V_59 != V_65 )
&& ( V_257 [ V_105 ] & V_263 ) ) {
V_171 = V_10 -> V_269 ;
} else {
V_171 = F_110 ( V_257 [ V_105 ] ) ;
}
V_258 = F_112 ( V_257 [ V_105 ] ) ;
V_173 = F_82 ( V_257 [ V_105 ] ) ;
V_260 = ( ( V_257 [ V_105 ] & V_267 ) != 0 ) ;
V_173 = V_265 [ V_58 . V_266 ] [ V_173 ] ;
if ( V_58 . V_59 == V_186 )
V_10 -> V_205 [ V_105 ] = V_259 ;
else
V_10 -> V_205 [ V_105 ] = ( V_173 & 0x100 ) ? 0 : V_259 ;
V_289 = 0 ;
if ( ( V_257 [ V_105 ] & V_263 ) ) {
if ( V_58 . V_59 == V_186 )
F_38 ( F_110 ( V_257 [ V_105 ] ) & 0x0003 ,
V_297 ) ;
} else {
if ( V_58 . V_59 == V_186 )
V_258 = V_278 ;
else if ( V_58 . V_59 == V_65 )
V_258 = V_284 ;
switch ( V_258 ) {
case V_278 :
V_289 |= V_298 ;
break;
case V_280 :
V_289 |= V_299 ;
break;
case V_282 :
V_289 |= V_300 ;
break;
case V_284 :
break;
}
}
V_289 |= F_117 ( V_171 ) ;
F_38 ( V_289 , V_301 ) ;
if ( V_58 . V_59 != V_65 ) {
V_290 = V_173 ;
if ( V_105 == V_256 - 1 )
V_290 |= V_302 ;
if ( V_260 )
V_290 |= V_303 ;
F_38 ( V_290 , V_304 ) ;
}
}
if ( ( V_58 . V_59 != V_186 )
&& ( V_58 . V_59 != V_65 ) ) {
F_108 ( V_5 ) ;
}
}
static int F_118 ( const struct V_4 * V_5 , unsigned V_305 ,
int V_306 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_307 ;
switch ( V_306 ) {
case V_308 :
default:
V_307 = ( V_305 + V_10 -> V_309 / 2 ) / V_10 -> V_309 ;
break;
case V_310 :
V_307 = ( V_305 ) / V_10 -> V_309 ;
break;
case V_311 :
V_307 = ( V_305 + V_10 -> V_309 - 1 ) / V_10 -> V_309 ;
break;
}
return V_307 - 1 ;
}
static unsigned F_119 ( const struct V_4 * V_5 , int V_312 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
return V_10 -> V_309 * ( V_312 + 1 ) ;
}
static unsigned F_120 ( struct V_4 * V_5 ,
unsigned V_313 )
{
switch ( V_58 . V_59 ) {
case V_186 :
case V_65 :
return V_58 . V_314 ;
break;
default:
break;
}
return V_58 . V_314 * V_313 ;
}
static int F_121 ( struct V_4 * V_5 , struct V_98 * V_99 ,
struct V_169 * V_170 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_174 = 0 ;
int V_315 ;
unsigned int V_316 ;
if ( ( V_170 -> V_12 & V_317 ) )
V_170 -> V_12 &= ~ V_317 ;
V_174 |= F_122 ( & V_170 -> V_318 ,
V_319 | V_320 | V_321 ) ;
V_174 |= F_122 ( & V_170 -> V_322 ,
V_323 | V_321 ) ;
V_316 = V_323 | V_321 ;
if ( V_58 . V_59 == V_186 ||
V_58 . V_59 == V_65 )
V_316 |= V_319 ;
V_174 |= F_122 ( & V_170 -> V_324 , V_316 ) ;
V_174 |= F_122 ( & V_170 -> V_325 , V_326 ) ;
V_174 |= F_122 ( & V_170 -> V_327 , V_326 | V_328 ) ;
if ( V_174 )
return 1 ;
V_174 |= F_123 ( V_170 -> V_318 ) ;
V_174 |= F_123 ( V_170 -> V_322 ) ;
V_174 |= F_123 ( V_170 -> V_324 ) ;
V_174 |= F_123 ( V_170 -> V_327 ) ;
if ( V_174 )
return 2 ;
if ( V_170 -> V_318 == V_321 ) {
unsigned int V_315 = F_110 ( V_170 -> V_329 ) ;
if ( V_315 > 16 )
V_315 = 16 ;
V_315 |= ( V_170 -> V_329 & ( V_330 | V_331 ) ) ;
V_174 |= F_124 ( & V_170 -> V_329 , V_315 ) ;
} else {
V_174 |= F_124 ( & V_170 -> V_329 , 0 ) ;
}
if ( V_170 -> V_322 == V_323 ) {
V_174 |= F_125 ( & V_170 -> V_332 ,
F_120 ( V_5 , V_170 -> V_181 ) ) ;
V_174 |= F_126 ( & V_170 -> V_332 ,
V_10 -> V_309 * 0xffffff ) ;
} else if ( V_170 -> V_322 == V_321 ) {
unsigned int V_315 = F_110 ( V_170 -> V_332 ) ;
if ( V_315 > 16 )
V_315 = 16 ;
V_315 |= ( V_170 -> V_332 & ( V_330 | V_331 ) ) ;
V_174 |= F_124 ( & V_170 -> V_332 , V_315 ) ;
} else {
V_174 |= F_124 ( & V_170 -> V_332 , 0 ) ;
}
if ( V_170 -> V_324 == V_323 ) {
if ( ( V_58 . V_59 == V_186 )
|| ( V_58 . V_59 == V_65 ) ) {
V_174 |= F_124 ( & V_170 -> V_333 , 0 ) ;
} else {
V_174 |= F_125 ( & V_170 -> V_333 ,
V_58 . V_314 ) ;
V_174 |= F_126 ( & V_170 -> V_333 ,
V_10 -> V_309 * 0xffff ) ;
}
} else if ( V_170 -> V_324 == V_321 ) {
unsigned int V_315 = F_110 ( V_170 -> V_333 ) ;
if ( V_315 > 16 )
V_315 = 16 ;
V_315 |= ( V_170 -> V_333 & ( V_267 | V_330 ) ) ;
V_174 |= F_124 ( & V_170 -> V_333 , V_315 ) ;
} else if ( V_170 -> V_324 == V_319 ) {
V_174 |= F_124 ( & V_170 -> V_333 , 0 ) ;
}
V_174 |= F_124 ( & V_170 -> V_334 , V_170 -> V_181 ) ;
if ( V_170 -> V_327 == V_326 ) {
unsigned int V_335 = 0x01000000 ;
if ( V_58 . V_59 == V_186 )
V_335 -= V_251 ;
V_174 |= F_126 ( & V_170 -> V_336 , V_335 ) ;
V_174 |= F_125 ( & V_170 -> V_336 , 1 ) ;
} else {
V_174 |= F_124 ( & V_170 -> V_336 , 0 ) ;
}
if ( V_174 )
return 3 ;
if ( V_170 -> V_322 == V_323 ) {
V_315 = V_170 -> V_332 ;
V_170 -> V_332 =
F_119 ( V_5 , F_118 ( V_5 ,
V_170 -> V_332 ,
V_170 ->
V_12 &
V_337 ) ) ;
if ( V_315 != V_170 -> V_332 )
V_174 ++ ;
}
if ( V_170 -> V_324 == V_323 ) {
if ( ( V_58 . V_59 != V_186 )
&& ( V_58 . V_59 != V_65 ) ) {
V_315 = V_170 -> V_333 ;
V_170 -> V_333 =
F_119 ( V_5 , F_118 ( V_5 ,
V_170 -> V_333 ,
V_170 ->
V_12 &
V_337 ) ) ;
if ( V_315 != V_170 -> V_333 )
V_174 ++ ;
if ( V_170 -> V_322 == V_323 &&
V_170 -> V_332 <
V_170 -> V_333 * V_170 -> V_334 ) {
V_170 -> V_332 =
V_170 -> V_333 * V_170 -> V_334 ;
V_174 ++ ;
}
}
}
if ( V_174 )
return 4 ;
return 0 ;
}
static int F_127 ( struct V_4 * V_5 , struct V_98 * V_99 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
const struct V_169 * V_170 = & V_99 -> V_102 -> V_170 ;
int V_312 ;
int V_338 = 0 ;
int V_339 = 0 ;
int V_340 = 0 ;
unsigned int V_341 ;
int V_342 = 0 ;
F_78 ( L_30 ) ;
if ( V_5 -> V_78 == 0 ) {
F_19 ( V_5 , L_31 ) ;
return - V_207 ;
}
F_31 ( V_5 ) ;
F_107 ( V_5 , V_170 -> V_181 , V_170 -> V_176 ) ;
V_10 -> V_16 ( V_5 , V_210 , V_212 ) ;
V_10 -> V_343 &= ~ V_344 ;
V_10 -> V_16 ( V_5 , V_10 -> V_343 ,
V_345 ) ;
switch ( V_170 -> V_318 ) {
case V_320 :
case V_319 :
V_10 -> V_16 ( V_5 , F_128 ( 0 ) |
V_346 | V_347 |
F_129 ( 0 ) ,
V_348 ) ;
break;
case V_321 :
{
int V_171 = F_110 ( V_170 -> V_329 ) ;
unsigned int V_71 = F_128 ( 0 ) |
V_346 | F_129 ( V_171 + 1 ) ;
if ( V_170 -> V_329 & V_330 )
V_71 |= V_349 ;
if ( V_170 -> V_329 & V_331 )
V_71 |= V_347 ;
V_10 -> V_16 ( V_5 , V_71 ,
V_348 ) ;
break;
}
}
V_339 &= ~ V_350 ;
V_339 &= ~ V_351 ;
V_339 &= ~ V_352 ;
V_10 -> V_16 ( V_5 , V_339 , V_226 ) ;
if ( V_170 -> V_181 == 1 || ( V_58 . V_59 == V_186 )
|| ( V_58 . V_59 == V_65 ) ) {
V_340 |= V_353 ;
V_340 |= F_130 ( 31 ) ;
V_340 |= V_354 ;
} else {
V_340 |= F_130 ( 19 ) ;
}
V_10 -> V_16 ( V_5 , V_340 ,
V_355 ) ;
V_10 -> V_112 = 0 ;
switch ( V_170 -> V_327 ) {
case V_326 :
V_341 = V_170 -> V_336 - 1 ;
if ( V_58 . V_59 == V_186 ) {
V_341 += V_251 ;
}
V_10 -> V_356 ( V_5 , V_341 , V_357 ) ;
V_338 |= V_223 | V_224 | V_358 ;
V_10 -> V_16 ( V_5 , V_338 , V_225 ) ;
V_10 -> V_16 ( V_5 , V_359 , V_222 ) ;
V_10 -> V_143 = 0 ;
if ( V_341 == 0 ) {
V_10 -> V_112 |= V_113 ;
V_342 |= V_217 ;
if ( V_170 -> V_181 > 1 )
V_340 |=
V_353 | V_360 ;
}
break;
case V_328 :
V_10 -> V_356 ( V_5 , 0 , V_357 ) ;
V_338 |= V_223 | V_224 | V_361 ;
V_10 -> V_16 ( V_5 , V_338 , V_225 ) ;
V_10 -> V_16 ( V_5 , V_359 , V_222 ) ;
V_10 -> V_143 = 1 ;
break;
}
switch ( V_170 -> V_322 ) {
case V_323 :
V_340 |= V_362 | V_363 ;
V_10 -> V_16 ( V_5 , V_340 ,
V_355 ) ;
V_339 |= F_131 ( 0 ) ;
V_339 &= ~ V_364 ;
V_10 -> V_16 ( V_5 , V_339 , V_226 ) ;
V_312 = F_118 ( V_5 , V_170 -> V_332 ,
V_308 ) ;
V_10 -> V_356 ( V_5 , V_312 , V_365 ) ;
V_10 -> V_16 ( V_5 , V_366 , V_222 ) ;
break;
case V_321 :
if ( V_170 -> V_332 & V_331 )
V_340 |= V_362 ;
if ( V_170 -> V_332 & V_330 )
V_340 |= V_367 ;
if ( V_170 -> V_322 != V_170 -> V_324 ||
( V_170 -> V_332 & ~ V_331 ) !=
( V_170 -> V_333 & ~ V_331 ) )
V_340 |= V_363 ;
V_340 |=
F_132 ( 1 + F_110 ( V_170 -> V_332 ) ) ;
V_10 -> V_16 ( V_5 , V_340 ,
V_355 ) ;
break;
}
switch ( V_170 -> V_324 ) {
case V_323 :
case V_319 :
if ( V_170 -> V_333 == 0 || V_170 -> V_324 == V_319 )
V_312 = 1 ;
else
V_312 = F_118 ( V_5 , V_170 -> V_333 ,
V_308 ) ;
V_10 -> V_16 ( V_5 , 1 , V_368 ) ;
V_10 -> V_16 ( V_5 , V_312 , V_369 ) ;
V_339 &= ~ V_370 ;
V_339 |= V_371 ;
V_10 -> V_16 ( V_5 , V_339 , V_226 ) ;
V_10 -> V_16 ( V_5 , V_372 , V_222 ) ;
V_339 |= V_371 ;
V_339 |= V_370 ;
V_10 -> V_16 ( V_5 , V_339 , V_226 ) ;
break;
case V_321 :
V_338 |= F_133 ( 1 + V_170 -> V_333 ) ;
if ( ( V_170 -> V_333 & V_330 ) == 0 )
V_338 |= V_373 ;
V_10 -> V_16 ( V_5 , V_338 , V_225 ) ;
V_339 |= V_374 | V_375 ;
V_10 -> V_16 ( V_5 , V_339 , V_226 ) ;
break;
}
if ( V_5 -> V_78 ) {
V_342 |= V_218 |
V_213 ;
#ifndef F_24
V_342 |= V_219 ;
#endif
if ( V_170 -> V_12 & V_376
|| ( V_10 -> V_112 & V_113 ) ) {
V_10 -> V_108 = V_109 ;
} else {
V_10 -> V_108 = V_377 ;
}
switch ( V_10 -> V_108 ) {
case V_377 :
#ifdef F_24
V_10 -> V_16 ( V_5 , V_378 ,
V_227 ) ;
#else
V_10 -> V_16 ( V_5 , V_379 ,
V_227 ) ;
#endif
break;
case V_380 :
V_10 -> V_16 ( V_5 , V_381 ,
V_227 ) ;
break;
case V_109 :
#ifdef F_24
V_10 -> V_16 ( V_5 , V_381 ,
V_227 ) ;
#else
V_10 -> V_16 ( V_5 , V_379 ,
V_227 ) ;
#endif
V_342 |= V_217 ;
break;
default:
break;
}
V_10 -> V_16 ( V_5 , V_240 | V_126 | V_124 | V_239 | V_122 | V_120 | V_238 , V_127 ) ;
F_42 ( V_5 , V_14 ,
V_342 , 1 ) ;
F_78 ( L_32 ,
V_10 -> V_15 ) ;
} else {
F_42 ( V_5 , V_14 , ~ 0 , 0 ) ;
F_78 ( L_33 ) ;
}
V_10 -> V_16 ( V_5 , V_241 , V_212 ) ;
switch ( V_170 -> V_322 ) {
case V_323 :
V_10 -> V_16 ( V_5 ,
V_382 | V_383 | V_384 |
V_385 , V_222 ) ;
break;
case V_321 :
V_10 -> V_16 ( V_5 ,
V_382 | V_383 | V_384 |
V_385 , V_222 ) ;
break;
}
#ifdef F_24
{
int V_193 = F_94 ( V_5 ) ;
if ( V_193 )
return V_193 ;
}
#endif
switch ( V_170 -> V_318 ) {
case V_319 :
V_10 -> V_16 ( V_5 , V_386 | V_10 -> V_112 ,
V_387 ) ;
V_99 -> V_102 -> V_388 = NULL ;
break;
case V_321 :
V_99 -> V_102 -> V_388 = NULL ;
break;
case V_320 :
V_99 -> V_102 -> V_388 = & V_389 ;
break;
}
F_78 ( L_34 ) ;
return 0 ;
}
static int V_389 ( struct V_4 * V_5 , struct V_98 * V_99 ,
unsigned int V_390 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_390 != 0 )
return - V_391 ;
V_10 -> V_16 ( V_5 , V_386 | V_10 -> V_112 ,
V_387 ) ;
V_99 -> V_102 -> V_388 = NULL ;
return 1 ;
}
static int F_134 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 , unsigned int * V_70 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_246 -> V_167 < 1 )
return - V_391 ;
switch ( V_70 [ 0 ] ) {
case V_392 :
return F_135 ( V_5 , V_99 , V_246 , V_70 ) ;
case V_393 :
if ( V_58 . V_59 & V_60 ) {
if ( V_70 [ 1 ] & ~ ( V_270 |
V_271 |
V_272 |
V_273 ) ) {
return - V_391 ;
}
V_10 -> V_269 = V_70 [ 1 ] ;
} else if ( V_58 . V_59 == V_65 ) {
unsigned int V_394 ;
V_394 = V_70 [ 1 ] & 0xf ;
if ( V_394 > 0xF )
return - V_391 ;
V_10 -> V_269 = V_394 ;
F_38 ( V_394 , V_295 ) ;
} else {
unsigned int V_394 ;
unsigned int V_395 ;
V_394 = V_70 [ 1 ] & 0xf ;
V_395 = ( V_70 [ 1 ] >> 4 ) & 0xff ;
if ( V_394 >= 8 )
return - V_391 ;
V_10 -> V_269 = V_394 ;
if ( V_58 . V_59 == V_186 ) {
F_5 ( V_395 ,
V_396 ) ;
}
}
return 2 ;
default:
break;
}
return - V_391 ;
}
static int F_135 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 ,
unsigned int * V_70 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_397 , V_398 , V_399 ;
int V_174 = 0 ;
if ( ! V_58 . V_400 )
return - V_391 ;
if ( ( V_70 [ 1 ] & 0xffff0000 ) != V_401 ) {
V_70 [ 1 ] &= ( V_401 | 0xffff ) ;
V_174 ++ ;
}
if ( V_70 [ 2 ] >= V_58 . V_402 ) {
V_70 [ 2 ] = V_58 . V_402 - 1 ;
V_174 ++ ;
}
if ( V_70 [ 3 ] > 255 ) {
V_70 [ 3 ] = 255 ;
V_174 ++ ;
}
if ( V_70 [ 4 ] > 255 ) {
V_70 [ 4 ] = 255 ;
V_174 ++ ;
}
V_397 = V_70 [ 3 ] ;
V_398 = V_70 [ 4 ] ;
V_399 = V_70 [ 1 ] & 0xff ;
if ( V_399 & 0xf0 ) {
if ( V_398 < V_397 ) {
V_397 = V_70 [ 4 ] ;
V_398 = V_70 [ 3 ] ;
V_399 =
( ( V_70 [ 1 ] & 0xf ) << 4 ) | ( ( V_70 [ 1 ] & 0xf0 ) >> 4 ) ;
}
V_10 -> V_403 = V_397 ;
V_10 -> V_404 = V_398 ;
switch ( V_399 ) {
case 0x81 :
V_10 -> V_405 = 6 ;
break;
case 0x42 :
V_10 -> V_405 = 3 ;
break;
case 0x96 :
V_10 -> V_405 = 2 ;
break;
default:
V_70 [ 1 ] &= ~ 0xff ;
V_174 ++ ;
}
} else {
if ( V_398 != 0 ) {
V_70 [ 4 ] = 0 ;
V_174 ++ ;
}
switch ( V_399 ) {
case 0x06 :
V_10 -> V_404 = V_397 ;
V_10 -> V_405 = 0 ;
break;
case 0x09 :
V_10 -> V_403 = V_397 ;
V_10 -> V_405 = 1 ;
break;
default:
V_70 [ 1 ] &= ~ 0xff ;
V_174 ++ ;
}
}
if ( V_174 )
return - V_406 ;
return 5 ;
}
static void F_136 ( struct V_4 * V_5 , struct V_98 * V_99 ,
void * V_70 , unsigned int V_198 ,
unsigned int V_199 )
{
struct V_168 * V_102 = V_99 -> V_102 ;
unsigned int V_173 ;
unsigned int V_105 ;
unsigned int V_259 ;
unsigned int V_200 = V_198 / sizeof( short ) ;
short * V_201 = V_70 ;
V_259 = 1 << ( V_58 . V_407 - 1 ) ;
for ( V_105 = 0 ; V_105 < V_200 ; V_105 ++ ) {
V_173 = F_82 ( V_102 -> V_170 . V_176 [ V_199 ] ) ;
if ( V_58 . V_408 == 0 || ( V_173 & 1 ) == 0 )
V_201 [ V_105 ] -= V_259 ;
#ifdef F_24
V_201 [ V_105 ] = F_137 ( V_201 [ V_105 ] ) ;
#endif
V_199 ++ ;
V_199 %= V_102 -> V_170 . V_181 ;
}
}
static int F_138 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
unsigned int V_250 [] ,
unsigned int V_409 , int V_410 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_173 ;
unsigned int V_171 ;
unsigned int V_411 ;
int V_105 ;
int V_412 = 0 ;
if ( V_410 ) {
for ( V_105 = 0 ; V_105 < V_58 . V_413 ; ++ V_105 ) {
V_10 -> V_414 [ V_105 ] &= ~ V_415 ;
F_5 ( V_10 -> V_414 [ V_105 ] ,
F_139 ( V_105 ) ) ;
F_5 ( 0xf , F_140 ( V_105 ) ) ;
}
}
for ( V_105 = 0 ; V_105 < V_409 ; V_105 ++ ) {
const struct V_416 * V_417 ;
V_171 = F_110 ( V_250 [ V_105 ] ) ;
V_173 = F_82 ( V_250 [ V_105 ] ) ;
V_417 = V_99 -> V_418 -> V_173 + V_173 ;
V_412 = 0 ;
V_411 = 0 ;
switch ( V_417 -> V_419 - V_417 -> V_420 ) {
case 20000000 :
V_411 |= V_421 ;
F_5 ( 0 , F_141 ( V_171 ) ) ;
break;
case 10000000 :
V_411 |= V_422 ;
F_5 ( 0 , F_141 ( V_171 ) ) ;
break;
case 4000000 :
V_411 |= V_421 ;
F_5 ( V_423 ,
F_141 ( V_171 ) ) ;
break;
case 2000000 :
V_411 |= V_422 ;
F_5 ( V_423 ,
F_141 ( V_171 ) ) ;
break;
default:
F_6 ( L_35 ,
V_25 ) ;
break;
}
switch ( V_417 -> V_419 + V_417 -> V_420 ) {
case 0 :
V_411 |= V_424 ;
break;
case 10000000 :
V_411 |= V_425 ;
break;
default:
F_6 ( L_36 ,
V_25 ) ;
break;
}
if ( V_410 )
V_411 |= V_415 ;
F_5 ( V_411 , F_139 ( V_171 ) ) ;
V_10 -> V_414 [ V_171 ] = V_411 ;
F_5 ( V_105 , F_140 ( V_171 ) ) ;
}
return V_412 ;
}
static int F_142 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
unsigned int V_250 [] ,
unsigned int V_409 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_173 ;
unsigned int V_171 ;
unsigned int V_411 ;
int V_105 ;
int V_412 = 0 ;
for ( V_105 = 0 ; V_105 < V_409 ; V_105 ++ ) {
V_171 = F_110 ( V_250 [ V_105 ] ) ;
V_173 = F_82 ( V_250 [ V_105 ] ) ;
V_411 = F_143 ( V_171 ) ;
if ( V_58 . V_408 ) {
if ( ( V_173 & 1 ) == 0 ) {
V_411 |= V_426 ;
V_412 = ( 1 << ( V_58 . V_407 - 1 ) ) ;
} else {
V_412 = 0 ;
}
if ( V_173 & 2 )
V_411 |= V_427 ;
} else {
V_411 |= V_426 ;
V_412 = ( 1 << ( V_58 . V_407 - 1 ) ) ;
}
if ( V_250 [ V_105 ] & V_428 )
V_411 |= V_429 ;
V_411 |= ( F_112 ( V_250 [ V_105 ] ) ==
V_284 ) ? V_430 : 0 ;
F_38 ( V_411 , V_431 ) ;
V_10 -> V_414 [ V_171 ] = V_411 ;
}
return V_412 ;
}
static int F_144 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
unsigned int V_250 [] , unsigned int V_409 ,
int V_410 )
{
if ( V_58 . V_59 & V_60 )
return F_138 ( V_5 , V_99 , V_250 , V_409 ,
V_410 ) ;
else
return F_142 ( V_5 , V_99 , V_250 , V_409 ) ;
}
static int F_145 ( struct V_4 * V_5 ,
struct V_98 * V_99 , struct V_245 * V_246 ,
unsigned int * V_70 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_70 [ 0 ] = V_10 -> V_432 [ F_110 ( V_246 -> V_250 ) ] ;
return 1 ;
}
static int F_146 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 , unsigned int * V_70 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_171 = F_110 ( V_246 -> V_250 ) ;
unsigned int V_412 ;
V_412 = F_144 ( V_5 , V_99 , & V_246 -> V_250 , 1 , 0 ) ;
V_10 -> V_432 [ V_171 ] = V_70 [ 0 ] ;
if ( V_58 . V_59 & V_60 ) {
F_38 ( V_70 [ 0 ] , F_147 ( V_171 ) ) ;
} else
F_38 ( V_70 [ 0 ] ^ V_412 ,
( V_171 ) ? V_433 : V_434 ) ;
return 1 ;
}
static int F_148 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 , unsigned int * V_70 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_171 = F_110 ( V_246 -> V_250 ) ;
unsigned int V_412 ;
F_149 ( 1 << V_171 , V_435 ) ;
V_412 = 1 << ( V_58 . V_407 - 1 ) ;
F_144 ( V_5 , V_99 , & V_246 -> V_250 , 1 , 0 ) ;
V_10 -> V_432 [ V_171 ] = V_70 [ 0 ] ;
F_149 ( V_70 [ 0 ] ^ V_412 , F_150 ( V_171 ) ) ;
return 1 ;
}
static int F_151 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 , unsigned int * V_70 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
switch ( V_70 [ 0 ] ) {
case V_436 :
switch ( V_70 [ 1 ] ) {
case V_47 :
V_70 [ 2 ] = 1 + V_58 . V_182 * sizeof( short ) ;
if ( V_10 -> V_40 )
V_70 [ 2 ] += V_10 -> V_40 -> V_437 ;
break;
case V_44 :
V_70 [ 2 ] = 0 ;
break;
default:
return - V_391 ;
break;
}
return 0 ;
default:
break;
}
return - V_391 ;
}
static int F_152 ( struct V_4 * V_5 , struct V_98 * V_99 ,
unsigned int V_390 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_162 ;
int V_438 ;
int V_105 ;
static const int V_104 = 1000 ;
if ( V_390 != 0 )
return - V_391 ;
V_99 -> V_102 -> V_388 = NULL ;
F_42 ( V_5 , V_17 ,
V_163 | V_164 , 0 ) ;
V_438 = V_164 ;
#ifdef F_24
V_10 -> V_16 ( V_5 , 1 , V_184 ) ;
if ( V_58 . V_59 & V_177 )
F_39 ( V_5 , 0x6 , V_185 ) ;
V_162 = F_98 ( V_5 ) ;
if ( V_162 )
return V_162 ;
V_162 = F_58 ( V_5 ) ;
if ( V_162 < 0 )
return V_162 ;
#else
V_162 = F_84 ( V_5 , V_99 ) ;
if ( V_162 == 0 )
return - V_107 ;
V_438 |= V_163 ;
#endif
V_10 -> V_16 ( V_5 , V_10 -> V_439 | V_440 ,
V_441 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_439 , V_441 ) ;
for ( V_105 = 0 ; V_105 < V_104 ; V_105 ++ ) {
F_59 ( 1 ) ;
if ( ( V_10 -> V_72 ( V_5 ,
V_442 ) &
V_443 ) == 0 )
break;
}
if ( V_105 == V_104 ) {
F_19 ( V_5 ,
L_37 ) ;
return - V_207 ;
}
V_10 -> V_16 ( V_5 , V_148 ,
V_159 ) ;
F_42 ( V_5 , V_17 , V_438 , 1 ) ;
V_10 -> V_16 ( V_5 ,
V_10 -> V_444 | V_445 | V_446 | V_447
| V_448 | V_449 ,
V_450 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_451 | V_452 ,
V_453 ) ;
return 0 ;
}
static int F_153 ( struct V_4 * V_5 , struct V_98 * V_99 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
const struct V_169 * V_170 = & V_99 -> V_102 -> V_170 ;
int V_71 ;
int V_105 ;
unsigned V_454 ;
if ( V_5 -> V_78 == 0 ) {
F_19 ( V_5 , L_31 ) ;
return - V_207 ;
}
V_10 -> V_16 ( V_5 , V_455 , V_212 ) ;
V_10 -> V_16 ( V_5 , V_456 , V_450 ) ;
if ( V_58 . V_59 & V_177 ) {
F_149 ( V_457 , V_458 ) ;
V_71 = 0 ;
for ( V_105 = 0 ; V_105 < V_170 -> V_181 ; V_105 ++ ) {
int V_171 ;
V_171 = F_110 ( V_170 -> V_176 [ V_105 ] ) ;
V_71 |= 1 << V_171 ;
F_149 ( V_171 , V_459 ) ;
}
F_149 ( V_71 , V_460 ) ;
}
F_144 ( V_5 , V_99 , V_170 -> V_176 , V_170 -> V_181 , 1 ) ;
if ( V_170 -> V_327 == V_328 ) {
V_10 -> V_461 |= V_462 ;
V_10 -> V_461 &= ~ V_463 ;
} else {
V_10 -> V_461 &= ~ V_462 ;
V_10 -> V_461 |= V_463 ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_461 , V_464 ) ;
switch ( V_170 -> V_318 ) {
case V_320 :
case V_319 :
V_10 -> V_465 &=
~ ( V_466 | F_154 ( - 1 ) ) ;
V_10 -> V_465 |= V_467 | V_468 ;
V_10 -> V_16 ( V_5 , V_10 -> V_465 ,
V_469 ) ;
break;
case V_321 :
V_10 -> V_465 =
F_154 ( F_110 ( V_170 -> V_329 ) + 1 ) ;
if ( V_170 -> V_329 & V_330 )
V_10 -> V_465 |= V_466 ;
if ( V_170 -> V_329 & V_331 )
V_10 -> V_465 |= V_467 ;
V_10 -> V_16 ( V_5 , V_10 -> V_465 ,
V_469 ) ;
break;
default:
F_2 () ;
break;
}
V_10 -> V_439 &= ~ V_470 ;
V_10 -> V_16 ( V_5 , V_10 -> V_439 , V_441 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_461 , V_464 ) ;
V_10 -> V_471 &= ~ V_472 ;
V_10 -> V_16 ( V_5 , V_10 -> V_471 , V_473 ) ;
if ( V_170 -> V_327 == V_328 ) {
V_10 -> V_356 ( V_5 , 0xffffff , V_474 ) ;
} else {
V_10 -> V_356 ( V_5 , 0 , V_474 ) ;
}
V_10 -> V_16 ( V_5 , V_475 , V_450 ) ;
V_10 -> V_471 &= ~ V_476 ;
V_10 -> V_16 ( V_5 , V_10 -> V_471 , V_473 ) ;
switch ( V_170 -> V_327 ) {
case V_326 :
if ( V_58 . V_59 & V_60 ) {
V_10 -> V_356 ( V_5 , V_170 -> V_336 - 1 ,
V_477 ) ;
V_10 -> V_16 ( V_5 , V_478 ,
V_450 ) ;
} else {
V_10 -> V_356 ( V_5 , V_170 -> V_336 ,
V_477 ) ;
V_10 -> V_16 ( V_5 , V_478 ,
V_450 ) ;
V_10 -> V_356 ( V_5 , V_170 -> V_336 - 1 ,
V_477 ) ;
}
break;
case V_328 :
V_10 -> V_356 ( V_5 , 0xffffff , V_477 ) ;
V_10 -> V_16 ( V_5 , V_478 , V_450 ) ;
V_10 -> V_356 ( V_5 , 0xffffff , V_477 ) ;
break;
default:
V_10 -> V_356 ( V_5 , 0 , V_477 ) ;
V_10 -> V_16 ( V_5 , V_478 , V_450 ) ;
V_10 -> V_356 ( V_5 , V_170 -> V_336 , V_477 ) ;
}
V_10 -> V_461 &=
~ ( F_155 ( 0x1f ) | V_479 |
F_156 ( 0x1f ) | V_480 ) ;
switch ( V_170 -> V_322 ) {
case V_323 :
V_10 -> V_451 &= ~ V_481 ;
V_454 =
F_118 ( V_5 , V_170 -> V_332 ,
V_308 ) ;
V_10 -> V_356 ( V_5 , 1 , V_482 ) ;
V_10 -> V_16 ( V_5 , V_483 , V_450 ) ;
V_10 -> V_356 ( V_5 , V_454 , V_482 ) ;
break;
case V_321 :
V_10 -> V_461 |=
F_156 ( V_170 -> V_332 ) ;
if ( V_170 -> V_332 & V_330 )
V_10 -> V_461 |= V_480 ;
V_10 -> V_451 |= V_481 ;
break;
default:
F_2 () ;
break;
}
V_10 -> V_16 ( V_5 , V_10 -> V_451 , V_453 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_461 , V_464 ) ;
V_10 -> V_471 &=
~ ( F_157 ( 3 ) | V_484 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_471 , V_473 ) ;
if ( V_170 -> V_334 > 1 ) {
V_10 -> V_461 |= V_485 ;
V_10 -> V_16 ( V_5 ,
F_158 ( V_170 -> V_334 -
1 ) |
F_159
( V_486 ) ,
V_487 ) ;
} else {
unsigned V_71 ;
V_10 -> V_461 &= ~ V_485 ;
V_71 = F_159 ( V_486 ) ;
if ( V_58 .
V_59 & ( V_60 | V_177 ) ) {
V_71 |= F_158 ( 0 ) ;
} else {
V_71 |=
F_158 ( F_110 ( V_170 -> V_176 [ 0 ] ) ) ;
}
V_10 -> V_16 ( V_5 , V_71 , V_487 ) ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_461 , V_464 ) ;
V_10 -> V_16 ( V_5 , V_449 | V_448 ,
V_450 ) ;
V_10 -> V_439 |= V_488 ;
V_10 -> V_16 ( V_5 , V_10 -> V_439 , V_441 ) ;
V_10 -> V_471 &= ~ V_489 ;
#ifdef F_24
V_10 -> V_471 |= V_490 ;
#else
V_10 -> V_471 |= V_491 ;
#endif
V_10 -> V_471 &= ~ V_492 ;
V_10 -> V_16 ( V_5 , V_10 -> V_471 , V_473 ) ;
V_71 = V_493 | V_494 |
V_495 ;
if ( V_58 . V_182 )
V_71 |= V_496 ;
else
V_71 |= V_497 ;
#if 0
if (boardtype.reg_type & ni_reg_m_series_mask)
bits |= AO_Number_Of_DAC_Packages;
#endif
V_10 -> V_16 ( V_5 , V_71 , V_498 ) ;
V_10 -> V_16 ( V_5 , V_499 , V_500 ) ;
V_10 -> V_16 ( V_5 , V_501 , V_212 ) ;
if ( V_170 -> V_327 == V_326 ) {
V_10 -> V_16 ( V_5 , V_146 ,
V_159 ) ;
F_42 ( V_5 , V_17 ,
V_502 , 1 ) ;
}
V_99 -> V_102 -> V_388 = & F_152 ;
return 0 ;
}
static int F_160 ( struct V_4 * V_5 , struct V_98 * V_99 ,
struct V_169 * V_170 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_174 = 0 ;
int V_315 ;
if ( ( V_170 -> V_12 & V_317 ) == 0 )
V_170 -> V_12 |= V_317 ;
V_174 |= F_122 ( & V_170 -> V_318 , V_320 | V_321 ) ;
V_174 |= F_122 ( & V_170 -> V_322 ,
V_323 | V_321 ) ;
V_174 |= F_122 ( & V_170 -> V_324 , V_319 ) ;
V_174 |= F_122 ( & V_170 -> V_325 , V_326 ) ;
V_174 |= F_122 ( & V_170 -> V_327 , V_326 | V_328 ) ;
if ( V_174 )
return 1 ;
V_174 |= F_123 ( V_170 -> V_318 ) ;
V_174 |= F_123 ( V_170 -> V_322 ) ;
V_174 |= F_123 ( V_170 -> V_327 ) ;
if ( V_174 )
return 2 ;
if ( V_170 -> V_318 == V_321 ) {
unsigned int V_315 = F_110 ( V_170 -> V_329 ) ;
if ( V_315 > 18 )
V_315 = 18 ;
V_315 |= ( V_170 -> V_329 & ( V_330 | V_331 ) ) ;
V_174 |= F_124 ( & V_170 -> V_329 , V_315 ) ;
} else {
V_174 |= F_124 ( & V_170 -> V_329 , 0 ) ;
}
if ( V_170 -> V_322 == V_323 ) {
V_174 |= F_125 ( & V_170 -> V_332 ,
V_58 . V_503 ) ;
V_174 |= F_126 ( & V_170 -> V_332 ,
V_10 -> V_309 * 0xffffff ) ;
}
V_174 |= F_124 ( & V_170 -> V_333 , 0 ) ;
V_174 |= F_124 ( & V_170 -> V_334 , V_170 -> V_181 ) ;
if ( V_170 -> V_327 == V_326 )
V_174 |= F_126 ( & V_170 -> V_336 , 0x00ffffff ) ;
else
V_174 |= F_124 ( & V_170 -> V_336 , 0 ) ;
if ( V_174 )
return 3 ;
if ( V_170 -> V_322 == V_323 ) {
V_315 = V_170 -> V_332 ;
V_170 -> V_332 =
F_119 ( V_5 , F_118 ( V_5 ,
V_170 -> V_332 ,
V_170 ->
V_12 &
V_337 ) ) ;
if ( V_315 != V_170 -> V_332 )
V_174 ++ ;
}
if ( V_174 )
return 4 ;
if ( V_174 )
return 5 ;
return 0 ;
}
static int F_68 ( struct V_4 * V_5 , struct V_98 * V_99 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
F_27 ( V_5 ) ;
V_10 -> V_16 ( V_5 , V_455 , V_212 ) ;
V_10 -> V_16 ( V_5 , V_456 , V_450 ) ;
F_42 ( V_5 , V_17 , ~ 0 , 0 ) ;
V_10 -> V_16 ( V_5 , V_493 , V_498 ) ;
V_10 -> V_16 ( V_5 , 0x3f98 , V_159 ) ;
V_10 -> V_16 ( V_5 , V_493 | V_494 |
V_495 , V_498 ) ;
V_10 -> V_16 ( V_5 , 0 , V_487 ) ;
V_10 -> V_16 ( V_5 , 0 , V_500 ) ;
V_10 -> V_444 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_444 , V_450 ) ;
V_10 -> V_451 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_451 , V_453 ) ;
V_10 -> V_461 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_461 , V_464 ) ;
V_10 -> V_471 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_471 , V_473 ) ;
if ( V_58 . V_59 & V_60 )
V_10 -> V_439 = V_504 ;
else
V_10 -> V_439 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_439 , V_441 ) ;
V_10 -> V_465 = 0 ;
V_10 -> V_16 ( V_5 , V_10 -> V_465 ,
V_469 ) ;
if ( V_58 . V_59 & V_177 ) {
unsigned V_505 = 0 ;
unsigned V_105 ;
for ( V_105 = 0 ; V_105 < V_99 -> V_256 ; ++ V_105 ) {
V_505 |= 1 << V_105 ;
}
F_149 ( V_505 , V_435 ) ;
F_149 ( V_457 , V_458 ) ;
}
V_10 -> V_16 ( V_5 , V_501 , V_212 ) ;
return 0 ;
}
static int F_161 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 , unsigned int * V_70 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
#ifdef F_162
F_6 ( L_38 ,
F_110 ( V_246 -> V_250 ) , V_70 [ 0 ] ) ;
#endif
switch ( V_70 [ 0 ] ) {
case V_506 :
V_99 -> V_507 |= 1 << F_110 ( V_246 -> V_250 ) ;
break;
case V_508 :
V_99 -> V_507 &= ~ ( 1 << F_110 ( V_246 -> V_250 ) ) ;
break;
case V_509 :
V_70 [ 1 ] =
( V_99 ->
V_507 & ( 1 << F_110 ( V_246 -> V_250 ) ) ) ? V_47 :
V_44 ;
return V_246 -> V_167 ;
break;
default:
return - V_391 ;
}
V_10 -> V_510 &= ~ V_511 ;
V_10 -> V_510 |= F_163 ( V_99 -> V_507 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_510 , V_512 ) ;
return 1 ;
}
static int F_164 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 , unsigned int * V_70 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
#ifdef F_162
F_6 ( L_39 , V_70 [ 0 ] , V_70 [ 1 ] ) ;
#endif
if ( V_70 [ 0 ] ) {
if ( ( V_70 [ 0 ] & ( V_513 | V_514 ) )
&& V_10 -> V_515 )
return - V_42 ;
V_99 -> V_516 &= ~ V_70 [ 0 ] ;
V_99 -> V_516 |= ( V_70 [ 0 ] & V_70 [ 1 ] ) ;
V_10 -> V_517 &= ~ V_518 ;
V_10 -> V_517 |= F_165 ( V_99 -> V_516 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_517 ,
V_519 ) ;
}
V_70 [ 1 ] = V_10 -> V_72 ( V_5 , V_520 ) ;
return V_246 -> V_167 ;
}
static int F_166 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 ,
unsigned int * V_70 )
{
struct V_9 * V_10 V_196 = V_5 -> V_11 ;
#ifdef F_162
F_6 ( L_40 ,
F_110 ( V_246 -> V_250 ) , V_70 [ 0 ] ) ;
#endif
switch ( V_70 [ 0 ] ) {
case V_506 :
V_99 -> V_507 |= 1 << F_110 ( V_246 -> V_250 ) ;
break;
case V_508 :
V_99 -> V_507 &= ~ ( 1 << F_110 ( V_246 -> V_250 ) ) ;
break;
case V_509 :
V_70 [ 1 ] =
( V_99 ->
V_507 & ( 1 << F_110 ( V_246 -> V_250 ) ) ) ? V_47 :
V_44 ;
return V_246 -> V_167 ;
break;
default:
return - V_391 ;
}
F_32 ( V_99 -> V_507 , V_521 ) ;
return 1 ;
}
static int F_167 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 ,
unsigned int * V_70 )
{
struct V_9 * V_10 V_196 = V_5 -> V_11 ;
#ifdef F_162
F_6 ( L_41 , V_70 [ 0 ] ,
V_70 [ 1 ] ) ;
#endif
if ( V_70 [ 0 ] ) {
V_99 -> V_516 &= ~ V_70 [ 0 ] ;
V_99 -> V_516 |= ( V_70 [ 0 ] & V_70 [ 1 ] ) ;
F_32 ( V_99 -> V_516 , V_522 ) ;
}
V_70 [ 1 ] = F_33 ( V_523 ) ;
return V_246 -> V_167 ;
}
static int F_168 ( struct V_4 * V_5 ,
struct V_98 * V_99 , struct V_169 * V_170 )
{
int V_174 = 0 ;
int V_315 ;
unsigned V_105 ;
V_174 |= F_122 ( & V_170 -> V_318 , V_320 ) ;
V_174 |= F_122 ( & V_170 -> V_322 , V_321 ) ;
V_174 |= F_122 ( & V_170 -> V_324 , V_319 ) ;
V_174 |= F_122 ( & V_170 -> V_325 , V_326 ) ;
V_174 |= F_122 ( & V_170 -> V_327 , V_328 ) ;
if ( V_174 )
return 1 ;
if ( V_174 )
return 2 ;
V_174 |= F_124 ( & V_170 -> V_329 , 0 ) ;
V_315 = V_170 -> V_332 ;
V_315 &= F_169 ( V_524 , 0 , 0 , V_330 ) ;
if ( V_315 != V_170 -> V_332 )
V_174 |= - V_391 ;
V_174 |= F_124 ( & V_170 -> V_333 , 0 ) ;
V_174 |= F_124 ( & V_170 -> V_334 , V_170 -> V_181 ) ;
V_174 |= F_124 ( & V_170 -> V_336 , 0 ) ;
if ( V_174 )
return 3 ;
if ( V_174 )
return 4 ;
for ( V_105 = 0 ; V_105 < V_170 -> V_181 ; ++ V_105 ) {
if ( V_170 -> V_176 [ V_105 ] != V_105 )
V_174 = 1 ;
}
if ( V_174 )
return 5 ;
return 0 ;
}
static int F_170 ( struct V_4 * V_5 , struct V_98 * V_99 )
{
struct V_9 * V_10 V_196 = V_5 -> V_11 ;
const struct V_169 * V_170 = & V_99 -> V_102 -> V_170 ;
unsigned V_525 = V_526 | V_527 ;
int V_193 ;
F_32 ( V_528 , V_529 ) ;
switch ( V_170 -> V_322 ) {
case V_321 :
V_525 |=
F_110 ( V_170 -> V_332 ) &
V_524 ;
break;
default:
F_2 () ;
break;
}
if ( V_170 -> V_332 & V_330 )
V_525 |= V_530 ;
F_32 ( V_525 , V_531 ) ;
if ( V_99 -> V_507 ) {
F_32 ( V_99 -> V_516 , V_532 ) ;
F_32 ( V_533 , V_529 ) ;
F_32 ( V_99 -> V_507 , V_534 ) ;
} else {
F_19 ( V_5 ,
L_42 ) ;
return - V_207 ;
}
V_193 = F_23 ( V_5 ) ;
if ( V_193 < 0 ) {
return V_193 ;
}
V_99 -> V_102 -> V_388 = & V_535 ;
return 0 ;
}
static int V_535 ( struct V_4 * V_5 , struct V_98 * V_99 ,
unsigned int V_390 )
{
#ifdef F_24
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_12 ;
#endif
int V_193 = 0 ;
unsigned V_105 ;
const unsigned V_104 = 1000 ;
V_99 -> V_102 -> V_388 = NULL ;
F_99 ( V_99 -> V_102 , V_99 -> V_102 -> V_206 ) ;
#ifdef F_24
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_55 ) {
F_96 ( V_10 -> V_55 , 32 , 32 ) ;
F_97 ( V_10 -> V_55 ) ;
} else {
F_19 ( V_5 , L_43 ) ;
V_193 = - V_207 ;
}
F_8 ( & V_10 -> V_38 , V_12 ) ;
if ( V_193 < 0 )
return V_193 ;
#endif
for ( V_105 = 0 ; V_105 < V_104 ; ++ V_105 ) {
if ( F_33 ( V_536 ) & V_537 )
break;
F_59 ( 10 ) ;
}
if ( V_105 == V_104 ) {
F_19 ( V_5 , L_44 ) ;
F_70 ( V_5 , V_99 ) ;
return - V_207 ;
}
F_32 ( V_538 | V_539 |
V_540 ,
V_529 ) ;
return V_193 ;
}
static int F_70 ( struct V_4 * V_5 , struct V_98 * V_99 )
{
struct V_9 * V_10 V_196 = V_5 -> V_11 ;
F_32 ( V_541 | V_542 |
V_543 |
V_544 ,
V_529 ) ;
F_32 ( 0 , V_534 ) ;
F_29 ( V_5 ) ;
return 0 ;
}
static void F_53 ( struct V_4 * V_5 )
{
struct V_9 * V_10 V_196 = V_5 -> V_11 ;
unsigned V_545 ;
struct V_98 * V_99 = & V_5 -> V_100 [ V_117 ] ;
#ifdef F_24
unsigned long V_12 ;
#endif
if ( ( V_58 . V_59 & V_60 ) == 0 ) {
return;
}
#ifdef F_24
F_4 ( & V_10 -> V_38 , V_12 ) ;
if ( V_10 -> V_55 ) {
unsigned V_546 =
F_45 ( V_10 -> V_55 ) ;
if ( V_546 & V_91 ) {
F_46 ( V_92 ,
V_10 -> V_40 -> V_93 +
F_47 ( V_10 -> V_55 -> V_26 ) ) ;
}
F_57 ( V_10 -> V_55 , V_99 -> V_102 ) ;
}
F_8 ( & V_10 -> V_38 , V_12 ) ;
#endif
V_545 = F_33 ( V_536 ) ;
if ( V_545 & ( V_547 | V_548 ) ) {
F_32 ( V_549 , V_529 ) ;
V_99 -> V_102 -> V_110 |= V_116 ;
}
if ( V_545 & V_550 ) {
F_32 ( V_543 ,
V_529 ) ;
}
F_66 ( V_5 , V_99 ) ;
}
static int F_171 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 , unsigned int * V_70 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_174 = V_246 -> V_167 ;
unsigned char V_551 , V_552 = 0 ;
if ( V_246 -> V_167 != 2 )
return - V_391 ;
switch ( V_70 [ 0 ] ) {
case V_553 :
#ifdef F_162
F_6 ( L_45 , V_70 [ 1 ] ) ;
#endif
V_10 -> V_554 = 1 ;
V_10 -> V_510 |= V_555 ;
if ( V_70 [ 1 ] == V_556 ) {
V_10 -> V_554 = 0 ;
V_10 -> V_510 &= ~ ( V_555 |
V_557 ) ;
V_70 [ 1 ] = V_556 ;
V_10 -> V_515 = V_70 [ 1 ] ;
} else if ( V_70 [ 1 ] <= V_558 ) {
V_10 -> V_510 &= ~ V_559 ;
V_10 -> V_560 |= V_561 ;
V_10 -> V_560 &= ~ V_562 ;
V_70 [ 1 ] = V_558 ;
V_10 -> V_515 = V_70 [ 1 ] ;
} else if ( V_70 [ 1 ] <= V_563 ) {
V_10 -> V_510 &= ~ V_559 ;
V_10 -> V_560 |= V_561 |
V_562 ;
V_70 [ 1 ] = V_563 ;
V_10 -> V_515 = V_70 [ 1 ] ;
} else if ( V_70 [ 1 ] <= V_564 ) {
V_10 -> V_510 |= V_559 ;
V_10 -> V_560 |= V_561 |
V_562 ;
V_70 [ 1 ] = V_564 ;
V_10 -> V_515 = V_70 [ 1 ] ;
} else {
V_10 -> V_510 &= ~ ( V_555 |
V_557 ) ;
V_10 -> V_554 = 0 ;
V_70 [ 1 ] = ( V_70 [ 1 ] / 1000 ) * 1000 ;
V_10 -> V_515 = V_70 [ 1 ] ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_510 ,
V_512 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_560 ,
V_565 ) ;
return 1 ;
break;
case V_566 :
if ( V_10 -> V_515 == 0 ) {
return - V_391 ;
}
V_551 = V_70 [ 1 ] & 0xFF ;
if ( V_10 -> V_554 ) {
V_174 = F_172 ( V_5 , V_99 , V_551 ,
& V_552 ) ;
} else if ( V_10 -> V_515 > 0 ) {
V_174 = F_173 ( V_5 , V_99 , V_551 ,
& V_552 ) ;
} else {
F_6 ( L_46 ) ;
return - V_391 ;
}
if ( V_174 < 0 )
return V_174 ;
V_70 [ 1 ] = V_552 & 0xFF ;
return V_246 -> V_167 ;
break;
default:
return - V_391 ;
}
}
static int F_172 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
unsigned char V_567 ,
unsigned char * V_568 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_569 ;
int V_174 = 0 , V_242 = 20 ;
#ifdef F_162
F_6 ( L_47 , V_567 ) ;
#endif
V_10 -> V_517 &= ~ V_570 ;
V_10 -> V_517 |= F_174 ( V_567 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_517 , V_519 ) ;
V_569 = V_10 -> V_72 ( V_5 , V_571 ) ;
if ( V_569 & V_572 ) {
V_174 = - V_42 ;
goto Error;
}
V_10 -> V_510 |= V_573 ;
V_10 -> V_16 ( V_5 , V_10 -> V_510 , V_512 ) ;
V_10 -> V_510 &= ~ V_573 ;
while ( ( V_569 =
V_10 -> V_72 ( V_5 ,
V_571 ) ) &
V_572 ) {
F_59 ( ( V_10 -> V_515 + 999 ) / 1000 ) ;
if ( -- V_242 < 0 ) {
F_6
( L_48 ) ;
V_174 = - V_254 ;
goto Error;
}
}
F_59 ( ( V_10 -> V_515 + 999 ) / 1000 ) ;
if ( V_568 != NULL ) {
* V_568 = V_10 -> V_72 ( V_5 , V_574 ) ;
#ifdef F_162
F_6 ( L_49 , * V_568 ) ;
#endif
}
Error:
V_10 -> V_16 ( V_5 , V_10 -> V_510 , V_512 ) ;
return V_174 ;
}
static int F_173 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
unsigned char V_567 ,
unsigned char * V_568 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned char V_247 , V_575 = 0 ;
#ifdef F_162
F_6 ( L_50 , V_567 ) ;
#endif
F_59 ( ( V_10 -> V_515 + 999 ) / 1000 ) ;
for ( V_247 = 0x80 ; V_247 ; V_247 >>= 1 ) {
V_10 -> V_517 &= ~ V_514 ;
if ( V_567 & V_247 ) {
V_10 -> V_517 |= V_514 ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_517 ,
V_519 ) ;
V_10 -> V_510 |= V_557 ;
V_10 -> V_16 ( V_5 , V_10 -> V_510 ,
V_512 ) ;
F_59 ( ( V_10 -> V_515 + 999 ) / 2000 ) ;
V_10 -> V_510 &= ~ V_557 ;
V_10 -> V_16 ( V_5 , V_10 -> V_510 ,
V_512 ) ;
F_59 ( ( V_10 -> V_515 + 999 ) / 2000 ) ;
if ( V_10 -> V_72 ( V_5 ,
V_520 ) & V_513 )
{
V_575 |= V_247 ;
}
}
#ifdef F_162
F_6 ( L_51 , V_575 ) ;
#endif
if ( V_568 )
* V_568 = V_575 ;
return 0 ;
}
static void F_175 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_98 * V_99 ;
if ( V_10 ) {
if ( V_10 -> V_52 ) {
F_176 ( V_10 -> V_52 ) ;
}
}
if ( V_5 -> V_100 && V_58 . V_576 ) {
V_99 = & V_5 -> V_100 [ V_577 ] ;
F_177 ( V_5 , V_99 ) ;
}
}
static void F_178 ( struct V_4 * V_5 , struct V_98 * V_99 )
{
int V_105 ;
for ( V_105 = 0 ; V_105 < V_99 -> V_256 ; V_105 ++ ) {
F_37 ( V_5 , F_143 ( V_105 ) | 0x0 ,
V_578 ) ;
}
F_149 ( 0x0 , V_579 ) ;
}
static unsigned F_179 ( enum V_580 V_6 )
{
unsigned V_581 ;
switch ( V_6 ) {
case V_582 :
V_581 = F_180 ( 0 ) ;
break;
case V_583 :
V_581 = F_180 ( 1 ) ;
break;
case V_584 :
V_581 = F_181 ( 0 ) ;
break;
case V_585 :
V_581 = F_181 ( 1 ) ;
break;
case V_586 :
V_581 = F_182 ( 0 ) ;
break;
case V_587 :
V_581 = F_182 ( 1 ) ;
break;
case V_588 :
V_581 = F_183 ( 0 ) ;
break;
case V_589 :
V_581 = F_183 ( 1 ) ;
break;
case V_590 :
V_581 = F_184 ( 0 ) ;
break;
case V_591 :
V_581 = F_184 ( 1 ) ;
break;
case V_592 :
V_581 = F_185 ( 0 ) ;
break;
case V_593 :
V_581 = F_185 ( 1 ) ;
break;
case V_594 :
V_581 = F_186 ( 0 ) ;
break;
case V_595 :
V_581 = F_186 ( 1 ) ;
break;
case V_596 :
V_581 = F_187 ( 0 ) ;
break;
case V_597 :
V_581 = F_187 ( 1 ) ;
break;
case V_598 :
V_581 = V_599 ;
break;
case V_600 :
V_581 = V_212 ;
break;
case V_601 :
V_581 = V_571 ;
break;
case V_602 :
V_581 = V_442 ;
break;
case V_603 :
V_581 = V_127 ;
break;
case V_604 :
V_581 = V_159 ;
break;
case V_605 :
V_581 = V_88 ;
break;
case V_606 :
V_581 = V_89 ;
break;
case V_607 :
V_581 = V_14 ;
break;
case V_608 :
V_581 = V_17 ;
break;
default:
F_6 ( L_52 ,
V_25 , V_6 ) ;
F_2 () ;
return 0 ;
break;
}
return V_581 ;
}
static void F_188 ( struct V_609 * V_610 , unsigned V_71 ,
enum V_580 V_6 )
{
struct V_4 * V_5 = V_610 -> V_52 -> V_5 ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned V_581 ;
static const unsigned V_611 = V_612 | V_613 ;
static const unsigned V_614 =
V_615 | V_616 ;
static const unsigned V_617 =
V_618 | V_619 ;
switch ( V_6 ) {
case V_620 :
F_38 ( V_71 , V_621 ) ;
break;
case V_622 :
F_38 ( V_71 , V_623 ) ;
break;
case V_624 :
F_38 ( V_71 , V_625 ) ;
break;
case V_626 :
F_38 ( V_71 , V_627 ) ;
break;
case V_628 :
F_38 ( V_71 , V_629 ) ;
break;
case V_630 :
F_38 ( V_71 , V_631 ) ;
break;
case V_632 :
F_38 ( V_71 , V_633 ) ;
break;
case V_634 :
F_38 ( V_71 , V_635 ) ;
break;
case V_592 :
case V_593 :
case V_594 :
case V_595 :
V_581 = F_179 ( V_6 ) ;
V_10 -> V_356 ( V_5 , V_71 , V_581 ) ;
break;
case V_607 :
F_17 ( V_71 & ~ V_614 ) ;
F_3 ( V_5 , V_14 ,
V_614 , V_71 ) ;
break;
case V_608 :
F_17 ( V_71 & ~ V_617 ) ;
F_3 ( V_5 , V_17 ,
V_617 , V_71 ) ;
break;
case V_600 :
F_17 ( V_71 & ~ V_611 ) ;
default:
V_581 = F_179 ( V_6 ) ;
V_10 -> V_16 ( V_5 , V_71 , V_581 ) ;
}
}
static unsigned F_189 ( struct V_609 * V_610 ,
enum V_580 V_6 )
{
struct V_4 * V_5 = V_610 -> V_52 -> V_5 ;
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned V_581 ;
switch ( V_6 ) {
case V_636 :
return F_41 ( V_637 ) ;
break;
case V_638 :
return F_41 ( V_639 ) ;
break;
case V_586 :
case V_587 :
case V_588 :
case V_589 :
V_581 = F_179 ( V_6 ) ;
return V_10 -> V_640 ( V_5 , V_581 ) ;
break;
default:
V_581 = F_179 ( V_6 ) ;
return V_10 -> V_72 ( V_5 , V_581 ) ;
break;
}
return 0 ;
}
static int F_190 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 , unsigned int * V_70 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_70 [ 0 ] = V_10 -> V_560 & V_641 ;
return 1 ;
}
static int F_191 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 , unsigned int * V_70 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_10 -> V_560 &= ~ V_642 ;
V_10 -> V_16 ( V_5 , V_10 -> V_560 ,
V_565 ) ;
V_10 -> V_560 &= ~ V_641 ;
V_10 -> V_560 |= F_192 ( V_70 [ 0 ] ) ;
V_10 -> V_560 |= V_642 ;
V_10 -> V_16 ( V_5 , V_10 -> V_560 ,
V_565 ) ;
return V_246 -> V_167 ;
}
static int F_193 ( struct V_4 * V_5 ,
unsigned int V_643 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
switch ( V_643 ) {
case V_644 :
V_10 -> V_560 &= ~ V_645 ;
break;
case V_646 :
V_10 -> V_560 |= V_645 ;
break;
default:
return - V_391 ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_560 ,
V_565 ) ;
return 3 ;
}
static void F_194 ( struct V_4 * V_5 ,
unsigned int * V_643 ,
unsigned int * V_647 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_10 -> V_560 & V_645 ) {
* V_643 = V_646 ;
* V_647 = V_648 ;
} else {
* V_643 = V_644 ;
* V_647 = V_649 * 2 ;
}
}
static int F_195 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 , unsigned int * V_70 )
{
switch ( V_70 [ 0 ] ) {
case V_650 :
return F_193 ( V_5 , V_70 [ 1 ] ) ;
break;
case V_651 :
F_194 ( V_5 , & V_70 [ 1 ] , & V_70 [ 2 ] ) ;
return 3 ;
default:
break;
}
return - V_391 ;
}
static int F_196 ( struct V_4 * V_5 )
{
struct V_9 * V_10 ;
V_10 = F_197 ( sizeof( * V_10 ) , V_652 ) ;
if ( ! V_10 )
return - V_653 ;
V_5 -> V_11 = V_10 ;
F_198 ( & V_10 -> V_74 ) ;
F_198 ( & V_10 -> V_13 ) ;
F_198 ( & V_10 -> V_38 ) ;
return 0 ;
}
static int F_199 ( int V_43 , int V_654 , int V_70 , unsigned long V_655 )
{
struct V_4 * V_5 = (struct V_4 * ) V_655 ;
struct V_9 * V_10 V_196 = V_5 -> V_11 ;
if ( V_43 ) {
F_5 ( V_70 , V_656 + 2 * V_654 ) ;
return 0 ;
} else {
return F_89 ( V_656 + 2 * V_654 ) ;
}
}
static int F_200 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 , unsigned int * V_70 )
{
V_70 [ 0 ] = F_201 ( V_5 , F_110 ( V_246 -> V_250 ) ) ;
return 1 ;
}
static int F_201 ( struct V_4 * V_5 , int V_73 )
{
struct V_9 * V_10 V_196 = V_5 -> V_11 ;
int V_657 ;
int V_658 ;
V_658 = 0x0300 | ( ( V_73 & 0x100 ) << 3 ) | ( V_73 & 0xff ) ;
F_5 ( 0x04 , V_659 ) ;
for ( V_657 = 0x8000 ; V_657 ; V_657 >>= 1 ) {
F_5 ( 0x04 | ( ( V_657 & V_658 ) ? 0x02 : 0 ) ,
V_659 ) ;
F_5 ( 0x05 | ( ( V_657 & V_658 ) ? 0x02 : 0 ) ,
V_659 ) ;
}
V_658 = 0 ;
for ( V_657 = 0x80 ; V_657 ; V_657 >>= 1 ) {
F_5 ( 0x04 , V_659 ) ;
F_5 ( 0x05 , V_659 ) ;
V_658 |= ( ( F_89 ( V_197 ) & V_660 ) ? V_657 : 0 ) ;
}
F_5 ( 0x00 , V_659 ) ;
return V_658 ;
}
static int F_202 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 ,
unsigned int * V_70 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_70 [ 0 ] = V_10 -> V_661 [ F_110 ( V_246 -> V_250 ) ] ;
return 1 ;
}
static int F_203 ( struct V_4 * V_5 , unsigned int * V_70 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_70 [ 1 ] = V_10 -> V_662 * V_10 -> V_309 ;
V_70 [ 2 ] = V_10 -> V_663 * V_10 -> V_309 ;
return 3 ;
}
static int F_204 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 , unsigned int * V_70 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned V_664 , V_665 ;
switch ( V_70 [ 0 ] ) {
case V_666 :
switch ( V_70 [ 1 ] ) {
case V_308 :
V_664 =
( V_70 [ 2 ] +
V_10 -> V_309 / 2 ) / V_10 -> V_309 ;
break;
case V_310 :
V_664 = V_70 [ 2 ] / V_10 -> V_309 ;
break;
case V_311 :
V_664 =
( V_70 [ 2 ] + V_10 -> V_309 -
1 ) / V_10 -> V_309 ;
break;
default:
return - V_391 ;
break;
}
switch ( V_70 [ 3 ] ) {
case V_308 :
V_665 =
( V_70 [ 4 ] +
V_10 -> V_309 / 2 ) / V_10 -> V_309 ;
break;
case V_310 :
V_665 = V_70 [ 4 ] / V_10 -> V_309 ;
break;
case V_311 :
V_665 =
( V_70 [ 4 ] + V_10 -> V_309 -
1 ) / V_10 -> V_309 ;
break;
default:
return - V_391 ;
break;
}
if ( V_664 * V_10 -> V_309 != V_70 [ 2 ] ||
V_665 * V_10 -> V_309 != V_70 [ 4 ] ) {
V_70 [ 2 ] = V_664 * V_10 -> V_309 ;
V_70 [ 4 ] = V_665 * V_10 -> V_309 ;
return - V_406 ;
}
F_32 ( F_205 ( V_664 ) |
F_206 ( V_665 ) ,
V_667 ) ;
V_10 -> V_662 = V_664 ;
V_10 -> V_663 = V_665 ;
return 5 ;
break;
case V_668 :
return F_203 ( V_5 , V_70 ) ;
break;
default:
return - V_391 ;
break;
}
return 0 ;
}
static int F_207 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 , unsigned int * V_70 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned V_664 , V_665 ;
switch ( V_70 [ 0 ] ) {
case V_666 :
switch ( V_70 [ 1 ] ) {
case V_308 :
V_664 =
( V_70 [ 2 ] +
V_10 -> V_309 / 2 ) / V_10 -> V_309 ;
break;
case V_310 :
V_664 = V_70 [ 2 ] / V_10 -> V_309 ;
break;
case V_311 :
V_664 =
( V_70 [ 2 ] + V_10 -> V_309 -
1 ) / V_10 -> V_309 ;
break;
default:
return - V_391 ;
break;
}
switch ( V_70 [ 3 ] ) {
case V_308 :
V_665 =
( V_70 [ 4 ] +
V_10 -> V_309 / 2 ) / V_10 -> V_309 ;
break;
case V_310 :
V_665 = V_70 [ 4 ] / V_10 -> V_309 ;
break;
case V_311 :
V_665 =
( V_70 [ 4 ] + V_10 -> V_309 -
1 ) / V_10 -> V_309 ;
break;
default:
return - V_391 ;
break;
}
if ( V_664 * V_10 -> V_309 != V_70 [ 2 ] ||
V_665 * V_10 -> V_309 != V_70 [ 4 ] ) {
V_70 [ 2 ] = V_664 * V_10 -> V_309 ;
V_70 [ 4 ] = V_665 * V_10 -> V_309 ;
return - V_406 ;
}
F_32 ( V_664 , V_669 ) ;
V_10 -> V_662 = V_664 ;
F_32 ( V_665 , V_670 ) ;
V_10 -> V_663 = V_665 ;
return 5 ;
break;
case V_668 :
return F_203 ( V_5 , V_70 ) ;
default:
return - V_391 ;
break;
}
return 0 ;
}
static int F_208 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 , unsigned int * V_70 )
{
F_209 ( V_5 , F_110 ( V_246 -> V_250 ) , V_70 [ 0 ] ) ;
return 1 ;
}
static int F_210 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 , unsigned int * V_70 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_70 [ 0 ] = V_10 -> V_671 [ F_110 ( V_246 -> V_250 ) ] ;
return 1 ;
}
static void F_211 ( struct V_4 * V_5 , struct V_98 * V_99 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_105 , V_672 ;
int V_673 ;
int V_409 = 0 ;
int V_674 ;
int V_675 = 0 ;
int type ;
int V_171 ;
type = V_58 . V_676 [ 0 ] ;
if ( type == V_677 )
return;
V_674 = V_671 [ type ] . V_674 ;
for ( V_105 = 0 ; V_105 < 3 ; V_105 ++ ) {
type = V_58 . V_676 [ V_105 ] ;
if ( type == V_677 )
break;
if ( V_671 [ type ] . V_674 != V_674 )
V_675 = 1 ;
V_409 += V_671 [ type ] . V_409 ;
}
V_673 = V_105 ;
V_99 -> V_256 = V_409 ;
if ( V_675 ) {
unsigned int * V_678 ;
if ( V_409 > V_679 ) {
F_6 ( L_53 ) ;
}
V_99 -> V_678 = V_678 = V_10 -> V_680 ;
V_171 = 0 ;
for ( V_105 = 0 ; V_105 < V_673 ; V_105 ++ ) {
type = V_58 . V_676 [ V_105 ] ;
for ( V_672 = 0 ; V_672 < V_671 [ type ] . V_409 ; V_672 ++ ) {
V_678 [ V_171 ] =
( 1 << V_671 [ type ] . V_674 ) - 1 ;
V_171 ++ ;
}
}
for ( V_171 = 0 ; V_171 < V_99 -> V_256 ; V_171 ++ )
F_209 ( V_5 , V_105 , V_99 -> V_678 [ V_105 ] / 2 ) ;
} else {
type = V_58 . V_676 [ 0 ] ;
V_99 -> V_681 = ( 1 << V_671 [ type ] . V_674 ) - 1 ;
for ( V_171 = 0 ; V_171 < V_99 -> V_256 ; V_171 ++ )
F_209 ( V_5 , V_105 , V_99 -> V_681 / 2 ) ;
}
}
static void F_209 ( struct V_4 * V_5 , int V_73 , int V_682 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_683 = 0 , V_71 = 0 , V_657 , V_658 = 0 ;
int V_105 ;
int type ;
if ( V_10 -> V_671 [ V_73 ] == V_682 )
return;
V_10 -> V_671 [ V_73 ] = V_682 ;
for ( V_105 = 0 ; V_105 < 3 ; V_105 ++ ) {
type = V_58 . V_676 [ V_105 ] ;
if ( type == V_677 )
break;
if ( V_73 < V_671 [ type ] . V_409 ) {
V_71 = V_671 [ type ] . F_212 ( V_73 , V_682 , & V_658 ) ;
V_683 = F_213 ( V_105 ) ;
break;
}
V_73 -= V_671 [ type ] . V_409 ;
}
for ( V_657 = 1 << ( V_71 - 1 ) ; V_657 ; V_657 >>= 1 ) {
F_5 ( ( ( V_657 & V_658 ) ? 0x02 : 0 ) , V_659 ) ;
F_59 ( 1 ) ;
F_5 ( 1 | ( ( V_657 & V_658 ) ? 0x02 : 0 ) , V_659 ) ;
F_59 ( 1 ) ;
}
F_5 ( V_683 , V_659 ) ;
F_59 ( 1 ) ;
F_5 ( 0 , V_659 ) ;
}
static int F_214 ( int V_73 , int V_682 , int * V_658 )
{
V_73 ++ ;
* V_658 = ( ( V_73 & 0x1 ) << 11 ) |
( ( V_73 & 0x2 ) << 9 ) |
( ( V_73 & 0x4 ) << 7 ) | ( ( V_73 & 0x8 ) << 5 ) | ( V_682 & 0xff ) ;
return 12 ;
}
static int F_215 ( int V_73 , int V_682 , int * V_658 )
{
* V_658 = ( ( V_73 & 0x7 ) << 8 ) | ( V_682 & 0xff ) ;
return 11 ;
}
static int F_216 ( int V_73 , int V_682 , int * V_658 )
{
* V_658 = V_682 & 0xfff ;
return 12 ;
}
static int F_217 ( int V_73 , int V_682 , int * V_658 )
{
* V_658 = ( V_682 & 0xfff ) | ( V_73 ? 0xc000 : 0xa000 ) ;
return 16 ;
}
static int F_218 ( int V_73 , int V_682 , int * V_658 )
{
* V_658 = ( ( V_73 & 0xf ) << 8 ) | ( V_682 & 0xff ) ;
return 12 ;
}
static int F_219 ( int V_73 , int V_682 , int * V_658 )
{
* V_658 = ( ( V_73 + 1 ) << 8 ) | ( V_682 & 0xff ) ;
return 12 ;
}
static int F_220 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 , unsigned int * V_70 )
{
struct V_609 * V_610 = V_99 -> V_11 ;
return F_221 ( V_610 , V_246 , V_70 ) ;
}
static int F_222 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 , unsigned int * V_70 )
{
struct V_609 * V_610 = V_99 -> V_11 ;
return F_223 ( V_610 , V_246 , V_70 ) ;
}
static int F_224 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 , unsigned int * V_70 )
{
struct V_609 * V_610 = V_99 -> V_11 ;
return F_225 ( V_610 , V_246 , V_70 ) ;
}
static int F_226 ( struct V_4 * V_5 , struct V_98 * V_99 )
{
int V_193 ;
#ifdef F_24
struct V_609 * V_610 = V_99 -> V_11 ;
V_193 = F_21 ( V_5 , V_610 -> V_1 ,
V_44 ) ;
if ( V_193 ) {
F_19 ( V_5 ,
L_54 ) ;
return V_193 ;
}
F_227 ( V_610 , NULL , NULL , NULL , NULL ) ;
F_30 ( V_5 , V_610 -> V_1 , 1 ) ;
V_193 = F_228 ( V_610 , V_99 -> V_102 ) ;
#else
V_193 = - V_684 ;
#endif
return V_193 ;
}
static int F_229 ( struct V_4 * V_5 ,
struct V_98 * V_99 , struct V_169 * V_170 )
{
#ifdef F_24
struct V_609 * V_610 = V_99 -> V_11 ;
return F_230 ( V_610 , V_170 ) ;
#else
return - V_684 ;
#endif
}
static int F_69 ( struct V_4 * V_5 , struct V_98 * V_99 )
{
#ifdef F_24
struct V_609 * V_610 = V_99 -> V_11 ;
int V_193 ;
V_193 = F_231 ( V_610 ) ;
F_30 ( V_5 , V_610 -> V_1 , 0 ) ;
F_28 ( V_5 , V_610 -> V_1 ) ;
return V_193 ;
#else
return 0 ;
#endif
}
static int F_232 ( struct V_4 * V_5 , unsigned V_171 ,
unsigned V_685 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned V_686 ;
unsigned V_687 ;
if ( ( V_685 & 0x1f ) != V_685 )
return - V_391 ;
V_686 = 1 + V_171 / 3 ;
V_687 = V_686 - 1 ;
V_10 -> V_688 [ V_687 ] &=
~ F_233 ( V_171 ) ;
V_10 -> V_688 [ V_687 ] |=
F_234 ( V_171 , V_685 ) ;
F_38 ( V_10 -> V_688 [ V_687 ] ,
F_235 ( V_686 ) ) ;
return 2 ;
}
static int F_236 ( struct V_4 * V_5 , unsigned V_171 ,
unsigned V_685 )
{
if ( V_685 != F_237 ( V_5 , V_171 ) )
return - V_391 ;
return 2 ;
}
static int F_238 ( struct V_4 * V_5 , unsigned V_171 ,
unsigned V_685 )
{
if ( V_58 . V_59 & V_60 )
return F_232 ( V_5 , V_171 , V_685 ) ;
else
return F_236 ( V_5 , V_171 , V_685 ) ;
}
static unsigned F_239 ( struct V_4 * V_5 ,
unsigned V_171 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
const unsigned V_687 = V_171 / 3 ;
return F_240 ( V_171 ,
V_10 ->
V_688
[ V_687 ] ) ;
}
static unsigned F_237 ( struct V_4 * V_5 , unsigned V_171 )
{
switch ( V_171 ) {
case 0 :
return V_689 ;
break;
case 1 :
return V_690 ;
break;
case 2 :
return V_691 ;
break;
case 3 :
return V_692 ;
break;
case 4 :
return V_693 ;
break;
case 5 :
return V_694 ;
break;
case 6 :
return V_695 ;
break;
case 7 :
return V_696 ;
break;
case 8 :
return V_697 ;
break;
case 9 :
return V_698 ;
break;
default:
F_6 ( L_55 , V_25 ) ;
break;
}
return 0 ;
}
static unsigned F_241 ( struct V_4 * V_5 , unsigned V_171 )
{
if ( V_58 . V_59 & V_60 )
return F_239 ( V_5 , V_171 ) ;
else
return F_237 ( V_5 , V_171 ) ;
}
static int F_242 ( struct V_4 * V_5 , unsigned V_699 ,
enum V_700 V_701 )
{
struct V_9 * V_10 V_196 = V_5 -> V_11 ;
unsigned V_71 ;
if ( ( V_58 . V_59 & V_60 ) == 0 ) {
return - V_684 ;
}
V_71 = F_33 ( V_702 ) ;
V_71 &= ~ F_243 ( V_699 ) ;
V_71 |= F_244 ( V_699 , V_701 ) ;
F_32 ( V_71 , V_702 ) ;
return 0 ;
}
static int F_245 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 , unsigned int * V_70 )
{
struct V_9 * V_10 V_196 = V_5 -> V_11 ;
if ( ( V_58 . V_59 & V_60 ) == 0 ) {
return - V_684 ;
}
if ( V_70 [ 0 ] ) {
V_99 -> V_516 &= ~ V_70 [ 0 ] ;
V_99 -> V_516 |= ( V_70 [ 0 ] & V_70 [ 1 ] ) ;
F_38 ( V_99 -> V_516 , V_703 ) ;
}
V_70 [ 1 ] = F_41 ( V_704 ) ;
return V_246 -> V_167 ;
}
static int F_246 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 , unsigned int * V_70 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_171 ;
if ( V_246 -> V_167 < 1 )
return - V_391 ;
V_171 = F_110 ( V_246 -> V_250 ) ;
switch ( V_70 [ 0 ] ) {
case V_47 :
F_42 ( V_5 , V_19 , 1 << V_171 , 1 ) ;
break;
case V_44 :
F_42 ( V_5 , V_19 , 1 << V_171 , 0 ) ;
break;
case V_509 :
V_70 [ 1 ] =
( V_10 -> V_20 & ( 1 << V_171 ) ) ?
V_47 : V_44 ;
return 0 ;
break;
case V_705 :
return F_238 ( V_5 , V_171 , V_70 [ 1 ] ) ;
break;
case V_706 :
V_70 [ 1 ] = F_241 ( V_5 , V_171 ) ;
break;
case V_707 :
return F_242 ( V_5 , V_171 , V_70 [ 1 ] ) ;
break;
default:
return - V_391 ;
}
return 0 ;
}
static void F_247 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
V_10 -> V_708 = V_709 ;
if ( F_248 ( V_5 , V_710 , 0 ) < 0 ) {
F_6 ( L_56 ) ;
}
V_10 -> V_711 =
F_249 ( 0 ,
V_712 ) |
F_249 ( 1 ,
V_713 ) |
F_249 ( 2 ,
V_714 ) |
F_249 ( 3 , V_715 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_711 ,
V_716 ) ;
V_10 -> V_717 =
F_249 ( 4 ,
V_718 ) |
F_249 ( 5 ,
V_719 ) |
F_249 ( 6 , V_720 ) ;
if ( V_58 . V_59 & V_60 )
V_10 -> V_717 |=
F_249 ( 7 , V_721 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_717 ,
V_722 ) ;
}
static int F_250 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 , unsigned int * V_70 )
{
V_70 [ 1 ] = 0 ;
return V_246 -> V_167 ;
}
static int F_251 ( unsigned V_723 ,
unsigned * V_724 ,
unsigned * V_725 ,
unsigned * V_726 )
{
unsigned div ;
unsigned V_727 = 1 ;
static const unsigned V_728 = 0x10 ;
unsigned V_729 ;
unsigned V_730 = 1 ;
static const unsigned V_731 = 0x100 ;
static const unsigned V_732 = 1000 ;
const unsigned V_733 = V_723 * V_732 ;
static const unsigned V_734 = 12500 ;
static const unsigned V_735 = 4 ;
int V_736 = 0 ;
for ( div = 1 ; div <= V_728 ; ++ div ) {
for ( V_729 = 1 ; V_729 <= V_731 ; ++ V_729 ) {
unsigned V_737 =
( V_733 * div ) / V_729 ;
if ( abs ( V_737 - V_734 ) <
abs ( V_736 - V_734 ) ) {
V_736 = V_737 ;
V_727 = div ;
V_730 = V_729 ;
}
}
}
if ( V_736 == 0 ) {
F_6 ( L_57 , V_25 ) ;
return - V_207 ;
}
* V_724 = V_727 ;
* V_725 = V_730 ;
* V_726 =
( V_736 * V_735 +
( V_732 / 2 ) ) / V_732 ;
return 0 ;
}
static inline unsigned F_252 ( struct V_4 * V_5 )
{
if ( V_58 . V_59 & V_60 )
return 8 ;
else
return 7 ;
}
static int F_253 ( struct V_4 * V_5 ,
unsigned V_685 , unsigned V_738 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
static const unsigned V_739 = 50 ;
static const unsigned V_740 = 1000 ;
static const unsigned V_104 = 1000 ;
unsigned V_741 ;
unsigned V_724 ;
unsigned V_725 ;
unsigned V_105 ;
int V_193 ;
if ( V_685 == V_742 )
V_738 = 100 ;
if ( V_738 < V_739 || V_738 > V_740 ) {
F_6
( L_58
L_59 , V_25 ,
V_739 , V_740 ) ;
return - V_391 ;
}
V_10 -> V_743 &= ~ V_744 ;
V_10 -> V_16 ( V_5 , V_10 -> V_743 ,
V_745 ) ;
V_741 =
V_746 | V_747 ;
V_10 -> V_708 |=
V_748 | V_749 ;
V_10 -> V_708 &= ~ V_750 ;
switch ( V_685 ) {
case V_751 :
V_10 -> V_708 |=
V_752 ;
V_193 = F_251 ( V_738 , & V_724 ,
& V_725 ,
& V_10 -> V_309 ) ;
if ( V_193 < 0 )
return V_193 ;
break;
case V_742 :
V_10 -> V_708 |=
V_753 ;
V_193 = F_251 ( V_738 , & V_724 ,
& V_725 ,
& V_10 -> V_309 ) ;
if ( V_193 < 0 )
return V_193 ;
break;
default:
{
unsigned V_754 ;
static const unsigned V_755 = 7 ;
for ( V_754 = 0 ; V_754 <= V_755 ;
++ V_754 ) {
if ( V_685 ==
F_254 ( V_754 ) ) {
V_10 -> V_708 |=
F_255
( V_754 ) ;
break;
}
}
if ( V_754 > V_755 )
return - V_391 ;
V_193 = F_251 ( V_738 ,
& V_724 ,
& V_725 ,
& V_10 ->
V_309 ) ;
if ( V_193 < 0 )
return V_193 ;
}
break;
}
F_38 ( V_10 -> V_708 , V_756 ) ;
V_741 |=
F_256 ( V_724 ) |
F_257 ( V_725 ) ;
F_38 ( V_741 , V_757 ) ;
V_10 -> V_643 = V_685 ;
for ( V_105 = 0 ; V_105 < V_104 ; ++ V_105 ) {
if ( F_41 ( V_758 ) & V_759 ) {
break;
}
F_59 ( 1 ) ;
}
if ( V_105 == V_104 ) {
F_6
( L_60 ,
V_25 , V_685 , V_738 ) ;
return - V_760 ;
}
return 3 ;
}
static int F_248 ( struct V_4 * V_5 , unsigned V_685 ,
unsigned V_738 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_685 == V_710 ) {
V_10 -> V_743 &= ~ V_744 ;
V_10 -> V_16 ( V_5 , V_10 -> V_743 ,
V_745 ) ;
V_10 -> V_309 = V_649 ;
if ( V_58 . V_59 & V_60 ) {
V_10 -> V_708 &=
~ ( V_748 |
V_749 ) ;
F_38 ( V_10 -> V_708 ,
V_756 ) ;
F_38 ( 0 , V_757 ) ;
}
V_10 -> V_643 = V_685 ;
} else {
if ( V_58 . V_59 & V_60 ) {
return F_253 ( V_5 , V_685 ,
V_738 ) ;
} else {
if ( V_685 == V_761 ) {
V_10 -> V_743 |=
V_744 ;
V_10 -> V_16 ( V_5 ,
V_10 ->
V_743 ,
V_745 ) ;
if ( V_738 == 0 ) {
F_6
( L_61 ,
V_25 ) ;
return - V_391 ;
} else {
V_10 -> V_309 = V_738 ;
}
V_10 -> V_643 = V_685 ;
} else
return - V_391 ;
}
}
return 3 ;
}
static int F_258 ( struct V_4 * V_5 , unsigned V_171 ,
unsigned V_685 )
{
if ( V_171 >= F_252 ( V_5 ) ) {
if ( V_171 == V_762 ) {
if ( V_685 == V_721 )
return 1 ;
else {
F_6
( L_62 ,
V_25 , V_171 , V_762 ) ;
return 0 ;
}
}
return 0 ;
}
switch ( V_685 ) {
case V_712 :
case V_713 :
case V_714 :
case V_715 :
case V_718 :
case V_719 :
case V_720 :
case V_763 :
case V_764 :
return 1 ;
break;
case V_721 :
if ( V_58 . V_59 & V_60 )
return 1 ;
else
return 0 ;
break;
default:
return 0 ;
break;
}
}
static int F_259 ( struct V_4 * V_5 , unsigned V_171 ,
unsigned V_685 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( F_258 ( V_5 , V_171 , V_685 ) == 0 )
return - V_391 ;
if ( V_171 < 4 ) {
V_10 -> V_711 &= ~ F_260 ( V_171 ) ;
V_10 -> V_711 |=
F_249 ( V_171 , V_685 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_711 ,
V_716 ) ;
} else if ( V_171 < 8 ) {
V_10 -> V_717 &= ~ F_260 ( V_171 ) ;
V_10 -> V_717 |=
F_249 ( V_171 , V_685 ) ;
V_10 -> V_16 ( V_5 , V_10 -> V_717 ,
V_722 ) ;
}
return 2 ;
}
static unsigned F_261 ( struct V_4 * V_5 , unsigned V_171 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
if ( V_171 < 4 ) {
return F_262 ( V_171 ,
V_10 -> V_711 ) ;
} else if ( V_171 < F_252 ( V_5 ) ) {
return F_262 ( V_171 ,
V_10 -> V_717 ) ;
} else {
if ( V_171 == V_762 )
return V_721 ;
F_6 ( L_63 , V_25 ) ;
return 0 ;
}
}
static int F_263 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 , unsigned int * V_70 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned int V_171 = F_110 ( V_246 -> V_250 ) ;
switch ( V_70 [ 0 ] ) {
case V_506 :
if ( V_171 < F_252 ( V_5 ) ) {
V_10 -> V_743 |=
F_264 ( V_171 ,
( V_58 .
V_59 & V_60 ) !=
0 ) ;
} else if ( V_171 == V_762 ) {
V_10 -> V_743 |=
V_765 ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_743 ,
V_745 ) ;
break;
case V_508 :
if ( V_171 < F_252 ( V_5 ) ) {
V_10 -> V_743 &=
~ F_264 ( V_171 ,
( V_58 .
V_59 & V_60 )
!= 0 ) ;
} else if ( V_171 == V_762 ) {
V_10 -> V_743 &=
~ V_765 ;
}
V_10 -> V_16 ( V_5 , V_10 -> V_743 ,
V_745 ) ;
break;
case V_509 :
if ( V_171 < F_252 ( V_5 ) ) {
V_70 [ 1 ] =
( V_10 -> V_743 &
F_264 ( V_171 ,
( V_58 . V_59 &
V_60 )
!= 0 ) ) ? V_506 :
V_508 ;
} else if ( V_171 == V_762 ) {
V_70 [ 1 ] =
( V_10 -> V_743 &
V_765 )
? V_506 : V_508 ;
}
return 2 ;
break;
case V_650 :
return F_248 ( V_5 , V_70 [ 1 ] , V_70 [ 2 ] ) ;
break;
case V_651 :
V_70 [ 1 ] = V_10 -> V_643 ;
V_70 [ 2 ] = V_10 -> V_309 ;
return 3 ;
break;
case V_705 :
return F_259 ( V_5 , V_171 , V_70 [ 1 ] ) ;
break;
case V_706 :
V_70 [ 1 ] = F_261 ( V_5 , V_171 ) ;
return 2 ;
break;
default:
return - V_391 ;
break;
}
return 1 ;
}
static int F_265 ( struct V_4 * V_5 )
{
unsigned short V_128 ;
const int V_104 = V_766 ;
int V_105 ;
for ( V_105 = 0 ; V_105 < V_104 ; V_105 ++ ) {
V_128 = F_40 ( V_5 , V_767 ) ;
if ( ( V_128 & V_768 ) == 0 ) {
break;
}
F_266 ( V_769 ) ;
if ( F_267 ( 1 ) ) {
return - V_207 ;
}
}
if ( V_105 == V_104 ) {
F_6 ( L_64 , __FILE__ , V_25 ) ;
return - V_254 ;
}
return 0 ;
}
static void F_268 ( struct V_4 * V_5 , unsigned short V_77 )
{
static const int V_104 = 100 ;
int V_105 ;
F_37 ( V_5 , V_77 , V_770 ) ;
for ( V_105 = 0 ; V_105 < V_104 ; V_105 ++ ) {
if ( ( F_40 ( V_5 , V_767 ) & V_768 ) )
break;
F_59 ( 1 ) ;
}
if ( V_105 == V_104 ) {
F_19 ( V_5 , L_65 ) ;
}
}
static void F_269 ( struct V_4 * V_5 , unsigned int V_77 ,
unsigned int V_771 )
{
F_37 ( V_5 , ( ( V_77 >> 16 ) & 0xff ) ,
V_772 ) ;
F_37 ( V_5 , ( V_77 & 0xffff ) ,
V_773 ) ;
V_771 &= V_774 ;
F_268 ( V_5 , V_775 | V_771 ) ;
if ( F_265 ( V_5 ) )
F_19 ( V_5 , L_66 ) ;
}
static unsigned int F_270 ( struct V_4 * V_5 ,
unsigned int V_771 )
{
unsigned int V_77 ;
V_771 &= V_774 ;
F_268 ( V_5 , V_775 | V_776 | V_771 ) ;
if ( F_265 ( V_5 ) )
F_19 ( V_5 , L_67 ) ;
V_77 = ( F_40 ( V_5 ,
V_772 ) << 16 ) &
0xff0000 ;
V_77 |= F_40 ( V_5 , V_773 ) & 0xffff ;
return V_77 ;
}
static int F_271 ( struct V_4 * V_5 , unsigned short * V_70 )
{
int V_193 ;
unsigned short V_128 ;
F_268 ( V_5 , V_775 | V_777 ) ;
V_193 = F_265 ( V_5 ) ;
if ( V_193 ) {
F_19 ( V_5 ,
L_68 ) ;
return - V_254 ;
}
V_128 = F_40 ( V_5 , V_767 ) ;
if ( V_128 & V_778 ) {
F_6
( L_69 ) ;
return - V_207 ;
}
if ( V_128 & V_779 ) {
F_6
( L_70 ) ;
}
if ( V_70 ) {
* V_70 = F_40 ( V_5 , V_780 ) ;
* V_70 ^= ( 1 << 15 ) ;
}
return 0 ;
}
static int F_272 ( struct V_4 * V_5 ,
struct V_98 * V_99 ,
struct V_245 * V_246 , unsigned int * V_70 )
{
int V_167 , V_193 ;
unsigned short V_781 ;
unsigned int V_782 ;
const unsigned int V_783 = 0x1000 ;
if ( V_246 -> V_250 & V_263 )
V_782 = V_783 ;
else
V_782 = F_110 ( V_246 -> V_250 ) ;
F_37 ( V_5 , V_782 , V_784 ) ;
for ( V_167 = 0 ; V_167 < V_246 -> V_167 ; V_167 ++ ) {
V_193 = F_271 ( V_5 , & V_781 ) ;
if ( V_193 < 0 )
return V_193 ;
V_70 [ V_167 ] = V_781 ;
}
return V_246 -> V_167 ;
}
static int F_273 ( struct V_4 * V_5 )
{
unsigned int V_277 =
V_785 | V_786 ;
#if 1
F_269 ( V_5 , V_277 | V_787 ,
V_788 ) ;
F_271 ( V_5 , NULL ) ;
#else
F_269 ( V_5 , 0x400000 , V_789 ) ;
F_269 ( V_5 , V_277 | V_790 ,
V_788 ) ;
if ( F_265 ( V_5 ) )
F_19 ( V_5 , L_71 ) ;
#endif
#ifdef F_274
F_6 ( L_72 , F_270 ( V_5 ,
V_788 ) ) ;
F_6 ( L_73 , F_270 ( V_5 , V_789 ) ) ;
F_6 ( L_74 , F_270 ( V_5 ,
V_791 ) ) ;
#endif
return 0 ;
}

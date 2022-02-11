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
unsigned long V_9 ;
F_4 ( & V_10 -> V_11 , V_9 ) ;
switch ( V_6 ) {
case V_12 :
V_10 -> V_13 &= ~ V_7 ;
V_10 -> V_13 |= V_8 & V_7 ;
V_10 -> V_14 ( V_5 , V_10 -> V_13 ,
V_12 ) ;
break;
case V_15 :
V_10 -> V_16 &= ~ V_7 ;
V_10 -> V_16 |= V_8 & V_7 ;
V_10 -> V_14 ( V_5 , V_10 -> V_16 ,
V_15 ) ;
break;
case V_17 :
V_10 -> V_18 &= ~ V_7 ;
V_10 -> V_18 |= V_8 & V_7 ;
V_10 -> V_14 ( V_5 , V_10 -> V_18 ,
V_17 ) ;
break;
case V_19 :
V_10 -> V_20 &= ~ V_7 ;
V_10 -> V_20 |= V_8 & V_7 ;
F_5 ( V_10 -> V_20 , V_19 ) ;
break;
case V_21 :
V_10 -> V_22 &= ~ V_7 ;
V_10 -> V_22 |= V_8 & V_7 ;
F_5 ( V_10 -> V_22 , V_21 ) ;
break;
default:
F_6 ( L_1 , V_23 ) ;
F_6 ( L_2 , V_6 ) ;
break;
}
F_7 () ;
F_8 ( & V_10 -> V_11 , V_9 ) ;
}
static inline void F_9 ( struct V_4 * V_5 , int V_24 )
{
unsigned V_25 ;
if ( V_24 >= 0 ) {
V_25 =
( F_10 ( V_24 ) <<
V_26 ) & V_27 ;
} else {
V_25 = 0 ;
}
F_3 ( V_5 , V_19 , V_27 , V_25 ) ;
}
static inline void F_11 ( struct V_4 * V_5 , int V_24 )
{
unsigned V_25 ;
if ( V_24 >= 0 ) {
V_25 =
( F_10 ( V_24 ) <<
V_28 ) & V_29 ;
} else {
V_25 = 0 ;
}
F_3 ( V_5 , V_19 , V_29 , V_25 ) ;
}
static inline void F_12 ( struct V_4 * V_5 ,
unsigned V_30 ,
int V_31 )
{
unsigned V_25 ;
if ( V_31 >= 0 ) {
V_25 = F_13 ( V_30 , V_31 ) ;
} else {
V_25 = 0 ;
}
F_3 ( V_5 , V_21 , F_14 ( V_30 ) ,
V_25 ) ;
}
static inline void F_15 ( struct V_4 * V_5 ,
int V_31 )
{
unsigned long V_9 ;
F_4 ( & V_10 -> V_11 , V_9 ) ;
V_10 -> V_32 &= ~ V_33 ;
if ( V_31 >= 0 ) {
V_10 -> V_32 |=
( F_10 ( V_31 ) <<
V_34 ) & V_33 ;
}
F_5 ( V_10 -> V_32 , V_35 ) ;
F_7 () ;
F_8 ( & V_10 -> V_11 , V_9 ) ;
}
static int F_16 ( struct V_4 * V_5 )
{
unsigned long V_9 ;
F_4 ( & V_10 -> V_36 , V_9 ) ;
F_17 ( V_10 -> V_37 ) ;
V_10 -> V_37 =
F_18 ( V_10 -> V_38 , V_10 -> V_39 ) ;
if ( V_10 -> V_37 == NULL ) {
F_8 ( & V_10 -> V_36 , V_9 ) ;
F_19 ( V_5 ,
L_3 ) ;
return - V_40 ;
}
V_10 -> V_37 -> V_41 = V_42 ;
F_9 ( V_5 , V_10 -> V_37 -> V_24 ) ;
F_8 ( & V_10 -> V_36 , V_9 ) ;
return 0 ;
}
static int F_20 ( struct V_4 * V_5 )
{
unsigned long V_9 ;
F_4 ( & V_10 -> V_36 , V_9 ) ;
F_17 ( V_10 -> V_43 ) ;
V_10 -> V_43 =
F_18 ( V_10 -> V_38 , V_10 -> V_44 ) ;
if ( V_10 -> V_43 == NULL ) {
F_8 ( & V_10 -> V_36 , V_9 ) ;
F_19 ( V_5 ,
L_4 ) ;
return - V_40 ;
}
V_10 -> V_43 -> V_41 = V_45 ;
F_11 ( V_5 , V_10 -> V_43 -> V_24 ) ;
F_8 ( & V_10 -> V_36 , V_9 ) ;
return 0 ;
}
static int F_21 ( struct V_4 * V_5 ,
unsigned V_30 ,
enum V_46 V_47 )
{
unsigned long V_9 ;
struct V_31 * V_48 ;
F_17 ( V_30 >= V_49 ) ;
F_4 ( & V_10 -> V_36 , V_9 ) ;
F_17 ( V_10 -> V_50 -> V_51 [ V_30 ] . V_48 ) ;
V_48 =
F_18 ( V_10 -> V_38 ,
V_10 -> V_52 [ V_30 ] ) ;
if ( V_48 == NULL ) {
F_8 ( & V_10 -> V_36 , V_9 ) ;
F_19 ( V_5 ,
L_5 ) ;
return - V_40 ;
}
V_48 -> V_41 = V_47 ;
F_22 ( & V_10 -> V_50 -> V_51 [ V_30 ] ,
V_48 ) ;
F_12 ( V_5 , V_30 , V_48 -> V_24 ) ;
F_8 ( & V_10 -> V_36 , V_9 ) ;
return 0 ;
}
static int F_23 ( struct V_4 * V_5 )
{
#ifdef F_24
unsigned long V_9 ;
F_4 ( & V_10 -> V_36 , V_9 ) ;
F_17 ( V_10 -> V_53 ) ;
V_10 -> V_53 =
F_18 ( V_10 -> V_38 , V_10 -> V_54 ) ;
if ( V_10 -> V_53 == NULL ) {
F_8 ( & V_10 -> V_36 , V_9 ) ;
F_19 ( V_5 ,
L_6 ) ;
return - V_40 ;
}
V_10 -> V_53 -> V_41 = V_45 ;
F_15 ( V_5 , V_10 -> V_53 -> V_24 ) ;
F_8 ( & V_10 -> V_36 , V_9 ) ;
#endif
return 0 ;
}
static void F_25 ( struct V_4 * V_5 )
{
#ifdef F_24
unsigned long V_9 ;
F_4 ( & V_10 -> V_36 , V_9 ) ;
if ( V_10 -> V_37 ) {
F_9 ( V_5 , - 1 ) ;
F_26 ( V_10 -> V_37 ) ;
V_10 -> V_37 = NULL ;
}
F_8 ( & V_10 -> V_36 , V_9 ) ;
#endif
}
static void F_27 ( struct V_4 * V_5 )
{
#ifdef F_24
unsigned long V_9 ;
F_4 ( & V_10 -> V_36 , V_9 ) ;
if ( V_10 -> V_43 ) {
F_11 ( V_5 , - 1 ) ;
F_26 ( V_10 -> V_43 ) ;
V_10 -> V_43 = NULL ;
}
F_8 ( & V_10 -> V_36 , V_9 ) ;
#endif
}
static void F_28 ( struct V_4 * V_5 ,
unsigned V_30 )
{
unsigned long V_9 ;
F_17 ( V_30 >= V_49 ) ;
F_4 ( & V_10 -> V_36 , V_9 ) ;
if ( V_10 -> V_50 -> V_51 [ V_30 ] . V_48 ) {
struct V_31 * V_48 =
V_10 -> V_50 -> V_51 [ V_30 ] . V_48 ;
F_12 ( V_5 , V_30 , - 1 ) ;
F_22 ( & V_10 ->
V_50 -> V_51 [ V_30 ] ,
NULL ) ;
F_26 ( V_48 ) ;
}
F_8 ( & V_10 -> V_36 , V_9 ) ;
}
static void F_29 ( struct V_4 * V_5 )
{
#ifdef F_24
unsigned long V_9 ;
F_4 ( & V_10 -> V_36 , V_9 ) ;
if ( V_10 -> V_53 ) {
F_15 ( V_5 , - 1 ) ;
F_26 ( V_10 -> V_53 ) ;
V_10 -> V_53 = NULL ;
}
F_8 ( & V_10 -> V_36 , V_9 ) ;
#endif
}
static void F_30 ( struct V_4 * V_5 ,
unsigned V_30 , short V_55 )
{
if ( V_56 . V_57 & V_58 )
return;
switch ( V_30 ) {
case 0 :
if ( V_55 ) {
V_10 -> V_14 ( V_5 , V_59 ,
V_60 ) ;
} else {
V_10 -> V_14 ( V_5 , 0 ,
V_60 ) ;
}
break;
case 1 :
if ( V_55 ) {
V_10 -> V_14 ( V_5 , V_61 ,
V_62 ) ;
} else {
V_10 -> V_14 ( V_5 , 0 ,
V_62 ) ;
}
break;
default:
F_2 () ;
break;
}
}
static void F_31 ( struct V_4 * V_5 )
{
if ( V_56 . V_57 == V_63 ) {
F_32 ( 0x10 , V_64 ) ;
F_32 ( 0x00 , V_64 ) ;
while ( F_33 ( V_65 ) & 0x10 ) ;
} else {
V_10 -> V_14 ( V_5 , 1 , V_66 ) ;
if ( V_56 . V_57 == V_67 ) {
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
static void F_35 ( struct V_4 * V_5 , T_1 V_68 , int V_6 )
{
V_10 -> V_14 ( V_5 , V_68 >> 16 , V_6 ) ;
V_10 -> V_14 ( V_5 , V_68 & 0xffff , V_6 + 1 ) ;
}
static T_1 F_36 ( struct V_4 * V_5 , int V_6 )
{
T_1 V_69 ;
V_69 = V_10 -> V_70 ( V_5 , V_6 ) << 16 ;
V_69 |= V_10 -> V_70 ( V_5 , V_6 + 1 ) ;
return V_69 ;
}
static inline void F_37 ( struct V_4 * V_5 , T_2 V_68 ,
int V_71 )
{
unsigned long V_9 ;
F_4 ( & V_10 -> V_72 , V_9 ) ;
F_38 ( V_71 , V_73 ) ;
F_38 ( V_68 , V_74 ) ;
F_8 ( & V_10 -> V_72 , V_9 ) ;
}
static inline void F_39 ( struct V_4 * V_5 , T_1 V_68 ,
int V_71 )
{
unsigned long V_9 ;
F_4 ( & V_10 -> V_72 , V_9 ) ;
F_38 ( V_71 , V_73 ) ;
F_32 ( V_68 , V_74 ) ;
F_8 ( & V_10 -> V_72 , V_9 ) ;
}
static inline unsigned short F_40 ( struct V_4 * V_5 , int V_71 )
{
unsigned long V_9 ;
unsigned short V_68 ;
F_4 ( & V_10 -> V_72 , V_9 ) ;
F_38 ( V_71 , V_73 ) ;
V_68 = F_41 ( V_74 ) ;
F_8 ( & V_10 -> V_72 , V_9 ) ;
return V_68 ;
}
static inline void F_42 ( struct V_4 * V_5 , int V_6 ,
unsigned V_69 , unsigned V_75 )
{
unsigned V_8 ;
if ( V_75 )
V_8 = V_69 ;
else
V_8 = 0 ;
F_3 ( V_5 , V_6 , V_69 , V_8 ) ;
}
static T_3 F_43 ( int V_76 , void * V_77 )
{
struct V_4 * V_5 = V_77 ;
unsigned short V_78 ;
unsigned short V_79 ;
unsigned int V_80 = 0 ;
unsigned int V_81 = 0 ;
unsigned long V_9 ;
#ifdef F_24
struct V_82 * V_38 = V_10 -> V_38 ;
#endif
if ( V_5 -> V_83 == 0 )
return V_84 ;
F_44 () ;
F_4 ( & V_5 -> V_85 , V_9 ) ;
V_78 = V_10 -> V_70 ( V_5 , V_86 ) ;
V_79 = V_10 -> V_70 ( V_5 , V_87 ) ;
#ifdef F_24
if ( V_38 ) {
unsigned long V_88 ;
F_4 ( & V_10 -> V_36 , V_88 ) ;
if ( V_10 -> V_37 ) {
V_80 = F_45 ( V_10 -> V_37 ) ;
if ( V_80 & V_89 )
F_46 ( V_90 ,
V_10 -> V_38 -> V_91 +
F_47 ( V_10 ->
V_37 -> V_24 ) ) ;
}
if ( V_10 -> V_43 ) {
V_81 = F_45 ( V_10 -> V_43 ) ;
if ( V_81 & V_89 )
F_46 ( V_90 ,
V_38 -> V_91 +
F_47 ( V_10 ->
V_43 -> V_24 ) ) ;
}
F_8 ( & V_10 -> V_36 , V_88 ) ;
}
#endif
F_48 ( V_5 , V_78 ) ;
F_49 ( V_5 , V_79 ) ;
if ( ( V_78 & V_92 ) || ( V_80 & V_93 ) )
F_50 ( V_5 , V_78 , V_80 ) ;
if ( ( V_79 & V_94 ) || ( V_81 & V_93 ) )
F_51 ( V_5 , V_79 , V_81 ) ;
F_52 ( V_5 , 0 ) ;
F_52 ( V_5 , 1 ) ;
F_53 ( V_5 ) ;
F_8 ( & V_5 -> V_85 , V_9 ) ;
return V_95 ;
}
static void F_54 ( struct V_4 * V_5 )
{
struct V_96 * V_97 = & V_5 -> V_98 [ V_99 ] ;
unsigned long V_9 ;
F_4 ( & V_10 -> V_36 , V_9 ) ;
if ( V_10 -> V_37 )
F_55 ( V_10 -> V_37 , V_97 -> V_100 ) ;
F_8 ( & V_10 -> V_36 , V_9 ) ;
}
static void F_56 ( struct V_82 * V_38 ,
struct V_4 * V_5 )
{
struct V_96 * V_97 = & V_5 -> V_98 [ V_101 ] ;
unsigned long V_9 ;
F_4 ( & V_10 -> V_36 , V_9 ) ;
if ( V_10 -> V_43 ) {
F_57 ( V_10 -> V_43 , V_97 -> V_100 ) ;
}
F_8 ( & V_10 -> V_36 , V_9 ) ;
}
static int F_58 ( struct V_4 * V_5 )
{
static const int V_102 = 10000 ;
int V_103 ;
for ( V_103 = 0 ; V_103 < V_102 ; V_103 ++ ) {
unsigned short V_79 ;
V_79 = V_10 -> V_70 ( V_5 , V_87 ) ;
if ( V_79 & V_104 )
break;
F_59 ( 10 ) ;
}
if ( V_103 == V_102 ) {
F_19 ( V_5 , L_7 ) ;
return - V_105 ;
}
return 0 ;
}
static void F_60 ( struct V_4 * V_5 , struct V_96 * V_97 )
{
if ( V_10 -> V_106 == V_107 ) {
#ifdef F_24
static const int V_102 = 10 ;
int V_103 ;
for ( V_103 = 0 ; V_103 < V_102 ; V_103 ++ ) {
F_54 ( V_5 ) ;
if ( ( V_97 -> V_100 -> V_108 & V_109 ) )
break;
F_59 ( 1 ) ;
}
#else
F_61 ( V_5 ) ;
V_97 -> V_100 -> V_108 |= V_109 ;
#endif
}
if ( ( V_10 -> V_110 & V_111 ) ) {
F_62 ( V_5 ) ;
}
}
static void F_62 ( struct V_4 * V_5 )
{
struct V_96 * V_97 = & V_5 -> V_98 [ V_99 ] ;
#ifdef F_24
F_63 ( V_5 ) ;
#endif
F_61 ( V_5 ) ;
F_64 ( V_5 ) ;
F_65 ( V_5 ) ;
V_97 -> V_100 -> V_108 |= V_112 ;
}
static void F_66 ( struct V_4 * V_5 , struct V_96 * V_97 )
{
if ( V_97 ->
V_100 -> V_108 & ( V_113 | V_114 |
V_112 ) ) {
switch ( V_97 - V_5 -> V_98 ) {
case V_99 :
F_67 ( V_5 , V_97 ) ;
break;
case V_101 :
F_68 ( V_5 , V_97 ) ;
break;
case V_2 :
case V_3 :
F_69 ( V_5 , V_97 ) ;
break;
case V_115 :
F_70 ( V_5 , V_97 ) ;
break;
default:
break;
}
}
F_71 ( V_5 , V_97 ) ;
}
static void F_52 ( struct V_4 * V_5 ,
unsigned short V_1 )
{
#ifdef F_24
struct V_96 * V_97 ;
V_97 = & V_5 -> V_98 [ F_1 ( V_1 ) ] ;
F_72 ( & V_10 -> V_50 -> V_51 [ V_1 ] ,
V_97 ) ;
if ( V_97 -> V_100 -> V_108 )
F_66 ( V_5 , V_97 ) ;
#endif
}
static void F_48 ( struct V_4 * V_5 , unsigned short V_78 )
{
unsigned short V_116 = 0 ;
if ( V_78 & V_117 ) {
V_116 |= V_118 ;
}
if ( V_78 & V_119 ) {
V_116 |= V_120 ;
}
if ( V_78 & V_121 ) {
V_116 |= V_122 ;
}
if ( V_78 & V_123 ) {
V_116 |= V_124 ;
}
if ( V_116 )
V_10 -> V_14 ( V_5 , V_116 , V_125 ) ;
}
static void F_50 ( struct V_4 * V_5 , unsigned short V_126 ,
unsigned V_80 )
{
struct V_96 * V_97 = & V_5 -> V_98 [ V_99 ] ;
if ( V_97 -> type == V_127 )
return;
#ifdef F_73
F_6
( L_8 ,
V_126 , V_80 ) ;
F_74 ( V_126 ) ;
#endif
#ifdef F_24
if ( V_80 & V_89 ) {
F_54 ( V_5 ) ;
}
if ( V_80 & ~ ( V_93 | V_89 | V_128 | V_129 |
V_130 | V_131 | V_132 | V_133 |
V_134 | V_135 | V_136 ) ) {
F_6
( L_9 ,
V_80 ) ;
V_97 -> V_100 -> V_108 |= V_113 | V_112 ;
}
#endif
if ( V_126 & ( V_137 | V_138 | V_139 |
V_117 | V_119 ) ) {
if ( V_126 == 0xffff ) {
F_6
( L_10 ) ;
if ( F_75 ( V_97 ) & V_140 ) {
V_97 -> V_100 -> V_108 |=
V_113 | V_112 ;
F_66 ( V_5 , V_97 ) ;
}
return;
}
if ( V_126 & ( V_137 | V_138 |
V_139 ) ) {
F_6 ( L_11 ,
V_126 ) ;
F_74 ( V_126 ) ;
F_62 ( V_5 ) ;
V_97 -> V_100 -> V_108 |= V_113 ;
if ( V_126 & ( V_137 | V_138 ) )
V_97 -> V_100 -> V_108 |= V_114 ;
F_66 ( V_5 , V_97 ) ;
return;
}
if ( V_126 & V_117 ) {
#ifdef F_73
F_6 ( L_12 ) ;
#endif
if ( ! V_10 -> V_141 ) {
F_62 ( V_5 ) ;
}
}
}
#ifndef F_24
if ( V_126 & V_142 ) {
int V_103 ;
static const int V_102 = 10 ;
for ( V_103 = 0 ; V_103 < V_102 ; ++ V_103 ) {
F_76 ( V_5 ) ;
if ( ( V_10 -> V_70 ( V_5 ,
V_86 ) &
V_142 ) == 0 )
break;
}
}
#endif
if ( ( V_126 & V_123 ) ) {
F_60 ( V_5 , V_97 ) ;
}
F_66 ( V_5 , V_97 ) ;
#ifdef F_73
V_126 = V_10 -> V_70 ( V_5 , V_86 ) ;
if ( V_126 & V_92 ) {
F_6
( L_13 ,
V_126 ) ;
}
#endif
}
static void F_49 ( struct V_4 * V_5 , unsigned short V_79 )
{
unsigned short V_116 = 0 ;
if ( V_79 & V_143 ) {
V_116 |= V_144 ;
}
if ( V_79 & V_145 ) {
V_116 |= V_146 ;
}
if ( V_79 & V_147 ) {
V_116 |= V_148 ;
}
if ( V_79 & V_149 ) {
V_116 |= V_150 ;
}
if ( V_79 & V_151 ) {
V_116 |= V_152 ;
}
if ( V_79 & V_153 ) {
V_116 |= V_154 ;
}
if ( V_79 & V_155 ) {
V_116 |= V_156 ;
}
if ( V_116 )
V_10 -> V_14 ( V_5 , V_116 , V_157 ) ;
}
static void F_51 ( struct V_4 * V_5 ,
unsigned short V_79 , unsigned V_81 )
{
struct V_96 * V_97 = & V_5 -> V_98 [ V_101 ] ;
#ifdef F_73
F_6 ( L_14 ,
V_79 , V_81 ) ;
F_77 ( V_79 ) ;
#endif
#ifdef F_24
if ( V_81 & V_89 ) {
F_56 ( V_10 -> V_38 , V_5 ) ;
}
if ( V_81 & ~ ( V_93 | V_89 | V_128 | V_129 |
V_130 | V_131 | V_132 | V_133 |
V_134 | V_135 | V_136 ) ) {
F_6
( L_15 ,
V_81 ) ;
V_97 -> V_100 -> V_108 |= V_112 | V_113 ;
}
#endif
if ( V_79 == 0xffff )
return;
if ( V_79 & V_145 ) {
F_6
( L_16 ,
V_79 , V_10 -> V_70 ( V_5 , V_158 ) ) ;
V_97 -> V_100 -> V_108 |= V_114 ;
}
if ( V_79 & V_143 ) {
F_78
( L_17 ,
V_79 , V_10 -> V_70 ( V_5 , V_158 ) ) ;
V_97 -> V_100 -> V_108 |= V_112 ;
}
#ifndef F_24
if ( V_79 & V_159 ) {
int V_160 ;
V_160 = F_79 ( V_5 , V_97 ) ;
if ( ! V_160 ) {
F_6 ( L_18 ) ;
F_42 ( V_5 , V_15 ,
V_161 |
V_162 , 0 ) ;
V_97 -> V_100 -> V_108 |= V_114 ;
}
}
#endif
F_66 ( V_5 , V_97 ) ;
}
static void F_74 ( int V_126 )
{
int V_103 ;
F_6 ( L_19 ) ;
for ( V_103 = 15 ; V_103 >= 0 ; V_103 -- ) {
if ( V_126 & ( 1 << V_103 ) ) {
F_6 ( L_20 , V_163 [ V_103 ] ) ;
}
}
F_6 ( L_21 ) ;
}
static void F_77 ( int V_126 )
{
int V_103 ;
F_6 ( L_22 ) ;
for ( V_103 = 15 ; V_103 >= 0 ; V_103 -- ) {
if ( V_126 & ( 1 << V_103 ) ) {
F_6 ( L_20 , V_164 [ V_103 ] ) ;
}
}
F_6 ( L_21 ) ;
}
static void F_80 ( struct V_4 * V_5 ,
struct V_96 * V_97 , int V_165 )
{
struct V_166 * V_100 = V_97 -> V_100 ;
struct V_167 * V_168 = & V_100 -> V_168 ;
int V_169 ;
int V_103 ;
short V_77 ;
T_4 V_170 ;
int V_171 ;
int V_172 = 1 ;
V_169 = V_100 -> V_173 ;
for ( V_103 = 0 ; V_103 < V_165 ; V_103 ++ ) {
V_172 &= F_81 ( V_100 , & V_77 ) ;
if ( V_172 == 0 )
break;
V_171 = F_82 ( V_168 -> V_174 [ V_169 ] ) ;
if ( V_56 . V_57 & V_175 ) {
V_170 = V_77 & 0xffff ;
if ( V_56 . V_57 != V_176 ) {
V_172 &= F_81 ( V_100 , & V_77 ) ;
if ( V_172 == 0 )
break;
V_169 ++ ;
V_103 ++ ;
V_170 |= ( V_77 << 16 ) & 0xffff0000 ;
}
F_32 ( V_170 , V_177 ) ;
} else {
F_38 ( V_77 , V_178 ) ;
}
V_169 ++ ;
V_169 %= V_168 -> V_179 ;
}
V_100 -> V_173 = V_169 ;
if ( V_172 == 0 ) {
V_100 -> V_108 |= V_114 ;
}
}
static int F_79 ( struct V_4 * V_5 ,
struct V_96 * V_97 )
{
int V_165 ;
V_165 = F_83 ( V_97 -> V_100 ) ;
if ( V_165 == 0 ) {
V_97 -> V_100 -> V_108 |= V_114 ;
return 0 ;
}
V_165 /= sizeof( short ) ;
if ( V_165 > V_56 . V_180 / 2 )
V_165 = V_56 . V_180 / 2 ;
F_80 ( V_5 , V_97 , V_165 ) ;
V_97 -> V_100 -> V_108 |= V_181 ;
return 1 ;
}
static int F_84 ( struct V_4 * V_5 ,
struct V_96 * V_97 )
{
int V_165 ;
V_10 -> V_14 ( V_5 , 1 , V_182 ) ;
if ( V_56 . V_57 & V_175 )
F_39 ( V_5 , 0x6 , V_183 ) ;
V_165 = F_83 ( V_97 -> V_100 ) ;
if ( V_165 == 0 )
return 0 ;
V_165 /= sizeof( short ) ;
if ( V_165 > V_56 . V_180 )
V_165 = V_56 . V_180 ;
F_80 ( V_5 , V_97 , V_165 ) ;
return V_165 ;
}
static void F_85 ( struct V_4 * V_5 ,
struct V_96 * V_97 , int V_165 )
{
struct V_166 * V_100 = V_97 -> V_100 ;
int V_103 ;
if ( V_56 . V_57 == V_184 ) {
short V_68 [ 2 ] ;
T_4 V_185 ;
for ( V_103 = 0 ; V_103 < V_165 / 2 ; V_103 ++ ) {
V_185 = F_33 ( V_186 ) ;
V_68 [ 0 ] = ( V_185 >> 16 ) & 0xffff ;
V_68 [ 1 ] = V_185 & 0xffff ;
F_86 ( V_97 , V_68 , sizeof( V_68 ) ) ;
}
if ( V_165 % 2 ) {
V_185 = F_33 ( V_186 ) ;
V_68 [ 0 ] = V_185 & 0xffff ;
F_87 ( V_97 , V_68 [ 0 ] ) ;
}
} else if ( V_56 . V_57 == V_63 ) {
short V_68 [ 2 ] ;
T_4 V_185 ;
for ( V_103 = 0 ; V_103 < V_165 / 2 ; V_103 ++ ) {
V_185 = F_33 ( V_187 ) ;
V_68 [ 0 ] = ( V_185 >> 16 ) & 0xffff ;
V_68 [ 1 ] = V_185 & 0xffff ;
F_86 ( V_97 , V_68 , sizeof( V_68 ) ) ;
}
if ( V_165 % 2 ) {
F_32 ( 0x01 , V_64 ) ;
V_185 = F_33 ( V_187 ) ;
V_68 [ 0 ] = ( V_185 >> 16 ) & 0xffff ;
F_87 ( V_97 , V_68 [ 0 ] ) ;
}
} else {
if ( V_165 > sizeof( V_10 -> V_188 ) /
sizeof( V_10 -> V_188 [ 0 ] ) ) {
F_19 ( V_5 , L_23 ) ;
V_100 -> V_108 |= V_113 ;
return;
}
for ( V_103 = 0 ; V_103 < V_165 ; V_103 ++ ) {
V_10 -> V_188 [ V_103 ] =
F_41 ( V_189 ) ;
}
F_86 ( V_97 , V_10 -> V_188 ,
V_165 *
sizeof( V_10 -> V_188 [ 0 ] ) ) ;
}
}
static void F_76 ( struct V_4 * V_5 )
{
int V_165 ;
struct V_96 * V_97 = & V_5 -> V_98 [ V_99 ] ;
V_165 = V_56 . V_190 / 2 ;
F_85 ( V_5 , V_97 , V_165 ) ;
}
static int F_63 ( struct V_4 * V_5 )
{
int V_103 ;
static const int V_102 = 10000 ;
unsigned long V_9 ;
int V_191 = 0 ;
F_4 ( & V_10 -> V_36 , V_9 ) ;
if ( V_10 -> V_37 ) {
for ( V_103 = 0 ; V_103 < V_102 ; V_103 ++ ) {
if ( ( V_10 -> V_70 ( V_5 ,
V_86 ) &
V_192 )
&& F_88 ( V_10 -> V_37 ) ==
0 )
break;
F_59 ( 5 ) ;
}
if ( V_103 == V_102 ) {
F_6 ( L_24 ) ;
F_6
( L_25 ,
F_88 ( V_10 -> V_37 ) ,
V_10 -> V_70 ( V_5 , V_86 ) ) ;
V_191 = - 1 ;
}
}
F_8 ( & V_10 -> V_36 , V_9 ) ;
F_54 ( V_5 ) ;
return V_191 ;
}
static void F_61 ( struct V_4 * V_5 )
{
struct V_96 * V_97 = & V_5 -> V_98 [ V_99 ] ;
short V_68 [ 2 ] ;
T_4 V_185 ;
short V_193 ;
int V_103 ;
if ( V_56 . V_57 == V_184 ) {
while ( ( V_10 -> V_70 ( V_5 ,
V_86 ) &
V_192 ) == 0 ) {
V_185 = F_33 ( V_186 ) ;
V_68 [ 0 ] = ( V_185 >> 16 ) ;
V_68 [ 1 ] = ( V_185 & 0xffff ) ;
F_86 ( V_97 , V_68 , sizeof( V_68 ) ) ;
}
} else if ( V_56 . V_57 == V_63 ) {
V_103 = 0 ;
while ( F_33 ( V_65 ) & 0x04 ) {
V_185 = F_33 ( V_187 ) ;
V_68 [ 0 ] = ( V_185 >> 16 ) ;
V_68 [ 1 ] = ( V_185 & 0xffff ) ;
F_86 ( V_97 , V_68 , sizeof( V_68 ) ) ;
V_103 += 2 ;
}
if ( F_33 ( V_65 ) & 0x01 ) {
F_32 ( 0x01 , V_64 ) ;
V_185 = F_33 ( V_187 ) ;
V_68 [ 0 ] = ( V_185 >> 16 ) & 0xffff ;
F_87 ( V_97 , V_68 [ 0 ] ) ;
}
} else {
V_193 =
V_10 -> V_70 ( V_5 ,
V_86 ) & V_192 ;
while ( V_193 == 0 ) {
for ( V_103 = 0 ;
V_103 <
sizeof( V_10 -> V_188 ) /
sizeof( V_10 -> V_188 [ 0 ] ) ; V_103 ++ ) {
V_193 =
V_10 -> V_70 ( V_5 ,
V_86 ) &
V_192 ;
if ( V_193 )
break;
V_10 -> V_188 [ V_103 ] =
F_41 ( V_189 ) ;
}
F_86 ( V_97 , V_10 -> V_188 ,
V_103 *
sizeof( V_10 ->
V_188 [ 0 ] ) ) ;
}
}
}
static void F_64 ( struct V_4 * V_5 )
{
struct V_96 * V_97 = & V_5 -> V_98 [ V_99 ] ;
short V_68 ;
T_4 V_185 ;
if ( V_56 . V_57 != V_184 )
return;
if ( F_89 ( V_194 ) & 0x80 ) {
V_185 = F_33 ( V_186 ) ;
V_68 = ( V_185 & 0xffff ) ;
F_87 ( V_97 , V_68 ) ;
}
}
static void F_65 ( struct V_4 * V_5 )
{
struct V_96 * V_97 = & V_5 -> V_98 [ V_99 ] ;
short V_68 ;
T_4 V_185 ;
if ( V_56 . V_57 != V_63 )
return;
if ( F_33 ( V_65 ) & 0x01 ) {
F_32 ( 0x01 , V_64 ) ;
V_185 = F_33 ( V_187 ) ;
V_68 = ( V_185 >> 16 ) & 0xffff ;
F_87 ( V_97 , V_68 ) ;
}
}
static void F_90 ( struct V_4 * V_5 , struct V_96 * V_97 ,
void * V_68 , unsigned int V_195 ,
unsigned int V_196 )
{
struct V_166 * V_100 = V_97 -> V_100 ;
unsigned int V_103 ;
unsigned int V_197 = V_195 / F_91 ( V_97 ) ;
short * V_198 = V_68 ;
unsigned int * V_199 = V_68 ;
for ( V_103 = 0 ; V_103 < V_197 ; V_103 ++ ) {
#ifdef F_24
if ( V_97 -> V_200 & V_201 )
V_199 [ V_103 ] = F_92 ( V_199 [ V_103 ] ) ;
else
V_198 [ V_103 ] = F_93 ( V_198 [ V_103 ] ) ;
#endif
if ( V_97 -> V_200 & V_201 )
V_199 [ V_103 ] += V_10 -> V_202 [ V_196 ] ;
else
V_198 [ V_103 ] += V_10 -> V_202 [ V_196 ] ;
V_196 ++ ;
V_196 %= V_100 -> V_168 . V_179 ;
}
}
static int F_94 ( struct V_4 * V_5 )
{
struct V_96 * V_97 = & V_5 -> V_98 [ V_99 ] ;
int V_191 ;
unsigned long V_9 ;
V_191 = F_16 ( V_5 ) ;
if ( V_191 )
return V_191 ;
F_95 ( V_97 -> V_100 , V_97 -> V_100 -> V_203 ) ;
F_4 ( & V_10 -> V_36 , V_9 ) ;
if ( V_10 -> V_37 == NULL ) {
F_8 ( & V_10 -> V_36 , V_9 ) ;
return - V_204 ;
}
switch ( V_56 . V_57 ) {
case V_184 :
case V_63 :
F_96 ( V_10 -> V_37 , 32 , 16 ) ;
break;
case V_205 :
F_96 ( V_10 -> V_37 , 32 , 32 ) ;
break;
default:
F_96 ( V_10 -> V_37 , 16 , 16 ) ;
break;
}
F_97 ( V_10 -> V_37 ) ;
F_8 ( & V_10 -> V_36 , V_9 ) ;
return 0 ;
}
static int F_98 ( struct V_4 * V_5 )
{
struct V_96 * V_97 = & V_5 -> V_98 [ V_101 ] ;
int V_191 ;
unsigned long V_9 ;
V_191 = F_20 ( V_5 ) ;
if ( V_191 )
return V_191 ;
F_99 ( V_97 -> V_100 , V_97 -> V_100 -> V_203 ) ;
F_4 ( & V_10 -> V_36 , V_9 ) ;
if ( V_10 -> V_43 ) {
if ( V_56 . V_57 & ( V_184 | V_206 ) ) {
F_96 ( V_10 -> V_43 , 32 , 32 ) ;
} else {
F_96 ( V_10 -> V_43 , 16 , 32 ) ;
}
F_97 ( V_10 -> V_43 ) ;
} else
V_191 = - V_204 ;
F_8 ( & V_10 -> V_36 , V_9 ) ;
return V_191 ;
}
static int F_67 ( struct V_4 * V_5 , struct V_96 * V_97 )
{
F_25 ( V_5 ) ;
V_10 -> V_14 ( V_5 , V_207 | V_208 ,
V_209 ) ;
F_42 ( V_5 , V_12 ,
V_210 | V_211 |
V_212 | V_213 |
V_214 | V_215 |
V_216 , 0 ) ;
F_31 ( V_5 ) ;
if ( V_56 . V_57 != V_63 )
F_5 ( 0 , V_217 ) ;
V_10 -> V_14 ( V_5 , V_218 , V_219 ) ;
V_10 -> V_14 ( V_5 ,
V_220 | V_221
,
V_222 ) ;
V_10 -> V_14 ( V_5 , 0x0000 , V_223 ) ;
V_10 -> V_14 ( V_5 , ( 0 << 6 ) | 0x0000 , V_224 ) ;
if ( V_56 . V_57 == V_184 ) {
V_10 -> V_14 ( V_5 , V_225 |
V_226 |
V_227 ,
V_228 ) ;
V_10 -> V_14 ( V_5 ,
F_100 ( 3 ) |
F_101 ( 0 ) |
F_102 ( 2 ) |
F_103 ( 3 ) |
F_104
( V_229 ) ,
V_230 ) ;
} else if ( V_56 . V_57 == V_63 ) {
V_10 -> V_14 ( V_5 , V_225 |
V_226 |
V_227 ,
V_228 ) ;
V_10 -> V_14 ( V_5 ,
F_100 ( 3 ) |
F_101 ( 0 ) |
F_102 ( 2 ) |
F_103 ( 3 ) |
F_104
( V_231 ) ,
V_230 ) ;
} else {
unsigned V_232 ;
V_10 -> V_14 ( V_5 , V_225 |
V_226 |
V_233 |
V_227 ,
V_228 ) ;
V_232 =
F_100 ( 3 ) |
F_101 ( 0 ) |
F_102 ( 2 ) |
F_103 ( 3 ) ;
if ( V_56 . V_57 == V_234 )
V_232 |=
F_104
( V_229 ) ;
else
V_232 |=
F_104
( V_231 ) ;
V_10 -> V_14 ( V_5 , V_232 ,
V_230 ) ;
}
V_10 -> V_14 ( V_5 , V_235 | V_122 | V_236 | V_120 | V_118 | V_237 | V_124 , V_125 ) ;
V_10 -> V_14 ( V_5 , V_238 , V_209 ) ;
return 0 ;
}
static int F_105 ( struct V_4 * V_5 , struct V_96 * V_97 )
{
unsigned long V_9 ;
int V_239 ;
F_4 ( & V_5 -> V_85 , V_9 ) ;
#ifndef F_24
F_61 ( V_5 ) ;
#else
F_54 ( V_5 ) ;
#endif
V_239 = V_97 -> V_100 -> V_240 - V_97 -> V_100 -> V_241 ;
F_8 ( & V_5 -> V_85 , V_9 ) ;
return V_239 ;
}
static int F_106 ( struct V_4 * V_5 ,
struct V_96 * V_97 , struct V_242 * V_243 ,
unsigned int * V_68 )
{
int V_103 , V_165 ;
const unsigned int V_244 = ( 1 << V_56 . V_245 ) - 1 ;
unsigned V_246 ;
unsigned short V_77 ;
unsigned long V_185 ;
F_107 ( V_5 , 1 , & V_243 -> V_247 ) ;
F_31 ( V_5 ) ;
V_246 = V_10 -> V_202 [ 0 ] ;
if ( V_56 . V_57 == V_184 ) {
for ( V_165 = 0 ; V_165 < V_248 ; V_165 ++ ) {
V_10 -> V_14 ( V_5 , V_249 ,
V_219 ) ;
F_59 ( 1 ) ;
}
for ( V_165 = 0 ; V_165 < V_243 -> V_165 ; V_165 ++ ) {
V_10 -> V_14 ( V_5 , V_249 ,
V_219 ) ;
V_77 = 0 ;
for ( V_103 = 0 ; V_103 < V_250 ; V_103 ++ ) {
if ( F_89 ( V_194 ) & 0x80 ) {
V_77 = ( F_33 ( V_186 ) >> 16 )
& 0xffff ;
break;
}
if ( ! ( V_10 -> V_70 ( V_5 ,
V_86 ) &
V_192 ) ) {
V_77 = F_33 ( V_186 ) &
0xffff ;
break;
}
}
if ( V_103 == V_250 ) {
F_6
( L_26 ) ;
return - V_251 ;
}
V_77 += V_246 ;
V_68 [ V_165 ] = V_77 ;
}
} else if ( V_56 . V_57 == V_63 ) {
for ( V_165 = 0 ; V_165 < V_243 -> V_165 ; V_165 ++ ) {
V_10 -> V_14 ( V_5 , V_249 ,
V_219 ) ;
V_185 = 0 ;
for ( V_103 = 0 ; V_103 < V_250 ; V_103 ++ ) {
if ( F_33 ( V_65 ) & 0x01 ) {
F_32 ( 0x01 , V_64 ) ;
V_185 = F_33 ( V_187 ) ;
break;
}
}
if ( V_103 == V_250 ) {
F_6
( L_27 ) ;
return - V_251 ;
}
V_68 [ V_165 ] = ( ( ( V_185 >> 16 ) & 0xFFFF ) + V_246 ) & 0xFFFF ;
}
} else {
for ( V_165 = 0 ; V_165 < V_243 -> V_165 ; V_165 ++ ) {
V_10 -> V_14 ( V_5 , V_249 ,
V_219 ) ;
for ( V_103 = 0 ; V_103 < V_250 ; V_103 ++ ) {
if ( ! ( V_10 -> V_70 ( V_5 ,
V_86 ) &
V_192 ) )
break;
}
if ( V_103 == V_250 ) {
F_6
( L_28 ) ;
return - V_251 ;
}
if ( V_56 . V_57 & V_58 ) {
V_68 [ V_165 ] =
F_33 ( V_252 ) & V_244 ;
} else {
V_77 = F_41 ( V_189 ) ;
V_77 += V_246 ;
V_68 [ V_165 ] = V_77 ;
}
}
}
return V_243 -> V_165 ;
}
static void F_108 ( struct V_4 * V_5 )
{
int V_103 ;
V_10 -> V_14 ( V_5 , V_249 , V_219 ) ;
for ( V_103 = 0 ; V_103 < V_250 ; ++ V_103 ) {
if ( ! ( V_10 -> V_70 ( V_5 ,
V_86 ) &
V_192 ) ) {
V_10 -> V_14 ( V_5 , 1 , V_66 ) ;
return;
}
F_59 ( 1 ) ;
}
F_6 ( L_29 ) ;
}
static void F_109 ( struct V_4 * V_5 ,
unsigned int V_253 ,
unsigned int * V_254 )
{
unsigned int V_169 , V_171 , V_255 ;
unsigned int V_103 ;
unsigned V_256 ;
unsigned int V_257 ;
unsigned V_258 ;
V_10 -> V_14 ( V_5 , 1 , V_259 ) ;
if ( ( V_254 [ 0 ] & V_260 ) ) {
unsigned V_261 ;
V_169 = F_110 ( V_254 [ 0 ] ) ;
V_171 = F_82 ( V_254 [ 0 ] ) ;
V_258 = V_262 [ V_56 . V_263 ] [ V_171 ] ;
V_257 = ( ( V_254 [ 0 ] & V_264 ) != 0 ) ;
V_261 = V_265 ;
V_261 |= V_169 ;
V_261 |=
( V_10 -> V_266 ) &
( V_267 |
V_268 |
V_269 |
V_270 ) ;
V_261 |= F_111 ( V_258 ) ;
if ( V_257 )
V_261 |= V_271 ;
V_261 |= V_272 ;
F_32 ( V_261 , V_273 ) ;
} else {
F_32 ( 0 , V_273 ) ;
}
V_256 = 0 ;
for ( V_103 = 0 ; V_103 < V_253 ; V_103 ++ ) {
unsigned V_274 = 0 ;
V_169 = F_110 ( V_254 [ V_103 ] ) ;
V_255 = F_112 ( V_254 [ V_103 ] ) ;
V_171 = F_82 ( V_254 [ V_103 ] ) ;
V_257 = ( ( V_254 [ V_103 ] & V_264 ) != 0 ) ;
V_258 = V_262 [ V_56 . V_263 ] [ V_171 ] ;
V_10 -> V_202 [ V_103 ] = V_256 ;
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
V_274 |= F_113 ( V_169 ) ;
V_274 |=
F_114 ( V_56 . V_57 , V_169 ) ;
V_274 |= F_115 ( V_258 ) ;
if ( V_103 == V_253 - 1 )
V_274 |= V_282 ;
if ( V_257 )
V_274 |= V_283 ;
V_274 |= V_284 ;
F_38 ( V_274 , V_285 ) ;
}
F_108 ( V_5 ) ;
}
static void F_107 ( struct V_4 * V_5 ,
unsigned int V_253 , unsigned int * V_254 )
{
unsigned int V_169 , V_171 , V_255 ;
unsigned int V_103 ;
unsigned int V_286 , V_287 ;
unsigned V_256 ;
unsigned int V_257 ;
if ( V_56 . V_57 & V_58 ) {
F_109 ( V_5 , V_253 , V_254 ) ;
return;
}
if ( V_253 == 1 && ( V_56 . V_57 != V_184 )
&& ( V_56 . V_57 != V_63 ) ) {
if ( V_10 -> V_288
&& V_10 -> V_289 == V_254 [ 0 ] ) {
return;
}
V_10 -> V_288 = 1 ;
V_10 -> V_289 = V_254 [ 0 ] ;
} else {
V_10 -> V_288 = 0 ;
}
V_10 -> V_14 ( V_5 , 1 , V_259 ) ;
if ( V_56 . V_57 == V_63 ) {
if ( ( V_254 [ 0 ] & V_260 )
&& ! V_10 -> V_290 ) {
F_38 ( V_10 -> V_266 |
V_291 ,
V_292 ) ;
F_38 ( V_10 -> V_266 ,
V_292 ) ;
V_10 -> V_290 = 1 ;
F_116 ( 100 ) ;
} else if ( ! ( V_254 [ 0 ] & V_260 )
&& V_10 -> V_290 ) {
F_38 ( V_10 -> V_266 |
V_293 ,
V_292 ) ;
F_38 ( V_10 -> V_266 ,
V_292 ) ;
V_10 -> V_290 = 0 ;
F_116 ( 100 ) ;
}
}
V_256 = 1 << ( V_56 . V_245 - 1 ) ;
for ( V_103 = 0 ; V_103 < V_253 ; V_103 ++ ) {
if ( ( V_56 . V_57 != V_63 )
&& ( V_254 [ V_103 ] & V_260 ) ) {
V_169 = V_10 -> V_266 ;
} else {
V_169 = F_110 ( V_254 [ V_103 ] ) ;
}
V_255 = F_112 ( V_254 [ V_103 ] ) ;
V_171 = F_82 ( V_254 [ V_103 ] ) ;
V_257 = ( ( V_254 [ V_103 ] & V_264 ) != 0 ) ;
V_171 = V_262 [ V_56 . V_263 ] [ V_171 ] ;
if ( V_56 . V_57 == V_184 )
V_10 -> V_202 [ V_103 ] = V_256 ;
else
V_10 -> V_202 [ V_103 ] = ( V_171 & 0x100 ) ? 0 : V_256 ;
V_286 = 0 ;
if ( ( V_254 [ V_103 ] & V_260 ) ) {
if ( V_56 . V_57 == V_184 )
F_38 ( F_110 ( V_254 [ V_103 ] ) & 0x0003 ,
V_294 ) ;
} else {
if ( V_56 . V_57 == V_184 )
V_255 = V_275 ;
else if ( V_56 . V_57 == V_63 )
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
V_286 |= F_117 ( V_169 ) ;
F_38 ( V_286 , V_298 ) ;
if ( V_56 . V_57 != V_63 ) {
V_287 = V_171 ;
if ( V_103 == V_253 - 1 )
V_287 |= V_299 ;
if ( V_257 )
V_287 |= V_300 ;
F_38 ( V_287 , V_301 ) ;
}
}
if ( ( V_56 . V_57 != V_184 )
&& ( V_56 . V_57 != V_63 ) ) {
F_108 ( V_5 ) ;
}
}
static int F_118 ( const struct V_4 * V_5 , unsigned V_302 ,
int V_303 )
{
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
static unsigned F_119 ( const struct V_4 * V_5 , int V_309 )
{
return V_10 -> V_306 * ( V_309 + 1 ) ;
}
static unsigned F_120 ( struct V_4 * V_5 ,
unsigned V_310 )
{
switch ( V_56 . V_57 ) {
case V_184 :
case V_63 :
return V_56 . V_311 ;
break;
default:
break;
}
return V_56 . V_311 * V_310 ;
}
static int F_121 ( struct V_4 * V_5 , struct V_96 * V_97 ,
struct V_167 * V_168 )
{
int V_172 = 0 ;
int V_312 ;
unsigned int V_313 ;
if ( ( V_168 -> V_9 & V_314 ) )
V_168 -> V_9 &= ~ V_314 ;
V_172 |= F_122 ( & V_168 -> V_315 ,
V_316 | V_317 | V_318 ) ;
V_172 |= F_122 ( & V_168 -> V_319 ,
V_320 | V_318 ) ;
V_313 = V_320 | V_318 ;
if ( V_56 . V_57 == V_184 ||
V_56 . V_57 == V_63 )
V_313 |= V_316 ;
V_172 |= F_122 ( & V_168 -> V_321 , V_313 ) ;
V_172 |= F_122 ( & V_168 -> V_322 , V_323 ) ;
V_172 |= F_122 ( & V_168 -> V_324 , V_323 | V_325 ) ;
if ( V_172 )
return 1 ;
V_172 |= F_123 ( V_168 -> V_315 ) ;
V_172 |= F_123 ( V_168 -> V_319 ) ;
V_172 |= F_123 ( V_168 -> V_321 ) ;
V_172 |= F_123 ( V_168 -> V_324 ) ;
if ( V_172 )
return 2 ;
if ( V_168 -> V_315 == V_318 ) {
unsigned int V_312 = F_110 ( V_168 -> V_326 ) ;
if ( V_312 > 16 )
V_312 = 16 ;
V_312 |= ( V_168 -> V_326 & ( V_327 | V_328 ) ) ;
if ( V_168 -> V_326 != V_312 ) {
V_168 -> V_326 = V_312 ;
V_172 ++ ;
}
} else {
if ( V_168 -> V_326 != 0 ) {
V_168 -> V_326 = 0 ;
V_172 ++ ;
}
}
if ( V_168 -> V_319 == V_320 ) {
if ( V_168 -> V_329 < F_120 ( V_5 ,
V_168 ->
V_179 ) )
{
V_168 -> V_329 =
F_120 ( V_5 , V_168 -> V_179 ) ;
V_172 ++ ;
}
if ( V_168 -> V_329 > V_10 -> V_306 * 0xffffff ) {
V_168 -> V_329 = V_10 -> V_306 * 0xffffff ;
V_172 ++ ;
}
} else if ( V_168 -> V_319 == V_318 ) {
unsigned int V_312 = F_110 ( V_168 -> V_329 ) ;
if ( V_312 > 16 )
V_312 = 16 ;
V_312 |= ( V_168 -> V_329 & ( V_327 | V_328 ) ) ;
if ( V_168 -> V_329 != V_312 ) {
V_168 -> V_329 = V_312 ;
V_172 ++ ;
}
} else {
if ( V_168 -> V_329 ) {
V_168 -> V_329 = 0 ;
V_172 ++ ;
}
}
if ( V_168 -> V_321 == V_320 ) {
if ( ( V_56 . V_57 == V_184 )
|| ( V_56 . V_57 == V_63 ) ) {
if ( V_168 -> V_330 != 0 ) {
V_168 -> V_330 = 0 ;
V_172 ++ ;
}
} else {
if ( V_168 -> V_330 < V_56 . V_311 ) {
V_168 -> V_330 = V_56 . V_311 ;
V_172 ++ ;
}
if ( V_168 -> V_330 > V_10 -> V_306 * 0xffff ) {
V_168 -> V_330 = V_10 -> V_306 * 0xffff ;
V_172 ++ ;
}
}
} else if ( V_168 -> V_321 == V_318 ) {
unsigned int V_312 = F_110 ( V_168 -> V_330 ) ;
if ( V_312 > 16 )
V_312 = 16 ;
V_312 |= ( V_168 -> V_330 & ( V_264 | V_327 ) ) ;
if ( V_168 -> V_330 != V_312 ) {
V_168 -> V_330 = V_312 ;
V_172 ++ ;
}
} else if ( V_168 -> V_321 == V_316 ) {
if ( V_168 -> V_330 != 0 ) {
V_168 -> V_330 = 0 ;
V_172 ++ ;
}
}
if ( V_168 -> V_331 != V_168 -> V_179 ) {
V_168 -> V_331 = V_168 -> V_179 ;
V_172 ++ ;
}
if ( V_168 -> V_324 == V_323 ) {
unsigned int V_332 = 0x01000000 ;
if ( V_56 . V_57 == V_184 )
V_332 -= V_248 ;
if ( V_168 -> V_333 > V_332 ) {
V_168 -> V_333 = V_332 ;
V_172 ++ ;
}
if ( V_168 -> V_333 < 1 ) {
V_168 -> V_333 = 1 ;
V_172 ++ ;
}
} else {
if ( V_168 -> V_333 != 0 ) {
V_168 -> V_333 = 0 ;
V_172 ++ ;
}
}
if ( V_172 )
return 3 ;
if ( V_168 -> V_319 == V_320 ) {
V_312 = V_168 -> V_329 ;
V_168 -> V_329 =
F_119 ( V_5 , F_118 ( V_5 ,
V_168 -> V_329 ,
V_168 ->
V_9 &
V_334 ) ) ;
if ( V_312 != V_168 -> V_329 )
V_172 ++ ;
}
if ( V_168 -> V_321 == V_320 ) {
if ( ( V_56 . V_57 != V_184 )
&& ( V_56 . V_57 != V_63 ) ) {
V_312 = V_168 -> V_330 ;
V_168 -> V_330 =
F_119 ( V_5 , F_118 ( V_5 ,
V_168 -> V_330 ,
V_168 ->
V_9 &
V_334 ) ) ;
if ( V_312 != V_168 -> V_330 )
V_172 ++ ;
if ( V_168 -> V_319 == V_320 &&
V_168 -> V_329 <
V_168 -> V_330 * V_168 -> V_331 ) {
V_168 -> V_329 =
V_168 -> V_330 * V_168 -> V_331 ;
V_172 ++ ;
}
}
}
if ( V_172 )
return 4 ;
return 0 ;
}
static int F_124 ( struct V_4 * V_5 , struct V_96 * V_97 )
{
const struct V_167 * V_168 = & V_97 -> V_100 -> V_168 ;
int V_309 ;
int V_335 = 0 ;
int V_336 = 0 ;
int V_337 = 0 ;
unsigned int V_338 ;
int V_339 = 0 ;
F_78 ( L_30 ) ;
if ( V_5 -> V_76 == 0 ) {
F_19 ( V_5 , L_31 ) ;
return - V_204 ;
}
F_31 ( V_5 ) ;
F_107 ( V_5 , V_168 -> V_179 , V_168 -> V_174 ) ;
V_10 -> V_14 ( V_5 , V_207 , V_209 ) ;
V_10 -> V_340 &= ~ V_341 ;
V_10 -> V_14 ( V_5 , V_10 -> V_340 ,
V_342 ) ;
switch ( V_168 -> V_315 ) {
case V_317 :
case V_316 :
V_10 -> V_14 ( V_5 , F_125 ( 0 ) |
V_343 | V_344 |
F_126 ( 0 ) ,
V_345 ) ;
break;
case V_318 :
{
int V_169 = F_110 ( V_168 -> V_326 ) ;
unsigned int V_69 = F_125 ( 0 ) |
V_343 | F_126 ( V_169 + 1 ) ;
if ( V_168 -> V_326 & V_327 )
V_69 |= V_346 ;
if ( V_168 -> V_326 & V_328 )
V_69 |= V_344 ;
V_10 -> V_14 ( V_5 , V_69 ,
V_345 ) ;
break;
}
}
V_336 &= ~ V_347 ;
V_336 &= ~ V_348 ;
V_336 &= ~ V_349 ;
V_10 -> V_14 ( V_5 , V_336 , V_223 ) ;
if ( V_168 -> V_179 == 1 || ( V_56 . V_57 == V_184 )
|| ( V_56 . V_57 == V_63 ) ) {
V_337 |= V_350 ;
V_337 |= F_127 ( 31 ) ;
V_337 |= V_351 ;
} else {
V_337 |= F_127 ( 19 ) ;
}
V_10 -> V_14 ( V_5 , V_337 ,
V_352 ) ;
V_10 -> V_110 = 0 ;
switch ( V_168 -> V_324 ) {
case V_323 :
V_338 = V_168 -> V_333 - 1 ;
if ( V_56 . V_57 == V_184 ) {
V_338 += V_248 ;
}
V_10 -> V_353 ( V_5 , V_338 , V_354 ) ;
V_335 |= V_220 | V_221 | V_355 ;
V_10 -> V_14 ( V_5 , V_335 , V_222 ) ;
V_10 -> V_14 ( V_5 , V_356 , V_219 ) ;
V_10 -> V_141 = 0 ;
if ( V_338 == 0 ) {
V_10 -> V_110 |= V_111 ;
V_339 |= V_214 ;
if ( V_168 -> V_179 > 1 )
V_337 |=
V_350 | V_357 ;
}
break;
case V_325 :
V_10 -> V_353 ( V_5 , 0 , V_354 ) ;
V_335 |= V_220 | V_221 | V_358 ;
V_10 -> V_14 ( V_5 , V_335 , V_222 ) ;
V_10 -> V_14 ( V_5 , V_356 , V_219 ) ;
V_10 -> V_141 = 1 ;
break;
}
switch ( V_168 -> V_319 ) {
case V_320 :
V_337 |= V_359 | V_360 ;
V_10 -> V_14 ( V_5 , V_337 ,
V_352 ) ;
V_336 |= F_128 ( 0 ) ;
V_336 &= ~ V_361 ;
V_10 -> V_14 ( V_5 , V_336 , V_223 ) ;
V_309 = F_118 ( V_5 , V_168 -> V_329 ,
V_305 ) ;
V_10 -> V_353 ( V_5 , V_309 , V_362 ) ;
V_10 -> V_14 ( V_5 , V_363 , V_219 ) ;
break;
case V_318 :
if ( V_168 -> V_329 & V_328 )
V_337 |= V_359 ;
if ( V_168 -> V_329 & V_327 )
V_337 |= V_364 ;
if ( V_168 -> V_319 != V_168 -> V_321 ||
( V_168 -> V_329 & ~ V_328 ) !=
( V_168 -> V_330 & ~ V_328 ) )
V_337 |= V_360 ;
V_337 |=
F_129 ( 1 + F_110 ( V_168 -> V_329 ) ) ;
V_10 -> V_14 ( V_5 , V_337 ,
V_352 ) ;
break;
}
switch ( V_168 -> V_321 ) {
case V_320 :
case V_316 :
if ( V_168 -> V_330 == 0 || V_168 -> V_321 == V_316 )
V_309 = 1 ;
else
V_309 = F_118 ( V_5 , V_168 -> V_330 ,
V_305 ) ;
V_10 -> V_14 ( V_5 , 1 , V_365 ) ;
V_10 -> V_14 ( V_5 , V_309 , V_366 ) ;
V_336 &= ~ V_367 ;
V_336 |= V_368 ;
V_10 -> V_14 ( V_5 , V_336 , V_223 ) ;
V_10 -> V_14 ( V_5 , V_369 , V_219 ) ;
V_336 |= V_368 ;
V_336 |= V_367 ;
V_10 -> V_14 ( V_5 , V_336 , V_223 ) ;
break;
case V_318 :
V_335 |= F_130 ( 1 + V_168 -> V_330 ) ;
if ( ( V_168 -> V_330 & V_327 ) == 0 )
V_335 |= V_370 ;
V_10 -> V_14 ( V_5 , V_335 , V_222 ) ;
V_336 |= V_371 | V_372 ;
V_10 -> V_14 ( V_5 , V_336 , V_223 ) ;
break;
}
if ( V_5 -> V_76 ) {
V_339 |= V_215 |
V_210 ;
#ifndef F_24
V_339 |= V_216 ;
#endif
if ( V_168 -> V_9 & V_373
|| ( V_10 -> V_110 & V_111 ) ) {
V_10 -> V_106 = V_107 ;
} else {
V_10 -> V_106 = V_374 ;
}
switch ( V_10 -> V_106 ) {
case V_374 :
#ifdef F_24
V_10 -> V_14 ( V_5 , V_375 ,
V_224 ) ;
#else
V_10 -> V_14 ( V_5 , V_376 ,
V_224 ) ;
#endif
break;
case V_377 :
V_10 -> V_14 ( V_5 , V_378 ,
V_224 ) ;
break;
case V_107 :
#ifdef F_24
V_10 -> V_14 ( V_5 , V_378 ,
V_224 ) ;
#else
V_10 -> V_14 ( V_5 , V_376 ,
V_224 ) ;
#endif
V_339 |= V_214 ;
break;
default:
break;
}
V_10 -> V_14 ( V_5 , V_237 | V_124 | V_122 | V_236 | V_120 | V_118 | V_235 , V_125 ) ;
F_42 ( V_5 , V_12 ,
V_339 , 1 ) ;
F_78 ( L_32 ,
V_10 -> V_13 ) ;
} else {
F_42 ( V_5 , V_12 , ~ 0 , 0 ) ;
F_78 ( L_33 ) ;
}
V_10 -> V_14 ( V_5 , V_238 , V_209 ) ;
switch ( V_168 -> V_319 ) {
case V_320 :
V_10 -> V_14 ( V_5 ,
V_379 | V_380 | V_381 |
V_382 , V_219 ) ;
break;
case V_318 :
V_10 -> V_14 ( V_5 ,
V_379 | V_380 | V_381 |
V_382 , V_219 ) ;
break;
}
#ifdef F_24
{
int V_191 = F_94 ( V_5 ) ;
if ( V_191 )
return V_191 ;
}
#endif
switch ( V_168 -> V_315 ) {
case V_316 :
V_10 -> V_14 ( V_5 , V_383 | V_10 -> V_110 ,
V_384 ) ;
V_97 -> V_100 -> V_385 = NULL ;
break;
case V_318 :
V_97 -> V_100 -> V_385 = NULL ;
break;
case V_317 :
V_97 -> V_100 -> V_385 = & V_386 ;
break;
}
F_78 ( L_34 ) ;
return 0 ;
}
static int V_386 ( struct V_4 * V_5 , struct V_96 * V_97 ,
unsigned int V_387 )
{
if ( V_387 != 0 )
return - V_388 ;
V_10 -> V_14 ( V_5 , V_383 | V_10 -> V_110 ,
V_384 ) ;
V_97 -> V_100 -> V_385 = NULL ;
return 1 ;
}
static int F_131 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
if ( V_243 -> V_165 < 1 )
return - V_388 ;
switch ( V_68 [ 0 ] ) {
case V_389 :
return F_132 ( V_5 , V_97 , V_243 , V_68 ) ;
case V_390 :
if ( V_56 . V_57 & V_58 ) {
if ( V_68 [ 1 ] & ~ ( V_267 |
V_268 |
V_269 |
V_270 ) ) {
return - V_388 ;
}
V_10 -> V_266 = V_68 [ 1 ] ;
} else if ( V_56 . V_57 == V_63 ) {
unsigned int V_391 ;
V_391 = V_68 [ 1 ] & 0xf ;
if ( V_391 > 0xF )
return - V_388 ;
V_10 -> V_266 = V_391 ;
F_38 ( V_391 , V_292 ) ;
} else {
unsigned int V_391 ;
unsigned int V_392 ;
V_391 = V_68 [ 1 ] & 0xf ;
V_392 = ( V_68 [ 1 ] >> 4 ) & 0xff ;
if ( V_391 >= 8 )
return - V_388 ;
V_10 -> V_266 = V_391 ;
if ( V_56 . V_57 == V_184 ) {
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
static int F_132 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 ,
unsigned int * V_68 )
{
unsigned int V_394 , V_395 , V_396 ;
int V_172 = 0 ;
if ( ! V_56 . V_397 )
return - V_388 ;
if ( ( V_68 [ 1 ] & 0xffff0000 ) != V_398 ) {
V_68 [ 1 ] &= ( V_398 | 0xffff ) ;
V_172 ++ ;
}
if ( V_68 [ 2 ] >= V_56 . V_399 ) {
V_68 [ 2 ] = V_56 . V_399 - 1 ;
V_172 ++ ;
}
if ( V_68 [ 3 ] > 255 ) {
V_68 [ 3 ] = 255 ;
V_172 ++ ;
}
if ( V_68 [ 4 ] > 255 ) {
V_68 [ 4 ] = 255 ;
V_172 ++ ;
}
V_394 = V_68 [ 3 ] ;
V_395 = V_68 [ 4 ] ;
V_396 = V_68 [ 1 ] & 0xff ;
if ( V_396 & 0xf0 ) {
if ( V_395 < V_394 ) {
V_394 = V_68 [ 4 ] ;
V_395 = V_68 [ 3 ] ;
V_396 =
( ( V_68 [ 1 ] & 0xf ) << 4 ) | ( ( V_68 [ 1 ] & 0xf0 ) >> 4 ) ;
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
V_68 [ 1 ] &= ~ 0xff ;
V_172 ++ ;
}
} else {
if ( V_395 != 0 ) {
V_68 [ 4 ] = 0 ;
V_172 ++ ;
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
V_68 [ 1 ] &= ~ 0xff ;
V_172 ++ ;
}
}
if ( V_172 )
return - V_403 ;
return 5 ;
}
static void F_133 ( struct V_4 * V_5 , struct V_96 * V_97 ,
void * V_68 , unsigned int V_195 ,
unsigned int V_196 )
{
struct V_166 * V_100 = V_97 -> V_100 ;
unsigned int V_171 ;
unsigned int V_103 ;
unsigned int V_256 ;
unsigned int V_197 = V_195 / sizeof( short ) ;
short * V_198 = V_68 ;
V_256 = 1 << ( V_56 . V_404 - 1 ) ;
for ( V_103 = 0 ; V_103 < V_197 ; V_103 ++ ) {
V_171 = F_82 ( V_100 -> V_168 . V_174 [ V_196 ] ) ;
if ( V_56 . V_405 == 0 || ( V_171 & 1 ) == 0 )
V_198 [ V_103 ] -= V_256 ;
#ifdef F_24
V_198 [ V_103 ] = F_134 ( V_198 [ V_103 ] ) ;
#endif
V_196 ++ ;
V_196 %= V_100 -> V_168 . V_179 ;
}
}
static int F_135 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
unsigned int V_247 [] ,
unsigned int V_406 , int V_407 )
{
unsigned int V_171 ;
unsigned int V_169 ;
unsigned int V_408 ;
int V_103 ;
int V_409 = 0 ;
if ( V_407 ) {
for ( V_103 = 0 ; V_103 < V_56 . V_410 ; ++ V_103 ) {
V_10 -> V_411 [ V_103 ] &= ~ V_412 ;
F_5 ( V_10 -> V_411 [ V_103 ] ,
F_136 ( V_103 ) ) ;
F_5 ( 0xf , F_137 ( V_103 ) ) ;
}
}
for ( V_103 = 0 ; V_103 < V_406 ; V_103 ++ ) {
const struct V_413 * V_414 ;
V_169 = F_110 ( V_247 [ V_103 ] ) ;
V_171 = F_82 ( V_247 [ V_103 ] ) ;
V_414 = V_97 -> V_415 -> V_171 + V_171 ;
V_409 = 0 ;
V_408 = 0 ;
switch ( V_414 -> V_416 - V_414 -> V_417 ) {
case 20000000 :
V_408 |= V_418 ;
F_5 ( 0 , F_138 ( V_169 ) ) ;
break;
case 10000000 :
V_408 |= V_419 ;
F_5 ( 0 , F_138 ( V_169 ) ) ;
break;
case 4000000 :
V_408 |= V_418 ;
F_5 ( V_420 ,
F_138 ( V_169 ) ) ;
break;
case 2000000 :
V_408 |= V_419 ;
F_5 ( V_420 ,
F_138 ( V_169 ) ) ;
break;
default:
F_6 ( L_35 ,
V_23 ) ;
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
F_6 ( L_36 ,
V_23 ) ;
break;
}
if ( V_407 )
V_408 |= V_412 ;
F_5 ( V_408 , F_136 ( V_169 ) ) ;
V_10 -> V_411 [ V_169 ] = V_408 ;
F_5 ( V_103 , F_137 ( V_169 ) ) ;
}
return V_409 ;
}
static int F_139 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
unsigned int V_247 [] ,
unsigned int V_406 )
{
unsigned int V_171 ;
unsigned int V_169 ;
unsigned int V_408 ;
int V_103 ;
int V_409 = 0 ;
for ( V_103 = 0 ; V_103 < V_406 ; V_103 ++ ) {
V_169 = F_110 ( V_247 [ V_103 ] ) ;
V_171 = F_82 ( V_247 [ V_103 ] ) ;
V_408 = F_140 ( V_169 ) ;
if ( V_56 . V_405 ) {
if ( ( V_171 & 1 ) == 0 ) {
V_408 |= V_423 ;
V_409 = ( 1 << ( V_56 . V_404 - 1 ) ) ;
} else {
V_409 = 0 ;
}
if ( V_171 & 2 )
V_408 |= V_424 ;
} else {
V_408 |= V_423 ;
V_409 = ( 1 << ( V_56 . V_404 - 1 ) ) ;
}
if ( V_247 [ V_103 ] & V_425 )
V_408 |= V_426 ;
V_408 |= ( F_112 ( V_247 [ V_103 ] ) ==
V_281 ) ? V_427 : 0 ;
F_38 ( V_408 , V_428 ) ;
V_10 -> V_411 [ V_169 ] = V_408 ;
}
return V_409 ;
}
static int F_141 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
unsigned int V_247 [] , unsigned int V_406 ,
int V_407 )
{
if ( V_56 . V_57 & V_58 )
return F_135 ( V_5 , V_97 , V_247 , V_406 ,
V_407 ) ;
else
return F_139 ( V_5 , V_97 , V_247 , V_406 ) ;
}
static int F_142 ( struct V_4 * V_5 ,
struct V_96 * V_97 , struct V_242 * V_243 ,
unsigned int * V_68 )
{
V_68 [ 0 ] = V_10 -> V_429 [ F_110 ( V_243 -> V_247 ) ] ;
return 1 ;
}
static int F_143 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
unsigned int V_169 = F_110 ( V_243 -> V_247 ) ;
unsigned int V_409 ;
V_409 = F_141 ( V_5 , V_97 , & V_243 -> V_247 , 1 , 0 ) ;
V_10 -> V_429 [ V_169 ] = V_68 [ 0 ] ;
if ( V_56 . V_57 & V_58 ) {
F_38 ( V_68 [ 0 ] , F_144 ( V_169 ) ) ;
} else
F_38 ( V_68 [ 0 ] ^ V_409 ,
( V_169 ) ? V_430 : V_431 ) ;
return 1 ;
}
static int F_145 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
unsigned int V_169 = F_110 ( V_243 -> V_247 ) ;
unsigned int V_409 ;
F_146 ( 1 << V_169 , V_432 ) ;
V_409 = 1 << ( V_56 . V_404 - 1 ) ;
F_141 ( V_5 , V_97 , & V_243 -> V_247 , 1 , 0 ) ;
V_10 -> V_429 [ V_169 ] = V_68 [ 0 ] ;
F_146 ( V_68 [ 0 ] ^ V_409 , F_147 ( V_169 ) ) ;
return 1 ;
}
static int F_148 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
switch ( V_68 [ 0 ] ) {
case V_433 :
switch ( V_68 [ 1 ] ) {
case V_45 :
V_68 [ 2 ] = 1 + V_56 . V_180 * sizeof( short ) ;
if ( V_10 -> V_38 )
V_68 [ 2 ] += V_10 -> V_38 -> V_434 ;
break;
case V_42 :
V_68 [ 2 ] = 0 ;
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
static int F_149 ( struct V_4 * V_5 , struct V_96 * V_97 ,
unsigned int V_387 )
{
int V_160 ;
int V_435 ;
int V_103 ;
static const int V_102 = 1000 ;
if ( V_387 != 0 )
return - V_388 ;
V_97 -> V_100 -> V_385 = NULL ;
F_42 ( V_5 , V_15 ,
V_161 | V_162 , 0 ) ;
V_435 = V_162 ;
#ifdef F_24
V_10 -> V_14 ( V_5 , 1 , V_182 ) ;
if ( V_56 . V_57 & V_175 )
F_39 ( V_5 , 0x6 , V_183 ) ;
V_160 = F_98 ( V_5 ) ;
if ( V_160 )
return V_160 ;
V_160 = F_58 ( V_5 ) ;
if ( V_160 < 0 )
return V_160 ;
#else
V_160 = F_84 ( V_5 , V_97 ) ;
if ( V_160 == 0 )
return - V_105 ;
V_435 |= V_161 ;
#endif
V_10 -> V_14 ( V_5 , V_10 -> V_436 | V_437 ,
V_438 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_436 , V_438 ) ;
for ( V_103 = 0 ; V_103 < V_102 ; V_103 ++ ) {
F_59 ( 1 ) ;
if ( ( V_10 -> V_70 ( V_5 ,
V_439 ) &
V_440 ) == 0 )
break;
}
if ( V_103 == V_102 ) {
F_19 ( V_5 ,
L_37 ) ;
return - V_204 ;
}
V_10 -> V_14 ( V_5 , V_146 ,
V_157 ) ;
F_42 ( V_5 , V_15 , V_435 , 1 ) ;
V_10 -> V_14 ( V_5 ,
V_10 -> V_441 | V_442 | V_443 | V_444
| V_445 | V_446 ,
V_447 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_448 | V_449 ,
V_450 ) ;
return 0 ;
}
static int F_150 ( struct V_4 * V_5 , struct V_96 * V_97 )
{
const struct V_167 * V_168 = & V_97 -> V_100 -> V_168 ;
int V_69 ;
int V_103 ;
unsigned V_451 ;
if ( V_5 -> V_76 == 0 ) {
F_19 ( V_5 , L_31 ) ;
return - V_204 ;
}
V_10 -> V_14 ( V_5 , V_452 , V_209 ) ;
V_10 -> V_14 ( V_5 , V_453 , V_447 ) ;
if ( V_56 . V_57 & V_175 ) {
F_146 ( V_454 , V_455 ) ;
V_69 = 0 ;
for ( V_103 = 0 ; V_103 < V_168 -> V_179 ; V_103 ++ ) {
int V_169 ;
V_169 = F_110 ( V_168 -> V_174 [ V_103 ] ) ;
V_69 |= 1 << V_169 ;
F_146 ( V_169 , V_456 ) ;
}
F_146 ( V_69 , V_457 ) ;
}
F_141 ( V_5 , V_97 , V_168 -> V_174 , V_168 -> V_179 , 1 ) ;
if ( V_168 -> V_324 == V_325 ) {
V_10 -> V_458 |= V_459 ;
V_10 -> V_458 &= ~ V_460 ;
} else {
V_10 -> V_458 &= ~ V_459 ;
V_10 -> V_458 |= V_460 ;
}
V_10 -> V_14 ( V_5 , V_10 -> V_458 , V_461 ) ;
switch ( V_168 -> V_315 ) {
case V_317 :
case V_316 :
V_10 -> V_462 &=
~ ( V_463 | F_151 ( - 1 ) ) ;
V_10 -> V_462 |= V_464 | V_465 ;
V_10 -> V_14 ( V_5 , V_10 -> V_462 ,
V_466 ) ;
break;
case V_318 :
V_10 -> V_462 =
F_151 ( F_110 ( V_168 -> V_326 ) + 1 ) ;
if ( V_168 -> V_326 & V_327 )
V_10 -> V_462 |= V_463 ;
if ( V_168 -> V_326 & V_328 )
V_10 -> V_462 |= V_464 ;
V_10 -> V_14 ( V_5 , V_10 -> V_462 ,
V_466 ) ;
break;
default:
F_2 () ;
break;
}
V_10 -> V_436 &= ~ V_467 ;
V_10 -> V_14 ( V_5 , V_10 -> V_436 , V_438 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_458 , V_461 ) ;
V_10 -> V_468 &= ~ V_469 ;
V_10 -> V_14 ( V_5 , V_10 -> V_468 , V_470 ) ;
if ( V_168 -> V_324 == V_325 ) {
V_10 -> V_353 ( V_5 , 0xffffff , V_471 ) ;
} else {
V_10 -> V_353 ( V_5 , 0 , V_471 ) ;
}
V_10 -> V_14 ( V_5 , V_472 , V_447 ) ;
V_10 -> V_468 &= ~ V_473 ;
V_10 -> V_14 ( V_5 , V_10 -> V_468 , V_470 ) ;
switch ( V_168 -> V_324 ) {
case V_323 :
if ( V_56 . V_57 & V_58 ) {
V_10 -> V_353 ( V_5 , V_168 -> V_333 - 1 ,
V_474 ) ;
V_10 -> V_14 ( V_5 , V_475 ,
V_447 ) ;
} else {
V_10 -> V_353 ( V_5 , V_168 -> V_333 ,
V_474 ) ;
V_10 -> V_14 ( V_5 , V_475 ,
V_447 ) ;
V_10 -> V_353 ( V_5 , V_168 -> V_333 - 1 ,
V_474 ) ;
}
break;
case V_325 :
V_10 -> V_353 ( V_5 , 0xffffff , V_474 ) ;
V_10 -> V_14 ( V_5 , V_475 , V_447 ) ;
V_10 -> V_353 ( V_5 , 0xffffff , V_474 ) ;
break;
default:
V_10 -> V_353 ( V_5 , 0 , V_474 ) ;
V_10 -> V_14 ( V_5 , V_475 , V_447 ) ;
V_10 -> V_353 ( V_5 , V_168 -> V_333 , V_474 ) ;
}
V_10 -> V_458 &=
~ ( F_152 ( 0x1f ) | V_476 |
F_153 ( 0x1f ) | V_477 ) ;
switch ( V_168 -> V_319 ) {
case V_320 :
V_10 -> V_448 &= ~ V_478 ;
V_451 =
F_118 ( V_5 , V_168 -> V_329 ,
V_305 ) ;
V_10 -> V_353 ( V_5 , 1 , V_479 ) ;
V_10 -> V_14 ( V_5 , V_480 , V_447 ) ;
V_10 -> V_353 ( V_5 , V_451 , V_479 ) ;
break;
case V_318 :
V_10 -> V_458 |=
F_153 ( V_168 -> V_329 ) ;
if ( V_168 -> V_329 & V_327 )
V_10 -> V_458 |= V_477 ;
V_10 -> V_448 |= V_478 ;
break;
default:
F_2 () ;
break;
}
V_10 -> V_14 ( V_5 , V_10 -> V_448 , V_450 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_458 , V_461 ) ;
V_10 -> V_468 &=
~ ( F_154 ( 3 ) | V_481 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_468 , V_470 ) ;
if ( V_168 -> V_331 > 1 ) {
V_10 -> V_458 |= V_482 ;
V_10 -> V_14 ( V_5 ,
F_155 ( V_168 -> V_331 -
1 ) |
F_156
( V_483 ) ,
V_484 ) ;
} else {
unsigned V_69 ;
V_10 -> V_458 &= ~ V_482 ;
V_69 = F_156 ( V_483 ) ;
if ( V_56 .
V_57 & ( V_58 | V_175 ) ) {
V_69 |= F_155 ( 0 ) ;
} else {
V_69 |=
F_155 ( F_110 ( V_168 -> V_174 [ 0 ] ) ) ;
}
V_10 -> V_14 ( V_5 , V_69 , V_484 ) ;
}
V_10 -> V_14 ( V_5 , V_10 -> V_458 , V_461 ) ;
V_10 -> V_14 ( V_5 , V_446 | V_445 ,
V_447 ) ;
V_10 -> V_436 |= V_485 ;
V_10 -> V_14 ( V_5 , V_10 -> V_436 , V_438 ) ;
V_10 -> V_468 &= ~ V_486 ;
#ifdef F_24
V_10 -> V_468 |= V_487 ;
#else
V_10 -> V_468 |= V_488 ;
#endif
V_10 -> V_468 &= ~ V_489 ;
V_10 -> V_14 ( V_5 , V_10 -> V_468 , V_470 ) ;
V_69 = V_490 | V_491 |
V_492 ;
if ( V_56 . V_180 )
V_69 |= V_493 ;
else
V_69 |= V_494 ;
#if 0
if (boardtype.reg_type & ni_reg_m_series_mask)
bits |= AO_Number_Of_DAC_Packages;
#endif
V_10 -> V_14 ( V_5 , V_69 , V_495 ) ;
V_10 -> V_14 ( V_5 , V_496 , V_497 ) ;
V_10 -> V_14 ( V_5 , V_498 , V_209 ) ;
if ( V_168 -> V_324 == V_323 ) {
V_10 -> V_14 ( V_5 , V_144 ,
V_157 ) ;
F_42 ( V_5 , V_15 ,
V_499 , 1 ) ;
}
V_97 -> V_100 -> V_385 = & F_149 ;
return 0 ;
}
static int F_157 ( struct V_4 * V_5 , struct V_96 * V_97 ,
struct V_167 * V_168 )
{
int V_172 = 0 ;
int V_312 ;
if ( ( V_168 -> V_9 & V_314 ) == 0 )
V_168 -> V_9 |= V_314 ;
V_172 |= F_122 ( & V_168 -> V_315 , V_317 | V_318 ) ;
V_172 |= F_122 ( & V_168 -> V_319 ,
V_320 | V_318 ) ;
V_172 |= F_122 ( & V_168 -> V_321 , V_316 ) ;
V_172 |= F_122 ( & V_168 -> V_322 , V_323 ) ;
V_172 |= F_122 ( & V_168 -> V_324 , V_323 | V_325 ) ;
if ( V_172 )
return 1 ;
V_172 |= F_123 ( V_168 -> V_315 ) ;
V_172 |= F_123 ( V_168 -> V_319 ) ;
V_172 |= F_123 ( V_168 -> V_324 ) ;
if ( V_172 )
return 2 ;
if ( V_168 -> V_315 == V_318 ) {
unsigned int V_312 = F_110 ( V_168 -> V_326 ) ;
if ( V_312 > 18 )
V_312 = 18 ;
V_312 |= ( V_168 -> V_326 & ( V_327 | V_328 ) ) ;
if ( V_168 -> V_326 != V_312 ) {
V_168 -> V_326 = V_312 ;
V_172 ++ ;
}
} else {
if ( V_168 -> V_326 != 0 ) {
V_168 -> V_326 = 0 ;
V_172 ++ ;
}
}
if ( V_168 -> V_319 == V_320 ) {
if ( V_168 -> V_329 < V_56 . V_500 ) {
V_168 -> V_329 = V_56 . V_500 ;
V_172 ++ ;
}
if ( V_168 -> V_329 > V_10 -> V_306 * 0xffffff ) {
V_168 -> V_329 = V_10 -> V_306 * 0xffffff ;
V_172 ++ ;
}
}
if ( V_168 -> V_330 != 0 ) {
V_168 -> V_330 = 0 ;
V_172 ++ ;
}
if ( V_168 -> V_331 != V_168 -> V_179 ) {
V_168 -> V_331 = V_168 -> V_179 ;
V_172 ++ ;
}
if ( V_168 -> V_324 == V_323 ) {
if ( V_168 -> V_333 > 0x00ffffff ) {
V_168 -> V_333 = 0x00ffffff ;
V_172 ++ ;
}
} else {
if ( V_168 -> V_333 != 0 ) {
V_168 -> V_333 = 0 ;
V_172 ++ ;
}
}
if ( V_172 )
return 3 ;
if ( V_168 -> V_319 == V_320 ) {
V_312 = V_168 -> V_329 ;
V_168 -> V_329 =
F_119 ( V_5 , F_118 ( V_5 ,
V_168 -> V_329 ,
V_168 ->
V_9 &
V_334 ) ) ;
if ( V_312 != V_168 -> V_329 )
V_172 ++ ;
}
if ( V_172 )
return 4 ;
if ( V_172 )
return 5 ;
return 0 ;
}
static int F_68 ( struct V_4 * V_5 , struct V_96 * V_97 )
{
F_27 ( V_5 ) ;
V_10 -> V_14 ( V_5 , V_452 , V_209 ) ;
V_10 -> V_14 ( V_5 , V_453 , V_447 ) ;
F_42 ( V_5 , V_15 , ~ 0 , 0 ) ;
V_10 -> V_14 ( V_5 , V_490 , V_495 ) ;
V_10 -> V_14 ( V_5 , 0x3f98 , V_157 ) ;
V_10 -> V_14 ( V_5 , V_490 | V_491 |
V_492 , V_495 ) ;
V_10 -> V_14 ( V_5 , 0 , V_484 ) ;
V_10 -> V_14 ( V_5 , 0 , V_497 ) ;
V_10 -> V_441 = 0 ;
V_10 -> V_14 ( V_5 , V_10 -> V_441 , V_447 ) ;
V_10 -> V_448 = 0 ;
V_10 -> V_14 ( V_5 , V_10 -> V_448 , V_450 ) ;
V_10 -> V_458 = 0 ;
V_10 -> V_14 ( V_5 , V_10 -> V_458 , V_461 ) ;
V_10 -> V_468 = 0 ;
V_10 -> V_14 ( V_5 , V_10 -> V_468 , V_470 ) ;
if ( V_56 . V_57 & V_58 )
V_10 -> V_436 = V_501 ;
else
V_10 -> V_436 = 0 ;
V_10 -> V_14 ( V_5 , V_10 -> V_436 , V_438 ) ;
V_10 -> V_462 = 0 ;
V_10 -> V_14 ( V_5 , V_10 -> V_462 ,
V_466 ) ;
if ( V_56 . V_57 & V_175 ) {
unsigned V_502 = 0 ;
unsigned V_103 ;
for ( V_103 = 0 ; V_103 < V_97 -> V_253 ; ++ V_103 ) {
V_502 |= 1 << V_103 ;
}
F_146 ( V_502 , V_432 ) ;
F_146 ( V_454 , V_455 ) ;
}
V_10 -> V_14 ( V_5 , V_498 , V_209 ) ;
return 0 ;
}
static int F_158 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
#ifdef F_159
F_6 ( L_38 ,
F_110 ( V_243 -> V_247 ) , V_68 [ 0 ] ) ;
#endif
switch ( V_68 [ 0 ] ) {
case V_503 :
V_97 -> V_504 |= 1 << F_110 ( V_243 -> V_247 ) ;
break;
case V_505 :
V_97 -> V_504 &= ~ ( 1 << F_110 ( V_243 -> V_247 ) ) ;
break;
case V_506 :
V_68 [ 1 ] =
( V_97 ->
V_504 & ( 1 << F_110 ( V_243 -> V_247 ) ) ) ? V_45 :
V_42 ;
return V_243 -> V_165 ;
break;
default:
return - V_388 ;
}
V_10 -> V_507 &= ~ V_508 ;
V_10 -> V_507 |= F_160 ( V_97 -> V_504 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_507 , V_509 ) ;
return 1 ;
}
static int F_161 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
#ifdef F_159
F_6 ( L_39 , V_68 [ 0 ] , V_68 [ 1 ] ) ;
#endif
if ( V_68 [ 0 ] ) {
if ( ( V_68 [ 0 ] & ( V_510 | V_511 ) )
&& V_10 -> V_512 )
return - V_40 ;
V_97 -> V_513 &= ~ V_68 [ 0 ] ;
V_97 -> V_513 |= ( V_68 [ 0 ] & V_68 [ 1 ] ) ;
V_10 -> V_514 &= ~ V_515 ;
V_10 -> V_514 |= F_162 ( V_97 -> V_513 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_514 ,
V_516 ) ;
}
V_68 [ 1 ] = V_10 -> V_70 ( V_5 , V_517 ) ;
return V_243 -> V_165 ;
}
static int F_163 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 ,
unsigned int * V_68 )
{
#ifdef F_159
F_6 ( L_40 ,
F_110 ( V_243 -> V_247 ) , V_68 [ 0 ] ) ;
#endif
switch ( V_68 [ 0 ] ) {
case V_503 :
V_97 -> V_504 |= 1 << F_110 ( V_243 -> V_247 ) ;
break;
case V_505 :
V_97 -> V_504 &= ~ ( 1 << F_110 ( V_243 -> V_247 ) ) ;
break;
case V_506 :
V_68 [ 1 ] =
( V_97 ->
V_504 & ( 1 << F_110 ( V_243 -> V_247 ) ) ) ? V_45 :
V_42 ;
return V_243 -> V_165 ;
break;
default:
return - V_388 ;
}
F_32 ( V_97 -> V_504 , V_518 ) ;
return 1 ;
}
static int F_164 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 ,
unsigned int * V_68 )
{
#ifdef F_159
F_6 ( L_41 , V_68 [ 0 ] ,
V_68 [ 1 ] ) ;
#endif
if ( V_68 [ 0 ] ) {
V_97 -> V_513 &= ~ V_68 [ 0 ] ;
V_97 -> V_513 |= ( V_68 [ 0 ] & V_68 [ 1 ] ) ;
F_32 ( V_97 -> V_513 , V_519 ) ;
}
V_68 [ 1 ] = F_33 ( V_520 ) ;
return V_243 -> V_165 ;
}
static int F_165 ( struct V_4 * V_5 ,
struct V_96 * V_97 , struct V_167 * V_168 )
{
int V_172 = 0 ;
int V_312 ;
unsigned V_103 ;
V_172 |= F_122 ( & V_168 -> V_315 , V_317 ) ;
V_172 |= F_122 ( & V_168 -> V_319 , V_318 ) ;
V_172 |= F_122 ( & V_168 -> V_321 , V_316 ) ;
V_172 |= F_122 ( & V_168 -> V_322 , V_323 ) ;
V_172 |= F_122 ( & V_168 -> V_324 , V_325 ) ;
if ( V_172 )
return 1 ;
if ( V_172 )
return 2 ;
if ( V_168 -> V_315 == V_317 ) {
if ( V_168 -> V_326 != 0 ) {
V_168 -> V_326 = 0 ;
V_172 ++ ;
}
}
if ( V_168 -> V_319 == V_318 ) {
V_312 = V_168 -> V_329 ;
V_312 &= F_166 ( V_521 , 0 , 0 ,
V_327 ) ;
if ( V_312 != V_168 -> V_329 ) {
V_172 ++ ;
}
}
if ( V_168 -> V_321 == V_316 ) {
if ( V_168 -> V_330 ) {
V_168 -> V_330 = 0 ;
V_172 ++ ;
}
}
if ( V_168 -> V_331 != V_168 -> V_179 ) {
V_168 -> V_331 = V_168 -> V_179 ;
V_172 ++ ;
}
if ( V_168 -> V_324 == V_325 ) {
if ( V_168 -> V_333 != 0 ) {
V_168 -> V_333 = 0 ;
V_172 ++ ;
}
}
if ( V_172 )
return 3 ;
if ( V_172 )
return 4 ;
for ( V_103 = 0 ; V_103 < V_168 -> V_179 ; ++ V_103 ) {
if ( V_168 -> V_174 [ V_103 ] != V_103 )
V_172 = 1 ;
}
if ( V_172 )
return 5 ;
return 0 ;
}
static int F_167 ( struct V_4 * V_5 , struct V_96 * V_97 )
{
const struct V_167 * V_168 = & V_97 -> V_100 -> V_168 ;
unsigned V_522 = V_523 | V_524 ;
int V_191 ;
F_32 ( V_525 , V_526 ) ;
switch ( V_168 -> V_319 ) {
case V_318 :
V_522 |=
F_110 ( V_168 -> V_329 ) &
V_521 ;
break;
default:
F_2 () ;
break;
}
if ( V_168 -> V_329 & V_327 )
V_522 |= V_527 ;
F_32 ( V_522 , V_528 ) ;
if ( V_97 -> V_504 ) {
F_32 ( V_97 -> V_513 , V_529 ) ;
F_32 ( V_530 , V_526 ) ;
F_32 ( V_97 -> V_504 , V_531 ) ;
} else {
F_19 ( V_5 ,
L_42 ) ;
return - V_204 ;
}
V_191 = F_23 ( V_5 ) ;
if ( V_191 < 0 ) {
return V_191 ;
}
V_97 -> V_100 -> V_385 = & V_532 ;
return 0 ;
}
static int V_532 ( struct V_4 * V_5 , struct V_96 * V_97 ,
unsigned int V_387 )
{
#ifdef F_24
unsigned long V_9 ;
#endif
int V_191 = 0 ;
unsigned V_103 ;
const unsigned V_102 = 1000 ;
V_97 -> V_100 -> V_385 = NULL ;
F_99 ( V_97 -> V_100 , V_97 -> V_100 -> V_203 ) ;
#ifdef F_24
F_4 ( & V_10 -> V_36 , V_9 ) ;
if ( V_10 -> V_53 ) {
F_96 ( V_10 -> V_53 , 32 , 32 ) ;
F_97 ( V_10 -> V_53 ) ;
} else {
F_19 ( V_5 , L_43 ) ;
V_191 = - V_204 ;
}
F_8 ( & V_10 -> V_36 , V_9 ) ;
if ( V_191 < 0 )
return V_191 ;
#endif
for ( V_103 = 0 ; V_103 < V_102 ; ++ V_103 ) {
if ( F_33 ( V_533 ) & V_534 )
break;
F_59 ( 10 ) ;
}
if ( V_103 == V_102 ) {
F_19 ( V_5 , L_44 ) ;
F_70 ( V_5 , V_97 ) ;
return - V_204 ;
}
F_32 ( V_535 | V_536 |
V_537 ,
V_526 ) ;
return V_191 ;
}
static int F_70 ( struct V_4 * V_5 , struct V_96 * V_97 )
{
F_32 ( V_538 | V_539 |
V_540 |
V_541 ,
V_526 ) ;
F_32 ( 0 , V_531 ) ;
F_29 ( V_5 ) ;
return 0 ;
}
static void F_53 ( struct V_4 * V_5 )
{
unsigned V_542 ;
struct V_96 * V_97 = & V_5 -> V_98 [ V_115 ] ;
#ifdef F_24
unsigned long V_9 ;
#endif
if ( ( V_56 . V_57 & V_58 ) == 0 ) {
return;
}
#ifdef F_24
F_4 ( & V_10 -> V_36 , V_9 ) ;
if ( V_10 -> V_53 ) {
unsigned V_543 =
F_45 ( V_10 -> V_53 ) ;
if ( V_543 & V_89 ) {
F_46 ( V_90 ,
V_10 -> V_38 -> V_91 +
F_47 ( V_10 -> V_53 -> V_24 ) ) ;
}
F_57 ( V_10 -> V_53 , V_97 -> V_100 ) ;
}
F_8 ( & V_10 -> V_36 , V_9 ) ;
#endif
V_542 = F_33 ( V_533 ) ;
if ( V_542 & ( V_544 | V_545 ) ) {
F_32 ( V_546 , V_526 ) ;
V_97 -> V_100 -> V_108 |= V_114 ;
}
if ( V_542 & V_547 ) {
F_32 ( V_540 ,
V_526 ) ;
}
F_66 ( V_5 , V_97 ) ;
}
static int F_168 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
int V_172 = V_243 -> V_165 ;
unsigned char V_548 , V_549 = 0 ;
if ( V_243 -> V_165 != 2 )
return - V_388 ;
switch ( V_68 [ 0 ] ) {
case V_550 :
#ifdef F_159
F_6 ( L_45 , V_68 [ 1 ] ) ;
#endif
V_10 -> V_551 = 1 ;
V_10 -> V_507 |= V_552 ;
if ( V_68 [ 1 ] == V_553 ) {
V_10 -> V_551 = 0 ;
V_10 -> V_507 &= ~ ( V_552 |
V_554 ) ;
V_68 [ 1 ] = V_553 ;
V_10 -> V_512 = V_68 [ 1 ] ;
} else if ( V_68 [ 1 ] <= V_555 ) {
V_10 -> V_507 &= ~ V_556 ;
V_10 -> V_557 |= V_558 ;
V_10 -> V_557 &= ~ V_559 ;
V_68 [ 1 ] = V_555 ;
V_10 -> V_512 = V_68 [ 1 ] ;
} else if ( V_68 [ 1 ] <= V_560 ) {
V_10 -> V_507 &= ~ V_556 ;
V_10 -> V_557 |= V_558 |
V_559 ;
V_68 [ 1 ] = V_560 ;
V_10 -> V_512 = V_68 [ 1 ] ;
} else if ( V_68 [ 1 ] <= V_561 ) {
V_10 -> V_507 |= V_556 ;
V_10 -> V_557 |= V_558 |
V_559 ;
V_68 [ 1 ] = V_561 ;
V_10 -> V_512 = V_68 [ 1 ] ;
} else {
V_10 -> V_507 &= ~ ( V_552 |
V_554 ) ;
V_10 -> V_551 = 0 ;
V_68 [ 1 ] = ( V_68 [ 1 ] / 1000 ) * 1000 ;
V_10 -> V_512 = V_68 [ 1 ] ;
}
V_10 -> V_14 ( V_5 , V_10 -> V_507 ,
V_509 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_557 ,
V_562 ) ;
return 1 ;
break;
case V_563 :
if ( V_10 -> V_512 == 0 ) {
return - V_388 ;
}
V_548 = V_68 [ 1 ] & 0xFF ;
if ( V_10 -> V_551 ) {
V_172 = F_169 ( V_5 , V_97 , V_548 ,
& V_549 ) ;
} else if ( V_10 -> V_512 > 0 ) {
V_172 = F_170 ( V_5 , V_97 , V_548 ,
& V_549 ) ;
} else {
F_6 ( L_46 ) ;
return - V_388 ;
}
if ( V_172 < 0 )
return V_172 ;
V_68 [ 1 ] = V_549 & 0xFF ;
return V_243 -> V_165 ;
break;
default:
return - V_388 ;
}
}
static int F_169 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
unsigned char V_564 ,
unsigned char * V_565 )
{
unsigned int V_566 ;
int V_172 = 0 , V_239 = 20 ;
#ifdef F_159
F_6 ( L_47 , V_564 ) ;
#endif
V_10 -> V_514 &= ~ V_567 ;
V_10 -> V_514 |= F_171 ( V_564 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_514 , V_516 ) ;
V_566 = V_10 -> V_70 ( V_5 , V_568 ) ;
if ( V_566 & V_569 ) {
V_172 = - V_40 ;
goto Error;
}
V_10 -> V_507 |= V_570 ;
V_10 -> V_14 ( V_5 , V_10 -> V_507 , V_509 ) ;
V_10 -> V_507 &= ~ V_570 ;
while ( ( V_566 =
V_10 -> V_70 ( V_5 ,
V_568 ) ) &
V_569 ) {
F_59 ( ( V_10 -> V_512 + 999 ) / 1000 ) ;
if ( -- V_239 < 0 ) {
F_6
( L_48 ) ;
V_172 = - V_251 ;
goto Error;
}
}
F_59 ( ( V_10 -> V_512 + 999 ) / 1000 ) ;
if ( V_565 != NULL ) {
* V_565 = V_10 -> V_70 ( V_5 , V_571 ) ;
#ifdef F_159
F_6 ( L_49 , * V_565 ) ;
#endif
}
Error:
V_10 -> V_14 ( V_5 , V_10 -> V_507 , V_509 ) ;
return V_172 ;
}
static int F_170 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
unsigned char V_564 ,
unsigned char * V_565 )
{
unsigned char V_244 , V_572 = 0 ;
#ifdef F_159
F_6 ( L_50 , V_564 ) ;
#endif
F_59 ( ( V_10 -> V_512 + 999 ) / 1000 ) ;
for ( V_244 = 0x80 ; V_244 ; V_244 >>= 1 ) {
V_10 -> V_514 &= ~ V_511 ;
if ( V_564 & V_244 ) {
V_10 -> V_514 |= V_511 ;
}
V_10 -> V_14 ( V_5 , V_10 -> V_514 ,
V_516 ) ;
V_10 -> V_507 |= V_554 ;
V_10 -> V_14 ( V_5 , V_10 -> V_507 ,
V_509 ) ;
F_59 ( ( V_10 -> V_512 + 999 ) / 2000 ) ;
V_10 -> V_507 &= ~ V_554 ;
V_10 -> V_14 ( V_5 , V_10 -> V_507 ,
V_509 ) ;
F_59 ( ( V_10 -> V_512 + 999 ) / 2000 ) ;
if ( V_10 -> V_70 ( V_5 ,
V_517 ) & V_510 )
{
V_572 |= V_244 ;
}
}
#ifdef F_159
F_6 ( L_51 , V_572 ) ;
#endif
if ( V_565 )
* V_565 = V_572 ;
return 0 ;
}
static void F_172 ( struct V_4 * V_5 )
{
struct V_96 * V_97 ;
if ( V_5 -> V_573 ) {
if ( V_10 -> V_50 ) {
F_173 ( V_10 -> V_50 ) ;
}
}
if ( V_5 -> V_98 && V_56 . V_574 ) {
V_97 = & V_5 -> V_98 [ V_575 ] ;
F_174 ( V_5 , V_97 ) ;
}
}
static void F_175 ( struct V_4 * V_5 , struct V_96 * V_97 )
{
int V_103 ;
for ( V_103 = 0 ; V_103 < V_97 -> V_253 ; V_103 ++ ) {
F_37 ( V_5 , F_140 ( V_103 ) | 0x0 ,
V_576 ) ;
}
F_146 ( 0x0 , V_577 ) ;
}
static unsigned F_176 ( enum V_578 V_6 )
{
unsigned V_579 ;
switch ( V_6 ) {
case V_580 :
V_579 = F_177 ( 0 ) ;
break;
case V_581 :
V_579 = F_177 ( 1 ) ;
break;
case V_582 :
V_579 = F_178 ( 0 ) ;
break;
case V_583 :
V_579 = F_178 ( 1 ) ;
break;
case V_584 :
V_579 = F_179 ( 0 ) ;
break;
case V_585 :
V_579 = F_179 ( 1 ) ;
break;
case V_586 :
V_579 = F_180 ( 0 ) ;
break;
case V_587 :
V_579 = F_180 ( 1 ) ;
break;
case V_588 :
V_579 = F_181 ( 0 ) ;
break;
case V_589 :
V_579 = F_181 ( 1 ) ;
break;
case V_590 :
V_579 = F_182 ( 0 ) ;
break;
case V_591 :
V_579 = F_182 ( 1 ) ;
break;
case V_592 :
V_579 = F_183 ( 0 ) ;
break;
case V_593 :
V_579 = F_183 ( 1 ) ;
break;
case V_594 :
V_579 = F_184 ( 0 ) ;
break;
case V_595 :
V_579 = F_184 ( 1 ) ;
break;
case V_596 :
V_579 = V_597 ;
break;
case V_598 :
V_579 = V_209 ;
break;
case V_599 :
V_579 = V_568 ;
break;
case V_600 :
V_579 = V_439 ;
break;
case V_601 :
V_579 = V_125 ;
break;
case V_602 :
V_579 = V_157 ;
break;
case V_603 :
V_579 = V_86 ;
break;
case V_604 :
V_579 = V_87 ;
break;
case V_605 :
V_579 = V_12 ;
break;
case V_606 :
V_579 = V_15 ;
break;
default:
F_6 ( L_52 ,
V_23 , V_6 ) ;
F_2 () ;
return 0 ;
break;
}
return V_579 ;
}
static void F_185 ( struct V_607 * V_608 , unsigned V_69 ,
enum V_578 V_6 )
{
struct V_4 * V_5 = V_608 -> V_50 -> V_5 ;
unsigned V_579 ;
static const unsigned V_609 = V_610 | V_611 ;
static const unsigned V_612 =
V_613 | V_614 ;
static const unsigned V_615 =
V_616 | V_617 ;
switch ( V_6 ) {
case V_618 :
F_38 ( V_69 , V_619 ) ;
break;
case V_620 :
F_38 ( V_69 , V_621 ) ;
break;
case V_622 :
F_38 ( V_69 , V_623 ) ;
break;
case V_624 :
F_38 ( V_69 , V_625 ) ;
break;
case V_626 :
F_38 ( V_69 , V_627 ) ;
break;
case V_628 :
F_38 ( V_69 , V_629 ) ;
break;
case V_630 :
F_38 ( V_69 , V_631 ) ;
break;
case V_632 :
F_38 ( V_69 , V_633 ) ;
break;
case V_590 :
case V_591 :
case V_592 :
case V_593 :
V_579 = F_176 ( V_6 ) ;
V_10 -> V_353 ( V_5 , V_69 , V_579 ) ;
break;
case V_605 :
F_17 ( V_69 & ~ V_612 ) ;
F_3 ( V_5 , V_12 ,
V_612 , V_69 ) ;
break;
case V_606 :
F_17 ( V_69 & ~ V_615 ) ;
F_3 ( V_5 , V_15 ,
V_615 , V_69 ) ;
break;
case V_598 :
F_17 ( V_69 & ~ V_609 ) ;
default:
V_579 = F_176 ( V_6 ) ;
V_10 -> V_14 ( V_5 , V_69 , V_579 ) ;
}
}
static unsigned F_186 ( struct V_607 * V_608 ,
enum V_578 V_6 )
{
struct V_4 * V_5 = V_608 -> V_50 -> V_5 ;
unsigned V_579 ;
switch ( V_6 ) {
case V_634 :
return F_41 ( V_635 ) ;
break;
case V_636 :
return F_41 ( V_637 ) ;
break;
case V_584 :
case V_585 :
case V_586 :
case V_587 :
V_579 = F_176 ( V_6 ) ;
return V_10 -> V_638 ( V_5 , V_579 ) ;
break;
default:
V_579 = F_176 ( V_6 ) ;
return V_10 -> V_70 ( V_5 , V_579 ) ;
break;
}
return 0 ;
}
static int F_187 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
V_68 [ 0 ] = V_10 -> V_557 & V_639 ;
return 1 ;
}
static int F_188 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
V_10 -> V_557 &= ~ V_640 ;
V_10 -> V_14 ( V_5 , V_10 -> V_557 ,
V_562 ) ;
V_10 -> V_557 &= ~ V_639 ;
V_10 -> V_557 |= F_189 ( V_68 [ 0 ] ) ;
V_10 -> V_557 |= V_640 ;
V_10 -> V_14 ( V_5 , V_10 -> V_557 ,
V_562 ) ;
return V_243 -> V_165 ;
}
static int F_190 ( struct V_4 * V_5 ,
unsigned int V_641 )
{
switch ( V_641 ) {
case V_642 :
V_10 -> V_557 &= ~ V_643 ;
break;
case V_644 :
V_10 -> V_557 |= V_643 ;
break;
default:
return - V_388 ;
}
V_10 -> V_14 ( V_5 , V_10 -> V_557 ,
V_562 ) ;
return 3 ;
}
static void F_191 ( struct V_4 * V_5 ,
unsigned int * V_641 ,
unsigned int * V_645 )
{
if ( V_10 -> V_557 & V_643 ) {
* V_641 = V_644 ;
* V_645 = V_646 ;
} else {
* V_641 = V_642 ;
* V_645 = V_647 * 2 ;
}
}
static int F_192 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
switch ( V_68 [ 0 ] ) {
case V_648 :
return F_190 ( V_5 , V_68 [ 1 ] ) ;
break;
case V_649 :
F_191 ( V_5 , & V_68 [ 1 ] , & V_68 [ 2 ] ) ;
return 3 ;
default:
break;
}
return - V_388 ;
}
static int F_193 ( struct V_4 * V_5 )
{
int V_160 ;
V_160 = F_194 ( V_5 , sizeof( struct V_650 ) ) ;
if ( V_160 < 0 )
return V_160 ;
F_195 ( & V_10 -> V_72 ) ;
F_195 ( & V_10 -> V_11 ) ;
F_195 ( & V_10 -> V_36 ) ;
return 0 ;
}
static int F_196 ( int V_41 , int V_651 , int V_68 , unsigned long V_652 )
{
struct V_4 * V_5 = (struct V_4 * ) V_652 ;
if ( V_41 ) {
F_5 ( V_68 , V_653 + 2 * V_651 ) ;
return 0 ;
} else {
return F_89 ( V_653 + 2 * V_651 ) ;
}
}
static int F_197 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
V_68 [ 0 ] = F_198 ( V_5 , F_110 ( V_243 -> V_247 ) ) ;
return 1 ;
}
static int F_198 ( struct V_4 * V_5 , int V_71 )
{
int V_654 ;
int V_655 ;
V_655 = 0x0300 | ( ( V_71 & 0x100 ) << 3 ) | ( V_71 & 0xff ) ;
F_5 ( 0x04 , V_656 ) ;
for ( V_654 = 0x8000 ; V_654 ; V_654 >>= 1 ) {
F_5 ( 0x04 | ( ( V_654 & V_655 ) ? 0x02 : 0 ) ,
V_656 ) ;
F_5 ( 0x05 | ( ( V_654 & V_655 ) ? 0x02 : 0 ) ,
V_656 ) ;
}
V_655 = 0 ;
for ( V_654 = 0x80 ; V_654 ; V_654 >>= 1 ) {
F_5 ( 0x04 , V_656 ) ;
F_5 ( 0x05 , V_656 ) ;
V_655 |= ( ( F_89 ( V_194 ) & V_657 ) ? V_654 : 0 ) ;
}
F_5 ( 0x00 , V_656 ) ;
return V_655 ;
}
static int F_199 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 ,
unsigned int * V_68 )
{
V_68 [ 0 ] = V_10 -> V_658 [ F_110 ( V_243 -> V_247 ) ] ;
return 1 ;
}
static int F_200 ( struct V_4 * V_5 , unsigned int * V_68 )
{
V_68 [ 1 ] = V_10 -> V_659 * V_10 -> V_306 ;
V_68 [ 2 ] = V_10 -> V_660 * V_10 -> V_306 ;
return 3 ;
}
static int F_201 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
unsigned V_661 , V_662 ;
switch ( V_68 [ 0 ] ) {
case V_663 :
switch ( V_68 [ 1 ] ) {
case V_305 :
V_661 =
( V_68 [ 2 ] +
V_10 -> V_306 / 2 ) / V_10 -> V_306 ;
break;
case V_307 :
V_661 = V_68 [ 2 ] / V_10 -> V_306 ;
break;
case V_308 :
V_661 =
( V_68 [ 2 ] + V_10 -> V_306 -
1 ) / V_10 -> V_306 ;
break;
default:
return - V_388 ;
break;
}
switch ( V_68 [ 3 ] ) {
case V_305 :
V_662 =
( V_68 [ 4 ] +
V_10 -> V_306 / 2 ) / V_10 -> V_306 ;
break;
case V_307 :
V_662 = V_68 [ 4 ] / V_10 -> V_306 ;
break;
case V_308 :
V_662 =
( V_68 [ 4 ] + V_10 -> V_306 -
1 ) / V_10 -> V_306 ;
break;
default:
return - V_388 ;
break;
}
if ( V_661 * V_10 -> V_306 != V_68 [ 2 ] ||
V_662 * V_10 -> V_306 != V_68 [ 4 ] ) {
V_68 [ 2 ] = V_661 * V_10 -> V_306 ;
V_68 [ 4 ] = V_662 * V_10 -> V_306 ;
return - V_403 ;
}
F_32 ( F_202 ( V_661 ) |
F_203 ( V_662 ) ,
V_664 ) ;
V_10 -> V_659 = V_661 ;
V_10 -> V_660 = V_662 ;
return 5 ;
break;
case V_665 :
return F_200 ( V_5 , V_68 ) ;
break;
default:
return - V_388 ;
break;
}
return 0 ;
}
static int F_204 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
unsigned V_661 , V_662 ;
switch ( V_68 [ 0 ] ) {
case V_663 :
switch ( V_68 [ 1 ] ) {
case V_305 :
V_661 =
( V_68 [ 2 ] +
V_10 -> V_306 / 2 ) / V_10 -> V_306 ;
break;
case V_307 :
V_661 = V_68 [ 2 ] / V_10 -> V_306 ;
break;
case V_308 :
V_661 =
( V_68 [ 2 ] + V_10 -> V_306 -
1 ) / V_10 -> V_306 ;
break;
default:
return - V_388 ;
break;
}
switch ( V_68 [ 3 ] ) {
case V_305 :
V_662 =
( V_68 [ 4 ] +
V_10 -> V_306 / 2 ) / V_10 -> V_306 ;
break;
case V_307 :
V_662 = V_68 [ 4 ] / V_10 -> V_306 ;
break;
case V_308 :
V_662 =
( V_68 [ 4 ] + V_10 -> V_306 -
1 ) / V_10 -> V_306 ;
break;
default:
return - V_388 ;
break;
}
if ( V_661 * V_10 -> V_306 != V_68 [ 2 ] ||
V_662 * V_10 -> V_306 != V_68 [ 4 ] ) {
V_68 [ 2 ] = V_661 * V_10 -> V_306 ;
V_68 [ 4 ] = V_662 * V_10 -> V_306 ;
return - V_403 ;
}
F_32 ( V_661 , V_666 ) ;
V_10 -> V_659 = V_661 ;
F_32 ( V_662 , V_667 ) ;
V_10 -> V_660 = V_662 ;
return 5 ;
break;
case V_665 :
return F_200 ( V_5 , V_68 ) ;
default:
return - V_388 ;
break;
}
return 0 ;
}
static int F_205 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
F_206 ( V_5 , F_110 ( V_243 -> V_247 ) , V_68 [ 0 ] ) ;
return 1 ;
}
static int F_207 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
V_68 [ 0 ] = V_10 -> V_668 [ F_110 ( V_243 -> V_247 ) ] ;
return 1 ;
}
static void F_208 ( struct V_4 * V_5 , struct V_96 * V_97 )
{
int V_103 , V_669 ;
int V_670 ;
int V_406 = 0 ;
int V_671 ;
int V_672 = 0 ;
int type ;
int V_169 ;
type = V_56 . V_673 [ 0 ] ;
if ( type == V_674 )
return;
V_671 = V_668 [ type ] . V_671 ;
for ( V_103 = 0 ; V_103 < 3 ; V_103 ++ ) {
type = V_56 . V_673 [ V_103 ] ;
if ( type == V_674 )
break;
if ( V_668 [ type ] . V_671 != V_671 )
V_672 = 1 ;
V_406 += V_668 [ type ] . V_406 ;
}
V_670 = V_103 ;
V_97 -> V_253 = V_406 ;
if ( V_672 ) {
unsigned int * V_675 ;
if ( V_406 > V_676 ) {
F_6 ( L_53 ) ;
}
V_97 -> V_675 = V_675 = V_10 -> V_677 ;
V_169 = 0 ;
for ( V_103 = 0 ; V_103 < V_670 ; V_103 ++ ) {
type = V_56 . V_673 [ V_103 ] ;
for ( V_669 = 0 ; V_669 < V_668 [ type ] . V_406 ; V_669 ++ ) {
V_675 [ V_169 ] =
( 1 << V_668 [ type ] . V_671 ) - 1 ;
V_169 ++ ;
}
}
for ( V_169 = 0 ; V_169 < V_97 -> V_253 ; V_169 ++ )
F_206 ( V_5 , V_103 , V_97 -> V_675 [ V_103 ] / 2 ) ;
} else {
type = V_56 . V_673 [ 0 ] ;
V_97 -> V_678 = ( 1 << V_668 [ type ] . V_671 ) - 1 ;
for ( V_169 = 0 ; V_169 < V_97 -> V_253 ; V_169 ++ )
F_206 ( V_5 , V_103 , V_97 -> V_678 / 2 ) ;
}
}
static void F_206 ( struct V_4 * V_5 , int V_71 , int V_679 )
{
unsigned int V_680 = 0 , V_69 = 0 , V_654 , V_655 = 0 ;
int V_103 ;
int type ;
if ( V_10 -> V_668 [ V_71 ] == V_679 )
return;
V_10 -> V_668 [ V_71 ] = V_679 ;
for ( V_103 = 0 ; V_103 < 3 ; V_103 ++ ) {
type = V_56 . V_673 [ V_103 ] ;
if ( type == V_674 )
break;
if ( V_71 < V_668 [ type ] . V_406 ) {
V_69 = V_668 [ type ] . F_209 ( V_71 , V_679 , & V_655 ) ;
V_680 = F_210 ( V_103 ) ;
break;
}
V_71 -= V_668 [ type ] . V_406 ;
}
for ( V_654 = 1 << ( V_69 - 1 ) ; V_654 ; V_654 >>= 1 ) {
F_5 ( ( ( V_654 & V_655 ) ? 0x02 : 0 ) , V_656 ) ;
F_59 ( 1 ) ;
F_5 ( 1 | ( ( V_654 & V_655 ) ? 0x02 : 0 ) , V_656 ) ;
F_59 ( 1 ) ;
}
F_5 ( V_680 , V_656 ) ;
F_59 ( 1 ) ;
F_5 ( 0 , V_656 ) ;
}
static int F_211 ( int V_71 , int V_679 , int * V_655 )
{
V_71 ++ ;
* V_655 = ( ( V_71 & 0x1 ) << 11 ) |
( ( V_71 & 0x2 ) << 9 ) |
( ( V_71 & 0x4 ) << 7 ) | ( ( V_71 & 0x8 ) << 5 ) | ( V_679 & 0xff ) ;
return 12 ;
}
static int F_212 ( int V_71 , int V_679 , int * V_655 )
{
* V_655 = ( ( V_71 & 0x7 ) << 8 ) | ( V_679 & 0xff ) ;
return 11 ;
}
static int F_213 ( int V_71 , int V_679 , int * V_655 )
{
* V_655 = V_679 & 0xfff ;
return 12 ;
}
static int F_214 ( int V_71 , int V_679 , int * V_655 )
{
* V_655 = ( V_679 & 0xfff ) | ( V_71 ? 0xc000 : 0xa000 ) ;
return 16 ;
}
static int F_215 ( int V_71 , int V_679 , int * V_655 )
{
* V_655 = ( ( V_71 & 0xf ) << 8 ) | ( V_679 & 0xff ) ;
return 12 ;
}
static int F_216 ( int V_71 , int V_679 , int * V_655 )
{
* V_655 = ( ( V_71 + 1 ) << 8 ) | ( V_679 & 0xff ) ;
return 12 ;
}
static int F_217 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
struct V_607 * V_608 = V_97 -> V_573 ;
return F_218 ( V_608 , V_243 , V_68 ) ;
}
static int F_219 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
struct V_607 * V_608 = V_97 -> V_573 ;
return F_220 ( V_608 , V_243 , V_68 ) ;
}
static int F_221 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
struct V_607 * V_608 = V_97 -> V_573 ;
return F_222 ( V_608 , V_243 , V_68 ) ;
}
static int F_223 ( struct V_4 * V_5 , struct V_96 * V_97 )
{
int V_191 ;
#ifdef F_24
struct V_607 * V_608 = V_97 -> V_573 ;
V_191 = F_21 ( V_5 , V_608 -> V_1 ,
V_42 ) ;
if ( V_191 ) {
F_19 ( V_5 ,
L_54 ) ;
return V_191 ;
}
F_224 ( V_608 , NULL , NULL , NULL , NULL ) ;
F_30 ( V_5 , V_608 -> V_1 , 1 ) ;
V_191 = F_225 ( V_608 , V_97 -> V_100 ) ;
#else
V_191 = - V_681 ;
#endif
return V_191 ;
}
static int F_226 ( struct V_4 * V_5 ,
struct V_96 * V_97 , struct V_167 * V_168 )
{
#ifdef F_24
struct V_607 * V_608 = V_97 -> V_573 ;
return F_227 ( V_608 , V_168 ) ;
#else
return - V_681 ;
#endif
}
static int F_69 ( struct V_4 * V_5 , struct V_96 * V_97 )
{
#ifdef F_24
struct V_607 * V_608 = V_97 -> V_573 ;
int V_191 ;
V_191 = F_228 ( V_608 ) ;
F_30 ( V_5 , V_608 -> V_1 , 0 ) ;
F_28 ( V_5 , V_608 -> V_1 ) ;
return V_191 ;
#else
return 0 ;
#endif
}
static int F_229 ( struct V_4 * V_5 , unsigned V_169 ,
unsigned V_682 )
{
unsigned V_683 ;
unsigned V_684 ;
if ( ( V_682 & 0x1f ) != V_682 )
return - V_388 ;
V_683 = 1 + V_169 / 3 ;
V_684 = V_683 - 1 ;
V_10 -> V_685 [ V_684 ] &=
~ F_230 ( V_169 ) ;
V_10 -> V_685 [ V_684 ] |=
F_231 ( V_169 , V_682 ) ;
F_38 ( V_10 -> V_685 [ V_684 ] ,
F_232 ( V_683 ) ) ;
return 2 ;
}
static int F_233 ( struct V_4 * V_5 , unsigned V_169 ,
unsigned V_682 )
{
if ( V_682 != F_234 ( V_5 , V_169 ) )
return - V_388 ;
return 2 ;
}
static int F_235 ( struct V_4 * V_5 , unsigned V_169 ,
unsigned V_682 )
{
if ( V_56 . V_57 & V_58 )
return F_229 ( V_5 , V_169 , V_682 ) ;
else
return F_233 ( V_5 , V_169 , V_682 ) ;
}
static unsigned F_236 ( struct V_4 * V_5 ,
unsigned V_169 )
{
const unsigned V_684 = V_169 / 3 ;
return F_237 ( V_169 ,
V_10 ->
V_685
[ V_684 ] ) ;
}
static unsigned F_234 ( struct V_4 * V_5 , unsigned V_169 )
{
switch ( V_169 ) {
case 0 :
return V_686 ;
break;
case 1 :
return V_687 ;
break;
case 2 :
return V_688 ;
break;
case 3 :
return V_689 ;
break;
case 4 :
return V_690 ;
break;
case 5 :
return V_691 ;
break;
case 6 :
return V_692 ;
break;
case 7 :
return V_693 ;
break;
case 8 :
return V_694 ;
break;
case 9 :
return V_695 ;
break;
default:
F_6 ( L_55 , V_23 ) ;
break;
}
return 0 ;
}
static unsigned F_238 ( struct V_4 * V_5 , unsigned V_169 )
{
if ( V_56 . V_57 & V_58 )
return F_236 ( V_5 , V_169 ) ;
else
return F_234 ( V_5 , V_169 ) ;
}
static int F_239 ( struct V_4 * V_5 , unsigned V_696 ,
enum V_697 V_698 )
{
unsigned V_69 ;
if ( ( V_56 . V_57 & V_58 ) == 0 ) {
return - V_681 ;
}
V_69 = F_33 ( V_699 ) ;
V_69 &= ~ F_240 ( V_696 ) ;
V_69 |= F_241 ( V_696 , V_698 ) ;
F_32 ( V_69 , V_699 ) ;
return 0 ;
}
static int F_242 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
if ( ( V_56 . V_57 & V_58 ) == 0 ) {
return - V_681 ;
}
if ( V_68 [ 0 ] ) {
V_97 -> V_513 &= ~ V_68 [ 0 ] ;
V_97 -> V_513 |= ( V_68 [ 0 ] & V_68 [ 1 ] ) ;
F_38 ( V_97 -> V_513 , V_700 ) ;
}
V_68 [ 1 ] = F_41 ( V_701 ) ;
return V_243 -> V_165 ;
}
static int F_243 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
unsigned int V_169 ;
if ( V_243 -> V_165 < 1 )
return - V_388 ;
V_169 = F_110 ( V_243 -> V_247 ) ;
switch ( V_68 [ 0 ] ) {
case V_45 :
F_42 ( V_5 , V_17 , 1 << V_169 , 1 ) ;
break;
case V_42 :
F_42 ( V_5 , V_17 , 1 << V_169 , 0 ) ;
break;
case V_506 :
V_68 [ 1 ] =
( V_10 -> V_18 & ( 1 << V_169 ) ) ?
V_45 : V_42 ;
return 0 ;
break;
case V_702 :
return F_235 ( V_5 , V_169 , V_68 [ 1 ] ) ;
break;
case V_703 :
V_68 [ 1 ] = F_238 ( V_5 , V_169 ) ;
break;
case V_704 :
return F_239 ( V_5 , V_169 , V_68 [ 1 ] ) ;
break;
default:
return - V_388 ;
}
return 0 ;
}
static void F_244 ( struct V_4 * V_5 )
{
V_10 -> V_705 = V_706 ;
if ( F_245 ( V_5 , V_707 , 0 ) < 0 ) {
F_6 ( L_56 ) ;
}
V_10 -> V_708 =
F_246 ( 0 ,
V_709 ) |
F_246 ( 1 ,
V_710 ) |
F_246 ( 2 ,
V_711 ) |
F_246 ( 3 , V_712 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_708 ,
V_713 ) ;
V_10 -> V_714 =
F_246 ( 4 ,
V_715 ) |
F_246 ( 5 ,
V_716 ) |
F_246 ( 6 , V_717 ) ;
if ( V_56 . V_57 & V_58 )
V_10 -> V_714 |=
F_246 ( 7 , V_718 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_714 ,
V_719 ) ;
}
static int F_247 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
V_68 [ 1 ] = 0 ;
return V_243 -> V_165 ;
}
static int F_248 ( unsigned V_720 ,
unsigned * V_721 ,
unsigned * V_722 ,
unsigned * V_723 )
{
unsigned div ;
unsigned V_724 = 1 ;
static const unsigned V_725 = 0x10 ;
unsigned V_726 ;
unsigned V_727 = 1 ;
static const unsigned V_728 = 0x100 ;
static const unsigned V_729 = 1000 ;
const unsigned V_730 = V_720 * V_729 ;
static const unsigned V_731 = 12500 ;
static const unsigned V_732 = 4 ;
int V_733 = 0 ;
for ( div = 1 ; div <= V_725 ; ++ div ) {
for ( V_726 = 1 ; V_726 <= V_728 ; ++ V_726 ) {
unsigned V_734 =
( V_730 * div ) / V_726 ;
if ( abs ( V_734 - V_731 ) <
abs ( V_733 - V_731 ) ) {
V_733 = V_734 ;
V_724 = div ;
V_727 = V_726 ;
}
}
}
if ( V_733 == 0 ) {
F_6 ( L_57 , V_23 ) ;
return - V_204 ;
}
* V_721 = V_724 ;
* V_722 = V_727 ;
* V_723 =
( V_733 * V_732 +
( V_729 / 2 ) ) / V_729 ;
return 0 ;
}
static inline unsigned F_249 ( struct V_4 * V_5 )
{
if ( V_56 . V_57 & V_58 )
return 8 ;
else
return 7 ;
}
static int F_250 ( struct V_4 * V_5 ,
unsigned V_682 , unsigned V_735 )
{
static const unsigned V_736 = 50 ;
static const unsigned V_737 = 1000 ;
static const unsigned V_102 = 1000 ;
unsigned V_738 ;
unsigned V_721 ;
unsigned V_722 ;
unsigned V_103 ;
int V_191 ;
if ( V_682 == V_739 )
V_735 = 100 ;
if ( V_735 < V_736 || V_735 > V_737 ) {
F_6
( L_58
L_59 , V_23 ,
V_736 , V_737 ) ;
return - V_388 ;
}
V_10 -> V_740 &= ~ V_741 ;
V_10 -> V_14 ( V_5 , V_10 -> V_740 ,
V_742 ) ;
V_738 =
V_743 | V_744 ;
V_10 -> V_705 |=
V_745 | V_746 ;
V_10 -> V_705 &= ~ V_747 ;
switch ( V_682 ) {
case V_748 :
V_10 -> V_705 |=
V_749 ;
V_191 = F_248 ( V_735 , & V_721 ,
& V_722 ,
& V_10 -> V_306 ) ;
if ( V_191 < 0 )
return V_191 ;
break;
case V_739 :
V_10 -> V_705 |=
V_750 ;
V_191 = F_248 ( V_735 , & V_721 ,
& V_722 ,
& V_10 -> V_306 ) ;
if ( V_191 < 0 )
return V_191 ;
break;
default:
{
unsigned V_751 ;
static const unsigned V_752 = 7 ;
for ( V_751 = 0 ; V_751 <= V_752 ;
++ V_751 ) {
if ( V_682 ==
F_251 ( V_751 ) ) {
V_10 -> V_705 |=
F_252
( V_751 ) ;
break;
}
}
if ( V_751 > V_752 )
return - V_388 ;
V_191 = F_248 ( V_735 ,
& V_721 ,
& V_722 ,
& V_10 ->
V_306 ) ;
if ( V_191 < 0 )
return V_191 ;
}
break;
}
F_38 ( V_10 -> V_705 , V_753 ) ;
V_738 |=
F_253 ( V_721 ) |
F_254 ( V_722 ) ;
F_38 ( V_738 , V_754 ) ;
V_10 -> V_641 = V_682 ;
for ( V_103 = 0 ; V_103 < V_102 ; ++ V_103 ) {
if ( F_41 ( V_755 ) & V_756 ) {
break;
}
F_59 ( 1 ) ;
}
if ( V_103 == V_102 ) {
F_6
( L_60 ,
V_23 , V_682 , V_735 ) ;
return - V_757 ;
}
return 3 ;
}
static int F_245 ( struct V_4 * V_5 , unsigned V_682 ,
unsigned V_735 )
{
if ( V_682 == V_707 ) {
V_10 -> V_740 &= ~ V_741 ;
V_10 -> V_14 ( V_5 , V_10 -> V_740 ,
V_742 ) ;
V_10 -> V_306 = V_647 ;
if ( V_56 . V_57 & V_58 ) {
V_10 -> V_705 &=
~ ( V_745 |
V_746 ) ;
F_38 ( V_10 -> V_705 ,
V_753 ) ;
F_38 ( 0 , V_754 ) ;
}
V_10 -> V_641 = V_682 ;
} else {
if ( V_56 . V_57 & V_58 ) {
return F_250 ( V_5 , V_682 ,
V_735 ) ;
} else {
if ( V_682 == V_758 ) {
V_10 -> V_740 |=
V_741 ;
V_10 -> V_14 ( V_5 ,
V_10 ->
V_740 ,
V_742 ) ;
if ( V_735 == 0 ) {
F_6
( L_61 ,
V_23 ) ;
return - V_388 ;
} else {
V_10 -> V_306 = V_735 ;
}
V_10 -> V_641 = V_682 ;
} else
return - V_388 ;
}
}
return 3 ;
}
static int F_255 ( struct V_4 * V_5 , unsigned V_169 ,
unsigned V_682 )
{
if ( V_169 >= F_249 ( V_5 ) ) {
if ( V_169 == V_759 ) {
if ( V_682 == V_718 )
return 1 ;
else {
F_6
( L_62 ,
V_23 , V_169 , V_759 ) ;
return 0 ;
}
}
return 0 ;
}
switch ( V_682 ) {
case V_709 :
case V_710 :
case V_711 :
case V_712 :
case V_715 :
case V_716 :
case V_717 :
case V_760 :
case V_761 :
return 1 ;
break;
case V_718 :
if ( V_56 . V_57 & V_58 )
return 1 ;
else
return 0 ;
break;
default:
return 0 ;
break;
}
}
static int F_256 ( struct V_4 * V_5 , unsigned V_169 ,
unsigned V_682 )
{
if ( F_255 ( V_5 , V_169 , V_682 ) == 0 )
return - V_388 ;
if ( V_169 < 4 ) {
V_10 -> V_708 &= ~ F_257 ( V_169 ) ;
V_10 -> V_708 |=
F_246 ( V_169 , V_682 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_708 ,
V_713 ) ;
} else if ( V_169 < 8 ) {
V_10 -> V_714 &= ~ F_257 ( V_169 ) ;
V_10 -> V_714 |=
F_246 ( V_169 , V_682 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_714 ,
V_719 ) ;
}
return 2 ;
}
static unsigned F_258 ( struct V_4 * V_5 , unsigned V_169 )
{
if ( V_169 < 4 ) {
return F_259 ( V_169 ,
V_10 -> V_708 ) ;
} else if ( V_169 < F_249 ( V_5 ) ) {
return F_259 ( V_169 ,
V_10 -> V_714 ) ;
} else {
if ( V_169 == V_759 )
return V_718 ;
F_6 ( L_63 , V_23 ) ;
return 0 ;
}
}
static int F_260 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
unsigned int V_169 = F_110 ( V_243 -> V_247 ) ;
switch ( V_68 [ 0 ] ) {
case V_503 :
if ( V_169 < F_249 ( V_5 ) ) {
V_10 -> V_740 |=
F_261 ( V_169 ,
( V_56 .
V_57 & V_58 ) !=
0 ) ;
} else if ( V_169 == V_759 ) {
V_10 -> V_740 |=
V_762 ;
}
V_10 -> V_14 ( V_5 , V_10 -> V_740 ,
V_742 ) ;
break;
case V_505 :
if ( V_169 < F_249 ( V_5 ) ) {
V_10 -> V_740 &=
~ F_261 ( V_169 ,
( V_56 .
V_57 & V_58 )
!= 0 ) ;
} else if ( V_169 == V_759 ) {
V_10 -> V_740 &=
~ V_762 ;
}
V_10 -> V_14 ( V_5 , V_10 -> V_740 ,
V_742 ) ;
break;
case V_506 :
if ( V_169 < F_249 ( V_5 ) ) {
V_68 [ 1 ] =
( V_10 -> V_740 &
F_261 ( V_169 ,
( V_56 . V_57 &
V_58 )
!= 0 ) ) ? V_503 :
V_505 ;
} else if ( V_169 == V_759 ) {
V_68 [ 1 ] =
( V_10 -> V_740 &
V_762 )
? V_503 : V_505 ;
}
return 2 ;
break;
case V_648 :
return F_245 ( V_5 , V_68 [ 1 ] , V_68 [ 2 ] ) ;
break;
case V_649 :
V_68 [ 1 ] = V_10 -> V_641 ;
V_68 [ 2 ] = V_10 -> V_306 ;
return 3 ;
break;
case V_702 :
return F_256 ( V_5 , V_169 , V_68 [ 1 ] ) ;
break;
case V_703 :
V_68 [ 1 ] = F_258 ( V_5 , V_169 ) ;
return 2 ;
break;
default:
return - V_388 ;
break;
}
return 1 ;
}
static int F_262 ( struct V_4 * V_5 )
{
unsigned short V_126 ;
const int V_102 = V_763 ;
int V_103 ;
for ( V_103 = 0 ; V_103 < V_102 ; V_103 ++ ) {
V_126 = F_40 ( V_5 , V_764 ) ;
if ( ( V_126 & V_765 ) == 0 ) {
break;
}
F_263 ( V_766 ) ;
if ( F_264 ( 1 ) ) {
return - V_204 ;
}
}
if ( V_103 == V_102 ) {
F_6 ( L_64 , __FILE__ , V_23 ) ;
return - V_251 ;
}
return 0 ;
}
static void F_265 ( struct V_4 * V_5 , unsigned short V_75 )
{
static const int V_102 = 100 ;
int V_103 ;
F_37 ( V_5 , V_75 , V_767 ) ;
for ( V_103 = 0 ; V_103 < V_102 ; V_103 ++ ) {
if ( ( F_40 ( V_5 , V_764 ) & V_765 ) )
break;
F_59 ( 1 ) ;
}
if ( V_103 == V_102 ) {
F_19 ( V_5 , L_65 ) ;
}
}
static void F_266 ( struct V_4 * V_5 , unsigned int V_75 ,
unsigned int V_768 )
{
F_37 ( V_5 , ( ( V_75 >> 16 ) & 0xff ) ,
V_769 ) ;
F_37 ( V_5 , ( V_75 & 0xffff ) ,
V_770 ) ;
V_768 &= V_771 ;
F_265 ( V_5 , V_772 | V_768 ) ;
if ( F_262 ( V_5 ) )
F_19 ( V_5 , L_66 ) ;
}
static unsigned int F_267 ( struct V_4 * V_5 ,
unsigned int V_768 )
{
unsigned int V_75 ;
V_768 &= V_771 ;
F_265 ( V_5 , V_772 | V_773 | V_768 ) ;
if ( F_262 ( V_5 ) )
F_19 ( V_5 , L_67 ) ;
V_75 = ( F_40 ( V_5 ,
V_769 ) << 16 ) &
0xff0000 ;
V_75 |= F_40 ( V_5 , V_770 ) & 0xffff ;
return V_75 ;
}
static int F_268 ( struct V_4 * V_5 , unsigned short * V_68 )
{
int V_191 ;
unsigned short V_126 ;
F_265 ( V_5 , V_772 | V_774 ) ;
V_191 = F_262 ( V_5 ) ;
if ( V_191 ) {
F_19 ( V_5 ,
L_68 ) ;
return - V_251 ;
}
V_126 = F_40 ( V_5 , V_764 ) ;
if ( V_126 & V_775 ) {
F_6
( L_69 ) ;
return - V_204 ;
}
if ( V_126 & V_776 ) {
F_6
( L_70 ) ;
}
if ( V_68 ) {
* V_68 = F_40 ( V_5 , V_777 ) ;
* V_68 ^= ( 1 << 15 ) ;
}
return 0 ;
}
static int F_269 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
int V_165 , V_191 ;
unsigned short V_778 ;
unsigned int V_779 ;
const unsigned int V_780 = 0x1000 ;
if ( V_243 -> V_247 & V_260 )
V_779 = V_780 ;
else
V_779 = F_110 ( V_243 -> V_247 ) ;
F_37 ( V_5 , V_779 , V_781 ) ;
for ( V_165 = 0 ; V_165 < V_243 -> V_165 ; V_165 ++ ) {
V_191 = F_268 ( V_5 , & V_778 ) ;
if ( V_191 < 0 )
return V_191 ;
V_68 [ V_165 ] = V_778 ;
}
return V_243 -> V_165 ;
}
static int F_270 ( struct V_4 * V_5 )
{
unsigned int V_274 =
V_782 | V_783 ;
#if 1
F_266 ( V_5 , V_274 | V_784 ,
V_785 ) ;
F_268 ( V_5 , NULL ) ;
#else
F_266 ( V_5 , 0x400000 , V_786 ) ;
F_266 ( V_5 , V_274 | V_787 ,
V_785 ) ;
if ( F_262 ( V_5 ) )
F_19 ( V_5 , L_71 ) ;
#endif
#ifdef F_271
F_6 ( L_72 , F_267 ( V_5 ,
V_785 ) ) ;
F_6 ( L_73 , F_267 ( V_5 , V_786 ) ) ;
F_6 ( L_74 , F_267 ( V_5 ,
V_788 ) ) ;
#endif
return 0 ;
}

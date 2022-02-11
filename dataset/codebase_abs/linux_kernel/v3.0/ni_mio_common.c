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
void F_28 ( struct V_4 * V_5 ,
unsigned V_30 )
{
#ifdef F_24
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
#endif
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
struct V_96 * V_97 = V_5 -> V_98 + V_99 ;
unsigned long V_9 ;
F_4 ( & V_10 -> V_36 , V_9 ) ;
if ( V_10 -> V_37 )
F_55 ( V_10 -> V_37 , V_97 -> V_100 ) ;
F_8 ( & V_10 -> V_36 , V_9 ) ;
}
static void F_56 ( struct V_82 * V_38 ,
struct V_4 * V_5 )
{
struct V_96 * V_97 = V_5 -> V_98 + V_101 ;
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
struct V_96 * V_97 = V_5 -> V_98 + V_99 ;
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
struct V_96 * V_97 =
V_5 -> V_98 + F_1 ( V_1 ) ;
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
struct V_96 * V_97 = V_5 -> V_98 + V_99 ;
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
struct V_96 * V_97 = V_5 -> V_98 + V_101 ;
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
struct V_96 * V_97 = V_5 -> V_98 + V_99 ;
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
struct V_96 * V_97 = V_5 -> V_98 + V_99 ;
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
struct V_96 * V_97 = V_5 -> V_98 + V_99 ;
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
struct V_96 * V_97 = V_5 -> V_98 + V_99 ;
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
struct V_96 * V_97 = V_5 -> V_98 + V_99 ;
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
struct V_96 * V_97 = V_5 -> V_98 + V_101 ;
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
unsigned long V_9 = 0 ;
int V_239 ;
if ( F_106 () == 0 )
F_4 ( & V_5 -> V_85 , V_9 ) ;
#ifndef F_24
F_61 ( V_5 ) ;
#else
F_54 ( V_5 ) ;
#endif
V_239 = V_97 -> V_100 -> V_240 - V_97 -> V_100 -> V_241 ;
if ( F_106 () == 0 )
F_8 ( & V_5 -> V_85 , V_9 ) ;
return V_239 ;
}
static int F_107 ( struct V_4 * V_5 ,
struct V_96 * V_97 , struct V_242 * V_243 ,
unsigned int * V_68 )
{
int V_103 , V_165 ;
const unsigned int V_244 = ( 1 << V_56 . V_245 ) - 1 ;
unsigned V_246 ;
unsigned short V_77 ;
unsigned long V_185 ;
F_108 ( V_5 , 1 , & V_243 -> V_247 ) ;
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
void F_109 ( struct V_4 * V_5 )
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
static void F_110 ( struct V_4 * V_5 ,
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
V_169 = F_111 ( V_254 [ 0 ] ) ;
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
V_261 |= F_112 ( V_258 ) ;
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
V_169 = F_111 ( V_254 [ V_103 ] ) ;
V_255 = F_113 ( V_254 [ V_103 ] ) ;
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
V_274 |= F_114 ( V_169 ) ;
V_274 |=
F_115 ( V_56 . V_57 , V_169 ) ;
V_274 |= F_116 ( V_258 ) ;
if ( V_103 == V_253 - 1 )
V_274 |= V_282 ;
if ( V_257 )
V_274 |= V_283 ;
V_274 |= V_284 ;
F_38 ( V_274 , V_285 ) ;
}
F_109 ( V_5 ) ;
}
static void F_108 ( struct V_4 * V_5 ,
unsigned int V_253 , unsigned int * V_254 )
{
unsigned int V_169 , V_171 , V_255 ;
unsigned int V_103 ;
unsigned int V_286 , V_287 ;
unsigned V_256 ;
unsigned int V_257 ;
if ( V_56 . V_57 & V_58 ) {
F_110 ( V_5 , V_253 , V_254 ) ;
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
F_117 ( 100 ) ;
} else if ( ! ( V_254 [ 0 ] & V_260 )
&& V_10 -> V_290 ) {
F_38 ( V_10 -> V_266 |
V_293 ,
V_292 ) ;
F_38 ( V_10 -> V_266 ,
V_292 ) ;
V_10 -> V_290 = 0 ;
F_117 ( 100 ) ;
}
}
V_256 = 1 << ( V_56 . V_245 - 1 ) ;
for ( V_103 = 0 ; V_103 < V_253 ; V_103 ++ ) {
if ( ( V_56 . V_57 != V_63 )
&& ( V_254 [ V_103 ] & V_260 ) ) {
V_169 = V_10 -> V_266 ;
} else {
V_169 = F_111 ( V_254 [ V_103 ] ) ;
}
V_255 = F_113 ( V_254 [ V_103 ] ) ;
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
F_38 ( F_111 ( V_254 [ V_103 ] ) & 0x0003 ,
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
V_286 |= F_118 ( V_169 ) ;
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
F_109 ( V_5 ) ;
}
}
static int F_119 ( const struct V_4 * V_5 , unsigned V_302 ,
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
static unsigned F_120 ( const struct V_4 * V_5 , int V_309 )
{
return V_10 -> V_306 * ( V_309 + 1 ) ;
}
static unsigned F_121 ( struct V_4 * V_5 ,
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
static int F_122 ( struct V_4 * V_5 , struct V_96 * V_97 ,
struct V_167 * V_168 )
{
int V_172 = 0 ;
int V_312 ;
int V_313 ;
if ( ( V_168 -> V_9 & V_314 ) ) {
V_168 -> V_9 &= ~ V_314 ;
}
V_312 = V_168 -> V_315 ;
V_168 -> V_315 &= V_316 | V_317 | V_318 ;
if ( ! V_168 -> V_315 || V_312 != V_168 -> V_315 )
V_172 ++ ;
V_312 = V_168 -> V_319 ;
V_168 -> V_319 &= V_320 | V_318 ;
if ( ! V_168 -> V_319 || V_312 != V_168 -> V_319 )
V_172 ++ ;
V_312 = V_168 -> V_321 ;
V_313 = V_320 | V_318 ;
if ( ( V_56 . V_57 == V_184 )
|| ( V_56 . V_57 == V_63 ) )
V_313 |= V_316 ;
V_168 -> V_321 &= V_313 ;
if ( ! V_168 -> V_321 || V_312 != V_168 -> V_321 )
V_172 ++ ;
V_312 = V_168 -> V_322 ;
V_168 -> V_322 &= V_323 ;
if ( ! V_168 -> V_322 || V_312 != V_168 -> V_322 )
V_172 ++ ;
V_312 = V_168 -> V_324 ;
V_168 -> V_324 &= V_323 | V_325 ;
if ( ! V_168 -> V_324 || V_312 != V_168 -> V_324 )
V_172 ++ ;
if ( V_172 )
return 1 ;
if ( V_168 -> V_315 != V_316 &&
V_168 -> V_315 != V_317 && V_168 -> V_315 != V_318 )
V_172 ++ ;
if ( V_168 -> V_319 != V_320 &&
V_168 -> V_319 != V_318 &&
V_168 -> V_319 != V_326 )
V_172 ++ ;
if ( V_168 -> V_321 != V_320 &&
V_168 -> V_321 != V_318 && V_168 -> V_321 != V_316 )
V_172 ++ ;
if ( V_168 -> V_324 != V_323 && V_168 -> V_324 != V_325 )
V_172 ++ ;
if ( V_172 )
return 2 ;
if ( V_168 -> V_315 == V_318 ) {
unsigned int V_312 = F_111 ( V_168 -> V_327 ) ;
if ( V_312 > 16 )
V_312 = 16 ;
V_312 |= ( V_168 -> V_327 & ( V_328 | V_329 ) ) ;
if ( V_168 -> V_327 != V_312 ) {
V_168 -> V_327 = V_312 ;
V_172 ++ ;
}
} else {
if ( V_168 -> V_327 != 0 ) {
V_168 -> V_327 = 0 ;
V_172 ++ ;
}
}
if ( V_168 -> V_319 == V_320 ) {
if ( V_168 -> V_330 < F_121 ( V_5 ,
V_168 ->
V_179 ) )
{
V_168 -> V_330 =
F_121 ( V_5 , V_168 -> V_179 ) ;
V_172 ++ ;
}
if ( V_168 -> V_330 > V_10 -> V_306 * 0xffffff ) {
V_168 -> V_330 = V_10 -> V_306 * 0xffffff ;
V_172 ++ ;
}
} else if ( V_168 -> V_319 == V_318 ) {
unsigned int V_312 = F_111 ( V_168 -> V_330 ) ;
if ( V_312 > 16 )
V_312 = 16 ;
V_312 |= ( V_168 -> V_330 & ( V_328 | V_329 ) ) ;
if ( V_168 -> V_330 != V_312 ) {
V_168 -> V_330 = V_312 ;
V_172 ++ ;
}
} else {
if ( V_168 -> V_330 ) {
V_168 -> V_330 = 0 ;
V_172 ++ ;
}
}
if ( V_168 -> V_321 == V_320 ) {
if ( ( V_56 . V_57 == V_184 )
|| ( V_56 . V_57 == V_63 ) ) {
if ( V_168 -> V_331 != 0 ) {
V_168 -> V_331 = 0 ;
V_172 ++ ;
}
} else {
if ( V_168 -> V_331 < V_56 . V_311 ) {
V_168 -> V_331 = V_56 . V_311 ;
V_172 ++ ;
}
if ( V_168 -> V_331 > V_10 -> V_306 * 0xffff ) {
V_168 -> V_331 = V_10 -> V_306 * 0xffff ;
V_172 ++ ;
}
}
} else if ( V_168 -> V_321 == V_318 ) {
unsigned int V_312 = F_111 ( V_168 -> V_331 ) ;
if ( V_312 > 16 )
V_312 = 16 ;
V_312 |= ( V_168 -> V_331 & ( V_264 | V_328 ) ) ;
if ( V_168 -> V_331 != V_312 ) {
V_168 -> V_331 = V_312 ;
V_172 ++ ;
}
} else if ( V_168 -> V_321 == V_316 ) {
if ( V_168 -> V_331 != 0 ) {
V_168 -> V_331 = 0 ;
V_172 ++ ;
}
}
if ( V_168 -> V_332 != V_168 -> V_179 ) {
V_168 -> V_332 = V_168 -> V_179 ;
V_172 ++ ;
}
if ( V_168 -> V_324 == V_323 ) {
unsigned int V_333 = 0x01000000 ;
if ( V_56 . V_57 == V_184 )
V_333 -= V_248 ;
if ( V_168 -> V_334 > V_333 ) {
V_168 -> V_334 = V_333 ;
V_172 ++ ;
}
if ( V_168 -> V_334 < 1 ) {
V_168 -> V_334 = 1 ;
V_172 ++ ;
}
} else {
if ( V_168 -> V_334 != 0 ) {
V_168 -> V_334 = 0 ;
V_172 ++ ;
}
}
if ( V_172 )
return 3 ;
if ( V_168 -> V_319 == V_320 ) {
V_312 = V_168 -> V_330 ;
V_168 -> V_330 =
F_120 ( V_5 , F_119 ( V_5 ,
V_168 -> V_330 ,
V_168 ->
V_9 &
V_335 ) ) ;
if ( V_312 != V_168 -> V_330 )
V_172 ++ ;
}
if ( V_168 -> V_321 == V_320 ) {
if ( ( V_56 . V_57 != V_184 )
&& ( V_56 . V_57 != V_63 ) ) {
V_312 = V_168 -> V_331 ;
V_168 -> V_331 =
F_120 ( V_5 , F_119 ( V_5 ,
V_168 -> V_331 ,
V_168 ->
V_9 &
V_335 ) ) ;
if ( V_312 != V_168 -> V_331 )
V_172 ++ ;
if ( V_168 -> V_319 == V_320 &&
V_168 -> V_330 <
V_168 -> V_331 * V_168 -> V_332 ) {
V_168 -> V_330 =
V_168 -> V_331 * V_168 -> V_332 ;
V_172 ++ ;
}
}
}
if ( V_172 )
return 4 ;
return 0 ;
}
static int F_123 ( struct V_4 * V_5 , struct V_96 * V_97 )
{
const struct V_167 * V_168 = & V_97 -> V_100 -> V_168 ;
int V_309 ;
int V_336 = 0 ;
int V_337 = 0 ;
int V_338 = 0 ;
unsigned int V_339 ;
int V_340 = 0 ;
F_78 ( L_30 ) ;
if ( V_5 -> V_76 == 0 ) {
F_19 ( V_5 , L_31 ) ;
return - V_204 ;
}
F_31 ( V_5 ) ;
F_108 ( V_5 , V_168 -> V_179 , V_168 -> V_174 ) ;
V_10 -> V_14 ( V_5 , V_207 , V_209 ) ;
V_10 -> V_341 &= ~ V_342 ;
V_10 -> V_14 ( V_5 , V_10 -> V_341 ,
V_343 ) ;
switch ( V_168 -> V_315 ) {
case V_317 :
case V_316 :
V_10 -> V_14 ( V_5 , F_124 ( 0 ) |
V_344 | V_345 |
F_125 ( 0 ) ,
V_346 ) ;
break;
case V_318 :
{
int V_169 = F_111 ( V_168 -> V_327 ) ;
unsigned int V_69 = F_124 ( 0 ) |
V_344 | F_125 ( V_169 + 1 ) ;
if ( V_168 -> V_327 & V_328 )
V_69 |= V_347 ;
if ( V_168 -> V_327 & V_329 )
V_69 |= V_345 ;
V_10 -> V_14 ( V_5 , V_69 ,
V_346 ) ;
break;
}
}
V_337 &= ~ V_348 ;
V_337 &= ~ V_349 ;
V_337 &= ~ V_350 ;
V_10 -> V_14 ( V_5 , V_337 , V_223 ) ;
if ( V_168 -> V_179 == 1 || ( V_56 . V_57 == V_184 )
|| ( V_56 . V_57 == V_63 ) ) {
V_338 |= V_351 ;
V_338 |= F_126 ( 31 ) ;
V_338 |= V_352 ;
} else {
V_338 |= F_126 ( 19 ) ;
}
V_10 -> V_14 ( V_5 , V_338 ,
V_353 ) ;
V_10 -> V_110 = 0 ;
switch ( V_168 -> V_324 ) {
case V_323 :
V_339 = V_168 -> V_334 - 1 ;
if ( V_56 . V_57 == V_184 ) {
V_339 += V_248 ;
}
V_10 -> V_354 ( V_5 , V_339 , V_355 ) ;
V_336 |= V_220 | V_221 | V_356 ;
V_10 -> V_14 ( V_5 , V_336 , V_222 ) ;
V_10 -> V_14 ( V_5 , V_357 , V_219 ) ;
V_10 -> V_141 = 0 ;
if ( V_339 == 0 ) {
V_10 -> V_110 |= V_111 ;
V_340 |= V_214 ;
if ( V_168 -> V_179 > 1 )
V_338 |=
V_351 | V_358 ;
}
break;
case V_325 :
V_10 -> V_354 ( V_5 , 0 , V_355 ) ;
V_336 |= V_220 | V_221 | V_359 ;
V_10 -> V_14 ( V_5 , V_336 , V_222 ) ;
V_10 -> V_14 ( V_5 , V_357 , V_219 ) ;
V_10 -> V_141 = 1 ;
break;
}
switch ( V_168 -> V_319 ) {
case V_320 :
V_338 |= V_360 | V_361 ;
V_10 -> V_14 ( V_5 , V_338 ,
V_353 ) ;
V_337 |= F_127 ( 0 ) ;
V_337 &= ~ V_362 ;
V_10 -> V_14 ( V_5 , V_337 , V_223 ) ;
V_309 = F_119 ( V_5 , V_168 -> V_330 ,
V_305 ) ;
V_10 -> V_354 ( V_5 , V_309 , V_363 ) ;
V_10 -> V_14 ( V_5 , V_364 , V_219 ) ;
break;
case V_318 :
if ( V_168 -> V_330 & V_329 )
V_338 |= V_360 ;
if ( V_168 -> V_330 & V_328 )
V_338 |= V_365 ;
if ( V_168 -> V_319 != V_168 -> V_321 ||
( V_168 -> V_330 & ~ V_329 ) !=
( V_168 -> V_331 & ~ V_329 ) )
V_338 |= V_361 ;
V_338 |=
F_128 ( 1 + F_111 ( V_168 -> V_330 ) ) ;
V_10 -> V_14 ( V_5 , V_338 ,
V_353 ) ;
break;
}
switch ( V_168 -> V_321 ) {
case V_320 :
case V_316 :
if ( V_168 -> V_331 == 0 || V_168 -> V_321 == V_316 )
V_309 = 1 ;
else
V_309 = F_119 ( V_5 , V_168 -> V_331 ,
V_305 ) ;
V_10 -> V_14 ( V_5 , 1 , V_366 ) ;
V_10 -> V_14 ( V_5 , V_309 , V_367 ) ;
V_337 &= ~ V_368 ;
V_337 |= V_369 ;
V_10 -> V_14 ( V_5 , V_337 , V_223 ) ;
V_10 -> V_14 ( V_5 , V_370 , V_219 ) ;
V_337 |= V_369 ;
V_337 |= V_368 ;
V_10 -> V_14 ( V_5 , V_337 , V_223 ) ;
break;
case V_318 :
V_336 |= F_129 ( 1 + V_168 -> V_331 ) ;
if ( ( V_168 -> V_331 & V_328 ) == 0 )
V_336 |= V_371 ;
V_10 -> V_14 ( V_5 , V_336 , V_222 ) ;
V_337 |= V_372 | V_373 ;
V_10 -> V_14 ( V_5 , V_337 , V_223 ) ;
break;
}
if ( V_5 -> V_76 ) {
V_340 |= V_215 |
V_210 ;
#ifndef F_24
V_340 |= V_216 ;
#endif
if ( V_168 -> V_9 & V_374
|| ( V_10 -> V_110 & V_111 ) ) {
V_10 -> V_106 = V_107 ;
} else {
V_10 -> V_106 = V_375 ;
}
switch ( V_10 -> V_106 ) {
case V_375 :
#ifdef F_24
V_10 -> V_14 ( V_5 , V_376 ,
V_224 ) ;
#else
V_10 -> V_14 ( V_5 , V_377 ,
V_224 ) ;
#endif
break;
case V_378 :
V_10 -> V_14 ( V_5 , V_379 ,
V_224 ) ;
break;
case V_107 :
#ifdef F_24
V_10 -> V_14 ( V_5 , V_379 ,
V_224 ) ;
#else
V_10 -> V_14 ( V_5 , V_377 ,
V_224 ) ;
#endif
V_340 |= V_214 ;
break;
default:
break;
}
V_10 -> V_14 ( V_5 , V_237 | V_124 | V_122 | V_236 | V_120 | V_118 | V_235 , V_125 ) ;
F_42 ( V_5 , V_12 ,
V_340 , 1 ) ;
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
V_380 | V_381 | V_382 |
V_383 , V_219 ) ;
break;
case V_318 :
V_10 -> V_14 ( V_5 ,
V_380 | V_381 | V_382 |
V_383 , V_219 ) ;
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
V_10 -> V_14 ( V_5 , V_384 | V_10 -> V_110 ,
V_385 ) ;
V_97 -> V_100 -> V_386 = NULL ;
break;
case V_318 :
V_97 -> V_100 -> V_386 = NULL ;
break;
case V_317 :
V_97 -> V_100 -> V_386 = & V_387 ;
break;
}
F_78 ( L_34 ) ;
return 0 ;
}
static int V_387 ( struct V_4 * V_5 , struct V_96 * V_97 ,
unsigned int V_388 )
{
if ( V_388 != 0 )
return - V_389 ;
V_10 -> V_14 ( V_5 , V_384 | V_10 -> V_110 ,
V_385 ) ;
V_97 -> V_100 -> V_386 = NULL ;
return 1 ;
}
static int F_130 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
if ( V_243 -> V_165 < 1 )
return - V_389 ;
switch ( V_68 [ 0 ] ) {
case V_390 :
return F_131 ( V_5 , V_97 , V_243 , V_68 ) ;
case V_391 :
if ( V_56 . V_57 & V_58 ) {
if ( V_68 [ 1 ] & ~ ( V_267 |
V_268 |
V_269 |
V_270 ) ) {
return - V_389 ;
}
V_10 -> V_266 = V_68 [ 1 ] ;
} else if ( V_56 . V_57 == V_63 ) {
unsigned int V_392 ;
V_392 = V_68 [ 1 ] & 0xf ;
if ( V_392 > 0xF )
return - V_389 ;
V_10 -> V_266 = V_392 ;
F_38 ( V_392 , V_292 ) ;
} else {
unsigned int V_392 ;
unsigned int V_393 ;
V_392 = V_68 [ 1 ] & 0xf ;
V_393 = ( V_68 [ 1 ] >> 4 ) & 0xff ;
if ( V_392 >= 8 )
return - V_389 ;
V_10 -> V_266 = V_392 ;
if ( V_56 . V_57 == V_184 ) {
F_5 ( V_393 ,
V_394 ) ;
}
}
return 2 ;
default:
break;
}
return - V_389 ;
}
static int F_131 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 ,
unsigned int * V_68 )
{
unsigned int V_395 , V_396 , V_397 ;
int V_172 = 0 ;
if ( ! V_56 . V_398 )
return - V_389 ;
if ( ( V_68 [ 1 ] & 0xffff0000 ) != V_399 ) {
V_68 [ 1 ] &= ( V_399 | 0xffff ) ;
V_172 ++ ;
}
if ( V_68 [ 2 ] >= V_56 . V_400 ) {
V_68 [ 2 ] = V_56 . V_400 - 1 ;
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
V_395 = V_68 [ 3 ] ;
V_396 = V_68 [ 4 ] ;
V_397 = V_68 [ 1 ] & 0xff ;
if ( V_397 & 0xf0 ) {
if ( V_396 < V_395 ) {
V_395 = V_68 [ 4 ] ;
V_396 = V_68 [ 3 ] ;
V_397 =
( ( V_68 [ 1 ] & 0xf ) << 4 ) | ( ( V_68 [ 1 ] & 0xf0 ) >> 4 ) ;
}
V_10 -> V_401 = V_395 ;
V_10 -> V_402 = V_396 ;
switch ( V_397 ) {
case 0x81 :
V_10 -> V_403 = 6 ;
break;
case 0x42 :
V_10 -> V_403 = 3 ;
break;
case 0x96 :
V_10 -> V_403 = 2 ;
break;
default:
V_68 [ 1 ] &= ~ 0xff ;
V_172 ++ ;
}
} else {
if ( V_396 != 0 ) {
V_68 [ 4 ] = 0 ;
V_172 ++ ;
}
switch ( V_397 ) {
case 0x06 :
V_10 -> V_402 = V_395 ;
V_10 -> V_403 = 0 ;
break;
case 0x09 :
V_10 -> V_401 = V_395 ;
V_10 -> V_403 = 1 ;
break;
default:
V_68 [ 1 ] &= ~ 0xff ;
V_172 ++ ;
}
}
if ( V_172 )
return - V_404 ;
return 5 ;
}
static void F_132 ( struct V_4 * V_5 , struct V_96 * V_97 ,
void * V_68 , unsigned int V_195 ,
unsigned int V_196 )
{
struct V_166 * V_100 = V_97 -> V_100 ;
unsigned int V_171 ;
unsigned int V_103 ;
unsigned int V_256 ;
unsigned int V_197 = V_195 / sizeof( short ) ;
short * V_198 = V_68 ;
V_256 = 1 << ( V_56 . V_405 - 1 ) ;
for ( V_103 = 0 ; V_103 < V_197 ; V_103 ++ ) {
V_171 = F_82 ( V_100 -> V_168 . V_174 [ V_196 ] ) ;
if ( V_56 . V_406 == 0 || ( V_171 & 1 ) == 0 )
V_198 [ V_103 ] -= V_256 ;
#ifdef F_24
V_198 [ V_103 ] = F_133 ( V_198 [ V_103 ] ) ;
#endif
V_196 ++ ;
V_196 %= V_100 -> V_168 . V_179 ;
}
}
static int F_134 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
unsigned int V_247 [] ,
unsigned int V_407 , int V_408 )
{
unsigned int V_171 ;
unsigned int V_169 ;
unsigned int V_409 ;
int V_103 ;
int V_410 = 0 ;
if ( V_408 ) {
for ( V_103 = 0 ; V_103 < V_56 . V_411 ; ++ V_103 ) {
V_10 -> V_412 [ V_103 ] &= ~ V_413 ;
F_5 ( V_10 -> V_412 [ V_103 ] ,
F_135 ( V_103 ) ) ;
F_5 ( 0xf , F_136 ( V_103 ) ) ;
}
}
for ( V_103 = 0 ; V_103 < V_407 ; V_103 ++ ) {
const struct V_414 * V_415 ;
V_169 = F_111 ( V_247 [ V_103 ] ) ;
V_171 = F_82 ( V_247 [ V_103 ] ) ;
V_415 = V_97 -> V_416 -> V_171 + V_171 ;
V_410 = 0 ;
V_409 = 0 ;
switch ( V_415 -> V_417 - V_415 -> V_418 ) {
case 20000000 :
V_409 |= V_419 ;
F_5 ( 0 , F_137 ( V_169 ) ) ;
break;
case 10000000 :
V_409 |= V_420 ;
F_5 ( 0 , F_137 ( V_169 ) ) ;
break;
case 4000000 :
V_409 |= V_419 ;
F_5 ( V_421 ,
F_137 ( V_169 ) ) ;
break;
case 2000000 :
V_409 |= V_420 ;
F_5 ( V_421 ,
F_137 ( V_169 ) ) ;
break;
default:
F_6 ( L_35 ,
V_23 ) ;
break;
}
switch ( V_415 -> V_417 + V_415 -> V_418 ) {
case 0 :
V_409 |= V_422 ;
break;
case 10000000 :
V_409 |= V_423 ;
break;
default:
F_6 ( L_36 ,
V_23 ) ;
break;
}
if ( V_408 )
V_409 |= V_413 ;
F_5 ( V_409 , F_135 ( V_169 ) ) ;
V_10 -> V_412 [ V_169 ] = V_409 ;
F_5 ( V_103 , F_136 ( V_169 ) ) ;
}
return V_410 ;
}
static int F_138 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
unsigned int V_247 [] ,
unsigned int V_407 )
{
unsigned int V_171 ;
unsigned int V_169 ;
unsigned int V_409 ;
int V_103 ;
int V_410 = 0 ;
for ( V_103 = 0 ; V_103 < V_407 ; V_103 ++ ) {
V_169 = F_111 ( V_247 [ V_103 ] ) ;
V_171 = F_82 ( V_247 [ V_103 ] ) ;
V_409 = F_139 ( V_169 ) ;
if ( V_56 . V_406 ) {
if ( ( V_171 & 1 ) == 0 ) {
V_409 |= V_424 ;
V_410 = ( 1 << ( V_56 . V_405 - 1 ) ) ;
} else {
V_410 = 0 ;
}
if ( V_171 & 2 )
V_409 |= V_425 ;
} else {
V_409 |= V_424 ;
V_410 = ( 1 << ( V_56 . V_405 - 1 ) ) ;
}
if ( V_247 [ V_103 ] & V_426 )
V_409 |= V_427 ;
V_409 |= ( F_113 ( V_247 [ V_103 ] ) ==
V_281 ) ? V_428 : 0 ;
F_38 ( V_409 , V_429 ) ;
V_10 -> V_412 [ V_169 ] = V_409 ;
}
return V_410 ;
}
static int F_140 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
unsigned int V_247 [] , unsigned int V_407 ,
int V_408 )
{
if ( V_56 . V_57 & V_58 )
return F_134 ( V_5 , V_97 , V_247 , V_407 ,
V_408 ) ;
else
return F_138 ( V_5 , V_97 , V_247 , V_407 ) ;
}
static int F_141 ( struct V_4 * V_5 ,
struct V_96 * V_97 , struct V_242 * V_243 ,
unsigned int * V_68 )
{
V_68 [ 0 ] = V_10 -> V_430 [ F_111 ( V_243 -> V_247 ) ] ;
return 1 ;
}
static int F_142 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
unsigned int V_169 = F_111 ( V_243 -> V_247 ) ;
unsigned int V_410 ;
V_410 = F_140 ( V_5 , V_97 , & V_243 -> V_247 , 1 , 0 ) ;
V_10 -> V_430 [ V_169 ] = V_68 [ 0 ] ;
if ( V_56 . V_57 & V_58 ) {
F_38 ( V_68 [ 0 ] , F_143 ( V_169 ) ) ;
} else
F_38 ( V_68 [ 0 ] ^ V_410 ,
( V_169 ) ? V_431 : V_432 ) ;
return 1 ;
}
static int F_144 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
unsigned int V_169 = F_111 ( V_243 -> V_247 ) ;
unsigned int V_410 ;
F_145 ( 1 << V_169 , V_433 ) ;
V_410 = 1 << ( V_56 . V_405 - 1 ) ;
F_140 ( V_5 , V_97 , & V_243 -> V_247 , 1 , 0 ) ;
V_10 -> V_430 [ V_169 ] = V_68 [ 0 ] ;
F_145 ( V_68 [ 0 ] ^ V_410 , F_146 ( V_169 ) ) ;
return 1 ;
}
static int F_147 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
switch ( V_68 [ 0 ] ) {
case V_434 :
switch ( V_68 [ 1 ] ) {
case V_45 :
V_68 [ 2 ] = 1 + V_56 . V_180 * sizeof( short ) ;
if ( V_10 -> V_38 )
V_68 [ 2 ] += V_10 -> V_38 -> V_435 ;
break;
case V_42 :
V_68 [ 2 ] = 0 ;
break;
default:
return - V_389 ;
break;
}
return 0 ;
default:
break;
}
return - V_389 ;
}
static int F_148 ( struct V_4 * V_5 , struct V_96 * V_97 ,
unsigned int V_388 )
{
int V_160 ;
int V_436 ;
int V_103 ;
static const int V_102 = 1000 ;
if ( V_388 != 0 )
return - V_389 ;
V_97 -> V_100 -> V_386 = NULL ;
F_42 ( V_5 , V_15 ,
V_161 | V_162 , 0 ) ;
V_436 = V_162 ;
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
V_436 |= V_161 ;
#endif
V_10 -> V_14 ( V_5 , V_10 -> V_437 | V_438 ,
V_439 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_437 , V_439 ) ;
for ( V_103 = 0 ; V_103 < V_102 ; V_103 ++ ) {
F_59 ( 1 ) ;
if ( ( V_10 -> V_70 ( V_5 ,
V_440 ) &
V_441 ) == 0 )
break;
}
if ( V_103 == V_102 ) {
F_19 ( V_5 ,
L_37 ) ;
return - V_204 ;
}
V_10 -> V_14 ( V_5 , V_146 ,
V_157 ) ;
F_42 ( V_5 , V_15 , V_436 , 1 ) ;
V_10 -> V_14 ( V_5 ,
V_10 -> V_442 | V_443 | V_444 | V_445
| V_446 | V_447 ,
V_448 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_449 | V_450 ,
V_451 ) ;
return 0 ;
}
static int F_149 ( struct V_4 * V_5 , struct V_96 * V_97 )
{
const struct V_167 * V_168 = & V_97 -> V_100 -> V_168 ;
int V_69 ;
int V_103 ;
unsigned V_452 ;
if ( V_5 -> V_76 == 0 ) {
F_19 ( V_5 , L_31 ) ;
return - V_204 ;
}
V_10 -> V_14 ( V_5 , V_453 , V_209 ) ;
V_10 -> V_14 ( V_5 , V_454 , V_448 ) ;
if ( V_56 . V_57 & V_175 ) {
F_145 ( V_455 , V_456 ) ;
V_69 = 0 ;
for ( V_103 = 0 ; V_103 < V_168 -> V_179 ; V_103 ++ ) {
int V_169 ;
V_169 = F_111 ( V_168 -> V_174 [ V_103 ] ) ;
V_69 |= 1 << V_169 ;
F_145 ( V_169 , V_457 ) ;
}
F_145 ( V_69 , V_458 ) ;
}
F_140 ( V_5 , V_97 , V_168 -> V_174 , V_168 -> V_179 , 1 ) ;
if ( V_168 -> V_324 == V_325 ) {
V_10 -> V_459 |= V_460 ;
V_10 -> V_459 &= ~ V_461 ;
} else {
V_10 -> V_459 &= ~ V_460 ;
V_10 -> V_459 |= V_461 ;
}
V_10 -> V_14 ( V_5 , V_10 -> V_459 , V_462 ) ;
switch ( V_168 -> V_315 ) {
case V_317 :
case V_316 :
V_10 -> V_463 &=
~ ( V_464 | F_150 ( - 1 ) ) ;
V_10 -> V_463 |= V_465 | V_466 ;
V_10 -> V_14 ( V_5 , V_10 -> V_463 ,
V_467 ) ;
break;
case V_318 :
V_10 -> V_463 =
F_150 ( F_111 ( V_168 -> V_327 ) + 1 ) ;
if ( V_168 -> V_327 & V_328 )
V_10 -> V_463 |= V_464 ;
if ( V_168 -> V_327 & V_329 )
V_10 -> V_463 |= V_465 ;
V_10 -> V_14 ( V_5 , V_10 -> V_463 ,
V_467 ) ;
break;
default:
F_2 () ;
break;
}
V_10 -> V_437 &= ~ V_468 ;
V_10 -> V_14 ( V_5 , V_10 -> V_437 , V_439 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_459 , V_462 ) ;
V_10 -> V_469 &= ~ V_470 ;
V_10 -> V_14 ( V_5 , V_10 -> V_469 , V_471 ) ;
if ( V_168 -> V_324 == V_325 ) {
V_10 -> V_354 ( V_5 , 0xffffff , V_472 ) ;
} else {
V_10 -> V_354 ( V_5 , 0 , V_472 ) ;
}
V_10 -> V_14 ( V_5 , V_473 , V_448 ) ;
V_10 -> V_469 &= ~ V_474 ;
V_10 -> V_14 ( V_5 , V_10 -> V_469 , V_471 ) ;
switch ( V_168 -> V_324 ) {
case V_323 :
if ( V_56 . V_57 & V_58 ) {
V_10 -> V_354 ( V_5 , V_168 -> V_334 - 1 ,
V_475 ) ;
V_10 -> V_14 ( V_5 , V_476 ,
V_448 ) ;
} else {
V_10 -> V_354 ( V_5 , V_168 -> V_334 ,
V_475 ) ;
V_10 -> V_14 ( V_5 , V_476 ,
V_448 ) ;
V_10 -> V_354 ( V_5 , V_168 -> V_334 - 1 ,
V_475 ) ;
}
break;
case V_325 :
V_10 -> V_354 ( V_5 , 0xffffff , V_475 ) ;
V_10 -> V_14 ( V_5 , V_476 , V_448 ) ;
V_10 -> V_354 ( V_5 , 0xffffff , V_475 ) ;
break;
default:
V_10 -> V_354 ( V_5 , 0 , V_475 ) ;
V_10 -> V_14 ( V_5 , V_476 , V_448 ) ;
V_10 -> V_354 ( V_5 , V_168 -> V_334 , V_475 ) ;
}
V_10 -> V_459 &=
~ ( F_151 ( 0x1f ) | V_477 |
F_152 ( 0x1f ) | V_478 ) ;
switch ( V_168 -> V_319 ) {
case V_320 :
V_10 -> V_449 &= ~ V_479 ;
V_452 =
F_119 ( V_5 , V_168 -> V_330 ,
V_305 ) ;
V_10 -> V_354 ( V_5 , 1 , V_480 ) ;
V_10 -> V_14 ( V_5 , V_481 , V_448 ) ;
V_10 -> V_354 ( V_5 , V_452 , V_480 ) ;
break;
case V_318 :
V_10 -> V_459 |=
F_152 ( V_168 -> V_330 ) ;
if ( V_168 -> V_330 & V_328 )
V_10 -> V_459 |= V_478 ;
V_10 -> V_449 |= V_479 ;
break;
default:
F_2 () ;
break;
}
V_10 -> V_14 ( V_5 , V_10 -> V_449 , V_451 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_459 , V_462 ) ;
V_10 -> V_469 &=
~ ( F_153 ( 3 ) | V_482 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_469 , V_471 ) ;
if ( V_168 -> V_332 > 1 ) {
V_10 -> V_459 |= V_483 ;
V_10 -> V_14 ( V_5 ,
F_154 ( V_168 -> V_332 -
1 ) |
F_155
( V_484 ) ,
V_485 ) ;
} else {
unsigned V_69 ;
V_10 -> V_459 &= ~ V_483 ;
V_69 = F_155 ( V_484 ) ;
if ( V_56 .
V_57 & ( V_58 | V_175 ) ) {
V_69 |= F_154 ( 0 ) ;
} else {
V_69 |=
F_154 ( F_111 ( V_168 -> V_174 [ 0 ] ) ) ;
}
V_10 -> V_14 ( V_5 , V_69 , V_485 ) ;
}
V_10 -> V_14 ( V_5 , V_10 -> V_459 , V_462 ) ;
V_10 -> V_14 ( V_5 , V_447 | V_446 ,
V_448 ) ;
V_10 -> V_437 |= V_486 ;
V_10 -> V_14 ( V_5 , V_10 -> V_437 , V_439 ) ;
V_10 -> V_469 &= ~ V_487 ;
#ifdef F_24
V_10 -> V_469 |= V_488 ;
#else
V_10 -> V_469 |= V_489 ;
#endif
V_10 -> V_469 &= ~ V_490 ;
V_10 -> V_14 ( V_5 , V_10 -> V_469 , V_471 ) ;
V_69 = V_491 | V_492 |
V_493 ;
if ( V_56 . V_180 )
V_69 |= V_494 ;
else
V_69 |= V_495 ;
#if 0
if (boardtype.reg_type & ni_reg_m_series_mask)
bits |= AO_Number_Of_DAC_Packages;
#endif
V_10 -> V_14 ( V_5 , V_69 , V_496 ) ;
V_10 -> V_14 ( V_5 , V_497 , V_498 ) ;
V_10 -> V_14 ( V_5 , V_499 , V_209 ) ;
if ( V_168 -> V_324 == V_323 ) {
V_10 -> V_14 ( V_5 , V_144 ,
V_157 ) ;
F_42 ( V_5 , V_15 ,
V_500 , 1 ) ;
}
V_97 -> V_100 -> V_386 = & F_148 ;
return 0 ;
}
static int F_156 ( struct V_4 * V_5 , struct V_96 * V_97 ,
struct V_167 * V_168 )
{
int V_172 = 0 ;
int V_312 ;
if ( ( V_168 -> V_9 & V_314 ) == 0 ) {
V_168 -> V_9 |= V_314 ;
}
V_312 = V_168 -> V_315 ;
V_168 -> V_315 &= V_317 | V_318 ;
if ( ! V_168 -> V_315 || V_312 != V_168 -> V_315 )
V_172 ++ ;
V_312 = V_168 -> V_319 ;
V_168 -> V_319 &= V_320 | V_318 ;
if ( ! V_168 -> V_319 || V_312 != V_168 -> V_319 )
V_172 ++ ;
V_312 = V_168 -> V_321 ;
V_168 -> V_321 &= V_316 ;
if ( ! V_168 -> V_321 || V_312 != V_168 -> V_321 )
V_172 ++ ;
V_312 = V_168 -> V_322 ;
V_168 -> V_322 &= V_323 ;
if ( ! V_168 -> V_322 || V_312 != V_168 -> V_322 )
V_172 ++ ;
V_312 = V_168 -> V_324 ;
V_168 -> V_324 &= V_323 | V_325 ;
if ( ! V_168 -> V_324 || V_312 != V_168 -> V_324 )
V_172 ++ ;
if ( V_172 )
return 1 ;
if ( V_168 -> V_324 != V_323 && V_168 -> V_324 != V_325 )
V_172 ++ ;
if ( V_172 )
return 2 ;
if ( V_168 -> V_315 == V_318 ) {
unsigned int V_312 = F_111 ( V_168 -> V_327 ) ;
if ( V_312 > 18 )
V_312 = 18 ;
V_312 |= ( V_168 -> V_327 & ( V_328 | V_329 ) ) ;
if ( V_168 -> V_327 != V_312 ) {
V_168 -> V_327 = V_312 ;
V_172 ++ ;
}
} else {
if ( V_168 -> V_327 != 0 ) {
V_168 -> V_327 = 0 ;
V_172 ++ ;
}
}
if ( V_168 -> V_319 == V_320 ) {
if ( V_168 -> V_330 < V_56 . V_501 ) {
V_168 -> V_330 = V_56 . V_501 ;
V_172 ++ ;
}
if ( V_168 -> V_330 > V_10 -> V_306 * 0xffffff ) {
V_168 -> V_330 = V_10 -> V_306 * 0xffffff ;
V_172 ++ ;
}
}
if ( V_168 -> V_331 != 0 ) {
V_168 -> V_331 = 0 ;
V_172 ++ ;
}
if ( V_168 -> V_332 != V_168 -> V_179 ) {
V_168 -> V_332 = V_168 -> V_179 ;
V_172 ++ ;
}
if ( V_168 -> V_324 == V_323 ) {
if ( V_168 -> V_334 > 0x00ffffff ) {
V_168 -> V_334 = 0x00ffffff ;
V_172 ++ ;
}
} else {
if ( V_168 -> V_334 != 0 ) {
V_168 -> V_334 = 0 ;
V_172 ++ ;
}
}
if ( V_172 )
return 3 ;
if ( V_168 -> V_319 == V_320 ) {
V_312 = V_168 -> V_330 ;
V_168 -> V_330 =
F_120 ( V_5 , F_119 ( V_5 ,
V_168 -> V_330 ,
V_168 ->
V_9 &
V_335 ) ) ;
if ( V_312 != V_168 -> V_330 )
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
V_10 -> V_14 ( V_5 , V_453 , V_209 ) ;
V_10 -> V_14 ( V_5 , V_454 , V_448 ) ;
F_42 ( V_5 , V_15 , ~ 0 , 0 ) ;
V_10 -> V_14 ( V_5 , V_491 , V_496 ) ;
V_10 -> V_14 ( V_5 , 0x3f98 , V_157 ) ;
V_10 -> V_14 ( V_5 , V_491 | V_492 |
V_493 , V_496 ) ;
V_10 -> V_14 ( V_5 , 0 , V_485 ) ;
V_10 -> V_14 ( V_5 , 0 , V_498 ) ;
V_10 -> V_442 = 0 ;
V_10 -> V_14 ( V_5 , V_10 -> V_442 , V_448 ) ;
V_10 -> V_449 = 0 ;
V_10 -> V_14 ( V_5 , V_10 -> V_449 , V_451 ) ;
V_10 -> V_459 = 0 ;
V_10 -> V_14 ( V_5 , V_10 -> V_459 , V_462 ) ;
V_10 -> V_469 = 0 ;
V_10 -> V_14 ( V_5 , V_10 -> V_469 , V_471 ) ;
if ( V_56 . V_57 & V_58 )
V_10 -> V_437 = V_502 ;
else
V_10 -> V_437 = 0 ;
V_10 -> V_14 ( V_5 , V_10 -> V_437 , V_439 ) ;
V_10 -> V_463 = 0 ;
V_10 -> V_14 ( V_5 , V_10 -> V_463 ,
V_467 ) ;
if ( V_56 . V_57 & V_175 ) {
unsigned V_503 = 0 ;
unsigned V_103 ;
for ( V_103 = 0 ; V_103 < V_97 -> V_253 ; ++ V_103 ) {
V_503 |= 1 << V_103 ;
}
F_145 ( V_503 , V_433 ) ;
F_145 ( V_455 , V_456 ) ;
}
V_10 -> V_14 ( V_5 , V_499 , V_209 ) ;
return 0 ;
}
static int F_157 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
#ifdef F_158
F_6 ( L_38 ,
F_111 ( V_243 -> V_247 ) , V_68 [ 0 ] ) ;
#endif
switch ( V_68 [ 0 ] ) {
case V_504 :
V_97 -> V_505 |= 1 << F_111 ( V_243 -> V_247 ) ;
break;
case V_506 :
V_97 -> V_505 &= ~ ( 1 << F_111 ( V_243 -> V_247 ) ) ;
break;
case V_507 :
V_68 [ 1 ] =
( V_97 ->
V_505 & ( 1 << F_111 ( V_243 -> V_247 ) ) ) ? V_45 :
V_42 ;
return V_243 -> V_165 ;
break;
default:
return - V_389 ;
}
V_10 -> V_508 &= ~ V_509 ;
V_10 -> V_508 |= F_159 ( V_97 -> V_505 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_508 , V_510 ) ;
return 1 ;
}
static int F_160 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
#ifdef F_158
F_6 ( L_39 , V_68 [ 0 ] , V_68 [ 1 ] ) ;
#endif
if ( V_243 -> V_165 != 2 )
return - V_389 ;
if ( V_68 [ 0 ] ) {
if ( ( V_68 [ 0 ] & ( V_511 | V_512 ) )
&& V_10 -> V_513 )
return - V_40 ;
V_97 -> V_514 &= ~ V_68 [ 0 ] ;
V_97 -> V_514 |= ( V_68 [ 0 ] & V_68 [ 1 ] ) ;
V_10 -> V_515 &= ~ V_516 ;
V_10 -> V_515 |= F_161 ( V_97 -> V_514 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_515 ,
V_517 ) ;
}
V_68 [ 1 ] = V_10 -> V_70 ( V_5 , V_518 ) ;
return 2 ;
}
static int F_162 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 ,
unsigned int * V_68 )
{
#ifdef F_158
F_6 ( L_40 ,
F_111 ( V_243 -> V_247 ) , V_68 [ 0 ] ) ;
#endif
switch ( V_68 [ 0 ] ) {
case V_504 :
V_97 -> V_505 |= 1 << F_111 ( V_243 -> V_247 ) ;
break;
case V_506 :
V_97 -> V_505 &= ~ ( 1 << F_111 ( V_243 -> V_247 ) ) ;
break;
case V_507 :
V_68 [ 1 ] =
( V_97 ->
V_505 & ( 1 << F_111 ( V_243 -> V_247 ) ) ) ? V_45 :
V_42 ;
return V_243 -> V_165 ;
break;
default:
return - V_389 ;
}
F_32 ( V_97 -> V_505 , V_519 ) ;
return 1 ;
}
static int F_163 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 ,
unsigned int * V_68 )
{
#ifdef F_158
F_6 ( L_41 , V_68 [ 0 ] ,
V_68 [ 1 ] ) ;
#endif
if ( V_243 -> V_165 != 2 )
return - V_389 ;
if ( V_68 [ 0 ] ) {
V_97 -> V_514 &= ~ V_68 [ 0 ] ;
V_97 -> V_514 |= ( V_68 [ 0 ] & V_68 [ 1 ] ) ;
F_32 ( V_97 -> V_514 , V_520 ) ;
}
V_68 [ 1 ] = F_33 ( V_521 ) ;
return 2 ;
}
static int F_164 ( struct V_4 * V_5 ,
struct V_96 * V_97 , struct V_167 * V_168 )
{
int V_172 = 0 ;
int V_312 ;
int V_313 ;
unsigned V_103 ;
V_312 = V_168 -> V_315 ;
V_313 = V_317 ;
V_168 -> V_315 &= V_313 ;
if ( ! V_168 -> V_315 || V_312 != V_168 -> V_315 )
V_172 ++ ;
V_312 = V_168 -> V_319 ;
V_168 -> V_319 &= V_318 ;
if ( ! V_168 -> V_319 || V_312 != V_168 -> V_319 )
V_172 ++ ;
V_312 = V_168 -> V_321 ;
V_168 -> V_321 &= V_316 ;
if ( ! V_168 -> V_321 || V_312 != V_168 -> V_321 )
V_172 ++ ;
V_312 = V_168 -> V_322 ;
V_168 -> V_322 &= V_323 ;
if ( ! V_168 -> V_322 || V_312 != V_168 -> V_322 )
V_172 ++ ;
V_312 = V_168 -> V_324 ;
V_168 -> V_324 &= V_325 ;
if ( ! V_168 -> V_324 || V_312 != V_168 -> V_324 )
V_172 ++ ;
if ( V_172 )
return 1 ;
if ( V_168 -> V_315 != V_317 )
V_172 ++ ;
if ( V_168 -> V_319 != V_318 )
V_172 ++ ;
if ( V_168 -> V_321 != V_316 )
V_172 ++ ;
if ( V_168 -> V_324 != V_325 )
V_172 ++ ;
if ( V_172 )
return 2 ;
if ( V_168 -> V_315 == V_317 ) {
if ( V_168 -> V_327 != 0 ) {
V_168 -> V_327 = 0 ;
V_172 ++ ;
}
}
if ( V_168 -> V_319 == V_318 ) {
V_312 = V_168 -> V_330 ;
V_312 &= F_165 ( V_522 , 0 , 0 ,
V_328 ) ;
if ( V_312 != V_168 -> V_330 ) {
V_172 ++ ;
}
}
if ( V_168 -> V_321 == V_316 ) {
if ( V_168 -> V_331 ) {
V_168 -> V_331 = 0 ;
V_172 ++ ;
}
}
if ( V_168 -> V_332 != V_168 -> V_179 ) {
V_168 -> V_332 = V_168 -> V_179 ;
V_172 ++ ;
}
if ( V_168 -> V_324 == V_325 ) {
if ( V_168 -> V_334 != 0 ) {
V_168 -> V_334 = 0 ;
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
static int F_166 ( struct V_4 * V_5 , struct V_96 * V_97 )
{
const struct V_167 * V_168 = & V_97 -> V_100 -> V_168 ;
unsigned V_523 = V_524 | V_525 ;
int V_191 ;
F_32 ( V_526 , V_527 ) ;
switch ( V_168 -> V_319 ) {
case V_318 :
V_523 |=
F_111 ( V_168 -> V_330 ) &
V_522 ;
break;
default:
F_2 () ;
break;
}
if ( V_168 -> V_330 & V_328 )
V_523 |= V_528 ;
F_32 ( V_523 , V_529 ) ;
if ( V_97 -> V_505 ) {
F_32 ( V_97 -> V_514 , V_530 ) ;
F_32 ( V_531 , V_527 ) ;
F_32 ( V_97 -> V_505 , V_532 ) ;
} else {
F_19 ( V_5 ,
L_42 ) ;
return - V_204 ;
}
V_191 = F_23 ( V_5 ) ;
if ( V_191 < 0 ) {
return V_191 ;
}
V_97 -> V_100 -> V_386 = & V_533 ;
return 0 ;
}
static int V_533 ( struct V_4 * V_5 , struct V_96 * V_97 ,
unsigned int V_388 )
{
#ifdef F_24
unsigned long V_9 ;
#endif
int V_191 = 0 ;
unsigned V_103 ;
const unsigned V_102 = 1000 ;
V_97 -> V_100 -> V_386 = NULL ;
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
if ( F_33 ( V_534 ) & V_535 )
break;
F_59 ( 10 ) ;
}
if ( V_103 == V_102 ) {
F_19 ( V_5 , L_44 ) ;
F_70 ( V_5 , V_97 ) ;
return - V_204 ;
}
F_32 ( V_536 | V_537 |
V_538 ,
V_527 ) ;
return V_191 ;
}
static int F_70 ( struct V_4 * V_5 , struct V_96 * V_97 )
{
F_32 ( V_539 | V_540 |
V_541 |
V_542 ,
V_527 ) ;
F_32 ( 0 , V_532 ) ;
F_29 ( V_5 ) ;
return 0 ;
}
static void F_53 ( struct V_4 * V_5 )
{
unsigned V_543 ;
struct V_96 * V_97 = V_5 -> V_98 + V_115 ;
#ifdef F_24
unsigned long V_9 ;
#endif
if ( ( V_56 . V_57 & V_58 ) == 0 ) {
return;
}
#ifdef F_24
F_4 ( & V_10 -> V_36 , V_9 ) ;
if ( V_10 -> V_53 ) {
unsigned V_544 =
F_45 ( V_10 -> V_53 ) ;
if ( V_544 & V_89 ) {
F_46 ( V_90 ,
V_10 -> V_38 -> V_91 +
F_47 ( V_10 -> V_53 -> V_24 ) ) ;
}
F_57 ( V_10 -> V_53 , V_97 -> V_100 ) ;
}
F_8 ( & V_10 -> V_36 , V_9 ) ;
#endif
V_543 = F_33 ( V_534 ) ;
if ( V_543 & ( V_545 | V_546 ) ) {
F_32 ( V_547 , V_527 ) ;
V_97 -> V_100 -> V_108 |= V_114 ;
}
if ( V_543 & V_548 ) {
F_32 ( V_541 ,
V_527 ) ;
}
F_66 ( V_5 , V_97 ) ;
}
static int F_167 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
int V_172 = V_243 -> V_165 ;
unsigned char V_549 , V_550 = 0 ;
if ( V_243 -> V_165 != 2 )
return - V_389 ;
switch ( V_68 [ 0 ] ) {
case V_551 :
#ifdef F_158
F_6 ( L_45 , V_68 [ 1 ] ) ;
#endif
V_10 -> V_552 = 1 ;
V_10 -> V_508 |= V_553 ;
if ( V_68 [ 1 ] == V_554 ) {
V_10 -> V_552 = 0 ;
V_10 -> V_508 &= ~ ( V_553 |
V_555 ) ;
V_68 [ 1 ] = V_554 ;
V_10 -> V_513 = V_68 [ 1 ] ;
} else if ( V_68 [ 1 ] <= V_556 ) {
V_10 -> V_508 &= ~ V_557 ;
V_10 -> V_558 |= V_559 ;
V_10 -> V_558 &= ~ V_560 ;
V_68 [ 1 ] = V_556 ;
V_10 -> V_513 = V_68 [ 1 ] ;
} else if ( V_68 [ 1 ] <= V_561 ) {
V_10 -> V_508 &= ~ V_557 ;
V_10 -> V_558 |= V_559 |
V_560 ;
V_68 [ 1 ] = V_561 ;
V_10 -> V_513 = V_68 [ 1 ] ;
} else if ( V_68 [ 1 ] <= V_562 ) {
V_10 -> V_508 |= V_557 ;
V_10 -> V_558 |= V_559 |
V_560 ;
V_68 [ 1 ] = V_562 ;
V_10 -> V_513 = V_68 [ 1 ] ;
} else {
V_10 -> V_508 &= ~ ( V_553 |
V_555 ) ;
V_10 -> V_552 = 0 ;
V_68 [ 1 ] = ( V_68 [ 1 ] / 1000 ) * 1000 ;
V_10 -> V_513 = V_68 [ 1 ] ;
}
V_10 -> V_14 ( V_5 , V_10 -> V_508 ,
V_510 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_558 ,
V_563 ) ;
return 1 ;
break;
case V_564 :
if ( V_10 -> V_513 == 0 ) {
return - V_389 ;
}
V_549 = V_68 [ 1 ] & 0xFF ;
if ( V_10 -> V_552 ) {
V_172 = F_168 ( V_5 , V_97 , V_549 ,
& V_550 ) ;
} else if ( V_10 -> V_513 > 0 ) {
V_172 = F_169 ( V_5 , V_97 , V_549 ,
& V_550 ) ;
} else {
F_6 ( L_46 ) ;
return - V_389 ;
}
if ( V_172 < 0 )
return V_172 ;
V_68 [ 1 ] = V_550 & 0xFF ;
return V_243 -> V_165 ;
break;
default:
return - V_389 ;
}
}
static int F_168 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
unsigned char V_565 ,
unsigned char * V_566 )
{
unsigned int V_567 ;
int V_172 = 0 , V_239 = 20 ;
#ifdef F_158
F_6 ( L_47 , V_565 ) ;
#endif
V_10 -> V_515 &= ~ V_568 ;
V_10 -> V_515 |= F_170 ( V_565 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_515 , V_517 ) ;
V_567 = V_10 -> V_70 ( V_5 , V_569 ) ;
if ( V_567 & V_570 ) {
V_172 = - V_40 ;
goto Error;
}
V_10 -> V_508 |= V_571 ;
V_10 -> V_14 ( V_5 , V_10 -> V_508 , V_510 ) ;
V_10 -> V_508 &= ~ V_571 ;
while ( ( V_567 =
V_10 -> V_70 ( V_5 ,
V_569 ) ) &
V_570 ) {
F_59 ( ( V_10 -> V_513 + 999 ) / 1000 ) ;
if ( -- V_239 < 0 ) {
F_6
( L_48 ) ;
V_172 = - V_251 ;
goto Error;
}
}
F_59 ( ( V_10 -> V_513 + 999 ) / 1000 ) ;
if ( V_566 != NULL ) {
* V_566 = V_10 -> V_70 ( V_5 , V_572 ) ;
#ifdef F_158
F_6 ( L_49 , * V_566 ) ;
#endif
}
Error:
V_10 -> V_14 ( V_5 , V_10 -> V_508 , V_510 ) ;
return V_172 ;
}
static int F_169 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
unsigned char V_565 ,
unsigned char * V_566 )
{
unsigned char V_244 , V_573 = 0 ;
#ifdef F_158
F_6 ( L_50 , V_565 ) ;
#endif
F_59 ( ( V_10 -> V_513 + 999 ) / 1000 ) ;
for ( V_244 = 0x80 ; V_244 ; V_244 >>= 1 ) {
V_10 -> V_515 &= ~ V_512 ;
if ( V_565 & V_244 ) {
V_10 -> V_515 |= V_512 ;
}
V_10 -> V_14 ( V_5 , V_10 -> V_515 ,
V_517 ) ;
V_10 -> V_508 |= V_555 ;
V_10 -> V_14 ( V_5 , V_10 -> V_508 ,
V_510 ) ;
F_59 ( ( V_10 -> V_513 + 999 ) / 2000 ) ;
V_10 -> V_508 &= ~ V_555 ;
V_10 -> V_14 ( V_5 , V_10 -> V_508 ,
V_510 ) ;
F_59 ( ( V_10 -> V_513 + 999 ) / 2000 ) ;
if ( V_10 -> V_70 ( V_5 ,
V_518 ) & V_511 )
{
V_573 |= V_244 ;
}
}
#ifdef F_158
F_6 ( L_51 , V_573 ) ;
#endif
if ( V_566 )
* V_566 = V_573 ;
return 0 ;
}
static void F_171 ( struct V_4 * V_5 )
{
if ( V_5 -> V_574 ) {
if ( V_10 -> V_50 ) {
F_172 ( V_10 -> V_50 ) ;
}
}
if ( V_5 -> V_98 && V_56 . V_575 )
F_173 ( V_5 , V_5 -> V_98 + V_576 ) ;
}
static void F_174 ( struct V_4 * V_5 , struct V_96 * V_97 )
{
int V_103 ;
for ( V_103 = 0 ; V_103 < V_97 -> V_253 ; V_103 ++ ) {
F_37 ( V_5 , F_139 ( V_103 ) | 0x0 ,
V_577 ) ;
}
F_145 ( 0x0 , V_578 ) ;
}
static unsigned F_175 ( enum V_579 V_6 )
{
unsigned V_580 ;
switch ( V_6 ) {
case V_581 :
V_580 = F_176 ( 0 ) ;
break;
case V_582 :
V_580 = F_176 ( 1 ) ;
break;
case V_583 :
V_580 = F_177 ( 0 ) ;
break;
case V_584 :
V_580 = F_177 ( 1 ) ;
break;
case V_585 :
V_580 = F_178 ( 0 ) ;
break;
case V_586 :
V_580 = F_178 ( 1 ) ;
break;
case V_587 :
V_580 = F_179 ( 0 ) ;
break;
case V_588 :
V_580 = F_179 ( 1 ) ;
break;
case V_589 :
V_580 = F_180 ( 0 ) ;
break;
case V_590 :
V_580 = F_180 ( 1 ) ;
break;
case V_591 :
V_580 = F_181 ( 0 ) ;
break;
case V_592 :
V_580 = F_181 ( 1 ) ;
break;
case V_593 :
V_580 = F_182 ( 0 ) ;
break;
case V_594 :
V_580 = F_182 ( 1 ) ;
break;
case V_595 :
V_580 = F_183 ( 0 ) ;
break;
case V_596 :
V_580 = F_183 ( 1 ) ;
break;
case V_597 :
V_580 = V_598 ;
break;
case V_599 :
V_580 = V_209 ;
break;
case V_600 :
V_580 = V_569 ;
break;
case V_601 :
V_580 = V_440 ;
break;
case V_602 :
V_580 = V_125 ;
break;
case V_603 :
V_580 = V_157 ;
break;
case V_604 :
V_580 = V_86 ;
break;
case V_605 :
V_580 = V_87 ;
break;
case V_606 :
V_580 = V_12 ;
break;
case V_607 :
V_580 = V_15 ;
break;
default:
F_6 ( L_52 ,
V_23 , V_6 ) ;
F_2 () ;
return 0 ;
break;
}
return V_580 ;
}
static void F_184 ( struct V_608 * V_609 , unsigned V_69 ,
enum V_579 V_6 )
{
struct V_4 * V_5 = V_609 -> V_50 -> V_5 ;
unsigned V_580 ;
static const unsigned V_610 = V_611 | V_612 ;
static const unsigned V_613 =
V_614 | V_615 ;
static const unsigned V_616 =
V_617 | V_618 ;
switch ( V_6 ) {
case V_619 :
F_38 ( V_69 , V_620 ) ;
break;
case V_621 :
F_38 ( V_69 , V_622 ) ;
break;
case V_623 :
F_38 ( V_69 , V_624 ) ;
break;
case V_625 :
F_38 ( V_69 , V_626 ) ;
break;
case V_627 :
F_38 ( V_69 , V_628 ) ;
break;
case V_629 :
F_38 ( V_69 , V_630 ) ;
break;
case V_631 :
F_38 ( V_69 , V_632 ) ;
break;
case V_633 :
F_38 ( V_69 , V_634 ) ;
break;
case V_591 :
case V_592 :
case V_593 :
case V_594 :
V_580 = F_175 ( V_6 ) ;
V_10 -> V_354 ( V_5 , V_69 , V_580 ) ;
break;
case V_606 :
F_17 ( V_69 & ~ V_613 ) ;
F_3 ( V_5 , V_12 ,
V_613 , V_69 ) ;
break;
case V_607 :
F_17 ( V_69 & ~ V_616 ) ;
F_3 ( V_5 , V_15 ,
V_616 , V_69 ) ;
break;
case V_599 :
F_17 ( V_69 & ~ V_610 ) ;
default:
V_580 = F_175 ( V_6 ) ;
V_10 -> V_14 ( V_5 , V_69 , V_580 ) ;
}
}
static unsigned F_185 ( struct V_608 * V_609 ,
enum V_579 V_6 )
{
struct V_4 * V_5 = V_609 -> V_50 -> V_5 ;
unsigned V_580 ;
switch ( V_6 ) {
case V_635 :
return F_41 ( V_636 ) ;
break;
case V_637 :
return F_41 ( V_638 ) ;
break;
case V_585 :
case V_586 :
case V_587 :
case V_588 :
V_580 = F_175 ( V_6 ) ;
return V_10 -> V_639 ( V_5 , V_580 ) ;
break;
default:
V_580 = F_175 ( V_6 ) ;
return V_10 -> V_70 ( V_5 , V_580 ) ;
break;
}
return 0 ;
}
static int F_186 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
V_68 [ 0 ] = V_10 -> V_558 & V_640 ;
return 1 ;
}
static int F_187 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
V_10 -> V_558 &= ~ V_641 ;
V_10 -> V_14 ( V_5 , V_10 -> V_558 ,
V_563 ) ;
V_10 -> V_558 &= ~ V_640 ;
V_10 -> V_558 |= F_188 ( V_68 [ 0 ] ) ;
V_10 -> V_558 |= V_641 ;
V_10 -> V_14 ( V_5 , V_10 -> V_558 ,
V_563 ) ;
return V_243 -> V_165 ;
}
static int F_189 ( struct V_4 * V_5 ,
unsigned int V_642 )
{
switch ( V_642 ) {
case V_643 :
V_10 -> V_558 &= ~ V_644 ;
break;
case V_645 :
V_10 -> V_558 |= V_644 ;
break;
default:
return - V_389 ;
}
V_10 -> V_14 ( V_5 , V_10 -> V_558 ,
V_563 ) ;
return 3 ;
}
static void F_190 ( struct V_4 * V_5 ,
unsigned int * V_642 ,
unsigned int * V_646 )
{
if ( V_10 -> V_558 & V_644 ) {
* V_642 = V_645 ;
* V_646 = V_647 ;
} else {
* V_642 = V_643 ;
* V_646 = V_648 * 2 ;
}
}
static int F_191 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
switch ( V_68 [ 0 ] ) {
case V_649 :
return F_189 ( V_5 , V_68 [ 1 ] ) ;
break;
case V_650 :
F_190 ( V_5 , & V_68 [ 1 ] , & V_68 [ 2 ] ) ;
return 3 ;
default:
break;
}
return - V_389 ;
}
static int F_192 ( struct V_4 * V_5 )
{
int V_160 ;
V_160 = F_193 ( V_5 , sizeof( struct V_651 ) ) ;
if ( V_160 < 0 )
return V_160 ;
F_194 ( & V_10 -> V_72 ) ;
F_194 ( & V_10 -> V_11 ) ;
F_194 ( & V_10 -> V_36 ) ;
return 0 ;
}
static int F_195 ( int V_41 , int V_652 , int V_68 , unsigned long V_653 )
{
struct V_4 * V_5 = (struct V_4 * ) V_653 ;
if ( V_41 ) {
F_5 ( V_68 , V_654 + 2 * V_652 ) ;
return 0 ;
} else {
return F_89 ( V_654 + 2 * V_652 ) ;
}
}
static int F_196 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
V_68 [ 0 ] = F_197 ( V_5 , F_111 ( V_243 -> V_247 ) ) ;
return 1 ;
}
static int F_197 ( struct V_4 * V_5 , int V_71 )
{
int V_655 ;
int V_656 ;
V_656 = 0x0300 | ( ( V_71 & 0x100 ) << 3 ) | ( V_71 & 0xff ) ;
F_5 ( 0x04 , V_657 ) ;
for ( V_655 = 0x8000 ; V_655 ; V_655 >>= 1 ) {
F_5 ( 0x04 | ( ( V_655 & V_656 ) ? 0x02 : 0 ) ,
V_657 ) ;
F_5 ( 0x05 | ( ( V_655 & V_656 ) ? 0x02 : 0 ) ,
V_657 ) ;
}
V_656 = 0 ;
for ( V_655 = 0x80 ; V_655 ; V_655 >>= 1 ) {
F_5 ( 0x04 , V_657 ) ;
F_5 ( 0x05 , V_657 ) ;
V_656 |= ( ( F_89 ( V_194 ) & V_658 ) ? V_655 : 0 ) ;
}
F_5 ( 0x00 , V_657 ) ;
return V_656 ;
}
static int F_198 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 ,
unsigned int * V_68 )
{
V_68 [ 0 ] = V_10 -> V_659 [ F_111 ( V_243 -> V_247 ) ] ;
return 1 ;
}
static int F_199 ( struct V_4 * V_5 , unsigned int * V_68 )
{
V_68 [ 1 ] = V_10 -> V_660 * V_10 -> V_306 ;
V_68 [ 2 ] = V_10 -> V_661 * V_10 -> V_306 ;
return 3 ;
}
static int F_200 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
unsigned V_662 , V_663 ;
switch ( V_68 [ 0 ] ) {
case V_664 :
switch ( V_68 [ 1 ] ) {
case V_305 :
V_662 =
( V_68 [ 2 ] +
V_10 -> V_306 / 2 ) / V_10 -> V_306 ;
break;
case V_307 :
V_662 = V_68 [ 2 ] / V_10 -> V_306 ;
break;
case V_308 :
V_662 =
( V_68 [ 2 ] + V_10 -> V_306 -
1 ) / V_10 -> V_306 ;
break;
default:
return - V_389 ;
break;
}
switch ( V_68 [ 3 ] ) {
case V_305 :
V_663 =
( V_68 [ 4 ] +
V_10 -> V_306 / 2 ) / V_10 -> V_306 ;
break;
case V_307 :
V_663 = V_68 [ 4 ] / V_10 -> V_306 ;
break;
case V_308 :
V_663 =
( V_68 [ 4 ] + V_10 -> V_306 -
1 ) / V_10 -> V_306 ;
break;
default:
return - V_389 ;
break;
}
if ( V_662 * V_10 -> V_306 != V_68 [ 2 ] ||
V_663 * V_10 -> V_306 != V_68 [ 4 ] ) {
V_68 [ 2 ] = V_662 * V_10 -> V_306 ;
V_68 [ 4 ] = V_663 * V_10 -> V_306 ;
return - V_404 ;
}
F_32 ( F_201 ( V_662 ) |
F_202 ( V_663 ) ,
V_665 ) ;
V_10 -> V_660 = V_662 ;
V_10 -> V_661 = V_663 ;
return 5 ;
break;
case V_666 :
return F_199 ( V_5 , V_68 ) ;
break;
default:
return - V_389 ;
break;
}
return 0 ;
}
static int F_203 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
unsigned V_662 , V_663 ;
switch ( V_68 [ 0 ] ) {
case V_664 :
switch ( V_68 [ 1 ] ) {
case V_305 :
V_662 =
( V_68 [ 2 ] +
V_10 -> V_306 / 2 ) / V_10 -> V_306 ;
break;
case V_307 :
V_662 = V_68 [ 2 ] / V_10 -> V_306 ;
break;
case V_308 :
V_662 =
( V_68 [ 2 ] + V_10 -> V_306 -
1 ) / V_10 -> V_306 ;
break;
default:
return - V_389 ;
break;
}
switch ( V_68 [ 3 ] ) {
case V_305 :
V_663 =
( V_68 [ 4 ] +
V_10 -> V_306 / 2 ) / V_10 -> V_306 ;
break;
case V_307 :
V_663 = V_68 [ 4 ] / V_10 -> V_306 ;
break;
case V_308 :
V_663 =
( V_68 [ 4 ] + V_10 -> V_306 -
1 ) / V_10 -> V_306 ;
break;
default:
return - V_389 ;
break;
}
if ( V_662 * V_10 -> V_306 != V_68 [ 2 ] ||
V_663 * V_10 -> V_306 != V_68 [ 4 ] ) {
V_68 [ 2 ] = V_662 * V_10 -> V_306 ;
V_68 [ 4 ] = V_663 * V_10 -> V_306 ;
return - V_404 ;
}
F_32 ( V_662 , V_667 ) ;
V_10 -> V_660 = V_662 ;
F_32 ( V_663 , V_668 ) ;
V_10 -> V_661 = V_663 ;
return 5 ;
break;
case V_666 :
return F_199 ( V_5 , V_68 ) ;
default:
return - V_389 ;
break;
}
return 0 ;
}
static int F_204 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
F_205 ( V_5 , F_111 ( V_243 -> V_247 ) , V_68 [ 0 ] ) ;
return 1 ;
}
static int F_206 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
V_68 [ 0 ] = V_10 -> V_669 [ F_111 ( V_243 -> V_247 ) ] ;
return 1 ;
}
static void F_207 ( struct V_4 * V_5 , struct V_96 * V_97 )
{
int V_103 , V_670 ;
int V_671 ;
int V_407 = 0 ;
int V_672 ;
int V_673 = 0 ;
int type ;
int V_169 ;
type = V_56 . V_674 [ 0 ] ;
if ( type == V_675 )
return;
V_672 = V_669 [ type ] . V_672 ;
for ( V_103 = 0 ; V_103 < 3 ; V_103 ++ ) {
type = V_56 . V_674 [ V_103 ] ;
if ( type == V_675 )
break;
if ( V_669 [ type ] . V_672 != V_672 )
V_673 = 1 ;
V_407 += V_669 [ type ] . V_407 ;
}
V_671 = V_103 ;
V_97 -> V_253 = V_407 ;
if ( V_673 ) {
unsigned int * V_676 ;
if ( V_407 > V_677 ) {
F_6 ( L_53 ) ;
}
V_97 -> V_676 = V_676 = V_10 -> V_678 ;
V_169 = 0 ;
for ( V_103 = 0 ; V_103 < V_671 ; V_103 ++ ) {
type = V_56 . V_674 [ V_103 ] ;
for ( V_670 = 0 ; V_670 < V_669 [ type ] . V_407 ; V_670 ++ ) {
V_676 [ V_169 ] =
( 1 << V_669 [ type ] . V_672 ) - 1 ;
V_169 ++ ;
}
}
for ( V_169 = 0 ; V_169 < V_97 -> V_253 ; V_169 ++ )
F_205 ( V_5 , V_103 , V_97 -> V_676 [ V_103 ] / 2 ) ;
} else {
type = V_56 . V_674 [ 0 ] ;
V_97 -> V_679 = ( 1 << V_669 [ type ] . V_672 ) - 1 ;
for ( V_169 = 0 ; V_169 < V_97 -> V_253 ; V_169 ++ )
F_205 ( V_5 , V_103 , V_97 -> V_679 / 2 ) ;
}
}
static void F_205 ( struct V_4 * V_5 , int V_71 , int V_680 )
{
unsigned int V_681 = 0 , V_69 = 0 , V_655 , V_656 = 0 ;
int V_103 ;
int type ;
if ( V_10 -> V_669 [ V_71 ] == V_680 )
return;
V_10 -> V_669 [ V_71 ] = V_680 ;
for ( V_103 = 0 ; V_103 < 3 ; V_103 ++ ) {
type = V_56 . V_674 [ V_103 ] ;
if ( type == V_675 )
break;
if ( V_71 < V_669 [ type ] . V_407 ) {
V_69 = V_669 [ type ] . F_208 ( V_71 , V_680 , & V_656 ) ;
V_681 = F_209 ( V_103 ) ;
break;
}
V_71 -= V_669 [ type ] . V_407 ;
}
for ( V_655 = 1 << ( V_69 - 1 ) ; V_655 ; V_655 >>= 1 ) {
F_5 ( ( ( V_655 & V_656 ) ? 0x02 : 0 ) , V_657 ) ;
F_59 ( 1 ) ;
F_5 ( 1 | ( ( V_655 & V_656 ) ? 0x02 : 0 ) , V_657 ) ;
F_59 ( 1 ) ;
}
F_5 ( V_681 , V_657 ) ;
F_59 ( 1 ) ;
F_5 ( 0 , V_657 ) ;
}
static int F_210 ( int V_71 , int V_680 , int * V_656 )
{
V_71 ++ ;
* V_656 = ( ( V_71 & 0x1 ) << 11 ) |
( ( V_71 & 0x2 ) << 9 ) |
( ( V_71 & 0x4 ) << 7 ) | ( ( V_71 & 0x8 ) << 5 ) | ( V_680 & 0xff ) ;
return 12 ;
}
static int F_211 ( int V_71 , int V_680 , int * V_656 )
{
* V_656 = ( ( V_71 & 0x7 ) << 8 ) | ( V_680 & 0xff ) ;
return 11 ;
}
static int F_212 ( int V_71 , int V_680 , int * V_656 )
{
* V_656 = V_680 & 0xfff ;
return 12 ;
}
static int F_213 ( int V_71 , int V_680 , int * V_656 )
{
* V_656 = ( V_680 & 0xfff ) | ( V_71 ? 0xc000 : 0xa000 ) ;
return 16 ;
}
static int F_214 ( int V_71 , int V_680 , int * V_656 )
{
* V_656 = ( ( V_71 & 0xf ) << 8 ) | ( V_680 & 0xff ) ;
return 12 ;
}
static int F_215 ( int V_71 , int V_680 , int * V_656 )
{
* V_656 = ( ( V_71 + 1 ) << 8 ) | ( V_680 & 0xff ) ;
return 12 ;
}
static int F_216 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
struct V_608 * V_609 = V_97 -> V_574 ;
return F_217 ( V_609 , V_243 , V_68 ) ;
}
static int F_218 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
struct V_608 * V_609 = V_97 -> V_574 ;
return F_219 ( V_609 , V_243 , V_68 ) ;
}
static int F_220 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
struct V_608 * V_609 = V_97 -> V_574 ;
return F_221 ( V_609 , V_243 , V_68 ) ;
}
static int F_222 ( struct V_4 * V_5 , struct V_96 * V_97 )
{
int V_191 ;
#ifdef F_24
struct V_608 * V_609 = V_97 -> V_574 ;
V_191 = F_21 ( V_5 , V_609 -> V_1 ,
V_42 ) ;
if ( V_191 ) {
F_19 ( V_5 ,
L_54 ) ;
return V_191 ;
}
F_223 ( V_609 , NULL , NULL , NULL , NULL ) ;
F_30 ( V_5 , V_609 -> V_1 , 1 ) ;
V_191 = F_224 ( V_609 , V_97 -> V_100 ) ;
#else
V_191 = - V_682 ;
#endif
return V_191 ;
}
static int F_225 ( struct V_4 * V_5 ,
struct V_96 * V_97 , struct V_167 * V_168 )
{
#ifdef F_24
struct V_608 * V_609 = V_97 -> V_574 ;
return F_226 ( V_609 , V_168 ) ;
#else
return - V_682 ;
#endif
}
static int F_69 ( struct V_4 * V_5 , struct V_96 * V_97 )
{
#ifdef F_24
struct V_608 * V_609 = V_97 -> V_574 ;
int V_191 ;
V_191 = F_227 ( V_609 ) ;
F_30 ( V_5 , V_609 -> V_1 , 0 ) ;
F_28 ( V_5 , V_609 -> V_1 ) ;
return V_191 ;
#else
return 0 ;
#endif
}
static int F_228 ( struct V_4 * V_5 , unsigned V_169 ,
unsigned V_683 )
{
unsigned V_684 ;
unsigned V_685 ;
if ( ( V_683 & 0x1f ) != V_683 )
return - V_389 ;
V_684 = 1 + V_169 / 3 ;
V_685 = V_684 - 1 ;
V_10 -> V_686 [ V_685 ] &=
~ F_229 ( V_169 ) ;
V_10 -> V_686 [ V_685 ] |=
F_230 ( V_169 , V_683 ) ;
F_38 ( V_10 -> V_686 [ V_685 ] ,
F_231 ( V_684 ) ) ;
return 2 ;
}
static int F_232 ( struct V_4 * V_5 , unsigned V_169 ,
unsigned V_683 )
{
if ( V_683 != F_233 ( V_5 , V_169 ) )
return - V_389 ;
return 2 ;
}
static int F_234 ( struct V_4 * V_5 , unsigned V_169 ,
unsigned V_683 )
{
if ( V_56 . V_57 & V_58 )
return F_228 ( V_5 , V_169 , V_683 ) ;
else
return F_232 ( V_5 , V_169 , V_683 ) ;
}
static unsigned F_235 ( struct V_4 * V_5 ,
unsigned V_169 )
{
const unsigned V_685 = V_169 / 3 ;
return F_236 ( V_169 ,
V_10 ->
V_686
[ V_685 ] ) ;
}
static unsigned F_233 ( struct V_4 * V_5 , unsigned V_169 )
{
switch ( V_169 ) {
case 0 :
return V_687 ;
break;
case 1 :
return V_688 ;
break;
case 2 :
return V_689 ;
break;
case 3 :
return V_690 ;
break;
case 4 :
return V_691 ;
break;
case 5 :
return V_692 ;
break;
case 6 :
return V_693 ;
break;
case 7 :
return V_694 ;
break;
case 8 :
return V_695 ;
break;
case 9 :
return V_696 ;
break;
default:
F_6 ( L_55 , V_23 ) ;
break;
}
return 0 ;
}
static unsigned F_237 ( struct V_4 * V_5 , unsigned V_169 )
{
if ( V_56 . V_57 & V_58 )
return F_235 ( V_5 , V_169 ) ;
else
return F_233 ( V_5 , V_169 ) ;
}
static int F_238 ( struct V_4 * V_5 , unsigned V_697 ,
enum V_698 V_699 )
{
unsigned V_69 ;
if ( ( V_56 . V_57 & V_58 ) == 0 ) {
return - V_682 ;
}
V_69 = F_33 ( V_700 ) ;
V_69 &= ~ F_239 ( V_697 ) ;
V_69 |= F_240 ( V_697 , V_699 ) ;
F_32 ( V_69 , V_700 ) ;
return 0 ;
}
static int F_241 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
if ( ( V_56 . V_57 & V_58 ) == 0 ) {
return - V_682 ;
}
if ( V_68 [ 0 ] ) {
V_97 -> V_514 &= ~ V_68 [ 0 ] ;
V_97 -> V_514 |= ( V_68 [ 0 ] & V_68 [ 1 ] ) ;
F_38 ( V_97 -> V_514 , V_701 ) ;
}
V_68 [ 1 ] = F_41 ( V_702 ) ;
return 2 ;
}
static int F_242 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
unsigned int V_169 ;
if ( V_243 -> V_165 < 1 )
return - V_389 ;
V_169 = F_111 ( V_243 -> V_247 ) ;
switch ( V_68 [ 0 ] ) {
case V_45 :
F_42 ( V_5 , V_17 , 1 << V_169 , 1 ) ;
break;
case V_42 :
F_42 ( V_5 , V_17 , 1 << V_169 , 0 ) ;
break;
case V_507 :
V_68 [ 1 ] =
( V_10 -> V_18 & ( 1 << V_169 ) ) ?
V_45 : V_42 ;
return 0 ;
break;
case V_703 :
return F_234 ( V_5 , V_169 , V_68 [ 1 ] ) ;
break;
case V_704 :
V_68 [ 1 ] = F_237 ( V_5 , V_169 ) ;
break;
case V_705 :
return F_238 ( V_5 , V_169 , V_68 [ 1 ] ) ;
break;
default:
return - V_389 ;
}
return 0 ;
}
static void F_243 ( struct V_4 * V_5 )
{
V_10 -> V_706 = V_707 ;
if ( F_244 ( V_5 , V_708 , 0 ) < 0 ) {
F_6 ( L_56 ) ;
}
V_10 -> V_709 =
F_245 ( 0 ,
V_710 ) |
F_245 ( 1 ,
V_711 ) |
F_245 ( 2 ,
V_712 ) |
F_245 ( 3 , V_713 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_709 ,
V_714 ) ;
V_10 -> V_715 =
F_245 ( 4 ,
V_716 ) |
F_245 ( 5 ,
V_717 ) |
F_245 ( 6 , V_718 ) ;
if ( V_56 . V_57 & V_58 )
V_10 -> V_715 |=
F_245 ( 7 , V_719 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_715 ,
V_720 ) ;
}
static int F_246 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
if ( V_243 -> V_165 != 2 )
return - V_389 ;
V_68 [ 1 ] = 0 ;
return 2 ;
}
static int F_247 ( unsigned V_721 ,
unsigned * V_722 ,
unsigned * V_723 ,
unsigned * V_724 )
{
unsigned div ;
unsigned V_725 = 1 ;
static const unsigned V_726 = 0x10 ;
unsigned V_727 ;
unsigned V_728 = 1 ;
static const unsigned V_729 = 0x100 ;
static const unsigned V_730 = 1000 ;
const unsigned V_731 = V_721 * V_730 ;
static const unsigned V_732 = 12500 ;
static const unsigned V_733 = 4 ;
int V_734 = 0 ;
for ( div = 1 ; div <= V_726 ; ++ div ) {
for ( V_727 = 1 ; V_727 <= V_729 ; ++ V_727 ) {
unsigned V_735 =
( V_731 * div ) / V_727 ;
if ( abs ( V_735 - V_732 ) <
abs ( V_734 - V_732 ) ) {
V_734 = V_735 ;
V_725 = div ;
V_728 = V_727 ;
}
}
}
if ( V_734 == 0 ) {
F_6 ( L_57 , V_23 ) ;
return - V_204 ;
}
* V_722 = V_725 ;
* V_723 = V_728 ;
* V_724 =
( V_734 * V_733 +
( V_730 / 2 ) ) / V_730 ;
return 0 ;
}
static inline unsigned F_248 ( struct V_4 * V_5 )
{
if ( V_56 . V_57 & V_58 )
return 8 ;
else
return 7 ;
}
static int F_249 ( struct V_4 * V_5 ,
unsigned V_683 , unsigned V_736 )
{
static const unsigned V_737 = 50 ;
static const unsigned V_738 = 1000 ;
static const unsigned V_102 = 1000 ;
unsigned V_739 ;
unsigned V_722 ;
unsigned V_723 ;
unsigned V_103 ;
int V_191 ;
if ( V_683 == V_740 )
V_736 = 100 ;
if ( V_736 < V_737 || V_736 > V_738 ) {
F_6
( L_58
L_59 , V_23 ,
V_737 , V_738 ) ;
return - V_389 ;
}
V_10 -> V_741 &= ~ V_742 ;
V_10 -> V_14 ( V_5 , V_10 -> V_741 ,
V_743 ) ;
V_739 =
V_744 | V_745 ;
V_10 -> V_706 |=
V_746 | V_747 ;
V_10 -> V_706 &= ~ V_748 ;
switch ( V_683 ) {
case V_749 :
V_10 -> V_706 |=
V_750 ;
V_191 = F_247 ( V_736 , & V_722 ,
& V_723 ,
& V_10 -> V_306 ) ;
if ( V_191 < 0 )
return V_191 ;
break;
case V_740 :
V_10 -> V_706 |=
V_751 ;
V_191 = F_247 ( V_736 , & V_722 ,
& V_723 ,
& V_10 -> V_306 ) ;
if ( V_191 < 0 )
return V_191 ;
break;
default:
{
unsigned V_752 ;
static const unsigned V_753 = 7 ;
for ( V_752 = 0 ; V_752 <= V_753 ;
++ V_752 ) {
if ( V_683 ==
F_250 ( V_752 ) ) {
V_10 -> V_706 |=
F_251
( V_752 ) ;
break;
}
}
if ( V_752 > V_753 )
return - V_389 ;
V_191 = F_247 ( V_736 ,
& V_722 ,
& V_723 ,
& V_10 ->
V_306 ) ;
if ( V_191 < 0 )
return V_191 ;
}
break;
}
F_38 ( V_10 -> V_706 , V_754 ) ;
V_739 |=
F_252 ( V_722 ) |
F_253 ( V_723 ) ;
F_38 ( V_739 , V_755 ) ;
V_10 -> V_642 = V_683 ;
for ( V_103 = 0 ; V_103 < V_102 ; ++ V_103 ) {
if ( F_41 ( V_756 ) & V_757 ) {
break;
}
F_59 ( 1 ) ;
}
if ( V_103 == V_102 ) {
F_6
( L_60 ,
V_23 , V_683 , V_736 ) ;
return - V_758 ;
}
return 3 ;
}
static int F_244 ( struct V_4 * V_5 , unsigned V_683 ,
unsigned V_736 )
{
if ( V_683 == V_708 ) {
V_10 -> V_741 &= ~ V_742 ;
V_10 -> V_14 ( V_5 , V_10 -> V_741 ,
V_743 ) ;
V_10 -> V_306 = V_648 ;
if ( V_56 . V_57 & V_58 ) {
V_10 -> V_706 &=
~ ( V_746 |
V_747 ) ;
F_38 ( V_10 -> V_706 ,
V_754 ) ;
F_38 ( 0 , V_755 ) ;
}
V_10 -> V_642 = V_683 ;
} else {
if ( V_56 . V_57 & V_58 ) {
return F_249 ( V_5 , V_683 ,
V_736 ) ;
} else {
if ( V_683 == V_759 ) {
V_10 -> V_741 |=
V_742 ;
V_10 -> V_14 ( V_5 ,
V_10 ->
V_741 ,
V_743 ) ;
if ( V_736 == 0 ) {
F_6
( L_61 ,
V_23 ) ;
return - V_389 ;
} else {
V_10 -> V_306 = V_736 ;
}
V_10 -> V_642 = V_683 ;
} else
return - V_389 ;
}
}
return 3 ;
}
static int F_254 ( struct V_4 * V_5 , unsigned V_169 ,
unsigned V_683 )
{
if ( V_169 >= F_248 ( V_5 ) ) {
if ( V_169 == V_760 ) {
if ( V_683 == V_719 )
return 1 ;
else {
F_6
( L_62 ,
V_23 , V_169 , V_760 ) ;
return 0 ;
}
}
return 0 ;
}
switch ( V_683 ) {
case V_710 :
case V_711 :
case V_712 :
case V_713 :
case V_716 :
case V_717 :
case V_718 :
case V_761 :
case V_762 :
return 1 ;
break;
case V_719 :
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
static int F_255 ( struct V_4 * V_5 , unsigned V_169 ,
unsigned V_683 )
{
if ( F_254 ( V_5 , V_169 , V_683 ) == 0 )
return - V_389 ;
if ( V_169 < 4 ) {
V_10 -> V_709 &= ~ F_256 ( V_169 ) ;
V_10 -> V_709 |=
F_245 ( V_169 , V_683 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_709 ,
V_714 ) ;
} else if ( V_169 < 8 ) {
V_10 -> V_715 &= ~ F_256 ( V_169 ) ;
V_10 -> V_715 |=
F_245 ( V_169 , V_683 ) ;
V_10 -> V_14 ( V_5 , V_10 -> V_715 ,
V_720 ) ;
}
return 2 ;
}
static unsigned F_257 ( struct V_4 * V_5 , unsigned V_169 )
{
if ( V_169 < 4 ) {
return F_258 ( V_169 ,
V_10 -> V_709 ) ;
} else if ( V_169 < F_248 ( V_5 ) ) {
return F_258 ( V_169 ,
V_10 -> V_715 ) ;
} else {
if ( V_169 == V_760 )
return V_719 ;
F_6 ( L_63 , V_23 ) ;
return 0 ;
}
}
static int F_259 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
unsigned int V_169 = F_111 ( V_243 -> V_247 ) ;
switch ( V_68 [ 0 ] ) {
case V_504 :
if ( V_169 < F_248 ( V_5 ) ) {
V_10 -> V_741 |=
F_260 ( V_169 ,
( V_56 .
V_57 & V_58 ) !=
0 ) ;
} else if ( V_169 == V_760 ) {
V_10 -> V_741 |=
V_763 ;
}
V_10 -> V_14 ( V_5 , V_10 -> V_741 ,
V_743 ) ;
break;
case V_506 :
if ( V_169 < F_248 ( V_5 ) ) {
V_10 -> V_741 &=
~ F_260 ( V_169 ,
( V_56 .
V_57 & V_58 )
!= 0 ) ;
} else if ( V_169 == V_760 ) {
V_10 -> V_741 &=
~ V_763 ;
}
V_10 -> V_14 ( V_5 , V_10 -> V_741 ,
V_743 ) ;
break;
case V_507 :
if ( V_169 < F_248 ( V_5 ) ) {
V_68 [ 1 ] =
( V_10 -> V_741 &
F_260 ( V_169 ,
( V_56 . V_57 &
V_58 )
!= 0 ) ) ? V_504 :
V_506 ;
} else if ( V_169 == V_760 ) {
V_68 [ 1 ] =
( V_10 -> V_741 &
V_763 )
? V_504 : V_506 ;
}
return 2 ;
break;
case V_649 :
return F_244 ( V_5 , V_68 [ 1 ] , V_68 [ 2 ] ) ;
break;
case V_650 :
V_68 [ 1 ] = V_10 -> V_642 ;
V_68 [ 2 ] = V_10 -> V_306 ;
return 3 ;
break;
case V_703 :
return F_255 ( V_5 , V_169 , V_68 [ 1 ] ) ;
break;
case V_704 :
V_68 [ 1 ] = F_257 ( V_5 , V_169 ) ;
return 2 ;
break;
default:
return - V_389 ;
break;
}
return 1 ;
}
static int F_261 ( struct V_4 * V_5 )
{
unsigned short V_126 ;
const int V_102 = V_764 ;
int V_103 ;
for ( V_103 = 0 ; V_103 < V_102 ; V_103 ++ ) {
V_126 = F_40 ( V_5 , V_765 ) ;
if ( ( V_126 & V_766 ) == 0 ) {
break;
}
F_262 ( V_767 ) ;
if ( F_263 ( 1 ) ) {
return - V_204 ;
}
}
if ( V_103 == V_102 ) {
F_6 ( L_64 , __FILE__ , V_23 ) ;
return - V_251 ;
}
return 0 ;
}
static void F_264 ( struct V_4 * V_5 , unsigned short V_75 )
{
static const int V_102 = 100 ;
int V_103 ;
F_37 ( V_5 , V_75 , V_768 ) ;
for ( V_103 = 0 ; V_103 < V_102 ; V_103 ++ ) {
if ( ( F_40 ( V_5 , V_765 ) & V_766 ) )
break;
F_59 ( 1 ) ;
}
if ( V_103 == V_102 ) {
F_19 ( V_5 , L_65 ) ;
}
}
static void F_265 ( struct V_4 * V_5 , unsigned int V_75 ,
unsigned int V_769 )
{
F_37 ( V_5 , ( ( V_75 >> 16 ) & 0xff ) ,
V_770 ) ;
F_37 ( V_5 , ( V_75 & 0xffff ) ,
V_771 ) ;
V_769 &= V_772 ;
F_264 ( V_5 , V_773 | V_769 ) ;
if ( F_261 ( V_5 ) )
F_19 ( V_5 , L_66 ) ;
}
static unsigned int F_266 ( struct V_4 * V_5 ,
unsigned int V_769 )
{
unsigned int V_75 ;
V_769 &= V_772 ;
F_264 ( V_5 , V_773 | V_774 | V_769 ) ;
if ( F_261 ( V_5 ) )
F_19 ( V_5 , L_67 ) ;
V_75 = ( F_40 ( V_5 ,
V_770 ) << 16 ) &
0xff0000 ;
V_75 |= F_40 ( V_5 , V_771 ) & 0xffff ;
return V_75 ;
}
static int F_267 ( struct V_4 * V_5 , unsigned short * V_68 )
{
int V_191 ;
unsigned short V_126 ;
F_264 ( V_5 , V_773 | V_775 ) ;
V_191 = F_261 ( V_5 ) ;
if ( V_191 ) {
F_19 ( V_5 ,
L_68 ) ;
return - V_251 ;
}
V_126 = F_40 ( V_5 , V_765 ) ;
if ( V_126 & V_776 ) {
F_6
( L_69 ) ;
return - V_204 ;
}
if ( V_126 & V_777 ) {
F_6
( L_70 ) ;
}
if ( V_68 ) {
* V_68 = F_40 ( V_5 , V_778 ) ;
* V_68 ^= ( 1 << 15 ) ;
}
return 0 ;
}
static int F_268 ( struct V_4 * V_5 ,
struct V_96 * V_97 ,
struct V_242 * V_243 , unsigned int * V_68 )
{
int V_165 , V_191 ;
unsigned short V_779 ;
unsigned int V_780 ;
const unsigned int V_781 = 0x1000 ;
if ( V_243 -> V_247 & V_260 )
V_780 = V_781 ;
else
V_780 = F_111 ( V_243 -> V_247 ) ;
F_37 ( V_5 , V_780 , V_782 ) ;
for ( V_165 = 0 ; V_165 < V_243 -> V_165 ; V_165 ++ ) {
V_191 = F_267 ( V_5 , & V_779 ) ;
if ( V_191 < 0 )
return V_191 ;
V_68 [ V_165 ] = V_779 ;
}
return V_243 -> V_165 ;
}
static int F_269 ( struct V_4 * V_5 )
{
unsigned int V_274 =
V_783 | V_784 ;
#if 1
F_265 ( V_5 , V_274 | V_785 ,
V_786 ) ;
F_267 ( V_5 , NULL ) ;
#else
F_265 ( V_5 , 0x400000 , V_787 ) ;
F_265 ( V_5 , V_274 | V_788 ,
V_786 ) ;
if ( F_261 ( V_5 ) )
F_19 ( V_5 , L_71 ) ;
#endif
#ifdef F_270
F_6 ( L_72 , F_266 ( V_5 ,
V_786 ) ) ;
F_6 ( L_73 , F_266 ( V_5 , V_787 ) ) ;
F_6 ( L_74 , F_266 ( V_5 ,
V_789 ) ) ;
#endif
return 0 ;
}

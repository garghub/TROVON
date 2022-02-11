static inline unsigned int F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 ;
if ( V_3 > V_5 ) {
V_3 <<= 2 ;
V_4 = F_2 ( V_2 -> V_6 . V_7 + V_3 ) ;
} else
V_4 = ( unsigned int ) F_3 ( V_2 -> V_6 . V_7 + V_3 ) ;
return V_4 ;
}
static inline void F_4 ( struct V_1 * V_2 , int V_3 , int V_8 )
{
if ( V_3 > V_5 ) {
V_3 <<= 2 ;
F_5 ( V_8 , V_2 -> V_6 . V_7 + V_3 ) ;
} else {
unsigned char V_4 = V_8 & 0xff ;
F_6 ( V_4 , V_2 -> V_6 . V_7 + V_3 ) ;
}
}
static T_1 F_7 ( struct V_9 * V_9 , char T_2 * V_10 ,
T_3 V_11 , T_4 * V_12 )
{
struct V_1 * V_2 = V_9 -> V_13 ;
char * V_14 ;
T_5 V_15 = 0 ;
T_1 V_16 ;
V_14 = F_8 ( V_17 , V_18 ) ;
if ( ! V_14 )
return 0 ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_1 , V_2 -> V_19 ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_2 ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_3 , F_1 ( V_2 , V_20 ) ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_4 , F_1 ( V_2 , V_21 ) ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_5 , F_1 ( V_2 , V_22 ) ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_6 , F_1 ( V_2 , V_23 ) ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_7 , F_1 ( V_2 , V_24 ) ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_8 , F_1 ( V_2 , V_5 ) ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_9 , F_1 ( V_2 , V_25 ) ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_10 , F_1 ( V_2 , V_26 ) ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_11 , F_1 ( V_2 , V_27 ) ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_12 , F_1 ( V_2 , V_28 ) ) ;
if ( V_15 > V_17 )
V_15 = V_17 ;
V_16 = F_9 ( V_10 , V_11 , V_12 , V_14 , V_15 ) ;
F_10 ( V_14 ) ;
return V_16 ;
}
static T_1 F_11 ( struct V_9 * V_9 , char T_2 * V_10 ,
T_3 V_11 , T_4 * V_12 )
{
struct V_29 * V_30 = V_9 -> V_13 ;
char * V_14 ;
T_5 V_15 = 0 ;
T_1 V_16 ;
V_14 = F_8 ( V_17 , V_18 ) ;
if ( ! V_14 )
return 0 ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_13 , V_30 -> V_31 ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_2 ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_14 , F_12 ( V_30 , V_32 ) ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_15 , F_12 ( V_30 , V_33 ) ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_16 , F_12 ( V_30 , V_34 ) ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_17 , F_12 ( V_30 , V_35 ) ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_18 , F_12 ( V_30 , V_36 ) ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_19 , F_12 ( V_30 , V_37 ) ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_18 , F_12 ( V_30 , V_38 ) ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_19 , F_12 ( V_30 , V_39 ) ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_18 , F_12 ( V_30 , V_40 ) ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_19 , F_12 ( V_30 , V_41 ) ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_18 , F_12 ( V_30 , V_42 ) ) ;
V_15 += snprintf ( V_14 + V_15 , V_17 - V_15 ,
L_19 , F_12 ( V_30 , V_43 ) ) ;
if ( V_15 > V_17 )
V_15 = V_17 ;
V_16 = F_9 ( V_10 , V_11 , V_12 , V_14 , V_15 ) ;
F_10 ( V_14 ) ;
return V_16 ;
}
static int F_13 ( struct V_44 * V_45 )
{
int V_46 ;
char V_47 [ 32 ] ;
V_45 -> V_48 = F_14 ( L_20 , NULL ) ;
if ( ! V_45 -> V_48 )
return - V_49 ;
for ( V_46 = 0 ; V_46 < 3 ; V_46 ++ ) {
snprintf ( V_47 , sizeof( V_47 ) , L_21 , V_46 ) ;
F_15 ( V_47 , V_50 | V_51 ,
V_45 -> V_48 , ( void * ) ( & V_45 -> V_6 [ V_46 ] ) , & V_52 ) ;
}
for ( V_46 = 0 ; V_46 < 6 ; V_46 ++ ) {
snprintf ( V_47 , sizeof( V_47 ) , L_22 , V_46 ) ;
F_15 ( V_47 , V_50 | V_51 ,
V_45 -> V_48 , ( void * ) & V_45 -> V_53 [ V_46 ] , & V_54 ) ;
}
return 0 ;
}
static void F_16 ( struct V_44 * V_45 )
{
if ( V_45 -> V_48 )
F_17 ( V_45 -> V_48 ) ;
}
static inline int F_13 ( struct V_44 * V_45 )
{
return 0 ;
}
static inline void F_16 ( struct V_44 * V_45 )
{
}
static void F_18 ( struct V_55 * V_6 )
{
struct V_1 * V_2 =
F_19 ( V_6 , struct V_1 , V_6 ) ;
V_2 -> V_56 |= V_57 ;
F_4 ( V_2 , V_20 , V_2 -> V_56 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_58 * V_59 = & V_2 -> V_6 . V_60 -> V_59 ;
struct V_61 * V_62 = & V_2 -> V_63 ;
int V_11 ;
if ( V_2 -> V_64 )
return;
V_59 -> V_65 += V_62 -> V_66 ;
V_59 -> V_65 &= V_67 - 1 ;
V_2 -> V_6 . V_68 . V_69 += V_62 -> V_66 ;
V_62 -> V_66 = 0 ;
F_21 ( V_2 -> V_70 , V_32 , 0x0 ) ;
if ( ! F_22 ( V_59 ) && ! F_23 ( & V_2 -> V_6 ) ) {
F_24 ( V_2 -> V_6 . V_71 ,
V_62 -> V_72 ,
V_62 -> V_73 ,
V_74 ) ;
V_11 = F_25 ( V_59 -> V_75 , V_59 -> V_65 , V_67 ) ;
V_62 -> V_66 = V_11 ;
F_21 ( V_2 -> V_70 , V_36 , V_62 -> V_72 + V_59 -> V_65 ) ;
F_21 ( V_2 -> V_70 , V_37 , V_11 ) ;
F_21 ( V_2 -> V_70 , V_33 , 0x1
| ( 0x1 << 8 )
| ( 0x1 << 16 )
| ( 0x1 << 24 ) ) ;
V_2 -> V_64 = 1 ;
F_21 ( V_2 -> V_70 , V_32 , 0x1 ) ;
}
if ( F_26 ( V_59 ) < V_76 )
F_27 ( & V_2 -> V_6 ) ;
}
void F_28 ( struct V_29 * V_77 , struct V_61 * V_62 )
{
V_62 -> V_66 = 0 ;
F_21 ( V_77 , V_34 , 32 ) ;
F_21 ( V_77 , V_35 , 4 ) ;
F_21 ( V_77 , V_36 , V_62 -> V_72 ) ;
F_21 ( V_77 , V_37 , V_62 -> V_73 ) ;
F_21 ( V_77 , V_33 , 0x1 | ( 0x1 << 8 )
| ( 0x1 << 16 )
| ( 0x1 << 24 )
) ;
F_21 ( V_77 , V_32 , 0x3 ) ;
}
static void F_29 ( struct V_55 * V_6 )
{
struct V_1 * V_2 =
F_19 ( V_6 , struct V_1 , V_6 ) ;
if ( V_2 -> V_78 ) {
F_20 ( V_2 ) ;
} else if ( ! ( V_2 -> V_56 & V_79 ) ) {
V_2 -> V_56 |= V_79 ;
F_4 ( V_2 , V_20 , V_2 -> V_56 ) ;
}
}
static void F_30 ( struct V_55 * V_6 )
{
struct V_1 * V_2 =
F_19 ( V_6 , struct V_1 , V_6 ) ;
struct V_29 * V_70 = V_2 -> V_70 ;
if ( V_2 -> V_78 )
F_21 ( V_70 , V_32 , 0x0 ) ;
else if ( V_2 -> V_56 & V_79 ) {
V_2 -> V_56 &= ~ V_79 ;
F_4 ( V_2 , V_20 , V_2 -> V_56 ) ;
}
}
void F_31 ( struct V_1 * V_2 , T_5 V_80 )
{
struct V_61 * V_62 = & V_2 -> V_81 ;
struct V_29 * V_30 = V_2 -> V_77 ;
struct V_55 * V_6 = & V_2 -> V_6 ;
struct V_82 * V_83 = V_6 -> V_60 -> V_6 . V_83 ;
int V_11 ;
if ( ! V_83 )
return;
if ( V_80 & 0xf00 )
F_32 ( 2 ) ;
F_21 ( V_30 , V_32 , 0x0 ) ;
V_11 = F_12 ( V_30 , V_36 ) - V_62 -> V_72 ;
if ( ! V_11 ) {
F_21 ( V_30 , V_32 , 0x3 ) ;
return;
}
F_33 ( V_6 -> V_71 , V_62 -> V_72 ,
V_62 -> V_73 , V_84 ) ;
F_34 ( V_83 , V_62 -> V_14 , V_11 ) ;
V_6 -> V_68 . V_85 += V_11 ;
F_24 ( V_2 -> V_6 . V_71 , V_62 -> V_72 ,
V_62 -> V_73 , V_84 ) ;
F_21 ( V_30 , V_36 , V_62 -> V_72 ) ;
F_21 ( V_30 , V_37 , V_62 -> V_73 ) ;
F_21 ( V_30 , V_33 , 0x1
| ( 0x1 << 8 )
| ( 0x1 << 16 )
| ( 0x1 << 24 )
) ;
F_35 ( V_83 ) ;
F_21 ( V_30 , V_32 , 0x3 ) ;
}
static void F_36 ( struct V_55 * V_6 )
{
struct V_1 * V_2 =
F_19 ( V_6 , struct V_1 , V_6 ) ;
struct V_29 * V_30 = V_2 -> V_77 ;
if ( V_2 -> V_78 )
F_21 ( V_30 , V_32 , 0x2 ) ;
else {
V_2 -> V_56 &= ~ V_86 ;
V_2 -> V_6 . V_87 &= ~ V_88 ;
F_4 ( V_2 , V_20 , V_2 -> V_56 ) ;
}
}
static inline void F_37 ( struct V_1 * V_2 , int * V_89 )
{
struct V_82 * V_83 = V_2 -> V_6 . V_60 -> V_6 . V_83 ;
unsigned int V_90 , V_91 ;
unsigned int V_92 = 256 ;
if ( ! V_83 )
return;
do {
V_90 = F_1 ( V_2 , V_93 ) ;
V_91 = V_94 ;
V_2 -> V_6 . V_68 . V_85 ++ ;
if ( F_38 ( * V_89 & ( V_95 | V_96 |
V_97 | V_98 ) ) ) {
F_39 ( V_2 -> V_71 , L_23
L_24 , * V_89 ) ;
if ( * V_89 & V_95 ) {
* V_89 &= ~ ( V_97 | V_96 ) ;
V_2 -> V_6 . V_68 . V_99 ++ ;
if ( F_40 ( & V_2 -> V_6 ) )
goto V_100;
} else if ( * V_89 & V_96 )
V_2 -> V_6 . V_68 . V_101 ++ ;
else if ( * V_89 & V_97 )
V_2 -> V_6 . V_68 . V_102 ++ ;
if ( * V_89 & V_98 )
V_2 -> V_6 . V_68 . V_103 ++ ;
* V_89 &= V_2 -> V_6 . V_87 ;
#ifdef F_41
if ( V_2 -> V_6 . V_104 &&
V_2 -> V_6 . V_104 -> V_19 == V_2 -> V_6 . line ) {
* V_89 |= V_2 -> V_105 ;
V_2 -> V_105 = 0 ;
}
#endif
if ( * V_89 & V_95 ) {
V_91 = V_106 ;
} else if ( * V_89 & V_96 )
V_91 = V_107 ;
else if ( * V_89 & V_97 )
V_91 = V_108 ;
}
if ( F_42 ( & V_2 -> V_6 , V_90 ) )
goto V_100;
F_43 ( & V_2 -> V_6 , * V_89 , V_98 , V_90 , V_91 ) ;
V_100:
* V_89 = F_1 ( V_2 , V_24 ) ;
} while ( ( * V_89 & V_88 ) && V_92 -- );
F_35 ( V_83 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_58 * V_59 = & V_2 -> V_6 . V_60 -> V_59 ;
int V_11 ;
if ( V_2 -> V_6 . V_109 ) {
F_4 ( V_2 , V_110 , V_2 -> V_6 . V_109 ) ;
V_2 -> V_6 . V_68 . V_69 ++ ;
V_2 -> V_6 . V_109 = 0 ;
return;
}
if ( F_22 ( V_59 ) || F_23 ( & V_2 -> V_6 ) ) {
F_30 ( & V_2 -> V_6 ) ;
return;
}
V_11 = V_2 -> V_6 . V_111 / 2 ;
do {
F_4 ( V_2 , V_110 , V_59 -> V_14 [ V_59 -> V_65 ] ) ;
V_59 -> V_65 = ( V_59 -> V_65 + 1 ) & ( V_67 - 1 ) ;
V_2 -> V_6 . V_68 . V_69 ++ ;
if ( F_22 ( V_59 ) )
break;
} while ( -- V_11 > 0 );
if ( F_26 ( V_59 ) < V_76 )
F_27 ( & V_2 -> V_6 ) ;
if ( F_22 ( V_59 ) )
F_30 ( & V_2 -> V_6 ) ;
}
static inline void F_45 ( struct V_1 * V_2 )
{
int V_89 ;
V_89 = F_1 ( V_2 , V_5 ) ;
if ( ( V_89 & V_112 ) == 0 )
return;
if ( V_89 & V_113 )
V_2 -> V_6 . V_68 . V_114 ++ ;
if ( V_89 & V_115 )
V_2 -> V_6 . V_68 . V_116 ++ ;
if ( V_89 & V_117 )
F_46 ( & V_2 -> V_6 , V_89 & V_118 ) ;
if ( V_89 & V_119 )
F_47 ( & V_2 -> V_6 , V_89 & V_120 ) ;
F_48 ( & V_2 -> V_6 . V_60 -> V_6 . V_121 ) ;
}
static T_6 F_49 ( int V_122 , void * V_123 )
{
struct V_1 * V_2 = V_123 ;
unsigned int V_124 , V_125 ;
unsigned long V_126 ;
if ( F_38 ( ! V_2 -> V_127 ) )
return V_128 ;
F_50 ( & V_2 -> V_6 . V_129 , V_126 ) ;
if ( V_2 -> V_78 ) {
V_125 = F_1 ( V_2 , V_24 ) ;
if ( F_38 ( V_125 & ( V_95 | V_96 |
V_97 | V_98 ) ) )
F_39 ( V_2 -> V_71 ,
L_25 ,
V_125 ) ;
F_45 ( V_2 ) ;
F_51 ( & V_2 -> V_6 . V_129 , V_126 ) ;
return V_130 ;
}
V_124 = F_1 ( V_2 , V_21 ) ;
if ( V_124 & V_131 ) {
F_51 ( & V_2 -> V_6 . V_129 , V_126 ) ;
return V_128 ;
}
V_125 = F_1 ( V_2 , V_24 ) ;
if ( V_125 & V_88 )
F_37 ( V_2 , & V_125 ) ;
F_45 ( V_2 ) ;
if ( V_125 & V_132 )
F_44 ( V_2 ) ;
F_51 ( & V_2 -> V_6 . V_129 , V_126 ) ;
return V_130 ;
}
static inline void F_52 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_133 ;
unsigned long V_126 ;
T_5 V_80 ;
F_50 ( & V_2 -> V_6 . V_129 , V_126 ) ;
if ( ! V_2 -> V_78 || ! V_2 -> V_127 )
goto exit;
V_80 = F_12 ( V_30 , V_134 ) ;
if ( V_30 -> V_135 == V_84 )
F_31 ( V_2 , V_80 ) ;
if ( V_30 -> V_135 == V_74 ) {
F_21 ( V_30 , V_32 , 0x0 ) ;
V_2 -> V_64 = 0 ;
F_20 ( V_2 ) ;
}
exit:
F_51 ( & V_2 -> V_6 . V_129 , V_126 ) ;
return;
}
static T_6 F_53 ( int V_122 , void * V_123 )
{
struct V_44 * V_45 = V_123 ;
T_5 V_80 , V_46 ;
V_80 = F_54 ( V_45 , V_136 ) ;
for ( V_46 = 0 ; V_46 < 6 ; V_46 ++ ) {
if ( V_80 & 0x1 )
F_52 ( & V_45 -> V_53 [ V_46 ] ) ;
V_80 >>= 1 ;
}
return V_130 ;
}
static unsigned int F_55 ( struct V_55 * V_6 )
{
struct V_1 * V_2 =
F_19 ( V_6 , struct V_1 , V_6 ) ;
unsigned long V_126 ;
unsigned int V_16 ;
F_50 ( & V_2 -> V_6 . V_129 , V_126 ) ;
V_16 = F_1 ( V_2 , V_24 ) & V_137 ? V_138 : 0 ;
F_51 ( & V_2 -> V_6 . V_129 , V_126 ) ;
return V_16 ;
}
static unsigned int F_56 ( struct V_55 * V_6 )
{
struct V_1 * V_2 =
F_19 ( V_6 , struct V_1 , V_6 ) ;
unsigned char V_89 ;
unsigned int V_16 ;
V_89 = F_1 ( V_2 , V_5 ) ;
V_16 = 0 ;
if ( V_89 & V_118 )
V_16 |= V_139 ;
if ( V_89 & V_140 )
V_16 |= V_141 ;
if ( V_89 & V_142 )
V_16 |= V_143 ;
if ( V_89 & V_120 )
V_16 |= V_144 ;
return V_16 ;
}
static void F_57 ( struct V_55 * V_6 , unsigned int V_145 )
{
struct V_1 * V_2 =
F_19 ( V_6 , struct V_1 , V_6 ) ;
unsigned char V_146 = 0 ;
if ( V_145 & V_147 )
V_146 |= V_148 ;
if ( V_145 & V_149 )
V_146 |= V_150 ;
if ( V_145 & V_151 )
V_146 |= V_152 ;
if ( V_145 & V_153 )
V_146 |= V_154 ;
if ( V_145 & V_155 )
V_146 |= V_156 ;
V_146 |= V_2 -> V_146 ;
F_4 ( V_2 , V_23 , V_146 ) ;
}
static void F_58 ( struct V_55 * V_6 , int V_157 )
{
struct V_1 * V_2 =
F_19 ( V_6 , struct V_1 , V_6 ) ;
unsigned long V_126 ;
F_50 ( & V_2 -> V_6 . V_129 , V_126 ) ;
if ( V_157 == - 1 )
V_2 -> V_158 |= V_159 ;
else
V_2 -> V_158 &= ~ V_159 ;
F_4 ( V_2 , V_22 , V_2 -> V_158 ) ;
F_51 ( & V_2 -> V_6 . V_129 , V_126 ) ;
}
static int F_59 ( struct V_55 * V_6 )
{
struct V_1 * V_2 =
F_19 ( V_6 , struct V_1 , V_6 ) ;
unsigned long V_126 ;
F_60 ( V_2 -> V_71 ) ;
F_4 ( V_2 , V_160 , V_161 ) ;
F_4 ( V_2 , V_160 , V_161 |
V_162 | V_163 ) ;
F_4 ( V_2 , V_160 , 0 ) ;
( void ) F_1 ( V_2 , V_24 ) ;
( void ) F_1 ( V_2 , V_93 ) ;
( void ) F_1 ( V_2 , V_21 ) ;
( void ) F_1 ( V_2 , V_5 ) ;
F_4 ( V_2 , V_22 , V_164 ) ;
F_50 ( & V_2 -> V_6 . V_129 , V_126 ) ;
V_2 -> V_6 . V_145 |= V_153 ;
F_57 ( & V_2 -> V_6 , V_2 -> V_6 . V_145 ) ;
if ( ! V_2 -> V_78 )
V_2 -> V_56 = V_86 | V_165 | V_166 ;
else
V_2 -> V_56 = 0 ;
F_4 ( V_2 , V_20 , V_2 -> V_56 ) ;
F_51 ( & V_2 -> V_6 . V_129 , V_126 ) ;
if ( V_2 -> V_78 ) {
struct V_61 * V_62 ;
struct V_58 * V_59 = & V_6 -> V_60 -> V_59 ;
V_2 -> V_64 = 0 ;
V_62 = & V_2 -> V_81 ;
V_62 -> V_14 = F_8 ( V_167 , V_18 ) ;
if ( ! V_62 -> V_14 ) {
V_2 -> V_78 = 0 ;
goto exit;
}
V_62 -> V_72 = F_61 ( V_6 -> V_71 ,
V_62 -> V_14 ,
V_167 ,
V_84 ) ;
V_62 -> V_73 = V_167 ;
F_28 ( V_2 -> V_77 , V_62 ) ;
V_62 = & V_2 -> V_63 ;
V_62 -> V_14 = V_59 -> V_14 ;
V_62 -> V_72 = F_61 ( V_6 -> V_71 ,
V_62 -> V_14 ,
V_67 ,
V_74 ) ;
V_62 -> V_73 = V_67 ;
F_21 ( V_2 -> V_70 , V_34 , 32 ) ;
F_21 ( V_2 -> V_70 , V_35 , 4 ) ;
V_62 -> V_66 = 0 ;
}
exit:
( void ) F_1 ( V_2 , V_24 ) ;
( void ) F_1 ( V_2 , V_93 ) ;
( void ) F_1 ( V_2 , V_21 ) ;
( void ) F_1 ( V_2 , V_5 ) ;
V_2 -> V_127 = 1 ;
return 0 ;
}
static void F_62 ( struct V_55 * V_6 )
{
struct V_1 * V_2 =
F_19 ( V_6 , struct V_1 , V_6 ) ;
unsigned long V_126 ;
V_2 -> V_56 = 0 ;
F_4 ( V_2 , V_20 , 0 ) ;
V_2 -> V_127 = 0 ;
F_50 ( & V_2 -> V_6 . V_129 , V_126 ) ;
V_2 -> V_6 . V_145 &= ~ V_153 ;
F_57 ( & V_2 -> V_6 , V_2 -> V_6 . V_145 ) ;
F_51 ( & V_2 -> V_6 . V_129 , V_126 ) ;
F_4 ( V_2 , V_22 , F_1 ( V_2 , V_22 ) & ~ V_159 ) ;
F_4 ( V_2 , V_160 , V_161 |
V_162 |
V_163 ) ;
F_4 ( V_2 , V_160 , 0 ) ;
F_63 ( V_2 -> V_71 ) ;
}
static void
F_64 ( struct V_55 * V_6 , struct V_168 * V_169 ,
struct V_168 * V_170 )
{
struct V_1 * V_2 =
F_19 ( V_6 , struct V_1 , V_6 ) ;
unsigned char V_171 , V_172 = 0 ;
unsigned long V_126 ;
unsigned int V_173 , V_174 ;
T_5 V_175 , V_176 ;
switch ( V_169 -> V_177 & V_178 ) {
case V_179 :
V_171 = V_180 ;
break;
case V_181 :
V_171 = V_182 ;
break;
case V_183 :
V_171 = V_184 ;
break;
default:
case V_185 :
V_171 = V_164 ;
break;
}
V_169 -> V_177 &= ~ V_186 ;
if ( V_169 -> V_177 & V_187 )
V_171 |= V_188 ;
if ( V_169 -> V_177 & V_189 )
V_171 |= V_190 ;
if ( ! ( V_169 -> V_177 & V_191 ) )
V_171 |= V_192 ;
V_173 = F_65 ( V_6 , V_169 , V_170 , 0 , 4000000 ) ;
V_174 = 1 ;
V_175 = 0x10 ;
V_176 = 0x3600 ;
switch ( V_173 ) {
case 3500000 :
V_176 = 0x3345 ;
V_175 = 0xC ;
break;
case 1843200 :
V_176 = 0x2400 ;
break;
case 3000000 :
case 2500000 :
case 2000000 :
case 1500000 :
case 1000000 :
case 500000 :
V_176 = V_173 / 500000 * 0x9C4 ;
break;
default:
V_174 = 0 ;
}
if ( ! V_174 )
V_174 = F_66 ( V_6 , V_173 ) ;
if ( ( V_2 -> V_6 . V_193 / V_174 ) < ( 2400 * 16 ) )
V_172 = V_161 | V_194 ;
else if ( ( V_2 -> V_6 . V_193 / V_174 ) < ( 230400 * 16 ) )
V_172 = V_161 | V_195 ;
else
V_172 = V_161 | V_196 ;
V_172 |= V_197 ;
F_50 ( & V_2 -> V_6 . V_129 , V_126 ) ;
F_67 ( V_6 , V_169 -> V_177 , V_173 ) ;
V_2 -> V_6 . V_87 = V_98 | V_132 | V_88 ;
if ( V_169 -> V_198 & V_199 )
V_2 -> V_6 . V_87 |= V_97 | V_96 ;
if ( V_169 -> V_198 & ( V_200 | V_201 ) )
V_2 -> V_6 . V_87 |= V_95 ;
V_2 -> V_6 . V_202 = 0 ;
if ( V_169 -> V_198 & V_203 )
V_2 -> V_6 . V_202 |= V_96 | V_97 ;
if ( V_169 -> V_198 & V_204 ) {
V_2 -> V_6 . V_202 |= V_95 ;
if ( V_169 -> V_198 & V_203 )
V_2 -> V_6 . V_202 |= V_98 ;
}
if ( ( V_169 -> V_177 & V_205 ) == 0 )
V_2 -> V_6 . V_202 |= V_88 ;
V_2 -> V_56 &= ~ V_57 ;
if ( F_68 ( & V_2 -> V_6 , V_169 -> V_177 ) )
V_2 -> V_56 |= V_57 ;
F_4 ( V_2 , V_20 , V_2 -> V_56 ) ;
if ( V_169 -> V_177 & V_206 )
V_2 -> V_146 |= V_207 | V_148 ;
else
V_2 -> V_146 &= ~ V_207 ;
F_4 ( V_2 , V_22 , V_171 | V_208 ) ;
F_4 ( V_2 , V_209 , V_174 & 0xff ) ;
F_4 ( V_2 , V_210 , V_174 >> 8 ) ;
F_4 ( V_2 , V_22 , V_171 ) ;
F_4 ( V_2 , V_27 , V_176 ) ;
F_4 ( V_2 , V_26 , V_175 ) ;
V_2 -> V_158 = V_171 ;
F_57 ( & V_2 -> V_6 , V_2 -> V_6 . V_145 ) ;
F_4 ( V_2 , V_160 , V_172 ) ;
F_51 ( & V_2 -> V_6 . V_129 , V_126 ) ;
}
static void
F_69 ( struct V_55 * V_6 , unsigned int V_60 ,
unsigned int V_211 )
{
}
static void F_70 ( struct V_55 * V_6 )
{
}
static int F_71 ( struct V_55 * V_6 )
{
return 0 ;
}
static void F_72 ( struct V_55 * V_6 , int V_126 )
{
struct V_1 * V_2 =
F_19 ( V_6 , struct V_1 , V_6 ) ;
V_2 -> V_6 . type = V_212 ;
}
static int
F_73 ( struct V_55 * V_6 , struct V_213 * V_214 )
{
return - V_215 ;
}
static const char *
F_74 ( struct V_55 * V_6 )
{
struct V_1 * V_2 =
F_19 ( V_6 , struct V_1 , V_6 ) ;
return V_2 -> V_47 ;
}
static inline void F_75 ( struct V_1 * V_2 )
{
unsigned int V_89 , V_216 = 1000 ;
do {
V_89 = F_1 ( V_2 , V_24 ) ;
if ( V_89 & V_95 )
V_2 -> V_105 = V_95 ;
if ( -- V_216 == 0 )
break;
F_32 ( 1 ) ;
} while ( ! ( V_89 & V_217 ) );
if ( V_2 -> V_6 . V_126 & V_218 ) {
V_216 = 1000000 ;
while ( -- V_216 &&
( ( F_1 ( V_2 , V_5 ) & V_120 ) == 0 ) )
F_32 ( 1 ) ;
}
}
static void F_76 ( struct V_55 * V_6 , int V_90 )
{
struct V_1 * V_2 =
F_19 ( V_6 , struct V_1 , V_6 ) ;
F_75 ( V_2 ) ;
F_4 ( V_2 , V_110 , V_90 ) ;
}
static void
F_77 ( struct V_219 * V_220 , const char * V_221 , unsigned int V_11 )
{
struct V_1 * V_2 = V_222 [ V_220 -> V_19 ] ;
unsigned long V_126 ;
unsigned int V_56 ;
int V_223 = 1 ;
F_78 ( V_126 ) ;
if ( V_2 -> V_6 . V_224 )
V_223 = 0 ;
else if ( V_225 ) {
V_223 = F_79 ( & V_2 -> V_6 . V_129 ) ;
} else
F_80 ( & V_2 -> V_6 . V_129 ) ;
V_56 = F_1 ( V_2 , V_20 ) ;
F_4 ( V_2 , V_20 , 0 ) ;
F_81 ( & V_2 -> V_6 , V_221 , V_11 , F_76 ) ;
F_75 ( V_2 ) ;
F_4 ( V_2 , V_20 , V_56 ) ;
if ( V_223 )
F_82 ( & V_2 -> V_6 . V_129 ) ;
F_83 ( V_126 ) ;
}
static int T_7
F_84 ( struct V_219 * V_220 , char * V_226 )
{
struct V_1 * V_2 ;
int V_173 = 115200 ;
int V_227 = 8 ;
int V_101 = 'n' ;
int V_228 = 'n' ;
if ( V_220 -> V_19 == - 1 || V_220 -> V_19 >= V_229 . V_230 )
V_220 -> V_19 = 0 ;
V_2 = V_222 [ V_220 -> V_19 ] ;
if ( ! V_2 )
return - V_231 ;
if ( V_226 )
F_85 ( V_226 , & V_173 , & V_101 , & V_227 , & V_228 ) ;
return F_86 ( & V_2 -> V_6 , V_220 , V_173 , V_101 , V_227 , V_228 ) ;
}
static int F_87 ( struct V_232 * V_233 , T_8 V_60 )
{
void * V_234 = F_88 ( V_233 ) ;
struct V_1 * V_2 ;
if ( V_234 && ( V_233 -> V_235 != 0x081E ) ) {
V_2 = V_234 ;
F_89 ( & V_229 , & V_2 -> V_6 ) ;
}
F_90 ( V_233 ) ;
F_91 ( V_233 , F_92 ( V_233 , V_60 ) ) ;
return 0 ;
}
static int F_93 ( struct V_232 * V_233 )
{
void * V_234 = F_88 ( V_233 ) ;
struct V_1 * V_2 ;
int V_16 ;
F_91 ( V_233 , V_236 ) ;
F_94 ( V_233 ) ;
V_16 = F_95 ( V_233 ) ;
if ( V_16 )
F_39 ( & V_233 -> V_71 ,
L_26 ) ;
if ( V_234 && ( V_233 -> V_235 != 0x081E ) ) {
V_2 = V_234 ;
F_96 ( & V_229 , & V_2 -> V_6 ) ;
}
return 0 ;
}
static int F_97 ( struct V_235 * V_71 )
{
int V_237 ;
V_237 = F_98 ( V_71 , 500 ) ;
if ( V_237 )
return - V_238 ;
return 0 ;
}
static int F_99 ( struct V_235 * V_71 )
{
return 0 ;
}
static int F_100 ( struct V_235 * V_71 )
{
return 0 ;
}
static int F_101 ( struct V_232 * V_233 ,
const struct V_239 * V_240 )
{
struct V_1 * V_133 ;
int V_19 , V_16 ;
F_102 ( V_241 L_27 ,
V_233 -> V_242 , V_233 -> V_235 ) ;
switch ( V_233 -> V_235 ) {
case 0x081B :
V_19 = 0 ;
break;
case 0x081C :
V_19 = 1 ;
break;
case 0x081D :
V_19 = 2 ;
break;
case 0x081E :
V_19 = 3 ;
break;
default:
F_103 ( & V_233 -> V_71 , L_28 ) ;
return - V_231 ;
}
V_16 = F_95 ( V_233 ) ;
if ( V_16 )
return V_16 ;
if ( V_19 == 3 ) {
V_16 = F_104 ( V_233 -> V_122 , F_53 , 0 , L_29 , V_243 ) ;
if ( V_16 ) {
F_103 ( & V_233 -> V_71 , L_30 ) ;
goto V_244;
}
F_105 ( V_233 , V_243 ) ;
} else {
V_133 = & V_243 -> V_6 [ V_19 ] ;
V_133 -> V_6 . V_122 = V_233 -> V_122 ;
V_133 -> V_6 . V_71 = & V_233 -> V_71 ;
V_133 -> V_71 = & V_233 -> V_71 ;
V_16 = F_104 ( V_233 -> V_122 , F_49 , 0 , V_133 -> V_47 , V_133 ) ;
if ( V_16 ) {
F_103 ( & V_233 -> V_71 , L_30 ) ;
goto V_244;
}
F_106 ( & V_229 , & V_133 -> V_6 ) ;
F_105 ( V_233 , V_133 ) ;
}
F_107 ( & V_233 -> V_71 ) ;
F_108 ( & V_233 -> V_71 ) ;
return 0 ;
V_244:
F_109 ( V_233 ) ;
return V_16 ;
}
static void F_110 ( void )
{
struct V_44 * V_45 ;
struct V_1 * V_133 ;
struct V_29 * V_245 ;
int V_46 , V_16 ;
V_45 = F_8 ( sizeof( struct V_44 ) , V_18 ) ;
if ( ! V_45 )
return;
V_45 -> V_246 = 0xffa28000 ;
V_45 -> V_247 = 0x1000 ;
if ( ! ( F_111 ( V_45 -> V_246 , V_45 -> V_247 , L_31 ) ) )
F_112 ( L_32 ) ;
V_45 -> V_248 = F_113 ( ( unsigned long ) V_45 -> V_246 , V_45 -> V_247 ) ;
if ( ! V_45 -> V_248 ) {
F_114 ( L_33 ) ;
V_16 = - V_49 ;
goto V_249;
}
V_133 = V_45 -> V_6 ;
for ( V_46 = 0 ; V_46 < 3 ; V_46 ++ ) {
V_133 -> V_6 . type = V_212 ;
V_133 -> V_6 . V_250 = V_251 ;
V_133 -> V_6 . V_252 = ( V_253 ) V_45 -> V_246
+ V_254
+ V_46 * V_255 ;
V_133 -> V_6 . V_7 = V_45 -> V_248 + V_254
+ V_46 * V_255 ;
sprintf ( V_133 -> V_47 , L_34 , V_46 ) ;
V_133 -> V_6 . V_111 = 64 ;
V_133 -> V_6 . V_256 = & V_257 ;
V_133 -> V_6 . line = V_46 ;
V_133 -> V_6 . V_126 = V_258 ;
V_133 -> V_6 . V_193 = 115200 * 24 * 16 ;
V_133 -> V_127 = 0 ;
V_133 -> V_70 = & V_45 -> V_53 [ V_46 * 2 ] ;
V_133 -> V_77 = & V_45 -> V_53 [ V_46 * 2 + 1 ] ;
V_222 [ V_46 ] = V_133 ;
V_133 -> V_19 = V_46 ;
if ( V_259 & ( 1 << V_46 ) )
V_133 -> V_78 = 1 ;
else
V_133 -> V_78 = 0 ;
V_133 ++ ;
}
V_245 = V_45 -> V_53 ;
for ( V_46 = 0 ; V_46 < 6 ; V_46 ++ ) {
V_245 -> V_31 = V_46 ;
V_245 -> V_135 = ( V_46 & 0x1 ) ? V_84 : V_74 ;
V_245 -> V_133 = & V_45 -> V_6 [ V_46 / 2 ] ;
V_245 -> V_248 = V_45 -> V_248 + V_260 +
V_46 * V_261 ;
V_245 ++ ;
}
V_243 = V_45 ;
F_13 ( V_45 ) ;
return;
V_249:
F_115 ( V_45 -> V_246 , V_45 -> V_247 ) ;
F_10 ( V_45 ) ;
return;
}
static void F_116 ( struct V_232 * V_233 )
{
void * V_234 = F_88 ( V_233 ) ;
struct V_1 * V_2 ;
if ( ! V_234 )
return;
F_117 ( & V_233 -> V_71 ) ;
F_118 ( & V_233 -> V_71 ) ;
if ( V_233 -> V_235 != 0x081E ) {
V_2 = V_234 ;
F_119 ( & V_229 , & V_2 -> V_6 ) ;
}
F_105 ( V_233 , NULL ) ;
F_120 ( V_233 -> V_122 , V_234 ) ;
F_109 ( V_233 ) ;
}
static int T_7 F_121 ( void )
{
int V_16 ;
F_110 () ;
V_16 = F_122 ( & V_229 ) ;
if ( V_16 )
return V_16 ;
return F_123 ( & V_262 ) ;
}
static void T_9 F_124 ( void )
{
F_125 ( & V_262 ) ;
F_126 ( & V_229 ) ;
F_16 ( V_243 ) ;
F_10 ( V_243 ) ;
}

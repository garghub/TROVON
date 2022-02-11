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
static int F_7 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
V_10 -> V_11 = V_9 -> V_12 ;
return 0 ;
}
static T_1 F_8 ( struct V_10 * V_10 , char T_2 * V_13 ,
T_3 V_14 , T_4 * V_15 )
{
struct V_1 * V_2 = V_10 -> V_11 ;
char * V_16 ;
T_5 V_17 = 0 ;
T_1 V_18 ;
V_16 = F_9 ( V_19 , V_20 ) ;
if ( ! V_16 )
return 0 ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_1 , V_2 -> V_21 ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_2 ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_3 , F_1 ( V_2 , V_22 ) ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_4 , F_1 ( V_2 , V_23 ) ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_5 , F_1 ( V_2 , V_24 ) ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_6 , F_1 ( V_2 , V_25 ) ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_7 , F_1 ( V_2 , V_26 ) ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_8 , F_1 ( V_2 , V_5 ) ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_9 , F_1 ( V_2 , V_27 ) ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_10 , F_1 ( V_2 , V_28 ) ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_11 , F_1 ( V_2 , V_29 ) ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_12 , F_1 ( V_2 , V_30 ) ) ;
if ( V_17 > V_19 )
V_17 = V_19 ;
V_18 = F_10 ( V_13 , V_14 , V_15 , V_16 , V_17 ) ;
F_11 ( V_16 ) ;
return V_18 ;
}
static T_1 F_12 ( struct V_10 * V_10 , char T_2 * V_13 ,
T_3 V_14 , T_4 * V_15 )
{
struct V_31 * V_32 = V_10 -> V_11 ;
char * V_16 ;
T_5 V_17 = 0 ;
T_1 V_18 ;
V_16 = F_9 ( V_19 , V_20 ) ;
if ( ! V_16 )
return 0 ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_13 , V_32 -> V_33 ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_2 ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_14 , F_13 ( V_32 , V_34 ) ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_15 , F_13 ( V_32 , V_35 ) ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_16 , F_13 ( V_32 , V_36 ) ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_17 , F_13 ( V_32 , V_37 ) ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_18 , F_13 ( V_32 , V_38 ) ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_19 , F_13 ( V_32 , V_39 ) ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_18 , F_13 ( V_32 , V_40 ) ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_19 , F_13 ( V_32 , V_41 ) ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_18 , F_13 ( V_32 , V_42 ) ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_19 , F_13 ( V_32 , V_43 ) ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_18 , F_13 ( V_32 , V_44 ) ) ;
V_17 += snprintf ( V_16 + V_17 , V_19 - V_17 ,
L_19 , F_13 ( V_32 , V_45 ) ) ;
if ( V_17 > V_19 )
V_17 = V_19 ;
V_18 = F_10 ( V_13 , V_14 , V_15 , V_16 , V_17 ) ;
F_11 ( V_16 ) ;
return V_18 ;
}
static int F_14 ( struct V_46 * V_47 )
{
int V_48 ;
char V_49 [ 32 ] ;
V_47 -> V_50 = F_15 ( L_20 , NULL ) ;
if ( ! V_47 -> V_50 )
return - V_51 ;
for ( V_48 = 0 ; V_48 < 3 ; V_48 ++ ) {
snprintf ( V_49 , sizeof( V_49 ) , L_21 , V_48 ) ;
F_16 ( V_49 , V_52 | V_53 ,
V_47 -> V_50 , ( void * ) ( & V_47 -> V_6 [ V_48 ] ) , & V_54 ) ;
}
for ( V_48 = 0 ; V_48 < 6 ; V_48 ++ ) {
snprintf ( V_49 , sizeof( V_49 ) , L_22 , V_48 ) ;
F_16 ( V_49 , V_52 | V_53 ,
V_47 -> V_50 , ( void * ) & V_47 -> V_55 [ V_48 ] , & V_56 ) ;
}
return 0 ;
}
static void F_17 ( struct V_46 * V_47 )
{
if ( V_47 -> V_50 )
F_18 ( V_47 -> V_50 ) ;
}
static inline int F_14 ( struct V_46 * V_47 )
{
return 0 ;
}
static inline void F_17 ( struct V_46 * V_47 )
{
}
static void F_19 ( struct V_57 * V_6 )
{
struct V_1 * V_2 =
F_20 ( V_6 , struct V_1 , V_6 ) ;
V_2 -> V_58 |= V_59 ;
F_4 ( V_2 , V_22 , V_2 -> V_58 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = & V_2 -> V_6 . V_62 -> V_61 ;
struct V_63 * V_64 = & V_2 -> V_65 ;
int V_14 ;
if ( V_2 -> V_66 )
return;
V_61 -> V_67 += V_64 -> V_68 ;
V_61 -> V_67 &= V_69 - 1 ;
V_2 -> V_6 . V_70 . V_71 += V_64 -> V_68 ;
V_64 -> V_68 = 0 ;
F_22 ( V_2 -> V_72 , V_34 , 0x0 ) ;
if ( ! F_23 ( V_61 ) && ! F_24 ( & V_2 -> V_6 ) ) {
F_25 ( V_2 -> V_6 . V_73 ,
V_64 -> V_74 ,
V_64 -> V_75 ,
V_76 ) ;
V_14 = F_26 ( V_61 -> V_77 , V_61 -> V_67 , V_69 ) ;
V_64 -> V_68 = V_14 ;
F_22 ( V_2 -> V_72 , V_38 , V_64 -> V_74 + V_61 -> V_67 ) ;
F_22 ( V_2 -> V_72 , V_39 , V_14 ) ;
F_22 ( V_2 -> V_72 , V_35 , 0x1
| ( 0x1 << 8 )
| ( 0x1 << 16 )
| ( 0x1 << 24 ) ) ;
V_2 -> V_66 = 1 ;
F_22 ( V_2 -> V_72 , V_34 , 0x1 ) ;
}
if ( F_27 ( V_61 ) < V_78 )
F_28 ( & V_2 -> V_6 ) ;
}
void F_29 ( struct V_31 * V_79 , struct V_63 * V_64 )
{
V_64 -> V_68 = 0 ;
F_22 ( V_79 , V_36 , 32 ) ;
F_22 ( V_79 , V_37 , 4 ) ;
F_22 ( V_79 , V_38 , V_64 -> V_74 ) ;
F_22 ( V_79 , V_39 , V_64 -> V_75 ) ;
F_22 ( V_79 , V_35 , 0x1 | ( 0x1 << 8 )
| ( 0x1 << 16 )
| ( 0x1 << 24 )
) ;
F_22 ( V_79 , V_34 , 0x3 ) ;
}
static void F_30 ( struct V_57 * V_6 )
{
struct V_1 * V_2 =
F_20 ( V_6 , struct V_1 , V_6 ) ;
if ( V_2 -> V_80 ) {
F_21 ( V_2 ) ;
} else if ( ! ( V_2 -> V_58 & V_81 ) ) {
V_2 -> V_58 |= V_81 ;
F_4 ( V_2 , V_22 , V_2 -> V_58 ) ;
}
}
static void F_31 ( struct V_57 * V_6 )
{
struct V_1 * V_2 =
F_20 ( V_6 , struct V_1 , V_6 ) ;
struct V_31 * V_72 = V_2 -> V_72 ;
if ( V_2 -> V_80 )
F_22 ( V_72 , V_34 , 0x0 ) ;
else if ( V_2 -> V_58 & V_81 ) {
V_2 -> V_58 &= ~ V_81 ;
F_4 ( V_2 , V_22 , V_2 -> V_58 ) ;
}
}
void F_32 ( struct V_1 * V_2 , T_5 V_82 )
{
struct V_63 * V_64 = & V_2 -> V_83 ;
struct V_31 * V_32 = V_2 -> V_79 ;
struct V_57 * V_6 = & V_2 -> V_6 ;
struct V_84 * V_85 = V_6 -> V_62 -> V_6 . V_85 ;
int V_14 ;
if ( ! V_85 )
return;
if ( V_82 & 0xf00 )
F_33 ( 2 ) ;
F_22 ( V_32 , V_34 , 0x0 ) ;
V_14 = F_13 ( V_32 , V_38 ) - V_64 -> V_74 ;
if ( ! V_14 ) {
F_22 ( V_32 , V_34 , 0x3 ) ;
return;
}
F_34 ( V_6 -> V_73 , V_64 -> V_74 ,
V_64 -> V_75 , V_86 ) ;
F_35 ( V_85 , V_64 -> V_16 , V_14 ) ;
V_6 -> V_70 . V_87 += V_14 ;
F_25 ( V_2 -> V_6 . V_73 , V_64 -> V_74 ,
V_64 -> V_75 , V_86 ) ;
F_22 ( V_32 , V_38 , V_64 -> V_74 ) ;
F_22 ( V_32 , V_39 , V_64 -> V_75 ) ;
F_22 ( V_32 , V_35 , 0x1
| ( 0x1 << 8 )
| ( 0x1 << 16 )
| ( 0x1 << 24 )
) ;
F_36 ( V_85 ) ;
F_22 ( V_32 , V_34 , 0x3 ) ;
}
static void F_37 ( struct V_57 * V_6 )
{
struct V_1 * V_2 =
F_20 ( V_6 , struct V_1 , V_6 ) ;
struct V_31 * V_32 = V_2 -> V_79 ;
if ( V_2 -> V_80 )
F_22 ( V_32 , V_34 , 0x2 ) ;
else {
V_2 -> V_58 &= ~ V_88 ;
V_2 -> V_6 . V_89 &= ~ V_90 ;
F_4 ( V_2 , V_22 , V_2 -> V_58 ) ;
}
}
static inline void F_38 ( struct V_1 * V_2 , int * V_91 )
{
struct V_84 * V_85 = V_2 -> V_6 . V_62 -> V_6 . V_85 ;
unsigned int V_92 , V_93 ;
unsigned int V_94 = 256 ;
if ( ! V_85 )
return;
do {
V_92 = F_1 ( V_2 , V_95 ) ;
V_93 = V_96 ;
V_2 -> V_6 . V_70 . V_87 ++ ;
if ( F_39 ( * V_91 & ( V_97 | V_98 |
V_99 | V_100 ) ) ) {
F_40 ( V_2 -> V_73 , L_23
L_24 , * V_91 ) ;
if ( * V_91 & V_97 ) {
* V_91 &= ~ ( V_99 | V_98 ) ;
V_2 -> V_6 . V_70 . V_101 ++ ;
if ( F_41 ( & V_2 -> V_6 ) )
goto V_102;
} else if ( * V_91 & V_98 )
V_2 -> V_6 . V_70 . V_103 ++ ;
else if ( * V_91 & V_99 )
V_2 -> V_6 . V_70 . V_104 ++ ;
if ( * V_91 & V_100 )
V_2 -> V_6 . V_70 . V_105 ++ ;
* V_91 &= V_2 -> V_6 . V_89 ;
#ifdef F_42
if ( V_2 -> V_6 . V_106 &&
V_2 -> V_6 . V_106 -> V_21 == V_2 -> V_6 . line ) {
* V_91 |= V_2 -> V_107 ;
V_2 -> V_107 = 0 ;
}
#endif
if ( * V_91 & V_97 ) {
V_93 = V_108 ;
} else if ( * V_91 & V_98 )
V_93 = V_109 ;
else if ( * V_91 & V_99 )
V_93 = V_110 ;
}
if ( F_43 ( & V_2 -> V_6 , V_92 ) )
goto V_102;
F_44 ( & V_2 -> V_6 , * V_91 , V_100 , V_92 , V_93 ) ;
V_102:
* V_91 = F_1 ( V_2 , V_26 ) ;
} while ( ( * V_91 & V_90 ) && V_94 -- );
F_36 ( V_85 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = & V_2 -> V_6 . V_62 -> V_61 ;
int V_14 ;
if ( V_2 -> V_6 . V_111 ) {
F_4 ( V_2 , V_112 , V_2 -> V_6 . V_111 ) ;
V_2 -> V_6 . V_70 . V_71 ++ ;
V_2 -> V_6 . V_111 = 0 ;
return;
}
if ( F_23 ( V_61 ) || F_24 ( & V_2 -> V_6 ) ) {
F_31 ( & V_2 -> V_6 ) ;
return;
}
V_14 = V_2 -> V_6 . V_113 / 2 ;
do {
F_4 ( V_2 , V_112 , V_61 -> V_16 [ V_61 -> V_67 ] ) ;
V_61 -> V_67 = ( V_61 -> V_67 + 1 ) & ( V_69 - 1 ) ;
V_2 -> V_6 . V_70 . V_71 ++ ;
if ( F_23 ( V_61 ) )
break;
} while ( -- V_14 > 0 );
if ( F_27 ( V_61 ) < V_78 )
F_28 ( & V_2 -> V_6 ) ;
if ( F_23 ( V_61 ) )
F_31 ( & V_2 -> V_6 ) ;
}
static inline void F_46 ( struct V_1 * V_2 )
{
int V_91 ;
V_91 = F_1 ( V_2 , V_5 ) ;
if ( ( V_91 & V_114 ) == 0 )
return;
if ( V_91 & V_115 )
V_2 -> V_6 . V_70 . V_116 ++ ;
if ( V_91 & V_117 )
V_2 -> V_6 . V_70 . V_118 ++ ;
if ( V_91 & V_119 )
F_47 ( & V_2 -> V_6 , V_91 & V_120 ) ;
if ( V_91 & V_121 )
F_48 ( & V_2 -> V_6 , V_91 & V_122 ) ;
F_49 ( & V_2 -> V_6 . V_62 -> V_6 . V_123 ) ;
}
static T_6 F_50 ( int V_124 , void * V_125 )
{
struct V_1 * V_2 = V_125 ;
unsigned int V_126 , V_127 ;
unsigned long V_128 ;
if ( F_39 ( ! V_2 -> V_129 ) )
return V_130 ;
F_51 ( & V_2 -> V_6 . V_131 , V_128 ) ;
if ( V_2 -> V_80 ) {
V_127 = F_1 ( V_2 , V_26 ) ;
if ( F_39 ( V_127 & ( V_97 | V_98 |
V_99 | V_100 ) ) )
F_40 ( V_2 -> V_73 ,
L_25 ,
V_127 ) ;
F_46 ( V_2 ) ;
F_52 ( & V_2 -> V_6 . V_131 , V_128 ) ;
return V_132 ;
}
V_126 = F_1 ( V_2 , V_23 ) ;
if ( V_126 & V_133 ) {
F_52 ( & V_2 -> V_6 . V_131 , V_128 ) ;
return V_130 ;
}
V_127 = F_1 ( V_2 , V_26 ) ;
if ( V_127 & V_90 )
F_38 ( V_2 , & V_127 ) ;
F_46 ( V_2 ) ;
if ( V_127 & V_134 )
F_45 ( V_2 ) ;
F_52 ( & V_2 -> V_6 . V_131 , V_128 ) ;
return V_132 ;
}
static inline void F_53 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_135 ;
unsigned long V_128 ;
T_5 V_82 ;
F_51 ( & V_2 -> V_6 . V_131 , V_128 ) ;
if ( ! V_2 -> V_80 || ! V_2 -> V_129 )
goto exit;
V_82 = F_13 ( V_32 , V_136 ) ;
if ( V_32 -> V_137 == V_86 )
F_32 ( V_2 , V_82 ) ;
if ( V_32 -> V_137 == V_76 ) {
F_22 ( V_32 , V_34 , 0x0 ) ;
V_2 -> V_66 = 0 ;
F_21 ( V_2 ) ;
}
exit:
F_52 ( & V_2 -> V_6 . V_131 , V_128 ) ;
return;
}
static T_6 F_54 ( int V_124 , void * V_125 )
{
struct V_46 * V_47 = V_125 ;
T_5 V_82 , V_48 ;
V_82 = F_55 ( V_47 , V_138 ) ;
for ( V_48 = 0 ; V_48 < 6 ; V_48 ++ ) {
if ( V_82 & 0x1 )
F_53 ( & V_47 -> V_55 [ V_48 ] ) ;
V_82 >>= 1 ;
}
return V_132 ;
}
static unsigned int F_56 ( struct V_57 * V_6 )
{
struct V_1 * V_2 =
F_20 ( V_6 , struct V_1 , V_6 ) ;
unsigned long V_128 ;
unsigned int V_18 ;
F_51 ( & V_2 -> V_6 . V_131 , V_128 ) ;
V_18 = F_1 ( V_2 , V_26 ) & V_139 ? V_140 : 0 ;
F_52 ( & V_2 -> V_6 . V_131 , V_128 ) ;
return V_18 ;
}
static unsigned int F_57 ( struct V_57 * V_6 )
{
struct V_1 * V_2 =
F_20 ( V_6 , struct V_1 , V_6 ) ;
unsigned char V_91 ;
unsigned int V_18 ;
V_91 = F_1 ( V_2 , V_5 ) ;
V_18 = 0 ;
if ( V_91 & V_120 )
V_18 |= V_141 ;
if ( V_91 & V_142 )
V_18 |= V_143 ;
if ( V_91 & V_144 )
V_18 |= V_145 ;
if ( V_91 & V_122 )
V_18 |= V_146 ;
return V_18 ;
}
static void F_58 ( struct V_57 * V_6 , unsigned int V_147 )
{
struct V_1 * V_2 =
F_20 ( V_6 , struct V_1 , V_6 ) ;
unsigned char V_148 = 0 ;
if ( V_147 & V_149 )
V_148 |= V_150 ;
if ( V_147 & V_151 )
V_148 |= V_152 ;
if ( V_147 & V_153 )
V_148 |= V_154 ;
if ( V_147 & V_155 )
V_148 |= V_156 ;
if ( V_147 & V_157 )
V_148 |= V_158 ;
V_148 |= V_2 -> V_148 ;
F_4 ( V_2 , V_25 , V_148 ) ;
}
static void F_59 ( struct V_57 * V_6 , int V_159 )
{
struct V_1 * V_2 =
F_20 ( V_6 , struct V_1 , V_6 ) ;
unsigned long V_128 ;
F_51 ( & V_2 -> V_6 . V_131 , V_128 ) ;
if ( V_159 == - 1 )
V_2 -> V_160 |= V_161 ;
else
V_2 -> V_160 &= ~ V_161 ;
F_4 ( V_2 , V_24 , V_2 -> V_160 ) ;
F_52 ( & V_2 -> V_6 . V_131 , V_128 ) ;
}
static int F_60 ( struct V_57 * V_6 )
{
struct V_1 * V_2 =
F_20 ( V_6 , struct V_1 , V_6 ) ;
unsigned long V_128 ;
F_4 ( V_2 , V_162 , V_163 ) ;
F_4 ( V_2 , V_162 , V_163 |
V_164 | V_165 ) ;
F_4 ( V_2 , V_162 , 0 ) ;
( void ) F_1 ( V_2 , V_26 ) ;
( void ) F_1 ( V_2 , V_95 ) ;
( void ) F_1 ( V_2 , V_23 ) ;
( void ) F_1 ( V_2 , V_5 ) ;
F_4 ( V_2 , V_24 , V_166 ) ;
F_51 ( & V_2 -> V_6 . V_131 , V_128 ) ;
V_2 -> V_6 . V_147 |= V_155 ;
F_58 ( & V_2 -> V_6 , V_2 -> V_6 . V_147 ) ;
if ( ! V_2 -> V_80 )
V_2 -> V_58 = V_88 | V_167 | V_168 ;
else
V_2 -> V_58 = 0 ;
F_4 ( V_2 , V_22 , V_2 -> V_58 ) ;
F_52 ( & V_2 -> V_6 . V_131 , V_128 ) ;
if ( V_2 -> V_80 ) {
struct V_63 * V_64 ;
struct V_60 * V_61 = & V_6 -> V_62 -> V_61 ;
V_2 -> V_66 = 0 ;
V_64 = & V_2 -> V_83 ;
V_64 -> V_16 = F_9 ( V_169 , V_20 ) ;
if ( ! V_64 -> V_16 ) {
V_2 -> V_80 = 0 ;
goto exit;
}
V_64 -> V_74 = F_61 ( V_6 -> V_73 ,
V_64 -> V_16 ,
V_169 ,
V_86 ) ;
V_64 -> V_75 = V_169 ;
F_29 ( V_2 -> V_79 , V_64 ) ;
V_64 = & V_2 -> V_65 ;
V_64 -> V_16 = V_61 -> V_16 ;
V_64 -> V_74 = F_61 ( V_6 -> V_73 ,
V_64 -> V_16 ,
V_69 ,
V_76 ) ;
V_64 -> V_75 = V_69 ;
F_22 ( V_2 -> V_72 , V_36 , 32 ) ;
F_22 ( V_2 -> V_72 , V_37 , 4 ) ;
V_64 -> V_68 = 0 ;
}
exit:
( void ) F_1 ( V_2 , V_26 ) ;
( void ) F_1 ( V_2 , V_95 ) ;
( void ) F_1 ( V_2 , V_23 ) ;
( void ) F_1 ( V_2 , V_5 ) ;
V_2 -> V_129 = 1 ;
return 0 ;
}
static void F_62 ( struct V_57 * V_6 )
{
struct V_1 * V_2 =
F_20 ( V_6 , struct V_1 , V_6 ) ;
unsigned long V_128 ;
V_2 -> V_58 = 0 ;
F_4 ( V_2 , V_22 , 0 ) ;
V_2 -> V_129 = 0 ;
F_51 ( & V_2 -> V_6 . V_131 , V_128 ) ;
V_2 -> V_6 . V_147 &= ~ V_155 ;
F_58 ( & V_2 -> V_6 , V_2 -> V_6 . V_147 ) ;
F_52 ( & V_2 -> V_6 . V_131 , V_128 ) ;
F_4 ( V_2 , V_24 , F_1 ( V_2 , V_24 ) & ~ V_161 ) ;
F_4 ( V_2 , V_162 , V_163 |
V_164 |
V_165 ) ;
F_4 ( V_2 , V_162 , 0 ) ;
}
static void
F_63 ( struct V_57 * V_6 , struct V_170 * V_171 ,
struct V_170 * V_172 )
{
struct V_1 * V_2 =
F_20 ( V_6 , struct V_1 , V_6 ) ;
struct V_84 * V_85 = V_6 -> V_62 -> V_6 . V_85 ;
unsigned char V_173 , V_174 = 0 ;
unsigned long V_128 ;
unsigned int V_175 , V_176 ;
T_5 V_177 , V_178 ;
switch ( V_171 -> V_179 & V_180 ) {
case V_181 :
V_173 = V_182 ;
break;
case V_183 :
V_173 = V_184 ;
break;
case V_185 :
V_173 = V_186 ;
break;
default:
case V_187 :
V_173 = V_166 ;
break;
}
if ( V_85 )
V_85 -> V_171 -> V_179 &= ~ V_188 ;
if ( V_171 -> V_179 & V_189 )
V_173 |= V_190 ;
if ( V_171 -> V_179 & V_191 )
V_173 |= V_192 ;
if ( ! ( V_171 -> V_179 & V_193 ) )
V_173 |= V_194 ;
V_175 = F_64 ( V_6 , V_171 , V_172 , 0 , 4000000 ) ;
V_176 = 1 ;
V_177 = 0x10 ;
V_178 = 0x3600 ;
switch ( V_175 ) {
case 3500000 :
V_178 = 0x3345 ;
V_177 = 0xC ;
break;
case 1843200 :
V_178 = 0x2400 ;
break;
case 3000000 :
case 2500000 :
case 2000000 :
case 1500000 :
case 1000000 :
case 500000 :
V_178 = V_175 / 500000 * 0x9C4 ;
break;
default:
V_176 = 0 ;
}
if ( ! V_176 )
V_176 = F_65 ( V_6 , V_175 ) ;
if ( ( V_2 -> V_6 . V_195 / V_176 ) < ( 2400 * 16 ) )
V_174 = V_163 | V_196 ;
else if ( ( V_2 -> V_6 . V_195 / V_176 ) < ( 230400 * 16 ) )
V_174 = V_163 | V_197 ;
else
V_174 = V_163 | V_198 ;
V_174 |= V_199 ;
F_51 ( & V_2 -> V_6 . V_131 , V_128 ) ;
F_66 ( V_6 , V_171 -> V_179 , V_175 ) ;
V_2 -> V_6 . V_89 = V_100 | V_134 | V_90 ;
if ( V_171 -> V_200 & V_201 )
V_2 -> V_6 . V_89 |= V_99 | V_98 ;
if ( V_171 -> V_200 & ( V_202 | V_203 ) )
V_2 -> V_6 . V_89 |= V_97 ;
V_2 -> V_6 . V_204 = 0 ;
if ( V_171 -> V_200 & V_205 )
V_2 -> V_6 . V_204 |= V_98 | V_99 ;
if ( V_171 -> V_200 & V_206 ) {
V_2 -> V_6 . V_204 |= V_97 ;
if ( V_171 -> V_200 & V_205 )
V_2 -> V_6 . V_204 |= V_100 ;
}
if ( ( V_171 -> V_179 & V_207 ) == 0 )
V_2 -> V_6 . V_204 |= V_90 ;
V_2 -> V_58 &= ~ V_59 ;
if ( F_67 ( & V_2 -> V_6 , V_171 -> V_179 ) )
V_2 -> V_58 |= V_59 ;
F_4 ( V_2 , V_22 , V_2 -> V_58 ) ;
if ( V_171 -> V_179 & V_208 )
V_2 -> V_148 |= V_209 | V_150 ;
else
V_2 -> V_148 &= ~ V_209 ;
F_4 ( V_2 , V_24 , V_173 | V_210 ) ;
F_4 ( V_2 , V_211 , V_176 & 0xff ) ;
F_4 ( V_2 , V_212 , V_176 >> 8 ) ;
F_4 ( V_2 , V_24 , V_173 ) ;
F_4 ( V_2 , V_29 , V_178 ) ;
F_4 ( V_2 , V_28 , V_177 ) ;
V_2 -> V_160 = V_173 ;
F_58 ( & V_2 -> V_6 , V_2 -> V_6 . V_147 ) ;
F_4 ( V_2 , V_162 , V_174 ) ;
F_52 ( & V_2 -> V_6 . V_131 , V_128 ) ;
}
static void
F_68 ( struct V_57 * V_6 , unsigned int V_62 ,
unsigned int V_213 )
{
}
static void F_69 ( struct V_57 * V_6 )
{
}
static int F_70 ( struct V_57 * V_6 )
{
return 0 ;
}
static void F_71 ( struct V_57 * V_6 , int V_128 )
{
struct V_1 * V_2 =
F_20 ( V_6 , struct V_1 , V_6 ) ;
V_2 -> V_6 . type = V_214 ;
}
static int
F_72 ( struct V_57 * V_6 , struct V_215 * V_216 )
{
return - V_217 ;
}
static const char *
F_73 ( struct V_57 * V_6 )
{
struct V_1 * V_2 =
F_20 ( V_6 , struct V_1 , V_6 ) ;
return V_2 -> V_49 ;
}
static inline void F_74 ( struct V_1 * V_2 )
{
unsigned int V_91 , V_218 = 1000 ;
do {
V_91 = F_1 ( V_2 , V_26 ) ;
if ( V_91 & V_97 )
V_2 -> V_107 = V_97 ;
if ( -- V_218 == 0 )
break;
F_33 ( 1 ) ;
} while ( ! ( V_91 & V_219 ) );
if ( V_2 -> V_6 . V_128 & V_220 ) {
V_218 = 1000000 ;
while ( -- V_218 &&
( ( F_1 ( V_2 , V_5 ) & V_122 ) == 0 ) )
F_33 ( 1 ) ;
}
}
static void F_75 ( struct V_57 * V_6 , int V_92 )
{
struct V_1 * V_2 =
F_20 ( V_6 , struct V_1 , V_6 ) ;
F_74 ( V_2 ) ;
F_4 ( V_2 , V_112 , V_92 ) ;
}
static void
F_76 ( struct V_221 * V_222 , const char * V_223 , unsigned int V_14 )
{
struct V_1 * V_2 = V_224 [ V_222 -> V_21 ] ;
unsigned long V_128 ;
unsigned int V_58 ;
int V_225 = 1 ;
F_77 ( V_128 ) ;
if ( V_2 -> V_6 . V_226 )
V_225 = 0 ;
else if ( V_227 ) {
V_225 = F_78 ( & V_2 -> V_6 . V_131 ) ;
} else
F_79 ( & V_2 -> V_6 . V_131 ) ;
V_58 = F_1 ( V_2 , V_22 ) ;
F_4 ( V_2 , V_22 , 0 ) ;
F_80 ( & V_2 -> V_6 , V_223 , V_14 , F_75 ) ;
F_74 ( V_2 ) ;
F_4 ( V_2 , V_22 , V_58 ) ;
if ( V_225 )
F_81 ( & V_2 -> V_6 . V_131 ) ;
F_82 ( V_128 ) ;
}
static int T_7
F_83 ( struct V_221 * V_222 , char * V_228 )
{
struct V_1 * V_2 ;
int V_175 = 115200 ;
int V_229 = 8 ;
int V_103 = 'n' ;
int V_230 = 'n' ;
int V_18 ;
if ( V_222 -> V_21 == - 1 || V_222 -> V_21 >= V_231 . V_232 )
V_222 -> V_21 = 0 ;
V_2 = V_224 [ V_222 -> V_21 ] ;
if ( ! V_2 )
return - V_233 ;
if ( V_228 )
F_84 ( V_228 , & V_175 , & V_103 , & V_229 , & V_230 ) ;
V_18 = F_85 ( & V_2 -> V_6 , V_222 , V_175 , V_103 , V_229 , V_230 ) ;
return V_18 ;
}
static int F_86 ( struct V_234 * V_235 , T_8 V_62 )
{
void * V_236 = F_87 ( V_235 ) ;
struct V_1 * V_2 ;
if ( V_236 && ( V_235 -> V_237 != 0x081E ) ) {
V_2 = V_236 ;
F_88 ( & V_231 , & V_2 -> V_6 ) ;
}
F_89 ( V_235 ) ;
F_90 ( V_235 , F_91 ( V_235 , V_62 ) ) ;
return 0 ;
}
static int F_92 ( struct V_234 * V_235 )
{
void * V_236 = F_87 ( V_235 ) ;
struct V_1 * V_2 ;
int V_18 ;
F_90 ( V_235 , V_238 ) ;
F_93 ( V_235 ) ;
V_18 = F_94 ( V_235 ) ;
if ( V_18 )
F_40 ( & V_235 -> V_73 ,
L_26 ) ;
if ( V_236 && ( V_235 -> V_237 != 0x081E ) ) {
V_2 = V_236 ;
F_95 ( & V_231 , & V_2 -> V_6 ) ;
}
return 0 ;
}
static int F_96 ( struct V_234 * V_235 ,
const struct V_239 * V_240 )
{
struct V_1 * V_135 ;
int V_21 , V_18 ;
F_97 ( V_241 L_27 ,
V_235 -> V_242 , V_235 -> V_237 ) ;
switch ( V_235 -> V_237 ) {
case 0x081B :
V_21 = 0 ;
break;
case 0x081C :
V_21 = 1 ;
break;
case 0x081D :
V_21 = 2 ;
break;
case 0x081E :
V_21 = 3 ;
break;
default:
F_98 ( & V_235 -> V_73 , L_28 ) ;
return - V_233 ;
}
V_18 = F_94 ( V_235 ) ;
if ( V_18 )
return V_18 ;
if ( V_21 == 3 ) {
V_18 = F_99 ( V_235 -> V_124 , F_54 , 0 , L_29 , V_243 ) ;
if ( V_18 ) {
F_98 ( & V_235 -> V_73 , L_30 ) ;
goto V_244;
}
F_100 ( V_235 , V_243 ) ;
} else {
V_135 = & V_243 -> V_6 [ V_21 ] ;
V_135 -> V_6 . V_124 = V_235 -> V_124 ;
V_135 -> V_6 . V_73 = & V_235 -> V_73 ;
V_135 -> V_73 = & V_235 -> V_73 ;
V_18 = F_99 ( V_235 -> V_124 , F_50 , 0 , V_135 -> V_49 , V_135 ) ;
if ( V_18 ) {
F_98 ( & V_235 -> V_73 , L_30 ) ;
goto V_244;
}
F_101 ( & V_231 , & V_135 -> V_6 ) ;
#ifdef F_42
if ( V_21 == 2 ) {
F_102 ( & V_245 ) ;
V_135 -> V_6 . V_106 = & V_245 ;
}
#endif
F_100 ( V_235 , V_135 ) ;
}
return 0 ;
V_244:
F_103 ( V_235 ) ;
return V_18 ;
}
static void F_104 ( void )
{
struct V_46 * V_47 ;
struct V_1 * V_135 ;
struct V_31 * V_246 ;
int V_48 , V_18 ;
V_47 = F_9 ( sizeof( struct V_46 ) , V_20 ) ;
if ( ! V_47 )
return;
V_47 -> V_247 = 0xffa28000 ;
V_47 -> V_248 = 0x1000 ;
if ( ! ( F_105 ( V_47 -> V_247 , V_47 -> V_248 , L_31 ) ) )
F_106 ( L_32 ) ;
V_47 -> V_249 = F_107 ( ( unsigned long ) V_47 -> V_247 , V_47 -> V_248 ) ;
if ( ! V_47 -> V_249 ) {
F_108 ( L_33 ) ;
V_18 = - V_51 ;
goto V_250;
}
V_135 = V_47 -> V_6 ;
for ( V_48 = 0 ; V_48 < 3 ; V_48 ++ ) {
V_135 -> V_6 . type = V_214 ;
V_135 -> V_6 . V_251 = V_252 ;
V_135 -> V_6 . V_253 = ( V_254 ) V_47 -> V_247
+ V_255
+ V_48 * V_256 ;
V_135 -> V_6 . V_7 = V_47 -> V_249 + V_255
+ V_48 * V_256 ;
sprintf ( V_135 -> V_49 , L_34 , V_48 ) ;
V_135 -> V_6 . V_113 = 64 ;
V_135 -> V_6 . V_257 = & V_258 ;
V_135 -> V_6 . line = V_48 ;
V_135 -> V_6 . V_128 = V_259 ;
V_135 -> V_6 . V_195 = 115200 * 24 * 16 ;
V_135 -> V_129 = 0 ;
V_135 -> V_72 = & V_47 -> V_55 [ V_48 * 2 ] ;
V_135 -> V_79 = & V_47 -> V_55 [ V_48 * 2 + 1 ] ;
V_224 [ V_48 ] = V_135 ;
V_135 -> V_21 = V_48 ;
if ( V_260 & ( 1 << V_48 ) )
V_135 -> V_80 = 1 ;
else
V_135 -> V_80 = 0 ;
V_135 ++ ;
}
V_246 = V_47 -> V_55 ;
for ( V_48 = 0 ; V_48 < 6 ; V_48 ++ ) {
V_246 -> V_33 = V_48 ;
V_246 -> V_137 = ( V_48 & 0x1 ) ? V_86 : V_76 ;
V_246 -> V_135 = & V_47 -> V_6 [ V_48 / 2 ] ;
V_246 -> V_249 = V_47 -> V_249 + V_261 +
V_48 * V_262 ;
V_246 ++ ;
}
V_243 = V_47 ;
F_14 ( V_47 ) ;
return;
V_250:
F_109 ( V_47 -> V_247 , V_47 -> V_248 ) ;
F_11 ( V_47 ) ;
return;
}
static void F_110 ( struct V_234 * V_235 )
{
void * V_236 = F_87 ( V_235 ) ;
struct V_1 * V_2 ;
if ( ! V_236 )
return;
if ( V_235 -> V_237 != 0x081E ) {
V_2 = V_236 ;
F_111 ( & V_231 , & V_2 -> V_6 ) ;
}
F_100 ( V_235 , NULL ) ;
F_112 ( V_235 -> V_124 , V_236 ) ;
F_103 ( V_235 ) ;
}
static int T_7 F_113 ( void )
{
int V_18 ;
F_104 () ;
V_18 = F_114 ( & V_231 ) ;
if ( V_18 )
return V_18 ;
return F_115 ( & V_263 ) ;
}
static void T_9 F_116 ( void )
{
F_117 ( & V_263 ) ;
F_118 ( & V_231 ) ;
F_17 ( V_243 ) ;
F_11 ( V_243 ) ;
}

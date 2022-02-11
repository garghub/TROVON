static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
if ( V_2 -> V_4 )
return F_2 ( V_2 -> V_4 , V_3 ) ;
return V_3 ;
}
static void F_3 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 || ! V_2 -> V_6 )
return;
F_4 ( V_2 -> V_6 , V_2 -> V_5 ) ;
V_2 -> V_5 = 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_7 ,
T_1 V_8 , int V_9 , int V_10 , int V_11 )
{
T_1 V_12 ;
T_1 V_13 ;
int V_14 = 10 ;
V_12 = ( 1ULL << V_10 ) - 1 ;
V_12 = ( V_12 << V_9 ) ;
while ( V_14 ) {
V_13 = F_6 ( V_2 , V_8 , V_7 ) ;
if ( ( ( V_13 & V_12 ) >> V_9 ) == V_11 )
return 0 ;
F_7 ( 1000 , 2000 ) ;
V_14 -- ;
}
F_8 ( V_2 -> V_15 , L_1 , V_8 ) ;
return 1 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_16 * V_17 ,
int V_18 , int V_19 , int V_20 )
{
V_17 -> V_18 = V_18 ;
V_17 -> V_21 = ( V_19 * V_18 ) + V_20 ;
V_17 -> V_22 = F_10 ( & V_2 -> V_23 -> V_24 , V_17 -> V_21 ,
& V_17 -> V_25 , V_26 ) ;
if ( ! V_17 -> V_22 )
return - V_27 ;
V_17 -> V_28 = F_11 ( ( T_1 ) V_17 -> V_25 , V_20 ) ;
V_17 -> V_29 = V_17 -> V_22 + ( V_17 -> V_28 - V_17 -> V_25 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
if ( ! V_17 )
return;
F_13 ( & V_2 -> V_23 -> V_24 , V_17 -> V_21 ,
V_17 -> V_22 , V_17 -> V_25 ) ;
V_17 -> V_22 = NULL ;
V_17 -> V_29 = NULL ;
}
static inline int F_14 ( struct V_1 * V_2 , T_3 V_30 ,
T_4 V_31 , T_1 * * V_32 )
{
int V_33 = V_34 ;
if ( V_2 -> V_6 &&
( ( V_2 -> V_35 + V_31 ) < ( V_36 << V_33 ) ) ) {
V_2 -> V_5 ++ ;
goto V_37;
}
F_3 ( V_2 ) ;
V_2 -> V_6 = F_15 ( V_30 | V_38 | V_39 ,
V_33 ) ;
if ( ! V_2 -> V_6 ) {
F_16 ( V_2 -> V_40 -> V_41 -> V_42 ) ;
return - V_27 ;
}
V_2 -> V_35 = 0 ;
V_37:
* V_32 = ( T_1 * ) ( ( T_1 ) F_17 ( & V_2 -> V_23 -> V_24 , V_2 -> V_6 ,
V_2 -> V_35 , V_31 ,
V_43 ,
V_44 ) ) ;
if ( F_18 ( & V_2 -> V_23 -> V_24 , ( T_2 ) * V_32 ) ) {
if ( ! V_2 -> V_35 )
F_19 ( V_2 -> V_6 , V_33 ) ;
V_2 -> V_6 = NULL ;
return - V_27 ;
}
V_2 -> V_35 += V_31 ;
return 0 ;
}
static struct V_45 * F_20 ( struct V_1 * V_2 ,
T_1 V_46 , int V_47 )
{
void * V_48 ;
struct V_45 * V_49 ;
V_48 = F_21 ( V_46 ) ;
V_49 = F_22 ( V_48 , V_50 ) ;
if ( ! V_49 ) {
F_23 ( F_24 ( V_48 ) ) ;
return NULL ;
}
F_25 ( V_49 -> V_48 ) ;
return V_49 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_51 * V_51 ,
int V_52 , int V_53 )
{
int V_54 ;
T_1 * V_32 ;
struct V_55 * V_56 ;
int V_57 ;
V_57 = F_9 ( V_2 , & V_51 -> V_17 , V_52 ,
sizeof( struct V_55 ) ,
V_58 ) ;
if ( V_57 )
return V_57 ;
V_51 -> V_56 = V_51 -> V_17 . V_29 ;
V_51 -> V_59 = V_53 ;
V_51 -> V_60 = true ;
V_51 -> V_61 = V_62 ;
V_51 -> V_63 = 0 ;
V_51 -> V_64 = 0 ;
V_2 -> V_6 = NULL ;
for ( V_54 = 0 ; V_54 < V_52 ; V_54 ++ ) {
V_57 = F_14 ( V_2 , V_26 , V_50 ,
& V_32 ) ;
if ( V_57 ) {
V_51 -> V_64 = V_54 - 1 ;
return V_57 ;
}
V_56 = F_27 ( V_51 , V_54 ) ;
V_56 -> V_65 = ( T_1 ) V_32 >> V_66 ;
}
F_3 ( V_2 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 , struct V_51 * V_51 )
{
int V_63 , V_64 ;
T_1 V_65 , V_67 ;
struct V_55 * V_56 ;
if ( ! V_51 )
return;
V_51 -> V_60 = false ;
if ( ! V_51 -> V_17 . V_29 )
return;
V_63 = V_51 -> V_63 ;
V_64 = V_51 -> V_64 ;
while ( V_63 != V_64 ) {
V_56 = F_27 ( V_51 , V_63 ) ;
V_65 = ( ( T_1 ) V_56 -> V_65 ) << V_66 ;
V_67 = F_1 ( V_2 , V_65 ) ;
F_29 ( & V_2 -> V_23 -> V_24 , V_65 , V_50 ,
V_43 , V_44 ) ;
if ( V_67 )
F_23 ( F_24 ( F_21 ( V_67 ) ) ) ;
V_63 ++ ;
V_63 &= ( V_51 -> V_17 . V_18 - 1 ) ;
}
V_56 = F_27 ( V_51 , V_64 ) ;
V_65 = ( ( T_1 ) V_56 -> V_65 ) << V_66 ;
V_67 = F_1 ( V_2 , V_65 ) ;
F_29 ( & V_2 -> V_23 -> V_24 , V_65 , V_50 ,
V_43 , V_44 ) ;
if ( V_67 )
F_23 ( F_24 ( F_21 ( V_67 ) ) ) ;
F_12 ( V_2 , & V_51 -> V_17 ) ;
}
static void F_30 ( struct V_1 * V_2 , T_3 V_30 )
{
struct V_68 * V_69 = V_2 -> V_69 ;
int V_70 = V_69 -> V_71 ;
int V_64 , V_72 ;
int V_73 ;
struct V_51 * V_51 ;
struct V_55 * V_56 ;
T_1 * V_32 ;
int V_74 = 0 ;
V_75:
if ( ! V_70 )
return;
V_70 -- ;
V_51 = & V_69 -> V_51 [ V_70 ] ;
if ( ! V_51 -> V_60 )
goto V_76;
V_72 = F_6 ( V_2 , V_77 , V_70 ) ;
V_72 &= 0x7FFFF ;
if ( V_72 >= ( V_69 -> V_78 - 1 ) )
goto V_76;
else
V_73 = V_69 -> V_78 - V_72 - 1 ;
V_64 = F_6 ( V_2 , V_79 , V_70 ) >> 3 ;
while ( V_73 ) {
V_64 ++ ;
V_64 &= ( V_51 -> V_17 . V_18 - 1 ) ;
if ( F_14 ( V_2 , V_30 , V_50 , & V_32 ) )
break;
V_56 = F_27 ( V_51 , V_64 ) ;
V_56 -> V_65 = ( T_1 ) V_32 >> V_66 ;
V_73 -- ;
V_74 ++ ;
}
F_3 ( V_2 ) ;
F_31 () ;
if ( V_73 )
V_2 -> V_80 = true ;
else
V_2 -> V_80 = false ;
F_32 ( V_2 , V_81 ,
V_70 , V_74 ) ;
V_76:
if ( ! V_2 -> V_80 && V_51 -> V_60 &&
F_33 ( V_2 -> V_40 -> V_15 ) )
F_34 ( V_2 , V_82 , V_70 ) ;
if ( V_70 )
goto V_75;
}
void F_35 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_36 ( V_84 , struct V_1 , V_85 . V_84 ) ;
F_30 ( V_2 , V_26 ) ;
if ( V_2 -> V_80 )
F_37 ( & V_2 -> V_85 , F_38 ( 10 ) ) ;
else
V_2 -> V_86 = false ;
}
void F_39 ( unsigned long V_48 )
{
struct V_1 * V_2 = (struct V_1 * ) V_48 ;
F_30 ( V_2 , V_87 ) ;
if ( V_2 -> V_80 ) {
V_2 -> V_86 = true ;
F_37 ( & V_2 -> V_85 , F_38 ( 10 ) ) ;
}
}
static int F_40 ( struct V_1 * V_2 ,
struct V_88 * V_89 , int V_18 )
{
int V_57 ;
V_57 = F_9 ( V_2 , & V_89 -> V_17 , V_18 , V_90 ,
V_91 ) ;
if ( V_57 )
return V_57 ;
V_89 -> V_56 = V_89 -> V_17 . V_29 ;
V_89 -> V_61 = F_41 ( V_2 -> V_23 ) ? 0 : V_92 ;
V_2 -> V_93 = ( V_94 * 0.05 ) - 1 ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 , struct V_88 * V_89 )
{
if ( ! V_89 )
return;
if ( ! V_89 -> V_17 . V_29 )
return;
F_12 ( V_2 , & V_89 -> V_17 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_95 * V_96 , int V_18 )
{
int V_57 ;
V_57 = F_9 ( V_2 , & V_96 -> V_17 , V_18 , V_97 ,
V_98 ) ;
if ( V_57 )
return V_57 ;
V_96 -> V_56 = V_96 -> V_17 . V_29 ;
V_96 -> V_99 = F_44 ( V_18 , sizeof( T_1 ) , V_26 ) ;
if ( ! V_96 -> V_99 )
return - V_27 ;
V_96 -> V_63 = 0 ;
V_96 -> V_64 = 0 ;
F_45 ( & V_96 -> V_100 , V_18 - 1 ) ;
V_96 -> V_61 = V_101 ;
V_96 -> V_102 = F_46 ( & V_2 -> V_23 -> V_24 ,
V_18 * V_103 ,
& V_96 -> V_104 , V_26 ) ;
if ( ! V_96 -> V_102 )
return - V_27 ;
return 0 ;
}
void F_47 ( struct V_1 * V_2 , struct V_95 * V_96 ,
int V_105 , T_5 V_106 )
{
T_5 V_54 ;
struct V_107 * V_108 ;
for ( V_54 = 0 ; V_54 < V_106 ; V_54 ++ ) {
V_105 ++ ;
V_105 &= ( V_96 -> V_17 . V_18 - 1 ) ;
V_108 = (struct V_107 * ) F_48 ( V_96 , V_105 ) ;
F_29 ( & V_2 -> V_23 -> V_24 , V_108 -> V_109 ,
V_108 -> V_21 , V_110 ,
V_44 ) ;
}
}
static void F_49 ( struct V_1 * V_2 , struct V_95 * V_96 )
{
struct V_45 * V_49 ;
struct V_111 * V_112 ;
struct V_111 * V_113 ;
if ( ! V_96 )
return;
if ( ! V_96 -> V_17 . V_29 )
return;
if ( V_96 -> V_102 )
F_13 ( & V_2 -> V_23 -> V_24 ,
V_96 -> V_17 . V_18 * V_103 ,
V_96 -> V_102 , V_96 -> V_104 ) ;
F_50 () ;
while ( V_96 -> V_63 != V_96 -> V_64 ) {
V_49 = (struct V_45 * ) V_96 -> V_99 [ V_96 -> V_63 ] ;
if ( ! V_49 )
goto V_114;
V_112 = (struct V_111 * ) F_48 ( V_96 , V_96 -> V_63 ) ;
if ( V_112 -> V_115 ) {
V_113 =
(struct V_111 * ) F_48 ( V_96 , V_112 -> V_116 ) ;
F_47 ( V_2 , V_96 , V_112 -> V_116 ,
V_113 -> V_106 ) ;
} else {
F_47 ( V_2 , V_96 , V_96 -> V_63 ,
V_112 -> V_106 ) ;
}
F_51 ( V_49 ) ;
V_114:
V_96 -> V_63 ++ ;
V_96 -> V_63 &= ( V_96 -> V_17 . V_18 - 1 ) ;
}
F_52 ( V_96 -> V_99 ) ;
F_12 ( V_2 , & V_96 -> V_17 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_68 * V_69 , int V_7 )
{
F_32 ( V_2 , V_117 , V_7 , 0 ) ;
if ( F_5 ( V_2 , V_7 , V_118 , 21 , 1 , 0x01 ) )
return;
F_32 ( V_2 , V_117 , V_7 , V_119 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_68 * V_69 , int V_7 )
{
union V_120 V_121 = {} ;
V_121 . V_122 . V_122 = V_123 ;
F_55 ( V_2 , & V_121 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_68 * V_69 , int V_7 )
{
F_32 ( V_2 , V_124 , V_7 , 0 ) ;
F_32 ( V_2 , V_125 , V_7 , 0 ) ;
F_32 ( V_2 , V_125 , V_7 , V_126 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_51 * V_51 , int V_7 )
{
T_1 V_127 , V_128 ;
int V_14 = 10 ;
V_51 -> V_63 = F_6 ( V_2 ,
V_129 ,
V_7 ) >> 3 ;
V_51 -> V_64 = F_6 ( V_2 ,
V_79 ,
V_7 ) >> 3 ;
V_128 = F_6 ( V_2 , V_77 , V_7 ) ;
if ( ( ( V_128 >> 62 ) & 0x03 ) == 0x3 )
F_32 ( V_2 , V_130 ,
V_7 , V_131 ) ;
F_32 ( V_2 , V_130 , V_7 , 0 ) ;
if ( F_5 ( V_2 , V_7 , V_77 , 62 , 2 , 0x00 ) )
return;
while ( 1 ) {
V_127 = F_6 ( V_2 ,
V_132 ,
V_7 ) ;
if ( ( V_127 & 0xFFFFFFFF ) == ( ( V_127 >> 32 ) & 0xFFFFFFFF ) )
break;
F_7 ( 1000 , 2000 ) ;
V_14 -- ;
if ( ! V_14 ) {
F_8 ( V_2 -> V_15 ,
L_2 ) ;
return;
}
}
F_32 ( V_2 , V_130 ,
V_7 , V_131 ) ;
if ( F_5 ( V_2 , V_7 , V_77 , 62 , 2 , 0x02 ) )
return;
F_32 ( V_2 , V_130 , V_7 , 0x00 ) ;
if ( F_5 ( V_2 , V_7 , V_77 , 62 , 2 , 0x00 ) )
return;
}
void F_58 ( struct V_1 * V_2 , T_6 V_133 )
{
T_1 V_134 ;
int V_135 ;
V_134 = F_6 ( V_2 , V_136 , 0 ) ;
if ( V_133 & V_137 )
V_134 |= ( 1ULL << 25 ) ;
else
V_134 &= ~ ( 1ULL << 25 ) ;
F_32 ( V_2 , V_136 , 0 , V_134 ) ;
for ( V_135 = 0 ; V_135 < V_2 -> V_138 ; V_135 ++ )
if ( V_2 -> V_139 [ V_135 ] )
F_32 ( V_2 -> V_139 [ V_135 ] ,
V_136 , 0 , V_134 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
union V_120 V_121 = {} ;
V_121 . V_140 . V_122 = V_141 ;
V_121 . V_140 . V_142 = 0x3FFF ;
V_121 . V_140 . V_143 = 0x1F ;
V_121 . V_140 . V_144 = 0xFFFF ;
V_121 . V_140 . V_145 = 0xFFFF ;
F_55 ( V_2 , & V_121 ) ;
}
static void F_60 ( struct V_1 * V_2 , struct V_68 * V_69 ,
int V_7 , bool V_60 )
{
union V_120 V_121 = {} ;
struct V_146 * V_147 ;
struct V_134 V_134 ;
V_147 = & V_69 -> V_147 [ V_7 ] ;
V_147 -> V_60 = V_60 ;
F_32 ( V_2 , V_148 , V_7 , 0 ) ;
if ( ! V_147 -> V_60 ) {
F_54 ( V_2 , V_69 , V_7 ) ;
return;
}
V_147 -> V_149 = V_69 -> V_150 ;
V_147 -> V_151 = V_7 ;
V_147 -> V_152 = V_69 -> V_150 ;
V_147 -> V_153 = V_69 -> V_71 - 1 ;
V_147 -> V_154 = V_69 -> V_150 ;
V_147 -> V_155 = V_69 -> V_71 - 1 ;
V_147 -> V_156 = 1 ;
V_121 . V_147 . V_122 = V_157 ;
V_121 . V_147 . V_158 = V_69 -> V_150 ;
V_121 . V_147 . V_159 = V_7 ;
V_121 . V_147 . V_160 = ( V_147 -> V_156 << 26 ) | ( V_147 -> V_149 << 19 ) |
( V_147 -> V_151 << 16 ) | ( V_147 -> V_154 << 9 ) |
( V_147 -> V_155 << 8 ) |
( V_147 -> V_152 << 1 ) | ( V_147 -> V_153 ) ;
F_55 ( V_2 , & V_121 ) ;
V_121 . V_147 . V_122 = V_161 ;
V_121 . V_147 . V_160 = F_61 ( 63 ) | F_61 ( 62 ) |
( V_162 << 16 ) | ( V_163 << 8 ) |
( V_69 -> V_150 << 0 ) ;
F_55 ( V_2 , & V_121 ) ;
V_121 . V_147 . V_122 = V_164 ;
V_121 . V_147 . V_160 = F_61 ( 63 ) | F_61 ( 62 ) |
( V_162 << 40 ) | ( V_165 << 32 ) |
( V_163 << 16 ) | ( V_166 << 8 ) ;
F_55 ( V_2 , & V_121 ) ;
if ( ! V_2 -> V_167 && ( V_7 == 0 ) ) {
F_32 ( V_2 , V_136 , 0 ,
( F_62 ( 24 ) | F_62 ( 23 ) | F_62 ( 21 ) | F_62 ( 20 ) ) ) ;
F_58 ( V_2 , V_2 -> V_15 -> V_133 ) ;
}
memset ( & V_134 , 0 , sizeof( struct V_134 ) ) ;
V_134 . V_168 = 1 ;
V_134 . V_169 = 0 ;
F_32 ( V_2 , V_148 , V_7 , * ( T_1 * ) & V_134 ) ;
}
void F_63 ( struct V_1 * V_2 , struct V_68 * V_69 ,
int V_7 , bool V_60 )
{
struct V_88 * V_89 ;
struct V_170 V_170 ;
V_89 = & V_69 -> V_89 [ V_7 ] ;
V_89 -> V_60 = V_60 ;
if ( ! V_89 -> V_60 ) {
F_56 ( V_2 , V_69 , V_7 ) ;
return;
}
F_32 ( V_2 , V_125 , V_7 , V_126 ) ;
if ( ! V_89 -> V_60 )
return;
F_64 ( & V_89 -> V_171 ) ;
F_32 ( V_2 , V_172 ,
V_7 , ( T_1 ) ( V_89 -> V_17 . V_28 ) ) ;
memset ( & V_170 , 0 , sizeof( struct V_170 ) ) ;
V_170 . V_168 = 1 ;
V_170 . V_173 = 0 ;
V_170 . V_156 = 0 ;
V_170 . V_174 = F_65 ( V_69 -> V_175 >> 10 ) ;
V_170 . V_176 = 0 ;
F_32 ( V_2 , V_125 , V_7 , * ( T_1 * ) & V_170 ) ;
F_32 ( V_2 , V_177 , V_7 , V_89 -> V_61 ) ;
F_32 ( V_2 , V_124 ,
V_7 , V_94 ) ;
}
static void F_66 ( struct V_1 * V_2 , struct V_68 * V_69 ,
int V_7 , bool V_60 )
{
union V_120 V_121 = {} ;
struct V_95 * V_96 ;
struct V_178 V_178 ;
V_96 = & V_69 -> V_96 [ V_7 ] ;
V_96 -> V_60 = V_60 ;
if ( ! V_96 -> V_60 ) {
F_53 ( V_2 , V_69 , V_7 ) ;
return;
}
F_32 ( V_2 , V_117 , V_7 , V_119 ) ;
V_96 -> V_149 = V_69 -> V_150 ;
V_96 -> V_151 = V_7 ;
V_121 . V_96 . V_122 = V_179 ;
V_121 . V_96 . V_158 = V_69 -> V_150 ;
V_121 . V_96 . V_180 = V_7 ;
V_121 . V_96 . V_167 = V_2 -> V_167 ;
V_121 . V_96 . V_160 = ( V_96 -> V_149 << 3 ) | V_96 -> V_151 ;
F_55 ( V_2 , & V_121 ) ;
F_32 ( V_2 , V_181 ,
V_7 , ( T_1 ) ( V_96 -> V_17 . V_28 ) ) ;
memset ( & V_178 , 0 , sizeof( struct V_178 ) ) ;
V_178 . V_168 = 1 ;
V_178 . V_173 = 0 ;
V_178 . V_182 = 0 ;
V_178 . V_174 = F_65 ( V_69 -> V_183 >> 10 ) ;
V_178 . V_184 = 0 ;
V_178 . V_185 = ( V_186 * 256 ) / V_69 -> V_175 ;
F_32 ( V_2 , V_117 , V_7 , * ( T_1 * ) & V_178 ) ;
F_32 ( V_2 , V_187 , V_7 , V_96 -> V_61 ) ;
if ( F_67 ( V_7 ) ) {
F_68 ( V_7 , & V_96 -> V_188 ) ;
F_69 ( V_2 -> V_15 ,
& V_96 -> V_188 , V_7 ) ;
}
}
static void F_70 ( struct V_1 * V_2 , struct V_68 * V_69 ,
int V_7 , bool V_60 )
{
struct V_51 * V_51 ;
struct V_189 V_189 ;
V_51 = & V_69 -> V_51 [ V_7 ] ;
F_57 ( V_2 , V_51 , V_7 ) ;
if ( ! V_60 )
return;
F_32 ( V_2 , V_190 ,
V_7 , ( T_1 ) ( V_51 -> V_17 . V_28 ) ) ;
memset ( & V_189 , 0 , sizeof( struct V_189 ) ) ;
V_189 . V_168 = 1 ;
V_189 . V_173 = 0 ;
V_189 . V_182 = 0 ;
V_189 . V_174 = V_191 ;
V_189 . V_176 = 0 ;
V_189 . V_192 = V_51 -> V_59 / 128 ;
F_32 ( V_2 , V_130 ,
V_7 , * ( T_1 * ) & V_189 ) ;
F_32 ( V_2 , V_81 ,
V_7 , V_69 -> V_78 - 1 ) ;
F_32 ( V_2 , V_193 ,
V_7 , V_51 -> V_61 - 1 ) ;
}
void F_71 ( struct V_1 * V_2 , bool V_60 )
{
union V_120 V_121 = {} ;
struct V_68 * V_69 = V_2 -> V_69 ;
struct V_194 * V_194 ;
if ( ! V_69 ) {
F_72 ( V_2 -> V_15 ,
L_3 ) ;
return;
}
V_69 -> V_60 = V_60 ;
V_69 -> V_150 = V_2 -> V_195 ;
V_121 . V_69 . V_122 = V_196 ;
V_121 . V_69 . V_197 = V_69 -> V_150 ;
V_121 . V_69 . V_138 = V_2 -> V_138 ;
V_121 . V_69 . V_160 = 0 ;
V_194 = (struct V_194 * ) & V_121 . V_69 . V_160 ;
if ( V_69 -> V_60 ) {
V_194 -> V_168 = 1 ;
#ifdef F_73
V_194 -> V_198 = 1 ;
#endif
V_194 -> V_199 = V_69 -> V_150 ;
}
F_55 ( V_2 , & V_121 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
int V_7 ;
struct V_68 * V_69 = V_2 -> V_69 ;
for ( V_7 = 0 ; V_7 < V_69 -> V_71 ; V_7 ++ )
F_28 ( V_2 , & V_69 -> V_51 [ V_7 ] ) ;
for ( V_7 = 0 ; V_7 < V_69 -> V_200 ; V_7 ++ )
F_42 ( V_2 , & V_69 -> V_89 [ V_7 ] ) ;
for ( V_7 = 0 ; V_7 < V_69 -> V_201 ; V_7 ++ )
F_49 ( V_2 , & V_69 -> V_96 [ V_7 ] ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_7 ;
struct V_68 * V_69 = V_2 -> V_69 ;
for ( V_7 = 0 ; V_7 < V_69 -> V_71 ; V_7 ++ ) {
if ( F_26 ( V_2 , & V_69 -> V_51 [ V_7 ] , V_69 -> V_78 ,
V_202 ) )
goto V_203;
}
for ( V_7 = 0 ; V_7 < V_69 -> V_201 ; V_7 ++ ) {
if ( F_43 ( V_2 , & V_69 -> V_96 [ V_7 ] , V_69 -> V_183 ) )
goto V_203;
}
for ( V_7 = 0 ; V_7 < V_69 -> V_200 ; V_7 ++ ) {
if ( F_40 ( V_2 , & V_69 -> V_89 [ V_7 ] , V_69 -> V_175 ) )
goto V_203;
}
return 0 ;
V_203:
F_74 ( V_2 ) ;
return - V_27 ;
}
int F_76 ( struct V_1 * V_2 )
{
struct V_68 * V_69 ;
V_69 = F_77 ( & V_2 -> V_23 -> V_24 , sizeof( * V_69 ) , V_26 ) ;
if ( ! V_69 )
return - V_27 ;
V_2 -> V_69 = V_69 ;
V_69 -> V_71 = V_204 ;
V_69 -> V_205 = F_78 ( T_5 , V_206 , F_79 () ) ;
V_69 -> V_201 = F_78 ( T_5 , V_207 , F_79 () ) ;
V_69 -> V_200 = F_80 ( T_5 , V_69 -> V_205 , V_69 -> V_201 ) ;
V_69 -> V_78 = V_208 ;
V_69 -> V_183 = V_209 ;
V_69 -> V_175 = V_210 ;
V_2 -> V_211 = V_69 -> V_205 ;
V_2 -> V_212 = V_69 -> V_201 ;
return 0 ;
}
int F_81 ( struct V_1 * V_2 , bool V_60 )
{
bool V_213 = false ;
struct V_68 * V_69 = V_2 -> V_69 ;
struct V_68 * V_214 = V_2 -> V_40 -> V_69 ;
int V_7 ;
if ( ! V_69 )
return 0 ;
if ( V_2 -> V_167 && V_214 ) {
V_69 -> V_175 = V_214 -> V_175 ;
V_69 -> V_183 = V_214 -> V_183 ;
}
if ( V_60 ) {
if ( F_75 ( V_2 ) )
return - V_27 ;
for ( V_7 = 0 ; V_7 < V_69 -> V_201 ; V_7 ++ )
F_66 ( V_2 , V_69 , V_7 , V_60 ) ;
for ( V_7 = 0 ; V_7 < V_69 -> V_200 ; V_7 ++ )
F_63 ( V_2 , V_69 , V_7 , V_60 ) ;
for ( V_7 = 0 ; V_7 < V_69 -> V_71 ; V_7 ++ )
F_70 ( V_2 , V_69 , V_7 , V_60 ) ;
for ( V_7 = 0 ; V_7 < V_69 -> V_205 ; V_7 ++ )
F_60 ( V_2 , V_69 , V_7 , V_60 ) ;
} else {
for ( V_7 = 0 ; V_7 < V_69 -> V_205 ; V_7 ++ )
F_60 ( V_2 , V_69 , V_7 , V_213 ) ;
for ( V_7 = 0 ; V_7 < V_69 -> V_71 ; V_7 ++ )
F_70 ( V_2 , V_69 , V_7 , V_213 ) ;
for ( V_7 = 0 ; V_7 < V_69 -> V_201 ; V_7 ++ )
F_66 ( V_2 , V_69 , V_7 , V_213 ) ;
for ( V_7 = 0 ; V_7 < V_69 -> V_200 ; V_7 ++ )
F_63 ( V_2 , V_69 , V_7 , V_213 ) ;
F_74 ( V_2 ) ;
}
F_59 ( V_2 ) ;
return 0 ;
}
static inline int F_82 ( struct V_95 * V_96 , int V_215 )
{
int V_216 ;
V_216 = V_96 -> V_64 ;
F_83 ( V_215 , & V_96 -> V_100 ) ;
V_96 -> V_64 += V_215 ;
V_96 -> V_64 &= ( V_96 -> V_17 . V_18 - 1 ) ;
return V_216 ;
}
static inline void F_84 ( struct V_95 * V_96 ,
int V_216 , int V_215 )
{
V_96 -> V_64 = V_216 ;
F_85 ( V_215 , & V_96 -> V_100 ) ;
}
void F_86 ( struct V_95 * V_96 , int V_215 )
{
F_85 ( V_215 , & V_96 -> V_100 ) ;
V_96 -> V_63 += V_215 ;
V_96 -> V_63 &= ( V_96 -> V_17 . V_18 - 1 ) ;
}
static inline int F_87 ( struct V_95 * V_96 , int V_216 )
{
V_216 ++ ;
V_216 &= ( V_96 -> V_17 . V_18 - 1 ) ;
return V_216 ;
}
void F_88 ( struct V_1 * V_2 , struct V_95 * V_96 , int V_7 )
{
T_1 V_178 ;
V_178 = F_6 ( V_2 , V_117 , V_7 ) ;
V_178 |= V_217 ;
F_32 ( V_2 , V_117 , V_7 , V_178 ) ;
F_32 ( V_2 , V_218 , V_7 , 0 ) ;
}
void F_89 ( struct V_1 * V_2 , int V_7 )
{
T_1 V_178 ;
V_178 = F_6 ( V_2 , V_117 , V_7 ) ;
V_178 &= ~ V_217 ;
F_32 ( V_2 , V_117 , V_7 , V_178 ) ;
}
void F_90 ( struct V_219 * V_15 , struct V_95 * V_96 ,
int V_7 )
{
T_1 V_63 , V_64 ;
struct V_45 * V_49 ;
struct V_1 * V_2 = F_91 ( V_15 ) ;
struct V_111 * V_112 ;
V_63 = F_6 ( V_2 , V_220 , V_7 ) >> 4 ;
V_64 = F_6 ( V_2 , V_221 , V_7 ) >> 4 ;
while ( V_96 -> V_63 != V_63 ) {
V_112 = (struct V_111 * ) F_48 ( V_96 , V_96 -> V_63 ) ;
if ( V_112 -> V_222 != V_223 ) {
F_86 ( V_96 , 1 ) ;
continue;
}
V_49 = (struct V_45 * ) V_96 -> V_99 [ V_96 -> V_63 ] ;
if ( V_49 )
F_51 ( V_49 ) ;
F_92 ( 1 , ( V_224 * ) & V_15 -> V_225 . V_226 ) ;
F_92 ( V_112 -> V_227 ,
( V_224 * ) & V_15 -> V_225 . V_228 ) ;
F_86 ( V_96 , V_112 -> V_106 + 1 ) ;
}
}
static int F_93 ( struct V_45 * V_49 )
{
struct V_229 * V_230 = F_94 ( V_49 ) ;
unsigned int V_231 = F_95 ( V_49 ) + F_96 ( V_49 ) ;
unsigned int V_232 = V_49 -> V_47 - V_231 ;
unsigned int V_233 = V_230 -> V_234 ;
long V_235 = - 1 ;
long V_236 = F_97 ( V_49 ) - V_231 ;
long V_237 = 0 ;
long V_238 ;
int V_239 = 0 ;
int V_240 ;
for ( V_240 = 0 ; V_240 < V_230 -> V_241 ; V_240 ++ ) {
unsigned int V_242 = 0 ;
for ( V_239 ++ ; V_242 < V_233 ; V_239 ++ ) {
while ( V_237 >= V_236 ) {
V_235 ++ ;
V_236 = F_98 ( & V_230 -> V_243 [ V_235 ] ) ;
V_237 = 0 ;
}
V_238 = V_233 - V_242 ;
if ( V_238 > V_236 - V_237 )
V_238 = V_236 - V_237 ;
V_237 += V_238 ;
V_242 += V_238 ;
}
V_232 -= V_233 ;
if ( V_232 < V_233 )
V_233 = V_232 ;
}
return V_239 + V_230 -> V_241 ;
}
static int F_99 ( struct V_1 * V_2 , struct V_45 * V_49 )
{
int V_106 = V_244 ;
if ( F_94 ( V_49 ) -> V_234 && ! V_2 -> V_245 ) {
V_106 = F_93 ( V_49 ) ;
return V_106 ;
}
if ( V_2 -> V_246 && V_2 -> V_245 && F_94 ( V_49 ) -> V_234 )
V_106 += V_247 ;
if ( F_94 ( V_49 ) -> V_248 )
V_106 += F_94 ( V_49 ) -> V_248 ;
return V_106 ;
}
static inline void
F_100 ( struct V_1 * V_2 , struct V_95 * V_96 , int V_216 ,
int V_106 , struct V_45 * V_49 , int V_47 )
{
int V_249 ;
struct V_111 * V_112 ;
V_112 = (struct V_111 * ) F_48 ( V_96 , V_216 ) ;
memset ( V_112 , 0 , V_97 ) ;
V_112 -> V_222 = V_223 ;
if ( V_2 -> V_246 && V_2 -> V_245 && F_94 ( V_49 ) -> V_234 ) {
V_112 -> V_106 = V_106 - V_247 ;
} else {
V_96 -> V_99 [ V_216 ] = ( T_1 ) V_49 ;
V_112 -> V_250 = 1 ;
V_112 -> V_106 = V_106 ;
}
V_112 -> V_227 = V_47 ;
if ( V_49 -> V_251 == V_252 ) {
V_112 -> V_253 = 1 ;
V_112 -> V_254 = F_101 ( V_49 ) ;
V_112 -> V_255 = F_95 ( V_49 ) ;
V_249 = F_102 ( V_49 ) -> V_256 ;
switch ( V_249 ) {
case V_257 :
V_112 -> V_258 = V_259 ;
break;
case V_260 :
V_112 -> V_258 = V_261 ;
break;
case V_262 :
V_112 -> V_258 = V_263 ;
break;
}
}
if ( V_2 -> V_245 && F_94 ( V_49 ) -> V_234 ) {
V_112 -> V_264 = 1 ;
V_112 -> V_265 = F_95 ( V_49 ) + F_96 ( V_49 ) ;
V_112 -> V_266 = F_94 ( V_49 ) -> V_234 ;
V_112 -> V_267 = F_101 ( V_49 ) - 2 ;
F_16 ( V_2 -> V_40 -> V_41 -> V_268 ) ;
}
}
static inline void F_103 ( struct V_95 * V_96 , int V_216 ,
int V_21 , T_1 V_48 )
{
struct V_107 * V_108 ;
V_216 &= ( V_96 -> V_17 . V_18 - 1 ) ;
V_108 = (struct V_107 * ) F_48 ( V_96 , V_216 ) ;
memset ( V_108 , 0 , V_97 ) ;
V_108 -> V_222 = V_269 ;
V_108 -> V_270 = V_271 ;
V_108 -> V_21 = V_21 ;
V_108 -> V_109 = V_48 ;
}
static inline void F_104 ( struct V_95 * V_96 , int V_216 ,
int V_113 , struct V_45 * V_49 )
{
struct V_272 * V_273 ;
struct V_111 * V_112 ;
V_96 -> V_99 [ V_216 ] = ( T_1 ) V_49 ;
V_112 = (struct V_111 * ) F_48 ( V_96 , V_216 ) ;
memset ( V_112 , 0 , V_97 ) ;
V_112 -> V_222 = V_223 ;
V_112 -> V_250 = 1 ;
V_112 -> V_115 = 1 ;
V_112 -> V_106 = V_247 - 1 ;
V_112 -> V_227 = 1 ;
V_112 -> V_116 = V_113 ;
V_216 = F_87 ( V_96 , V_216 ) ;
V_273 = (struct V_272 * ) F_48 ( V_96 , V_216 ) ;
memset ( V_273 , 0 , V_97 ) ;
V_273 -> V_222 = V_274 ;
V_273 -> V_47 = 1 ;
}
static inline void F_105 ( struct V_1 * V_2 , struct V_45 * V_49 ,
int V_180 , int V_215 )
{
struct V_275 * V_276 ;
V_276 = F_106 ( V_2 -> V_40 -> V_15 ,
F_107 ( V_49 ) ) ;
F_108 ( V_276 , V_49 -> V_47 ) ;
F_31 () ;
F_32 ( V_2 , V_218 ,
V_180 , V_215 ) ;
}
static int F_109 ( struct V_1 * V_2 , struct V_95 * V_96 ,
int V_180 , int V_216 , struct V_45 * V_49 )
{
struct V_277 V_264 ;
int V_278 = 0 , V_215 = 0 ;
int V_279 , V_280 , V_281 ;
int V_282 = V_216 ;
int V_283 = F_95 ( V_49 ) + F_96 ( V_49 ) ;
V_265 ( V_49 , & V_264 ) ;
V_280 = V_49 -> V_47 - V_283 ;
while ( V_280 > 0 ) {
char * V_112 ;
V_282 = V_216 ;
V_281 = F_78 ( int , F_94 ( V_49 ) -> V_234 , V_280 ) ;
V_280 -= V_281 ;
V_216 = F_87 ( V_96 , V_216 ) ;
V_112 = V_96 -> V_102 + V_216 * V_103 ;
F_110 ( V_49 , V_112 , & V_264 , V_281 , V_280 == 0 ) ;
F_103 ( V_96 , V_216 , V_283 ,
V_96 -> V_104 +
V_216 * V_103 ) ;
V_278 = 2 ;
V_279 = V_283 ;
while ( V_281 > 0 ) {
int V_21 ;
V_21 = F_78 ( int , V_264 . V_21 , V_281 ) ;
V_216 = F_87 ( V_96 , V_216 ) ;
F_103 ( V_96 , V_216 , V_21 ,
F_111 ( V_264 . V_48 ) ) ;
V_278 ++ ;
V_279 += V_21 ;
V_281 -= V_21 ;
F_112 ( V_49 , & V_264 , V_21 ) ;
}
F_100 ( V_2 , V_96 , V_282 ,
V_278 - 1 , V_49 , V_279 ) ;
V_96 -> V_99 [ V_282 ] = ( T_1 ) NULL ;
V_216 = F_87 ( V_96 , V_216 ) ;
V_215 += V_278 ;
}
V_96 -> V_99 [ V_282 ] = ( T_1 ) V_49 ;
F_105 ( V_2 , V_49 , V_180 , V_215 ) ;
F_16 ( V_2 -> V_40 -> V_41 -> V_268 ) ;
return 1 ;
}
int F_113 ( struct V_1 * V_2 , struct V_95 * V_96 ,
struct V_45 * V_49 , T_5 V_180 )
{
int V_284 , V_21 ;
int V_106 , V_105 = 0 ;
int V_216 ;
T_1 V_3 ;
V_106 = F_99 ( V_2 , V_49 ) ;
if ( V_106 > F_114 ( & V_96 -> V_100 ) )
goto V_285;
V_216 = F_82 ( V_96 , V_106 ) ;
if ( F_94 ( V_49 ) -> V_234 && ! V_2 -> V_245 )
return F_109 ( V_2 , V_96 , V_180 , V_216 , V_49 ) ;
F_100 ( V_2 , V_96 , V_216 , V_106 - 1 ,
V_49 , V_49 -> V_47 ) ;
V_105 = V_216 ;
V_216 = F_87 ( V_96 , V_216 ) ;
V_21 = F_115 ( V_49 ) ? F_97 ( V_49 ) : V_49 -> V_47 ;
V_3 = F_17 ( & V_2 -> V_23 -> V_24 , F_24 ( V_49 -> V_48 ) ,
F_116 ( V_49 -> V_48 ) , V_21 ,
V_110 , V_44 ) ;
if ( F_18 ( & V_2 -> V_23 -> V_24 , V_3 ) ) {
F_84 ( V_96 , V_216 , V_106 ) ;
return 0 ;
}
F_103 ( V_96 , V_216 , V_21 , V_3 ) ;
if ( ! F_115 ( V_49 ) )
goto V_286;
for ( V_284 = 0 ; V_284 < F_94 ( V_49 ) -> V_248 ; V_284 ++ ) {
const struct V_287 * V_288 ;
V_288 = & F_94 ( V_49 ) -> V_243 [ V_284 ] ;
V_216 = F_87 ( V_96 , V_216 ) ;
V_21 = F_98 ( V_288 ) ;
V_3 = F_17 ( & V_2 -> V_23 -> V_24 ,
F_117 ( V_288 ) ,
V_288 -> V_289 , V_21 ,
V_110 ,
V_44 ) ;
if ( F_18 ( & V_2 -> V_23 -> V_24 , V_3 ) ) {
F_47 ( V_2 , V_96 , V_105 , V_284 ) ;
F_84 ( V_96 , V_216 , V_106 ) ;
return 0 ;
}
F_103 ( V_96 , V_216 , V_21 , V_3 ) ;
}
V_286:
if ( V_2 -> V_246 && F_94 ( V_49 ) -> V_234 ) {
V_216 = F_87 ( V_96 , V_216 ) ;
F_104 ( V_96 , V_216 , V_105 , V_49 ) ;
}
F_105 ( V_2 , V_49 , V_180 , V_106 ) ;
return 1 ;
V_285:
V_2 = V_2 -> V_40 ;
F_118 ( V_2 -> V_15 , L_4 ) ;
return 0 ;
}
static inline unsigned F_119 ( unsigned V_284 )
{
#ifdef F_73
return ( V_284 & ~ 3 ) + 3 - ( V_284 & 3 ) ;
#else
return V_284 ;
#endif
}
struct V_45 * F_120 ( struct V_1 * V_2 , struct V_290 * V_291 )
{
int V_288 ;
int V_292 = 0 ;
struct V_45 * V_49 = NULL ;
struct V_293 * V_293 ;
int V_294 ;
T_7 * V_295 = NULL ;
T_1 * V_296 = NULL ;
T_1 V_67 ;
V_295 = ( void * ) V_291 + ( 3 * sizeof( T_1 ) ) ;
if ( ! V_2 -> V_245 )
V_296 = ( void * ) V_291 + ( 6 * sizeof( T_1 ) ) ;
else
V_296 = ( void * ) V_291 + ( 7 * sizeof( T_1 ) ) ;
for ( V_288 = 0 ; V_288 < V_291 -> V_297 ; V_288 ++ ) {
V_292 = V_295 [ F_119 ( V_288 ) ] ;
V_67 = F_1 ( V_2 , * V_296 ) ;
if ( ! V_67 ) {
if ( V_49 )
F_51 ( V_49 ) ;
return NULL ;
}
if ( ! V_288 ) {
F_29 ( & V_2 -> V_23 -> V_24 ,
* V_296 - V_291 -> V_298 ,
V_50 , V_43 ,
V_44 ) ;
V_49 = F_20 ( V_2 ,
V_67 - V_291 -> V_298 ,
V_292 ) ;
if ( ! V_49 )
return NULL ;
F_121 ( V_49 , V_291 -> V_298 ) ;
F_122 ( V_49 , V_292 ) ;
} else {
F_29 ( & V_2 -> V_23 -> V_24 , * V_296 ,
V_50 , V_43 ,
V_44 ) ;
V_293 = F_24 ( F_21 ( V_67 ) ) ;
V_294 = F_21 ( V_67 ) - F_123 ( V_293 ) ;
F_124 ( V_49 , F_94 ( V_49 ) -> V_248 , V_293 ,
V_294 , V_292 , V_50 ) ;
}
V_296 ++ ;
}
return V_49 ;
}
static T_1 F_125 ( int V_299 , int V_300 )
{
T_1 V_13 ;
switch ( V_299 ) {
case V_301 :
V_13 = ( ( 1ULL << V_300 ) << V_302 ) ;
break;
case V_303 :
V_13 = ( ( 1ULL << V_300 ) << V_304 ) ;
break;
case V_82 :
V_13 = ( ( 1ULL << V_300 ) << V_305 ) ;
break;
case V_306 :
V_13 = ( 1ULL << V_307 ) ;
break;
case V_308 :
V_13 = ( 1ULL << V_309 ) ;
break;
case V_310 :
V_13 = ( 1ULL << V_311 ) ;
break;
case V_312 :
V_13 = ( 1ULL << V_313 ) ;
break;
default:
V_13 = 0 ;
}
return V_13 ;
}
void F_34 ( struct V_1 * V_2 , int V_299 , int V_300 )
{
T_1 V_314 = F_125 ( V_299 , V_300 ) ;
if ( ! V_314 ) {
F_118 ( V_2 -> V_15 ,
L_5 ) ;
return;
}
F_126 ( V_2 , V_315 ,
F_127 ( V_2 , V_315 ) | V_314 ) ;
}
void F_128 ( struct V_1 * V_2 , int V_299 , int V_300 )
{
T_1 V_314 = F_125 ( V_299 , V_300 ) ;
if ( ! V_314 ) {
F_118 ( V_2 -> V_15 ,
L_6 ) ;
return;
}
F_126 ( V_2 , V_316 , V_314 ) ;
}
void F_129 ( struct V_1 * V_2 , int V_299 , int V_300 )
{
T_1 V_314 = F_125 ( V_299 , V_300 ) ;
if ( ! V_314 ) {
F_118 ( V_2 -> V_15 ,
L_7 ) ;
return;
}
F_126 ( V_2 , V_317 , V_314 ) ;
}
int F_130 ( struct V_1 * V_2 , int V_299 , int V_300 )
{
T_1 V_314 = F_125 ( V_299 , V_300 ) ;
if ( ! V_314 ) {
F_118 ( V_2 -> V_15 ,
L_8 ) ;
return 0 ;
}
return V_314 & F_127 ( V_2 , V_315 ) ;
}
void F_131 ( struct V_1 * V_2 , int V_318 )
{
struct V_146 * V_147 ;
#define F_132 ( V_8 ) \
nicvf_reg_read(nic, NIC_QSET_RQ_0_7_STAT_0_1 |\
(rq_idx << NIC_Q_NUM_SHIFT) | (reg << 3))
V_147 = & V_2 -> V_69 -> V_147 [ V_318 ] ;
V_147 -> V_225 . V_319 = F_132 ( V_320 ) ;
V_147 -> V_225 . V_321 = F_132 ( V_322 ) ;
}
void F_133 ( struct V_1 * V_2 , int V_323 )
{
struct V_95 * V_96 ;
#define F_134 ( V_8 ) \
nicvf_reg_read(nic, NIC_QSET_SQ_0_7_STAT_0_1 |\
(sq_idx << NIC_Q_NUM_SHIFT) | (reg << 3))
V_96 = & V_2 -> V_69 -> V_96 [ V_323 ] ;
V_96 -> V_225 . V_319 = F_134 ( V_320 ) ;
V_96 -> V_225 . V_321 = F_134 ( V_322 ) ;
}
int F_135 ( struct V_1 * V_2 , struct V_290 * V_291 )
{
if ( ! V_291 -> V_324 && ! V_291 -> V_325 )
return 0 ;
if ( F_136 ( V_2 ) )
F_8 ( V_2 -> V_15 ,
L_9 ,
V_2 -> V_15 -> V_326 ,
V_291 -> V_324 , V_291 -> V_325 ) ;
switch ( V_291 -> V_325 ) {
case V_327 :
F_16 ( V_2 -> V_41 -> V_328 ) ;
break;
case V_329 :
F_16 ( V_2 -> V_41 -> V_330 ) ;
break;
case V_331 :
F_16 ( V_2 -> V_41 -> V_332 ) ;
break;
case V_333 :
F_16 ( V_2 -> V_41 -> V_334 ) ;
break;
case V_335 :
F_16 ( V_2 -> V_41 -> V_336 ) ;
break;
case V_337 :
F_16 ( V_2 -> V_41 -> V_338 ) ;
break;
case V_339 :
F_16 ( V_2 -> V_41 -> V_340 ) ;
break;
case V_341 :
F_16 ( V_2 -> V_41 -> V_342 ) ;
break;
case V_343 :
F_16 ( V_2 -> V_41 -> V_344 ) ;
break;
case V_345 :
F_16 ( V_2 -> V_41 -> V_346 ) ;
break;
case V_347 :
F_16 ( V_2 -> V_41 -> V_348 ) ;
break;
case V_349 :
F_16 ( V_2 -> V_41 -> V_350 ) ;
break;
case V_351 :
F_16 ( V_2 -> V_41 -> V_352 ) ;
break;
case V_353 :
F_16 ( V_2 -> V_41 -> V_354 ) ;
break;
case V_355 :
F_16 ( V_2 -> V_41 -> V_356 ) ;
break;
case V_357 :
F_16 ( V_2 -> V_41 -> V_358 ) ;
break;
case V_359 :
F_16 ( V_2 -> V_41 -> V_360 ) ;
break;
case V_361 :
F_16 ( V_2 -> V_41 -> V_362 ) ;
break;
case V_363 :
F_16 ( V_2 -> V_41 -> V_364 ) ;
break;
case V_365 :
F_16 ( V_2 -> V_41 -> V_366 ) ;
break;
case V_367 :
F_16 ( V_2 -> V_41 -> V_368 ) ;
break;
case V_369 :
F_16 ( V_2 -> V_41 -> V_370 ) ;
break;
case V_371 :
F_16 ( V_2 -> V_41 -> V_372 ) ;
break;
case V_373 :
F_16 ( V_2 -> V_41 -> V_374 ) ;
break;
}
return 1 ;
}
int F_137 ( struct V_1 * V_2 , struct V_375 * V_376 )
{
switch ( V_376 -> V_377 ) {
case V_378 :
return 0 ;
case V_379 :
F_16 ( V_2 -> V_41 -> V_380 ) ;
break;
case V_381 :
F_16 ( V_2 -> V_41 -> V_382 ) ;
break;
case V_383 :
F_16 ( V_2 -> V_41 -> V_384 ) ;
break;
case V_385 :
F_16 ( V_2 -> V_41 -> V_386 ) ;
break;
case V_387 :
F_16 ( V_2 -> V_41 -> V_388 ) ;
break;
case V_389 :
F_16 ( V_2 -> V_41 -> V_390 ) ;
break;
case V_391 :
F_16 ( V_2 -> V_41 -> V_392 ) ;
break;
case V_393 :
F_16 ( V_2 -> V_41 -> V_394 ) ;
break;
case V_395 :
F_16 ( V_2 -> V_41 -> V_396 ) ;
break;
case V_397 :
F_16 ( V_2 -> V_41 -> V_398 ) ;
break;
case V_399 :
F_16 ( V_2 -> V_41 -> V_400 ) ;
break;
case V_401 :
F_16 ( V_2 -> V_41 -> V_402 ) ;
break;
case V_403 :
F_16 ( V_2 -> V_41 -> V_404 ) ;
break;
case V_405 :
F_16 ( V_2 -> V_41 -> V_406 ) ;
break;
}
return 1 ;
}

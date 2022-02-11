static void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 || ! V_2 -> V_4 )
return;
F_2 ( V_2 -> V_4 , V_2 -> V_3 ) ;
V_2 -> V_3 = 0 ;
}
static int F_3 ( struct V_1 * V_2 , int V_5 ,
T_1 V_6 , int V_7 , int V_8 , int V_9 )
{
T_1 V_10 ;
T_1 V_11 ;
int V_12 = 10 ;
V_10 = ( 1ULL << V_8 ) - 1 ;
V_10 = ( V_10 << V_7 ) ;
while ( V_12 ) {
V_11 = F_4 ( V_2 , V_6 , V_5 ) ;
if ( ( ( V_11 & V_10 ) >> V_7 ) == V_9 )
return 0 ;
F_5 ( 1000 , 2000 ) ;
V_12 -- ;
}
F_6 ( V_2 -> V_13 , L_1 , V_6 ) ;
return 1 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_14 * V_15 ,
int V_16 , int V_17 , int V_18 )
{
V_15 -> V_16 = V_16 ;
V_15 -> V_19 = ( V_17 * V_16 ) + V_18 ;
V_15 -> V_20 = F_8 ( & V_2 -> V_21 -> V_22 , V_15 -> V_19 ,
& V_15 -> V_23 , V_24 ) ;
if ( ! V_15 -> V_20 )
return - V_25 ;
V_15 -> V_26 = F_9 ( ( T_1 ) V_15 -> V_23 , V_18 ) ;
V_15 -> V_27 = V_15 -> V_20 + ( V_15 -> V_26 - V_15 -> V_23 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
if ( ! V_15 )
return;
F_11 ( & V_2 -> V_21 -> V_22 , V_15 -> V_19 ,
V_15 -> V_20 , V_15 -> V_23 ) ;
V_15 -> V_20 = NULL ;
V_15 -> V_27 = NULL ;
}
static inline int F_12 ( struct V_1 * V_2 , T_2 V_28 ,
T_3 V_29 , T_1 * * V_30 )
{
int V_31 = ( V_32 <= 4096 ) ? V_33 : 0 ;
if ( V_2 -> V_4 &&
( ( V_2 -> V_34 + V_29 ) < ( V_32 << V_31 ) ) ) {
V_2 -> V_3 ++ ;
goto V_35;
}
F_1 ( V_2 ) ;
V_2 -> V_4 = NULL ;
if ( ! V_2 -> V_4 ) {
V_2 -> V_4 = F_13 ( V_28 | V_36 | V_37 ,
V_31 ) ;
if ( ! V_2 -> V_4 ) {
F_14 ( V_2 -> V_38 -> V_39 ->
V_40 ) ;
return - V_25 ;
}
V_2 -> V_34 = 0 ;
}
V_35:
* V_30 = ( T_1 * ) ( ( T_1 ) F_15 ( V_2 -> V_4 ) + V_2 -> V_34 ) ;
V_2 -> V_34 += V_29 ;
return 0 ;
}
static struct V_41 * F_16 ( struct V_1 * V_2 ,
T_1 V_42 , int V_43 )
{
void * V_44 ;
struct V_41 * V_45 ;
V_44 = F_17 ( V_42 ) ;
V_45 = F_18 ( V_44 , V_46 ) ;
if ( ! V_45 ) {
F_19 ( F_20 ( V_44 ) ) ;
return NULL ;
}
F_21 ( V_45 -> V_44 ) ;
return V_45 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_47 * V_47 ,
int V_48 , int V_49 )
{
int V_50 ;
T_1 * V_30 ;
struct V_51 * V_52 ;
int V_53 ;
V_53 = F_7 ( V_2 , & V_47 -> V_15 , V_48 ,
sizeof( struct V_51 ) ,
V_54 ) ;
if ( V_53 )
return V_53 ;
V_47 -> V_52 = V_47 -> V_15 . V_27 ;
V_47 -> V_55 = V_49 ;
V_47 -> V_56 = true ;
V_47 -> V_57 = V_58 ;
V_2 -> V_4 = NULL ;
for ( V_50 = 0 ; V_50 < V_48 ; V_50 ++ ) {
V_53 = F_12 ( V_2 , V_24 , V_46 ,
& V_30 ) ;
if ( V_53 )
return V_53 ;
V_52 = F_23 ( V_47 , V_50 ) ;
V_52 -> V_59 = F_24 ( V_30 ) >> V_60 ;
}
F_1 ( V_2 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 , struct V_47 * V_47 )
{
int V_61 , V_62 ;
T_1 V_59 ;
struct V_51 * V_52 ;
if ( ! V_47 )
return;
V_47 -> V_56 = false ;
if ( ! V_47 -> V_15 . V_27 )
return;
V_61 = V_47 -> V_61 ;
V_62 = V_47 -> V_62 ;
while ( V_61 != V_62 ) {
V_52 = F_23 ( V_47 , V_61 ) ;
V_59 = V_52 -> V_59 << V_60 ;
F_19 ( F_20 ( F_17 ( V_59 ) ) ) ;
V_61 ++ ;
V_61 &= ( V_47 -> V_15 . V_16 - 1 ) ;
}
V_52 = F_23 ( V_47 , V_62 ) ;
V_59 = V_52 -> V_59 << V_60 ;
F_19 ( F_20 ( F_17 ( V_59 ) ) ) ;
F_10 ( V_2 , & V_47 -> V_15 ) ;
}
static void F_26 ( struct V_1 * V_2 , T_2 V_28 )
{
struct V_63 * V_64 = V_2 -> V_64 ;
int V_65 = V_64 -> V_66 ;
int V_62 , V_67 ;
int V_68 ;
struct V_47 * V_47 ;
struct V_51 * V_52 ;
T_1 * V_30 ;
int V_69 = 0 ;
V_70:
if ( ! V_65 )
return;
V_65 -- ;
V_47 = & V_64 -> V_47 [ V_65 ] ;
if ( ! V_47 -> V_56 )
goto V_71;
V_67 = F_4 ( V_2 , V_72 , V_65 ) ;
V_67 &= 0x7FFFF ;
if ( V_67 >= ( V_64 -> V_73 - 1 ) )
goto V_71;
else
V_68 = V_64 -> V_73 - V_67 - 1 ;
V_62 = F_4 ( V_2 , V_74 , V_65 ) >> 3 ;
while ( V_68 ) {
V_62 ++ ;
V_62 &= ( V_47 -> V_15 . V_16 - 1 ) ;
if ( F_12 ( V_2 , V_28 , V_46 , & V_30 ) )
break;
V_52 = F_23 ( V_47 , V_62 ) ;
V_52 -> V_59 = F_24 ( V_30 ) >> V_60 ;
V_68 -- ;
V_69 ++ ;
}
F_1 ( V_2 ) ;
F_27 () ;
if ( V_68 )
V_2 -> V_75 = true ;
else
V_2 -> V_75 = false ;
F_28 ( V_2 , V_76 ,
V_65 , V_69 ) ;
V_71:
if ( ! V_2 -> V_75 && V_47 -> V_56 &&
F_29 ( V_2 -> V_38 -> V_13 ) )
F_30 ( V_2 , V_77 , V_65 ) ;
if ( V_65 )
goto V_70;
}
void F_31 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_32 ( V_79 , struct V_1 , V_80 . V_79 ) ;
F_26 ( V_2 , V_24 ) ;
if ( V_2 -> V_75 )
F_33 ( & V_2 -> V_80 , F_34 ( 10 ) ) ;
else
V_2 -> V_81 = false ;
}
void F_35 ( unsigned long V_44 )
{
struct V_1 * V_2 = (struct V_1 * ) V_44 ;
F_26 ( V_2 , V_82 ) ;
if ( V_2 -> V_75 ) {
V_2 -> V_81 = true ;
F_33 ( & V_2 -> V_80 , F_34 ( 10 ) ) ;
}
}
static int F_36 ( struct V_1 * V_2 ,
struct V_83 * V_84 , int V_16 )
{
int V_53 ;
V_53 = F_7 ( V_2 , & V_84 -> V_15 , V_16 , V_85 ,
V_86 ) ;
if ( V_53 )
return V_53 ;
V_84 -> V_52 = V_84 -> V_15 . V_27 ;
V_84 -> V_57 = F_37 ( V_2 -> V_21 ) ? 0 : V_87 ;
V_2 -> V_88 = ( V_89 * 0.05 ) - 1 ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , struct V_83 * V_84 )
{
if ( ! V_84 )
return;
if ( ! V_84 -> V_15 . V_27 )
return;
F_10 ( V_2 , & V_84 -> V_15 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_90 * V_91 , int V_16 )
{
int V_53 ;
V_53 = F_7 ( V_2 , & V_91 -> V_15 , V_16 , V_92 ,
V_93 ) ;
if ( V_53 )
return V_53 ;
V_91 -> V_52 = V_91 -> V_15 . V_27 ;
V_91 -> V_94 = F_40 ( V_16 , sizeof( T_1 ) , V_24 ) ;
if ( ! V_91 -> V_94 )
return - V_25 ;
V_91 -> V_61 = 0 ;
V_91 -> V_62 = 0 ;
F_41 ( & V_91 -> V_95 , V_16 - 1 ) ;
V_91 -> V_57 = V_96 ;
V_91 -> V_97 = F_42 ( & V_2 -> V_21 -> V_22 ,
V_16 * V_98 ,
& V_91 -> V_99 , V_24 ) ;
if ( ! V_91 -> V_97 )
return - V_25 ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
struct V_41 * V_45 ;
if ( ! V_91 )
return;
if ( ! V_91 -> V_15 . V_27 )
return;
if ( V_91 -> V_97 )
F_11 ( & V_2 -> V_21 -> V_22 ,
V_91 -> V_15 . V_16 * V_98 ,
V_91 -> V_97 , V_91 -> V_99 ) ;
F_44 () ;
while ( V_91 -> V_61 != V_91 -> V_62 ) {
V_45 = (struct V_41 * ) V_91 -> V_94 [ V_91 -> V_61 ] ;
if ( V_45 )
F_45 ( V_45 ) ;
V_91 -> V_61 ++ ;
V_91 -> V_61 &= ( V_91 -> V_15 . V_16 - 1 ) ;
}
F_46 ( V_91 -> V_94 ) ;
F_10 ( V_2 , & V_91 -> V_15 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_63 * V_64 , int V_5 )
{
F_28 ( V_2 , V_100 , V_5 , 0 ) ;
if ( F_3 ( V_2 , V_5 , V_101 , 21 , 1 , 0x01 ) )
return;
F_28 ( V_2 , V_100 , V_5 , V_102 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_63 * V_64 , int V_5 )
{
union V_103 V_104 = {} ;
V_104 . V_105 . V_105 = V_106 ;
F_49 ( V_2 , & V_104 ) ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_63 * V_64 , int V_5 )
{
F_28 ( V_2 , V_107 , V_5 , 0 ) ;
F_28 ( V_2 , V_108 , V_5 , 0 ) ;
F_28 ( V_2 , V_108 , V_5 , V_109 ) ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_47 * V_47 , int V_5 )
{
T_1 V_110 , V_111 ;
int V_12 = 10 ;
V_47 -> V_61 = F_4 ( V_2 ,
V_112 ,
V_5 ) >> 3 ;
V_47 -> V_62 = F_4 ( V_2 ,
V_74 ,
V_5 ) >> 3 ;
V_111 = F_4 ( V_2 , V_72 , V_5 ) ;
if ( ( ( V_111 >> 62 ) & 0x03 ) == 0x3 )
F_28 ( V_2 , V_113 ,
V_5 , V_114 ) ;
F_28 ( V_2 , V_113 , V_5 , 0 ) ;
if ( F_3 ( V_2 , V_5 , V_72 , 62 , 2 , 0x00 ) )
return;
while ( 1 ) {
V_110 = F_4 ( V_2 ,
V_115 ,
V_5 ) ;
if ( ( V_110 & 0xFFFFFFFF ) == ( ( V_110 >> 32 ) & 0xFFFFFFFF ) )
break;
F_5 ( 1000 , 2000 ) ;
V_12 -- ;
if ( ! V_12 ) {
F_6 ( V_2 -> V_13 ,
L_2 ) ;
return;
}
}
F_28 ( V_2 , V_113 ,
V_5 , V_114 ) ;
if ( F_3 ( V_2 , V_5 , V_72 , 62 , 2 , 0x02 ) )
return;
F_28 ( V_2 , V_113 , V_5 , 0x00 ) ;
if ( F_3 ( V_2 , V_5 , V_72 , 62 , 2 , 0x00 ) )
return;
}
void F_52 ( struct V_1 * V_2 , T_4 V_116 )
{
T_1 V_117 ;
int V_118 ;
V_117 = F_4 ( V_2 , V_119 , 0 ) ;
if ( V_116 & V_120 )
V_117 |= ( 1ULL << 25 ) ;
else
V_117 &= ~ ( 1ULL << 25 ) ;
F_28 ( V_2 , V_119 , 0 , V_117 ) ;
for ( V_118 = 0 ; V_118 < V_2 -> V_121 ; V_118 ++ )
if ( V_2 -> V_122 [ V_118 ] )
F_28 ( V_2 -> V_122 [ V_118 ] ,
V_119 , 0 , V_117 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
union V_103 V_104 = {} ;
V_104 . V_123 . V_105 = V_124 ;
V_104 . V_123 . V_125 = 0x3FFF ;
V_104 . V_123 . V_126 = 0x1F ;
V_104 . V_123 . V_127 = 0xFFFF ;
V_104 . V_123 . V_128 = 0xFFFF ;
F_49 ( V_2 , & V_104 ) ;
}
static void F_54 ( struct V_1 * V_2 , struct V_63 * V_64 ,
int V_5 , bool V_56 )
{
union V_103 V_104 = {} ;
struct V_129 * V_130 ;
struct V_117 V_117 ;
V_130 = & V_64 -> V_130 [ V_5 ] ;
V_130 -> V_56 = V_56 ;
F_28 ( V_2 , V_131 , V_5 , 0 ) ;
if ( ! V_130 -> V_56 ) {
F_48 ( V_2 , V_64 , V_5 ) ;
return;
}
V_130 -> V_132 = V_64 -> V_133 ;
V_130 -> V_134 = V_5 ;
V_130 -> V_135 = V_64 -> V_133 ;
V_130 -> V_136 = V_64 -> V_66 - 1 ;
V_130 -> V_137 = V_64 -> V_133 ;
V_130 -> V_138 = V_64 -> V_66 - 1 ;
V_130 -> V_139 = 1 ;
V_104 . V_130 . V_105 = V_140 ;
V_104 . V_130 . V_141 = V_64 -> V_133 ;
V_104 . V_130 . V_142 = V_5 ;
V_104 . V_130 . V_143 = ( V_130 -> V_139 << 26 ) | ( V_130 -> V_132 << 19 ) |
( V_130 -> V_134 << 16 ) | ( V_130 -> V_137 << 9 ) |
( V_130 -> V_138 << 8 ) |
( V_130 -> V_135 << 1 ) | ( V_130 -> V_136 ) ;
F_49 ( V_2 , & V_104 ) ;
V_104 . V_130 . V_105 = V_144 ;
V_104 . V_130 . V_143 = F_55 ( 63 ) | F_55 ( 62 ) |
( V_145 << 16 ) | ( V_146 << 8 ) |
( V_64 -> V_133 << 0 ) ;
F_49 ( V_2 , & V_104 ) ;
V_104 . V_130 . V_105 = V_147 ;
V_104 . V_130 . V_143 = F_55 ( 63 ) | F_55 ( 62 ) |
( V_145 << 40 ) | ( V_148 << 32 ) |
( V_146 << 16 ) | ( V_149 << 8 ) ;
F_49 ( V_2 , & V_104 ) ;
if ( ! V_2 -> V_150 && ( V_5 == 0 ) ) {
F_28 ( V_2 , V_119 , 0 ,
( F_56 ( 24 ) | F_56 ( 23 ) | F_56 ( 21 ) ) ) ;
F_52 ( V_2 , V_2 -> V_13 -> V_116 ) ;
}
memset ( & V_117 , 0 , sizeof( struct V_117 ) ) ;
V_117 . V_151 = 1 ;
V_117 . V_152 = 0 ;
F_28 ( V_2 , V_131 , V_5 , * ( T_1 * ) & V_117 ) ;
}
void F_57 ( struct V_1 * V_2 , struct V_63 * V_64 ,
int V_5 , bool V_56 )
{
struct V_83 * V_84 ;
struct V_153 V_153 ;
V_84 = & V_64 -> V_84 [ V_5 ] ;
V_84 -> V_56 = V_56 ;
if ( ! V_84 -> V_56 ) {
F_50 ( V_2 , V_64 , V_5 ) ;
return;
}
F_28 ( V_2 , V_108 , V_5 , V_109 ) ;
if ( ! V_84 -> V_56 )
return;
F_58 ( & V_84 -> V_154 ) ;
F_28 ( V_2 , V_155 ,
V_5 , ( T_1 ) ( V_84 -> V_15 . V_26 ) ) ;
memset ( & V_153 , 0 , sizeof( struct V_153 ) ) ;
V_153 . V_151 = 1 ;
V_153 . V_156 = 0 ;
V_153 . V_139 = 0 ;
V_153 . V_157 = V_158 ;
V_153 . V_159 = 0 ;
F_28 ( V_2 , V_108 , V_5 , * ( T_1 * ) & V_153 ) ;
F_28 ( V_2 , V_160 , V_5 , V_84 -> V_57 ) ;
F_28 ( V_2 , V_107 ,
V_5 , V_89 ) ;
}
static void F_59 ( struct V_1 * V_2 , struct V_63 * V_64 ,
int V_5 , bool V_56 )
{
union V_103 V_104 = {} ;
struct V_90 * V_91 ;
struct V_161 V_161 ;
V_91 = & V_64 -> V_91 [ V_5 ] ;
V_91 -> V_56 = V_56 ;
if ( ! V_91 -> V_56 ) {
F_47 ( V_2 , V_64 , V_5 ) ;
return;
}
F_28 ( V_2 , V_100 , V_5 , V_102 ) ;
V_91 -> V_132 = V_64 -> V_133 ;
V_91 -> V_134 = V_5 ;
V_104 . V_91 . V_105 = V_162 ;
V_104 . V_91 . V_141 = V_64 -> V_133 ;
V_104 . V_91 . V_163 = V_5 ;
V_104 . V_91 . V_150 = V_2 -> V_150 ;
V_104 . V_91 . V_143 = ( V_91 -> V_132 << 3 ) | V_91 -> V_134 ;
F_49 ( V_2 , & V_104 ) ;
F_28 ( V_2 , V_164 ,
V_5 , ( T_1 ) ( V_91 -> V_15 . V_26 ) ) ;
memset ( & V_161 , 0 , sizeof( struct V_161 ) ) ;
V_161 . V_151 = 1 ;
V_161 . V_156 = 0 ;
V_161 . V_165 = 0 ;
V_161 . V_157 = V_166 ;
V_161 . V_167 = 0 ;
V_161 . V_168 = 0 ;
F_28 ( V_2 , V_100 , V_5 , * ( T_1 * ) & V_161 ) ;
F_28 ( V_2 , V_169 , V_5 , V_91 -> V_57 ) ;
if ( F_60 ( V_5 ) ) {
F_61 ( V_5 , & V_91 -> V_170 ) ;
F_62 ( V_2 -> V_13 ,
& V_91 -> V_170 , V_5 ) ;
}
}
static void F_63 ( struct V_1 * V_2 , struct V_63 * V_64 ,
int V_5 , bool V_56 )
{
struct V_47 * V_47 ;
struct V_171 V_171 ;
V_47 = & V_64 -> V_47 [ V_5 ] ;
F_51 ( V_2 , V_47 , V_5 ) ;
if ( ! V_56 )
return;
F_28 ( V_2 , V_172 ,
V_5 , ( T_1 ) ( V_47 -> V_15 . V_26 ) ) ;
memset ( & V_171 , 0 , sizeof( struct V_171 ) ) ;
V_171 . V_151 = 1 ;
V_171 . V_156 = 0 ;
V_171 . V_165 = 0 ;
V_171 . V_157 = V_173 ;
V_171 . V_159 = 0 ;
V_171 . V_174 = V_47 -> V_55 / 128 ;
F_28 ( V_2 , V_113 ,
V_5 , * ( T_1 * ) & V_171 ) ;
F_28 ( V_2 , V_76 ,
V_5 , V_64 -> V_73 - 1 ) ;
F_28 ( V_2 , V_175 ,
V_5 , V_47 -> V_57 - 1 ) ;
}
void F_64 ( struct V_1 * V_2 , bool V_56 )
{
union V_103 V_104 = {} ;
struct V_63 * V_64 = V_2 -> V_64 ;
struct V_176 * V_176 ;
if ( ! V_64 ) {
F_65 ( V_2 -> V_13 ,
L_3 ) ;
return;
}
V_64 -> V_56 = V_56 ;
V_64 -> V_133 = V_2 -> V_177 ;
V_104 . V_64 . V_105 = V_178 ;
V_104 . V_64 . V_179 = V_64 -> V_133 ;
V_104 . V_64 . V_121 = V_2 -> V_121 ;
V_104 . V_64 . V_143 = 0 ;
V_176 = (struct V_176 * ) & V_104 . V_64 . V_143 ;
if ( V_64 -> V_56 ) {
V_176 -> V_151 = 1 ;
#ifdef F_66
V_176 -> V_180 = 1 ;
#endif
V_176 -> V_181 = V_64 -> V_133 ;
}
F_49 ( V_2 , & V_104 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_63 * V_64 = V_2 -> V_64 ;
for ( V_5 = 0 ; V_5 < V_64 -> V_66 ; V_5 ++ )
F_25 ( V_2 , & V_64 -> V_47 [ V_5 ] ) ;
for ( V_5 = 0 ; V_5 < V_64 -> V_182 ; V_5 ++ )
F_38 ( V_2 , & V_64 -> V_84 [ V_5 ] ) ;
for ( V_5 = 0 ; V_5 < V_64 -> V_183 ; V_5 ++ )
F_43 ( V_2 , & V_64 -> V_91 [ V_5 ] ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_63 * V_64 = V_2 -> V_64 ;
for ( V_5 = 0 ; V_5 < V_64 -> V_66 ; V_5 ++ ) {
if ( F_22 ( V_2 , & V_64 -> V_47 [ V_5 ] , V_64 -> V_73 ,
V_184 ) )
goto V_185;
}
for ( V_5 = 0 ; V_5 < V_64 -> V_183 ; V_5 ++ ) {
if ( F_39 ( V_2 , & V_64 -> V_91 [ V_5 ] , V_64 -> V_186 ) )
goto V_185;
}
for ( V_5 = 0 ; V_5 < V_64 -> V_182 ; V_5 ++ ) {
if ( F_36 ( V_2 , & V_64 -> V_84 [ V_5 ] , V_64 -> V_187 ) )
goto V_185;
}
return 0 ;
V_185:
F_67 ( V_2 ) ;
return - V_25 ;
}
int F_69 ( struct V_1 * V_2 )
{
struct V_63 * V_64 ;
V_64 = F_70 ( & V_2 -> V_21 -> V_22 , sizeof( * V_64 ) , V_24 ) ;
if ( ! V_64 )
return - V_25 ;
V_2 -> V_64 = V_64 ;
V_64 -> V_66 = V_188 ;
V_64 -> V_189 = F_71 ( V_190 , V_191 , F_72 () ) ;
V_64 -> V_183 = F_71 ( V_190 , V_192 , F_72 () ) ;
V_64 -> V_182 = F_73 ( V_190 , V_64 -> V_189 , V_64 -> V_183 ) ;
V_64 -> V_73 = V_193 ;
V_64 -> V_186 = V_194 ;
V_64 -> V_187 = V_195 ;
V_2 -> V_196 = V_64 -> V_189 ;
V_2 -> V_197 = V_64 -> V_183 ;
return 0 ;
}
int F_74 ( struct V_1 * V_2 , bool V_56 )
{
bool V_198 = false ;
struct V_63 * V_64 = V_2 -> V_64 ;
int V_5 ;
if ( ! V_64 )
return 0 ;
if ( V_56 ) {
if ( F_68 ( V_2 ) )
return - V_25 ;
for ( V_5 = 0 ; V_5 < V_64 -> V_183 ; V_5 ++ )
F_59 ( V_2 , V_64 , V_5 , V_56 ) ;
for ( V_5 = 0 ; V_5 < V_64 -> V_182 ; V_5 ++ )
F_57 ( V_2 , V_64 , V_5 , V_56 ) ;
for ( V_5 = 0 ; V_5 < V_64 -> V_66 ; V_5 ++ )
F_63 ( V_2 , V_64 , V_5 , V_56 ) ;
for ( V_5 = 0 ; V_5 < V_64 -> V_189 ; V_5 ++ )
F_54 ( V_2 , V_64 , V_5 , V_56 ) ;
} else {
for ( V_5 = 0 ; V_5 < V_64 -> V_189 ; V_5 ++ )
F_54 ( V_2 , V_64 , V_5 , V_198 ) ;
for ( V_5 = 0 ; V_5 < V_64 -> V_66 ; V_5 ++ )
F_63 ( V_2 , V_64 , V_5 , V_198 ) ;
for ( V_5 = 0 ; V_5 < V_64 -> V_183 ; V_5 ++ )
F_59 ( V_2 , V_64 , V_5 , V_198 ) ;
for ( V_5 = 0 ; V_5 < V_64 -> V_182 ; V_5 ++ )
F_57 ( V_2 , V_64 , V_5 , V_198 ) ;
F_67 ( V_2 ) ;
}
F_53 ( V_2 ) ;
return 0 ;
}
static inline int F_75 ( struct V_90 * V_91 , int V_199 )
{
int V_200 ;
V_200 = V_91 -> V_62 ;
F_76 ( V_199 , & V_91 -> V_95 ) ;
V_91 -> V_62 += V_199 ;
V_91 -> V_62 &= ( V_91 -> V_15 . V_16 - 1 ) ;
return V_200 ;
}
void F_77 ( struct V_90 * V_91 , int V_199 )
{
F_78 ( V_199 , & V_91 -> V_95 ) ;
V_91 -> V_61 += V_199 ;
V_91 -> V_61 &= ( V_91 -> V_15 . V_16 - 1 ) ;
}
static inline int F_79 ( struct V_90 * V_91 , int V_200 )
{
V_200 ++ ;
V_200 &= ( V_91 -> V_15 . V_16 - 1 ) ;
return V_200 ;
}
void F_80 ( struct V_1 * V_2 , struct V_90 * V_91 , int V_5 )
{
T_1 V_161 ;
V_161 = F_4 ( V_2 , V_100 , V_5 ) ;
V_161 |= V_201 ;
F_28 ( V_2 , V_100 , V_5 , V_161 ) ;
F_28 ( V_2 , V_202 , V_5 , 0 ) ;
}
void F_81 ( struct V_1 * V_2 , int V_5 )
{
T_1 V_161 ;
V_161 = F_4 ( V_2 , V_100 , V_5 ) ;
V_161 &= ~ V_201 ;
F_28 ( V_2 , V_100 , V_5 , V_161 ) ;
}
void F_82 ( struct V_203 * V_13 , struct V_90 * V_91 ,
int V_5 )
{
T_1 V_61 , V_62 ;
struct V_41 * V_45 ;
struct V_1 * V_2 = F_83 ( V_13 ) ;
struct V_204 * V_205 ;
V_61 = F_4 ( V_2 , V_206 , V_5 ) >> 4 ;
V_62 = F_4 ( V_2 , V_207 , V_5 ) >> 4 ;
while ( V_91 -> V_61 != V_61 ) {
V_205 = (struct V_204 * ) F_84 ( V_91 , V_91 -> V_61 ) ;
if ( V_205 -> V_208 != V_209 ) {
F_77 ( V_91 , 1 ) ;
continue;
}
V_45 = (struct V_41 * ) V_91 -> V_94 [ V_91 -> V_61 ] ;
if ( V_45 )
F_45 ( V_45 ) ;
F_85 ( 1 , ( V_210 * ) & V_13 -> V_211 . V_212 ) ;
F_85 ( V_205 -> V_213 ,
( V_210 * ) & V_13 -> V_211 . V_214 ) ;
F_77 ( V_91 , V_205 -> V_215 + 1 ) ;
}
}
static int F_86 ( struct V_41 * V_45 )
{
struct V_216 * V_217 = F_87 ( V_45 ) ;
unsigned int V_218 = F_88 ( V_45 ) + F_89 ( V_45 ) ;
unsigned int V_219 = V_45 -> V_43 - V_218 ;
unsigned int V_220 = V_217 -> V_221 ;
long V_222 = - 1 ;
long V_223 = F_90 ( V_45 ) - V_218 ;
long V_224 = 0 ;
long V_225 ;
int V_226 = 0 ;
int V_227 ;
for ( V_227 = 0 ; V_227 < V_217 -> V_228 ; V_227 ++ ) {
unsigned int V_229 = 0 ;
for ( V_226 ++ ; V_229 < V_220 ; V_226 ++ ) {
while ( V_224 >= V_223 ) {
V_222 ++ ;
V_223 = F_91 ( & V_217 -> V_230 [ V_222 ] ) ;
V_224 = 0 ;
}
V_225 = V_220 - V_229 ;
if ( V_225 > V_223 - V_224 )
V_225 = V_223 - V_224 ;
V_224 += V_225 ;
V_229 += V_225 ;
}
V_219 -= V_220 ;
if ( V_219 < V_220 )
V_220 = V_219 ;
}
return V_226 + V_217 -> V_228 ;
}
static int F_92 ( struct V_1 * V_2 , struct V_41 * V_45 )
{
int V_215 = V_231 ;
if ( F_87 ( V_45 ) -> V_221 && ! V_2 -> V_232 ) {
V_215 = F_86 ( V_45 ) ;
return V_215 ;
}
if ( V_2 -> V_233 && V_2 -> V_232 && F_87 ( V_45 ) -> V_221 )
V_215 += V_234 ;
if ( F_87 ( V_45 ) -> V_235 )
V_215 += F_87 ( V_45 ) -> V_235 ;
return V_215 ;
}
static inline void
F_93 ( struct V_1 * V_2 , struct V_90 * V_91 , int V_200 ,
int V_215 , struct V_41 * V_45 , int V_43 )
{
int V_236 ;
struct V_204 * V_205 ;
V_205 = (struct V_204 * ) F_84 ( V_91 , V_200 ) ;
memset ( V_205 , 0 , V_92 ) ;
V_205 -> V_208 = V_209 ;
if ( V_2 -> V_233 && V_2 -> V_232 && F_87 ( V_45 ) -> V_221 ) {
V_205 -> V_215 = V_215 - V_234 ;
} else {
V_91 -> V_94 [ V_200 ] = ( T_1 ) V_45 ;
V_205 -> V_237 = 1 ;
V_205 -> V_215 = V_215 ;
}
V_205 -> V_213 = V_43 ;
if ( V_45 -> V_238 == V_239 ) {
V_205 -> V_240 = 1 ;
V_205 -> V_241 = F_94 ( V_45 ) ;
V_205 -> V_242 = F_88 ( V_45 ) ;
V_236 = F_95 ( V_45 ) -> V_243 ;
switch ( V_236 ) {
case V_244 :
V_205 -> V_245 = V_246 ;
break;
case V_247 :
V_205 -> V_245 = V_248 ;
break;
case V_249 :
V_205 -> V_245 = V_250 ;
break;
}
}
if ( V_2 -> V_232 && F_87 ( V_45 ) -> V_221 ) {
V_205 -> V_251 = 1 ;
V_205 -> V_252 = F_88 ( V_45 ) + F_89 ( V_45 ) ;
V_205 -> V_253 = F_87 ( V_45 ) -> V_221 ;
V_205 -> V_254 = F_94 ( V_45 ) - 2 ;
F_14 ( V_2 -> V_38 -> V_39 -> V_255 ) ;
}
}
static inline void F_96 ( struct V_90 * V_91 , int V_200 ,
int V_19 , T_1 V_44 )
{
struct V_256 * V_257 ;
V_200 &= ( V_91 -> V_15 . V_16 - 1 ) ;
V_257 = (struct V_256 * ) F_84 ( V_91 , V_200 ) ;
memset ( V_257 , 0 , V_92 ) ;
V_257 -> V_208 = V_258 ;
V_257 -> V_259 = V_260 ;
V_257 -> V_19 = V_19 ;
V_257 -> V_261 = V_44 ;
}
static inline void F_97 ( struct V_90 * V_91 , int V_200 ,
int V_262 , struct V_41 * V_45 )
{
struct V_263 * V_264 ;
struct V_204 * V_205 ;
V_91 -> V_94 [ V_200 ] = ( T_1 ) V_45 ;
V_205 = (struct V_204 * ) F_84 ( V_91 , V_200 ) ;
memset ( V_205 , 0 , V_92 ) ;
V_205 -> V_208 = V_209 ;
V_205 -> V_237 = 1 ;
V_205 -> V_265 = 1 ;
V_205 -> V_215 = V_234 - 1 ;
V_205 -> V_213 = 1 ;
V_205 -> V_266 = V_262 ;
V_200 = F_79 ( V_91 , V_200 ) ;
V_264 = (struct V_263 * ) F_84 ( V_91 , V_200 ) ;
memset ( V_264 , 0 , V_92 ) ;
V_264 -> V_208 = V_267 ;
V_264 -> V_43 = 1 ;
}
static inline void F_98 ( struct V_1 * V_2 , struct V_41 * V_45 ,
int V_163 , int V_199 )
{
struct V_268 * V_269 ;
V_269 = F_99 ( V_2 -> V_38 -> V_13 ,
F_100 ( V_45 ) ) ;
F_101 ( V_269 , V_45 -> V_43 ) ;
F_27 () ;
F_28 ( V_2 , V_202 ,
V_163 , V_199 ) ;
}
static int F_102 ( struct V_1 * V_2 , struct V_90 * V_91 ,
int V_163 , int V_200 , struct V_41 * V_45 )
{
struct V_270 V_251 ;
int V_271 = 0 , V_199 = 0 ;
int V_272 , V_273 , V_274 ;
int V_275 = V_200 ;
int V_276 = F_88 ( V_45 ) + F_89 ( V_45 ) ;
V_252 ( V_45 , & V_251 ) ;
V_273 = V_45 -> V_43 - V_276 ;
while ( V_273 > 0 ) {
char * V_205 ;
V_275 = V_200 ;
V_274 = F_71 ( int , F_87 ( V_45 ) -> V_221 , V_273 ) ;
V_273 -= V_274 ;
V_200 = F_79 ( V_91 , V_200 ) ;
V_205 = V_91 -> V_97 + V_200 * V_98 ;
F_103 ( V_45 , V_205 , & V_251 , V_274 , V_273 == 0 ) ;
F_96 ( V_91 , V_200 , V_276 ,
V_91 -> V_99 +
V_200 * V_98 ) ;
V_271 = 2 ;
V_272 = V_276 ;
while ( V_274 > 0 ) {
int V_19 ;
V_19 = F_71 ( int , V_251 . V_19 , V_274 ) ;
V_200 = F_79 ( V_91 , V_200 ) ;
F_96 ( V_91 , V_200 , V_19 ,
F_24 ( V_251 . V_44 ) ) ;
V_271 ++ ;
V_272 += V_19 ;
V_274 -= V_19 ;
F_104 ( V_45 , & V_251 , V_19 ) ;
}
F_93 ( V_2 , V_91 , V_275 ,
V_271 - 1 , V_45 , V_272 ) ;
V_91 -> V_94 [ V_275 ] = ( T_1 ) NULL ;
V_200 = F_79 ( V_91 , V_200 ) ;
V_199 += V_271 ;
}
V_91 -> V_94 [ V_275 ] = ( T_1 ) V_45 ;
F_98 ( V_2 , V_45 , V_163 , V_199 ) ;
F_14 ( V_2 -> V_38 -> V_39 -> V_255 ) ;
return 1 ;
}
int F_105 ( struct V_1 * V_2 , struct V_90 * V_91 ,
struct V_41 * V_45 , V_190 V_163 )
{
int V_277 , V_19 ;
int V_215 , V_262 = 0 ;
int V_200 ;
V_215 = F_92 ( V_2 , V_45 ) ;
if ( V_215 > F_106 ( & V_91 -> V_95 ) )
goto V_278;
V_200 = F_75 ( V_91 , V_215 ) ;
if ( F_87 ( V_45 ) -> V_221 && ! V_2 -> V_232 )
return F_102 ( V_2 , V_91 , V_163 , V_200 , V_45 ) ;
F_93 ( V_2 , V_91 , V_200 , V_215 - 1 ,
V_45 , V_45 -> V_43 ) ;
V_262 = V_200 ;
V_200 = F_79 ( V_91 , V_200 ) ;
V_19 = F_107 ( V_45 ) ? F_90 ( V_45 ) : V_45 -> V_43 ;
F_96 ( V_91 , V_200 , V_19 , F_24 ( V_45 -> V_44 ) ) ;
if ( ! F_107 ( V_45 ) )
goto V_279;
for ( V_277 = 0 ; V_277 < F_87 ( V_45 ) -> V_235 ; V_277 ++ ) {
const struct V_280 * V_281 ;
V_281 = & F_87 ( V_45 ) -> V_230 [ V_277 ] ;
V_200 = F_79 ( V_91 , V_200 ) ;
V_19 = F_91 ( V_281 ) ;
F_96 ( V_91 , V_200 , V_19 ,
F_24 (
F_108 ( V_281 ) ) ) ;
}
V_279:
if ( V_2 -> V_233 && F_87 ( V_45 ) -> V_221 ) {
V_200 = F_79 ( V_91 , V_200 ) ;
F_97 ( V_91 , V_200 , V_262 , V_45 ) ;
}
F_98 ( V_2 , V_45 , V_163 , V_215 ) ;
return 1 ;
V_278:
V_2 = V_2 -> V_38 ;
F_109 ( V_2 -> V_13 , L_4 ) ;
return 0 ;
}
static inline unsigned F_110 ( unsigned V_277 )
{
#ifdef F_66
return ( V_277 & ~ 3 ) + 3 - ( V_277 & 3 ) ;
#else
return V_277 ;
#endif
}
struct V_41 * F_111 ( struct V_1 * V_2 , struct V_282 * V_283 )
{
int V_281 ;
int V_284 = 0 ;
struct V_41 * V_45 = NULL ;
struct V_285 * V_285 ;
int V_286 ;
T_5 * V_287 = NULL ;
T_1 * V_288 = NULL ;
V_287 = ( void * ) V_283 + ( 3 * sizeof( T_1 ) ) ;
if ( ! V_2 -> V_232 )
V_288 = ( void * ) V_283 + ( 6 * sizeof( T_1 ) ) ;
else
V_288 = ( void * ) V_283 + ( 7 * sizeof( T_1 ) ) ;
F_109 ( V_2 -> V_13 , L_5 ,
V_289 , V_283 -> V_290 , V_283 -> V_291 , V_283 -> V_292 ) ;
for ( V_281 = 0 ; V_281 < V_283 -> V_290 ; V_281 ++ ) {
V_284 = V_287 [ F_110 ( V_281 ) ] ;
if ( ! V_281 ) {
V_45 = F_16 ( V_2 ,
* V_288 - V_283 -> V_293 ,
V_284 ) ;
if ( ! V_45 )
return NULL ;
F_112 ( V_45 , V_283 -> V_293 ) ;
F_113 ( V_45 , V_284 ) ;
} else {
V_285 = F_20 ( F_17 ( * V_288 ) ) ;
V_286 = F_17 ( * V_288 ) - F_15 ( V_285 ) ;
F_114 ( V_45 , F_87 ( V_45 ) -> V_235 , V_285 ,
V_286 , V_284 , V_46 ) ;
}
V_288 ++ ;
}
return V_45 ;
}
static T_1 F_115 ( int V_294 , int V_295 )
{
T_1 V_11 ;
switch ( V_294 ) {
case V_296 :
V_11 = ( ( 1ULL << V_295 ) << V_297 ) ;
break;
case V_298 :
V_11 = ( ( 1ULL << V_295 ) << V_299 ) ;
break;
case V_77 :
V_11 = ( ( 1ULL << V_295 ) << V_300 ) ;
break;
case V_301 :
V_11 = ( 1ULL << V_302 ) ;
break;
case V_303 :
V_11 = ( 1ULL << V_304 ) ;
break;
case V_305 :
V_11 = ( 1ULL << V_306 ) ;
break;
case V_307 :
V_11 = ( 1ULL << V_308 ) ;
break;
default:
V_11 = 0 ;
}
return V_11 ;
}
void F_30 ( struct V_1 * V_2 , int V_294 , int V_295 )
{
T_1 V_309 = F_115 ( V_294 , V_295 ) ;
if ( ! V_309 ) {
F_109 ( V_2 -> V_13 ,
L_6 ) ;
return;
}
F_116 ( V_2 , V_310 ,
F_117 ( V_2 , V_310 ) | V_309 ) ;
}
void F_118 ( struct V_1 * V_2 , int V_294 , int V_295 )
{
T_1 V_309 = F_115 ( V_294 , V_295 ) ;
if ( ! V_309 ) {
F_109 ( V_2 -> V_13 ,
L_7 ) ;
return;
}
F_116 ( V_2 , V_311 , V_309 ) ;
}
void F_119 ( struct V_1 * V_2 , int V_294 , int V_295 )
{
T_1 V_309 = F_115 ( V_294 , V_295 ) ;
if ( ! V_309 ) {
F_109 ( V_2 -> V_13 ,
L_8 ) ;
return;
}
F_116 ( V_2 , V_312 , V_309 ) ;
}
int F_120 ( struct V_1 * V_2 , int V_294 , int V_295 )
{
T_1 V_309 = F_115 ( V_294 , V_295 ) ;
if ( ! V_309 ) {
F_109 ( V_2 -> V_13 ,
L_9 ) ;
return 0 ;
}
return V_309 & F_117 ( V_2 , V_310 ) ;
}
void F_121 ( struct V_1 * V_2 , int V_313 )
{
struct V_129 * V_130 ;
#define F_122 ( V_6 ) \
nicvf_reg_read(nic, NIC_QSET_RQ_0_7_STAT_0_1 |\
(rq_idx << NIC_Q_NUM_SHIFT) | (reg << 3))
V_130 = & V_2 -> V_64 -> V_130 [ V_313 ] ;
V_130 -> V_211 . V_314 = F_122 ( V_315 ) ;
V_130 -> V_211 . V_316 = F_122 ( V_317 ) ;
}
void F_123 ( struct V_1 * V_2 , int V_318 )
{
struct V_90 * V_91 ;
#define F_124 ( V_6 ) \
nicvf_reg_read(nic, NIC_QSET_SQ_0_7_STAT_0_1 |\
(sq_idx << NIC_Q_NUM_SHIFT) | (reg << 3))
V_91 = & V_2 -> V_64 -> V_91 [ V_318 ] ;
V_91 -> V_211 . V_314 = F_124 ( V_315 ) ;
V_91 -> V_211 . V_316 = F_124 ( V_317 ) ;
}
int F_125 ( struct V_1 * V_2 , struct V_282 * V_283 )
{
if ( ! V_283 -> V_319 && ! V_283 -> V_320 )
return 0 ;
if ( F_126 ( V_2 ) )
F_6 ( V_2 -> V_13 ,
L_10 ,
V_2 -> V_13 -> V_321 ,
V_283 -> V_319 , V_283 -> V_320 ) ;
switch ( V_283 -> V_320 ) {
case V_322 :
F_14 ( V_2 -> V_39 -> V_323 ) ;
break;
case V_324 :
F_14 ( V_2 -> V_39 -> V_325 ) ;
break;
case V_326 :
F_14 ( V_2 -> V_39 -> V_327 ) ;
break;
case V_328 :
F_14 ( V_2 -> V_39 -> V_329 ) ;
break;
case V_330 :
F_14 ( V_2 -> V_39 -> V_331 ) ;
break;
case V_332 :
F_14 ( V_2 -> V_39 -> V_333 ) ;
break;
case V_334 :
F_14 ( V_2 -> V_39 -> V_335 ) ;
break;
case V_336 :
F_14 ( V_2 -> V_39 -> V_337 ) ;
break;
case V_338 :
F_14 ( V_2 -> V_39 -> V_339 ) ;
break;
case V_340 :
F_14 ( V_2 -> V_39 -> V_341 ) ;
break;
case V_342 :
F_14 ( V_2 -> V_39 -> V_343 ) ;
break;
case V_344 :
F_14 ( V_2 -> V_39 -> V_345 ) ;
break;
case V_346 :
F_14 ( V_2 -> V_39 -> V_347 ) ;
break;
case V_348 :
F_14 ( V_2 -> V_39 -> V_349 ) ;
break;
case V_350 :
F_14 ( V_2 -> V_39 -> V_351 ) ;
break;
case V_352 :
F_14 ( V_2 -> V_39 -> V_353 ) ;
break;
case V_354 :
F_14 ( V_2 -> V_39 -> V_355 ) ;
break;
case V_356 :
F_14 ( V_2 -> V_39 -> V_357 ) ;
break;
case V_358 :
F_14 ( V_2 -> V_39 -> V_359 ) ;
break;
case V_360 :
F_14 ( V_2 -> V_39 -> V_361 ) ;
break;
case V_362 :
F_14 ( V_2 -> V_39 -> V_363 ) ;
break;
case V_364 :
F_14 ( V_2 -> V_39 -> V_365 ) ;
break;
case V_366 :
F_14 ( V_2 -> V_39 -> V_367 ) ;
break;
case V_368 :
F_14 ( V_2 -> V_39 -> V_369 ) ;
break;
}
return 1 ;
}
int F_127 ( struct V_1 * V_2 , struct V_370 * V_371 )
{
switch ( V_371 -> V_372 ) {
case V_373 :
return 0 ;
case V_374 :
F_14 ( V_2 -> V_39 -> V_375 ) ;
break;
case V_376 :
F_14 ( V_2 -> V_39 -> V_377 ) ;
break;
case V_378 :
F_14 ( V_2 -> V_39 -> V_379 ) ;
break;
case V_380 :
F_14 ( V_2 -> V_39 -> V_381 ) ;
break;
case V_382 :
F_14 ( V_2 -> V_39 -> V_383 ) ;
break;
case V_384 :
F_14 ( V_2 -> V_39 -> V_385 ) ;
break;
case V_386 :
F_14 ( V_2 -> V_39 -> V_387 ) ;
break;
case V_388 :
F_14 ( V_2 -> V_39 -> V_389 ) ;
break;
case V_390 :
F_14 ( V_2 -> V_39 -> V_391 ) ;
break;
case V_392 :
F_14 ( V_2 -> V_39 -> V_393 ) ;
break;
case V_394 :
F_14 ( V_2 -> V_39 -> V_395 ) ;
break;
case V_396 :
F_14 ( V_2 -> V_39 -> V_397 ) ;
break;
case V_398 :
F_14 ( V_2 -> V_39 -> V_399 ) ;
break;
case V_400 :
F_14 ( V_2 -> V_39 -> V_401 ) ;
break;
}
return 1 ;
}

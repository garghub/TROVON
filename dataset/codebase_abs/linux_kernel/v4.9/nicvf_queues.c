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
V_104 . V_130 . V_143 = ( 1ULL << 63 ) | ( 1ULL << 62 ) | ( V_64 -> V_133 << 0 ) ;
F_49 ( V_2 , & V_104 ) ;
V_104 . V_130 . V_105 = V_145 ;
V_104 . V_130 . V_143 = ( 1ULL << 62 ) | ( V_146 << 8 ) ;
F_49 ( V_2 , & V_104 ) ;
if ( ! V_2 -> V_147 && ( V_5 == 0 ) ) {
F_28 ( V_2 , V_119 , 0 ,
( F_55 ( 24 ) | F_55 ( 23 ) | F_55 ( 21 ) ) ) ;
F_52 ( V_2 , V_2 -> V_13 -> V_116 ) ;
}
memset ( & V_117 , 0 , sizeof( struct V_117 ) ) ;
V_117 . V_148 = 1 ;
V_117 . V_149 = 0 ;
F_28 ( V_2 , V_131 , V_5 , * ( T_1 * ) & V_117 ) ;
}
void F_56 ( struct V_1 * V_2 , struct V_63 * V_64 ,
int V_5 , bool V_56 )
{
struct V_83 * V_84 ;
struct V_150 V_150 ;
V_84 = & V_64 -> V_84 [ V_5 ] ;
V_84 -> V_56 = V_56 ;
if ( ! V_84 -> V_56 ) {
F_50 ( V_2 , V_64 , V_5 ) ;
return;
}
F_28 ( V_2 , V_108 , V_5 , V_109 ) ;
if ( ! V_84 -> V_56 )
return;
F_57 ( & V_84 -> V_151 ) ;
F_28 ( V_2 , V_152 ,
V_5 , ( T_1 ) ( V_84 -> V_15 . V_26 ) ) ;
memset ( & V_150 , 0 , sizeof( struct V_150 ) ) ;
V_150 . V_148 = 1 ;
V_150 . V_153 = 0 ;
V_150 . V_139 = 0 ;
V_150 . V_154 = V_155 ;
V_150 . V_156 = 0 ;
F_28 ( V_2 , V_108 , V_5 , * ( T_1 * ) & V_150 ) ;
F_28 ( V_2 , V_157 , V_5 , V_84 -> V_57 ) ;
F_28 ( V_2 , V_107 ,
V_5 , V_89 ) ;
}
static void F_58 ( struct V_1 * V_2 , struct V_63 * V_64 ,
int V_5 , bool V_56 )
{
union V_103 V_104 = {} ;
struct V_90 * V_91 ;
struct V_158 V_158 ;
V_91 = & V_64 -> V_91 [ V_5 ] ;
V_91 -> V_56 = V_56 ;
if ( ! V_91 -> V_56 ) {
F_47 ( V_2 , V_64 , V_5 ) ;
return;
}
F_28 ( V_2 , V_100 , V_5 , V_102 ) ;
V_91 -> V_132 = V_64 -> V_133 ;
V_91 -> V_134 = V_5 ;
V_104 . V_91 . V_105 = V_159 ;
V_104 . V_91 . V_141 = V_64 -> V_133 ;
V_104 . V_91 . V_160 = V_5 ;
V_104 . V_91 . V_147 = V_2 -> V_147 ;
V_104 . V_91 . V_143 = ( V_91 -> V_132 << 3 ) | V_91 -> V_134 ;
F_49 ( V_2 , & V_104 ) ;
F_28 ( V_2 , V_161 ,
V_5 , ( T_1 ) ( V_91 -> V_15 . V_26 ) ) ;
memset ( & V_158 , 0 , sizeof( struct V_158 ) ) ;
V_158 . V_148 = 1 ;
V_158 . V_153 = 0 ;
V_158 . V_162 = 0 ;
V_158 . V_154 = V_163 ;
V_158 . V_164 = 0 ;
F_28 ( V_2 , V_100 , V_5 , * ( T_1 * ) & V_158 ) ;
F_28 ( V_2 , V_165 , V_5 , V_91 -> V_57 ) ;
if ( F_59 ( V_5 ) ) {
F_60 ( V_5 , & V_91 -> V_166 ) ;
F_61 ( V_2 -> V_13 ,
& V_91 -> V_166 , V_5 ) ;
}
}
static void F_62 ( struct V_1 * V_2 , struct V_63 * V_64 ,
int V_5 , bool V_56 )
{
struct V_47 * V_47 ;
struct V_167 V_167 ;
V_47 = & V_64 -> V_47 [ V_5 ] ;
F_51 ( V_2 , V_47 , V_5 ) ;
if ( ! V_56 )
return;
F_28 ( V_2 , V_168 ,
V_5 , ( T_1 ) ( V_47 -> V_15 . V_26 ) ) ;
memset ( & V_167 , 0 , sizeof( struct V_167 ) ) ;
V_167 . V_148 = 1 ;
V_167 . V_153 = 0 ;
V_167 . V_162 = 0 ;
V_167 . V_154 = V_169 ;
V_167 . V_156 = 0 ;
V_167 . V_170 = V_47 -> V_55 / 128 ;
F_28 ( V_2 , V_113 ,
V_5 , * ( T_1 * ) & V_167 ) ;
F_28 ( V_2 , V_76 ,
V_5 , V_64 -> V_73 - 1 ) ;
F_28 ( V_2 , V_171 ,
V_5 , V_47 -> V_57 - 1 ) ;
}
void F_63 ( struct V_1 * V_2 , bool V_56 )
{
union V_103 V_104 = {} ;
struct V_63 * V_64 = V_2 -> V_64 ;
struct V_172 * V_172 ;
if ( ! V_64 ) {
F_64 ( V_2 -> V_13 ,
L_3 ) ;
return;
}
V_64 -> V_56 = V_56 ;
V_64 -> V_133 = V_2 -> V_173 ;
V_104 . V_64 . V_105 = V_174 ;
V_104 . V_64 . V_175 = V_64 -> V_133 ;
V_104 . V_64 . V_121 = V_2 -> V_121 ;
V_104 . V_64 . V_143 = 0 ;
V_172 = (struct V_172 * ) & V_104 . V_64 . V_143 ;
if ( V_64 -> V_56 ) {
V_172 -> V_148 = 1 ;
#ifdef F_65
V_172 -> V_176 = 1 ;
#endif
V_172 -> V_177 = V_64 -> V_133 ;
}
F_49 ( V_2 , & V_104 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_63 * V_64 = V_2 -> V_64 ;
for ( V_5 = 0 ; V_5 < V_64 -> V_66 ; V_5 ++ )
F_25 ( V_2 , & V_64 -> V_47 [ V_5 ] ) ;
for ( V_5 = 0 ; V_5 < V_64 -> V_178 ; V_5 ++ )
F_38 ( V_2 , & V_64 -> V_84 [ V_5 ] ) ;
for ( V_5 = 0 ; V_5 < V_64 -> V_179 ; V_5 ++ )
F_43 ( V_2 , & V_64 -> V_91 [ V_5 ] ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_63 * V_64 = V_2 -> V_64 ;
for ( V_5 = 0 ; V_5 < V_64 -> V_66 ; V_5 ++ ) {
if ( F_22 ( V_2 , & V_64 -> V_47 [ V_5 ] , V_64 -> V_73 ,
V_180 ) )
goto V_181;
}
for ( V_5 = 0 ; V_5 < V_64 -> V_179 ; V_5 ++ ) {
if ( F_39 ( V_2 , & V_64 -> V_91 [ V_5 ] , V_64 -> V_182 ) )
goto V_181;
}
for ( V_5 = 0 ; V_5 < V_64 -> V_178 ; V_5 ++ ) {
if ( F_36 ( V_2 , & V_64 -> V_84 [ V_5 ] , V_64 -> V_183 ) )
goto V_181;
}
return 0 ;
V_181:
F_66 ( V_2 ) ;
return - V_25 ;
}
int F_68 ( struct V_1 * V_2 )
{
struct V_63 * V_64 ;
V_64 = F_69 ( & V_2 -> V_21 -> V_22 , sizeof( * V_64 ) , V_24 ) ;
if ( ! V_64 )
return - V_25 ;
V_2 -> V_64 = V_64 ;
V_64 -> V_66 = V_184 ;
V_64 -> V_185 = F_70 ( V_186 , V_187 , F_71 () ) ;
V_64 -> V_179 = F_70 ( V_186 , V_188 , F_71 () ) ;
V_64 -> V_178 = F_72 ( V_186 , V_64 -> V_185 , V_64 -> V_179 ) ;
V_64 -> V_73 = V_189 ;
V_64 -> V_182 = V_190 ;
V_64 -> V_183 = V_191 ;
V_2 -> V_192 = V_64 -> V_185 ;
V_2 -> V_193 = V_64 -> V_179 ;
return 0 ;
}
int F_73 ( struct V_1 * V_2 , bool V_56 )
{
bool V_194 = false ;
struct V_63 * V_64 = V_2 -> V_64 ;
int V_5 ;
if ( ! V_64 )
return 0 ;
if ( V_56 ) {
if ( F_67 ( V_2 ) )
return - V_25 ;
for ( V_5 = 0 ; V_5 < V_64 -> V_179 ; V_5 ++ )
F_58 ( V_2 , V_64 , V_5 , V_56 ) ;
for ( V_5 = 0 ; V_5 < V_64 -> V_178 ; V_5 ++ )
F_56 ( V_2 , V_64 , V_5 , V_56 ) ;
for ( V_5 = 0 ; V_5 < V_64 -> V_66 ; V_5 ++ )
F_62 ( V_2 , V_64 , V_5 , V_56 ) ;
for ( V_5 = 0 ; V_5 < V_64 -> V_185 ; V_5 ++ )
F_54 ( V_2 , V_64 , V_5 , V_56 ) ;
} else {
for ( V_5 = 0 ; V_5 < V_64 -> V_185 ; V_5 ++ )
F_54 ( V_2 , V_64 , V_5 , V_194 ) ;
for ( V_5 = 0 ; V_5 < V_64 -> V_66 ; V_5 ++ )
F_62 ( V_2 , V_64 , V_5 , V_194 ) ;
for ( V_5 = 0 ; V_5 < V_64 -> V_179 ; V_5 ++ )
F_58 ( V_2 , V_64 , V_5 , V_194 ) ;
for ( V_5 = 0 ; V_5 < V_64 -> V_178 ; V_5 ++ )
F_56 ( V_2 , V_64 , V_5 , V_194 ) ;
F_66 ( V_2 ) ;
}
F_53 ( V_2 ) ;
return 0 ;
}
static inline int F_74 ( struct V_90 * V_91 , int V_195 )
{
int V_196 ;
V_196 = V_91 -> V_62 ;
F_75 ( V_195 , & V_91 -> V_95 ) ;
V_91 -> V_62 += V_195 ;
V_91 -> V_62 &= ( V_91 -> V_15 . V_16 - 1 ) ;
return V_196 ;
}
void F_76 ( struct V_90 * V_91 , int V_195 )
{
F_77 ( V_195 , & V_91 -> V_95 ) ;
V_91 -> V_61 += V_195 ;
V_91 -> V_61 &= ( V_91 -> V_15 . V_16 - 1 ) ;
}
static inline int F_78 ( struct V_90 * V_91 , int V_196 )
{
V_196 ++ ;
V_196 &= ( V_91 -> V_15 . V_16 - 1 ) ;
return V_196 ;
}
void F_79 ( struct V_1 * V_2 , struct V_90 * V_91 , int V_5 )
{
T_1 V_158 ;
V_158 = F_4 ( V_2 , V_100 , V_5 ) ;
V_158 |= V_197 ;
F_28 ( V_2 , V_100 , V_5 , V_158 ) ;
F_28 ( V_2 , V_198 , V_5 , 0 ) ;
}
void F_80 ( struct V_1 * V_2 , int V_5 )
{
T_1 V_158 ;
V_158 = F_4 ( V_2 , V_100 , V_5 ) ;
V_158 &= ~ V_197 ;
F_28 ( V_2 , V_100 , V_5 , V_158 ) ;
}
void F_81 ( struct V_199 * V_13 , struct V_90 * V_91 ,
int V_5 )
{
T_1 V_61 , V_62 ;
struct V_41 * V_45 ;
struct V_1 * V_2 = F_82 ( V_13 ) ;
struct V_200 * V_201 ;
V_61 = F_4 ( V_2 , V_202 , V_5 ) >> 4 ;
V_62 = F_4 ( V_2 , V_203 , V_5 ) >> 4 ;
while ( V_91 -> V_61 != V_61 ) {
V_201 = (struct V_200 * ) F_83 ( V_91 , V_91 -> V_61 ) ;
if ( V_201 -> V_204 != V_205 ) {
F_76 ( V_91 , 1 ) ;
continue;
}
V_45 = (struct V_41 * ) V_91 -> V_94 [ V_91 -> V_61 ] ;
if ( V_45 )
F_45 ( V_45 ) ;
F_84 ( 1 , ( V_206 * ) & V_13 -> V_207 . V_208 ) ;
F_84 ( V_201 -> V_209 ,
( V_206 * ) & V_13 -> V_207 . V_210 ) ;
F_76 ( V_91 , V_201 -> V_211 + 1 ) ;
}
}
static int F_85 ( struct V_41 * V_45 )
{
struct V_212 * V_213 = F_86 ( V_45 ) ;
unsigned int V_214 = F_87 ( V_45 ) + F_88 ( V_45 ) ;
unsigned int V_215 = V_45 -> V_43 - V_214 ;
unsigned int V_216 = V_213 -> V_217 ;
long V_218 = - 1 ;
long V_219 = F_89 ( V_45 ) - V_214 ;
long V_220 = 0 ;
long V_221 ;
int V_222 = 0 ;
int V_223 ;
for ( V_223 = 0 ; V_223 < V_213 -> V_224 ; V_223 ++ ) {
unsigned int V_225 = 0 ;
for ( V_222 ++ ; V_225 < V_216 ; V_222 ++ ) {
while ( V_220 >= V_219 ) {
V_218 ++ ;
V_219 = F_90 ( & V_213 -> V_226 [ V_218 ] ) ;
V_220 = 0 ;
}
V_221 = V_216 - V_225 ;
if ( V_221 > V_219 - V_220 )
V_221 = V_219 - V_220 ;
V_220 += V_221 ;
V_225 += V_221 ;
}
V_215 -= V_216 ;
if ( V_215 < V_216 )
V_216 = V_215 ;
}
return V_222 + V_213 -> V_224 ;
}
static int F_91 ( struct V_1 * V_2 , struct V_41 * V_45 )
{
int V_211 = V_227 ;
if ( F_86 ( V_45 ) -> V_217 && ! V_2 -> V_228 ) {
V_211 = F_85 ( V_45 ) ;
return V_211 ;
}
if ( V_2 -> V_229 && V_2 -> V_228 && F_86 ( V_45 ) -> V_217 )
V_211 += V_230 ;
if ( F_86 ( V_45 ) -> V_231 )
V_211 += F_86 ( V_45 ) -> V_231 ;
return V_211 ;
}
static inline void
F_92 ( struct V_1 * V_2 , struct V_90 * V_91 , int V_196 ,
int V_211 , struct V_41 * V_45 , int V_43 )
{
int V_232 ;
struct V_200 * V_201 ;
V_201 = (struct V_200 * ) F_83 ( V_91 , V_196 ) ;
memset ( V_201 , 0 , V_92 ) ;
V_201 -> V_204 = V_205 ;
if ( V_2 -> V_229 && V_2 -> V_228 && F_86 ( V_45 ) -> V_217 ) {
V_201 -> V_211 = V_211 - V_230 ;
} else {
V_91 -> V_94 [ V_196 ] = ( T_1 ) V_45 ;
V_201 -> V_233 = 1 ;
V_201 -> V_211 = V_211 ;
}
V_201 -> V_209 = V_43 ;
if ( V_45 -> V_234 == V_235 ) {
V_201 -> V_236 = 1 ;
V_201 -> V_237 = F_93 ( V_45 ) ;
V_201 -> V_238 = F_87 ( V_45 ) ;
V_232 = F_94 ( V_45 ) -> V_239 ;
switch ( V_232 ) {
case V_240 :
V_201 -> V_241 = V_242 ;
break;
case V_243 :
V_201 -> V_241 = V_244 ;
break;
case V_245 :
V_201 -> V_241 = V_246 ;
break;
}
}
if ( V_2 -> V_228 && F_86 ( V_45 ) -> V_217 ) {
V_201 -> V_247 = 1 ;
V_201 -> V_248 = F_87 ( V_45 ) + F_88 ( V_45 ) ;
V_201 -> V_249 = F_86 ( V_45 ) -> V_217 ;
V_201 -> V_250 = F_93 ( V_45 ) - 2 ;
F_14 ( V_2 -> V_38 -> V_39 -> V_251 ) ;
}
}
static inline void F_95 ( struct V_90 * V_91 , int V_196 ,
int V_19 , T_1 V_44 )
{
struct V_252 * V_253 ;
V_196 &= ( V_91 -> V_15 . V_16 - 1 ) ;
V_253 = (struct V_252 * ) F_83 ( V_91 , V_196 ) ;
memset ( V_253 , 0 , V_92 ) ;
V_253 -> V_204 = V_254 ;
V_253 -> V_255 = V_256 ;
V_253 -> V_19 = V_19 ;
V_253 -> V_257 = V_44 ;
}
static inline void F_96 ( struct V_90 * V_91 , int V_196 ,
int V_258 , struct V_41 * V_45 )
{
struct V_259 * V_260 ;
struct V_200 * V_201 ;
V_91 -> V_94 [ V_196 ] = ( T_1 ) V_45 ;
V_201 = (struct V_200 * ) F_83 ( V_91 , V_196 ) ;
memset ( V_201 , 0 , V_92 ) ;
V_201 -> V_204 = V_205 ;
V_201 -> V_233 = 1 ;
V_201 -> V_261 = 1 ;
V_201 -> V_211 = V_230 - 1 ;
V_201 -> V_209 = 1 ;
V_201 -> V_262 = V_258 ;
V_196 = F_78 ( V_91 , V_196 ) ;
V_260 = (struct V_259 * ) F_83 ( V_91 , V_196 ) ;
memset ( V_260 , 0 , V_92 ) ;
V_260 -> V_204 = V_263 ;
V_260 -> V_43 = 1 ;
}
static inline void F_97 ( struct V_1 * V_2 , struct V_41 * V_45 ,
int V_160 , int V_195 )
{
struct V_264 * V_265 ;
V_265 = F_98 ( V_2 -> V_38 -> V_13 ,
F_99 ( V_45 ) ) ;
F_100 ( V_265 , V_45 -> V_43 ) ;
F_27 () ;
F_28 ( V_2 , V_198 ,
V_160 , V_195 ) ;
}
static int F_101 ( struct V_1 * V_2 , struct V_90 * V_91 ,
int V_160 , int V_196 , struct V_41 * V_45 )
{
struct V_266 V_247 ;
int V_267 = 0 , V_195 = 0 ;
int V_268 , V_269 , V_270 ;
int V_271 = V_196 ;
int V_272 = F_87 ( V_45 ) + F_88 ( V_45 ) ;
V_248 ( V_45 , & V_247 ) ;
V_269 = V_45 -> V_43 - V_272 ;
while ( V_269 > 0 ) {
char * V_201 ;
V_271 = V_196 ;
V_270 = F_70 ( int , F_86 ( V_45 ) -> V_217 , V_269 ) ;
V_269 -= V_270 ;
V_196 = F_78 ( V_91 , V_196 ) ;
V_201 = V_91 -> V_97 + V_196 * V_98 ;
F_102 ( V_45 , V_201 , & V_247 , V_270 , V_269 == 0 ) ;
F_95 ( V_91 , V_196 , V_272 ,
V_91 -> V_99 +
V_196 * V_98 ) ;
V_267 = 2 ;
V_268 = V_272 ;
while ( V_270 > 0 ) {
int V_19 ;
V_19 = F_70 ( int , V_247 . V_19 , V_270 ) ;
V_196 = F_78 ( V_91 , V_196 ) ;
F_95 ( V_91 , V_196 , V_19 ,
F_24 ( V_247 . V_44 ) ) ;
V_267 ++ ;
V_268 += V_19 ;
V_270 -= V_19 ;
F_103 ( V_45 , & V_247 , V_19 ) ;
}
F_92 ( V_2 , V_91 , V_271 ,
V_267 - 1 , V_45 , V_268 ) ;
V_91 -> V_94 [ V_271 ] = ( T_1 ) NULL ;
V_196 = F_78 ( V_91 , V_196 ) ;
V_195 += V_267 ;
}
V_91 -> V_94 [ V_271 ] = ( T_1 ) V_45 ;
F_97 ( V_2 , V_45 , V_160 , V_195 ) ;
F_14 ( V_2 -> V_38 -> V_39 -> V_251 ) ;
return 1 ;
}
int F_104 ( struct V_1 * V_2 , struct V_41 * V_45 )
{
int V_273 , V_19 ;
int V_211 , V_258 = 0 ;
int V_160 , V_196 ;
struct V_63 * V_64 ;
struct V_90 * V_91 ;
V_160 = F_99 ( V_45 ) ;
if ( V_160 >= V_188 ) {
V_273 = V_160 / V_188 ;
if ( ! V_2 -> V_122 [ V_273 - 1 ] ) {
F_64 ( V_2 -> V_13 ,
L_4 ,
V_273 - 1 ) ;
return 1 ;
}
V_2 = (struct V_1 * ) V_2 -> V_122 [ V_273 - 1 ] ;
V_160 = V_160 % V_188 ;
}
V_64 = V_2 -> V_64 ;
V_91 = & V_64 -> V_91 [ V_160 ] ;
V_211 = F_91 ( V_2 , V_45 ) ;
if ( V_211 > F_105 ( & V_91 -> V_95 ) )
goto V_274;
V_196 = F_74 ( V_91 , V_211 ) ;
if ( F_86 ( V_45 ) -> V_217 && ! V_2 -> V_228 )
return F_101 ( V_2 , V_91 , V_160 , V_196 , V_45 ) ;
F_92 ( V_2 , V_91 , V_196 , V_211 - 1 ,
V_45 , V_45 -> V_43 ) ;
V_258 = V_196 ;
V_196 = F_78 ( V_91 , V_196 ) ;
V_19 = F_106 ( V_45 ) ? F_89 ( V_45 ) : V_45 -> V_43 ;
F_95 ( V_91 , V_196 , V_19 , F_24 ( V_45 -> V_44 ) ) ;
if ( ! F_106 ( V_45 ) )
goto V_275;
for ( V_273 = 0 ; V_273 < F_86 ( V_45 ) -> V_231 ; V_273 ++ ) {
const struct V_276 * V_277 ;
V_277 = & F_86 ( V_45 ) -> V_226 [ V_273 ] ;
V_196 = F_78 ( V_91 , V_196 ) ;
V_19 = F_90 ( V_277 ) ;
F_95 ( V_91 , V_196 , V_19 ,
F_24 (
F_107 ( V_277 ) ) ) ;
}
V_275:
if ( V_2 -> V_229 && F_86 ( V_45 ) -> V_217 ) {
V_196 = F_78 ( V_91 , V_196 ) ;
F_96 ( V_91 , V_196 , V_258 , V_45 ) ;
}
F_97 ( V_2 , V_45 , V_160 , V_211 ) ;
return 1 ;
V_274:
V_2 = V_2 -> V_38 ;
F_108 ( V_2 -> V_13 , L_5 ) ;
return 0 ;
}
static inline unsigned F_109 ( unsigned V_273 )
{
#ifdef F_65
return ( V_273 & ~ 3 ) + 3 - ( V_273 & 3 ) ;
#else
return V_273 ;
#endif
}
struct V_41 * F_110 ( struct V_1 * V_2 , struct V_278 * V_279 )
{
int V_277 ;
int V_280 = 0 ;
struct V_41 * V_45 = NULL ;
struct V_281 * V_281 ;
int V_282 ;
T_5 * V_283 = NULL ;
T_1 * V_284 = NULL ;
V_283 = ( void * ) V_279 + ( 3 * sizeof( T_1 ) ) ;
if ( ! V_2 -> V_228 )
V_284 = ( void * ) V_279 + ( 6 * sizeof( T_1 ) ) ;
else
V_284 = ( void * ) V_279 + ( 7 * sizeof( T_1 ) ) ;
F_108 ( V_2 -> V_13 , L_6 ,
V_285 , V_279 -> V_286 , V_279 -> V_287 , V_279 -> V_288 ) ;
for ( V_277 = 0 ; V_277 < V_279 -> V_286 ; V_277 ++ ) {
V_280 = V_283 [ F_109 ( V_277 ) ] ;
if ( ! V_277 ) {
V_45 = F_16 ( V_2 ,
* V_284 - V_279 -> V_289 ,
V_280 ) ;
if ( ! V_45 )
return NULL ;
F_111 ( V_45 , V_279 -> V_289 ) ;
F_112 ( V_45 , V_280 ) ;
} else {
V_281 = F_20 ( F_17 ( * V_284 ) ) ;
V_282 = F_17 ( * V_284 ) - F_15 ( V_281 ) ;
F_113 ( V_45 , F_86 ( V_45 ) -> V_231 , V_281 ,
V_282 , V_280 , V_46 ) ;
}
V_284 ++ ;
}
return V_45 ;
}
static T_1 F_114 ( int V_290 , int V_291 )
{
T_1 V_11 ;
switch ( V_290 ) {
case V_292 :
V_11 = ( ( 1ULL << V_291 ) << V_293 ) ;
break;
case V_294 :
V_11 = ( ( 1ULL << V_291 ) << V_295 ) ;
break;
case V_77 :
V_11 = ( ( 1ULL << V_291 ) << V_296 ) ;
break;
case V_297 :
V_11 = ( 1ULL << V_298 ) ;
break;
case V_299 :
V_11 = ( 1ULL << V_300 ) ;
break;
case V_301 :
V_11 = ( 1ULL << V_302 ) ;
break;
case V_303 :
V_11 = ( 1ULL << V_304 ) ;
break;
default:
V_11 = 0 ;
}
return V_11 ;
}
void F_30 ( struct V_1 * V_2 , int V_290 , int V_291 )
{
T_1 V_305 = F_114 ( V_290 , V_291 ) ;
if ( ! V_305 ) {
F_108 ( V_2 -> V_13 ,
L_7 ) ;
return;
}
F_115 ( V_2 , V_306 ,
F_116 ( V_2 , V_306 ) | V_305 ) ;
}
void F_117 ( struct V_1 * V_2 , int V_290 , int V_291 )
{
T_1 V_305 = F_114 ( V_290 , V_291 ) ;
if ( ! V_305 ) {
F_108 ( V_2 -> V_13 ,
L_8 ) ;
return;
}
F_115 ( V_2 , V_307 , V_305 ) ;
}
void F_118 ( struct V_1 * V_2 , int V_290 , int V_291 )
{
T_1 V_305 = F_114 ( V_290 , V_291 ) ;
if ( ! V_305 ) {
F_108 ( V_2 -> V_13 ,
L_9 ) ;
return;
}
F_115 ( V_2 , V_308 , V_305 ) ;
}
int F_119 ( struct V_1 * V_2 , int V_290 , int V_291 )
{
T_1 V_305 = F_114 ( V_290 , V_291 ) ;
if ( ! V_305 ) {
F_108 ( V_2 -> V_13 ,
L_10 ) ;
return 0 ;
}
return V_305 & F_116 ( V_2 , V_306 ) ;
}
void F_120 ( struct V_1 * V_2 , int V_309 )
{
struct V_129 * V_130 ;
#define F_121 ( V_6 ) \
nicvf_reg_read(nic, NIC_QSET_RQ_0_7_STAT_0_1 |\
(rq_idx << NIC_Q_NUM_SHIFT) | (reg << 3))
V_130 = & V_2 -> V_64 -> V_130 [ V_309 ] ;
V_130 -> V_207 . V_310 = F_121 ( V_311 ) ;
V_130 -> V_207 . V_312 = F_121 ( V_313 ) ;
}
void F_122 ( struct V_1 * V_2 , int V_314 )
{
struct V_90 * V_91 ;
#define F_123 ( V_6 ) \
nicvf_reg_read(nic, NIC_QSET_SQ_0_7_STAT_0_1 |\
(sq_idx << NIC_Q_NUM_SHIFT) | (reg << 3))
V_91 = & V_2 -> V_64 -> V_91 [ V_314 ] ;
V_91 -> V_207 . V_310 = F_123 ( V_311 ) ;
V_91 -> V_207 . V_312 = F_123 ( V_313 ) ;
}
int F_124 ( struct V_1 * V_2 , struct V_278 * V_279 )
{
if ( ! V_279 -> V_315 && ! V_279 -> V_316 )
return 0 ;
if ( F_125 ( V_2 ) )
F_6 ( V_2 -> V_13 ,
L_11 ,
V_2 -> V_13 -> V_317 ,
V_279 -> V_315 , V_279 -> V_316 ) ;
switch ( V_279 -> V_316 ) {
case V_318 :
F_14 ( V_2 -> V_39 -> V_319 ) ;
break;
case V_320 :
F_14 ( V_2 -> V_39 -> V_321 ) ;
break;
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
}
return 1 ;
}
int F_126 ( struct V_1 * V_2 , struct V_366 * V_367 )
{
switch ( V_367 -> V_368 ) {
case V_369 :
return 0 ;
case V_370 :
F_14 ( V_2 -> V_39 -> V_371 ) ;
break;
case V_372 :
F_14 ( V_2 -> V_39 -> V_373 ) ;
break;
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
}
return 1 ;
}

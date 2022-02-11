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
V_2 -> V_38 . V_39 ++ ;
return - V_25 ;
}
V_2 -> V_34 = 0 ;
}
V_35:
* V_30 = ( T_1 * ) ( ( T_1 ) F_14 ( V_2 -> V_4 ) + V_2 -> V_34 ) ;
V_2 -> V_34 += V_29 ;
return 0 ;
}
static struct V_40 * F_15 ( struct V_1 * V_2 ,
T_1 V_41 , int V_42 )
{
void * V_43 ;
struct V_40 * V_44 ;
V_43 = F_16 ( V_41 ) ;
V_44 = F_17 ( V_43 , V_45 ) ;
if ( ! V_44 ) {
F_18 ( F_19 ( V_43 ) ) ;
return NULL ;
}
F_20 ( V_44 -> V_43 ) ;
return V_44 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_46 * V_46 ,
int V_47 , int V_48 )
{
int V_49 ;
T_1 * V_30 ;
struct V_50 * V_51 ;
int V_52 ;
V_52 = F_7 ( V_2 , & V_46 -> V_15 , V_47 ,
sizeof( struct V_50 ) ,
V_53 ) ;
if ( V_52 )
return V_52 ;
V_46 -> V_51 = V_46 -> V_15 . V_27 ;
V_46 -> V_54 = V_48 ;
V_46 -> V_55 = true ;
V_46 -> V_56 = V_57 ;
V_2 -> V_4 = NULL ;
for ( V_49 = 0 ; V_49 < V_47 ; V_49 ++ ) {
V_52 = F_12 ( V_2 , V_24 , V_45 ,
& V_30 ) ;
if ( V_52 )
return V_52 ;
V_51 = F_22 ( V_46 , V_49 ) ;
V_51 -> V_58 = F_23 ( V_30 ) >> V_59 ;
}
F_1 ( V_2 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 , struct V_46 * V_46 )
{
int V_60 , V_61 ;
T_1 V_58 ;
struct V_50 * V_51 ;
if ( ! V_46 )
return;
V_46 -> V_55 = false ;
if ( ! V_46 -> V_15 . V_27 )
return;
V_60 = V_46 -> V_60 ;
V_61 = V_46 -> V_61 ;
while ( V_60 != V_61 ) {
V_51 = F_22 ( V_46 , V_60 ) ;
V_58 = V_51 -> V_58 << V_59 ;
F_18 ( F_19 ( F_16 ( V_58 ) ) ) ;
V_60 ++ ;
V_60 &= ( V_46 -> V_15 . V_16 - 1 ) ;
}
V_51 = F_22 ( V_46 , V_61 ) ;
V_58 = V_51 -> V_58 << V_59 ;
F_18 ( F_19 ( F_16 ( V_58 ) ) ) ;
F_10 ( V_2 , & V_46 -> V_15 ) ;
}
static void F_25 ( struct V_1 * V_2 , T_2 V_28 )
{
struct V_62 * V_63 = V_2 -> V_63 ;
int V_64 = V_63 -> V_65 ;
int V_61 , V_66 ;
int V_67 ;
struct V_46 * V_46 ;
struct V_50 * V_51 ;
T_1 * V_30 ;
int V_68 = 0 ;
V_69:
if ( ! V_64 )
return;
V_64 -- ;
V_46 = & V_63 -> V_46 [ V_64 ] ;
if ( ! V_46 -> V_55 )
goto V_70;
V_66 = F_4 ( V_2 , V_71 , V_64 ) ;
V_66 &= 0x7FFFF ;
if ( V_66 >= ( V_63 -> V_72 - 1 ) )
goto V_70;
else
V_67 = V_63 -> V_72 - V_66 - 1 ;
V_61 = F_4 ( V_2 , V_73 , V_64 ) >> 3 ;
while ( V_67 ) {
V_61 ++ ;
V_61 &= ( V_46 -> V_15 . V_16 - 1 ) ;
if ( F_12 ( V_2 , V_28 , V_45 , & V_30 ) )
break;
V_51 = F_22 ( V_46 , V_61 ) ;
V_51 -> V_58 = F_23 ( V_30 ) >> V_59 ;
V_67 -- ;
V_68 ++ ;
}
F_1 ( V_2 ) ;
F_26 () ;
if ( V_67 )
V_2 -> V_74 = true ;
else
V_2 -> V_74 = false ;
F_27 ( V_2 , V_75 ,
V_64 , V_68 ) ;
V_70:
if ( ! V_2 -> V_74 && V_46 -> V_55 )
F_28 ( V_2 , V_76 , V_64 ) ;
if ( V_64 )
goto V_69;
}
void F_29 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_30 ( V_78 , struct V_1 , V_79 . V_78 ) ;
F_25 ( V_2 , V_24 ) ;
if ( V_2 -> V_74 )
F_31 ( & V_2 -> V_79 , F_32 ( 10 ) ) ;
else
V_2 -> V_80 = false ;
}
void F_33 ( unsigned long V_43 )
{
struct V_1 * V_2 = (struct V_1 * ) V_43 ;
F_25 ( V_2 , V_81 ) ;
if ( V_2 -> V_74 ) {
V_2 -> V_80 = true ;
F_31 ( & V_2 -> V_79 , F_32 ( 10 ) ) ;
}
}
static int F_34 ( struct V_1 * V_2 ,
struct V_82 * V_83 , int V_16 )
{
int V_52 ;
V_52 = F_7 ( V_2 , & V_83 -> V_15 , V_16 , V_84 ,
V_85 ) ;
if ( V_52 )
return V_52 ;
V_83 -> V_51 = V_83 -> V_15 . V_27 ;
V_83 -> V_56 = F_35 ( V_2 -> V_21 ) ? 0 : V_86 ;
V_2 -> V_87 = ( V_88 * 0.05 ) - 1 ;
return 0 ;
}
static void F_36 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
if ( ! V_83 )
return;
if ( ! V_83 -> V_15 . V_27 )
return;
F_10 ( V_2 , & V_83 -> V_15 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_89 * V_90 , int V_16 )
{
int V_52 ;
V_52 = F_7 ( V_2 , & V_90 -> V_15 , V_16 , V_91 ,
V_92 ) ;
if ( V_52 )
return V_52 ;
V_90 -> V_51 = V_90 -> V_15 . V_27 ;
V_90 -> V_93 = F_38 ( V_16 , sizeof( T_1 ) , V_24 ) ;
if ( ! V_90 -> V_93 )
return - V_25 ;
V_90 -> V_60 = 0 ;
V_90 -> V_61 = 0 ;
F_39 ( & V_90 -> V_94 , V_16 - 1 ) ;
V_90 -> V_56 = V_95 ;
V_90 -> V_96 = F_40 ( & V_2 -> V_21 -> V_22 ,
V_16 * V_97 ,
& V_90 -> V_98 , V_24 ) ;
if ( ! V_90 -> V_96 )
return - V_25 ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 , struct V_89 * V_90 )
{
if ( ! V_90 )
return;
if ( ! V_90 -> V_15 . V_27 )
return;
if ( V_90 -> V_96 )
F_11 ( & V_2 -> V_21 -> V_22 ,
V_90 -> V_15 . V_16 * V_97 ,
V_90 -> V_96 , V_90 -> V_98 ) ;
F_42 ( V_90 -> V_93 ) ;
F_10 ( V_2 , & V_90 -> V_15 ) ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_62 * V_63 , int V_5 )
{
F_27 ( V_2 , V_99 , V_5 , 0 ) ;
if ( F_3 ( V_2 , V_5 , V_100 , 21 , 1 , 0x01 ) )
return;
F_27 ( V_2 , V_99 , V_5 , V_101 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_62 * V_63 , int V_5 )
{
union V_102 V_103 = {} ;
V_103 . V_104 . V_104 = V_105 ;
F_45 ( V_2 , & V_103 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_62 * V_63 , int V_5 )
{
F_27 ( V_2 , V_106 , V_5 , 0 ) ;
F_27 ( V_2 , V_107 , V_5 , 0 ) ;
F_27 ( V_2 , V_107 , V_5 , V_108 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_46 * V_46 , int V_5 )
{
T_1 V_109 , V_110 ;
int V_12 = 10 ;
V_46 -> V_60 = F_4 ( V_2 ,
V_111 ,
V_5 ) >> 3 ;
V_46 -> V_61 = F_4 ( V_2 ,
V_73 ,
V_5 ) >> 3 ;
V_110 = F_4 ( V_2 , V_71 , V_5 ) ;
if ( ( ( V_110 >> 62 ) & 0x03 ) == 0x3 )
F_27 ( V_2 , V_112 ,
V_5 , V_113 ) ;
F_27 ( V_2 , V_112 , V_5 , 0 ) ;
if ( F_3 ( V_2 , V_5 , V_71 , 62 , 2 , 0x00 ) )
return;
while ( 1 ) {
V_109 = F_4 ( V_2 ,
V_114 ,
V_5 ) ;
if ( ( V_109 & 0xFFFFFFFF ) == ( ( V_109 >> 32 ) & 0xFFFFFFFF ) )
break;
F_5 ( 1000 , 2000 ) ;
V_12 -- ;
if ( ! V_12 ) {
F_6 ( V_2 -> V_13 ,
L_2 ) ;
return;
}
}
F_27 ( V_2 , V_112 ,
V_5 , V_113 ) ;
if ( F_3 ( V_2 , V_5 , V_71 , 62 , 2 , 0x02 ) )
return;
F_27 ( V_2 , V_112 , V_5 , 0x00 ) ;
if ( F_3 ( V_2 , V_5 , V_71 , 62 , 2 , 0x00 ) )
return;
}
void F_48 ( struct V_1 * V_2 , T_4 V_115 )
{
T_1 V_116 ;
int V_117 ;
V_116 = F_4 ( V_2 , V_118 , 0 ) ;
if ( V_115 & V_119 )
V_116 |= ( 1ULL << 25 ) ;
else
V_116 &= ~ ( 1ULL << 25 ) ;
F_27 ( V_2 , V_118 , 0 , V_116 ) ;
for ( V_117 = 0 ; V_117 < V_2 -> V_120 ; V_117 ++ )
if ( V_2 -> V_121 [ V_117 ] )
F_27 ( V_2 -> V_121 [ V_117 ] ,
V_118 , 0 , V_116 ) ;
}
static void F_49 ( struct V_1 * V_2 , struct V_62 * V_63 ,
int V_5 , bool V_55 )
{
union V_102 V_103 = {} ;
struct V_122 * V_123 ;
struct V_116 V_116 ;
V_123 = & V_63 -> V_123 [ V_5 ] ;
V_123 -> V_55 = V_55 ;
F_27 ( V_2 , V_124 , V_5 , 0 ) ;
if ( ! V_123 -> V_55 ) {
F_44 ( V_2 , V_63 , V_5 ) ;
return;
}
V_123 -> V_125 = V_63 -> V_126 ;
V_123 -> V_127 = V_5 ;
V_123 -> V_128 = V_63 -> V_126 ;
V_123 -> V_129 = V_63 -> V_65 - 1 ;
V_123 -> V_130 = V_63 -> V_126 ;
V_123 -> V_131 = V_63 -> V_65 - 1 ;
V_123 -> V_132 = 1 ;
V_103 . V_123 . V_104 = V_133 ;
V_103 . V_123 . V_134 = V_63 -> V_126 ;
V_103 . V_123 . V_135 = V_5 ;
V_103 . V_123 . V_136 = ( V_123 -> V_132 << 26 ) | ( V_123 -> V_125 << 19 ) |
( V_123 -> V_127 << 16 ) | ( V_123 -> V_130 << 9 ) |
( V_123 -> V_131 << 8 ) |
( V_123 -> V_128 << 1 ) | ( V_123 -> V_129 ) ;
F_45 ( V_2 , & V_103 ) ;
V_103 . V_123 . V_104 = V_137 ;
V_103 . V_123 . V_136 = ( 1ULL << 63 ) | ( 1ULL << 62 ) | ( V_63 -> V_126 << 0 ) ;
F_45 ( V_2 , & V_103 ) ;
V_103 . V_123 . V_104 = V_138 ;
V_103 . V_123 . V_136 = ( 1ULL << 62 ) | ( V_139 << 8 ) ;
F_45 ( V_2 , & V_103 ) ;
F_27 ( V_2 , V_118 , 0 , 0x00 ) ;
if ( ! V_2 -> V_140 )
F_48 ( V_2 , V_2 -> V_13 -> V_115 ) ;
memset ( & V_116 , 0 , sizeof( struct V_116 ) ) ;
V_116 . V_141 = 1 ;
V_116 . V_142 = 0 ;
F_27 ( V_2 , V_124 , V_5 , * ( T_1 * ) & V_116 ) ;
}
void F_50 ( struct V_1 * V_2 , struct V_62 * V_63 ,
int V_5 , bool V_55 )
{
struct V_82 * V_83 ;
struct V_143 V_143 ;
V_83 = & V_63 -> V_83 [ V_5 ] ;
V_83 -> V_55 = V_55 ;
if ( ! V_83 -> V_55 ) {
F_46 ( V_2 , V_63 , V_5 ) ;
return;
}
F_27 ( V_2 , V_107 , V_5 , V_108 ) ;
if ( ! V_83 -> V_55 )
return;
F_51 ( & V_83 -> V_144 ) ;
F_27 ( V_2 , V_145 ,
V_5 , ( T_1 ) ( V_83 -> V_15 . V_26 ) ) ;
memset ( & V_143 , 0 , sizeof( struct V_143 ) ) ;
V_143 . V_141 = 1 ;
V_143 . V_146 = 0 ;
V_143 . V_132 = 0 ;
V_143 . V_147 = V_148 ;
V_143 . V_149 = 0 ;
F_27 ( V_2 , V_107 , V_5 , * ( T_1 * ) & V_143 ) ;
F_27 ( V_2 , V_150 , V_5 , V_83 -> V_56 ) ;
F_27 ( V_2 , V_106 ,
V_5 , V_88 ) ;
}
static void F_52 ( struct V_1 * V_2 , struct V_62 * V_63 ,
int V_5 , bool V_55 )
{
union V_102 V_103 = {} ;
struct V_89 * V_90 ;
struct V_151 V_151 ;
V_90 = & V_63 -> V_90 [ V_5 ] ;
V_90 -> V_55 = V_55 ;
if ( ! V_90 -> V_55 ) {
F_43 ( V_2 , V_63 , V_5 ) ;
return;
}
F_27 ( V_2 , V_99 , V_5 , V_101 ) ;
V_90 -> V_125 = V_63 -> V_126 ;
V_90 -> V_127 = V_5 ;
V_103 . V_90 . V_104 = V_152 ;
V_103 . V_90 . V_134 = V_63 -> V_126 ;
V_103 . V_90 . V_153 = V_5 ;
V_103 . V_90 . V_140 = V_2 -> V_140 ;
V_103 . V_90 . V_136 = ( V_90 -> V_125 << 3 ) | V_90 -> V_127 ;
F_45 ( V_2 , & V_103 ) ;
F_27 ( V_2 , V_154 ,
V_5 , ( T_1 ) ( V_90 -> V_15 . V_26 ) ) ;
memset ( & V_151 , 0 , sizeof( struct V_151 ) ) ;
V_151 . V_141 = 1 ;
V_151 . V_146 = 0 ;
V_151 . V_155 = 0 ;
V_151 . V_147 = V_156 ;
V_151 . V_157 = 0 ;
F_27 ( V_2 , V_99 , V_5 , * ( T_1 * ) & V_151 ) ;
F_27 ( V_2 , V_158 , V_5 , V_90 -> V_56 ) ;
if ( F_53 ( V_5 ) ) {
F_54 ( V_5 , & V_90 -> V_159 ) ;
F_55 ( V_2 -> V_13 ,
& V_90 -> V_159 , V_5 ) ;
}
}
static void F_56 ( struct V_1 * V_2 , struct V_62 * V_63 ,
int V_5 , bool V_55 )
{
struct V_46 * V_46 ;
struct V_160 V_160 ;
V_46 = & V_63 -> V_46 [ V_5 ] ;
F_47 ( V_2 , V_46 , V_5 ) ;
if ( ! V_55 )
return;
F_27 ( V_2 , V_161 ,
V_5 , ( T_1 ) ( V_46 -> V_15 . V_26 ) ) ;
memset ( & V_160 , 0 , sizeof( struct V_160 ) ) ;
V_160 . V_141 = 1 ;
V_160 . V_146 = 0 ;
V_160 . V_155 = 0 ;
V_160 . V_147 = V_162 ;
V_160 . V_149 = 0 ;
V_160 . V_163 = V_46 -> V_54 / 128 ;
F_27 ( V_2 , V_112 ,
V_5 , * ( T_1 * ) & V_160 ) ;
F_27 ( V_2 , V_75 ,
V_5 , V_63 -> V_72 - 1 ) ;
F_27 ( V_2 , V_164 ,
V_5 , V_46 -> V_56 - 1 ) ;
}
void F_57 ( struct V_1 * V_2 , bool V_55 )
{
union V_102 V_103 = {} ;
struct V_62 * V_63 = V_2 -> V_63 ;
struct V_165 * V_165 ;
if ( ! V_63 ) {
F_58 ( V_2 -> V_13 ,
L_3 ) ;
return;
}
V_63 -> V_55 = V_55 ;
V_63 -> V_126 = V_2 -> V_166 ;
V_103 . V_63 . V_104 = V_167 ;
V_103 . V_63 . V_168 = V_63 -> V_126 ;
V_103 . V_63 . V_120 = V_2 -> V_120 ;
V_103 . V_63 . V_136 = 0 ;
V_165 = (struct V_165 * ) & V_103 . V_63 . V_136 ;
if ( V_63 -> V_55 ) {
V_165 -> V_141 = 1 ;
#ifdef F_59
V_165 -> V_169 = 1 ;
#endif
V_165 -> V_170 = V_63 -> V_126 ;
}
F_45 ( V_2 , & V_103 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_62 * V_63 = V_2 -> V_63 ;
for ( V_5 = 0 ; V_5 < V_63 -> V_65 ; V_5 ++ )
F_24 ( V_2 , & V_63 -> V_46 [ V_5 ] ) ;
for ( V_5 = 0 ; V_5 < V_63 -> V_171 ; V_5 ++ )
F_36 ( V_2 , & V_63 -> V_83 [ V_5 ] ) ;
for ( V_5 = 0 ; V_5 < V_63 -> V_172 ; V_5 ++ )
F_41 ( V_2 , & V_63 -> V_90 [ V_5 ] ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_62 * V_63 = V_2 -> V_63 ;
for ( V_5 = 0 ; V_5 < V_63 -> V_65 ; V_5 ++ ) {
if ( F_21 ( V_2 , & V_63 -> V_46 [ V_5 ] , V_63 -> V_72 ,
V_173 ) )
goto V_174;
}
for ( V_5 = 0 ; V_5 < V_63 -> V_172 ; V_5 ++ ) {
if ( F_37 ( V_2 , & V_63 -> V_90 [ V_5 ] , V_63 -> V_175 ) )
goto V_174;
}
for ( V_5 = 0 ; V_5 < V_63 -> V_171 ; V_5 ++ ) {
if ( F_34 ( V_2 , & V_63 -> V_83 [ V_5 ] , V_63 -> V_176 ) )
goto V_174;
}
return 0 ;
V_174:
F_60 ( V_2 ) ;
return - V_25 ;
}
int F_62 ( struct V_1 * V_2 )
{
struct V_62 * V_63 ;
V_63 = F_63 ( & V_2 -> V_21 -> V_22 , sizeof( * V_63 ) , V_24 ) ;
if ( ! V_63 )
return - V_25 ;
V_2 -> V_63 = V_63 ;
V_63 -> V_65 = V_177 ;
V_63 -> V_178 = V_179 ;
V_63 -> V_172 = V_180 ;
V_63 -> V_171 = V_181 ;
V_63 -> V_72 = V_182 ;
V_63 -> V_175 = V_183 ;
V_63 -> V_176 = V_184 ;
V_2 -> V_185 = V_63 -> V_178 ;
V_2 -> V_186 = V_63 -> V_172 ;
return 0 ;
}
int F_64 ( struct V_1 * V_2 , bool V_55 )
{
bool V_187 = false ;
struct V_62 * V_63 = V_2 -> V_63 ;
int V_5 ;
if ( ! V_63 )
return 0 ;
if ( V_55 ) {
if ( F_61 ( V_2 ) )
return - V_25 ;
for ( V_5 = 0 ; V_5 < V_63 -> V_172 ; V_5 ++ )
F_52 ( V_2 , V_63 , V_5 , V_55 ) ;
for ( V_5 = 0 ; V_5 < V_63 -> V_171 ; V_5 ++ )
F_50 ( V_2 , V_63 , V_5 , V_55 ) ;
for ( V_5 = 0 ; V_5 < V_63 -> V_65 ; V_5 ++ )
F_56 ( V_2 , V_63 , V_5 , V_55 ) ;
for ( V_5 = 0 ; V_5 < V_63 -> V_178 ; V_5 ++ )
F_49 ( V_2 , V_63 , V_5 , V_55 ) ;
} else {
for ( V_5 = 0 ; V_5 < V_63 -> V_178 ; V_5 ++ )
F_49 ( V_2 , V_63 , V_5 , V_187 ) ;
for ( V_5 = 0 ; V_5 < V_63 -> V_65 ; V_5 ++ )
F_56 ( V_2 , V_63 , V_5 , V_187 ) ;
for ( V_5 = 0 ; V_5 < V_63 -> V_172 ; V_5 ++ )
F_52 ( V_2 , V_63 , V_5 , V_187 ) ;
for ( V_5 = 0 ; V_5 < V_63 -> V_171 ; V_5 ++ )
F_50 ( V_2 , V_63 , V_5 , V_187 ) ;
F_60 ( V_2 ) ;
}
return 0 ;
}
static inline int F_65 ( struct V_89 * V_90 , int V_188 )
{
int V_189 ;
V_189 = V_90 -> V_61 ;
F_66 ( V_188 , & V_90 -> V_94 ) ;
V_90 -> V_61 += V_188 ;
V_90 -> V_61 &= ( V_90 -> V_15 . V_16 - 1 ) ;
return V_189 ;
}
void F_67 ( struct V_89 * V_90 , int V_188 )
{
F_68 ( V_188 , & V_90 -> V_94 ) ;
V_90 -> V_60 += V_188 ;
V_90 -> V_60 &= ( V_90 -> V_15 . V_16 - 1 ) ;
}
static inline int F_69 ( struct V_89 * V_90 , int V_189 )
{
V_189 ++ ;
V_189 &= ( V_90 -> V_15 . V_16 - 1 ) ;
return V_189 ;
}
void F_70 ( struct V_1 * V_2 , struct V_89 * V_90 , int V_5 )
{
T_1 V_151 ;
V_151 = F_4 ( V_2 , V_99 , V_5 ) ;
V_151 |= V_190 ;
F_27 ( V_2 , V_99 , V_5 , V_151 ) ;
F_27 ( V_2 , V_191 , V_5 , 0 ) ;
}
void F_71 ( struct V_1 * V_2 , int V_5 )
{
T_1 V_151 ;
V_151 = F_4 ( V_2 , V_99 , V_5 ) ;
V_151 &= ~ V_190 ;
F_27 ( V_2 , V_99 , V_5 , V_151 ) ;
}
void F_72 ( struct V_192 * V_13 , struct V_89 * V_90 ,
int V_5 )
{
T_1 V_60 , V_61 ;
struct V_40 * V_44 ;
struct V_1 * V_2 = F_73 ( V_13 ) ;
struct V_193 * V_194 ;
V_60 = F_4 ( V_2 , V_195 , V_5 ) >> 4 ;
V_61 = F_4 ( V_2 , V_196 , V_5 ) >> 4 ;
while ( V_90 -> V_60 != V_60 ) {
V_194 = (struct V_193 * ) F_74 ( V_90 , V_90 -> V_60 ) ;
if ( V_194 -> V_197 != V_198 ) {
F_67 ( V_90 , 1 ) ;
continue;
}
V_44 = (struct V_40 * ) V_90 -> V_93 [ V_90 -> V_60 ] ;
if ( V_44 )
F_75 ( V_44 ) ;
F_76 ( 1 , ( V_199 * ) & V_13 -> V_200 . V_201 ) ;
F_76 ( V_194 -> V_202 ,
( V_199 * ) & V_13 -> V_200 . V_203 ) ;
F_67 ( V_90 , V_194 -> V_204 + 1 ) ;
}
}
static int F_77 ( struct V_40 * V_44 )
{
struct V_205 * V_206 = F_78 ( V_44 ) ;
unsigned int V_207 = F_79 ( V_44 ) + F_80 ( V_44 ) ;
unsigned int V_208 = V_44 -> V_42 - V_207 ;
unsigned int V_209 = V_206 -> V_210 ;
long V_211 = - 1 ;
long V_212 = F_81 ( V_44 ) - V_207 ;
long V_213 = 0 ;
long V_214 ;
int V_215 = 0 ;
int V_216 ;
for ( V_216 = 0 ; V_216 < V_206 -> V_217 ; V_216 ++ ) {
unsigned int V_218 = 0 ;
for ( V_215 ++ ; V_218 < V_209 ; V_215 ++ ) {
while ( V_213 >= V_212 ) {
V_211 ++ ;
V_212 = F_82 ( & V_206 -> V_219 [ V_211 ] ) ;
V_213 = 0 ;
}
V_214 = V_209 - V_218 ;
if ( V_214 > V_212 - V_213 )
V_214 = V_212 - V_213 ;
V_213 += V_214 ;
V_218 += V_214 ;
}
V_208 -= V_209 ;
if ( V_208 < V_209 )
V_209 = V_208 ;
}
return V_215 + V_206 -> V_217 ;
}
static int F_83 ( struct V_1 * V_2 , struct V_40 * V_44 )
{
int V_204 = V_220 ;
if ( F_78 ( V_44 ) -> V_210 && ! V_2 -> V_221 ) {
V_204 = F_77 ( V_44 ) ;
return V_204 ;
}
if ( F_78 ( V_44 ) -> V_222 )
V_204 += F_78 ( V_44 ) -> V_222 ;
return V_204 ;
}
static inline void
F_84 ( struct V_1 * V_2 , struct V_89 * V_90 , int V_189 ,
int V_204 , struct V_40 * V_44 , int V_42 )
{
int V_223 ;
struct V_193 * V_194 ;
V_194 = (struct V_193 * ) F_74 ( V_90 , V_189 ) ;
V_90 -> V_93 [ V_189 ] = ( T_1 ) V_44 ;
memset ( V_194 , 0 , V_91 ) ;
V_194 -> V_197 = V_198 ;
V_194 -> V_224 = 1 ;
V_194 -> V_204 = V_204 ;
V_194 -> V_202 = V_42 ;
if ( V_44 -> V_225 == V_226 ) {
V_194 -> V_227 = 1 ;
V_194 -> V_228 = F_85 ( V_44 ) ;
V_194 -> V_229 = F_79 ( V_44 ) ;
V_223 = F_86 ( V_44 ) -> V_230 ;
switch ( V_223 ) {
case V_231 :
V_194 -> V_232 = V_233 ;
break;
case V_234 :
V_194 -> V_232 = V_235 ;
break;
case V_236 :
V_194 -> V_232 = V_237 ;
break;
}
}
if ( V_2 -> V_221 && F_78 ( V_44 ) -> V_210 ) {
V_194 -> V_238 = 1 ;
V_194 -> V_239 = F_79 ( V_44 ) + F_80 ( V_44 ) ;
V_194 -> V_240 = F_78 ( V_44 ) -> V_210 ;
V_194 -> V_241 = F_85 ( V_44 ) - 2 ;
V_2 -> V_38 . V_242 ++ ;
}
}
static inline void F_87 ( struct V_89 * V_90 , int V_189 ,
int V_19 , T_1 V_43 )
{
struct V_243 * V_244 ;
V_189 &= ( V_90 -> V_15 . V_16 - 1 ) ;
V_244 = (struct V_243 * ) F_74 ( V_90 , V_189 ) ;
memset ( V_244 , 0 , V_91 ) ;
V_244 -> V_197 = V_245 ;
V_244 -> V_246 = V_247 ;
V_244 -> V_19 = V_19 ;
V_244 -> V_248 = V_43 ;
}
static int F_88 ( struct V_1 * V_2 , struct V_89 * V_90 ,
int V_153 , int V_189 , struct V_40 * V_44 )
{
struct V_249 V_238 ;
int V_250 = 0 , V_188 = 0 ;
int V_251 , V_252 , V_253 ;
int V_254 = V_189 ;
int V_255 = F_79 ( V_44 ) + F_80 ( V_44 ) ;
V_239 ( V_44 , & V_238 ) ;
V_252 = V_44 -> V_42 - V_255 ;
while ( V_252 > 0 ) {
char * V_194 ;
V_254 = V_189 ;
V_253 = F_89 ( int , F_78 ( V_44 ) -> V_210 , V_252 ) ;
V_252 -= V_253 ;
V_189 = F_69 ( V_90 , V_189 ) ;
V_194 = V_90 -> V_96 + V_189 * V_97 ;
F_90 ( V_44 , V_194 , & V_238 , V_253 , V_252 == 0 ) ;
F_87 ( V_90 , V_189 , V_255 ,
V_90 -> V_98 +
V_189 * V_97 ) ;
V_250 = 2 ;
V_251 = V_255 ;
while ( V_253 > 0 ) {
int V_19 ;
V_19 = F_89 ( int , V_238 . V_19 , V_253 ) ;
V_189 = F_69 ( V_90 , V_189 ) ;
F_87 ( V_90 , V_189 , V_19 ,
F_23 ( V_238 . V_43 ) ) ;
V_250 ++ ;
V_251 += V_19 ;
V_253 -= V_19 ;
F_91 ( V_44 , & V_238 , V_19 ) ;
}
F_84 ( V_2 , V_90 , V_254 ,
V_250 - 1 , V_44 , V_251 ) ;
V_90 -> V_93 [ V_254 ] = ( T_1 ) NULL ;
V_189 = F_69 ( V_90 , V_189 ) ;
V_188 += V_250 ;
}
V_90 -> V_93 [ V_254 ] = ( T_1 ) V_44 ;
F_26 () ;
F_27 ( V_2 , V_191 ,
V_153 , V_188 ) ;
V_2 -> V_38 . V_242 ++ ;
return 1 ;
}
int F_92 ( struct V_1 * V_2 , struct V_40 * V_44 )
{
int V_256 , V_19 ;
int V_204 ;
int V_153 , V_189 ;
struct V_62 * V_63 ;
struct V_89 * V_90 ;
V_153 = F_93 ( V_44 ) ;
if ( V_153 >= V_257 ) {
V_256 = V_153 / V_257 ;
if ( ! V_2 -> V_121 [ V_256 - 1 ] ) {
F_58 ( V_2 -> V_13 ,
L_4 ,
V_256 - 1 ) ;
return 1 ;
}
V_2 = (struct V_1 * ) V_2 -> V_121 [ V_256 - 1 ] ;
V_153 = V_153 % V_257 ;
}
V_63 = V_2 -> V_63 ;
V_90 = & V_63 -> V_90 [ V_153 ] ;
V_204 = F_83 ( V_2 , V_44 ) ;
if ( V_204 > F_94 ( & V_90 -> V_94 ) )
goto V_258;
V_189 = F_65 ( V_90 , V_204 ) ;
if ( F_78 ( V_44 ) -> V_210 && ! V_2 -> V_221 )
return F_88 ( V_2 , V_90 , V_153 , V_189 , V_44 ) ;
F_84 ( V_2 , V_90 , V_189 , V_204 - 1 ,
V_44 , V_44 -> V_42 ) ;
V_189 = F_69 ( V_90 , V_189 ) ;
V_19 = F_95 ( V_44 ) ? F_81 ( V_44 ) : V_44 -> V_42 ;
F_87 ( V_90 , V_189 , V_19 , F_23 ( V_44 -> V_43 ) ) ;
if ( ! F_95 ( V_44 ) )
goto V_259;
for ( V_256 = 0 ; V_256 < F_78 ( V_44 ) -> V_222 ; V_256 ++ ) {
const struct V_260 * V_261 ;
V_261 = & F_78 ( V_44 ) -> V_219 [ V_256 ] ;
V_189 = F_69 ( V_90 , V_189 ) ;
V_19 = F_82 ( V_261 ) ;
F_87 ( V_90 , V_189 , V_19 ,
F_23 (
F_96 ( V_261 ) ) ) ;
}
V_259:
F_26 () ;
F_27 ( V_2 , V_191 ,
V_153 , V_204 ) ;
return 1 ;
V_258:
V_2 = V_2 -> V_262 ;
F_97 ( V_2 -> V_13 , L_5 ) ;
return 0 ;
}
static inline unsigned F_98 ( unsigned V_256 )
{
#ifdef F_59
return ( V_256 & ~ 3 ) + 3 - ( V_256 & 3 ) ;
#else
return V_256 ;
#endif
}
struct V_40 * F_99 ( struct V_1 * V_2 , struct V_263 * V_264 )
{
int V_261 ;
int V_265 = 0 ;
struct V_40 * V_44 = NULL ;
struct V_40 * V_266 = NULL ;
struct V_40 * V_267 = NULL ;
T_5 * V_268 = NULL ;
T_1 * V_269 = NULL ;
V_268 = ( void * ) V_264 + ( 3 * sizeof( T_1 ) ) ;
V_269 = ( void * ) V_264 + ( 6 * sizeof( T_1 ) ) ;
F_97 ( V_2 -> V_13 , L_6 ,
V_270 , V_264 -> V_271 , V_264 -> V_272 , V_264 -> V_273 ) ;
for ( V_261 = 0 ; V_261 < V_264 -> V_271 ; V_261 ++ ) {
V_265 = V_268 [ F_98 ( V_261 ) ] ;
if ( ! V_261 ) {
V_44 = F_15 ( V_2 ,
* V_269 - V_264 -> V_274 ,
V_265 ) ;
if ( ! V_44 )
return NULL ;
F_100 ( V_44 , V_264 -> V_274 ) ;
F_101 ( V_44 , V_265 ) ;
} else {
V_266 = F_15 ( V_2 , * V_269 ,
V_265 ) ;
if ( ! V_266 ) {
F_102 ( V_44 ) ;
return NULL ;
}
if ( ! F_78 ( V_44 ) -> V_275 )
F_78 ( V_44 ) -> V_275 = V_266 ;
else
V_267 -> V_276 = V_266 ;
V_267 = V_266 ;
V_44 -> V_42 += V_265 ;
V_44 -> V_208 += V_265 ;
V_266 -> V_42 = V_265 ;
}
V_269 ++ ;
}
return V_44 ;
}
static T_1 F_103 ( int V_277 , int V_278 )
{
T_1 V_11 ;
switch ( V_277 ) {
case V_279 :
V_11 = ( ( 1ULL << V_278 ) << V_280 ) ;
break;
case V_281 :
V_11 = ( ( 1ULL << V_278 ) << V_282 ) ;
break;
case V_76 :
V_11 = ( ( 1ULL << V_278 ) << V_283 ) ;
break;
case V_284 :
V_11 = ( 1ULL << V_285 ) ;
break;
case V_286 :
V_11 = ( 1ULL << V_287 ) ;
break;
case V_288 :
V_11 = ( 1ULL << V_289 ) ;
break;
case V_290 :
V_11 = ( 1ULL << V_291 ) ;
break;
default:
V_11 = 0 ;
}
return V_11 ;
}
void F_28 ( struct V_1 * V_2 , int V_277 , int V_278 )
{
T_1 V_292 = F_103 ( V_277 , V_278 ) ;
if ( ! V_292 ) {
F_97 ( V_2 -> V_13 ,
L_7 ) ;
return;
}
F_104 ( V_2 , V_293 ,
F_105 ( V_2 , V_293 ) | V_292 ) ;
}
void F_106 ( struct V_1 * V_2 , int V_277 , int V_278 )
{
T_1 V_292 = F_103 ( V_277 , V_278 ) ;
if ( ! V_292 ) {
F_97 ( V_2 -> V_13 ,
L_8 ) ;
return;
}
F_104 ( V_2 , V_294 , V_292 ) ;
}
void F_107 ( struct V_1 * V_2 , int V_277 , int V_278 )
{
T_1 V_292 = F_103 ( V_277 , V_278 ) ;
if ( ! V_292 ) {
F_97 ( V_2 -> V_13 ,
L_9 ) ;
return;
}
F_104 ( V_2 , V_295 , V_292 ) ;
}
int F_108 ( struct V_1 * V_2 , int V_277 , int V_278 )
{
T_1 V_292 = F_103 ( V_277 , V_278 ) ;
if ( ! V_292 ) {
F_97 ( V_2 -> V_13 ,
L_10 ) ;
return 0 ;
}
return V_292 & F_105 ( V_2 , V_293 ) ;
}
void F_109 ( struct V_1 * V_2 , int V_296 )
{
struct V_122 * V_123 ;
#define F_110 ( V_6 ) \
nicvf_reg_read(nic, NIC_QSET_RQ_0_7_STAT_0_1 |\
(rq_idx << NIC_Q_NUM_SHIFT) | (reg << 3))
V_123 = & V_2 -> V_63 -> V_123 [ V_296 ] ;
V_123 -> V_200 . V_297 = F_110 ( V_298 ) ;
V_123 -> V_200 . V_299 = F_110 ( V_300 ) ;
}
void F_111 ( struct V_1 * V_2 , int V_301 )
{
struct V_89 * V_90 ;
#define F_112 ( V_6 ) \
nicvf_reg_read(nic, NIC_QSET_SQ_0_7_STAT_0_1 |\
(sq_idx << NIC_Q_NUM_SHIFT) | (reg << 3))
V_90 = & V_2 -> V_63 -> V_90 [ V_301 ] ;
V_90 -> V_200 . V_297 = F_112 ( V_298 ) ;
V_90 -> V_200 . V_299 = F_112 ( V_300 ) ;
}
int F_113 ( struct V_1 * V_2 , struct V_263 * V_264 )
{
struct V_302 * V_200 = & V_2 -> V_303 ;
if ( ! V_264 -> V_304 && ! V_264 -> V_305 )
return 0 ;
if ( F_114 ( V_2 ) )
F_6 ( V_2 -> V_13 ,
L_11 ,
V_2 -> V_13 -> V_306 ,
V_264 -> V_304 , V_264 -> V_305 ) ;
switch ( V_264 -> V_305 ) {
case V_307 :
V_200 -> V_308 ++ ;
break;
case V_309 :
V_200 -> V_310 ++ ;
break;
case V_311 :
V_200 -> V_312 ++ ;
break;
case V_313 :
V_200 -> V_314 ++ ;
break;
case V_315 :
V_200 -> V_316 ++ ;
break;
case V_317 :
V_200 -> V_318 ++ ;
break;
case V_319 :
V_200 -> V_320 ++ ;
break;
case V_321 :
V_200 -> V_322 ++ ;
break;
case V_323 :
V_200 -> V_324 ++ ;
break;
case V_325 :
V_200 -> V_326 ++ ;
break;
case V_327 :
V_200 -> V_328 ++ ;
break;
case V_329 :
V_200 -> V_330 ++ ;
break;
case V_331 :
V_200 -> V_332 ++ ;
break;
case V_333 :
V_200 -> V_334 ++ ;
break;
case V_335 :
V_200 -> V_336 ++ ;
break;
case V_337 :
V_200 -> V_338 ++ ;
break;
case V_339 :
V_200 -> V_340 ++ ;
break;
case V_341 :
V_200 -> V_342 ++ ;
break;
case V_343 :
V_200 -> V_344 ++ ;
break;
case V_345 :
V_200 -> V_346 ++ ;
break;
case V_347 :
V_200 -> V_348 ++ ;
break;
case V_349 :
V_200 -> V_350 ++ ;
break;
case V_351 :
V_200 -> V_352 ++ ;
break;
case V_353 :
V_200 -> V_354 ++ ;
break;
}
return 1 ;
}
int F_115 ( struct V_1 * V_2 ,
struct V_82 * V_83 , struct V_355 * V_356 )
{
struct V_357 * V_200 = & V_83 -> V_200 ;
switch ( V_356 -> V_358 ) {
case V_359 :
V_200 -> V_360 . V_361 ++ ;
return 0 ;
case V_362 :
V_200 -> V_360 . V_363 ++ ;
break;
case V_364 :
V_200 -> V_360 . V_365 ++ ;
break;
case V_366 :
V_200 -> V_360 . V_367 ++ ;
break;
case V_368 :
V_200 -> V_360 . V_369 ++ ;
break;
case V_370 :
V_200 -> V_360 . V_371 ++ ;
break;
case V_372 :
V_200 -> V_360 . V_373 ++ ;
break;
case V_374 :
V_200 -> V_360 . V_375 ++ ;
break;
case V_376 :
V_200 -> V_360 . V_377 ++ ;
break;
case V_378 :
V_200 -> V_360 . V_379 ++ ;
break;
case V_380 :
V_200 -> V_360 . V_381 ++ ;
break;
case V_382 :
V_200 -> V_360 . V_383 ++ ;
break;
case V_384 :
V_200 -> V_360 . V_385 ++ ;
break;
case V_386 :
V_200 -> V_360 . V_387 ++ ;
break;
}
return 1 ;
}

static int F_1 ( struct V_1 * V_2 , int V_3 ,
T_1 V_4 , int V_5 , int V_6 , int V_7 )
{
T_1 V_8 ;
T_1 V_9 ;
int V_10 = 10 ;
V_8 = ( 1ULL << V_6 ) - 1 ;
V_8 = ( V_8 << V_5 ) ;
while ( V_10 ) {
V_9 = F_2 ( V_2 , V_4 , V_3 ) ;
if ( ( ( V_9 & V_8 ) >> V_5 ) == V_7 )
return 0 ;
F_3 ( 1000 , 2000 ) ;
V_10 -- ;
}
F_4 ( V_2 -> V_11 , L_1 , V_4 ) ;
return 1 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_12 * V_13 ,
int V_14 , int V_15 , int V_16 )
{
V_13 -> V_14 = V_14 ;
V_13 -> V_17 = ( V_15 * V_14 ) + V_16 ;
V_13 -> V_18 = F_6 ( & V_2 -> V_19 -> V_20 , V_13 -> V_17 ,
& V_13 -> V_21 , V_22 ) ;
if ( ! V_13 -> V_18 )
return - V_23 ;
V_13 -> V_24 = F_7 ( ( T_1 ) V_13 -> V_21 , V_16 ) ;
V_13 -> V_25 = V_13 -> V_18 + ( V_13 -> V_24 - V_13 -> V_21 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
if ( ! V_13 )
return;
F_9 ( & V_2 -> V_19 -> V_20 , V_13 -> V_17 ,
V_13 -> V_18 , V_13 -> V_21 ) ;
V_13 -> V_18 = NULL ;
V_13 -> V_25 = NULL ;
}
static inline int F_10 ( struct V_1 * V_2 , T_2 V_26 ,
T_3 V_27 , T_1 * * V_28 )
{
T_1 V_29 ;
struct V_30 * V_31 ;
int V_32 = F_11 ( V_27 ) ;
if ( V_2 -> V_33 ) {
if ( ( V_2 -> V_34 + V_27 + V_27 ) >
( V_35 << V_32 ) ) {
V_2 -> V_33 = NULL ;
} else {
V_2 -> V_34 += V_27 ;
F_12 ( V_2 -> V_33 ) ;
}
}
if ( ! V_2 -> V_33 ) {
V_2 -> V_33 = F_13 ( V_26 | V_36 | V_37 ,
V_32 ) ;
if ( ! V_2 -> V_33 ) {
F_4 ( V_2 -> V_11 ,
L_2 ) ;
return - V_23 ;
}
V_2 -> V_34 = 0 ;
}
V_29 = ( T_1 ) F_14 ( V_2 -> V_33 ) + V_2 -> V_34 ;
V_31 = (struct V_30 * ) ( V_29 + F_15 ( V_29 ) ) ;
V_31 -> V_38 = V_2 -> V_33 ;
V_31 -> V_29 = ( void * ) V_29 ;
V_31 -> V_39 = F_15 ( V_29 ) ;
V_29 += V_31 -> V_39 ;
* V_28 = ( T_1 * ) ( V_29 + V_40 ) ;
return 0 ;
}
static struct V_41 * F_16 ( struct V_1 * V_2 ,
T_1 V_42 , int V_43 )
{
struct V_41 * V_44 ;
struct V_30 * V_31 ;
V_42 = ( T_1 ) F_17 ( V_42 ) ;
V_31 = F_18 ( V_42 ) ;
V_44 = F_19 ( V_31 -> V_29 , V_45 ) ;
if ( ! V_44 ) {
F_20 ( V_31 -> V_38 ) ;
return NULL ;
}
F_21 ( V_44 , V_31 -> V_39 + V_40 ) ;
F_22 ( ( void * ) V_42 ) ;
return V_44 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_46 * V_46 ,
int V_47 , int V_48 )
{
int V_49 ;
T_1 * V_28 ;
struct V_50 * V_51 ;
int V_52 ;
V_52 = F_5 ( V_2 , & V_46 -> V_13 , V_47 ,
sizeof( struct V_50 ) ,
V_40 ) ;
if ( V_52 )
return V_52 ;
V_46 -> V_51 = V_46 -> V_13 . V_25 ;
V_46 -> V_53 = V_48 ;
V_46 -> V_54 = true ;
V_46 -> V_55 = V_56 ;
V_2 -> V_33 = NULL ;
for ( V_49 = 0 ; V_49 < V_47 ; V_49 ++ ) {
V_52 = F_10 ( V_2 , V_22 , V_45 ,
& V_28 ) ;
if ( V_52 )
return V_52 ;
V_51 = F_24 ( V_46 , V_49 ) ;
V_51 -> V_57 = F_25 ( V_28 ) >> V_58 ;
}
return 0 ;
}
static void F_26 ( struct V_1 * V_2 , struct V_46 * V_46 )
{
int V_59 , V_60 ;
T_1 V_57 ;
struct V_50 * V_51 ;
struct V_30 * V_31 ;
if ( ! V_46 )
return;
V_46 -> V_54 = false ;
if ( ! V_46 -> V_13 . V_25 )
return;
V_59 = V_46 -> V_59 ;
V_60 = V_46 -> V_60 ;
while ( V_59 != V_60 ) {
V_51 = F_24 ( V_46 , V_59 ) ;
V_57 = V_51 -> V_57 << V_58 ;
V_31 = F_18 ( ( T_1 ) F_17 ( V_57 ) ) ;
F_20 ( V_31 -> V_38 ) ;
V_59 ++ ;
V_59 &= ( V_46 -> V_13 . V_14 - 1 ) ;
}
V_51 = F_24 ( V_46 , V_60 ) ;
V_57 = V_51 -> V_57 << V_58 ;
V_31 = F_18 ( ( T_1 ) F_17 ( V_57 ) ) ;
F_20 ( V_31 -> V_38 ) ;
F_8 ( V_2 , & V_46 -> V_13 ) ;
}
static void F_27 ( struct V_1 * V_2 , T_2 V_26 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
int V_63 = V_62 -> V_64 ;
int V_60 , V_65 ;
int V_66 ;
struct V_46 * V_46 ;
struct V_50 * V_51 ;
T_1 * V_28 ;
int V_67 = 0 ;
V_68:
if ( ! V_63 )
return;
V_63 -- ;
V_46 = & V_62 -> V_46 [ V_63 ] ;
if ( ! V_46 -> V_54 )
goto V_69;
V_65 = F_2 ( V_2 , V_70 , V_63 ) ;
V_65 &= 0x7FFFF ;
if ( V_65 >= ( V_62 -> V_71 - 1 ) )
goto V_69;
else
V_66 = V_62 -> V_71 - V_65 - 1 ;
V_60 = F_2 ( V_2 , V_72 , V_63 ) >> 3 ;
while ( V_66 ) {
V_60 ++ ;
V_60 &= ( V_46 -> V_13 . V_14 - 1 ) ;
if ( F_10 ( V_2 , V_26 , V_45 , & V_28 ) )
break;
V_51 = F_24 ( V_46 , V_60 ) ;
V_51 -> V_57 = F_25 ( V_28 ) >> V_58 ;
V_66 -- ;
V_67 ++ ;
}
F_28 () ;
if ( V_66 )
V_2 -> V_73 = true ;
else
V_2 -> V_73 = false ;
F_29 ( V_2 , V_74 ,
V_63 , V_67 ) ;
V_69:
if ( ! V_2 -> V_73 && V_46 -> V_54 )
F_30 ( V_2 , V_75 , V_63 ) ;
if ( V_63 )
goto V_68;
}
void F_31 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_32 ( V_77 , struct V_1 , V_78 . V_77 ) ;
F_27 ( V_2 , V_22 ) ;
if ( V_2 -> V_73 )
F_33 ( & V_2 -> V_78 , F_34 ( 10 ) ) ;
else
V_2 -> V_79 = false ;
}
void F_35 ( unsigned long V_29 )
{
struct V_1 * V_2 = (struct V_1 * ) V_29 ;
F_27 ( V_2 , V_80 ) ;
if ( V_2 -> V_73 ) {
V_2 -> V_79 = true ;
F_33 ( & V_2 -> V_78 , F_34 ( 10 ) ) ;
}
}
static int F_36 ( struct V_1 * V_2 ,
struct V_81 * V_82 , int V_14 )
{
int V_52 ;
V_52 = F_5 ( V_2 , & V_82 -> V_13 , V_14 , V_83 ,
V_84 ) ;
if ( V_52 )
return V_52 ;
V_82 -> V_51 = V_82 -> V_13 . V_25 ;
V_82 -> V_55 = V_85 ;
V_2 -> V_86 = ( V_87 * 0.05 ) - 1 ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 , struct V_81 * V_82 )
{
if ( ! V_82 )
return;
if ( ! V_82 -> V_13 . V_25 )
return;
F_8 ( V_2 , & V_82 -> V_13 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_88 * V_89 , int V_14 )
{
int V_52 ;
V_52 = F_5 ( V_2 , & V_89 -> V_13 , V_14 , V_90 ,
V_91 ) ;
if ( V_52 )
return V_52 ;
V_89 -> V_51 = V_89 -> V_13 . V_25 ;
V_89 -> V_92 = F_39 ( V_14 , sizeof( T_1 ) , V_22 ) ;
if ( ! V_89 -> V_92 )
return - V_23 ;
V_89 -> V_59 = 0 ;
V_89 -> V_60 = 0 ;
F_40 ( & V_89 -> V_93 , V_14 - 1 ) ;
V_89 -> V_55 = V_94 ;
V_89 -> V_95 = F_41 ( & V_2 -> V_19 -> V_20 ,
V_14 * V_96 ,
& V_89 -> V_97 , V_22 ) ;
if ( ! V_89 -> V_95 )
return - V_23 ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 , struct V_88 * V_89 )
{
if ( ! V_89 )
return;
if ( ! V_89 -> V_13 . V_25 )
return;
if ( V_89 -> V_95 )
F_9 ( & V_2 -> V_19 -> V_20 ,
V_89 -> V_13 . V_14 * V_96 ,
V_89 -> V_95 , V_89 -> V_97 ) ;
F_43 ( V_89 -> V_92 ) ;
F_8 ( V_2 , & V_89 -> V_13 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_61 * V_62 , int V_3 )
{
F_29 ( V_2 , V_98 , V_3 , 0 ) ;
if ( F_1 ( V_2 , V_3 , V_99 , 21 , 1 , 0x01 ) )
return;
F_29 ( V_2 , V_98 , V_3 , V_100 ) ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_61 * V_62 , int V_3 )
{
union V_101 V_102 = {} ;
V_102 . V_103 . V_103 = V_104 ;
F_46 ( V_2 , & V_102 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_61 * V_62 , int V_3 )
{
F_29 ( V_2 , V_105 , V_3 , 0 ) ;
F_29 ( V_2 , V_106 , V_3 , 0 ) ;
F_29 ( V_2 , V_106 , V_3 , V_107 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_46 * V_46 , int V_3 )
{
T_1 V_108 , V_109 ;
int V_10 = 10 ;
V_46 -> V_59 = F_2 ( V_2 ,
V_110 ,
V_3 ) >> 3 ;
V_46 -> V_60 = F_2 ( V_2 ,
V_72 ,
V_3 ) >> 3 ;
V_109 = F_2 ( V_2 , V_70 , V_3 ) ;
if ( ( ( V_109 >> 62 ) & 0x03 ) == 0x3 )
F_29 ( V_2 , V_111 ,
V_3 , V_112 ) ;
F_29 ( V_2 , V_111 , V_3 , 0 ) ;
if ( F_1 ( V_2 , V_3 , V_70 , 62 , 2 , 0x00 ) )
return;
while ( 1 ) {
V_108 = F_2 ( V_2 ,
V_113 ,
V_3 ) ;
if ( ( V_108 & 0xFFFFFFFF ) == ( ( V_108 >> 32 ) & 0xFFFFFFFF ) )
break;
F_3 ( 1000 , 2000 ) ;
V_10 -- ;
if ( ! V_10 ) {
F_4 ( V_2 -> V_11 ,
L_3 ) ;
return;
}
}
F_29 ( V_2 , V_111 ,
V_3 , V_112 ) ;
if ( F_1 ( V_2 , V_3 , V_70 , 62 , 2 , 0x02 ) )
return;
F_29 ( V_2 , V_111 , V_3 , 0x00 ) ;
if ( F_1 ( V_2 , V_3 , V_70 , 62 , 2 , 0x00 ) )
return;
}
static void F_49 ( struct V_1 * V_2 , struct V_61 * V_62 ,
int V_3 , bool V_54 )
{
union V_101 V_102 = {} ;
struct V_114 * V_115 ;
struct V_116 V_116 ;
V_115 = & V_62 -> V_115 [ V_3 ] ;
V_115 -> V_54 = V_54 ;
F_29 ( V_2 , V_117 , V_3 , 0 ) ;
if ( ! V_115 -> V_54 ) {
F_45 ( V_2 , V_62 , V_3 ) ;
return;
}
V_115 -> V_118 = V_62 -> V_119 ;
V_115 -> V_120 = V_3 ;
V_115 -> V_121 = V_62 -> V_119 ;
V_115 -> V_122 = V_62 -> V_64 - 1 ;
V_115 -> V_123 = V_62 -> V_119 ;
V_115 -> V_124 = V_62 -> V_64 - 1 ;
V_115 -> V_125 = 1 ;
V_102 . V_115 . V_103 = V_126 ;
V_102 . V_115 . V_127 = V_62 -> V_119 ;
V_102 . V_115 . V_128 = V_3 ;
V_102 . V_115 . V_129 = ( V_115 -> V_125 << 26 ) | ( V_115 -> V_118 << 19 ) |
( V_115 -> V_120 << 16 ) | ( V_115 -> V_123 << 9 ) |
( V_115 -> V_124 << 8 ) |
( V_115 -> V_121 << 1 ) | ( V_115 -> V_122 ) ;
F_46 ( V_2 , & V_102 ) ;
V_102 . V_115 . V_103 = V_130 ;
V_102 . V_115 . V_129 = ( 1ULL << 63 ) | ( 1ULL << 62 ) | ( V_62 -> V_119 << 0 ) ;
F_46 ( V_2 , & V_102 ) ;
V_102 . V_115 . V_103 = V_131 ;
V_102 . V_115 . V_129 = ( 1ULL << 62 ) | ( V_132 << 8 ) ;
F_46 ( V_2 , & V_102 ) ;
F_29 ( V_2 , V_133 , V_3 , 0x00 ) ;
V_116 . V_134 = 1 ;
V_116 . V_135 = 0 ;
F_29 ( V_2 , V_117 , V_3 , * ( T_1 * ) & V_116 ) ;
}
void F_50 ( struct V_1 * V_2 , struct V_61 * V_62 ,
int V_3 , bool V_54 )
{
struct V_81 * V_82 ;
struct V_136 V_136 ;
V_82 = & V_62 -> V_82 [ V_3 ] ;
V_82 -> V_54 = V_54 ;
if ( ! V_82 -> V_54 ) {
F_47 ( V_2 , V_62 , V_3 ) ;
return;
}
F_29 ( V_2 , V_106 , V_3 , V_107 ) ;
if ( ! V_82 -> V_54 )
return;
F_51 ( & V_82 -> V_137 ) ;
F_29 ( V_2 , V_138 ,
V_3 , ( T_1 ) ( V_82 -> V_13 . V_24 ) ) ;
V_136 . V_134 = 1 ;
V_136 . V_139 = 0 ;
V_136 . V_125 = 0 ;
V_136 . V_140 = V_141 ;
V_136 . V_142 = 0 ;
F_29 ( V_2 , V_106 , V_3 , * ( T_1 * ) & V_136 ) ;
F_29 ( V_2 , V_143 , V_3 , V_82 -> V_55 ) ;
F_29 ( V_2 , V_105 ,
V_3 , V_2 -> V_86 ) ;
}
static void F_52 ( struct V_1 * V_2 , struct V_61 * V_62 ,
int V_3 , bool V_54 )
{
union V_101 V_102 = {} ;
struct V_88 * V_89 ;
struct V_144 V_144 ;
V_89 = & V_62 -> V_89 [ V_3 ] ;
V_89 -> V_54 = V_54 ;
if ( ! V_89 -> V_54 ) {
F_44 ( V_2 , V_62 , V_3 ) ;
return;
}
F_29 ( V_2 , V_98 , V_3 , V_100 ) ;
V_89 -> V_118 = V_62 -> V_119 ;
V_89 -> V_120 = V_3 ;
V_102 . V_89 . V_103 = V_145 ;
V_102 . V_89 . V_127 = V_62 -> V_119 ;
V_102 . V_89 . V_146 = V_3 ;
V_102 . V_89 . V_129 = ( V_89 -> V_118 << 3 ) | V_89 -> V_120 ;
F_46 ( V_2 , & V_102 ) ;
F_29 ( V_2 , V_147 ,
V_3 , ( T_1 ) ( V_89 -> V_13 . V_24 ) ) ;
V_144 . V_134 = 1 ;
V_144 . V_139 = 0 ;
V_144 . V_148 = 0 ;
V_144 . V_140 = V_149 ;
V_144 . V_150 = 0 ;
F_29 ( V_2 , V_98 , V_3 , * ( T_1 * ) & V_144 ) ;
F_29 ( V_2 , V_151 , V_3 , V_89 -> V_55 ) ;
if ( F_53 ( V_3 ) ) {
F_54 ( V_3 , & V_89 -> V_152 ) ;
F_55 ( V_2 -> V_11 ,
& V_89 -> V_152 , V_3 ) ;
}
}
static void F_56 ( struct V_1 * V_2 , struct V_61 * V_62 ,
int V_3 , bool V_54 )
{
struct V_46 * V_46 ;
struct V_153 V_153 ;
V_46 = & V_62 -> V_46 [ V_3 ] ;
F_48 ( V_2 , V_46 , V_3 ) ;
if ( ! V_54 )
return;
F_29 ( V_2 , V_154 ,
V_3 , ( T_1 ) ( V_46 -> V_13 . V_24 ) ) ;
V_153 . V_134 = 1 ;
V_153 . V_139 = 0 ;
V_153 . V_148 = 0 ;
V_153 . V_140 = V_155 ;
V_153 . V_142 = 0 ;
V_153 . V_156 = V_46 -> V_53 / 128 ;
F_29 ( V_2 , V_111 ,
V_3 , * ( T_1 * ) & V_153 ) ;
F_29 ( V_2 , V_74 ,
V_3 , V_62 -> V_71 - 1 ) ;
F_29 ( V_2 , V_157 ,
V_3 , V_46 -> V_55 - 1 ) ;
}
void F_57 ( struct V_1 * V_2 , bool V_54 )
{
union V_101 V_102 = {} ;
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_158 * V_158 ;
if ( ! V_62 ) {
F_58 ( V_2 -> V_11 ,
L_4 ) ;
return;
}
V_62 -> V_54 = V_54 ;
V_62 -> V_119 = V_2 -> V_159 ;
V_102 . V_62 . V_103 = V_160 ;
V_102 . V_62 . V_161 = V_62 -> V_119 ;
V_102 . V_62 . V_129 = 0 ;
V_158 = (struct V_158 * ) & V_102 . V_62 . V_129 ;
if ( V_62 -> V_54 ) {
V_158 -> V_134 = 1 ;
#ifdef F_59
V_158 -> V_162 = 1 ;
#endif
V_158 -> V_163 = V_62 -> V_119 ;
}
F_46 ( V_2 , & V_102 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_61 * V_62 = V_2 -> V_62 ;
for ( V_3 = 0 ; V_3 < V_62 -> V_64 ; V_3 ++ )
F_26 ( V_2 , & V_62 -> V_46 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < V_62 -> V_164 ; V_3 ++ )
F_37 ( V_2 , & V_62 -> V_82 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < V_62 -> V_165 ; V_3 ++ )
F_42 ( V_2 , & V_62 -> V_89 [ V_3 ] ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_61 * V_62 = V_2 -> V_62 ;
for ( V_3 = 0 ; V_3 < V_62 -> V_64 ; V_3 ++ ) {
if ( F_23 ( V_2 , & V_62 -> V_46 [ V_3 ] , V_62 -> V_71 ,
V_166 ) )
goto V_167;
}
for ( V_3 = 0 ; V_3 < V_62 -> V_165 ; V_3 ++ ) {
if ( F_38 ( V_2 , & V_62 -> V_89 [ V_3 ] , V_62 -> V_168 ) )
goto V_167;
}
for ( V_3 = 0 ; V_3 < V_62 -> V_164 ; V_3 ++ ) {
if ( F_36 ( V_2 , & V_62 -> V_82 [ V_3 ] , V_62 -> V_169 ) )
goto V_167;
}
return 0 ;
V_167:
F_60 ( V_2 ) ;
return - V_23 ;
}
int F_62 ( struct V_1 * V_2 )
{
struct V_61 * V_62 ;
V_62 = F_63 ( & V_2 -> V_19 -> V_20 , sizeof( * V_62 ) , V_22 ) ;
if ( ! V_62 )
return - V_23 ;
V_2 -> V_62 = V_62 ;
V_62 -> V_64 = V_170 ;
V_62 -> V_171 = V_172 ;
V_62 -> V_165 = V_173 ;
V_62 -> V_164 = V_174 ;
V_62 -> V_71 = V_175 ;
V_62 -> V_168 = V_176 ;
V_62 -> V_169 = V_177 ;
return 0 ;
}
int F_64 ( struct V_1 * V_2 , bool V_54 )
{
bool V_178 = false ;
struct V_61 * V_62 = V_2 -> V_62 ;
int V_3 ;
if ( ! V_62 )
return 0 ;
if ( V_54 ) {
if ( F_61 ( V_2 ) )
return - V_23 ;
for ( V_3 = 0 ; V_3 < V_62 -> V_165 ; V_3 ++ )
F_52 ( V_2 , V_62 , V_3 , V_54 ) ;
for ( V_3 = 0 ; V_3 < V_62 -> V_164 ; V_3 ++ )
F_50 ( V_2 , V_62 , V_3 , V_54 ) ;
for ( V_3 = 0 ; V_3 < V_62 -> V_64 ; V_3 ++ )
F_56 ( V_2 , V_62 , V_3 , V_54 ) ;
for ( V_3 = 0 ; V_3 < V_62 -> V_171 ; V_3 ++ )
F_49 ( V_2 , V_62 , V_3 , V_54 ) ;
} else {
for ( V_3 = 0 ; V_3 < V_62 -> V_171 ; V_3 ++ )
F_49 ( V_2 , V_62 , V_3 , V_178 ) ;
for ( V_3 = 0 ; V_3 < V_62 -> V_64 ; V_3 ++ )
F_56 ( V_2 , V_62 , V_3 , V_178 ) ;
for ( V_3 = 0 ; V_3 < V_62 -> V_165 ; V_3 ++ )
F_52 ( V_2 , V_62 , V_3 , V_178 ) ;
for ( V_3 = 0 ; V_3 < V_62 -> V_164 ; V_3 ++ )
F_50 ( V_2 , V_62 , V_3 , V_178 ) ;
F_60 ( V_2 ) ;
}
return 0 ;
}
static inline int F_65 ( struct V_88 * V_89 , int V_179 )
{
int V_180 ;
V_180 = V_89 -> V_60 ;
F_66 ( V_179 , & V_89 -> V_93 ) ;
V_89 -> V_60 += V_179 ;
V_89 -> V_60 &= ( V_89 -> V_13 . V_14 - 1 ) ;
return V_180 ;
}
void F_67 ( struct V_88 * V_89 , int V_179 )
{
F_68 ( V_179 , & V_89 -> V_93 ) ;
V_89 -> V_59 += V_179 ;
V_89 -> V_59 &= ( V_89 -> V_13 . V_14 - 1 ) ;
}
static inline int F_69 ( struct V_88 * V_89 , int V_180 )
{
V_180 ++ ;
V_180 &= ( V_89 -> V_13 . V_14 - 1 ) ;
return V_180 ;
}
void F_70 ( struct V_1 * V_2 , struct V_88 * V_89 , int V_3 )
{
T_1 V_144 ;
V_144 = F_2 ( V_2 , V_98 , V_3 ) ;
V_144 |= V_181 ;
F_29 ( V_2 , V_98 , V_3 , V_144 ) ;
F_29 ( V_2 , V_182 , V_3 , 0 ) ;
}
void F_71 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_144 ;
V_144 = F_2 ( V_2 , V_98 , V_3 ) ;
V_144 &= ~ V_181 ;
F_29 ( V_2 , V_98 , V_3 , V_144 ) ;
}
void F_72 ( struct V_183 * V_11 , struct V_88 * V_89 ,
int V_3 )
{
T_1 V_59 , V_60 ;
struct V_41 * V_44 ;
struct V_1 * V_2 = F_73 ( V_11 ) ;
struct V_184 * V_185 ;
V_59 = F_2 ( V_2 , V_186 , V_3 ) >> 4 ;
V_60 = F_2 ( V_2 , V_187 , V_3 ) >> 4 ;
while ( V_89 -> V_59 != V_59 ) {
V_185 = (struct V_184 * ) F_74 ( V_89 , V_89 -> V_59 ) ;
if ( V_185 -> V_188 != V_189 ) {
F_67 ( V_89 , 1 ) ;
continue;
}
V_44 = (struct V_41 * ) V_89 -> V_92 [ V_89 -> V_59 ] ;
if ( V_44 )
F_75 ( V_44 ) ;
F_76 ( 1 , ( V_190 * ) & V_11 -> V_191 . V_192 ) ;
F_76 ( V_185 -> V_193 ,
( V_190 * ) & V_11 -> V_191 . V_194 ) ;
F_67 ( V_89 , V_185 -> V_195 + 1 ) ;
}
}
static int F_77 ( struct V_41 * V_44 )
{
struct V_196 * V_197 = F_78 ( V_44 ) ;
unsigned int V_198 = F_79 ( V_44 ) + F_80 ( V_44 ) ;
unsigned int V_199 = V_44 -> V_43 - V_198 ;
unsigned int V_200 = V_197 -> V_201 ;
long V_202 = - 1 ;
long V_203 = F_81 ( V_44 ) - V_198 ;
long V_204 = 0 ;
long V_205 ;
int V_206 = 0 ;
int V_207 ;
for ( V_207 = 0 ; V_207 < V_197 -> V_208 ; V_207 ++ ) {
unsigned int V_209 = 0 ;
for ( V_206 ++ ; V_209 < V_200 ; V_206 ++ ) {
while ( V_204 >= V_203 ) {
V_202 ++ ;
V_203 = F_82 ( & V_197 -> V_210 [ V_202 ] ) ;
V_204 = 0 ;
}
V_205 = V_200 - V_209 ;
if ( V_205 > V_203 - V_204 )
V_205 = V_203 - V_204 ;
V_204 += V_205 ;
V_209 += V_205 ;
}
V_199 -= V_200 ;
if ( V_199 < V_200 )
V_200 = V_199 ;
}
return V_206 + V_197 -> V_208 ;
}
static int F_83 ( struct V_1 * V_2 , struct V_41 * V_44 )
{
int V_195 = V_211 ;
if ( F_78 ( V_44 ) -> V_201 ) {
V_195 = F_77 ( V_44 ) ;
return V_195 ;
}
if ( F_78 ( V_44 ) -> V_212 )
V_195 += F_78 ( V_44 ) -> V_212 ;
return V_195 ;
}
static inline void
F_84 ( struct V_88 * V_89 , int V_180 ,
int V_195 , struct V_41 * V_44 , int V_43 )
{
int V_213 ;
struct V_184 * V_185 ;
V_185 = (struct V_184 * ) F_74 ( V_89 , V_180 ) ;
V_89 -> V_92 [ V_180 ] = ( T_1 ) V_44 ;
memset ( V_185 , 0 , V_90 ) ;
V_185 -> V_188 = V_189 ;
V_185 -> V_214 = 1 ;
V_185 -> V_195 = V_195 ;
V_185 -> V_193 = V_43 ;
if ( V_44 -> V_215 == V_216 ) {
if ( V_44 -> V_217 != F_85 ( V_218 ) )
return;
V_185 -> V_219 = 1 ;
V_185 -> V_220 = F_86 ( V_44 ) ;
V_185 -> V_221 = F_79 ( V_44 ) ;
V_213 = F_87 ( V_44 ) -> V_217 ;
switch ( V_213 ) {
case V_222 :
V_185 -> V_223 = V_224 ;
break;
case V_225 :
V_185 -> V_223 = V_226 ;
break;
case V_227 :
V_185 -> V_223 = V_228 ;
break;
}
}
}
static inline void F_88 ( struct V_88 * V_89 , int V_180 ,
int V_17 , T_1 V_29 )
{
struct V_229 * V_230 ;
V_180 &= ( V_89 -> V_13 . V_14 - 1 ) ;
V_230 = (struct V_229 * ) F_74 ( V_89 , V_180 ) ;
memset ( V_230 , 0 , V_90 ) ;
V_230 -> V_188 = V_231 ;
V_230 -> V_232 = V_233 ;
V_230 -> V_17 = V_17 ;
V_230 -> V_234 = V_29 ;
}
static int F_89 ( struct V_1 * V_2 , struct V_88 * V_89 ,
int V_180 , struct V_41 * V_44 )
{
struct V_235 V_236 ;
int V_237 = 0 , V_179 = 0 ;
int V_238 , V_239 , V_240 ;
int V_241 = V_180 ;
int V_242 = F_79 ( V_44 ) + F_80 ( V_44 ) ;
F_90 ( V_44 , & V_236 ) ;
V_239 = V_44 -> V_43 - V_242 ;
while ( V_239 > 0 ) {
char * V_185 ;
V_241 = V_180 ;
V_240 = F_91 ( int , F_78 ( V_44 ) -> V_201 , V_239 ) ;
V_239 -= V_240 ;
V_180 = F_69 ( V_89 , V_180 ) ;
V_185 = V_89 -> V_95 + V_180 * V_96 ;
F_92 ( V_44 , V_185 , & V_236 , V_240 , V_239 == 0 ) ;
F_88 ( V_89 , V_180 , V_242 ,
V_89 -> V_97 +
V_180 * V_96 ) ;
V_237 = 2 ;
V_238 = V_242 ;
while ( V_240 > 0 ) {
int V_17 ;
V_17 = F_91 ( int , V_236 . V_17 , V_240 ) ;
V_180 = F_69 ( V_89 , V_180 ) ;
F_88 ( V_89 , V_180 , V_17 ,
F_25 ( V_236 . V_29 ) ) ;
V_237 ++ ;
V_238 += V_17 ;
V_240 -= V_17 ;
F_93 ( V_44 , & V_236 , V_17 ) ;
}
F_84 ( V_89 , V_241 ,
V_237 - 1 , V_44 , V_238 ) ;
V_89 -> V_92 [ V_241 ] = ( T_1 ) NULL ;
V_180 = F_69 ( V_89 , V_180 ) ;
V_179 += V_237 ;
}
V_89 -> V_92 [ V_241 ] = ( T_1 ) V_44 ;
F_28 () ;
F_29 ( V_2 , V_182 ,
F_94 ( V_44 ) , V_179 ) ;
V_2 -> V_243 . V_244 ++ ;
return 1 ;
}
int F_95 ( struct V_1 * V_2 , struct V_41 * V_44 )
{
int V_245 , V_17 ;
int V_195 ;
int V_146 , V_180 ;
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_88 * V_89 ;
V_146 = F_94 ( V_44 ) ;
V_89 = & V_62 -> V_89 [ V_146 ] ;
V_195 = F_83 ( V_2 , V_44 ) ;
if ( V_195 > F_96 ( & V_89 -> V_93 ) )
goto V_246;
V_180 = F_65 ( V_89 , V_195 ) ;
if ( F_78 ( V_44 ) -> V_201 )
return F_89 ( V_2 , V_89 , V_180 , V_44 ) ;
F_84 ( V_89 , V_180 , V_195 - 1 , V_44 , V_44 -> V_43 ) ;
V_180 = F_69 ( V_89 , V_180 ) ;
V_17 = F_97 ( V_44 ) ? F_81 ( V_44 ) : V_44 -> V_43 ;
F_88 ( V_89 , V_180 , V_17 , F_25 ( V_44 -> V_29 ) ) ;
if ( ! F_97 ( V_44 ) )
goto V_247;
for ( V_245 = 0 ; V_245 < F_78 ( V_44 ) -> V_212 ; V_245 ++ ) {
const struct V_248 * V_249 ;
V_249 = & F_78 ( V_44 ) -> V_210 [ V_245 ] ;
V_180 = F_69 ( V_89 , V_180 ) ;
V_17 = F_82 ( V_249 ) ;
F_88 ( V_89 , V_180 , V_17 ,
F_25 (
F_98 ( V_249 ) ) ) ;
}
V_247:
F_28 () ;
F_29 ( V_2 , V_182 ,
V_146 , V_195 ) ;
return 1 ;
V_246:
F_99 ( V_2 -> V_11 , L_5 ) ;
return 0 ;
}
static inline unsigned F_100 ( unsigned V_245 )
{
#ifdef F_59
return ( V_245 & ~ 3 ) + 3 - ( V_245 & 3 ) ;
#else
return V_245 ;
#endif
}
struct V_41 * F_101 ( struct V_1 * V_2 , struct V_250 * V_251 )
{
int V_249 ;
int V_252 = 0 ;
struct V_41 * V_44 = NULL ;
struct V_41 * V_253 = NULL ;
struct V_41 * V_254 = NULL ;
T_4 * V_255 = NULL ;
T_1 * V_256 = NULL ;
V_255 = ( void * ) V_251 + ( 3 * sizeof( T_1 ) ) ;
V_256 = ( void * ) V_251 + ( 6 * sizeof( T_1 ) ) ;
F_99 ( V_2 -> V_11 , L_6 ,
V_257 , V_251 -> V_258 , V_251 -> V_259 , V_251 -> V_260 ) ;
for ( V_249 = 0 ; V_249 < V_251 -> V_258 ; V_249 ++ ) {
V_252 = V_255 [ F_100 ( V_249 ) ] ;
if ( ! V_249 ) {
V_44 = F_16 ( V_2 ,
* V_256 - V_251 -> V_261 ,
V_252 ) ;
if ( ! V_44 )
return NULL ;
F_21 ( V_44 , V_251 -> V_261 ) ;
F_102 ( V_44 , V_252 ) ;
} else {
V_253 = F_16 ( V_2 , * V_256 ,
V_252 ) ;
if ( ! V_253 ) {
F_103 ( V_44 ) ;
return NULL ;
}
if ( ! F_78 ( V_44 ) -> V_262 )
F_78 ( V_44 ) -> V_262 = V_253 ;
else
V_254 -> V_263 = V_253 ;
V_254 = V_253 ;
V_44 -> V_43 += V_252 ;
V_44 -> V_199 += V_252 ;
V_253 -> V_43 = V_252 ;
}
V_256 ++ ;
}
return V_44 ;
}
void F_30 ( struct V_1 * V_2 , int V_264 , int V_265 )
{
T_1 V_9 ;
V_9 = F_104 ( V_2 , V_266 ) ;
switch ( V_264 ) {
case V_267 :
V_9 |= ( ( 1ULL << V_265 ) << V_268 ) ;
break;
case V_269 :
V_9 |= ( ( 1ULL << V_265 ) << V_270 ) ;
break;
case V_75 :
V_9 |= ( ( 1ULL << V_265 ) << V_271 ) ;
break;
case V_272 :
V_9 |= ( 1ULL << V_273 ) ;
break;
case V_274 :
V_9 |= ( 1ULL << V_275 ) ;
break;
case V_276 :
V_9 |= ( 1ULL << V_277 ) ;
break;
case V_278 :
V_9 |= ( 1ULL << V_279 ) ;
break;
default:
F_4 ( V_2 -> V_11 ,
L_7 ) ;
break;
}
F_105 ( V_2 , V_266 , V_9 ) ;
}
void F_106 ( struct V_1 * V_2 , int V_264 , int V_265 )
{
T_1 V_9 = 0 ;
switch ( V_264 ) {
case V_267 :
V_9 |= ( ( 1ULL << V_265 ) << V_268 ) ;
break;
case V_269 :
V_9 |= ( ( 1ULL << V_265 ) << V_270 ) ;
break;
case V_75 :
V_9 |= ( ( 1ULL << V_265 ) << V_271 ) ;
break;
case V_272 :
V_9 |= ( 1ULL << V_273 ) ;
break;
case V_274 :
V_9 |= ( 1ULL << V_275 ) ;
break;
case V_276 :
V_9 |= ( 1ULL << V_277 ) ;
break;
case V_278 :
V_9 |= ( 1ULL << V_279 ) ;
break;
default:
F_4 ( V_2 -> V_11 ,
L_8 ) ;
break;
}
F_105 ( V_2 , V_280 , V_9 ) ;
}
void F_107 ( struct V_1 * V_2 , int V_264 , int V_265 )
{
T_1 V_9 = 0 ;
switch ( V_264 ) {
case V_267 :
V_9 = ( ( 1ULL << V_265 ) << V_268 ) ;
break;
case V_269 :
V_9 = ( ( 1ULL << V_265 ) << V_270 ) ;
break;
case V_75 :
V_9 = ( ( 1ULL << V_265 ) << V_271 ) ;
break;
case V_272 :
V_9 = ( 1ULL << V_273 ) ;
break;
case V_274 :
V_9 = ( 1ULL << V_275 ) ;
break;
case V_276 :
V_9 = ( 1ULL << V_277 ) ;
break;
case V_278 :
V_9 |= ( 1ULL << V_279 ) ;
break;
default:
F_4 ( V_2 -> V_11 ,
L_9 ) ;
break;
}
F_105 ( V_2 , V_281 , V_9 ) ;
}
int F_108 ( struct V_1 * V_2 , int V_264 , int V_265 )
{
T_1 V_9 ;
T_1 V_282 = 0xff ;
V_9 = F_104 ( V_2 , V_266 ) ;
switch ( V_264 ) {
case V_267 :
V_282 = ( ( 1ULL << V_265 ) << V_268 ) ;
break;
case V_269 :
V_282 = ( ( 1ULL << V_265 ) << V_270 ) ;
break;
case V_75 :
V_282 = ( ( 1ULL << V_265 ) << V_271 ) ;
break;
case V_272 :
V_282 = V_283 ;
break;
case V_274 :
V_282 = V_284 ;
break;
case V_276 :
V_282 = V_285 ;
break;
case V_278 :
V_282 = V_286 ;
break;
default:
F_4 ( V_2 -> V_11 ,
L_10 ) ;
break;
}
return ( V_9 & V_282 ) ;
}
void F_109 ( struct V_1 * V_2 , int V_287 )
{
struct V_114 * V_115 ;
#define F_110 ( V_4 ) \
nicvf_reg_read(nic, NIC_QSET_RQ_0_7_STAT_0_1 |\
(rq_idx << NIC_Q_NUM_SHIFT) | (reg << 3))
V_115 = & V_2 -> V_62 -> V_115 [ V_287 ] ;
V_115 -> V_191 . V_288 = F_110 ( V_289 ) ;
V_115 -> V_191 . V_290 = F_110 ( V_291 ) ;
}
void F_111 ( struct V_1 * V_2 , int V_292 )
{
struct V_88 * V_89 ;
#define F_112 ( V_4 ) \
nicvf_reg_read(nic, NIC_QSET_SQ_0_7_STAT_0_1 |\
(sq_idx << NIC_Q_NUM_SHIFT) | (reg << 3))
V_89 = & V_2 -> V_62 -> V_89 [ V_292 ] ;
V_89 -> V_191 . V_288 = F_112 ( V_289 ) ;
V_89 -> V_191 . V_290 = F_112 ( V_291 ) ;
}
int F_113 ( struct V_1 * V_2 ,
struct V_81 * V_82 , struct V_250 * V_251 )
{
struct V_293 * V_191 = & V_82 -> V_191 ;
if ( ! V_251 -> V_294 && ! V_251 -> V_295 ) {
V_191 -> V_296 . V_297 . V_298 ++ ;
return 0 ;
}
if ( F_114 ( V_2 ) )
F_4 ( V_2 -> V_11 ,
L_11 ,
V_2 -> V_11 -> V_299 ,
V_251 -> V_294 , V_251 -> V_295 ) ;
switch ( V_251 -> V_294 ) {
case V_300 :
V_191 -> V_296 . V_301 . V_302 ++ ;
break;
case V_303 :
V_191 -> V_296 . V_301 . V_304 ++ ;
break;
case V_305 :
V_191 -> V_296 . V_301 . V_306 ++ ;
break;
case V_307 :
V_191 -> V_296 . V_301 . V_308 ++ ;
break;
}
switch ( V_251 -> V_295 ) {
case V_309 :
V_191 -> V_296 . V_297 . V_310 ++ ;
break;
case V_311 :
V_191 -> V_296 . V_297 . V_312 ++ ;
break;
case V_313 :
V_191 -> V_296 . V_297 . V_314 ++ ;
break;
case V_315 :
V_191 -> V_296 . V_297 . V_316 ++ ;
break;
case V_317 :
V_191 -> V_296 . V_297 . V_318 ++ ;
break;
case V_319 :
V_191 -> V_296 . V_297 . V_320 ++ ;
break;
case V_321 :
V_191 -> V_296 . V_297 . V_322 ++ ;
break;
case V_323 :
V_191 -> V_296 . V_297 . V_324 ++ ;
break;
case V_325 :
V_191 -> V_296 . V_297 . V_326 ++ ;
break;
case V_327 :
V_191 -> V_296 . V_297 . V_328 ++ ;
break;
case V_329 :
V_191 -> V_296 . V_297 . V_330 ++ ;
break;
case V_331 :
V_191 -> V_296 . V_297 . V_332 ++ ;
break;
case V_333 :
V_191 -> V_296 . V_297 . V_334 ++ ;
break;
case V_335 :
V_191 -> V_296 . V_297 . V_336 ++ ;
break;
case V_337 :
V_191 -> V_296 . V_297 . V_338 ++ ;
break;
case V_339 :
V_191 -> V_296 . V_297 . V_340 ++ ;
break;
case V_341 :
V_191 -> V_296 . V_297 . V_342 ++ ;
break;
case V_343 :
V_191 -> V_296 . V_297 . V_344 ++ ;
break;
case V_345 :
V_191 -> V_296 . V_297 . V_346 ++ ;
break;
case V_347 :
V_191 -> V_296 . V_297 . V_348 ++ ;
break;
case V_349 :
V_191 -> V_296 . V_297 . V_350 ++ ;
break;
case V_351 :
V_191 -> V_296 . V_297 . V_352 ++ ;
break;
case V_353 :
V_191 -> V_296 . V_297 . V_354 ++ ;
break;
case V_355 :
V_191 -> V_296 . V_297 . V_356 ++ ;
break;
case V_357 :
V_191 -> V_296 . V_297 . V_358 ++ ;
break;
case V_359 :
V_191 -> V_296 . V_297 . V_360 ++ ;
break;
case V_361 :
V_191 -> V_296 . V_297 . V_362 ++ ;
break;
case V_363 :
V_191 -> V_296 . V_297 . V_364 ++ ;
break;
case V_365 :
V_191 -> V_296 . V_297 . V_366 ++ ;
break;
case V_367 :
V_191 -> V_296 . V_297 . V_368 ++ ;
break;
}
return 1 ;
}
int F_115 ( struct V_1 * V_2 ,
struct V_81 * V_82 , struct V_369 * V_370 )
{
struct V_293 * V_191 = & V_82 -> V_191 ;
switch ( V_370 -> V_371 ) {
case V_372 :
V_191 -> V_373 . V_298 ++ ;
return 0 ;
case V_374 :
V_191 -> V_373 . V_375 ++ ;
break;
case V_376 :
V_191 -> V_373 . V_377 ++ ;
break;
case V_378 :
V_191 -> V_373 . V_379 ++ ;
break;
case V_380 :
V_191 -> V_373 . V_381 ++ ;
break;
case V_382 :
V_191 -> V_373 . V_383 ++ ;
break;
case V_384 :
V_191 -> V_373 . V_385 ++ ;
break;
case V_386 :
V_191 -> V_373 . V_387 ++ ;
break;
case V_388 :
V_191 -> V_373 . V_389 ++ ;
break;
case V_390 :
V_191 -> V_373 . V_391 ++ ;
break;
case V_392 :
V_191 -> V_373 . V_393 ++ ;
break;
case V_394 :
V_191 -> V_373 . V_395 ++ ;
break;
case V_396 :
V_191 -> V_373 . V_397 ++ ;
break;
case V_398 :
V_191 -> V_373 . V_399 ++ ;
break;
}
return 1 ;
}

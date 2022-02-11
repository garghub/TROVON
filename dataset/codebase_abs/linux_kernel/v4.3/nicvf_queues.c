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
void F_49 ( struct V_1 * V_2 , T_4 V_114 )
{
T_1 V_115 ;
int V_116 ;
V_115 = F_2 ( V_2 , V_117 , 0 ) ;
if ( V_114 & V_118 )
V_115 |= ( 1ULL << 25 ) ;
else
V_115 &= ~ ( 1ULL << 25 ) ;
F_29 ( V_2 , V_117 , 0 , V_115 ) ;
for ( V_116 = 0 ; V_116 < V_2 -> V_119 ; V_116 ++ )
if ( V_2 -> V_120 [ V_116 ] )
F_29 ( V_2 -> V_120 [ V_116 ] ,
V_117 , 0 , V_115 ) ;
}
static void F_50 ( struct V_1 * V_2 , struct V_61 * V_62 ,
int V_3 , bool V_54 )
{
union V_101 V_102 = {} ;
struct V_121 * V_122 ;
struct V_115 V_115 ;
V_122 = & V_62 -> V_122 [ V_3 ] ;
V_122 -> V_54 = V_54 ;
F_29 ( V_2 , V_123 , V_3 , 0 ) ;
if ( ! V_122 -> V_54 ) {
F_45 ( V_2 , V_62 , V_3 ) ;
return;
}
V_122 -> V_124 = V_62 -> V_125 ;
V_122 -> V_126 = V_3 ;
V_122 -> V_127 = V_62 -> V_125 ;
V_122 -> V_128 = V_62 -> V_64 - 1 ;
V_122 -> V_129 = V_62 -> V_125 ;
V_122 -> V_130 = V_62 -> V_64 - 1 ;
V_122 -> V_131 = 1 ;
V_102 . V_122 . V_103 = V_132 ;
V_102 . V_122 . V_133 = V_62 -> V_125 ;
V_102 . V_122 . V_134 = V_3 ;
V_102 . V_122 . V_135 = ( V_122 -> V_131 << 26 ) | ( V_122 -> V_124 << 19 ) |
( V_122 -> V_126 << 16 ) | ( V_122 -> V_129 << 9 ) |
( V_122 -> V_130 << 8 ) |
( V_122 -> V_127 << 1 ) | ( V_122 -> V_128 ) ;
F_46 ( V_2 , & V_102 ) ;
V_102 . V_122 . V_103 = V_136 ;
V_102 . V_122 . V_135 = ( 1ULL << 63 ) | ( 1ULL << 62 ) | ( V_62 -> V_125 << 0 ) ;
F_46 ( V_2 , & V_102 ) ;
V_102 . V_122 . V_103 = V_137 ;
V_102 . V_122 . V_135 = ( 1ULL << 62 ) | ( V_138 << 8 ) ;
F_46 ( V_2 , & V_102 ) ;
F_29 ( V_2 , V_117 , 0 , 0x00 ) ;
if ( ! V_2 -> V_139 )
F_49 ( V_2 , V_2 -> V_11 -> V_114 ) ;
V_115 . V_140 = 1 ;
V_115 . V_141 = 0 ;
F_29 ( V_2 , V_123 , V_3 , * ( T_1 * ) & V_115 ) ;
}
void F_51 ( struct V_1 * V_2 , struct V_61 * V_62 ,
int V_3 , bool V_54 )
{
struct V_81 * V_82 ;
struct V_142 V_142 ;
V_82 = & V_62 -> V_82 [ V_3 ] ;
V_82 -> V_54 = V_54 ;
if ( ! V_82 -> V_54 ) {
F_47 ( V_2 , V_62 , V_3 ) ;
return;
}
F_29 ( V_2 , V_106 , V_3 , V_107 ) ;
if ( ! V_82 -> V_54 )
return;
F_52 ( & V_82 -> V_143 ) ;
F_29 ( V_2 , V_144 ,
V_3 , ( T_1 ) ( V_82 -> V_13 . V_24 ) ) ;
V_142 . V_140 = 1 ;
V_142 . V_145 = 0 ;
V_142 . V_131 = 0 ;
V_142 . V_146 = V_147 ;
V_142 . V_148 = 0 ;
F_29 ( V_2 , V_106 , V_3 , * ( T_1 * ) & V_142 ) ;
F_29 ( V_2 , V_149 , V_3 , V_82 -> V_55 ) ;
F_29 ( V_2 , V_105 ,
V_3 , V_2 -> V_86 ) ;
}
static void F_53 ( struct V_1 * V_2 , struct V_61 * V_62 ,
int V_3 , bool V_54 )
{
union V_101 V_102 = {} ;
struct V_88 * V_89 ;
struct V_150 V_150 ;
V_89 = & V_62 -> V_89 [ V_3 ] ;
V_89 -> V_54 = V_54 ;
if ( ! V_89 -> V_54 ) {
F_44 ( V_2 , V_62 , V_3 ) ;
return;
}
F_29 ( V_2 , V_98 , V_3 , V_100 ) ;
V_89 -> V_124 = V_62 -> V_125 ;
V_89 -> V_126 = V_3 ;
V_102 . V_89 . V_103 = V_151 ;
V_102 . V_89 . V_133 = V_62 -> V_125 ;
V_102 . V_89 . V_152 = V_3 ;
V_102 . V_89 . V_139 = V_2 -> V_139 ;
V_102 . V_89 . V_135 = ( V_89 -> V_124 << 3 ) | V_89 -> V_126 ;
F_46 ( V_2 , & V_102 ) ;
F_29 ( V_2 , V_153 ,
V_3 , ( T_1 ) ( V_89 -> V_13 . V_24 ) ) ;
V_150 . V_140 = 1 ;
V_150 . V_145 = 0 ;
V_150 . V_154 = 0 ;
V_150 . V_146 = V_155 ;
V_150 . V_156 = 0 ;
F_29 ( V_2 , V_98 , V_3 , * ( T_1 * ) & V_150 ) ;
F_29 ( V_2 , V_157 , V_3 , V_89 -> V_55 ) ;
if ( F_54 ( V_3 ) ) {
F_55 ( V_3 , & V_89 -> V_158 ) ;
F_56 ( V_2 -> V_11 ,
& V_89 -> V_158 , V_3 ) ;
}
}
static void F_57 ( struct V_1 * V_2 , struct V_61 * V_62 ,
int V_3 , bool V_54 )
{
struct V_46 * V_46 ;
struct V_159 V_159 ;
V_46 = & V_62 -> V_46 [ V_3 ] ;
F_48 ( V_2 , V_46 , V_3 ) ;
if ( ! V_54 )
return;
F_29 ( V_2 , V_160 ,
V_3 , ( T_1 ) ( V_46 -> V_13 . V_24 ) ) ;
V_159 . V_140 = 1 ;
V_159 . V_145 = 0 ;
V_159 . V_154 = 0 ;
V_159 . V_146 = V_161 ;
V_159 . V_148 = 0 ;
V_159 . V_162 = V_46 -> V_53 / 128 ;
F_29 ( V_2 , V_111 ,
V_3 , * ( T_1 * ) & V_159 ) ;
F_29 ( V_2 , V_74 ,
V_3 , V_62 -> V_71 - 1 ) ;
F_29 ( V_2 , V_163 ,
V_3 , V_46 -> V_55 - 1 ) ;
}
void F_58 ( struct V_1 * V_2 , bool V_54 )
{
union V_101 V_102 = {} ;
struct V_61 * V_62 = V_2 -> V_62 ;
struct V_164 * V_164 ;
if ( ! V_62 ) {
F_59 ( V_2 -> V_11 ,
L_4 ) ;
return;
}
V_62 -> V_54 = V_54 ;
V_62 -> V_125 = V_2 -> V_165 ;
V_102 . V_62 . V_103 = V_166 ;
V_102 . V_62 . V_167 = V_62 -> V_125 ;
V_102 . V_62 . V_119 = V_2 -> V_119 ;
V_102 . V_62 . V_135 = 0 ;
V_164 = (struct V_164 * ) & V_102 . V_62 . V_135 ;
if ( V_62 -> V_54 ) {
V_164 -> V_140 = 1 ;
#ifdef F_60
V_164 -> V_168 = 1 ;
#endif
V_164 -> V_169 = V_62 -> V_125 ;
}
F_46 ( V_2 , & V_102 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_61 * V_62 = V_2 -> V_62 ;
for ( V_3 = 0 ; V_3 < V_62 -> V_64 ; V_3 ++ )
F_26 ( V_2 , & V_62 -> V_46 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < V_62 -> V_170 ; V_3 ++ )
F_37 ( V_2 , & V_62 -> V_82 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < V_62 -> V_171 ; V_3 ++ )
F_42 ( V_2 , & V_62 -> V_89 [ V_3 ] ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_61 * V_62 = V_2 -> V_62 ;
for ( V_3 = 0 ; V_3 < V_62 -> V_64 ; V_3 ++ ) {
if ( F_23 ( V_2 , & V_62 -> V_46 [ V_3 ] , V_62 -> V_71 ,
V_172 ) )
goto V_173;
}
for ( V_3 = 0 ; V_3 < V_62 -> V_171 ; V_3 ++ ) {
if ( F_38 ( V_2 , & V_62 -> V_89 [ V_3 ] , V_62 -> V_174 ) )
goto V_173;
}
for ( V_3 = 0 ; V_3 < V_62 -> V_170 ; V_3 ++ ) {
if ( F_36 ( V_2 , & V_62 -> V_82 [ V_3 ] , V_62 -> V_175 ) )
goto V_173;
}
return 0 ;
V_173:
F_61 ( V_2 ) ;
return - V_23 ;
}
int F_63 ( struct V_1 * V_2 )
{
struct V_61 * V_62 ;
V_62 = F_64 ( & V_2 -> V_19 -> V_20 , sizeof( * V_62 ) , V_22 ) ;
if ( ! V_62 )
return - V_23 ;
V_2 -> V_62 = V_62 ;
V_62 -> V_64 = V_176 ;
V_62 -> V_177 = V_178 ;
V_62 -> V_171 = V_179 ;
V_62 -> V_170 = V_180 ;
V_62 -> V_71 = V_181 ;
V_62 -> V_174 = V_182 ;
V_62 -> V_175 = V_183 ;
V_2 -> V_184 = V_62 -> V_177 ;
V_2 -> V_185 = V_62 -> V_171 ;
return 0 ;
}
int F_65 ( struct V_1 * V_2 , bool V_54 )
{
bool V_186 = false ;
struct V_61 * V_62 = V_2 -> V_62 ;
int V_3 ;
if ( ! V_62 )
return 0 ;
if ( V_54 ) {
if ( F_62 ( V_2 ) )
return - V_23 ;
for ( V_3 = 0 ; V_3 < V_62 -> V_171 ; V_3 ++ )
F_53 ( V_2 , V_62 , V_3 , V_54 ) ;
for ( V_3 = 0 ; V_3 < V_62 -> V_170 ; V_3 ++ )
F_51 ( V_2 , V_62 , V_3 , V_54 ) ;
for ( V_3 = 0 ; V_3 < V_62 -> V_64 ; V_3 ++ )
F_57 ( V_2 , V_62 , V_3 , V_54 ) ;
for ( V_3 = 0 ; V_3 < V_62 -> V_177 ; V_3 ++ )
F_50 ( V_2 , V_62 , V_3 , V_54 ) ;
} else {
for ( V_3 = 0 ; V_3 < V_62 -> V_177 ; V_3 ++ )
F_50 ( V_2 , V_62 , V_3 , V_186 ) ;
for ( V_3 = 0 ; V_3 < V_62 -> V_64 ; V_3 ++ )
F_57 ( V_2 , V_62 , V_3 , V_186 ) ;
for ( V_3 = 0 ; V_3 < V_62 -> V_171 ; V_3 ++ )
F_53 ( V_2 , V_62 , V_3 , V_186 ) ;
for ( V_3 = 0 ; V_3 < V_62 -> V_170 ; V_3 ++ )
F_51 ( V_2 , V_62 , V_3 , V_186 ) ;
F_61 ( V_2 ) ;
}
return 0 ;
}
static inline int F_66 ( struct V_88 * V_89 , int V_187 )
{
int V_188 ;
V_188 = V_89 -> V_60 ;
F_67 ( V_187 , & V_89 -> V_93 ) ;
V_89 -> V_60 += V_187 ;
V_89 -> V_60 &= ( V_89 -> V_13 . V_14 - 1 ) ;
return V_188 ;
}
void F_68 ( struct V_88 * V_89 , int V_187 )
{
F_69 ( V_187 , & V_89 -> V_93 ) ;
V_89 -> V_59 += V_187 ;
V_89 -> V_59 &= ( V_89 -> V_13 . V_14 - 1 ) ;
}
static inline int F_70 ( struct V_88 * V_89 , int V_188 )
{
V_188 ++ ;
V_188 &= ( V_89 -> V_13 . V_14 - 1 ) ;
return V_188 ;
}
void F_71 ( struct V_1 * V_2 , struct V_88 * V_89 , int V_3 )
{
T_1 V_150 ;
V_150 = F_2 ( V_2 , V_98 , V_3 ) ;
V_150 |= V_189 ;
F_29 ( V_2 , V_98 , V_3 , V_150 ) ;
F_29 ( V_2 , V_190 , V_3 , 0 ) ;
}
void F_72 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_150 ;
V_150 = F_2 ( V_2 , V_98 , V_3 ) ;
V_150 &= ~ V_189 ;
F_29 ( V_2 , V_98 , V_3 , V_150 ) ;
}
void F_73 ( struct V_191 * V_11 , struct V_88 * V_89 ,
int V_3 )
{
T_1 V_59 , V_60 ;
struct V_41 * V_44 ;
struct V_1 * V_2 = F_74 ( V_11 ) ;
struct V_192 * V_193 ;
V_59 = F_2 ( V_2 , V_194 , V_3 ) >> 4 ;
V_60 = F_2 ( V_2 , V_195 , V_3 ) >> 4 ;
while ( V_89 -> V_59 != V_59 ) {
V_193 = (struct V_192 * ) F_75 ( V_89 , V_89 -> V_59 ) ;
if ( V_193 -> V_196 != V_197 ) {
F_68 ( V_89 , 1 ) ;
continue;
}
V_44 = (struct V_41 * ) V_89 -> V_92 [ V_89 -> V_59 ] ;
if ( V_44 )
F_76 ( V_44 ) ;
F_77 ( 1 , ( V_198 * ) & V_11 -> V_199 . V_200 ) ;
F_77 ( V_193 -> V_201 ,
( V_198 * ) & V_11 -> V_199 . V_202 ) ;
F_68 ( V_89 , V_193 -> V_203 + 1 ) ;
}
}
static int F_78 ( struct V_41 * V_44 )
{
struct V_204 * V_205 = F_79 ( V_44 ) ;
unsigned int V_206 = F_80 ( V_44 ) + F_81 ( V_44 ) ;
unsigned int V_207 = V_44 -> V_43 - V_206 ;
unsigned int V_208 = V_205 -> V_209 ;
long V_210 = - 1 ;
long V_211 = F_82 ( V_44 ) - V_206 ;
long V_212 = 0 ;
long V_213 ;
int V_214 = 0 ;
int V_215 ;
for ( V_215 = 0 ; V_215 < V_205 -> V_216 ; V_215 ++ ) {
unsigned int V_217 = 0 ;
for ( V_214 ++ ; V_217 < V_208 ; V_214 ++ ) {
while ( V_212 >= V_211 ) {
V_210 ++ ;
V_211 = F_83 ( & V_205 -> V_218 [ V_210 ] ) ;
V_212 = 0 ;
}
V_213 = V_208 - V_217 ;
if ( V_213 > V_211 - V_212 )
V_213 = V_211 - V_212 ;
V_212 += V_213 ;
V_217 += V_213 ;
}
V_207 -= V_208 ;
if ( V_207 < V_208 )
V_208 = V_207 ;
}
return V_214 + V_205 -> V_216 ;
}
static int F_84 ( struct V_1 * V_2 , struct V_41 * V_44 )
{
int V_203 = V_219 ;
if ( F_79 ( V_44 ) -> V_209 ) {
V_203 = F_78 ( V_44 ) ;
return V_203 ;
}
if ( F_79 ( V_44 ) -> V_220 )
V_203 += F_79 ( V_44 ) -> V_220 ;
return V_203 ;
}
static inline void
F_85 ( struct V_88 * V_89 , int V_188 ,
int V_203 , struct V_41 * V_44 , int V_43 )
{
int V_221 ;
struct V_192 * V_193 ;
V_193 = (struct V_192 * ) F_75 ( V_89 , V_188 ) ;
V_89 -> V_92 [ V_188 ] = ( T_1 ) V_44 ;
memset ( V_193 , 0 , V_90 ) ;
V_193 -> V_196 = V_197 ;
V_193 -> V_222 = 1 ;
V_193 -> V_203 = V_203 ;
V_193 -> V_201 = V_43 ;
if ( V_44 -> V_223 == V_224 ) {
V_193 -> V_225 = 1 ;
V_193 -> V_226 = F_86 ( V_44 ) ;
V_193 -> V_227 = F_80 ( V_44 ) ;
V_221 = F_87 ( V_44 ) -> V_228 ;
switch ( V_221 ) {
case V_229 :
V_193 -> V_230 = V_231 ;
break;
case V_232 :
V_193 -> V_230 = V_233 ;
break;
case V_234 :
V_193 -> V_230 = V_235 ;
break;
}
}
}
static inline void F_88 ( struct V_88 * V_89 , int V_188 ,
int V_17 , T_1 V_29 )
{
struct V_236 * V_237 ;
V_188 &= ( V_89 -> V_13 . V_14 - 1 ) ;
V_237 = (struct V_236 * ) F_75 ( V_89 , V_188 ) ;
memset ( V_237 , 0 , V_90 ) ;
V_237 -> V_196 = V_238 ;
V_237 -> V_239 = V_240 ;
V_237 -> V_17 = V_17 ;
V_237 -> V_241 = V_29 ;
}
static int F_89 ( struct V_1 * V_2 , struct V_88 * V_89 ,
int V_152 , int V_188 , struct V_41 * V_44 )
{
struct V_242 V_243 ;
int V_244 = 0 , V_187 = 0 ;
int V_245 , V_246 , V_247 ;
int V_248 = V_188 ;
int V_249 = F_80 ( V_44 ) + F_81 ( V_44 ) ;
F_90 ( V_44 , & V_243 ) ;
V_246 = V_44 -> V_43 - V_249 ;
while ( V_246 > 0 ) {
char * V_193 ;
V_248 = V_188 ;
V_247 = F_91 ( int , F_79 ( V_44 ) -> V_209 , V_246 ) ;
V_246 -= V_247 ;
V_188 = F_70 ( V_89 , V_188 ) ;
V_193 = V_89 -> V_95 + V_188 * V_96 ;
F_92 ( V_44 , V_193 , & V_243 , V_247 , V_246 == 0 ) ;
F_88 ( V_89 , V_188 , V_249 ,
V_89 -> V_97 +
V_188 * V_96 ) ;
V_244 = 2 ;
V_245 = V_249 ;
while ( V_247 > 0 ) {
int V_17 ;
V_17 = F_91 ( int , V_243 . V_17 , V_247 ) ;
V_188 = F_70 ( V_89 , V_188 ) ;
F_88 ( V_89 , V_188 , V_17 ,
F_25 ( V_243 . V_29 ) ) ;
V_244 ++ ;
V_245 += V_17 ;
V_247 -= V_17 ;
F_93 ( V_44 , & V_243 , V_17 ) ;
}
F_85 ( V_89 , V_248 ,
V_244 - 1 , V_44 , V_245 ) ;
V_89 -> V_92 [ V_248 ] = ( T_1 ) NULL ;
V_188 = F_70 ( V_89 , V_188 ) ;
V_187 += V_244 ;
}
V_89 -> V_92 [ V_248 ] = ( T_1 ) V_44 ;
F_28 () ;
F_29 ( V_2 , V_190 ,
V_152 , V_187 ) ;
V_2 -> V_250 . V_251 ++ ;
return 1 ;
}
int F_94 ( struct V_1 * V_2 , struct V_41 * V_44 )
{
int V_252 , V_17 ;
int V_203 ;
int V_152 , V_188 ;
struct V_61 * V_62 ;
struct V_88 * V_89 ;
V_152 = F_95 ( V_44 ) ;
if ( V_152 >= V_253 ) {
V_252 = V_152 / V_253 ;
if ( ! V_2 -> V_120 [ V_252 - 1 ] ) {
F_59 ( V_2 -> V_11 ,
L_5 ,
V_252 - 1 ) ;
return 1 ;
}
V_2 = (struct V_1 * ) V_2 -> V_120 [ V_252 - 1 ] ;
V_152 = V_152 % V_253 ;
}
V_62 = V_2 -> V_62 ;
V_89 = & V_62 -> V_89 [ V_152 ] ;
V_203 = F_84 ( V_2 , V_44 ) ;
if ( V_203 > F_96 ( & V_89 -> V_93 ) )
goto V_254;
V_188 = F_66 ( V_89 , V_203 ) ;
if ( F_79 ( V_44 ) -> V_209 )
return F_89 ( V_2 , V_89 , V_152 , V_188 , V_44 ) ;
F_85 ( V_89 , V_188 , V_203 - 1 , V_44 , V_44 -> V_43 ) ;
V_188 = F_70 ( V_89 , V_188 ) ;
V_17 = F_97 ( V_44 ) ? F_82 ( V_44 ) : V_44 -> V_43 ;
F_88 ( V_89 , V_188 , V_17 , F_25 ( V_44 -> V_29 ) ) ;
if ( ! F_97 ( V_44 ) )
goto V_255;
for ( V_252 = 0 ; V_252 < F_79 ( V_44 ) -> V_220 ; V_252 ++ ) {
const struct V_256 * V_257 ;
V_257 = & F_79 ( V_44 ) -> V_218 [ V_252 ] ;
V_188 = F_70 ( V_89 , V_188 ) ;
V_17 = F_83 ( V_257 ) ;
F_88 ( V_89 , V_188 , V_17 ,
F_25 (
F_98 ( V_257 ) ) ) ;
}
V_255:
F_28 () ;
F_29 ( V_2 , V_190 ,
V_152 , V_203 ) ;
return 1 ;
V_254:
V_2 = V_2 -> V_258 ;
F_99 ( V_2 -> V_11 , L_6 ) ;
return 0 ;
}
static inline unsigned F_100 ( unsigned V_252 )
{
#ifdef F_60
return ( V_252 & ~ 3 ) + 3 - ( V_252 & 3 ) ;
#else
return V_252 ;
#endif
}
struct V_41 * F_101 ( struct V_1 * V_2 , struct V_259 * V_260 )
{
int V_257 ;
int V_261 = 0 ;
struct V_41 * V_44 = NULL ;
struct V_41 * V_262 = NULL ;
struct V_41 * V_263 = NULL ;
T_5 * V_264 = NULL ;
T_1 * V_265 = NULL ;
V_264 = ( void * ) V_260 + ( 3 * sizeof( T_1 ) ) ;
V_265 = ( void * ) V_260 + ( 6 * sizeof( T_1 ) ) ;
F_99 ( V_2 -> V_11 , L_7 ,
V_266 , V_260 -> V_267 , V_260 -> V_268 , V_260 -> V_269 ) ;
for ( V_257 = 0 ; V_257 < V_260 -> V_267 ; V_257 ++ ) {
V_261 = V_264 [ F_100 ( V_257 ) ] ;
if ( ! V_257 ) {
V_44 = F_16 ( V_2 ,
* V_265 - V_260 -> V_270 ,
V_261 ) ;
if ( ! V_44 )
return NULL ;
F_21 ( V_44 , V_260 -> V_270 ) ;
F_102 ( V_44 , V_261 ) ;
} else {
V_262 = F_16 ( V_2 , * V_265 ,
V_261 ) ;
if ( ! V_262 ) {
F_103 ( V_44 ) ;
return NULL ;
}
if ( ! F_79 ( V_44 ) -> V_271 )
F_79 ( V_44 ) -> V_271 = V_262 ;
else
V_263 -> V_272 = V_262 ;
V_263 = V_262 ;
V_44 -> V_43 += V_261 ;
V_44 -> V_207 += V_261 ;
V_262 -> V_43 = V_261 ;
}
V_265 ++ ;
}
return V_44 ;
}
void F_30 ( struct V_1 * V_2 , int V_273 , int V_274 )
{
T_1 V_9 ;
V_9 = F_104 ( V_2 , V_275 ) ;
switch ( V_273 ) {
case V_276 :
V_9 |= ( ( 1ULL << V_274 ) << V_277 ) ;
break;
case V_278 :
V_9 |= ( ( 1ULL << V_274 ) << V_279 ) ;
break;
case V_75 :
V_9 |= ( ( 1ULL << V_274 ) << V_280 ) ;
break;
case V_281 :
V_9 |= ( 1ULL << V_282 ) ;
break;
case V_283 :
V_9 |= ( 1ULL << V_284 ) ;
break;
case V_285 :
V_9 |= ( 1ULL << V_286 ) ;
break;
case V_287 :
V_9 |= ( 1ULL << V_288 ) ;
break;
default:
F_4 ( V_2 -> V_11 ,
L_8 ) ;
break;
}
F_105 ( V_2 , V_275 , V_9 ) ;
}
void F_106 ( struct V_1 * V_2 , int V_273 , int V_274 )
{
T_1 V_9 = 0 ;
switch ( V_273 ) {
case V_276 :
V_9 |= ( ( 1ULL << V_274 ) << V_277 ) ;
break;
case V_278 :
V_9 |= ( ( 1ULL << V_274 ) << V_279 ) ;
break;
case V_75 :
V_9 |= ( ( 1ULL << V_274 ) << V_280 ) ;
break;
case V_281 :
V_9 |= ( 1ULL << V_282 ) ;
break;
case V_283 :
V_9 |= ( 1ULL << V_284 ) ;
break;
case V_285 :
V_9 |= ( 1ULL << V_286 ) ;
break;
case V_287 :
V_9 |= ( 1ULL << V_288 ) ;
break;
default:
F_4 ( V_2 -> V_11 ,
L_9 ) ;
break;
}
F_105 ( V_2 , V_289 , V_9 ) ;
}
void F_107 ( struct V_1 * V_2 , int V_273 , int V_274 )
{
T_1 V_9 = 0 ;
switch ( V_273 ) {
case V_276 :
V_9 = ( ( 1ULL << V_274 ) << V_277 ) ;
break;
case V_278 :
V_9 = ( ( 1ULL << V_274 ) << V_279 ) ;
break;
case V_75 :
V_9 = ( ( 1ULL << V_274 ) << V_280 ) ;
break;
case V_281 :
V_9 = ( 1ULL << V_282 ) ;
break;
case V_283 :
V_9 = ( 1ULL << V_284 ) ;
break;
case V_285 :
V_9 = ( 1ULL << V_286 ) ;
break;
case V_287 :
V_9 |= ( 1ULL << V_288 ) ;
break;
default:
F_4 ( V_2 -> V_11 ,
L_10 ) ;
break;
}
F_105 ( V_2 , V_290 , V_9 ) ;
}
int F_108 ( struct V_1 * V_2 , int V_273 , int V_274 )
{
T_1 V_9 ;
T_1 V_291 = 0xff ;
V_9 = F_104 ( V_2 , V_275 ) ;
switch ( V_273 ) {
case V_276 :
V_291 = ( ( 1ULL << V_274 ) << V_277 ) ;
break;
case V_278 :
V_291 = ( ( 1ULL << V_274 ) << V_279 ) ;
break;
case V_75 :
V_291 = ( ( 1ULL << V_274 ) << V_280 ) ;
break;
case V_281 :
V_291 = V_292 ;
break;
case V_283 :
V_291 = V_293 ;
break;
case V_285 :
V_291 = V_294 ;
break;
case V_287 :
V_291 = V_295 ;
break;
default:
F_4 ( V_2 -> V_11 ,
L_11 ) ;
break;
}
return ( V_9 & V_291 ) ;
}
void F_109 ( struct V_1 * V_2 , int V_296 )
{
struct V_121 * V_122 ;
#define F_110 ( V_4 ) \
nicvf_reg_read(nic, NIC_QSET_RQ_0_7_STAT_0_1 |\
(rq_idx << NIC_Q_NUM_SHIFT) | (reg << 3))
V_122 = & V_2 -> V_62 -> V_122 [ V_296 ] ;
V_122 -> V_199 . V_297 = F_110 ( V_298 ) ;
V_122 -> V_199 . V_299 = F_110 ( V_300 ) ;
}
void F_111 ( struct V_1 * V_2 , int V_301 )
{
struct V_88 * V_89 ;
#define F_112 ( V_4 ) \
nicvf_reg_read(nic, NIC_QSET_SQ_0_7_STAT_0_1 |\
(sq_idx << NIC_Q_NUM_SHIFT) | (reg << 3))
V_89 = & V_2 -> V_62 -> V_89 [ V_301 ] ;
V_89 -> V_199 . V_297 = F_112 ( V_298 ) ;
V_89 -> V_199 . V_299 = F_112 ( V_300 ) ;
}
int F_113 ( struct V_1 * V_2 ,
struct V_81 * V_82 , struct V_259 * V_260 )
{
struct V_302 * V_199 = & V_2 -> V_303 ;
struct V_304 * V_250 = & V_2 -> V_250 ;
if ( ! V_260 -> V_305 && ! V_260 -> V_306 ) {
V_250 -> V_307 ++ ;
return 0 ;
}
if ( F_114 ( V_2 ) )
F_4 ( V_2 -> V_11 ,
L_12 ,
V_2 -> V_11 -> V_308 ,
V_260 -> V_305 , V_260 -> V_306 ) ;
switch ( V_260 -> V_306 ) {
case V_309 :
V_199 -> V_310 ++ ;
break;
case V_311 :
V_199 -> V_312 ++ ;
break;
case V_313 :
V_199 -> V_314 ++ ;
break;
case V_315 :
V_199 -> V_316 ++ ;
break;
case V_317 :
V_199 -> V_318 ++ ;
break;
case V_319 :
V_199 -> V_320 ++ ;
break;
case V_321 :
V_199 -> V_322 ++ ;
break;
case V_323 :
V_199 -> V_324 ++ ;
break;
case V_325 :
V_199 -> V_326 ++ ;
break;
case V_327 :
V_199 -> V_328 ++ ;
break;
case V_329 :
V_199 -> V_330 ++ ;
break;
case V_331 :
V_199 -> V_332 ++ ;
break;
case V_333 :
V_199 -> V_334 ++ ;
break;
case V_335 :
V_199 -> V_336 ++ ;
break;
case V_337 :
V_199 -> V_338 ++ ;
break;
case V_339 :
V_199 -> V_340 ++ ;
break;
case V_341 :
V_199 -> V_342 ++ ;
break;
case V_343 :
V_199 -> V_344 ++ ;
break;
case V_345 :
V_199 -> V_346 ++ ;
break;
case V_347 :
V_199 -> V_348 ++ ;
break;
case V_349 :
V_199 -> V_350 ++ ;
break;
case V_351 :
V_199 -> V_352 ++ ;
break;
case V_353 :
V_199 -> V_354 ++ ;
break;
case V_355 :
V_199 -> V_356 ++ ;
break;
}
return 1 ;
}
int F_115 ( struct V_1 * V_2 ,
struct V_81 * V_82 , struct V_357 * V_358 )
{
struct V_359 * V_199 = & V_82 -> V_199 ;
switch ( V_358 -> V_360 ) {
case V_361 :
V_199 -> V_362 . V_363 ++ ;
return 0 ;
case V_364 :
V_199 -> V_362 . V_365 ++ ;
break;
case V_366 :
V_199 -> V_362 . V_367 ++ ;
break;
case V_368 :
V_199 -> V_362 . V_369 ++ ;
break;
case V_370 :
V_199 -> V_362 . V_371 ++ ;
break;
case V_372 :
V_199 -> V_362 . V_373 ++ ;
break;
case V_374 :
V_199 -> V_362 . V_375 ++ ;
break;
case V_376 :
V_199 -> V_362 . V_377 ++ ;
break;
case V_378 :
V_199 -> V_362 . V_379 ++ ;
break;
case V_380 :
V_199 -> V_362 . V_381 ++ ;
break;
case V_382 :
V_199 -> V_362 . V_383 ++ ;
break;
case V_384 :
V_199 -> V_362 . V_385 ++ ;
break;
case V_386 :
V_199 -> V_362 . V_387 ++ ;
break;
case V_388 :
V_199 -> V_362 . V_389 ++ ;
break;
}
return 1 ;
}

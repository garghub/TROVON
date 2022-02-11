static void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 || ! V_2 -> V_4 )
return;
F_2 ( V_2 -> V_3 , & V_2 -> V_4 -> V_5 ) ;
V_2 -> V_3 = 0 ;
}
static int F_3 ( struct V_1 * V_2 , int V_6 ,
T_1 V_7 , int V_8 , int V_9 , int V_10 )
{
T_1 V_11 ;
T_1 V_12 ;
int V_13 = 10 ;
V_11 = ( 1ULL << V_9 ) - 1 ;
V_11 = ( V_11 << V_8 ) ;
while ( V_13 ) {
V_12 = F_4 ( V_2 , V_7 , V_6 ) ;
if ( ( ( V_12 & V_11 ) >> V_8 ) == V_10 )
return 0 ;
F_5 ( 1000 , 2000 ) ;
V_13 -- ;
}
F_6 ( V_2 -> V_14 , L_1 , V_7 ) ;
return 1 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_17 , int V_18 , int V_19 )
{
V_16 -> V_17 = V_17 ;
V_16 -> V_20 = ( V_18 * V_17 ) + V_19 ;
V_16 -> V_21 = F_8 ( & V_2 -> V_22 -> V_23 , V_16 -> V_20 ,
& V_16 -> V_24 , V_25 ) ;
if ( ! V_16 -> V_21 )
return - V_26 ;
V_16 -> V_27 = F_9 ( ( T_1 ) V_16 -> V_24 , V_19 ) ;
V_16 -> V_28 = V_16 -> V_21 + ( V_16 -> V_27 - V_16 -> V_24 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
if ( ! V_16 )
return;
F_11 ( & V_2 -> V_22 -> V_23 , V_16 -> V_20 ,
V_16 -> V_21 , V_16 -> V_24 ) ;
V_16 -> V_21 = NULL ;
V_16 -> V_28 = NULL ;
}
static inline int F_12 ( struct V_1 * V_2 , T_2 V_29 ,
T_3 V_30 , T_1 * * V_31 )
{
int V_32 = ( V_33 <= 4096 ) ? V_34 : 0 ;
if ( V_2 -> V_4 &&
( ( V_2 -> V_35 + V_30 ) < ( V_33 << V_32 ) ) ) {
V_2 -> V_3 ++ ;
goto V_36;
}
F_1 ( V_2 ) ;
V_2 -> V_4 = NULL ;
if ( ! V_2 -> V_4 ) {
V_2 -> V_4 = F_13 ( V_29 | V_37 | V_38 ,
V_32 ) ;
if ( ! V_2 -> V_4 ) {
V_2 -> V_39 . V_40 ++ ;
return - V_26 ;
}
V_2 -> V_35 = 0 ;
}
V_36:
* V_31 = ( T_1 * ) ( ( T_1 ) F_14 ( V_2 -> V_4 ) + V_2 -> V_35 ) ;
V_2 -> V_35 += V_30 ;
return 0 ;
}
static struct V_41 * F_15 ( struct V_1 * V_2 ,
T_1 V_42 , int V_43 )
{
void * V_44 ;
struct V_41 * V_45 ;
V_44 = F_16 ( V_42 ) ;
V_45 = F_17 ( V_44 , V_46 ) ;
if ( ! V_45 ) {
F_18 ( F_19 ( V_44 ) ) ;
return NULL ;
}
F_20 ( V_45 -> V_44 ) ;
return V_45 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_47 * V_47 ,
int V_48 , int V_49 )
{
int V_50 ;
T_1 * V_31 ;
struct V_51 * V_52 ;
int V_53 ;
V_53 = F_7 ( V_2 , & V_47 -> V_16 , V_48 ,
sizeof( struct V_51 ) ,
V_54 ) ;
if ( V_53 )
return V_53 ;
V_47 -> V_52 = V_47 -> V_16 . V_28 ;
V_47 -> V_55 = V_49 ;
V_47 -> V_56 = true ;
V_47 -> V_57 = V_58 ;
V_2 -> V_4 = NULL ;
for ( V_50 = 0 ; V_50 < V_48 ; V_50 ++ ) {
V_53 = F_12 ( V_2 , V_25 , V_46 ,
& V_31 ) ;
if ( V_53 )
return V_53 ;
V_52 = F_22 ( V_47 , V_50 ) ;
V_52 -> V_59 = F_23 ( V_31 ) >> V_60 ;
}
F_1 ( V_2 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 , struct V_47 * V_47 )
{
int V_61 , V_62 ;
T_1 V_59 ;
struct V_51 * V_52 ;
if ( ! V_47 )
return;
V_47 -> V_56 = false ;
if ( ! V_47 -> V_16 . V_28 )
return;
V_61 = V_47 -> V_61 ;
V_62 = V_47 -> V_62 ;
while ( V_61 != V_62 ) {
V_52 = F_22 ( V_47 , V_61 ) ;
V_59 = V_52 -> V_59 << V_60 ;
F_18 ( F_19 ( F_16 ( V_59 ) ) ) ;
V_61 ++ ;
V_61 &= ( V_47 -> V_16 . V_17 - 1 ) ;
}
V_52 = F_22 ( V_47 , V_62 ) ;
V_59 = V_52 -> V_59 << V_60 ;
F_18 ( F_19 ( F_16 ( V_59 ) ) ) ;
F_10 ( V_2 , & V_47 -> V_16 ) ;
}
static void F_25 ( struct V_1 * V_2 , T_2 V_29 )
{
struct V_63 * V_64 = V_2 -> V_64 ;
int V_65 = V_64 -> V_66 ;
int V_62 , V_67 ;
int V_68 ;
struct V_47 * V_47 ;
struct V_51 * V_52 ;
T_1 * V_31 ;
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
V_62 &= ( V_47 -> V_16 . V_17 - 1 ) ;
if ( F_12 ( V_2 , V_29 , V_46 , & V_31 ) )
break;
V_52 = F_22 ( V_47 , V_62 ) ;
V_52 -> V_59 = F_23 ( V_31 ) >> V_60 ;
V_68 -- ;
V_69 ++ ;
}
F_1 ( V_2 ) ;
F_26 () ;
if ( V_68 )
V_2 -> V_75 = true ;
else
V_2 -> V_75 = false ;
F_27 ( V_2 , V_76 ,
V_65 , V_69 ) ;
V_71:
if ( ! V_2 -> V_75 && V_47 -> V_56 )
F_28 ( V_2 , V_77 , V_65 ) ;
if ( V_65 )
goto V_70;
}
void F_29 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_30 ( V_79 , struct V_1 , V_80 . V_79 ) ;
F_25 ( V_2 , V_25 ) ;
if ( V_2 -> V_75 )
F_31 ( & V_2 -> V_80 , F_32 ( 10 ) ) ;
else
V_2 -> V_81 = false ;
}
void F_33 ( unsigned long V_44 )
{
struct V_1 * V_2 = (struct V_1 * ) V_44 ;
F_25 ( V_2 , V_82 ) ;
if ( V_2 -> V_75 ) {
V_2 -> V_81 = true ;
F_31 ( & V_2 -> V_80 , F_32 ( 10 ) ) ;
}
}
static int F_34 ( struct V_1 * V_2 ,
struct V_83 * V_84 , int V_17 )
{
int V_53 ;
V_53 = F_7 ( V_2 , & V_84 -> V_16 , V_17 , V_85 ,
V_86 ) ;
if ( V_53 )
return V_53 ;
V_84 -> V_52 = V_84 -> V_16 . V_28 ;
V_84 -> V_57 = F_35 ( V_2 -> V_22 ) ? 0 : V_87 ;
V_2 -> V_88 = ( V_89 * 0.05 ) - 1 ;
return 0 ;
}
static void F_36 ( struct V_1 * V_2 , struct V_83 * V_84 )
{
if ( ! V_84 )
return;
if ( ! V_84 -> V_16 . V_28 )
return;
F_10 ( V_2 , & V_84 -> V_16 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_90 * V_91 , int V_17 )
{
int V_53 ;
V_53 = F_7 ( V_2 , & V_91 -> V_16 , V_17 , V_92 ,
V_93 ) ;
if ( V_53 )
return V_53 ;
V_91 -> V_52 = V_91 -> V_16 . V_28 ;
V_91 -> V_94 = F_38 ( V_17 , sizeof( T_1 ) , V_25 ) ;
if ( ! V_91 -> V_94 )
return - V_26 ;
V_91 -> V_61 = 0 ;
V_91 -> V_62 = 0 ;
F_39 ( & V_91 -> V_95 , V_17 - 1 ) ;
V_91 -> V_57 = V_96 ;
V_91 -> V_97 = F_40 ( & V_2 -> V_22 -> V_23 ,
V_17 * V_98 ,
& V_91 -> V_99 , V_25 ) ;
if ( ! V_91 -> V_97 )
return - V_26 ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
if ( ! V_91 )
return;
if ( ! V_91 -> V_16 . V_28 )
return;
if ( V_91 -> V_97 )
F_11 ( & V_2 -> V_22 -> V_23 ,
V_91 -> V_16 . V_17 * V_98 ,
V_91 -> V_97 , V_91 -> V_99 ) ;
F_42 ( V_91 -> V_94 ) ;
F_10 ( V_2 , & V_91 -> V_16 ) ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_63 * V_64 , int V_6 )
{
F_27 ( V_2 , V_100 , V_6 , 0 ) ;
if ( F_3 ( V_2 , V_6 , V_101 , 21 , 1 , 0x01 ) )
return;
F_27 ( V_2 , V_100 , V_6 , V_102 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_63 * V_64 , int V_6 )
{
union V_103 V_104 = {} ;
V_104 . V_105 . V_105 = V_106 ;
F_45 ( V_2 , & V_104 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_63 * V_64 , int V_6 )
{
F_27 ( V_2 , V_107 , V_6 , 0 ) ;
F_27 ( V_2 , V_108 , V_6 , 0 ) ;
F_27 ( V_2 , V_108 , V_6 , V_109 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_47 * V_47 , int V_6 )
{
T_1 V_110 , V_111 ;
int V_13 = 10 ;
V_47 -> V_61 = F_4 ( V_2 ,
V_112 ,
V_6 ) >> 3 ;
V_47 -> V_62 = F_4 ( V_2 ,
V_74 ,
V_6 ) >> 3 ;
V_111 = F_4 ( V_2 , V_72 , V_6 ) ;
if ( ( ( V_111 >> 62 ) & 0x03 ) == 0x3 )
F_27 ( V_2 , V_113 ,
V_6 , V_114 ) ;
F_27 ( V_2 , V_113 , V_6 , 0 ) ;
if ( F_3 ( V_2 , V_6 , V_72 , 62 , 2 , 0x00 ) )
return;
while ( 1 ) {
V_110 = F_4 ( V_2 ,
V_115 ,
V_6 ) ;
if ( ( V_110 & 0xFFFFFFFF ) == ( ( V_110 >> 32 ) & 0xFFFFFFFF ) )
break;
F_5 ( 1000 , 2000 ) ;
V_13 -- ;
if ( ! V_13 ) {
F_6 ( V_2 -> V_14 ,
L_2 ) ;
return;
}
}
F_27 ( V_2 , V_113 ,
V_6 , V_114 ) ;
if ( F_3 ( V_2 , V_6 , V_72 , 62 , 2 , 0x02 ) )
return;
F_27 ( V_2 , V_113 , V_6 , 0x00 ) ;
if ( F_3 ( V_2 , V_6 , V_72 , 62 , 2 , 0x00 ) )
return;
}
void F_48 ( struct V_1 * V_2 , T_4 V_116 )
{
T_1 V_117 ;
int V_118 ;
V_117 = F_4 ( V_2 , V_119 , 0 ) ;
if ( V_116 & V_120 )
V_117 |= ( 1ULL << 25 ) ;
else
V_117 &= ~ ( 1ULL << 25 ) ;
F_27 ( V_2 , V_119 , 0 , V_117 ) ;
for ( V_118 = 0 ; V_118 < V_2 -> V_121 ; V_118 ++ )
if ( V_2 -> V_122 [ V_118 ] )
F_27 ( V_2 -> V_122 [ V_118 ] ,
V_119 , 0 , V_117 ) ;
}
static void F_49 ( struct V_1 * V_2 , struct V_63 * V_64 ,
int V_6 , bool V_56 )
{
union V_103 V_104 = {} ;
struct V_123 * V_124 ;
struct V_117 V_117 ;
V_124 = & V_64 -> V_124 [ V_6 ] ;
V_124 -> V_56 = V_56 ;
F_27 ( V_2 , V_125 , V_6 , 0 ) ;
if ( ! V_124 -> V_56 ) {
F_44 ( V_2 , V_64 , V_6 ) ;
return;
}
V_124 -> V_126 = V_64 -> V_127 ;
V_124 -> V_128 = V_6 ;
V_124 -> V_129 = V_64 -> V_127 ;
V_124 -> V_130 = V_64 -> V_66 - 1 ;
V_124 -> V_131 = V_64 -> V_127 ;
V_124 -> V_132 = V_64 -> V_66 - 1 ;
V_124 -> V_133 = 1 ;
V_104 . V_124 . V_105 = V_134 ;
V_104 . V_124 . V_135 = V_64 -> V_127 ;
V_104 . V_124 . V_136 = V_6 ;
V_104 . V_124 . V_137 = ( V_124 -> V_133 << 26 ) | ( V_124 -> V_126 << 19 ) |
( V_124 -> V_128 << 16 ) | ( V_124 -> V_131 << 9 ) |
( V_124 -> V_132 << 8 ) |
( V_124 -> V_129 << 1 ) | ( V_124 -> V_130 ) ;
F_45 ( V_2 , & V_104 ) ;
V_104 . V_124 . V_105 = V_138 ;
V_104 . V_124 . V_137 = ( 1ULL << 63 ) | ( 1ULL << 62 ) | ( V_64 -> V_127 << 0 ) ;
F_45 ( V_2 , & V_104 ) ;
V_104 . V_124 . V_105 = V_139 ;
V_104 . V_124 . V_137 = ( 1ULL << 62 ) | ( V_140 << 8 ) ;
F_45 ( V_2 , & V_104 ) ;
F_27 ( V_2 , V_119 , 0 , 0x00 ) ;
if ( ! V_2 -> V_141 )
F_48 ( V_2 , V_2 -> V_14 -> V_116 ) ;
memset ( & V_117 , 0 , sizeof( struct V_117 ) ) ;
V_117 . V_142 = 1 ;
V_117 . V_143 = 0 ;
F_27 ( V_2 , V_125 , V_6 , * ( T_1 * ) & V_117 ) ;
}
void F_50 ( struct V_1 * V_2 , struct V_63 * V_64 ,
int V_6 , bool V_56 )
{
struct V_83 * V_84 ;
struct V_144 V_144 ;
V_84 = & V_64 -> V_84 [ V_6 ] ;
V_84 -> V_56 = V_56 ;
if ( ! V_84 -> V_56 ) {
F_46 ( V_2 , V_64 , V_6 ) ;
return;
}
F_27 ( V_2 , V_108 , V_6 , V_109 ) ;
if ( ! V_84 -> V_56 )
return;
F_51 ( & V_84 -> V_145 ) ;
F_27 ( V_2 , V_146 ,
V_6 , ( T_1 ) ( V_84 -> V_16 . V_27 ) ) ;
memset ( & V_144 , 0 , sizeof( struct V_144 ) ) ;
V_144 . V_142 = 1 ;
V_144 . V_147 = 0 ;
V_144 . V_133 = 0 ;
V_144 . V_148 = V_149 ;
V_144 . V_150 = 0 ;
F_27 ( V_2 , V_108 , V_6 , * ( T_1 * ) & V_144 ) ;
F_27 ( V_2 , V_151 , V_6 , V_84 -> V_57 ) ;
F_27 ( V_2 , V_107 ,
V_6 , V_89 ) ;
}
static void F_52 ( struct V_1 * V_2 , struct V_63 * V_64 ,
int V_6 , bool V_56 )
{
union V_103 V_104 = {} ;
struct V_90 * V_91 ;
struct V_152 V_152 ;
V_91 = & V_64 -> V_91 [ V_6 ] ;
V_91 -> V_56 = V_56 ;
if ( ! V_91 -> V_56 ) {
F_43 ( V_2 , V_64 , V_6 ) ;
return;
}
F_27 ( V_2 , V_100 , V_6 , V_102 ) ;
V_91 -> V_126 = V_64 -> V_127 ;
V_91 -> V_128 = V_6 ;
V_104 . V_91 . V_105 = V_153 ;
V_104 . V_91 . V_135 = V_64 -> V_127 ;
V_104 . V_91 . V_154 = V_6 ;
V_104 . V_91 . V_141 = V_2 -> V_141 ;
V_104 . V_91 . V_137 = ( V_91 -> V_126 << 3 ) | V_91 -> V_128 ;
F_45 ( V_2 , & V_104 ) ;
F_27 ( V_2 , V_155 ,
V_6 , ( T_1 ) ( V_91 -> V_16 . V_27 ) ) ;
memset ( & V_152 , 0 , sizeof( struct V_152 ) ) ;
V_152 . V_142 = 1 ;
V_152 . V_147 = 0 ;
V_152 . V_156 = 0 ;
V_152 . V_148 = V_157 ;
V_152 . V_158 = 0 ;
F_27 ( V_2 , V_100 , V_6 , * ( T_1 * ) & V_152 ) ;
F_27 ( V_2 , V_159 , V_6 , V_91 -> V_57 ) ;
if ( F_53 ( V_6 ) ) {
F_54 ( V_6 , & V_91 -> V_160 ) ;
F_55 ( V_2 -> V_14 ,
& V_91 -> V_160 , V_6 ) ;
}
}
static void F_56 ( struct V_1 * V_2 , struct V_63 * V_64 ,
int V_6 , bool V_56 )
{
struct V_47 * V_47 ;
struct V_161 V_161 ;
V_47 = & V_64 -> V_47 [ V_6 ] ;
F_47 ( V_2 , V_47 , V_6 ) ;
if ( ! V_56 )
return;
F_27 ( V_2 , V_162 ,
V_6 , ( T_1 ) ( V_47 -> V_16 . V_27 ) ) ;
memset ( & V_161 , 0 , sizeof( struct V_161 ) ) ;
V_161 . V_142 = 1 ;
V_161 . V_147 = 0 ;
V_161 . V_156 = 0 ;
V_161 . V_148 = V_163 ;
V_161 . V_150 = 0 ;
V_161 . V_164 = V_47 -> V_55 / 128 ;
F_27 ( V_2 , V_113 ,
V_6 , * ( T_1 * ) & V_161 ) ;
F_27 ( V_2 , V_76 ,
V_6 , V_64 -> V_73 - 1 ) ;
F_27 ( V_2 , V_165 ,
V_6 , V_47 -> V_57 - 1 ) ;
}
void F_57 ( struct V_1 * V_2 , bool V_56 )
{
union V_103 V_104 = {} ;
struct V_63 * V_64 = V_2 -> V_64 ;
struct V_166 * V_166 ;
if ( ! V_64 ) {
F_58 ( V_2 -> V_14 ,
L_3 ) ;
return;
}
V_64 -> V_56 = V_56 ;
V_64 -> V_127 = V_2 -> V_167 ;
V_104 . V_64 . V_105 = V_168 ;
V_104 . V_64 . V_169 = V_64 -> V_127 ;
V_104 . V_64 . V_121 = V_2 -> V_121 ;
V_104 . V_64 . V_137 = 0 ;
V_166 = (struct V_166 * ) & V_104 . V_64 . V_137 ;
if ( V_64 -> V_56 ) {
V_166 -> V_142 = 1 ;
#ifdef F_59
V_166 -> V_170 = 1 ;
#endif
V_166 -> V_171 = V_64 -> V_127 ;
}
F_45 ( V_2 , & V_104 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
int V_6 ;
struct V_63 * V_64 = V_2 -> V_64 ;
for ( V_6 = 0 ; V_6 < V_64 -> V_66 ; V_6 ++ )
F_24 ( V_2 , & V_64 -> V_47 [ V_6 ] ) ;
for ( V_6 = 0 ; V_6 < V_64 -> V_172 ; V_6 ++ )
F_36 ( V_2 , & V_64 -> V_84 [ V_6 ] ) ;
for ( V_6 = 0 ; V_6 < V_64 -> V_173 ; V_6 ++ )
F_41 ( V_2 , & V_64 -> V_91 [ V_6 ] ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_6 ;
struct V_63 * V_64 = V_2 -> V_64 ;
for ( V_6 = 0 ; V_6 < V_64 -> V_66 ; V_6 ++ ) {
if ( F_21 ( V_2 , & V_64 -> V_47 [ V_6 ] , V_64 -> V_73 ,
V_174 ) )
goto V_175;
}
for ( V_6 = 0 ; V_6 < V_64 -> V_173 ; V_6 ++ ) {
if ( F_37 ( V_2 , & V_64 -> V_91 [ V_6 ] , V_64 -> V_176 ) )
goto V_175;
}
for ( V_6 = 0 ; V_6 < V_64 -> V_172 ; V_6 ++ ) {
if ( F_34 ( V_2 , & V_64 -> V_84 [ V_6 ] , V_64 -> V_177 ) )
goto V_175;
}
return 0 ;
V_175:
F_60 ( V_2 ) ;
return - V_26 ;
}
int F_62 ( struct V_1 * V_2 )
{
struct V_63 * V_64 ;
V_64 = F_63 ( & V_2 -> V_22 -> V_23 , sizeof( * V_64 ) , V_25 ) ;
if ( ! V_64 )
return - V_26 ;
V_2 -> V_64 = V_64 ;
V_64 -> V_66 = V_178 ;
V_64 -> V_179 = V_180 ;
V_64 -> V_173 = V_181 ;
V_64 -> V_172 = V_182 ;
V_64 -> V_73 = V_183 ;
V_64 -> V_176 = V_184 ;
V_64 -> V_177 = V_185 ;
V_2 -> V_186 = V_64 -> V_179 ;
V_2 -> V_187 = V_64 -> V_173 ;
return 0 ;
}
int F_64 ( struct V_1 * V_2 , bool V_56 )
{
bool V_188 = false ;
struct V_63 * V_64 = V_2 -> V_64 ;
int V_6 ;
if ( ! V_64 )
return 0 ;
if ( V_56 ) {
if ( F_61 ( V_2 ) )
return - V_26 ;
for ( V_6 = 0 ; V_6 < V_64 -> V_173 ; V_6 ++ )
F_52 ( V_2 , V_64 , V_6 , V_56 ) ;
for ( V_6 = 0 ; V_6 < V_64 -> V_172 ; V_6 ++ )
F_50 ( V_2 , V_64 , V_6 , V_56 ) ;
for ( V_6 = 0 ; V_6 < V_64 -> V_66 ; V_6 ++ )
F_56 ( V_2 , V_64 , V_6 , V_56 ) ;
for ( V_6 = 0 ; V_6 < V_64 -> V_179 ; V_6 ++ )
F_49 ( V_2 , V_64 , V_6 , V_56 ) ;
} else {
for ( V_6 = 0 ; V_6 < V_64 -> V_179 ; V_6 ++ )
F_49 ( V_2 , V_64 , V_6 , V_188 ) ;
for ( V_6 = 0 ; V_6 < V_64 -> V_66 ; V_6 ++ )
F_56 ( V_2 , V_64 , V_6 , V_188 ) ;
for ( V_6 = 0 ; V_6 < V_64 -> V_173 ; V_6 ++ )
F_52 ( V_2 , V_64 , V_6 , V_188 ) ;
for ( V_6 = 0 ; V_6 < V_64 -> V_172 ; V_6 ++ )
F_50 ( V_2 , V_64 , V_6 , V_188 ) ;
F_60 ( V_2 ) ;
}
return 0 ;
}
static inline int F_65 ( struct V_90 * V_91 , int V_189 )
{
int V_190 ;
V_190 = V_91 -> V_62 ;
F_66 ( V_189 , & V_91 -> V_95 ) ;
V_91 -> V_62 += V_189 ;
V_91 -> V_62 &= ( V_91 -> V_16 . V_17 - 1 ) ;
return V_190 ;
}
void F_67 ( struct V_90 * V_91 , int V_189 )
{
F_2 ( V_189 , & V_91 -> V_95 ) ;
V_91 -> V_61 += V_189 ;
V_91 -> V_61 &= ( V_91 -> V_16 . V_17 - 1 ) ;
}
static inline int F_68 ( struct V_90 * V_91 , int V_190 )
{
V_190 ++ ;
V_190 &= ( V_91 -> V_16 . V_17 - 1 ) ;
return V_190 ;
}
void F_69 ( struct V_1 * V_2 , struct V_90 * V_91 , int V_6 )
{
T_1 V_152 ;
V_152 = F_4 ( V_2 , V_100 , V_6 ) ;
V_152 |= V_191 ;
F_27 ( V_2 , V_100 , V_6 , V_152 ) ;
F_27 ( V_2 , V_192 , V_6 , 0 ) ;
}
void F_70 ( struct V_1 * V_2 , int V_6 )
{
T_1 V_152 ;
V_152 = F_4 ( V_2 , V_100 , V_6 ) ;
V_152 &= ~ V_191 ;
F_27 ( V_2 , V_100 , V_6 , V_152 ) ;
}
void F_71 ( struct V_193 * V_14 , struct V_90 * V_91 ,
int V_6 )
{
T_1 V_61 , V_62 ;
struct V_41 * V_45 ;
struct V_1 * V_2 = F_72 ( V_14 ) ;
struct V_194 * V_195 ;
V_61 = F_4 ( V_2 , V_196 , V_6 ) >> 4 ;
V_62 = F_4 ( V_2 , V_197 , V_6 ) >> 4 ;
while ( V_91 -> V_61 != V_61 ) {
V_195 = (struct V_194 * ) F_73 ( V_91 , V_91 -> V_61 ) ;
if ( V_195 -> V_198 != V_199 ) {
F_67 ( V_91 , 1 ) ;
continue;
}
V_45 = (struct V_41 * ) V_91 -> V_94 [ V_91 -> V_61 ] ;
if ( V_45 )
F_74 ( V_45 ) ;
F_75 ( 1 , ( V_200 * ) & V_14 -> V_201 . V_202 ) ;
F_75 ( V_195 -> V_203 ,
( V_200 * ) & V_14 -> V_201 . V_204 ) ;
F_67 ( V_91 , V_195 -> V_205 + 1 ) ;
}
}
static int F_76 ( struct V_41 * V_45 )
{
struct V_206 * V_207 = F_77 ( V_45 ) ;
unsigned int V_208 = F_78 ( V_45 ) + F_79 ( V_45 ) ;
unsigned int V_209 = V_45 -> V_43 - V_208 ;
unsigned int V_210 = V_207 -> V_211 ;
long V_212 = - 1 ;
long V_213 = F_80 ( V_45 ) - V_208 ;
long V_214 = 0 ;
long V_215 ;
int V_216 = 0 ;
int V_217 ;
for ( V_217 = 0 ; V_217 < V_207 -> V_218 ; V_217 ++ ) {
unsigned int V_219 = 0 ;
for ( V_216 ++ ; V_219 < V_210 ; V_216 ++ ) {
while ( V_214 >= V_213 ) {
V_212 ++ ;
V_213 = F_81 ( & V_207 -> V_220 [ V_212 ] ) ;
V_214 = 0 ;
}
V_215 = V_210 - V_219 ;
if ( V_215 > V_213 - V_214 )
V_215 = V_213 - V_214 ;
V_214 += V_215 ;
V_219 += V_215 ;
}
V_209 -= V_210 ;
if ( V_209 < V_210 )
V_210 = V_209 ;
}
return V_216 + V_207 -> V_218 ;
}
static int F_82 ( struct V_1 * V_2 , struct V_41 * V_45 )
{
int V_205 = V_221 ;
if ( F_77 ( V_45 ) -> V_211 && ! V_2 -> V_222 ) {
V_205 = F_76 ( V_45 ) ;
return V_205 ;
}
if ( F_77 ( V_45 ) -> V_223 )
V_205 += F_77 ( V_45 ) -> V_223 ;
return V_205 ;
}
static inline void
F_83 ( struct V_1 * V_2 , struct V_90 * V_91 , int V_190 ,
int V_205 , struct V_41 * V_45 , int V_43 )
{
int V_224 ;
struct V_194 * V_195 ;
V_195 = (struct V_194 * ) F_73 ( V_91 , V_190 ) ;
V_91 -> V_94 [ V_190 ] = ( T_1 ) V_45 ;
memset ( V_195 , 0 , V_92 ) ;
V_195 -> V_198 = V_199 ;
V_195 -> V_225 = 1 ;
V_195 -> V_205 = V_205 ;
V_195 -> V_203 = V_43 ;
if ( V_45 -> V_226 == V_227 ) {
V_195 -> V_228 = 1 ;
V_195 -> V_229 = F_84 ( V_45 ) ;
V_195 -> V_230 = F_78 ( V_45 ) ;
V_224 = F_85 ( V_45 ) -> V_231 ;
switch ( V_224 ) {
case V_232 :
V_195 -> V_233 = V_234 ;
break;
case V_235 :
V_195 -> V_233 = V_236 ;
break;
case V_237 :
V_195 -> V_233 = V_238 ;
break;
}
}
if ( V_2 -> V_222 && F_77 ( V_45 ) -> V_211 ) {
V_195 -> V_239 = 1 ;
V_195 -> V_240 = F_78 ( V_45 ) + F_79 ( V_45 ) ;
V_195 -> V_241 = F_77 ( V_45 ) -> V_211 ;
V_195 -> V_242 = F_84 ( V_45 ) - 2 ;
V_2 -> V_39 . V_243 ++ ;
}
}
static inline void F_86 ( struct V_90 * V_91 , int V_190 ,
int V_20 , T_1 V_44 )
{
struct V_244 * V_245 ;
V_190 &= ( V_91 -> V_16 . V_17 - 1 ) ;
V_245 = (struct V_244 * ) F_73 ( V_91 , V_190 ) ;
memset ( V_245 , 0 , V_92 ) ;
V_245 -> V_198 = V_246 ;
V_245 -> V_247 = V_248 ;
V_245 -> V_20 = V_20 ;
V_245 -> V_249 = V_44 ;
}
static int F_87 ( struct V_1 * V_2 , struct V_90 * V_91 ,
int V_154 , int V_190 , struct V_41 * V_45 )
{
struct V_250 V_239 ;
int V_251 = 0 , V_189 = 0 ;
int V_252 , V_253 , V_254 ;
int V_255 = V_190 ;
int V_256 = F_78 ( V_45 ) + F_79 ( V_45 ) ;
V_240 ( V_45 , & V_239 ) ;
V_253 = V_45 -> V_43 - V_256 ;
while ( V_253 > 0 ) {
char * V_195 ;
V_255 = V_190 ;
V_254 = F_88 ( int , F_77 ( V_45 ) -> V_211 , V_253 ) ;
V_253 -= V_254 ;
V_190 = F_68 ( V_91 , V_190 ) ;
V_195 = V_91 -> V_97 + V_190 * V_98 ;
F_89 ( V_45 , V_195 , & V_239 , V_254 , V_253 == 0 ) ;
F_86 ( V_91 , V_190 , V_256 ,
V_91 -> V_99 +
V_190 * V_98 ) ;
V_251 = 2 ;
V_252 = V_256 ;
while ( V_254 > 0 ) {
int V_20 ;
V_20 = F_88 ( int , V_239 . V_20 , V_254 ) ;
V_190 = F_68 ( V_91 , V_190 ) ;
F_86 ( V_91 , V_190 , V_20 ,
F_23 ( V_239 . V_44 ) ) ;
V_251 ++ ;
V_252 += V_20 ;
V_254 -= V_20 ;
F_90 ( V_45 , & V_239 , V_20 ) ;
}
F_83 ( V_2 , V_91 , V_255 ,
V_251 - 1 , V_45 , V_252 ) ;
V_91 -> V_94 [ V_255 ] = ( T_1 ) NULL ;
V_190 = F_68 ( V_91 , V_190 ) ;
V_189 += V_251 ;
}
V_91 -> V_94 [ V_255 ] = ( T_1 ) V_45 ;
F_26 () ;
F_27 ( V_2 , V_192 ,
V_154 , V_189 ) ;
V_2 -> V_39 . V_243 ++ ;
return 1 ;
}
int F_91 ( struct V_1 * V_2 , struct V_41 * V_45 )
{
int V_257 , V_20 ;
int V_205 ;
int V_154 , V_190 ;
struct V_63 * V_64 ;
struct V_90 * V_91 ;
V_154 = F_92 ( V_45 ) ;
if ( V_154 >= V_258 ) {
V_257 = V_154 / V_258 ;
if ( ! V_2 -> V_122 [ V_257 - 1 ] ) {
F_58 ( V_2 -> V_14 ,
L_4 ,
V_257 - 1 ) ;
return 1 ;
}
V_2 = (struct V_1 * ) V_2 -> V_122 [ V_257 - 1 ] ;
V_154 = V_154 % V_258 ;
}
V_64 = V_2 -> V_64 ;
V_91 = & V_64 -> V_91 [ V_154 ] ;
V_205 = F_82 ( V_2 , V_45 ) ;
if ( V_205 > F_93 ( & V_91 -> V_95 ) )
goto V_259;
V_190 = F_65 ( V_91 , V_205 ) ;
if ( F_77 ( V_45 ) -> V_211 && ! V_2 -> V_222 )
return F_87 ( V_2 , V_91 , V_154 , V_190 , V_45 ) ;
F_83 ( V_2 , V_91 , V_190 , V_205 - 1 ,
V_45 , V_45 -> V_43 ) ;
V_190 = F_68 ( V_91 , V_190 ) ;
V_20 = F_94 ( V_45 ) ? F_80 ( V_45 ) : V_45 -> V_43 ;
F_86 ( V_91 , V_190 , V_20 , F_23 ( V_45 -> V_44 ) ) ;
if ( ! F_94 ( V_45 ) )
goto V_260;
for ( V_257 = 0 ; V_257 < F_77 ( V_45 ) -> V_223 ; V_257 ++ ) {
const struct V_261 * V_262 ;
V_262 = & F_77 ( V_45 ) -> V_220 [ V_257 ] ;
V_190 = F_68 ( V_91 , V_190 ) ;
V_20 = F_81 ( V_262 ) ;
F_86 ( V_91 , V_190 , V_20 ,
F_23 (
F_95 ( V_262 ) ) ) ;
}
V_260:
F_26 () ;
F_27 ( V_2 , V_192 ,
V_154 , V_205 ) ;
return 1 ;
V_259:
V_2 = V_2 -> V_263 ;
F_96 ( V_2 -> V_14 , L_5 ) ;
return 0 ;
}
static inline unsigned F_97 ( unsigned V_257 )
{
#ifdef F_59
return ( V_257 & ~ 3 ) + 3 - ( V_257 & 3 ) ;
#else
return V_257 ;
#endif
}
struct V_41 * F_98 ( struct V_1 * V_2 , struct V_264 * V_265 )
{
int V_262 ;
int V_266 = 0 ;
struct V_41 * V_45 = NULL ;
struct V_41 * V_267 = NULL ;
struct V_41 * V_268 = NULL ;
T_5 * V_269 = NULL ;
T_1 * V_270 = NULL ;
V_269 = ( void * ) V_265 + ( 3 * sizeof( T_1 ) ) ;
V_270 = ( void * ) V_265 + ( 6 * sizeof( T_1 ) ) ;
F_96 ( V_2 -> V_14 , L_6 ,
V_271 , V_265 -> V_272 , V_265 -> V_273 , V_265 -> V_274 ) ;
for ( V_262 = 0 ; V_262 < V_265 -> V_272 ; V_262 ++ ) {
V_266 = V_269 [ F_97 ( V_262 ) ] ;
if ( ! V_262 ) {
V_45 = F_15 ( V_2 ,
* V_270 - V_265 -> V_275 ,
V_266 ) ;
if ( ! V_45 )
return NULL ;
F_99 ( V_45 , V_265 -> V_275 ) ;
F_100 ( V_45 , V_266 ) ;
} else {
V_267 = F_15 ( V_2 , * V_270 ,
V_266 ) ;
if ( ! V_267 ) {
F_101 ( V_45 ) ;
return NULL ;
}
if ( ! F_77 ( V_45 ) -> V_276 )
F_77 ( V_45 ) -> V_276 = V_267 ;
else
V_268 -> V_277 = V_267 ;
V_268 = V_267 ;
V_45 -> V_43 += V_266 ;
V_45 -> V_209 += V_266 ;
V_267 -> V_43 = V_266 ;
}
V_270 ++ ;
}
return V_45 ;
}
static T_1 F_102 ( int V_278 , int V_279 )
{
T_1 V_12 ;
switch ( V_278 ) {
case V_280 :
V_12 = ( ( 1ULL << V_279 ) << V_281 ) ;
break;
case V_282 :
V_12 = ( ( 1ULL << V_279 ) << V_283 ) ;
break;
case V_77 :
V_12 = ( ( 1ULL << V_279 ) << V_284 ) ;
break;
case V_285 :
V_12 = ( 1ULL << V_286 ) ;
break;
case V_287 :
V_12 = ( 1ULL << V_288 ) ;
break;
case V_289 :
V_12 = ( 1ULL << V_290 ) ;
break;
case V_291 :
V_12 = ( 1ULL << V_292 ) ;
break;
default:
V_12 = 0 ;
}
return V_12 ;
}
void F_28 ( struct V_1 * V_2 , int V_278 , int V_279 )
{
T_1 V_293 = F_102 ( V_278 , V_279 ) ;
if ( ! V_293 ) {
F_96 ( V_2 -> V_14 ,
L_7 ) ;
return;
}
F_103 ( V_2 , V_294 ,
F_104 ( V_2 , V_294 ) | V_293 ) ;
}
void F_105 ( struct V_1 * V_2 , int V_278 , int V_279 )
{
T_1 V_293 = F_102 ( V_278 , V_279 ) ;
if ( ! V_293 ) {
F_96 ( V_2 -> V_14 ,
L_8 ) ;
return;
}
F_103 ( V_2 , V_295 , V_293 ) ;
}
void F_106 ( struct V_1 * V_2 , int V_278 , int V_279 )
{
T_1 V_293 = F_102 ( V_278 , V_279 ) ;
if ( ! V_293 ) {
F_96 ( V_2 -> V_14 ,
L_9 ) ;
return;
}
F_103 ( V_2 , V_296 , V_293 ) ;
}
int F_107 ( struct V_1 * V_2 , int V_278 , int V_279 )
{
T_1 V_293 = F_102 ( V_278 , V_279 ) ;
if ( ! V_293 ) {
F_96 ( V_2 -> V_14 ,
L_10 ) ;
return 0 ;
}
return V_293 & F_104 ( V_2 , V_294 ) ;
}
void F_108 ( struct V_1 * V_2 , int V_297 )
{
struct V_123 * V_124 ;
#define F_109 ( V_7 ) \
nicvf_reg_read(nic, NIC_QSET_RQ_0_7_STAT_0_1 |\
(rq_idx << NIC_Q_NUM_SHIFT) | (reg << 3))
V_124 = & V_2 -> V_64 -> V_124 [ V_297 ] ;
V_124 -> V_201 . V_298 = F_109 ( V_299 ) ;
V_124 -> V_201 . V_300 = F_109 ( V_301 ) ;
}
void F_110 ( struct V_1 * V_2 , int V_302 )
{
struct V_90 * V_91 ;
#define F_111 ( V_7 ) \
nicvf_reg_read(nic, NIC_QSET_SQ_0_7_STAT_0_1 |\
(sq_idx << NIC_Q_NUM_SHIFT) | (reg << 3))
V_91 = & V_2 -> V_64 -> V_91 [ V_302 ] ;
V_91 -> V_201 . V_298 = F_111 ( V_299 ) ;
V_91 -> V_201 . V_300 = F_111 ( V_301 ) ;
}
int F_112 ( struct V_1 * V_2 , struct V_264 * V_265 )
{
struct V_303 * V_201 = & V_2 -> V_304 ;
if ( ! V_265 -> V_305 && ! V_265 -> V_306 )
return 0 ;
if ( F_113 ( V_2 ) )
F_6 ( V_2 -> V_14 ,
L_11 ,
V_2 -> V_14 -> V_307 ,
V_265 -> V_305 , V_265 -> V_306 ) ;
switch ( V_265 -> V_306 ) {
case V_308 :
V_201 -> V_309 ++ ;
break;
case V_310 :
V_201 -> V_311 ++ ;
break;
case V_312 :
V_201 -> V_313 ++ ;
break;
case V_314 :
V_201 -> V_315 ++ ;
break;
case V_316 :
V_201 -> V_317 ++ ;
break;
case V_318 :
V_201 -> V_319 ++ ;
break;
case V_320 :
V_201 -> V_321 ++ ;
break;
case V_322 :
V_201 -> V_323 ++ ;
break;
case V_324 :
V_201 -> V_325 ++ ;
break;
case V_326 :
V_201 -> V_327 ++ ;
break;
case V_328 :
V_201 -> V_329 ++ ;
break;
case V_330 :
V_201 -> V_331 ++ ;
break;
case V_332 :
V_201 -> V_333 ++ ;
break;
case V_334 :
V_201 -> V_335 ++ ;
break;
case V_336 :
V_201 -> V_337 ++ ;
break;
case V_338 :
V_201 -> V_339 ++ ;
break;
case V_340 :
V_201 -> V_341 ++ ;
break;
case V_342 :
V_201 -> V_343 ++ ;
break;
case V_344 :
V_201 -> V_345 ++ ;
break;
case V_346 :
V_201 -> V_347 ++ ;
break;
case V_348 :
V_201 -> V_349 ++ ;
break;
case V_350 :
V_201 -> V_351 ++ ;
break;
case V_352 :
V_201 -> V_353 ++ ;
break;
case V_354 :
V_201 -> V_355 ++ ;
break;
}
return 1 ;
}
int F_114 ( struct V_1 * V_2 ,
struct V_83 * V_84 , struct V_356 * V_357 )
{
struct V_358 * V_201 = & V_84 -> V_201 ;
switch ( V_357 -> V_359 ) {
case V_360 :
V_201 -> V_361 . V_362 ++ ;
return 0 ;
case V_363 :
V_201 -> V_361 . V_364 ++ ;
break;
case V_365 :
V_201 -> V_361 . V_366 ++ ;
break;
case V_367 :
V_201 -> V_361 . V_368 ++ ;
break;
case V_369 :
V_201 -> V_361 . V_370 ++ ;
break;
case V_371 :
V_201 -> V_361 . V_372 ++ ;
break;
case V_373 :
V_201 -> V_361 . V_374 ++ ;
break;
case V_375 :
V_201 -> V_361 . V_376 ++ ;
break;
case V_377 :
V_201 -> V_361 . V_378 ++ ;
break;
case V_379 :
V_201 -> V_361 . V_380 ++ ;
break;
case V_381 :
V_201 -> V_361 . V_382 ++ ;
break;
case V_383 :
V_201 -> V_361 . V_384 ++ ;
break;
case V_385 :
V_201 -> V_361 . V_386 ++ ;
break;
case V_387 :
V_201 -> V_361 . V_388 ++ ;
break;
}
return 1 ;
}

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
int V_29 = F_11 ( V_27 ) ;
if ( V_2 -> V_30 ) {
if ( ( V_2 -> V_31 + V_27 + V_27 ) >
( V_32 << V_29 ) ) {
V_2 -> V_30 = NULL ;
} else {
V_2 -> V_31 += V_27 ;
F_12 ( V_2 -> V_30 ) ;
}
}
if ( ! V_2 -> V_30 ) {
V_2 -> V_30 = F_13 ( V_26 | V_33 | V_34 ,
V_29 ) ;
if ( ! V_2 -> V_30 ) {
F_4 ( V_2 -> V_11 ,
L_2 ) ;
return - V_23 ;
}
V_2 -> V_31 = 0 ;
}
* V_28 = ( T_1 * ) ( ( T_1 ) F_14 ( V_2 -> V_30 ) + V_2 -> V_31 ) ;
return 0 ;
}
static struct V_35 * F_15 ( struct V_1 * V_2 ,
T_1 V_36 , int V_37 )
{
void * V_38 ;
struct V_35 * V_39 ;
V_38 = F_16 ( V_36 ) ;
V_39 = F_17 ( V_38 , V_40 ) ;
if ( ! V_39 ) {
F_18 ( F_19 ( V_38 ) ) ;
return NULL ;
}
F_20 ( V_39 -> V_38 ) ;
return V_39 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_41 * V_41 ,
int V_42 , int V_43 )
{
int V_44 ;
T_1 * V_28 ;
struct V_45 * V_46 ;
int V_47 ;
V_47 = F_5 ( V_2 , & V_41 -> V_13 , V_42 ,
sizeof( struct V_45 ) ,
V_48 ) ;
if ( V_47 )
return V_47 ;
V_41 -> V_46 = V_41 -> V_13 . V_25 ;
V_41 -> V_49 = V_43 ;
V_41 -> V_50 = true ;
V_41 -> V_51 = V_52 ;
V_2 -> V_30 = NULL ;
for ( V_44 = 0 ; V_44 < V_42 ; V_44 ++ ) {
V_47 = F_10 ( V_2 , V_22 , V_40 ,
& V_28 ) ;
if ( V_47 )
return V_47 ;
V_46 = F_22 ( V_41 , V_44 ) ;
V_46 -> V_53 = F_23 ( V_28 ) >> V_54 ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 , struct V_41 * V_41 )
{
int V_55 , V_56 ;
T_1 V_53 ;
struct V_45 * V_46 ;
if ( ! V_41 )
return;
V_41 -> V_50 = false ;
if ( ! V_41 -> V_13 . V_25 )
return;
V_55 = V_41 -> V_55 ;
V_56 = V_41 -> V_56 ;
while ( V_55 != V_56 ) {
V_46 = F_22 ( V_41 , V_55 ) ;
V_53 = V_46 -> V_53 << V_54 ;
F_18 ( F_19 ( F_16 ( V_53 ) ) ) ;
V_55 ++ ;
V_55 &= ( V_41 -> V_13 . V_14 - 1 ) ;
}
V_46 = F_22 ( V_41 , V_56 ) ;
V_53 = V_46 -> V_53 << V_54 ;
F_18 ( F_19 ( F_16 ( V_53 ) ) ) ;
F_8 ( V_2 , & V_41 -> V_13 ) ;
}
static void F_25 ( struct V_1 * V_2 , T_2 V_26 )
{
struct V_57 * V_58 = V_2 -> V_58 ;
int V_59 = V_58 -> V_60 ;
int V_56 , V_61 ;
int V_62 ;
struct V_41 * V_41 ;
struct V_45 * V_46 ;
T_1 * V_28 ;
int V_63 = 0 ;
V_64:
if ( ! V_59 )
return;
V_59 -- ;
V_41 = & V_58 -> V_41 [ V_59 ] ;
if ( ! V_41 -> V_50 )
goto V_65;
V_61 = F_2 ( V_2 , V_66 , V_59 ) ;
V_61 &= 0x7FFFF ;
if ( V_61 >= ( V_58 -> V_67 - 1 ) )
goto V_65;
else
V_62 = V_58 -> V_67 - V_61 - 1 ;
V_56 = F_2 ( V_2 , V_68 , V_59 ) >> 3 ;
while ( V_62 ) {
V_56 ++ ;
V_56 &= ( V_41 -> V_13 . V_14 - 1 ) ;
if ( F_10 ( V_2 , V_26 , V_40 , & V_28 ) )
break;
V_46 = F_22 ( V_41 , V_56 ) ;
V_46 -> V_53 = F_23 ( V_28 ) >> V_54 ;
V_62 -- ;
V_63 ++ ;
}
F_26 () ;
if ( V_62 )
V_2 -> V_69 = true ;
else
V_2 -> V_69 = false ;
F_27 ( V_2 , V_70 ,
V_59 , V_63 ) ;
V_65:
if ( ! V_2 -> V_69 && V_41 -> V_50 )
F_28 ( V_2 , V_71 , V_59 ) ;
if ( V_59 )
goto V_64;
}
void F_29 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = F_30 ( V_73 , struct V_1 , V_74 . V_73 ) ;
F_25 ( V_2 , V_22 ) ;
if ( V_2 -> V_69 )
F_31 ( & V_2 -> V_74 , F_32 ( 10 ) ) ;
else
V_2 -> V_75 = false ;
}
void F_33 ( unsigned long V_38 )
{
struct V_1 * V_2 = (struct V_1 * ) V_38 ;
F_25 ( V_2 , V_76 ) ;
if ( V_2 -> V_69 ) {
V_2 -> V_75 = true ;
F_31 ( & V_2 -> V_74 , F_32 ( 10 ) ) ;
}
}
static int F_34 ( struct V_1 * V_2 ,
struct V_77 * V_78 , int V_14 )
{
int V_47 ;
V_47 = F_5 ( V_2 , & V_78 -> V_13 , V_14 , V_79 ,
V_80 ) ;
if ( V_47 )
return V_47 ;
V_78 -> V_46 = V_78 -> V_13 . V_25 ;
V_78 -> V_51 = F_35 ( V_2 -> V_19 ) ? 0 : V_81 ;
V_2 -> V_82 = ( V_83 * 0.05 ) - 1 ;
return 0 ;
}
static void F_36 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
if ( ! V_78 )
return;
if ( ! V_78 -> V_13 . V_25 )
return;
F_8 ( V_2 , & V_78 -> V_13 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_84 * V_85 , int V_14 )
{
int V_47 ;
V_47 = F_5 ( V_2 , & V_85 -> V_13 , V_14 , V_86 ,
V_87 ) ;
if ( V_47 )
return V_47 ;
V_85 -> V_46 = V_85 -> V_13 . V_25 ;
V_85 -> V_88 = F_38 ( V_14 , sizeof( T_1 ) , V_22 ) ;
if ( ! V_85 -> V_88 )
return - V_23 ;
V_85 -> V_55 = 0 ;
V_85 -> V_56 = 0 ;
F_39 ( & V_85 -> V_89 , V_14 - 1 ) ;
V_85 -> V_51 = V_90 ;
V_85 -> V_91 = F_40 ( & V_2 -> V_19 -> V_20 ,
V_14 * V_92 ,
& V_85 -> V_93 , V_22 ) ;
if ( ! V_85 -> V_91 )
return - V_23 ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 , struct V_84 * V_85 )
{
if ( ! V_85 )
return;
if ( ! V_85 -> V_13 . V_25 )
return;
if ( V_85 -> V_91 )
F_9 ( & V_2 -> V_19 -> V_20 ,
V_85 -> V_13 . V_14 * V_92 ,
V_85 -> V_91 , V_85 -> V_93 ) ;
F_42 ( V_85 -> V_88 ) ;
F_8 ( V_2 , & V_85 -> V_13 ) ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_57 * V_58 , int V_3 )
{
F_27 ( V_2 , V_94 , V_3 , 0 ) ;
if ( F_1 ( V_2 , V_3 , V_95 , 21 , 1 , 0x01 ) )
return;
F_27 ( V_2 , V_94 , V_3 , V_96 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_57 * V_58 , int V_3 )
{
union V_97 V_98 = {} ;
V_98 . V_99 . V_99 = V_100 ;
F_45 ( V_2 , & V_98 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_57 * V_58 , int V_3 )
{
F_27 ( V_2 , V_101 , V_3 , 0 ) ;
F_27 ( V_2 , V_102 , V_3 , 0 ) ;
F_27 ( V_2 , V_102 , V_3 , V_103 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_41 * V_41 , int V_3 )
{
T_1 V_104 , V_105 ;
int V_10 = 10 ;
V_41 -> V_55 = F_2 ( V_2 ,
V_106 ,
V_3 ) >> 3 ;
V_41 -> V_56 = F_2 ( V_2 ,
V_68 ,
V_3 ) >> 3 ;
V_105 = F_2 ( V_2 , V_66 , V_3 ) ;
if ( ( ( V_105 >> 62 ) & 0x03 ) == 0x3 )
F_27 ( V_2 , V_107 ,
V_3 , V_108 ) ;
F_27 ( V_2 , V_107 , V_3 , 0 ) ;
if ( F_1 ( V_2 , V_3 , V_66 , 62 , 2 , 0x00 ) )
return;
while ( 1 ) {
V_104 = F_2 ( V_2 ,
V_109 ,
V_3 ) ;
if ( ( V_104 & 0xFFFFFFFF ) == ( ( V_104 >> 32 ) & 0xFFFFFFFF ) )
break;
F_3 ( 1000 , 2000 ) ;
V_10 -- ;
if ( ! V_10 ) {
F_4 ( V_2 -> V_11 ,
L_3 ) ;
return;
}
}
F_27 ( V_2 , V_107 ,
V_3 , V_108 ) ;
if ( F_1 ( V_2 , V_3 , V_66 , 62 , 2 , 0x02 ) )
return;
F_27 ( V_2 , V_107 , V_3 , 0x00 ) ;
if ( F_1 ( V_2 , V_3 , V_66 , 62 , 2 , 0x00 ) )
return;
}
void F_48 ( struct V_1 * V_2 , T_4 V_110 )
{
T_1 V_111 ;
int V_112 ;
V_111 = F_2 ( V_2 , V_113 , 0 ) ;
if ( V_110 & V_114 )
V_111 |= ( 1ULL << 25 ) ;
else
V_111 &= ~ ( 1ULL << 25 ) ;
F_27 ( V_2 , V_113 , 0 , V_111 ) ;
for ( V_112 = 0 ; V_112 < V_2 -> V_115 ; V_112 ++ )
if ( V_2 -> V_116 [ V_112 ] )
F_27 ( V_2 -> V_116 [ V_112 ] ,
V_113 , 0 , V_111 ) ;
}
static void F_49 ( struct V_1 * V_2 , struct V_57 * V_58 ,
int V_3 , bool V_50 )
{
union V_97 V_98 = {} ;
struct V_117 * V_118 ;
struct V_111 V_111 ;
V_118 = & V_58 -> V_118 [ V_3 ] ;
V_118 -> V_50 = V_50 ;
F_27 ( V_2 , V_119 , V_3 , 0 ) ;
if ( ! V_118 -> V_50 ) {
F_44 ( V_2 , V_58 , V_3 ) ;
return;
}
V_118 -> V_120 = V_58 -> V_121 ;
V_118 -> V_122 = V_3 ;
V_118 -> V_123 = V_58 -> V_121 ;
V_118 -> V_124 = V_58 -> V_60 - 1 ;
V_118 -> V_125 = V_58 -> V_121 ;
V_118 -> V_126 = V_58 -> V_60 - 1 ;
V_118 -> V_127 = 1 ;
V_98 . V_118 . V_99 = V_128 ;
V_98 . V_118 . V_129 = V_58 -> V_121 ;
V_98 . V_118 . V_130 = V_3 ;
V_98 . V_118 . V_131 = ( V_118 -> V_127 << 26 ) | ( V_118 -> V_120 << 19 ) |
( V_118 -> V_122 << 16 ) | ( V_118 -> V_125 << 9 ) |
( V_118 -> V_126 << 8 ) |
( V_118 -> V_123 << 1 ) | ( V_118 -> V_124 ) ;
F_45 ( V_2 , & V_98 ) ;
V_98 . V_118 . V_99 = V_132 ;
V_98 . V_118 . V_131 = ( 1ULL << 63 ) | ( 1ULL << 62 ) | ( V_58 -> V_121 << 0 ) ;
F_45 ( V_2 , & V_98 ) ;
V_98 . V_118 . V_99 = V_133 ;
V_98 . V_118 . V_131 = ( 1ULL << 62 ) | ( V_134 << 8 ) ;
F_45 ( V_2 , & V_98 ) ;
F_27 ( V_2 , V_113 , 0 , 0x00 ) ;
if ( ! V_2 -> V_135 )
F_48 ( V_2 , V_2 -> V_11 -> V_110 ) ;
V_111 . V_136 = 1 ;
V_111 . V_137 = 0 ;
F_27 ( V_2 , V_119 , V_3 , * ( T_1 * ) & V_111 ) ;
}
void F_50 ( struct V_1 * V_2 , struct V_57 * V_58 ,
int V_3 , bool V_50 )
{
struct V_77 * V_78 ;
struct V_138 V_138 ;
V_78 = & V_58 -> V_78 [ V_3 ] ;
V_78 -> V_50 = V_50 ;
if ( ! V_78 -> V_50 ) {
F_46 ( V_2 , V_58 , V_3 ) ;
return;
}
F_27 ( V_2 , V_102 , V_3 , V_103 ) ;
if ( ! V_78 -> V_50 )
return;
F_51 ( & V_78 -> V_139 ) ;
F_27 ( V_2 , V_140 ,
V_3 , ( T_1 ) ( V_78 -> V_13 . V_24 ) ) ;
V_138 . V_136 = 1 ;
V_138 . V_141 = 0 ;
V_138 . V_127 = 0 ;
V_138 . V_142 = V_143 ;
V_138 . V_144 = 0 ;
F_27 ( V_2 , V_102 , V_3 , * ( T_1 * ) & V_138 ) ;
F_27 ( V_2 , V_145 , V_3 , V_78 -> V_51 ) ;
F_27 ( V_2 , V_101 ,
V_3 , V_83 ) ;
}
static void F_52 ( struct V_1 * V_2 , struct V_57 * V_58 ,
int V_3 , bool V_50 )
{
union V_97 V_98 = {} ;
struct V_84 * V_85 ;
struct V_146 V_146 ;
V_85 = & V_58 -> V_85 [ V_3 ] ;
V_85 -> V_50 = V_50 ;
if ( ! V_85 -> V_50 ) {
F_43 ( V_2 , V_58 , V_3 ) ;
return;
}
F_27 ( V_2 , V_94 , V_3 , V_96 ) ;
V_85 -> V_120 = V_58 -> V_121 ;
V_85 -> V_122 = V_3 ;
V_98 . V_85 . V_99 = V_147 ;
V_98 . V_85 . V_129 = V_58 -> V_121 ;
V_98 . V_85 . V_148 = V_3 ;
V_98 . V_85 . V_135 = V_2 -> V_135 ;
V_98 . V_85 . V_131 = ( V_85 -> V_120 << 3 ) | V_85 -> V_122 ;
F_45 ( V_2 , & V_98 ) ;
F_27 ( V_2 , V_149 ,
V_3 , ( T_1 ) ( V_85 -> V_13 . V_24 ) ) ;
V_146 . V_136 = 1 ;
V_146 . V_141 = 0 ;
V_146 . V_150 = 0 ;
V_146 . V_142 = V_151 ;
V_146 . V_152 = 0 ;
F_27 ( V_2 , V_94 , V_3 , * ( T_1 * ) & V_146 ) ;
F_27 ( V_2 , V_153 , V_3 , V_85 -> V_51 ) ;
if ( F_53 ( V_3 ) ) {
F_54 ( V_3 , & V_85 -> V_154 ) ;
F_55 ( V_2 -> V_11 ,
& V_85 -> V_154 , V_3 ) ;
}
}
static void F_56 ( struct V_1 * V_2 , struct V_57 * V_58 ,
int V_3 , bool V_50 )
{
struct V_41 * V_41 ;
struct V_155 V_155 ;
V_41 = & V_58 -> V_41 [ V_3 ] ;
F_47 ( V_2 , V_41 , V_3 ) ;
if ( ! V_50 )
return;
F_27 ( V_2 , V_156 ,
V_3 , ( T_1 ) ( V_41 -> V_13 . V_24 ) ) ;
V_155 . V_136 = 1 ;
V_155 . V_141 = 0 ;
V_155 . V_150 = 0 ;
V_155 . V_142 = V_157 ;
V_155 . V_144 = 0 ;
V_155 . V_158 = V_41 -> V_49 / 128 ;
F_27 ( V_2 , V_107 ,
V_3 , * ( T_1 * ) & V_155 ) ;
F_27 ( V_2 , V_70 ,
V_3 , V_58 -> V_67 - 1 ) ;
F_27 ( V_2 , V_159 ,
V_3 , V_41 -> V_51 - 1 ) ;
}
void F_57 ( struct V_1 * V_2 , bool V_50 )
{
union V_97 V_98 = {} ;
struct V_57 * V_58 = V_2 -> V_58 ;
struct V_160 * V_160 ;
if ( ! V_58 ) {
F_58 ( V_2 -> V_11 ,
L_4 ) ;
return;
}
V_58 -> V_50 = V_50 ;
V_58 -> V_121 = V_2 -> V_161 ;
V_98 . V_58 . V_99 = V_162 ;
V_98 . V_58 . V_163 = V_58 -> V_121 ;
V_98 . V_58 . V_115 = V_2 -> V_115 ;
V_98 . V_58 . V_131 = 0 ;
V_160 = (struct V_160 * ) & V_98 . V_58 . V_131 ;
if ( V_58 -> V_50 ) {
V_160 -> V_136 = 1 ;
#ifdef F_59
V_160 -> V_164 = 1 ;
#endif
V_160 -> V_165 = V_58 -> V_121 ;
}
F_45 ( V_2 , & V_98 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_57 * V_58 = V_2 -> V_58 ;
for ( V_3 = 0 ; V_3 < V_58 -> V_60 ; V_3 ++ )
F_24 ( V_2 , & V_58 -> V_41 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < V_58 -> V_166 ; V_3 ++ )
F_36 ( V_2 , & V_58 -> V_78 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < V_58 -> V_167 ; V_3 ++ )
F_41 ( V_2 , & V_58 -> V_85 [ V_3 ] ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_57 * V_58 = V_2 -> V_58 ;
for ( V_3 = 0 ; V_3 < V_58 -> V_60 ; V_3 ++ ) {
if ( F_21 ( V_2 , & V_58 -> V_41 [ V_3 ] , V_58 -> V_67 ,
V_168 ) )
goto V_169;
}
for ( V_3 = 0 ; V_3 < V_58 -> V_167 ; V_3 ++ ) {
if ( F_37 ( V_2 , & V_58 -> V_85 [ V_3 ] , V_58 -> V_170 ) )
goto V_169;
}
for ( V_3 = 0 ; V_3 < V_58 -> V_166 ; V_3 ++ ) {
if ( F_34 ( V_2 , & V_58 -> V_78 [ V_3 ] , V_58 -> V_171 ) )
goto V_169;
}
return 0 ;
V_169:
F_60 ( V_2 ) ;
return - V_23 ;
}
int F_62 ( struct V_1 * V_2 )
{
struct V_57 * V_58 ;
V_58 = F_63 ( & V_2 -> V_19 -> V_20 , sizeof( * V_58 ) , V_22 ) ;
if ( ! V_58 )
return - V_23 ;
V_2 -> V_58 = V_58 ;
V_58 -> V_60 = V_172 ;
V_58 -> V_173 = V_174 ;
V_58 -> V_167 = V_175 ;
V_58 -> V_166 = V_176 ;
V_58 -> V_67 = V_177 ;
V_58 -> V_170 = V_178 ;
V_58 -> V_171 = V_179 ;
V_2 -> V_180 = V_58 -> V_173 ;
V_2 -> V_181 = V_58 -> V_167 ;
return 0 ;
}
int F_64 ( struct V_1 * V_2 , bool V_50 )
{
bool V_182 = false ;
struct V_57 * V_58 = V_2 -> V_58 ;
int V_3 ;
if ( ! V_58 )
return 0 ;
if ( V_50 ) {
if ( F_61 ( V_2 ) )
return - V_23 ;
for ( V_3 = 0 ; V_3 < V_58 -> V_167 ; V_3 ++ )
F_52 ( V_2 , V_58 , V_3 , V_50 ) ;
for ( V_3 = 0 ; V_3 < V_58 -> V_166 ; V_3 ++ )
F_50 ( V_2 , V_58 , V_3 , V_50 ) ;
for ( V_3 = 0 ; V_3 < V_58 -> V_60 ; V_3 ++ )
F_56 ( V_2 , V_58 , V_3 , V_50 ) ;
for ( V_3 = 0 ; V_3 < V_58 -> V_173 ; V_3 ++ )
F_49 ( V_2 , V_58 , V_3 , V_50 ) ;
} else {
for ( V_3 = 0 ; V_3 < V_58 -> V_173 ; V_3 ++ )
F_49 ( V_2 , V_58 , V_3 , V_182 ) ;
for ( V_3 = 0 ; V_3 < V_58 -> V_60 ; V_3 ++ )
F_56 ( V_2 , V_58 , V_3 , V_182 ) ;
for ( V_3 = 0 ; V_3 < V_58 -> V_167 ; V_3 ++ )
F_52 ( V_2 , V_58 , V_3 , V_182 ) ;
for ( V_3 = 0 ; V_3 < V_58 -> V_166 ; V_3 ++ )
F_50 ( V_2 , V_58 , V_3 , V_182 ) ;
F_60 ( V_2 ) ;
}
return 0 ;
}
static inline int F_65 ( struct V_84 * V_85 , int V_183 )
{
int V_184 ;
V_184 = V_85 -> V_56 ;
F_66 ( V_183 , & V_85 -> V_89 ) ;
V_85 -> V_56 += V_183 ;
V_85 -> V_56 &= ( V_85 -> V_13 . V_14 - 1 ) ;
return V_184 ;
}
void F_67 ( struct V_84 * V_85 , int V_183 )
{
F_68 ( V_183 , & V_85 -> V_89 ) ;
V_85 -> V_55 += V_183 ;
V_85 -> V_55 &= ( V_85 -> V_13 . V_14 - 1 ) ;
}
static inline int F_69 ( struct V_84 * V_85 , int V_184 )
{
V_184 ++ ;
V_184 &= ( V_85 -> V_13 . V_14 - 1 ) ;
return V_184 ;
}
void F_70 ( struct V_1 * V_2 , struct V_84 * V_85 , int V_3 )
{
T_1 V_146 ;
V_146 = F_2 ( V_2 , V_94 , V_3 ) ;
V_146 |= V_185 ;
F_27 ( V_2 , V_94 , V_3 , V_146 ) ;
F_27 ( V_2 , V_186 , V_3 , 0 ) ;
}
void F_71 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_146 ;
V_146 = F_2 ( V_2 , V_94 , V_3 ) ;
V_146 &= ~ V_185 ;
F_27 ( V_2 , V_94 , V_3 , V_146 ) ;
}
void F_72 ( struct V_187 * V_11 , struct V_84 * V_85 ,
int V_3 )
{
T_1 V_55 , V_56 ;
struct V_35 * V_39 ;
struct V_1 * V_2 = F_73 ( V_11 ) ;
struct V_188 * V_189 ;
V_55 = F_2 ( V_2 , V_190 , V_3 ) >> 4 ;
V_56 = F_2 ( V_2 , V_191 , V_3 ) >> 4 ;
while ( V_85 -> V_55 != V_55 ) {
V_189 = (struct V_188 * ) F_74 ( V_85 , V_85 -> V_55 ) ;
if ( V_189 -> V_192 != V_193 ) {
F_67 ( V_85 , 1 ) ;
continue;
}
V_39 = (struct V_35 * ) V_85 -> V_88 [ V_85 -> V_55 ] ;
if ( V_39 )
F_75 ( V_39 ) ;
F_76 ( 1 , ( V_194 * ) & V_11 -> V_195 . V_196 ) ;
F_76 ( V_189 -> V_197 ,
( V_194 * ) & V_11 -> V_195 . V_198 ) ;
F_67 ( V_85 , V_189 -> V_199 + 1 ) ;
}
}
static int F_77 ( struct V_35 * V_39 )
{
struct V_200 * V_201 = F_78 ( V_39 ) ;
unsigned int V_202 = F_79 ( V_39 ) + F_80 ( V_39 ) ;
unsigned int V_203 = V_39 -> V_37 - V_202 ;
unsigned int V_204 = V_201 -> V_205 ;
long V_206 = - 1 ;
long V_207 = F_81 ( V_39 ) - V_202 ;
long V_208 = 0 ;
long V_209 ;
int V_210 = 0 ;
int V_211 ;
for ( V_211 = 0 ; V_211 < V_201 -> V_212 ; V_211 ++ ) {
unsigned int V_213 = 0 ;
for ( V_210 ++ ; V_213 < V_204 ; V_210 ++ ) {
while ( V_208 >= V_207 ) {
V_206 ++ ;
V_207 = F_82 ( & V_201 -> V_214 [ V_206 ] ) ;
V_208 = 0 ;
}
V_209 = V_204 - V_213 ;
if ( V_209 > V_207 - V_208 )
V_209 = V_207 - V_208 ;
V_208 += V_209 ;
V_213 += V_209 ;
}
V_203 -= V_204 ;
if ( V_203 < V_204 )
V_204 = V_203 ;
}
return V_210 + V_201 -> V_212 ;
}
static int F_83 ( struct V_1 * V_2 , struct V_35 * V_39 )
{
int V_199 = V_215 ;
if ( F_78 ( V_39 ) -> V_205 && ! V_2 -> V_216 ) {
V_199 = F_77 ( V_39 ) ;
return V_199 ;
}
if ( F_78 ( V_39 ) -> V_217 )
V_199 += F_78 ( V_39 ) -> V_217 ;
return V_199 ;
}
static inline void
F_84 ( struct V_1 * V_2 , struct V_84 * V_85 , int V_184 ,
int V_199 , struct V_35 * V_39 , int V_37 )
{
int V_218 ;
struct V_188 * V_189 ;
V_189 = (struct V_188 * ) F_74 ( V_85 , V_184 ) ;
V_85 -> V_88 [ V_184 ] = ( T_1 ) V_39 ;
memset ( V_189 , 0 , V_86 ) ;
V_189 -> V_192 = V_193 ;
V_189 -> V_219 = 1 ;
V_189 -> V_199 = V_199 ;
V_189 -> V_197 = V_37 ;
if ( V_39 -> V_220 == V_221 ) {
V_189 -> V_222 = 1 ;
V_189 -> V_223 = F_85 ( V_39 ) ;
V_189 -> V_224 = F_79 ( V_39 ) ;
V_218 = F_86 ( V_39 ) -> V_225 ;
switch ( V_218 ) {
case V_226 :
V_189 -> V_227 = V_228 ;
break;
case V_229 :
V_189 -> V_227 = V_230 ;
break;
case V_231 :
V_189 -> V_227 = V_232 ;
break;
}
}
if ( V_2 -> V_216 && F_78 ( V_39 ) -> V_205 ) {
V_189 -> V_233 = 1 ;
V_189 -> V_234 = F_79 ( V_39 ) + F_80 ( V_39 ) ;
V_189 -> V_235 = F_78 ( V_39 ) -> V_205 ;
V_189 -> V_236 = F_85 ( V_39 ) - 2 ;
V_2 -> V_237 . V_238 ++ ;
}
}
static inline void F_87 ( struct V_84 * V_85 , int V_184 ,
int V_17 , T_1 V_38 )
{
struct V_239 * V_240 ;
V_184 &= ( V_85 -> V_13 . V_14 - 1 ) ;
V_240 = (struct V_239 * ) F_74 ( V_85 , V_184 ) ;
memset ( V_240 , 0 , V_86 ) ;
V_240 -> V_192 = V_241 ;
V_240 -> V_242 = V_243 ;
V_240 -> V_17 = V_17 ;
V_240 -> V_244 = V_38 ;
}
static int F_88 ( struct V_1 * V_2 , struct V_84 * V_85 ,
int V_148 , int V_184 , struct V_35 * V_39 )
{
struct V_245 V_233 ;
int V_246 = 0 , V_183 = 0 ;
int V_247 , V_248 , V_249 ;
int V_250 = V_184 ;
int V_251 = F_79 ( V_39 ) + F_80 ( V_39 ) ;
V_234 ( V_39 , & V_233 ) ;
V_248 = V_39 -> V_37 - V_251 ;
while ( V_248 > 0 ) {
char * V_189 ;
V_250 = V_184 ;
V_249 = F_89 ( int , F_78 ( V_39 ) -> V_205 , V_248 ) ;
V_248 -= V_249 ;
V_184 = F_69 ( V_85 , V_184 ) ;
V_189 = V_85 -> V_91 + V_184 * V_92 ;
F_90 ( V_39 , V_189 , & V_233 , V_249 , V_248 == 0 ) ;
F_87 ( V_85 , V_184 , V_251 ,
V_85 -> V_93 +
V_184 * V_92 ) ;
V_246 = 2 ;
V_247 = V_251 ;
while ( V_249 > 0 ) {
int V_17 ;
V_17 = F_89 ( int , V_233 . V_17 , V_249 ) ;
V_184 = F_69 ( V_85 , V_184 ) ;
F_87 ( V_85 , V_184 , V_17 ,
F_23 ( V_233 . V_38 ) ) ;
V_246 ++ ;
V_247 += V_17 ;
V_249 -= V_17 ;
F_91 ( V_39 , & V_233 , V_17 ) ;
}
F_84 ( V_2 , V_85 , V_250 ,
V_246 - 1 , V_39 , V_247 ) ;
V_85 -> V_88 [ V_250 ] = ( T_1 ) NULL ;
V_184 = F_69 ( V_85 , V_184 ) ;
V_183 += V_246 ;
}
V_85 -> V_88 [ V_250 ] = ( T_1 ) V_39 ;
F_26 () ;
F_27 ( V_2 , V_186 ,
V_148 , V_183 ) ;
V_2 -> V_237 . V_238 ++ ;
return 1 ;
}
int F_92 ( struct V_1 * V_2 , struct V_35 * V_39 )
{
int V_252 , V_17 ;
int V_199 ;
int V_148 , V_184 ;
struct V_57 * V_58 ;
struct V_84 * V_85 ;
V_148 = F_93 ( V_39 ) ;
if ( V_148 >= V_253 ) {
V_252 = V_148 / V_253 ;
if ( ! V_2 -> V_116 [ V_252 - 1 ] ) {
F_58 ( V_2 -> V_11 ,
L_5 ,
V_252 - 1 ) ;
return 1 ;
}
V_2 = (struct V_1 * ) V_2 -> V_116 [ V_252 - 1 ] ;
V_148 = V_148 % V_253 ;
}
V_58 = V_2 -> V_58 ;
V_85 = & V_58 -> V_85 [ V_148 ] ;
V_199 = F_83 ( V_2 , V_39 ) ;
if ( V_199 > F_94 ( & V_85 -> V_89 ) )
goto V_254;
V_184 = F_65 ( V_85 , V_199 ) ;
if ( F_78 ( V_39 ) -> V_205 && ! V_2 -> V_216 )
return F_88 ( V_2 , V_85 , V_148 , V_184 , V_39 ) ;
F_84 ( V_2 , V_85 , V_184 , V_199 - 1 ,
V_39 , V_39 -> V_37 ) ;
V_184 = F_69 ( V_85 , V_184 ) ;
V_17 = F_95 ( V_39 ) ? F_81 ( V_39 ) : V_39 -> V_37 ;
F_87 ( V_85 , V_184 , V_17 , F_23 ( V_39 -> V_38 ) ) ;
if ( ! F_95 ( V_39 ) )
goto V_255;
for ( V_252 = 0 ; V_252 < F_78 ( V_39 ) -> V_217 ; V_252 ++ ) {
const struct V_256 * V_257 ;
V_257 = & F_78 ( V_39 ) -> V_214 [ V_252 ] ;
V_184 = F_69 ( V_85 , V_184 ) ;
V_17 = F_82 ( V_257 ) ;
F_87 ( V_85 , V_184 , V_17 ,
F_23 (
F_96 ( V_257 ) ) ) ;
}
V_255:
F_26 () ;
F_27 ( V_2 , V_186 ,
V_148 , V_199 ) ;
return 1 ;
V_254:
V_2 = V_2 -> V_258 ;
F_97 ( V_2 -> V_11 , L_6 ) ;
return 0 ;
}
static inline unsigned F_98 ( unsigned V_252 )
{
#ifdef F_59
return ( V_252 & ~ 3 ) + 3 - ( V_252 & 3 ) ;
#else
return V_252 ;
#endif
}
struct V_35 * F_99 ( struct V_1 * V_2 , struct V_259 * V_260 )
{
int V_257 ;
int V_261 = 0 ;
struct V_35 * V_39 = NULL ;
struct V_35 * V_262 = NULL ;
struct V_35 * V_263 = NULL ;
T_5 * V_264 = NULL ;
T_1 * V_265 = NULL ;
V_264 = ( void * ) V_260 + ( 3 * sizeof( T_1 ) ) ;
V_265 = ( void * ) V_260 + ( 6 * sizeof( T_1 ) ) ;
F_97 ( V_2 -> V_11 , L_7 ,
V_266 , V_260 -> V_267 , V_260 -> V_268 , V_260 -> V_269 ) ;
for ( V_257 = 0 ; V_257 < V_260 -> V_267 ; V_257 ++ ) {
V_261 = V_264 [ F_98 ( V_257 ) ] ;
if ( ! V_257 ) {
V_39 = F_15 ( V_2 ,
* V_265 - V_260 -> V_270 ,
V_261 ) ;
if ( ! V_39 )
return NULL ;
F_100 ( V_39 , V_260 -> V_270 ) ;
F_101 ( V_39 , V_261 ) ;
} else {
V_262 = F_15 ( V_2 , * V_265 ,
V_261 ) ;
if ( ! V_262 ) {
F_102 ( V_39 ) ;
return NULL ;
}
if ( ! F_78 ( V_39 ) -> V_271 )
F_78 ( V_39 ) -> V_271 = V_262 ;
else
V_263 -> V_272 = V_262 ;
V_263 = V_262 ;
V_39 -> V_37 += V_261 ;
V_39 -> V_203 += V_261 ;
V_262 -> V_37 = V_261 ;
}
V_265 ++ ;
}
return V_39 ;
}
static T_1 F_103 ( int V_273 , int V_274 )
{
T_1 V_9 ;
switch ( V_273 ) {
case V_275 :
V_9 = ( ( 1ULL << V_274 ) << V_276 ) ;
break;
case V_277 :
V_9 = ( ( 1ULL << V_274 ) << V_278 ) ;
break;
case V_71 :
V_9 = ( ( 1ULL << V_274 ) << V_279 ) ;
break;
case V_280 :
V_9 = ( 1ULL << V_281 ) ;
break;
case V_282 :
V_9 = ( 1ULL << V_283 ) ;
break;
case V_284 :
V_9 = ( 1ULL << V_285 ) ;
break;
case V_286 :
V_9 = ( 1ULL << V_287 ) ;
break;
default:
V_9 = 0 ;
}
return V_9 ;
}
void F_28 ( struct V_1 * V_2 , int V_273 , int V_274 )
{
T_1 V_288 = F_103 ( V_273 , V_274 ) ;
if ( ! V_288 ) {
F_97 ( V_2 -> V_11 ,
L_8 ) ;
return;
}
F_104 ( V_2 , V_289 ,
F_105 ( V_2 , V_289 ) | V_288 ) ;
}
void F_106 ( struct V_1 * V_2 , int V_273 , int V_274 )
{
T_1 V_288 = F_103 ( V_273 , V_274 ) ;
if ( ! V_288 ) {
F_97 ( V_2 -> V_11 ,
L_9 ) ;
return;
}
F_104 ( V_2 , V_290 , V_288 ) ;
}
void F_107 ( struct V_1 * V_2 , int V_273 , int V_274 )
{
T_1 V_288 = F_103 ( V_273 , V_274 ) ;
if ( ! V_288 ) {
F_97 ( V_2 -> V_11 ,
L_10 ) ;
return;
}
F_104 ( V_2 , V_291 , V_288 ) ;
}
int F_108 ( struct V_1 * V_2 , int V_273 , int V_274 )
{
T_1 V_288 = F_103 ( V_273 , V_274 ) ;
if ( ! V_288 ) {
F_97 ( V_2 -> V_11 ,
L_11 ) ;
return 0 ;
}
return V_288 & F_105 ( V_2 , V_289 ) ;
}
void F_109 ( struct V_1 * V_2 , int V_292 )
{
struct V_117 * V_118 ;
#define F_110 ( V_4 ) \
nicvf_reg_read(nic, NIC_QSET_RQ_0_7_STAT_0_1 |\
(rq_idx << NIC_Q_NUM_SHIFT) | (reg << 3))
V_118 = & V_2 -> V_58 -> V_118 [ V_292 ] ;
V_118 -> V_195 . V_293 = F_110 ( V_294 ) ;
V_118 -> V_195 . V_295 = F_110 ( V_296 ) ;
}
void F_111 ( struct V_1 * V_2 , int V_297 )
{
struct V_84 * V_85 ;
#define F_112 ( V_4 ) \
nicvf_reg_read(nic, NIC_QSET_SQ_0_7_STAT_0_1 |\
(sq_idx << NIC_Q_NUM_SHIFT) | (reg << 3))
V_85 = & V_2 -> V_58 -> V_85 [ V_297 ] ;
V_85 -> V_195 . V_293 = F_112 ( V_294 ) ;
V_85 -> V_195 . V_295 = F_112 ( V_296 ) ;
}
int F_113 ( struct V_1 * V_2 , struct V_259 * V_260 )
{
struct V_298 * V_195 = & V_2 -> V_299 ;
if ( ! V_260 -> V_300 && ! V_260 -> V_301 )
return 0 ;
if ( F_114 ( V_2 ) )
F_4 ( V_2 -> V_11 ,
L_12 ,
V_2 -> V_11 -> V_302 ,
V_260 -> V_300 , V_260 -> V_301 ) ;
switch ( V_260 -> V_301 ) {
case V_303 :
V_195 -> V_304 ++ ;
break;
case V_305 :
V_195 -> V_306 ++ ;
break;
case V_307 :
V_195 -> V_308 ++ ;
break;
case V_309 :
V_195 -> V_310 ++ ;
break;
case V_311 :
V_195 -> V_312 ++ ;
break;
case V_313 :
V_195 -> V_314 ++ ;
break;
case V_315 :
V_195 -> V_316 ++ ;
break;
case V_317 :
V_195 -> V_318 ++ ;
break;
case V_319 :
V_195 -> V_320 ++ ;
break;
case V_321 :
V_195 -> V_322 ++ ;
break;
case V_323 :
V_195 -> V_324 ++ ;
break;
case V_325 :
V_195 -> V_326 ++ ;
break;
case V_327 :
V_195 -> V_328 ++ ;
break;
case V_329 :
V_195 -> V_330 ++ ;
break;
case V_331 :
V_195 -> V_332 ++ ;
break;
case V_333 :
V_195 -> V_334 ++ ;
break;
case V_335 :
V_195 -> V_336 ++ ;
break;
case V_337 :
V_195 -> V_338 ++ ;
break;
case V_339 :
V_195 -> V_340 ++ ;
break;
case V_341 :
V_195 -> V_342 ++ ;
break;
case V_343 :
V_195 -> V_344 ++ ;
break;
case V_345 :
V_195 -> V_346 ++ ;
break;
case V_347 :
V_195 -> V_348 ++ ;
break;
case V_349 :
V_195 -> V_350 ++ ;
break;
}
return 1 ;
}
int F_115 ( struct V_1 * V_2 ,
struct V_77 * V_78 , struct V_351 * V_352 )
{
struct V_353 * V_195 = & V_78 -> V_195 ;
switch ( V_352 -> V_354 ) {
case V_355 :
V_195 -> V_356 . V_357 ++ ;
return 0 ;
case V_358 :
V_195 -> V_356 . V_359 ++ ;
break;
case V_360 :
V_195 -> V_356 . V_361 ++ ;
break;
case V_362 :
V_195 -> V_356 . V_363 ++ ;
break;
case V_364 :
V_195 -> V_356 . V_365 ++ ;
break;
case V_366 :
V_195 -> V_356 . V_367 ++ ;
break;
case V_368 :
V_195 -> V_356 . V_369 ++ ;
break;
case V_370 :
V_195 -> V_356 . V_371 ++ ;
break;
case V_372 :
V_195 -> V_356 . V_373 ++ ;
break;
case V_374 :
V_195 -> V_356 . V_375 ++ ;
break;
case V_376 :
V_195 -> V_356 . V_377 ++ ;
break;
case V_378 :
V_195 -> V_356 . V_379 ++ ;
break;
case V_380 :
V_195 -> V_356 . V_381 ++ ;
break;
case V_382 :
V_195 -> V_356 . V_383 ++ ;
break;
}
return 1 ;
}

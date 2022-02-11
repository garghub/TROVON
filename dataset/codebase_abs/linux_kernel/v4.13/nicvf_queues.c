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
static inline struct V_28 * F_12 ( struct V_1 * V_2 ,
struct V_29 * V_29 , T_2 V_30 )
{
int V_31 ;
struct V_32 * V_32 = NULL ;
struct V_28 * V_28 , * V_33 ;
V_28 = & V_29 -> V_28 [ V_29 -> V_34 ] ;
V_32 = V_28 -> V_32 ;
if ( V_32 ) {
V_31 = F_13 ( V_32 ) ;
if ( V_29 -> V_35 && ( V_31 == V_28 -> V_31 ) )
V_28 -> V_31 -- ;
else
V_32 = NULL ;
if ( ! V_29 -> V_35 && ( V_31 != 1 ) )
V_32 = NULL ;
}
if ( ! V_32 ) {
V_32 = F_14 ( V_30 | V_36 | V_37 , 0 ) ;
if ( ! V_32 )
return NULL ;
F_15 ( V_2 -> V_38 -> V_39 -> V_40 ) ;
if ( V_29 -> V_41 >= V_29 -> V_42 ) {
V_2 -> V_4 = V_32 ;
return NULL ;
}
V_28 -> V_32 = V_32 ;
V_28 -> V_43 = 0 ;
V_28 -> V_31 = 0 ;
V_29 -> V_41 ++ ;
}
if ( V_29 -> V_35 ) {
if ( ! V_28 -> V_31 ) {
V_28 -> V_31 = V_44 ;
F_2 ( V_32 , V_44 ) ;
}
} else {
F_2 ( V_32 , 1 ) ;
}
V_29 -> V_34 ++ ;
V_29 -> V_34 &= ( V_29 -> V_42 - 1 ) ;
V_33 = & V_29 -> V_28 [ V_29 -> V_34 ] ;
V_32 = V_33 -> V_32 ;
if ( V_32 )
F_16 ( & V_32 -> V_45 ) ;
return V_28 ;
}
static inline int F_17 ( struct V_1 * V_2 , struct V_29 * V_29 ,
T_2 V_30 , T_3 V_46 , T_1 * V_47 )
{
struct V_28 * V_28 = NULL ;
if ( ! V_29 -> V_35 && V_2 -> V_4 &&
( ( V_2 -> V_48 + V_46 ) <= V_49 ) ) {
V_2 -> V_3 ++ ;
goto V_50;
}
F_1 ( V_2 ) ;
V_2 -> V_4 = NULL ;
V_28 = F_12 ( V_2 , V_29 , V_30 ) ;
if ( ! V_28 && ! V_2 -> V_4 ) {
F_15 ( V_2 -> V_38 -> V_39 -> V_51 ) ;
return - V_25 ;
}
V_2 -> V_48 = 0 ;
if ( V_29 -> V_35 )
V_46 += V_52 ;
if ( V_28 )
V_2 -> V_4 = V_28 -> V_32 ;
V_50:
if ( V_29 -> V_35 && V_28 && V_28 -> V_43 ) {
* V_47 = V_28 -> V_43 ;
} else {
* V_47 = ( T_1 ) F_18 ( & V_2 -> V_21 -> V_22 , V_2 -> V_4 ,
V_2 -> V_48 , V_46 ,
V_53 ,
V_54 ) ;
if ( F_19 ( & V_2 -> V_21 -> V_22 , ( V_55 ) * V_47 ) ) {
if ( ! V_2 -> V_48 )
F_20 ( V_2 -> V_4 , 0 ) ;
V_2 -> V_4 = NULL ;
return - V_25 ;
}
if ( V_28 )
V_28 -> V_43 = * V_47 + V_52 ;
V_2 -> V_48 += V_46 ;
}
return 0 ;
}
static struct V_56 * F_21 ( struct V_1 * V_2 ,
T_1 V_57 , int V_58 )
{
void * V_59 ;
struct V_56 * V_60 ;
V_59 = F_22 ( V_57 ) ;
V_60 = F_23 ( V_59 , V_61 ) ;
if ( ! V_60 ) {
F_24 ( F_25 ( V_59 ) ) ;
return NULL ;
}
F_16 ( V_60 -> V_59 ) ;
return V_60 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_29 * V_29 ,
int V_62 , int V_63 )
{
int V_64 ;
T_1 V_47 ;
struct V_65 * V_66 ;
int V_67 ;
V_67 = F_7 ( V_2 , & V_29 -> V_15 , V_62 ,
sizeof( struct V_65 ) ,
V_68 ) ;
if ( V_67 )
return V_67 ;
V_29 -> V_66 = V_29 -> V_15 . V_27 ;
V_29 -> V_69 = V_63 ;
V_29 -> V_70 = true ;
V_29 -> V_71 = V_72 ;
V_29 -> V_73 = 0 ;
V_29 -> V_74 = 0 ;
if ( ! V_2 -> V_38 -> V_75 ) {
V_29 -> V_42 = V_62 / ( V_49 / V_63 ) ;
V_29 -> V_35 = false ;
} else {
V_29 -> V_42 = V_62 ;
V_29 -> V_35 = true ;
}
V_29 -> V_42 = F_27 ( V_29 -> V_42 ) ;
V_29 -> V_28 = F_28 ( sizeof( * V_29 -> V_28 ) *
V_29 -> V_42 , V_24 ) ;
if ( ! V_29 -> V_28 )
return - V_25 ;
V_29 -> V_34 = 0 ;
V_29 -> V_41 = 0 ;
V_2 -> V_4 = NULL ;
for ( V_64 = 0 ; V_64 < V_62 ; V_64 ++ ) {
V_67 = F_17 ( V_2 , V_29 , V_24 ,
V_61 , & V_47 ) ;
if ( V_67 ) {
V_29 -> V_74 = V_64 - 1 ;
return V_67 ;
}
V_66 = F_29 ( V_29 , V_64 ) ;
V_66 -> V_76 = V_47 & ~ ( V_68 - 1 ) ;
}
F_1 ( V_2 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 , struct V_29 * V_29 )
{
int V_73 , V_74 ;
T_1 V_76 , V_77 ;
struct V_28 * V_28 ;
struct V_65 * V_66 ;
if ( ! V_29 )
return;
V_29 -> V_70 = false ;
if ( ! V_29 -> V_15 . V_27 )
return;
V_73 = V_29 -> V_73 ;
V_74 = V_29 -> V_74 ;
while ( V_73 != V_74 ) {
V_66 = F_29 ( V_29 , V_73 ) ;
V_76 = V_66 -> V_76 ;
V_77 = F_31 ( V_2 , V_76 ) ;
F_32 ( & V_2 -> V_21 -> V_22 , V_76 , V_61 ,
V_53 , V_54 ) ;
if ( V_77 )
F_24 ( F_25 ( F_22 ( V_77 ) ) ) ;
V_73 ++ ;
V_73 &= ( V_29 -> V_15 . V_16 - 1 ) ;
}
V_66 = F_29 ( V_29 , V_74 ) ;
V_76 = V_66 -> V_76 ;
V_77 = F_31 ( V_2 , V_76 ) ;
F_32 ( & V_2 -> V_21 -> V_22 , V_76 , V_61 ,
V_53 , V_54 ) ;
if ( V_77 )
F_24 ( F_25 ( F_22 ( V_77 ) ) ) ;
F_33 () ;
V_73 = 0 ;
while ( V_73 < V_29 -> V_42 ) {
V_28 = & V_29 -> V_28 [ V_73 ] ;
if ( V_28 -> V_32 && F_13 ( V_28 -> V_32 ) != 0 ) {
if ( ! V_29 -> V_35 ) {
F_24 ( V_28 -> V_32 ) ;
continue;
}
F_34 ( V_28 -> V_32 , V_28 -> V_31 - 1 ) ;
F_24 ( V_28 -> V_32 ) ;
}
V_73 ++ ;
}
F_10 ( V_2 , & V_29 -> V_15 ) ;
}
static void F_35 ( struct V_1 * V_2 , T_2 V_30 )
{
struct V_78 * V_79 = V_2 -> V_79 ;
int V_80 = V_79 -> V_81 ;
int V_74 , V_82 ;
int V_83 ;
struct V_29 * V_29 ;
struct V_65 * V_66 ;
T_1 V_47 ;
int V_84 = 0 ;
V_85:
if ( ! V_80 )
return;
V_80 -- ;
V_29 = & V_79 -> V_29 [ V_80 ] ;
if ( ! V_29 -> V_70 )
goto V_86;
V_82 = F_4 ( V_2 , V_87 , V_80 ) ;
V_82 &= 0x7FFFF ;
if ( V_82 >= ( V_79 -> V_88 - 1 ) )
goto V_86;
else
V_83 = V_79 -> V_88 - V_82 - 1 ;
F_33 () ;
V_74 = F_4 ( V_2 , V_89 , V_80 ) >> 3 ;
while ( V_83 ) {
V_74 ++ ;
V_74 &= ( V_29 -> V_15 . V_16 - 1 ) ;
if ( F_17 ( V_2 , V_29 , V_30 , V_61 , & V_47 ) )
break;
V_66 = F_29 ( V_29 , V_74 ) ;
V_66 -> V_76 = V_47 & ~ ( V_68 - 1 ) ;
V_83 -- ;
V_84 ++ ;
}
F_1 ( V_2 ) ;
F_36 () ;
if ( V_83 )
V_2 -> V_90 = true ;
else
V_2 -> V_90 = false ;
F_37 ( V_2 , V_91 ,
V_80 , V_84 ) ;
V_86:
if ( ! V_2 -> V_90 && V_29 -> V_70 &&
F_38 ( V_2 -> V_38 -> V_13 ) )
F_39 ( V_2 , V_92 , V_80 ) ;
if ( V_80 )
goto V_85;
}
void F_40 ( struct V_93 * V_94 )
{
struct V_1 * V_2 = F_41 ( V_94 , struct V_1 , V_95 . V_94 ) ;
F_35 ( V_2 , V_24 ) ;
if ( V_2 -> V_90 )
F_42 ( & V_2 -> V_95 , F_43 ( 10 ) ) ;
else
V_2 -> V_96 = false ;
}
void F_44 ( unsigned long V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_59 ;
F_35 ( V_2 , V_97 ) ;
if ( V_2 -> V_90 ) {
V_2 -> V_96 = true ;
F_42 ( & V_2 -> V_95 , F_43 ( 10 ) ) ;
}
}
static int F_45 ( struct V_1 * V_2 ,
struct V_98 * V_99 , int V_16 )
{
int V_67 ;
V_67 = F_7 ( V_2 , & V_99 -> V_15 , V_16 , V_100 ,
V_101 ) ;
if ( V_67 )
return V_67 ;
V_99 -> V_66 = V_99 -> V_15 . V_27 ;
V_99 -> V_71 = F_46 ( V_2 -> V_21 ) ? 0 : V_102 ;
V_2 -> V_103 = ( V_104 * 0.05 ) - 1 ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 , struct V_98 * V_99 )
{
if ( ! V_99 )
return;
if ( ! V_99 -> V_15 . V_27 )
return;
F_10 ( V_2 , & V_99 -> V_15 ) ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_105 * V_106 , int V_16 , int V_5 )
{
int V_67 ;
V_67 = F_7 ( V_2 , & V_106 -> V_15 , V_16 , V_107 ,
V_108 ) ;
if ( V_67 )
return V_67 ;
V_106 -> V_66 = V_106 -> V_15 . V_27 ;
V_106 -> V_109 = F_49 ( V_16 , sizeof( T_1 ) , V_24 ) ;
if ( ! V_106 -> V_109 )
return - V_25 ;
V_106 -> V_73 = 0 ;
V_106 -> V_74 = 0 ;
V_106 -> V_71 = V_110 ;
if ( V_2 -> V_111 )
V_5 += ( ( V_2 -> V_112 + 1 ) * V_113 ) ;
if ( V_5 < V_2 -> V_38 -> V_114 ) {
V_106 -> V_115 = F_49 ( V_16 , sizeof( T_1 ) , V_24 ) ;
if ( ! V_106 -> V_115 )
return - V_25 ;
V_106 -> V_116 = 0 ;
V_106 -> V_117 = V_16 - 1 ;
V_106 -> V_35 = true ;
} else {
V_106 -> V_115 = NULL ;
V_106 -> V_116 = 0 ;
V_106 -> V_117 = 0 ;
V_106 -> V_35 = false ;
F_50 ( & V_106 -> V_118 , V_16 - 1 ) ;
V_106 -> V_119 = F_51 ( & V_2 -> V_21 -> V_22 ,
V_16 * V_120 ,
& V_106 -> V_121 ,
V_24 ) ;
if ( ! V_106 -> V_119 )
return - V_25 ;
}
return 0 ;
}
void F_52 ( struct V_1 * V_2 , struct V_105 * V_106 ,
int V_122 , T_4 V_123 )
{
T_4 V_64 ;
struct V_124 * V_125 ;
for ( V_64 = 0 ; V_64 < V_123 ; V_64 ++ ) {
V_122 ++ ;
V_122 &= ( V_106 -> V_15 . V_16 - 1 ) ;
V_125 = (struct V_124 * ) F_53 ( V_106 , V_122 ) ;
F_32 ( & V_2 -> V_21 -> V_22 , V_125 -> V_126 ,
V_125 -> V_19 , V_127 ,
V_54 ) ;
}
}
static void F_54 ( struct V_1 * V_2 , struct V_105 * V_106 )
{
struct V_56 * V_60 ;
struct V_32 * V_32 ;
struct V_128 * V_129 ;
struct V_128 * V_130 ;
if ( ! V_106 )
return;
if ( ! V_106 -> V_15 . V_27 )
return;
if ( V_106 -> V_119 )
F_11 ( & V_2 -> V_21 -> V_22 ,
V_106 -> V_15 . V_16 * V_120 ,
V_106 -> V_119 , V_106 -> V_121 ) ;
F_33 () ;
while ( V_106 -> V_73 != V_106 -> V_74 ) {
V_60 = (struct V_56 * ) V_106 -> V_109 [ V_106 -> V_73 ] ;
if ( ! V_60 || ! V_106 -> V_115 )
goto V_33;
V_32 = (struct V_32 * ) V_106 -> V_115 [ V_106 -> V_73 ] ;
if ( ! V_32 )
goto V_33;
else
F_24 ( V_32 ) ;
V_129 = (struct V_128 * ) F_53 ( V_106 , V_106 -> V_73 ) ;
if ( V_129 -> V_131 ) {
V_130 =
(struct V_128 * ) F_53 ( V_106 , V_129 -> V_132 ) ;
F_52 ( V_2 , V_106 , V_129 -> V_132 ,
V_130 -> V_123 ) ;
} else {
F_52 ( V_2 , V_106 , V_106 -> V_73 ,
V_129 -> V_123 ) ;
}
if ( V_60 )
F_55 ( V_60 ) ;
V_33:
V_106 -> V_73 ++ ;
V_106 -> V_73 &= ( V_106 -> V_15 . V_16 - 1 ) ;
}
F_56 ( V_106 -> V_109 ) ;
F_56 ( V_106 -> V_115 ) ;
F_10 ( V_2 , & V_106 -> V_15 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_78 * V_79 , int V_5 )
{
F_37 ( V_2 , V_133 , V_5 , 0 ) ;
if ( F_3 ( V_2 , V_5 , V_134 , 21 , 1 , 0x01 ) )
return;
F_37 ( V_2 , V_133 , V_5 , V_135 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_78 * V_79 , int V_5 )
{
union V_136 V_137 = {} ;
V_137 . V_138 . V_138 = V_139 ;
F_59 ( V_2 , & V_137 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_78 * V_79 , int V_5 )
{
F_37 ( V_2 , V_140 , V_5 , 0 ) ;
F_37 ( V_2 , V_141 , V_5 , 0 ) ;
F_37 ( V_2 , V_141 , V_5 , V_142 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_29 * V_29 , int V_5 )
{
T_1 V_143 , V_144 ;
int V_12 = 10 ;
V_29 -> V_73 = F_4 ( V_2 ,
V_145 ,
V_5 ) >> 3 ;
V_29 -> V_74 = F_4 ( V_2 ,
V_89 ,
V_5 ) >> 3 ;
V_144 = F_4 ( V_2 , V_87 , V_5 ) ;
if ( ( ( V_144 >> 62 ) & 0x03 ) == 0x3 )
F_37 ( V_2 , V_146 ,
V_5 , V_147 ) ;
F_37 ( V_2 , V_146 , V_5 , 0 ) ;
if ( F_3 ( V_2 , V_5 , V_87 , 62 , 2 , 0x00 ) )
return;
while ( 1 ) {
V_143 = F_4 ( V_2 ,
V_148 ,
V_5 ) ;
if ( ( V_143 & 0xFFFFFFFF ) == ( ( V_143 >> 32 ) & 0xFFFFFFFF ) )
break;
F_5 ( 1000 , 2000 ) ;
V_12 -- ;
if ( ! V_12 ) {
F_6 ( V_2 -> V_13 ,
L_2 ) ;
return;
}
}
F_37 ( V_2 , V_146 ,
V_5 , V_147 ) ;
if ( F_3 ( V_2 , V_5 , V_87 , 62 , 2 , 0x02 ) )
return;
F_37 ( V_2 , V_146 , V_5 , 0x00 ) ;
if ( F_3 ( V_2 , V_5 , V_87 , 62 , 2 , 0x00 ) )
return;
}
void F_62 ( struct V_1 * V_2 , T_5 V_149 )
{
T_1 V_150 ;
int V_151 ;
V_150 = F_4 ( V_2 , V_152 , 0 ) ;
if ( V_149 & V_153 )
V_150 |= ( 1ULL << 25 ) ;
else
V_150 &= ~ ( 1ULL << 25 ) ;
F_37 ( V_2 , V_152 , 0 , V_150 ) ;
for ( V_151 = 0 ; V_151 < V_2 -> V_154 ; V_151 ++ )
if ( V_2 -> V_155 [ V_151 ] )
F_37 ( V_2 -> V_155 [ V_151 ] ,
V_152 , 0 , V_150 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
union V_136 V_137 = {} ;
V_137 . V_156 . V_138 = V_157 ;
V_137 . V_156 . V_158 = 0x3FFF ;
V_137 . V_156 . V_159 = 0x1F ;
V_137 . V_156 . V_160 = 0xFFFF ;
V_137 . V_156 . V_161 = 0xFFFF ;
F_59 ( V_2 , & V_137 ) ;
}
static void F_64 ( struct V_1 * V_2 , struct V_78 * V_79 ,
int V_5 , bool V_70 )
{
union V_136 V_137 = {} ;
struct V_162 * V_163 ;
struct V_150 V_150 ;
V_163 = & V_79 -> V_163 [ V_5 ] ;
V_163 -> V_70 = V_70 ;
F_37 ( V_2 , V_164 , V_5 , 0 ) ;
if ( ! V_163 -> V_70 ) {
F_58 ( V_2 , V_79 , V_5 ) ;
return;
}
V_163 -> V_165 = V_79 -> V_166 ;
V_163 -> V_167 = V_5 ;
V_163 -> V_168 = V_79 -> V_166 ;
V_163 -> V_169 = V_79 -> V_81 - 1 ;
V_163 -> V_170 = V_79 -> V_166 ;
V_163 -> V_171 = V_79 -> V_81 - 1 ;
V_163 -> V_172 = 1 ;
V_137 . V_163 . V_138 = V_173 ;
V_137 . V_163 . V_174 = V_79 -> V_166 ;
V_137 . V_163 . V_175 = V_5 ;
V_137 . V_163 . V_176 = ( V_163 -> V_172 << 26 ) | ( V_163 -> V_165 << 19 ) |
( V_163 -> V_167 << 16 ) | ( V_163 -> V_170 << 9 ) |
( V_163 -> V_171 << 8 ) |
( V_163 -> V_168 << 1 ) | ( V_163 -> V_169 ) ;
F_59 ( V_2 , & V_137 ) ;
V_137 . V_163 . V_138 = V_177 ;
V_137 . V_163 . V_176 = F_65 ( 63 ) | F_65 ( 62 ) |
( V_178 << 16 ) | ( V_179 << 8 ) |
( V_79 -> V_166 << 0 ) ;
F_59 ( V_2 , & V_137 ) ;
V_137 . V_163 . V_138 = V_180 ;
V_137 . V_163 . V_176 = F_65 ( 63 ) | F_65 ( 62 ) |
( V_178 << 40 ) | ( V_181 << 32 ) |
( V_179 << 16 ) | ( V_182 << 8 ) ;
F_59 ( V_2 , & V_137 ) ;
if ( ! V_2 -> V_111 && ( V_5 == 0 ) ) {
F_37 ( V_2 , V_152 , 0 ,
( F_66 ( 24 ) | F_66 ( 23 ) | F_66 ( 21 ) | F_66 ( 20 ) ) ) ;
F_62 ( V_2 , V_2 -> V_13 -> V_149 ) ;
}
memset ( & V_150 , 0 , sizeof( struct V_150 ) ) ;
V_150 . V_183 = 1 ;
V_150 . V_184 = 0 ;
F_37 ( V_2 , V_164 , V_5 , * ( T_1 * ) & V_150 ) ;
}
void F_67 ( struct V_1 * V_2 , struct V_78 * V_79 ,
int V_5 , bool V_70 )
{
struct V_98 * V_99 ;
struct V_185 V_185 ;
V_99 = & V_79 -> V_99 [ V_5 ] ;
V_99 -> V_70 = V_70 ;
if ( ! V_99 -> V_70 ) {
F_60 ( V_2 , V_79 , V_5 ) ;
return;
}
F_37 ( V_2 , V_141 , V_5 , V_142 ) ;
if ( ! V_99 -> V_70 )
return;
F_68 ( & V_99 -> V_186 ) ;
F_37 ( V_2 , V_187 ,
V_5 , ( T_1 ) ( V_99 -> V_15 . V_26 ) ) ;
memset ( & V_185 , 0 , sizeof( struct V_185 ) ) ;
V_185 . V_183 = 1 ;
V_185 . V_188 = 0 ;
V_185 . V_172 = 0 ;
V_185 . V_189 = F_69 ( V_79 -> V_190 >> 10 ) ;
V_185 . V_191 = 0 ;
F_37 ( V_2 , V_141 , V_5 , * ( T_1 * ) & V_185 ) ;
F_37 ( V_2 , V_192 , V_5 , V_99 -> V_71 ) ;
F_37 ( V_2 , V_140 ,
V_5 , V_104 ) ;
}
static void F_70 ( struct V_1 * V_2 , struct V_78 * V_79 ,
int V_5 , bool V_70 )
{
union V_136 V_137 = {} ;
struct V_105 * V_106 ;
struct V_193 V_193 ;
V_106 = & V_79 -> V_106 [ V_5 ] ;
V_106 -> V_70 = V_70 ;
if ( ! V_106 -> V_70 ) {
F_57 ( V_2 , V_79 , V_5 ) ;
return;
}
F_37 ( V_2 , V_133 , V_5 , V_135 ) ;
V_106 -> V_165 = V_79 -> V_166 ;
V_106 -> V_167 = V_5 ;
V_137 . V_106 . V_138 = V_194 ;
V_137 . V_106 . V_174 = V_79 -> V_166 ;
V_137 . V_106 . V_195 = V_5 ;
V_137 . V_106 . V_111 = V_2 -> V_111 ;
V_137 . V_106 . V_176 = ( V_106 -> V_165 << 3 ) | V_106 -> V_167 ;
F_59 ( V_2 , & V_137 ) ;
F_37 ( V_2 , V_196 ,
V_5 , ( T_1 ) ( V_106 -> V_15 . V_26 ) ) ;
memset ( & V_193 , 0 , sizeof( struct V_193 ) ) ;
V_193 . V_183 = 1 ;
V_193 . V_188 = 0 ;
V_193 . V_197 = 0 ;
V_193 . V_189 = F_69 ( V_79 -> V_198 >> 10 ) ;
V_193 . V_199 = 0 ;
V_193 . V_200 = ( V_201 * 256 ) / V_79 -> V_190 ;
F_37 ( V_2 , V_133 , V_5 , * ( T_1 * ) & V_193 ) ;
F_37 ( V_2 , V_202 , V_5 , V_106 -> V_71 ) ;
if ( F_71 ( V_5 ) ) {
F_72 ( V_5 , & V_106 -> V_203 ) ;
F_73 ( V_2 -> V_13 ,
& V_106 -> V_203 , V_5 ) ;
}
}
static void F_74 ( struct V_1 * V_2 , struct V_78 * V_79 ,
int V_5 , bool V_70 )
{
struct V_29 * V_29 ;
struct V_204 V_204 ;
V_29 = & V_79 -> V_29 [ V_5 ] ;
F_61 ( V_2 , V_29 , V_5 ) ;
if ( ! V_70 )
return;
F_37 ( V_2 , V_205 ,
V_5 , ( T_1 ) ( V_29 -> V_15 . V_26 ) ) ;
memset ( & V_204 , 0 , sizeof( struct V_204 ) ) ;
V_204 . V_183 = 1 ;
V_204 . V_188 = 0 ;
V_204 . V_197 = 0 ;
V_204 . V_189 = V_206 ;
V_204 . V_191 = 0 ;
V_204 . V_207 = V_29 -> V_69 / 128 ;
F_37 ( V_2 , V_146 ,
V_5 , * ( T_1 * ) & V_204 ) ;
F_37 ( V_2 , V_91 ,
V_5 , V_79 -> V_88 - 1 ) ;
F_37 ( V_2 , V_208 ,
V_5 , V_29 -> V_71 - 1 ) ;
}
void F_75 ( struct V_1 * V_2 , bool V_70 )
{
union V_136 V_137 = {} ;
struct V_78 * V_79 = V_2 -> V_79 ;
struct V_209 * V_209 ;
if ( ! V_79 ) {
F_76 ( V_2 -> V_13 ,
L_3 ) ;
return;
}
V_79 -> V_70 = V_70 ;
V_79 -> V_166 = V_2 -> V_210 ;
V_137 . V_79 . V_138 = V_211 ;
V_137 . V_79 . V_212 = V_79 -> V_166 ;
V_137 . V_79 . V_154 = V_2 -> V_154 ;
V_137 . V_79 . V_176 = 0 ;
V_209 = (struct V_209 * ) & V_137 . V_79 . V_176 ;
if ( V_79 -> V_70 ) {
V_209 -> V_183 = 1 ;
#ifdef F_77
V_209 -> V_213 = 1 ;
#endif
V_209 -> V_214 = V_79 -> V_166 ;
}
F_59 ( V_2 , & V_137 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_78 * V_79 = V_2 -> V_79 ;
for ( V_5 = 0 ; V_5 < V_79 -> V_81 ; V_5 ++ )
F_30 ( V_2 , & V_79 -> V_29 [ V_5 ] ) ;
for ( V_5 = 0 ; V_5 < V_79 -> V_215 ; V_5 ++ )
F_47 ( V_2 , & V_79 -> V_99 [ V_5 ] ) ;
for ( V_5 = 0 ; V_5 < V_79 -> V_216 ; V_5 ++ )
F_54 ( V_2 , & V_79 -> V_106 [ V_5 ] ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_78 * V_79 = V_2 -> V_79 ;
for ( V_5 = 0 ; V_5 < V_79 -> V_81 ; V_5 ++ ) {
if ( F_26 ( V_2 , & V_79 -> V_29 [ V_5 ] , V_79 -> V_88 ,
V_217 ) )
goto V_218;
}
for ( V_5 = 0 ; V_5 < V_79 -> V_216 ; V_5 ++ ) {
if ( F_48 ( V_2 , & V_79 -> V_106 [ V_5 ] , V_79 -> V_198 , V_5 ) )
goto V_218;
}
for ( V_5 = 0 ; V_5 < V_79 -> V_215 ; V_5 ++ ) {
if ( F_45 ( V_2 , & V_79 -> V_99 [ V_5 ] , V_79 -> V_190 ) )
goto V_218;
}
return 0 ;
V_218:
F_78 ( V_2 ) ;
return - V_25 ;
}
int F_80 ( struct V_1 * V_2 )
{
struct V_78 * V_79 ;
V_79 = F_81 ( & V_2 -> V_21 -> V_22 , sizeof( * V_79 ) , V_24 ) ;
if ( ! V_79 )
return - V_25 ;
V_2 -> V_79 = V_79 ;
V_79 -> V_81 = V_219 ;
V_79 -> V_220 = F_82 ( T_4 , V_221 , F_83 () ) ;
V_79 -> V_216 = F_82 ( T_4 , V_113 , F_83 () ) ;
V_79 -> V_215 = F_84 ( T_4 , V_79 -> V_220 , V_79 -> V_216 ) ;
V_79 -> V_88 = V_222 ;
V_79 -> V_198 = V_223 ;
V_79 -> V_190 = V_224 ;
V_2 -> V_225 = V_79 -> V_220 ;
V_2 -> V_226 = V_79 -> V_216 ;
V_2 -> V_114 = 0 ;
return 0 ;
}
int F_85 ( struct V_1 * V_2 , bool V_70 )
{
bool V_227 = false ;
struct V_78 * V_79 = V_2 -> V_79 ;
struct V_78 * V_228 = V_2 -> V_38 -> V_79 ;
int V_5 ;
if ( ! V_79 )
return 0 ;
if ( V_2 -> V_111 && V_228 ) {
V_79 -> V_190 = V_228 -> V_190 ;
V_79 -> V_198 = V_228 -> V_198 ;
}
if ( V_70 ) {
if ( F_79 ( V_2 ) )
return - V_25 ;
for ( V_5 = 0 ; V_5 < V_79 -> V_216 ; V_5 ++ )
F_70 ( V_2 , V_79 , V_5 , V_70 ) ;
for ( V_5 = 0 ; V_5 < V_79 -> V_215 ; V_5 ++ )
F_67 ( V_2 , V_79 , V_5 , V_70 ) ;
for ( V_5 = 0 ; V_5 < V_79 -> V_81 ; V_5 ++ )
F_74 ( V_2 , V_79 , V_5 , V_70 ) ;
for ( V_5 = 0 ; V_5 < V_79 -> V_220 ; V_5 ++ )
F_64 ( V_2 , V_79 , V_5 , V_70 ) ;
} else {
for ( V_5 = 0 ; V_5 < V_79 -> V_220 ; V_5 ++ )
F_64 ( V_2 , V_79 , V_5 , V_227 ) ;
for ( V_5 = 0 ; V_5 < V_79 -> V_81 ; V_5 ++ )
F_74 ( V_2 , V_79 , V_5 , V_227 ) ;
for ( V_5 = 0 ; V_5 < V_79 -> V_216 ; V_5 ++ )
F_70 ( V_2 , V_79 , V_5 , V_227 ) ;
for ( V_5 = 0 ; V_5 < V_79 -> V_215 ; V_5 ++ )
F_67 ( V_2 , V_79 , V_5 , V_227 ) ;
F_78 ( V_2 ) ;
}
F_63 ( V_2 ) ;
return 0 ;
}
static inline int F_86 ( struct V_105 * V_106 , int V_229 )
{
int V_230 ;
V_230 = V_106 -> V_74 ;
if ( ! V_106 -> V_35 )
F_87 ( V_229 , & V_106 -> V_118 ) ;
else
V_106 -> V_117 -= V_229 ;
V_106 -> V_74 += V_229 ;
V_106 -> V_74 &= ( V_106 -> V_15 . V_16 - 1 ) ;
return V_230 ;
}
static inline void F_88 ( struct V_105 * V_106 ,
int V_230 , int V_229 )
{
V_106 -> V_74 = V_230 ;
F_89 ( V_229 , & V_106 -> V_118 ) ;
}
void F_90 ( struct V_105 * V_106 , int V_229 )
{
if ( ! V_106 -> V_35 )
F_89 ( V_229 , & V_106 -> V_118 ) ;
else
V_106 -> V_117 += V_229 ;
V_106 -> V_73 += V_229 ;
V_106 -> V_73 &= ( V_106 -> V_15 . V_16 - 1 ) ;
}
static inline int F_91 ( struct V_105 * V_106 , int V_230 )
{
V_230 ++ ;
V_230 &= ( V_106 -> V_15 . V_16 - 1 ) ;
return V_230 ;
}
void F_92 ( struct V_1 * V_2 , struct V_105 * V_106 , int V_5 )
{
T_1 V_193 ;
V_193 = F_4 ( V_2 , V_133 , V_5 ) ;
V_193 |= V_231 ;
F_37 ( V_2 , V_133 , V_5 , V_193 ) ;
F_37 ( V_2 , V_232 , V_5 , 0 ) ;
}
void F_93 ( struct V_1 * V_2 , int V_5 )
{
T_1 V_193 ;
V_193 = F_4 ( V_2 , V_133 , V_5 ) ;
V_193 &= ~ V_231 ;
F_37 ( V_2 , V_133 , V_5 , V_193 ) ;
}
void F_94 ( struct V_233 * V_13 , struct V_105 * V_106 ,
int V_5 )
{
T_1 V_73 , V_74 ;
struct V_56 * V_60 ;
struct V_1 * V_2 = F_95 ( V_13 ) ;
struct V_128 * V_129 ;
V_73 = F_4 ( V_2 , V_234 , V_5 ) >> 4 ;
V_74 = F_4 ( V_2 , V_235 , V_5 ) >> 4 ;
while ( V_106 -> V_73 != V_73 ) {
V_129 = (struct V_128 * ) F_53 ( V_106 , V_106 -> V_73 ) ;
if ( V_129 -> V_236 != V_237 ) {
F_90 ( V_106 , 1 ) ;
continue;
}
V_60 = (struct V_56 * ) V_106 -> V_109 [ V_106 -> V_73 ] ;
if ( V_60 )
F_55 ( V_60 ) ;
F_96 ( 1 , ( V_238 * ) & V_13 -> V_239 . V_240 ) ;
F_96 ( V_129 -> V_241 ,
( V_238 * ) & V_13 -> V_239 . V_242 ) ;
F_90 ( V_106 , V_129 -> V_123 + 1 ) ;
}
}
void F_97 ( struct V_1 * V_2 ,
struct V_105 * V_106 , int V_195 )
{
if ( ! V_106 -> V_116 )
return;
F_98 () ;
F_37 ( V_2 , V_232 ,
V_195 , V_106 -> V_116 ) ;
V_106 -> V_116 = 0 ;
}
static inline void
F_99 ( struct V_105 * V_106 , int V_230 ,
int V_123 , T_1 V_59 , int V_58 )
{
struct V_128 * V_129 ;
V_129 = (struct V_128 * ) F_53 ( V_106 , V_230 ) ;
memset ( V_129 , 0 , V_107 ) ;
V_129 -> V_236 = V_237 ;
V_129 -> V_123 = V_123 ;
V_129 -> V_241 = V_58 ;
V_129 -> V_243 = 1 ;
V_106 -> V_115 [ V_230 ] = ( T_1 ) F_25 ( ( void * ) V_59 ) ;
}
int F_100 ( struct V_1 * V_2 , struct V_105 * V_106 ,
T_1 V_244 , T_1 V_43 , T_6 V_58 )
{
int V_123 = V_245 ;
int V_230 ;
if ( V_123 > V_106 -> V_117 )
return 0 ;
V_230 = F_86 ( V_106 , V_123 ) ;
F_99 ( V_106 , V_230 , V_123 - 1 , V_244 , V_58 ) ;
V_230 = F_91 ( V_106 , V_230 ) ;
F_101 ( V_106 , V_230 , V_58 , V_43 ) ;
V_106 -> V_116 += V_123 ;
return 1 ;
}
static int F_102 ( struct V_56 * V_60 )
{
struct V_246 * V_247 = F_103 ( V_60 ) ;
unsigned int V_248 = F_104 ( V_60 ) + F_105 ( V_60 ) ;
unsigned int V_249 = V_60 -> V_58 - V_248 ;
unsigned int V_250 = V_247 -> V_251 ;
long V_252 = - 1 ;
long V_253 = F_106 ( V_60 ) - V_248 ;
long V_254 = 0 ;
long V_255 ;
int V_256 = 0 ;
int V_257 ;
for ( V_257 = 0 ; V_257 < V_247 -> V_258 ; V_257 ++ ) {
unsigned int V_259 = 0 ;
for ( V_256 ++ ; V_259 < V_250 ; V_256 ++ ) {
while ( V_254 >= V_253 ) {
V_252 ++ ;
V_253 = F_107 ( & V_247 -> V_260 [ V_252 ] ) ;
V_254 = 0 ;
}
V_255 = V_250 - V_259 ;
if ( V_255 > V_253 - V_254 )
V_255 = V_253 - V_254 ;
V_254 += V_255 ;
V_259 += V_255 ;
}
V_249 -= V_250 ;
if ( V_249 < V_250 )
V_250 = V_249 ;
}
return V_256 + V_247 -> V_258 ;
}
static int F_108 ( struct V_1 * V_2 , struct V_56 * V_60 )
{
int V_123 = V_245 ;
if ( F_103 ( V_60 ) -> V_251 && ! V_2 -> V_261 ) {
V_123 = F_102 ( V_60 ) ;
return V_123 ;
}
if ( V_2 -> V_262 && V_2 -> V_261 && F_103 ( V_60 ) -> V_251 )
V_123 += V_263 ;
if ( F_103 ( V_60 ) -> V_264 )
V_123 += F_103 ( V_60 ) -> V_264 ;
return V_123 ;
}
static inline void
F_109 ( struct V_1 * V_2 , struct V_105 * V_106 , int V_230 ,
int V_123 , struct V_56 * V_60 , int V_58 )
{
int V_265 ;
struct V_128 * V_129 ;
union {
struct V_266 * V_267 ;
struct V_268 * V_269 ;
unsigned char * V_129 ;
} V_270 ;
V_270 . V_129 = F_110 ( V_60 ) ;
V_129 = (struct V_128 * ) F_53 ( V_106 , V_230 ) ;
memset ( V_129 , 0 , V_107 ) ;
V_129 -> V_236 = V_237 ;
if ( V_2 -> V_262 && V_2 -> V_261 && F_103 ( V_60 ) -> V_251 ) {
V_129 -> V_123 = V_123 - V_263 ;
} else {
V_106 -> V_109 [ V_230 ] = ( T_1 ) V_60 ;
V_129 -> V_243 = 1 ;
V_129 -> V_123 = V_123 ;
}
V_129 -> V_241 = V_58 ;
if ( V_60 -> V_271 == V_272 ) {
V_129 -> V_273 = 1 ;
V_129 -> V_274 = F_111 ( V_60 ) ;
V_129 -> V_275 = F_104 ( V_60 ) ;
V_265 = ( V_270 . V_267 -> V_276 == 4 ) ? V_270 . V_267 -> V_277 :
V_270 . V_269 -> V_278 ;
switch ( V_265 ) {
case V_279 :
V_129 -> V_280 = V_281 ;
break;
case V_282 :
V_129 -> V_280 = V_283 ;
break;
case V_284 :
V_129 -> V_280 = V_285 ;
break;
}
}
if ( V_2 -> V_261 && F_103 ( V_60 ) -> V_251 ) {
V_129 -> V_286 = 1 ;
V_129 -> V_287 = F_104 ( V_60 ) + F_105 ( V_60 ) ;
V_129 -> V_288 = F_103 ( V_60 ) -> V_251 ;
V_129 -> V_289 = F_111 ( V_60 ) - 2 ;
F_15 ( V_2 -> V_38 -> V_39 -> V_290 ) ;
}
}
static inline void F_101 ( struct V_105 * V_106 , int V_230 ,
int V_19 , T_1 V_59 )
{
struct V_124 * V_125 ;
V_230 &= ( V_106 -> V_15 . V_16 - 1 ) ;
V_125 = (struct V_124 * ) F_53 ( V_106 , V_230 ) ;
memset ( V_125 , 0 , V_107 ) ;
V_125 -> V_236 = V_291 ;
V_125 -> V_292 = V_293 ;
V_125 -> V_19 = V_19 ;
V_125 -> V_126 = V_59 ;
}
static inline void F_112 ( struct V_105 * V_106 , int V_230 ,
int V_130 , struct V_56 * V_60 )
{
struct V_294 * V_295 ;
struct V_128 * V_129 ;
V_106 -> V_109 [ V_230 ] = ( T_1 ) V_60 ;
V_129 = (struct V_128 * ) F_53 ( V_106 , V_230 ) ;
memset ( V_129 , 0 , V_107 ) ;
V_129 -> V_236 = V_237 ;
V_129 -> V_243 = 1 ;
V_129 -> V_131 = 1 ;
V_129 -> V_123 = V_263 - 1 ;
V_129 -> V_241 = 1 ;
V_129 -> V_132 = V_130 ;
V_230 = F_91 ( V_106 , V_230 ) ;
V_295 = (struct V_294 * ) F_53 ( V_106 , V_230 ) ;
memset ( V_295 , 0 , V_107 ) ;
V_295 -> V_236 = V_296 ;
V_295 -> V_58 = 1 ;
}
static inline void F_113 ( struct V_1 * V_2 , struct V_56 * V_60 ,
int V_195 , int V_229 )
{
struct V_297 * V_298 ;
V_298 = F_114 ( V_2 -> V_38 -> V_13 ,
F_115 ( V_60 ) ) ;
F_116 ( V_298 , V_60 -> V_58 ) ;
F_36 () ;
F_37 ( V_2 , V_232 ,
V_195 , V_229 ) ;
}
static int F_117 ( struct V_1 * V_2 , struct V_105 * V_106 ,
int V_195 , int V_230 , struct V_56 * V_60 )
{
struct V_299 V_286 ;
int V_300 = 0 , V_229 = 0 ;
int V_301 , V_302 , V_303 ;
int V_304 = V_230 ;
int V_305 = F_104 ( V_60 ) + F_105 ( V_60 ) ;
V_287 ( V_60 , & V_286 ) ;
V_302 = V_60 -> V_58 - V_305 ;
while ( V_302 > 0 ) {
char * V_129 ;
V_304 = V_230 ;
V_303 = F_82 ( int , F_103 ( V_60 ) -> V_251 , V_302 ) ;
V_302 -= V_303 ;
V_230 = F_91 ( V_106 , V_230 ) ;
V_129 = V_106 -> V_119 + V_230 * V_120 ;
F_118 ( V_60 , V_129 , & V_286 , V_303 , V_302 == 0 ) ;
F_101 ( V_106 , V_230 , V_305 ,
V_106 -> V_121 +
V_230 * V_120 ) ;
V_300 = 2 ;
V_301 = V_305 ;
while ( V_303 > 0 ) {
int V_19 ;
V_19 = F_82 ( int , V_286 . V_19 , V_303 ) ;
V_230 = F_91 ( V_106 , V_230 ) ;
F_101 ( V_106 , V_230 , V_19 ,
F_119 ( V_286 . V_59 ) ) ;
V_300 ++ ;
V_301 += V_19 ;
V_303 -= V_19 ;
F_120 ( V_60 , & V_286 , V_19 ) ;
}
F_109 ( V_2 , V_106 , V_304 ,
V_300 - 1 , V_60 , V_301 ) ;
V_106 -> V_109 [ V_304 ] = ( T_1 ) NULL ;
V_230 = F_91 ( V_106 , V_230 ) ;
V_229 += V_300 ;
}
V_106 -> V_109 [ V_304 ] = ( T_1 ) V_60 ;
F_113 ( V_2 , V_60 , V_195 , V_229 ) ;
F_15 ( V_2 -> V_38 -> V_39 -> V_290 ) ;
return 1 ;
}
int F_121 ( struct V_1 * V_2 , struct V_105 * V_106 ,
struct V_56 * V_60 , T_4 V_195 )
{
int V_306 , V_19 ;
int V_123 , V_122 = 0 ;
int V_230 ;
T_1 V_43 ;
V_123 = F_108 ( V_2 , V_60 ) ;
if ( V_123 > F_122 ( & V_106 -> V_118 ) )
goto V_307;
V_230 = F_86 ( V_106 , V_123 ) ;
if ( F_103 ( V_60 ) -> V_251 && ! V_2 -> V_261 )
return F_117 ( V_2 , V_106 , V_195 , V_230 , V_60 ) ;
F_109 ( V_2 , V_106 , V_230 , V_123 - 1 ,
V_60 , V_60 -> V_58 ) ;
V_122 = V_230 ;
V_230 = F_91 ( V_106 , V_230 ) ;
V_19 = F_123 ( V_60 ) ? F_106 ( V_60 ) : V_60 -> V_58 ;
V_43 = F_18 ( & V_2 -> V_21 -> V_22 , F_25 ( V_60 -> V_59 ) ,
F_124 ( V_60 -> V_59 ) , V_19 ,
V_127 , V_54 ) ;
if ( F_19 ( & V_2 -> V_21 -> V_22 , V_43 ) ) {
F_88 ( V_106 , V_230 , V_123 ) ;
return 0 ;
}
F_101 ( V_106 , V_230 , V_19 , V_43 ) ;
if ( ! F_123 ( V_60 ) )
goto V_308;
for ( V_306 = 0 ; V_306 < F_103 ( V_60 ) -> V_264 ; V_306 ++ ) {
const struct V_309 * V_310 ;
V_310 = & F_103 ( V_60 ) -> V_260 [ V_306 ] ;
V_230 = F_91 ( V_106 , V_230 ) ;
V_19 = F_107 ( V_310 ) ;
V_43 = F_18 ( & V_2 -> V_21 -> V_22 ,
F_125 ( V_310 ) ,
V_310 -> V_311 , V_19 ,
V_127 ,
V_54 ) ;
if ( F_19 ( & V_2 -> V_21 -> V_22 , V_43 ) ) {
F_52 ( V_2 , V_106 , V_122 , V_306 ) ;
F_88 ( V_106 , V_230 , V_123 ) ;
return 0 ;
}
F_101 ( V_106 , V_230 , V_19 , V_43 ) ;
}
V_308:
if ( V_2 -> V_262 && F_103 ( V_60 ) -> V_251 ) {
V_230 = F_91 ( V_106 , V_230 ) ;
F_112 ( V_106 , V_230 , V_122 , V_60 ) ;
}
F_113 ( V_2 , V_60 , V_195 , V_123 ) ;
return 1 ;
V_307:
V_2 = V_2 -> V_38 ;
F_126 ( V_2 -> V_13 , L_4 ) ;
return 0 ;
}
static inline unsigned F_127 ( unsigned V_306 )
{
#ifdef F_77
return ( V_306 & ~ 3 ) + 3 - ( V_306 & 3 ) ;
#else
return V_306 ;
#endif
}
static void F_128 ( struct V_1 * V_2 , T_1 V_43 ,
T_1 V_76 , bool V_312 )
{
struct V_32 * V_32 = NULL ;
int V_58 = V_61 ;
if ( V_312 ) {
V_32 = F_25 ( F_22 ( V_76 ) ) ;
if ( F_13 ( V_32 ) != 1 )
return;
V_58 += V_52 ;
V_43 &= V_313 ;
}
F_32 ( & V_2 -> V_21 -> V_22 , V_43 , V_58 ,
V_53 , V_54 ) ;
}
struct V_56 * F_129 ( struct V_1 * V_2 ,
struct V_314 * V_315 , bool V_312 )
{
int V_310 ;
int V_316 = 0 ;
struct V_56 * V_60 = NULL ;
struct V_32 * V_32 ;
int V_317 ;
T_6 * V_318 = NULL ;
T_1 * V_319 = NULL ;
T_1 V_77 ;
V_318 = ( void * ) V_315 + ( 3 * sizeof( T_1 ) ) ;
if ( ! V_2 -> V_261 )
V_319 = ( void * ) V_315 + ( 6 * sizeof( T_1 ) ) ;
else
V_319 = ( void * ) V_315 + ( 7 * sizeof( T_1 ) ) ;
for ( V_310 = 0 ; V_310 < V_315 -> V_320 ; V_310 ++ ) {
V_316 = V_318 [ F_127 ( V_310 ) ] ;
V_77 = F_31 ( V_2 , * V_319 ) ;
if ( ! V_77 ) {
if ( V_60 )
F_55 ( V_60 ) ;
return NULL ;
}
if ( ! V_310 ) {
F_128 ( V_2 ,
* V_319 - V_315 -> V_321 ,
V_77 , V_312 ) ;
V_60 = F_21 ( V_2 ,
V_77 - V_315 -> V_321 ,
V_316 ) ;
if ( ! V_60 )
return NULL ;
F_130 ( V_60 , V_315 -> V_321 ) ;
F_131 ( V_60 , V_316 ) ;
} else {
F_128 ( V_2 , * V_319 , V_77 , V_312 ) ;
V_32 = F_25 ( F_22 ( V_77 ) ) ;
V_317 = F_22 ( V_77 ) - F_132 ( V_32 ) ;
F_133 ( V_60 , F_103 ( V_60 ) -> V_264 , V_32 ,
V_317 , V_316 , V_61 ) ;
}
V_319 ++ ;
}
return V_60 ;
}
static T_1 F_134 ( int V_322 , int V_323 )
{
T_1 V_11 ;
switch ( V_322 ) {
case V_324 :
V_11 = ( ( 1ULL << V_323 ) << V_325 ) ;
break;
case V_326 :
V_11 = ( ( 1ULL << V_323 ) << V_327 ) ;
break;
case V_92 :
V_11 = ( ( 1ULL << V_323 ) << V_328 ) ;
break;
case V_329 :
V_11 = ( 1ULL << V_330 ) ;
break;
case V_331 :
V_11 = ( 1ULL << V_332 ) ;
break;
case V_333 :
V_11 = ( 1ULL << V_334 ) ;
break;
case V_335 :
V_11 = ( 1ULL << V_336 ) ;
break;
default:
V_11 = 0 ;
}
return V_11 ;
}
void F_39 ( struct V_1 * V_2 , int V_322 , int V_323 )
{
T_1 V_337 = F_134 ( V_322 , V_323 ) ;
if ( ! V_337 ) {
F_126 ( V_2 -> V_13 ,
L_5 ) ;
return;
}
F_135 ( V_2 , V_338 ,
F_136 ( V_2 , V_338 ) | V_337 ) ;
}
void F_137 ( struct V_1 * V_2 , int V_322 , int V_323 )
{
T_1 V_337 = F_134 ( V_322 , V_323 ) ;
if ( ! V_337 ) {
F_126 ( V_2 -> V_13 ,
L_6 ) ;
return;
}
F_135 ( V_2 , V_339 , V_337 ) ;
}
void F_138 ( struct V_1 * V_2 , int V_322 , int V_323 )
{
T_1 V_337 = F_134 ( V_322 , V_323 ) ;
if ( ! V_337 ) {
F_126 ( V_2 -> V_13 ,
L_7 ) ;
return;
}
F_135 ( V_2 , V_340 , V_337 ) ;
}
int F_139 ( struct V_1 * V_2 , int V_322 , int V_323 )
{
T_1 V_337 = F_134 ( V_322 , V_323 ) ;
if ( ! V_337 ) {
F_126 ( V_2 -> V_13 ,
L_8 ) ;
return 0 ;
}
return V_337 & F_136 ( V_2 , V_338 ) ;
}
void F_140 ( struct V_1 * V_2 , int V_341 )
{
struct V_162 * V_163 ;
#define F_141 ( V_6 ) \
nicvf_reg_read(nic, NIC_QSET_RQ_0_7_STAT_0_1 |\
(rq_idx << NIC_Q_NUM_SHIFT) | (reg << 3))
V_163 = & V_2 -> V_79 -> V_163 [ V_341 ] ;
V_163 -> V_239 . V_342 = F_141 ( V_343 ) ;
V_163 -> V_239 . V_344 = F_141 ( V_345 ) ;
}
void F_142 ( struct V_1 * V_2 , int V_346 )
{
struct V_105 * V_106 ;
#define F_143 ( V_6 ) \
nicvf_reg_read(nic, NIC_QSET_SQ_0_7_STAT_0_1 |\
(sq_idx << NIC_Q_NUM_SHIFT) | (reg << 3))
V_106 = & V_2 -> V_79 -> V_106 [ V_346 ] ;
V_106 -> V_239 . V_342 = F_143 ( V_343 ) ;
V_106 -> V_239 . V_344 = F_143 ( V_345 ) ;
}
int F_144 ( struct V_1 * V_2 , struct V_314 * V_315 )
{
F_145 ( V_2 , V_347 , V_2 -> V_13 ,
L_9 ,
V_315 -> V_348 , V_315 -> V_349 ) ;
switch ( V_315 -> V_349 ) {
case V_350 :
F_15 ( V_2 -> V_39 -> V_351 ) ;
break;
case V_352 :
F_15 ( V_2 -> V_39 -> V_353 ) ;
break;
case V_354 :
F_15 ( V_2 -> V_39 -> V_355 ) ;
break;
case V_356 :
F_15 ( V_2 -> V_39 -> V_357 ) ;
break;
case V_358 :
F_15 ( V_2 -> V_39 -> V_359 ) ;
break;
case V_360 :
F_15 ( V_2 -> V_39 -> V_361 ) ;
break;
case V_362 :
F_15 ( V_2 -> V_39 -> V_363 ) ;
break;
case V_364 :
F_15 ( V_2 -> V_39 -> V_365 ) ;
break;
case V_366 :
F_15 ( V_2 -> V_39 -> V_367 ) ;
break;
case V_368 :
F_15 ( V_2 -> V_39 -> V_369 ) ;
break;
case V_370 :
F_15 ( V_2 -> V_39 -> V_371 ) ;
break;
case V_372 :
F_15 ( V_2 -> V_39 -> V_373 ) ;
break;
case V_374 :
F_15 ( V_2 -> V_39 -> V_375 ) ;
break;
case V_376 :
F_15 ( V_2 -> V_39 -> V_377 ) ;
break;
case V_378 :
F_15 ( V_2 -> V_39 -> V_379 ) ;
break;
case V_380 :
F_15 ( V_2 -> V_39 -> V_381 ) ;
break;
case V_382 :
F_15 ( V_2 -> V_39 -> V_383 ) ;
break;
case V_384 :
F_15 ( V_2 -> V_39 -> V_385 ) ;
break;
case V_386 :
F_15 ( V_2 -> V_39 -> V_387 ) ;
break;
case V_388 :
F_15 ( V_2 -> V_39 -> V_389 ) ;
break;
case V_390 :
F_15 ( V_2 -> V_39 -> V_391 ) ;
break;
case V_392 :
F_15 ( V_2 -> V_39 -> V_393 ) ;
break;
case V_394 :
F_15 ( V_2 -> V_39 -> V_395 ) ;
break;
case V_396 :
F_15 ( V_2 -> V_39 -> V_397 ) ;
break;
}
return 1 ;
}
int F_146 ( struct V_1 * V_2 , struct V_398 * V_399 )
{
switch ( V_399 -> V_400 ) {
case V_401 :
F_15 ( V_2 -> V_39 -> V_402 ) ;
break;
case V_403 :
F_15 ( V_2 -> V_39 -> V_404 ) ;
break;
case V_405 :
F_15 ( V_2 -> V_39 -> V_406 ) ;
break;
case V_407 :
F_15 ( V_2 -> V_39 -> V_408 ) ;
break;
case V_409 :
F_15 ( V_2 -> V_39 -> V_410 ) ;
break;
case V_411 :
F_15 ( V_2 -> V_39 -> V_412 ) ;
break;
case V_413 :
F_15 ( V_2 -> V_39 -> V_414 ) ;
break;
case V_415 :
F_15 ( V_2 -> V_39 -> V_416 ) ;
break;
case V_417 :
F_15 ( V_2 -> V_39 -> V_418 ) ;
break;
case V_419 :
F_15 ( V_2 -> V_39 -> V_420 ) ;
break;
case V_421 :
F_15 ( V_2 -> V_39 -> V_422 ) ;
break;
case V_423 :
F_15 ( V_2 -> V_39 -> V_424 ) ;
break;
case V_425 :
F_15 ( V_2 -> V_39 -> V_426 ) ;
break;
case V_427 :
F_15 ( V_2 -> V_39 -> V_428 ) ;
break;
}
return 1 ;
}

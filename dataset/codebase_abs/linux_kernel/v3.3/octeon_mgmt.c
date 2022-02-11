static void F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = V_2 -> V_4 ;
union V_5 V_6 ;
unsigned long V_7 ;
F_2 ( & V_2 -> V_8 , V_7 ) ;
V_6 . V_9 = F_3 ( F_4 ( V_4 ) ) ;
V_6 . V_10 . V_11 = V_3 ? 1 : 0 ;
F_5 ( F_4 ( V_4 ) , V_6 . V_9 ) ;
F_6 ( & V_2 -> V_8 , V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = V_2 -> V_4 ;
union V_5 V_6 ;
unsigned long V_7 ;
F_2 ( & V_2 -> V_8 , V_7 ) ;
V_6 . V_9 = F_3 ( F_4 ( V_4 ) ) ;
V_6 . V_10 . V_12 = V_3 ? 1 : 0 ;
F_5 ( F_4 ( V_4 ) , V_6 . V_9 ) ;
F_6 ( & V_2 -> V_8 , V_7 ) ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 1 ) ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0 ) ;
}
static inline void F_10 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 1 ) ;
}
static inline void F_11 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 0 ) ;
}
static unsigned int F_12 ( unsigned int V_13 )
{
return V_13 - 8 ;
}
static unsigned int F_13 ( unsigned int V_13 )
{
return V_13 * sizeof( union V_14 ) ;
}
static void F_14 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
int V_4 = V_2 -> V_4 ;
while ( V_2 -> V_17 < F_12 ( V_18 ) ) {
unsigned int V_19 ;
union V_14 V_20 ;
struct V_21 * V_22 ;
V_19 = V_16 -> V_23 + V_24 + 8 + V_25 ;
V_22 = F_16 ( V_16 , V_19 ) ;
if ( ! V_22 )
break;
F_17 ( V_22 , V_25 ) ;
F_18 ( & V_2 -> V_26 , V_22 ) ;
V_20 . V_27 = 0 ;
V_20 . V_10 . V_28 = V_19 ;
V_20 . V_10 . V_29 = F_19 ( V_2 -> V_30 , V_22 -> V_31 ,
V_19 ,
V_32 ) ;
V_2 -> V_33 [ V_2 -> V_34 ] = V_20 . V_27 ;
F_20 ( V_2 -> V_30 , V_2 -> V_35 ,
F_13 ( V_18 ) ,
V_36 ) ;
V_2 -> V_34 =
( V_2 -> V_34 + 1 ) % V_18 ;
V_2 -> V_17 ++ ;
F_5 ( F_21 ( V_4 ) , 1 ) ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
int V_4 = V_2 -> V_4 ;
union V_37 V_38 ;
union V_14 V_20 ;
struct V_21 * V_22 ;
int V_39 = 0 ;
unsigned long V_7 ;
V_38 . V_9 = F_3 ( F_23 ( V_4 ) ) ;
while ( V_38 . V_10 . V_40 ) {
F_2 ( & V_2 -> V_41 . V_8 , V_7 ) ;
V_38 . V_9 = F_3 ( F_23 ( V_4 ) ) ;
if ( V_38 . V_10 . V_40 == 0 ) {
F_6 ( & V_2 -> V_41 . V_8 , V_7 ) ;
break;
}
F_24 ( V_2 -> V_30 , V_2 -> V_42 ,
F_13 ( V_43 ) ,
V_36 ) ;
V_20 . V_27 = V_2 -> V_44 [ V_2 -> V_45 ] ;
V_2 -> V_45 =
( V_2 -> V_45 + 1 ) % V_43 ;
V_22 = F_25 ( & V_2 -> V_41 ) ;
V_38 . V_9 = 0 ;
V_38 . V_10 . V_40 = 1 ;
F_5 ( F_23 ( V_4 ) , V_38 . V_9 ) ;
V_2 -> V_46 -- ;
F_6 ( & V_2 -> V_41 . V_8 , V_7 ) ;
F_26 ( V_2 -> V_30 , V_20 . V_10 . V_29 , V_20 . V_10 . V_28 ,
V_47 ) ;
F_27 ( V_22 ) ;
V_39 ++ ;
V_38 . V_9 = F_3 ( F_23 ( V_4 ) ) ;
}
if ( V_39 && F_28 ( V_2 -> V_16 ) )
F_29 ( V_2 -> V_16 ) ;
}
static void F_30 ( unsigned long V_48 )
{
struct V_1 * V_2 = (struct V_1 * ) V_48 ;
F_22 ( V_2 ) ;
F_10 ( V_2 ) ;
}
static void F_31 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
int V_4 = V_2 -> V_4 ;
unsigned long V_7 ;
V_9 V_49 , V_50 ;
V_49 = F_3 ( F_32 ( V_4 ) ) ;
V_50 = F_3 ( F_33 ( V_4 ) ) ;
if ( V_49 || V_50 ) {
F_2 ( & V_2 -> V_8 , V_7 ) ;
V_16 -> V_51 . V_52 += V_50 ;
V_16 -> V_51 . V_53 += V_49 ;
F_6 ( & V_2 -> V_8 , V_7 ) ;
}
}
static void F_34 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
int V_4 = V_2 -> V_4 ;
unsigned long V_7 ;
union V_54 V_55 ;
union V_56 V_57 ;
V_55 . V_9 = F_3 ( F_35 ( V_4 ) ) ;
V_57 . V_9 = F_3 ( F_36 ( V_4 ) ) ;
if ( V_55 . V_10 . V_58 || V_55 . V_10 . V_59 || V_57 . V_10 . V_60 || V_57 . V_10 . V_61 ) {
F_2 ( & V_2 -> V_8 , V_7 ) ;
V_16 -> V_51 . V_62 += V_55 . V_10 . V_58 + V_55 . V_10 . V_59 ;
V_16 -> V_51 . V_63 += V_57 . V_10 . V_60 + V_57 . V_10 . V_61 ;
F_6 ( & V_2 -> V_8 , V_7 ) ;
}
}
static V_9 F_37 ( struct V_1 * V_2 ,
struct V_21 * * V_64 )
{
union V_14 V_20 ;
F_24 ( V_2 -> V_30 , V_2 -> V_35 ,
F_13 ( V_18 ) ,
V_36 ) ;
V_20 . V_27 = V_2 -> V_33 [ V_2 -> V_65 ] ;
V_2 -> V_65 = ( V_2 -> V_65 + 1 ) % V_18 ;
V_2 -> V_17 -- ;
* V_64 = F_25 ( & V_2 -> V_26 ) ;
F_26 ( V_2 -> V_30 , V_20 . V_10 . V_29 ,
V_66 + V_24 ,
V_32 ) ;
return V_20 . V_27 ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_4 = V_2 -> V_4 ;
struct V_15 * V_16 = V_2 -> V_16 ;
union V_67 V_68 ;
union V_14 V_20 ;
struct V_21 * V_22 ;
struct V_21 * V_69 ;
struct V_21 * V_70 ;
union V_14 V_71 ;
int V_72 = 1 ;
V_20 . V_27 = F_37 ( V_2 , & V_22 ) ;
if ( F_39 ( V_20 . V_10 . V_73 == V_74 ) ) {
F_40 ( V_22 , V_20 . V_10 . V_28 ) ;
V_75:
V_22 -> V_76 = F_41 ( V_22 , V_16 ) ;
V_16 -> V_51 . V_77 ++ ;
V_16 -> V_51 . V_78 += V_22 -> V_28 ;
F_42 ( V_22 ) ;
V_72 = 0 ;
} else if ( V_20 . V_10 . V_73 == V_79 ) {
F_40 ( V_22 , V_20 . V_10 . V_28 ) ;
do {
V_71 . V_27 = F_37 ( V_2 , & V_69 ) ;
if ( V_71 . V_10 . V_73 != V_79
&& V_71 . V_10 . V_73 != V_74 )
goto V_80;
F_40 ( V_69 , V_71 . V_10 . V_28 ) ;
V_70 = F_43 ( V_22 , 0 , V_69 -> V_28 ,
V_81 ) ;
if ( ! V_70 )
goto V_80;
if ( F_44 ( V_69 , 0 , F_45 ( V_70 ) ,
V_69 -> V_28 ) )
goto V_80;
F_40 ( V_70 , V_69 -> V_28 ) ;
F_27 ( V_22 ) ;
F_27 ( V_69 ) ;
V_22 = V_70 ;
} while ( V_71 . V_10 . V_73 == V_79 );
goto V_75;
} else {
F_27 ( V_22 ) ;
}
goto V_82;
V_80:
F_27 ( V_22 ) ;
F_27 ( V_69 ) ;
while ( V_71 . V_10 . V_73 == V_79 ) {
V_71 . V_27 = F_37 ( V_2 , & V_69 ) ;
F_27 ( V_69 ) ;
}
V_16 -> V_51 . V_52 ++ ;
V_82:
V_68 . V_9 = 0 ;
V_68 . V_10 . V_83 = 1 ;
F_5 ( F_46 ( V_4 ) , V_68 . V_9 ) ;
return V_72 ;
}
static int F_47 ( struct V_1 * V_2 , int V_84 )
{
int V_4 = V_2 -> V_4 ;
unsigned int V_85 = 0 ;
union V_67 V_68 ;
int V_72 ;
V_68 . V_9 = F_3 ( F_46 ( V_4 ) ) ;
while ( V_85 < V_84 && V_68 . V_10 . V_83 ) {
V_72 = F_38 ( V_2 ) ;
if ( ! V_72 )
V_85 ++ ;
V_68 . V_9 = F_3 ( F_46 ( V_4 ) ) ;
}
F_14 ( V_2 -> V_16 ) ;
return V_85 ;
}
static int F_48 ( struct V_86 * V_87 , int V_84 )
{
struct V_1 * V_2 = F_49 ( V_87 , struct V_1 , V_87 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
unsigned int V_85 = 0 ;
V_85 = F_47 ( V_2 , V_84 ) ;
if ( V_85 < V_84 ) {
F_50 ( V_87 ) ;
F_8 ( V_2 ) ;
}
F_31 ( V_16 ) ;
return V_85 ;
}
static void F_51 ( struct V_1 * V_2 )
{
union V_88 V_89 ;
union V_90 V_91 ;
union V_92 V_93 ;
V_89 . V_9 = 0 ;
F_5 ( F_52 ( V_2 -> V_4 ) , V_89 . V_9 ) ;
do {
V_89 . V_9 = F_3 ( F_52 ( V_2 -> V_4 ) ) ;
} while ( V_89 . V_10 . V_94 );
V_89 . V_10 . V_95 = 1 ;
F_5 ( F_52 ( V_2 -> V_4 ) , V_89 . V_9 ) ;
F_3 ( F_52 ( V_2 -> V_4 ) ) ;
F_53 ( 64 ) ;
V_91 . V_9 = F_3 ( F_54 ( V_2 -> V_4 ) ) ;
if ( V_91 . V_9 )
F_55 ( V_2 -> V_30 , L_1 ,
( unsigned long long ) V_91 . V_9 ) ;
V_93 . V_9 = F_3 ( V_96 ) ;
if ( V_93 . V_9 )
F_55 ( V_2 -> V_30 , L_2 ,
( unsigned long long ) V_93 . V_9 ) ;
}
static void F_56 ( struct V_97 * V_98 ,
unsigned char * V_29 )
{
int V_99 ;
for ( V_99 = 0 ; V_99 < 6 ; V_99 ++ )
V_98 -> V_100 [ V_99 ] |= ( V_9 ) V_29 [ V_99 ] << ( 8 * ( V_98 -> V_101 ) ) ;
V_98 -> V_102 |= ( 1ULL << V_98 -> V_101 ) ;
V_98 -> V_101 ++ ;
}
static void F_57 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
int V_4 = V_2 -> V_4 ;
union V_103 V_104 ;
union V_105 V_106 ;
unsigned long V_7 ;
unsigned int V_107 ;
unsigned int V_108 = 1 ;
unsigned int V_109 = 1 ;
struct V_97 V_110 ;
struct V_111 * V_112 ;
int V_113 ;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
if ( ( V_16 -> V_7 & V_114 ) || V_16 -> V_115 . V_116 > 7 ) {
V_108 = 0 ;
V_113 = 8 ;
} else {
V_113 = 7 - V_16 -> V_115 . V_116 ;
}
if ( V_16 -> V_7 & V_117 ) {
if ( V_108 == 0 || ( V_16 -> V_7 & V_118 ) ||
F_58 ( V_16 ) > V_113 )
V_109 = 2 ;
else
V_109 = 0 ;
}
if ( V_108 == 1 ) {
F_56 ( & V_110 , V_16 -> V_119 ) ;
F_59 (ha, netdev)
F_56 ( & V_110 , V_112 -> V_29 ) ;
}
if ( V_109 == 0 ) {
F_60 (ha, netdev)
F_56 ( & V_110 , V_112 -> V_29 ) ;
}
F_2 ( & V_2 -> V_8 , V_7 ) ;
V_106 . V_9 = F_3 ( F_61 ( V_4 ) ) ;
V_107 = V_106 . V_10 . V_120 ;
V_106 . V_10 . V_120 = 0 ;
F_5 ( F_61 ( V_4 ) , V_106 . V_9 ) ;
V_104 . V_9 = 0 ;
V_104 . V_10 . V_108 = V_108 ;
V_104 . V_10 . V_121 = V_109 ;
V_104 . V_10 . V_122 = 1 ;
F_5 ( F_62 ( V_4 ) , V_104 . V_9 ) ;
F_5 ( F_63 ( V_4 ) , V_110 . V_100 [ 0 ] ) ;
F_5 ( F_64 ( V_4 ) , V_110 . V_100 [ 1 ] ) ;
F_5 ( F_65 ( V_4 ) , V_110 . V_100 [ 2 ] ) ;
F_5 ( F_66 ( V_4 ) , V_110 . V_100 [ 3 ] ) ;
F_5 ( F_67 ( V_4 ) , V_110 . V_100 [ 4 ] ) ;
F_5 ( F_68 ( V_4 ) , V_110 . V_100 [ 5 ] ) ;
F_5 ( F_69 ( V_4 ) , V_110 . V_102 ) ;
V_106 . V_10 . V_120 = V_107 ;
F_5 ( F_61 ( V_4 ) , V_106 . V_9 ) ;
F_6 ( & V_2 -> V_8 , V_7 ) ;
}
static int F_70 ( struct V_15 * V_16 , void * V_29 )
{
struct V_123 * V_124 = V_29 ;
if ( ! F_71 ( V_124 -> V_125 ) )
return - V_126 ;
memcpy ( V_16 -> V_119 , V_124 -> V_125 , V_127 ) ;
F_57 ( V_16 ) ;
return 0 ;
}
static int F_72 ( struct V_15 * V_16 , int V_128 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
int V_4 = V_2 -> V_4 ;
int V_129 = V_128 + V_24 ;
if ( V_129 < 64 || V_129 > 16383 ) {
F_55 ( V_2 -> V_30 , L_3 ,
64 - V_24 ,
16383 - V_24 ) ;
return - V_130 ;
}
V_16 -> V_23 = V_128 ;
F_5 ( F_73 ( V_4 ) , V_129 ) ;
F_5 ( F_74 ( V_4 ) ,
( V_129 + 7 ) & 0xfff8 ) ;
return 0 ;
}
static T_1 F_75 ( int V_131 , void * V_132 )
{
struct V_15 * V_16 = V_132 ;
struct V_1 * V_2 = F_15 ( V_16 ) ;
int V_4 = V_2 -> V_4 ;
union V_133 V_134 ;
V_134 . V_9 = F_3 ( F_76 ( V_4 ) ) ;
F_5 ( F_76 ( V_4 ) , V_134 . V_9 ) ;
F_3 ( F_76 ( V_4 ) ) ;
if ( V_134 . V_10 . V_135 ) {
F_9 ( V_2 ) ;
F_77 ( & V_2 -> V_87 ) ;
}
if ( V_134 . V_10 . V_136 ) {
F_11 ( V_2 ) ;
F_78 ( & V_2 -> V_137 ) ;
}
return V_138 ;
}
static int F_79 ( struct V_15 * V_16 ,
struct V_139 * V_140 , int V_141 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
if ( ! F_80 ( V_16 ) )
return - V_130 ;
if ( ! V_2 -> V_142 )
return - V_130 ;
return F_81 ( V_2 -> V_142 , V_140 , V_141 ) ;
}
static void F_82 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
int V_4 = V_2 -> V_4 ;
union V_105 V_143 ;
unsigned long V_7 ;
int V_144 = 0 ;
F_2 ( & V_2 -> V_8 , V_7 ) ;
if ( V_2 -> V_142 -> V_145 ) {
if ( ! V_2 -> V_146 )
V_144 = 1 ;
if ( V_2 -> V_147 != V_2 -> V_142 -> V_148 ) {
V_2 -> V_147 = V_2 -> V_142 -> V_148 ;
V_143 . V_9 =
F_3 ( F_61 ( V_4 ) ) ;
V_143 . V_10 . V_148 = V_2 -> V_142 -> V_148 ;
F_5 ( F_61 ( V_4 ) ,
V_143 . V_9 ) ;
}
} else {
if ( V_2 -> V_146 )
V_144 = - 1 ;
}
V_2 -> V_146 = V_2 -> V_142 -> V_145 ;
F_6 ( & V_2 -> V_8 , V_7 ) ;
if ( V_144 != 0 ) {
if ( V_144 > 0 ) {
F_83 ( V_16 ) ;
F_84 ( L_4 , V_16 -> V_149 ,
V_2 -> V_142 -> V_150 ,
V_151 == V_2 -> V_142 -> V_148 ?
L_5 : L_6 ) ;
} else {
F_85 ( V_16 ) ;
F_84 ( L_7 , V_16 -> V_149 ) ;
}
}
}
static int F_86 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
char V_152 [ V_153 + 3 ] ;
if ( F_87 () ) {
F_83 ( V_16 ) ;
return 0 ;
}
snprintf ( V_152 , sizeof( V_152 ) , V_154 , L_8 , V_2 -> V_4 ) ;
V_2 -> V_142 = F_88 ( V_16 , V_152 , F_82 , 0 ,
V_155 ) ;
if ( F_89 ( V_2 -> V_142 ) ) {
V_2 -> V_142 = NULL ;
return - 1 ;
}
F_90 ( V_2 -> V_142 ) ;
return 0 ;
}
static int F_91 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
int V_4 = V_2 -> V_4 ;
union V_88 V_89 ;
union V_156 V_157 ;
union V_158 V_159 ;
union V_160 V_161 ;
union V_105 V_143 ;
union V_162 V_163 ;
union V_164 V_165 ;
union V_166 V_167 ;
union V_5 V_6 ;
struct V_123 V_124 ;
V_2 -> V_44 = F_92 ( F_13 ( V_43 ) ,
V_168 ) ;
if ( ! V_2 -> V_44 )
return - V_169 ;
V_2 -> V_42 =
F_19 ( V_2 -> V_30 , V_2 -> V_44 ,
F_13 ( V_43 ) ,
V_36 ) ;
V_2 -> V_170 = 0 ;
V_2 -> V_45 = 0 ;
V_2 -> V_46 = 0 ;
V_2 -> V_33 = F_92 ( F_13 ( V_18 ) ,
V_168 ) ;
if ( ! V_2 -> V_33 )
goto V_171;
V_2 -> V_35 =
F_19 ( V_2 -> V_30 , V_2 -> V_33 ,
F_13 ( V_18 ) ,
V_36 ) ;
V_2 -> V_65 = 0 ;
V_2 -> V_34 = 0 ;
V_2 -> V_17 = 0 ;
F_51 ( V_2 ) ;
V_89 . V_9 = F_3 ( F_52 ( V_4 ) ) ;
if ( V_89 . V_10 . V_95 ) {
V_89 . V_10 . V_95 = 0 ;
F_5 ( F_52 ( V_4 ) , V_89 . V_9 ) ;
do {
V_89 . V_9 = F_3 ( F_52 ( V_4 ) ) ;
} while ( V_89 . V_10 . V_95 );
}
V_157 . V_9 = 0 ;
V_157 . V_10 . V_120 = 1 ;
F_5 ( V_172 , V_157 . V_9 ) ;
V_159 . V_9 = 0 ;
V_159 . V_10 . V_173 = V_2 -> V_42 >> 3 ;
V_159 . V_10 . V_174 = V_43 ;
F_5 ( F_93 ( V_4 ) , V_159 . V_9 ) ;
V_161 . V_9 = 0 ;
V_161 . V_10 . V_175 = V_2 -> V_35 >> 3 ;
V_161 . V_10 . V_176 = V_18 ;
F_5 ( F_94 ( V_4 ) , V_161 . V_9 ) ;
V_143 . V_9 = F_3 ( F_61 ( V_4 ) ) ;
V_143 . V_10 . V_120 = 0 ;
F_5 ( F_61 ( V_4 ) , V_143 . V_9 ) ;
memcpy ( V_124 . V_125 , V_16 -> V_119 , V_127 ) ;
F_70 ( V_16 , & V_124 ) ;
F_72 ( V_16 , V_16 -> V_23 ) ;
V_89 . V_9 = 0 ;
V_89 . V_10 . V_177 = 1 ;
V_89 . V_10 . V_120 = 1 ;
V_89 . V_10 . V_178 = 0 ;
V_89 . V_10 . V_179 = 1 ;
F_5 ( F_52 ( V_4 ) , V_89 . V_9 ) ;
if ( F_95 ( V_180 )
|| F_95 ( V_181 ) ) {
union V_182 V_183 ;
V_183 . V_9 = F_3 ( V_184 ) ;
if ( V_4 ) {
V_183 . V_10 . V_185 = 1 ;
V_183 . V_10 . V_186 = 6 ;
V_183 . V_10 . V_187 = 6 ;
} else {
V_183 . V_10 . V_188 = 1 ;
V_183 . V_10 . V_189 = 6 ;
V_183 . V_10 . V_190 = 6 ;
}
F_5 ( V_184 , V_183 . V_9 ) ;
}
F_14 ( V_16 ) ;
F_5 ( F_96 ( V_4 ) , 1 ) ;
F_5 ( F_32 ( V_4 ) , 0 ) ;
F_5 ( F_33 ( V_4 ) , 0 ) ;
F_5 ( F_97 ( V_4 ) , 1 ) ;
F_5 ( F_35 ( V_4 ) , 0 ) ;
F_5 ( F_36 ( V_4 ) , 0 ) ;
F_5 ( F_76 ( V_4 ) , F_3 ( F_76 ( V_4 ) ) ) ;
if ( F_98 ( V_2 -> V_191 , F_75 , 0 , V_16 -> V_149 ,
V_16 ) ) {
F_99 ( V_2 -> V_30 , L_9 , V_2 -> V_191 ) ;
goto V_192;
}
V_165 . V_9 = 0 ;
V_165 . V_10 . V_193 = 0 ;
F_5 ( F_100 ( V_4 ) , V_165 . V_9 ) ;
V_167 . V_9 = 0 ;
V_167 . V_10 . V_194 = 1 ;
F_5 ( F_101 ( V_4 ) , V_167 . V_9 ) ;
V_6 . V_9 = 0 ;
V_6 . V_10 . V_11 = 1 ;
V_6 . V_10 . V_12 = 1 ;
F_5 ( F_4 ( V_4 ) , V_6 . V_9 ) ;
V_163 . V_9 = 0 ;
V_163 . V_10 . V_195 = 1 ;
V_163 . V_10 . V_196 = 1 ;
V_163 . V_10 . V_197 = 1 ;
V_163 . V_10 . V_198 = 1 ;
V_163 . V_10 . V_199 = 0 ;
V_163 . V_10 . V_200 = 1 ;
V_163 . V_10 . V_201 = 1 ;
V_163 . V_10 . V_202 = 1 ;
V_163 . V_10 . V_203 = 1 ;
V_163 . V_10 . V_204 = 1 ;
F_5 ( F_102 ( V_4 ) , V_163 . V_9 ) ;
V_157 . V_9 = 0 ;
V_157 . V_10 . V_120 = 1 ;
F_5 ( V_172 , V_157 . V_9 ) ;
V_143 . V_9 = F_3 ( F_61 ( V_4 ) ) ;
V_143 . V_10 . V_205 = 1 ;
V_143 . V_10 . V_206 = 1 ;
V_143 . V_10 . V_120 = 1 ;
V_2 -> V_147 = 1 ;
V_143 . V_10 . V_148 = V_2 -> V_147 ;
F_5 ( F_61 ( V_4 ) , V_143 . V_9 ) ;
V_2 -> V_146 = 0 ;
F_85 ( V_16 ) ;
if ( F_86 ( V_16 ) ) {
F_99 ( V_2 -> V_30 , L_10 ) ;
goto V_192;
}
F_29 ( V_16 ) ;
F_103 ( & V_2 -> V_87 ) ;
return 0 ;
V_192:
F_51 ( V_2 ) ;
F_26 ( V_2 -> V_30 , V_2 -> V_35 ,
F_13 ( V_18 ) ,
V_36 ) ;
F_104 ( V_2 -> V_33 ) ;
V_171:
F_26 ( V_2 -> V_30 , V_2 -> V_42 ,
F_13 ( V_43 ) ,
V_36 ) ;
F_104 ( V_2 -> V_44 ) ;
return - V_169 ;
}
static int F_105 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
F_106 ( & V_2 -> V_87 ) ;
F_107 ( V_16 ) ;
if ( V_2 -> V_142 )
F_108 ( V_2 -> V_142 ) ;
F_85 ( V_16 ) ;
F_51 ( V_2 ) ;
F_109 ( V_2 -> V_191 , V_16 ) ;
F_110 ( & V_2 -> V_41 ) ;
F_110 ( & V_2 -> V_26 ) ;
F_26 ( V_2 -> V_30 , V_2 -> V_35 ,
F_13 ( V_18 ) ,
V_36 ) ;
F_104 ( V_2 -> V_33 ) ;
F_26 ( V_2 -> V_30 , V_2 -> V_42 ,
F_13 ( V_43 ) ,
V_36 ) ;
F_104 ( V_2 -> V_44 ) ;
return 0 ;
}
static int F_111 ( struct V_21 * V_22 , struct V_15 * V_16 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
int V_4 = V_2 -> V_4 ;
union V_14 V_20 ;
unsigned long V_7 ;
int V_207 = V_208 ;
V_20 . V_27 = 0 ;
V_20 . V_10 . V_28 = V_22 -> V_28 ;
V_20 . V_10 . V_29 = F_19 ( V_2 -> V_30 , V_22 -> V_31 ,
V_22 -> V_28 ,
V_47 ) ;
F_2 ( & V_2 -> V_41 . V_8 , V_7 ) ;
if ( F_112 ( V_2 -> V_46 >= F_12 ( V_43 ) - 1 ) ) {
F_6 ( & V_2 -> V_41 . V_8 , V_7 ) ;
F_107 ( V_16 ) ;
F_2 ( & V_2 -> V_41 . V_8 , V_7 ) ;
}
if ( F_112 ( V_2 -> V_46 >=
F_12 ( V_43 ) ) ) {
F_6 ( & V_2 -> V_41 . V_8 , V_7 ) ;
F_26 ( V_2 -> V_30 , V_20 . V_10 . V_29 , V_20 . V_10 . V_28 ,
V_47 ) ;
goto V_209;
}
F_18 ( & V_2 -> V_41 , V_22 ) ;
V_2 -> V_44 [ V_2 -> V_170 ] = V_20 . V_27 ;
V_2 -> V_170 = ( V_2 -> V_170 + 1 ) % V_43 ;
V_2 -> V_46 ++ ;
F_6 ( & V_2 -> V_41 . V_8 , V_7 ) ;
F_20 ( V_2 -> V_30 , V_2 -> V_42 ,
F_13 ( V_43 ) ,
V_36 ) ;
V_16 -> V_51 . V_210 ++ ;
V_16 -> V_51 . V_211 += V_22 -> V_28 ;
F_5 ( F_113 ( V_4 ) , 1 ) ;
V_207 = V_212 ;
V_209:
F_34 ( V_16 ) ;
return V_207 ;
}
static void F_114 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
F_47 ( V_2 , 16 ) ;
F_31 ( V_16 ) ;
}
static void F_115 ( struct V_15 * V_16 ,
struct V_213 * V_214 )
{
strncpy ( V_214 -> V_215 , V_216 , sizeof( V_214 -> V_215 ) ) ;
strncpy ( V_214 -> V_217 , V_218 , sizeof( V_214 -> V_217 ) ) ;
strncpy ( V_214 -> V_219 , L_11 , sizeof( V_214 -> V_219 ) ) ;
strncpy ( V_214 -> V_220 , L_11 , sizeof( V_214 -> V_220 ) ) ;
V_214 -> V_221 = 0 ;
V_214 -> V_222 = 0 ;
V_214 -> V_223 = 0 ;
V_214 -> V_224 = 0 ;
}
static int F_116 ( struct V_15 * V_16 ,
struct V_225 * V_141 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
if ( V_2 -> V_142 )
return F_117 ( V_2 -> V_142 , V_141 ) ;
return - V_130 ;
}
static int F_118 ( struct V_15 * V_16 ,
struct V_225 * V_141 )
{
struct V_1 * V_2 = F_15 ( V_16 ) ;
if ( ! F_119 ( V_226 ) )
return - V_227 ;
if ( V_2 -> V_142 )
return F_120 ( V_2 -> V_142 , V_141 ) ;
return - V_130 ;
}
static int T_2 F_121 ( struct V_228 * V_229 )
{
struct V_230 * V_231 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
int V_99 ;
V_16 = F_122 ( sizeof( struct V_1 ) ) ;
if ( V_16 == NULL )
return - V_169 ;
F_123 ( & V_229 -> V_30 , V_16 ) ;
V_2 = F_15 ( V_16 ) ;
F_124 ( V_16 , & V_2 -> V_87 , F_48 ,
V_232 ) ;
V_2 -> V_16 = V_16 ;
V_2 -> V_30 = & V_229 -> V_30 ;
V_2 -> V_4 = V_229 -> V_233 ;
snprintf ( V_16 -> V_149 , V_234 , L_12 , V_2 -> V_4 ) ;
V_231 = F_125 ( V_229 , V_235 , 0 ) ;
if ( ! V_231 )
goto V_236;
V_2 -> V_191 = V_231 -> V_237 ;
F_126 ( & V_2 -> V_8 ) ;
F_127 ( & V_2 -> V_41 ) ;
F_127 ( & V_2 -> V_26 ) ;
F_128 ( & V_2 -> V_137 ,
F_30 , ( unsigned long ) V_2 ) ;
V_16 -> V_238 |= V_239 ;
V_16 -> V_240 = & V_241 ;
V_16 -> V_242 = & V_243 ;
for ( V_99 = 0 ; V_99 < 6 ; V_99 ++ )
V_16 -> V_119 [ V_99 ] = V_244 -> V_245 [ V_99 ] ;
V_16 -> V_119 [ 5 ] += V_2 -> V_4 ;
if ( V_2 -> V_4 >= V_244 -> V_246 )
F_99 ( & V_229 -> V_30 ,
L_13 ,
V_16 -> V_149 , V_16 -> V_119 ) ;
if ( F_129 ( V_16 ) )
goto V_236;
F_130 ( & V_229 -> V_30 , L_14 V_218 L_15 ) ;
return 0 ;
V_236:
F_131 ( V_16 ) ;
return - V_247 ;
}
static int T_3 F_132 ( struct V_228 * V_229 )
{
struct V_15 * V_16 = F_133 ( & V_229 -> V_30 ) ;
F_134 ( V_16 ) ;
F_131 ( V_16 ) ;
return 0 ;
}
static int T_4 F_135 ( void )
{
F_136 () ;
return F_137 ( & V_248 ) ;
}
static void T_5 F_138 ( void )
{
F_139 ( & V_248 ) ;
}

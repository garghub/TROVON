static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( ! V_2 || ! F_2 ( V_4 , & V_2 -> V_5 ) ||
F_2 ( V_6 , & V_2 -> V_5 ) ||
F_2 ( V_7 , & V_2 -> V_5 ) )
V_3 = - V_8 ;
return V_3 ;
}
static void F_3 ( struct V_9 * V_10 , T_1 V_11 ,
T_1 * V_12 , T_1 * V_13 )
{
struct V_14 * V_15 = V_10 -> V_16 . V_15 ;
T_1 V_17 = 0 ;
T_1 V_18 = 0 ;
if ( V_11 ) {
while ( V_11 >= ( V_17 + V_15 -> V_19 ) ) {
V_17 += V_15 -> V_19 ;
V_18 ++ ;
V_15 ++ ;
}
}
* V_12 = V_11 - V_17 ;
* V_13 = V_18 ;
}
static void F_4 ( struct V_20 * V_21 )
{
struct V_9 * V_10 = V_21 -> V_22 ;
T_1 V_23 ;
T_1 V_13 ;
T_1 V_24 = 0 ;
T_1 V_25 = V_10 -> V_26 . V_27 ;
if ( ! F_5 ( V_21 ) && ! V_21 -> V_28 )
return;
V_24 += V_21 -> V_28 ;
if ( V_21 -> V_28 == V_25 )
return;
if ( F_5 ( V_21 ) ) {
F_3 ( V_10 , V_24 ,
& V_23 , & V_13 ) ;
V_10 -> V_26 . V_29 = V_23 ;
V_10 -> V_26 . V_30 = V_13 ;
V_24 += V_21 -> V_31 . V_32 ;
}
if ( V_24 != V_25 ) {
F_3 ( V_10 , V_24 ,
& V_23 , & V_13 ) ;
if ( ( V_23 > V_21 -> V_33 -> V_34 -> V_35 ) ||
( V_13 > F_6 ( V_10 -> V_36 ) ) ) {
int V_37 = 0 ;
F_7 ( V_38 , V_21 -> V_33 ,
L_1
L_2 ,
V_24 , V_10 -> V_16 . V_39 ,
F_6 ( V_10 -> V_36 ) ) ;
for ( V_37 = 0 ; V_37 < V_10 -> V_16 . V_39 ; V_37 ++ )
F_7 ( V_38 , V_21 -> V_33 ,
L_3 ,
V_37 , V_10 -> V_16 . V_15 [ V_37 ] .\
V_19 ) ;
}
V_10 -> V_26 . V_40 = V_23 ;
V_10 -> V_26 . V_41 = V_13 ;
}
}
static int F_8 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_42 * V_43 = V_10 -> V_36 ;
struct V_14 * V_44 = V_10 -> V_16 . V_15 ;
struct V_45 * V_46 ;
int V_47 = 0 ;
int V_48 = 0 ;
int V_49 ;
int V_50 ;
T_2 V_51 ;
int V_37 ;
F_9 ( F_6 ( V_43 ) > V_52 ) ;
V_49 = F_10 ( V_43 ) ;
F_11 (sc, sg, sg_count, i) {
V_50 = F_12 ( V_46 ) ;
V_51 = ( T_2 ) F_13 ( V_46 ) ;
V_44 [ V_48 ] . V_53 = V_51 & 0xffffffff ;
V_44 [ V_48 ] . V_54 = V_51 >> 32 ;
V_44 [ V_48 ] . V_19 = V_50 ;
V_44 [ V_48 ] . V_55 = 0 ;
if ( V_48 == 0 )
V_44 [ V_48 ] . V_55 = V_56 ;
V_47 += V_50 ;
V_48 ++ ;
}
if ( V_48 )
V_44 [ V_48 - 1 ] . V_55 |= V_57 ;
F_9 ( V_47 != F_14 ( V_43 ) ) ;
return V_48 ;
}
static void F_15 ( struct V_9 * V_10 )
{
int V_48 ;
V_48 = F_8 ( V_10 -> V_33 -> V_2 , V_10 ) ;
if ( ! V_48 ) {
struct V_14 * V_44 = V_10 -> V_16 . V_15 ;
V_44 [ 0 ] . V_53 = V_44 [ 0 ] . V_54 = 0 ;
V_44 [ 0 ] . V_19 = V_44 [ 0 ] . V_55 = 0 ;
}
V_10 -> V_16 . V_39 = V_48 ;
}
void F_16 ( struct V_9 * V_10 )
{
struct V_42 * V_43 = V_10 -> V_36 ;
if ( V_10 -> V_16 . V_39 && V_43 ) {
F_17 ( V_43 ) ;
V_10 -> V_16 . V_39 = 0 ;
}
}
static void F_18 ( struct V_9 * V_10 )
{
memset ( & V_10 -> V_26 , 0x00 , sizeof( V_10 -> V_26 ) ) ;
V_10 -> V_26 . V_58 = 0xFF ;
V_10 -> V_26 . V_59 = ( T_1 ) V_10 -> V_16 . V_60 ;
V_10 -> V_26 . V_61 =
( T_1 ) ( ( T_2 ) V_10 -> V_16 . V_60 >> 32 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_62 * V_62 ,
T_1 V_63 )
{
if ( V_2 && V_2 -> V_64 . V_65 [ V_63 ] ) {
F_7 ( V_38 , V_62 -> V_66 -> V_22 ,
L_4 , V_63 ) ;
return - V_67 ;
}
V_2 -> V_64 . V_65 [ V_63 ] = V_62 ;
return 0 ;
}
struct V_62 * F_20 ( struct V_1 * V_2 ,
T_3 V_63 )
{
if ( ! V_2 -> V_64 . V_65 ) {
F_21 ( V_68 L_5 ) ;
return NULL ;
} else if ( V_63 >= V_2 -> V_69 ) {
F_21 ( V_68 L_6 , V_63 ) ;
return NULL ;
}
return V_2 -> V_64 . V_65 [ V_63 ] ;
}
static T_1 F_22 ( struct V_1 * V_2 )
{
int V_70 ;
if ( ! V_2 -> V_64 . V_71 )
return - 1 ;
V_70 = V_2 -> V_64 . V_72 ;
V_2 -> V_64 . V_72 ++ ;
if ( V_2 -> V_64 . V_72 == V_2 -> V_64 . V_73 )
V_2 -> V_64 . V_72 = 0 ;
V_2 -> V_64 . V_71 -- ;
return V_2 -> V_64 . V_64 [ V_70 ] ;
}
static void F_23 ( struct V_1 * V_2 , T_3 V_63 )
{
int V_70 ;
if ( V_63 == ( T_3 ) - 1 )
return;
V_2 -> V_64 . V_71 ++ ;
V_70 = V_2 -> V_64 . V_74 ;
V_2 -> V_64 . V_64 [ V_70 ] = V_63 ;
V_2 -> V_64 . V_65 [ V_63 ] = NULL ;
V_2 -> V_64 . V_74 ++ ;
if ( V_2 -> V_64 . V_74 == V_2 -> V_64 . V_73 )
V_2 -> V_64 . V_74 = 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_75 ;
int V_37 ;
V_75 = V_2 -> V_69 * sizeof( T_1 ) ;
V_75 = ( V_75 + ( V_76 - 1 ) ) & V_77 ;
V_2 -> V_64 . V_78 = F_25 ( V_75 , V_79 ) ;
if ( ! V_2 -> V_64 . V_78 )
return - V_80 ;
V_75 = V_2 -> V_69 * sizeof( struct V_62 * ) ;
V_75 = ( V_75 + ( V_76 - 1 ) ) & V_77 ;
V_2 -> V_64 . V_65 = F_25 ( V_75 , V_79 ) ;
if ( ! V_2 -> V_64 . V_65 ) {
F_26 ( V_2 -> V_64 . V_78 ) ;
V_2 -> V_64 . V_78 = NULL ;
return - V_80 ;
}
V_2 -> V_64 . V_64 = ( T_1 * ) V_2 -> V_64 . V_78 ;
V_2 -> V_64 . V_74 = 0 ;
V_2 -> V_64 . V_72 = 0 ;
V_2 -> V_64 . V_73 = V_2 -> V_69 ;
V_2 -> V_64 . V_71 = V_2 -> V_69 ;
for ( V_37 = 0 ; V_37 < V_2 -> V_69 ; V_37 ++ ) {
V_2 -> V_64 . V_64 [ V_37 ] = V_37 ;
V_2 -> V_64 . V_65 [ V_37 ] = NULL ;
}
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_64 . V_78 ) ;
V_2 -> V_64 . V_78 = NULL ;
F_26 ( V_2 -> V_64 . V_65 ) ;
V_2 -> V_64 . V_65 = NULL ;
}
static struct V_81 * F_28 ( struct V_1 * V_2 )
{
struct V_81 * V_82 ;
struct V_83 * V_84 ;
T_1 V_85 ;
V_82 = F_29 ( sizeof( * V_84 ) ) ;
if ( ! V_82 ) {
F_21 ( V_68 L_7 ) ;
return NULL ;
}
V_84 = V_82 -> V_22 ;
V_84 -> V_86 = V_82 ;
F_30 ( & V_84 -> V_87 ) ;
V_84 -> V_88 = V_89 ;
V_84 -> V_90 = ( T_3 ) - 1 ;
V_84 -> V_2 = V_2 ;
V_84 -> V_91 = V_2 -> V_92 ;
V_85 = V_93 ;
while ( V_85 >>= 1 )
V_84 -> V_94 += 1 ;
V_2 -> V_95 ++ ;
F_31 ( & V_84 -> V_96 ) ;
return V_82 ;
}
static void F_32 ( struct V_81 * V_82 )
{
struct V_83 * V_84 = V_82 -> V_22 ;
unsigned long V_55 ;
F_33 ( & V_97 , V_55 ) ;
V_84 -> V_88 = V_89 ;
V_84 -> V_2 -> V_95 -- ;
if ( V_84 -> V_90 != ( T_3 ) - 1 )
F_23 ( V_84 -> V_2 , V_84 -> V_90 ) ;
if ( V_84 -> V_33 ) {
V_84 -> V_33 -> V_82 = NULL ;
V_84 -> V_33 = NULL ;
}
V_84 -> V_2 = NULL ;
F_34 ( & V_97 , V_55 ) ;
F_35 ( V_82 ) ;
}
static int F_36 ( struct V_1 * V_2 , struct V_98 * V_34 ,
struct V_9 * V_10 )
{
struct V_99 * V_100 = & V_10 -> V_16 ;
struct V_14 * V_44 ;
V_100 -> V_15 = F_37 ( & V_2 -> V_101 -> V_102 ,
V_52 * sizeof( * V_44 ) ,
& V_100 -> V_60 , V_79 ) ;
if ( ! V_100 -> V_15 ) {
F_38 ( V_68 , V_34 , L_8
L_9 ) ;
return - V_80 ;
}
V_100 -> V_39 = 0 ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_98 * V_34 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_34 -> V_103 ; V_37 ++ ) {
struct V_20 * V_21 = V_34 -> V_104 [ V_37 ] ;
struct V_9 * V_10 = V_21 -> V_22 ;
if ( V_10 -> V_16 . V_15 )
F_40 ( & V_2 -> V_101 -> V_102 ,
V_52 *
sizeof( struct V_14 ) ,
V_10 -> V_16 . V_15 ,
V_10 -> V_16 . V_60 ) ;
}
}
static int F_41 ( struct V_1 * V_2 ,
struct V_98 * V_34 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_34 -> V_103 ; V_37 ++ ) {
struct V_20 * V_21 = V_34 -> V_104 [ V_37 ] ;
struct V_9 * V_10 = V_21 -> V_22 ;
V_21 -> V_105 = & V_10 -> V_105 ;
V_21 -> V_106 = sizeof( struct V_107 ) ;
if ( F_36 ( V_2 , V_34 , V_10 ) )
goto V_108;
}
return 0 ;
V_108:
F_39 ( V_2 , V_34 ) ;
return - V_80 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_109 = 0 ;
struct V_14 * V_110 ;
T_2 V_51 ;
V_2 -> V_111 = F_37 ( & V_2 -> V_101 -> V_102 , V_112 ,
& V_2 -> V_113 , V_79 ) ;
if ( ! V_2 -> V_111 ) {
F_21 ( V_68 L_10 ) ;
V_109 = - 1 ;
goto V_114;
}
V_2 -> V_115 = F_37 ( & V_2 -> V_101 -> V_102 ,
V_112 ,
& V_2 -> V_116 , V_79 ) ;
if ( ! V_2 -> V_115 ) {
F_21 ( V_68 L_11 ) ;
F_40 ( & V_2 -> V_101 -> V_102 , V_112 ,
V_2 -> V_111 , V_2 -> V_113 ) ;
V_2 -> V_111 = NULL ;
V_109 = - 1 ;
goto V_114;
}
V_110 = (struct V_14 * ) V_2 -> V_111 ;
V_51 = ( unsigned long ) V_2 -> V_116 ;
V_110 -> V_53 = V_51 & 0xffffffff ;
V_110 -> V_54 = V_51 >> 32 ;
V_110 -> V_19 = V_112 ;
V_110 -> V_55 = V_57 |
V_56 ;
V_114:
return V_109 ;
}
static void F_43 ( struct V_1 * V_2 )
{
if ( V_2 -> V_111 ) {
F_40 ( & V_2 -> V_101 -> V_102 , V_112 ,
V_2 -> V_111 , V_2 -> V_113 ) ;
V_2 -> V_111 = NULL ;
}
if ( V_2 -> V_115 ) {
F_40 ( & V_2 -> V_101 -> V_102 , V_112 ,
V_2 -> V_115 , V_2 -> V_116 ) ;
V_2 -> V_115 = NULL ;
}
return;
}
void F_44 ( struct V_117 * V_118 )
{
F_45 ( V_118 -> V_22 , V_119 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_83 * V_82 )
{
F_47 ( & V_2 -> V_120 ) ;
F_48 ( & V_82 -> V_87 , & V_2 -> V_121 ) ;
F_49 ( & V_2 -> V_120 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_83 * V_82 )
{
F_47 ( & V_2 -> V_120 ) ;
F_51 ( & V_82 -> V_87 ) ;
F_49 ( & V_2 -> V_120 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_83 * V_82 )
{
F_47 ( & V_2 -> V_120 ) ;
F_48 ( & V_82 -> V_87 , & V_2 -> V_122 ) ;
F_49 ( & V_2 -> V_120 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_83 * V_82 )
{
F_47 ( & V_2 -> V_120 ) ;
F_51 ( & V_82 -> V_87 ) ;
F_49 ( & V_2 -> V_120 ) ;
return 0 ;
}
struct V_83 *
F_54 ( struct V_1 * V_2 , T_1 V_63 )
{
struct V_123 * V_124 ;
struct V_123 * V_125 ;
struct V_83 * V_82 ;
F_55 ( & V_2 -> V_120 ) ;
F_56 (list, tmp, &hba->ep_ofld_list) {
V_82 = (struct V_83 * ) V_124 ;
if ( V_82 -> V_90 == V_63 )
break;
V_82 = NULL ;
}
F_57 ( & V_2 -> V_120 ) ;
if ( ! V_82 )
F_21 ( V_68 L_12 , V_63 ) ;
return V_82 ;
}
struct V_83 *
F_58 ( struct V_1 * V_2 , T_1 V_63 )
{
struct V_123 * V_124 ;
struct V_123 * V_125 ;
struct V_83 * V_82 ;
F_55 ( & V_2 -> V_120 ) ;
F_56 (list, tmp, &hba->ep_destroy_list) {
V_82 = (struct V_83 * ) V_124 ;
if ( V_82 -> V_90 == V_63 )
break;
V_82 = NULL ;
}
F_57 ( & V_2 -> V_120 ) ;
if ( ! V_82 )
F_21 ( V_68 L_12 , V_63 ) ;
return V_82 ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_83 * V_82 )
{
F_47 ( & V_2 -> V_120 ) ;
F_48 ( & V_82 -> V_87 , & V_2 -> V_126 ) ;
F_49 ( & V_2 -> V_120 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_83 * V_82 )
{
F_47 ( & V_2 -> V_120 ) ;
F_51 ( & V_82 -> V_87 ) ;
F_49 ( & V_2 -> V_120 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_127 * V_128 )
{
if ( F_2 ( V_129 , & V_2 -> V_130 ) )
V_128 -> V_131 = V_132 ;
else if ( F_2 ( V_133 , & V_2 -> V_130 ) )
V_128 -> V_131 = V_134 ;
else if ( F_2 ( V_135 , & V_2 -> V_130 ) )
V_128 -> V_131 = V_136 ;
else
V_128 -> V_131 = V_132 ;
}
struct V_1 * F_62 ( struct V_137 * V_138 )
{
struct V_127 * V_128 ;
struct V_1 * V_2 ;
V_128 = F_63 ( & V_139 , sizeof( * V_2 ) , 0 ) ;
if ( ! V_128 )
return NULL ;
V_128 -> V_140 = V_138 -> V_101 -> V_141 ;
V_128 -> V_142 = V_143 ;
V_128 -> V_144 = V_145 ;
V_128 -> V_146 = 0 ;
V_128 -> V_147 = 512 ;
V_128 -> V_148 = 16 ;
V_2 = F_64 ( V_128 ) ;
V_2 -> V_128 = V_128 ;
V_2 -> V_149 = V_138 -> V_149 ;
V_2 -> V_101 = V_138 -> V_101 ;
F_65 ( V_2 -> V_101 ) ;
V_2 -> V_150 = V_2 -> V_101 -> V_151 ;
V_2 -> V_152 = V_2 -> V_101 -> V_153 ;
V_2 -> V_154 = V_2 -> V_101 -> V_155 ;
V_2 -> V_156 = V_2 -> V_101 -> V_157 ;
V_2 -> V_158 = F_66 ( V_2 -> V_101 -> V_159 ) ;
V_2 -> V_160 = F_67 ( V_2 -> V_101 -> V_159 ) ;
F_68 ( V_2 , V_138 ) ;
F_61 ( V_2 , V_128 ) ;
V_2 -> V_161 = F_69 ( V_2 -> V_101 , 0 ) ;
if ( F_2 ( V_133 , & V_2 -> V_130 ) ) {
V_2 -> V_162 = F_70 ( V_2 -> V_101 , 0 , V_163 ) ;
if ( ! V_2 -> V_162 )
goto V_164;
} else if ( F_2 ( V_135 , & V_2 -> V_130 ) ) {
V_2 -> V_162 = F_70 ( V_2 -> V_101 , 0 , 4096 ) ;
if ( ! V_2 -> V_162 )
goto V_164;
}
if ( F_42 ( V_2 ) )
goto V_165;
F_30 ( & V_2 -> V_122 ) ;
F_30 ( & V_2 -> V_126 ) ;
F_30 ( & V_2 -> V_121 ) ;
F_71 ( & V_2 -> V_120 ) ;
V_2 -> V_166 = V_167 ;
V_2 -> V_69 = V_145 ;
if ( F_24 ( V_2 ) )
goto V_168;
if ( F_2 ( V_135 , & V_2 -> V_130 ) ) {
if ( V_169 && V_169 <= V_170 )
V_2 -> V_171 = V_169 ;
else
V_2 -> V_171 = V_172 ;
} else {
if ( V_169 && V_169 <= V_173 )
V_2 -> V_171 = V_169 ;
else
V_2 -> V_171 = V_174 ;
}
V_2 -> V_175 = V_176 ;
V_2 -> V_177 = V_2 -> V_171 + V_176 ;
if ( F_2 ( V_135 , & V_2 -> V_130 ) ) {
if ( V_2 -> V_177 > V_178 )
V_2 -> V_177 = V_178 ;
} else if ( V_2 -> V_177 > V_179 )
V_2 -> V_177 = V_179 ;
V_2 -> V_180 = V_2 -> V_171 / 2 ;
F_72 ( & V_2 -> V_181 ) ;
F_73 ( & V_2 -> V_182 ) ;
F_31 ( & V_2 -> V_183 ) ;
if ( F_2 ( V_135 , & V_2 -> V_130 ) ) {
V_2 -> V_184 = 30 * V_185 ;
V_2 -> V_186 = 20 * V_185 ;
V_2 -> V_187 = 6 * V_185 ;
} else {
V_2 -> V_184 = 20 * V_185 ;
V_2 -> V_186 = 10 * V_185 ;
V_2 -> V_187 = 2 * V_185 ;
}
#ifdef F_74
F_72 ( & V_2 -> V_188 ) ;
#endif
memset ( & V_2 -> V_189 , 0 , sizeof( struct V_190 ) ) ;
if ( F_75 ( V_128 , & V_2 -> V_101 -> V_102 ) )
goto V_191;
return V_2 ;
V_191:
F_27 ( V_2 ) ;
V_168:
F_43 ( V_2 ) ;
V_165:
if ( V_2 -> V_162 ) {
F_76 ( V_2 -> V_101 , V_2 -> V_162 ) ;
V_2 -> V_162 = NULL ;
}
V_164:
F_77 ( V_2 -> V_101 ) ;
F_78 ( V_128 ) ;
return NULL ;
}
void F_79 ( struct V_1 * V_2 )
{
struct V_127 * V_128 = V_2 -> V_128 ;
F_80 ( V_128 ) ;
F_30 ( & V_2 -> V_122 ) ;
F_30 ( & V_2 -> V_126 ) ;
F_30 ( & V_2 -> V_121 ) ;
F_77 ( V_2 -> V_101 ) ;
if ( V_2 -> V_162 ) {
F_76 ( V_2 -> V_101 , V_2 -> V_162 ) ;
V_2 -> V_162 = NULL ;
}
F_43 ( V_2 ) ;
F_27 ( V_2 ) ;
F_81 ( V_128 ) ;
}
static void F_82 ( struct V_1 * V_2 ,
struct V_62 * V_62 )
{
if ( V_62 -> V_192 . V_193 ) {
F_40 ( & V_2 -> V_101 -> V_102 , V_112 ,
V_62 -> V_192 . V_193 ,
V_62 -> V_192 . V_194 ) ;
V_62 -> V_192 . V_193 = NULL ;
}
if ( V_62 -> V_192 . V_195 ) {
F_40 ( & V_2 -> V_101 -> V_102 , V_112 ,
V_62 -> V_192 . V_195 ,
V_62 -> V_192 . V_196 ) ;
V_62 -> V_192 . V_195 = NULL ;
}
if ( V_62 -> V_192 . V_197 ) {
F_40 ( & V_2 -> V_101 -> V_102 ,
V_198 ,
V_62 -> V_192 . V_197 ,
V_62 -> V_192 . V_199 ) ;
V_62 -> V_192 . V_197 = NULL ;
}
if ( V_62 -> V_192 . V_200 ) {
F_40 ( & V_2 -> V_101 -> V_102 ,
V_198 ,
V_62 -> V_192 . V_200 ,
V_62 -> V_192 . V_201 ) ;
V_62 -> V_192 . V_200 = NULL ;
}
}
static int F_83 ( struct V_1 * V_2 ,
struct V_62 * V_62 )
{
V_62 -> V_192 . V_200 =
F_37 ( & V_2 -> V_101 -> V_102 ,
V_198 ,
& V_62 -> V_192 . V_201 ,
V_79 ) ;
if ( V_62 -> V_192 . V_200 == NULL )
goto V_202;
V_62 -> V_192 . V_203 = 0 ;
V_62 -> V_192 . V_204 = V_62 -> V_192 . V_200 ;
V_62 -> V_192 . V_197 =
F_37 ( & V_2 -> V_101 -> V_102 ,
V_198 ,
& V_62 -> V_192 . V_199 ,
V_79 ) ;
if ( V_62 -> V_192 . V_197 == NULL )
goto V_205;
V_62 -> V_192 . V_206 = V_198 ;
V_62 -> V_192 . V_207 = V_62 -> V_192 . V_197 ;
V_62 -> V_192 . V_195 =
F_37 ( & V_2 -> V_101 -> V_102 , V_112 ,
& V_62 -> V_192 . V_196 , V_79 ) ;
if ( V_62 -> V_192 . V_195 == NULL )
goto V_208;
V_62 -> V_192 . V_193 =
F_37 ( & V_2 -> V_101 -> V_102 , V_112 ,
& V_62 -> V_192 . V_194 ,
V_79 ) ;
if ( V_62 -> V_192 . V_193 == NULL )
goto V_209;
return 0 ;
V_209:
F_40 ( & V_2 -> V_101 -> V_102 , V_112 ,
V_62 -> V_192 . V_195 ,
V_62 -> V_192 . V_196 ) ;
V_62 -> V_192 . V_195 = NULL ;
V_208:
F_40 ( & V_2 -> V_101 -> V_102 , V_198 ,
V_62 -> V_192 . V_197 ,
V_62 -> V_192 . V_199 ) ;
V_62 -> V_192 . V_197 = NULL ;
V_205:
F_40 ( & V_2 -> V_101 -> V_102 , V_198 ,
V_62 -> V_192 . V_200 ,
V_62 -> V_192 . V_201 ) ;
V_62 -> V_192 . V_200 = NULL ;
V_202:
F_7 ( V_68 , V_62 -> V_66 -> V_22 ,
L_13 ) ;
return - V_80 ;
}
static void F_84 ( struct V_62 * V_62 )
{
struct V_14 * V_15 ;
V_15 = (struct V_14 * ) V_62 -> V_192 . V_195 ;
V_15 -> V_54 =
( T_1 ) ( ( T_2 ) V_62 -> V_192 . V_201 >> 32 ) ;
V_15 -> V_53 = ( T_1 ) V_62 -> V_192 . V_201 ;
V_15 -> V_19 = V_62 -> V_192 . V_204 -
V_62 -> V_192 . V_200 ;
V_15 -> V_210 = 0 ;
V_15 -> V_55 = V_57 |
V_56 ;
V_15 = (struct V_14 * ) V_62 -> V_192 . V_193 ;
V_15 -> V_54 = ( T_2 ) V_62 -> V_192 . V_199 >> 32 ;
V_15 -> V_53 = ( T_1 ) V_62 -> V_192 . V_199 ;
V_15 -> V_19 = V_198 ;
V_15 -> V_210 = 0 ;
V_15 -> V_55 = V_57 |
V_56 ;
}
static int F_85 ( struct V_20 * V_21 )
{
struct V_9 * V_10 = V_21 -> V_22 ;
struct V_62 * V_62 = V_10 -> V_33 ;
int V_109 = 0 ;
char * V_211 ;
int V_212 ;
F_84 ( V_62 ) ;
switch ( V_21 -> V_105 -> V_213 & V_214 ) {
case V_215 :
F_86 ( V_62 , V_21 ) ;
break;
case V_216 :
V_212 = V_62 -> V_192 . V_203 ;
V_211 = V_62 -> V_192 . V_200 ;
if ( V_212 )
V_109 = F_87 ( V_62 , V_21 ,
V_211 , V_212 , 1 ) ;
else
V_109 = F_87 ( V_62 , V_21 ,
NULL , 0 , 1 ) ;
break;
case V_217 :
V_109 = F_88 ( V_62 , V_21 ) ;
break;
case V_218 :
V_109 = F_89 ( V_62 , V_21 ) ;
break;
case V_219 :
V_109 = F_90 ( V_62 , V_21 ) ;
break;
default:
F_7 ( V_38 , V_62 -> V_66 -> V_22 ,
L_14 ,
V_21 -> V_105 -> V_213 ) ;
}
return V_109 ;
}
static void F_91 ( struct V_42 * V_43 , struct V_9 * V_10 )
{
T_1 V_220 ;
int V_221 ;
T_4 * V_222 ;
T_1 * V_223 ;
T_1 V_224 [ 2 ] ;
F_92 ( V_43 -> V_151 -> V_225 , (struct V_224 * ) V_224 ) ;
V_10 -> V_26 . V_225 [ 0 ] = F_93 ( V_224 [ 0 ] ) ;
V_10 -> V_26 . V_225 [ 1 ] = F_93 ( V_224 [ 1 ] ) ;
V_221 = V_10 -> V_36 -> V_25 / sizeof( V_220 ) ;
V_222 = ( T_4 * ) V_43 -> V_226 ;
V_223 = ( T_1 * ) V_10 -> V_26 . V_227 ;
while ( V_221 -- ) {
memcpy ( & V_220 , ( const void * ) V_222 , 4 ) ;
* V_223 = F_94 ( V_220 ) ;
V_222 += 4 ;
V_223 ++ ;
}
if ( V_43 -> V_25 & 0x3 ) {
V_220 = ( T_1 ) V_222 [ 0 ] | ( ( T_1 ) V_222 [ 1 ] << 8 ) ;
* V_223 = F_94 ( V_220 ) ;
}
}
static void F_95 ( struct V_20 * V_21 )
{
struct V_228 * V_33 = V_21 -> V_33 ;
struct V_62 * V_62 = V_33 -> V_22 ;
struct V_1 * V_2 = V_62 -> V_2 ;
if ( ! V_21 -> V_43 || V_21 -> V_88 == V_229 )
return;
if ( V_21 -> V_88 == V_230 ) {
F_96 ( V_2 , V_21 -> V_22 ) ;
F_97 ( & V_33 -> V_34 -> V_231 ) ;
F_98 ( & V_62 -> V_232 ,
F_99 ( V_233 ) ) ;
F_100 ( & V_33 -> V_34 -> V_231 ) ;
}
F_16 ( V_21 -> V_22 ) ;
}
static int
F_101 ( struct V_228 * V_33 , struct V_20 * V_21 )
{
struct V_62 * V_62 = V_33 -> V_22 ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_9 * V_10 = V_21 -> V_22 ;
memset ( V_62 -> V_192 . V_200 , 0 , V_198 ) ;
F_18 ( V_10 ) ;
V_62 -> V_192 . V_203 = V_21 -> V_234 ;
F_102 ( V_2 , V_235 , 1 ) ;
F_102 ( V_2 , V_236 , V_21 -> V_234 ) ;
if ( V_21 -> V_234 ) {
memcpy ( V_62 -> V_192 . V_200 , V_21 -> V_237 ,
V_21 -> V_234 ) ;
V_62 -> V_192 . V_204 =
V_62 -> V_192 . V_200 + V_21 -> V_234 ;
}
V_10 -> V_33 = V_33 -> V_22 ;
V_10 -> V_36 = NULL ;
return F_85 ( V_21 ) ;
}
static int F_103 ( struct V_20 * V_21 )
{
struct V_228 * V_33 = V_21 -> V_33 ;
struct V_98 * V_34 = V_33 -> V_34 ;
struct V_127 * V_128 = F_104 ( V_34 -> V_118 ) ;
struct V_1 * V_2 = F_64 ( V_128 ) ;
struct V_62 * V_62 = V_33 -> V_22 ;
struct V_42 * V_43 = V_21 -> V_43 ;
struct V_9 * V_10 = V_21 -> V_22 ;
struct V_238 * V_105 = (struct V_238 * ) V_21 -> V_105 ;
if ( F_105 ( & V_62 -> V_82 -> V_239 ) + 1 >
V_2 -> V_171 )
return - V_80 ;
if ( ! V_43 )
return F_101 ( V_33 , V_21 ) ;
F_18 ( V_10 ) ;
V_10 -> V_26 . V_58 = V_240 ;
V_10 -> V_33 = V_62 ;
V_10 -> V_36 = V_43 ;
V_10 -> V_26 . V_27 = F_14 ( V_43 ) ;
V_10 -> V_26 . V_241 = F_93 ( V_105 -> V_242 ) ;
F_15 ( V_10 ) ;
F_91 ( V_43 , V_10 ) ;
V_10 -> V_26 . V_243 = V_244 ;
if ( V_43 -> V_245 == V_246 ) {
V_10 -> V_26 . V_243 |= V_247 ;
V_10 -> V_26 . V_248 = V_21 -> V_248 |
( V_249 << V_250 ) ;
F_4 ( V_21 ) ;
} else {
if ( F_14 ( V_43 ) )
V_10 -> V_26 . V_243 |= V_251 ;
V_10 -> V_26 . V_248 = V_21 -> V_248 |
( V_252 << V_250 ) ;
}
V_10 -> V_26 . V_253 = V_10 -> V_16 . V_39 ;
if ( ! V_10 -> V_16 . V_39 ) {
V_10 -> V_26 . V_59 = ( T_1 ) V_2 -> V_113 ;
V_10 -> V_26 . V_61 = ( T_1 ) ( ( T_2 ) V_2 -> V_113 >> 32 ) ;
V_10 -> V_26 . V_253 = 1 ;
}
F_106 ( V_62 , V_10 ) ;
return 0 ;
}
static struct V_117 *
F_107 ( struct V_81 * V_82 ,
T_5 V_103 , T_5 V_254 ,
T_6 V_255 )
{
struct V_127 * V_128 ;
struct V_117 * V_118 ;
struct V_1 * V_2 ;
struct V_83 * V_84 ;
if ( ! V_82 ) {
F_21 ( V_68 L_15 ) ;
return NULL ;
}
V_84 = V_82 -> V_22 ;
V_128 = V_84 -> V_2 -> V_128 ;
V_2 = F_64 ( V_128 ) ;
if ( F_1 ( V_2 ) )
return NULL ;
if ( V_103 > V_2 -> V_171 )
V_103 = V_2 -> V_171 ;
else if ( V_103 < V_256 )
V_103 = V_256 ;
V_118 = F_108 ( & V_257 , V_128 ,
V_103 , 0 , sizeof( struct V_9 ) ,
V_255 , V_258 ) ;
if ( ! V_118 )
return NULL ;
if ( F_41 ( V_2 , V_118 -> V_22 ) )
goto V_259;
return V_118 ;
V_259:
F_109 ( V_118 ) ;
return NULL ;
}
static void F_110 ( struct V_117 * V_118 )
{
struct V_98 * V_34 = V_118 -> V_22 ;
struct V_127 * V_128 = F_104 ( V_118 ) ;
struct V_1 * V_2 = F_64 ( V_128 ) ;
F_39 ( V_2 , V_34 ) ;
F_109 ( V_118 ) ;
}
static struct V_260 *
F_111 ( struct V_117 * V_118 , T_6 V_261 )
{
struct V_127 * V_128 = F_104 ( V_118 ) ;
struct V_1 * V_2 = F_64 ( V_128 ) ;
struct V_62 * V_62 ;
struct V_260 * V_66 ;
struct V_228 * V_33 ;
V_66 = F_112 ( V_118 , sizeof( * V_62 ) ,
V_261 ) ;
if ( ! V_66 )
return NULL ;
V_33 = V_66 -> V_22 ;
V_62 = V_33 -> V_22 ;
V_62 -> V_66 = V_66 ;
V_62 -> V_2 = V_2 ;
F_113 ( & V_62 -> V_262 , 0 ) ;
V_62 -> V_82 = NULL ;
F_114 ( & V_62 -> V_232 ) ;
if ( F_83 ( V_2 , V_62 ) ) {
F_7 ( V_38 , V_33 ,
L_16 ) ;
goto V_263;
}
return V_66 ;
V_263:
F_115 ( V_66 ) ;
return NULL ;
}
static int F_116 ( struct V_117 * V_118 ,
struct V_260 * V_66 ,
T_7 V_264 , int V_265 )
{
struct V_228 * V_33 = V_66 -> V_22 ;
struct V_62 * V_62 = V_33 -> V_22 ;
struct V_127 * V_128 = F_104 ( V_118 ) ;
struct V_1 * V_2 = F_64 ( V_128 ) ;
struct V_83 * V_84 ;
struct V_81 * V_82 ;
int V_266 ;
V_82 = F_117 ( V_264 ) ;
if ( ! V_82 )
return - V_267 ;
if ( F_1 ( V_2 ) )
return - V_268 ;
V_84 = V_82 -> V_22 ;
if ( ( V_84 -> V_88 == V_269 ) ||
( V_84 -> V_88 == V_270 ) )
return - V_267 ;
if ( F_118 ( V_118 , V_66 , V_265 ) )
return - V_267 ;
if ( V_84 -> V_2 != V_2 ) {
F_7 ( V_38 , V_66 -> V_22 ,
L_17 ,
V_84 , V_84 -> V_2 -> V_149 -> V_271 ) ;
F_7 ( V_38 , V_66 -> V_22 ,
L_18 ,
V_2 -> V_149 -> V_271 ) ;
return - V_272 ;
}
V_84 -> V_33 = V_62 ;
V_62 -> V_82 = V_84 ;
V_62 -> V_273 = V_84 -> V_90 ;
V_62 -> V_274 = V_84 -> V_275 ;
V_266 = F_19 ( V_2 , V_62 ,
V_84 -> V_90 ) ;
if ( F_2 ( V_135 , & V_84 -> V_2 -> V_130 ) )
F_119 ( V_62 , 0 ) ;
F_120 ( V_62 -> V_82 , V_276 ) ;
return V_266 ;
}
static void F_121 ( struct V_260 * V_66 )
{
struct V_228 * V_33 = V_66 -> V_22 ;
struct V_62 * V_62 = V_33 -> V_22 ;
struct V_127 * V_128 ;
struct V_1 * V_2 ;
struct V_277 * V_278 , * V_125 ;
unsigned V_279 = 0 ;
struct V_280 * V_281 ;
V_128 = F_104 ( F_122 ( V_66 ) ) ;
V_2 = F_64 ( V_128 ) ;
F_82 ( V_2 , V_62 ) ;
if ( F_105 ( & V_62 -> V_262 ) ) {
F_123 (cpu) {
V_281 = & F_124 ( V_282 , V_279 ) ;
F_100 ( & V_281 -> V_283 ) ;
F_125 (work, tmp,
&p->work_list, list) {
if ( V_278 -> V_34 == V_33 -> V_34 &&
V_278 -> V_62 == V_62 ) {
F_51 ( & V_278 -> V_124 ) ;
F_26 ( V_278 ) ;
if ( ! F_126 (
& V_62 -> V_262 ) )
break;
}
}
F_97 ( & V_281 -> V_283 ) ;
}
}
F_115 ( V_66 ) ;
}
static int F_127 ( struct V_81 * V_82 ,
enum V_284 V_285 , char * V_211 )
{
struct V_83 * V_84 = V_82 -> V_22 ;
struct V_1 * V_2 = V_84 -> V_2 ;
int V_286 = - V_287 ;
if ( ! V_2 )
return - V_287 ;
switch ( V_285 ) {
case V_288 :
F_128 ( & V_2 -> V_182 ) ;
if ( V_84 -> V_289 )
V_286 = sprintf ( V_211 , L_19 , V_84 -> V_289 -> V_290 ) ;
F_129 ( & V_2 -> V_182 ) ;
break;
case V_291 :
F_128 ( & V_2 -> V_182 ) ;
if ( V_84 -> V_289 )
V_286 = sprintf ( V_211 , L_20 , & V_84 -> V_289 -> V_292 ) ;
F_129 ( & V_2 -> V_182 ) ;
break;
default:
return - V_293 ;
}
return V_286 ;
}
static int F_130 ( struct V_127 * V_128 ,
enum V_294 V_285 , char * V_211 )
{
struct V_1 * V_2 = F_64 ( V_128 ) ;
int V_286 = 0 ;
switch ( V_285 ) {
case V_295 :
V_286 = F_131 ( V_211 , V_2 -> V_138 -> V_296 , 6 ) ;
break;
case V_297 :
V_286 = sprintf ( V_211 , L_21 , V_2 -> V_149 -> V_271 ) ;
break;
case V_298 : {
struct V_123 * V_299 = & V_2 -> V_126 ;
F_55 ( & V_2 -> V_120 ) ;
if ( ! F_132 ( & V_2 -> V_126 ) ) {
struct V_83 * V_84 ;
struct V_300 * V_301 ;
V_84 = F_133 ( V_299 ,
struct V_83 ,
V_87 ) ;
V_301 = V_84 -> V_289 ;
if ( F_2 ( V_302 , & V_301 -> V_55 ) )
V_286 = sprintf ( V_211 , L_22 , V_301 -> V_303 ) ;
else
V_286 = sprintf ( V_211 , L_20 , V_301 -> V_303 ) ;
}
F_57 ( & V_2 -> V_120 ) ;
break;
}
default:
return F_134 ( V_128 , V_285 , V_211 ) ;
}
return V_286 ;
}
static int F_135 ( struct V_260 * V_66 )
{
struct V_228 * V_33 = V_66 -> V_22 ;
struct V_62 * V_62 = V_33 -> V_22 ;
V_62 -> V_82 -> V_88 = V_304 ;
F_136 ( V_33 ) ;
V_62 -> V_82 -> V_305 . V_306 = 1 * V_185 + V_307 ;
V_62 -> V_82 -> V_305 . V_308 = V_309 ;
V_62 -> V_82 -> V_305 . V_237 = ( unsigned long ) V_62 -> V_82 ;
F_137 ( & V_62 -> V_82 -> V_305 ) ;
F_138 ( V_62 -> V_82 -> V_96 ,
V_62 -> V_82 -> V_88 != V_304 ) ;
if ( F_139 ( V_310 ) )
F_140 ( V_310 ) ;
F_141 ( & V_62 -> V_82 -> V_305 ) ;
F_142 ( V_66 ) ;
return 0 ;
}
static void F_143 ( struct V_260 * V_66 ,
struct V_311 * V_189 )
{
struct V_228 * V_33 = V_66 -> V_22 ;
V_189 -> V_312 = V_33 -> V_312 ;
V_189 -> V_313 = V_33 -> V_313 ;
V_189 -> V_314 = V_33 -> V_315 ;
V_189 -> V_316 = V_33 -> V_317 ;
V_189 -> V_318 = V_33 -> V_319 ;
V_189 -> V_320 = V_33 -> V_321 ;
V_189 -> V_322 = V_33 -> V_323 ;
V_189 -> V_324 = V_33 -> V_325 ;
V_189 -> V_326 = V_33 -> V_327 ;
V_189 -> V_328 = 0 ;
V_189 -> V_329 = 0 ;
strcpy ( V_189 -> V_330 [ 0 ] . V_331 , L_23 ) ;
V_189 -> V_330 [ 0 ] . V_332 = V_33 -> V_333 ;
V_189 -> V_334 = 1 ;
}
static struct V_1 * F_144 ( struct V_335 * V_336 )
{
struct V_337 * V_338 = (struct V_337 * ) V_336 ;
struct V_1 * V_2 ;
struct V_137 * V_138 = NULL ;
V_2 = F_145 () ;
if ( V_2 && V_2 -> V_138 )
V_138 = V_2 -> V_138 -> V_339 ( V_338 , V_340 ) ;
if ( ! V_138 ) {
F_21 ( V_38 L_24
L_25 ) ;
goto V_341;
}
V_2 = F_146 ( V_138 ) ;
if ( ! V_2 )
goto V_341;
if ( F_1 ( V_2 ) ) {
F_21 ( V_38 L_26 ) ;
goto V_341;
}
if ( V_2 -> V_149 -> V_342 > V_2 -> V_166 ) {
F_21 ( V_38 L_27 ,
V_2 -> V_149 -> V_271 , V_2 -> V_149 -> V_342 ) ;
F_21 ( V_38 L_28 ,
V_2 -> V_166 ) ;
goto V_341;
}
return V_2 ;
V_341:
return NULL ;
}
static int F_147 ( struct V_1 * V_2 ,
struct V_83 * V_82 )
{
if ( F_2 ( V_343 , & V_2 -> V_344 ) && V_82 -> V_289 )
V_2 -> V_138 -> V_345 ( V_82 -> V_289 ) ;
if ( F_2 ( V_135 , & V_2 -> V_130 ) &&
V_82 -> V_88 == V_346 ) {
if ( V_82 -> V_33 && V_82 -> V_33 -> V_66 &&
V_82 -> V_33 -> V_66 -> V_22 ) {
struct V_228 * V_33 = V_82 -> V_33 -> V_66 -> V_22 ;
F_148 ( V_347 , & V_33 -> V_348 ) ;
}
F_21 ( V_38 L_29
L_30
L_31 ,
V_2 -> V_149 -> V_271 ) ;
}
V_82 -> V_88 = V_349 ;
F_149 ( & V_82 -> V_305 ) ;
V_82 -> V_305 . V_306 = V_2 -> V_187 + V_307 ;
V_82 -> V_305 . V_308 = V_309 ;
V_82 -> V_305 . V_237 = ( unsigned long ) V_82 ;
F_137 ( & V_82 -> V_305 ) ;
F_46 ( V_2 , V_82 ) ;
if ( F_150 ( V_2 , V_82 ) )
V_82 -> V_88 = V_350 ;
F_138 ( V_82 -> V_96 ,
( V_82 -> V_88 != V_349 ) ) ;
if ( F_139 ( V_310 ) )
F_140 ( V_310 ) ;
F_141 ( & V_82 -> V_305 ) ;
F_50 ( V_2 , V_82 ) ;
if ( V_82 -> V_88 != V_350 )
F_21 ( V_38 L_32 ) ;
return 0 ;
}
static struct V_81 * F_151 ( struct V_127 * V_128 ,
struct V_335 * V_336 ,
int V_351 )
{
T_1 V_63 = V_352 ;
struct V_337 * V_338 = (struct V_337 * ) V_336 ;
struct V_353 * V_354 ;
struct V_83 * V_84 ;
struct V_1 * V_2 ;
struct V_137 * V_138 ;
struct V_355 V_356 ;
struct V_81 * V_82 ;
int V_109 = 0 ;
if ( V_128 ) {
V_2 = F_64 ( V_128 ) ;
} else
V_2 = F_144 ( V_336 ) ;
if ( ! V_2 ) {
V_109 = - V_267 ;
goto V_357;
}
F_128 ( & V_2 -> V_182 ) ;
if ( F_1 ( V_2 ) || ! V_2 -> V_64 . V_71 ) {
V_109 = - V_8 ;
goto V_358;
}
V_138 = V_2 -> V_138 ;
V_82 = F_28 ( V_2 ) ;
if ( ! V_82 ) {
V_109 = - V_80 ;
goto V_358;
}
V_84 = V_82 -> V_22 ;
F_113 ( & V_84 -> V_239 , 0 ) ;
V_63 = F_22 ( V_2 ) ;
if ( V_63 == - 1 ) {
F_21 ( V_38 L_33
L_34 , V_2 -> V_149 -> V_271 ) ;
V_109 = - V_80 ;
F_32 ( V_82 ) ;
goto V_358;
}
V_84 -> V_91 = V_2 -> V_92 ;
V_109 = F_152 ( V_2 , V_84 ) ;
if ( V_109 != 0 ) {
F_21 ( V_38 L_35
L_36 , V_2 -> V_149 -> V_271 ) ;
V_109 = - V_80 ;
goto V_359;
}
V_84 -> V_90 = ( T_3 ) V_63 ;
V_84 -> V_88 = V_360 ;
F_52 ( V_2 , V_84 ) ;
F_149 ( & V_84 -> V_305 ) ;
V_84 -> V_305 . V_306 = 2 * V_185 + V_307 ;
V_84 -> V_305 . V_308 = V_309 ;
V_84 -> V_305 . V_237 = ( unsigned long ) V_84 ;
F_137 ( & V_84 -> V_305 ) ;
if ( F_153 ( V_2 , V_84 ) ) {
if ( V_84 -> V_88 == V_361 ) {
F_21 ( V_38 L_37 ,
V_2 -> V_149 -> V_271 , V_84 -> V_90 ) ;
V_109 = - V_67 ;
} else
V_109 = - V_362 ;
F_21 ( V_38 L_38
L_36 , V_2 -> V_149 -> V_271 ) ;
F_53 ( V_2 , V_84 ) ;
goto V_363;
}
F_138 ( V_84 -> V_96 ,
V_84 -> V_88 != V_360 ) ;
if ( F_139 ( V_310 ) )
F_140 ( V_310 ) ;
F_141 ( & V_84 -> V_305 ) ;
F_53 ( V_2 , V_84 ) ;
if ( V_84 -> V_88 != V_364 ) {
if ( V_84 -> V_88 == V_361 ) {
F_21 ( V_38 L_37 ,
V_2 -> V_149 -> V_271 , V_84 -> V_90 ) ;
V_109 = - V_67 ;
} else
V_109 = - V_362 ;
goto V_363;
}
V_109 = V_138 -> V_365 ( V_138 , V_340 , V_84 -> V_275 ,
V_63 , & V_84 -> V_289 , V_84 ) ;
if ( V_109 ) {
V_109 = - V_267 ;
goto V_366;
}
V_84 -> V_289 -> V_367 = 256 * 1024 ;
V_84 -> V_289 -> V_368 = 256 * 1024 ;
F_154 ( V_369 , & V_84 -> V_289 -> V_370 ) ;
memset ( & V_356 , 0 , sizeof( V_356 ) ) ;
if ( V_336 -> V_371 == V_372 ) {
V_338 = (struct V_337 * ) V_336 ;
V_356 . V_373 . V_374 = * V_338 ;
V_356 . V_375 . V_374 . V_376 = V_338 -> V_376 ;
} else if ( V_336 -> V_371 == V_377 ) {
V_354 = (struct V_353 * ) V_336 ;
V_356 . V_373 . V_378 = * V_354 ;
V_356 . V_375 . V_378 . V_379 = V_354 -> V_379 ;
}
V_84 -> V_380 = V_307 ;
V_84 -> V_88 = V_381 ;
if ( ! F_2 ( V_343 , & V_2 -> V_344 ) ) {
V_109 = - V_267 ;
goto V_363;
} else
V_109 = V_138 -> V_382 ( V_84 -> V_289 , & V_356 ) ;
if ( V_109 )
goto V_366;
F_59 ( V_2 , V_84 ) ;
if ( F_155 ( V_84 ) )
goto V_383;
F_129 ( & V_2 -> V_182 ) ;
return V_82 ;
V_383:
F_60 ( V_2 , V_84 ) ;
V_366:
if ( F_147 ( V_2 , V_84 ) ) {
F_129 ( & V_2 -> V_182 ) ;
return F_156 ( V_109 ) ;
}
V_363:
F_157 ( V_2 , V_84 ) ;
V_359:
F_32 ( V_82 ) ;
V_358:
F_129 ( & V_2 -> V_182 ) ;
V_357:
return F_156 ( V_109 ) ;
}
static int F_158 ( struct V_81 * V_82 , int V_384 )
{
struct V_83 * V_84 ;
int V_109 = 0 ;
V_84 = V_82 -> V_22 ;
if ( ( V_84 -> V_88 == V_89 ) ||
( V_84 -> V_88 == V_385 ) ||
( V_84 -> V_88 == V_386 ) )
return - 1 ;
if ( V_84 -> V_88 == V_387 )
return 1 ;
V_109 = F_159 ( V_84 -> V_96 ,
( ( V_84 -> V_88 ==
V_386 ) ||
( V_84 -> V_88 ==
V_385 ) ||
( V_84 -> V_88 ==
V_387 ) ) ,
F_99 ( V_384 ) ) ;
if ( V_84 -> V_88 == V_386 )
V_109 = - 1 ;
if ( V_109 > 0 )
return 1 ;
else if ( ! V_109 )
return 0 ;
else
return V_109 ;
}
static int F_160 ( struct V_83 * V_84 )
{
int V_388 ;
int V_389 = 0 ;
if ( F_2 ( V_135 , & V_84 -> V_2 -> V_130 ) )
V_389 = 1 ;
switch ( V_84 -> V_88 ) {
case V_390 :
case V_386 :
case V_346 :
V_388 = 0 ;
break;
case V_381 :
case V_385 :
case V_387 :
case V_304 :
case V_391 :
case V_269 :
case V_392 :
case V_393 :
case V_394 :
V_388 = 1 ;
break;
case V_270 :
if ( V_389 )
V_388 = 0 ;
else
V_388 = 1 ;
break;
default:
V_388 = 0 ;
}
return V_388 ;
}
int F_161 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = V_84 -> V_2 ;
struct V_137 * V_138 ;
struct V_98 * V_34 = NULL ;
struct V_228 * V_33 = NULL ;
int V_388 = 0 ;
int V_395 = 0 ;
int V_396 = 0 ;
if ( ! V_2 )
return 0 ;
V_138 = V_2 -> V_138 ;
if ( ! V_138 )
return 0 ;
if ( V_84 -> V_88 == V_89 ||
V_84 -> V_88 == V_346 )
return 0 ;
if ( ! F_160 ( V_84 ) )
goto V_397;
if ( V_84 -> V_33 ) {
V_33 = V_84 -> V_33 -> V_66 -> V_22 ;
V_34 = V_33 -> V_34 ;
}
F_149 ( & V_84 -> V_305 ) ;
V_84 -> V_305 . V_306 = V_2 -> V_186 + V_307 ;
V_84 -> V_305 . V_308 = V_309 ;
V_84 -> V_305 . V_237 = ( unsigned long ) V_84 ;
F_137 ( & V_84 -> V_305 ) ;
if ( ! F_2 ( V_343 , & V_2 -> V_344 ) )
goto V_114;
if ( V_34 ) {
F_100 ( & V_34 -> V_398 ) ;
if ( V_84 -> V_88 != V_269 ) {
if ( V_34 -> V_88 == V_399 ) {
if ( V_84 -> V_88 == V_392 ) {
F_21 ( V_38 L_39
L_40
L_41 ,
V_84 -> V_2 -> V_149 -> V_271 ) ;
} else if ( V_84 -> V_88 ==
V_393 )
V_395 = 1 ;
}
} else
V_395 = 1 ;
F_97 ( & V_34 -> V_398 ) ;
}
V_84 -> V_88 = V_400 ;
if ( V_395 )
V_396 = V_138 -> V_401 ( V_84 -> V_289 ) ;
else
V_396 = V_138 -> V_402 ( V_84 -> V_289 ) ;
if ( V_396 )
F_21 ( V_38 L_42 ,
V_84 -> V_2 -> V_149 -> V_271 , V_395 , V_396 ) ;
else
F_138 ( V_84 -> V_96 ,
V_84 -> V_88 != V_400 ) ;
if ( F_139 ( V_310 ) )
F_140 ( V_310 ) ;
F_141 ( & V_84 -> V_305 ) ;
V_397:
F_60 ( V_2 , V_84 ) ;
if ( F_147 ( V_2 , V_84 ) )
return - V_267 ;
V_114:
V_84 -> V_88 = V_89 ;
return V_388 ;
}
static void F_162 ( struct V_81 * V_82 )
{
struct V_83 * V_84 ;
struct V_62 * V_62 = NULL ;
struct V_228 * V_33 = NULL ;
struct V_1 * V_2 ;
V_84 = V_82 -> V_22 ;
while ( ( V_84 -> V_88 == V_381 ) &&
! F_163 ( V_307 , V_84 -> V_380 + ( 12 * V_185 ) ) )
F_164 ( 250 ) ;
if ( V_84 -> V_33 ) {
V_62 = V_84 -> V_33 ;
V_33 = V_62 -> V_66 -> V_22 ;
F_165 ( V_33 ) ;
}
V_2 = V_84 -> V_2 ;
F_128 ( & V_2 -> V_182 ) ;
if ( V_84 -> V_88 == V_346 )
goto V_114;
if ( V_84 -> V_88 == V_89 )
goto V_403;
if ( ! F_2 ( V_4 , & V_2 -> V_5 ) ||
( V_84 -> V_91 != V_2 -> V_92 ) ) {
F_60 ( V_2 , V_84 ) ;
goto V_403;
}
if ( F_161 ( V_84 ) ) {
F_129 ( & V_2 -> V_182 ) ;
return;
}
V_403:
F_157 ( V_2 , V_84 ) ;
if ( V_62 )
V_62 -> V_82 = NULL ;
F_32 ( V_82 ) ;
V_114:
F_129 ( & V_2 -> V_182 ) ;
F_166 ( & V_2 -> V_183 ) ;
}
static int F_167 ( struct V_127 * V_128 , struct V_404 * V_405 )
{
struct V_1 * V_2 = F_64 ( V_128 ) ;
char * V_211 = ( char * ) V_405 ;
T_3 V_286 = sizeof( * V_405 ) ;
V_2 -> V_138 -> V_406 ( V_2 -> V_138 , V_407 , V_211 ,
V_286 ) ;
return 0 ;
}
static T_8 F_168 ( int V_408 , int V_285 )
{
switch ( V_408 ) {
case V_409 :
switch ( V_285 ) {
case V_297 :
case V_295 :
case V_298 :
return V_410 ;
default:
return 0 ;
}
case V_411 :
switch ( V_285 ) {
case V_412 :
case V_413 :
case V_414 :
case V_415 :
case V_291 :
case V_288 :
case V_416 :
case V_417 :
case V_418 :
case V_419 :
case V_420 :
case V_421 :
case V_422 :
case V_423 :
case V_424 :
case V_425 :
case V_426 :
case V_427 :
case V_428 :
case V_429 :
case V_430 :
case V_431 :
case V_432 :
case V_433 :
case V_434 :
case V_435 :
case V_436 :
case V_437 :
case V_438 :
case V_439 :
case V_440 :
case V_441 :
case V_442 :
case V_443 :
return V_410 ;
default:
return 0 ;
}
}
return 0 ;
}

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
V_2 -> V_111 = F_37 ( & V_2 -> V_101 -> V_102 , V_76 ,
& V_2 -> V_112 , V_79 ) ;
if ( ! V_2 -> V_111 ) {
F_21 ( V_68 L_10 ) ;
V_109 = - 1 ;
goto V_113;
}
V_2 -> V_114 = F_37 ( & V_2 -> V_101 -> V_102 , V_76 ,
& V_2 -> V_115 , V_79 ) ;
if ( ! V_2 -> V_114 ) {
F_21 ( V_68 L_11 ) ;
F_40 ( & V_2 -> V_101 -> V_102 , V_76 ,
V_2 -> V_111 , V_2 -> V_112 ) ;
V_2 -> V_111 = NULL ;
V_109 = - 1 ;
goto V_113;
}
V_110 = (struct V_14 * ) V_2 -> V_111 ;
V_51 = ( unsigned long ) V_2 -> V_115 ;
V_110 -> V_53 = V_51 & 0xffffffff ;
V_110 -> V_54 = V_51 >> 32 ;
V_110 -> V_19 = V_76 ;
V_110 -> V_55 = V_57 |
V_56 ;
V_113:
return V_109 ;
}
static void F_43 ( struct V_1 * V_2 )
{
if ( V_2 -> V_111 ) {
F_40 ( & V_2 -> V_101 -> V_102 , V_76 ,
V_2 -> V_111 , V_2 -> V_112 ) ;
V_2 -> V_111 = NULL ;
}
if ( V_2 -> V_114 ) {
F_40 ( & V_2 -> V_101 -> V_102 , V_76 ,
V_2 -> V_114 , V_2 -> V_115 ) ;
V_2 -> V_114 = NULL ;
}
return;
}
void F_44 ( struct V_116 * V_117 )
{
F_45 ( V_117 -> V_22 , V_118 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_83 * V_82 )
{
F_47 ( & V_2 -> V_119 ) ;
F_48 ( & V_82 -> V_87 , & V_2 -> V_120 ) ;
F_49 ( & V_2 -> V_119 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_83 * V_82 )
{
F_47 ( & V_2 -> V_119 ) ;
F_51 ( & V_82 -> V_87 ) ;
F_49 ( & V_2 -> V_119 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_83 * V_82 )
{
F_47 ( & V_2 -> V_119 ) ;
F_48 ( & V_82 -> V_87 , & V_2 -> V_121 ) ;
F_49 ( & V_2 -> V_119 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_83 * V_82 )
{
F_47 ( & V_2 -> V_119 ) ;
F_51 ( & V_82 -> V_87 ) ;
F_49 ( & V_2 -> V_119 ) ;
return 0 ;
}
struct V_83 *
F_54 ( struct V_1 * V_2 , T_1 V_63 )
{
struct V_122 * V_123 ;
struct V_122 * V_124 ;
struct V_83 * V_82 ;
F_55 ( & V_2 -> V_119 ) ;
F_56 (list, tmp, &hba->ep_ofld_list) {
V_82 = (struct V_83 * ) V_123 ;
if ( V_82 -> V_90 == V_63 )
break;
V_82 = NULL ;
}
F_57 ( & V_2 -> V_119 ) ;
if ( ! V_82 )
F_21 ( V_68 L_12 , V_63 ) ;
return V_82 ;
}
struct V_83 *
F_58 ( struct V_1 * V_2 , T_1 V_63 )
{
struct V_122 * V_123 ;
struct V_122 * V_124 ;
struct V_83 * V_82 ;
F_55 ( & V_2 -> V_119 ) ;
F_56 (list, tmp, &hba->ep_destroy_list) {
V_82 = (struct V_83 * ) V_123 ;
if ( V_82 -> V_90 == V_63 )
break;
V_82 = NULL ;
}
F_57 ( & V_2 -> V_119 ) ;
if ( ! V_82 )
F_21 ( V_68 L_12 , V_63 ) ;
return V_82 ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_83 * V_82 )
{
F_47 ( & V_2 -> V_119 ) ;
F_48 ( & V_82 -> V_87 , & V_2 -> V_125 ) ;
F_49 ( & V_2 -> V_119 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_83 * V_82 )
{
F_47 ( & V_2 -> V_119 ) ;
F_51 ( & V_82 -> V_87 ) ;
F_49 ( & V_2 -> V_119 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_126 * V_127 )
{
if ( F_2 ( V_128 , & V_2 -> V_129 ) )
V_127 -> V_130 = V_131 ;
else if ( F_2 ( V_132 , & V_2 -> V_129 ) )
V_127 -> V_130 = V_133 ;
else if ( F_2 ( V_134 , & V_2 -> V_129 ) )
V_127 -> V_130 = V_135 ;
else
V_127 -> V_130 = V_131 ;
}
struct V_1 * F_62 ( struct V_136 * V_137 )
{
struct V_126 * V_127 ;
struct V_1 * V_2 ;
V_127 = F_63 ( & V_138 , sizeof( * V_2 ) , 0 ) ;
if ( ! V_127 )
return NULL ;
V_127 -> V_139 = V_137 -> V_101 -> V_140 ;
V_127 -> V_141 = V_142 ;
V_127 -> V_143 = V_144 ;
V_127 -> V_145 = 0 ;
V_127 -> V_146 = 512 ;
V_127 -> V_147 = 16 ;
V_2 = F_64 ( V_127 ) ;
V_2 -> V_127 = V_127 ;
V_2 -> V_148 = V_137 -> V_148 ;
V_2 -> V_101 = V_137 -> V_101 ;
F_65 ( V_2 -> V_101 ) ;
V_2 -> V_149 = V_2 -> V_101 -> V_150 ;
V_2 -> V_151 = V_2 -> V_101 -> V_152 ;
V_2 -> V_153 = V_2 -> V_101 -> V_154 ;
V_2 -> V_155 = V_2 -> V_101 -> V_156 ;
V_2 -> V_157 = F_66 ( V_2 -> V_101 -> V_158 ) ;
V_2 -> V_159 = F_67 ( V_2 -> V_101 -> V_158 ) ;
F_68 ( V_2 ) ;
F_61 ( V_2 , V_127 ) ;
if ( F_2 ( V_132 , & V_2 -> V_129 ) ) {
V_2 -> V_160 = F_69 ( V_2 -> V_148 -> V_161 ,
V_162 ) ;
if ( ! V_2 -> V_160 )
goto V_163;
} else if ( F_2 ( V_134 , & V_2 -> V_129 ) ) {
V_2 -> V_160 = F_69 ( V_2 -> V_148 -> V_161 , 4096 ) ;
if ( ! V_2 -> V_160 )
goto V_163;
}
if ( F_42 ( V_2 ) )
goto V_164;
F_30 ( & V_2 -> V_121 ) ;
F_30 ( & V_2 -> V_125 ) ;
F_30 ( & V_2 -> V_120 ) ;
F_70 ( & V_2 -> V_119 ) ;
V_2 -> V_165 = V_166 ;
V_2 -> V_69 = V_144 ;
if ( F_24 ( V_2 ) )
goto V_167;
if ( F_2 ( V_134 , & V_2 -> V_129 ) ) {
if ( V_168 && V_168 <= V_169 )
V_2 -> V_170 = V_168 ;
else
V_2 -> V_170 = V_171 ;
} else {
if ( V_168 && V_168 <= V_172 )
V_2 -> V_170 = V_168 ;
else
V_2 -> V_170 = V_173 ;
}
V_2 -> V_174 = V_175 ;
V_2 -> V_176 = V_2 -> V_170 + V_175 ;
if ( F_2 ( V_134 , & V_2 -> V_129 ) ) {
if ( V_2 -> V_176 > V_177 )
V_2 -> V_176 = V_177 ;
} else if ( V_2 -> V_176 > V_178 )
V_2 -> V_176 = V_178 ;
V_2 -> V_179 = V_2 -> V_170 / 2 ;
F_71 ( & V_2 -> V_180 ) ;
F_72 ( & V_2 -> V_181 ) ;
F_31 ( & V_2 -> V_182 ) ;
if ( F_2 ( V_134 , & V_2 -> V_129 ) ) {
V_2 -> V_183 = 30 * V_184 ;
V_2 -> V_185 = 20 * V_184 ;
V_2 -> V_186 = 6 * V_184 ;
} else {
V_2 -> V_183 = 20 * V_184 ;
V_2 -> V_185 = 10 * V_184 ;
V_2 -> V_186 = 2 * V_184 ;
}
if ( F_73 ( V_127 , & V_2 -> V_101 -> V_102 ) )
goto V_187;
return V_2 ;
V_187:
F_27 ( V_2 ) ;
V_167:
F_43 ( V_2 ) ;
V_164:
if ( V_2 -> V_160 ) {
F_74 ( V_2 -> V_160 ) ;
V_2 -> V_160 = NULL ;
}
V_163:
F_75 ( V_2 -> V_101 ) ;
F_76 ( V_127 ) ;
return NULL ;
}
void F_77 ( struct V_1 * V_2 )
{
struct V_126 * V_127 = V_2 -> V_127 ;
F_78 ( V_127 ) ;
F_30 ( & V_2 -> V_121 ) ;
F_30 ( & V_2 -> V_125 ) ;
F_30 ( & V_2 -> V_120 ) ;
F_75 ( V_2 -> V_101 ) ;
if ( V_2 -> V_160 ) {
F_74 ( V_2 -> V_160 ) ;
V_2 -> V_160 = NULL ;
}
F_43 ( V_2 ) ;
F_27 ( V_2 ) ;
F_79 ( V_127 ) ;
}
static void F_80 ( struct V_1 * V_2 ,
struct V_62 * V_62 )
{
if ( V_62 -> V_188 . V_189 ) {
F_40 ( & V_2 -> V_101 -> V_102 , V_76 ,
V_62 -> V_188 . V_189 ,
V_62 -> V_188 . V_190 ) ;
V_62 -> V_188 . V_189 = NULL ;
}
if ( V_62 -> V_188 . V_191 ) {
F_40 ( & V_2 -> V_101 -> V_102 , V_76 ,
V_62 -> V_188 . V_191 ,
V_62 -> V_188 . V_192 ) ;
V_62 -> V_188 . V_191 = NULL ;
}
if ( V_62 -> V_188 . V_193 ) {
F_40 ( & V_2 -> V_101 -> V_102 ,
V_194 ,
V_62 -> V_188 . V_193 ,
V_62 -> V_188 . V_195 ) ;
V_62 -> V_188 . V_193 = NULL ;
}
if ( V_62 -> V_188 . V_196 ) {
F_40 ( & V_2 -> V_101 -> V_102 ,
V_194 ,
V_62 -> V_188 . V_196 ,
V_62 -> V_188 . V_197 ) ;
V_62 -> V_188 . V_196 = NULL ;
}
}
static int F_81 ( struct V_1 * V_2 ,
struct V_62 * V_62 )
{
V_62 -> V_188 . V_196 =
F_37 ( & V_2 -> V_101 -> V_102 ,
V_194 ,
& V_62 -> V_188 . V_197 ,
V_79 ) ;
if ( V_62 -> V_188 . V_196 == NULL )
goto V_198;
V_62 -> V_188 . V_199 = 0 ;
V_62 -> V_188 . V_200 = V_62 -> V_188 . V_196 ;
V_62 -> V_188 . V_193 =
F_37 ( & V_2 -> V_101 -> V_102 ,
V_194 ,
& V_62 -> V_188 . V_195 ,
V_79 ) ;
if ( V_62 -> V_188 . V_193 == NULL )
goto V_201;
V_62 -> V_188 . V_202 = V_194 ;
V_62 -> V_188 . V_203 = V_62 -> V_188 . V_193 ;
V_62 -> V_188 . V_191 =
F_37 ( & V_2 -> V_101 -> V_102 , V_76 ,
& V_62 -> V_188 . V_192 , V_79 ) ;
if ( V_62 -> V_188 . V_191 == NULL )
goto V_204;
V_62 -> V_188 . V_189 =
F_37 ( & V_2 -> V_101 -> V_102 , V_76 ,
& V_62 -> V_188 . V_190 ,
V_79 ) ;
if ( V_62 -> V_188 . V_189 == NULL )
goto V_205;
return 0 ;
V_205:
F_40 ( & V_2 -> V_101 -> V_102 , V_76 ,
V_62 -> V_188 . V_191 ,
V_62 -> V_188 . V_192 ) ;
V_62 -> V_188 . V_191 = NULL ;
V_204:
F_40 ( & V_2 -> V_101 -> V_102 , V_194 ,
V_62 -> V_188 . V_193 ,
V_62 -> V_188 . V_195 ) ;
V_62 -> V_188 . V_193 = NULL ;
V_201:
F_40 ( & V_2 -> V_101 -> V_102 , V_194 ,
V_62 -> V_188 . V_196 ,
V_62 -> V_188 . V_197 ) ;
V_62 -> V_188 . V_196 = NULL ;
V_198:
F_7 ( V_68 , V_62 -> V_66 -> V_22 ,
L_13 ) ;
return - V_80 ;
}
static void F_82 ( struct V_62 * V_62 )
{
struct V_14 * V_15 ;
V_15 = (struct V_14 * ) V_62 -> V_188 . V_191 ;
V_15 -> V_54 =
( T_1 ) ( ( T_2 ) V_62 -> V_188 . V_197 >> 32 ) ;
V_15 -> V_53 = ( T_1 ) V_62 -> V_188 . V_197 ;
V_15 -> V_19 = V_62 -> V_188 . V_200 -
V_62 -> V_188 . V_196 ;
V_15 -> V_206 = 0 ;
V_15 -> V_55 = V_57 |
V_56 ;
V_15 = (struct V_14 * ) V_62 -> V_188 . V_189 ;
V_15 -> V_54 = ( T_2 ) V_62 -> V_188 . V_195 >> 32 ;
V_15 -> V_53 = ( T_1 ) V_62 -> V_188 . V_195 ;
V_15 -> V_19 = V_194 ;
V_15 -> V_206 = 0 ;
V_15 -> V_55 = V_57 |
V_56 ;
}
static int F_83 ( struct V_20 * V_21 )
{
struct V_9 * V_10 = V_21 -> V_22 ;
struct V_62 * V_62 = V_10 -> V_33 ;
int V_109 = 0 ;
char * V_207 ;
int V_208 ;
F_82 ( V_62 ) ;
switch ( V_21 -> V_105 -> V_209 & V_210 ) {
case V_211 :
F_84 ( V_62 , V_21 ) ;
break;
case V_212 :
V_208 = V_62 -> V_188 . V_199 ;
V_207 = V_62 -> V_188 . V_196 ;
if ( V_208 )
V_109 = F_85 ( V_62 , V_21 ,
V_207 , V_208 , 1 ) ;
else
V_109 = F_85 ( V_62 , V_21 ,
NULL , 0 , 1 ) ;
break;
case V_213 :
V_109 = F_86 ( V_62 , V_21 ) ;
break;
case V_214 :
V_109 = F_87 ( V_62 , V_21 ) ;
break;
case V_215 :
V_109 = F_88 ( V_62 , V_21 ) ;
break;
default:
F_7 ( V_38 , V_62 -> V_66 -> V_22 ,
L_14 ,
V_21 -> V_105 -> V_209 ) ;
}
return V_109 ;
}
static void F_89 ( struct V_42 * V_43 , struct V_9 * V_10 )
{
T_1 V_216 ;
int V_217 ;
T_4 * V_218 ;
T_1 * V_219 ;
T_1 V_220 [ 2 ] ;
F_90 ( V_43 -> V_150 -> V_221 , (struct V_220 * ) V_220 ) ;
V_10 -> V_26 . V_221 [ 0 ] = F_91 ( V_220 [ 0 ] ) ;
V_10 -> V_26 . V_221 [ 1 ] = F_91 ( V_220 [ 1 ] ) ;
V_217 = V_10 -> V_36 -> V_25 / sizeof( V_216 ) ;
V_218 = ( T_4 * ) V_43 -> V_222 ;
V_219 = ( T_1 * ) V_10 -> V_26 . V_223 ;
while ( V_217 -- ) {
memcpy ( & V_216 , ( const void * ) V_218 , 4 ) ;
* V_219 = F_92 ( V_216 ) ;
V_218 += 4 ;
V_219 ++ ;
}
if ( V_43 -> V_25 & 0x3 ) {
V_216 = ( T_1 ) V_218 [ 0 ] | ( ( T_1 ) V_218 [ 1 ] << 8 ) ;
* V_219 = F_92 ( V_216 ) ;
}
}
static void F_93 ( struct V_20 * V_21 )
{
struct V_224 * V_33 = V_21 -> V_33 ;
struct V_62 * V_62 = V_33 -> V_22 ;
struct V_1 * V_2 = V_62 -> V_2 ;
if ( ! V_21 -> V_43 || V_21 -> V_88 == V_225 )
return;
if ( V_21 -> V_88 == V_226 ) {
F_94 ( V_2 , V_21 -> V_22 ) ;
F_95 ( & V_33 -> V_34 -> V_180 ) ;
F_96 ( & V_62 -> V_227 ,
F_97 ( V_228 ) ) ;
F_98 ( & V_33 -> V_34 -> V_180 ) ;
}
F_16 ( V_21 -> V_22 ) ;
}
static int
F_99 ( struct V_224 * V_33 , struct V_20 * V_21 )
{
struct V_62 * V_62 = V_33 -> V_22 ;
struct V_9 * V_10 = V_21 -> V_22 ;
memset ( V_62 -> V_188 . V_196 , 0 , V_194 ) ;
F_18 ( V_10 ) ;
V_62 -> V_188 . V_199 = V_21 -> V_229 ;
if ( V_21 -> V_229 ) {
memcpy ( V_62 -> V_188 . V_196 , V_21 -> V_230 ,
V_21 -> V_229 ) ;
V_62 -> V_188 . V_200 =
V_62 -> V_188 . V_196 + V_21 -> V_229 ;
}
V_10 -> V_33 = V_33 -> V_22 ;
V_10 -> V_36 = NULL ;
return F_83 ( V_21 ) ;
}
static int F_100 ( struct V_20 * V_21 )
{
struct V_224 * V_33 = V_21 -> V_33 ;
struct V_98 * V_34 = V_33 -> V_34 ;
struct V_126 * V_127 = F_101 ( V_34 -> V_117 ) ;
struct V_1 * V_2 = F_64 ( V_127 ) ;
struct V_62 * V_62 = V_33 -> V_22 ;
struct V_42 * V_43 = V_21 -> V_43 ;
struct V_9 * V_10 = V_21 -> V_22 ;
struct V_231 * V_105 = (struct V_231 * ) V_21 -> V_105 ;
if ( V_62 -> V_82 -> V_232 + 1 > V_2 -> V_170 )
return - V_80 ;
if ( ! V_43 )
return F_99 ( V_33 , V_21 ) ;
F_18 ( V_10 ) ;
V_10 -> V_26 . V_58 = V_233 ;
V_10 -> V_33 = V_62 ;
V_10 -> V_36 = V_43 ;
V_10 -> V_26 . V_27 = F_14 ( V_43 ) ;
V_10 -> V_26 . V_234 = F_91 ( V_105 -> V_235 ) ;
F_15 ( V_10 ) ;
F_89 ( V_43 , V_10 ) ;
V_10 -> V_26 . V_236 = V_237 ;
if ( V_43 -> V_238 == V_239 ) {
V_10 -> V_26 . V_236 |= V_240 ;
V_10 -> V_26 . V_241 = V_21 -> V_241 |
( V_242 << V_243 ) ;
F_4 ( V_21 ) ;
} else {
if ( F_14 ( V_43 ) )
V_10 -> V_26 . V_236 |= V_244 ;
V_10 -> V_26 . V_241 = V_21 -> V_241 |
( V_245 << V_243 ) ;
}
V_10 -> V_26 . V_246 = V_10 -> V_16 . V_39 ;
if ( ! V_10 -> V_16 . V_39 ) {
V_10 -> V_26 . V_59 = ( T_1 ) V_2 -> V_112 ;
V_10 -> V_26 . V_61 = ( T_1 ) ( ( T_2 ) V_2 -> V_112 >> 32 ) ;
V_10 -> V_26 . V_246 = 1 ;
}
F_102 ( V_62 , V_10 ) ;
return 0 ;
}
static struct V_116 *
F_103 ( struct V_81 * V_82 ,
T_5 V_103 , T_5 V_247 ,
T_6 V_248 )
{
struct V_126 * V_127 ;
struct V_116 * V_117 ;
struct V_1 * V_2 ;
struct V_83 * V_84 ;
if ( ! V_82 ) {
F_21 ( V_68 L_15 ) ;
return NULL ;
}
V_84 = V_82 -> V_22 ;
V_127 = V_84 -> V_2 -> V_127 ;
V_2 = F_64 ( V_127 ) ;
if ( F_1 ( V_2 ) )
return NULL ;
if ( V_103 > V_2 -> V_170 )
V_103 = V_2 -> V_170 ;
else if ( V_103 < V_249 )
V_103 = V_249 ;
V_117 = F_104 ( & V_250 , V_127 ,
V_103 , 0 , sizeof( struct V_9 ) ,
V_248 , V_251 ) ;
if ( ! V_117 )
return NULL ;
if ( F_41 ( V_2 , V_117 -> V_22 ) )
goto V_252;
return V_117 ;
V_252:
F_105 ( V_117 ) ;
return NULL ;
}
static void F_106 ( struct V_116 * V_117 )
{
struct V_98 * V_34 = V_117 -> V_22 ;
struct V_126 * V_127 = F_101 ( V_117 ) ;
struct V_1 * V_2 = F_64 ( V_127 ) ;
F_39 ( V_2 , V_34 ) ;
F_105 ( V_117 ) ;
}
static struct V_253 *
F_107 ( struct V_116 * V_117 , T_6 V_254 )
{
struct V_126 * V_127 = F_101 ( V_117 ) ;
struct V_1 * V_2 = F_64 ( V_127 ) ;
struct V_62 * V_62 ;
struct V_253 * V_66 ;
struct V_224 * V_33 ;
V_66 = F_108 ( V_117 , sizeof( * V_62 ) ,
V_254 ) ;
if ( ! V_66 )
return NULL ;
V_33 = V_66 -> V_22 ;
V_62 = V_33 -> V_22 ;
V_62 -> V_66 = V_66 ;
V_62 -> V_2 = V_2 ;
V_62 -> V_82 = NULL ;
F_109 ( & V_62 -> V_227 ) ;
if ( F_81 ( V_2 , V_62 ) ) {
F_7 ( V_38 , V_33 ,
L_16 ) ;
goto V_255;
}
return V_66 ;
V_255:
F_110 ( V_66 ) ;
return NULL ;
}
static int F_111 ( struct V_116 * V_117 ,
struct V_253 * V_66 ,
T_7 V_256 , int V_257 )
{
struct V_224 * V_33 = V_66 -> V_22 ;
struct V_62 * V_62 = V_33 -> V_22 ;
struct V_126 * V_127 = F_101 ( V_117 ) ;
struct V_1 * V_2 = F_64 ( V_127 ) ;
struct V_83 * V_84 ;
struct V_81 * V_82 ;
int V_258 ;
V_82 = F_112 ( V_256 ) ;
if ( ! V_82 )
return - V_259 ;
if ( F_1 ( V_2 ) )
return - V_260 ;
V_84 = V_82 -> V_22 ;
if ( ( V_84 -> V_88 == V_261 ) ||
( V_84 -> V_88 == V_262 ) )
return - V_259 ;
if ( F_113 ( V_117 , V_66 , V_257 ) )
return - V_259 ;
if ( V_84 -> V_2 != V_2 ) {
F_7 ( V_38 , V_66 -> V_22 ,
L_17 ,
V_84 , V_84 -> V_2 -> V_148 -> V_263 ) ;
F_7 ( V_38 , V_66 -> V_22 ,
L_18 ,
V_2 -> V_148 -> V_263 ) ;
return - V_264 ;
}
V_84 -> V_33 = V_62 ;
V_62 -> V_82 = V_84 ;
V_62 -> V_265 = V_84 -> V_90 ;
V_62 -> V_266 = V_84 -> V_267 ;
V_258 = F_19 ( V_2 , V_62 ,
V_84 -> V_90 ) ;
if ( F_2 ( V_134 , & V_84 -> V_2 -> V_129 ) )
F_114 ( V_62 , 0 ) ;
F_115 ( V_62 -> V_82 , V_268 ) ;
return V_258 ;
}
static void F_116 ( struct V_253 * V_66 )
{
struct V_224 * V_33 = V_66 -> V_22 ;
struct V_62 * V_62 = V_33 -> V_22 ;
struct V_126 * V_127 ;
struct V_1 * V_2 ;
V_127 = F_101 ( F_117 ( V_66 ) ) ;
V_2 = F_64 ( V_127 ) ;
F_80 ( V_2 , V_62 ) ;
F_110 ( V_66 ) ;
}
static int F_118 ( struct V_81 * V_82 ,
enum V_269 V_270 , char * V_207 )
{
struct V_83 * V_84 = V_82 -> V_22 ;
struct V_1 * V_2 = V_84 -> V_2 ;
int V_271 = - V_272 ;
if ( ! V_2 )
return - V_272 ;
switch ( V_270 ) {
case V_273 :
F_119 ( & V_2 -> V_181 ) ;
if ( V_84 -> V_274 )
V_271 = sprintf ( V_207 , L_19 , V_84 -> V_274 -> V_275 ) ;
F_120 ( & V_2 -> V_181 ) ;
break;
case V_276 :
F_119 ( & V_2 -> V_181 ) ;
if ( V_84 -> V_274 )
V_271 = sprintf ( V_207 , L_20 , & V_84 -> V_274 -> V_277 ) ;
F_120 ( & V_2 -> V_181 ) ;
break;
default:
return - V_278 ;
}
return V_271 ;
}
static int F_121 ( struct V_126 * V_127 ,
enum V_279 V_270 , char * V_207 )
{
struct V_1 * V_2 = F_64 ( V_127 ) ;
int V_271 = 0 ;
switch ( V_270 ) {
case V_280 :
V_271 = F_122 ( V_207 , V_2 -> V_137 -> V_281 , 6 ) ;
break;
case V_282 :
V_271 = sprintf ( V_207 , L_21 , V_2 -> V_148 -> V_263 ) ;
break;
case V_283 : {
struct V_122 * V_284 = & V_2 -> V_125 ;
F_55 ( & V_2 -> V_119 ) ;
if ( ! F_123 ( & V_2 -> V_125 ) ) {
struct V_83 * V_84 ;
struct V_285 * V_286 ;
V_84 = F_124 ( V_284 ,
struct V_83 ,
V_87 ) ;
V_286 = V_84 -> V_274 ;
if ( F_2 ( V_287 , & V_286 -> V_55 ) )
V_271 = sprintf ( V_207 , L_22 , V_286 -> V_288 ) ;
else
V_271 = sprintf ( V_207 , L_20 , V_286 -> V_288 ) ;
}
F_57 ( & V_2 -> V_119 ) ;
break;
}
default:
return F_125 ( V_127 , V_270 , V_207 ) ;
}
return V_271 ;
}
static int F_126 ( struct V_253 * V_66 )
{
struct V_224 * V_33 = V_66 -> V_22 ;
struct V_62 * V_62 = V_33 -> V_22 ;
V_62 -> V_82 -> V_88 = V_289 ;
F_127 ( V_33 ) ;
V_62 -> V_82 -> V_290 . V_291 = 1 * V_184 + V_292 ;
V_62 -> V_82 -> V_290 . V_293 = V_294 ;
V_62 -> V_82 -> V_290 . V_230 = ( unsigned long ) V_62 -> V_82 ;
F_128 ( & V_62 -> V_82 -> V_290 ) ;
F_129 ( V_62 -> V_82 -> V_96 ,
V_62 -> V_82 -> V_88 != V_289 ) ;
if ( F_130 ( V_295 ) )
F_131 ( V_295 ) ;
F_132 ( & V_62 -> V_82 -> V_290 ) ;
F_133 ( V_66 ) ;
return 0 ;
}
static void F_134 ( struct V_253 * V_66 ,
struct V_296 * V_297 )
{
struct V_224 * V_33 = V_66 -> V_22 ;
V_297 -> V_298 = V_33 -> V_298 ;
V_297 -> V_299 = V_33 -> V_299 ;
V_297 -> V_300 = V_33 -> V_301 ;
V_297 -> V_302 = V_33 -> V_303 ;
V_297 -> V_304 = V_33 -> V_305 ;
V_297 -> V_306 = V_33 -> V_307 ;
V_297 -> V_308 = V_33 -> V_309 ;
V_297 -> V_310 = V_33 -> V_311 ;
V_297 -> V_312 = V_33 -> V_313 ;
V_297 -> V_314 = 3 ;
strcpy ( V_297 -> V_315 [ 2 ] . V_316 , L_23 ) ;
V_297 -> V_315 [ 2 ] . V_317 = V_33 -> V_318 ;
V_297 -> V_319 = 0 ;
V_297 -> V_320 = 0 ;
V_297 -> V_314 = 0 ;
}
static struct V_1 * F_135 ( struct V_321 * V_322 )
{
struct V_323 * V_324 = (struct V_323 * ) V_322 ;
struct V_1 * V_2 ;
struct V_136 * V_137 = NULL ;
V_2 = F_136 () ;
if ( V_2 && V_2 -> V_137 )
V_137 = V_2 -> V_137 -> V_325 ( V_324 , V_326 ) ;
if ( ! V_137 ) {
F_21 ( V_38 L_24
L_25 ) ;
goto V_327;
}
V_2 = F_137 ( V_137 ) ;
if ( ! V_2 )
goto V_327;
if ( F_1 ( V_2 ) ) {
F_21 ( V_38 L_26 ) ;
goto V_327;
}
if ( V_2 -> V_148 -> V_328 > V_2 -> V_165 ) {
F_21 ( V_38 L_27 ,
V_2 -> V_148 -> V_263 , V_2 -> V_148 -> V_328 ) ;
F_21 ( V_38 L_28 ,
V_2 -> V_165 ) ;
goto V_327;
}
return V_2 ;
V_327:
return NULL ;
}
static int F_138 ( struct V_1 * V_2 ,
struct V_83 * V_82 )
{
if ( F_2 ( V_329 , & V_2 -> V_330 ) && V_82 -> V_274 )
V_2 -> V_137 -> V_331 ( V_82 -> V_274 ) ;
if ( F_2 ( V_134 , & V_2 -> V_129 ) &&
V_82 -> V_88 == V_332 ) {
if ( V_82 -> V_33 && V_82 -> V_33 -> V_66 &&
V_82 -> V_33 -> V_66 -> V_22 ) {
struct V_224 * V_33 = V_82 -> V_33 -> V_66 -> V_22 ;
F_139 ( V_333 , & V_33 -> V_334 ) ;
}
F_21 ( V_38 L_29
L_30
L_31 ,
V_2 -> V_148 -> V_263 ) ;
}
V_82 -> V_88 = V_335 ;
F_140 ( & V_82 -> V_290 ) ;
V_82 -> V_290 . V_291 = V_2 -> V_186 + V_292 ;
V_82 -> V_290 . V_293 = V_294 ;
V_82 -> V_290 . V_230 = ( unsigned long ) V_82 ;
F_128 ( & V_82 -> V_290 ) ;
F_46 ( V_2 , V_82 ) ;
if ( F_141 ( V_2 , V_82 ) )
V_82 -> V_88 = V_336 ;
F_129 ( V_82 -> V_96 ,
( V_82 -> V_88 != V_335 ) ) ;
if ( F_130 ( V_295 ) )
F_131 ( V_295 ) ;
F_132 ( & V_82 -> V_290 ) ;
F_50 ( V_2 , V_82 ) ;
if ( V_82 -> V_88 != V_336 )
F_21 ( V_38 L_32 ) ;
return 0 ;
}
static struct V_81 * F_142 ( struct V_126 * V_127 ,
struct V_321 * V_322 ,
int V_337 )
{
T_1 V_63 = V_338 ;
struct V_323 * V_324 = (struct V_323 * ) V_322 ;
struct V_339 * V_340 ;
struct V_83 * V_84 ;
struct V_1 * V_2 ;
struct V_136 * V_137 ;
struct V_341 V_342 ;
struct V_81 * V_82 ;
int V_109 = 0 ;
if ( V_127 ) {
V_2 = F_64 ( V_127 ) ;
} else
V_2 = F_135 ( V_322 ) ;
if ( ! V_2 ) {
V_109 = - V_259 ;
goto V_343;
}
F_119 ( & V_2 -> V_181 ) ;
if ( F_1 ( V_2 ) || ! V_2 -> V_64 . V_71 ) {
V_109 = - V_8 ;
goto V_344;
}
V_137 = V_2 -> V_137 ;
V_82 = F_28 ( V_2 ) ;
if ( ! V_82 ) {
V_109 = - V_80 ;
goto V_344;
}
V_84 = V_82 -> V_22 ;
V_84 -> V_232 = 0 ;
V_63 = F_22 ( V_2 ) ;
if ( V_63 == - 1 ) {
F_21 ( V_38 L_33
L_34 , V_2 -> V_148 -> V_263 ) ;
V_109 = - V_80 ;
F_32 ( V_82 ) ;
goto V_344;
}
V_84 -> V_91 = V_2 -> V_92 ;
V_109 = F_143 ( V_2 , V_84 ) ;
if ( V_109 != 0 ) {
F_21 ( V_38 L_35
L_36 , V_2 -> V_148 -> V_263 ) ;
V_109 = - V_80 ;
goto V_345;
}
V_84 -> V_90 = ( T_3 ) V_63 ;
V_84 -> V_88 = V_346 ;
F_52 ( V_2 , V_84 ) ;
F_140 ( & V_84 -> V_290 ) ;
V_84 -> V_290 . V_291 = 2 * V_184 + V_292 ;
V_84 -> V_290 . V_293 = V_294 ;
V_84 -> V_290 . V_230 = ( unsigned long ) V_84 ;
F_128 ( & V_84 -> V_290 ) ;
if ( F_144 ( V_2 , V_84 ) ) {
if ( V_84 -> V_88 == V_347 ) {
F_21 ( V_38 L_37 ,
V_2 -> V_148 -> V_263 , V_84 -> V_90 ) ;
V_109 = - V_67 ;
} else
V_109 = - V_348 ;
F_21 ( V_38 L_38
L_36 , V_2 -> V_148 -> V_263 ) ;
F_53 ( V_2 , V_84 ) ;
goto V_349;
}
F_129 ( V_84 -> V_96 ,
V_84 -> V_88 != V_346 ) ;
if ( F_130 ( V_295 ) )
F_131 ( V_295 ) ;
F_132 ( & V_84 -> V_290 ) ;
F_53 ( V_2 , V_84 ) ;
if ( V_84 -> V_88 != V_350 ) {
if ( V_84 -> V_88 == V_347 ) {
F_21 ( V_38 L_37 ,
V_2 -> V_148 -> V_263 , V_84 -> V_90 ) ;
V_109 = - V_67 ;
} else
V_109 = - V_348 ;
goto V_349;
}
V_109 = V_137 -> V_351 ( V_137 , V_326 , V_84 -> V_267 ,
V_63 , & V_84 -> V_274 , V_84 ) ;
if ( V_109 ) {
V_109 = - V_259 ;
goto V_352;
}
V_84 -> V_274 -> V_353 = 256 * 1024 ;
V_84 -> V_274 -> V_354 = 256 * 1024 ;
F_145 ( V_355 , & V_84 -> V_274 -> V_356 ) ;
memset ( & V_342 , 0 , sizeof( V_342 ) ) ;
if ( V_322 -> V_357 == V_358 ) {
V_324 = (struct V_323 * ) V_322 ;
V_342 . V_359 . V_360 = * V_324 ;
V_342 . V_361 . V_360 . V_362 = V_324 -> V_362 ;
} else if ( V_322 -> V_357 == V_363 ) {
V_340 = (struct V_339 * ) V_322 ;
V_342 . V_359 . V_364 = * V_340 ;
V_342 . V_361 . V_364 . V_365 = V_340 -> V_365 ;
}
V_84 -> V_366 = V_292 ;
V_84 -> V_88 = V_367 ;
if ( ! F_2 ( V_329 , & V_2 -> V_330 ) ) {
V_109 = - V_259 ;
goto V_349;
} else
V_109 = V_137 -> V_368 ( V_84 -> V_274 , & V_342 ) ;
if ( V_109 )
goto V_352;
F_59 ( V_2 , V_84 ) ;
if ( F_146 ( V_84 ) )
goto V_369;
F_120 ( & V_2 -> V_181 ) ;
return V_82 ;
V_369:
F_60 ( V_2 , V_84 ) ;
V_352:
if ( F_138 ( V_2 , V_84 ) ) {
F_120 ( & V_2 -> V_181 ) ;
return F_147 ( V_109 ) ;
}
V_349:
F_148 ( V_2 , V_84 ) ;
V_345:
F_32 ( V_82 ) ;
V_344:
F_120 ( & V_2 -> V_181 ) ;
V_343:
return F_147 ( V_109 ) ;
}
static int F_149 ( struct V_81 * V_82 , int V_370 )
{
struct V_83 * V_84 ;
int V_109 = 0 ;
V_84 = V_82 -> V_22 ;
if ( ( V_84 -> V_88 == V_89 ) ||
( V_84 -> V_88 == V_371 ) ||
( V_84 -> V_88 == V_372 ) )
return - 1 ;
if ( V_84 -> V_88 == V_373 )
return 1 ;
V_109 = F_150 ( V_84 -> V_96 ,
( ( V_84 -> V_88 ==
V_372 ) ||
( V_84 -> V_88 ==
V_371 ) ||
( V_84 -> V_88 ==
V_373 ) ) ,
F_97 ( V_370 ) ) ;
if ( V_84 -> V_88 == V_372 )
V_109 = - 1 ;
if ( V_109 > 0 )
return 1 ;
else if ( ! V_109 )
return 0 ;
else
return V_109 ;
}
static int F_151 ( struct V_83 * V_84 )
{
int V_374 ;
int V_375 = 0 ;
if ( F_2 ( V_134 , & V_84 -> V_2 -> V_129 ) )
V_375 = 1 ;
switch ( V_84 -> V_88 ) {
case V_376 :
case V_372 :
case V_332 :
V_374 = 0 ;
break;
case V_367 :
case V_371 :
case V_373 :
case V_289 :
case V_377 :
case V_261 :
case V_378 :
case V_379 :
case V_380 :
V_374 = 1 ;
break;
case V_262 :
if ( V_375 )
V_374 = 0 ;
else
V_374 = 1 ;
break;
default:
V_374 = 0 ;
}
return V_374 ;
}
int F_152 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = V_84 -> V_2 ;
struct V_136 * V_137 ;
struct V_98 * V_34 = NULL ;
struct V_224 * V_33 = NULL ;
int V_374 = 0 ;
int V_381 = 0 ;
int V_382 = 0 ;
if ( ! V_2 )
return 0 ;
V_137 = V_2 -> V_137 ;
if ( ! V_137 )
return 0 ;
if ( V_84 -> V_88 == V_89 ||
V_84 -> V_88 == V_332 )
return 0 ;
if ( ! F_151 ( V_84 ) )
goto V_383;
if ( V_84 -> V_33 ) {
V_33 = V_84 -> V_33 -> V_66 -> V_22 ;
V_34 = V_33 -> V_34 ;
}
F_140 ( & V_84 -> V_290 ) ;
V_84 -> V_290 . V_291 = V_2 -> V_185 + V_292 ;
V_84 -> V_290 . V_293 = V_294 ;
V_84 -> V_290 . V_230 = ( unsigned long ) V_84 ;
F_128 ( & V_84 -> V_290 ) ;
if ( ! F_2 ( V_329 , & V_2 -> V_330 ) )
goto V_113;
if ( V_34 ) {
F_98 ( & V_34 -> V_180 ) ;
if ( V_84 -> V_88 != V_261 ) {
if ( V_34 -> V_88 == V_384 ) {
if ( V_84 -> V_88 == V_378 ) {
F_21 ( V_38 L_39
L_40
L_41 ,
V_84 -> V_2 -> V_148 -> V_263 ) ;
} else if ( V_84 -> V_88 ==
V_379 )
V_381 = 1 ;
}
} else
V_381 = 1 ;
F_95 ( & V_34 -> V_180 ) ;
}
V_84 -> V_88 = V_385 ;
if ( V_381 )
V_382 = V_137 -> V_386 ( V_84 -> V_274 ) ;
else
V_382 = V_137 -> V_387 ( V_84 -> V_274 ) ;
if ( V_382 )
F_21 ( V_38 L_42 ,
V_84 -> V_2 -> V_148 -> V_263 , V_381 , V_382 ) ;
else
F_129 ( V_84 -> V_96 ,
V_84 -> V_88 != V_385 ) ;
if ( F_130 ( V_295 ) )
F_131 ( V_295 ) ;
F_132 ( & V_84 -> V_290 ) ;
V_383:
F_60 ( V_2 , V_84 ) ;
if ( F_138 ( V_2 , V_84 ) )
return - V_259 ;
V_113:
V_84 -> V_88 = V_89 ;
return V_374 ;
}
static void F_153 ( struct V_81 * V_82 )
{
struct V_83 * V_84 ;
struct V_62 * V_62 = NULL ;
struct V_224 * V_33 = NULL ;
struct V_1 * V_2 ;
V_84 = V_82 -> V_22 ;
while ( ( V_84 -> V_88 == V_367 ) &&
! F_154 ( V_292 , V_84 -> V_366 + ( 12 * V_184 ) ) )
F_155 ( 250 ) ;
if ( V_84 -> V_33 ) {
V_62 = V_84 -> V_33 ;
V_33 = V_62 -> V_66 -> V_22 ;
F_156 ( V_33 ) ;
}
V_2 = V_84 -> V_2 ;
F_119 ( & V_2 -> V_181 ) ;
if ( V_84 -> V_88 == V_332 )
goto V_113;
if ( V_84 -> V_88 == V_89 )
goto V_388;
if ( ! F_2 ( V_4 , & V_2 -> V_5 ) ||
( V_84 -> V_91 != V_2 -> V_92 ) ) {
F_60 ( V_2 , V_84 ) ;
goto V_388;
}
if ( F_152 ( V_84 ) ) {
F_120 ( & V_2 -> V_181 ) ;
return;
}
V_388:
F_148 ( V_2 , V_84 ) ;
if ( V_62 )
V_62 -> V_82 = NULL ;
F_32 ( V_82 ) ;
V_113:
F_120 ( & V_2 -> V_181 ) ;
F_157 ( & V_2 -> V_182 ) ;
}
static int F_158 ( struct V_126 * V_127 , struct V_389 * V_390 )
{
struct V_1 * V_2 = F_64 ( V_127 ) ;
char * V_207 = ( char * ) V_390 ;
T_3 V_271 = sizeof( * V_390 ) ;
V_2 -> V_137 -> V_391 ( V_2 -> V_137 , V_392 , V_207 ,
V_271 ) ;
return 0 ;
}

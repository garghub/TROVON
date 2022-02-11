static void F_1 ( struct V_1 * V_2 )
{
}
static void F_2 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_2 = V_4 -> V_2 ;
V_2 -> V_7 = V_6 ? V_6 -> V_8 . V_7 : NULL ;
V_2 -> V_9 = F_1 ;
}
int F_3 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
return F_4 ( V_2 ) -> V_10 -> V_11 ( V_2 ) ;
}
void F_5 ( struct V_3 * V_4 , T_1 V_12 ,
T_2 V_13 )
{
struct V_14 V_15 ;
T_3 V_16 ;
V_15 . V_17 = V_12 ;
V_16 = sizeof( V_15 ) + V_13 ;
V_15 . V_18 = F_6 ( V_16 ) ;
V_4 -> V_19 . V_20 = F_7 ( V_4 , sizeof( V_15 ) , & V_15 ) ;
}
static int F_8 ( struct V_3 * V_4 , T_1 V_12 ,
T_2 V_13 )
{
struct V_14 V_15 ;
T_3 V_16 ;
V_15 . V_17 = V_12 ;
V_16 = sizeof( V_15 ) + V_13 ;
V_15 . V_18 = F_6 ( V_16 ) ;
if ( F_9 ( V_4 -> V_2 ) < V_16 )
return - V_21 ;
V_4 -> V_19 . V_20 = F_10 ( V_4 , sizeof( V_15 ) , & V_15 ) ;
return 0 ;
}
struct V_3 * F_11 ( const struct V_5 * V_6 ,
const struct V_22 * V_23 ,
T_4 V_24 , int V_25 )
{
struct V_26 * V_26 = F_12 ( V_6 -> V_8 . V_7 ) ;
struct V_27 V_28 ;
struct V_29 V_30 ;
struct V_31 * V_32 = NULL ;
struct V_31 * V_33 = NULL ;
struct V_34 V_35 ;
struct V_36 * V_37 = V_6 -> V_37 ;
struct V_3 * V_38 = NULL ;
int V_39 , V_40 = 0 ;
struct V_41 V_42 ;
union V_43 V_44 ;
struct V_45 * V_46 ;
T_5 V_47 [ 4 ] ;
T_2 V_48 ;
T_1 V_49 [ 2 ] ;
int V_50 = 0 ;
V_44 = F_13 ( V_23 , & V_40 , V_24 ) ;
V_42 . V_51 = F_14 ( V_6 -> V_52 . V_53 ) ;
V_42 . V_54 = F_14 ( V_6 -> V_55 ) ;
V_42 . V_56 = F_6 ( V_6 -> V_52 . V_57 ) ;
V_42 . V_58 = F_6 ( V_6 -> V_52 . V_59 ) ;
V_42 . V_60 = F_14 ( V_6 -> V_52 . V_60 ) ;
V_46 = F_15 ( V_6 -> V_8 . V_7 ) ;
V_39 = V_46 -> V_61 -> V_62 ( V_46 , V_49 ) ;
V_48 = sizeof( V_42 ) + V_40 ;
V_48 += F_16 ( F_17 ( V_39 ) ) ;
V_48 += sizeof( V_63 ) ;
if ( V_6 -> V_64 )
V_48 += sizeof( V_65 ) ;
if ( V_26 -> V_66 . V_67 ) {
V_47 [ V_50 ] = V_68 ;
V_47 [ V_50 + 1 ] = V_69 ;
V_50 += 2 ;
}
if ( V_6 -> V_70 ) {
V_47 [ V_50 ] = V_71 ;
V_50 += 1 ;
}
if ( V_46 -> V_72 )
V_48 += sizeof( V_30 ) ;
V_48 += V_25 ;
if ( V_37 -> V_73 ) {
V_48 += sizeof( V_6 -> V_52 . V_74 ) ;
V_33 = (struct V_31 * ) V_6 -> V_52 . V_33 ;
if ( V_33 -> V_18 )
V_48 += F_16 ( F_18 ( V_33 -> V_18 ) ) ;
else
V_33 = NULL ;
V_32 = (struct V_31 * ) V_6 -> V_52 . V_32 ;
if ( V_32 -> V_18 )
V_48 += F_16 ( F_18 ( V_32 -> V_18 ) ) ;
else
V_32 = NULL ;
V_47 [ V_50 ] = V_75 ;
V_50 += 1 ;
}
if ( V_50 )
V_48 += F_16 ( sizeof( V_28 ) + V_50 ) ;
V_38 = F_19 ( V_6 , V_76 , 0 , V_48 , V_24 ) ;
if ( ! V_38 )
goto V_77;
V_38 -> V_19 . V_78 =
F_7 ( V_38 , sizeof( V_42 ) , & V_42 ) ;
V_38 -> V_79 . V_80 =
F_7 ( V_38 , V_40 , V_44 . V_80 ) ;
V_35 . V_79 . type = V_81 ;
V_35 . V_79 . V_18 = F_6 ( F_17 ( V_39 ) ) ;
F_7 ( V_38 , sizeof( V_35 ) , & V_35 ) ;
F_7 ( V_38 , V_39 * sizeof( T_3 ) , & V_49 ) ;
F_7 ( V_38 , sizeof( V_63 ) , & V_63 ) ;
if ( V_50 ) {
V_28 . V_79 . type = V_82 ;
V_28 . V_79 . V_18 = F_6 ( sizeof( V_28 ) + V_50 ) ;
F_7 ( V_38 , sizeof( V_28 ) , & V_28 ) ;
F_20 ( V_38 , V_50 , V_47 ) ;
}
if ( V_6 -> V_64 )
F_7 ( V_38 , sizeof( V_65 ) , & V_65 ) ;
if ( V_46 -> V_72 ) {
V_30 . V_79 . type = V_83 ;
V_30 . V_79 . V_18 = F_6 ( sizeof( V_30 ) ) ;
V_30 . V_72 = F_14 ( V_46 -> V_72 ) ;
F_7 ( V_38 , sizeof( V_30 ) , & V_30 ) ;
}
if ( V_37 -> V_73 ) {
F_7 ( V_38 , sizeof( V_6 -> V_52 . V_74 ) ,
V_6 -> V_52 . V_74 ) ;
if ( V_33 )
F_7 ( V_38 , F_18 ( V_33 -> V_18 ) ,
V_33 ) ;
if ( V_32 )
F_7 ( V_38 , F_18 ( V_32 -> V_18 ) ,
V_32 ) ;
}
V_77:
F_21 ( V_44 . V_80 ) ;
return V_38 ;
}
struct V_3 * F_22 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
T_4 V_24 , int V_84 )
{
struct V_27 V_28 ;
struct V_29 V_30 ;
struct V_31 * V_32 = NULL ;
struct V_31 * V_74 = NULL ;
struct V_31 * V_33 = NULL ;
struct V_3 * V_38 = NULL ;
struct V_85 * V_86 ;
struct V_41 V_87 ;
union V_43 V_44 ;
struct V_45 * V_46 ;
T_5 V_47 [ 4 ] ;
T_2 V_48 ;
int V_50 = 0 ;
int V_88 ;
int V_40 ;
V_44 = F_13 ( & V_6 -> V_8 . V_89 , & V_40 , V_24 ) ;
V_87 . V_51 = F_14 ( V_6 -> V_52 . V_53 ) ;
V_87 . V_54 = F_14 ( V_6 -> V_55 ) ;
V_87 . V_56 = F_6 ( V_6 -> V_52 . V_57 ) ;
V_87 . V_58 = F_6 ( V_6 -> V_52 . V_59 ) ;
V_87 . V_60 = F_14 ( V_6 -> V_52 . V_60 ) ;
V_86 = F_23 ( V_6 -> V_37 , V_6 , V_4 , & V_88 ,
V_44 . V_80 , V_40 ) ;
if ( ! V_86 )
goto V_90;
V_46 = F_15 ( V_6 -> V_8 . V_7 ) ;
V_48 = sizeof( V_87 ) + V_40 + V_88 + V_84 ;
if ( V_6 -> V_91 . V_92 )
V_48 += sizeof( V_63 ) ;
if ( V_6 -> V_91 . V_93 )
V_48 += sizeof( V_65 ) ;
if ( V_6 -> V_91 . V_94 ) {
V_47 [ V_50 ] = V_68 ;
V_47 [ V_50 + 1 ] = V_69 ;
V_50 += 2 ;
}
if ( V_6 -> V_91 . V_95 ) {
V_47 [ V_50 ] = V_71 ;
V_50 += 1 ;
}
if ( V_46 -> V_72 )
V_48 += sizeof( V_30 ) ;
if ( V_6 -> V_91 . V_96 ) {
V_74 = (struct V_31 * ) V_6 -> V_52 . V_74 ;
V_48 += F_18 ( V_74 -> V_18 ) ;
V_33 = (struct V_31 * ) V_6 -> V_52 . V_33 ;
if ( V_33 -> V_18 )
V_48 += F_16 ( F_18 ( V_33 -> V_18 ) ) ;
else
V_33 = NULL ;
V_32 = (struct V_31 * ) V_6 -> V_52 . V_32 ;
if ( V_32 -> V_18 )
V_48 += F_16 ( F_18 ( V_32 -> V_18 ) ) ;
else
V_32 = NULL ;
V_47 [ V_50 ] = V_75 ;
V_50 += 1 ;
}
if ( V_50 )
V_48 += F_16 ( sizeof( V_28 ) + V_50 ) ;
V_38 = F_19 ( V_6 , V_97 , 0 , V_48 , V_24 ) ;
if ( ! V_38 )
goto V_98;
V_38 -> V_99 = V_4 -> V_99 ;
V_38 -> V_19 . V_78 =
F_7 ( V_38 , sizeof( V_87 ) , & V_87 ) ;
V_38 -> V_79 . V_80 = F_7 ( V_38 , V_40 , V_44 . V_80 ) ;
F_7 ( V_38 , V_88 , V_86 ) ;
if ( V_6 -> V_91 . V_92 )
F_7 ( V_38 , sizeof( V_63 ) , & V_63 ) ;
if ( V_50 ) {
V_28 . V_79 . type = V_82 ;
V_28 . V_79 . V_18 = F_6 ( sizeof( V_28 ) + V_50 ) ;
F_7 ( V_38 , sizeof( V_28 ) , & V_28 ) ;
F_20 ( V_38 , V_50 , V_47 ) ;
}
if ( V_6 -> V_91 . V_93 )
F_7 ( V_38 , sizeof( V_65 ) , & V_65 ) ;
if ( V_46 -> V_72 ) {
V_30 . V_79 . type = V_83 ;
V_30 . V_79 . V_18 = F_6 ( sizeof( V_30 ) ) ;
V_30 . V_72 = F_14 ( V_46 -> V_72 ) ;
F_7 ( V_38 , sizeof( V_30 ) , & V_30 ) ;
}
if ( V_6 -> V_91 . V_96 ) {
F_7 ( V_38 , F_18 ( V_74 -> V_18 ) ,
V_74 ) ;
if ( V_33 )
F_7 ( V_38 , F_18 ( V_33 -> V_18 ) ,
V_33 ) ;
if ( V_32 )
F_7 ( V_38 , F_18 ( V_32 -> V_18 ) ,
V_32 ) ;
}
V_38 -> V_6 = (struct V_5 * ) V_6 ;
V_98:
F_21 ( V_86 ) ;
V_90:
F_21 ( V_44 . V_80 ) ;
return V_38 ;
}
struct V_3 * F_24 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_38 ;
int V_88 ;
void * V_86 ;
V_86 = V_6 -> V_91 . V_86 ;
V_88 = V_6 -> V_91 . V_88 ;
V_38 = F_19 ( V_6 , V_100 , 0 ,
V_88 , V_101 ) ;
if ( ! V_38 )
goto V_77;
V_38 -> V_19 . V_102 =
F_7 ( V_38 , V_88 , V_86 ) ;
if ( V_4 )
V_38 -> V_99 = V_4 -> V_99 ;
V_77:
return V_38 ;
}
struct V_3 * F_25 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_38 ;
V_38 = F_19 ( V_6 , V_103 , 0 , 0 , V_101 ) ;
if ( V_38 && V_4 )
V_38 -> V_99 = V_4 -> V_99 ;
return V_38 ;
}
struct V_3 * F_26 ( const struct V_5 * V_6 ,
const T_6 V_104 ,
const struct V_3 * V_4 )
{
struct V_3 * V_38 ;
struct V_105 V_106 ;
V_106 . V_104 = F_14 ( V_104 ) ;
V_38 = F_19 ( V_6 , V_107 , 0 ,
sizeof( V_106 ) , V_101 ) ;
if ( ! V_38 )
goto V_77;
V_38 -> V_19 . V_108 =
F_7 ( V_38 , sizeof( V_106 ) , & V_106 ) ;
if ( V_4 )
V_38 -> V_99 = V_4 -> V_99 ;
V_77:
return V_38 ;
}
struct V_3 * F_27 ( const struct V_5 * V_6 ,
const T_6 V_104 )
{
struct V_3 * V_38 ;
struct V_109 V_110 ;
V_110 . V_104 = F_14 ( V_104 ) ;
V_38 = F_19 ( V_6 , V_111 , 0 ,
sizeof( V_110 ) , V_101 ) ;
if ( ! V_38 )
goto V_77;
V_38 -> V_19 . V_112 =
F_7 ( V_38 , sizeof( V_110 ) , & V_110 ) ;
V_77:
return V_38 ;
}
struct V_3 * F_28 ( struct V_5 * V_6 ,
const struct V_113 * V_114 ,
int V_115 , T_5 V_116 , T_3 V_117 ,
T_4 V_24 )
{
struct V_3 * V_38 ;
struct V_118 V_119 ;
int V_120 ;
V_119 . V_121 = 0 ;
V_119 . V_122 = F_6 ( V_114 -> V_123 ) ;
V_119 . V_124 = V_114 -> V_125 ;
if ( V_114 -> V_126 & V_127 ) {
V_116 |= V_128 ;
V_119 . V_117 = 0 ;
} else
V_119 . V_117 = F_6 ( V_117 ) ;
V_120 = sizeof( V_119 ) + V_115 ;
V_38 = F_29 ( V_6 , V_116 , V_120 , V_24 ) ;
if ( ! V_38 )
goto V_77;
V_38 -> V_19 . V_129 = F_7 ( V_38 , sizeof( V_119 ) , & V_119 ) ;
memcpy ( & V_38 -> V_114 , V_114 , sizeof( struct V_113 ) ) ;
V_77:
return V_38 ;
}
struct V_3 * F_30 ( const struct V_5 * V_6 )
{
struct V_130 * V_131 = (struct V_130 * ) & V_6 -> V_91 . V_132 ;
struct V_5 * V_133 = (struct V_5 * ) V_6 ;
struct V_134 V_135 [ V_136 ] ;
T_3 V_137 , V_138 ;
struct V_139 * V_140 ;
struct V_3 * V_38 ;
struct V_141 V_142 ;
T_6 V_143 ;
int V_16 ;
memset ( V_135 , 0 , sizeof( V_135 ) ) ;
V_143 = F_31 ( V_131 ) ;
F_32 ( L_1 , V_144 , V_143 ) ;
V_137 = F_33 ( V_131 , V_135 ) ;
V_138 = F_34 ( V_131 ) ;
V_142 . V_145 = F_14 ( V_143 ) ;
V_142 . V_54 = F_14 ( V_6 -> V_54 ) ;
V_142 . V_146 = F_6 ( V_137 ) ;
V_142 . V_138 = F_6 ( V_138 ) ;
V_16 = sizeof( V_142 )
+ sizeof( struct V_134 ) * V_137
+ sizeof( T_6 ) * V_138 ;
V_38 = F_19 ( V_6 , V_147 , 0 , V_16 , V_101 ) ;
if ( ! V_38 )
goto V_77;
V_38 -> V_99 = V_6 -> V_91 . V_148 ;
V_38 -> V_19 . V_149 =
F_7 ( V_38 , sizeof( V_142 ) , & V_142 ) ;
if ( V_137 )
F_7 ( V_38 , sizeof( T_6 ) * V_137 ,
V_135 ) ;
if ( V_138 ) {
V_133 -> V_150 . V_151 += V_138 ;
F_7 ( V_38 , sizeof( T_6 ) * V_138 ,
F_35 ( V_131 ) ) ;
}
if ( ++ V_133 -> V_91 . V_152 == 0 ) {
F_36 (trans, &asoc->peer.transport_addr_list,
transports)
V_140 -> V_152 = 0 ;
V_133 -> V_91 . V_152 = 1 ;
}
V_77:
return V_38 ;
}
struct V_3 * F_37 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_153 V_154 ;
struct V_3 * V_38 ;
T_6 V_143 ;
V_143 = F_31 ( & V_6 -> V_91 . V_132 ) ;
V_154 . V_145 = F_14 ( V_143 ) ;
V_38 = F_19 ( V_6 , V_155 , 0 ,
sizeof( V_154 ) , V_101 ) ;
if ( ! V_38 )
goto V_77;
V_38 -> V_19 . V_156 =
F_7 ( V_38 , sizeof( V_154 ) , & V_154 ) ;
if ( V_4 )
V_38 -> V_99 = V_4 -> V_99 ;
V_77:
return V_38 ;
}
struct V_3 * F_38 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_38 ;
V_38 = F_19 ( V_6 , V_157 , 0 , 0 ,
V_101 ) ;
if ( V_38 && V_4 )
V_38 -> V_99 = V_4 -> V_99 ;
return V_38 ;
}
struct V_3 * F_39 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_38 ;
T_5 V_116 = 0 ;
V_116 |= V_6 ? 0 : V_158 ;
V_38 = F_19 ( V_6 , V_159 , V_116 ,
0 , V_101 ) ;
if ( V_38 && V_4 )
V_38 -> V_99 = V_4 -> V_99 ;
return V_38 ;
}
struct V_3 * F_40 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
const T_2 V_160 )
{
struct V_3 * V_38 ;
T_5 V_116 = 0 ;
if ( ! V_6 ) {
if ( V_4 && V_4 -> V_161 &&
V_4 -> V_161 -> type == V_76 )
V_116 = 0 ;
else
V_116 = V_158 ;
}
V_38 = F_19 ( V_6 , V_162 , V_116 , V_160 ,
V_101 ) ;
if ( V_38 && V_4 )
V_38 -> V_99 = V_4 -> V_99 ;
return V_38 ;
}
struct V_3 * F_41 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
T_6 V_121 )
{
struct V_3 * V_38 ;
T_7 V_163 ;
V_38 = F_40 ( V_6 , V_4 ,
sizeof( struct V_14 ) + sizeof( V_121 ) ) ;
if ( ! V_38 )
goto V_164;
V_163 = F_14 ( V_121 ) ;
F_5 ( V_38 , V_165 , sizeof( V_163 ) ) ;
F_7 ( V_38 , sizeof( V_163 ) , ( const void * ) & V_163 ) ;
if ( V_4 )
V_38 -> V_99 = V_4 -> V_99 ;
V_164:
return V_38 ;
}
struct V_3 * F_42 ( const struct V_5 * V_6 ,
struct V_166 * V_167 ,
T_2 V_13 )
{
struct V_3 * V_38 ;
void * V_163 = NULL ;
int V_15 ;
V_38 = F_40 ( V_6 , NULL ,
sizeof( struct V_14 ) + V_13 ) ;
if ( ! V_38 )
goto V_168;
if ( V_13 ) {
V_163 = F_43 ( V_13 , V_169 ) ;
if ( ! V_163 )
goto V_170;
V_15 = F_44 ( V_163 , V_167 , V_13 ) ;
if ( V_15 < 0 )
goto V_171;
}
F_5 ( V_38 , V_172 , V_13 ) ;
F_7 ( V_38 , V_13 , V_163 ) ;
if ( V_13 )
F_21 ( V_163 ) ;
return V_38 ;
V_171:
F_21 ( V_163 ) ;
V_170:
F_45 ( V_38 ) ;
V_38 = NULL ;
V_168:
return V_38 ;
}
static void * F_20 ( struct V_3 * V_4 , int V_16 ,
const void * V_173 )
{
int V_174 = F_18 ( V_4 -> V_161 -> V_18 ) ;
void * V_175 ;
V_175 = F_46 ( V_4 -> V_2 , V_16 ) ;
if ( V_173 )
memcpy ( V_175 , V_173 , V_16 ) ;
else
memset ( V_175 , 0 , V_16 ) ;
V_4 -> V_161 -> V_18 = F_6 ( V_174 + V_16 ) ;
V_4 -> V_176 = F_47 ( V_4 -> V_2 ) ;
return V_175 ;
}
struct V_3 * F_48 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
const T_5 * V_163 ,
const T_2 V_13 )
{
struct V_3 * V_38 ;
struct V_31 V_177 ;
V_38 = F_40 ( V_6 , V_4 , sizeof( struct V_14 ) +
V_13 + sizeof( V_177 ) ) ;
if ( ! V_38 )
goto V_178;
F_5 ( V_38 , V_179 , V_13 +
sizeof( V_177 ) ) ;
V_177 . type = F_6 ( V_4 -> V_161 -> type ) ;
V_177 . V_18 = V_4 -> V_161 -> V_18 ;
F_7 ( V_38 , V_13 , V_163 ) ;
F_20 ( V_38 , sizeof( V_177 ) , & V_177 ) ;
V_178:
return V_38 ;
}
struct V_3 * F_49 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
struct V_31 * V_180 )
{
static const char error [] = L_2 ;
T_2 V_181 = sizeof( error ) + sizeof( struct V_14 ) +
sizeof( * V_180 ) ;
struct V_3 * V_38 ;
V_38 = F_40 ( V_6 , V_4 , V_181 ) ;
if ( ! V_38 )
goto V_77;
F_5 ( V_38 , V_179 ,
sizeof( error ) + sizeof( * V_180 ) ) ;
F_7 ( V_38 , sizeof( error ) , error ) ;
F_20 ( V_38 , sizeof( * V_180 ) , V_180 ) ;
V_77:
return V_38 ;
}
struct V_3 * F_50 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
static const char error [] = L_3 ;
T_2 V_181 = sizeof( error ) + sizeof( struct V_14 ) ;
struct V_3 * V_38 ;
V_38 = F_40 ( V_6 , V_4 , V_181 ) ;
if ( ! V_38 )
goto V_77;
F_5 ( V_38 , V_179 , sizeof( error ) ) ;
F_7 ( V_38 , sizeof( error ) , error ) ;
V_77:
return V_38 ;
}
struct V_3 * F_51 ( const struct V_5 * V_6 ,
const struct V_139 * V_99 )
{
struct V_182 V_183 ;
struct V_3 * V_38 ;
V_38 = F_19 ( V_6 , V_184 , 0 ,
sizeof( V_183 ) , V_101 ) ;
if ( ! V_38 )
goto V_77;
V_183 . V_79 . type = V_185 ;
V_183 . V_79 . V_18 = F_6 ( sizeof( V_183 ) ) ;
V_183 . V_186 = V_99 -> V_187 ;
V_183 . V_188 = V_189 ;
V_183 . V_190 = V_99 -> V_190 ;
V_38 -> V_99 = (struct V_139 * ) V_99 ;
V_38 -> V_19 . V_191 = F_7 ( V_38 , sizeof( V_183 ) ,
& V_183 ) ;
V_77:
return V_38 ;
}
struct V_3 * F_52 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
const void * V_163 ,
const T_2 V_13 )
{
struct V_3 * V_38 ;
V_38 = F_19 ( V_6 , V_192 , 0 , V_13 ,
V_101 ) ;
if ( ! V_38 )
goto V_77;
V_38 -> V_19 . V_191 = F_7 ( V_38 , V_13 , V_163 ) ;
if ( V_4 )
V_38 -> V_99 = V_4 -> V_99 ;
V_77:
return V_38 ;
}
static struct V_3 * F_53 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
T_2 V_193 )
{
struct V_3 * V_38 ;
V_38 = F_19 ( V_6 , V_194 , 0 ,
sizeof( struct V_14 ) + V_193 ,
V_101 ) ;
if ( ! V_38 )
goto V_77;
if ( V_4 )
V_38 -> V_99 = V_4 -> V_99 ;
V_77:
return V_38 ;
}
static inline struct V_3 * F_54 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
T_2 V_193 = V_6 ? V_6 -> V_195 : 0 ;
if ( ! V_193 )
V_193 = V_196 ;
return F_53 ( V_6 , V_4 , V_193 ) ;
}
struct V_3 * F_55 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
T_1 V_12 , const void * V_163 ,
T_2 V_13 , T_2 V_197 )
{
struct V_3 * V_38 ;
V_38 = F_53 ( V_6 , V_4 , V_13 + V_197 ) ;
if ( ! V_38 )
goto V_77;
F_5 ( V_38 , V_12 , V_13 + V_197 ) ;
F_7 ( V_38 , V_13 , V_163 ) ;
if ( V_197 )
F_20 ( V_38 , V_197 , NULL ) ;
V_77:
return V_38 ;
}
struct V_3 * F_56 ( const struct V_5 * V_6 )
{
struct V_198 V_199 ;
struct V_200 * V_201 ;
struct V_3 * V_38 ;
T_5 * V_202 ;
V_201 = F_57 ( V_6 ) ;
if ( F_58 ( ! V_201 ) )
return NULL ;
V_38 = F_19 ( V_6 , V_75 , 0 ,
V_201 -> V_203 + sizeof( V_199 ) ,
V_101 ) ;
if ( ! V_38 )
return NULL ;
V_199 . V_204 = F_6 ( V_201 -> V_204 ) ;
V_199 . V_205 = F_6 ( V_6 -> V_206 ) ;
V_38 -> V_19 . V_199 = F_7 ( V_38 , sizeof( V_199 ) ,
& V_199 ) ;
V_202 = F_59 ( V_38 -> V_2 , V_201 -> V_203 ) ;
V_38 -> V_161 -> V_18 =
F_6 ( F_18 ( V_38 -> V_161 -> V_18 ) + V_201 -> V_203 ) ;
V_38 -> V_176 = F_47 ( V_38 -> V_2 ) ;
return V_38 ;
}
struct V_3 * F_60 ( struct V_1 * V_2 ,
const struct V_5 * V_6 ,
struct V_207 * V_7 , T_4 V_24 )
{
struct V_3 * V_38 ;
V_38 = F_61 ( V_208 , V_24 ) ;
if ( ! V_38 )
goto V_77;
if ( ! V_7 )
F_32 ( L_4 , V_144 , V_2 ) ;
F_62 ( & V_38 -> V_209 ) ;
V_38 -> V_2 = V_2 ;
V_38 -> V_6 = (struct V_5 * ) V_6 ;
V_38 -> V_210 = 1 ;
V_38 -> V_211 = V_212 ;
F_62 ( & V_38 -> V_213 ) ;
F_62 ( & V_38 -> V_214 ) ;
F_63 ( V_4 ) ;
F_64 ( & V_38 -> V_215 , 1 ) ;
V_77:
return V_38 ;
}
void F_65 ( struct V_3 * V_4 , union V_216 * V_217 ,
union V_216 * V_218 )
{
memcpy ( & V_4 -> V_219 , V_217 , sizeof( union V_216 ) ) ;
memcpy ( & V_4 -> V_218 , V_218 , sizeof( union V_216 ) ) ;
}
const union V_216 * F_66 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_99 ) {
return & V_4 -> V_99 -> V_187 ;
} else {
return & V_4 -> V_219 ;
}
}
static struct V_3 * F_67 ( const struct V_5 * V_6 ,
T_5 type , T_5 V_116 , int V_13 ,
T_4 V_24 )
{
struct V_220 * V_161 ;
struct V_3 * V_38 ;
struct V_1 * V_2 ;
struct V_207 * V_7 ;
V_2 = F_68 ( F_16 ( sizeof( * V_161 ) + V_13 ) , V_24 ) ;
if ( ! V_2 )
goto V_77;
V_161 = (struct V_220 * ) F_46 ( V_2 , sizeof( * V_161 ) ) ;
V_161 -> type = type ;
V_161 -> V_116 = V_116 ;
V_161 -> V_18 = F_6 ( sizeof( * V_161 ) ) ;
V_7 = V_6 ? V_6 -> V_8 . V_7 : NULL ;
V_38 = F_60 ( V_2 , V_6 , V_7 , V_24 ) ;
if ( ! V_38 ) {
F_69 ( V_2 ) ;
goto V_77;
}
V_38 -> V_161 = V_161 ;
V_38 -> V_176 = ( ( T_5 * ) V_161 ) + sizeof( * V_161 ) ;
if ( F_70 ( type , V_6 ) )
V_38 -> V_221 = 1 ;
return V_38 ;
V_77:
return NULL ;
}
static struct V_3 * F_29 ( const struct V_5 * V_6 ,
T_5 V_116 , int V_13 , T_4 V_24 )
{
return F_67 ( V_6 , V_222 , V_116 , V_13 , V_24 ) ;
}
static struct V_3 * F_19 ( const struct V_5 * V_6 ,
T_5 type , T_5 V_116 , int V_13 ,
T_4 V_24 )
{
struct V_3 * V_4 ;
V_4 = F_67 ( V_6 , type , V_116 , V_13 , V_24 ) ;
if ( V_4 )
F_2 ( V_4 ) ;
return V_4 ;
}
static void F_71 ( struct V_3 * V_4 )
{
F_72 ( ! F_73 ( & V_4 -> V_209 ) ) ;
F_74 ( & V_4 -> V_213 ) ;
F_75 ( V_4 -> V_2 ) ;
F_75 ( V_4 -> V_223 ) ;
F_76 ( V_4 ) ;
F_77 ( V_208 , V_4 ) ;
}
void F_45 ( struct V_3 * V_4 )
{
if ( V_4 -> V_167 )
F_78 ( V_4 -> V_167 ) ;
F_79 ( V_4 ) ;
}
void F_80 ( struct V_3 * V_224 )
{
F_81 ( & V_224 -> V_215 ) ;
}
void F_79 ( struct V_3 * V_224 )
{
if ( F_82 ( & V_224 -> V_215 ) )
F_71 ( V_224 ) ;
}
void * F_7 ( struct V_3 * V_4 , int V_16 , const void * V_173 )
{
int V_174 = F_18 ( V_4 -> V_161 -> V_18 ) ;
int V_225 = F_16 ( V_174 ) - V_174 ;
void * V_175 ;
F_59 ( V_4 -> V_2 , V_225 ) ;
V_175 = F_83 ( V_4 -> V_2 , V_173 , V_16 ) ;
V_4 -> V_161 -> V_18 = F_6 ( V_174 + V_225 + V_16 ) ;
V_4 -> V_176 = F_47 ( V_4 -> V_2 ) ;
return V_175 ;
}
static void * F_10 ( struct V_3 * V_4 ,
int V_16 , const void * V_173 )
{
if ( F_9 ( V_4 -> V_2 ) >= V_16 )
return F_7 ( V_4 , V_16 , V_173 ) ;
else
return NULL ;
}
int F_84 ( struct V_3 * V_4 , int V_16 ,
struct V_226 * V_227 )
{
void * V_175 ;
V_175 = F_46 ( V_4 -> V_2 , V_16 ) ;
if ( ! F_85 ( V_175 , V_16 , V_227 ) )
return - V_228 ;
V_4 -> V_161 -> V_18 =
F_6 ( F_18 ( V_4 -> V_161 -> V_18 ) + V_16 ) ;
V_4 -> V_176 = F_47 ( V_4 -> V_2 ) ;
return 0 ;
}
void F_86 ( struct V_3 * V_4 )
{
struct V_229 * V_122 ;
struct V_3 * V_230 ;
struct V_231 * V_167 ;
T_3 V_117 , V_232 ;
if ( V_4 -> V_233 )
return;
V_232 = F_18 ( V_4 -> V_19 . V_129 -> V_122 ) ;
V_122 = & V_4 -> V_6 -> V_122 ;
V_167 = V_4 -> V_167 ;
F_36 (lchunk, &msg->chunks, frag_list) {
if ( V_230 -> V_161 -> V_116 & V_128 ) {
V_117 = 0 ;
} else {
if ( V_230 -> V_161 -> V_116 & V_234 )
V_117 = F_87 ( V_122 , V_235 , V_232 ) ;
else
V_117 = F_88 ( V_122 , V_235 , V_232 ) ;
}
V_230 -> V_19 . V_129 -> V_117 = F_6 ( V_117 ) ;
V_230 -> V_233 = 1 ;
}
}
void F_89 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_236 ) {
V_4 -> V_19 . V_129 -> V_121 =
F_14 ( F_90 ( V_4 -> V_6 ) ) ;
V_4 -> V_236 = 1 ;
}
}
struct V_5 * F_91 ( const struct V_36 * V_37 ,
struct V_3 * V_4 ,
T_4 V_24 )
{
struct V_5 * V_6 ;
enum V_237 V_238 ;
struct V_1 * V_2 ;
V_238 = V_237 ( F_66 ( V_4 ) ) ;
V_6 = F_92 ( V_37 , V_37 -> V_8 . V_7 , V_238 , V_24 ) ;
if ( ! V_6 )
goto V_77;
V_6 -> V_239 = 1 ;
V_2 = V_4 -> V_2 ;
F_4 ( V_2 ) -> V_10 -> V_240 ( & V_6 -> V_52 . V_241 , V_2 , 1 ) ;
V_77:
return V_6 ;
}
static struct V_85 * F_23 (
const struct V_36 * V_37 ,
const struct V_5 * V_6 ,
const struct V_3 * V_242 ,
int * V_88 , const T_5 * V_243 ,
int V_40 )
{
struct V_244 * V_86 ;
struct V_85 * V_38 ;
int V_245 , V_246 ;
V_245 = sizeof( struct V_31 ) +
( sizeof( struct V_244 ) -
sizeof( struct V_247 ) ) ;
V_246 = sizeof( struct V_247 )
+ F_18 ( V_242 -> V_161 -> V_18 ) + V_40 ;
if ( V_246 % V_248 )
V_246 += V_248
- ( V_246 % V_248 ) ;
* V_88 = V_245 + V_246 ;
V_38 = F_93 ( * V_88 , V_101 ) ;
if ( ! V_38 )
goto V_77;
V_86 = (struct V_244 * ) V_38 -> V_249 ;
V_38 -> V_250 . type = V_251 ;
V_38 -> V_250 . V_18 = F_6 ( * V_88 ) ;
V_86 -> V_52 = V_6 -> V_52 ;
V_86 -> V_52 . V_252 = V_40 ;
V_86 -> V_52 . V_93 = V_6 -> V_91 . V_93 ;
V_86 -> V_52 . V_72 = V_6 -> V_91 . V_72 ;
V_86 -> V_52 . V_253 = F_94 ( V_6 -> V_254 ,
F_95 () ) ;
memcpy ( & V_86 -> V_52 . V_255 [ 0 ] , V_242 -> V_161 ,
F_18 ( V_242 -> V_161 -> V_18 ) ) ;
memcpy ( ( T_5 * ) & V_86 -> V_52 . V_255 [ 0 ] +
F_18 ( V_242 -> V_161 -> V_18 ) , V_243 , V_40 ) ;
if ( F_15 ( V_37 -> V_8 . V_7 ) -> V_202 ) {
F_96 ( V_256 , F_15 ( V_37 -> V_8 . V_7 ) -> V_202 ) ;
int V_15 ;
V_256 -> V_257 = F_15 ( V_37 -> V_8 . V_7 ) -> V_202 ;
V_256 -> V_116 = 0 ;
V_15 = F_97 ( V_256 -> V_257 , V_37 -> V_258 ,
sizeof( V_37 -> V_258 ) ) ? :
F_98 ( V_256 , ( V_259 * ) & V_86 -> V_52 , V_246 ,
V_86 -> V_260 ) ;
F_99 ( V_256 ) ;
if ( V_15 )
goto V_261;
}
return V_38 ;
V_261:
F_21 ( V_38 ) ;
V_77:
* V_88 = 0 ;
return NULL ;
}
struct V_5 * F_100 (
const struct V_36 * V_37 ,
const struct V_5 * V_6 ,
struct V_3 * V_4 , T_4 V_24 ,
int * error , struct V_3 * * V_262 )
{
struct V_5 * V_38 = NULL ;
int V_245 , V_246 , V_263 ;
struct V_244 * V_86 ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_247 * V_264 ;
T_5 * V_265 = V_37 -> V_265 ;
enum V_237 V_238 ;
unsigned int V_16 ;
T_8 V_266 ;
V_245 = sizeof( struct V_220 ) +
( sizeof( struct V_244 ) -
sizeof( struct V_247 ) ) ;
V_246 = F_18 ( V_4 -> V_161 -> V_18 ) - V_245 ;
V_263 = V_245 + sizeof( struct V_247 ) ;
V_16 = F_18 ( V_4 -> V_161 -> V_18 ) ;
if ( V_16 < V_263 + sizeof( struct V_220 ) )
goto V_267;
if ( V_246 % V_248 )
goto V_267;
V_86 = V_4 -> V_19 . V_102 ;
V_264 = & V_86 -> V_52 ;
if ( ! F_15 ( V_37 -> V_8 . V_7 ) -> V_202 )
goto V_268;
{
F_96 ( V_256 , F_15 ( V_37 -> V_8 . V_7 ) -> V_202 ) ;
int V_15 ;
V_256 -> V_257 = F_15 ( V_37 -> V_8 . V_7 ) -> V_202 ;
V_256 -> V_116 = 0 ;
V_15 = F_97 ( V_256 -> V_257 , V_37 -> V_258 ,
sizeof( V_37 -> V_258 ) ) ? :
F_98 ( V_256 , ( V_259 * ) V_264 , V_246 ,
V_265 ) ;
F_99 ( V_256 ) ;
if ( V_15 ) {
* error = - V_269 ;
goto V_270;
}
}
if ( memcmp ( V_265 , V_86 -> V_260 , V_271 ) ) {
* error = - V_272 ;
goto V_270;
}
V_268:
if ( F_101 ( V_4 -> V_273 -> V_274 ) != V_264 -> V_53 ) {
* error = - V_275 ;
goto V_270;
}
if ( V_4 -> V_273 -> V_219 != V_264 -> V_241 . V_276 . V_277 ||
F_18 ( V_4 -> V_273 -> V_218 ) != V_264 -> V_278 ) {
* error = - V_279 ;
goto V_270;
}
if ( F_102 ( V_37 -> V_8 . V_7 , V_280 ) )
V_266 = F_103 ( V_2 ) ;
else
V_266 = F_95 () ;
if ( ! V_6 && F_104 ( V_264 -> V_253 , V_266 ) ) {
V_16 = F_18 ( V_4 -> V_161 -> V_18 ) ;
* V_262 = F_53 ( V_6 , V_4 , V_16 ) ;
if ( * V_262 ) {
T_9 V_281 = F_105 ( F_106 ( V_266 , V_264 -> V_253 ) ) ;
T_7 V_282 = F_14 ( V_281 ) ;
F_5 ( * V_262 , V_283 ,
sizeof( V_282 ) ) ;
F_7 ( * V_262 , sizeof( V_282 ) , & V_282 ) ;
* error = - V_284 ;
} else
* error = - V_269 ;
goto V_270;
}
V_238 = V_237 ( F_66 ( V_4 ) ) ;
V_38 = F_92 ( V_37 , V_37 -> V_8 . V_7 , V_238 , V_24 ) ;
if ( ! V_38 ) {
* error = - V_269 ;
goto V_270;
}
V_38 -> V_91 . V_285 = F_18 ( V_4 -> V_273 -> V_219 ) ;
memcpy ( & V_38 -> V_52 , V_264 , sizeof( * V_264 ) ) ;
if ( F_107 ( V_38 , V_264 ,
V_101 ) < 0 ) {
* error = - V_269 ;
goto V_270;
}
if ( F_73 ( & V_38 -> V_8 . V_89 . V_286 ) ) {
F_108 ( & V_38 -> V_8 . V_89 , & V_4 -> V_218 ,
sizeof( V_4 -> V_218 ) , V_287 ,
V_101 ) ;
}
V_38 -> V_288 = V_38 -> V_52 . V_60 ;
V_38 -> V_289 = V_38 -> V_288 - 1 ;
V_38 -> V_290 = V_38 -> V_52 . V_60 ;
V_38 -> V_291 = V_38 -> V_52 . V_60 ;
V_38 -> V_292 = V_38 -> V_289 ;
V_38 -> V_91 . V_93 = V_38 -> V_52 . V_93 ;
V_38 -> V_91 . V_72 = V_38 -> V_52 . V_72 ;
return V_38 ;
V_270:
if ( V_38 )
F_109 ( V_38 ) ;
return NULL ;
V_267:
* error = - V_293 ;
goto V_270;
}
static int F_110 ( const struct V_5 * V_6 ,
enum V_294 V_295 ,
struct V_3 * V_4 ,
struct V_3 * * V_262 )
{
struct V_296 V_297 ;
T_3 V_16 ;
V_16 = F_16 ( sizeof( V_297 ) ) ;
if ( ! * V_262 )
* V_262 = F_53 ( V_6 , V_4 , V_16 ) ;
if ( * V_262 ) {
V_297 . V_298 = F_14 ( 1 ) ;
V_297 . type = V_295 ;
F_5 ( * V_262 , V_299 ,
sizeof( V_297 ) ) ;
F_7 ( * V_262 , sizeof( V_297 ) , & V_297 ) ;
}
return 0 ;
}
static int F_111 ( const struct V_5 * V_6 ,
struct V_3 * V_4 ,
struct V_3 * * V_262 )
{
if ( ! * V_262 )
* V_262 = F_53 ( V_6 , V_4 , 0 ) ;
if ( * V_262 )
F_5 ( * V_262 , V_300 , 0 ) ;
return 0 ;
}
static int F_112 ( const struct V_5 * V_6 ,
struct V_31 * V_180 ,
const struct V_3 * V_4 ,
struct V_3 * * V_262 )
{
if ( * V_262 )
F_45 ( * V_262 ) ;
* V_262 = F_49 ( V_6 , V_4 , V_180 ) ;
return 0 ;
}
static int F_113 ( const struct V_5 * V_6 ,
union V_43 V_180 ,
struct V_3 * V_4 ,
struct V_3 * * V_262 )
{
T_3 V_16 = F_18 ( V_180 . V_250 -> V_18 ) ;
if ( * V_262 )
F_45 ( * V_262 ) ;
* V_262 = F_53 ( V_6 , V_4 , V_16 ) ;
if ( * V_262 ) {
F_5 ( * V_262 , V_301 , V_16 ) ;
F_7 ( * V_262 , V_16 , V_180 . V_80 ) ;
}
return 0 ;
}
static int F_114 ( struct V_26 * V_26 , union V_43 V_180 )
{
T_3 V_50 = F_18 ( V_180 . V_250 -> V_18 ) - sizeof( struct V_31 ) ;
int V_302 = 0 ;
int V_303 = 0 ;
int V_304 ;
for ( V_304 = 0 ; V_304 < V_50 ; V_304 ++ ) {
switch ( V_180 . V_305 -> V_306 [ V_304 ] ) {
case V_75 :
V_303 = 1 ;
break;
case V_68 :
case V_69 :
V_302 = 1 ;
break;
}
}
if ( V_26 -> V_66 . V_307 )
return 1 ;
if ( V_26 -> V_66 . V_67 && ! V_303 && V_302 )
return 0 ;
return 1 ;
}
static void F_115 ( struct V_5 * V_6 ,
union V_43 V_180 )
{
T_3 V_50 = F_18 ( V_180 . V_250 -> V_18 ) - sizeof( struct V_31 ) ;
struct V_26 * V_26 = F_12 ( V_6 -> V_8 . V_7 ) ;
int V_304 ;
for ( V_304 = 0 ; V_304 < V_50 ; V_304 ++ ) {
switch ( V_180 . V_305 -> V_306 [ V_304 ] ) {
case V_71 :
if ( V_6 -> V_70 &&
! V_6 -> V_91 . V_95 )
V_6 -> V_91 . V_95 = 1 ;
break;
case V_308 :
if ( V_6 -> V_64 && ! V_6 -> V_91 . V_93 )
V_6 -> V_91 . V_93 = 1 ;
break;
case V_75 :
if ( V_6 -> V_37 -> V_73 )
V_6 -> V_91 . V_96 = 1 ;
break;
case V_68 :
case V_69 :
if ( V_26 -> V_66 . V_67 )
V_6 -> V_91 . V_94 = 1 ;
break;
default:
break;
}
}
}
static enum V_309 F_116 (
const struct V_5 * V_6 ,
union V_43 V_180 ,
struct V_3 * V_4 ,
struct V_3 * * V_262 )
{
int V_38 = V_310 ;
switch ( V_180 . V_250 -> type & V_311 ) {
case V_312 :
V_38 = V_313 ;
break;
case V_314 :
break;
case V_315 :
V_38 = V_313 ;
case V_316 :
if ( NULL == * V_262 )
* V_262 = F_54 ( V_6 , V_4 ) ;
if ( * V_262 ) {
if ( ! F_8 ( * V_262 , V_317 ,
F_16 ( F_18 ( V_180 . V_250 -> V_18 ) ) ) )
F_10 ( * V_262 ,
F_16 ( F_18 ( V_180 . V_250 -> V_18 ) ) ,
V_180 . V_80 ) ;
} else {
V_38 = V_269 ;
}
break;
default:
break;
}
return V_38 ;
}
static enum V_309 F_117 ( struct V_26 * V_26 ,
const struct V_36 * V_37 ,
const struct V_5 * V_6 ,
union V_43 V_180 ,
enum V_318 V_319 ,
struct V_3 * V_4 ,
struct V_3 * * V_168 )
{
struct V_320 * V_321 ;
int V_38 = V_310 ;
T_3 V_322 , V_323 = 0 ;
int V_304 ;
switch ( V_180 . V_250 -> type ) {
case V_324 :
case V_325 :
case V_326 :
case V_81 :
case V_251 :
case V_185 :
case V_327 :
case V_328 :
case V_83 :
break;
case V_82 :
if ( ! F_114 ( V_26 , V_180 ) )
return V_329 ;
break;
case V_330 :
if ( V_26 -> V_66 . V_67 )
break;
goto V_331;
case V_332 :
F_113 ( V_6 , V_180 , V_4 , V_168 ) ;
V_38 = V_329 ;
break;
case V_333 :
if ( V_37 -> V_64 )
break;
goto V_331;
case V_334 :
if ( ! V_37 -> V_73 )
goto V_331;
if ( V_335 !=
F_18 ( V_180 . V_250 -> V_18 ) - sizeof( struct V_31 ) ) {
F_112 ( V_6 , V_180 . V_250 ,
V_4 , V_168 ) ;
V_38 = V_329 ;
}
break;
case V_336 :
if ( ! V_37 -> V_73 )
goto V_331;
if ( 260 < F_18 ( V_180 . V_250 -> V_18 ) ) {
F_112 ( V_6 , V_180 . V_250 ,
V_4 , V_168 ) ;
V_38 = V_329 ;
}
break;
case V_337 :
if ( ! V_37 -> V_73 )
goto V_331;
V_321 = (struct V_320 * ) V_180 . V_250 ;
V_322 = ( F_18 ( V_180 . V_250 -> V_18 ) -
sizeof( struct V_31 ) ) >> 1 ;
for ( V_304 = 0 ; V_304 < V_322 ; V_304 ++ ) {
V_323 = F_18 ( V_321 -> V_338 [ V_304 ] ) ;
if ( V_323 == V_339 )
break;
}
if ( V_323 != V_339 ) {
F_112 ( V_6 , V_180 . V_250 , V_4 ,
V_168 ) ;
V_38 = V_329 ;
}
break;
V_331:
default:
F_32 ( L_5 ,
V_144 , F_18 ( V_180 . V_250 -> type ) , V_319 ) ;
V_38 = F_116 ( V_6 , V_180 , V_4 , V_168 ) ;
break;
}
return V_38 ;
}
int F_118 ( struct V_26 * V_26 , const struct V_36 * V_37 ,
const struct V_5 * V_6 , enum V_318 V_319 ,
struct V_340 * V_255 ,
struct V_3 * V_4 , struct V_3 * * V_262 )
{
union V_43 V_180 ;
bool V_341 = false ;
int V_342 ;
if ( V_255 -> V_78 . V_56 == 0 ||
V_255 -> V_78 . V_58 == 0 ||
V_255 -> V_78 . V_51 == 0 ||
F_101 ( V_255 -> V_78 . V_54 ) < V_343 )
return F_111 ( V_6 , V_4 , V_262 ) ;
F_119 (param, peer_init, init_hdr.params) {
if ( V_180 . V_250 -> type == V_251 )
V_341 = true ;
}
if ( V_180 . V_80 != ( void * ) V_4 -> V_176 )
return F_112 ( V_6 , V_180 . V_250 , V_4 , V_262 ) ;
if ( ( V_97 == V_319 ) && ! V_341 )
return F_110 ( V_6 , V_251 ,
V_4 , V_262 ) ;
F_119 (param, peer_init, init_hdr.params) {
V_342 = F_117 ( V_26 , V_37 , V_6 , V_180 , V_319 ,
V_4 , V_262 ) ;
switch ( V_342 ) {
case V_329 :
case V_269 :
return 0 ;
case V_313 :
return 1 ;
case V_310 :
default:
break;
}
}
return 1 ;
}
int F_120 ( struct V_5 * V_6 , struct V_3 * V_4 ,
const union V_216 * V_241 ,
struct V_340 * V_255 , T_4 V_24 )
{
struct V_26 * V_26 = F_12 ( V_6 -> V_8 . V_7 ) ;
struct V_139 * V_99 ;
struct V_344 * V_345 , * V_239 ;
union V_43 V_180 ;
union V_216 V_346 ;
struct V_347 * V_10 ;
int V_348 = 0 ;
char * V_86 ;
if ( ! F_121 ( V_6 , V_241 , V_24 , V_349 ) )
goto V_350;
if ( F_122 ( F_66 ( V_4 ) , V_241 ) )
V_348 = 1 ;
F_119 (param, peer_init, init_hdr.params) {
if ( ! V_348 && ( V_180 . V_250 -> type == V_324 ||
V_180 . V_250 -> type == V_325 ) ) {
V_10 = F_123 ( F_124 ( V_180 . V_250 -> type ) ) ;
V_10 -> V_351 ( & V_346 , V_180 . V_346 ,
V_4 -> V_273 -> V_219 , 0 ) ;
if ( F_122 ( F_66 ( V_4 ) , & V_346 ) )
V_348 = 1 ;
}
if ( ! F_125 ( V_6 , V_180 , V_241 , V_24 ) )
goto V_352;
}
if ( ! V_348 )
goto V_352;
if ( V_6 -> V_91 . V_96 && ( ! V_6 -> V_91 . V_353 ||
! V_6 -> V_91 . V_354 ) )
V_6 -> V_91 . V_96 = 0 ;
if ( ! V_26 -> V_66 . V_307 &&
( V_6 -> V_91 . V_94 && ! V_6 -> V_91 . V_96 ) ) {
V_6 -> V_91 . V_355 |= ( V_356 |
V_357 |
V_330 ) ;
V_6 -> V_91 . V_94 = 0 ;
goto V_352;
}
F_126 (pos, temp, &asoc->peer.transport_addr_list) {
V_99 = F_127 ( V_345 , struct V_139 , V_358 ) ;
if ( V_99 -> V_359 == V_360 ) {
F_128 ( V_6 , V_99 ) ;
}
}
V_6 -> V_91 . V_304 . V_51 =
F_101 ( V_255 -> V_78 . V_51 ) ;
V_6 -> V_91 . V_304 . V_54 =
F_101 ( V_255 -> V_78 . V_54 ) ;
V_6 -> V_91 . V_304 . V_56 =
F_18 ( V_255 -> V_78 . V_56 ) ;
V_6 -> V_91 . V_304 . V_58 =
F_18 ( V_255 -> V_78 . V_58 ) ;
V_6 -> V_91 . V_304 . V_60 =
F_101 ( V_255 -> V_78 . V_60 ) ;
V_6 -> V_361 = V_6 -> V_91 . V_304 . V_60 ;
if ( V_6 -> V_52 . V_57 >
F_18 ( V_255 -> V_78 . V_58 ) ) {
V_6 -> V_52 . V_57 =
F_18 ( V_255 -> V_78 . V_58 ) ;
}
if ( V_6 -> V_52 . V_59 >
F_18 ( V_255 -> V_78 . V_56 ) ) {
V_6 -> V_52 . V_59 =
F_18 ( V_255 -> V_78 . V_56 ) ;
}
V_6 -> V_52 . V_362 = V_6 -> V_91 . V_304 . V_51 ;
V_6 -> V_91 . V_55 = V_6 -> V_91 . V_304 . V_54 ;
V_86 = V_6 -> V_91 . V_86 ;
if ( V_86 ) {
V_6 -> V_91 . V_86 = F_129 ( V_86 , V_6 -> V_91 . V_88 , V_24 ) ;
if ( ! V_6 -> V_91 . V_86 )
goto V_352;
}
F_36 (transport, &asoc->peer.transport_addr_list,
transports) {
V_99 -> V_363 = V_6 -> V_91 . V_304 . V_54 ;
}
if ( ! F_130 ( & V_6 -> V_91 . V_132 , V_364 ,
V_6 -> V_91 . V_304 . V_60 , V_24 ) )
goto V_352;
if ( F_131 ( & V_6 -> V_122 , V_6 -> V_52 . V_57 ,
V_6 -> V_52 . V_59 , V_24 ) )
goto V_352;
if ( ! V_6 -> V_239 && F_132 ( V_6 , V_24 ) )
goto V_352;
V_6 -> V_91 . V_290 = V_6 -> V_91 . V_304 . V_60 - 1 ;
return 1 ;
V_352:
F_126 (pos, temp, &asoc->peer.transport_addr_list) {
V_99 = F_127 ( V_345 , struct V_139 , V_358 ) ;
if ( V_99 -> V_359 != V_349 )
F_128 ( V_6 , V_99 ) ;
}
V_350:
return 0 ;
}
static int F_125 ( struct V_5 * V_6 ,
union V_43 V_180 ,
const union V_216 * V_241 ,
T_4 V_24 )
{
struct V_26 * V_26 = F_12 ( V_6 -> V_8 . V_7 ) ;
struct V_36 * V_37 = V_6 -> V_37 ;
union V_365 * V_366 ;
struct V_139 * V_367 ;
enum V_237 V_238 ;
union V_216 V_346 ;
struct V_347 * V_10 ;
int V_38 = 1 , V_304 ;
T_10 V_368 ;
T_3 V_35 ;
switch ( V_180 . V_250 -> type ) {
case V_325 :
if ( V_369 != V_6 -> V_8 . V_7 -> V_370 )
break;
goto V_371;
case V_324 :
if ( F_133 ( V_6 -> V_8 . V_7 ) )
break;
V_371:
V_10 = F_123 ( F_124 ( V_180 . V_250 -> type ) ) ;
V_10 -> V_351 ( & V_346 , V_180 . V_346 , F_6 ( V_6 -> V_91 . V_285 ) , 0 ) ;
V_238 = V_237 ( V_241 ) ;
if ( F_134 ( V_26 , & V_346 , V_238 ) )
if ( ! F_121 ( V_6 , & V_346 , V_24 , V_372 ) )
return 0 ;
break;
case V_326 :
if ( ! V_26 -> V_66 . V_373 )
break;
V_368 = F_101 ( V_180 . V_374 -> V_375 ) ;
V_6 -> V_254 = F_135 ( V_6 -> V_254 , V_368 ) ;
break;
case V_332 :
F_32 ( L_6 , V_144 ) ;
break;
case V_81 :
V_6 -> V_91 . V_376 = 0 ;
V_6 -> V_91 . V_377 = 0 ;
if ( V_241 -> V_378 . V_379 == V_380 )
V_6 -> V_91 . V_377 = 1 ;
else if ( V_241 -> V_378 . V_379 == V_381 )
V_6 -> V_91 . V_376 = 1 ;
V_35 = F_18 ( V_180 . V_250 -> V_18 ) - sizeof( struct V_31 ) ;
if ( V_35 )
V_35 /= sizeof( T_3 ) ;
for ( V_304 = 0 ; V_304 < V_35 ; ++ V_304 ) {
switch ( V_180 . V_35 -> V_49 [ V_304 ] ) {
case V_324 :
V_6 -> V_91 . V_376 = 1 ;
break;
case V_325 :
if ( V_369 == V_6 -> V_8 . V_7 -> V_370 )
V_6 -> V_91 . V_377 = 1 ;
break;
case V_332 :
V_6 -> V_91 . V_382 = 1 ;
break;
default:
break;
}
}
break;
case V_251 :
V_6 -> V_91 . V_88 =
F_18 ( V_180 . V_250 -> V_18 ) - sizeof( struct V_31 ) ;
V_6 -> V_91 . V_86 = V_180 . V_86 -> V_249 ;
break;
case V_185 :
break;
case V_327 :
break;
case V_328 :
V_6 -> V_91 . V_92 = 1 ;
break;
case V_83 :
V_6 -> V_91 . V_72 = F_101 ( V_180 . V_383 -> V_72 ) ;
break;
case V_330 :
if ( ! V_26 -> V_66 . V_67 )
goto V_384;
V_366 = V_180 . V_80 + sizeof( struct V_385 ) ;
V_10 = F_123 ( F_124 ( V_366 -> V_250 . type ) ) ;
if ( V_10 == NULL )
break;
V_10 -> V_351 ( & V_346 , V_366 ,
F_6 ( V_6 -> V_91 . V_285 ) , 0 ) ;
if ( ! V_10 -> V_386 ( & V_346 , NULL , NULL ) )
break;
V_367 = F_136 ( V_6 , & V_346 ) ;
if ( ! V_367 )
break;
F_137 ( V_6 , V_367 ) ;
break;
case V_82 :
F_115 ( V_6 , V_180 ) ;
break;
case V_333 :
if ( V_6 -> V_64 ) {
V_6 -> V_91 . V_93 = 1 ;
break;
}
goto V_384;
case V_334 :
if ( ! V_37 -> V_73 )
goto V_384;
V_6 -> V_91 . V_353 = F_129 ( V_180 . V_250 ,
F_18 ( V_180 . V_250 -> V_18 ) , V_24 ) ;
if ( ! V_6 -> V_91 . V_353 ) {
V_38 = 0 ;
break;
}
break;
case V_337 :
if ( ! V_37 -> V_73 )
goto V_384;
V_6 -> V_91 . V_354 = F_129 ( V_180 . V_250 ,
F_18 ( V_180 . V_250 -> V_18 ) , V_24 ) ;
if ( ! V_6 -> V_91 . V_354 ) {
V_38 = 0 ;
break;
}
F_138 ( V_6 , V_180 . V_387 ) ;
break;
case V_336 :
if ( ! V_37 -> V_73 )
goto V_384;
V_6 -> V_91 . V_388 = F_129 ( V_180 . V_250 ,
F_18 ( V_180 . V_250 -> V_18 ) , V_24 ) ;
if ( ! V_6 -> V_91 . V_388 )
V_38 = 0 ;
break;
V_384:
default:
F_32 ( L_7 ,
V_144 , F_18 ( V_180 . V_250 -> type ) , V_6 ) ;
break;
}
return V_38 ;
}
T_6 F_139 ( const struct V_36 * V_37 )
{
T_6 V_389 ;
do {
F_140 ( & V_389 , sizeof( T_6 ) ) ;
} while ( V_389 == 0 );
return V_389 ;
}
T_6 F_141 ( const struct V_36 * V_37 )
{
T_6 V_38 ;
F_140 ( & V_38 , sizeof( T_6 ) ) ;
return V_38 ;
}
static struct V_3 * F_142 ( struct V_5 * V_6 ,
union V_216 * V_346 ,
int V_25 )
{
struct V_390 V_391 ;
struct V_3 * V_38 ;
int V_18 = sizeof( V_391 ) + V_25 ;
union V_365 V_392 ;
int V_393 ;
struct V_347 * V_10 = F_123 ( V_346 -> V_276 . V_394 ) ;
V_393 = V_10 -> V_395 ( V_346 , & V_392 ) ;
if ( ! V_393 )
return NULL ;
V_18 += V_393 ;
V_38 = F_19 ( V_6 , V_68 , 0 , V_18 ,
V_101 ) ;
if ( ! V_38 )
return NULL ;
V_391 . V_396 = F_14 ( V_6 -> V_290 ++ ) ;
V_38 -> V_19 . V_397 =
F_7 ( V_38 , sizeof( V_391 ) , & V_391 ) ;
V_38 -> V_79 . V_80 =
F_7 ( V_38 , V_393 , & V_392 ) ;
return V_38 ;
}
struct V_3 * F_143 ( struct V_5 * V_6 ,
union V_216 * V_398 ,
struct V_399 * V_44 ,
int V_400 , T_1 V_116 )
{
union V_365 V_366 ;
struct V_385 V_180 ;
int V_401 = sizeof( V_180 ) ;
struct V_3 * V_38 ;
int V_402 = 0 ;
union V_216 * V_346 ;
int V_403 = 0 , V_304 ;
int V_404 = 0 ;
struct V_347 * V_10 ;
void * V_405 ;
V_405 = V_44 ;
for ( V_304 = 0 ; V_304 < V_400 ; V_304 ++ ) {
V_346 = V_405 ;
V_10 = F_123 ( V_346 -> V_276 . V_394 ) ;
V_402 = V_10 -> V_395 ( V_346 , & V_366 ) ;
V_403 += V_401 ;
V_403 += V_402 ;
V_405 += V_10 -> V_406 ;
if ( V_6 -> V_407 && ! V_404 ) {
V_403 += V_401 ;
V_403 += V_402 ;
V_404 = 1 ;
F_32 ( L_8
L_9 ,
V_144 , V_403 ) ;
}
}
V_38 = F_142 ( V_6 , V_398 , V_403 ) ;
if ( ! V_38 )
return NULL ;
V_405 = V_44 ;
for ( V_304 = 0 ; V_304 < V_400 ; V_304 ++ ) {
V_346 = V_405 ;
V_10 = F_123 ( V_346 -> V_276 . V_394 ) ;
V_402 = V_10 -> V_395 ( V_346 , & V_366 ) ;
V_180 . V_79 . type = V_116 ;
V_180 . V_79 . V_18 = F_6 ( V_401 + V_402 ) ;
V_180 . V_408 = F_14 ( V_304 ) ;
F_7 ( V_38 , V_401 , & V_180 ) ;
F_7 ( V_38 , V_402 , & V_366 ) ;
V_405 += V_10 -> V_406 ;
}
if ( V_116 == V_356 && V_404 ) {
V_346 = V_6 -> V_407 ;
V_10 = F_123 ( V_346 -> V_276 . V_394 ) ;
V_402 = V_10 -> V_395 ( V_346 , & V_366 ) ;
V_180 . V_79 . type = V_357 ;
V_180 . V_79 . V_18 = F_6 ( V_401 + V_402 ) ;
V_180 . V_408 = F_14 ( V_304 ) ;
F_7 ( V_38 , V_401 , & V_180 ) ;
F_7 ( V_38 , V_402 , & V_366 ) ;
}
return V_38 ;
}
struct V_3 * F_144 ( struct V_5 * V_6 ,
union V_216 * V_346 )
{
struct V_347 * V_10 = F_123 ( V_346 -> V_276 . V_394 ) ;
union V_365 V_392 ;
struct V_385 V_180 ;
struct V_3 * V_38 ;
int V_16 = sizeof( V_180 ) ;
int V_393 ;
V_393 = V_10 -> V_395 ( V_346 , & V_392 ) ;
if ( ! V_393 )
return NULL ;
V_16 += V_393 ;
V_38 = F_142 ( V_6 , V_346 , V_16 ) ;
if ( ! V_38 )
return NULL ;
V_180 . V_79 . type = V_330 ;
V_180 . V_79 . V_18 = F_6 ( V_16 ) ;
V_180 . V_408 = 0 ;
F_7 ( V_38 , sizeof( V_180 ) , & V_180 ) ;
F_7 ( V_38 , V_393 , & V_392 ) ;
return V_38 ;
}
static struct V_3 * F_145 ( const struct V_5 * V_6 ,
T_6 V_396 , int V_25 )
{
struct V_390 V_391 ;
struct V_3 * V_38 ;
int V_18 = sizeof( V_391 ) + V_25 ;
V_38 = F_19 ( V_6 , V_69 , 0 , V_18 ,
V_101 ) ;
if ( ! V_38 )
return NULL ;
V_391 . V_396 = F_14 ( V_396 ) ;
V_38 -> V_19 . V_397 =
F_7 ( V_38 , sizeof( V_391 ) , & V_391 ) ;
return V_38 ;
}
static void F_146 ( struct V_3 * V_4 , T_7 V_408 ,
T_1 V_409 ,
struct V_385 * V_410 )
{
struct V_385 V_411 ;
struct V_14 V_412 ;
int V_413 = 0 ;
int V_414 = 0 ;
T_1 V_415 ;
if ( V_416 == V_409 ) {
V_415 = V_417 ;
} else {
V_415 = V_418 ;
V_414 = sizeof( V_412 ) ;
if ( V_410 )
V_413 =
F_18 ( V_410 -> V_79 . V_18 ) ;
}
V_411 . V_79 . type = V_415 ;
V_411 . V_79 . V_18 = F_6 ( sizeof( V_411 ) +
V_414 +
V_413 ) ;
V_411 . V_408 = V_408 ;
F_7 ( V_4 , sizeof( V_411 ) , & V_411 ) ;
if ( V_416 == V_409 )
return;
V_412 . V_17 = V_409 ;
V_412 . V_18 = F_6 ( V_414 + V_413 ) ;
F_7 ( V_4 , V_414 , & V_412 ) ;
if ( V_410 )
F_7 ( V_4 , V_413 , V_410 ) ;
}
static T_1 F_147 ( struct V_5 * V_6 ,
struct V_3 * V_391 ,
struct V_385 * V_410 )
{
union V_365 * V_366 ;
struct V_139 * V_91 ;
union V_216 V_346 ;
struct V_347 * V_10 ;
V_366 = ( void * ) V_410 + sizeof( * V_410 ) ;
if ( V_410 -> V_79 . type != V_356 &&
V_410 -> V_79 . type != V_357 &&
V_410 -> V_79 . type != V_330 )
return V_317 ;
switch ( V_366 -> V_250 . type ) {
case V_325 :
if ( ! V_6 -> V_91 . V_377 )
return V_301 ;
break;
case V_324 :
if ( ! V_6 -> V_91 . V_376 )
return V_301 ;
break;
default:
return V_301 ;
}
V_10 = F_123 ( F_124 ( V_366 -> V_250 . type ) ) ;
if ( F_58 ( ! V_10 ) )
return V_301 ;
V_10 -> V_351 ( & V_346 , V_366 , F_6 ( V_6 -> V_91 . V_285 ) , 0 ) ;
if ( ! V_10 -> V_419 ( & V_346 ) && ! V_10 -> V_386 ( & V_346 , NULL , V_391 -> V_2 ) )
return V_301 ;
switch ( V_410 -> V_79 . type ) {
case V_356 :
if ( V_10 -> V_419 ( & V_346 ) )
memcpy ( & V_346 , & V_391 -> V_219 , sizeof( V_346 ) ) ;
V_91 = F_121 ( V_6 , & V_346 , V_101 , V_372 ) ;
if ( ! V_91 )
return V_420 ;
F_148 ( V_91 ) ;
V_6 -> V_421 = V_91 ;
break;
case V_357 :
if ( V_6 -> V_91 . V_422 == 1 )
return V_423 ;
if ( F_122 ( & V_391 -> V_219 , & V_346 ) )
return V_424 ;
if ( V_10 -> V_419 ( & V_346 ) ) {
F_137 ( V_6 , V_391 -> V_99 ) ;
F_149 ( V_6 ,
V_391 -> V_99 ) ;
return V_416 ;
}
V_91 = F_136 ( V_6 , & V_346 ) ;
if ( ! V_91 )
return V_301 ;
F_128 ( V_6 , V_91 ) ;
break;
case V_330 :
if ( V_10 -> V_419 ( & V_346 ) )
memcpy ( & V_346 . V_276 , F_66 ( V_391 ) , sizeof( V_346 ) ) ;
V_91 = F_136 ( V_6 , & V_346 ) ;
if ( ! V_91 )
return V_301 ;
F_137 ( V_6 , V_91 ) ;
break;
}
return V_416 ;
}
bool F_150 ( const struct V_5 * V_6 ,
struct V_3 * V_4 , bool V_425 ,
struct V_31 * * V_262 )
{
struct V_426 * V_427 ;
bool V_428 = false ;
union V_43 V_180 ;
V_427 = (struct V_426 * ) V_4 -> V_161 ;
F_119 (param, addip, addip_hdr.params) {
T_2 V_18 = F_18 ( V_180 . V_250 -> V_18 ) ;
* V_262 = V_180 . V_250 ;
switch ( V_180 . V_250 -> type ) {
case V_418 :
break;
case V_324 :
if ( V_18 != sizeof( struct V_429 ) )
return false ;
if ( V_180 . V_80 != V_427 -> V_397 . V_430 )
return false ;
V_428 = true ;
break;
case V_325 :
if ( V_18 != sizeof( struct V_431 ) )
return false ;
if ( V_180 . V_80 != V_427 -> V_397 . V_430 )
return false ;
V_428 = true ;
break;
case V_356 :
case V_357 :
case V_330 :
if ( V_425 && ! V_428 )
return false ;
V_18 = F_18 ( V_180 . V_427 -> V_79 . V_18 ) ;
if ( V_18 < sizeof( struct V_385 ) +
sizeof( * * V_262 ) )
return false ;
break;
case V_417 :
case V_83 :
if ( V_18 != sizeof( struct V_385 ) )
return false ;
break;
default:
return false ;
}
}
if ( V_425 && ! V_428 )
return false ;
if ( ! V_425 && V_428 )
return false ;
if ( V_180 . V_80 != V_4 -> V_176 )
return false ;
return true ;
}
struct V_3 * F_151 ( struct V_5 * V_6 ,
struct V_3 * V_391 )
{
union V_365 * V_366 ;
struct V_426 * V_427 ;
struct V_3 * V_432 ;
bool V_433 = true ;
struct V_390 * V_434 ;
int V_18 = 0 , V_120 ;
union V_43 V_180 ;
T_1 V_409 ;
T_6 V_396 ;
V_427 = (struct V_426 * ) V_391 -> V_161 ;
V_120 = F_18 ( V_391 -> V_161 -> V_18 ) -
sizeof( struct V_220 ) ;
V_434 = (struct V_390 * ) V_391 -> V_2 -> V_173 ;
V_396 = F_101 ( V_434 -> V_396 ) ;
V_18 = sizeof( * V_434 ) ;
V_366 = (union V_365 * ) ( V_391 -> V_2 -> V_173 + V_18 ) ;
V_120 -= V_18 ;
V_18 = F_18 ( V_366 -> V_250 . V_18 ) ;
V_120 -= V_18 ;
V_432 = F_145 ( V_6 , V_396 , V_120 * 4 ) ;
if ( ! V_432 )
goto V_435;
F_119 (param, addip, addip_hdr.params) {
if ( V_180 . V_250 -> type == V_324 ||
V_180 . V_250 -> type == V_325 )
continue;
V_409 = F_147 ( V_6 , V_391 ,
V_180 . V_427 ) ;
if ( V_409 != V_416 )
V_433 = false ;
if ( ! V_433 )
F_146 ( V_432 , V_180 . V_427 -> V_408 ,
V_409 , V_180 . V_427 ) ;
if ( V_409 == V_420 )
goto V_435;
}
V_435:
V_6 -> V_91 . V_290 ++ ;
if ( V_432 ) {
F_80 ( V_432 ) ;
F_152 ( & V_432 -> V_213 ,
& V_6 -> V_436 ) ;
}
return V_432 ;
}
static void F_153 ( struct V_5 * V_6 ,
struct V_385 * V_410 )
{
struct V_22 * V_23 = & V_6 -> V_8 . V_89 ;
union V_365 * V_366 ;
struct V_437 * V_438 ;
struct V_139 * V_99 ;
union V_216 V_346 ;
struct V_347 * V_10 ;
V_366 = ( void * ) V_410 + sizeof( * V_410 ) ;
V_10 = F_123 ( F_124 ( V_366 -> V_250 . type ) ) ;
V_10 -> V_351 ( & V_346 , V_366 , F_6 ( V_23 -> V_285 ) , 0 ) ;
switch ( V_410 -> V_79 . type ) {
case V_356 :
F_154 () ;
F_36 (saddr, &bp->address_list, list) {
if ( F_122 ( & V_438 -> V_439 , & V_346 ) )
V_438 -> V_359 = V_287 ;
}
F_155 () ;
F_36 (transport, &asoc->peer.transport_addr_list,
transports) {
F_156 ( V_99 ) ;
}
break;
case V_357 :
F_154 () ;
F_157 ( V_23 , & V_346 ) ;
if ( V_6 -> V_407 != NULL &&
F_122 ( V_6 -> V_407 , & V_346 ) ) {
F_21 ( V_6 -> V_407 ) ;
V_6 -> V_407 = NULL ;
}
F_155 () ;
F_36 (transport, &asoc->peer.transport_addr_list,
transports) {
F_156 ( V_99 ) ;
}
break;
default:
break;
}
}
static T_1 F_158 ( struct V_3 * V_432 ,
struct V_385 * V_410 ,
int V_440 )
{
struct V_385 * V_441 ;
struct V_14 * V_412 ;
int V_442 ;
T_1 V_409 ;
int V_18 ;
if ( V_440 )
V_409 = V_416 ;
else
V_409 = V_443 ;
V_442 = F_18 ( V_432 -> V_161 -> V_18 ) -
sizeof( struct V_220 ) ;
V_18 = sizeof( struct V_390 ) ;
V_441 = (struct V_385 * ) ( V_432 -> V_2 -> V_173 +
V_18 ) ;
V_442 -= V_18 ;
while ( V_442 > 0 ) {
if ( V_441 -> V_408 == V_410 -> V_408 ) {
switch ( V_441 -> V_79 . type ) {
case V_417 :
return V_416 ;
case V_418 :
V_18 = sizeof( * V_441 ) ;
V_412 = ( void * ) V_441 + V_18 ;
V_442 -= V_18 ;
if ( V_442 > 0 )
return V_412 -> V_17 ;
else
return V_300 ;
break;
default:
return V_300 ;
}
}
V_18 = F_18 ( V_441 -> V_79 . V_18 ) ;
V_441 = ( void * ) V_441 + V_18 ;
V_442 -= V_18 ;
}
return V_409 ;
}
int F_159 ( struct V_5 * V_6 ,
struct V_3 * V_432 )
{
struct V_3 * V_391 = V_6 -> V_444 ;
struct V_385 * V_410 ;
T_1 V_409 = V_416 ;
union V_365 * V_366 ;
int V_445 = V_391 -> V_2 -> V_16 ;
int V_433 = 0 ;
int V_18 = 0 ;
int V_440 = 1 ;
int V_38 = 0 ;
V_18 = sizeof( struct V_426 ) ;
V_366 = (union V_365 * ) ( V_391 -> V_2 -> V_173 + V_18 ) ;
V_445 -= V_18 ;
V_18 = F_18 ( V_366 -> V_250 . V_18 ) ;
V_410 = ( void * ) V_366 + V_18 ;
V_445 -= V_18 ;
if ( V_432 -> V_2 -> V_16 == sizeof( struct V_390 ) )
V_433 = 1 ;
while ( V_445 > 0 ) {
if ( V_433 )
V_409 = V_416 ;
else {
V_409 = F_158 ( V_432 ,
V_410 ,
V_440 ) ;
if ( V_440 && ( V_416 != V_409 ) )
V_440 = 0 ;
}
switch ( V_409 ) {
case V_416 :
F_153 ( V_6 , V_410 ) ;
break;
case V_420 :
V_38 = 1 ;
break;
case V_317 :
V_6 -> V_91 . V_355 |=
V_410 -> V_79 . type ;
break;
case V_443 :
case V_423 :
case V_424 :
default:
break;
}
V_18 = F_18 ( V_410 -> V_79 . V_18 ) ;
V_410 = ( void * ) V_410 + V_18 ;
V_445 -= V_18 ;
}
if ( V_440 && V_6 -> V_446 ) {
V_6 -> V_446 = 0 ;
F_160 ( V_6 -> V_91 . V_447 ) ;
}
F_74 ( & V_391 -> V_213 ) ;
F_45 ( V_391 ) ;
V_6 -> V_444 = NULL ;
return V_38 ;
}
struct V_3 * F_161 ( const struct V_5 * V_6 ,
T_6 V_448 , T_2 V_449 ,
struct V_450 * V_451 )
{
struct V_3 * V_38 = NULL ;
struct V_452 V_453 ;
struct V_450 V_454 ;
T_2 V_160 ;
int V_304 ;
V_160 = ( V_449 + 1 ) * sizeof( T_6 ) ;
V_38 = F_19 ( V_6 , V_308 , 0 , V_160 , V_101 ) ;
if ( ! V_38 )
return NULL ;
V_453 . V_448 = F_14 ( V_448 ) ;
V_38 -> V_19 . V_455 =
F_7 ( V_38 , sizeof( V_453 ) , & V_453 ) ;
for ( V_304 = 0 ; V_304 < V_449 ; V_304 ++ ) {
V_454 . V_122 = V_451 [ V_304 ] . V_122 ;
V_454 . V_117 = V_451 [ V_304 ] . V_117 ;
F_7 ( V_38 , sizeof( V_454 ) , & V_454 ) ;
}
return V_38 ;
}
static struct V_3 * F_162 ( const struct V_5 * V_6 ,
int V_18 )
{
struct V_456 * V_457 ;
struct V_3 * V_38 ;
V_38 = F_19 ( V_6 , V_71 , 0 , V_18 ,
V_101 ) ;
if ( ! V_38 )
return NULL ;
V_457 = (struct V_456 * ) V_38 -> V_161 ;
V_38 -> V_79 . V_80 = V_457 -> V_430 ;
return V_38 ;
}
struct V_3 * F_163 (
const struct V_5 * V_6 ,
T_3 V_458 , T_1 * V_459 ,
bool V_235 , bool V_460 )
{
struct V_461 V_462 ;
T_3 V_463 = V_458 * 2 ;
struct V_464 V_465 ;
struct V_3 * V_38 ;
T_3 V_466 , V_467 ;
V_466 = ( sizeof( V_462 ) + V_463 ) * V_235 ;
V_467 = ( sizeof( V_465 ) + V_463 ) * V_460 ;
V_38 = F_162 ( V_6 , V_466 + V_467 ) ;
if ( ! V_38 )
return NULL ;
if ( V_466 ) {
V_462 . V_79 . type = V_468 ;
V_462 . V_79 . V_18 = F_6 ( V_466 ) ;
V_462 . V_469 = F_14 ( V_6 -> V_291 ) ;
V_462 . V_470 = F_14 ( V_6 -> V_361 - 1 ) ;
V_462 . V_471 = F_14 ( V_6 -> V_288 - 1 ) ;
F_7 ( V_38 , sizeof( V_462 ) , & V_462 ) ;
if ( V_463 )
F_7 ( V_38 , V_463 , V_459 ) ;
}
if ( V_467 ) {
V_465 . V_79 . type = V_472 ;
V_465 . V_79 . V_18 = F_6 ( V_467 ) ;
V_465 . V_469 = F_14 ( V_6 -> V_291 + V_235 ) ;
F_7 ( V_38 , sizeof( V_465 ) , & V_465 ) ;
if ( V_463 )
F_7 ( V_38 , V_463 , V_459 ) ;
}
return V_38 ;
}
struct V_3 * F_164 (
const struct V_5 * V_6 )
{
struct V_473 V_474 ;
T_3 V_18 = sizeof( V_474 ) ;
struct V_3 * V_38 ;
V_38 = F_162 ( V_6 , V_18 ) ;
if ( ! V_38 )
return NULL ;
V_474 . V_79 . type = V_475 ;
V_474 . V_79 . V_18 = F_6 ( V_18 ) ;
V_474 . V_469 = F_14 ( V_6 -> V_291 ) ;
F_7 ( V_38 , sizeof( V_474 ) , & V_474 ) ;
return V_38 ;
}
struct V_3 * F_165 (
const struct V_5 * V_6 ,
T_3 V_235 , T_3 V_460 )
{
struct V_476 V_477 ;
T_3 V_193 = sizeof( V_477 ) ;
struct V_3 * V_38 ;
V_38 = F_162 ( V_6 , ( ! ! V_235 + ! ! V_460 ) * V_193 ) ;
if ( ! V_38 )
return NULL ;
if ( V_235 ) {
V_477 . V_79 . type = V_478 ;
V_477 . V_79 . V_18 = F_6 ( V_193 ) ;
V_477 . V_479 = F_6 ( V_235 ) ;
V_477 . V_469 = F_14 ( V_6 -> V_291 ) ;
V_477 . V_480 = 0 ;
F_7 ( V_38 , V_193 , & V_477 ) ;
}
if ( V_460 ) {
V_477 . V_79 . type = V_481 ;
V_477 . V_79 . V_18 = F_6 ( V_193 ) ;
V_477 . V_479 = F_6 ( V_460 ) ;
V_477 . V_469 = F_14 ( V_6 -> V_291 + ! ! V_235 ) ;
V_477 . V_480 = 0 ;
F_7 ( V_38 , V_193 , & V_477 ) ;
}
return V_38 ;
}
struct V_3 * F_166 ( const struct V_5 * V_6 ,
T_6 V_342 , T_6 V_482 )
{
struct V_483 V_484 ;
T_3 V_18 = sizeof( V_484 ) ;
struct V_3 * V_38 ;
V_38 = F_162 ( V_6 , V_18 ) ;
if ( ! V_38 )
return NULL ;
V_484 . V_79 . type = V_485 ;
V_484 . V_79 . V_18 = F_6 ( V_18 ) ;
V_484 . V_470 = F_14 ( V_482 ) ;
V_484 . V_342 = F_14 ( V_342 ) ;
F_7 ( V_38 , sizeof( V_484 ) , & V_484 ) ;
return V_38 ;
}
struct V_3 * F_167 ( struct V_5 * V_6 ,
T_6 V_342 , T_6 V_482 ,
T_6 V_486 ,
T_6 V_487 )
{
struct V_488 V_489 ;
T_3 V_18 = sizeof( V_489 ) ;
struct V_3 * V_38 ;
V_38 = F_162 ( V_6 , V_18 ) ;
if ( ! V_38 )
return NULL ;
V_489 . V_79 . type = V_485 ;
V_489 . V_79 . V_18 = F_6 ( V_18 ) ;
V_489 . V_470 = F_14 ( V_482 ) ;
V_489 . V_342 = F_14 ( V_342 ) ;
V_489 . V_490 = F_14 ( V_486 ) ;
V_489 . V_491 = F_14 ( V_487 ) ;
F_7 ( V_38 , sizeof( V_489 ) , & V_489 ) ;
return V_38 ;
}
bool F_168 ( const struct V_5 * V_6 ,
struct V_3 * V_4 ,
struct V_31 * * V_262 )
{
struct V_456 * V_434 ;
union V_43 V_180 ;
T_1 V_492 = 0 ;
T_3 V_493 = 0 ;
V_434 = (struct V_456 * ) V_4 -> V_161 ;
F_119 (param, hdr, params) {
T_3 V_18 = F_18 ( V_180 . V_250 -> V_18 ) ;
* V_262 = V_180 . V_250 ;
if ( V_493 ++ > 2 )
return false ;
switch ( V_180 . V_250 -> type ) {
case V_468 :
if ( V_18 < sizeof( struct V_461 ) ||
( V_492 && V_492 != V_485 &&
V_492 != V_472 ) )
return false ;
break;
case V_472 :
if ( V_18 < sizeof( struct V_464 ) ||
( V_492 && V_492 != V_468 ) )
return false ;
break;
case V_485 :
if ( ( V_18 != sizeof( struct V_483 ) &&
V_18 != sizeof( struct V_488 ) ) ||
( V_492 && V_492 != V_485 &&
V_492 != V_468 ) )
return false ;
break;
case V_475 :
if ( V_18 !=
sizeof( struct V_473 ) || V_492 )
return false ;
break;
case V_481 :
if ( V_18 != sizeof( struct V_476 ) ||
( V_492 && V_492 != V_478 ) )
return false ;
break;
case V_478 :
if ( V_18 != sizeof( struct V_476 ) ||
( V_492 && V_492 != V_481 ) )
return false ;
break;
default:
return false ;
}
V_492 = V_180 . V_250 -> type ;
}
return true ;
}

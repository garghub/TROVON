int F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 = 0 ;
V_4 = F_2 ( F_3 ( F_4 ( V_2 -> V_6 ) -> V_7 ) ) ;
if ( V_4 )
V_5 = V_4 -> V_8 ( V_2 -> V_6 ) ;
return V_5 ;
}
void F_5 ( struct V_1 * V_2 , T_1 V_9 ,
T_2 V_10 )
{
T_3 V_11 ;
T_4 V_12 ;
V_11 . V_13 = V_9 ;
V_12 = sizeof( T_3 ) + V_10 ;
V_11 . V_14 = F_6 ( V_12 ) ;
V_2 -> V_15 . V_16 = F_7 ( V_2 , sizeof( T_3 ) , & V_11 ) ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_9 ,
T_2 V_10 )
{
T_3 V_11 ;
T_4 V_12 ;
V_11 . V_13 = V_9 ;
V_12 = sizeof( T_3 ) + V_10 ;
V_11 . V_14 = F_6 ( V_12 ) ;
if ( F_9 ( V_2 -> V_6 ) < V_12 )
return - V_17 ;
V_2 -> V_15 . V_16 = F_10 ( V_2 ,
sizeof( T_3 ) ,
& V_11 ) ;
return 0 ;
}
struct V_1 * F_11 ( const struct V_18 * V_19 ,
const struct V_20 * V_21 ,
T_5 V_22 , int V_23 )
{
T_6 V_24 ;
union V_25 V_26 ;
T_2 V_27 ;
struct V_1 * V_28 = NULL ;
int V_29 , V_30 = 0 ;
struct V_31 * V_32 ;
T_7 V_33 ;
T_1 V_34 [ 2 ] ;
T_8 V_35 ;
T_9 V_36 ;
int V_37 = 0 ;
T_10 V_38 [ 3 ] ;
T_11 * V_39 = NULL ,
* V_40 = NULL ;
V_28 = NULL ;
V_26 = F_12 ( V_21 , & V_30 , V_22 ) ;
V_24 . V_41 = F_13 ( V_19 -> V_42 . V_43 ) ;
V_24 . V_44 = F_13 ( V_19 -> V_45 ) ;
V_24 . V_46 = F_6 ( V_19 -> V_42 . V_47 ) ;
V_24 . V_48 = F_6 ( V_19 -> V_42 . V_49 ) ;
V_24 . V_50 = F_13 ( V_19 -> V_42 . V_50 ) ;
V_32 = F_14 ( V_19 -> V_51 . V_52 ) ;
V_29 = V_32 -> V_53 -> V_54 ( V_32 , V_34 ) ;
V_27 = sizeof( V_24 ) + V_30 ;
V_27 += F_15 ( F_16 ( V_29 ) ) ;
V_27 += sizeof( V_55 ) ;
if ( V_56 )
V_27 += sizeof( V_57 ) ;
if ( V_58 ) {
V_38 [ V_37 ] = V_59 ;
V_38 [ V_37 + 1 ] = V_60 ;
V_37 += 2 ;
}
if ( V_32 -> V_61 )
V_27 += sizeof( V_35 ) ;
V_27 += V_23 ;
if ( V_62 ) {
V_27 += sizeof( V_19 -> V_42 . V_63 ) ;
V_40 = ( T_11 * ) V_19 -> V_42 . V_40 ;
if ( V_40 -> V_14 )
V_27 += F_15 ( F_17 ( V_40 -> V_14 ) ) ;
else
V_40 = NULL ;
V_39 = ( T_11 * ) V_19 -> V_42 . V_39 ;
if ( V_39 -> V_14 )
V_27 += F_15 ( F_17 ( V_39 -> V_14 ) ) ;
else
V_39 = NULL ;
V_38 [ V_37 ] = V_64 ;
V_37 += 1 ;
}
if ( V_37 )
V_27 += F_15 ( sizeof( T_9 ) +
V_37 ) ;
V_28 = F_18 ( V_19 , V_65 , 0 , V_27 ) ;
if ( ! V_28 )
goto V_66;
V_28 -> V_15 . V_67 =
F_7 ( V_28 , sizeof( V_24 ) , & V_24 ) ;
V_28 -> V_68 . V_69 =
F_7 ( V_28 , V_30 , V_26 . V_69 ) ;
V_33 . V_68 . type = V_70 ;
V_33 . V_68 . V_14 = F_6 ( F_16 ( V_29 ) ) ;
F_7 ( V_28 , sizeof( V_33 ) , & V_33 ) ;
F_7 ( V_28 , V_29 * sizeof( T_4 ) , & V_34 ) ;
F_7 ( V_28 , sizeof( V_55 ) , & V_55 ) ;
if ( V_37 ) {
V_36 . V_68 . type = V_71 ;
V_36 . V_68 . V_14 =
F_6 ( sizeof( T_9 ) + V_37 ) ;
F_7 ( V_28 , sizeof( T_9 ) ,
& V_36 ) ;
F_19 ( V_28 , V_37 , V_38 ) ;
}
if ( V_56 )
F_7 ( V_28 , sizeof( V_57 ) , & V_57 ) ;
if ( V_32 -> V_61 ) {
V_35 . V_68 . type = V_72 ;
V_35 . V_68 . V_14 = F_6 ( sizeof( V_35 ) ) ;
V_35 . V_61 = F_13 ( V_32 -> V_61 ) ;
F_7 ( V_28 , sizeof( V_35 ) , & V_35 ) ;
}
if ( V_62 ) {
F_7 ( V_28 , sizeof( V_19 -> V_42 . V_63 ) ,
V_19 -> V_42 . V_63 ) ;
if ( V_40 )
F_7 ( V_28 , F_17 ( V_40 -> V_14 ) ,
V_40 ) ;
if ( V_39 )
F_7 ( V_28 , F_17 ( V_39 -> V_14 ) ,
V_39 ) ;
}
V_66:
F_20 ( V_26 . V_69 ) ;
return V_28 ;
}
struct V_1 * F_21 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
T_5 V_22 , int V_73 )
{
T_6 V_74 ;
struct V_1 * V_28 ;
union V_25 V_26 ;
struct V_31 * V_32 ;
int V_30 ;
T_12 * V_75 ;
int V_76 ;
T_2 V_27 ;
T_8 V_35 ;
T_9 V_36 ;
int V_37 = 0 ;
T_10 V_38 [ 3 ] ;
T_11 * V_39 = NULL ,
* V_40 = NULL ,
* V_63 = NULL ;
V_28 = NULL ;
V_26 = F_12 ( & V_19 -> V_51 . V_77 , & V_30 , V_22 ) ;
V_74 . V_41 = F_13 ( V_19 -> V_42 . V_43 ) ;
V_74 . V_44 = F_13 ( V_19 -> V_45 ) ;
V_74 . V_46 = F_6 ( V_19 -> V_42 . V_47 ) ;
V_74 . V_48 = F_6 ( V_19 -> V_42 . V_49 ) ;
V_74 . V_50 = F_13 ( V_19 -> V_42 . V_50 ) ;
V_75 = F_22 ( V_19 -> V_78 , V_19 , V_2 , & V_76 ,
V_26 . V_69 , V_30 ) ;
if ( ! V_75 )
goto V_79;
V_32 = F_14 ( V_19 -> V_51 . V_52 ) ;
V_27 = sizeof( V_74 ) + V_30 + V_76 + V_73 ;
if ( V_19 -> V_80 . V_81 )
V_27 += sizeof( V_55 ) ;
if ( V_19 -> V_80 . V_82 )
V_27 += sizeof( V_57 ) ;
if ( V_19 -> V_80 . V_83 ) {
V_38 [ V_37 ] = V_59 ;
V_38 [ V_37 + 1 ] = V_60 ;
V_37 += 2 ;
}
if ( V_32 -> V_61 )
V_27 += sizeof( V_35 ) ;
if ( V_19 -> V_80 . V_84 ) {
V_63 = ( T_11 * ) V_19 -> V_42 . V_63 ;
V_27 += F_17 ( V_63 -> V_14 ) ;
V_40 = ( T_11 * ) V_19 -> V_42 . V_40 ;
if ( V_40 -> V_14 )
V_27 += F_15 ( F_17 ( V_40 -> V_14 ) ) ;
else
V_40 = NULL ;
V_39 = ( T_11 * ) V_19 -> V_42 . V_39 ;
if ( V_39 -> V_14 )
V_27 += F_15 ( F_17 ( V_39 -> V_14 ) ) ;
else
V_39 = NULL ;
V_38 [ V_37 ] = V_64 ;
V_37 += 1 ;
}
if ( V_37 )
V_27 += F_15 ( sizeof( T_9 ) +
V_37 ) ;
V_28 = F_18 ( V_19 , V_85 , 0 , V_27 ) ;
if ( ! V_28 )
goto V_86;
V_28 -> V_87 = V_2 -> V_87 ;
V_28 -> V_15 . V_67 =
F_7 ( V_28 , sizeof( V_74 ) , & V_74 ) ;
V_28 -> V_68 . V_69 = F_7 ( V_28 , V_30 , V_26 . V_69 ) ;
F_7 ( V_28 , V_76 , V_75 ) ;
if ( V_19 -> V_80 . V_81 )
F_7 ( V_28 , sizeof( V_55 ) , & V_55 ) ;
if ( V_37 ) {
V_36 . V_68 . type = V_71 ;
V_36 . V_68 . V_14 =
F_6 ( sizeof( T_9 ) + V_37 ) ;
F_7 ( V_28 , sizeof( T_9 ) ,
& V_36 ) ;
F_19 ( V_28 , V_37 , V_38 ) ;
}
if ( V_19 -> V_80 . V_82 )
F_7 ( V_28 , sizeof( V_57 ) , & V_57 ) ;
if ( V_32 -> V_61 ) {
V_35 . V_68 . type = V_72 ;
V_35 . V_68 . V_14 = F_6 ( sizeof( V_35 ) ) ;
V_35 . V_61 = F_13 ( V_32 -> V_61 ) ;
F_7 ( V_28 , sizeof( V_35 ) , & V_35 ) ;
}
if ( V_19 -> V_80 . V_84 ) {
F_7 ( V_28 , F_17 ( V_63 -> V_14 ) ,
V_63 ) ;
if ( V_40 )
F_7 ( V_28 , F_17 ( V_40 -> V_14 ) ,
V_40 ) ;
if ( V_39 )
F_7 ( V_28 , F_17 ( V_39 -> V_14 ) ,
V_39 ) ;
}
V_28 -> V_19 = (struct V_18 * ) V_19 ;
V_86:
F_20 ( V_75 ) ;
V_79:
F_20 ( V_26 . V_69 ) ;
return V_28 ;
}
struct V_1 * F_23 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
struct V_1 * V_28 ;
void * V_75 ;
int V_76 ;
V_75 = V_19 -> V_80 . V_75 ;
V_76 = V_19 -> V_80 . V_76 ;
V_28 = F_18 ( V_19 , V_88 , 0 , V_76 ) ;
if ( ! V_28 )
goto V_66;
V_28 -> V_15 . V_89 =
F_7 ( V_28 , V_76 , V_75 ) ;
if ( V_2 )
V_28 -> V_87 = V_2 -> V_87 ;
V_66:
return V_28 ;
}
struct V_1 * F_24 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
struct V_1 * V_28 ;
V_28 = F_18 ( V_19 , V_90 , 0 , 0 ) ;
if ( V_28 && V_2 )
V_28 -> V_87 = V_2 -> V_87 ;
return V_28 ;
}
struct V_1 * F_25 ( const struct V_18 * V_19 ,
const T_13 V_91 ,
const struct V_1 * V_2 )
{
struct V_1 * V_28 ;
T_14 V_92 ;
V_92 . V_91 = F_13 ( V_91 ) ;
V_28 = F_18 ( V_19 , V_93 , 0 ,
sizeof( T_14 ) ) ;
if ( ! V_28 )
goto V_66;
V_28 -> V_15 . V_94 =
F_7 ( V_28 , sizeof( V_92 ) , & V_92 ) ;
if ( V_2 )
V_28 -> V_87 = V_2 -> V_87 ;
V_66:
return V_28 ;
}
struct V_1 * F_26 ( const struct V_18 * V_19 ,
const T_13 V_91 )
{
struct V_1 * V_28 ;
T_15 V_95 ;
V_95 . V_91 = F_13 ( V_91 ) ;
V_28 = F_18 ( V_19 , V_96 , 0 ,
sizeof( T_15 ) ) ;
if ( ! V_28 )
goto V_66;
V_28 -> V_15 . V_97 =
F_7 ( V_28 , sizeof( V_95 ) , & V_95 ) ;
V_66:
return V_28 ;
}
struct V_1 * F_27 ( struct V_18 * V_19 ,
const struct V_98 * V_99 ,
int V_100 , T_10 V_101 , T_4 V_102 )
{
struct V_1 * V_28 ;
struct V_103 V_104 ;
int V_105 ;
V_104 . V_106 = 0 ;
V_104 . V_107 = F_6 ( V_99 -> V_108 ) ;
V_104 . V_109 = V_99 -> V_110 ;
if ( V_99 -> V_111 & V_112 ) {
V_101 |= V_113 ;
V_104 . V_102 = 0 ;
} else
V_104 . V_102 = F_6 ( V_102 ) ;
V_105 = sizeof( V_104 ) + V_100 ;
V_28 = F_18 ( V_19 , V_114 , V_101 , V_105 ) ;
if ( ! V_28 )
goto V_66;
V_28 -> V_15 . V_115 = F_7 ( V_28 , sizeof( V_104 ) , & V_104 ) ;
memcpy ( & V_28 -> V_99 , V_99 , sizeof( struct V_98 ) ) ;
V_66:
return V_28 ;
}
struct V_1 * F_28 ( const struct V_18 * V_19 )
{
struct V_1 * V_28 ;
struct V_116 V_117 ;
int V_12 ;
T_13 V_118 ;
T_4 V_119 , V_120 ;
struct V_18 * V_121 = (struct V_18 * ) V_19 ;
struct V_122 * V_123 = (struct V_122 * ) & V_19 -> V_80 . V_124 ;
struct V_125 V_126 [ V_127 ] ;
struct V_128 * V_129 ;
memset ( V_126 , 0 , sizeof( V_126 ) ) ;
V_118 = F_29 ( V_123 ) ;
F_30 ( L_1 , V_118 ) ;
V_119 = F_31 ( V_123 , V_126 ) ;
V_120 = F_32 ( V_123 ) ;
V_117 . V_130 = F_13 ( V_118 ) ;
V_117 . V_44 = F_13 ( V_19 -> V_44 ) ;
V_117 . V_131 = F_6 ( V_119 ) ;
V_117 . V_120 = F_6 ( V_120 ) ;
V_12 = sizeof( V_117 )
+ sizeof( struct V_125 ) * V_119
+ sizeof( T_13 ) * V_120 ;
V_28 = F_18 ( V_19 , V_132 , 0 , V_12 ) ;
if ( ! V_28 )
goto V_66;
V_28 -> V_87 = V_19 -> V_80 . V_133 ;
V_28 -> V_15 . V_134 =
F_7 ( V_28 , sizeof( V_117 ) , & V_117 ) ;
if ( V_119 )
F_7 ( V_28 , sizeof( T_13 ) * V_119 ,
V_126 ) ;
if ( V_120 )
F_7 ( V_28 , sizeof( T_13 ) * V_120 ,
F_33 ( V_123 ) ) ;
if ( ++ V_121 -> V_80 . V_135 == 0 ) {
F_34 (trans, &asoc->peer.transport_addr_list,
transports)
V_129 -> V_135 = 0 ;
V_121 -> V_80 . V_135 = 1 ;
}
V_66:
return V_28 ;
}
struct V_1 * F_35 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
struct V_1 * V_28 ;
T_16 V_136 ;
T_13 V_118 ;
V_118 = F_29 ( & V_19 -> V_80 . V_124 ) ;
V_136 . V_130 = F_13 ( V_118 ) ;
V_28 = F_18 ( V_19 , V_137 , 0 ,
sizeof( T_16 ) ) ;
if ( ! V_28 )
goto V_66;
V_28 -> V_15 . V_138 =
F_7 ( V_28 , sizeof( V_136 ) , & V_136 ) ;
if ( V_2 )
V_28 -> V_87 = V_2 -> V_87 ;
V_66:
return V_28 ;
}
struct V_1 * F_36 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
struct V_1 * V_28 ;
V_28 = F_18 ( V_19 , V_139 , 0 , 0 ) ;
if ( V_28 && V_2 )
V_28 -> V_87 = V_2 -> V_87 ;
return V_28 ;
}
struct V_1 * F_37 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
struct V_1 * V_28 ;
T_10 V_101 = 0 ;
V_101 |= V_19 ? 0 : V_140 ;
V_28 = F_18 ( V_19 , V_141 , V_101 , 0 ) ;
if ( V_28 && V_2 )
V_28 -> V_87 = V_2 -> V_87 ;
return V_28 ;
}
struct V_1 * F_38 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
const T_2 V_142 )
{
struct V_1 * V_28 ;
T_10 V_101 = 0 ;
if ( ! V_19 ) {
if ( V_2 && V_2 -> V_143 &&
V_2 -> V_143 -> type == V_65 )
V_101 = 0 ;
else
V_101 = V_140 ;
}
V_28 = F_18 ( V_19 , V_144 , V_101 , V_142 ) ;
if ( V_28 && V_2 )
V_28 -> V_87 = V_2 -> V_87 ;
return V_28 ;
}
struct V_1 * F_39 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 , T_13 V_106 )
{
struct V_1 * V_28 ;
T_17 V_145 ;
V_28 = F_38 ( V_19 , V_2 , sizeof( T_3 )
+ sizeof( V_106 ) ) ;
if ( ! V_28 )
goto V_146;
V_145 = F_13 ( V_106 ) ;
F_5 ( V_28 , V_147 , sizeof( V_145 ) ) ;
F_7 ( V_28 , sizeof( V_145 ) , ( const void * ) & V_145 ) ;
if ( V_2 )
V_28 -> V_87 = V_2 -> V_87 ;
V_146:
return V_28 ;
}
struct V_1 * F_40 ( const struct V_18 * V_19 ,
const struct V_148 * V_149 ,
T_2 V_10 )
{
struct V_1 * V_28 ;
void * V_145 = NULL ;
int V_11 ;
V_28 = F_38 ( V_19 , NULL , sizeof( T_3 ) + V_10 ) ;
if ( ! V_28 )
goto V_150;
if ( V_10 ) {
V_145 = F_41 ( V_10 , V_151 ) ;
if ( ! V_145 )
goto V_152;
V_11 = F_42 ( V_145 , V_149 -> V_153 , V_10 ) ;
if ( V_11 < 0 )
goto V_154;
}
F_5 ( V_28 , V_155 , V_10 ) ;
F_7 ( V_28 , V_10 , V_145 ) ;
if ( V_10 )
F_20 ( V_145 ) ;
return V_28 ;
V_154:
F_20 ( V_145 ) ;
V_152:
F_43 ( V_28 ) ;
V_28 = NULL ;
V_150:
return V_28 ;
}
static void * F_19 ( struct V_1 * V_2 , int V_12 ,
const void * V_156 )
{
void * V_157 ;
int V_158 = F_17 ( V_2 -> V_143 -> V_14 ) ;
V_157 = F_44 ( V_2 -> V_6 , V_12 ) ;
if ( V_156 )
memcpy ( V_157 , V_156 , V_12 ) ;
else
memset ( V_157 , 0 , V_12 ) ;
V_2 -> V_143 -> V_14 = F_6 ( V_158 + V_12 ) ;
V_2 -> V_159 = F_45 ( V_2 -> V_6 ) ;
return V_157 ;
}
struct V_1 * F_46 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
const T_10 * V_145 ,
const T_2 V_10 )
{
struct V_1 * V_28 ;
struct V_160 V_161 ;
V_28 = F_38 ( V_19 , V_2 , sizeof( T_3 ) + V_10
+ sizeof( T_11 ) ) ;
if ( ! V_28 )
goto V_162;
F_5 ( V_28 , V_163 , V_10
+ sizeof( T_11 ) ) ;
V_161 . type = F_6 ( V_2 -> V_143 -> type ) ;
V_161 . V_14 = V_2 -> V_143 -> V_14 ;
F_7 ( V_28 , V_10 , V_145 ) ;
F_19 ( V_28 , sizeof( T_11 ) , & V_161 ) ;
V_162:
return V_28 ;
}
struct V_1 * F_47 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
struct V_160 * V_164 )
{
struct V_1 * V_28 ;
static const char error [] = L_2 ;
T_2 V_165 = sizeof( error ) + sizeof( T_3 ) +
sizeof( T_11 ) ;
V_28 = F_38 ( V_19 , V_2 , V_165 ) ;
if ( ! V_28 )
goto V_66;
F_5 ( V_28 , V_163 ,
sizeof( error ) + sizeof( T_11 ) ) ;
F_7 ( V_28 , sizeof( error ) , error ) ;
F_19 ( V_28 , sizeof( T_11 ) , V_164 ) ;
V_66:
return V_28 ;
}
struct V_1 * F_48 ( const struct V_18 * V_19 ,
const struct V_128 * V_87 )
{
struct V_1 * V_28 ;
T_18 V_166 ;
V_28 = F_18 ( V_19 , V_167 , 0 , sizeof( V_166 ) ) ;
if ( ! V_28 )
goto V_66;
V_166 . V_68 . type = V_168 ;
V_166 . V_68 . V_14 = F_6 ( sizeof( T_18 ) ) ;
V_166 . V_169 = V_87 -> V_170 ;
V_166 . V_171 = V_172 ;
V_166 . V_173 = V_87 -> V_173 ;
V_28 -> V_87 = (struct V_128 * ) V_87 ;
V_28 -> V_15 . V_174 = F_7 ( V_28 , sizeof( V_166 ) ,
& V_166 ) ;
V_66:
return V_28 ;
}
struct V_1 * F_49 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
const void * V_145 , const T_2 V_10 )
{
struct V_1 * V_28 ;
V_28 = F_18 ( V_19 , V_175 , 0 , V_10 ) ;
if ( ! V_28 )
goto V_66;
V_28 -> V_15 . V_174 = F_7 ( V_28 , V_10 , V_145 ) ;
if ( V_2 )
V_28 -> V_87 = V_2 -> V_87 ;
V_66:
return V_28 ;
}
static struct V_1 * F_50 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
T_2 V_176 )
{
struct V_1 * V_28 ;
V_28 = F_18 ( V_19 , V_177 , 0 ,
sizeof( T_3 ) + V_176 ) ;
if ( ! V_28 )
goto V_66;
if ( V_2 )
V_28 -> V_87 = V_2 -> V_87 ;
V_66:
return V_28 ;
}
static inline struct V_1 * F_51 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
T_2 V_176 = V_19 ? V_19 -> V_178 : 0 ;
if ( ! V_176 )
V_176 = V_179 ;
return F_50 ( V_19 , V_2 , V_176 ) ;
}
struct V_1 * F_52 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
T_1 V_9 , const void * V_145 ,
T_2 V_10 , T_2 V_180 )
{
struct V_1 * V_28 ;
V_28 = F_50 ( V_19 , V_2 , V_10 + V_180 ) ;
if ( ! V_28 )
goto V_66;
F_5 ( V_28 , V_9 , V_10 + V_180 ) ;
F_7 ( V_28 , V_10 , V_145 ) ;
if ( V_180 )
F_19 ( V_28 , V_180 , NULL ) ;
V_66:
return V_28 ;
}
struct V_1 * F_53 ( const struct V_18 * V_19 )
{
struct V_1 * V_28 ;
struct V_181 * V_182 ;
struct V_183 V_184 ;
T_10 * V_185 ;
V_182 = F_54 ( V_19 ) ;
if ( F_55 ( ! V_182 ) )
return NULL ;
V_28 = F_18 ( V_19 , V_64 , 0 ,
V_182 -> V_186 + sizeof( V_187 ) ) ;
if ( ! V_28 )
return NULL ;
V_184 . V_188 = F_6 ( V_182 -> V_188 ) ;
V_184 . V_189 = F_6 ( V_19 -> V_190 ) ;
V_28 -> V_15 . V_184 = F_7 ( V_28 , sizeof( V_187 ) ,
& V_184 ) ;
V_185 = F_44 ( V_28 -> V_6 , V_182 -> V_186 ) ;
memset ( V_185 , 0 , V_182 -> V_186 ) ;
V_28 -> V_143 -> V_14 =
F_6 ( F_17 ( V_28 -> V_143 -> V_14 ) + V_182 -> V_186 ) ;
V_28 -> V_159 = F_45 ( V_28 -> V_6 ) ;
return V_28 ;
}
struct V_1 * F_56 ( struct V_191 * V_6 ,
const struct V_18 * V_19 ,
struct V_192 * V_52 )
{
struct V_1 * V_28 ;
V_28 = F_57 ( V_193 , V_194 ) ;
if ( ! V_28 )
goto V_66;
if ( ! V_52 ) {
F_30 ( L_3 , V_6 ) ;
}
F_58 ( & V_28 -> V_195 ) ;
V_28 -> V_6 = V_6 ;
V_28 -> V_19 = (struct V_18 * ) V_19 ;
V_28 -> V_196 = 0 ;
V_28 -> V_197 = 0 ;
V_28 -> V_198 = 0 ;
V_28 -> V_171 = 0 ;
V_28 -> V_199 = 1 ;
V_28 -> V_200 = 0 ;
V_28 -> V_201 = 0 ;
V_28 -> V_202 = 0 ;
V_28 -> V_203 = 0 ;
V_28 -> V_204 = 0 ;
V_28 -> V_205 = V_206 ;
V_28 -> V_149 = NULL ;
F_58 ( & V_28 -> V_207 ) ;
F_58 ( & V_28 -> V_208 ) ;
F_59 ( V_2 ) ;
F_60 ( & V_28 -> V_209 , 1 ) ;
V_66:
return V_28 ;
}
void F_61 ( struct V_1 * V_2 , union V_210 * V_211 ,
union V_210 * V_212 )
{
memcpy ( & V_2 -> V_213 , V_211 , sizeof( union V_210 ) ) ;
memcpy ( & V_2 -> V_212 , V_212 , sizeof( union V_210 ) ) ;
}
const union V_210 * F_62 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_87 ) {
return & V_2 -> V_87 -> V_170 ;
} else {
return & V_2 -> V_213 ;
}
}
T_19
struct V_1 * F_18 ( const struct V_18 * V_19 ,
T_10 type , T_10 V_101 , int V_10 )
{
struct V_1 * V_28 ;
T_20 * V_143 ;
struct V_191 * V_6 ;
struct V_192 * V_52 ;
V_6 = F_63 ( F_15 ( sizeof( T_20 ) + V_10 ) ,
V_194 ) ;
if ( ! V_6 )
goto V_66;
V_143 = ( T_20 * ) F_44 ( V_6 , sizeof( T_20 ) ) ;
V_143 -> type = type ;
V_143 -> V_101 = V_101 ;
V_143 -> V_14 = F_6 ( sizeof( T_20 ) ) ;
V_52 = V_19 ? V_19 -> V_51 . V_52 : NULL ;
V_28 = F_56 ( V_6 , V_19 , V_52 ) ;
if ( ! V_28 ) {
F_64 ( V_6 ) ;
goto V_66;
}
V_28 -> V_143 = V_143 ;
V_28 -> V_159 = ( ( T_10 * ) V_143 ) + sizeof( struct V_214 ) ;
if ( F_65 ( type , V_19 ) )
V_28 -> V_215 = 1 ;
V_6 -> V_52 = V_52 ;
return V_28 ;
V_66:
return NULL ;
}
static void F_66 ( struct V_1 * V_2 )
{
F_67 ( ! F_68 ( & V_2 -> V_195 ) ) ;
F_69 ( & V_2 -> V_207 ) ;
F_70 ( V_2 -> V_6 ) ;
F_71 ( V_2 ) ;
F_72 ( V_193 , V_2 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
if ( V_2 -> V_149 )
F_73 ( V_2 -> V_149 ) ;
F_74 ( V_2 ) ;
}
void F_75 ( struct V_1 * V_216 )
{
F_76 ( & V_216 -> V_209 ) ;
}
void F_74 ( struct V_1 * V_216 )
{
if ( F_77 ( & V_216 -> V_209 ) )
F_66 ( V_216 ) ;
}
void * F_7 ( struct V_1 * V_2 , int V_12 , const void * V_156 )
{
void * V_157 ;
void * V_217 ;
int V_158 = F_17 ( V_2 -> V_143 -> V_14 ) ;
int V_218 = F_15 ( V_158 ) - V_158 ;
V_217 = F_44 ( V_2 -> V_6 , V_218 ) ;
V_157 = F_44 ( V_2 -> V_6 , V_12 ) ;
memset ( V_217 , 0 , V_218 ) ;
memcpy ( V_157 , V_156 , V_12 ) ;
V_2 -> V_143 -> V_14 = F_6 ( V_158 + V_218 + V_12 ) ;
V_2 -> V_159 = F_45 ( V_2 -> V_6 ) ;
return V_157 ;
}
void * F_10 ( struct V_1 * V_2 ,
int V_12 , const void * V_156 )
{
if ( F_9 ( V_2 -> V_6 ) >= V_12 )
return F_7 ( V_2 , V_12 , V_156 ) ;
else
return NULL ;
}
int F_78 ( struct V_1 * V_2 , int V_219 , int V_12 ,
struct V_220 * V_156 )
{
T_10 * V_157 ;
int V_11 = 0 ;
V_157 = F_44 ( V_2 -> V_6 , V_12 ) ;
if ( ( V_11 = F_79 ( V_157 , V_156 , V_219 , V_12 ) ) )
goto V_221;
V_2 -> V_143 -> V_14 =
F_6 ( F_17 ( V_2 -> V_143 -> V_14 ) + V_12 ) ;
V_2 -> V_159 = F_45 ( V_2 -> V_6 ) ;
V_221:
return V_11 ;
}
void F_80 ( struct V_1 * V_2 )
{
struct V_222 * V_149 ;
struct V_1 * V_223 ;
struct V_224 * V_107 ;
T_4 V_102 ;
T_4 V_225 ;
if ( V_2 -> V_197 )
return;
V_225 = F_17 ( V_2 -> V_15 . V_115 -> V_107 ) ;
V_107 = & V_2 -> V_19 -> V_226 -> V_221 ;
V_149 = V_2 -> V_149 ;
F_34 (lchunk, &msg->chunks, frag_list) {
if ( V_223 -> V_143 -> V_101 & V_113 ) {
V_102 = 0 ;
} else {
if ( V_223 -> V_143 -> V_101 & V_227 )
V_102 = F_81 ( V_107 , V_225 ) ;
else
V_102 = F_82 ( V_107 , V_225 ) ;
}
V_223 -> V_15 . V_115 -> V_102 = F_6 ( V_102 ) ;
V_223 -> V_197 = 1 ;
}
}
void F_83 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_196 ) {
V_2 -> V_15 . V_115 -> V_106 =
F_13 ( F_84 ( V_2 -> V_19 ) ) ;
V_2 -> V_196 = 1 ;
}
}
struct V_18 * F_85 ( const struct V_228 * V_78 ,
struct V_1 * V_2 ,
T_5 V_22 )
{
struct V_18 * V_19 ;
struct V_191 * V_6 ;
T_21 V_229 ;
struct V_3 * V_4 ;
V_229 = F_86 ( F_62 ( V_2 ) ) ;
V_19 = F_87 ( V_78 , V_78 -> V_51 . V_52 , V_229 , V_22 ) ;
if ( ! V_19 )
goto V_66;
V_19 -> V_230 = 1 ;
V_6 = V_2 -> V_6 ;
V_4 = F_2 ( F_3 ( F_4 ( V_6 ) -> V_7 ) ) ;
if ( F_55 ( ! V_4 ) )
goto V_231;
V_4 -> V_232 ( & V_19 -> V_42 . V_233 , V_6 , 1 ) ;
V_66:
return V_19 ;
V_231:
F_88 ( V_19 ) ;
return NULL ;
}
static T_12 * F_22 ( const struct V_228 * V_78 ,
const struct V_18 * V_19 ,
const struct V_1 * V_234 ,
int * V_76 ,
const T_10 * V_235 , int V_30 )
{
T_12 * V_28 ;
struct V_236 * V_75 ;
struct V_237 V_238 ;
int V_239 , V_240 ;
unsigned int V_241 ;
char * V_242 ;
V_239 = sizeof( T_11 ) +
( sizeof( struct V_236 ) -
sizeof( struct V_243 ) ) ;
V_240 = sizeof( struct V_243 )
+ F_17 ( V_234 -> V_143 -> V_14 ) + V_30 ;
if ( V_240 % V_244 )
V_240 += V_244
- ( V_240 % V_244 ) ;
* V_76 = V_239 + V_240 ;
V_28 = F_89 ( * V_76 , V_194 ) ;
if ( ! V_28 )
goto V_66;
V_75 = (struct V_236 * ) V_28 -> V_245 ;
V_28 -> V_246 . type = V_247 ;
V_28 -> V_246 . V_14 = F_6 ( * V_76 ) ;
V_75 -> V_42 = V_19 -> V_42 ;
V_75 -> V_42 . V_248 = V_30 ;
V_75 -> V_42 . V_82 = V_19 -> V_80 . V_82 ;
V_75 -> V_42 . V_61 = V_19 -> V_80 . V_61 ;
F_90 ( & V_75 -> V_42 . V_249 ) ;
F_91 ( V_19 -> V_250 , V_75 -> V_42 . V_249 ) ;
memcpy ( & V_75 -> V_42 . V_251 [ 0 ] , V_234 -> V_143 ,
F_17 ( V_234 -> V_143 -> V_14 ) ) ;
memcpy ( ( T_10 * ) & V_75 -> V_42 . V_251 [ 0 ] +
F_17 ( V_234 -> V_143 -> V_14 ) , V_235 , V_30 ) ;
if ( F_14 ( V_78 -> V_51 . V_52 ) -> V_185 ) {
struct V_252 V_253 ;
F_92 ( & V_238 , & V_75 -> V_42 , V_240 ) ;
V_241 = V_254 ;
V_242 = ( char * ) V_78 -> V_255 [ V_78 -> V_256 ] ;
V_253 . V_257 = F_14 ( V_78 -> V_51 . V_52 ) -> V_185 ;
V_253 . V_101 = 0 ;
if ( F_93 ( V_253 . V_257 , V_242 , V_241 ) ||
F_94 ( & V_253 , & V_238 , V_240 , V_75 -> V_258 ) )
goto V_259;
}
return V_28 ;
V_259:
F_20 ( V_28 ) ;
V_66:
* V_76 = 0 ;
return NULL ;
}
struct V_18 * F_95 (
const struct V_228 * V_78 ,
const struct V_18 * V_19 ,
struct V_1 * V_2 , T_5 V_22 ,
int * error , struct V_1 * * V_260 )
{
struct V_18 * V_28 = NULL ;
struct V_236 * V_75 ;
struct V_243 * V_261 ;
int V_239 , V_240 , V_262 ;
T_10 * V_263 = V_78 -> V_263 ;
struct V_237 V_238 ;
unsigned int V_241 , V_12 ;
char * V_242 ;
T_21 V_229 ;
struct V_191 * V_6 = V_2 -> V_6 ;
struct V_264 V_265 ;
struct V_252 V_253 ;
V_239 = sizeof( T_20 ) +
( sizeof( struct V_236 ) -
sizeof( struct V_243 ) ) ;
V_240 = F_17 ( V_2 -> V_143 -> V_14 ) - V_239 ;
V_262 = V_239 + sizeof( struct V_243 ) ;
V_12 = F_17 ( V_2 -> V_143 -> V_14 ) ;
if ( V_12 < V_262 + sizeof( struct V_214 ) )
goto V_266;
if ( V_240 % V_244 )
goto V_266;
V_75 = V_2 -> V_15 . V_89 ;
V_261 = & V_75 -> V_42 ;
if ( ! F_14 ( V_78 -> V_51 . V_52 ) -> V_185 )
goto V_267;
V_241 = V_254 ;
F_92 ( & V_238 , V_261 , V_240 ) ;
V_242 = ( char * ) V_78 -> V_255 [ V_78 -> V_256 ] ;
V_253 . V_257 = F_14 ( V_78 -> V_51 . V_52 ) -> V_185 ;
V_253 . V_101 = 0 ;
memset ( V_263 , 0x00 , V_268 ) ;
if ( F_93 ( V_253 . V_257 , V_242 , V_241 ) ||
F_94 ( & V_253 , & V_238 , V_240 , V_263 ) ) {
* error = - V_269 ;
goto V_231;
}
if ( memcmp ( V_263 , V_75 -> V_258 , V_268 ) ) {
V_242 = ( char * ) V_78 -> V_255 [ V_78 -> V_270 ] ;
memset ( V_263 , 0x00 , V_268 ) ;
if ( F_93 ( V_253 . V_257 , V_242 , V_241 ) ||
F_94 ( & V_253 , & V_238 , V_240 , V_263 ) ) {
* error = - V_269 ;
goto V_231;
}
if ( memcmp ( V_263 , V_75 -> V_258 , V_268 ) ) {
* error = - V_271 ;
goto V_231;
}
}
V_267:
if ( F_96 ( V_2 -> V_272 -> V_273 ) != V_261 -> V_43 ) {
* error = - V_274 ;
goto V_231;
}
if ( V_2 -> V_272 -> V_213 != V_261 -> V_233 . V_275 . V_276 ||
F_17 ( V_2 -> V_272 -> V_212 ) != V_261 -> V_277 ) {
* error = - V_278 ;
goto V_231;
}
if ( F_97 ( V_78 -> V_51 . V_52 , V_279 ) )
F_98 ( V_6 , & V_265 ) ;
else
F_90 ( & V_265 ) ;
if ( ! V_19 && F_99 ( V_261 -> V_249 , V_265 ) ) {
V_12 = F_17 ( V_2 -> V_143 -> V_14 ) ;
* V_260 = F_50 ( V_19 , V_2 , V_12 ) ;
if ( * V_260 ) {
T_22 V_280 = ( V_265 . V_281 -
V_261 -> V_249 . V_281 ) * 1000000L +
V_265 . V_282 - V_261 -> V_249 . V_282 ;
T_17 V_283 = F_13 ( V_280 ) ;
F_5 ( * V_260 , V_284 ,
sizeof( V_283 ) ) ;
F_7 ( * V_260 , sizeof( V_283 ) , & V_283 ) ;
* error = - V_285 ;
} else
* error = - V_269 ;
goto V_231;
}
V_229 = F_86 ( F_62 ( V_2 ) ) ;
V_28 = F_87 ( V_78 , V_78 -> V_51 . V_52 , V_229 , V_22 ) ;
if ( ! V_28 ) {
* error = - V_269 ;
goto V_231;
}
V_28 -> V_80 . V_286 = F_17 ( V_2 -> V_272 -> V_213 ) ;
memcpy ( & V_28 -> V_42 , V_261 , sizeof( * V_261 ) ) ;
if ( F_100 ( V_28 , V_261 ,
V_194 ) < 0 ) {
* error = - V_269 ;
goto V_231;
}
if ( F_68 ( & V_28 -> V_51 . V_77 . V_287 ) ) {
F_101 ( & V_28 -> V_51 . V_77 , & V_2 -> V_212 ,
V_288 , V_194 ) ;
}
V_28 -> V_289 = V_28 -> V_42 . V_50 ;
V_28 -> V_290 = V_28 -> V_289 - 1 ;
V_28 -> V_291 = V_28 -> V_42 . V_50 ;
V_28 -> V_292 = V_28 -> V_290 ;
V_28 -> V_80 . V_82 = V_28 -> V_42 . V_82 ;
V_28 -> V_80 . V_61 = V_28 -> V_42 . V_61 ;
return V_28 ;
V_231:
if ( V_28 )
F_88 ( V_28 ) ;
return NULL ;
V_266:
* error = - V_293 ;
goto V_231;
}
static int F_102 ( const struct V_18 * V_19 ,
T_23 V_294 ,
struct V_1 * V_2 ,
struct V_1 * * V_260 )
{
struct V_295 V_296 ;
T_4 V_12 ;
V_12 = F_15 ( sizeof( V_296 ) ) ;
if ( ! * V_260 )
* V_260 = F_50 ( V_19 , V_2 , V_12 ) ;
if ( * V_260 ) {
V_296 . V_297 = F_13 ( 1 ) ;
V_296 . type = V_294 ;
F_5 ( * V_260 , V_298 ,
sizeof( V_296 ) ) ;
F_7 ( * V_260 , sizeof( V_296 ) , & V_296 ) ;
}
return 0 ;
}
static int F_103 ( const struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_1 * * V_260 )
{
if ( ! * V_260 )
* V_260 = F_50 ( V_19 , V_2 , 0 ) ;
if ( * V_260 )
F_5 ( * V_260 , V_299 , 0 ) ;
return 0 ;
}
static int F_104 ( const struct V_18 * V_19 ,
struct V_160 * V_164 ,
const struct V_1 * V_2 ,
struct V_1 * * V_260 )
{
if ( * V_260 )
F_43 ( * V_260 ) ;
* V_260 = F_47 ( V_19 , V_2 , V_164 ) ;
return 0 ;
}
static int F_105 ( const struct V_18 * V_19 ,
union V_25 V_164 ,
struct V_1 * V_2 ,
struct V_1 * * V_260 )
{
T_4 V_12 = F_17 ( V_164 . V_246 -> V_14 ) ;
if ( * V_260 )
F_43 ( * V_260 ) ;
* V_260 = F_50 ( V_19 , V_2 , V_12 ) ;
if ( * V_260 ) {
F_5 ( * V_260 , V_300 , V_12 ) ;
F_7 ( * V_260 , V_12 , V_164 . V_69 ) ;
}
return 0 ;
}
static int F_106 ( union V_25 V_164 )
{
T_4 V_37 = F_17 ( V_164 . V_246 -> V_14 ) - sizeof( T_11 ) ;
int V_301 = 0 ;
int V_302 = 0 ;
int V_303 ;
for ( V_303 = 0 ; V_303 < V_37 ; V_303 ++ ) {
switch ( V_164 . V_304 -> V_305 [ V_303 ] ) {
case V_64 :
V_301 = 1 ;
break;
case V_59 :
case V_60 :
V_302 = 1 ;
break;
}
}
if ( V_306 )
return 1 ;
if ( V_58 && ! V_301 && V_302 )
return 0 ;
return 1 ;
}
static void F_107 ( struct V_18 * V_19 ,
union V_25 V_164 )
{
T_4 V_37 = F_17 ( V_164 . V_246 -> V_14 ) - sizeof( T_11 ) ;
int V_303 ;
for ( V_303 = 0 ; V_303 < V_37 ; V_303 ++ ) {
switch ( V_164 . V_304 -> V_305 [ V_303 ] ) {
case V_307 :
if ( V_56 &&
! V_19 -> V_80 . V_82 )
V_19 -> V_80 . V_82 = 1 ;
break;
case V_64 :
if ( V_62 )
V_19 -> V_80 . V_84 = 1 ;
break;
case V_59 :
case V_60 :
if ( V_58 )
V_19 -> V_80 . V_83 = 1 ;
break;
default:
break;
}
}
}
static T_24 F_108 ( const struct V_18 * V_19 ,
union V_25 V_164 ,
struct V_1 * V_2 ,
struct V_1 * * V_260 )
{
int V_28 = V_308 ;
switch ( V_164 . V_246 -> type & V_309 ) {
case V_310 :
V_28 = V_311 ;
break;
case V_312 :
break;
case V_313 :
V_28 = V_311 ;
case V_314 :
if ( NULL == * V_260 )
* V_260 = F_51 ( V_19 , V_2 ) ;
if ( * V_260 ) {
if ( ! F_8 ( * V_260 , V_315 ,
F_15 ( F_17 ( V_164 . V_246 -> V_14 ) ) ) )
F_10 ( * V_260 ,
F_15 ( F_17 ( V_164 . V_246 -> V_14 ) ) ,
V_164 . V_69 ) ;
} else {
V_28 = V_269 ;
}
break;
default:
break;
}
return V_28 ;
}
static T_24 F_109 ( const struct V_18 * V_19 ,
union V_25 V_164 ,
T_25 V_316 ,
struct V_1 * V_2 ,
struct V_1 * * V_150 )
{
struct V_317 * V_318 ;
int V_28 = V_308 ;
T_4 V_319 , V_320 = 0 ;
int V_303 ;
switch ( V_164 . V_246 -> type ) {
case V_321 :
case V_322 :
case V_323 :
case V_70 :
case V_247 :
case V_168 :
case V_324 :
case V_325 :
case V_72 :
break;
case V_71 :
if ( ! F_106 ( V_164 ) )
return V_326 ;
break;
case V_327 :
if ( V_58 )
break;
goto V_328;
case V_329 :
F_105 ( V_19 , V_164 , V_2 , V_150 ) ;
V_28 = V_326 ;
break;
case V_330 :
if ( V_56 )
break;
goto V_328;
case V_331 :
if ( ! V_62 )
goto V_328;
if ( V_332 !=
F_17 ( V_164 . V_246 -> V_14 ) - sizeof( T_11 ) ) {
F_104 ( V_19 , V_164 . V_246 ,
V_2 , V_150 ) ;
V_28 = V_326 ;
}
break;
case V_333 :
if ( ! V_62 )
goto V_328;
if ( 260 < F_17 ( V_164 . V_246 -> V_14 ) ) {
F_104 ( V_19 , V_164 . V_246 ,
V_2 , V_150 ) ;
V_28 = V_326 ;
}
break;
case V_334 :
if ( ! V_62 )
goto V_328;
V_318 = (struct V_317 * ) V_164 . V_246 ;
V_319 = ( F_17 ( V_164 . V_246 -> V_14 ) - sizeof( T_11 ) ) >> 1 ;
for ( V_303 = 0 ; V_303 < V_319 ; V_303 ++ ) {
V_320 = F_17 ( V_318 -> V_335 [ V_303 ] ) ;
if ( V_320 == V_336 )
break;
}
if ( V_320 != V_336 ) {
F_104 ( V_19 , V_164 . V_246 , V_2 ,
V_150 ) ;
V_28 = V_326 ;
}
break;
V_328:
default:
F_30 ( L_4 ,
F_17 ( V_164 . V_246 -> type ) , V_316 ) ;
V_28 = F_108 ( V_19 , V_164 , V_2 , V_150 ) ;
break;
}
return V_28 ;
}
int F_110 ( const struct V_18 * V_19 ,
T_25 V_316 ,
T_26 * V_251 ,
struct V_1 * V_2 ,
struct V_1 * * V_260 )
{
union V_25 V_164 ;
int V_337 = 0 ;
int V_338 ;
if ( ( 0 == V_251 -> V_67 . V_46 ) ||
( 0 == V_251 -> V_67 . V_48 ) ||
( 0 == V_251 -> V_67 . V_41 ) ||
( V_339 > F_96 ( V_251 -> V_67 . V_44 ) ) ) {
return F_103 ( V_19 , V_2 , V_260 ) ;
}
F_111 (param, peer_init, init_hdr.params) {
if ( V_247 == V_164 . V_246 -> type )
V_337 = 1 ;
}
if ( V_164 . V_69 != ( void * ) V_2 -> V_159 )
return F_104 ( V_19 , V_164 . V_246 , V_2 , V_260 ) ;
if ( ( V_85 == V_316 ) && ! V_337 )
return F_102 ( V_19 , V_247 ,
V_2 , V_260 ) ;
F_111 (param, peer_init, init_hdr.params) {
V_338 = F_109 ( V_19 , V_164 , V_316 , V_2 , V_260 ) ;
switch ( V_338 ) {
case V_326 :
case V_269 :
return 0 ;
case V_311 :
return 1 ;
case V_308 :
default:
break;
}
}
return 1 ;
}
int F_112 ( struct V_18 * V_19 , struct V_1 * V_2 ,
const union V_210 * V_233 ,
T_26 * V_251 , T_5 V_22 )
{
union V_25 V_164 ;
struct V_128 * V_87 ;
struct V_340 * V_341 , * V_230 ;
struct V_3 * V_4 ;
union V_210 V_342 ;
char * V_75 ;
int V_343 = 0 ;
if( ! F_113 ( V_19 , V_233 , V_22 , V_344 ) )
goto V_345;
if ( F_114 ( F_62 ( V_2 ) , V_233 ) )
V_343 = 1 ;
F_111 (param, peer_init, init_hdr.params) {
if ( ! V_343 && ( V_164 . V_246 -> type == V_321 ||
V_164 . V_246 -> type == V_322 ) ) {
V_4 = F_2 ( F_115 ( V_164 . V_246 -> type ) ) ;
V_4 -> V_346 ( & V_342 , V_164 . V_342 ,
V_2 -> V_272 -> V_213 , 0 ) ;
if ( F_114 ( F_62 ( V_2 ) , & V_342 ) )
V_343 = 1 ;
}
if ( ! F_116 ( V_19 , V_164 , V_233 , V_22 ) )
goto V_347;
}
if ( ! V_343 )
goto V_347;
if ( V_19 -> V_80 . V_84 && ( ! V_19 -> V_80 . V_348 ||
! V_19 -> V_80 . V_349 ) )
V_19 -> V_80 . V_84 = 0 ;
if ( ! V_306 &&
( V_19 -> V_80 . V_83 && ! V_19 -> V_80 . V_84 ) ) {
V_19 -> V_80 . V_350 |= ( V_351 |
V_352 |
V_327 ) ;
V_19 -> V_80 . V_83 = 0 ;
goto V_347;
}
F_117 (pos, temp, &asoc->peer.transport_addr_list) {
V_87 = F_118 ( V_341 , struct V_128 , V_353 ) ;
if ( V_87 -> V_354 == V_355 ) {
F_119 ( V_19 , V_87 ) ;
}
}
V_19 -> V_80 . V_303 . V_41 =
F_96 ( V_251 -> V_67 . V_41 ) ;
V_19 -> V_80 . V_303 . V_44 =
F_96 ( V_251 -> V_67 . V_44 ) ;
V_19 -> V_80 . V_303 . V_46 =
F_17 ( V_251 -> V_67 . V_46 ) ;
V_19 -> V_80 . V_303 . V_48 =
F_17 ( V_251 -> V_67 . V_48 ) ;
V_19 -> V_80 . V_303 . V_50 =
F_96 ( V_251 -> V_67 . V_50 ) ;
if ( V_19 -> V_42 . V_47 >
F_17 ( V_251 -> V_67 . V_48 ) ) {
V_19 -> V_42 . V_47 =
F_17 ( V_251 -> V_67 . V_48 ) ;
}
if ( V_19 -> V_42 . V_49 >
F_17 ( V_251 -> V_67 . V_46 ) ) {
V_19 -> V_42 . V_49 =
F_17 ( V_251 -> V_67 . V_46 ) ;
}
V_19 -> V_42 . V_356 = V_19 -> V_80 . V_303 . V_41 ;
V_19 -> V_80 . V_45 = V_19 -> V_80 . V_303 . V_44 ;
V_75 = V_19 -> V_80 . V_75 ;
if ( V_75 ) {
V_19 -> V_80 . V_75 = F_120 ( V_75 , V_19 -> V_80 . V_76 , V_22 ) ;
if ( ! V_19 -> V_80 . V_75 )
goto V_347;
}
F_34 (transport, &asoc->peer.transport_addr_list,
transports) {
V_87 -> V_357 = V_19 -> V_80 . V_303 . V_44 ;
}
if ( ! F_121 ( & V_19 -> V_80 . V_124 , V_358 ,
V_19 -> V_80 . V_303 . V_50 , V_22 ) )
goto V_347;
if ( ! V_19 -> V_230 ) {
int error ;
V_19 -> V_226 = F_122 ( V_19 -> V_42 . V_49 ,
V_19 -> V_42 . V_47 , V_22 ) ;
if ( ! V_19 -> V_226 )
goto V_347;
error = F_123 ( V_19 , V_22 ) ;
if ( error )
goto V_347;
}
V_19 -> V_80 . V_291 = V_19 -> V_80 . V_303 . V_50 - 1 ;
return 1 ;
V_347:
F_117 (pos, temp, &asoc->peer.transport_addr_list) {
V_87 = F_118 ( V_341 , struct V_128 , V_353 ) ;
if ( V_87 -> V_354 != V_344 )
F_119 ( V_19 , V_87 ) ;
}
V_345:
return 0 ;
}
static int F_116 ( struct V_18 * V_19 ,
union V_25 V_164 ,
const union V_210 * V_233 ,
T_5 V_22 )
{
union V_210 V_342 ;
int V_303 ;
T_4 V_33 ;
int V_28 = 1 ;
T_21 V_229 ;
T_27 V_359 ;
struct V_3 * V_4 ;
union V_360 * V_361 ;
struct V_128 * V_362 ;
switch ( V_164 . V_246 -> type ) {
case V_322 :
if ( V_363 != V_19 -> V_51 . V_52 -> V_364 )
break;
goto V_365;
case V_321 :
if ( F_124 ( V_19 -> V_51 . V_52 ) )
break;
V_365:
V_4 = F_2 ( F_115 ( V_164 . V_246 -> type ) ) ;
V_4 -> V_346 ( & V_342 , V_164 . V_342 , F_6 ( V_19 -> V_80 . V_286 ) , 0 ) ;
V_229 = F_86 ( V_233 ) ;
if ( F_125 ( & V_342 , V_229 ) )
if ( ! F_113 ( V_19 , & V_342 , V_22 , V_366 ) )
return 0 ;
break;
case V_323 :
if ( ! V_367 )
break;
V_359 = F_96 ( V_164 . V_368 -> V_369 ) ;
V_19 -> V_250 . V_281 += V_359 / 1000 ;
V_19 -> V_250 . V_282 += ( V_359 % 1000 ) * 1000 ;
break;
case V_329 :
F_30 ( L_5 ) ;
break;
case V_70 :
V_19 -> V_80 . V_370 = 0 ;
V_19 -> V_80 . V_371 = 0 ;
if ( V_233 -> V_372 . V_373 == V_374 )
V_19 -> V_80 . V_371 = 1 ;
else if ( V_233 -> V_372 . V_373 == V_375 )
V_19 -> V_80 . V_370 = 1 ;
V_33 = F_17 ( V_164 . V_246 -> V_14 ) - sizeof( T_11 ) ;
if ( V_33 )
V_33 /= sizeof( T_4 ) ;
for ( V_303 = 0 ; V_303 < V_33 ; ++ V_303 ) {
switch ( V_164 . V_33 -> V_34 [ V_303 ] ) {
case V_321 :
V_19 -> V_80 . V_370 = 1 ;
break;
case V_322 :
if ( V_363 == V_19 -> V_51 . V_52 -> V_364 )
V_19 -> V_80 . V_371 = 1 ;
break;
case V_329 :
V_19 -> V_80 . V_376 = 1 ;
break;
default:
break;
}
}
break;
case V_247 :
V_19 -> V_80 . V_76 =
F_17 ( V_164 . V_246 -> V_14 ) - sizeof( T_11 ) ;
V_19 -> V_80 . V_75 = V_164 . V_75 -> V_245 ;
break;
case V_168 :
break;
case V_324 :
break;
case V_325 :
V_19 -> V_80 . V_81 = 1 ;
break;
case V_72 :
V_19 -> V_80 . V_61 = F_96 ( V_164 . V_377 -> V_61 ) ;
break;
case V_327 :
if ( ! V_58 )
goto V_378;
V_361 = V_164 . V_69 + sizeof( V_379 ) ;
V_4 = F_2 ( F_115 ( V_164 . V_246 -> type ) ) ;
V_4 -> V_346 ( & V_342 , V_361 ,
F_6 ( V_19 -> V_80 . V_286 ) , 0 ) ;
if ( ! V_4 -> V_380 ( & V_342 , NULL , NULL ) )
break;
V_362 = F_126 ( V_19 , & V_342 ) ;
if ( ! V_362 )
break;
F_127 ( V_19 , V_362 ) ;
break;
case V_71 :
F_107 ( V_19 , V_164 ) ;
break;
case V_330 :
if ( V_56 ) {
V_19 -> V_80 . V_82 = 1 ;
break;
}
goto V_378;
case V_331 :
if ( ! V_62 )
goto V_378;
V_19 -> V_80 . V_348 = F_120 ( V_164 . V_246 ,
F_17 ( V_164 . V_246 -> V_14 ) , V_22 ) ;
if ( ! V_19 -> V_80 . V_348 ) {
V_28 = 0 ;
break;
}
break;
case V_334 :
if ( ! V_62 )
goto V_378;
V_19 -> V_80 . V_349 = F_120 ( V_164 . V_246 ,
F_17 ( V_164 . V_246 -> V_14 ) , V_22 ) ;
if ( ! V_19 -> V_80 . V_349 ) {
V_28 = 0 ;
break;
}
F_128 ( V_19 , V_164 . V_381 ) ;
break;
case V_333 :
if ( ! V_62 )
goto V_378;
V_19 -> V_80 . V_382 = F_120 ( V_164 . V_246 ,
F_17 ( V_164 . V_246 -> V_14 ) , V_22 ) ;
if ( ! V_19 -> V_80 . V_382 )
V_28 = 0 ;
break;
V_378:
default:
F_30 ( L_6 ,
F_17 ( V_164 . V_246 -> type ) , V_19 ) ;
break;
}
return V_28 ;
}
T_13 F_129 ( const struct V_228 * V_78 )
{
T_13 V_383 ;
do {
F_130 ( & V_383 , sizeof( T_13 ) ) ;
} while ( V_383 == 0 );
return V_383 ;
}
T_13 F_131 ( const struct V_228 * V_78 )
{
T_13 V_28 ;
F_130 ( & V_28 , sizeof( T_13 ) ) ;
return V_28 ;
}
static struct V_1 * F_132 ( struct V_18 * V_19 ,
union V_210 * V_342 ,
int V_23 )
{
T_28 V_384 ;
struct V_1 * V_28 ;
int V_14 = sizeof( V_384 ) + V_23 ;
union V_360 V_385 ;
int V_386 ;
struct V_3 * V_4 = F_2 ( V_342 -> V_275 . V_387 ) ;
V_386 = V_4 -> V_388 ( V_342 , & V_385 ) ;
if ( ! V_386 )
return NULL ;
V_14 += V_386 ;
V_28 = F_18 ( V_19 , V_59 , 0 , V_14 ) ;
if ( ! V_28 )
return NULL ;
V_384 . V_389 = F_13 ( V_19 -> V_291 ++ ) ;
V_28 -> V_15 . V_390 =
F_7 ( V_28 , sizeof( V_384 ) , & V_384 ) ;
V_28 -> V_68 . V_69 =
F_7 ( V_28 , V_386 , & V_385 ) ;
return V_28 ;
}
struct V_1 * F_133 ( struct V_18 * V_19 ,
union V_210 * V_391 ,
struct V_392 * V_26 ,
int V_393 ,
T_1 V_101 )
{
V_379 V_164 ;
struct V_1 * V_28 ;
union V_360 V_361 ;
union V_210 * V_342 ;
void * V_394 ;
struct V_3 * V_4 ;
int V_395 = sizeof( V_164 ) ;
int V_396 = 0 ;
int V_397 = 0 ;
int V_303 ;
int V_398 = 0 ;
V_394 = V_26 ;
for ( V_303 = 0 ; V_303 < V_393 ; V_303 ++ ) {
V_342 = V_394 ;
V_4 = F_2 ( V_342 -> V_275 . V_387 ) ;
V_396 = V_4 -> V_388 ( V_342 , & V_361 ) ;
V_397 += V_395 ;
V_397 += V_396 ;
V_394 += V_4 -> V_399 ;
if ( V_19 -> V_400 && ! V_398 ) {
V_397 += V_395 ;
V_397 += V_396 ;
V_398 = 1 ;
F_30 ( L_7 , V_397 ) ;
}
}
V_28 = F_132 ( V_19 , V_391 , V_397 ) ;
if ( ! V_28 )
return NULL ;
V_394 = V_26 ;
for ( V_303 = 0 ; V_303 < V_393 ; V_303 ++ ) {
V_342 = V_394 ;
V_4 = F_2 ( V_342 -> V_275 . V_387 ) ;
V_396 = V_4 -> V_388 ( V_342 , & V_361 ) ;
V_164 . V_68 . type = V_101 ;
V_164 . V_68 . V_14 = F_6 ( V_395 + V_396 ) ;
V_164 . V_401 = V_303 ;
F_7 ( V_28 , V_395 , & V_164 ) ;
F_7 ( V_28 , V_396 , & V_361 ) ;
V_394 += V_4 -> V_399 ;
}
if ( V_101 == V_351 && V_398 ) {
V_342 = V_19 -> V_400 ;
V_4 = F_2 ( V_342 -> V_275 . V_387 ) ;
V_396 = V_4 -> V_388 ( V_342 , & V_361 ) ;
V_164 . V_68 . type = V_352 ;
V_164 . V_68 . V_14 = F_6 ( V_395 + V_396 ) ;
V_164 . V_401 = V_303 ;
F_7 ( V_28 , V_395 , & V_164 ) ;
F_7 ( V_28 , V_396 , & V_361 ) ;
}
return V_28 ;
}
struct V_1 * F_134 ( struct V_18 * V_19 ,
union V_210 * V_342 )
{
V_379 V_164 ;
struct V_1 * V_28 ;
int V_12 = sizeof( V_164 ) ;
union V_360 V_385 ;
int V_386 ;
struct V_3 * V_4 = F_2 ( V_342 -> V_275 . V_387 ) ;
V_386 = V_4 -> V_388 ( V_342 , & V_385 ) ;
if ( ! V_386 )
return NULL ;
V_12 += V_386 ;
V_28 = F_132 ( V_19 , V_342 , V_12 ) ;
if ( ! V_28 )
return NULL ;
V_164 . V_68 . type = V_327 ;
V_164 . V_68 . V_14 = F_6 ( V_12 ) ;
V_164 . V_401 = 0 ;
F_7 ( V_28 , sizeof( V_164 ) , & V_164 ) ;
F_7 ( V_28 , V_386 , & V_385 ) ;
return V_28 ;
}
static struct V_1 * F_135 ( const struct V_18 * V_19 ,
T_13 V_389 , int V_23 )
{
T_28 V_384 ;
struct V_1 * V_28 ;
int V_14 = sizeof( V_384 ) + V_23 ;
V_28 = F_18 ( V_19 , V_60 , 0 , V_14 ) ;
if ( ! V_28 )
return NULL ;
V_384 . V_389 = F_13 ( V_389 ) ;
V_28 -> V_15 . V_390 =
F_7 ( V_28 , sizeof( V_384 ) , & V_384 ) ;
return V_28 ;
}
static void F_136 ( struct V_1 * V_2 , T_17 V_401 ,
T_1 V_402 , V_379 * V_403 )
{
V_379 V_404 ;
T_3 V_405 ;
int V_406 = 0 ;
int V_407 = 0 ;
T_1 V_408 ;
if ( V_409 == V_402 ) {
V_408 = V_410 ;
} else {
V_408 = V_411 ;
V_407 = sizeof( V_405 ) ;
if ( V_403 )
V_406 =
F_17 ( V_403 -> V_68 . V_14 ) ;
}
V_404 . V_68 . type = V_408 ;
V_404 . V_68 . V_14 = F_6 ( sizeof( V_404 ) +
V_407 +
V_406 ) ;
V_404 . V_401 = V_401 ;
F_7 ( V_2 , sizeof( V_404 ) , & V_404 ) ;
if ( V_409 == V_402 )
return;
V_405 . V_13 = V_402 ;
V_405 . V_14 = F_6 ( V_407 + V_406 ) ;
F_7 ( V_2 , V_407 , & V_405 ) ;
if ( V_403 )
F_7 ( V_2 , V_406 , V_403 ) ;
}
static T_1 F_137 ( struct V_18 * V_19 ,
struct V_1 * V_384 ,
V_379 * V_403 )
{
struct V_128 * V_80 ;
struct V_3 * V_4 ;
union V_210 V_342 ;
union V_360 * V_361 ;
V_361 = ( void * ) V_403 + sizeof( V_379 ) ;
if ( V_403 -> V_68 . type != V_351 &&
V_403 -> V_68 . type != V_352 &&
V_403 -> V_68 . type != V_327 )
return V_315 ;
switch ( V_361 -> V_246 . type ) {
case V_322 :
if ( ! V_19 -> V_80 . V_371 )
return V_300 ;
break;
case V_321 :
if ( ! V_19 -> V_80 . V_370 )
return V_300 ;
break;
default:
return V_300 ;
}
V_4 = F_2 ( F_115 ( V_361 -> V_246 . type ) ) ;
if ( F_55 ( ! V_4 ) )
return V_300 ;
V_4 -> V_346 ( & V_342 , V_361 , F_6 ( V_19 -> V_80 . V_286 ) , 0 ) ;
if ( ! V_4 -> V_412 ( & V_342 ) && ! V_4 -> V_380 ( & V_342 , NULL , V_384 -> V_6 ) )
return V_300 ;
switch ( V_403 -> V_68 . type ) {
case V_351 :
if ( V_4 -> V_412 ( & V_342 ) )
memcpy ( & V_342 , & V_384 -> V_213 , sizeof( V_342 ) ) ;
V_80 = F_113 ( V_19 , & V_342 , V_194 , V_366 ) ;
if ( ! V_80 )
return V_413 ;
if ( ! F_138 ( & V_80 -> V_414 , F_139 ( V_80 ) ) )
F_140 ( V_80 ) ;
V_19 -> V_415 = V_80 ;
break;
case V_352 :
if ( V_19 -> V_80 . V_416 == 1 )
return V_417 ;
if ( F_114 ( & V_384 -> V_213 , & V_342 ) )
return V_418 ;
if ( V_4 -> V_412 ( & V_342 ) ) {
F_127 ( V_19 , V_384 -> V_87 ) ;
F_141 ( V_19 ,
V_384 -> V_87 ) ;
} else
F_142 ( V_19 , & V_342 ) ;
break;
case V_327 :
if ( V_4 -> V_412 ( & V_342 ) )
memcpy ( & V_342 . V_275 , F_62 ( V_384 ) , sizeof( V_342 ) ) ;
V_80 = F_126 ( V_19 , & V_342 ) ;
if ( ! V_80 )
return V_300 ;
F_127 ( V_19 , V_80 ) ;
break;
}
return V_409 ;
}
int F_143 ( const struct V_18 * V_19 ,
struct V_160 * V_68 , void * V_159 ,
struct V_160 * * V_260 ) {
V_379 * V_403 ;
union V_25 V_164 ;
int V_14 , V_419 ;
V_164 . V_69 = ( T_11 * ) V_68 ;
while ( V_164 . V_69 <= V_159 - sizeof( T_11 ) ) {
V_14 = F_17 ( V_164 . V_246 -> V_14 ) ;
* V_260 = V_164 . V_246 ;
if ( V_164 . V_69 > V_159 - V_14 ||
V_14 < sizeof( T_11 ) )
return 0 ;
switch ( V_164 . V_246 -> type ) {
case V_351 :
case V_352 :
case V_327 :
V_403 = ( V_379 * ) V_164 . V_69 ;
V_419 = F_17 ( V_403 -> V_68 . V_14 ) ;
if ( V_419 < sizeof( V_379 ) +
sizeof( T_11 ) )
return 0 ;
break;
case V_410 :
case V_72 :
if ( V_14 != sizeof( V_379 ) )
return 0 ;
break;
default:
break;
}
V_164 . V_69 += F_15 ( V_14 ) ;
}
if ( V_164 . V_69 != V_159 )
return 0 ;
return 1 ;
}
struct V_1 * F_144 ( struct V_18 * V_19 ,
struct V_1 * V_384 )
{
T_28 * V_420 ;
union V_360 * V_361 ;
V_379 * V_403 ;
struct V_1 * V_421 ;
T_1 V_402 ;
int V_14 = 0 ;
int V_105 ;
T_13 V_389 ;
int V_422 = 1 ;
V_105 = F_17 ( V_384 -> V_143 -> V_14 ) - sizeof( T_20 ) ;
V_420 = ( T_28 * ) V_384 -> V_6 -> V_156 ;
V_389 = F_96 ( V_420 -> V_389 ) ;
V_14 = sizeof( T_28 ) ;
V_361 = (union V_360 * ) ( V_384 -> V_6 -> V_156 + V_14 ) ;
V_105 -= V_14 ;
V_14 = F_17 ( V_361 -> V_246 . V_14 ) ;
V_403 = ( void * ) V_361 + V_14 ;
V_105 -= V_14 ;
V_421 = F_135 ( V_19 , V_389 , V_105 * 4 ) ;
if ( ! V_421 )
goto V_423;
while ( V_105 > 0 ) {
V_402 = F_137 ( V_19 , V_384 ,
V_403 ) ;
if ( V_409 != V_402 )
V_422 = 0 ;
if ( ! V_422 )
F_136 ( V_421 ,
V_403 -> V_401 , V_402 ,
V_403 ) ;
if ( V_413 == V_402 )
goto V_423;
V_14 = F_17 ( V_403 -> V_68 . V_14 ) ;
V_403 = ( void * ) V_403 + V_14 ;
V_105 -= V_14 ;
}
V_423:
V_19 -> V_80 . V_291 ++ ;
if ( V_421 ) {
F_75 ( V_421 ) ;
F_145 ( & V_421 -> V_207 ,
& V_19 -> V_424 ) ;
}
return V_421 ;
}
static void F_146 ( struct V_18 * V_19 ,
V_379 * V_403 )
{
struct V_3 * V_4 ;
union V_210 V_342 ;
struct V_20 * V_21 = & V_19 -> V_51 . V_77 ;
union V_360 * V_361 ;
struct V_128 * V_87 ;
struct V_425 * V_426 ;
V_361 = ( void * ) V_403 + sizeof( V_379 ) ;
V_4 = F_2 ( F_115 ( V_361 -> V_246 . type ) ) ;
V_4 -> V_346 ( & V_342 , V_361 , F_6 ( V_21 -> V_286 ) , 0 ) ;
switch ( V_403 -> V_68 . type ) {
case V_351 :
F_147 () ;
F_34 (saddr, &bp->address_list, list) {
if ( F_114 ( & V_426 -> V_427 , & V_342 ) )
V_426 -> V_354 = V_288 ;
}
F_148 () ;
F_34 (transport, &asoc->peer.transport_addr_list,
transports) {
F_149 ( V_87 -> V_428 ) ;
V_87 -> V_428 = NULL ;
}
break;
case V_352 :
F_147 () ;
F_150 ( V_21 , & V_342 ) ;
if ( V_19 -> V_400 != NULL &&
F_114 ( V_19 -> V_400 , & V_342 ) ) {
F_20 ( V_19 -> V_400 ) ;
V_19 -> V_400 = NULL ;
}
F_148 () ;
F_34 (transport, &asoc->peer.transport_addr_list,
transports) {
F_149 ( V_87 -> V_428 ) ;
V_87 -> V_428 = NULL ;
}
break;
default:
break;
}
}
static T_1 F_151 ( struct V_1 * V_421 ,
V_379 * V_403 ,
int V_429 )
{
V_379 * V_430 ;
T_3 * V_405 ;
int V_14 ;
int V_431 ;
T_1 V_402 ;
if ( V_429 )
V_402 = V_409 ;
else
V_402 = V_432 ;
V_431 = F_17 ( V_421 -> V_143 -> V_14 ) -
sizeof( T_20 ) ;
V_14 = sizeof( T_28 ) ;
V_430 = ( V_379 * ) ( V_421 -> V_6 -> V_156 +
V_14 ) ;
V_431 -= V_14 ;
while ( V_431 > 0 ) {
if ( V_430 -> V_401 == V_403 -> V_401 ) {
switch( V_430 -> V_68 . type ) {
case V_410 :
return V_409 ;
case V_411 :
V_14 = sizeof( V_379 ) ;
V_405 = ( void * ) V_430 + V_14 ;
V_431 -= V_14 ;
if ( V_431 > 0 )
return V_405 -> V_13 ;
else
return V_299 ;
break;
default:
return V_299 ;
}
}
V_14 = F_17 ( V_430 -> V_68 . V_14 ) ;
V_430 = ( void * ) V_430 + V_14 ;
V_431 -= V_14 ;
}
return V_402 ;
}
int F_152 ( struct V_18 * V_19 ,
struct V_1 * V_421 )
{
struct V_1 * V_384 = V_19 -> V_433 ;
union V_360 * V_361 ;
V_379 * V_403 ;
int V_14 = 0 ;
int V_434 = V_384 -> V_6 -> V_12 ;
int V_422 = 0 ;
int V_429 = 1 ;
int V_28 = 0 ;
T_1 V_402 = V_409 ;
V_14 = sizeof( V_435 ) ;
V_361 = (union V_360 * ) ( V_384 -> V_6 -> V_156 + V_14 ) ;
V_434 -= V_14 ;
V_14 = F_17 ( V_361 -> V_246 . V_14 ) ;
V_403 = ( void * ) V_361 + V_14 ;
V_434 -= V_14 ;
if ( V_421 -> V_6 -> V_12 == sizeof( T_28 ) )
V_422 = 1 ;
while ( V_434 > 0 ) {
if ( V_422 )
V_402 = V_409 ;
else {
V_402 = F_151 ( V_421 ,
V_403 ,
V_429 ) ;
if ( V_429 && ( V_409 != V_402 ) )
V_429 = 0 ;
}
switch ( V_402 ) {
case V_409 :
F_146 ( V_19 , V_403 ) ;
break;
case V_413 :
V_28 = 1 ;
break;
case V_315 :
V_19 -> V_80 . V_350 |=
V_403 -> V_68 . type ;
break;
case V_432 :
case V_417 :
case V_418 :
default:
break;
}
V_14 = F_17 ( V_403 -> V_68 . V_14 ) ;
V_403 = ( void * ) V_403 + V_14 ;
V_434 -= V_14 ;
}
if ( V_429 && V_19 -> V_436 ) {
V_19 -> V_436 = 0 ;
F_153 ( V_19 -> V_80 . V_437 ) ;
}
F_69 ( & V_384 -> V_207 ) ;
F_43 ( V_384 ) ;
V_19 -> V_433 = NULL ;
return V_28 ;
}
struct V_1 * F_154 ( const struct V_18 * V_19 ,
T_13 V_438 , T_2 V_439 ,
struct V_440 * V_441 )
{
struct V_1 * V_28 = NULL ;
struct V_442 V_443 ;
struct V_440 V_444 ;
T_2 V_142 ;
int V_303 ;
V_142 = ( V_439 + 1 ) * sizeof( T_13 ) ;
V_28 = F_18 ( V_19 , V_307 , 0 , V_142 ) ;
if ( ! V_28 )
return NULL ;
V_443 . V_438 = F_13 ( V_438 ) ;
V_28 -> V_15 . V_445 =
F_7 ( V_28 , sizeof( V_443 ) , & V_443 ) ;
for ( V_303 = 0 ; V_303 < V_439 ; V_303 ++ ) {
V_444 . V_107 = V_441 [ V_303 ] . V_107 ;
V_444 . V_102 = V_441 [ V_303 ] . V_102 ;
F_7 ( V_28 , sizeof( V_444 ) , & V_444 ) ;
}
return V_28 ;
}

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
struct V_10 * V_11 ;
int V_12 = 0 ;
V_11 = F_4 ( F_5 ( F_6 ( V_4 -> V_2 ) -> V_13 ) ) ;
if ( V_11 )
V_12 = V_11 -> V_14 ( V_4 -> V_2 ) ;
return V_12 ;
}
void F_7 ( struct V_3 * V_4 , T_1 V_15 ,
T_2 V_16 )
{
T_3 V_17 ;
T_4 V_18 ;
V_17 . V_19 = V_15 ;
V_18 = sizeof( T_3 ) + V_16 ;
V_17 . V_20 = F_8 ( V_18 ) ;
V_4 -> V_21 . V_22 = F_9 ( V_4 , sizeof( T_3 ) , & V_17 ) ;
}
static int F_10 ( struct V_3 * V_4 , T_1 V_15 ,
T_2 V_16 )
{
T_3 V_17 ;
T_4 V_18 ;
V_17 . V_19 = V_15 ;
V_18 = sizeof( T_3 ) + V_16 ;
V_17 . V_20 = F_8 ( V_18 ) ;
if ( F_11 ( V_4 -> V_2 ) < V_18 )
return - V_23 ;
V_4 -> V_21 . V_22 = F_12 ( V_4 ,
sizeof( T_3 ) ,
& V_17 ) ;
return 0 ;
}
struct V_3 * F_13 ( const struct V_5 * V_6 ,
const struct V_24 * V_25 ,
T_5 V_26 , int V_27 )
{
struct V_28 * V_28 = F_14 ( V_6 -> V_8 . V_7 ) ;
struct V_29 * V_30 = V_6 -> V_30 ;
T_6 V_31 ;
union V_32 V_33 ;
T_2 V_34 ;
struct V_3 * V_35 = NULL ;
int V_36 , V_37 = 0 ;
struct V_38 * V_39 ;
T_7 V_40 ;
T_1 V_41 [ 2 ] ;
T_8 V_42 ;
T_9 V_43 ;
int V_44 = 0 ;
T_10 V_45 [ 3 ] ;
T_11 * V_46 = NULL ,
* V_47 = NULL ;
V_35 = NULL ;
V_33 = F_15 ( V_25 , & V_37 , V_26 ) ;
V_31 . V_48 = F_16 ( V_6 -> V_49 . V_50 ) ;
V_31 . V_51 = F_16 ( V_6 -> V_52 ) ;
V_31 . V_53 = F_8 ( V_6 -> V_49 . V_54 ) ;
V_31 . V_55 = F_8 ( V_6 -> V_49 . V_56 ) ;
V_31 . V_57 = F_16 ( V_6 -> V_49 . V_57 ) ;
V_39 = F_17 ( V_6 -> V_8 . V_7 ) ;
V_36 = V_39 -> V_58 -> V_59 ( V_39 , V_41 ) ;
V_34 = sizeof( V_31 ) + V_37 ;
V_34 += F_18 ( F_19 ( V_36 ) ) ;
V_34 += sizeof( V_60 ) ;
if ( V_28 -> V_61 . V_62 )
V_34 += sizeof( V_63 ) ;
if ( V_28 -> V_61 . V_64 ) {
V_45 [ V_44 ] = V_65 ;
V_45 [ V_44 + 1 ] = V_66 ;
V_44 += 2 ;
}
if ( V_39 -> V_67 )
V_34 += sizeof( V_42 ) ;
V_34 += V_27 ;
if ( V_30 -> V_68 ) {
V_34 += sizeof( V_6 -> V_49 . V_69 ) ;
V_47 = ( T_11 * ) V_6 -> V_49 . V_47 ;
if ( V_47 -> V_20 )
V_34 += F_18 ( F_20 ( V_47 -> V_20 ) ) ;
else
V_47 = NULL ;
V_46 = ( T_11 * ) V_6 -> V_49 . V_46 ;
if ( V_46 -> V_20 )
V_34 += F_18 ( F_20 ( V_46 -> V_20 ) ) ;
else
V_46 = NULL ;
V_45 [ V_44 ] = V_70 ;
V_44 += 1 ;
}
if ( V_44 )
V_34 += F_18 ( sizeof( T_9 ) +
V_44 ) ;
V_35 = F_21 ( V_6 , V_71 , 0 , V_34 ) ;
if ( ! V_35 )
goto V_72;
V_35 -> V_21 . V_73 =
F_9 ( V_35 , sizeof( V_31 ) , & V_31 ) ;
V_35 -> V_74 . V_75 =
F_9 ( V_35 , V_37 , V_33 . V_75 ) ;
V_40 . V_74 . type = V_76 ;
V_40 . V_74 . V_20 = F_8 ( F_19 ( V_36 ) ) ;
F_9 ( V_35 , sizeof( V_40 ) , & V_40 ) ;
F_9 ( V_35 , V_36 * sizeof( T_4 ) , & V_41 ) ;
F_9 ( V_35 , sizeof( V_60 ) , & V_60 ) ;
if ( V_44 ) {
V_43 . V_74 . type = V_77 ;
V_43 . V_74 . V_20 =
F_8 ( sizeof( T_9 ) + V_44 ) ;
F_9 ( V_35 , sizeof( T_9 ) ,
& V_43 ) ;
F_22 ( V_35 , V_44 , V_45 ) ;
}
if ( V_28 -> V_61 . V_62 )
F_9 ( V_35 , sizeof( V_63 ) , & V_63 ) ;
if ( V_39 -> V_67 ) {
V_42 . V_74 . type = V_78 ;
V_42 . V_74 . V_20 = F_8 ( sizeof( V_42 ) ) ;
V_42 . V_67 = F_16 ( V_39 -> V_67 ) ;
F_9 ( V_35 , sizeof( V_42 ) , & V_42 ) ;
}
if ( V_30 -> V_68 ) {
F_9 ( V_35 , sizeof( V_6 -> V_49 . V_69 ) ,
V_6 -> V_49 . V_69 ) ;
if ( V_47 )
F_9 ( V_35 , F_20 ( V_47 -> V_20 ) ,
V_47 ) ;
if ( V_46 )
F_9 ( V_35 , F_20 ( V_46 -> V_20 ) ,
V_46 ) ;
}
V_72:
F_23 ( V_33 . V_75 ) ;
return V_35 ;
}
struct V_3 * F_24 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
T_5 V_26 , int V_79 )
{
T_6 V_80 ;
struct V_3 * V_35 ;
union V_32 V_33 ;
struct V_38 * V_39 ;
int V_37 ;
T_12 * V_81 ;
int V_82 ;
T_2 V_34 ;
T_8 V_42 ;
T_9 V_43 ;
int V_44 = 0 ;
T_10 V_45 [ 3 ] ;
T_11 * V_46 = NULL ,
* V_47 = NULL ,
* V_69 = NULL ;
V_35 = NULL ;
V_33 = F_15 ( & V_6 -> V_8 . V_83 , & V_37 , V_26 ) ;
V_80 . V_48 = F_16 ( V_6 -> V_49 . V_50 ) ;
V_80 . V_51 = F_16 ( V_6 -> V_52 ) ;
V_80 . V_53 = F_8 ( V_6 -> V_49 . V_54 ) ;
V_80 . V_55 = F_8 ( V_6 -> V_49 . V_56 ) ;
V_80 . V_57 = F_16 ( V_6 -> V_49 . V_57 ) ;
V_81 = F_25 ( V_6 -> V_30 , V_6 , V_4 , & V_82 ,
V_33 . V_75 , V_37 ) ;
if ( ! V_81 )
goto V_84;
V_39 = F_17 ( V_6 -> V_8 . V_7 ) ;
V_34 = sizeof( V_80 ) + V_37 + V_82 + V_79 ;
if ( V_6 -> V_85 . V_86 )
V_34 += sizeof( V_60 ) ;
if ( V_6 -> V_85 . V_87 )
V_34 += sizeof( V_63 ) ;
if ( V_6 -> V_85 . V_88 ) {
V_45 [ V_44 ] = V_65 ;
V_45 [ V_44 + 1 ] = V_66 ;
V_44 += 2 ;
}
if ( V_39 -> V_67 )
V_34 += sizeof( V_42 ) ;
if ( V_6 -> V_85 . V_89 ) {
V_69 = ( T_11 * ) V_6 -> V_49 . V_69 ;
V_34 += F_20 ( V_69 -> V_20 ) ;
V_47 = ( T_11 * ) V_6 -> V_49 . V_47 ;
if ( V_47 -> V_20 )
V_34 += F_18 ( F_20 ( V_47 -> V_20 ) ) ;
else
V_47 = NULL ;
V_46 = ( T_11 * ) V_6 -> V_49 . V_46 ;
if ( V_46 -> V_20 )
V_34 += F_18 ( F_20 ( V_46 -> V_20 ) ) ;
else
V_46 = NULL ;
V_45 [ V_44 ] = V_70 ;
V_44 += 1 ;
}
if ( V_44 )
V_34 += F_18 ( sizeof( T_9 ) +
V_44 ) ;
V_35 = F_21 ( V_6 , V_90 , 0 , V_34 ) ;
if ( ! V_35 )
goto V_91;
V_35 -> V_92 = V_4 -> V_92 ;
V_35 -> V_21 . V_73 =
F_9 ( V_35 , sizeof( V_80 ) , & V_80 ) ;
V_35 -> V_74 . V_75 = F_9 ( V_35 , V_37 , V_33 . V_75 ) ;
F_9 ( V_35 , V_82 , V_81 ) ;
if ( V_6 -> V_85 . V_86 )
F_9 ( V_35 , sizeof( V_60 ) , & V_60 ) ;
if ( V_44 ) {
V_43 . V_74 . type = V_77 ;
V_43 . V_74 . V_20 =
F_8 ( sizeof( T_9 ) + V_44 ) ;
F_9 ( V_35 , sizeof( T_9 ) ,
& V_43 ) ;
F_22 ( V_35 , V_44 , V_45 ) ;
}
if ( V_6 -> V_85 . V_87 )
F_9 ( V_35 , sizeof( V_63 ) , & V_63 ) ;
if ( V_39 -> V_67 ) {
V_42 . V_74 . type = V_78 ;
V_42 . V_74 . V_20 = F_8 ( sizeof( V_42 ) ) ;
V_42 . V_67 = F_16 ( V_39 -> V_67 ) ;
F_9 ( V_35 , sizeof( V_42 ) , & V_42 ) ;
}
if ( V_6 -> V_85 . V_89 ) {
F_9 ( V_35 , F_20 ( V_69 -> V_20 ) ,
V_69 ) ;
if ( V_47 )
F_9 ( V_35 , F_20 ( V_47 -> V_20 ) ,
V_47 ) ;
if ( V_46 )
F_9 ( V_35 , F_20 ( V_46 -> V_20 ) ,
V_46 ) ;
}
V_35 -> V_6 = (struct V_5 * ) V_6 ;
V_91:
F_23 ( V_81 ) ;
V_84:
F_23 ( V_33 . V_75 ) ;
return V_35 ;
}
struct V_3 * F_26 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_35 ;
void * V_81 ;
int V_82 ;
V_81 = V_6 -> V_85 . V_81 ;
V_82 = V_6 -> V_85 . V_82 ;
V_35 = F_21 ( V_6 , V_93 , 0 , V_82 ) ;
if ( ! V_35 )
goto V_72;
V_35 -> V_21 . V_94 =
F_9 ( V_35 , V_82 , V_81 ) ;
if ( V_4 )
V_35 -> V_92 = V_4 -> V_92 ;
V_72:
return V_35 ;
}
struct V_3 * F_27 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_35 ;
V_35 = F_21 ( V_6 , V_95 , 0 , 0 ) ;
if ( V_35 && V_4 )
V_35 -> V_92 = V_4 -> V_92 ;
return V_35 ;
}
struct V_3 * F_28 ( const struct V_5 * V_6 ,
const T_13 V_96 ,
const struct V_3 * V_4 )
{
struct V_3 * V_35 ;
T_14 V_97 ;
V_97 . V_96 = F_16 ( V_96 ) ;
V_35 = F_21 ( V_6 , V_98 , 0 ,
sizeof( T_14 ) ) ;
if ( ! V_35 )
goto V_72;
V_35 -> V_21 . V_99 =
F_9 ( V_35 , sizeof( V_97 ) , & V_97 ) ;
if ( V_4 )
V_35 -> V_92 = V_4 -> V_92 ;
V_72:
return V_35 ;
}
struct V_3 * F_29 ( const struct V_5 * V_6 ,
const T_13 V_96 )
{
struct V_3 * V_35 ;
T_15 V_100 ;
V_100 . V_96 = F_16 ( V_96 ) ;
V_35 = F_21 ( V_6 , V_101 , 0 ,
sizeof( T_15 ) ) ;
if ( ! V_35 )
goto V_72;
V_35 -> V_21 . V_102 =
F_9 ( V_35 , sizeof( V_100 ) , & V_100 ) ;
V_72:
return V_35 ;
}
struct V_3 * F_30 ( struct V_5 * V_6 ,
const struct V_103 * V_104 ,
int V_105 , T_10 V_106 , T_4 V_107 )
{
struct V_3 * V_35 ;
struct V_108 V_109 ;
int V_110 ;
V_109 . V_111 = 0 ;
V_109 . V_112 = F_8 ( V_104 -> V_113 ) ;
V_109 . V_114 = V_104 -> V_115 ;
if ( V_104 -> V_116 & V_117 ) {
V_106 |= V_118 ;
V_109 . V_107 = 0 ;
} else
V_109 . V_107 = F_8 ( V_107 ) ;
V_110 = sizeof( V_109 ) + V_105 ;
V_35 = F_31 ( V_6 , V_106 , V_110 ) ;
if ( ! V_35 )
goto V_72;
V_35 -> V_21 . V_119 = F_9 ( V_35 , sizeof( V_109 ) , & V_109 ) ;
memcpy ( & V_35 -> V_104 , V_104 , sizeof( struct V_103 ) ) ;
V_72:
return V_35 ;
}
struct V_3 * F_32 ( const struct V_5 * V_6 )
{
struct V_3 * V_35 ;
struct V_120 V_121 ;
int V_18 ;
T_13 V_122 ;
T_4 V_123 , V_124 ;
struct V_5 * V_125 = (struct V_5 * ) V_6 ;
struct V_126 * V_127 = (struct V_126 * ) & V_6 -> V_85 . V_128 ;
struct V_129 V_130 [ V_131 ] ;
struct V_132 * V_133 ;
memset ( V_130 , 0 , sizeof( V_130 ) ) ;
V_122 = F_33 ( V_127 ) ;
F_34 ( L_1 , V_134 , V_122 ) ;
V_123 = F_35 ( V_127 , V_130 ) ;
V_124 = F_36 ( V_127 ) ;
V_121 . V_135 = F_16 ( V_122 ) ;
V_121 . V_51 = F_16 ( V_6 -> V_51 ) ;
V_121 . V_136 = F_8 ( V_123 ) ;
V_121 . V_124 = F_8 ( V_124 ) ;
V_18 = sizeof( V_121 )
+ sizeof( struct V_129 ) * V_123
+ sizeof( T_13 ) * V_124 ;
V_35 = F_21 ( V_6 , V_137 , 0 , V_18 ) ;
if ( ! V_35 )
goto V_72;
V_35 -> V_92 = V_6 -> V_85 . V_138 ;
V_35 -> V_21 . V_139 =
F_9 ( V_35 , sizeof( V_121 ) , & V_121 ) ;
if ( V_123 )
F_9 ( V_35 , sizeof( T_13 ) * V_123 ,
V_130 ) ;
if ( V_124 ) {
V_125 -> V_140 . V_141 += V_124 ;
F_9 ( V_35 , sizeof( T_13 ) * V_124 ,
F_37 ( V_127 ) ) ;
}
if ( ++ V_125 -> V_85 . V_142 == 0 ) {
F_38 (trans, &asoc->peer.transport_addr_list,
transports)
V_133 -> V_142 = 0 ;
V_125 -> V_85 . V_142 = 1 ;
}
V_72:
return V_35 ;
}
struct V_3 * F_39 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_35 ;
T_16 V_143 ;
T_13 V_122 ;
V_122 = F_33 ( & V_6 -> V_85 . V_128 ) ;
V_143 . V_135 = F_16 ( V_122 ) ;
V_35 = F_21 ( V_6 , V_144 , 0 ,
sizeof( T_16 ) ) ;
if ( ! V_35 )
goto V_72;
V_35 -> V_21 . V_145 =
F_9 ( V_35 , sizeof( V_143 ) , & V_143 ) ;
if ( V_4 )
V_35 -> V_92 = V_4 -> V_92 ;
V_72:
return V_35 ;
}
struct V_3 * F_40 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_35 ;
V_35 = F_21 ( V_6 , V_146 , 0 , 0 ) ;
if ( V_35 && V_4 )
V_35 -> V_92 = V_4 -> V_92 ;
return V_35 ;
}
struct V_3 * F_41 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_35 ;
T_10 V_106 = 0 ;
V_106 |= V_6 ? 0 : V_147 ;
V_35 = F_21 ( V_6 , V_148 , V_106 , 0 ) ;
if ( V_35 && V_4 )
V_35 -> V_92 = V_4 -> V_92 ;
return V_35 ;
}
struct V_3 * F_42 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
const T_2 V_149 )
{
struct V_3 * V_35 ;
T_10 V_106 = 0 ;
if ( ! V_6 ) {
if ( V_4 && V_4 -> V_150 &&
V_4 -> V_150 -> type == V_71 )
V_106 = 0 ;
else
V_106 = V_147 ;
}
V_35 = F_21 ( V_6 , V_151 , V_106 , V_149 ) ;
if ( V_35 && V_4 )
V_35 -> V_92 = V_4 -> V_92 ;
return V_35 ;
}
struct V_3 * F_43 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 , T_13 V_111 )
{
struct V_3 * V_35 ;
T_17 V_152 ;
V_35 = F_42 ( V_6 , V_4 , sizeof( T_3 )
+ sizeof( V_111 ) ) ;
if ( ! V_35 )
goto V_153;
V_152 = F_16 ( V_111 ) ;
F_7 ( V_35 , V_154 , sizeof( V_152 ) ) ;
F_9 ( V_35 , sizeof( V_152 ) , ( const void * ) & V_152 ) ;
if ( V_4 )
V_35 -> V_92 = V_4 -> V_92 ;
V_153:
return V_35 ;
}
struct V_3 * F_44 ( const struct V_5 * V_6 ,
const struct V_155 * V_156 ,
T_2 V_16 )
{
struct V_3 * V_35 ;
void * V_152 = NULL ;
int V_17 ;
V_35 = F_42 ( V_6 , NULL , sizeof( T_3 ) + V_16 ) ;
if ( ! V_35 )
goto V_157;
if ( V_16 ) {
V_152 = F_45 ( V_16 , V_158 ) ;
if ( ! V_152 )
goto V_159;
V_17 = F_46 ( V_152 , V_156 -> V_160 , V_16 ) ;
if ( V_17 < 0 )
goto V_161;
}
F_7 ( V_35 , V_162 , V_16 ) ;
F_9 ( V_35 , V_16 , V_152 ) ;
if ( V_16 )
F_23 ( V_152 ) ;
return V_35 ;
V_161:
F_23 ( V_152 ) ;
V_159:
F_47 ( V_35 ) ;
V_35 = NULL ;
V_157:
return V_35 ;
}
static void * F_22 ( struct V_3 * V_4 , int V_18 ,
const void * V_163 )
{
void * V_164 ;
int V_165 = F_20 ( V_4 -> V_150 -> V_20 ) ;
V_164 = F_48 ( V_4 -> V_2 , V_18 ) ;
if ( V_163 )
memcpy ( V_164 , V_163 , V_18 ) ;
else
memset ( V_164 , 0 , V_18 ) ;
V_4 -> V_150 -> V_20 = F_8 ( V_165 + V_18 ) ;
V_4 -> V_166 = F_49 ( V_4 -> V_2 ) ;
return V_164 ;
}
struct V_3 * F_50 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
const T_10 * V_152 ,
const T_2 V_16 )
{
struct V_3 * V_35 ;
struct V_167 V_168 ;
V_35 = F_42 ( V_6 , V_4 , sizeof( T_3 ) + V_16
+ sizeof( T_11 ) ) ;
if ( ! V_35 )
goto V_169;
F_7 ( V_35 , V_170 , V_16
+ sizeof( T_11 ) ) ;
V_168 . type = F_8 ( V_4 -> V_150 -> type ) ;
V_168 . V_20 = V_4 -> V_150 -> V_20 ;
F_9 ( V_35 , V_16 , V_152 ) ;
F_22 ( V_35 , sizeof( T_11 ) , & V_168 ) ;
V_169:
return V_35 ;
}
struct V_3 * F_51 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
struct V_167 * V_171 )
{
struct V_3 * V_35 ;
static const char error [] = L_2 ;
T_2 V_172 = sizeof( error ) + sizeof( T_3 ) +
sizeof( T_11 ) ;
V_35 = F_42 ( V_6 , V_4 , V_172 ) ;
if ( ! V_35 )
goto V_72;
F_7 ( V_35 , V_170 ,
sizeof( error ) + sizeof( T_11 ) ) ;
F_9 ( V_35 , sizeof( error ) , error ) ;
F_22 ( V_35 , sizeof( T_11 ) , V_171 ) ;
V_72:
return V_35 ;
}
struct V_3 * F_52 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_35 ;
static const char error [] = L_3 ;
T_2 V_172 = sizeof( error ) + sizeof( T_3 ) ;
V_35 = F_42 ( V_6 , V_4 , V_172 ) ;
if ( ! V_35 )
goto V_72;
F_7 ( V_35 , V_170 , sizeof( error ) ) ;
F_9 ( V_35 , sizeof( error ) , error ) ;
V_72:
return V_35 ;
}
struct V_3 * F_53 ( const struct V_5 * V_6 ,
const struct V_132 * V_92 )
{
struct V_3 * V_35 ;
T_18 V_173 ;
V_35 = F_21 ( V_6 , V_174 , 0 , sizeof( V_173 ) ) ;
if ( ! V_35 )
goto V_72;
V_173 . V_74 . type = V_175 ;
V_173 . V_74 . V_20 = F_8 ( sizeof( T_18 ) ) ;
V_173 . V_176 = V_92 -> V_177 ;
V_173 . V_178 = V_179 ;
V_173 . V_180 = V_92 -> V_180 ;
V_35 -> V_92 = (struct V_132 * ) V_92 ;
V_35 -> V_21 . V_181 = F_9 ( V_35 , sizeof( V_173 ) ,
& V_173 ) ;
V_72:
return V_35 ;
}
struct V_3 * F_54 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
const void * V_152 , const T_2 V_16 )
{
struct V_3 * V_35 ;
V_35 = F_21 ( V_6 , V_182 , 0 , V_16 ) ;
if ( ! V_35 )
goto V_72;
V_35 -> V_21 . V_181 = F_9 ( V_35 , V_16 , V_152 ) ;
if ( V_4 )
V_35 -> V_92 = V_4 -> V_92 ;
V_72:
return V_35 ;
}
static struct V_3 * F_55 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
T_2 V_183 )
{
struct V_3 * V_35 ;
V_35 = F_21 ( V_6 , V_184 , 0 ,
sizeof( T_3 ) + V_183 ) ;
if ( ! V_35 )
goto V_72;
if ( V_4 )
V_35 -> V_92 = V_4 -> V_92 ;
V_72:
return V_35 ;
}
static inline struct V_3 * F_56 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
T_2 V_183 = V_6 ? V_6 -> V_185 : 0 ;
if ( ! V_183 )
V_183 = V_186 ;
return F_55 ( V_6 , V_4 , V_183 ) ;
}
struct V_3 * F_57 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
T_1 V_15 , const void * V_152 ,
T_2 V_16 , T_2 V_187 )
{
struct V_3 * V_35 ;
V_35 = F_55 ( V_6 , V_4 , V_16 + V_187 ) ;
if ( ! V_35 )
goto V_72;
F_7 ( V_35 , V_15 , V_16 + V_187 ) ;
F_9 ( V_35 , V_16 , V_152 ) ;
if ( V_187 )
F_22 ( V_35 , V_187 , NULL ) ;
V_72:
return V_35 ;
}
struct V_3 * F_58 ( const struct V_5 * V_6 )
{
struct V_3 * V_35 ;
struct V_188 * V_189 ;
struct V_190 V_191 ;
T_10 * V_192 ;
V_189 = F_59 ( V_6 ) ;
if ( F_60 ( ! V_189 ) )
return NULL ;
V_35 = F_21 ( V_6 , V_70 , 0 ,
V_189 -> V_193 + sizeof( V_194 ) ) ;
if ( ! V_35 )
return NULL ;
V_191 . V_195 = F_8 ( V_189 -> V_195 ) ;
V_191 . V_196 = F_8 ( V_6 -> V_197 ) ;
V_35 -> V_21 . V_191 = F_9 ( V_35 , sizeof( V_194 ) ,
& V_191 ) ;
V_192 = F_48 ( V_35 -> V_2 , V_189 -> V_193 ) ;
memset ( V_192 , 0 , V_189 -> V_193 ) ;
V_35 -> V_150 -> V_20 =
F_8 ( F_20 ( V_35 -> V_150 -> V_20 ) + V_189 -> V_193 ) ;
V_35 -> V_166 = F_49 ( V_35 -> V_2 ) ;
return V_35 ;
}
struct V_3 * F_61 ( struct V_1 * V_2 ,
const struct V_5 * V_6 ,
struct V_198 * V_7 )
{
struct V_3 * V_35 ;
V_35 = F_62 ( V_199 , V_200 ) ;
if ( ! V_35 )
goto V_72;
if ( ! V_7 )
F_34 ( L_4 , V_134 , V_2 ) ;
F_63 ( & V_35 -> V_201 ) ;
V_35 -> V_2 = V_2 ;
V_35 -> V_6 = (struct V_5 * ) V_6 ;
V_35 -> V_202 = 1 ;
V_35 -> V_203 = V_204 ;
F_63 ( & V_35 -> V_205 ) ;
F_63 ( & V_35 -> V_206 ) ;
F_64 ( V_4 ) ;
F_65 ( & V_35 -> V_207 , 1 ) ;
V_72:
return V_35 ;
}
void F_66 ( struct V_3 * V_4 , union V_208 * V_209 ,
union V_208 * V_210 )
{
memcpy ( & V_4 -> V_211 , V_209 , sizeof( union V_208 ) ) ;
memcpy ( & V_4 -> V_210 , V_210 , sizeof( union V_208 ) ) ;
}
const union V_208 * F_67 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_92 ) {
return & V_4 -> V_92 -> V_177 ;
} else {
return & V_4 -> V_211 ;
}
}
static struct V_3 * F_68 ( const struct V_5 * V_6 ,
T_10 type , T_10 V_106 , int V_16 )
{
struct V_3 * V_35 ;
T_19 * V_150 ;
struct V_1 * V_2 ;
struct V_198 * V_7 ;
V_2 = F_69 ( F_18 ( sizeof( T_19 ) + V_16 ) ,
V_200 ) ;
if ( ! V_2 )
goto V_72;
V_150 = ( T_19 * ) F_48 ( V_2 , sizeof( T_19 ) ) ;
V_150 -> type = type ;
V_150 -> V_106 = V_106 ;
V_150 -> V_20 = F_8 ( sizeof( T_19 ) ) ;
V_7 = V_6 ? V_6 -> V_8 . V_7 : NULL ;
V_35 = F_61 ( V_2 , V_6 , V_7 ) ;
if ( ! V_35 ) {
F_70 ( V_2 ) ;
goto V_72;
}
V_35 -> V_150 = V_150 ;
V_35 -> V_166 = ( ( T_10 * ) V_150 ) + sizeof( struct V_212 ) ;
if ( F_71 ( type , V_6 ) )
V_35 -> V_213 = 1 ;
return V_35 ;
V_72:
return NULL ;
}
static struct V_3 * F_31 ( const struct V_5 * V_6 ,
T_10 V_106 , int V_16 )
{
return F_68 ( V_6 , V_214 , V_106 , V_16 ) ;
}
static struct V_3 * F_21 ( const struct V_5 * V_6 ,
T_10 type , T_10 V_106 , int V_16 )
{
struct V_3 * V_4 = F_68 ( V_6 , type , V_106 , V_16 ) ;
if ( V_4 )
F_2 ( V_4 ) ;
return V_4 ;
}
static void F_72 ( struct V_3 * V_4 )
{
F_73 ( ! F_74 ( & V_4 -> V_201 ) ) ;
F_75 ( & V_4 -> V_205 ) ;
F_76 ( V_4 -> V_2 ) ;
F_76 ( V_4 -> V_215 ) ;
F_77 ( V_4 ) ;
F_78 ( V_199 , V_4 ) ;
}
void F_47 ( struct V_3 * V_4 )
{
if ( V_4 -> V_156 )
F_79 ( V_4 -> V_156 ) ;
F_80 ( V_4 ) ;
}
void F_81 ( struct V_3 * V_216 )
{
F_82 ( & V_216 -> V_207 ) ;
}
void F_80 ( struct V_3 * V_216 )
{
if ( F_83 ( & V_216 -> V_207 ) )
F_72 ( V_216 ) ;
}
void * F_9 ( struct V_3 * V_4 , int V_18 , const void * V_163 )
{
void * V_164 ;
void * V_217 ;
int V_165 = F_20 ( V_4 -> V_150 -> V_20 ) ;
int V_218 = F_18 ( V_165 ) - V_165 ;
V_217 = F_48 ( V_4 -> V_2 , V_218 ) ;
V_164 = F_48 ( V_4 -> V_2 , V_18 ) ;
memset ( V_217 , 0 , V_218 ) ;
memcpy ( V_164 , V_163 , V_18 ) ;
V_4 -> V_150 -> V_20 = F_8 ( V_165 + V_218 + V_18 ) ;
V_4 -> V_166 = F_49 ( V_4 -> V_2 ) ;
return V_164 ;
}
static void * F_12 ( struct V_3 * V_4 ,
int V_18 , const void * V_163 )
{
if ( F_11 ( V_4 -> V_2 ) >= V_18 )
return F_9 ( V_4 , V_18 , V_163 ) ;
else
return NULL ;
}
int F_84 ( struct V_3 * V_4 , int V_219 , int V_18 ,
struct V_220 * V_163 )
{
T_10 * V_164 ;
int V_17 = 0 ;
V_164 = F_48 ( V_4 -> V_2 , V_18 ) ;
if ( ( V_17 = F_85 ( V_164 , V_163 , V_219 , V_18 ) ) )
goto V_221;
V_4 -> V_150 -> V_20 =
F_8 ( F_20 ( V_4 -> V_150 -> V_20 ) + V_18 ) ;
V_4 -> V_166 = F_49 ( V_4 -> V_2 ) ;
V_221:
return V_17 ;
}
void F_86 ( struct V_3 * V_4 )
{
struct V_222 * V_156 ;
struct V_3 * V_223 ;
struct V_224 * V_112 ;
T_4 V_107 ;
T_4 V_225 ;
if ( V_4 -> V_226 )
return;
V_225 = F_20 ( V_4 -> V_21 . V_119 -> V_112 ) ;
V_112 = & V_4 -> V_6 -> V_227 -> V_221 ;
V_156 = V_4 -> V_156 ;
F_38 (lchunk, &msg->chunks, frag_list) {
if ( V_223 -> V_150 -> V_106 & V_118 ) {
V_107 = 0 ;
} else {
if ( V_223 -> V_150 -> V_106 & V_228 )
V_107 = F_87 ( V_112 , V_225 ) ;
else
V_107 = F_88 ( V_112 , V_225 ) ;
}
V_223 -> V_21 . V_119 -> V_107 = F_8 ( V_107 ) ;
V_223 -> V_226 = 1 ;
}
}
void F_89 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_229 ) {
V_4 -> V_21 . V_119 -> V_111 =
F_16 ( F_90 ( V_4 -> V_6 ) ) ;
V_4 -> V_229 = 1 ;
}
}
struct V_5 * F_91 ( const struct V_29 * V_30 ,
struct V_3 * V_4 ,
T_5 V_26 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
T_20 V_230 ;
struct V_10 * V_11 ;
V_230 = F_92 ( F_67 ( V_4 ) ) ;
V_6 = F_93 ( V_30 , V_30 -> V_8 . V_7 , V_230 , V_26 ) ;
if ( ! V_6 )
goto V_72;
V_6 -> V_231 = 1 ;
V_2 = V_4 -> V_2 ;
V_11 = F_4 ( F_5 ( F_6 ( V_2 ) -> V_13 ) ) ;
if ( F_60 ( ! V_11 ) )
goto V_232;
V_11 -> V_233 ( & V_6 -> V_49 . V_234 , V_2 , 1 ) ;
V_72:
return V_6 ;
V_232:
F_94 ( V_6 ) ;
return NULL ;
}
static T_12 * F_25 ( const struct V_29 * V_30 ,
const struct V_5 * V_6 ,
const struct V_3 * V_235 ,
int * V_82 ,
const T_10 * V_236 , int V_37 )
{
T_12 * V_35 ;
struct V_237 * V_81 ;
struct V_238 V_239 ;
int V_240 , V_241 ;
V_240 = sizeof( T_11 ) +
( sizeof( struct V_237 ) -
sizeof( struct V_242 ) ) ;
V_241 = sizeof( struct V_242 )
+ F_20 ( V_235 -> V_150 -> V_20 ) + V_37 ;
if ( V_241 % V_243 )
V_241 += V_243
- ( V_241 % V_243 ) ;
* V_82 = V_240 + V_241 ;
V_35 = F_95 ( * V_82 , V_200 ) ;
if ( ! V_35 )
goto V_72;
V_81 = (struct V_237 * ) V_35 -> V_244 ;
V_35 -> V_245 . type = V_246 ;
V_35 -> V_245 . V_20 = F_8 ( * V_82 ) ;
V_81 -> V_49 = V_6 -> V_49 ;
V_81 -> V_49 . V_247 = V_37 ;
V_81 -> V_49 . V_87 = V_6 -> V_85 . V_87 ;
V_81 -> V_49 . V_67 = V_6 -> V_85 . V_67 ;
V_81 -> V_49 . V_248 = F_96 ( V_6 -> V_249 ,
F_97 () ) ;
memcpy ( & V_81 -> V_49 . V_250 [ 0 ] , V_235 -> V_150 ,
F_20 ( V_235 -> V_150 -> V_20 ) ) ;
memcpy ( ( T_10 * ) & V_81 -> V_49 . V_250 [ 0 ] +
F_20 ( V_235 -> V_150 -> V_20 ) , V_236 , V_37 ) ;
if ( F_17 ( V_30 -> V_8 . V_7 ) -> V_192 ) {
struct V_251 V_252 ;
F_98 ( & V_239 , & V_81 -> V_49 , V_241 ) ;
V_252 . V_253 = F_17 ( V_30 -> V_8 . V_7 ) -> V_192 ;
V_252 . V_106 = 0 ;
if ( F_99 ( V_252 . V_253 , V_30 -> V_254 ,
sizeof( V_30 -> V_254 ) ) ||
F_100 ( & V_252 , & V_239 , V_241 , V_81 -> V_255 ) )
goto V_256;
}
return V_35 ;
V_256:
F_23 ( V_35 ) ;
V_72:
* V_82 = 0 ;
return NULL ;
}
struct V_5 * F_101 (
const struct V_29 * V_30 ,
const struct V_5 * V_6 ,
struct V_3 * V_4 , T_5 V_26 ,
int * error , struct V_3 * * V_257 )
{
struct V_5 * V_35 = NULL ;
struct V_237 * V_81 ;
struct V_242 * V_258 ;
int V_240 , V_241 , V_259 ;
T_10 * V_260 = V_30 -> V_260 ;
struct V_238 V_239 ;
unsigned int V_18 ;
T_20 V_230 ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_21 V_261 ;
struct V_251 V_252 ;
V_240 = sizeof( T_19 ) +
( sizeof( struct V_237 ) -
sizeof( struct V_242 ) ) ;
V_241 = F_20 ( V_4 -> V_150 -> V_20 ) - V_240 ;
V_259 = V_240 + sizeof( struct V_242 ) ;
V_18 = F_20 ( V_4 -> V_150 -> V_20 ) ;
if ( V_18 < V_259 + sizeof( struct V_212 ) )
goto V_262;
if ( V_241 % V_243 )
goto V_262;
V_81 = V_4 -> V_21 . V_94 ;
V_258 = & V_81 -> V_49 ;
if ( ! F_17 ( V_30 -> V_8 . V_7 ) -> V_192 )
goto V_263;
F_98 ( & V_239 , V_258 , V_241 ) ;
V_252 . V_253 = F_17 ( V_30 -> V_8 . V_7 ) -> V_192 ;
V_252 . V_106 = 0 ;
memset ( V_260 , 0x00 , V_264 ) ;
if ( F_99 ( V_252 . V_253 , V_30 -> V_254 ,
sizeof( V_30 -> V_254 ) ) ||
F_100 ( & V_252 , & V_239 , V_241 , V_260 ) ) {
* error = - V_265 ;
goto V_232;
}
if ( memcmp ( V_260 , V_81 -> V_255 , V_264 ) ) {
* error = - V_266 ;
goto V_232;
}
V_263:
if ( F_102 ( V_4 -> V_267 -> V_268 ) != V_258 -> V_50 ) {
* error = - V_269 ;
goto V_232;
}
if ( V_4 -> V_267 -> V_211 != V_258 -> V_234 . V_270 . V_271 ||
F_20 ( V_4 -> V_267 -> V_210 ) != V_258 -> V_272 ) {
* error = - V_273 ;
goto V_232;
}
if ( F_103 ( V_30 -> V_8 . V_7 , V_274 ) )
V_261 = F_104 ( V_2 ) ;
else
V_261 = F_97 () ;
if ( ! V_6 && F_105 ( V_258 -> V_248 , V_261 ) ) {
V_18 = F_20 ( V_4 -> V_150 -> V_20 ) ;
* V_257 = F_55 ( V_6 , V_4 , V_18 ) ;
if ( * V_257 ) {
T_22 V_275 = F_106 ( F_107 ( V_261 , V_258 -> V_248 ) ) ;
T_17 V_276 = F_16 ( V_275 ) ;
F_7 ( * V_257 , V_277 ,
sizeof( V_276 ) ) ;
F_9 ( * V_257 , sizeof( V_276 ) , & V_276 ) ;
* error = - V_278 ;
} else
* error = - V_265 ;
goto V_232;
}
V_230 = F_92 ( F_67 ( V_4 ) ) ;
V_35 = F_93 ( V_30 , V_30 -> V_8 . V_7 , V_230 , V_26 ) ;
if ( ! V_35 ) {
* error = - V_265 ;
goto V_232;
}
V_35 -> V_85 . V_279 = F_20 ( V_4 -> V_267 -> V_211 ) ;
memcpy ( & V_35 -> V_49 , V_258 , sizeof( * V_258 ) ) ;
if ( F_108 ( V_35 , V_258 ,
V_200 ) < 0 ) {
* error = - V_265 ;
goto V_232;
}
if ( F_74 ( & V_35 -> V_8 . V_83 . V_280 ) ) {
F_109 ( & V_35 -> V_8 . V_83 , & V_4 -> V_210 ,
V_281 , V_200 ) ;
}
V_35 -> V_282 = V_35 -> V_49 . V_57 ;
V_35 -> V_283 = V_35 -> V_282 - 1 ;
V_35 -> V_284 = V_35 -> V_49 . V_57 ;
V_35 -> V_285 = V_35 -> V_283 ;
V_35 -> V_85 . V_87 = V_35 -> V_49 . V_87 ;
V_35 -> V_85 . V_67 = V_35 -> V_49 . V_67 ;
return V_35 ;
V_232:
if ( V_35 )
F_94 ( V_35 ) ;
return NULL ;
V_262:
* error = - V_286 ;
goto V_232;
}
static int F_110 ( const struct V_5 * V_6 ,
T_23 V_287 ,
struct V_3 * V_4 ,
struct V_3 * * V_257 )
{
struct V_288 V_289 ;
T_4 V_18 ;
V_18 = F_18 ( sizeof( V_289 ) ) ;
if ( ! * V_257 )
* V_257 = F_55 ( V_6 , V_4 , V_18 ) ;
if ( * V_257 ) {
V_289 . V_290 = F_16 ( 1 ) ;
V_289 . type = V_287 ;
F_7 ( * V_257 , V_291 ,
sizeof( V_289 ) ) ;
F_9 ( * V_257 , sizeof( V_289 ) , & V_289 ) ;
}
return 0 ;
}
static int F_111 ( const struct V_5 * V_6 ,
struct V_3 * V_4 ,
struct V_3 * * V_257 )
{
if ( ! * V_257 )
* V_257 = F_55 ( V_6 , V_4 , 0 ) ;
if ( * V_257 )
F_7 ( * V_257 , V_292 , 0 ) ;
return 0 ;
}
static int F_112 ( const struct V_5 * V_6 ,
struct V_167 * V_171 ,
const struct V_3 * V_4 ,
struct V_3 * * V_257 )
{
if ( * V_257 )
F_47 ( * V_257 ) ;
* V_257 = F_51 ( V_6 , V_4 , V_171 ) ;
return 0 ;
}
static int F_113 ( const struct V_5 * V_6 ,
union V_32 V_171 ,
struct V_3 * V_4 ,
struct V_3 * * V_257 )
{
T_4 V_18 = F_20 ( V_171 . V_245 -> V_20 ) ;
if ( * V_257 )
F_47 ( * V_257 ) ;
* V_257 = F_55 ( V_6 , V_4 , V_18 ) ;
if ( * V_257 ) {
F_7 ( * V_257 , V_293 , V_18 ) ;
F_9 ( * V_257 , V_18 , V_171 . V_75 ) ;
}
return 0 ;
}
static int F_114 ( struct V_28 * V_28 , union V_32 V_171 )
{
T_4 V_44 = F_20 ( V_171 . V_245 -> V_20 ) - sizeof( T_11 ) ;
int V_294 = 0 ;
int V_295 = 0 ;
int V_296 ;
for ( V_296 = 0 ; V_296 < V_44 ; V_296 ++ ) {
switch ( V_171 . V_297 -> V_298 [ V_296 ] ) {
case V_70 :
V_294 = 1 ;
break;
case V_65 :
case V_66 :
V_295 = 1 ;
break;
}
}
if ( V_28 -> V_61 . V_299 )
return 1 ;
if ( V_28 -> V_61 . V_64 && ! V_294 && V_295 )
return 0 ;
return 1 ;
}
static void F_115 ( struct V_5 * V_6 ,
union V_32 V_171 )
{
struct V_28 * V_28 = F_14 ( V_6 -> V_8 . V_7 ) ;
T_4 V_44 = F_20 ( V_171 . V_245 -> V_20 ) - sizeof( T_11 ) ;
int V_296 ;
for ( V_296 = 0 ; V_296 < V_44 ; V_296 ++ ) {
switch ( V_171 . V_297 -> V_298 [ V_296 ] ) {
case V_300 :
if ( V_28 -> V_61 . V_62 && ! V_6 -> V_85 . V_87 )
V_6 -> V_85 . V_87 = 1 ;
break;
case V_70 :
if ( V_6 -> V_30 -> V_68 )
V_6 -> V_85 . V_89 = 1 ;
break;
case V_65 :
case V_66 :
if ( V_28 -> V_61 . V_64 )
V_6 -> V_85 . V_88 = 1 ;
break;
default:
break;
}
}
}
static T_24 F_116 ( const struct V_5 * V_6 ,
union V_32 V_171 ,
struct V_3 * V_4 ,
struct V_3 * * V_257 )
{
int V_35 = V_301 ;
switch ( V_171 . V_245 -> type & V_302 ) {
case V_303 :
V_35 = V_304 ;
break;
case V_305 :
break;
case V_306 :
V_35 = V_304 ;
case V_307 :
if ( NULL == * V_257 )
* V_257 = F_56 ( V_6 , V_4 ) ;
if ( * V_257 ) {
if ( ! F_10 ( * V_257 , V_308 ,
F_18 ( F_20 ( V_171 . V_245 -> V_20 ) ) ) )
F_12 ( * V_257 ,
F_18 ( F_20 ( V_171 . V_245 -> V_20 ) ) ,
V_171 . V_75 ) ;
} else {
V_35 = V_265 ;
}
break;
default:
break;
}
return V_35 ;
}
static T_24 F_117 ( struct V_28 * V_28 ,
const struct V_29 * V_30 ,
const struct V_5 * V_6 ,
union V_32 V_171 ,
T_25 V_309 ,
struct V_3 * V_4 ,
struct V_3 * * V_157 )
{
struct V_310 * V_311 ;
int V_35 = V_301 ;
T_4 V_312 , V_313 = 0 ;
int V_296 ;
switch ( V_171 . V_245 -> type ) {
case V_314 :
case V_315 :
case V_316 :
case V_76 :
case V_246 :
case V_175 :
case V_317 :
case V_318 :
case V_78 :
break;
case V_77 :
if ( ! F_114 ( V_28 , V_171 ) )
return V_319 ;
break;
case V_320 :
if ( V_28 -> V_61 . V_64 )
break;
goto V_321;
case V_322 :
F_113 ( V_6 , V_171 , V_4 , V_157 ) ;
V_35 = V_319 ;
break;
case V_323 :
if ( V_28 -> V_61 . V_62 )
break;
goto V_321;
case V_324 :
if ( ! V_30 -> V_68 )
goto V_321;
if ( V_325 !=
F_20 ( V_171 . V_245 -> V_20 ) - sizeof( T_11 ) ) {
F_112 ( V_6 , V_171 . V_245 ,
V_4 , V_157 ) ;
V_35 = V_319 ;
}
break;
case V_326 :
if ( ! V_30 -> V_68 )
goto V_321;
if ( 260 < F_20 ( V_171 . V_245 -> V_20 ) ) {
F_112 ( V_6 , V_171 . V_245 ,
V_4 , V_157 ) ;
V_35 = V_319 ;
}
break;
case V_327 :
if ( ! V_30 -> V_68 )
goto V_321;
V_311 = (struct V_310 * ) V_171 . V_245 ;
V_312 = ( F_20 ( V_171 . V_245 -> V_20 ) - sizeof( T_11 ) ) >> 1 ;
for ( V_296 = 0 ; V_296 < V_312 ; V_296 ++ ) {
V_313 = F_20 ( V_311 -> V_328 [ V_296 ] ) ;
if ( V_313 == V_329 )
break;
}
if ( V_313 != V_329 ) {
F_112 ( V_6 , V_171 . V_245 , V_4 ,
V_157 ) ;
V_35 = V_319 ;
}
break;
V_321:
default:
F_34 ( L_5 ,
V_134 , F_20 ( V_171 . V_245 -> type ) , V_309 ) ;
V_35 = F_116 ( V_6 , V_171 , V_4 , V_157 ) ;
break;
}
return V_35 ;
}
int F_118 ( struct V_28 * V_28 , const struct V_29 * V_30 ,
const struct V_5 * V_6 , T_25 V_309 ,
T_26 * V_250 , struct V_3 * V_4 ,
struct V_3 * * V_257 )
{
union V_32 V_171 ;
bool V_330 = false ;
int V_331 ;
if ( V_250 -> V_73 . V_53 == 0 ||
V_250 -> V_73 . V_55 == 0 ||
V_250 -> V_73 . V_48 == 0 ||
F_102 ( V_250 -> V_73 . V_51 ) < V_332 )
return F_111 ( V_6 , V_4 , V_257 ) ;
F_119 (param, peer_init, init_hdr.params) {
if ( V_171 . V_245 -> type == V_246 )
V_330 = true ;
}
if ( V_171 . V_75 != ( void * ) V_4 -> V_166 )
return F_112 ( V_6 , V_171 . V_245 , V_4 , V_257 ) ;
if ( ( V_90 == V_309 ) && ! V_330 )
return F_110 ( V_6 , V_246 ,
V_4 , V_257 ) ;
F_119 (param, peer_init, init_hdr.params) {
V_331 = F_117 ( V_28 , V_30 , V_6 , V_171 , V_309 ,
V_4 , V_257 ) ;
switch ( V_331 ) {
case V_319 :
case V_265 :
return 0 ;
case V_304 :
return 1 ;
case V_301 :
default:
break;
}
}
return 1 ;
}
int F_120 ( struct V_5 * V_6 , struct V_3 * V_4 ,
const union V_208 * V_234 ,
T_26 * V_250 , T_5 V_26 )
{
struct V_28 * V_28 = F_14 ( V_6 -> V_8 . V_7 ) ;
union V_32 V_171 ;
struct V_132 * V_92 ;
struct V_333 * V_334 , * V_231 ;
struct V_10 * V_11 ;
union V_208 V_335 ;
char * V_81 ;
int V_336 = 0 ;
if ( ! F_121 ( V_6 , V_234 , V_26 , V_337 ) )
goto V_338;
if ( F_122 ( F_67 ( V_4 ) , V_234 ) )
V_336 = 1 ;
F_119 (param, peer_init, init_hdr.params) {
if ( ! V_336 && ( V_171 . V_245 -> type == V_314 ||
V_171 . V_245 -> type == V_315 ) ) {
V_11 = F_4 ( F_123 ( V_171 . V_245 -> type ) ) ;
V_11 -> V_339 ( & V_335 , V_171 . V_335 ,
V_4 -> V_267 -> V_211 , 0 ) ;
if ( F_122 ( F_67 ( V_4 ) , & V_335 ) )
V_336 = 1 ;
}
if ( ! F_124 ( V_6 , V_171 , V_234 , V_26 ) )
goto V_340;
}
if ( ! V_336 )
goto V_340;
if ( V_6 -> V_85 . V_89 && ( ! V_6 -> V_85 . V_341 ||
! V_6 -> V_85 . V_342 ) )
V_6 -> V_85 . V_89 = 0 ;
if ( ! V_28 -> V_61 . V_299 &&
( V_6 -> V_85 . V_88 && ! V_6 -> V_85 . V_89 ) ) {
V_6 -> V_85 . V_343 |= ( V_344 |
V_345 |
V_320 ) ;
V_6 -> V_85 . V_88 = 0 ;
goto V_340;
}
F_125 (pos, temp, &asoc->peer.transport_addr_list) {
V_92 = F_126 ( V_334 , struct V_132 , V_346 ) ;
if ( V_92 -> V_347 == V_348 ) {
F_127 ( V_6 , V_92 ) ;
}
}
V_6 -> V_85 . V_296 . V_48 =
F_102 ( V_250 -> V_73 . V_48 ) ;
V_6 -> V_85 . V_296 . V_51 =
F_102 ( V_250 -> V_73 . V_51 ) ;
V_6 -> V_85 . V_296 . V_53 =
F_20 ( V_250 -> V_73 . V_53 ) ;
V_6 -> V_85 . V_296 . V_55 =
F_20 ( V_250 -> V_73 . V_55 ) ;
V_6 -> V_85 . V_296 . V_57 =
F_102 ( V_250 -> V_73 . V_57 ) ;
if ( V_6 -> V_49 . V_54 >
F_20 ( V_250 -> V_73 . V_55 ) ) {
V_6 -> V_49 . V_54 =
F_20 ( V_250 -> V_73 . V_55 ) ;
}
if ( V_6 -> V_49 . V_56 >
F_20 ( V_250 -> V_73 . V_53 ) ) {
V_6 -> V_49 . V_56 =
F_20 ( V_250 -> V_73 . V_53 ) ;
}
V_6 -> V_49 . V_349 = V_6 -> V_85 . V_296 . V_48 ;
V_6 -> V_85 . V_52 = V_6 -> V_85 . V_296 . V_51 ;
V_81 = V_6 -> V_85 . V_81 ;
if ( V_81 ) {
V_6 -> V_85 . V_81 = F_128 ( V_81 , V_6 -> V_85 . V_82 , V_26 ) ;
if ( ! V_6 -> V_85 . V_81 )
goto V_340;
}
F_38 (transport, &asoc->peer.transport_addr_list,
transports) {
V_92 -> V_350 = V_6 -> V_85 . V_296 . V_51 ;
}
if ( ! F_129 ( & V_6 -> V_85 . V_128 , V_351 ,
V_6 -> V_85 . V_296 . V_57 , V_26 ) )
goto V_340;
if ( ! V_6 -> V_231 ) {
int error ;
V_6 -> V_227 = F_130 ( V_6 -> V_49 . V_56 ,
V_6 -> V_49 . V_54 , V_26 ) ;
if ( ! V_6 -> V_227 )
goto V_340;
error = F_131 ( V_6 , V_26 ) ;
if ( error )
goto V_340;
}
V_6 -> V_85 . V_284 = V_6 -> V_85 . V_296 . V_57 - 1 ;
return 1 ;
V_340:
F_125 (pos, temp, &asoc->peer.transport_addr_list) {
V_92 = F_126 ( V_334 , struct V_132 , V_346 ) ;
if ( V_92 -> V_347 != V_337 )
F_127 ( V_6 , V_92 ) ;
}
V_338:
return 0 ;
}
static int F_124 ( struct V_5 * V_6 ,
union V_32 V_171 ,
const union V_208 * V_234 ,
T_5 V_26 )
{
struct V_28 * V_28 = F_14 ( V_6 -> V_8 . V_7 ) ;
union V_208 V_335 ;
int V_296 ;
T_4 V_40 ;
int V_35 = 1 ;
T_20 V_230 ;
T_27 V_352 ;
struct V_10 * V_11 ;
union V_353 * V_354 ;
struct V_132 * V_355 ;
struct V_29 * V_30 = V_6 -> V_30 ;
switch ( V_171 . V_245 -> type ) {
case V_315 :
if ( V_356 != V_6 -> V_8 . V_7 -> V_357 )
break;
goto V_358;
case V_314 :
if ( F_132 ( V_6 -> V_8 . V_7 ) )
break;
V_358:
V_11 = F_4 ( F_123 ( V_171 . V_245 -> type ) ) ;
V_11 -> V_339 ( & V_335 , V_171 . V_335 , F_8 ( V_6 -> V_85 . V_279 ) , 0 ) ;
V_230 = F_92 ( V_234 ) ;
if ( F_133 ( V_28 , & V_335 , V_230 ) )
if ( ! F_121 ( V_6 , & V_335 , V_26 , V_359 ) )
return 0 ;
break;
case V_316 :
if ( ! V_28 -> V_61 . V_360 )
break;
V_352 = F_102 ( V_171 . V_361 -> V_362 ) ;
V_6 -> V_249 = F_134 ( V_6 -> V_249 , V_352 ) ;
break;
case V_322 :
F_34 ( L_6 , V_134 ) ;
break;
case V_76 :
V_6 -> V_85 . V_363 = 0 ;
V_6 -> V_85 . V_364 = 0 ;
if ( V_234 -> V_365 . V_366 == V_367 )
V_6 -> V_85 . V_364 = 1 ;
else if ( V_234 -> V_365 . V_366 == V_368 )
V_6 -> V_85 . V_363 = 1 ;
V_40 = F_20 ( V_171 . V_245 -> V_20 ) - sizeof( T_11 ) ;
if ( V_40 )
V_40 /= sizeof( T_4 ) ;
for ( V_296 = 0 ; V_296 < V_40 ; ++ V_296 ) {
switch ( V_171 . V_40 -> V_41 [ V_296 ] ) {
case V_314 :
V_6 -> V_85 . V_363 = 1 ;
break;
case V_315 :
if ( V_356 == V_6 -> V_8 . V_7 -> V_357 )
V_6 -> V_85 . V_364 = 1 ;
break;
case V_322 :
V_6 -> V_85 . V_369 = 1 ;
break;
default:
break;
}
}
break;
case V_246 :
V_6 -> V_85 . V_82 =
F_20 ( V_171 . V_245 -> V_20 ) - sizeof( T_11 ) ;
V_6 -> V_85 . V_81 = V_171 . V_81 -> V_244 ;
break;
case V_175 :
break;
case V_317 :
break;
case V_318 :
V_6 -> V_85 . V_86 = 1 ;
break;
case V_78 :
V_6 -> V_85 . V_67 = F_102 ( V_171 . V_370 -> V_67 ) ;
break;
case V_320 :
if ( ! V_28 -> V_61 . V_64 )
goto V_371;
V_354 = V_171 . V_75 + sizeof( V_372 ) ;
V_11 = F_4 ( F_123 ( V_171 . V_245 -> type ) ) ;
V_11 -> V_339 ( & V_335 , V_354 ,
F_8 ( V_6 -> V_85 . V_279 ) , 0 ) ;
if ( ! V_11 -> V_373 ( & V_335 , NULL , NULL ) )
break;
V_355 = F_135 ( V_6 , & V_335 ) ;
if ( ! V_355 )
break;
F_136 ( V_6 , V_355 ) ;
break;
case V_77 :
F_115 ( V_6 , V_171 ) ;
break;
case V_323 :
if ( V_28 -> V_61 . V_62 ) {
V_6 -> V_85 . V_87 = 1 ;
break;
}
goto V_371;
case V_324 :
if ( ! V_30 -> V_68 )
goto V_371;
V_6 -> V_85 . V_341 = F_128 ( V_171 . V_245 ,
F_20 ( V_171 . V_245 -> V_20 ) , V_26 ) ;
if ( ! V_6 -> V_85 . V_341 ) {
V_35 = 0 ;
break;
}
break;
case V_327 :
if ( ! V_30 -> V_68 )
goto V_371;
V_6 -> V_85 . V_342 = F_128 ( V_171 . V_245 ,
F_20 ( V_171 . V_245 -> V_20 ) , V_26 ) ;
if ( ! V_6 -> V_85 . V_342 ) {
V_35 = 0 ;
break;
}
F_137 ( V_6 , V_171 . V_374 ) ;
break;
case V_326 :
if ( ! V_30 -> V_68 )
goto V_371;
V_6 -> V_85 . V_375 = F_128 ( V_171 . V_245 ,
F_20 ( V_171 . V_245 -> V_20 ) , V_26 ) ;
if ( ! V_6 -> V_85 . V_375 )
V_35 = 0 ;
break;
V_371:
default:
F_34 ( L_7 ,
V_134 , F_20 ( V_171 . V_245 -> type ) , V_6 ) ;
break;
}
return V_35 ;
}
T_13 F_138 ( const struct V_29 * V_30 )
{
T_13 V_376 ;
do {
F_139 ( & V_376 , sizeof( T_13 ) ) ;
} while ( V_376 == 0 );
return V_376 ;
}
T_13 F_140 ( const struct V_29 * V_30 )
{
T_13 V_35 ;
F_139 ( & V_35 , sizeof( T_13 ) ) ;
return V_35 ;
}
static struct V_3 * F_141 ( struct V_5 * V_6 ,
union V_208 * V_335 ,
int V_27 )
{
T_28 V_377 ;
struct V_3 * V_35 ;
int V_20 = sizeof( V_377 ) + V_27 ;
union V_353 V_378 ;
int V_379 ;
struct V_10 * V_11 = F_4 ( V_335 -> V_270 . V_380 ) ;
V_379 = V_11 -> V_381 ( V_335 , & V_378 ) ;
if ( ! V_379 )
return NULL ;
V_20 += V_379 ;
V_35 = F_21 ( V_6 , V_65 , 0 , V_20 ) ;
if ( ! V_35 )
return NULL ;
V_377 . V_382 = F_16 ( V_6 -> V_284 ++ ) ;
V_35 -> V_21 . V_383 =
F_9 ( V_35 , sizeof( V_377 ) , & V_377 ) ;
V_35 -> V_74 . V_75 =
F_9 ( V_35 , V_379 , & V_378 ) ;
return V_35 ;
}
struct V_3 * F_142 ( struct V_5 * V_6 ,
union V_208 * V_384 ,
struct V_385 * V_33 ,
int V_386 ,
T_1 V_106 )
{
V_372 V_171 ;
struct V_3 * V_35 ;
union V_353 V_354 ;
union V_208 * V_335 ;
void * V_387 ;
struct V_10 * V_11 ;
int V_388 = sizeof( V_171 ) ;
int V_389 = 0 ;
int V_390 = 0 ;
int V_296 ;
int V_391 = 0 ;
V_387 = V_33 ;
for ( V_296 = 0 ; V_296 < V_386 ; V_296 ++ ) {
V_335 = V_387 ;
V_11 = F_4 ( V_335 -> V_270 . V_380 ) ;
V_389 = V_11 -> V_381 ( V_335 , & V_354 ) ;
V_390 += V_388 ;
V_390 += V_389 ;
V_387 += V_11 -> V_392 ;
if ( V_6 -> V_393 && ! V_391 ) {
V_390 += V_388 ;
V_390 += V_389 ;
V_391 = 1 ;
F_34 ( L_8
L_9 ,
V_134 , V_390 ) ;
}
}
V_35 = F_141 ( V_6 , V_384 , V_390 ) ;
if ( ! V_35 )
return NULL ;
V_387 = V_33 ;
for ( V_296 = 0 ; V_296 < V_386 ; V_296 ++ ) {
V_335 = V_387 ;
V_11 = F_4 ( V_335 -> V_270 . V_380 ) ;
V_389 = V_11 -> V_381 ( V_335 , & V_354 ) ;
V_171 . V_74 . type = V_106 ;
V_171 . V_74 . V_20 = F_8 ( V_388 + V_389 ) ;
V_171 . V_394 = V_296 ;
F_9 ( V_35 , V_388 , & V_171 ) ;
F_9 ( V_35 , V_389 , & V_354 ) ;
V_387 += V_11 -> V_392 ;
}
if ( V_106 == V_344 && V_391 ) {
V_335 = V_6 -> V_393 ;
V_11 = F_4 ( V_335 -> V_270 . V_380 ) ;
V_389 = V_11 -> V_381 ( V_335 , & V_354 ) ;
V_171 . V_74 . type = V_345 ;
V_171 . V_74 . V_20 = F_8 ( V_388 + V_389 ) ;
V_171 . V_394 = V_296 ;
F_9 ( V_35 , V_388 , & V_171 ) ;
F_9 ( V_35 , V_389 , & V_354 ) ;
}
return V_35 ;
}
struct V_3 * F_143 ( struct V_5 * V_6 ,
union V_208 * V_335 )
{
V_372 V_171 ;
struct V_3 * V_35 ;
int V_18 = sizeof( V_171 ) ;
union V_353 V_378 ;
int V_379 ;
struct V_10 * V_11 = F_4 ( V_335 -> V_270 . V_380 ) ;
V_379 = V_11 -> V_381 ( V_335 , & V_378 ) ;
if ( ! V_379 )
return NULL ;
V_18 += V_379 ;
V_35 = F_141 ( V_6 , V_335 , V_18 ) ;
if ( ! V_35 )
return NULL ;
V_171 . V_74 . type = V_320 ;
V_171 . V_74 . V_20 = F_8 ( V_18 ) ;
V_171 . V_394 = 0 ;
F_9 ( V_35 , sizeof( V_171 ) , & V_171 ) ;
F_9 ( V_35 , V_379 , & V_378 ) ;
return V_35 ;
}
static struct V_3 * F_144 ( const struct V_5 * V_6 ,
T_13 V_382 , int V_27 )
{
T_28 V_377 ;
struct V_3 * V_35 ;
int V_20 = sizeof( V_377 ) + V_27 ;
V_35 = F_21 ( V_6 , V_66 , 0 , V_20 ) ;
if ( ! V_35 )
return NULL ;
V_377 . V_382 = F_16 ( V_382 ) ;
V_35 -> V_21 . V_383 =
F_9 ( V_35 , sizeof( V_377 ) , & V_377 ) ;
return V_35 ;
}
static void F_145 ( struct V_3 * V_4 , T_17 V_394 ,
T_1 V_395 , V_372 * V_396 )
{
V_372 V_397 ;
T_3 V_398 ;
int V_399 = 0 ;
int V_400 = 0 ;
T_1 V_401 ;
if ( V_402 == V_395 ) {
V_401 = V_403 ;
} else {
V_401 = V_404 ;
V_400 = sizeof( V_398 ) ;
if ( V_396 )
V_399 =
F_20 ( V_396 -> V_74 . V_20 ) ;
}
V_397 . V_74 . type = V_401 ;
V_397 . V_74 . V_20 = F_8 ( sizeof( V_397 ) +
V_400 +
V_399 ) ;
V_397 . V_394 = V_394 ;
F_9 ( V_4 , sizeof( V_397 ) , & V_397 ) ;
if ( V_402 == V_395 )
return;
V_398 . V_19 = V_395 ;
V_398 . V_20 = F_8 ( V_400 + V_399 ) ;
F_9 ( V_4 , V_400 , & V_398 ) ;
if ( V_396 )
F_9 ( V_4 , V_399 , V_396 ) ;
}
static T_1 F_146 ( struct V_5 * V_6 ,
struct V_3 * V_377 ,
V_372 * V_396 )
{
struct V_132 * V_85 ;
struct V_10 * V_11 ;
union V_208 V_335 ;
union V_353 * V_354 ;
V_354 = ( void * ) V_396 + sizeof( V_372 ) ;
if ( V_396 -> V_74 . type != V_344 &&
V_396 -> V_74 . type != V_345 &&
V_396 -> V_74 . type != V_320 )
return V_308 ;
switch ( V_354 -> V_245 . type ) {
case V_315 :
if ( ! V_6 -> V_85 . V_364 )
return V_293 ;
break;
case V_314 :
if ( ! V_6 -> V_85 . V_363 )
return V_293 ;
break;
default:
return V_293 ;
}
V_11 = F_4 ( F_123 ( V_354 -> V_245 . type ) ) ;
if ( F_60 ( ! V_11 ) )
return V_293 ;
V_11 -> V_339 ( & V_335 , V_354 , F_8 ( V_6 -> V_85 . V_279 ) , 0 ) ;
if ( ! V_11 -> V_405 ( & V_335 ) && ! V_11 -> V_373 ( & V_335 , NULL , V_377 -> V_2 ) )
return V_293 ;
switch ( V_396 -> V_74 . type ) {
case V_344 :
if ( V_11 -> V_405 ( & V_335 ) )
memcpy ( & V_335 , & V_377 -> V_211 , sizeof( V_335 ) ) ;
V_85 = F_121 ( V_6 , & V_335 , V_200 , V_359 ) ;
if ( ! V_85 )
return V_406 ;
if ( ! F_147 ( & V_85 -> V_407 , F_148 ( V_85 ) ) )
F_149 ( V_85 ) ;
V_6 -> V_408 = V_85 ;
break;
case V_345 :
if ( V_6 -> V_85 . V_409 == 1 )
return V_410 ;
if ( F_122 ( & V_377 -> V_211 , & V_335 ) )
return V_411 ;
if ( V_11 -> V_405 ( & V_335 ) ) {
F_136 ( V_6 , V_377 -> V_92 ) ;
F_150 ( V_6 ,
V_377 -> V_92 ) ;
} else
F_151 ( V_6 , & V_335 ) ;
break;
case V_320 :
if ( V_11 -> V_405 ( & V_335 ) )
memcpy ( & V_335 . V_270 , F_67 ( V_377 ) , sizeof( V_335 ) ) ;
V_85 = F_135 ( V_6 , & V_335 ) ;
if ( ! V_85 )
return V_293 ;
F_136 ( V_6 , V_85 ) ;
break;
}
return V_402 ;
}
int F_152 ( const struct V_5 * V_6 ,
struct V_167 * V_74 , void * V_166 ,
struct V_167 * * V_257 ) {
V_372 * V_396 ;
union V_32 V_171 ;
int V_20 , V_412 ;
V_171 . V_75 = ( T_11 * ) V_74 ;
while ( V_171 . V_75 <= V_166 - sizeof( T_11 ) ) {
V_20 = F_20 ( V_171 . V_245 -> V_20 ) ;
* V_257 = V_171 . V_245 ;
if ( V_171 . V_75 > V_166 - V_20 ||
V_20 < sizeof( T_11 ) )
return 0 ;
switch ( V_171 . V_245 -> type ) {
case V_344 :
case V_345 :
case V_320 :
V_396 = ( V_372 * ) V_171 . V_75 ;
V_412 = F_20 ( V_396 -> V_74 . V_20 ) ;
if ( V_412 < sizeof( V_372 ) +
sizeof( T_11 ) )
return 0 ;
break;
case V_403 :
case V_78 :
if ( V_20 != sizeof( V_372 ) )
return 0 ;
break;
default:
break;
}
V_171 . V_75 += F_18 ( V_20 ) ;
}
if ( V_171 . V_75 != V_166 )
return 0 ;
return 1 ;
}
struct V_3 * F_153 ( struct V_5 * V_6 ,
struct V_3 * V_377 )
{
T_28 * V_413 ;
union V_353 * V_354 ;
V_372 * V_396 ;
struct V_3 * V_414 ;
T_1 V_395 ;
int V_20 = 0 ;
int V_110 ;
T_13 V_382 ;
int V_415 = 1 ;
V_110 = F_20 ( V_377 -> V_150 -> V_20 ) - sizeof( T_19 ) ;
V_413 = ( T_28 * ) V_377 -> V_2 -> V_163 ;
V_382 = F_102 ( V_413 -> V_382 ) ;
V_20 = sizeof( T_28 ) ;
V_354 = (union V_353 * ) ( V_377 -> V_2 -> V_163 + V_20 ) ;
V_110 -= V_20 ;
V_20 = F_20 ( V_354 -> V_245 . V_20 ) ;
V_396 = ( void * ) V_354 + V_20 ;
V_110 -= V_20 ;
V_414 = F_144 ( V_6 , V_382 , V_110 * 4 ) ;
if ( ! V_414 )
goto V_416;
while ( V_110 > 0 ) {
V_395 = F_146 ( V_6 , V_377 ,
V_396 ) ;
if ( V_402 != V_395 )
V_415 = 0 ;
if ( ! V_415 )
F_145 ( V_414 ,
V_396 -> V_394 , V_395 ,
V_396 ) ;
if ( V_406 == V_395 )
goto V_416;
V_20 = F_20 ( V_396 -> V_74 . V_20 ) ;
V_396 = ( void * ) V_396 + V_20 ;
V_110 -= V_20 ;
}
V_416:
V_6 -> V_85 . V_284 ++ ;
if ( V_414 ) {
F_81 ( V_414 ) ;
F_154 ( & V_414 -> V_205 ,
& V_6 -> V_417 ) ;
}
return V_414 ;
}
static void F_155 ( struct V_5 * V_6 ,
V_372 * V_396 )
{
struct V_10 * V_11 ;
union V_208 V_335 ;
struct V_24 * V_25 = & V_6 -> V_8 . V_83 ;
union V_353 * V_354 ;
struct V_132 * V_92 ;
struct V_418 * V_419 ;
V_354 = ( void * ) V_396 + sizeof( V_372 ) ;
V_11 = F_4 ( F_123 ( V_354 -> V_245 . type ) ) ;
V_11 -> V_339 ( & V_335 , V_354 , F_8 ( V_25 -> V_279 ) , 0 ) ;
switch ( V_396 -> V_74 . type ) {
case V_344 :
F_156 () ;
F_38 (saddr, &bp->address_list, list) {
if ( F_122 ( & V_419 -> V_420 , & V_335 ) )
V_419 -> V_347 = V_281 ;
}
F_157 () ;
F_38 (transport, &asoc->peer.transport_addr_list,
transports) {
F_158 ( V_92 -> V_421 ) ;
V_92 -> V_421 = NULL ;
}
break;
case V_345 :
F_156 () ;
F_159 ( V_25 , & V_335 ) ;
if ( V_6 -> V_393 != NULL &&
F_122 ( V_6 -> V_393 , & V_335 ) ) {
F_23 ( V_6 -> V_393 ) ;
V_6 -> V_393 = NULL ;
}
F_157 () ;
F_38 (transport, &asoc->peer.transport_addr_list,
transports) {
F_158 ( V_92 -> V_421 ) ;
V_92 -> V_421 = NULL ;
}
break;
default:
break;
}
}
static T_1 F_160 ( struct V_3 * V_414 ,
V_372 * V_396 ,
int V_422 )
{
V_372 * V_423 ;
T_3 * V_398 ;
int V_20 ;
int V_424 ;
T_1 V_395 ;
if ( V_422 )
V_395 = V_402 ;
else
V_395 = V_425 ;
V_424 = F_20 ( V_414 -> V_150 -> V_20 ) -
sizeof( T_19 ) ;
V_20 = sizeof( T_28 ) ;
V_423 = ( V_372 * ) ( V_414 -> V_2 -> V_163 +
V_20 ) ;
V_424 -= V_20 ;
while ( V_424 > 0 ) {
if ( V_423 -> V_394 == V_396 -> V_394 ) {
switch ( V_423 -> V_74 . type ) {
case V_403 :
return V_402 ;
case V_404 :
V_20 = sizeof( V_372 ) ;
V_398 = ( void * ) V_423 + V_20 ;
V_424 -= V_20 ;
if ( V_424 > 0 )
return V_398 -> V_19 ;
else
return V_292 ;
break;
default:
return V_292 ;
}
}
V_20 = F_20 ( V_423 -> V_74 . V_20 ) ;
V_423 = ( void * ) V_423 + V_20 ;
V_424 -= V_20 ;
}
return V_395 ;
}
int F_161 ( struct V_5 * V_6 ,
struct V_3 * V_414 )
{
struct V_3 * V_377 = V_6 -> V_426 ;
union V_353 * V_354 ;
V_372 * V_396 ;
int V_20 = 0 ;
int V_427 = V_377 -> V_2 -> V_18 ;
int V_415 = 0 ;
int V_422 = 1 ;
int V_35 = 0 ;
T_1 V_395 = V_402 ;
V_20 = sizeof( V_428 ) ;
V_354 = (union V_353 * ) ( V_377 -> V_2 -> V_163 + V_20 ) ;
V_427 -= V_20 ;
V_20 = F_20 ( V_354 -> V_245 . V_20 ) ;
V_396 = ( void * ) V_354 + V_20 ;
V_427 -= V_20 ;
if ( V_414 -> V_2 -> V_18 == sizeof( T_28 ) )
V_415 = 1 ;
while ( V_427 > 0 ) {
if ( V_415 )
V_395 = V_402 ;
else {
V_395 = F_160 ( V_414 ,
V_396 ,
V_422 ) ;
if ( V_422 && ( V_402 != V_395 ) )
V_422 = 0 ;
}
switch ( V_395 ) {
case V_402 :
F_155 ( V_6 , V_396 ) ;
break;
case V_406 :
V_35 = 1 ;
break;
case V_308 :
V_6 -> V_85 . V_343 |=
V_396 -> V_74 . type ;
break;
case V_425 :
case V_410 :
case V_411 :
default:
break;
}
V_20 = F_20 ( V_396 -> V_74 . V_20 ) ;
V_396 = ( void * ) V_396 + V_20 ;
V_427 -= V_20 ;
}
if ( V_422 && V_6 -> V_429 ) {
V_6 -> V_429 = 0 ;
F_162 ( V_6 -> V_85 . V_430 ) ;
}
F_75 ( & V_377 -> V_205 ) ;
F_47 ( V_377 ) ;
V_6 -> V_426 = NULL ;
return V_35 ;
}
struct V_3 * F_163 ( const struct V_5 * V_6 ,
T_13 V_431 , T_2 V_432 ,
struct V_433 * V_434 )
{
struct V_3 * V_35 = NULL ;
struct V_435 V_436 ;
struct V_433 V_437 ;
T_2 V_149 ;
int V_296 ;
V_149 = ( V_432 + 1 ) * sizeof( T_13 ) ;
V_35 = F_21 ( V_6 , V_300 , 0 , V_149 ) ;
if ( ! V_35 )
return NULL ;
V_436 . V_431 = F_16 ( V_431 ) ;
V_35 -> V_21 . V_438 =
F_9 ( V_35 , sizeof( V_436 ) , & V_436 ) ;
for ( V_296 = 0 ; V_296 < V_432 ; V_296 ++ ) {
V_437 . V_112 = V_434 [ V_296 ] . V_112 ;
V_437 . V_107 = V_434 [ V_296 ] . V_107 ;
F_9 ( V_35 , sizeof( V_437 ) , & V_437 ) ;
}
return V_35 ;
}

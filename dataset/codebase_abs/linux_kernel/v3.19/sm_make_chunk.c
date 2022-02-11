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
struct V_155 * V_156 ,
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
V_17 = F_46 ( V_152 , V_156 , V_16 ) ;
if ( V_17 < 0 )
goto V_160;
}
F_7 ( V_35 , V_161 , V_16 ) ;
F_9 ( V_35 , V_16 , V_152 ) ;
if ( V_16 )
F_23 ( V_152 ) ;
return V_35 ;
V_160:
F_23 ( V_152 ) ;
V_159:
F_47 ( V_35 ) ;
V_35 = NULL ;
V_157:
return V_35 ;
}
static void * F_22 ( struct V_3 * V_4 , int V_18 ,
const void * V_162 )
{
void * V_163 ;
int V_164 = F_20 ( V_4 -> V_150 -> V_20 ) ;
V_163 = F_48 ( V_4 -> V_2 , V_18 ) ;
if ( V_162 )
memcpy ( V_163 , V_162 , V_18 ) ;
else
memset ( V_163 , 0 , V_18 ) ;
V_4 -> V_150 -> V_20 = F_8 ( V_164 + V_18 ) ;
V_4 -> V_165 = F_49 ( V_4 -> V_2 ) ;
return V_163 ;
}
struct V_3 * F_50 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
const T_10 * V_152 ,
const T_2 V_16 )
{
struct V_3 * V_35 ;
struct V_166 V_167 ;
V_35 = F_42 ( V_6 , V_4 , sizeof( T_3 ) + V_16
+ sizeof( T_11 ) ) ;
if ( ! V_35 )
goto V_168;
F_7 ( V_35 , V_169 , V_16
+ sizeof( T_11 ) ) ;
V_167 . type = F_8 ( V_4 -> V_150 -> type ) ;
V_167 . V_20 = V_4 -> V_150 -> V_20 ;
F_9 ( V_35 , V_16 , V_152 ) ;
F_22 ( V_35 , sizeof( T_11 ) , & V_167 ) ;
V_168:
return V_35 ;
}
struct V_3 * F_51 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
struct V_166 * V_170 )
{
struct V_3 * V_35 ;
static const char error [] = L_2 ;
T_2 V_171 = sizeof( error ) + sizeof( T_3 ) +
sizeof( T_11 ) ;
V_35 = F_42 ( V_6 , V_4 , V_171 ) ;
if ( ! V_35 )
goto V_72;
F_7 ( V_35 , V_169 ,
sizeof( error ) + sizeof( T_11 ) ) ;
F_9 ( V_35 , sizeof( error ) , error ) ;
F_22 ( V_35 , sizeof( T_11 ) , V_170 ) ;
V_72:
return V_35 ;
}
struct V_3 * F_52 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_35 ;
static const char error [] = L_3 ;
T_2 V_171 = sizeof( error ) + sizeof( T_3 ) ;
V_35 = F_42 ( V_6 , V_4 , V_171 ) ;
if ( ! V_35 )
goto V_72;
F_7 ( V_35 , V_169 , sizeof( error ) ) ;
F_9 ( V_35 , sizeof( error ) , error ) ;
V_72:
return V_35 ;
}
struct V_3 * F_53 ( const struct V_5 * V_6 ,
const struct V_132 * V_92 )
{
struct V_3 * V_35 ;
T_18 V_172 ;
V_35 = F_21 ( V_6 , V_173 , 0 , sizeof( V_172 ) ) ;
if ( ! V_35 )
goto V_72;
V_172 . V_74 . type = V_174 ;
V_172 . V_74 . V_20 = F_8 ( sizeof( T_18 ) ) ;
V_172 . V_175 = V_92 -> V_176 ;
V_172 . V_177 = V_178 ;
V_172 . V_179 = V_92 -> V_179 ;
V_35 -> V_92 = (struct V_132 * ) V_92 ;
V_35 -> V_21 . V_180 = F_9 ( V_35 , sizeof( V_172 ) ,
& V_172 ) ;
V_72:
return V_35 ;
}
struct V_3 * F_54 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
const void * V_152 , const T_2 V_16 )
{
struct V_3 * V_35 ;
V_35 = F_21 ( V_6 , V_181 , 0 , V_16 ) ;
if ( ! V_35 )
goto V_72;
V_35 -> V_21 . V_180 = F_9 ( V_35 , V_16 , V_152 ) ;
if ( V_4 )
V_35 -> V_92 = V_4 -> V_92 ;
V_72:
return V_35 ;
}
static struct V_3 * F_55 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
T_2 V_182 )
{
struct V_3 * V_35 ;
V_35 = F_21 ( V_6 , V_183 , 0 ,
sizeof( T_3 ) + V_182 ) ;
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
T_2 V_182 = V_6 ? V_6 -> V_184 : 0 ;
if ( ! V_182 )
V_182 = V_185 ;
return F_55 ( V_6 , V_4 , V_182 ) ;
}
struct V_3 * F_57 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
T_1 V_15 , const void * V_152 ,
T_2 V_16 , T_2 V_186 )
{
struct V_3 * V_35 ;
V_35 = F_55 ( V_6 , V_4 , V_16 + V_186 ) ;
if ( ! V_35 )
goto V_72;
F_7 ( V_35 , V_15 , V_16 + V_186 ) ;
F_9 ( V_35 , V_16 , V_152 ) ;
if ( V_186 )
F_22 ( V_35 , V_186 , NULL ) ;
V_72:
return V_35 ;
}
struct V_3 * F_58 ( const struct V_5 * V_6 )
{
struct V_3 * V_35 ;
struct V_187 * V_188 ;
struct V_189 V_190 ;
T_10 * V_191 ;
V_188 = F_59 ( V_6 ) ;
if ( F_60 ( ! V_188 ) )
return NULL ;
V_35 = F_21 ( V_6 , V_70 , 0 ,
V_188 -> V_192 + sizeof( V_193 ) ) ;
if ( ! V_35 )
return NULL ;
V_190 . V_194 = F_8 ( V_188 -> V_194 ) ;
V_190 . V_195 = F_8 ( V_6 -> V_196 ) ;
V_35 -> V_21 . V_190 = F_9 ( V_35 , sizeof( V_193 ) ,
& V_190 ) ;
V_191 = F_48 ( V_35 -> V_2 , V_188 -> V_192 ) ;
memset ( V_191 , 0 , V_188 -> V_192 ) ;
V_35 -> V_150 -> V_20 =
F_8 ( F_20 ( V_35 -> V_150 -> V_20 ) + V_188 -> V_192 ) ;
V_35 -> V_165 = F_49 ( V_35 -> V_2 ) ;
return V_35 ;
}
struct V_3 * F_61 ( struct V_1 * V_2 ,
const struct V_5 * V_6 ,
struct V_197 * V_7 )
{
struct V_3 * V_35 ;
V_35 = F_62 ( V_198 , V_199 ) ;
if ( ! V_35 )
goto V_72;
if ( ! V_7 )
F_34 ( L_4 , V_134 , V_2 ) ;
F_63 ( & V_35 -> V_200 ) ;
V_35 -> V_2 = V_2 ;
V_35 -> V_6 = (struct V_5 * ) V_6 ;
V_35 -> V_201 = 1 ;
V_35 -> V_202 = V_203 ;
F_63 ( & V_35 -> V_204 ) ;
F_63 ( & V_35 -> V_205 ) ;
F_64 ( V_4 ) ;
F_65 ( & V_35 -> V_206 , 1 ) ;
V_72:
return V_35 ;
}
void F_66 ( struct V_3 * V_4 , union V_207 * V_208 ,
union V_207 * V_209 )
{
memcpy ( & V_4 -> V_210 , V_208 , sizeof( union V_207 ) ) ;
memcpy ( & V_4 -> V_209 , V_209 , sizeof( union V_207 ) ) ;
}
const union V_207 * F_67 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_92 ) {
return & V_4 -> V_92 -> V_176 ;
} else {
return & V_4 -> V_210 ;
}
}
static struct V_3 * F_68 ( const struct V_5 * V_6 ,
T_10 type , T_10 V_106 , int V_16 )
{
struct V_3 * V_35 ;
T_19 * V_150 ;
struct V_1 * V_2 ;
struct V_197 * V_7 ;
V_2 = F_69 ( F_18 ( sizeof( T_19 ) + V_16 ) ,
V_199 ) ;
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
V_35 -> V_165 = ( ( T_10 * ) V_150 ) + sizeof( struct V_211 ) ;
if ( F_71 ( type , V_6 ) )
V_35 -> V_212 = 1 ;
return V_35 ;
V_72:
return NULL ;
}
static struct V_3 * F_31 ( const struct V_5 * V_6 ,
T_10 V_106 , int V_16 )
{
return F_68 ( V_6 , V_213 , V_106 , V_16 ) ;
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
F_73 ( ! F_74 ( & V_4 -> V_200 ) ) ;
F_75 ( & V_4 -> V_204 ) ;
F_76 ( V_4 -> V_2 ) ;
F_76 ( V_4 -> V_214 ) ;
F_77 ( V_4 ) ;
F_78 ( V_198 , V_4 ) ;
}
void F_47 ( struct V_3 * V_4 )
{
if ( V_4 -> V_156 )
F_79 ( V_4 -> V_156 ) ;
F_80 ( V_4 ) ;
}
void F_81 ( struct V_3 * V_215 )
{
F_82 ( & V_215 -> V_206 ) ;
}
void F_80 ( struct V_3 * V_215 )
{
if ( F_83 ( & V_215 -> V_206 ) )
F_72 ( V_215 ) ;
}
void * F_9 ( struct V_3 * V_4 , int V_18 , const void * V_162 )
{
void * V_163 ;
void * V_216 ;
int V_164 = F_20 ( V_4 -> V_150 -> V_20 ) ;
int V_217 = F_18 ( V_164 ) - V_164 ;
V_216 = F_48 ( V_4 -> V_2 , V_217 ) ;
V_163 = F_48 ( V_4 -> V_2 , V_18 ) ;
memset ( V_216 , 0 , V_217 ) ;
memcpy ( V_163 , V_162 , V_18 ) ;
V_4 -> V_150 -> V_20 = F_8 ( V_164 + V_217 + V_18 ) ;
V_4 -> V_165 = F_49 ( V_4 -> V_2 ) ;
return V_163 ;
}
static void * F_12 ( struct V_3 * V_4 ,
int V_18 , const void * V_162 )
{
if ( F_11 ( V_4 -> V_2 ) >= V_18 )
return F_9 ( V_4 , V_18 , V_162 ) ;
else
return NULL ;
}
int F_84 ( struct V_3 * V_4 , int V_18 ,
struct V_218 * V_219 )
{
void * V_163 ;
T_20 V_220 ;
V_163 = F_48 ( V_4 -> V_2 , V_18 ) ;
V_220 = F_85 ( V_163 , V_18 , V_219 ) ;
if ( V_220 != V_18 )
return - V_221 ;
V_4 -> V_150 -> V_20 =
F_8 ( F_20 ( V_4 -> V_150 -> V_20 ) + V_18 ) ;
V_4 -> V_165 = F_49 ( V_4 -> V_2 ) ;
return 0 ;
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
V_112 = & V_4 -> V_6 -> V_227 -> V_228 ;
V_156 = V_4 -> V_156 ;
F_38 (lchunk, &msg->chunks, frag_list) {
if ( V_223 -> V_150 -> V_106 & V_118 ) {
V_107 = 0 ;
} else {
if ( V_223 -> V_150 -> V_106 & V_229 )
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
if ( ! V_4 -> V_230 ) {
V_4 -> V_21 . V_119 -> V_111 =
F_16 ( F_90 ( V_4 -> V_6 ) ) ;
V_4 -> V_230 = 1 ;
}
}
struct V_5 * F_91 ( const struct V_29 * V_30 ,
struct V_3 * V_4 ,
T_5 V_26 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
T_21 V_231 ;
struct V_10 * V_11 ;
V_231 = F_92 ( F_67 ( V_4 ) ) ;
V_6 = F_93 ( V_30 , V_30 -> V_8 . V_7 , V_231 , V_26 ) ;
if ( ! V_6 )
goto V_72;
V_6 -> V_232 = 1 ;
V_2 = V_4 -> V_2 ;
V_11 = F_4 ( F_5 ( F_6 ( V_2 ) -> V_13 ) ) ;
if ( F_60 ( ! V_11 ) )
goto V_233;
V_11 -> V_234 ( & V_6 -> V_49 . V_235 , V_2 , 1 ) ;
V_72:
return V_6 ;
V_233:
F_94 ( V_6 ) ;
return NULL ;
}
static T_12 * F_25 ( const struct V_29 * V_30 ,
const struct V_5 * V_6 ,
const struct V_3 * V_236 ,
int * V_82 ,
const T_10 * V_237 , int V_37 )
{
T_12 * V_35 ;
struct V_238 * V_81 ;
struct V_239 V_240 ;
int V_241 , V_242 ;
V_241 = sizeof( T_11 ) +
( sizeof( struct V_238 ) -
sizeof( struct V_243 ) ) ;
V_242 = sizeof( struct V_243 )
+ F_20 ( V_236 -> V_150 -> V_20 ) + V_37 ;
if ( V_242 % V_244 )
V_242 += V_244
- ( V_242 % V_244 ) ;
* V_82 = V_241 + V_242 ;
V_35 = F_95 ( * V_82 , V_199 ) ;
if ( ! V_35 )
goto V_72;
V_81 = (struct V_238 * ) V_35 -> V_245 ;
V_35 -> V_246 . type = V_247 ;
V_35 -> V_246 . V_20 = F_8 ( * V_82 ) ;
V_81 -> V_49 = V_6 -> V_49 ;
V_81 -> V_49 . V_248 = V_37 ;
V_81 -> V_49 . V_87 = V_6 -> V_85 . V_87 ;
V_81 -> V_49 . V_67 = V_6 -> V_85 . V_67 ;
V_81 -> V_49 . V_249 = F_96 ( V_6 -> V_250 ,
F_97 () ) ;
memcpy ( & V_81 -> V_49 . V_251 [ 0 ] , V_236 -> V_150 ,
F_20 ( V_236 -> V_150 -> V_20 ) ) ;
memcpy ( ( T_10 * ) & V_81 -> V_49 . V_251 [ 0 ] +
F_20 ( V_236 -> V_150 -> V_20 ) , V_237 , V_37 ) ;
if ( F_17 ( V_30 -> V_8 . V_7 ) -> V_191 ) {
struct V_252 V_253 ;
F_98 ( & V_240 , & V_81 -> V_49 , V_242 ) ;
V_253 . V_254 = F_17 ( V_30 -> V_8 . V_7 ) -> V_191 ;
V_253 . V_106 = 0 ;
if ( F_99 ( V_253 . V_254 , V_30 -> V_255 ,
sizeof( V_30 -> V_255 ) ) ||
F_100 ( & V_253 , & V_240 , V_242 , V_81 -> V_256 ) )
goto V_257;
}
return V_35 ;
V_257:
F_23 ( V_35 ) ;
V_72:
* V_82 = 0 ;
return NULL ;
}
struct V_5 * F_101 (
const struct V_29 * V_30 ,
const struct V_5 * V_6 ,
struct V_3 * V_4 , T_5 V_26 ,
int * error , struct V_3 * * V_258 )
{
struct V_5 * V_35 = NULL ;
struct V_238 * V_81 ;
struct V_243 * V_259 ;
int V_241 , V_242 , V_260 ;
T_10 * V_261 = V_30 -> V_261 ;
struct V_239 V_240 ;
unsigned int V_18 ;
T_21 V_231 ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_22 V_262 ;
struct V_252 V_253 ;
V_241 = sizeof( T_19 ) +
( sizeof( struct V_238 ) -
sizeof( struct V_243 ) ) ;
V_242 = F_20 ( V_4 -> V_150 -> V_20 ) - V_241 ;
V_260 = V_241 + sizeof( struct V_243 ) ;
V_18 = F_20 ( V_4 -> V_150 -> V_20 ) ;
if ( V_18 < V_260 + sizeof( struct V_211 ) )
goto V_263;
if ( V_242 % V_244 )
goto V_263;
V_81 = V_4 -> V_21 . V_94 ;
V_259 = & V_81 -> V_49 ;
if ( ! F_17 ( V_30 -> V_8 . V_7 ) -> V_191 )
goto V_264;
F_98 ( & V_240 , V_259 , V_242 ) ;
V_253 . V_254 = F_17 ( V_30 -> V_8 . V_7 ) -> V_191 ;
V_253 . V_106 = 0 ;
memset ( V_261 , 0x00 , V_265 ) ;
if ( F_99 ( V_253 . V_254 , V_30 -> V_255 ,
sizeof( V_30 -> V_255 ) ) ||
F_100 ( & V_253 , & V_240 , V_242 , V_261 ) ) {
* error = - V_266 ;
goto V_233;
}
if ( memcmp ( V_261 , V_81 -> V_256 , V_265 ) ) {
* error = - V_267 ;
goto V_233;
}
V_264:
if ( F_102 ( V_4 -> V_268 -> V_269 ) != V_259 -> V_50 ) {
* error = - V_270 ;
goto V_233;
}
if ( V_4 -> V_268 -> V_210 != V_259 -> V_235 . V_271 . V_272 ||
F_20 ( V_4 -> V_268 -> V_209 ) != V_259 -> V_273 ) {
* error = - V_274 ;
goto V_233;
}
if ( F_103 ( V_30 -> V_8 . V_7 , V_275 ) )
V_262 = F_104 ( V_2 ) ;
else
V_262 = F_97 () ;
if ( ! V_6 && F_105 ( V_259 -> V_249 , V_262 ) ) {
V_18 = F_20 ( V_4 -> V_150 -> V_20 ) ;
* V_258 = F_55 ( V_6 , V_4 , V_18 ) ;
if ( * V_258 ) {
T_23 V_276 = F_106 ( F_107 ( V_262 , V_259 -> V_249 ) ) ;
T_17 V_277 = F_16 ( V_276 ) ;
F_7 ( * V_258 , V_278 ,
sizeof( V_277 ) ) ;
F_9 ( * V_258 , sizeof( V_277 ) , & V_277 ) ;
* error = - V_279 ;
} else
* error = - V_266 ;
goto V_233;
}
V_231 = F_92 ( F_67 ( V_4 ) ) ;
V_35 = F_93 ( V_30 , V_30 -> V_8 . V_7 , V_231 , V_26 ) ;
if ( ! V_35 ) {
* error = - V_266 ;
goto V_233;
}
V_35 -> V_85 . V_280 = F_20 ( V_4 -> V_268 -> V_210 ) ;
memcpy ( & V_35 -> V_49 , V_259 , sizeof( * V_259 ) ) ;
if ( F_108 ( V_35 , V_259 ,
V_199 ) < 0 ) {
* error = - V_266 ;
goto V_233;
}
if ( F_74 ( & V_35 -> V_8 . V_83 . V_281 ) ) {
F_109 ( & V_35 -> V_8 . V_83 , & V_4 -> V_209 ,
V_282 , V_199 ) ;
}
V_35 -> V_283 = V_35 -> V_49 . V_57 ;
V_35 -> V_284 = V_35 -> V_283 - 1 ;
V_35 -> V_285 = V_35 -> V_49 . V_57 ;
V_35 -> V_286 = V_35 -> V_284 ;
V_35 -> V_85 . V_87 = V_35 -> V_49 . V_87 ;
V_35 -> V_85 . V_67 = V_35 -> V_49 . V_67 ;
return V_35 ;
V_233:
if ( V_35 )
F_94 ( V_35 ) ;
return NULL ;
V_263:
* error = - V_287 ;
goto V_233;
}
static int F_110 ( const struct V_5 * V_6 ,
T_24 V_288 ,
struct V_3 * V_4 ,
struct V_3 * * V_258 )
{
struct V_289 V_290 ;
T_4 V_18 ;
V_18 = F_18 ( sizeof( V_290 ) ) ;
if ( ! * V_258 )
* V_258 = F_55 ( V_6 , V_4 , V_18 ) ;
if ( * V_258 ) {
V_290 . V_291 = F_16 ( 1 ) ;
V_290 . type = V_288 ;
F_7 ( * V_258 , V_292 ,
sizeof( V_290 ) ) ;
F_9 ( * V_258 , sizeof( V_290 ) , & V_290 ) ;
}
return 0 ;
}
static int F_111 ( const struct V_5 * V_6 ,
struct V_3 * V_4 ,
struct V_3 * * V_258 )
{
if ( ! * V_258 )
* V_258 = F_55 ( V_6 , V_4 , 0 ) ;
if ( * V_258 )
F_7 ( * V_258 , V_293 , 0 ) ;
return 0 ;
}
static int F_112 ( const struct V_5 * V_6 ,
struct V_166 * V_170 ,
const struct V_3 * V_4 ,
struct V_3 * * V_258 )
{
if ( * V_258 )
F_47 ( * V_258 ) ;
* V_258 = F_51 ( V_6 , V_4 , V_170 ) ;
return 0 ;
}
static int F_113 ( const struct V_5 * V_6 ,
union V_32 V_170 ,
struct V_3 * V_4 ,
struct V_3 * * V_258 )
{
T_4 V_18 = F_20 ( V_170 . V_246 -> V_20 ) ;
if ( * V_258 )
F_47 ( * V_258 ) ;
* V_258 = F_55 ( V_6 , V_4 , V_18 ) ;
if ( * V_258 ) {
F_7 ( * V_258 , V_294 , V_18 ) ;
F_9 ( * V_258 , V_18 , V_170 . V_75 ) ;
}
return 0 ;
}
static int F_114 ( struct V_28 * V_28 , union V_32 V_170 )
{
T_4 V_44 = F_20 ( V_170 . V_246 -> V_20 ) - sizeof( T_11 ) ;
int V_295 = 0 ;
int V_296 = 0 ;
int V_297 ;
for ( V_297 = 0 ; V_297 < V_44 ; V_297 ++ ) {
switch ( V_170 . V_298 -> V_299 [ V_297 ] ) {
case V_70 :
V_295 = 1 ;
break;
case V_65 :
case V_66 :
V_296 = 1 ;
break;
}
}
if ( V_28 -> V_61 . V_300 )
return 1 ;
if ( V_28 -> V_61 . V_64 && ! V_295 && V_296 )
return 0 ;
return 1 ;
}
static void F_115 ( struct V_5 * V_6 ,
union V_32 V_170 )
{
struct V_28 * V_28 = F_14 ( V_6 -> V_8 . V_7 ) ;
T_4 V_44 = F_20 ( V_170 . V_246 -> V_20 ) - sizeof( T_11 ) ;
int V_297 ;
for ( V_297 = 0 ; V_297 < V_44 ; V_297 ++ ) {
switch ( V_170 . V_298 -> V_299 [ V_297 ] ) {
case V_301 :
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
static T_25 F_116 ( const struct V_5 * V_6 ,
union V_32 V_170 ,
struct V_3 * V_4 ,
struct V_3 * * V_258 )
{
int V_35 = V_302 ;
switch ( V_170 . V_246 -> type & V_303 ) {
case V_304 :
V_35 = V_305 ;
break;
case V_306 :
break;
case V_307 :
V_35 = V_305 ;
case V_308 :
if ( NULL == * V_258 )
* V_258 = F_56 ( V_6 , V_4 ) ;
if ( * V_258 ) {
if ( ! F_10 ( * V_258 , V_309 ,
F_18 ( F_20 ( V_170 . V_246 -> V_20 ) ) ) )
F_12 ( * V_258 ,
F_18 ( F_20 ( V_170 . V_246 -> V_20 ) ) ,
V_170 . V_75 ) ;
} else {
V_35 = V_266 ;
}
break;
default:
break;
}
return V_35 ;
}
static T_25 F_117 ( struct V_28 * V_28 ,
const struct V_29 * V_30 ,
const struct V_5 * V_6 ,
union V_32 V_170 ,
T_26 V_310 ,
struct V_3 * V_4 ,
struct V_3 * * V_157 )
{
struct V_311 * V_312 ;
int V_35 = V_302 ;
T_4 V_313 , V_314 = 0 ;
int V_297 ;
switch ( V_170 . V_246 -> type ) {
case V_315 :
case V_316 :
case V_317 :
case V_76 :
case V_247 :
case V_174 :
case V_318 :
case V_319 :
case V_78 :
break;
case V_77 :
if ( ! F_114 ( V_28 , V_170 ) )
return V_320 ;
break;
case V_321 :
if ( V_28 -> V_61 . V_64 )
break;
goto V_322;
case V_323 :
F_113 ( V_6 , V_170 , V_4 , V_157 ) ;
V_35 = V_320 ;
break;
case V_324 :
if ( V_28 -> V_61 . V_62 )
break;
goto V_322;
case V_325 :
if ( ! V_30 -> V_68 )
goto V_322;
if ( V_326 !=
F_20 ( V_170 . V_246 -> V_20 ) - sizeof( T_11 ) ) {
F_112 ( V_6 , V_170 . V_246 ,
V_4 , V_157 ) ;
V_35 = V_320 ;
}
break;
case V_327 :
if ( ! V_30 -> V_68 )
goto V_322;
if ( 260 < F_20 ( V_170 . V_246 -> V_20 ) ) {
F_112 ( V_6 , V_170 . V_246 ,
V_4 , V_157 ) ;
V_35 = V_320 ;
}
break;
case V_328 :
if ( ! V_30 -> V_68 )
goto V_322;
V_312 = (struct V_311 * ) V_170 . V_246 ;
V_313 = ( F_20 ( V_170 . V_246 -> V_20 ) - sizeof( T_11 ) ) >> 1 ;
for ( V_297 = 0 ; V_297 < V_313 ; V_297 ++ ) {
V_314 = F_20 ( V_312 -> V_329 [ V_297 ] ) ;
if ( V_314 == V_330 )
break;
}
if ( V_314 != V_330 ) {
F_112 ( V_6 , V_170 . V_246 , V_4 ,
V_157 ) ;
V_35 = V_320 ;
}
break;
V_322:
default:
F_34 ( L_5 ,
V_134 , F_20 ( V_170 . V_246 -> type ) , V_310 ) ;
V_35 = F_116 ( V_6 , V_170 , V_4 , V_157 ) ;
break;
}
return V_35 ;
}
int F_118 ( struct V_28 * V_28 , const struct V_29 * V_30 ,
const struct V_5 * V_6 , T_26 V_310 ,
T_27 * V_251 , struct V_3 * V_4 ,
struct V_3 * * V_258 )
{
union V_32 V_170 ;
bool V_331 = false ;
int V_332 ;
if ( V_251 -> V_73 . V_53 == 0 ||
V_251 -> V_73 . V_55 == 0 ||
V_251 -> V_73 . V_48 == 0 ||
F_102 ( V_251 -> V_73 . V_51 ) < V_333 )
return F_111 ( V_6 , V_4 , V_258 ) ;
F_119 (param, peer_init, init_hdr.params) {
if ( V_170 . V_246 -> type == V_247 )
V_331 = true ;
}
if ( V_170 . V_75 != ( void * ) V_4 -> V_165 )
return F_112 ( V_6 , V_170 . V_246 , V_4 , V_258 ) ;
if ( ( V_90 == V_310 ) && ! V_331 )
return F_110 ( V_6 , V_247 ,
V_4 , V_258 ) ;
F_119 (param, peer_init, init_hdr.params) {
V_332 = F_117 ( V_28 , V_30 , V_6 , V_170 , V_310 ,
V_4 , V_258 ) ;
switch ( V_332 ) {
case V_320 :
case V_266 :
return 0 ;
case V_305 :
return 1 ;
case V_302 :
default:
break;
}
}
return 1 ;
}
int F_120 ( struct V_5 * V_6 , struct V_3 * V_4 ,
const union V_207 * V_235 ,
T_27 * V_251 , T_5 V_26 )
{
struct V_28 * V_28 = F_14 ( V_6 -> V_8 . V_7 ) ;
union V_32 V_170 ;
struct V_132 * V_92 ;
struct V_334 * V_335 , * V_232 ;
struct V_10 * V_11 ;
union V_207 V_336 ;
char * V_81 ;
int V_337 = 0 ;
if ( ! F_121 ( V_6 , V_235 , V_26 , V_338 ) )
goto V_339;
if ( F_122 ( F_67 ( V_4 ) , V_235 ) )
V_337 = 1 ;
F_119 (param, peer_init, init_hdr.params) {
if ( ! V_337 && ( V_170 . V_246 -> type == V_315 ||
V_170 . V_246 -> type == V_316 ) ) {
V_11 = F_4 ( F_123 ( V_170 . V_246 -> type ) ) ;
V_11 -> V_340 ( & V_336 , V_170 . V_336 ,
V_4 -> V_268 -> V_210 , 0 ) ;
if ( F_122 ( F_67 ( V_4 ) , & V_336 ) )
V_337 = 1 ;
}
if ( ! F_124 ( V_6 , V_170 , V_235 , V_26 ) )
goto V_341;
}
if ( ! V_337 )
goto V_341;
if ( V_6 -> V_85 . V_89 && ( ! V_6 -> V_85 . V_342 ||
! V_6 -> V_85 . V_343 ) )
V_6 -> V_85 . V_89 = 0 ;
if ( ! V_28 -> V_61 . V_300 &&
( V_6 -> V_85 . V_88 && ! V_6 -> V_85 . V_89 ) ) {
V_6 -> V_85 . V_344 |= ( V_345 |
V_346 |
V_321 ) ;
V_6 -> V_85 . V_88 = 0 ;
goto V_341;
}
F_125 (pos, temp, &asoc->peer.transport_addr_list) {
V_92 = F_126 ( V_335 , struct V_132 , V_347 ) ;
if ( V_92 -> V_348 == V_349 ) {
F_127 ( V_6 , V_92 ) ;
}
}
V_6 -> V_85 . V_297 . V_48 =
F_102 ( V_251 -> V_73 . V_48 ) ;
V_6 -> V_85 . V_297 . V_51 =
F_102 ( V_251 -> V_73 . V_51 ) ;
V_6 -> V_85 . V_297 . V_53 =
F_20 ( V_251 -> V_73 . V_53 ) ;
V_6 -> V_85 . V_297 . V_55 =
F_20 ( V_251 -> V_73 . V_55 ) ;
V_6 -> V_85 . V_297 . V_57 =
F_102 ( V_251 -> V_73 . V_57 ) ;
if ( V_6 -> V_49 . V_54 >
F_20 ( V_251 -> V_73 . V_55 ) ) {
V_6 -> V_49 . V_54 =
F_20 ( V_251 -> V_73 . V_55 ) ;
}
if ( V_6 -> V_49 . V_56 >
F_20 ( V_251 -> V_73 . V_53 ) ) {
V_6 -> V_49 . V_56 =
F_20 ( V_251 -> V_73 . V_53 ) ;
}
V_6 -> V_49 . V_350 = V_6 -> V_85 . V_297 . V_48 ;
V_6 -> V_85 . V_52 = V_6 -> V_85 . V_297 . V_51 ;
V_81 = V_6 -> V_85 . V_81 ;
if ( V_81 ) {
V_6 -> V_85 . V_81 = F_128 ( V_81 , V_6 -> V_85 . V_82 , V_26 ) ;
if ( ! V_6 -> V_85 . V_81 )
goto V_341;
}
F_38 (transport, &asoc->peer.transport_addr_list,
transports) {
V_92 -> V_351 = V_6 -> V_85 . V_297 . V_51 ;
}
if ( ! F_129 ( & V_6 -> V_85 . V_128 , V_352 ,
V_6 -> V_85 . V_297 . V_57 , V_26 ) )
goto V_341;
if ( ! V_6 -> V_232 ) {
int error ;
V_6 -> V_227 = F_130 ( V_6 -> V_49 . V_56 ,
V_6 -> V_49 . V_54 , V_26 ) ;
if ( ! V_6 -> V_227 )
goto V_341;
error = F_131 ( V_6 , V_26 ) ;
if ( error )
goto V_341;
}
V_6 -> V_85 . V_285 = V_6 -> V_85 . V_297 . V_57 - 1 ;
return 1 ;
V_341:
F_125 (pos, temp, &asoc->peer.transport_addr_list) {
V_92 = F_126 ( V_335 , struct V_132 , V_347 ) ;
if ( V_92 -> V_348 != V_338 )
F_127 ( V_6 , V_92 ) ;
}
V_339:
return 0 ;
}
static int F_124 ( struct V_5 * V_6 ,
union V_32 V_170 ,
const union V_207 * V_235 ,
T_5 V_26 )
{
struct V_28 * V_28 = F_14 ( V_6 -> V_8 . V_7 ) ;
union V_207 V_336 ;
int V_297 ;
T_4 V_40 ;
int V_35 = 1 ;
T_21 V_231 ;
T_28 V_353 ;
struct V_10 * V_11 ;
union V_354 * V_355 ;
struct V_132 * V_356 ;
struct V_29 * V_30 = V_6 -> V_30 ;
switch ( V_170 . V_246 -> type ) {
case V_316 :
if ( V_357 != V_6 -> V_8 . V_7 -> V_358 )
break;
goto V_359;
case V_315 :
if ( F_132 ( V_6 -> V_8 . V_7 ) )
break;
V_359:
V_11 = F_4 ( F_123 ( V_170 . V_246 -> type ) ) ;
V_11 -> V_340 ( & V_336 , V_170 . V_336 , F_8 ( V_6 -> V_85 . V_280 ) , 0 ) ;
V_231 = F_92 ( V_235 ) ;
if ( F_133 ( V_28 , & V_336 , V_231 ) )
if ( ! F_121 ( V_6 , & V_336 , V_26 , V_360 ) )
return 0 ;
break;
case V_317 :
if ( ! V_28 -> V_61 . V_361 )
break;
V_353 = F_102 ( V_170 . V_362 -> V_363 ) ;
V_6 -> V_250 = F_134 ( V_6 -> V_250 , V_353 ) ;
break;
case V_323 :
F_34 ( L_6 , V_134 ) ;
break;
case V_76 :
V_6 -> V_85 . V_364 = 0 ;
V_6 -> V_85 . V_365 = 0 ;
if ( V_235 -> V_366 . V_367 == V_368 )
V_6 -> V_85 . V_365 = 1 ;
else if ( V_235 -> V_366 . V_367 == V_369 )
V_6 -> V_85 . V_364 = 1 ;
V_40 = F_20 ( V_170 . V_246 -> V_20 ) - sizeof( T_11 ) ;
if ( V_40 )
V_40 /= sizeof( T_4 ) ;
for ( V_297 = 0 ; V_297 < V_40 ; ++ V_297 ) {
switch ( V_170 . V_40 -> V_41 [ V_297 ] ) {
case V_315 :
V_6 -> V_85 . V_364 = 1 ;
break;
case V_316 :
if ( V_357 == V_6 -> V_8 . V_7 -> V_358 )
V_6 -> V_85 . V_365 = 1 ;
break;
case V_323 :
V_6 -> V_85 . V_370 = 1 ;
break;
default:
break;
}
}
break;
case V_247 :
V_6 -> V_85 . V_82 =
F_20 ( V_170 . V_246 -> V_20 ) - sizeof( T_11 ) ;
V_6 -> V_85 . V_81 = V_170 . V_81 -> V_245 ;
break;
case V_174 :
break;
case V_318 :
break;
case V_319 :
V_6 -> V_85 . V_86 = 1 ;
break;
case V_78 :
V_6 -> V_85 . V_67 = F_102 ( V_170 . V_371 -> V_67 ) ;
break;
case V_321 :
if ( ! V_28 -> V_61 . V_64 )
goto V_372;
V_355 = V_170 . V_75 + sizeof( V_373 ) ;
V_11 = F_4 ( F_123 ( V_355 -> V_246 . type ) ) ;
if ( V_11 == NULL )
break;
V_11 -> V_340 ( & V_336 , V_355 ,
F_8 ( V_6 -> V_85 . V_280 ) , 0 ) ;
if ( ! V_11 -> V_374 ( & V_336 , NULL , NULL ) )
break;
V_356 = F_135 ( V_6 , & V_336 ) ;
if ( ! V_356 )
break;
F_136 ( V_6 , V_356 ) ;
break;
case V_77 :
F_115 ( V_6 , V_170 ) ;
break;
case V_324 :
if ( V_28 -> V_61 . V_62 ) {
V_6 -> V_85 . V_87 = 1 ;
break;
}
goto V_372;
case V_325 :
if ( ! V_30 -> V_68 )
goto V_372;
V_6 -> V_85 . V_342 = F_128 ( V_170 . V_246 ,
F_20 ( V_170 . V_246 -> V_20 ) , V_26 ) ;
if ( ! V_6 -> V_85 . V_342 ) {
V_35 = 0 ;
break;
}
break;
case V_328 :
if ( ! V_30 -> V_68 )
goto V_372;
V_6 -> V_85 . V_343 = F_128 ( V_170 . V_246 ,
F_20 ( V_170 . V_246 -> V_20 ) , V_26 ) ;
if ( ! V_6 -> V_85 . V_343 ) {
V_35 = 0 ;
break;
}
F_137 ( V_6 , V_170 . V_375 ) ;
break;
case V_327 :
if ( ! V_30 -> V_68 )
goto V_372;
V_6 -> V_85 . V_376 = F_128 ( V_170 . V_246 ,
F_20 ( V_170 . V_246 -> V_20 ) , V_26 ) ;
if ( ! V_6 -> V_85 . V_376 )
V_35 = 0 ;
break;
V_372:
default:
F_34 ( L_7 ,
V_134 , F_20 ( V_170 . V_246 -> type ) , V_6 ) ;
break;
}
return V_35 ;
}
T_13 F_138 ( const struct V_29 * V_30 )
{
T_13 V_377 ;
do {
F_139 ( & V_377 , sizeof( T_13 ) ) ;
} while ( V_377 == 0 );
return V_377 ;
}
T_13 F_140 ( const struct V_29 * V_30 )
{
T_13 V_35 ;
F_139 ( & V_35 , sizeof( T_13 ) ) ;
return V_35 ;
}
static struct V_3 * F_141 ( struct V_5 * V_6 ,
union V_207 * V_336 ,
int V_27 )
{
T_29 V_378 ;
struct V_3 * V_35 ;
int V_20 = sizeof( V_378 ) + V_27 ;
union V_354 V_379 ;
int V_380 ;
struct V_10 * V_11 = F_4 ( V_336 -> V_271 . V_381 ) ;
V_380 = V_11 -> V_382 ( V_336 , & V_379 ) ;
if ( ! V_380 )
return NULL ;
V_20 += V_380 ;
V_35 = F_21 ( V_6 , V_65 , 0 , V_20 ) ;
if ( ! V_35 )
return NULL ;
V_378 . V_383 = F_16 ( V_6 -> V_285 ++ ) ;
V_35 -> V_21 . V_384 =
F_9 ( V_35 , sizeof( V_378 ) , & V_378 ) ;
V_35 -> V_74 . V_75 =
F_9 ( V_35 , V_380 , & V_379 ) ;
return V_35 ;
}
struct V_3 * F_142 ( struct V_5 * V_6 ,
union V_207 * V_385 ,
struct V_386 * V_33 ,
int V_387 ,
T_1 V_106 )
{
V_373 V_170 ;
struct V_3 * V_35 ;
union V_354 V_355 ;
union V_207 * V_336 ;
void * V_388 ;
struct V_10 * V_11 ;
int V_389 = sizeof( V_170 ) ;
int V_390 = 0 ;
int V_391 = 0 ;
int V_297 ;
int V_392 = 0 ;
V_388 = V_33 ;
for ( V_297 = 0 ; V_297 < V_387 ; V_297 ++ ) {
V_336 = V_388 ;
V_11 = F_4 ( V_336 -> V_271 . V_381 ) ;
V_390 = V_11 -> V_382 ( V_336 , & V_355 ) ;
V_391 += V_389 ;
V_391 += V_390 ;
V_388 += V_11 -> V_393 ;
if ( V_6 -> V_394 && ! V_392 ) {
V_391 += V_389 ;
V_391 += V_390 ;
V_392 = 1 ;
F_34 ( L_8
L_9 ,
V_134 , V_391 ) ;
}
}
V_35 = F_141 ( V_6 , V_385 , V_391 ) ;
if ( ! V_35 )
return NULL ;
V_388 = V_33 ;
for ( V_297 = 0 ; V_297 < V_387 ; V_297 ++ ) {
V_336 = V_388 ;
V_11 = F_4 ( V_336 -> V_271 . V_381 ) ;
V_390 = V_11 -> V_382 ( V_336 , & V_355 ) ;
V_170 . V_74 . type = V_106 ;
V_170 . V_74 . V_20 = F_8 ( V_389 + V_390 ) ;
V_170 . V_395 = V_297 ;
F_9 ( V_35 , V_389 , & V_170 ) ;
F_9 ( V_35 , V_390 , & V_355 ) ;
V_388 += V_11 -> V_393 ;
}
if ( V_106 == V_345 && V_392 ) {
V_336 = V_6 -> V_394 ;
V_11 = F_4 ( V_336 -> V_271 . V_381 ) ;
V_390 = V_11 -> V_382 ( V_336 , & V_355 ) ;
V_170 . V_74 . type = V_346 ;
V_170 . V_74 . V_20 = F_8 ( V_389 + V_390 ) ;
V_170 . V_395 = V_297 ;
F_9 ( V_35 , V_389 , & V_170 ) ;
F_9 ( V_35 , V_390 , & V_355 ) ;
}
return V_35 ;
}
struct V_3 * F_143 ( struct V_5 * V_6 ,
union V_207 * V_336 )
{
V_373 V_170 ;
struct V_3 * V_35 ;
int V_18 = sizeof( V_170 ) ;
union V_354 V_379 ;
int V_380 ;
struct V_10 * V_11 = F_4 ( V_336 -> V_271 . V_381 ) ;
V_380 = V_11 -> V_382 ( V_336 , & V_379 ) ;
if ( ! V_380 )
return NULL ;
V_18 += V_380 ;
V_35 = F_141 ( V_6 , V_336 , V_18 ) ;
if ( ! V_35 )
return NULL ;
V_170 . V_74 . type = V_321 ;
V_170 . V_74 . V_20 = F_8 ( V_18 ) ;
V_170 . V_395 = 0 ;
F_9 ( V_35 , sizeof( V_170 ) , & V_170 ) ;
F_9 ( V_35 , V_380 , & V_379 ) ;
return V_35 ;
}
static struct V_3 * F_144 ( const struct V_5 * V_6 ,
T_13 V_383 , int V_27 )
{
T_29 V_378 ;
struct V_3 * V_35 ;
int V_20 = sizeof( V_378 ) + V_27 ;
V_35 = F_21 ( V_6 , V_66 , 0 , V_20 ) ;
if ( ! V_35 )
return NULL ;
V_378 . V_383 = F_16 ( V_383 ) ;
V_35 -> V_21 . V_384 =
F_9 ( V_35 , sizeof( V_378 ) , & V_378 ) ;
return V_35 ;
}
static void F_145 ( struct V_3 * V_4 , T_17 V_395 ,
T_1 V_396 , V_373 * V_397 )
{
V_373 V_398 ;
T_3 V_399 ;
int V_400 = 0 ;
int V_401 = 0 ;
T_1 V_402 ;
if ( V_403 == V_396 ) {
V_402 = V_404 ;
} else {
V_402 = V_405 ;
V_401 = sizeof( V_399 ) ;
if ( V_397 )
V_400 =
F_20 ( V_397 -> V_74 . V_20 ) ;
}
V_398 . V_74 . type = V_402 ;
V_398 . V_74 . V_20 = F_8 ( sizeof( V_398 ) +
V_401 +
V_400 ) ;
V_398 . V_395 = V_395 ;
F_9 ( V_4 , sizeof( V_398 ) , & V_398 ) ;
if ( V_403 == V_396 )
return;
V_399 . V_19 = V_396 ;
V_399 . V_20 = F_8 ( V_401 + V_400 ) ;
F_9 ( V_4 , V_401 , & V_399 ) ;
if ( V_397 )
F_9 ( V_4 , V_400 , V_397 ) ;
}
static T_1 F_146 ( struct V_5 * V_6 ,
struct V_3 * V_378 ,
V_373 * V_397 )
{
struct V_132 * V_85 ;
struct V_10 * V_11 ;
union V_207 V_336 ;
union V_354 * V_355 ;
V_355 = ( void * ) V_397 + sizeof( V_373 ) ;
if ( V_397 -> V_74 . type != V_345 &&
V_397 -> V_74 . type != V_346 &&
V_397 -> V_74 . type != V_321 )
return V_309 ;
switch ( V_355 -> V_246 . type ) {
case V_316 :
if ( ! V_6 -> V_85 . V_365 )
return V_294 ;
break;
case V_315 :
if ( ! V_6 -> V_85 . V_364 )
return V_294 ;
break;
default:
return V_294 ;
}
V_11 = F_4 ( F_123 ( V_355 -> V_246 . type ) ) ;
if ( F_60 ( ! V_11 ) )
return V_294 ;
V_11 -> V_340 ( & V_336 , V_355 , F_8 ( V_6 -> V_85 . V_280 ) , 0 ) ;
if ( ! V_11 -> V_406 ( & V_336 ) && ! V_11 -> V_374 ( & V_336 , NULL , V_378 -> V_2 ) )
return V_294 ;
switch ( V_397 -> V_74 . type ) {
case V_345 :
if ( V_11 -> V_406 ( & V_336 ) )
memcpy ( & V_336 , & V_378 -> V_210 , sizeof( V_336 ) ) ;
V_85 = F_121 ( V_6 , & V_336 , V_199 , V_360 ) ;
if ( ! V_85 )
return V_407 ;
if ( ! F_147 ( & V_85 -> V_408 , F_148 ( V_85 ) ) )
F_149 ( V_85 ) ;
V_6 -> V_409 = V_85 ;
break;
case V_346 :
if ( V_6 -> V_85 . V_410 == 1 )
return V_411 ;
if ( F_122 ( & V_378 -> V_210 , & V_336 ) )
return V_412 ;
if ( V_11 -> V_406 ( & V_336 ) ) {
F_136 ( V_6 , V_378 -> V_92 ) ;
F_150 ( V_6 ,
V_378 -> V_92 ) ;
} else
F_151 ( V_6 , & V_336 ) ;
break;
case V_321 :
if ( V_11 -> V_406 ( & V_336 ) )
memcpy ( & V_336 . V_271 , F_67 ( V_378 ) , sizeof( V_336 ) ) ;
V_85 = F_135 ( V_6 , & V_336 ) ;
if ( ! V_85 )
return V_294 ;
F_136 ( V_6 , V_85 ) ;
break;
}
return V_403 ;
}
bool F_152 ( const struct V_5 * V_6 ,
struct V_3 * V_4 , bool V_413 ,
struct V_166 * * V_258 )
{
T_30 * V_414 = ( T_30 * ) V_4 -> V_150 ;
union V_32 V_170 ;
bool V_415 = false ;
F_119 (param, addip, addip_hdr.params) {
T_2 V_20 = F_20 ( V_170 . V_246 -> V_20 ) ;
* V_258 = V_170 . V_246 ;
switch ( V_170 . V_246 -> type ) {
case V_405 :
break;
case V_315 :
if ( V_20 != sizeof( V_416 ) )
return false ;
V_415 = true ;
break;
case V_316 :
if ( V_20 != sizeof( V_417 ) )
return false ;
V_415 = true ;
break;
case V_345 :
case V_346 :
case V_321 :
if ( V_413 && ! V_415 )
return false ;
V_20 = F_20 ( V_170 . V_414 -> V_74 . V_20 ) ;
if ( V_20 < sizeof( V_373 ) +
sizeof( T_11 ) )
return false ;
break;
case V_404 :
case V_78 :
if ( V_20 != sizeof( V_373 ) )
return false ;
break;
default:
return false ;
}
}
if ( V_413 && ! V_415 )
return false ;
if ( ! V_413 && V_415 )
return false ;
if ( V_170 . V_75 != V_4 -> V_165 )
return false ;
return true ;
}
struct V_3 * F_153 ( struct V_5 * V_6 ,
struct V_3 * V_378 )
{
T_30 * V_414 = ( T_30 * ) V_378 -> V_150 ;
bool V_418 = true ;
union V_32 V_170 ;
T_29 * V_419 ;
union V_354 * V_355 ;
V_373 * V_397 ;
struct V_3 * V_420 ;
T_1 V_396 ;
int V_20 = 0 ;
int V_110 ;
T_13 V_383 ;
V_110 = F_20 ( V_378 -> V_150 -> V_20 ) - sizeof( T_19 ) ;
V_419 = ( T_29 * ) V_378 -> V_2 -> V_162 ;
V_383 = F_102 ( V_419 -> V_383 ) ;
V_20 = sizeof( T_29 ) ;
V_355 = (union V_354 * ) ( V_378 -> V_2 -> V_162 + V_20 ) ;
V_110 -= V_20 ;
V_20 = F_20 ( V_355 -> V_246 . V_20 ) ;
V_397 = ( void * ) V_355 + V_20 ;
V_110 -= V_20 ;
V_420 = F_144 ( V_6 , V_383 , V_110 * 4 ) ;
if ( ! V_420 )
goto V_421;
F_119 (param, addip, addip_hdr.params) {
if ( V_170 . V_246 -> type == V_315 ||
V_170 . V_246 -> type == V_316 )
continue;
V_396 = F_146 ( V_6 , V_378 ,
V_170 . V_414 ) ;
if ( V_396 != V_403 )
V_418 = false ;
if ( ! V_418 )
F_145 ( V_420 , V_170 . V_414 -> V_395 ,
V_396 , V_170 . V_414 ) ;
if ( V_396 == V_407 )
goto V_421;
}
V_421:
V_6 -> V_85 . V_285 ++ ;
if ( V_420 ) {
F_81 ( V_420 ) ;
F_154 ( & V_420 -> V_204 ,
& V_6 -> V_422 ) ;
}
return V_420 ;
}
static void F_155 ( struct V_5 * V_6 ,
V_373 * V_397 )
{
struct V_10 * V_11 ;
union V_207 V_336 ;
struct V_24 * V_25 = & V_6 -> V_8 . V_83 ;
union V_354 * V_355 ;
struct V_132 * V_92 ;
struct V_423 * V_424 ;
V_355 = ( void * ) V_397 + sizeof( V_373 ) ;
V_11 = F_4 ( F_123 ( V_355 -> V_246 . type ) ) ;
V_11 -> V_340 ( & V_336 , V_355 , F_8 ( V_25 -> V_280 ) , 0 ) ;
switch ( V_397 -> V_74 . type ) {
case V_345 :
F_156 () ;
F_38 (saddr, &bp->address_list, list) {
if ( F_122 ( & V_424 -> V_425 , & V_336 ) )
V_424 -> V_348 = V_282 ;
}
F_157 () ;
F_38 (transport, &asoc->peer.transport_addr_list,
transports) {
F_158 ( V_92 -> V_426 ) ;
V_92 -> V_426 = NULL ;
}
break;
case V_346 :
F_156 () ;
F_159 ( V_25 , & V_336 ) ;
if ( V_6 -> V_394 != NULL &&
F_122 ( V_6 -> V_394 , & V_336 ) ) {
F_23 ( V_6 -> V_394 ) ;
V_6 -> V_394 = NULL ;
}
F_157 () ;
F_38 (transport, &asoc->peer.transport_addr_list,
transports) {
F_158 ( V_92 -> V_426 ) ;
V_92 -> V_426 = NULL ;
}
break;
default:
break;
}
}
static T_1 F_160 ( struct V_3 * V_420 ,
V_373 * V_397 ,
int V_427 )
{
V_373 * V_428 ;
T_3 * V_399 ;
int V_20 ;
int V_429 ;
T_1 V_396 ;
if ( V_427 )
V_396 = V_403 ;
else
V_396 = V_430 ;
V_429 = F_20 ( V_420 -> V_150 -> V_20 ) -
sizeof( T_19 ) ;
V_20 = sizeof( T_29 ) ;
V_428 = ( V_373 * ) ( V_420 -> V_2 -> V_162 +
V_20 ) ;
V_429 -= V_20 ;
while ( V_429 > 0 ) {
if ( V_428 -> V_395 == V_397 -> V_395 ) {
switch ( V_428 -> V_74 . type ) {
case V_404 :
return V_403 ;
case V_405 :
V_20 = sizeof( V_373 ) ;
V_399 = ( void * ) V_428 + V_20 ;
V_429 -= V_20 ;
if ( V_429 > 0 )
return V_399 -> V_19 ;
else
return V_293 ;
break;
default:
return V_293 ;
}
}
V_20 = F_20 ( V_428 -> V_74 . V_20 ) ;
V_428 = ( void * ) V_428 + V_20 ;
V_429 -= V_20 ;
}
return V_396 ;
}
int F_161 ( struct V_5 * V_6 ,
struct V_3 * V_420 )
{
struct V_3 * V_378 = V_6 -> V_431 ;
union V_354 * V_355 ;
V_373 * V_397 ;
int V_20 = 0 ;
int V_432 = V_378 -> V_2 -> V_18 ;
int V_418 = 0 ;
int V_427 = 1 ;
int V_35 = 0 ;
T_1 V_396 = V_403 ;
V_20 = sizeof( T_30 ) ;
V_355 = (union V_354 * ) ( V_378 -> V_2 -> V_162 + V_20 ) ;
V_432 -= V_20 ;
V_20 = F_20 ( V_355 -> V_246 . V_20 ) ;
V_397 = ( void * ) V_355 + V_20 ;
V_432 -= V_20 ;
if ( V_420 -> V_2 -> V_18 == sizeof( T_29 ) )
V_418 = 1 ;
while ( V_432 > 0 ) {
if ( V_418 )
V_396 = V_403 ;
else {
V_396 = F_160 ( V_420 ,
V_397 ,
V_427 ) ;
if ( V_427 && ( V_403 != V_396 ) )
V_427 = 0 ;
}
switch ( V_396 ) {
case V_403 :
F_155 ( V_6 , V_397 ) ;
break;
case V_407 :
V_35 = 1 ;
break;
case V_309 :
V_6 -> V_85 . V_344 |=
V_397 -> V_74 . type ;
break;
case V_430 :
case V_411 :
case V_412 :
default:
break;
}
V_20 = F_20 ( V_397 -> V_74 . V_20 ) ;
V_397 = ( void * ) V_397 + V_20 ;
V_432 -= V_20 ;
}
if ( V_427 && V_6 -> V_433 ) {
V_6 -> V_433 = 0 ;
F_162 ( V_6 -> V_85 . V_434 ) ;
}
F_75 ( & V_378 -> V_204 ) ;
F_47 ( V_378 ) ;
V_6 -> V_431 = NULL ;
return V_35 ;
}
struct V_3 * F_163 ( const struct V_5 * V_6 ,
T_13 V_435 , T_2 V_436 ,
struct V_437 * V_438 )
{
struct V_3 * V_35 = NULL ;
struct V_439 V_440 ;
struct V_437 V_441 ;
T_2 V_149 ;
int V_297 ;
V_149 = ( V_436 + 1 ) * sizeof( T_13 ) ;
V_35 = F_21 ( V_6 , V_301 , 0 , V_149 ) ;
if ( ! V_35 )
return NULL ;
V_440 . V_435 = F_16 ( V_435 ) ;
V_35 -> V_21 . V_442 =
F_9 ( V_35 , sizeof( V_440 ) , & V_440 ) ;
for ( V_297 = 0 ; V_297 < V_436 ; V_297 ++ ) {
V_441 . V_112 = V_438 [ V_297 ] . V_112 ;
V_441 . V_107 = V_438 [ V_297 ] . V_107 ;
F_9 ( V_35 , sizeof( V_441 ) , & V_441 ) ;
}
return V_35 ;
}

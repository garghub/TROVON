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
V_35 = F_21 ( V_6 , V_71 , 0 , V_34 , V_26 ) ;
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
V_35 = F_21 ( V_6 , V_90 , 0 , V_34 , V_26 ) ;
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
V_35 = F_21 ( V_6 , V_93 , 0 ,
V_82 , V_94 ) ;
if ( ! V_35 )
goto V_72;
V_35 -> V_21 . V_95 =
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
V_35 = F_21 ( V_6 , V_96 , 0 , 0 , V_94 ) ;
if ( V_35 && V_4 )
V_35 -> V_92 = V_4 -> V_92 ;
return V_35 ;
}
struct V_3 * F_28 ( const struct V_5 * V_6 ,
const T_13 V_97 ,
const struct V_3 * V_4 )
{
struct V_3 * V_35 ;
T_14 V_98 ;
V_98 . V_97 = F_16 ( V_97 ) ;
V_35 = F_21 ( V_6 , V_99 , 0 ,
sizeof( T_14 ) , V_94 ) ;
if ( ! V_35 )
goto V_72;
V_35 -> V_21 . V_100 =
F_9 ( V_35 , sizeof( V_98 ) , & V_98 ) ;
if ( V_4 )
V_35 -> V_92 = V_4 -> V_92 ;
V_72:
return V_35 ;
}
struct V_3 * F_29 ( const struct V_5 * V_6 ,
const T_13 V_97 )
{
struct V_3 * V_35 ;
T_15 V_101 ;
V_101 . V_97 = F_16 ( V_97 ) ;
V_35 = F_21 ( V_6 , V_102 , 0 ,
sizeof( T_15 ) , V_94 ) ;
if ( ! V_35 )
goto V_72;
V_35 -> V_21 . V_103 =
F_9 ( V_35 , sizeof( V_101 ) , & V_101 ) ;
V_72:
return V_35 ;
}
struct V_3 * F_30 ( struct V_5 * V_6 ,
const struct V_104 * V_105 ,
int V_106 , T_10 V_107 , T_4 V_108 ,
T_5 V_26 )
{
struct V_3 * V_35 ;
struct V_109 V_110 ;
int V_111 ;
V_110 . V_112 = 0 ;
V_110 . V_113 = F_8 ( V_105 -> V_114 ) ;
V_110 . V_115 = V_105 -> V_116 ;
if ( V_105 -> V_117 & V_118 ) {
V_107 |= V_119 ;
V_110 . V_108 = 0 ;
} else
V_110 . V_108 = F_8 ( V_108 ) ;
V_111 = sizeof( V_110 ) + V_106 ;
V_35 = F_31 ( V_6 , V_107 , V_111 , V_26 ) ;
if ( ! V_35 )
goto V_72;
V_35 -> V_21 . V_120 = F_9 ( V_35 , sizeof( V_110 ) , & V_110 ) ;
memcpy ( & V_35 -> V_105 , V_105 , sizeof( struct V_104 ) ) ;
V_72:
return V_35 ;
}
struct V_3 * F_32 ( const struct V_5 * V_6 )
{
struct V_3 * V_35 ;
struct V_121 V_122 ;
int V_18 ;
T_13 V_123 ;
T_4 V_124 , V_125 ;
struct V_5 * V_126 = (struct V_5 * ) V_6 ;
struct V_127 * V_128 = (struct V_127 * ) & V_6 -> V_85 . V_129 ;
struct V_130 V_131 [ V_132 ] ;
struct V_133 * V_134 ;
memset ( V_131 , 0 , sizeof( V_131 ) ) ;
V_123 = F_33 ( V_128 ) ;
F_34 ( L_1 , V_135 , V_123 ) ;
V_124 = F_35 ( V_128 , V_131 ) ;
V_125 = F_36 ( V_128 ) ;
V_122 . V_136 = F_16 ( V_123 ) ;
V_122 . V_51 = F_16 ( V_6 -> V_51 ) ;
V_122 . V_137 = F_8 ( V_124 ) ;
V_122 . V_125 = F_8 ( V_125 ) ;
V_18 = sizeof( V_122 )
+ sizeof( struct V_130 ) * V_124
+ sizeof( T_13 ) * V_125 ;
V_35 = F_21 ( V_6 , V_138 , 0 , V_18 , V_94 ) ;
if ( ! V_35 )
goto V_72;
V_35 -> V_92 = V_6 -> V_85 . V_139 ;
V_35 -> V_21 . V_140 =
F_9 ( V_35 , sizeof( V_122 ) , & V_122 ) ;
if ( V_124 )
F_9 ( V_35 , sizeof( T_13 ) * V_124 ,
V_131 ) ;
if ( V_125 ) {
V_126 -> V_141 . V_142 += V_125 ;
F_9 ( V_35 , sizeof( T_13 ) * V_125 ,
F_37 ( V_128 ) ) ;
}
if ( ++ V_126 -> V_85 . V_143 == 0 ) {
F_38 (trans, &asoc->peer.transport_addr_list,
transports)
V_134 -> V_143 = 0 ;
V_126 -> V_85 . V_143 = 1 ;
}
V_72:
return V_35 ;
}
struct V_3 * F_39 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_35 ;
T_16 V_144 ;
T_13 V_123 ;
V_123 = F_33 ( & V_6 -> V_85 . V_129 ) ;
V_144 . V_136 = F_16 ( V_123 ) ;
V_35 = F_21 ( V_6 , V_145 , 0 ,
sizeof( T_16 ) , V_94 ) ;
if ( ! V_35 )
goto V_72;
V_35 -> V_21 . V_146 =
F_9 ( V_35 , sizeof( V_144 ) , & V_144 ) ;
if ( V_4 )
V_35 -> V_92 = V_4 -> V_92 ;
V_72:
return V_35 ;
}
struct V_3 * F_40 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_35 ;
V_35 = F_21 ( V_6 , V_147 , 0 , 0 ,
V_94 ) ;
if ( V_35 && V_4 )
V_35 -> V_92 = V_4 -> V_92 ;
return V_35 ;
}
struct V_3 * F_41 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_35 ;
T_10 V_107 = 0 ;
V_107 |= V_6 ? 0 : V_148 ;
V_35 = F_21 ( V_6 , V_149 , V_107 ,
0 , V_94 ) ;
if ( V_35 && V_4 )
V_35 -> V_92 = V_4 -> V_92 ;
return V_35 ;
}
struct V_3 * F_42 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
const T_2 V_150 )
{
struct V_3 * V_35 ;
T_10 V_107 = 0 ;
if ( ! V_6 ) {
if ( V_4 && V_4 -> V_151 &&
V_4 -> V_151 -> type == V_71 )
V_107 = 0 ;
else
V_107 = V_148 ;
}
V_35 = F_21 ( V_6 , V_152 , V_107 , V_150 ,
V_94 ) ;
if ( V_35 && V_4 )
V_35 -> V_92 = V_4 -> V_92 ;
return V_35 ;
}
struct V_3 * F_43 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 , T_13 V_112 )
{
struct V_3 * V_35 ;
T_17 V_153 ;
V_35 = F_42 ( V_6 , V_4 , sizeof( T_3 )
+ sizeof( V_112 ) ) ;
if ( ! V_35 )
goto V_154;
V_153 = F_16 ( V_112 ) ;
F_7 ( V_35 , V_155 , sizeof( V_153 ) ) ;
F_9 ( V_35 , sizeof( V_153 ) , ( const void * ) & V_153 ) ;
if ( V_4 )
V_35 -> V_92 = V_4 -> V_92 ;
V_154:
return V_35 ;
}
struct V_3 * F_44 ( const struct V_5 * V_6 ,
struct V_156 * V_157 ,
T_2 V_16 )
{
struct V_3 * V_35 ;
void * V_153 = NULL ;
int V_17 ;
V_35 = F_42 ( V_6 , NULL , sizeof( T_3 ) + V_16 ) ;
if ( ! V_35 )
goto V_158;
if ( V_16 ) {
V_153 = F_45 ( V_16 , V_159 ) ;
if ( ! V_153 )
goto V_160;
V_17 = F_46 ( V_153 , V_157 , V_16 ) ;
if ( V_17 < 0 )
goto V_161;
}
F_7 ( V_35 , V_162 , V_16 ) ;
F_9 ( V_35 , V_16 , V_153 ) ;
if ( V_16 )
F_23 ( V_153 ) ;
return V_35 ;
V_161:
F_23 ( V_153 ) ;
V_160:
F_47 ( V_35 ) ;
V_35 = NULL ;
V_158:
return V_35 ;
}
static void * F_22 ( struct V_3 * V_4 , int V_18 ,
const void * V_163 )
{
void * V_164 ;
int V_165 = F_20 ( V_4 -> V_151 -> V_20 ) ;
V_164 = F_48 ( V_4 -> V_2 , V_18 ) ;
if ( V_163 )
memcpy ( V_164 , V_163 , V_18 ) ;
else
memset ( V_164 , 0 , V_18 ) ;
V_4 -> V_151 -> V_20 = F_8 ( V_165 + V_18 ) ;
V_4 -> V_166 = F_49 ( V_4 -> V_2 ) ;
return V_164 ;
}
struct V_3 * F_50 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
const T_10 * V_153 ,
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
V_168 . type = F_8 ( V_4 -> V_151 -> type ) ;
V_168 . V_20 = V_4 -> V_151 -> V_20 ;
F_9 ( V_35 , V_16 , V_153 ) ;
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
const struct V_133 * V_92 )
{
struct V_3 * V_35 ;
T_18 V_173 ;
V_35 = F_21 ( V_6 , V_174 , 0 ,
sizeof( V_173 ) , V_94 ) ;
if ( ! V_35 )
goto V_72;
V_173 . V_74 . type = V_175 ;
V_173 . V_74 . V_20 = F_8 ( sizeof( T_18 ) ) ;
V_173 . V_176 = V_92 -> V_177 ;
V_173 . V_178 = V_179 ;
V_173 . V_180 = V_92 -> V_180 ;
V_35 -> V_92 = (struct V_133 * ) V_92 ;
V_35 -> V_21 . V_181 = F_9 ( V_35 , sizeof( V_173 ) ,
& V_173 ) ;
V_72:
return V_35 ;
}
struct V_3 * F_54 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
const void * V_153 , const T_2 V_16 )
{
struct V_3 * V_35 ;
V_35 = F_21 ( V_6 , V_182 , 0 , V_16 ,
V_94 ) ;
if ( ! V_35 )
goto V_72;
V_35 -> V_21 . V_181 = F_9 ( V_35 , V_16 , V_153 ) ;
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
sizeof( T_3 ) + V_183 , V_94 ) ;
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
T_1 V_15 , const void * V_153 ,
T_2 V_16 , T_2 V_187 )
{
struct V_3 * V_35 ;
V_35 = F_55 ( V_6 , V_4 , V_16 + V_187 ) ;
if ( ! V_35 )
goto V_72;
F_7 ( V_35 , V_15 , V_16 + V_187 ) ;
F_9 ( V_35 , V_16 , V_153 ) ;
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
V_189 -> V_193 + sizeof( V_194 ) ,
V_94 ) ;
if ( ! V_35 )
return NULL ;
V_191 . V_195 = F_8 ( V_189 -> V_195 ) ;
V_191 . V_196 = F_8 ( V_6 -> V_197 ) ;
V_35 -> V_21 . V_191 = F_9 ( V_35 , sizeof( V_194 ) ,
& V_191 ) ;
V_192 = F_48 ( V_35 -> V_2 , V_189 -> V_193 ) ;
memset ( V_192 , 0 , V_189 -> V_193 ) ;
V_35 -> V_151 -> V_20 =
F_8 ( F_20 ( V_35 -> V_151 -> V_20 ) + V_189 -> V_193 ) ;
V_35 -> V_166 = F_49 ( V_35 -> V_2 ) ;
return V_35 ;
}
struct V_3 * F_61 ( struct V_1 * V_2 ,
const struct V_5 * V_6 ,
struct V_198 * V_7 , T_5 V_26 )
{
struct V_3 * V_35 ;
V_35 = F_62 ( V_199 , V_26 ) ;
if ( ! V_35 )
goto V_72;
if ( ! V_7 )
F_34 ( L_4 , V_135 , V_2 ) ;
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
return & V_4 -> V_92 -> V_177 ;
} else {
return & V_4 -> V_210 ;
}
}
static struct V_3 * F_68 ( const struct V_5 * V_6 ,
T_10 type , T_10 V_107 , int V_16 ,
T_5 V_26 )
{
struct V_3 * V_35 ;
T_19 * V_151 ;
struct V_1 * V_2 ;
struct V_198 * V_7 ;
V_2 = F_69 ( F_18 ( sizeof( T_19 ) + V_16 ) , V_26 ) ;
if ( ! V_2 )
goto V_72;
V_151 = ( T_19 * ) F_48 ( V_2 , sizeof( T_19 ) ) ;
V_151 -> type = type ;
V_151 -> V_107 = V_107 ;
V_151 -> V_20 = F_8 ( sizeof( T_19 ) ) ;
V_7 = V_6 ? V_6 -> V_8 . V_7 : NULL ;
V_35 = F_61 ( V_2 , V_6 , V_7 , V_26 ) ;
if ( ! V_35 ) {
F_70 ( V_2 ) ;
goto V_72;
}
V_35 -> V_151 = V_151 ;
V_35 -> V_166 = ( ( T_10 * ) V_151 ) + sizeof( struct V_211 ) ;
if ( F_71 ( type , V_6 ) )
V_35 -> V_212 = 1 ;
return V_35 ;
V_72:
return NULL ;
}
static struct V_3 * F_31 ( const struct V_5 * V_6 ,
T_10 V_107 , int V_16 , T_5 V_26 )
{
return F_68 ( V_6 , V_213 , V_107 , V_16 , V_26 ) ;
}
static struct V_3 * F_21 ( const struct V_5 * V_6 ,
T_10 type , T_10 V_107 , int V_16 ,
T_5 V_26 )
{
struct V_3 * V_4 ;
V_4 = F_68 ( V_6 , type , V_107 , V_16 , V_26 ) ;
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
F_78 ( V_199 , V_4 ) ;
}
void F_47 ( struct V_3 * V_4 )
{
if ( V_4 -> V_157 )
F_79 ( V_4 -> V_157 ) ;
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
void * F_9 ( struct V_3 * V_4 , int V_18 , const void * V_163 )
{
void * V_164 ;
void * V_216 ;
int V_165 = F_20 ( V_4 -> V_151 -> V_20 ) ;
int V_217 = F_18 ( V_165 ) - V_165 ;
V_216 = F_48 ( V_4 -> V_2 , V_217 ) ;
V_164 = F_48 ( V_4 -> V_2 , V_18 ) ;
memset ( V_216 , 0 , V_217 ) ;
memcpy ( V_164 , V_163 , V_18 ) ;
V_4 -> V_151 -> V_20 = F_8 ( V_165 + V_217 + V_18 ) ;
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
int F_84 ( struct V_3 * V_4 , int V_18 ,
struct V_218 * V_219 )
{
void * V_164 ;
T_20 V_220 ;
V_164 = F_48 ( V_4 -> V_2 , V_18 ) ;
V_220 = F_85 ( V_164 , V_18 , V_219 ) ;
if ( V_220 != V_18 )
return - V_221 ;
V_4 -> V_151 -> V_20 =
F_8 ( F_20 ( V_4 -> V_151 -> V_20 ) + V_18 ) ;
V_4 -> V_166 = F_49 ( V_4 -> V_2 ) ;
return 0 ;
}
void F_86 ( struct V_3 * V_4 )
{
struct V_222 * V_157 ;
struct V_3 * V_223 ;
struct V_224 * V_113 ;
T_4 V_108 ;
T_4 V_225 ;
if ( V_4 -> V_226 )
return;
V_225 = F_20 ( V_4 -> V_21 . V_120 -> V_113 ) ;
V_113 = & V_4 -> V_6 -> V_227 -> V_228 ;
V_157 = V_4 -> V_157 ;
F_38 (lchunk, &msg->chunks, frag_list) {
if ( V_223 -> V_151 -> V_107 & V_119 ) {
V_108 = 0 ;
} else {
if ( V_223 -> V_151 -> V_107 & V_229 )
V_108 = F_87 ( V_113 , V_225 ) ;
else
V_108 = F_88 ( V_113 , V_225 ) ;
}
V_223 -> V_21 . V_120 -> V_108 = F_8 ( V_108 ) ;
V_223 -> V_226 = 1 ;
}
}
void F_89 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_230 ) {
V_4 -> V_21 . V_120 -> V_112 =
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
int V_239 , V_240 ;
V_239 = sizeof( T_11 ) +
( sizeof( struct V_238 ) -
sizeof( struct V_241 ) ) ;
V_240 = sizeof( struct V_241 )
+ F_20 ( V_236 -> V_151 -> V_20 ) + V_37 ;
if ( V_240 % V_242 )
V_240 += V_242
- ( V_240 % V_242 ) ;
* V_82 = V_239 + V_240 ;
V_35 = F_95 ( * V_82 , V_94 ) ;
if ( ! V_35 )
goto V_72;
V_81 = (struct V_238 * ) V_35 -> V_243 ;
V_35 -> V_244 . type = V_245 ;
V_35 -> V_244 . V_20 = F_8 ( * V_82 ) ;
V_81 -> V_49 = V_6 -> V_49 ;
V_81 -> V_49 . V_246 = V_37 ;
V_81 -> V_49 . V_87 = V_6 -> V_85 . V_87 ;
V_81 -> V_49 . V_67 = V_6 -> V_85 . V_67 ;
V_81 -> V_49 . V_247 = F_96 ( V_6 -> V_248 ,
F_97 () ) ;
memcpy ( & V_81 -> V_49 . V_249 [ 0 ] , V_236 -> V_151 ,
F_20 ( V_236 -> V_151 -> V_20 ) ) ;
memcpy ( ( T_10 * ) & V_81 -> V_49 . V_249 [ 0 ] +
F_20 ( V_236 -> V_151 -> V_20 ) , V_237 , V_37 ) ;
if ( F_17 ( V_30 -> V_8 . V_7 ) -> V_192 ) {
F_98 ( V_250 , F_17 ( V_30 -> V_8 . V_7 ) -> V_192 ) ;
int V_17 ;
V_250 -> V_251 = F_17 ( V_30 -> V_8 . V_7 ) -> V_192 ;
V_250 -> V_107 = 0 ;
V_17 = F_99 ( V_250 -> V_251 , V_30 -> V_252 ,
sizeof( V_30 -> V_252 ) ) ? :
F_100 ( V_250 , ( V_253 * ) & V_81 -> V_49 , V_240 ,
V_81 -> V_254 ) ;
F_101 ( V_250 ) ;
if ( V_17 )
goto V_255;
}
return V_35 ;
V_255:
F_23 ( V_35 ) ;
V_72:
* V_82 = 0 ;
return NULL ;
}
struct V_5 * F_102 (
const struct V_29 * V_30 ,
const struct V_5 * V_6 ,
struct V_3 * V_4 , T_5 V_26 ,
int * error , struct V_3 * * V_256 )
{
struct V_5 * V_35 = NULL ;
struct V_238 * V_81 ;
struct V_241 * V_257 ;
int V_239 , V_240 , V_258 ;
T_10 * V_259 = V_30 -> V_259 ;
unsigned int V_18 ;
T_21 V_231 ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_22 V_260 ;
V_239 = sizeof( T_19 ) +
( sizeof( struct V_238 ) -
sizeof( struct V_241 ) ) ;
V_240 = F_20 ( V_4 -> V_151 -> V_20 ) - V_239 ;
V_258 = V_239 + sizeof( struct V_241 ) ;
V_18 = F_20 ( V_4 -> V_151 -> V_20 ) ;
if ( V_18 < V_258 + sizeof( struct V_211 ) )
goto V_261;
if ( V_240 % V_242 )
goto V_261;
V_81 = V_4 -> V_21 . V_95 ;
V_257 = & V_81 -> V_49 ;
if ( ! F_17 ( V_30 -> V_8 . V_7 ) -> V_192 )
goto V_262;
{
F_98 ( V_250 , F_17 ( V_30 -> V_8 . V_7 ) -> V_192 ) ;
int V_17 ;
V_250 -> V_251 = F_17 ( V_30 -> V_8 . V_7 ) -> V_192 ;
V_250 -> V_107 = 0 ;
V_17 = F_99 ( V_250 -> V_251 , V_30 -> V_252 ,
sizeof( V_30 -> V_252 ) ) ? :
F_100 ( V_250 , ( V_253 * ) V_257 , V_240 ,
V_259 ) ;
F_101 ( V_250 ) ;
if ( V_17 ) {
* error = - V_263 ;
goto V_233;
}
}
if ( memcmp ( V_259 , V_81 -> V_254 , V_264 ) ) {
* error = - V_265 ;
goto V_233;
}
V_262:
if ( F_103 ( V_4 -> V_266 -> V_267 ) != V_257 -> V_50 ) {
* error = - V_268 ;
goto V_233;
}
if ( V_4 -> V_266 -> V_210 != V_257 -> V_235 . V_269 . V_270 ||
F_20 ( V_4 -> V_266 -> V_209 ) != V_257 -> V_271 ) {
* error = - V_272 ;
goto V_233;
}
if ( F_104 ( V_30 -> V_8 . V_7 , V_273 ) )
V_260 = F_105 ( V_2 ) ;
else
V_260 = F_97 () ;
if ( ! V_6 && F_106 ( V_257 -> V_247 , V_260 ) ) {
V_18 = F_20 ( V_4 -> V_151 -> V_20 ) ;
* V_256 = F_55 ( V_6 , V_4 , V_18 ) ;
if ( * V_256 ) {
T_23 V_274 = F_107 ( F_108 ( V_260 , V_257 -> V_247 ) ) ;
T_17 V_275 = F_16 ( V_274 ) ;
F_7 ( * V_256 , V_276 ,
sizeof( V_275 ) ) ;
F_9 ( * V_256 , sizeof( V_275 ) , & V_275 ) ;
* error = - V_277 ;
} else
* error = - V_263 ;
goto V_233;
}
V_231 = F_92 ( F_67 ( V_4 ) ) ;
V_35 = F_93 ( V_30 , V_30 -> V_8 . V_7 , V_231 , V_26 ) ;
if ( ! V_35 ) {
* error = - V_263 ;
goto V_233;
}
V_35 -> V_85 . V_278 = F_20 ( V_4 -> V_266 -> V_210 ) ;
memcpy ( & V_35 -> V_49 , V_257 , sizeof( * V_257 ) ) ;
if ( F_109 ( V_35 , V_257 ,
V_94 ) < 0 ) {
* error = - V_263 ;
goto V_233;
}
if ( F_74 ( & V_35 -> V_8 . V_83 . V_279 ) ) {
F_110 ( & V_35 -> V_8 . V_83 , & V_4 -> V_209 ,
sizeof( V_4 -> V_209 ) , V_280 ,
V_94 ) ;
}
V_35 -> V_281 = V_35 -> V_49 . V_57 ;
V_35 -> V_282 = V_35 -> V_281 - 1 ;
V_35 -> V_283 = V_35 -> V_49 . V_57 ;
V_35 -> V_284 = V_35 -> V_282 ;
V_35 -> V_85 . V_87 = V_35 -> V_49 . V_87 ;
V_35 -> V_85 . V_67 = V_35 -> V_49 . V_67 ;
return V_35 ;
V_233:
if ( V_35 )
F_94 ( V_35 ) ;
return NULL ;
V_261:
* error = - V_285 ;
goto V_233;
}
static int F_111 ( const struct V_5 * V_6 ,
T_24 V_286 ,
struct V_3 * V_4 ,
struct V_3 * * V_256 )
{
struct V_287 V_288 ;
T_4 V_18 ;
V_18 = F_18 ( sizeof( V_288 ) ) ;
if ( ! * V_256 )
* V_256 = F_55 ( V_6 , V_4 , V_18 ) ;
if ( * V_256 ) {
V_288 . V_289 = F_16 ( 1 ) ;
V_288 . type = V_286 ;
F_7 ( * V_256 , V_290 ,
sizeof( V_288 ) ) ;
F_9 ( * V_256 , sizeof( V_288 ) , & V_288 ) ;
}
return 0 ;
}
static int F_112 ( const struct V_5 * V_6 ,
struct V_3 * V_4 ,
struct V_3 * * V_256 )
{
if ( ! * V_256 )
* V_256 = F_55 ( V_6 , V_4 , 0 ) ;
if ( * V_256 )
F_7 ( * V_256 , V_291 , 0 ) ;
return 0 ;
}
static int F_113 ( const struct V_5 * V_6 ,
struct V_167 * V_171 ,
const struct V_3 * V_4 ,
struct V_3 * * V_256 )
{
if ( * V_256 )
F_47 ( * V_256 ) ;
* V_256 = F_51 ( V_6 , V_4 , V_171 ) ;
return 0 ;
}
static int F_114 ( const struct V_5 * V_6 ,
union V_32 V_171 ,
struct V_3 * V_4 ,
struct V_3 * * V_256 )
{
T_4 V_18 = F_20 ( V_171 . V_244 -> V_20 ) ;
if ( * V_256 )
F_47 ( * V_256 ) ;
* V_256 = F_55 ( V_6 , V_4 , V_18 ) ;
if ( * V_256 ) {
F_7 ( * V_256 , V_292 , V_18 ) ;
F_9 ( * V_256 , V_18 , V_171 . V_75 ) ;
}
return 0 ;
}
static int F_115 ( struct V_28 * V_28 , union V_32 V_171 )
{
T_4 V_44 = F_20 ( V_171 . V_244 -> V_20 ) - sizeof( T_11 ) ;
int V_293 = 0 ;
int V_294 = 0 ;
int V_295 ;
for ( V_295 = 0 ; V_295 < V_44 ; V_295 ++ ) {
switch ( V_171 . V_296 -> V_297 [ V_295 ] ) {
case V_70 :
V_293 = 1 ;
break;
case V_65 :
case V_66 :
V_294 = 1 ;
break;
}
}
if ( V_28 -> V_61 . V_298 )
return 1 ;
if ( V_28 -> V_61 . V_64 && ! V_293 && V_294 )
return 0 ;
return 1 ;
}
static void F_116 ( struct V_5 * V_6 ,
union V_32 V_171 )
{
struct V_28 * V_28 = F_14 ( V_6 -> V_8 . V_7 ) ;
T_4 V_44 = F_20 ( V_171 . V_244 -> V_20 ) - sizeof( T_11 ) ;
int V_295 ;
for ( V_295 = 0 ; V_295 < V_44 ; V_295 ++ ) {
switch ( V_171 . V_296 -> V_297 [ V_295 ] ) {
case V_299 :
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
static T_25 F_117 ( const struct V_5 * V_6 ,
union V_32 V_171 ,
struct V_3 * V_4 ,
struct V_3 * * V_256 )
{
int V_35 = V_300 ;
switch ( V_171 . V_244 -> type & V_301 ) {
case V_302 :
V_35 = V_303 ;
break;
case V_304 :
break;
case V_305 :
V_35 = V_303 ;
case V_306 :
if ( NULL == * V_256 )
* V_256 = F_56 ( V_6 , V_4 ) ;
if ( * V_256 ) {
if ( ! F_10 ( * V_256 , V_307 ,
F_18 ( F_20 ( V_171 . V_244 -> V_20 ) ) ) )
F_12 ( * V_256 ,
F_18 ( F_20 ( V_171 . V_244 -> V_20 ) ) ,
V_171 . V_75 ) ;
} else {
V_35 = V_263 ;
}
break;
default:
break;
}
return V_35 ;
}
static T_25 F_118 ( struct V_28 * V_28 ,
const struct V_29 * V_30 ,
const struct V_5 * V_6 ,
union V_32 V_171 ,
T_26 V_308 ,
struct V_3 * V_4 ,
struct V_3 * * V_158 )
{
struct V_309 * V_310 ;
int V_35 = V_300 ;
T_4 V_311 , V_312 = 0 ;
int V_295 ;
switch ( V_171 . V_244 -> type ) {
case V_313 :
case V_314 :
case V_315 :
case V_76 :
case V_245 :
case V_175 :
case V_316 :
case V_317 :
case V_78 :
break;
case V_77 :
if ( ! F_115 ( V_28 , V_171 ) )
return V_318 ;
break;
case V_319 :
if ( V_28 -> V_61 . V_64 )
break;
goto V_320;
case V_321 :
F_114 ( V_6 , V_171 , V_4 , V_158 ) ;
V_35 = V_318 ;
break;
case V_322 :
if ( V_28 -> V_61 . V_62 )
break;
goto V_320;
case V_323 :
if ( ! V_30 -> V_68 )
goto V_320;
if ( V_324 !=
F_20 ( V_171 . V_244 -> V_20 ) - sizeof( T_11 ) ) {
F_113 ( V_6 , V_171 . V_244 ,
V_4 , V_158 ) ;
V_35 = V_318 ;
}
break;
case V_325 :
if ( ! V_30 -> V_68 )
goto V_320;
if ( 260 < F_20 ( V_171 . V_244 -> V_20 ) ) {
F_113 ( V_6 , V_171 . V_244 ,
V_4 , V_158 ) ;
V_35 = V_318 ;
}
break;
case V_326 :
if ( ! V_30 -> V_68 )
goto V_320;
V_310 = (struct V_309 * ) V_171 . V_244 ;
V_311 = ( F_20 ( V_171 . V_244 -> V_20 ) - sizeof( T_11 ) ) >> 1 ;
for ( V_295 = 0 ; V_295 < V_311 ; V_295 ++ ) {
V_312 = F_20 ( V_310 -> V_327 [ V_295 ] ) ;
if ( V_312 == V_328 )
break;
}
if ( V_312 != V_328 ) {
F_113 ( V_6 , V_171 . V_244 , V_4 ,
V_158 ) ;
V_35 = V_318 ;
}
break;
V_320:
default:
F_34 ( L_5 ,
V_135 , F_20 ( V_171 . V_244 -> type ) , V_308 ) ;
V_35 = F_117 ( V_6 , V_171 , V_4 , V_158 ) ;
break;
}
return V_35 ;
}
int F_119 ( struct V_28 * V_28 , const struct V_29 * V_30 ,
const struct V_5 * V_6 , T_26 V_308 ,
T_27 * V_249 , struct V_3 * V_4 ,
struct V_3 * * V_256 )
{
union V_32 V_171 ;
bool V_329 = false ;
int V_330 ;
if ( V_249 -> V_73 . V_53 == 0 ||
V_249 -> V_73 . V_55 == 0 ||
V_249 -> V_73 . V_48 == 0 ||
F_103 ( V_249 -> V_73 . V_51 ) < V_331 )
return F_112 ( V_6 , V_4 , V_256 ) ;
F_120 (param, peer_init, init_hdr.params) {
if ( V_171 . V_244 -> type == V_245 )
V_329 = true ;
}
if ( V_171 . V_75 != ( void * ) V_4 -> V_166 )
return F_113 ( V_6 , V_171 . V_244 , V_4 , V_256 ) ;
if ( ( V_90 == V_308 ) && ! V_329 )
return F_111 ( V_6 , V_245 ,
V_4 , V_256 ) ;
F_120 (param, peer_init, init_hdr.params) {
V_330 = F_118 ( V_28 , V_30 , V_6 , V_171 , V_308 ,
V_4 , V_256 ) ;
switch ( V_330 ) {
case V_318 :
case V_263 :
return 0 ;
case V_303 :
return 1 ;
case V_300 :
default:
break;
}
}
return 1 ;
}
int F_121 ( struct V_5 * V_6 , struct V_3 * V_4 ,
const union V_207 * V_235 ,
T_27 * V_249 , T_5 V_26 )
{
struct V_28 * V_28 = F_14 ( V_6 -> V_8 . V_7 ) ;
union V_32 V_171 ;
struct V_133 * V_92 ;
struct V_332 * V_333 , * V_232 ;
struct V_10 * V_11 ;
union V_207 V_334 ;
char * V_81 ;
int V_335 = 0 ;
if ( ! F_122 ( V_6 , V_235 , V_26 , V_336 ) )
goto V_337;
if ( F_123 ( F_67 ( V_4 ) , V_235 ) )
V_335 = 1 ;
F_120 (param, peer_init, init_hdr.params) {
if ( ! V_335 && ( V_171 . V_244 -> type == V_313 ||
V_171 . V_244 -> type == V_314 ) ) {
V_11 = F_4 ( F_124 ( V_171 . V_244 -> type ) ) ;
V_11 -> V_338 ( & V_334 , V_171 . V_334 ,
V_4 -> V_266 -> V_210 , 0 ) ;
if ( F_123 ( F_67 ( V_4 ) , & V_334 ) )
V_335 = 1 ;
}
if ( ! F_125 ( V_6 , V_171 , V_235 , V_26 ) )
goto V_339;
}
if ( ! V_335 )
goto V_339;
if ( V_6 -> V_85 . V_89 && ( ! V_6 -> V_85 . V_340 ||
! V_6 -> V_85 . V_341 ) )
V_6 -> V_85 . V_89 = 0 ;
if ( ! V_28 -> V_61 . V_298 &&
( V_6 -> V_85 . V_88 && ! V_6 -> V_85 . V_89 ) ) {
V_6 -> V_85 . V_342 |= ( V_343 |
V_344 |
V_319 ) ;
V_6 -> V_85 . V_88 = 0 ;
goto V_339;
}
F_126 (pos, temp, &asoc->peer.transport_addr_list) {
V_92 = F_127 ( V_333 , struct V_133 , V_345 ) ;
if ( V_92 -> V_346 == V_347 ) {
F_128 ( V_6 , V_92 ) ;
}
}
V_6 -> V_85 . V_295 . V_48 =
F_103 ( V_249 -> V_73 . V_48 ) ;
V_6 -> V_85 . V_295 . V_51 =
F_103 ( V_249 -> V_73 . V_51 ) ;
V_6 -> V_85 . V_295 . V_53 =
F_20 ( V_249 -> V_73 . V_53 ) ;
V_6 -> V_85 . V_295 . V_55 =
F_20 ( V_249 -> V_73 . V_55 ) ;
V_6 -> V_85 . V_295 . V_57 =
F_103 ( V_249 -> V_73 . V_57 ) ;
if ( V_6 -> V_49 . V_54 >
F_20 ( V_249 -> V_73 . V_55 ) ) {
V_6 -> V_49 . V_54 =
F_20 ( V_249 -> V_73 . V_55 ) ;
}
if ( V_6 -> V_49 . V_56 >
F_20 ( V_249 -> V_73 . V_53 ) ) {
V_6 -> V_49 . V_56 =
F_20 ( V_249 -> V_73 . V_53 ) ;
}
V_6 -> V_49 . V_348 = V_6 -> V_85 . V_295 . V_48 ;
V_6 -> V_85 . V_52 = V_6 -> V_85 . V_295 . V_51 ;
V_81 = V_6 -> V_85 . V_81 ;
if ( V_81 ) {
V_6 -> V_85 . V_81 = F_129 ( V_81 , V_6 -> V_85 . V_82 , V_26 ) ;
if ( ! V_6 -> V_85 . V_81 )
goto V_339;
}
F_38 (transport, &asoc->peer.transport_addr_list,
transports) {
V_92 -> V_349 = V_6 -> V_85 . V_295 . V_51 ;
}
if ( ! F_130 ( & V_6 -> V_85 . V_129 , V_350 ,
V_6 -> V_85 . V_295 . V_57 , V_26 ) )
goto V_339;
if ( ! V_6 -> V_232 ) {
int error ;
V_6 -> V_227 = F_131 ( V_6 -> V_49 . V_56 ,
V_6 -> V_49 . V_54 , V_26 ) ;
if ( ! V_6 -> V_227 )
goto V_339;
error = F_132 ( V_6 , V_26 ) ;
if ( error )
goto V_339;
}
V_6 -> V_85 . V_283 = V_6 -> V_85 . V_295 . V_57 - 1 ;
return 1 ;
V_339:
F_126 (pos, temp, &asoc->peer.transport_addr_list) {
V_92 = F_127 ( V_333 , struct V_133 , V_345 ) ;
if ( V_92 -> V_346 != V_336 )
F_128 ( V_6 , V_92 ) ;
}
V_337:
return 0 ;
}
static int F_125 ( struct V_5 * V_6 ,
union V_32 V_171 ,
const union V_207 * V_235 ,
T_5 V_26 )
{
struct V_28 * V_28 = F_14 ( V_6 -> V_8 . V_7 ) ;
union V_207 V_334 ;
int V_295 ;
T_4 V_40 ;
int V_35 = 1 ;
T_21 V_231 ;
T_28 V_351 ;
struct V_10 * V_11 ;
union V_352 * V_353 ;
struct V_133 * V_354 ;
struct V_29 * V_30 = V_6 -> V_30 ;
switch ( V_171 . V_244 -> type ) {
case V_314 :
if ( V_355 != V_6 -> V_8 . V_7 -> V_356 )
break;
goto V_357;
case V_313 :
if ( F_133 ( V_6 -> V_8 . V_7 ) )
break;
V_357:
V_11 = F_4 ( F_124 ( V_171 . V_244 -> type ) ) ;
V_11 -> V_338 ( & V_334 , V_171 . V_334 , F_8 ( V_6 -> V_85 . V_278 ) , 0 ) ;
V_231 = F_92 ( V_235 ) ;
if ( F_134 ( V_28 , & V_334 , V_231 ) )
if ( ! F_122 ( V_6 , & V_334 , V_26 , V_358 ) )
return 0 ;
break;
case V_315 :
if ( ! V_28 -> V_61 . V_359 )
break;
V_351 = F_103 ( V_171 . V_360 -> V_361 ) ;
V_6 -> V_248 = F_135 ( V_6 -> V_248 , V_351 ) ;
break;
case V_321 :
F_34 ( L_6 , V_135 ) ;
break;
case V_76 :
V_6 -> V_85 . V_362 = 0 ;
V_6 -> V_85 . V_363 = 0 ;
if ( V_235 -> V_364 . V_365 == V_366 )
V_6 -> V_85 . V_363 = 1 ;
else if ( V_235 -> V_364 . V_365 == V_367 )
V_6 -> V_85 . V_362 = 1 ;
V_40 = F_20 ( V_171 . V_244 -> V_20 ) - sizeof( T_11 ) ;
if ( V_40 )
V_40 /= sizeof( T_4 ) ;
for ( V_295 = 0 ; V_295 < V_40 ; ++ V_295 ) {
switch ( V_171 . V_40 -> V_41 [ V_295 ] ) {
case V_313 :
V_6 -> V_85 . V_362 = 1 ;
break;
case V_314 :
if ( V_355 == V_6 -> V_8 . V_7 -> V_356 )
V_6 -> V_85 . V_363 = 1 ;
break;
case V_321 :
V_6 -> V_85 . V_368 = 1 ;
break;
default:
break;
}
}
break;
case V_245 :
V_6 -> V_85 . V_82 =
F_20 ( V_171 . V_244 -> V_20 ) - sizeof( T_11 ) ;
V_6 -> V_85 . V_81 = V_171 . V_81 -> V_243 ;
break;
case V_175 :
break;
case V_316 :
break;
case V_317 :
V_6 -> V_85 . V_86 = 1 ;
break;
case V_78 :
V_6 -> V_85 . V_67 = F_103 ( V_171 . V_369 -> V_67 ) ;
break;
case V_319 :
if ( ! V_28 -> V_61 . V_64 )
goto V_370;
V_353 = V_171 . V_75 + sizeof( V_371 ) ;
V_11 = F_4 ( F_124 ( V_353 -> V_244 . type ) ) ;
if ( V_11 == NULL )
break;
V_11 -> V_338 ( & V_334 , V_353 ,
F_8 ( V_6 -> V_85 . V_278 ) , 0 ) ;
if ( ! V_11 -> V_372 ( & V_334 , NULL , NULL ) )
break;
V_354 = F_136 ( V_6 , & V_334 ) ;
if ( ! V_354 )
break;
F_137 ( V_6 , V_354 ) ;
break;
case V_77 :
F_116 ( V_6 , V_171 ) ;
break;
case V_322 :
if ( V_28 -> V_61 . V_62 ) {
V_6 -> V_85 . V_87 = 1 ;
break;
}
goto V_370;
case V_323 :
if ( ! V_30 -> V_68 )
goto V_370;
V_6 -> V_85 . V_340 = F_129 ( V_171 . V_244 ,
F_20 ( V_171 . V_244 -> V_20 ) , V_26 ) ;
if ( ! V_6 -> V_85 . V_340 ) {
V_35 = 0 ;
break;
}
break;
case V_326 :
if ( ! V_30 -> V_68 )
goto V_370;
V_6 -> V_85 . V_341 = F_129 ( V_171 . V_244 ,
F_20 ( V_171 . V_244 -> V_20 ) , V_26 ) ;
if ( ! V_6 -> V_85 . V_341 ) {
V_35 = 0 ;
break;
}
F_138 ( V_6 , V_171 . V_373 ) ;
break;
case V_325 :
if ( ! V_30 -> V_68 )
goto V_370;
V_6 -> V_85 . V_374 = F_129 ( V_171 . V_244 ,
F_20 ( V_171 . V_244 -> V_20 ) , V_26 ) ;
if ( ! V_6 -> V_85 . V_374 )
V_35 = 0 ;
break;
V_370:
default:
F_34 ( L_7 ,
V_135 , F_20 ( V_171 . V_244 -> type ) , V_6 ) ;
break;
}
return V_35 ;
}
T_13 F_139 ( const struct V_29 * V_30 )
{
T_13 V_375 ;
do {
F_140 ( & V_375 , sizeof( T_13 ) ) ;
} while ( V_375 == 0 );
return V_375 ;
}
T_13 F_141 ( const struct V_29 * V_30 )
{
T_13 V_35 ;
F_140 ( & V_35 , sizeof( T_13 ) ) ;
return V_35 ;
}
static struct V_3 * F_142 ( struct V_5 * V_6 ,
union V_207 * V_334 ,
int V_27 )
{
T_29 V_376 ;
struct V_3 * V_35 ;
int V_20 = sizeof( V_376 ) + V_27 ;
union V_352 V_377 ;
int V_378 ;
struct V_10 * V_11 = F_4 ( V_334 -> V_269 . V_379 ) ;
V_378 = V_11 -> V_380 ( V_334 , & V_377 ) ;
if ( ! V_378 )
return NULL ;
V_20 += V_378 ;
V_35 = F_21 ( V_6 , V_65 , 0 , V_20 ,
V_94 ) ;
if ( ! V_35 )
return NULL ;
V_376 . V_381 = F_16 ( V_6 -> V_283 ++ ) ;
V_35 -> V_21 . V_382 =
F_9 ( V_35 , sizeof( V_376 ) , & V_376 ) ;
V_35 -> V_74 . V_75 =
F_9 ( V_35 , V_378 , & V_377 ) ;
return V_35 ;
}
struct V_3 * F_143 ( struct V_5 * V_6 ,
union V_207 * V_383 ,
struct V_384 * V_33 ,
int V_385 ,
T_1 V_107 )
{
V_371 V_171 ;
struct V_3 * V_35 ;
union V_352 V_353 ;
union V_207 * V_334 ;
void * V_386 ;
struct V_10 * V_11 ;
int V_387 = sizeof( V_171 ) ;
int V_388 = 0 ;
int V_389 = 0 ;
int V_295 ;
int V_390 = 0 ;
V_386 = V_33 ;
for ( V_295 = 0 ; V_295 < V_385 ; V_295 ++ ) {
V_334 = V_386 ;
V_11 = F_4 ( V_334 -> V_269 . V_379 ) ;
V_388 = V_11 -> V_380 ( V_334 , & V_353 ) ;
V_389 += V_387 ;
V_389 += V_388 ;
V_386 += V_11 -> V_391 ;
if ( V_6 -> V_392 && ! V_390 ) {
V_389 += V_387 ;
V_389 += V_388 ;
V_390 = 1 ;
F_34 ( L_8
L_9 ,
V_135 , V_389 ) ;
}
}
V_35 = F_142 ( V_6 , V_383 , V_389 ) ;
if ( ! V_35 )
return NULL ;
V_386 = V_33 ;
for ( V_295 = 0 ; V_295 < V_385 ; V_295 ++ ) {
V_334 = V_386 ;
V_11 = F_4 ( V_334 -> V_269 . V_379 ) ;
V_388 = V_11 -> V_380 ( V_334 , & V_353 ) ;
V_171 . V_74 . type = V_107 ;
V_171 . V_74 . V_20 = F_8 ( V_387 + V_388 ) ;
V_171 . V_393 = V_295 ;
F_9 ( V_35 , V_387 , & V_171 ) ;
F_9 ( V_35 , V_388 , & V_353 ) ;
V_386 += V_11 -> V_391 ;
}
if ( V_107 == V_343 && V_390 ) {
V_334 = V_6 -> V_392 ;
V_11 = F_4 ( V_334 -> V_269 . V_379 ) ;
V_388 = V_11 -> V_380 ( V_334 , & V_353 ) ;
V_171 . V_74 . type = V_344 ;
V_171 . V_74 . V_20 = F_8 ( V_387 + V_388 ) ;
V_171 . V_393 = V_295 ;
F_9 ( V_35 , V_387 , & V_171 ) ;
F_9 ( V_35 , V_388 , & V_353 ) ;
}
return V_35 ;
}
struct V_3 * F_144 ( struct V_5 * V_6 ,
union V_207 * V_334 )
{
V_371 V_171 ;
struct V_3 * V_35 ;
int V_18 = sizeof( V_171 ) ;
union V_352 V_377 ;
int V_378 ;
struct V_10 * V_11 = F_4 ( V_334 -> V_269 . V_379 ) ;
V_378 = V_11 -> V_380 ( V_334 , & V_377 ) ;
if ( ! V_378 )
return NULL ;
V_18 += V_378 ;
V_35 = F_142 ( V_6 , V_334 , V_18 ) ;
if ( ! V_35 )
return NULL ;
V_171 . V_74 . type = V_319 ;
V_171 . V_74 . V_20 = F_8 ( V_18 ) ;
V_171 . V_393 = 0 ;
F_9 ( V_35 , sizeof( V_171 ) , & V_171 ) ;
F_9 ( V_35 , V_378 , & V_377 ) ;
return V_35 ;
}
static struct V_3 * F_145 ( const struct V_5 * V_6 ,
T_13 V_381 , int V_27 )
{
T_29 V_376 ;
struct V_3 * V_35 ;
int V_20 = sizeof( V_376 ) + V_27 ;
V_35 = F_21 ( V_6 , V_66 , 0 , V_20 ,
V_94 ) ;
if ( ! V_35 )
return NULL ;
V_376 . V_381 = F_16 ( V_381 ) ;
V_35 -> V_21 . V_382 =
F_9 ( V_35 , sizeof( V_376 ) , & V_376 ) ;
return V_35 ;
}
static void F_146 ( struct V_3 * V_4 , T_17 V_393 ,
T_1 V_394 , V_371 * V_395 )
{
V_371 V_396 ;
T_3 V_397 ;
int V_398 = 0 ;
int V_399 = 0 ;
T_1 V_400 ;
if ( V_401 == V_394 ) {
V_400 = V_402 ;
} else {
V_400 = V_403 ;
V_399 = sizeof( V_397 ) ;
if ( V_395 )
V_398 =
F_20 ( V_395 -> V_74 . V_20 ) ;
}
V_396 . V_74 . type = V_400 ;
V_396 . V_74 . V_20 = F_8 ( sizeof( V_396 ) +
V_399 +
V_398 ) ;
V_396 . V_393 = V_393 ;
F_9 ( V_4 , sizeof( V_396 ) , & V_396 ) ;
if ( V_401 == V_394 )
return;
V_397 . V_19 = V_394 ;
V_397 . V_20 = F_8 ( V_399 + V_398 ) ;
F_9 ( V_4 , V_399 , & V_397 ) ;
if ( V_395 )
F_9 ( V_4 , V_398 , V_395 ) ;
}
static T_1 F_147 ( struct V_5 * V_6 ,
struct V_3 * V_376 ,
V_371 * V_395 )
{
struct V_133 * V_85 ;
struct V_10 * V_11 ;
union V_207 V_334 ;
union V_352 * V_353 ;
V_353 = ( void * ) V_395 + sizeof( V_371 ) ;
if ( V_395 -> V_74 . type != V_343 &&
V_395 -> V_74 . type != V_344 &&
V_395 -> V_74 . type != V_319 )
return V_307 ;
switch ( V_353 -> V_244 . type ) {
case V_314 :
if ( ! V_6 -> V_85 . V_363 )
return V_292 ;
break;
case V_313 :
if ( ! V_6 -> V_85 . V_362 )
return V_292 ;
break;
default:
return V_292 ;
}
V_11 = F_4 ( F_124 ( V_353 -> V_244 . type ) ) ;
if ( F_60 ( ! V_11 ) )
return V_292 ;
V_11 -> V_338 ( & V_334 , V_353 , F_8 ( V_6 -> V_85 . V_278 ) , 0 ) ;
if ( ! V_11 -> V_404 ( & V_334 ) && ! V_11 -> V_372 ( & V_334 , NULL , V_376 -> V_2 ) )
return V_292 ;
switch ( V_395 -> V_74 . type ) {
case V_343 :
if ( V_11 -> V_404 ( & V_334 ) )
memcpy ( & V_334 , & V_376 -> V_210 , sizeof( V_334 ) ) ;
V_85 = F_122 ( V_6 , & V_334 , V_94 , V_358 ) ;
if ( ! V_85 )
return V_405 ;
F_148 ( V_85 ) ;
V_6 -> V_406 = V_85 ;
break;
case V_344 :
if ( V_6 -> V_85 . V_407 == 1 )
return V_408 ;
if ( F_123 ( & V_376 -> V_210 , & V_334 ) )
return V_409 ;
if ( V_11 -> V_404 ( & V_334 ) ) {
F_137 ( V_6 , V_376 -> V_92 ) ;
F_149 ( V_6 ,
V_376 -> V_92 ) ;
return V_401 ;
}
V_85 = F_136 ( V_6 , & V_334 ) ;
if ( ! V_85 )
return V_292 ;
F_128 ( V_6 , V_85 ) ;
break;
case V_319 :
if ( V_11 -> V_404 ( & V_334 ) )
memcpy ( & V_334 . V_269 , F_67 ( V_376 ) , sizeof( V_334 ) ) ;
V_85 = F_136 ( V_6 , & V_334 ) ;
if ( ! V_85 )
return V_292 ;
F_137 ( V_6 , V_85 ) ;
break;
}
return V_401 ;
}
bool F_150 ( const struct V_5 * V_6 ,
struct V_3 * V_4 , bool V_410 ,
struct V_167 * * V_256 )
{
T_30 * V_411 = ( T_30 * ) V_4 -> V_151 ;
union V_32 V_171 ;
bool V_412 = false ;
F_120 (param, addip, addip_hdr.params) {
T_2 V_20 = F_20 ( V_171 . V_244 -> V_20 ) ;
* V_256 = V_171 . V_244 ;
switch ( V_171 . V_244 -> type ) {
case V_403 :
break;
case V_313 :
if ( V_20 != sizeof( V_413 ) )
return false ;
if ( V_171 . V_75 != V_411 -> V_382 . V_414 )
return false ;
V_412 = true ;
break;
case V_314 :
if ( V_20 != sizeof( V_415 ) )
return false ;
if ( V_171 . V_75 != V_411 -> V_382 . V_414 )
return false ;
V_412 = true ;
break;
case V_343 :
case V_344 :
case V_319 :
if ( V_410 && ! V_412 )
return false ;
V_20 = F_20 ( V_171 . V_411 -> V_74 . V_20 ) ;
if ( V_20 < sizeof( V_371 ) +
sizeof( T_11 ) )
return false ;
break;
case V_402 :
case V_78 :
if ( V_20 != sizeof( V_371 ) )
return false ;
break;
default:
return false ;
}
}
if ( V_410 && ! V_412 )
return false ;
if ( ! V_410 && V_412 )
return false ;
if ( V_171 . V_75 != V_4 -> V_166 )
return false ;
return true ;
}
struct V_3 * F_151 ( struct V_5 * V_6 ,
struct V_3 * V_376 )
{
T_30 * V_411 = ( T_30 * ) V_376 -> V_151 ;
bool V_416 = true ;
union V_32 V_171 ;
T_29 * V_417 ;
union V_352 * V_353 ;
V_371 * V_395 ;
struct V_3 * V_418 ;
T_1 V_394 ;
int V_20 = 0 ;
int V_111 ;
T_13 V_381 ;
V_111 = F_20 ( V_376 -> V_151 -> V_20 ) - sizeof( T_19 ) ;
V_417 = ( T_29 * ) V_376 -> V_2 -> V_163 ;
V_381 = F_103 ( V_417 -> V_381 ) ;
V_20 = sizeof( T_29 ) ;
V_353 = (union V_352 * ) ( V_376 -> V_2 -> V_163 + V_20 ) ;
V_111 -= V_20 ;
V_20 = F_20 ( V_353 -> V_244 . V_20 ) ;
V_395 = ( void * ) V_353 + V_20 ;
V_111 -= V_20 ;
V_418 = F_145 ( V_6 , V_381 , V_111 * 4 ) ;
if ( ! V_418 )
goto V_419;
F_120 (param, addip, addip_hdr.params) {
if ( V_171 . V_244 -> type == V_313 ||
V_171 . V_244 -> type == V_314 )
continue;
V_394 = F_147 ( V_6 , V_376 ,
V_171 . V_411 ) ;
if ( V_394 != V_401 )
V_416 = false ;
if ( ! V_416 )
F_146 ( V_418 , V_171 . V_411 -> V_393 ,
V_394 , V_171 . V_411 ) ;
if ( V_394 == V_405 )
goto V_419;
}
V_419:
V_6 -> V_85 . V_283 ++ ;
if ( V_418 ) {
F_81 ( V_418 ) ;
F_152 ( & V_418 -> V_204 ,
& V_6 -> V_420 ) ;
}
return V_418 ;
}
static void F_153 ( struct V_5 * V_6 ,
V_371 * V_395 )
{
struct V_10 * V_11 ;
union V_207 V_334 ;
struct V_24 * V_25 = & V_6 -> V_8 . V_83 ;
union V_352 * V_353 ;
struct V_133 * V_92 ;
struct V_421 * V_422 ;
V_353 = ( void * ) V_395 + sizeof( V_371 ) ;
V_11 = F_4 ( F_124 ( V_353 -> V_244 . type ) ) ;
V_11 -> V_338 ( & V_334 , V_353 , F_8 ( V_25 -> V_278 ) , 0 ) ;
switch ( V_395 -> V_74 . type ) {
case V_343 :
F_154 () ;
F_38 (saddr, &bp->address_list, list) {
if ( F_123 ( & V_422 -> V_423 , & V_334 ) )
V_422 -> V_346 = V_280 ;
}
F_155 () ;
F_38 (transport, &asoc->peer.transport_addr_list,
transports) {
F_156 ( V_92 -> V_424 ) ;
V_92 -> V_424 = NULL ;
}
break;
case V_344 :
F_154 () ;
F_157 ( V_25 , & V_334 ) ;
if ( V_6 -> V_392 != NULL &&
F_123 ( V_6 -> V_392 , & V_334 ) ) {
F_23 ( V_6 -> V_392 ) ;
V_6 -> V_392 = NULL ;
}
F_155 () ;
F_38 (transport, &asoc->peer.transport_addr_list,
transports) {
F_156 ( V_92 -> V_424 ) ;
V_92 -> V_424 = NULL ;
}
break;
default:
break;
}
}
static T_1 F_158 ( struct V_3 * V_418 ,
V_371 * V_395 ,
int V_425 )
{
V_371 * V_426 ;
T_3 * V_397 ;
int V_20 ;
int V_427 ;
T_1 V_394 ;
if ( V_425 )
V_394 = V_401 ;
else
V_394 = V_428 ;
V_427 = F_20 ( V_418 -> V_151 -> V_20 ) -
sizeof( T_19 ) ;
V_20 = sizeof( T_29 ) ;
V_426 = ( V_371 * ) ( V_418 -> V_2 -> V_163 +
V_20 ) ;
V_427 -= V_20 ;
while ( V_427 > 0 ) {
if ( V_426 -> V_393 == V_395 -> V_393 ) {
switch ( V_426 -> V_74 . type ) {
case V_402 :
return V_401 ;
case V_403 :
V_20 = sizeof( V_371 ) ;
V_397 = ( void * ) V_426 + V_20 ;
V_427 -= V_20 ;
if ( V_427 > 0 )
return V_397 -> V_19 ;
else
return V_291 ;
break;
default:
return V_291 ;
}
}
V_20 = F_20 ( V_426 -> V_74 . V_20 ) ;
V_426 = ( void * ) V_426 + V_20 ;
V_427 -= V_20 ;
}
return V_394 ;
}
int F_159 ( struct V_5 * V_6 ,
struct V_3 * V_418 )
{
struct V_3 * V_376 = V_6 -> V_429 ;
union V_352 * V_353 ;
V_371 * V_395 ;
int V_20 = 0 ;
int V_430 = V_376 -> V_2 -> V_18 ;
int V_416 = 0 ;
int V_425 = 1 ;
int V_35 = 0 ;
T_1 V_394 = V_401 ;
V_20 = sizeof( T_30 ) ;
V_353 = (union V_352 * ) ( V_376 -> V_2 -> V_163 + V_20 ) ;
V_430 -= V_20 ;
V_20 = F_20 ( V_353 -> V_244 . V_20 ) ;
V_395 = ( void * ) V_353 + V_20 ;
V_430 -= V_20 ;
if ( V_418 -> V_2 -> V_18 == sizeof( T_29 ) )
V_416 = 1 ;
while ( V_430 > 0 ) {
if ( V_416 )
V_394 = V_401 ;
else {
V_394 = F_158 ( V_418 ,
V_395 ,
V_425 ) ;
if ( V_425 && ( V_401 != V_394 ) )
V_425 = 0 ;
}
switch ( V_394 ) {
case V_401 :
F_153 ( V_6 , V_395 ) ;
break;
case V_405 :
V_35 = 1 ;
break;
case V_307 :
V_6 -> V_85 . V_342 |=
V_395 -> V_74 . type ;
break;
case V_428 :
case V_408 :
case V_409 :
default:
break;
}
V_20 = F_20 ( V_395 -> V_74 . V_20 ) ;
V_395 = ( void * ) V_395 + V_20 ;
V_430 -= V_20 ;
}
if ( V_425 && V_6 -> V_431 ) {
V_6 -> V_431 = 0 ;
F_160 ( V_6 -> V_85 . V_432 ) ;
}
F_75 ( & V_376 -> V_204 ) ;
F_47 ( V_376 ) ;
V_6 -> V_429 = NULL ;
return V_35 ;
}
struct V_3 * F_161 ( const struct V_5 * V_6 ,
T_13 V_433 , T_2 V_434 ,
struct V_435 * V_436 )
{
struct V_3 * V_35 = NULL ;
struct V_437 V_438 ;
struct V_435 V_439 ;
T_2 V_150 ;
int V_295 ;
V_150 = ( V_434 + 1 ) * sizeof( T_13 ) ;
V_35 = F_21 ( V_6 , V_299 , 0 , V_150 , V_94 ) ;
if ( ! V_35 )
return NULL ;
V_438 . V_433 = F_16 ( V_433 ) ;
V_35 -> V_21 . V_440 =
F_9 ( V_35 , sizeof( V_438 ) , & V_438 ) ;
for ( V_295 = 0 ; V_295 < V_434 ; V_295 ++ ) {
V_439 . V_113 = V_436 [ V_295 ] . V_113 ;
V_439 . V_108 = V_436 [ V_295 ] . V_108 ;
F_9 ( V_35 , sizeof( V_439 ) , & V_439 ) ;
}
return V_35 ;
}

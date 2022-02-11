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
T_3 V_14 ;
T_4 V_15 ;
V_14 . V_16 = V_12 ;
V_15 = sizeof( T_3 ) + V_13 ;
V_14 . V_17 = F_6 ( V_15 ) ;
V_4 -> V_18 . V_19 = F_7 ( V_4 , sizeof( T_3 ) , & V_14 ) ;
}
static int F_8 ( struct V_3 * V_4 , T_1 V_12 ,
T_2 V_13 )
{
T_3 V_14 ;
T_4 V_15 ;
V_14 . V_16 = V_12 ;
V_15 = sizeof( T_3 ) + V_13 ;
V_14 . V_17 = F_6 ( V_15 ) ;
if ( F_9 ( V_4 -> V_2 ) < V_15 )
return - V_20 ;
V_4 -> V_18 . V_19 = F_10 ( V_4 ,
sizeof( T_3 ) ,
& V_14 ) ;
return 0 ;
}
struct V_3 * F_11 ( const struct V_5 * V_6 ,
const struct V_21 * V_22 ,
T_5 V_23 , int V_24 )
{
struct V_25 * V_25 = F_12 ( V_6 -> V_8 . V_7 ) ;
struct V_26 * V_27 = V_6 -> V_27 ;
T_6 V_28 ;
union V_29 V_30 ;
T_2 V_31 ;
struct V_3 * V_32 = NULL ;
int V_33 , V_34 = 0 ;
struct V_35 * V_36 ;
T_7 V_37 ;
T_1 V_38 [ 2 ] ;
T_8 V_39 ;
T_9 V_40 ;
int V_41 = 0 ;
T_10 V_42 [ 3 ] ;
T_11 * V_43 = NULL ,
* V_44 = NULL ;
V_32 = NULL ;
V_30 = F_13 ( V_22 , & V_34 , V_23 ) ;
V_28 . V_45 = F_14 ( V_6 -> V_46 . V_47 ) ;
V_28 . V_48 = F_14 ( V_6 -> V_49 ) ;
V_28 . V_50 = F_6 ( V_6 -> V_46 . V_51 ) ;
V_28 . V_52 = F_6 ( V_6 -> V_46 . V_53 ) ;
V_28 . V_54 = F_14 ( V_6 -> V_46 . V_54 ) ;
V_36 = F_15 ( V_6 -> V_8 . V_7 ) ;
V_33 = V_36 -> V_55 -> V_56 ( V_36 , V_38 ) ;
V_31 = sizeof( V_28 ) + V_34 ;
V_31 += F_16 ( F_17 ( V_33 ) ) ;
V_31 += sizeof( V_57 ) ;
if ( V_6 -> V_58 )
V_31 += sizeof( V_59 ) ;
if ( V_25 -> V_60 . V_61 ) {
V_42 [ V_41 ] = V_62 ;
V_42 [ V_41 + 1 ] = V_63 ;
V_41 += 2 ;
}
if ( V_6 -> V_64 ) {
V_42 [ V_41 ] = V_65 ;
V_41 += 1 ;
}
if ( V_36 -> V_66 )
V_31 += sizeof( V_39 ) ;
V_31 += V_24 ;
if ( V_27 -> V_67 ) {
V_31 += sizeof( V_6 -> V_46 . V_68 ) ;
V_44 = ( T_11 * ) V_6 -> V_46 . V_44 ;
if ( V_44 -> V_17 )
V_31 += F_16 ( F_18 ( V_44 -> V_17 ) ) ;
else
V_44 = NULL ;
V_43 = ( T_11 * ) V_6 -> V_46 . V_43 ;
if ( V_43 -> V_17 )
V_31 += F_16 ( F_18 ( V_43 -> V_17 ) ) ;
else
V_43 = NULL ;
V_42 [ V_41 ] = V_69 ;
V_41 += 1 ;
}
if ( V_41 )
V_31 += F_16 ( sizeof( T_9 ) +
V_41 ) ;
V_32 = F_19 ( V_6 , V_70 , 0 , V_31 , V_23 ) ;
if ( ! V_32 )
goto V_71;
V_32 -> V_18 . V_72 =
F_7 ( V_32 , sizeof( V_28 ) , & V_28 ) ;
V_32 -> V_73 . V_74 =
F_7 ( V_32 , V_34 , V_30 . V_74 ) ;
V_37 . V_73 . type = V_75 ;
V_37 . V_73 . V_17 = F_6 ( F_17 ( V_33 ) ) ;
F_7 ( V_32 , sizeof( V_37 ) , & V_37 ) ;
F_7 ( V_32 , V_33 * sizeof( T_4 ) , & V_38 ) ;
F_7 ( V_32 , sizeof( V_57 ) , & V_57 ) ;
if ( V_41 ) {
V_40 . V_73 . type = V_76 ;
V_40 . V_73 . V_17 =
F_6 ( sizeof( T_9 ) + V_41 ) ;
F_7 ( V_32 , sizeof( T_9 ) ,
& V_40 ) ;
F_20 ( V_32 , V_41 , V_42 ) ;
}
if ( V_6 -> V_58 )
F_7 ( V_32 , sizeof( V_59 ) , & V_59 ) ;
if ( V_36 -> V_66 ) {
V_39 . V_73 . type = V_77 ;
V_39 . V_73 . V_17 = F_6 ( sizeof( V_39 ) ) ;
V_39 . V_66 = F_14 ( V_36 -> V_66 ) ;
F_7 ( V_32 , sizeof( V_39 ) , & V_39 ) ;
}
if ( V_27 -> V_67 ) {
F_7 ( V_32 , sizeof( V_6 -> V_46 . V_68 ) ,
V_6 -> V_46 . V_68 ) ;
if ( V_44 )
F_7 ( V_32 , F_18 ( V_44 -> V_17 ) ,
V_44 ) ;
if ( V_43 )
F_7 ( V_32 , F_18 ( V_43 -> V_17 ) ,
V_43 ) ;
}
V_71:
F_21 ( V_30 . V_74 ) ;
return V_32 ;
}
struct V_3 * F_22 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
T_5 V_23 , int V_78 )
{
T_6 V_79 ;
struct V_3 * V_32 ;
union V_29 V_30 ;
struct V_35 * V_36 ;
int V_34 ;
T_12 * V_80 ;
int V_81 ;
T_2 V_31 ;
T_8 V_39 ;
T_9 V_40 ;
int V_41 = 0 ;
T_10 V_42 [ 3 ] ;
T_11 * V_43 = NULL ,
* V_44 = NULL ,
* V_68 = NULL ;
V_32 = NULL ;
V_30 = F_13 ( & V_6 -> V_8 . V_82 , & V_34 , V_23 ) ;
V_79 . V_45 = F_14 ( V_6 -> V_46 . V_47 ) ;
V_79 . V_48 = F_14 ( V_6 -> V_49 ) ;
V_79 . V_50 = F_6 ( V_6 -> V_46 . V_51 ) ;
V_79 . V_52 = F_6 ( V_6 -> V_46 . V_53 ) ;
V_79 . V_54 = F_14 ( V_6 -> V_46 . V_54 ) ;
V_80 = F_23 ( V_6 -> V_27 , V_6 , V_4 , & V_81 ,
V_30 . V_74 , V_34 ) ;
if ( ! V_80 )
goto V_83;
V_36 = F_15 ( V_6 -> V_8 . V_7 ) ;
V_31 = sizeof( V_79 ) + V_34 + V_81 + V_78 ;
if ( V_6 -> V_84 . V_85 )
V_31 += sizeof( V_57 ) ;
if ( V_6 -> V_84 . V_86 )
V_31 += sizeof( V_59 ) ;
if ( V_6 -> V_84 . V_87 ) {
V_42 [ V_41 ] = V_62 ;
V_42 [ V_41 + 1 ] = V_63 ;
V_41 += 2 ;
}
if ( V_6 -> V_84 . V_88 ) {
V_42 [ V_41 ] = V_65 ;
V_41 += 1 ;
}
if ( V_36 -> V_66 )
V_31 += sizeof( V_39 ) ;
if ( V_6 -> V_84 . V_89 ) {
V_68 = ( T_11 * ) V_6 -> V_46 . V_68 ;
V_31 += F_18 ( V_68 -> V_17 ) ;
V_44 = ( T_11 * ) V_6 -> V_46 . V_44 ;
if ( V_44 -> V_17 )
V_31 += F_16 ( F_18 ( V_44 -> V_17 ) ) ;
else
V_44 = NULL ;
V_43 = ( T_11 * ) V_6 -> V_46 . V_43 ;
if ( V_43 -> V_17 )
V_31 += F_16 ( F_18 ( V_43 -> V_17 ) ) ;
else
V_43 = NULL ;
V_42 [ V_41 ] = V_69 ;
V_41 += 1 ;
}
if ( V_41 )
V_31 += F_16 ( sizeof( T_9 ) +
V_41 ) ;
V_32 = F_19 ( V_6 , V_90 , 0 , V_31 , V_23 ) ;
if ( ! V_32 )
goto V_91;
V_32 -> V_92 = V_4 -> V_92 ;
V_32 -> V_18 . V_72 =
F_7 ( V_32 , sizeof( V_79 ) , & V_79 ) ;
V_32 -> V_73 . V_74 = F_7 ( V_32 , V_34 , V_30 . V_74 ) ;
F_7 ( V_32 , V_81 , V_80 ) ;
if ( V_6 -> V_84 . V_85 )
F_7 ( V_32 , sizeof( V_57 ) , & V_57 ) ;
if ( V_41 ) {
V_40 . V_73 . type = V_76 ;
V_40 . V_73 . V_17 =
F_6 ( sizeof( T_9 ) + V_41 ) ;
F_7 ( V_32 , sizeof( T_9 ) ,
& V_40 ) ;
F_20 ( V_32 , V_41 , V_42 ) ;
}
if ( V_6 -> V_84 . V_86 )
F_7 ( V_32 , sizeof( V_59 ) , & V_59 ) ;
if ( V_36 -> V_66 ) {
V_39 . V_73 . type = V_77 ;
V_39 . V_73 . V_17 = F_6 ( sizeof( V_39 ) ) ;
V_39 . V_66 = F_14 ( V_36 -> V_66 ) ;
F_7 ( V_32 , sizeof( V_39 ) , & V_39 ) ;
}
if ( V_6 -> V_84 . V_89 ) {
F_7 ( V_32 , F_18 ( V_68 -> V_17 ) ,
V_68 ) ;
if ( V_44 )
F_7 ( V_32 , F_18 ( V_44 -> V_17 ) ,
V_44 ) ;
if ( V_43 )
F_7 ( V_32 , F_18 ( V_43 -> V_17 ) ,
V_43 ) ;
}
V_32 -> V_6 = (struct V_5 * ) V_6 ;
V_91:
F_21 ( V_80 ) ;
V_83:
F_21 ( V_30 . V_74 ) ;
return V_32 ;
}
struct V_3 * F_24 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_32 ;
void * V_80 ;
int V_81 ;
V_80 = V_6 -> V_84 . V_80 ;
V_81 = V_6 -> V_84 . V_81 ;
V_32 = F_19 ( V_6 , V_93 , 0 ,
V_81 , V_94 ) ;
if ( ! V_32 )
goto V_71;
V_32 -> V_18 . V_95 =
F_7 ( V_32 , V_81 , V_80 ) ;
if ( V_4 )
V_32 -> V_92 = V_4 -> V_92 ;
V_71:
return V_32 ;
}
struct V_3 * F_25 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_32 ;
V_32 = F_19 ( V_6 , V_96 , 0 , 0 , V_94 ) ;
if ( V_32 && V_4 )
V_32 -> V_92 = V_4 -> V_92 ;
return V_32 ;
}
struct V_3 * F_26 ( const struct V_5 * V_6 ,
const T_13 V_97 ,
const struct V_3 * V_4 )
{
struct V_3 * V_32 ;
T_14 V_98 ;
V_98 . V_97 = F_14 ( V_97 ) ;
V_32 = F_19 ( V_6 , V_99 , 0 ,
sizeof( T_14 ) , V_94 ) ;
if ( ! V_32 )
goto V_71;
V_32 -> V_18 . V_100 =
F_7 ( V_32 , sizeof( V_98 ) , & V_98 ) ;
if ( V_4 )
V_32 -> V_92 = V_4 -> V_92 ;
V_71:
return V_32 ;
}
struct V_3 * F_27 ( const struct V_5 * V_6 ,
const T_13 V_97 )
{
struct V_3 * V_32 ;
T_15 V_101 ;
V_101 . V_97 = F_14 ( V_97 ) ;
V_32 = F_19 ( V_6 , V_102 , 0 ,
sizeof( T_15 ) , V_94 ) ;
if ( ! V_32 )
goto V_71;
V_32 -> V_18 . V_103 =
F_7 ( V_32 , sizeof( V_101 ) , & V_101 ) ;
V_71:
return V_32 ;
}
struct V_3 * F_28 ( struct V_5 * V_6 ,
const struct V_104 * V_105 ,
int V_106 , T_10 V_107 , T_4 V_108 ,
T_5 V_23 )
{
struct V_3 * V_32 ;
struct V_109 V_110 ;
int V_111 ;
V_110 . V_112 = 0 ;
V_110 . V_113 = F_6 ( V_105 -> V_114 ) ;
V_110 . V_115 = V_105 -> V_116 ;
if ( V_105 -> V_117 & V_118 ) {
V_107 |= V_119 ;
V_110 . V_108 = 0 ;
} else
V_110 . V_108 = F_6 ( V_108 ) ;
V_111 = sizeof( V_110 ) + V_106 ;
V_32 = F_29 ( V_6 , V_107 , V_111 , V_23 ) ;
if ( ! V_32 )
goto V_71;
V_32 -> V_18 . V_120 = F_7 ( V_32 , sizeof( V_110 ) , & V_110 ) ;
memcpy ( & V_32 -> V_105 , V_105 , sizeof( struct V_104 ) ) ;
V_71:
return V_32 ;
}
struct V_3 * F_30 ( const struct V_5 * V_6 )
{
struct V_3 * V_32 ;
struct V_121 V_122 ;
int V_15 ;
T_13 V_123 ;
T_4 V_124 , V_125 ;
struct V_5 * V_126 = (struct V_5 * ) V_6 ;
struct V_127 * V_128 = (struct V_127 * ) & V_6 -> V_84 . V_129 ;
struct V_130 V_131 [ V_132 ] ;
struct V_133 * V_134 ;
memset ( V_131 , 0 , sizeof( V_131 ) ) ;
V_123 = F_31 ( V_128 ) ;
F_32 ( L_1 , V_135 , V_123 ) ;
V_124 = F_33 ( V_128 , V_131 ) ;
V_125 = F_34 ( V_128 ) ;
V_122 . V_136 = F_14 ( V_123 ) ;
V_122 . V_48 = F_14 ( V_6 -> V_48 ) ;
V_122 . V_137 = F_6 ( V_124 ) ;
V_122 . V_125 = F_6 ( V_125 ) ;
V_15 = sizeof( V_122 )
+ sizeof( struct V_130 ) * V_124
+ sizeof( T_13 ) * V_125 ;
V_32 = F_19 ( V_6 , V_138 , 0 , V_15 , V_94 ) ;
if ( ! V_32 )
goto V_71;
V_32 -> V_92 = V_6 -> V_84 . V_139 ;
V_32 -> V_18 . V_140 =
F_7 ( V_32 , sizeof( V_122 ) , & V_122 ) ;
if ( V_124 )
F_7 ( V_32 , sizeof( T_13 ) * V_124 ,
V_131 ) ;
if ( V_125 ) {
V_126 -> V_141 . V_142 += V_125 ;
F_7 ( V_32 , sizeof( T_13 ) * V_125 ,
F_35 ( V_128 ) ) ;
}
if ( ++ V_126 -> V_84 . V_143 == 0 ) {
F_36 (trans, &asoc->peer.transport_addr_list,
transports)
V_134 -> V_143 = 0 ;
V_126 -> V_84 . V_143 = 1 ;
}
V_71:
return V_32 ;
}
struct V_3 * F_37 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_32 ;
T_16 V_144 ;
T_13 V_123 ;
V_123 = F_31 ( & V_6 -> V_84 . V_129 ) ;
V_144 . V_136 = F_14 ( V_123 ) ;
V_32 = F_19 ( V_6 , V_145 , 0 ,
sizeof( T_16 ) , V_94 ) ;
if ( ! V_32 )
goto V_71;
V_32 -> V_18 . V_146 =
F_7 ( V_32 , sizeof( V_144 ) , & V_144 ) ;
if ( V_4 )
V_32 -> V_92 = V_4 -> V_92 ;
V_71:
return V_32 ;
}
struct V_3 * F_38 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_32 ;
V_32 = F_19 ( V_6 , V_147 , 0 , 0 ,
V_94 ) ;
if ( V_32 && V_4 )
V_32 -> V_92 = V_4 -> V_92 ;
return V_32 ;
}
struct V_3 * F_39 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_32 ;
T_10 V_107 = 0 ;
V_107 |= V_6 ? 0 : V_148 ;
V_32 = F_19 ( V_6 , V_149 , V_107 ,
0 , V_94 ) ;
if ( V_32 && V_4 )
V_32 -> V_92 = V_4 -> V_92 ;
return V_32 ;
}
struct V_3 * F_40 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
const T_2 V_150 )
{
struct V_3 * V_32 ;
T_10 V_107 = 0 ;
if ( ! V_6 ) {
if ( V_4 && V_4 -> V_151 &&
V_4 -> V_151 -> type == V_70 )
V_107 = 0 ;
else
V_107 = V_148 ;
}
V_32 = F_19 ( V_6 , V_152 , V_107 , V_150 ,
V_94 ) ;
if ( V_32 && V_4 )
V_32 -> V_92 = V_4 -> V_92 ;
return V_32 ;
}
struct V_3 * F_41 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 , T_13 V_112 )
{
struct V_3 * V_32 ;
T_17 V_153 ;
V_32 = F_40 ( V_6 , V_4 , sizeof( T_3 )
+ sizeof( V_112 ) ) ;
if ( ! V_32 )
goto V_154;
V_153 = F_14 ( V_112 ) ;
F_5 ( V_32 , V_155 , sizeof( V_153 ) ) ;
F_7 ( V_32 , sizeof( V_153 ) , ( const void * ) & V_153 ) ;
if ( V_4 )
V_32 -> V_92 = V_4 -> V_92 ;
V_154:
return V_32 ;
}
struct V_3 * F_42 ( const struct V_5 * V_6 ,
struct V_156 * V_157 ,
T_2 V_13 )
{
struct V_3 * V_32 ;
void * V_153 = NULL ;
int V_14 ;
V_32 = F_40 ( V_6 , NULL , sizeof( T_3 ) + V_13 ) ;
if ( ! V_32 )
goto V_158;
if ( V_13 ) {
V_153 = F_43 ( V_13 , V_159 ) ;
if ( ! V_153 )
goto V_160;
V_14 = F_44 ( V_153 , V_157 , V_13 ) ;
if ( V_14 < 0 )
goto V_161;
}
F_5 ( V_32 , V_162 , V_13 ) ;
F_7 ( V_32 , V_13 , V_153 ) ;
if ( V_13 )
F_21 ( V_153 ) ;
return V_32 ;
V_161:
F_21 ( V_153 ) ;
V_160:
F_45 ( V_32 ) ;
V_32 = NULL ;
V_158:
return V_32 ;
}
static void * F_20 ( struct V_3 * V_4 , int V_15 ,
const void * V_163 )
{
void * V_164 ;
int V_165 = F_18 ( V_4 -> V_151 -> V_17 ) ;
V_164 = F_46 ( V_4 -> V_2 , V_15 ) ;
if ( V_163 )
memcpy ( V_164 , V_163 , V_15 ) ;
else
memset ( V_164 , 0 , V_15 ) ;
V_4 -> V_151 -> V_17 = F_6 ( V_165 + V_15 ) ;
V_4 -> V_166 = F_47 ( V_4 -> V_2 ) ;
return V_164 ;
}
struct V_3 * F_48 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
const T_10 * V_153 ,
const T_2 V_13 )
{
struct V_3 * V_32 ;
struct V_167 V_168 ;
V_32 = F_40 ( V_6 , V_4 , sizeof( T_3 ) + V_13
+ sizeof( T_11 ) ) ;
if ( ! V_32 )
goto V_169;
F_5 ( V_32 , V_170 , V_13
+ sizeof( T_11 ) ) ;
V_168 . type = F_6 ( V_4 -> V_151 -> type ) ;
V_168 . V_17 = V_4 -> V_151 -> V_17 ;
F_7 ( V_32 , V_13 , V_153 ) ;
F_20 ( V_32 , sizeof( T_11 ) , & V_168 ) ;
V_169:
return V_32 ;
}
struct V_3 * F_49 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
struct V_167 * V_171 )
{
struct V_3 * V_32 ;
static const char error [] = L_2 ;
T_2 V_172 = sizeof( error ) + sizeof( T_3 ) +
sizeof( T_11 ) ;
V_32 = F_40 ( V_6 , V_4 , V_172 ) ;
if ( ! V_32 )
goto V_71;
F_5 ( V_32 , V_170 ,
sizeof( error ) + sizeof( T_11 ) ) ;
F_7 ( V_32 , sizeof( error ) , error ) ;
F_20 ( V_32 , sizeof( T_11 ) , V_171 ) ;
V_71:
return V_32 ;
}
struct V_3 * F_50 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_32 ;
static const char error [] = L_3 ;
T_2 V_172 = sizeof( error ) + sizeof( T_3 ) ;
V_32 = F_40 ( V_6 , V_4 , V_172 ) ;
if ( ! V_32 )
goto V_71;
F_5 ( V_32 , V_170 , sizeof( error ) ) ;
F_7 ( V_32 , sizeof( error ) , error ) ;
V_71:
return V_32 ;
}
struct V_3 * F_51 ( const struct V_5 * V_6 ,
const struct V_133 * V_92 )
{
struct V_3 * V_32 ;
T_18 V_173 ;
V_32 = F_19 ( V_6 , V_174 , 0 ,
sizeof( V_173 ) , V_94 ) ;
if ( ! V_32 )
goto V_71;
V_173 . V_73 . type = V_175 ;
V_173 . V_73 . V_17 = F_6 ( sizeof( T_18 ) ) ;
V_173 . V_176 = V_92 -> V_177 ;
V_173 . V_178 = V_179 ;
V_173 . V_180 = V_92 -> V_180 ;
V_32 -> V_92 = (struct V_133 * ) V_92 ;
V_32 -> V_18 . V_181 = F_7 ( V_32 , sizeof( V_173 ) ,
& V_173 ) ;
V_71:
return V_32 ;
}
struct V_3 * F_52 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
const void * V_153 , const T_2 V_13 )
{
struct V_3 * V_32 ;
V_32 = F_19 ( V_6 , V_182 , 0 , V_13 ,
V_94 ) ;
if ( ! V_32 )
goto V_71;
V_32 -> V_18 . V_181 = F_7 ( V_32 , V_13 , V_153 ) ;
if ( V_4 )
V_32 -> V_92 = V_4 -> V_92 ;
V_71:
return V_32 ;
}
static struct V_3 * F_53 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
T_2 V_183 )
{
struct V_3 * V_32 ;
V_32 = F_19 ( V_6 , V_184 , 0 ,
sizeof( T_3 ) + V_183 , V_94 ) ;
if ( ! V_32 )
goto V_71;
if ( V_4 )
V_32 -> V_92 = V_4 -> V_92 ;
V_71:
return V_32 ;
}
static inline struct V_3 * F_54 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
T_2 V_183 = V_6 ? V_6 -> V_185 : 0 ;
if ( ! V_183 )
V_183 = V_186 ;
return F_53 ( V_6 , V_4 , V_183 ) ;
}
struct V_3 * F_55 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
T_1 V_12 , const void * V_153 ,
T_2 V_13 , T_2 V_187 )
{
struct V_3 * V_32 ;
V_32 = F_53 ( V_6 , V_4 , V_13 + V_187 ) ;
if ( ! V_32 )
goto V_71;
F_5 ( V_32 , V_12 , V_13 + V_187 ) ;
F_7 ( V_32 , V_13 , V_153 ) ;
if ( V_187 )
F_20 ( V_32 , V_187 , NULL ) ;
V_71:
return V_32 ;
}
struct V_3 * F_56 ( const struct V_5 * V_6 )
{
struct V_3 * V_32 ;
struct V_188 * V_189 ;
struct V_190 V_191 ;
T_10 * V_192 ;
V_189 = F_57 ( V_6 ) ;
if ( F_58 ( ! V_189 ) )
return NULL ;
V_32 = F_19 ( V_6 , V_69 , 0 ,
V_189 -> V_193 + sizeof( V_194 ) ,
V_94 ) ;
if ( ! V_32 )
return NULL ;
V_191 . V_195 = F_6 ( V_189 -> V_195 ) ;
V_191 . V_196 = F_6 ( V_6 -> V_197 ) ;
V_32 -> V_18 . V_191 = F_7 ( V_32 , sizeof( V_194 ) ,
& V_191 ) ;
V_192 = F_46 ( V_32 -> V_2 , V_189 -> V_193 ) ;
memset ( V_192 , 0 , V_189 -> V_193 ) ;
V_32 -> V_151 -> V_17 =
F_6 ( F_18 ( V_32 -> V_151 -> V_17 ) + V_189 -> V_193 ) ;
V_32 -> V_166 = F_47 ( V_32 -> V_2 ) ;
return V_32 ;
}
struct V_3 * F_59 ( struct V_1 * V_2 ,
const struct V_5 * V_6 ,
struct V_198 * V_7 , T_5 V_23 )
{
struct V_3 * V_32 ;
V_32 = F_60 ( V_199 , V_23 ) ;
if ( ! V_32 )
goto V_71;
if ( ! V_7 )
F_32 ( L_4 , V_135 , V_2 ) ;
F_61 ( & V_32 -> V_200 ) ;
V_32 -> V_2 = V_2 ;
V_32 -> V_6 = (struct V_5 * ) V_6 ;
V_32 -> V_201 = 1 ;
V_32 -> V_202 = V_203 ;
F_61 ( & V_32 -> V_204 ) ;
F_61 ( & V_32 -> V_205 ) ;
F_62 ( V_4 ) ;
F_63 ( & V_32 -> V_206 , 1 ) ;
V_71:
return V_32 ;
}
void F_64 ( struct V_3 * V_4 , union V_207 * V_208 ,
union V_207 * V_209 )
{
memcpy ( & V_4 -> V_210 , V_208 , sizeof( union V_207 ) ) ;
memcpy ( & V_4 -> V_209 , V_209 , sizeof( union V_207 ) ) ;
}
const union V_207 * F_65 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_92 ) {
return & V_4 -> V_92 -> V_177 ;
} else {
return & V_4 -> V_210 ;
}
}
static struct V_3 * F_66 ( const struct V_5 * V_6 ,
T_10 type , T_10 V_107 , int V_13 ,
T_5 V_23 )
{
struct V_3 * V_32 ;
T_19 * V_151 ;
struct V_1 * V_2 ;
struct V_198 * V_7 ;
V_2 = F_67 ( F_16 ( sizeof( T_19 ) + V_13 ) , V_23 ) ;
if ( ! V_2 )
goto V_71;
V_151 = ( T_19 * ) F_46 ( V_2 , sizeof( T_19 ) ) ;
V_151 -> type = type ;
V_151 -> V_107 = V_107 ;
V_151 -> V_17 = F_6 ( sizeof( T_19 ) ) ;
V_7 = V_6 ? V_6 -> V_8 . V_7 : NULL ;
V_32 = F_59 ( V_2 , V_6 , V_7 , V_23 ) ;
if ( ! V_32 ) {
F_68 ( V_2 ) ;
goto V_71;
}
V_32 -> V_151 = V_151 ;
V_32 -> V_166 = ( ( T_10 * ) V_151 ) + sizeof( struct V_211 ) ;
if ( F_69 ( type , V_6 ) )
V_32 -> V_212 = 1 ;
return V_32 ;
V_71:
return NULL ;
}
static struct V_3 * F_29 ( const struct V_5 * V_6 ,
T_10 V_107 , int V_13 , T_5 V_23 )
{
return F_66 ( V_6 , V_213 , V_107 , V_13 , V_23 ) ;
}
static struct V_3 * F_19 ( const struct V_5 * V_6 ,
T_10 type , T_10 V_107 , int V_13 ,
T_5 V_23 )
{
struct V_3 * V_4 ;
V_4 = F_66 ( V_6 , type , V_107 , V_13 , V_23 ) ;
if ( V_4 )
F_2 ( V_4 ) ;
return V_4 ;
}
static void F_70 ( struct V_3 * V_4 )
{
F_71 ( ! F_72 ( & V_4 -> V_200 ) ) ;
F_73 ( & V_4 -> V_204 ) ;
F_74 ( V_4 -> V_2 ) ;
F_74 ( V_4 -> V_214 ) ;
F_75 ( V_4 ) ;
F_76 ( V_199 , V_4 ) ;
}
void F_45 ( struct V_3 * V_4 )
{
if ( V_4 -> V_157 )
F_77 ( V_4 -> V_157 ) ;
F_78 ( V_4 ) ;
}
void F_79 ( struct V_3 * V_215 )
{
F_80 ( & V_215 -> V_206 ) ;
}
void F_78 ( struct V_3 * V_215 )
{
if ( F_81 ( & V_215 -> V_206 ) )
F_70 ( V_215 ) ;
}
void * F_7 ( struct V_3 * V_4 , int V_15 , const void * V_163 )
{
void * V_164 ;
void * V_216 ;
int V_165 = F_18 ( V_4 -> V_151 -> V_17 ) ;
int V_217 = F_16 ( V_165 ) - V_165 ;
V_216 = F_46 ( V_4 -> V_2 , V_217 ) ;
V_164 = F_46 ( V_4 -> V_2 , V_15 ) ;
memset ( V_216 , 0 , V_217 ) ;
memcpy ( V_164 , V_163 , V_15 ) ;
V_4 -> V_151 -> V_17 = F_6 ( V_165 + V_217 + V_15 ) ;
V_4 -> V_166 = F_47 ( V_4 -> V_2 ) ;
return V_164 ;
}
static void * F_10 ( struct V_3 * V_4 ,
int V_15 , const void * V_163 )
{
if ( F_9 ( V_4 -> V_2 ) >= V_15 )
return F_7 ( V_4 , V_15 , V_163 ) ;
else
return NULL ;
}
int F_82 ( struct V_3 * V_4 , int V_15 ,
struct V_218 * V_219 )
{
void * V_164 ;
V_164 = F_46 ( V_4 -> V_2 , V_15 ) ;
if ( ! F_83 ( V_164 , V_15 , V_219 ) )
return - V_220 ;
V_4 -> V_151 -> V_17 =
F_6 ( F_18 ( V_4 -> V_151 -> V_17 ) + V_15 ) ;
V_4 -> V_166 = F_47 ( V_4 -> V_2 ) ;
return 0 ;
}
void F_84 ( struct V_3 * V_4 )
{
struct V_221 * V_157 ;
struct V_3 * V_222 ;
struct V_223 * V_113 ;
T_4 V_108 ;
T_4 V_224 ;
if ( V_4 -> V_225 )
return;
V_224 = F_18 ( V_4 -> V_18 . V_120 -> V_113 ) ;
V_113 = V_4 -> V_6 -> V_113 ;
V_157 = V_4 -> V_157 ;
F_36 (lchunk, &msg->chunks, frag_list) {
if ( V_222 -> V_151 -> V_107 & V_119 ) {
V_108 = 0 ;
} else {
if ( V_222 -> V_151 -> V_107 & V_226 )
V_108 = F_85 ( V_113 , V_227 , V_224 ) ;
else
V_108 = F_86 ( V_113 , V_227 , V_224 ) ;
}
V_222 -> V_18 . V_120 -> V_108 = F_6 ( V_108 ) ;
V_222 -> V_225 = 1 ;
}
}
void F_87 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_228 ) {
V_4 -> V_18 . V_120 -> V_112 =
F_14 ( F_88 ( V_4 -> V_6 ) ) ;
V_4 -> V_228 = 1 ;
}
}
struct V_5 * F_89 ( const struct V_26 * V_27 ,
struct V_3 * V_4 ,
T_5 V_23 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
T_20 V_229 ;
V_229 = F_90 ( F_65 ( V_4 ) ) ;
V_6 = F_91 ( V_27 , V_27 -> V_8 . V_7 , V_229 , V_23 ) ;
if ( ! V_6 )
goto V_71;
V_6 -> V_230 = 1 ;
V_2 = V_4 -> V_2 ;
F_4 ( V_2 ) -> V_10 -> V_231 ( & V_6 -> V_46 . V_232 , V_2 , 1 ) ;
V_71:
return V_6 ;
}
static T_12 * F_23 ( const struct V_26 * V_27 ,
const struct V_5 * V_6 ,
const struct V_3 * V_233 ,
int * V_81 ,
const T_10 * V_234 , int V_34 )
{
T_12 * V_32 ;
struct V_235 * V_80 ;
int V_236 , V_237 ;
V_236 = sizeof( T_11 ) +
( sizeof( struct V_235 ) -
sizeof( struct V_238 ) ) ;
V_237 = sizeof( struct V_238 )
+ F_18 ( V_233 -> V_151 -> V_17 ) + V_34 ;
if ( V_237 % V_239 )
V_237 += V_239
- ( V_237 % V_239 ) ;
* V_81 = V_236 + V_237 ;
V_32 = F_92 ( * V_81 , V_94 ) ;
if ( ! V_32 )
goto V_71;
V_80 = (struct V_235 * ) V_32 -> V_240 ;
V_32 -> V_241 . type = V_242 ;
V_32 -> V_241 . V_17 = F_6 ( * V_81 ) ;
V_80 -> V_46 = V_6 -> V_46 ;
V_80 -> V_46 . V_243 = V_34 ;
V_80 -> V_46 . V_86 = V_6 -> V_84 . V_86 ;
V_80 -> V_46 . V_66 = V_6 -> V_84 . V_66 ;
V_80 -> V_46 . V_244 = F_93 ( V_6 -> V_245 ,
F_94 () ) ;
memcpy ( & V_80 -> V_46 . V_246 [ 0 ] , V_233 -> V_151 ,
F_18 ( V_233 -> V_151 -> V_17 ) ) ;
memcpy ( ( T_10 * ) & V_80 -> V_46 . V_246 [ 0 ] +
F_18 ( V_233 -> V_151 -> V_17 ) , V_234 , V_34 ) ;
if ( F_15 ( V_27 -> V_8 . V_7 ) -> V_192 ) {
F_95 ( V_247 , F_15 ( V_27 -> V_8 . V_7 ) -> V_192 ) ;
int V_14 ;
V_247 -> V_248 = F_15 ( V_27 -> V_8 . V_7 ) -> V_192 ;
V_247 -> V_107 = 0 ;
V_14 = F_96 ( V_247 -> V_248 , V_27 -> V_249 ,
sizeof( V_27 -> V_249 ) ) ? :
F_97 ( V_247 , ( V_250 * ) & V_80 -> V_46 , V_237 ,
V_80 -> V_251 ) ;
F_98 ( V_247 ) ;
if ( V_14 )
goto V_252;
}
return V_32 ;
V_252:
F_21 ( V_32 ) ;
V_71:
* V_81 = 0 ;
return NULL ;
}
struct V_5 * F_99 (
const struct V_26 * V_27 ,
const struct V_5 * V_6 ,
struct V_3 * V_4 , T_5 V_23 ,
int * error , struct V_3 * * V_253 )
{
struct V_5 * V_32 = NULL ;
struct V_235 * V_80 ;
struct V_238 * V_254 ;
int V_236 , V_237 , V_255 ;
T_10 * V_256 = V_27 -> V_256 ;
unsigned int V_15 ;
T_20 V_229 ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_21 V_257 ;
V_236 = sizeof( T_19 ) +
( sizeof( struct V_235 ) -
sizeof( struct V_238 ) ) ;
V_237 = F_18 ( V_4 -> V_151 -> V_17 ) - V_236 ;
V_255 = V_236 + sizeof( struct V_238 ) ;
V_15 = F_18 ( V_4 -> V_151 -> V_17 ) ;
if ( V_15 < V_255 + sizeof( struct V_211 ) )
goto V_258;
if ( V_237 % V_239 )
goto V_258;
V_80 = V_4 -> V_18 . V_95 ;
V_254 = & V_80 -> V_46 ;
if ( ! F_15 ( V_27 -> V_8 . V_7 ) -> V_192 )
goto V_259;
{
F_95 ( V_247 , F_15 ( V_27 -> V_8 . V_7 ) -> V_192 ) ;
int V_14 ;
V_247 -> V_248 = F_15 ( V_27 -> V_8 . V_7 ) -> V_192 ;
V_247 -> V_107 = 0 ;
V_14 = F_96 ( V_247 -> V_248 , V_27 -> V_249 ,
sizeof( V_27 -> V_249 ) ) ? :
F_97 ( V_247 , ( V_250 * ) V_254 , V_237 ,
V_256 ) ;
F_98 ( V_247 ) ;
if ( V_14 ) {
* error = - V_260 ;
goto V_261;
}
}
if ( memcmp ( V_256 , V_80 -> V_251 , V_262 ) ) {
* error = - V_263 ;
goto V_261;
}
V_259:
if ( F_100 ( V_4 -> V_264 -> V_265 ) != V_254 -> V_47 ) {
* error = - V_266 ;
goto V_261;
}
if ( V_4 -> V_264 -> V_210 != V_254 -> V_232 . V_267 . V_268 ||
F_18 ( V_4 -> V_264 -> V_209 ) != V_254 -> V_269 ) {
* error = - V_270 ;
goto V_261;
}
if ( F_101 ( V_27 -> V_8 . V_7 , V_271 ) )
V_257 = F_102 ( V_2 ) ;
else
V_257 = F_94 () ;
if ( ! V_6 && F_103 ( V_254 -> V_244 , V_257 ) ) {
V_15 = F_18 ( V_4 -> V_151 -> V_17 ) ;
* V_253 = F_53 ( V_6 , V_4 , V_15 ) ;
if ( * V_253 ) {
T_22 V_272 = F_104 ( F_105 ( V_257 , V_254 -> V_244 ) ) ;
T_17 V_273 = F_14 ( V_272 ) ;
F_5 ( * V_253 , V_274 ,
sizeof( V_273 ) ) ;
F_7 ( * V_253 , sizeof( V_273 ) , & V_273 ) ;
* error = - V_275 ;
} else
* error = - V_260 ;
goto V_261;
}
V_229 = F_90 ( F_65 ( V_4 ) ) ;
V_32 = F_91 ( V_27 , V_27 -> V_8 . V_7 , V_229 , V_23 ) ;
if ( ! V_32 ) {
* error = - V_260 ;
goto V_261;
}
V_32 -> V_84 . V_276 = F_18 ( V_4 -> V_264 -> V_210 ) ;
memcpy ( & V_32 -> V_46 , V_254 , sizeof( * V_254 ) ) ;
if ( F_106 ( V_32 , V_254 ,
V_94 ) < 0 ) {
* error = - V_260 ;
goto V_261;
}
if ( F_72 ( & V_32 -> V_8 . V_82 . V_277 ) ) {
F_107 ( & V_32 -> V_8 . V_82 , & V_4 -> V_209 ,
sizeof( V_4 -> V_209 ) , V_278 ,
V_94 ) ;
}
V_32 -> V_279 = V_32 -> V_46 . V_54 ;
V_32 -> V_280 = V_32 -> V_279 - 1 ;
V_32 -> V_281 = V_32 -> V_46 . V_54 ;
V_32 -> V_282 = V_32 -> V_46 . V_54 ;
V_32 -> V_283 = V_32 -> V_280 ;
V_32 -> V_84 . V_86 = V_32 -> V_46 . V_86 ;
V_32 -> V_84 . V_66 = V_32 -> V_46 . V_66 ;
return V_32 ;
V_261:
if ( V_32 )
F_108 ( V_32 ) ;
return NULL ;
V_258:
* error = - V_284 ;
goto V_261;
}
static int F_109 ( const struct V_5 * V_6 ,
T_23 V_285 ,
struct V_3 * V_4 ,
struct V_3 * * V_253 )
{
struct V_286 V_287 ;
T_4 V_15 ;
V_15 = F_16 ( sizeof( V_287 ) ) ;
if ( ! * V_253 )
* V_253 = F_53 ( V_6 , V_4 , V_15 ) ;
if ( * V_253 ) {
V_287 . V_288 = F_14 ( 1 ) ;
V_287 . type = V_285 ;
F_5 ( * V_253 , V_289 ,
sizeof( V_287 ) ) ;
F_7 ( * V_253 , sizeof( V_287 ) , & V_287 ) ;
}
return 0 ;
}
static int F_110 ( const struct V_5 * V_6 ,
struct V_3 * V_4 ,
struct V_3 * * V_253 )
{
if ( ! * V_253 )
* V_253 = F_53 ( V_6 , V_4 , 0 ) ;
if ( * V_253 )
F_5 ( * V_253 , V_290 , 0 ) ;
return 0 ;
}
static int F_111 ( const struct V_5 * V_6 ,
struct V_167 * V_171 ,
const struct V_3 * V_4 ,
struct V_3 * * V_253 )
{
if ( * V_253 )
F_45 ( * V_253 ) ;
* V_253 = F_49 ( V_6 , V_4 , V_171 ) ;
return 0 ;
}
static int F_112 ( const struct V_5 * V_6 ,
union V_29 V_171 ,
struct V_3 * V_4 ,
struct V_3 * * V_253 )
{
T_4 V_15 = F_18 ( V_171 . V_241 -> V_17 ) ;
if ( * V_253 )
F_45 ( * V_253 ) ;
* V_253 = F_53 ( V_6 , V_4 , V_15 ) ;
if ( * V_253 ) {
F_5 ( * V_253 , V_291 , V_15 ) ;
F_7 ( * V_253 , V_15 , V_171 . V_74 ) ;
}
return 0 ;
}
static int F_113 ( struct V_25 * V_25 , union V_29 V_171 )
{
T_4 V_41 = F_18 ( V_171 . V_241 -> V_17 ) - sizeof( T_11 ) ;
int V_292 = 0 ;
int V_293 = 0 ;
int V_294 ;
for ( V_294 = 0 ; V_294 < V_41 ; V_294 ++ ) {
switch ( V_171 . V_295 -> V_296 [ V_294 ] ) {
case V_69 :
V_292 = 1 ;
break;
case V_62 :
case V_63 :
V_293 = 1 ;
break;
}
}
if ( V_25 -> V_60 . V_297 )
return 1 ;
if ( V_25 -> V_60 . V_61 && ! V_292 && V_293 )
return 0 ;
return 1 ;
}
static void F_114 ( struct V_5 * V_6 ,
union V_29 V_171 )
{
struct V_25 * V_25 = F_12 ( V_6 -> V_8 . V_7 ) ;
T_4 V_41 = F_18 ( V_171 . V_241 -> V_17 ) - sizeof( T_11 ) ;
int V_294 ;
for ( V_294 = 0 ; V_294 < V_41 ; V_294 ++ ) {
switch ( V_171 . V_295 -> V_296 [ V_294 ] ) {
case V_65 :
if ( V_6 -> V_64 &&
! V_6 -> V_84 . V_88 )
V_6 -> V_84 . V_88 = 1 ;
break;
case V_298 :
if ( V_6 -> V_58 && ! V_6 -> V_84 . V_86 )
V_6 -> V_84 . V_86 = 1 ;
break;
case V_69 :
if ( V_6 -> V_27 -> V_67 )
V_6 -> V_84 . V_89 = 1 ;
break;
case V_62 :
case V_63 :
if ( V_25 -> V_60 . V_61 )
V_6 -> V_84 . V_87 = 1 ;
break;
default:
break;
}
}
}
static T_24 F_115 ( const struct V_5 * V_6 ,
union V_29 V_171 ,
struct V_3 * V_4 ,
struct V_3 * * V_253 )
{
int V_32 = V_299 ;
switch ( V_171 . V_241 -> type & V_300 ) {
case V_301 :
V_32 = V_302 ;
break;
case V_303 :
break;
case V_304 :
V_32 = V_302 ;
case V_305 :
if ( NULL == * V_253 )
* V_253 = F_54 ( V_6 , V_4 ) ;
if ( * V_253 ) {
if ( ! F_8 ( * V_253 , V_306 ,
F_16 ( F_18 ( V_171 . V_241 -> V_17 ) ) ) )
F_10 ( * V_253 ,
F_16 ( F_18 ( V_171 . V_241 -> V_17 ) ) ,
V_171 . V_74 ) ;
} else {
V_32 = V_260 ;
}
break;
default:
break;
}
return V_32 ;
}
static T_24 F_116 ( struct V_25 * V_25 ,
const struct V_26 * V_27 ,
const struct V_5 * V_6 ,
union V_29 V_171 ,
T_25 V_307 ,
struct V_3 * V_4 ,
struct V_3 * * V_158 )
{
struct V_308 * V_309 ;
int V_32 = V_299 ;
T_4 V_310 , V_311 = 0 ;
int V_294 ;
switch ( V_171 . V_241 -> type ) {
case V_312 :
case V_313 :
case V_314 :
case V_75 :
case V_242 :
case V_175 :
case V_315 :
case V_316 :
case V_77 :
break;
case V_76 :
if ( ! F_113 ( V_25 , V_171 ) )
return V_317 ;
break;
case V_318 :
if ( V_25 -> V_60 . V_61 )
break;
goto V_319;
case V_320 :
F_112 ( V_6 , V_171 , V_4 , V_158 ) ;
V_32 = V_317 ;
break;
case V_321 :
if ( V_27 -> V_58 )
break;
goto V_319;
case V_322 :
if ( ! V_27 -> V_67 )
goto V_319;
if ( V_323 !=
F_18 ( V_171 . V_241 -> V_17 ) - sizeof( T_11 ) ) {
F_111 ( V_6 , V_171 . V_241 ,
V_4 , V_158 ) ;
V_32 = V_317 ;
}
break;
case V_324 :
if ( ! V_27 -> V_67 )
goto V_319;
if ( 260 < F_18 ( V_171 . V_241 -> V_17 ) ) {
F_111 ( V_6 , V_171 . V_241 ,
V_4 , V_158 ) ;
V_32 = V_317 ;
}
break;
case V_325 :
if ( ! V_27 -> V_67 )
goto V_319;
V_309 = (struct V_308 * ) V_171 . V_241 ;
V_310 = ( F_18 ( V_171 . V_241 -> V_17 ) - sizeof( T_11 ) ) >> 1 ;
for ( V_294 = 0 ; V_294 < V_310 ; V_294 ++ ) {
V_311 = F_18 ( V_309 -> V_326 [ V_294 ] ) ;
if ( V_311 == V_327 )
break;
}
if ( V_311 != V_327 ) {
F_111 ( V_6 , V_171 . V_241 , V_4 ,
V_158 ) ;
V_32 = V_317 ;
}
break;
V_319:
default:
F_32 ( L_5 ,
V_135 , F_18 ( V_171 . V_241 -> type ) , V_307 ) ;
V_32 = F_115 ( V_6 , V_171 , V_4 , V_158 ) ;
break;
}
return V_32 ;
}
int F_117 ( struct V_25 * V_25 , const struct V_26 * V_27 ,
const struct V_5 * V_6 , T_25 V_307 ,
T_26 * V_246 , struct V_3 * V_4 ,
struct V_3 * * V_253 )
{
union V_29 V_171 ;
bool V_328 = false ;
int V_329 ;
if ( V_246 -> V_72 . V_50 == 0 ||
V_246 -> V_72 . V_52 == 0 ||
V_246 -> V_72 . V_45 == 0 ||
F_100 ( V_246 -> V_72 . V_48 ) < V_330 )
return F_110 ( V_6 , V_4 , V_253 ) ;
F_118 (param, peer_init, init_hdr.params) {
if ( V_171 . V_241 -> type == V_242 )
V_328 = true ;
}
if ( V_171 . V_74 != ( void * ) V_4 -> V_166 )
return F_111 ( V_6 , V_171 . V_241 , V_4 , V_253 ) ;
if ( ( V_90 == V_307 ) && ! V_328 )
return F_109 ( V_6 , V_242 ,
V_4 , V_253 ) ;
F_118 (param, peer_init, init_hdr.params) {
V_329 = F_116 ( V_25 , V_27 , V_6 , V_171 , V_307 ,
V_4 , V_253 ) ;
switch ( V_329 ) {
case V_317 :
case V_260 :
return 0 ;
case V_302 :
return 1 ;
case V_299 :
default:
break;
}
}
return 1 ;
}
int F_119 ( struct V_5 * V_6 , struct V_3 * V_4 ,
const union V_207 * V_232 ,
T_26 * V_246 , T_5 V_23 )
{
struct V_25 * V_25 = F_12 ( V_6 -> V_8 . V_7 ) ;
union V_29 V_171 ;
struct V_133 * V_92 ;
struct V_331 * V_332 , * V_230 ;
struct V_333 * V_10 ;
union V_207 V_334 ;
char * V_80 ;
int V_335 = 0 ;
if ( ! F_120 ( V_6 , V_232 , V_23 , V_336 ) )
goto V_337;
if ( F_121 ( F_65 ( V_4 ) , V_232 ) )
V_335 = 1 ;
F_118 (param, peer_init, init_hdr.params) {
if ( ! V_335 && ( V_171 . V_241 -> type == V_312 ||
V_171 . V_241 -> type == V_313 ) ) {
V_10 = F_122 ( F_123 ( V_171 . V_241 -> type ) ) ;
V_10 -> V_338 ( & V_334 , V_171 . V_334 ,
V_4 -> V_264 -> V_210 , 0 ) ;
if ( F_121 ( F_65 ( V_4 ) , & V_334 ) )
V_335 = 1 ;
}
if ( ! F_124 ( V_6 , V_171 , V_232 , V_23 ) )
goto V_339;
}
if ( ! V_335 )
goto V_339;
if ( V_6 -> V_84 . V_89 && ( ! V_6 -> V_84 . V_340 ||
! V_6 -> V_84 . V_341 ) )
V_6 -> V_84 . V_89 = 0 ;
if ( ! V_25 -> V_60 . V_297 &&
( V_6 -> V_84 . V_87 && ! V_6 -> V_84 . V_89 ) ) {
V_6 -> V_84 . V_342 |= ( V_343 |
V_344 |
V_318 ) ;
V_6 -> V_84 . V_87 = 0 ;
goto V_339;
}
F_125 (pos, temp, &asoc->peer.transport_addr_list) {
V_92 = F_126 ( V_332 , struct V_133 , V_345 ) ;
if ( V_92 -> V_346 == V_347 ) {
F_127 ( V_6 , V_92 ) ;
}
}
V_6 -> V_84 . V_294 . V_45 =
F_100 ( V_246 -> V_72 . V_45 ) ;
V_6 -> V_84 . V_294 . V_48 =
F_100 ( V_246 -> V_72 . V_48 ) ;
V_6 -> V_84 . V_294 . V_50 =
F_18 ( V_246 -> V_72 . V_50 ) ;
V_6 -> V_84 . V_294 . V_52 =
F_18 ( V_246 -> V_72 . V_52 ) ;
V_6 -> V_84 . V_294 . V_54 =
F_100 ( V_246 -> V_72 . V_54 ) ;
V_6 -> V_348 = V_6 -> V_84 . V_294 . V_54 ;
if ( V_6 -> V_46 . V_51 >
F_18 ( V_246 -> V_72 . V_52 ) ) {
V_6 -> V_46 . V_51 =
F_18 ( V_246 -> V_72 . V_52 ) ;
}
if ( V_6 -> V_46 . V_53 >
F_18 ( V_246 -> V_72 . V_50 ) ) {
V_6 -> V_46 . V_53 =
F_18 ( V_246 -> V_72 . V_50 ) ;
}
V_6 -> V_46 . V_349 = V_6 -> V_84 . V_294 . V_45 ;
V_6 -> V_84 . V_49 = V_6 -> V_84 . V_294 . V_48 ;
V_80 = V_6 -> V_84 . V_80 ;
if ( V_80 ) {
V_6 -> V_84 . V_80 = F_128 ( V_80 , V_6 -> V_84 . V_81 , V_23 ) ;
if ( ! V_6 -> V_84 . V_80 )
goto V_339;
}
F_36 (transport, &asoc->peer.transport_addr_list,
transports) {
V_92 -> V_350 = V_6 -> V_84 . V_294 . V_48 ;
}
if ( ! F_129 ( & V_6 -> V_84 . V_129 , V_351 ,
V_6 -> V_84 . V_294 . V_54 , V_23 ) )
goto V_339;
if ( F_130 ( V_6 , V_23 ) )
goto V_339;
if ( ! V_6 -> V_230 && F_131 ( V_6 , V_23 ) )
goto V_339;
V_6 -> V_84 . V_281 = V_6 -> V_84 . V_294 . V_54 - 1 ;
return 1 ;
V_339:
F_125 (pos, temp, &asoc->peer.transport_addr_list) {
V_92 = F_126 ( V_332 , struct V_133 , V_345 ) ;
if ( V_92 -> V_346 != V_336 )
F_127 ( V_6 , V_92 ) ;
}
V_337:
return 0 ;
}
static int F_124 ( struct V_5 * V_6 ,
union V_29 V_171 ,
const union V_207 * V_232 ,
T_5 V_23 )
{
struct V_25 * V_25 = F_12 ( V_6 -> V_8 . V_7 ) ;
union V_207 V_334 ;
int V_294 ;
T_4 V_37 ;
int V_32 = 1 ;
T_20 V_229 ;
T_27 V_352 ;
struct V_333 * V_10 ;
union V_353 * V_354 ;
struct V_133 * V_355 ;
struct V_26 * V_27 = V_6 -> V_27 ;
switch ( V_171 . V_241 -> type ) {
case V_313 :
if ( V_356 != V_6 -> V_8 . V_7 -> V_357 )
break;
goto V_358;
case V_312 :
if ( F_132 ( V_6 -> V_8 . V_7 ) )
break;
V_358:
V_10 = F_122 ( F_123 ( V_171 . V_241 -> type ) ) ;
V_10 -> V_338 ( & V_334 , V_171 . V_334 , F_6 ( V_6 -> V_84 . V_276 ) , 0 ) ;
V_229 = F_90 ( V_232 ) ;
if ( F_133 ( V_25 , & V_334 , V_229 ) )
if ( ! F_120 ( V_6 , & V_334 , V_23 , V_359 ) )
return 0 ;
break;
case V_314 :
if ( ! V_25 -> V_60 . V_360 )
break;
V_352 = F_100 ( V_171 . V_361 -> V_362 ) ;
V_6 -> V_245 = F_134 ( V_6 -> V_245 , V_352 ) ;
break;
case V_320 :
F_32 ( L_6 , V_135 ) ;
break;
case V_75 :
V_6 -> V_84 . V_363 = 0 ;
V_6 -> V_84 . V_364 = 0 ;
if ( V_232 -> V_365 . V_366 == V_367 )
V_6 -> V_84 . V_364 = 1 ;
else if ( V_232 -> V_365 . V_366 == V_368 )
V_6 -> V_84 . V_363 = 1 ;
V_37 = F_18 ( V_171 . V_241 -> V_17 ) - sizeof( T_11 ) ;
if ( V_37 )
V_37 /= sizeof( T_4 ) ;
for ( V_294 = 0 ; V_294 < V_37 ; ++ V_294 ) {
switch ( V_171 . V_37 -> V_38 [ V_294 ] ) {
case V_312 :
V_6 -> V_84 . V_363 = 1 ;
break;
case V_313 :
if ( V_356 == V_6 -> V_8 . V_7 -> V_357 )
V_6 -> V_84 . V_364 = 1 ;
break;
case V_320 :
V_6 -> V_84 . V_369 = 1 ;
break;
default:
break;
}
}
break;
case V_242 :
V_6 -> V_84 . V_81 =
F_18 ( V_171 . V_241 -> V_17 ) - sizeof( T_11 ) ;
V_6 -> V_84 . V_80 = V_171 . V_80 -> V_240 ;
break;
case V_175 :
break;
case V_315 :
break;
case V_316 :
V_6 -> V_84 . V_85 = 1 ;
break;
case V_77 :
V_6 -> V_84 . V_66 = F_100 ( V_171 . V_370 -> V_66 ) ;
break;
case V_318 :
if ( ! V_25 -> V_60 . V_61 )
goto V_371;
V_354 = V_171 . V_74 + sizeof( V_372 ) ;
V_10 = F_122 ( F_123 ( V_354 -> V_241 . type ) ) ;
if ( V_10 == NULL )
break;
V_10 -> V_338 ( & V_334 , V_354 ,
F_6 ( V_6 -> V_84 . V_276 ) , 0 ) ;
if ( ! V_10 -> V_373 ( & V_334 , NULL , NULL ) )
break;
V_355 = F_135 ( V_6 , & V_334 ) ;
if ( ! V_355 )
break;
F_136 ( V_6 , V_355 ) ;
break;
case V_76 :
F_114 ( V_6 , V_171 ) ;
break;
case V_321 :
if ( V_6 -> V_58 ) {
V_6 -> V_84 . V_86 = 1 ;
break;
}
goto V_371;
case V_322 :
if ( ! V_27 -> V_67 )
goto V_371;
V_6 -> V_84 . V_340 = F_128 ( V_171 . V_241 ,
F_18 ( V_171 . V_241 -> V_17 ) , V_23 ) ;
if ( ! V_6 -> V_84 . V_340 ) {
V_32 = 0 ;
break;
}
break;
case V_325 :
if ( ! V_27 -> V_67 )
goto V_371;
V_6 -> V_84 . V_341 = F_128 ( V_171 . V_241 ,
F_18 ( V_171 . V_241 -> V_17 ) , V_23 ) ;
if ( ! V_6 -> V_84 . V_341 ) {
V_32 = 0 ;
break;
}
F_137 ( V_6 , V_171 . V_374 ) ;
break;
case V_324 :
if ( ! V_27 -> V_67 )
goto V_371;
V_6 -> V_84 . V_375 = F_128 ( V_171 . V_241 ,
F_18 ( V_171 . V_241 -> V_17 ) , V_23 ) ;
if ( ! V_6 -> V_84 . V_375 )
V_32 = 0 ;
break;
V_371:
default:
F_32 ( L_7 ,
V_135 , F_18 ( V_171 . V_241 -> type ) , V_6 ) ;
break;
}
return V_32 ;
}
T_13 F_138 ( const struct V_26 * V_27 )
{
T_13 V_376 ;
do {
F_139 ( & V_376 , sizeof( T_13 ) ) ;
} while ( V_376 == 0 );
return V_376 ;
}
T_13 F_140 ( const struct V_26 * V_27 )
{
T_13 V_32 ;
F_139 ( & V_32 , sizeof( T_13 ) ) ;
return V_32 ;
}
static struct V_3 * F_141 ( struct V_5 * V_6 ,
union V_207 * V_334 ,
int V_24 )
{
T_28 V_377 ;
struct V_3 * V_32 ;
int V_17 = sizeof( V_377 ) + V_24 ;
union V_353 V_378 ;
int V_379 ;
struct V_333 * V_10 = F_122 ( V_334 -> V_267 . V_380 ) ;
V_379 = V_10 -> V_381 ( V_334 , & V_378 ) ;
if ( ! V_379 )
return NULL ;
V_17 += V_379 ;
V_32 = F_19 ( V_6 , V_62 , 0 , V_17 ,
V_94 ) ;
if ( ! V_32 )
return NULL ;
V_377 . V_382 = F_14 ( V_6 -> V_281 ++ ) ;
V_32 -> V_18 . V_383 =
F_7 ( V_32 , sizeof( V_377 ) , & V_377 ) ;
V_32 -> V_73 . V_74 =
F_7 ( V_32 , V_379 , & V_378 ) ;
return V_32 ;
}
struct V_3 * F_142 ( struct V_5 * V_6 ,
union V_207 * V_384 ,
struct V_385 * V_30 ,
int V_386 ,
T_1 V_107 )
{
V_372 V_171 ;
struct V_3 * V_32 ;
union V_353 V_354 ;
union V_207 * V_334 ;
void * V_387 ;
struct V_333 * V_10 ;
int V_388 = sizeof( V_171 ) ;
int V_389 = 0 ;
int V_390 = 0 ;
int V_294 ;
int V_391 = 0 ;
V_387 = V_30 ;
for ( V_294 = 0 ; V_294 < V_386 ; V_294 ++ ) {
V_334 = V_387 ;
V_10 = F_122 ( V_334 -> V_267 . V_380 ) ;
V_389 = V_10 -> V_381 ( V_334 , & V_354 ) ;
V_390 += V_388 ;
V_390 += V_389 ;
V_387 += V_10 -> V_392 ;
if ( V_6 -> V_393 && ! V_391 ) {
V_390 += V_388 ;
V_390 += V_389 ;
V_391 = 1 ;
F_32 ( L_8
L_9 ,
V_135 , V_390 ) ;
}
}
V_32 = F_141 ( V_6 , V_384 , V_390 ) ;
if ( ! V_32 )
return NULL ;
V_387 = V_30 ;
for ( V_294 = 0 ; V_294 < V_386 ; V_294 ++ ) {
V_334 = V_387 ;
V_10 = F_122 ( V_334 -> V_267 . V_380 ) ;
V_389 = V_10 -> V_381 ( V_334 , & V_354 ) ;
V_171 . V_73 . type = V_107 ;
V_171 . V_73 . V_17 = F_6 ( V_388 + V_389 ) ;
V_171 . V_394 = V_294 ;
F_7 ( V_32 , V_388 , & V_171 ) ;
F_7 ( V_32 , V_389 , & V_354 ) ;
V_387 += V_10 -> V_392 ;
}
if ( V_107 == V_343 && V_391 ) {
V_334 = V_6 -> V_393 ;
V_10 = F_122 ( V_334 -> V_267 . V_380 ) ;
V_389 = V_10 -> V_381 ( V_334 , & V_354 ) ;
V_171 . V_73 . type = V_344 ;
V_171 . V_73 . V_17 = F_6 ( V_388 + V_389 ) ;
V_171 . V_394 = V_294 ;
F_7 ( V_32 , V_388 , & V_171 ) ;
F_7 ( V_32 , V_389 , & V_354 ) ;
}
return V_32 ;
}
struct V_3 * F_143 ( struct V_5 * V_6 ,
union V_207 * V_334 )
{
V_372 V_171 ;
struct V_3 * V_32 ;
int V_15 = sizeof( V_171 ) ;
union V_353 V_378 ;
int V_379 ;
struct V_333 * V_10 = F_122 ( V_334 -> V_267 . V_380 ) ;
V_379 = V_10 -> V_381 ( V_334 , & V_378 ) ;
if ( ! V_379 )
return NULL ;
V_15 += V_379 ;
V_32 = F_141 ( V_6 , V_334 , V_15 ) ;
if ( ! V_32 )
return NULL ;
V_171 . V_73 . type = V_318 ;
V_171 . V_73 . V_17 = F_6 ( V_15 ) ;
V_171 . V_394 = 0 ;
F_7 ( V_32 , sizeof( V_171 ) , & V_171 ) ;
F_7 ( V_32 , V_379 , & V_378 ) ;
return V_32 ;
}
static struct V_3 * F_144 ( const struct V_5 * V_6 ,
T_13 V_382 , int V_24 )
{
T_28 V_377 ;
struct V_3 * V_32 ;
int V_17 = sizeof( V_377 ) + V_24 ;
V_32 = F_19 ( V_6 , V_63 , 0 , V_17 ,
V_94 ) ;
if ( ! V_32 )
return NULL ;
V_377 . V_382 = F_14 ( V_382 ) ;
V_32 -> V_18 . V_383 =
F_7 ( V_32 , sizeof( V_377 ) , & V_377 ) ;
return V_32 ;
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
F_18 ( V_396 -> V_73 . V_17 ) ;
}
V_397 . V_73 . type = V_401 ;
V_397 . V_73 . V_17 = F_6 ( sizeof( V_397 ) +
V_400 +
V_399 ) ;
V_397 . V_394 = V_394 ;
F_7 ( V_4 , sizeof( V_397 ) , & V_397 ) ;
if ( V_402 == V_395 )
return;
V_398 . V_16 = V_395 ;
V_398 . V_17 = F_6 ( V_400 + V_399 ) ;
F_7 ( V_4 , V_400 , & V_398 ) ;
if ( V_396 )
F_7 ( V_4 , V_399 , V_396 ) ;
}
static T_1 F_146 ( struct V_5 * V_6 ,
struct V_3 * V_377 ,
V_372 * V_396 )
{
struct V_133 * V_84 ;
struct V_333 * V_10 ;
union V_207 V_334 ;
union V_353 * V_354 ;
V_354 = ( void * ) V_396 + sizeof( V_372 ) ;
if ( V_396 -> V_73 . type != V_343 &&
V_396 -> V_73 . type != V_344 &&
V_396 -> V_73 . type != V_318 )
return V_306 ;
switch ( V_354 -> V_241 . type ) {
case V_313 :
if ( ! V_6 -> V_84 . V_364 )
return V_291 ;
break;
case V_312 :
if ( ! V_6 -> V_84 . V_363 )
return V_291 ;
break;
default:
return V_291 ;
}
V_10 = F_122 ( F_123 ( V_354 -> V_241 . type ) ) ;
if ( F_58 ( ! V_10 ) )
return V_291 ;
V_10 -> V_338 ( & V_334 , V_354 , F_6 ( V_6 -> V_84 . V_276 ) , 0 ) ;
if ( ! V_10 -> V_405 ( & V_334 ) && ! V_10 -> V_373 ( & V_334 , NULL , V_377 -> V_2 ) )
return V_291 ;
switch ( V_396 -> V_73 . type ) {
case V_343 :
if ( V_10 -> V_405 ( & V_334 ) )
memcpy ( & V_334 , & V_377 -> V_210 , sizeof( V_334 ) ) ;
V_84 = F_120 ( V_6 , & V_334 , V_94 , V_359 ) ;
if ( ! V_84 )
return V_406 ;
F_147 ( V_84 ) ;
V_6 -> V_407 = V_84 ;
break;
case V_344 :
if ( V_6 -> V_84 . V_408 == 1 )
return V_409 ;
if ( F_121 ( & V_377 -> V_210 , & V_334 ) )
return V_410 ;
if ( V_10 -> V_405 ( & V_334 ) ) {
F_136 ( V_6 , V_377 -> V_92 ) ;
F_148 ( V_6 ,
V_377 -> V_92 ) ;
return V_402 ;
}
V_84 = F_135 ( V_6 , & V_334 ) ;
if ( ! V_84 )
return V_291 ;
F_127 ( V_6 , V_84 ) ;
break;
case V_318 :
if ( V_10 -> V_405 ( & V_334 ) )
memcpy ( & V_334 . V_267 , F_65 ( V_377 ) , sizeof( V_334 ) ) ;
V_84 = F_135 ( V_6 , & V_334 ) ;
if ( ! V_84 )
return V_291 ;
F_136 ( V_6 , V_84 ) ;
break;
}
return V_402 ;
}
bool F_149 ( const struct V_5 * V_6 ,
struct V_3 * V_4 , bool V_411 ,
struct V_167 * * V_253 )
{
T_29 * V_412 = ( T_29 * ) V_4 -> V_151 ;
union V_29 V_171 ;
bool V_413 = false ;
F_118 (param, addip, addip_hdr.params) {
T_2 V_17 = F_18 ( V_171 . V_241 -> V_17 ) ;
* V_253 = V_171 . V_241 ;
switch ( V_171 . V_241 -> type ) {
case V_404 :
break;
case V_312 :
if ( V_17 != sizeof( V_414 ) )
return false ;
if ( V_171 . V_74 != V_412 -> V_383 . V_415 )
return false ;
V_413 = true ;
break;
case V_313 :
if ( V_17 != sizeof( V_416 ) )
return false ;
if ( V_171 . V_74 != V_412 -> V_383 . V_415 )
return false ;
V_413 = true ;
break;
case V_343 :
case V_344 :
case V_318 :
if ( V_411 && ! V_413 )
return false ;
V_17 = F_18 ( V_171 . V_412 -> V_73 . V_17 ) ;
if ( V_17 < sizeof( V_372 ) +
sizeof( T_11 ) )
return false ;
break;
case V_403 :
case V_77 :
if ( V_17 != sizeof( V_372 ) )
return false ;
break;
default:
return false ;
}
}
if ( V_411 && ! V_413 )
return false ;
if ( ! V_411 && V_413 )
return false ;
if ( V_171 . V_74 != V_4 -> V_166 )
return false ;
return true ;
}
struct V_3 * F_150 ( struct V_5 * V_6 ,
struct V_3 * V_377 )
{
T_29 * V_412 = ( T_29 * ) V_377 -> V_151 ;
bool V_417 = true ;
union V_29 V_171 ;
T_28 * V_418 ;
union V_353 * V_354 ;
struct V_3 * V_419 ;
T_1 V_395 ;
int V_17 = 0 ;
int V_111 ;
T_13 V_382 ;
V_111 = F_18 ( V_377 -> V_151 -> V_17 ) - sizeof( T_19 ) ;
V_418 = ( T_28 * ) V_377 -> V_2 -> V_163 ;
V_382 = F_100 ( V_418 -> V_382 ) ;
V_17 = sizeof( T_28 ) ;
V_354 = (union V_353 * ) ( V_377 -> V_2 -> V_163 + V_17 ) ;
V_111 -= V_17 ;
V_17 = F_18 ( V_354 -> V_241 . V_17 ) ;
V_111 -= V_17 ;
V_419 = F_144 ( V_6 , V_382 , V_111 * 4 ) ;
if ( ! V_419 )
goto V_420;
F_118 (param, addip, addip_hdr.params) {
if ( V_171 . V_241 -> type == V_312 ||
V_171 . V_241 -> type == V_313 )
continue;
V_395 = F_146 ( V_6 , V_377 ,
V_171 . V_412 ) ;
if ( V_395 != V_402 )
V_417 = false ;
if ( ! V_417 )
F_145 ( V_419 , V_171 . V_412 -> V_394 ,
V_395 , V_171 . V_412 ) ;
if ( V_395 == V_406 )
goto V_420;
}
V_420:
V_6 -> V_84 . V_281 ++ ;
if ( V_419 ) {
F_79 ( V_419 ) ;
F_151 ( & V_419 -> V_204 ,
& V_6 -> V_421 ) ;
}
return V_419 ;
}
static void F_152 ( struct V_5 * V_6 ,
V_372 * V_396 )
{
struct V_333 * V_10 ;
union V_207 V_334 ;
struct V_21 * V_22 = & V_6 -> V_8 . V_82 ;
union V_353 * V_354 ;
struct V_133 * V_92 ;
struct V_422 * V_423 ;
V_354 = ( void * ) V_396 + sizeof( V_372 ) ;
V_10 = F_122 ( F_123 ( V_354 -> V_241 . type ) ) ;
V_10 -> V_338 ( & V_334 , V_354 , F_6 ( V_22 -> V_276 ) , 0 ) ;
switch ( V_396 -> V_73 . type ) {
case V_343 :
F_153 () ;
F_36 (saddr, &bp->address_list, list) {
if ( F_121 ( & V_423 -> V_424 , & V_334 ) )
V_423 -> V_346 = V_278 ;
}
F_154 () ;
F_36 (transport, &asoc->peer.transport_addr_list,
transports) {
F_155 ( V_92 ) ;
}
break;
case V_344 :
F_153 () ;
F_156 ( V_22 , & V_334 ) ;
if ( V_6 -> V_393 != NULL &&
F_121 ( V_6 -> V_393 , & V_334 ) ) {
F_21 ( V_6 -> V_393 ) ;
V_6 -> V_393 = NULL ;
}
F_154 () ;
F_36 (transport, &asoc->peer.transport_addr_list,
transports) {
F_155 ( V_92 ) ;
}
break;
default:
break;
}
}
static T_1 F_157 ( struct V_3 * V_419 ,
V_372 * V_396 ,
int V_425 )
{
V_372 * V_426 ;
T_3 * V_398 ;
int V_17 ;
int V_427 ;
T_1 V_395 ;
if ( V_425 )
V_395 = V_402 ;
else
V_395 = V_428 ;
V_427 = F_18 ( V_419 -> V_151 -> V_17 ) -
sizeof( T_19 ) ;
V_17 = sizeof( T_28 ) ;
V_426 = ( V_372 * ) ( V_419 -> V_2 -> V_163 +
V_17 ) ;
V_427 -= V_17 ;
while ( V_427 > 0 ) {
if ( V_426 -> V_394 == V_396 -> V_394 ) {
switch ( V_426 -> V_73 . type ) {
case V_403 :
return V_402 ;
case V_404 :
V_17 = sizeof( V_372 ) ;
V_398 = ( void * ) V_426 + V_17 ;
V_427 -= V_17 ;
if ( V_427 > 0 )
return V_398 -> V_16 ;
else
return V_290 ;
break;
default:
return V_290 ;
}
}
V_17 = F_18 ( V_426 -> V_73 . V_17 ) ;
V_426 = ( void * ) V_426 + V_17 ;
V_427 -= V_17 ;
}
return V_395 ;
}
int F_158 ( struct V_5 * V_6 ,
struct V_3 * V_419 )
{
struct V_3 * V_377 = V_6 -> V_429 ;
union V_353 * V_354 ;
V_372 * V_396 ;
int V_17 = 0 ;
int V_430 = V_377 -> V_2 -> V_15 ;
int V_417 = 0 ;
int V_425 = 1 ;
int V_32 = 0 ;
T_1 V_395 = V_402 ;
V_17 = sizeof( T_29 ) ;
V_354 = (union V_353 * ) ( V_377 -> V_2 -> V_163 + V_17 ) ;
V_430 -= V_17 ;
V_17 = F_18 ( V_354 -> V_241 . V_17 ) ;
V_396 = ( void * ) V_354 + V_17 ;
V_430 -= V_17 ;
if ( V_419 -> V_2 -> V_15 == sizeof( T_28 ) )
V_417 = 1 ;
while ( V_430 > 0 ) {
if ( V_417 )
V_395 = V_402 ;
else {
V_395 = F_157 ( V_419 ,
V_396 ,
V_425 ) ;
if ( V_425 && ( V_402 != V_395 ) )
V_425 = 0 ;
}
switch ( V_395 ) {
case V_402 :
F_152 ( V_6 , V_396 ) ;
break;
case V_406 :
V_32 = 1 ;
break;
case V_306 :
V_6 -> V_84 . V_342 |=
V_396 -> V_73 . type ;
break;
case V_428 :
case V_409 :
case V_410 :
default:
break;
}
V_17 = F_18 ( V_396 -> V_73 . V_17 ) ;
V_396 = ( void * ) V_396 + V_17 ;
V_430 -= V_17 ;
}
if ( V_425 && V_6 -> V_431 ) {
V_6 -> V_431 = 0 ;
F_159 ( V_6 -> V_84 . V_432 ) ;
}
F_73 ( & V_377 -> V_204 ) ;
F_45 ( V_377 ) ;
V_6 -> V_429 = NULL ;
return V_32 ;
}
struct V_3 * F_160 ( const struct V_5 * V_6 ,
T_13 V_433 , T_2 V_434 ,
struct V_435 * V_436 )
{
struct V_3 * V_32 = NULL ;
struct V_437 V_438 ;
struct V_435 V_439 ;
T_2 V_150 ;
int V_294 ;
V_150 = ( V_434 + 1 ) * sizeof( T_13 ) ;
V_32 = F_19 ( V_6 , V_298 , 0 , V_150 , V_94 ) ;
if ( ! V_32 )
return NULL ;
V_438 . V_433 = F_14 ( V_433 ) ;
V_32 -> V_18 . V_440 =
F_7 ( V_32 , sizeof( V_438 ) , & V_438 ) ;
for ( V_294 = 0 ; V_294 < V_434 ; V_294 ++ ) {
V_439 . V_113 = V_436 [ V_294 ] . V_113 ;
V_439 . V_108 = V_436 [ V_294 ] . V_108 ;
F_7 ( V_32 , sizeof( V_439 ) , & V_439 ) ;
}
return V_32 ;
}
static struct V_3 * F_161 (
const struct V_5 * V_6 ,
int V_17 )
{
struct V_441 * V_442 ;
struct V_3 * V_32 ;
V_32 = F_19 ( V_6 , V_65 , 0 , V_17 ,
V_94 ) ;
if ( ! V_32 )
return NULL ;
V_442 = (struct V_441 * ) V_32 -> V_151 ;
V_32 -> V_73 . V_74 = V_442 -> V_415 ;
return V_32 ;
}
struct V_3 * F_162 (
const struct V_5 * V_6 ,
T_4 V_443 , T_4 * V_444 ,
bool V_227 , bool V_445 )
{
struct V_446 V_447 ;
T_4 V_448 = V_443 * 2 ;
struct V_449 V_450 ;
struct V_3 * V_32 ;
T_4 V_451 , V_452 ;
V_451 = ( sizeof( V_447 ) + V_448 ) * V_227 ;
V_452 = ( sizeof( V_450 ) + V_448 ) * V_445 ;
V_32 = F_161 ( V_6 , V_451 + V_452 ) ;
if ( ! V_32 )
return NULL ;
if ( V_451 ) {
V_447 . V_73 . type = V_453 ;
V_447 . V_73 . V_17 = F_6 ( V_451 ) ;
V_447 . V_454 = F_14 ( V_6 -> V_282 ) ;
V_447 . V_455 = F_14 ( V_6 -> V_348 - 1 ) ;
V_447 . V_456 = F_14 ( V_6 -> V_279 - 1 ) ;
F_7 ( V_32 , sizeof( V_447 ) , & V_447 ) ;
if ( V_448 )
F_7 ( V_32 , V_448 , V_444 ) ;
}
if ( V_452 ) {
V_450 . V_73 . type = V_457 ;
V_450 . V_73 . V_17 = F_6 ( V_452 ) ;
V_450 . V_454 = F_14 ( V_6 -> V_282 + V_227 ) ;
F_7 ( V_32 , sizeof( V_450 ) , & V_450 ) ;
if ( V_448 )
F_7 ( V_32 , V_448 , V_444 ) ;
}
return V_32 ;
}
struct V_3 * F_163 (
const struct V_5 * V_6 )
{
struct V_458 V_459 ;
T_4 V_17 = sizeof( V_459 ) ;
struct V_3 * V_32 ;
V_32 = F_161 ( V_6 , V_17 ) ;
if ( ! V_32 )
return NULL ;
V_459 . V_73 . type = V_460 ;
V_459 . V_73 . V_17 = F_6 ( V_17 ) ;
V_459 . V_454 = F_14 ( V_6 -> V_282 ) ;
F_7 ( V_32 , sizeof( V_459 ) , & V_459 ) ;
return V_32 ;
}
struct V_3 * F_164 (
const struct V_5 * V_6 ,
T_4 V_227 , T_4 V_445 )
{
struct V_461 V_462 ;
T_4 V_183 = sizeof( V_462 ) ;
struct V_3 * V_32 ;
V_32 = F_161 ( V_6 , ( ! ! V_227 + ! ! V_445 ) * V_183 ) ;
if ( ! V_32 )
return NULL ;
if ( V_227 ) {
V_462 . V_73 . type = V_463 ;
V_462 . V_73 . V_17 = F_6 ( V_183 ) ;
V_462 . V_464 = F_6 ( V_227 ) ;
V_462 . V_454 = F_14 ( V_6 -> V_282 ) ;
V_462 . V_465 = 0 ;
F_7 ( V_32 , V_183 , & V_462 ) ;
}
if ( V_445 ) {
V_462 . V_73 . type = V_466 ;
V_462 . V_73 . V_17 = F_6 ( V_183 ) ;
V_462 . V_464 = F_6 ( V_445 ) ;
V_462 . V_454 = F_14 ( V_6 -> V_282 + ! ! V_227 ) ;
V_462 . V_465 = 0 ;
F_7 ( V_32 , V_183 , & V_462 ) ;
}
return V_32 ;
}
struct V_3 * F_165 (
const struct V_5 * V_6 ,
T_13 V_329 , T_13 V_467 )
{
struct V_468 V_469 ;
T_4 V_17 = sizeof( V_469 ) ;
struct V_3 * V_32 ;
V_32 = F_161 ( V_6 , V_17 ) ;
if ( ! V_32 )
return NULL ;
V_469 . V_73 . type = V_470 ;
V_469 . V_73 . V_17 = F_6 ( V_17 ) ;
V_469 . V_455 = F_14 ( V_467 ) ;
V_469 . V_329 = F_14 ( V_329 ) ;
F_7 ( V_32 , sizeof( V_469 ) , & V_469 ) ;
return V_32 ;
}
struct V_3 * F_166 (
struct V_5 * V_6 ,
T_13 V_329 , T_13 V_467 ,
T_13 V_471 , T_13 V_472 )
{
struct V_473 V_474 ;
T_4 V_17 = sizeof( V_474 ) ;
struct V_3 * V_32 ;
V_32 = F_161 ( V_6 , V_17 ) ;
if ( ! V_32 )
return NULL ;
V_474 . V_73 . type = V_470 ;
V_474 . V_73 . V_17 = F_6 ( V_17 ) ;
V_474 . V_455 = F_14 ( V_467 ) ;
V_474 . V_329 = F_14 ( V_329 ) ;
V_474 . V_475 = F_14 ( V_471 ) ;
V_474 . V_476 = F_14 ( V_472 ) ;
F_7 ( V_32 , sizeof( V_474 ) , & V_474 ) ;
return V_32 ;
}
bool F_167 ( const struct V_5 * V_6 ,
struct V_3 * V_4 ,
struct V_167 * * V_253 )
{
struct V_441 * V_418 ;
union V_29 V_171 ;
T_4 V_477 = 0 , V_478 = 0 ;
V_418 = (struct V_441 * ) V_4 -> V_151 ;
F_118 (param, hdr, params) {
T_4 V_17 = F_18 ( V_171 . V_241 -> V_17 ) ;
* V_253 = V_171 . V_241 ;
if ( V_478 ++ > 2 )
return false ;
switch ( V_171 . V_241 -> type ) {
case V_453 :
if ( V_17 < sizeof( struct V_446 ) ||
( V_477 && V_477 != V_470 &&
V_477 != V_457 ) )
return false ;
break;
case V_457 :
if ( V_17 < sizeof( struct V_449 ) ||
( V_477 && V_477 != V_453 ) )
return false ;
break;
case V_470 :
if ( ( V_17 != sizeof( struct V_468 ) &&
V_17 != sizeof( struct V_473 ) ) ||
( V_477 && V_477 != V_470 &&
V_477 != V_453 ) )
return false ;
break;
case V_460 :
if ( V_17 !=
sizeof( struct V_458 ) || V_477 )
return false ;
break;
case V_466 :
if ( V_17 != sizeof( struct V_461 ) ||
( V_477 && V_477 != V_463 ) )
return false ;
break;
case V_463 :
if ( V_17 != sizeof( struct V_461 ) ||
( V_477 && V_477 != V_466 ) )
return false ;
break;
default:
return false ;
}
V_477 = V_171 . V_241 -> type ;
}
return true ;
}

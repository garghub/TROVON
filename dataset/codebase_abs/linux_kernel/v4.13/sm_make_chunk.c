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
struct V_28 V_29 ;
union V_30 V_31 ;
T_2 V_32 ;
struct V_3 * V_33 = NULL ;
int V_34 , V_35 = 0 ;
struct V_36 * V_37 ;
T_6 V_38 ;
T_1 V_39 [ 2 ] ;
T_7 V_40 ;
T_8 V_41 ;
int V_42 = 0 ;
T_9 V_43 [ 4 ] ;
struct V_44 * V_45 = NULL ,
* V_46 = NULL ;
V_33 = NULL ;
V_31 = F_13 ( V_22 , & V_35 , V_23 ) ;
V_29 . V_47 = F_14 ( V_6 -> V_48 . V_49 ) ;
V_29 . V_50 = F_14 ( V_6 -> V_51 ) ;
V_29 . V_52 = F_6 ( V_6 -> V_48 . V_53 ) ;
V_29 . V_54 = F_6 ( V_6 -> V_48 . V_55 ) ;
V_29 . V_56 = F_14 ( V_6 -> V_48 . V_56 ) ;
V_37 = F_15 ( V_6 -> V_8 . V_7 ) ;
V_34 = V_37 -> V_57 -> V_58 ( V_37 , V_39 ) ;
V_32 = sizeof( V_29 ) + V_35 ;
V_32 += F_16 ( F_17 ( V_34 ) ) ;
V_32 += sizeof( V_59 ) ;
if ( V_6 -> V_60 )
V_32 += sizeof( V_61 ) ;
if ( V_25 -> V_62 . V_63 ) {
V_43 [ V_42 ] = V_64 ;
V_43 [ V_42 + 1 ] = V_65 ;
V_42 += 2 ;
}
if ( V_6 -> V_66 ) {
V_43 [ V_42 ] = V_67 ;
V_42 += 1 ;
}
if ( V_37 -> V_68 )
V_32 += sizeof( V_40 ) ;
V_32 += V_24 ;
if ( V_27 -> V_69 ) {
V_32 += sizeof( V_6 -> V_48 . V_70 ) ;
V_46 = (struct V_44 * ) V_6 -> V_48 . V_46 ;
if ( V_46 -> V_17 )
V_32 += F_16 ( F_18 ( V_46 -> V_17 ) ) ;
else
V_46 = NULL ;
V_45 = (struct V_44 * ) V_6 -> V_48 . V_45 ;
if ( V_45 -> V_17 )
V_32 += F_16 ( F_18 ( V_45 -> V_17 ) ) ;
else
V_45 = NULL ;
V_43 [ V_42 ] = V_71 ;
V_42 += 1 ;
}
if ( V_42 )
V_32 += F_16 ( sizeof( T_8 ) +
V_42 ) ;
V_33 = F_19 ( V_6 , V_72 , 0 , V_32 , V_23 ) ;
if ( ! V_33 )
goto V_73;
V_33 -> V_18 . V_74 =
F_7 ( V_33 , sizeof( V_29 ) , & V_29 ) ;
V_33 -> V_75 . V_76 =
F_7 ( V_33 , V_35 , V_31 . V_76 ) ;
V_38 . V_75 . type = V_77 ;
V_38 . V_75 . V_17 = F_6 ( F_17 ( V_34 ) ) ;
F_7 ( V_33 , sizeof( V_38 ) , & V_38 ) ;
F_7 ( V_33 , V_34 * sizeof( T_4 ) , & V_39 ) ;
F_7 ( V_33 , sizeof( V_59 ) , & V_59 ) ;
if ( V_42 ) {
V_41 . V_75 . type = V_78 ;
V_41 . V_75 . V_17 =
F_6 ( sizeof( T_8 ) + V_42 ) ;
F_7 ( V_33 , sizeof( T_8 ) ,
& V_41 ) ;
F_20 ( V_33 , V_42 , V_43 ) ;
}
if ( V_6 -> V_60 )
F_7 ( V_33 , sizeof( V_61 ) , & V_61 ) ;
if ( V_37 -> V_68 ) {
V_40 . V_75 . type = V_79 ;
V_40 . V_75 . V_17 = F_6 ( sizeof( V_40 ) ) ;
V_40 . V_68 = F_14 ( V_37 -> V_68 ) ;
F_7 ( V_33 , sizeof( V_40 ) , & V_40 ) ;
}
if ( V_27 -> V_69 ) {
F_7 ( V_33 , sizeof( V_6 -> V_48 . V_70 ) ,
V_6 -> V_48 . V_70 ) ;
if ( V_46 )
F_7 ( V_33 , F_18 ( V_46 -> V_17 ) ,
V_46 ) ;
if ( V_45 )
F_7 ( V_33 , F_18 ( V_45 -> V_17 ) ,
V_45 ) ;
}
V_73:
F_21 ( V_31 . V_76 ) ;
return V_33 ;
}
struct V_3 * F_22 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
T_5 V_23 , int V_80 )
{
struct V_28 V_81 ;
struct V_3 * V_33 ;
union V_30 V_31 ;
struct V_36 * V_37 ;
int V_35 ;
T_10 * V_82 ;
int V_83 ;
T_2 V_32 ;
T_7 V_40 ;
T_8 V_41 ;
int V_42 = 0 ;
T_9 V_43 [ 4 ] ;
struct V_44 * V_45 = NULL ,
* V_46 = NULL ,
* V_70 = NULL ;
V_33 = NULL ;
V_31 = F_13 ( & V_6 -> V_8 . V_84 , & V_35 , V_23 ) ;
V_81 . V_47 = F_14 ( V_6 -> V_48 . V_49 ) ;
V_81 . V_50 = F_14 ( V_6 -> V_51 ) ;
V_81 . V_52 = F_6 ( V_6 -> V_48 . V_53 ) ;
V_81 . V_54 = F_6 ( V_6 -> V_48 . V_55 ) ;
V_81 . V_56 = F_14 ( V_6 -> V_48 . V_56 ) ;
V_82 = F_23 ( V_6 -> V_27 , V_6 , V_4 , & V_83 ,
V_31 . V_76 , V_35 ) ;
if ( ! V_82 )
goto V_85;
V_37 = F_15 ( V_6 -> V_8 . V_7 ) ;
V_32 = sizeof( V_81 ) + V_35 + V_83 + V_80 ;
if ( V_6 -> V_86 . V_87 )
V_32 += sizeof( V_59 ) ;
if ( V_6 -> V_86 . V_88 )
V_32 += sizeof( V_61 ) ;
if ( V_6 -> V_86 . V_89 ) {
V_43 [ V_42 ] = V_64 ;
V_43 [ V_42 + 1 ] = V_65 ;
V_42 += 2 ;
}
if ( V_6 -> V_86 . V_90 ) {
V_43 [ V_42 ] = V_67 ;
V_42 += 1 ;
}
if ( V_37 -> V_68 )
V_32 += sizeof( V_40 ) ;
if ( V_6 -> V_86 . V_91 ) {
V_70 = (struct V_44 * ) V_6 -> V_48 . V_70 ;
V_32 += F_18 ( V_70 -> V_17 ) ;
V_46 = (struct V_44 * ) V_6 -> V_48 . V_46 ;
if ( V_46 -> V_17 )
V_32 += F_16 ( F_18 ( V_46 -> V_17 ) ) ;
else
V_46 = NULL ;
V_45 = (struct V_44 * ) V_6 -> V_48 . V_45 ;
if ( V_45 -> V_17 )
V_32 += F_16 ( F_18 ( V_45 -> V_17 ) ) ;
else
V_45 = NULL ;
V_43 [ V_42 ] = V_71 ;
V_42 += 1 ;
}
if ( V_42 )
V_32 += F_16 ( sizeof( T_8 ) +
V_42 ) ;
V_33 = F_19 ( V_6 , V_92 , 0 , V_32 , V_23 ) ;
if ( ! V_33 )
goto V_93;
V_33 -> V_94 = V_4 -> V_94 ;
V_33 -> V_18 . V_74 =
F_7 ( V_33 , sizeof( V_81 ) , & V_81 ) ;
V_33 -> V_75 . V_76 = F_7 ( V_33 , V_35 , V_31 . V_76 ) ;
F_7 ( V_33 , V_83 , V_82 ) ;
if ( V_6 -> V_86 . V_87 )
F_7 ( V_33 , sizeof( V_59 ) , & V_59 ) ;
if ( V_42 ) {
V_41 . V_75 . type = V_78 ;
V_41 . V_75 . V_17 =
F_6 ( sizeof( T_8 ) + V_42 ) ;
F_7 ( V_33 , sizeof( T_8 ) ,
& V_41 ) ;
F_20 ( V_33 , V_42 , V_43 ) ;
}
if ( V_6 -> V_86 . V_88 )
F_7 ( V_33 , sizeof( V_61 ) , & V_61 ) ;
if ( V_37 -> V_68 ) {
V_40 . V_75 . type = V_79 ;
V_40 . V_75 . V_17 = F_6 ( sizeof( V_40 ) ) ;
V_40 . V_68 = F_14 ( V_37 -> V_68 ) ;
F_7 ( V_33 , sizeof( V_40 ) , & V_40 ) ;
}
if ( V_6 -> V_86 . V_91 ) {
F_7 ( V_33 , F_18 ( V_70 -> V_17 ) ,
V_70 ) ;
if ( V_46 )
F_7 ( V_33 , F_18 ( V_46 -> V_17 ) ,
V_46 ) ;
if ( V_45 )
F_7 ( V_33 , F_18 ( V_45 -> V_17 ) ,
V_45 ) ;
}
V_33 -> V_6 = (struct V_5 * ) V_6 ;
V_93:
F_21 ( V_82 ) ;
V_85:
F_21 ( V_31 . V_76 ) ;
return V_33 ;
}
struct V_3 * F_24 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_33 ;
void * V_82 ;
int V_83 ;
V_82 = V_6 -> V_86 . V_82 ;
V_83 = V_6 -> V_86 . V_83 ;
V_33 = F_19 ( V_6 , V_95 , 0 ,
V_83 , V_96 ) ;
if ( ! V_33 )
goto V_73;
V_33 -> V_18 . V_97 =
F_7 ( V_33 , V_83 , V_82 ) ;
if ( V_4 )
V_33 -> V_94 = V_4 -> V_94 ;
V_73:
return V_33 ;
}
struct V_3 * F_25 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_33 ;
V_33 = F_19 ( V_6 , V_98 , 0 , 0 , V_96 ) ;
if ( V_33 && V_4 )
V_33 -> V_94 = V_4 -> V_94 ;
return V_33 ;
}
struct V_3 * F_26 ( const struct V_5 * V_6 ,
const T_11 V_99 ,
const struct V_3 * V_4 )
{
struct V_3 * V_33 ;
T_12 V_100 ;
V_100 . V_99 = F_14 ( V_99 ) ;
V_33 = F_19 ( V_6 , V_101 , 0 ,
sizeof( T_12 ) , V_96 ) ;
if ( ! V_33 )
goto V_73;
V_33 -> V_18 . V_102 =
F_7 ( V_33 , sizeof( V_100 ) , & V_100 ) ;
if ( V_4 )
V_33 -> V_94 = V_4 -> V_94 ;
V_73:
return V_33 ;
}
struct V_3 * F_27 ( const struct V_5 * V_6 ,
const T_11 V_99 )
{
struct V_3 * V_33 ;
T_13 V_103 ;
V_103 . V_99 = F_14 ( V_99 ) ;
V_33 = F_19 ( V_6 , V_104 , 0 ,
sizeof( T_13 ) , V_96 ) ;
if ( ! V_33 )
goto V_73;
V_33 -> V_18 . V_105 =
F_7 ( V_33 , sizeof( V_103 ) , & V_103 ) ;
V_73:
return V_33 ;
}
struct V_3 * F_28 ( struct V_5 * V_6 ,
const struct V_106 * V_107 ,
int V_108 , T_9 V_109 , T_4 V_110 ,
T_5 V_23 )
{
struct V_3 * V_33 ;
struct V_111 V_112 ;
int V_113 ;
V_112 . V_114 = 0 ;
V_112 . V_115 = F_6 ( V_107 -> V_116 ) ;
V_112 . V_117 = V_107 -> V_118 ;
if ( V_107 -> V_119 & V_120 ) {
V_109 |= V_121 ;
V_112 . V_110 = 0 ;
} else
V_112 . V_110 = F_6 ( V_110 ) ;
V_113 = sizeof( V_112 ) + V_108 ;
V_33 = F_29 ( V_6 , V_109 , V_113 , V_23 ) ;
if ( ! V_33 )
goto V_73;
V_33 -> V_18 . V_122 = F_7 ( V_33 , sizeof( V_112 ) , & V_112 ) ;
memcpy ( & V_33 -> V_107 , V_107 , sizeof( struct V_106 ) ) ;
V_73:
return V_33 ;
}
struct V_3 * F_30 ( const struct V_5 * V_6 )
{
struct V_3 * V_33 ;
struct V_123 V_124 ;
int V_15 ;
T_11 V_125 ;
T_4 V_126 , V_127 ;
struct V_5 * V_128 = (struct V_5 * ) V_6 ;
struct V_129 * V_130 = (struct V_129 * ) & V_6 -> V_86 . V_131 ;
struct V_132 V_133 [ V_134 ] ;
struct V_135 * V_136 ;
memset ( V_133 , 0 , sizeof( V_133 ) ) ;
V_125 = F_31 ( V_130 ) ;
F_32 ( L_1 , V_137 , V_125 ) ;
V_126 = F_33 ( V_130 , V_133 ) ;
V_127 = F_34 ( V_130 ) ;
V_124 . V_138 = F_14 ( V_125 ) ;
V_124 . V_50 = F_14 ( V_6 -> V_50 ) ;
V_124 . V_139 = F_6 ( V_126 ) ;
V_124 . V_127 = F_6 ( V_127 ) ;
V_15 = sizeof( V_124 )
+ sizeof( struct V_132 ) * V_126
+ sizeof( T_11 ) * V_127 ;
V_33 = F_19 ( V_6 , V_140 , 0 , V_15 , V_96 ) ;
if ( ! V_33 )
goto V_73;
V_33 -> V_94 = V_6 -> V_86 . V_141 ;
V_33 -> V_18 . V_142 =
F_7 ( V_33 , sizeof( V_124 ) , & V_124 ) ;
if ( V_126 )
F_7 ( V_33 , sizeof( T_11 ) * V_126 ,
V_133 ) ;
if ( V_127 ) {
V_128 -> V_143 . V_144 += V_127 ;
F_7 ( V_33 , sizeof( T_11 ) * V_127 ,
F_35 ( V_130 ) ) ;
}
if ( ++ V_128 -> V_86 . V_145 == 0 ) {
F_36 (trans, &asoc->peer.transport_addr_list,
transports)
V_136 -> V_145 = 0 ;
V_128 -> V_86 . V_145 = 1 ;
}
V_73:
return V_33 ;
}
struct V_3 * F_37 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_33 ;
T_14 V_146 ;
T_11 V_125 ;
V_125 = F_31 ( & V_6 -> V_86 . V_131 ) ;
V_146 . V_138 = F_14 ( V_125 ) ;
V_33 = F_19 ( V_6 , V_147 , 0 ,
sizeof( T_14 ) , V_96 ) ;
if ( ! V_33 )
goto V_73;
V_33 -> V_18 . V_148 =
F_7 ( V_33 , sizeof( V_146 ) , & V_146 ) ;
if ( V_4 )
V_33 -> V_94 = V_4 -> V_94 ;
V_73:
return V_33 ;
}
struct V_3 * F_38 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_33 ;
V_33 = F_19 ( V_6 , V_149 , 0 , 0 ,
V_96 ) ;
if ( V_33 && V_4 )
V_33 -> V_94 = V_4 -> V_94 ;
return V_33 ;
}
struct V_3 * F_39 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_33 ;
T_9 V_109 = 0 ;
V_109 |= V_6 ? 0 : V_150 ;
V_33 = F_19 ( V_6 , V_151 , V_109 ,
0 , V_96 ) ;
if ( V_33 && V_4 )
V_33 -> V_94 = V_4 -> V_94 ;
return V_33 ;
}
struct V_3 * F_40 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
const T_2 V_152 )
{
struct V_3 * V_33 ;
T_9 V_109 = 0 ;
if ( ! V_6 ) {
if ( V_4 && V_4 -> V_153 &&
V_4 -> V_153 -> type == V_72 )
V_109 = 0 ;
else
V_109 = V_150 ;
}
V_33 = F_19 ( V_6 , V_154 , V_109 , V_152 ,
V_96 ) ;
if ( V_33 && V_4 )
V_33 -> V_94 = V_4 -> V_94 ;
return V_33 ;
}
struct V_3 * F_41 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 , T_11 V_114 )
{
struct V_3 * V_33 ;
T_15 V_155 ;
V_33 = F_40 ( V_6 , V_4 , sizeof( T_3 )
+ sizeof( V_114 ) ) ;
if ( ! V_33 )
goto V_156;
V_155 = F_14 ( V_114 ) ;
F_5 ( V_33 , V_157 , sizeof( V_155 ) ) ;
F_7 ( V_33 , sizeof( V_155 ) , ( const void * ) & V_155 ) ;
if ( V_4 )
V_33 -> V_94 = V_4 -> V_94 ;
V_156:
return V_33 ;
}
struct V_3 * F_42 ( const struct V_5 * V_6 ,
struct V_158 * V_159 ,
T_2 V_13 )
{
struct V_3 * V_33 ;
void * V_155 = NULL ;
int V_14 ;
V_33 = F_40 ( V_6 , NULL , sizeof( T_3 ) + V_13 ) ;
if ( ! V_33 )
goto V_160;
if ( V_13 ) {
V_155 = F_43 ( V_13 , V_161 ) ;
if ( ! V_155 )
goto V_162;
V_14 = F_44 ( V_155 , V_159 , V_13 ) ;
if ( V_14 < 0 )
goto V_163;
}
F_5 ( V_33 , V_164 , V_13 ) ;
F_7 ( V_33 , V_13 , V_155 ) ;
if ( V_13 )
F_21 ( V_155 ) ;
return V_33 ;
V_163:
F_21 ( V_155 ) ;
V_162:
F_45 ( V_33 ) ;
V_33 = NULL ;
V_160:
return V_33 ;
}
static void * F_20 ( struct V_3 * V_4 , int V_15 ,
const void * V_165 )
{
void * V_166 ;
int V_167 = F_18 ( V_4 -> V_153 -> V_17 ) ;
V_166 = F_46 ( V_4 -> V_2 , V_15 ) ;
if ( V_165 )
memcpy ( V_166 , V_165 , V_15 ) ;
else
memset ( V_166 , 0 , V_15 ) ;
V_4 -> V_153 -> V_17 = F_6 ( V_167 + V_15 ) ;
V_4 -> V_168 = F_47 ( V_4 -> V_2 ) ;
return V_166 ;
}
struct V_3 * F_48 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
const T_9 * V_155 ,
const T_2 V_13 )
{
struct V_3 * V_33 ;
struct V_44 V_169 ;
V_33 = F_40 ( V_6 , V_4 , sizeof( T_3 ) + V_13 +
sizeof( V_169 ) ) ;
if ( ! V_33 )
goto V_170;
F_5 ( V_33 , V_171 , V_13 +
sizeof( V_169 ) ) ;
V_169 . type = F_6 ( V_4 -> V_153 -> type ) ;
V_169 . V_17 = V_4 -> V_153 -> V_17 ;
F_7 ( V_33 , V_13 , V_155 ) ;
F_20 ( V_33 , sizeof( V_169 ) , & V_169 ) ;
V_170:
return V_33 ;
}
struct V_3 * F_49 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
struct V_44 * V_172 )
{
struct V_3 * V_33 ;
static const char error [] = L_2 ;
T_2 V_173 = sizeof( error ) + sizeof( T_3 ) +
sizeof( * V_172 ) ;
V_33 = F_40 ( V_6 , V_4 , V_173 ) ;
if ( ! V_33 )
goto V_73;
F_5 ( V_33 , V_171 ,
sizeof( error ) + sizeof( * V_172 ) ) ;
F_7 ( V_33 , sizeof( error ) , error ) ;
F_20 ( V_33 , sizeof( * V_172 ) , V_172 ) ;
V_73:
return V_33 ;
}
struct V_3 * F_50 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_33 ;
static const char error [] = L_3 ;
T_2 V_173 = sizeof( error ) + sizeof( T_3 ) ;
V_33 = F_40 ( V_6 , V_4 , V_173 ) ;
if ( ! V_33 )
goto V_73;
F_5 ( V_33 , V_171 , sizeof( error ) ) ;
F_7 ( V_33 , sizeof( error ) , error ) ;
V_73:
return V_33 ;
}
struct V_3 * F_51 ( const struct V_5 * V_6 ,
const struct V_135 * V_94 )
{
struct V_3 * V_33 ;
T_16 V_174 ;
V_33 = F_19 ( V_6 , V_175 , 0 ,
sizeof( V_174 ) , V_96 ) ;
if ( ! V_33 )
goto V_73;
V_174 . V_75 . type = V_176 ;
V_174 . V_75 . V_17 = F_6 ( sizeof( T_16 ) ) ;
V_174 . V_177 = V_94 -> V_178 ;
V_174 . V_179 = V_180 ;
V_174 . V_181 = V_94 -> V_181 ;
V_33 -> V_94 = (struct V_135 * ) V_94 ;
V_33 -> V_18 . V_182 = F_7 ( V_33 , sizeof( V_174 ) ,
& V_174 ) ;
V_73:
return V_33 ;
}
struct V_3 * F_52 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
const void * V_155 , const T_2 V_13 )
{
struct V_3 * V_33 ;
V_33 = F_19 ( V_6 , V_183 , 0 , V_13 ,
V_96 ) ;
if ( ! V_33 )
goto V_73;
V_33 -> V_18 . V_182 = F_7 ( V_33 , V_13 , V_155 ) ;
if ( V_4 )
V_33 -> V_94 = V_4 -> V_94 ;
V_73:
return V_33 ;
}
static struct V_3 * F_53 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
T_2 V_184 )
{
struct V_3 * V_33 ;
V_33 = F_19 ( V_6 , V_185 , 0 ,
sizeof( T_3 ) + V_184 , V_96 ) ;
if ( ! V_33 )
goto V_73;
if ( V_4 )
V_33 -> V_94 = V_4 -> V_94 ;
V_73:
return V_33 ;
}
static inline struct V_3 * F_54 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
T_2 V_184 = V_6 ? V_6 -> V_186 : 0 ;
if ( ! V_184 )
V_184 = V_187 ;
return F_53 ( V_6 , V_4 , V_184 ) ;
}
struct V_3 * F_55 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
T_1 V_12 , const void * V_155 ,
T_2 V_13 , T_2 V_188 )
{
struct V_3 * V_33 ;
V_33 = F_53 ( V_6 , V_4 , V_13 + V_188 ) ;
if ( ! V_33 )
goto V_73;
F_5 ( V_33 , V_12 , V_13 + V_188 ) ;
F_7 ( V_33 , V_13 , V_155 ) ;
if ( V_188 )
F_20 ( V_33 , V_188 , NULL ) ;
V_73:
return V_33 ;
}
struct V_3 * F_56 ( const struct V_5 * V_6 )
{
struct V_3 * V_33 ;
struct V_189 * V_190 ;
struct V_191 V_192 ;
T_9 * V_193 ;
V_190 = F_57 ( V_6 ) ;
if ( F_58 ( ! V_190 ) )
return NULL ;
V_33 = F_19 ( V_6 , V_71 , 0 ,
V_190 -> V_194 + sizeof( V_195 ) ,
V_96 ) ;
if ( ! V_33 )
return NULL ;
V_192 . V_196 = F_6 ( V_190 -> V_196 ) ;
V_192 . V_197 = F_6 ( V_6 -> V_198 ) ;
V_33 -> V_18 . V_192 = F_7 ( V_33 , sizeof( V_195 ) ,
& V_192 ) ;
V_193 = F_59 ( V_33 -> V_2 , V_190 -> V_194 ) ;
V_33 -> V_153 -> V_17 =
F_6 ( F_18 ( V_33 -> V_153 -> V_17 ) + V_190 -> V_194 ) ;
V_33 -> V_168 = F_47 ( V_33 -> V_2 ) ;
return V_33 ;
}
struct V_3 * F_60 ( struct V_1 * V_2 ,
const struct V_5 * V_6 ,
struct V_199 * V_7 , T_5 V_23 )
{
struct V_3 * V_33 ;
V_33 = F_61 ( V_200 , V_23 ) ;
if ( ! V_33 )
goto V_73;
if ( ! V_7 )
F_32 ( L_4 , V_137 , V_2 ) ;
F_62 ( & V_33 -> V_201 ) ;
V_33 -> V_2 = V_2 ;
V_33 -> V_6 = (struct V_5 * ) V_6 ;
V_33 -> V_202 = 1 ;
V_33 -> V_203 = V_204 ;
F_62 ( & V_33 -> V_205 ) ;
F_62 ( & V_33 -> V_206 ) ;
F_63 ( V_4 ) ;
F_64 ( & V_33 -> V_207 , 1 ) ;
V_73:
return V_33 ;
}
void F_65 ( struct V_3 * V_4 , union V_208 * V_209 ,
union V_208 * V_210 )
{
memcpy ( & V_4 -> V_211 , V_209 , sizeof( union V_208 ) ) ;
memcpy ( & V_4 -> V_210 , V_210 , sizeof( union V_208 ) ) ;
}
const union V_208 * F_66 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_94 ) {
return & V_4 -> V_94 -> V_178 ;
} else {
return & V_4 -> V_211 ;
}
}
static struct V_3 * F_67 ( const struct V_5 * V_6 ,
T_9 type , T_9 V_109 , int V_13 ,
T_5 V_23 )
{
struct V_3 * V_33 ;
struct V_212 * V_153 ;
struct V_1 * V_2 ;
struct V_199 * V_7 ;
V_2 = F_68 ( F_16 ( sizeof( * V_153 ) + V_13 ) , V_23 ) ;
if ( ! V_2 )
goto V_73;
V_153 = (struct V_212 * ) F_46 ( V_2 , sizeof( * V_153 ) ) ;
V_153 -> type = type ;
V_153 -> V_109 = V_109 ;
V_153 -> V_17 = F_6 ( sizeof( * V_153 ) ) ;
V_7 = V_6 ? V_6 -> V_8 . V_7 : NULL ;
V_33 = F_60 ( V_2 , V_6 , V_7 , V_23 ) ;
if ( ! V_33 ) {
F_69 ( V_2 ) ;
goto V_73;
}
V_33 -> V_153 = V_153 ;
V_33 -> V_168 = ( ( T_9 * ) V_153 ) + sizeof( * V_153 ) ;
if ( F_70 ( type , V_6 ) )
V_33 -> V_213 = 1 ;
return V_33 ;
V_73:
return NULL ;
}
static struct V_3 * F_29 ( const struct V_5 * V_6 ,
T_9 V_109 , int V_13 , T_5 V_23 )
{
return F_67 ( V_6 , V_214 , V_109 , V_13 , V_23 ) ;
}
static struct V_3 * F_19 ( const struct V_5 * V_6 ,
T_9 type , T_9 V_109 , int V_13 ,
T_5 V_23 )
{
struct V_3 * V_4 ;
V_4 = F_67 ( V_6 , type , V_109 , V_13 , V_23 ) ;
if ( V_4 )
F_2 ( V_4 ) ;
return V_4 ;
}
static void F_71 ( struct V_3 * V_4 )
{
F_72 ( ! F_73 ( & V_4 -> V_201 ) ) ;
F_74 ( & V_4 -> V_205 ) ;
F_75 ( V_4 -> V_2 ) ;
F_75 ( V_4 -> V_215 ) ;
F_76 ( V_4 ) ;
F_77 ( V_200 , V_4 ) ;
}
void F_45 ( struct V_3 * V_4 )
{
if ( V_4 -> V_159 )
F_78 ( V_4 -> V_159 ) ;
F_79 ( V_4 ) ;
}
void F_80 ( struct V_3 * V_216 )
{
F_81 ( & V_216 -> V_207 ) ;
}
void F_79 ( struct V_3 * V_216 )
{
if ( F_82 ( & V_216 -> V_207 ) )
F_71 ( V_216 ) ;
}
void * F_7 ( struct V_3 * V_4 , int V_15 , const void * V_165 )
{
void * V_166 ;
int V_167 = F_18 ( V_4 -> V_153 -> V_17 ) ;
int V_217 = F_16 ( V_167 ) - V_167 ;
F_59 ( V_4 -> V_2 , V_217 ) ;
V_166 = F_83 ( V_4 -> V_2 , V_165 , V_15 ) ;
V_4 -> V_153 -> V_17 = F_6 ( V_167 + V_217 + V_15 ) ;
V_4 -> V_168 = F_47 ( V_4 -> V_2 ) ;
return V_166 ;
}
static void * F_10 ( struct V_3 * V_4 ,
int V_15 , const void * V_165 )
{
if ( F_9 ( V_4 -> V_2 ) >= V_15 )
return F_7 ( V_4 , V_15 , V_165 ) ;
else
return NULL ;
}
int F_84 ( struct V_3 * V_4 , int V_15 ,
struct V_218 * V_219 )
{
void * V_166 ;
V_166 = F_46 ( V_4 -> V_2 , V_15 ) ;
if ( ! F_85 ( V_166 , V_15 , V_219 ) )
return - V_220 ;
V_4 -> V_153 -> V_17 =
F_6 ( F_18 ( V_4 -> V_153 -> V_17 ) + V_15 ) ;
V_4 -> V_168 = F_47 ( V_4 -> V_2 ) ;
return 0 ;
}
void F_86 ( struct V_3 * V_4 )
{
struct V_221 * V_159 ;
struct V_3 * V_222 ;
struct V_223 * V_115 ;
T_4 V_110 ;
T_4 V_224 ;
if ( V_4 -> V_225 )
return;
V_224 = F_18 ( V_4 -> V_18 . V_122 -> V_115 ) ;
V_115 = & V_4 -> V_6 -> V_115 ;
V_159 = V_4 -> V_159 ;
F_36 (lchunk, &msg->chunks, frag_list) {
if ( V_222 -> V_153 -> V_109 & V_121 ) {
V_110 = 0 ;
} else {
if ( V_222 -> V_153 -> V_109 & V_226 )
V_110 = F_87 ( V_115 , V_227 , V_224 ) ;
else
V_110 = F_88 ( V_115 , V_227 , V_224 ) ;
}
V_222 -> V_18 . V_122 -> V_110 = F_6 ( V_110 ) ;
V_222 -> V_225 = 1 ;
}
}
void F_89 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_228 ) {
V_4 -> V_18 . V_122 -> V_114 =
F_14 ( F_90 ( V_4 -> V_6 ) ) ;
V_4 -> V_228 = 1 ;
}
}
struct V_5 * F_91 ( const struct V_26 * V_27 ,
struct V_3 * V_4 ,
T_5 V_23 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
T_17 V_229 ;
V_229 = F_92 ( F_66 ( V_4 ) ) ;
V_6 = F_93 ( V_27 , V_27 -> V_8 . V_7 , V_229 , V_23 ) ;
if ( ! V_6 )
goto V_73;
V_6 -> V_230 = 1 ;
V_2 = V_4 -> V_2 ;
F_4 ( V_2 ) -> V_10 -> V_231 ( & V_6 -> V_48 . V_232 , V_2 , 1 ) ;
V_73:
return V_6 ;
}
static T_10 * F_23 ( const struct V_26 * V_27 ,
const struct V_5 * V_6 ,
const struct V_3 * V_233 ,
int * V_83 ,
const T_9 * V_234 , int V_35 )
{
T_10 * V_33 ;
struct V_235 * V_82 ;
int V_236 , V_237 ;
V_236 = sizeof( struct V_44 ) +
( sizeof( struct V_235 ) -
sizeof( struct V_238 ) ) ;
V_237 = sizeof( struct V_238 )
+ F_18 ( V_233 -> V_153 -> V_17 ) + V_35 ;
if ( V_237 % V_239 )
V_237 += V_239
- ( V_237 % V_239 ) ;
* V_83 = V_236 + V_237 ;
V_33 = F_94 ( * V_83 , V_96 ) ;
if ( ! V_33 )
goto V_73;
V_82 = (struct V_235 * ) V_33 -> V_240 ;
V_33 -> V_241 . type = V_242 ;
V_33 -> V_241 . V_17 = F_6 ( * V_83 ) ;
V_82 -> V_48 = V_6 -> V_48 ;
V_82 -> V_48 . V_243 = V_35 ;
V_82 -> V_48 . V_88 = V_6 -> V_86 . V_88 ;
V_82 -> V_48 . V_68 = V_6 -> V_86 . V_68 ;
V_82 -> V_48 . V_244 = F_95 ( V_6 -> V_245 ,
F_96 () ) ;
memcpy ( & V_82 -> V_48 . V_246 [ 0 ] , V_233 -> V_153 ,
F_18 ( V_233 -> V_153 -> V_17 ) ) ;
memcpy ( ( T_9 * ) & V_82 -> V_48 . V_246 [ 0 ] +
F_18 ( V_233 -> V_153 -> V_17 ) , V_234 , V_35 ) ;
if ( F_15 ( V_27 -> V_8 . V_7 ) -> V_193 ) {
F_97 ( V_247 , F_15 ( V_27 -> V_8 . V_7 ) -> V_193 ) ;
int V_14 ;
V_247 -> V_248 = F_15 ( V_27 -> V_8 . V_7 ) -> V_193 ;
V_247 -> V_109 = 0 ;
V_14 = F_98 ( V_247 -> V_248 , V_27 -> V_249 ,
sizeof( V_27 -> V_249 ) ) ? :
F_99 ( V_247 , ( V_250 * ) & V_82 -> V_48 , V_237 ,
V_82 -> V_251 ) ;
F_100 ( V_247 ) ;
if ( V_14 )
goto V_252;
}
return V_33 ;
V_252:
F_21 ( V_33 ) ;
V_73:
* V_83 = 0 ;
return NULL ;
}
struct V_5 * F_101 (
const struct V_26 * V_27 ,
const struct V_5 * V_6 ,
struct V_3 * V_4 , T_5 V_23 ,
int * error , struct V_3 * * V_253 )
{
struct V_5 * V_33 = NULL ;
struct V_235 * V_82 ;
struct V_238 * V_254 ;
int V_236 , V_237 , V_255 ;
T_9 * V_256 = V_27 -> V_256 ;
unsigned int V_15 ;
T_17 V_229 ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_18 V_257 ;
V_236 = sizeof( struct V_212 ) +
( sizeof( struct V_235 ) -
sizeof( struct V_238 ) ) ;
V_237 = F_18 ( V_4 -> V_153 -> V_17 ) - V_236 ;
V_255 = V_236 + sizeof( struct V_238 ) ;
V_15 = F_18 ( V_4 -> V_153 -> V_17 ) ;
if ( V_15 < V_255 + sizeof( struct V_212 ) )
goto V_258;
if ( V_237 % V_239 )
goto V_258;
V_82 = V_4 -> V_18 . V_97 ;
V_254 = & V_82 -> V_48 ;
if ( ! F_15 ( V_27 -> V_8 . V_7 ) -> V_193 )
goto V_259;
{
F_97 ( V_247 , F_15 ( V_27 -> V_8 . V_7 ) -> V_193 ) ;
int V_14 ;
V_247 -> V_248 = F_15 ( V_27 -> V_8 . V_7 ) -> V_193 ;
V_247 -> V_109 = 0 ;
V_14 = F_98 ( V_247 -> V_248 , V_27 -> V_249 ,
sizeof( V_27 -> V_249 ) ) ? :
F_99 ( V_247 , ( V_250 * ) V_254 , V_237 ,
V_256 ) ;
F_100 ( V_247 ) ;
if ( V_14 ) {
* error = - V_260 ;
goto V_261;
}
}
if ( memcmp ( V_256 , V_82 -> V_251 , V_262 ) ) {
* error = - V_263 ;
goto V_261;
}
V_259:
if ( F_102 ( V_4 -> V_264 -> V_265 ) != V_254 -> V_49 ) {
* error = - V_266 ;
goto V_261;
}
if ( V_4 -> V_264 -> V_211 != V_254 -> V_232 . V_267 . V_268 ||
F_18 ( V_4 -> V_264 -> V_210 ) != V_254 -> V_269 ) {
* error = - V_270 ;
goto V_261;
}
if ( F_103 ( V_27 -> V_8 . V_7 , V_271 ) )
V_257 = F_104 ( V_2 ) ;
else
V_257 = F_96 () ;
if ( ! V_6 && F_105 ( V_254 -> V_244 , V_257 ) ) {
V_15 = F_18 ( V_4 -> V_153 -> V_17 ) ;
* V_253 = F_53 ( V_6 , V_4 , V_15 ) ;
if ( * V_253 ) {
T_19 V_272 = F_106 ( F_107 ( V_257 , V_254 -> V_244 ) ) ;
T_15 V_273 = F_14 ( V_272 ) ;
F_5 ( * V_253 , V_274 ,
sizeof( V_273 ) ) ;
F_7 ( * V_253 , sizeof( V_273 ) , & V_273 ) ;
* error = - V_275 ;
} else
* error = - V_260 ;
goto V_261;
}
V_229 = F_92 ( F_66 ( V_4 ) ) ;
V_33 = F_93 ( V_27 , V_27 -> V_8 . V_7 , V_229 , V_23 ) ;
if ( ! V_33 ) {
* error = - V_260 ;
goto V_261;
}
V_33 -> V_86 . V_276 = F_18 ( V_4 -> V_264 -> V_211 ) ;
memcpy ( & V_33 -> V_48 , V_254 , sizeof( * V_254 ) ) ;
if ( F_108 ( V_33 , V_254 ,
V_96 ) < 0 ) {
* error = - V_260 ;
goto V_261;
}
if ( F_73 ( & V_33 -> V_8 . V_84 . V_277 ) ) {
F_109 ( & V_33 -> V_8 . V_84 , & V_4 -> V_210 ,
sizeof( V_4 -> V_210 ) , V_278 ,
V_96 ) ;
}
V_33 -> V_279 = V_33 -> V_48 . V_56 ;
V_33 -> V_280 = V_33 -> V_279 - 1 ;
V_33 -> V_281 = V_33 -> V_48 . V_56 ;
V_33 -> V_282 = V_33 -> V_48 . V_56 ;
V_33 -> V_283 = V_33 -> V_280 ;
V_33 -> V_86 . V_88 = V_33 -> V_48 . V_88 ;
V_33 -> V_86 . V_68 = V_33 -> V_48 . V_68 ;
return V_33 ;
V_261:
if ( V_33 )
F_110 ( V_33 ) ;
return NULL ;
V_258:
* error = - V_284 ;
goto V_261;
}
static int F_111 ( const struct V_5 * V_6 ,
enum V_285 V_286 ,
struct V_3 * V_4 ,
struct V_3 * * V_253 )
{
struct V_287 V_288 ;
T_4 V_15 ;
V_15 = F_16 ( sizeof( V_288 ) ) ;
if ( ! * V_253 )
* V_253 = F_53 ( V_6 , V_4 , V_15 ) ;
if ( * V_253 ) {
V_288 . V_289 = F_14 ( 1 ) ;
V_288 . type = V_286 ;
F_5 ( * V_253 , V_290 ,
sizeof( V_288 ) ) ;
F_7 ( * V_253 , sizeof( V_288 ) , & V_288 ) ;
}
return 0 ;
}
static int F_112 ( const struct V_5 * V_6 ,
struct V_3 * V_4 ,
struct V_3 * * V_253 )
{
if ( ! * V_253 )
* V_253 = F_53 ( V_6 , V_4 , 0 ) ;
if ( * V_253 )
F_5 ( * V_253 , V_291 , 0 ) ;
return 0 ;
}
static int F_113 ( const struct V_5 * V_6 ,
struct V_44 * V_172 ,
const struct V_3 * V_4 ,
struct V_3 * * V_253 )
{
if ( * V_253 )
F_45 ( * V_253 ) ;
* V_253 = F_49 ( V_6 , V_4 , V_172 ) ;
return 0 ;
}
static int F_114 ( const struct V_5 * V_6 ,
union V_30 V_172 ,
struct V_3 * V_4 ,
struct V_3 * * V_253 )
{
T_4 V_15 = F_18 ( V_172 . V_241 -> V_17 ) ;
if ( * V_253 )
F_45 ( * V_253 ) ;
* V_253 = F_53 ( V_6 , V_4 , V_15 ) ;
if ( * V_253 ) {
F_5 ( * V_253 , V_292 , V_15 ) ;
F_7 ( * V_253 , V_15 , V_172 . V_76 ) ;
}
return 0 ;
}
static int F_115 ( struct V_25 * V_25 , union V_30 V_172 )
{
T_4 V_42 = F_18 ( V_172 . V_241 -> V_17 ) - sizeof( struct V_44 ) ;
int V_293 = 0 ;
int V_294 = 0 ;
int V_295 ;
for ( V_295 = 0 ; V_295 < V_42 ; V_295 ++ ) {
switch ( V_172 . V_296 -> V_297 [ V_295 ] ) {
case V_71 :
V_293 = 1 ;
break;
case V_64 :
case V_65 :
V_294 = 1 ;
break;
}
}
if ( V_25 -> V_62 . V_298 )
return 1 ;
if ( V_25 -> V_62 . V_63 && ! V_293 && V_294 )
return 0 ;
return 1 ;
}
static void F_116 ( struct V_5 * V_6 ,
union V_30 V_172 )
{
struct V_25 * V_25 = F_12 ( V_6 -> V_8 . V_7 ) ;
T_4 V_42 = F_18 ( V_172 . V_241 -> V_17 ) - sizeof( struct V_44 ) ;
int V_295 ;
for ( V_295 = 0 ; V_295 < V_42 ; V_295 ++ ) {
switch ( V_172 . V_296 -> V_297 [ V_295 ] ) {
case V_67 :
if ( V_6 -> V_66 &&
! V_6 -> V_86 . V_90 )
V_6 -> V_86 . V_90 = 1 ;
break;
case V_299 :
if ( V_6 -> V_60 && ! V_6 -> V_86 . V_88 )
V_6 -> V_86 . V_88 = 1 ;
break;
case V_71 :
if ( V_6 -> V_27 -> V_69 )
V_6 -> V_86 . V_91 = 1 ;
break;
case V_64 :
case V_65 :
if ( V_25 -> V_62 . V_63 )
V_6 -> V_86 . V_89 = 1 ;
break;
default:
break;
}
}
}
static T_20 F_117 ( const struct V_5 * V_6 ,
union V_30 V_172 ,
struct V_3 * V_4 ,
struct V_3 * * V_253 )
{
int V_33 = V_300 ;
switch ( V_172 . V_241 -> type & V_301 ) {
case V_302 :
V_33 = V_303 ;
break;
case V_304 :
break;
case V_305 :
V_33 = V_303 ;
case V_306 :
if ( NULL == * V_253 )
* V_253 = F_54 ( V_6 , V_4 ) ;
if ( * V_253 ) {
if ( ! F_8 ( * V_253 , V_307 ,
F_16 ( F_18 ( V_172 . V_241 -> V_17 ) ) ) )
F_10 ( * V_253 ,
F_16 ( F_18 ( V_172 . V_241 -> V_17 ) ) ,
V_172 . V_76 ) ;
} else {
V_33 = V_260 ;
}
break;
default:
break;
}
return V_33 ;
}
static T_20 F_118 ( struct V_25 * V_25 ,
const struct V_26 * V_27 ,
const struct V_5 * V_6 ,
union V_30 V_172 ,
enum V_308 V_309 ,
struct V_3 * V_4 ,
struct V_3 * * V_160 )
{
struct V_310 * V_311 ;
int V_33 = V_300 ;
T_4 V_312 , V_313 = 0 ;
int V_295 ;
switch ( V_172 . V_241 -> type ) {
case V_314 :
case V_315 :
case V_316 :
case V_77 :
case V_242 :
case V_176 :
case V_317 :
case V_318 :
case V_79 :
break;
case V_78 :
if ( ! F_115 ( V_25 , V_172 ) )
return V_319 ;
break;
case V_320 :
if ( V_25 -> V_62 . V_63 )
break;
goto V_321;
case V_322 :
F_114 ( V_6 , V_172 , V_4 , V_160 ) ;
V_33 = V_319 ;
break;
case V_323 :
if ( V_27 -> V_60 )
break;
goto V_321;
case V_324 :
if ( ! V_27 -> V_69 )
goto V_321;
if ( V_325 !=
F_18 ( V_172 . V_241 -> V_17 ) - sizeof( struct V_44 ) ) {
F_113 ( V_6 , V_172 . V_241 ,
V_4 , V_160 ) ;
V_33 = V_319 ;
}
break;
case V_326 :
if ( ! V_27 -> V_69 )
goto V_321;
if ( 260 < F_18 ( V_172 . V_241 -> V_17 ) ) {
F_113 ( V_6 , V_172 . V_241 ,
V_4 , V_160 ) ;
V_33 = V_319 ;
}
break;
case V_327 :
if ( ! V_27 -> V_69 )
goto V_321;
V_311 = (struct V_310 * ) V_172 . V_241 ;
V_312 = ( F_18 ( V_172 . V_241 -> V_17 ) -
sizeof( struct V_44 ) ) >> 1 ;
for ( V_295 = 0 ; V_295 < V_312 ; V_295 ++ ) {
V_313 = F_18 ( V_311 -> V_328 [ V_295 ] ) ;
if ( V_313 == V_329 )
break;
}
if ( V_313 != V_329 ) {
F_113 ( V_6 , V_172 . V_241 , V_4 ,
V_160 ) ;
V_33 = V_319 ;
}
break;
V_321:
default:
F_32 ( L_5 ,
V_137 , F_18 ( V_172 . V_241 -> type ) , V_309 ) ;
V_33 = F_117 ( V_6 , V_172 , V_4 , V_160 ) ;
break;
}
return V_33 ;
}
int F_119 ( struct V_25 * V_25 , const struct V_26 * V_27 ,
const struct V_5 * V_6 , enum V_308 V_309 ,
struct V_330 * V_246 ,
struct V_3 * V_4 , struct V_3 * * V_253 )
{
union V_30 V_172 ;
bool V_331 = false ;
int V_332 ;
if ( V_246 -> V_74 . V_52 == 0 ||
V_246 -> V_74 . V_54 == 0 ||
V_246 -> V_74 . V_47 == 0 ||
F_102 ( V_246 -> V_74 . V_50 ) < V_333 )
return F_112 ( V_6 , V_4 , V_253 ) ;
F_120 (param, peer_init, init_hdr.params) {
if ( V_172 . V_241 -> type == V_242 )
V_331 = true ;
}
if ( V_172 . V_76 != ( void * ) V_4 -> V_168 )
return F_113 ( V_6 , V_172 . V_241 , V_4 , V_253 ) ;
if ( ( V_92 == V_309 ) && ! V_331 )
return F_111 ( V_6 , V_242 ,
V_4 , V_253 ) ;
F_120 (param, peer_init, init_hdr.params) {
V_332 = F_118 ( V_25 , V_27 , V_6 , V_172 , V_309 ,
V_4 , V_253 ) ;
switch ( V_332 ) {
case V_319 :
case V_260 :
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
const union V_208 * V_232 ,
struct V_330 * V_246 , T_5 V_23 )
{
struct V_25 * V_25 = F_12 ( V_6 -> V_8 . V_7 ) ;
union V_30 V_172 ;
struct V_135 * V_94 ;
struct V_334 * V_335 , * V_230 ;
struct V_336 * V_10 ;
union V_208 V_337 ;
char * V_82 ;
int V_338 = 0 ;
if ( ! F_122 ( V_6 , V_232 , V_23 , V_339 ) )
goto V_340;
if ( F_123 ( F_66 ( V_4 ) , V_232 ) )
V_338 = 1 ;
F_120 (param, peer_init, init_hdr.params) {
if ( ! V_338 && ( V_172 . V_241 -> type == V_314 ||
V_172 . V_241 -> type == V_315 ) ) {
V_10 = F_124 ( F_125 ( V_172 . V_241 -> type ) ) ;
V_10 -> V_341 ( & V_337 , V_172 . V_337 ,
V_4 -> V_264 -> V_211 , 0 ) ;
if ( F_123 ( F_66 ( V_4 ) , & V_337 ) )
V_338 = 1 ;
}
if ( ! F_126 ( V_6 , V_172 , V_232 , V_23 ) )
goto V_342;
}
if ( ! V_338 )
goto V_342;
if ( V_6 -> V_86 . V_91 && ( ! V_6 -> V_86 . V_343 ||
! V_6 -> V_86 . V_344 ) )
V_6 -> V_86 . V_91 = 0 ;
if ( ! V_25 -> V_62 . V_298 &&
( V_6 -> V_86 . V_89 && ! V_6 -> V_86 . V_91 ) ) {
V_6 -> V_86 . V_345 |= ( V_346 |
V_347 |
V_320 ) ;
V_6 -> V_86 . V_89 = 0 ;
goto V_342;
}
F_127 (pos, temp, &asoc->peer.transport_addr_list) {
V_94 = F_128 ( V_335 , struct V_135 , V_348 ) ;
if ( V_94 -> V_349 == V_350 ) {
F_129 ( V_6 , V_94 ) ;
}
}
V_6 -> V_86 . V_295 . V_47 =
F_102 ( V_246 -> V_74 . V_47 ) ;
V_6 -> V_86 . V_295 . V_50 =
F_102 ( V_246 -> V_74 . V_50 ) ;
V_6 -> V_86 . V_295 . V_52 =
F_18 ( V_246 -> V_74 . V_52 ) ;
V_6 -> V_86 . V_295 . V_54 =
F_18 ( V_246 -> V_74 . V_54 ) ;
V_6 -> V_86 . V_295 . V_56 =
F_102 ( V_246 -> V_74 . V_56 ) ;
V_6 -> V_351 = V_6 -> V_86 . V_295 . V_56 ;
if ( V_6 -> V_48 . V_53 >
F_18 ( V_246 -> V_74 . V_54 ) ) {
V_6 -> V_48 . V_53 =
F_18 ( V_246 -> V_74 . V_54 ) ;
}
if ( V_6 -> V_48 . V_55 >
F_18 ( V_246 -> V_74 . V_52 ) ) {
V_6 -> V_48 . V_55 =
F_18 ( V_246 -> V_74 . V_52 ) ;
}
V_6 -> V_48 . V_352 = V_6 -> V_86 . V_295 . V_47 ;
V_6 -> V_86 . V_51 = V_6 -> V_86 . V_295 . V_50 ;
V_82 = V_6 -> V_86 . V_82 ;
if ( V_82 ) {
V_6 -> V_86 . V_82 = F_130 ( V_82 , V_6 -> V_86 . V_83 , V_23 ) ;
if ( ! V_6 -> V_86 . V_82 )
goto V_342;
}
F_36 (transport, &asoc->peer.transport_addr_list,
transports) {
V_94 -> V_353 = V_6 -> V_86 . V_295 . V_50 ;
}
if ( ! F_131 ( & V_6 -> V_86 . V_131 , V_354 ,
V_6 -> V_86 . V_295 . V_56 , V_23 ) )
goto V_342;
if ( F_132 ( & V_6 -> V_115 , V_6 -> V_48 . V_53 ,
V_6 -> V_48 . V_55 , V_23 ) )
goto V_342;
if ( ! V_6 -> V_230 && F_133 ( V_6 , V_23 ) )
goto V_342;
V_6 -> V_86 . V_281 = V_6 -> V_86 . V_295 . V_56 - 1 ;
return 1 ;
V_342:
F_127 (pos, temp, &asoc->peer.transport_addr_list) {
V_94 = F_128 ( V_335 , struct V_135 , V_348 ) ;
if ( V_94 -> V_349 != V_339 )
F_129 ( V_6 , V_94 ) ;
}
V_340:
return 0 ;
}
static int F_126 ( struct V_5 * V_6 ,
union V_30 V_172 ,
const union V_208 * V_232 ,
T_5 V_23 )
{
struct V_25 * V_25 = F_12 ( V_6 -> V_8 . V_7 ) ;
union V_208 V_337 ;
int V_295 ;
T_4 V_38 ;
int V_33 = 1 ;
T_17 V_229 ;
T_21 V_355 ;
struct V_336 * V_10 ;
union V_356 * V_357 ;
struct V_135 * V_358 ;
struct V_26 * V_27 = V_6 -> V_27 ;
switch ( V_172 . V_241 -> type ) {
case V_315 :
if ( V_359 != V_6 -> V_8 . V_7 -> V_360 )
break;
goto V_361;
case V_314 :
if ( F_134 ( V_6 -> V_8 . V_7 ) )
break;
V_361:
V_10 = F_124 ( F_125 ( V_172 . V_241 -> type ) ) ;
V_10 -> V_341 ( & V_337 , V_172 . V_337 , F_6 ( V_6 -> V_86 . V_276 ) , 0 ) ;
V_229 = F_92 ( V_232 ) ;
if ( F_135 ( V_25 , & V_337 , V_229 ) )
if ( ! F_122 ( V_6 , & V_337 , V_23 , V_362 ) )
return 0 ;
break;
case V_316 :
if ( ! V_25 -> V_62 . V_363 )
break;
V_355 = F_102 ( V_172 . V_364 -> V_365 ) ;
V_6 -> V_245 = F_136 ( V_6 -> V_245 , V_355 ) ;
break;
case V_322 :
F_32 ( L_6 , V_137 ) ;
break;
case V_77 :
V_6 -> V_86 . V_366 = 0 ;
V_6 -> V_86 . V_367 = 0 ;
if ( V_232 -> V_368 . V_369 == V_370 )
V_6 -> V_86 . V_367 = 1 ;
else if ( V_232 -> V_368 . V_369 == V_371 )
V_6 -> V_86 . V_366 = 1 ;
V_38 = F_18 ( V_172 . V_241 -> V_17 ) - sizeof( struct V_44 ) ;
if ( V_38 )
V_38 /= sizeof( T_4 ) ;
for ( V_295 = 0 ; V_295 < V_38 ; ++ V_295 ) {
switch ( V_172 . V_38 -> V_39 [ V_295 ] ) {
case V_314 :
V_6 -> V_86 . V_366 = 1 ;
break;
case V_315 :
if ( V_359 == V_6 -> V_8 . V_7 -> V_360 )
V_6 -> V_86 . V_367 = 1 ;
break;
case V_322 :
V_6 -> V_86 . V_372 = 1 ;
break;
default:
break;
}
}
break;
case V_242 :
V_6 -> V_86 . V_83 =
F_18 ( V_172 . V_241 -> V_17 ) - sizeof( struct V_44 ) ;
V_6 -> V_86 . V_82 = V_172 . V_82 -> V_240 ;
break;
case V_176 :
break;
case V_317 :
break;
case V_318 :
V_6 -> V_86 . V_87 = 1 ;
break;
case V_79 :
V_6 -> V_86 . V_68 = F_102 ( V_172 . V_373 -> V_68 ) ;
break;
case V_320 :
if ( ! V_25 -> V_62 . V_63 )
goto V_374;
V_357 = V_172 . V_76 + sizeof( V_375 ) ;
V_10 = F_124 ( F_125 ( V_357 -> V_241 . type ) ) ;
if ( V_10 == NULL )
break;
V_10 -> V_341 ( & V_337 , V_357 ,
F_6 ( V_6 -> V_86 . V_276 ) , 0 ) ;
if ( ! V_10 -> V_376 ( & V_337 , NULL , NULL ) )
break;
V_358 = F_137 ( V_6 , & V_337 ) ;
if ( ! V_358 )
break;
F_138 ( V_6 , V_358 ) ;
break;
case V_78 :
F_116 ( V_6 , V_172 ) ;
break;
case V_323 :
if ( V_6 -> V_60 ) {
V_6 -> V_86 . V_88 = 1 ;
break;
}
goto V_374;
case V_324 :
if ( ! V_27 -> V_69 )
goto V_374;
V_6 -> V_86 . V_343 = F_130 ( V_172 . V_241 ,
F_18 ( V_172 . V_241 -> V_17 ) , V_23 ) ;
if ( ! V_6 -> V_86 . V_343 ) {
V_33 = 0 ;
break;
}
break;
case V_327 :
if ( ! V_27 -> V_69 )
goto V_374;
V_6 -> V_86 . V_344 = F_130 ( V_172 . V_241 ,
F_18 ( V_172 . V_241 -> V_17 ) , V_23 ) ;
if ( ! V_6 -> V_86 . V_344 ) {
V_33 = 0 ;
break;
}
F_139 ( V_6 , V_172 . V_377 ) ;
break;
case V_326 :
if ( ! V_27 -> V_69 )
goto V_374;
V_6 -> V_86 . V_378 = F_130 ( V_172 . V_241 ,
F_18 ( V_172 . V_241 -> V_17 ) , V_23 ) ;
if ( ! V_6 -> V_86 . V_378 )
V_33 = 0 ;
break;
V_374:
default:
F_32 ( L_7 ,
V_137 , F_18 ( V_172 . V_241 -> type ) , V_6 ) ;
break;
}
return V_33 ;
}
T_11 F_140 ( const struct V_26 * V_27 )
{
T_11 V_379 ;
do {
F_141 ( & V_379 , sizeof( T_11 ) ) ;
} while ( V_379 == 0 );
return V_379 ;
}
T_11 F_142 ( const struct V_26 * V_27 )
{
T_11 V_33 ;
F_141 ( & V_33 , sizeof( T_11 ) ) ;
return V_33 ;
}
static struct V_3 * F_143 ( struct V_5 * V_6 ,
union V_208 * V_337 ,
int V_24 )
{
T_22 V_380 ;
struct V_3 * V_33 ;
int V_17 = sizeof( V_380 ) + V_24 ;
union V_356 V_381 ;
int V_382 ;
struct V_336 * V_10 = F_124 ( V_337 -> V_267 . V_383 ) ;
V_382 = V_10 -> V_384 ( V_337 , & V_381 ) ;
if ( ! V_382 )
return NULL ;
V_17 += V_382 ;
V_33 = F_19 ( V_6 , V_64 , 0 , V_17 ,
V_96 ) ;
if ( ! V_33 )
return NULL ;
V_380 . V_385 = F_14 ( V_6 -> V_281 ++ ) ;
V_33 -> V_18 . V_386 =
F_7 ( V_33 , sizeof( V_380 ) , & V_380 ) ;
V_33 -> V_75 . V_76 =
F_7 ( V_33 , V_382 , & V_381 ) ;
return V_33 ;
}
struct V_3 * F_144 ( struct V_5 * V_6 ,
union V_208 * V_387 ,
struct V_388 * V_31 ,
int V_389 ,
T_1 V_109 )
{
V_375 V_172 ;
struct V_3 * V_33 ;
union V_356 V_357 ;
union V_208 * V_337 ;
void * V_390 ;
struct V_336 * V_10 ;
int V_391 = sizeof( V_172 ) ;
int V_392 = 0 ;
int V_393 = 0 ;
int V_295 ;
int V_394 = 0 ;
V_390 = V_31 ;
for ( V_295 = 0 ; V_295 < V_389 ; V_295 ++ ) {
V_337 = V_390 ;
V_10 = F_124 ( V_337 -> V_267 . V_383 ) ;
V_392 = V_10 -> V_384 ( V_337 , & V_357 ) ;
V_393 += V_391 ;
V_393 += V_392 ;
V_390 += V_10 -> V_395 ;
if ( V_6 -> V_396 && ! V_394 ) {
V_393 += V_391 ;
V_393 += V_392 ;
V_394 = 1 ;
F_32 ( L_8
L_9 ,
V_137 , V_393 ) ;
}
}
V_33 = F_143 ( V_6 , V_387 , V_393 ) ;
if ( ! V_33 )
return NULL ;
V_390 = V_31 ;
for ( V_295 = 0 ; V_295 < V_389 ; V_295 ++ ) {
V_337 = V_390 ;
V_10 = F_124 ( V_337 -> V_267 . V_383 ) ;
V_392 = V_10 -> V_384 ( V_337 , & V_357 ) ;
V_172 . V_75 . type = V_109 ;
V_172 . V_75 . V_17 = F_6 ( V_391 + V_392 ) ;
V_172 . V_397 = V_295 ;
F_7 ( V_33 , V_391 , & V_172 ) ;
F_7 ( V_33 , V_392 , & V_357 ) ;
V_390 += V_10 -> V_395 ;
}
if ( V_109 == V_346 && V_394 ) {
V_337 = V_6 -> V_396 ;
V_10 = F_124 ( V_337 -> V_267 . V_383 ) ;
V_392 = V_10 -> V_384 ( V_337 , & V_357 ) ;
V_172 . V_75 . type = V_347 ;
V_172 . V_75 . V_17 = F_6 ( V_391 + V_392 ) ;
V_172 . V_397 = V_295 ;
F_7 ( V_33 , V_391 , & V_172 ) ;
F_7 ( V_33 , V_392 , & V_357 ) ;
}
return V_33 ;
}
struct V_3 * F_145 ( struct V_5 * V_6 ,
union V_208 * V_337 )
{
V_375 V_172 ;
struct V_3 * V_33 ;
int V_15 = sizeof( V_172 ) ;
union V_356 V_381 ;
int V_382 ;
struct V_336 * V_10 = F_124 ( V_337 -> V_267 . V_383 ) ;
V_382 = V_10 -> V_384 ( V_337 , & V_381 ) ;
if ( ! V_382 )
return NULL ;
V_15 += V_382 ;
V_33 = F_143 ( V_6 , V_337 , V_15 ) ;
if ( ! V_33 )
return NULL ;
V_172 . V_75 . type = V_320 ;
V_172 . V_75 . V_17 = F_6 ( V_15 ) ;
V_172 . V_397 = 0 ;
F_7 ( V_33 , sizeof( V_172 ) , & V_172 ) ;
F_7 ( V_33 , V_382 , & V_381 ) ;
return V_33 ;
}
static struct V_3 * F_146 ( const struct V_5 * V_6 ,
T_11 V_385 , int V_24 )
{
T_22 V_380 ;
struct V_3 * V_33 ;
int V_17 = sizeof( V_380 ) + V_24 ;
V_33 = F_19 ( V_6 , V_65 , 0 , V_17 ,
V_96 ) ;
if ( ! V_33 )
return NULL ;
V_380 . V_385 = F_14 ( V_385 ) ;
V_33 -> V_18 . V_386 =
F_7 ( V_33 , sizeof( V_380 ) , & V_380 ) ;
return V_33 ;
}
static void F_147 ( struct V_3 * V_4 , T_15 V_397 ,
T_1 V_398 , V_375 * V_399 )
{
V_375 V_400 ;
T_3 V_401 ;
int V_402 = 0 ;
int V_403 = 0 ;
T_1 V_404 ;
if ( V_405 == V_398 ) {
V_404 = V_406 ;
} else {
V_404 = V_407 ;
V_403 = sizeof( V_401 ) ;
if ( V_399 )
V_402 =
F_18 ( V_399 -> V_75 . V_17 ) ;
}
V_400 . V_75 . type = V_404 ;
V_400 . V_75 . V_17 = F_6 ( sizeof( V_400 ) +
V_403 +
V_402 ) ;
V_400 . V_397 = V_397 ;
F_7 ( V_4 , sizeof( V_400 ) , & V_400 ) ;
if ( V_405 == V_398 )
return;
V_401 . V_16 = V_398 ;
V_401 . V_17 = F_6 ( V_403 + V_402 ) ;
F_7 ( V_4 , V_403 , & V_401 ) ;
if ( V_399 )
F_7 ( V_4 , V_402 , V_399 ) ;
}
static T_1 F_148 ( struct V_5 * V_6 ,
struct V_3 * V_380 ,
V_375 * V_399 )
{
struct V_135 * V_86 ;
struct V_336 * V_10 ;
union V_208 V_337 ;
union V_356 * V_357 ;
V_357 = ( void * ) V_399 + sizeof( V_375 ) ;
if ( V_399 -> V_75 . type != V_346 &&
V_399 -> V_75 . type != V_347 &&
V_399 -> V_75 . type != V_320 )
return V_307 ;
switch ( V_357 -> V_241 . type ) {
case V_315 :
if ( ! V_6 -> V_86 . V_367 )
return V_292 ;
break;
case V_314 :
if ( ! V_6 -> V_86 . V_366 )
return V_292 ;
break;
default:
return V_292 ;
}
V_10 = F_124 ( F_125 ( V_357 -> V_241 . type ) ) ;
if ( F_58 ( ! V_10 ) )
return V_292 ;
V_10 -> V_341 ( & V_337 , V_357 , F_6 ( V_6 -> V_86 . V_276 ) , 0 ) ;
if ( ! V_10 -> V_408 ( & V_337 ) && ! V_10 -> V_376 ( & V_337 , NULL , V_380 -> V_2 ) )
return V_292 ;
switch ( V_399 -> V_75 . type ) {
case V_346 :
if ( V_10 -> V_408 ( & V_337 ) )
memcpy ( & V_337 , & V_380 -> V_211 , sizeof( V_337 ) ) ;
V_86 = F_122 ( V_6 , & V_337 , V_96 , V_362 ) ;
if ( ! V_86 )
return V_409 ;
F_149 ( V_86 ) ;
V_6 -> V_410 = V_86 ;
break;
case V_347 :
if ( V_6 -> V_86 . V_411 == 1 )
return V_412 ;
if ( F_123 ( & V_380 -> V_211 , & V_337 ) )
return V_413 ;
if ( V_10 -> V_408 ( & V_337 ) ) {
F_138 ( V_6 , V_380 -> V_94 ) ;
F_150 ( V_6 ,
V_380 -> V_94 ) ;
return V_405 ;
}
V_86 = F_137 ( V_6 , & V_337 ) ;
if ( ! V_86 )
return V_292 ;
F_129 ( V_6 , V_86 ) ;
break;
case V_320 :
if ( V_10 -> V_408 ( & V_337 ) )
memcpy ( & V_337 . V_267 , F_66 ( V_380 ) , sizeof( V_337 ) ) ;
V_86 = F_137 ( V_6 , & V_337 ) ;
if ( ! V_86 )
return V_292 ;
F_138 ( V_6 , V_86 ) ;
break;
}
return V_405 ;
}
bool F_151 ( const struct V_5 * V_6 ,
struct V_3 * V_4 , bool V_414 ,
struct V_44 * * V_253 )
{
T_23 * V_415 = ( T_23 * ) V_4 -> V_153 ;
union V_30 V_172 ;
bool V_416 = false ;
F_120 (param, addip, addip_hdr.params) {
T_2 V_17 = F_18 ( V_172 . V_241 -> V_17 ) ;
* V_253 = V_172 . V_241 ;
switch ( V_172 . V_241 -> type ) {
case V_407 :
break;
case V_314 :
if ( V_17 != sizeof( V_417 ) )
return false ;
if ( V_172 . V_76 != V_415 -> V_386 . V_418 )
return false ;
V_416 = true ;
break;
case V_315 :
if ( V_17 != sizeof( V_419 ) )
return false ;
if ( V_172 . V_76 != V_415 -> V_386 . V_418 )
return false ;
V_416 = true ;
break;
case V_346 :
case V_347 :
case V_320 :
if ( V_414 && ! V_416 )
return false ;
V_17 = F_18 ( V_172 . V_415 -> V_75 . V_17 ) ;
if ( V_17 < sizeof( V_375 ) +
sizeof( * * V_253 ) )
return false ;
break;
case V_406 :
case V_79 :
if ( V_17 != sizeof( V_375 ) )
return false ;
break;
default:
return false ;
}
}
if ( V_414 && ! V_416 )
return false ;
if ( ! V_414 && V_416 )
return false ;
if ( V_172 . V_76 != V_4 -> V_168 )
return false ;
return true ;
}
struct V_3 * F_152 ( struct V_5 * V_6 ,
struct V_3 * V_380 )
{
T_23 * V_415 = ( T_23 * ) V_380 -> V_153 ;
bool V_420 = true ;
union V_30 V_172 ;
T_22 * V_421 ;
union V_356 * V_357 ;
struct V_3 * V_422 ;
T_1 V_398 ;
int V_17 = 0 ;
int V_113 ;
T_11 V_385 ;
V_113 = F_18 ( V_380 -> V_153 -> V_17 ) -
sizeof( struct V_212 ) ;
V_421 = ( T_22 * ) V_380 -> V_2 -> V_165 ;
V_385 = F_102 ( V_421 -> V_385 ) ;
V_17 = sizeof( T_22 ) ;
V_357 = (union V_356 * ) ( V_380 -> V_2 -> V_165 + V_17 ) ;
V_113 -= V_17 ;
V_17 = F_18 ( V_357 -> V_241 . V_17 ) ;
V_113 -= V_17 ;
V_422 = F_146 ( V_6 , V_385 , V_113 * 4 ) ;
if ( ! V_422 )
goto V_423;
F_120 (param, addip, addip_hdr.params) {
if ( V_172 . V_241 -> type == V_314 ||
V_172 . V_241 -> type == V_315 )
continue;
V_398 = F_148 ( V_6 , V_380 ,
V_172 . V_415 ) ;
if ( V_398 != V_405 )
V_420 = false ;
if ( ! V_420 )
F_147 ( V_422 , V_172 . V_415 -> V_397 ,
V_398 , V_172 . V_415 ) ;
if ( V_398 == V_409 )
goto V_423;
}
V_423:
V_6 -> V_86 . V_281 ++ ;
if ( V_422 ) {
F_80 ( V_422 ) ;
F_153 ( & V_422 -> V_205 ,
& V_6 -> V_424 ) ;
}
return V_422 ;
}
static void F_154 ( struct V_5 * V_6 ,
V_375 * V_399 )
{
struct V_336 * V_10 ;
union V_208 V_337 ;
struct V_21 * V_22 = & V_6 -> V_8 . V_84 ;
union V_356 * V_357 ;
struct V_135 * V_94 ;
struct V_425 * V_426 ;
V_357 = ( void * ) V_399 + sizeof( V_375 ) ;
V_10 = F_124 ( F_125 ( V_357 -> V_241 . type ) ) ;
V_10 -> V_341 ( & V_337 , V_357 , F_6 ( V_22 -> V_276 ) , 0 ) ;
switch ( V_399 -> V_75 . type ) {
case V_346 :
F_155 () ;
F_36 (saddr, &bp->address_list, list) {
if ( F_123 ( & V_426 -> V_427 , & V_337 ) )
V_426 -> V_349 = V_278 ;
}
F_156 () ;
F_36 (transport, &asoc->peer.transport_addr_list,
transports) {
F_157 ( V_94 ) ;
}
break;
case V_347 :
F_155 () ;
F_158 ( V_22 , & V_337 ) ;
if ( V_6 -> V_396 != NULL &&
F_123 ( V_6 -> V_396 , & V_337 ) ) {
F_21 ( V_6 -> V_396 ) ;
V_6 -> V_396 = NULL ;
}
F_156 () ;
F_36 (transport, &asoc->peer.transport_addr_list,
transports) {
F_157 ( V_94 ) ;
}
break;
default:
break;
}
}
static T_1 F_159 ( struct V_3 * V_422 ,
V_375 * V_399 ,
int V_428 )
{
V_375 * V_429 ;
T_3 * V_401 ;
int V_17 ;
int V_430 ;
T_1 V_398 ;
if ( V_428 )
V_398 = V_405 ;
else
V_398 = V_431 ;
V_430 = F_18 ( V_422 -> V_153 -> V_17 ) -
sizeof( struct V_212 ) ;
V_17 = sizeof( T_22 ) ;
V_429 = ( V_375 * ) ( V_422 -> V_2 -> V_165 +
V_17 ) ;
V_430 -= V_17 ;
while ( V_430 > 0 ) {
if ( V_429 -> V_397 == V_399 -> V_397 ) {
switch ( V_429 -> V_75 . type ) {
case V_406 :
return V_405 ;
case V_407 :
V_17 = sizeof( V_375 ) ;
V_401 = ( void * ) V_429 + V_17 ;
V_430 -= V_17 ;
if ( V_430 > 0 )
return V_401 -> V_16 ;
else
return V_291 ;
break;
default:
return V_291 ;
}
}
V_17 = F_18 ( V_429 -> V_75 . V_17 ) ;
V_429 = ( void * ) V_429 + V_17 ;
V_430 -= V_17 ;
}
return V_398 ;
}
int F_160 ( struct V_5 * V_6 ,
struct V_3 * V_422 )
{
struct V_3 * V_380 = V_6 -> V_432 ;
union V_356 * V_357 ;
V_375 * V_399 ;
int V_17 = 0 ;
int V_433 = V_380 -> V_2 -> V_15 ;
int V_420 = 0 ;
int V_428 = 1 ;
int V_33 = 0 ;
T_1 V_398 = V_405 ;
V_17 = sizeof( T_23 ) ;
V_357 = (union V_356 * ) ( V_380 -> V_2 -> V_165 + V_17 ) ;
V_433 -= V_17 ;
V_17 = F_18 ( V_357 -> V_241 . V_17 ) ;
V_399 = ( void * ) V_357 + V_17 ;
V_433 -= V_17 ;
if ( V_422 -> V_2 -> V_15 == sizeof( T_22 ) )
V_420 = 1 ;
while ( V_433 > 0 ) {
if ( V_420 )
V_398 = V_405 ;
else {
V_398 = F_159 ( V_422 ,
V_399 ,
V_428 ) ;
if ( V_428 && ( V_405 != V_398 ) )
V_428 = 0 ;
}
switch ( V_398 ) {
case V_405 :
F_154 ( V_6 , V_399 ) ;
break;
case V_409 :
V_33 = 1 ;
break;
case V_307 :
V_6 -> V_86 . V_345 |=
V_399 -> V_75 . type ;
break;
case V_431 :
case V_412 :
case V_413 :
default:
break;
}
V_17 = F_18 ( V_399 -> V_75 . V_17 ) ;
V_399 = ( void * ) V_399 + V_17 ;
V_433 -= V_17 ;
}
if ( V_428 && V_6 -> V_434 ) {
V_6 -> V_434 = 0 ;
F_161 ( V_6 -> V_86 . V_435 ) ;
}
F_74 ( & V_380 -> V_205 ) ;
F_45 ( V_380 ) ;
V_6 -> V_432 = NULL ;
return V_33 ;
}
struct V_3 * F_162 ( const struct V_5 * V_6 ,
T_11 V_436 , T_2 V_437 ,
struct V_438 * V_439 )
{
struct V_3 * V_33 = NULL ;
struct V_440 V_441 ;
struct V_438 V_442 ;
T_2 V_152 ;
int V_295 ;
V_152 = ( V_437 + 1 ) * sizeof( T_11 ) ;
V_33 = F_19 ( V_6 , V_299 , 0 , V_152 , V_96 ) ;
if ( ! V_33 )
return NULL ;
V_441 . V_436 = F_14 ( V_436 ) ;
V_33 -> V_18 . V_443 =
F_7 ( V_33 , sizeof( V_441 ) , & V_441 ) ;
for ( V_295 = 0 ; V_295 < V_437 ; V_295 ++ ) {
V_442 . V_115 = V_439 [ V_295 ] . V_115 ;
V_442 . V_110 = V_439 [ V_295 ] . V_110 ;
F_7 ( V_33 , sizeof( V_442 ) , & V_442 ) ;
}
return V_33 ;
}
static struct V_3 * F_163 (
const struct V_5 * V_6 ,
int V_17 )
{
struct V_444 * V_445 ;
struct V_3 * V_33 ;
V_33 = F_19 ( V_6 , V_67 , 0 , V_17 ,
V_96 ) ;
if ( ! V_33 )
return NULL ;
V_445 = (struct V_444 * ) V_33 -> V_153 ;
V_33 -> V_75 . V_76 = V_445 -> V_418 ;
return V_33 ;
}
struct V_3 * F_164 (
const struct V_5 * V_6 ,
T_4 V_446 , T_4 * V_447 ,
bool V_227 , bool V_448 )
{
struct V_449 V_450 ;
T_4 V_451 = V_446 * 2 ;
struct V_452 V_453 ;
struct V_3 * V_33 ;
T_4 V_454 , V_455 ;
V_454 = ( sizeof( V_450 ) + V_451 ) * V_227 ;
V_455 = ( sizeof( V_453 ) + V_451 ) * V_448 ;
V_33 = F_163 ( V_6 , V_454 + V_455 ) ;
if ( ! V_33 )
return NULL ;
if ( V_454 ) {
V_450 . V_75 . type = V_456 ;
V_450 . V_75 . V_17 = F_6 ( V_454 ) ;
V_450 . V_457 = F_14 ( V_6 -> V_282 ) ;
V_450 . V_458 = F_14 ( V_6 -> V_351 - 1 ) ;
V_450 . V_459 = F_14 ( V_6 -> V_279 - 1 ) ;
F_7 ( V_33 , sizeof( V_450 ) , & V_450 ) ;
if ( V_451 )
F_7 ( V_33 , V_451 , V_447 ) ;
}
if ( V_455 ) {
V_453 . V_75 . type = V_460 ;
V_453 . V_75 . V_17 = F_6 ( V_455 ) ;
V_453 . V_457 = F_14 ( V_6 -> V_282 + V_227 ) ;
F_7 ( V_33 , sizeof( V_453 ) , & V_453 ) ;
if ( V_451 )
F_7 ( V_33 , V_451 , V_447 ) ;
}
return V_33 ;
}
struct V_3 * F_165 (
const struct V_5 * V_6 )
{
struct V_461 V_462 ;
T_4 V_17 = sizeof( V_462 ) ;
struct V_3 * V_33 ;
V_33 = F_163 ( V_6 , V_17 ) ;
if ( ! V_33 )
return NULL ;
V_462 . V_75 . type = V_463 ;
V_462 . V_75 . V_17 = F_6 ( V_17 ) ;
V_462 . V_457 = F_14 ( V_6 -> V_282 ) ;
F_7 ( V_33 , sizeof( V_462 ) , & V_462 ) ;
return V_33 ;
}
struct V_3 * F_166 (
const struct V_5 * V_6 ,
T_4 V_227 , T_4 V_448 )
{
struct V_464 V_465 ;
T_4 V_184 = sizeof( V_465 ) ;
struct V_3 * V_33 ;
V_33 = F_163 ( V_6 , ( ! ! V_227 + ! ! V_448 ) * V_184 ) ;
if ( ! V_33 )
return NULL ;
if ( V_227 ) {
V_465 . V_75 . type = V_466 ;
V_465 . V_75 . V_17 = F_6 ( V_184 ) ;
V_465 . V_467 = F_6 ( V_227 ) ;
V_465 . V_457 = F_14 ( V_6 -> V_282 ) ;
V_465 . V_468 = 0 ;
F_7 ( V_33 , V_184 , & V_465 ) ;
}
if ( V_448 ) {
V_465 . V_75 . type = V_469 ;
V_465 . V_75 . V_17 = F_6 ( V_184 ) ;
V_465 . V_467 = F_6 ( V_448 ) ;
V_465 . V_457 = F_14 ( V_6 -> V_282 + ! ! V_227 ) ;
V_465 . V_468 = 0 ;
F_7 ( V_33 , V_184 , & V_465 ) ;
}
return V_33 ;
}
struct V_3 * F_167 (
const struct V_5 * V_6 ,
T_11 V_332 , T_11 V_470 )
{
struct V_471 V_472 ;
T_4 V_17 = sizeof( V_472 ) ;
struct V_3 * V_33 ;
V_33 = F_163 ( V_6 , V_17 ) ;
if ( ! V_33 )
return NULL ;
V_472 . V_75 . type = V_473 ;
V_472 . V_75 . V_17 = F_6 ( V_17 ) ;
V_472 . V_458 = F_14 ( V_470 ) ;
V_472 . V_332 = F_14 ( V_332 ) ;
F_7 ( V_33 , sizeof( V_472 ) , & V_472 ) ;
return V_33 ;
}
struct V_3 * F_168 (
struct V_5 * V_6 ,
T_11 V_332 , T_11 V_470 ,
T_11 V_474 , T_11 V_475 )
{
struct V_476 V_477 ;
T_4 V_17 = sizeof( V_477 ) ;
struct V_3 * V_33 ;
V_33 = F_163 ( V_6 , V_17 ) ;
if ( ! V_33 )
return NULL ;
V_477 . V_75 . type = V_473 ;
V_477 . V_75 . V_17 = F_6 ( V_17 ) ;
V_477 . V_458 = F_14 ( V_470 ) ;
V_477 . V_332 = F_14 ( V_332 ) ;
V_477 . V_478 = F_14 ( V_474 ) ;
V_477 . V_479 = F_14 ( V_475 ) ;
F_7 ( V_33 , sizeof( V_477 ) , & V_477 ) ;
return V_33 ;
}
bool F_169 ( const struct V_5 * V_6 ,
struct V_3 * V_4 ,
struct V_44 * * V_253 )
{
struct V_444 * V_421 ;
union V_30 V_172 ;
T_4 V_480 = 0 , V_481 = 0 ;
V_421 = (struct V_444 * ) V_4 -> V_153 ;
F_120 (param, hdr, params) {
T_4 V_17 = F_18 ( V_172 . V_241 -> V_17 ) ;
* V_253 = V_172 . V_241 ;
if ( V_481 ++ > 2 )
return false ;
switch ( V_172 . V_241 -> type ) {
case V_456 :
if ( V_17 < sizeof( struct V_449 ) ||
( V_480 && V_480 != V_473 &&
V_480 != V_460 ) )
return false ;
break;
case V_460 :
if ( V_17 < sizeof( struct V_452 ) ||
( V_480 && V_480 != V_456 ) )
return false ;
break;
case V_473 :
if ( ( V_17 != sizeof( struct V_471 ) &&
V_17 != sizeof( struct V_476 ) ) ||
( V_480 && V_480 != V_473 &&
V_480 != V_456 ) )
return false ;
break;
case V_463 :
if ( V_17 !=
sizeof( struct V_461 ) || V_480 )
return false ;
break;
case V_469 :
if ( V_17 != sizeof( struct V_464 ) ||
( V_480 && V_480 != V_466 ) )
return false ;
break;
case V_466 :
if ( V_17 != sizeof( struct V_464 ) ||
( V_480 && V_480 != V_469 ) )
return false ;
break;
default:
return false ;
}
V_480 = V_172 . V_241 -> type ;
}
return true ;
}

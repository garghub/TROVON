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
T_6 V_29 ;
union V_30 V_31 ;
T_2 V_32 ;
struct V_3 * V_33 = NULL ;
int V_34 , V_35 = 0 ;
struct V_36 * V_37 ;
T_7 V_38 ;
T_1 V_39 [ 2 ] ;
T_8 V_40 ;
T_9 V_41 ;
int V_42 = 0 ;
T_10 V_43 [ 3 ] ;
T_11 * V_44 = NULL ,
* V_45 = NULL ;
V_33 = NULL ;
V_31 = F_15 ( V_25 , & V_35 , V_26 ) ;
V_29 . V_46 = F_16 ( V_6 -> V_47 . V_48 ) ;
V_29 . V_49 = F_16 ( V_6 -> V_50 ) ;
V_29 . V_51 = F_8 ( V_6 -> V_47 . V_52 ) ;
V_29 . V_53 = F_8 ( V_6 -> V_47 . V_54 ) ;
V_29 . V_55 = F_16 ( V_6 -> V_47 . V_55 ) ;
V_37 = F_17 ( V_6 -> V_8 . V_7 ) ;
V_34 = V_37 -> V_56 -> V_57 ( V_37 , V_39 ) ;
V_32 = sizeof( V_29 ) + V_35 ;
V_32 += F_18 ( F_19 ( V_34 ) ) ;
V_32 += sizeof( V_58 ) ;
if ( V_28 -> V_59 . V_60 )
V_32 += sizeof( V_61 ) ;
if ( V_28 -> V_59 . V_62 ) {
V_43 [ V_42 ] = V_63 ;
V_43 [ V_42 + 1 ] = V_64 ;
V_42 += 2 ;
}
if ( V_37 -> V_65 )
V_32 += sizeof( V_40 ) ;
V_32 += V_27 ;
if ( V_28 -> V_59 . V_66 ) {
V_32 += sizeof( V_6 -> V_47 . V_67 ) ;
V_45 = ( T_11 * ) V_6 -> V_47 . V_45 ;
if ( V_45 -> V_20 )
V_32 += F_18 ( F_20 ( V_45 -> V_20 ) ) ;
else
V_45 = NULL ;
V_44 = ( T_11 * ) V_6 -> V_47 . V_44 ;
if ( V_44 -> V_20 )
V_32 += F_18 ( F_20 ( V_44 -> V_20 ) ) ;
else
V_44 = NULL ;
V_43 [ V_42 ] = V_68 ;
V_42 += 1 ;
}
if ( V_42 )
V_32 += F_18 ( sizeof( T_9 ) +
V_42 ) ;
V_33 = F_21 ( V_6 , V_69 , 0 , V_32 ) ;
if ( ! V_33 )
goto V_70;
V_33 -> V_21 . V_71 =
F_9 ( V_33 , sizeof( V_29 ) , & V_29 ) ;
V_33 -> V_72 . V_73 =
F_9 ( V_33 , V_35 , V_31 . V_73 ) ;
V_38 . V_72 . type = V_74 ;
V_38 . V_72 . V_20 = F_8 ( F_19 ( V_34 ) ) ;
F_9 ( V_33 , sizeof( V_38 ) , & V_38 ) ;
F_9 ( V_33 , V_34 * sizeof( T_4 ) , & V_39 ) ;
F_9 ( V_33 , sizeof( V_58 ) , & V_58 ) ;
if ( V_42 ) {
V_41 . V_72 . type = V_75 ;
V_41 . V_72 . V_20 =
F_8 ( sizeof( T_9 ) + V_42 ) ;
F_9 ( V_33 , sizeof( T_9 ) ,
& V_41 ) ;
F_22 ( V_33 , V_42 , V_43 ) ;
}
if ( V_28 -> V_59 . V_60 )
F_9 ( V_33 , sizeof( V_61 ) , & V_61 ) ;
if ( V_37 -> V_65 ) {
V_40 . V_72 . type = V_76 ;
V_40 . V_72 . V_20 = F_8 ( sizeof( V_40 ) ) ;
V_40 . V_65 = F_16 ( V_37 -> V_65 ) ;
F_9 ( V_33 , sizeof( V_40 ) , & V_40 ) ;
}
if ( V_28 -> V_59 . V_66 ) {
F_9 ( V_33 , sizeof( V_6 -> V_47 . V_67 ) ,
V_6 -> V_47 . V_67 ) ;
if ( V_45 )
F_9 ( V_33 , F_20 ( V_45 -> V_20 ) ,
V_45 ) ;
if ( V_44 )
F_9 ( V_33 , F_20 ( V_44 -> V_20 ) ,
V_44 ) ;
}
V_70:
F_23 ( V_31 . V_73 ) ;
return V_33 ;
}
struct V_3 * F_24 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
T_5 V_26 , int V_77 )
{
T_6 V_78 ;
struct V_3 * V_33 ;
union V_30 V_31 ;
struct V_36 * V_37 ;
int V_35 ;
T_12 * V_79 ;
int V_80 ;
T_2 V_32 ;
T_8 V_40 ;
T_9 V_41 ;
int V_42 = 0 ;
T_10 V_43 [ 3 ] ;
T_11 * V_44 = NULL ,
* V_45 = NULL ,
* V_67 = NULL ;
V_33 = NULL ;
V_31 = F_15 ( & V_6 -> V_8 . V_81 , & V_35 , V_26 ) ;
V_78 . V_46 = F_16 ( V_6 -> V_47 . V_48 ) ;
V_78 . V_49 = F_16 ( V_6 -> V_50 ) ;
V_78 . V_51 = F_8 ( V_6 -> V_47 . V_52 ) ;
V_78 . V_53 = F_8 ( V_6 -> V_47 . V_54 ) ;
V_78 . V_55 = F_16 ( V_6 -> V_47 . V_55 ) ;
V_79 = F_25 ( V_6 -> V_82 , V_6 , V_4 , & V_80 ,
V_31 . V_73 , V_35 ) ;
if ( ! V_79 )
goto V_83;
V_37 = F_17 ( V_6 -> V_8 . V_7 ) ;
V_32 = sizeof( V_78 ) + V_35 + V_80 + V_77 ;
if ( V_6 -> V_84 . V_85 )
V_32 += sizeof( V_58 ) ;
if ( V_6 -> V_84 . V_86 )
V_32 += sizeof( V_61 ) ;
if ( V_6 -> V_84 . V_87 ) {
V_43 [ V_42 ] = V_63 ;
V_43 [ V_42 + 1 ] = V_64 ;
V_42 += 2 ;
}
if ( V_37 -> V_65 )
V_32 += sizeof( V_40 ) ;
if ( V_6 -> V_84 . V_88 ) {
V_67 = ( T_11 * ) V_6 -> V_47 . V_67 ;
V_32 += F_20 ( V_67 -> V_20 ) ;
V_45 = ( T_11 * ) V_6 -> V_47 . V_45 ;
if ( V_45 -> V_20 )
V_32 += F_18 ( F_20 ( V_45 -> V_20 ) ) ;
else
V_45 = NULL ;
V_44 = ( T_11 * ) V_6 -> V_47 . V_44 ;
if ( V_44 -> V_20 )
V_32 += F_18 ( F_20 ( V_44 -> V_20 ) ) ;
else
V_44 = NULL ;
V_43 [ V_42 ] = V_68 ;
V_42 += 1 ;
}
if ( V_42 )
V_32 += F_18 ( sizeof( T_9 ) +
V_42 ) ;
V_33 = F_21 ( V_6 , V_89 , 0 , V_32 ) ;
if ( ! V_33 )
goto V_90;
V_33 -> V_91 = V_4 -> V_91 ;
V_33 -> V_21 . V_71 =
F_9 ( V_33 , sizeof( V_78 ) , & V_78 ) ;
V_33 -> V_72 . V_73 = F_9 ( V_33 , V_35 , V_31 . V_73 ) ;
F_9 ( V_33 , V_80 , V_79 ) ;
if ( V_6 -> V_84 . V_85 )
F_9 ( V_33 , sizeof( V_58 ) , & V_58 ) ;
if ( V_42 ) {
V_41 . V_72 . type = V_75 ;
V_41 . V_72 . V_20 =
F_8 ( sizeof( T_9 ) + V_42 ) ;
F_9 ( V_33 , sizeof( T_9 ) ,
& V_41 ) ;
F_22 ( V_33 , V_42 , V_43 ) ;
}
if ( V_6 -> V_84 . V_86 )
F_9 ( V_33 , sizeof( V_61 ) , & V_61 ) ;
if ( V_37 -> V_65 ) {
V_40 . V_72 . type = V_76 ;
V_40 . V_72 . V_20 = F_8 ( sizeof( V_40 ) ) ;
V_40 . V_65 = F_16 ( V_37 -> V_65 ) ;
F_9 ( V_33 , sizeof( V_40 ) , & V_40 ) ;
}
if ( V_6 -> V_84 . V_88 ) {
F_9 ( V_33 , F_20 ( V_67 -> V_20 ) ,
V_67 ) ;
if ( V_45 )
F_9 ( V_33 , F_20 ( V_45 -> V_20 ) ,
V_45 ) ;
if ( V_44 )
F_9 ( V_33 , F_20 ( V_44 -> V_20 ) ,
V_44 ) ;
}
V_33 -> V_6 = (struct V_5 * ) V_6 ;
V_90:
F_23 ( V_79 ) ;
V_83:
F_23 ( V_31 . V_73 ) ;
return V_33 ;
}
struct V_3 * F_26 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_33 ;
void * V_79 ;
int V_80 ;
V_79 = V_6 -> V_84 . V_79 ;
V_80 = V_6 -> V_84 . V_80 ;
V_33 = F_21 ( V_6 , V_92 , 0 , V_80 ) ;
if ( ! V_33 )
goto V_70;
V_33 -> V_21 . V_93 =
F_9 ( V_33 , V_80 , V_79 ) ;
if ( V_4 )
V_33 -> V_91 = V_4 -> V_91 ;
V_70:
return V_33 ;
}
struct V_3 * F_27 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_33 ;
V_33 = F_21 ( V_6 , V_94 , 0 , 0 ) ;
if ( V_33 && V_4 )
V_33 -> V_91 = V_4 -> V_91 ;
return V_33 ;
}
struct V_3 * F_28 ( const struct V_5 * V_6 ,
const T_13 V_95 ,
const struct V_3 * V_4 )
{
struct V_3 * V_33 ;
T_14 V_96 ;
V_96 . V_95 = F_16 ( V_95 ) ;
V_33 = F_21 ( V_6 , V_97 , 0 ,
sizeof( T_14 ) ) ;
if ( ! V_33 )
goto V_70;
V_33 -> V_21 . V_98 =
F_9 ( V_33 , sizeof( V_96 ) , & V_96 ) ;
if ( V_4 )
V_33 -> V_91 = V_4 -> V_91 ;
V_70:
return V_33 ;
}
struct V_3 * F_29 ( const struct V_5 * V_6 ,
const T_13 V_95 )
{
struct V_3 * V_33 ;
T_15 V_99 ;
V_99 . V_95 = F_16 ( V_95 ) ;
V_33 = F_21 ( V_6 , V_100 , 0 ,
sizeof( T_15 ) ) ;
if ( ! V_33 )
goto V_70;
V_33 -> V_21 . V_101 =
F_9 ( V_33 , sizeof( V_99 ) , & V_99 ) ;
V_70:
return V_33 ;
}
struct V_3 * F_30 ( struct V_5 * V_6 ,
const struct V_102 * V_103 ,
int V_104 , T_10 V_105 , T_4 V_106 )
{
struct V_3 * V_33 ;
struct V_107 V_108 ;
int V_109 ;
V_108 . V_110 = 0 ;
V_108 . V_111 = F_8 ( V_103 -> V_112 ) ;
V_108 . V_113 = V_103 -> V_114 ;
if ( V_103 -> V_115 & V_116 ) {
V_105 |= V_117 ;
V_108 . V_106 = 0 ;
} else
V_108 . V_106 = F_8 ( V_106 ) ;
V_109 = sizeof( V_108 ) + V_104 ;
V_33 = F_31 ( V_6 , V_105 , V_109 ) ;
if ( ! V_33 )
goto V_70;
V_33 -> V_21 . V_118 = F_9 ( V_33 , sizeof( V_108 ) , & V_108 ) ;
memcpy ( & V_33 -> V_103 , V_103 , sizeof( struct V_102 ) ) ;
V_70:
return V_33 ;
}
struct V_3 * F_32 ( const struct V_5 * V_6 )
{
struct V_3 * V_33 ;
struct V_119 V_120 ;
int V_18 ;
T_13 V_121 ;
T_4 V_122 , V_123 ;
struct V_5 * V_124 = (struct V_5 * ) V_6 ;
struct V_125 * V_126 = (struct V_125 * ) & V_6 -> V_84 . V_127 ;
struct V_128 V_129 [ V_130 ] ;
struct V_131 * V_132 ;
memset ( V_129 , 0 , sizeof( V_129 ) ) ;
V_121 = F_33 ( V_126 ) ;
F_34 ( L_1 , V_133 , V_121 ) ;
V_122 = F_35 ( V_126 , V_129 ) ;
V_123 = F_36 ( V_126 ) ;
V_120 . V_134 = F_16 ( V_121 ) ;
V_120 . V_49 = F_16 ( V_6 -> V_49 ) ;
V_120 . V_135 = F_8 ( V_122 ) ;
V_120 . V_123 = F_8 ( V_123 ) ;
V_18 = sizeof( V_120 )
+ sizeof( struct V_128 ) * V_122
+ sizeof( T_13 ) * V_123 ;
V_33 = F_21 ( V_6 , V_136 , 0 , V_18 ) ;
if ( ! V_33 )
goto V_70;
V_33 -> V_91 = V_6 -> V_84 . V_137 ;
V_33 -> V_21 . V_138 =
F_9 ( V_33 , sizeof( V_120 ) , & V_120 ) ;
if ( V_122 )
F_9 ( V_33 , sizeof( T_13 ) * V_122 ,
V_129 ) ;
if ( V_123 ) {
V_124 -> V_139 . V_140 += V_123 ;
F_9 ( V_33 , sizeof( T_13 ) * V_123 ,
F_37 ( V_126 ) ) ;
}
if ( ++ V_124 -> V_84 . V_141 == 0 ) {
F_38 (trans, &asoc->peer.transport_addr_list,
transports)
V_132 -> V_141 = 0 ;
V_124 -> V_84 . V_141 = 1 ;
}
V_70:
return V_33 ;
}
struct V_3 * F_39 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_33 ;
T_16 V_142 ;
T_13 V_121 ;
V_121 = F_33 ( & V_6 -> V_84 . V_127 ) ;
V_142 . V_134 = F_16 ( V_121 ) ;
V_33 = F_21 ( V_6 , V_143 , 0 ,
sizeof( T_16 ) ) ;
if ( ! V_33 )
goto V_70;
V_33 -> V_21 . V_144 =
F_9 ( V_33 , sizeof( V_142 ) , & V_142 ) ;
if ( V_4 )
V_33 -> V_91 = V_4 -> V_91 ;
V_70:
return V_33 ;
}
struct V_3 * F_40 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_33 ;
V_33 = F_21 ( V_6 , V_145 , 0 , 0 ) ;
if ( V_33 && V_4 )
V_33 -> V_91 = V_4 -> V_91 ;
return V_33 ;
}
struct V_3 * F_41 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_33 ;
T_10 V_105 = 0 ;
V_105 |= V_6 ? 0 : V_146 ;
V_33 = F_21 ( V_6 , V_147 , V_105 , 0 ) ;
if ( V_33 && V_4 )
V_33 -> V_91 = V_4 -> V_91 ;
return V_33 ;
}
struct V_3 * F_42 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
const T_2 V_148 )
{
struct V_3 * V_33 ;
T_10 V_105 = 0 ;
if ( ! V_6 ) {
if ( V_4 && V_4 -> V_149 &&
V_4 -> V_149 -> type == V_69 )
V_105 = 0 ;
else
V_105 = V_146 ;
}
V_33 = F_21 ( V_6 , V_150 , V_105 , V_148 ) ;
if ( V_33 && V_4 )
V_33 -> V_91 = V_4 -> V_91 ;
return V_33 ;
}
struct V_3 * F_43 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 , T_13 V_110 )
{
struct V_3 * V_33 ;
T_17 V_151 ;
V_33 = F_42 ( V_6 , V_4 , sizeof( T_3 )
+ sizeof( V_110 ) ) ;
if ( ! V_33 )
goto V_152;
V_151 = F_16 ( V_110 ) ;
F_7 ( V_33 , V_153 , sizeof( V_151 ) ) ;
F_9 ( V_33 , sizeof( V_151 ) , ( const void * ) & V_151 ) ;
if ( V_4 )
V_33 -> V_91 = V_4 -> V_91 ;
V_152:
return V_33 ;
}
struct V_3 * F_44 ( const struct V_5 * V_6 ,
const struct V_154 * V_155 ,
T_2 V_16 )
{
struct V_3 * V_33 ;
void * V_151 = NULL ;
int V_17 ;
V_33 = F_42 ( V_6 , NULL , sizeof( T_3 ) + V_16 ) ;
if ( ! V_33 )
goto V_156;
if ( V_16 ) {
V_151 = F_45 ( V_16 , V_157 ) ;
if ( ! V_151 )
goto V_158;
V_17 = F_46 ( V_151 , V_155 -> V_159 , V_16 ) ;
if ( V_17 < 0 )
goto V_160;
}
F_7 ( V_33 , V_161 , V_16 ) ;
F_9 ( V_33 , V_16 , V_151 ) ;
if ( V_16 )
F_23 ( V_151 ) ;
return V_33 ;
V_160:
F_23 ( V_151 ) ;
V_158:
F_47 ( V_33 ) ;
V_33 = NULL ;
V_156:
return V_33 ;
}
static void * F_22 ( struct V_3 * V_4 , int V_18 ,
const void * V_162 )
{
void * V_163 ;
int V_164 = F_20 ( V_4 -> V_149 -> V_20 ) ;
V_163 = F_48 ( V_4 -> V_2 , V_18 ) ;
if ( V_162 )
memcpy ( V_163 , V_162 , V_18 ) ;
else
memset ( V_163 , 0 , V_18 ) ;
V_4 -> V_149 -> V_20 = F_8 ( V_164 + V_18 ) ;
V_4 -> V_165 = F_49 ( V_4 -> V_2 ) ;
return V_163 ;
}
struct V_3 * F_50 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
const T_10 * V_151 ,
const T_2 V_16 )
{
struct V_3 * V_33 ;
struct V_166 V_167 ;
V_33 = F_42 ( V_6 , V_4 , sizeof( T_3 ) + V_16
+ sizeof( T_11 ) ) ;
if ( ! V_33 )
goto V_168;
F_7 ( V_33 , V_169 , V_16
+ sizeof( T_11 ) ) ;
V_167 . type = F_8 ( V_4 -> V_149 -> type ) ;
V_167 . V_20 = V_4 -> V_149 -> V_20 ;
F_9 ( V_33 , V_16 , V_151 ) ;
F_22 ( V_33 , sizeof( T_11 ) , & V_167 ) ;
V_168:
return V_33 ;
}
struct V_3 * F_51 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
struct V_166 * V_170 )
{
struct V_3 * V_33 ;
static const char error [] = L_2 ;
T_2 V_171 = sizeof( error ) + sizeof( T_3 ) +
sizeof( T_11 ) ;
V_33 = F_42 ( V_6 , V_4 , V_171 ) ;
if ( ! V_33 )
goto V_70;
F_7 ( V_33 , V_169 ,
sizeof( error ) + sizeof( T_11 ) ) ;
F_9 ( V_33 , sizeof( error ) , error ) ;
F_22 ( V_33 , sizeof( T_11 ) , V_170 ) ;
V_70:
return V_33 ;
}
struct V_3 * F_52 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_33 ;
static const char error [] = L_3 ;
T_2 V_171 = sizeof( error ) + sizeof( T_3 ) ;
V_33 = F_42 ( V_6 , V_4 , V_171 ) ;
if ( ! V_33 )
goto V_70;
F_7 ( V_33 , V_169 , sizeof( error ) ) ;
F_9 ( V_33 , sizeof( error ) , error ) ;
V_70:
return V_33 ;
}
struct V_3 * F_53 ( const struct V_5 * V_6 ,
const struct V_131 * V_91 )
{
struct V_3 * V_33 ;
T_18 V_172 ;
V_33 = F_21 ( V_6 , V_173 , 0 , sizeof( V_172 ) ) ;
if ( ! V_33 )
goto V_70;
V_172 . V_72 . type = V_174 ;
V_172 . V_72 . V_20 = F_8 ( sizeof( T_18 ) ) ;
V_172 . V_175 = V_91 -> V_176 ;
V_172 . V_177 = V_178 ;
V_172 . V_179 = V_91 -> V_179 ;
V_33 -> V_91 = (struct V_131 * ) V_91 ;
V_33 -> V_21 . V_180 = F_9 ( V_33 , sizeof( V_172 ) ,
& V_172 ) ;
V_70:
return V_33 ;
}
struct V_3 * F_54 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
const void * V_151 , const T_2 V_16 )
{
struct V_3 * V_33 ;
V_33 = F_21 ( V_6 , V_181 , 0 , V_16 ) ;
if ( ! V_33 )
goto V_70;
V_33 -> V_21 . V_180 = F_9 ( V_33 , V_16 , V_151 ) ;
if ( V_4 )
V_33 -> V_91 = V_4 -> V_91 ;
V_70:
return V_33 ;
}
static struct V_3 * F_55 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
T_2 V_182 )
{
struct V_3 * V_33 ;
V_33 = F_21 ( V_6 , V_183 , 0 ,
sizeof( T_3 ) + V_182 ) ;
if ( ! V_33 )
goto V_70;
if ( V_4 )
V_33 -> V_91 = V_4 -> V_91 ;
V_70:
return V_33 ;
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
T_1 V_15 , const void * V_151 ,
T_2 V_16 , T_2 V_186 )
{
struct V_3 * V_33 ;
V_33 = F_55 ( V_6 , V_4 , V_16 + V_186 ) ;
if ( ! V_33 )
goto V_70;
F_7 ( V_33 , V_15 , V_16 + V_186 ) ;
F_9 ( V_33 , V_16 , V_151 ) ;
if ( V_186 )
F_22 ( V_33 , V_186 , NULL ) ;
V_70:
return V_33 ;
}
struct V_3 * F_58 ( const struct V_5 * V_6 )
{
struct V_3 * V_33 ;
struct V_187 * V_188 ;
struct V_189 V_190 ;
T_10 * V_191 ;
V_188 = F_59 ( V_6 ) ;
if ( F_60 ( ! V_188 ) )
return NULL ;
V_33 = F_21 ( V_6 , V_68 , 0 ,
V_188 -> V_192 + sizeof( V_193 ) ) ;
if ( ! V_33 )
return NULL ;
V_190 . V_194 = F_8 ( V_188 -> V_194 ) ;
V_190 . V_195 = F_8 ( V_6 -> V_196 ) ;
V_33 -> V_21 . V_190 = F_9 ( V_33 , sizeof( V_193 ) ,
& V_190 ) ;
V_191 = F_48 ( V_33 -> V_2 , V_188 -> V_192 ) ;
memset ( V_191 , 0 , V_188 -> V_192 ) ;
V_33 -> V_149 -> V_20 =
F_8 ( F_20 ( V_33 -> V_149 -> V_20 ) + V_188 -> V_192 ) ;
V_33 -> V_165 = F_49 ( V_33 -> V_2 ) ;
return V_33 ;
}
struct V_3 * F_61 ( struct V_1 * V_2 ,
const struct V_5 * V_6 ,
struct V_197 * V_7 )
{
struct V_3 * V_33 ;
V_33 = F_62 ( V_198 , V_199 ) ;
if ( ! V_33 )
goto V_70;
if ( ! V_7 )
F_34 ( L_4 , V_133 , V_2 ) ;
F_63 ( & V_33 -> V_200 ) ;
V_33 -> V_2 = V_2 ;
V_33 -> V_6 = (struct V_5 * ) V_6 ;
V_33 -> V_201 = 0 ;
V_33 -> V_202 = 0 ;
V_33 -> V_203 = 0 ;
V_33 -> V_177 = 0 ;
V_33 -> V_204 = 1 ;
V_33 -> V_205 = 0 ;
V_33 -> V_206 = 0 ;
V_33 -> V_207 = 0 ;
V_33 -> V_208 = 0 ;
V_33 -> V_209 = 0 ;
V_33 -> V_210 = V_211 ;
V_33 -> V_155 = NULL ;
F_63 ( & V_33 -> V_212 ) ;
F_63 ( & V_33 -> V_213 ) ;
F_64 ( V_4 ) ;
F_65 ( & V_33 -> V_214 , 1 ) ;
V_70:
return V_33 ;
}
void F_66 ( struct V_3 * V_4 , union V_215 * V_216 ,
union V_215 * V_217 )
{
memcpy ( & V_4 -> V_218 , V_216 , sizeof( union V_215 ) ) ;
memcpy ( & V_4 -> V_217 , V_217 , sizeof( union V_215 ) ) ;
}
const union V_215 * F_67 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_91 ) {
return & V_4 -> V_91 -> V_176 ;
} else {
return & V_4 -> V_218 ;
}
}
static struct V_3 * F_68 ( const struct V_5 * V_6 ,
T_10 type , T_10 V_105 , int V_16 )
{
struct V_3 * V_33 ;
T_19 * V_149 ;
struct V_1 * V_2 ;
struct V_197 * V_7 ;
V_2 = F_69 ( F_18 ( sizeof( T_19 ) + V_16 ) ,
V_199 ) ;
if ( ! V_2 )
goto V_70;
V_149 = ( T_19 * ) F_48 ( V_2 , sizeof( T_19 ) ) ;
V_149 -> type = type ;
V_149 -> V_105 = V_105 ;
V_149 -> V_20 = F_8 ( sizeof( T_19 ) ) ;
V_7 = V_6 ? V_6 -> V_8 . V_7 : NULL ;
V_33 = F_61 ( V_2 , V_6 , V_7 ) ;
if ( ! V_33 ) {
F_70 ( V_2 ) ;
goto V_70;
}
V_33 -> V_149 = V_149 ;
V_33 -> V_165 = ( ( T_10 * ) V_149 ) + sizeof( struct V_219 ) ;
if ( F_71 ( type , V_6 ) )
V_33 -> V_220 = 1 ;
return V_33 ;
V_70:
return NULL ;
}
static struct V_3 * F_31 ( const struct V_5 * V_6 ,
T_10 V_105 , int V_16 )
{
return F_68 ( V_6 , V_221 , V_105 , V_16 ) ;
}
static struct V_3 * F_21 ( const struct V_5 * V_6 ,
T_10 type , T_10 V_105 , int V_16 )
{
struct V_3 * V_4 = F_68 ( V_6 , type , V_105 , V_16 ) ;
if ( V_4 )
F_2 ( V_4 ) ;
return V_4 ;
}
static void F_72 ( struct V_3 * V_4 )
{
F_73 ( ! F_74 ( & V_4 -> V_200 ) ) ;
F_75 ( & V_4 -> V_212 ) ;
F_76 ( V_4 -> V_2 ) ;
F_77 ( V_4 ) ;
F_78 ( V_198 , V_4 ) ;
}
void F_47 ( struct V_3 * V_4 )
{
if ( V_4 -> V_155 )
F_79 ( V_4 -> V_155 ) ;
F_80 ( V_4 ) ;
}
void F_81 ( struct V_3 * V_222 )
{
F_82 ( & V_222 -> V_214 ) ;
}
void F_80 ( struct V_3 * V_222 )
{
if ( F_83 ( & V_222 -> V_214 ) )
F_72 ( V_222 ) ;
}
void * F_9 ( struct V_3 * V_4 , int V_18 , const void * V_162 )
{
void * V_163 ;
void * V_223 ;
int V_164 = F_20 ( V_4 -> V_149 -> V_20 ) ;
int V_224 = F_18 ( V_164 ) - V_164 ;
V_223 = F_48 ( V_4 -> V_2 , V_224 ) ;
V_163 = F_48 ( V_4 -> V_2 , V_18 ) ;
memset ( V_223 , 0 , V_224 ) ;
memcpy ( V_163 , V_162 , V_18 ) ;
V_4 -> V_149 -> V_20 = F_8 ( V_164 + V_224 + V_18 ) ;
V_4 -> V_165 = F_49 ( V_4 -> V_2 ) ;
return V_163 ;
}
void * F_12 ( struct V_3 * V_4 ,
int V_18 , const void * V_162 )
{
if ( F_11 ( V_4 -> V_2 ) >= V_18 )
return F_9 ( V_4 , V_18 , V_162 ) ;
else
return NULL ;
}
int F_84 ( struct V_3 * V_4 , int V_225 , int V_18 ,
struct V_226 * V_162 )
{
T_10 * V_163 ;
int V_17 = 0 ;
V_163 = F_48 ( V_4 -> V_2 , V_18 ) ;
if ( ( V_17 = F_85 ( V_163 , V_162 , V_225 , V_18 ) ) )
goto V_227;
V_4 -> V_149 -> V_20 =
F_8 ( F_20 ( V_4 -> V_149 -> V_20 ) + V_18 ) ;
V_4 -> V_165 = F_49 ( V_4 -> V_2 ) ;
V_227:
return V_17 ;
}
void F_86 ( struct V_3 * V_4 )
{
struct V_228 * V_155 ;
struct V_3 * V_229 ;
struct V_230 * V_111 ;
T_4 V_106 ;
T_4 V_231 ;
if ( V_4 -> V_202 )
return;
V_231 = F_20 ( V_4 -> V_21 . V_118 -> V_111 ) ;
V_111 = & V_4 -> V_6 -> V_232 -> V_227 ;
V_155 = V_4 -> V_155 ;
F_38 (lchunk, &msg->chunks, frag_list) {
if ( V_229 -> V_149 -> V_105 & V_117 ) {
V_106 = 0 ;
} else {
if ( V_229 -> V_149 -> V_105 & V_233 )
V_106 = F_87 ( V_111 , V_231 ) ;
else
V_106 = F_88 ( V_111 , V_231 ) ;
}
V_229 -> V_21 . V_118 -> V_106 = F_8 ( V_106 ) ;
V_229 -> V_202 = 1 ;
}
}
void F_89 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_201 ) {
V_4 -> V_21 . V_118 -> V_110 =
F_16 ( F_90 ( V_4 -> V_6 ) ) ;
V_4 -> V_201 = 1 ;
}
}
struct V_5 * F_91 ( const struct V_234 * V_82 ,
struct V_3 * V_4 ,
T_5 V_26 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
T_20 V_235 ;
struct V_10 * V_11 ;
V_235 = F_92 ( F_67 ( V_4 ) ) ;
V_6 = F_93 ( V_82 , V_82 -> V_8 . V_7 , V_235 , V_26 ) ;
if ( ! V_6 )
goto V_70;
V_6 -> V_236 = 1 ;
V_2 = V_4 -> V_2 ;
V_11 = F_4 ( F_5 ( F_6 ( V_2 ) -> V_13 ) ) ;
if ( F_60 ( ! V_11 ) )
goto V_237;
V_11 -> V_238 ( & V_6 -> V_47 . V_239 , V_2 , 1 ) ;
V_70:
return V_6 ;
V_237:
F_94 ( V_6 ) ;
return NULL ;
}
static T_12 * F_25 ( const struct V_234 * V_82 ,
const struct V_5 * V_6 ,
const struct V_3 * V_240 ,
int * V_80 ,
const T_10 * V_241 , int V_35 )
{
T_12 * V_33 ;
struct V_242 * V_79 ;
struct V_243 V_244 ;
int V_245 , V_246 ;
V_245 = sizeof( T_11 ) +
( sizeof( struct V_242 ) -
sizeof( struct V_247 ) ) ;
V_246 = sizeof( struct V_247 )
+ F_20 ( V_240 -> V_149 -> V_20 ) + V_35 ;
if ( V_246 % V_248 )
V_246 += V_248
- ( V_246 % V_248 ) ;
* V_80 = V_245 + V_246 ;
V_33 = F_95 ( * V_80 , V_199 ) ;
if ( ! V_33 )
goto V_70;
V_79 = (struct V_242 * ) V_33 -> V_249 ;
V_33 -> V_250 . type = V_251 ;
V_33 -> V_250 . V_20 = F_8 ( * V_80 ) ;
V_79 -> V_47 = V_6 -> V_47 ;
V_79 -> V_47 . V_252 = V_35 ;
V_79 -> V_47 . V_86 = V_6 -> V_84 . V_86 ;
V_79 -> V_47 . V_65 = V_6 -> V_84 . V_65 ;
V_79 -> V_47 . V_253 = F_96 ( V_6 -> V_254 ,
F_97 () ) ;
memcpy ( & V_79 -> V_47 . V_255 [ 0 ] , V_240 -> V_149 ,
F_20 ( V_240 -> V_149 -> V_20 ) ) ;
memcpy ( ( T_10 * ) & V_79 -> V_47 . V_255 [ 0 ] +
F_20 ( V_240 -> V_149 -> V_20 ) , V_241 , V_35 ) ;
if ( F_17 ( V_82 -> V_8 . V_7 ) -> V_191 ) {
struct V_256 V_257 ;
F_98 ( & V_244 , & V_79 -> V_47 , V_246 ) ;
V_257 . V_258 = F_17 ( V_82 -> V_8 . V_7 ) -> V_191 ;
V_257 . V_105 = 0 ;
if ( F_99 ( V_257 . V_258 , V_82 -> V_259 ,
sizeof( V_82 -> V_259 ) ) ||
F_100 ( & V_257 , & V_244 , V_246 , V_79 -> V_260 ) )
goto V_261;
}
return V_33 ;
V_261:
F_23 ( V_33 ) ;
V_70:
* V_80 = 0 ;
return NULL ;
}
struct V_5 * F_101 (
const struct V_234 * V_82 ,
const struct V_5 * V_6 ,
struct V_3 * V_4 , T_5 V_26 ,
int * error , struct V_3 * * V_262 )
{
struct V_5 * V_33 = NULL ;
struct V_242 * V_79 ;
struct V_247 * V_263 ;
int V_245 , V_246 , V_264 ;
T_10 * V_265 = V_82 -> V_265 ;
struct V_243 V_244 ;
unsigned int V_18 ;
T_20 V_235 ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_21 V_266 ;
struct V_256 V_257 ;
V_245 = sizeof( T_19 ) +
( sizeof( struct V_242 ) -
sizeof( struct V_247 ) ) ;
V_246 = F_20 ( V_4 -> V_149 -> V_20 ) - V_245 ;
V_264 = V_245 + sizeof( struct V_247 ) ;
V_18 = F_20 ( V_4 -> V_149 -> V_20 ) ;
if ( V_18 < V_264 + sizeof( struct V_219 ) )
goto V_267;
if ( V_246 % V_248 )
goto V_267;
V_79 = V_4 -> V_21 . V_93 ;
V_263 = & V_79 -> V_47 ;
if ( ! F_17 ( V_82 -> V_8 . V_7 ) -> V_191 )
goto V_268;
F_98 ( & V_244 , V_263 , V_246 ) ;
V_257 . V_258 = F_17 ( V_82 -> V_8 . V_7 ) -> V_191 ;
V_257 . V_105 = 0 ;
memset ( V_265 , 0x00 , V_269 ) ;
if ( F_99 ( V_257 . V_258 , V_82 -> V_259 ,
sizeof( V_82 -> V_259 ) ) ||
F_100 ( & V_257 , & V_244 , V_246 , V_265 ) ) {
* error = - V_270 ;
goto V_237;
}
if ( memcmp ( V_265 , V_79 -> V_260 , V_269 ) ) {
* error = - V_271 ;
goto V_237;
}
V_268:
if ( F_102 ( V_4 -> V_272 -> V_273 ) != V_263 -> V_48 ) {
* error = - V_274 ;
goto V_237;
}
if ( V_4 -> V_272 -> V_218 != V_263 -> V_239 . V_275 . V_276 ||
F_20 ( V_4 -> V_272 -> V_217 ) != V_263 -> V_277 ) {
* error = - V_278 ;
goto V_237;
}
if ( F_103 ( V_82 -> V_8 . V_7 , V_279 ) )
V_266 = F_104 ( V_2 ) ;
else
V_266 = F_97 () ;
if ( ! V_6 && F_105 ( V_263 -> V_253 , V_266 ) < 0 ) {
V_18 = F_20 ( V_4 -> V_149 -> V_20 ) ;
* V_262 = F_55 ( V_6 , V_4 , V_18 ) ;
if ( * V_262 ) {
T_22 V_280 = F_106 ( F_107 ( V_266 , V_263 -> V_253 ) ) ;
T_17 V_281 = F_16 ( V_280 ) ;
F_7 ( * V_262 , V_282 ,
sizeof( V_281 ) ) ;
F_9 ( * V_262 , sizeof( V_281 ) , & V_281 ) ;
* error = - V_283 ;
} else
* error = - V_270 ;
goto V_237;
}
V_235 = F_92 ( F_67 ( V_4 ) ) ;
V_33 = F_93 ( V_82 , V_82 -> V_8 . V_7 , V_235 , V_26 ) ;
if ( ! V_33 ) {
* error = - V_270 ;
goto V_237;
}
V_33 -> V_84 . V_284 = F_20 ( V_4 -> V_272 -> V_218 ) ;
memcpy ( & V_33 -> V_47 , V_263 , sizeof( * V_263 ) ) ;
if ( F_108 ( V_33 , V_263 ,
V_199 ) < 0 ) {
* error = - V_270 ;
goto V_237;
}
if ( F_74 ( & V_33 -> V_8 . V_81 . V_285 ) ) {
F_109 ( & V_33 -> V_8 . V_81 , & V_4 -> V_217 ,
V_286 , V_199 ) ;
}
V_33 -> V_287 = V_33 -> V_47 . V_55 ;
V_33 -> V_288 = V_33 -> V_287 - 1 ;
V_33 -> V_289 = V_33 -> V_47 . V_55 ;
V_33 -> V_290 = V_33 -> V_288 ;
V_33 -> V_84 . V_86 = V_33 -> V_47 . V_86 ;
V_33 -> V_84 . V_65 = V_33 -> V_47 . V_65 ;
return V_33 ;
V_237:
if ( V_33 )
F_94 ( V_33 ) ;
return NULL ;
V_267:
* error = - V_291 ;
goto V_237;
}
static int F_110 ( const struct V_5 * V_6 ,
T_23 V_292 ,
struct V_3 * V_4 ,
struct V_3 * * V_262 )
{
struct V_293 V_294 ;
T_4 V_18 ;
V_18 = F_18 ( sizeof( V_294 ) ) ;
if ( ! * V_262 )
* V_262 = F_55 ( V_6 , V_4 , V_18 ) ;
if ( * V_262 ) {
V_294 . V_295 = F_16 ( 1 ) ;
V_294 . type = V_292 ;
F_7 ( * V_262 , V_296 ,
sizeof( V_294 ) ) ;
F_9 ( * V_262 , sizeof( V_294 ) , & V_294 ) ;
}
return 0 ;
}
static int F_111 ( const struct V_5 * V_6 ,
struct V_3 * V_4 ,
struct V_3 * * V_262 )
{
if ( ! * V_262 )
* V_262 = F_55 ( V_6 , V_4 , 0 ) ;
if ( * V_262 )
F_7 ( * V_262 , V_297 , 0 ) ;
return 0 ;
}
static int F_112 ( const struct V_5 * V_6 ,
struct V_166 * V_170 ,
const struct V_3 * V_4 ,
struct V_3 * * V_262 )
{
if ( * V_262 )
F_47 ( * V_262 ) ;
* V_262 = F_51 ( V_6 , V_4 , V_170 ) ;
return 0 ;
}
static int F_113 ( const struct V_5 * V_6 ,
union V_30 V_170 ,
struct V_3 * V_4 ,
struct V_3 * * V_262 )
{
T_4 V_18 = F_20 ( V_170 . V_250 -> V_20 ) ;
if ( * V_262 )
F_47 ( * V_262 ) ;
* V_262 = F_55 ( V_6 , V_4 , V_18 ) ;
if ( * V_262 ) {
F_7 ( * V_262 , V_298 , V_18 ) ;
F_9 ( * V_262 , V_18 , V_170 . V_73 ) ;
}
return 0 ;
}
static int F_114 ( struct V_28 * V_28 , union V_30 V_170 )
{
T_4 V_42 = F_20 ( V_170 . V_250 -> V_20 ) - sizeof( T_11 ) ;
int V_299 = 0 ;
int V_300 = 0 ;
int V_301 ;
for ( V_301 = 0 ; V_301 < V_42 ; V_301 ++ ) {
switch ( V_170 . V_302 -> V_303 [ V_301 ] ) {
case V_68 :
V_299 = 1 ;
break;
case V_63 :
case V_64 :
V_300 = 1 ;
break;
}
}
if ( V_28 -> V_59 . V_304 )
return 1 ;
if ( V_28 -> V_59 . V_62 && ! V_299 && V_300 )
return 0 ;
return 1 ;
}
static void F_115 ( struct V_5 * V_6 ,
union V_30 V_170 )
{
struct V_28 * V_28 = F_14 ( V_6 -> V_8 . V_7 ) ;
T_4 V_42 = F_20 ( V_170 . V_250 -> V_20 ) - sizeof( T_11 ) ;
int V_301 ;
for ( V_301 = 0 ; V_301 < V_42 ; V_301 ++ ) {
switch ( V_170 . V_302 -> V_303 [ V_301 ] ) {
case V_305 :
if ( V_28 -> V_59 . V_60 &&
! V_6 -> V_84 . V_86 )
V_6 -> V_84 . V_86 = 1 ;
break;
case V_68 :
if ( V_28 -> V_59 . V_66 )
V_6 -> V_84 . V_88 = 1 ;
break;
case V_63 :
case V_64 :
if ( V_28 -> V_59 . V_62 )
V_6 -> V_84 . V_87 = 1 ;
break;
default:
break;
}
}
}
static T_24 F_116 ( const struct V_5 * V_6 ,
union V_30 V_170 ,
struct V_3 * V_4 ,
struct V_3 * * V_262 )
{
int V_33 = V_306 ;
switch ( V_170 . V_250 -> type & V_307 ) {
case V_308 :
V_33 = V_309 ;
break;
case V_310 :
break;
case V_311 :
V_33 = V_309 ;
case V_312 :
if ( NULL == * V_262 )
* V_262 = F_56 ( V_6 , V_4 ) ;
if ( * V_262 ) {
if ( ! F_10 ( * V_262 , V_313 ,
F_18 ( F_20 ( V_170 . V_250 -> V_20 ) ) ) )
F_12 ( * V_262 ,
F_18 ( F_20 ( V_170 . V_250 -> V_20 ) ) ,
V_170 . V_73 ) ;
} else {
V_33 = V_270 ;
}
break;
default:
break;
}
return V_33 ;
}
static T_24 F_117 ( struct V_28 * V_28 ,
const struct V_5 * V_6 ,
union V_30 V_170 ,
T_25 V_314 ,
struct V_3 * V_4 ,
struct V_3 * * V_156 )
{
struct V_315 * V_316 ;
int V_33 = V_306 ;
T_4 V_317 , V_318 = 0 ;
int V_301 ;
switch ( V_170 . V_250 -> type ) {
case V_319 :
case V_320 :
case V_321 :
case V_74 :
case V_251 :
case V_174 :
case V_322 :
case V_323 :
case V_76 :
break;
case V_75 :
if ( ! F_114 ( V_28 , V_170 ) )
return V_324 ;
break;
case V_325 :
if ( V_28 -> V_59 . V_62 )
break;
goto V_326;
case V_327 :
F_113 ( V_6 , V_170 , V_4 , V_156 ) ;
V_33 = V_324 ;
break;
case V_328 :
if ( V_28 -> V_59 . V_60 )
break;
goto V_326;
case V_329 :
if ( ! V_28 -> V_59 . V_66 )
goto V_326;
if ( V_330 !=
F_20 ( V_170 . V_250 -> V_20 ) - sizeof( T_11 ) ) {
F_112 ( V_6 , V_170 . V_250 ,
V_4 , V_156 ) ;
V_33 = V_324 ;
}
break;
case V_331 :
if ( ! V_28 -> V_59 . V_66 )
goto V_326;
if ( 260 < F_20 ( V_170 . V_250 -> V_20 ) ) {
F_112 ( V_6 , V_170 . V_250 ,
V_4 , V_156 ) ;
V_33 = V_324 ;
}
break;
case V_332 :
if ( ! V_28 -> V_59 . V_66 )
goto V_326;
V_316 = (struct V_315 * ) V_170 . V_250 ;
V_317 = ( F_20 ( V_170 . V_250 -> V_20 ) - sizeof( T_11 ) ) >> 1 ;
for ( V_301 = 0 ; V_301 < V_317 ; V_301 ++ ) {
V_318 = F_20 ( V_316 -> V_333 [ V_301 ] ) ;
if ( V_318 == V_334 )
break;
}
if ( V_318 != V_334 ) {
F_112 ( V_6 , V_170 . V_250 , V_4 ,
V_156 ) ;
V_33 = V_324 ;
}
break;
V_326:
default:
F_34 ( L_5 ,
V_133 , F_20 ( V_170 . V_250 -> type ) , V_314 ) ;
V_33 = F_116 ( V_6 , V_170 , V_4 , V_156 ) ;
break;
}
return V_33 ;
}
int F_118 ( struct V_28 * V_28 , const struct V_5 * V_6 ,
T_25 V_314 ,
T_26 * V_255 ,
struct V_3 * V_4 ,
struct V_3 * * V_262 )
{
union V_30 V_170 ;
bool V_335 = false ;
int V_336 ;
if ( V_255 -> V_71 . V_51 == 0 ||
V_255 -> V_71 . V_53 == 0 ||
V_255 -> V_71 . V_46 == 0 ||
F_102 ( V_255 -> V_71 . V_49 ) < V_337 )
return F_111 ( V_6 , V_4 , V_262 ) ;
F_119 (param, peer_init, init_hdr.params) {
if ( V_170 . V_250 -> type == V_251 )
V_335 = true ;
}
if ( V_170 . V_73 != ( void * ) V_4 -> V_165 )
return F_112 ( V_6 , V_170 . V_250 , V_4 , V_262 ) ;
if ( ( V_89 == V_314 ) && ! V_335 )
return F_110 ( V_6 , V_251 ,
V_4 , V_262 ) ;
F_119 (param, peer_init, init_hdr.params) {
V_336 = F_117 ( V_28 , V_6 , V_170 , V_314 , V_4 , V_262 ) ;
switch ( V_336 ) {
case V_324 :
case V_270 :
return 0 ;
case V_309 :
return 1 ;
case V_306 :
default:
break;
}
}
return 1 ;
}
int F_120 ( struct V_5 * V_6 , struct V_3 * V_4 ,
const union V_215 * V_239 ,
T_26 * V_255 , T_5 V_26 )
{
struct V_28 * V_28 = F_14 ( V_6 -> V_8 . V_7 ) ;
union V_30 V_170 ;
struct V_131 * V_91 ;
struct V_338 * V_339 , * V_236 ;
struct V_10 * V_11 ;
union V_215 V_340 ;
char * V_79 ;
int V_341 = 0 ;
if( ! F_121 ( V_6 , V_239 , V_26 , V_342 ) )
goto V_343;
if ( F_122 ( F_67 ( V_4 ) , V_239 ) )
V_341 = 1 ;
F_119 (param, peer_init, init_hdr.params) {
if ( ! V_341 && ( V_170 . V_250 -> type == V_319 ||
V_170 . V_250 -> type == V_320 ) ) {
V_11 = F_4 ( F_123 ( V_170 . V_250 -> type ) ) ;
V_11 -> V_344 ( & V_340 , V_170 . V_340 ,
V_4 -> V_272 -> V_218 , 0 ) ;
if ( F_122 ( F_67 ( V_4 ) , & V_340 ) )
V_341 = 1 ;
}
if ( ! F_124 ( V_6 , V_170 , V_239 , V_26 ) )
goto V_345;
}
if ( ! V_341 )
goto V_345;
if ( V_6 -> V_84 . V_88 && ( ! V_6 -> V_84 . V_346 ||
! V_6 -> V_84 . V_347 ) )
V_6 -> V_84 . V_88 = 0 ;
if ( ! V_28 -> V_59 . V_304 &&
( V_6 -> V_84 . V_87 && ! V_6 -> V_84 . V_88 ) ) {
V_6 -> V_84 . V_348 |= ( V_349 |
V_350 |
V_325 ) ;
V_6 -> V_84 . V_87 = 0 ;
goto V_345;
}
F_125 (pos, temp, &asoc->peer.transport_addr_list) {
V_91 = F_126 ( V_339 , struct V_131 , V_351 ) ;
if ( V_91 -> V_352 == V_353 ) {
F_127 ( V_6 , V_91 ) ;
}
}
V_6 -> V_84 . V_301 . V_46 =
F_102 ( V_255 -> V_71 . V_46 ) ;
V_6 -> V_84 . V_301 . V_49 =
F_102 ( V_255 -> V_71 . V_49 ) ;
V_6 -> V_84 . V_301 . V_51 =
F_20 ( V_255 -> V_71 . V_51 ) ;
V_6 -> V_84 . V_301 . V_53 =
F_20 ( V_255 -> V_71 . V_53 ) ;
V_6 -> V_84 . V_301 . V_55 =
F_102 ( V_255 -> V_71 . V_55 ) ;
if ( V_6 -> V_47 . V_52 >
F_20 ( V_255 -> V_71 . V_53 ) ) {
V_6 -> V_47 . V_52 =
F_20 ( V_255 -> V_71 . V_53 ) ;
}
if ( V_6 -> V_47 . V_54 >
F_20 ( V_255 -> V_71 . V_51 ) ) {
V_6 -> V_47 . V_54 =
F_20 ( V_255 -> V_71 . V_51 ) ;
}
V_6 -> V_47 . V_354 = V_6 -> V_84 . V_301 . V_46 ;
V_6 -> V_84 . V_50 = V_6 -> V_84 . V_301 . V_49 ;
V_79 = V_6 -> V_84 . V_79 ;
if ( V_79 ) {
V_6 -> V_84 . V_79 = F_128 ( V_79 , V_6 -> V_84 . V_80 , V_26 ) ;
if ( ! V_6 -> V_84 . V_79 )
goto V_345;
}
F_38 (transport, &asoc->peer.transport_addr_list,
transports) {
V_91 -> V_355 = V_6 -> V_84 . V_301 . V_49 ;
}
if ( ! F_129 ( & V_6 -> V_84 . V_127 , V_356 ,
V_6 -> V_84 . V_301 . V_55 , V_26 ) )
goto V_345;
if ( ! V_6 -> V_236 ) {
int error ;
V_6 -> V_232 = F_130 ( V_6 -> V_47 . V_54 ,
V_6 -> V_47 . V_52 , V_26 ) ;
if ( ! V_6 -> V_232 )
goto V_345;
error = F_131 ( V_6 , V_26 ) ;
if ( error )
goto V_345;
}
V_6 -> V_84 . V_289 = V_6 -> V_84 . V_301 . V_55 - 1 ;
return 1 ;
V_345:
F_125 (pos, temp, &asoc->peer.transport_addr_list) {
V_91 = F_126 ( V_339 , struct V_131 , V_351 ) ;
if ( V_91 -> V_352 != V_342 )
F_127 ( V_6 , V_91 ) ;
}
V_343:
return 0 ;
}
static int F_124 ( struct V_5 * V_6 ,
union V_30 V_170 ,
const union V_215 * V_239 ,
T_5 V_26 )
{
struct V_28 * V_28 = F_14 ( V_6 -> V_8 . V_7 ) ;
union V_215 V_340 ;
int V_301 ;
T_4 V_38 ;
int V_33 = 1 ;
T_20 V_235 ;
T_27 V_357 ;
struct V_10 * V_11 ;
union V_358 * V_359 ;
struct V_131 * V_360 ;
switch ( V_170 . V_250 -> type ) {
case V_320 :
if ( V_361 != V_6 -> V_8 . V_7 -> V_362 )
break;
goto V_363;
case V_319 :
if ( F_132 ( V_6 -> V_8 . V_7 ) )
break;
V_363:
V_11 = F_4 ( F_123 ( V_170 . V_250 -> type ) ) ;
V_11 -> V_344 ( & V_340 , V_170 . V_340 , F_8 ( V_6 -> V_84 . V_284 ) , 0 ) ;
V_235 = F_92 ( V_239 ) ;
if ( F_133 ( V_28 , & V_340 , V_235 ) )
if ( ! F_121 ( V_6 , & V_340 , V_26 , V_364 ) )
return 0 ;
break;
case V_321 :
if ( ! V_28 -> V_59 . V_365 )
break;
V_357 = F_102 ( V_170 . V_366 -> V_367 ) ;
V_6 -> V_254 = F_134 ( V_6 -> V_254 , V_357 ) ;
break;
case V_327 :
F_34 ( L_6 , V_133 ) ;
break;
case V_74 :
V_6 -> V_84 . V_368 = 0 ;
V_6 -> V_84 . V_369 = 0 ;
if ( V_239 -> V_370 . V_371 == V_372 )
V_6 -> V_84 . V_369 = 1 ;
else if ( V_239 -> V_370 . V_371 == V_373 )
V_6 -> V_84 . V_368 = 1 ;
V_38 = F_20 ( V_170 . V_250 -> V_20 ) - sizeof( T_11 ) ;
if ( V_38 )
V_38 /= sizeof( T_4 ) ;
for ( V_301 = 0 ; V_301 < V_38 ; ++ V_301 ) {
switch ( V_170 . V_38 -> V_39 [ V_301 ] ) {
case V_319 :
V_6 -> V_84 . V_368 = 1 ;
break;
case V_320 :
if ( V_361 == V_6 -> V_8 . V_7 -> V_362 )
V_6 -> V_84 . V_369 = 1 ;
break;
case V_327 :
V_6 -> V_84 . V_374 = 1 ;
break;
default:
break;
}
}
break;
case V_251 :
V_6 -> V_84 . V_80 =
F_20 ( V_170 . V_250 -> V_20 ) - sizeof( T_11 ) ;
V_6 -> V_84 . V_79 = V_170 . V_79 -> V_249 ;
break;
case V_174 :
break;
case V_322 :
break;
case V_323 :
V_6 -> V_84 . V_85 = 1 ;
break;
case V_76 :
V_6 -> V_84 . V_65 = F_102 ( V_170 . V_375 -> V_65 ) ;
break;
case V_325 :
if ( ! V_28 -> V_59 . V_62 )
goto V_376;
V_359 = V_170 . V_73 + sizeof( V_377 ) ;
V_11 = F_4 ( F_123 ( V_170 . V_250 -> type ) ) ;
V_11 -> V_344 ( & V_340 , V_359 ,
F_8 ( V_6 -> V_84 . V_284 ) , 0 ) ;
if ( ! V_11 -> V_378 ( & V_340 , NULL , NULL ) )
break;
V_360 = F_135 ( V_6 , & V_340 ) ;
if ( ! V_360 )
break;
F_136 ( V_6 , V_360 ) ;
break;
case V_75 :
F_115 ( V_6 , V_170 ) ;
break;
case V_328 :
if ( V_28 -> V_59 . V_60 ) {
V_6 -> V_84 . V_86 = 1 ;
break;
}
goto V_376;
case V_329 :
if ( ! V_28 -> V_59 . V_66 )
goto V_376;
V_6 -> V_84 . V_346 = F_128 ( V_170 . V_250 ,
F_20 ( V_170 . V_250 -> V_20 ) , V_26 ) ;
if ( ! V_6 -> V_84 . V_346 ) {
V_33 = 0 ;
break;
}
break;
case V_332 :
if ( ! V_28 -> V_59 . V_66 )
goto V_376;
V_6 -> V_84 . V_347 = F_128 ( V_170 . V_250 ,
F_20 ( V_170 . V_250 -> V_20 ) , V_26 ) ;
if ( ! V_6 -> V_84 . V_347 ) {
V_33 = 0 ;
break;
}
F_137 ( V_6 , V_170 . V_379 ) ;
break;
case V_331 :
if ( ! V_28 -> V_59 . V_66 )
goto V_376;
V_6 -> V_84 . V_380 = F_128 ( V_170 . V_250 ,
F_20 ( V_170 . V_250 -> V_20 ) , V_26 ) ;
if ( ! V_6 -> V_84 . V_380 )
V_33 = 0 ;
break;
V_376:
default:
F_34 ( L_7 ,
V_133 , F_20 ( V_170 . V_250 -> type ) , V_6 ) ;
break;
}
return V_33 ;
}
T_13 F_138 ( const struct V_234 * V_82 )
{
T_13 V_381 ;
do {
F_139 ( & V_381 , sizeof( T_13 ) ) ;
} while ( V_381 == 0 );
return V_381 ;
}
T_13 F_140 ( const struct V_234 * V_82 )
{
T_13 V_33 ;
F_139 ( & V_33 , sizeof( T_13 ) ) ;
return V_33 ;
}
static struct V_3 * F_141 ( struct V_5 * V_6 ,
union V_215 * V_340 ,
int V_27 )
{
T_28 V_382 ;
struct V_3 * V_33 ;
int V_20 = sizeof( V_382 ) + V_27 ;
union V_358 V_383 ;
int V_384 ;
struct V_10 * V_11 = F_4 ( V_340 -> V_275 . V_385 ) ;
V_384 = V_11 -> V_386 ( V_340 , & V_383 ) ;
if ( ! V_384 )
return NULL ;
V_20 += V_384 ;
V_33 = F_21 ( V_6 , V_63 , 0 , V_20 ) ;
if ( ! V_33 )
return NULL ;
V_382 . V_387 = F_16 ( V_6 -> V_289 ++ ) ;
V_33 -> V_21 . V_388 =
F_9 ( V_33 , sizeof( V_382 ) , & V_382 ) ;
V_33 -> V_72 . V_73 =
F_9 ( V_33 , V_384 , & V_383 ) ;
return V_33 ;
}
struct V_3 * F_142 ( struct V_5 * V_6 ,
union V_215 * V_389 ,
struct V_390 * V_31 ,
int V_391 ,
T_1 V_105 )
{
V_377 V_170 ;
struct V_3 * V_33 ;
union V_358 V_359 ;
union V_215 * V_340 ;
void * V_392 ;
struct V_10 * V_11 ;
int V_393 = sizeof( V_170 ) ;
int V_394 = 0 ;
int V_395 = 0 ;
int V_301 ;
int V_396 = 0 ;
V_392 = V_31 ;
for ( V_301 = 0 ; V_301 < V_391 ; V_301 ++ ) {
V_340 = V_392 ;
V_11 = F_4 ( V_340 -> V_275 . V_385 ) ;
V_394 = V_11 -> V_386 ( V_340 , & V_359 ) ;
V_395 += V_393 ;
V_395 += V_394 ;
V_392 += V_11 -> V_397 ;
if ( V_6 -> V_398 && ! V_396 ) {
V_395 += V_393 ;
V_395 += V_394 ;
V_396 = 1 ;
F_34 ( L_8
L_9 ,
V_133 , V_395 ) ;
}
}
V_33 = F_141 ( V_6 , V_389 , V_395 ) ;
if ( ! V_33 )
return NULL ;
V_392 = V_31 ;
for ( V_301 = 0 ; V_301 < V_391 ; V_301 ++ ) {
V_340 = V_392 ;
V_11 = F_4 ( V_340 -> V_275 . V_385 ) ;
V_394 = V_11 -> V_386 ( V_340 , & V_359 ) ;
V_170 . V_72 . type = V_105 ;
V_170 . V_72 . V_20 = F_8 ( V_393 + V_394 ) ;
V_170 . V_399 = V_301 ;
F_9 ( V_33 , V_393 , & V_170 ) ;
F_9 ( V_33 , V_394 , & V_359 ) ;
V_392 += V_11 -> V_397 ;
}
if ( V_105 == V_349 && V_396 ) {
V_340 = V_6 -> V_398 ;
V_11 = F_4 ( V_340 -> V_275 . V_385 ) ;
V_394 = V_11 -> V_386 ( V_340 , & V_359 ) ;
V_170 . V_72 . type = V_350 ;
V_170 . V_72 . V_20 = F_8 ( V_393 + V_394 ) ;
V_170 . V_399 = V_301 ;
F_9 ( V_33 , V_393 , & V_170 ) ;
F_9 ( V_33 , V_394 , & V_359 ) ;
}
return V_33 ;
}
struct V_3 * F_143 ( struct V_5 * V_6 ,
union V_215 * V_340 )
{
V_377 V_170 ;
struct V_3 * V_33 ;
int V_18 = sizeof( V_170 ) ;
union V_358 V_383 ;
int V_384 ;
struct V_10 * V_11 = F_4 ( V_340 -> V_275 . V_385 ) ;
V_384 = V_11 -> V_386 ( V_340 , & V_383 ) ;
if ( ! V_384 )
return NULL ;
V_18 += V_384 ;
V_33 = F_141 ( V_6 , V_340 , V_18 ) ;
if ( ! V_33 )
return NULL ;
V_170 . V_72 . type = V_325 ;
V_170 . V_72 . V_20 = F_8 ( V_18 ) ;
V_170 . V_399 = 0 ;
F_9 ( V_33 , sizeof( V_170 ) , & V_170 ) ;
F_9 ( V_33 , V_384 , & V_383 ) ;
return V_33 ;
}
static struct V_3 * F_144 ( const struct V_5 * V_6 ,
T_13 V_387 , int V_27 )
{
T_28 V_382 ;
struct V_3 * V_33 ;
int V_20 = sizeof( V_382 ) + V_27 ;
V_33 = F_21 ( V_6 , V_64 , 0 , V_20 ) ;
if ( ! V_33 )
return NULL ;
V_382 . V_387 = F_16 ( V_387 ) ;
V_33 -> V_21 . V_388 =
F_9 ( V_33 , sizeof( V_382 ) , & V_382 ) ;
return V_33 ;
}
static void F_145 ( struct V_3 * V_4 , T_17 V_399 ,
T_1 V_400 , V_377 * V_401 )
{
V_377 V_402 ;
T_3 V_403 ;
int V_404 = 0 ;
int V_405 = 0 ;
T_1 V_406 ;
if ( V_407 == V_400 ) {
V_406 = V_408 ;
} else {
V_406 = V_409 ;
V_405 = sizeof( V_403 ) ;
if ( V_401 )
V_404 =
F_20 ( V_401 -> V_72 . V_20 ) ;
}
V_402 . V_72 . type = V_406 ;
V_402 . V_72 . V_20 = F_8 ( sizeof( V_402 ) +
V_405 +
V_404 ) ;
V_402 . V_399 = V_399 ;
F_9 ( V_4 , sizeof( V_402 ) , & V_402 ) ;
if ( V_407 == V_400 )
return;
V_403 . V_19 = V_400 ;
V_403 . V_20 = F_8 ( V_405 + V_404 ) ;
F_9 ( V_4 , V_405 , & V_403 ) ;
if ( V_401 )
F_9 ( V_4 , V_404 , V_401 ) ;
}
static T_1 F_146 ( struct V_5 * V_6 ,
struct V_3 * V_382 ,
V_377 * V_401 )
{
struct V_131 * V_84 ;
struct V_10 * V_11 ;
union V_215 V_340 ;
union V_358 * V_359 ;
V_359 = ( void * ) V_401 + sizeof( V_377 ) ;
if ( V_401 -> V_72 . type != V_349 &&
V_401 -> V_72 . type != V_350 &&
V_401 -> V_72 . type != V_325 )
return V_313 ;
switch ( V_359 -> V_250 . type ) {
case V_320 :
if ( ! V_6 -> V_84 . V_369 )
return V_298 ;
break;
case V_319 :
if ( ! V_6 -> V_84 . V_368 )
return V_298 ;
break;
default:
return V_298 ;
}
V_11 = F_4 ( F_123 ( V_359 -> V_250 . type ) ) ;
if ( F_60 ( ! V_11 ) )
return V_298 ;
V_11 -> V_344 ( & V_340 , V_359 , F_8 ( V_6 -> V_84 . V_284 ) , 0 ) ;
if ( ! V_11 -> V_410 ( & V_340 ) && ! V_11 -> V_378 ( & V_340 , NULL , V_382 -> V_2 ) )
return V_298 ;
switch ( V_401 -> V_72 . type ) {
case V_349 :
if ( V_11 -> V_410 ( & V_340 ) )
memcpy ( & V_340 , & V_382 -> V_218 , sizeof( V_340 ) ) ;
V_84 = F_121 ( V_6 , & V_340 , V_199 , V_364 ) ;
if ( ! V_84 )
return V_411 ;
if ( ! F_147 ( & V_84 -> V_412 , F_148 ( V_84 ) ) )
F_149 ( V_84 ) ;
V_6 -> V_413 = V_84 ;
break;
case V_350 :
if ( V_6 -> V_84 . V_414 == 1 )
return V_415 ;
if ( F_122 ( & V_382 -> V_218 , & V_340 ) )
return V_416 ;
if ( V_11 -> V_410 ( & V_340 ) ) {
F_136 ( V_6 , V_382 -> V_91 ) ;
F_150 ( V_6 ,
V_382 -> V_91 ) ;
} else
F_151 ( V_6 , & V_340 ) ;
break;
case V_325 :
if ( V_11 -> V_410 ( & V_340 ) )
memcpy ( & V_340 . V_275 , F_67 ( V_382 ) , sizeof( V_340 ) ) ;
V_84 = F_135 ( V_6 , & V_340 ) ;
if ( ! V_84 )
return V_298 ;
F_136 ( V_6 , V_84 ) ;
break;
}
return V_407 ;
}
int F_152 ( const struct V_5 * V_6 ,
struct V_166 * V_72 , void * V_165 ,
struct V_166 * * V_262 ) {
V_377 * V_401 ;
union V_30 V_170 ;
int V_20 , V_417 ;
V_170 . V_73 = ( T_11 * ) V_72 ;
while ( V_170 . V_73 <= V_165 - sizeof( T_11 ) ) {
V_20 = F_20 ( V_170 . V_250 -> V_20 ) ;
* V_262 = V_170 . V_250 ;
if ( V_170 . V_73 > V_165 - V_20 ||
V_20 < sizeof( T_11 ) )
return 0 ;
switch ( V_170 . V_250 -> type ) {
case V_349 :
case V_350 :
case V_325 :
V_401 = ( V_377 * ) V_170 . V_73 ;
V_417 = F_20 ( V_401 -> V_72 . V_20 ) ;
if ( V_417 < sizeof( V_377 ) +
sizeof( T_11 ) )
return 0 ;
break;
case V_408 :
case V_76 :
if ( V_20 != sizeof( V_377 ) )
return 0 ;
break;
default:
break;
}
V_170 . V_73 += F_18 ( V_20 ) ;
}
if ( V_170 . V_73 != V_165 )
return 0 ;
return 1 ;
}
struct V_3 * F_153 ( struct V_5 * V_6 ,
struct V_3 * V_382 )
{
T_28 * V_418 ;
union V_358 * V_359 ;
V_377 * V_401 ;
struct V_3 * V_419 ;
T_1 V_400 ;
int V_20 = 0 ;
int V_109 ;
T_13 V_387 ;
int V_420 = 1 ;
V_109 = F_20 ( V_382 -> V_149 -> V_20 ) - sizeof( T_19 ) ;
V_418 = ( T_28 * ) V_382 -> V_2 -> V_162 ;
V_387 = F_102 ( V_418 -> V_387 ) ;
V_20 = sizeof( T_28 ) ;
V_359 = (union V_358 * ) ( V_382 -> V_2 -> V_162 + V_20 ) ;
V_109 -= V_20 ;
V_20 = F_20 ( V_359 -> V_250 . V_20 ) ;
V_401 = ( void * ) V_359 + V_20 ;
V_109 -= V_20 ;
V_419 = F_144 ( V_6 , V_387 , V_109 * 4 ) ;
if ( ! V_419 )
goto V_421;
while ( V_109 > 0 ) {
V_400 = F_146 ( V_6 , V_382 ,
V_401 ) ;
if ( V_407 != V_400 )
V_420 = 0 ;
if ( ! V_420 )
F_145 ( V_419 ,
V_401 -> V_399 , V_400 ,
V_401 ) ;
if ( V_411 == V_400 )
goto V_421;
V_20 = F_20 ( V_401 -> V_72 . V_20 ) ;
V_401 = ( void * ) V_401 + V_20 ;
V_109 -= V_20 ;
}
V_421:
V_6 -> V_84 . V_289 ++ ;
if ( V_419 ) {
F_81 ( V_419 ) ;
F_154 ( & V_419 -> V_212 ,
& V_6 -> V_422 ) ;
}
return V_419 ;
}
static void F_155 ( struct V_5 * V_6 ,
V_377 * V_401 )
{
struct V_10 * V_11 ;
union V_215 V_340 ;
struct V_24 * V_25 = & V_6 -> V_8 . V_81 ;
union V_358 * V_359 ;
struct V_131 * V_91 ;
struct V_423 * V_424 ;
V_359 = ( void * ) V_401 + sizeof( V_377 ) ;
V_11 = F_4 ( F_123 ( V_359 -> V_250 . type ) ) ;
V_11 -> V_344 ( & V_340 , V_359 , F_8 ( V_25 -> V_284 ) , 0 ) ;
switch ( V_401 -> V_72 . type ) {
case V_349 :
F_156 () ;
F_38 (saddr, &bp->address_list, list) {
if ( F_122 ( & V_424 -> V_425 , & V_340 ) )
V_424 -> V_352 = V_286 ;
}
F_157 () ;
F_38 (transport, &asoc->peer.transport_addr_list,
transports) {
F_158 ( V_91 -> V_426 ) ;
V_91 -> V_426 = NULL ;
}
break;
case V_350 :
F_156 () ;
F_159 ( V_25 , & V_340 ) ;
if ( V_6 -> V_398 != NULL &&
F_122 ( V_6 -> V_398 , & V_340 ) ) {
F_23 ( V_6 -> V_398 ) ;
V_6 -> V_398 = NULL ;
}
F_157 () ;
F_38 (transport, &asoc->peer.transport_addr_list,
transports) {
F_158 ( V_91 -> V_426 ) ;
V_91 -> V_426 = NULL ;
}
break;
default:
break;
}
}
static T_1 F_160 ( struct V_3 * V_419 ,
V_377 * V_401 ,
int V_427 )
{
V_377 * V_428 ;
T_3 * V_403 ;
int V_20 ;
int V_429 ;
T_1 V_400 ;
if ( V_427 )
V_400 = V_407 ;
else
V_400 = V_430 ;
V_429 = F_20 ( V_419 -> V_149 -> V_20 ) -
sizeof( T_19 ) ;
V_20 = sizeof( T_28 ) ;
V_428 = ( V_377 * ) ( V_419 -> V_2 -> V_162 +
V_20 ) ;
V_429 -= V_20 ;
while ( V_429 > 0 ) {
if ( V_428 -> V_399 == V_401 -> V_399 ) {
switch( V_428 -> V_72 . type ) {
case V_408 :
return V_407 ;
case V_409 :
V_20 = sizeof( V_377 ) ;
V_403 = ( void * ) V_428 + V_20 ;
V_429 -= V_20 ;
if ( V_429 > 0 )
return V_403 -> V_19 ;
else
return V_297 ;
break;
default:
return V_297 ;
}
}
V_20 = F_20 ( V_428 -> V_72 . V_20 ) ;
V_428 = ( void * ) V_428 + V_20 ;
V_429 -= V_20 ;
}
return V_400 ;
}
int F_161 ( struct V_5 * V_6 ,
struct V_3 * V_419 )
{
struct V_3 * V_382 = V_6 -> V_431 ;
union V_358 * V_359 ;
V_377 * V_401 ;
int V_20 = 0 ;
int V_432 = V_382 -> V_2 -> V_18 ;
int V_420 = 0 ;
int V_427 = 1 ;
int V_33 = 0 ;
T_1 V_400 = V_407 ;
V_20 = sizeof( V_433 ) ;
V_359 = (union V_358 * ) ( V_382 -> V_2 -> V_162 + V_20 ) ;
V_432 -= V_20 ;
V_20 = F_20 ( V_359 -> V_250 . V_20 ) ;
V_401 = ( void * ) V_359 + V_20 ;
V_432 -= V_20 ;
if ( V_419 -> V_2 -> V_18 == sizeof( T_28 ) )
V_420 = 1 ;
while ( V_432 > 0 ) {
if ( V_420 )
V_400 = V_407 ;
else {
V_400 = F_160 ( V_419 ,
V_401 ,
V_427 ) ;
if ( V_427 && ( V_407 != V_400 ) )
V_427 = 0 ;
}
switch ( V_400 ) {
case V_407 :
F_155 ( V_6 , V_401 ) ;
break;
case V_411 :
V_33 = 1 ;
break;
case V_313 :
V_6 -> V_84 . V_348 |=
V_401 -> V_72 . type ;
break;
case V_430 :
case V_415 :
case V_416 :
default:
break;
}
V_20 = F_20 ( V_401 -> V_72 . V_20 ) ;
V_401 = ( void * ) V_401 + V_20 ;
V_432 -= V_20 ;
}
if ( V_427 && V_6 -> V_434 ) {
V_6 -> V_434 = 0 ;
F_162 ( V_6 -> V_84 . V_435 ) ;
}
F_75 ( & V_382 -> V_212 ) ;
F_47 ( V_382 ) ;
V_6 -> V_431 = NULL ;
return V_33 ;
}
struct V_3 * F_163 ( const struct V_5 * V_6 ,
T_13 V_436 , T_2 V_437 ,
struct V_438 * V_439 )
{
struct V_3 * V_33 = NULL ;
struct V_440 V_441 ;
struct V_438 V_442 ;
T_2 V_148 ;
int V_301 ;
V_148 = ( V_437 + 1 ) * sizeof( T_13 ) ;
V_33 = F_21 ( V_6 , V_305 , 0 , V_148 ) ;
if ( ! V_33 )
return NULL ;
V_441 . V_436 = F_16 ( V_436 ) ;
V_33 -> V_21 . V_443 =
F_9 ( V_33 , sizeof( V_441 ) , & V_441 ) ;
for ( V_301 = 0 ; V_301 < V_437 ; V_301 ++ ) {
V_442 . V_111 = V_439 [ V_301 ] . V_111 ;
V_442 . V_106 = V_439 [ V_301 ] . V_106 ;
F_9 ( V_33 , sizeof( V_442 ) , & V_442 ) ;
}
return V_33 ;
}

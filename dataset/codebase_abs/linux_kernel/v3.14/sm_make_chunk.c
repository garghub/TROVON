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
V_33 -> V_201 = 1 ;
V_33 -> V_202 = V_203 ;
F_63 ( & V_33 -> V_204 ) ;
F_63 ( & V_33 -> V_205 ) ;
F_64 ( V_4 ) ;
F_65 ( & V_33 -> V_206 , 1 ) ;
V_70:
return V_33 ;
}
void F_66 ( struct V_3 * V_4 , union V_207 * V_208 ,
union V_207 * V_209 )
{
memcpy ( & V_4 -> V_210 , V_208 , sizeof( union V_207 ) ) ;
memcpy ( & V_4 -> V_209 , V_209 , sizeof( union V_207 ) ) ;
}
const union V_207 * F_67 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_91 ) {
return & V_4 -> V_91 -> V_176 ;
} else {
return & V_4 -> V_210 ;
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
V_33 -> V_165 = ( ( T_10 * ) V_149 ) + sizeof( struct V_211 ) ;
if ( F_71 ( type , V_6 ) )
V_33 -> V_212 = 1 ;
return V_33 ;
V_70:
return NULL ;
}
static struct V_3 * F_31 ( const struct V_5 * V_6 ,
T_10 V_105 , int V_16 )
{
return F_68 ( V_6 , V_213 , V_105 , V_16 ) ;
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
F_75 ( & V_4 -> V_204 ) ;
F_76 ( V_4 -> V_2 ) ;
F_76 ( V_4 -> V_214 ) ;
F_77 ( V_4 ) ;
F_78 ( V_198 , V_4 ) ;
}
void F_47 ( struct V_3 * V_4 )
{
if ( V_4 -> V_155 )
F_79 ( V_4 -> V_155 ) ;
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
int V_164 = F_20 ( V_4 -> V_149 -> V_20 ) ;
int V_217 = F_18 ( V_164 ) - V_164 ;
V_216 = F_48 ( V_4 -> V_2 , V_217 ) ;
V_163 = F_48 ( V_4 -> V_2 , V_18 ) ;
memset ( V_216 , 0 , V_217 ) ;
memcpy ( V_163 , V_162 , V_18 ) ;
V_4 -> V_149 -> V_20 = F_8 ( V_164 + V_217 + V_18 ) ;
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
int F_84 ( struct V_3 * V_4 , int V_218 , int V_18 ,
struct V_219 * V_162 )
{
T_10 * V_163 ;
int V_17 = 0 ;
V_163 = F_48 ( V_4 -> V_2 , V_18 ) ;
if ( ( V_17 = F_85 ( V_163 , V_162 , V_218 , V_18 ) ) )
goto V_220;
V_4 -> V_149 -> V_20 =
F_8 ( F_20 ( V_4 -> V_149 -> V_20 ) + V_18 ) ;
V_4 -> V_165 = F_49 ( V_4 -> V_2 ) ;
V_220:
return V_17 ;
}
void F_86 ( struct V_3 * V_4 )
{
struct V_221 * V_155 ;
struct V_3 * V_222 ;
struct V_223 * V_111 ;
T_4 V_106 ;
T_4 V_224 ;
if ( V_4 -> V_225 )
return;
V_224 = F_20 ( V_4 -> V_21 . V_118 -> V_111 ) ;
V_111 = & V_4 -> V_6 -> V_226 -> V_220 ;
V_155 = V_4 -> V_155 ;
F_38 (lchunk, &msg->chunks, frag_list) {
if ( V_222 -> V_149 -> V_105 & V_117 ) {
V_106 = 0 ;
} else {
if ( V_222 -> V_149 -> V_105 & V_227 )
V_106 = F_87 ( V_111 , V_224 ) ;
else
V_106 = F_88 ( V_111 , V_224 ) ;
}
V_222 -> V_21 . V_118 -> V_106 = F_8 ( V_106 ) ;
V_222 -> V_225 = 1 ;
}
}
void F_89 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_228 ) {
V_4 -> V_21 . V_118 -> V_110 =
F_16 ( F_90 ( V_4 -> V_6 ) ) ;
V_4 -> V_228 = 1 ;
}
}
struct V_5 * F_91 ( const struct V_229 * V_82 ,
struct V_3 * V_4 ,
T_5 V_26 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
T_20 V_230 ;
struct V_10 * V_11 ;
V_230 = F_92 ( F_67 ( V_4 ) ) ;
V_6 = F_93 ( V_82 , V_82 -> V_8 . V_7 , V_230 , V_26 ) ;
if ( ! V_6 )
goto V_70;
V_6 -> V_231 = 1 ;
V_2 = V_4 -> V_2 ;
V_11 = F_4 ( F_5 ( F_6 ( V_2 ) -> V_13 ) ) ;
if ( F_60 ( ! V_11 ) )
goto V_232;
V_11 -> V_233 ( & V_6 -> V_47 . V_234 , V_2 , 1 ) ;
V_70:
return V_6 ;
V_232:
F_94 ( V_6 ) ;
return NULL ;
}
static T_12 * F_25 ( const struct V_229 * V_82 ,
const struct V_5 * V_6 ,
const struct V_3 * V_235 ,
int * V_80 ,
const T_10 * V_236 , int V_35 )
{
T_12 * V_33 ;
struct V_237 * V_79 ;
struct V_238 V_239 ;
int V_240 , V_241 ;
V_240 = sizeof( T_11 ) +
( sizeof( struct V_237 ) -
sizeof( struct V_242 ) ) ;
V_241 = sizeof( struct V_242 )
+ F_20 ( V_235 -> V_149 -> V_20 ) + V_35 ;
if ( V_241 % V_243 )
V_241 += V_243
- ( V_241 % V_243 ) ;
* V_80 = V_240 + V_241 ;
V_33 = F_95 ( * V_80 , V_199 ) ;
if ( ! V_33 )
goto V_70;
V_79 = (struct V_237 * ) V_33 -> V_244 ;
V_33 -> V_245 . type = V_246 ;
V_33 -> V_245 . V_20 = F_8 ( * V_80 ) ;
V_79 -> V_47 = V_6 -> V_47 ;
V_79 -> V_47 . V_247 = V_35 ;
V_79 -> V_47 . V_86 = V_6 -> V_84 . V_86 ;
V_79 -> V_47 . V_65 = V_6 -> V_84 . V_65 ;
V_79 -> V_47 . V_248 = F_96 ( V_6 -> V_249 ,
F_97 () ) ;
memcpy ( & V_79 -> V_47 . V_250 [ 0 ] , V_235 -> V_149 ,
F_20 ( V_235 -> V_149 -> V_20 ) ) ;
memcpy ( ( T_10 * ) & V_79 -> V_47 . V_250 [ 0 ] +
F_20 ( V_235 -> V_149 -> V_20 ) , V_236 , V_35 ) ;
if ( F_17 ( V_82 -> V_8 . V_7 ) -> V_191 ) {
struct V_251 V_252 ;
F_98 ( & V_239 , & V_79 -> V_47 , V_241 ) ;
V_252 . V_253 = F_17 ( V_82 -> V_8 . V_7 ) -> V_191 ;
V_252 . V_105 = 0 ;
if ( F_99 ( V_252 . V_253 , V_82 -> V_254 ,
sizeof( V_82 -> V_254 ) ) ||
F_100 ( & V_252 , & V_239 , V_241 , V_79 -> V_255 ) )
goto V_256;
}
return V_33 ;
V_256:
F_23 ( V_33 ) ;
V_70:
* V_80 = 0 ;
return NULL ;
}
struct V_5 * F_101 (
const struct V_229 * V_82 ,
const struct V_5 * V_6 ,
struct V_3 * V_4 , T_5 V_26 ,
int * error , struct V_3 * * V_257 )
{
struct V_5 * V_33 = NULL ;
struct V_237 * V_79 ;
struct V_242 * V_258 ;
int V_240 , V_241 , V_259 ;
T_10 * V_260 = V_82 -> V_260 ;
struct V_238 V_239 ;
unsigned int V_18 ;
T_20 V_230 ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_21 V_261 ;
struct V_251 V_252 ;
V_240 = sizeof( T_19 ) +
( sizeof( struct V_237 ) -
sizeof( struct V_242 ) ) ;
V_241 = F_20 ( V_4 -> V_149 -> V_20 ) - V_240 ;
V_259 = V_240 + sizeof( struct V_242 ) ;
V_18 = F_20 ( V_4 -> V_149 -> V_20 ) ;
if ( V_18 < V_259 + sizeof( struct V_211 ) )
goto V_262;
if ( V_241 % V_243 )
goto V_262;
V_79 = V_4 -> V_21 . V_93 ;
V_258 = & V_79 -> V_47 ;
if ( ! F_17 ( V_82 -> V_8 . V_7 ) -> V_191 )
goto V_263;
F_98 ( & V_239 , V_258 , V_241 ) ;
V_252 . V_253 = F_17 ( V_82 -> V_8 . V_7 ) -> V_191 ;
V_252 . V_105 = 0 ;
memset ( V_260 , 0x00 , V_264 ) ;
if ( F_99 ( V_252 . V_253 , V_82 -> V_254 ,
sizeof( V_82 -> V_254 ) ) ||
F_100 ( & V_252 , & V_239 , V_241 , V_260 ) ) {
* error = - V_265 ;
goto V_232;
}
if ( memcmp ( V_260 , V_79 -> V_255 , V_264 ) ) {
* error = - V_266 ;
goto V_232;
}
V_263:
if ( F_102 ( V_4 -> V_267 -> V_268 ) != V_258 -> V_48 ) {
* error = - V_269 ;
goto V_232;
}
if ( V_4 -> V_267 -> V_210 != V_258 -> V_234 . V_270 . V_271 ||
F_20 ( V_4 -> V_267 -> V_209 ) != V_258 -> V_272 ) {
* error = - V_273 ;
goto V_232;
}
if ( F_103 ( V_82 -> V_8 . V_7 , V_274 ) )
V_261 = F_104 ( V_2 ) ;
else
V_261 = F_97 () ;
if ( ! V_6 && F_105 ( V_258 -> V_248 , V_261 ) < 0 ) {
V_18 = F_20 ( V_4 -> V_149 -> V_20 ) ;
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
V_33 = F_93 ( V_82 , V_82 -> V_8 . V_7 , V_230 , V_26 ) ;
if ( ! V_33 ) {
* error = - V_265 ;
goto V_232;
}
V_33 -> V_84 . V_279 = F_20 ( V_4 -> V_267 -> V_210 ) ;
memcpy ( & V_33 -> V_47 , V_258 , sizeof( * V_258 ) ) ;
if ( F_108 ( V_33 , V_258 ,
V_199 ) < 0 ) {
* error = - V_265 ;
goto V_232;
}
if ( F_74 ( & V_33 -> V_8 . V_81 . V_280 ) ) {
F_109 ( & V_33 -> V_8 . V_81 , & V_4 -> V_209 ,
V_281 , V_199 ) ;
}
V_33 -> V_282 = V_33 -> V_47 . V_55 ;
V_33 -> V_283 = V_33 -> V_282 - 1 ;
V_33 -> V_284 = V_33 -> V_47 . V_55 ;
V_33 -> V_285 = V_33 -> V_283 ;
V_33 -> V_84 . V_86 = V_33 -> V_47 . V_86 ;
V_33 -> V_84 . V_65 = V_33 -> V_47 . V_65 ;
return V_33 ;
V_232:
if ( V_33 )
F_94 ( V_33 ) ;
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
struct V_166 * V_170 ,
const struct V_3 * V_4 ,
struct V_3 * * V_257 )
{
if ( * V_257 )
F_47 ( * V_257 ) ;
* V_257 = F_51 ( V_6 , V_4 , V_170 ) ;
return 0 ;
}
static int F_113 ( const struct V_5 * V_6 ,
union V_30 V_170 ,
struct V_3 * V_4 ,
struct V_3 * * V_257 )
{
T_4 V_18 = F_20 ( V_170 . V_245 -> V_20 ) ;
if ( * V_257 )
F_47 ( * V_257 ) ;
* V_257 = F_55 ( V_6 , V_4 , V_18 ) ;
if ( * V_257 ) {
F_7 ( * V_257 , V_293 , V_18 ) ;
F_9 ( * V_257 , V_18 , V_170 . V_73 ) ;
}
return 0 ;
}
static int F_114 ( struct V_28 * V_28 , union V_30 V_170 )
{
T_4 V_42 = F_20 ( V_170 . V_245 -> V_20 ) - sizeof( T_11 ) ;
int V_294 = 0 ;
int V_295 = 0 ;
int V_296 ;
for ( V_296 = 0 ; V_296 < V_42 ; V_296 ++ ) {
switch ( V_170 . V_297 -> V_298 [ V_296 ] ) {
case V_68 :
V_294 = 1 ;
break;
case V_63 :
case V_64 :
V_295 = 1 ;
break;
}
}
if ( V_28 -> V_59 . V_299 )
return 1 ;
if ( V_28 -> V_59 . V_62 && ! V_294 && V_295 )
return 0 ;
return 1 ;
}
static void F_115 ( struct V_5 * V_6 ,
union V_30 V_170 )
{
struct V_28 * V_28 = F_14 ( V_6 -> V_8 . V_7 ) ;
T_4 V_42 = F_20 ( V_170 . V_245 -> V_20 ) - sizeof( T_11 ) ;
int V_296 ;
for ( V_296 = 0 ; V_296 < V_42 ; V_296 ++ ) {
switch ( V_170 . V_297 -> V_298 [ V_296 ] ) {
case V_300 :
if ( V_28 -> V_59 . V_60 && ! V_6 -> V_84 . V_86 )
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
struct V_3 * * V_257 )
{
int V_33 = V_301 ;
switch ( V_170 . V_245 -> type & V_302 ) {
case V_303 :
V_33 = V_304 ;
break;
case V_305 :
break;
case V_306 :
V_33 = V_304 ;
case V_307 :
if ( NULL == * V_257 )
* V_257 = F_56 ( V_6 , V_4 ) ;
if ( * V_257 ) {
if ( ! F_10 ( * V_257 , V_308 ,
F_18 ( F_20 ( V_170 . V_245 -> V_20 ) ) ) )
F_12 ( * V_257 ,
F_18 ( F_20 ( V_170 . V_245 -> V_20 ) ) ,
V_170 . V_73 ) ;
} else {
V_33 = V_265 ;
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
T_25 V_309 ,
struct V_3 * V_4 ,
struct V_3 * * V_156 )
{
struct V_310 * V_311 ;
int V_33 = V_301 ;
T_4 V_312 , V_313 = 0 ;
int V_296 ;
switch ( V_170 . V_245 -> type ) {
case V_314 :
case V_315 :
case V_316 :
case V_74 :
case V_246 :
case V_174 :
case V_317 :
case V_318 :
case V_76 :
break;
case V_75 :
if ( ! F_114 ( V_28 , V_170 ) )
return V_319 ;
break;
case V_320 :
if ( V_28 -> V_59 . V_62 )
break;
goto V_321;
case V_322 :
F_113 ( V_6 , V_170 , V_4 , V_156 ) ;
V_33 = V_319 ;
break;
case V_323 :
if ( V_28 -> V_59 . V_60 )
break;
goto V_321;
case V_324 :
if ( ! V_28 -> V_59 . V_66 )
goto V_321;
if ( V_325 !=
F_20 ( V_170 . V_245 -> V_20 ) - sizeof( T_11 ) ) {
F_112 ( V_6 , V_170 . V_245 ,
V_4 , V_156 ) ;
V_33 = V_319 ;
}
break;
case V_326 :
if ( ! V_28 -> V_59 . V_66 )
goto V_321;
if ( 260 < F_20 ( V_170 . V_245 -> V_20 ) ) {
F_112 ( V_6 , V_170 . V_245 ,
V_4 , V_156 ) ;
V_33 = V_319 ;
}
break;
case V_327 :
if ( ! V_28 -> V_59 . V_66 )
goto V_321;
V_311 = (struct V_310 * ) V_170 . V_245 ;
V_312 = ( F_20 ( V_170 . V_245 -> V_20 ) - sizeof( T_11 ) ) >> 1 ;
for ( V_296 = 0 ; V_296 < V_312 ; V_296 ++ ) {
V_313 = F_20 ( V_311 -> V_328 [ V_296 ] ) ;
if ( V_313 == V_329 )
break;
}
if ( V_313 != V_329 ) {
F_112 ( V_6 , V_170 . V_245 , V_4 ,
V_156 ) ;
V_33 = V_319 ;
}
break;
V_321:
default:
F_34 ( L_5 ,
V_133 , F_20 ( V_170 . V_245 -> type ) , V_309 ) ;
V_33 = F_116 ( V_6 , V_170 , V_4 , V_156 ) ;
break;
}
return V_33 ;
}
int F_118 ( struct V_28 * V_28 , const struct V_5 * V_6 ,
T_25 V_309 ,
T_26 * V_250 ,
struct V_3 * V_4 ,
struct V_3 * * V_257 )
{
union V_30 V_170 ;
bool V_330 = false ;
int V_331 ;
if ( V_250 -> V_71 . V_51 == 0 ||
V_250 -> V_71 . V_53 == 0 ||
V_250 -> V_71 . V_46 == 0 ||
F_102 ( V_250 -> V_71 . V_49 ) < V_332 )
return F_111 ( V_6 , V_4 , V_257 ) ;
F_119 (param, peer_init, init_hdr.params) {
if ( V_170 . V_245 -> type == V_246 )
V_330 = true ;
}
if ( V_170 . V_73 != ( void * ) V_4 -> V_165 )
return F_112 ( V_6 , V_170 . V_245 , V_4 , V_257 ) ;
if ( ( V_89 == V_309 ) && ! V_330 )
return F_110 ( V_6 , V_246 ,
V_4 , V_257 ) ;
F_119 (param, peer_init, init_hdr.params) {
V_331 = F_117 ( V_28 , V_6 , V_170 , V_309 , V_4 , V_257 ) ;
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
const union V_207 * V_234 ,
T_26 * V_250 , T_5 V_26 )
{
struct V_28 * V_28 = F_14 ( V_6 -> V_8 . V_7 ) ;
union V_30 V_170 ;
struct V_131 * V_91 ;
struct V_333 * V_334 , * V_231 ;
struct V_10 * V_11 ;
union V_207 V_335 ;
char * V_79 ;
int V_336 = 0 ;
if ( ! F_121 ( V_6 , V_234 , V_26 , V_337 ) )
goto V_338;
if ( F_122 ( F_67 ( V_4 ) , V_234 ) )
V_336 = 1 ;
F_119 (param, peer_init, init_hdr.params) {
if ( ! V_336 && ( V_170 . V_245 -> type == V_314 ||
V_170 . V_245 -> type == V_315 ) ) {
V_11 = F_4 ( F_123 ( V_170 . V_245 -> type ) ) ;
V_11 -> V_339 ( & V_335 , V_170 . V_335 ,
V_4 -> V_267 -> V_210 , 0 ) ;
if ( F_122 ( F_67 ( V_4 ) , & V_335 ) )
V_336 = 1 ;
}
if ( ! F_124 ( V_6 , V_170 , V_234 , V_26 ) )
goto V_340;
}
if ( ! V_336 )
goto V_340;
if ( V_6 -> V_84 . V_88 && ( ! V_6 -> V_84 . V_341 ||
! V_6 -> V_84 . V_342 ) )
V_6 -> V_84 . V_88 = 0 ;
if ( ! V_28 -> V_59 . V_299 &&
( V_6 -> V_84 . V_87 && ! V_6 -> V_84 . V_88 ) ) {
V_6 -> V_84 . V_343 |= ( V_344 |
V_345 |
V_320 ) ;
V_6 -> V_84 . V_87 = 0 ;
goto V_340;
}
F_125 (pos, temp, &asoc->peer.transport_addr_list) {
V_91 = F_126 ( V_334 , struct V_131 , V_346 ) ;
if ( V_91 -> V_347 == V_348 ) {
F_127 ( V_6 , V_91 ) ;
}
}
V_6 -> V_84 . V_296 . V_46 =
F_102 ( V_250 -> V_71 . V_46 ) ;
V_6 -> V_84 . V_296 . V_49 =
F_102 ( V_250 -> V_71 . V_49 ) ;
V_6 -> V_84 . V_296 . V_51 =
F_20 ( V_250 -> V_71 . V_51 ) ;
V_6 -> V_84 . V_296 . V_53 =
F_20 ( V_250 -> V_71 . V_53 ) ;
V_6 -> V_84 . V_296 . V_55 =
F_102 ( V_250 -> V_71 . V_55 ) ;
if ( V_6 -> V_47 . V_52 >
F_20 ( V_250 -> V_71 . V_53 ) ) {
V_6 -> V_47 . V_52 =
F_20 ( V_250 -> V_71 . V_53 ) ;
}
if ( V_6 -> V_47 . V_54 >
F_20 ( V_250 -> V_71 . V_51 ) ) {
V_6 -> V_47 . V_54 =
F_20 ( V_250 -> V_71 . V_51 ) ;
}
V_6 -> V_47 . V_349 = V_6 -> V_84 . V_296 . V_46 ;
V_6 -> V_84 . V_50 = V_6 -> V_84 . V_296 . V_49 ;
V_79 = V_6 -> V_84 . V_79 ;
if ( V_79 ) {
V_6 -> V_84 . V_79 = F_128 ( V_79 , V_6 -> V_84 . V_80 , V_26 ) ;
if ( ! V_6 -> V_84 . V_79 )
goto V_340;
}
F_38 (transport, &asoc->peer.transport_addr_list,
transports) {
V_91 -> V_350 = V_6 -> V_84 . V_296 . V_49 ;
}
if ( ! F_129 ( & V_6 -> V_84 . V_127 , V_351 ,
V_6 -> V_84 . V_296 . V_55 , V_26 ) )
goto V_340;
if ( ! V_6 -> V_231 ) {
int error ;
V_6 -> V_226 = F_130 ( V_6 -> V_47 . V_54 ,
V_6 -> V_47 . V_52 , V_26 ) ;
if ( ! V_6 -> V_226 )
goto V_340;
error = F_131 ( V_6 , V_26 ) ;
if ( error )
goto V_340;
}
V_6 -> V_84 . V_284 = V_6 -> V_84 . V_296 . V_55 - 1 ;
return 1 ;
V_340:
F_125 (pos, temp, &asoc->peer.transport_addr_list) {
V_91 = F_126 ( V_334 , struct V_131 , V_346 ) ;
if ( V_91 -> V_347 != V_337 )
F_127 ( V_6 , V_91 ) ;
}
V_338:
return 0 ;
}
static int F_124 ( struct V_5 * V_6 ,
union V_30 V_170 ,
const union V_207 * V_234 ,
T_5 V_26 )
{
struct V_28 * V_28 = F_14 ( V_6 -> V_8 . V_7 ) ;
union V_207 V_335 ;
int V_296 ;
T_4 V_38 ;
int V_33 = 1 ;
T_20 V_230 ;
T_27 V_352 ;
struct V_10 * V_11 ;
union V_353 * V_354 ;
struct V_131 * V_355 ;
switch ( V_170 . V_245 -> type ) {
case V_315 :
if ( V_356 != V_6 -> V_8 . V_7 -> V_357 )
break;
goto V_358;
case V_314 :
if ( F_132 ( V_6 -> V_8 . V_7 ) )
break;
V_358:
V_11 = F_4 ( F_123 ( V_170 . V_245 -> type ) ) ;
V_11 -> V_339 ( & V_335 , V_170 . V_335 , F_8 ( V_6 -> V_84 . V_279 ) , 0 ) ;
V_230 = F_92 ( V_234 ) ;
if ( F_133 ( V_28 , & V_335 , V_230 ) )
if ( ! F_121 ( V_6 , & V_335 , V_26 , V_359 ) )
return 0 ;
break;
case V_316 :
if ( ! V_28 -> V_59 . V_360 )
break;
V_352 = F_102 ( V_170 . V_361 -> V_362 ) ;
V_6 -> V_249 = F_134 ( V_6 -> V_249 , V_352 ) ;
break;
case V_322 :
F_34 ( L_6 , V_133 ) ;
break;
case V_74 :
V_6 -> V_84 . V_363 = 0 ;
V_6 -> V_84 . V_364 = 0 ;
if ( V_234 -> V_365 . V_366 == V_367 )
V_6 -> V_84 . V_364 = 1 ;
else if ( V_234 -> V_365 . V_366 == V_368 )
V_6 -> V_84 . V_363 = 1 ;
V_38 = F_20 ( V_170 . V_245 -> V_20 ) - sizeof( T_11 ) ;
if ( V_38 )
V_38 /= sizeof( T_4 ) ;
for ( V_296 = 0 ; V_296 < V_38 ; ++ V_296 ) {
switch ( V_170 . V_38 -> V_39 [ V_296 ] ) {
case V_314 :
V_6 -> V_84 . V_363 = 1 ;
break;
case V_315 :
if ( V_356 == V_6 -> V_8 . V_7 -> V_357 )
V_6 -> V_84 . V_364 = 1 ;
break;
case V_322 :
V_6 -> V_84 . V_369 = 1 ;
break;
default:
break;
}
}
break;
case V_246 :
V_6 -> V_84 . V_80 =
F_20 ( V_170 . V_245 -> V_20 ) - sizeof( T_11 ) ;
V_6 -> V_84 . V_79 = V_170 . V_79 -> V_244 ;
break;
case V_174 :
break;
case V_317 :
break;
case V_318 :
V_6 -> V_84 . V_85 = 1 ;
break;
case V_76 :
V_6 -> V_84 . V_65 = F_102 ( V_170 . V_370 -> V_65 ) ;
break;
case V_320 :
if ( ! V_28 -> V_59 . V_62 )
goto V_371;
V_354 = V_170 . V_73 + sizeof( V_372 ) ;
V_11 = F_4 ( F_123 ( V_170 . V_245 -> type ) ) ;
V_11 -> V_339 ( & V_335 , V_354 ,
F_8 ( V_6 -> V_84 . V_279 ) , 0 ) ;
if ( ! V_11 -> V_373 ( & V_335 , NULL , NULL ) )
break;
V_355 = F_135 ( V_6 , & V_335 ) ;
if ( ! V_355 )
break;
F_136 ( V_6 , V_355 ) ;
break;
case V_75 :
F_115 ( V_6 , V_170 ) ;
break;
case V_323 :
if ( V_28 -> V_59 . V_60 ) {
V_6 -> V_84 . V_86 = 1 ;
break;
}
goto V_371;
case V_324 :
if ( ! V_28 -> V_59 . V_66 )
goto V_371;
V_6 -> V_84 . V_341 = F_128 ( V_170 . V_245 ,
F_20 ( V_170 . V_245 -> V_20 ) , V_26 ) ;
if ( ! V_6 -> V_84 . V_341 ) {
V_33 = 0 ;
break;
}
break;
case V_327 :
if ( ! V_28 -> V_59 . V_66 )
goto V_371;
V_6 -> V_84 . V_342 = F_128 ( V_170 . V_245 ,
F_20 ( V_170 . V_245 -> V_20 ) , V_26 ) ;
if ( ! V_6 -> V_84 . V_342 ) {
V_33 = 0 ;
break;
}
F_137 ( V_6 , V_170 . V_374 ) ;
break;
case V_326 :
if ( ! V_28 -> V_59 . V_66 )
goto V_371;
V_6 -> V_84 . V_375 = F_128 ( V_170 . V_245 ,
F_20 ( V_170 . V_245 -> V_20 ) , V_26 ) ;
if ( ! V_6 -> V_84 . V_375 )
V_33 = 0 ;
break;
V_371:
default:
F_34 ( L_7 ,
V_133 , F_20 ( V_170 . V_245 -> type ) , V_6 ) ;
break;
}
return V_33 ;
}
T_13 F_138 ( const struct V_229 * V_82 )
{
T_13 V_376 ;
do {
F_139 ( & V_376 , sizeof( T_13 ) ) ;
} while ( V_376 == 0 );
return V_376 ;
}
T_13 F_140 ( const struct V_229 * V_82 )
{
T_13 V_33 ;
F_139 ( & V_33 , sizeof( T_13 ) ) ;
return V_33 ;
}
static struct V_3 * F_141 ( struct V_5 * V_6 ,
union V_207 * V_335 ,
int V_27 )
{
T_28 V_377 ;
struct V_3 * V_33 ;
int V_20 = sizeof( V_377 ) + V_27 ;
union V_353 V_378 ;
int V_379 ;
struct V_10 * V_11 = F_4 ( V_335 -> V_270 . V_380 ) ;
V_379 = V_11 -> V_381 ( V_335 , & V_378 ) ;
if ( ! V_379 )
return NULL ;
V_20 += V_379 ;
V_33 = F_21 ( V_6 , V_63 , 0 , V_20 ) ;
if ( ! V_33 )
return NULL ;
V_377 . V_382 = F_16 ( V_6 -> V_284 ++ ) ;
V_33 -> V_21 . V_383 =
F_9 ( V_33 , sizeof( V_377 ) , & V_377 ) ;
V_33 -> V_72 . V_73 =
F_9 ( V_33 , V_379 , & V_378 ) ;
return V_33 ;
}
struct V_3 * F_142 ( struct V_5 * V_6 ,
union V_207 * V_384 ,
struct V_385 * V_31 ,
int V_386 ,
T_1 V_105 )
{
V_372 V_170 ;
struct V_3 * V_33 ;
union V_353 V_354 ;
union V_207 * V_335 ;
void * V_387 ;
struct V_10 * V_11 ;
int V_388 = sizeof( V_170 ) ;
int V_389 = 0 ;
int V_390 = 0 ;
int V_296 ;
int V_391 = 0 ;
V_387 = V_31 ;
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
V_133 , V_390 ) ;
}
}
V_33 = F_141 ( V_6 , V_384 , V_390 ) ;
if ( ! V_33 )
return NULL ;
V_387 = V_31 ;
for ( V_296 = 0 ; V_296 < V_386 ; V_296 ++ ) {
V_335 = V_387 ;
V_11 = F_4 ( V_335 -> V_270 . V_380 ) ;
V_389 = V_11 -> V_381 ( V_335 , & V_354 ) ;
V_170 . V_72 . type = V_105 ;
V_170 . V_72 . V_20 = F_8 ( V_388 + V_389 ) ;
V_170 . V_394 = V_296 ;
F_9 ( V_33 , V_388 , & V_170 ) ;
F_9 ( V_33 , V_389 , & V_354 ) ;
V_387 += V_11 -> V_392 ;
}
if ( V_105 == V_344 && V_391 ) {
V_335 = V_6 -> V_393 ;
V_11 = F_4 ( V_335 -> V_270 . V_380 ) ;
V_389 = V_11 -> V_381 ( V_335 , & V_354 ) ;
V_170 . V_72 . type = V_345 ;
V_170 . V_72 . V_20 = F_8 ( V_388 + V_389 ) ;
V_170 . V_394 = V_296 ;
F_9 ( V_33 , V_388 , & V_170 ) ;
F_9 ( V_33 , V_389 , & V_354 ) ;
}
return V_33 ;
}
struct V_3 * F_143 ( struct V_5 * V_6 ,
union V_207 * V_335 )
{
V_372 V_170 ;
struct V_3 * V_33 ;
int V_18 = sizeof( V_170 ) ;
union V_353 V_378 ;
int V_379 ;
struct V_10 * V_11 = F_4 ( V_335 -> V_270 . V_380 ) ;
V_379 = V_11 -> V_381 ( V_335 , & V_378 ) ;
if ( ! V_379 )
return NULL ;
V_18 += V_379 ;
V_33 = F_141 ( V_6 , V_335 , V_18 ) ;
if ( ! V_33 )
return NULL ;
V_170 . V_72 . type = V_320 ;
V_170 . V_72 . V_20 = F_8 ( V_18 ) ;
V_170 . V_394 = 0 ;
F_9 ( V_33 , sizeof( V_170 ) , & V_170 ) ;
F_9 ( V_33 , V_379 , & V_378 ) ;
return V_33 ;
}
static struct V_3 * F_144 ( const struct V_5 * V_6 ,
T_13 V_382 , int V_27 )
{
T_28 V_377 ;
struct V_3 * V_33 ;
int V_20 = sizeof( V_377 ) + V_27 ;
V_33 = F_21 ( V_6 , V_64 , 0 , V_20 ) ;
if ( ! V_33 )
return NULL ;
V_377 . V_382 = F_16 ( V_382 ) ;
V_33 -> V_21 . V_383 =
F_9 ( V_33 , sizeof( V_377 ) , & V_377 ) ;
return V_33 ;
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
F_20 ( V_396 -> V_72 . V_20 ) ;
}
V_397 . V_72 . type = V_401 ;
V_397 . V_72 . V_20 = F_8 ( sizeof( V_397 ) +
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
struct V_131 * V_84 ;
struct V_10 * V_11 ;
union V_207 V_335 ;
union V_353 * V_354 ;
V_354 = ( void * ) V_396 + sizeof( V_372 ) ;
if ( V_396 -> V_72 . type != V_344 &&
V_396 -> V_72 . type != V_345 &&
V_396 -> V_72 . type != V_320 )
return V_308 ;
switch ( V_354 -> V_245 . type ) {
case V_315 :
if ( ! V_6 -> V_84 . V_364 )
return V_293 ;
break;
case V_314 :
if ( ! V_6 -> V_84 . V_363 )
return V_293 ;
break;
default:
return V_293 ;
}
V_11 = F_4 ( F_123 ( V_354 -> V_245 . type ) ) ;
if ( F_60 ( ! V_11 ) )
return V_293 ;
V_11 -> V_339 ( & V_335 , V_354 , F_8 ( V_6 -> V_84 . V_279 ) , 0 ) ;
if ( ! V_11 -> V_405 ( & V_335 ) && ! V_11 -> V_373 ( & V_335 , NULL , V_377 -> V_2 ) )
return V_293 ;
switch ( V_396 -> V_72 . type ) {
case V_344 :
if ( V_11 -> V_405 ( & V_335 ) )
memcpy ( & V_335 , & V_377 -> V_210 , sizeof( V_335 ) ) ;
V_84 = F_121 ( V_6 , & V_335 , V_199 , V_359 ) ;
if ( ! V_84 )
return V_406 ;
if ( ! F_147 ( & V_84 -> V_407 , F_148 ( V_84 ) ) )
F_149 ( V_84 ) ;
V_6 -> V_408 = V_84 ;
break;
case V_345 :
if ( V_6 -> V_84 . V_409 == 1 )
return V_410 ;
if ( F_122 ( & V_377 -> V_210 , & V_335 ) )
return V_411 ;
if ( V_11 -> V_405 ( & V_335 ) ) {
F_136 ( V_6 , V_377 -> V_91 ) ;
F_150 ( V_6 ,
V_377 -> V_91 ) ;
} else
F_151 ( V_6 , & V_335 ) ;
break;
case V_320 :
if ( V_11 -> V_405 ( & V_335 ) )
memcpy ( & V_335 . V_270 , F_67 ( V_377 ) , sizeof( V_335 ) ) ;
V_84 = F_135 ( V_6 , & V_335 ) ;
if ( ! V_84 )
return V_293 ;
F_136 ( V_6 , V_84 ) ;
break;
}
return V_402 ;
}
int F_152 ( const struct V_5 * V_6 ,
struct V_166 * V_72 , void * V_165 ,
struct V_166 * * V_257 ) {
V_372 * V_396 ;
union V_30 V_170 ;
int V_20 , V_412 ;
V_170 . V_73 = ( T_11 * ) V_72 ;
while ( V_170 . V_73 <= V_165 - sizeof( T_11 ) ) {
V_20 = F_20 ( V_170 . V_245 -> V_20 ) ;
* V_257 = V_170 . V_245 ;
if ( V_170 . V_73 > V_165 - V_20 ||
V_20 < sizeof( T_11 ) )
return 0 ;
switch ( V_170 . V_245 -> type ) {
case V_344 :
case V_345 :
case V_320 :
V_396 = ( V_372 * ) V_170 . V_73 ;
V_412 = F_20 ( V_396 -> V_72 . V_20 ) ;
if ( V_412 < sizeof( V_372 ) +
sizeof( T_11 ) )
return 0 ;
break;
case V_403 :
case V_76 :
if ( V_20 != sizeof( V_372 ) )
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
struct V_3 * V_377 )
{
T_28 * V_413 ;
union V_353 * V_354 ;
V_372 * V_396 ;
struct V_3 * V_414 ;
T_1 V_395 ;
int V_20 = 0 ;
int V_109 ;
T_13 V_382 ;
int V_415 = 1 ;
V_109 = F_20 ( V_377 -> V_149 -> V_20 ) - sizeof( T_19 ) ;
V_413 = ( T_28 * ) V_377 -> V_2 -> V_162 ;
V_382 = F_102 ( V_413 -> V_382 ) ;
V_20 = sizeof( T_28 ) ;
V_354 = (union V_353 * ) ( V_377 -> V_2 -> V_162 + V_20 ) ;
V_109 -= V_20 ;
V_20 = F_20 ( V_354 -> V_245 . V_20 ) ;
V_396 = ( void * ) V_354 + V_20 ;
V_109 -= V_20 ;
V_414 = F_144 ( V_6 , V_382 , V_109 * 4 ) ;
if ( ! V_414 )
goto V_416;
while ( V_109 > 0 ) {
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
V_20 = F_20 ( V_396 -> V_72 . V_20 ) ;
V_396 = ( void * ) V_396 + V_20 ;
V_109 -= V_20 ;
}
V_416:
V_6 -> V_84 . V_284 ++ ;
if ( V_414 ) {
F_81 ( V_414 ) ;
F_154 ( & V_414 -> V_204 ,
& V_6 -> V_417 ) ;
}
return V_414 ;
}
static void F_155 ( struct V_5 * V_6 ,
V_372 * V_396 )
{
struct V_10 * V_11 ;
union V_207 V_335 ;
struct V_24 * V_25 = & V_6 -> V_8 . V_81 ;
union V_353 * V_354 ;
struct V_131 * V_91 ;
struct V_418 * V_419 ;
V_354 = ( void * ) V_396 + sizeof( V_372 ) ;
V_11 = F_4 ( F_123 ( V_354 -> V_245 . type ) ) ;
V_11 -> V_339 ( & V_335 , V_354 , F_8 ( V_25 -> V_279 ) , 0 ) ;
switch ( V_396 -> V_72 . type ) {
case V_344 :
F_156 () ;
F_38 (saddr, &bp->address_list, list) {
if ( F_122 ( & V_419 -> V_420 , & V_335 ) )
V_419 -> V_347 = V_281 ;
}
F_157 () ;
F_38 (transport, &asoc->peer.transport_addr_list,
transports) {
F_158 ( V_91 -> V_421 ) ;
V_91 -> V_421 = NULL ;
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
F_158 ( V_91 -> V_421 ) ;
V_91 -> V_421 = NULL ;
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
V_424 = F_20 ( V_414 -> V_149 -> V_20 ) -
sizeof( T_19 ) ;
V_20 = sizeof( T_28 ) ;
V_423 = ( V_372 * ) ( V_414 -> V_2 -> V_162 +
V_20 ) ;
V_424 -= V_20 ;
while ( V_424 > 0 ) {
if ( V_423 -> V_394 == V_396 -> V_394 ) {
switch ( V_423 -> V_72 . type ) {
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
V_20 = F_20 ( V_423 -> V_72 . V_20 ) ;
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
int V_33 = 0 ;
T_1 V_395 = V_402 ;
V_20 = sizeof( V_428 ) ;
V_354 = (union V_353 * ) ( V_377 -> V_2 -> V_162 + V_20 ) ;
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
V_33 = 1 ;
break;
case V_308 :
V_6 -> V_84 . V_343 |=
V_396 -> V_72 . type ;
break;
case V_425 :
case V_410 :
case V_411 :
default:
break;
}
V_20 = F_20 ( V_396 -> V_72 . V_20 ) ;
V_396 = ( void * ) V_396 + V_20 ;
V_427 -= V_20 ;
}
if ( V_422 && V_6 -> V_429 ) {
V_6 -> V_429 = 0 ;
F_162 ( V_6 -> V_84 . V_430 ) ;
}
F_75 ( & V_377 -> V_204 ) ;
F_47 ( V_377 ) ;
V_6 -> V_426 = NULL ;
return V_33 ;
}
struct V_3 * F_163 ( const struct V_5 * V_6 ,
T_13 V_431 , T_2 V_432 ,
struct V_433 * V_434 )
{
struct V_3 * V_33 = NULL ;
struct V_435 V_436 ;
struct V_433 V_437 ;
T_2 V_148 ;
int V_296 ;
V_148 = ( V_432 + 1 ) * sizeof( T_13 ) ;
V_33 = F_21 ( V_6 , V_300 , 0 , V_148 ) ;
if ( ! V_33 )
return NULL ;
V_436 . V_431 = F_16 ( V_431 ) ;
V_33 -> V_21 . V_438 =
F_9 ( V_33 , sizeof( V_436 ) , & V_436 ) ;
for ( V_296 = 0 ; V_296 < V_432 ; V_296 ++ ) {
V_437 . V_111 = V_434 [ V_296 ] . V_111 ;
V_437 . V_106 = V_434 [ V_296 ] . V_106 ;
F_9 ( V_33 , sizeof( V_437 ) , & V_437 ) ;
}
return V_33 ;
}

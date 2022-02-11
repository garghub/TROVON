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
static int F_8 ( struct V_1 * V_2 , T_1 V_9 ,
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
struct V_24 * V_24 = F_12 ( V_19 -> V_25 . V_26 ) ;
T_6 V_27 ;
union V_28 V_29 ;
T_2 V_30 ;
struct V_1 * V_31 = NULL ;
int V_32 , V_33 = 0 ;
struct V_34 * V_35 ;
T_7 V_36 ;
T_1 V_37 [ 2 ] ;
T_8 V_38 ;
T_9 V_39 ;
int V_40 = 0 ;
T_10 V_41 [ 3 ] ;
T_11 * V_42 = NULL ,
* V_43 = NULL ;
V_31 = NULL ;
V_29 = F_13 ( V_21 , & V_33 , V_22 ) ;
V_27 . V_44 = F_14 ( V_19 -> V_45 . V_46 ) ;
V_27 . V_47 = F_14 ( V_19 -> V_48 ) ;
V_27 . V_49 = F_6 ( V_19 -> V_45 . V_50 ) ;
V_27 . V_51 = F_6 ( V_19 -> V_45 . V_52 ) ;
V_27 . V_53 = F_14 ( V_19 -> V_45 . V_53 ) ;
V_35 = F_15 ( V_19 -> V_25 . V_26 ) ;
V_32 = V_35 -> V_54 -> V_55 ( V_35 , V_37 ) ;
V_30 = sizeof( V_27 ) + V_33 ;
V_30 += F_16 ( F_17 ( V_32 ) ) ;
V_30 += sizeof( V_56 ) ;
if ( V_24 -> V_57 . V_58 )
V_30 += sizeof( V_59 ) ;
if ( V_24 -> V_57 . V_60 ) {
V_41 [ V_40 ] = V_61 ;
V_41 [ V_40 + 1 ] = V_62 ;
V_40 += 2 ;
}
if ( V_35 -> V_63 )
V_30 += sizeof( V_38 ) ;
V_30 += V_23 ;
if ( V_24 -> V_57 . V_64 ) {
V_30 += sizeof( V_19 -> V_45 . V_65 ) ;
V_43 = ( T_11 * ) V_19 -> V_45 . V_43 ;
if ( V_43 -> V_14 )
V_30 += F_16 ( F_18 ( V_43 -> V_14 ) ) ;
else
V_43 = NULL ;
V_42 = ( T_11 * ) V_19 -> V_45 . V_42 ;
if ( V_42 -> V_14 )
V_30 += F_16 ( F_18 ( V_42 -> V_14 ) ) ;
else
V_42 = NULL ;
V_41 [ V_40 ] = V_66 ;
V_40 += 1 ;
}
if ( V_40 )
V_30 += F_16 ( sizeof( T_9 ) +
V_40 ) ;
V_31 = F_19 ( V_19 , V_67 , 0 , V_30 ) ;
if ( ! V_31 )
goto V_68;
V_31 -> V_15 . V_69 =
F_7 ( V_31 , sizeof( V_27 ) , & V_27 ) ;
V_31 -> V_70 . V_71 =
F_7 ( V_31 , V_33 , V_29 . V_71 ) ;
V_36 . V_70 . type = V_72 ;
V_36 . V_70 . V_14 = F_6 ( F_17 ( V_32 ) ) ;
F_7 ( V_31 , sizeof( V_36 ) , & V_36 ) ;
F_7 ( V_31 , V_32 * sizeof( T_4 ) , & V_37 ) ;
F_7 ( V_31 , sizeof( V_56 ) , & V_56 ) ;
if ( V_40 ) {
V_39 . V_70 . type = V_73 ;
V_39 . V_70 . V_14 =
F_6 ( sizeof( T_9 ) + V_40 ) ;
F_7 ( V_31 , sizeof( T_9 ) ,
& V_39 ) ;
F_20 ( V_31 , V_40 , V_41 ) ;
}
if ( V_24 -> V_57 . V_58 )
F_7 ( V_31 , sizeof( V_59 ) , & V_59 ) ;
if ( V_35 -> V_63 ) {
V_38 . V_70 . type = V_74 ;
V_38 . V_70 . V_14 = F_6 ( sizeof( V_38 ) ) ;
V_38 . V_63 = F_14 ( V_35 -> V_63 ) ;
F_7 ( V_31 , sizeof( V_38 ) , & V_38 ) ;
}
if ( V_24 -> V_57 . V_64 ) {
F_7 ( V_31 , sizeof( V_19 -> V_45 . V_65 ) ,
V_19 -> V_45 . V_65 ) ;
if ( V_43 )
F_7 ( V_31 , F_18 ( V_43 -> V_14 ) ,
V_43 ) ;
if ( V_42 )
F_7 ( V_31 , F_18 ( V_42 -> V_14 ) ,
V_42 ) ;
}
V_68:
F_21 ( V_29 . V_71 ) ;
return V_31 ;
}
struct V_1 * F_22 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
T_5 V_22 , int V_75 )
{
T_6 V_76 ;
struct V_1 * V_31 ;
union V_28 V_29 ;
struct V_34 * V_35 ;
int V_33 ;
T_12 * V_77 ;
int V_78 ;
T_2 V_30 ;
T_8 V_38 ;
T_9 V_39 ;
int V_40 = 0 ;
T_10 V_41 [ 3 ] ;
T_11 * V_42 = NULL ,
* V_43 = NULL ,
* V_65 = NULL ;
V_31 = NULL ;
V_29 = F_13 ( & V_19 -> V_25 . V_79 , & V_33 , V_22 ) ;
V_76 . V_44 = F_14 ( V_19 -> V_45 . V_46 ) ;
V_76 . V_47 = F_14 ( V_19 -> V_48 ) ;
V_76 . V_49 = F_6 ( V_19 -> V_45 . V_50 ) ;
V_76 . V_51 = F_6 ( V_19 -> V_45 . V_52 ) ;
V_76 . V_53 = F_14 ( V_19 -> V_45 . V_53 ) ;
V_77 = F_23 ( V_19 -> V_80 , V_19 , V_2 , & V_78 ,
V_29 . V_71 , V_33 ) ;
if ( ! V_77 )
goto V_81;
V_35 = F_15 ( V_19 -> V_25 . V_26 ) ;
V_30 = sizeof( V_76 ) + V_33 + V_78 + V_75 ;
if ( V_19 -> V_82 . V_83 )
V_30 += sizeof( V_56 ) ;
if ( V_19 -> V_82 . V_84 )
V_30 += sizeof( V_59 ) ;
if ( V_19 -> V_82 . V_85 ) {
V_41 [ V_40 ] = V_61 ;
V_41 [ V_40 + 1 ] = V_62 ;
V_40 += 2 ;
}
if ( V_35 -> V_63 )
V_30 += sizeof( V_38 ) ;
if ( V_19 -> V_82 . V_86 ) {
V_65 = ( T_11 * ) V_19 -> V_45 . V_65 ;
V_30 += F_18 ( V_65 -> V_14 ) ;
V_43 = ( T_11 * ) V_19 -> V_45 . V_43 ;
if ( V_43 -> V_14 )
V_30 += F_16 ( F_18 ( V_43 -> V_14 ) ) ;
else
V_43 = NULL ;
V_42 = ( T_11 * ) V_19 -> V_45 . V_42 ;
if ( V_42 -> V_14 )
V_30 += F_16 ( F_18 ( V_42 -> V_14 ) ) ;
else
V_42 = NULL ;
V_41 [ V_40 ] = V_66 ;
V_40 += 1 ;
}
if ( V_40 )
V_30 += F_16 ( sizeof( T_9 ) +
V_40 ) ;
V_31 = F_19 ( V_19 , V_87 , 0 , V_30 ) ;
if ( ! V_31 )
goto V_88;
V_31 -> V_89 = V_2 -> V_89 ;
V_31 -> V_15 . V_69 =
F_7 ( V_31 , sizeof( V_76 ) , & V_76 ) ;
V_31 -> V_70 . V_71 = F_7 ( V_31 , V_33 , V_29 . V_71 ) ;
F_7 ( V_31 , V_78 , V_77 ) ;
if ( V_19 -> V_82 . V_83 )
F_7 ( V_31 , sizeof( V_56 ) , & V_56 ) ;
if ( V_40 ) {
V_39 . V_70 . type = V_73 ;
V_39 . V_70 . V_14 =
F_6 ( sizeof( T_9 ) + V_40 ) ;
F_7 ( V_31 , sizeof( T_9 ) ,
& V_39 ) ;
F_20 ( V_31 , V_40 , V_41 ) ;
}
if ( V_19 -> V_82 . V_84 )
F_7 ( V_31 , sizeof( V_59 ) , & V_59 ) ;
if ( V_35 -> V_63 ) {
V_38 . V_70 . type = V_74 ;
V_38 . V_70 . V_14 = F_6 ( sizeof( V_38 ) ) ;
V_38 . V_63 = F_14 ( V_35 -> V_63 ) ;
F_7 ( V_31 , sizeof( V_38 ) , & V_38 ) ;
}
if ( V_19 -> V_82 . V_86 ) {
F_7 ( V_31 , F_18 ( V_65 -> V_14 ) ,
V_65 ) ;
if ( V_43 )
F_7 ( V_31 , F_18 ( V_43 -> V_14 ) ,
V_43 ) ;
if ( V_42 )
F_7 ( V_31 , F_18 ( V_42 -> V_14 ) ,
V_42 ) ;
}
V_31 -> V_19 = (struct V_18 * ) V_19 ;
V_88:
F_21 ( V_77 ) ;
V_81:
F_21 ( V_29 . V_71 ) ;
return V_31 ;
}
struct V_1 * F_24 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
struct V_1 * V_31 ;
void * V_77 ;
int V_78 ;
V_77 = V_19 -> V_82 . V_77 ;
V_78 = V_19 -> V_82 . V_78 ;
V_31 = F_19 ( V_19 , V_90 , 0 , V_78 ) ;
if ( ! V_31 )
goto V_68;
V_31 -> V_15 . V_91 =
F_7 ( V_31 , V_78 , V_77 ) ;
if ( V_2 )
V_31 -> V_89 = V_2 -> V_89 ;
V_68:
return V_31 ;
}
struct V_1 * F_25 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
struct V_1 * V_31 ;
V_31 = F_19 ( V_19 , V_92 , 0 , 0 ) ;
if ( V_31 && V_2 )
V_31 -> V_89 = V_2 -> V_89 ;
return V_31 ;
}
struct V_1 * F_26 ( const struct V_18 * V_19 ,
const T_13 V_93 ,
const struct V_1 * V_2 )
{
struct V_1 * V_31 ;
T_14 V_94 ;
V_94 . V_93 = F_14 ( V_93 ) ;
V_31 = F_19 ( V_19 , V_95 , 0 ,
sizeof( T_14 ) ) ;
if ( ! V_31 )
goto V_68;
V_31 -> V_15 . V_96 =
F_7 ( V_31 , sizeof( V_94 ) , & V_94 ) ;
if ( V_2 )
V_31 -> V_89 = V_2 -> V_89 ;
V_68:
return V_31 ;
}
struct V_1 * F_27 ( const struct V_18 * V_19 ,
const T_13 V_93 )
{
struct V_1 * V_31 ;
T_15 V_97 ;
V_97 . V_93 = F_14 ( V_93 ) ;
V_31 = F_19 ( V_19 , V_98 , 0 ,
sizeof( T_15 ) ) ;
if ( ! V_31 )
goto V_68;
V_31 -> V_15 . V_99 =
F_7 ( V_31 , sizeof( V_97 ) , & V_97 ) ;
V_68:
return V_31 ;
}
struct V_1 * F_28 ( struct V_18 * V_19 ,
const struct V_100 * V_101 ,
int V_102 , T_10 V_103 , T_4 V_104 )
{
struct V_1 * V_31 ;
struct V_105 V_106 ;
int V_107 ;
V_106 . V_108 = 0 ;
V_106 . V_109 = F_6 ( V_101 -> V_110 ) ;
V_106 . V_111 = V_101 -> V_112 ;
if ( V_101 -> V_113 & V_114 ) {
V_103 |= V_115 ;
V_106 . V_104 = 0 ;
} else
V_106 . V_104 = F_6 ( V_104 ) ;
V_107 = sizeof( V_106 ) + V_102 ;
V_31 = F_19 ( V_19 , V_116 , V_103 , V_107 ) ;
if ( ! V_31 )
goto V_68;
V_31 -> V_15 . V_117 = F_7 ( V_31 , sizeof( V_106 ) , & V_106 ) ;
memcpy ( & V_31 -> V_101 , V_101 , sizeof( struct V_100 ) ) ;
V_68:
return V_31 ;
}
struct V_1 * F_29 ( const struct V_18 * V_19 )
{
struct V_1 * V_31 ;
struct V_118 V_119 ;
int V_12 ;
T_13 V_120 ;
T_4 V_121 , V_122 ;
struct V_18 * V_123 = (struct V_18 * ) V_19 ;
struct V_124 * V_125 = (struct V_124 * ) & V_19 -> V_82 . V_126 ;
struct V_127 V_128 [ V_129 ] ;
struct V_130 * V_131 ;
memset ( V_128 , 0 , sizeof( V_128 ) ) ;
V_120 = F_30 ( V_125 ) ;
F_31 ( L_1 , V_120 ) ;
V_121 = F_32 ( V_125 , V_128 ) ;
V_122 = F_33 ( V_125 ) ;
V_119 . V_132 = F_14 ( V_120 ) ;
V_119 . V_47 = F_14 ( V_19 -> V_47 ) ;
V_119 . V_133 = F_6 ( V_121 ) ;
V_119 . V_122 = F_6 ( V_122 ) ;
V_12 = sizeof( V_119 )
+ sizeof( struct V_127 ) * V_121
+ sizeof( T_13 ) * V_122 ;
V_31 = F_19 ( V_19 , V_134 , 0 , V_12 ) ;
if ( ! V_31 )
goto V_68;
V_31 -> V_89 = V_19 -> V_82 . V_135 ;
V_31 -> V_15 . V_136 =
F_7 ( V_31 , sizeof( V_119 ) , & V_119 ) ;
if ( V_121 )
F_7 ( V_31 , sizeof( T_13 ) * V_121 ,
V_128 ) ;
if ( V_122 ) {
V_123 -> V_137 . V_138 += V_122 ;
F_7 ( V_31 , sizeof( T_13 ) * V_122 ,
F_34 ( V_125 ) ) ;
}
if ( ++ V_123 -> V_82 . V_139 == 0 ) {
F_35 (trans, &asoc->peer.transport_addr_list,
transports)
V_131 -> V_139 = 0 ;
V_123 -> V_82 . V_139 = 1 ;
}
V_68:
return V_31 ;
}
struct V_1 * F_36 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
struct V_1 * V_31 ;
T_16 V_140 ;
T_13 V_120 ;
V_120 = F_30 ( & V_19 -> V_82 . V_126 ) ;
V_140 . V_132 = F_14 ( V_120 ) ;
V_31 = F_19 ( V_19 , V_141 , 0 ,
sizeof( T_16 ) ) ;
if ( ! V_31 )
goto V_68;
V_31 -> V_15 . V_142 =
F_7 ( V_31 , sizeof( V_140 ) , & V_140 ) ;
if ( V_2 )
V_31 -> V_89 = V_2 -> V_89 ;
V_68:
return V_31 ;
}
struct V_1 * F_37 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
struct V_1 * V_31 ;
V_31 = F_19 ( V_19 , V_143 , 0 , 0 ) ;
if ( V_31 && V_2 )
V_31 -> V_89 = V_2 -> V_89 ;
return V_31 ;
}
struct V_1 * F_38 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
struct V_1 * V_31 ;
T_10 V_103 = 0 ;
V_103 |= V_19 ? 0 : V_144 ;
V_31 = F_19 ( V_19 , V_145 , V_103 , 0 ) ;
if ( V_31 && V_2 )
V_31 -> V_89 = V_2 -> V_89 ;
return V_31 ;
}
struct V_1 * F_39 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
const T_2 V_146 )
{
struct V_1 * V_31 ;
T_10 V_103 = 0 ;
if ( ! V_19 ) {
if ( V_2 && V_2 -> V_147 &&
V_2 -> V_147 -> type == V_67 )
V_103 = 0 ;
else
V_103 = V_144 ;
}
V_31 = F_19 ( V_19 , V_148 , V_103 , V_146 ) ;
if ( V_31 && V_2 )
V_31 -> V_89 = V_2 -> V_89 ;
return V_31 ;
}
struct V_1 * F_40 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 , T_13 V_108 )
{
struct V_1 * V_31 ;
T_17 V_149 ;
V_31 = F_39 ( V_19 , V_2 , sizeof( T_3 )
+ sizeof( V_108 ) ) ;
if ( ! V_31 )
goto V_150;
V_149 = F_14 ( V_108 ) ;
F_5 ( V_31 , V_151 , sizeof( V_149 ) ) ;
F_7 ( V_31 , sizeof( V_149 ) , ( const void * ) & V_149 ) ;
if ( V_2 )
V_31 -> V_89 = V_2 -> V_89 ;
V_150:
return V_31 ;
}
struct V_1 * F_41 ( const struct V_18 * V_19 ,
const struct V_152 * V_153 ,
T_2 V_10 )
{
struct V_1 * V_31 ;
void * V_149 = NULL ;
int V_11 ;
V_31 = F_39 ( V_19 , NULL , sizeof( T_3 ) + V_10 ) ;
if ( ! V_31 )
goto V_154;
if ( V_10 ) {
V_149 = F_42 ( V_10 , V_155 ) ;
if ( ! V_149 )
goto V_156;
V_11 = F_43 ( V_149 , V_153 -> V_157 , V_10 ) ;
if ( V_11 < 0 )
goto V_158;
}
F_5 ( V_31 , V_159 , V_10 ) ;
F_7 ( V_31 , V_10 , V_149 ) ;
if ( V_10 )
F_21 ( V_149 ) ;
return V_31 ;
V_158:
F_21 ( V_149 ) ;
V_156:
F_44 ( V_31 ) ;
V_31 = NULL ;
V_154:
return V_31 ;
}
static void * F_20 ( struct V_1 * V_2 , int V_12 ,
const void * V_160 )
{
void * V_161 ;
int V_162 = F_18 ( V_2 -> V_147 -> V_14 ) ;
V_161 = F_45 ( V_2 -> V_6 , V_12 ) ;
if ( V_160 )
memcpy ( V_161 , V_160 , V_12 ) ;
else
memset ( V_161 , 0 , V_12 ) ;
V_2 -> V_147 -> V_14 = F_6 ( V_162 + V_12 ) ;
V_2 -> V_163 = F_46 ( V_2 -> V_6 ) ;
return V_161 ;
}
struct V_1 * F_47 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
const T_10 * V_149 ,
const T_2 V_10 )
{
struct V_1 * V_31 ;
struct V_164 V_165 ;
V_31 = F_39 ( V_19 , V_2 , sizeof( T_3 ) + V_10
+ sizeof( T_11 ) ) ;
if ( ! V_31 )
goto V_166;
F_5 ( V_31 , V_167 , V_10
+ sizeof( T_11 ) ) ;
V_165 . type = F_6 ( V_2 -> V_147 -> type ) ;
V_165 . V_14 = V_2 -> V_147 -> V_14 ;
F_7 ( V_31 , V_10 , V_149 ) ;
F_20 ( V_31 , sizeof( T_11 ) , & V_165 ) ;
V_166:
return V_31 ;
}
struct V_1 * F_48 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
struct V_164 * V_168 )
{
struct V_1 * V_31 ;
static const char error [] = L_2 ;
T_2 V_169 = sizeof( error ) + sizeof( T_3 ) +
sizeof( T_11 ) ;
V_31 = F_39 ( V_19 , V_2 , V_169 ) ;
if ( ! V_31 )
goto V_68;
F_5 ( V_31 , V_167 ,
sizeof( error ) + sizeof( T_11 ) ) ;
F_7 ( V_31 , sizeof( error ) , error ) ;
F_20 ( V_31 , sizeof( T_11 ) , V_168 ) ;
V_68:
return V_31 ;
}
struct V_1 * F_49 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
struct V_1 * V_31 ;
static const char error [] = L_3 ;
T_2 V_169 = sizeof( error ) + sizeof( T_3 ) ;
V_31 = F_39 ( V_19 , V_2 , V_169 ) ;
if ( ! V_31 )
goto V_68;
F_5 ( V_31 , V_167 , sizeof( error ) ) ;
F_7 ( V_31 , sizeof( error ) , error ) ;
V_68:
return V_31 ;
}
struct V_1 * F_50 ( const struct V_18 * V_19 ,
const struct V_130 * V_89 )
{
struct V_1 * V_31 ;
T_18 V_170 ;
V_31 = F_19 ( V_19 , V_171 , 0 , sizeof( V_170 ) ) ;
if ( ! V_31 )
goto V_68;
V_170 . V_70 . type = V_172 ;
V_170 . V_70 . V_14 = F_6 ( sizeof( T_18 ) ) ;
V_170 . V_173 = V_89 -> V_174 ;
V_170 . V_175 = V_176 ;
V_170 . V_177 = V_89 -> V_177 ;
V_31 -> V_89 = (struct V_130 * ) V_89 ;
V_31 -> V_15 . V_178 = F_7 ( V_31 , sizeof( V_170 ) ,
& V_170 ) ;
V_68:
return V_31 ;
}
struct V_1 * F_51 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
const void * V_149 , const T_2 V_10 )
{
struct V_1 * V_31 ;
V_31 = F_19 ( V_19 , V_179 , 0 , V_10 ) ;
if ( ! V_31 )
goto V_68;
V_31 -> V_15 . V_178 = F_7 ( V_31 , V_10 , V_149 ) ;
if ( V_2 )
V_31 -> V_89 = V_2 -> V_89 ;
V_68:
return V_31 ;
}
static struct V_1 * F_52 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
T_2 V_180 )
{
struct V_1 * V_31 ;
V_31 = F_19 ( V_19 , V_181 , 0 ,
sizeof( T_3 ) + V_180 ) ;
if ( ! V_31 )
goto V_68;
if ( V_2 )
V_31 -> V_89 = V_2 -> V_89 ;
V_68:
return V_31 ;
}
static inline struct V_1 * F_53 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
T_2 V_180 = V_19 ? V_19 -> V_182 : 0 ;
if ( ! V_180 )
V_180 = V_183 ;
return F_52 ( V_19 , V_2 , V_180 ) ;
}
struct V_1 * F_54 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
T_1 V_9 , const void * V_149 ,
T_2 V_10 , T_2 V_184 )
{
struct V_1 * V_31 ;
V_31 = F_52 ( V_19 , V_2 , V_10 + V_184 ) ;
if ( ! V_31 )
goto V_68;
F_5 ( V_31 , V_9 , V_10 + V_184 ) ;
F_7 ( V_31 , V_10 , V_149 ) ;
if ( V_184 )
F_20 ( V_31 , V_184 , NULL ) ;
V_68:
return V_31 ;
}
struct V_1 * F_55 ( const struct V_18 * V_19 )
{
struct V_1 * V_31 ;
struct V_185 * V_186 ;
struct V_187 V_188 ;
T_10 * V_189 ;
V_186 = F_56 ( V_19 ) ;
if ( F_57 ( ! V_186 ) )
return NULL ;
V_31 = F_19 ( V_19 , V_66 , 0 ,
V_186 -> V_190 + sizeof( V_191 ) ) ;
if ( ! V_31 )
return NULL ;
V_188 . V_192 = F_6 ( V_186 -> V_192 ) ;
V_188 . V_193 = F_6 ( V_19 -> V_194 ) ;
V_31 -> V_15 . V_188 = F_7 ( V_31 , sizeof( V_191 ) ,
& V_188 ) ;
V_189 = F_45 ( V_31 -> V_6 , V_186 -> V_190 ) ;
memset ( V_189 , 0 , V_186 -> V_190 ) ;
V_31 -> V_147 -> V_14 =
F_6 ( F_18 ( V_31 -> V_147 -> V_14 ) + V_186 -> V_190 ) ;
V_31 -> V_163 = F_46 ( V_31 -> V_6 ) ;
return V_31 ;
}
struct V_1 * F_58 ( struct V_195 * V_6 ,
const struct V_18 * V_19 ,
struct V_196 * V_26 )
{
struct V_1 * V_31 ;
V_31 = F_59 ( V_197 , V_198 ) ;
if ( ! V_31 )
goto V_68;
if ( ! V_26 ) {
F_31 ( L_4 , V_6 ) ;
}
F_60 ( & V_31 -> V_199 ) ;
V_31 -> V_6 = V_6 ;
V_31 -> V_19 = (struct V_18 * ) V_19 ;
V_31 -> V_200 = 0 ;
V_31 -> V_201 = 0 ;
V_31 -> V_202 = 0 ;
V_31 -> V_175 = 0 ;
V_31 -> V_203 = 1 ;
V_31 -> V_204 = 0 ;
V_31 -> V_205 = 0 ;
V_31 -> V_206 = 0 ;
V_31 -> V_207 = 0 ;
V_31 -> V_208 = 0 ;
V_31 -> V_209 = V_210 ;
V_31 -> V_153 = NULL ;
F_60 ( & V_31 -> V_211 ) ;
F_60 ( & V_31 -> V_212 ) ;
F_61 ( V_2 ) ;
F_62 ( & V_31 -> V_213 , 1 ) ;
V_68:
return V_31 ;
}
void F_63 ( struct V_1 * V_2 , union V_214 * V_215 ,
union V_214 * V_216 )
{
memcpy ( & V_2 -> V_217 , V_215 , sizeof( union V_214 ) ) ;
memcpy ( & V_2 -> V_216 , V_216 , sizeof( union V_214 ) ) ;
}
const union V_214 * F_64 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_89 ) {
return & V_2 -> V_89 -> V_174 ;
} else {
return & V_2 -> V_217 ;
}
}
T_19
struct V_1 * F_19 ( const struct V_18 * V_19 ,
T_10 type , T_10 V_103 , int V_10 )
{
struct V_1 * V_31 ;
T_20 * V_147 ;
struct V_195 * V_6 ;
struct V_196 * V_26 ;
V_6 = F_65 ( F_16 ( sizeof( T_20 ) + V_10 ) ,
V_198 ) ;
if ( ! V_6 )
goto V_68;
V_147 = ( T_20 * ) F_45 ( V_6 , sizeof( T_20 ) ) ;
V_147 -> type = type ;
V_147 -> V_103 = V_103 ;
V_147 -> V_14 = F_6 ( sizeof( T_20 ) ) ;
V_26 = V_19 ? V_19 -> V_25 . V_26 : NULL ;
V_31 = F_58 ( V_6 , V_19 , V_26 ) ;
if ( ! V_31 ) {
F_66 ( V_6 ) ;
goto V_68;
}
V_31 -> V_147 = V_147 ;
V_31 -> V_163 = ( ( T_10 * ) V_147 ) + sizeof( struct V_218 ) ;
if ( F_67 ( type , V_19 ) )
V_31 -> V_219 = 1 ;
V_6 -> V_26 = V_26 ;
return V_31 ;
V_68:
return NULL ;
}
static void F_68 ( struct V_1 * V_2 )
{
F_69 ( ! F_70 ( & V_2 -> V_199 ) ) ;
F_71 ( & V_2 -> V_211 ) ;
F_72 ( V_2 -> V_6 ) ;
F_73 ( V_2 ) ;
F_74 ( V_197 , V_2 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_153 )
F_75 ( V_2 -> V_153 ) ;
F_76 ( V_2 ) ;
}
void F_77 ( struct V_1 * V_220 )
{
F_78 ( & V_220 -> V_213 ) ;
}
void F_76 ( struct V_1 * V_220 )
{
if ( F_79 ( & V_220 -> V_213 ) )
F_68 ( V_220 ) ;
}
void * F_7 ( struct V_1 * V_2 , int V_12 , const void * V_160 )
{
void * V_161 ;
void * V_221 ;
int V_162 = F_18 ( V_2 -> V_147 -> V_14 ) ;
int V_222 = F_16 ( V_162 ) - V_162 ;
V_221 = F_45 ( V_2 -> V_6 , V_222 ) ;
V_161 = F_45 ( V_2 -> V_6 , V_12 ) ;
memset ( V_221 , 0 , V_222 ) ;
memcpy ( V_161 , V_160 , V_12 ) ;
V_2 -> V_147 -> V_14 = F_6 ( V_162 + V_222 + V_12 ) ;
V_2 -> V_163 = F_46 ( V_2 -> V_6 ) ;
return V_161 ;
}
void * F_10 ( struct V_1 * V_2 ,
int V_12 , const void * V_160 )
{
if ( F_9 ( V_2 -> V_6 ) >= V_12 )
return F_7 ( V_2 , V_12 , V_160 ) ;
else
return NULL ;
}
int F_80 ( struct V_1 * V_2 , int V_223 , int V_12 ,
struct V_224 * V_160 )
{
T_10 * V_161 ;
int V_11 = 0 ;
V_161 = F_45 ( V_2 -> V_6 , V_12 ) ;
if ( ( V_11 = F_81 ( V_161 , V_160 , V_223 , V_12 ) ) )
goto V_225;
V_2 -> V_147 -> V_14 =
F_6 ( F_18 ( V_2 -> V_147 -> V_14 ) + V_12 ) ;
V_2 -> V_163 = F_46 ( V_2 -> V_6 ) ;
V_225:
return V_11 ;
}
void F_82 ( struct V_1 * V_2 )
{
struct V_226 * V_153 ;
struct V_1 * V_227 ;
struct V_228 * V_109 ;
T_4 V_104 ;
T_4 V_229 ;
if ( V_2 -> V_201 )
return;
V_229 = F_18 ( V_2 -> V_15 . V_117 -> V_109 ) ;
V_109 = & V_2 -> V_19 -> V_230 -> V_225 ;
V_153 = V_2 -> V_153 ;
F_35 (lchunk, &msg->chunks, frag_list) {
if ( V_227 -> V_147 -> V_103 & V_115 ) {
V_104 = 0 ;
} else {
if ( V_227 -> V_147 -> V_103 & V_231 )
V_104 = F_83 ( V_109 , V_229 ) ;
else
V_104 = F_84 ( V_109 , V_229 ) ;
}
V_227 -> V_15 . V_117 -> V_104 = F_6 ( V_104 ) ;
V_227 -> V_201 = 1 ;
}
}
void F_85 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_200 ) {
V_2 -> V_15 . V_117 -> V_108 =
F_14 ( F_86 ( V_2 -> V_19 ) ) ;
V_2 -> V_200 = 1 ;
}
}
struct V_18 * F_87 ( const struct V_232 * V_80 ,
struct V_1 * V_2 ,
T_5 V_22 )
{
struct V_18 * V_19 ;
struct V_195 * V_6 ;
T_21 V_233 ;
struct V_3 * V_4 ;
V_233 = F_88 ( F_64 ( V_2 ) ) ;
V_19 = F_89 ( V_80 , V_80 -> V_25 . V_26 , V_233 , V_22 ) ;
if ( ! V_19 )
goto V_68;
V_19 -> V_234 = 1 ;
V_6 = V_2 -> V_6 ;
V_4 = F_2 ( F_3 ( F_4 ( V_6 ) -> V_7 ) ) ;
if ( F_57 ( ! V_4 ) )
goto V_235;
V_4 -> V_236 ( & V_19 -> V_45 . V_237 , V_6 , 1 ) ;
V_68:
return V_19 ;
V_235:
F_90 ( V_19 ) ;
return NULL ;
}
static T_12 * F_23 ( const struct V_232 * V_80 ,
const struct V_18 * V_19 ,
const struct V_1 * V_238 ,
int * V_78 ,
const T_10 * V_239 , int V_33 )
{
T_12 * V_31 ;
struct V_240 * V_77 ;
struct V_241 V_242 ;
int V_243 , V_244 ;
V_243 = sizeof( T_11 ) +
( sizeof( struct V_240 ) -
sizeof( struct V_245 ) ) ;
V_244 = sizeof( struct V_245 )
+ F_18 ( V_238 -> V_147 -> V_14 ) + V_33 ;
if ( V_244 % V_246 )
V_244 += V_246
- ( V_244 % V_246 ) ;
* V_78 = V_243 + V_244 ;
V_31 = F_91 ( * V_78 , V_198 ) ;
if ( ! V_31 )
goto V_68;
V_77 = (struct V_240 * ) V_31 -> V_247 ;
V_31 -> V_248 . type = V_249 ;
V_31 -> V_248 . V_14 = F_6 ( * V_78 ) ;
V_77 -> V_45 = V_19 -> V_45 ;
V_77 -> V_45 . V_250 = V_33 ;
V_77 -> V_45 . V_84 = V_19 -> V_82 . V_84 ;
V_77 -> V_45 . V_63 = V_19 -> V_82 . V_63 ;
F_92 ( & V_77 -> V_45 . V_251 ) ;
F_93 ( V_19 -> V_252 , V_77 -> V_45 . V_251 ) ;
memcpy ( & V_77 -> V_45 . V_253 [ 0 ] , V_238 -> V_147 ,
F_18 ( V_238 -> V_147 -> V_14 ) ) ;
memcpy ( ( T_10 * ) & V_77 -> V_45 . V_253 [ 0 ] +
F_18 ( V_238 -> V_147 -> V_14 ) , V_239 , V_33 ) ;
if ( F_15 ( V_80 -> V_25 . V_26 ) -> V_189 ) {
struct V_254 V_255 ;
F_94 ( & V_242 , & V_77 -> V_45 , V_244 ) ;
V_255 . V_256 = F_15 ( V_80 -> V_25 . V_26 ) -> V_189 ;
V_255 . V_103 = 0 ;
if ( F_95 ( V_255 . V_256 , V_80 -> V_257 ,
sizeof( V_80 -> V_257 ) ) ||
F_96 ( & V_255 , & V_242 , V_244 , V_77 -> V_258 ) )
goto V_259;
}
return V_31 ;
V_259:
F_21 ( V_31 ) ;
V_68:
* V_78 = 0 ;
return NULL ;
}
struct V_18 * F_97 (
const struct V_232 * V_80 ,
const struct V_18 * V_19 ,
struct V_1 * V_2 , T_5 V_22 ,
int * error , struct V_1 * * V_260 )
{
struct V_18 * V_31 = NULL ;
struct V_240 * V_77 ;
struct V_245 * V_261 ;
int V_243 , V_244 , V_262 ;
T_10 * V_263 = V_80 -> V_263 ;
struct V_241 V_242 ;
unsigned int V_12 ;
T_21 V_233 ;
struct V_195 * V_6 = V_2 -> V_6 ;
struct V_264 V_265 ;
struct V_254 V_255 ;
V_243 = sizeof( T_20 ) +
( sizeof( struct V_240 ) -
sizeof( struct V_245 ) ) ;
V_244 = F_18 ( V_2 -> V_147 -> V_14 ) - V_243 ;
V_262 = V_243 + sizeof( struct V_245 ) ;
V_12 = F_18 ( V_2 -> V_147 -> V_14 ) ;
if ( V_12 < V_262 + sizeof( struct V_218 ) )
goto V_266;
if ( V_244 % V_246 )
goto V_266;
V_77 = V_2 -> V_15 . V_91 ;
V_261 = & V_77 -> V_45 ;
if ( ! F_15 ( V_80 -> V_25 . V_26 ) -> V_189 )
goto V_267;
F_94 ( & V_242 , V_261 , V_244 ) ;
V_255 . V_256 = F_15 ( V_80 -> V_25 . V_26 ) -> V_189 ;
V_255 . V_103 = 0 ;
memset ( V_263 , 0x00 , V_268 ) ;
if ( F_95 ( V_255 . V_256 , V_80 -> V_257 ,
sizeof( V_80 -> V_257 ) ) ||
F_96 ( & V_255 , & V_242 , V_244 , V_263 ) ) {
* error = - V_269 ;
goto V_235;
}
if ( memcmp ( V_263 , V_77 -> V_258 , V_268 ) ) {
* error = - V_270 ;
goto V_235;
}
V_267:
if ( F_98 ( V_2 -> V_271 -> V_272 ) != V_261 -> V_46 ) {
* error = - V_273 ;
goto V_235;
}
if ( V_2 -> V_271 -> V_217 != V_261 -> V_237 . V_274 . V_275 ||
F_18 ( V_2 -> V_271 -> V_216 ) != V_261 -> V_276 ) {
* error = - V_277 ;
goto V_235;
}
if ( F_99 ( V_80 -> V_25 . V_26 , V_278 ) )
F_100 ( V_6 , & V_265 ) ;
else
F_92 ( & V_265 ) ;
if ( ! V_19 && F_101 ( V_261 -> V_251 , V_265 ) ) {
V_12 = F_18 ( V_2 -> V_147 -> V_14 ) ;
* V_260 = F_52 ( V_19 , V_2 , V_12 ) ;
if ( * V_260 ) {
T_22 V_279 = ( V_265 . V_280 -
V_261 -> V_251 . V_280 ) * 1000000L +
V_265 . V_281 - V_261 -> V_251 . V_281 ;
T_17 V_282 = F_14 ( V_279 ) ;
F_5 ( * V_260 , V_283 ,
sizeof( V_282 ) ) ;
F_7 ( * V_260 , sizeof( V_282 ) , & V_282 ) ;
* error = - V_284 ;
} else
* error = - V_269 ;
goto V_235;
}
V_233 = F_88 ( F_64 ( V_2 ) ) ;
V_31 = F_89 ( V_80 , V_80 -> V_25 . V_26 , V_233 , V_22 ) ;
if ( ! V_31 ) {
* error = - V_269 ;
goto V_235;
}
V_31 -> V_82 . V_285 = F_18 ( V_2 -> V_271 -> V_217 ) ;
memcpy ( & V_31 -> V_45 , V_261 , sizeof( * V_261 ) ) ;
if ( F_102 ( V_31 , V_261 ,
V_198 ) < 0 ) {
* error = - V_269 ;
goto V_235;
}
if ( F_70 ( & V_31 -> V_25 . V_79 . V_286 ) ) {
F_103 ( & V_31 -> V_25 . V_79 , & V_2 -> V_216 ,
V_287 , V_198 ) ;
}
V_31 -> V_288 = V_31 -> V_45 . V_53 ;
V_31 -> V_289 = V_31 -> V_288 - 1 ;
V_31 -> V_290 = V_31 -> V_45 . V_53 ;
V_31 -> V_291 = V_31 -> V_289 ;
V_31 -> V_82 . V_84 = V_31 -> V_45 . V_84 ;
V_31 -> V_82 . V_63 = V_31 -> V_45 . V_63 ;
return V_31 ;
V_235:
if ( V_31 )
F_90 ( V_31 ) ;
return NULL ;
V_266:
* error = - V_292 ;
goto V_235;
}
static int F_104 ( const struct V_18 * V_19 ,
T_23 V_293 ,
struct V_1 * V_2 ,
struct V_1 * * V_260 )
{
struct V_294 V_295 ;
T_4 V_12 ;
V_12 = F_16 ( sizeof( V_295 ) ) ;
if ( ! * V_260 )
* V_260 = F_52 ( V_19 , V_2 , V_12 ) ;
if ( * V_260 ) {
V_295 . V_296 = F_14 ( 1 ) ;
V_295 . type = V_293 ;
F_5 ( * V_260 , V_297 ,
sizeof( V_295 ) ) ;
F_7 ( * V_260 , sizeof( V_295 ) , & V_295 ) ;
}
return 0 ;
}
static int F_105 ( const struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_1 * * V_260 )
{
if ( ! * V_260 )
* V_260 = F_52 ( V_19 , V_2 , 0 ) ;
if ( * V_260 )
F_5 ( * V_260 , V_298 , 0 ) ;
return 0 ;
}
static int F_106 ( const struct V_18 * V_19 ,
struct V_164 * V_168 ,
const struct V_1 * V_2 ,
struct V_1 * * V_260 )
{
if ( * V_260 )
F_44 ( * V_260 ) ;
* V_260 = F_48 ( V_19 , V_2 , V_168 ) ;
return 0 ;
}
static int F_107 ( const struct V_18 * V_19 ,
union V_28 V_168 ,
struct V_1 * V_2 ,
struct V_1 * * V_260 )
{
T_4 V_12 = F_18 ( V_168 . V_248 -> V_14 ) ;
if ( * V_260 )
F_44 ( * V_260 ) ;
* V_260 = F_52 ( V_19 , V_2 , V_12 ) ;
if ( * V_260 ) {
F_5 ( * V_260 , V_299 , V_12 ) ;
F_7 ( * V_260 , V_12 , V_168 . V_71 ) ;
}
return 0 ;
}
static int F_108 ( struct V_24 * V_24 , union V_28 V_168 )
{
T_4 V_40 = F_18 ( V_168 . V_248 -> V_14 ) - sizeof( T_11 ) ;
int V_300 = 0 ;
int V_301 = 0 ;
int V_302 ;
for ( V_302 = 0 ; V_302 < V_40 ; V_302 ++ ) {
switch ( V_168 . V_303 -> V_304 [ V_302 ] ) {
case V_66 :
V_300 = 1 ;
break;
case V_61 :
case V_62 :
V_301 = 1 ;
break;
}
}
if ( V_24 -> V_57 . V_305 )
return 1 ;
if ( V_24 -> V_57 . V_60 && ! V_300 && V_301 )
return 0 ;
return 1 ;
}
static void F_109 ( struct V_18 * V_19 ,
union V_28 V_168 )
{
struct V_24 * V_24 = F_12 ( V_19 -> V_25 . V_26 ) ;
T_4 V_40 = F_18 ( V_168 . V_248 -> V_14 ) - sizeof( T_11 ) ;
int V_302 ;
for ( V_302 = 0 ; V_302 < V_40 ; V_302 ++ ) {
switch ( V_168 . V_303 -> V_304 [ V_302 ] ) {
case V_306 :
if ( V_24 -> V_57 . V_58 &&
! V_19 -> V_82 . V_84 )
V_19 -> V_82 . V_84 = 1 ;
break;
case V_66 :
if ( V_24 -> V_57 . V_64 )
V_19 -> V_82 . V_86 = 1 ;
break;
case V_61 :
case V_62 :
if ( V_24 -> V_57 . V_60 )
V_19 -> V_82 . V_85 = 1 ;
break;
default:
break;
}
}
}
static T_24 F_110 ( const struct V_18 * V_19 ,
union V_28 V_168 ,
struct V_1 * V_2 ,
struct V_1 * * V_260 )
{
int V_31 = V_307 ;
switch ( V_168 . V_248 -> type & V_308 ) {
case V_309 :
V_31 = V_310 ;
break;
case V_311 :
break;
case V_312 :
V_31 = V_310 ;
case V_313 :
if ( NULL == * V_260 )
* V_260 = F_53 ( V_19 , V_2 ) ;
if ( * V_260 ) {
if ( ! F_8 ( * V_260 , V_314 ,
F_16 ( F_18 ( V_168 . V_248 -> V_14 ) ) ) )
F_10 ( * V_260 ,
F_16 ( F_18 ( V_168 . V_248 -> V_14 ) ) ,
V_168 . V_71 ) ;
} else {
V_31 = V_269 ;
}
break;
default:
break;
}
return V_31 ;
}
static T_24 F_111 ( struct V_24 * V_24 ,
const struct V_18 * V_19 ,
union V_28 V_168 ,
T_25 V_315 ,
struct V_1 * V_2 ,
struct V_1 * * V_154 )
{
struct V_316 * V_317 ;
int V_31 = V_307 ;
T_4 V_318 , V_319 = 0 ;
int V_302 ;
switch ( V_168 . V_248 -> type ) {
case V_320 :
case V_321 :
case V_322 :
case V_72 :
case V_249 :
case V_172 :
case V_323 :
case V_324 :
case V_74 :
break;
case V_73 :
if ( ! F_108 ( V_24 , V_168 ) )
return V_325 ;
break;
case V_326 :
if ( V_24 -> V_57 . V_60 )
break;
goto V_327;
case V_328 :
F_107 ( V_19 , V_168 , V_2 , V_154 ) ;
V_31 = V_325 ;
break;
case V_329 :
if ( V_24 -> V_57 . V_58 )
break;
goto V_327;
case V_330 :
if ( ! V_24 -> V_57 . V_64 )
goto V_327;
if ( V_331 !=
F_18 ( V_168 . V_248 -> V_14 ) - sizeof( T_11 ) ) {
F_106 ( V_19 , V_168 . V_248 ,
V_2 , V_154 ) ;
V_31 = V_325 ;
}
break;
case V_332 :
if ( ! V_24 -> V_57 . V_64 )
goto V_327;
if ( 260 < F_18 ( V_168 . V_248 -> V_14 ) ) {
F_106 ( V_19 , V_168 . V_248 ,
V_2 , V_154 ) ;
V_31 = V_325 ;
}
break;
case V_333 :
if ( ! V_24 -> V_57 . V_64 )
goto V_327;
V_317 = (struct V_316 * ) V_168 . V_248 ;
V_318 = ( F_18 ( V_168 . V_248 -> V_14 ) - sizeof( T_11 ) ) >> 1 ;
for ( V_302 = 0 ; V_302 < V_318 ; V_302 ++ ) {
V_319 = F_18 ( V_317 -> V_334 [ V_302 ] ) ;
if ( V_319 == V_335 )
break;
}
if ( V_319 != V_335 ) {
F_106 ( V_19 , V_168 . V_248 , V_2 ,
V_154 ) ;
V_31 = V_325 ;
}
break;
V_327:
default:
F_31 ( L_5 ,
F_18 ( V_168 . V_248 -> type ) , V_315 ) ;
V_31 = F_110 ( V_19 , V_168 , V_2 , V_154 ) ;
break;
}
return V_31 ;
}
int F_112 ( struct V_24 * V_24 , const struct V_18 * V_19 ,
T_25 V_315 ,
T_26 * V_253 ,
struct V_1 * V_2 ,
struct V_1 * * V_260 )
{
union V_28 V_168 ;
int V_336 = 0 ;
int V_337 ;
if ( ( 0 == V_253 -> V_69 . V_49 ) ||
( 0 == V_253 -> V_69 . V_51 ) ||
( 0 == V_253 -> V_69 . V_44 ) ||
( V_338 > F_98 ( V_253 -> V_69 . V_47 ) ) ) {
return F_105 ( V_19 , V_2 , V_260 ) ;
}
F_113 (param, peer_init, init_hdr.params) {
if ( V_249 == V_168 . V_248 -> type )
V_336 = 1 ;
}
if ( V_168 . V_71 != ( void * ) V_2 -> V_163 )
return F_106 ( V_19 , V_168 . V_248 , V_2 , V_260 ) ;
if ( ( V_87 == V_315 ) && ! V_336 )
return F_104 ( V_19 , V_249 ,
V_2 , V_260 ) ;
F_113 (param, peer_init, init_hdr.params) {
V_337 = F_111 ( V_24 , V_19 , V_168 , V_315 , V_2 , V_260 ) ;
switch ( V_337 ) {
case V_325 :
case V_269 :
return 0 ;
case V_310 :
return 1 ;
case V_307 :
default:
break;
}
}
return 1 ;
}
int F_114 ( struct V_18 * V_19 , struct V_1 * V_2 ,
const union V_214 * V_237 ,
T_26 * V_253 , T_5 V_22 )
{
struct V_24 * V_24 = F_12 ( V_19 -> V_25 . V_26 ) ;
union V_28 V_168 ;
struct V_130 * V_89 ;
struct V_339 * V_340 , * V_234 ;
struct V_3 * V_4 ;
union V_214 V_341 ;
char * V_77 ;
int V_342 = 0 ;
if( ! F_115 ( V_19 , V_237 , V_22 , V_343 ) )
goto V_344;
if ( F_116 ( F_64 ( V_2 ) , V_237 ) )
V_342 = 1 ;
F_113 (param, peer_init, init_hdr.params) {
if ( ! V_342 && ( V_168 . V_248 -> type == V_320 ||
V_168 . V_248 -> type == V_321 ) ) {
V_4 = F_2 ( F_117 ( V_168 . V_248 -> type ) ) ;
V_4 -> V_345 ( & V_341 , V_168 . V_341 ,
V_2 -> V_271 -> V_217 , 0 ) ;
if ( F_116 ( F_64 ( V_2 ) , & V_341 ) )
V_342 = 1 ;
}
if ( ! F_118 ( V_19 , V_168 , V_237 , V_22 ) )
goto V_346;
}
if ( ! V_342 )
goto V_346;
if ( V_19 -> V_82 . V_86 && ( ! V_19 -> V_82 . V_347 ||
! V_19 -> V_82 . V_348 ) )
V_19 -> V_82 . V_86 = 0 ;
if ( ! V_24 -> V_57 . V_305 &&
( V_19 -> V_82 . V_85 && ! V_19 -> V_82 . V_86 ) ) {
V_19 -> V_82 . V_349 |= ( V_350 |
V_351 |
V_326 ) ;
V_19 -> V_82 . V_85 = 0 ;
goto V_346;
}
F_119 (pos, temp, &asoc->peer.transport_addr_list) {
V_89 = F_120 ( V_340 , struct V_130 , V_352 ) ;
if ( V_89 -> V_353 == V_354 ) {
F_121 ( V_19 , V_89 ) ;
}
}
V_19 -> V_82 . V_302 . V_44 =
F_98 ( V_253 -> V_69 . V_44 ) ;
V_19 -> V_82 . V_302 . V_47 =
F_98 ( V_253 -> V_69 . V_47 ) ;
V_19 -> V_82 . V_302 . V_49 =
F_18 ( V_253 -> V_69 . V_49 ) ;
V_19 -> V_82 . V_302 . V_51 =
F_18 ( V_253 -> V_69 . V_51 ) ;
V_19 -> V_82 . V_302 . V_53 =
F_98 ( V_253 -> V_69 . V_53 ) ;
if ( V_19 -> V_45 . V_50 >
F_18 ( V_253 -> V_69 . V_51 ) ) {
V_19 -> V_45 . V_50 =
F_18 ( V_253 -> V_69 . V_51 ) ;
}
if ( V_19 -> V_45 . V_52 >
F_18 ( V_253 -> V_69 . V_49 ) ) {
V_19 -> V_45 . V_52 =
F_18 ( V_253 -> V_69 . V_49 ) ;
}
V_19 -> V_45 . V_355 = V_19 -> V_82 . V_302 . V_44 ;
V_19 -> V_82 . V_48 = V_19 -> V_82 . V_302 . V_47 ;
V_77 = V_19 -> V_82 . V_77 ;
if ( V_77 ) {
V_19 -> V_82 . V_77 = F_122 ( V_77 , V_19 -> V_82 . V_78 , V_22 ) ;
if ( ! V_19 -> V_82 . V_77 )
goto V_346;
}
F_35 (transport, &asoc->peer.transport_addr_list,
transports) {
V_89 -> V_356 = V_19 -> V_82 . V_302 . V_47 ;
}
if ( ! F_123 ( & V_19 -> V_82 . V_126 , V_357 ,
V_19 -> V_82 . V_302 . V_53 , V_22 ) )
goto V_346;
if ( ! V_19 -> V_234 ) {
int error ;
V_19 -> V_230 = F_124 ( V_19 -> V_45 . V_52 ,
V_19 -> V_45 . V_50 , V_22 ) ;
if ( ! V_19 -> V_230 )
goto V_346;
error = F_125 ( V_19 , V_22 ) ;
if ( error )
goto V_346;
}
V_19 -> V_82 . V_290 = V_19 -> V_82 . V_302 . V_53 - 1 ;
return 1 ;
V_346:
F_119 (pos, temp, &asoc->peer.transport_addr_list) {
V_89 = F_120 ( V_340 , struct V_130 , V_352 ) ;
if ( V_89 -> V_353 != V_343 )
F_121 ( V_19 , V_89 ) ;
}
V_344:
return 0 ;
}
static int F_118 ( struct V_18 * V_19 ,
union V_28 V_168 ,
const union V_214 * V_237 ,
T_5 V_22 )
{
struct V_24 * V_24 = F_12 ( V_19 -> V_25 . V_26 ) ;
union V_214 V_341 ;
int V_302 ;
T_4 V_36 ;
int V_31 = 1 ;
T_21 V_233 ;
T_27 V_358 ;
struct V_3 * V_4 ;
union V_359 * V_360 ;
struct V_130 * V_361 ;
switch ( V_168 . V_248 -> type ) {
case V_321 :
if ( V_362 != V_19 -> V_25 . V_26 -> V_363 )
break;
goto V_364;
case V_320 :
if ( F_126 ( V_19 -> V_25 . V_26 ) )
break;
V_364:
V_4 = F_2 ( F_117 ( V_168 . V_248 -> type ) ) ;
V_4 -> V_345 ( & V_341 , V_168 . V_341 , F_6 ( V_19 -> V_82 . V_285 ) , 0 ) ;
V_233 = F_88 ( V_237 ) ;
if ( F_127 ( V_24 , & V_341 , V_233 ) )
if ( ! F_115 ( V_19 , & V_341 , V_22 , V_365 ) )
return 0 ;
break;
case V_322 :
if ( ! V_24 -> V_57 . V_366 )
break;
V_358 = F_98 ( V_168 . V_367 -> V_368 ) ;
V_19 -> V_252 . V_280 += V_358 / 1000 ;
V_19 -> V_252 . V_281 += ( V_358 % 1000 ) * 1000 ;
break;
case V_328 :
F_31 ( L_6 ) ;
break;
case V_72 :
V_19 -> V_82 . V_369 = 0 ;
V_19 -> V_82 . V_370 = 0 ;
if ( V_237 -> V_371 . V_372 == V_373 )
V_19 -> V_82 . V_370 = 1 ;
else if ( V_237 -> V_371 . V_372 == V_374 )
V_19 -> V_82 . V_369 = 1 ;
V_36 = F_18 ( V_168 . V_248 -> V_14 ) - sizeof( T_11 ) ;
if ( V_36 )
V_36 /= sizeof( T_4 ) ;
for ( V_302 = 0 ; V_302 < V_36 ; ++ V_302 ) {
switch ( V_168 . V_36 -> V_37 [ V_302 ] ) {
case V_320 :
V_19 -> V_82 . V_369 = 1 ;
break;
case V_321 :
if ( V_362 == V_19 -> V_25 . V_26 -> V_363 )
V_19 -> V_82 . V_370 = 1 ;
break;
case V_328 :
V_19 -> V_82 . V_375 = 1 ;
break;
default:
break;
}
}
break;
case V_249 :
V_19 -> V_82 . V_78 =
F_18 ( V_168 . V_248 -> V_14 ) - sizeof( T_11 ) ;
V_19 -> V_82 . V_77 = V_168 . V_77 -> V_247 ;
break;
case V_172 :
break;
case V_323 :
break;
case V_324 :
V_19 -> V_82 . V_83 = 1 ;
break;
case V_74 :
V_19 -> V_82 . V_63 = F_98 ( V_168 . V_376 -> V_63 ) ;
break;
case V_326 :
if ( ! V_24 -> V_57 . V_60 )
goto V_377;
V_360 = V_168 . V_71 + sizeof( V_378 ) ;
V_4 = F_2 ( F_117 ( V_168 . V_248 -> type ) ) ;
V_4 -> V_345 ( & V_341 , V_360 ,
F_6 ( V_19 -> V_82 . V_285 ) , 0 ) ;
if ( ! V_4 -> V_379 ( & V_341 , NULL , NULL ) )
break;
V_361 = F_128 ( V_19 , & V_341 ) ;
if ( ! V_361 )
break;
F_129 ( V_19 , V_361 ) ;
break;
case V_73 :
F_109 ( V_19 , V_168 ) ;
break;
case V_329 :
if ( V_24 -> V_57 . V_58 ) {
V_19 -> V_82 . V_84 = 1 ;
break;
}
goto V_377;
case V_330 :
if ( ! V_24 -> V_57 . V_64 )
goto V_377;
V_19 -> V_82 . V_347 = F_122 ( V_168 . V_248 ,
F_18 ( V_168 . V_248 -> V_14 ) , V_22 ) ;
if ( ! V_19 -> V_82 . V_347 ) {
V_31 = 0 ;
break;
}
break;
case V_333 :
if ( ! V_24 -> V_57 . V_64 )
goto V_377;
V_19 -> V_82 . V_348 = F_122 ( V_168 . V_248 ,
F_18 ( V_168 . V_248 -> V_14 ) , V_22 ) ;
if ( ! V_19 -> V_82 . V_348 ) {
V_31 = 0 ;
break;
}
F_130 ( V_19 , V_168 . V_380 ) ;
break;
case V_332 :
if ( ! V_24 -> V_57 . V_64 )
goto V_377;
V_19 -> V_82 . V_381 = F_122 ( V_168 . V_248 ,
F_18 ( V_168 . V_248 -> V_14 ) , V_22 ) ;
if ( ! V_19 -> V_82 . V_381 )
V_31 = 0 ;
break;
V_377:
default:
F_31 ( L_7 ,
F_18 ( V_168 . V_248 -> type ) , V_19 ) ;
break;
}
return V_31 ;
}
T_13 F_131 ( const struct V_232 * V_80 )
{
T_13 V_382 ;
do {
F_132 ( & V_382 , sizeof( T_13 ) ) ;
} while ( V_382 == 0 );
return V_382 ;
}
T_13 F_133 ( const struct V_232 * V_80 )
{
T_13 V_31 ;
F_132 ( & V_31 , sizeof( T_13 ) ) ;
return V_31 ;
}
static struct V_1 * F_134 ( struct V_18 * V_19 ,
union V_214 * V_341 ,
int V_23 )
{
T_28 V_383 ;
struct V_1 * V_31 ;
int V_14 = sizeof( V_383 ) + V_23 ;
union V_359 V_384 ;
int V_385 ;
struct V_3 * V_4 = F_2 ( V_341 -> V_274 . V_386 ) ;
V_385 = V_4 -> V_387 ( V_341 , & V_384 ) ;
if ( ! V_385 )
return NULL ;
V_14 += V_385 ;
V_31 = F_19 ( V_19 , V_61 , 0 , V_14 ) ;
if ( ! V_31 )
return NULL ;
V_383 . V_388 = F_14 ( V_19 -> V_290 ++ ) ;
V_31 -> V_15 . V_389 =
F_7 ( V_31 , sizeof( V_383 ) , & V_383 ) ;
V_31 -> V_70 . V_71 =
F_7 ( V_31 , V_385 , & V_384 ) ;
return V_31 ;
}
struct V_1 * F_135 ( struct V_18 * V_19 ,
union V_214 * V_390 ,
struct V_391 * V_29 ,
int V_392 ,
T_1 V_103 )
{
V_378 V_168 ;
struct V_1 * V_31 ;
union V_359 V_360 ;
union V_214 * V_341 ;
void * V_393 ;
struct V_3 * V_4 ;
int V_394 = sizeof( V_168 ) ;
int V_395 = 0 ;
int V_396 = 0 ;
int V_302 ;
int V_397 = 0 ;
V_393 = V_29 ;
for ( V_302 = 0 ; V_302 < V_392 ; V_302 ++ ) {
V_341 = V_393 ;
V_4 = F_2 ( V_341 -> V_274 . V_386 ) ;
V_395 = V_4 -> V_387 ( V_341 , & V_360 ) ;
V_396 += V_394 ;
V_396 += V_395 ;
V_393 += V_4 -> V_398 ;
if ( V_19 -> V_399 && ! V_397 ) {
V_396 += V_394 ;
V_396 += V_395 ;
V_397 = 1 ;
F_31 ( L_8 , V_396 ) ;
}
}
V_31 = F_134 ( V_19 , V_390 , V_396 ) ;
if ( ! V_31 )
return NULL ;
V_393 = V_29 ;
for ( V_302 = 0 ; V_302 < V_392 ; V_302 ++ ) {
V_341 = V_393 ;
V_4 = F_2 ( V_341 -> V_274 . V_386 ) ;
V_395 = V_4 -> V_387 ( V_341 , & V_360 ) ;
V_168 . V_70 . type = V_103 ;
V_168 . V_70 . V_14 = F_6 ( V_394 + V_395 ) ;
V_168 . V_400 = V_302 ;
F_7 ( V_31 , V_394 , & V_168 ) ;
F_7 ( V_31 , V_395 , & V_360 ) ;
V_393 += V_4 -> V_398 ;
}
if ( V_103 == V_350 && V_397 ) {
V_341 = V_19 -> V_399 ;
V_4 = F_2 ( V_341 -> V_274 . V_386 ) ;
V_395 = V_4 -> V_387 ( V_341 , & V_360 ) ;
V_168 . V_70 . type = V_351 ;
V_168 . V_70 . V_14 = F_6 ( V_394 + V_395 ) ;
V_168 . V_400 = V_302 ;
F_7 ( V_31 , V_394 , & V_168 ) ;
F_7 ( V_31 , V_395 , & V_360 ) ;
}
return V_31 ;
}
struct V_1 * F_136 ( struct V_18 * V_19 ,
union V_214 * V_341 )
{
V_378 V_168 ;
struct V_1 * V_31 ;
int V_12 = sizeof( V_168 ) ;
union V_359 V_384 ;
int V_385 ;
struct V_3 * V_4 = F_2 ( V_341 -> V_274 . V_386 ) ;
V_385 = V_4 -> V_387 ( V_341 , & V_384 ) ;
if ( ! V_385 )
return NULL ;
V_12 += V_385 ;
V_31 = F_134 ( V_19 , V_341 , V_12 ) ;
if ( ! V_31 )
return NULL ;
V_168 . V_70 . type = V_326 ;
V_168 . V_70 . V_14 = F_6 ( V_12 ) ;
V_168 . V_400 = 0 ;
F_7 ( V_31 , sizeof( V_168 ) , & V_168 ) ;
F_7 ( V_31 , V_385 , & V_384 ) ;
return V_31 ;
}
static struct V_1 * F_137 ( const struct V_18 * V_19 ,
T_13 V_388 , int V_23 )
{
T_28 V_383 ;
struct V_1 * V_31 ;
int V_14 = sizeof( V_383 ) + V_23 ;
V_31 = F_19 ( V_19 , V_62 , 0 , V_14 ) ;
if ( ! V_31 )
return NULL ;
V_383 . V_388 = F_14 ( V_388 ) ;
V_31 -> V_15 . V_389 =
F_7 ( V_31 , sizeof( V_383 ) , & V_383 ) ;
return V_31 ;
}
static void F_138 ( struct V_1 * V_2 , T_17 V_400 ,
T_1 V_401 , V_378 * V_402 )
{
V_378 V_403 ;
T_3 V_404 ;
int V_405 = 0 ;
int V_406 = 0 ;
T_1 V_407 ;
if ( V_408 == V_401 ) {
V_407 = V_409 ;
} else {
V_407 = V_410 ;
V_406 = sizeof( V_404 ) ;
if ( V_402 )
V_405 =
F_18 ( V_402 -> V_70 . V_14 ) ;
}
V_403 . V_70 . type = V_407 ;
V_403 . V_70 . V_14 = F_6 ( sizeof( V_403 ) +
V_406 +
V_405 ) ;
V_403 . V_400 = V_400 ;
F_7 ( V_2 , sizeof( V_403 ) , & V_403 ) ;
if ( V_408 == V_401 )
return;
V_404 . V_13 = V_401 ;
V_404 . V_14 = F_6 ( V_406 + V_405 ) ;
F_7 ( V_2 , V_406 , & V_404 ) ;
if ( V_402 )
F_7 ( V_2 , V_405 , V_402 ) ;
}
static T_1 F_139 ( struct V_18 * V_19 ,
struct V_1 * V_383 ,
V_378 * V_402 )
{
struct V_130 * V_82 ;
struct V_3 * V_4 ;
union V_214 V_341 ;
union V_359 * V_360 ;
V_360 = ( void * ) V_402 + sizeof( V_378 ) ;
if ( V_402 -> V_70 . type != V_350 &&
V_402 -> V_70 . type != V_351 &&
V_402 -> V_70 . type != V_326 )
return V_314 ;
switch ( V_360 -> V_248 . type ) {
case V_321 :
if ( ! V_19 -> V_82 . V_370 )
return V_299 ;
break;
case V_320 :
if ( ! V_19 -> V_82 . V_369 )
return V_299 ;
break;
default:
return V_299 ;
}
V_4 = F_2 ( F_117 ( V_360 -> V_248 . type ) ) ;
if ( F_57 ( ! V_4 ) )
return V_299 ;
V_4 -> V_345 ( & V_341 , V_360 , F_6 ( V_19 -> V_82 . V_285 ) , 0 ) ;
if ( ! V_4 -> V_411 ( & V_341 ) && ! V_4 -> V_379 ( & V_341 , NULL , V_383 -> V_6 ) )
return V_299 ;
switch ( V_402 -> V_70 . type ) {
case V_350 :
if ( V_4 -> V_411 ( & V_341 ) )
memcpy ( & V_341 , & V_383 -> V_217 , sizeof( V_341 ) ) ;
V_82 = F_115 ( V_19 , & V_341 , V_198 , V_365 ) ;
if ( ! V_82 )
return V_412 ;
if ( ! F_140 ( & V_82 -> V_413 , F_141 ( V_82 ) ) )
F_142 ( V_82 ) ;
V_19 -> V_414 = V_82 ;
break;
case V_351 :
if ( V_19 -> V_82 . V_415 == 1 )
return V_416 ;
if ( F_116 ( & V_383 -> V_217 , & V_341 ) )
return V_417 ;
if ( V_4 -> V_411 ( & V_341 ) ) {
F_129 ( V_19 , V_383 -> V_89 ) ;
F_143 ( V_19 ,
V_383 -> V_89 ) ;
} else
F_144 ( V_19 , & V_341 ) ;
break;
case V_326 :
if ( V_4 -> V_411 ( & V_341 ) )
memcpy ( & V_341 . V_274 , F_64 ( V_383 ) , sizeof( V_341 ) ) ;
V_82 = F_128 ( V_19 , & V_341 ) ;
if ( ! V_82 )
return V_299 ;
F_129 ( V_19 , V_82 ) ;
break;
}
return V_408 ;
}
int F_145 ( const struct V_18 * V_19 ,
struct V_164 * V_70 , void * V_163 ,
struct V_164 * * V_260 ) {
V_378 * V_402 ;
union V_28 V_168 ;
int V_14 , V_418 ;
V_168 . V_71 = ( T_11 * ) V_70 ;
while ( V_168 . V_71 <= V_163 - sizeof( T_11 ) ) {
V_14 = F_18 ( V_168 . V_248 -> V_14 ) ;
* V_260 = V_168 . V_248 ;
if ( V_168 . V_71 > V_163 - V_14 ||
V_14 < sizeof( T_11 ) )
return 0 ;
switch ( V_168 . V_248 -> type ) {
case V_350 :
case V_351 :
case V_326 :
V_402 = ( V_378 * ) V_168 . V_71 ;
V_418 = F_18 ( V_402 -> V_70 . V_14 ) ;
if ( V_418 < sizeof( V_378 ) +
sizeof( T_11 ) )
return 0 ;
break;
case V_409 :
case V_74 :
if ( V_14 != sizeof( V_378 ) )
return 0 ;
break;
default:
break;
}
V_168 . V_71 += F_16 ( V_14 ) ;
}
if ( V_168 . V_71 != V_163 )
return 0 ;
return 1 ;
}
struct V_1 * F_146 ( struct V_18 * V_19 ,
struct V_1 * V_383 )
{
T_28 * V_419 ;
union V_359 * V_360 ;
V_378 * V_402 ;
struct V_1 * V_420 ;
T_1 V_401 ;
int V_14 = 0 ;
int V_107 ;
T_13 V_388 ;
int V_421 = 1 ;
V_107 = F_18 ( V_383 -> V_147 -> V_14 ) - sizeof( T_20 ) ;
V_419 = ( T_28 * ) V_383 -> V_6 -> V_160 ;
V_388 = F_98 ( V_419 -> V_388 ) ;
V_14 = sizeof( T_28 ) ;
V_360 = (union V_359 * ) ( V_383 -> V_6 -> V_160 + V_14 ) ;
V_107 -= V_14 ;
V_14 = F_18 ( V_360 -> V_248 . V_14 ) ;
V_402 = ( void * ) V_360 + V_14 ;
V_107 -= V_14 ;
V_420 = F_137 ( V_19 , V_388 , V_107 * 4 ) ;
if ( ! V_420 )
goto V_422;
while ( V_107 > 0 ) {
V_401 = F_139 ( V_19 , V_383 ,
V_402 ) ;
if ( V_408 != V_401 )
V_421 = 0 ;
if ( ! V_421 )
F_138 ( V_420 ,
V_402 -> V_400 , V_401 ,
V_402 ) ;
if ( V_412 == V_401 )
goto V_422;
V_14 = F_18 ( V_402 -> V_70 . V_14 ) ;
V_402 = ( void * ) V_402 + V_14 ;
V_107 -= V_14 ;
}
V_422:
V_19 -> V_82 . V_290 ++ ;
if ( V_420 ) {
F_77 ( V_420 ) ;
F_147 ( & V_420 -> V_211 ,
& V_19 -> V_423 ) ;
}
return V_420 ;
}
static void F_148 ( struct V_18 * V_19 ,
V_378 * V_402 )
{
struct V_3 * V_4 ;
union V_214 V_341 ;
struct V_20 * V_21 = & V_19 -> V_25 . V_79 ;
union V_359 * V_360 ;
struct V_130 * V_89 ;
struct V_424 * V_425 ;
V_360 = ( void * ) V_402 + sizeof( V_378 ) ;
V_4 = F_2 ( F_117 ( V_360 -> V_248 . type ) ) ;
V_4 -> V_345 ( & V_341 , V_360 , F_6 ( V_21 -> V_285 ) , 0 ) ;
switch ( V_402 -> V_70 . type ) {
case V_350 :
F_149 () ;
F_35 (saddr, &bp->address_list, list) {
if ( F_116 ( & V_425 -> V_426 , & V_341 ) )
V_425 -> V_353 = V_287 ;
}
F_150 () ;
F_35 (transport, &asoc->peer.transport_addr_list,
transports) {
F_151 ( V_89 -> V_427 ) ;
V_89 -> V_427 = NULL ;
}
break;
case V_351 :
F_149 () ;
F_152 ( V_21 , & V_341 ) ;
if ( V_19 -> V_399 != NULL &&
F_116 ( V_19 -> V_399 , & V_341 ) ) {
F_21 ( V_19 -> V_399 ) ;
V_19 -> V_399 = NULL ;
}
F_150 () ;
F_35 (transport, &asoc->peer.transport_addr_list,
transports) {
F_151 ( V_89 -> V_427 ) ;
V_89 -> V_427 = NULL ;
}
break;
default:
break;
}
}
static T_1 F_153 ( struct V_1 * V_420 ,
V_378 * V_402 ,
int V_428 )
{
V_378 * V_429 ;
T_3 * V_404 ;
int V_14 ;
int V_430 ;
T_1 V_401 ;
if ( V_428 )
V_401 = V_408 ;
else
V_401 = V_431 ;
V_430 = F_18 ( V_420 -> V_147 -> V_14 ) -
sizeof( T_20 ) ;
V_14 = sizeof( T_28 ) ;
V_429 = ( V_378 * ) ( V_420 -> V_6 -> V_160 +
V_14 ) ;
V_430 -= V_14 ;
while ( V_430 > 0 ) {
if ( V_429 -> V_400 == V_402 -> V_400 ) {
switch( V_429 -> V_70 . type ) {
case V_409 :
return V_408 ;
case V_410 :
V_14 = sizeof( V_378 ) ;
V_404 = ( void * ) V_429 + V_14 ;
V_430 -= V_14 ;
if ( V_430 > 0 )
return V_404 -> V_13 ;
else
return V_298 ;
break;
default:
return V_298 ;
}
}
V_14 = F_18 ( V_429 -> V_70 . V_14 ) ;
V_429 = ( void * ) V_429 + V_14 ;
V_430 -= V_14 ;
}
return V_401 ;
}
int F_154 ( struct V_18 * V_19 ,
struct V_1 * V_420 )
{
struct V_1 * V_383 = V_19 -> V_432 ;
union V_359 * V_360 ;
V_378 * V_402 ;
int V_14 = 0 ;
int V_433 = V_383 -> V_6 -> V_12 ;
int V_421 = 0 ;
int V_428 = 1 ;
int V_31 = 0 ;
T_1 V_401 = V_408 ;
V_14 = sizeof( V_434 ) ;
V_360 = (union V_359 * ) ( V_383 -> V_6 -> V_160 + V_14 ) ;
V_433 -= V_14 ;
V_14 = F_18 ( V_360 -> V_248 . V_14 ) ;
V_402 = ( void * ) V_360 + V_14 ;
V_433 -= V_14 ;
if ( V_420 -> V_6 -> V_12 == sizeof( T_28 ) )
V_421 = 1 ;
while ( V_433 > 0 ) {
if ( V_421 )
V_401 = V_408 ;
else {
V_401 = F_153 ( V_420 ,
V_402 ,
V_428 ) ;
if ( V_428 && ( V_408 != V_401 ) )
V_428 = 0 ;
}
switch ( V_401 ) {
case V_408 :
F_148 ( V_19 , V_402 ) ;
break;
case V_412 :
V_31 = 1 ;
break;
case V_314 :
V_19 -> V_82 . V_349 |=
V_402 -> V_70 . type ;
break;
case V_431 :
case V_416 :
case V_417 :
default:
break;
}
V_14 = F_18 ( V_402 -> V_70 . V_14 ) ;
V_402 = ( void * ) V_402 + V_14 ;
V_433 -= V_14 ;
}
if ( V_428 && V_19 -> V_435 ) {
V_19 -> V_435 = 0 ;
F_155 ( V_19 -> V_82 . V_436 ) ;
}
F_71 ( & V_383 -> V_211 ) ;
F_44 ( V_383 ) ;
V_19 -> V_432 = NULL ;
return V_31 ;
}
struct V_1 * F_156 ( const struct V_18 * V_19 ,
T_13 V_437 , T_2 V_438 ,
struct V_439 * V_440 )
{
struct V_1 * V_31 = NULL ;
struct V_441 V_442 ;
struct V_439 V_443 ;
T_2 V_146 ;
int V_302 ;
V_146 = ( V_438 + 1 ) * sizeof( T_13 ) ;
V_31 = F_19 ( V_19 , V_306 , 0 , V_146 ) ;
if ( ! V_31 )
return NULL ;
V_442 . V_437 = F_14 ( V_437 ) ;
V_31 -> V_15 . V_444 =
F_7 ( V_31 , sizeof( V_442 ) , & V_442 ) ;
for ( V_302 = 0 ; V_302 < V_438 ; V_302 ++ ) {
V_443 . V_109 = V_440 [ V_302 ] . V_109 ;
V_443 . V_104 = V_440 [ V_302 ] . V_104 ;
F_7 ( V_31 , sizeof( V_443 ) , & V_443 ) ;
}
return V_31 ;
}

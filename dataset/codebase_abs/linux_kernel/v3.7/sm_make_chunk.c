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
if ( V_122 )
F_7 ( V_31 , sizeof( T_13 ) * V_122 ,
F_34 ( V_125 ) ) ;
if ( ++ V_123 -> V_82 . V_137 == 0 ) {
F_35 (trans, &asoc->peer.transport_addr_list,
transports)
V_131 -> V_137 = 0 ;
V_123 -> V_82 . V_137 = 1 ;
}
V_68:
return V_31 ;
}
struct V_1 * F_36 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
struct V_1 * V_31 ;
T_16 V_138 ;
T_13 V_120 ;
V_120 = F_30 ( & V_19 -> V_82 . V_126 ) ;
V_138 . V_132 = F_14 ( V_120 ) ;
V_31 = F_19 ( V_19 , V_139 , 0 ,
sizeof( T_16 ) ) ;
if ( ! V_31 )
goto V_68;
V_31 -> V_15 . V_140 =
F_7 ( V_31 , sizeof( V_138 ) , & V_138 ) ;
if ( V_2 )
V_31 -> V_89 = V_2 -> V_89 ;
V_68:
return V_31 ;
}
struct V_1 * F_37 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
struct V_1 * V_31 ;
V_31 = F_19 ( V_19 , V_141 , 0 , 0 ) ;
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
V_103 |= V_19 ? 0 : V_142 ;
V_31 = F_19 ( V_19 , V_143 , V_103 , 0 ) ;
if ( V_31 && V_2 )
V_31 -> V_89 = V_2 -> V_89 ;
return V_31 ;
}
struct V_1 * F_39 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
const T_2 V_144 )
{
struct V_1 * V_31 ;
T_10 V_103 = 0 ;
if ( ! V_19 ) {
if ( V_2 && V_2 -> V_145 &&
V_2 -> V_145 -> type == V_67 )
V_103 = 0 ;
else
V_103 = V_142 ;
}
V_31 = F_19 ( V_19 , V_146 , V_103 , V_144 ) ;
if ( V_31 && V_2 )
V_31 -> V_89 = V_2 -> V_89 ;
return V_31 ;
}
struct V_1 * F_40 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 , T_13 V_108 )
{
struct V_1 * V_31 ;
T_17 V_147 ;
V_31 = F_39 ( V_19 , V_2 , sizeof( T_3 )
+ sizeof( V_108 ) ) ;
if ( ! V_31 )
goto V_148;
V_147 = F_14 ( V_108 ) ;
F_5 ( V_31 , V_149 , sizeof( V_147 ) ) ;
F_7 ( V_31 , sizeof( V_147 ) , ( const void * ) & V_147 ) ;
if ( V_2 )
V_31 -> V_89 = V_2 -> V_89 ;
V_148:
return V_31 ;
}
struct V_1 * F_41 ( const struct V_18 * V_19 ,
const struct V_150 * V_151 ,
T_2 V_10 )
{
struct V_1 * V_31 ;
void * V_147 = NULL ;
int V_11 ;
V_31 = F_39 ( V_19 , NULL , sizeof( T_3 ) + V_10 ) ;
if ( ! V_31 )
goto V_152;
if ( V_10 ) {
V_147 = F_42 ( V_10 , V_153 ) ;
if ( ! V_147 )
goto V_154;
V_11 = F_43 ( V_147 , V_151 -> V_155 , V_10 ) ;
if ( V_11 < 0 )
goto V_156;
}
F_5 ( V_31 , V_157 , V_10 ) ;
F_7 ( V_31 , V_10 , V_147 ) ;
if ( V_10 )
F_21 ( V_147 ) ;
return V_31 ;
V_156:
F_21 ( V_147 ) ;
V_154:
F_44 ( V_31 ) ;
V_31 = NULL ;
V_152:
return V_31 ;
}
static void * F_20 ( struct V_1 * V_2 , int V_12 ,
const void * V_158 )
{
void * V_159 ;
int V_160 = F_18 ( V_2 -> V_145 -> V_14 ) ;
V_159 = F_45 ( V_2 -> V_6 , V_12 ) ;
if ( V_158 )
memcpy ( V_159 , V_158 , V_12 ) ;
else
memset ( V_159 , 0 , V_12 ) ;
V_2 -> V_145 -> V_14 = F_6 ( V_160 + V_12 ) ;
V_2 -> V_161 = F_46 ( V_2 -> V_6 ) ;
return V_159 ;
}
struct V_1 * F_47 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
const T_10 * V_147 ,
const T_2 V_10 )
{
struct V_1 * V_31 ;
struct V_162 V_163 ;
V_31 = F_39 ( V_19 , V_2 , sizeof( T_3 ) + V_10
+ sizeof( T_11 ) ) ;
if ( ! V_31 )
goto V_164;
F_5 ( V_31 , V_165 , V_10
+ sizeof( T_11 ) ) ;
V_163 . type = F_6 ( V_2 -> V_145 -> type ) ;
V_163 . V_14 = V_2 -> V_145 -> V_14 ;
F_7 ( V_31 , V_10 , V_147 ) ;
F_20 ( V_31 , sizeof( T_11 ) , & V_163 ) ;
V_164:
return V_31 ;
}
struct V_1 * F_48 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
struct V_162 * V_166 )
{
struct V_1 * V_31 ;
static const char error [] = L_2 ;
T_2 V_167 = sizeof( error ) + sizeof( T_3 ) +
sizeof( T_11 ) ;
V_31 = F_39 ( V_19 , V_2 , V_167 ) ;
if ( ! V_31 )
goto V_68;
F_5 ( V_31 , V_165 ,
sizeof( error ) + sizeof( T_11 ) ) ;
F_7 ( V_31 , sizeof( error ) , error ) ;
F_20 ( V_31 , sizeof( T_11 ) , V_166 ) ;
V_68:
return V_31 ;
}
struct V_1 * F_49 ( const struct V_18 * V_19 ,
const struct V_130 * V_89 )
{
struct V_1 * V_31 ;
T_18 V_168 ;
V_31 = F_19 ( V_19 , V_169 , 0 , sizeof( V_168 ) ) ;
if ( ! V_31 )
goto V_68;
V_168 . V_70 . type = V_170 ;
V_168 . V_70 . V_14 = F_6 ( sizeof( T_18 ) ) ;
V_168 . V_171 = V_89 -> V_172 ;
V_168 . V_173 = V_174 ;
V_168 . V_175 = V_89 -> V_175 ;
V_31 -> V_89 = (struct V_130 * ) V_89 ;
V_31 -> V_15 . V_176 = F_7 ( V_31 , sizeof( V_168 ) ,
& V_168 ) ;
V_68:
return V_31 ;
}
struct V_1 * F_50 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
const void * V_147 , const T_2 V_10 )
{
struct V_1 * V_31 ;
V_31 = F_19 ( V_19 , V_177 , 0 , V_10 ) ;
if ( ! V_31 )
goto V_68;
V_31 -> V_15 . V_176 = F_7 ( V_31 , V_10 , V_147 ) ;
if ( V_2 )
V_31 -> V_89 = V_2 -> V_89 ;
V_68:
return V_31 ;
}
static struct V_1 * F_51 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
T_2 V_178 )
{
struct V_1 * V_31 ;
V_31 = F_19 ( V_19 , V_179 , 0 ,
sizeof( T_3 ) + V_178 ) ;
if ( ! V_31 )
goto V_68;
if ( V_2 )
V_31 -> V_89 = V_2 -> V_89 ;
V_68:
return V_31 ;
}
static inline struct V_1 * F_52 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
T_2 V_178 = V_19 ? V_19 -> V_180 : 0 ;
if ( ! V_178 )
V_178 = V_181 ;
return F_51 ( V_19 , V_2 , V_178 ) ;
}
struct V_1 * F_53 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
T_1 V_9 , const void * V_147 ,
T_2 V_10 , T_2 V_182 )
{
struct V_1 * V_31 ;
V_31 = F_51 ( V_19 , V_2 , V_10 + V_182 ) ;
if ( ! V_31 )
goto V_68;
F_5 ( V_31 , V_9 , V_10 + V_182 ) ;
F_7 ( V_31 , V_10 , V_147 ) ;
if ( V_182 )
F_20 ( V_31 , V_182 , NULL ) ;
V_68:
return V_31 ;
}
struct V_1 * F_54 ( const struct V_18 * V_19 )
{
struct V_1 * V_31 ;
struct V_183 * V_184 ;
struct V_185 V_186 ;
T_10 * V_187 ;
V_184 = F_55 ( V_19 ) ;
if ( F_56 ( ! V_184 ) )
return NULL ;
V_31 = F_19 ( V_19 , V_66 , 0 ,
V_184 -> V_188 + sizeof( V_189 ) ) ;
if ( ! V_31 )
return NULL ;
V_186 . V_190 = F_6 ( V_184 -> V_190 ) ;
V_186 . V_191 = F_6 ( V_19 -> V_192 ) ;
V_31 -> V_15 . V_186 = F_7 ( V_31 , sizeof( V_189 ) ,
& V_186 ) ;
V_187 = F_45 ( V_31 -> V_6 , V_184 -> V_188 ) ;
memset ( V_187 , 0 , V_184 -> V_188 ) ;
V_31 -> V_145 -> V_14 =
F_6 ( F_18 ( V_31 -> V_145 -> V_14 ) + V_184 -> V_188 ) ;
V_31 -> V_161 = F_46 ( V_31 -> V_6 ) ;
return V_31 ;
}
struct V_1 * F_57 ( struct V_193 * V_6 ,
const struct V_18 * V_19 ,
struct V_194 * V_26 )
{
struct V_1 * V_31 ;
V_31 = F_58 ( V_195 , V_196 ) ;
if ( ! V_31 )
goto V_68;
if ( ! V_26 ) {
F_31 ( L_3 , V_6 ) ;
}
F_59 ( & V_31 -> V_197 ) ;
V_31 -> V_6 = V_6 ;
V_31 -> V_19 = (struct V_18 * ) V_19 ;
V_31 -> V_198 = 0 ;
V_31 -> V_199 = 0 ;
V_31 -> V_200 = 0 ;
V_31 -> V_173 = 0 ;
V_31 -> V_201 = 1 ;
V_31 -> V_202 = 0 ;
V_31 -> V_203 = 0 ;
V_31 -> V_204 = 0 ;
V_31 -> V_205 = 0 ;
V_31 -> V_206 = 0 ;
V_31 -> V_207 = V_208 ;
V_31 -> V_151 = NULL ;
F_59 ( & V_31 -> V_209 ) ;
F_59 ( & V_31 -> V_210 ) ;
F_60 ( V_2 ) ;
F_61 ( & V_31 -> V_211 , 1 ) ;
V_68:
return V_31 ;
}
void F_62 ( struct V_1 * V_2 , union V_212 * V_213 ,
union V_212 * V_214 )
{
memcpy ( & V_2 -> V_215 , V_213 , sizeof( union V_212 ) ) ;
memcpy ( & V_2 -> V_214 , V_214 , sizeof( union V_212 ) ) ;
}
const union V_212 * F_63 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_89 ) {
return & V_2 -> V_89 -> V_172 ;
} else {
return & V_2 -> V_215 ;
}
}
T_19
struct V_1 * F_19 ( const struct V_18 * V_19 ,
T_10 type , T_10 V_103 , int V_10 )
{
struct V_1 * V_31 ;
T_20 * V_145 ;
struct V_193 * V_6 ;
struct V_194 * V_26 ;
V_6 = F_64 ( F_16 ( sizeof( T_20 ) + V_10 ) ,
V_196 ) ;
if ( ! V_6 )
goto V_68;
V_145 = ( T_20 * ) F_45 ( V_6 , sizeof( T_20 ) ) ;
V_145 -> type = type ;
V_145 -> V_103 = V_103 ;
V_145 -> V_14 = F_6 ( sizeof( T_20 ) ) ;
V_26 = V_19 ? V_19 -> V_25 . V_26 : NULL ;
V_31 = F_57 ( V_6 , V_19 , V_26 ) ;
if ( ! V_31 ) {
F_65 ( V_6 ) ;
goto V_68;
}
V_31 -> V_145 = V_145 ;
V_31 -> V_161 = ( ( T_10 * ) V_145 ) + sizeof( struct V_216 ) ;
if ( F_66 ( type , V_19 ) )
V_31 -> V_217 = 1 ;
V_6 -> V_26 = V_26 ;
return V_31 ;
V_68:
return NULL ;
}
static void F_67 ( struct V_1 * V_2 )
{
F_68 ( ! F_69 ( & V_2 -> V_197 ) ) ;
F_70 ( & V_2 -> V_209 ) ;
F_71 ( V_2 -> V_6 ) ;
F_72 ( V_2 ) ;
F_73 ( V_195 , V_2 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_151 )
F_74 ( V_2 -> V_151 ) ;
F_75 ( V_2 ) ;
}
void F_76 ( struct V_1 * V_218 )
{
F_77 ( & V_218 -> V_211 ) ;
}
void F_75 ( struct V_1 * V_218 )
{
if ( F_78 ( & V_218 -> V_211 ) )
F_67 ( V_218 ) ;
}
void * F_7 ( struct V_1 * V_2 , int V_12 , const void * V_158 )
{
void * V_159 ;
void * V_219 ;
int V_160 = F_18 ( V_2 -> V_145 -> V_14 ) ;
int V_220 = F_16 ( V_160 ) - V_160 ;
V_219 = F_45 ( V_2 -> V_6 , V_220 ) ;
V_159 = F_45 ( V_2 -> V_6 , V_12 ) ;
memset ( V_219 , 0 , V_220 ) ;
memcpy ( V_159 , V_158 , V_12 ) ;
V_2 -> V_145 -> V_14 = F_6 ( V_160 + V_220 + V_12 ) ;
V_2 -> V_161 = F_46 ( V_2 -> V_6 ) ;
return V_159 ;
}
void * F_10 ( struct V_1 * V_2 ,
int V_12 , const void * V_158 )
{
if ( F_9 ( V_2 -> V_6 ) >= V_12 )
return F_7 ( V_2 , V_12 , V_158 ) ;
else
return NULL ;
}
int F_79 ( struct V_1 * V_2 , int V_221 , int V_12 ,
struct V_222 * V_158 )
{
T_10 * V_159 ;
int V_11 = 0 ;
V_159 = F_45 ( V_2 -> V_6 , V_12 ) ;
if ( ( V_11 = F_80 ( V_159 , V_158 , V_221 , V_12 ) ) )
goto V_223;
V_2 -> V_145 -> V_14 =
F_6 ( F_18 ( V_2 -> V_145 -> V_14 ) + V_12 ) ;
V_2 -> V_161 = F_46 ( V_2 -> V_6 ) ;
V_223:
return V_11 ;
}
void F_81 ( struct V_1 * V_2 )
{
struct V_224 * V_151 ;
struct V_1 * V_225 ;
struct V_226 * V_109 ;
T_4 V_104 ;
T_4 V_227 ;
if ( V_2 -> V_199 )
return;
V_227 = F_18 ( V_2 -> V_15 . V_117 -> V_109 ) ;
V_109 = & V_2 -> V_19 -> V_228 -> V_223 ;
V_151 = V_2 -> V_151 ;
F_35 (lchunk, &msg->chunks, frag_list) {
if ( V_225 -> V_145 -> V_103 & V_115 ) {
V_104 = 0 ;
} else {
if ( V_225 -> V_145 -> V_103 & V_229 )
V_104 = F_82 ( V_109 , V_227 ) ;
else
V_104 = F_83 ( V_109 , V_227 ) ;
}
V_225 -> V_15 . V_117 -> V_104 = F_6 ( V_104 ) ;
V_225 -> V_199 = 1 ;
}
}
void F_84 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_198 ) {
V_2 -> V_15 . V_117 -> V_108 =
F_14 ( F_85 ( V_2 -> V_19 ) ) ;
V_2 -> V_198 = 1 ;
}
}
struct V_18 * F_86 ( const struct V_230 * V_80 ,
struct V_1 * V_2 ,
T_5 V_22 )
{
struct V_18 * V_19 ;
struct V_193 * V_6 ;
T_21 V_231 ;
struct V_3 * V_4 ;
V_231 = F_87 ( F_63 ( V_2 ) ) ;
V_19 = F_88 ( V_80 , V_80 -> V_25 . V_26 , V_231 , V_22 ) ;
if ( ! V_19 )
goto V_68;
V_19 -> V_232 = 1 ;
V_6 = V_2 -> V_6 ;
V_4 = F_2 ( F_3 ( F_4 ( V_6 ) -> V_7 ) ) ;
if ( F_56 ( ! V_4 ) )
goto V_233;
V_4 -> V_234 ( & V_19 -> V_45 . V_235 , V_6 , 1 ) ;
V_68:
return V_19 ;
V_233:
F_89 ( V_19 ) ;
return NULL ;
}
static T_12 * F_23 ( const struct V_230 * V_80 ,
const struct V_18 * V_19 ,
const struct V_1 * V_236 ,
int * V_78 ,
const T_10 * V_237 , int V_33 )
{
T_12 * V_31 ;
struct V_238 * V_77 ;
struct V_239 V_240 ;
int V_241 , V_242 ;
unsigned int V_243 ;
char * V_244 ;
V_241 = sizeof( T_11 ) +
( sizeof( struct V_238 ) -
sizeof( struct V_245 ) ) ;
V_242 = sizeof( struct V_245 )
+ F_18 ( V_236 -> V_145 -> V_14 ) + V_33 ;
if ( V_242 % V_246 )
V_242 += V_246
- ( V_242 % V_246 ) ;
* V_78 = V_241 + V_242 ;
V_31 = F_90 ( * V_78 , V_196 ) ;
if ( ! V_31 )
goto V_68;
V_77 = (struct V_238 * ) V_31 -> V_247 ;
V_31 -> V_248 . type = V_249 ;
V_31 -> V_248 . V_14 = F_6 ( * V_78 ) ;
V_77 -> V_45 = V_19 -> V_45 ;
V_77 -> V_45 . V_250 = V_33 ;
V_77 -> V_45 . V_84 = V_19 -> V_82 . V_84 ;
V_77 -> V_45 . V_63 = V_19 -> V_82 . V_63 ;
F_91 ( & V_77 -> V_45 . V_251 ) ;
F_92 ( V_19 -> V_252 , V_77 -> V_45 . V_251 ) ;
memcpy ( & V_77 -> V_45 . V_253 [ 0 ] , V_236 -> V_145 ,
F_18 ( V_236 -> V_145 -> V_14 ) ) ;
memcpy ( ( T_10 * ) & V_77 -> V_45 . V_253 [ 0 ] +
F_18 ( V_236 -> V_145 -> V_14 ) , V_237 , V_33 ) ;
if ( F_15 ( V_80 -> V_25 . V_26 ) -> V_187 ) {
struct V_254 V_255 ;
F_93 ( & V_240 , & V_77 -> V_45 , V_242 ) ;
V_243 = V_256 ;
V_244 = ( char * ) V_80 -> V_257 [ V_80 -> V_258 ] ;
V_255 . V_259 = F_15 ( V_80 -> V_25 . V_26 ) -> V_187 ;
V_255 . V_103 = 0 ;
if ( F_94 ( V_255 . V_259 , V_244 , V_243 ) ||
F_95 ( & V_255 , & V_240 , V_242 , V_77 -> V_260 ) )
goto V_261;
}
return V_31 ;
V_261:
F_21 ( V_31 ) ;
V_68:
* V_78 = 0 ;
return NULL ;
}
struct V_18 * F_96 (
const struct V_230 * V_80 ,
const struct V_18 * V_19 ,
struct V_1 * V_2 , T_5 V_22 ,
int * error , struct V_1 * * V_262 )
{
struct V_18 * V_31 = NULL ;
struct V_238 * V_77 ;
struct V_245 * V_263 ;
int V_241 , V_242 , V_264 ;
T_10 * V_265 = V_80 -> V_265 ;
struct V_239 V_240 ;
unsigned int V_243 , V_12 ;
char * V_244 ;
T_21 V_231 ;
struct V_193 * V_6 = V_2 -> V_6 ;
struct V_266 V_267 ;
struct V_254 V_255 ;
V_241 = sizeof( T_20 ) +
( sizeof( struct V_238 ) -
sizeof( struct V_245 ) ) ;
V_242 = F_18 ( V_2 -> V_145 -> V_14 ) - V_241 ;
V_264 = V_241 + sizeof( struct V_245 ) ;
V_12 = F_18 ( V_2 -> V_145 -> V_14 ) ;
if ( V_12 < V_264 + sizeof( struct V_216 ) )
goto V_268;
if ( V_242 % V_246 )
goto V_268;
V_77 = V_2 -> V_15 . V_91 ;
V_263 = & V_77 -> V_45 ;
if ( ! F_15 ( V_80 -> V_25 . V_26 ) -> V_187 )
goto V_269;
V_243 = V_256 ;
F_93 ( & V_240 , V_263 , V_242 ) ;
V_244 = ( char * ) V_80 -> V_257 [ V_80 -> V_258 ] ;
V_255 . V_259 = F_15 ( V_80 -> V_25 . V_26 ) -> V_187 ;
V_255 . V_103 = 0 ;
memset ( V_265 , 0x00 , V_270 ) ;
if ( F_94 ( V_255 . V_259 , V_244 , V_243 ) ||
F_95 ( & V_255 , & V_240 , V_242 , V_265 ) ) {
* error = - V_271 ;
goto V_233;
}
if ( memcmp ( V_265 , V_77 -> V_260 , V_270 ) ) {
V_244 = ( char * ) V_80 -> V_257 [ V_80 -> V_272 ] ;
memset ( V_265 , 0x00 , V_270 ) ;
if ( F_94 ( V_255 . V_259 , V_244 , V_243 ) ||
F_95 ( & V_255 , & V_240 , V_242 , V_265 ) ) {
* error = - V_271 ;
goto V_233;
}
if ( memcmp ( V_265 , V_77 -> V_260 , V_270 ) ) {
* error = - V_273 ;
goto V_233;
}
}
V_269:
if ( F_97 ( V_2 -> V_274 -> V_275 ) != V_263 -> V_46 ) {
* error = - V_276 ;
goto V_233;
}
if ( V_2 -> V_274 -> V_215 != V_263 -> V_235 . V_277 . V_278 ||
F_18 ( V_2 -> V_274 -> V_214 ) != V_263 -> V_279 ) {
* error = - V_280 ;
goto V_233;
}
if ( F_98 ( V_80 -> V_25 . V_26 , V_281 ) )
F_99 ( V_6 , & V_267 ) ;
else
F_91 ( & V_267 ) ;
if ( ! V_19 && F_100 ( V_263 -> V_251 , V_267 ) ) {
V_12 = F_18 ( V_2 -> V_145 -> V_14 ) ;
* V_262 = F_51 ( V_19 , V_2 , V_12 ) ;
if ( * V_262 ) {
T_22 V_282 = ( V_267 . V_283 -
V_263 -> V_251 . V_283 ) * 1000000L +
V_267 . V_284 - V_263 -> V_251 . V_284 ;
T_17 V_285 = F_14 ( V_282 ) ;
F_5 ( * V_262 , V_286 ,
sizeof( V_285 ) ) ;
F_7 ( * V_262 , sizeof( V_285 ) , & V_285 ) ;
* error = - V_287 ;
} else
* error = - V_271 ;
goto V_233;
}
V_231 = F_87 ( F_63 ( V_2 ) ) ;
V_31 = F_88 ( V_80 , V_80 -> V_25 . V_26 , V_231 , V_22 ) ;
if ( ! V_31 ) {
* error = - V_271 ;
goto V_233;
}
V_31 -> V_82 . V_288 = F_18 ( V_2 -> V_274 -> V_215 ) ;
memcpy ( & V_31 -> V_45 , V_263 , sizeof( * V_263 ) ) ;
if ( F_101 ( V_31 , V_263 ,
V_196 ) < 0 ) {
* error = - V_271 ;
goto V_233;
}
if ( F_69 ( & V_31 -> V_25 . V_79 . V_289 ) ) {
F_102 ( & V_31 -> V_25 . V_79 , & V_2 -> V_214 ,
V_290 , V_196 ) ;
}
V_31 -> V_291 = V_31 -> V_45 . V_53 ;
V_31 -> V_292 = V_31 -> V_291 - 1 ;
V_31 -> V_293 = V_31 -> V_45 . V_53 ;
V_31 -> V_294 = V_31 -> V_292 ;
V_31 -> V_82 . V_84 = V_31 -> V_45 . V_84 ;
V_31 -> V_82 . V_63 = V_31 -> V_45 . V_63 ;
return V_31 ;
V_233:
if ( V_31 )
F_89 ( V_31 ) ;
return NULL ;
V_268:
* error = - V_295 ;
goto V_233;
}
static int F_103 ( const struct V_18 * V_19 ,
T_23 V_296 ,
struct V_1 * V_2 ,
struct V_1 * * V_262 )
{
struct V_297 V_298 ;
T_4 V_12 ;
V_12 = F_16 ( sizeof( V_298 ) ) ;
if ( ! * V_262 )
* V_262 = F_51 ( V_19 , V_2 , V_12 ) ;
if ( * V_262 ) {
V_298 . V_299 = F_14 ( 1 ) ;
V_298 . type = V_296 ;
F_5 ( * V_262 , V_300 ,
sizeof( V_298 ) ) ;
F_7 ( * V_262 , sizeof( V_298 ) , & V_298 ) ;
}
return 0 ;
}
static int F_104 ( const struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_1 * * V_262 )
{
if ( ! * V_262 )
* V_262 = F_51 ( V_19 , V_2 , 0 ) ;
if ( * V_262 )
F_5 ( * V_262 , V_301 , 0 ) ;
return 0 ;
}
static int F_105 ( const struct V_18 * V_19 ,
struct V_162 * V_166 ,
const struct V_1 * V_2 ,
struct V_1 * * V_262 )
{
if ( * V_262 )
F_44 ( * V_262 ) ;
* V_262 = F_48 ( V_19 , V_2 , V_166 ) ;
return 0 ;
}
static int F_106 ( const struct V_18 * V_19 ,
union V_28 V_166 ,
struct V_1 * V_2 ,
struct V_1 * * V_262 )
{
T_4 V_12 = F_18 ( V_166 . V_248 -> V_14 ) ;
if ( * V_262 )
F_44 ( * V_262 ) ;
* V_262 = F_51 ( V_19 , V_2 , V_12 ) ;
if ( * V_262 ) {
F_5 ( * V_262 , V_302 , V_12 ) ;
F_7 ( * V_262 , V_12 , V_166 . V_71 ) ;
}
return 0 ;
}
static int F_107 ( struct V_24 * V_24 , union V_28 V_166 )
{
T_4 V_40 = F_18 ( V_166 . V_248 -> V_14 ) - sizeof( T_11 ) ;
int V_303 = 0 ;
int V_304 = 0 ;
int V_305 ;
for ( V_305 = 0 ; V_305 < V_40 ; V_305 ++ ) {
switch ( V_166 . V_306 -> V_307 [ V_305 ] ) {
case V_66 :
V_303 = 1 ;
break;
case V_61 :
case V_62 :
V_304 = 1 ;
break;
}
}
if ( V_24 -> V_57 . V_308 )
return 1 ;
if ( V_24 -> V_57 . V_60 && ! V_303 && V_304 )
return 0 ;
return 1 ;
}
static void F_108 ( struct V_18 * V_19 ,
union V_28 V_166 )
{
struct V_24 * V_24 = F_12 ( V_19 -> V_25 . V_26 ) ;
T_4 V_40 = F_18 ( V_166 . V_248 -> V_14 ) - sizeof( T_11 ) ;
int V_305 ;
for ( V_305 = 0 ; V_305 < V_40 ; V_305 ++ ) {
switch ( V_166 . V_306 -> V_307 [ V_305 ] ) {
case V_309 :
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
static T_24 F_109 ( const struct V_18 * V_19 ,
union V_28 V_166 ,
struct V_1 * V_2 ,
struct V_1 * * V_262 )
{
int V_31 = V_310 ;
switch ( V_166 . V_248 -> type & V_311 ) {
case V_312 :
V_31 = V_313 ;
break;
case V_314 :
break;
case V_315 :
V_31 = V_313 ;
case V_316 :
if ( NULL == * V_262 )
* V_262 = F_52 ( V_19 , V_2 ) ;
if ( * V_262 ) {
if ( ! F_8 ( * V_262 , V_317 ,
F_16 ( F_18 ( V_166 . V_248 -> V_14 ) ) ) )
F_10 ( * V_262 ,
F_16 ( F_18 ( V_166 . V_248 -> V_14 ) ) ,
V_166 . V_71 ) ;
} else {
V_31 = V_271 ;
}
break;
default:
break;
}
return V_31 ;
}
static T_24 F_110 ( struct V_24 * V_24 ,
const struct V_18 * V_19 ,
union V_28 V_166 ,
T_25 V_318 ,
struct V_1 * V_2 ,
struct V_1 * * V_152 )
{
struct V_319 * V_320 ;
int V_31 = V_310 ;
T_4 V_321 , V_322 = 0 ;
int V_305 ;
switch ( V_166 . V_248 -> type ) {
case V_323 :
case V_324 :
case V_325 :
case V_72 :
case V_249 :
case V_170 :
case V_326 :
case V_327 :
case V_74 :
break;
case V_73 :
if ( ! F_107 ( V_24 , V_166 ) )
return V_328 ;
break;
case V_329 :
if ( V_24 -> V_57 . V_60 )
break;
goto V_330;
case V_331 :
F_106 ( V_19 , V_166 , V_2 , V_152 ) ;
V_31 = V_328 ;
break;
case V_332 :
if ( V_24 -> V_57 . V_58 )
break;
goto V_330;
case V_333 :
if ( ! V_24 -> V_57 . V_64 )
goto V_330;
if ( V_334 !=
F_18 ( V_166 . V_248 -> V_14 ) - sizeof( T_11 ) ) {
F_105 ( V_19 , V_166 . V_248 ,
V_2 , V_152 ) ;
V_31 = V_328 ;
}
break;
case V_335 :
if ( ! V_24 -> V_57 . V_64 )
goto V_330;
if ( 260 < F_18 ( V_166 . V_248 -> V_14 ) ) {
F_105 ( V_19 , V_166 . V_248 ,
V_2 , V_152 ) ;
V_31 = V_328 ;
}
break;
case V_336 :
if ( ! V_24 -> V_57 . V_64 )
goto V_330;
V_320 = (struct V_319 * ) V_166 . V_248 ;
V_321 = ( F_18 ( V_166 . V_248 -> V_14 ) - sizeof( T_11 ) ) >> 1 ;
for ( V_305 = 0 ; V_305 < V_321 ; V_305 ++ ) {
V_322 = F_18 ( V_320 -> V_337 [ V_305 ] ) ;
if ( V_322 == V_338 )
break;
}
if ( V_322 != V_338 ) {
F_105 ( V_19 , V_166 . V_248 , V_2 ,
V_152 ) ;
V_31 = V_328 ;
}
break;
V_330:
default:
F_31 ( L_4 ,
F_18 ( V_166 . V_248 -> type ) , V_318 ) ;
V_31 = F_109 ( V_19 , V_166 , V_2 , V_152 ) ;
break;
}
return V_31 ;
}
int F_111 ( struct V_24 * V_24 , const struct V_18 * V_19 ,
T_25 V_318 ,
T_26 * V_253 ,
struct V_1 * V_2 ,
struct V_1 * * V_262 )
{
union V_28 V_166 ;
int V_339 = 0 ;
int V_340 ;
if ( ( 0 == V_253 -> V_69 . V_49 ) ||
( 0 == V_253 -> V_69 . V_51 ) ||
( 0 == V_253 -> V_69 . V_44 ) ||
( V_341 > F_97 ( V_253 -> V_69 . V_47 ) ) ) {
return F_104 ( V_19 , V_2 , V_262 ) ;
}
F_112 (param, peer_init, init_hdr.params) {
if ( V_249 == V_166 . V_248 -> type )
V_339 = 1 ;
}
if ( V_166 . V_71 != ( void * ) V_2 -> V_161 )
return F_105 ( V_19 , V_166 . V_248 , V_2 , V_262 ) ;
if ( ( V_87 == V_318 ) && ! V_339 )
return F_103 ( V_19 , V_249 ,
V_2 , V_262 ) ;
F_112 (param, peer_init, init_hdr.params) {
V_340 = F_110 ( V_24 , V_19 , V_166 , V_318 , V_2 , V_262 ) ;
switch ( V_340 ) {
case V_328 :
case V_271 :
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
int F_113 ( struct V_18 * V_19 , struct V_1 * V_2 ,
const union V_212 * V_235 ,
T_26 * V_253 , T_5 V_22 )
{
struct V_24 * V_24 = F_12 ( V_19 -> V_25 . V_26 ) ;
union V_28 V_166 ;
struct V_130 * V_89 ;
struct V_342 * V_343 , * V_232 ;
struct V_3 * V_4 ;
union V_212 V_344 ;
char * V_77 ;
int V_345 = 0 ;
if( ! F_114 ( V_19 , V_235 , V_22 , V_346 ) )
goto V_347;
if ( F_115 ( F_63 ( V_2 ) , V_235 ) )
V_345 = 1 ;
F_112 (param, peer_init, init_hdr.params) {
if ( ! V_345 && ( V_166 . V_248 -> type == V_323 ||
V_166 . V_248 -> type == V_324 ) ) {
V_4 = F_2 ( F_116 ( V_166 . V_248 -> type ) ) ;
V_4 -> V_348 ( & V_344 , V_166 . V_344 ,
V_2 -> V_274 -> V_215 , 0 ) ;
if ( F_115 ( F_63 ( V_2 ) , & V_344 ) )
V_345 = 1 ;
}
if ( ! F_117 ( V_19 , V_166 , V_235 , V_22 ) )
goto V_349;
}
if ( ! V_345 )
goto V_349;
if ( V_19 -> V_82 . V_86 && ( ! V_19 -> V_82 . V_350 ||
! V_19 -> V_82 . V_351 ) )
V_19 -> V_82 . V_86 = 0 ;
if ( ! V_24 -> V_57 . V_308 &&
( V_19 -> V_82 . V_85 && ! V_19 -> V_82 . V_86 ) ) {
V_19 -> V_82 . V_352 |= ( V_353 |
V_354 |
V_329 ) ;
V_19 -> V_82 . V_85 = 0 ;
goto V_349;
}
F_118 (pos, temp, &asoc->peer.transport_addr_list) {
V_89 = F_119 ( V_343 , struct V_130 , V_355 ) ;
if ( V_89 -> V_356 == V_357 ) {
F_120 ( V_19 , V_89 ) ;
}
}
V_19 -> V_82 . V_305 . V_44 =
F_97 ( V_253 -> V_69 . V_44 ) ;
V_19 -> V_82 . V_305 . V_47 =
F_97 ( V_253 -> V_69 . V_47 ) ;
V_19 -> V_82 . V_305 . V_49 =
F_18 ( V_253 -> V_69 . V_49 ) ;
V_19 -> V_82 . V_305 . V_51 =
F_18 ( V_253 -> V_69 . V_51 ) ;
V_19 -> V_82 . V_305 . V_53 =
F_97 ( V_253 -> V_69 . V_53 ) ;
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
V_19 -> V_45 . V_358 = V_19 -> V_82 . V_305 . V_44 ;
V_19 -> V_82 . V_48 = V_19 -> V_82 . V_305 . V_47 ;
V_77 = V_19 -> V_82 . V_77 ;
if ( V_77 ) {
V_19 -> V_82 . V_77 = F_121 ( V_77 , V_19 -> V_82 . V_78 , V_22 ) ;
if ( ! V_19 -> V_82 . V_77 )
goto V_349;
}
F_35 (transport, &asoc->peer.transport_addr_list,
transports) {
V_89 -> V_359 = V_19 -> V_82 . V_305 . V_47 ;
}
if ( ! F_122 ( & V_19 -> V_82 . V_126 , V_360 ,
V_19 -> V_82 . V_305 . V_53 , V_22 ) )
goto V_349;
if ( ! V_19 -> V_232 ) {
int error ;
V_19 -> V_228 = F_123 ( V_19 -> V_45 . V_52 ,
V_19 -> V_45 . V_50 , V_22 ) ;
if ( ! V_19 -> V_228 )
goto V_349;
error = F_124 ( V_19 , V_22 ) ;
if ( error )
goto V_349;
}
V_19 -> V_82 . V_293 = V_19 -> V_82 . V_305 . V_53 - 1 ;
return 1 ;
V_349:
F_118 (pos, temp, &asoc->peer.transport_addr_list) {
V_89 = F_119 ( V_343 , struct V_130 , V_355 ) ;
if ( V_89 -> V_356 != V_346 )
F_120 ( V_19 , V_89 ) ;
}
V_347:
return 0 ;
}
static int F_117 ( struct V_18 * V_19 ,
union V_28 V_166 ,
const union V_212 * V_235 ,
T_5 V_22 )
{
struct V_24 * V_24 = F_12 ( V_19 -> V_25 . V_26 ) ;
union V_212 V_344 ;
int V_305 ;
T_4 V_36 ;
int V_31 = 1 ;
T_21 V_231 ;
T_27 V_361 ;
struct V_3 * V_4 ;
union V_362 * V_363 ;
struct V_130 * V_364 ;
switch ( V_166 . V_248 -> type ) {
case V_324 :
if ( V_365 != V_19 -> V_25 . V_26 -> V_366 )
break;
goto V_367;
case V_323 :
if ( F_125 ( V_19 -> V_25 . V_26 ) )
break;
V_367:
V_4 = F_2 ( F_116 ( V_166 . V_248 -> type ) ) ;
V_4 -> V_348 ( & V_344 , V_166 . V_344 , F_6 ( V_19 -> V_82 . V_288 ) , 0 ) ;
V_231 = F_87 ( V_235 ) ;
if ( F_126 ( V_24 , & V_344 , V_231 ) )
if ( ! F_114 ( V_19 , & V_344 , V_22 , V_368 ) )
return 0 ;
break;
case V_325 :
if ( ! V_24 -> V_57 . V_369 )
break;
V_361 = F_97 ( V_166 . V_370 -> V_371 ) ;
V_19 -> V_252 . V_283 += V_361 / 1000 ;
V_19 -> V_252 . V_284 += ( V_361 % 1000 ) * 1000 ;
break;
case V_331 :
F_31 ( L_5 ) ;
break;
case V_72 :
V_19 -> V_82 . V_372 = 0 ;
V_19 -> V_82 . V_373 = 0 ;
if ( V_235 -> V_374 . V_375 == V_376 )
V_19 -> V_82 . V_373 = 1 ;
else if ( V_235 -> V_374 . V_375 == V_377 )
V_19 -> V_82 . V_372 = 1 ;
V_36 = F_18 ( V_166 . V_248 -> V_14 ) - sizeof( T_11 ) ;
if ( V_36 )
V_36 /= sizeof( T_4 ) ;
for ( V_305 = 0 ; V_305 < V_36 ; ++ V_305 ) {
switch ( V_166 . V_36 -> V_37 [ V_305 ] ) {
case V_323 :
V_19 -> V_82 . V_372 = 1 ;
break;
case V_324 :
if ( V_365 == V_19 -> V_25 . V_26 -> V_366 )
V_19 -> V_82 . V_373 = 1 ;
break;
case V_331 :
V_19 -> V_82 . V_378 = 1 ;
break;
default:
break;
}
}
break;
case V_249 :
V_19 -> V_82 . V_78 =
F_18 ( V_166 . V_248 -> V_14 ) - sizeof( T_11 ) ;
V_19 -> V_82 . V_77 = V_166 . V_77 -> V_247 ;
break;
case V_170 :
break;
case V_326 :
break;
case V_327 :
V_19 -> V_82 . V_83 = 1 ;
break;
case V_74 :
V_19 -> V_82 . V_63 = F_97 ( V_166 . V_379 -> V_63 ) ;
break;
case V_329 :
if ( ! V_24 -> V_57 . V_60 )
goto V_380;
V_363 = V_166 . V_71 + sizeof( V_381 ) ;
V_4 = F_2 ( F_116 ( V_166 . V_248 -> type ) ) ;
V_4 -> V_348 ( & V_344 , V_363 ,
F_6 ( V_19 -> V_82 . V_288 ) , 0 ) ;
if ( ! V_4 -> V_382 ( & V_344 , NULL , NULL ) )
break;
V_364 = F_127 ( V_19 , & V_344 ) ;
if ( ! V_364 )
break;
F_128 ( V_19 , V_364 ) ;
break;
case V_73 :
F_108 ( V_19 , V_166 ) ;
break;
case V_332 :
if ( V_24 -> V_57 . V_58 ) {
V_19 -> V_82 . V_84 = 1 ;
break;
}
goto V_380;
case V_333 :
if ( ! V_24 -> V_57 . V_64 )
goto V_380;
V_19 -> V_82 . V_350 = F_121 ( V_166 . V_248 ,
F_18 ( V_166 . V_248 -> V_14 ) , V_22 ) ;
if ( ! V_19 -> V_82 . V_350 ) {
V_31 = 0 ;
break;
}
break;
case V_336 :
if ( ! V_24 -> V_57 . V_64 )
goto V_380;
V_19 -> V_82 . V_351 = F_121 ( V_166 . V_248 ,
F_18 ( V_166 . V_248 -> V_14 ) , V_22 ) ;
if ( ! V_19 -> V_82 . V_351 ) {
V_31 = 0 ;
break;
}
F_129 ( V_19 , V_166 . V_383 ) ;
break;
case V_335 :
if ( ! V_24 -> V_57 . V_64 )
goto V_380;
V_19 -> V_82 . V_384 = F_121 ( V_166 . V_248 ,
F_18 ( V_166 . V_248 -> V_14 ) , V_22 ) ;
if ( ! V_19 -> V_82 . V_384 )
V_31 = 0 ;
break;
V_380:
default:
F_31 ( L_6 ,
F_18 ( V_166 . V_248 -> type ) , V_19 ) ;
break;
}
return V_31 ;
}
T_13 F_130 ( const struct V_230 * V_80 )
{
T_13 V_385 ;
do {
F_131 ( & V_385 , sizeof( T_13 ) ) ;
} while ( V_385 == 0 );
return V_385 ;
}
T_13 F_132 ( const struct V_230 * V_80 )
{
T_13 V_31 ;
F_131 ( & V_31 , sizeof( T_13 ) ) ;
return V_31 ;
}
static struct V_1 * F_133 ( struct V_18 * V_19 ,
union V_212 * V_344 ,
int V_23 )
{
T_28 V_386 ;
struct V_1 * V_31 ;
int V_14 = sizeof( V_386 ) + V_23 ;
union V_362 V_387 ;
int V_388 ;
struct V_3 * V_4 = F_2 ( V_344 -> V_277 . V_389 ) ;
V_388 = V_4 -> V_390 ( V_344 , & V_387 ) ;
if ( ! V_388 )
return NULL ;
V_14 += V_388 ;
V_31 = F_19 ( V_19 , V_61 , 0 , V_14 ) ;
if ( ! V_31 )
return NULL ;
V_386 . V_391 = F_14 ( V_19 -> V_293 ++ ) ;
V_31 -> V_15 . V_392 =
F_7 ( V_31 , sizeof( V_386 ) , & V_386 ) ;
V_31 -> V_70 . V_71 =
F_7 ( V_31 , V_388 , & V_387 ) ;
return V_31 ;
}
struct V_1 * F_134 ( struct V_18 * V_19 ,
union V_212 * V_393 ,
struct V_394 * V_29 ,
int V_395 ,
T_1 V_103 )
{
V_381 V_166 ;
struct V_1 * V_31 ;
union V_362 V_363 ;
union V_212 * V_344 ;
void * V_396 ;
struct V_3 * V_4 ;
int V_397 = sizeof( V_166 ) ;
int V_398 = 0 ;
int V_399 = 0 ;
int V_305 ;
int V_400 = 0 ;
V_396 = V_29 ;
for ( V_305 = 0 ; V_305 < V_395 ; V_305 ++ ) {
V_344 = V_396 ;
V_4 = F_2 ( V_344 -> V_277 . V_389 ) ;
V_398 = V_4 -> V_390 ( V_344 , & V_363 ) ;
V_399 += V_397 ;
V_399 += V_398 ;
V_396 += V_4 -> V_401 ;
if ( V_19 -> V_402 && ! V_400 ) {
V_399 += V_397 ;
V_399 += V_398 ;
V_400 = 1 ;
F_31 ( L_7 , V_399 ) ;
}
}
V_31 = F_133 ( V_19 , V_393 , V_399 ) ;
if ( ! V_31 )
return NULL ;
V_396 = V_29 ;
for ( V_305 = 0 ; V_305 < V_395 ; V_305 ++ ) {
V_344 = V_396 ;
V_4 = F_2 ( V_344 -> V_277 . V_389 ) ;
V_398 = V_4 -> V_390 ( V_344 , & V_363 ) ;
V_166 . V_70 . type = V_103 ;
V_166 . V_70 . V_14 = F_6 ( V_397 + V_398 ) ;
V_166 . V_403 = V_305 ;
F_7 ( V_31 , V_397 , & V_166 ) ;
F_7 ( V_31 , V_398 , & V_363 ) ;
V_396 += V_4 -> V_401 ;
}
if ( V_103 == V_353 && V_400 ) {
V_344 = V_19 -> V_402 ;
V_4 = F_2 ( V_344 -> V_277 . V_389 ) ;
V_398 = V_4 -> V_390 ( V_344 , & V_363 ) ;
V_166 . V_70 . type = V_354 ;
V_166 . V_70 . V_14 = F_6 ( V_397 + V_398 ) ;
V_166 . V_403 = V_305 ;
F_7 ( V_31 , V_397 , & V_166 ) ;
F_7 ( V_31 , V_398 , & V_363 ) ;
}
return V_31 ;
}
struct V_1 * F_135 ( struct V_18 * V_19 ,
union V_212 * V_344 )
{
V_381 V_166 ;
struct V_1 * V_31 ;
int V_12 = sizeof( V_166 ) ;
union V_362 V_387 ;
int V_388 ;
struct V_3 * V_4 = F_2 ( V_344 -> V_277 . V_389 ) ;
V_388 = V_4 -> V_390 ( V_344 , & V_387 ) ;
if ( ! V_388 )
return NULL ;
V_12 += V_388 ;
V_31 = F_133 ( V_19 , V_344 , V_12 ) ;
if ( ! V_31 )
return NULL ;
V_166 . V_70 . type = V_329 ;
V_166 . V_70 . V_14 = F_6 ( V_12 ) ;
V_166 . V_403 = 0 ;
F_7 ( V_31 , sizeof( V_166 ) , & V_166 ) ;
F_7 ( V_31 , V_388 , & V_387 ) ;
return V_31 ;
}
static struct V_1 * F_136 ( const struct V_18 * V_19 ,
T_13 V_391 , int V_23 )
{
T_28 V_386 ;
struct V_1 * V_31 ;
int V_14 = sizeof( V_386 ) + V_23 ;
V_31 = F_19 ( V_19 , V_62 , 0 , V_14 ) ;
if ( ! V_31 )
return NULL ;
V_386 . V_391 = F_14 ( V_391 ) ;
V_31 -> V_15 . V_392 =
F_7 ( V_31 , sizeof( V_386 ) , & V_386 ) ;
return V_31 ;
}
static void F_137 ( struct V_1 * V_2 , T_17 V_403 ,
T_1 V_404 , V_381 * V_405 )
{
V_381 V_406 ;
T_3 V_407 ;
int V_408 = 0 ;
int V_409 = 0 ;
T_1 V_410 ;
if ( V_411 == V_404 ) {
V_410 = V_412 ;
} else {
V_410 = V_413 ;
V_409 = sizeof( V_407 ) ;
if ( V_405 )
V_408 =
F_18 ( V_405 -> V_70 . V_14 ) ;
}
V_406 . V_70 . type = V_410 ;
V_406 . V_70 . V_14 = F_6 ( sizeof( V_406 ) +
V_409 +
V_408 ) ;
V_406 . V_403 = V_403 ;
F_7 ( V_2 , sizeof( V_406 ) , & V_406 ) ;
if ( V_411 == V_404 )
return;
V_407 . V_13 = V_404 ;
V_407 . V_14 = F_6 ( V_409 + V_408 ) ;
F_7 ( V_2 , V_409 , & V_407 ) ;
if ( V_405 )
F_7 ( V_2 , V_408 , V_405 ) ;
}
static T_1 F_138 ( struct V_18 * V_19 ,
struct V_1 * V_386 ,
V_381 * V_405 )
{
struct V_130 * V_82 ;
struct V_3 * V_4 ;
union V_212 V_344 ;
union V_362 * V_363 ;
V_363 = ( void * ) V_405 + sizeof( V_381 ) ;
if ( V_405 -> V_70 . type != V_353 &&
V_405 -> V_70 . type != V_354 &&
V_405 -> V_70 . type != V_329 )
return V_317 ;
switch ( V_363 -> V_248 . type ) {
case V_324 :
if ( ! V_19 -> V_82 . V_373 )
return V_302 ;
break;
case V_323 :
if ( ! V_19 -> V_82 . V_372 )
return V_302 ;
break;
default:
return V_302 ;
}
V_4 = F_2 ( F_116 ( V_363 -> V_248 . type ) ) ;
if ( F_56 ( ! V_4 ) )
return V_302 ;
V_4 -> V_348 ( & V_344 , V_363 , F_6 ( V_19 -> V_82 . V_288 ) , 0 ) ;
if ( ! V_4 -> V_414 ( & V_344 ) && ! V_4 -> V_382 ( & V_344 , NULL , V_386 -> V_6 ) )
return V_302 ;
switch ( V_405 -> V_70 . type ) {
case V_353 :
if ( V_4 -> V_414 ( & V_344 ) )
memcpy ( & V_344 , & V_386 -> V_215 , sizeof( V_344 ) ) ;
V_82 = F_114 ( V_19 , & V_344 , V_196 , V_368 ) ;
if ( ! V_82 )
return V_415 ;
if ( ! F_139 ( & V_82 -> V_416 , F_140 ( V_82 ) ) )
F_141 ( V_82 ) ;
V_19 -> V_417 = V_82 ;
break;
case V_354 :
if ( V_19 -> V_82 . V_418 == 1 )
return V_419 ;
if ( F_115 ( & V_386 -> V_215 , & V_344 ) )
return V_420 ;
if ( V_4 -> V_414 ( & V_344 ) ) {
F_128 ( V_19 , V_386 -> V_89 ) ;
F_142 ( V_19 ,
V_386 -> V_89 ) ;
} else
F_143 ( V_19 , & V_344 ) ;
break;
case V_329 :
if ( V_4 -> V_414 ( & V_344 ) )
memcpy ( & V_344 . V_277 , F_63 ( V_386 ) , sizeof( V_344 ) ) ;
V_82 = F_127 ( V_19 , & V_344 ) ;
if ( ! V_82 )
return V_302 ;
F_128 ( V_19 , V_82 ) ;
break;
}
return V_411 ;
}
int F_144 ( const struct V_18 * V_19 ,
struct V_162 * V_70 , void * V_161 ,
struct V_162 * * V_262 ) {
V_381 * V_405 ;
union V_28 V_166 ;
int V_14 , V_421 ;
V_166 . V_71 = ( T_11 * ) V_70 ;
while ( V_166 . V_71 <= V_161 - sizeof( T_11 ) ) {
V_14 = F_18 ( V_166 . V_248 -> V_14 ) ;
* V_262 = V_166 . V_248 ;
if ( V_166 . V_71 > V_161 - V_14 ||
V_14 < sizeof( T_11 ) )
return 0 ;
switch ( V_166 . V_248 -> type ) {
case V_353 :
case V_354 :
case V_329 :
V_405 = ( V_381 * ) V_166 . V_71 ;
V_421 = F_18 ( V_405 -> V_70 . V_14 ) ;
if ( V_421 < sizeof( V_381 ) +
sizeof( T_11 ) )
return 0 ;
break;
case V_412 :
case V_74 :
if ( V_14 != sizeof( V_381 ) )
return 0 ;
break;
default:
break;
}
V_166 . V_71 += F_16 ( V_14 ) ;
}
if ( V_166 . V_71 != V_161 )
return 0 ;
return 1 ;
}
struct V_1 * F_145 ( struct V_18 * V_19 ,
struct V_1 * V_386 )
{
T_28 * V_422 ;
union V_362 * V_363 ;
V_381 * V_405 ;
struct V_1 * V_423 ;
T_1 V_404 ;
int V_14 = 0 ;
int V_107 ;
T_13 V_391 ;
int V_424 = 1 ;
V_107 = F_18 ( V_386 -> V_145 -> V_14 ) - sizeof( T_20 ) ;
V_422 = ( T_28 * ) V_386 -> V_6 -> V_158 ;
V_391 = F_97 ( V_422 -> V_391 ) ;
V_14 = sizeof( T_28 ) ;
V_363 = (union V_362 * ) ( V_386 -> V_6 -> V_158 + V_14 ) ;
V_107 -= V_14 ;
V_14 = F_18 ( V_363 -> V_248 . V_14 ) ;
V_405 = ( void * ) V_363 + V_14 ;
V_107 -= V_14 ;
V_423 = F_136 ( V_19 , V_391 , V_107 * 4 ) ;
if ( ! V_423 )
goto V_425;
while ( V_107 > 0 ) {
V_404 = F_138 ( V_19 , V_386 ,
V_405 ) ;
if ( V_411 != V_404 )
V_424 = 0 ;
if ( ! V_424 )
F_137 ( V_423 ,
V_405 -> V_403 , V_404 ,
V_405 ) ;
if ( V_415 == V_404 )
goto V_425;
V_14 = F_18 ( V_405 -> V_70 . V_14 ) ;
V_405 = ( void * ) V_405 + V_14 ;
V_107 -= V_14 ;
}
V_425:
V_19 -> V_82 . V_293 ++ ;
if ( V_423 ) {
F_76 ( V_423 ) ;
F_146 ( & V_423 -> V_209 ,
& V_19 -> V_426 ) ;
}
return V_423 ;
}
static void F_147 ( struct V_18 * V_19 ,
V_381 * V_405 )
{
struct V_3 * V_4 ;
union V_212 V_344 ;
struct V_20 * V_21 = & V_19 -> V_25 . V_79 ;
union V_362 * V_363 ;
struct V_130 * V_89 ;
struct V_427 * V_428 ;
V_363 = ( void * ) V_405 + sizeof( V_381 ) ;
V_4 = F_2 ( F_116 ( V_363 -> V_248 . type ) ) ;
V_4 -> V_348 ( & V_344 , V_363 , F_6 ( V_21 -> V_288 ) , 0 ) ;
switch ( V_405 -> V_70 . type ) {
case V_353 :
F_148 () ;
F_35 (saddr, &bp->address_list, list) {
if ( F_115 ( & V_428 -> V_429 , & V_344 ) )
V_428 -> V_356 = V_290 ;
}
F_149 () ;
F_35 (transport, &asoc->peer.transport_addr_list,
transports) {
F_150 ( V_89 -> V_430 ) ;
V_89 -> V_430 = NULL ;
}
break;
case V_354 :
F_148 () ;
F_151 ( V_21 , & V_344 ) ;
if ( V_19 -> V_402 != NULL &&
F_115 ( V_19 -> V_402 , & V_344 ) ) {
F_21 ( V_19 -> V_402 ) ;
V_19 -> V_402 = NULL ;
}
F_149 () ;
F_35 (transport, &asoc->peer.transport_addr_list,
transports) {
F_150 ( V_89 -> V_430 ) ;
V_89 -> V_430 = NULL ;
}
break;
default:
break;
}
}
static T_1 F_152 ( struct V_1 * V_423 ,
V_381 * V_405 ,
int V_431 )
{
V_381 * V_432 ;
T_3 * V_407 ;
int V_14 ;
int V_433 ;
T_1 V_404 ;
if ( V_431 )
V_404 = V_411 ;
else
V_404 = V_434 ;
V_433 = F_18 ( V_423 -> V_145 -> V_14 ) -
sizeof( T_20 ) ;
V_14 = sizeof( T_28 ) ;
V_432 = ( V_381 * ) ( V_423 -> V_6 -> V_158 +
V_14 ) ;
V_433 -= V_14 ;
while ( V_433 > 0 ) {
if ( V_432 -> V_403 == V_405 -> V_403 ) {
switch( V_432 -> V_70 . type ) {
case V_412 :
return V_411 ;
case V_413 :
V_14 = sizeof( V_381 ) ;
V_407 = ( void * ) V_432 + V_14 ;
V_433 -= V_14 ;
if ( V_433 > 0 )
return V_407 -> V_13 ;
else
return V_301 ;
break;
default:
return V_301 ;
}
}
V_14 = F_18 ( V_432 -> V_70 . V_14 ) ;
V_432 = ( void * ) V_432 + V_14 ;
V_433 -= V_14 ;
}
return V_404 ;
}
int F_153 ( struct V_18 * V_19 ,
struct V_1 * V_423 )
{
struct V_1 * V_386 = V_19 -> V_435 ;
union V_362 * V_363 ;
V_381 * V_405 ;
int V_14 = 0 ;
int V_436 = V_386 -> V_6 -> V_12 ;
int V_424 = 0 ;
int V_431 = 1 ;
int V_31 = 0 ;
T_1 V_404 = V_411 ;
V_14 = sizeof( V_437 ) ;
V_363 = (union V_362 * ) ( V_386 -> V_6 -> V_158 + V_14 ) ;
V_436 -= V_14 ;
V_14 = F_18 ( V_363 -> V_248 . V_14 ) ;
V_405 = ( void * ) V_363 + V_14 ;
V_436 -= V_14 ;
if ( V_423 -> V_6 -> V_12 == sizeof( T_28 ) )
V_424 = 1 ;
while ( V_436 > 0 ) {
if ( V_424 )
V_404 = V_411 ;
else {
V_404 = F_152 ( V_423 ,
V_405 ,
V_431 ) ;
if ( V_431 && ( V_411 != V_404 ) )
V_431 = 0 ;
}
switch ( V_404 ) {
case V_411 :
F_147 ( V_19 , V_405 ) ;
break;
case V_415 :
V_31 = 1 ;
break;
case V_317 :
V_19 -> V_82 . V_352 |=
V_405 -> V_70 . type ;
break;
case V_434 :
case V_419 :
case V_420 :
default:
break;
}
V_14 = F_18 ( V_405 -> V_70 . V_14 ) ;
V_405 = ( void * ) V_405 + V_14 ;
V_436 -= V_14 ;
}
if ( V_431 && V_19 -> V_438 ) {
V_19 -> V_438 = 0 ;
F_154 ( V_19 -> V_82 . V_439 ) ;
}
F_70 ( & V_386 -> V_209 ) ;
F_44 ( V_386 ) ;
V_19 -> V_435 = NULL ;
return V_31 ;
}
struct V_1 * F_155 ( const struct V_18 * V_19 ,
T_13 V_440 , T_2 V_441 ,
struct V_442 * V_443 )
{
struct V_1 * V_31 = NULL ;
struct V_444 V_445 ;
struct V_442 V_446 ;
T_2 V_144 ;
int V_305 ;
V_144 = ( V_441 + 1 ) * sizeof( T_13 ) ;
V_31 = F_19 ( V_19 , V_309 , 0 , V_144 ) ;
if ( ! V_31 )
return NULL ;
V_445 . V_440 = F_14 ( V_440 ) ;
V_31 -> V_15 . V_447 =
F_7 ( V_31 , sizeof( V_445 ) , & V_445 ) ;
for ( V_305 = 0 ; V_305 < V_441 ; V_305 ++ ) {
V_446 . V_109 = V_443 [ V_305 ] . V_109 ;
V_446 . V_104 = V_443 [ V_305 ] . V_104 ;
F_7 ( V_31 , sizeof( V_446 ) , & V_446 ) ;
}
return V_31 ;
}

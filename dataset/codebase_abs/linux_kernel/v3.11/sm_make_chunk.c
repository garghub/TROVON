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
F_31 ( L_1 , V_132 , V_120 ) ;
V_121 = F_32 ( V_125 , V_128 ) ;
V_122 = F_33 ( V_125 ) ;
V_119 . V_133 = F_14 ( V_120 ) ;
V_119 . V_47 = F_14 ( V_19 -> V_47 ) ;
V_119 . V_134 = F_6 ( V_121 ) ;
V_119 . V_122 = F_6 ( V_122 ) ;
V_12 = sizeof( V_119 )
+ sizeof( struct V_127 ) * V_121
+ sizeof( T_13 ) * V_122 ;
V_31 = F_19 ( V_19 , V_135 , 0 , V_12 ) ;
if ( ! V_31 )
goto V_68;
V_31 -> V_89 = V_19 -> V_82 . V_136 ;
V_31 -> V_15 . V_137 =
F_7 ( V_31 , sizeof( V_119 ) , & V_119 ) ;
if ( V_121 )
F_7 ( V_31 , sizeof( T_13 ) * V_121 ,
V_128 ) ;
if ( V_122 ) {
V_123 -> V_138 . V_139 += V_122 ;
F_7 ( V_31 , sizeof( T_13 ) * V_122 ,
F_34 ( V_125 ) ) ;
}
if ( ++ V_123 -> V_82 . V_140 == 0 ) {
F_35 (trans, &asoc->peer.transport_addr_list,
transports)
V_131 -> V_140 = 0 ;
V_123 -> V_82 . V_140 = 1 ;
}
V_68:
return V_31 ;
}
struct V_1 * F_36 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
struct V_1 * V_31 ;
T_16 V_141 ;
T_13 V_120 ;
V_120 = F_30 ( & V_19 -> V_82 . V_126 ) ;
V_141 . V_133 = F_14 ( V_120 ) ;
V_31 = F_19 ( V_19 , V_142 , 0 ,
sizeof( T_16 ) ) ;
if ( ! V_31 )
goto V_68;
V_31 -> V_15 . V_143 =
F_7 ( V_31 , sizeof( V_141 ) , & V_141 ) ;
if ( V_2 )
V_31 -> V_89 = V_2 -> V_89 ;
V_68:
return V_31 ;
}
struct V_1 * F_37 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
struct V_1 * V_31 ;
V_31 = F_19 ( V_19 , V_144 , 0 , 0 ) ;
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
V_103 |= V_19 ? 0 : V_145 ;
V_31 = F_19 ( V_19 , V_146 , V_103 , 0 ) ;
if ( V_31 && V_2 )
V_31 -> V_89 = V_2 -> V_89 ;
return V_31 ;
}
struct V_1 * F_39 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
const T_2 V_147 )
{
struct V_1 * V_31 ;
T_10 V_103 = 0 ;
if ( ! V_19 ) {
if ( V_2 && V_2 -> V_148 &&
V_2 -> V_148 -> type == V_67 )
V_103 = 0 ;
else
V_103 = V_145 ;
}
V_31 = F_19 ( V_19 , V_149 , V_103 , V_147 ) ;
if ( V_31 && V_2 )
V_31 -> V_89 = V_2 -> V_89 ;
return V_31 ;
}
struct V_1 * F_40 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 , T_13 V_108 )
{
struct V_1 * V_31 ;
T_17 V_150 ;
V_31 = F_39 ( V_19 , V_2 , sizeof( T_3 )
+ sizeof( V_108 ) ) ;
if ( ! V_31 )
goto V_151;
V_150 = F_14 ( V_108 ) ;
F_5 ( V_31 , V_152 , sizeof( V_150 ) ) ;
F_7 ( V_31 , sizeof( V_150 ) , ( const void * ) & V_150 ) ;
if ( V_2 )
V_31 -> V_89 = V_2 -> V_89 ;
V_151:
return V_31 ;
}
struct V_1 * F_41 ( const struct V_18 * V_19 ,
const struct V_153 * V_154 ,
T_2 V_10 )
{
struct V_1 * V_31 ;
void * V_150 = NULL ;
int V_11 ;
V_31 = F_39 ( V_19 , NULL , sizeof( T_3 ) + V_10 ) ;
if ( ! V_31 )
goto V_155;
if ( V_10 ) {
V_150 = F_42 ( V_10 , V_156 ) ;
if ( ! V_150 )
goto V_157;
V_11 = F_43 ( V_150 , V_154 -> V_158 , V_10 ) ;
if ( V_11 < 0 )
goto V_159;
}
F_5 ( V_31 , V_160 , V_10 ) ;
F_7 ( V_31 , V_10 , V_150 ) ;
if ( V_10 )
F_21 ( V_150 ) ;
return V_31 ;
V_159:
F_21 ( V_150 ) ;
V_157:
F_44 ( V_31 ) ;
V_31 = NULL ;
V_155:
return V_31 ;
}
static void * F_20 ( struct V_1 * V_2 , int V_12 ,
const void * V_161 )
{
void * V_162 ;
int V_163 = F_18 ( V_2 -> V_148 -> V_14 ) ;
V_162 = F_45 ( V_2 -> V_6 , V_12 ) ;
if ( V_161 )
memcpy ( V_162 , V_161 , V_12 ) ;
else
memset ( V_162 , 0 , V_12 ) ;
V_2 -> V_148 -> V_14 = F_6 ( V_163 + V_12 ) ;
V_2 -> V_164 = F_46 ( V_2 -> V_6 ) ;
return V_162 ;
}
struct V_1 * F_47 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
const T_10 * V_150 ,
const T_2 V_10 )
{
struct V_1 * V_31 ;
struct V_165 V_166 ;
V_31 = F_39 ( V_19 , V_2 , sizeof( T_3 ) + V_10
+ sizeof( T_11 ) ) ;
if ( ! V_31 )
goto V_167;
F_5 ( V_31 , V_168 , V_10
+ sizeof( T_11 ) ) ;
V_166 . type = F_6 ( V_2 -> V_148 -> type ) ;
V_166 . V_14 = V_2 -> V_148 -> V_14 ;
F_7 ( V_31 , V_10 , V_150 ) ;
F_20 ( V_31 , sizeof( T_11 ) , & V_166 ) ;
V_167:
return V_31 ;
}
struct V_1 * F_48 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
struct V_165 * V_169 )
{
struct V_1 * V_31 ;
static const char error [] = L_2 ;
T_2 V_170 = sizeof( error ) + sizeof( T_3 ) +
sizeof( T_11 ) ;
V_31 = F_39 ( V_19 , V_2 , V_170 ) ;
if ( ! V_31 )
goto V_68;
F_5 ( V_31 , V_168 ,
sizeof( error ) + sizeof( T_11 ) ) ;
F_7 ( V_31 , sizeof( error ) , error ) ;
F_20 ( V_31 , sizeof( T_11 ) , V_169 ) ;
V_68:
return V_31 ;
}
struct V_1 * F_49 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
struct V_1 * V_31 ;
static const char error [] = L_3 ;
T_2 V_170 = sizeof( error ) + sizeof( T_3 ) ;
V_31 = F_39 ( V_19 , V_2 , V_170 ) ;
if ( ! V_31 )
goto V_68;
F_5 ( V_31 , V_168 , sizeof( error ) ) ;
F_7 ( V_31 , sizeof( error ) , error ) ;
V_68:
return V_31 ;
}
struct V_1 * F_50 ( const struct V_18 * V_19 ,
const struct V_130 * V_89 )
{
struct V_1 * V_31 ;
T_18 V_171 ;
V_31 = F_19 ( V_19 , V_172 , 0 , sizeof( V_171 ) ) ;
if ( ! V_31 )
goto V_68;
V_171 . V_70 . type = V_173 ;
V_171 . V_70 . V_14 = F_6 ( sizeof( T_18 ) ) ;
V_171 . V_174 = V_89 -> V_175 ;
V_171 . V_176 = V_177 ;
V_171 . V_178 = V_89 -> V_178 ;
V_31 -> V_89 = (struct V_130 * ) V_89 ;
V_31 -> V_15 . V_179 = F_7 ( V_31 , sizeof( V_171 ) ,
& V_171 ) ;
V_68:
return V_31 ;
}
struct V_1 * F_51 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
const void * V_150 , const T_2 V_10 )
{
struct V_1 * V_31 ;
V_31 = F_19 ( V_19 , V_180 , 0 , V_10 ) ;
if ( ! V_31 )
goto V_68;
V_31 -> V_15 . V_179 = F_7 ( V_31 , V_10 , V_150 ) ;
if ( V_2 )
V_31 -> V_89 = V_2 -> V_89 ;
V_68:
return V_31 ;
}
static struct V_1 * F_52 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
T_2 V_181 )
{
struct V_1 * V_31 ;
V_31 = F_19 ( V_19 , V_182 , 0 ,
sizeof( T_3 ) + V_181 ) ;
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
T_2 V_181 = V_19 ? V_19 -> V_183 : 0 ;
if ( ! V_181 )
V_181 = V_184 ;
return F_52 ( V_19 , V_2 , V_181 ) ;
}
struct V_1 * F_54 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
T_1 V_9 , const void * V_150 ,
T_2 V_10 , T_2 V_185 )
{
struct V_1 * V_31 ;
V_31 = F_52 ( V_19 , V_2 , V_10 + V_185 ) ;
if ( ! V_31 )
goto V_68;
F_5 ( V_31 , V_9 , V_10 + V_185 ) ;
F_7 ( V_31 , V_10 , V_150 ) ;
if ( V_185 )
F_20 ( V_31 , V_185 , NULL ) ;
V_68:
return V_31 ;
}
struct V_1 * F_55 ( const struct V_18 * V_19 )
{
struct V_1 * V_31 ;
struct V_186 * V_187 ;
struct V_188 V_189 ;
T_10 * V_190 ;
V_187 = F_56 ( V_19 ) ;
if ( F_57 ( ! V_187 ) )
return NULL ;
V_31 = F_19 ( V_19 , V_66 , 0 ,
V_187 -> V_191 + sizeof( V_192 ) ) ;
if ( ! V_31 )
return NULL ;
V_189 . V_193 = F_6 ( V_187 -> V_193 ) ;
V_189 . V_194 = F_6 ( V_19 -> V_195 ) ;
V_31 -> V_15 . V_189 = F_7 ( V_31 , sizeof( V_192 ) ,
& V_189 ) ;
V_190 = F_45 ( V_31 -> V_6 , V_187 -> V_191 ) ;
memset ( V_190 , 0 , V_187 -> V_191 ) ;
V_31 -> V_148 -> V_14 =
F_6 ( F_18 ( V_31 -> V_148 -> V_14 ) + V_187 -> V_191 ) ;
V_31 -> V_164 = F_46 ( V_31 -> V_6 ) ;
return V_31 ;
}
struct V_1 * F_58 ( struct V_196 * V_6 ,
const struct V_18 * V_19 ,
struct V_197 * V_26 )
{
struct V_1 * V_31 ;
V_31 = F_59 ( V_198 , V_199 ) ;
if ( ! V_31 )
goto V_68;
if ( ! V_26 )
F_31 ( L_4 , V_132 , V_6 ) ;
F_60 ( & V_31 -> V_200 ) ;
V_31 -> V_6 = V_6 ;
V_31 -> V_19 = (struct V_18 * ) V_19 ;
V_31 -> V_201 = 0 ;
V_31 -> V_202 = 0 ;
V_31 -> V_203 = 0 ;
V_31 -> V_176 = 0 ;
V_31 -> V_204 = 1 ;
V_31 -> V_205 = 0 ;
V_31 -> V_206 = 0 ;
V_31 -> V_207 = 0 ;
V_31 -> V_208 = 0 ;
V_31 -> V_209 = 0 ;
V_31 -> V_210 = V_211 ;
V_31 -> V_154 = NULL ;
F_60 ( & V_31 -> V_212 ) ;
F_60 ( & V_31 -> V_213 ) ;
F_61 ( V_2 ) ;
F_62 ( & V_31 -> V_214 , 1 ) ;
V_68:
return V_31 ;
}
void F_63 ( struct V_1 * V_2 , union V_215 * V_216 ,
union V_215 * V_217 )
{
memcpy ( & V_2 -> V_218 , V_216 , sizeof( union V_215 ) ) ;
memcpy ( & V_2 -> V_217 , V_217 , sizeof( union V_215 ) ) ;
}
const union V_215 * F_64 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_89 ) {
return & V_2 -> V_89 -> V_175 ;
} else {
return & V_2 -> V_218 ;
}
}
static struct V_1 * F_19 ( const struct V_18 * V_19 ,
T_10 type , T_10 V_103 , int V_10 )
{
struct V_1 * V_31 ;
T_19 * V_148 ;
struct V_196 * V_6 ;
struct V_197 * V_26 ;
V_6 = F_65 ( F_16 ( sizeof( T_19 ) + V_10 ) ,
V_199 ) ;
if ( ! V_6 )
goto V_68;
V_148 = ( T_19 * ) F_45 ( V_6 , sizeof( T_19 ) ) ;
V_148 -> type = type ;
V_148 -> V_103 = V_103 ;
V_148 -> V_14 = F_6 ( sizeof( T_19 ) ) ;
V_26 = V_19 ? V_19 -> V_25 . V_26 : NULL ;
V_31 = F_58 ( V_6 , V_19 , V_26 ) ;
if ( ! V_31 ) {
F_66 ( V_6 ) ;
goto V_68;
}
V_31 -> V_148 = V_148 ;
V_31 -> V_164 = ( ( T_10 * ) V_148 ) + sizeof( struct V_219 ) ;
if ( F_67 ( type , V_19 ) )
V_31 -> V_220 = 1 ;
V_6 -> V_26 = V_26 ;
return V_31 ;
V_68:
return NULL ;
}
static void F_68 ( struct V_1 * V_2 )
{
F_69 ( ! F_70 ( & V_2 -> V_200 ) ) ;
F_71 ( & V_2 -> V_212 ) ;
F_72 ( V_2 -> V_6 ) ;
F_73 ( V_2 ) ;
F_74 ( V_198 , V_2 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_154 )
F_75 ( V_2 -> V_154 ) ;
F_76 ( V_2 ) ;
}
void F_77 ( struct V_1 * V_221 )
{
F_78 ( & V_221 -> V_214 ) ;
}
void F_76 ( struct V_1 * V_221 )
{
if ( F_79 ( & V_221 -> V_214 ) )
F_68 ( V_221 ) ;
}
void * F_7 ( struct V_1 * V_2 , int V_12 , const void * V_161 )
{
void * V_162 ;
void * V_222 ;
int V_163 = F_18 ( V_2 -> V_148 -> V_14 ) ;
int V_223 = F_16 ( V_163 ) - V_163 ;
V_222 = F_45 ( V_2 -> V_6 , V_223 ) ;
V_162 = F_45 ( V_2 -> V_6 , V_12 ) ;
memset ( V_222 , 0 , V_223 ) ;
memcpy ( V_162 , V_161 , V_12 ) ;
V_2 -> V_148 -> V_14 = F_6 ( V_163 + V_223 + V_12 ) ;
V_2 -> V_164 = F_46 ( V_2 -> V_6 ) ;
return V_162 ;
}
void * F_10 ( struct V_1 * V_2 ,
int V_12 , const void * V_161 )
{
if ( F_9 ( V_2 -> V_6 ) >= V_12 )
return F_7 ( V_2 , V_12 , V_161 ) ;
else
return NULL ;
}
int F_80 ( struct V_1 * V_2 , int V_224 , int V_12 ,
struct V_225 * V_161 )
{
T_10 * V_162 ;
int V_11 = 0 ;
V_162 = F_45 ( V_2 -> V_6 , V_12 ) ;
if ( ( V_11 = F_81 ( V_162 , V_161 , V_224 , V_12 ) ) )
goto V_226;
V_2 -> V_148 -> V_14 =
F_6 ( F_18 ( V_2 -> V_148 -> V_14 ) + V_12 ) ;
V_2 -> V_164 = F_46 ( V_2 -> V_6 ) ;
V_226:
return V_11 ;
}
void F_82 ( struct V_1 * V_2 )
{
struct V_227 * V_154 ;
struct V_1 * V_228 ;
struct V_229 * V_109 ;
T_4 V_104 ;
T_4 V_230 ;
if ( V_2 -> V_202 )
return;
V_230 = F_18 ( V_2 -> V_15 . V_117 -> V_109 ) ;
V_109 = & V_2 -> V_19 -> V_231 -> V_226 ;
V_154 = V_2 -> V_154 ;
F_35 (lchunk, &msg->chunks, frag_list) {
if ( V_228 -> V_148 -> V_103 & V_115 ) {
V_104 = 0 ;
} else {
if ( V_228 -> V_148 -> V_103 & V_232 )
V_104 = F_83 ( V_109 , V_230 ) ;
else
V_104 = F_84 ( V_109 , V_230 ) ;
}
V_228 -> V_15 . V_117 -> V_104 = F_6 ( V_104 ) ;
V_228 -> V_202 = 1 ;
}
}
void F_85 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_201 ) {
V_2 -> V_15 . V_117 -> V_108 =
F_14 ( F_86 ( V_2 -> V_19 ) ) ;
V_2 -> V_201 = 1 ;
}
}
struct V_18 * F_87 ( const struct V_233 * V_80 ,
struct V_1 * V_2 ,
T_5 V_22 )
{
struct V_18 * V_19 ;
struct V_196 * V_6 ;
T_20 V_234 ;
struct V_3 * V_4 ;
V_234 = F_88 ( F_64 ( V_2 ) ) ;
V_19 = F_89 ( V_80 , V_80 -> V_25 . V_26 , V_234 , V_22 ) ;
if ( ! V_19 )
goto V_68;
V_19 -> V_235 = 1 ;
V_6 = V_2 -> V_6 ;
V_4 = F_2 ( F_3 ( F_4 ( V_6 ) -> V_7 ) ) ;
if ( F_57 ( ! V_4 ) )
goto V_236;
V_4 -> V_237 ( & V_19 -> V_45 . V_238 , V_6 , 1 ) ;
V_68:
return V_19 ;
V_236:
F_90 ( V_19 ) ;
return NULL ;
}
static T_12 * F_23 ( const struct V_233 * V_80 ,
const struct V_18 * V_19 ,
const struct V_1 * V_239 ,
int * V_78 ,
const T_10 * V_240 , int V_33 )
{
T_12 * V_31 ;
struct V_241 * V_77 ;
struct V_242 V_243 ;
int V_244 , V_245 ;
V_244 = sizeof( T_11 ) +
( sizeof( struct V_241 ) -
sizeof( struct V_246 ) ) ;
V_245 = sizeof( struct V_246 )
+ F_18 ( V_239 -> V_148 -> V_14 ) + V_33 ;
if ( V_245 % V_247 )
V_245 += V_247
- ( V_245 % V_247 ) ;
* V_78 = V_244 + V_245 ;
V_31 = F_91 ( * V_78 , V_199 ) ;
if ( ! V_31 )
goto V_68;
V_77 = (struct V_241 * ) V_31 -> V_248 ;
V_31 -> V_249 . type = V_250 ;
V_31 -> V_249 . V_14 = F_6 ( * V_78 ) ;
V_77 -> V_45 = V_19 -> V_45 ;
V_77 -> V_45 . V_251 = V_33 ;
V_77 -> V_45 . V_84 = V_19 -> V_82 . V_84 ;
V_77 -> V_45 . V_63 = V_19 -> V_82 . V_63 ;
V_77 -> V_45 . V_252 = F_92 ( V_19 -> V_253 ,
F_93 () ) ;
memcpy ( & V_77 -> V_45 . V_254 [ 0 ] , V_239 -> V_148 ,
F_18 ( V_239 -> V_148 -> V_14 ) ) ;
memcpy ( ( T_10 * ) & V_77 -> V_45 . V_254 [ 0 ] +
F_18 ( V_239 -> V_148 -> V_14 ) , V_240 , V_33 ) ;
if ( F_15 ( V_80 -> V_25 . V_26 ) -> V_190 ) {
struct V_255 V_256 ;
F_94 ( & V_243 , & V_77 -> V_45 , V_245 ) ;
V_256 . V_257 = F_15 ( V_80 -> V_25 . V_26 ) -> V_190 ;
V_256 . V_103 = 0 ;
if ( F_95 ( V_256 . V_257 , V_80 -> V_258 ,
sizeof( V_80 -> V_258 ) ) ||
F_96 ( & V_256 , & V_243 , V_245 , V_77 -> V_259 ) )
goto V_260;
}
return V_31 ;
V_260:
F_21 ( V_31 ) ;
V_68:
* V_78 = 0 ;
return NULL ;
}
struct V_18 * F_97 (
const struct V_233 * V_80 ,
const struct V_18 * V_19 ,
struct V_1 * V_2 , T_5 V_22 ,
int * error , struct V_1 * * V_261 )
{
struct V_18 * V_31 = NULL ;
struct V_241 * V_77 ;
struct V_246 * V_262 ;
int V_244 , V_245 , V_263 ;
T_10 * V_264 = V_80 -> V_264 ;
struct V_242 V_243 ;
unsigned int V_12 ;
T_20 V_234 ;
struct V_196 * V_6 = V_2 -> V_6 ;
T_21 V_265 ;
struct V_255 V_256 ;
V_244 = sizeof( T_19 ) +
( sizeof( struct V_241 ) -
sizeof( struct V_246 ) ) ;
V_245 = F_18 ( V_2 -> V_148 -> V_14 ) - V_244 ;
V_263 = V_244 + sizeof( struct V_246 ) ;
V_12 = F_18 ( V_2 -> V_148 -> V_14 ) ;
if ( V_12 < V_263 + sizeof( struct V_219 ) )
goto V_266;
if ( V_245 % V_247 )
goto V_266;
V_77 = V_2 -> V_15 . V_91 ;
V_262 = & V_77 -> V_45 ;
if ( ! F_15 ( V_80 -> V_25 . V_26 ) -> V_190 )
goto V_267;
F_94 ( & V_243 , V_262 , V_245 ) ;
V_256 . V_257 = F_15 ( V_80 -> V_25 . V_26 ) -> V_190 ;
V_256 . V_103 = 0 ;
memset ( V_264 , 0x00 , V_268 ) ;
if ( F_95 ( V_256 . V_257 , V_80 -> V_258 ,
sizeof( V_80 -> V_258 ) ) ||
F_96 ( & V_256 , & V_243 , V_245 , V_264 ) ) {
* error = - V_269 ;
goto V_236;
}
if ( memcmp ( V_264 , V_77 -> V_259 , V_268 ) ) {
* error = - V_270 ;
goto V_236;
}
V_267:
if ( F_98 ( V_2 -> V_271 -> V_272 ) != V_262 -> V_46 ) {
* error = - V_273 ;
goto V_236;
}
if ( V_2 -> V_271 -> V_218 != V_262 -> V_238 . V_274 . V_275 ||
F_18 ( V_2 -> V_271 -> V_217 ) != V_262 -> V_276 ) {
* error = - V_277 ;
goto V_236;
}
if ( F_99 ( V_80 -> V_25 . V_26 , V_278 ) )
V_265 = F_100 ( V_6 ) ;
else
V_265 = F_93 () ;
if ( ! V_19 && F_101 ( V_262 -> V_252 , V_265 ) < 0 ) {
V_12 = F_18 ( V_2 -> V_148 -> V_14 ) ;
* V_261 = F_52 ( V_19 , V_2 , V_12 ) ;
if ( * V_261 ) {
T_22 V_279 = F_102 ( F_103 ( V_265 , V_262 -> V_252 ) ) ;
T_17 V_280 = F_14 ( V_279 ) ;
F_5 ( * V_261 , V_281 ,
sizeof( V_280 ) ) ;
F_7 ( * V_261 , sizeof( V_280 ) , & V_280 ) ;
* error = - V_282 ;
} else
* error = - V_269 ;
goto V_236;
}
V_234 = F_88 ( F_64 ( V_2 ) ) ;
V_31 = F_89 ( V_80 , V_80 -> V_25 . V_26 , V_234 , V_22 ) ;
if ( ! V_31 ) {
* error = - V_269 ;
goto V_236;
}
V_31 -> V_82 . V_283 = F_18 ( V_2 -> V_271 -> V_218 ) ;
memcpy ( & V_31 -> V_45 , V_262 , sizeof( * V_262 ) ) ;
if ( F_104 ( V_31 , V_262 ,
V_199 ) < 0 ) {
* error = - V_269 ;
goto V_236;
}
if ( F_70 ( & V_31 -> V_25 . V_79 . V_284 ) ) {
F_105 ( & V_31 -> V_25 . V_79 , & V_2 -> V_217 ,
V_285 , V_199 ) ;
}
V_31 -> V_286 = V_31 -> V_45 . V_53 ;
V_31 -> V_287 = V_31 -> V_286 - 1 ;
V_31 -> V_288 = V_31 -> V_45 . V_53 ;
V_31 -> V_289 = V_31 -> V_287 ;
V_31 -> V_82 . V_84 = V_31 -> V_45 . V_84 ;
V_31 -> V_82 . V_63 = V_31 -> V_45 . V_63 ;
return V_31 ;
V_236:
if ( V_31 )
F_90 ( V_31 ) ;
return NULL ;
V_266:
* error = - V_290 ;
goto V_236;
}
static int F_106 ( const struct V_18 * V_19 ,
T_23 V_291 ,
struct V_1 * V_2 ,
struct V_1 * * V_261 )
{
struct V_292 V_293 ;
T_4 V_12 ;
V_12 = F_16 ( sizeof( V_293 ) ) ;
if ( ! * V_261 )
* V_261 = F_52 ( V_19 , V_2 , V_12 ) ;
if ( * V_261 ) {
V_293 . V_294 = F_14 ( 1 ) ;
V_293 . type = V_291 ;
F_5 ( * V_261 , V_295 ,
sizeof( V_293 ) ) ;
F_7 ( * V_261 , sizeof( V_293 ) , & V_293 ) ;
}
return 0 ;
}
static int F_107 ( const struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_1 * * V_261 )
{
if ( ! * V_261 )
* V_261 = F_52 ( V_19 , V_2 , 0 ) ;
if ( * V_261 )
F_5 ( * V_261 , V_296 , 0 ) ;
return 0 ;
}
static int F_108 ( const struct V_18 * V_19 ,
struct V_165 * V_169 ,
const struct V_1 * V_2 ,
struct V_1 * * V_261 )
{
if ( * V_261 )
F_44 ( * V_261 ) ;
* V_261 = F_48 ( V_19 , V_2 , V_169 ) ;
return 0 ;
}
static int F_109 ( const struct V_18 * V_19 ,
union V_28 V_169 ,
struct V_1 * V_2 ,
struct V_1 * * V_261 )
{
T_4 V_12 = F_18 ( V_169 . V_249 -> V_14 ) ;
if ( * V_261 )
F_44 ( * V_261 ) ;
* V_261 = F_52 ( V_19 , V_2 , V_12 ) ;
if ( * V_261 ) {
F_5 ( * V_261 , V_297 , V_12 ) ;
F_7 ( * V_261 , V_12 , V_169 . V_71 ) ;
}
return 0 ;
}
static int F_110 ( struct V_24 * V_24 , union V_28 V_169 )
{
T_4 V_40 = F_18 ( V_169 . V_249 -> V_14 ) - sizeof( T_11 ) ;
int V_298 = 0 ;
int V_299 = 0 ;
int V_300 ;
for ( V_300 = 0 ; V_300 < V_40 ; V_300 ++ ) {
switch ( V_169 . V_301 -> V_302 [ V_300 ] ) {
case V_66 :
V_298 = 1 ;
break;
case V_61 :
case V_62 :
V_299 = 1 ;
break;
}
}
if ( V_24 -> V_57 . V_303 )
return 1 ;
if ( V_24 -> V_57 . V_60 && ! V_298 && V_299 )
return 0 ;
return 1 ;
}
static void F_111 ( struct V_18 * V_19 ,
union V_28 V_169 )
{
struct V_24 * V_24 = F_12 ( V_19 -> V_25 . V_26 ) ;
T_4 V_40 = F_18 ( V_169 . V_249 -> V_14 ) - sizeof( T_11 ) ;
int V_300 ;
for ( V_300 = 0 ; V_300 < V_40 ; V_300 ++ ) {
switch ( V_169 . V_301 -> V_302 [ V_300 ] ) {
case V_304 :
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
static T_24 F_112 ( const struct V_18 * V_19 ,
union V_28 V_169 ,
struct V_1 * V_2 ,
struct V_1 * * V_261 )
{
int V_31 = V_305 ;
switch ( V_169 . V_249 -> type & V_306 ) {
case V_307 :
V_31 = V_308 ;
break;
case V_309 :
break;
case V_310 :
V_31 = V_308 ;
case V_311 :
if ( NULL == * V_261 )
* V_261 = F_53 ( V_19 , V_2 ) ;
if ( * V_261 ) {
if ( ! F_8 ( * V_261 , V_312 ,
F_16 ( F_18 ( V_169 . V_249 -> V_14 ) ) ) )
F_10 ( * V_261 ,
F_16 ( F_18 ( V_169 . V_249 -> V_14 ) ) ,
V_169 . V_71 ) ;
} else {
V_31 = V_269 ;
}
break;
default:
break;
}
return V_31 ;
}
static T_24 F_113 ( struct V_24 * V_24 ,
const struct V_18 * V_19 ,
union V_28 V_169 ,
T_25 V_313 ,
struct V_1 * V_2 ,
struct V_1 * * V_155 )
{
struct V_314 * V_315 ;
int V_31 = V_305 ;
T_4 V_316 , V_317 = 0 ;
int V_300 ;
switch ( V_169 . V_249 -> type ) {
case V_318 :
case V_319 :
case V_320 :
case V_72 :
case V_250 :
case V_173 :
case V_321 :
case V_322 :
case V_74 :
break;
case V_73 :
if ( ! F_110 ( V_24 , V_169 ) )
return V_323 ;
break;
case V_324 :
if ( V_24 -> V_57 . V_60 )
break;
goto V_325;
case V_326 :
F_109 ( V_19 , V_169 , V_2 , V_155 ) ;
V_31 = V_323 ;
break;
case V_327 :
if ( V_24 -> V_57 . V_58 )
break;
goto V_325;
case V_328 :
if ( ! V_24 -> V_57 . V_64 )
goto V_325;
if ( V_329 !=
F_18 ( V_169 . V_249 -> V_14 ) - sizeof( T_11 ) ) {
F_108 ( V_19 , V_169 . V_249 ,
V_2 , V_155 ) ;
V_31 = V_323 ;
}
break;
case V_330 :
if ( ! V_24 -> V_57 . V_64 )
goto V_325;
if ( 260 < F_18 ( V_169 . V_249 -> V_14 ) ) {
F_108 ( V_19 , V_169 . V_249 ,
V_2 , V_155 ) ;
V_31 = V_323 ;
}
break;
case V_331 :
if ( ! V_24 -> V_57 . V_64 )
goto V_325;
V_315 = (struct V_314 * ) V_169 . V_249 ;
V_316 = ( F_18 ( V_169 . V_249 -> V_14 ) - sizeof( T_11 ) ) >> 1 ;
for ( V_300 = 0 ; V_300 < V_316 ; V_300 ++ ) {
V_317 = F_18 ( V_315 -> V_332 [ V_300 ] ) ;
if ( V_317 == V_333 )
break;
}
if ( V_317 != V_333 ) {
F_108 ( V_19 , V_169 . V_249 , V_2 ,
V_155 ) ;
V_31 = V_323 ;
}
break;
V_325:
default:
F_31 ( L_5 ,
V_132 , F_18 ( V_169 . V_249 -> type ) , V_313 ) ;
V_31 = F_112 ( V_19 , V_169 , V_2 , V_155 ) ;
break;
}
return V_31 ;
}
int F_114 ( struct V_24 * V_24 , const struct V_18 * V_19 ,
T_25 V_313 ,
T_26 * V_254 ,
struct V_1 * V_2 ,
struct V_1 * * V_261 )
{
union V_28 V_169 ;
int V_334 = 0 ;
int V_335 ;
if ( ( 0 == V_254 -> V_69 . V_49 ) ||
( 0 == V_254 -> V_69 . V_51 ) ||
( 0 == V_254 -> V_69 . V_44 ) ||
( V_336 > F_98 ( V_254 -> V_69 . V_47 ) ) ) {
return F_107 ( V_19 , V_2 , V_261 ) ;
}
F_115 (param, peer_init, init_hdr.params) {
if ( V_250 == V_169 . V_249 -> type )
V_334 = 1 ;
}
if ( V_169 . V_71 != ( void * ) V_2 -> V_164 )
return F_108 ( V_19 , V_169 . V_249 , V_2 , V_261 ) ;
if ( ( V_87 == V_313 ) && ! V_334 )
return F_106 ( V_19 , V_250 ,
V_2 , V_261 ) ;
F_115 (param, peer_init, init_hdr.params) {
V_335 = F_113 ( V_24 , V_19 , V_169 , V_313 , V_2 , V_261 ) ;
switch ( V_335 ) {
case V_323 :
case V_269 :
return 0 ;
case V_308 :
return 1 ;
case V_305 :
default:
break;
}
}
return 1 ;
}
int F_116 ( struct V_18 * V_19 , struct V_1 * V_2 ,
const union V_215 * V_238 ,
T_26 * V_254 , T_5 V_22 )
{
struct V_24 * V_24 = F_12 ( V_19 -> V_25 . V_26 ) ;
union V_28 V_169 ;
struct V_130 * V_89 ;
struct V_337 * V_338 , * V_235 ;
struct V_3 * V_4 ;
union V_215 V_339 ;
char * V_77 ;
int V_340 = 0 ;
if( ! F_117 ( V_19 , V_238 , V_22 , V_341 ) )
goto V_342;
if ( F_118 ( F_64 ( V_2 ) , V_238 ) )
V_340 = 1 ;
F_115 (param, peer_init, init_hdr.params) {
if ( ! V_340 && ( V_169 . V_249 -> type == V_318 ||
V_169 . V_249 -> type == V_319 ) ) {
V_4 = F_2 ( F_119 ( V_169 . V_249 -> type ) ) ;
V_4 -> V_343 ( & V_339 , V_169 . V_339 ,
V_2 -> V_271 -> V_218 , 0 ) ;
if ( F_118 ( F_64 ( V_2 ) , & V_339 ) )
V_340 = 1 ;
}
if ( ! F_120 ( V_19 , V_169 , V_238 , V_22 ) )
goto V_344;
}
if ( ! V_340 )
goto V_344;
if ( V_19 -> V_82 . V_86 && ( ! V_19 -> V_82 . V_345 ||
! V_19 -> V_82 . V_346 ) )
V_19 -> V_82 . V_86 = 0 ;
if ( ! V_24 -> V_57 . V_303 &&
( V_19 -> V_82 . V_85 && ! V_19 -> V_82 . V_86 ) ) {
V_19 -> V_82 . V_347 |= ( V_348 |
V_349 |
V_324 ) ;
V_19 -> V_82 . V_85 = 0 ;
goto V_344;
}
F_121 (pos, temp, &asoc->peer.transport_addr_list) {
V_89 = F_122 ( V_338 , struct V_130 , V_350 ) ;
if ( V_89 -> V_351 == V_352 ) {
F_123 ( V_19 , V_89 ) ;
}
}
V_19 -> V_82 . V_300 . V_44 =
F_98 ( V_254 -> V_69 . V_44 ) ;
V_19 -> V_82 . V_300 . V_47 =
F_98 ( V_254 -> V_69 . V_47 ) ;
V_19 -> V_82 . V_300 . V_49 =
F_18 ( V_254 -> V_69 . V_49 ) ;
V_19 -> V_82 . V_300 . V_51 =
F_18 ( V_254 -> V_69 . V_51 ) ;
V_19 -> V_82 . V_300 . V_53 =
F_98 ( V_254 -> V_69 . V_53 ) ;
if ( V_19 -> V_45 . V_50 >
F_18 ( V_254 -> V_69 . V_51 ) ) {
V_19 -> V_45 . V_50 =
F_18 ( V_254 -> V_69 . V_51 ) ;
}
if ( V_19 -> V_45 . V_52 >
F_18 ( V_254 -> V_69 . V_49 ) ) {
V_19 -> V_45 . V_52 =
F_18 ( V_254 -> V_69 . V_49 ) ;
}
V_19 -> V_45 . V_353 = V_19 -> V_82 . V_300 . V_44 ;
V_19 -> V_82 . V_48 = V_19 -> V_82 . V_300 . V_47 ;
V_77 = V_19 -> V_82 . V_77 ;
if ( V_77 ) {
V_19 -> V_82 . V_77 = F_124 ( V_77 , V_19 -> V_82 . V_78 , V_22 ) ;
if ( ! V_19 -> V_82 . V_77 )
goto V_344;
}
F_35 (transport, &asoc->peer.transport_addr_list,
transports) {
V_89 -> V_354 = V_19 -> V_82 . V_300 . V_47 ;
}
if ( ! F_125 ( & V_19 -> V_82 . V_126 , V_355 ,
V_19 -> V_82 . V_300 . V_53 , V_22 ) )
goto V_344;
if ( ! V_19 -> V_235 ) {
int error ;
V_19 -> V_231 = F_126 ( V_19 -> V_45 . V_52 ,
V_19 -> V_45 . V_50 , V_22 ) ;
if ( ! V_19 -> V_231 )
goto V_344;
error = F_127 ( V_19 , V_22 ) ;
if ( error )
goto V_344;
}
V_19 -> V_82 . V_288 = V_19 -> V_82 . V_300 . V_53 - 1 ;
return 1 ;
V_344:
F_121 (pos, temp, &asoc->peer.transport_addr_list) {
V_89 = F_122 ( V_338 , struct V_130 , V_350 ) ;
if ( V_89 -> V_351 != V_341 )
F_123 ( V_19 , V_89 ) ;
}
V_342:
return 0 ;
}
static int F_120 ( struct V_18 * V_19 ,
union V_28 V_169 ,
const union V_215 * V_238 ,
T_5 V_22 )
{
struct V_24 * V_24 = F_12 ( V_19 -> V_25 . V_26 ) ;
union V_215 V_339 ;
int V_300 ;
T_4 V_36 ;
int V_31 = 1 ;
T_20 V_234 ;
T_27 V_356 ;
struct V_3 * V_4 ;
union V_357 * V_358 ;
struct V_130 * V_359 ;
switch ( V_169 . V_249 -> type ) {
case V_319 :
if ( V_360 != V_19 -> V_25 . V_26 -> V_361 )
break;
goto V_362;
case V_318 :
if ( F_128 ( V_19 -> V_25 . V_26 ) )
break;
V_362:
V_4 = F_2 ( F_119 ( V_169 . V_249 -> type ) ) ;
V_4 -> V_343 ( & V_339 , V_169 . V_339 , F_6 ( V_19 -> V_82 . V_283 ) , 0 ) ;
V_234 = F_88 ( V_238 ) ;
if ( F_129 ( V_24 , & V_339 , V_234 ) )
if ( ! F_117 ( V_19 , & V_339 , V_22 , V_363 ) )
return 0 ;
break;
case V_320 :
if ( ! V_24 -> V_57 . V_364 )
break;
V_356 = F_98 ( V_169 . V_365 -> V_366 ) ;
V_19 -> V_253 = F_130 ( V_19 -> V_253 , V_356 ) ;
break;
case V_326 :
F_31 ( L_6 , V_132 ) ;
break;
case V_72 :
V_19 -> V_82 . V_367 = 0 ;
V_19 -> V_82 . V_368 = 0 ;
if ( V_238 -> V_369 . V_370 == V_371 )
V_19 -> V_82 . V_368 = 1 ;
else if ( V_238 -> V_369 . V_370 == V_372 )
V_19 -> V_82 . V_367 = 1 ;
V_36 = F_18 ( V_169 . V_249 -> V_14 ) - sizeof( T_11 ) ;
if ( V_36 )
V_36 /= sizeof( T_4 ) ;
for ( V_300 = 0 ; V_300 < V_36 ; ++ V_300 ) {
switch ( V_169 . V_36 -> V_37 [ V_300 ] ) {
case V_318 :
V_19 -> V_82 . V_367 = 1 ;
break;
case V_319 :
if ( V_360 == V_19 -> V_25 . V_26 -> V_361 )
V_19 -> V_82 . V_368 = 1 ;
break;
case V_326 :
V_19 -> V_82 . V_373 = 1 ;
break;
default:
break;
}
}
break;
case V_250 :
V_19 -> V_82 . V_78 =
F_18 ( V_169 . V_249 -> V_14 ) - sizeof( T_11 ) ;
V_19 -> V_82 . V_77 = V_169 . V_77 -> V_248 ;
break;
case V_173 :
break;
case V_321 :
break;
case V_322 :
V_19 -> V_82 . V_83 = 1 ;
break;
case V_74 :
V_19 -> V_82 . V_63 = F_98 ( V_169 . V_374 -> V_63 ) ;
break;
case V_324 :
if ( ! V_24 -> V_57 . V_60 )
goto V_375;
V_358 = V_169 . V_71 + sizeof( V_376 ) ;
V_4 = F_2 ( F_119 ( V_169 . V_249 -> type ) ) ;
V_4 -> V_343 ( & V_339 , V_358 ,
F_6 ( V_19 -> V_82 . V_283 ) , 0 ) ;
if ( ! V_4 -> V_377 ( & V_339 , NULL , NULL ) )
break;
V_359 = F_131 ( V_19 , & V_339 ) ;
if ( ! V_359 )
break;
F_132 ( V_19 , V_359 ) ;
break;
case V_73 :
F_111 ( V_19 , V_169 ) ;
break;
case V_327 :
if ( V_24 -> V_57 . V_58 ) {
V_19 -> V_82 . V_84 = 1 ;
break;
}
goto V_375;
case V_328 :
if ( ! V_24 -> V_57 . V_64 )
goto V_375;
V_19 -> V_82 . V_345 = F_124 ( V_169 . V_249 ,
F_18 ( V_169 . V_249 -> V_14 ) , V_22 ) ;
if ( ! V_19 -> V_82 . V_345 ) {
V_31 = 0 ;
break;
}
break;
case V_331 :
if ( ! V_24 -> V_57 . V_64 )
goto V_375;
V_19 -> V_82 . V_346 = F_124 ( V_169 . V_249 ,
F_18 ( V_169 . V_249 -> V_14 ) , V_22 ) ;
if ( ! V_19 -> V_82 . V_346 ) {
V_31 = 0 ;
break;
}
F_133 ( V_19 , V_169 . V_378 ) ;
break;
case V_330 :
if ( ! V_24 -> V_57 . V_64 )
goto V_375;
V_19 -> V_82 . V_379 = F_124 ( V_169 . V_249 ,
F_18 ( V_169 . V_249 -> V_14 ) , V_22 ) ;
if ( ! V_19 -> V_82 . V_379 )
V_31 = 0 ;
break;
V_375:
default:
F_31 ( L_7 ,
V_132 , F_18 ( V_169 . V_249 -> type ) , V_19 ) ;
break;
}
return V_31 ;
}
T_13 F_134 ( const struct V_233 * V_80 )
{
T_13 V_380 ;
do {
F_135 ( & V_380 , sizeof( T_13 ) ) ;
} while ( V_380 == 0 );
return V_380 ;
}
T_13 F_136 ( const struct V_233 * V_80 )
{
T_13 V_31 ;
F_135 ( & V_31 , sizeof( T_13 ) ) ;
return V_31 ;
}
static struct V_1 * F_137 ( struct V_18 * V_19 ,
union V_215 * V_339 ,
int V_23 )
{
T_28 V_381 ;
struct V_1 * V_31 ;
int V_14 = sizeof( V_381 ) + V_23 ;
union V_357 V_382 ;
int V_383 ;
struct V_3 * V_4 = F_2 ( V_339 -> V_274 . V_384 ) ;
V_383 = V_4 -> V_385 ( V_339 , & V_382 ) ;
if ( ! V_383 )
return NULL ;
V_14 += V_383 ;
V_31 = F_19 ( V_19 , V_61 , 0 , V_14 ) ;
if ( ! V_31 )
return NULL ;
V_381 . V_386 = F_14 ( V_19 -> V_288 ++ ) ;
V_31 -> V_15 . V_387 =
F_7 ( V_31 , sizeof( V_381 ) , & V_381 ) ;
V_31 -> V_70 . V_71 =
F_7 ( V_31 , V_383 , & V_382 ) ;
return V_31 ;
}
struct V_1 * F_138 ( struct V_18 * V_19 ,
union V_215 * V_388 ,
struct V_389 * V_29 ,
int V_390 ,
T_1 V_103 )
{
V_376 V_169 ;
struct V_1 * V_31 ;
union V_357 V_358 ;
union V_215 * V_339 ;
void * V_391 ;
struct V_3 * V_4 ;
int V_392 = sizeof( V_169 ) ;
int V_393 = 0 ;
int V_394 = 0 ;
int V_300 ;
int V_395 = 0 ;
V_391 = V_29 ;
for ( V_300 = 0 ; V_300 < V_390 ; V_300 ++ ) {
V_339 = V_391 ;
V_4 = F_2 ( V_339 -> V_274 . V_384 ) ;
V_393 = V_4 -> V_385 ( V_339 , & V_358 ) ;
V_394 += V_392 ;
V_394 += V_393 ;
V_391 += V_4 -> V_396 ;
if ( V_19 -> V_397 && ! V_395 ) {
V_394 += V_392 ;
V_394 += V_393 ;
V_395 = 1 ;
F_31 ( L_8
L_9 ,
V_132 , V_394 ) ;
}
}
V_31 = F_137 ( V_19 , V_388 , V_394 ) ;
if ( ! V_31 )
return NULL ;
V_391 = V_29 ;
for ( V_300 = 0 ; V_300 < V_390 ; V_300 ++ ) {
V_339 = V_391 ;
V_4 = F_2 ( V_339 -> V_274 . V_384 ) ;
V_393 = V_4 -> V_385 ( V_339 , & V_358 ) ;
V_169 . V_70 . type = V_103 ;
V_169 . V_70 . V_14 = F_6 ( V_392 + V_393 ) ;
V_169 . V_398 = V_300 ;
F_7 ( V_31 , V_392 , & V_169 ) ;
F_7 ( V_31 , V_393 , & V_358 ) ;
V_391 += V_4 -> V_396 ;
}
if ( V_103 == V_348 && V_395 ) {
V_339 = V_19 -> V_397 ;
V_4 = F_2 ( V_339 -> V_274 . V_384 ) ;
V_393 = V_4 -> V_385 ( V_339 , & V_358 ) ;
V_169 . V_70 . type = V_349 ;
V_169 . V_70 . V_14 = F_6 ( V_392 + V_393 ) ;
V_169 . V_398 = V_300 ;
F_7 ( V_31 , V_392 , & V_169 ) ;
F_7 ( V_31 , V_393 , & V_358 ) ;
}
return V_31 ;
}
struct V_1 * F_139 ( struct V_18 * V_19 ,
union V_215 * V_339 )
{
V_376 V_169 ;
struct V_1 * V_31 ;
int V_12 = sizeof( V_169 ) ;
union V_357 V_382 ;
int V_383 ;
struct V_3 * V_4 = F_2 ( V_339 -> V_274 . V_384 ) ;
V_383 = V_4 -> V_385 ( V_339 , & V_382 ) ;
if ( ! V_383 )
return NULL ;
V_12 += V_383 ;
V_31 = F_137 ( V_19 , V_339 , V_12 ) ;
if ( ! V_31 )
return NULL ;
V_169 . V_70 . type = V_324 ;
V_169 . V_70 . V_14 = F_6 ( V_12 ) ;
V_169 . V_398 = 0 ;
F_7 ( V_31 , sizeof( V_169 ) , & V_169 ) ;
F_7 ( V_31 , V_383 , & V_382 ) ;
return V_31 ;
}
static struct V_1 * F_140 ( const struct V_18 * V_19 ,
T_13 V_386 , int V_23 )
{
T_28 V_381 ;
struct V_1 * V_31 ;
int V_14 = sizeof( V_381 ) + V_23 ;
V_31 = F_19 ( V_19 , V_62 , 0 , V_14 ) ;
if ( ! V_31 )
return NULL ;
V_381 . V_386 = F_14 ( V_386 ) ;
V_31 -> V_15 . V_387 =
F_7 ( V_31 , sizeof( V_381 ) , & V_381 ) ;
return V_31 ;
}
static void F_141 ( struct V_1 * V_2 , T_17 V_398 ,
T_1 V_399 , V_376 * V_400 )
{
V_376 V_401 ;
T_3 V_402 ;
int V_403 = 0 ;
int V_404 = 0 ;
T_1 V_405 ;
if ( V_406 == V_399 ) {
V_405 = V_407 ;
} else {
V_405 = V_408 ;
V_404 = sizeof( V_402 ) ;
if ( V_400 )
V_403 =
F_18 ( V_400 -> V_70 . V_14 ) ;
}
V_401 . V_70 . type = V_405 ;
V_401 . V_70 . V_14 = F_6 ( sizeof( V_401 ) +
V_404 +
V_403 ) ;
V_401 . V_398 = V_398 ;
F_7 ( V_2 , sizeof( V_401 ) , & V_401 ) ;
if ( V_406 == V_399 )
return;
V_402 . V_13 = V_399 ;
V_402 . V_14 = F_6 ( V_404 + V_403 ) ;
F_7 ( V_2 , V_404 , & V_402 ) ;
if ( V_400 )
F_7 ( V_2 , V_403 , V_400 ) ;
}
static T_1 F_142 ( struct V_18 * V_19 ,
struct V_1 * V_381 ,
V_376 * V_400 )
{
struct V_130 * V_82 ;
struct V_3 * V_4 ;
union V_215 V_339 ;
union V_357 * V_358 ;
V_358 = ( void * ) V_400 + sizeof( V_376 ) ;
if ( V_400 -> V_70 . type != V_348 &&
V_400 -> V_70 . type != V_349 &&
V_400 -> V_70 . type != V_324 )
return V_312 ;
switch ( V_358 -> V_249 . type ) {
case V_319 :
if ( ! V_19 -> V_82 . V_368 )
return V_297 ;
break;
case V_318 :
if ( ! V_19 -> V_82 . V_367 )
return V_297 ;
break;
default:
return V_297 ;
}
V_4 = F_2 ( F_119 ( V_358 -> V_249 . type ) ) ;
if ( F_57 ( ! V_4 ) )
return V_297 ;
V_4 -> V_343 ( & V_339 , V_358 , F_6 ( V_19 -> V_82 . V_283 ) , 0 ) ;
if ( ! V_4 -> V_409 ( & V_339 ) && ! V_4 -> V_377 ( & V_339 , NULL , V_381 -> V_6 ) )
return V_297 ;
switch ( V_400 -> V_70 . type ) {
case V_348 :
if ( V_4 -> V_409 ( & V_339 ) )
memcpy ( & V_339 , & V_381 -> V_218 , sizeof( V_339 ) ) ;
V_82 = F_117 ( V_19 , & V_339 , V_199 , V_363 ) ;
if ( ! V_82 )
return V_410 ;
if ( ! F_143 ( & V_82 -> V_411 , F_144 ( V_82 ) ) )
F_145 ( V_82 ) ;
V_19 -> V_412 = V_82 ;
break;
case V_349 :
if ( V_19 -> V_82 . V_413 == 1 )
return V_414 ;
if ( F_118 ( & V_381 -> V_218 , & V_339 ) )
return V_415 ;
if ( V_4 -> V_409 ( & V_339 ) ) {
F_132 ( V_19 , V_381 -> V_89 ) ;
F_146 ( V_19 ,
V_381 -> V_89 ) ;
} else
F_147 ( V_19 , & V_339 ) ;
break;
case V_324 :
if ( V_4 -> V_409 ( & V_339 ) )
memcpy ( & V_339 . V_274 , F_64 ( V_381 ) , sizeof( V_339 ) ) ;
V_82 = F_131 ( V_19 , & V_339 ) ;
if ( ! V_82 )
return V_297 ;
F_132 ( V_19 , V_82 ) ;
break;
}
return V_406 ;
}
int F_148 ( const struct V_18 * V_19 ,
struct V_165 * V_70 , void * V_164 ,
struct V_165 * * V_261 ) {
V_376 * V_400 ;
union V_28 V_169 ;
int V_14 , V_416 ;
V_169 . V_71 = ( T_11 * ) V_70 ;
while ( V_169 . V_71 <= V_164 - sizeof( T_11 ) ) {
V_14 = F_18 ( V_169 . V_249 -> V_14 ) ;
* V_261 = V_169 . V_249 ;
if ( V_169 . V_71 > V_164 - V_14 ||
V_14 < sizeof( T_11 ) )
return 0 ;
switch ( V_169 . V_249 -> type ) {
case V_348 :
case V_349 :
case V_324 :
V_400 = ( V_376 * ) V_169 . V_71 ;
V_416 = F_18 ( V_400 -> V_70 . V_14 ) ;
if ( V_416 < sizeof( V_376 ) +
sizeof( T_11 ) )
return 0 ;
break;
case V_407 :
case V_74 :
if ( V_14 != sizeof( V_376 ) )
return 0 ;
break;
default:
break;
}
V_169 . V_71 += F_16 ( V_14 ) ;
}
if ( V_169 . V_71 != V_164 )
return 0 ;
return 1 ;
}
struct V_1 * F_149 ( struct V_18 * V_19 ,
struct V_1 * V_381 )
{
T_28 * V_417 ;
union V_357 * V_358 ;
V_376 * V_400 ;
struct V_1 * V_418 ;
T_1 V_399 ;
int V_14 = 0 ;
int V_107 ;
T_13 V_386 ;
int V_419 = 1 ;
V_107 = F_18 ( V_381 -> V_148 -> V_14 ) - sizeof( T_19 ) ;
V_417 = ( T_28 * ) V_381 -> V_6 -> V_161 ;
V_386 = F_98 ( V_417 -> V_386 ) ;
V_14 = sizeof( T_28 ) ;
V_358 = (union V_357 * ) ( V_381 -> V_6 -> V_161 + V_14 ) ;
V_107 -= V_14 ;
V_14 = F_18 ( V_358 -> V_249 . V_14 ) ;
V_400 = ( void * ) V_358 + V_14 ;
V_107 -= V_14 ;
V_418 = F_140 ( V_19 , V_386 , V_107 * 4 ) ;
if ( ! V_418 )
goto V_420;
while ( V_107 > 0 ) {
V_399 = F_142 ( V_19 , V_381 ,
V_400 ) ;
if ( V_406 != V_399 )
V_419 = 0 ;
if ( ! V_419 )
F_141 ( V_418 ,
V_400 -> V_398 , V_399 ,
V_400 ) ;
if ( V_410 == V_399 )
goto V_420;
V_14 = F_18 ( V_400 -> V_70 . V_14 ) ;
V_400 = ( void * ) V_400 + V_14 ;
V_107 -= V_14 ;
}
V_420:
V_19 -> V_82 . V_288 ++ ;
if ( V_418 ) {
F_77 ( V_418 ) ;
F_150 ( & V_418 -> V_212 ,
& V_19 -> V_421 ) ;
}
return V_418 ;
}
static void F_151 ( struct V_18 * V_19 ,
V_376 * V_400 )
{
struct V_3 * V_4 ;
union V_215 V_339 ;
struct V_20 * V_21 = & V_19 -> V_25 . V_79 ;
union V_357 * V_358 ;
struct V_130 * V_89 ;
struct V_422 * V_423 ;
V_358 = ( void * ) V_400 + sizeof( V_376 ) ;
V_4 = F_2 ( F_119 ( V_358 -> V_249 . type ) ) ;
V_4 -> V_343 ( & V_339 , V_358 , F_6 ( V_21 -> V_283 ) , 0 ) ;
switch ( V_400 -> V_70 . type ) {
case V_348 :
F_152 () ;
F_35 (saddr, &bp->address_list, list) {
if ( F_118 ( & V_423 -> V_424 , & V_339 ) )
V_423 -> V_351 = V_285 ;
}
F_153 () ;
F_35 (transport, &asoc->peer.transport_addr_list,
transports) {
F_154 ( V_89 -> V_425 ) ;
V_89 -> V_425 = NULL ;
}
break;
case V_349 :
F_152 () ;
F_155 ( V_21 , & V_339 ) ;
if ( V_19 -> V_397 != NULL &&
F_118 ( V_19 -> V_397 , & V_339 ) ) {
F_21 ( V_19 -> V_397 ) ;
V_19 -> V_397 = NULL ;
}
F_153 () ;
F_35 (transport, &asoc->peer.transport_addr_list,
transports) {
F_154 ( V_89 -> V_425 ) ;
V_89 -> V_425 = NULL ;
}
break;
default:
break;
}
}
static T_1 F_156 ( struct V_1 * V_418 ,
V_376 * V_400 ,
int V_426 )
{
V_376 * V_427 ;
T_3 * V_402 ;
int V_14 ;
int V_428 ;
T_1 V_399 ;
if ( V_426 )
V_399 = V_406 ;
else
V_399 = V_429 ;
V_428 = F_18 ( V_418 -> V_148 -> V_14 ) -
sizeof( T_19 ) ;
V_14 = sizeof( T_28 ) ;
V_427 = ( V_376 * ) ( V_418 -> V_6 -> V_161 +
V_14 ) ;
V_428 -= V_14 ;
while ( V_428 > 0 ) {
if ( V_427 -> V_398 == V_400 -> V_398 ) {
switch( V_427 -> V_70 . type ) {
case V_407 :
return V_406 ;
case V_408 :
V_14 = sizeof( V_376 ) ;
V_402 = ( void * ) V_427 + V_14 ;
V_428 -= V_14 ;
if ( V_428 > 0 )
return V_402 -> V_13 ;
else
return V_296 ;
break;
default:
return V_296 ;
}
}
V_14 = F_18 ( V_427 -> V_70 . V_14 ) ;
V_427 = ( void * ) V_427 + V_14 ;
V_428 -= V_14 ;
}
return V_399 ;
}
int F_157 ( struct V_18 * V_19 ,
struct V_1 * V_418 )
{
struct V_1 * V_381 = V_19 -> V_430 ;
union V_357 * V_358 ;
V_376 * V_400 ;
int V_14 = 0 ;
int V_431 = V_381 -> V_6 -> V_12 ;
int V_419 = 0 ;
int V_426 = 1 ;
int V_31 = 0 ;
T_1 V_399 = V_406 ;
V_14 = sizeof( V_432 ) ;
V_358 = (union V_357 * ) ( V_381 -> V_6 -> V_161 + V_14 ) ;
V_431 -= V_14 ;
V_14 = F_18 ( V_358 -> V_249 . V_14 ) ;
V_400 = ( void * ) V_358 + V_14 ;
V_431 -= V_14 ;
if ( V_418 -> V_6 -> V_12 == sizeof( T_28 ) )
V_419 = 1 ;
while ( V_431 > 0 ) {
if ( V_419 )
V_399 = V_406 ;
else {
V_399 = F_156 ( V_418 ,
V_400 ,
V_426 ) ;
if ( V_426 && ( V_406 != V_399 ) )
V_426 = 0 ;
}
switch ( V_399 ) {
case V_406 :
F_151 ( V_19 , V_400 ) ;
break;
case V_410 :
V_31 = 1 ;
break;
case V_312 :
V_19 -> V_82 . V_347 |=
V_400 -> V_70 . type ;
break;
case V_429 :
case V_414 :
case V_415 :
default:
break;
}
V_14 = F_18 ( V_400 -> V_70 . V_14 ) ;
V_400 = ( void * ) V_400 + V_14 ;
V_431 -= V_14 ;
}
if ( V_426 && V_19 -> V_433 ) {
V_19 -> V_433 = 0 ;
F_158 ( V_19 -> V_82 . V_434 ) ;
}
F_71 ( & V_381 -> V_212 ) ;
F_44 ( V_381 ) ;
V_19 -> V_430 = NULL ;
return V_31 ;
}
struct V_1 * F_159 ( const struct V_18 * V_19 ,
T_13 V_435 , T_2 V_436 ,
struct V_437 * V_438 )
{
struct V_1 * V_31 = NULL ;
struct V_439 V_440 ;
struct V_437 V_441 ;
T_2 V_147 ;
int V_300 ;
V_147 = ( V_436 + 1 ) * sizeof( T_13 ) ;
V_31 = F_19 ( V_19 , V_304 , 0 , V_147 ) ;
if ( ! V_31 )
return NULL ;
V_440 . V_435 = F_14 ( V_435 ) ;
V_31 -> V_15 . V_442 =
F_7 ( V_31 , sizeof( V_440 ) , & V_440 ) ;
for ( V_300 = 0 ; V_300 < V_436 ; V_300 ++ ) {
V_441 . V_109 = V_438 [ V_300 ] . V_109 ;
V_441 . V_104 = V_438 [ V_300 ] . V_104 ;
F_7 ( V_31 , sizeof( V_441 ) , & V_441 ) ;
}
return V_31 ;
}

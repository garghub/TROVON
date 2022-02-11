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
if ( V_36 -> V_64 )
V_31 += sizeof( V_39 ) ;
V_31 += V_24 ;
if ( V_27 -> V_65 ) {
V_31 += sizeof( V_6 -> V_46 . V_66 ) ;
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
V_42 [ V_41 ] = V_67 ;
V_41 += 1 ;
}
if ( V_41 )
V_31 += F_16 ( sizeof( T_9 ) +
V_41 ) ;
V_32 = F_19 ( V_6 , V_68 , 0 , V_31 , V_23 ) ;
if ( ! V_32 )
goto V_69;
V_32 -> V_18 . V_70 =
F_7 ( V_32 , sizeof( V_28 ) , & V_28 ) ;
V_32 -> V_71 . V_72 =
F_7 ( V_32 , V_34 , V_30 . V_72 ) ;
V_37 . V_71 . type = V_73 ;
V_37 . V_71 . V_17 = F_6 ( F_17 ( V_33 ) ) ;
F_7 ( V_32 , sizeof( V_37 ) , & V_37 ) ;
F_7 ( V_32 , V_33 * sizeof( T_4 ) , & V_38 ) ;
F_7 ( V_32 , sizeof( V_57 ) , & V_57 ) ;
if ( V_41 ) {
V_40 . V_71 . type = V_74 ;
V_40 . V_71 . V_17 =
F_6 ( sizeof( T_9 ) + V_41 ) ;
F_7 ( V_32 , sizeof( T_9 ) ,
& V_40 ) ;
F_20 ( V_32 , V_41 , V_42 ) ;
}
if ( V_6 -> V_58 )
F_7 ( V_32 , sizeof( V_59 ) , & V_59 ) ;
if ( V_36 -> V_64 ) {
V_39 . V_71 . type = V_75 ;
V_39 . V_71 . V_17 = F_6 ( sizeof( V_39 ) ) ;
V_39 . V_64 = F_14 ( V_36 -> V_64 ) ;
F_7 ( V_32 , sizeof( V_39 ) , & V_39 ) ;
}
if ( V_27 -> V_65 ) {
F_7 ( V_32 , sizeof( V_6 -> V_46 . V_66 ) ,
V_6 -> V_46 . V_66 ) ;
if ( V_44 )
F_7 ( V_32 , F_18 ( V_44 -> V_17 ) ,
V_44 ) ;
if ( V_43 )
F_7 ( V_32 , F_18 ( V_43 -> V_17 ) ,
V_43 ) ;
}
V_69:
F_21 ( V_30 . V_72 ) ;
return V_32 ;
}
struct V_3 * F_22 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
T_5 V_23 , int V_76 )
{
T_6 V_77 ;
struct V_3 * V_32 ;
union V_29 V_30 ;
struct V_35 * V_36 ;
int V_34 ;
T_12 * V_78 ;
int V_79 ;
T_2 V_31 ;
T_8 V_39 ;
T_9 V_40 ;
int V_41 = 0 ;
T_10 V_42 [ 3 ] ;
T_11 * V_43 = NULL ,
* V_44 = NULL ,
* V_66 = NULL ;
V_32 = NULL ;
V_30 = F_13 ( & V_6 -> V_8 . V_80 , & V_34 , V_23 ) ;
V_77 . V_45 = F_14 ( V_6 -> V_46 . V_47 ) ;
V_77 . V_48 = F_14 ( V_6 -> V_49 ) ;
V_77 . V_50 = F_6 ( V_6 -> V_46 . V_51 ) ;
V_77 . V_52 = F_6 ( V_6 -> V_46 . V_53 ) ;
V_77 . V_54 = F_14 ( V_6 -> V_46 . V_54 ) ;
V_78 = F_23 ( V_6 -> V_27 , V_6 , V_4 , & V_79 ,
V_30 . V_72 , V_34 ) ;
if ( ! V_78 )
goto V_81;
V_36 = F_15 ( V_6 -> V_8 . V_7 ) ;
V_31 = sizeof( V_77 ) + V_34 + V_79 + V_76 ;
if ( V_6 -> V_82 . V_83 )
V_31 += sizeof( V_57 ) ;
if ( V_6 -> V_82 . V_84 )
V_31 += sizeof( V_59 ) ;
if ( V_6 -> V_82 . V_85 ) {
V_42 [ V_41 ] = V_62 ;
V_42 [ V_41 + 1 ] = V_63 ;
V_41 += 2 ;
}
if ( V_36 -> V_64 )
V_31 += sizeof( V_39 ) ;
if ( V_6 -> V_82 . V_86 ) {
V_66 = ( T_11 * ) V_6 -> V_46 . V_66 ;
V_31 += F_18 ( V_66 -> V_17 ) ;
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
V_42 [ V_41 ] = V_67 ;
V_41 += 1 ;
}
if ( V_41 )
V_31 += F_16 ( sizeof( T_9 ) +
V_41 ) ;
V_32 = F_19 ( V_6 , V_87 , 0 , V_31 , V_23 ) ;
if ( ! V_32 )
goto V_88;
V_32 -> V_89 = V_4 -> V_89 ;
V_32 -> V_18 . V_70 =
F_7 ( V_32 , sizeof( V_77 ) , & V_77 ) ;
V_32 -> V_71 . V_72 = F_7 ( V_32 , V_34 , V_30 . V_72 ) ;
F_7 ( V_32 , V_79 , V_78 ) ;
if ( V_6 -> V_82 . V_83 )
F_7 ( V_32 , sizeof( V_57 ) , & V_57 ) ;
if ( V_41 ) {
V_40 . V_71 . type = V_74 ;
V_40 . V_71 . V_17 =
F_6 ( sizeof( T_9 ) + V_41 ) ;
F_7 ( V_32 , sizeof( T_9 ) ,
& V_40 ) ;
F_20 ( V_32 , V_41 , V_42 ) ;
}
if ( V_6 -> V_82 . V_84 )
F_7 ( V_32 , sizeof( V_59 ) , & V_59 ) ;
if ( V_36 -> V_64 ) {
V_39 . V_71 . type = V_75 ;
V_39 . V_71 . V_17 = F_6 ( sizeof( V_39 ) ) ;
V_39 . V_64 = F_14 ( V_36 -> V_64 ) ;
F_7 ( V_32 , sizeof( V_39 ) , & V_39 ) ;
}
if ( V_6 -> V_82 . V_86 ) {
F_7 ( V_32 , F_18 ( V_66 -> V_17 ) ,
V_66 ) ;
if ( V_44 )
F_7 ( V_32 , F_18 ( V_44 -> V_17 ) ,
V_44 ) ;
if ( V_43 )
F_7 ( V_32 , F_18 ( V_43 -> V_17 ) ,
V_43 ) ;
}
V_32 -> V_6 = (struct V_5 * ) V_6 ;
V_88:
F_21 ( V_78 ) ;
V_81:
F_21 ( V_30 . V_72 ) ;
return V_32 ;
}
struct V_3 * F_24 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_32 ;
void * V_78 ;
int V_79 ;
V_78 = V_6 -> V_82 . V_78 ;
V_79 = V_6 -> V_82 . V_79 ;
V_32 = F_19 ( V_6 , V_90 , 0 ,
V_79 , V_91 ) ;
if ( ! V_32 )
goto V_69;
V_32 -> V_18 . V_92 =
F_7 ( V_32 , V_79 , V_78 ) ;
if ( V_4 )
V_32 -> V_89 = V_4 -> V_89 ;
V_69:
return V_32 ;
}
struct V_3 * F_25 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_32 ;
V_32 = F_19 ( V_6 , V_93 , 0 , 0 , V_91 ) ;
if ( V_32 && V_4 )
V_32 -> V_89 = V_4 -> V_89 ;
return V_32 ;
}
struct V_3 * F_26 ( const struct V_5 * V_6 ,
const T_13 V_94 ,
const struct V_3 * V_4 )
{
struct V_3 * V_32 ;
T_14 V_95 ;
V_95 . V_94 = F_14 ( V_94 ) ;
V_32 = F_19 ( V_6 , V_96 , 0 ,
sizeof( T_14 ) , V_91 ) ;
if ( ! V_32 )
goto V_69;
V_32 -> V_18 . V_97 =
F_7 ( V_32 , sizeof( V_95 ) , & V_95 ) ;
if ( V_4 )
V_32 -> V_89 = V_4 -> V_89 ;
V_69:
return V_32 ;
}
struct V_3 * F_27 ( const struct V_5 * V_6 ,
const T_13 V_94 )
{
struct V_3 * V_32 ;
T_15 V_98 ;
V_98 . V_94 = F_14 ( V_94 ) ;
V_32 = F_19 ( V_6 , V_99 , 0 ,
sizeof( T_15 ) , V_91 ) ;
if ( ! V_32 )
goto V_69;
V_32 -> V_18 . V_100 =
F_7 ( V_32 , sizeof( V_98 ) , & V_98 ) ;
V_69:
return V_32 ;
}
struct V_3 * F_28 ( struct V_5 * V_6 ,
const struct V_101 * V_102 ,
int V_103 , T_10 V_104 , T_4 V_105 ,
T_5 V_23 )
{
struct V_3 * V_32 ;
struct V_106 V_107 ;
int V_108 ;
V_107 . V_109 = 0 ;
V_107 . V_110 = F_6 ( V_102 -> V_111 ) ;
V_107 . V_112 = V_102 -> V_113 ;
if ( V_102 -> V_114 & V_115 ) {
V_104 |= V_116 ;
V_107 . V_105 = 0 ;
} else
V_107 . V_105 = F_6 ( V_105 ) ;
V_108 = sizeof( V_107 ) + V_103 ;
V_32 = F_29 ( V_6 , V_104 , V_108 , V_23 ) ;
if ( ! V_32 )
goto V_69;
V_32 -> V_18 . V_117 = F_7 ( V_32 , sizeof( V_107 ) , & V_107 ) ;
memcpy ( & V_32 -> V_102 , V_102 , sizeof( struct V_101 ) ) ;
V_69:
return V_32 ;
}
struct V_3 * F_30 ( const struct V_5 * V_6 )
{
struct V_3 * V_32 ;
struct V_118 V_119 ;
int V_15 ;
T_13 V_120 ;
T_4 V_121 , V_122 ;
struct V_5 * V_123 = (struct V_5 * ) V_6 ;
struct V_124 * V_125 = (struct V_124 * ) & V_6 -> V_82 . V_126 ;
struct V_127 V_128 [ V_129 ] ;
struct V_130 * V_131 ;
memset ( V_128 , 0 , sizeof( V_128 ) ) ;
V_120 = F_31 ( V_125 ) ;
F_32 ( L_1 , V_132 , V_120 ) ;
V_121 = F_33 ( V_125 , V_128 ) ;
V_122 = F_34 ( V_125 ) ;
V_119 . V_133 = F_14 ( V_120 ) ;
V_119 . V_48 = F_14 ( V_6 -> V_48 ) ;
V_119 . V_134 = F_6 ( V_121 ) ;
V_119 . V_122 = F_6 ( V_122 ) ;
V_15 = sizeof( V_119 )
+ sizeof( struct V_127 ) * V_121
+ sizeof( T_13 ) * V_122 ;
V_32 = F_19 ( V_6 , V_135 , 0 , V_15 , V_91 ) ;
if ( ! V_32 )
goto V_69;
V_32 -> V_89 = V_6 -> V_82 . V_136 ;
V_32 -> V_18 . V_137 =
F_7 ( V_32 , sizeof( V_119 ) , & V_119 ) ;
if ( V_121 )
F_7 ( V_32 , sizeof( T_13 ) * V_121 ,
V_128 ) ;
if ( V_122 ) {
V_123 -> V_138 . V_139 += V_122 ;
F_7 ( V_32 , sizeof( T_13 ) * V_122 ,
F_35 ( V_125 ) ) ;
}
if ( ++ V_123 -> V_82 . V_140 == 0 ) {
F_36 (trans, &asoc->peer.transport_addr_list,
transports)
V_131 -> V_140 = 0 ;
V_123 -> V_82 . V_140 = 1 ;
}
V_69:
return V_32 ;
}
struct V_3 * F_37 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_32 ;
T_16 V_141 ;
T_13 V_120 ;
V_120 = F_31 ( & V_6 -> V_82 . V_126 ) ;
V_141 . V_133 = F_14 ( V_120 ) ;
V_32 = F_19 ( V_6 , V_142 , 0 ,
sizeof( T_16 ) , V_91 ) ;
if ( ! V_32 )
goto V_69;
V_32 -> V_18 . V_143 =
F_7 ( V_32 , sizeof( V_141 ) , & V_141 ) ;
if ( V_4 )
V_32 -> V_89 = V_4 -> V_89 ;
V_69:
return V_32 ;
}
struct V_3 * F_38 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_32 ;
V_32 = F_19 ( V_6 , V_144 , 0 , 0 ,
V_91 ) ;
if ( V_32 && V_4 )
V_32 -> V_89 = V_4 -> V_89 ;
return V_32 ;
}
struct V_3 * F_39 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_32 ;
T_10 V_104 = 0 ;
V_104 |= V_6 ? 0 : V_145 ;
V_32 = F_19 ( V_6 , V_146 , V_104 ,
0 , V_91 ) ;
if ( V_32 && V_4 )
V_32 -> V_89 = V_4 -> V_89 ;
return V_32 ;
}
struct V_3 * F_40 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
const T_2 V_147 )
{
struct V_3 * V_32 ;
T_10 V_104 = 0 ;
if ( ! V_6 ) {
if ( V_4 && V_4 -> V_148 &&
V_4 -> V_148 -> type == V_68 )
V_104 = 0 ;
else
V_104 = V_145 ;
}
V_32 = F_19 ( V_6 , V_149 , V_104 , V_147 ,
V_91 ) ;
if ( V_32 && V_4 )
V_32 -> V_89 = V_4 -> V_89 ;
return V_32 ;
}
struct V_3 * F_41 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 , T_13 V_109 )
{
struct V_3 * V_32 ;
T_17 V_150 ;
V_32 = F_40 ( V_6 , V_4 , sizeof( T_3 )
+ sizeof( V_109 ) ) ;
if ( ! V_32 )
goto V_151;
V_150 = F_14 ( V_109 ) ;
F_5 ( V_32 , V_152 , sizeof( V_150 ) ) ;
F_7 ( V_32 , sizeof( V_150 ) , ( const void * ) & V_150 ) ;
if ( V_4 )
V_32 -> V_89 = V_4 -> V_89 ;
V_151:
return V_32 ;
}
struct V_3 * F_42 ( const struct V_5 * V_6 ,
struct V_153 * V_154 ,
T_2 V_13 )
{
struct V_3 * V_32 ;
void * V_150 = NULL ;
int V_14 ;
V_32 = F_40 ( V_6 , NULL , sizeof( T_3 ) + V_13 ) ;
if ( ! V_32 )
goto V_155;
if ( V_13 ) {
V_150 = F_43 ( V_13 , V_156 ) ;
if ( ! V_150 )
goto V_157;
V_14 = F_44 ( V_150 , V_154 , V_13 ) ;
if ( V_14 < 0 )
goto V_158;
}
F_5 ( V_32 , V_159 , V_13 ) ;
F_7 ( V_32 , V_13 , V_150 ) ;
if ( V_13 )
F_21 ( V_150 ) ;
return V_32 ;
V_158:
F_21 ( V_150 ) ;
V_157:
F_45 ( V_32 ) ;
V_32 = NULL ;
V_155:
return V_32 ;
}
static void * F_20 ( struct V_3 * V_4 , int V_15 ,
const void * V_160 )
{
void * V_161 ;
int V_162 = F_18 ( V_4 -> V_148 -> V_17 ) ;
V_161 = F_46 ( V_4 -> V_2 , V_15 ) ;
if ( V_160 )
memcpy ( V_161 , V_160 , V_15 ) ;
else
memset ( V_161 , 0 , V_15 ) ;
V_4 -> V_148 -> V_17 = F_6 ( V_162 + V_15 ) ;
V_4 -> V_163 = F_47 ( V_4 -> V_2 ) ;
return V_161 ;
}
struct V_3 * F_48 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
const T_10 * V_150 ,
const T_2 V_13 )
{
struct V_3 * V_32 ;
struct V_164 V_165 ;
V_32 = F_40 ( V_6 , V_4 , sizeof( T_3 ) + V_13
+ sizeof( T_11 ) ) ;
if ( ! V_32 )
goto V_166;
F_5 ( V_32 , V_167 , V_13
+ sizeof( T_11 ) ) ;
V_165 . type = F_6 ( V_4 -> V_148 -> type ) ;
V_165 . V_17 = V_4 -> V_148 -> V_17 ;
F_7 ( V_32 , V_13 , V_150 ) ;
F_20 ( V_32 , sizeof( T_11 ) , & V_165 ) ;
V_166:
return V_32 ;
}
struct V_3 * F_49 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
struct V_164 * V_168 )
{
struct V_3 * V_32 ;
static const char error [] = L_2 ;
T_2 V_169 = sizeof( error ) + sizeof( T_3 ) +
sizeof( T_11 ) ;
V_32 = F_40 ( V_6 , V_4 , V_169 ) ;
if ( ! V_32 )
goto V_69;
F_5 ( V_32 , V_167 ,
sizeof( error ) + sizeof( T_11 ) ) ;
F_7 ( V_32 , sizeof( error ) , error ) ;
F_20 ( V_32 , sizeof( T_11 ) , V_168 ) ;
V_69:
return V_32 ;
}
struct V_3 * F_50 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
struct V_3 * V_32 ;
static const char error [] = L_3 ;
T_2 V_169 = sizeof( error ) + sizeof( T_3 ) ;
V_32 = F_40 ( V_6 , V_4 , V_169 ) ;
if ( ! V_32 )
goto V_69;
F_5 ( V_32 , V_167 , sizeof( error ) ) ;
F_7 ( V_32 , sizeof( error ) , error ) ;
V_69:
return V_32 ;
}
struct V_3 * F_51 ( const struct V_5 * V_6 ,
const struct V_130 * V_89 )
{
struct V_3 * V_32 ;
T_18 V_170 ;
V_32 = F_19 ( V_6 , V_171 , 0 ,
sizeof( V_170 ) , V_91 ) ;
if ( ! V_32 )
goto V_69;
V_170 . V_71 . type = V_172 ;
V_170 . V_71 . V_17 = F_6 ( sizeof( T_18 ) ) ;
V_170 . V_173 = V_89 -> V_174 ;
V_170 . V_175 = V_176 ;
V_170 . V_177 = V_89 -> V_177 ;
V_32 -> V_89 = (struct V_130 * ) V_89 ;
V_32 -> V_18 . V_178 = F_7 ( V_32 , sizeof( V_170 ) ,
& V_170 ) ;
V_69:
return V_32 ;
}
struct V_3 * F_52 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
const void * V_150 , const T_2 V_13 )
{
struct V_3 * V_32 ;
V_32 = F_19 ( V_6 , V_179 , 0 , V_13 ,
V_91 ) ;
if ( ! V_32 )
goto V_69;
V_32 -> V_18 . V_178 = F_7 ( V_32 , V_13 , V_150 ) ;
if ( V_4 )
V_32 -> V_89 = V_4 -> V_89 ;
V_69:
return V_32 ;
}
static struct V_3 * F_53 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
T_2 V_180 )
{
struct V_3 * V_32 ;
V_32 = F_19 ( V_6 , V_181 , 0 ,
sizeof( T_3 ) + V_180 , V_91 ) ;
if ( ! V_32 )
goto V_69;
if ( V_4 )
V_32 -> V_89 = V_4 -> V_89 ;
V_69:
return V_32 ;
}
static inline struct V_3 * F_54 (
const struct V_5 * V_6 ,
const struct V_3 * V_4 )
{
T_2 V_180 = V_6 ? V_6 -> V_182 : 0 ;
if ( ! V_180 )
V_180 = V_183 ;
return F_53 ( V_6 , V_4 , V_180 ) ;
}
struct V_3 * F_55 ( const struct V_5 * V_6 ,
const struct V_3 * V_4 ,
T_1 V_12 , const void * V_150 ,
T_2 V_13 , T_2 V_184 )
{
struct V_3 * V_32 ;
V_32 = F_53 ( V_6 , V_4 , V_13 + V_184 ) ;
if ( ! V_32 )
goto V_69;
F_5 ( V_32 , V_12 , V_13 + V_184 ) ;
F_7 ( V_32 , V_13 , V_150 ) ;
if ( V_184 )
F_20 ( V_32 , V_184 , NULL ) ;
V_69:
return V_32 ;
}
struct V_3 * F_56 ( const struct V_5 * V_6 )
{
struct V_3 * V_32 ;
struct V_185 * V_186 ;
struct V_187 V_188 ;
T_10 * V_189 ;
V_186 = F_57 ( V_6 ) ;
if ( F_58 ( ! V_186 ) )
return NULL ;
V_32 = F_19 ( V_6 , V_67 , 0 ,
V_186 -> V_190 + sizeof( V_191 ) ,
V_91 ) ;
if ( ! V_32 )
return NULL ;
V_188 . V_192 = F_6 ( V_186 -> V_192 ) ;
V_188 . V_193 = F_6 ( V_6 -> V_194 ) ;
V_32 -> V_18 . V_188 = F_7 ( V_32 , sizeof( V_191 ) ,
& V_188 ) ;
V_189 = F_46 ( V_32 -> V_2 , V_186 -> V_190 ) ;
memset ( V_189 , 0 , V_186 -> V_190 ) ;
V_32 -> V_148 -> V_17 =
F_6 ( F_18 ( V_32 -> V_148 -> V_17 ) + V_186 -> V_190 ) ;
V_32 -> V_163 = F_47 ( V_32 -> V_2 ) ;
return V_32 ;
}
struct V_3 * F_59 ( struct V_1 * V_2 ,
const struct V_5 * V_6 ,
struct V_195 * V_7 , T_5 V_23 )
{
struct V_3 * V_32 ;
V_32 = F_60 ( V_196 , V_23 ) ;
if ( ! V_32 )
goto V_69;
if ( ! V_7 )
F_32 ( L_4 , V_132 , V_2 ) ;
F_61 ( & V_32 -> V_197 ) ;
V_32 -> V_2 = V_2 ;
V_32 -> V_6 = (struct V_5 * ) V_6 ;
V_32 -> V_198 = 1 ;
V_32 -> V_199 = V_200 ;
F_61 ( & V_32 -> V_201 ) ;
F_61 ( & V_32 -> V_202 ) ;
F_62 ( V_4 ) ;
F_63 ( & V_32 -> V_203 , 1 ) ;
V_69:
return V_32 ;
}
void F_64 ( struct V_3 * V_4 , union V_204 * V_205 ,
union V_204 * V_206 )
{
memcpy ( & V_4 -> V_207 , V_205 , sizeof( union V_204 ) ) ;
memcpy ( & V_4 -> V_206 , V_206 , sizeof( union V_204 ) ) ;
}
const union V_204 * F_65 ( const struct V_3 * V_4 )
{
if ( V_4 -> V_89 ) {
return & V_4 -> V_89 -> V_174 ;
} else {
return & V_4 -> V_207 ;
}
}
static struct V_3 * F_66 ( const struct V_5 * V_6 ,
T_10 type , T_10 V_104 , int V_13 ,
T_5 V_23 )
{
struct V_3 * V_32 ;
T_19 * V_148 ;
struct V_1 * V_2 ;
struct V_195 * V_7 ;
V_2 = F_67 ( F_16 ( sizeof( T_19 ) + V_13 ) , V_23 ) ;
if ( ! V_2 )
goto V_69;
V_148 = ( T_19 * ) F_46 ( V_2 , sizeof( T_19 ) ) ;
V_148 -> type = type ;
V_148 -> V_104 = V_104 ;
V_148 -> V_17 = F_6 ( sizeof( T_19 ) ) ;
V_7 = V_6 ? V_6 -> V_8 . V_7 : NULL ;
V_32 = F_59 ( V_2 , V_6 , V_7 , V_23 ) ;
if ( ! V_32 ) {
F_68 ( V_2 ) ;
goto V_69;
}
V_32 -> V_148 = V_148 ;
V_32 -> V_163 = ( ( T_10 * ) V_148 ) + sizeof( struct V_208 ) ;
if ( F_69 ( type , V_6 ) )
V_32 -> V_209 = 1 ;
return V_32 ;
V_69:
return NULL ;
}
static struct V_3 * F_29 ( const struct V_5 * V_6 ,
T_10 V_104 , int V_13 , T_5 V_23 )
{
return F_66 ( V_6 , V_210 , V_104 , V_13 , V_23 ) ;
}
static struct V_3 * F_19 ( const struct V_5 * V_6 ,
T_10 type , T_10 V_104 , int V_13 ,
T_5 V_23 )
{
struct V_3 * V_4 ;
V_4 = F_66 ( V_6 , type , V_104 , V_13 , V_23 ) ;
if ( V_4 )
F_2 ( V_4 ) ;
return V_4 ;
}
static void F_70 ( struct V_3 * V_4 )
{
F_71 ( ! F_72 ( & V_4 -> V_197 ) ) ;
F_73 ( & V_4 -> V_201 ) ;
F_74 ( V_4 -> V_2 ) ;
F_74 ( V_4 -> V_211 ) ;
F_75 ( V_4 ) ;
F_76 ( V_196 , V_4 ) ;
}
void F_45 ( struct V_3 * V_4 )
{
if ( V_4 -> V_154 )
F_77 ( V_4 -> V_154 ) ;
F_78 ( V_4 ) ;
}
void F_79 ( struct V_3 * V_212 )
{
F_80 ( & V_212 -> V_203 ) ;
}
void F_78 ( struct V_3 * V_212 )
{
if ( F_81 ( & V_212 -> V_203 ) )
F_70 ( V_212 ) ;
}
void * F_7 ( struct V_3 * V_4 , int V_15 , const void * V_160 )
{
void * V_161 ;
void * V_213 ;
int V_162 = F_18 ( V_4 -> V_148 -> V_17 ) ;
int V_214 = F_16 ( V_162 ) - V_162 ;
V_213 = F_46 ( V_4 -> V_2 , V_214 ) ;
V_161 = F_46 ( V_4 -> V_2 , V_15 ) ;
memset ( V_213 , 0 , V_214 ) ;
memcpy ( V_161 , V_160 , V_15 ) ;
V_4 -> V_148 -> V_17 = F_6 ( V_162 + V_214 + V_15 ) ;
V_4 -> V_163 = F_47 ( V_4 -> V_2 ) ;
return V_161 ;
}
static void * F_10 ( struct V_3 * V_4 ,
int V_15 , const void * V_160 )
{
if ( F_9 ( V_4 -> V_2 ) >= V_15 )
return F_7 ( V_4 , V_15 , V_160 ) ;
else
return NULL ;
}
int F_82 ( struct V_3 * V_4 , int V_15 ,
struct V_215 * V_216 )
{
void * V_161 ;
T_20 V_217 ;
V_161 = F_46 ( V_4 -> V_2 , V_15 ) ;
V_217 = F_83 ( V_161 , V_15 , V_216 ) ;
if ( V_217 != V_15 )
return - V_218 ;
V_4 -> V_148 -> V_17 =
F_6 ( F_18 ( V_4 -> V_148 -> V_17 ) + V_15 ) ;
V_4 -> V_163 = F_47 ( V_4 -> V_2 ) ;
return 0 ;
}
void F_84 ( struct V_3 * V_4 )
{
struct V_219 * V_154 ;
struct V_3 * V_220 ;
struct V_221 * V_110 ;
T_4 V_105 ;
T_4 V_222 ;
if ( V_4 -> V_223 )
return;
V_222 = F_18 ( V_4 -> V_18 . V_117 -> V_110 ) ;
V_110 = & V_4 -> V_6 -> V_224 -> V_225 ;
V_154 = V_4 -> V_154 ;
F_36 (lchunk, &msg->chunks, frag_list) {
if ( V_220 -> V_148 -> V_104 & V_116 ) {
V_105 = 0 ;
} else {
if ( V_220 -> V_148 -> V_104 & V_226 )
V_105 = F_85 ( V_110 , V_222 ) ;
else
V_105 = F_86 ( V_110 , V_222 ) ;
}
V_220 -> V_18 . V_117 -> V_105 = F_6 ( V_105 ) ;
V_220 -> V_223 = 1 ;
}
}
void F_87 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_227 ) {
V_4 -> V_18 . V_117 -> V_109 =
F_14 ( F_88 ( V_4 -> V_6 ) ) ;
V_4 -> V_227 = 1 ;
}
}
struct V_5 * F_89 ( const struct V_26 * V_27 ,
struct V_3 * V_4 ,
T_5 V_23 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
T_21 V_228 ;
V_228 = F_90 ( F_65 ( V_4 ) ) ;
V_6 = F_91 ( V_27 , V_27 -> V_8 . V_7 , V_228 , V_23 ) ;
if ( ! V_6 )
goto V_69;
V_6 -> V_229 = 1 ;
V_2 = V_4 -> V_2 ;
F_4 ( V_2 ) -> V_10 -> V_230 ( & V_6 -> V_46 . V_231 , V_2 , 1 ) ;
V_69:
return V_6 ;
}
static T_12 * F_23 ( const struct V_26 * V_27 ,
const struct V_5 * V_6 ,
const struct V_3 * V_232 ,
int * V_79 ,
const T_10 * V_233 , int V_34 )
{
T_12 * V_32 ;
struct V_234 * V_78 ;
int V_235 , V_236 ;
V_235 = sizeof( T_11 ) +
( sizeof( struct V_234 ) -
sizeof( struct V_237 ) ) ;
V_236 = sizeof( struct V_237 )
+ F_18 ( V_232 -> V_148 -> V_17 ) + V_34 ;
if ( V_236 % V_238 )
V_236 += V_238
- ( V_236 % V_238 ) ;
* V_79 = V_235 + V_236 ;
V_32 = F_92 ( * V_79 , V_91 ) ;
if ( ! V_32 )
goto V_69;
V_78 = (struct V_234 * ) V_32 -> V_239 ;
V_32 -> V_240 . type = V_241 ;
V_32 -> V_240 . V_17 = F_6 ( * V_79 ) ;
V_78 -> V_46 = V_6 -> V_46 ;
V_78 -> V_46 . V_242 = V_34 ;
V_78 -> V_46 . V_84 = V_6 -> V_82 . V_84 ;
V_78 -> V_46 . V_64 = V_6 -> V_82 . V_64 ;
V_78 -> V_46 . V_243 = F_93 ( V_6 -> V_244 ,
F_94 () ) ;
memcpy ( & V_78 -> V_46 . V_245 [ 0 ] , V_232 -> V_148 ,
F_18 ( V_232 -> V_148 -> V_17 ) ) ;
memcpy ( ( T_10 * ) & V_78 -> V_46 . V_245 [ 0 ] +
F_18 ( V_232 -> V_148 -> V_17 ) , V_233 , V_34 ) ;
if ( F_15 ( V_27 -> V_8 . V_7 ) -> V_189 ) {
F_95 ( V_246 , F_15 ( V_27 -> V_8 . V_7 ) -> V_189 ) ;
int V_14 ;
V_246 -> V_247 = F_15 ( V_27 -> V_8 . V_7 ) -> V_189 ;
V_246 -> V_104 = 0 ;
V_14 = F_96 ( V_246 -> V_247 , V_27 -> V_248 ,
sizeof( V_27 -> V_248 ) ) ? :
F_97 ( V_246 , ( V_249 * ) & V_78 -> V_46 , V_236 ,
V_78 -> V_250 ) ;
F_98 ( V_246 ) ;
if ( V_14 )
goto V_251;
}
return V_32 ;
V_251:
F_21 ( V_32 ) ;
V_69:
* V_79 = 0 ;
return NULL ;
}
struct V_5 * F_99 (
const struct V_26 * V_27 ,
const struct V_5 * V_6 ,
struct V_3 * V_4 , T_5 V_23 ,
int * error , struct V_3 * * V_252 )
{
struct V_5 * V_32 = NULL ;
struct V_234 * V_78 ;
struct V_237 * V_253 ;
int V_235 , V_236 , V_254 ;
T_10 * V_255 = V_27 -> V_255 ;
unsigned int V_15 ;
T_21 V_228 ;
struct V_1 * V_2 = V_4 -> V_2 ;
T_22 V_256 ;
V_235 = sizeof( T_19 ) +
( sizeof( struct V_234 ) -
sizeof( struct V_237 ) ) ;
V_236 = F_18 ( V_4 -> V_148 -> V_17 ) - V_235 ;
V_254 = V_235 + sizeof( struct V_237 ) ;
V_15 = F_18 ( V_4 -> V_148 -> V_17 ) ;
if ( V_15 < V_254 + sizeof( struct V_208 ) )
goto V_257;
if ( V_236 % V_238 )
goto V_257;
V_78 = V_4 -> V_18 . V_92 ;
V_253 = & V_78 -> V_46 ;
if ( ! F_15 ( V_27 -> V_8 . V_7 ) -> V_189 )
goto V_258;
{
F_95 ( V_246 , F_15 ( V_27 -> V_8 . V_7 ) -> V_189 ) ;
int V_14 ;
V_246 -> V_247 = F_15 ( V_27 -> V_8 . V_7 ) -> V_189 ;
V_246 -> V_104 = 0 ;
V_14 = F_96 ( V_246 -> V_247 , V_27 -> V_248 ,
sizeof( V_27 -> V_248 ) ) ? :
F_97 ( V_246 , ( V_249 * ) V_253 , V_236 ,
V_255 ) ;
F_98 ( V_246 ) ;
if ( V_14 ) {
* error = - V_259 ;
goto V_260;
}
}
if ( memcmp ( V_255 , V_78 -> V_250 , V_261 ) ) {
* error = - V_262 ;
goto V_260;
}
V_258:
if ( F_100 ( V_4 -> V_263 -> V_264 ) != V_253 -> V_47 ) {
* error = - V_265 ;
goto V_260;
}
if ( V_4 -> V_263 -> V_207 != V_253 -> V_231 . V_266 . V_267 ||
F_18 ( V_4 -> V_263 -> V_206 ) != V_253 -> V_268 ) {
* error = - V_269 ;
goto V_260;
}
if ( F_101 ( V_27 -> V_8 . V_7 , V_270 ) )
V_256 = F_102 ( V_2 ) ;
else
V_256 = F_94 () ;
if ( ! V_6 && F_103 ( V_253 -> V_243 , V_256 ) ) {
V_15 = F_18 ( V_4 -> V_148 -> V_17 ) ;
* V_252 = F_53 ( V_6 , V_4 , V_15 ) ;
if ( * V_252 ) {
T_23 V_271 = F_104 ( F_105 ( V_256 , V_253 -> V_243 ) ) ;
T_17 V_272 = F_14 ( V_271 ) ;
F_5 ( * V_252 , V_273 ,
sizeof( V_272 ) ) ;
F_7 ( * V_252 , sizeof( V_272 ) , & V_272 ) ;
* error = - V_274 ;
} else
* error = - V_259 ;
goto V_260;
}
V_228 = F_90 ( F_65 ( V_4 ) ) ;
V_32 = F_91 ( V_27 , V_27 -> V_8 . V_7 , V_228 , V_23 ) ;
if ( ! V_32 ) {
* error = - V_259 ;
goto V_260;
}
V_32 -> V_82 . V_275 = F_18 ( V_4 -> V_263 -> V_207 ) ;
memcpy ( & V_32 -> V_46 , V_253 , sizeof( * V_253 ) ) ;
if ( F_106 ( V_32 , V_253 ,
V_91 ) < 0 ) {
* error = - V_259 ;
goto V_260;
}
if ( F_72 ( & V_32 -> V_8 . V_80 . V_276 ) ) {
F_107 ( & V_32 -> V_8 . V_80 , & V_4 -> V_206 ,
sizeof( V_4 -> V_206 ) , V_277 ,
V_91 ) ;
}
V_32 -> V_278 = V_32 -> V_46 . V_54 ;
V_32 -> V_279 = V_32 -> V_278 - 1 ;
V_32 -> V_280 = V_32 -> V_46 . V_54 ;
V_32 -> V_281 = V_32 -> V_279 ;
V_32 -> V_82 . V_84 = V_32 -> V_46 . V_84 ;
V_32 -> V_82 . V_64 = V_32 -> V_46 . V_64 ;
return V_32 ;
V_260:
if ( V_32 )
F_108 ( V_32 ) ;
return NULL ;
V_257:
* error = - V_282 ;
goto V_260;
}
static int F_109 ( const struct V_5 * V_6 ,
T_24 V_283 ,
struct V_3 * V_4 ,
struct V_3 * * V_252 )
{
struct V_284 V_285 ;
T_4 V_15 ;
V_15 = F_16 ( sizeof( V_285 ) ) ;
if ( ! * V_252 )
* V_252 = F_53 ( V_6 , V_4 , V_15 ) ;
if ( * V_252 ) {
V_285 . V_286 = F_14 ( 1 ) ;
V_285 . type = V_283 ;
F_5 ( * V_252 , V_287 ,
sizeof( V_285 ) ) ;
F_7 ( * V_252 , sizeof( V_285 ) , & V_285 ) ;
}
return 0 ;
}
static int F_110 ( const struct V_5 * V_6 ,
struct V_3 * V_4 ,
struct V_3 * * V_252 )
{
if ( ! * V_252 )
* V_252 = F_53 ( V_6 , V_4 , 0 ) ;
if ( * V_252 )
F_5 ( * V_252 , V_288 , 0 ) ;
return 0 ;
}
static int F_111 ( const struct V_5 * V_6 ,
struct V_164 * V_168 ,
const struct V_3 * V_4 ,
struct V_3 * * V_252 )
{
if ( * V_252 )
F_45 ( * V_252 ) ;
* V_252 = F_49 ( V_6 , V_4 , V_168 ) ;
return 0 ;
}
static int F_112 ( const struct V_5 * V_6 ,
union V_29 V_168 ,
struct V_3 * V_4 ,
struct V_3 * * V_252 )
{
T_4 V_15 = F_18 ( V_168 . V_240 -> V_17 ) ;
if ( * V_252 )
F_45 ( * V_252 ) ;
* V_252 = F_53 ( V_6 , V_4 , V_15 ) ;
if ( * V_252 ) {
F_5 ( * V_252 , V_289 , V_15 ) ;
F_7 ( * V_252 , V_15 , V_168 . V_72 ) ;
}
return 0 ;
}
static int F_113 ( struct V_25 * V_25 , union V_29 V_168 )
{
T_4 V_41 = F_18 ( V_168 . V_240 -> V_17 ) - sizeof( T_11 ) ;
int V_290 = 0 ;
int V_291 = 0 ;
int V_292 ;
for ( V_292 = 0 ; V_292 < V_41 ; V_292 ++ ) {
switch ( V_168 . V_293 -> V_294 [ V_292 ] ) {
case V_67 :
V_290 = 1 ;
break;
case V_62 :
case V_63 :
V_291 = 1 ;
break;
}
}
if ( V_25 -> V_60 . V_295 )
return 1 ;
if ( V_25 -> V_60 . V_61 && ! V_290 && V_291 )
return 0 ;
return 1 ;
}
static void F_114 ( struct V_5 * V_6 ,
union V_29 V_168 )
{
struct V_25 * V_25 = F_12 ( V_6 -> V_8 . V_7 ) ;
T_4 V_41 = F_18 ( V_168 . V_240 -> V_17 ) - sizeof( T_11 ) ;
int V_292 ;
for ( V_292 = 0 ; V_292 < V_41 ; V_292 ++ ) {
switch ( V_168 . V_293 -> V_294 [ V_292 ] ) {
case V_296 :
if ( V_6 -> V_58 && ! V_6 -> V_82 . V_84 )
V_6 -> V_82 . V_84 = 1 ;
break;
case V_67 :
if ( V_6 -> V_27 -> V_65 )
V_6 -> V_82 . V_86 = 1 ;
break;
case V_62 :
case V_63 :
if ( V_25 -> V_60 . V_61 )
V_6 -> V_82 . V_85 = 1 ;
break;
default:
break;
}
}
}
static T_25 F_115 ( const struct V_5 * V_6 ,
union V_29 V_168 ,
struct V_3 * V_4 ,
struct V_3 * * V_252 )
{
int V_32 = V_297 ;
switch ( V_168 . V_240 -> type & V_298 ) {
case V_299 :
V_32 = V_300 ;
break;
case V_301 :
break;
case V_302 :
V_32 = V_300 ;
case V_303 :
if ( NULL == * V_252 )
* V_252 = F_54 ( V_6 , V_4 ) ;
if ( * V_252 ) {
if ( ! F_8 ( * V_252 , V_304 ,
F_16 ( F_18 ( V_168 . V_240 -> V_17 ) ) ) )
F_10 ( * V_252 ,
F_16 ( F_18 ( V_168 . V_240 -> V_17 ) ) ,
V_168 . V_72 ) ;
} else {
V_32 = V_259 ;
}
break;
default:
break;
}
return V_32 ;
}
static T_25 F_116 ( struct V_25 * V_25 ,
const struct V_26 * V_27 ,
const struct V_5 * V_6 ,
union V_29 V_168 ,
T_26 V_305 ,
struct V_3 * V_4 ,
struct V_3 * * V_155 )
{
struct V_306 * V_307 ;
int V_32 = V_297 ;
T_4 V_308 , V_309 = 0 ;
int V_292 ;
switch ( V_168 . V_240 -> type ) {
case V_310 :
case V_311 :
case V_312 :
case V_73 :
case V_241 :
case V_172 :
case V_313 :
case V_314 :
case V_75 :
break;
case V_74 :
if ( ! F_113 ( V_25 , V_168 ) )
return V_315 ;
break;
case V_316 :
if ( V_25 -> V_60 . V_61 )
break;
goto V_317;
case V_318 :
F_112 ( V_6 , V_168 , V_4 , V_155 ) ;
V_32 = V_315 ;
break;
case V_319 :
if ( V_27 -> V_58 )
break;
goto V_317;
case V_320 :
if ( ! V_27 -> V_65 )
goto V_317;
if ( V_321 !=
F_18 ( V_168 . V_240 -> V_17 ) - sizeof( T_11 ) ) {
F_111 ( V_6 , V_168 . V_240 ,
V_4 , V_155 ) ;
V_32 = V_315 ;
}
break;
case V_322 :
if ( ! V_27 -> V_65 )
goto V_317;
if ( 260 < F_18 ( V_168 . V_240 -> V_17 ) ) {
F_111 ( V_6 , V_168 . V_240 ,
V_4 , V_155 ) ;
V_32 = V_315 ;
}
break;
case V_323 :
if ( ! V_27 -> V_65 )
goto V_317;
V_307 = (struct V_306 * ) V_168 . V_240 ;
V_308 = ( F_18 ( V_168 . V_240 -> V_17 ) - sizeof( T_11 ) ) >> 1 ;
for ( V_292 = 0 ; V_292 < V_308 ; V_292 ++ ) {
V_309 = F_18 ( V_307 -> V_324 [ V_292 ] ) ;
if ( V_309 == V_325 )
break;
}
if ( V_309 != V_325 ) {
F_111 ( V_6 , V_168 . V_240 , V_4 ,
V_155 ) ;
V_32 = V_315 ;
}
break;
V_317:
default:
F_32 ( L_5 ,
V_132 , F_18 ( V_168 . V_240 -> type ) , V_305 ) ;
V_32 = F_115 ( V_6 , V_168 , V_4 , V_155 ) ;
break;
}
return V_32 ;
}
int F_117 ( struct V_25 * V_25 , const struct V_26 * V_27 ,
const struct V_5 * V_6 , T_26 V_305 ,
T_27 * V_245 , struct V_3 * V_4 ,
struct V_3 * * V_252 )
{
union V_29 V_168 ;
bool V_326 = false ;
int V_327 ;
if ( V_245 -> V_70 . V_50 == 0 ||
V_245 -> V_70 . V_52 == 0 ||
V_245 -> V_70 . V_45 == 0 ||
F_100 ( V_245 -> V_70 . V_48 ) < V_328 )
return F_110 ( V_6 , V_4 , V_252 ) ;
F_118 (param, peer_init, init_hdr.params) {
if ( V_168 . V_240 -> type == V_241 )
V_326 = true ;
}
if ( V_168 . V_72 != ( void * ) V_4 -> V_163 )
return F_111 ( V_6 , V_168 . V_240 , V_4 , V_252 ) ;
if ( ( V_87 == V_305 ) && ! V_326 )
return F_109 ( V_6 , V_241 ,
V_4 , V_252 ) ;
F_118 (param, peer_init, init_hdr.params) {
V_327 = F_116 ( V_25 , V_27 , V_6 , V_168 , V_305 ,
V_4 , V_252 ) ;
switch ( V_327 ) {
case V_315 :
case V_259 :
return 0 ;
case V_300 :
return 1 ;
case V_297 :
default:
break;
}
}
return 1 ;
}
int F_119 ( struct V_5 * V_6 , struct V_3 * V_4 ,
const union V_204 * V_231 ,
T_27 * V_245 , T_5 V_23 )
{
struct V_25 * V_25 = F_12 ( V_6 -> V_8 . V_7 ) ;
union V_29 V_168 ;
struct V_130 * V_89 ;
struct V_329 * V_330 , * V_229 ;
struct V_331 * V_10 ;
union V_204 V_332 ;
char * V_78 ;
int V_333 = 0 ;
if ( ! F_120 ( V_6 , V_231 , V_23 , V_334 ) )
goto V_335;
if ( F_121 ( F_65 ( V_4 ) , V_231 ) )
V_333 = 1 ;
F_118 (param, peer_init, init_hdr.params) {
if ( ! V_333 && ( V_168 . V_240 -> type == V_310 ||
V_168 . V_240 -> type == V_311 ) ) {
V_10 = F_122 ( F_123 ( V_168 . V_240 -> type ) ) ;
V_10 -> V_336 ( & V_332 , V_168 . V_332 ,
V_4 -> V_263 -> V_207 , 0 ) ;
if ( F_121 ( F_65 ( V_4 ) , & V_332 ) )
V_333 = 1 ;
}
if ( ! F_124 ( V_6 , V_168 , V_231 , V_23 ) )
goto V_337;
}
if ( ! V_333 )
goto V_337;
if ( V_6 -> V_82 . V_86 && ( ! V_6 -> V_82 . V_338 ||
! V_6 -> V_82 . V_339 ) )
V_6 -> V_82 . V_86 = 0 ;
if ( ! V_25 -> V_60 . V_295 &&
( V_6 -> V_82 . V_85 && ! V_6 -> V_82 . V_86 ) ) {
V_6 -> V_82 . V_340 |= ( V_341 |
V_342 |
V_316 ) ;
V_6 -> V_82 . V_85 = 0 ;
goto V_337;
}
F_125 (pos, temp, &asoc->peer.transport_addr_list) {
V_89 = F_126 ( V_330 , struct V_130 , V_343 ) ;
if ( V_89 -> V_344 == V_345 ) {
F_127 ( V_6 , V_89 ) ;
}
}
V_6 -> V_82 . V_292 . V_45 =
F_100 ( V_245 -> V_70 . V_45 ) ;
V_6 -> V_82 . V_292 . V_48 =
F_100 ( V_245 -> V_70 . V_48 ) ;
V_6 -> V_82 . V_292 . V_50 =
F_18 ( V_245 -> V_70 . V_50 ) ;
V_6 -> V_82 . V_292 . V_52 =
F_18 ( V_245 -> V_70 . V_52 ) ;
V_6 -> V_82 . V_292 . V_54 =
F_100 ( V_245 -> V_70 . V_54 ) ;
if ( V_6 -> V_46 . V_51 >
F_18 ( V_245 -> V_70 . V_52 ) ) {
V_6 -> V_46 . V_51 =
F_18 ( V_245 -> V_70 . V_52 ) ;
}
if ( V_6 -> V_46 . V_53 >
F_18 ( V_245 -> V_70 . V_50 ) ) {
V_6 -> V_46 . V_53 =
F_18 ( V_245 -> V_70 . V_50 ) ;
}
V_6 -> V_46 . V_346 = V_6 -> V_82 . V_292 . V_45 ;
V_6 -> V_82 . V_49 = V_6 -> V_82 . V_292 . V_48 ;
V_78 = V_6 -> V_82 . V_78 ;
if ( V_78 ) {
V_6 -> V_82 . V_78 = F_128 ( V_78 , V_6 -> V_82 . V_79 , V_23 ) ;
if ( ! V_6 -> V_82 . V_78 )
goto V_337;
}
F_36 (transport, &asoc->peer.transport_addr_list,
transports) {
V_89 -> V_347 = V_6 -> V_82 . V_292 . V_48 ;
}
if ( ! F_129 ( & V_6 -> V_82 . V_126 , V_348 ,
V_6 -> V_82 . V_292 . V_54 , V_23 ) )
goto V_337;
if ( ! V_6 -> V_229 ) {
int error ;
V_6 -> V_224 = F_130 ( V_6 -> V_46 . V_53 ,
V_6 -> V_46 . V_51 , V_23 ) ;
if ( ! V_6 -> V_224 )
goto V_337;
error = F_131 ( V_6 , V_23 ) ;
if ( error )
goto V_337;
}
V_6 -> V_82 . V_280 = V_6 -> V_82 . V_292 . V_54 - 1 ;
return 1 ;
V_337:
F_125 (pos, temp, &asoc->peer.transport_addr_list) {
V_89 = F_126 ( V_330 , struct V_130 , V_343 ) ;
if ( V_89 -> V_344 != V_334 )
F_127 ( V_6 , V_89 ) ;
}
V_335:
return 0 ;
}
static int F_124 ( struct V_5 * V_6 ,
union V_29 V_168 ,
const union V_204 * V_231 ,
T_5 V_23 )
{
struct V_25 * V_25 = F_12 ( V_6 -> V_8 . V_7 ) ;
union V_204 V_332 ;
int V_292 ;
T_4 V_37 ;
int V_32 = 1 ;
T_21 V_228 ;
T_28 V_349 ;
struct V_331 * V_10 ;
union V_350 * V_351 ;
struct V_130 * V_352 ;
struct V_26 * V_27 = V_6 -> V_27 ;
switch ( V_168 . V_240 -> type ) {
case V_311 :
if ( V_353 != V_6 -> V_8 . V_7 -> V_354 )
break;
goto V_355;
case V_310 :
if ( F_132 ( V_6 -> V_8 . V_7 ) )
break;
V_355:
V_10 = F_122 ( F_123 ( V_168 . V_240 -> type ) ) ;
V_10 -> V_336 ( & V_332 , V_168 . V_332 , F_6 ( V_6 -> V_82 . V_275 ) , 0 ) ;
V_228 = F_90 ( V_231 ) ;
if ( F_133 ( V_25 , & V_332 , V_228 ) )
if ( ! F_120 ( V_6 , & V_332 , V_23 , V_356 ) )
return 0 ;
break;
case V_312 :
if ( ! V_25 -> V_60 . V_357 )
break;
V_349 = F_100 ( V_168 . V_358 -> V_359 ) ;
V_6 -> V_244 = F_134 ( V_6 -> V_244 , V_349 ) ;
break;
case V_318 :
F_32 ( L_6 , V_132 ) ;
break;
case V_73 :
V_6 -> V_82 . V_360 = 0 ;
V_6 -> V_82 . V_361 = 0 ;
if ( V_231 -> V_362 . V_363 == V_364 )
V_6 -> V_82 . V_361 = 1 ;
else if ( V_231 -> V_362 . V_363 == V_365 )
V_6 -> V_82 . V_360 = 1 ;
V_37 = F_18 ( V_168 . V_240 -> V_17 ) - sizeof( T_11 ) ;
if ( V_37 )
V_37 /= sizeof( T_4 ) ;
for ( V_292 = 0 ; V_292 < V_37 ; ++ V_292 ) {
switch ( V_168 . V_37 -> V_38 [ V_292 ] ) {
case V_310 :
V_6 -> V_82 . V_360 = 1 ;
break;
case V_311 :
if ( V_353 == V_6 -> V_8 . V_7 -> V_354 )
V_6 -> V_82 . V_361 = 1 ;
break;
case V_318 :
V_6 -> V_82 . V_366 = 1 ;
break;
default:
break;
}
}
break;
case V_241 :
V_6 -> V_82 . V_79 =
F_18 ( V_168 . V_240 -> V_17 ) - sizeof( T_11 ) ;
V_6 -> V_82 . V_78 = V_168 . V_78 -> V_239 ;
break;
case V_172 :
break;
case V_313 :
break;
case V_314 :
V_6 -> V_82 . V_83 = 1 ;
break;
case V_75 :
V_6 -> V_82 . V_64 = F_100 ( V_168 . V_367 -> V_64 ) ;
break;
case V_316 :
if ( ! V_25 -> V_60 . V_61 )
goto V_368;
V_351 = V_168 . V_72 + sizeof( V_369 ) ;
V_10 = F_122 ( F_123 ( V_351 -> V_240 . type ) ) ;
if ( V_10 == NULL )
break;
V_10 -> V_336 ( & V_332 , V_351 ,
F_6 ( V_6 -> V_82 . V_275 ) , 0 ) ;
if ( ! V_10 -> V_370 ( & V_332 , NULL , NULL ) )
break;
V_352 = F_135 ( V_6 , & V_332 ) ;
if ( ! V_352 )
break;
F_136 ( V_6 , V_352 ) ;
break;
case V_74 :
F_114 ( V_6 , V_168 ) ;
break;
case V_319 :
if ( V_6 -> V_58 ) {
V_6 -> V_82 . V_84 = 1 ;
break;
}
goto V_368;
case V_320 :
if ( ! V_27 -> V_65 )
goto V_368;
V_6 -> V_82 . V_338 = F_128 ( V_168 . V_240 ,
F_18 ( V_168 . V_240 -> V_17 ) , V_23 ) ;
if ( ! V_6 -> V_82 . V_338 ) {
V_32 = 0 ;
break;
}
break;
case V_323 :
if ( ! V_27 -> V_65 )
goto V_368;
V_6 -> V_82 . V_339 = F_128 ( V_168 . V_240 ,
F_18 ( V_168 . V_240 -> V_17 ) , V_23 ) ;
if ( ! V_6 -> V_82 . V_339 ) {
V_32 = 0 ;
break;
}
F_137 ( V_6 , V_168 . V_371 ) ;
break;
case V_322 :
if ( ! V_27 -> V_65 )
goto V_368;
V_6 -> V_82 . V_372 = F_128 ( V_168 . V_240 ,
F_18 ( V_168 . V_240 -> V_17 ) , V_23 ) ;
if ( ! V_6 -> V_82 . V_372 )
V_32 = 0 ;
break;
V_368:
default:
F_32 ( L_7 ,
V_132 , F_18 ( V_168 . V_240 -> type ) , V_6 ) ;
break;
}
return V_32 ;
}
T_13 F_138 ( const struct V_26 * V_27 )
{
T_13 V_373 ;
do {
F_139 ( & V_373 , sizeof( T_13 ) ) ;
} while ( V_373 == 0 );
return V_373 ;
}
T_13 F_140 ( const struct V_26 * V_27 )
{
T_13 V_32 ;
F_139 ( & V_32 , sizeof( T_13 ) ) ;
return V_32 ;
}
static struct V_3 * F_141 ( struct V_5 * V_6 ,
union V_204 * V_332 ,
int V_24 )
{
T_29 V_374 ;
struct V_3 * V_32 ;
int V_17 = sizeof( V_374 ) + V_24 ;
union V_350 V_375 ;
int V_376 ;
struct V_331 * V_10 = F_122 ( V_332 -> V_266 . V_377 ) ;
V_376 = V_10 -> V_378 ( V_332 , & V_375 ) ;
if ( ! V_376 )
return NULL ;
V_17 += V_376 ;
V_32 = F_19 ( V_6 , V_62 , 0 , V_17 ,
V_91 ) ;
if ( ! V_32 )
return NULL ;
V_374 . V_379 = F_14 ( V_6 -> V_280 ++ ) ;
V_32 -> V_18 . V_380 =
F_7 ( V_32 , sizeof( V_374 ) , & V_374 ) ;
V_32 -> V_71 . V_72 =
F_7 ( V_32 , V_376 , & V_375 ) ;
return V_32 ;
}
struct V_3 * F_142 ( struct V_5 * V_6 ,
union V_204 * V_381 ,
struct V_382 * V_30 ,
int V_383 ,
T_1 V_104 )
{
V_369 V_168 ;
struct V_3 * V_32 ;
union V_350 V_351 ;
union V_204 * V_332 ;
void * V_384 ;
struct V_331 * V_10 ;
int V_385 = sizeof( V_168 ) ;
int V_386 = 0 ;
int V_387 = 0 ;
int V_292 ;
int V_388 = 0 ;
V_384 = V_30 ;
for ( V_292 = 0 ; V_292 < V_383 ; V_292 ++ ) {
V_332 = V_384 ;
V_10 = F_122 ( V_332 -> V_266 . V_377 ) ;
V_386 = V_10 -> V_378 ( V_332 , & V_351 ) ;
V_387 += V_385 ;
V_387 += V_386 ;
V_384 += V_10 -> V_389 ;
if ( V_6 -> V_390 && ! V_388 ) {
V_387 += V_385 ;
V_387 += V_386 ;
V_388 = 1 ;
F_32 ( L_8
L_9 ,
V_132 , V_387 ) ;
}
}
V_32 = F_141 ( V_6 , V_381 , V_387 ) ;
if ( ! V_32 )
return NULL ;
V_384 = V_30 ;
for ( V_292 = 0 ; V_292 < V_383 ; V_292 ++ ) {
V_332 = V_384 ;
V_10 = F_122 ( V_332 -> V_266 . V_377 ) ;
V_386 = V_10 -> V_378 ( V_332 , & V_351 ) ;
V_168 . V_71 . type = V_104 ;
V_168 . V_71 . V_17 = F_6 ( V_385 + V_386 ) ;
V_168 . V_391 = V_292 ;
F_7 ( V_32 , V_385 , & V_168 ) ;
F_7 ( V_32 , V_386 , & V_351 ) ;
V_384 += V_10 -> V_389 ;
}
if ( V_104 == V_341 && V_388 ) {
V_332 = V_6 -> V_390 ;
V_10 = F_122 ( V_332 -> V_266 . V_377 ) ;
V_386 = V_10 -> V_378 ( V_332 , & V_351 ) ;
V_168 . V_71 . type = V_342 ;
V_168 . V_71 . V_17 = F_6 ( V_385 + V_386 ) ;
V_168 . V_391 = V_292 ;
F_7 ( V_32 , V_385 , & V_168 ) ;
F_7 ( V_32 , V_386 , & V_351 ) ;
}
return V_32 ;
}
struct V_3 * F_143 ( struct V_5 * V_6 ,
union V_204 * V_332 )
{
V_369 V_168 ;
struct V_3 * V_32 ;
int V_15 = sizeof( V_168 ) ;
union V_350 V_375 ;
int V_376 ;
struct V_331 * V_10 = F_122 ( V_332 -> V_266 . V_377 ) ;
V_376 = V_10 -> V_378 ( V_332 , & V_375 ) ;
if ( ! V_376 )
return NULL ;
V_15 += V_376 ;
V_32 = F_141 ( V_6 , V_332 , V_15 ) ;
if ( ! V_32 )
return NULL ;
V_168 . V_71 . type = V_316 ;
V_168 . V_71 . V_17 = F_6 ( V_15 ) ;
V_168 . V_391 = 0 ;
F_7 ( V_32 , sizeof( V_168 ) , & V_168 ) ;
F_7 ( V_32 , V_376 , & V_375 ) ;
return V_32 ;
}
static struct V_3 * F_144 ( const struct V_5 * V_6 ,
T_13 V_379 , int V_24 )
{
T_29 V_374 ;
struct V_3 * V_32 ;
int V_17 = sizeof( V_374 ) + V_24 ;
V_32 = F_19 ( V_6 , V_63 , 0 , V_17 ,
V_91 ) ;
if ( ! V_32 )
return NULL ;
V_374 . V_379 = F_14 ( V_379 ) ;
V_32 -> V_18 . V_380 =
F_7 ( V_32 , sizeof( V_374 ) , & V_374 ) ;
return V_32 ;
}
static void F_145 ( struct V_3 * V_4 , T_17 V_391 ,
T_1 V_392 , V_369 * V_393 )
{
V_369 V_394 ;
T_3 V_395 ;
int V_396 = 0 ;
int V_397 = 0 ;
T_1 V_398 ;
if ( V_399 == V_392 ) {
V_398 = V_400 ;
} else {
V_398 = V_401 ;
V_397 = sizeof( V_395 ) ;
if ( V_393 )
V_396 =
F_18 ( V_393 -> V_71 . V_17 ) ;
}
V_394 . V_71 . type = V_398 ;
V_394 . V_71 . V_17 = F_6 ( sizeof( V_394 ) +
V_397 +
V_396 ) ;
V_394 . V_391 = V_391 ;
F_7 ( V_4 , sizeof( V_394 ) , & V_394 ) ;
if ( V_399 == V_392 )
return;
V_395 . V_16 = V_392 ;
V_395 . V_17 = F_6 ( V_397 + V_396 ) ;
F_7 ( V_4 , V_397 , & V_395 ) ;
if ( V_393 )
F_7 ( V_4 , V_396 , V_393 ) ;
}
static T_1 F_146 ( struct V_5 * V_6 ,
struct V_3 * V_374 ,
V_369 * V_393 )
{
struct V_130 * V_82 ;
struct V_331 * V_10 ;
union V_204 V_332 ;
union V_350 * V_351 ;
V_351 = ( void * ) V_393 + sizeof( V_369 ) ;
if ( V_393 -> V_71 . type != V_341 &&
V_393 -> V_71 . type != V_342 &&
V_393 -> V_71 . type != V_316 )
return V_304 ;
switch ( V_351 -> V_240 . type ) {
case V_311 :
if ( ! V_6 -> V_82 . V_361 )
return V_289 ;
break;
case V_310 :
if ( ! V_6 -> V_82 . V_360 )
return V_289 ;
break;
default:
return V_289 ;
}
V_10 = F_122 ( F_123 ( V_351 -> V_240 . type ) ) ;
if ( F_58 ( ! V_10 ) )
return V_289 ;
V_10 -> V_336 ( & V_332 , V_351 , F_6 ( V_6 -> V_82 . V_275 ) , 0 ) ;
if ( ! V_10 -> V_402 ( & V_332 ) && ! V_10 -> V_370 ( & V_332 , NULL , V_374 -> V_2 ) )
return V_289 ;
switch ( V_393 -> V_71 . type ) {
case V_341 :
if ( V_10 -> V_402 ( & V_332 ) )
memcpy ( & V_332 , & V_374 -> V_207 , sizeof( V_332 ) ) ;
V_82 = F_120 ( V_6 , & V_332 , V_91 , V_356 ) ;
if ( ! V_82 )
return V_403 ;
F_147 ( V_82 ) ;
V_6 -> V_404 = V_82 ;
break;
case V_342 :
if ( V_6 -> V_82 . V_405 == 1 )
return V_406 ;
if ( F_121 ( & V_374 -> V_207 , & V_332 ) )
return V_407 ;
if ( V_10 -> V_402 ( & V_332 ) ) {
F_136 ( V_6 , V_374 -> V_89 ) ;
F_148 ( V_6 ,
V_374 -> V_89 ) ;
return V_399 ;
}
V_82 = F_135 ( V_6 , & V_332 ) ;
if ( ! V_82 )
return V_289 ;
F_127 ( V_6 , V_82 ) ;
break;
case V_316 :
if ( V_10 -> V_402 ( & V_332 ) )
memcpy ( & V_332 . V_266 , F_65 ( V_374 ) , sizeof( V_332 ) ) ;
V_82 = F_135 ( V_6 , & V_332 ) ;
if ( ! V_82 )
return V_289 ;
F_136 ( V_6 , V_82 ) ;
break;
}
return V_399 ;
}
bool F_149 ( const struct V_5 * V_6 ,
struct V_3 * V_4 , bool V_408 ,
struct V_164 * * V_252 )
{
T_30 * V_409 = ( T_30 * ) V_4 -> V_148 ;
union V_29 V_168 ;
bool V_410 = false ;
F_118 (param, addip, addip_hdr.params) {
T_2 V_17 = F_18 ( V_168 . V_240 -> V_17 ) ;
* V_252 = V_168 . V_240 ;
switch ( V_168 . V_240 -> type ) {
case V_401 :
break;
case V_310 :
if ( V_17 != sizeof( V_411 ) )
return false ;
if ( V_168 . V_72 != V_409 -> V_380 . V_412 )
return false ;
V_410 = true ;
break;
case V_311 :
if ( V_17 != sizeof( V_413 ) )
return false ;
if ( V_168 . V_72 != V_409 -> V_380 . V_412 )
return false ;
V_410 = true ;
break;
case V_341 :
case V_342 :
case V_316 :
if ( V_408 && ! V_410 )
return false ;
V_17 = F_18 ( V_168 . V_409 -> V_71 . V_17 ) ;
if ( V_17 < sizeof( V_369 ) +
sizeof( T_11 ) )
return false ;
break;
case V_400 :
case V_75 :
if ( V_17 != sizeof( V_369 ) )
return false ;
break;
default:
return false ;
}
}
if ( V_408 && ! V_410 )
return false ;
if ( ! V_408 && V_410 )
return false ;
if ( V_168 . V_72 != V_4 -> V_163 )
return false ;
return true ;
}
struct V_3 * F_150 ( struct V_5 * V_6 ,
struct V_3 * V_374 )
{
T_30 * V_409 = ( T_30 * ) V_374 -> V_148 ;
bool V_414 = true ;
union V_29 V_168 ;
T_29 * V_415 ;
union V_350 * V_351 ;
V_369 * V_393 ;
struct V_3 * V_416 ;
T_1 V_392 ;
int V_17 = 0 ;
int V_108 ;
T_13 V_379 ;
V_108 = F_18 ( V_374 -> V_148 -> V_17 ) - sizeof( T_19 ) ;
V_415 = ( T_29 * ) V_374 -> V_2 -> V_160 ;
V_379 = F_100 ( V_415 -> V_379 ) ;
V_17 = sizeof( T_29 ) ;
V_351 = (union V_350 * ) ( V_374 -> V_2 -> V_160 + V_17 ) ;
V_108 -= V_17 ;
V_17 = F_18 ( V_351 -> V_240 . V_17 ) ;
V_393 = ( void * ) V_351 + V_17 ;
V_108 -= V_17 ;
V_416 = F_144 ( V_6 , V_379 , V_108 * 4 ) ;
if ( ! V_416 )
goto V_417;
F_118 (param, addip, addip_hdr.params) {
if ( V_168 . V_240 -> type == V_310 ||
V_168 . V_240 -> type == V_311 )
continue;
V_392 = F_146 ( V_6 , V_374 ,
V_168 . V_409 ) ;
if ( V_392 != V_399 )
V_414 = false ;
if ( ! V_414 )
F_145 ( V_416 , V_168 . V_409 -> V_391 ,
V_392 , V_168 . V_409 ) ;
if ( V_392 == V_403 )
goto V_417;
}
V_417:
V_6 -> V_82 . V_280 ++ ;
if ( V_416 ) {
F_79 ( V_416 ) ;
F_151 ( & V_416 -> V_201 ,
& V_6 -> V_418 ) ;
}
return V_416 ;
}
static void F_152 ( struct V_5 * V_6 ,
V_369 * V_393 )
{
struct V_331 * V_10 ;
union V_204 V_332 ;
struct V_21 * V_22 = & V_6 -> V_8 . V_80 ;
union V_350 * V_351 ;
struct V_130 * V_89 ;
struct V_419 * V_420 ;
V_351 = ( void * ) V_393 + sizeof( V_369 ) ;
V_10 = F_122 ( F_123 ( V_351 -> V_240 . type ) ) ;
V_10 -> V_336 ( & V_332 , V_351 , F_6 ( V_22 -> V_275 ) , 0 ) ;
switch ( V_393 -> V_71 . type ) {
case V_341 :
F_153 () ;
F_36 (saddr, &bp->address_list, list) {
if ( F_121 ( & V_420 -> V_421 , & V_332 ) )
V_420 -> V_344 = V_277 ;
}
F_154 () ;
F_36 (transport, &asoc->peer.transport_addr_list,
transports) {
F_155 ( V_89 -> V_422 ) ;
V_89 -> V_422 = NULL ;
}
break;
case V_342 :
F_153 () ;
F_156 ( V_22 , & V_332 ) ;
if ( V_6 -> V_390 != NULL &&
F_121 ( V_6 -> V_390 , & V_332 ) ) {
F_21 ( V_6 -> V_390 ) ;
V_6 -> V_390 = NULL ;
}
F_154 () ;
F_36 (transport, &asoc->peer.transport_addr_list,
transports) {
F_155 ( V_89 -> V_422 ) ;
V_89 -> V_422 = NULL ;
}
break;
default:
break;
}
}
static T_1 F_157 ( struct V_3 * V_416 ,
V_369 * V_393 ,
int V_423 )
{
V_369 * V_424 ;
T_3 * V_395 ;
int V_17 ;
int V_425 ;
T_1 V_392 ;
if ( V_423 )
V_392 = V_399 ;
else
V_392 = V_426 ;
V_425 = F_18 ( V_416 -> V_148 -> V_17 ) -
sizeof( T_19 ) ;
V_17 = sizeof( T_29 ) ;
V_424 = ( V_369 * ) ( V_416 -> V_2 -> V_160 +
V_17 ) ;
V_425 -= V_17 ;
while ( V_425 > 0 ) {
if ( V_424 -> V_391 == V_393 -> V_391 ) {
switch ( V_424 -> V_71 . type ) {
case V_400 :
return V_399 ;
case V_401 :
V_17 = sizeof( V_369 ) ;
V_395 = ( void * ) V_424 + V_17 ;
V_425 -= V_17 ;
if ( V_425 > 0 )
return V_395 -> V_16 ;
else
return V_288 ;
break;
default:
return V_288 ;
}
}
V_17 = F_18 ( V_424 -> V_71 . V_17 ) ;
V_424 = ( void * ) V_424 + V_17 ;
V_425 -= V_17 ;
}
return V_392 ;
}
int F_158 ( struct V_5 * V_6 ,
struct V_3 * V_416 )
{
struct V_3 * V_374 = V_6 -> V_427 ;
union V_350 * V_351 ;
V_369 * V_393 ;
int V_17 = 0 ;
int V_428 = V_374 -> V_2 -> V_15 ;
int V_414 = 0 ;
int V_423 = 1 ;
int V_32 = 0 ;
T_1 V_392 = V_399 ;
V_17 = sizeof( T_30 ) ;
V_351 = (union V_350 * ) ( V_374 -> V_2 -> V_160 + V_17 ) ;
V_428 -= V_17 ;
V_17 = F_18 ( V_351 -> V_240 . V_17 ) ;
V_393 = ( void * ) V_351 + V_17 ;
V_428 -= V_17 ;
if ( V_416 -> V_2 -> V_15 == sizeof( T_29 ) )
V_414 = 1 ;
while ( V_428 > 0 ) {
if ( V_414 )
V_392 = V_399 ;
else {
V_392 = F_157 ( V_416 ,
V_393 ,
V_423 ) ;
if ( V_423 && ( V_399 != V_392 ) )
V_423 = 0 ;
}
switch ( V_392 ) {
case V_399 :
F_152 ( V_6 , V_393 ) ;
break;
case V_403 :
V_32 = 1 ;
break;
case V_304 :
V_6 -> V_82 . V_340 |=
V_393 -> V_71 . type ;
break;
case V_426 :
case V_406 :
case V_407 :
default:
break;
}
V_17 = F_18 ( V_393 -> V_71 . V_17 ) ;
V_393 = ( void * ) V_393 + V_17 ;
V_428 -= V_17 ;
}
if ( V_423 && V_6 -> V_429 ) {
V_6 -> V_429 = 0 ;
F_159 ( V_6 -> V_82 . V_430 ) ;
}
F_73 ( & V_374 -> V_201 ) ;
F_45 ( V_374 ) ;
V_6 -> V_427 = NULL ;
return V_32 ;
}
struct V_3 * F_160 ( const struct V_5 * V_6 ,
T_13 V_431 , T_2 V_432 ,
struct V_433 * V_434 )
{
struct V_3 * V_32 = NULL ;
struct V_435 V_436 ;
struct V_433 V_437 ;
T_2 V_147 ;
int V_292 ;
V_147 = ( V_432 + 1 ) * sizeof( T_13 ) ;
V_32 = F_19 ( V_6 , V_296 , 0 , V_147 , V_91 ) ;
if ( ! V_32 )
return NULL ;
V_436 . V_431 = F_14 ( V_431 ) ;
V_32 -> V_18 . V_438 =
F_7 ( V_32 , sizeof( V_436 ) , & V_436 ) ;
for ( V_292 = 0 ; V_292 < V_432 ; V_292 ++ ) {
V_437 . V_110 = V_434 [ V_292 ] . V_110 ;
V_437 . V_105 = V_434 [ V_292 ] . V_105 ;
F_7 ( V_32 , sizeof( V_437 ) , & V_437 ) ;
}
return V_32 ;
}

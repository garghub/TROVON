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
int F_8 ( struct V_1 * V_2 , T_1 V_9 ,
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
T_6 V_24 ;
union V_25 V_26 ;
T_2 V_27 ;
struct V_1 * V_28 = NULL ;
int V_29 , V_30 = 0 ;
struct V_31 * V_32 ;
T_7 V_33 ;
T_1 V_34 [ 2 ] ;
T_8 V_35 ;
T_9 V_36 ;
int V_37 = 0 ;
T_10 V_38 [ 3 ] ;
T_11 * V_39 = NULL ,
* V_40 = NULL ;
V_28 = NULL ;
V_26 = F_12 ( V_21 , & V_30 , V_22 ) ;
V_24 . V_41 = F_13 ( V_19 -> V_42 . V_43 ) ;
V_24 . V_44 = F_13 ( V_19 -> V_45 ) ;
V_24 . V_46 = F_6 ( V_19 -> V_42 . V_47 ) ;
V_24 . V_48 = F_6 ( V_19 -> V_42 . V_49 ) ;
V_24 . V_50 = F_13 ( V_19 -> V_42 . V_50 ) ;
V_32 = F_14 ( V_19 -> V_51 . V_52 ) ;
V_29 = V_32 -> V_53 -> V_54 ( V_32 , V_34 ) ;
V_27 = sizeof( V_24 ) + V_30 ;
V_27 += F_15 ( F_16 ( V_29 ) ) ;
V_27 += sizeof( V_55 ) ;
if ( V_56 )
V_27 += sizeof( V_57 ) ;
if ( V_58 ) {
V_38 [ V_37 ] = V_59 ;
V_38 [ V_37 + 1 ] = V_60 ;
V_37 += 2 ;
}
if ( V_32 -> V_61 )
V_27 += sizeof( V_35 ) ;
V_27 += V_23 ;
if ( V_62 ) {
V_27 += sizeof( V_19 -> V_42 . V_63 ) ;
V_40 = ( T_11 * ) V_19 -> V_42 . V_40 ;
if ( V_40 -> V_14 )
V_27 += F_15 ( F_17 ( V_40 -> V_14 ) ) ;
else
V_40 = NULL ;
V_39 = ( T_11 * ) V_19 -> V_42 . V_39 ;
if ( V_39 -> V_14 )
V_27 += F_15 ( F_17 ( V_39 -> V_14 ) ) ;
else
V_39 = NULL ;
V_38 [ V_37 ] = V_64 ;
V_37 += 1 ;
}
if ( V_37 )
V_27 += F_15 ( sizeof( T_9 ) +
V_37 ) ;
V_28 = F_18 ( V_19 , V_65 , 0 , V_27 ) ;
if ( ! V_28 )
goto V_66;
V_28 -> V_15 . V_67 =
F_7 ( V_28 , sizeof( V_24 ) , & V_24 ) ;
V_28 -> V_68 . V_69 =
F_7 ( V_28 , V_30 , V_26 . V_69 ) ;
V_33 . V_68 . type = V_70 ;
V_33 . V_68 . V_14 = F_6 ( F_16 ( V_29 ) ) ;
F_7 ( V_28 , sizeof( V_33 ) , & V_33 ) ;
F_7 ( V_28 , V_29 * sizeof( T_4 ) , & V_34 ) ;
F_7 ( V_28 , sizeof( V_55 ) , & V_55 ) ;
if ( V_37 ) {
V_36 . V_68 . type = V_71 ;
V_36 . V_68 . V_14 =
F_6 ( sizeof( T_9 ) + V_37 ) ;
F_7 ( V_28 , sizeof( T_9 ) ,
& V_36 ) ;
F_19 ( V_28 , V_37 , V_38 ) ;
}
if ( V_56 )
F_7 ( V_28 , sizeof( V_57 ) , & V_57 ) ;
if ( V_32 -> V_61 ) {
V_35 . V_68 . type = V_72 ;
V_35 . V_68 . V_14 = F_6 ( sizeof( V_35 ) ) ;
V_35 . V_61 = F_13 ( V_32 -> V_61 ) ;
F_7 ( V_28 , sizeof( V_35 ) , & V_35 ) ;
}
if ( V_62 ) {
F_7 ( V_28 , sizeof( V_19 -> V_42 . V_63 ) ,
V_19 -> V_42 . V_63 ) ;
if ( V_40 )
F_7 ( V_28 , F_17 ( V_40 -> V_14 ) ,
V_40 ) ;
if ( V_39 )
F_7 ( V_28 , F_17 ( V_39 -> V_14 ) ,
V_39 ) ;
}
V_66:
F_20 ( V_26 . V_69 ) ;
return V_28 ;
}
struct V_1 * F_21 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
T_5 V_22 , int V_73 )
{
T_6 V_74 ;
struct V_1 * V_28 ;
union V_25 V_26 ;
struct V_31 * V_32 ;
int V_30 ;
T_12 * V_75 ;
int V_76 ;
T_2 V_27 ;
T_8 V_35 ;
T_9 V_36 ;
int V_37 = 0 ;
T_10 V_38 [ 3 ] ;
T_11 * V_39 = NULL ,
* V_40 = NULL ,
* V_63 = NULL ;
V_28 = NULL ;
V_26 = F_12 ( & V_19 -> V_51 . V_77 , & V_30 , V_22 ) ;
V_74 . V_41 = F_13 ( V_19 -> V_42 . V_43 ) ;
V_74 . V_44 = F_13 ( V_19 -> V_45 ) ;
V_74 . V_46 = F_6 ( V_19 -> V_42 . V_47 ) ;
V_74 . V_48 = F_6 ( V_19 -> V_42 . V_49 ) ;
V_74 . V_50 = F_13 ( V_19 -> V_42 . V_50 ) ;
V_75 = F_22 ( V_19 -> V_78 , V_19 , V_2 , & V_76 ,
V_26 . V_69 , V_30 ) ;
if ( ! V_75 )
goto V_79;
V_32 = F_14 ( V_19 -> V_51 . V_52 ) ;
V_27 = sizeof( V_74 ) + V_30 + V_76 + V_73 ;
if ( V_19 -> V_80 . V_81 )
V_27 += sizeof( V_55 ) ;
if ( V_19 -> V_80 . V_82 )
V_27 += sizeof( V_57 ) ;
if ( V_19 -> V_80 . V_83 ) {
V_38 [ V_37 ] = V_59 ;
V_38 [ V_37 + 1 ] = V_60 ;
V_37 += 2 ;
}
if ( V_32 -> V_61 )
V_27 += sizeof( V_35 ) ;
if ( V_19 -> V_80 . V_84 ) {
V_63 = ( T_11 * ) V_19 -> V_42 . V_63 ;
V_27 += F_17 ( V_63 -> V_14 ) ;
V_40 = ( T_11 * ) V_19 -> V_42 . V_40 ;
if ( V_40 -> V_14 )
V_27 += F_15 ( F_17 ( V_40 -> V_14 ) ) ;
else
V_40 = NULL ;
V_39 = ( T_11 * ) V_19 -> V_42 . V_39 ;
if ( V_39 -> V_14 )
V_27 += F_15 ( F_17 ( V_39 -> V_14 ) ) ;
else
V_39 = NULL ;
V_38 [ V_37 ] = V_64 ;
V_37 += 1 ;
}
if ( V_37 )
V_27 += F_15 ( sizeof( T_9 ) +
V_37 ) ;
V_28 = F_18 ( V_19 , V_85 , 0 , V_27 ) ;
if ( ! V_28 )
goto V_86;
V_28 -> V_87 = V_2 -> V_87 ;
V_28 -> V_15 . V_67 =
F_7 ( V_28 , sizeof( V_74 ) , & V_74 ) ;
V_28 -> V_68 . V_69 = F_7 ( V_28 , V_30 , V_26 . V_69 ) ;
F_7 ( V_28 , V_76 , V_75 ) ;
if ( V_19 -> V_80 . V_81 )
F_7 ( V_28 , sizeof( V_55 ) , & V_55 ) ;
if ( V_37 ) {
V_36 . V_68 . type = V_71 ;
V_36 . V_68 . V_14 =
F_6 ( sizeof( T_9 ) + V_37 ) ;
F_7 ( V_28 , sizeof( T_9 ) ,
& V_36 ) ;
F_19 ( V_28 , V_37 , V_38 ) ;
}
if ( V_19 -> V_80 . V_82 )
F_7 ( V_28 , sizeof( V_57 ) , & V_57 ) ;
if ( V_32 -> V_61 ) {
V_35 . V_68 . type = V_72 ;
V_35 . V_68 . V_14 = F_6 ( sizeof( V_35 ) ) ;
V_35 . V_61 = F_13 ( V_32 -> V_61 ) ;
F_7 ( V_28 , sizeof( V_35 ) , & V_35 ) ;
}
if ( V_19 -> V_80 . V_84 ) {
F_7 ( V_28 , F_17 ( V_63 -> V_14 ) ,
V_63 ) ;
if ( V_40 )
F_7 ( V_28 , F_17 ( V_40 -> V_14 ) ,
V_40 ) ;
if ( V_39 )
F_7 ( V_28 , F_17 ( V_39 -> V_14 ) ,
V_39 ) ;
}
V_28 -> V_19 = (struct V_18 * ) V_19 ;
V_86:
F_20 ( V_75 ) ;
V_79:
F_20 ( V_26 . V_69 ) ;
return V_28 ;
}
struct V_1 * F_23 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
struct V_1 * V_28 ;
void * V_75 ;
int V_76 ;
V_75 = V_19 -> V_80 . V_75 ;
V_76 = V_19 -> V_80 . V_76 ;
V_28 = F_18 ( V_19 , V_88 , 0 , V_76 ) ;
if ( ! V_28 )
goto V_66;
V_28 -> V_15 . V_89 =
F_7 ( V_28 , V_76 , V_75 ) ;
if ( V_2 )
V_28 -> V_87 = V_2 -> V_87 ;
V_66:
return V_28 ;
}
struct V_1 * F_24 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
struct V_1 * V_28 ;
V_28 = F_18 ( V_19 , V_90 , 0 , 0 ) ;
if ( V_28 && V_2 )
V_28 -> V_87 = V_2 -> V_87 ;
return V_28 ;
}
struct V_1 * F_25 ( const struct V_18 * V_19 ,
const T_13 V_91 ,
const struct V_1 * V_2 )
{
struct V_1 * V_28 ;
T_14 V_92 ;
V_92 . V_91 = F_13 ( V_91 ) ;
V_28 = F_18 ( V_19 , V_93 , 0 ,
sizeof( T_14 ) ) ;
if ( ! V_28 )
goto V_66;
V_28 -> V_15 . V_94 =
F_7 ( V_28 , sizeof( V_92 ) , & V_92 ) ;
if ( V_2 )
V_28 -> V_87 = V_2 -> V_87 ;
V_66:
return V_28 ;
}
struct V_1 * F_26 ( const struct V_18 * V_19 ,
const T_13 V_91 )
{
struct V_1 * V_28 ;
T_15 V_95 ;
V_95 . V_91 = F_13 ( V_91 ) ;
V_28 = F_18 ( V_19 , V_96 , 0 ,
sizeof( T_15 ) ) ;
if ( ! V_28 )
goto V_66;
V_28 -> V_15 . V_97 =
F_7 ( V_28 , sizeof( V_95 ) , & V_95 ) ;
V_66:
return V_28 ;
}
struct V_1 * F_27 ( struct V_18 * V_19 ,
const struct V_98 * V_99 ,
int V_100 , T_10 V_101 , T_4 V_102 )
{
struct V_1 * V_28 ;
struct V_103 V_104 ;
int V_105 ;
V_104 . V_106 = 0 ;
V_104 . V_107 = F_6 ( V_99 -> V_108 ) ;
V_104 . V_109 = V_99 -> V_110 ;
if ( V_99 -> V_111 & V_112 ) {
V_101 |= V_113 ;
V_104 . V_102 = 0 ;
} else
V_104 . V_102 = F_6 ( V_102 ) ;
V_105 = sizeof( V_104 ) + V_100 ;
V_28 = F_18 ( V_19 , V_114 , V_101 , V_105 ) ;
if ( ! V_28 )
goto V_66;
V_28 -> V_15 . V_115 = F_7 ( V_28 , sizeof( V_104 ) , & V_104 ) ;
memcpy ( & V_28 -> V_99 , V_99 , sizeof( struct V_98 ) ) ;
V_66:
return V_28 ;
}
struct V_1 * F_28 ( const struct V_18 * V_19 )
{
struct V_1 * V_28 ;
struct V_116 V_117 ;
int V_12 ;
T_13 V_118 ;
T_4 V_119 , V_120 ;
struct V_121 * V_122 = (struct V_121 * ) & V_19 -> V_80 . V_123 ;
struct V_124 V_125 [ V_126 ] ;
memset ( V_125 , 0 , sizeof( V_125 ) ) ;
V_118 = F_29 ( V_122 ) ;
F_30 ( L_1 , V_118 ) ;
V_119 = F_31 ( V_122 , V_125 ) ;
V_120 = F_32 ( V_122 ) ;
V_117 . V_127 = F_13 ( V_118 ) ;
V_117 . V_44 = F_13 ( V_19 -> V_44 ) ;
V_117 . V_128 = F_6 ( V_119 ) ;
V_117 . V_120 = F_6 ( V_120 ) ;
V_12 = sizeof( V_117 )
+ sizeof( struct V_124 ) * V_119
+ sizeof( T_13 ) * V_120 ;
V_28 = F_18 ( V_19 , V_129 , 0 , V_12 ) ;
if ( ! V_28 )
goto V_66;
V_28 -> V_87 = V_19 -> V_80 . V_130 ;
V_28 -> V_15 . V_131 =
F_7 ( V_28 , sizeof( V_117 ) , & V_117 ) ;
if ( V_119 )
F_7 ( V_28 , sizeof( T_13 ) * V_119 ,
V_125 ) ;
if ( V_120 )
F_7 ( V_28 , sizeof( T_13 ) * V_120 ,
F_33 ( V_122 ) ) ;
V_66:
return V_28 ;
}
struct V_1 * F_34 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
struct V_1 * V_28 ;
T_16 V_132 ;
T_13 V_118 ;
V_118 = F_29 ( & V_19 -> V_80 . V_123 ) ;
V_132 . V_127 = F_13 ( V_118 ) ;
V_28 = F_18 ( V_19 , V_133 , 0 ,
sizeof( T_16 ) ) ;
if ( ! V_28 )
goto V_66;
V_28 -> V_15 . V_134 =
F_7 ( V_28 , sizeof( V_132 ) , & V_132 ) ;
if ( V_2 )
V_28 -> V_87 = V_2 -> V_87 ;
V_66:
return V_28 ;
}
struct V_1 * F_35 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
struct V_1 * V_28 ;
V_28 = F_18 ( V_19 , V_135 , 0 , 0 ) ;
if ( V_28 && V_2 )
V_28 -> V_87 = V_2 -> V_87 ;
return V_28 ;
}
struct V_1 * F_36 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
struct V_1 * V_28 ;
T_10 V_101 = 0 ;
V_101 |= V_19 ? 0 : V_136 ;
V_28 = F_18 ( V_19 , V_137 , V_101 , 0 ) ;
if ( V_28 && V_2 )
V_28 -> V_87 = V_2 -> V_87 ;
return V_28 ;
}
struct V_1 * F_37 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
const T_2 V_138 )
{
struct V_1 * V_28 ;
T_10 V_101 = 0 ;
if ( ! V_19 ) {
if ( V_2 && V_2 -> V_139 &&
V_2 -> V_139 -> type == V_65 )
V_101 = 0 ;
else
V_101 = V_136 ;
}
V_28 = F_18 ( V_19 , V_140 , V_101 , V_138 ) ;
if ( V_28 && V_2 )
V_28 -> V_87 = V_2 -> V_87 ;
return V_28 ;
}
struct V_1 * F_38 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 , T_13 V_106 )
{
struct V_1 * V_28 ;
T_17 V_141 ;
V_28 = F_37 ( V_19 , V_2 , sizeof( T_3 )
+ sizeof( V_106 ) ) ;
if ( ! V_28 )
goto V_142;
V_141 = F_13 ( V_106 ) ;
F_5 ( V_28 , V_143 , sizeof( V_141 ) ) ;
F_7 ( V_28 , sizeof( V_141 ) , ( const void * ) & V_141 ) ;
if ( V_2 )
V_28 -> V_87 = V_2 -> V_87 ;
V_142:
return V_28 ;
}
struct V_1 * F_39 ( const struct V_18 * V_19 ,
const struct V_144 * V_145 ,
T_2 V_10 )
{
struct V_1 * V_28 ;
void * V_141 = NULL ;
int V_11 ;
V_28 = F_37 ( V_19 , NULL , sizeof( T_3 ) + V_10 ) ;
if ( ! V_28 )
goto V_146;
if ( V_10 ) {
V_141 = F_40 ( V_10 , V_147 ) ;
if ( ! V_141 )
goto V_148;
V_11 = F_41 ( V_141 , V_145 -> V_149 , V_10 ) ;
if ( V_11 < 0 )
goto V_150;
}
F_5 ( V_28 , V_151 , V_10 ) ;
F_7 ( V_28 , V_10 , V_141 ) ;
if ( V_10 )
F_20 ( V_141 ) ;
return V_28 ;
V_150:
F_20 ( V_141 ) ;
V_148:
F_42 ( V_28 ) ;
V_28 = NULL ;
V_146:
return V_28 ;
}
static void * F_19 ( struct V_1 * V_2 , int V_12 ,
const void * V_152 )
{
void * V_153 ;
int V_154 = F_17 ( V_2 -> V_139 -> V_14 ) ;
V_153 = F_43 ( V_2 -> V_6 , V_12 ) ;
if ( V_152 )
memcpy ( V_153 , V_152 , V_12 ) ;
else
memset ( V_153 , 0 , V_12 ) ;
V_2 -> V_139 -> V_14 = F_6 ( V_154 + V_12 ) ;
V_2 -> V_155 = F_44 ( V_2 -> V_6 ) ;
return V_153 ;
}
struct V_1 * F_45 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
const T_10 * V_141 ,
const T_2 V_10 )
{
struct V_1 * V_28 ;
struct V_156 V_157 ;
V_28 = F_37 ( V_19 , V_2 , sizeof( T_3 ) + V_10
+ sizeof( T_11 ) ) ;
if ( ! V_28 )
goto V_158;
F_5 ( V_28 , V_159 , V_10
+ sizeof( T_11 ) ) ;
V_157 . type = F_6 ( V_2 -> V_139 -> type ) ;
V_157 . V_14 = V_2 -> V_139 -> V_14 ;
F_7 ( V_28 , V_10 , V_141 ) ;
F_19 ( V_28 , sizeof( T_11 ) , & V_157 ) ;
V_158:
return V_28 ;
}
struct V_1 * F_46 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
struct V_156 * V_160 )
{
struct V_1 * V_28 ;
static const char error [] = L_2 ;
T_2 V_161 = sizeof( error ) + sizeof( T_3 ) +
sizeof( T_11 ) ;
V_28 = F_37 ( V_19 , V_2 , V_161 ) ;
if ( ! V_28 )
goto V_66;
F_5 ( V_28 , V_159 ,
sizeof( error ) + sizeof( T_11 ) ) ;
F_7 ( V_28 , sizeof( error ) , error ) ;
F_19 ( V_28 , sizeof( T_11 ) , V_160 ) ;
V_66:
return V_28 ;
}
struct V_1 * F_47 ( const struct V_18 * V_19 ,
const struct V_162 * V_87 )
{
struct V_1 * V_28 ;
T_18 V_163 ;
V_28 = F_18 ( V_19 , V_164 , 0 , sizeof( V_163 ) ) ;
if ( ! V_28 )
goto V_66;
V_163 . V_68 . type = V_165 ;
V_163 . V_68 . V_14 = F_6 ( sizeof( T_18 ) ) ;
V_163 . V_166 = V_87 -> V_167 ;
V_163 . V_168 = V_169 ;
V_163 . V_170 = V_87 -> V_170 ;
V_28 -> V_87 = (struct V_162 * ) V_87 ;
V_28 -> V_15 . V_171 = F_7 ( V_28 , sizeof( V_163 ) ,
& V_163 ) ;
V_66:
return V_28 ;
}
struct V_1 * F_48 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
const void * V_141 , const T_2 V_10 )
{
struct V_1 * V_28 ;
V_28 = F_18 ( V_19 , V_172 , 0 , V_10 ) ;
if ( ! V_28 )
goto V_66;
V_28 -> V_15 . V_171 = F_7 ( V_28 , V_10 , V_141 ) ;
if ( V_2 )
V_28 -> V_87 = V_2 -> V_87 ;
V_66:
return V_28 ;
}
static struct V_1 * F_49 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
T_2 V_173 )
{
struct V_1 * V_28 ;
V_28 = F_18 ( V_19 , V_174 , 0 ,
sizeof( T_3 ) + V_173 ) ;
if ( ! V_28 )
goto V_66;
if ( V_2 )
V_28 -> V_87 = V_2 -> V_87 ;
V_66:
return V_28 ;
}
static inline struct V_1 * F_50 (
const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
T_2 V_173 = V_19 ? V_19 -> V_175 : 0 ;
if ( ! V_173 )
V_173 = V_176 ;
return F_49 ( V_19 , V_2 , V_173 ) ;
}
struct V_1 * F_51 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
T_1 V_9 , const void * V_141 ,
T_2 V_10 , T_2 V_177 )
{
struct V_1 * V_28 ;
V_28 = F_49 ( V_19 , V_2 , V_10 + V_177 ) ;
if ( ! V_28 )
goto V_66;
F_5 ( V_28 , V_9 , V_10 + V_177 ) ;
F_7 ( V_28 , V_10 , V_141 ) ;
if ( V_177 )
F_19 ( V_28 , V_177 , NULL ) ;
V_66:
return V_28 ;
}
struct V_1 * F_52 ( const struct V_18 * V_19 )
{
struct V_1 * V_28 ;
struct V_178 * V_179 ;
struct V_180 V_181 ;
T_10 * V_182 ;
V_179 = F_53 ( V_19 ) ;
if ( F_54 ( ! V_179 ) )
return NULL ;
V_28 = F_18 ( V_19 , V_64 , 0 ,
V_179 -> V_183 + sizeof( V_184 ) ) ;
if ( ! V_28 )
return NULL ;
V_181 . V_185 = F_6 ( V_179 -> V_185 ) ;
V_181 . V_186 = F_6 ( V_19 -> V_187 ) ;
V_28 -> V_15 . V_181 = F_7 ( V_28 , sizeof( V_184 ) ,
& V_181 ) ;
V_182 = F_43 ( V_28 -> V_6 , V_179 -> V_183 ) ;
memset ( V_182 , 0 , V_179 -> V_183 ) ;
V_28 -> V_139 -> V_14 =
F_6 ( F_17 ( V_28 -> V_139 -> V_14 ) + V_179 -> V_183 ) ;
V_28 -> V_155 = F_44 ( V_28 -> V_6 ) ;
return V_28 ;
}
struct V_1 * F_55 ( struct V_188 * V_6 ,
const struct V_18 * V_19 ,
struct V_189 * V_52 )
{
struct V_1 * V_28 ;
V_28 = F_56 ( V_190 , V_191 ) ;
if ( ! V_28 )
goto V_66;
if ( ! V_52 ) {
F_30 ( L_3 , V_6 ) ;
}
F_57 ( & V_28 -> V_192 ) ;
V_28 -> V_6 = V_6 ;
V_28 -> V_19 = (struct V_18 * ) V_19 ;
V_28 -> V_193 = 0 ;
V_28 -> V_194 = 0 ;
V_28 -> V_195 = 0 ;
V_28 -> V_168 = 0 ;
V_28 -> V_196 = 1 ;
V_28 -> V_197 = 0 ;
V_28 -> V_198 = 0 ;
V_28 -> V_199 = 0 ;
V_28 -> V_200 = 0 ;
V_28 -> V_201 = 0 ;
V_28 -> V_202 = V_203 ;
V_28 -> V_145 = NULL ;
F_57 ( & V_28 -> V_204 ) ;
F_57 ( & V_28 -> V_205 ) ;
F_58 ( V_2 ) ;
F_59 ( & V_28 -> V_206 , 1 ) ;
V_66:
return V_28 ;
}
void F_60 ( struct V_1 * V_2 , union V_207 * V_208 ,
union V_207 * V_209 )
{
memcpy ( & V_2 -> V_210 , V_208 , sizeof( union V_207 ) ) ;
memcpy ( & V_2 -> V_209 , V_209 , sizeof( union V_207 ) ) ;
}
const union V_207 * F_61 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_87 ) {
return & V_2 -> V_87 -> V_167 ;
} else {
return & V_2 -> V_210 ;
}
}
T_19
struct V_1 * F_18 ( const struct V_18 * V_19 ,
T_10 type , T_10 V_101 , int V_10 )
{
struct V_1 * V_28 ;
T_20 * V_139 ;
struct V_188 * V_6 ;
struct V_189 * V_52 ;
V_6 = F_62 ( F_15 ( sizeof( T_20 ) + V_10 ) ,
V_191 ) ;
if ( ! V_6 )
goto V_66;
V_139 = ( T_20 * ) F_43 ( V_6 , sizeof( T_20 ) ) ;
V_139 -> type = type ;
V_139 -> V_101 = V_101 ;
V_139 -> V_14 = F_6 ( sizeof( T_20 ) ) ;
V_52 = V_19 ? V_19 -> V_51 . V_52 : NULL ;
V_28 = F_55 ( V_6 , V_19 , V_52 ) ;
if ( ! V_28 ) {
F_63 ( V_6 ) ;
goto V_66;
}
V_28 -> V_139 = V_139 ;
V_28 -> V_155 = ( ( T_10 * ) V_139 ) + sizeof( struct V_211 ) ;
if ( F_64 ( type , V_19 ) )
V_28 -> V_212 = 1 ;
V_6 -> V_52 = V_52 ;
return V_28 ;
V_66:
return NULL ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_66 ( ! F_67 ( & V_2 -> V_192 ) ) ;
F_68 ( & V_2 -> V_204 ) ;
F_69 ( V_2 -> V_6 ) ;
F_70 ( V_2 ) ;
F_71 ( V_190 , V_2 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
if ( V_2 -> V_145 )
F_72 ( V_2 -> V_145 ) ;
F_73 ( V_2 ) ;
}
void F_74 ( struct V_1 * V_213 )
{
F_75 ( & V_213 -> V_206 ) ;
}
void F_73 ( struct V_1 * V_213 )
{
if ( F_76 ( & V_213 -> V_206 ) )
F_65 ( V_213 ) ;
}
void * F_7 ( struct V_1 * V_2 , int V_12 , const void * V_152 )
{
void * V_153 ;
void * V_214 ;
int V_154 = F_17 ( V_2 -> V_139 -> V_14 ) ;
int V_215 = F_15 ( V_154 ) - V_154 ;
V_214 = F_43 ( V_2 -> V_6 , V_215 ) ;
V_153 = F_43 ( V_2 -> V_6 , V_12 ) ;
memset ( V_214 , 0 , V_215 ) ;
memcpy ( V_153 , V_152 , V_12 ) ;
V_2 -> V_139 -> V_14 = F_6 ( V_154 + V_215 + V_12 ) ;
V_2 -> V_155 = F_44 ( V_2 -> V_6 ) ;
return V_153 ;
}
void * F_10 ( struct V_1 * V_2 ,
int V_12 , const void * V_152 )
{
if ( F_9 ( V_2 -> V_6 ) >= V_12 )
return F_7 ( V_2 , V_12 , V_152 ) ;
else
return NULL ;
}
int F_77 ( struct V_1 * V_2 , int V_216 , int V_12 ,
struct V_217 * V_152 )
{
T_10 * V_153 ;
int V_11 = 0 ;
V_153 = F_43 ( V_2 -> V_6 , V_12 ) ;
if ( ( V_11 = F_78 ( V_153 , V_152 , V_216 , V_12 ) ) )
goto V_218;
V_2 -> V_139 -> V_14 =
F_6 ( F_17 ( V_2 -> V_139 -> V_14 ) + V_12 ) ;
V_2 -> V_155 = F_44 ( V_2 -> V_6 ) ;
V_218:
return V_11 ;
}
void F_79 ( struct V_1 * V_2 )
{
struct V_219 * V_145 ;
struct V_1 * V_220 ;
struct V_221 * V_107 ;
T_4 V_102 ;
T_4 V_222 ;
if ( V_2 -> V_194 )
return;
V_222 = F_17 ( V_2 -> V_15 . V_115 -> V_107 ) ;
V_107 = & V_2 -> V_19 -> V_223 -> V_218 ;
V_145 = V_2 -> V_145 ;
F_80 (lchunk, &msg->chunks, frag_list) {
if ( V_220 -> V_139 -> V_101 & V_113 ) {
V_102 = 0 ;
} else {
if ( V_220 -> V_139 -> V_101 & V_224 )
V_102 = F_81 ( V_107 , V_222 ) ;
else
V_102 = F_82 ( V_107 , V_222 ) ;
}
V_220 -> V_15 . V_115 -> V_102 = F_6 ( V_102 ) ;
V_220 -> V_194 = 1 ;
}
}
void F_83 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_193 ) {
V_2 -> V_15 . V_115 -> V_106 =
F_13 ( F_84 ( V_2 -> V_19 ) ) ;
V_2 -> V_193 = 1 ;
}
}
struct V_18 * F_85 ( const struct V_225 * V_78 ,
struct V_1 * V_2 ,
T_5 V_22 )
{
struct V_18 * V_19 ;
struct V_188 * V_6 ;
T_21 V_226 ;
struct V_3 * V_4 ;
V_226 = F_86 ( F_61 ( V_2 ) ) ;
V_19 = F_87 ( V_78 , V_78 -> V_51 . V_52 , V_226 , V_22 ) ;
if ( ! V_19 )
goto V_66;
V_19 -> V_227 = 1 ;
V_6 = V_2 -> V_6 ;
V_4 = F_2 ( F_3 ( F_4 ( V_6 ) -> V_7 ) ) ;
if ( F_54 ( ! V_4 ) )
goto V_228;
V_4 -> V_229 ( & V_19 -> V_42 . V_230 , V_6 , 1 ) ;
V_66:
return V_19 ;
V_228:
F_88 ( V_19 ) ;
return NULL ;
}
static T_12 * F_22 ( const struct V_225 * V_78 ,
const struct V_18 * V_19 ,
const struct V_1 * V_231 ,
int * V_76 ,
const T_10 * V_232 , int V_30 )
{
T_12 * V_28 ;
struct V_233 * V_75 ;
struct V_234 V_235 ;
int V_236 , V_237 ;
unsigned int V_238 ;
char * V_239 ;
V_236 = sizeof( T_11 ) +
( sizeof( struct V_233 ) -
sizeof( struct V_240 ) ) ;
V_237 = sizeof( struct V_240 )
+ F_17 ( V_231 -> V_139 -> V_14 ) + V_30 ;
if ( V_237 % V_241 )
V_237 += V_241
- ( V_237 % V_241 ) ;
* V_76 = V_236 + V_237 ;
V_28 = F_89 ( * V_76 , V_191 ) ;
if ( ! V_28 )
goto V_66;
V_75 = (struct V_233 * ) V_28 -> V_242 ;
V_28 -> V_243 . type = V_244 ;
V_28 -> V_243 . V_14 = F_6 ( * V_76 ) ;
V_75 -> V_42 = V_19 -> V_42 ;
V_75 -> V_42 . V_245 = V_30 ;
V_75 -> V_42 . V_82 = V_19 -> V_80 . V_82 ;
V_75 -> V_42 . V_61 = V_19 -> V_80 . V_61 ;
F_90 ( & V_75 -> V_42 . V_246 ) ;
F_91 ( V_19 -> V_247 , V_75 -> V_42 . V_246 ) ;
memcpy ( & V_75 -> V_42 . V_248 [ 0 ] , V_231 -> V_139 ,
F_17 ( V_231 -> V_139 -> V_14 ) ) ;
memcpy ( ( T_10 * ) & V_75 -> V_42 . V_248 [ 0 ] +
F_17 ( V_231 -> V_139 -> V_14 ) , V_232 , V_30 ) ;
if ( F_14 ( V_78 -> V_51 . V_52 ) -> V_182 ) {
struct V_249 V_250 ;
F_92 ( & V_235 , & V_75 -> V_42 , V_237 ) ;
V_238 = V_251 ;
V_239 = ( char * ) V_78 -> V_252 [ V_78 -> V_253 ] ;
V_250 . V_254 = F_14 ( V_78 -> V_51 . V_52 ) -> V_182 ;
V_250 . V_101 = 0 ;
if ( F_93 ( V_250 . V_254 , V_239 , V_238 ) ||
F_94 ( & V_250 , & V_235 , V_237 , V_75 -> V_255 ) )
goto V_256;
}
return V_28 ;
V_256:
F_20 ( V_28 ) ;
V_66:
* V_76 = 0 ;
return NULL ;
}
struct V_18 * F_95 (
const struct V_225 * V_78 ,
const struct V_18 * V_19 ,
struct V_1 * V_2 , T_5 V_22 ,
int * error , struct V_1 * * V_257 )
{
struct V_18 * V_28 = NULL ;
struct V_233 * V_75 ;
struct V_240 * V_258 ;
int V_236 , V_237 , V_259 ;
T_10 * V_260 = V_78 -> V_260 ;
struct V_234 V_235 ;
unsigned int V_238 , V_12 ;
char * V_239 ;
T_21 V_226 ;
struct V_188 * V_6 = V_2 -> V_6 ;
struct V_261 V_262 ;
struct V_249 V_250 ;
V_236 = sizeof( T_20 ) +
( sizeof( struct V_233 ) -
sizeof( struct V_240 ) ) ;
V_237 = F_17 ( V_2 -> V_139 -> V_14 ) - V_236 ;
V_259 = V_236 + sizeof( struct V_240 ) ;
V_12 = F_17 ( V_2 -> V_139 -> V_14 ) ;
if ( V_12 < V_259 + sizeof( struct V_211 ) )
goto V_263;
if ( V_237 % V_241 )
goto V_263;
V_75 = V_2 -> V_15 . V_89 ;
V_258 = & V_75 -> V_42 ;
if ( ! F_14 ( V_78 -> V_51 . V_52 ) -> V_182 )
goto V_264;
V_238 = V_251 ;
F_92 ( & V_235 , V_258 , V_237 ) ;
V_239 = ( char * ) V_78 -> V_252 [ V_78 -> V_253 ] ;
V_250 . V_254 = F_14 ( V_78 -> V_51 . V_52 ) -> V_182 ;
V_250 . V_101 = 0 ;
memset ( V_260 , 0x00 , V_265 ) ;
if ( F_93 ( V_250 . V_254 , V_239 , V_238 ) ||
F_94 ( & V_250 , & V_235 , V_237 , V_260 ) ) {
* error = - V_266 ;
goto V_228;
}
if ( memcmp ( V_260 , V_75 -> V_255 , V_265 ) ) {
V_239 = ( char * ) V_78 -> V_252 [ V_78 -> V_267 ] ;
memset ( V_260 , 0x00 , V_265 ) ;
if ( F_93 ( V_250 . V_254 , V_239 , V_238 ) ||
F_94 ( & V_250 , & V_235 , V_237 , V_260 ) ) {
* error = - V_266 ;
goto V_228;
}
if ( memcmp ( V_260 , V_75 -> V_255 , V_265 ) ) {
* error = - V_268 ;
goto V_228;
}
}
V_264:
if ( F_96 ( V_2 -> V_269 -> V_270 ) != V_258 -> V_43 ) {
* error = - V_271 ;
goto V_228;
}
if ( V_2 -> V_269 -> V_210 != V_258 -> V_230 . V_272 . V_273 ||
F_17 ( V_2 -> V_269 -> V_209 ) != V_258 -> V_274 ) {
* error = - V_275 ;
goto V_228;
}
if ( F_97 ( V_78 -> V_51 . V_52 , V_276 ) )
F_98 ( V_6 , & V_262 ) ;
else
F_90 ( & V_262 ) ;
if ( ! V_19 && F_99 ( V_258 -> V_246 , V_262 ) ) {
V_12 = F_17 ( V_2 -> V_139 -> V_14 ) ;
* V_257 = F_49 ( V_19 , V_2 , V_12 ) ;
if ( * V_257 ) {
T_22 V_277 = ( V_262 . V_278 -
V_258 -> V_246 . V_278 ) * 1000000L +
V_262 . V_279 - V_258 -> V_246 . V_279 ;
T_17 V_280 = F_13 ( V_277 ) ;
F_5 ( * V_257 , V_281 ,
sizeof( V_280 ) ) ;
F_7 ( * V_257 , sizeof( V_280 ) , & V_280 ) ;
* error = - V_282 ;
} else
* error = - V_266 ;
goto V_228;
}
V_226 = F_86 ( F_61 ( V_2 ) ) ;
V_28 = F_87 ( V_78 , V_78 -> V_51 . V_52 , V_226 , V_22 ) ;
if ( ! V_28 ) {
* error = - V_266 ;
goto V_228;
}
V_28 -> V_80 . V_283 = F_17 ( V_2 -> V_269 -> V_210 ) ;
memcpy ( & V_28 -> V_42 , V_258 , sizeof( * V_258 ) ) ;
if ( F_100 ( V_28 , V_258 ,
V_191 ) < 0 ) {
* error = - V_266 ;
goto V_228;
}
if ( F_67 ( & V_28 -> V_51 . V_77 . V_284 ) ) {
F_101 ( & V_28 -> V_51 . V_77 , & V_2 -> V_209 ,
V_285 , V_191 ) ;
}
V_28 -> V_286 = V_28 -> V_42 . V_50 ;
V_28 -> V_287 = V_28 -> V_286 - 1 ;
V_28 -> V_288 = V_28 -> V_42 . V_50 ;
V_28 -> V_289 = V_28 -> V_287 ;
V_28 -> V_80 . V_82 = V_28 -> V_42 . V_82 ;
V_28 -> V_80 . V_61 = V_28 -> V_42 . V_61 ;
return V_28 ;
V_228:
if ( V_28 )
F_88 ( V_28 ) ;
return NULL ;
V_263:
* error = - V_290 ;
goto V_228;
}
static int F_102 ( const struct V_18 * V_19 ,
T_23 V_291 ,
struct V_1 * V_2 ,
struct V_1 * * V_257 )
{
struct V_292 V_293 ;
T_4 V_12 ;
V_12 = F_15 ( sizeof( V_293 ) ) ;
if ( ! * V_257 )
* V_257 = F_49 ( V_19 , V_2 , V_12 ) ;
if ( * V_257 ) {
V_293 . V_294 = F_13 ( 1 ) ;
V_293 . type = V_291 ;
F_5 ( * V_257 , V_295 ,
sizeof( V_293 ) ) ;
F_7 ( * V_257 , sizeof( V_293 ) , & V_293 ) ;
}
return 0 ;
}
static int F_103 ( const struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_1 * * V_257 )
{
if ( ! * V_257 )
* V_257 = F_49 ( V_19 , V_2 , 0 ) ;
if ( * V_257 )
F_5 ( * V_257 , V_296 , 0 ) ;
return 0 ;
}
static int F_104 ( const struct V_18 * V_19 ,
struct V_156 * V_160 ,
const struct V_1 * V_2 ,
struct V_1 * * V_257 )
{
if ( * V_257 )
F_42 ( * V_257 ) ;
* V_257 = F_46 ( V_19 , V_2 , V_160 ) ;
return 0 ;
}
static int F_105 ( const struct V_18 * V_19 ,
union V_25 V_160 ,
struct V_1 * V_2 ,
struct V_1 * * V_257 )
{
T_4 V_12 = F_17 ( V_160 . V_243 -> V_14 ) ;
if ( * V_257 )
F_42 ( * V_257 ) ;
* V_257 = F_49 ( V_19 , V_2 , V_12 ) ;
if ( * V_257 ) {
F_5 ( * V_257 , V_297 , V_12 ) ;
F_7 ( * V_257 , V_12 , V_160 . V_69 ) ;
}
return 0 ;
}
static int F_106 ( union V_25 V_160 )
{
T_4 V_37 = F_17 ( V_160 . V_243 -> V_14 ) - sizeof( T_11 ) ;
int V_298 = 0 ;
int V_299 = 0 ;
int V_300 ;
for ( V_300 = 0 ; V_300 < V_37 ; V_300 ++ ) {
switch ( V_160 . V_301 -> V_302 [ V_300 ] ) {
case V_64 :
V_298 = 1 ;
break;
case V_59 :
case V_60 :
V_299 = 1 ;
break;
}
}
if ( V_303 )
return 1 ;
if ( V_58 && ! V_298 && V_299 )
return 0 ;
return 1 ;
}
static void F_107 ( struct V_18 * V_19 ,
union V_25 V_160 )
{
T_4 V_37 = F_17 ( V_160 . V_243 -> V_14 ) - sizeof( T_11 ) ;
int V_300 ;
for ( V_300 = 0 ; V_300 < V_37 ; V_300 ++ ) {
switch ( V_160 . V_301 -> V_302 [ V_300 ] ) {
case V_304 :
if ( V_56 &&
! V_19 -> V_80 . V_82 )
V_19 -> V_80 . V_82 = 1 ;
break;
case V_64 :
if ( V_62 )
V_19 -> V_80 . V_84 = 1 ;
break;
case V_59 :
case V_60 :
if ( V_58 )
V_19 -> V_80 . V_83 = 1 ;
break;
default:
break;
}
}
}
static T_24 F_108 ( const struct V_18 * V_19 ,
union V_25 V_160 ,
struct V_1 * V_2 ,
struct V_1 * * V_257 )
{
int V_28 = V_305 ;
switch ( V_160 . V_243 -> type & V_306 ) {
case V_307 :
V_28 = V_308 ;
break;
case V_309 :
break;
case V_310 :
V_28 = V_308 ;
case V_311 :
if ( NULL == * V_257 )
* V_257 = F_50 ( V_19 , V_2 ) ;
if ( * V_257 ) {
if ( ! F_8 ( * V_257 , V_312 ,
F_15 ( F_17 ( V_160 . V_243 -> V_14 ) ) ) )
F_10 ( * V_257 ,
F_15 ( F_17 ( V_160 . V_243 -> V_14 ) ) ,
V_160 . V_69 ) ;
} else {
V_28 = V_266 ;
}
break;
default:
break;
}
return V_28 ;
}
static T_24 F_109 ( const struct V_18 * V_19 ,
union V_25 V_160 ,
T_25 V_313 ,
struct V_1 * V_2 ,
struct V_1 * * V_146 )
{
struct V_314 * V_315 ;
int V_28 = V_305 ;
T_4 V_316 , V_317 = 0 ;
int V_300 ;
switch ( V_160 . V_243 -> type ) {
case V_318 :
case V_319 :
case V_320 :
case V_70 :
case V_244 :
case V_165 :
case V_321 :
case V_322 :
case V_72 :
break;
case V_71 :
if ( ! F_106 ( V_160 ) )
return V_323 ;
break;
case V_324 :
if ( V_58 )
break;
goto V_325;
case V_326 :
F_105 ( V_19 , V_160 , V_2 , V_146 ) ;
V_28 = V_323 ;
break;
case V_327 :
if ( V_56 )
break;
goto V_325;
case V_328 :
if ( ! V_62 )
goto V_325;
if ( V_329 !=
F_17 ( V_160 . V_243 -> V_14 ) - sizeof( T_11 ) ) {
F_104 ( V_19 , V_160 . V_243 ,
V_2 , V_146 ) ;
V_28 = V_323 ;
}
break;
case V_330 :
if ( ! V_62 )
goto V_325;
if ( 260 < F_17 ( V_160 . V_243 -> V_14 ) ) {
F_104 ( V_19 , V_160 . V_243 ,
V_2 , V_146 ) ;
V_28 = V_323 ;
}
break;
case V_331 :
if ( ! V_62 )
goto V_325;
V_315 = (struct V_314 * ) V_160 . V_243 ;
V_316 = ( F_17 ( V_160 . V_243 -> V_14 ) - sizeof( T_11 ) ) >> 1 ;
for ( V_300 = 0 ; V_300 < V_316 ; V_300 ++ ) {
V_317 = F_17 ( V_315 -> V_332 [ V_300 ] ) ;
if ( V_317 == V_333 )
break;
}
if ( V_317 != V_333 ) {
F_104 ( V_19 , V_160 . V_243 , V_2 ,
V_146 ) ;
V_28 = V_323 ;
}
break;
V_325:
default:
F_30 ( L_4 ,
F_17 ( V_160 . V_243 -> type ) , V_313 ) ;
V_28 = F_108 ( V_19 , V_160 , V_2 , V_146 ) ;
break;
}
return V_28 ;
}
int F_110 ( const struct V_18 * V_19 ,
T_25 V_313 ,
T_26 * V_248 ,
struct V_1 * V_2 ,
struct V_1 * * V_257 )
{
union V_25 V_160 ;
int V_334 = 0 ;
int V_335 ;
if ( ( 0 == V_248 -> V_67 . V_46 ) ||
( 0 == V_248 -> V_67 . V_48 ) ||
( 0 == V_248 -> V_67 . V_41 ) ||
( V_336 > F_96 ( V_248 -> V_67 . V_44 ) ) ) {
return F_103 ( V_19 , V_2 , V_257 ) ;
}
F_111 (param, peer_init, init_hdr.params) {
if ( V_244 == V_160 . V_243 -> type )
V_334 = 1 ;
}
if ( V_160 . V_69 != ( void * ) V_2 -> V_155 )
return F_104 ( V_19 , V_160 . V_243 , V_2 , V_257 ) ;
if ( ( V_85 == V_313 ) && ! V_334 )
return F_102 ( V_19 , V_244 ,
V_2 , V_257 ) ;
F_111 (param, peer_init, init_hdr.params) {
V_335 = F_109 ( V_19 , V_160 , V_313 , V_2 , V_257 ) ;
switch ( V_335 ) {
case V_323 :
case V_266 :
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
int F_112 ( struct V_18 * V_19 , struct V_1 * V_2 ,
const union V_207 * V_230 ,
T_26 * V_248 , T_5 V_22 )
{
union V_25 V_160 ;
struct V_162 * V_87 ;
struct V_337 * V_338 , * V_227 ;
struct V_3 * V_4 ;
union V_207 V_339 ;
char * V_75 ;
int V_340 = 0 ;
if( ! F_113 ( V_19 , V_230 , V_22 , V_341 ) )
goto V_342;
if ( F_114 ( F_61 ( V_2 ) , V_230 ) )
V_340 = 1 ;
F_111 (param, peer_init, init_hdr.params) {
if ( ! V_340 && ( V_160 . V_243 -> type == V_318 ||
V_160 . V_243 -> type == V_319 ) ) {
V_4 = F_2 ( F_115 ( V_160 . V_243 -> type ) ) ;
V_4 -> V_343 ( & V_339 , V_160 . V_339 ,
V_2 -> V_269 -> V_210 , 0 ) ;
if ( F_114 ( F_61 ( V_2 ) , & V_339 ) )
V_340 = 1 ;
}
if ( ! F_116 ( V_19 , V_160 , V_230 , V_22 ) )
goto V_344;
}
if ( ! V_340 )
goto V_344;
if ( V_19 -> V_80 . V_84 && ( ! V_19 -> V_80 . V_345 ||
! V_19 -> V_80 . V_346 ) )
V_19 -> V_80 . V_84 = 0 ;
if ( ! V_303 &&
( V_19 -> V_80 . V_83 && ! V_19 -> V_80 . V_84 ) ) {
V_19 -> V_80 . V_347 |= ( V_348 |
V_349 |
V_324 ) ;
V_19 -> V_80 . V_83 = 0 ;
goto V_344;
}
F_117 (pos, temp, &asoc->peer.transport_addr_list) {
V_87 = F_118 ( V_338 , struct V_162 , V_350 ) ;
if ( V_87 -> V_351 == V_352 ) {
F_119 ( V_19 , V_87 ) ;
}
}
V_19 -> V_80 . V_300 . V_41 =
F_96 ( V_248 -> V_67 . V_41 ) ;
V_19 -> V_80 . V_300 . V_44 =
F_96 ( V_248 -> V_67 . V_44 ) ;
V_19 -> V_80 . V_300 . V_46 =
F_17 ( V_248 -> V_67 . V_46 ) ;
V_19 -> V_80 . V_300 . V_48 =
F_17 ( V_248 -> V_67 . V_48 ) ;
V_19 -> V_80 . V_300 . V_50 =
F_96 ( V_248 -> V_67 . V_50 ) ;
if ( V_19 -> V_42 . V_47 >
F_17 ( V_248 -> V_67 . V_48 ) ) {
V_19 -> V_42 . V_47 =
F_17 ( V_248 -> V_67 . V_48 ) ;
}
if ( V_19 -> V_42 . V_49 >
F_17 ( V_248 -> V_67 . V_46 ) ) {
V_19 -> V_42 . V_49 =
F_17 ( V_248 -> V_67 . V_46 ) ;
}
V_19 -> V_42 . V_353 = V_19 -> V_80 . V_300 . V_41 ;
V_19 -> V_80 . V_45 = V_19 -> V_80 . V_300 . V_44 ;
V_75 = V_19 -> V_80 . V_75 ;
if ( V_75 ) {
V_19 -> V_80 . V_75 = F_120 ( V_75 , V_19 -> V_80 . V_76 , V_22 ) ;
if ( ! V_19 -> V_80 . V_75 )
goto V_344;
}
F_80 (transport, &asoc->peer.transport_addr_list,
transports) {
V_87 -> V_354 = V_19 -> V_80 . V_300 . V_44 ;
}
if ( ! F_121 ( & V_19 -> V_80 . V_123 , V_355 ,
V_19 -> V_80 . V_300 . V_50 , V_22 ) )
goto V_344;
if ( ! V_19 -> V_227 ) {
int error ;
V_19 -> V_223 = F_122 ( V_19 -> V_42 . V_49 ,
V_19 -> V_42 . V_47 , V_22 ) ;
if ( ! V_19 -> V_223 )
goto V_344;
error = F_123 ( V_19 , V_22 ) ;
if ( error )
goto V_344;
}
V_19 -> V_80 . V_288 = V_19 -> V_80 . V_300 . V_50 - 1 ;
return 1 ;
V_344:
F_117 (pos, temp, &asoc->peer.transport_addr_list) {
V_87 = F_118 ( V_338 , struct V_162 , V_350 ) ;
if ( V_87 -> V_351 != V_341 )
F_119 ( V_19 , V_87 ) ;
}
V_342:
return 0 ;
}
static int F_116 ( struct V_18 * V_19 ,
union V_25 V_160 ,
const union V_207 * V_230 ,
T_5 V_22 )
{
union V_207 V_339 ;
int V_300 ;
T_4 V_33 ;
int V_28 = 1 ;
T_21 V_226 ;
T_27 V_356 ;
struct V_3 * V_4 ;
union V_357 * V_358 ;
struct V_162 * V_359 ;
switch ( V_160 . V_243 -> type ) {
case V_319 :
if ( V_360 != V_19 -> V_51 . V_52 -> V_361 )
break;
goto V_362;
case V_318 :
if ( F_124 ( V_19 -> V_51 . V_52 ) )
break;
V_362:
V_4 = F_2 ( F_115 ( V_160 . V_243 -> type ) ) ;
V_4 -> V_343 ( & V_339 , V_160 . V_339 , F_6 ( V_19 -> V_80 . V_283 ) , 0 ) ;
V_226 = F_86 ( V_230 ) ;
if ( F_125 ( & V_339 , V_226 ) )
if ( ! F_113 ( V_19 , & V_339 , V_22 , V_363 ) )
return 0 ;
break;
case V_320 :
if ( ! V_364 )
break;
V_356 = F_96 ( V_160 . V_365 -> V_366 ) ;
V_19 -> V_247 . V_278 += V_356 / 1000 ;
V_19 -> V_247 . V_279 += ( V_356 % 1000 ) * 1000 ;
break;
case V_326 :
F_30 ( L_5 ) ;
break;
case V_70 :
V_19 -> V_80 . V_367 = 0 ;
V_19 -> V_80 . V_368 = 0 ;
if ( V_230 -> V_369 . V_370 == V_371 )
V_19 -> V_80 . V_368 = 1 ;
else if ( V_230 -> V_369 . V_370 == V_372 )
V_19 -> V_80 . V_367 = 1 ;
V_33 = F_17 ( V_160 . V_243 -> V_14 ) - sizeof( T_11 ) ;
if ( V_33 )
V_33 /= sizeof( T_4 ) ;
for ( V_300 = 0 ; V_300 < V_33 ; ++ V_300 ) {
switch ( V_160 . V_33 -> V_34 [ V_300 ] ) {
case V_318 :
V_19 -> V_80 . V_367 = 1 ;
break;
case V_319 :
if ( V_360 == V_19 -> V_51 . V_52 -> V_361 )
V_19 -> V_80 . V_368 = 1 ;
break;
case V_326 :
V_19 -> V_80 . V_373 = 1 ;
break;
default:
break;
}
}
break;
case V_244 :
V_19 -> V_80 . V_76 =
F_17 ( V_160 . V_243 -> V_14 ) - sizeof( T_11 ) ;
V_19 -> V_80 . V_75 = V_160 . V_75 -> V_242 ;
break;
case V_165 :
break;
case V_321 :
break;
case V_322 :
V_19 -> V_80 . V_81 = 1 ;
break;
case V_72 :
V_19 -> V_80 . V_61 = F_96 ( V_160 . V_374 -> V_61 ) ;
break;
case V_324 :
if ( ! V_58 )
goto V_375;
V_358 = V_160 . V_69 + sizeof( V_376 ) ;
V_4 = F_2 ( F_115 ( V_160 . V_243 -> type ) ) ;
V_4 -> V_343 ( & V_339 , V_358 ,
F_6 ( V_19 -> V_80 . V_283 ) , 0 ) ;
if ( ! V_4 -> V_377 ( & V_339 , NULL , NULL ) )
break;
V_359 = F_126 ( V_19 , & V_339 ) ;
if ( ! V_359 )
break;
F_127 ( V_19 , V_359 ) ;
break;
case V_71 :
F_107 ( V_19 , V_160 ) ;
break;
case V_327 :
if ( V_56 ) {
V_19 -> V_80 . V_82 = 1 ;
break;
}
goto V_375;
case V_328 :
if ( ! V_62 )
goto V_375;
V_19 -> V_80 . V_345 = F_120 ( V_160 . V_243 ,
F_17 ( V_160 . V_243 -> V_14 ) , V_22 ) ;
if ( ! V_19 -> V_80 . V_345 ) {
V_28 = 0 ;
break;
}
break;
case V_331 :
if ( ! V_62 )
goto V_375;
V_19 -> V_80 . V_346 = F_120 ( V_160 . V_243 ,
F_17 ( V_160 . V_243 -> V_14 ) , V_22 ) ;
if ( ! V_19 -> V_80 . V_346 ) {
V_28 = 0 ;
break;
}
F_128 ( V_19 , V_160 . V_378 ) ;
break;
case V_330 :
if ( ! V_62 )
goto V_375;
V_19 -> V_80 . V_379 = F_120 ( V_160 . V_243 ,
F_17 ( V_160 . V_243 -> V_14 ) , V_22 ) ;
if ( ! V_19 -> V_80 . V_379 )
V_28 = 0 ;
break;
V_375:
default:
F_30 ( L_6 ,
F_17 ( V_160 . V_243 -> type ) , V_19 ) ;
break;
}
return V_28 ;
}
T_13 F_129 ( const struct V_225 * V_78 )
{
T_13 V_380 ;
do {
F_130 ( & V_380 , sizeof( T_13 ) ) ;
} while ( V_380 == 0 );
return V_380 ;
}
T_13 F_131 ( const struct V_225 * V_78 )
{
T_13 V_28 ;
F_130 ( & V_28 , sizeof( T_13 ) ) ;
return V_28 ;
}
static struct V_1 * F_132 ( struct V_18 * V_19 ,
union V_207 * V_339 ,
int V_23 )
{
T_28 V_381 ;
struct V_1 * V_28 ;
int V_14 = sizeof( V_381 ) + V_23 ;
union V_357 V_382 ;
int V_383 ;
struct V_3 * V_4 = F_2 ( V_339 -> V_272 . V_384 ) ;
V_383 = V_4 -> V_385 ( V_339 , & V_382 ) ;
if ( ! V_383 )
return NULL ;
V_14 += V_383 ;
V_28 = F_18 ( V_19 , V_59 , 0 , V_14 ) ;
if ( ! V_28 )
return NULL ;
V_381 . V_386 = F_13 ( V_19 -> V_288 ++ ) ;
V_28 -> V_15 . V_387 =
F_7 ( V_28 , sizeof( V_381 ) , & V_381 ) ;
V_28 -> V_68 . V_69 =
F_7 ( V_28 , V_383 , & V_382 ) ;
return V_28 ;
}
struct V_1 * F_133 ( struct V_18 * V_19 ,
union V_207 * V_388 ,
struct V_389 * V_26 ,
int V_390 ,
T_1 V_101 )
{
V_376 V_160 ;
struct V_1 * V_28 ;
union V_357 V_358 ;
union V_207 * V_339 ;
void * V_391 ;
struct V_3 * V_4 ;
int V_392 = sizeof( V_160 ) ;
int V_393 = 0 ;
int V_394 = 0 ;
int V_300 ;
V_391 = V_26 ;
for ( V_300 = 0 ; V_300 < V_390 ; V_300 ++ ) {
V_339 = (union V_207 * ) V_391 ;
V_4 = F_2 ( V_339 -> V_272 . V_384 ) ;
V_393 = V_4 -> V_385 ( V_339 , & V_358 ) ;
V_394 += V_392 ;
V_394 += V_393 ;
V_391 += V_4 -> V_395 ;
}
V_28 = F_132 ( V_19 , V_388 , V_394 ) ;
if ( ! V_28 )
return NULL ;
V_391 = V_26 ;
for ( V_300 = 0 ; V_300 < V_390 ; V_300 ++ ) {
V_339 = (union V_207 * ) V_391 ;
V_4 = F_2 ( V_339 -> V_272 . V_384 ) ;
V_393 = V_4 -> V_385 ( V_339 , & V_358 ) ;
V_160 . V_68 . type = V_101 ;
V_160 . V_68 . V_14 = F_6 ( V_392 + V_393 ) ;
V_160 . V_396 = V_300 ;
F_7 ( V_28 , V_392 , & V_160 ) ;
F_7 ( V_28 , V_393 , & V_358 ) ;
V_391 += V_4 -> V_395 ;
}
return V_28 ;
}
struct V_1 * F_134 ( struct V_18 * V_19 ,
union V_207 * V_339 )
{
V_376 V_160 ;
struct V_1 * V_28 ;
int V_12 = sizeof( V_160 ) ;
union V_357 V_382 ;
int V_383 ;
struct V_3 * V_4 = F_2 ( V_339 -> V_272 . V_384 ) ;
V_383 = V_4 -> V_385 ( V_339 , & V_382 ) ;
if ( ! V_383 )
return NULL ;
V_12 += V_383 ;
V_28 = F_132 ( V_19 , V_339 , V_12 ) ;
if ( ! V_28 )
return NULL ;
V_160 . V_68 . type = V_324 ;
V_160 . V_68 . V_14 = F_6 ( V_12 ) ;
V_160 . V_396 = 0 ;
F_7 ( V_28 , sizeof( V_160 ) , & V_160 ) ;
F_7 ( V_28 , V_383 , & V_382 ) ;
return V_28 ;
}
static struct V_1 * F_135 ( const struct V_18 * V_19 ,
T_13 V_386 , int V_23 )
{
T_28 V_381 ;
struct V_1 * V_28 ;
int V_14 = sizeof( V_381 ) + V_23 ;
V_28 = F_18 ( V_19 , V_60 , 0 , V_14 ) ;
if ( ! V_28 )
return NULL ;
V_381 . V_386 = F_13 ( V_386 ) ;
V_28 -> V_15 . V_387 =
F_7 ( V_28 , sizeof( V_381 ) , & V_381 ) ;
return V_28 ;
}
static void F_136 ( struct V_1 * V_2 , T_17 V_396 ,
T_1 V_397 , V_376 * V_398 )
{
V_376 V_399 ;
T_3 V_400 ;
int V_401 = 0 ;
int V_402 = 0 ;
T_1 V_403 ;
if ( V_404 == V_397 ) {
V_403 = V_405 ;
} else {
V_403 = V_406 ;
V_402 = sizeof( V_400 ) ;
if ( V_398 )
V_401 =
F_17 ( V_398 -> V_68 . V_14 ) ;
}
V_399 . V_68 . type = V_403 ;
V_399 . V_68 . V_14 = F_6 ( sizeof( V_399 ) +
V_402 +
V_401 ) ;
V_399 . V_396 = V_396 ;
F_7 ( V_2 , sizeof( V_399 ) , & V_399 ) ;
if ( V_404 == V_397 )
return;
V_400 . V_13 = V_397 ;
V_400 . V_14 = F_6 ( V_402 + V_401 ) ;
F_7 ( V_2 , V_402 , & V_400 ) ;
if ( V_398 )
F_7 ( V_2 , V_401 , V_398 ) ;
}
static T_1 F_137 ( struct V_18 * V_19 ,
struct V_1 * V_381 ,
V_376 * V_398 )
{
struct V_162 * V_80 ;
struct V_3 * V_4 ;
union V_207 V_339 ;
union V_357 * V_358 ;
V_358 = (union V_357 * )
( ( void * ) V_398 + sizeof( V_376 ) ) ;
if ( V_398 -> V_68 . type != V_348 &&
V_398 -> V_68 . type != V_349 &&
V_398 -> V_68 . type != V_324 )
return V_312 ;
switch ( V_358 -> V_243 . type ) {
case V_319 :
if ( ! V_19 -> V_80 . V_368 )
return V_297 ;
break;
case V_318 :
if ( ! V_19 -> V_80 . V_367 )
return V_297 ;
break;
default:
return V_297 ;
}
V_4 = F_2 ( F_115 ( V_358 -> V_243 . type ) ) ;
if ( F_54 ( ! V_4 ) )
return V_297 ;
V_4 -> V_343 ( & V_339 , V_358 , F_6 ( V_19 -> V_80 . V_283 ) , 0 ) ;
if ( ! V_4 -> V_407 ( & V_339 ) && ! V_4 -> V_377 ( & V_339 , NULL , V_381 -> V_6 ) )
return V_297 ;
switch ( V_398 -> V_68 . type ) {
case V_348 :
if ( V_4 -> V_407 ( & V_339 ) )
memcpy ( & V_339 , & V_381 -> V_210 , sizeof( V_339 ) ) ;
V_80 = F_113 ( V_19 , & V_339 , V_191 , V_363 ) ;
if ( ! V_80 )
return V_408 ;
if ( ! F_138 ( & V_80 -> V_409 , F_139 ( V_80 ) ) )
F_140 ( V_80 ) ;
break;
case V_349 :
if ( V_19 -> V_80 . V_410 == 1 )
return V_411 ;
if ( F_114 ( F_61 ( V_381 ) , & V_339 ) )
return V_412 ;
if ( V_4 -> V_407 ( & V_339 ) ) {
F_127 ( V_19 , V_381 -> V_87 ) ;
F_141 ( V_19 ,
V_381 -> V_87 ) ;
} else
F_142 ( V_19 , & V_339 ) ;
break;
case V_324 :
if ( V_4 -> V_407 ( & V_339 ) )
memcpy ( & V_339 . V_272 , F_61 ( V_381 ) , sizeof( V_339 ) ) ;
V_80 = F_126 ( V_19 , & V_339 ) ;
if ( ! V_80 )
return V_297 ;
F_127 ( V_19 , V_80 ) ;
break;
}
return V_404 ;
}
int F_143 ( const struct V_18 * V_19 ,
struct V_156 * V_68 , void * V_155 ,
struct V_156 * * V_257 ) {
V_376 * V_398 ;
union V_25 V_160 ;
int V_14 , V_413 ;
V_160 . V_69 = ( T_11 * ) V_68 ;
while ( V_160 . V_69 <= V_155 - sizeof( T_11 ) ) {
V_14 = F_17 ( V_160 . V_243 -> V_14 ) ;
* V_257 = V_160 . V_243 ;
if ( V_160 . V_69 > V_155 - V_14 ||
V_14 < sizeof( T_11 ) )
return 0 ;
switch ( V_160 . V_243 -> type ) {
case V_348 :
case V_349 :
case V_324 :
V_398 = ( V_376 * ) V_160 . V_69 ;
V_413 = F_17 ( V_398 -> V_68 . V_14 ) ;
if ( V_413 < sizeof( V_376 ) +
sizeof( T_11 ) )
return 0 ;
break;
case V_405 :
case V_72 :
if ( V_14 != sizeof( V_376 ) )
return 0 ;
break;
default:
break;
}
V_160 . V_69 += F_15 ( V_14 ) ;
}
if ( V_160 . V_69 != V_155 )
return 0 ;
return 1 ;
}
struct V_1 * F_144 ( struct V_18 * V_19 ,
struct V_1 * V_381 )
{
T_28 * V_414 ;
union V_357 * V_358 ;
V_376 * V_398 ;
struct V_1 * V_415 ;
T_1 V_397 ;
int V_14 = 0 ;
int V_105 ;
T_13 V_386 ;
int V_416 = 1 ;
V_105 = F_17 ( V_381 -> V_139 -> V_14 ) - sizeof( T_20 ) ;
V_414 = ( T_28 * ) V_381 -> V_6 -> V_152 ;
V_386 = F_96 ( V_414 -> V_386 ) ;
V_14 = sizeof( T_28 ) ;
V_358 = (union V_357 * ) ( V_381 -> V_6 -> V_152 + V_14 ) ;
V_105 -= V_14 ;
V_14 = F_17 ( V_358 -> V_243 . V_14 ) ;
V_398 = ( V_376 * ) ( ( void * ) V_358 + V_14 ) ;
V_105 -= V_14 ;
V_415 = F_135 ( V_19 , V_386 , V_105 * 4 ) ;
if ( ! V_415 )
goto V_417;
while ( V_105 > 0 ) {
V_397 = F_137 ( V_19 , V_381 ,
V_398 ) ;
if ( V_404 != V_397 )
V_416 = 0 ;
if ( ! V_416 )
F_136 ( V_415 ,
V_398 -> V_396 , V_397 ,
V_398 ) ;
if ( V_408 == V_397 )
goto V_417;
V_14 = F_17 ( V_398 -> V_68 . V_14 ) ;
V_398 = ( V_376 * ) ( ( void * ) V_398 +
V_14 ) ;
V_105 -= V_14 ;
}
V_417:
V_19 -> V_80 . V_288 ++ ;
if ( V_415 ) {
F_74 ( V_415 ) ;
F_145 ( & V_415 -> V_204 ,
& V_19 -> V_418 ) ;
}
return V_415 ;
}
static void F_146 ( struct V_18 * V_19 ,
V_376 * V_398 )
{
struct V_3 * V_4 ;
union V_207 V_339 ;
struct V_20 * V_21 = & V_19 -> V_51 . V_77 ;
union V_357 * V_358 ;
struct V_162 * V_87 ;
struct V_419 * V_420 ;
V_358 = (union V_357 * )
( ( void * ) V_398 + sizeof( V_376 ) ) ;
V_4 = F_2 ( F_115 ( V_358 -> V_243 . type ) ) ;
V_4 -> V_343 ( & V_339 , V_358 , F_6 ( V_21 -> V_283 ) , 0 ) ;
switch ( V_398 -> V_68 . type ) {
case V_348 :
F_147 () ;
F_80 (saddr, &bp->address_list, list) {
if ( F_114 ( & V_420 -> V_421 , & V_339 ) )
V_420 -> V_351 = V_285 ;
}
F_148 () ;
F_80 (transport, &asoc->peer.transport_addr_list,
transports) {
F_149 ( V_87 -> V_422 ) ;
V_87 -> V_422 = NULL ;
}
break;
case V_349 :
F_147 () ;
F_150 ( V_21 , & V_339 ) ;
F_148 () ;
F_80 (transport, &asoc->peer.transport_addr_list,
transports) {
F_149 ( V_87 -> V_422 ) ;
V_87 -> V_422 = NULL ;
}
break;
default:
break;
}
}
static T_1 F_151 ( struct V_1 * V_415 ,
V_376 * V_398 ,
int V_423 )
{
V_376 * V_424 ;
T_3 * V_400 ;
int V_14 ;
int V_425 ;
T_1 V_397 ;
if ( V_423 )
V_397 = V_404 ;
else
V_397 = V_426 ;
V_425 = F_17 ( V_415 -> V_139 -> V_14 ) -
sizeof( T_20 ) ;
V_14 = sizeof( T_28 ) ;
V_424 = ( V_376 * ) ( V_415 -> V_6 -> V_152 +
V_14 ) ;
V_425 -= V_14 ;
while ( V_425 > 0 ) {
if ( V_424 -> V_396 == V_398 -> V_396 ) {
switch( V_424 -> V_68 . type ) {
case V_405 :
return V_404 ;
case V_406 :
V_14 = sizeof( V_376 ) ;
V_400 = ( T_3 * )
( ( void * ) V_424 + V_14 ) ;
V_425 -= V_14 ;
if ( V_425 > 0 )
return V_400 -> V_13 ;
else
return V_296 ;
break;
default:
return V_296 ;
}
}
V_14 = F_17 ( V_424 -> V_68 . V_14 ) ;
V_424 = ( V_376 * )
( ( void * ) V_424 + V_14 ) ;
V_425 -= V_14 ;
}
return V_397 ;
}
int F_152 ( struct V_18 * V_19 ,
struct V_1 * V_415 )
{
struct V_1 * V_381 = V_19 -> V_427 ;
union V_357 * V_358 ;
V_376 * V_398 ;
int V_14 = 0 ;
int V_428 = V_381 -> V_6 -> V_12 ;
int V_416 = 0 ;
int V_423 = 1 ;
int V_28 = 0 ;
T_1 V_397 = V_404 ;
V_14 = sizeof( V_429 ) ;
V_358 = (union V_357 * ) ( V_381 -> V_6 -> V_152 + V_14 ) ;
V_428 -= V_14 ;
V_14 = F_17 ( V_358 -> V_243 . V_14 ) ;
V_398 = ( V_376 * ) ( ( void * ) V_358 + V_14 ) ;
V_428 -= V_14 ;
if ( V_415 -> V_6 -> V_12 == sizeof( T_28 ) )
V_416 = 1 ;
while ( V_428 > 0 ) {
if ( V_416 )
V_397 = V_404 ;
else {
V_397 = F_151 ( V_415 ,
V_398 ,
V_423 ) ;
if ( V_423 && ( V_404 != V_397 ) )
V_423 = 0 ;
}
switch ( V_397 ) {
case V_404 :
F_146 ( V_19 , V_398 ) ;
break;
case V_408 :
V_28 = 1 ;
break;
case V_312 :
V_19 -> V_80 . V_347 |=
V_398 -> V_68 . type ;
break;
case V_426 :
case V_411 :
case V_412 :
default:
break;
}
V_14 = F_17 ( V_398 -> V_68 . V_14 ) ;
V_398 = ( V_376 * ) ( ( void * ) V_398 +
V_14 ) ;
V_428 -= V_14 ;
}
F_68 ( & V_381 -> V_204 ) ;
F_42 ( V_381 ) ;
V_19 -> V_427 = NULL ;
return V_28 ;
}
struct V_1 * F_153 ( const struct V_18 * V_19 ,
T_13 V_430 , T_2 V_431 ,
struct V_432 * V_433 )
{
struct V_1 * V_28 = NULL ;
struct V_434 V_435 ;
struct V_432 V_436 ;
T_2 V_138 ;
int V_300 ;
V_138 = ( V_431 + 1 ) * sizeof( T_13 ) ;
V_28 = F_18 ( V_19 , V_304 , 0 , V_138 ) ;
if ( ! V_28 )
return NULL ;
V_435 . V_430 = F_13 ( V_430 ) ;
V_28 -> V_15 . V_437 =
F_7 ( V_28 , sizeof( V_435 ) , & V_435 ) ;
for ( V_300 = 0 ; V_300 < V_431 ; V_300 ++ ) {
V_436 . V_107 = V_433 [ V_300 ] . V_107 ;
V_436 . V_102 = V_433 [ V_300 ] . V_102 ;
F_7 ( V_28 , sizeof( V_436 ) , & V_436 ) ;
}
return V_28 ;
}

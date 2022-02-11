static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline T_2 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
F_6 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_3 , T_3 V_5 )
{
F_8 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_5 )
{
F_10 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline int F_11 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
do {
if ( F_1 ( V_2 , V_7 ) == V_8 )
return 0 ;
F_12 ( 1 ) ;
} while ( V_6 ++ < V_9 );
F_13 ( & V_2 -> V_10 -> V_11 , L_1 ,
F_1 ( V_2 , V_7 ) ) ;
return - V_12 ;
}
static inline int F_14 ( struct V_1 * V_2 , int V_13 )
{
T_1 V_14 ;
while ( V_13 > 0 ) {
V_14 = F_1 ( V_2 , V_15 ) ;
if ( V_14 )
break;
V_13 -- ;
F_12 ( 1 ) ;
}
if ( V_13 <= 0 ) {
F_13 ( & V_2 -> V_10 -> V_11 , L_2 ) ;
return - V_12 ;
}
if ( V_14 != V_16 ) {
F_13 ( & V_2 -> V_10 -> V_11 , L_3 ,
V_14 , F_1 ( V_2 , V_17 ) ) ;
return - V_18 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_19 , T_1 V_11 , T_1 V_20 ,
T_1 V_21 , T_4 V_22 , int V_13 )
{
int V_23 = 0 ;
F_5 ( V_2 , V_15 , V_24 ) ;
if ( F_11 ( V_2 ) )
return - V_12 ;
V_11 |= V_25 ;
F_5 ( V_2 , V_26 , V_11 ) ;
F_5 ( V_2 , V_27 , V_20 ) ;
F_5 ( V_2 , V_28 , V_21 ) ;
if ( V_22 )
F_9 ( V_2 , V_29 , V_22 ) ;
F_5 ( V_2 , V_15 , V_24 ) ;
F_5 ( V_2 , V_7 , V_19 ) ;
if ( V_13 )
V_23 = F_14 ( V_2 , V_13 ) ;
if ( V_19 != V_30 )
F_5 ( V_2 , V_15 , V_24 ) ;
return V_23 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
if ( F_15 ( V_2 , V_33 , 0 , 0 , 0 , 0 ,
V_34 ) )
F_17 ( & V_2 -> V_10 -> V_11 , L_4 ) ;
F_5 ( V_2 , V_35 , 0 ) ;
F_18 (scb, &wd->active_scbs, list)
F_19 ( V_2 -> V_10 , sizeof( struct V_31 ) , V_32 ,
V_32 -> V_36 ) ;
F_18 (scb, &wd->free_scbs, list)
F_19 ( V_2 -> V_10 , sizeof( struct V_31 ) , V_32 ,
V_32 -> V_36 ) ;
F_19 ( V_2 -> V_10 , V_2 -> V_37 , V_2 -> V_38 , V_2 -> V_39 ) ;
V_2 -> V_38 = NULL ;
F_19 ( V_2 -> V_10 , V_40 , V_2 -> V_41 ,
V_2 -> V_42 ) ;
V_2 -> V_41 = NULL ;
F_19 ( V_2 -> V_10 , sizeof( struct V_43 ) ,
V_2 -> V_44 , V_2 -> V_45 ) ;
V_2 -> V_44 = NULL ;
F_20 ( V_2 -> V_10 -> V_46 , V_2 ) ;
}
static void F_21 ( struct V_47 * V_48 , int V_49 )
{
struct V_1 * V_2 = F_22 ( V_48 -> V_50 -> V_51 ) ;
struct V_31 * V_32 = (struct V_31 * ) V_48 -> V_52 ;
if ( V_32 ) {
F_23 ( & V_32 -> V_53 , & V_2 -> V_54 ) ;
F_24 ( & V_2 -> V_10 -> V_11 , V_48 -> V_55 . V_56 ,
V_57 , V_58 ) ;
F_25 ( V_48 ) ;
}
V_48 -> V_49 = V_49 << 16 ;
V_48 -> V_59 ( V_48 ) ;
}
static int F_26 ( struct V_60 * V_61 , struct V_47 * V_48 )
{
int V_6 , V_62 ;
unsigned long V_63 ;
struct V_31 * V_32 ;
struct V_1 * V_2 = F_22 ( V_61 ) ;
T_4 V_36 ;
V_48 -> V_52 = NULL ;
F_27 ( V_2 -> V_61 -> V_64 , V_63 ) ;
V_32 = F_28 ( & V_2 -> V_54 , struct V_31 , V_53 ) ;
if ( V_32 ) {
F_29 ( & V_32 -> V_53 ) ;
V_36 = V_32 -> V_36 ;
} else {
F_30 ( V_2 -> V_61 -> V_64 , V_63 ) ;
V_32 = F_31 ( V_2 -> V_10 , sizeof( struct V_31 ) ,
& V_36 ) ;
F_27 ( V_2 -> V_61 -> V_64 , V_63 ) ;
if ( ! V_32 ) {
F_13 ( & V_2 -> V_10 -> V_11 , L_5 ) ;
F_21 ( V_48 , V_65 ) ;
F_30 ( V_2 -> V_61 -> V_64 , V_63 ) ;
return 0 ;
}
}
memset ( V_32 , 0 , sizeof( struct V_31 ) ) ;
F_32 ( & V_32 -> V_53 , & V_2 -> V_66 ) ;
V_32 -> V_36 = V_36 ;
V_32 -> V_48 = V_48 ;
V_48 -> V_52 = ( char * ) V_32 ;
V_32 -> V_67 = 0 ;
V_32 -> V_68 = V_48 -> V_50 -> V_69 ;
V_32 -> V_20 = V_48 -> V_50 -> V_20 ;
memcpy ( V_32 -> V_70 , V_48 -> V_71 , V_48 -> V_72 ) ;
V_32 -> V_73 = V_57 ;
V_48 -> V_55 . V_56 = F_33 ( & V_2 -> V_10 -> V_11 , V_48 -> V_74 ,
V_57 , V_58 ) ;
V_32 -> V_75 = F_34 ( V_48 -> V_55 . V_56 ) ;
V_32 -> V_76 |= V_77 ;
if ( V_48 -> V_78 == V_79 )
V_32 -> V_76 |= V_80
| V_81 ;
else if ( V_48 -> V_78 == V_58 )
V_32 -> V_76 |= V_80 ;
V_62 = F_35 ( V_48 ) ;
if ( V_62 < 0 ) {
F_21 ( V_48 , V_65 ) ;
F_30 ( V_2 -> V_61 -> V_64 , V_63 ) ;
return 0 ;
}
F_36 ( V_62 > V_82 ) ;
if ( V_62 ) {
struct V_83 * V_84 ;
V_32 -> V_85 = F_34 ( V_62 *
sizeof( struct V_86 ) ) ;
V_32 -> V_87 = F_34 ( V_32 -> V_36 +
F_37 ( struct V_31 , V_88 ) ) ;
F_38 (cmd, sg, count_sg, i) {
V_32 -> V_88 [ V_6 ] . V_89 = F_34 ( F_39 ( V_84 ) ) ;
V_32 -> V_88 [ V_6 ] . V_90 = F_34 ( F_40 ( V_84 ) ) ;
}
V_32 -> V_76 |= V_91 ;
} else {
V_32 -> V_85 = 0 ;
V_32 -> V_87 = 0 ;
}
if ( F_1 ( V_2 , V_7 ) != V_8 ) {
F_30 ( V_2 -> V_61 -> V_64 , V_63 ) ;
return V_92 ;
}
F_9 ( V_2 , V_29 , V_32 -> V_36 ) ;
F_5 ( V_2 , V_7 , V_93 ) ;
F_30 ( V_2 -> V_61 -> V_64 , V_63 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_6 , V_23 ;
T_2 V_94 [ 3 ] ;
const struct V_95 * V_96 , * V_97 ;
const char V_98 [] = L_6 ;
const char V_99 [] = L_7 ;
memset ( V_2 -> V_41 , 0 , V_40 ) ;
V_23 = F_42 ( & V_96 , V_98 , & V_2 -> V_10 -> V_11 ) ;
if ( V_23 ) {
F_13 ( & V_2 -> V_10 -> V_11 , L_8 ,
V_98 , V_23 ) ;
return V_23 ;
}
V_23 = F_42 ( & V_97 , V_99 , & V_2 -> V_10 -> V_11 ) ;
if ( V_23 ) {
F_13 ( & V_2 -> V_10 -> V_11 , L_8 ,
V_99 , V_23 ) ;
F_43 ( V_96 ) ;
return V_23 ;
}
V_2 -> V_37 = F_44 ( V_96 -> V_100 , 4 ) + V_97 -> V_100 ;
if ( ! V_2 -> V_38 )
V_2 -> V_38 = F_31 ( V_2 -> V_10 , V_2 -> V_37 ,
& V_2 -> V_39 ) ;
if ( ! V_2 -> V_38 ) {
V_23 = - V_101 ;
goto V_102;
}
memcpy ( V_2 -> V_38 , V_96 -> V_22 , V_96 -> V_100 ) ;
memcpy ( V_2 -> V_38 + F_44 ( V_96 -> V_100 , 4 ) , V_97 -> V_22 ,
V_97 -> V_100 ) ;
F_5 ( V_2 , V_103 , V_104 ) ;
F_12 ( V_34 ) ;
F_5 ( V_2 , V_26 , 0 ) ;
F_5 ( V_2 , V_35 , 0 ) ;
F_5 ( V_2 , V_7 , 0 ) ;
if ( F_11 ( V_2 ) ) {
V_23 = - V_12 ;
goto V_102;
}
V_94 [ 0 ] = V_2 -> V_39 ;
V_94 [ 1 ] = V_2 -> V_39 + F_44 ( V_96 -> V_100 , 4 ) ;
V_94 [ 2 ] = V_2 -> V_42 ;
F_5 ( V_2 , V_105 , 0 ) ;
F_9 ( V_2 , V_106 , V_94 [ 1 ] ) ;
F_7 ( V_2 , V_107 , V_108 ) ;
F_7 ( V_2 , V_109 , 2048 * 2 ) ;
F_5 ( V_2 , V_110 , V_111 ) ;
V_6 = V_34 ;
while ( V_6 -- > 0 ) {
T_1 V_14 = F_1 ( V_2 , V_105 ) ;
if ( V_14 == V_112 )
break;
if ( V_14 == V_113 ) {
F_17 ( & V_2 -> V_10 -> V_11 , L_9 ) ;
V_23 = - V_18 ;
goto V_102;
}
F_12 ( 1 ) ;
}
if ( V_6 < 1 ) {
F_17 ( & V_2 -> V_10 -> V_11 , L_10 ) ;
V_23 = - V_12 ;
goto V_102;
}
F_9 ( V_2 , V_29 , V_94 [ 0 ] ) ;
F_9 ( V_2 , V_29 + 4 , V_94 [ 1 ] ) ;
F_9 ( V_2 , V_29 + 8 , V_94 [ 2 ] ) ;
F_5 ( V_2 , V_26 , V_25 ) ;
F_5 ( V_2 , V_7 , V_114 ) ;
F_5 ( V_2 , V_35 , V_115 ) ;
F_12 ( V_34 ) ;
V_23 = F_14 ( V_2 , V_34 ) ;
F_5 ( V_2 , V_15 , V_24 ) ;
if ( V_23 ) {
F_17 ( & V_2 -> V_10 -> V_11 , L_11 ) ;
goto V_102;
}
V_23 = F_15 ( V_2 , V_30 , 0 , 0 , 0 , 0 ,
V_34 ) ;
if ( V_23 ) {
F_17 ( & V_2 -> V_10 -> V_11 , L_12 ) ;
goto V_102;
}
F_45 ( & V_2 -> V_10 -> V_11 , L_13 ,
F_1 ( V_2 , V_116 + 1 ) ,
F_1 ( V_2 , V_116 ) ) ;
V_23 = F_15 ( V_2 , V_117 , 0 , 0 , 0 , 0 ,
V_118 ) ;
if ( V_23 ) {
F_17 ( & V_2 -> V_10 -> V_11 , L_14 ) ;
goto V_102;
}
V_23 = F_15 ( V_2 , V_119 , 0 ,
sizeof( struct V_43 ) , 0 ,
V_2 -> V_45 , V_34 ) ;
if ( V_23 ) {
F_17 ( & V_2 -> V_10 -> V_11 , L_15 ) ;
goto V_102;
}
V_23 = F_15 ( V_2 , V_120 , 0 , 0 , 0 , 0 ,
V_118 ) ;
if ( V_23 ) {
F_17 ( & V_2 -> V_10 -> V_11 , L_16 ) ;
goto V_102;
}
F_5 ( V_2 , V_121 , 0 ) ;
V_102:
F_43 ( V_96 ) ;
F_43 ( V_97 ) ;
return V_23 ;
}
static int F_46 ( struct V_47 * V_48 )
{
int V_122 , V_49 ;
unsigned long V_63 ;
struct V_31 * V_32 = (struct V_31 * ) V_48 -> V_52 ;
struct V_1 * V_2 = F_22 ( V_48 -> V_50 -> V_51 ) ;
F_45 ( & V_2 -> V_10 -> V_11 , L_17 , V_48 -> V_21 ) ;
V_122 = V_123 ;
F_27 ( V_2 -> V_61 -> V_64 , V_63 ) ;
V_49 = F_15 ( V_2 , V_122 , V_48 -> V_50 -> V_69 ,
V_48 -> V_50 -> V_20 , V_48 -> V_21 , V_32 -> V_36 , 0 ) ;
F_30 ( V_2 -> V_61 -> V_64 , V_63 ) ;
if ( V_49 )
return V_124 ;
return V_125 ;
}
static int F_47 ( struct V_47 * V_48 , T_1 V_19 , T_1 V_50 )
{
int V_49 ;
unsigned long V_63 ;
struct V_1 * V_2 = F_22 ( V_48 -> V_50 -> V_51 ) ;
F_45 ( & V_2 -> V_10 -> V_11 , L_18 ,
( V_19 == V_117 ) ? L_19 : L_20 ) ;
F_27 ( V_2 -> V_61 -> V_64 , V_63 ) ;
V_49 = F_15 ( V_2 , V_19 , V_50 , 0 , 0 , 0 ,
V_118 ) ;
F_30 ( V_2 -> V_61 -> V_64 , V_63 ) ;
if ( V_49 )
return V_124 ;
return V_125 ;
}
static int F_48 ( struct V_47 * V_48 )
{
return F_47 ( V_48 , V_126 , V_48 -> V_50 -> V_69 ) ;
}
static int F_49 ( struct V_47 * V_48 )
{
return F_47 ( V_48 , V_117 , 0 ) ;
}
static int F_50 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_22 ( V_48 -> V_50 -> V_51 ) ;
struct V_31 * V_32 , * V_127 ;
unsigned long V_63 ;
int V_49 ;
F_45 ( & V_2 -> V_10 -> V_11 , L_21 ) ;
F_27 ( V_2 -> V_61 -> V_64 , V_63 ) ;
if ( F_41 ( V_2 ) == 0 )
V_49 = V_125 ;
else
V_49 = V_124 ;
F_51 (scb, tmp, &wd->active_scbs, list) {
struct V_47 * V_128 = V_32 -> V_48 ;
F_21 ( V_128 , V_49 ) ;
}
F_30 ( V_2 -> V_61 -> V_64 , V_63 ) ;
return V_49 ;
}
static int F_52 ( struct V_129 * V_130 , struct V_131 * V_132 ,
T_5 V_133 , int V_134 [] )
{
if ( V_133 >= 0x200000 ) {
V_134 [ 0 ] = 255 ;
V_134 [ 1 ] = 63 ;
} else {
V_134 [ 0 ] = 64 ;
V_134 [ 1 ] = 32 ;
}
V_134 [ 2 ] = F_53 ( V_133 , V_134 [ 0 ] * V_134 [ 1 ] ) ;
return 0 ;
}
static inline void F_54 ( struct V_1 * V_2 ,
union V_135 V_136 ,
struct V_31 * V_32 )
{
struct V_47 * V_48 ;
int V_49 ;
switch ( V_136 . V_137 . V_138 ) {
case V_139 :
V_49 = V_140 ;
break;
case V_141 :
F_13 ( & V_2 -> V_10 -> V_11 , L_22 ) ;
V_49 = V_65 ;
break;
case V_142 :
F_13 ( & V_2 -> V_10 -> V_11 , L_23 ) ;
V_49 = V_65 ;
break;
case V_143 :
F_55 ( & V_2 -> V_10 -> V_11 , L_24 ) ;
V_49 = V_144 ;
break;
case V_145 :
case V_146 :
V_49 = V_144 ;
F_13 ( & V_2 -> V_10 -> V_11 , L_25 ) ;
break;
case V_147 :
case V_148 :
V_49 = V_149 ;
F_13 ( & V_2 -> V_10 -> V_11 , L_26 ) ;
break;
case V_150 :
V_49 = V_151 ;
F_55 ( & V_2 -> V_10 -> V_11 , L_27 ) ;
break;
case V_152 :
F_55 ( & V_2 -> V_10 -> V_11 , L_28 ) ;
V_49 = V_153 ;
break;
case V_154 :
F_55 ( & V_2 -> V_10 -> V_11 , L_29 ) ;
V_49 = V_65 ;
break;
case V_155 :
F_13 ( & V_2 -> V_10 -> V_11 , L_30 ) ;
V_49 = V_65 ;
break;
case V_156 :
F_13 ( & V_2 -> V_10 -> V_11 , L_31 ) ;
V_49 = V_65 ;
break;
case V_157 :
F_13 ( & V_2 -> V_10 -> V_11 , L_32 ) ;
V_49 = V_65 ;
break;
case V_158 :
F_13 ( & V_2 -> V_10 -> V_11 , L_33 ) ;
V_49 = V_159 ;
break;
case V_160 :
F_55 ( & V_2 -> V_10 -> V_11 , L_34 ) ;
if ( V_136 . V_137 . V_161 == 0 )
V_49 = V_140 ;
else
V_49 = V_149 ;
break;
case V_162 :
F_13 ( & V_2 -> V_10 -> V_11 , L_35 ,
V_32 -> V_48 -> V_50 -> V_69 ) ;
V_49 = V_159 ;
break;
case V_163 :
F_13 ( & V_2 -> V_10 -> V_11 , L_36 ) ;
V_49 = V_65 ;
break;
case V_164 :
F_13 ( & V_2 -> V_10 -> V_11 , L_37 ) ;
V_49 = V_65 ;
break;
case V_165 :
F_13 ( & V_2 -> V_10 -> V_11 , L_38 ) ;
V_49 = V_65 ;
break;
default:
F_17 ( & V_2 -> V_10 -> V_11 , L_39 ,
V_136 . V_137 . V_138 ) ;
V_49 = V_65 ;
break;
}
V_48 = V_32 -> V_48 ;
F_21 ( V_48 , V_49 ) ;
}
static T_6 F_56 ( int V_46 , void * V_166 )
{
struct V_1 * V_2 = V_166 ;
union V_135 V_136 ;
unsigned long V_63 ;
T_2 V_167 ;
F_27 ( V_2 -> V_61 -> V_64 , V_63 ) ;
V_167 = F_3 ( V_2 , V_116 ) ;
V_136 . V_168 = F_34 ( F_3 ( V_2 , V_169 ) ) ;
switch ( V_136 . V_137 . INT ) {
case V_24 :
F_30 ( V_2 -> V_61 -> V_64 , V_63 ) ;
return V_170 ;
case V_171 :
F_13 ( & V_2 -> V_10 -> V_11 , L_40 ) ;
break;
case V_172 :
F_13 ( & V_2 -> V_10 -> V_11 , L_41 ) ;
break;
case V_16 :
case V_173 :
case V_174 :
case V_175 :
if ( V_136 . V_137 . V_176 == V_93 ) {
struct V_31 * V_32 ;
F_18 (scb, &wd->active_scbs, list)
if ( V_167 == V_32 -> V_36 )
break;
if ( V_167 == V_32 -> V_36 )
F_54 ( V_2 , V_136 , V_32 ) ;
else
F_13 ( & V_2 -> V_10 -> V_11 , L_42 ) ;
} else
F_17 ( & V_2 -> V_10 -> V_11 , L_43 ,
V_136 . V_137 . V_176 ) ;
break;
case V_177 :
F_13 ( & V_2 -> V_10 -> V_11 , L_44 ) ;
break;
default:
F_13 ( & V_2 -> V_10 -> V_11 , L_45 ,
V_136 . V_137 . INT ) ;
}
F_5 ( V_2 , V_15 , V_24 ) ;
F_30 ( V_2 -> V_61 -> V_64 , V_63 ) ;
return V_178 ;
}
static void F_57 ( struct V_179 * V_180 )
{
struct V_1 * V_2 = V_180 -> V_22 ;
T_1 V_3 = F_1 ( V_2 , V_181 ) ;
V_180 -> V_182 = V_3 & V_183 ;
}
static void F_58 ( struct V_179 * V_180 )
{
struct V_1 * V_2 = V_180 -> V_22 ;
T_1 V_3 = 0 ;
if ( V_180 -> V_184 )
V_3 |= V_185 ;
if ( V_180 -> V_186 )
V_3 |= V_187 ;
if ( V_180 -> V_188 )
V_3 |= V_189 ;
F_5 ( V_2 , V_181 , V_3 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_179 V_180 ;
T_1 V_190 ;
struct V_191 V_192 ;
V_180 . V_22 = V_2 ;
V_180 . V_193 = F_57 ;
V_180 . V_194 = F_58 ;
V_180 . V_195 = V_196 ;
F_5 ( V_2 , V_181 , 0 ) ;
V_190 = F_1 ( V_2 , V_197 ) ;
V_190 &= ( ~ ( V_187 | V_185 | V_189 ) ) ;
V_190 |= V_183 ;
F_5 ( V_2 , V_197 , V_190 ) ;
F_60 ( & V_180 , 0 , ( T_1 * ) & V_192 , sizeof( V_192 ) ) ;
if ( V_192 . V_198 == 'W' && V_192 . V_199 == 'D' )
F_60 ( & V_180 , V_192 . V_200 ,
( T_1 * ) V_2 -> V_44 ,
sizeof( struct V_43 ) ) ;
else {
F_17 ( & V_2 -> V_10 -> V_11 , L_46 ,
V_192 . V_198 , V_192 . V_199 ) ;
V_2 -> V_44 -> V_201 = 0x10 ;
V_2 -> V_44 -> V_202 = 0x4c ;
V_2 -> V_44 -> V_203 = 0x07 ;
V_2 -> V_44 -> V_204 = 0x4d ;
V_2 -> V_44 -> V_205 = 0x01 ;
V_2 -> V_44 -> V_206 = F_61 ( 0x5555 ) ;
V_2 -> V_44 -> V_207 = 0x1b ;
if ( V_2 -> type == V_208 )
V_2 -> V_44 -> V_209 = F_34 ( 0x00000000 ) ;
else
V_2 -> V_44 -> V_209 = F_34 ( 0xffffffff ) ;
V_2 -> V_44 -> V_210 = F_34 ( 0xffffffff ) ;
V_2 -> V_44 -> V_211 = 0x00 ;
V_2 -> V_44 -> V_212 = 0x00 ;
}
V_2 -> V_44 -> V_213 = F_61 ( 0x0000 ) ;
}
static enum V_214 F_62 ( struct V_1 * V_2 )
{
T_1 V_215 = F_1 ( V_2 , V_197 ) ;
V_215 |= V_216 ;
F_5 ( V_2 , V_197 , V_215 ) ;
V_215 = F_1 ( V_2 , V_181 ) & V_216 ;
switch ( V_215 ) {
case 0x08 :
return V_208 ;
case 0x02 :
return V_217 ;
case 0x00 :
return V_218 ;
default:
F_17 ( & V_2 -> V_10 -> V_11 , L_47 , V_215 ) ;
return V_219 ;
}
}
static int F_63 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_22 ( V_61 ) ;
char * V_220 [] = { L_48 , L_49 , L_50 , L_51 } ;
int V_23 ;
F_64 ( & V_2 -> V_66 ) ;
F_64 ( & V_2 -> V_54 ) ;
V_61 -> V_4 = F_65 ( V_2 -> V_10 , 0 ) ;
V_2 -> type = F_62 ( V_2 ) ;
V_2 -> V_61 = V_61 ;
V_61 -> V_46 = V_2 -> V_10 -> V_46 ;
V_2 -> V_38 = NULL ;
V_2 -> V_44 = F_31 ( V_2 -> V_10 ,
sizeof( struct V_43 ) ,
& V_2 -> V_45 ) ;
if ( ! V_2 -> V_44 ) {
F_17 ( & V_2 -> V_10 -> V_11 , L_52 ) ;
return - V_101 ;
}
V_2 -> V_41 = F_31 ( V_2 -> V_10 , V_40 ,
& V_2 -> V_42 ) ;
if ( ! V_2 -> V_41 ) {
F_17 ( & V_2 -> V_10 -> V_11 , L_53 ) ;
V_23 = - V_101 ;
goto V_221;
}
V_23 = F_66 ( V_2 -> V_10 -> V_46 , F_56 , V_222 ,
L_54 , V_2 ) ;
if ( V_23 ) {
F_17 ( & V_2 -> V_10 -> V_11 , L_55 ,
V_2 -> V_10 -> V_46 ) ;
goto V_223;
}
F_59 ( V_2 ) ;
V_23 = F_41 ( V_2 ) ;
if ( V_23 )
goto V_224;
V_61 -> V_225 = V_2 -> V_44 -> V_203 & V_226 ;
F_45 ( & V_2 -> V_10 -> V_11 , L_56 ,
V_220 [ V_2 -> type ] , V_61 -> V_4 , V_61 -> V_46 , V_61 -> V_225 ) ;
return 0 ;
V_224:
F_20 ( V_2 -> V_10 -> V_46 , V_2 ) ;
V_223:
F_19 ( V_2 -> V_10 , V_40 , V_2 -> V_41 ,
V_2 -> V_42 ) ;
V_221:
F_19 ( V_2 -> V_10 , sizeof( struct V_43 ) ,
V_2 -> V_44 , V_2 -> V_45 ) ;
return V_23 ;
}
static int F_67 ( struct V_227 * V_10 , const struct V_228 * V_229 )
{
int V_230 ;
struct V_60 * V_61 ;
struct V_1 * V_2 ;
V_230 = F_68 ( V_10 ) ;
if ( V_230 )
goto V_231;
if ( F_69 ( V_10 , F_70 ( 32 ) ) ) {
F_17 ( & V_10 -> V_11 , L_57 ) ;
goto V_232;
}
V_230 = F_71 ( V_10 , L_54 ) ;
if ( V_230 )
goto V_232;
F_72 ( V_10 ) ;
V_230 = - V_233 ;
if ( F_73 ( V_10 , 0 ) == 0 )
goto V_234;
V_230 = - V_101 ;
V_61 = F_74 ( & V_235 , sizeof( struct V_1 ) ) ;
if ( ! V_61 )
goto V_234;
V_2 = F_22 ( V_61 ) ;
V_2 -> V_4 = F_75 ( V_10 , 0 , 0 ) ;
if ( ! V_2 -> V_4 )
goto V_236;
V_2 -> V_10 = V_10 ;
V_230 = F_63 ( V_61 ) ;
if ( V_230 )
goto V_237;
V_230 = F_76 ( V_61 , & V_2 -> V_10 -> V_11 ) ;
if ( V_230 )
goto V_238;
F_77 ( V_61 ) ;
F_78 ( V_10 , V_61 ) ;
return 0 ;
V_238:
F_16 ( V_2 ) ;
V_237:
F_79 ( V_10 , V_2 -> V_4 ) ;
V_236:
F_80 ( V_61 ) ;
V_234:
F_81 ( V_10 ) ;
V_232:
F_82 ( V_10 ) ;
V_231:
return V_230 ;
}
static void F_83 ( struct V_227 * V_10 )
{
struct V_60 * V_61 = F_84 ( V_10 ) ;
struct V_1 * V_2 = F_22 ( V_61 ) ;
F_85 ( V_61 ) ;
F_16 ( V_2 ) ;
F_79 ( V_10 , V_2 -> V_4 ) ;
F_81 ( V_10 ) ;
F_82 ( V_10 ) ;
F_80 ( V_61 ) ;
}
static int T_7 F_86 ( void )
{
return F_87 ( & V_239 ) ;
}
static void T_8 F_88 ( void )
{
F_89 ( & V_239 ) ;
}

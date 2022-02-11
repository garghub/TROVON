static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_6 )
{
F_3 ( V_2 , V_3 , F_1 ( V_2 , V_3 ) | V_6 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_6 )
{
F_3 ( V_2 , V_3 , F_1 ( V_2 , V_3 ) & ~ V_6 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_7 , T_1 V_8 , T_1 V_5 )
{
F_3 ( V_2 , V_3 ,
( F_1 ( V_2 , V_3 ) & ( ~ V_7 ) ) | V_5 << V_8 ) ;
}
static inline void F_8 ( void * V_9 , const void T_3 * V_10 ,
T_4 V_11 )
{
memcpy ( V_9 , V_10 , V_11 ) ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
T_1 V_12 = F_1 ( V_2 , V_13 ) ;
V_12 |= V_14 | V_15 ;
F_3 ( V_2 , V_13 , V_12 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
unsigned long V_16 = F_11 ( 100 ) ;
F_5 ( V_2 , V_13 , V_17 ) ;
F_5 ( V_2 , V_18 , V_19 ) ;
if ( ! F_12 ( & V_2 -> V_20 , V_16 ) )
F_13 ( V_2 -> V_21 , L_1 ) ;
F_9 ( V_2 ) ;
}
static T_5 F_14 ( struct V_1 * V_2 , int V_22 )
{
T_1 V_23 ;
if ( V_22 < 4 ) {
V_23 = F_1 ( V_2 , V_24 ) ;
V_23 >>= ( 3 - V_22 ) * 8 ;
} else {
V_23 = F_1 ( V_2 , V_25 ) ;
V_23 >>= 24 ;
}
return V_23 & 0xff ;
}
static T_5 F_15 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_25 ) & V_26 ;
}
static void F_16 ( struct V_1 * V_2 , T_1 V_27 ,
T_1 V_28 )
{
T_1 V_12 ;
F_9 ( V_2 ) ;
V_12 = F_1 ( V_2 , V_18 ) ;
V_12 &= ~ ( V_29 | V_30 | V_31 ) ;
V_12 |= V_27 << V_32 ;
V_12 |= V_28 << V_33 ;
F_3 ( V_2 , V_18 , V_12 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_27 ,
T_1 V_34 , T_1 V_28 )
{
T_1 V_12 ;
F_16 ( V_2 , V_27 , V_28 ) ;
V_12 = F_1 ( V_2 , V_35 ) ;
V_12 &= ~ V_36 ;
V_12 |= V_34 << V_37 ;
F_3 ( V_2 , V_35 , V_12 ) ;
}
static T_6 F_18 ( int V_38 , void * V_39 )
{
struct V_40 * V_41 = V_39 ;
struct V_1 * V_2 = F_19 ( V_41 ) ;
F_6 ( V_2 , V_13 , V_17 ) ;
F_20 ( & V_2 -> V_20 ) ;
return V_42 ;
}
static void F_21 ( struct V_1 * V_2 , int V_43 , int V_44 )
{
if ( V_43 != - 1 ) {
if ( V_2 -> V_45 . V_46 & V_47 )
V_43 = V_43 / 2 ;
F_7 ( V_2 , V_48 , V_49 ,
V_50 , V_43 ) ;
}
if ( V_44 != - 1 )
F_7 ( V_2 , V_51 , V_52 ,
V_53 , V_44 ) ;
}
static inline void F_22 ( struct V_1 * V_2 , int V_54 )
{
F_7 ( V_2 , V_55 ,
V_56 ,
V_57 , V_54 ) ;
}
static inline void F_23 ( struct V_1 * V_2 , int V_58 )
{
F_3 ( V_2 , V_59 , V_58 ) ;
}
static void F_24 ( struct V_40 * V_41 , unsigned V_60 ,
int V_43 , int V_44 )
{
struct V_1 * V_2 = F_19 ( V_41 ) ;
int V_61 = V_2 -> V_45 . V_46 & V_47 ? 1 : 0 ;
V_2 -> V_62 = F_25 ( V_43 , 0 ) ;
V_2 -> V_63 = V_64 ;
switch ( V_60 ) {
case V_65 :
F_21 ( V_2 , V_43 , V_44 ) ;
V_2 -> V_62 = 0 ;
return;
case V_66 :
V_61 += V_2 -> V_67 ;
F_23 ( V_2 , V_61 ) ;
F_17 ( V_2 , V_65 ,
V_60 , V_68 ) ;
if ( V_2 -> V_69 )
F_22 ( V_2 , V_2 -> V_54 ) ;
else
F_22 ( V_2 , V_70 ) ;
break;
case V_71 :
F_23 ( V_2 , 0 ) ;
F_16 ( V_2 , V_60 , V_72 ) ;
break;
case V_73 :
V_61 += V_41 -> V_74 ;
V_43 = V_41 -> V_75 ;
F_23 ( V_2 , V_61 ) ;
F_17 ( V_2 , V_76 ,
V_77 , V_78 ) ;
F_21 ( V_2 , V_43 , V_44 ) ;
F_22 ( V_2 , V_70 ) ;
break;
case V_76 :
V_61 += V_41 -> V_75 + V_41 -> V_74 ;
F_23 ( V_2 , V_61 ) ;
F_17 ( V_2 , V_76 ,
V_77 , V_78 ) ;
F_21 ( V_2 , V_43 , V_44 ) ;
F_22 ( V_2 , V_2 -> V_54 ) ;
break;
case V_79 :
V_2 -> V_63 = V_80 ;
V_61 = 3 * sizeof( struct V_81 ) ;
F_23 ( V_2 , V_61 ) ;
F_16 ( V_2 , V_60 , V_82 ) ;
F_21 ( V_2 , - 1 , V_43 ) ;
F_22 ( V_2 , V_70 ) ;
break;
case V_83 :
F_23 ( V_2 , 0 ) ;
F_17 ( V_2 , V_60 ,
V_84 , V_85 ) ;
F_21 ( V_2 , V_43 , V_44 ) ;
break;
case V_86 :
V_2 -> V_63 = V_87 ;
V_2 -> V_62 = 0 ;
F_23 ( V_2 , 0 ) ;
F_16 ( V_2 , V_60 , V_88 ) ;
F_21 ( V_2 , - 1 , V_43 ) ;
break;
case V_89 :
V_2 -> V_63 = V_90 ;
F_23 ( V_2 , 0 ) ;
F_16 ( V_2 , V_60 , V_91 ) ;
break;
default:
return;
}
F_10 ( V_2 ) ;
V_2 -> V_69 = false ;
V_2 -> V_67 = 0 ;
}
static void F_26 ( struct V_40 * V_41 , T_7 * V_92 , int V_93 )
{
struct V_1 * V_2 = F_19 ( V_41 ) ;
T_2 V_94 = V_2 -> V_62 ;
F_27 ( V_2 -> V_63 ) ;
F_8 ( V_92 , V_2 -> V_4 + F_28 ( 0 ) + V_94 , V_93 ) ;
V_2 -> V_62 += V_93 ;
}
static void F_29 ( struct V_40 * V_41 , const T_8 * V_92 ,
int V_93 )
{
struct V_1 * V_2 = F_19 ( V_41 ) ;
T_2 V_94 = V_2 -> V_62 ;
T_2 V_95 ;
V_95 = F_30 ( T_2 , V_93 , V_41 -> V_75 + V_41 -> V_74 - V_94 ) ;
F_8 ( V_2 -> V_4 + F_28 ( 0 ) + V_94 , V_92 , V_95 ) ;
V_2 -> V_67 += V_95 ;
V_2 -> V_62 += V_95 ;
}
static T_8 F_31 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_19 ( V_41 ) ;
T_5 V_12 ;
T_2 V_94 = V_2 -> V_62 ;
switch ( V_2 -> V_63 ) {
case V_87 :
V_12 = F_14 ( V_2 , V_94 ) ;
break;
case V_90 :
V_12 = F_15 ( V_2 ) ;
break;
#ifdef F_32
case V_80 :
V_94 = V_2 -> V_62 ^ 0x3 ;
#endif
default:
V_12 = * ( ( T_5 * ) ( V_2 -> V_4 + F_28 ( 0 ) + V_94 ) ) ;
break;
}
V_2 -> V_62 ++ ;
return V_12 ;
}
static T_9 F_33 ( struct V_40 * V_41 )
{
T_9 V_12 ;
F_26 ( V_41 , ( T_7 * ) & V_12 , sizeof( V_12 ) ) ;
return V_12 ;
}
static int F_34 ( struct V_40 * V_41 )
{
return 1 ;
}
static void F_35 ( struct V_40 * V_41 , int V_45 )
{
struct V_1 * V_2 = F_19 ( V_41 ) ;
T_1 V_12 = F_1 ( V_2 , V_51 ) ;
if ( V_2 -> V_96 != V_97 )
return;
V_12 &= ~ ( V_98 | V_99 ) ;
if ( V_45 >= 0 ) {
V_12 |= 1 << V_100 ;
V_12 |= F_36 ( V_45 ) << V_101 ;
}
F_3 ( V_2 , V_51 , V_12 ) ;
}
static inline int F_37 ( T_8 * V_102 , int V_58 , int V_103 )
{
T_10 * V_104 = ( T_10 * ) V_102 ;
int V_105 , V_106 = 0 ;
for ( V_105 = 0 ; V_105 < ( V_58 / 4 ) ; V_105 ++ ) {
V_106 += F_38 ( ~ V_104 [ V_105 ] ) ;
if ( F_39 ( V_106 > V_103 ) )
break;
}
return V_106 ;
}
static inline int F_40 ( struct V_40 * V_41 , T_8 * V_107 ,
T_8 * V_108 , int V_44 )
{
struct V_1 * V_2 = F_19 ( V_41 ) ;
T_1 V_109 = F_28 ( 0 ) + V_110 + V_111 ;
T_5 V_112 ;
T_5 V_113 ;
int V_114 = V_2 -> V_45 . V_115 . V_116 / 2 ;
V_112 = F_1 ( V_2 , V_109 ) & 0xff ;
V_113 = V_112 & V_117 ;
if ( ! ( V_112 & V_118 ) )
return V_113 ;
F_24 ( V_41 , V_73 , 0 , V_44 ) ;
F_26 ( V_41 , V_108 , V_41 -> V_74 ) ;
return F_41 ( V_107 , V_2 -> V_45 . V_115 . V_58 , V_108 ,
V_41 -> V_74 , NULL , 0 ,
V_114 ) ;
}
static int F_42 ( struct V_40 * V_41 , struct V_119 * V_45 ,
T_8 * V_92 , int V_120 , int V_44 )
{
int V_121 = V_45 -> V_115 . V_58 ;
int V_122 ;
F_26 ( V_41 , V_92 , V_121 ) ;
if ( V_120 )
F_26 ( V_41 , V_45 -> V_123 , V_41 -> V_74 ) ;
V_122 = F_40 ( V_41 , V_92 , V_45 -> V_123 , V_44 ) ;
if ( V_122 < 0 ) {
V_41 -> V_124 . V_125 ++ ;
return 0 ;
} else {
V_41 -> V_124 . V_126 += V_122 ;
return V_122 ;
}
}
static int F_43 ( struct V_40 * V_41 , struct V_119 * V_45 ,
const T_8 * V_92 , int V_120 , int V_44 )
{
struct V_1 * V_2 = F_19 ( V_41 ) ;
F_29 ( V_41 , V_92 , V_41 -> V_75 ) ;
if ( V_120 )
F_29 ( V_41 , V_45 -> V_123 , V_41 -> V_74 ) ;
V_2 -> V_69 = true ;
V_2 -> V_67 = V_41 -> V_75 + V_41 -> V_74 ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_55 , V_127 ) ;
F_6 ( V_2 , V_55 , V_128 ) ;
F_6 ( V_2 , V_55 , V_129 ) ;
F_6 ( V_2 , V_55 , V_130 ) ;
F_6 ( V_2 , V_55 , V_131 ) ;
F_5 ( V_2 , V_55 , V_132 ) ;
F_7 ( V_2 , V_55 , V_133 ,
V_134 , 1 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
if ( V_2 -> V_45 . V_46 & V_47 )
F_5 ( V_2 , V_55 , V_127 ) ;
else
F_6 ( V_2 , V_55 , V_127 ) ;
if ( V_2 -> V_45 . V_115 . V_135 == V_136 ) {
F_7 ( V_2 , V_55 ,
V_137 ,
V_138 ,
V_110 >> 3 ) ;
F_5 ( V_2 , V_55 , V_139 ) ;
}
}
static int F_46 ( struct V_140 * V_141 )
{
struct V_1 * V_2 ;
struct V_142 * V_143 ;
struct V_40 * V_41 ;
struct V_119 * V_45 ;
struct V_144 * V_145 ;
const struct V_146 * V_147 ;
int V_148 ;
int V_38 ;
V_2 = F_47 ( & V_141 -> V_21 , sizeof( * V_2 ) , V_149 ) ;
if ( ! V_2 )
return - V_150 ;
V_2 -> V_21 = & V_141 -> V_21 ;
V_41 = & V_2 -> V_41 ;
V_45 = & V_2 -> V_45 ;
V_41 -> V_151 = V_45 ;
V_41 -> V_152 = V_153 ;
V_41 -> V_21 . V_154 = V_2 -> V_21 ;
V_41 -> V_155 = V_156 ;
V_38 = F_48 ( V_141 , 0 ) ;
if ( V_38 <= 0 )
return - V_157 ;
V_143 = F_49 ( V_141 , V_158 , 0 ) ;
V_2 -> V_4 = F_50 ( V_2 -> V_21 , V_143 ) ;
if ( F_51 ( V_2 -> V_4 ) )
return F_52 ( V_2 -> V_4 ) ;
V_2 -> V_159 = F_53 ( & V_141 -> V_21 , NULL ) ;
if ( F_51 ( V_2 -> V_159 ) )
return F_52 ( V_2 -> V_159 ) ;
V_148 = F_54 ( V_2 -> V_159 ) ;
if ( V_148 ) {
F_55 ( V_2 -> V_21 , L_2 ) ;
return V_148 ;
}
V_147 = F_56 ( V_160 , & V_141 -> V_21 ) ;
V_2 -> V_96 = (enum V_161 ) V_147 -> V_39 ;
F_57 (nfc->dev->of_node, child) {
if ( F_58 ( V_145 , L_3 ) ) {
if ( V_45 -> V_162 ) {
F_55 ( V_2 -> V_21 ,
L_4 ) ;
V_148 = - V_157 ;
goto error;
}
V_45 -> V_162 = V_145 ;
}
}
if ( ! V_45 -> V_162 ) {
F_55 ( V_2 -> V_21 , L_5 ) ;
V_148 = - V_163 ;
goto V_164;
}
V_45 -> V_165 = F_34 ;
V_45 -> V_166 = F_24 ;
V_45 -> V_167 = F_31 ;
V_45 -> V_168 = F_33 ;
V_45 -> V_169 = F_26 ;
V_45 -> V_170 = F_29 ;
V_45 -> V_171 = F_35 ;
V_45 -> V_46 |= V_172 ;
F_59 ( & V_2 -> V_20 ) ;
V_148 = F_60 ( V_2 -> V_21 , V_38 , F_18 , 0 , V_156 , V_41 ) ;
if ( V_148 ) {
F_55 ( V_2 -> V_21 , L_6 ) ;
goto error;
}
F_44 ( V_2 ) ;
if ( F_61 ( V_41 , 1 , NULL ) ) {
V_148 = - V_173 ;
goto error;
}
F_45 ( V_2 ) ;
if ( V_45 -> V_174 & V_175 )
V_45 -> V_174 |= V_176 ;
if ( V_41 -> V_75 + V_41 -> V_74 > V_177 + V_178 - 8 ) {
F_55 ( V_2 -> V_21 , L_7 ) ;
V_148 = - V_173 ;
goto error;
}
if ( V_45 -> V_115 . V_135 == V_136 ) {
if ( V_41 -> V_75 != V_177 && V_41 -> V_74 < 64 ) {
F_55 ( V_2 -> V_21 , L_8 ) ;
V_148 = - V_173 ;
goto error;
}
if ( V_45 -> V_115 . V_58 != V_41 -> V_75 ) {
F_55 ( V_2 -> V_21 , L_9 ) ;
V_148 = - V_173 ;
goto error;
}
if ( V_41 -> V_74 > 64 )
V_41 -> V_74 = 64 ;
if ( V_45 -> V_115 . V_116 == 32 ) {
V_2 -> V_54 = V_179 ;
V_45 -> V_115 . V_180 = 60 ;
V_45 -> V_115 . V_181 = & V_182 ;
} else if ( V_45 -> V_115 . V_116 == 24 ) {
V_2 -> V_54 = V_183 ;
V_45 -> V_115 . V_180 = 45 ;
V_45 -> V_115 . V_181 = & V_184 ;
} else {
F_55 ( V_2 -> V_21 , L_10 ) ;
V_148 = - V_173 ;
goto error;
}
V_41 -> V_185 = V_45 -> V_115 . V_181 ;
V_45 -> V_115 . V_186 = F_42 ;
V_45 -> V_115 . V_187 = F_43 ;
V_45 -> V_115 . V_58 = V_177 ;
}
if ( F_62 ( V_41 ) ) {
V_148 = - V_173 ;
goto error;
}
F_63 ( V_141 , V_41 ) ;
return F_64 (mtd, NULL,
&(struct mtd_part_parser_data){
.of_node = chip->flash_node,
},
NULL, 0 ) ;
error:
F_65 ( V_45 -> V_162 ) ;
V_164:
F_66 ( V_2 -> V_159 ) ;
return V_148 ;
}
static int F_67 ( struct V_140 * V_141 )
{
struct V_40 * V_41 = F_68 ( V_141 ) ;
struct V_1 * V_2 = F_19 ( V_41 ) ;
F_69 ( V_41 ) ;
F_66 ( V_2 -> V_159 ) ;
return 0 ;
}
static int F_70 ( struct V_188 * V_21 )
{
struct V_40 * V_41 = F_71 ( V_21 ) ;
struct V_1 * V_2 = F_19 ( V_41 ) ;
F_66 ( V_2 -> V_159 ) ;
return 0 ;
}
static int F_72 ( struct V_188 * V_21 )
{
struct V_40 * V_41 = F_71 ( V_21 ) ;
struct V_1 * V_2 = F_19 ( V_41 ) ;
F_73 ( V_21 ) ;
F_54 ( V_2 -> V_159 ) ;
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
return 0 ;
}

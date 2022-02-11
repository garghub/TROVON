static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static inline T_1 F_4 ( struct V_1 * V_5 , T_2 V_6 )
{
return F_5 ( V_5 -> V_7 + V_6 ) ;
}
static inline void F_6 ( struct V_1 * V_5 , T_2 V_6 , T_1 V_8 )
{
F_7 ( V_8 , V_5 -> V_7 + V_6 ) ;
}
static inline void F_8 ( struct V_1 * V_5 , T_2 V_6 , T_1 V_9 )
{
F_6 ( V_5 , V_6 , F_4 ( V_5 , V_6 ) | V_9 ) ;
}
static inline void F_9 ( struct V_1 * V_5 , T_2 V_6 , T_1 V_9 )
{
F_6 ( V_5 , V_6 , F_4 ( V_5 , V_6 ) & ~ V_9 ) ;
}
static inline void F_10 ( struct V_1 * V_5 , T_1 V_6 ,
T_1 V_10 , T_1 V_11 , T_1 V_8 )
{
F_6 ( V_5 , V_6 ,
( F_4 ( V_5 , V_6 ) & ( ~ V_10 ) ) | V_8 << V_11 ) ;
}
static inline void F_11 ( void * V_12 , const void T_3 * V_13 ,
T_4 V_14 )
{
memcpy ( V_12 , V_13 , V_14 ) ;
}
static inline void F_12 ( struct V_1 * V_5 )
{
T_1 V_15 = F_4 ( V_5 , V_16 ) ;
V_15 |= V_17 | V_18 ;
F_6 ( V_5 , V_16 , V_15 ) ;
}
static void F_13 ( struct V_1 * V_5 )
{
unsigned long V_19 = F_14 ( 100 ) ;
F_8 ( V_5 , V_16 , V_20 ) ;
F_8 ( V_5 , V_21 , V_22 ) ;
if ( ! F_15 ( & V_5 -> V_23 , V_19 ) )
F_16 ( V_5 -> V_24 , L_1 ) ;
F_12 ( V_5 ) ;
}
static T_5 F_17 ( struct V_1 * V_5 , int V_25 )
{
T_1 V_26 ;
if ( V_25 < 4 ) {
V_26 = F_4 ( V_5 , V_27 ) ;
V_26 >>= ( 3 - V_25 ) * 8 ;
} else {
V_26 = F_4 ( V_5 , V_28 ) ;
V_26 >>= 24 ;
}
return V_26 & 0xff ;
}
static T_5 F_18 ( struct V_1 * V_5 )
{
return F_4 ( V_5 , V_28 ) & V_29 ;
}
static void F_19 ( struct V_1 * V_5 , T_1 V_30 ,
T_1 V_31 )
{
T_1 V_15 ;
F_12 ( V_5 ) ;
V_15 = F_4 ( V_5 , V_21 ) ;
V_15 &= ~ ( V_32 | V_33 | V_34 ) ;
V_15 |= V_30 << V_35 ;
V_15 |= V_31 << V_36 ;
F_6 ( V_5 , V_21 , V_15 ) ;
}
static void F_20 ( struct V_1 * V_5 , T_1 V_30 ,
T_1 V_37 , T_1 V_31 )
{
T_1 V_15 ;
F_19 ( V_5 , V_30 , V_31 ) ;
V_15 = F_4 ( V_5 , V_38 ) ;
V_15 &= ~ V_39 ;
V_15 |= V_37 << V_40 ;
F_6 ( V_5 , V_38 , V_15 ) ;
}
static T_6 F_21 ( int V_41 , void * V_42 )
{
struct V_2 * V_3 = V_42 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_9 ( V_5 , V_16 , V_20 ) ;
F_22 ( & V_5 -> V_23 ) ;
return V_43 ;
}
static void F_23 ( struct V_1 * V_5 , int V_44 , int V_45 )
{
if ( V_44 != - 1 ) {
if ( V_5 -> V_4 . V_46 & V_47 )
V_44 = V_44 / 2 ;
F_10 ( V_5 , V_48 , V_49 ,
V_50 , V_44 ) ;
}
if ( V_45 != - 1 )
F_10 ( V_5 , V_51 , V_52 ,
V_53 , V_45 ) ;
}
static inline void F_24 ( struct V_1 * V_5 , int V_54 )
{
F_10 ( V_5 , V_55 ,
V_56 ,
V_57 , V_54 ) ;
}
static inline void F_25 ( struct V_1 * V_5 , int V_58 )
{
F_6 ( V_5 , V_59 , V_58 ) ;
}
static void F_26 ( struct V_2 * V_3 , unsigned V_60 ,
int V_44 , int V_45 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_61 = V_5 -> V_4 . V_46 & V_47 ? 1 : 0 ;
V_5 -> V_62 = F_27 ( V_44 , 0 ) ;
V_5 -> V_63 = V_64 ;
switch ( V_60 ) {
case V_65 :
F_23 ( V_5 , V_44 , V_45 ) ;
V_5 -> V_62 = 0 ;
return;
case V_66 :
V_61 += V_5 -> V_67 ;
F_25 ( V_5 , V_61 ) ;
F_20 ( V_5 , V_65 ,
V_60 , V_68 ) ;
if ( V_5 -> V_69 )
F_24 ( V_5 , V_5 -> V_54 ) ;
else
F_24 ( V_5 , V_70 ) ;
break;
case V_71 :
F_25 ( V_5 , 0 ) ;
F_19 ( V_5 , V_60 , V_72 ) ;
break;
case V_73 :
V_61 += V_3 -> V_74 ;
V_44 = V_3 -> V_75 ;
F_25 ( V_5 , V_61 ) ;
F_20 ( V_5 , V_76 ,
V_77 , V_78 ) ;
F_23 ( V_5 , V_44 , V_45 ) ;
F_24 ( V_5 , V_70 ) ;
break;
case V_76 :
V_61 += V_3 -> V_75 + V_3 -> V_74 ;
F_25 ( V_5 , V_61 ) ;
F_20 ( V_5 , V_76 ,
V_77 , V_78 ) ;
F_23 ( V_5 , V_44 , V_45 ) ;
F_24 ( V_5 , V_5 -> V_54 ) ;
break;
case V_79 :
V_5 -> V_63 = V_80 ;
V_61 = 3 * sizeof( struct V_81 ) ;
F_25 ( V_5 , V_61 ) ;
F_19 ( V_5 , V_60 , V_82 ) ;
F_23 ( V_5 , - 1 , V_44 ) ;
F_24 ( V_5 , V_70 ) ;
break;
case V_83 :
F_25 ( V_5 , 0 ) ;
F_20 ( V_5 , V_60 ,
V_84 , V_85 ) ;
F_23 ( V_5 , V_44 , V_45 ) ;
break;
case V_86 :
V_5 -> V_63 = V_87 ;
V_5 -> V_62 = 0 ;
F_25 ( V_5 , 0 ) ;
F_19 ( V_5 , V_60 , V_88 ) ;
F_23 ( V_5 , - 1 , V_44 ) ;
break;
case V_89 :
V_5 -> V_63 = V_90 ;
F_25 ( V_5 , 0 ) ;
F_19 ( V_5 , V_60 , V_91 ) ;
break;
default:
return;
}
F_13 ( V_5 ) ;
V_5 -> V_69 = false ;
V_5 -> V_67 = 0 ;
}
static void F_28 ( struct V_2 * V_3 , T_7 * V_92 , int V_93 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_2 V_94 = V_5 -> V_62 ;
F_29 ( V_5 -> V_63 ) ;
F_11 ( V_92 , V_5 -> V_7 + F_30 ( 0 ) + V_94 , V_93 ) ;
V_5 -> V_62 += V_93 ;
}
static void F_31 ( struct V_2 * V_3 , const T_8 * V_92 ,
int V_93 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_2 V_94 = V_5 -> V_62 ;
T_2 V_95 ;
V_95 = F_32 ( T_2 , V_93 , V_3 -> V_75 + V_3 -> V_74 - V_94 ) ;
F_11 ( V_5 -> V_7 + F_30 ( 0 ) + V_94 , V_92 , V_95 ) ;
V_5 -> V_67 += V_95 ;
V_5 -> V_62 += V_95 ;
}
static T_8 F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_5 V_15 ;
T_2 V_94 = V_5 -> V_62 ;
switch ( V_5 -> V_63 ) {
case V_87 :
V_15 = F_17 ( V_5 , V_94 ) ;
break;
case V_90 :
V_15 = F_18 ( V_5 ) ;
break;
#ifdef F_34
case V_80 :
V_94 = V_5 -> V_62 ^ 0x3 ;
#endif
default:
V_15 = * ( ( T_5 * ) ( V_5 -> V_7 + F_30 ( 0 ) + V_94 ) ) ;
break;
}
V_5 -> V_62 ++ ;
return V_15 ;
}
static T_9 F_35 ( struct V_2 * V_3 )
{
T_9 V_15 ;
F_28 ( V_3 , ( T_7 * ) & V_15 , sizeof( V_15 ) ) ;
return V_15 ;
}
static int F_36 ( struct V_2 * V_3 )
{
return 1 ;
}
static void F_37 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_15 = F_4 ( V_5 , V_51 ) ;
if ( V_5 -> V_96 != V_97 )
return;
V_15 &= ~ ( V_98 | V_99 ) ;
if ( V_4 >= 0 ) {
V_15 |= 1 << V_100 ;
V_15 |= F_38 ( V_4 ) << V_101 ;
}
F_6 ( V_5 , V_51 , V_15 ) ;
}
static inline int F_39 ( T_8 * V_102 , int V_58 , int V_103 )
{
T_10 * V_104 = ( T_10 * ) V_102 ;
int V_105 , V_106 = 0 ;
for ( V_105 = 0 ; V_105 < ( V_58 / 4 ) ; V_105 ++ ) {
V_106 += F_40 ( ~ V_104 [ V_105 ] ) ;
if ( F_41 ( V_106 > V_103 ) )
break;
}
return V_106 ;
}
static inline int F_42 ( struct V_2 * V_3 , T_8 * V_107 ,
T_8 * V_108 , int V_45 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_109 = F_30 ( 0 ) + V_110 + V_111 ;
T_5 V_112 ;
T_5 V_113 ;
int V_114 = V_5 -> V_4 . V_115 . V_116 / 2 ;
V_112 = F_4 ( V_5 , V_109 ) & 0xff ;
V_113 = V_112 & V_117 ;
if ( ! ( V_112 & V_118 ) )
return V_113 ;
F_26 ( V_3 , V_73 , 0 , V_45 ) ;
F_28 ( V_3 , V_108 , V_3 -> V_74 ) ;
return F_43 ( V_107 , V_5 -> V_4 . V_115 . V_58 , V_108 ,
V_3 -> V_74 , NULL , 0 ,
V_114 ) ;
}
static int F_44 ( struct V_2 * V_3 , struct V_119 * V_4 ,
T_8 * V_92 , int V_120 , int V_45 )
{
int V_121 = V_4 -> V_115 . V_58 ;
int V_122 ;
F_28 ( V_3 , V_92 , V_121 ) ;
if ( V_120 )
F_28 ( V_3 , V_4 -> V_123 , V_3 -> V_74 ) ;
V_122 = F_42 ( V_3 , V_92 , V_4 -> V_123 , V_45 ) ;
if ( V_122 < 0 ) {
V_3 -> V_124 . V_125 ++ ;
return 0 ;
} else {
V_3 -> V_124 . V_126 += V_122 ;
return V_122 ;
}
}
static int F_45 ( struct V_2 * V_3 , struct V_119 * V_4 ,
const T_8 * V_92 , int V_120 , int V_45 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_31 ( V_3 , V_92 , V_3 -> V_75 ) ;
if ( V_120 )
F_31 ( V_3 , V_4 -> V_123 , V_3 -> V_74 ) ;
V_5 -> V_69 = true ;
V_5 -> V_67 = V_3 -> V_75 + V_3 -> V_74 ;
return 0 ;
}
static void F_46 ( struct V_1 * V_5 )
{
F_9 ( V_5 , V_55 , V_127 ) ;
F_9 ( V_5 , V_55 , V_128 ) ;
F_9 ( V_5 , V_55 , V_129 ) ;
F_9 ( V_5 , V_55 , V_130 ) ;
F_9 ( V_5 , V_55 , V_131 ) ;
F_8 ( V_5 , V_55 , V_132 ) ;
F_10 ( V_5 , V_55 , V_133 ,
V_134 , 1 ) ;
}
static void F_47 ( struct V_1 * V_5 )
{
if ( V_5 -> V_4 . V_46 & V_47 )
F_8 ( V_5 , V_55 , V_127 ) ;
else
F_9 ( V_5 , V_55 , V_127 ) ;
if ( V_5 -> V_4 . V_115 . V_135 == V_136 ) {
F_10 ( V_5 , V_55 ,
V_137 ,
V_138 ,
V_110 >> 3 ) ;
F_8 ( V_5 , V_55 , V_139 ) ;
}
}
static int F_48 ( struct V_140 * V_141 )
{
struct V_1 * V_5 ;
struct V_142 * V_143 ;
struct V_2 * V_3 ;
struct V_119 * V_4 ;
struct V_144 * V_145 ;
const struct V_146 * V_147 ;
int V_148 ;
int V_41 ;
V_5 = F_49 ( & V_141 -> V_24 , sizeof( * V_5 ) , V_149 ) ;
if ( ! V_5 )
return - V_150 ;
V_5 -> V_24 = & V_141 -> V_24 ;
V_4 = & V_5 -> V_4 ;
V_3 = F_50 ( V_4 ) ;
V_3 -> V_151 = V_152 ;
V_3 -> V_24 . V_153 = V_5 -> V_24 ;
V_3 -> V_154 = V_155 ;
V_41 = F_51 ( V_141 , 0 ) ;
if ( V_41 <= 0 )
return - V_156 ;
V_143 = F_52 ( V_141 , V_157 , 0 ) ;
V_5 -> V_7 = F_53 ( V_5 -> V_24 , V_143 ) ;
if ( F_54 ( V_5 -> V_7 ) )
return F_55 ( V_5 -> V_7 ) ;
V_5 -> V_158 = F_56 ( & V_141 -> V_24 , NULL ) ;
if ( F_54 ( V_5 -> V_158 ) )
return F_55 ( V_5 -> V_158 ) ;
V_148 = F_57 ( V_5 -> V_158 ) ;
if ( V_148 ) {
F_58 ( V_5 -> V_24 , L_2 ) ;
return V_148 ;
}
V_147 = F_59 ( V_159 , & V_141 -> V_24 ) ;
V_5 -> V_96 = (enum V_160 ) V_147 -> V_42 ;
F_60 (nfc->dev->of_node, child) {
if ( F_61 ( V_145 , L_3 ) ) {
if ( F_62 ( V_4 ) ) {
F_58 ( V_5 -> V_24 ,
L_4 ) ;
V_148 = - V_156 ;
goto error;
}
F_63 ( V_4 , V_145 ) ;
}
}
if ( ! F_62 ( V_4 ) ) {
F_58 ( V_5 -> V_24 , L_5 ) ;
V_148 = - V_161 ;
goto V_162;
}
V_4 -> V_163 = F_36 ;
V_4 -> V_164 = F_26 ;
V_4 -> V_165 = F_33 ;
V_4 -> V_166 = F_35 ;
V_4 -> V_167 = F_28 ;
V_4 -> V_168 = F_31 ;
V_4 -> V_169 = F_37 ;
V_4 -> V_46 |= V_170 ;
F_64 ( & V_5 -> V_23 ) ;
V_148 = F_65 ( V_5 -> V_24 , V_41 , F_21 , 0 , V_155 , V_3 ) ;
if ( V_148 ) {
F_58 ( V_5 -> V_24 , L_6 ) ;
goto error;
}
F_46 ( V_5 ) ;
if ( F_66 ( V_3 , 1 , NULL ) ) {
V_148 = - V_171 ;
goto error;
}
F_47 ( V_5 ) ;
if ( V_4 -> V_172 & V_173 )
V_4 -> V_172 |= V_174 ;
if ( V_3 -> V_75 + V_3 -> V_74 > V_175 + V_176 - 8 ) {
F_58 ( V_5 -> V_24 , L_7 ) ;
V_148 = - V_171 ;
goto error;
}
if ( V_4 -> V_115 . V_135 == V_136 ) {
if ( V_3 -> V_75 != V_175 && V_3 -> V_74 < 64 ) {
F_58 ( V_5 -> V_24 , L_8 ) ;
V_148 = - V_171 ;
goto error;
}
if ( V_4 -> V_115 . V_58 != V_3 -> V_75 ) {
F_58 ( V_5 -> V_24 , L_9 ) ;
V_148 = - V_171 ;
goto error;
}
if ( V_3 -> V_74 > 64 )
V_3 -> V_74 = 64 ;
if ( V_4 -> V_115 . V_116 == 32 ) {
V_5 -> V_54 = V_177 ;
V_4 -> V_115 . V_178 = 60 ;
} else if ( V_4 -> V_115 . V_116 == 24 ) {
V_5 -> V_54 = V_179 ;
V_4 -> V_115 . V_178 = 45 ;
} else {
F_58 ( V_5 -> V_24 , L_10 ) ;
V_148 = - V_171 ;
goto error;
}
V_4 -> V_115 . V_180 = F_44 ;
V_4 -> V_115 . V_181 = F_45 ;
V_4 -> V_115 . V_58 = V_175 ;
}
if ( F_67 ( V_3 ) ) {
V_148 = - V_171 ;
goto error;
}
F_68 ( V_141 , V_3 ) ;
return F_69 ( V_3 , NULL , 0 ) ;
error:
F_70 ( F_62 ( V_4 ) ) ;
V_162:
F_71 ( V_5 -> V_158 ) ;
return V_148 ;
}
static int F_72 ( struct V_140 * V_141 )
{
struct V_2 * V_3 = F_73 ( V_141 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_74 ( V_3 ) ;
F_71 ( V_5 -> V_158 ) ;
return 0 ;
}
static int F_75 ( struct V_182 * V_24 )
{
struct V_2 * V_3 = F_76 ( V_24 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_71 ( V_5 -> V_158 ) ;
return 0 ;
}
static int F_77 ( struct V_182 * V_24 )
{
struct V_2 * V_3 = F_76 ( V_24 ) ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_78 ( V_24 ) ;
F_57 ( V_5 -> V_158 ) ;
F_46 ( V_5 ) ;
F_47 ( V_5 ) ;
return 0 ;
}

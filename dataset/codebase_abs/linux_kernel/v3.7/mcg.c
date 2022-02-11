static const char * F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
return L_1 ;
case V_4 :
return L_2 ;
case V_5 :
return L_3 ;
case V_6 :
return L_4 ;
}
return L_5 ;
}
static struct V_7 * F_2 ( struct V_8 * V_9 ,
union V_10 * V_11 )
{
struct V_12 * V_13 = V_9 -> V_14 . V_12 ;
struct V_7 * V_15 ;
int V_16 ;
while ( V_13 ) {
V_15 = F_3 ( V_13 , struct V_7 , V_13 ) ;
V_16 = memcmp ( V_11 -> V_17 , V_15 -> V_18 . V_11 . V_17 , sizeof *V_11 ) ;
if ( ! V_16 )
return V_15 ;
if ( V_16 < 0 )
V_13 = V_13 -> V_19 ;
else
V_13 = V_13 -> V_20 ;
}
return NULL ;
}
static struct V_7 * F_4 ( struct V_8 * V_9 ,
struct V_7 * V_15 )
{
struct V_12 * * V_21 = & V_9 -> V_14 . V_12 ;
struct V_12 * V_22 = NULL ;
struct V_7 * V_23 ;
int V_16 ;
while ( * V_21 ) {
V_22 = * V_21 ;
V_23 = F_3 ( V_22 , struct V_7 , V_13 ) ;
V_16 = memcmp ( V_15 -> V_18 . V_11 . V_17 , V_23 -> V_18 . V_11 . V_17 ,
sizeof V_15 -> V_18 . V_11 ) ;
if ( V_16 < 0 )
V_21 = & ( * V_21 ) -> V_19 ;
else if ( V_16 > 0 )
V_21 = & ( * V_21 ) -> V_20 ;
else
return V_23 ;
}
F_5 ( & V_15 -> V_13 , V_22 , V_21 ) ;
F_6 ( & V_15 -> V_13 , & V_9 -> V_14 ) ;
return NULL ;
}
static int F_7 ( struct V_8 * V_9 , struct V_24 * V_25 )
{
struct V_26 * V_27 = V_9 -> V_27 ;
struct V_28 V_29 ;
F_8 ( & V_27 -> V_30 ) ;
if ( ! V_27 -> V_31 [ V_9 -> V_32 - 1 ] ) {
F_9 ( & V_27 -> V_30 ) ;
return - V_33 ;
}
F_10 ( V_27 -> V_31 [ V_9 -> V_32 - 1 ] , & V_29 ) ;
F_9 ( & V_27 -> V_30 ) ;
return F_11 ( V_27 , F_12 ( V_27 -> V_27 ) , V_9 -> V_32 ,
V_34 , 0 , 1 , V_35 , & V_29 , V_25 ) ;
}
static int F_13 ( int V_36 , struct V_8 * V_9 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = V_9 -> V_27 ;
struct V_37 * V_38 = V_27 -> V_39 [ V_9 -> V_32 - 1 ] [ 1 ] ;
struct V_40 V_41 ;
struct V_28 V_29 ;
if ( ! V_38 )
return - V_33 ;
F_14 ( V_27 -> V_31 [ V_9 -> V_32 - 1 ] , & V_29 ) ;
if ( F_15 ( & V_27 -> V_42 , V_9 -> V_32 , V_43 , & V_41 . V_44 ) )
return - V_45 ;
V_41 . V_46 = 0 ;
V_41 . V_47 = 0 ;
V_41 . V_48 = V_9 -> V_32 ;
V_41 . V_49 = V_29 . V_50 ;
V_41 . V_51 = 1 ;
return F_16 ( V_27 , V_36 , V_9 -> V_32 , V_34 , & V_41 , NULL , V_25 ) ;
}
static int F_17 ( struct V_7 * V_15 , struct V_52 * V_53 )
{
struct V_52 V_25 ;
struct V_54 * V_55 = (struct V_54 * ) & V_25 . V_56 ;
int V_16 ;
memcpy ( & V_25 , V_53 , sizeof V_25 ) ;
V_55 -> V_57 . V_58 . V_59 = V_15 -> V_60 -> V_61 [ 0 ] ;
V_25 . V_62 . V_63 = F_18 ( V_15 -> V_60 ) ;
V_15 -> V_64 = V_25 . V_62 . V_63 ;
V_16 = F_7 ( V_15 -> V_60 , (struct V_24 * ) & V_25 ) ;
if ( ! V_16 ) {
F_19 ( V_15 -> V_60 -> V_65 , & V_15 -> V_66 ,
F_20 ( V_67 ) ) ;
}
return V_16 ;
}
static int F_21 ( struct V_7 * V_15 , T_1 V_68 )
{
struct V_52 V_25 ;
struct V_54 * V_69 = (struct V_54 * ) & V_25 . V_56 ;
int V_16 ;
memset ( & V_25 , 0 , sizeof V_25 ) ;
V_25 . V_62 . V_70 = 1 ;
V_25 . V_62 . V_71 = V_72 ;
V_25 . V_62 . V_73 = 2 ;
V_25 . V_62 . V_74 = V_75 ;
V_25 . V_62 . V_76 = F_22 ( 0 ) ;
V_25 . V_62 . V_77 = F_22 ( 0 ) ;
V_25 . V_62 . V_63 = F_18 ( V_15 -> V_60 ) ;
V_15 -> V_64 = V_25 . V_62 . V_63 ;
V_25 . V_62 . V_78 = F_22 ( V_79 ) ;
V_25 . V_62 . V_80 = F_23 ( 0 ) ;
V_25 . V_81 . V_82 = 0x0 ;
V_25 . V_81 . V_83 = F_22 ( 7 ) ;
V_25 . V_81 . V_84 = V_85 |
V_86 | V_87 ;
* V_69 = V_15 -> V_18 ;
V_69 -> V_88 = V_68 ;
V_16 = F_7 ( V_15 -> V_60 , (struct V_24 * ) & V_25 ) ;
if ( V_16 )
V_15 -> V_2 = V_3 ;
if ( ! V_16 ) {
F_19 ( V_15 -> V_60 -> V_65 , & V_15 -> V_66 ,
F_20 ( V_67 ) ) ;
}
return V_16 ;
}
static int F_24 ( int V_36 , struct V_7 * V_15 ,
struct V_52 * V_89 , T_2 V_76 )
{
struct V_52 V_25 ;
struct V_54 * V_69 = (struct V_54 * ) & V_25 . V_56 ;
struct V_54 * V_90 = (struct V_54 * ) & V_89 -> V_56 ;
int V_16 ;
memset ( & V_25 , 0 , sizeof V_25 ) ;
V_25 . V_62 . V_70 = 1 ;
V_25 . V_62 . V_71 = V_72 ;
V_25 . V_62 . V_73 = 2 ;
V_25 . V_62 . V_74 = V_91 ;
V_25 . V_62 . V_76 = F_22 ( V_76 ) ;
V_25 . V_62 . V_77 = F_22 ( 0 ) ;
V_25 . V_62 . V_63 = V_89 -> V_62 . V_63 ;
* ( T_1 * ) & V_25 . V_62 . V_63 = 0 ;
V_25 . V_62 . V_78 = F_22 ( V_79 ) ;
V_25 . V_62 . V_80 = F_23 ( 0 ) ;
V_25 . V_81 . V_82 = V_89 -> V_81 . V_82 ;
V_25 . V_81 . V_83 = F_22 ( 7 ) ;
V_25 . V_81 . V_84 = 0 ;
* V_69 = V_15 -> V_18 ;
V_69 -> V_88 &= 0xf0 ;
V_69 -> V_88 |= ( V_15 -> V_92 [ V_36 ] . V_68 & 0x0f ) ;
memcpy ( & V_69 -> V_57 , & V_90 -> V_57 , sizeof V_90 -> V_57 ) ;
V_16 = F_13 ( V_36 , V_15 -> V_60 , (struct V_24 * ) & V_25 ) ;
return V_16 ;
}
static int F_25 ( T_3 V_84 ,
T_3 V_93 ,
T_3 V_94 ,
T_1 V_95 , T_1 V_96 )
{
int V_97 ;
T_1 V_98 = V_96 >> 6 ;
V_96 &= 0x3f ;
V_95 &= 0x3f ;
if ( ! ( V_84 & V_93 ) || ! ( V_84 & V_94 ) )
return 0 ;
switch ( V_98 ) {
case V_99 :
V_97 = ( V_95 <= V_96 ) ;
break;
case V_100 :
V_97 = ( V_95 >= V_96 ) ;
break;
case V_101 :
V_97 = ( V_95 != V_96 ) ;
break;
default:
V_97 = 0 ;
break;
}
return V_97 ;
}
static T_2 F_26 ( struct V_54 * V_102 ,
struct V_54 * V_103 , T_3 V_84 )
{
#define F_27 0x0200
if ( V_84 & V_104 && V_102 -> V_105 != V_103 -> V_105 )
return F_27 ;
if ( V_84 & V_106 && V_102 -> V_107 != V_103 -> V_107 )
return F_27 ;
if ( F_25 ( V_84 , V_108 ,
V_109 ,
V_102 -> V_110 , V_103 -> V_110 ) )
return F_27 ;
if ( V_84 & V_111 &&
V_102 -> V_112 != V_103 -> V_112 )
return F_27 ;
if ( V_84 & V_113 && V_102 -> V_114 != V_103 -> V_114 )
return F_27 ;
if ( F_25 ( V_84 , V_115 ,
V_116 ,
V_102 -> V_117 , V_103 -> V_117 ) )
return F_27 ;
if ( F_25 ( V_84 ,
V_118 ,
V_119 ,
V_102 -> V_120 , V_103 -> V_120 ) )
return F_27 ;
if ( V_84 & V_121 &&
( F_28 ( V_102 -> V_122 ) & 0xf0000000 ) !=
( F_28 ( V_103 -> V_122 ) & 0xf0000000 ) )
return F_27 ;
if ( V_84 & V_123 &&
( F_28 ( V_102 -> V_122 ) & 0x0fffff00 ) !=
( F_28 ( V_103 -> V_122 ) & 0x0fffff00 ) )
return F_27 ;
if ( V_84 & V_124 &&
( F_28 ( V_102 -> V_122 ) & 0x000000ff ) !=
( F_28 ( V_103 -> V_122 ) & 0x000000ff ) )
return F_27 ;
if ( V_84 & V_125 &&
( V_102 -> V_88 & 0xf0 ) !=
( V_103 -> V_88 & 0xf0 ) )
return F_27 ;
return 0 ;
}
static int F_29 ( struct V_7 * V_15 , int V_126 )
{
struct V_8 * V_9 = V_15 -> V_60 ;
int V_127 ;
F_30 ( & V_9 -> V_128 ) ;
F_30 ( & V_15 -> V_129 ) ;
if ( F_31 ( & V_15 -> V_130 ) ) {
if ( ! V_126 ) {
if ( V_15 -> V_2 != V_3 &&
! F_32 ( & V_15 -> V_66 ) ) {
F_33 ( & V_15 -> V_130 ) ;
F_34 ( & V_15 -> V_129 ) ;
F_34 ( & V_9 -> V_128 ) ;
return 0 ;
}
}
V_127 = memcmp ( & V_15 -> V_18 . V_11 , & V_131 , sizeof V_131 ) ;
if ( V_127 )
F_35 ( V_9 -> V_27 , V_9 -> V_32 , & V_15 -> V_132 . V_133 ) ;
if ( ! F_36 ( & V_15 -> V_134 ) )
F_37 ( V_15 , L_6 ) ;
if ( V_127 )
F_38 ( & V_15 -> V_13 , & V_9 -> V_14 ) ;
F_39 ( & V_15 -> V_135 ) ;
F_34 ( & V_15 -> V_129 ) ;
F_34 ( & V_9 -> V_128 ) ;
F_40 ( V_15 ) ;
return 1 ;
} else {
F_34 ( & V_15 -> V_129 ) ;
F_34 ( & V_9 -> V_128 ) ;
}
return 0 ;
}
static void F_41 ( struct V_7 * V_15 , T_1 V_68 , int V_136 )
{
int V_137 ;
for ( V_137 = 0 ; V_137 < 3 ; V_137 ++ , V_68 >>= 1 )
if ( V_68 & 0x1 )
V_15 -> V_138 [ V_137 ] += V_136 ;
}
static T_1 F_42 ( struct V_7 * V_15 )
{
T_1 V_139 = 0 ;
int V_137 ;
for ( V_137 = 0 ; V_137 < 3 ; V_137 ++ )
if ( ! V_15 -> V_138 [ V_137 ] )
V_139 |= ( 1 << V_137 ) ;
return V_139 & ( V_15 -> V_18 . V_88 & 7 ) ;
}
static int F_43 ( struct V_7 * V_15 , int V_36 , T_1 V_140 )
{
int V_16 = 0 ;
T_1 V_68 ;
V_68 = V_140 & ( ~ V_15 -> V_92 [ V_36 ] . V_68 ) ;
F_41 ( V_15 , V_68 , 1 ) ;
V_15 -> V_92 [ V_36 ] . V_68 |= V_68 ;
if ( V_15 -> V_92 [ V_36 ] . V_2 != V_141 && V_68 ) {
V_15 -> V_92 [ V_36 ] . V_2 = V_141 ;
V_16 = 1 ;
}
return V_16 ;
}
static int F_44 ( struct V_7 * V_15 , int V_36 , T_1 V_139 )
{
int V_16 = 0 ;
F_41 ( V_15 , V_139 , - 1 ) ;
V_15 -> V_92 [ V_36 ] . V_68 &= ~ V_139 ;
if ( ! V_15 -> V_92 [ V_36 ] . V_68 ) {
V_15 -> V_92 [ V_36 ] . V_2 = V_142 ;
V_16 = 1 ;
}
return V_16 ;
}
static int F_45 ( struct V_7 * V_15 , int V_36 , T_1 V_143 )
{
if ( V_15 -> V_92 [ V_36 ] . V_2 != V_141 )
return F_27 ;
if ( ~ V_15 -> V_92 [ V_36 ] . V_68 & V_143 )
return F_27 ;
if ( ! V_143 )
return F_27 ;
return 0 ;
}
static void F_46 ( struct V_144 * V_145 )
{
struct V_146 * V_147 = F_47 ( V_145 ) ;
struct V_7 * V_15 ;
struct V_148 * V_149 = NULL ;
V_15 = F_48 ( V_147 , F_49 ( * V_15 ) , V_66 ) ;
F_30 ( & V_15 -> V_129 ) ;
if ( V_15 -> V_2 == V_4 ) {
if ( ! F_36 ( & V_15 -> V_134 ) ) {
V_149 = F_50 ( & V_15 -> V_134 , struct V_148 , V_150 ) ;
F_51 ( & V_149 -> V_150 ) ;
F_51 ( & V_149 -> V_151 ) ;
-- V_15 -> V_92 [ V_149 -> V_92 ] . V_152 ;
F_34 ( & V_15 -> V_129 ) ;
F_40 ( V_149 ) ;
if ( memcmp ( & V_15 -> V_18 . V_11 , & V_131 , sizeof V_131 ) ) {
if ( F_29 ( V_15 , 1 ) )
return;
} else {
F_40 ( V_15 ) ;
return;
}
F_30 ( & V_15 -> V_129 ) ;
} else
F_37 ( V_15 , L_7 ) ;
} else if ( V_15 -> V_2 == V_5 ) {
if ( V_15 -> V_18 . V_88 & 7 )
V_15 -> V_18 . V_88 &= 0xf8 ;
V_15 -> V_2 = V_3 ;
F_34 ( & V_15 -> V_129 ) ;
if ( F_29 ( V_15 , 1 ) )
return;
F_30 ( & V_15 -> V_129 ) ;
} else
F_37 ( V_15 , L_8 , F_1 ( V_15 -> V_2 ) ) ;
V_15 -> V_2 = V_3 ;
F_33 ( & V_15 -> V_130 ) ;
if ( ! F_52 ( V_15 -> V_60 -> V_65 , & V_15 -> V_145 ) )
F_53 ( & V_15 -> V_130 ) ;
F_34 ( & V_15 -> V_129 ) ;
}
static int F_54 ( struct V_7 * V_15 , T_1 V_143 ,
struct V_148 * V_149 )
{
T_2 V_76 ;
if ( V_149 -> V_153 )
V_143 = V_15 -> V_92 [ V_149 -> V_92 ] . V_68 ;
V_76 = F_45 ( V_15 , V_149 -> V_92 , V_143 ) ;
if ( ! V_76 )
F_44 ( V_15 , V_149 -> V_92 , V_143 ) ;
if ( ! V_149 -> V_153 )
F_24 ( V_149 -> V_92 , V_15 , & V_149 -> V_53 , V_76 ) ;
-- V_15 -> V_92 [ V_149 -> V_92 ] . V_152 ;
F_51 ( & V_149 -> V_150 ) ;
F_51 ( & V_149 -> V_151 ) ;
F_40 ( V_149 ) ;
return 1 ;
}
static int F_55 ( struct V_7 * V_15 , T_1 V_140 ,
struct V_148 * V_149 )
{
T_1 V_154 = V_15 -> V_18 . V_88 & 7 ;
int V_155 = 0 ;
T_2 V_76 ;
struct V_54 * V_69 = (struct V_54 * ) V_149 -> V_53 . V_56 ;
if ( V_140 == ( V_154 & V_140 ) ) {
V_76 = F_26 ( & V_15 -> V_18 , V_69 , V_149 -> V_53 . V_81 . V_84 ) ;
if ( ! V_76 )
F_43 ( V_15 , V_149 -> V_92 , V_140 ) ;
-- V_15 -> V_92 [ V_149 -> V_92 ] . V_152 ;
F_24 ( V_149 -> V_92 , V_15 , & V_149 -> V_53 , V_76 ) ;
F_51 ( & V_149 -> V_150 ) ;
F_51 ( & V_149 -> V_151 ) ;
F_40 ( V_149 ) ;
++ V_155 ;
} else {
V_15 -> V_156 = V_15 -> V_2 ;
if ( F_17 ( V_15 , & V_149 -> V_53 ) ) {
-- V_15 -> V_92 [ V_149 -> V_92 ] . V_152 ;
F_51 ( & V_149 -> V_150 ) ;
F_51 ( & V_149 -> V_151 ) ;
F_40 ( V_149 ) ;
V_155 = 1 ;
V_15 -> V_2 = V_15 -> V_156 ;
} else
V_15 -> V_2 = V_4 ;
}
return V_155 ;
}
static void F_56 ( struct V_144 * V_145 )
{
struct V_7 * V_15 ;
struct V_148 * V_149 = NULL ;
struct V_54 * V_69 ;
T_1 V_157 ;
int V_158 = 1 ;
T_2 V_76 ;
T_1 V_74 ;
V_15 = F_48 ( V_145 , F_49 ( * V_15 ) , V_145 ) ;
F_30 ( & V_15 -> V_129 ) ;
if ( V_15 -> V_2 == V_6 ) {
F_32 ( & V_15 -> V_66 ) ;
V_76 = F_57 ( V_15 -> V_159 . V_62 . V_76 ) ;
V_74 = V_15 -> V_159 . V_62 . V_74 ;
if ( V_15 -> V_64 != V_15 -> V_159 . V_62 . V_63 ) {
F_37 ( V_15 , L_9 ,
F_58 ( V_15 -> V_159 . V_62 . V_63 ) ,
F_58 ( V_15 -> V_64 ) ) ;
V_15 -> V_2 = V_15 -> V_156 ;
goto V_160;
}
if ( V_76 ) {
if ( ! F_36 ( & V_15 -> V_134 ) )
V_149 = F_50 ( & V_15 -> V_134 ,
struct V_148 , V_150 ) ;
if ( ( V_74 == V_91 ) ) {
if ( V_149 ) {
F_24 ( V_149 -> V_92 , V_15 , & V_149 -> V_53 , V_76 ) ;
-- V_15 -> V_92 [ V_149 -> V_92 ] . V_152 ;
F_51 ( & V_149 -> V_150 ) ;
F_51 ( & V_149 -> V_151 ) ;
F_40 ( V_149 ) ;
++ V_158 ;
} else
F_37 ( V_15 , L_10 ) ;
} else if ( V_74 == V_161 && V_15 -> V_60 -> V_162 )
++ V_158 ;
} else {
T_1 V_163 ;
T_1 V_164 ;
V_163 = ( (struct V_54 * )
V_15 -> V_159 . V_56 ) -> V_88 & 7 ;
V_164 = V_15 -> V_18 . V_88 & 7 ;
if ( V_74 == V_91 ) {
if ( ! V_164 && V_163 )
-- V_158 ;
} else if ( ! V_163 )
++ V_158 ;
memcpy ( & V_15 -> V_18 , V_15 -> V_159 . V_56 , sizeof V_15 -> V_18 ) ;
}
V_15 -> V_2 = V_3 ;
}
V_160:
while ( ! F_36 ( & V_15 -> V_134 ) && V_15 -> V_2 == V_3 ) {
V_149 = F_50 ( & V_15 -> V_134 , struct V_148 ,
V_150 ) ;
V_69 = (struct V_54 * ) V_149 -> V_53 . V_56 ;
V_157 = V_69 -> V_88 & 0x7 ;
if ( V_149 -> V_53 . V_62 . V_74 == V_75 )
V_158 += F_54 ( V_15 , V_157 , V_149 ) ;
else
V_158 += F_55 ( V_15 , V_157 , V_149 ) ;
}
if ( V_15 -> V_2 == V_3 ) {
V_157 = F_42 ( V_15 ) ;
if ( V_157 ) {
V_15 -> V_18 . V_88 &= ~ V_157 ;
V_15 -> V_156 = V_15 -> V_2 ;
if ( F_21 ( V_15 , V_157 ) ) {
V_15 -> V_2 = V_15 -> V_156 ;
++ V_158 ;
} else
V_15 -> V_2 = V_5 ;
}
}
if ( ! F_36 ( & V_15 -> V_134 ) && V_15 -> V_2 == V_3 )
goto V_160;
F_34 ( & V_15 -> V_129 ) ;
while ( V_158 -- )
F_29 ( V_15 , 0 ) ;
}
static struct V_7 * F_59 ( struct V_8 * V_9 ,
T_4 V_63 ,
union V_10 * V_165 )
{
struct V_7 * V_15 = NULL , * V_23 ;
struct V_148 * V_149 ;
struct V_166 * V_167 ;
struct V_166 * V_168 ;
F_30 ( & V_9 -> V_128 ) ;
F_60 (pos, n, &ctx->mcg_mgid0_list) {
V_15 = F_61 ( V_167 , struct V_7 , V_135 ) ;
F_30 ( & V_15 -> V_129 ) ;
if ( V_15 -> V_64 == V_63 ) {
if ( memcmp ( V_165 , & V_131 , sizeof V_131 ) ) {
V_15 -> V_18 . V_11 = * V_165 ;
sprintf ( V_15 -> V_169 , L_11 ,
F_58 ( V_15 -> V_18 . V_11 . V_58 . V_170 ) ,
F_58 ( V_15 -> V_18 . V_11 . V_58 . V_59 ) ) ;
F_39 ( & V_15 -> V_135 ) ;
V_23 = F_4 ( V_9 , V_15 ) ;
if ( V_23 ) {
V_149 = F_50 ( & V_15 -> V_134 ,
struct V_148 , V_150 ) ;
-- V_15 -> V_92 [ V_149 -> V_92 ] . V_152 ;
F_51 ( & V_149 -> V_150 ) ;
F_51 ( & V_149 -> V_151 ) ;
F_40 ( V_149 ) ;
F_34 ( & V_15 -> V_129 ) ;
F_34 ( & V_9 -> V_128 ) ;
F_29 ( V_15 , 0 ) ;
return NULL ;
}
F_33 ( & V_15 -> V_130 ) ;
F_62 ( V_9 -> V_27 , V_9 -> V_32 , & V_15 -> V_132 . V_133 ) ;
F_34 ( & V_15 -> V_129 ) ;
F_34 ( & V_9 -> V_128 ) ;
return V_15 ;
} else {
struct V_148 * V_171 , * V_172 ;
F_51 ( & V_15 -> V_135 ) ;
if ( ! F_36 ( & V_15 -> V_134 ) && V_15 -> V_2 != V_3 )
F_63 ( & V_15 -> V_66 ) ;
F_64 (tmp1, tmp2, &group->pending_list, group_list) {
F_51 ( & V_171 -> V_150 ) ;
F_40 ( V_171 ) ;
}
F_34 ( & V_15 -> V_129 ) ;
F_34 ( & V_9 -> V_128 ) ;
F_40 ( V_15 ) ;
return NULL ;
}
}
F_34 ( & V_15 -> V_129 ) ;
}
F_34 ( & V_9 -> V_128 ) ;
return NULL ;
}
static struct V_7 * F_65 ( struct V_8 * V_9 ,
union V_10 * V_11 , int V_173 ,
T_5 V_174 )
{
struct V_7 * V_15 , * V_23 ;
int V_175 ;
int V_137 ;
V_175 = ! memcmp ( & V_131 , V_11 , sizeof V_131 ) ;
if ( ! V_175 ) {
V_15 = F_2 ( V_9 , V_11 ) ;
if ( V_15 )
goto V_176;
}
if ( ! V_173 )
return F_66 ( - V_177 ) ;
V_15 = F_67 ( sizeof *V_15 , V_174 ) ;
if ( ! V_15 )
return F_66 ( - V_178 ) ;
V_15 -> V_60 = V_9 ;
V_15 -> V_18 . V_11 = * V_11 ;
F_68 ( & V_15 -> V_134 ) ;
F_68 ( & V_15 -> V_135 ) ;
for ( V_137 = 0 ; V_137 < V_179 ; ++ V_137 )
F_68 ( & V_15 -> V_92 [ V_137 ] . V_180 ) ;
F_69 ( & V_15 -> V_145 , F_56 ) ;
F_70 ( & V_15 -> V_66 , F_46 ) ;
F_71 ( & V_15 -> V_129 ) ;
sprintf ( V_15 -> V_169 , L_11 ,
F_58 ( V_15 -> V_18 . V_11 . V_58 . V_170 ) ,
F_58 ( V_15 -> V_18 . V_11 . V_58 . V_59 ) ) ;
F_72 ( & V_15 -> V_132 . V_133 ) ;
V_15 -> V_132 . V_181 = V_182 ;
V_15 -> V_132 . V_183 = NULL ;
V_15 -> V_132 . V_133 . V_169 = V_15 -> V_169 ;
V_15 -> V_132 . V_133 . V_184 = 0400 ;
V_15 -> V_2 = V_3 ;
if ( V_175 ) {
F_73 ( & V_15 -> V_135 , & V_9 -> V_185 ) ;
goto V_176;
}
V_23 = F_4 ( V_9 , V_15 ) ;
if ( V_23 ) {
F_74 ( L_12 , V_23 -> V_169 ) ;
F_40 ( V_15 ) ;
return F_66 ( - V_45 ) ;
}
F_62 ( V_9 -> V_27 , V_9 -> V_32 , & V_15 -> V_132 . V_133 ) ;
V_176:
F_33 ( & V_15 -> V_130 ) ;
return V_15 ;
}
static void F_75 ( struct V_148 * V_149 )
{
struct V_7 * V_15 = V_149 -> V_15 ;
F_33 ( & V_15 -> V_130 ) ;
F_33 ( & V_15 -> V_130 ) ;
F_76 ( & V_149 -> V_150 , & V_15 -> V_134 ) ;
F_76 ( & V_149 -> V_151 , & V_15 -> V_92 [ V_149 -> V_92 ] . V_180 ) ;
if ( ! F_52 ( V_15 -> V_60 -> V_65 , & V_15 -> V_145 ) )
F_53 ( & V_15 -> V_130 ) ;
}
int F_77 ( struct V_186 * V_187 , int V_32 , int V_36 ,
struct V_52 * V_25 )
{
struct V_26 * V_27 = F_78 ( V_187 ) ;
struct V_54 * V_18 = (struct V_54 * ) V_25 -> V_56 ;
struct V_8 * V_9 = & V_27 -> V_188 . V_60 [ V_32 - 1 ] ;
struct V_7 * V_15 ;
switch ( V_25 -> V_62 . V_74 ) {
case V_91 :
case V_161 :
F_30 ( & V_9 -> V_128 ) ;
V_15 = F_65 ( V_9 , & V_18 -> V_11 , 0 , V_189 ) ;
F_34 ( & V_9 -> V_128 ) ;
if ( F_79 ( V_15 ) ) {
if ( V_25 -> V_62 . V_74 == V_91 ) {
T_4 V_63 = V_25 -> V_62 . V_63 ;
* ( T_1 * ) ( & V_63 ) = ( T_1 ) V_36 ;
V_15 = F_59 ( V_9 , V_63 , & V_18 -> V_11 ) ;
} else
V_15 = NULL ;
}
if ( ! V_15 )
return 1 ;
F_30 ( & V_15 -> V_129 ) ;
V_15 -> V_159 = * V_25 ;
V_15 -> V_156 = V_15 -> V_2 ;
V_15 -> V_2 = V_6 ;
F_33 ( & V_15 -> V_130 ) ;
if ( ! F_52 ( V_9 -> V_65 , & V_15 -> V_145 ) )
F_53 ( & V_15 -> V_130 ) ;
F_34 ( & V_15 -> V_129 ) ;
F_29 ( V_15 , 0 ) ;
return 1 ;
case V_190 :
case V_191 :
case V_192 :
case V_75 :
return 0 ;
default:
F_74 ( L_13 ,
V_32 , V_25 -> V_62 . V_74 ) ;
return 1 ;
}
}
int F_80 ( struct V_186 * V_187 , int V_32 ,
int V_36 , struct V_52 * V_53 )
{
struct V_26 * V_27 = F_78 ( V_187 ) ;
struct V_54 * V_18 = (struct V_54 * ) V_53 -> V_56 ;
struct V_8 * V_9 = & V_27 -> V_188 . V_60 [ V_32 - 1 ] ;
struct V_7 * V_15 ;
struct V_148 * V_149 ;
int V_193 = 0 ;
if ( V_9 -> V_162 )
return - V_33 ;
switch ( V_53 -> V_62 . V_74 ) {
case V_190 :
V_193 = 1 ;
case V_75 :
V_149 = F_67 ( sizeof *V_149 , V_189 ) ;
if ( ! V_149 )
return - V_178 ;
V_149 -> V_92 = V_36 ;
V_149 -> V_53 = * V_53 ;
F_30 ( & V_9 -> V_128 ) ;
V_15 = F_65 ( V_9 , & V_18 -> V_11 , V_193 , V_189 ) ;
F_34 ( & V_9 -> V_128 ) ;
if ( F_79 ( V_15 ) ) {
F_40 ( V_149 ) ;
return F_81 ( V_15 ) ;
}
F_30 ( & V_15 -> V_129 ) ;
if ( V_15 -> V_92 [ V_36 ] . V_152 > V_194 ) {
F_34 ( & V_15 -> V_129 ) ;
F_37 ( V_15 , L_14 ,
V_32 , V_36 , V_194 ) ;
F_29 ( V_15 , 0 ) ;
F_40 ( V_149 ) ;
return - V_178 ;
}
++ V_15 -> V_92 [ V_36 ] . V_152 ;
V_149 -> V_15 = V_15 ;
F_75 ( V_149 ) ;
F_34 ( & V_15 -> V_129 ) ;
F_29 ( V_15 , 0 ) ;
return 1 ;
case V_191 :
case V_91 :
case V_192 :
case V_161 :
return 0 ;
default:
F_74 ( L_15 ,
V_32 , V_36 , V_53 -> V_62 . V_74 ) ;
return 1 ;
}
}
static T_6 V_182 ( struct V_195 * V_27 ,
struct V_196 * V_133 , char * V_197 )
{
struct V_7 * V_15 =
F_48 ( V_133 , struct V_7 , V_132 ) ;
struct V_148 * V_149 = NULL ;
char V_198 [ 40 ] ;
char V_199 [ 40 ] ;
T_6 V_200 = 0 ;
int V_201 ;
if ( V_15 -> V_2 == V_3 )
sprintf ( V_199 , L_16 , F_1 ( V_15 -> V_2 ) ) ;
else
sprintf ( V_199 , L_17 ,
F_1 ( V_15 -> V_2 ) ,
F_58 ( V_15 -> V_64 ) ) ;
if ( F_36 ( & V_15 -> V_134 ) ) {
sprintf ( V_198 , L_18 ) ;
} else {
V_149 = F_50 ( & V_15 -> V_134 , struct V_148 , V_150 ) ;
sprintf ( V_198 , L_19 ,
F_58 ( V_149 -> V_53 . V_62 . V_63 ) ) ;
}
V_200 += sprintf ( V_197 + V_200 , L_20 ,
V_15 -> V_18 . V_88 & 0xf ,
V_15 -> V_138 [ 2 ] , V_15 -> V_138 [ 1 ] , V_15 -> V_138 [ 0 ] ,
F_82 ( & V_15 -> V_130 ) ,
V_198 ,
V_199 ) ;
for ( V_201 = 0 ; V_201 < V_179 ; ++ V_201 )
if ( V_15 -> V_92 [ V_201 ] . V_2 == V_141 )
V_200 += sprintf ( V_197 + V_200 , L_21 ,
V_201 , V_15 -> V_92 [ V_201 ] . V_68 ) ;
V_200 += sprintf ( V_197 + V_200 , L_22
L_23 ,
F_57 ( V_15 -> V_18 . V_114 ) ,
F_28 ( V_15 -> V_18 . V_105 ) ,
( V_15 -> V_18 . V_110 & 0xc0 ) >> 6 ,
V_15 -> V_18 . V_110 & 0x3f ,
V_15 -> V_18 . V_112 ,
( V_15 -> V_18 . V_117 & 0xc0 ) >> 6 ,
V_15 -> V_18 . V_117 & 0x3f ,
( F_28 ( V_15 -> V_18 . V_122 ) & 0xf0000000 ) >> 28 ,
( F_28 ( V_15 -> V_18 . V_122 ) & 0x0fffff00 ) >> 8 ,
F_28 ( V_15 -> V_18 . V_122 ) & 0x000000ff ,
V_15 -> V_18 . V_202 ) ;
return V_200 ;
}
int F_83 ( struct V_8 * V_9 )
{
char V_169 [ 20 ] ;
F_84 ( & V_9 -> V_63 , 0 ) ;
sprintf ( V_169 , L_24 , V_9 -> V_32 ) ;
V_9 -> V_65 = F_85 ( V_169 ) ;
if ( ! V_9 -> V_65 )
return - V_178 ;
F_71 ( & V_9 -> V_128 ) ;
V_9 -> V_14 = V_203 ;
F_68 ( & V_9 -> V_185 ) ;
V_9 -> V_162 = 0 ;
return 0 ;
}
static void F_86 ( struct V_7 * V_15 )
{
struct V_148 * V_149 , * V_204
;
F_64 (req, tmp, &group->pending_list, group_list) {
F_51 ( & V_149 -> V_150 ) ;
F_40 ( V_149 ) ;
}
F_35 ( V_15 -> V_60 -> V_27 , V_15 -> V_60 -> V_32 , & V_15 -> V_132 . V_133 ) ;
F_38 ( & V_15 -> V_13 , & V_15 -> V_60 -> V_14 ) ;
F_40 ( V_15 ) ;
}
static void F_87 ( struct V_8 * V_9 , int V_205 )
{
int V_137 ;
struct V_12 * V_206 ;
struct V_7 * V_15 ;
unsigned long V_207 ;
int V_208 ;
for ( V_137 = 0 ; V_137 < V_179 ; ++ V_137 )
F_88 ( V_9 , V_137 ) ;
V_207 = V_209 + F_20 ( V_67 + 3000 ) ;
do {
V_208 = 0 ;
F_30 ( & V_9 -> V_128 ) ;
for ( V_206 = F_89 ( & V_9 -> V_14 ) ; V_206 ; V_206 = F_90 ( V_206 ) )
++ V_208 ;
F_34 ( & V_9 -> V_128 ) ;
if ( ! V_208 )
break;
F_91 ( 1 ) ;
} while ( F_92 ( V_207 , V_209 ) );
F_93 ( V_9 -> V_65 ) ;
if ( V_205 )
F_94 ( V_9 -> V_65 ) ;
F_30 ( & V_9 -> V_128 ) ;
while ( ( V_206 = F_89 ( & V_9 -> V_14 ) ) != NULL ) {
V_15 = F_3 ( V_206 , struct V_7 , V_13 ) ;
if ( F_82 ( & V_15 -> V_130 ) )
F_37 ( V_15 , L_25 , F_82 ( & V_15 -> V_130 ) , V_15 ) ;
F_86 ( V_15 ) ;
}
F_34 ( & V_9 -> V_128 ) ;
}
static void F_95 ( struct V_144 * V_145 )
{
struct V_210 * V_211 = F_48 ( V_145 , struct V_210 , V_145 ) ;
F_87 ( V_211 -> V_9 , V_211 -> V_205 ) ;
V_211 -> V_9 -> V_162 = 0 ;
F_40 ( V_211 ) ;
}
void F_96 ( struct V_8 * V_9 , int V_205 )
{
struct V_210 * V_145 ;
if ( V_9 -> V_162 )
return;
V_9 -> V_162 = 1 ;
if ( V_205 ) {
F_87 ( V_9 , V_205 ) ;
V_9 -> V_162 = 0 ;
return;
}
V_145 = F_97 ( sizeof *V_145 , V_189 ) ;
if ( ! V_145 ) {
V_9 -> V_162 = 0 ;
F_74 ( L_26 ) ;
return;
}
V_145 -> V_9 = V_9 ;
V_145 -> V_205 = V_205 ;
F_69 ( & V_145 -> V_145 , F_95 ) ;
F_52 ( V_212 , & V_145 -> V_145 ) ;
}
static void F_98 ( struct V_148 * V_149 )
{
struct V_52 * V_25 = & V_149 -> V_53 ;
V_25 -> V_62 . V_74 = V_75 ;
}
static void F_99 ( struct V_7 * V_15 , int V_213 )
{
struct V_148 * V_149 , * V_204 , * V_214 = NULL ;
int V_215 ;
int V_216 = 0 ;
if ( ! F_36 ( & V_15 -> V_134 ) )
V_214 = F_50 ( & V_15 -> V_134 , struct V_148 , V_150 ) ;
F_64 (req, tmp, &group->func[vf].pending, func_list) {
V_215 = 1 ;
if ( V_214 == V_149 &&
( V_15 -> V_2 == V_4 ||
V_15 -> V_2 == V_5 ) ) {
V_215 = F_32 ( & V_15 -> V_66 ) ;
V_216 = ! V_215 ;
V_15 -> V_2 = V_3 ;
}
if ( V_215 ) {
-- V_15 -> V_92 [ V_213 ] . V_152 ;
F_51 ( & V_149 -> V_150 ) ;
F_51 ( & V_149 -> V_151 ) ;
F_40 ( V_149 ) ;
F_100 ( & V_15 -> V_130 ) ;
}
}
if ( ! V_216 && ( ! F_36 ( & V_15 -> V_92 [ V_213 ] . V_180 ) || V_15 -> V_92 [ V_213 ] . V_152 ) ) {
F_37 ( V_15 , L_27 ,
F_36 ( & V_15 -> V_92 [ V_213 ] . V_180 ) , V_15 -> V_92 [ V_213 ] . V_152 ) ;
}
}
static int F_101 ( struct V_7 * V_15 , int V_36 )
{
struct V_148 * V_149 ;
struct V_148 * V_217 ;
if ( ! V_15 -> V_92 [ V_36 ] . V_68 )
return 0 ;
V_149 = F_67 ( sizeof *V_149 , V_189 ) ;
if ( ! V_149 ) {
F_37 ( V_15 , L_28 ) ;
return - V_178 ;
}
if ( ! F_36 ( & V_15 -> V_92 [ V_36 ] . V_180 ) ) {
V_217 = F_61 ( V_15 -> V_92 [ V_36 ] . V_180 . V_218 , struct V_148 , V_150 ) ;
if ( V_217 -> V_153 ) {
F_40 ( V_149 ) ;
return 0 ;
}
}
V_149 -> V_153 = 1 ;
V_149 -> V_92 = V_36 ;
V_149 -> V_15 = V_15 ;
++ V_15 -> V_92 [ V_36 ] . V_152 ;
F_98 ( V_149 ) ;
F_75 ( V_149 ) ;
return 0 ;
}
void F_88 ( struct V_8 * V_9 , int V_36 )
{
struct V_7 * V_15 ;
struct V_12 * V_206 ;
F_30 ( & V_9 -> V_128 ) ;
for ( V_206 = F_89 ( & V_9 -> V_14 ) ; V_206 ; V_206 = F_90 ( V_206 ) ) {
V_15 = F_3 ( V_206 , struct V_7 , V_13 ) ;
F_30 ( & V_15 -> V_129 ) ;
if ( F_82 ( & V_15 -> V_130 ) ) {
F_99 ( V_15 , V_36 ) ;
F_101 ( V_15 , V_36 ) ;
}
F_34 ( & V_15 -> V_129 ) ;
}
F_34 ( & V_9 -> V_128 ) ;
}
int F_102 ( void )
{
V_212 = F_85 ( L_29 ) ;
if ( ! V_212 )
return - V_178 ;
return 0 ;
}
void F_103 ( void )
{
F_94 ( V_212 ) ;
}

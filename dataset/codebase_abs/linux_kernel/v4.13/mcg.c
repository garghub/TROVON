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
unsigned long V_30 ;
F_8 ( & V_27 -> V_31 , V_30 ) ;
if ( ! V_27 -> V_32 [ V_9 -> V_33 - 1 ] ) {
F_9 ( & V_27 -> V_31 , V_30 ) ;
return - V_34 ;
}
F_10 ( V_27 -> V_32 [ V_9 -> V_33 - 1 ] , & V_29 ) ;
F_9 ( & V_27 -> V_31 , V_30 ) ;
return F_11 ( V_27 , F_12 ( V_27 -> V_27 ) ,
V_9 -> V_33 , V_35 , 0 , 1 , V_36 ,
& V_29 , NULL , 0xffff , V_25 ) ;
}
static int F_13 ( int V_37 , struct V_8 * V_9 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = V_9 -> V_27 ;
struct V_38 * V_39 = V_27 -> V_40 [ V_9 -> V_33 - 1 ] [ 1 ] ;
struct V_41 V_42 ;
struct V_28 V_29 ;
if ( ! V_39 )
return - V_34 ;
F_14 ( V_27 -> V_32 [ V_9 -> V_33 - 1 ] , & V_29 ) ;
if ( F_15 ( & V_27 -> V_43 , V_9 -> V_33 , V_44 , & V_42 . V_45 ) )
return - V_46 ;
V_42 . V_47 = 0 ;
V_42 . V_48 = 0 ;
V_42 . V_49 = V_9 -> V_33 ;
V_42 . V_50 = F_16 ( & V_29 ) ;
V_42 . V_51 = 1 ;
return F_17 ( V_27 , V_37 , V_9 -> V_33 , V_35 , & V_42 , NULL , V_25 ) ;
}
static int F_18 ( struct V_7 * V_15 , struct V_52 * V_53 )
{
struct V_52 V_25 ;
struct V_54 * V_55 = (struct V_54 * ) & V_25 . V_56 ;
int V_16 ;
memcpy ( & V_25 , V_53 , sizeof V_25 ) ;
V_55 -> V_57 . V_58 . V_59 = V_15 -> V_60 -> V_61 [ 0 ] ;
V_25 . V_62 . V_63 = F_19 ( V_15 -> V_60 ) ;
V_15 -> V_64 = V_25 . V_62 . V_63 ;
V_16 = F_7 ( V_15 -> V_60 , (struct V_24 * ) & V_25 ) ;
if ( ! V_16 ) {
F_20 ( V_15 -> V_60 -> V_65 , & V_15 -> V_66 ,
F_21 ( V_67 ) ) ;
}
return V_16 ;
}
static int F_22 ( struct V_7 * V_15 , T_1 V_68 )
{
struct V_52 V_25 ;
struct V_54 * V_69 = (struct V_54 * ) & V_25 . V_56 ;
int V_16 ;
memset ( & V_25 , 0 , sizeof V_25 ) ;
V_25 . V_62 . V_70 = 1 ;
V_25 . V_62 . V_71 = V_72 ;
V_25 . V_62 . V_73 = 2 ;
V_25 . V_62 . V_74 = V_75 ;
V_25 . V_62 . V_76 = F_23 ( 0 ) ;
V_25 . V_62 . V_77 = F_23 ( 0 ) ;
V_25 . V_62 . V_63 = F_19 ( V_15 -> V_60 ) ;
V_15 -> V_64 = V_25 . V_62 . V_63 ;
V_25 . V_62 . V_78 = F_23 ( V_79 ) ;
V_25 . V_62 . V_80 = F_24 ( 0 ) ;
V_25 . V_81 . V_82 = 0x0 ;
V_25 . V_81 . V_83 = F_23 ( 7 ) ;
V_25 . V_81 . V_84 = V_85 |
V_86 | V_87 ;
* V_69 = V_15 -> V_18 ;
V_69 -> V_88 = V_68 ;
V_16 = F_7 ( V_15 -> V_60 , (struct V_24 * ) & V_25 ) ;
if ( V_16 )
V_15 -> V_2 = V_3 ;
if ( ! V_16 ) {
F_20 ( V_15 -> V_60 -> V_65 , & V_15 -> V_66 ,
F_21 ( V_67 ) ) ;
}
return V_16 ;
}
static int F_25 ( int V_37 , struct V_7 * V_15 ,
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
V_25 . V_62 . V_76 = F_23 ( V_76 ) ;
V_25 . V_62 . V_77 = F_23 ( 0 ) ;
V_25 . V_62 . V_63 = V_89 -> V_62 . V_63 ;
* ( T_1 * ) & V_25 . V_62 . V_63 = 0 ;
V_25 . V_62 . V_78 = F_23 ( V_79 ) ;
V_25 . V_62 . V_80 = F_24 ( 0 ) ;
V_25 . V_81 . V_82 = V_89 -> V_81 . V_82 ;
V_25 . V_81 . V_83 = F_23 ( 7 ) ;
V_25 . V_81 . V_84 = 0 ;
* V_69 = V_15 -> V_18 ;
V_69 -> V_88 &= 0xf0 ;
V_69 -> V_88 |= ( V_15 -> V_92 [ V_37 ] . V_68 & 0x0f ) ;
memcpy ( & V_69 -> V_57 , & V_90 -> V_57 , sizeof V_90 -> V_57 ) ;
V_16 = F_13 ( V_37 , V_15 -> V_60 , (struct V_24 * ) & V_25 ) ;
return V_16 ;
}
static int F_26 ( T_3 V_84 ,
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
static T_2 F_27 ( struct V_54 * V_102 ,
struct V_54 * V_103 , T_3 V_84 )
{
#define F_28 0x0200
if ( V_84 & V_104 && V_102 -> V_105 != V_103 -> V_105 )
return F_28 ;
if ( V_84 & V_106 && V_102 -> V_107 != V_103 -> V_107 )
return F_28 ;
if ( F_26 ( V_84 , V_108 ,
V_109 ,
V_102 -> V_110 , V_103 -> V_110 ) )
return F_28 ;
if ( V_84 & V_111 &&
V_102 -> V_112 != V_103 -> V_112 )
return F_28 ;
if ( V_84 & V_113 && V_102 -> V_114 != V_103 -> V_114 )
return F_28 ;
if ( F_26 ( V_84 , V_115 ,
V_116 ,
V_102 -> V_117 , V_103 -> V_117 ) )
return F_28 ;
if ( F_26 ( V_84 ,
V_118 ,
V_119 ,
V_102 -> V_120 , V_103 -> V_120 ) )
return F_28 ;
if ( V_84 & V_121 &&
( F_29 ( V_102 -> V_122 ) & 0xf0000000 ) !=
( F_29 ( V_103 -> V_122 ) & 0xf0000000 ) )
return F_28 ;
if ( V_84 & V_123 &&
( F_29 ( V_102 -> V_122 ) & 0x0fffff00 ) !=
( F_29 ( V_103 -> V_122 ) & 0x0fffff00 ) )
return F_28 ;
if ( V_84 & V_124 &&
( F_29 ( V_102 -> V_122 ) & 0x000000ff ) !=
( F_29 ( V_103 -> V_122 ) & 0x000000ff ) )
return F_28 ;
if ( V_84 & V_125 &&
( V_102 -> V_88 & 0xf0 ) !=
( V_103 -> V_88 & 0xf0 ) )
return F_28 ;
return 0 ;
}
static int F_30 ( struct V_7 * V_15 , int V_126 )
{
struct V_8 * V_9 = V_15 -> V_60 ;
int V_127 ;
F_31 ( & V_9 -> V_128 ) ;
F_31 ( & V_15 -> V_129 ) ;
if ( F_32 ( & V_15 -> V_130 ) ) {
if ( ! V_126 ) {
if ( V_15 -> V_2 != V_3 &&
! F_33 ( & V_15 -> V_66 ) ) {
F_34 ( & V_15 -> V_130 ) ;
F_35 ( & V_15 -> V_129 ) ;
F_35 ( & V_9 -> V_128 ) ;
return 0 ;
}
}
V_127 = memcmp ( & V_15 -> V_18 . V_11 , & V_131 , sizeof V_131 ) ;
if ( V_127 )
F_36 ( V_9 -> V_27 , V_9 -> V_33 , & V_15 -> V_132 . V_133 ) ;
if ( ! F_37 ( & V_15 -> V_134 ) )
F_38 ( V_15 , L_6 ) ;
if ( V_127 )
F_39 ( & V_15 -> V_13 , & V_9 -> V_14 ) ;
F_40 ( & V_15 -> V_135 ) ;
F_35 ( & V_15 -> V_129 ) ;
F_35 ( & V_9 -> V_128 ) ;
F_41 ( V_15 ) ;
return 1 ;
} else {
F_35 ( & V_15 -> V_129 ) ;
F_35 ( & V_9 -> V_128 ) ;
}
return 0 ;
}
static void F_42 ( struct V_7 * V_15 , T_1 V_68 , int V_136 )
{
int V_137 ;
for ( V_137 = 0 ; V_137 < 3 ; V_137 ++ , V_68 >>= 1 )
if ( V_68 & 0x1 )
V_15 -> V_138 [ V_137 ] += V_136 ;
}
static T_1 F_43 ( struct V_7 * V_15 )
{
T_1 V_139 = 0 ;
int V_137 ;
for ( V_137 = 0 ; V_137 < 3 ; V_137 ++ )
if ( ! V_15 -> V_138 [ V_137 ] )
V_139 |= ( 1 << V_137 ) ;
return V_139 & ( V_15 -> V_18 . V_88 & 0xf ) ;
}
static int F_44 ( struct V_7 * V_15 , int V_37 , T_1 V_140 )
{
int V_16 = 0 ;
T_1 V_68 ;
V_68 = V_140 & ( ~ V_15 -> V_92 [ V_37 ] . V_68 ) ;
F_42 ( V_15 , V_68 , 1 ) ;
V_15 -> V_92 [ V_37 ] . V_68 |= V_68 ;
if ( V_15 -> V_92 [ V_37 ] . V_2 != V_141 && V_68 ) {
V_15 -> V_92 [ V_37 ] . V_2 = V_141 ;
V_16 = 1 ;
}
return V_16 ;
}
static int F_45 ( struct V_7 * V_15 , int V_37 , T_1 V_139 )
{
int V_16 = 0 ;
F_42 ( V_15 , V_139 , - 1 ) ;
V_15 -> V_92 [ V_37 ] . V_68 &= ~ V_139 ;
if ( ! V_15 -> V_92 [ V_37 ] . V_68 ) {
V_15 -> V_92 [ V_37 ] . V_2 = V_142 ;
V_16 = 1 ;
}
return V_16 ;
}
static int F_46 ( struct V_7 * V_15 , int V_37 , T_1 V_143 )
{
if ( V_15 -> V_92 [ V_37 ] . V_2 != V_141 )
return F_28 ;
if ( ~ V_15 -> V_92 [ V_37 ] . V_68 & V_143 )
return F_28 ;
if ( ! V_143 )
return F_28 ;
return 0 ;
}
static void F_47 ( struct V_144 * V_145 )
{
struct V_146 * V_147 = F_48 ( V_145 ) ;
struct V_7 * V_15 ;
struct V_148 * V_149 = NULL ;
V_15 = F_49 ( V_147 , F_50 ( * V_15 ) , V_66 ) ;
F_31 ( & V_15 -> V_129 ) ;
if ( V_15 -> V_2 == V_4 ) {
if ( ! F_37 ( & V_15 -> V_134 ) ) {
V_149 = F_51 ( & V_15 -> V_134 , struct V_148 , V_150 ) ;
F_52 ( & V_149 -> V_150 ) ;
F_52 ( & V_149 -> V_151 ) ;
-- V_15 -> V_92 [ V_149 -> V_92 ] . V_152 ;
F_35 ( & V_15 -> V_129 ) ;
F_41 ( V_149 ) ;
if ( memcmp ( & V_15 -> V_18 . V_11 , & V_131 , sizeof V_131 ) ) {
if ( F_30 ( V_15 , 1 ) )
return;
} else {
F_41 ( V_15 ) ;
return;
}
F_31 ( & V_15 -> V_129 ) ;
} else
F_38 ( V_15 , L_7 ) ;
} else if ( V_15 -> V_2 == V_5 ) {
if ( V_15 -> V_18 . V_88 & 0xf )
V_15 -> V_18 . V_88 &= 0xf0 ;
V_15 -> V_2 = V_3 ;
F_35 ( & V_15 -> V_129 ) ;
if ( F_30 ( V_15 , 1 ) )
return;
F_31 ( & V_15 -> V_129 ) ;
} else
F_38 ( V_15 , L_8 , F_1 ( V_15 -> V_2 ) ) ;
V_15 -> V_2 = V_3 ;
F_34 ( & V_15 -> V_130 ) ;
if ( ! F_53 ( V_15 -> V_60 -> V_65 , & V_15 -> V_145 ) )
F_54 ( & V_15 -> V_130 ) ;
F_35 ( & V_15 -> V_129 ) ;
}
static int F_55 ( struct V_7 * V_15 , T_1 V_143 ,
struct V_148 * V_149 )
{
T_2 V_76 ;
if ( V_149 -> V_153 )
V_143 = V_15 -> V_92 [ V_149 -> V_92 ] . V_68 ;
V_76 = F_46 ( V_15 , V_149 -> V_92 , V_143 ) ;
if ( ! V_76 )
F_45 ( V_15 , V_149 -> V_92 , V_143 ) ;
if ( ! V_149 -> V_153 )
F_25 ( V_149 -> V_92 , V_15 , & V_149 -> V_53 , V_76 ) ;
-- V_15 -> V_92 [ V_149 -> V_92 ] . V_152 ;
F_52 ( & V_149 -> V_150 ) ;
F_52 ( & V_149 -> V_151 ) ;
F_41 ( V_149 ) ;
return 1 ;
}
static int F_56 ( struct V_7 * V_15 , T_1 V_140 ,
struct V_148 * V_149 )
{
T_1 V_154 = V_15 -> V_18 . V_88 & 0xf ;
int V_155 = 0 ;
T_2 V_76 ;
struct V_54 * V_69 = (struct V_54 * ) V_149 -> V_53 . V_56 ;
if ( V_140 == ( V_154 & V_140 ) ) {
V_76 = F_27 ( & V_15 -> V_18 , V_69 , V_149 -> V_53 . V_81 . V_84 ) ;
if ( ! V_76 )
F_44 ( V_15 , V_149 -> V_92 , V_140 ) ;
-- V_15 -> V_92 [ V_149 -> V_92 ] . V_152 ;
F_25 ( V_149 -> V_92 , V_15 , & V_149 -> V_53 , V_76 ) ;
F_52 ( & V_149 -> V_150 ) ;
F_52 ( & V_149 -> V_151 ) ;
F_41 ( V_149 ) ;
++ V_155 ;
} else {
V_15 -> V_156 = V_15 -> V_2 ;
if ( F_18 ( V_15 , & V_149 -> V_53 ) ) {
-- V_15 -> V_92 [ V_149 -> V_92 ] . V_152 ;
F_52 ( & V_149 -> V_150 ) ;
F_52 ( & V_149 -> V_151 ) ;
F_41 ( V_149 ) ;
V_155 = 1 ;
V_15 -> V_2 = V_15 -> V_156 ;
} else
V_15 -> V_2 = V_4 ;
}
return V_155 ;
}
static void F_57 ( struct V_144 * V_145 )
{
struct V_7 * V_15 ;
struct V_148 * V_149 = NULL ;
struct V_54 * V_69 ;
T_1 V_157 ;
int V_158 = 1 ;
T_2 V_76 ;
T_1 V_74 ;
V_15 = F_49 ( V_145 , F_50 ( * V_15 ) , V_145 ) ;
F_31 ( & V_15 -> V_129 ) ;
if ( V_15 -> V_2 == V_6 ) {
F_33 ( & V_15 -> V_66 ) ;
V_76 = F_58 ( V_15 -> V_159 . V_62 . V_76 ) ;
V_74 = V_15 -> V_159 . V_62 . V_74 ;
if ( V_15 -> V_64 != V_15 -> V_159 . V_62 . V_63 ) {
F_38 ( V_15 , L_9 ,
F_59 ( V_15 -> V_159 . V_62 . V_63 ) ,
F_59 ( V_15 -> V_64 ) ) ;
V_15 -> V_2 = V_15 -> V_156 ;
goto V_160;
}
if ( V_76 ) {
if ( ! F_37 ( & V_15 -> V_134 ) )
V_149 = F_51 ( & V_15 -> V_134 ,
struct V_148 , V_150 ) ;
if ( ( V_74 == V_91 ) ) {
if ( V_149 ) {
F_25 ( V_149 -> V_92 , V_15 , & V_149 -> V_53 , V_76 ) ;
-- V_15 -> V_92 [ V_149 -> V_92 ] . V_152 ;
F_52 ( & V_149 -> V_150 ) ;
F_52 ( & V_149 -> V_151 ) ;
F_41 ( V_149 ) ;
++ V_158 ;
} else
F_38 ( V_15 , L_10 ) ;
} else if ( V_74 == V_161 && V_15 -> V_60 -> V_162 )
++ V_158 ;
} else {
T_1 V_163 ;
T_1 V_164 ;
V_163 = ( (struct V_54 * )
V_15 -> V_159 . V_56 ) -> V_88 & 0xf ;
V_164 = V_15 -> V_18 . V_88 & 0xf ;
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
while ( ! F_37 ( & V_15 -> V_134 ) && V_15 -> V_2 == V_3 ) {
V_149 = F_51 ( & V_15 -> V_134 , struct V_148 ,
V_150 ) ;
V_69 = (struct V_54 * ) V_149 -> V_53 . V_56 ;
V_157 = V_69 -> V_88 & 0xf ;
if ( V_149 -> V_53 . V_62 . V_74 == V_75 )
V_158 += F_55 ( V_15 , V_157 , V_149 ) ;
else
V_158 += F_56 ( V_15 , V_157 , V_149 ) ;
}
if ( V_15 -> V_2 == V_3 ) {
V_157 = F_43 ( V_15 ) ;
if ( V_157 ) {
V_15 -> V_18 . V_88 &= ~ V_157 ;
V_15 -> V_156 = V_15 -> V_2 ;
if ( F_22 ( V_15 , V_157 ) ) {
V_15 -> V_2 = V_15 -> V_156 ;
++ V_158 ;
} else
V_15 -> V_2 = V_5 ;
}
}
if ( ! F_37 ( & V_15 -> V_134 ) && V_15 -> V_2 == V_3 )
goto V_160;
F_35 ( & V_15 -> V_129 ) ;
while ( V_158 -- )
F_30 ( V_15 , 0 ) ;
}
static struct V_7 * F_60 ( struct V_8 * V_9 ,
T_4 V_63 ,
union V_10 * V_165 )
{
struct V_7 * V_15 = NULL , * V_23 , * V_166 ;
struct V_148 * V_149 ;
F_31 ( & V_9 -> V_128 ) ;
F_61 (group, n, &ctx->mcg_mgid0_list, mgid0_list) {
F_31 ( & V_15 -> V_129 ) ;
if ( V_15 -> V_64 == V_63 ) {
if ( memcmp ( V_165 , & V_131 , sizeof V_131 ) ) {
V_15 -> V_18 . V_11 = * V_165 ;
sprintf ( V_15 -> V_167 , L_11 ,
F_59 ( V_15 -> V_18 . V_11 . V_58 . V_168 ) ,
F_59 ( V_15 -> V_18 . V_11 . V_58 . V_59 ) ) ;
F_40 ( & V_15 -> V_135 ) ;
V_23 = F_4 ( V_9 , V_15 ) ;
if ( V_23 ) {
V_149 = F_51 ( & V_15 -> V_134 ,
struct V_148 , V_150 ) ;
-- V_15 -> V_92 [ V_149 -> V_92 ] . V_152 ;
F_52 ( & V_149 -> V_150 ) ;
F_52 ( & V_149 -> V_151 ) ;
F_41 ( V_149 ) ;
F_35 ( & V_15 -> V_129 ) ;
F_35 ( & V_9 -> V_128 ) ;
F_30 ( V_15 , 0 ) ;
return NULL ;
}
F_34 ( & V_15 -> V_130 ) ;
F_62 ( V_9 -> V_27 , V_9 -> V_33 , & V_15 -> V_132 . V_133 ) ;
F_35 ( & V_15 -> V_129 ) ;
F_35 ( & V_9 -> V_128 ) ;
return V_15 ;
} else {
struct V_148 * V_169 , * V_170 ;
F_52 ( & V_15 -> V_135 ) ;
if ( ! F_37 ( & V_15 -> V_134 ) && V_15 -> V_2 != V_3 )
F_63 ( & V_15 -> V_66 ) ;
F_61 (tmp1, tmp2, &group->pending_list, group_list) {
F_52 ( & V_169 -> V_150 ) ;
F_41 ( V_169 ) ;
}
F_35 ( & V_15 -> V_129 ) ;
F_35 ( & V_9 -> V_128 ) ;
F_41 ( V_15 ) ;
return NULL ;
}
}
F_35 ( & V_15 -> V_129 ) ;
}
F_35 ( & V_9 -> V_128 ) ;
return NULL ;
}
static struct V_7 * F_64 ( struct V_8 * V_9 ,
union V_10 * V_11 , int V_171 ,
T_5 V_172 )
{
struct V_7 * V_15 , * V_23 ;
int V_173 ;
int V_137 ;
V_173 = ! memcmp ( & V_131 , V_11 , sizeof V_131 ) ;
if ( ! V_173 ) {
V_15 = F_2 ( V_9 , V_11 ) ;
if ( V_15 )
goto V_174;
}
if ( ! V_171 )
return F_65 ( - V_175 ) ;
V_15 = F_66 ( sizeof *V_15 , V_172 ) ;
if ( ! V_15 )
return F_65 ( - V_176 ) ;
V_15 -> V_60 = V_9 ;
V_15 -> V_18 . V_11 = * V_11 ;
F_67 ( & V_15 -> V_134 ) ;
F_67 ( & V_15 -> V_135 ) ;
for ( V_137 = 0 ; V_137 < V_177 ; ++ V_137 )
F_67 ( & V_15 -> V_92 [ V_137 ] . V_178 ) ;
F_68 ( & V_15 -> V_145 , F_57 ) ;
F_69 ( & V_15 -> V_66 , F_47 ) ;
F_70 ( & V_15 -> V_129 ) ;
sprintf ( V_15 -> V_167 , L_11 ,
F_59 ( V_15 -> V_18 . V_11 . V_58 . V_168 ) ,
F_59 ( V_15 -> V_18 . V_11 . V_58 . V_59 ) ) ;
F_71 ( & V_15 -> V_132 . V_133 ) ;
V_15 -> V_132 . V_179 = V_180 ;
V_15 -> V_132 . V_181 = NULL ;
V_15 -> V_132 . V_133 . V_167 = V_15 -> V_167 ;
V_15 -> V_132 . V_133 . V_182 = 0400 ;
V_15 -> V_2 = V_3 ;
if ( V_173 ) {
F_72 ( & V_15 -> V_135 , & V_9 -> V_183 ) ;
goto V_174;
}
V_23 = F_4 ( V_9 , V_15 ) ;
if ( V_23 ) {
F_73 ( L_12 , V_23 -> V_167 ) ;
F_41 ( V_15 ) ;
return F_65 ( - V_46 ) ;
}
F_62 ( V_9 -> V_27 , V_9 -> V_33 , & V_15 -> V_132 . V_133 ) ;
V_174:
F_34 ( & V_15 -> V_130 ) ;
return V_15 ;
}
static void F_74 ( struct V_148 * V_149 )
{
struct V_7 * V_15 = V_149 -> V_15 ;
F_34 ( & V_15 -> V_130 ) ;
F_34 ( & V_15 -> V_130 ) ;
F_75 ( & V_149 -> V_150 , & V_15 -> V_134 ) ;
F_75 ( & V_149 -> V_151 , & V_15 -> V_92 [ V_149 -> V_92 ] . V_178 ) ;
if ( ! F_53 ( V_15 -> V_60 -> V_65 , & V_15 -> V_145 ) )
F_54 ( & V_15 -> V_130 ) ;
}
int F_76 ( struct V_184 * V_185 , int V_33 , int V_37 ,
struct V_52 * V_25 )
{
struct V_26 * V_27 = F_77 ( V_185 ) ;
struct V_54 * V_18 = (struct V_54 * ) V_25 -> V_56 ;
struct V_8 * V_9 = & V_27 -> V_186 . V_60 [ V_33 - 1 ] ;
struct V_7 * V_15 ;
switch ( V_25 -> V_62 . V_74 ) {
case V_91 :
case V_161 :
F_31 ( & V_9 -> V_128 ) ;
V_15 = F_64 ( V_9 , & V_18 -> V_11 , 0 , V_187 ) ;
F_35 ( & V_9 -> V_128 ) ;
if ( F_78 ( V_15 ) ) {
if ( V_25 -> V_62 . V_74 == V_91 ) {
T_4 V_63 = V_25 -> V_62 . V_63 ;
* ( T_1 * ) ( & V_63 ) = ( T_1 ) V_37 ;
V_15 = F_60 ( V_9 , V_63 , & V_18 -> V_11 ) ;
} else
V_15 = NULL ;
}
if ( ! V_15 )
return 1 ;
F_31 ( & V_15 -> V_129 ) ;
V_15 -> V_159 = * V_25 ;
V_15 -> V_156 = V_15 -> V_2 ;
V_15 -> V_2 = V_6 ;
F_34 ( & V_15 -> V_130 ) ;
if ( ! F_53 ( V_9 -> V_65 , & V_15 -> V_145 ) )
F_54 ( & V_15 -> V_130 ) ;
F_35 ( & V_15 -> V_129 ) ;
F_30 ( V_15 , 0 ) ;
return 1 ;
case V_188 :
case V_189 :
case V_190 :
case V_75 :
return 0 ;
default:
F_73 ( L_13 ,
V_33 , V_25 -> V_62 . V_74 ) ;
return 1 ;
}
}
int F_79 ( struct V_184 * V_185 , int V_33 ,
int V_37 , struct V_52 * V_53 )
{
struct V_26 * V_27 = F_77 ( V_185 ) ;
struct V_54 * V_18 = (struct V_54 * ) V_53 -> V_56 ;
struct V_8 * V_9 = & V_27 -> V_186 . V_60 [ V_33 - 1 ] ;
struct V_7 * V_15 ;
struct V_148 * V_149 ;
int V_191 = 0 ;
if ( V_9 -> V_162 )
return - V_34 ;
switch ( V_53 -> V_62 . V_74 ) {
case V_188 :
V_191 = 1 ;
case V_75 :
V_149 = F_66 ( sizeof *V_149 , V_187 ) ;
if ( ! V_149 )
return - V_176 ;
V_149 -> V_92 = V_37 ;
V_149 -> V_53 = * V_53 ;
F_31 ( & V_9 -> V_128 ) ;
V_15 = F_64 ( V_9 , & V_18 -> V_11 , V_191 , V_187 ) ;
F_35 ( & V_9 -> V_128 ) ;
if ( F_78 ( V_15 ) ) {
F_41 ( V_149 ) ;
return F_80 ( V_15 ) ;
}
F_31 ( & V_15 -> V_129 ) ;
if ( V_15 -> V_92 [ V_37 ] . V_152 > V_192 ) {
F_35 ( & V_15 -> V_129 ) ;
F_81 ( V_15 , L_14 ,
V_33 , V_37 , V_192 ) ;
F_30 ( V_15 , 0 ) ;
F_41 ( V_149 ) ;
return - V_176 ;
}
++ V_15 -> V_92 [ V_37 ] . V_152 ;
V_149 -> V_15 = V_15 ;
F_74 ( V_149 ) ;
F_35 ( & V_15 -> V_129 ) ;
F_30 ( V_15 , 0 ) ;
return 1 ;
case V_189 :
case V_91 :
case V_190 :
case V_161 :
return 0 ;
default:
F_73 ( L_15 ,
V_33 , V_37 , V_53 -> V_62 . V_74 ) ;
return 1 ;
}
}
static T_6 V_180 ( struct V_193 * V_27 ,
struct V_194 * V_133 , char * V_195 )
{
struct V_7 * V_15 =
F_49 ( V_133 , struct V_7 , V_132 ) ;
struct V_148 * V_149 = NULL ;
char V_196 [ 40 ] ;
char V_197 [ 40 ] ;
T_6 V_198 = 0 ;
int V_199 ;
if ( V_15 -> V_2 == V_3 )
sprintf ( V_197 , L_16 , F_1 ( V_15 -> V_2 ) ) ;
else
sprintf ( V_197 , L_17 ,
F_1 ( V_15 -> V_2 ) ,
F_59 ( V_15 -> V_64 ) ) ;
if ( F_37 ( & V_15 -> V_134 ) ) {
sprintf ( V_196 , L_18 ) ;
} else {
V_149 = F_51 ( & V_15 -> V_134 , struct V_148 , V_150 ) ;
sprintf ( V_196 , L_19 ,
F_59 ( V_149 -> V_53 . V_62 . V_63 ) ) ;
}
V_198 += sprintf ( V_195 + V_198 , L_20 ,
V_15 -> V_18 . V_88 & 0xf ,
V_15 -> V_138 [ 2 ] , V_15 -> V_138 [ 1 ] , V_15 -> V_138 [ 0 ] ,
F_82 ( & V_15 -> V_130 ) ,
V_196 ,
V_197 ) ;
for ( V_199 = 0 ; V_199 < V_177 ; ++ V_199 )
if ( V_15 -> V_92 [ V_199 ] . V_2 == V_141 )
V_198 += sprintf ( V_195 + V_198 , L_21 ,
V_199 , V_15 -> V_92 [ V_199 ] . V_68 ) ;
V_198 += sprintf ( V_195 + V_198 , L_22
L_23 ,
F_58 ( V_15 -> V_18 . V_114 ) ,
F_29 ( V_15 -> V_18 . V_105 ) ,
( V_15 -> V_18 . V_110 & 0xc0 ) >> 6 ,
V_15 -> V_18 . V_110 & 0x3f ,
V_15 -> V_18 . V_112 ,
( V_15 -> V_18 . V_117 & 0xc0 ) >> 6 ,
V_15 -> V_18 . V_117 & 0x3f ,
( F_29 ( V_15 -> V_18 . V_122 ) & 0xf0000000 ) >> 28 ,
( F_29 ( V_15 -> V_18 . V_122 ) & 0x0fffff00 ) >> 8 ,
F_29 ( V_15 -> V_18 . V_122 ) & 0x000000ff ,
V_15 -> V_18 . V_200 ) ;
return V_198 ;
}
int F_83 ( struct V_8 * V_9 )
{
char V_167 [ 20 ] ;
F_84 ( & V_9 -> V_63 , 0 ) ;
sprintf ( V_167 , L_24 , V_9 -> V_33 ) ;
V_9 -> V_65 = F_85 ( V_167 , V_201 ) ;
if ( ! V_9 -> V_65 )
return - V_176 ;
F_70 ( & V_9 -> V_128 ) ;
V_9 -> V_14 = V_202 ;
F_67 ( & V_9 -> V_183 ) ;
V_9 -> V_162 = 0 ;
return 0 ;
}
static void F_86 ( struct V_7 * V_15 )
{
struct V_148 * V_149 , * V_203
;
F_61 (req, tmp, &group->pending_list, group_list) {
F_52 ( & V_149 -> V_150 ) ;
F_41 ( V_149 ) ;
}
F_36 ( V_15 -> V_60 -> V_27 , V_15 -> V_60 -> V_33 , & V_15 -> V_132 . V_133 ) ;
F_39 ( & V_15 -> V_13 , & V_15 -> V_60 -> V_14 ) ;
F_41 ( V_15 ) ;
}
static void F_87 ( struct V_8 * V_9 , int V_204 )
{
int V_137 ;
struct V_12 * V_205 ;
struct V_7 * V_15 ;
unsigned long V_206 ;
int V_207 ;
for ( V_137 = 0 ; V_137 < V_177 ; ++ V_137 )
F_88 ( V_9 , V_137 ) ;
V_206 = V_208 + F_21 ( V_67 + 3000 ) ;
do {
V_207 = 0 ;
F_31 ( & V_9 -> V_128 ) ;
for ( V_205 = F_89 ( & V_9 -> V_14 ) ; V_205 ; V_205 = F_90 ( V_205 ) )
++ V_207 ;
F_35 ( & V_9 -> V_128 ) ;
if ( ! V_207 )
break;
F_91 ( 1000 , 2000 ) ;
} while ( F_92 ( V_206 , V_208 ) );
F_93 ( V_9 -> V_65 ) ;
if ( V_204 )
F_94 ( V_9 -> V_65 ) ;
F_31 ( & V_9 -> V_128 ) ;
while ( ( V_205 = F_89 ( & V_9 -> V_14 ) ) != NULL ) {
V_15 = F_3 ( V_205 , struct V_7 , V_13 ) ;
if ( F_82 ( & V_15 -> V_130 ) )
F_81 ( V_15 , L_25 ,
F_82 ( & V_15 -> V_130 ) , V_15 ) ;
F_86 ( V_15 ) ;
}
F_35 ( & V_9 -> V_128 ) ;
}
static void F_95 ( struct V_144 * V_145 )
{
struct V_209 * V_210 = F_49 ( V_145 , struct V_209 , V_145 ) ;
F_87 ( V_210 -> V_9 , V_210 -> V_204 ) ;
V_210 -> V_9 -> V_162 = 0 ;
F_41 ( V_210 ) ;
}
void F_96 ( struct V_8 * V_9 , int V_204 )
{
struct V_209 * V_145 ;
if ( V_9 -> V_162 )
return;
V_9 -> V_162 = 1 ;
if ( V_204 ) {
F_87 ( V_9 , V_204 ) ;
V_9 -> V_162 = 0 ;
return;
}
V_145 = F_97 ( sizeof *V_145 , V_187 ) ;
if ( ! V_145 ) {
V_9 -> V_162 = 0 ;
return;
}
V_145 -> V_9 = V_9 ;
V_145 -> V_204 = V_204 ;
F_68 ( & V_145 -> V_145 , F_95 ) ;
F_53 ( V_211 , & V_145 -> V_145 ) ;
}
static void F_98 ( struct V_148 * V_149 )
{
struct V_52 * V_25 = & V_149 -> V_53 ;
V_25 -> V_62 . V_74 = V_75 ;
}
static void F_99 ( struct V_7 * V_15 , int V_212 )
{
struct V_148 * V_149 , * V_203 , * V_213 = NULL ;
int V_214 ;
int V_215 = 0 ;
if ( ! F_37 ( & V_15 -> V_134 ) )
V_213 = F_51 ( & V_15 -> V_134 , struct V_148 , V_150 ) ;
F_61 (req, tmp, &group->func[vf].pending, func_list) {
V_214 = 1 ;
if ( V_213 == V_149 &&
( V_15 -> V_2 == V_4 ||
V_15 -> V_2 == V_5 ) ) {
V_214 = F_33 ( & V_15 -> V_66 ) ;
V_215 = ! V_214 ;
V_15 -> V_2 = V_3 ;
}
if ( V_214 ) {
-- V_15 -> V_92 [ V_212 ] . V_152 ;
F_52 ( & V_149 -> V_150 ) ;
F_52 ( & V_149 -> V_151 ) ;
F_41 ( V_149 ) ;
F_100 ( & V_15 -> V_130 ) ;
}
}
if ( ! V_215 && ( ! F_37 ( & V_15 -> V_92 [ V_212 ] . V_178 ) || V_15 -> V_92 [ V_212 ] . V_152 ) ) {
F_38 ( V_15 , L_26 ,
F_37 ( & V_15 -> V_92 [ V_212 ] . V_178 ) , V_15 -> V_92 [ V_212 ] . V_152 ) ;
}
}
static int F_101 ( struct V_7 * V_15 , int V_37 )
{
struct V_148 * V_149 ;
struct V_148 * V_216 ;
if ( ! V_15 -> V_92 [ V_37 ] . V_68 )
return 0 ;
V_149 = F_66 ( sizeof *V_149 , V_187 ) ;
if ( ! V_149 )
return - V_176 ;
if ( ! F_37 ( & V_15 -> V_92 [ V_37 ] . V_178 ) ) {
V_216 = F_102 ( V_15 -> V_92 [ V_37 ] . V_178 . V_217 , struct V_148 , V_150 ) ;
if ( V_216 -> V_153 ) {
F_41 ( V_149 ) ;
return 0 ;
}
}
V_149 -> V_153 = 1 ;
V_149 -> V_92 = V_37 ;
V_149 -> V_15 = V_15 ;
++ V_15 -> V_92 [ V_37 ] . V_152 ;
F_98 ( V_149 ) ;
F_74 ( V_149 ) ;
return 0 ;
}
void F_88 ( struct V_8 * V_9 , int V_37 )
{
struct V_7 * V_15 ;
struct V_12 * V_205 ;
F_31 ( & V_9 -> V_128 ) ;
for ( V_205 = F_89 ( & V_9 -> V_14 ) ; V_205 ; V_205 = F_90 ( V_205 ) ) {
V_15 = F_3 ( V_205 , struct V_7 , V_13 ) ;
F_31 ( & V_15 -> V_129 ) ;
if ( F_82 ( & V_15 -> V_130 ) ) {
F_99 ( V_15 , V_37 ) ;
F_101 ( V_15 , V_37 ) ;
}
F_35 ( & V_15 -> V_129 ) ;
}
F_35 ( & V_9 -> V_128 ) ;
}
int F_103 ( void )
{
V_211 = F_85 ( L_27 , V_201 ) ;
if ( ! V_211 )
return - V_176 ;
return 0 ;
}
void F_104 ( void )
{
F_94 ( V_211 ) ;
}

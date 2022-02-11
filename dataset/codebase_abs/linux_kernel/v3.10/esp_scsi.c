static void F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 )
{
V_3 -> V_4 = V_1 -> V_4 ;
V_3 -> V_5 = V_1 -> V_5 ;
V_3 -> V_6 = V_1 -> V_6 ;
V_3 -> V_7 = V_1 -> V_7 ;
V_3 -> V_8 = V_1 -> V_8 ;
V_3 -> V_9 = V_1 -> V_9 ;
}
void F_2 ( struct V_1 * V_1 , T_1 V_10 )
{
struct V_2 * V_3 ;
int V_11 = V_1 -> V_12 ;
V_3 = & V_1 -> V_13 [ V_11 ] ;
V_3 -> type = V_14 ;
V_3 -> V_10 = V_10 ;
F_1 ( V_1 , V_3 ) ;
V_1 -> V_12 = ( V_11 + 1 ) & ( V_15 - 1 ) ;
F_3 ( V_10 , V_16 ) ;
}
static void F_4 ( struct V_1 * V_1 , T_1 V_10 )
{
struct V_2 * V_3 ;
int V_11 = V_1 -> V_12 ;
V_3 = & V_1 -> V_13 [ V_11 ] ;
V_3 -> type = V_17 ;
V_3 -> V_10 = V_10 ;
F_1 ( V_1 , V_3 ) ;
V_1 -> V_12 = ( V_11 + 1 ) & ( V_15 - 1 ) ;
V_1 -> V_9 = V_10 ;
}
static void F_5 ( struct V_1 * V_1 )
{
int V_11 = V_1 -> V_12 ;
int V_18 = V_11 ;
F_6 (KERN_INFO PFX L_1 ,
esp->host->unique_id) ;
do {
struct V_2 * V_3 = & V_1 -> V_13 [ V_11 ] ;
F_6 (KERN_INFO PFX L_2 ,
esp->host->unique_id, idx,
p->type == ESP_EVENT_TYPE_CMD ? L_3 : L_4 ) ;
F_6 ( L_5
L_6 ,
V_3 -> V_10 , V_3 -> V_4 , V_3 -> V_5 ,
V_3 -> V_6 , V_3 -> V_7 , V_3 -> V_8 , V_3 -> V_9 ) ;
V_11 = ( V_11 + 1 ) & ( V_15 - 1 ) ;
} while ( V_11 != V_18 );
}
static void F_7 ( struct V_1 * V_1 )
{
F_2 ( V_1 , V_19 ) ;
if ( V_1 -> V_20 == V_21 ) {
int V_22 = 1000 ;
while ( F_8 ( V_23 ) & V_24 ) {
if ( -- V_22 == 0 ) {
F_6 (KERN_ALERT PFX L_7
L_8 ,
esp->host->unique_id) ;
break;
}
F_9 ( 1 ) ;
}
}
}
static void F_10 ( struct V_1 * V_1 )
{
int V_25 = F_8 ( V_23 ) & V_24 ;
int V_11 = 0 ;
while ( V_25 -- ) {
V_1 -> V_26 [ V_11 ++ ] = F_8 ( V_27 ) ;
V_1 -> V_26 [ V_11 ++ ] = F_8 ( V_27 ) ;
}
if ( V_1 -> V_6 & V_28 ) {
F_3 ( 0 , V_27 ) ;
V_1 -> V_26 [ V_11 ++ ] = F_8 ( V_27 ) ;
F_2 ( V_1 , V_19 ) ;
}
V_1 -> V_29 = V_11 ;
}
static void F_11 ( struct V_1 * V_1 , T_1 V_10 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ )
V_1 -> V_32 [ V_30 ] . V_33 = V_10 ;
}
static void F_12 ( struct V_1 * V_1 )
{
T_1 V_34 , V_35 ;
F_2 ( V_1 , V_36 ) ;
F_2 ( V_1 , V_37 | V_38 ) ;
if ( V_1 -> V_20 == V_39 )
F_3 ( V_40 , V_41 ) ;
F_2 ( V_1 , V_37 | V_38 ) ;
V_1 -> V_42 = ( ( 35 * V_1 -> V_43 ) / 1000 ) ;
if ( V_1 -> V_20 == V_39 ) {
V_35 = F_8 ( V_44 ) ;
V_34 = ( V_35 & 0xf8 ) >> 3 ;
if ( V_34 == 0x02 )
V_1 -> V_20 = V_45 ;
else if ( V_34 == 0x0a )
V_1 -> V_20 = V_46 ;
else
V_1 -> V_20 = V_47 ;
V_1 -> V_48 = ( ( 4 * V_1 -> V_43 ) / 1000 ) ;
} else {
V_1 -> V_48 = ( ( 5 * V_1 -> V_43 ) / 1000 ) ;
}
V_1 -> V_42 = ( V_1 -> V_42 + 3 ) >> 2 ;
V_1 -> V_48 = ( V_1 -> V_48 + 3 ) >> 2 ;
F_3 ( V_1 -> V_49 , V_50 ) ;
switch ( V_1 -> V_20 ) {
case V_51 :
break;
case V_52 :
F_3 ( V_1 -> V_53 , V_41 ) ;
break;
case V_21 :
F_3 ( V_1 -> V_53 , V_41 ) ;
V_1 -> V_54 = V_1 -> V_32 [ 0 ] . V_33 ;
F_3 ( V_1 -> V_54 , V_55 ) ;
break;
case V_46 :
V_1 -> V_53 |= ( V_56 | V_57 ) ;
case V_45 :
F_3 ( V_1 -> V_53 , V_41 ) ;
if ( V_1 -> V_20 == V_46 ) {
T_1 V_58 = V_1 -> V_32 [ 0 ] . V_33 ;
V_58 |= V_59 | V_60 ;
if ( V_1 -> V_61 >= 8 )
V_58 |= V_62 ;
F_11 ( V_1 , V_58 ) ;
} else {
T_2 V_58 = V_1 -> V_32 [ 0 ] . V_33 ;
V_58 |= V_63 ;
F_11 ( V_1 , V_58 ) ;
}
V_1 -> V_54 = V_1 -> V_32 [ 0 ] . V_33 ;
F_3 ( V_1 -> V_54 , V_55 ) ;
if ( V_1 -> V_20 == V_46 ) {
V_1 -> V_64 = 80 ;
} else {
if ( V_1 -> V_65 & V_66 )
V_1 -> V_64 = 0 ;
else
V_1 -> V_64 = 96 ;
}
break;
case V_47 :
F_3 ( V_1 -> V_53 , V_41 ) ;
F_11 ( V_1 ,
( V_1 -> V_32 [ 0 ] . V_33 |
V_59 ) ) ;
V_1 -> V_54 = V_1 -> V_32 [ 0 ] . V_33 ;
F_3 ( V_1 -> V_54 , V_55 ) ;
V_1 -> V_64 = 32 ;
break;
default:
break;
}
F_3 ( V_1 -> V_67 , V_68 ) ;
V_1 -> V_69 = 0 ;
F_3 ( V_1 -> V_69 , V_70 ) ;
V_1 -> V_71 = 0 ;
F_3 ( V_1 -> V_71 , V_72 ) ;
F_3 ( V_1 -> V_73 , V_74 ) ;
F_8 ( V_75 ) ;
F_9 ( 100 ) ;
}
static void F_13 ( struct V_1 * V_1 , struct V_76 * V_77 )
{
struct V_78 * V_79 = F_14 ( V_77 ) ;
struct V_80 * V_81 = F_15 ( V_77 ) ;
int V_82 = V_77 -> V_83 ;
int V_84 , V_30 ;
if ( V_82 == V_85 )
return;
V_79 -> V_86 . V_87 = V_1 -> V_88 -> V_89 ( V_1 , V_81 , F_16 ( V_77 ) , V_82 ) ;
V_79 -> V_90 = F_17 ( V_81 ) ;
V_79 -> V_91 = V_81 ;
V_84 = 0 ;
for ( V_30 = 0 ; V_30 < V_79 -> V_86 . V_87 ; V_30 ++ )
V_84 += F_17 ( & V_81 [ V_30 ] ) ;
V_79 -> V_92 = V_84 ;
}
static T_3 F_18 ( struct V_93 * V_94 ,
struct V_76 * V_77 )
{
struct V_78 * V_3 = F_14 ( V_77 ) ;
if ( V_94 -> V_65 & V_95 ) {
return V_94 -> V_96 +
( V_94 -> V_97 - V_77 -> V_98 ) ;
}
return F_19 ( V_3 -> V_91 ) +
( F_17 ( V_3 -> V_91 ) -
V_3 -> V_90 ) ;
}
static unsigned int F_20 ( struct V_93 * V_94 ,
struct V_76 * V_77 )
{
struct V_78 * V_3 = F_14 ( V_77 ) ;
if ( V_94 -> V_65 & V_95 ) {
return V_99 -
( V_94 -> V_97 - V_77 -> V_98 ) ;
}
return V_3 -> V_90 ;
}
static void F_21 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_76 * V_77 , unsigned int V_100 )
{
struct V_78 * V_3 = F_14 ( V_77 ) ;
if ( V_94 -> V_65 & V_95 ) {
V_94 -> V_97 += V_100 ;
return;
}
V_3 -> V_90 -= V_100 ;
V_3 -> V_92 -= V_100 ;
if ( V_3 -> V_90 < 0 || V_3 -> V_92 < 0 ) {
F_6 (KERN_ERR PFX L_9 ,
esp->host->unique_id) ;
F_6 (KERN_ERR PFX L_10
L_11 ,
esp->host->unique_id,
p->cur_residue, p->tot_residue, len) ;
V_3 -> V_90 = 0 ;
V_3 -> V_92 = 0 ;
}
if ( ! V_3 -> V_90 && V_3 -> V_92 ) {
V_3 -> V_91 ++ ;
V_3 -> V_90 = F_17 ( V_3 -> V_91 ) ;
}
}
static void F_22 ( struct V_1 * V_1 , struct V_76 * V_77 )
{
struct V_78 * V_79 = F_14 ( V_77 ) ;
int V_82 = V_77 -> V_83 ;
if ( V_82 == V_85 )
return;
V_1 -> V_88 -> V_101 ( V_1 , F_15 ( V_77 ) , V_79 -> V_86 . V_87 , V_82 ) ;
}
static void F_23 ( struct V_1 * V_1 , struct V_93 * V_94 )
{
struct V_76 * V_77 = V_94 -> V_77 ;
struct V_78 * V_79 = F_14 ( V_77 ) ;
if ( V_94 -> V_65 & V_95 ) {
V_94 -> V_102 = V_94 -> V_97 ;
return;
}
V_94 -> V_103 = V_79 -> V_90 ;
V_94 -> V_104 = V_79 -> V_91 ;
V_94 -> V_105 = V_79 -> V_92 ;
}
static void F_24 ( struct V_1 * V_1 , struct V_93 * V_94 )
{
struct V_76 * V_77 = V_94 -> V_77 ;
struct V_78 * V_79 = F_14 ( V_77 ) ;
if ( V_94 -> V_65 & V_95 ) {
V_94 -> V_97 = V_94 -> V_102 ;
return;
}
V_79 -> V_90 = V_94 -> V_103 ;
V_79 -> V_91 = V_94 -> V_104 ;
V_79 -> V_92 = V_94 -> V_105 ;
}
static void F_25 ( struct V_1 * V_1 , struct V_76 * V_77 )
{
if ( V_77 -> V_106 == 6 ||
V_77 -> V_106 == 10 ||
V_77 -> V_106 == 12 ) {
V_1 -> V_65 &= ~ V_107 ;
} else {
V_1 -> V_65 |= V_107 ;
}
}
static void F_26 ( struct V_1 * V_1 , int V_108 )
{
if ( V_1 -> V_20 > V_52 ) {
T_1 V_10 = V_1 -> V_32 [ V_108 ] . V_33 ;
if ( V_10 != V_1 -> V_54 ) {
V_1 -> V_54 = V_10 ;
F_3 ( V_10 , V_55 ) ;
}
}
}
static void F_27 ( struct V_1 * V_1 , int V_108 )
{
T_1 V_109 = V_1 -> V_32 [ V_108 ] . V_110 ;
T_1 V_111 = V_1 -> V_32 [ V_108 ] . V_112 ;
if ( V_109 != V_1 -> V_71 ) {
V_1 -> V_71 = V_109 ;
F_3 ( V_109 , V_72 ) ;
}
if ( V_111 != V_1 -> V_69 ) {
V_1 -> V_69 = V_111 ;
F_3 ( V_111 , V_70 ) ;
}
}
static T_2 F_28 ( struct V_1 * V_1 , T_2 V_113 , T_2 V_114 )
{
if ( V_1 -> V_20 == V_46 ) {
if ( V_114 > ( 1U << 24 ) )
V_114 = ( 1U << 24 ) ;
} else {
T_2 V_115 , V_116 ;
if ( V_114 > ( 1U << 16 ) )
V_114 = ( 1U << 16 ) ;
V_115 = V_113 & ( ( 1U << 24 ) - 1U ) ;
V_116 = V_115 + V_114 ;
if ( V_116 > ( 1U << 24 ) )
V_116 = ( 1U << 24 ) ;
V_114 = V_116 - V_115 ;
}
return V_114 ;
}
static int F_29 ( struct V_117 * V_118 )
{
struct V_119 * V_32 = V_118 -> V_120 ;
return F_30 ( V_32 ) != V_118 -> V_121 ;
}
static int F_31 ( struct V_117 * V_118 )
{
struct V_119 * V_32 = V_118 -> V_120 ;
if ( ! F_32 ( V_32 ) && ! V_118 -> V_122 )
return 0 ;
if ( F_32 ( V_32 ) == V_118 -> V_122 &&
F_33 ( V_32 ) == V_118 -> V_123 )
return 0 ;
return 1 ;
}
static int F_34 ( struct V_93 * V_94 ,
struct V_124 * V_125 )
{
if ( ! V_94 -> V_126 [ 0 ] ) {
if ( V_125 -> V_127 )
return - V_128 ;
if ( V_125 -> V_129 ) {
if ( V_125 -> V_130 )
return - V_128 ;
V_125 -> V_129 = 0 ;
} else if ( V_125 -> V_130 ) {
V_125 -> V_129 = 1 ;
return - V_128 ;
}
V_125 -> V_127 = V_94 ;
return 0 ;
} else {
if ( V_125 -> V_127 || V_125 -> V_129 )
return - V_128 ;
}
F_35 ( V_125 -> V_131 [ V_94 -> V_126 [ 1 ] ] ) ;
V_125 -> V_131 [ V_94 -> V_126 [ 1 ] ] = V_94 ;
V_125 -> V_130 ++ ;
return 0 ;
}
static void F_36 ( struct V_93 * V_94 ,
struct V_124 * V_125 )
{
if ( V_94 -> V_126 [ 0 ] ) {
F_35 ( V_125 -> V_131 [ V_94 -> V_126 [ 1 ] ] != V_94 ) ;
V_125 -> V_131 [ V_94 -> V_126 [ 1 ] ] = NULL ;
V_125 -> V_130 -- ;
} else {
F_35 ( V_125 -> V_127 != V_94 ) ;
V_125 -> V_127 = NULL ;
}
}
static void F_37 ( struct V_1 * V_1 , struct V_93 * V_94 )
{
struct V_76 * V_77 = V_94 -> V_77 ;
struct V_132 * V_133 = V_77 -> V_134 ;
int V_108 , V_135 ;
T_1 * V_3 , V_10 ;
V_108 = V_133 -> V_136 ;
V_135 = V_133 -> V_135 ;
if ( ! V_94 -> V_97 ) {
F_38 ( L_12
L_13 ,
V_1 -> V_137 -> V_138 , V_108 , V_135 ) ;
V_94 -> V_97 = V_77 -> V_98 ;
V_94 -> V_96 = V_1 -> V_88 -> V_139 ( V_1 ,
V_94 -> V_97 ,
V_99 ,
V_140 ) ;
}
V_94 -> V_102 = V_94 -> V_97 ;
V_1 -> V_141 = V_94 ;
V_3 = V_1 -> V_142 ;
V_1 -> V_143 = 0 ;
* V_3 ++ = F_39 ( 0 , V_135 ) ;
* V_3 ++ = V_144 ;
* V_3 ++ = ( ( V_133 -> V_145 <= V_146 ) ?
( V_135 << 5 ) : 0 ) ;
* V_3 ++ = 0 ;
* V_3 ++ = 0 ;
* V_3 ++ = V_99 ;
* V_3 ++ = 0 ;
V_1 -> V_8 = V_147 ;
V_10 = V_108 ;
if ( V_1 -> V_20 == V_46 )
V_10 |= V_148 | V_149 ;
F_3 ( V_10 , V_150 ) ;
F_27 ( V_1 , V_108 ) ;
F_26 ( V_1 , V_108 ) ;
V_10 = ( V_3 - V_1 -> V_142 ) ;
if ( V_1 -> V_20 == V_46 )
F_2 ( V_1 , V_19 ) ;
V_1 -> V_88 -> V_151 ( V_1 , V_1 -> V_152 ,
V_10 , 16 , 0 , V_38 | V_153 ) ;
}
static struct V_93 * F_40 ( struct V_1 * V_1 )
{
struct V_93 * V_94 ;
F_41 (ent, &esp->queued_cmds, list) {
struct V_76 * V_77 = V_94 -> V_77 ;
struct V_132 * V_133 = V_77 -> V_134 ;
struct V_124 * V_125 = V_133 -> V_154 ;
if ( V_94 -> V_65 & V_95 ) {
V_94 -> V_126 [ 0 ] = 0 ;
V_94 -> V_126 [ 1 ] = 0 ;
return V_94 ;
}
if ( ! F_42 ( V_77 , & V_94 -> V_126 [ 0 ] ) ) {
V_94 -> V_126 [ 0 ] = 0 ;
V_94 -> V_126 [ 1 ] = 0 ;
}
if ( F_34 ( V_94 , V_125 ) < 0 )
continue;
return V_94 ;
}
return NULL ;
}
static void F_43 ( struct V_1 * V_1 )
{
struct V_117 * V_118 ;
struct V_124 * V_125 ;
struct V_132 * V_133 ;
struct V_76 * V_77 ;
struct V_93 * V_94 ;
int V_108 , V_135 , V_30 ;
T_2 V_10 , V_155 ;
T_1 * V_3 ;
if ( V_1 -> V_141 ||
( V_1 -> V_65 & V_156 ) )
return;
V_94 = F_40 ( V_1 ) ;
if ( ! V_94 )
return;
if ( V_94 -> V_65 & V_95 ) {
F_37 ( V_1 , V_94 ) ;
return;
}
V_77 = V_94 -> V_77 ;
V_133 = V_77 -> V_134 ;
V_108 = V_133 -> V_136 ;
V_135 = V_133 -> V_135 ;
V_118 = & V_1 -> V_32 [ V_108 ] ;
V_125 = V_133 -> V_154 ;
F_44 ( & V_94 -> V_157 , & V_1 -> V_158 ) ;
V_1 -> V_141 = V_94 ;
F_13 ( V_1 , V_77 ) ;
F_23 ( V_1 , V_94 ) ;
F_25 ( V_1 , V_77 ) ;
V_3 = V_1 -> V_142 ;
V_1 -> V_143 = 0 ;
if ( V_118 -> V_65 & V_159 ) {
if ( V_118 -> V_65 & V_160 ) {
V_118 -> V_65 &= ~ V_161 ;
V_118 -> V_123 = 0 ;
V_118 -> V_122 = 0 ;
V_118 -> V_121 = 0 ;
V_118 -> V_162 = 0 ;
}
if ( F_30 ( V_118 -> V_120 ) == V_118 -> V_121 &&
F_33 ( V_118 -> V_120 ) == V_118 -> V_123 &&
F_32 ( V_118 -> V_120 ) == V_118 -> V_122 ) {
V_118 -> V_65 &= ~ V_159 ;
goto V_163;
}
if ( V_1 -> V_20 == V_46 && F_29 ( V_118 ) ) {
V_1 -> V_143 =
F_45 ( & V_1 -> V_164 [ 0 ] ,
( V_118 -> V_121 ?
1 : 0 ) ) ;
V_118 -> V_65 |= V_165 ;
} else if ( F_31 ( V_118 ) ) {
V_1 -> V_143 =
F_46 ( & V_1 -> V_164 [ 0 ] ,
V_118 -> V_123 ,
V_118 -> V_122 ) ;
V_118 -> V_65 |= V_166 ;
} else {
V_118 -> V_65 &= ~ V_159 ;
}
if ( V_118 -> V_65 & ( V_165 | V_166 ) )
V_1 -> V_65 |= V_107 ;
}
V_163:
if ( V_125 && ( V_118 -> V_65 & V_161 ) && V_94 -> V_126 [ 0 ] )
* V_3 ++ = F_39 ( 1 , V_135 ) ;
else
* V_3 ++ = F_39 ( 0 , V_135 ) ;
if ( V_94 -> V_126 [ 0 ] && V_1 -> V_20 == V_51 ) {
V_1 -> V_65 |= V_107 ;
}
if ( ! ( V_1 -> V_65 & V_107 ) ) {
V_155 = V_38 | V_153 ;
if ( V_94 -> V_126 [ 0 ] ) {
* V_3 ++ = V_94 -> V_126 [ 0 ] ;
* V_3 ++ = V_94 -> V_126 [ 1 ] ;
V_155 = V_38 | V_167 ;
}
for ( V_30 = 0 ; V_30 < V_77 -> V_106 ; V_30 ++ )
* V_3 ++ = V_77 -> V_168 [ V_30 ] ;
V_1 -> V_8 = V_147 ;
} else {
V_1 -> V_169 = V_77 -> V_106 ;
V_1 -> V_170 = & V_77 -> V_168 [ 0 ] ;
if ( V_94 -> V_126 [ 0 ] ) {
for ( V_30 = V_1 -> V_143 - 1 ;
V_30 >= 0 ; V_30 -- )
V_1 -> V_164 [ V_30 + 2 ] = V_1 -> V_164 [ V_30 ] ;
V_1 -> V_164 [ 0 ] = V_94 -> V_126 [ 0 ] ;
V_1 -> V_164 [ 1 ] = V_94 -> V_126 [ 1 ] ;
V_1 -> V_143 += 2 ;
}
V_155 = V_38 | V_171 ;
V_1 -> V_8 = V_172 ;
}
V_10 = V_108 ;
if ( V_1 -> V_20 == V_46 )
V_10 |= V_148 | V_149 ;
F_3 ( V_10 , V_150 ) ;
F_27 ( V_1 , V_108 ) ;
F_26 ( V_1 , V_108 ) ;
V_10 = ( V_3 - V_1 -> V_142 ) ;
if ( V_173 & V_174 ) {
F_6 ( L_14 , V_108 , V_135 ) ;
for ( V_30 = 0 ; V_30 < V_77 -> V_106 ; V_30 ++ )
F_6 ( L_15 , V_77 -> V_168 [ V_30 ] ) ;
F_6 ( L_16 ) ;
}
if ( V_1 -> V_20 == V_46 )
F_2 ( V_1 , V_19 ) ;
V_1 -> V_88 -> V_151 ( V_1 , V_1 -> V_152 ,
V_10 , 16 , 0 , V_155 ) ;
}
static struct V_93 * F_47 ( struct V_1 * V_1 )
{
struct V_175 * V_176 = & V_1 -> V_177 ;
struct V_93 * V_178 ;
if ( F_48 ( V_176 ) ) {
V_178 = F_49 ( sizeof( struct V_93 ) , V_179 ) ;
} else {
V_178 = F_50 ( V_176 -> V_180 , struct V_93 , V_157 ) ;
F_51 ( & V_178 -> V_157 ) ;
memset ( V_178 , 0 , sizeof( * V_178 ) ) ;
}
return V_178 ;
}
static void F_52 ( struct V_1 * V_1 , struct V_93 * V_94 )
{
F_53 ( & V_94 -> V_157 , & V_1 -> V_177 ) ;
}
static void F_54 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_76 * V_77 , unsigned int V_181 )
{
struct V_132 * V_133 = V_77 -> V_134 ;
int V_108 = V_133 -> V_136 ;
int V_135 = V_133 -> V_135 ;
V_1 -> V_141 = NULL ;
F_22 ( V_1 , V_77 ) ;
F_36 ( V_94 , V_133 -> V_154 ) ;
V_77 -> V_181 = V_181 ;
if ( V_94 -> V_182 ) {
F_55 ( V_94 -> V_182 ) ;
V_94 -> V_182 = NULL ;
}
if ( V_94 -> V_65 & V_95 ) {
V_1 -> V_88 -> V_183 ( V_1 , V_94 -> V_96 ,
V_99 , V_140 ) ;
V_94 -> V_97 = NULL ;
V_77 -> V_181 = ( ( V_184 << 24 ) |
( V_185 << 16 ) |
( V_186 << 8 ) |
( V_187 << 0 ) ) ;
V_94 -> V_65 &= ~ V_95 ;
if ( V_173 & V_188 ) {
int V_30 ;
F_6 ( L_17 ,
V_1 -> V_137 -> V_138 , V_108 , V_135 ) ;
for ( V_30 = 0 ; V_30 < 18 ; V_30 ++ )
F_6 ( L_15 , V_77 -> V_98 [ V_30 ] ) ;
F_6 ( L_16 ) ;
}
}
V_77 -> V_189 ( V_77 ) ;
F_51 ( & V_94 -> V_157 ) ;
F_52 ( V_1 , V_94 ) ;
F_43 ( V_1 ) ;
}
static unsigned int F_56 ( unsigned int V_190 , unsigned int V_191 ,
unsigned int V_192 )
{
return ( V_190 | ( V_191 << 8 ) | ( V_192 << 16 ) ) ;
}
static void F_57 ( struct V_1 * V_1 , struct V_93 * V_94 )
{
struct V_132 * V_133 = V_94 -> V_77 -> V_134 ;
struct V_124 * V_125 = V_133 -> V_154 ;
F_58 ( V_133 , V_125 -> V_130 - 1 ) ;
}
static int F_59 ( struct V_76 * V_77 , void (* F_60)( struct V_76 * ) )
{
struct V_132 * V_133 = V_77 -> V_134 ;
struct V_1 * V_1 = F_61 ( V_133 -> V_137 ) ;
struct V_78 * V_79 ;
struct V_93 * V_94 ;
V_94 = F_47 ( V_1 ) ;
if ( ! V_94 )
return V_193 ;
V_94 -> V_77 = V_77 ;
V_77 -> V_189 = F_60 ;
V_79 = F_14 ( V_77 ) ;
V_79 -> V_86 . V_113 = ~ ( T_3 ) 0x0 ;
F_62 ( & V_94 -> V_157 , & V_1 -> V_194 ) ;
F_43 ( V_1 ) ;
return 0 ;
}
int F_63 ( struct V_1 * V_1 )
{
switch ( V_1 -> V_20 ) {
case V_51 :
case V_52 :
V_1 -> V_4 &= ~ V_195 ;
break;
default:
if ( ! ( V_1 -> V_4 & V_195 ) ) {
V_1 -> V_7 = F_8 ( V_75 ) ;
if ( V_1 -> V_7 & V_196 )
return 1 ;
if ( ! V_1 -> V_88 -> V_197 ( V_1 ) ) {
F_6 (KERN_ERR PFX L_18
L_19 ,
esp->host->unique_id, esp->sreg) ;
return - 1 ;
}
F_6 (KERN_ERR PFX L_20 ,
esp->host->unique_id) ;
return - 1 ;
}
break;
}
return 0 ;
}
static void F_64 ( struct V_1 * V_1 )
{
F_65 ( L_21 ,
F_66 ( 0 ) ) ;
V_1 -> V_65 |= V_156 ;
F_4 ( V_1 , V_198 ) ;
}
static struct V_93 * F_67 ( struct V_1 * V_1 ,
struct V_124 * V_125 )
{
struct V_93 * V_94 ;
int V_30 ;
if ( ! V_125 -> V_130 ) {
F_6 (KERN_ERR PFX L_22 ,
esp->host->unique_id) ;
return NULL ;
}
F_68 ( L_23 ) ;
for ( V_30 = 0 ; V_30 < V_199 ; V_30 ++ ) {
if ( V_1 -> V_88 -> V_200 ( V_1 ) )
break;
}
if ( V_30 == V_199 ) {
F_6 (KERN_ERR PFX L_24 ,
esp->host->unique_id) ;
return NULL ;
}
V_1 -> V_4 = F_8 ( V_201 ) ;
V_1 -> V_7 = F_8 ( V_75 ) ;
F_68 ( L_25 ,
V_30 , V_1 -> V_7 , V_1 -> V_4 ) ;
if ( V_1 -> V_7 & V_202 ) {
F_6 (KERN_ERR PFX L_26 ,
esp->host->unique_id) ;
return NULL ;
}
if ( ( V_1 -> V_4 & V_203 ) != V_204 ) {
F_6 (KERN_ERR PFX L_27 ,
esp->host->unique_id, esp->sreg) ;
return NULL ;
}
V_1 -> V_142 [ 0 ] = 0xff ;
V_1 -> V_142 [ 1 ] = 0xff ;
V_1 -> V_88 -> V_151 ( V_1 , V_1 -> V_152 ,
2 , 2 , 1 , V_38 | V_205 ) ;
F_2 ( V_1 , V_206 ) ;
for ( V_30 = 0 ; V_30 < V_207 ; V_30 ++ ) {
if ( V_1 -> V_88 -> V_200 ( V_1 ) ) {
V_1 -> V_4 = F_8 ( V_201 ) ;
V_1 -> V_7 = F_8 ( V_75 ) ;
if ( V_1 -> V_7 & V_208 )
break;
}
F_9 ( 1 ) ;
}
if ( V_30 == V_207 ) {
F_6 (KERN_ERR PFX L_28 ,
esp->host->unique_id) ;
return NULL ;
}
V_1 -> V_88 -> V_209 ( V_1 ) ;
V_1 -> V_88 -> V_210 ( V_1 ) ;
F_68 ( L_29 ,
V_30 , V_1 -> V_7 , V_1 -> V_4 ,
V_1 -> V_142 [ 0 ] ,
V_1 -> V_142 [ 1 ] ) ;
if ( V_1 -> V_142 [ 0 ] < V_211 ||
V_1 -> V_142 [ 0 ] > V_212 ) {
F_6 (KERN_ERR PFX L_30
L_31 ,
esp->host->unique_id, esp->command_block[0]) ;
return NULL ;
}
V_94 = V_125 -> V_131 [ V_1 -> V_142 [ 1 ] ] ;
if ( ! V_94 ) {
F_6 (KERN_ERR PFX L_32
L_33 ,
esp->host->unique_id, esp->command_block[1]) ;
return NULL ;
}
return V_94 ;
}
static int F_69 ( struct V_1 * V_1 )
{
struct V_93 * V_94 ;
struct V_117 * V_118 ;
struct V_124 * V_125 ;
struct V_132 * V_133 ;
int V_32 , V_135 ;
F_35 ( V_1 -> V_141 ) ;
if ( V_1 -> V_20 == V_46 ) {
V_32 = V_1 -> V_26 [ 0 ] ;
V_135 = V_1 -> V_26 [ 1 ] & 0x7 ;
} else {
T_1 V_213 = F_8 ( V_27 ) ;
if ( ! ( V_213 & V_1 -> V_214 ) )
goto V_215;
V_213 &= ~ V_1 -> V_214 ;
if ( ! V_213 || ( V_213 & ( V_213 - 1 ) ) )
goto V_215;
V_32 = F_70 ( V_213 ) - 1 ;
V_135 = ( F_8 ( V_27 ) & 0x7 ) ;
F_2 ( V_1 , V_19 ) ;
if ( V_1 -> V_20 == V_51 ) {
T_1 V_7 = F_8 ( V_75 ) ;
if ( V_7 & V_196 )
goto V_215;
}
F_2 ( V_1 , V_37 ) ;
}
F_27 ( V_1 , V_32 ) ;
F_26 ( V_1 , V_32 ) ;
F_2 ( V_1 , V_206 ) ;
if ( V_1 -> V_20 == V_46 )
F_3 ( V_32 | V_148 | V_149 ,
V_150 ) ;
V_118 = & V_1 -> V_32 [ V_32 ] ;
V_133 = F_71 ( V_118 -> V_120 , V_135 ) ;
if ( ! V_133 ) {
F_6 (KERN_ERR PFX L_34
L_35 ,
esp->host->unique_id, target, lun) ;
goto V_215;
}
V_125 = V_133 -> V_154 ;
V_94 = V_125 -> V_127 ;
if ( ! V_94 ) {
V_94 = F_67 ( V_1 , V_125 ) ;
if ( ! V_94 )
goto V_215;
}
V_1 -> V_141 = V_94 ;
if ( V_94 -> V_65 & V_216 ) {
V_1 -> V_164 [ 0 ] = V_217 ;
V_1 -> V_143 = 1 ;
F_2 ( V_1 , V_218 ) ;
}
F_4 ( V_1 , V_219 ) ;
F_24 ( V_1 , V_94 ) ;
V_1 -> V_65 |= V_220 ;
return 1 ;
V_215:
F_64 ( V_1 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_1 )
{
struct V_93 * V_94 ;
struct V_76 * V_77 ;
T_1 V_221 ;
V_221 = V_1 -> V_8 ;
V_1 -> V_8 = V_222 ;
V_1 -> V_5 = F_8 ( V_223 ) & V_224 ;
V_94 = V_1 -> V_141 ;
V_77 = V_94 -> V_77 ;
if ( V_1 -> V_88 -> V_197 ( V_1 ) ) {
F_64 ( V_1 ) ;
F_54 ( V_1 , V_94 , V_77 , ( V_225 << 16 ) ) ;
return 0 ;
}
V_1 -> V_88 -> V_210 ( V_1 ) ;
if ( V_1 -> V_7 == ( V_226 | V_208 ) ) {
struct V_117 * V_118 = & V_1 -> V_32 [ V_77 -> V_134 -> V_136 ] ;
if ( ! ( V_94 -> V_65 & V_95 ) ) {
F_22 ( V_1 , V_77 ) ;
F_36 ( V_94 , V_77 -> V_134 -> V_154 ) ;
V_118 -> V_65 &= ~ ( V_166 | V_165 ) ;
V_1 -> V_65 &= ~ V_107 ;
V_1 -> V_170 = NULL ;
V_1 -> V_169 = 0 ;
} else {
V_1 -> V_88 -> V_183 ( V_1 , V_94 -> V_96 ,
V_99 ,
V_140 ) ;
V_94 -> V_97 = NULL ;
}
F_44 ( & V_94 -> V_157 , & V_1 -> V_194 ) ;
V_1 -> V_141 = NULL ;
return 0 ;
}
if ( V_1 -> V_7 == V_202 ) {
struct V_132 * V_133 = V_77 -> V_134 ;
V_1 -> V_32 [ V_133 -> V_136 ] . V_65 |= V_159 ;
F_2 ( V_1 , V_227 ) ;
F_54 ( V_1 , V_94 , V_77 , ( V_228 << 16 ) ) ;
return 1 ;
}
if ( V_1 -> V_7 == ( V_208 | V_229 ) ) {
if ( V_1 -> V_20 <= V_21 ) {
int V_25 = F_8 ( V_23 ) & V_24 ;
F_2 ( V_1 , V_37 ) ;
if ( ! V_25 &&
( ! V_1 -> V_71 ||
( ( V_1 -> V_4 & V_203 ) != V_230 ) ) )
F_7 ( V_1 ) ;
}
F_4 ( V_1 , V_219 ) ;
return 0 ;
}
F_6 ( L_36 ,
V_1 -> V_7 ) ;
F_64 ( V_1 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_1 , struct V_93 * V_94 ,
struct V_76 * V_77 )
{
int V_29 , V_231 , V_232 , V_233 ;
V_29 = F_8 ( V_23 ) & V_24 ;
if ( V_1 -> V_54 & V_234 )
V_29 <<= 1 ;
V_231 = 0 ;
if ( ! ( V_1 -> V_4 & V_235 ) ) {
V_231 = ( ( unsigned int ) F_8 ( V_236 ) |
( ( ( unsigned int ) F_8 ( V_237 ) ) << 8 ) ) ;
if ( V_1 -> V_20 == V_46 )
V_231 |= ( ( unsigned int ) F_8 ( V_238 ) ) << 16 ;
}
V_232 = V_1 -> V_239 ;
V_232 -= V_231 ;
if ( ! ( V_94 -> V_65 & V_240 ) )
V_232 -= V_29 ;
V_233 = 0 ;
if ( ! V_1 -> V_71 ) {
V_233 = 1 ;
} else {
if ( V_1 -> V_20 == V_51 ) {
T_2 V_241 , V_242 ;
V_1 -> V_4 = F_8 ( V_201 ) ;
V_242 = V_1 -> V_4 & V_203 ;
V_241 = F_8 ( V_23 ) ;
if ( ( V_242 == V_243 &&
( V_241 & V_244 ) ) ||
( V_242 == V_230 &&
( V_241 & V_24 ) ) )
return - 1 ;
}
if ( ! ( V_94 -> V_65 & V_240 ) )
V_233 = 1 ;
}
if ( V_233 )
F_7 ( V_1 ) ;
return V_232 ;
}
static void F_74 ( struct V_1 * V_1 , struct V_117 * V_118 ,
T_1 V_245 , T_1 V_246 ,
T_1 V_247 , T_1 V_248 )
{
F_33 ( V_118 -> V_120 ) = V_245 ;
F_32 ( V_118 -> V_120 ) = V_246 ;
F_30 ( V_118 -> V_120 ) = ( V_118 -> V_65 & V_249 ) ? 1 : 0 ;
if ( V_248 ) {
V_247 &= 0x1f ;
V_248 |= V_1 -> V_64 ;
if ( V_1 -> V_20 >= V_45 ) {
T_1 V_250 = V_251 ;
if ( V_1 -> V_20 >= V_47 )
V_250 = V_252 ;
if ( V_245 < 50 ) {
if ( V_1 -> V_20 == V_46 )
V_248 &= ~ V_1 -> V_64 ;
V_118 -> V_33 |= V_250 ;
} else {
V_118 -> V_33 &= ~ V_250 ;
}
V_1 -> V_54 = V_118 -> V_33 ;
F_3 ( V_1 -> V_54 , V_55 ) ;
}
}
V_118 -> V_112 = V_1 -> V_69 = V_247 ;
V_118 -> V_110 = V_1 -> V_71 = V_248 ;
F_3 ( V_248 , V_72 ) ;
F_3 ( V_247 , V_70 ) ;
V_118 -> V_65 &= ~ ( V_166 | V_159 ) ;
F_75 ( V_118 -> V_120 ) ;
}
static void F_76 ( struct V_1 * V_1 )
{
struct V_93 * V_94 = V_1 -> V_141 ;
struct V_76 * V_77 = V_94 -> V_77 ;
struct V_117 * V_118 ;
int V_108 ;
V_108 = V_77 -> V_134 -> V_136 ;
V_118 = & V_1 -> V_32 [ V_108 ] ;
if ( V_118 -> V_65 & V_165 ) {
V_118 -> V_65 &= ~ ( V_165 | V_249 ) ;
if ( ! F_31 ( V_118 ) ) {
V_118 -> V_65 &= ~ V_159 ;
F_2 ( V_1 , V_253 ) ;
} else {
V_1 -> V_143 =
F_46 ( & V_1 -> V_164 [ 0 ] ,
V_118 -> V_123 ,
V_118 -> V_122 ) ;
V_118 -> V_65 |= V_166 ;
F_2 ( V_1 , V_218 ) ;
}
return;
}
if ( V_118 -> V_65 & V_166 ) {
V_118 -> V_65 &= ~ ( V_166 | V_159 ) ;
V_118 -> V_112 = 0 ;
V_118 -> V_110 = 0 ;
F_74 ( V_1 , V_118 , 0 , 0 , 0 , 0 ) ;
F_2 ( V_1 , V_253 ) ;
return;
}
V_1 -> V_164 [ 0 ] = V_217 ;
V_1 -> V_143 = 1 ;
F_2 ( V_1 , V_218 ) ;
}
static void F_77 ( struct V_1 * V_1 , struct V_117 * V_118 )
{
T_1 V_254 = V_1 -> V_255 [ 3 ] ;
T_1 V_256 = V_1 -> V_255 [ 4 ] ;
T_1 V_257 ;
if ( ! ( V_118 -> V_65 & V_166 ) )
goto V_258;
if ( V_256 > 15 )
goto V_258;
if ( V_256 ) {
int V_259 ;
if ( V_254 > V_1 -> V_42 ) {
V_254 = V_256 = 0 ;
goto V_260;
}
if ( V_254 < V_1 -> V_48 )
goto V_258;
V_259 = V_1 -> V_43 / 1000 ;
V_257 = F_78 ( V_254 << 2 , V_259 ) ;
if ( V_257 && V_1 -> V_20 >= V_45 ) {
if ( V_257 >= 50 )
V_257 -- ;
}
} else {
V_257 = 0 ;
}
F_74 ( V_1 , V_118 , V_254 , V_256 , V_257 , V_256 ) ;
return;
V_258:
V_1 -> V_164 [ 0 ] = V_261 ;
V_1 -> V_143 = 1 ;
F_2 ( V_1 , V_218 ) ;
return;
V_260:
V_118 -> V_123 = V_254 ;
V_118 -> V_122 = V_256 ;
V_1 -> V_143 =
F_46 ( & V_1 -> V_164 [ 0 ] ,
V_118 -> V_123 ,
V_118 -> V_122 ) ;
F_2 ( V_1 , V_218 ) ;
}
static void F_79 ( struct V_1 * V_1 , struct V_117 * V_118 )
{
int V_262 = 8 << V_1 -> V_255 [ 3 ] ;
T_1 V_58 ;
if ( V_1 -> V_20 != V_46 )
goto V_258;
if ( V_262 != 8 && V_262 != 16 )
goto V_258;
if ( ! ( V_118 -> V_65 & V_165 ) )
goto V_258;
V_58 = V_118 -> V_33 ;
if ( V_262 == 16 ) {
V_118 -> V_65 |= V_249 ;
V_58 |= V_234 ;
} else {
V_118 -> V_65 &= ~ V_249 ;
V_58 &= ~ V_234 ;
}
V_118 -> V_33 = V_58 ;
V_1 -> V_54 = V_58 ;
F_3 ( V_58 , V_55 ) ;
V_118 -> V_65 &= ~ V_165 ;
F_33 ( V_118 -> V_120 ) = 0 ;
F_32 ( V_118 -> V_120 ) = 0 ;
if ( ! F_31 ( V_118 ) ) {
V_118 -> V_65 &= ~ V_159 ;
F_2 ( V_1 , V_253 ) ;
} else {
V_1 -> V_143 =
F_46 ( & V_1 -> V_164 [ 0 ] ,
V_118 -> V_123 ,
V_118 -> V_122 ) ;
V_118 -> V_65 |= V_166 ;
F_2 ( V_1 , V_218 ) ;
}
return;
V_258:
V_1 -> V_164 [ 0 ] = V_261 ;
V_1 -> V_143 = 1 ;
F_2 ( V_1 , V_218 ) ;
}
static void F_80 ( struct V_1 * V_1 )
{
struct V_93 * V_94 = V_1 -> V_141 ;
struct V_76 * V_77 = V_94 -> V_77 ;
struct V_117 * V_118 ;
int V_108 = V_77 -> V_134 -> V_136 ;
V_118 = & V_1 -> V_32 [ V_108 ] ;
if ( V_1 -> V_255 [ 2 ] == V_263 ) {
F_77 ( V_1 , V_118 ) ;
return;
}
if ( V_1 -> V_255 [ 2 ] == V_264 ) {
F_79 ( V_1 , V_118 ) ;
return;
}
F_6 ( L_37 ,
V_1 -> V_255 [ 2 ] ) ;
V_1 -> V_164 [ 0 ] = V_217 ;
V_1 -> V_143 = 1 ;
F_2 ( V_1 , V_218 ) ;
}
static int F_81 ( struct V_1 * V_1 )
{
T_1 V_265 = V_1 -> V_255 [ 0 ] ;
int V_100 = V_1 -> V_266 ;
if ( V_265 & 0x80 ) {
F_6 ( L_38 ) ;
return 0 ;
}
switch ( V_265 ) {
case V_267 :
if ( V_100 == 1 )
return 1 ;
if ( V_100 < V_1 -> V_255 [ 1 ] + 2 )
return 1 ;
F_80 ( V_1 ) ;
return 0 ;
case V_268 : {
struct V_93 * V_94 ;
struct V_78 * V_79 ;
if ( V_100 == 1 )
return 1 ;
if ( V_1 -> V_255 [ 1 ] != 1 )
goto V_258;
V_94 = V_1 -> V_141 ;
V_79 = F_14 ( V_94 -> V_77 ) ;
if ( V_79 -> V_90 == F_17 ( V_79 -> V_91 ) ) {
V_79 -> V_91 -- ;
V_79 -> V_90 = 1 ;
} else
V_79 -> V_90 ++ ;
V_79 -> V_92 ++ ;
return 0 ;
}
case V_269 :
return 0 ;
case V_270 :
F_24 ( V_1 , V_1 -> V_141 ) ;
return 0 ;
case V_271 :
F_23 ( V_1 , V_1 -> V_141 ) ;
return 0 ;
case V_186 :
case V_272 : {
struct V_93 * V_94 = V_1 -> V_141 ;
V_94 -> V_191 = V_265 ;
F_4 ( V_1 , V_273 ) ;
V_1 -> V_65 |= V_220 ;
return 0 ;
}
case V_261 :
F_76 ( V_1 ) ;
return 0 ;
default:
V_258:
V_1 -> V_164 [ 0 ] = V_261 ;
V_1 -> V_143 = 1 ;
F_2 ( V_1 , V_218 ) ;
return 0 ;
}
}
static int F_82 ( struct V_1 * V_1 )
{
int V_274 ;
V_275:
V_274 = 0 ;
switch ( V_1 -> V_9 ) {
case V_219 :
switch ( V_1 -> V_4 & V_203 ) {
case V_243 :
F_4 ( V_1 , V_276 ) ;
break;
case V_230 :
F_4 ( V_1 , V_277 ) ;
break;
case V_278 :
F_7 ( V_1 ) ;
F_2 ( V_1 , V_279 ) ;
F_4 ( V_1 , V_280 ) ;
V_1 -> V_65 |= V_220 ;
return 1 ;
case V_281 :
F_4 ( V_1 , V_282 ) ;
break;
case V_204 :
F_4 ( V_1 , V_283 ) ;
break;
case V_284 :
F_4 ( V_1 , V_285 ) ;
break;
default:
F_6 ( L_39 ,
V_1 -> V_4 ) ;
F_64 ( V_1 ) ;
return 0 ;
}
goto V_275;
break;
case V_277 :
V_274 = 1 ;
case V_276 : {
struct V_93 * V_94 = V_1 -> V_141 ;
struct V_76 * V_77 = V_94 -> V_77 ;
T_3 V_113 = F_18 ( V_94 , V_77 ) ;
unsigned int V_114 = F_20 ( V_94 , V_77 ) ;
if ( V_1 -> V_20 == V_51 )
F_2 ( V_1 , V_37 ) ;
if ( V_274 )
V_94 -> V_65 |= V_240 ;
else
V_94 -> V_65 &= ~ V_240 ;
if ( V_1 -> V_88 -> V_286 )
V_114 = V_1 -> V_88 -> V_286 ( V_1 , V_113 ,
V_114 ) ;
else
V_114 = F_28 ( V_1 , V_113 , V_114 ) ;
V_1 -> V_239 = V_114 ;
if ( ! V_114 ) {
F_6 (KERN_ERR PFX L_40 ,
esp->host->unique_id) ;
F_6 (KERN_ERR PFX L_41 ,
esp->host->unique_id,
(unsigned long long)esp_cur_dma_addr(ent, cmd),
esp_cur_dma_len(ent, cmd)) ;
F_64 ( V_1 ) ;
return 0 ;
}
F_83 ( L_42
L_43 ,
( unsigned long long ) V_113 , V_114 , V_274 ) ;
V_1 -> V_88 -> V_151 ( V_1 , V_113 , V_114 , V_114 ,
V_274 , V_38 | V_205 ) ;
F_4 ( V_1 , V_287 ) ;
break;
}
case V_287 : {
struct V_93 * V_94 = V_1 -> V_141 ;
struct V_76 * V_77 = V_94 -> V_77 ;
int V_232 ;
if ( V_1 -> V_88 -> V_197 ( V_1 ) ) {
F_6 ( L_44 ) ;
F_64 ( V_1 ) ;
return 0 ;
}
if ( V_94 -> V_65 & V_240 ) {
V_1 -> V_88 -> V_209 ( V_1 ) ;
}
V_1 -> V_88 -> V_210 ( V_1 ) ;
if ( V_1 -> V_7 != V_229 ) {
F_6 ( L_45 ) ;
F_64 ( V_1 ) ;
return 0 ;
}
V_232 = F_73 ( V_1 , V_94 , V_77 ) ;
F_84 ( L_46 ,
V_94 -> V_65 , V_232 ) ;
if ( V_232 < 0 ) {
F_64 ( V_1 ) ;
return 0 ;
}
F_21 ( V_1 , V_94 , V_77 , V_232 ) ;
F_4 ( V_1 , V_219 ) ;
goto V_275;
}
case V_280 : {
struct V_93 * V_94 = V_1 -> V_141 ;
if ( V_1 -> V_7 & V_208 ) {
V_94 -> V_190 = F_8 ( V_27 ) ;
V_94 -> V_191 = F_8 ( V_27 ) ;
F_2 ( V_1 , V_206 ) ;
} else if ( V_1 -> V_7 == V_229 ) {
V_94 -> V_190 = F_8 ( V_27 ) ;
V_94 -> V_191 = 0xff ;
F_4 ( V_1 , V_283 ) ;
return 0 ;
}
if ( V_94 -> V_191 != V_186 ) {
F_6 ( L_47 ,
V_94 -> V_191 ) ;
F_64 ( V_1 ) ;
return 0 ;
}
F_4 ( V_1 , V_273 ) ;
V_1 -> V_65 |= V_220 ;
break;
}
case V_273 : {
struct V_93 * V_94 = V_1 -> V_141 ;
struct V_76 * V_77 = V_94 -> V_77 ;
if ( V_94 -> V_191 == V_186 ||
V_94 -> V_191 == V_272 )
F_2 ( V_1 , V_227 ) ;
if ( V_94 -> V_191 == V_186 ) {
F_85 ( L_48
L_49 ,
V_94 -> V_190 , V_94 -> V_191 ) ;
if ( V_94 -> V_190 == V_288 )
F_57 ( V_1 , V_94 ) ;
if ( V_94 -> V_190 == V_187 &&
! ( V_94 -> V_65 & V_95 ) ) {
V_94 -> V_65 |= V_95 ;
F_37 ( V_1 , V_94 ) ;
} else {
F_54 ( V_1 , V_94 , V_77 ,
F_56 ( V_94 -> V_190 ,
V_94 -> V_191 ,
V_185 ) ) ;
}
} else if ( V_94 -> V_191 == V_272 ) {
F_86 ( L_50
L_51 ,
V_77 -> V_134 -> V_136 ,
V_94 -> V_126 [ 0 ] , V_94 -> V_126 [ 1 ] ) ;
V_1 -> V_141 = NULL ;
F_43 ( V_1 ) ;
} else {
F_6 ( L_52 ,
V_94 -> V_191 ) ;
F_64 ( V_1 ) ;
return 0 ;
}
if ( V_1 -> V_141 )
V_1 -> V_65 |= V_220 ;
break;
}
case V_282 : {
F_2 ( V_1 , V_19 ) ;
if ( V_173 & V_289 ) {
int V_30 ;
F_6 ( L_53 ) ;
for ( V_30 = 0 ; V_30 < V_1 -> V_143 ; V_30 ++ )
F_6 ( L_15 , V_1 -> V_164 [ V_30 ] ) ;
F_6 ( L_16 ) ;
}
if ( V_1 -> V_20 == V_46 ) {
int V_30 ;
for ( V_30 = 0 ; V_30 < V_1 -> V_143 ; V_30 ++ ) {
F_3 ( V_1 -> V_164 [ V_30 ] , V_27 ) ;
F_3 ( 0 , V_27 ) ;
}
F_2 ( V_1 , V_205 ) ;
} else {
if ( V_1 -> V_143 == 1 ) {
F_3 ( V_1 -> V_164 [ 0 ] , V_27 ) ;
F_2 ( V_1 , V_205 ) ;
} else {
memcpy ( V_1 -> V_142 ,
V_1 -> V_164 ,
V_1 -> V_143 ) ;
V_1 -> V_88 -> V_151 ( V_1 ,
V_1 -> V_152 ,
V_1 -> V_143 ,
V_1 -> V_143 ,
0 ,
V_38 | V_205 ) ;
}
}
F_4 ( V_1 , V_290 ) ;
break;
}
case V_290 :
if ( V_1 -> V_20 == V_46 ) {
F_2 ( V_1 , V_19 ) ;
} else {
if ( V_1 -> V_143 > 1 )
V_1 -> V_88 -> V_210 ( V_1 ) ;
}
if ( ! ( V_1 -> V_7 & V_202 ) ) {
if ( V_1 -> V_20 != V_46 )
F_2 ( V_1 , V_37 ) ;
}
F_4 ( V_1 , V_219 ) ;
goto V_275;
case V_283 :
if ( V_1 -> V_7 & V_229 ) {
if ( V_1 -> V_20 == V_46 ) {
if ( ! ( F_8 ( V_291 ) &
V_292 ) )
F_2 ( V_1 , V_19 ) ;
} else {
F_2 ( V_1 , V_19 ) ;
if ( V_1 -> V_20 == V_51 )
F_2 ( V_1 , V_37 ) ;
}
F_2 ( V_1 , V_205 ) ;
V_1 -> V_65 |= V_220 ;
return 1 ;
}
if ( V_1 -> V_7 & V_208 ) {
T_1 V_10 ;
if ( V_1 -> V_20 == V_46 )
V_10 = V_1 -> V_26 [ 0 ] ;
else
V_10 = F_8 ( V_27 ) ;
V_1 -> V_255 [ V_1 -> V_266 ++ ] = V_10 ;
F_87 ( L_54 , V_10 ) ;
if ( ! F_81 ( V_1 ) )
V_1 -> V_266 = 0 ;
if ( V_1 -> V_20 == V_46 )
F_2 ( V_1 , V_19 ) ;
F_2 ( V_1 , V_206 ) ;
if ( V_1 -> V_9 != V_273 )
F_4 ( V_1 , V_219 ) ;
} else {
F_6 ( L_55 ) ;
F_64 ( V_1 ) ;
return 0 ;
}
break;
case V_285 :
memcpy ( V_1 -> V_142 , V_1 -> V_170 ,
V_1 -> V_169 ) ;
if ( V_1 -> V_20 == V_46 )
F_2 ( V_1 , V_19 ) ;
V_1 -> V_88 -> V_151 ( V_1 , V_1 -> V_152 ,
V_1 -> V_169 , 16 , 0 ,
V_38 | V_205 ) ;
F_4 ( V_1 , V_293 ) ;
V_1 -> V_65 |= V_220 ;
break;
case V_293 :
V_1 -> V_88 -> V_210 ( V_1 ) ;
if ( V_1 -> V_7 & V_229 ) {
F_4 ( V_1 , V_219 ) ;
goto V_275;
}
F_64 ( V_1 ) ;
return 0 ;
break;
case V_198 :
F_2 ( V_1 , V_294 ) ;
break;
default:
F_6 ( L_56 ,
V_1 -> V_9 ) ;
F_64 ( V_1 ) ;
return 0 ;
break;
}
return 1 ;
}
static void F_88 ( struct V_1 * V_1 , struct V_93 * V_94 )
{
struct V_76 * V_77 = V_94 -> V_77 ;
F_22 ( V_1 , V_77 ) ;
F_36 ( V_94 , V_77 -> V_134 -> V_154 ) ;
V_77 -> V_181 = V_295 << 16 ;
if ( V_94 -> V_65 & V_95 ) {
V_1 -> V_88 -> V_183 ( V_1 , V_94 -> V_96 ,
V_99 , V_140 ) ;
V_94 -> V_97 = NULL ;
}
V_77 -> V_189 ( V_77 ) ;
F_51 ( & V_94 -> V_157 ) ;
F_52 ( V_1 , V_94 ) ;
}
static void F_89 ( struct V_132 * V_133 , void * V_296 )
{
struct V_124 * V_125 = V_133 -> V_154 ;
F_35 ( V_125 -> V_130 ) ;
V_125 -> V_129 = 0 ;
}
static void F_90 ( struct V_1 * V_1 )
{
struct V_93 * V_94 , * V_297 ;
int V_30 ;
F_91 (ent, tmp, &esp->queued_cmds, list) {
struct V_76 * V_77 = V_94 -> V_77 ;
F_51 ( & V_94 -> V_157 ) ;
V_77 -> V_181 = V_295 << 16 ;
V_77 -> V_189 ( V_77 ) ;
F_52 ( V_1 , V_94 ) ;
}
F_91 (ent, tmp, &esp->active_cmds, list) {
if ( V_94 == V_1 -> V_141 )
V_1 -> V_141 = NULL ;
F_88 ( V_1 , V_94 ) ;
}
F_35 ( V_1 -> V_141 != NULL ) ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
struct V_117 * V_118 = & V_1 -> V_32 [ V_30 ] ;
V_118 -> V_112 = 0 ;
V_118 -> V_110 = 0 ;
V_118 -> V_33 &= ~ ( V_234 |
V_251 |
V_252 ) ;
V_118 -> V_65 &= ~ V_249 ;
V_118 -> V_65 |= V_159 ;
if ( V_118 -> V_120 )
F_92 ( V_118 -> V_120 , NULL ,
F_89 ) ;
}
V_1 -> V_65 &= ~ V_156 ;
}
static void F_93 ( struct V_1 * V_1 )
{
int V_298 , V_299 ;
T_1 V_242 ;
V_1 -> V_4 = F_8 ( V_201 ) ;
if ( V_1 -> V_65 & V_156 ) {
V_298 = 1 ;
} else {
if ( F_94 ( V_1 ) )
return;
V_298 = F_63 ( V_1 ) ;
if ( V_298 < 0 )
return;
}
V_1 -> V_7 = F_8 ( V_75 ) ;
if ( V_1 -> V_7 & V_196 )
V_298 = 1 ;
if ( V_298 ) {
F_90 ( V_1 ) ;
if ( V_1 -> V_300 ) {
F_55 ( V_1 -> V_300 ) ;
V_1 -> V_300 = NULL ;
}
return;
}
V_242 = ( V_1 -> V_4 & V_203 ) ;
if ( V_1 -> V_20 == V_46 ) {
if ( ( ( V_242 != V_230 && V_242 != V_243 ) &&
V_1 -> V_8 == V_222 &&
V_1 -> V_9 != V_280 &&
V_1 -> V_9 != V_287 ) ||
( V_1 -> V_7 & V_226 ) ) {
V_1 -> V_6 = F_8 ( V_291 ) ;
if ( ! ( V_1 -> V_6 & V_292 ) ||
( V_1 -> V_6 & V_28 ) )
F_10 ( V_1 ) ;
}
}
F_95 ( L_57
L_58 ,
V_1 -> V_4 , V_1 -> V_5 , V_1 -> V_6 , V_1 -> V_7 ) ;
V_299 = 0 ;
if ( V_1 -> V_7 & ( V_301 | V_302 | V_303 ) ) {
F_6 ( L_59 , V_1 -> V_7 ) ;
if ( V_1 -> V_7 & V_303 )
F_5 ( V_1 ) ;
F_64 ( V_1 ) ;
} else {
if ( ! ( V_1 -> V_7 & V_226 ) ) {
if ( V_1 -> V_8 != V_222 )
V_299 = F_72 ( V_1 ) ;
} else if ( V_1 -> V_7 & V_226 ) {
if ( V_1 -> V_141 )
( void ) F_72 ( V_1 ) ;
V_299 = F_69 ( V_1 ) ;
}
}
while ( ! V_299 )
V_299 = F_82 ( V_1 ) ;
}
T_4 F_96 ( int V_304 , void * V_305 )
{
struct V_1 * V_1 = V_305 ;
unsigned long V_65 ;
T_4 V_178 ;
F_97 ( V_1 -> V_137 -> V_306 , V_65 ) ;
V_178 = V_307 ;
if ( V_1 -> V_88 -> V_200 ( V_1 ) ) {
V_178 = V_308 ;
for (; ; ) {
int V_30 ;
F_93 ( V_1 ) ;
if ( ! ( V_1 -> V_65 & V_220 ) )
break;
V_1 -> V_65 &= ~ V_220 ;
for ( V_30 = 0 ; V_30 < V_199 ; V_30 ++ ) {
if ( V_1 -> V_88 -> V_200 ( V_1 ) )
break;
}
if ( V_30 == V_199 )
break;
}
}
F_98 ( V_1 -> V_137 -> V_306 , V_65 ) ;
return V_178 ;
}
static void F_99 ( struct V_1 * V_1 )
{
T_1 V_10 ;
V_1 -> V_49 = ( V_309 | ( V_1 -> V_61 & 7 ) ) ;
V_1 -> V_53 = ( V_310 | V_311 ) ;
F_3 ( V_1 -> V_53 , V_41 ) ;
V_10 = F_8 ( V_41 ) ;
V_10 &= ~ V_312 ;
if ( V_10 != ( V_310 | V_311 ) ) {
V_1 -> V_20 = V_51 ;
} else {
V_1 -> V_53 = 0 ;
F_11 ( V_1 , 5 ) ;
V_1 -> V_54 = 5 ;
F_3 ( V_1 -> V_53 , V_41 ) ;
F_3 ( 0 , V_55 ) ;
F_3 ( V_1 -> V_54 , V_55 ) ;
V_10 = F_8 ( V_55 ) ;
if ( V_10 != 5 ) {
V_1 -> V_20 = V_52 ;
} else {
F_11 ( V_1 , 0 ) ;
V_1 -> V_54 = 0 ;
F_3 ( V_1 -> V_54 , V_55 ) ;
if ( V_1 -> V_67 == 0 || V_1 -> V_67 > V_313 ) {
V_1 -> V_20 = V_39 ;
V_1 -> V_314 = V_315 ;
} else {
V_1 -> V_20 = V_21 ;
}
V_1 -> V_53 = 0 ;
F_3 ( V_1 -> V_53 , V_41 ) ;
}
}
}
static void F_100 ( struct V_1 * V_1 )
{
int V_30 ;
F_101 ( & V_1 -> V_194 ) ;
F_101 ( & V_1 -> V_158 ) ;
F_101 ( & V_1 -> V_177 ) ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
V_1 -> V_32 [ V_30 ] . V_65 = 0 ;
V_1 -> V_32 [ V_30 ] . V_123 = 0 ;
V_1 -> V_32 [ V_30 ] . V_122 = 0 ;
V_1 -> V_32 [ V_30 ] . V_121 = 0 ;
V_1 -> V_32 [ V_30 ] . V_162 = 0 ;
}
}
static void F_102 ( struct V_1 * V_1 )
{
T_1 V_10 ;
V_1 -> V_88 -> V_316 ( V_1 ) ;
F_12 ( V_1 ) ;
V_10 = F_8 ( V_50 ) ;
V_10 |= V_317 ;
F_3 ( V_10 , V_50 ) ;
F_2 ( V_1 , V_294 ) ;
F_9 ( 400 ) ;
F_3 ( V_1 -> V_49 , V_50 ) ;
F_8 ( V_75 ) ;
}
static void F_103 ( struct V_1 * V_1 )
{
int V_318 ;
T_1 V_319 ;
V_318 = V_1 -> V_320 ;
V_319 = ( ( V_318 / 1000000 ) + 4 ) / 5 ;
if ( V_319 == 1 )
V_319 = 2 ;
if ( V_318 <= 5000000 || V_319 < 1 || V_319 > 8 ) {
V_318 = 20000000 ;
V_319 = 4 ;
}
V_1 -> V_67 = ( V_319 == 8 ? 0 : V_319 ) ;
V_1 -> V_320 = V_318 ;
V_1 -> V_43 = F_104 ( V_318 ) ;
V_1 -> V_321 = F_105 ( V_319 , V_1 -> V_43 ) ;
V_1 -> V_73 = F_106 ( V_318 , V_319 ) ;
V_1 -> V_314 = V_322 ;
}
int F_107 ( struct V_1 * V_1 , struct V_134 * V_133 )
{
static int V_323 ;
int V_324 ;
V_1 -> V_137 -> V_325 = V_326 ;
V_1 -> V_137 -> V_327 = V_328 ;
V_1 -> V_137 -> V_329 = 2 ;
V_1 -> V_137 -> V_138 = V_323 ;
F_103 ( V_1 ) ;
F_99 ( V_1 ) ;
F_100 ( V_1 ) ;
F_102 ( V_1 ) ;
F_6 (KERN_INFO PFX L_60 ,
esp->host->unique_id, esp->regs, esp->dma_regs,
esp->host->irq) ;
F_6 (KERN_INFO PFX L_61 ,
esp->host->unique_id, esp_chip_names[esp->rev],
esp->cfreq / 1000000 , esp->cfact, esp->scsi_id) ;
F_108 ( V_330 ) ;
V_324 = F_109 ( V_1 -> V_137 , V_133 ) ;
if ( V_324 )
return V_324 ;
V_323 ++ ;
F_110 ( V_1 -> V_137 ) ;
return 0 ;
}
void F_111 ( struct V_1 * V_1 )
{
F_112 ( V_1 -> V_137 ) ;
}
static int F_113 ( struct V_119 * V_120 )
{
struct V_1 * V_1 = F_61 ( F_114 ( & V_120 -> V_133 ) ) ;
struct V_117 * V_118 = & V_1 -> V_32 [ V_120 -> V_136 ] ;
V_118 -> V_120 = V_120 ;
return 0 ;
}
static void F_115 ( struct V_119 * V_120 )
{
struct V_1 * V_1 = F_61 ( F_114 ( & V_120 -> V_133 ) ) ;
struct V_117 * V_118 = & V_1 -> V_32 [ V_120 -> V_136 ] ;
V_118 -> V_120 = NULL ;
}
static int F_116 ( struct V_132 * V_133 )
{
struct V_1 * V_1 = F_61 ( V_133 -> V_137 ) ;
struct V_117 * V_118 = & V_1 -> V_32 [ V_133 -> V_136 ] ;
struct V_124 * V_125 ;
V_125 = F_49 ( sizeof( * V_125 ) , V_331 ) ;
if ( ! V_125 )
return - V_332 ;
V_133 -> V_154 = V_125 ;
F_117 ( V_118 -> V_120 ) = V_1 -> V_48 ;
F_118 ( V_118 -> V_120 ) = 15 ;
if ( V_1 -> V_65 & V_333 )
F_119 ( V_118 -> V_120 ) = 1 ;
else
F_119 ( V_118 -> V_120 ) = 0 ;
return 0 ;
}
static int F_120 ( struct V_132 * V_133 )
{
struct V_1 * V_1 = F_61 ( V_133 -> V_137 ) ;
struct V_117 * V_118 = & V_1 -> V_32 [ V_133 -> V_136 ] ;
int V_334 , V_335 ;
V_334 = 0 ;
if ( V_133 -> V_336 ) {
V_334 = V_337 ;
if ( V_334 > V_338 )
V_334 = V_338 ;
}
V_335 = V_334 ;
if ( V_335 < V_133 -> V_137 -> V_329 )
V_335 = V_133 -> V_137 -> V_329 ;
if ( V_334 ) {
F_121 ( V_133 , V_339 ) ;
F_122 ( V_133 , V_335 ) ;
} else {
F_123 ( V_133 , V_335 ) ;
}
V_118 -> V_65 |= V_161 ;
if ( ! F_124 ( V_133 -> V_340 ) )
F_125 ( V_133 ) ;
return 0 ;
}
static void F_126 ( struct V_132 * V_133 )
{
struct V_124 * V_125 = V_133 -> V_154 ;
F_127 ( V_125 ) ;
V_133 -> V_154 = NULL ;
}
static int F_128 ( struct V_76 * V_77 )
{
struct V_1 * V_1 = F_61 ( V_77 -> V_134 -> V_137 ) ;
struct V_93 * V_94 , * V_297 ;
struct V_341 V_182 ;
unsigned long V_65 ;
F_97 ( V_1 -> V_137 -> V_306 , V_65 ) ;
F_6 (KERN_ERR PFX L_62 ,
esp->host->unique_id, cmd, cmd->cmnd[0]) ;
V_94 = V_1 -> V_141 ;
if ( V_94 )
F_6 (KERN_ERR PFX L_63 ,
esp->host->unique_id, ent->cmd, ent->cmd->cmnd[0]) ;
F_41 (ent, &esp->queued_cmds, list) {
F_6 (KERN_ERR PFX L_64 ,
esp->host->unique_id, ent->cmd, ent->cmd->cmnd[0]) ;
}
F_41 (ent, &esp->active_cmds, list) {
F_6 (KERN_ERR PFX L_65 ,
esp->host->unique_id, ent->cmd, ent->cmd->cmnd[0]) ;
}
F_5 ( V_1 ) ;
F_98 ( V_1 -> V_137 -> V_306 , V_65 ) ;
F_97 ( V_1 -> V_137 -> V_306 , V_65 ) ;
V_94 = NULL ;
F_41 (tmp, &esp->queued_cmds, list) {
if ( V_297 -> V_77 == V_77 ) {
V_94 = V_297 ;
break;
}
}
if ( V_94 ) {
F_51 ( & V_94 -> V_157 ) ;
V_77 -> V_181 = V_342 << 16 ;
V_77 -> V_189 ( V_77 ) ;
F_52 ( V_1 , V_94 ) ;
goto V_343;
}
F_129 ( & V_182 ) ;
V_94 = V_1 -> V_141 ;
if ( V_94 && V_94 -> V_77 == V_77 ) {
if ( V_1 -> V_143 )
goto V_344;
V_1 -> V_164 [ 0 ] = V_217 ;
V_1 -> V_143 = 1 ;
V_94 -> V_182 = & V_182 ;
F_2 ( V_1 , V_218 ) ;
} else {
goto V_344;
}
F_98 ( V_1 -> V_137 -> V_306 , V_65 ) ;
if ( ! F_130 ( & V_182 , 5 * V_345 ) ) {
F_97 ( V_1 -> V_137 -> V_306 , V_65 ) ;
V_94 -> V_182 = NULL ;
F_98 ( V_1 -> V_137 -> V_306 , V_65 ) ;
return V_346 ;
}
return V_347 ;
V_343:
F_98 ( V_1 -> V_137 -> V_306 , V_65 ) ;
return V_347 ;
V_344:
F_98 ( V_1 -> V_137 -> V_306 , V_65 ) ;
return V_346 ;
}
static int F_131 ( struct V_76 * V_77 )
{
struct V_1 * V_1 = F_61 ( V_77 -> V_134 -> V_137 ) ;
struct V_341 V_300 ;
unsigned long V_65 ;
F_129 ( & V_300 ) ;
F_97 ( V_1 -> V_137 -> V_306 , V_65 ) ;
V_1 -> V_300 = & V_300 ;
V_1 -> V_65 |= V_156 ;
F_2 ( V_1 , V_294 ) ;
F_98 ( V_1 -> V_137 -> V_306 , V_65 ) ;
F_108 ( V_330 ) ;
if ( ! F_130 ( & V_300 , 5 * V_345 ) ) {
F_97 ( V_1 -> V_137 -> V_306 , V_65 ) ;
V_1 -> V_300 = NULL ;
F_98 ( V_1 -> V_137 -> V_306 , V_65 ) ;
return V_346 ;
}
return V_347 ;
}
static int F_132 ( struct V_76 * V_77 )
{
struct V_1 * V_1 = F_61 ( V_77 -> V_134 -> V_137 ) ;
unsigned long V_65 ;
F_97 ( V_1 -> V_137 -> V_306 , V_65 ) ;
F_102 ( V_1 ) ;
F_90 ( V_1 ) ;
F_98 ( V_1 -> V_137 -> V_306 , V_65 ) ;
F_108 ( V_330 ) ;
return V_347 ;
}
static const char * F_133 ( struct V_348 * V_137 )
{
return L_66 ;
}
static void F_134 ( struct V_348 * V_137 )
{
struct V_1 * V_1 = F_61 ( V_137 ) ;
enum V_349 type ;
if ( V_1 -> V_65 & V_66 )
type = V_350 ;
else
type = V_351 ;
F_135 ( V_137 ) = type ;
}
static void F_136 ( struct V_119 * V_32 , int V_256 )
{
struct V_348 * V_137 = F_114 ( V_32 -> V_133 . V_352 ) ;
struct V_1 * V_1 = F_61 ( V_137 ) ;
struct V_117 * V_118 = & V_1 -> V_32 [ V_32 -> V_136 ] ;
if ( V_1 -> V_65 & V_353 )
V_118 -> V_122 = 0 ;
else
V_118 -> V_122 = V_256 ;
V_118 -> V_65 |= V_159 ;
}
static void F_137 ( struct V_119 * V_32 , int V_254 )
{
struct V_348 * V_137 = F_114 ( V_32 -> V_133 . V_352 ) ;
struct V_1 * V_1 = F_61 ( V_137 ) ;
struct V_117 * V_118 = & V_1 -> V_32 [ V_32 -> V_136 ] ;
V_118 -> V_123 = V_254 ;
V_118 -> V_65 |= V_159 ;
}
static void F_138 ( struct V_119 * V_32 , int V_354 )
{
struct V_348 * V_137 = F_114 ( V_32 -> V_133 . V_352 ) ;
struct V_1 * V_1 = F_61 ( V_137 ) ;
struct V_117 * V_118 = & V_1 -> V_32 [ V_32 -> V_136 ] ;
V_118 -> V_121 = ( V_354 ? 1 : 0 ) ;
V_118 -> V_65 |= V_159 ;
}
static int T_5 F_139 ( void )
{
F_140 ( sizeof( struct V_355 ) <
sizeof( struct V_78 ) ) ;
V_326 = F_141 ( & V_356 ) ;
if ( ! V_326 )
return - V_357 ;
return 0 ;
}
static void T_6 F_142 ( void )
{
F_143 ( V_326 ) ;
}

static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_6 ) ;
struct V_7 * V_9 ;
struct V_5 * V_10 ;
unsigned int V_11 ;
int V_12 = 0 ;
if ( V_8 -> V_13 . V_14 [ 0 ] . V_15 & V_16 )
V_11 = sizeof( struct V_17 ) ;
else
V_11 = sizeof( struct V_18 ) ;
V_10 = F_3 ( V_11 + V_2 -> V_19 -> V_20 ) ;
if ( F_4 ( ! V_10 ) ) {
F_5 ( V_2 , L_1 ) ;
return - V_21 ;
}
F_6 ( V_10 , V_2 -> V_19 -> V_20 ) ;
F_7 ( V_10 , V_11 ) ;
memcpy ( V_10 -> V_22 , V_6 -> V_22 , sizeof( V_10 -> V_22 ) ) ;
V_9 = F_2 ( V_10 ) ;
V_9 -> V_13 . V_14 [ 0 ] . V_15 &= ~ V_23 ;
V_9 -> V_13 . V_14 [ 0 ] . V_15 &= ~ V_16 ;
if ( V_8 -> V_13 . V_14 [ 0 ] . V_15 & V_16 )
V_9 -> V_15 |= V_24 ;
else
V_9 -> V_15 &= ~ V_24 ;
V_9 -> V_13 . V_25 = NULL ;
V_11 += F_8 ( V_2 , V_10 ) ;
if ( V_8 -> V_13 . V_14 [ 0 ] . V_15 & V_16 )
F_9 ( V_2 -> V_19 , V_8 -> V_13 . V_26 ,
V_6 -> V_27 , V_11 , V_8 ,
(struct V_17 * ) ( V_10 -> V_27 ) ) ;
else
F_10 ( V_2 -> V_19 , V_8 -> V_13 . V_26 ,
V_6 -> V_27 , V_11 , V_8 ,
(struct V_18 * ) ( V_10 -> V_27 ) ) ;
V_12 = F_11 ( V_4 , V_10 , NULL , true ) ;
if ( V_12 ) {
F_12 ( V_10 ) ;
F_5 ( V_2 , L_2 ) ;
}
return V_12 ;
}
void F_13 ( struct V_28 * V_19 ,
struct V_29 * V_13 ,
struct V_5 * V_10 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_7 * V_8 = F_2 ( V_10 ) ;
enum V_31 V_32 = F_14 ( V_10 ) ;
struct V_3 * V_4 = NULL ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
goto V_34;
if ( V_8 -> V_15 & V_35 &&
F_16 ( V_2 , V_36 ) )
V_32 = V_37 ;
V_4 = F_17 ( V_2 , V_32 ) ;
if ( F_4 ( ! V_4 ) ) {
F_18 ( V_2 ,
L_3
L_4 , V_32 , V_38 ) ;
goto V_34;
}
if ( ! V_2 -> V_39 -> V_19 -> V_40 &&
( V_8 -> V_13 . V_14 [ 0 ] . V_15 & ( V_23 |
V_16 ) ) ) {
if ( F_19 ( V_4 ) <= 1 )
goto V_41;
if ( F_1 ( V_2 , V_4 , V_10 ) )
goto V_41;
}
if ( F_4 ( F_11 ( V_4 , V_10 , V_13 -> V_42 , false ) ) )
goto V_41;
F_20 ( & V_4 -> V_43 ) ;
if ( F_21 ( V_4 ) )
F_22 ( V_4 ) ;
F_23 ( & V_4 -> V_43 ) ;
return;
V_41:
F_20 ( & V_4 -> V_43 ) ;
F_22 ( V_4 ) ;
F_23 ( & V_4 -> V_43 ) ;
V_34:
F_24 ( V_19 , V_10 ) ;
}
int F_25 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
return 0 ;
return F_26 ( V_2 ) ;
}
void F_27 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
return;
F_28 ( V_2 ) ;
}
int F_29 ( struct V_28 * V_19 ,
struct V_44 * V_26 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_45 * V_46 = F_30 ( V_26 ) ;
struct V_3 * V_4 = V_2 -> V_47 ;
struct V_48 * V_49 = NULL ;
unsigned int V_50 ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) ||
! F_15 ( V_51 , & V_2 -> V_15 ) )
return - V_52 ;
for ( V_50 = 0 ; V_50 < V_4 -> V_53 ; V_50 ++ ) {
V_49 = & V_4 -> V_54 [ V_50 ] ;
if ( ! F_31 ( V_55 , & V_49 -> V_15 ) )
break;
}
if ( F_4 ( V_50 == V_4 -> V_53 ) )
return - V_56 ;
if ( V_26 -> type == V_57 )
V_2 -> V_58 ++ ;
else
V_2 -> V_59 ++ ;
F_32 ( & V_46 -> V_60 ) ;
V_46 -> V_61 = V_49 ;
F_33 ( V_2 , V_46 , V_26 -> type ,
V_26 -> V_62 , NULL ) ;
V_2 -> V_63 = 0 ;
return 0 ;
}
void F_34 ( struct V_28 * V_19 ,
struct V_44 * V_26 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_45 * V_46 = F_30 ( V_26 ) ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) ||
( V_26 -> type == V_57 && ! V_2 -> V_58 ) ||
( V_26 -> type != V_57 && ! V_2 -> V_59 ) )
return;
if ( V_26 -> type == V_57 )
V_2 -> V_58 -- ;
else
V_2 -> V_59 -- ;
F_35 ( V_55 , & V_46 -> V_61 -> V_15 ) ;
F_33 ( V_2 , V_46 ,
V_64 , NULL , NULL ) ;
}
int F_36 ( struct V_28 * V_19 , T_1 V_65 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_66 * V_67 = & V_19 -> V_67 ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
return 0 ;
F_37 ( V_2 -> V_68 ) ;
F_38 ( & V_2 -> V_69 ) ;
F_39 ( V_2 , V_67 , V_65 ) ;
F_40 ( V_2 , V_2 -> V_70 ) ;
F_41 ( & V_2 -> V_69 ) ;
F_42 ( V_2 -> V_68 ) ;
return 0 ;
}
void F_43 ( struct V_28 * V_19 ,
unsigned int V_71 ,
unsigned int * V_72 ,
T_2 V_73 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
* V_72 &=
V_74 |
V_75 |
V_76 |
V_77 |
V_78 |
V_79 ;
* V_72 |= V_74 ;
if ( ! F_44 ( V_2 ) ) {
if ( * V_72 & V_77 || * V_72 & V_78 )
* V_72 |= V_77 | V_78 ;
}
if ( ! F_45 ( V_2 ) ) {
if ( * V_72 & V_77 )
* V_72 |= V_78 ;
}
V_2 -> V_63 = * V_72 ;
V_2 -> V_39 -> V_80 -> V_81 ( V_2 , * V_72 ) ;
}
static void F_46 ( void * V_27 , T_3 * V_82 ,
struct V_44 * V_26 )
{
struct V_45 * V_46 = F_30 ( V_26 ) ;
if ( V_26 -> type != V_57 &&
V_26 -> type != V_83 &&
V_26 -> type != V_84 &&
V_26 -> type != V_85 )
return;
F_47 ( V_86 , & V_46 -> V_87 ) ;
}
int F_48 ( struct V_28 * V_19 , struct V_88 * V_42 ,
bool V_89 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
if ( ! F_15 ( V_90 , & V_2 -> V_15 ) )
return 0 ;
F_49 (
V_2 -> V_19 , V_91 ,
F_46 , V_2 ) ;
F_50 ( V_2 -> V_19 , & V_2 -> V_92 ) ;
return 0 ;
}
static void F_51 ( struct V_93 * V_94 , T_3 * V_95 , T_3 V_96 )
{
if ( V_96 > V_97 )
memcpy ( V_94 -> V_95 ,
& V_95 [ V_97 ] ,
sizeof( V_94 -> V_95 ) ) ;
if ( V_96 > V_98 )
memcpy ( V_94 -> V_99 ,
& V_95 [ V_98 ] ,
sizeof( V_94 -> V_99 ) ) ;
if ( V_96 > V_100 )
memcpy ( V_94 -> V_101 ,
& V_95 [ V_100 ] ,
sizeof( V_94 -> V_101 ) ) ;
}
int F_52 ( struct V_28 * V_19 , enum V_102 V_103 ,
struct V_44 * V_26 , struct V_88 * V_42 ,
struct V_104 * V_95 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
int (* F_53) ( struct V_1 * V_2 ,
struct V_93 * V_94 ,
struct V_104 * V_95 );
struct V_93 V_94 ;
static const T_3 V_105 [ V_106 ] =
{ 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , } ;
struct V_107 * V_108 = NULL ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
return 0 ;
if ( ! F_54 ( V_2 ) )
return - V_109 ;
if ( V_26 -> type == V_83 &&
! ( V_95 -> V_15 & V_110 ) )
return - V_109 ;
if ( V_95 -> V_111 > 32 )
return - V_112 ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
V_94 . V_113 = F_55 ( V_2 , V_26 ) ;
V_94 . V_114 = F_56 ( V_95 ) ;
if ( V_94 . V_114 == V_115 )
return - V_109 ;
if ( V_94 . V_114 == V_116 && F_57 ( V_2 ) )
return - V_109 ;
V_94 . V_103 = V_103 ;
if ( V_42 ) {
V_94 . V_117 = V_42 -> V_62 ;
V_108 = F_58 ( V_42 ) ;
V_94 . V_118 = V_108 -> V_118 ;
} else
V_94 . V_117 = V_105 ;
if ( V_94 . V_114 == V_116 )
F_51 ( & V_94 , & V_95 -> V_95 [ 0 ] , V_95 -> V_111 ) ;
else
memcpy ( V_94 . V_95 , & V_95 -> V_95 [ 0 ] , V_95 -> V_111 ) ;
if ( V_103 == V_119 )
V_95 -> V_120 = 0 ;
if ( V_95 -> V_15 & V_110 )
F_53 = V_2 -> V_39 -> V_80 -> V_121 ;
else
F_53 = V_2 -> V_39 -> V_80 -> V_122 ;
if ( ! F_53 )
return - V_109 ;
return F_53 ( V_2 , & V_94 , V_95 ) ;
}
int F_59 ( struct V_28 * V_19 , struct V_44 * V_26 ,
struct V_88 * V_42 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
return V_2 -> V_39 -> V_80 -> V_123 ( V_2 , V_26 , V_42 ) ;
}
int F_60 ( struct V_28 * V_19 , struct V_44 * V_26 ,
struct V_88 * V_42 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
return V_2 -> V_39 -> V_80 -> V_124 ( V_2 , V_42 ) ;
}
void F_61 ( struct V_28 * V_19 ,
struct V_44 * V_26 ,
const T_3 * V_125 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
F_47 ( V_126 , & V_2 -> V_15 ) ;
F_62 ( V_2 ) ;
}
void F_63 ( struct V_28 * V_19 ,
struct V_44 * V_26 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
F_35 ( V_126 , & V_2 -> V_15 ) ;
F_64 ( V_2 ) ;
}
int F_65 ( struct V_28 * V_19 ,
struct V_127 * V_128 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
memcpy ( V_128 , & V_2 -> V_129 , sizeof( * V_128 ) ) ;
return 0 ;
}
void F_66 ( struct V_28 * V_19 ,
struct V_44 * V_26 ,
struct V_130 * V_131 ,
T_1 V_132 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_45 * V_46 = F_30 ( V_26 ) ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
return;
if ( V_132 & V_133 )
F_33 ( V_2 , V_46 , V_26 -> type , NULL ,
V_131 -> V_134 ) ;
if ( V_132 & V_135 ) {
F_38 ( & V_46 -> V_60 ) ;
if ( ! V_131 -> V_136 && V_46 -> V_136 ) {
V_2 -> V_137 -- ;
V_46 -> V_136 = false ;
if ( V_2 -> V_137 == 0 ) {
F_37 ( V_2 -> V_47 ) ;
}
F_67 ( V_2 , V_26 ) ;
} else if ( V_131 -> V_136 && ! V_46 -> V_136 ) {
V_2 -> V_137 ++ ;
V_46 -> V_136 = true ;
if ( F_57 ( V_2 ) )
F_68 ( V_2 , V_26 ) ;
if ( V_2 -> V_137 == 1 ) {
F_42 ( V_2 -> V_47 ) ;
}
}
F_41 ( & V_46 -> V_60 ) ;
}
if ( V_132 & V_138 ) {
V_2 -> V_139 . V_140 = 0 ;
if ( V_131 -> V_141 )
V_2 -> V_142 ++ ;
else
V_2 -> V_142 -- ;
F_69 ( V_2 , ! ! V_2 -> V_142 ) ;
F_35 ( V_143 , & V_2 -> V_15 ) ;
}
if ( V_132 & V_144 && ! V_131 -> V_145 )
F_47 ( V_143 , & V_2 -> V_15 ) ;
if ( V_132 & ( V_146 | V_147 |
V_148 | V_149 |
V_150 | V_151 ) )
F_70 ( V_2 , V_46 , V_131 , V_132 ) ;
}
int F_71 ( struct V_28 * V_19 ,
struct V_44 * V_26 , T_4 V_152 ,
const struct V_153 * V_154 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_3 * V_4 ;
V_4 = F_17 ( V_2 , V_152 ) ;
if ( F_4 ( ! V_4 ) )
return - V_155 ;
if ( V_154 -> V_156 > 0 )
V_4 -> V_156 = F_72 ( V_154 -> V_156 ) ;
else
V_4 -> V_156 = 5 ;
if ( V_154 -> V_157 > 0 )
V_4 -> V_157 = F_72 ( V_154 -> V_157 ) ;
else
V_4 -> V_157 = 10 ;
V_4 -> V_158 = V_154 -> V_158 ;
V_4 -> V_159 = V_154 -> V_159 ;
F_73 ( V_2 ,
L_5 ,
V_152 , V_4 -> V_156 , V_4 -> V_157 , V_4 -> V_158 ,
V_4 -> V_159 ) ;
return 0 ;
}
void F_74 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
bool V_160 = ! ! V_2 -> V_39 -> V_80 -> V_161 ( V_2 ) ;
F_75 ( V_19 -> V_162 , ! V_160 ) ;
}
void F_76 ( struct V_28 * V_19 , struct V_44 * V_26 ,
T_1 V_163 , bool V_164 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_3 * V_4 ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
return;
F_77 (rt2x00dev, queue)
if ( ! F_78 ( V_4 ) )
F_79 ( V_4 , V_164 ) ;
}
int F_80 ( struct V_28 * V_19 , T_1 V_165 , T_1 V_166 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_167 * V_168 = & V_2 -> V_139 . V_168 ;
struct V_169 * V_170 = & V_2 -> V_70 ;
struct V_169 V_171 ;
if ( ! V_165 || ( V_165 & ~ 3 ) || ! V_166 || ( V_166 & ~ 3 ) )
return - V_155 ;
if ( V_168 -> V_15 & V_172 && V_165 != 3 )
V_168 -> V_15 &= ~ V_172 ;
if ( V_168 -> V_15 & V_173 && V_166 != 3 )
V_168 -> V_15 &= ~ V_173 ;
if ( V_165 == 3 && V_170 -> V_174 == V_175 ) {
V_165 = V_175 ;
V_168 -> V_15 |= V_172 ;
}
if ( V_166 == 3 && V_170 -> V_68 == V_175 ) {
V_166 = V_175 ;
V_168 -> V_15 |= V_173 ;
}
V_171 . V_174 = V_165 ;
V_171 . V_68 = V_166 ;
V_171 . V_176 = 0 ;
V_171 . V_177 = 0 ;
F_40 ( V_2 , V_171 ) ;
return 0 ;
}
int F_81 ( struct V_28 * V_19 , T_1 * V_165 , T_1 * V_166 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_167 * V_168 = & V_2 -> V_139 . V_168 ;
struct V_169 * V_160 = & V_2 -> V_139 . V_168 . V_160 ;
if ( V_168 -> V_15 & V_172 )
* V_165 = V_178 ;
else
* V_165 = V_160 -> V_174 ;
if ( V_168 -> V_15 & V_173 )
* V_166 = V_178 ;
else
* V_166 = V_160 -> V_68 ;
return 0 ;
}
void F_82 ( struct V_28 * V_19 ,
T_1 * V_174 , T_1 * V_179 , T_1 * V_68 , T_1 * V_180 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_3 * V_4 ;
F_77 (rt2x00dev, queue) {
* V_174 += V_4 -> V_181 ;
* V_179 += V_4 -> V_53 ;
}
* V_68 = V_2 -> V_68 -> V_181 ;
* V_180 = V_2 -> V_68 -> V_53 ;
}
bool F_83 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_3 * V_4 ;
F_77 (rt2x00dev, queue) {
if ( ! F_78 ( V_4 ) )
return true ;
}
return false ;
}

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
V_12 = F_11 ( V_4 , V_10 , true ) ;
if ( V_12 ) {
F_12 ( V_10 ) ;
F_5 ( V_2 , L_2 ) ;
}
return V_12 ;
}
void F_13 ( struct V_28 * V_19 , struct V_5 * V_10 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_7 * V_8 = F_2 ( V_10 ) ;
enum V_30 V_31 = F_14 ( V_10 ) ;
struct V_3 * V_4 = NULL ;
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) )
goto V_33;
if ( V_8 -> V_15 & V_34 &&
F_15 ( V_35 , & V_2 -> V_36 ) )
V_31 = V_37 ;
V_4 = F_16 ( V_2 , V_31 ) ;
if ( F_4 ( ! V_4 ) ) {
ERROR ( V_2 ,
L_3
L_4 , V_31 , V_38 ) ;
goto V_33;
}
if ( ! V_2 -> V_39 -> V_19 -> V_40 &&
( V_8 -> V_13 . V_14 [ 0 ] . V_15 & ( V_23 |
V_16 ) ) ) {
if ( F_17 ( V_4 ) <= 1 )
goto V_41;
if ( F_1 ( V_2 , V_4 , V_10 ) )
goto V_41;
}
if ( F_4 ( F_11 ( V_4 , V_10 , false ) ) )
goto V_41;
if ( F_18 ( V_4 ) )
F_19 ( V_4 ) ;
return;
V_41:
F_19 ( V_4 ) ;
V_33:
F_12 ( V_10 ) ;
}
int F_20 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) )
return 0 ;
return F_21 ( V_2 ) ;
}
void F_22 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) )
return;
F_23 ( V_2 ) ;
}
int F_24 ( struct V_28 * V_19 ,
struct V_42 * V_26 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_43 * V_44 = F_25 ( V_26 ) ;
struct V_3 * V_4 = V_2 -> V_45 ;
struct V_46 * V_47 = NULL ;
unsigned int V_48 ;
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) ||
! F_15 ( V_49 , & V_2 -> V_15 ) )
return - V_50 ;
switch ( V_26 -> type ) {
case V_51 :
if ( V_2 -> V_52 )
return - V_53 ;
if ( V_2 -> V_54 >= V_2 -> V_39 -> V_55 )
return - V_53 ;
break;
case V_56 :
case V_57 :
case V_58 :
case V_59 :
if ( V_2 -> V_54 )
return - V_53 ;
if ( V_2 -> V_52 >= V_2 -> V_39 -> V_60 )
return - V_53 ;
break;
default:
return - V_61 ;
}
for ( V_48 = 0 ; V_48 < V_4 -> V_62 ; V_48 ++ ) {
V_47 = & V_4 -> V_63 [ V_48 ] ;
if ( ! F_26 ( V_64 , & V_47 -> V_15 ) )
break;
}
if ( F_4 ( V_48 == V_4 -> V_62 ) )
return - V_53 ;
if ( V_26 -> type == V_51 )
V_2 -> V_54 ++ ;
else
V_2 -> V_52 ++ ;
F_27 ( & V_44 -> V_65 ) ;
F_28 ( & V_44 -> V_66 ) ;
V_44 -> V_67 = V_47 ;
F_29 ( V_2 , V_44 , V_26 -> type ,
V_26 -> V_68 , NULL ) ;
V_2 -> V_69 = 0 ;
return 0 ;
}
void F_30 ( struct V_28 * V_19 ,
struct V_42 * V_26 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_43 * V_44 = F_25 ( V_26 ) ;
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) ||
( V_26 -> type == V_51 && ! V_2 -> V_54 ) ||
( V_26 -> type != V_51 && ! V_2 -> V_52 ) )
return;
if ( V_26 -> type == V_51 )
V_2 -> V_54 -- ;
else
V_2 -> V_52 -- ;
F_31 ( V_64 , & V_44 -> V_67 -> V_15 ) ;
F_29 ( V_2 , V_44 ,
V_70 , NULL , NULL ) ;
}
int F_32 ( struct V_28 * V_19 , T_1 V_71 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_72 * V_73 = & V_19 -> V_73 ;
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) )
return 0 ;
F_33 ( V_2 -> V_74 ) ;
F_34 ( V_2 , V_73 , V_71 ) ;
F_35 ( V_2 , V_2 -> V_75 ) ;
F_36 ( V_2 -> V_74 ) ;
return 0 ;
}
void F_37 ( struct V_28 * V_19 ,
unsigned int V_76 ,
unsigned int * V_77 ,
T_2 V_78 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
* V_77 &=
V_79 |
V_80 |
V_81 |
V_82 |
V_83 |
V_84 |
V_85 ;
* V_77 |= V_79 ;
if ( * V_77 & V_84 ||
* V_77 & V_85 )
* V_77 |= V_85 | V_84 ;
if ( ! F_15 ( V_86 , & V_2 -> V_36 ) ) {
if ( * V_77 & V_82 || * V_77 & V_83 )
* V_77 |= V_82 | V_83 ;
}
if ( ! F_15 ( V_87 , & V_2 -> V_36 ) ) {
if ( * V_77 & V_82 )
* V_77 |= V_83 ;
}
if ( V_2 -> V_69 == * V_77 )
return;
V_2 -> V_69 = * V_77 ;
V_2 -> V_39 -> V_88 -> V_89 ( V_2 , * V_77 ) ;
}
static void F_38 ( void * V_27 , T_3 * V_90 ,
struct V_42 * V_26 )
{
struct V_43 * V_44 = F_25 ( V_26 ) ;
if ( V_26 -> type != V_51 &&
V_26 -> type != V_57 &&
V_26 -> type != V_58 &&
V_26 -> type != V_59 )
return;
F_39 ( V_91 , & V_44 -> V_92 ) ;
}
int F_40 ( struct V_28 * V_19 , struct V_93 * V_94 ,
bool V_95 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
if ( ! F_15 ( V_96 , & V_2 -> V_15 ) )
return 0 ;
F_41 ( V_2 -> V_19 ,
F_38 ,
V_2 ) ;
F_42 ( V_2 -> V_19 , & V_2 -> V_97 ) ;
return 0 ;
}
static void F_43 ( struct V_98 * V_99 , T_3 * V_100 , T_3 V_101 )
{
if ( V_101 > V_102 )
memcpy ( V_99 -> V_100 ,
& V_100 [ V_102 ] ,
sizeof( V_99 -> V_100 ) ) ;
if ( V_101 > V_103 )
memcpy ( V_99 -> V_104 ,
& V_100 [ V_103 ] ,
sizeof( V_99 -> V_104 ) ) ;
if ( V_101 > V_105 )
memcpy ( V_99 -> V_106 ,
& V_100 [ V_105 ] ,
sizeof( V_99 -> V_106 ) ) ;
}
int F_44 ( struct V_28 * V_19 , enum V_107 V_108 ,
struct V_42 * V_26 , struct V_93 * V_94 ,
struct V_109 * V_100 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
int (* F_45) ( struct V_1 * V_2 ,
struct V_98 * V_99 ,
struct V_109 * V_100 );
struct V_98 V_99 ;
static const T_3 V_110 [ V_111 ] =
{ 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , } ;
struct V_112 * V_113 = NULL ;
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) )
return 0 ;
else if ( ! F_15 ( V_114 , & V_2 -> V_36 ) )
return - V_115 ;
else if ( V_100 -> V_116 > 32 )
return - V_117 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_118 = F_46 ( V_2 , V_26 ) ;
V_99 . V_119 = F_47 ( V_100 ) ;
if ( V_99 . V_119 == V_120 )
return - V_115 ;
V_99 . V_108 = V_108 ;
if ( V_94 ) {
V_99 . V_121 = V_94 -> V_68 ;
V_113 = F_48 ( V_94 ) ;
V_99 . V_122 = V_113 -> V_122 ;
} else
V_99 . V_121 = V_110 ;
if ( V_99 . V_119 == V_123 )
F_43 ( & V_99 , & V_100 -> V_100 [ 0 ] , V_100 -> V_116 ) ;
else
memcpy ( V_99 . V_100 , & V_100 -> V_100 [ 0 ] , V_100 -> V_116 ) ;
if ( V_108 == V_124 )
V_100 -> V_125 = 0 ;
if ( V_100 -> V_15 & V_126 )
F_45 = V_2 -> V_39 -> V_88 -> V_127 ;
else
F_45 = V_2 -> V_39 -> V_88 -> V_128 ;
if ( ! F_45 )
return - V_115 ;
return F_45 ( V_2 , & V_99 , V_100 ) ;
}
int F_49 ( struct V_28 * V_19 , struct V_42 * V_26 ,
struct V_93 * V_94 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_112 * V_113 = F_48 ( V_94 ) ;
if ( V_2 -> V_39 -> V_88 -> V_129 ( V_2 , V_26 , V_94 ) )
V_113 -> V_122 = - 1 ;
return 0 ;
}
int F_50 ( struct V_28 * V_19 , struct V_42 * V_26 ,
struct V_93 * V_94 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_112 * V_113 = F_48 ( V_94 ) ;
if ( V_113 -> V_122 < 0 )
return 0 ;
return V_2 -> V_39 -> V_88 -> V_130 ( V_2 , V_113 -> V_122 ) ;
}
void F_51 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
F_39 ( V_131 , & V_2 -> V_15 ) ;
F_52 ( V_2 ) ;
}
void F_53 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
F_31 ( V_131 , & V_2 -> V_15 ) ;
F_54 ( V_2 ) ;
}
int F_55 ( struct V_28 * V_19 ,
struct V_132 * V_133 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
memcpy ( V_133 , & V_2 -> V_134 , sizeof( * V_133 ) ) ;
return 0 ;
}
void F_56 ( struct V_28 * V_19 ,
struct V_42 * V_26 ,
struct V_135 * V_136 ,
T_1 V_137 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_43 * V_44 = F_25 ( V_26 ) ;
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) )
return;
if ( V_137 & V_138 )
F_29 ( V_2 , V_44 , V_26 -> type , NULL ,
V_136 -> V_139 ) ;
if ( V_137 & V_140 && F_57 ( V_2 ) )
F_58 ( V_2 , V_26 ) ;
if ( V_137 & V_141 ) {
if ( ! V_136 -> V_142 && V_44 -> V_142 ) {
F_59 ( V_2 , V_26 ) ;
V_2 -> V_143 -- ;
V_44 -> V_142 = false ;
if ( V_2 -> V_143 == 0 ) {
F_60 ( & V_44 -> V_66 ) ;
F_33 ( V_2 -> V_45 ) ;
F_61 ( & V_44 -> V_66 ) ;
}
} else if ( V_136 -> V_142 && ! V_44 -> V_142 ) {
V_2 -> V_143 ++ ;
V_44 -> V_142 = true ;
if ( V_2 -> V_143 == 1 ) {
F_60 ( & V_44 -> V_66 ) ;
F_36 ( V_2 -> V_45 ) ;
F_61 ( & V_44 -> V_66 ) ;
}
}
}
if ( V_137 & V_144 ) {
V_2 -> V_145 . V_146 = 0 ;
if ( V_136 -> V_147 )
V_2 -> V_148 ++ ;
else
V_2 -> V_148 -- ;
F_62 ( V_2 , ! ! V_2 -> V_148 ) ;
}
if ( V_137 & ( V_149 | V_150 |
V_151 | V_152 |
V_153 | V_154 ) )
F_63 ( V_2 , V_44 , V_136 , V_137 ) ;
}
int F_64 ( struct V_28 * V_19 ,
struct V_42 * V_26 , T_4 V_155 ,
const struct V_156 * V_157 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_3 * V_4 ;
V_4 = F_16 ( V_2 , V_155 ) ;
if ( F_4 ( ! V_4 ) )
return - V_61 ;
if ( V_157 -> V_158 > 0 )
V_4 -> V_158 = F_65 ( V_157 -> V_158 ) ;
else
V_4 -> V_158 = 5 ;
if ( V_157 -> V_159 > 0 )
V_4 -> V_159 = F_65 ( V_157 -> V_159 ) ;
else
V_4 -> V_159 = 10 ;
V_4 -> V_160 = V_157 -> V_160 ;
V_4 -> V_161 = V_157 -> V_161 ;
F_66 ( V_2 ,
L_5 ,
V_155 , V_4 -> V_158 , V_4 -> V_159 , V_4 -> V_160 , V_4 -> V_161 ) ;
return 0 ;
}
void F_67 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
bool V_162 = ! ! V_2 -> V_39 -> V_88 -> V_163 ( V_2 ) ;
F_68 ( V_19 -> V_164 , ! V_162 ) ;
}
void F_69 ( struct V_28 * V_19 , bool V_165 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_3 * V_4 ;
F_70 (rt2x00dev, queue)
F_71 ( V_4 , V_165 ) ;
}
int F_72 ( struct V_28 * V_19 , T_1 V_166 , T_1 V_167 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_168 * V_169 = & V_2 -> V_145 . V_169 ;
struct V_170 * V_171 = & V_2 -> V_75 ;
struct V_170 V_172 ;
if ( ! V_166 || ( V_166 & ~ 3 ) || ! V_167 || ( V_167 & ~ 3 ) )
return - V_61 ;
if ( V_169 -> V_15 & V_173 && V_166 != 3 )
V_169 -> V_15 &= ~ V_173 ;
if ( V_169 -> V_15 & V_174 && V_167 != 3 )
V_169 -> V_15 &= ~ V_174 ;
if ( V_166 == 3 && V_171 -> V_175 == V_176 ) {
V_166 = V_176 ;
V_169 -> V_15 |= V_173 ;
}
if ( V_167 == 3 && V_171 -> V_74 == V_176 ) {
V_167 = V_176 ;
V_169 -> V_15 |= V_174 ;
}
V_172 . V_175 = V_166 ;
V_172 . V_74 = V_167 ;
F_35 ( V_2 , V_172 ) ;
return 0 ;
}
int F_73 ( struct V_28 * V_19 , T_1 * V_166 , T_1 * V_167 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_168 * V_169 = & V_2 -> V_145 . V_169 ;
struct V_170 * V_162 = & V_2 -> V_145 . V_169 . V_162 ;
if ( V_169 -> V_15 & V_173 )
* V_166 = V_177 ;
else
* V_166 = V_162 -> V_175 ;
if ( V_169 -> V_15 & V_174 )
* V_167 = V_177 ;
else
* V_167 = V_162 -> V_74 ;
return 0 ;
}
void F_74 ( struct V_28 * V_19 ,
T_1 * V_175 , T_1 * V_178 , T_1 * V_74 , T_1 * V_179 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_3 * V_4 ;
F_70 (rt2x00dev, queue) {
* V_175 += V_4 -> V_180 ;
* V_178 += V_4 -> V_62 ;
}
* V_74 = V_2 -> V_74 -> V_180 ;
* V_179 = V_2 -> V_74 -> V_62 ;
}
bool F_75 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_3 * V_4 ;
F_70 (rt2x00dev, queue) {
if ( ! F_76 ( V_4 ) )
return true ;
}
return false ;
}

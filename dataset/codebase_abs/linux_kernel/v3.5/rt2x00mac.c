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
F_18 ( & V_4 -> V_42 ) ;
if ( F_19 ( V_4 ) )
F_20 ( V_4 ) ;
F_21 ( & V_4 -> V_42 ) ;
return;
V_41:
F_18 ( & V_4 -> V_42 ) ;
F_20 ( V_4 ) ;
F_21 ( & V_4 -> V_42 ) ;
V_33:
F_22 ( V_19 , V_10 ) ;
}
int F_23 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) )
return 0 ;
return F_24 ( V_2 ) ;
}
void F_25 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) )
return;
F_26 ( V_2 ) ;
}
int F_27 ( struct V_28 * V_19 ,
struct V_43 * V_26 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_44 * V_45 = F_28 ( V_26 ) ;
struct V_3 * V_4 = V_2 -> V_46 ;
struct V_47 * V_48 = NULL ;
unsigned int V_49 ;
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) ||
! F_15 ( V_50 , & V_2 -> V_15 ) )
return - V_51 ;
switch ( V_26 -> type ) {
case V_52 :
if ( V_2 -> V_53 )
return - V_54 ;
if ( V_2 -> V_55 >= V_2 -> V_39 -> V_56 )
return - V_54 ;
break;
case V_57 :
case V_58 :
case V_59 :
case V_60 :
if ( V_2 -> V_55 )
return - V_54 ;
if ( V_2 -> V_53 >= V_2 -> V_39 -> V_61 )
return - V_54 ;
break;
default:
return - V_62 ;
}
for ( V_49 = 0 ; V_49 < V_4 -> V_63 ; V_49 ++ ) {
V_48 = & V_4 -> V_64 [ V_49 ] ;
if ( ! F_29 ( V_65 , & V_48 -> V_15 ) )
break;
}
if ( F_4 ( V_49 == V_4 -> V_63 ) )
return - V_54 ;
if ( V_26 -> type == V_52 )
V_2 -> V_55 ++ ;
else
V_2 -> V_53 ++ ;
F_30 ( & V_45 -> V_66 ) ;
V_45 -> V_67 = V_48 ;
F_31 ( V_2 , V_45 , V_26 -> type ,
V_26 -> V_68 , NULL ) ;
V_2 -> V_69 = 0 ;
return 0 ;
}
void F_32 ( struct V_28 * V_19 ,
struct V_43 * V_26 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_44 * V_45 = F_28 ( V_26 ) ;
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) ||
( V_26 -> type == V_52 && ! V_2 -> V_55 ) ||
( V_26 -> type != V_52 && ! V_2 -> V_53 ) )
return;
if ( V_26 -> type == V_52 )
V_2 -> V_55 -- ;
else
V_2 -> V_53 -- ;
F_33 ( V_65 , & V_45 -> V_67 -> V_15 ) ;
F_31 ( V_2 , V_45 ,
V_70 , NULL , NULL ) ;
}
int F_34 ( struct V_28 * V_19 , T_1 V_71 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_72 * V_73 = & V_19 -> V_73 ;
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) )
return 0 ;
F_35 ( V_2 -> V_74 ) ;
F_36 ( V_2 , V_73 , V_71 ) ;
F_37 ( V_2 , V_2 -> V_75 ) ;
F_38 ( V_2 -> V_74 ) ;
return 0 ;
}
void F_39 ( struct V_28 * V_19 ,
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
static void F_40 ( void * V_27 , T_3 * V_90 ,
struct V_43 * V_26 )
{
struct V_44 * V_45 = F_28 ( V_26 ) ;
if ( V_26 -> type != V_52 &&
V_26 -> type != V_58 &&
V_26 -> type != V_59 &&
V_26 -> type != V_60 )
return;
F_41 ( V_91 , & V_45 -> V_92 ) ;
}
int F_42 ( struct V_28 * V_19 , struct V_93 * V_94 ,
bool V_95 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
if ( ! F_15 ( V_96 , & V_2 -> V_15 ) )
return 0 ;
F_43 ( V_2 -> V_19 ,
F_40 ,
V_2 ) ;
F_44 ( V_2 -> V_19 , & V_2 -> V_97 ) ;
return 0 ;
}
static void F_45 ( struct V_98 * V_99 , T_3 * V_100 , T_3 V_101 )
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
int F_46 ( struct V_28 * V_19 , enum V_107 V_108 ,
struct V_43 * V_26 , struct V_93 * V_94 ,
struct V_109 * V_100 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
int (* F_47) ( struct V_1 * V_2 ,
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
V_99 . V_118 = F_48 ( V_2 , V_26 ) ;
V_99 . V_119 = F_49 ( V_100 ) ;
if ( V_99 . V_119 == V_120 )
return - V_115 ;
V_99 . V_108 = V_108 ;
if ( V_94 ) {
V_99 . V_121 = V_94 -> V_68 ;
V_113 = F_50 ( V_94 ) ;
V_99 . V_122 = V_113 -> V_122 ;
} else
V_99 . V_121 = V_110 ;
if ( V_99 . V_119 == V_123 )
F_45 ( & V_99 , & V_100 -> V_100 [ 0 ] , V_100 -> V_116 ) ;
else
memcpy ( V_99 . V_100 , & V_100 -> V_100 [ 0 ] , V_100 -> V_116 ) ;
if ( V_108 == V_124 )
V_100 -> V_125 = 0 ;
if ( V_100 -> V_15 & V_126 )
F_47 = V_2 -> V_39 -> V_88 -> V_127 ;
else
F_47 = V_2 -> V_39 -> V_88 -> V_128 ;
if ( ! F_47 )
return - V_115 ;
return F_47 ( V_2 , & V_99 , V_100 ) ;
}
int F_51 ( struct V_28 * V_19 , struct V_43 * V_26 ,
struct V_93 * V_94 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_112 * V_113 = F_50 ( V_94 ) ;
if ( V_2 -> V_39 -> V_88 -> V_129 ( V_2 , V_26 , V_94 ) )
V_113 -> V_122 = - 1 ;
return 0 ;
}
int F_52 ( struct V_28 * V_19 , struct V_43 * V_26 ,
struct V_93 * V_94 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_112 * V_113 = F_50 ( V_94 ) ;
if ( V_113 -> V_122 < 0 )
return 0 ;
return V_2 -> V_39 -> V_88 -> V_130 ( V_2 , V_113 -> V_122 ) ;
}
void F_53 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
F_41 ( V_131 , & V_2 -> V_15 ) ;
F_54 ( V_2 ) ;
}
void F_55 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
F_33 ( V_131 , & V_2 -> V_15 ) ;
F_56 ( V_2 ) ;
}
int F_57 ( struct V_28 * V_19 ,
struct V_132 * V_133 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
memcpy ( V_133 , & V_2 -> V_134 , sizeof( * V_133 ) ) ;
return 0 ;
}
void F_58 ( struct V_28 * V_19 ,
struct V_43 * V_26 ,
struct V_135 * V_136 ,
T_1 V_137 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_44 * V_45 = F_28 ( V_26 ) ;
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) )
return;
if ( V_137 & V_138 )
F_31 ( V_2 , V_45 , V_26 -> type , NULL ,
V_136 -> V_139 ) ;
if ( V_137 & V_140 && F_59 ( V_2 ) )
F_60 ( V_2 , V_26 ) ;
if ( V_137 & V_141 ) {
if ( ! V_136 -> V_142 && V_45 -> V_142 ) {
F_61 ( V_2 , V_26 ) ;
V_2 -> V_143 -- ;
V_45 -> V_142 = false ;
if ( V_2 -> V_143 == 0 ) {
F_62 ( & V_45 -> V_66 ) ;
F_35 ( V_2 -> V_46 ) ;
F_63 ( & V_45 -> V_66 ) ;
}
} else if ( V_136 -> V_142 && ! V_45 -> V_142 ) {
V_2 -> V_143 ++ ;
V_45 -> V_142 = true ;
if ( V_2 -> V_143 == 1 ) {
F_62 ( & V_45 -> V_66 ) ;
F_38 ( V_2 -> V_46 ) ;
F_63 ( & V_45 -> V_66 ) ;
}
}
}
if ( V_137 & V_144 ) {
V_2 -> V_145 . V_146 = 0 ;
if ( V_136 -> V_147 )
V_2 -> V_148 ++ ;
else
V_2 -> V_148 -- ;
F_64 ( V_2 , ! ! V_2 -> V_148 ) ;
F_33 ( V_149 , & V_2 -> V_15 ) ;
}
if ( V_137 & V_150 && ! V_136 -> V_151 )
F_41 ( V_149 , & V_2 -> V_15 ) ;
if ( V_137 & ( V_152 | V_153 |
V_154 | V_155 |
V_156 | V_157 ) )
F_65 ( V_2 , V_45 , V_136 , V_137 ) ;
}
int F_66 ( struct V_28 * V_19 ,
struct V_43 * V_26 , T_4 V_158 ,
const struct V_159 * V_160 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_3 * V_4 ;
V_4 = F_16 ( V_2 , V_158 ) ;
if ( F_4 ( ! V_4 ) )
return - V_62 ;
if ( V_160 -> V_161 > 0 )
V_4 -> V_161 = F_67 ( V_160 -> V_161 ) ;
else
V_4 -> V_161 = 5 ;
if ( V_160 -> V_162 > 0 )
V_4 -> V_162 = F_67 ( V_160 -> V_162 ) ;
else
V_4 -> V_162 = 10 ;
V_4 -> V_163 = V_160 -> V_163 ;
V_4 -> V_164 = V_160 -> V_164 ;
F_68 ( V_2 ,
L_5 ,
V_158 , V_4 -> V_161 , V_4 -> V_162 , V_4 -> V_163 , V_4 -> V_164 ) ;
return 0 ;
}
void F_69 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
bool V_165 = ! ! V_2 -> V_39 -> V_88 -> V_166 ( V_2 ) ;
F_70 ( V_19 -> V_167 , ! V_165 ) ;
}
void F_71 ( struct V_28 * V_19 , bool V_168 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_3 * V_4 ;
F_72 (rt2x00dev, queue)
F_73 ( V_4 , V_168 ) ;
}
int F_74 ( struct V_28 * V_19 , T_1 V_169 , T_1 V_170 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_171 * V_172 = & V_2 -> V_145 . V_172 ;
struct V_173 * V_174 = & V_2 -> V_75 ;
struct V_173 V_175 ;
if ( ! V_169 || ( V_169 & ~ 3 ) || ! V_170 || ( V_170 & ~ 3 ) )
return - V_62 ;
if ( V_172 -> V_15 & V_176 && V_169 != 3 )
V_172 -> V_15 &= ~ V_176 ;
if ( V_172 -> V_15 & V_177 && V_170 != 3 )
V_172 -> V_15 &= ~ V_177 ;
if ( V_169 == 3 && V_174 -> V_178 == V_179 ) {
V_169 = V_179 ;
V_172 -> V_15 |= V_176 ;
}
if ( V_170 == 3 && V_174 -> V_74 == V_179 ) {
V_170 = V_179 ;
V_172 -> V_15 |= V_177 ;
}
V_175 . V_178 = V_169 ;
V_175 . V_74 = V_170 ;
F_37 ( V_2 , V_175 ) ;
return 0 ;
}
int F_75 ( struct V_28 * V_19 , T_1 * V_169 , T_1 * V_170 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_171 * V_172 = & V_2 -> V_145 . V_172 ;
struct V_173 * V_165 = & V_2 -> V_145 . V_172 . V_165 ;
if ( V_172 -> V_15 & V_176 )
* V_169 = V_180 ;
else
* V_169 = V_165 -> V_178 ;
if ( V_172 -> V_15 & V_177 )
* V_170 = V_180 ;
else
* V_170 = V_165 -> V_74 ;
return 0 ;
}
void F_76 ( struct V_28 * V_19 ,
T_1 * V_178 , T_1 * V_181 , T_1 * V_74 , T_1 * V_182 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_3 * V_4 ;
F_72 (rt2x00dev, queue) {
* V_178 += V_4 -> V_183 ;
* V_181 += V_4 -> V_63 ;
}
* V_74 = V_2 -> V_74 -> V_183 ;
* V_182 = V_2 -> V_74 -> V_63 ;
}
bool F_77 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_3 * V_4 ;
F_72 (rt2x00dev, queue) {
if ( ! F_78 ( V_4 ) )
return true ;
}
return false ;
}

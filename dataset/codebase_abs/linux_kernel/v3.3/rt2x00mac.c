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
F_31 ( & V_45 -> V_67 ) ;
V_45 -> V_68 = V_48 ;
F_32 ( V_2 , V_45 , V_26 -> type ,
V_26 -> V_69 , NULL ) ;
V_2 -> V_70 = 0 ;
return 0 ;
}
void F_33 ( struct V_28 * V_19 ,
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
F_34 ( V_65 , & V_45 -> V_68 -> V_15 ) ;
F_32 ( V_2 , V_45 ,
V_71 , NULL , NULL ) ;
}
int F_35 ( struct V_28 * V_19 , T_1 V_72 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_73 * V_74 = & V_19 -> V_74 ;
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) )
return 0 ;
F_36 ( V_2 -> V_75 ) ;
F_37 ( V_2 , V_74 , V_72 ) ;
F_38 ( V_2 , V_2 -> V_76 ) ;
F_39 ( V_2 -> V_75 ) ;
return 0 ;
}
void F_40 ( struct V_28 * V_19 ,
unsigned int V_77 ,
unsigned int * V_78 ,
T_2 V_79 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
* V_78 &=
V_80 |
V_81 |
V_82 |
V_83 |
V_84 |
V_85 |
V_86 ;
* V_78 |= V_80 ;
if ( * V_78 & V_85 ||
* V_78 & V_86 )
* V_78 |= V_86 | V_85 ;
if ( ! F_15 ( V_87 , & V_2 -> V_36 ) ) {
if ( * V_78 & V_83 || * V_78 & V_84 )
* V_78 |= V_83 | V_84 ;
}
if ( ! F_15 ( V_88 , & V_2 -> V_36 ) ) {
if ( * V_78 & V_83 )
* V_78 |= V_84 ;
}
if ( V_2 -> V_70 == * V_78 )
return;
V_2 -> V_70 = * V_78 ;
V_2 -> V_39 -> V_89 -> V_90 ( V_2 , * V_78 ) ;
}
static void F_41 ( void * V_27 , T_3 * V_91 ,
struct V_43 * V_26 )
{
struct V_44 * V_45 = F_28 ( V_26 ) ;
if ( V_26 -> type != V_52 &&
V_26 -> type != V_58 &&
V_26 -> type != V_59 &&
V_26 -> type != V_60 )
return;
F_42 ( V_92 , & V_45 -> V_93 ) ;
}
int F_43 ( struct V_28 * V_19 , struct V_94 * V_95 ,
bool V_96 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
if ( ! F_15 ( V_97 , & V_2 -> V_15 ) )
return 0 ;
F_44 ( V_2 -> V_19 ,
F_41 ,
V_2 ) ;
F_45 ( V_2 -> V_19 , & V_2 -> V_98 ) ;
return 0 ;
}
static void F_46 ( struct V_99 * V_100 , T_3 * V_101 , T_3 V_102 )
{
if ( V_102 > V_103 )
memcpy ( V_100 -> V_101 ,
& V_101 [ V_103 ] ,
sizeof( V_100 -> V_101 ) ) ;
if ( V_102 > V_104 )
memcpy ( V_100 -> V_105 ,
& V_101 [ V_104 ] ,
sizeof( V_100 -> V_105 ) ) ;
if ( V_102 > V_106 )
memcpy ( V_100 -> V_107 ,
& V_101 [ V_106 ] ,
sizeof( V_100 -> V_107 ) ) ;
}
int F_47 ( struct V_28 * V_19 , enum V_108 V_109 ,
struct V_43 * V_26 , struct V_94 * V_95 ,
struct V_110 * V_101 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
int (* F_48) ( struct V_1 * V_2 ,
struct V_99 * V_100 ,
struct V_110 * V_101 );
struct V_99 V_100 ;
static const T_3 V_111 [ V_112 ] =
{ 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , } ;
struct V_113 * V_114 = NULL ;
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) )
return 0 ;
else if ( ! F_15 ( V_115 , & V_2 -> V_36 ) )
return - V_116 ;
else if ( V_101 -> V_117 > 32 )
return - V_118 ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_119 = F_49 ( V_2 , V_26 ) ;
V_100 . V_120 = F_50 ( V_101 ) ;
if ( V_100 . V_120 == V_121 )
return - V_116 ;
V_100 . V_109 = V_109 ;
if ( V_95 ) {
V_100 . V_122 = V_95 -> V_69 ;
V_114 = F_51 ( V_95 ) ;
V_100 . V_123 = V_114 -> V_123 ;
} else
V_100 . V_122 = V_111 ;
if ( V_100 . V_120 == V_124 )
F_46 ( & V_100 , & V_101 -> V_101 [ 0 ] , V_101 -> V_117 ) ;
else
memcpy ( V_100 . V_101 , & V_101 -> V_101 [ 0 ] , V_101 -> V_117 ) ;
if ( V_109 == V_125 )
V_101 -> V_126 = 0 ;
if ( V_101 -> V_15 & V_127 )
F_48 = V_2 -> V_39 -> V_89 -> V_128 ;
else
F_48 = V_2 -> V_39 -> V_89 -> V_129 ;
if ( ! F_48 )
return - V_116 ;
return F_48 ( V_2 , & V_100 , V_101 ) ;
}
int F_52 ( struct V_28 * V_19 , struct V_43 * V_26 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_113 * V_114 = F_51 ( V_95 ) ;
if ( V_2 -> V_39 -> V_89 -> V_130 ( V_2 , V_26 , V_95 ) )
V_114 -> V_123 = - 1 ;
return 0 ;
}
int F_53 ( struct V_28 * V_19 , struct V_43 * V_26 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_113 * V_114 = F_51 ( V_95 ) ;
if ( V_114 -> V_123 < 0 )
return 0 ;
return V_2 -> V_39 -> V_89 -> V_131 ( V_2 , V_114 -> V_123 ) ;
}
void F_54 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
F_42 ( V_132 , & V_2 -> V_15 ) ;
F_55 ( V_2 ) ;
}
void F_56 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
F_34 ( V_132 , & V_2 -> V_15 ) ;
F_57 ( V_2 ) ;
}
int F_58 ( struct V_28 * V_19 ,
struct V_133 * V_134 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
memcpy ( V_134 , & V_2 -> V_135 , sizeof( * V_134 ) ) ;
return 0 ;
}
void F_59 ( struct V_28 * V_19 ,
struct V_43 * V_26 ,
struct V_136 * V_137 ,
T_1 V_138 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_44 * V_45 = F_28 ( V_26 ) ;
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) )
return;
if ( V_138 & V_139 )
F_32 ( V_2 , V_45 , V_26 -> type , NULL ,
V_137 -> V_140 ) ;
if ( V_138 & V_141 && F_60 ( V_2 ) )
F_61 ( V_2 , V_26 ) ;
if ( V_138 & V_142 ) {
if ( ! V_137 -> V_143 && V_45 -> V_143 ) {
F_62 ( V_2 , V_26 ) ;
V_2 -> V_144 -- ;
V_45 -> V_143 = false ;
if ( V_2 -> V_144 == 0 ) {
F_63 ( & V_45 -> V_67 ) ;
F_36 ( V_2 -> V_46 ) ;
F_64 ( & V_45 -> V_67 ) ;
}
} else if ( V_137 -> V_143 && ! V_45 -> V_143 ) {
V_2 -> V_144 ++ ;
V_45 -> V_143 = true ;
if ( V_2 -> V_144 == 1 ) {
F_63 ( & V_45 -> V_67 ) ;
F_39 ( V_2 -> V_46 ) ;
F_64 ( & V_45 -> V_67 ) ;
}
}
}
if ( V_138 & V_145 ) {
V_2 -> V_146 . V_147 = 0 ;
if ( V_137 -> V_148 )
V_2 -> V_149 ++ ;
else
V_2 -> V_149 -- ;
F_65 ( V_2 , ! ! V_2 -> V_149 ) ;
}
if ( V_138 & ( V_150 | V_151 |
V_152 | V_153 |
V_154 | V_155 ) )
F_66 ( V_2 , V_45 , V_137 , V_138 ) ;
}
int F_67 ( struct V_28 * V_19 ,
struct V_43 * V_26 , T_4 V_156 ,
const struct V_157 * V_158 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_3 * V_4 ;
V_4 = F_16 ( V_2 , V_156 ) ;
if ( F_4 ( ! V_4 ) )
return - V_62 ;
if ( V_158 -> V_159 > 0 )
V_4 -> V_159 = F_68 ( V_158 -> V_159 ) ;
else
V_4 -> V_159 = 5 ;
if ( V_158 -> V_160 > 0 )
V_4 -> V_160 = F_68 ( V_158 -> V_160 ) ;
else
V_4 -> V_160 = 10 ;
V_4 -> V_161 = V_158 -> V_161 ;
V_4 -> V_162 = V_158 -> V_162 ;
F_69 ( V_2 ,
L_5 ,
V_156 , V_4 -> V_159 , V_4 -> V_160 , V_4 -> V_161 , V_4 -> V_162 ) ;
return 0 ;
}
void F_70 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
bool V_163 = ! ! V_2 -> V_39 -> V_89 -> V_164 ( V_2 ) ;
F_71 ( V_19 -> V_165 , ! V_163 ) ;
}
void F_72 ( struct V_28 * V_19 , bool V_166 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_3 * V_4 ;
F_73 (rt2x00dev, queue)
F_74 ( V_4 , V_166 ) ;
}
int F_75 ( struct V_28 * V_19 , T_1 V_167 , T_1 V_168 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_169 * V_170 = & V_2 -> V_146 . V_170 ;
struct V_171 * V_172 = & V_2 -> V_76 ;
struct V_171 V_173 ;
if ( ! V_167 || ( V_167 & ~ 3 ) || ! V_168 || ( V_168 & ~ 3 ) )
return - V_62 ;
if ( V_170 -> V_15 & V_174 && V_167 != 3 )
V_170 -> V_15 &= ~ V_174 ;
if ( V_170 -> V_15 & V_175 && V_168 != 3 )
V_170 -> V_15 &= ~ V_175 ;
if ( V_167 == 3 && V_172 -> V_176 == V_177 ) {
V_167 = V_177 ;
V_170 -> V_15 |= V_174 ;
}
if ( V_168 == 3 && V_172 -> V_75 == V_177 ) {
V_168 = V_177 ;
V_170 -> V_15 |= V_175 ;
}
V_173 . V_176 = V_167 ;
V_173 . V_75 = V_168 ;
F_38 ( V_2 , V_173 ) ;
return 0 ;
}
int F_76 ( struct V_28 * V_19 , T_1 * V_167 , T_1 * V_168 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_169 * V_170 = & V_2 -> V_146 . V_170 ;
struct V_171 * V_163 = & V_2 -> V_146 . V_170 . V_163 ;
if ( V_170 -> V_15 & V_174 )
* V_167 = V_178 ;
else
* V_167 = V_163 -> V_176 ;
if ( V_170 -> V_15 & V_175 )
* V_168 = V_178 ;
else
* V_168 = V_163 -> V_75 ;
return 0 ;
}
void F_77 ( struct V_28 * V_19 ,
T_1 * V_176 , T_1 * V_179 , T_1 * V_75 , T_1 * V_180 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_3 * V_4 ;
F_73 (rt2x00dev, queue) {
* V_176 += V_4 -> V_181 ;
* V_179 += V_4 -> V_63 ;
}
* V_75 = V_2 -> V_75 -> V_181 ;
* V_180 = V_2 -> V_75 -> V_63 ;
}
bool F_78 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_3 * V_4 ;
F_73 (rt2x00dev, queue) {
if ( ! F_79 ( V_4 ) )
return true ;
}
return false ;
}

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
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) )
return 0 ;
else if ( ! F_15 ( V_112 , & V_2 -> V_36 ) )
return - V_113 ;
else if ( V_100 -> V_114 > 32 )
return - V_115 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
if ( V_2 -> V_52 )
V_99 . V_116 = 0 ;
else
V_99 . V_116 = V_26 -> V_68 [ 5 ] & ( V_2 -> V_39 -> V_55 - 1 ) ;
V_99 . V_117 = F_46 ( V_100 ) ;
if ( V_99 . V_117 == V_118 )
return - V_113 ;
V_99 . V_108 = V_108 ;
if ( V_94 )
V_99 . V_119 = V_94 -> V_68 ;
else
V_99 . V_119 = V_110 ;
if ( V_99 . V_117 == V_120 )
F_43 ( & V_99 , & V_100 -> V_100 [ 0 ] , V_100 -> V_114 ) ;
else
memcpy ( V_99 . V_100 , & V_100 -> V_100 [ 0 ] , V_100 -> V_114 ) ;
if ( V_108 == V_121 )
V_100 -> V_122 = 0 ;
if ( V_100 -> V_15 & V_123 )
F_45 = V_2 -> V_39 -> V_88 -> V_124 ;
else
F_45 = V_2 -> V_39 -> V_88 -> V_125 ;
if ( ! F_45 )
return - V_113 ;
return F_45 ( V_2 , & V_99 , V_100 ) ;
}
void F_47 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
F_39 ( V_126 , & V_2 -> V_15 ) ;
F_48 ( V_2 ) ;
}
void F_49 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
F_31 ( V_126 , & V_2 -> V_15 ) ;
F_50 ( V_2 ) ;
}
int F_51 ( struct V_28 * V_19 ,
struct V_127 * V_128 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
memcpy ( V_128 , & V_2 -> V_129 , sizeof( * V_128 ) ) ;
return 0 ;
}
void F_52 ( struct V_28 * V_19 ,
struct V_42 * V_26 ,
struct V_130 * V_131 ,
T_1 V_132 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_43 * V_44 = F_25 ( V_26 ) ;
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) )
return;
if ( V_132 & V_133 )
F_29 ( V_2 , V_44 , V_26 -> type , NULL ,
V_131 -> V_134 ) ;
if ( V_132 & V_135 && F_53 ( V_2 ) )
F_54 ( V_2 , V_26 ) ;
if ( V_132 & V_136 ) {
if ( ! V_131 -> V_137 && V_44 -> V_137 ) {
F_55 ( V_2 , V_26 ) ;
V_2 -> V_138 -- ;
V_44 -> V_137 = false ;
if ( V_2 -> V_138 == 0 ) {
F_56 ( & V_44 -> V_66 ) ;
F_33 ( V_2 -> V_45 ) ;
F_57 ( & V_44 -> V_66 ) ;
}
} else if ( V_131 -> V_137 && ! V_44 -> V_137 ) {
V_2 -> V_138 ++ ;
V_44 -> V_137 = true ;
if ( V_2 -> V_138 == 1 ) {
F_56 ( & V_44 -> V_66 ) ;
F_36 ( V_2 -> V_45 ) ;
F_57 ( & V_44 -> V_66 ) ;
}
}
}
if ( V_132 & V_139 ) {
V_2 -> V_140 . V_141 = 0 ;
if ( V_131 -> V_142 )
V_2 -> V_143 ++ ;
else
V_2 -> V_143 -- ;
F_58 ( V_2 , ! ! V_2 -> V_143 ) ;
}
if ( V_132 & ( V_144 | V_145 |
V_146 | V_147 |
V_148 | V_149 ) )
F_59 ( V_2 , V_44 , V_131 , V_132 ) ;
}
int F_60 ( struct V_28 * V_19 , T_4 V_150 ,
const struct V_151 * V_152 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_3 * V_4 ;
V_4 = F_16 ( V_2 , V_150 ) ;
if ( F_4 ( ! V_4 ) )
return - V_61 ;
if ( V_152 -> V_153 > 0 )
V_4 -> V_153 = F_61 ( V_152 -> V_153 ) ;
else
V_4 -> V_153 = 5 ;
if ( V_152 -> V_154 > 0 )
V_4 -> V_154 = F_61 ( V_152 -> V_154 ) ;
else
V_4 -> V_154 = 10 ;
V_4 -> V_155 = V_152 -> V_155 ;
V_4 -> V_156 = V_152 -> V_156 ;
F_62 ( V_2 ,
L_5 ,
V_150 , V_4 -> V_153 , V_4 -> V_154 , V_4 -> V_155 , V_4 -> V_156 ) ;
return 0 ;
}
void F_63 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
bool V_157 = ! ! V_2 -> V_39 -> V_88 -> V_158 ( V_2 ) ;
F_64 ( V_19 -> V_159 , ! V_157 ) ;
}
void F_65 ( struct V_28 * V_19 , bool V_160 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_3 * V_4 ;
F_66 (rt2x00dev, queue)
F_67 ( V_4 , V_160 ) ;
}
int F_68 ( struct V_28 * V_19 , T_1 V_161 , T_1 V_162 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_163 * V_164 = & V_2 -> V_140 . V_164 ;
struct V_165 * V_166 = & V_2 -> V_75 ;
struct V_165 V_167 ;
if ( ! V_161 || ( V_161 & ~ 3 ) || ! V_162 || ( V_162 & ~ 3 ) )
return - V_61 ;
if ( V_164 -> V_15 & V_168 && V_161 != 3 )
V_164 -> V_15 &= ~ V_168 ;
if ( V_164 -> V_15 & V_169 && V_162 != 3 )
V_164 -> V_15 &= ~ V_169 ;
if ( V_161 == 3 && V_166 -> V_170 == V_171 ) {
V_161 = V_171 ;
V_164 -> V_15 |= V_168 ;
}
if ( V_162 == 3 && V_166 -> V_74 == V_171 ) {
V_162 = V_171 ;
V_164 -> V_15 |= V_169 ;
}
V_167 . V_170 = V_161 ;
V_167 . V_74 = V_162 ;
F_35 ( V_2 , V_167 ) ;
return 0 ;
}
int F_69 ( struct V_28 * V_19 , T_1 * V_161 , T_1 * V_162 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_163 * V_164 = & V_2 -> V_140 . V_164 ;
struct V_165 * V_157 = & V_2 -> V_140 . V_164 . V_157 ;
if ( V_164 -> V_15 & V_168 )
* V_161 = V_172 ;
else
* V_161 = V_157 -> V_170 ;
if ( V_164 -> V_15 & V_169 )
* V_162 = V_172 ;
else
* V_162 = V_157 -> V_74 ;
return 0 ;
}
void F_70 ( struct V_28 * V_19 ,
T_1 * V_170 , T_1 * V_173 , T_1 * V_74 , T_1 * V_174 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_3 * V_4 ;
F_66 (rt2x00dev, queue) {
* V_170 += V_4 -> V_175 ;
* V_173 += V_4 -> V_62 ;
}
* V_74 = V_2 -> V_74 -> V_175 ;
* V_174 = V_2 -> V_74 -> V_62 ;
}
bool F_71 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_3 * V_4 ;
F_66 (rt2x00dev, queue) {
if ( ! F_72 ( V_4 ) )
return true ;
}
return false ;
}

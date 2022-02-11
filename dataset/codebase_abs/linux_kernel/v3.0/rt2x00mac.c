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
goto V_33;
if ( F_1 ( V_2 , V_4 , V_10 ) )
goto V_33;
}
if ( F_4 ( F_11 ( V_4 , V_10 , false ) ) )
goto V_33;
if ( F_18 ( V_4 ) )
F_19 ( V_4 ) ;
return;
V_33:
F_19 ( V_4 ) ;
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
struct V_41 * V_26 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_42 * V_43 = F_25 ( V_26 ) ;
struct V_3 * V_4 = V_2 -> V_44 ;
struct V_45 * V_46 = NULL ;
unsigned int V_47 ;
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) ||
! F_15 ( V_48 , & V_2 -> V_15 ) )
return - V_49 ;
switch ( V_26 -> type ) {
case V_50 :
if ( V_2 -> V_51 )
return - V_52 ;
if ( V_2 -> V_53 >= V_2 -> V_39 -> V_54 )
return - V_52 ;
break;
case V_55 :
case V_56 :
case V_57 :
case V_58 :
if ( V_2 -> V_53 )
return - V_52 ;
if ( V_2 -> V_51 >= V_2 -> V_39 -> V_59 )
return - V_52 ;
break;
default:
return - V_60 ;
}
for ( V_47 = 0 ; V_47 < V_4 -> V_61 ; V_47 ++ ) {
V_46 = & V_4 -> V_62 [ V_47 ] ;
if ( ! F_26 ( V_63 , & V_46 -> V_15 ) )
break;
}
if ( F_4 ( V_47 == V_4 -> V_61 ) )
return - V_52 ;
if ( V_26 -> type == V_50 )
V_2 -> V_53 ++ ;
else
V_2 -> V_51 ++ ;
F_27 ( & V_43 -> V_64 ) ;
F_28 ( & V_43 -> V_65 ) ;
V_43 -> V_66 = V_46 ;
F_29 ( V_2 , V_43 , V_26 -> type ,
V_26 -> V_67 , NULL ) ;
V_2 -> V_68 = 0 ;
return 0 ;
}
void F_30 ( struct V_28 * V_19 ,
struct V_41 * V_26 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_42 * V_43 = F_25 ( V_26 ) ;
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) ||
( V_26 -> type == V_50 && ! V_2 -> V_53 ) ||
( V_26 -> type != V_50 && ! V_2 -> V_51 ) )
return;
if ( V_26 -> type == V_50 )
V_2 -> V_53 -- ;
else
V_2 -> V_51 -- ;
F_31 ( V_63 , & V_43 -> V_66 -> V_15 ) ;
F_29 ( V_2 , V_43 ,
V_69 , NULL , NULL ) ;
}
int F_32 ( struct V_28 * V_19 , T_1 V_70 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_71 * V_72 = & V_19 -> V_72 ;
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) )
return 0 ;
F_33 ( V_2 -> V_73 ) ;
F_34 ( V_2 , V_72 , V_70 ) ;
F_35 ( V_2 , V_2 -> V_74 ) ;
F_36 ( V_2 -> V_73 ) ;
return 0 ;
}
void F_37 ( struct V_28 * V_19 ,
unsigned int V_75 ,
unsigned int * V_76 ,
T_2 V_77 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
* V_76 &=
V_78 |
V_79 |
V_80 |
V_81 |
V_82 |
V_83 |
V_84 ;
* V_76 |= V_78 ;
if ( * V_76 & V_83 ||
* V_76 & V_84 )
* V_76 |= V_84 | V_83 ;
if ( ! F_15 ( V_85 , & V_2 -> V_36 ) ) {
if ( * V_76 & V_81 || * V_76 & V_82 )
* V_76 |= V_81 | V_82 ;
}
if ( ! F_15 ( V_86 , & V_2 -> V_36 ) ) {
if ( * V_76 & V_81 )
* V_76 |= V_82 ;
}
if ( V_2 -> V_68 == * V_76 )
return;
V_2 -> V_68 = * V_76 ;
V_2 -> V_39 -> V_87 -> V_88 ( V_2 , * V_76 ) ;
}
static void F_38 ( void * V_27 , T_3 * V_89 ,
struct V_41 * V_26 )
{
struct V_42 * V_43 = F_25 ( V_26 ) ;
if ( V_26 -> type != V_50 &&
V_26 -> type != V_56 &&
V_26 -> type != V_57 &&
V_26 -> type != V_58 )
return;
F_39 ( V_90 , & V_43 -> V_91 ) ;
}
int F_40 ( struct V_28 * V_19 , struct V_92 * V_93 ,
bool V_94 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
if ( ! F_15 ( V_95 , & V_2 -> V_15 ) )
return 0 ;
F_41 ( V_2 -> V_19 ,
F_38 ,
V_2 ) ;
F_42 ( V_2 -> V_19 , & V_2 -> V_96 ) ;
return 0 ;
}
static void F_43 ( struct V_97 * V_98 , T_3 * V_99 , T_3 V_100 )
{
if ( V_100 > V_101 )
memcpy ( V_98 -> V_99 ,
& V_99 [ V_101 ] ,
sizeof( V_98 -> V_99 ) ) ;
if ( V_100 > V_102 )
memcpy ( V_98 -> V_103 ,
& V_99 [ V_102 ] ,
sizeof( V_98 -> V_103 ) ) ;
if ( V_100 > V_104 )
memcpy ( V_98 -> V_105 ,
& V_99 [ V_104 ] ,
sizeof( V_98 -> V_105 ) ) ;
}
int F_44 ( struct V_28 * V_19 , enum V_106 V_107 ,
struct V_41 * V_26 , struct V_92 * V_93 ,
struct V_108 * V_99 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
int (* F_45) ( struct V_1 * V_2 ,
struct V_97 * V_98 ,
struct V_108 * V_99 );
struct V_97 V_98 ;
static const T_3 V_109 [ V_110 ] =
{ 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , } ;
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) )
return 0 ;
else if ( ! F_15 ( V_111 , & V_2 -> V_36 ) )
return - V_112 ;
else if ( V_99 -> V_113 > 32 )
return - V_114 ;
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
if ( V_2 -> V_51 )
V_98 . V_115 = 0 ;
else
V_98 . V_115 = V_26 -> V_67 [ 5 ] & ( V_2 -> V_39 -> V_54 - 1 ) ;
V_98 . V_116 = F_46 ( V_99 ) ;
if ( V_98 . V_116 == V_117 )
return - V_112 ;
V_98 . V_107 = V_107 ;
if ( V_93 )
V_98 . V_118 = V_93 -> V_67 ;
else
V_98 . V_118 = V_109 ;
if ( V_98 . V_116 == V_119 )
F_43 ( & V_98 , & V_99 -> V_99 [ 0 ] , V_99 -> V_113 ) ;
else
memcpy ( V_98 . V_99 , & V_99 -> V_99 [ 0 ] , V_99 -> V_113 ) ;
if ( V_107 == V_120 )
V_99 -> V_121 = 0 ;
if ( V_99 -> V_15 & V_122 )
F_45 = V_2 -> V_39 -> V_87 -> V_123 ;
else
F_45 = V_2 -> V_39 -> V_87 -> V_124 ;
if ( ! F_45 )
return - V_112 ;
return F_45 ( V_2 , & V_98 , V_99 ) ;
}
void F_47 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
F_39 ( V_125 , & V_2 -> V_15 ) ;
F_48 ( V_2 ) ;
}
void F_49 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
F_31 ( V_125 , & V_2 -> V_15 ) ;
F_50 ( V_2 ) ;
}
int F_51 ( struct V_28 * V_19 ,
struct V_126 * V_127 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
memcpy ( V_127 , & V_2 -> V_128 , sizeof( * V_127 ) ) ;
return 0 ;
}
void F_52 ( struct V_28 * V_19 ,
struct V_41 * V_26 ,
struct V_129 * V_130 ,
T_1 V_131 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_42 * V_43 = F_25 ( V_26 ) ;
if ( ! F_15 ( V_32 , & V_2 -> V_15 ) )
return;
if ( V_131 & V_132 )
F_29 ( V_2 , V_43 , V_26 -> type , NULL ,
V_130 -> V_133 ) ;
if ( V_131 & V_134 && F_53 ( V_2 ) )
F_54 ( V_2 , V_26 ) ;
if ( V_131 & V_135 ) {
if ( ! V_130 -> V_136 && V_43 -> V_136 ) {
F_55 ( V_2 , V_26 ) ;
V_2 -> V_137 -- ;
V_43 -> V_136 = false ;
if ( V_2 -> V_137 == 0 ) {
F_56 ( & V_43 -> V_65 ) ;
F_33 ( V_2 -> V_44 ) ;
F_57 ( & V_43 -> V_65 ) ;
}
} else if ( V_130 -> V_136 && ! V_43 -> V_136 ) {
V_2 -> V_137 ++ ;
V_43 -> V_136 = true ;
if ( V_2 -> V_137 == 1 ) {
F_56 ( & V_43 -> V_65 ) ;
F_36 ( V_2 -> V_44 ) ;
F_57 ( & V_43 -> V_65 ) ;
}
}
}
if ( V_131 & V_138 ) {
V_2 -> V_139 . V_140 = 0 ;
if ( V_130 -> V_141 )
V_2 -> V_142 ++ ;
else
V_2 -> V_142 -- ;
F_58 ( V_2 , ! ! V_2 -> V_142 ) ;
}
if ( V_131 & ( V_143 | V_144 |
V_145 | V_146 |
V_147 | V_148 ) )
F_59 ( V_2 , V_43 , V_130 , V_131 ) ;
}
int F_60 ( struct V_28 * V_19 , T_4 V_149 ,
const struct V_150 * V_151 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_3 * V_4 ;
V_4 = F_16 ( V_2 , V_149 ) ;
if ( F_4 ( ! V_4 ) )
return - V_60 ;
if ( V_151 -> V_152 > 0 )
V_4 -> V_152 = F_61 ( V_151 -> V_152 ) ;
else
V_4 -> V_152 = 5 ;
if ( V_151 -> V_153 > 0 )
V_4 -> V_153 = F_61 ( V_151 -> V_153 ) ;
else
V_4 -> V_153 = 10 ;
V_4 -> V_154 = V_151 -> V_154 ;
V_4 -> V_155 = V_151 -> V_155 ;
F_62 ( V_2 ,
L_5 ,
V_149 , V_4 -> V_152 , V_4 -> V_153 , V_4 -> V_154 , V_4 -> V_155 ) ;
return 0 ;
}
void F_63 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
bool V_156 = ! ! V_2 -> V_39 -> V_87 -> V_157 ( V_2 ) ;
F_64 ( V_19 -> V_158 , ! V_156 ) ;
}
void F_65 ( struct V_28 * V_19 , bool V_159 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_3 * V_4 ;
F_66 (rt2x00dev, queue)
F_67 ( V_4 , V_159 ) ;
}
int F_68 ( struct V_28 * V_19 , T_1 V_160 , T_1 V_161 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_162 * V_163 = & V_2 -> V_139 . V_163 ;
struct V_164 * V_165 = & V_2 -> V_74 ;
struct V_164 V_166 ;
if ( ! V_160 || ( V_160 & ~ 3 ) || ! V_161 || ( V_161 & ~ 3 ) )
return - V_60 ;
if ( V_163 -> V_15 & V_167 && V_160 != 3 )
V_163 -> V_15 &= ~ V_167 ;
if ( V_163 -> V_15 & V_168 && V_161 != 3 )
V_163 -> V_15 &= ~ V_168 ;
if ( V_160 == 3 && V_165 -> V_169 == V_170 ) {
V_160 = V_170 ;
V_163 -> V_15 |= V_167 ;
}
if ( V_161 == 3 && V_165 -> V_73 == V_170 ) {
V_161 = V_170 ;
V_163 -> V_15 |= V_168 ;
}
V_166 . V_169 = V_160 ;
V_166 . V_73 = V_161 ;
F_35 ( V_2 , V_166 ) ;
return 0 ;
}
int F_69 ( struct V_28 * V_19 , T_1 * V_160 , T_1 * V_161 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_162 * V_163 = & V_2 -> V_139 . V_163 ;
struct V_164 * V_156 = & V_2 -> V_139 . V_163 . V_156 ;
if ( V_163 -> V_15 & V_167 )
* V_160 = V_171 ;
else
* V_160 = V_156 -> V_169 ;
if ( V_163 -> V_15 & V_168 )
* V_161 = V_171 ;
else
* V_161 = V_156 -> V_73 ;
return 0 ;
}
void F_70 ( struct V_28 * V_19 ,
T_1 * V_169 , T_1 * V_172 , T_1 * V_73 , T_1 * V_173 )
{
struct V_1 * V_2 = V_19 -> V_29 ;
struct V_3 * V_4 ;
F_66 (rt2x00dev, queue) {
* V_169 += V_4 -> V_174 ;
* V_172 += V_4 -> V_61 ;
}
* V_73 = V_2 -> V_73 -> V_174 ;
* V_173 = V_2 -> V_73 -> V_61 ;
}

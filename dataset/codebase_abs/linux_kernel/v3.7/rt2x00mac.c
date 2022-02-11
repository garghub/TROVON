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
F_15 ( V_36 , & V_2 -> V_37 ) )
V_32 = V_38 ;
V_4 = F_16 ( V_2 , V_32 ) ;
if ( F_4 ( ! V_4 ) ) {
ERROR ( V_2 ,
L_3
L_4 , V_32 , V_39 ) ;
goto V_34;
}
if ( ! V_2 -> V_40 -> V_19 -> V_41 &&
( V_8 -> V_13 . V_14 [ 0 ] . V_15 & ( V_23 |
V_16 ) ) ) {
if ( F_17 ( V_4 ) <= 1 )
goto V_42;
if ( F_1 ( V_2 , V_4 , V_10 ) )
goto V_42;
}
if ( F_4 ( F_11 ( V_4 , V_10 , false ) ) )
goto V_42;
F_18 ( & V_4 -> V_43 ) ;
if ( F_19 ( V_4 ) )
F_20 ( V_4 ) ;
F_21 ( & V_4 -> V_43 ) ;
return;
V_42:
F_18 ( & V_4 -> V_43 ) ;
F_20 ( V_4 ) ;
F_21 ( & V_4 -> V_43 ) ;
V_34:
F_22 ( V_19 , V_10 ) ;
}
int F_23 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
return 0 ;
return F_24 ( V_2 ) ;
}
void F_25 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
return;
F_26 ( V_2 ) ;
}
int F_27 ( struct V_28 * V_19 ,
struct V_44 * V_26 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_45 * V_46 = F_28 ( V_26 ) ;
struct V_3 * V_4 = V_2 -> V_47 ;
struct V_48 * V_49 = NULL ;
unsigned int V_50 ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) ||
! F_15 ( V_51 , & V_2 -> V_15 ) )
return - V_52 ;
for ( V_50 = 0 ; V_50 < V_4 -> V_53 ; V_50 ++ ) {
V_49 = & V_4 -> V_54 [ V_50 ] ;
if ( ! F_29 ( V_55 , & V_49 -> V_15 ) )
break;
}
if ( F_4 ( V_50 == V_4 -> V_53 ) )
return - V_56 ;
if ( V_26 -> type == V_57 )
V_2 -> V_58 ++ ;
else
V_2 -> V_59 ++ ;
F_30 ( & V_46 -> V_60 ) ;
V_46 -> V_61 = V_49 ;
F_31 ( V_2 , V_46 , V_26 -> type ,
V_26 -> V_62 , NULL ) ;
V_2 -> V_63 = 0 ;
return 0 ;
}
void F_32 ( struct V_28 * V_19 ,
struct V_44 * V_26 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_45 * V_46 = F_28 ( V_26 ) ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) ||
( V_26 -> type == V_57 && ! V_2 -> V_58 ) ||
( V_26 -> type != V_57 && ! V_2 -> V_59 ) )
return;
if ( V_26 -> type == V_57 )
V_2 -> V_58 -- ;
else
V_2 -> V_59 -- ;
F_33 ( V_55 , & V_46 -> V_61 -> V_15 ) ;
F_31 ( V_2 , V_46 ,
V_64 , NULL , NULL ) ;
}
int F_34 ( struct V_28 * V_19 , T_1 V_65 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_66 * V_67 = & V_19 -> V_67 ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
return 0 ;
F_35 ( V_2 -> V_68 ) ;
F_36 ( V_2 , V_67 , V_65 ) ;
F_37 ( V_2 , V_2 -> V_69 ) ;
F_38 ( V_2 -> V_68 ) ;
return 0 ;
}
void F_39 ( struct V_28 * V_19 ,
unsigned int V_70 ,
unsigned int * V_71 ,
T_2 V_72 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
* V_71 &=
V_73 |
V_74 |
V_75 |
V_76 |
V_77 |
V_78 |
V_79 ;
* V_71 |= V_73 ;
if ( * V_71 & V_78 ||
* V_71 & V_79 )
* V_71 |= V_79 | V_78 ;
if ( ! F_15 ( V_80 , & V_2 -> V_37 ) ) {
if ( * V_71 & V_76 || * V_71 & V_77 )
* V_71 |= V_76 | V_77 ;
}
if ( ! F_15 ( V_81 , & V_2 -> V_37 ) ) {
if ( * V_71 & V_76 )
* V_71 |= V_77 ;
}
if ( V_2 -> V_63 == * V_71 )
return;
V_2 -> V_63 = * V_71 ;
V_2 -> V_40 -> V_82 -> V_83 ( V_2 , * V_71 ) ;
}
static void F_40 ( void * V_27 , T_3 * V_84 ,
struct V_44 * V_26 )
{
struct V_45 * V_46 = F_28 ( V_26 ) ;
if ( V_26 -> type != V_57 &&
V_26 -> type != V_85 &&
V_26 -> type != V_86 &&
V_26 -> type != V_87 )
return;
F_41 ( V_88 , & V_46 -> V_89 ) ;
}
int F_42 ( struct V_28 * V_19 , struct V_90 * V_91 ,
bool V_92 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
if ( ! F_15 ( V_93 , & V_2 -> V_15 ) )
return 0 ;
F_43 ( V_2 -> V_19 ,
F_40 ,
V_2 ) ;
F_44 ( V_2 -> V_19 , & V_2 -> V_94 ) ;
return 0 ;
}
static void F_45 ( struct V_95 * V_96 , T_3 * V_97 , T_3 V_98 )
{
if ( V_98 > V_99 )
memcpy ( V_96 -> V_97 ,
& V_97 [ V_99 ] ,
sizeof( V_96 -> V_97 ) ) ;
if ( V_98 > V_100 )
memcpy ( V_96 -> V_101 ,
& V_97 [ V_100 ] ,
sizeof( V_96 -> V_101 ) ) ;
if ( V_98 > V_102 )
memcpy ( V_96 -> V_103 ,
& V_97 [ V_102 ] ,
sizeof( V_96 -> V_103 ) ) ;
}
int F_46 ( struct V_28 * V_19 , enum V_104 V_105 ,
struct V_44 * V_26 , struct V_90 * V_91 ,
struct V_106 * V_97 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
int (* F_47) ( struct V_1 * V_2 ,
struct V_95 * V_96 ,
struct V_106 * V_97 );
struct V_95 V_96 ;
static const T_3 V_107 [ V_108 ] =
{ 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , } ;
struct V_109 * V_110 = NULL ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
return 0 ;
if ( ! F_15 ( V_111 , & V_2 -> V_37 ) )
return - V_112 ;
if ( V_26 -> type == V_85 &&
! ( V_97 -> V_15 & V_113 ) )
return - V_112 ;
if ( V_97 -> V_114 > 32 )
return - V_115 ;
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_116 = F_48 ( V_2 , V_26 ) ;
V_96 . V_117 = F_49 ( V_97 ) ;
if ( V_96 . V_117 == V_118 )
return - V_112 ;
V_96 . V_105 = V_105 ;
if ( V_91 ) {
V_96 . V_119 = V_91 -> V_62 ;
V_110 = F_50 ( V_91 ) ;
V_96 . V_120 = V_110 -> V_120 ;
} else
V_96 . V_119 = V_107 ;
if ( V_96 . V_117 == V_121 )
F_45 ( & V_96 , & V_97 -> V_97 [ 0 ] , V_97 -> V_114 ) ;
else
memcpy ( V_96 . V_97 , & V_97 -> V_97 [ 0 ] , V_97 -> V_114 ) ;
if ( V_105 == V_122 )
V_97 -> V_123 = 0 ;
if ( V_97 -> V_15 & V_113 )
F_47 = V_2 -> V_40 -> V_82 -> V_124 ;
else
F_47 = V_2 -> V_40 -> V_82 -> V_125 ;
if ( ! F_47 )
return - V_112 ;
return F_47 ( V_2 , & V_96 , V_97 ) ;
}
int F_51 ( struct V_28 * V_19 , struct V_44 * V_26 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_109 * V_110 = F_50 ( V_91 ) ;
if ( V_2 -> V_40 -> V_82 -> V_126 ( V_2 , V_26 , V_91 ) )
V_110 -> V_120 = - 1 ;
return 0 ;
}
int F_52 ( struct V_28 * V_19 , struct V_44 * V_26 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_109 * V_110 = F_50 ( V_91 ) ;
if ( V_110 -> V_120 < 0 )
return 0 ;
return V_2 -> V_40 -> V_82 -> V_127 ( V_2 , V_110 -> V_120 ) ;
}
void F_53 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
F_41 ( V_128 , & V_2 -> V_15 ) ;
F_54 ( V_2 ) ;
}
void F_55 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
F_33 ( V_128 , & V_2 -> V_15 ) ;
F_56 ( V_2 ) ;
}
int F_57 ( struct V_28 * V_19 ,
struct V_129 * V_130 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
memcpy ( V_130 , & V_2 -> V_131 , sizeof( * V_130 ) ) ;
return 0 ;
}
void F_58 ( struct V_28 * V_19 ,
struct V_44 * V_26 ,
struct V_132 * V_133 ,
T_1 V_134 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_45 * V_46 = F_28 ( V_26 ) ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
return;
if ( V_134 & V_135 )
F_31 ( V_2 , V_46 , V_26 -> type , NULL ,
V_133 -> V_136 ) ;
if ( V_134 & V_137 && F_59 ( V_2 ) )
F_60 ( V_2 , V_26 ) ;
if ( V_134 & V_138 ) {
if ( ! V_133 -> V_139 && V_46 -> V_139 ) {
F_61 ( V_2 , V_26 ) ;
V_2 -> V_140 -- ;
V_46 -> V_139 = false ;
if ( V_2 -> V_140 == 0 ) {
F_62 ( & V_46 -> V_60 ) ;
F_35 ( V_2 -> V_47 ) ;
F_63 ( & V_46 -> V_60 ) ;
}
} else if ( V_133 -> V_139 && ! V_46 -> V_139 ) {
V_2 -> V_140 ++ ;
V_46 -> V_139 = true ;
if ( V_2 -> V_140 == 1 ) {
F_62 ( & V_46 -> V_60 ) ;
F_38 ( V_2 -> V_47 ) ;
F_63 ( & V_46 -> V_60 ) ;
}
}
}
if ( V_134 & V_141 ) {
V_2 -> V_142 . V_143 = 0 ;
if ( V_133 -> V_144 )
V_2 -> V_145 ++ ;
else
V_2 -> V_145 -- ;
F_64 ( V_2 , ! ! V_2 -> V_145 ) ;
F_33 ( V_146 , & V_2 -> V_15 ) ;
}
if ( V_134 & V_147 && ! V_133 -> V_148 )
F_41 ( V_146 , & V_2 -> V_15 ) ;
if ( V_134 & ( V_149 | V_150 |
V_151 | V_152 |
V_153 | V_154 ) )
F_65 ( V_2 , V_46 , V_133 , V_134 ) ;
}
int F_66 ( struct V_28 * V_19 ,
struct V_44 * V_26 , T_4 V_155 ,
const struct V_156 * V_157 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_3 * V_4 ;
V_4 = F_16 ( V_2 , V_155 ) ;
if ( F_4 ( ! V_4 ) )
return - V_158 ;
if ( V_157 -> V_159 > 0 )
V_4 -> V_159 = F_67 ( V_157 -> V_159 ) ;
else
V_4 -> V_159 = 5 ;
if ( V_157 -> V_160 > 0 )
V_4 -> V_160 = F_67 ( V_157 -> V_160 ) ;
else
V_4 -> V_160 = 10 ;
V_4 -> V_161 = V_157 -> V_161 ;
V_4 -> V_162 = V_157 -> V_162 ;
F_68 ( V_2 ,
L_5 ,
V_155 , V_4 -> V_159 , V_4 -> V_160 , V_4 -> V_161 , V_4 -> V_162 ) ;
return 0 ;
}
void F_69 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
bool V_163 = ! ! V_2 -> V_40 -> V_82 -> V_164 ( V_2 ) ;
F_70 ( V_19 -> V_165 , ! V_163 ) ;
}
void F_71 ( struct V_28 * V_19 , bool V_166 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_3 * V_4 ;
F_72 (rt2x00dev, queue)
F_73 ( V_4 , V_166 ) ;
}
int F_74 ( struct V_28 * V_19 , T_1 V_167 , T_1 V_168 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_169 * V_170 = & V_2 -> V_142 . V_170 ;
struct V_171 * V_172 = & V_2 -> V_69 ;
struct V_171 V_173 ;
if ( ! V_167 || ( V_167 & ~ 3 ) || ! V_168 || ( V_168 & ~ 3 ) )
return - V_158 ;
if ( V_170 -> V_15 & V_174 && V_167 != 3 )
V_170 -> V_15 &= ~ V_174 ;
if ( V_170 -> V_15 & V_175 && V_168 != 3 )
V_170 -> V_15 &= ~ V_175 ;
if ( V_167 == 3 && V_172 -> V_176 == V_177 ) {
V_167 = V_177 ;
V_170 -> V_15 |= V_174 ;
}
if ( V_168 == 3 && V_172 -> V_68 == V_177 ) {
V_168 = V_177 ;
V_170 -> V_15 |= V_175 ;
}
V_173 . V_176 = V_167 ;
V_173 . V_68 = V_168 ;
F_37 ( V_2 , V_173 ) ;
return 0 ;
}
int F_75 ( struct V_28 * V_19 , T_1 * V_167 , T_1 * V_168 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_169 * V_170 = & V_2 -> V_142 . V_170 ;
struct V_171 * V_163 = & V_2 -> V_142 . V_170 . V_163 ;
if ( V_170 -> V_15 & V_174 )
* V_167 = V_178 ;
else
* V_167 = V_163 -> V_176 ;
if ( V_170 -> V_15 & V_175 )
* V_168 = V_178 ;
else
* V_168 = V_163 -> V_68 ;
return 0 ;
}
void F_76 ( struct V_28 * V_19 ,
T_1 * V_176 , T_1 * V_179 , T_1 * V_68 , T_1 * V_180 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_3 * V_4 ;
F_72 (rt2x00dev, queue) {
* V_176 += V_4 -> V_181 ;
* V_179 += V_4 -> V_53 ;
}
* V_68 = V_2 -> V_68 -> V_181 ;
* V_180 = V_2 -> V_68 -> V_53 ;
}
bool F_77 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_3 * V_4 ;
F_72 (rt2x00dev, queue) {
if ( ! F_78 ( V_4 ) )
return true ;
}
return false ;
}

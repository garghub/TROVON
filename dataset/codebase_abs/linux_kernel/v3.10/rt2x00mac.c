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
F_17 ( V_2 ,
L_3
L_4 , V_32 , V_39 ) ;
goto V_34;
}
if ( ! V_2 -> V_40 -> V_19 -> V_41 &&
( V_8 -> V_13 . V_14 [ 0 ] . V_15 & ( V_23 |
V_16 ) ) ) {
if ( F_18 ( V_4 ) <= 1 )
goto V_42;
if ( F_1 ( V_2 , V_4 , V_10 ) )
goto V_42;
}
if ( F_4 ( F_11 ( V_4 , V_10 , false ) ) )
goto V_42;
F_19 ( & V_4 -> V_43 ) ;
if ( F_20 ( V_4 ) )
F_21 ( V_4 ) ;
F_22 ( & V_4 -> V_43 ) ;
return;
V_42:
F_19 ( & V_4 -> V_43 ) ;
F_21 ( V_4 ) ;
F_22 ( & V_4 -> V_43 ) ;
V_34:
F_23 ( V_19 , V_10 ) ;
}
int F_24 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
return 0 ;
return F_25 ( V_2 ) ;
}
void F_26 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
return;
F_27 ( V_2 ) ;
}
int F_28 ( struct V_28 * V_19 ,
struct V_44 * V_26 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_45 * V_46 = F_29 ( V_26 ) ;
struct V_3 * V_4 = V_2 -> V_47 ;
struct V_48 * V_49 = NULL ;
unsigned int V_50 ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) ||
! F_15 ( V_51 , & V_2 -> V_15 ) )
return - V_52 ;
for ( V_50 = 0 ; V_50 < V_4 -> V_53 ; V_50 ++ ) {
V_49 = & V_4 -> V_54 [ V_50 ] ;
if ( ! F_30 ( V_55 , & V_49 -> V_15 ) )
break;
}
if ( F_4 ( V_50 == V_4 -> V_53 ) )
return - V_56 ;
if ( V_26 -> type == V_57 )
V_2 -> V_58 ++ ;
else
V_2 -> V_59 ++ ;
F_31 ( & V_46 -> V_60 ) ;
V_46 -> V_61 = V_49 ;
F_32 ( V_2 , V_46 , V_26 -> type ,
V_26 -> V_62 , NULL ) ;
V_2 -> V_63 = 0 ;
return 0 ;
}
void F_33 ( struct V_28 * V_19 ,
struct V_44 * V_26 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_45 * V_46 = F_29 ( V_26 ) ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) ||
( V_26 -> type == V_57 && ! V_2 -> V_58 ) ||
( V_26 -> type != V_57 && ! V_2 -> V_59 ) )
return;
if ( V_26 -> type == V_57 )
V_2 -> V_58 -- ;
else
V_2 -> V_59 -- ;
F_34 ( V_55 , & V_46 -> V_61 -> V_15 ) ;
F_32 ( V_2 , V_46 ,
V_64 , NULL , NULL ) ;
}
int F_35 ( struct V_28 * V_19 , T_1 V_65 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_66 * V_67 = & V_19 -> V_67 ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
return 0 ;
F_36 ( V_2 -> V_68 ) ;
F_37 ( V_2 , V_67 , V_65 ) ;
F_38 ( V_2 , V_2 -> V_69 ) ;
F_39 ( V_2 -> V_68 ) ;
return 0 ;
}
void F_40 ( struct V_28 * V_19 ,
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
static void F_41 ( void * V_27 , T_3 * V_84 ,
struct V_44 * V_26 )
{
struct V_45 * V_46 = F_29 ( V_26 ) ;
if ( V_26 -> type != V_57 &&
V_26 -> type != V_85 &&
V_26 -> type != V_86 &&
V_26 -> type != V_87 )
return;
F_42 ( V_88 , & V_46 -> V_89 ) ;
}
int F_43 ( struct V_28 * V_19 , struct V_90 * V_91 ,
bool V_92 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
if ( ! F_15 ( V_93 , & V_2 -> V_15 ) )
return 0 ;
F_44 (
V_2 -> V_19 , V_94 ,
F_41 , V_2 ) ;
F_45 ( V_2 -> V_19 , & V_2 -> V_95 ) ;
return 0 ;
}
static void F_46 ( struct V_96 * V_97 , T_3 * V_98 , T_3 V_99 )
{
if ( V_99 > V_100 )
memcpy ( V_97 -> V_98 ,
& V_98 [ V_100 ] ,
sizeof( V_97 -> V_98 ) ) ;
if ( V_99 > V_101 )
memcpy ( V_97 -> V_102 ,
& V_98 [ V_101 ] ,
sizeof( V_97 -> V_102 ) ) ;
if ( V_99 > V_103 )
memcpy ( V_97 -> V_104 ,
& V_98 [ V_103 ] ,
sizeof( V_97 -> V_104 ) ) ;
}
int F_47 ( struct V_28 * V_19 , enum V_105 V_106 ,
struct V_44 * V_26 , struct V_90 * V_91 ,
struct V_107 * V_98 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
int (* F_48) ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
struct V_107 * V_98 );
struct V_96 V_97 ;
static const T_3 V_108 [ V_109 ] =
{ 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , } ;
struct V_110 * V_111 = NULL ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
return 0 ;
if ( ! F_15 ( V_112 , & V_2 -> V_37 ) )
return - V_113 ;
if ( V_26 -> type == V_85 &&
! ( V_98 -> V_15 & V_114 ) )
return - V_113 ;
if ( V_98 -> V_115 > 32 )
return - V_116 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_117 = F_49 ( V_2 , V_26 ) ;
V_97 . V_118 = F_50 ( V_98 ) ;
if ( V_97 . V_118 == V_119 )
return - V_113 ;
V_97 . V_106 = V_106 ;
if ( V_91 ) {
V_97 . V_120 = V_91 -> V_62 ;
V_111 = F_51 ( V_91 ) ;
V_97 . V_121 = V_111 -> V_121 ;
} else
V_97 . V_120 = V_108 ;
if ( V_97 . V_118 == V_122 )
F_46 ( & V_97 , & V_98 -> V_98 [ 0 ] , V_98 -> V_115 ) ;
else
memcpy ( V_97 . V_98 , & V_98 -> V_98 [ 0 ] , V_98 -> V_115 ) ;
if ( V_106 == V_123 )
V_98 -> V_124 = 0 ;
if ( V_98 -> V_15 & V_114 )
F_48 = V_2 -> V_40 -> V_82 -> V_125 ;
else
F_48 = V_2 -> V_40 -> V_82 -> V_126 ;
if ( ! F_48 )
return - V_113 ;
return F_48 ( V_2 , & V_97 , V_98 ) ;
}
int F_52 ( struct V_28 * V_19 , struct V_44 * V_26 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_110 * V_111 = F_51 ( V_91 ) ;
if ( V_2 -> V_40 -> V_82 -> V_127 ( V_2 , V_26 , V_91 ) )
V_111 -> V_121 = - 1 ;
return 0 ;
}
int F_53 ( struct V_28 * V_19 , struct V_44 * V_26 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_110 * V_111 = F_51 ( V_91 ) ;
if ( V_111 -> V_121 < 0 )
return 0 ;
return V_2 -> V_40 -> V_82 -> V_128 ( V_2 , V_111 -> V_121 ) ;
}
void F_54 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
F_42 ( V_129 , & V_2 -> V_15 ) ;
F_55 ( V_2 ) ;
}
void F_56 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
F_34 ( V_129 , & V_2 -> V_15 ) ;
F_57 ( V_2 ) ;
}
int F_58 ( struct V_28 * V_19 ,
struct V_130 * V_131 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
memcpy ( V_131 , & V_2 -> V_132 , sizeof( * V_131 ) ) ;
return 0 ;
}
void F_59 ( struct V_28 * V_19 ,
struct V_44 * V_26 ,
struct V_133 * V_134 ,
T_1 V_135 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_45 * V_46 = F_29 ( V_26 ) ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
return;
if ( V_135 & V_136 )
F_32 ( V_2 , V_46 , V_26 -> type , NULL ,
V_134 -> V_137 ) ;
if ( V_135 & V_138 && F_60 ( V_2 ) )
F_61 ( V_2 , V_26 ) ;
if ( V_135 & V_139 ) {
if ( ! V_134 -> V_140 && V_46 -> V_140 ) {
F_62 ( V_2 , V_26 ) ;
V_2 -> V_141 -- ;
V_46 -> V_140 = false ;
if ( V_2 -> V_141 == 0 ) {
F_63 ( & V_46 -> V_60 ) ;
F_36 ( V_2 -> V_47 ) ;
F_64 ( & V_46 -> V_60 ) ;
}
} else if ( V_134 -> V_140 && ! V_46 -> V_140 ) {
V_2 -> V_141 ++ ;
V_46 -> V_140 = true ;
if ( V_2 -> V_141 == 1 ) {
F_63 ( & V_46 -> V_60 ) ;
F_39 ( V_2 -> V_47 ) ;
F_64 ( & V_46 -> V_60 ) ;
}
}
}
if ( V_135 & V_142 ) {
V_2 -> V_143 . V_144 = 0 ;
if ( V_134 -> V_145 )
V_2 -> V_146 ++ ;
else
V_2 -> V_146 -- ;
F_65 ( V_2 , ! ! V_2 -> V_146 ) ;
F_34 ( V_147 , & V_2 -> V_15 ) ;
}
if ( V_135 & V_148 && ! V_134 -> V_149 )
F_42 ( V_147 , & V_2 -> V_15 ) ;
if ( V_135 & ( V_150 | V_151 |
V_152 | V_153 |
V_154 | V_155 ) )
F_66 ( V_2 , V_46 , V_134 , V_135 ) ;
}
int F_67 ( struct V_28 * V_19 ,
struct V_44 * V_26 , T_4 V_156 ,
const struct V_157 * V_158 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_3 * V_4 ;
V_4 = F_16 ( V_2 , V_156 ) ;
if ( F_4 ( ! V_4 ) )
return - V_159 ;
if ( V_158 -> V_160 > 0 )
V_4 -> V_160 = F_68 ( V_158 -> V_160 ) ;
else
V_4 -> V_160 = 5 ;
if ( V_158 -> V_161 > 0 )
V_4 -> V_161 = F_68 ( V_158 -> V_161 ) ;
else
V_4 -> V_161 = 10 ;
V_4 -> V_162 = V_158 -> V_162 ;
V_4 -> V_163 = V_158 -> V_163 ;
F_69 ( V_2 ,
L_5 ,
V_156 , V_4 -> V_160 , V_4 -> V_161 , V_4 -> V_162 ,
V_4 -> V_163 ) ;
return 0 ;
}
void F_70 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
bool V_164 = ! ! V_2 -> V_40 -> V_82 -> V_165 ( V_2 ) ;
F_71 ( V_19 -> V_166 , ! V_164 ) ;
}
void F_72 ( struct V_28 * V_19 , T_1 V_167 , bool V_168 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_3 * V_4 ;
F_73 (rt2x00dev, queue)
F_74 ( V_4 , V_168 ) ;
}
int F_75 ( struct V_28 * V_19 , T_1 V_169 , T_1 V_170 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_171 * V_172 = & V_2 -> V_143 . V_172 ;
struct V_173 * V_174 = & V_2 -> V_69 ;
struct V_173 V_175 ;
if ( ! V_169 || ( V_169 & ~ 3 ) || ! V_170 || ( V_170 & ~ 3 ) )
return - V_159 ;
if ( V_172 -> V_15 & V_176 && V_169 != 3 )
V_172 -> V_15 &= ~ V_176 ;
if ( V_172 -> V_15 & V_177 && V_170 != 3 )
V_172 -> V_15 &= ~ V_177 ;
if ( V_169 == 3 && V_174 -> V_178 == V_179 ) {
V_169 = V_179 ;
V_172 -> V_15 |= V_176 ;
}
if ( V_170 == 3 && V_174 -> V_68 == V_179 ) {
V_170 = V_179 ;
V_172 -> V_15 |= V_177 ;
}
V_175 . V_178 = V_169 ;
V_175 . V_68 = V_170 ;
F_38 ( V_2 , V_175 ) ;
return 0 ;
}
int F_76 ( struct V_28 * V_19 , T_1 * V_169 , T_1 * V_170 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_171 * V_172 = & V_2 -> V_143 . V_172 ;
struct V_173 * V_164 = & V_2 -> V_143 . V_172 . V_164 ;
if ( V_172 -> V_15 & V_176 )
* V_169 = V_180 ;
else
* V_169 = V_164 -> V_178 ;
if ( V_172 -> V_15 & V_177 )
* V_170 = V_180 ;
else
* V_170 = V_164 -> V_68 ;
return 0 ;
}
void F_77 ( struct V_28 * V_19 ,
T_1 * V_178 , T_1 * V_181 , T_1 * V_68 , T_1 * V_182 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_3 * V_4 ;
F_73 (rt2x00dev, queue) {
* V_178 += V_4 -> V_183 ;
* V_181 += V_4 -> V_53 ;
}
* V_68 = V_2 -> V_68 -> V_183 ;
* V_182 = V_2 -> V_68 -> V_53 ;
}
bool F_78 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_3 * V_4 ;
F_73 (rt2x00dev, queue) {
if ( ! F_79 ( V_4 ) )
return true ;
}
return false ;
}

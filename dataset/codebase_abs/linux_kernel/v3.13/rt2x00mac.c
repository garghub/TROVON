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
if ( F_4 ( F_11 ( V_4 , V_10 , V_13 -> V_43 , false ) ) )
goto V_42;
F_19 ( & V_4 -> V_44 ) ;
if ( F_20 ( V_4 ) )
F_21 ( V_4 ) ;
F_22 ( & V_4 -> V_44 ) ;
return;
V_42:
F_19 ( & V_4 -> V_44 ) ;
F_21 ( V_4 ) ;
F_22 ( & V_4 -> V_44 ) ;
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
struct V_45 * V_26 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_46 * V_47 = F_29 ( V_26 ) ;
struct V_3 * V_4 = V_2 -> V_48 ;
struct V_49 * V_50 = NULL ;
unsigned int V_51 ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) ||
! F_15 ( V_52 , & V_2 -> V_15 ) )
return - V_53 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_54 ; V_51 ++ ) {
V_50 = & V_4 -> V_55 [ V_51 ] ;
if ( ! F_30 ( V_56 , & V_50 -> V_15 ) )
break;
}
if ( F_4 ( V_51 == V_4 -> V_54 ) )
return - V_57 ;
if ( V_26 -> type == V_58 )
V_2 -> V_59 ++ ;
else
V_2 -> V_60 ++ ;
F_31 ( & V_47 -> V_61 ) ;
V_47 -> V_62 = V_50 ;
F_32 ( V_2 , V_47 , V_26 -> type ,
V_26 -> V_63 , NULL ) ;
V_2 -> V_64 = 0 ;
return 0 ;
}
void F_33 ( struct V_28 * V_19 ,
struct V_45 * V_26 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_46 * V_47 = F_29 ( V_26 ) ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) ||
( V_26 -> type == V_58 && ! V_2 -> V_59 ) ||
( V_26 -> type != V_58 && ! V_2 -> V_60 ) )
return;
if ( V_26 -> type == V_58 )
V_2 -> V_59 -- ;
else
V_2 -> V_60 -- ;
F_34 ( V_56 , & V_47 -> V_62 -> V_15 ) ;
F_32 ( V_2 , V_47 ,
V_65 , NULL , NULL ) ;
}
int F_35 ( struct V_28 * V_19 , T_1 V_66 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_67 * V_68 = & V_19 -> V_68 ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
return 0 ;
F_36 ( V_2 -> V_69 ) ;
F_37 ( V_2 , V_68 , V_66 ) ;
F_38 ( V_2 , V_2 -> V_70 ) ;
F_39 ( V_2 -> V_69 ) ;
return 0 ;
}
void F_40 ( struct V_28 * V_19 ,
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
V_79 |
V_80 ;
* V_72 |= V_74 ;
if ( * V_72 & V_79 ||
* V_72 & V_80 )
* V_72 |= V_80 | V_79 ;
if ( ! F_41 ( V_2 ) ) {
if ( * V_72 & V_77 || * V_72 & V_78 )
* V_72 |= V_77 | V_78 ;
}
if ( ! F_42 ( V_2 ) ) {
if ( * V_72 & V_77 )
* V_72 |= V_78 ;
}
if ( V_2 -> V_64 == * V_72 )
return;
V_2 -> V_64 = * V_72 ;
V_2 -> V_40 -> V_81 -> V_82 ( V_2 , * V_72 ) ;
}
static void F_43 ( void * V_27 , T_3 * V_83 ,
struct V_45 * V_26 )
{
struct V_46 * V_47 = F_29 ( V_26 ) ;
if ( V_26 -> type != V_58 &&
V_26 -> type != V_84 &&
V_26 -> type != V_85 &&
V_26 -> type != V_86 )
return;
F_44 ( V_87 , & V_47 -> V_88 ) ;
}
int F_45 ( struct V_28 * V_19 , struct V_89 * V_43 ,
bool V_90 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
if ( ! F_15 ( V_91 , & V_2 -> V_15 ) )
return 0 ;
F_46 (
V_2 -> V_19 , V_92 ,
F_43 , V_2 ) ;
F_47 ( V_2 -> V_19 , & V_2 -> V_93 ) ;
return 0 ;
}
static void F_48 ( struct V_94 * V_95 , T_3 * V_96 , T_3 V_97 )
{
if ( V_97 > V_98 )
memcpy ( V_95 -> V_96 ,
& V_96 [ V_98 ] ,
sizeof( V_95 -> V_96 ) ) ;
if ( V_97 > V_99 )
memcpy ( V_95 -> V_100 ,
& V_96 [ V_99 ] ,
sizeof( V_95 -> V_100 ) ) ;
if ( V_97 > V_101 )
memcpy ( V_95 -> V_102 ,
& V_96 [ V_101 ] ,
sizeof( V_95 -> V_102 ) ) ;
}
int F_49 ( struct V_28 * V_19 , enum V_103 V_104 ,
struct V_45 * V_26 , struct V_89 * V_43 ,
struct V_105 * V_96 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
int (* F_50) ( struct V_1 * V_2 ,
struct V_94 * V_95 ,
struct V_105 * V_96 );
struct V_94 V_95 ;
static const T_3 V_106 [ V_107 ] =
{ 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , } ;
struct V_108 * V_109 = NULL ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
return 0 ;
if ( ! F_51 ( V_2 ) )
return - V_110 ;
if ( V_26 -> type == V_84 &&
! ( V_96 -> V_15 & V_111 ) )
return - V_110 ;
if ( V_96 -> V_112 > 32 )
return - V_113 ;
memset ( & V_95 , 0 , sizeof( V_95 ) ) ;
V_95 . V_114 = F_52 ( V_2 , V_26 ) ;
V_95 . V_115 = F_53 ( V_96 ) ;
if ( V_95 . V_115 == V_116 )
return - V_110 ;
V_95 . V_104 = V_104 ;
if ( V_43 ) {
V_95 . V_117 = V_43 -> V_63 ;
V_109 = F_54 ( V_43 ) ;
V_95 . V_118 = V_109 -> V_118 ;
} else
V_95 . V_117 = V_106 ;
if ( V_95 . V_115 == V_119 )
F_48 ( & V_95 , & V_96 -> V_96 [ 0 ] , V_96 -> V_112 ) ;
else
memcpy ( V_95 . V_96 , & V_96 -> V_96 [ 0 ] , V_96 -> V_112 ) ;
if ( V_104 == V_120 )
V_96 -> V_121 = 0 ;
if ( V_96 -> V_15 & V_111 )
F_50 = V_2 -> V_40 -> V_81 -> V_122 ;
else
F_50 = V_2 -> V_40 -> V_81 -> V_123 ;
if ( ! F_50 )
return - V_110 ;
return F_50 ( V_2 , & V_95 , V_96 ) ;
}
int F_55 ( struct V_28 * V_19 , struct V_45 * V_26 ,
struct V_89 * V_43 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_108 * V_109 = F_54 ( V_43 ) ;
if ( V_2 -> V_40 -> V_81 -> V_124 ( V_2 , V_26 , V_43 ) )
V_109 -> V_118 = - 1 ;
return 0 ;
}
int F_56 ( struct V_28 * V_19 , struct V_45 * V_26 ,
struct V_89 * V_43 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_108 * V_109 = F_54 ( V_43 ) ;
if ( V_109 -> V_118 < 0 )
return 0 ;
return V_2 -> V_40 -> V_81 -> V_125 ( V_2 , V_109 -> V_118 ) ;
}
void F_57 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
F_44 ( V_126 , & V_2 -> V_15 ) ;
F_58 ( V_2 ) ;
}
void F_59 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
F_34 ( V_126 , & V_2 -> V_15 ) ;
F_60 ( V_2 ) ;
}
int F_61 ( struct V_28 * V_19 ,
struct V_127 * V_128 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
memcpy ( V_128 , & V_2 -> V_129 , sizeof( * V_128 ) ) ;
return 0 ;
}
void F_62 ( struct V_28 * V_19 ,
struct V_45 * V_26 ,
struct V_130 * V_131 ,
T_1 V_132 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_46 * V_47 = F_29 ( V_26 ) ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
return;
if ( V_132 & V_133 )
F_32 ( V_2 , V_47 , V_26 -> type , NULL ,
V_131 -> V_134 ) ;
if ( V_132 & V_135 && F_63 ( V_2 ) )
F_64 ( V_2 , V_26 ) ;
if ( V_132 & V_136 ) {
if ( ! V_131 -> V_137 && V_47 -> V_137 ) {
F_65 ( V_2 , V_26 ) ;
V_2 -> V_138 -- ;
V_47 -> V_137 = false ;
if ( V_2 -> V_138 == 0 ) {
F_66 ( & V_47 -> V_61 ) ;
F_36 ( V_2 -> V_48 ) ;
F_67 ( & V_47 -> V_61 ) ;
}
} else if ( V_131 -> V_137 && ! V_47 -> V_137 ) {
V_2 -> V_138 ++ ;
V_47 -> V_137 = true ;
if ( V_2 -> V_138 == 1 ) {
F_66 ( & V_47 -> V_61 ) ;
F_39 ( V_2 -> V_48 ) ;
F_67 ( & V_47 -> V_61 ) ;
}
}
}
if ( V_132 & V_139 ) {
V_2 -> V_140 . V_141 = 0 ;
if ( V_131 -> V_142 )
V_2 -> V_143 ++ ;
else
V_2 -> V_143 -- ;
F_68 ( V_2 , ! ! V_2 -> V_143 ) ;
F_34 ( V_144 , & V_2 -> V_15 ) ;
}
if ( V_132 & V_145 && ! V_131 -> V_146 )
F_44 ( V_144 , & V_2 -> V_15 ) ;
if ( V_132 & ( V_147 | V_148 |
V_149 | V_150 |
V_151 | V_152 ) )
F_69 ( V_2 , V_47 , V_131 , V_132 ) ;
}
int F_70 ( struct V_28 * V_19 ,
struct V_45 * V_26 , T_4 V_153 ,
const struct V_154 * V_155 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_3 * V_4 ;
V_4 = F_16 ( V_2 , V_153 ) ;
if ( F_4 ( ! V_4 ) )
return - V_156 ;
if ( V_155 -> V_157 > 0 )
V_4 -> V_157 = F_71 ( V_155 -> V_157 ) ;
else
V_4 -> V_157 = 5 ;
if ( V_155 -> V_158 > 0 )
V_4 -> V_158 = F_71 ( V_155 -> V_158 ) ;
else
V_4 -> V_158 = 10 ;
V_4 -> V_159 = V_155 -> V_159 ;
V_4 -> V_160 = V_155 -> V_160 ;
F_72 ( V_2 ,
L_5 ,
V_153 , V_4 -> V_157 , V_4 -> V_158 , V_4 -> V_159 ,
V_4 -> V_160 ) ;
return 0 ;
}
void F_73 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
bool V_161 = ! ! V_2 -> V_40 -> V_81 -> V_162 ( V_2 ) ;
F_74 ( V_19 -> V_163 , ! V_161 ) ;
}
void F_75 ( struct V_28 * V_19 , T_1 V_164 , bool V_165 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_3 * V_4 ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
return;
F_76 (rt2x00dev, queue)
F_77 ( V_4 , V_165 ) ;
}
int F_78 ( struct V_28 * V_19 , T_1 V_166 , T_1 V_167 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_168 * V_169 = & V_2 -> V_140 . V_169 ;
struct V_170 * V_171 = & V_2 -> V_70 ;
struct V_170 V_172 ;
if ( ! V_166 || ( V_166 & ~ 3 ) || ! V_167 || ( V_167 & ~ 3 ) )
return - V_156 ;
if ( V_169 -> V_15 & V_173 && V_166 != 3 )
V_169 -> V_15 &= ~ V_173 ;
if ( V_169 -> V_15 & V_174 && V_167 != 3 )
V_169 -> V_15 &= ~ V_174 ;
if ( V_166 == 3 && V_171 -> V_175 == V_176 ) {
V_166 = V_176 ;
V_169 -> V_15 |= V_173 ;
}
if ( V_167 == 3 && V_171 -> V_69 == V_176 ) {
V_167 = V_176 ;
V_169 -> V_15 |= V_174 ;
}
V_172 . V_175 = V_166 ;
V_172 . V_69 = V_167 ;
F_38 ( V_2 , V_172 ) ;
return 0 ;
}
int F_79 ( struct V_28 * V_19 , T_1 * V_166 , T_1 * V_167 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_168 * V_169 = & V_2 -> V_140 . V_169 ;
struct V_170 * V_161 = & V_2 -> V_140 . V_169 . V_161 ;
if ( V_169 -> V_15 & V_173 )
* V_166 = V_177 ;
else
* V_166 = V_161 -> V_175 ;
if ( V_169 -> V_15 & V_174 )
* V_167 = V_177 ;
else
* V_167 = V_161 -> V_69 ;
return 0 ;
}
void F_80 ( struct V_28 * V_19 ,
T_1 * V_175 , T_1 * V_178 , T_1 * V_69 , T_1 * V_179 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_3 * V_4 ;
F_76 (rt2x00dev, queue) {
* V_175 += V_4 -> V_180 ;
* V_178 += V_4 -> V_54 ;
}
* V_69 = V_2 -> V_69 -> V_180 ;
* V_179 = V_2 -> V_69 -> V_54 ;
}
bool F_81 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_3 * V_4 ;
F_76 (rt2x00dev, queue) {
if ( ! F_82 ( V_4 ) )
return true ;
}
return false ;
}

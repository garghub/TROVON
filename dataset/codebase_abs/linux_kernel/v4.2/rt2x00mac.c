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
F_38 ( V_2 , V_67 , V_65 ) ;
F_39 ( V_2 , V_2 -> V_69 ) ;
F_40 ( V_2 -> V_68 ) ;
return 0 ;
}
void F_41 ( struct V_28 * V_19 ,
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
V_78 ;
* V_71 |= V_73 ;
if ( ! F_42 ( V_2 ) ) {
if ( * V_71 & V_76 || * V_71 & V_77 )
* V_71 |= V_76 | V_77 ;
}
if ( ! F_43 ( V_2 ) ) {
if ( * V_71 & V_76 )
* V_71 |= V_77 ;
}
if ( V_2 -> V_63 == * V_71 )
return;
V_2 -> V_63 = * V_71 ;
V_2 -> V_39 -> V_79 -> V_80 ( V_2 , * V_71 ) ;
}
static void F_44 ( void * V_27 , T_3 * V_81 ,
struct V_44 * V_26 )
{
struct V_45 * V_46 = F_30 ( V_26 ) ;
if ( V_26 -> type != V_57 &&
V_26 -> type != V_82 &&
V_26 -> type != V_83 &&
V_26 -> type != V_84 )
return;
F_45 ( V_85 , & V_46 -> V_86 ) ;
}
int F_46 ( struct V_28 * V_19 , struct V_87 * V_42 ,
bool V_88 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
if ( ! F_15 ( V_89 , & V_2 -> V_15 ) )
return 0 ;
F_47 (
V_2 -> V_19 , V_90 ,
F_44 , V_2 ) ;
F_48 ( V_2 -> V_19 , & V_2 -> V_91 ) ;
return 0 ;
}
static void F_49 ( struct V_92 * V_93 , T_3 * V_94 , T_3 V_95 )
{
if ( V_95 > V_96 )
memcpy ( V_93 -> V_94 ,
& V_94 [ V_96 ] ,
sizeof( V_93 -> V_94 ) ) ;
if ( V_95 > V_97 )
memcpy ( V_93 -> V_98 ,
& V_94 [ V_97 ] ,
sizeof( V_93 -> V_98 ) ) ;
if ( V_95 > V_99 )
memcpy ( V_93 -> V_100 ,
& V_94 [ V_99 ] ,
sizeof( V_93 -> V_100 ) ) ;
}
int F_50 ( struct V_28 * V_19 , enum V_101 V_102 ,
struct V_44 * V_26 , struct V_87 * V_42 ,
struct V_103 * V_94 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
int (* F_51) ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
struct V_103 * V_94 );
struct V_92 V_93 ;
static const T_3 V_104 [ V_105 ] =
{ 0xff , 0xff , 0xff , 0xff , 0xff , 0xff , } ;
struct V_106 * V_107 = NULL ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
return 0 ;
if ( ! F_52 ( V_2 ) )
return - V_108 ;
if ( V_26 -> type == V_82 &&
! ( V_94 -> V_15 & V_109 ) )
return - V_108 ;
if ( V_94 -> V_110 > 32 )
return - V_111 ;
memset ( & V_93 , 0 , sizeof( V_93 ) ) ;
V_93 . V_112 = F_53 ( V_2 , V_26 ) ;
V_93 . V_113 = F_54 ( V_94 ) ;
if ( V_93 . V_113 == V_114 )
return - V_108 ;
if ( V_93 . V_113 == V_115 && F_55 ( V_2 ) )
return - V_108 ;
V_93 . V_102 = V_102 ;
if ( V_42 ) {
V_93 . V_116 = V_42 -> V_62 ;
V_107 = F_56 ( V_42 ) ;
V_93 . V_117 = V_107 -> V_117 ;
} else
V_93 . V_116 = V_104 ;
if ( V_93 . V_113 == V_115 )
F_49 ( & V_93 , & V_94 -> V_94 [ 0 ] , V_94 -> V_110 ) ;
else
memcpy ( V_93 . V_94 , & V_94 -> V_94 [ 0 ] , V_94 -> V_110 ) ;
if ( V_102 == V_118 )
V_94 -> V_119 = 0 ;
if ( V_94 -> V_15 & V_109 )
F_51 = V_2 -> V_39 -> V_79 -> V_120 ;
else
F_51 = V_2 -> V_39 -> V_79 -> V_121 ;
if ( ! F_51 )
return - V_108 ;
return F_51 ( V_2 , & V_93 , V_94 ) ;
}
int F_57 ( struct V_28 * V_19 , struct V_44 * V_26 ,
struct V_87 * V_42 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
return V_2 -> V_39 -> V_79 -> V_122 ( V_2 , V_26 , V_42 ) ;
}
int F_58 ( struct V_28 * V_19 , struct V_44 * V_26 ,
struct V_87 * V_42 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_106 * V_107 = F_56 ( V_42 ) ;
return V_2 -> V_39 -> V_79 -> V_123 ( V_2 , V_107 -> V_117 ) ;
}
void F_59 ( struct V_28 * V_19 ,
struct V_44 * V_26 ,
const T_3 * V_124 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
F_45 ( V_125 , & V_2 -> V_15 ) ;
F_60 ( V_2 ) ;
}
void F_61 ( struct V_28 * V_19 ,
struct V_44 * V_26 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
F_35 ( V_125 , & V_2 -> V_15 ) ;
F_62 ( V_2 ) ;
}
int F_63 ( struct V_28 * V_19 ,
struct V_126 * V_127 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
memcpy ( V_127 , & V_2 -> V_128 , sizeof( * V_127 ) ) ;
return 0 ;
}
void F_64 ( struct V_28 * V_19 ,
struct V_44 * V_26 ,
struct V_129 * V_130 ,
T_1 V_131 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_45 * V_46 = F_30 ( V_26 ) ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
return;
if ( V_131 & V_132 )
F_33 ( V_2 , V_46 , V_26 -> type , NULL ,
V_130 -> V_133 ) ;
if ( V_131 & V_134 ) {
F_65 ( & V_46 -> V_60 ) ;
if ( ! V_130 -> V_135 && V_46 -> V_135 ) {
V_2 -> V_136 -- ;
V_46 -> V_135 = false ;
if ( V_2 -> V_136 == 0 ) {
F_37 ( V_2 -> V_47 ) ;
}
F_66 ( V_2 , V_26 ) ;
} else if ( V_130 -> V_135 && ! V_46 -> V_135 ) {
V_2 -> V_136 ++ ;
V_46 -> V_135 = true ;
if ( F_55 ( V_2 ) )
F_67 ( V_2 , V_26 ) ;
if ( V_2 -> V_136 == 1 ) {
F_40 ( V_2 -> V_47 ) ;
}
}
F_68 ( & V_46 -> V_60 ) ;
}
if ( V_131 & V_137 ) {
V_2 -> V_138 . V_139 = 0 ;
if ( V_130 -> V_140 )
V_2 -> V_141 ++ ;
else
V_2 -> V_141 -- ;
F_69 ( V_2 , ! ! V_2 -> V_141 ) ;
F_35 ( V_142 , & V_2 -> V_15 ) ;
}
if ( V_131 & V_143 && ! V_130 -> V_144 )
F_45 ( V_142 , & V_2 -> V_15 ) ;
if ( V_131 & ( V_145 | V_146 |
V_147 | V_148 |
V_149 | V_150 ) )
F_70 ( V_2 , V_46 , V_130 , V_131 ) ;
}
int F_71 ( struct V_28 * V_19 ,
struct V_44 * V_26 , T_4 V_151 ,
const struct V_152 * V_153 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_3 * V_4 ;
V_4 = F_17 ( V_2 , V_151 ) ;
if ( F_4 ( ! V_4 ) )
return - V_154 ;
if ( V_153 -> V_155 > 0 )
V_4 -> V_155 = F_72 ( V_153 -> V_155 ) ;
else
V_4 -> V_155 = 5 ;
if ( V_153 -> V_156 > 0 )
V_4 -> V_156 = F_72 ( V_153 -> V_156 ) ;
else
V_4 -> V_156 = 10 ;
V_4 -> V_157 = V_153 -> V_157 ;
V_4 -> V_158 = V_153 -> V_158 ;
F_73 ( V_2 ,
L_5 ,
V_151 , V_4 -> V_155 , V_4 -> V_156 , V_4 -> V_157 ,
V_4 -> V_158 ) ;
return 0 ;
}
void F_74 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
bool V_159 = ! ! V_2 -> V_39 -> V_79 -> V_160 ( V_2 ) ;
F_75 ( V_19 -> V_161 , ! V_159 ) ;
}
void F_76 ( struct V_28 * V_19 , struct V_44 * V_26 ,
T_1 V_162 , bool V_163 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_3 * V_4 ;
if ( ! F_15 ( V_33 , & V_2 -> V_15 ) )
return;
F_77 (rt2x00dev, queue)
F_78 ( V_4 , V_163 ) ;
}
int F_79 ( struct V_28 * V_19 , T_1 V_164 , T_1 V_165 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_166 * V_167 = & V_2 -> V_138 . V_167 ;
struct V_168 * V_169 = & V_2 -> V_69 ;
struct V_168 V_170 ;
if ( ! V_164 || ( V_164 & ~ 3 ) || ! V_165 || ( V_165 & ~ 3 ) )
return - V_154 ;
if ( V_167 -> V_15 & V_171 && V_164 != 3 )
V_167 -> V_15 &= ~ V_171 ;
if ( V_167 -> V_15 & V_172 && V_165 != 3 )
V_167 -> V_15 &= ~ V_172 ;
if ( V_164 == 3 && V_169 -> V_173 == V_174 ) {
V_164 = V_174 ;
V_167 -> V_15 |= V_171 ;
}
if ( V_165 == 3 && V_169 -> V_68 == V_174 ) {
V_165 = V_174 ;
V_167 -> V_15 |= V_172 ;
}
V_170 . V_173 = V_164 ;
V_170 . V_68 = V_165 ;
V_170 . V_175 = 0 ;
V_170 . V_176 = 0 ;
F_39 ( V_2 , V_170 ) ;
return 0 ;
}
int F_80 ( struct V_28 * V_19 , T_1 * V_164 , T_1 * V_165 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_166 * V_167 = & V_2 -> V_138 . V_167 ;
struct V_168 * V_159 = & V_2 -> V_138 . V_167 . V_159 ;
if ( V_167 -> V_15 & V_171 )
* V_164 = V_177 ;
else
* V_164 = V_159 -> V_173 ;
if ( V_167 -> V_15 & V_172 )
* V_165 = V_177 ;
else
* V_165 = V_159 -> V_68 ;
return 0 ;
}
void F_81 ( struct V_28 * V_19 ,
T_1 * V_173 , T_1 * V_178 , T_1 * V_68 , T_1 * V_179 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_3 * V_4 ;
F_77 (rt2x00dev, queue) {
* V_173 += V_4 -> V_180 ;
* V_178 += V_4 -> V_53 ;
}
* V_68 = V_2 -> V_68 -> V_180 ;
* V_179 = V_2 -> V_68 -> V_53 ;
}
bool F_82 ( struct V_28 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_30 ;
struct V_3 * V_4 ;
F_77 (rt2x00dev, queue) {
if ( ! F_83 ( V_4 ) )
return true ;
}
return false ;
}

static void F_1 ( struct V_1 * V_2 ,
void * V_3 ,
union V_4 * V_5 , T_1 V_6 )
{
struct V_7 * V_8 ;
V_8 = (struct V_7 * ) V_3 ;
V_8 -> V_6 = V_6 ;
F_2 ( & V_8 -> V_9 , 0x1 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
T_1 * V_12 , bool V_13 )
{
struct V_7 * V_8 ;
T_2 V_14 ;
V_8 = (struct V_7 * ) V_11 -> V_15 . V_3 ;
V_14 = V_13 ? V_16
: V_17 ;
while ( V_14 -- ) {
if ( F_4 ( V_8 -> V_9 ) == 1 ) {
F_5 () ;
if ( V_12 )
* V_12 = V_8 -> V_6 ;
return 0 ;
}
if ( V_13 )
F_6 ( V_18 ) ;
else
F_7 ( V_19 ) ;
}
return - V_20 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
T_1 * V_12 , bool V_21 )
{
struct V_7 * V_8 ;
int V_22 ;
if ( ! V_21 ) {
V_22 = F_3 ( V_2 , V_11 , V_12 , false ) ;
if ( ! V_22 )
return 0 ;
}
V_22 = F_3 ( V_2 , V_11 , V_12 , true ) ;
if ( ! V_22 )
return 0 ;
F_9 ( V_2 , L_1 ) ;
V_22 = F_10 ( V_2 , V_2 -> V_23 ) ;
if ( V_22 ) {
F_11 ( V_2 , L_2 ) ;
goto V_24;
}
V_22 = F_3 ( V_2 , V_11 , V_12 , true ) ;
if ( ! V_22 )
return 0 ;
V_8 = (struct V_7 * ) V_11 -> V_15 . V_3 ;
if ( V_8 -> V_9 == 1 ) {
if ( V_12 )
* V_12 = V_8 -> V_6 ;
return 0 ;
}
V_24:
F_11 ( V_2 ,
L_3 ,
F_12 ( V_11 -> V_25 . V_26 . V_27 ) ,
V_11 -> V_25 . V_26 . V_28 ,
V_11 -> V_25 . V_26 . V_29 ,
F_13 ( V_11 -> V_25 . V_26 . V_30 ) ) ;
return - V_20 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
V_11 -> V_31 = 0 ;
switch ( V_11 -> V_32 ) {
case V_33 :
case V_34 :
V_11 -> V_15 . V_35 = F_1 ;
break;
case V_36 :
break;
default:
F_11 ( V_2 , L_4 ,
V_11 -> V_32 ) ;
return - V_37 ;
}
F_15 ( V_2 , V_38 ,
L_5 ,
V_11 -> V_25 . V_26 . V_27 ,
V_11 -> V_25 . V_26 . V_28 ,
V_11 -> V_25 . V_26 . V_29 ,
V_11 -> V_25 . V_39 . V_40 ,
V_11 -> V_25 . V_39 . V_41 ,
F_16 ( V_11 -> V_32 , V_33 ,
V_34 , L_6 , L_7 ,
L_8 ) ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
T_3 V_44 ;
struct V_45 V_46 ;
struct V_47 * V_48 ;
union V_49 V_50 ;
int V_22 ;
V_46 . V_51 = V_43 -> V_27 ;
V_22 = F_18 ( V_2 , & V_46 ) ;
if ( V_22 < 0 ) {
F_11 ( V_2 , L_9 ,
V_43 -> V_27 ) ;
return;
}
V_48 = V_46 . V_48 ;
F_19 ( V_48 -> V_52 . V_53 ,
V_54 , 1 ) ;
F_19 ( V_48 -> V_52 . V_55 ,
V_56 , 1 ) ;
F_19 ( V_48 -> V_52 . V_57 ,
V_58 , 1 ) ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_59 . V_60 = V_61 ;
V_44 = F_20 ( V_2 , V_62 , & V_50 ) ;
V_48 -> V_52 . V_63 = F_21 ( V_44 ) ;
V_48 -> V_64 . V_65 =
F_22 ( V_43 -> V_66 . V_67 ) ;
V_48 -> V_64 . V_68 =
F_23 ( V_43 -> V_66 . V_67 ) ;
F_24 ( V_48 -> V_64 . V_69 ,
V_2 -> V_70 -> V_66 . V_67 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_42 * V_43 , struct V_10 * V_11 )
{
struct V_71 * V_72 = & V_2 -> V_43 -> V_66 ;
T_3 V_30 = F_26 ( V_72 ) ;
struct V_73 * V_25 ;
struct V_74 V_75 ;
V_11 -> V_25 . V_26 . V_30 = F_21 ( V_30 ) ;
V_25 = F_27 ( V_72 ) ;
if ( ! V_25 ) {
F_11 ( V_2 , L_10 ) ;
return - V_37 ;
}
* V_25 = V_11 -> V_25 ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
F_19 ( V_75 . V_76 , V_77 , V_78 ) ;
F_19 ( V_75 . V_76 , V_79 , V_80 ) ;
F_19 ( V_75 . V_76 , V_81 ,
V_82 ) ;
V_75 . V_83 = V_84 ;
V_75 . V_85 = F_21 ( F_26 ( V_72 ) ) ;
F_28 () ;
F_29 ( V_2 , F_30 ( V_43 -> V_27 , V_86 ) , * ( T_2 * ) & V_75 ) ;
F_28 () ;
F_15 ( V_2 , V_38 ,
L_11 ,
F_30 ( V_43 -> V_27 , V_86 ) ,
V_43 -> V_27 , V_75 . V_76 , V_75 . V_83 ,
F_26 ( V_72 ) ) ;
return 0 ;
}
static int
F_31 ( struct V_1 * V_2 ,
struct V_87 * V_88 )
{
switch ( V_88 -> V_29 ) {
case V_89 :
F_32 ( V_2 , V_88 ) ;
return 0 ;
case V_90 :
return F_33 ( V_2 ,
V_88 -> V_91 ,
V_88 -> V_30 , & V_88 -> V_5 ) ;
case V_92 :
if ( ! F_34 ( V_93 ) )
return - V_37 ;
if ( V_88 -> V_91 == V_94 ) {
T_2 V_27 = F_12 ( V_88 -> V_5 . V_95 . V_27 ) ;
F_35 ( V_2 ,
V_2 -> V_96 ,
V_27 ) ;
return 0 ;
}
if ( V_2 -> V_97 -> V_98 ) {
struct V_99 * V_100 = V_2 -> V_97 ;
return V_100 -> V_98 ( V_100 -> V_101 ,
V_88 -> V_91 , & V_88 -> V_5 ) ;
} else {
F_11 ( V_2 ,
L_12 ) ;
return - V_37 ;
}
default:
F_11 ( V_2 ,
L_13 ,
V_88 -> V_29 ) ;
return - V_37 ;
}
}
void F_36 ( struct V_1 * V_2 , T_3 V_102 )
{
T_2 V_103 = V_104 +
F_37 ( V_2 -> V_105 ) ;
F_38 ( V_2 , V_103 , V_102 ) ;
F_39 () ;
}
int F_40 ( struct V_1 * V_2 , void * V_3 )
{
struct V_106 * V_107 = V_3 ;
struct V_71 * V_72 = & V_107 -> V_66 ;
int V_22 = 0 ;
T_3 V_108 = F_13 ( * V_107 -> V_109 ) ;
F_15 ( V_2 , V_38 , L_14 , V_108 ) ;
if ( ( V_108 & F_41 ( V_72 ) ) ==
F_41 ( V_72 ) )
V_108 += F_42 ( V_72 ) ;
while ( V_108 != F_43 ( V_72 ) ) {
struct V_87 * V_88 = F_44 ( V_72 ) ;
if ( ! V_88 ) {
V_22 = - V_37 ;
break;
}
F_15 ( V_2 , V_38 ,
L_15 ,
V_88 -> V_91 ,
V_88 -> V_29 ,
V_88 -> V_110 ,
F_13 ( V_88 -> V_30 ) ,
V_88 -> V_6 ,
V_88 -> V_31 ) ;
if ( F_45 ( V_88 -> V_31 , V_111 ) ) {
if ( F_31 ( V_2 , V_88 ) )
V_22 = - V_37 ;
} else if ( F_46 ( V_2 ,
V_88 -> V_30 ,
V_88 -> V_6 ,
& V_88 -> V_5 ) ) {
V_22 = - V_37 ;
}
F_47 ( V_72 ) ;
}
F_36 ( V_2 , F_26 ( V_72 ) ) ;
return V_22 ;
}
struct V_106 * F_48 ( struct V_1 * V_2 , T_3 V_112 )
{
struct V_106 * V_107 ;
V_107 = F_49 ( sizeof( * V_107 ) , V_113 ) ;
if ( ! V_107 )
return NULL ;
if ( F_50 ( V_2 -> V_114 ,
V_115 ,
V_116 ,
V_117 ,
V_112 ,
sizeof( union V_118 ) ,
& V_107 -> V_66 ) )
goto V_119;
F_51 ( V_2 , F_40 ,
V_107 , & V_107 -> V_120 , & V_107 -> V_109 ) ;
return V_107 ;
V_119:
F_52 ( V_2 , V_107 ) ;
return NULL ;
}
void F_53 ( struct V_1 * V_2 , struct V_106 * V_107 )
{
F_54 ( & V_107 -> V_66 ) ;
}
void F_52 ( struct V_1 * V_2 , struct V_106 * V_107 )
{
if ( ! V_107 )
return;
F_55 ( V_2 -> V_114 , & V_107 -> V_66 ) ;
F_56 ( V_107 ) ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_121 * V_122 ,
enum V_123 V_124 )
{
if ( F_58 ( V_2 -> V_114 ) )
return 0 ;
return F_46 ( V_2 , V_122 -> V_30 , 0 , NULL ) ;
}
int F_59 ( struct V_1 * V_2 ,
struct V_121 * V_122 )
{
int V_22 ;
V_22 = F_57 ( V_2 , V_122 , V_125 ) ;
if ( V_22 )
F_11 ( V_2 ,
L_16 ,
V_122 -> V_126 ) ;
return V_22 ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_43 ;
struct V_10 * V_127 = NULL ;
T_4 V_128 = 0 ;
T_2 V_129 , V_130 ;
F_61 ( & V_43 -> V_131 ) ;
F_61 ( & V_43 -> V_132 ) ;
F_61 ( & V_43 -> V_133 ) ;
F_61 ( & V_43 -> V_134 ) ;
F_62 ( & V_43 -> V_135 ) ;
V_128 = V_43 -> V_128 + F_63 ( struct V_10 , V_136 ) ;
V_127 = V_43 -> V_127 ;
V_130 = F_64 ( & V_43 -> V_66 ) ;
for ( V_129 = 0 ; V_129 < V_130 ; V_129 ++ ) {
F_24 ( V_127 -> V_25 . V_39 , V_128 ) ;
F_65 ( & V_127 -> V_137 , & V_43 -> V_133 ) ;
V_127 ++ ;
V_128 += sizeof( struct V_10 ) ;
}
V_43 -> V_138 = 0 ;
V_43 -> V_139 = 0 ;
V_43 -> V_140 = 0 ;
V_43 -> V_141 = 0 ;
F_66 ( V_43 -> V_142 , V_143 ) ;
V_43 -> V_144 = 0 ;
F_67 ( V_2 , V_62 , & V_43 -> V_27 ) ;
F_17 ( V_2 , V_43 ) ;
F_54 ( & V_43 -> V_66 ) ;
}
int F_68 ( struct V_1 * V_2 )
{
struct V_10 * V_127 = NULL ;
struct V_42 * V_43 = NULL ;
T_4 V_128 = 0 ;
T_2 V_130 ;
V_43 = F_49 ( sizeof( struct V_42 ) , V_113 ) ;
if ( ! V_43 )
return - V_145 ;
if ( F_50 ( V_2 -> V_114 ,
V_115 ,
V_146 ,
V_117 ,
0 ,
sizeof( struct V_73 ) ,
& V_43 -> V_66 ) )
goto V_147;
V_130 = F_64 ( & V_43 -> V_66 ) ;
V_127 = F_69 ( & V_2 -> V_114 -> V_148 -> V_149 ,
V_130 * sizeof( struct V_10 ) ,
& V_128 , V_113 ) ;
if ( ! V_127 )
goto V_147;
V_43 -> V_127 = V_127 ;
V_43 -> V_128 = V_128 ;
V_2 -> V_43 = V_43 ;
return 0 ;
V_147:
F_55 ( V_2 -> V_114 , & V_43 -> V_66 ) ;
F_56 ( V_43 ) ;
return - V_145 ;
}
void F_70 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_43 ;
T_2 V_130 ;
if ( ! V_43 )
return;
if ( V_43 -> V_127 ) {
V_130 = F_64 ( & V_43 -> V_66 ) ;
F_71 ( & V_2 -> V_114 -> V_148 -> V_149 ,
V_130 *
sizeof( struct V_10 ) ,
V_43 -> V_127 , V_43 -> V_128 ) ;
}
F_55 ( V_2 -> V_114 , & V_43 -> V_66 ) ;
;
F_56 ( V_43 ) ;
}
int F_72 ( struct V_1 * V_2 , struct V_10 * * V_150 )
{
struct V_42 * V_43 = V_2 -> V_43 ;
struct V_10 * V_11 = NULL ;
int V_22 = 0 ;
F_73 ( & V_43 -> V_135 ) ;
if ( F_74 ( & V_43 -> V_133 ) ) {
V_11 = F_49 ( sizeof( * V_11 ) , V_151 ) ;
if ( ! V_11 ) {
F_11 ( V_2 ,
L_17 ) ;
V_22 = - V_145 ;
goto V_152;
}
V_11 -> V_153 = & V_43 -> V_134 ;
} else {
V_11 = F_75 ( & V_43 -> V_133 ,
struct V_10 , V_137 ) ;
F_76 ( & V_11 -> V_137 ) ;
V_11 -> V_153 = & V_43 -> V_131 ;
}
* V_150 = V_11 ;
V_152:
F_77 ( & V_43 -> V_135 ) ;
return V_22 ;
}
static void F_78 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_65 ( & V_11 -> V_137 , & V_2 -> V_43 -> V_133 ) ;
}
void F_79 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
F_73 ( & V_2 -> V_43 -> V_135 ) ;
F_78 ( V_2 , V_11 ) ;
F_77 ( & V_2 -> V_43 -> V_135 ) ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
enum V_154 V_155 )
{
struct V_42 * V_43 = V_2 -> V_43 ;
if ( V_11 -> V_153 == & V_43 -> V_134 ) {
if ( F_74 ( & V_43 -> V_133 ) ) {
F_65 ( & V_11 -> V_137 , & V_43 -> V_134 ) ;
V_43 -> V_141 ++ ;
return 0 ;
} else {
struct V_10 * V_156 ;
V_156 = F_75 ( & V_43 -> V_133 ,
struct V_10 , V_137 ) ;
F_76 ( & V_156 -> V_137 ) ;
V_11 -> V_25 . V_39 = V_156 -> V_25 . V_39 ;
* V_156 = * V_11 ;
if ( V_11 -> V_32 != V_33 )
F_56 ( V_11 ) ;
V_11 = V_156 ;
}
}
switch ( V_155 ) {
case V_157 :
F_65 ( & V_11 -> V_137 , & V_43 -> V_131 ) ;
V_43 -> V_138 ++ ;
break;
case V_158 :
F_81 ( & V_11 -> V_137 , & V_43 -> V_131 ) ;
V_43 -> V_159 ++ ;
break;
default:
return - V_37 ;
}
return 0 ;
}
T_2 F_82 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_43 )
return 0xffffffff ;
return V_2 -> V_43 -> V_27 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_160 * V_161 , T_2 V_162 )
{
struct V_42 * V_43 = V_2 -> V_43 ;
int V_22 ;
while ( F_84 ( & V_43 -> V_66 ) > V_162 &&
! F_74 ( V_161 ) ) {
struct V_10 * V_11 =
F_75 ( V_161 , struct V_10 , V_137 ) ;
F_76 ( & V_11 -> V_137 ) ;
F_65 ( & V_11 -> V_137 , & V_43 -> V_132 ) ;
V_43 -> V_140 ++ ;
V_22 = F_25 ( V_2 , V_43 , V_11 ) ;
if ( V_22 ) {
F_76 ( & V_11 -> V_137 ) ;
F_78 ( V_2 , V_11 ) ;
return V_22 ;
}
}
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_43 ;
struct V_10 * V_11 = NULL ;
while ( ! F_74 ( & V_43 -> V_133 ) ) {
if ( F_74 ( & V_43 -> V_134 ) )
break;
V_11 = F_75 ( & V_43 -> V_134 ,
struct V_10 , V_137 ) ;
if ( ! V_11 )
return - V_37 ;
F_76 ( & V_11 -> V_137 ) ;
F_80 ( V_2 , V_11 , V_11 -> V_155 ) ;
}
return F_83 ( V_2 , & V_43 -> V_131 ,
V_163 ) ;
}
int F_86 ( struct V_1 * V_2 ,
struct V_10 * V_11 , T_1 * V_6 )
{
int V_22 = 0 ;
struct V_42 * V_43 = V_2 ? V_2 -> V_43 : NULL ;
bool V_164 = true ;
if ( ! V_2 )
return - V_37 ;
if ( ! V_11 ) {
F_11 ( V_2 , L_18 ) ;
return - V_37 ;
}
V_22 = F_14 ( V_2 , V_11 ) ;
F_73 ( & V_43 -> V_135 ) ;
if ( V_22 )
goto V_165;
V_22 = F_80 ( V_2 , V_11 , V_11 -> V_155 ) ;
if ( V_22 )
goto V_165;
V_22 = F_85 ( V_2 ) ;
if ( V_22 ) {
V_164 = false ;
goto V_165;
}
F_77 ( & V_43 -> V_135 ) ;
if ( V_11 -> V_32 == V_33 ) {
V_22 = F_8 ( V_2 , V_11 , V_6 ,
V_11 -> V_153 == & V_43 -> V_134 ) ;
if ( V_11 -> V_153 == & V_43 -> V_134 ) {
F_56 ( V_11 ) ;
return V_22 ;
}
if ( V_22 )
goto V_166;
F_79 ( V_2 , V_11 ) ;
}
return V_22 ;
V_166:
F_73 ( & V_43 -> V_135 ) ;
F_76 ( & V_11 -> V_137 ) ;
F_87 ( & V_43 -> V_66 ) ;
V_165:
if ( V_164 )
F_78 ( V_2 , V_11 ) ;
F_77 ( & V_43 -> V_135 ) ;
return V_22 ;
}
int F_46 ( struct V_1 * V_2 ,
T_5 V_30 ,
T_1 V_6 ,
union V_4 * V_167 )
{
struct V_42 * V_43 ;
struct V_10 * V_11 = NULL ;
struct V_10 * V_168 ;
struct V_10 * V_169 = NULL ;
int V_22 ;
if ( ! V_2 )
return - V_37 ;
V_43 = V_2 -> V_43 ;
if ( ! V_43 )
return - V_37 ;
F_73 ( & V_43 -> V_135 ) ;
F_88 (p_ent, tmp, &p_spq->completion_pending, list) {
if ( V_11 -> V_25 . V_26 . V_30 == V_30 ) {
T_3 V_170 = F_13 ( V_30 ) % V_143 ;
F_76 ( & V_11 -> V_137 ) ;
F_89 ( V_170 , V_43 -> V_142 ) ;
while ( F_90 ( V_43 -> V_144 ,
V_43 -> V_142 ) ) {
F_91 ( V_43 -> V_144 ,
V_43 -> V_142 ) ;
V_43 -> V_144 ++ ;
F_87 ( & V_43 -> V_66 ) ;
}
V_43 -> V_139 ++ ;
V_169 = V_11 ;
break;
}
F_15 ( V_2 , V_38 ,
L_19 ,
F_13 ( V_30 ) ,
F_13 ( V_11 -> V_25 . V_26 . V_30 ) ) ;
}
F_77 ( & V_43 -> V_135 ) ;
if ( ! V_169 ) {
F_11 ( V_2 ,
L_20 ,
F_13 ( V_30 ) ) ;
return - V_171 ;
}
F_15 ( V_2 , V_38 ,
L_21 ,
F_13 ( V_30 ) ,
V_11 -> V_15 . V_35 , V_11 -> V_15 . V_3 ) ;
if ( V_169 -> V_15 . V_35 )
V_169 -> V_15 . V_35 ( V_2 , V_169 -> V_15 . V_3 , V_167 ,
V_6 ) ;
else
F_15 ( V_2 ,
V_38 ,
L_22 ) ;
if ( ( V_169 -> V_32 != V_33 ) ||
( V_169 -> V_153 == & V_43 -> V_134 ) )
F_79 ( V_2 , V_169 ) ;
F_73 ( & V_43 -> V_135 ) ;
V_22 = F_85 ( V_2 ) ;
F_77 ( & V_43 -> V_135 ) ;
return V_22 ;
}
struct V_172 * F_92 ( struct V_1 * V_2 )
{
struct V_172 * V_70 ;
V_70 = F_49 ( sizeof( * V_70 ) , V_113 ) ;
if ( ! V_70 )
return NULL ;
if ( F_50 ( V_2 -> V_114 ,
V_115 ,
V_116 ,
V_117 ,
V_173 / 0x80 ,
0x80 , & V_70 -> V_66 ) )
goto V_174;
return V_70 ;
V_174:
F_93 ( V_2 , V_70 ) ;
return NULL ;
}
void F_94 ( struct V_1 * V_2 , struct V_172 * V_70 )
{
F_54 ( & V_70 -> V_66 ) ;
}
void F_93 ( struct V_1 * V_2 , struct V_172 * V_70 )
{
if ( ! V_70 )
return;
F_55 ( V_2 -> V_114 , & V_70 -> V_66 ) ;
F_56 ( V_70 ) ;
}

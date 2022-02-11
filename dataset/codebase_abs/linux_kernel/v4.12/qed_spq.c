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
struct V_22 * V_23 ;
int V_24 ;
if ( ! V_21 ) {
V_24 = F_3 ( V_2 , V_11 , V_12 , false ) ;
if ( ! V_24 )
return 0 ;
}
V_24 = F_3 ( V_2 , V_11 , V_12 , true ) ;
if ( ! V_24 )
return 0 ;
V_23 = F_9 ( V_2 ) ;
if ( ! V_23 ) {
F_10 ( V_2 , L_1 ) ;
return - V_25 ;
}
F_11 ( V_2 , L_2 ) ;
V_24 = F_12 ( V_2 , V_23 ) ;
if ( V_24 ) {
F_10 ( V_2 , L_3 ) ;
goto V_26;
}
V_24 = F_3 ( V_2 , V_11 , V_12 , true ) ;
if ( ! V_24 )
goto V_27;
V_8 = (struct V_7 * ) V_11 -> V_15 . V_3 ;
if ( V_8 -> V_9 == 1 )
if ( V_12 )
* V_12 = V_8 -> V_6 ;
V_27:
F_13 ( V_2 , V_23 ) ;
return 0 ;
V_26:
F_13 ( V_2 , V_23 ) ;
F_10 ( V_2 ,
L_4 ,
F_14 ( V_11 -> V_28 . V_29 . V_30 ) ,
V_11 -> V_28 . V_29 . V_31 ,
V_11 -> V_28 . V_29 . V_32 ,
F_15 ( V_11 -> V_28 . V_29 . V_33 ) ) ;
return - V_20 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
V_11 -> V_34 = 0 ;
switch ( V_11 -> V_35 ) {
case V_36 :
case V_37 :
V_11 -> V_15 . V_38 = F_1 ;
break;
case V_39 :
break;
default:
F_10 ( V_2 , L_5 ,
V_11 -> V_35 ) ;
return - V_40 ;
}
F_17 ( V_2 , V_41 ,
L_6 ,
V_11 -> V_28 . V_29 . V_30 ,
V_11 -> V_28 . V_29 . V_31 ,
V_11 -> V_28 . V_29 . V_32 ,
V_11 -> V_28 . V_42 . V_43 ,
V_11 -> V_28 . V_42 . V_44 ,
F_18 ( V_11 -> V_35 , V_36 ,
V_37 , L_7 , L_8 ,
L_9 ) ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
struct V_47 * V_48 ;
struct V_49 V_50 ;
T_3 V_51 ;
int V_24 ;
V_50 . V_52 = V_46 -> V_30 ;
V_24 = F_20 ( V_2 , & V_50 ) ;
if ( V_24 < 0 ) {
F_10 ( V_2 , L_10 ,
V_46 -> V_30 ) ;
return;
}
V_48 = V_50 . V_48 ;
F_21 ( V_48 -> V_53 . V_54 ,
V_55 , 1 ) ;
F_21 ( V_48 -> V_53 . V_56 ,
V_57 , 1 ) ;
F_21 ( V_48 -> V_53 . V_58 ,
V_59 , 1 ) ;
V_51 = F_22 ( V_2 , V_60 ) ;
V_48 -> V_53 . V_61 = F_23 ( V_51 ) ;
V_48 -> V_62 . V_63 =
F_24 ( V_46 -> V_64 . V_65 ) ;
V_48 -> V_62 . V_66 =
F_25 ( V_46 -> V_64 . V_65 ) ;
F_26 ( V_48 -> V_62 . V_67 ,
V_2 -> V_68 -> V_64 . V_65 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_45 * V_46 , struct V_10 * V_11 )
{
struct V_69 * V_70 = & V_2 -> V_46 -> V_64 ;
T_3 V_33 = F_28 ( V_70 ) ;
struct V_71 * V_28 ;
struct V_72 V_73 ;
V_11 -> V_28 . V_29 . V_33 = F_23 ( V_33 ) ;
V_28 = F_29 ( V_70 ) ;
if ( ! V_28 ) {
F_10 ( V_2 , L_11 ) ;
return - V_40 ;
}
* V_28 = V_11 -> V_28 ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
F_21 ( V_73 . V_74 , V_75 , V_76 ) ;
F_21 ( V_73 . V_74 , V_77 , V_78 ) ;
F_21 ( V_73 . V_74 , V_79 ,
V_80 ) ;
V_73 . V_81 = V_82 ;
V_73 . V_83 = F_23 ( F_28 ( V_70 ) ) ;
F_30 () ;
F_31 ( V_2 , F_32 ( V_46 -> V_30 , V_84 ) , * ( T_2 * ) & V_73 ) ;
F_30 () ;
F_17 ( V_2 , V_41 ,
L_12 ,
F_32 ( V_46 -> V_30 , V_84 ) ,
V_46 -> V_30 , V_73 . V_74 , V_73 . V_81 ,
F_28 ( V_70 ) ) ;
return 0 ;
}
static int
F_33 ( struct V_1 * V_2 ,
struct V_85 * V_86 )
{
switch ( V_86 -> V_32 ) {
#if F_34 ( V_87 )
case V_88 :
F_35 ( V_2 , V_86 -> V_89 ,
& V_86 -> V_5 . V_90 ) ;
return 0 ;
#endif
case V_91 :
return F_36 ( V_2 ,
V_86 -> V_89 ,
V_86 -> V_33 , & V_86 -> V_5 ) ;
case V_92 :
if ( ! F_34 ( V_93 ) )
return - V_40 ;
if ( V_2 -> V_94 -> V_95 ) {
struct V_96 * V_97 = V_2 -> V_94 ;
return V_97 -> V_95 ( V_97 -> V_98 ,
V_86 -> V_89 , & V_86 -> V_5 ) ;
} else {
F_10 ( V_2 ,
L_13 ) ;
return - V_40 ;
}
default:
F_10 ( V_2 ,
L_14 ,
V_86 -> V_32 ) ;
return - V_40 ;
}
}
void F_37 ( struct V_1 * V_2 , T_3 V_99 )
{
T_2 V_100 = V_101 +
F_38 ( V_2 -> V_102 ) ;
F_39 ( V_2 , V_100 , V_99 ) ;
F_40 () ;
}
int F_41 ( struct V_1 * V_2 , void * V_3 )
{
struct V_103 * V_104 = V_3 ;
struct V_69 * V_70 = & V_104 -> V_64 ;
int V_24 = 0 ;
T_3 V_105 = F_15 ( * V_104 -> V_106 ) ;
F_17 ( V_2 , V_41 , L_15 , V_105 ) ;
if ( ( V_105 & F_42 ( V_70 ) ) ==
F_42 ( V_70 ) )
V_105 += F_43 ( V_70 ) ;
while ( V_105 != F_44 ( V_70 ) ) {
struct V_85 * V_86 = F_45 ( V_70 ) ;
if ( ! V_86 ) {
V_24 = - V_40 ;
break;
}
F_17 ( V_2 , V_41 ,
L_16 ,
V_86 -> V_89 ,
V_86 -> V_32 ,
V_86 -> V_107 ,
F_15 ( V_86 -> V_33 ) ,
V_86 -> V_6 ,
V_86 -> V_34 ) ;
if ( F_46 ( V_86 -> V_34 , V_108 ) ) {
if ( F_33 ( V_2 , V_86 ) )
V_24 = - V_40 ;
} else if ( F_47 ( V_2 ,
V_86 -> V_33 ,
V_86 -> V_6 ,
& V_86 -> V_5 ) ) {
V_24 = - V_40 ;
}
F_48 ( V_70 ) ;
}
F_37 ( V_2 , F_28 ( V_70 ) ) ;
return V_24 ;
}
struct V_103 * F_49 ( struct V_1 * V_2 , T_3 V_109 )
{
struct V_103 * V_104 ;
V_104 = F_50 ( sizeof( * V_104 ) , V_110 ) ;
if ( ! V_104 )
return NULL ;
if ( F_51 ( V_2 -> V_111 ,
V_112 ,
V_113 ,
V_114 ,
V_109 ,
sizeof( union V_115 ) ,
& V_104 -> V_64 ) )
goto V_116;
F_52 ( V_2 , F_41 ,
V_104 , & V_104 -> V_117 , & V_104 -> V_106 ) ;
return V_104 ;
V_116:
F_53 ( V_2 , V_104 ) ;
return NULL ;
}
void F_54 ( struct V_1 * V_2 , struct V_103 * V_104 )
{
F_55 ( & V_104 -> V_64 ) ;
}
void F_53 ( struct V_1 * V_2 , struct V_103 * V_104 )
{
if ( ! V_104 )
return;
F_56 ( V_2 -> V_111 , & V_104 -> V_64 ) ;
F_57 ( V_104 ) ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_118 * V_119 ,
enum V_120 V_121 )
{
if ( F_59 ( V_2 -> V_111 ) )
return 0 ;
return F_47 ( V_2 , V_119 -> V_33 , 0 , NULL ) ;
}
int F_60 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
int V_24 ;
V_24 = F_58 ( V_2 , V_119 , V_122 ) ;
if ( V_24 )
F_10 ( V_2 ,
L_17 ,
V_119 -> V_123 ) ;
return V_24 ;
}
void F_61 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
struct V_10 * V_124 = NULL ;
T_4 V_125 = 0 ;
T_2 V_126 , V_127 ;
F_62 ( & V_46 -> V_128 ) ;
F_62 ( & V_46 -> V_129 ) ;
F_62 ( & V_46 -> V_130 ) ;
F_62 ( & V_46 -> V_131 ) ;
F_63 ( & V_46 -> V_132 ) ;
V_125 = V_46 -> V_125 + F_64 ( struct V_10 , V_133 ) ;
V_124 = V_46 -> V_124 ;
V_127 = F_65 ( & V_46 -> V_64 ) ;
for ( V_126 = 0 ; V_126 < V_127 ; V_126 ++ ) {
F_26 ( V_124 -> V_28 . V_42 , V_125 ) ;
F_66 ( & V_124 -> V_134 , & V_46 -> V_130 ) ;
V_124 ++ ;
V_125 += sizeof( struct V_10 ) ;
}
V_46 -> V_135 = 0 ;
V_46 -> V_136 = 0 ;
V_46 -> V_137 = 0 ;
V_46 -> V_138 = 0 ;
F_67 ( V_46 -> V_139 , V_140 ) ;
V_46 -> V_141 = 0 ;
F_68 ( V_2 , V_142 , & V_46 -> V_30 ) ;
F_19 ( V_2 , V_46 ) ;
F_55 ( & V_46 -> V_64 ) ;
}
int F_69 ( struct V_1 * V_2 )
{
struct V_10 * V_124 = NULL ;
struct V_45 * V_46 = NULL ;
T_4 V_125 = 0 ;
T_2 V_127 ;
V_46 = F_50 ( sizeof( struct V_45 ) , V_110 ) ;
if ( ! V_46 )
return - V_143 ;
if ( F_51 ( V_2 -> V_111 ,
V_112 ,
V_144 ,
V_114 ,
0 ,
sizeof( struct V_71 ) ,
& V_46 -> V_64 ) )
goto V_145;
V_127 = F_65 ( & V_46 -> V_64 ) ;
V_124 = F_70 ( & V_2 -> V_111 -> V_146 -> V_147 ,
V_127 * sizeof( struct V_10 ) ,
& V_125 , V_110 ) ;
if ( ! V_124 )
goto V_145;
V_46 -> V_124 = V_124 ;
V_46 -> V_125 = V_125 ;
V_2 -> V_46 = V_46 ;
return 0 ;
V_145:
F_56 ( V_2 -> V_111 , & V_46 -> V_64 ) ;
F_57 ( V_46 ) ;
return - V_143 ;
}
void F_71 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
T_2 V_127 ;
if ( ! V_46 )
return;
if ( V_46 -> V_124 ) {
V_127 = F_65 ( & V_46 -> V_64 ) ;
F_72 ( & V_2 -> V_111 -> V_146 -> V_147 ,
V_127 *
sizeof( struct V_10 ) ,
V_46 -> V_124 , V_46 -> V_125 ) ;
}
F_56 ( V_2 -> V_111 , & V_46 -> V_64 ) ;
;
F_57 ( V_46 ) ;
}
int F_73 ( struct V_1 * V_2 , struct V_10 * * V_148 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
struct V_10 * V_11 = NULL ;
int V_24 = 0 ;
F_74 ( & V_46 -> V_132 ) ;
if ( F_75 ( & V_46 -> V_130 ) ) {
V_11 = F_50 ( sizeof( * V_11 ) , V_149 ) ;
if ( ! V_11 ) {
F_10 ( V_2 ,
L_18 ) ;
V_24 = - V_143 ;
goto V_150;
}
V_11 -> V_151 = & V_46 -> V_131 ;
} else {
V_11 = F_76 ( & V_46 -> V_130 ,
struct V_10 , V_134 ) ;
F_77 ( & V_11 -> V_134 ) ;
V_11 -> V_151 = & V_46 -> V_128 ;
}
* V_148 = V_11 ;
V_150:
F_78 ( & V_46 -> V_132 ) ;
return V_24 ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_66 ( & V_11 -> V_134 , & V_2 -> V_46 -> V_130 ) ;
}
void F_80 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
F_74 ( & V_2 -> V_46 -> V_132 ) ;
F_79 ( V_2 , V_11 ) ;
F_78 ( & V_2 -> V_46 -> V_132 ) ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
enum V_152 V_153 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
if ( V_11 -> V_151 == & V_46 -> V_131 ) {
if ( F_75 ( & V_46 -> V_130 ) ) {
F_66 ( & V_11 -> V_134 , & V_46 -> V_131 ) ;
V_46 -> V_138 ++ ;
return 0 ;
} else {
struct V_10 * V_154 ;
V_154 = F_76 ( & V_46 -> V_130 ,
struct V_10 , V_134 ) ;
F_77 ( & V_154 -> V_134 ) ;
V_11 -> V_28 . V_42 = V_154 -> V_28 . V_42 ;
* V_154 = * V_11 ;
if ( V_11 -> V_35 != V_36 )
F_57 ( V_11 ) ;
V_11 = V_154 ;
}
}
switch ( V_153 ) {
case V_155 :
F_66 ( & V_11 -> V_134 , & V_46 -> V_128 ) ;
V_46 -> V_135 ++ ;
break;
case V_156 :
F_82 ( & V_11 -> V_134 , & V_46 -> V_128 ) ;
V_46 -> V_157 ++ ;
break;
default:
return - V_40 ;
}
return 0 ;
}
T_2 F_83 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_46 )
return 0xffffffff ;
return V_2 -> V_46 -> V_30 ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_158 * V_159 , T_2 V_160 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
int V_24 ;
while ( F_85 ( & V_46 -> V_64 ) > V_160 &&
! F_75 ( V_159 ) ) {
struct V_10 * V_11 =
F_76 ( V_159 , struct V_10 , V_134 ) ;
F_77 ( & V_11 -> V_134 ) ;
F_66 ( & V_11 -> V_134 , & V_46 -> V_129 ) ;
V_46 -> V_137 ++ ;
V_24 = F_27 ( V_2 , V_46 , V_11 ) ;
if ( V_24 ) {
F_77 ( & V_11 -> V_134 ) ;
F_79 ( V_2 , V_11 ) ;
return V_24 ;
}
}
return 0 ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
struct V_10 * V_11 = NULL ;
while ( ! F_75 ( & V_46 -> V_130 ) ) {
if ( F_75 ( & V_46 -> V_131 ) )
break;
V_11 = F_76 ( & V_46 -> V_131 ,
struct V_10 , V_134 ) ;
if ( ! V_11 )
return - V_40 ;
F_77 ( & V_11 -> V_134 ) ;
F_81 ( V_2 , V_11 , V_11 -> V_153 ) ;
}
return F_84 ( V_2 , & V_46 -> V_128 ,
V_161 ) ;
}
int F_87 ( struct V_1 * V_2 ,
struct V_10 * V_11 , T_1 * V_6 )
{
int V_24 = 0 ;
struct V_45 * V_46 = V_2 ? V_2 -> V_46 : NULL ;
bool V_162 = true ;
if ( ! V_2 )
return - V_40 ;
if ( ! V_11 ) {
F_10 ( V_2 , L_19 ) ;
return - V_40 ;
}
V_24 = F_16 ( V_2 , V_11 ) ;
F_74 ( & V_46 -> V_132 ) ;
if ( V_24 )
goto V_163;
V_24 = F_81 ( V_2 , V_11 , V_11 -> V_153 ) ;
if ( V_24 )
goto V_163;
V_24 = F_86 ( V_2 ) ;
if ( V_24 ) {
V_162 = false ;
goto V_163;
}
F_78 ( & V_46 -> V_132 ) ;
if ( V_11 -> V_35 == V_36 ) {
V_24 = F_8 ( V_2 , V_11 , V_6 ,
V_11 -> V_151 == & V_46 -> V_131 ) ;
if ( V_11 -> V_151 == & V_46 -> V_131 ) {
F_57 ( V_11 ) ;
return V_24 ;
}
if ( V_24 )
goto V_164;
F_80 ( V_2 , V_11 ) ;
}
return V_24 ;
V_164:
F_74 ( & V_46 -> V_132 ) ;
F_77 ( & V_11 -> V_134 ) ;
F_88 ( & V_46 -> V_64 ) ;
V_163:
if ( V_162 )
F_79 ( V_2 , V_11 ) ;
F_78 ( & V_46 -> V_132 ) ;
return V_24 ;
}
int F_47 ( struct V_1 * V_2 ,
T_5 V_33 ,
T_1 V_6 ,
union V_4 * V_165 )
{
struct V_45 * V_46 ;
struct V_10 * V_11 = NULL ;
struct V_10 * V_166 ;
struct V_10 * V_167 = NULL ;
int V_24 ;
if ( ! V_2 )
return - V_40 ;
V_46 = V_2 -> V_46 ;
if ( ! V_46 )
return - V_40 ;
F_74 ( & V_46 -> V_132 ) ;
F_89 (p_ent, tmp, &p_spq->completion_pending, list) {
if ( V_11 -> V_28 . V_29 . V_33 == V_33 ) {
T_3 V_168 = F_15 ( V_33 ) % V_140 ;
F_77 ( & V_11 -> V_134 ) ;
F_90 ( V_168 , V_46 -> V_139 ) ;
while ( F_91 ( V_46 -> V_141 ,
V_46 -> V_139 ) ) {
F_92 ( V_46 -> V_141 ,
V_46 -> V_139 ) ;
V_46 -> V_141 ++ ;
F_88 ( & V_46 -> V_64 ) ;
}
V_46 -> V_136 ++ ;
V_167 = V_11 ;
break;
}
F_17 ( V_2 , V_41 ,
L_20 ,
F_15 ( V_33 ) ,
F_15 ( V_11 -> V_28 . V_29 . V_33 ) ) ;
}
F_78 ( & V_46 -> V_132 ) ;
if ( ! V_167 ) {
F_10 ( V_2 ,
L_21 ,
F_15 ( V_33 ) ) ;
return - V_169 ;
}
F_17 ( V_2 , V_41 ,
L_22 ,
F_15 ( V_33 ) ,
V_11 -> V_15 . V_38 , V_11 -> V_15 . V_3 ) ;
if ( V_167 -> V_15 . V_38 )
V_167 -> V_15 . V_38 ( V_2 , V_167 -> V_15 . V_3 , V_165 ,
V_6 ) ;
else
F_17 ( V_2 ,
V_41 ,
L_23 ) ;
if ( ( V_167 -> V_35 != V_36 ) ||
( V_167 -> V_151 == & V_46 -> V_131 ) )
F_80 ( V_2 , V_167 ) ;
F_74 ( & V_46 -> V_132 ) ;
V_24 = F_86 ( V_2 ) ;
F_78 ( & V_46 -> V_132 ) ;
return V_24 ;
}
struct V_170 * F_93 ( struct V_1 * V_2 )
{
struct V_170 * V_68 ;
V_68 = F_50 ( sizeof( * V_68 ) , V_110 ) ;
if ( ! V_68 )
return NULL ;
if ( F_51 ( V_2 -> V_111 ,
V_112 ,
V_113 ,
V_114 ,
V_171 / 0x80 ,
0x80 , & V_68 -> V_64 ) )
goto V_172;
return V_68 ;
V_172:
F_94 ( V_2 , V_68 ) ;
return NULL ;
}
void F_95 ( struct V_1 * V_2 , struct V_170 * V_68 )
{
F_55 ( & V_68 -> V_64 ) ;
}
void F_94 ( struct V_1 * V_2 , struct V_170 * V_68 )
{
if ( ! V_68 )
return;
F_56 ( V_2 -> V_111 , & V_68 -> V_64 ) ;
F_57 ( V_68 ) ;
}

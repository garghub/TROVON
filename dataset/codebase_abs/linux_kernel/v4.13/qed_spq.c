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
T_4 V_87 ;
if ( ! V_2 -> V_46 || ( V_86 -> V_32 >= V_88 ) )
return - V_40 ;
V_87 = V_2 -> V_46 -> V_89 [ V_86 -> V_32 ] ;
if ( V_87 ) {
return V_87 ( V_2 , V_86 -> V_90 , V_86 -> V_33 ,
& V_86 -> V_5 , V_86 -> V_6 ) ;
} else {
F_10 ( V_2 ,
L_13 ,
V_86 -> V_32 ) ;
return - V_40 ;
}
}
int
F_34 ( struct V_1 * V_2 ,
enum V_91 V_32 ,
T_4 V_87 )
{
if ( ! V_2 -> V_46 || ( V_32 >= V_88 ) )
return - V_40 ;
V_2 -> V_46 -> V_89 [ V_32 ] = V_87 ;
return 0 ;
}
void
F_35 ( struct V_1 * V_2 ,
enum V_91 V_32 )
{
if ( ! V_2 -> V_46 || ( V_32 >= V_88 ) )
return;
V_2 -> V_46 -> V_89 [ V_32 ] = NULL ;
}
void F_36 ( struct V_1 * V_2 , T_3 V_92 )
{
T_2 V_93 = V_94 +
F_37 ( V_2 -> V_95 ) ;
F_38 ( V_2 , V_93 , V_92 ) ;
F_39 () ;
}
int F_40 ( struct V_1 * V_2 , void * V_3 )
{
struct V_96 * V_97 = V_3 ;
struct V_69 * V_70 = & V_97 -> V_64 ;
int V_24 = 0 ;
T_3 V_98 = F_15 ( * V_97 -> V_99 ) ;
F_17 ( V_2 , V_41 , L_14 , V_98 ) ;
if ( ( V_98 & F_41 ( V_70 ) ) ==
F_41 ( V_70 ) )
V_98 += F_42 ( V_70 ) ;
while ( V_98 != F_43 ( V_70 ) ) {
struct V_85 * V_86 = F_44 ( V_70 ) ;
if ( ! V_86 ) {
V_24 = - V_40 ;
break;
}
F_17 ( V_2 , V_41 ,
L_15 ,
V_86 -> V_90 ,
V_86 -> V_32 ,
V_86 -> V_100 ,
F_15 ( V_86 -> V_33 ) ,
V_86 -> V_6 ,
V_86 -> V_34 ) ;
if ( F_45 ( V_86 -> V_34 , V_101 ) ) {
if ( F_33 ( V_2 , V_86 ) )
V_24 = - V_40 ;
} else if ( F_46 ( V_2 ,
V_86 -> V_33 ,
V_86 -> V_6 ,
& V_86 -> V_5 ) ) {
V_24 = - V_40 ;
}
F_47 ( V_70 ) ;
}
F_36 ( V_2 , F_28 ( V_70 ) ) ;
return V_24 ;
}
int F_48 ( struct V_1 * V_2 , T_3 V_102 )
{
struct V_96 * V_97 ;
V_97 = F_49 ( sizeof( * V_97 ) , V_103 ) ;
if ( ! V_97 )
return - V_104 ;
if ( F_50 ( V_2 -> V_105 ,
V_106 ,
V_107 ,
V_108 ,
V_102 ,
sizeof( union V_109 ) ,
& V_97 -> V_64 , NULL ) )
goto V_110;
F_51 ( V_2 , F_40 ,
V_97 , & V_97 -> V_111 , & V_97 -> V_99 ) ;
V_2 -> V_97 = V_97 ;
return 0 ;
V_110:
F_52 ( V_97 ) ;
return - V_104 ;
}
void F_53 ( struct V_1 * V_2 )
{
F_54 ( & V_2 -> V_97 -> V_64 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_97 )
return;
F_56 ( V_2 -> V_105 , & V_2 -> V_97 -> V_64 ) ;
F_52 ( V_2 -> V_97 ) ;
V_2 -> V_97 = NULL ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_112 * V_113 ,
enum V_91 V_114 )
{
if ( F_58 ( V_2 -> V_105 ) )
return 0 ;
return F_46 ( V_2 , V_113 -> V_33 , 0 , NULL ) ;
}
int F_59 ( struct V_1 * V_2 ,
struct V_112 * V_113 )
{
int V_24 ;
V_24 = F_57 ( V_2 , V_113 , V_115 ) ;
if ( V_24 )
F_10 ( V_2 ,
L_16 ,
V_113 -> V_116 ) ;
return V_24 ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
struct V_10 * V_117 = NULL ;
T_5 V_118 = 0 ;
T_2 V_119 , V_120 ;
F_61 ( & V_46 -> V_121 ) ;
F_61 ( & V_46 -> V_122 ) ;
F_61 ( & V_46 -> V_123 ) ;
F_61 ( & V_46 -> V_124 ) ;
F_62 ( & V_46 -> V_125 ) ;
V_118 = V_46 -> V_118 + F_63 ( struct V_10 , V_126 ) ;
V_117 = V_46 -> V_117 ;
V_120 = F_64 ( & V_46 -> V_64 ) ;
for ( V_119 = 0 ; V_119 < V_120 ; V_119 ++ ) {
F_26 ( V_117 -> V_28 . V_42 , V_118 ) ;
F_65 ( & V_117 -> V_127 , & V_46 -> V_123 ) ;
V_117 ++ ;
V_118 += sizeof( struct V_10 ) ;
}
V_46 -> V_128 = 0 ;
V_46 -> V_129 = 0 ;
V_46 -> V_130 = 0 ;
V_46 -> V_131 = 0 ;
F_66 ( V_46 -> V_132 , V_133 ) ;
V_46 -> V_134 = 0 ;
F_67 ( V_2 , V_135 , & V_46 -> V_30 ) ;
F_19 ( V_2 , V_46 ) ;
F_54 ( & V_46 -> V_64 ) ;
}
int F_68 ( struct V_1 * V_2 )
{
struct V_10 * V_117 = NULL ;
struct V_45 * V_46 = NULL ;
T_5 V_118 = 0 ;
T_2 V_120 ;
V_46 = F_49 ( sizeof( struct V_45 ) , V_103 ) ;
if ( ! V_46 )
return - V_104 ;
if ( F_50 ( V_2 -> V_105 ,
V_106 ,
V_136 ,
V_108 ,
0 ,
sizeof( struct V_71 ) ,
& V_46 -> V_64 , NULL ) )
goto V_137;
V_120 = F_64 ( & V_46 -> V_64 ) ;
V_117 = F_69 ( & V_2 -> V_105 -> V_138 -> V_139 ,
V_120 * sizeof( struct V_10 ) ,
& V_118 , V_103 ) ;
if ( ! V_117 )
goto V_137;
V_46 -> V_117 = V_117 ;
V_46 -> V_118 = V_118 ;
V_2 -> V_46 = V_46 ;
return 0 ;
V_137:
F_56 ( V_2 -> V_105 , & V_46 -> V_64 ) ;
F_52 ( V_46 ) ;
return - V_104 ;
}
void F_70 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
T_2 V_120 ;
if ( ! V_46 )
return;
if ( V_46 -> V_117 ) {
V_120 = F_64 ( & V_46 -> V_64 ) ;
F_71 ( & V_2 -> V_105 -> V_138 -> V_139 ,
V_120 *
sizeof( struct V_10 ) ,
V_46 -> V_117 , V_46 -> V_118 ) ;
}
F_56 ( V_2 -> V_105 , & V_46 -> V_64 ) ;
F_52 ( V_46 ) ;
V_2 -> V_46 = NULL ;
}
int F_72 ( struct V_1 * V_2 , struct V_10 * * V_140 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
struct V_10 * V_11 = NULL ;
int V_24 = 0 ;
F_73 ( & V_46 -> V_125 ) ;
if ( F_74 ( & V_46 -> V_123 ) ) {
V_11 = F_49 ( sizeof( * V_11 ) , V_141 ) ;
if ( ! V_11 ) {
F_10 ( V_2 ,
L_17 ) ;
V_24 = - V_104 ;
goto V_142;
}
V_11 -> V_143 = & V_46 -> V_124 ;
} else {
V_11 = F_75 ( & V_46 -> V_123 ,
struct V_10 , V_127 ) ;
F_76 ( & V_11 -> V_127 ) ;
V_11 -> V_143 = & V_46 -> V_121 ;
}
* V_140 = V_11 ;
V_142:
F_77 ( & V_46 -> V_125 ) ;
return V_24 ;
}
static void F_78 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_65 ( & V_11 -> V_127 , & V_2 -> V_46 -> V_123 ) ;
}
void F_79 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
F_73 ( & V_2 -> V_46 -> V_125 ) ;
F_78 ( V_2 , V_11 ) ;
F_77 ( & V_2 -> V_46 -> V_125 ) ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
enum V_144 V_145 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
if ( V_11 -> V_143 == & V_46 -> V_124 ) {
if ( F_74 ( & V_46 -> V_123 ) ) {
F_65 ( & V_11 -> V_127 , & V_46 -> V_124 ) ;
V_46 -> V_131 ++ ;
return 0 ;
} else {
struct V_10 * V_146 ;
V_146 = F_75 ( & V_46 -> V_123 ,
struct V_10 , V_127 ) ;
F_76 ( & V_146 -> V_127 ) ;
V_11 -> V_28 . V_42 = V_146 -> V_28 . V_42 ;
* V_146 = * V_11 ;
if ( V_11 -> V_35 != V_36 )
F_52 ( V_11 ) ;
V_11 = V_146 ;
}
}
switch ( V_145 ) {
case V_147 :
F_65 ( & V_11 -> V_127 , & V_46 -> V_121 ) ;
V_46 -> V_128 ++ ;
break;
case V_148 :
F_81 ( & V_11 -> V_127 , & V_46 -> V_121 ) ;
V_46 -> V_149 ++ ;
break;
default:
return - V_40 ;
}
return 0 ;
}
T_2 F_82 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_46 )
return 0xffffffff ;
return V_2 -> V_46 -> V_30 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_150 * V_151 , T_2 V_152 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
int V_24 ;
while ( F_84 ( & V_46 -> V_64 ) > V_152 &&
! F_74 ( V_151 ) ) {
struct V_10 * V_11 =
F_75 ( V_151 , struct V_10 , V_127 ) ;
F_76 ( & V_11 -> V_127 ) ;
F_65 ( & V_11 -> V_127 , & V_46 -> V_122 ) ;
V_46 -> V_130 ++ ;
V_24 = F_27 ( V_2 , V_46 , V_11 ) ;
if ( V_24 ) {
F_76 ( & V_11 -> V_127 ) ;
F_78 ( V_2 , V_11 ) ;
return V_24 ;
}
}
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
struct V_10 * V_11 = NULL ;
while ( ! F_74 ( & V_46 -> V_123 ) ) {
if ( F_74 ( & V_46 -> V_124 ) )
break;
V_11 = F_75 ( & V_46 -> V_124 ,
struct V_10 , V_127 ) ;
if ( ! V_11 )
return - V_40 ;
F_76 ( & V_11 -> V_127 ) ;
F_80 ( V_2 , V_11 , V_11 -> V_145 ) ;
}
return F_83 ( V_2 , & V_46 -> V_121 ,
V_153 ) ;
}
int F_86 ( struct V_1 * V_2 ,
struct V_10 * V_11 , T_1 * V_6 )
{
int V_24 = 0 ;
struct V_45 * V_46 = V_2 ? V_2 -> V_46 : NULL ;
bool V_154 = true ;
if ( ! V_2 )
return - V_40 ;
if ( ! V_11 ) {
F_10 ( V_2 , L_18 ) ;
return - V_40 ;
}
V_24 = F_16 ( V_2 , V_11 ) ;
F_73 ( & V_46 -> V_125 ) ;
if ( V_24 )
goto V_155;
V_24 = F_80 ( V_2 , V_11 , V_11 -> V_145 ) ;
if ( V_24 )
goto V_155;
V_24 = F_85 ( V_2 ) ;
if ( V_24 ) {
V_154 = false ;
goto V_155;
}
F_77 ( & V_46 -> V_125 ) ;
if ( V_11 -> V_35 == V_36 ) {
V_24 = F_8 ( V_2 , V_11 , V_6 ,
V_11 -> V_143 == & V_46 -> V_124 ) ;
if ( V_11 -> V_143 == & V_46 -> V_124 ) {
F_52 ( V_11 ) ;
return V_24 ;
}
if ( V_24 )
goto V_156;
F_79 ( V_2 , V_11 ) ;
}
return V_24 ;
V_156:
F_73 ( & V_46 -> V_125 ) ;
F_76 ( & V_11 -> V_127 ) ;
F_87 ( & V_46 -> V_64 ) ;
V_155:
if ( V_154 )
F_78 ( V_2 , V_11 ) ;
F_77 ( & V_46 -> V_125 ) ;
return V_24 ;
}
int F_46 ( struct V_1 * V_2 ,
T_6 V_33 ,
T_1 V_6 ,
union V_4 * V_157 )
{
struct V_45 * V_46 ;
struct V_10 * V_11 = NULL ;
struct V_10 * V_158 ;
struct V_10 * V_159 = NULL ;
int V_24 ;
if ( ! V_2 )
return - V_40 ;
V_46 = V_2 -> V_46 ;
if ( ! V_46 )
return - V_40 ;
F_73 ( & V_46 -> V_125 ) ;
F_88 (p_ent, tmp, &p_spq->completion_pending, list) {
if ( V_11 -> V_28 . V_29 . V_33 == V_33 ) {
T_3 V_160 = F_15 ( V_33 ) % V_133 ;
F_76 ( & V_11 -> V_127 ) ;
F_89 ( V_160 , V_46 -> V_132 ) ;
while ( F_90 ( V_46 -> V_134 ,
V_46 -> V_132 ) ) {
F_91 ( V_46 -> V_134 ,
V_46 -> V_132 ) ;
V_46 -> V_134 ++ ;
F_87 ( & V_46 -> V_64 ) ;
}
V_46 -> V_129 ++ ;
V_159 = V_11 ;
break;
}
F_17 ( V_2 , V_41 ,
L_19 ,
F_15 ( V_33 ) ,
F_15 ( V_11 -> V_28 . V_29 . V_33 ) ) ;
}
F_77 ( & V_46 -> V_125 ) ;
if ( ! V_159 ) {
F_10 ( V_2 ,
L_20 ,
F_15 ( V_33 ) ) ;
return - V_161 ;
}
F_17 ( V_2 , V_41 ,
L_21 ,
F_15 ( V_33 ) ,
V_11 -> V_15 . V_38 , V_11 -> V_15 . V_3 ) ;
if ( V_159 -> V_15 . V_38 )
V_159 -> V_15 . V_38 ( V_2 , V_159 -> V_15 . V_3 , V_157 ,
V_6 ) ;
else
F_17 ( V_2 ,
V_41 ,
L_22 ) ;
if ( ( V_159 -> V_35 != V_36 ) ||
( V_159 -> V_143 == & V_46 -> V_124 ) )
F_79 ( V_2 , V_159 ) ;
F_73 ( & V_46 -> V_125 ) ;
V_24 = F_85 ( V_2 ) ;
F_77 ( & V_46 -> V_125 ) ;
return V_24 ;
}
int F_92 ( struct V_1 * V_2 )
{
struct V_162 * V_68 ;
V_68 = F_49 ( sizeof( * V_68 ) , V_103 ) ;
if ( ! V_68 )
return - V_104 ;
if ( F_50 ( V_2 -> V_105 ,
V_106 ,
V_107 ,
V_108 ,
V_163 / 0x80 ,
0x80 , & V_68 -> V_64 , NULL ) )
goto V_164;
V_2 -> V_68 = V_68 ;
return 0 ;
V_164:
F_52 ( V_68 ) ;
return - V_104 ;
}
void F_93 ( struct V_1 * V_2 )
{
F_54 ( & V_2 -> V_68 -> V_64 ) ;
}
void F_94 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_68 )
return;
F_56 ( V_2 -> V_105 , & V_2 -> V_68 -> V_64 ) ;
F_52 ( V_2 -> V_68 ) ;
V_2 -> V_68 = NULL ;
}

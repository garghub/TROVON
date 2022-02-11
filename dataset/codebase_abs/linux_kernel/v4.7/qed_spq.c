static void F_1 ( struct V_1 * V_2 ,
void * V_3 ,
union V_4 * V_5 ,
T_1 V_6 )
{
struct V_7 * V_8 ;
V_8 = (struct V_7 * ) V_3 ;
V_8 -> V_9 = 0x1 ;
V_8 -> V_6 = V_6 ;
F_2 () ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
T_1 * V_12 )
{
int V_13 = V_14 ;
struct V_7 * V_8 ;
int V_15 ;
V_8 = (struct V_7 * ) V_11 -> V_16 . V_3 ;
while ( V_13 ) {
F_4 () ;
if ( V_8 -> V_9 == 1 ) {
if ( V_12 )
* V_12 = V_8 -> V_6 ;
return 0 ;
}
F_5 ( 5000 , 10000 ) ;
V_13 -- ;
}
F_6 ( V_2 , L_1 ) ;
V_15 = F_7 ( V_2 , V_2 -> V_17 ) ;
if ( V_15 != 0 )
F_8 ( V_2 , L_2 ) ;
V_13 = V_14 ;
while ( V_13 ) {
F_4 () ;
if ( V_8 -> V_9 == 1 ) {
if ( V_12 )
* V_12 = V_8 -> V_6 ;
return 0 ;
}
F_5 ( 5000 , 10000 ) ;
V_13 -- ;
}
if ( V_8 -> V_9 == 1 ) {
if ( V_12 )
* V_12 = V_8 -> V_6 ;
return 0 ;
}
F_8 ( V_2 , L_3 ) ;
return - V_18 ;
}
static int
F_9 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
V_11 -> V_19 = 0 ;
switch ( V_11 -> V_20 ) {
case V_21 :
case V_22 :
V_11 -> V_16 . V_23 = F_1 ;
break;
case V_24 :
break;
default:
F_8 ( V_2 , L_4 ,
V_11 -> V_20 ) ;
return - V_25 ;
}
F_10 ( V_2 , V_26 ,
L_5 ,
V_11 -> V_27 . V_28 . V_29 ,
V_11 -> V_27 . V_28 . V_30 ,
V_11 -> V_27 . V_28 . V_31 ,
V_11 -> V_27 . V_32 . V_33 ,
V_11 -> V_27 . V_32 . V_34 ,
F_11 ( V_11 -> V_20 , V_21 ,
V_22 , L_6 , L_7 ,
L_8 ) ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
T_2 V_37 ;
struct V_38 V_39 ;
struct V_40 * V_41 ;
union V_42 V_43 ;
int V_15 ;
V_39 . V_44 = V_36 -> V_29 ;
V_15 = F_13 ( V_2 , & V_39 ) ;
if ( V_15 < 0 ) {
F_8 ( V_2 , L_9 ,
V_36 -> V_29 ) ;
return;
}
V_41 = V_39 . V_41 ;
F_14 ( V_41 -> V_45 . V_46 ,
V_47 , 1 ) ;
F_14 ( V_41 -> V_45 . V_48 ,
V_49 , 1 ) ;
F_14 ( V_41 -> V_45 . V_50 ,
V_51 , 1 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_52 . V_53 = V_54 ;
V_37 = F_15 ( V_2 , V_55 , & V_43 ) ;
V_41 -> V_45 . V_56 = F_16 ( V_37 ) ;
V_41 -> V_57 . V_58 =
F_17 ( V_36 -> V_59 . V_60 ) ;
V_41 -> V_57 . V_61 =
F_18 ( V_36 -> V_59 . V_60 ) ;
F_19 ( V_41 -> V_57 . V_62 ,
V_2 -> V_63 -> V_59 . V_60 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
struct V_10 * V_11 )
{
struct V_64 * V_65 = & V_2 -> V_36 -> V_59 ;
T_2 V_66 = F_21 ( V_65 ) ;
struct V_67 * V_27 ;
struct V_68 V_69 ;
V_11 -> V_27 . V_28 . V_66 = F_16 ( V_66 ) ;
V_27 = F_22 ( V_65 ) ;
if ( ! V_27 ) {
F_8 ( V_2 , L_10 ) ;
return - V_25 ;
}
* V_27 = V_11 -> V_27 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
F_14 ( V_69 . V_70 , V_71 , V_72 ) ;
F_14 ( V_69 . V_70 , V_73 , V_74 ) ;
F_14 ( V_69 . V_70 , V_75 ,
V_76 ) ;
V_69 . V_77 = V_78 ;
V_69 . V_79 = F_16 ( F_21 ( V_65 ) ) ;
F_23 () ;
F_24 ( V_2 , F_25 ( V_36 -> V_29 , V_80 ) , * ( V_81 * ) & V_69 ) ;
F_23 () ;
F_10 ( V_2 , V_26 ,
L_11 ,
F_25 ( V_36 -> V_29 , V_80 ) ,
V_36 -> V_29 , V_69 . V_70 , V_69 . V_77 ,
F_21 ( V_65 ) ) ;
return 0 ;
}
static int
F_26 ( struct V_1 * V_2 ,
struct V_82 * V_83 )
{
switch ( V_83 -> V_31 ) {
case V_84 :
return F_27 ( V_2 ,
V_83 -> V_85 ,
V_83 -> V_66 , & V_83 -> V_5 ) ;
default:
F_8 ( V_2 ,
L_12 ,
V_83 -> V_31 ) ;
return - V_25 ;
}
}
void F_28 ( struct V_1 * V_2 ,
T_2 V_86 )
{
V_81 V_87 = V_88 +
F_29 ( V_2 -> V_89 ) ;
F_30 ( V_2 , V_87 , V_86 ) ;
F_31 () ;
}
int F_32 ( struct V_1 * V_2 ,
void * V_3 )
{
struct V_90 * V_91 = V_3 ;
struct V_64 * V_65 = & V_91 -> V_59 ;
int V_15 = 0 ;
T_2 V_92 = F_33 ( * V_91 -> V_93 ) ;
F_10 ( V_2 , V_26 , L_13 , V_92 ) ;
if ( ( V_92 & F_34 ( V_65 ) ) ==
F_34 ( V_65 ) )
V_92 += F_35 ( V_65 ) ;
while ( V_92 != F_36 ( V_65 ) ) {
struct V_82 * V_83 = F_37 ( V_65 ) ;
if ( ! V_83 ) {
V_15 = - V_25 ;
break;
}
F_10 ( V_2 , V_26 ,
L_14 ,
V_83 -> V_85 ,
V_83 -> V_31 ,
V_83 -> V_94 ,
F_33 ( V_83 -> V_66 ) ,
V_83 -> V_6 ,
V_83 -> V_19 ) ;
if ( F_38 ( V_83 -> V_19 , V_95 ) ) {
if ( F_26 ( V_2 , V_83 ) )
V_15 = - V_25 ;
} else if ( F_39 ( V_2 ,
V_83 -> V_66 ,
V_83 -> V_6 ,
& V_83 -> V_5 ) ) {
V_15 = - V_25 ;
}
F_40 ( V_65 ) ;
}
F_28 ( V_2 , F_21 ( V_65 ) ) ;
return V_15 ;
}
struct V_90 * F_41 ( struct V_1 * V_2 ,
T_2 V_96 )
{
struct V_90 * V_91 ;
V_91 = F_42 ( sizeof( * V_91 ) , V_97 ) ;
if ( ! V_91 ) {
F_8 ( V_2 , L_15 ) ;
return NULL ;
}
if ( F_43 ( V_2 -> V_98 ,
V_99 ,
V_100 ,
V_96 ,
sizeof( union V_101 ) ,
& V_91 -> V_59 ) ) {
F_8 ( V_2 , L_16 ) ;
goto V_102;
}
F_44 ( V_2 ,
F_32 ,
V_91 ,
& V_91 -> V_103 ,
& V_91 -> V_93 ) ;
return V_91 ;
V_102:
F_45 ( V_2 , V_91 ) ;
return NULL ;
}
void F_46 ( struct V_1 * V_2 ,
struct V_90 * V_91 )
{
F_47 ( & V_91 -> V_59 ) ;
}
void F_45 ( struct V_1 * V_2 ,
struct V_90 * V_91 )
{
if ( ! V_91 )
return;
F_48 ( V_2 -> V_98 , & V_91 -> V_59 ) ;
F_49 ( V_91 ) ;
}
static int F_50 (
struct V_1 * V_2 ,
struct V_104 * V_105 ,
enum V_106 V_107 )
{
if ( F_51 ( V_2 -> V_98 ) )
return 0 ;
return F_39 ( V_2 , V_105 -> V_66 , 0 , NULL ) ;
}
int F_52 ( struct V_1 * V_2 ,
struct V_104 * V_105 )
{
int V_15 ;
V_15 = F_50 ( V_2 , V_105 , V_108 ) ;
if ( V_15 )
F_8 ( V_2 ,
L_17 ,
V_105 -> V_109 ) ;
return V_15 ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
struct V_10 * V_110 = NULL ;
T_3 V_111 = 0 ;
unsigned int V_112 = 0 ;
F_54 ( & V_36 -> V_113 ) ;
F_54 ( & V_36 -> V_114 ) ;
F_54 ( & V_36 -> V_115 ) ;
F_54 ( & V_36 -> V_116 ) ;
F_55 ( & V_36 -> V_117 ) ;
V_111 = V_36 -> V_111 + F_56 ( struct V_10 , V_118 ) ;
V_110 = V_36 -> V_110 ;
for ( V_112 = 0 ; V_112 < V_36 -> V_59 . V_119 ; V_112 ++ ) {
F_19 ( V_110 -> V_27 . V_32 , V_111 ) ;
F_57 ( & V_110 -> V_120 , & V_36 -> V_115 ) ;
V_110 ++ ;
V_111 += sizeof( struct V_10 ) ;
}
V_36 -> V_121 = 0 ;
V_36 -> V_122 = 0 ;
V_36 -> V_123 = 0 ;
V_36 -> V_124 = 0 ;
F_58 ( V_36 -> V_125 , V_126 ) ;
V_36 -> V_127 = 0 ;
F_59 ( V_2 , V_55 , & V_36 -> V_29 ) ;
F_12 ( V_2 , V_36 ) ;
F_47 ( & V_36 -> V_59 ) ;
}
int F_60 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = NULL ;
T_3 V_111 = 0 ;
struct V_10 * V_110 = NULL ;
V_36 =
F_42 ( sizeof( struct V_35 ) , V_97 ) ;
if ( ! V_36 ) {
F_8 ( V_2 , L_18 ) ;
return - V_128 ;
}
if ( F_43 ( V_2 -> V_98 ,
V_99 ,
V_129 ,
0 ,
sizeof( struct V_67 ) ,
& V_36 -> V_59 ) ) {
F_8 ( V_2 , L_19 ) ;
goto V_130;
}
V_110 = F_61 ( & V_2 -> V_98 -> V_131 -> V_132 ,
V_36 -> V_59 . V_119 *
sizeof( struct V_10 ) ,
& V_111 ,
V_97 ) ;
if ( ! V_110 )
goto V_130;
V_36 -> V_110 = V_110 ;
V_36 -> V_111 = V_111 ;
V_2 -> V_36 = V_36 ;
return 0 ;
V_130:
F_48 ( V_2 -> V_98 , & V_36 -> V_59 ) ;
F_49 ( V_36 ) ;
return - V_128 ;
}
void F_62 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
if ( ! V_36 )
return;
if ( V_36 -> V_110 )
F_63 ( & V_2 -> V_98 -> V_131 -> V_132 ,
V_36 -> V_59 . V_119 *
sizeof( struct V_10 ) ,
V_36 -> V_110 ,
V_36 -> V_111 ) ;
F_48 ( V_2 -> V_98 , & V_36 -> V_59 ) ;
;
F_49 ( V_36 ) ;
}
int
F_64 ( struct V_1 * V_2 ,
struct V_10 * * V_133 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
struct V_10 * V_11 = NULL ;
int V_15 = 0 ;
F_65 ( & V_36 -> V_117 ) ;
if ( F_66 ( & V_36 -> V_115 ) ) {
V_11 = F_42 ( sizeof( * V_11 ) , V_134 ) ;
if ( ! V_11 ) {
V_15 = - V_128 ;
goto V_135;
}
V_11 -> V_136 = & V_36 -> V_116 ;
} else {
V_11 = F_67 ( & V_36 -> V_115 ,
struct V_10 ,
V_120 ) ;
F_68 ( & V_11 -> V_120 ) ;
V_11 -> V_136 = & V_36 -> V_113 ;
}
* V_133 = V_11 ;
V_135:
F_69 ( & V_36 -> V_117 ) ;
return V_15 ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_57 ( & V_11 -> V_120 , & V_2 -> V_36 -> V_115 ) ;
}
void F_71 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_65 ( & V_2 -> V_36 -> V_117 ) ;
F_70 ( V_2 , V_11 ) ;
F_69 ( & V_2 -> V_36 -> V_117 ) ;
}
static int
F_72 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
enum V_137 V_138 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
if ( V_11 -> V_136 == & V_36 -> V_116 ) {
if ( F_66 ( & V_36 -> V_115 ) ) {
F_57 ( & V_11 -> V_120 , & V_36 -> V_116 ) ;
V_36 -> V_124 ++ ;
return 0 ;
} else {
struct V_10 * V_139 ;
V_139 = F_67 ( & V_36 -> V_115 ,
struct V_10 ,
V_120 ) ;
F_68 ( & V_139 -> V_120 ) ;
V_11 -> V_27 . V_32 = V_139 -> V_27 . V_32 ;
* V_139 = * V_11 ;
if ( V_11 -> V_20 != V_21 )
F_49 ( V_11 ) ;
V_11 = V_139 ;
}
}
switch ( V_138 ) {
case V_140 :
F_57 ( & V_11 -> V_120 , & V_36 -> V_113 ) ;
V_36 -> V_121 ++ ;
break;
case V_141 :
F_73 ( & V_11 -> V_120 , & V_36 -> V_113 ) ;
V_36 -> V_142 ++ ;
break;
default:
return - V_25 ;
}
return 0 ;
}
V_81 F_74 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_36 )
return 0xffffffff ;
return V_2 -> V_36 -> V_29 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_143 * V_144 ,
V_81 V_145 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
int V_15 ;
while ( F_76 ( & V_36 -> V_59 ) > V_145 &&
! F_66 ( V_144 ) ) {
struct V_10 * V_11 =
F_67 ( V_144 , struct V_10 , V_120 ) ;
F_68 ( & V_11 -> V_120 ) ;
F_57 ( & V_11 -> V_120 , & V_36 -> V_114 ) ;
V_36 -> V_123 ++ ;
V_15 = F_20 ( V_2 , V_36 , V_11 ) ;
if ( V_15 ) {
F_68 ( & V_11 -> V_120 ) ;
F_70 ( V_2 , V_11 ) ;
return V_15 ;
}
}
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
struct V_10 * V_11 = NULL ;
while ( ! F_66 ( & V_36 -> V_115 ) ) {
if ( F_66 ( & V_36 -> V_116 ) )
break;
V_11 = F_67 ( & V_36 -> V_116 ,
struct V_10 ,
V_120 ) ;
if ( ! V_11 )
return - V_25 ;
F_68 ( & V_11 -> V_120 ) ;
F_72 ( V_2 , V_11 , V_11 -> V_138 ) ;
}
return F_75 ( V_2 , & V_36 -> V_113 ,
V_146 ) ;
}
int F_78 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
T_1 * V_6 )
{
int V_15 = 0 ;
struct V_35 * V_36 = V_2 ? V_2 -> V_36 : NULL ;
bool V_147 = true ;
if ( ! V_2 )
return - V_25 ;
if ( ! V_11 ) {
F_8 ( V_2 , L_20 ) ;
return - V_25 ;
}
V_15 = F_9 ( V_2 , V_11 ) ;
F_65 ( & V_36 -> V_117 ) ;
if ( V_15 )
goto V_148;
V_15 = F_72 ( V_2 , V_11 , V_11 -> V_138 ) ;
if ( V_15 )
goto V_148;
V_15 = F_77 ( V_2 ) ;
if ( V_15 ) {
V_147 = false ;
goto V_148;
}
F_69 ( & V_36 -> V_117 ) ;
if ( V_11 -> V_20 == V_21 ) {
V_15 = F_3 ( V_2 , V_11 , V_6 ) ;
if ( V_11 -> V_136 == & V_36 -> V_116 ) {
F_49 ( V_11 ) ;
return V_15 ;
}
if ( V_15 )
goto V_149;
F_71 ( V_2 , V_11 ) ;
}
return V_15 ;
V_149:
F_65 ( & V_36 -> V_117 ) ;
F_68 ( & V_11 -> V_120 ) ;
F_79 ( & V_36 -> V_59 ) ;
V_148:
if ( V_147 )
F_70 ( V_2 , V_11 ) ;
F_69 ( & V_36 -> V_117 ) ;
return V_15 ;
}
int F_39 ( struct V_1 * V_2 ,
T_4 V_66 ,
T_1 V_6 ,
union V_4 * V_150 )
{
struct V_35 * V_36 ;
struct V_10 * V_11 = NULL ;
struct V_10 * V_151 ;
struct V_10 * V_152 = NULL ;
int V_15 ;
if ( ! V_2 )
return - V_25 ;
V_36 = V_2 -> V_36 ;
if ( ! V_36 )
return - V_25 ;
F_65 ( & V_36 -> V_117 ) ;
F_80 (p_ent, tmp, &p_spq->completion_pending,
list) {
if ( V_11 -> V_27 . V_28 . V_66 == V_66 ) {
T_2 V_153 = F_33 ( V_66 ) % V_126 ;
F_68 ( & V_11 -> V_120 ) ;
F_81 ( V_36 -> V_125 , V_153 , V_126 ) ;
while ( F_82 ( V_36 -> V_127 ,
V_36 -> V_125 ) ) {
F_83 ( V_36 -> V_125 ,
V_36 -> V_127 ,
V_126 ) ;
V_36 -> V_127 ++ ;
F_79 ( & V_36 -> V_59 ) ;
}
V_36 -> V_122 ++ ;
V_152 = V_11 ;
break;
}
F_10 ( V_2 , V_26 ,
L_21 ,
F_33 ( V_66 ) ,
F_33 ( V_11 -> V_27 . V_28 . V_66 ) ) ;
}
F_69 ( & V_36 -> V_117 ) ;
if ( ! V_152 ) {
F_8 ( V_2 ,
L_22 ) ;
return - V_154 ;
}
F_10 ( V_2 , V_26 , L_23 ,
V_11 -> V_16 . V_23 , V_11 -> V_16 . V_3 ) ;
if ( V_152 -> V_16 . V_23 )
V_152 -> V_16 . V_23 ( V_2 , V_152 -> V_16 . V_3 , V_150 ,
V_6 ) ;
if ( ( V_152 -> V_20 != V_21 ) ||
( V_152 -> V_136 == & V_36 -> V_116 ) )
F_71 ( V_2 , V_152 ) ;
F_65 ( & V_36 -> V_117 ) ;
V_15 = F_77 ( V_2 ) ;
F_69 ( & V_36 -> V_117 ) ;
return V_15 ;
}
struct V_155 * F_84 ( struct V_1 * V_2 )
{
struct V_155 * V_63 ;
V_63 = F_42 ( sizeof( * V_63 ) , V_97 ) ;
if ( ! V_63 ) {
F_8 ( V_2 , L_24 ) ;
return NULL ;
}
if ( F_43 ( V_2 -> V_98 ,
V_99 ,
V_100 ,
V_156 / 0x80 ,
0x80 ,
& V_63 -> V_59 ) ) {
F_8 ( V_2 , L_25 ) ;
goto V_157;
}
return V_63 ;
V_157:
F_85 ( V_2 , V_63 ) ;
return NULL ;
}
void F_86 ( struct V_1 * V_2 ,
struct V_155 * V_63 )
{
F_47 ( & V_63 -> V_59 ) ;
}
void F_85 ( struct V_1 * V_2 ,
struct V_155 * V_63 )
{
if ( ! V_63 )
return;
F_48 ( V_2 -> V_98 , & V_63 -> V_59 ) ;
F_49 ( V_63 ) ;
}

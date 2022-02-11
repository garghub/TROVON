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
F_23 () ;
V_69 . V_79 = F_16 ( F_21 ( V_65 ) ) ;
F_24 () ;
F_25 ( V_2 , F_26 ( V_36 -> V_29 , V_80 ) , * ( V_81 * ) & V_69 ) ;
F_27 () ;
F_10 ( V_2 , V_26 ,
L_11 ,
F_26 ( V_36 -> V_29 , V_80 ) ,
V_36 -> V_29 , V_69 . V_70 , V_69 . V_77 ,
F_21 ( V_65 ) ) ;
return 0 ;
}
static int
F_28 ( struct V_1 * V_2 ,
struct V_82 * V_83 )
{
F_8 ( V_2 ,
L_12 ,
V_83 -> V_31 ) ;
return - V_25 ;
}
void F_29 ( struct V_1 * V_2 ,
T_2 V_84 )
{
V_81 V_85 = V_86 +
F_30 ( V_2 -> V_87 ) ;
F_31 ( V_2 , V_85 , V_84 ) ;
F_27 () ;
}
int F_32 ( struct V_1 * V_2 ,
void * V_3 )
{
struct V_88 * V_89 = V_3 ;
struct V_64 * V_65 = & V_89 -> V_59 ;
int V_15 = 0 ;
T_2 V_90 = F_33 ( * V_89 -> V_91 ) ;
F_10 ( V_2 , V_26 , L_13 , V_90 ) ;
if ( ( V_90 & F_34 ( V_65 ) ) ==
F_34 ( V_65 ) )
V_90 += F_35 ( V_65 ) ;
while ( V_90 != F_36 ( V_65 ) ) {
struct V_82 * V_83 = F_37 ( V_65 ) ;
if ( ! V_83 ) {
V_15 = - V_25 ;
break;
}
F_10 ( V_2 , V_26 ,
L_14 ,
V_83 -> V_92 ,
V_83 -> V_31 ,
V_83 -> V_93 ,
F_33 ( V_83 -> V_66 ) ,
V_83 -> V_6 ,
V_83 -> V_19 ) ;
if ( F_38 ( V_83 -> V_19 , V_94 ) ) {
if ( F_28 ( V_2 , V_83 ) )
V_15 = - V_25 ;
} else if ( F_39 ( V_2 ,
V_83 -> V_66 ,
V_83 -> V_6 ,
& V_83 -> V_5 ) ) {
V_15 = - V_25 ;
}
F_40 ( V_65 ) ;
}
F_29 ( V_2 , F_21 ( V_65 ) ) ;
return V_15 ;
}
struct V_88 * F_41 ( struct V_1 * V_2 ,
T_2 V_95 )
{
struct V_88 * V_89 ;
V_89 = F_42 ( sizeof( * V_89 ) , V_96 ) ;
if ( ! V_89 ) {
F_8 ( V_2 , L_15 ) ;
return NULL ;
}
if ( F_43 ( V_2 -> V_97 ,
V_98 ,
V_99 ,
V_95 ,
sizeof( union V_100 ) ,
& V_89 -> V_59 ) ) {
F_8 ( V_2 , L_16 ) ;
goto V_101;
}
F_44 ( V_2 ,
F_32 ,
V_89 ,
& V_89 -> V_102 ,
& V_89 -> V_91 ) ;
return V_89 ;
V_101:
F_45 ( V_2 , V_89 ) ;
return NULL ;
}
void F_46 ( struct V_1 * V_2 ,
struct V_88 * V_89 )
{
F_47 ( & V_89 -> V_59 ) ;
}
void F_45 ( struct V_1 * V_2 ,
struct V_88 * V_89 )
{
if ( ! V_89 )
return;
F_48 ( V_2 -> V_97 , & V_89 -> V_59 ) ;
F_49 ( V_89 ) ;
}
static int F_50 (
struct V_1 * V_2 ,
struct V_103 * V_104 ,
enum V_105 V_106 )
{
return F_39 ( V_2 , V_104 -> V_66 , 0 , NULL ) ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_103 * V_104 )
{
int V_15 ;
V_15 = F_50 ( V_2 , V_104 , V_107 ) ;
if ( V_15 )
F_8 ( V_2 ,
L_17 ,
V_104 -> V_108 ) ;
return V_15 ;
}
void F_52 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
struct V_10 * V_109 = NULL ;
T_3 V_110 = 0 ;
unsigned int V_111 = 0 ;
F_53 ( & V_36 -> V_112 ) ;
F_53 ( & V_36 -> V_113 ) ;
F_53 ( & V_36 -> V_114 ) ;
F_53 ( & V_36 -> V_115 ) ;
F_54 ( & V_36 -> V_116 ) ;
V_110 = V_36 -> V_110 + F_55 ( struct V_10 , V_117 ) ;
V_109 = V_36 -> V_109 ;
for ( V_111 = 0 ; V_111 < V_36 -> V_59 . V_118 ; V_111 ++ ) {
F_19 ( V_109 -> V_27 . V_32 , V_110 ) ;
F_56 ( & V_109 -> V_119 , & V_36 -> V_114 ) ;
V_109 ++ ;
V_110 += sizeof( struct V_10 ) ;
}
V_36 -> V_120 = 0 ;
V_36 -> V_121 = 0 ;
V_36 -> V_122 = 0 ;
V_36 -> V_123 = 0 ;
F_57 ( V_36 -> V_124 , V_125 ) ;
V_36 -> V_126 = 0 ;
F_58 ( V_2 , V_55 , & V_36 -> V_29 ) ;
F_12 ( V_2 , V_36 ) ;
F_47 ( & V_36 -> V_59 ) ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = NULL ;
T_3 V_110 = 0 ;
struct V_10 * V_109 = NULL ;
V_36 =
F_42 ( sizeof( struct V_35 ) , V_96 ) ;
if ( ! V_36 ) {
F_8 ( V_2 , L_18 ) ;
return - V_127 ;
}
if ( F_43 ( V_2 -> V_97 ,
V_98 ,
V_128 ,
0 ,
sizeof( struct V_67 ) ,
& V_36 -> V_59 ) ) {
F_8 ( V_2 , L_19 ) ;
goto V_129;
}
V_109 = F_60 ( & V_2 -> V_97 -> V_130 -> V_131 ,
V_36 -> V_59 . V_118 *
sizeof( struct V_10 ) ,
& V_110 ,
V_96 ) ;
if ( ! V_109 )
goto V_129;
V_36 -> V_109 = V_109 ;
V_36 -> V_110 = V_110 ;
V_2 -> V_36 = V_36 ;
return 0 ;
V_129:
F_48 ( V_2 -> V_97 , & V_36 -> V_59 ) ;
F_49 ( V_36 ) ;
return - V_127 ;
}
void F_61 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
if ( ! V_36 )
return;
if ( V_36 -> V_109 )
F_62 ( & V_2 -> V_97 -> V_130 -> V_131 ,
V_36 -> V_59 . V_118 *
sizeof( struct V_10 ) ,
V_36 -> V_109 ,
V_36 -> V_110 ) ;
F_48 ( V_2 -> V_97 , & V_36 -> V_59 ) ;
;
F_49 ( V_36 ) ;
}
int
F_63 ( struct V_1 * V_2 ,
struct V_10 * * V_132 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
struct V_10 * V_11 = NULL ;
int V_15 = 0 ;
F_64 ( & V_36 -> V_116 ) ;
if ( F_65 ( & V_36 -> V_114 ) ) {
V_11 = F_42 ( sizeof( * V_11 ) , V_133 ) ;
if ( ! V_11 ) {
V_15 = - V_127 ;
goto V_134;
}
V_11 -> V_135 = & V_36 -> V_115 ;
} else {
V_11 = F_66 ( & V_36 -> V_114 ,
struct V_10 ,
V_119 ) ;
F_67 ( & V_11 -> V_119 ) ;
V_11 -> V_135 = & V_36 -> V_112 ;
}
* V_132 = V_11 ;
V_134:
F_68 ( & V_36 -> V_116 ) ;
return V_15 ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_56 ( & V_11 -> V_119 , & V_2 -> V_36 -> V_114 ) ;
}
void F_70 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_64 ( & V_2 -> V_36 -> V_116 ) ;
F_69 ( V_2 , V_11 ) ;
F_68 ( & V_2 -> V_36 -> V_116 ) ;
}
static int
F_71 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
enum V_136 V_137 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
if ( V_11 -> V_135 == & V_36 -> V_115 ) {
if ( F_65 ( & V_36 -> V_114 ) ) {
F_56 ( & V_11 -> V_119 , & V_36 -> V_115 ) ;
V_36 -> V_123 ++ ;
return 0 ;
} else {
struct V_10 * V_138 ;
V_138 = F_66 ( & V_36 -> V_114 ,
struct V_10 ,
V_119 ) ;
F_67 ( & V_138 -> V_119 ) ;
V_11 -> V_27 . V_32 = V_138 -> V_27 . V_32 ;
* V_138 = * V_11 ;
F_49 ( V_11 ) ;
V_11 = V_138 ;
}
}
switch ( V_137 ) {
case V_139 :
F_56 ( & V_11 -> V_119 , & V_36 -> V_112 ) ;
V_36 -> V_120 ++ ;
break;
case V_140 :
F_72 ( & V_11 -> V_119 , & V_36 -> V_112 ) ;
V_36 -> V_141 ++ ;
break;
default:
return - V_25 ;
}
return 0 ;
}
V_81 F_73 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_36 )
return 0xffffffff ;
return V_2 -> V_36 -> V_29 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_142 * V_143 ,
V_81 V_144 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
int V_15 ;
while ( F_75 ( & V_36 -> V_59 ) > V_144 &&
! F_65 ( V_143 ) ) {
struct V_10 * V_11 =
F_66 ( V_143 , struct V_10 , V_119 ) ;
F_67 ( & V_11 -> V_119 ) ;
F_56 ( & V_11 -> V_119 , & V_36 -> V_113 ) ;
V_36 -> V_122 ++ ;
V_15 = F_20 ( V_2 , V_36 , V_11 ) ;
if ( V_15 ) {
F_67 ( & V_11 -> V_119 ) ;
F_69 ( V_2 , V_11 ) ;
return V_15 ;
}
}
return 0 ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
struct V_10 * V_11 = NULL ;
while ( ! F_65 ( & V_36 -> V_114 ) ) {
if ( F_65 ( & V_36 -> V_115 ) )
break;
V_11 = F_66 ( & V_36 -> V_115 ,
struct V_10 ,
V_119 ) ;
if ( ! V_11 )
return - V_25 ;
F_67 ( & V_11 -> V_119 ) ;
F_71 ( V_2 , V_11 , V_11 -> V_137 ) ;
}
return F_74 ( V_2 , & V_36 -> V_112 ,
V_145 ) ;
}
int F_77 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
T_1 * V_6 )
{
int V_15 = 0 ;
struct V_35 * V_36 = V_2 ? V_2 -> V_36 : NULL ;
bool V_146 = true ;
if ( ! V_2 )
return - V_25 ;
if ( ! V_11 ) {
F_8 ( V_2 , L_20 ) ;
return - V_25 ;
}
V_15 = F_9 ( V_2 , V_11 ) ;
F_64 ( & V_36 -> V_116 ) ;
if ( V_15 )
goto V_147;
V_15 = F_71 ( V_2 , V_11 , V_11 -> V_137 ) ;
if ( V_15 )
goto V_147;
V_15 = F_76 ( V_2 ) ;
if ( V_15 ) {
V_146 = false ;
goto V_147;
}
F_68 ( & V_36 -> V_116 ) ;
if ( V_11 -> V_20 == V_21 ) {
V_15 = F_3 ( V_2 , V_11 , V_6 ) ;
if ( V_15 )
goto V_148;
F_70 ( V_2 , V_11 ) ;
}
return V_15 ;
V_148:
F_64 ( & V_36 -> V_116 ) ;
F_67 ( & V_11 -> V_119 ) ;
F_78 ( & V_36 -> V_59 ) ;
V_147:
if ( V_146 )
F_69 ( V_2 , V_11 ) ;
F_68 ( & V_36 -> V_116 ) ;
return V_15 ;
}
int F_39 ( struct V_1 * V_2 ,
T_4 V_66 ,
T_1 V_6 ,
union V_4 * V_149 )
{
struct V_35 * V_36 ;
struct V_10 * V_11 = NULL ;
struct V_10 * V_150 ;
struct V_10 * V_151 = NULL ;
int V_15 ;
if ( ! V_2 )
return - V_25 ;
V_36 = V_2 -> V_36 ;
if ( ! V_36 )
return - V_25 ;
F_64 ( & V_36 -> V_116 ) ;
F_79 (p_ent, tmp, &p_spq->completion_pending,
list) {
if ( V_11 -> V_27 . V_28 . V_66 == V_66 ) {
T_2 V_152 = F_33 ( V_66 ) % V_125 ;
F_67 ( & V_11 -> V_119 ) ;
F_80 ( V_36 -> V_124 , V_152 , V_125 ) ;
while ( F_81 ( V_36 -> V_126 ,
V_36 -> V_124 ) ) {
F_82 ( V_36 -> V_124 ,
V_36 -> V_126 ,
V_125 ) ;
V_36 -> V_126 ++ ;
F_78 ( & V_36 -> V_59 ) ;
}
V_36 -> V_121 ++ ;
V_151 = V_11 ;
break;
}
F_10 ( V_2 , V_26 ,
L_21 ,
F_33 ( V_66 ) ,
F_33 ( V_11 -> V_27 . V_28 . V_66 ) ) ;
}
F_68 ( & V_36 -> V_116 ) ;
if ( ! V_151 ) {
F_8 ( V_2 ,
L_22 ) ;
return - V_153 ;
}
F_10 ( V_2 , V_26 , L_23 ,
V_11 -> V_16 . V_23 , V_11 -> V_16 . V_3 ) ;
if ( V_151 -> V_16 . V_23 )
V_151 -> V_16 . V_23 ( V_2 , V_151 -> V_16 . V_3 , V_149 ,
V_6 ) ;
if ( V_151 -> V_20 != V_21 )
F_70 ( V_2 , V_151 ) ;
F_64 ( & V_36 -> V_116 ) ;
V_15 = F_76 ( V_2 ) ;
F_68 ( & V_36 -> V_116 ) ;
return V_15 ;
}
struct V_154 * F_83 ( struct V_1 * V_2 )
{
struct V_154 * V_63 ;
V_63 = F_42 ( sizeof( * V_63 ) , V_96 ) ;
if ( ! V_63 ) {
F_8 ( V_2 , L_24 ) ;
return NULL ;
}
if ( F_43 ( V_2 -> V_97 ,
V_98 ,
V_99 ,
V_155 / 0x80 ,
0x80 ,
& V_63 -> V_59 ) ) {
F_8 ( V_2 , L_25 ) ;
goto V_156;
}
return V_63 ;
V_156:
F_84 ( V_2 , V_63 ) ;
return NULL ;
}
void F_85 ( struct V_1 * V_2 ,
struct V_154 * V_63 )
{
F_47 ( & V_63 -> V_59 ) ;
}
void F_84 ( struct V_1 * V_2 ,
struct V_154 * V_63 )
{
if ( ! V_63 )
return;
F_48 ( V_2 -> V_97 , & V_63 -> V_59 ) ;
F_49 ( V_63 ) ;
}

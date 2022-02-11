static void F_1 ( struct V_1 * V_2 ,
void * V_3 ,
union V_4 * V_5 , T_1 V_6 )
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
static int F_9 ( struct V_1 * V_2 ,
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
struct V_35 * V_36 , struct V_10 * V_11 )
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
F_27 ( V_2 , V_83 ) ;
return 0 ;
case V_85 :
return F_28 ( V_2 ,
V_83 -> V_86 ,
V_83 -> V_66 , & V_83 -> V_5 ) ;
default:
F_8 ( V_2 ,
L_12 ,
V_83 -> V_31 ) ;
return - V_25 ;
}
}
void F_29 ( struct V_1 * V_2 , T_2 V_87 )
{
V_81 V_88 = V_89 +
F_30 ( V_2 -> V_90 ) ;
F_31 ( V_2 , V_88 , V_87 ) ;
F_32 () ;
}
int F_33 ( struct V_1 * V_2 , void * V_3 )
{
struct V_91 * V_92 = V_3 ;
struct V_64 * V_65 = & V_92 -> V_59 ;
int V_15 = 0 ;
T_2 V_93 = F_34 ( * V_92 -> V_94 ) ;
F_10 ( V_2 , V_26 , L_13 , V_93 ) ;
if ( ( V_93 & F_35 ( V_65 ) ) ==
F_35 ( V_65 ) )
V_93 += F_36 ( V_65 ) ;
while ( V_93 != F_37 ( V_65 ) ) {
struct V_82 * V_83 = F_38 ( V_65 ) ;
if ( ! V_83 ) {
V_15 = - V_25 ;
break;
}
F_10 ( V_2 , V_26 ,
L_14 ,
V_83 -> V_86 ,
V_83 -> V_31 ,
V_83 -> V_95 ,
F_34 ( V_83 -> V_66 ) ,
V_83 -> V_6 ,
V_83 -> V_19 ) ;
if ( F_39 ( V_83 -> V_19 , V_96 ) ) {
if ( F_26 ( V_2 , V_83 ) )
V_15 = - V_25 ;
} else if ( F_40 ( V_2 ,
V_83 -> V_66 ,
V_83 -> V_6 ,
& V_83 -> V_5 ) ) {
V_15 = - V_25 ;
}
F_41 ( V_65 ) ;
}
F_29 ( V_2 , F_21 ( V_65 ) ) ;
return V_15 ;
}
struct V_91 * F_42 ( struct V_1 * V_2 , T_2 V_97 )
{
struct V_91 * V_92 ;
V_92 = F_43 ( sizeof( * V_92 ) , V_98 ) ;
if ( ! V_92 )
return NULL ;
if ( F_44 ( V_2 -> V_99 ,
V_100 ,
V_101 ,
V_102 ,
V_97 ,
sizeof( union V_103 ) ,
& V_92 -> V_59 ) )
goto V_104;
F_45 ( V_2 , F_33 ,
V_92 , & V_92 -> V_105 , & V_92 -> V_94 ) ;
return V_92 ;
V_104:
F_46 ( V_2 , V_92 ) ;
return NULL ;
}
void F_47 ( struct V_1 * V_2 , struct V_91 * V_92 )
{
F_48 ( & V_92 -> V_59 ) ;
}
void F_46 ( struct V_1 * V_2 , struct V_91 * V_92 )
{
if ( ! V_92 )
return;
F_49 ( V_2 -> V_99 , & V_92 -> V_59 ) ;
F_50 ( V_92 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_106 * V_107 ,
enum V_108 V_109 )
{
if ( F_52 ( V_2 -> V_99 ) )
return 0 ;
return F_40 ( V_2 , V_107 -> V_66 , 0 , NULL ) ;
}
int F_53 ( struct V_1 * V_2 ,
struct V_106 * V_107 )
{
int V_15 ;
V_15 = F_51 ( V_2 , V_107 , V_110 ) ;
if ( V_15 )
F_8 ( V_2 ,
L_15 ,
V_107 -> V_111 ) ;
return V_15 ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
struct V_10 * V_112 = NULL ;
T_3 V_113 = 0 ;
V_81 V_114 , V_115 ;
F_55 ( & V_36 -> V_116 ) ;
F_55 ( & V_36 -> V_117 ) ;
F_55 ( & V_36 -> V_118 ) ;
F_55 ( & V_36 -> V_119 ) ;
F_56 ( & V_36 -> V_120 ) ;
V_113 = V_36 -> V_113 + F_57 ( struct V_10 , V_121 ) ;
V_112 = V_36 -> V_112 ;
V_115 = F_58 ( & V_36 -> V_59 ) ;
for ( V_114 = 0 ; V_114 < V_115 ; V_114 ++ ) {
F_19 ( V_112 -> V_27 . V_32 , V_113 ) ;
F_59 ( & V_112 -> V_122 , & V_36 -> V_118 ) ;
V_112 ++ ;
V_113 += sizeof( struct V_10 ) ;
}
V_36 -> V_123 = 0 ;
V_36 -> V_124 = 0 ;
V_36 -> V_125 = 0 ;
V_36 -> V_126 = 0 ;
F_60 ( V_36 -> V_127 , V_128 ) ;
V_36 -> V_129 = 0 ;
F_61 ( V_2 , V_55 , & V_36 -> V_29 ) ;
F_12 ( V_2 , V_36 ) ;
F_48 ( & V_36 -> V_59 ) ;
}
int F_62 ( struct V_1 * V_2 )
{
struct V_10 * V_112 = NULL ;
struct V_35 * V_36 = NULL ;
T_3 V_113 = 0 ;
V_81 V_115 ;
V_36 = F_43 ( sizeof( struct V_35 ) , V_98 ) ;
if ( ! V_36 )
return - V_130 ;
if ( F_44 ( V_2 -> V_99 ,
V_100 ,
V_131 ,
V_102 ,
0 ,
sizeof( struct V_67 ) ,
& V_36 -> V_59 ) )
goto V_132;
V_115 = F_58 ( & V_36 -> V_59 ) ;
V_112 = F_63 ( & V_2 -> V_99 -> V_133 -> V_134 ,
V_115 * sizeof( struct V_10 ) ,
& V_113 , V_98 ) ;
if ( ! V_112 )
goto V_132;
V_36 -> V_112 = V_112 ;
V_36 -> V_113 = V_113 ;
V_2 -> V_36 = V_36 ;
return 0 ;
V_132:
F_49 ( V_2 -> V_99 , & V_36 -> V_59 ) ;
F_50 ( V_36 ) ;
return - V_130 ;
}
void F_64 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
V_81 V_115 ;
if ( ! V_36 )
return;
if ( V_36 -> V_112 ) {
V_115 = F_58 ( & V_36 -> V_59 ) ;
F_65 ( & V_2 -> V_99 -> V_133 -> V_134 ,
V_115 *
sizeof( struct V_10 ) ,
V_36 -> V_112 , V_36 -> V_113 ) ;
}
F_49 ( V_2 -> V_99 , & V_36 -> V_59 ) ;
;
F_50 ( V_36 ) ;
}
int F_66 ( struct V_1 * V_2 , struct V_10 * * V_135 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
struct V_10 * V_11 = NULL ;
int V_15 = 0 ;
F_67 ( & V_36 -> V_120 ) ;
if ( F_68 ( & V_36 -> V_118 ) ) {
V_11 = F_43 ( sizeof( * V_11 ) , V_136 ) ;
if ( ! V_11 ) {
F_8 ( V_2 ,
L_16 ) ;
V_15 = - V_130 ;
goto V_137;
}
V_11 -> V_138 = & V_36 -> V_119 ;
} else {
V_11 = F_69 ( & V_36 -> V_118 ,
struct V_10 , V_122 ) ;
F_70 ( & V_11 -> V_122 ) ;
V_11 -> V_138 = & V_36 -> V_116 ;
}
* V_135 = V_11 ;
V_137:
F_71 ( & V_36 -> V_120 ) ;
return V_15 ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_59 ( & V_11 -> V_122 , & V_2 -> V_36 -> V_118 ) ;
}
void F_73 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
F_67 ( & V_2 -> V_36 -> V_120 ) ;
F_72 ( V_2 , V_11 ) ;
F_71 ( & V_2 -> V_36 -> V_120 ) ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
enum V_139 V_140 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
if ( V_11 -> V_138 == & V_36 -> V_119 ) {
if ( F_68 ( & V_36 -> V_118 ) ) {
F_59 ( & V_11 -> V_122 , & V_36 -> V_119 ) ;
V_36 -> V_126 ++ ;
return 0 ;
} else {
struct V_10 * V_141 ;
V_141 = F_69 ( & V_36 -> V_118 ,
struct V_10 , V_122 ) ;
F_70 ( & V_141 -> V_122 ) ;
V_11 -> V_27 . V_32 = V_141 -> V_27 . V_32 ;
* V_141 = * V_11 ;
if ( V_11 -> V_20 != V_21 )
F_50 ( V_11 ) ;
V_11 = V_141 ;
}
}
switch ( V_140 ) {
case V_142 :
F_59 ( & V_11 -> V_122 , & V_36 -> V_116 ) ;
V_36 -> V_123 ++ ;
break;
case V_143 :
F_75 ( & V_11 -> V_122 , & V_36 -> V_116 ) ;
V_36 -> V_144 ++ ;
break;
default:
return - V_25 ;
}
return 0 ;
}
V_81 F_76 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_36 )
return 0xffffffff ;
return V_2 -> V_36 -> V_29 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_145 * V_146 , V_81 V_147 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
int V_15 ;
while ( F_78 ( & V_36 -> V_59 ) > V_147 &&
! F_68 ( V_146 ) ) {
struct V_10 * V_11 =
F_69 ( V_146 , struct V_10 , V_122 ) ;
F_70 ( & V_11 -> V_122 ) ;
F_59 ( & V_11 -> V_122 , & V_36 -> V_117 ) ;
V_36 -> V_125 ++ ;
V_15 = F_20 ( V_2 , V_36 , V_11 ) ;
if ( V_15 ) {
F_70 ( & V_11 -> V_122 ) ;
F_72 ( V_2 , V_11 ) ;
return V_15 ;
}
}
return 0 ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
struct V_10 * V_11 = NULL ;
while ( ! F_68 ( & V_36 -> V_118 ) ) {
if ( F_68 ( & V_36 -> V_119 ) )
break;
V_11 = F_69 ( & V_36 -> V_119 ,
struct V_10 , V_122 ) ;
if ( ! V_11 )
return - V_25 ;
F_70 ( & V_11 -> V_122 ) ;
F_74 ( V_2 , V_11 , V_11 -> V_140 ) ;
}
return F_77 ( V_2 , & V_36 -> V_116 ,
V_148 ) ;
}
int F_80 ( struct V_1 * V_2 ,
struct V_10 * V_11 , T_1 * V_6 )
{
int V_15 = 0 ;
struct V_35 * V_36 = V_2 ? V_2 -> V_36 : NULL ;
bool V_149 = true ;
if ( ! V_2 )
return - V_25 ;
if ( ! V_11 ) {
F_8 ( V_2 , L_17 ) ;
return - V_25 ;
}
V_15 = F_9 ( V_2 , V_11 ) ;
F_67 ( & V_36 -> V_120 ) ;
if ( V_15 )
goto V_150;
V_15 = F_74 ( V_2 , V_11 , V_11 -> V_140 ) ;
if ( V_15 )
goto V_150;
V_15 = F_79 ( V_2 ) ;
if ( V_15 ) {
V_149 = false ;
goto V_150;
}
F_71 ( & V_36 -> V_120 ) ;
if ( V_11 -> V_20 == V_21 ) {
V_15 = F_3 ( V_2 , V_11 , V_6 ) ;
if ( V_11 -> V_138 == & V_36 -> V_119 ) {
F_50 ( V_11 ) ;
return V_15 ;
}
if ( V_15 )
goto V_151;
F_73 ( V_2 , V_11 ) ;
}
return V_15 ;
V_151:
F_67 ( & V_36 -> V_120 ) ;
F_70 ( & V_11 -> V_122 ) ;
F_81 ( & V_36 -> V_59 ) ;
V_150:
if ( V_149 )
F_72 ( V_2 , V_11 ) ;
F_71 ( & V_36 -> V_120 ) ;
return V_15 ;
}
int F_40 ( struct V_1 * V_2 ,
T_4 V_66 ,
T_1 V_6 ,
union V_4 * V_152 )
{
struct V_35 * V_36 ;
struct V_10 * V_11 = NULL ;
struct V_10 * V_153 ;
struct V_10 * V_154 = NULL ;
int V_15 ;
if ( ! V_2 )
return - V_25 ;
V_36 = V_2 -> V_36 ;
if ( ! V_36 )
return - V_25 ;
F_67 ( & V_36 -> V_120 ) ;
F_82 (p_ent, tmp, &p_spq->completion_pending, list) {
if ( V_11 -> V_27 . V_28 . V_66 == V_66 ) {
T_2 V_155 = F_34 ( V_66 ) % V_128 ;
F_70 ( & V_11 -> V_122 ) ;
F_83 ( V_155 , V_36 -> V_127 ) ;
while ( F_84 ( V_36 -> V_129 ,
V_36 -> V_127 ) ) {
F_85 ( V_36 -> V_129 ,
V_36 -> V_127 ) ;
V_36 -> V_129 ++ ;
F_81 ( & V_36 -> V_59 ) ;
}
V_36 -> V_124 ++ ;
V_154 = V_11 ;
break;
}
F_10 ( V_2 , V_26 ,
L_18 ,
F_34 ( V_66 ) ,
F_34 ( V_11 -> V_27 . V_28 . V_66 ) ) ;
}
F_71 ( & V_36 -> V_120 ) ;
if ( ! V_154 ) {
F_8 ( V_2 ,
L_19 ,
F_34 ( V_66 ) ) ;
return - V_156 ;
}
F_10 ( V_2 , V_26 ,
L_20 ,
F_34 ( V_66 ) ,
V_11 -> V_16 . V_23 , V_11 -> V_16 . V_3 ) ;
if ( V_154 -> V_16 . V_23 )
V_154 -> V_16 . V_23 ( V_2 , V_154 -> V_16 . V_3 , V_152 ,
V_6 ) ;
else
F_10 ( V_2 ,
V_26 ,
L_21 ) ;
if ( ( V_154 -> V_20 != V_21 ) ||
( V_154 -> V_138 == & V_36 -> V_119 ) )
F_73 ( V_2 , V_154 ) ;
F_67 ( & V_36 -> V_120 ) ;
V_15 = F_79 ( V_2 ) ;
F_71 ( & V_36 -> V_120 ) ;
return V_15 ;
}
struct V_157 * F_86 ( struct V_1 * V_2 )
{
struct V_157 * V_63 ;
V_63 = F_43 ( sizeof( * V_63 ) , V_98 ) ;
if ( ! V_63 )
return NULL ;
if ( F_44 ( V_2 -> V_99 ,
V_100 ,
V_101 ,
V_102 ,
V_158 / 0x80 ,
0x80 , & V_63 -> V_59 ) )
goto V_159;
return V_63 ;
V_159:
F_87 ( V_2 , V_63 ) ;
return NULL ;
}
void F_88 ( struct V_1 * V_2 , struct V_157 * V_63 )
{
F_48 ( & V_63 -> V_59 ) ;
}
void F_87 ( struct V_1 * V_2 , struct V_157 * V_63 )
{
if ( ! V_63 )
return;
F_49 ( V_2 -> V_99 , & V_63 -> V_59 ) ;
F_50 ( V_63 ) ;
}

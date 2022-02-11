void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
F_2 ( & V_2 -> V_8 ) ;
for ( V_7 = 0 ; V_7 < F_3 ( V_2 -> V_9 ) ; V_7 ++ ) {
V_4 = F_4 ( V_2 -> V_9 [ V_7 ] ,
F_5 ( & V_2 -> V_8 ) ) ;
if ( ! V_4 || F_6 ( V_4 ) || ! V_4 -> V_10 )
continue;
V_6 = F_7 ( V_4 ) ;
F_8 ( V_6 -> V_11 , V_4 -> V_12 ,
V_13 ,
V_14 ,
V_15 ) ;
}
}
int F_9 ( struct V_1 * V_2 , struct V_16 * V_11 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_17 = 0 ;
int V_7 ;
F_2 ( & V_2 -> V_8 ) ;
for ( V_7 = 0 ; V_7 < F_3 ( V_2 -> V_9 ) ; V_7 ++ ) {
V_4 = F_4 ( V_2 -> V_9 [ V_7 ] ,
F_5 ( & V_2 -> V_8 ) ) ;
if ( ! V_4 || F_6 ( V_4 ) || ! V_4 -> V_10 )
continue;
if ( V_11 ) {
V_6 = F_7 ( V_4 ) ;
if ( V_6 -> V_11 != V_11 )
continue;
}
V_17 ++ ;
}
return V_17 ;
}
static void F_10 ( struct V_1 * V_2 , struct V_16 * V_11 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 ;
struct V_22 V_23 = {} ;
struct V_24 V_25 = {
. V_26 = V_27 ,
. V_28 = V_29 ,
. V_30 = { & V_23 , } ,
. V_31 = { sizeof( struct V_22 ) , } ,
} ;
struct V_3 * V_4 ;
int V_32 , V_7 , V_33 ;
struct V_34 * V_35 = F_11 ( V_11 ) ;
F_2 ( & V_2 -> V_8 ) ;
V_23 . V_36 =
F_12 ( F_13 ( V_35 -> V_26 , V_35 -> V_37 ) ) ;
V_23 . V_38 = V_39 ;
V_23 . V_40 = F_14 ( 0 ) ;
V_33 = 0 ;
for ( V_7 = 0 ; V_7 < F_3 ( V_2 -> V_9 ) ; V_7 ++ ) {
V_4 = F_4 ( V_2 -> V_9 [ V_7 ] ,
F_5 ( & V_2 -> V_8 ) ) ;
if ( F_15 ( V_4 ) || ! V_4 -> V_10 )
continue;
V_23 . V_41 [ V_33 ] . V_42 = V_7 ;
V_23 . V_41 [ V_33 ] . V_43 =
V_39 ;
V_23 . V_41 [ V_33 ] . V_44 = F_14 ( 0 ) ;
V_23 . V_41 [ V_33 ] . V_45 =
F_12 ( V_4 -> V_46 ? 1 : 0 ) ;
V_33 ++ ;
}
V_23 . V_47 = V_33 ;
F_16 ( V_2 , L_1 , V_33 ) ;
V_32 = F_17 ( V_2 , & V_25 ) ;
if ( F_18 ( V_32 ) )
return;
V_19 = V_25 . V_48 ;
F_18 ( F_19 ( V_19 ) != sizeof( * V_21 ) ) ;
F_20 ( & V_25 ) ;
}
void F_21 ( struct V_1 * V_2 , struct V_16 * V_11 ,
bool V_49 )
{
int V_50 = F_9 ( V_2 , V_11 ) ;
if ( V_50 == 1 && V_49 )
F_22 ( V_2 ) ;
F_10 ( V_2 , V_11 ) ;
if ( V_50 == 0 && ! V_49 )
F_22 ( V_2 ) ;
}
void F_23 ( struct V_51 * V_52 ,
struct V_16 * V_11 )
{
struct V_1 * V_2 = F_24 ( V_52 ) ;
T_1 V_53 = 2 * V_11 -> V_54 . V_55 * V_11 -> V_54 . V_56 ;
if ( F_25 ( V_2 , V_57 ) )
return;
F_26 ( & V_2 -> V_8 ) ;
F_27 ( V_2 , V_11 , V_53 , V_53 , 100 , true ) ;
F_28 ( & V_2 -> V_8 ) ;
F_29 ( V_2 , V_57 ) ;
}
static const char *
F_30 ( enum V_58 V_59 )
{
switch ( V_59 ) {
case V_60 :
return L_2 ;
case V_61 :
return L_3 ;
case V_62 :
return L_4 ;
case V_63 :
return L_5 ;
case V_64 :
return L_6 ;
}
return NULL ;
}
static void F_31 ( struct V_1 * V_2 ,
enum V_58 V_59 )
{
if ( V_2 -> V_65 . V_59 == V_59 )
return;
F_16 ( V_2 , L_7 ,
F_30 ( V_2 -> V_65 . V_59 ) ,
F_30 ( V_59 ) ) ;
V_2 -> V_65 . V_59 = V_59 ;
if ( V_59 == V_61 )
V_2 -> V_65 . V_66 . V_67 =
F_32 ( V_2 -> V_68 , V_69 ) ;
if ( V_59 == V_60 )
V_2 -> V_65 . V_70 = V_71 ;
}
void F_33 ( struct V_1 * V_2 , struct V_72 * V_73 )
{
struct V_18 * V_19 = F_34 ( V_73 ) ;
struct V_74 * V_75 = ( void * ) V_19 -> V_30 ;
struct V_3 * V_4 ;
unsigned int V_76 ;
struct V_5 * V_6 ;
struct V_16 * V_11 ;
T_1 V_42 = F_35 ( V_75 -> V_42 ) ;
F_2 ( & V_2 -> V_8 ) ;
if ( ! F_35 ( V_75 -> V_77 ) ) {
F_31 ( V_2 , V_60 ) ;
return;
}
if ( F_36 ( V_42 >= V_78 ) )
return;
V_4 = F_4 ( V_2 -> V_9 [ V_42 ] ,
F_5 ( & V_2 -> V_8 ) ) ;
if ( F_15 ( V_4 ) || F_36 ( ! V_4 -> V_10 ) )
return;
V_6 = F_7 ( V_4 ) ;
V_11 = V_6 -> V_11 ;
V_76 = F_37 ( V_11 -> V_54 . V_55 * V_11 -> V_54 . V_56 ) ;
F_38 ( V_79 , & V_2 -> V_65 . V_80 ,
F_39 ( V_76 ) ) ;
F_31 ( V_2 , V_64 ) ;
}
static int
F_40 ( struct V_1 * V_2 ,
enum V_81 type ,
const T_2 * V_66 , bool V_82 , T_1 V_83 )
{
bool V_84 = false ;
int V_32 = 0 ;
if ( V_2 -> V_65 . V_59 != V_60 &&
V_2 -> V_65 . V_70 != V_71 ) {
struct V_3 * V_4 = F_4 (
V_2 -> V_9 [ V_2 -> V_65 . V_70 ] ,
F_5 ( & V_2 -> V_8 ) ) ;
if ( ! F_15 ( V_4 ) )
V_84 = F_41 ( V_66 , V_4 -> V_12 ) ;
}
switch ( V_2 -> V_65 . V_59 ) {
case V_60 :
if ( type == V_85 )
V_32 = - V_86 ;
break;
case V_61 :
if ( ! V_84 )
V_32 = - V_87 ;
else if ( type == V_88 &&
! V_82 )
V_32 = - V_87 ;
else if ( type == V_89 )
V_32 = - V_87 ;
else if ( V_83 <= V_2 -> V_65 . V_66 . V_67 )
V_32 = - V_86 ;
break;
case V_62 :
V_32 = - V_87 ;
break;
case V_63 :
if ( type == V_89 ) {
if ( ! V_84 )
V_32 = - V_87 ;
else if ( V_82 )
V_32 = - V_87 ;
} else if ( type == V_85 ) {
V_32 = - V_86 ;
}
break;
case V_64 :
if ( type != V_85 || ! V_84 )
V_32 = - V_87 ;
break;
}
if ( V_32 )
F_16 ( V_2 ,
L_8 ,
type , V_2 -> V_65 . V_59 , V_66 , V_84 ,
V_82 ) ;
return V_32 ;
}
static int
F_42 ( struct V_1 * V_2 ,
struct V_16 * V_11 ,
enum V_81 type ,
const T_2 * V_66 , bool V_82 ,
T_2 V_90 ,
struct V_91 * V_92 ,
T_1 V_83 , T_3 V_93 ,
T_3 V_94 , struct V_95 * V_96 ,
T_1 V_97 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_102 V_25 = { 0 } ;
int V_32 ;
F_2 ( & V_2 -> V_8 ) ;
V_32 = F_40 ( V_2 , type , V_66 , V_82 ,
V_83 ) ;
if ( V_32 )
return V_32 ;
if ( ! V_96 || F_36 ( V_96 -> V_31 > V_103 ) ) {
V_32 = - V_86 ;
goto V_104;
}
V_25 . V_105 = type ;
V_25 . V_106 . V_107 = F_12 ( V_83 ) ;
V_25 . V_106 . V_93 = F_12 ( V_93 ) ;
V_25 . V_106 . V_94 = F_12 ( V_94 ) ;
F_43 () ;
V_4 = F_44 ( V_11 , V_66 ) ;
if ( ! V_4 ) {
F_45 () ;
V_32 = - V_108 ;
goto V_104;
}
V_6 = F_7 ( V_4 ) ;
V_25 . V_109 = F_12 ( V_6 -> V_42 ) ;
if ( ! V_92 ) {
if ( V_2 -> V_65 . V_59 == V_61 &&
V_2 -> V_65 . V_66 . V_92 . V_110 ) {
V_92 = & V_2 -> V_65 . V_66 . V_92 ;
} else if ( V_2 -> V_65 . V_59 == V_64 &&
type == V_85 ) {
struct V_111 * V_112 =
F_46 ( V_11 -> V_113 ) ;
if ( F_18 ( ! V_112 ) ) {
F_45 () ;
goto V_104;
}
V_92 = & V_112 -> V_114 ;
}
}
if ( V_92 ) {
V_25 . V_115 . V_116 = ( V_92 -> V_110 -> V_116 == V_117 ?
V_118 : V_119 ) ;
V_25 . V_115 . V_120 = V_92 -> V_110 -> V_121 ;
V_25 . V_115 . V_122 = F_47 ( V_92 ) ;
V_25 . V_115 . V_123 = F_48 ( V_92 ) ;
}
V_25 . V_106 . V_124 =
F_12 ( F_49 ( V_11 -> V_54 . V_55 *
V_11 -> V_54 . V_56 ) / 2 ) ;
V_25 . V_125 . V_126 = F_12 ( V_97 + 2 ) ;
V_99 = F_50 ( V_96 ) ;
V_101 = ( void * ) V_96 -> V_30 ;
if ( V_99 -> V_127 . V_128 ) {
if ( V_99 -> V_127 . V_128 -> V_129 != V_130 ) {
F_45 () ;
V_32 = - V_86 ;
goto V_104;
}
F_51 ( V_99 , & V_25 . V_125 . V_131 ) ;
}
F_52 ( V_2 , V_96 , & V_25 . V_125 . V_131 , V_99 ,
V_6 -> V_42 ) ;
F_53 ( V_2 , & V_25 . V_125 . V_131 , V_99 , V_4 ,
V_101 -> V_132 ) ;
F_45 () ;
memcpy ( V_25 . V_125 . V_30 , V_96 -> V_30 , V_96 -> V_31 ) ;
V_32 = F_54 ( V_2 , V_133 , 0 ,
sizeof( V_25 ) , & V_25 ) ;
if ( V_32 ) {
F_55 ( V_2 , L_9 ,
V_32 ) ;
goto V_104;
}
if ( type != V_85 ) {
V_2 -> V_65 . V_70 = V_6 -> V_42 ;
F_31 ( V_2 ,
type == V_89 ?
V_61 :
V_63 ) ;
} else {
F_31 ( V_2 , V_62 ) ;
}
V_104:
if ( V_32 )
F_31 ( V_2 , V_60 ) ;
return V_32 ;
}
void F_56 ( struct V_134 * V_135 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_16 * V_11 ;
unsigned int V_76 ;
int V_32 ;
V_2 = F_57 ( V_135 , struct V_1 , V_65 . V_80 . V_135 ) ;
F_26 ( & V_2 -> V_8 ) ;
F_31 ( V_2 , V_60 ) ;
if ( V_2 -> V_65 . V_66 . V_42 == V_71 )
goto V_104;
V_4 = F_4 (
V_2 -> V_9 [ V_2 -> V_65 . V_66 . V_42 ] ,
F_5 ( & V_2 -> V_8 ) ) ;
if ( ! V_4 || F_6 ( V_4 ) || F_36 ( ! V_4 -> V_10 ) )
goto V_104;
V_6 = F_7 ( V_4 ) ;
V_11 = V_6 -> V_11 ;
V_32 = F_42 ( V_2 , V_11 ,
V_89 ,
V_4 -> V_12 ,
V_2 -> V_65 . V_66 . V_136 ,
V_2 -> V_65 . V_66 . V_137 ,
& V_2 -> V_65 . V_66 . V_92 ,
0 , 0 , 0 ,
V_2 -> V_65 . V_66 . V_96 ,
V_2 -> V_65 . V_66 . V_97 ) ;
if ( V_32 )
F_55 ( V_2 , L_10 , V_32 ) ;
V_76 = F_37 ( V_11 -> V_54 . V_55 * V_11 -> V_54 . V_56 ) ;
F_58 ( V_79 , & V_2 -> V_65 . V_80 ,
F_39 ( V_76 ) ) ;
V_104:
F_28 ( & V_2 -> V_8 ) ;
}
int
F_59 ( struct V_51 * V_52 ,
struct V_16 * V_11 ,
struct V_3 * V_4 , T_2 V_90 ,
struct V_91 * V_92 ,
struct V_95 * V_138 , T_1 V_97 )
{
struct V_1 * V_2 = F_24 ( V_52 ) ;
struct V_5 * V_6 ;
unsigned int V_76 ;
int V_32 ;
F_26 ( & V_2 -> V_8 ) ;
F_16 ( V_2 , L_11 ,
V_4 -> V_12 , V_92 -> V_110 -> V_139 , V_92 -> V_122 ) ;
if ( V_2 -> V_65 . V_66 . V_42 != V_71 ) {
F_16 ( V_2 ,
L_12 ,
V_4 -> V_12 ) ;
V_32 = - V_87 ;
goto V_104;
}
V_32 = F_42 ( V_2 , V_11 ,
V_89 ,
V_4 -> V_12 , V_4 -> V_46 ,
V_90 , V_92 , 0 , 0 , 0 ,
V_138 , V_97 ) ;
if ( V_32 )
goto V_104;
V_2 -> V_65 . V_66 . V_96 = F_60 ( V_138 , V_15 ) ;
if ( ! V_2 -> V_65 . V_66 . V_96 ) {
V_32 = - V_140 ;
goto V_104;
}
V_6 = F_7 ( V_4 ) ;
V_2 -> V_65 . V_66 . V_42 = V_6 -> V_42 ;
V_2 -> V_65 . V_66 . V_92 = * V_92 ;
V_2 -> V_65 . V_66 . V_136 = V_4 -> V_46 ;
V_2 -> V_65 . V_66 . V_137 = V_90 ;
V_2 -> V_65 . V_66 . V_97 = V_97 ;
V_76 = 2 * F_37 ( V_11 -> V_54 . V_55 *
V_11 -> V_54 . V_56 ) ;
F_38 ( V_79 , & V_2 -> V_65 . V_80 ,
F_39 ( V_76 ) ) ;
V_104:
F_28 ( & V_2 -> V_8 ) ;
return V_32 ;
}
void F_61 ( struct V_51 * V_52 ,
struct V_16 * V_11 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = F_24 ( V_52 ) ;
struct V_3 * V_141 ;
bool V_142 = false ;
F_26 ( & V_2 -> V_8 ) ;
F_16 ( V_2 , L_13 , V_4 -> V_12 ) ;
if ( V_2 -> V_65 . V_66 . V_42 == V_71 ) {
F_16 ( V_2 , L_14 , V_4 -> V_12 ) ;
goto V_104;
}
V_141 = F_4 (
V_2 -> V_9 [ V_2 -> V_65 . V_66 . V_42 ] ,
F_5 ( & V_2 -> V_8 ) ) ;
if ( V_141 != V_4 )
goto V_104;
if ( V_2 -> V_65 . V_70 == V_2 -> V_65 . V_66 . V_42 &&
V_2 -> V_65 . V_59 != V_60 )
V_142 = true ;
V_2 -> V_65 . V_66 . V_42 = V_71 ;
F_62 ( V_2 -> V_65 . V_66 . V_96 ) ;
V_2 -> V_65 . V_66 . V_96 = NULL ;
V_104:
F_28 ( & V_2 -> V_8 ) ;
if ( V_142 )
F_63 ( F_37 ( V_11 -> V_54 . V_55 *
V_11 -> V_54 . V_56 ) ) ;
F_64 ( & V_2 -> V_65 . V_80 ) ;
F_16 ( V_2 , L_15 , V_4 -> V_12 ) ;
}
void
F_65 ( struct V_51 * V_52 ,
struct V_16 * V_11 ,
struct V_143 * V_144 )
{
struct V_1 * V_2 = F_24 ( V_52 ) ;
enum V_81 type ;
unsigned int V_76 ;
const char * V_145 =
V_144 -> V_146 == V_147 ?
L_16 : L_17 ;
F_26 ( & V_2 -> V_8 ) ;
F_16 ( V_2 ,
L_18 ,
V_145 , V_144 -> V_4 -> V_12 , V_144 -> V_77 ) ;
if ( V_144 -> V_146 == V_148 &&
V_144 -> V_77 != 0 &&
V_2 -> V_65 . V_59 == V_61 &&
V_2 -> V_65 . V_70 != V_71 ) {
struct V_3 * V_141 ;
V_141 = F_4 (
V_2 -> V_9 [ V_2 -> V_65 . V_70 ] ,
F_5 ( & V_2 -> V_8 ) ) ;
if ( V_141 == V_144 -> V_4 ) {
F_31 ( V_2 ,
V_60 ) ;
goto V_149;
}
}
type = ( V_144 -> V_146 == V_147 ) ?
V_88 : V_85 ;
F_42 ( V_2 , V_11 , type , V_144 -> V_4 -> V_12 ,
V_144 -> V_4 -> V_46 , 0 ,
V_144 -> V_92 , V_144 -> V_83 ,
V_144 -> V_93 ,
V_144 -> V_94 ,
V_144 -> V_138 ,
V_144 -> V_97 ) ;
V_149:
V_76 = V_11 -> V_54 . V_55 * V_11 -> V_54 . V_56 *
1024 / 1000 ;
F_38 ( V_79 , & V_2 -> V_65 . V_80 ,
F_39 ( V_76 ) ) ;
F_28 ( & V_2 -> V_8 ) ;
}

void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
F_2 ( & V_2 -> V_8 ) ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
V_4 = F_3 ( V_2 -> V_10 [ V_7 ] ,
F_4 ( & V_2 -> V_8 ) ) ;
if ( ! V_4 || F_5 ( V_4 ) || ! V_4 -> V_11 )
continue;
V_6 = F_6 ( V_4 ) ;
F_7 ( V_6 -> V_12 , V_4 -> V_13 ,
V_14 ,
V_15 ,
V_16 ) ;
}
}
int F_8 ( struct V_1 * V_2 , struct V_17 * V_12 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_18 = 0 ;
int V_7 ;
F_2 ( & V_2 -> V_8 ) ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
V_4 = F_3 ( V_2 -> V_10 [ V_7 ] ,
F_4 ( & V_2 -> V_8 ) ) ;
if ( ! V_4 || F_5 ( V_4 ) || ! V_4 -> V_11 )
continue;
if ( V_12 ) {
V_6 = F_6 ( V_4 ) ;
if ( V_6 -> V_12 != V_12 )
continue;
}
V_18 ++ ;
}
return V_18 ;
}
static void F_9 ( struct V_1 * V_2 , struct V_17 * V_12 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_23 V_24 = {} ;
struct V_25 V_26 = {
. V_27 = V_28 ,
. V_29 = V_30 ,
. V_31 = { & V_24 , } ,
. V_32 = { sizeof( struct V_23 ) , } ,
} ;
struct V_3 * V_4 ;
int V_33 , V_7 , V_34 ;
struct V_35 * V_36 = F_10 ( V_12 ) ;
F_2 ( & V_2 -> V_8 ) ;
V_24 . V_37 =
F_11 ( F_12 ( V_36 -> V_27 , V_36 -> V_38 ) ) ;
V_24 . V_39 = V_40 ;
V_24 . V_41 = F_13 ( 0 ) ;
V_34 = 0 ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
V_4 = F_3 ( V_2 -> V_10 [ V_7 ] ,
F_4 ( & V_2 -> V_8 ) ) ;
if ( F_14 ( V_4 ) || ! V_4 -> V_11 )
continue;
V_24 . V_42 [ V_34 ] . V_43 = V_7 ;
V_24 . V_42 [ V_34 ] . V_44 =
V_40 ;
V_24 . V_42 [ V_34 ] . V_45 = F_13 ( 0 ) ;
V_24 . V_42 [ V_34 ] . V_46 =
F_11 ( V_4 -> V_47 ? 1 : 0 ) ;
V_34 ++ ;
}
V_24 . V_48 = V_34 ;
F_15 ( V_2 , L_1 , V_34 ) ;
V_33 = F_16 ( V_2 , & V_26 ) ;
if ( F_17 ( V_33 ) )
return;
V_20 = V_26 . V_49 ;
F_17 ( F_18 ( V_20 ) != sizeof( * V_22 ) ) ;
F_19 ( & V_26 ) ;
}
void F_20 ( struct V_1 * V_2 , struct V_17 * V_12 ,
bool V_50 )
{
int V_51 = F_8 ( V_2 , V_12 ) ;
if ( V_51 == 1 && V_50 )
F_21 ( V_2 ) ;
F_9 ( V_2 , V_12 ) ;
if ( V_51 == 0 && ! V_50 )
F_21 ( V_2 ) ;
}
void F_22 ( struct V_52 * V_53 ,
struct V_17 * V_12 )
{
struct V_1 * V_2 = F_23 ( V_53 ) ;
T_1 V_54 = 2 * V_12 -> V_55 . V_56 * V_12 -> V_55 . V_57 ;
if ( F_24 ( V_2 , V_58 ) )
return;
F_25 ( & V_2 -> V_8 ) ;
F_26 ( V_2 , V_12 , V_54 , V_54 , 100 , true ) ;
F_27 ( & V_2 -> V_8 ) ;
F_28 ( V_2 , V_58 ) ;
}
static const char *
F_29 ( enum V_59 V_60 )
{
switch ( V_60 ) {
case V_61 :
return L_2 ;
case V_62 :
return L_3 ;
case V_63 :
return L_4 ;
case V_64 :
return L_5 ;
case V_65 :
return L_6 ;
}
return NULL ;
}
static void F_30 ( struct V_1 * V_2 ,
enum V_59 V_60 )
{
if ( V_2 -> V_66 . V_60 == V_60 )
return;
F_15 ( V_2 , L_7 ,
F_29 ( V_2 -> V_66 . V_60 ) ,
F_29 ( V_60 ) ) ;
V_2 -> V_66 . V_60 = V_60 ;
if ( V_60 == V_62 )
V_2 -> V_66 . V_67 . V_68 =
F_31 ( V_2 -> V_69 , V_70 ) ;
if ( V_60 == V_61 )
V_2 -> V_66 . V_71 = V_9 ;
}
void F_32 ( struct V_1 * V_2 , struct V_72 * V_73 )
{
struct V_19 * V_20 = F_33 ( V_73 ) ;
struct V_74 * V_75 = ( void * ) V_20 -> V_31 ;
struct V_3 * V_4 ;
unsigned int V_76 ;
struct V_5 * V_6 ;
struct V_17 * V_12 ;
T_1 V_43 = F_34 ( V_75 -> V_43 ) ;
F_2 ( & V_2 -> V_8 ) ;
if ( ! F_34 ( V_75 -> V_77 ) ) {
F_30 ( V_2 , V_61 ) ;
return;
}
if ( F_35 ( V_43 >= V_9 ) )
return;
V_4 = F_3 ( V_2 -> V_10 [ V_43 ] ,
F_4 ( & V_2 -> V_8 ) ) ;
if ( F_14 ( V_4 ) || F_35 ( ! V_4 -> V_11 ) )
return;
V_6 = F_6 ( V_4 ) ;
V_12 = V_6 -> V_12 ;
V_76 = F_36 ( V_12 -> V_55 . V_56 * V_12 -> V_55 . V_57 ) ;
F_37 ( V_78 , & V_2 -> V_66 . V_79 ,
F_38 ( V_76 ) ) ;
F_30 ( V_2 , V_65 ) ;
}
static int
F_39 ( struct V_1 * V_2 ,
enum V_80 type ,
const T_2 * V_67 , bool V_81 , T_1 V_82 )
{
bool V_83 = false ;
int V_33 = 0 ;
if ( V_2 -> V_66 . V_60 != V_61 &&
V_2 -> V_66 . V_71 != V_9 ) {
struct V_3 * V_4 = F_3 (
V_2 -> V_10 [ V_2 -> V_66 . V_71 ] ,
F_4 ( & V_2 -> V_8 ) ) ;
if ( ! F_14 ( V_4 ) )
V_83 = F_40 ( V_67 , V_4 -> V_13 ) ;
}
switch ( V_2 -> V_66 . V_60 ) {
case V_61 :
if ( type == V_84 )
V_33 = - V_85 ;
break;
case V_62 :
if ( ! V_83 )
V_33 = - V_86 ;
else if ( type == V_87 &&
! V_81 )
V_33 = - V_86 ;
else if ( type == V_88 )
V_33 = - V_86 ;
else if ( V_82 <= V_2 -> V_66 . V_67 . V_68 )
V_33 = - V_85 ;
break;
case V_63 :
V_33 = - V_86 ;
break;
case V_64 :
if ( type == V_88 ) {
if ( ! V_83 )
V_33 = - V_86 ;
else if ( V_81 )
V_33 = - V_86 ;
} else if ( type == V_84 ) {
V_33 = - V_85 ;
}
break;
case V_65 :
if ( type != V_84 || ! V_83 )
V_33 = - V_86 ;
break;
}
if ( V_33 )
F_15 ( V_2 ,
L_8 ,
type , V_2 -> V_66 . V_60 , V_67 , V_83 ,
V_81 ) ;
return V_33 ;
}
static int
F_41 ( struct V_1 * V_2 ,
struct V_17 * V_12 ,
enum V_80 type ,
const T_2 * V_67 , bool V_81 ,
T_2 V_89 ,
struct V_90 * V_91 ,
T_1 V_82 , T_3 V_92 ,
T_3 V_93 , struct V_94 * V_95 ,
T_1 V_96 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_97 * V_98 ;
struct V_99 * V_100 ;
struct V_101 V_26 = { 0 } ;
int V_33 ;
F_2 ( & V_2 -> V_8 ) ;
V_33 = F_39 ( V_2 , type , V_67 , V_81 ,
V_82 ) ;
if ( V_33 )
return V_33 ;
if ( ! V_95 || F_35 ( V_95 -> V_32 > V_102 ) ) {
V_33 = - V_85 ;
goto V_103;
}
V_26 . V_104 = type ;
V_26 . V_105 . V_106 = F_11 ( V_82 ) ;
V_26 . V_105 . V_92 = F_11 ( V_92 ) ;
V_26 . V_105 . V_93 = F_11 ( V_93 ) ;
F_42 () ;
V_4 = F_43 ( V_12 , V_67 ) ;
if ( ! V_4 ) {
F_44 () ;
V_33 = - V_107 ;
goto V_103;
}
V_6 = F_6 ( V_4 ) ;
V_26 . V_108 = F_11 ( V_6 -> V_43 ) ;
if ( ! V_91 ) {
if ( V_2 -> V_66 . V_60 == V_62 &&
V_2 -> V_66 . V_67 . V_91 . V_109 ) {
V_91 = & V_2 -> V_66 . V_67 . V_91 ;
} else if ( V_2 -> V_66 . V_60 == V_65 &&
type == V_84 ) {
struct V_110 * V_111 =
F_45 ( V_12 -> V_112 ) ;
if ( F_17 ( ! V_111 ) ) {
F_44 () ;
goto V_103;
}
V_91 = & V_111 -> V_113 ;
}
}
if ( V_91 ) {
V_26 . V_114 . V_115 = ( V_91 -> V_109 -> V_115 == V_116 ?
V_117 : V_118 ) ;
V_26 . V_114 . V_119 = V_91 -> V_109 -> V_120 ;
V_26 . V_114 . V_121 = F_46 ( V_91 ) ;
V_26 . V_114 . V_122 = F_47 ( V_91 ) ;
}
V_26 . V_105 . V_123 =
F_11 ( F_48 ( V_12 -> V_55 . V_56 *
V_12 -> V_55 . V_57 ) / 2 ) ;
V_26 . V_124 . V_125 = F_11 ( V_96 + 2 ) ;
V_98 = F_49 ( V_95 ) ;
V_100 = ( void * ) V_95 -> V_31 ;
if ( V_98 -> V_126 . V_127 ) {
if ( V_98 -> V_126 . V_127 -> V_128 != V_129 ) {
F_44 () ;
V_33 = - V_85 ;
goto V_103;
}
F_50 ( V_98 , & V_26 . V_124 . V_130 ) ;
}
F_51 ( V_2 , V_95 , & V_26 . V_124 . V_130 , V_98 ,
V_6 -> V_43 ) ;
F_52 ( V_2 , & V_26 . V_124 . V_130 , V_98 , V_4 ,
V_100 -> V_131 ) ;
F_44 () ;
memcpy ( V_26 . V_124 . V_31 , V_95 -> V_31 , V_95 -> V_32 ) ;
V_33 = F_53 ( V_2 , V_132 , 0 ,
sizeof( V_26 ) , & V_26 ) ;
if ( V_33 ) {
F_54 ( V_2 , L_9 ,
V_33 ) ;
goto V_103;
}
if ( type != V_84 ) {
V_2 -> V_66 . V_71 = V_6 -> V_43 ;
F_30 ( V_2 ,
type == V_88 ?
V_62 :
V_64 ) ;
} else {
F_30 ( V_2 , V_63 ) ;
}
V_103:
if ( V_33 )
F_30 ( V_2 , V_61 ) ;
return V_33 ;
}
void F_55 ( struct V_133 * V_134 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_17 * V_12 ;
unsigned int V_76 ;
int V_33 ;
V_2 = F_56 ( V_134 , struct V_1 , V_66 . V_79 . V_134 ) ;
F_25 ( & V_2 -> V_8 ) ;
F_30 ( V_2 , V_61 ) ;
if ( V_2 -> V_66 . V_67 . V_43 == V_9 )
goto V_103;
V_4 = F_3 (
V_2 -> V_10 [ V_2 -> V_66 . V_67 . V_43 ] ,
F_4 ( & V_2 -> V_8 ) ) ;
if ( ! V_4 || F_5 ( V_4 ) || F_35 ( ! V_4 -> V_11 ) )
goto V_103;
V_6 = F_6 ( V_4 ) ;
V_12 = V_6 -> V_12 ;
V_33 = F_41 ( V_2 , V_12 ,
V_88 ,
V_4 -> V_13 ,
V_2 -> V_66 . V_67 . V_135 ,
V_2 -> V_66 . V_67 . V_136 ,
& V_2 -> V_66 . V_67 . V_91 ,
0 , 0 , 0 ,
V_2 -> V_66 . V_67 . V_95 ,
V_2 -> V_66 . V_67 . V_96 ) ;
if ( V_33 )
F_54 ( V_2 , L_10 , V_33 ) ;
V_76 = F_36 ( V_12 -> V_55 . V_56 * V_12 -> V_55 . V_57 ) ;
F_57 ( V_78 , & V_2 -> V_66 . V_79 ,
F_38 ( V_76 ) ) ;
V_103:
F_27 ( & V_2 -> V_8 ) ;
}
int
F_58 ( struct V_52 * V_53 ,
struct V_17 * V_12 ,
struct V_3 * V_4 , T_2 V_89 ,
struct V_90 * V_91 ,
struct V_94 * V_137 , T_1 V_96 )
{
struct V_1 * V_2 = F_23 ( V_53 ) ;
struct V_5 * V_6 ;
unsigned int V_76 ;
int V_33 ;
F_25 ( & V_2 -> V_8 ) ;
F_15 ( V_2 , L_11 ,
V_4 -> V_13 , V_91 -> V_109 -> V_138 , V_91 -> V_121 ) ;
if ( V_2 -> V_66 . V_67 . V_43 != V_9 ) {
F_15 ( V_2 ,
L_12 ,
V_4 -> V_13 ) ;
V_33 = - V_86 ;
goto V_103;
}
V_33 = F_41 ( V_2 , V_12 ,
V_88 ,
V_4 -> V_13 , V_4 -> V_47 ,
V_89 , V_91 , 0 , 0 , 0 ,
V_137 , V_96 ) ;
if ( V_33 )
goto V_103;
V_2 -> V_66 . V_67 . V_95 = F_59 ( V_137 , V_16 ) ;
if ( ! V_2 -> V_66 . V_67 . V_95 ) {
V_33 = - V_139 ;
goto V_103;
}
V_6 = F_6 ( V_4 ) ;
V_2 -> V_66 . V_67 . V_43 = V_6 -> V_43 ;
V_2 -> V_66 . V_67 . V_91 = * V_91 ;
V_2 -> V_66 . V_67 . V_135 = V_4 -> V_47 ;
V_2 -> V_66 . V_67 . V_136 = V_89 ;
V_2 -> V_66 . V_67 . V_96 = V_96 ;
V_76 = 2 * F_36 ( V_12 -> V_55 . V_56 *
V_12 -> V_55 . V_57 ) ;
F_37 ( V_78 , & V_2 -> V_66 . V_79 ,
F_38 ( V_76 ) ) ;
V_103:
F_27 ( & V_2 -> V_8 ) ;
return V_33 ;
}
void F_60 ( struct V_52 * V_53 ,
struct V_17 * V_12 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = F_23 ( V_53 ) ;
struct V_3 * V_140 ;
bool V_141 = false ;
F_25 ( & V_2 -> V_8 ) ;
F_15 ( V_2 , L_13 , V_4 -> V_13 ) ;
if ( V_2 -> V_66 . V_67 . V_43 == V_9 ) {
F_15 ( V_2 , L_14 , V_4 -> V_13 ) ;
goto V_103;
}
V_140 = F_3 (
V_2 -> V_10 [ V_2 -> V_66 . V_67 . V_43 ] ,
F_4 ( & V_2 -> V_8 ) ) ;
if ( V_140 != V_4 )
goto V_103;
if ( V_2 -> V_66 . V_71 == V_2 -> V_66 . V_67 . V_43 &&
V_2 -> V_66 . V_60 != V_61 )
V_141 = true ;
V_2 -> V_66 . V_67 . V_43 = V_9 ;
F_61 ( V_2 -> V_66 . V_67 . V_95 ) ;
V_2 -> V_66 . V_67 . V_95 = NULL ;
V_103:
F_27 ( & V_2 -> V_8 ) ;
if ( V_141 )
F_62 ( F_36 ( V_12 -> V_55 . V_56 *
V_12 -> V_55 . V_57 ) ) ;
F_63 ( & V_2 -> V_66 . V_79 ) ;
F_15 ( V_2 , L_15 , V_4 -> V_13 ) ;
}
void
F_64 ( struct V_52 * V_53 ,
struct V_17 * V_12 ,
struct V_142 * V_143 )
{
struct V_1 * V_2 = F_23 ( V_53 ) ;
enum V_80 type ;
unsigned int V_76 ;
const char * V_144 =
V_143 -> V_145 == V_146 ?
L_16 : L_17 ;
F_25 ( & V_2 -> V_8 ) ;
F_15 ( V_2 ,
L_18 ,
V_144 , V_143 -> V_4 -> V_13 , V_143 -> V_77 ) ;
if ( V_143 -> V_145 == V_147 &&
V_143 -> V_77 != 0 &&
V_2 -> V_66 . V_60 == V_62 &&
V_2 -> V_66 . V_71 != V_9 ) {
struct V_3 * V_140 ;
V_140 = F_3 (
V_2 -> V_10 [ V_2 -> V_66 . V_71 ] ,
F_4 ( & V_2 -> V_8 ) ) ;
if ( V_140 == V_143 -> V_4 ) {
F_30 ( V_2 ,
V_61 ) ;
goto V_148;
}
}
type = ( V_143 -> V_145 == V_146 ) ?
V_87 : V_84 ;
F_41 ( V_2 , V_12 , type , V_143 -> V_4 -> V_13 ,
V_143 -> V_4 -> V_47 , 0 ,
V_143 -> V_91 , V_143 -> V_82 ,
V_143 -> V_92 ,
V_143 -> V_93 ,
V_143 -> V_137 ,
V_143 -> V_96 ) ;
V_148:
V_76 = V_12 -> V_55 . V_56 * V_12 -> V_55 . V_57 *
1024 / 1000 ;
F_37 ( V_78 , & V_2 -> V_66 . V_79 ,
F_38 ( V_76 ) ) ;
F_27 ( & V_2 -> V_8 ) ;
}

static bool F_1 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
bool V_5 = false ;
int V_6 , V_7 ;
switch ( V_2 -> V_8 -> V_9 ) {
case V_10 :
V_5 = true ;
break;
case V_11 :
break;
case V_12 :
V_7 = V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_15 , & V_4 ) ;
if ( V_7 == 0 && V_4 . V_16 )
V_5 = true ;
break;
case V_17 :
for ( V_6 = 0 ; V_2 -> V_18 [ V_6 ] ; V_6 ++ ) {
V_7 = V_2 -> V_18 [ V_6 ] -> V_14 (
V_2 -> V_18 [ V_6 ] ,
V_15 , & V_4 ) ;
if ( V_7 == 0 && V_4 . V_16 ) {
V_5 = true ;
break;
}
}
break;
}
return V_5 ;
}
static bool F_2 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
bool V_19 = false ;
int V_6 , V_7 ;
for ( V_6 = 0 ; V_2 -> V_18 [ V_6 ] ; V_6 ++ ) {
V_7 = V_2 -> V_18 [ V_6 ] -> V_14 (
V_2 -> V_18 [ V_6 ] ,
V_20 , & V_4 ) ;
if ( V_7 == 0 && V_4 . V_16 ) {
V_19 = true ;
break;
}
}
return V_19 ;
}
static int F_3 ( struct V_1 * V_2 , int * V_21 )
{
union V_3 V_4 ;
int V_7 ;
if ( ! V_2 -> V_13 )
return - V_22 ;
V_7 = V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_23 , & V_4 ) ;
if ( V_7 )
return V_7 ;
* V_21 = V_4 . V_16 ;
return 0 ;
}
static bool F_4 ( struct V_1 * V_2 )
{
int V_6 , V_7 ;
bool V_24 = false ;
union V_3 V_4 ;
if ( ! F_1 ( V_2 ) )
return false ;
for ( V_6 = 0 ; V_2 -> V_18 [ V_6 ] ; V_6 ++ ) {
if ( V_2 -> V_25 )
continue;
if ( ! V_2 -> V_26 )
continue;
V_7 = V_2 -> V_18 [ V_6 ] -> V_14 (
V_2 -> V_18 [ V_6 ] ,
V_20 , & V_4 ) ;
if ( V_7 ) {
F_5 ( V_2 -> V_27 , L_1 ,
V_2 -> V_8 -> V_28 [ V_6 ] ) ;
continue;
}
if ( V_4 . V_16 == 0 )
continue;
V_7 = V_2 -> V_18 [ V_6 ] -> V_14 (
V_2 -> V_18 [ V_6 ] ,
V_29 , & V_4 ) ;
if ( V_7 ) {
F_5 ( V_2 -> V_27 , L_2 ,
V_2 -> V_8 -> V_28 [ V_6 ] ) ;
continue;
}
if ( V_4 . V_16 == V_30 ||
V_4 . V_16 == V_31 ||
V_4 . V_16 == V_32 )
continue;
V_24 = true ;
break;
}
return V_24 ;
}
static bool F_6 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 -> V_33 ) {
case V_34 :
return false ;
case V_35 :
return true ;
case V_36 :
return F_2 ( V_2 ) ;
case V_37 :
return F_4 ( V_2 ) ;
default:
F_5 ( V_2 -> V_27 , L_3 ,
V_2 -> V_8 -> V_33 ) ;
}
return false ;
}
static int F_7 ( struct V_1 * V_2 , bool V_38 )
{
int V_39 = 0 , V_6 ;
struct V_40 * V_8 = V_2 -> V_8 ;
if ( V_38 == V_2 -> V_26 )
return 0 ;
if ( V_38 ) {
if ( V_2 -> V_25 )
return - V_41 ;
for ( V_6 = 0 ; V_6 < V_8 -> V_42 ; V_6 ++ )
F_8 ( V_8 -> V_43 [ V_6 ] . V_44 ) ;
} else {
for ( V_6 = 0 ; V_6 < V_8 -> V_42 ; V_6 ++ ) {
if ( F_9 (
V_8 -> V_43 [ V_6 ] . V_44 ) ) {
F_10 (
V_8 -> V_43 [ V_6 ] . V_44 ) ;
F_5 ( V_2 -> V_27 ,
L_4 ,
V_8 -> V_43 [ V_6 ] . V_45 ) ;
}
}
}
if ( ! V_39 )
V_2 -> V_26 = V_38 ;
return V_39 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_39 ;
if ( V_2 -> V_25 )
return - V_41 ;
V_39 = F_7 ( V_2 , false ) ;
if ( V_39 )
return V_39 ;
return F_7 ( V_2 , true ) ;
}
static void F_12 ( struct V_1 * V_2 , const char * V_46 )
{
static char V_47 [ V_48 + 1 ] = L_5 ;
static char V_49 [ V_48 + 1 ] = L_5 ;
if ( V_50 ) {
if ( V_49 [ 0 ] == 0 ) {
if ( ! strncmp ( V_47 , V_46 , V_48 ) )
return;
strncpy ( V_49 , V_46 , V_48 ) ;
return;
}
if ( ! strncmp ( V_49 , V_46 , V_48 ) )
return;
strncpy ( V_49 , V_46 , V_48 ) ;
return;
}
if ( V_46 == NULL ) {
if ( ! V_49 [ 0 ] )
return;
strncpy ( V_47 , V_49 , V_48 ) ;
F_13 ( & V_2 -> V_27 -> V_51 , V_52 ) ;
V_49 [ 0 ] = 0 ;
return;
}
if ( ! strncmp ( V_47 , V_46 , V_48 ) )
return;
strncpy ( V_47 , V_46 , V_48 ) ;
F_13 ( & V_2 -> V_27 -> V_51 , V_52 ) ;
F_14 ( V_2 -> V_27 , V_46 ) ;
}
static void F_15 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_16 ( V_54 ) ;
struct V_1 * V_2 = F_17 ( V_56 ,
struct V_1 , V_57 ) ;
struct V_40 * V_8 = V_2 -> V_8 ;
int V_58 , V_39 , V_59 ;
V_2 -> V_60 = 0 ;
if ( ! V_8 -> V_61 || ! V_8 -> V_62 )
return;
V_39 = F_3 ( V_2 , & V_58 ) ;
if ( V_39 ) {
F_18 ( V_2 -> V_27 , L_6 , V_63 , V_39 ) ;
return;
}
V_59 = V_2 -> V_64 ;
V_59 -= V_58 ;
F_19 ( V_2 -> V_27 , L_7 , V_59 ) ;
if ( V_59 > V_8 -> V_61 ) {
F_11 ( V_2 ) ;
F_12 ( V_2 , L_8 ) ;
}
}
static bool F_20 ( struct V_1 * V_2 )
{
struct V_40 * V_8 = V_2 -> V_8 ;
int V_65 = V_8 -> V_66 ( & V_2 -> V_67 ) ;
F_19 ( V_2 -> V_27 , L_9 ,
V_2 -> V_67 / 1000 , V_2 -> V_67 % 1000 ) ;
if ( ! ! V_65 == ! ! V_2 -> V_25 )
return false ;
if ( V_65 ) {
V_2 -> V_25 = V_65 ;
if ( ! F_7 ( V_2 , false ) ) {
if ( V_65 > 0 )
F_12 ( V_2 , L_10 ) ;
else
F_12 ( V_2 , L_11 ) ;
}
} else {
V_2 -> V_25 = 0 ;
if ( ! F_7 ( V_2 , true ) )
F_12 ( V_2 , L_12 ) ;
}
return true ;
}
static bool F_21 ( void )
{
bool V_68 = false ;
struct V_1 * V_2 ;
F_22 ( & V_69 ) ;
F_23 (cm, &cm_list, entry) {
if ( F_20 ( V_2 ) )
V_68 = true ;
}
F_24 ( & V_69 ) ;
return V_68 ;
}
static void F_25 ( struct V_53 * V_54 )
{
unsigned long V_70 = V_71 ;
struct V_1 * V_2 ;
bool V_72 = false ;
unsigned long V_73 ;
F_22 ( & V_69 ) ;
F_23 (cm, &cm_list, entry) {
if ( F_6 ( V_2 ) && V_2 -> V_8 -> V_74 ) {
V_72 = true ;
if ( V_70 > V_2 -> V_8 -> V_74 )
V_70 = V_2 -> V_8 -> V_74 ;
}
}
V_75 = F_26 ( V_70 ) ;
if ( V_75 <= V_76 )
V_75 = V_76 + 1 ;
if ( ! V_72 )
V_75 = V_71 ;
if ( V_75 == V_71 )
goto V_77;
F_27 ( V_78 == NULL , L_13
L_14 , V_63 ) ;
V_73 = V_79 + V_75 ;
if ( ! F_28 ( & V_80 ) ||
( F_28 ( & V_80 ) &&
F_29 ( V_81 , V_73 ) ) ) {
F_30 ( & V_80 ) ;
V_81 = V_79 + V_75 ;
F_31 ( V_78 , & V_80 , V_75 ) ;
}
V_77:
F_24 ( & V_69 ) ;
}
static void F_32 ( struct V_53 * V_54 )
{
F_21 () ;
F_33 ( & V_82 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_40 * V_8 = V_2 -> V_8 ;
if ( ! V_8 -> V_61 || ! V_8 -> V_62 )
goto V_77;
if ( V_50 )
F_35 ( V_2 -> V_27 , true ) ;
if ( F_28 ( & V_2 -> V_57 ) )
F_36 ( & V_2 -> V_57 ) ;
F_31 ( V_78 , & V_2 -> V_57 ,
F_26 ( V_8 -> V_62 ) ) ;
V_2 -> V_60 = V_79 + F_26 (
V_8 -> V_62 ) ;
if ( V_2 -> V_60 == 0 )
V_2 -> V_60 = 1 ;
V_77:
F_14 ( V_2 -> V_27 , L_15 ) ;
F_12 ( V_2 , V_83 [ V_84 ] ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
if ( V_50 )
F_35 ( V_2 -> V_27 , true ) ;
if ( ! F_1 ( V_2 ) ) {
F_38 ( V_2 -> V_27 , L_16 ) ;
F_12 ( V_2 , V_83 [ V_85 ] ) ;
} else {
F_12 ( V_2 , L_17 ) ;
}
}
static void F_39 ( struct V_1 * V_2 ,
enum V_86 type )
{
if ( V_50 )
F_35 ( V_2 -> V_27 , true ) ;
if ( ! F_28 ( & V_80 ) &&
F_6 ( V_2 ) && V_2 -> V_8 -> V_74 )
F_33 ( & V_82 ) ;
F_12 ( V_2 , V_83 [ type ] ) ;
}
static int F_40 ( struct V_87 * V_88 ,
enum V_89 V_90 ,
union V_3 * V_4 )
{
struct V_1 * V_2 = F_17 ( V_88 ,
struct V_1 , V_91 ) ;
struct V_40 * V_8 = V_2 -> V_8 ;
int V_7 = 0 ;
int V_21 ;
switch ( V_90 ) {
case V_29 :
if ( F_4 ( V_2 ) )
V_4 -> V_16 = V_92 ;
else if ( F_2 ( V_2 ) )
V_4 -> V_16 = V_32 ;
else
V_4 -> V_16 = V_31 ;
break;
case V_93 :
if ( V_2 -> V_25 > 0 )
V_4 -> V_16 = V_94 ;
else if ( V_2 -> V_25 < 0 )
V_4 -> V_16 = V_95 ;
else
V_4 -> V_16 = V_96 ;
break;
case V_15 :
if ( F_1 ( V_2 ) )
V_4 -> V_16 = 1 ;
else
V_4 -> V_16 = 0 ;
break;
case V_23 :
V_7 = F_3 ( V_2 , & V_4 -> V_16 ) ;
break;
case V_97 :
V_7 = V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_97 , V_4 ) ;
break;
case V_98 :
if ( V_2 -> V_67 == V_99 )
V_8 -> V_66 ( & V_2 -> V_67 ) ;
V_4 -> V_16 = V_2 -> V_67 / 100 ;
if ( ! V_8 -> V_100 )
V_7 = - V_22 ;
break;
case V_101 :
if ( V_2 -> V_67 == V_99 )
V_8 -> V_66 ( & V_2 -> V_67 ) ;
V_4 -> V_16 = V_2 -> V_67 / 100 ;
if ( V_8 -> V_100 )
V_7 = - V_22 ;
break;
case V_102 :
if ( ! V_2 -> V_13 ) {
V_7 = - V_22 ;
break;
}
if ( ! F_1 ( V_2 ) ) {
V_4 -> V_16 = 100 ;
break;
}
V_7 = V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_102 , V_4 ) ;
if ( V_7 )
break;
if ( V_4 -> V_16 > 100 ) {
V_4 -> V_16 = 100 ;
break;
}
if ( V_4 -> V_16 < 0 )
V_4 -> V_16 = 0 ;
if ( F_4 ( V_2 ) )
break;
V_7 = F_3 ( V_2 , & V_21 ) ;
if ( V_7 ) {
V_7 = 0 ;
break;
}
if ( V_8 -> V_103 > 0 && V_21 >= V_8 -> V_103 &&
! F_4 ( V_2 ) ) {
V_4 -> V_16 = 100 ;
break;
}
break;
case V_20 :
if ( F_2 ( V_2 ) )
V_4 -> V_16 = 1 ;
else
V_4 -> V_16 = 0 ;
break;
case V_104 :
if ( V_2 -> V_13 ) {
if ( V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_104 , V_4 ) == 0 )
break;
}
if ( F_2 ( V_2 ) ) {
if ( F_4 ( V_2 ) ) {
V_4 -> V_16 = 0 ;
break;
}
if ( ! V_2 -> V_25 ) {
V_4 -> V_16 = 1 ;
break;
}
}
V_7 = F_3 ( V_2 , & V_21 ) ;
if ( ! V_7 && V_8 -> V_103 > 0 && V_21 >= V_8 -> V_103 &&
! F_4 ( V_2 ) ) {
V_4 -> V_16 = 1 ;
break;
}
if ( V_2 -> V_13 ) {
V_7 = V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_102 , V_4 ) ;
if ( ! V_7 && V_4 -> V_16 >= 100 && ! F_4 ( V_2 ) ) {
V_4 -> V_16 = 1 ;
break;
}
}
V_4 -> V_16 = 0 ;
V_7 = 0 ;
break;
case V_105 :
if ( F_4 ( V_2 ) ) {
V_7 = V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_105 ,
V_4 ) ;
if ( V_7 ) {
V_4 -> V_16 = 1 ;
V_7 = 0 ;
} else {
V_4 -> V_16 = ( V_4 -> V_16 > 0 ) ?
V_4 -> V_16 : 1 ;
}
} else {
V_4 -> V_16 = 0 ;
}
break;
default:
return - V_106 ;
}
return V_7 ;
}
static bool F_41 ( void )
{
struct V_1 * V_2 ;
unsigned int V_107 = V_108 ;
bool V_7 = false ;
F_22 ( & V_69 ) ;
F_23 (cm, &cm_list, entry) {
unsigned int V_109 = 0 ;
if ( V_2 -> V_60 ) {
V_109 = F_42 ( V_2 -> V_60
- V_79 ) ;
if ( F_43 (
V_2 -> V_60 ) ||
F_26 ( V_109 ) < V_76 ) {
F_15 ( & V_2 -> V_57 . V_54 ) ;
V_109 = 0 ;
}
}
F_44 ( V_107 , V_109 ) ;
if ( ! F_6 ( V_2 ) && ! V_2 -> V_25 )
continue;
if ( V_2 -> V_8 -> V_74 == 0 )
continue;
F_44 ( V_107 , V_2 -> V_8 -> V_74 ) ;
}
F_24 ( & V_69 ) ;
if ( V_107 < V_108 && V_107 > 0 ) {
F_45 ( L_18 , V_107 ) ;
if ( V_110 ) {
struct V_111 V_112 ;
unsigned long time , V_113 ;
unsigned long V_114 = F_46 ( V_107 , 1000 ) ;
V_112 . V_115 = 1 ;
F_47 ( V_110 , & V_112 . time ) ;
F_48 ( & V_112 . time , & V_113 ) ;
if ( V_114 < V_116 )
V_114 = V_116 ;
time = V_113 + V_114 ;
V_7 = true ;
if ( V_117 . V_115 &&
V_118 &&
V_118 < time ) {
if ( V_118 < V_113 + V_116 )
time = V_113 + V_116 ;
else
time = V_118 ;
V_7 = false ;
}
F_45 ( L_19 ,
time - V_113 ) ;
F_49 ( time , & V_112 . time ) ;
F_50 ( V_110 , & V_112 ) ;
V_119 += V_107 ;
return V_7 ;
}
}
if ( V_110 )
F_50 ( V_110 , & V_117 ) ;
return false ;
}
static void F_51 ( struct V_1 * V_2 )
{
unsigned long V_120 = V_79 ;
if ( ! V_2 -> V_60 )
return;
if ( V_121 && V_121 -> V_122 )
V_120 += F_26 ( V_119 ) ;
V_120 += V_76 ;
if ( F_52 ( V_120 , V_2 -> V_60 ) )
F_15 ( & V_2 -> V_57 . V_54 ) ;
}
bool F_53 ( void )
{
struct V_1 * V_2 ;
bool V_7 = false ;
if ( ! V_121 || ! V_121 -> V_123 || ! V_121 -> V_123 () ||
! V_124 )
return false ;
if ( F_21 () )
goto V_77;
V_7 = true ;
F_22 ( & V_69 ) ;
F_23 (cm, &cm_list, entry) {
F_51 ( V_2 ) ;
if ( V_2 -> V_125 != F_2 ( V_2 ) ||
V_2 -> V_126 != F_1 ( V_2 ) ) {
V_7 = false ;
break;
}
}
F_24 ( & V_69 ) ;
V_124 = F_41 () ;
V_77:
if ( V_117 . V_115 ) {
unsigned long V_113 ;
struct V_127 V_112 ;
F_47 ( V_110 , & V_112 ) ;
F_48 ( & V_112 , & V_113 ) ;
if ( V_118 &&
V_113 + V_116 >= V_118 )
return false ;
}
return V_7 ;
}
int F_54 ( struct V_128 * V_129 )
{
if ( ! V_129 )
return - V_106 ;
if ( V_110 )
F_55 ( V_110 ) ;
V_110 = NULL ;
V_121 = NULL ;
if ( ! V_129 -> V_123 ) {
F_56 ( L_20 ) ;
return - V_106 ;
}
if ( V_129 -> V_130 ) {
V_110 = F_57 ( V_129 -> V_130 ) ;
if ( F_58 ( V_110 ) ) {
V_110 = NULL ;
}
} else {
F_59 ( L_21
L_22 ) ;
}
V_121 = V_129 ;
return 0 ;
}
static void F_60 ( struct V_53 * V_54 )
{
struct V_131 * V_132 =
F_17 ( V_54 , struct V_131 , V_133 ) ;
int V_7 ;
if ( V_132 -> V_134 && V_132 -> V_135 != 0 && V_132 -> V_136 != 0 ) {
V_7 = F_61 ( V_132 -> V_137 -> V_44 ,
V_132 -> V_135 , V_132 -> V_136 ) ;
if ( V_7 < 0 ) {
F_56 ( L_23 ,
V_132 -> V_137 -> V_45 , V_132 -> V_138 ) ;
return;
}
F_45 ( L_24 ,
V_132 -> V_137 -> V_45 ,
V_132 -> V_135 , V_132 -> V_136 ) ;
}
F_7 ( V_132 -> V_2 , V_132 -> V_134 ) ;
}
static int F_62 ( struct V_139 * V_140 ,
unsigned long V_46 , void * V_141 )
{
struct V_131 * V_132 =
F_17 ( V_140 , struct V_131 , V_142 ) ;
V_132 -> V_134 = V_46 ;
F_33 ( & V_132 -> V_133 ) ;
return V_143 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_131 * V_132 )
{
int V_7 = 0 ;
F_64 ( & V_132 -> V_133 , F_60 ) ;
V_132 -> V_142 . V_144 = F_62 ;
V_7 = F_65 ( & V_132 -> V_145 ,
V_132 -> V_146 , V_132 -> V_138 , & V_132 -> V_142 ) ;
if ( V_7 < 0 ) {
F_45 ( L_25 ,
V_132 -> V_146 ,
V_132 -> V_138 ) ;
V_7 = - V_106 ;
}
return V_7 ;
}
static int F_66 ( struct V_147 * V_148 )
{
struct V_40 * V_8 = F_67 ( & V_148 -> V_27 ) ;
struct V_1 * V_2 ;
int V_7 = 0 , V_6 = 0 ;
int V_149 = 0 ;
union V_3 V_4 ;
if ( V_121 && ! V_110 && V_121 -> V_130 ) {
V_110 = F_57 ( V_121 -> V_130 ) ;
if ( F_58 ( V_110 ) ) {
V_110 = NULL ;
F_18 ( & V_148 -> V_27 , L_26 ,
V_121 -> V_130 ) ;
V_7 = - V_22 ;
goto V_150;
}
}
if ( ! V_8 ) {
F_18 ( & V_148 -> V_27 , L_27 ) ;
V_7 = - V_22 ;
goto V_150;
}
V_2 = F_68 ( sizeof( struct V_1 ) , V_151 ) ;
if ( ! V_2 ) {
F_18 ( & V_148 -> V_27 , L_28 ) ;
V_7 = - V_152 ;
goto V_150;
}
V_2 -> V_27 = & V_148 -> V_27 ;
V_2 -> V_8 = F_68 ( sizeof( struct V_40 ) , V_151 ) ;
if ( ! V_2 -> V_8 ) {
F_18 ( & V_148 -> V_27 , L_28 ) ;
V_7 = - V_152 ;
goto V_153;
}
memcpy ( V_2 -> V_8 , V_8 , sizeof( struct V_40 ) ) ;
V_2 -> V_67 = V_99 ;
if ( V_8 -> V_103 == 0 ) {
F_14 ( & V_148 -> V_27 , L_29
L_30 ) ;
}
if ( ! V_8 -> V_62 || ! V_8 -> V_61 ) {
F_14 ( & V_148 -> V_27 , L_31
L_32 ) ;
V_8 -> V_62 = 0 ;
V_8 -> V_61 = 0 ;
}
if ( ! V_8 -> V_43 || V_8 -> V_42 < 1 ) {
V_7 = - V_106 ;
F_18 ( & V_148 -> V_27 , L_33 ) ;
goto V_154;
}
if ( ! V_8 -> V_28 || ! V_8 -> V_28 [ 0 ] ) {
F_18 ( & V_148 -> V_27 , L_34 ) ;
V_7 = - V_106 ;
goto V_155;
}
while ( V_8 -> V_28 [ V_6 ] )
V_6 ++ ;
V_2 -> V_18 = F_68 ( sizeof( struct V_87 * ) * ( V_6 + 1 ) ,
V_151 ) ;
if ( ! V_2 -> V_18 ) {
V_7 = - V_152 ;
goto V_155;
}
for ( V_6 = 0 ; V_8 -> V_28 [ V_6 ] ; V_6 ++ ) {
V_2 -> V_18 [ V_6 ] = F_69 (
V_8 -> V_28 [ V_6 ] ) ;
if ( ! V_2 -> V_18 [ V_6 ] ) {
F_18 ( & V_148 -> V_27 , L_35
L_36 ,
V_8 -> V_28 [ V_6 ] ) ;
V_7 = - V_22 ;
goto V_156;
}
}
V_2 -> V_13 = F_69 ( V_8 -> V_157 ) ;
if ( ! V_2 -> V_13 ) {
F_18 ( & V_148 -> V_27 , L_37 ,
V_8 -> V_157 ) ;
V_7 = - V_22 ;
goto V_156;
}
if ( V_8 -> V_74 == 0 ||
F_26 ( V_8 -> V_74 ) <= V_76 ) {
F_18 ( & V_148 -> V_27 , L_38 ) ;
V_7 = - V_106 ;
goto V_156;
}
if ( ! V_8 -> V_66 ) {
F_18 ( & V_148 -> V_27 , L_39 ) ;
V_7 = - V_106 ;
goto V_156;
}
F_70 ( V_148 , V_2 ) ;
memcpy ( & V_2 -> V_91 , & V_158 , sizeof( V_158 ) ) ;
if ( ! V_8 -> V_159 ) {
strncpy ( V_2 -> V_160 , V_158 . V_138 , V_161 ) ;
} else {
strncpy ( V_2 -> V_160 , V_8 -> V_159 , V_161 ) ;
}
V_2 -> V_91 . V_138 = V_2 -> V_160 ;
V_2 -> V_91 . V_162 = F_68 ( sizeof( enum V_89 )
* ( F_71 ( V_163 ) +
V_164 ) ,
V_151 ) ;
if ( ! V_2 -> V_91 . V_162 ) {
F_18 ( & V_148 -> V_27 , L_40 ) ;
V_7 = - V_152 ;
goto V_156;
}
memcpy ( V_2 -> V_91 . V_162 , V_163 ,
sizeof( enum V_89 ) *
F_71 ( V_163 ) ) ;
V_2 -> V_91 . V_165 = V_158 . V_165 ;
if ( ! V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_105 , & V_4 ) ) {
V_2 -> V_91 . V_162 [ V_2 -> V_91 . V_165 ] =
V_105 ;
V_2 -> V_91 . V_165 ++ ;
}
if ( ! V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_97 ,
& V_4 ) ) {
V_2 -> V_91 . V_162 [ V_2 -> V_91 . V_165 ] =
V_97 ;
V_2 -> V_91 . V_165 ++ ;
}
if ( V_8 -> V_100 ) {
V_2 -> V_91 . V_162 [ V_2 -> V_91 . V_165 ] =
V_98 ;
V_2 -> V_91 . V_165 ++ ;
} else {
V_2 -> V_91 . V_162 [ V_2 -> V_91 . V_165 ] =
V_101 ;
V_2 -> V_91 . V_165 ++ ;
}
F_72 ( & V_2 -> V_57 , F_15 ) ;
V_7 = F_73 ( NULL , & V_2 -> V_91 ) ;
if ( V_7 ) {
F_18 ( & V_148 -> V_27 , L_41
L_42 , V_2 -> V_91 . V_138 ) ;
goto V_166;
}
for ( V_6 = 0 ; V_6 < V_8 -> V_42 ; V_6 ++ ) {
struct V_167 * V_137
= & V_8 -> V_43 [ V_6 ] ;
V_137 -> V_44 = F_74 ( & V_148 -> V_27 ,
V_137 -> V_45 ) ;
if ( V_137 -> V_44 == NULL ) {
F_18 ( & V_148 -> V_27 , L_43 ,
V_137 -> V_45 ) ;
V_7 = - V_106 ;
goto V_168;
}
for ( V_149 = 0 ; V_149 < V_137 -> V_169 ; V_149 ++ ) {
struct V_131 * V_132 = & V_137 -> V_170 [ V_149 ] ;
V_7 = F_63 ( V_2 , V_132 ) ;
if ( V_7 < 0 ) {
F_18 ( & V_148 -> V_27 , L_43 ,
V_137 -> V_45 ) ;
goto V_171;
}
V_132 -> V_137 = V_137 ;
V_132 -> V_2 = V_2 ;
}
}
V_7 = F_7 ( V_2 , true ) ;
if ( V_7 ) {
F_18 ( & V_148 -> V_27 , L_44 ) ;
goto V_172;
}
F_22 ( & V_69 ) ;
F_75 ( & V_2 -> V_173 , & V_174 ) ;
F_24 ( & V_69 ) ;
F_76 ( & V_148 -> V_27 , true ) ;
F_35 ( & V_148 -> V_27 , false ) ;
F_33 ( & V_82 ) ;
return 0 ;
V_172:
V_171:
for ( V_6 = 0 ; V_6 < V_8 -> V_42 ; V_6 ++ ) {
struct V_167 * V_137
= & V_8 -> V_43 [ V_6 ] ;
for ( V_149 = 0 ; V_149 < V_137 -> V_169 ; V_149 ++ ) {
struct V_131 * V_132 = & V_137 -> V_170 [ V_149 ] ;
F_77 ( & V_132 -> V_145 ) ;
}
}
V_168:
for ( V_6 = 0 ; V_6 < V_8 -> V_42 ; V_6 ++ )
F_78 ( V_8 -> V_43 [ V_6 ] . V_44 ) ;
F_79 ( & V_2 -> V_91 ) ;
V_166:
F_80 ( V_2 -> V_91 . V_162 ) ;
V_156:
F_80 ( V_2 -> V_18 ) ;
V_155:
V_154:
F_80 ( V_2 -> V_8 ) ;
V_153:
F_80 ( V_2 ) ;
V_150:
return V_7 ;
}
static int T_1 F_81 ( struct V_147 * V_148 )
{
struct V_1 * V_2 = F_82 ( V_148 ) ;
struct V_40 * V_8 = V_2 -> V_8 ;
int V_6 = 0 ;
int V_149 = 0 ;
F_22 ( & V_69 ) ;
F_83 ( & V_2 -> V_173 ) ;
F_24 ( & V_69 ) ;
if ( F_84 ( & V_82 ) )
F_85 ( & V_82 ) ;
if ( F_28 ( & V_80 ) )
F_30 ( & V_80 ) ;
for ( V_6 = 0 ; V_6 < V_8 -> V_42 ; V_6 ++ ) {
struct V_167 * V_137
= & V_8 -> V_43 [ V_6 ] ;
for ( V_149 = 0 ; V_149 < V_137 -> V_169 ; V_149 ++ ) {
struct V_131 * V_132 = & V_137 -> V_170 [ V_149 ] ;
F_77 ( & V_132 -> V_145 ) ;
}
}
for ( V_6 = 0 ; V_6 < V_8 -> V_42 ; V_6 ++ )
F_78 ( V_8 -> V_43 [ V_6 ] . V_44 ) ;
F_79 ( & V_2 -> V_91 ) ;
F_7 ( V_2 , false ) ;
F_80 ( V_2 -> V_91 . V_162 ) ;
F_80 ( V_2 -> V_18 ) ;
F_80 ( V_2 -> V_8 ) ;
F_80 ( V_2 ) ;
return 0 ;
}
static int F_86 ( struct V_175 * V_27 )
{
int V_7 = 0 ;
if ( F_87 ( V_27 ) ) {
F_35 ( V_27 , false ) ;
V_7 = - V_41 ;
}
return V_7 ;
}
static int F_88 ( struct V_175 * V_27 )
{
struct V_1 * V_2 = F_89 ( V_27 ) ;
if ( ! V_50 ) {
if ( V_110 ) {
struct V_127 V_112 ;
unsigned long V_113 ;
F_90 ( V_110 , & V_117 ) ;
F_47 ( V_110 , & V_112 ) ;
if ( V_117 . V_115 ) {
F_48 ( & V_117 . time ,
& V_118 ) ;
F_48 ( & V_112 , & V_113 ) ;
if ( V_113 > V_118 )
V_118 = 0 ;
} else {
V_118 = 0 ;
}
}
V_50 = true ;
}
if ( F_28 ( & V_2 -> V_57 ) )
F_36 ( & V_2 -> V_57 ) ;
V_2 -> V_125 = F_2 ( V_2 ) ;
V_2 -> V_126 = F_1 ( V_2 ) ;
if ( ! V_124 ) {
V_119 = 0 ;
V_124 = F_41 () ;
}
return 0 ;
}
static void F_91 ( struct V_175 * V_27 )
{
struct V_1 * V_2 = F_89 ( V_27 ) ;
if ( V_50 ) {
if ( V_110 ) {
struct V_111 V_112 ;
F_90 ( V_110 , & V_112 ) ;
V_117 . V_176 = V_112 . V_176 ;
F_50 ( V_110 , & V_117 ) ;
}
V_50 = false ;
V_124 = false ;
}
if ( V_2 -> V_60 ) {
unsigned long V_177 = 0 ;
unsigned long V_113 = V_79 + V_76 ;
if ( F_52 ( V_113 , V_2 -> V_60 ) ) {
V_177 = ( unsigned long ) ( ( long ) V_113
- ( long ) ( V_2 -> V_60 ) ) ;
V_177 = F_42 ( V_177 ) ;
} else {
V_177 = 0 ;
}
if ( V_121 && V_121 -> V_122 ) {
if ( V_177 > V_119 )
V_177 -= V_119 ;
else
V_177 = 0 ;
}
F_31 ( V_78 , & V_2 -> V_57 ,
F_26 ( V_177 ) ) ;
}
F_35 ( V_2 -> V_27 , false ) ;
F_12 ( V_2 , NULL ) ;
}
static int T_2 F_92 ( void )
{
V_78 = F_93 ( L_45 ) ;
F_72 ( & V_80 , F_32 ) ;
return F_94 ( & V_178 ) ;
}
static void T_3 F_95 ( void )
{
F_96 ( V_78 ) ;
V_78 = NULL ;
F_97 ( & V_178 ) ;
}
static bool F_98 ( struct V_1 * V_2 ,
struct V_87 * V_88 )
{
int V_6 ;
bool V_179 = false ;
for ( V_6 = 0 ; V_2 -> V_18 [ V_6 ] ; V_6 ++ ) {
if ( V_88 == V_2 -> V_18 [ V_6 ] ) {
V_179 = true ;
break;
}
}
return V_179 ;
}
void F_99 ( struct V_87 * V_88 , enum V_86 type ,
char * V_180 )
{
struct V_1 * V_2 ;
bool V_181 = false ;
if ( V_88 == NULL )
return;
F_22 ( & V_69 ) ;
F_23 (cm, &cm_list, entry) {
V_181 = F_98 ( V_2 , V_88 ) ;
if ( V_181 )
break;
}
F_24 ( & V_69 ) ;
if ( ! V_181 )
return;
switch ( type ) {
case V_84 :
F_34 ( V_2 ) ;
break;
case V_85 :
F_37 ( V_2 ) ;
break;
case V_182 :
case V_183 ... V_184 :
F_39 ( V_2 , type ) ;
break;
case V_185 :
case V_186 :
F_12 ( V_2 , V_180 ? V_180 : V_83 [ type ] ) ;
break;
default:
F_18 ( V_2 -> V_27 , L_46 , V_63 ) ;
break;
}
}

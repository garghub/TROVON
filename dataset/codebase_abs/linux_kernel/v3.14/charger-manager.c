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
struct V_33 * V_8 = V_2 -> V_8 ;
union V_3 V_4 ;
int V_7 = 0 ;
int V_21 ;
if ( ! F_1 ( V_2 ) )
return false ;
if ( V_2 -> V_13 && V_8 -> V_34 > 0 ) {
V_4 . V_16 = 0 ;
V_7 = V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_35 , & V_4 ) ;
if ( ! V_7 && V_4 . V_16 > V_8 -> V_34 )
return true ;
}
if ( V_8 -> V_36 > 0 ) {
V_7 = F_3 ( V_2 , & V_21 ) ;
if ( ! V_7 && V_21 >= V_8 -> V_36 )
return true ;
}
if ( V_2 -> V_13 && V_8 -> V_37 > 0 ) {
V_4 . V_16 = 0 ;
V_7 = V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_38 , & V_4 ) ;
if ( ! V_7 && V_4 . V_16 >= V_8 -> V_37 )
return true ;
}
return false ;
}
static bool F_7 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 -> V_39 ) {
case V_40 :
return false ;
case V_41 :
return true ;
case V_42 :
return F_2 ( V_2 ) ;
case V_43 :
return F_4 ( V_2 ) ;
default:
F_5 ( V_2 -> V_27 , L_3 ,
V_2 -> V_8 -> V_39 ) ;
}
return false ;
}
static int F_8 ( struct V_1 * V_2 , bool V_44 )
{
int V_45 = 0 , V_6 ;
struct V_33 * V_8 = V_2 -> V_8 ;
if ( V_44 == V_2 -> V_26 )
return 0 ;
if ( V_44 ) {
if ( V_2 -> V_25 )
return - V_46 ;
V_2 -> V_47 = F_9 ( F_10 () ) ;
V_2 -> V_48 = 0 ;
for ( V_6 = 0 ; V_6 < V_8 -> V_49 ; V_6 ++ ) {
if ( V_8 -> V_50 [ V_6 ] . V_51 )
continue;
V_45 = F_11 ( V_8 -> V_50 [ V_6 ] . V_52 ) ;
if ( V_45 < 0 ) {
F_5 ( V_2 -> V_27 , L_4 ,
V_8 -> V_50 [ V_6 ] . V_53 ) ;
}
}
} else {
V_2 -> V_47 = 0 ;
V_2 -> V_48 = F_9 ( F_10 () ) ;
for ( V_6 = 0 ; V_6 < V_8 -> V_49 ; V_6 ++ ) {
if ( V_8 -> V_50 [ V_6 ] . V_51 )
continue;
V_45 = F_12 ( V_8 -> V_50 [ V_6 ] . V_52 ) ;
if ( V_45 < 0 ) {
F_5 ( V_2 -> V_27 , L_5 ,
V_8 -> V_50 [ V_6 ] . V_53 ) ;
}
}
for ( V_6 = 0 ; V_6 < V_8 -> V_49 ; V_6 ++ ) {
if ( F_13 (
V_8 -> V_50 [ V_6 ] . V_52 ) ) {
F_14 (
V_8 -> V_50 [ V_6 ] . V_52 ) ;
F_5 ( V_2 -> V_27 , L_6 ,
V_8 -> V_50 [ V_6 ] . V_53 ) ;
}
}
}
if ( ! V_45 )
V_2 -> V_26 = V_44 ;
return V_45 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_45 ;
if ( V_2 -> V_25 )
return - V_46 ;
V_45 = F_8 ( V_2 , false ) ;
if ( V_45 )
return V_45 ;
return F_8 ( V_2 , true ) ;
}
static void F_16 ( struct V_1 * V_2 , const char * V_54 )
{
static char V_55 [ V_56 + 1 ] = L_7 ;
static char V_57 [ V_56 + 1 ] = L_7 ;
if ( V_58 ) {
if ( V_57 [ 0 ] == 0 ) {
if ( ! strncmp ( V_55 , V_54 , V_56 ) )
return;
strncpy ( V_57 , V_54 , V_56 ) ;
return;
}
if ( ! strncmp ( V_57 , V_54 , V_56 ) )
return;
strncpy ( V_57 , V_54 , V_56 ) ;
return;
}
if ( V_54 == NULL ) {
if ( ! V_57 [ 0 ] )
return;
strncpy ( V_55 , V_57 , V_56 ) ;
F_17 ( & V_2 -> V_27 -> V_59 , V_60 ) ;
V_57 [ 0 ] = 0 ;
return;
}
if ( ! strncmp ( V_55 , V_54 , V_56 ) )
return;
strncpy ( V_55 , V_54 , V_56 ) ;
F_17 ( & V_2 -> V_27 -> V_59 , V_60 ) ;
F_18 ( V_2 -> V_27 , L_8 , V_54 ) ;
}
static void F_19 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_20 ( V_62 ) ;
struct V_1 * V_2 = F_21 ( V_64 ,
struct V_1 , V_65 ) ;
struct V_33 * V_8 = V_2 -> V_8 ;
int V_66 , V_45 , V_67 ;
V_2 -> V_68 = 0 ;
if ( ! V_8 -> V_69 || ! V_8 -> V_70 )
return;
V_45 = F_3 ( V_2 , & V_66 ) ;
if ( V_45 ) {
F_22 ( V_2 -> V_27 , L_9 , V_71 , V_45 ) ;
return;
}
V_67 = V_8 -> V_36 - V_66 ;
if ( V_67 < 0 )
return;
F_18 ( V_2 -> V_27 , L_10 , V_67 ) ;
if ( V_67 > V_8 -> V_69 ) {
F_15 ( V_2 ) ;
F_16 ( V_2 , L_11 ) ;
}
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_33 * V_8 = V_2 -> V_8 ;
T_1 V_72 = F_9 ( F_10 () ) ;
T_1 V_73 ;
int V_7 = false ;
if ( ! V_8 -> V_74 &&
! V_8 -> V_75 )
return V_7 ;
if ( V_2 -> V_26 ) {
V_73 = V_72 - V_2 -> V_47 ;
if ( V_73 > V_8 -> V_74 ) {
F_18 ( V_2 -> V_27 , L_12 ,
V_8 -> V_74 ) ;
F_16 ( V_2 , L_13 ) ;
F_8 ( V_2 , false ) ;
V_7 = true ;
}
} else if ( F_2 ( V_2 ) && ! V_2 -> V_26 ) {
V_73 = V_72 - V_2 -> V_48 ;
if ( V_73 > V_8 -> V_74 &&
F_2 ( V_2 ) ) {
F_18 ( V_2 -> V_27 , L_14 ,
V_8 -> V_75 ) ;
F_16 ( V_2 , L_11 ) ;
F_8 ( V_2 , true ) ;
V_7 = true ;
}
}
return V_7 ;
}
static int F_24 ( struct V_1 * V_2 ,
int * V_76 )
{
int V_7 ;
if ( ! V_2 -> V_8 -> V_77 )
return - V_22 ;
#ifdef F_25
V_7 = F_26 ( V_2 -> V_78 , ( unsigned long * ) V_76 ) ;
if ( ! V_7 )
* V_76 /= 100 ;
#else
V_7 = V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_79 ,
(union V_3 * ) V_76 ) ;
#endif
return V_7 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_33 * V_8 = V_2 -> V_8 ;
int V_76 , V_80 , V_81 ;
int V_7 = 0 ;
V_7 = F_24 ( V_2 , & V_76 ) ;
if ( V_7 ) {
F_22 ( V_2 -> V_27 , L_15 ) ;
return 0 ;
}
V_80 = V_8 -> V_82 ;
V_81 = V_8 -> V_83 ;
if ( V_2 -> V_25 ) {
V_80 -= V_8 -> V_84 ;
V_81 += V_8 -> V_84 ;
}
if ( V_76 > V_80 )
V_7 = V_85 ;
else if ( V_76 < V_81 )
V_7 = V_86 ;
return V_7 ;
}
static bool F_28 ( struct V_1 * V_2 )
{
int V_87 ;
V_87 = F_27 ( V_2 ) ;
if ( V_87 && V_2 -> V_25 )
return false ;
if ( V_87 ) {
V_2 -> V_25 = V_87 ;
if ( ! F_8 ( V_2 , false ) )
F_16 ( V_2 , V_88 [ V_87 ] ) ;
} else if ( ! V_2 -> V_25 && F_23 ( V_2 ) ) {
F_29 ( V_2 -> V_27 ,
L_16 ) ;
} else if ( ! V_2 -> V_25 && F_2 ( V_2 ) &&
! V_2 -> V_26 ) {
F_19 ( & V_2 -> V_65 . V_62 ) ;
} else if ( ! V_2 -> V_25 && F_6 ( V_2 ) &&
V_2 -> V_26 ) {
F_18 ( V_2 -> V_27 , L_17 ) ;
F_16 ( V_2 , V_88 [ V_89 ] ) ;
F_8 ( V_2 , false ) ;
F_19 ( & V_2 -> V_65 . V_62 ) ;
} else {
V_2 -> V_25 = 0 ;
if ( F_2 ( V_2 ) ) {
if ( ! F_8 ( V_2 , true ) )
F_16 ( V_2 , L_18 ) ;
}
}
return true ;
}
static bool F_30 ( void )
{
bool V_90 = false ;
struct V_1 * V_2 ;
F_31 ( & V_91 ) ;
F_32 (cm, &cm_list, entry) {
if ( F_28 ( V_2 ) )
V_90 = true ;
}
F_33 ( & V_91 ) ;
return V_90 ;
}
static void F_34 ( struct V_61 * V_62 )
{
unsigned long V_92 = V_93 ;
struct V_1 * V_2 ;
bool V_94 = false ;
unsigned long V_95 ;
F_31 ( & V_91 ) ;
F_32 (cm, &cm_list, entry) {
if ( F_7 ( V_2 ) && V_2 -> V_8 -> V_96 ) {
V_94 = true ;
if ( V_92 > V_2 -> V_8 -> V_96 )
V_92 = V_2 -> V_8 -> V_96 ;
}
}
V_97 = F_35 ( V_92 ) ;
if ( V_97 <= V_98 )
V_97 = V_98 + 1 ;
if ( ! V_94 )
V_97 = V_93 ;
if ( V_97 == V_93 )
goto V_99;
F_36 ( V_100 == NULL , L_19
L_20 , V_71 ) ;
V_95 = V_101 + V_97 ;
if ( F_37 ( V_95 , V_102 ) ) {
F_38 ( V_100 , & V_103 , V_97 ) ;
V_102 = V_95 ;
} else {
if ( F_39 ( V_100 , & V_103 , V_97 ) )
V_102 = V_95 ;
}
V_99:
F_33 ( & V_91 ) ;
}
static void F_40 ( struct V_61 * V_62 )
{
F_30 () ;
F_41 ( & V_104 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_33 * V_8 = V_2 -> V_8 ;
if ( ! V_8 -> V_69 || ! V_8 -> V_70 )
goto V_99;
if ( V_58 )
F_43 ( V_2 -> V_27 , true ) ;
F_38 ( V_100 , & V_2 -> V_65 ,
F_35 ( V_8 -> V_70 ) ) ;
V_2 -> V_68 = V_101 + F_35 (
V_8 -> V_70 ) ;
if ( V_2 -> V_68 == 0 )
V_2 -> V_68 = 1 ;
V_99:
F_18 ( V_2 -> V_27 , L_17 ) ;
F_16 ( V_2 , V_88 [ V_89 ] ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
if ( V_58 )
F_43 ( V_2 -> V_27 , true ) ;
if ( ! F_1 ( V_2 ) ) {
F_45 ( V_2 -> V_27 , L_21 ) ;
F_16 ( V_2 , V_88 [ V_105 ] ) ;
} else {
F_16 ( V_2 , L_22 ) ;
}
}
static void F_46 ( struct V_1 * V_2 ,
enum V_106 type )
{
if ( V_58 )
F_43 ( V_2 -> V_27 , true ) ;
if ( F_7 ( V_2 ) && V_2 -> V_8 -> V_96 )
F_41 ( & V_104 ) ;
F_16 ( V_2 , V_88 [ type ] ) ;
}
static int F_47 ( struct V_107 * V_108 ,
enum V_109 V_110 ,
union V_3 * V_4 )
{
struct V_1 * V_2 = F_21 ( V_108 ,
struct V_1 , V_111 ) ;
struct V_33 * V_8 = V_2 -> V_8 ;
int V_7 = 0 ;
int V_21 ;
switch ( V_110 ) {
case V_29 :
if ( F_4 ( V_2 ) )
V_4 -> V_16 = V_112 ;
else if ( F_2 ( V_2 ) )
V_4 -> V_16 = V_32 ;
else
V_4 -> V_16 = V_31 ;
break;
case V_113 :
if ( V_2 -> V_25 > 0 )
V_4 -> V_16 = V_114 ;
else if ( V_2 -> V_25 < 0 )
V_4 -> V_16 = V_115 ;
else
V_4 -> V_16 = V_116 ;
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
case V_117 :
V_7 = V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_117 , V_4 ) ;
break;
case V_79 :
case V_118 :
return F_24 ( V_2 , & V_4 -> V_16 ) ;
case V_38 :
if ( ! V_2 -> V_13 ) {
V_7 = - V_22 ;
break;
}
if ( ! F_1 ( V_2 ) ) {
V_4 -> V_16 = 100 ;
break;
}
V_7 = V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_38 , V_4 ) ;
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
if ( V_8 -> V_36 > 0 && V_21 >= V_8 -> V_36 &&
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
case V_35 :
if ( F_6 ( V_2 ) )
V_4 -> V_16 = 1 ;
else
V_4 -> V_16 = 0 ;
V_7 = 0 ;
break;
case V_119 :
if ( F_4 ( V_2 ) ) {
V_7 = V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_119 ,
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
return - V_120 ;
}
return V_7 ;
}
static bool F_48 ( void )
{
struct V_1 * V_2 ;
unsigned int V_121 = V_122 ;
bool V_7 = false ;
F_31 ( & V_91 ) ;
F_32 (cm, &cm_list, entry) {
unsigned int V_123 = 0 ;
if ( V_2 -> V_68 ) {
V_123 = F_49 ( V_2 -> V_68
- V_101 ) ;
if ( F_50 (
V_2 -> V_68 ) ||
F_35 ( V_123 ) < V_98 ) {
F_19 ( & V_2 -> V_65 . V_62 ) ;
V_123 = 0 ;
}
}
F_51 ( V_121 , V_123 ) ;
if ( ! F_7 ( V_2 ) && ! V_2 -> V_25 )
continue;
if ( V_2 -> V_8 -> V_96 == 0 )
continue;
F_51 ( V_121 , V_2 -> V_8 -> V_96 ) ;
}
F_33 ( & V_91 ) ;
if ( V_121 < V_122 && V_121 > 0 ) {
F_52 ( L_23 , V_121 ) ;
if ( V_124 ) {
struct V_125 V_126 ;
unsigned long time , V_127 ;
unsigned long V_128 = F_53 ( V_121 , 1000 ) ;
V_126 . V_129 = 1 ;
F_54 ( V_124 , & V_126 . time ) ;
F_55 ( & V_126 . time , & V_127 ) ;
if ( V_128 < V_130 )
V_128 = V_130 ;
time = V_127 + V_128 ;
V_7 = true ;
if ( V_131 . V_129 &&
V_132 &&
V_132 < time ) {
if ( V_132 < V_127 + V_130 )
time = V_127 + V_130 ;
else
time = V_132 ;
V_7 = false ;
}
F_52 ( L_24 , time - V_127 ) ;
F_56 ( time , & V_126 . time ) ;
F_57 ( V_124 , & V_126 ) ;
V_133 += V_121 ;
return V_7 ;
}
}
if ( V_124 )
F_57 ( V_124 , & V_131 ) ;
return false ;
}
static void F_58 ( struct V_1 * V_2 )
{
unsigned long V_134 = V_101 ;
if ( ! V_2 -> V_68 )
return;
if ( V_135 && V_135 -> V_136 )
V_134 += F_35 ( V_133 ) ;
V_134 += V_98 ;
if ( F_59 ( V_134 , V_2 -> V_68 ) )
F_19 ( & V_2 -> V_65 . V_62 ) ;
}
bool F_60 ( void )
{
struct V_1 * V_2 ;
bool V_7 = false ;
if ( ! V_135 || ! V_135 -> V_137 || ! V_135 -> V_137 () ||
! V_138 )
return false ;
if ( F_30 () )
goto V_99;
V_7 = true ;
F_31 ( & V_91 ) ;
F_32 (cm, &cm_list, entry) {
F_58 ( V_2 ) ;
if ( V_2 -> V_139 != F_2 ( V_2 ) ||
V_2 -> V_140 != F_1 ( V_2 ) ) {
V_7 = false ;
break;
}
}
F_33 ( & V_91 ) ;
V_138 = F_48 () ;
V_99:
if ( V_131 . V_129 ) {
unsigned long V_127 ;
struct V_141 V_126 ;
F_54 ( V_124 , & V_126 ) ;
F_55 ( & V_126 , & V_127 ) ;
if ( V_132 &&
V_127 + V_130 >= V_132 )
return false ;
}
return V_7 ;
}
int F_61 ( struct V_142 * V_143 )
{
if ( ! V_143 )
return - V_120 ;
if ( V_124 )
F_62 ( V_124 ) ;
V_124 = NULL ;
V_135 = NULL ;
if ( ! V_143 -> V_137 ) {
F_63 ( L_25 ) ;
return - V_120 ;
}
if ( V_143 -> V_144 ) {
V_124 = F_64 ( V_143 -> V_144 ) ;
if ( F_65 ( V_124 ) ) {
V_124 = NULL ;
}
} else {
F_66 ( L_26
L_27 ) ;
}
V_135 = V_143 ;
return 0 ;
}
static void F_67 ( struct V_61 * V_62 )
{
struct V_145 * V_146 =
F_21 ( V_62 , struct V_145 , V_147 ) ;
int V_7 ;
if ( V_146 -> V_148 && V_146 -> V_149 != 0 && V_146 -> V_150 != 0 ) {
V_7 = F_68 ( V_146 -> V_151 -> V_52 ,
V_146 -> V_149 , V_146 -> V_150 ) ;
if ( V_7 < 0 ) {
F_63 ( L_28 ,
V_146 -> V_151 -> V_53 , V_146 -> V_152 ) ;
return;
}
F_52 ( L_29 ,
V_146 -> V_151 -> V_53 ,
V_146 -> V_149 , V_146 -> V_150 ) ;
}
F_8 ( V_146 -> V_2 , V_146 -> V_148 ) ;
}
static int F_69 ( struct V_153 * V_154 ,
unsigned long V_54 , void * V_155 )
{
struct V_145 * V_146 =
F_21 ( V_154 , struct V_145 , V_156 ) ;
V_146 -> V_148 = V_54 ;
if ( V_146 -> V_148 && F_7 ( V_146 -> V_2 ) ) {
F_70 ( & V_104 ) ;
F_41 ( & V_104 ) ;
}
F_41 ( & V_146 -> V_147 ) ;
return V_157 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_145 * V_146 )
{
int V_7 = 0 ;
F_72 ( & V_146 -> V_147 , F_67 ) ;
V_146 -> V_156 . V_158 = F_69 ;
V_7 = F_73 ( & V_146 -> V_159 ,
V_146 -> V_160 , V_146 -> V_152 , & V_146 -> V_156 ) ;
if ( V_7 < 0 ) {
F_52 ( L_30 ,
V_146 -> V_160 , V_146 -> V_152 ) ;
V_7 = - V_120 ;
}
return V_7 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_33 * V_8 = V_2 -> V_8 ;
struct V_161 * V_151 ;
int V_7 = 0 ;
int V_6 ;
int V_162 ;
for ( V_6 = 0 ; V_6 < V_8 -> V_49 ; V_6 ++ ) {
V_151 = & V_8 -> V_50 [ V_6 ] ;
V_151 -> V_52 = F_75 ( V_2 -> V_27 ,
V_151 -> V_53 ) ;
if ( F_76 ( V_151 -> V_52 ) ) {
F_22 ( V_2 -> V_27 , L_31 ,
V_151 -> V_53 ) ;
return F_77 ( V_151 -> V_52 ) ;
}
V_151 -> V_2 = V_2 ;
for ( V_162 = 0 ; V_162 < V_151 -> V_163 ; V_162 ++ ) {
struct V_145 * V_146 = & V_151 -> V_164 [ V_162 ] ;
V_7 = F_71 ( V_2 , V_146 ) ;
if ( V_7 < 0 ) {
F_22 ( V_2 -> V_27 , L_32 ,
V_151 -> V_53 ) ;
goto V_45;
}
V_146 -> V_151 = V_151 ;
V_146 -> V_2 = V_2 ;
}
}
V_45:
return V_7 ;
}
static T_2 F_78 ( struct V_165 * V_27 ,
struct V_166 * V_167 , char * V_168 )
{
struct V_161 * V_151
= F_21 ( V_167 , struct V_161 , V_169 ) ;
return sprintf ( V_168 , L_8 , V_151 -> V_53 ) ;
}
static T_2 F_79 ( struct V_165 * V_27 ,
struct V_166 * V_167 , char * V_168 )
{
struct V_161 * V_151
= F_21 ( V_167 , struct V_161 , V_170 ) ;
int V_171 = 0 ;
if ( ! V_151 -> V_51 )
V_171 = F_13 ( V_151 -> V_52 ) ;
return sprintf ( V_168 , L_8 , V_171 ? L_33 : L_34 ) ;
}
static T_2 F_80 ( struct V_165 * V_27 ,
struct V_166 * V_167 , char * V_168 )
{
struct V_161 * V_151 = F_21 ( V_167 ,
struct V_161 , V_172 ) ;
return sprintf ( V_168 , L_35 , V_151 -> V_51 ) ;
}
static T_2 F_81 ( struct V_165 * V_27 ,
struct V_166 * V_167 , const char * V_168 ,
T_3 V_173 )
{
struct V_161 * V_151
= F_21 ( V_167 , struct V_161 ,
V_172 ) ;
struct V_1 * V_2 = V_151 -> V_2 ;
struct V_33 * V_8 = V_2 -> V_8 ;
int V_6 ;
int V_7 ;
int V_51 ;
int V_174 = 1 ;
V_7 = sscanf ( V_168 , L_36 , & V_51 ) ;
if ( V_7 == 0 ) {
V_7 = - V_120 ;
return V_7 ;
}
if ( ! V_51 ) {
V_151 -> V_51 = 0 ;
return V_173 ;
}
for ( V_6 = 0 ; V_6 < V_8 -> V_49 ; V_6 ++ ) {
if ( & V_8 -> V_50 [ V_6 ] != V_151 &&
! V_8 -> V_50 [ V_6 ] . V_51 ) {
V_174 = 0 ;
break;
}
}
if ( ! V_174 ) {
if ( V_2 -> V_26 ) {
F_8 ( V_151 -> V_2 , false ) ;
V_151 -> V_51 = V_51 ;
F_8 ( V_151 -> V_2 , true ) ;
} else {
V_151 -> V_51 = V_51 ;
}
} else {
F_5 ( V_2 -> V_27 ,
L_37 ,
V_151 -> V_53 ) ;
}
return V_173 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_33 * V_8 = V_2 -> V_8 ;
struct V_161 * V_151 ;
int V_174 = 1 ;
char V_168 [ 11 ] ;
char * V_175 ;
int V_7 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_8 -> V_49 ; V_6 ++ ) {
V_151 = & V_8 -> V_50 [ V_6 ] ;
snprintf ( V_168 , 10 , L_38 , V_6 ) ;
V_175 = F_83 ( V_2 -> V_27 ,
sizeof( char ) * ( strlen ( V_168 ) + 1 ) , V_176 ) ;
if ( ! V_175 ) {
V_7 = - V_177 ;
goto V_45;
}
strcpy ( V_175 , V_168 ) ;
V_151 -> V_178 [ 0 ] = & V_151 -> V_169 . V_167 ;
V_151 -> V_178 [ 1 ] = & V_151 -> V_170 . V_167 ;
V_151 -> V_178 [ 2 ] = & V_151 -> V_172 . V_167 ;
V_151 -> V_178 [ 3 ] = NULL ;
V_151 -> V_179 . V_152 = V_175 ;
V_151 -> V_179 . V_178 = V_151 -> V_178 ;
F_84 ( & V_151 -> V_169 . V_167 ) ;
V_151 -> V_169 . V_167 . V_152 = L_39 ;
V_151 -> V_169 . V_167 . V_180 = 0444 ;
V_151 -> V_169 . V_181 = F_78 ;
F_84 ( & V_151 -> V_170 . V_167 ) ;
V_151 -> V_170 . V_167 . V_152 = L_40 ;
V_151 -> V_170 . V_167 . V_180 = 0444 ;
V_151 -> V_170 . V_181 = F_79 ;
F_84 ( & V_151 -> V_172 . V_167 ) ;
V_151 -> V_172 . V_167 . V_152
= L_41 ;
V_151 -> V_172 . V_167 . V_180 = 0644 ;
V_151 -> V_172 . V_181
= F_80 ;
V_151 -> V_172 . V_182
= F_81 ;
if ( ! V_8 -> V_50 [ V_6 ] . V_51 ||
! V_174 )
V_174 = 0 ;
F_18 ( V_2 -> V_27 , L_42 ,
V_151 -> V_53 , V_151 -> V_51 ) ;
V_7 = F_85 ( & V_2 -> V_111 . V_27 -> V_59 ,
& V_151 -> V_179 ) ;
if ( V_7 < 0 ) {
F_22 ( V_2 -> V_27 , L_43 ,
V_151 -> V_53 ) ;
V_7 = - V_120 ;
goto V_45;
}
}
if ( V_174 ) {
F_22 ( V_2 -> V_27 , L_44 ) ;
V_7 = - V_120 ;
goto V_45;
}
V_45:
return V_7 ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_33 * V_8 = V_2 -> V_8 ;
union V_3 V_4 ;
int V_7 ;
V_7 = V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_79 , & V_4 ) ;
if ( ! V_7 ) {
V_2 -> V_111 . V_183 [ V_2 -> V_111 . V_184 ] =
V_79 ;
V_2 -> V_111 . V_184 ++ ;
V_2 -> V_8 -> V_77 = true ;
}
#ifdef F_25
V_2 -> V_78 = V_2 -> V_13 -> V_185 ;
if ( V_7 && V_8 -> V_186 ) {
V_2 -> V_78 =
F_87 ( V_8 -> V_186 ) ;
if ( F_76 ( V_2 -> V_78 ) )
return F_77 ( V_2 -> V_78 ) ;
V_2 -> V_111 . V_183 [ V_2 -> V_111 . V_184 ] =
V_118 ;
V_2 -> V_111 . V_184 ++ ;
V_2 -> V_8 -> V_77 = true ;
V_7 = 0 ;
}
#endif
if ( V_2 -> V_8 -> V_77 ) {
if ( ! V_8 -> V_82 )
V_8 -> V_82 = V_187 ;
if ( ! V_8 -> V_84 )
V_8 -> V_84 = V_188 ;
}
return V_7 ;
}
static struct V_33 * F_88 ( struct V_165 * V_27 )
{
struct V_33 * V_8 ;
struct V_189 * V_190 = V_27 -> V_191 ;
T_4 V_192 = V_40 ;
T_4 V_193 = V_11 ;
int V_194 = 0 ;
V_8 = F_83 ( V_27 , sizeof( * V_8 ) , V_176 ) ;
if ( ! V_8 )
return F_89 ( - V_177 ) ;
F_90 ( V_190 , L_45 , & V_8 -> V_195 ) ;
F_91 ( V_190 , L_46 , & V_192 ) ;
V_8 -> V_39 = V_192 ;
F_91 ( V_190 , L_47 ,
& V_8 -> V_96 ) ;
F_91 ( V_190 , L_48 ,
& V_8 -> V_70 ) ;
F_91 ( V_190 , L_49 ,
& V_8 -> V_69 ) ;
F_91 ( V_190 , L_50 , & V_8 -> V_36 ) ;
F_91 ( V_190 , L_51 , & V_8 -> V_37 ) ;
F_91 ( V_190 , L_52 ,
& V_8 -> V_34 ) ;
F_91 ( V_190 , L_53 , & V_193 ) ;
V_8 -> V_9 = V_193 ;
F_91 ( V_190 , L_54 , & V_194 ) ;
if ( V_194 ) {
V_8 -> V_28 = F_83 ( V_27 , sizeof( char * )
* ( V_194 + 1 ) , V_176 ) ;
if ( V_8 -> V_28 ) {
int V_6 ;
for ( V_6 = 0 ; V_6 < V_194 ; V_6 ++ )
F_92 ( V_190 , L_55 ,
V_6 , & V_8 -> V_28 [ V_6 ] ) ;
} else {
return F_89 ( - V_177 ) ;
}
}
F_90 ( V_190 , L_56 , & V_8 -> V_196 ) ;
F_90 ( V_190 , L_57 , & V_8 -> V_186 ) ;
F_91 ( V_190 , L_58 , & V_8 -> V_83 ) ;
if ( F_93 ( V_190 , L_59 , NULL ) )
V_8 -> V_83 *= - 1 ;
F_91 ( V_190 , L_60 , & V_8 -> V_82 ) ;
F_91 ( V_190 , L_61 , & V_8 -> V_84 ) ;
F_91 ( V_190 , L_62 ,
& V_8 -> V_74 ) ;
F_91 ( V_190 , L_63 ,
& V_8 -> V_75 ) ;
V_8 -> V_49 = F_94 ( V_190 ) ;
if ( V_8 -> V_49 ) {
struct V_161 * V_197 ;
struct V_189 * V_198 ;
V_197 = F_83 ( V_27 , sizeof( * V_197 )
* V_8 -> V_49 ,
V_176 ) ;
if ( ! V_197 )
return F_89 ( - V_177 ) ;
V_8 -> V_50 = V_197 ;
F_95 (np, child) {
struct V_145 * V_164 ;
struct V_189 * V_199 ;
F_90 ( V_198 , L_64 ,
& V_197 -> V_53 ) ;
V_197 -> V_163 = F_94 ( V_198 ) ;
if ( V_197 -> V_163 ) {
V_164 = F_83 ( V_27 , sizeof( * V_164 )
* V_197 -> V_163 ,
V_176 ) ;
if ( ! V_164 )
return F_89 ( - V_177 ) ;
V_197 -> V_164 = V_164 ;
F_95 (child, _child) {
F_90 ( V_199 ,
L_65 , & V_164 -> V_152 ) ;
F_90 ( V_199 ,
L_66 ,
& V_164 -> V_160 ) ;
F_91 ( V_199 ,
L_67 ,
& V_164 -> V_149 ) ;
F_91 ( V_199 ,
L_68 ,
& V_164 -> V_150 ) ;
V_164 ++ ;
}
}
V_197 ++ ;
}
}
return V_8 ;
}
static inline struct V_33 * F_96 ( struct V_200 * V_201 )
{
if ( V_201 -> V_27 . V_191 )
return F_88 ( & V_201 -> V_27 ) ;
return (struct V_33 * ) F_97 ( & V_201 -> V_27 ) ;
}
static int F_98 ( struct V_200 * V_201 )
{
struct V_33 * V_8 = F_96 ( V_201 ) ;
struct V_1 * V_2 ;
int V_7 = 0 , V_6 = 0 ;
int V_162 = 0 ;
union V_3 V_4 ;
if ( V_135 && ! V_124 && V_135 -> V_144 ) {
V_124 = F_64 ( V_135 -> V_144 ) ;
if ( F_65 ( V_124 ) ) {
V_124 = NULL ;
F_22 ( & V_201 -> V_27 , L_69 ,
V_135 -> V_144 ) ;
return - V_22 ;
}
}
if ( ! V_8 ) {
F_22 ( & V_201 -> V_27 , L_70 ) ;
return - V_22 ;
}
V_2 = F_83 ( & V_201 -> V_27 ,
sizeof( struct V_1 ) , V_176 ) ;
if ( ! V_2 )
return - V_177 ;
V_2 -> V_27 = & V_201 -> V_27 ;
V_2 -> V_8 = V_8 ;
if ( V_8 -> V_36 == 0 ) {
F_18 ( & V_201 -> V_27 , L_71 ) ;
}
if ( ! V_8 -> V_70 || ! V_8 -> V_69 ) {
F_18 ( & V_201 -> V_27 , L_72 ) ;
V_8 -> V_70 = 0 ;
V_8 -> V_69 = 0 ;
}
if ( V_8 -> V_37 == 0 ) {
F_18 ( & V_201 -> V_27 , L_73 ) ;
}
if ( V_8 -> V_34 == 0 ) {
F_18 ( & V_201 -> V_27 , L_74 ) ;
}
if ( ! V_8 -> V_50 || V_8 -> V_49 < 1 ) {
F_22 ( & V_201 -> V_27 , L_75 ) ;
return - V_120 ;
}
if ( ! V_8 -> V_28 || ! V_8 -> V_28 [ 0 ] ) {
F_22 ( & V_201 -> V_27 , L_76 ) ;
return - V_120 ;
}
while ( V_8 -> V_28 [ V_6 ] )
V_6 ++ ;
V_2 -> V_18 = F_83 ( & V_201 -> V_27 ,
sizeof( struct V_107 * ) * V_6 , V_176 ) ;
if ( ! V_2 -> V_18 )
return - V_177 ;
for ( V_6 = 0 ; V_8 -> V_28 [ V_6 ] ; V_6 ++ ) {
V_2 -> V_18 [ V_6 ] = F_99 (
V_8 -> V_28 [ V_6 ] ) ;
if ( ! V_2 -> V_18 [ V_6 ] ) {
F_22 ( & V_201 -> V_27 , L_77 ,
V_8 -> V_28 [ V_6 ] ) ;
return - V_22 ;
}
}
V_2 -> V_13 = F_99 ( V_8 -> V_196 ) ;
if ( ! V_2 -> V_13 ) {
F_22 ( & V_201 -> V_27 , L_77 ,
V_8 -> V_196 ) ;
return - V_22 ;
}
if ( V_8 -> V_96 == 0 ||
F_35 ( V_8 -> V_96 ) <= V_98 ) {
F_22 ( & V_201 -> V_27 , L_78 ) ;
return - V_120 ;
}
if ( ! V_8 -> V_74 ||
! V_8 -> V_75 ) {
F_18 ( & V_201 -> V_27 , L_79 ) ;
V_8 -> V_74 = 0 ;
V_8 -> V_75 = 0 ;
}
F_100 ( V_201 , V_2 ) ;
memcpy ( & V_2 -> V_111 , & V_202 , sizeof( V_202 ) ) ;
if ( ! V_8 -> V_195 )
strncpy ( V_2 -> V_203 , V_202 . V_152 , V_204 ) ;
else
strncpy ( V_2 -> V_203 , V_8 -> V_195 , V_204 ) ;
V_2 -> V_111 . V_152 = V_2 -> V_203 ;
V_2 -> V_111 . V_183 = F_83 ( & V_201 -> V_27 ,
sizeof( enum V_109 )
* ( F_101 ( V_205 ) +
V_206 ) , V_176 ) ;
if ( ! V_2 -> V_111 . V_183 )
return - V_177 ;
memcpy ( V_2 -> V_111 . V_183 , V_205 ,
sizeof( enum V_109 ) *
F_101 ( V_205 ) ) ;
V_2 -> V_111 . V_184 = V_202 . V_184 ;
if ( ! V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_119 , & V_4 ) ) {
V_2 -> V_111 . V_183 [ V_2 -> V_111 . V_184 ] =
V_119 ;
V_2 -> V_111 . V_184 ++ ;
}
if ( ! V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_117 ,
& V_4 ) ) {
V_2 -> V_111 . V_183 [ V_2 -> V_111 . V_184 ] =
V_117 ;
V_2 -> V_111 . V_184 ++ ;
}
V_7 = F_86 ( V_2 ) ;
if ( V_7 ) {
F_22 ( & V_201 -> V_27 , L_80 ) ;
V_2 -> V_8 -> V_77 = false ;
}
F_102 ( & V_2 -> V_65 , F_19 ) ;
V_7 = F_103 ( NULL , & V_2 -> V_111 ) ;
if ( V_7 ) {
F_22 ( & V_201 -> V_27 , L_81 ,
V_2 -> V_111 . V_152 ) ;
return V_7 ;
}
V_7 = F_74 ( V_2 ) ;
if ( V_7 < 0 ) {
F_22 ( & V_201 -> V_27 , L_82 ) ;
goto V_207;
}
V_7 = F_82 ( V_2 ) ;
if ( V_7 < 0 ) {
F_22 ( & V_201 -> V_27 ,
L_83 ) ;
goto V_208;
}
F_31 ( & V_91 ) ;
F_104 ( & V_2 -> V_209 , & V_210 ) ;
F_33 ( & V_91 ) ;
F_105 ( & V_201 -> V_27 , true ) ;
F_43 ( & V_201 -> V_27 , false ) ;
F_41 ( & V_104 ) ;
return 0 ;
V_208:
for ( V_6 = 0 ; V_6 < V_8 -> V_49 ; V_6 ++ ) {
struct V_161 * V_151 ;
V_151 = & V_8 -> V_50 [ V_6 ] ;
F_106 ( & V_2 -> V_111 . V_27 -> V_59 ,
& V_151 -> V_179 ) ;
}
V_207:
for ( V_6 = 0 ; V_6 < V_8 -> V_49 ; V_6 ++ ) {
struct V_161 * V_151 ;
V_151 = & V_8 -> V_50 [ V_6 ] ;
for ( V_162 = 0 ; V_162 < V_151 -> V_163 ; V_162 ++ ) {
struct V_145 * V_146 = & V_151 -> V_164 [ V_162 ] ;
if ( V_146 -> V_159 . V_211 )
F_107 ( & V_146 -> V_159 ) ;
}
F_108 ( V_8 -> V_50 [ V_6 ] . V_52 ) ;
}
F_109 ( & V_2 -> V_111 ) ;
return V_7 ;
}
static int F_110 ( struct V_200 * V_201 )
{
struct V_1 * V_2 = F_111 ( V_201 ) ;
struct V_33 * V_8 = V_2 -> V_8 ;
int V_6 = 0 ;
int V_162 = 0 ;
F_31 ( & V_91 ) ;
F_112 ( & V_2 -> V_209 ) ;
F_33 ( & V_91 ) ;
F_70 ( & V_104 ) ;
F_113 ( & V_103 ) ;
for ( V_6 = 0 ; V_6 < V_8 -> V_49 ; V_6 ++ ) {
struct V_161 * V_151
= & V_8 -> V_50 [ V_6 ] ;
for ( V_162 = 0 ; V_162 < V_151 -> V_163 ; V_162 ++ ) {
struct V_145 * V_146 = & V_151 -> V_164 [ V_162 ] ;
F_107 ( & V_146 -> V_159 ) ;
}
}
for ( V_6 = 0 ; V_6 < V_8 -> V_49 ; V_6 ++ )
F_108 ( V_8 -> V_50 [ V_6 ] . V_52 ) ;
F_109 ( & V_2 -> V_111 ) ;
F_8 ( V_2 , false ) ;
return 0 ;
}
static int F_114 ( struct V_165 * V_27 )
{
int V_7 = 0 ;
if ( F_115 ( V_27 ) ) {
F_43 ( V_27 , false ) ;
V_7 = - V_46 ;
}
return V_7 ;
}
static int F_116 ( struct V_165 * V_27 )
{
struct V_1 * V_2 = F_117 ( V_27 ) ;
if ( ! V_58 ) {
if ( V_124 ) {
struct V_141 V_126 ;
unsigned long V_127 ;
F_118 ( V_124 , & V_131 ) ;
F_54 ( V_124 , & V_126 ) ;
if ( V_131 . V_129 ) {
F_55 ( & V_131 . time ,
& V_132 ) ;
F_55 ( & V_126 , & V_127 ) ;
if ( V_127 > V_132 )
V_132 = 0 ;
} else {
V_132 = 0 ;
}
}
V_58 = true ;
}
F_119 ( & V_2 -> V_65 ) ;
V_2 -> V_139 = F_2 ( V_2 ) ;
V_2 -> V_140 = F_1 ( V_2 ) ;
if ( ! V_138 ) {
V_133 = 0 ;
V_138 = F_48 () ;
}
return 0 ;
}
static void F_120 ( struct V_165 * V_27 )
{
struct V_1 * V_2 = F_117 ( V_27 ) ;
if ( V_58 ) {
if ( V_124 ) {
struct V_125 V_126 ;
F_118 ( V_124 , & V_126 ) ;
V_131 . V_212 = V_126 . V_212 ;
F_57 ( V_124 , & V_131 ) ;
}
V_58 = false ;
V_138 = false ;
}
if ( V_2 -> V_68 ) {
unsigned long V_213 = 0 ;
unsigned long V_127 = V_101 + V_98 ;
if ( F_59 ( V_127 , V_2 -> V_68 ) ) {
V_213 = ( unsigned long ) ( ( long ) V_127
- ( long ) ( V_2 -> V_68 ) ) ;
V_213 = F_49 ( V_213 ) ;
} else {
V_213 = 0 ;
}
if ( V_135 && V_135 -> V_136 ) {
if ( V_213 > V_133 )
V_213 -= V_133 ;
else
V_213 = 0 ;
}
F_39 ( V_100 , & V_2 -> V_65 ,
F_35 ( V_213 ) ) ;
}
F_43 ( V_2 -> V_27 , false ) ;
F_16 ( V_2 , NULL ) ;
}
static int T_5 F_121 ( void )
{
V_100 = F_122 ( L_84 ) ;
F_102 ( & V_103 , F_40 ) ;
return F_123 ( & V_214 ) ;
}
static void T_6 F_124 ( void )
{
F_125 ( V_100 ) ;
V_100 = NULL ;
F_126 ( & V_214 ) ;
}
static bool F_127 ( struct V_1 * V_2 ,
struct V_107 * V_108 )
{
int V_6 ;
bool V_215 = false ;
for ( V_6 = 0 ; V_2 -> V_18 [ V_6 ] ; V_6 ++ ) {
if ( V_108 == V_2 -> V_18 [ V_6 ] ) {
V_215 = true ;
break;
}
}
return V_215 ;
}
void F_128 ( struct V_107 * V_108 , enum V_106 type ,
char * V_216 )
{
struct V_1 * V_2 ;
bool V_217 = false ;
if ( V_108 == NULL )
return;
F_31 ( & V_91 ) ;
F_32 (cm, &cm_list, entry) {
V_217 = F_127 ( V_2 , V_108 ) ;
if ( V_217 )
break;
}
F_33 ( & V_91 ) ;
if ( ! V_217 )
return;
switch ( type ) {
case V_89 :
F_42 ( V_2 ) ;
break;
case V_105 :
F_44 ( V_2 ) ;
break;
case V_218 :
case V_219 ... V_220 :
F_46 ( V_2 , type ) ;
break;
case V_221 :
case V_222 :
F_16 ( V_2 , V_216 ? V_216 : V_88 [ type ] ) ;
break;
default:
F_22 ( V_2 -> V_27 , L_85 , V_71 ) ;
break;
}
}

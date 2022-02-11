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
if ( ! F_1 ( V_2 ) ) {
V_4 . V_16 = 0 ;
goto V_34;
}
if ( V_2 -> V_13 && V_8 -> V_35 > 0 ) {
V_7 = V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_36 , & V_4 ) ;
if ( ! V_7 && V_4 . V_16 > V_8 -> V_35 ) {
V_4 . V_16 = 1 ;
goto V_34;
}
}
if ( V_8 -> V_37 > 0 ) {
V_7 = F_3 ( V_2 , & V_21 ) ;
if ( ! V_7 && V_21 >= V_8 -> V_37 ) {
V_4 . V_16 = 1 ;
goto V_34;
}
}
if ( V_2 -> V_13 && V_8 -> V_38 > 0 ) {
V_7 = V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_39 , & V_4 ) ;
if ( ! V_7 && V_4 . V_16 >= V_8 -> V_38 ) {
V_4 . V_16 = 1 ;
goto V_34;
}
}
V_4 . V_16 = 0 ;
V_34:
return V_4 . V_16 ? true : false ;
}
static bool F_7 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 -> V_40 ) {
case V_41 :
return false ;
case V_42 :
return true ;
case V_43 :
return F_2 ( V_2 ) ;
case V_44 :
return F_4 ( V_2 ) ;
default:
F_5 ( V_2 -> V_27 , L_3 ,
V_2 -> V_8 -> V_40 ) ;
}
return false ;
}
static int F_8 ( struct V_1 * V_2 , bool V_45 )
{
int V_46 = 0 , V_6 ;
struct V_33 * V_8 = V_2 -> V_8 ;
if ( V_45 == V_2 -> V_26 )
return 0 ;
if ( V_45 ) {
if ( V_2 -> V_25 )
return - V_47 ;
V_2 -> V_48 = F_9 ( F_10 () ) ;
V_2 -> V_49 = 0 ;
for ( V_6 = 0 ; V_6 < V_8 -> V_50 ; V_6 ++ ) {
if ( V_8 -> V_51 [ V_6 ] . V_52 )
continue;
V_46 = F_11 ( V_8 -> V_51 [ V_6 ] . V_53 ) ;
if ( V_46 < 0 ) {
F_5 ( V_2 -> V_27 ,
L_4 ,
V_8 -> V_51 [ V_6 ] . V_54 ) ;
}
}
} else {
V_2 -> V_48 = 0 ;
V_2 -> V_49 = F_9 ( F_10 () ) ;
for ( V_6 = 0 ; V_6 < V_8 -> V_50 ; V_6 ++ ) {
if ( V_8 -> V_51 [ V_6 ] . V_52 )
continue;
V_46 = F_12 ( V_8 -> V_51 [ V_6 ] . V_53 ) ;
if ( V_46 < 0 ) {
F_5 ( V_2 -> V_27 ,
L_5 ,
V_8 -> V_51 [ V_6 ] . V_54 ) ;
}
}
for ( V_6 = 0 ; V_6 < V_8 -> V_50 ; V_6 ++ ) {
if ( F_13 (
V_8 -> V_51 [ V_6 ] . V_53 ) ) {
F_14 (
V_8 -> V_51 [ V_6 ] . V_53 ) ;
F_5 ( V_2 -> V_27 ,
L_6 ,
V_8 -> V_51 [ V_6 ] . V_54 ) ;
}
}
}
if ( ! V_46 )
V_2 -> V_26 = V_45 ;
return V_46 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_46 ;
if ( V_2 -> V_25 )
return - V_47 ;
V_46 = F_8 ( V_2 , false ) ;
if ( V_46 )
return V_46 ;
return F_8 ( V_2 , true ) ;
}
static void F_16 ( struct V_1 * V_2 , const char * V_55 )
{
static char V_56 [ V_57 + 1 ] = L_7 ;
static char V_58 [ V_57 + 1 ] = L_7 ;
if ( V_59 ) {
if ( V_58 [ 0 ] == 0 ) {
if ( ! strncmp ( V_56 , V_55 , V_57 ) )
return;
strncpy ( V_58 , V_55 , V_57 ) ;
return;
}
if ( ! strncmp ( V_58 , V_55 , V_57 ) )
return;
strncpy ( V_58 , V_55 , V_57 ) ;
return;
}
if ( V_55 == NULL ) {
if ( ! V_58 [ 0 ] )
return;
strncpy ( V_56 , V_58 , V_57 ) ;
F_17 ( & V_2 -> V_27 -> V_60 , V_61 ) ;
V_58 [ 0 ] = 0 ;
return;
}
if ( ! strncmp ( V_56 , V_55 , V_57 ) )
return;
strncpy ( V_56 , V_55 , V_57 ) ;
F_17 ( & V_2 -> V_27 -> V_60 , V_61 ) ;
F_18 ( V_2 -> V_27 , V_55 ) ;
}
static void F_19 ( struct V_62 * V_63 )
{
struct V_64 * V_65 = F_20 ( V_63 ) ;
struct V_1 * V_2 = F_21 ( V_65 ,
struct V_1 , V_66 ) ;
struct V_33 * V_8 = V_2 -> V_8 ;
int V_67 , V_46 , V_68 ;
V_2 -> V_69 = 0 ;
if ( ! V_8 -> V_70 || ! V_8 -> V_71 )
return;
V_46 = F_3 ( V_2 , & V_67 ) ;
if ( V_46 ) {
F_22 ( V_2 -> V_27 , L_8 , V_72 , V_46 ) ;
return;
}
V_68 = V_8 -> V_37 ;
V_68 -= V_67 ;
F_18 ( V_2 -> V_27 , L_9 , V_68 ) ;
if ( V_68 > V_8 -> V_70 ) {
F_15 ( V_2 ) ;
F_16 ( V_2 , L_10 ) ;
}
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_33 * V_8 = V_2 -> V_8 ;
T_1 V_73 = F_9 ( F_10 () ) ;
T_1 V_74 ;
int V_7 = false ;
if ( ! V_8 -> V_75 &&
! V_8 -> V_76 )
return V_7 ;
if ( V_2 -> V_26 ) {
V_74 = V_73 - V_2 -> V_48 ;
if ( V_74 > V_8 -> V_75 ) {
F_18 ( V_2 -> V_27 , L_11 ,
V_8 -> V_75 ) ;
F_16 ( V_2 , L_12 ) ;
F_8 ( V_2 , false ) ;
V_7 = true ;
}
} else if ( F_2 ( V_2 ) && ! V_2 -> V_26 ) {
V_74 = V_73 - V_2 -> V_49 ;
if ( V_74 > V_8 -> V_75 &&
F_2 ( V_2 ) ) {
F_18 ( V_2 -> V_27 , L_13 ,
V_8 -> V_76 ) ;
F_16 ( V_2 , L_14 ) ;
F_8 ( V_2 , true ) ;
V_7 = true ;
}
}
return V_7 ;
}
static bool F_24 ( struct V_1 * V_2 )
{
struct V_33 * V_8 = V_2 -> V_8 ;
int V_77 = V_8 -> V_78 ( & V_2 -> V_79 ) ;
F_25 ( V_2 -> V_27 , L_15 ,
V_2 -> V_79 / 1000 , V_2 -> V_79 % 1000 ) ;
if ( V_77 && V_2 -> V_25 )
return false ;
if ( V_77 ) {
V_2 -> V_25 = V_77 ;
if ( ! F_8 ( V_2 , false ) ) {
if ( V_77 > 0 )
F_16 ( V_2 , L_16 ) ;
else
F_16 ( V_2 , L_17 ) ;
}
} else if ( ! V_2 -> V_25 && F_23 ( V_2 ) ) {
F_25 ( V_2 -> V_27 ,
L_18 ) ;
} else if ( ! V_2 -> V_25 && F_2 ( V_2 ) &&
! V_2 -> V_26 ) {
F_19 ( & V_2 -> V_66 . V_63 ) ;
} else if ( ! V_2 -> V_25 && F_6 ( V_2 ) &&
V_2 -> V_26 ) {
F_18 ( V_2 -> V_27 , L_19 ) ;
F_16 ( V_2 , V_80 [ V_81 ] ) ;
F_8 ( V_2 , false ) ;
F_19 ( & V_2 -> V_66 . V_63 ) ;
} else {
V_2 -> V_25 = 0 ;
if ( F_2 ( V_2 ) ) {
if ( ! F_8 ( V_2 , true ) )
F_16 ( V_2 , L_20 ) ;
}
}
return true ;
}
static bool F_26 ( void )
{
bool V_82 = false ;
struct V_1 * V_2 ;
F_27 ( & V_83 ) ;
F_28 (cm, &cm_list, entry) {
if ( F_24 ( V_2 ) )
V_82 = true ;
}
F_29 ( & V_83 ) ;
return V_82 ;
}
static void F_30 ( struct V_62 * V_63 )
{
unsigned long V_84 = V_85 ;
struct V_1 * V_2 ;
bool V_86 = false ;
unsigned long V_87 ;
F_27 ( & V_83 ) ;
F_28 (cm, &cm_list, entry) {
if ( F_7 ( V_2 ) && V_2 -> V_8 -> V_88 ) {
V_86 = true ;
if ( V_84 > V_2 -> V_8 -> V_88 )
V_84 = V_2 -> V_8 -> V_88 ;
}
}
V_89 = F_31 ( V_84 ) ;
if ( V_89 <= V_90 )
V_89 = V_90 + 1 ;
if ( ! V_86 )
V_89 = V_85 ;
if ( V_89 == V_85 )
goto V_34;
F_32 ( V_91 == NULL , L_21
L_22 , V_72 ) ;
V_87 = V_92 + V_89 ;
if ( ! F_33 ( & V_93 ) ||
( F_33 ( & V_93 ) &&
F_34 ( V_94 , V_87 ) ) ) {
V_94 = V_92 + V_89 ;
F_35 ( V_91 , & V_93 , V_89 ) ;
}
V_34:
F_29 ( & V_83 ) ;
}
static void F_36 ( struct V_62 * V_63 )
{
F_26 () ;
F_37 ( & V_95 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_33 * V_8 = V_2 -> V_8 ;
if ( ! V_8 -> V_70 || ! V_8 -> V_71 )
goto V_34;
if ( V_59 )
F_39 ( V_2 -> V_27 , true ) ;
F_35 ( V_91 , & V_2 -> V_66 ,
F_31 ( V_8 -> V_71 ) ) ;
V_2 -> V_69 = V_92 + F_31 (
V_8 -> V_71 ) ;
if ( V_2 -> V_69 == 0 )
V_2 -> V_69 = 1 ;
V_34:
F_18 ( V_2 -> V_27 , L_19 ) ;
F_16 ( V_2 , V_80 [ V_81 ] ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
if ( V_59 )
F_39 ( V_2 -> V_27 , true ) ;
if ( ! F_1 ( V_2 ) ) {
F_41 ( V_2 -> V_27 , L_23 ) ;
F_16 ( V_2 , V_80 [ V_96 ] ) ;
} else {
F_16 ( V_2 , L_24 ) ;
}
}
static void F_42 ( struct V_1 * V_2 ,
enum V_97 type )
{
if ( V_59 )
F_39 ( V_2 -> V_27 , true ) ;
if ( ! F_33 ( & V_93 ) &&
F_7 ( V_2 ) && V_2 -> V_8 -> V_88 )
F_37 ( & V_95 ) ;
F_16 ( V_2 , V_80 [ type ] ) ;
}
static int F_43 ( struct V_98 * V_99 ,
enum V_100 V_101 ,
union V_3 * V_4 )
{
struct V_1 * V_2 = F_21 ( V_99 ,
struct V_1 , V_102 ) ;
struct V_33 * V_8 = V_2 -> V_8 ;
int V_7 = 0 ;
int V_21 ;
switch ( V_101 ) {
case V_29 :
if ( F_4 ( V_2 ) )
V_4 -> V_16 = V_103 ;
else if ( F_2 ( V_2 ) )
V_4 -> V_16 = V_32 ;
else
V_4 -> V_16 = V_31 ;
break;
case V_104 :
if ( V_2 -> V_25 > 0 )
V_4 -> V_16 = V_105 ;
else if ( V_2 -> V_25 < 0 )
V_4 -> V_16 = V_106 ;
else
V_4 -> V_16 = V_107 ;
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
case V_108 :
V_7 = V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_108 , V_4 ) ;
break;
case V_109 :
if ( V_2 -> V_79 == V_110 )
V_8 -> V_78 ( & V_2 -> V_79 ) ;
V_4 -> V_16 = V_2 -> V_79 / 100 ;
if ( ! V_8 -> V_111 )
V_7 = - V_22 ;
break;
case V_112 :
if ( V_2 -> V_79 == V_110 )
V_8 -> V_78 ( & V_2 -> V_79 ) ;
V_4 -> V_16 = V_2 -> V_79 / 100 ;
if ( V_8 -> V_111 )
V_7 = - V_22 ;
break;
case V_39 :
if ( ! V_2 -> V_13 ) {
V_7 = - V_22 ;
break;
}
if ( ! F_1 ( V_2 ) ) {
V_4 -> V_16 = 100 ;
break;
}
V_7 = V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_39 , V_4 ) ;
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
if ( V_8 -> V_37 > 0 && V_21 >= V_8 -> V_37 &&
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
case V_36 :
if ( F_6 ( V_2 ) )
V_4 -> V_16 = 1 ;
else
V_4 -> V_16 = 0 ;
V_7 = 0 ;
break;
case V_113 :
if ( F_4 ( V_2 ) ) {
V_7 = V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_113 ,
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
return - V_114 ;
}
return V_7 ;
}
static bool F_44 ( void )
{
struct V_1 * V_2 ;
unsigned int V_115 = V_116 ;
bool V_7 = false ;
F_27 ( & V_83 ) ;
F_28 (cm, &cm_list, entry) {
unsigned int V_117 = 0 ;
if ( V_2 -> V_69 ) {
V_117 = F_45 ( V_2 -> V_69
- V_92 ) ;
if ( F_46 (
V_2 -> V_69 ) ||
F_31 ( V_117 ) < V_90 ) {
F_19 ( & V_2 -> V_66 . V_63 ) ;
V_117 = 0 ;
}
}
F_47 ( V_115 , V_117 ) ;
if ( ! F_7 ( V_2 ) && ! V_2 -> V_25 )
continue;
if ( V_2 -> V_8 -> V_88 == 0 )
continue;
F_47 ( V_115 , V_2 -> V_8 -> V_88 ) ;
}
F_29 ( & V_83 ) ;
if ( V_115 < V_116 && V_115 > 0 ) {
F_48 ( L_25 , V_115 ) ;
if ( V_118 ) {
struct V_119 V_120 ;
unsigned long time , V_121 ;
unsigned long V_122 = F_49 ( V_115 , 1000 ) ;
V_120 . V_123 = 1 ;
F_50 ( V_118 , & V_120 . time ) ;
F_51 ( & V_120 . time , & V_121 ) ;
if ( V_122 < V_124 )
V_122 = V_124 ;
time = V_121 + V_122 ;
V_7 = true ;
if ( V_125 . V_123 &&
V_126 &&
V_126 < time ) {
if ( V_126 < V_121 + V_124 )
time = V_121 + V_124 ;
else
time = V_126 ;
V_7 = false ;
}
F_48 ( L_26 ,
time - V_121 ) ;
F_52 ( time , & V_120 . time ) ;
F_53 ( V_118 , & V_120 ) ;
V_127 += V_115 ;
return V_7 ;
}
}
if ( V_118 )
F_53 ( V_118 , & V_125 ) ;
return false ;
}
static void F_54 ( struct V_1 * V_2 )
{
unsigned long V_128 = V_92 ;
if ( ! V_2 -> V_69 )
return;
if ( V_129 && V_129 -> V_130 )
V_128 += F_31 ( V_127 ) ;
V_128 += V_90 ;
if ( F_55 ( V_128 , V_2 -> V_69 ) )
F_19 ( & V_2 -> V_66 . V_63 ) ;
}
bool F_56 ( void )
{
struct V_1 * V_2 ;
bool V_7 = false ;
if ( ! V_129 || ! V_129 -> V_131 || ! V_129 -> V_131 () ||
! V_132 )
return false ;
if ( F_26 () )
goto V_34;
V_7 = true ;
F_27 ( & V_83 ) ;
F_28 (cm, &cm_list, entry) {
F_54 ( V_2 ) ;
if ( V_2 -> V_133 != F_2 ( V_2 ) ||
V_2 -> V_134 != F_1 ( V_2 ) ) {
V_7 = false ;
break;
}
}
F_29 ( & V_83 ) ;
V_132 = F_44 () ;
V_34:
if ( V_125 . V_123 ) {
unsigned long V_121 ;
struct V_135 V_120 ;
F_50 ( V_118 , & V_120 ) ;
F_51 ( & V_120 , & V_121 ) ;
if ( V_126 &&
V_121 + V_124 >= V_126 )
return false ;
}
return V_7 ;
}
int F_57 ( struct V_136 * V_137 )
{
if ( ! V_137 )
return - V_114 ;
if ( V_118 )
F_58 ( V_118 ) ;
V_118 = NULL ;
V_129 = NULL ;
if ( ! V_137 -> V_131 ) {
F_59 ( L_27 ) ;
return - V_114 ;
}
if ( V_137 -> V_138 ) {
V_118 = F_60 ( V_137 -> V_138 ) ;
if ( F_61 ( V_118 ) ) {
V_118 = NULL ;
}
} else {
F_62 ( L_28
L_29 ) ;
}
V_129 = V_137 ;
return 0 ;
}
static void F_63 ( struct V_62 * V_63 )
{
struct V_139 * V_140 =
F_21 ( V_63 , struct V_139 , V_141 ) ;
int V_7 ;
if ( V_140 -> V_142 && V_140 -> V_143 != 0 && V_140 -> V_144 != 0 ) {
V_7 = F_64 ( V_140 -> V_145 -> V_53 ,
V_140 -> V_143 , V_140 -> V_144 ) ;
if ( V_7 < 0 ) {
F_59 ( L_30 ,
V_140 -> V_145 -> V_54 , V_140 -> V_146 ) ;
return;
}
F_48 ( L_31 ,
V_140 -> V_145 -> V_54 ,
V_140 -> V_143 , V_140 -> V_144 ) ;
}
F_8 ( V_140 -> V_2 , V_140 -> V_142 ) ;
}
static int F_65 ( struct V_147 * V_148 ,
unsigned long V_55 , void * V_149 )
{
struct V_139 * V_140 =
F_21 ( V_148 , struct V_139 , V_150 ) ;
V_140 -> V_142 = V_55 ;
if ( V_140 -> V_142 && F_7 ( V_140 -> V_2 ) ) {
if ( F_66 ( & V_95 ) )
F_67 ( & V_95 ) ;
F_37 ( & V_95 ) ;
}
F_37 ( & V_140 -> V_141 ) ;
return V_151 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_139 * V_140 )
{
int V_7 = 0 ;
F_69 ( & V_140 -> V_141 , F_63 ) ;
V_140 -> V_150 . V_152 = F_65 ;
V_7 = F_70 ( & V_140 -> V_153 ,
V_140 -> V_154 , V_140 -> V_146 , & V_140 -> V_150 ) ;
if ( V_7 < 0 ) {
F_48 ( L_32 ,
V_140 -> V_154 ,
V_140 -> V_146 ) ;
V_7 = - V_114 ;
}
return V_7 ;
}
static T_2 F_71 ( struct V_155 * V_27 ,
struct V_156 * V_157 , char * V_158 )
{
struct V_159 * V_145
= F_21 ( V_157 , struct V_159 , V_160 ) ;
return sprintf ( V_158 , L_33 , V_145 -> V_54 ) ;
}
static T_2 F_72 ( struct V_155 * V_27 ,
struct V_156 * V_157 , char * V_158 )
{
struct V_159 * V_145
= F_21 ( V_157 , struct V_159 , V_161 ) ;
int V_162 = 0 ;
if ( ! V_145 -> V_52 )
V_162 = F_13 ( V_145 -> V_53 ) ;
return sprintf ( V_158 , L_33 , V_162 ? L_34 : L_35 ) ;
}
static T_2 F_73 ( struct V_155 * V_27 ,
struct V_156 * V_157 , char * V_158 )
{
struct V_159 * V_145 = F_21 ( V_157 ,
struct V_159 , V_163 ) ;
return sprintf ( V_158 , L_36 , V_145 -> V_52 ) ;
}
static T_2 F_74 ( struct V_155 * V_27 ,
struct V_156 * V_157 , const char * V_158 ,
T_3 V_164 )
{
struct V_159 * V_145
= F_21 ( V_157 , struct V_159 ,
V_163 ) ;
struct V_1 * V_2 = V_145 -> V_2 ;
struct V_33 * V_8 = V_2 -> V_8 ;
int V_6 ;
int V_7 ;
int V_52 ;
int V_165 = 1 ;
V_7 = sscanf ( V_158 , L_37 , & V_52 ) ;
if ( V_7 == 0 ) {
V_7 = - V_114 ;
return V_7 ;
}
if ( ! V_52 ) {
V_145 -> V_52 = 0 ;
return V_164 ;
}
for ( V_6 = 0 ; V_6 < V_8 -> V_50 ; V_6 ++ ) {
if ( & V_8 -> V_51 [ V_6 ] != V_145 &&
! V_8 -> V_51 [ V_6 ] . V_52 ) {
V_165 = 0 ;
break;
}
}
if ( ! V_165 ) {
if ( V_2 -> V_26 ) {
F_8 ( V_145 -> V_2 , false ) ;
V_145 -> V_52 = V_52 ;
F_8 ( V_145 -> V_2 , true ) ;
} else {
V_145 -> V_52 = V_52 ;
}
} else {
F_5 ( V_2 -> V_27 ,
L_38
L_39
L_40 ,
V_145 -> V_54 ) ;
}
return V_164 ;
}
static int F_75 ( struct V_166 * V_167 )
{
struct V_33 * V_8 = F_76 ( & V_167 -> V_27 ) ;
struct V_1 * V_2 ;
int V_7 = 0 , V_6 = 0 ;
int V_168 = 0 ;
int V_165 = 1 ;
union V_3 V_4 ;
if ( V_129 && ! V_118 && V_129 -> V_138 ) {
V_118 = F_60 ( V_129 -> V_138 ) ;
if ( F_61 ( V_118 ) ) {
V_118 = NULL ;
F_22 ( & V_167 -> V_27 , L_41 ,
V_129 -> V_138 ) ;
V_7 = - V_22 ;
goto V_169;
}
}
if ( ! V_8 ) {
F_22 ( & V_167 -> V_27 , L_42 ) ;
V_7 = - V_22 ;
goto V_169;
}
V_2 = F_77 ( sizeof( struct V_1 ) , V_170 ) ;
if ( ! V_2 ) {
F_22 ( & V_167 -> V_27 , L_43 ) ;
V_7 = - V_171 ;
goto V_169;
}
V_2 -> V_27 = & V_167 -> V_27 ;
V_2 -> V_8 = F_77 ( sizeof( struct V_33 ) , V_170 ) ;
if ( ! V_2 -> V_8 ) {
F_22 ( & V_167 -> V_27 , L_43 ) ;
V_7 = - V_171 ;
goto V_172;
}
memcpy ( V_2 -> V_8 , V_8 , sizeof( struct V_33 ) ) ;
V_2 -> V_79 = V_110 ;
if ( V_8 -> V_37 == 0 ) {
F_18 ( & V_167 -> V_27 , L_44
L_45 ) ;
}
if ( ! V_8 -> V_71 || ! V_8 -> V_70 ) {
F_18 ( & V_167 -> V_27 , L_46
L_47 ) ;
V_8 -> V_71 = 0 ;
V_8 -> V_70 = 0 ;
}
if ( V_8 -> V_38 == 0 ) {
F_18 ( & V_167 -> V_27 , L_48
L_49
L_50 ) ;
}
if ( V_8 -> V_35 == 0 ) {
F_18 ( & V_167 -> V_27 , L_51
L_52 ) ;
}
if ( ! V_8 -> V_51 || V_8 -> V_50 < 1 ) {
V_7 = - V_114 ;
F_22 ( & V_167 -> V_27 , L_53 ) ;
goto V_173;
}
if ( ! V_8 -> V_28 || ! V_8 -> V_28 [ 0 ] ) {
F_22 ( & V_167 -> V_27 , L_54 ) ;
V_7 = - V_114 ;
goto V_174;
}
while ( V_8 -> V_28 [ V_6 ] )
V_6 ++ ;
V_2 -> V_18 = F_77 ( sizeof( struct V_98 * ) * ( V_6 + 1 ) ,
V_170 ) ;
if ( ! V_2 -> V_18 ) {
V_7 = - V_171 ;
goto V_174;
}
for ( V_6 = 0 ; V_8 -> V_28 [ V_6 ] ; V_6 ++ ) {
V_2 -> V_18 [ V_6 ] = F_78 (
V_8 -> V_28 [ V_6 ] ) ;
if ( ! V_2 -> V_18 [ V_6 ] ) {
F_22 ( & V_167 -> V_27 , L_55
L_56 ,
V_8 -> V_28 [ V_6 ] ) ;
V_7 = - V_22 ;
goto V_175;
}
}
V_2 -> V_13 = F_78 ( V_8 -> V_176 ) ;
if ( ! V_2 -> V_13 ) {
F_22 ( & V_167 -> V_27 , L_57 ,
V_8 -> V_176 ) ;
V_7 = - V_22 ;
goto V_175;
}
if ( V_8 -> V_88 == 0 ||
F_31 ( V_8 -> V_88 ) <= V_90 ) {
F_22 ( & V_167 -> V_27 , L_58 ) ;
V_7 = - V_114 ;
goto V_175;
}
if ( ! V_8 -> V_78 ) {
F_22 ( & V_167 -> V_27 , L_59 ) ;
V_7 = - V_114 ;
goto V_175;
}
if ( ! V_8 -> V_75 ||
! V_8 -> V_76 ) {
F_18 ( & V_167 -> V_27 , L_60
L_61
L_62 ) ;
V_8 -> V_75 = 0 ;
V_8 -> V_76 = 0 ;
}
F_79 ( V_167 , V_2 ) ;
memcpy ( & V_2 -> V_102 , & V_177 , sizeof( V_177 ) ) ;
if ( ! V_8 -> V_178 ) {
strncpy ( V_2 -> V_179 , V_177 . V_146 , V_180 ) ;
} else {
strncpy ( V_2 -> V_179 , V_8 -> V_178 , V_180 ) ;
}
V_2 -> V_102 . V_146 = V_2 -> V_179 ;
V_2 -> V_102 . V_181 = F_77 ( sizeof( enum V_100 )
* ( F_80 ( V_182 ) +
V_183 ) ,
V_170 ) ;
if ( ! V_2 -> V_102 . V_181 ) {
F_22 ( & V_167 -> V_27 , L_63 ) ;
V_7 = - V_171 ;
goto V_175;
}
memcpy ( V_2 -> V_102 . V_181 , V_182 ,
sizeof( enum V_100 ) *
F_80 ( V_182 ) ) ;
V_2 -> V_102 . V_184 = V_177 . V_184 ;
if ( ! V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_113 , & V_4 ) ) {
V_2 -> V_102 . V_181 [ V_2 -> V_102 . V_184 ] =
V_113 ;
V_2 -> V_102 . V_184 ++ ;
}
if ( ! V_2 -> V_13 -> V_14 ( V_2 -> V_13 ,
V_108 ,
& V_4 ) ) {
V_2 -> V_102 . V_181 [ V_2 -> V_102 . V_184 ] =
V_108 ;
V_2 -> V_102 . V_184 ++ ;
}
if ( V_8 -> V_111 ) {
V_2 -> V_102 . V_181 [ V_2 -> V_102 . V_184 ] =
V_109 ;
V_2 -> V_102 . V_184 ++ ;
} else {
V_2 -> V_102 . V_181 [ V_2 -> V_102 . V_184 ] =
V_112 ;
V_2 -> V_102 . V_184 ++ ;
}
F_81 ( & V_2 -> V_66 , F_19 ) ;
V_7 = F_82 ( NULL , & V_2 -> V_102 ) ;
if ( V_7 ) {
F_22 ( & V_167 -> V_27 , L_64
L_65 , V_2 -> V_102 . V_146 ) ;
goto V_185;
}
for ( V_6 = 0 ; V_6 < V_8 -> V_50 ; V_6 ++ ) {
struct V_159 * V_145
= & V_8 -> V_51 [ V_6 ] ;
char V_158 [ 11 ] ;
char * V_186 ;
V_145 -> V_53 = F_83 ( & V_167 -> V_27 ,
V_145 -> V_54 ) ;
if ( V_145 -> V_53 == NULL ) {
F_22 ( & V_167 -> V_27 , L_66 ,
V_145 -> V_54 ) ;
V_7 = - V_114 ;
goto V_187;
}
V_145 -> V_2 = V_2 ;
for ( V_168 = 0 ; V_168 < V_145 -> V_188 ; V_168 ++ ) {
struct V_139 * V_140 = & V_145 -> V_189 [ V_168 ] ;
V_7 = F_68 ( V_2 , V_140 ) ;
if ( V_7 < 0 ) {
F_22 ( & V_167 -> V_27 , L_66 ,
V_145 -> V_54 ) ;
goto V_190;
}
V_140 -> V_145 = V_145 ;
V_140 -> V_2 = V_2 ;
}
snprintf ( V_158 , 10 , L_67 , V_6 ) ;
V_186 = F_77 ( sizeof( char ) * ( strlen ( V_158 ) + 1 ) , V_170 ) ;
if ( ! V_186 ) {
for ( V_6 -- ; V_6 >= 0 ; V_6 -- ) {
V_145 = & V_8 -> V_51 [ V_6 ] ;
F_84 ( V_145 -> V_191 . V_146 ) ;
}
V_7 = - V_171 ;
goto V_190;
}
strcpy ( V_186 , V_158 ) ;
V_145 -> V_192 [ 0 ] = & V_145 -> V_160 . V_157 ;
V_145 -> V_192 [ 1 ] = & V_145 -> V_161 . V_157 ;
V_145 -> V_192 [ 2 ] = & V_145 -> V_163 . V_157 ;
V_145 -> V_192 [ 3 ] = NULL ;
V_145 -> V_191 . V_146 = V_186 ;
V_145 -> V_191 . V_192 = V_145 -> V_192 ;
F_85 ( & V_145 -> V_160 . V_157 ) ;
V_145 -> V_160 . V_157 . V_146 = L_68 ;
V_145 -> V_160 . V_157 . V_193 = 0444 ;
V_145 -> V_160 . V_194 = F_71 ;
F_85 ( & V_145 -> V_161 . V_157 ) ;
V_145 -> V_161 . V_157 . V_146 = L_69 ;
V_145 -> V_161 . V_157 . V_193 = 0444 ;
V_145 -> V_161 . V_194 = F_72 ;
F_85 ( & V_145 -> V_163 . V_157 ) ;
V_145 -> V_163 . V_157 . V_146
= L_70 ;
V_145 -> V_163 . V_157 . V_193 = 0644 ;
V_145 -> V_163 . V_194
= F_73 ;
V_145 -> V_163 . V_195
= F_74 ;
if ( ! V_8 -> V_51 [ V_6 ] . V_52 ||
! V_165 ) {
V_165 = 0 ;
}
F_18 ( & V_167 -> V_27 , L_71
L_72 , V_145 -> V_54 ,
V_145 -> V_52 ) ;
V_7 = F_86 ( & V_2 -> V_102 . V_27 -> V_60 ,
& V_145 -> V_191 ) ;
if ( V_7 < 0 ) {
F_18 ( & V_167 -> V_27 , L_73
L_74 ,
V_145 -> V_54 ) ;
}
}
if ( V_165 ) {
F_22 ( & V_167 -> V_27 , L_75
L_76
L_77 ) ;
V_7 = - V_114 ;
goto V_196;
}
V_7 = F_8 ( V_2 , true ) ;
if ( V_7 ) {
F_22 ( & V_167 -> V_27 , L_78 ) ;
goto V_196;
}
F_27 ( & V_83 ) ;
F_87 ( & V_2 -> V_197 , & V_198 ) ;
F_29 ( & V_83 ) ;
F_88 ( & V_167 -> V_27 , true ) ;
F_39 ( & V_167 -> V_27 , false ) ;
F_37 ( & V_95 ) ;
return 0 ;
V_196:
for ( V_6 = 0 ; V_6 < V_8 -> V_50 ; V_6 ++ ) {
struct V_159 * V_145 ;
V_145 = & V_8 -> V_51 [ V_6 ] ;
F_89 ( & V_2 -> V_102 . V_27 -> V_60 ,
& V_145 -> V_191 ) ;
F_84 ( V_145 -> V_191 . V_146 ) ;
}
V_190:
for ( V_6 = 0 ; V_6 < V_8 -> V_50 ; V_6 ++ ) {
struct V_159 * V_145
= & V_8 -> V_51 [ V_6 ] ;
for ( V_168 = 0 ; V_168 < V_145 -> V_188 ; V_168 ++ ) {
struct V_139 * V_140 = & V_145 -> V_189 [ V_168 ] ;
F_90 ( & V_140 -> V_153 ) ;
}
}
V_187:
for ( V_6 = 0 ; V_6 < V_8 -> V_50 ; V_6 ++ )
F_91 ( V_8 -> V_51 [ V_6 ] . V_53 ) ;
F_92 ( & V_2 -> V_102 ) ;
V_185:
F_84 ( V_2 -> V_102 . V_181 ) ;
V_175:
F_84 ( V_2 -> V_18 ) ;
V_174:
V_173:
F_84 ( V_2 -> V_8 ) ;
V_172:
F_84 ( V_2 ) ;
V_169:
return V_7 ;
}
static int T_4 F_93 ( struct V_166 * V_167 )
{
struct V_1 * V_2 = F_94 ( V_167 ) ;
struct V_33 * V_8 = V_2 -> V_8 ;
int V_6 = 0 ;
int V_168 = 0 ;
F_27 ( & V_83 ) ;
F_95 ( & V_2 -> V_197 ) ;
F_29 ( & V_83 ) ;
if ( F_66 ( & V_95 ) )
F_67 ( & V_95 ) ;
if ( F_33 ( & V_93 ) )
F_96 ( & V_93 ) ;
for ( V_6 = 0 ; V_6 < V_8 -> V_50 ; V_6 ++ ) {
struct V_159 * V_145
= & V_8 -> V_51 [ V_6 ] ;
for ( V_168 = 0 ; V_168 < V_145 -> V_188 ; V_168 ++ ) {
struct V_139 * V_140 = & V_145 -> V_189 [ V_168 ] ;
F_90 ( & V_140 -> V_153 ) ;
}
}
for ( V_6 = 0 ; V_6 < V_8 -> V_50 ; V_6 ++ )
F_91 ( V_8 -> V_51 [ V_6 ] . V_53 ) ;
F_92 ( & V_2 -> V_102 ) ;
F_8 ( V_2 , false ) ;
F_84 ( V_2 -> V_102 . V_181 ) ;
F_84 ( V_2 -> V_18 ) ;
F_84 ( V_2 -> V_8 ) ;
F_84 ( V_2 ) ;
return 0 ;
}
static int F_97 ( struct V_155 * V_27 )
{
int V_7 = 0 ;
if ( F_98 ( V_27 ) ) {
F_39 ( V_27 , false ) ;
V_7 = - V_47 ;
}
return V_7 ;
}
static int F_99 ( struct V_155 * V_27 )
{
struct V_1 * V_2 = F_100 ( V_27 ) ;
if ( ! V_59 ) {
if ( V_118 ) {
struct V_135 V_120 ;
unsigned long V_121 ;
F_101 ( V_118 , & V_125 ) ;
F_50 ( V_118 , & V_120 ) ;
if ( V_125 . V_123 ) {
F_51 ( & V_125 . time ,
& V_126 ) ;
F_51 ( & V_120 , & V_121 ) ;
if ( V_121 > V_126 )
V_126 = 0 ;
} else {
V_126 = 0 ;
}
}
V_59 = true ;
}
if ( F_33 ( & V_2 -> V_66 ) )
F_102 ( & V_2 -> V_66 ) ;
V_2 -> V_133 = F_2 ( V_2 ) ;
V_2 -> V_134 = F_1 ( V_2 ) ;
if ( ! V_132 ) {
V_127 = 0 ;
V_132 = F_44 () ;
}
return 0 ;
}
static void F_103 ( struct V_155 * V_27 )
{
struct V_1 * V_2 = F_100 ( V_27 ) ;
if ( V_59 ) {
if ( V_118 ) {
struct V_119 V_120 ;
F_101 ( V_118 , & V_120 ) ;
V_125 . V_199 = V_120 . V_199 ;
F_53 ( V_118 , & V_125 ) ;
}
V_59 = false ;
V_132 = false ;
}
if ( V_2 -> V_69 ) {
unsigned long V_200 = 0 ;
unsigned long V_121 = V_92 + V_90 ;
if ( F_55 ( V_121 , V_2 -> V_69 ) ) {
V_200 = ( unsigned long ) ( ( long ) V_121
- ( long ) ( V_2 -> V_69 ) ) ;
V_200 = F_45 ( V_200 ) ;
} else {
V_200 = 0 ;
}
if ( V_129 && V_129 -> V_130 ) {
if ( V_200 > V_127 )
V_200 -= V_127 ;
else
V_200 = 0 ;
}
F_104 ( V_91 , & V_2 -> V_66 ,
F_31 ( V_200 ) ) ;
}
F_39 ( V_2 -> V_27 , false ) ;
F_16 ( V_2 , NULL ) ;
}
static int T_5 F_105 ( void )
{
V_91 = F_106 ( L_79 ) ;
F_81 ( & V_93 , F_36 ) ;
return F_107 ( & V_201 ) ;
}
static void T_6 F_108 ( void )
{
F_109 ( V_91 ) ;
V_91 = NULL ;
F_110 ( & V_201 ) ;
}
static bool F_111 ( struct V_1 * V_2 ,
struct V_98 * V_99 )
{
int V_6 ;
bool V_202 = false ;
for ( V_6 = 0 ; V_2 -> V_18 [ V_6 ] ; V_6 ++ ) {
if ( V_99 == V_2 -> V_18 [ V_6 ] ) {
V_202 = true ;
break;
}
}
return V_202 ;
}
void F_112 ( struct V_98 * V_99 , enum V_97 type ,
char * V_203 )
{
struct V_1 * V_2 ;
bool V_204 = false ;
if ( V_99 == NULL )
return;
F_27 ( & V_83 ) ;
F_28 (cm, &cm_list, entry) {
V_204 = F_111 ( V_2 , V_99 ) ;
if ( V_204 )
break;
}
F_29 ( & V_83 ) ;
if ( ! V_204 )
return;
switch ( type ) {
case V_81 :
F_38 ( V_2 ) ;
break;
case V_96 :
F_40 ( V_2 ) ;
break;
case V_205 :
case V_206 ... V_207 :
F_42 ( V_2 , type ) ;
break;
case V_208 :
case V_209 :
F_16 ( V_2 , V_203 ? V_203 : V_80 [ type ] ) ;
break;
default:
F_22 ( V_2 -> V_27 , L_80 , V_72 ) ;
break;
}
}

static bool F_1 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
struct V_5 * V_6 ;
bool V_7 = false ;
int V_8 , V_9 ;
switch ( V_2 -> V_10 -> V_11 ) {
case V_12 :
V_7 = true ;
break;
case V_13 :
break;
case V_14 :
V_6 = F_2 ( V_2 -> V_10 -> V_15 ) ;
if ( ! V_6 )
break;
V_9 = V_6 -> V_16 ( V_6 ,
V_17 , & V_4 ) ;
if ( V_9 == 0 && V_4 . V_18 )
V_7 = true ;
break;
case V_19 :
for ( V_8 = 0 ; V_2 -> V_10 -> V_20 [ V_8 ] ; V_8 ++ ) {
V_6 = F_2 (
V_2 -> V_10 -> V_20 [ V_8 ] ) ;
if ( ! V_6 ) {
F_3 ( V_2 -> V_21 , L_1 ,
V_2 -> V_10 -> V_20 [ V_8 ] ) ;
continue;
}
V_9 = V_6 -> V_16 ( V_6 , V_17 ,
& V_4 ) ;
if ( V_9 == 0 && V_4 . V_18 ) {
V_7 = true ;
break;
}
}
break;
}
return V_7 ;
}
static bool F_4 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
struct V_5 * V_6 ;
bool V_22 = false ;
int V_8 , V_9 ;
for ( V_8 = 0 ; V_2 -> V_10 -> V_20 [ V_8 ] ; V_8 ++ ) {
V_6 = F_2 ( V_2 -> V_10 -> V_20 [ V_8 ] ) ;
if ( ! V_6 ) {
F_3 ( V_2 -> V_21 , L_1 ,
V_2 -> V_10 -> V_20 [ V_8 ] ) ;
continue;
}
V_9 = V_6 -> V_16 ( V_6 , V_23 , & V_4 ) ;
if ( V_9 == 0 && V_4 . V_18 ) {
V_22 = true ;
break;
}
}
return V_22 ;
}
static int F_5 ( struct V_1 * V_2 , int * V_24 )
{
union V_3 V_4 ;
struct V_5 * V_25 ;
int V_9 ;
V_25 = F_2 ( V_2 -> V_10 -> V_15 ) ;
if ( ! V_25 )
return - V_26 ;
V_9 = V_25 -> V_16 ( V_25 ,
V_27 , & V_4 ) ;
if ( V_9 )
return V_9 ;
* V_24 = V_4 . V_18 ;
return 0 ;
}
static bool F_6 ( struct V_1 * V_2 )
{
int V_8 , V_9 ;
bool V_28 = false ;
struct V_5 * V_6 ;
union V_3 V_4 ;
if ( ! F_1 ( V_2 ) )
return false ;
for ( V_8 = 0 ; V_2 -> V_10 -> V_20 [ V_8 ] ; V_8 ++ ) {
if ( V_2 -> V_29 )
continue;
if ( ! V_2 -> V_30 )
continue;
V_6 = F_2 ( V_2 -> V_10 -> V_20 [ V_8 ] ) ;
if ( ! V_6 ) {
F_3 ( V_2 -> V_21 , L_1 ,
V_2 -> V_10 -> V_20 [ V_8 ] ) ;
continue;
}
V_9 = V_6 -> V_16 ( V_6 , V_23 , & V_4 ) ;
if ( V_9 ) {
F_7 ( V_2 -> V_21 , L_2 ,
V_2 -> V_10 -> V_20 [ V_8 ] ) ;
continue;
}
if ( V_4 . V_18 == 0 )
continue;
V_9 = V_6 -> V_16 ( V_6 , V_31 , & V_4 ) ;
if ( V_9 ) {
F_7 ( V_2 -> V_21 , L_3 ,
V_2 -> V_10 -> V_20 [ V_8 ] ) ;
continue;
}
if ( V_4 . V_18 == V_32 ||
V_4 . V_18 == V_33 ||
V_4 . V_18 == V_34 )
continue;
V_28 = true ;
break;
}
return V_28 ;
}
static bool F_8 ( struct V_1 * V_2 )
{
struct V_35 * V_10 = V_2 -> V_10 ;
union V_3 V_4 ;
struct V_5 * V_25 ;
int V_9 = 0 ;
int V_24 ;
if ( ! F_1 ( V_2 ) )
return false ;
V_25 = F_2 ( V_2 -> V_10 -> V_15 ) ;
if ( ! V_25 )
return false ;
if ( V_10 -> V_36 > 0 ) {
V_4 . V_18 = 0 ;
V_9 = V_25 -> V_16 ( V_25 ,
V_37 , & V_4 ) ;
if ( ! V_9 && V_4 . V_18 > V_10 -> V_36 )
return true ;
}
if ( V_10 -> V_38 > 0 ) {
V_9 = F_5 ( V_2 , & V_24 ) ;
if ( ! V_9 && V_24 >= V_10 -> V_38 )
return true ;
}
if ( V_10 -> V_39 > 0 ) {
V_4 . V_18 = 0 ;
V_9 = V_25 -> V_16 ( V_25 ,
V_40 , & V_4 ) ;
if ( ! V_9 && V_4 . V_18 >= V_10 -> V_39 )
return true ;
}
return false ;
}
static bool F_9 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_10 -> V_41 ) {
case V_42 :
return false ;
case V_43 :
return true ;
case V_44 :
return F_4 ( V_2 ) ;
case V_45 :
return F_6 ( V_2 ) ;
default:
F_7 ( V_2 -> V_21 , L_4 ,
V_2 -> V_10 -> V_41 ) ;
}
return false ;
}
static int F_10 ( struct V_1 * V_2 , bool V_46 )
{
int V_47 = 0 , V_8 ;
struct V_35 * V_10 = V_2 -> V_10 ;
if ( V_46 == V_2 -> V_30 )
return 0 ;
if ( V_46 ) {
if ( V_2 -> V_29 )
return - V_48 ;
V_2 -> V_49 = F_11 ( F_12 () ) ;
V_2 -> V_50 = 0 ;
for ( V_8 = 0 ; V_8 < V_10 -> V_51 ; V_8 ++ ) {
if ( V_10 -> V_52 [ V_8 ] . V_53 )
continue;
V_47 = F_13 ( V_10 -> V_52 [ V_8 ] . V_54 ) ;
if ( V_47 < 0 ) {
F_7 ( V_2 -> V_21 , L_5 ,
V_10 -> V_52 [ V_8 ] . V_55 ) ;
}
}
} else {
V_2 -> V_49 = 0 ;
V_2 -> V_50 = F_11 ( F_12 () ) ;
for ( V_8 = 0 ; V_8 < V_10 -> V_51 ; V_8 ++ ) {
if ( V_10 -> V_52 [ V_8 ] . V_53 )
continue;
V_47 = F_14 ( V_10 -> V_52 [ V_8 ] . V_54 ) ;
if ( V_47 < 0 ) {
F_7 ( V_2 -> V_21 , L_6 ,
V_10 -> V_52 [ V_8 ] . V_55 ) ;
}
}
for ( V_8 = 0 ; V_8 < V_10 -> V_51 ; V_8 ++ ) {
if ( F_15 (
V_10 -> V_52 [ V_8 ] . V_54 ) ) {
F_16 (
V_10 -> V_52 [ V_8 ] . V_54 ) ;
F_7 ( V_2 -> V_21 , L_7 ,
V_10 -> V_52 [ V_8 ] . V_55 ) ;
}
}
}
if ( ! V_47 )
V_2 -> V_30 = V_46 ;
return V_47 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_47 ;
if ( V_2 -> V_29 )
return - V_48 ;
V_47 = F_10 ( V_2 , false ) ;
if ( V_47 )
return V_47 ;
return F_10 ( V_2 , true ) ;
}
static void F_18 ( struct V_1 * V_2 , const char * V_56 )
{
static char V_57 [ V_58 + 1 ] = L_8 ;
static char V_59 [ V_58 + 1 ] = L_8 ;
if ( V_60 ) {
if ( V_59 [ 0 ] == 0 ) {
if ( ! strncmp ( V_57 , V_56 , V_58 ) )
return;
strncpy ( V_59 , V_56 , V_58 ) ;
return;
}
if ( ! strncmp ( V_59 , V_56 , V_58 ) )
return;
strncpy ( V_59 , V_56 , V_58 ) ;
return;
}
if ( V_56 == NULL ) {
if ( ! V_59 [ 0 ] )
return;
strncpy ( V_57 , V_59 , V_58 ) ;
F_19 ( & V_2 -> V_21 -> V_61 , V_62 ) ;
V_59 [ 0 ] = 0 ;
return;
}
if ( ! strncmp ( V_57 , V_56 , V_58 ) )
return;
strncpy ( V_57 , V_56 , V_58 ) ;
F_19 ( & V_2 -> V_21 -> V_61 , V_62 ) ;
F_20 ( V_2 -> V_21 , L_9 , V_56 ) ;
}
static void F_21 ( struct V_63 * V_64 )
{
struct V_65 * V_66 = F_22 ( V_64 ) ;
struct V_1 * V_2 = F_23 ( V_66 ,
struct V_1 , V_67 ) ;
struct V_35 * V_10 = V_2 -> V_10 ;
int V_68 , V_47 , V_69 ;
V_2 -> V_70 = 0 ;
if ( ! V_10 -> V_71 || ! V_10 -> V_72 )
return;
V_47 = F_5 ( V_2 , & V_68 ) ;
if ( V_47 ) {
F_3 ( V_2 -> V_21 , L_10 , V_73 , V_47 ) ;
return;
}
V_69 = V_10 -> V_38 - V_68 ;
if ( V_69 < 0 )
return;
F_20 ( V_2 -> V_21 , L_11 , V_69 ) ;
if ( V_69 > V_10 -> V_71 ) {
F_17 ( V_2 ) ;
F_18 ( V_2 , L_12 ) ;
}
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_35 * V_10 = V_2 -> V_10 ;
T_1 V_74 = F_11 ( F_12 () ) ;
T_1 V_75 ;
int V_9 = false ;
if ( ! V_10 -> V_76 &&
! V_10 -> V_77 )
return V_9 ;
if ( V_2 -> V_30 ) {
V_75 = V_74 - V_2 -> V_49 ;
if ( V_75 > V_10 -> V_76 ) {
F_20 ( V_2 -> V_21 , L_13 ,
V_10 -> V_76 ) ;
F_18 ( V_2 , L_14 ) ;
F_10 ( V_2 , false ) ;
V_9 = true ;
}
} else if ( F_4 ( V_2 ) && ! V_2 -> V_30 ) {
V_75 = V_74 - V_2 -> V_50 ;
if ( V_75 > V_10 -> V_76 &&
F_4 ( V_2 ) ) {
F_20 ( V_2 -> V_21 , L_15 ,
V_10 -> V_77 ) ;
F_18 ( V_2 , L_12 ) ;
F_10 ( V_2 , true ) ;
V_9 = true ;
}
}
return V_9 ;
}
static int F_25 ( struct V_1 * V_2 ,
int * V_78 )
{
struct V_5 * V_25 ;
V_25 = F_2 ( V_2 -> V_10 -> V_15 ) ;
if ( ! V_25 )
return - V_26 ;
return V_25 -> V_16 ( V_25 ,
V_79 ,
(union V_3 * ) V_78 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
int * V_78 )
{
int V_9 ;
if ( ! V_2 -> V_10 -> V_80 )
return - V_26 ;
#ifdef F_27
if ( V_2 -> V_81 ) {
V_9 = F_28 ( V_2 -> V_81 , ( unsigned long * ) V_78 ) ;
if ( ! V_9 )
* V_78 /= 100 ;
} else
#endif
{
V_9 = F_25 ( V_2 , V_78 ) ;
}
return V_9 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_35 * V_10 = V_2 -> V_10 ;
int V_78 , V_82 , V_83 ;
int V_9 = 0 ;
V_9 = F_26 ( V_2 , & V_78 ) ;
if ( V_9 ) {
F_3 ( V_2 -> V_21 , L_16 ) ;
return 0 ;
}
V_82 = V_10 -> V_84 ;
V_83 = V_10 -> V_85 ;
if ( V_2 -> V_29 ) {
V_82 -= V_10 -> V_86 ;
V_83 += V_10 -> V_86 ;
}
if ( V_78 > V_82 )
V_9 = V_87 ;
else if ( V_78 < V_83 )
V_9 = V_88 ;
return V_9 ;
}
static bool F_30 ( struct V_1 * V_2 )
{
int V_89 ;
V_89 = F_29 ( V_2 ) ;
if ( V_89 && V_2 -> V_29 )
return false ;
if ( V_89 ) {
V_2 -> V_29 = V_89 ;
if ( ! F_10 ( V_2 , false ) )
F_18 ( V_2 , V_90 [ V_89 ] ) ;
} else if ( ! V_2 -> V_29 && F_24 ( V_2 ) ) {
F_31 ( V_2 -> V_21 ,
L_17 ) ;
} else if ( ! V_2 -> V_29 && F_4 ( V_2 ) &&
! V_2 -> V_30 ) {
F_21 ( & V_2 -> V_67 . V_64 ) ;
} else if ( ! V_2 -> V_29 && F_8 ( V_2 ) &&
V_2 -> V_30 ) {
F_20 ( V_2 -> V_21 , L_18 ) ;
F_18 ( V_2 , V_90 [ V_91 ] ) ;
F_10 ( V_2 , false ) ;
F_21 ( & V_2 -> V_67 . V_64 ) ;
} else {
V_2 -> V_29 = 0 ;
if ( F_4 ( V_2 ) ) {
if ( ! F_10 ( V_2 , true ) )
F_18 ( V_2 , L_19 ) ;
}
}
return true ;
}
static bool F_32 ( void )
{
bool V_92 = false ;
struct V_1 * V_2 ;
F_33 ( & V_93 ) ;
F_34 (cm, &cm_list, entry) {
if ( F_30 ( V_2 ) )
V_92 = true ;
}
F_35 ( & V_93 ) ;
return V_92 ;
}
static void F_36 ( struct V_63 * V_64 )
{
unsigned long V_94 = V_95 ;
struct V_1 * V_2 ;
bool V_96 = false ;
unsigned long V_97 ;
F_33 ( & V_93 ) ;
F_34 (cm, &cm_list, entry) {
if ( F_9 ( V_2 ) && V_2 -> V_10 -> V_98 ) {
V_96 = true ;
if ( V_94 > V_2 -> V_10 -> V_98 )
V_94 = V_2 -> V_10 -> V_98 ;
}
}
V_99 = F_37 ( V_94 ) ;
if ( V_99 <= V_100 )
V_99 = V_100 + 1 ;
if ( ! V_96 )
V_99 = V_95 ;
if ( V_99 == V_95 )
goto V_101;
F_38 ( V_102 == NULL , L_20
L_21 , V_73 ) ;
V_97 = V_103 + V_99 ;
if ( F_39 ( V_97 , V_104 ) ) {
F_40 ( V_102 , & V_105 , V_99 ) ;
V_104 = V_97 ;
} else {
if ( F_41 ( V_102 , & V_105 , V_99 ) )
V_104 = V_97 ;
}
V_101:
F_35 ( & V_93 ) ;
}
static void F_42 ( struct V_63 * V_64 )
{
F_32 () ;
F_43 ( & V_106 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_35 * V_10 = V_2 -> V_10 ;
if ( ! V_10 -> V_71 || ! V_10 -> V_72 )
goto V_101;
if ( V_60 )
F_45 ( V_2 -> V_21 , true ) ;
F_40 ( V_102 , & V_2 -> V_67 ,
F_37 ( V_10 -> V_72 ) ) ;
V_2 -> V_70 = V_103 + F_37 (
V_10 -> V_72 ) ;
if ( V_2 -> V_70 == 0 )
V_2 -> V_70 = 1 ;
V_101:
F_20 ( V_2 -> V_21 , L_18 ) ;
F_18 ( V_2 , V_90 [ V_91 ] ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
if ( V_60 )
F_45 ( V_2 -> V_21 , true ) ;
if ( ! F_1 ( V_2 ) ) {
F_47 ( V_2 -> V_21 , L_22 ) ;
F_18 ( V_2 , V_90 [ V_107 ] ) ;
} else {
F_18 ( V_2 , L_23 ) ;
}
}
static void F_48 ( struct V_1 * V_2 ,
enum V_108 type )
{
if ( V_60 )
F_45 ( V_2 -> V_21 , true ) ;
if ( F_9 ( V_2 ) && V_2 -> V_10 -> V_98 )
F_43 ( & V_106 ) ;
F_18 ( V_2 , V_90 [ type ] ) ;
}
static int F_49 ( struct V_5 * V_6 ,
enum V_109 V_110 ,
union V_3 * V_4 )
{
struct V_1 * V_2 = F_23 ( V_6 ,
struct V_1 , V_111 ) ;
struct V_35 * V_10 = V_2 -> V_10 ;
struct V_5 * V_25 ;
int V_9 = 0 ;
int V_24 ;
switch ( V_110 ) {
case V_31 :
if ( F_6 ( V_2 ) )
V_4 -> V_18 = V_112 ;
else if ( F_4 ( V_2 ) )
V_4 -> V_18 = V_34 ;
else
V_4 -> V_18 = V_33 ;
break;
case V_113 :
if ( V_2 -> V_29 > 0 )
V_4 -> V_18 = V_114 ;
else if ( V_2 -> V_29 < 0 )
V_4 -> V_18 = V_115 ;
else
V_4 -> V_18 = V_116 ;
break;
case V_17 :
if ( F_1 ( V_2 ) )
V_4 -> V_18 = 1 ;
else
V_4 -> V_18 = 0 ;
break;
case V_27 :
V_9 = F_5 ( V_2 , & V_4 -> V_18 ) ;
break;
case V_117 :
V_25 = F_2 ( V_2 -> V_10 -> V_15 ) ;
if ( ! V_25 ) {
V_9 = - V_26 ;
break;
}
V_9 = V_25 -> V_16 ( V_25 ,
V_117 , V_4 ) ;
break;
case V_79 :
case V_118 :
return F_26 ( V_2 , & V_4 -> V_18 ) ;
case V_40 :
V_25 = F_2 ( V_2 -> V_10 -> V_15 ) ;
if ( ! V_25 ) {
V_9 = - V_26 ;
break;
}
if ( ! F_1 ( V_2 ) ) {
V_4 -> V_18 = 100 ;
break;
}
V_9 = V_25 -> V_16 ( V_25 ,
V_40 , V_4 ) ;
if ( V_9 )
break;
if ( V_4 -> V_18 > 100 ) {
V_4 -> V_18 = 100 ;
break;
}
if ( V_4 -> V_18 < 0 )
V_4 -> V_18 = 0 ;
if ( F_6 ( V_2 ) )
break;
V_9 = F_5 ( V_2 , & V_24 ) ;
if ( V_9 ) {
V_9 = 0 ;
break;
}
if ( V_10 -> V_38 > 0 && V_24 >= V_10 -> V_38 &&
! F_6 ( V_2 ) ) {
V_4 -> V_18 = 100 ;
break;
}
break;
case V_23 :
if ( F_4 ( V_2 ) )
V_4 -> V_18 = 1 ;
else
V_4 -> V_18 = 0 ;
break;
case V_37 :
if ( F_8 ( V_2 ) )
V_4 -> V_18 = 1 ;
else
V_4 -> V_18 = 0 ;
V_9 = 0 ;
break;
case V_119 :
if ( F_6 ( V_2 ) ) {
V_25 = F_2 (
V_2 -> V_10 -> V_15 ) ;
if ( ! V_25 ) {
V_9 = - V_26 ;
break;
}
V_9 = V_25 -> V_16 ( V_25 ,
V_119 ,
V_4 ) ;
if ( V_9 ) {
V_4 -> V_18 = 1 ;
V_9 = 0 ;
} else {
V_4 -> V_18 = ( V_4 -> V_18 > 0 ) ?
V_4 -> V_18 : 1 ;
}
} else {
V_4 -> V_18 = 0 ;
}
break;
default:
return - V_120 ;
}
return V_9 ;
}
static bool F_50 ( void )
{
struct V_1 * V_2 ;
unsigned int V_121 = V_122 ;
int V_123 = 0 ;
if ( F_51 ( V_104 , V_103 ) )
F_52 ( V_121 ,
F_53 ( V_104 - V_103 ) ) ;
F_33 ( & V_93 ) ;
F_34 (cm, &cm_list, entry) {
unsigned int V_124 = 0 ;
if ( V_2 -> V_70 ) {
V_124 = F_53 ( V_2 -> V_70
- V_103 ) ;
if ( F_54 (
V_2 -> V_70 ) ||
F_37 ( V_124 ) < V_100 ) {
F_21 ( & V_2 -> V_67 . V_64 ) ;
V_124 = 0 ;
}
}
F_52 ( V_121 , V_124 ) ;
if ( ! F_9 ( V_2 ) && ! V_2 -> V_29 )
continue;
V_123 ++ ;
if ( V_2 -> V_10 -> V_98 == 0 )
continue;
F_52 ( V_121 , V_2 -> V_10 -> V_98 ) ;
}
F_35 ( & V_93 ) ;
if ( V_123 && V_125 ) {
T_2 V_126 , V_127 ;
if ( V_121 == V_122 ||
V_121 < V_128 * V_129 )
V_121 = 2 * V_128 * V_129 ;
F_55 ( L_24 , V_121 ) ;
V_126 = F_56 () ;
V_127 = F_57 ( V_121 / V_129 ,
( V_121 % V_129 ) * V_130 ) ;
F_58 ( V_125 , F_59 ( V_126 , V_127 ) ) ;
V_131 = V_121 ;
return true ;
}
return false ;
}
static void F_60 ( struct V_63 * V_64 )
{
struct V_132 * V_133 =
F_23 ( V_64 , struct V_132 , V_134 ) ;
int V_9 ;
if ( V_133 -> V_135 && V_133 -> V_136 != 0 && V_133 -> V_137 != 0 ) {
V_9 = F_61 ( V_133 -> V_138 -> V_54 ,
V_133 -> V_136 , V_133 -> V_137 ) ;
if ( V_9 < 0 ) {
F_62 ( L_25 ,
V_133 -> V_138 -> V_55 , V_133 -> V_139 ) ;
return;
}
F_55 ( L_26 ,
V_133 -> V_138 -> V_55 ,
V_133 -> V_136 , V_133 -> V_137 ) ;
}
F_10 ( V_133 -> V_2 , V_133 -> V_135 ) ;
}
static int F_63 ( struct V_140 * V_141 ,
unsigned long V_56 , void * V_142 )
{
struct V_132 * V_133 =
F_23 ( V_141 , struct V_132 , V_143 ) ;
V_133 -> V_135 = V_56 ;
if ( V_133 -> V_135 && F_9 ( V_133 -> V_2 ) ) {
F_64 ( & V_106 ) ;
F_43 ( & V_106 ) ;
}
F_43 ( & V_133 -> V_134 ) ;
return V_144 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_132 * V_133 )
{
int V_9 = 0 ;
F_66 ( & V_133 -> V_134 , F_60 ) ;
V_133 -> V_143 . V_145 = F_63 ;
V_9 = F_67 ( & V_133 -> V_146 ,
V_133 -> V_147 , V_133 -> V_139 , & V_133 -> V_143 ) ;
if ( V_9 < 0 ) {
F_55 ( L_27 ,
V_133 -> V_147 , V_133 -> V_139 ) ;
V_9 = - V_120 ;
}
return V_9 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_35 * V_10 = V_2 -> V_10 ;
struct V_148 * V_138 ;
int V_9 = 0 ;
int V_8 ;
int V_149 ;
for ( V_8 = 0 ; V_8 < V_10 -> V_51 ; V_8 ++ ) {
V_138 = & V_10 -> V_52 [ V_8 ] ;
V_138 -> V_54 = F_69 ( V_2 -> V_21 ,
V_138 -> V_55 ) ;
if ( F_70 ( V_138 -> V_54 ) ) {
F_3 ( V_2 -> V_21 , L_28 ,
V_138 -> V_55 ) ;
return F_71 ( V_138 -> V_54 ) ;
}
V_138 -> V_2 = V_2 ;
for ( V_149 = 0 ; V_149 < V_138 -> V_150 ; V_149 ++ ) {
struct V_132 * V_133 = & V_138 -> V_151 [ V_149 ] ;
V_9 = F_65 ( V_2 , V_133 ) ;
if ( V_9 < 0 ) {
F_3 ( V_2 -> V_21 , L_29 ,
V_138 -> V_55 ) ;
goto V_47;
}
V_133 -> V_138 = V_138 ;
V_133 -> V_2 = V_2 ;
}
}
V_47:
return V_9 ;
}
static T_3 F_72 ( struct V_152 * V_21 ,
struct V_153 * V_154 , char * V_155 )
{
struct V_148 * V_138
= F_23 ( V_154 , struct V_148 , V_156 ) ;
return sprintf ( V_155 , L_9 , V_138 -> V_55 ) ;
}
static T_3 F_73 ( struct V_152 * V_21 ,
struct V_153 * V_154 , char * V_155 )
{
struct V_148 * V_138
= F_23 ( V_154 , struct V_148 , V_157 ) ;
int V_158 = 0 ;
if ( ! V_138 -> V_53 )
V_158 = F_15 ( V_138 -> V_54 ) ;
return sprintf ( V_155 , L_9 , V_158 ? L_30 : L_31 ) ;
}
static T_3 F_74 ( struct V_152 * V_21 ,
struct V_153 * V_154 , char * V_155 )
{
struct V_148 * V_138 = F_23 ( V_154 ,
struct V_148 , V_159 ) ;
return sprintf ( V_155 , L_32 , V_138 -> V_53 ) ;
}
static T_3 F_75 ( struct V_152 * V_21 ,
struct V_153 * V_154 , const char * V_155 ,
T_4 V_160 )
{
struct V_148 * V_138
= F_23 ( V_154 , struct V_148 ,
V_159 ) ;
struct V_1 * V_2 = V_138 -> V_2 ;
struct V_35 * V_10 = V_2 -> V_10 ;
int V_8 ;
int V_9 ;
int V_53 ;
int V_161 = 1 ;
V_9 = sscanf ( V_155 , L_33 , & V_53 ) ;
if ( V_9 == 0 ) {
V_9 = - V_120 ;
return V_9 ;
}
if ( ! V_53 ) {
V_138 -> V_53 = 0 ;
return V_160 ;
}
for ( V_8 = 0 ; V_8 < V_10 -> V_51 ; V_8 ++ ) {
if ( & V_10 -> V_52 [ V_8 ] != V_138 &&
! V_10 -> V_52 [ V_8 ] . V_53 ) {
V_161 = 0 ;
break;
}
}
if ( ! V_161 ) {
if ( V_2 -> V_30 ) {
F_10 ( V_138 -> V_2 , false ) ;
V_138 -> V_53 = V_53 ;
F_10 ( V_138 -> V_2 , true ) ;
} else {
V_138 -> V_53 = V_53 ;
}
} else {
F_7 ( V_2 -> V_21 ,
L_34 ,
V_138 -> V_55 ) ;
}
return V_160 ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_35 * V_10 = V_2 -> V_10 ;
struct V_148 * V_138 ;
int V_161 = 1 ;
char V_155 [ 11 ] ;
char * V_162 ;
int V_9 = 0 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_10 -> V_51 ; V_8 ++ ) {
V_138 = & V_10 -> V_52 [ V_8 ] ;
snprintf ( V_155 , 10 , L_35 , V_8 ) ;
V_162 = F_77 ( V_2 -> V_21 ,
sizeof( char ) * ( strlen ( V_155 ) + 1 ) , V_163 ) ;
if ( ! V_162 ) {
V_9 = - V_164 ;
goto V_47;
}
strcpy ( V_162 , V_155 ) ;
V_138 -> V_165 [ 0 ] = & V_138 -> V_156 . V_154 ;
V_138 -> V_165 [ 1 ] = & V_138 -> V_157 . V_154 ;
V_138 -> V_165 [ 2 ] = & V_138 -> V_159 . V_154 ;
V_138 -> V_165 [ 3 ] = NULL ;
V_138 -> V_166 . V_139 = V_162 ;
V_138 -> V_166 . V_165 = V_138 -> V_165 ;
F_78 ( & V_138 -> V_156 . V_154 ) ;
V_138 -> V_156 . V_154 . V_139 = L_36 ;
V_138 -> V_156 . V_154 . V_167 = 0444 ;
V_138 -> V_156 . V_168 = F_72 ;
F_78 ( & V_138 -> V_157 . V_154 ) ;
V_138 -> V_157 . V_154 . V_139 = L_37 ;
V_138 -> V_157 . V_154 . V_167 = 0444 ;
V_138 -> V_157 . V_168 = F_73 ;
F_78 ( & V_138 -> V_159 . V_154 ) ;
V_138 -> V_159 . V_154 . V_139
= L_38 ;
V_138 -> V_159 . V_154 . V_167 = 0644 ;
V_138 -> V_159 . V_168
= F_74 ;
V_138 -> V_159 . V_169
= F_75 ;
if ( ! V_10 -> V_52 [ V_8 ] . V_53 ||
! V_161 )
V_161 = 0 ;
F_20 ( V_2 -> V_21 , L_39 ,
V_138 -> V_55 , V_138 -> V_53 ) ;
V_9 = F_79 ( & V_2 -> V_111 . V_21 -> V_61 ,
& V_138 -> V_166 ) ;
if ( V_9 < 0 ) {
F_3 ( V_2 -> V_21 , L_40 ,
V_138 -> V_55 ) ;
V_9 = - V_120 ;
goto V_47;
}
}
if ( V_161 ) {
F_3 ( V_2 -> V_21 , L_41 ) ;
V_9 = - V_120 ;
goto V_47;
}
V_47:
return V_9 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_5 * V_25 )
{
struct V_35 * V_10 = V_2 -> V_10 ;
union V_3 V_4 ;
int V_9 ;
V_9 = V_25 -> V_16 ( V_25 ,
V_79 , & V_4 ) ;
if ( ! V_9 ) {
V_2 -> V_111 . V_170 [ V_2 -> V_111 . V_171 ] =
V_79 ;
V_2 -> V_111 . V_171 ++ ;
V_2 -> V_10 -> V_80 = true ;
}
#ifdef F_27
if ( V_9 && V_10 -> V_172 ) {
V_2 -> V_81 =
F_81 ( V_10 -> V_172 ) ;
if ( F_70 ( V_2 -> V_81 ) )
return F_71 ( V_2 -> V_81 ) ;
V_2 -> V_111 . V_170 [ V_2 -> V_111 . V_171 ] =
V_118 ;
V_2 -> V_111 . V_171 ++ ;
V_2 -> V_10 -> V_80 = true ;
V_9 = 0 ;
}
#endif
if ( V_2 -> V_10 -> V_80 ) {
if ( ! V_10 -> V_84 )
V_10 -> V_84 = V_173 ;
if ( ! V_10 -> V_86 )
V_10 -> V_86 = V_174 ;
}
return V_9 ;
}
static struct V_35 * F_82 ( struct V_152 * V_21 )
{
struct V_35 * V_10 ;
struct V_175 * V_176 = V_21 -> V_177 ;
T_5 V_178 = V_42 ;
T_5 V_179 = V_13 ;
int V_180 = 0 ;
V_10 = F_77 ( V_21 , sizeof( * V_10 ) , V_163 ) ;
if ( ! V_10 )
return F_83 ( - V_164 ) ;
F_84 ( V_176 , L_42 , & V_10 -> V_181 ) ;
F_85 ( V_176 , L_43 , & V_178 ) ;
V_10 -> V_41 = V_178 ;
F_85 ( V_176 , L_44 ,
& V_10 -> V_98 ) ;
F_85 ( V_176 , L_45 ,
& V_10 -> V_72 ) ;
F_85 ( V_176 , L_46 ,
& V_10 -> V_71 ) ;
F_85 ( V_176 , L_47 , & V_10 -> V_38 ) ;
F_85 ( V_176 , L_48 , & V_10 -> V_39 ) ;
F_85 ( V_176 , L_49 ,
& V_10 -> V_36 ) ;
F_85 ( V_176 , L_50 , & V_179 ) ;
V_10 -> V_11 = V_179 ;
F_85 ( V_176 , L_51 , & V_180 ) ;
if ( V_180 ) {
V_10 -> V_20 = F_77 ( V_21 , sizeof( char * )
* ( V_180 + 1 ) , V_163 ) ;
if ( V_10 -> V_20 ) {
int V_8 ;
for ( V_8 = 0 ; V_8 < V_180 ; V_8 ++ )
F_86 ( V_176 , L_52 ,
V_8 , & V_10 -> V_20 [ V_8 ] ) ;
} else {
return F_83 ( - V_164 ) ;
}
}
F_84 ( V_176 , L_53 , & V_10 -> V_15 ) ;
F_84 ( V_176 , L_54 , & V_10 -> V_172 ) ;
F_85 ( V_176 , L_55 , & V_10 -> V_85 ) ;
if ( F_87 ( V_176 , L_56 , NULL ) )
V_10 -> V_85 *= - 1 ;
F_85 ( V_176 , L_57 , & V_10 -> V_84 ) ;
F_85 ( V_176 , L_58 , & V_10 -> V_86 ) ;
F_85 ( V_176 , L_59 ,
& V_10 -> V_76 ) ;
F_85 ( V_176 , L_60 ,
& V_10 -> V_77 ) ;
V_10 -> V_51 = F_88 ( V_176 ) ;
if ( V_10 -> V_51 ) {
struct V_148 * V_182 ;
struct V_175 * V_183 ;
V_182 = F_77 ( V_21 , sizeof( * V_182 )
* V_10 -> V_51 ,
V_163 ) ;
if ( ! V_182 )
return F_83 ( - V_164 ) ;
V_10 -> V_52 = V_182 ;
F_89 (np, child) {
struct V_132 * V_151 ;
struct V_175 * V_184 ;
F_84 ( V_183 , L_61 ,
& V_182 -> V_55 ) ;
V_182 -> V_150 = F_88 ( V_183 ) ;
if ( V_182 -> V_150 ) {
V_151 = F_77 ( V_21 , sizeof( * V_151 )
* V_182 -> V_150 ,
V_163 ) ;
if ( ! V_151 )
return F_83 ( - V_164 ) ;
V_182 -> V_151 = V_151 ;
F_89 (child, _child) {
F_84 ( V_184 ,
L_62 , & V_151 -> V_139 ) ;
F_84 ( V_184 ,
L_63 ,
& V_151 -> V_147 ) ;
F_85 ( V_184 ,
L_64 ,
& V_151 -> V_136 ) ;
F_85 ( V_184 ,
L_65 ,
& V_151 -> V_137 ) ;
V_151 ++ ;
}
}
V_182 ++ ;
}
}
return V_10 ;
}
static inline struct V_35 * F_90 ( struct V_185 * V_186 )
{
if ( V_186 -> V_21 . V_177 )
return F_82 ( & V_186 -> V_21 ) ;
return F_91 ( & V_186 -> V_21 ) ;
}
static enum V_187 F_92 ( struct V_188 * V_188 , T_2 V_126 )
{
V_189 = false ;
return V_190 ;
}
static int F_93 ( struct V_185 * V_186 )
{
struct V_35 * V_10 = F_90 ( V_186 ) ;
struct V_1 * V_2 ;
int V_9 = 0 , V_8 = 0 ;
int V_149 = 0 ;
union V_3 V_4 ;
struct V_5 * V_25 ;
if ( F_70 ( V_10 ) ) {
F_3 ( & V_186 -> V_21 , L_66 ) ;
return - V_26 ;
}
V_2 = F_77 ( & V_186 -> V_21 ,
sizeof( struct V_1 ) , V_163 ) ;
if ( ! V_2 )
return - V_164 ;
V_2 -> V_21 = & V_186 -> V_21 ;
V_2 -> V_10 = V_10 ;
if ( F_94 () ) {
V_125 = F_77 ( V_2 -> V_21 , sizeof( * V_125 ) , V_163 ) ;
F_95 ( V_125 , V_191 , F_92 ) ;
}
if ( V_10 -> V_38 == 0 ) {
F_20 ( & V_186 -> V_21 , L_67 ) ;
}
if ( ! V_10 -> V_72 || ! V_10 -> V_71 ) {
F_20 ( & V_186 -> V_21 , L_68 ) ;
V_10 -> V_72 = 0 ;
V_10 -> V_71 = 0 ;
}
if ( V_10 -> V_39 == 0 ) {
F_20 ( & V_186 -> V_21 , L_69 ) ;
}
if ( V_10 -> V_36 == 0 ) {
F_20 ( & V_186 -> V_21 , L_70 ) ;
}
if ( ! V_10 -> V_52 || V_10 -> V_51 < 1 ) {
F_3 ( & V_186 -> V_21 , L_71 ) ;
return - V_120 ;
}
if ( ! V_10 -> V_20 || ! V_10 -> V_20 [ 0 ] ) {
F_3 ( & V_186 -> V_21 , L_72 ) ;
return - V_120 ;
}
if ( ! V_10 -> V_15 ) {
F_3 ( & V_186 -> V_21 , L_73 ) ;
return - V_120 ;
}
while ( V_10 -> V_20 [ V_8 ] )
V_8 ++ ;
for ( V_8 = 0 ; V_10 -> V_20 [ V_8 ] ; V_8 ++ ) {
struct V_5 * V_6 ;
V_6 = F_2 ( V_10 -> V_20 [ V_8 ] ) ;
if ( ! V_6 ) {
F_3 ( & V_186 -> V_21 , L_1 ,
V_10 -> V_20 [ V_8 ] ) ;
return - V_26 ;
}
}
V_25 = F_2 ( V_10 -> V_15 ) ;
if ( ! V_25 ) {
F_3 ( & V_186 -> V_21 , L_1 ,
V_10 -> V_15 ) ;
return - V_26 ;
}
if ( V_10 -> V_98 == 0 ||
F_37 ( V_10 -> V_98 ) <= V_100 ) {
F_3 ( & V_186 -> V_21 , L_74 ) ;
return - V_120 ;
}
if ( ! V_10 -> V_76 ||
! V_10 -> V_77 ) {
F_20 ( & V_186 -> V_21 , L_75 ) ;
V_10 -> V_76 = 0 ;
V_10 -> V_77 = 0 ;
}
F_96 ( V_186 , V_2 ) ;
memcpy ( & V_2 -> V_111 , & V_192 , sizeof( V_192 ) ) ;
if ( ! V_10 -> V_181 )
strncpy ( V_2 -> V_193 , V_192 . V_139 , V_194 ) ;
else
strncpy ( V_2 -> V_193 , V_10 -> V_181 , V_194 ) ;
V_2 -> V_111 . V_139 = V_2 -> V_193 ;
V_2 -> V_111 . V_170 = F_77 ( & V_186 -> V_21 ,
sizeof( enum V_109 )
* ( F_97 ( V_195 ) +
V_196 ) , V_163 ) ;
if ( ! V_2 -> V_111 . V_170 )
return - V_164 ;
memcpy ( V_2 -> V_111 . V_170 , V_195 ,
sizeof( enum V_109 ) *
F_97 ( V_195 ) ) ;
V_2 -> V_111 . V_171 = V_192 . V_171 ;
if ( ! V_25 -> V_16 ( V_25 ,
V_119 , & V_4 ) ) {
V_2 -> V_111 . V_170 [ V_2 -> V_111 . V_171 ] =
V_119 ;
V_2 -> V_111 . V_171 ++ ;
}
if ( ! V_25 -> V_16 ( V_25 ,
V_117 ,
& V_4 ) ) {
V_2 -> V_111 . V_170 [ V_2 -> V_111 . V_171 ] =
V_117 ;
V_2 -> V_111 . V_171 ++ ;
}
V_9 = F_80 ( V_2 , V_25 ) ;
if ( V_9 ) {
F_3 ( & V_186 -> V_21 , L_76 ) ;
V_2 -> V_10 -> V_80 = false ;
}
F_98 ( & V_2 -> V_67 , F_21 ) ;
V_9 = F_99 ( NULL , & V_2 -> V_111 ) ;
if ( V_9 ) {
F_3 ( & V_186 -> V_21 , L_77 ,
V_2 -> V_111 . V_139 ) ;
return V_9 ;
}
V_9 = F_68 ( V_2 ) ;
if ( V_9 < 0 ) {
F_3 ( & V_186 -> V_21 , L_78 ) ;
goto V_197;
}
V_9 = F_76 ( V_2 ) ;
if ( V_9 < 0 ) {
F_3 ( & V_186 -> V_21 ,
L_79 ) ;
goto V_198;
}
F_33 ( & V_93 ) ;
F_100 ( & V_2 -> V_199 , & V_200 ) ;
F_35 ( & V_93 ) ;
F_101 ( & V_186 -> V_21 , true ) ;
F_45 ( & V_186 -> V_21 , false ) ;
F_32 () ;
F_43 ( & V_106 ) ;
return 0 ;
V_198:
for ( V_8 = 0 ; V_8 < V_10 -> V_51 ; V_8 ++ ) {
struct V_148 * V_138 ;
V_138 = & V_10 -> V_52 [ V_8 ] ;
F_102 ( & V_2 -> V_111 . V_21 -> V_61 ,
& V_138 -> V_166 ) ;
}
V_197:
for ( V_8 = 0 ; V_8 < V_10 -> V_51 ; V_8 ++ ) {
struct V_148 * V_138 ;
V_138 = & V_10 -> V_52 [ V_8 ] ;
for ( V_149 = 0 ; V_149 < V_138 -> V_150 ; V_149 ++ ) {
struct V_132 * V_133 = & V_138 -> V_151 [ V_149 ] ;
if ( V_133 -> V_146 . V_201 )
F_103 ( & V_133 -> V_146 ) ;
}
F_104 ( V_10 -> V_52 [ V_8 ] . V_54 ) ;
}
F_105 ( & V_2 -> V_111 ) ;
return V_9 ;
}
static int F_106 ( struct V_185 * V_186 )
{
struct V_1 * V_2 = F_107 ( V_186 ) ;
struct V_35 * V_10 = V_2 -> V_10 ;
int V_8 = 0 ;
int V_149 = 0 ;
F_33 ( & V_93 ) ;
F_108 ( & V_2 -> V_199 ) ;
F_35 ( & V_93 ) ;
F_64 ( & V_106 ) ;
F_109 ( & V_105 ) ;
for ( V_8 = 0 ; V_8 < V_10 -> V_51 ; V_8 ++ ) {
struct V_148 * V_138
= & V_10 -> V_52 [ V_8 ] ;
for ( V_149 = 0 ; V_149 < V_138 -> V_150 ; V_149 ++ ) {
struct V_132 * V_133 = & V_138 -> V_151 [ V_149 ] ;
F_103 ( & V_133 -> V_146 ) ;
}
}
for ( V_8 = 0 ; V_8 < V_10 -> V_51 ; V_8 ++ )
F_104 ( V_10 -> V_52 [ V_8 ] . V_54 ) ;
F_105 ( & V_2 -> V_111 ) ;
F_10 ( V_2 , false ) ;
return 0 ;
}
static int F_110 ( struct V_152 * V_21 )
{
int V_9 = 0 ;
if ( F_111 ( V_21 ) ) {
F_45 ( V_21 , false ) ;
V_9 = - V_48 ;
}
return V_9 ;
}
static bool F_112 ( void )
{
struct V_1 * V_2 ;
if ( V_125 )
return false ;
F_33 ( & V_93 ) ;
F_34 (cm, &cm_list, entry) {
if ( F_6 ( V_2 ) ) {
F_35 ( & V_93 ) ;
return true ;
}
}
F_35 ( & V_93 ) ;
return false ;
}
static int F_113 ( struct V_152 * V_21 )
{
struct V_1 * V_2 = F_114 ( V_21 ) ;
if ( F_112 () )
return - V_202 ;
if ( ! V_60 )
V_60 = true ;
V_189 = F_50 () ;
if ( V_189 ) {
F_64 ( & V_106 ) ;
F_109 ( & V_105 ) ;
F_115 ( & V_2 -> V_67 ) ;
}
return 0 ;
}
static void F_116 ( struct V_152 * V_21 )
{
struct V_1 * V_2 = F_114 ( V_21 ) ;
if ( V_60 )
V_60 = false ;
if ( V_189 ) {
T_2 V_203 ;
F_117 ( V_125 ) ;
V_189 = false ;
V_203 = F_118 ( V_125 ) ;
V_131 -= F_11 ( V_203 ) ;
F_43 ( & V_106 ) ;
}
F_30 ( V_2 ) ;
if ( V_2 -> V_70 ) {
unsigned long V_204 = 0 ;
unsigned long V_126 = V_103 + V_100 ;
if ( F_119 ( V_126 , V_2 -> V_70 ) ) {
V_204 = ( unsigned long ) ( ( long ) V_126
- ( long ) ( V_2 -> V_70 ) ) ;
V_204 = F_53 ( V_204 ) ;
} else {
V_204 = 0 ;
}
if ( V_204 > V_131 )
V_204 -= V_131 ;
else
V_204 = 0 ;
F_41 ( V_102 , & V_2 -> V_67 ,
F_37 ( V_204 ) ) ;
}
F_45 ( V_2 -> V_21 , false ) ;
}
static int T_6 F_120 ( void )
{
V_102 = F_121 ( L_80 ) ;
F_98 ( & V_105 , F_42 ) ;
return F_122 ( & V_205 ) ;
}
static void T_7 F_123 ( void )
{
F_124 ( V_102 ) ;
V_102 = NULL ;
F_125 ( & V_205 ) ;
}
static bool F_126 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
int V_8 ;
bool V_206 = false ;
for ( V_8 = 0 ; V_2 -> V_10 -> V_20 [ V_8 ] ; V_8 ++ ) {
if ( ! strcmp ( V_6 -> V_139 , V_2 -> V_10 -> V_20 [ V_8 ] ) ) {
V_206 = true ;
break;
}
}
return V_206 ;
}
void F_127 ( struct V_5 * V_6 , enum V_108 type ,
char * V_207 )
{
struct V_1 * V_2 ;
bool V_208 = false ;
if ( V_6 == NULL )
return;
F_33 ( & V_93 ) ;
F_34 (cm, &cm_list, entry) {
V_208 = F_126 ( V_2 , V_6 ) ;
if ( V_208 )
break;
}
F_35 ( & V_93 ) ;
if ( ! V_208 )
return;
switch ( type ) {
case V_91 :
F_44 ( V_2 ) ;
break;
case V_107 :
F_46 ( V_2 ) ;
break;
case V_209 :
case V_210 ... V_211 :
F_48 ( V_2 , type ) ;
break;
case V_212 :
case V_213 :
F_18 ( V_2 , V_207 ? V_207 : V_90 [ type ] ) ;
break;
default:
F_3 ( V_2 -> V_21 , L_81 , V_73 ) ;
break;
}
}

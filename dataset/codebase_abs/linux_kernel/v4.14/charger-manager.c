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
V_9 = F_3 ( V_6 , V_16 ,
& V_4 ) ;
if ( V_9 == 0 && V_4 . V_17 )
V_7 = true ;
F_4 ( V_6 ) ;
break;
case V_18 :
for ( V_8 = 0 ; V_2 -> V_10 -> V_19 [ V_8 ] ; V_8 ++ ) {
V_6 = F_2 (
V_2 -> V_10 -> V_19 [ V_8 ] ) ;
if ( ! V_6 ) {
F_5 ( V_2 -> V_20 , L_1 ,
V_2 -> V_10 -> V_19 [ V_8 ] ) ;
continue;
}
V_9 = F_3 ( V_6 ,
V_16 , & V_4 ) ;
F_4 ( V_6 ) ;
if ( V_9 == 0 && V_4 . V_17 ) {
V_7 = true ;
break;
}
}
break;
}
return V_7 ;
}
static bool F_6 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
struct V_5 * V_6 ;
bool V_21 = false ;
int V_8 , V_9 ;
for ( V_8 = 0 ; V_2 -> V_10 -> V_19 [ V_8 ] ; V_8 ++ ) {
V_6 = F_2 ( V_2 -> V_10 -> V_19 [ V_8 ] ) ;
if ( ! V_6 ) {
F_5 ( V_2 -> V_20 , L_1 ,
V_2 -> V_10 -> V_19 [ V_8 ] ) ;
continue;
}
V_9 = F_3 ( V_6 , V_22 ,
& V_4 ) ;
F_4 ( V_6 ) ;
if ( V_9 == 0 && V_4 . V_17 ) {
V_21 = true ;
break;
}
}
return V_21 ;
}
static int F_7 ( struct V_1 * V_2 , int * V_23 )
{
union V_3 V_4 ;
struct V_5 * V_24 ;
int V_9 ;
V_24 = F_2 ( V_2 -> V_10 -> V_15 ) ;
if ( ! V_24 )
return - V_25 ;
V_9 = F_3 ( V_24 ,
V_26 , & V_4 ) ;
F_4 ( V_24 ) ;
if ( V_9 )
return V_9 ;
* V_23 = V_4 . V_17 ;
return 0 ;
}
static bool F_8 ( struct V_1 * V_2 )
{
int V_8 , V_9 ;
bool V_27 = false ;
struct V_5 * V_6 ;
union V_3 V_4 ;
if ( ! F_1 ( V_2 ) )
return false ;
for ( V_8 = 0 ; V_2 -> V_10 -> V_19 [ V_8 ] ; V_8 ++ ) {
if ( V_2 -> V_28 )
continue;
if ( ! V_2 -> V_29 )
continue;
V_6 = F_2 ( V_2 -> V_10 -> V_19 [ V_8 ] ) ;
if ( ! V_6 ) {
F_5 ( V_2 -> V_20 , L_1 ,
V_2 -> V_10 -> V_19 [ V_8 ] ) ;
continue;
}
V_9 = F_3 ( V_6 , V_22 ,
& V_4 ) ;
if ( V_9 ) {
F_9 ( V_2 -> V_20 , L_2 ,
V_2 -> V_10 -> V_19 [ V_8 ] ) ;
F_4 ( V_6 ) ;
continue;
}
if ( V_4 . V_17 == 0 ) {
F_4 ( V_6 ) ;
continue;
}
V_9 = F_3 ( V_6 , V_30 ,
& V_4 ) ;
F_4 ( V_6 ) ;
if ( V_9 ) {
F_9 ( V_2 -> V_20 , L_3 ,
V_2 -> V_10 -> V_19 [ V_8 ] ) ;
continue;
}
if ( V_4 . V_17 == V_31 ||
V_4 . V_17 == V_32 ||
V_4 . V_17 == V_33 )
continue;
V_27 = true ;
break;
}
return V_27 ;
}
static bool F_10 ( struct V_1 * V_2 )
{
struct V_34 * V_10 = V_2 -> V_10 ;
union V_3 V_4 ;
struct V_5 * V_24 ;
bool V_35 = false ;
int V_9 = 0 ;
int V_23 ;
if ( ! F_1 ( V_2 ) )
return false ;
V_24 = F_2 ( V_2 -> V_10 -> V_15 ) ;
if ( ! V_24 )
return false ;
if ( V_10 -> V_36 > 0 ) {
V_4 . V_17 = 0 ;
V_9 = F_3 ( V_24 ,
V_37 , & V_4 ) ;
if ( ! V_9 && V_4 . V_17 > V_10 -> V_36 ) {
V_35 = true ;
goto V_38;
}
}
if ( V_10 -> V_39 > 0 ) {
V_9 = F_7 ( V_2 , & V_23 ) ;
if ( ! V_9 && V_23 >= V_10 -> V_39 ) {
V_35 = true ;
goto V_38;
}
}
if ( V_10 -> V_40 > 0 ) {
V_4 . V_17 = 0 ;
V_9 = F_3 ( V_24 ,
V_41 , & V_4 ) ;
if ( ! V_9 && V_4 . V_17 >= V_10 -> V_40 ) {
V_35 = true ;
goto V_38;
}
}
V_38:
F_4 ( V_24 ) ;
return V_35 ;
}
static bool F_11 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_10 -> V_42 ) {
case V_43 :
return false ;
case V_44 :
return true ;
case V_45 :
return F_6 ( V_2 ) ;
case V_46 :
return F_8 ( V_2 ) ;
default:
F_9 ( V_2 -> V_20 , L_4 ,
V_2 -> V_10 -> V_42 ) ;
}
return false ;
}
static int F_12 ( struct V_1 * V_2 , bool V_47 )
{
int V_48 = 0 , V_8 ;
struct V_34 * V_10 = V_2 -> V_10 ;
if ( V_47 == V_2 -> V_29 )
return 0 ;
if ( V_47 ) {
if ( V_2 -> V_28 )
return - V_49 ;
V_2 -> V_50 = F_13 ( F_14 () ) ;
V_2 -> V_51 = 0 ;
for ( V_8 = 0 ; V_8 < V_10 -> V_52 ; V_8 ++ ) {
if ( V_10 -> V_53 [ V_8 ] . V_54 )
continue;
V_48 = F_15 ( V_10 -> V_53 [ V_8 ] . V_55 ) ;
if ( V_48 < 0 ) {
F_9 ( V_2 -> V_20 , L_5 ,
V_10 -> V_53 [ V_8 ] . V_56 ) ;
}
}
} else {
V_2 -> V_50 = 0 ;
V_2 -> V_51 = F_13 ( F_14 () ) ;
for ( V_8 = 0 ; V_8 < V_10 -> V_52 ; V_8 ++ ) {
if ( V_10 -> V_53 [ V_8 ] . V_54 )
continue;
V_48 = F_16 ( V_10 -> V_53 [ V_8 ] . V_55 ) ;
if ( V_48 < 0 ) {
F_9 ( V_2 -> V_20 , L_6 ,
V_10 -> V_53 [ V_8 ] . V_56 ) ;
}
}
for ( V_8 = 0 ; V_8 < V_10 -> V_52 ; V_8 ++ ) {
if ( F_17 (
V_10 -> V_53 [ V_8 ] . V_55 ) ) {
F_18 (
V_10 -> V_53 [ V_8 ] . V_55 ) ;
F_9 ( V_2 -> V_20 , L_7 ,
V_10 -> V_53 [ V_8 ] . V_56 ) ;
}
}
}
if ( ! V_48 )
V_2 -> V_29 = V_47 ;
return V_48 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_48 ;
if ( V_2 -> V_28 )
return - V_49 ;
V_48 = F_12 ( V_2 , false ) ;
if ( V_48 )
return V_48 ;
return F_12 ( V_2 , true ) ;
}
static void F_20 ( struct V_1 * V_2 , const char * V_57 )
{
static char V_58 [ V_59 + 1 ] = L_8 ;
static char V_60 [ V_59 + 1 ] = L_8 ;
if ( V_61 ) {
if ( V_60 [ 0 ] == 0 ) {
if ( ! strncmp ( V_58 , V_57 , V_59 ) )
return;
strncpy ( V_60 , V_57 , V_59 ) ;
return;
}
if ( ! strncmp ( V_60 , V_57 , V_59 ) )
return;
strncpy ( V_60 , V_57 , V_59 ) ;
return;
}
if ( V_57 == NULL ) {
if ( ! V_60 [ 0 ] )
return;
strncpy ( V_58 , V_60 , V_59 ) ;
F_21 ( & V_2 -> V_20 -> V_62 , V_63 ) ;
V_60 [ 0 ] = 0 ;
return;
}
if ( ! strncmp ( V_58 , V_57 , V_59 ) )
return;
strncpy ( V_58 , V_57 , V_59 ) ;
F_21 ( & V_2 -> V_20 -> V_62 , V_63 ) ;
F_22 ( V_2 -> V_20 , L_9 , V_57 ) ;
}
static void F_23 ( struct V_64 * V_65 )
{
struct V_66 * V_67 = F_24 ( V_65 ) ;
struct V_1 * V_2 = F_25 ( V_67 ,
struct V_1 , V_68 ) ;
struct V_34 * V_10 = V_2 -> V_10 ;
int V_69 , V_48 , V_70 ;
V_2 -> V_71 = 0 ;
if ( ! V_10 -> V_72 || ! V_10 -> V_73 )
return;
V_48 = F_7 ( V_2 , & V_69 ) ;
if ( V_48 ) {
F_5 ( V_2 -> V_20 , L_10 , V_74 , V_48 ) ;
return;
}
V_70 = V_10 -> V_39 - V_69 ;
if ( V_70 < 0 )
return;
F_22 ( V_2 -> V_20 , L_11 , V_70 ) ;
if ( V_70 > V_10 -> V_72 ) {
F_19 ( V_2 ) ;
F_20 ( V_2 , L_12 ) ;
}
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_34 * V_10 = V_2 -> V_10 ;
T_1 V_75 = F_13 ( F_14 () ) ;
T_1 V_76 ;
int V_9 = false ;
if ( ! V_10 -> V_77 &&
! V_10 -> V_78 )
return V_9 ;
if ( V_2 -> V_29 ) {
V_76 = V_75 - V_2 -> V_50 ;
if ( V_76 > V_10 -> V_77 ) {
F_22 ( V_2 -> V_20 , L_13 ,
V_10 -> V_77 ) ;
F_20 ( V_2 , L_14 ) ;
F_12 ( V_2 , false ) ;
V_9 = true ;
}
} else if ( F_6 ( V_2 ) && ! V_2 -> V_29 ) {
V_76 = V_75 - V_2 -> V_51 ;
if ( V_76 > V_10 -> V_77 &&
F_6 ( V_2 ) ) {
F_22 ( V_2 -> V_20 , L_15 ,
V_10 -> V_78 ) ;
F_20 ( V_2 , L_12 ) ;
F_12 ( V_2 , true ) ;
V_9 = true ;
}
}
return V_9 ;
}
static int F_27 ( struct V_1 * V_2 ,
int * V_79 )
{
struct V_5 * V_24 ;
int V_9 ;
V_24 = F_2 ( V_2 -> V_10 -> V_15 ) ;
if ( ! V_24 )
return - V_25 ;
V_9 = F_3 ( V_24 ,
V_80 ,
(union V_3 * ) V_79 ) ;
F_4 ( V_24 ) ;
return V_9 ;
}
static int F_28 ( struct V_1 * V_2 ,
int * V_79 )
{
int V_9 ;
if ( ! V_2 -> V_10 -> V_81 )
return - V_25 ;
#ifdef F_29
if ( V_2 -> V_82 ) {
V_9 = F_30 ( V_2 -> V_82 , V_79 ) ;
if ( ! V_9 )
* V_79 /= 100 ;
} else
#endif
{
V_9 = F_27 ( V_2 , V_79 ) ;
}
return V_9 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_34 * V_10 = V_2 -> V_10 ;
int V_79 , V_83 , V_84 ;
int V_9 = 0 ;
V_9 = F_28 ( V_2 , & V_79 ) ;
if ( V_9 ) {
F_5 ( V_2 -> V_20 , L_16 ) ;
return 0 ;
}
V_83 = V_10 -> V_85 ;
V_84 = V_10 -> V_86 ;
if ( V_2 -> V_28 ) {
V_83 -= V_10 -> V_87 ;
V_84 += V_10 -> V_87 ;
}
if ( V_79 > V_83 )
V_9 = V_88 ;
else if ( V_79 < V_84 )
V_9 = V_89 ;
return V_9 ;
}
static bool F_32 ( struct V_1 * V_2 )
{
int V_90 ;
V_90 = F_31 ( V_2 ) ;
if ( V_90 && V_2 -> V_28 )
return false ;
if ( V_90 ) {
V_2 -> V_28 = V_90 ;
if ( ! F_12 ( V_2 , false ) )
F_20 ( V_2 , V_91 [ V_90 ] ) ;
} else if ( ! V_2 -> V_28 && F_26 ( V_2 ) ) {
F_33 ( V_2 -> V_20 ,
L_17 ) ;
} else if ( ! V_2 -> V_28 && F_6 ( V_2 ) &&
! V_2 -> V_29 ) {
F_23 ( & V_2 -> V_68 . V_65 ) ;
} else if ( ! V_2 -> V_28 && F_10 ( V_2 ) &&
V_2 -> V_29 ) {
F_22 ( V_2 -> V_20 , L_18 ) ;
F_20 ( V_2 , V_91 [ V_92 ] ) ;
F_12 ( V_2 , false ) ;
F_23 ( & V_2 -> V_68 . V_65 ) ;
} else {
V_2 -> V_28 = 0 ;
if ( F_6 ( V_2 ) ) {
if ( ! F_12 ( V_2 , true ) )
F_20 ( V_2 , L_19 ) ;
}
}
return true ;
}
static bool F_34 ( void )
{
bool V_93 = false ;
struct V_1 * V_2 ;
F_35 ( & V_94 ) ;
F_36 (cm, &cm_list, entry) {
if ( F_32 ( V_2 ) )
V_93 = true ;
}
F_37 ( & V_94 ) ;
return V_93 ;
}
static void F_38 ( struct V_64 * V_65 )
{
unsigned long V_95 = V_96 ;
struct V_1 * V_2 ;
bool V_97 = false ;
unsigned long V_98 ;
F_35 ( & V_94 ) ;
F_36 (cm, &cm_list, entry) {
if ( F_11 ( V_2 ) && V_2 -> V_10 -> V_99 ) {
V_97 = true ;
if ( V_95 > V_2 -> V_10 -> V_99 )
V_95 = V_2 -> V_10 -> V_99 ;
}
}
V_100 = F_39 ( V_95 ) ;
if ( V_100 <= V_101 )
V_100 = V_101 + 1 ;
if ( ! V_97 )
V_100 = V_96 ;
if ( V_100 == V_96 )
goto V_38;
F_40 ( V_102 == NULL , L_20
L_21 , V_74 ) ;
V_98 = V_103 + V_100 ;
if ( F_41 ( V_98 , V_104 ) ) {
F_42 ( V_102 , & V_105 , V_100 ) ;
V_104 = V_98 ;
} else {
if ( F_43 ( V_102 , & V_105 , V_100 ) )
V_104 = V_98 ;
}
V_38:
F_37 ( & V_94 ) ;
}
static void F_44 ( struct V_64 * V_65 )
{
F_34 () ;
F_45 ( & V_106 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_34 * V_10 = V_2 -> V_10 ;
if ( ! V_10 -> V_72 || ! V_10 -> V_73 )
goto V_38;
if ( V_61 )
F_47 ( V_2 -> V_20 , true ) ;
F_42 ( V_102 , & V_2 -> V_68 ,
F_39 ( V_10 -> V_73 ) ) ;
V_2 -> V_71 = V_103 + F_39 (
V_10 -> V_73 ) ;
if ( V_2 -> V_71 == 0 )
V_2 -> V_71 = 1 ;
V_38:
F_22 ( V_2 -> V_20 , L_18 ) ;
F_20 ( V_2 , V_91 [ V_92 ] ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
if ( V_61 )
F_47 ( V_2 -> V_20 , true ) ;
if ( ! F_1 ( V_2 ) ) {
F_49 ( V_2 -> V_20 , L_22 ) ;
F_20 ( V_2 , V_91 [ V_107 ] ) ;
} else {
F_20 ( V_2 , L_23 ) ;
}
}
static void F_50 ( struct V_1 * V_2 ,
enum V_108 type )
{
if ( V_61 )
F_47 ( V_2 -> V_20 , true ) ;
if ( F_11 ( V_2 ) && V_2 -> V_10 -> V_99 )
F_45 ( & V_106 ) ;
F_20 ( V_2 , V_91 [ type ] ) ;
}
static int F_51 ( struct V_5 * V_6 ,
enum V_109 V_110 ,
union V_3 * V_4 )
{
struct V_1 * V_2 = F_52 ( V_6 ) ;
struct V_34 * V_10 = V_2 -> V_10 ;
struct V_5 * V_24 = NULL ;
int V_9 = 0 ;
int V_23 ;
switch ( V_110 ) {
case V_30 :
if ( F_8 ( V_2 ) )
V_4 -> V_17 = V_111 ;
else if ( F_6 ( V_2 ) )
V_4 -> V_17 = V_33 ;
else
V_4 -> V_17 = V_32 ;
break;
case V_112 :
if ( V_2 -> V_28 > 0 )
V_4 -> V_17 = V_113 ;
else if ( V_2 -> V_28 < 0 )
V_4 -> V_17 = V_114 ;
else
V_4 -> V_17 = V_115 ;
break;
case V_16 :
if ( F_1 ( V_2 ) )
V_4 -> V_17 = 1 ;
else
V_4 -> V_17 = 0 ;
break;
case V_26 :
V_9 = F_7 ( V_2 , & V_4 -> V_17 ) ;
break;
case V_116 :
V_24 = F_2 ( V_2 -> V_10 -> V_15 ) ;
if ( ! V_24 ) {
V_9 = - V_25 ;
break;
}
V_9 = F_3 ( V_24 ,
V_116 , V_4 ) ;
break;
case V_80 :
case V_117 :
return F_28 ( V_2 , & V_4 -> V_17 ) ;
case V_41 :
if ( ! F_1 ( V_2 ) ) {
V_4 -> V_17 = 100 ;
break;
}
V_24 = F_2 ( V_2 -> V_10 -> V_15 ) ;
if ( ! V_24 ) {
V_9 = - V_25 ;
break;
}
V_9 = F_3 ( V_24 ,
V_41 , V_4 ) ;
if ( V_9 )
break;
if ( V_4 -> V_17 > 100 ) {
V_4 -> V_17 = 100 ;
break;
}
if ( V_4 -> V_17 < 0 )
V_4 -> V_17 = 0 ;
if ( F_8 ( V_2 ) )
break;
V_9 = F_7 ( V_2 , & V_23 ) ;
if ( V_9 ) {
V_9 = 0 ;
break;
}
if ( V_10 -> V_39 > 0 && V_23 >= V_10 -> V_39 &&
! F_8 ( V_2 ) ) {
V_4 -> V_17 = 100 ;
break;
}
break;
case V_22 :
if ( F_6 ( V_2 ) )
V_4 -> V_17 = 1 ;
else
V_4 -> V_17 = 0 ;
break;
case V_37 :
if ( F_10 ( V_2 ) )
V_4 -> V_17 = 1 ;
else
V_4 -> V_17 = 0 ;
V_9 = 0 ;
break;
case V_118 :
if ( F_8 ( V_2 ) ) {
V_24 = F_2 (
V_2 -> V_10 -> V_15 ) ;
if ( ! V_24 ) {
V_9 = - V_25 ;
break;
}
V_9 = F_3 ( V_24 ,
V_118 ,
V_4 ) ;
if ( V_9 ) {
V_4 -> V_17 = 1 ;
V_9 = 0 ;
} else {
V_4 -> V_17 = ( V_4 -> V_17 > 0 ) ?
V_4 -> V_17 : 1 ;
}
} else {
V_4 -> V_17 = 0 ;
}
break;
default:
return - V_119 ;
}
if ( V_24 )
F_4 ( V_24 ) ;
return V_9 ;
}
static bool F_53 ( void )
{
struct V_1 * V_2 ;
unsigned int V_120 = V_121 ;
int V_122 = 0 ;
if ( F_54 ( V_104 , V_103 ) )
F_55 ( V_120 ,
F_56 ( V_104 - V_103 ) ) ;
F_35 ( & V_94 ) ;
F_36 (cm, &cm_list, entry) {
unsigned int V_123 = 0 ;
if ( V_2 -> V_71 ) {
V_123 = F_56 ( V_2 -> V_71
- V_103 ) ;
if ( F_57 (
V_2 -> V_71 ) ||
F_39 ( V_123 ) < V_101 ) {
F_23 ( & V_2 -> V_68 . V_65 ) ;
V_123 = 0 ;
}
}
F_55 ( V_120 , V_123 ) ;
if ( ! F_11 ( V_2 ) && ! V_2 -> V_28 )
continue;
V_122 ++ ;
if ( V_2 -> V_10 -> V_99 == 0 )
continue;
F_55 ( V_120 , V_2 -> V_10 -> V_99 ) ;
}
F_37 ( & V_94 ) ;
if ( V_122 && V_124 ) {
T_2 V_125 , V_126 ;
if ( V_120 == V_121 ||
V_120 < V_127 * V_128 )
V_120 = 2 * V_127 * V_128 ;
F_58 ( L_24 , V_120 ) ;
V_125 = F_59 () ;
V_126 = F_60 ( V_120 / V_128 ,
( V_120 % V_128 ) * V_129 ) ;
F_61 ( V_124 , F_62 ( V_125 , V_126 ) ) ;
V_130 = V_120 ;
return true ;
}
return false ;
}
static void F_63 ( struct V_64 * V_65 )
{
struct V_131 * V_132 =
F_25 ( V_65 , struct V_131 , V_133 ) ;
int V_9 ;
if ( V_132 -> V_134 && V_132 -> V_135 != 0 && V_132 -> V_136 != 0 ) {
V_9 = F_64 ( V_132 -> V_137 -> V_55 ,
V_132 -> V_135 , V_132 -> V_136 ) ;
if ( V_9 < 0 ) {
F_65 ( L_25 ,
V_132 -> V_137 -> V_56 , V_132 -> V_138 ) ;
return;
}
F_58 ( L_26 ,
V_132 -> V_137 -> V_56 ,
V_132 -> V_135 , V_132 -> V_136 ) ;
}
F_12 ( V_132 -> V_2 , V_132 -> V_134 ) ;
}
static int F_66 ( struct V_139 * V_140 ,
unsigned long V_57 , void * V_141 )
{
struct V_131 * V_132 =
F_25 ( V_140 , struct V_131 , V_142 ) ;
V_132 -> V_134 = V_57 ;
if ( V_132 -> V_134 && F_11 ( V_132 -> V_2 ) ) {
F_67 ( & V_106 ) ;
F_45 ( & V_106 ) ;
}
F_45 ( & V_132 -> V_133 ) ;
return V_143 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_131 * V_132 )
{
int V_9 ;
F_69 ( & V_132 -> V_133 , F_63 ) ;
V_132 -> V_142 . V_144 = F_66 ;
V_9 = F_70 ( & V_132 -> V_145 ,
V_132 -> V_146 , V_132 -> V_138 , & V_132 -> V_142 ) ;
if ( V_9 < 0 ) {
F_58 ( L_27 ,
V_132 -> V_146 , V_132 -> V_138 ) ;
V_9 = - V_119 ;
}
return V_9 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_34 * V_10 = V_2 -> V_10 ;
struct V_147 * V_137 ;
int V_9 ;
int V_8 ;
int V_148 ;
for ( V_8 = 0 ; V_8 < V_10 -> V_52 ; V_8 ++ ) {
V_137 = & V_10 -> V_53 [ V_8 ] ;
V_137 -> V_55 = F_72 ( V_2 -> V_20 ,
V_137 -> V_56 ) ;
if ( F_73 ( V_137 -> V_55 ) ) {
F_5 ( V_2 -> V_20 , L_28 ,
V_137 -> V_56 ) ;
return F_74 ( V_137 -> V_55 ) ;
}
V_137 -> V_2 = V_2 ;
for ( V_148 = 0 ; V_148 < V_137 -> V_149 ; V_148 ++ ) {
struct V_131 * V_132 = & V_137 -> V_150 [ V_148 ] ;
V_9 = F_68 ( V_2 , V_132 ) ;
if ( V_9 < 0 ) {
F_5 ( V_2 -> V_20 , L_29 ,
V_137 -> V_56 ) ;
return V_9 ;
}
V_132 -> V_137 = V_137 ;
V_132 -> V_2 = V_2 ;
}
}
return 0 ;
}
static T_3 F_75 ( struct V_151 * V_20 ,
struct V_152 * V_153 , char * V_154 )
{
struct V_147 * V_137
= F_25 ( V_153 , struct V_147 , V_155 ) ;
return sprintf ( V_154 , L_9 , V_137 -> V_56 ) ;
}
static T_3 F_76 ( struct V_151 * V_20 ,
struct V_152 * V_153 , char * V_154 )
{
struct V_147 * V_137
= F_25 ( V_153 , struct V_147 , V_156 ) ;
int V_157 = 0 ;
if ( ! V_137 -> V_54 )
V_157 = F_17 ( V_137 -> V_55 ) ;
return sprintf ( V_154 , L_9 , V_157 ? L_30 : L_31 ) ;
}
static T_3 F_77 ( struct V_151 * V_20 ,
struct V_152 * V_153 , char * V_154 )
{
struct V_147 * V_137 = F_25 ( V_153 ,
struct V_147 , V_158 ) ;
return sprintf ( V_154 , L_32 , V_137 -> V_54 ) ;
}
static T_3 F_78 ( struct V_151 * V_20 ,
struct V_152 * V_153 , const char * V_154 ,
T_4 V_159 )
{
struct V_147 * V_137
= F_25 ( V_153 , struct V_147 ,
V_158 ) ;
struct V_1 * V_2 = V_137 -> V_2 ;
struct V_34 * V_10 = V_2 -> V_10 ;
int V_8 ;
int V_9 ;
int V_54 ;
int V_160 = 1 ;
V_9 = sscanf ( V_154 , L_33 , & V_54 ) ;
if ( V_9 == 0 ) {
V_9 = - V_119 ;
return V_9 ;
}
if ( ! V_54 ) {
V_137 -> V_54 = 0 ;
return V_159 ;
}
for ( V_8 = 0 ; V_8 < V_10 -> V_52 ; V_8 ++ ) {
if ( & V_10 -> V_53 [ V_8 ] != V_137 &&
! V_10 -> V_53 [ V_8 ] . V_54 ) {
V_160 = 0 ;
break;
}
}
if ( ! V_160 ) {
if ( V_2 -> V_29 ) {
F_12 ( V_137 -> V_2 , false ) ;
V_137 -> V_54 = V_54 ;
F_12 ( V_137 -> V_2 , true ) ;
} else {
V_137 -> V_54 = V_54 ;
}
} else {
F_9 ( V_2 -> V_20 ,
L_34 ,
V_137 -> V_56 ) ;
}
return V_159 ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_34 * V_10 = V_2 -> V_10 ;
struct V_147 * V_137 ;
int V_160 = 1 ;
char V_154 [ 11 ] ;
char * V_161 ;
int V_9 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_10 -> V_52 ; V_8 ++ ) {
V_137 = & V_10 -> V_53 [ V_8 ] ;
snprintf ( V_154 , 10 , L_35 , V_8 ) ;
V_161 = F_80 ( V_2 -> V_20 ,
sizeof( char ) * ( strlen ( V_154 ) + 1 ) , V_162 ) ;
if ( ! V_161 )
return - V_163 ;
strcpy ( V_161 , V_154 ) ;
V_137 -> V_164 [ 0 ] = & V_137 -> V_155 . V_153 ;
V_137 -> V_164 [ 1 ] = & V_137 -> V_156 . V_153 ;
V_137 -> V_164 [ 2 ] = & V_137 -> V_158 . V_153 ;
V_137 -> V_164 [ 3 ] = NULL ;
V_137 -> V_165 . V_138 = V_161 ;
V_137 -> V_165 . V_164 = V_137 -> V_164 ;
F_81 ( & V_137 -> V_155 . V_153 ) ;
V_137 -> V_155 . V_153 . V_138 = L_36 ;
V_137 -> V_155 . V_153 . V_166 = 0444 ;
V_137 -> V_155 . V_167 = F_75 ;
F_81 ( & V_137 -> V_156 . V_153 ) ;
V_137 -> V_156 . V_153 . V_138 = L_37 ;
V_137 -> V_156 . V_153 . V_166 = 0444 ;
V_137 -> V_156 . V_167 = F_76 ;
F_81 ( & V_137 -> V_158 . V_153 ) ;
V_137 -> V_158 . V_153 . V_138
= L_38 ;
V_137 -> V_158 . V_153 . V_166 = 0644 ;
V_137 -> V_158 . V_167
= F_77 ;
V_137 -> V_158 . V_168
= F_78 ;
if ( ! V_10 -> V_53 [ V_8 ] . V_54 ||
! V_160 )
V_160 = 0 ;
F_22 ( V_2 -> V_20 , L_39 ,
V_137 -> V_56 , V_137 -> V_54 ) ;
V_9 = F_82 ( & V_2 -> V_169 -> V_20 . V_62 ,
& V_137 -> V_165 ) ;
if ( V_9 < 0 ) {
F_5 ( V_2 -> V_20 , L_40 ,
V_137 -> V_56 ) ;
return V_9 ;
}
}
if ( V_160 ) {
F_5 ( V_2 -> V_20 , L_41 ) ;
return - V_119 ;
}
return 0 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_5 * V_24 )
{
struct V_34 * V_10 = V_2 -> V_10 ;
union V_3 V_4 ;
int V_9 ;
V_9 = F_3 ( V_24 ,
V_80 , & V_4 ) ;
if ( ! V_9 ) {
V_2 -> V_170 . V_171 [ V_2 -> V_170 . V_172 ] =
V_80 ;
V_2 -> V_170 . V_172 ++ ;
V_2 -> V_10 -> V_81 = true ;
}
#ifdef F_29
if ( V_9 && V_10 -> V_173 ) {
V_2 -> V_82 =
F_84 ( V_10 -> V_173 ) ;
if ( F_73 ( V_2 -> V_82 ) )
return F_74 ( V_2 -> V_82 ) ;
V_2 -> V_170 . V_171 [ V_2 -> V_170 . V_172 ] =
V_117 ;
V_2 -> V_170 . V_172 ++ ;
V_2 -> V_10 -> V_81 = true ;
V_9 = 0 ;
}
#endif
if ( V_2 -> V_10 -> V_81 ) {
if ( ! V_10 -> V_85 )
V_10 -> V_85 = V_174 ;
if ( ! V_10 -> V_87 )
V_10 -> V_87 = V_175 ;
}
return V_9 ;
}
static struct V_34 * F_85 ( struct V_151 * V_20 )
{
struct V_34 * V_10 ;
struct V_176 * V_177 = V_20 -> V_178 ;
T_5 V_179 = V_43 ;
T_5 V_180 = V_13 ;
int V_181 = 0 ;
V_10 = F_80 ( V_20 , sizeof( * V_10 ) , V_162 ) ;
if ( ! V_10 )
return F_86 ( - V_163 ) ;
F_87 ( V_177 , L_42 , & V_10 -> V_182 ) ;
F_88 ( V_177 , L_43 , & V_179 ) ;
V_10 -> V_42 = V_179 ;
F_88 ( V_177 , L_44 ,
& V_10 -> V_99 ) ;
F_88 ( V_177 , L_45 ,
& V_10 -> V_73 ) ;
F_88 ( V_177 , L_46 ,
& V_10 -> V_72 ) ;
F_88 ( V_177 , L_47 , & V_10 -> V_39 ) ;
F_88 ( V_177 , L_48 , & V_10 -> V_40 ) ;
F_88 ( V_177 , L_49 ,
& V_10 -> V_36 ) ;
F_88 ( V_177 , L_50 , & V_180 ) ;
V_10 -> V_11 = V_180 ;
F_88 ( V_177 , L_51 , & V_181 ) ;
if ( V_181 ) {
V_10 -> V_19 = F_80 ( V_20 , sizeof( char * )
* ( V_181 + 1 ) , V_162 ) ;
if ( V_10 -> V_19 ) {
int V_8 ;
for ( V_8 = 0 ; V_8 < V_181 ; V_8 ++ )
F_89 ( V_177 , L_52 ,
V_8 , & V_10 -> V_19 [ V_8 ] ) ;
} else {
return F_86 ( - V_163 ) ;
}
}
F_87 ( V_177 , L_53 , & V_10 -> V_15 ) ;
F_87 ( V_177 , L_54 , & V_10 -> V_173 ) ;
F_88 ( V_177 , L_55 , & V_10 -> V_86 ) ;
if ( F_90 ( V_177 , L_56 , NULL ) )
V_10 -> V_86 *= - 1 ;
F_88 ( V_177 , L_57 , & V_10 -> V_85 ) ;
F_88 ( V_177 , L_58 , & V_10 -> V_87 ) ;
F_88 ( V_177 , L_59 ,
& V_10 -> V_77 ) ;
F_88 ( V_177 , L_60 ,
& V_10 -> V_78 ) ;
V_10 -> V_52 = F_91 ( V_177 ) ;
if ( V_10 -> V_52 ) {
struct V_147 * V_183 ;
struct V_176 * V_184 ;
V_183 = F_80 ( V_20 , sizeof( * V_183 )
* V_10 -> V_52 ,
V_162 ) ;
if ( ! V_183 )
return F_86 ( - V_163 ) ;
V_10 -> V_53 = V_183 ;
F_92 (np, child) {
struct V_131 * V_150 ;
struct V_176 * V_185 ;
F_87 ( V_184 , L_61 ,
& V_183 -> V_56 ) ;
V_183 -> V_149 = F_91 ( V_184 ) ;
if ( V_183 -> V_149 ) {
V_150 = F_80 ( V_20 , sizeof( * V_150 )
* V_183 -> V_149 ,
V_162 ) ;
if ( ! V_150 ) {
F_93 ( V_184 ) ;
return F_86 ( - V_163 ) ;
}
V_183 -> V_150 = V_150 ;
F_92 (child, _child) {
F_87 ( V_185 ,
L_62 , & V_150 -> V_138 ) ;
F_87 ( V_185 ,
L_63 ,
& V_150 -> V_146 ) ;
F_88 ( V_185 ,
L_64 ,
& V_150 -> V_135 ) ;
F_88 ( V_185 ,
L_65 ,
& V_150 -> V_136 ) ;
V_150 ++ ;
}
}
V_183 ++ ;
}
}
return V_10 ;
}
static inline struct V_34 * F_94 ( struct V_186 * V_187 )
{
if ( V_187 -> V_20 . V_178 )
return F_85 ( & V_187 -> V_20 ) ;
return F_95 ( & V_187 -> V_20 ) ;
}
static enum V_188 F_96 ( struct V_189 * V_189 , T_2 V_125 )
{
V_190 = false ;
return V_191 ;
}
static int F_97 ( struct V_186 * V_187 )
{
struct V_34 * V_10 = F_94 ( V_187 ) ;
struct V_1 * V_2 ;
int V_9 , V_8 = 0 ;
int V_148 = 0 ;
union V_3 V_4 ;
struct V_5 * V_24 ;
struct V_192 V_193 = {} ;
if ( F_73 ( V_10 ) ) {
F_5 ( & V_187 -> V_20 , L_66 ) ;
return - V_25 ;
}
V_2 = F_80 ( & V_187 -> V_20 , sizeof( * V_2 ) , V_162 ) ;
if ( ! V_2 )
return - V_163 ;
V_2 -> V_20 = & V_187 -> V_20 ;
V_2 -> V_10 = V_10 ;
V_193 . V_194 = V_2 ;
if ( F_98 () ) {
V_124 = F_80 ( V_2 -> V_20 , sizeof( * V_124 ) , V_162 ) ;
if ( ! V_124 )
return - V_163 ;
F_99 ( V_124 , V_195 , F_96 ) ;
}
if ( V_10 -> V_39 == 0 ) {
F_22 ( & V_187 -> V_20 , L_67 ) ;
}
if ( ! V_10 -> V_73 || ! V_10 -> V_72 ) {
F_22 ( & V_187 -> V_20 , L_68 ) ;
V_10 -> V_73 = 0 ;
V_10 -> V_72 = 0 ;
}
if ( V_10 -> V_40 == 0 ) {
F_22 ( & V_187 -> V_20 , L_69 ) ;
}
if ( V_10 -> V_36 == 0 ) {
F_22 ( & V_187 -> V_20 , L_70 ) ;
}
if ( ! V_10 -> V_53 || V_10 -> V_52 < 1 ) {
F_5 ( & V_187 -> V_20 , L_71 ) ;
return - V_119 ;
}
if ( ! V_10 -> V_19 || ! V_10 -> V_19 [ 0 ] ) {
F_5 ( & V_187 -> V_20 , L_72 ) ;
return - V_119 ;
}
if ( ! V_10 -> V_15 ) {
F_5 ( & V_187 -> V_20 , L_73 ) ;
return - V_119 ;
}
while ( V_10 -> V_19 [ V_8 ] )
V_8 ++ ;
for ( V_8 = 0 ; V_10 -> V_19 [ V_8 ] ; V_8 ++ ) {
struct V_5 * V_6 ;
V_6 = F_2 ( V_10 -> V_19 [ V_8 ] ) ;
if ( ! V_6 ) {
F_5 ( & V_187 -> V_20 , L_1 ,
V_10 -> V_19 [ V_8 ] ) ;
return - V_25 ;
}
F_4 ( V_6 ) ;
}
if ( V_10 -> V_99 == 0 ||
F_39 ( V_10 -> V_99 ) <= V_101 ) {
F_5 ( & V_187 -> V_20 , L_74 ) ;
return - V_119 ;
}
if ( ! V_10 -> V_77 ||
! V_10 -> V_78 ) {
F_22 ( & V_187 -> V_20 , L_75 ) ;
V_10 -> V_77 = 0 ;
V_10 -> V_78 = 0 ;
}
F_100 ( V_187 , V_2 ) ;
memcpy ( & V_2 -> V_170 , & V_196 , sizeof( V_196 ) ) ;
if ( ! V_10 -> V_182 )
strncpy ( V_2 -> V_197 , V_196 . V_138 , V_198 ) ;
else
strncpy ( V_2 -> V_197 , V_10 -> V_182 , V_198 ) ;
V_2 -> V_170 . V_138 = V_2 -> V_197 ;
V_2 -> V_170 . V_171 = F_80 ( & V_187 -> V_20 ,
sizeof( enum V_109 )
* ( F_101 ( V_199 ) +
V_200 ) , V_162 ) ;
if ( ! V_2 -> V_170 . V_171 )
return - V_163 ;
memcpy ( V_2 -> V_170 . V_171 , V_199 ,
sizeof( enum V_109 ) *
F_101 ( V_199 ) ) ;
V_2 -> V_170 . V_172 = V_196 . V_172 ;
V_24 = F_2 ( V_10 -> V_15 ) ;
if ( ! V_24 ) {
F_5 ( & V_187 -> V_20 , L_1 ,
V_10 -> V_15 ) ;
return - V_25 ;
}
if ( ! F_3 ( V_24 ,
V_118 , & V_4 ) ) {
V_2 -> V_170 . V_171 [ V_2 -> V_170 . V_172 ] =
V_118 ;
V_2 -> V_170 . V_172 ++ ;
}
if ( ! F_3 ( V_24 ,
V_116 ,
& V_4 ) ) {
V_2 -> V_170 . V_171 [ V_2 -> V_170 . V_172 ] =
V_116 ;
V_2 -> V_170 . V_172 ++ ;
}
V_9 = F_83 ( V_2 , V_24 ) ;
if ( V_9 ) {
F_5 ( & V_187 -> V_20 , L_76 ) ;
V_2 -> V_10 -> V_81 = false ;
}
F_4 ( V_24 ) ;
F_102 ( & V_2 -> V_68 , F_23 ) ;
V_2 -> V_169 = F_103 ( & V_187 -> V_20 ,
& V_2 -> V_170 ,
& V_193 ) ;
if ( F_73 ( V_2 -> V_169 ) ) {
F_5 ( & V_187 -> V_20 , L_77 ,
V_2 -> V_170 . V_138 ) ;
return F_74 ( V_2 -> V_169 ) ;
}
V_9 = F_71 ( V_2 ) ;
if ( V_9 < 0 ) {
F_5 ( & V_187 -> V_20 , L_78 ) ;
goto V_201;
}
V_9 = F_79 ( V_2 ) ;
if ( V_9 < 0 ) {
F_5 ( & V_187 -> V_20 ,
L_79 ) ;
goto V_202;
}
F_35 ( & V_94 ) ;
F_104 ( & V_2 -> V_203 , & V_204 ) ;
F_37 ( & V_94 ) ;
F_105 ( & V_187 -> V_20 , true ) ;
F_47 ( & V_187 -> V_20 , false ) ;
F_34 () ;
F_45 ( & V_106 ) ;
return 0 ;
V_202:
for ( V_8 = 0 ; V_8 < V_10 -> V_52 ; V_8 ++ ) {
struct V_147 * V_137 ;
V_137 = & V_10 -> V_53 [ V_8 ] ;
F_106 ( & V_2 -> V_169 -> V_20 . V_62 ,
& V_137 -> V_165 ) ;
}
V_201:
for ( V_8 = 0 ; V_8 < V_10 -> V_52 ; V_8 ++ ) {
struct V_147 * V_137 ;
V_137 = & V_10 -> V_53 [ V_8 ] ;
for ( V_148 = 0 ; V_148 < V_137 -> V_149 ; V_148 ++ ) {
struct V_131 * V_132 = & V_137 -> V_150 [ V_148 ] ;
if ( V_132 -> V_145 . V_205 )
F_107 ( & V_132 -> V_145 ) ;
}
F_108 ( V_10 -> V_53 [ V_8 ] . V_55 ) ;
}
F_109 ( V_2 -> V_169 ) ;
return V_9 ;
}
static int F_110 ( struct V_186 * V_187 )
{
struct V_1 * V_2 = F_111 ( V_187 ) ;
struct V_34 * V_10 = V_2 -> V_10 ;
int V_8 = 0 ;
int V_148 = 0 ;
F_35 ( & V_94 ) ;
F_112 ( & V_2 -> V_203 ) ;
F_37 ( & V_94 ) ;
F_67 ( & V_106 ) ;
F_113 ( & V_105 ) ;
for ( V_8 = 0 ; V_8 < V_10 -> V_52 ; V_8 ++ ) {
struct V_147 * V_137
= & V_10 -> V_53 [ V_8 ] ;
for ( V_148 = 0 ; V_148 < V_137 -> V_149 ; V_148 ++ ) {
struct V_131 * V_132 = & V_137 -> V_150 [ V_148 ] ;
F_107 ( & V_132 -> V_145 ) ;
}
}
for ( V_8 = 0 ; V_8 < V_10 -> V_52 ; V_8 ++ )
F_108 ( V_10 -> V_53 [ V_8 ] . V_55 ) ;
F_109 ( V_2 -> V_169 ) ;
F_12 ( V_2 , false ) ;
return 0 ;
}
static int F_114 ( struct V_151 * V_20 )
{
if ( F_115 ( V_20 ) ) {
F_47 ( V_20 , false ) ;
return - V_49 ;
}
return 0 ;
}
static bool F_116 ( void )
{
struct V_1 * V_2 ;
if ( V_124 )
return false ;
F_35 ( & V_94 ) ;
F_36 (cm, &cm_list, entry) {
if ( F_8 ( V_2 ) ) {
F_37 ( & V_94 ) ;
return true ;
}
}
F_37 ( & V_94 ) ;
return false ;
}
static int F_117 ( struct V_151 * V_20 )
{
struct V_1 * V_2 = F_118 ( V_20 ) ;
if ( F_116 () )
return - V_206 ;
if ( ! V_61 )
V_61 = true ;
V_190 = F_53 () ;
if ( V_190 ) {
F_67 ( & V_106 ) ;
F_113 ( & V_105 ) ;
F_119 ( & V_2 -> V_68 ) ;
}
return 0 ;
}
static void F_120 ( struct V_151 * V_20 )
{
struct V_1 * V_2 = F_118 ( V_20 ) ;
if ( V_61 )
V_61 = false ;
if ( V_190 ) {
T_2 V_207 ;
F_121 ( V_124 ) ;
V_190 = false ;
V_207 = F_122 ( V_124 ) ;
V_130 -= F_13 ( V_207 ) ;
F_45 ( & V_106 ) ;
}
F_32 ( V_2 ) ;
if ( V_2 -> V_71 ) {
unsigned long V_208 = 0 ;
unsigned long V_125 = V_103 + V_101 ;
if ( F_123 ( V_125 , V_2 -> V_71 ) ) {
V_208 = ( unsigned long ) ( ( long ) V_125
- ( long ) ( V_2 -> V_71 ) ) ;
V_208 = F_56 ( V_208 ) ;
} else {
V_208 = 0 ;
}
if ( V_208 > V_130 )
V_208 -= V_130 ;
else
V_208 = 0 ;
F_43 ( V_102 , & V_2 -> V_68 ,
F_39 ( V_208 ) ) ;
}
F_47 ( V_2 -> V_20 , false ) ;
}
static int T_6 F_124 ( void )
{
V_102 = F_125 ( L_80 ) ;
F_102 ( & V_105 , F_44 ) ;
return F_126 ( & V_209 ) ;
}
static void T_7 F_127 ( void )
{
F_128 ( V_102 ) ;
V_102 = NULL ;
F_129 ( & V_209 ) ;
}
void F_130 ( struct V_5 * V_6 , enum V_108 type ,
char * V_210 )
{
struct V_1 * V_2 ;
bool V_211 = false ;
if ( V_6 == NULL )
return;
F_35 ( & V_94 ) ;
F_36 (cm, &cm_list, entry) {
if ( F_131 ( V_2 -> V_10 -> V_19 , - 1 ,
V_6 -> V_10 -> V_138 ) >= 0 ) {
V_211 = true ;
break;
}
}
F_37 ( & V_94 ) ;
if ( ! V_211 )
return;
switch ( type ) {
case V_92 :
F_46 ( V_2 ) ;
break;
case V_107 :
F_48 ( V_2 ) ;
break;
case V_212 :
case V_213 ... V_214 :
F_50 ( V_2 , type ) ;
break;
case V_215 :
case V_216 :
F_20 ( V_2 , V_210 ? V_210 : V_91 [ type ] ) ;
break;
default:
F_5 ( V_2 -> V_20 , L_81 , V_74 ) ;
break;
}
}

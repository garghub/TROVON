static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return V_2 -> V_4 [ V_3 ] & V_5 ;
}
static int F_2 ( struct V_1 * V_2 ,
int V_3 )
{
return ( int ) ( V_2 -> V_4 [ V_3 ] & V_6 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_3 ,
T_1 V_7 )
{
V_2 -> V_4 [ V_3 ] = V_7 ;
}
static bool F_4 ( struct V_8 * V_9 , unsigned long V_10 )
{
unsigned long V_11 , V_12 , V_13 = 0 ;
bool V_14 ;
F_5 ( V_9 -> V_15 . V_16 ) ;
V_11 = F_6 ( V_17 , V_10 , V_13 , V_12 ) ;
switch ( V_11 ) {
case V_18 :
V_9 -> V_12 = V_12 ;
V_14 = true ;
break;
case V_19 :
V_9 -> V_12 = V_20 ;
V_14 = true ;
break;
default:
V_14 = false ;
}
if ( V_9 -> V_12 & V_21 )
V_9 -> V_22 = 2 ;
else
V_9 -> V_22 = 1 ;
if ( ! V_14 ) {
F_7 ( L_1 , V_23 , V_11 ) ;
F_5 ( V_9 -> V_15 . V_24 ) ;
}
return V_14 ;
}
static bool F_8 ( struct V_8 * V_9 , unsigned long V_11 )
{
switch ( V_11 ) {
case V_19 :
return true ;
case V_25 :
V_9 -> V_26 = true ;
default:
return false ;
}
}
static bool F_9 ( struct V_8 * V_9 )
{
unsigned long V_11 , V_13 = 0 ;
V_11 = F_6 ( V_27 , V_28 , V_13 ,
V_13 ) ;
F_5 ( V_9 -> V_15 . V_29 ) ;
if ( F_8 ( V_9 , V_11 ) )
return true ;
F_7 ( L_1 , V_23 , V_11 ) ;
F_5 ( V_9 -> V_15 . V_30 ) ;
return false ;
}
static T_2 F_10 ( bool V_31 )
{
if ( V_31 )
return 1 << V_32 ;
return 1 ;
}
static bool F_11 ( struct V_8 * V_9 , T_3 * V_33 )
{
unsigned long V_11 ;
unsigned long V_34 ;
unsigned long V_35 ;
unsigned long V_13 = 0 ;
T_3 V_36 ;
F_12 ( & V_9 -> V_37 ) ;
V_35 = V_9 -> V_37 . V_38 ;
V_36 = ( T_3 ) V_35 ;
if ( V_35 != V_36 )
return false ;
F_5 ( V_9 -> V_15 . V_34 ) ;
V_11 = F_6 ( V_39 , V_35 , V_13 , V_34 ) ;
if ( F_8 ( V_9 , V_11 ) ) {
* V_33 = V_34 ;
return true ;
}
F_7 ( L_1 , V_23 , V_11 ) ;
F_5 ( V_9 -> V_15 . V_40 ) ;
return false ;
}
static int F_13 ( struct V_8 * V_9 , unsigned long V_41 ,
unsigned int * V_42 , unsigned int * V_34 )
{
unsigned long V_11 , V_13 = 0 ;
T_3 V_43 ;
V_43 = ( T_3 ) V_41 ;
if ( V_43 != V_41 )
return - 1 ;
F_5 ( V_9 -> V_15 . V_44 [ false ] ) ;
* V_42 = V_11 = F_6 ( V_45 , V_41 , V_13 , * V_34 ) ;
if ( F_8 ( V_9 , V_11 ) )
return 0 ;
F_7 ( L_2 , V_23 , V_41 , V_11 ) ;
F_5 ( V_9 -> V_15 . V_46 [ false ] ) ;
return 1 ;
}
static int F_14 ( struct V_8 * V_9 ,
unsigned int V_47 , bool V_48 , unsigned int * V_34 )
{
unsigned long V_11 ;
unsigned long V_41 = F_15 ( V_9 -> V_49 ) ;
F_5 ( V_9 -> V_15 . V_44 [ V_48 ] ) ;
if ( V_48 )
V_11 = F_6 ( V_50 , V_41 , V_47 ,
* V_34 ) ;
else
V_11 = F_6 ( V_51 , V_41 , V_47 ,
* V_34 ) ;
if ( F_8 ( V_9 , V_11 ) )
return 0 ;
F_7 ( L_3 , V_23 , V_41 , V_11 ) ;
F_5 ( V_9 -> V_15 . V_46 [ V_48 ] ) ;
return 1 ;
}
static bool F_16 ( struct V_8 * V_9 , unsigned long V_41 ,
unsigned int * V_34 )
{
unsigned long V_11 , V_13 = 0 ;
T_3 V_43 ;
V_43 = ( T_3 ) V_41 ;
if ( V_43 != V_41 )
return false ;
F_5 ( V_9 -> V_15 . V_52 [ false ] ) ;
V_11 = F_6 ( V_53 , V_41 , V_13 , * V_34 ) ;
if ( F_8 ( V_9 , V_11 ) )
return true ;
F_7 ( L_2 , V_23 , V_41 , V_11 ) ;
F_5 ( V_9 -> V_15 . V_54 [ false ] ) ;
return false ;
}
static bool F_17 ( struct V_8 * V_9 ,
unsigned int V_47 , bool V_48 , unsigned int * V_34 )
{
unsigned long V_11 ;
unsigned long V_41 = F_15 ( V_9 -> V_49 ) ;
F_5 ( V_9 -> V_15 . V_52 [ V_48 ] ) ;
if ( V_48 )
V_11 = F_6 ( V_55 , V_41 , V_47 ,
* V_34 ) ;
else
V_11 = F_6 ( V_56 , V_41 , V_47 ,
* V_34 ) ;
if ( F_8 ( V_9 , V_11 ) )
return true ;
F_7 ( L_3 , V_23 , V_41 , V_11 ) ;
F_5 ( V_9 -> V_15 . V_54 [ V_48 ] ) ;
return false ;
}
static struct V_49 * F_18 ( T_4 V_57 , bool V_31 )
{
if ( V_31 )
return F_19 ( V_57 , V_32 ) ;
return F_20 ( V_57 ) ;
}
static void F_21 ( struct V_49 * V_49 , bool V_31 )
{
if ( V_31 )
F_22 ( V_49 , V_32 ) ;
else
F_23 ( V_49 ) ;
}
static void F_24 ( struct V_8 * V_9 )
{
struct V_49 * V_49 , * V_58 ;
unsigned V_48 ;
for ( V_48 = 0 ; V_48 < V_59 ;
V_48 ++ ) {
struct F_10 * V_60 =
& V_9 -> V_61 [ V_48 ] ;
T_2 V_62 = F_10 ( V_48 ) ;
F_25 (page, next, &page_size->pages, lru) {
F_26 ( & V_49 -> V_63 ) ;
F_21 ( V_49 , V_48 ) ;
F_5 ( V_9 -> V_15 . free [ V_48 ] ) ;
V_9 -> V_64 -= V_62 ;
F_27 () ;
}
}
if ( V_9 -> V_65 ) {
F_28 ( V_9 -> V_65 ) ;
V_9 -> V_65 = NULL ;
}
if ( V_9 -> V_49 ) {
F_23 ( V_9 -> V_49 ) ;
V_9 -> V_49 = NULL ;
}
}
static int F_29 ( struct V_8 * V_9 , unsigned int V_47 ,
bool V_48 , unsigned int * V_34 )
{
int V_66 , V_42 ;
struct V_49 * V_49 = V_9 -> V_49 ;
struct F_10 * V_60 = & V_9 -> V_61 [ false ] ;
V_66 = F_13 ( V_9 , F_15 ( V_49 ) , & V_42 ,
V_34 ) ;
if ( V_66 > 0 ) {
F_5 ( V_9 -> V_15 . V_67 [ false ] ) ;
if ( V_42 == V_25 ||
V_42 == V_68 ) {
F_21 ( V_49 , false ) ;
return - V_69 ;
}
if ( V_60 -> V_70 < V_71 ) {
V_60 -> V_70 ++ ;
F_30 ( & V_49 -> V_63 , & V_60 -> V_72 ) ;
} else {
F_21 ( V_49 , false ) ;
}
return - V_69 ;
}
F_30 ( & V_49 -> V_63 , & V_60 -> V_4 ) ;
V_9 -> V_64 ++ ;
return 0 ;
}
static int F_31 ( struct V_8 * V_9 ,
unsigned int V_47 , bool V_48 , unsigned int * V_34 )
{
int V_66 , V_73 ;
T_2 V_62 = F_10 ( V_48 ) ;
V_66 = F_14 ( V_9 , V_47 , V_48 ,
V_34 ) ;
if ( V_66 > 0 ) {
for ( V_73 = 0 ; V_73 < V_47 ; V_73 ++ ) {
T_1 V_7 = F_1 ( V_9 -> V_65 , V_73 ) ;
struct V_49 * V_74 = F_32 ( V_7 >> V_75 ) ;
F_21 ( V_74 , V_48 ) ;
}
return - V_69 ;
}
for ( V_73 = 0 ; V_73 < V_47 ; V_73 ++ ) {
T_1 V_7 = F_1 ( V_9 -> V_65 , V_73 ) ;
struct V_49 * V_74 = F_32 ( V_7 >> V_75 ) ;
struct F_10 * V_60 =
& V_9 -> V_61 [ V_48 ] ;
V_66 = F_2 ( V_9 -> V_65 , V_73 ) ;
switch ( V_66 ) {
case V_19 :
F_30 ( & V_74 -> V_63 , & V_60 -> V_4 ) ;
V_9 -> V_64 += V_62 ;
break;
case V_76 :
case V_77 :
if ( V_60 -> V_70
< V_71 ) {
F_30 ( & V_74 -> V_63 , & V_60 -> V_72 ) ;
V_60 -> V_70 ++ ;
break;
}
case V_25 :
case V_68 :
F_21 ( V_74 , V_48 ) ;
break;
default:
F_33 ( true ) ;
}
}
return 0 ;
}
static int F_34 ( struct V_8 * V_9 , unsigned int V_47 ,
bool V_48 , unsigned int * V_34 )
{
struct V_49 * V_49 = V_9 -> V_49 ;
struct F_10 * V_60 = & V_9 -> V_61 [ false ] ;
if ( ! F_16 ( V_9 , F_15 ( V_49 ) , V_34 ) ) {
F_30 ( & V_49 -> V_63 , & V_60 -> V_4 ) ;
return - V_69 ;
}
F_21 ( V_49 , false ) ;
F_5 ( V_9 -> V_15 . free [ false ] ) ;
V_9 -> V_64 -- ;
return 0 ;
}
static int F_35 ( struct V_8 * V_9 ,
unsigned int V_47 , bool V_48 ,
unsigned int * V_34 )
{
int V_66 , V_73 , V_78 = 0 ;
bool V_79 ;
T_2 V_62 = F_10 ( V_48 ) ;
V_79 = F_17 ( V_9 , V_47 , V_48 ,
V_34 ) ;
if ( ! V_79 )
V_78 = - V_69 ;
for ( V_73 = 0 ; V_73 < V_47 ; V_73 ++ ) {
T_1 V_7 = F_1 ( V_9 -> V_65 , V_73 ) ;
struct V_49 * V_74 = F_32 ( V_7 >> V_75 ) ;
struct F_10 * V_60 =
& V_9 -> V_61 [ V_48 ] ;
V_66 = F_2 ( V_9 -> V_65 , V_73 ) ;
if ( ! V_79 || V_66 != V_19 ) {
F_30 ( & V_74 -> V_63 , & V_60 -> V_4 ) ;
} else {
F_21 ( V_74 , V_48 ) ;
F_5 ( V_9 -> V_15 . free [ V_48 ] ) ;
V_9 -> V_64 -= V_62 ;
}
}
return V_78 ;
}
static void F_36 ( struct V_8 * V_9 ,
bool V_48 )
{
struct V_49 * V_49 , * V_58 ;
struct F_10 * V_60 =
& V_9 -> V_61 [ V_48 ] ;
F_25 (page, next, &page_size->refused_pages, lru) {
F_26 ( & V_49 -> V_63 ) ;
F_21 ( V_49 , V_48 ) ;
F_5 ( V_9 -> V_15 . V_80 [ V_48 ] ) ;
}
V_60 -> V_70 = 0 ;
}
static void F_37 ( struct V_8 * V_9 , int V_3 , struct V_49 * V_74 )
{
V_9 -> V_49 = V_74 ;
}
static void F_38 ( struct V_8 * V_9 , int V_3 ,
struct V_49 * V_74 )
{
F_3 ( V_9 -> V_65 , V_3 ,
( T_1 ) F_15 ( V_74 ) << V_75 ) ;
}
static void F_39 ( struct V_8 * V_9 )
{
unsigned V_81 ;
unsigned int V_82 = 0 ;
unsigned int V_47 = 0 ;
int error = 0 ;
T_4 V_57 = V_83 ;
bool V_48 ;
F_7 ( L_4 , V_23 , V_9 -> V_64 , V_9 -> V_34 ) ;
if ( V_9 -> V_84 ) {
V_81 = V_9 -> V_85 ;
V_48 = false ;
} else {
V_81 = V_86 ;
V_48 =
V_9 -> V_22 == V_59 ;
}
F_7 ( L_5 ,
V_23 , V_9 -> V_34 - V_9 -> V_64 , V_81 , V_9 -> V_85 ) ;
while ( ! V_9 -> V_26 &&
V_9 -> V_64 + V_47 * F_10 ( V_48 )
< V_9 -> V_34 ) {
struct V_49 * V_49 ;
if ( V_57 == V_83 )
F_5 ( V_9 -> V_15 . V_87 [ V_48 ] ) ;
else
F_5 ( V_9 -> V_15 . V_88 ) ;
V_49 = F_18 ( V_57 , V_48 ) ;
if ( ! V_49 ) {
F_5 ( V_9 -> V_15 . V_89 [ V_48 ] ) ;
if ( V_48 ) {
V_9 -> V_90 -> V_44 ( V_9 , V_47 , true , & V_9 -> V_34 ) ;
V_47 = 0 ;
V_48 = false ;
continue;
}
if ( V_57 == V_91 ) {
V_9 -> V_85 = F_40 ( V_9 -> V_85 / 2 ,
V_92 ) ;
F_5 ( V_9 -> V_15 . V_93 ) ;
break;
}
V_9 -> V_84 = V_94 ;
if ( V_82 >= V_9 -> V_85 )
break;
V_57 = V_91 ;
V_81 = V_9 -> V_85 ;
continue;
}
V_9 -> V_90 -> V_95 ( V_9 , V_47 ++ , V_49 ) ;
if ( V_47 == V_9 -> V_96 ) {
error = V_9 -> V_90 -> V_44 ( V_9 , V_47 , V_48 ,
& V_9 -> V_34 ) ;
V_47 = 0 ;
if ( error )
break;
}
F_27 () ;
if ( V_82 >= V_81 ) {
break;
}
}
if ( V_47 > 0 )
V_9 -> V_90 -> V_44 ( V_9 , V_47 , V_48 , & V_9 -> V_34 ) ;
if ( error == 0 && V_82 >= V_9 -> V_85 ) {
unsigned int V_97 = V_82 / V_9 -> V_85 ;
V_9 -> V_85 =
F_41 ( V_9 -> V_85 + V_97 * V_98 ,
V_99 ) ;
}
F_36 ( V_9 , true ) ;
F_36 ( V_9 , false ) ;
}
static void F_42 ( struct V_8 * V_9 )
{
unsigned V_48 ;
F_7 ( L_4 , V_23 , V_9 -> V_64 , V_9 -> V_34 ) ;
for ( V_48 = 0 ; V_48 < V_9 -> V_22 ;
V_48 ++ ) {
struct V_49 * V_49 , * V_58 ;
unsigned int V_47 = 0 ;
struct F_10 * V_60 =
& V_9 -> V_61 [ V_48 ] ;
F_25 (page, next, &page_size->pages, lru) {
if ( V_9 -> V_26 ||
( V_9 -> V_34 > 0 &&
V_9 -> V_64 - V_47
* F_10 ( V_48 )
< V_9 -> V_34 + F_10 ( true ) ) )
break;
F_26 ( & V_49 -> V_63 ) ;
V_9 -> V_90 -> V_95 ( V_9 , V_47 ++ , V_49 ) ;
if ( V_47 == V_9 -> V_96 ) {
int error ;
error = V_9 -> V_90 -> V_52 ( V_9 , V_47 ,
V_48 , & V_9 -> V_34 ) ;
V_47 = 0 ;
if ( error )
return;
}
F_27 () ;
}
if ( V_47 > 0 )
V_9 -> V_90 -> V_52 ( V_9 , V_47 , V_48 , & V_9 -> V_34 ) ;
}
}
static bool F_43 ( struct V_8 * V_9 )
{
V_9 -> V_49 = F_20 ( V_83 ) ;
if ( ! V_9 -> V_49 )
return false ;
V_9 -> V_65 = F_44 ( & V_9 -> V_49 , 1 , V_100 , V_101 ) ;
if ( ! V_9 -> V_65 ) {
F_23 ( V_9 -> V_49 ) ;
return false ;
}
return true ;
}
static void F_45 ( void * V_102 )
{
struct V_8 * V_9 = V_102 ;
F_5 ( V_9 -> V_15 . V_103 ) ;
F_46 ( V_104 , & V_9 -> V_105 , 0 ) ;
}
static void F_47 ( struct V_8 * V_9 )
{
int error ;
F_6 ( V_106 , V_107 ,
V_107 , error ) ;
F_5 ( V_9 -> V_15 . V_108 ) ;
if ( ! F_48 ( V_9 -> V_109 ) ) {
F_49 ( V_9 -> V_109 ) ;
V_9 -> V_109 = V_110 ;
}
}
static int F_50 ( struct V_8 * V_9 )
{
int error = 0 ;
if ( ( V_9 -> V_12 & V_111 ) != 0 ) {
error = F_51 ( & V_9 -> V_109 ,
V_112 ,
V_113 ,
F_45 , V_9 ) ;
if ( error == V_114 ) {
F_6 ( V_106 ,
V_9 -> V_109 . V_115 ,
V_9 -> V_109 . V_116 , error ) ;
F_5 ( V_9 -> V_15 . V_117 ) ;
}
}
if ( error != 0 ) {
F_47 ( V_9 ) ;
return - V_69 ;
}
return 0 ;
}
static void F_52 ( struct V_8 * V_9 )
{
int error ;
F_47 ( V_9 ) ;
F_24 ( V_9 ) ;
if ( ! F_4 ( V_9 , V_118 ) )
return;
if ( ( V_9 -> V_12 & V_119 ) != 0 ) {
V_9 -> V_90 = & V_120 ;
V_9 -> V_96 = V_121 ;
if ( ! F_43 ( V_9 ) ) {
F_4 ( V_9 , 0 ) ;
return;
}
} else if ( ( V_9 -> V_12 & V_20 ) != 0 ) {
V_9 -> V_90 = & V_122 ;
V_9 -> V_96 = 1 ;
}
V_9 -> V_26 = false ;
error = F_50 ( V_9 ) ;
if ( error )
F_53 ( L_6 ) ;
if ( ! F_9 ( V_9 ) )
F_53 ( L_7 ) ;
}
static void F_54 ( struct V_123 * V_124 )
{
struct V_125 * V_105 = F_55 ( V_124 ) ;
struct V_8 * V_9 = F_56 ( V_105 , struct V_8 , V_105 ) ;
unsigned int V_34 ;
F_5 ( V_9 -> V_15 . V_126 ) ;
if ( V_9 -> V_26 )
F_52 ( V_9 ) ;
if ( V_9 -> V_84 > 0 )
V_9 -> V_84 -- ;
if ( ! V_9 -> V_26 && F_11 ( V_9 , & V_34 ) ) {
V_9 -> V_34 = V_34 ;
if ( V_9 -> V_64 < V_34 )
F_39 ( V_9 ) ;
else if ( V_34 == 0 ||
V_9 -> V_64 > V_34 + F_10 ( true ) )
F_42 ( V_9 ) ;
}
F_57 ( V_104 ,
V_105 , F_58 ( V_127 ) ) ;
}
static int F_59 ( struct V_128 * V_129 , void * V_130 )
{
struct V_8 * V_9 = V_129 -> V_131 ;
struct V_132 * V_15 = & V_9 -> V_15 ;
F_60 ( V_129 ,
L_8
L_9
L_10 ,
V_118 , V_9 -> V_12 ,
V_9 -> V_26 ? 'y' : 'n' ) ;
F_60 ( V_129 ,
L_11
L_12 ,
V_9 -> V_34 , V_9 -> V_64 ) ;
F_60 ( V_129 ,
L_13 ,
V_9 -> V_85 ) ;
F_60 ( V_129 ,
L_14
L_15
L_16
L_17
L_18
L_19
L_20
L_21
L_22
L_23
L_24
L_25
L_26
L_27
L_28
L_29
L_30
L_31
L_32
L_33
L_34 ,
V_15 -> V_126 ,
V_15 -> V_103 ,
V_15 -> V_16 , V_15 -> V_24 ,
V_15 -> V_29 , V_15 -> V_30 ,
V_15 -> V_44 [ true ] , V_15 -> V_46 [ true ] ,
V_15 -> V_44 [ false ] , V_15 -> V_46 [ false ] ,
V_15 -> V_52 [ true ] , V_15 -> V_54 [ true ] ,
V_15 -> V_52 [ false ] , V_15 -> V_54 [ false ] ,
V_15 -> V_34 , V_15 -> V_40 ,
V_15 -> V_87 [ true ] , V_15 -> V_89 [ true ] ,
V_15 -> V_87 [ false ] , V_15 -> V_89 [ false ] ,
V_15 -> V_88 , V_15 -> V_93 ,
V_15 -> free [ true ] ,
V_15 -> free [ false ] ,
V_15 -> V_67 [ true ] , V_15 -> V_67 [ false ] ,
V_15 -> V_80 [ true ] , V_15 -> V_80 [ false ] ,
V_15 -> V_117 , V_15 -> V_108 ) ;
return 0 ;
}
static int F_61 ( struct V_133 * V_133 , struct V_134 * V_134 )
{
return F_62 ( V_134 , F_59 , V_133 -> V_135 ) ;
}
static int T_5 F_63 ( struct V_8 * V_9 )
{
int error ;
V_9 -> V_136 = F_64 ( L_35 , V_137 , NULL , V_9 ,
& V_138 ) ;
if ( F_65 ( V_9 -> V_136 ) ) {
error = F_66 ( V_9 -> V_136 ) ;
F_53 ( L_36 , error ) ;
return error ;
}
return 0 ;
}
static void T_6 F_67 ( struct V_8 * V_9 )
{
F_68 ( V_9 -> V_136 ) ;
}
static inline int F_63 ( struct V_8 * V_9 )
{
return 0 ;
}
static inline void F_67 ( struct V_8 * V_9 )
{
}
static int T_5 F_69 ( void )
{
int error ;
unsigned V_48 ;
if ( V_139 != & V_140 )
return - V_141 ;
for ( V_48 = 0 ; V_48 < V_59 ;
V_48 ++ ) {
F_70 ( & V_142 . V_61 [ V_48 ] . V_4 ) ;
F_70 ( & V_142 . V_61 [ V_48 ] . V_72 ) ;
}
V_142 . V_85 = V_99 ;
F_71 ( & V_142 . V_105 , F_54 ) ;
error = F_63 ( & V_142 ) ;
if ( error )
return error ;
V_142 . V_109 = V_110 ;
V_142 . V_65 = NULL ;
V_142 . V_49 = NULL ;
V_142 . V_26 = true ;
F_57 ( V_104 , & V_142 . V_105 , 0 ) ;
return 0 ;
}
static void T_6 F_72 ( void )
{
F_47 ( & V_142 ) ;
F_73 ( & V_142 . V_105 ) ;
F_67 ( & V_142 ) ;
F_4 ( & V_142 , 0 ) ;
F_24 ( & V_142 ) ;
}

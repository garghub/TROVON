static inline void F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 = V_2 -> V_3 ;
F_2 ( L_1 ,
V_2 -> V_4 , V_3 -> V_4 , V_3 -> V_5 ) ;
F_3 ( & V_3 -> V_6 , 1 ) ;
V_3 -> V_7 -- ;
V_3 -> V_5 -- ;
if ( V_3 -> V_5 == 0 )
F_4 ( V_3 , V_8 ) ;
F_5 ( & V_3 -> V_6 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
const struct V_9 * V_10 ;
const struct V_11 * V_12 , * V_13 ;
unsigned long V_14 , V_15 ;
int V_16 = - 1 ;
ASSERT ( V_2 != NULL ) ;
F_2 ( L_2 ,
V_2 -> V_4 , V_2 -> V_12 -> V_17 , V_2 -> V_14 ) ;
V_15 = V_2 -> V_15 ;
V_18:
V_2 -> V_15 = 0 ;
V_12 = V_2 -> V_12 ;
V_19:
V_14 = V_2 -> V_14 ;
if ( V_14 & V_2 -> V_20 ) {
F_7 ( L_3 ,
V_2 -> V_4 , V_14 & V_2 -> V_20 ) ;
for ( V_10 = V_2 -> V_21 ; V_10 -> V_14 ; V_10 ++ ) {
if ( V_14 & V_10 -> V_14 ) {
V_12 = V_10 -> V_22 ;
ASSERT ( V_12 -> V_23 != NULL ) ;
V_16 = F_8 ( V_14 & V_10 -> V_14 ) - 1 ;
F_9 ( V_16 , & V_2 -> V_20 ) ;
F_10 ( V_16 , & V_2 -> V_14 ) ;
goto V_24;
}
}
}
if ( ! V_12 -> V_23 ) {
if ( V_14 & V_15 ) {
for ( V_10 = V_12 -> V_25 ; V_10 -> V_14 ; V_10 ++ ) {
if ( V_14 & V_10 -> V_14 ) {
V_13 = V_10 -> V_22 ;
V_16 = F_8 ( V_14 & V_10 -> V_14 ) - 1 ;
F_10 ( V_16 , & V_2 -> V_14 ) ;
F_7 ( L_4 ,
V_2 -> V_4 , V_16 ,
V_12 -> V_17 , V_13 -> V_17 ) ;
V_2 -> V_12 = V_12 = V_13 ;
goto V_24;
}
}
F_11 () ;
}
goto V_26;
}
V_24:
F_7 ( L_5 , V_2 -> V_4 , V_12 -> V_17 ) ;
V_13 = V_12 -> V_23 ( V_2 , V_16 ) ;
V_16 = - 1 ;
if ( V_13 == V_27 ) {
F_7 ( L_6 , V_2 -> V_4 , V_12 -> V_17 ) ;
F_12 ( V_2 ) ;
V_15 = V_2 -> V_20 ;
goto V_26;
}
F_7 ( L_7 ,
V_2 -> V_4 , V_12 -> V_17 , V_13 -> V_17 ) ;
V_2 -> V_12 = V_12 = V_13 ;
if ( V_12 -> V_23 ) {
if ( F_13 ( V_12 -> V_23 == ( ( void * ) 2UL ) ) ) {
F_14 ( L_8 ) ;
return;
}
goto V_19;
}
V_15 = V_2 -> V_20 ;
for ( V_10 = V_12 -> V_25 ; V_10 -> V_14 ; V_10 ++ )
V_15 |= V_10 -> V_14 ;
V_26:
V_2 -> V_15 = V_15 ;
F_15 () ;
V_14 = V_2 -> V_14 ;
if ( V_14 & V_15 )
goto V_18;
F_14 ( L_9 , V_15 ) ;
}
static void F_16 ( struct V_28 * V_23 )
{
struct V_1 * V_2 =
F_17 ( V_23 , struct V_1 , V_23 ) ;
unsigned long V_29 ;
F_2 ( L_10 , V_2 -> V_4 ) ;
V_29 = V_30 ;
F_6 ( V_2 ) ;
F_18 ( V_31 , V_29 ) ;
F_19 ( V_2 ) ;
}
void F_20 ( struct V_1 * V_2 ,
struct V_32 * V_33 ,
struct V_34 * V_35 )
{
const struct V_9 * V_10 ;
F_21 ( & V_35 -> V_36 ) ;
V_2 -> V_12 = F_22 ( V_37 ) ;
V_2 -> V_21 = V_38 ;
V_2 -> V_39 = 1 << V_40 ;
F_23 ( & V_2 -> V_6 ) ;
F_24 ( & V_2 -> V_41 ) ;
F_25 ( & V_2 -> V_42 ) ;
F_26 ( & V_2 -> V_23 , F_16 ) ;
F_24 ( & V_2 -> V_43 ) ;
F_24 ( & V_2 -> V_44 ) ;
F_24 ( & V_2 -> V_45 ) ;
V_2 -> V_46 = 0 ;
V_2 -> V_5 = V_2 -> V_47 = V_2 -> V_48 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_49 = 0 ;
V_2 -> V_50 = 0 ;
V_2 -> V_35 = V_35 ;
V_2 -> V_33 = V_33 ;
V_2 -> V_3 = NULL ;
#ifdef F_27
F_28 ( & V_2 -> V_51 ) ;
#endif
V_2 -> V_20 = 0 ;
for ( V_10 = V_2 -> V_21 ; V_10 -> V_14 ; V_10 ++ )
V_2 -> V_20 |= V_10 -> V_14 ;
V_2 -> V_15 = V_2 -> V_20 ;
for ( V_10 = V_2 -> V_12 -> V_25 ; V_10 -> V_14 ; V_10 ++ )
V_2 -> V_15 |= V_10 -> V_14 ;
}
static const struct V_11 * F_29 ( struct V_1 * V_2 ,
int V_16 )
{
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
V_2 -> V_20 = 0 ;
F_30 ( V_2 ) ;
return V_22 ( V_52 ) ;
}
static const struct V_11 * F_31 ( struct V_1 * V_2 ,
int V_16 )
{
struct V_1 * V_3 ;
bool V_53 ;
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
ASSERT ( F_32 ( & V_2 -> V_44 ) ) ;
V_3 = V_2 -> V_3 ;
if ( ! V_3 ) {
F_14 ( L_12 ) ;
return V_22 ( V_54 ) ;
}
F_7 ( L_13 , V_3 -> V_12 -> V_17 , V_3 -> V_39 ) ;
if ( F_33 ( V_3 ) ) {
F_14 ( L_14 ) ;
return V_22 ( V_54 ) ;
}
if ( F_34 ( V_3 ) ) {
F_14 ( L_15 ) ;
return V_22 ( V_55 ) ;
}
F_7 ( L_16 ) ;
F_35 ( & V_3 -> V_6 ) ;
F_36 ( & V_56 ) ;
V_53 = false ;
if ( F_37 ( V_3 ) &&
V_2 -> V_35 -> V_57 -> V_58 ( V_2 ) ) {
F_38 ( & V_2 -> V_44 , & V_3 -> V_43 ) ;
V_53 = true ;
}
F_39 ( & V_56 ) ;
F_5 ( & V_3 -> V_6 ) ;
if ( ! V_53 ) {
F_14 ( L_17 ) ;
return V_22 ( V_54 ) ;
}
F_4 ( V_3 , V_59 ) ;
F_14 ( L_18 ) ;
return V_22 ( V_60 ) ;
}
static const struct V_11 * F_40 ( struct V_1 * V_2 ,
int V_16 )
{
struct V_1 * V_3 = V_2 -> V_3 ;
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
ASSERT ( V_3 != NULL ) ;
F_35 ( & V_3 -> V_6 ) ;
V_3 -> V_5 ++ ;
V_3 -> V_7 ++ ;
V_2 -> V_61 = V_30 ;
F_5 ( & V_3 -> V_6 ) ;
F_14 ( L_19 ) ;
return V_22 ( V_62 ) ;
}
static const struct V_11 * F_41 ( struct V_1 * V_2 ,
int V_16 )
{
struct V_32 * V_33 = V_2 -> V_33 ;
struct V_1 * V_3 = V_2 -> V_3 ;
int V_63 ;
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
V_2 -> V_21 = V_64 ;
ASSERT ( V_3 != NULL ) ;
F_42 ( V_3 -> V_5 , > , 0 ) ;
F_42 ( V_3 -> V_7 , > , 0 ) ;
ASSERT ( F_34 ( V_3 ) ) ;
if ( F_33 ( V_3 ) ||
F_43 ( V_65 , & V_2 -> V_35 -> V_39 ) ||
! F_44 ( V_2 ) ) {
F_14 ( L_20 ) ;
return V_22 ( V_66 ) ;
}
F_7 ( L_21 ,
V_33 -> V_67 -> V_17 , V_2 -> V_35 -> V_68 -> V_17 ) ;
F_36 ( & V_69 ) ;
F_36 ( & V_70 ) ;
V_63 = V_2 -> V_35 -> V_57 -> V_71 ( V_2 ) ;
F_39 ( & V_70 ) ;
F_45 ( V_2 ) ;
if ( V_63 == - V_72 ) {
F_36 ( & V_73 ) ;
F_14 ( L_22 ) ;
return V_27 ;
}
if ( V_63 < 0 ) {
F_14 ( L_23 ) ;
return V_22 ( V_66 ) ;
}
F_14 ( L_24 ) ;
return V_22 ( V_74 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_33 ;
F_2 ( L_25 , V_2 -> V_4 , V_2 -> V_12 -> V_17 ) ;
if ( ! F_47 ( V_75 , & V_2 -> V_39 ) ) {
F_36 ( & V_76 ) ;
F_48 ( V_77 , & V_33 -> V_39 ) ;
F_10 ( V_78 , & V_33 -> V_39 ) ;
F_7 ( L_26 , & V_33 -> V_39 ) ;
F_49 ( V_79 , & V_33 -> V_39 ) ;
F_50 ( & V_33 -> V_39 , V_79 ) ;
}
F_14 ( L_19 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_33 ;
F_2 ( L_25 , V_2 -> V_4 , V_2 -> V_12 -> V_17 ) ;
if ( ! F_47 ( V_75 , & V_2 -> V_39 ) ) {
F_36 ( & V_80 ) ;
F_49 ( V_77 , & V_33 -> V_39 ) ;
F_10 ( V_78 , & V_33 -> V_39 ) ;
F_49 ( V_79 , & V_33 -> V_39 ) ;
F_50 ( & V_33 -> V_39 , V_79 ) ;
} else {
F_36 ( & V_81 ) ;
}
F_48 ( V_82 , & V_2 -> V_39 ) ;
F_14 ( L_19 ) ;
}
static const struct V_11 * F_52 ( struct V_1 * V_2 ,
int V_16 )
{
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
V_2 -> V_21 = V_83 ;
F_35 ( & V_2 -> V_6 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_47 == 0 ) {
if ( V_2 -> V_5 > 0 ) {
F_42 ( V_2 -> V_5 , >= , V_2 -> V_7 ) ;
F_53 ( V_2 ) ;
} else {
ASSERT ( F_32 ( & V_2 -> V_45 ) ) ;
}
}
F_5 ( & V_2 -> V_6 ) ;
F_36 ( & V_84 ) ;
V_2 -> V_35 -> V_57 -> V_85 ( V_2 ) ;
F_39 ( & V_84 ) ;
F_18 ( V_86 , V_2 -> V_61 ) ;
F_36 ( & V_87 ) ;
F_14 ( L_19 ) ;
return V_22 ( V_88 ) ;
}
static const struct V_11 * F_54 ( struct V_1 * V_2 ,
int V_16 )
{
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
if ( ! F_55 ( V_2 , V_89 ) )
return V_27 ;
return V_22 ( V_90 ) ;
}
static const struct V_11 * F_56 ( struct V_1 * V_2 ,
int V_16 )
{
struct V_32 * V_33 ;
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
V_2 -> V_20 = 0 ;
F_36 ( & V_84 ) ;
V_2 -> V_35 -> V_57 -> V_85 ( V_2 ) ;
F_39 ( & V_84 ) ;
V_33 = V_2 -> V_33 ;
F_48 ( V_78 , & V_33 -> V_39 ) ;
if ( F_57 ( V_79 , & V_33 -> V_39 ) )
F_50 ( & V_33 -> V_39 , V_79 ) ;
F_1 ( V_2 ) ;
return V_22 ( V_52 ) ;
}
static const struct V_11 * F_58 ( struct V_1 * V_2 ,
int V_16 )
{
F_2 ( L_27 ,
V_2 -> V_4 , V_2 -> V_5 , V_2 -> V_46 , V_16 ) ;
F_10 ( V_40 , & V_2 -> V_39 ) ;
V_2 -> V_20 = 0 ;
if ( F_32 ( & V_2 -> V_43 ) &&
V_2 -> V_5 == 0 &&
V_2 -> V_46 == 0 )
return V_22 ( V_54 ) ;
if ( V_2 -> V_47 == 0 ) {
F_35 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_5 > 0 && V_2 -> V_47 == 0 )
F_53 ( V_2 ) ;
F_5 ( & V_2 -> V_6 ) ;
}
if ( ! F_32 ( & V_2 -> V_43 ) )
return V_22 ( V_91 ) ;
return V_22 ( V_92 ) ;
}
static const struct V_11 * F_59 ( struct V_1 * V_2 ,
int V_16 )
{
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
if ( ! F_55 ( V_2 , V_93 ) )
return V_27 ;
return V_22 ( V_92 ) ;
}
static const struct V_11 * F_60 ( struct V_1 * V_2 ,
int V_16 )
{
struct V_1 * V_3 = V_2 -> V_3 ;
struct V_32 * V_33 = V_2 -> V_33 ;
struct V_34 * V_35 = V_2 -> V_35 ;
bool V_94 = false ;
F_2 ( L_28 , V_2 -> V_4 , V_2 -> V_46 , V_16 ) ;
ASSERT ( V_33 != NULL ) ;
ASSERT ( ! F_61 ( & V_2 -> V_42 ) ) ;
F_35 ( & V_33 -> V_6 ) ;
F_62 ( & V_2 -> V_42 ) ;
if ( F_63 ( & V_33 -> V_95 ) &&
F_57 ( V_96 , & V_33 -> V_39 ) )
V_94 = true ;
F_5 ( & V_33 -> V_6 ) ;
if ( V_94 )
F_50 ( & V_33 -> V_39 , V_96 ) ;
F_35 ( & V_2 -> V_6 ) ;
F_5 ( & V_2 -> V_6 ) ;
F_35 ( & V_35 -> V_97 ) ;
F_64 ( & V_2 -> V_41 ) ;
F_5 ( & V_35 -> V_97 ) ;
F_36 ( & V_98 ) ;
V_35 -> V_57 -> V_99 ( V_2 ) ;
F_39 ( & V_98 ) ;
if ( V_3 ) {
F_7 ( L_29 ,
V_3 -> V_4 , V_3 -> V_46 ) ;
F_35 ( & V_3 -> V_6 ) ;
V_3 -> V_46 -- ;
if ( V_3 -> V_46 == 0 )
F_4 ( V_3 , V_8 ) ;
F_5 ( & V_3 -> V_6 ) ;
V_2 -> V_3 = NULL ;
}
F_19 ( V_2 ) ;
F_36 ( & V_100 ) ;
F_14 ( L_19 ) ;
return V_22 ( V_101 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
int V_63 ;
F_36 ( & V_56 ) ;
V_63 = V_2 -> V_35 -> V_57 -> V_58 ( V_2 ) ? 0 : - V_102 ;
F_39 ( & V_56 ) ;
return V_63 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_36 ( & V_103 ) ;
V_2 -> V_35 -> V_57 -> V_104 ( V_2 ) ;
F_39 ( & V_103 ) ;
}
void F_66 ( struct V_1 * V_2 )
{
F_67 ( V_2 ) ;
F_68 ( V_2 -> V_33 ) ;
V_2 -> V_33 = NULL ;
}
void F_12 ( struct V_1 * V_2 )
{
F_2 ( L_10 , V_2 -> V_4 ) ;
if ( F_65 ( V_2 ) >= 0 ) {
T_1 * V_105 =
& F_69 ( V_106 ) ;
if ( F_70 ( V_107 , & V_2 -> V_23 ) ) {
if ( F_71 () )
F_72 ( V_105 ) ;
} else
F_19 ( V_2 ) ;
F_73 ( V_106 ) ;
}
}
bool F_74 ( signed long * V_108 )
{
T_1 * V_105 = F_75 ( & V_106 ) ;
F_76 ( V_109 ) ;
if ( F_71 () )
return true ;
F_77 ( V_105 , & V_109 ) ;
if ( ! F_71 () )
* V_108 = F_78 ( * V_108 ) ;
F_79 ( V_105 , & V_109 ) ;
return F_71 () ;
}
static bool F_55 ( struct V_1 * V_2 , int V_16 )
{
struct V_1 * V_110 ;
bool V_63 = true ;
F_2 ( L_10 , V_2 -> V_4 ) ;
if ( F_32 ( & V_2 -> V_43 ) )
return true ;
F_35 ( & V_2 -> V_6 ) ;
while ( ! F_32 ( & V_2 -> V_43 ) ) {
V_110 = F_80 ( V_2 -> V_43 . V_111 ,
struct V_1 , V_44 ) ;
F_64 ( & V_110 -> V_44 ) ;
F_4 ( V_110 , V_16 ) ;
F_19 ( V_110 ) ;
if ( ! F_32 ( & V_2 -> V_43 ) && F_81 () ) {
V_63 = false ;
break;
}
}
F_5 ( & V_2 -> V_6 ) ;
return V_63 ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_2 ( L_10 , V_2 -> V_4 ) ;
if ( ! F_32 ( & V_2 -> V_44 ) ) {
F_35 ( & V_2 -> V_3 -> V_6 ) ;
F_64 ( & V_2 -> V_44 ) ;
F_5 ( & V_2 -> V_3 -> V_6 ) ;
}
F_14 ( L_19 ) ;
}
enum V_112 F_82 ( struct V_1 * V_2 ,
const void * V_113 , T_2 V_114 )
{
enum V_112 V_115 ;
if ( ! V_2 -> V_33 -> V_67 -> V_116 ) {
F_36 ( & V_117 ) ;
return V_118 ;
}
V_115 = V_2 -> V_33 -> V_67 -> V_116 ( V_2 -> V_33 -> V_119 ,
V_113 , V_114 ) ;
switch ( V_115 ) {
case V_118 :
F_36 ( & V_120 ) ;
break;
case V_121 :
F_36 ( & V_122 ) ;
break;
case V_123 :
F_36 ( & V_124 ) ;
break;
default:
F_11 () ;
}
return V_115 ;
}
static const struct V_11 * F_83 ( struct V_1 * V_2 ,
int V_16 )
{
struct V_125 * V_126 ;
struct V_32 * V_33 = V_2 -> V_33 ;
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
if ( ! F_44 ( V_2 ) ) {
ASSERT ( V_2 -> V_33 -> V_127 . V_128 == NULL ) ;
F_48 ( V_129 , & V_2 -> V_39 ) ;
F_14 ( L_30 ) ;
return V_22 ( V_52 ) ;
}
F_84 ( V_33 ) ;
F_10 ( V_130 , & V_2 -> V_39 ) ;
F_85 ( V_2 ) ;
V_126 = F_86 ( sizeof( * V_126 ) , V_131 ) ;
if ( ! V_126 )
goto V_132;
F_87 ( V_126 , V_2 -> V_35 -> V_57 -> V_133 , NULL ) ;
V_126 -> V_39 = V_134 |
( 1 << V_135 ) |
( 1 << V_136 ) ;
F_35 ( & V_33 -> V_6 ) ;
if ( F_88 ( V_2 , V_126 ) < 0 )
goto V_137;
F_5 ( & V_33 -> V_6 ) ;
F_89 ( V_126 ) ;
F_48 ( V_77 , & V_33 -> V_39 ) ;
if ( F_57 ( V_96 , & V_33 -> V_39 ) )
F_50 ( & V_33 -> V_39 , V_96 ) ;
F_14 ( L_24 ) ;
return V_22 ( V_138 ) ;
V_132:
F_10 ( V_40 , & V_2 -> V_39 ) ;
F_45 ( V_2 ) ;
F_14 ( L_31 ) ;
return V_22 ( V_52 ) ;
V_137:
F_10 ( V_40 , & V_2 -> V_39 ) ;
F_5 ( & V_33 -> V_6 ) ;
F_45 ( V_2 ) ;
F_90 ( V_126 ) ;
F_14 ( L_32 ) ;
return V_22 ( V_52 ) ;
}
static const struct V_11 * F_91 ( struct V_1 * V_2 ,
int V_16 )
{
const struct V_11 * V_139 ;
F_36 ( & V_140 ) ;
F_36 ( & V_141 ) ;
V_139 = F_83 ( V_2 , V_16 ) ;
F_39 ( & V_141 ) ;
return V_139 ;
}
static const struct V_11 * F_92 ( struct V_1 * V_2 ,
int V_16 )
{
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
F_36 ( & V_142 ) ;
F_36 ( & V_143 ) ;
V_2 -> V_35 -> V_57 -> V_144 ( V_2 ) ;
F_39 ( & V_143 ) ;
F_14 ( L_19 ) ;
return V_22 ( V_90 ) ;
}

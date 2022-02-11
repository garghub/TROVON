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
if ( F_12 ( V_12 == F_13 ( V_28 ) ) ) {
F_14 ( L_7 ) ;
return;
}
F_15 ( V_2 ) ;
V_15 = V_2 -> V_20 ;
goto V_26;
}
F_7 ( L_8 ,
V_2 -> V_4 , V_12 -> V_17 , V_13 -> V_17 ) ;
V_2 -> V_12 = V_12 = V_13 ;
if ( V_12 -> V_23 ) {
if ( F_12 ( V_12 == F_13 ( V_28 ) ) ) {
F_14 ( L_7 ) ;
return;
}
goto V_19;
}
V_15 = V_2 -> V_20 ;
for ( V_10 = V_12 -> V_25 ; V_10 -> V_14 ; V_10 ++ )
V_15 |= V_10 -> V_14 ;
V_26:
V_2 -> V_15 = V_15 ;
F_16 () ;
V_14 = V_2 -> V_14 ;
if ( V_14 & V_15 )
goto V_18;
F_14 ( L_9 , V_15 ) ;
}
static void F_17 ( struct V_29 * V_23 )
{
struct V_1 * V_2 =
F_18 ( V_23 , struct V_1 , V_23 ) ;
unsigned long V_30 ;
F_2 ( L_10 , V_2 -> V_4 ) ;
V_30 = V_31 ;
F_6 ( V_2 ) ;
F_19 ( V_32 , V_30 ) ;
F_20 ( V_2 ) ;
}
void F_21 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
struct V_35 * V_36 )
{
const struct V_9 * V_10 ;
F_22 ( & V_36 -> V_37 ) ;
V_2 -> V_12 = F_13 ( V_38 ) ;
V_2 -> V_21 = V_39 ;
V_2 -> V_40 = 1 << V_41 ;
F_23 ( & V_2 -> V_6 ) ;
F_24 ( & V_2 -> V_42 ) ;
F_25 ( & V_2 -> V_43 ) ;
F_26 ( & V_2 -> V_23 , F_17 ) ;
F_24 ( & V_2 -> V_44 ) ;
F_24 ( & V_2 -> V_45 ) ;
F_24 ( & V_2 -> V_46 ) ;
V_2 -> V_47 = 0 ;
V_2 -> V_5 = V_2 -> V_48 = V_2 -> V_49 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_50 = 0 ;
V_2 -> V_51 = 0 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_3 = NULL ;
#ifdef F_27
F_28 ( & V_2 -> V_52 ) ;
#endif
V_2 -> V_20 = 0 ;
for ( V_10 = V_2 -> V_21 ; V_10 -> V_14 ; V_10 ++ )
V_2 -> V_20 |= V_10 -> V_14 ;
V_2 -> V_15 = V_2 -> V_20 ;
for ( V_10 = V_2 -> V_12 -> V_25 ; V_10 -> V_14 ; V_10 ++ )
V_2 -> V_15 |= V_10 -> V_14 ;
}
static inline void F_29 ( struct V_1 * V_2 )
{
F_30 ( & V_2 -> V_6 ) ;
F_10 ( V_41 , & V_2 -> V_40 ) ;
F_5 ( & V_2 -> V_6 ) ;
}
static const struct V_11 * F_31 ( struct V_1 * V_2 ,
int V_16 )
{
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
V_2 -> V_20 = 0 ;
F_32 ( V_2 ) ;
return V_22 ( V_53 ) ;
}
static const struct V_11 * F_33 ( struct V_1 * V_2 ,
int V_16 )
{
struct V_1 * V_3 ;
bool V_54 ;
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
ASSERT ( F_34 ( & V_2 -> V_45 ) ) ;
V_3 = V_2 -> V_3 ;
if ( ! V_3 ) {
F_14 ( L_12 ) ;
return V_22 ( V_55 ) ;
}
F_7 ( L_13 , V_3 -> V_12 -> V_17 , V_3 -> V_40 ) ;
if ( F_35 ( V_3 ) ) {
F_14 ( L_14 ) ;
return V_22 ( V_55 ) ;
}
if ( F_36 ( V_3 ) ) {
F_14 ( L_15 ) ;
return V_22 ( V_56 ) ;
}
F_7 ( L_16 ) ;
F_30 ( & V_3 -> V_6 ) ;
F_37 ( & V_57 ) ;
V_54 = false ;
if ( F_38 ( V_3 ) &&
V_2 -> V_36 -> V_58 -> V_59 ( V_2 ) ) {
F_39 ( & V_2 -> V_45 , & V_3 -> V_44 ) ;
V_54 = true ;
}
F_40 ( & V_57 ) ;
F_5 ( & V_3 -> V_6 ) ;
if ( ! V_54 ) {
F_14 ( L_17 ) ;
return V_22 ( V_55 ) ;
}
F_4 ( V_3 , V_60 ) ;
F_14 ( L_18 ) ;
return V_22 ( V_61 ) ;
}
static const struct V_11 * F_41 ( struct V_1 * V_2 ,
int V_16 )
{
struct V_1 * V_3 = V_2 -> V_3 ;
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
ASSERT ( V_3 != NULL ) ;
F_30 ( & V_3 -> V_6 ) ;
V_3 -> V_5 ++ ;
V_3 -> V_7 ++ ;
V_2 -> V_62 = V_31 ;
F_5 ( & V_3 -> V_6 ) ;
F_14 ( L_19 ) ;
return V_22 ( V_63 ) ;
}
static const struct V_11 * F_42 ( struct V_1 * V_2 ,
int V_16 )
{
struct V_33 * V_34 = V_2 -> V_34 ;
struct V_1 * V_3 = V_2 -> V_3 ;
int V_64 ;
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
V_2 -> V_21 = V_65 ;
ASSERT ( V_3 != NULL ) ;
F_43 ( V_3 -> V_5 , > , 0 ) ;
F_43 ( V_3 -> V_7 , > , 0 ) ;
ASSERT ( F_36 ( V_3 ) ) ;
if ( F_35 ( V_3 ) ||
F_44 ( V_66 , & V_2 -> V_36 -> V_40 ) ||
! F_45 ( V_2 ) ) {
F_14 ( L_20 ) ;
return V_22 ( V_67 ) ;
}
F_7 ( L_21 ,
V_34 -> V_68 -> V_17 , V_2 -> V_36 -> V_69 -> V_17 ) ;
F_37 ( & V_70 ) ;
F_37 ( & V_71 ) ;
V_64 = V_2 -> V_36 -> V_58 -> V_72 ( V_2 ) ;
F_40 ( & V_71 ) ;
F_46 ( V_2 ) ;
if ( V_64 == - V_73 ) {
F_37 ( & V_74 ) ;
F_14 ( L_22 ) ;
return V_27 ;
}
if ( V_64 < 0 ) {
F_14 ( L_23 ) ;
return V_22 ( V_67 ) ;
}
F_14 ( L_24 ) ;
return V_22 ( V_75 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_34 ;
F_2 ( L_25 , V_2 -> V_4 , V_2 -> V_12 -> V_17 ) ;
if ( ! F_48 ( V_76 , & V_2 -> V_40 ) ) {
F_37 ( & V_77 ) ;
F_49 ( V_78 , & V_34 -> V_40 ) ;
F_10 ( V_79 , & V_34 -> V_40 ) ;
F_7 ( L_26 , & V_34 -> V_40 ) ;
F_50 ( V_80 , & V_34 -> V_40 ) ;
F_51 ( & V_34 -> V_40 , V_80 ) ;
}
F_14 ( L_19 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_34 ;
F_2 ( L_25 , V_2 -> V_4 , V_2 -> V_12 -> V_17 ) ;
if ( ! F_48 ( V_76 , & V_2 -> V_40 ) ) {
F_37 ( & V_81 ) ;
F_50 ( V_78 , & V_34 -> V_40 ) ;
F_10 ( V_79 , & V_34 -> V_40 ) ;
F_50 ( V_80 , & V_34 -> V_40 ) ;
F_51 ( & V_34 -> V_40 , V_80 ) ;
} else {
F_37 ( & V_82 ) ;
}
F_49 ( V_83 , & V_2 -> V_40 ) ;
F_14 ( L_19 ) ;
}
static const struct V_11 * F_53 ( struct V_1 * V_2 ,
int V_16 )
{
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
V_2 -> V_21 = V_84 ;
F_30 ( & V_2 -> V_6 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_48 == 0 ) {
if ( V_2 -> V_5 > 0 ) {
F_43 ( V_2 -> V_5 , >= , V_2 -> V_7 ) ;
F_54 ( V_2 ) ;
} else {
ASSERT ( F_34 ( & V_2 -> V_46 ) ) ;
}
}
F_5 ( & V_2 -> V_6 ) ;
F_37 ( & V_85 ) ;
V_2 -> V_36 -> V_58 -> V_86 ( V_2 ) ;
F_40 ( & V_85 ) ;
F_19 ( V_87 , V_2 -> V_62 ) ;
F_37 ( & V_88 ) ;
F_14 ( L_19 ) ;
return V_22 ( V_89 ) ;
}
static const struct V_11 * F_55 ( struct V_1 * V_2 ,
int V_16 )
{
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
if ( ! F_56 ( V_2 , V_90 ) )
return V_27 ;
return V_22 ( V_91 ) ;
}
static const struct V_11 * F_57 ( struct V_1 * V_2 ,
int V_16 )
{
struct V_33 * V_34 ;
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
V_2 -> V_20 = 0 ;
F_37 ( & V_85 ) ;
V_2 -> V_36 -> V_58 -> V_86 ( V_2 ) ;
F_40 ( & V_85 ) ;
F_49 ( V_92 , & V_2 -> V_40 ) ;
V_34 = V_2 -> V_34 ;
F_49 ( V_79 , & V_34 -> V_40 ) ;
if ( F_58 ( V_80 , & V_34 -> V_40 ) )
F_51 ( & V_34 -> V_40 , V_80 ) ;
F_1 ( V_2 ) ;
return V_22 ( V_53 ) ;
}
static const struct V_11 * F_59 ( struct V_1 * V_2 ,
int V_16 )
{
F_2 ( L_27 ,
V_2 -> V_4 , V_2 -> V_5 , V_2 -> V_47 , V_16 ) ;
F_29 ( V_2 ) ;
V_2 -> V_20 = 0 ;
if ( F_44 ( V_93 , & V_2 -> V_40 ) ) {
F_10 ( V_94 , & V_2 -> V_40 ) ;
F_60 ( V_2 ) ;
}
if ( F_34 ( & V_2 -> V_44 ) &&
V_2 -> V_5 == 0 &&
V_2 -> V_47 == 0 )
return V_22 ( V_55 ) ;
if ( V_2 -> V_48 == 0 ) {
F_30 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_5 > 0 && V_2 -> V_48 == 0 )
F_54 ( V_2 ) ;
F_5 ( & V_2 -> V_6 ) ;
}
if ( ! F_34 ( & V_2 -> V_44 ) )
return V_22 ( V_95 ) ;
return V_22 ( V_96 ) ;
}
static const struct V_11 * F_61 ( struct V_1 * V_2 ,
int V_16 )
{
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
if ( ! F_56 ( V_2 , V_97 ) )
return V_27 ;
return V_22 ( V_96 ) ;
}
static const struct V_11 * F_62 ( struct V_1 * V_2 ,
int V_16 )
{
struct V_1 * V_3 = V_2 -> V_3 ;
struct V_33 * V_34 = V_2 -> V_34 ;
struct V_35 * V_36 = V_2 -> V_36 ;
bool V_98 = false ;
F_2 ( L_28 , V_2 -> V_4 , V_2 -> V_47 , V_16 ) ;
ASSERT ( V_34 != NULL ) ;
ASSERT ( ! F_63 ( & V_2 -> V_43 ) ) ;
F_30 ( & V_34 -> V_6 ) ;
F_64 ( & V_2 -> V_43 ) ;
if ( F_65 ( & V_34 -> V_99 ) &&
F_58 ( V_100 , & V_34 -> V_40 ) )
V_98 = true ;
F_5 ( & V_34 -> V_6 ) ;
if ( V_98 )
F_51 ( & V_34 -> V_40 , V_100 ) ;
F_30 ( & V_2 -> V_6 ) ;
F_5 ( & V_2 -> V_6 ) ;
F_30 ( & V_36 -> V_101 ) ;
F_66 ( & V_2 -> V_42 ) ;
F_5 ( & V_36 -> V_101 ) ;
F_37 ( & V_102 ) ;
V_36 -> V_58 -> V_103 ( V_2 ) ;
F_40 ( & V_102 ) ;
if ( V_3 ) {
F_7 ( L_29 ,
V_3 -> V_4 , V_3 -> V_47 ) ;
F_30 ( & V_3 -> V_6 ) ;
V_3 -> V_47 -- ;
if ( V_3 -> V_47 == 0 )
F_4 ( V_3 , V_8 ) ;
F_5 ( & V_3 -> V_6 ) ;
V_2 -> V_3 = NULL ;
}
F_20 ( V_2 ) ;
F_37 ( & V_104 ) ;
F_14 ( L_19 ) ;
return V_22 ( V_28 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_64 ;
F_37 ( & V_57 ) ;
V_64 = V_2 -> V_36 -> V_58 -> V_59 ( V_2 ) ? 0 : - V_105 ;
F_40 ( & V_57 ) ;
return V_64 ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_37 ( & V_106 ) ;
V_2 -> V_36 -> V_58 -> V_107 ( V_2 ) ;
F_40 ( & V_106 ) ;
}
void F_68 ( struct V_1 * V_2 )
{
F_69 ( V_2 ) ;
F_70 ( V_2 -> V_34 ) ;
V_2 -> V_34 = NULL ;
}
void F_15 ( struct V_1 * V_2 )
{
F_2 ( L_10 , V_2 -> V_4 ) ;
if ( F_67 ( V_2 ) >= 0 ) {
T_1 * V_108 =
& F_71 ( V_109 ) ;
if ( F_72 ( V_110 , & V_2 -> V_23 ) ) {
if ( F_73 () )
F_74 ( V_108 ) ;
} else
F_20 ( V_2 ) ;
F_75 ( V_109 ) ;
}
}
bool F_76 ( signed long * V_111 )
{
T_1 * V_108 = F_77 ( & V_109 ) ;
F_78 ( V_112 ) ;
if ( F_73 () )
return true ;
F_79 ( V_108 , & V_112 ) ;
if ( ! F_73 () )
* V_111 = F_80 ( * V_111 ) ;
F_81 ( V_108 , & V_112 ) ;
return F_73 () ;
}
static bool F_56 ( struct V_1 * V_2 , int V_16 )
{
struct V_1 * V_113 ;
bool V_64 = true ;
F_2 ( L_10 , V_2 -> V_4 ) ;
if ( F_34 ( & V_2 -> V_44 ) )
return true ;
F_30 ( & V_2 -> V_6 ) ;
while ( ! F_34 ( & V_2 -> V_44 ) ) {
V_113 = F_82 ( V_2 -> V_44 . V_114 ,
struct V_1 , V_45 ) ;
F_66 ( & V_113 -> V_45 ) ;
F_4 ( V_113 , V_16 ) ;
F_20 ( V_113 ) ;
if ( ! F_34 ( & V_2 -> V_44 ) && F_83 () ) {
V_64 = false ;
break;
}
}
F_5 ( & V_2 -> V_6 ) ;
return V_64 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_2 ( L_10 , V_2 -> V_4 ) ;
if ( ! F_34 ( & V_2 -> V_45 ) ) {
F_30 ( & V_2 -> V_3 -> V_6 ) ;
F_66 ( & V_2 -> V_45 ) ;
F_5 ( & V_2 -> V_3 -> V_6 ) ;
}
F_14 ( L_19 ) ;
}
enum V_115 F_84 ( struct V_1 * V_2 ,
const void * V_116 , T_2 V_117 )
{
enum V_115 V_118 ;
if ( ! V_2 -> V_34 -> V_68 -> V_119 ) {
F_37 ( & V_120 ) ;
return V_121 ;
}
V_118 = V_2 -> V_34 -> V_68 -> V_119 ( V_2 -> V_34 -> V_122 ,
V_116 , V_117 ) ;
switch ( V_118 ) {
case V_121 :
F_37 ( & V_123 ) ;
break;
case V_124 :
F_37 ( & V_125 ) ;
break;
case V_126 :
F_37 ( & V_127 ) ;
break;
default:
F_11 () ;
}
return V_118 ;
}
static const struct V_11 * F_85 ( struct V_1 * V_2 ,
int V_16 )
{
struct V_128 * V_129 ;
struct V_33 * V_34 = V_2 -> V_34 ;
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
if ( ! F_45 ( V_2 ) ) {
ASSERT ( V_2 -> V_34 -> V_130 . V_131 == NULL ) ;
F_49 ( V_93 , & V_2 -> V_40 ) ;
F_14 ( L_30 ) ;
return V_22 ( V_53 ) ;
}
F_86 ( V_34 ) ;
F_10 ( V_94 , & V_2 -> V_40 ) ;
F_60 ( V_2 ) ;
V_129 = F_87 ( sizeof( * V_129 ) , V_132 ) ;
if ( ! V_129 )
goto V_133;
F_88 ( V_129 , V_2 -> V_36 -> V_58 -> V_134 ,
NULL , NULL ) ;
V_129 -> V_40 = V_135 |
( 1 << V_136 ) |
( 1 << V_137 ) ;
F_30 ( & V_34 -> V_6 ) ;
if ( F_89 ( V_2 , V_129 ) < 0 )
goto V_138;
F_5 ( & V_34 -> V_6 ) ;
F_90 ( V_129 ) ;
F_49 ( V_78 , & V_34 -> V_40 ) ;
if ( F_58 ( V_100 , & V_34 -> V_40 ) )
F_51 ( & V_34 -> V_40 , V_100 ) ;
F_14 ( L_24 ) ;
return V_22 ( V_139 ) ;
V_133:
F_29 ( V_2 ) ;
F_46 ( V_2 ) ;
F_14 ( L_31 ) ;
return V_22 ( V_53 ) ;
V_138:
F_29 ( V_2 ) ;
F_5 ( & V_34 -> V_6 ) ;
F_46 ( V_2 ) ;
F_91 ( V_129 ) ;
F_14 ( L_32 ) ;
return V_22 ( V_53 ) ;
}
static const struct V_11 * F_92 ( struct V_1 * V_2 ,
int V_16 )
{
const struct V_11 * V_140 ;
F_37 ( & V_141 ) ;
F_37 ( & V_142 ) ;
V_140 = F_85 ( V_2 , V_16 ) ;
F_40 ( & V_142 ) ;
return V_140 ;
}
static const struct V_11 * F_93 ( struct V_1 * V_2 ,
int V_16 )
{
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
F_37 ( & V_143 ) ;
F_37 ( & V_144 ) ;
V_2 -> V_36 -> V_58 -> V_145 ( V_2 ) ;
F_40 ( & V_144 ) ;
F_14 ( L_19 ) ;
return V_22 ( V_91 ) ;
}
void F_94 ( struct V_1 * V_2 )
{
F_37 ( & V_146 ) ;
}
void F_95 ( struct V_1 * V_2 ,
enum V_147 V_148 )
{
if ( F_48 ( V_92 , & V_2 -> V_40 ) ) {
F_96 ( L_33 ,
V_2 -> V_36 -> V_149 ) ;
return;
}
switch ( V_148 ) {
case V_150 :
F_37 ( & V_146 ) ;
break;
case V_151 :
F_37 ( & V_152 ) ;
break;
case V_153 :
F_37 ( & V_154 ) ;
break;
case V_155 :
F_37 ( & V_156 ) ;
break;
}
}
static const struct V_11 * F_97 ( struct V_1 * V_2 ,
int V_16 )
{
if ( ! F_48 ( V_157 ,
& V_2 -> V_40 ) )
return V_27 ;
F_98 ( true , L_34 ) ;
return V_27 ;
}

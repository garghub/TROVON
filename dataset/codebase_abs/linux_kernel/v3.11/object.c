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
V_2 -> V_20 = 0 ;
for ( V_10 = V_2 -> V_21 ; V_10 -> V_14 ; V_10 ++ )
V_2 -> V_20 |= V_10 -> V_14 ;
V_2 -> V_15 = V_2 -> V_20 ;
for ( V_10 = V_2 -> V_12 -> V_25 ; V_10 -> V_14 ; V_10 ++ )
V_2 -> V_15 |= V_10 -> V_14 ;
}
static const struct V_11 * F_27 ( struct V_1 * V_2 ,
int V_16 )
{
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
V_2 -> V_20 = 0 ;
F_28 ( V_2 ) ;
return V_22 ( V_51 ) ;
}
static const struct V_11 * F_29 ( struct V_1 * V_2 ,
int V_16 )
{
struct V_1 * V_3 ;
bool V_52 ;
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
ASSERT ( F_30 ( & V_2 -> V_44 ) ) ;
V_3 = V_2 -> V_3 ;
if ( ! V_3 ) {
F_14 ( L_12 ) ;
return V_22 ( V_53 ) ;
}
F_7 ( L_13 , V_3 -> V_12 -> V_17 , V_3 -> V_39 ) ;
if ( F_31 ( V_3 ) ) {
F_14 ( L_14 ) ;
return V_22 ( V_53 ) ;
}
if ( F_32 ( V_3 ) ) {
F_14 ( L_15 ) ;
return V_22 ( V_54 ) ;
}
F_7 ( L_16 ) ;
F_33 ( & V_3 -> V_6 ) ;
F_34 ( & V_55 ) ;
V_52 = false ;
if ( F_35 ( V_3 ) &&
V_2 -> V_35 -> V_56 -> V_57 ( V_2 ) ) {
F_36 ( & V_2 -> V_44 , & V_3 -> V_43 ) ;
V_52 = true ;
}
F_37 ( & V_55 ) ;
F_5 ( & V_3 -> V_6 ) ;
if ( ! V_52 ) {
F_14 ( L_17 ) ;
return V_22 ( V_53 ) ;
}
F_4 ( V_3 , V_58 ) ;
F_14 ( L_18 ) ;
return V_22 ( V_59 ) ;
}
static const struct V_11 * F_38 ( struct V_1 * V_2 ,
int V_16 )
{
struct V_1 * V_3 = V_2 -> V_3 ;
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
ASSERT ( V_3 != NULL ) ;
F_33 ( & V_3 -> V_6 ) ;
V_3 -> V_5 ++ ;
V_3 -> V_7 ++ ;
V_2 -> V_60 = V_30 ;
F_5 ( & V_3 -> V_6 ) ;
F_14 ( L_19 ) ;
return V_22 ( V_61 ) ;
}
static const struct V_11 * F_39 ( struct V_1 * V_2 ,
int V_16 )
{
struct V_32 * V_33 = V_2 -> V_33 ;
struct V_1 * V_3 = V_2 -> V_3 ;
int V_62 ;
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
V_2 -> V_21 = V_63 ;
ASSERT ( V_3 != NULL ) ;
F_40 ( V_3 -> V_5 , > , 0 ) ;
F_40 ( V_3 -> V_7 , > , 0 ) ;
ASSERT ( F_32 ( V_3 ) ) ;
if ( F_31 ( V_3 ) ||
F_41 ( V_64 , & V_2 -> V_35 -> V_39 ) ||
! F_42 ( V_2 ) ) {
F_14 ( L_20 ) ;
return V_22 ( V_65 ) ;
}
F_7 ( L_21 ,
V_33 -> V_66 -> V_17 , V_2 -> V_35 -> V_67 -> V_17 ) ;
F_34 ( & V_68 ) ;
F_34 ( & V_69 ) ;
V_62 = V_2 -> V_35 -> V_56 -> V_70 ( V_2 ) ;
F_37 ( & V_69 ) ;
F_43 ( V_2 ) ;
if ( V_62 == - V_71 ) {
F_34 ( & V_72 ) ;
F_14 ( L_22 ) ;
return V_27 ;
}
if ( V_62 < 0 ) {
F_14 ( L_23 ) ;
return V_22 ( V_65 ) ;
}
F_14 ( L_24 ) ;
return V_22 ( V_73 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_33 ;
F_2 ( L_25 , V_2 -> V_4 , V_2 -> V_12 -> V_17 ) ;
if ( ! F_45 ( V_74 , & V_2 -> V_39 ) ) {
F_34 ( & V_75 ) ;
F_46 ( V_76 , & V_33 -> V_39 ) ;
F_7 ( L_26 , & V_33 -> V_39 ) ;
F_47 ( V_77 , & V_33 -> V_39 ) ;
F_48 ( & V_33 -> V_39 , V_77 ) ;
}
F_14 ( L_19 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_33 ;
F_2 ( L_25 , V_2 -> V_4 , V_2 -> V_12 -> V_17 ) ;
if ( ! F_45 ( V_74 , & V_2 -> V_39 ) ) {
F_34 ( & V_78 ) ;
F_47 ( V_76 , & V_33 -> V_39 ) ;
F_47 ( V_77 , & V_33 -> V_39 ) ;
F_48 ( & V_33 -> V_39 , V_77 ) ;
} else {
F_34 ( & V_79 ) ;
}
F_46 ( V_80 , & V_2 -> V_39 ) ;
F_14 ( L_19 ) ;
}
static const struct V_11 * F_50 ( struct V_1 * V_2 ,
int V_16 )
{
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
V_2 -> V_21 = V_81 ;
F_33 ( & V_2 -> V_6 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_47 == 0 ) {
if ( V_2 -> V_5 > 0 ) {
F_40 ( V_2 -> V_5 , >= , V_2 -> V_7 ) ;
F_51 ( V_2 ) ;
} else {
ASSERT ( F_30 ( & V_2 -> V_45 ) ) ;
}
}
F_5 ( & V_2 -> V_6 ) ;
F_34 ( & V_82 ) ;
V_2 -> V_35 -> V_56 -> V_83 ( V_2 ) ;
F_37 ( & V_82 ) ;
F_18 ( V_84 , V_2 -> V_60 ) ;
F_34 ( & V_85 ) ;
F_14 ( L_19 ) ;
return V_22 ( V_86 ) ;
}
static const struct V_11 * F_52 ( struct V_1 * V_2 ,
int V_16 )
{
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
if ( ! F_53 ( V_2 , V_87 ) )
return V_27 ;
return V_22 ( V_88 ) ;
}
static const struct V_11 * F_54 ( struct V_1 * V_2 ,
int V_16 )
{
struct V_32 * V_33 ;
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
V_2 -> V_20 = 0 ;
F_34 ( & V_82 ) ;
V_2 -> V_35 -> V_56 -> V_83 ( V_2 ) ;
F_37 ( & V_82 ) ;
V_33 = V_2 -> V_33 ;
F_46 ( V_89 , & V_33 -> V_39 ) ;
if ( F_55 ( V_77 , & V_33 -> V_39 ) )
F_48 ( & V_33 -> V_39 , V_77 ) ;
F_1 ( V_2 ) ;
return V_22 ( V_51 ) ;
}
static const struct V_11 * F_56 ( struct V_1 * V_2 ,
int V_16 )
{
F_2 ( L_27 ,
V_2 -> V_4 , V_2 -> V_5 , V_2 -> V_46 , V_16 ) ;
F_10 ( V_40 , & V_2 -> V_39 ) ;
V_2 -> V_20 = 0 ;
if ( F_30 ( & V_2 -> V_43 ) &&
V_2 -> V_5 == 0 &&
V_2 -> V_46 == 0 )
return V_22 ( V_53 ) ;
if ( V_2 -> V_47 == 0 ) {
F_33 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_5 > 0 && V_2 -> V_47 == 0 )
F_51 ( V_2 ) ;
F_5 ( & V_2 -> V_6 ) ;
}
if ( ! F_30 ( & V_2 -> V_43 ) )
return V_22 ( V_90 ) ;
return V_22 ( V_91 ) ;
}
static const struct V_11 * F_57 ( struct V_1 * V_2 ,
int V_16 )
{
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
if ( ! F_53 ( V_2 , V_92 ) )
return V_27 ;
return V_22 ( V_91 ) ;
}
static const struct V_11 * F_58 ( struct V_1 * V_2 ,
int V_16 )
{
struct V_1 * V_3 = V_2 -> V_3 ;
struct V_32 * V_33 = V_2 -> V_33 ;
struct V_34 * V_35 = V_2 -> V_35 ;
bool V_93 = false ;
F_2 ( L_28 , V_2 -> V_4 , V_2 -> V_46 , V_16 ) ;
ASSERT ( V_33 != NULL ) ;
ASSERT ( ! F_59 ( & V_2 -> V_42 ) ) ;
F_33 ( & V_33 -> V_6 ) ;
F_60 ( & V_2 -> V_42 ) ;
if ( F_55 ( V_94 , & V_33 -> V_39 ) )
V_93 = true ;
F_5 ( & V_33 -> V_6 ) ;
if ( V_93 )
F_48 ( & V_33 -> V_39 , V_94 ) ;
F_33 ( & V_2 -> V_6 ) ;
F_5 ( & V_2 -> V_6 ) ;
F_33 ( & V_35 -> V_95 ) ;
F_61 ( & V_2 -> V_41 ) ;
F_5 ( & V_35 -> V_95 ) ;
F_34 ( & V_96 ) ;
V_35 -> V_56 -> V_97 ( V_2 ) ;
F_37 ( & V_96 ) ;
if ( V_3 ) {
F_7 ( L_29 ,
V_3 -> V_4 , V_3 -> V_46 ) ;
F_33 ( & V_3 -> V_6 ) ;
V_3 -> V_46 -- ;
if ( V_3 -> V_46 == 0 )
F_4 ( V_3 , V_8 ) ;
F_5 ( & V_3 -> V_6 ) ;
V_2 -> V_3 = NULL ;
}
F_19 ( V_2 ) ;
F_34 ( & V_98 ) ;
F_14 ( L_19 ) ;
return V_22 ( V_99 ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
int V_62 ;
F_34 ( & V_55 ) ;
V_62 = V_2 -> V_35 -> V_56 -> V_57 ( V_2 ) ? 0 : - V_100 ;
F_37 ( & V_55 ) ;
return V_62 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_34 ( & V_101 ) ;
V_2 -> V_35 -> V_56 -> V_102 ( V_2 ) ;
F_37 ( & V_101 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
F_64 ( V_2 ) ;
F_65 ( V_2 -> V_33 ) ;
V_2 -> V_33 = NULL ;
}
void F_12 ( struct V_1 * V_2 )
{
F_2 ( L_10 , V_2 -> V_4 ) ;
if ( F_62 ( V_2 ) >= 0 ) {
T_1 * V_103 =
& F_66 ( V_104 ) ;
if ( F_67 ( V_105 , & V_2 -> V_23 ) ) {
if ( F_68 () )
F_69 ( V_103 ) ;
} else
F_19 ( V_2 ) ;
F_70 ( V_104 ) ;
}
}
bool F_71 ( signed long * V_106 )
{
T_1 * V_103 = & F_72 ( V_104 ) ;
F_73 ( V_107 ) ;
if ( F_68 () )
return true ;
F_74 ( V_103 , & V_107 ) ;
if ( ! F_68 () )
* V_106 = F_75 ( * V_106 ) ;
F_76 ( V_103 , & V_107 ) ;
return F_68 () ;
}
static bool F_53 ( struct V_1 * V_2 , int V_16 )
{
struct V_1 * V_108 ;
bool V_62 = true ;
F_2 ( L_10 , V_2 -> V_4 ) ;
if ( F_30 ( & V_2 -> V_43 ) )
return true ;
F_33 ( & V_2 -> V_6 ) ;
while ( ! F_30 ( & V_2 -> V_43 ) ) {
V_108 = F_77 ( V_2 -> V_43 . V_109 ,
struct V_1 , V_44 ) ;
F_61 ( & V_108 -> V_44 ) ;
F_4 ( V_108 , V_16 ) ;
F_19 ( V_108 ) ;
if ( ! F_30 ( & V_2 -> V_43 ) && F_78 () ) {
V_62 = false ;
break;
}
}
F_5 ( & V_2 -> V_6 ) ;
return V_62 ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_2 ( L_10 , V_2 -> V_4 ) ;
if ( ! F_30 ( & V_2 -> V_44 ) ) {
F_33 ( & V_2 -> V_3 -> V_6 ) ;
F_61 ( & V_2 -> V_44 ) ;
F_5 ( & V_2 -> V_3 -> V_6 ) ;
}
F_14 ( L_19 ) ;
}
enum V_110 F_79 ( struct V_1 * V_2 ,
const void * V_111 , T_2 V_112 )
{
enum V_110 V_113 ;
if ( ! V_2 -> V_33 -> V_66 -> V_114 ) {
F_34 ( & V_115 ) ;
return V_116 ;
}
V_113 = V_2 -> V_33 -> V_66 -> V_114 ( V_2 -> V_33 -> V_117 ,
V_111 , V_112 ) ;
switch ( V_113 ) {
case V_116 :
F_34 ( & V_118 ) ;
break;
case V_119 :
F_34 ( & V_120 ) ;
break;
case V_121 :
F_34 ( & V_122 ) ;
break;
default:
F_11 () ;
}
return V_113 ;
}
static const struct V_11 * F_80 ( struct V_1 * V_2 ,
int V_16 )
{
struct V_123 * V_124 ;
struct V_32 * V_33 = V_2 -> V_33 ;
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
if ( ! F_42 ( V_2 ) ) {
ASSERT ( V_2 -> V_33 -> V_125 . V_126 == NULL ) ;
F_46 ( V_127 , & V_33 -> V_39 ) ;
F_14 ( L_30 ) ;
return V_22 ( V_51 ) ;
}
F_81 ( V_33 ) ;
F_10 ( V_128 , & V_2 -> V_39 ) ;
F_82 ( V_2 ) ;
V_124 = F_83 ( sizeof( * V_124 ) , V_129 ) ;
if ( ! V_124 )
goto V_130;
F_84 ( V_124 , V_2 -> V_35 -> V_56 -> V_131 , NULL ) ;
V_124 -> V_39 = V_132 |
( 1 << V_133 ) |
( 1 << V_134 ) ;
F_33 ( & V_33 -> V_6 ) ;
if ( F_85 ( V_2 , V_124 ) < 0 )
goto V_135;
F_5 ( & V_33 -> V_6 ) ;
F_86 ( V_124 ) ;
F_46 ( V_76 , & V_33 -> V_39 ) ;
if ( F_55 ( V_94 , & V_33 -> V_39 ) )
F_48 ( & V_33 -> V_39 , V_94 ) ;
F_14 ( L_24 ) ;
return V_22 ( V_136 ) ;
V_130:
F_10 ( V_40 , & V_2 -> V_39 ) ;
F_43 ( V_2 ) ;
F_14 ( L_31 ) ;
return V_22 ( V_51 ) ;
V_135:
F_10 ( V_40 , & V_2 -> V_39 ) ;
F_5 ( & V_33 -> V_6 ) ;
F_87 ( V_124 ) ;
F_14 ( L_32 ) ;
return V_22 ( V_51 ) ;
}
static const struct V_11 * F_88 ( struct V_1 * V_2 ,
int V_16 )
{
const struct V_11 * V_137 ;
F_34 ( & V_138 ) ;
F_34 ( & V_139 ) ;
V_137 = F_80 ( V_2 , V_16 ) ;
F_37 ( & V_139 ) ;
return V_137 ;
}
static const struct V_11 * F_89 ( struct V_1 * V_2 ,
int V_16 )
{
F_2 ( L_11 , V_2 -> V_4 , V_16 ) ;
F_34 ( & V_140 ) ;
F_34 ( & V_141 ) ;
V_2 -> V_35 -> V_56 -> V_142 ( V_2 ) ;
F_37 ( & V_141 ) ;
F_14 ( L_19 ) ;
return V_22 ( V_88 ) ;
}

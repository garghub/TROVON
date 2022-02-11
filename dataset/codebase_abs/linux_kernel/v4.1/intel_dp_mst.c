static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
struct V_13 * V_14 ;
int V_15 , V_16 ;
int V_17 , V_18 , V_19 ;
struct V_20 * V_21 = & V_4 -> V_7 . V_21 ;
struct V_22 * V_23 = NULL ;
int V_24 ;
V_4 -> V_25 = true ;
V_4 -> V_26 = false ;
V_4 -> V_27 = true ;
V_15 = 24 ;
V_17 = F_3 ( V_11 -> V_28 ) ;
V_19 = F_4 ( V_11 ) ;
if ( V_11 -> V_29 ) {
V_11 -> V_30 = 0 ;
V_11 -> V_31 = F_5 ( V_11 , V_19 ) ;
} else {
V_11 -> V_30 = F_6 ( V_19 ) ;
V_11 -> V_31 = 0 ;
}
V_11 -> V_17 = V_17 ;
V_4 -> V_32 = 24 ;
V_4 -> V_33 = V_19 ;
V_14 = V_4 -> V_7 . V_14 ;
for ( V_16 = 0 ; V_16 < V_14 -> V_34 ; V_16 ++ ) {
if ( ! V_14 -> V_35 [ V_16 ] )
continue;
if ( V_14 -> V_36 [ V_16 ] -> V_37 == & V_2 -> V_7 ) {
V_23 = F_7 ( V_14 -> V_35 [ V_16 ] ) ;
break;
}
}
if ( ! V_23 ) {
F_8 ( L_1 ) ;
return false ;
}
V_24 = F_9 ( V_21 -> clock , V_15 ) ;
V_4 -> V_38 = V_24 ;
V_18 = F_10 ( & V_11 -> V_39 , V_24 ) ;
F_11 ( V_15 , V_17 ,
V_21 -> V_40 ,
V_4 -> V_33 ,
& V_4 -> V_41 ) ;
V_4 -> V_41 . V_42 = V_18 ;
return true ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
int V_43 ;
F_13 ( L_2 , V_11 -> V_44 ) ;
F_14 ( & V_11 -> V_39 , V_6 -> V_45 ) ;
V_43 = F_15 ( & V_11 -> V_39 ) ;
if ( V_43 ) {
F_8 ( L_3 , V_43 ) ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
F_13 ( L_2 , V_11 -> V_44 ) ;
F_17 ( & V_11 -> V_39 ) ;
F_18 ( & V_11 -> V_39 ) ;
F_19 ( & V_11 -> V_39 , V_6 -> V_45 ) ;
V_11 -> V_44 -- ;
V_6 -> V_45 = NULL ;
if ( V_11 -> V_44 == 0 ) {
V_9 -> V_7 . V_46 ( & V_9 -> V_7 ) ;
F_20 ( V_11 , V_47 ) ;
}
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
struct V_48 * V_49 = V_2 -> V_7 . V_49 ;
struct V_50 * V_51 = V_49 -> V_52 ;
enum V_45 V_45 = V_9 -> V_45 ;
int V_43 ;
T_1 V_53 ;
struct V_22 * V_23 = NULL , * V_22 ;
int V_18 ;
struct V_54 * V_55 = V_2 -> V_7 . V_55 ;
struct V_56 * V_56 = F_22 ( V_55 ) ;
F_23 (dev, intel_connector) {
if ( V_22 -> V_57 == V_2 ) {
V_23 = V_22 ;
break;
}
}
if ( ! V_23 ) {
F_8 ( L_1 ) ;
return;
}
F_13 ( L_2 , V_11 -> V_44 ) ;
V_6 -> V_45 = V_23 -> V_45 ;
if ( V_11 -> V_44 == 0 ) {
enum V_45 V_45 = F_24 ( V_2 ) ;
F_25 ( F_26 ( V_45 ) ,
V_56 -> V_58 -> V_59 ) ;
F_27 ( & V_9 -> V_7 ) ;
F_20 ( V_11 , V_60 ) ;
F_28 ( V_11 ) ;
F_29 ( V_11 ) ;
F_30 ( V_11 ) ;
}
V_43 = F_31 ( & V_11 -> V_39 ,
V_6 -> V_45 ,
V_56 -> V_58 -> V_38 , & V_18 ) ;
if ( V_43 == false ) {
F_8 ( L_4 ) ;
return;
}
V_11 -> V_44 ++ ;
V_53 = F_32 ( F_33 ( V_45 ) ) ;
F_25 ( F_33 ( V_45 ) , V_53 ) ;
V_43 = F_15 ( & V_11 -> V_39 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
struct V_48 * V_49 = V_9 -> V_7 . V_7 . V_49 ;
struct V_50 * V_51 = V_49 -> V_52 ;
enum V_45 V_45 = V_9 -> V_45 ;
int V_43 ;
F_13 ( L_2 , V_11 -> V_44 ) ;
if ( F_35 ( ( F_32 ( F_33 ( V_45 ) ) & V_61 ) ,
1 ) )
F_8 ( L_5 ) ;
V_43 = F_17 ( & V_11 -> V_39 ) ;
V_43 = F_18 ( & V_11 -> V_39 ) ;
}
static bool F_36 ( struct V_1 * V_2 ,
enum V_62 * V_62 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
* V_62 = V_6 -> V_62 ;
if ( V_6 -> V_45 )
return true ;
return false ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_56 * V_55 = F_22 ( V_2 -> V_7 . V_55 ) ;
struct V_48 * V_49 = V_2 -> V_7 . V_49 ;
struct V_50 * V_51 = V_49 -> V_52 ;
enum V_63 V_64 = V_4 -> V_64 ;
T_2 V_53 , V_65 = 0 ;
V_4 -> V_27 = true ;
V_53 = F_32 ( F_38 ( V_64 ) ) ;
if ( V_53 & V_66 )
V_65 |= V_67 ;
else
V_65 |= V_68 ;
if ( V_53 & V_69 )
V_65 |= V_70 ;
else
V_65 |= V_71 ;
switch ( V_53 & V_72 ) {
case V_73 :
V_4 -> V_32 = 18 ;
break;
case V_74 :
V_4 -> V_32 = 24 ;
break;
case V_75 :
V_4 -> V_32 = 30 ;
break;
case V_76 :
V_4 -> V_32 = 36 ;
break;
default:
break;
}
V_4 -> V_7 . V_21 . V_65 |= V_65 ;
F_39 ( V_55 , V_4 ) ;
F_40 ( & V_9 -> V_7 , V_4 ) ;
}
static int F_41 ( struct V_77 * V_78 )
{
struct V_22 * V_22 = F_7 ( V_78 ) ;
struct V_11 * V_11 = V_22 -> V_79 ;
struct V_80 * V_80 ;
int V_43 ;
V_80 = F_42 ( V_78 , & V_11 -> V_39 , V_22 -> V_45 ) ;
if ( ! V_80 )
return 0 ;
V_43 = F_43 ( V_78 , V_80 ) ;
F_44 ( V_80 ) ;
return V_43 ;
}
static enum V_81
F_45 ( struct V_77 * V_78 , bool V_82 )
{
struct V_22 * V_22 = F_7 ( V_78 ) ;
struct V_11 * V_11 = V_22 -> V_79 ;
return F_46 ( V_78 , & V_11 -> V_39 , V_22 -> V_45 ) ;
}
static int
F_47 ( struct V_77 * V_78 ,
struct V_83 * V_84 ,
T_3 V_85 )
{
return 0 ;
}
static void
F_48 ( struct V_77 * V_78 )
{
struct V_22 * V_22 = F_7 ( V_78 ) ;
if ( ! F_49 ( V_22 -> V_80 ) )
F_44 ( V_22 -> V_80 ) ;
F_50 ( V_78 ) ;
F_44 ( V_78 ) ;
}
static int F_51 ( struct V_77 * V_78 )
{
return F_41 ( V_78 ) ;
}
static enum V_86
F_52 ( struct V_77 * V_78 ,
struct V_20 * V_87 )
{
if ( V_87 -> clock < 10000 )
return V_88 ;
if ( V_87 -> V_65 & V_89 )
return V_90 ;
return V_91 ;
}
static struct V_92 * F_53 ( struct V_77 * V_78 )
{
struct V_22 * V_22 = F_7 ( V_78 ) ;
struct V_11 * V_11 = V_22 -> V_79 ;
return & V_11 -> V_93 [ 0 ] -> V_7 . V_7 ;
}
static void F_54 ( struct V_92 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_55 ( V_2 ) ;
F_44 ( V_6 ) ;
}
static bool F_56 ( struct V_22 * V_78 )
{
if ( V_78 -> V_2 ) {
enum V_62 V_62 ;
if ( ! V_78 -> V_2 -> V_94 ( V_78 -> V_2 , & V_62 ) )
return false ;
return true ;
}
return false ;
}
static void F_57 ( struct V_22 * V_78 )
{
#ifdef F_58
struct V_50 * V_51 = F_59 ( V_78 -> V_7 . V_49 ) ;
F_60 ( & V_51 -> V_95 -> V_96 , & V_78 -> V_7 ) ;
#endif
}
static void F_61 ( struct V_22 * V_78 )
{
#ifdef F_58
struct V_50 * V_51 = F_59 ( V_78 -> V_7 . V_49 ) ;
F_62 ( & V_51 -> V_95 -> V_96 , & V_78 -> V_7 ) ;
#endif
}
static struct V_77 * F_63 ( struct V_97 * V_98 , struct V_99 * V_45 , const char * V_100 )
{
struct V_11 * V_11 = F_64 ( V_98 , struct V_11 , V_39 ) ;
struct V_8 * V_9 = F_65 ( V_11 ) ;
struct V_48 * V_49 = V_9 -> V_7 . V_7 . V_49 ;
struct V_22 * V_22 ;
struct V_77 * V_78 ;
int V_16 ;
V_22 = F_66 () ;
if ( ! V_22 )
return NULL ;
V_78 = & V_22 -> V_7 ;
F_67 ( V_49 , V_78 , & V_101 , V_102 ) ;
F_68 ( V_78 , & V_103 ) ;
V_22 -> V_104 = V_105 ;
V_22 -> V_94 = F_56 ;
V_22 -> V_79 = V_11 ;
V_22 -> V_45 = V_45 ;
for ( V_16 = V_106 ; V_16 <= V_107 ; V_16 ++ ) {
F_69 ( & V_22 -> V_7 ,
& V_11 -> V_93 [ V_16 ] -> V_7 . V_7 ) ;
}
F_70 ( V_11 , V_78 ) ;
F_71 ( & V_78 -> V_7 , V_49 -> V_108 . V_109 , 0 ) ;
F_71 ( & V_78 -> V_7 , V_49 -> V_108 . V_110 , 0 ) ;
F_72 ( V_78 , V_100 ) ;
F_73 ( V_49 ) ;
F_74 ( & V_49 -> V_108 . V_111 ) ;
F_57 ( V_22 ) ;
F_75 ( & V_49 -> V_108 . V_111 ) ;
F_76 ( & V_22 -> V_7 ) ;
return V_78 ;
}
static void F_77 ( struct V_97 * V_98 ,
struct V_77 * V_78 )
{
struct V_22 * V_22 = F_7 ( V_78 ) ;
struct V_48 * V_49 = V_78 -> V_49 ;
F_74 ( & V_49 -> V_108 . V_111 ) ;
F_78 ( V_78 , V_47 ) ;
F_75 ( & V_49 -> V_108 . V_111 ) ;
V_22 -> V_104 ( V_22 ) ;
F_74 ( & V_49 -> V_108 . V_111 ) ;
F_61 ( V_22 ) ;
F_50 ( V_78 ) ;
F_75 ( & V_49 -> V_108 . V_111 ) ;
F_73 ( V_49 ) ;
F_44 ( V_22 ) ;
F_13 ( L_6 ) ;
}
static void F_79 ( struct V_97 * V_98 )
{
struct V_11 * V_11 = F_64 ( V_98 , struct V_11 , V_39 ) ;
struct V_8 * V_9 = F_65 ( V_11 ) ;
struct V_48 * V_49 = V_9 -> V_7 . V_7 . V_49 ;
F_80 ( V_49 ) ;
}
static struct V_5 *
F_81 ( struct V_8 * V_9 , enum V_62 V_62 )
{
struct V_5 * V_6 ;
struct V_1 * V_1 ;
struct V_48 * V_49 = V_9 -> V_7 . V_7 . V_49 ;
V_6 = F_82 ( sizeof( * V_6 ) , V_112 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_62 = V_62 ;
V_1 = & V_6 -> V_7 ;
V_6 -> V_10 = V_9 ;
F_83 ( V_49 , & V_1 -> V_7 , & V_113 ,
V_114 ) ;
V_1 -> type = V_115 ;
V_1 -> V_116 = 0x7 ;
V_1 -> V_117 = 0 ;
V_1 -> V_118 = F_1 ;
V_1 -> V_119 = F_12 ;
V_1 -> V_46 = F_16 ;
V_1 -> V_120 = F_21 ;
V_1 -> V_121 = F_34 ;
V_1 -> V_94 = F_36 ;
V_1 -> V_122 = F_37 ;
return V_6 ;
}
static bool
F_84 ( struct V_8 * V_9 )
{
int V_16 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
for ( V_16 = V_106 ; V_16 <= V_107 ; V_16 ++ )
V_11 -> V_93 [ V_16 ] = F_81 ( V_9 , V_16 ) ;
return true ;
}
int
F_85 ( struct V_8 * V_9 , int V_123 )
{
struct V_11 * V_11 = & V_9 -> V_12 ;
struct V_48 * V_49 = V_9 -> V_7 . V_7 . V_49 ;
int V_43 ;
V_11 -> V_124 = true ;
V_11 -> V_39 . V_125 = & V_126 ;
F_84 ( V_9 ) ;
V_43 = F_86 ( & V_11 -> V_39 , V_49 -> V_49 , & V_11 -> V_127 , 16 , 3 , V_123 ) ;
if ( V_43 ) {
V_11 -> V_124 = false ;
return V_43 ;
}
return 0 ;
}
void
F_87 ( struct V_8 * V_9 )
{
struct V_11 * V_11 = & V_9 -> V_12 ;
if ( ! V_11 -> V_124 )
return;
F_88 ( & V_11 -> V_39 ) ;
}

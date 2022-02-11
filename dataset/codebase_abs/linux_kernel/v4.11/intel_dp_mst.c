static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_15 * V_16 =
F_3 ( V_6 -> V_16 ) ;
struct V_17 * V_18 ;
int V_19 ;
int V_20 , V_21 ;
const struct V_22 * V_23 = & V_4 -> V_9 . V_23 ;
int V_24 ;
V_4 -> V_25 = false ;
V_19 = 24 ;
V_20 = F_4 ( V_13 -> V_26 ) ;
V_4 -> V_20 = V_20 ;
V_4 -> V_27 = 24 ;
V_4 -> V_28 = F_5 ( V_13 ) ;
V_18 = V_4 -> V_9 . V_18 ;
if ( F_6 ( & V_13 -> V_29 , V_16 -> V_30 ) )
V_4 -> V_31 = true ;
V_24 = F_7 ( V_23 -> V_32 , V_19 ) ;
V_4 -> V_33 = V_24 ;
V_21 = F_8 ( & V_13 -> V_29 , V_24 ) ;
F_9 ( V_19 , V_20 ,
V_23 -> V_32 ,
V_4 -> V_28 ,
& V_4 -> V_34 ) ;
V_4 -> V_34 . V_35 = V_21 ;
return true ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_36 ,
struct V_5 * V_37 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_15 * V_16 =
F_3 ( V_37 -> V_16 ) ;
struct V_38 * V_39 = F_11 ( V_2 -> V_9 . V_40 ) ;
int V_41 ;
F_12 ( L_1 , V_13 -> V_42 ) ;
F_13 ( & V_13 -> V_29 , V_16 -> V_30 ) ;
V_41 = F_14 ( & V_13 -> V_29 ) ;
if ( V_41 ) {
F_15 ( L_2 , V_41 ) ;
}
if ( V_36 -> V_31 ) {
F_16 ( V_2 ) ;
F_17 ( V_39 , V_43 ) ;
}
}
static void F_18 ( struct V_1 * V_2 ,
struct V_3 * V_36 ,
struct V_5 * V_37 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_15 * V_16 =
F_3 ( V_37 -> V_16 ) ;
F_12 ( L_1 , V_13 -> V_42 ) ;
F_19 ( & V_13 -> V_29 ) ;
F_20 ( & V_13 -> V_29 ) ;
F_21 ( & V_13 -> V_29 , V_16 -> V_30 ) ;
V_13 -> V_42 -- ;
V_8 -> V_16 = NULL ;
if ( V_13 -> V_42 == 0 ) {
V_11 -> V_9 . V_44 ( & V_11 -> V_9 ,
NULL , NULL ) ;
F_22 ( V_13 , V_45 ) ;
}
}
static void F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_9 . V_40 ) ;
enum V_30 V_30 = V_11 -> V_30 ;
struct V_15 * V_16 =
F_3 ( V_6 -> V_16 ) ;
int V_41 ;
T_1 V_46 ;
int V_21 ;
V_16 -> V_2 = V_2 ;
V_8 -> V_16 = V_16 ;
F_12 ( L_1 , V_13 -> V_42 ) ;
if ( V_13 -> V_42 == 0 ) {
F_24 ( & V_11 -> V_9 ,
V_4 -> V_47 ) ;
F_25 ( & V_11 -> V_9 ) ;
F_26 ( V_13 ,
V_4 -> V_28 ,
V_4 -> V_20 ,
true ) ;
F_27 ( & V_11 -> V_9 ) ;
F_22 ( V_13 , V_48 ) ;
F_28 ( V_13 ) ;
F_29 ( V_13 ) ;
}
V_41 = F_30 ( & V_13 -> V_29 ,
V_16 -> V_30 ,
V_4 -> V_33 , & V_21 ) ;
if ( V_41 == false ) {
F_15 ( L_3 ) ;
return;
}
V_13 -> V_42 ++ ;
V_46 = F_31 ( F_32 ( V_30 ) ) ;
F_33 ( F_32 ( V_30 ) , V_46 ) ;
V_41 = F_14 ( & V_13 -> V_29 ) ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_38 * V_39 = F_11 ( V_2 -> V_9 . V_40 ) ;
enum V_30 V_30 = V_11 -> V_30 ;
int V_41 ;
F_12 ( L_1 , V_13 -> V_42 ) ;
if ( F_35 ( V_39 ,
F_32 ( V_30 ) ,
V_49 ,
V_49 ,
1 ) )
F_15 ( L_4 ) ;
V_41 = F_19 ( & V_13 -> V_29 ) ;
V_41 = F_20 ( & V_13 -> V_29 ) ;
if ( V_4 -> V_31 ) {
F_36 ( V_39 , V_43 ) ;
F_37 ( V_2 , V_4 , V_6 ) ;
}
}
static bool F_38 ( struct V_1 * V_2 ,
enum V_50 * V_50 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
* V_50 = V_8 -> V_50 ;
if ( V_8 -> V_16 )
return true ;
return false ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_51 * V_52 = F_40 ( V_4 -> V_9 . V_52 ) ;
struct V_38 * V_39 = F_11 ( V_2 -> V_9 . V_40 ) ;
enum V_53 V_54 = V_4 -> V_54 ;
T_2 V_46 , V_55 = 0 ;
V_4 -> V_31 =
F_41 ( V_39 , V_52 ) ;
V_46 = F_31 ( F_42 ( V_54 ) ) ;
if ( V_46 & V_56 )
V_55 |= V_57 ;
else
V_55 |= V_58 ;
if ( V_46 & V_59 )
V_55 |= V_60 ;
else
V_55 |= V_61 ;
switch ( V_46 & V_62 ) {
case V_63 :
V_4 -> V_27 = 18 ;
break;
case V_64 :
V_4 -> V_27 = 24 ;
break;
case V_65 :
V_4 -> V_27 = 30 ;
break;
case V_66 :
V_4 -> V_27 = 36 ;
break;
default:
break;
}
V_4 -> V_9 . V_23 . V_55 |= V_55 ;
V_4 -> V_20 =
( ( V_46 & V_67 ) >> V_68 ) + 1 ;
F_43 ( V_52 , V_4 ) ;
F_44 ( & V_11 -> V_9 , V_4 ) ;
}
static int F_45 ( struct V_69 * V_16 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
struct V_13 * V_13 = V_15 -> V_70 ;
struct V_71 * V_71 ;
int V_41 ;
if ( ! V_13 ) {
return F_46 ( V_16 , NULL ) ;
}
V_71 = F_47 ( V_16 , & V_13 -> V_29 , V_15 -> V_30 ) ;
V_41 = F_46 ( V_16 , V_71 ) ;
F_48 ( V_71 ) ;
return V_41 ;
}
static enum V_72
F_49 ( struct V_69 * V_16 , bool V_73 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
struct V_13 * V_13 = V_15 -> V_70 ;
if ( ! V_13 )
return V_74 ;
return F_50 ( V_16 , & V_13 -> V_29 , V_15 -> V_30 ) ;
}
static int
F_51 ( struct V_69 * V_16 ,
struct V_75 * V_76 ,
T_3 V_77 )
{
return 0 ;
}
static void
F_52 ( struct V_69 * V_16 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
if ( ! F_53 ( V_15 -> V_71 ) )
F_48 ( V_15 -> V_71 ) ;
F_54 ( V_16 ) ;
F_48 ( V_16 ) ;
}
static int F_55 ( struct V_69 * V_16 )
{
return F_45 ( V_16 ) ;
}
static enum V_78
F_56 ( struct V_69 * V_16 ,
struct V_22 * V_79 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
struct V_13 * V_13 = V_15 -> V_70 ;
int V_80 = F_11 ( V_16 -> V_40 ) -> V_81 ;
int V_19 = 24 ;
int V_82 , V_83 , V_84 , V_85 ;
V_85 = F_5 ( V_13 ) ;
V_84 = F_4 ( V_13 -> V_26 ) ;
V_82 = F_57 ( V_85 , V_84 ) ;
V_83 = F_58 ( V_79 -> clock , V_19 ) ;
if ( V_79 -> clock < 10000 )
return V_86 ;
if ( V_79 -> V_55 & V_87 )
return V_88 ;
if ( V_83 > V_82 || V_79 -> clock > V_80 )
return V_89 ;
return V_90 ;
}
static struct V_91 * F_59 ( struct V_69 * V_16 ,
struct V_5 * V_18 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
struct V_13 * V_13 = V_15 -> V_70 ;
struct V_51 * V_52 = F_40 ( V_18 -> V_52 ) ;
if ( ! V_13 )
return NULL ;
return & V_13 -> V_92 [ V_52 -> V_50 ] -> V_9 . V_9 ;
}
static struct V_91 * F_60 ( struct V_69 * V_16 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
struct V_13 * V_13 = V_15 -> V_70 ;
if ( ! V_13 )
return NULL ;
return & V_13 -> V_92 [ 0 ] -> V_9 . V_9 ;
}
static void F_61 ( struct V_91 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_62 ( V_2 ) ;
F_48 ( V_8 ) ;
}
static bool F_63 ( struct V_15 * V_16 )
{
if ( V_16 -> V_2 && V_16 -> V_9 . V_18 -> V_52 ) {
enum V_50 V_50 ;
if ( ! V_16 -> V_2 -> V_93 ( V_16 -> V_2 , & V_50 ) )
return false ;
return true ;
}
return false ;
}
static void F_64 ( struct V_15 * V_16 )
{
#ifdef F_65
struct V_38 * V_39 = F_11 ( V_16 -> V_9 . V_40 ) ;
if ( V_39 -> V_94 )
F_66 ( & V_39 -> V_94 -> V_95 ,
& V_16 -> V_9 ) ;
#endif
}
static void F_67 ( struct V_15 * V_16 )
{
#ifdef F_65
struct V_38 * V_39 = F_11 ( V_16 -> V_9 . V_40 ) ;
if ( V_39 -> V_94 )
F_68 ( & V_39 -> V_94 -> V_95 ,
& V_16 -> V_9 ) ;
#endif
}
static struct V_69 * F_69 ( struct V_96 * V_97 , struct V_98 * V_30 , const char * V_99 )
{
struct V_13 * V_13 = F_70 ( V_97 , struct V_13 , V_29 ) ;
struct V_10 * V_11 = F_71 ( V_13 ) ;
struct V_100 * V_40 = V_11 -> V_9 . V_9 . V_40 ;
struct V_15 * V_15 ;
struct V_69 * V_16 ;
int V_101 ;
V_15 = F_72 () ;
if ( ! V_15 )
return NULL ;
V_16 = & V_15 -> V_9 ;
F_73 ( V_40 , V_16 , & V_102 , V_103 ) ;
F_74 ( V_16 , & V_104 ) ;
V_15 -> V_93 = F_63 ;
V_15 -> V_70 = V_13 ;
V_15 -> V_30 = V_30 ;
for ( V_101 = V_105 ; V_101 <= V_106 ; V_101 ++ ) {
F_75 ( & V_15 -> V_9 ,
& V_13 -> V_92 [ V_101 ] -> V_9 . V_9 ) ;
}
F_76 ( V_13 , V_16 ) ;
F_77 ( & V_16 -> V_9 , V_40 -> V_107 . V_108 , 0 ) ;
F_77 ( & V_16 -> V_9 , V_40 -> V_107 . V_109 , 0 ) ;
F_78 ( V_16 , V_99 ) ;
return V_16 ;
}
static void F_79 ( struct V_69 * V_16 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
struct V_100 * V_40 = V_16 -> V_40 ;
F_80 ( V_40 ) ;
F_64 ( V_15 ) ;
F_81 ( V_40 ) ;
F_82 ( & V_15 -> V_9 ) ;
}
static void F_83 ( struct V_96 * V_97 ,
struct V_69 * V_16 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
struct V_100 * V_40 = V_16 -> V_40 ;
F_84 ( V_16 ) ;
F_80 ( V_40 ) ;
F_67 ( V_15 ) ;
V_15 -> V_70 = NULL ;
F_81 ( V_40 ) ;
F_85 ( & V_15 -> V_9 ) ;
F_12 ( L_5 ) ;
}
static void F_86 ( struct V_96 * V_97 )
{
struct V_13 * V_13 = F_70 ( V_97 , struct V_13 , V_29 ) ;
struct V_10 * V_11 = F_71 ( V_13 ) ;
struct V_100 * V_40 = V_11 -> V_9 . V_9 . V_40 ;
F_87 ( V_40 ) ;
}
static struct V_7 *
F_88 ( struct V_10 * V_11 , enum V_50 V_50 )
{
struct V_7 * V_8 ;
struct V_1 * V_1 ;
struct V_100 * V_40 = V_11 -> V_9 . V_9 . V_40 ;
V_8 = F_89 ( sizeof( * V_8 ) , V_110 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_50 = V_50 ;
V_1 = & V_8 -> V_9 ;
V_8 -> V_12 = V_11 ;
F_90 ( V_40 , & V_1 -> V_9 , & V_111 ,
V_112 , L_6 , F_91 ( V_50 ) ) ;
V_1 -> type = V_113 ;
V_1 -> V_30 = V_11 -> V_30 ;
V_1 -> V_114 = 0x7 ;
V_1 -> V_115 = 0 ;
V_1 -> V_116 = F_1 ;
V_1 -> V_117 = F_10 ;
V_1 -> V_44 = F_18 ;
V_1 -> V_118 = F_23 ;
V_1 -> V_119 = F_34 ;
V_1 -> V_93 = F_38 ;
V_1 -> V_120 = F_39 ;
return V_8 ;
}
static bool
F_92 ( struct V_10 * V_11 )
{
int V_101 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
for ( V_101 = V_105 ; V_101 <= V_106 ; V_101 ++ )
V_13 -> V_92 [ V_101 ] = F_88 ( V_11 , V_101 ) ;
return true ;
}
int
F_93 ( struct V_10 * V_11 , int V_121 )
{
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_100 * V_40 = V_11 -> V_9 . V_9 . V_40 ;
int V_41 ;
V_13 -> V_122 = true ;
V_13 -> V_29 . V_123 = & V_124 ;
F_92 ( V_11 ) ;
V_41 = F_94 ( & V_13 -> V_29 , V_40 ,
& V_13 -> V_125 , 16 , 3 , V_121 ) ;
if ( V_41 ) {
V_13 -> V_122 = false ;
return V_41 ;
}
return 0 ;
}
void
F_95 ( struct V_10 * V_11 )
{
struct V_13 * V_13 = & V_11 -> V_14 ;
if ( ! V_13 -> V_122 )
return;
F_96 ( & V_13 -> V_29 ) ;
}

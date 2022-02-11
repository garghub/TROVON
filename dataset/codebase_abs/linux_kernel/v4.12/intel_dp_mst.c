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
bool V_25 = F_4 ( & V_13 -> V_26 ,
V_27 ) ;
V_4 -> V_28 = false ;
V_19 = 24 ;
if ( V_13 -> V_29 . V_30 . V_31 ) {
V_19 = V_13 -> V_29 . V_30 . V_31 * 3 ;
F_5 ( L_1 ,
V_19 ) ;
}
V_20 = F_6 ( V_13 -> V_32 ) ;
V_4 -> V_20 = V_20 ;
V_4 -> V_33 = V_19 ;
V_4 -> V_34 = F_7 ( V_13 ) ;
V_18 = V_4 -> V_9 . V_18 ;
if ( F_8 ( & V_13 -> V_35 , V_16 -> V_36 ) )
V_4 -> V_37 = true ;
V_24 = F_9 ( V_23 -> V_38 , V_19 ) ;
V_4 -> V_39 = V_24 ;
V_21 = F_10 ( & V_13 -> V_35 , V_24 ) ;
F_11 ( V_19 , V_20 ,
V_23 -> V_38 ,
V_4 -> V_34 ,
& V_4 -> V_40 ,
V_25 ) ;
V_4 -> V_40 . V_41 = V_21 ;
return true ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_42 ,
struct V_5 * V_43 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_15 * V_16 =
F_3 ( V_43 -> V_16 ) ;
int V_44 ;
F_5 ( L_2 , V_13 -> V_45 ) ;
F_13 ( & V_13 -> V_35 , V_16 -> V_36 ) ;
V_44 = F_14 ( & V_13 -> V_35 ) ;
if ( V_44 ) {
F_15 ( L_3 , V_44 ) ;
}
if ( V_42 -> V_37 )
F_16 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_3 * V_42 ,
struct V_5 * V_43 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_15 * V_16 =
F_3 ( V_43 -> V_16 ) ;
F_5 ( L_2 , V_13 -> V_45 ) ;
F_18 ( & V_13 -> V_35 ) ;
F_19 ( & V_13 -> V_35 ) ;
F_20 ( & V_13 -> V_35 , V_16 -> V_36 ) ;
V_13 -> V_45 -- ;
V_8 -> V_16 = NULL ;
if ( V_13 -> V_45 == 0 ) {
V_11 -> V_9 . V_46 ( & V_11 -> V_9 ,
NULL , NULL ) ;
F_21 ( V_13 , V_47 ) ;
}
}
static void F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_48 * V_49 = F_23 ( V_2 -> V_9 . V_50 ) ;
enum V_36 V_36 = V_11 -> V_36 ;
struct V_15 * V_16 =
F_3 ( V_6 -> V_16 ) ;
int V_44 ;
T_1 V_51 ;
V_16 -> V_2 = V_2 ;
V_8 -> V_16 = V_16 ;
F_5 ( L_2 , V_13 -> V_45 ) ;
if ( V_13 -> V_45 == 0 )
V_11 -> V_9 . V_52 ( & V_11 -> V_9 ,
V_4 , NULL ) ;
V_44 = F_24 ( & V_13 -> V_35 ,
V_16 -> V_36 ,
V_4 -> V_39 ,
V_4 -> V_40 . V_41 ) ;
if ( V_44 == false ) {
F_15 ( L_4 ) ;
return;
}
V_13 -> V_45 ++ ;
V_51 = F_25 ( F_26 ( V_36 ) ) ;
F_27 ( F_26 ( V_36 ) , V_51 ) ;
V_44 = F_14 ( & V_13 -> V_35 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_48 * V_49 = F_23 ( V_2 -> V_9 . V_50 ) ;
enum V_36 V_36 = V_11 -> V_36 ;
int V_44 ;
F_5 ( L_2 , V_13 -> V_45 ) ;
if ( F_29 ( V_49 ,
F_26 ( V_36 ) ,
V_53 ,
V_53 ,
1 ) )
F_15 ( L_5 ) ;
V_44 = F_18 ( & V_13 -> V_35 ) ;
V_44 = F_19 ( & V_13 -> V_35 ) ;
if ( V_4 -> V_37 )
F_30 ( V_2 , V_4 , V_6 ) ;
}
static bool F_31 ( struct V_1 * V_2 ,
enum V_54 * V_54 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
* V_54 = V_8 -> V_54 ;
if ( V_8 -> V_16 )
return true ;
return false ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_55 * V_56 = F_33 ( V_4 -> V_9 . V_56 ) ;
struct V_48 * V_49 = F_23 ( V_2 -> V_9 . V_50 ) ;
enum V_57 V_58 = V_4 -> V_58 ;
T_2 V_51 , V_59 = 0 ;
V_4 -> V_37 =
F_34 ( V_49 , V_56 ) ;
V_51 = F_25 ( F_35 ( V_58 ) ) ;
if ( V_51 & V_60 )
V_59 |= V_61 ;
else
V_59 |= V_62 ;
if ( V_51 & V_63 )
V_59 |= V_64 ;
else
V_59 |= V_65 ;
switch ( V_51 & V_66 ) {
case V_67 :
V_4 -> V_33 = 18 ;
break;
case V_68 :
V_4 -> V_33 = 24 ;
break;
case V_69 :
V_4 -> V_33 = 30 ;
break;
case V_70 :
V_4 -> V_33 = 36 ;
break;
default:
break;
}
V_4 -> V_9 . V_23 . V_59 |= V_59 ;
V_4 -> V_20 =
( ( V_51 & V_71 ) >> V_72 ) + 1 ;
F_36 ( V_56 , V_4 ) ;
F_37 ( & V_11 -> V_9 , V_4 ) ;
}
static int F_38 ( struct V_73 * V_16 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
struct V_13 * V_13 = V_15 -> V_74 ;
struct V_75 * V_75 ;
int V_44 ;
if ( ! V_13 ) {
return F_39 ( V_16 , NULL ) ;
}
V_75 = F_40 ( V_16 , & V_13 -> V_35 , V_15 -> V_36 ) ;
V_44 = F_39 ( V_16 , V_75 ) ;
F_41 ( V_75 ) ;
return V_44 ;
}
static enum V_76
F_42 ( struct V_73 * V_16 , bool V_77 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
struct V_13 * V_13 = V_15 -> V_74 ;
if ( ! V_13 )
return V_78 ;
return F_43 ( V_16 , & V_13 -> V_35 , V_15 -> V_36 ) ;
}
static int
F_44 ( struct V_73 * V_16 ,
struct V_79 * V_80 ,
T_3 V_81 )
{
return 0 ;
}
static void
F_45 ( struct V_73 * V_16 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
if ( ! F_46 ( V_15 -> V_75 ) )
F_41 ( V_15 -> V_75 ) ;
F_47 ( V_16 ) ;
F_41 ( V_16 ) ;
}
static int F_48 ( struct V_73 * V_16 )
{
return F_38 ( V_16 ) ;
}
static enum V_82
F_49 ( struct V_73 * V_16 ,
struct V_22 * V_83 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
struct V_13 * V_13 = V_15 -> V_74 ;
int V_84 = F_23 ( V_16 -> V_50 ) -> V_85 ;
int V_19 = 24 ;
int V_86 , V_87 , V_88 , V_89 ;
V_89 = F_7 ( V_13 ) ;
V_88 = F_6 ( V_13 -> V_32 ) ;
V_86 = F_50 ( V_89 , V_88 ) ;
V_87 = F_51 ( V_83 -> clock , V_19 ) ;
if ( V_83 -> clock < 10000 )
return V_90 ;
if ( V_83 -> V_59 & V_91 )
return V_92 ;
if ( V_87 > V_86 || V_83 -> clock > V_84 )
return V_93 ;
return V_94 ;
}
static struct V_95 * F_52 ( struct V_73 * V_16 ,
struct V_5 * V_18 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
struct V_13 * V_13 = V_15 -> V_74 ;
struct V_55 * V_56 = F_33 ( V_18 -> V_56 ) ;
if ( ! V_13 )
return NULL ;
return & V_13 -> V_96 [ V_56 -> V_54 ] -> V_9 . V_9 ;
}
static struct V_95 * F_53 ( struct V_73 * V_16 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
struct V_13 * V_13 = V_15 -> V_74 ;
if ( ! V_13 )
return NULL ;
return & V_13 -> V_96 [ 0 ] -> V_9 . V_9 ;
}
static void F_54 ( struct V_95 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_55 ( V_2 ) ;
F_41 ( V_8 ) ;
}
static bool F_56 ( struct V_15 * V_16 )
{
if ( V_16 -> V_2 && V_16 -> V_9 . V_18 -> V_56 ) {
enum V_54 V_54 ;
if ( ! V_16 -> V_2 -> V_97 ( V_16 -> V_2 , & V_54 ) )
return false ;
return true ;
}
return false ;
}
static void F_57 ( struct V_15 * V_16 )
{
#ifdef F_58
struct V_48 * V_49 = F_23 ( V_16 -> V_9 . V_50 ) ;
if ( V_49 -> V_98 )
F_59 ( & V_49 -> V_98 -> V_99 ,
& V_16 -> V_9 ) ;
#endif
}
static void F_60 ( struct V_15 * V_16 )
{
#ifdef F_58
struct V_48 * V_49 = F_23 ( V_16 -> V_9 . V_50 ) ;
if ( V_49 -> V_98 )
F_61 ( & V_49 -> V_98 -> V_99 ,
& V_16 -> V_9 ) ;
#endif
}
static struct V_73 * F_62 ( struct V_100 * V_101 , struct V_102 * V_36 , const char * V_103 )
{
struct V_13 * V_13 = F_63 ( V_101 , struct V_13 , V_35 ) ;
struct V_10 * V_11 = F_64 ( V_13 ) ;
struct V_104 * V_50 = V_11 -> V_9 . V_9 . V_50 ;
struct V_15 * V_15 ;
struct V_73 * V_16 ;
int V_105 ;
V_15 = F_65 () ;
if ( ! V_15 )
return NULL ;
V_16 = & V_15 -> V_9 ;
F_66 ( V_50 , V_16 , & V_106 , V_107 ) ;
F_67 ( V_16 , & V_108 ) ;
V_15 -> V_97 = F_56 ;
V_15 -> V_74 = V_13 ;
V_15 -> V_36 = V_36 ;
for ( V_105 = V_109 ; V_105 <= V_110 ; V_105 ++ ) {
F_68 ( & V_15 -> V_9 ,
& V_13 -> V_96 [ V_105 ] -> V_9 . V_9 ) ;
}
F_69 ( V_13 , V_16 ) ;
F_70 ( & V_16 -> V_9 , V_50 -> V_111 . V_112 , 0 ) ;
F_70 ( & V_16 -> V_9 , V_50 -> V_111 . V_113 , 0 ) ;
F_71 ( V_16 , V_103 ) ;
return V_16 ;
}
static void F_72 ( struct V_73 * V_16 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
struct V_104 * V_50 = V_16 -> V_50 ;
F_73 ( V_50 ) ;
F_57 ( V_15 ) ;
F_74 ( V_50 ) ;
F_75 ( & V_15 -> V_9 ) ;
}
static void F_76 ( struct V_100 * V_101 ,
struct V_73 * V_16 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
struct V_104 * V_50 = V_16 -> V_50 ;
F_77 ( V_16 ) ;
F_73 ( V_50 ) ;
F_60 ( V_15 ) ;
V_15 -> V_74 = NULL ;
F_74 ( V_50 ) ;
F_78 ( & V_15 -> V_9 ) ;
F_5 ( L_6 ) ;
}
static void F_79 ( struct V_100 * V_101 )
{
struct V_13 * V_13 = F_63 ( V_101 , struct V_13 , V_35 ) ;
struct V_10 * V_11 = F_64 ( V_13 ) ;
struct V_104 * V_50 = V_11 -> V_9 . V_9 . V_50 ;
F_80 ( V_50 ) ;
}
static struct V_7 *
F_81 ( struct V_10 * V_11 , enum V_54 V_54 )
{
struct V_7 * V_8 ;
struct V_1 * V_1 ;
struct V_104 * V_50 = V_11 -> V_9 . V_9 . V_50 ;
V_8 = F_82 ( sizeof( * V_8 ) , V_114 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_54 = V_54 ;
V_1 = & V_8 -> V_9 ;
V_8 -> V_12 = V_11 ;
F_83 ( V_50 , & V_1 -> V_9 , & V_115 ,
V_116 , L_7 , F_84 ( V_54 ) ) ;
V_1 -> type = V_117 ;
V_1 -> V_118 = V_11 -> V_9 . V_118 ;
V_1 -> V_36 = V_11 -> V_36 ;
V_1 -> V_119 = 0x7 ;
V_1 -> V_120 = 0 ;
V_1 -> V_121 = F_1 ;
V_1 -> V_122 = F_12 ;
V_1 -> V_46 = F_17 ;
V_1 -> V_52 = F_22 ;
V_1 -> V_123 = F_28 ;
V_1 -> V_97 = F_31 ;
V_1 -> V_124 = F_32 ;
return V_8 ;
}
static bool
F_85 ( struct V_10 * V_11 )
{
int V_105 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
for ( V_105 = V_109 ; V_105 <= V_110 ; V_105 ++ )
V_13 -> V_96 [ V_105 ] = F_81 ( V_11 , V_105 ) ;
return true ;
}
int
F_86 ( struct V_10 * V_11 , int V_125 )
{
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_104 * V_50 = V_11 -> V_9 . V_9 . V_50 ;
int V_44 ;
V_13 -> V_126 = true ;
V_13 -> V_35 . V_127 = & V_128 ;
F_85 ( V_11 ) ;
V_44 = F_87 ( & V_13 -> V_35 , V_50 ,
& V_13 -> V_129 , 16 , 3 , V_125 ) ;
if ( V_44 ) {
V_13 -> V_126 = false ;
return V_44 ;
}
return 0 ;
}
void
F_88 ( struct V_10 * V_11 )
{
struct V_13 * V_13 = & V_11 -> V_14 ;
if ( ! V_13 -> V_126 )
return;
F_89 ( & V_13 -> V_35 ) ;
}

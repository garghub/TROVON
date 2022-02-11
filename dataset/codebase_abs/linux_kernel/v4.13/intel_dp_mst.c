static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_15 * V_16 =
F_3 ( V_6 -> V_16 ) ;
struct V_17 * V_18 = V_4 -> V_9 . V_18 ;
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
V_20 = F_6 ( V_13 ) ;
V_4 -> V_20 = V_20 ;
V_4 -> V_32 = V_19 ;
V_4 -> V_33 = F_7 ( V_13 ) ;
if ( F_8 ( & V_13 -> V_34 , V_16 -> V_35 ) )
V_4 -> V_36 = true ;
V_24 = F_9 ( V_23 -> V_37 , V_19 ) ;
V_4 -> V_38 = V_24 ;
V_21 = F_10 ( V_18 , & V_13 -> V_34 ,
V_16 -> V_35 , V_24 ) ;
if ( V_21 < 0 ) {
F_5 ( L_2 , V_21 ) ;
return false ;
}
F_11 ( V_19 , V_20 ,
V_23 -> V_37 ,
V_4 -> V_33 ,
& V_4 -> V_39 ,
V_25 ) ;
V_4 -> V_39 . V_40 = V_21 ;
return true ;
}
static int F_12 ( struct V_41 * V_16 ,
struct V_5 * V_42 )
{
struct V_17 * V_18 = V_42 -> V_18 ;
struct V_5 * V_43 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
int V_21 , V_48 = 0 ;
V_43 = F_13 ( V_18 , V_16 ) ;
V_45 = V_43 -> V_49 ;
if ( ! V_45 )
return V_48 ;
V_47 = F_14 ( V_18 , V_45 ) ;
V_21 = F_15 ( V_47 ) -> V_39 . V_40 ;
if ( F_16 ( V_47 ) && V_21 > 0 ) {
struct V_50 * V_51 ;
struct V_52 * V_53 ;
V_53 = V_43 -> V_54 ;
V_51 = & F_2 ( V_53 ) -> V_12 -> V_14 . V_34 ;
V_48 = F_17 ( V_18 , V_51 , V_21 ) ;
if ( V_48 )
F_5 ( L_3 , V_21 , V_48 ) ;
else
F_15 ( V_47 ) -> V_39 . V_40 = 0 ;
}
return V_48 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_3 * V_55 ,
struct V_5 * V_43 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_15 * V_16 =
F_3 ( V_43 -> V_16 ) ;
int V_48 ;
F_5 ( L_4 , V_13 -> V_56 ) ;
F_19 ( & V_13 -> V_34 , V_16 -> V_35 ) ;
V_48 = F_20 ( & V_13 -> V_34 ) ;
if ( V_48 ) {
F_21 ( L_5 , V_48 ) ;
}
if ( V_55 -> V_36 )
F_22 ( V_2 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_3 * V_55 ,
struct V_5 * V_43 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_15 * V_16 =
F_3 ( V_43 -> V_16 ) ;
F_5 ( L_4 , V_13 -> V_56 ) ;
F_24 ( & V_13 -> V_34 ) ;
F_25 ( & V_13 -> V_34 ) ;
F_26 ( & V_13 -> V_34 , V_16 -> V_35 ) ;
V_13 -> V_56 -- ;
V_8 -> V_16 = NULL ;
if ( V_13 -> V_56 == 0 ) {
V_11 -> V_9 . V_57 ( & V_11 -> V_9 ,
NULL , NULL ) ;
F_27 ( V_13 , V_58 ) ;
}
}
static void F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_59 * V_60 = F_29 ( V_2 -> V_9 . V_61 ) ;
enum V_35 V_35 = V_11 -> V_35 ;
struct V_15 * V_16 =
F_3 ( V_6 -> V_16 ) ;
int V_48 ;
T_1 V_62 ;
V_16 -> V_2 = V_2 ;
V_8 -> V_16 = V_16 ;
F_5 ( L_4 , V_13 -> V_56 ) ;
if ( V_13 -> V_56 == 0 )
V_11 -> V_9 . V_63 ( & V_11 -> V_9 ,
V_4 , NULL ) ;
V_48 = F_30 ( & V_13 -> V_34 ,
V_16 -> V_35 ,
V_4 -> V_38 ,
V_4 -> V_39 . V_40 ) ;
if ( V_48 == false ) {
F_21 ( L_6 ) ;
return;
}
V_13 -> V_56 ++ ;
V_62 = F_31 ( F_32 ( V_35 ) ) ;
F_33 ( F_32 ( V_35 ) , V_62 ) ;
V_48 = F_20 ( & V_13 -> V_34 ) ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_59 * V_60 = F_29 ( V_2 -> V_9 . V_61 ) ;
enum V_35 V_35 = V_11 -> V_35 ;
int V_48 ;
F_5 ( L_4 , V_13 -> V_56 ) ;
if ( F_35 ( V_60 ,
F_32 ( V_35 ) ,
V_64 ,
V_64 ,
1 ) )
F_21 ( L_7 ) ;
V_48 = F_24 ( & V_13 -> V_34 ) ;
V_48 = F_25 ( & V_13 -> V_34 ) ;
if ( V_4 -> V_36 )
F_36 ( V_2 , V_4 , V_6 ) ;
}
static bool F_37 ( struct V_1 * V_2 ,
enum V_65 * V_65 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
* V_65 = V_8 -> V_65 ;
if ( V_8 -> V_16 )
return true ;
return false ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_66 * V_49 = F_39 ( V_4 -> V_9 . V_49 ) ;
struct V_59 * V_60 = F_29 ( V_2 -> V_9 . V_61 ) ;
enum V_67 V_68 = V_4 -> V_68 ;
T_2 V_62 , V_69 = 0 ;
V_4 -> V_36 =
F_40 ( V_60 , V_49 ) ;
V_62 = F_31 ( F_41 ( V_68 ) ) ;
if ( V_62 & V_70 )
V_69 |= V_71 ;
else
V_69 |= V_72 ;
if ( V_62 & V_73 )
V_69 |= V_74 ;
else
V_69 |= V_75 ;
switch ( V_62 & V_76 ) {
case V_77 :
V_4 -> V_32 = 18 ;
break;
case V_78 :
V_4 -> V_32 = 24 ;
break;
case V_79 :
V_4 -> V_32 = 30 ;
break;
case V_80 :
V_4 -> V_32 = 36 ;
break;
default:
break;
}
V_4 -> V_9 . V_23 . V_69 |= V_69 ;
V_4 -> V_20 =
( ( V_62 & V_81 ) >> V_82 ) + 1 ;
F_42 ( V_49 , V_4 ) ;
F_43 ( & V_11 -> V_9 , V_4 ) ;
}
static int F_44 ( struct V_41 * V_16 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
struct V_13 * V_13 = V_15 -> V_83 ;
struct V_84 * V_84 ;
int V_48 ;
if ( ! V_13 ) {
return F_45 ( V_16 , NULL ) ;
}
V_84 = F_46 ( V_16 , & V_13 -> V_34 , V_15 -> V_35 ) ;
V_48 = F_45 ( V_16 , V_84 ) ;
F_47 ( V_84 ) ;
return V_48 ;
}
static enum V_85
F_48 ( struct V_41 * V_16 , bool V_86 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
struct V_13 * V_13 = V_15 -> V_83 ;
if ( ! V_13 )
return V_87 ;
return F_49 ( V_16 , & V_13 -> V_34 , V_15 -> V_35 ) ;
}
static void
F_50 ( struct V_41 * V_16 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
if ( ! F_51 ( V_15 -> V_84 ) )
F_47 ( V_15 -> V_84 ) ;
F_52 ( V_16 ) ;
F_47 ( V_16 ) ;
}
static int F_53 ( struct V_41 * V_16 )
{
return F_44 ( V_16 ) ;
}
static enum V_88
F_54 ( struct V_41 * V_16 ,
struct V_22 * V_89 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
struct V_13 * V_13 = V_15 -> V_83 ;
int V_90 = F_29 ( V_16 -> V_61 ) -> V_91 ;
int V_19 = 24 ;
int V_92 , V_93 , V_94 , V_95 ;
V_95 = F_7 ( V_13 ) ;
V_94 = F_6 ( V_13 ) ;
V_92 = F_55 ( V_95 , V_94 ) ;
V_93 = F_56 ( V_89 -> clock , V_19 ) ;
if ( V_89 -> clock < 10000 )
return V_96 ;
if ( V_89 -> V_69 & V_97 )
return V_98 ;
if ( V_93 > V_92 || V_89 -> clock > V_90 )
return V_99 ;
return V_100 ;
}
static struct V_52 * F_57 ( struct V_41 * V_16 ,
struct V_5 * V_18 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
struct V_13 * V_13 = V_15 -> V_83 ;
struct V_66 * V_49 = F_39 ( V_18 -> V_49 ) ;
if ( ! V_13 )
return NULL ;
return & V_13 -> V_101 [ V_49 -> V_65 ] -> V_9 . V_9 ;
}
static struct V_52 * F_58 ( struct V_41 * V_16 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
struct V_13 * V_13 = V_15 -> V_83 ;
if ( ! V_13 )
return NULL ;
return & V_13 -> V_101 [ 0 ] -> V_9 . V_9 ;
}
static void F_59 ( struct V_52 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_60 ( V_2 ) ;
F_47 ( V_8 ) ;
}
static bool F_61 ( struct V_15 * V_16 )
{
if ( V_16 -> V_2 && V_16 -> V_9 . V_18 -> V_49 ) {
enum V_65 V_65 ;
if ( ! V_16 -> V_2 -> V_102 ( V_16 -> V_2 , & V_65 ) )
return false ;
return true ;
}
return false ;
}
static void F_62 ( struct V_15 * V_16 )
{
#ifdef F_63
struct V_59 * V_60 = F_29 ( V_16 -> V_9 . V_61 ) ;
if ( V_60 -> V_103 )
F_64 ( & V_60 -> V_103 -> V_104 ,
& V_16 -> V_9 ) ;
#endif
}
static void F_65 ( struct V_15 * V_16 )
{
#ifdef F_63
struct V_59 * V_60 = F_29 ( V_16 -> V_9 . V_61 ) ;
if ( V_60 -> V_103 )
F_66 ( & V_60 -> V_103 -> V_104 ,
& V_16 -> V_9 ) ;
#endif
}
static struct V_41 * F_67 ( struct V_50 * V_51 , struct V_105 * V_35 , const char * V_106 )
{
struct V_13 * V_13 = F_68 ( V_51 , struct V_13 , V_34 ) ;
struct V_10 * V_11 = F_69 ( V_13 ) ;
struct V_107 * V_61 = V_11 -> V_9 . V_9 . V_61 ;
struct V_15 * V_15 ;
struct V_41 * V_16 ;
int V_108 ;
V_15 = F_70 () ;
if ( ! V_15 )
return NULL ;
V_16 = & V_15 -> V_9 ;
F_71 ( V_61 , V_16 , & V_109 , V_110 ) ;
F_72 ( V_16 , & V_111 ) ;
V_15 -> V_102 = F_61 ;
V_15 -> V_83 = V_13 ;
V_15 -> V_35 = V_35 ;
for ( V_108 = V_112 ; V_108 <= V_113 ; V_108 ++ ) {
F_73 ( & V_15 -> V_9 ,
& V_13 -> V_101 [ V_108 ] -> V_9 . V_9 ) ;
}
F_74 ( & V_16 -> V_9 , V_61 -> V_114 . V_115 , 0 ) ;
F_74 ( & V_16 -> V_9 , V_61 -> V_114 . V_116 , 0 ) ;
F_75 ( V_16 , V_106 ) ;
return V_16 ;
}
static void F_76 ( struct V_41 * V_16 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
struct V_107 * V_61 = V_16 -> V_61 ;
F_77 ( V_61 ) ;
F_62 ( V_15 ) ;
F_78 ( V_61 ) ;
F_79 ( & V_15 -> V_9 ) ;
}
static void F_80 ( struct V_50 * V_51 ,
struct V_41 * V_16 )
{
struct V_15 * V_15 = F_3 ( V_16 ) ;
struct V_107 * V_61 = V_16 -> V_61 ;
F_81 ( V_16 ) ;
F_77 ( V_61 ) ;
F_65 ( V_15 ) ;
V_15 -> V_83 = NULL ;
F_78 ( V_61 ) ;
F_82 ( & V_15 -> V_9 ) ;
F_5 ( L_8 ) ;
}
static void F_83 ( struct V_50 * V_51 )
{
struct V_13 * V_13 = F_68 ( V_51 , struct V_13 , V_34 ) ;
struct V_10 * V_11 = F_69 ( V_13 ) ;
struct V_107 * V_61 = V_11 -> V_9 . V_9 . V_61 ;
F_84 ( V_61 ) ;
}
static struct V_7 *
F_85 ( struct V_10 * V_11 , enum V_65 V_65 )
{
struct V_7 * V_8 ;
struct V_1 * V_1 ;
struct V_107 * V_61 = V_11 -> V_9 . V_9 . V_61 ;
V_8 = F_86 ( sizeof( * V_8 ) , V_117 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_65 = V_65 ;
V_1 = & V_8 -> V_9 ;
V_8 -> V_12 = V_11 ;
F_87 ( V_61 , & V_1 -> V_9 , & V_118 ,
V_119 , L_9 , F_88 ( V_65 ) ) ;
V_1 -> type = V_120 ;
V_1 -> V_121 = V_11 -> V_9 . V_121 ;
V_1 -> V_35 = V_11 -> V_35 ;
V_1 -> V_122 = 0x7 ;
V_1 -> V_123 = 0 ;
V_1 -> V_124 = F_1 ;
V_1 -> V_125 = F_18 ;
V_1 -> V_57 = F_23 ;
V_1 -> V_63 = F_28 ;
V_1 -> V_126 = F_34 ;
V_1 -> V_102 = F_37 ;
V_1 -> V_127 = F_38 ;
return V_8 ;
}
static bool
F_89 ( struct V_10 * V_11 )
{
int V_108 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
for ( V_108 = V_112 ; V_108 <= V_113 ; V_108 ++ )
V_13 -> V_101 [ V_108 ] = F_85 ( V_11 , V_108 ) ;
return true ;
}
int
F_90 ( struct V_10 * V_11 , int V_128 )
{
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_107 * V_61 = V_11 -> V_9 . V_9 . V_61 ;
int V_48 ;
V_13 -> V_129 = true ;
V_13 -> V_34 . V_130 = & V_131 ;
F_89 ( V_11 ) ;
V_48 = F_91 ( & V_13 -> V_34 , V_61 ,
& V_13 -> V_132 , 16 , 3 , V_128 ) ;
if ( V_48 ) {
V_13 -> V_129 = false ;
return V_48 ;
}
return 0 ;
}
void
F_92 ( struct V_10 * V_11 )
{
struct V_13 * V_13 = & V_11 -> V_14 ;
if ( ! V_13 -> V_129 )
return;
F_93 ( & V_13 -> V_34 ) ;
}

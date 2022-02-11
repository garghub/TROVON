static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
struct V_13 * V_14 ;
int V_15 , V_16 ;
int V_17 , V_18 ;
const struct V_19 * V_20 = & V_4 -> V_7 . V_20 ;
struct V_21 * V_21 ;
struct V_22 * V_23 , * V_24 = NULL ;
struct V_25 * V_26 ;
int V_27 ;
V_4 -> V_28 = true ;
V_4 -> V_29 = false ;
V_4 -> V_30 = true ;
V_15 = 24 ;
V_17 = F_3 ( V_11 -> V_31 ) ;
V_4 -> V_17 = V_17 ;
V_4 -> V_32 = 24 ;
V_4 -> V_33 = F_4 ( V_11 ) ;
V_14 = V_4 -> V_7 . V_14 ;
F_5 (state, drm_connector, connector_state, i) {
V_23 = F_6 ( V_21 ) ;
if ( V_26 -> V_34 == & V_2 -> V_7 ) {
V_24 = V_23 ;
break;
}
}
if ( ! V_24 ) {
F_7 ( L_1 ) ;
return false ;
}
V_27 = F_8 ( V_20 -> V_35 , V_15 ) ;
V_4 -> V_36 = V_27 ;
V_18 = F_9 ( & V_11 -> V_37 , V_27 ) ;
F_10 ( V_15 , V_17 ,
V_20 -> V_35 ,
V_4 -> V_33 ,
& V_4 -> V_38 ) ;
V_4 -> V_38 . V_39 = V_18 ;
return true ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
int V_40 ;
F_12 ( L_2 , V_11 -> V_41 ) ;
F_13 ( & V_11 -> V_37 , V_6 -> V_23 -> V_42 ) ;
V_40 = F_14 ( & V_11 -> V_37 ) ;
if ( V_40 ) {
F_7 ( L_3 , V_40 ) ;
}
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
F_12 ( L_2 , V_11 -> V_41 ) ;
F_16 ( & V_11 -> V_37 ) ;
F_17 ( & V_11 -> V_37 ) ;
F_18 ( & V_11 -> V_37 , V_6 -> V_23 -> V_42 ) ;
V_11 -> V_41 -- ;
V_6 -> V_23 = NULL ;
if ( V_11 -> V_41 == 0 ) {
V_9 -> V_7 . V_43 ( & V_9 -> V_7 ) ;
F_19 ( V_11 , V_44 ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
struct V_45 * V_46 = V_2 -> V_7 . V_46 ;
struct V_47 * V_48 = V_46 -> V_49 ;
enum V_42 V_42 = V_9 -> V_42 ;
int V_40 ;
T_1 V_50 ;
struct V_22 * V_24 = NULL , * V_23 ;
int V_18 ;
struct V_51 * V_52 = V_2 -> V_7 . V_52 ;
struct V_53 * V_53 = F_21 ( V_52 ) ;
F_22 (dev, connector) {
if ( V_23 -> V_7 . V_14 -> V_34 == & V_2 -> V_7 ) {
V_24 = V_23 ;
break;
}
}
if ( ! V_24 ) {
F_7 ( L_1 ) ;
return;
}
V_24 -> V_2 = V_2 ;
F_12 ( L_2 , V_11 -> V_41 ) ;
V_6 -> V_23 = V_24 ;
if ( V_11 -> V_41 == 0 ) {
F_23 ( & V_9 -> V_7 ) ;
F_24 ( & V_9 -> V_7 , V_53 -> V_54 ) ;
F_25 ( V_11 , V_53 -> V_54 ) ;
F_26 ( & V_9 -> V_7 ) ;
F_19 ( V_11 , V_55 ) ;
F_27 ( V_11 ) ;
F_28 ( V_11 ) ;
}
V_40 = F_29 ( & V_11 -> V_37 ,
V_6 -> V_23 -> V_42 ,
V_53 -> V_54 -> V_36 , & V_18 ) ;
if ( V_40 == false ) {
F_7 ( L_4 ) ;
return;
}
V_11 -> V_41 ++ ;
V_50 = F_30 ( F_31 ( V_42 ) ) ;
F_32 ( F_31 ( V_42 ) , V_50 ) ;
V_40 = F_14 ( & V_11 -> V_37 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
struct V_45 * V_46 = V_9 -> V_7 . V_7 . V_46 ;
struct V_47 * V_48 = V_46 -> V_49 ;
enum V_42 V_42 = V_9 -> V_42 ;
int V_40 ;
F_12 ( L_2 , V_11 -> V_41 ) ;
if ( F_34 ( ( F_30 ( F_31 ( V_42 ) ) & V_56 ) ,
1 ) )
F_7 ( L_5 ) ;
V_40 = F_16 ( & V_11 -> V_37 ) ;
V_40 = F_17 ( & V_11 -> V_37 ) ;
}
static bool F_35 ( struct V_1 * V_2 ,
enum V_57 * V_57 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
* V_57 = V_6 -> V_57 ;
if ( V_6 -> V_23 )
return true ;
return false ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_53 * V_52 = F_21 ( V_2 -> V_7 . V_52 ) ;
struct V_45 * V_46 = V_2 -> V_7 . V_46 ;
struct V_47 * V_48 = V_46 -> V_49 ;
enum V_58 V_59 = V_4 -> V_59 ;
T_2 V_50 , V_60 = 0 ;
V_4 -> V_30 = true ;
V_50 = F_30 ( F_37 ( V_59 ) ) ;
if ( V_50 & V_61 )
V_60 |= V_62 ;
else
V_60 |= V_63 ;
if ( V_50 & V_64 )
V_60 |= V_65 ;
else
V_60 |= V_66 ;
switch ( V_50 & V_67 ) {
case V_68 :
V_4 -> V_32 = 18 ;
break;
case V_69 :
V_4 -> V_32 = 24 ;
break;
case V_70 :
V_4 -> V_32 = 30 ;
break;
case V_71 :
V_4 -> V_32 = 36 ;
break;
default:
break;
}
V_4 -> V_7 . V_20 . V_60 |= V_60 ;
V_4 -> V_17 =
( ( V_50 & V_72 ) >> V_73 ) + 1 ;
F_38 ( V_52 , V_4 ) ;
F_39 ( & V_9 -> V_7 , V_4 ) ;
}
static int F_40 ( struct V_21 * V_23 )
{
struct V_22 * V_22 = F_6 ( V_23 ) ;
struct V_11 * V_11 = V_22 -> V_74 ;
struct V_75 * V_75 ;
int V_40 ;
if ( ! V_11 ) {
return F_41 ( V_23 , NULL ) ;
}
V_75 = F_42 ( V_23 , & V_11 -> V_37 , V_22 -> V_42 ) ;
V_40 = F_41 ( V_23 , V_75 ) ;
F_43 ( V_75 ) ;
return V_40 ;
}
static enum V_76
F_44 ( struct V_21 * V_23 , bool V_77 )
{
struct V_22 * V_22 = F_6 ( V_23 ) ;
struct V_11 * V_11 = V_22 -> V_74 ;
if ( ! V_11 )
return V_78 ;
return F_45 ( V_23 , & V_11 -> V_37 , V_22 -> V_42 ) ;
}
static int
F_46 ( struct V_21 * V_23 ,
struct V_79 * V_80 ,
T_3 V_81 )
{
return 0 ;
}
static void
F_47 ( struct V_21 * V_23 )
{
struct V_22 * V_22 = F_6 ( V_23 ) ;
if ( ! F_48 ( V_22 -> V_75 ) )
F_43 ( V_22 -> V_75 ) ;
F_49 ( V_23 ) ;
F_43 ( V_23 ) ;
}
static int F_50 ( struct V_21 * V_23 )
{
return F_40 ( V_23 ) ;
}
static enum V_82
F_51 ( struct V_21 * V_23 ,
struct V_19 * V_83 )
{
int V_84 = F_52 ( V_23 -> V_46 ) -> V_85 ;
if ( V_83 -> clock < 10000 )
return V_86 ;
if ( V_83 -> V_60 & V_87 )
return V_88 ;
if ( V_83 -> clock > V_84 )
return V_89 ;
return V_90 ;
}
static struct V_91 * F_53 ( struct V_21 * V_23 ,
struct V_25 * V_14 )
{
struct V_22 * V_22 = F_6 ( V_23 ) ;
struct V_11 * V_11 = V_22 -> V_74 ;
struct V_53 * V_52 = F_21 ( V_14 -> V_52 ) ;
if ( ! V_11 )
return NULL ;
return & V_11 -> V_92 [ V_52 -> V_57 ] -> V_7 . V_7 ;
}
static struct V_91 * F_54 ( struct V_21 * V_23 )
{
struct V_22 * V_22 = F_6 ( V_23 ) ;
struct V_11 * V_11 = V_22 -> V_74 ;
if ( ! V_11 )
return NULL ;
return & V_11 -> V_92 [ 0 ] -> V_7 . V_7 ;
}
static void F_55 ( struct V_91 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_56 ( V_2 ) ;
F_43 ( V_6 ) ;
}
static bool F_57 ( struct V_22 * V_23 )
{
if ( V_23 -> V_2 && V_23 -> V_7 . V_14 -> V_52 ) {
enum V_57 V_57 ;
if ( ! V_23 -> V_2 -> V_93 ( V_23 -> V_2 , & V_57 ) )
return false ;
return true ;
}
return false ;
}
static void F_58 ( struct V_22 * V_23 )
{
#ifdef F_59
struct V_47 * V_48 = F_52 ( V_23 -> V_7 . V_46 ) ;
if ( V_48 -> V_94 )
F_60 ( & V_48 -> V_94 -> V_95 ,
& V_23 -> V_7 ) ;
#endif
}
static void F_61 ( struct V_22 * V_23 )
{
#ifdef F_59
struct V_47 * V_48 = F_52 ( V_23 -> V_7 . V_46 ) ;
if ( V_48 -> V_94 )
F_62 ( & V_48 -> V_94 -> V_95 ,
& V_23 -> V_7 ) ;
#endif
}
static struct V_21 * F_63 ( struct V_96 * V_97 , struct V_98 * V_42 , const char * V_99 )
{
struct V_11 * V_11 = F_64 ( V_97 , struct V_11 , V_37 ) ;
struct V_8 * V_9 = F_65 ( V_11 ) ;
struct V_45 * V_46 = V_9 -> V_7 . V_7 . V_46 ;
struct V_22 * V_22 ;
struct V_21 * V_23 ;
int V_16 ;
V_22 = F_66 () ;
if ( ! V_22 )
return NULL ;
V_23 = & V_22 -> V_7 ;
F_67 ( V_46 , V_23 , & V_100 , V_101 ) ;
F_68 ( V_23 , & V_102 ) ;
V_22 -> V_103 = V_104 ;
V_22 -> V_93 = F_57 ;
V_22 -> V_74 = V_11 ;
V_22 -> V_42 = V_42 ;
for ( V_16 = V_105 ; V_16 <= V_106 ; V_16 ++ ) {
F_69 ( & V_22 -> V_7 ,
& V_11 -> V_92 [ V_16 ] -> V_7 . V_7 ) ;
}
F_70 ( V_11 , V_23 ) ;
F_71 ( & V_23 -> V_7 , V_46 -> V_107 . V_108 , 0 ) ;
F_71 ( & V_23 -> V_7 , V_46 -> V_107 . V_109 , 0 ) ;
F_72 ( V_23 , V_99 ) ;
return V_23 ;
}
static void F_73 ( struct V_21 * V_23 )
{
struct V_22 * V_22 = F_6 ( V_23 ) ;
struct V_45 * V_46 = V_23 -> V_46 ;
F_74 ( V_46 ) ;
F_58 ( V_22 ) ;
F_75 ( V_46 ) ;
F_76 ( & V_22 -> V_7 ) ;
}
static void F_77 ( struct V_96 * V_97 ,
struct V_21 * V_23 )
{
struct V_22 * V_22 = F_6 ( V_23 ) ;
struct V_45 * V_46 = V_23 -> V_46 ;
V_22 -> V_103 ( V_22 ) ;
F_74 ( V_46 ) ;
F_61 ( V_22 ) ;
V_22 -> V_74 = NULL ;
F_75 ( V_46 ) ;
F_78 ( & V_22 -> V_7 ) ;
F_12 ( L_6 ) ;
}
static void F_79 ( struct V_96 * V_97 )
{
struct V_11 * V_11 = F_64 ( V_97 , struct V_11 , V_37 ) ;
struct V_8 * V_9 = F_65 ( V_11 ) ;
struct V_45 * V_46 = V_9 -> V_7 . V_7 . V_46 ;
F_80 ( V_46 ) ;
}
static struct V_5 *
F_81 ( struct V_8 * V_9 , enum V_57 V_57 )
{
struct V_5 * V_6 ;
struct V_1 * V_1 ;
struct V_45 * V_46 = V_9 -> V_7 . V_7 . V_46 ;
V_6 = F_82 ( sizeof( * V_6 ) , V_110 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_57 = V_57 ;
V_1 = & V_6 -> V_7 ;
V_6 -> V_10 = V_9 ;
F_83 ( V_46 , & V_1 -> V_7 , & V_111 ,
V_112 , NULL ) ;
V_1 -> type = V_113 ;
V_1 -> V_114 = 0x7 ;
V_1 -> V_115 = 0 ;
V_1 -> V_116 = F_1 ;
V_1 -> V_117 = F_11 ;
V_1 -> V_43 = F_15 ;
V_1 -> V_118 = F_20 ;
V_1 -> V_119 = F_33 ;
V_1 -> V_93 = F_35 ;
V_1 -> V_120 = F_36 ;
return V_6 ;
}
static bool
F_84 ( struct V_8 * V_9 )
{
int V_16 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
for ( V_16 = V_105 ; V_16 <= V_106 ; V_16 ++ )
V_11 -> V_92 [ V_16 ] = F_81 ( V_9 , V_16 ) ;
return true ;
}
int
F_85 ( struct V_8 * V_9 , int V_121 )
{
struct V_11 * V_11 = & V_9 -> V_12 ;
struct V_45 * V_46 = V_9 -> V_7 . V_7 . V_46 ;
int V_40 ;
V_11 -> V_122 = true ;
V_11 -> V_37 . V_123 = & V_124 ;
F_84 ( V_9 ) ;
V_40 = F_86 ( & V_11 -> V_37 , V_46 -> V_46 , & V_11 -> V_125 , 16 , 3 , V_121 ) ;
if ( V_40 ) {
V_11 -> V_122 = false ;
return V_40 ;
}
return 0 ;
}
void
F_87 ( struct V_8 * V_9 )
{
struct V_11 * V_11 = & V_9 -> V_12 ;
if ( ! V_11 -> V_122 )
return;
F_88 ( & V_11 -> V_37 ) ;
}

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
V_15 = 24 ;
V_17 = F_3 ( V_11 -> V_30 ) ;
V_4 -> V_17 = V_17 ;
V_4 -> V_31 = 24 ;
V_4 -> V_32 = F_4 ( V_11 ) ;
V_14 = V_4 -> V_7 . V_14 ;
F_5 (state, drm_connector, connector_state, i) {
V_23 = F_6 ( V_21 ) ;
if ( V_26 -> V_33 == & V_2 -> V_7 ) {
V_24 = V_23 ;
break;
}
}
if ( ! V_24 ) {
F_7 ( L_1 ) ;
return false ;
}
V_27 = F_8 ( V_20 -> V_34 , V_15 ) ;
V_4 -> V_35 = V_27 ;
V_18 = F_9 ( & V_11 -> V_36 , V_27 ) ;
F_10 ( V_15 , V_17 ,
V_20 -> V_34 ,
V_4 -> V_32 ,
& V_4 -> V_37 ) ;
V_4 -> V_37 . V_38 = V_18 ;
return true ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
int V_39 ;
F_12 ( L_2 , V_11 -> V_40 ) ;
F_13 ( & V_11 -> V_36 , V_6 -> V_23 -> V_41 ) ;
V_39 = F_14 ( & V_11 -> V_36 ) ;
if ( V_39 ) {
F_7 ( L_3 , V_39 ) ;
}
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
F_12 ( L_2 , V_11 -> V_40 ) ;
F_16 ( & V_11 -> V_36 ) ;
F_17 ( & V_11 -> V_36 ) ;
F_18 ( & V_11 -> V_36 , V_6 -> V_23 -> V_41 ) ;
V_11 -> V_40 -- ;
V_6 -> V_23 = NULL ;
if ( V_11 -> V_40 == 0 ) {
V_9 -> V_7 . V_42 ( & V_9 -> V_7 ) ;
F_19 ( V_11 , V_43 ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
struct V_44 * V_45 = V_2 -> V_7 . V_45 ;
struct V_46 * V_47 = F_21 ( V_45 ) ;
enum V_41 V_41 = V_9 -> V_41 ;
int V_39 ;
T_1 V_48 ;
struct V_22 * V_24 = NULL , * V_23 ;
int V_18 ;
struct V_49 * V_50 = V_2 -> V_7 . V_50 ;
struct V_51 * V_51 = F_22 ( V_50 ) ;
F_23 (dev, connector) {
if ( V_23 -> V_7 . V_14 -> V_33 == & V_2 -> V_7 ) {
V_24 = V_23 ;
break;
}
}
if ( ! V_24 ) {
F_7 ( L_1 ) ;
return;
}
V_24 -> V_2 = V_2 ;
F_12 ( L_2 , V_11 -> V_40 ) ;
V_6 -> V_23 = V_24 ;
if ( V_11 -> V_40 == 0 ) {
F_24 ( & V_9 -> V_7 ) ;
F_25 ( & V_9 -> V_7 , V_51 -> V_52 ) ;
F_26 ( V_11 , V_51 -> V_52 ) ;
F_27 ( & V_9 -> V_7 ) ;
F_19 ( V_11 , V_53 ) ;
F_28 ( V_11 ) ;
F_29 ( V_11 ) ;
}
V_39 = F_30 ( & V_11 -> V_36 ,
V_6 -> V_23 -> V_41 ,
V_51 -> V_52 -> V_35 , & V_18 ) ;
if ( V_39 == false ) {
F_7 ( L_4 ) ;
return;
}
V_11 -> V_40 ++ ;
V_48 = F_31 ( F_32 ( V_41 ) ) ;
F_33 ( F_32 ( V_41 ) , V_48 ) ;
V_39 = F_14 ( & V_11 -> V_36 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
struct V_44 * V_45 = V_9 -> V_7 . V_7 . V_45 ;
struct V_46 * V_47 = F_21 ( V_45 ) ;
enum V_41 V_41 = V_9 -> V_41 ;
int V_39 ;
F_12 ( L_2 , V_11 -> V_40 ) ;
if ( F_35 ( V_47 ,
F_32 ( V_41 ) ,
V_54 ,
V_54 ,
1 ) )
F_7 ( L_5 ) ;
V_39 = F_16 ( & V_11 -> V_36 ) ;
V_39 = F_17 ( & V_11 -> V_36 ) ;
}
static bool F_36 ( struct V_1 * V_2 ,
enum V_55 * V_55 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
* V_55 = V_6 -> V_55 ;
if ( V_6 -> V_23 )
return true ;
return false ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_51 * V_50 = F_22 ( V_2 -> V_7 . V_50 ) ;
struct V_44 * V_45 = V_2 -> V_7 . V_45 ;
struct V_46 * V_47 = F_21 ( V_45 ) ;
enum V_56 V_57 = V_4 -> V_57 ;
T_2 V_48 , V_58 = 0 ;
V_48 = F_31 ( F_38 ( V_57 ) ) ;
if ( V_48 & V_59 )
V_58 |= V_60 ;
else
V_58 |= V_61 ;
if ( V_48 & V_62 )
V_58 |= V_63 ;
else
V_58 |= V_64 ;
switch ( V_48 & V_65 ) {
case V_66 :
V_4 -> V_31 = 18 ;
break;
case V_67 :
V_4 -> V_31 = 24 ;
break;
case V_68 :
V_4 -> V_31 = 30 ;
break;
case V_69 :
V_4 -> V_31 = 36 ;
break;
default:
break;
}
V_4 -> V_7 . V_20 . V_58 |= V_58 ;
V_4 -> V_17 =
( ( V_48 & V_70 ) >> V_71 ) + 1 ;
F_39 ( V_50 , V_4 ) ;
F_40 ( & V_9 -> V_7 , V_4 ) ;
}
static int F_41 ( struct V_21 * V_23 )
{
struct V_22 * V_22 = F_6 ( V_23 ) ;
struct V_11 * V_11 = V_22 -> V_72 ;
struct V_73 * V_73 ;
int V_39 ;
if ( ! V_11 ) {
return F_42 ( V_23 , NULL ) ;
}
V_73 = F_43 ( V_23 , & V_11 -> V_36 , V_22 -> V_41 ) ;
V_39 = F_42 ( V_23 , V_73 ) ;
F_44 ( V_73 ) ;
return V_39 ;
}
static enum V_74
F_45 ( struct V_21 * V_23 , bool V_75 )
{
struct V_22 * V_22 = F_6 ( V_23 ) ;
struct V_11 * V_11 = V_22 -> V_72 ;
if ( ! V_11 )
return V_76 ;
return F_46 ( V_23 , & V_11 -> V_36 , V_22 -> V_41 ) ;
}
static int
F_47 ( struct V_21 * V_23 ,
struct V_77 * V_78 ,
T_3 V_79 )
{
return 0 ;
}
static void
F_48 ( struct V_21 * V_23 )
{
struct V_22 * V_22 = F_6 ( V_23 ) ;
if ( ! F_49 ( V_22 -> V_73 ) )
F_44 ( V_22 -> V_73 ) ;
F_50 ( V_23 ) ;
F_44 ( V_23 ) ;
}
static int F_51 ( struct V_21 * V_23 )
{
return F_41 ( V_23 ) ;
}
static enum V_80
F_52 ( struct V_21 * V_23 ,
struct V_19 * V_81 )
{
int V_82 = F_21 ( V_23 -> V_45 ) -> V_83 ;
if ( V_81 -> clock < 10000 )
return V_84 ;
if ( V_81 -> V_58 & V_85 )
return V_86 ;
if ( V_81 -> clock > V_82 )
return V_87 ;
return V_88 ;
}
static struct V_89 * F_53 ( struct V_21 * V_23 ,
struct V_25 * V_14 )
{
struct V_22 * V_22 = F_6 ( V_23 ) ;
struct V_11 * V_11 = V_22 -> V_72 ;
struct V_51 * V_50 = F_22 ( V_14 -> V_50 ) ;
if ( ! V_11 )
return NULL ;
return & V_11 -> V_90 [ V_50 -> V_55 ] -> V_7 . V_7 ;
}
static struct V_89 * F_54 ( struct V_21 * V_23 )
{
struct V_22 * V_22 = F_6 ( V_23 ) ;
struct V_11 * V_11 = V_22 -> V_72 ;
if ( ! V_11 )
return NULL ;
return & V_11 -> V_90 [ 0 ] -> V_7 . V_7 ;
}
static void F_55 ( struct V_89 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_56 ( V_2 ) ;
F_44 ( V_6 ) ;
}
static bool F_57 ( struct V_22 * V_23 )
{
if ( V_23 -> V_2 && V_23 -> V_7 . V_14 -> V_50 ) {
enum V_55 V_55 ;
if ( ! V_23 -> V_2 -> V_91 ( V_23 -> V_2 , & V_55 ) )
return false ;
return true ;
}
return false ;
}
static void F_58 ( struct V_22 * V_23 )
{
#ifdef F_59
struct V_46 * V_47 = F_21 ( V_23 -> V_7 . V_45 ) ;
if ( V_47 -> V_92 )
F_60 ( & V_47 -> V_92 -> V_93 ,
& V_23 -> V_7 ) ;
#endif
}
static void F_61 ( struct V_22 * V_23 )
{
#ifdef F_59
struct V_46 * V_47 = F_21 ( V_23 -> V_7 . V_45 ) ;
if ( V_47 -> V_92 )
F_62 ( & V_47 -> V_92 -> V_93 ,
& V_23 -> V_7 ) ;
#endif
}
static struct V_21 * F_63 ( struct V_94 * V_95 , struct V_96 * V_41 , const char * V_97 )
{
struct V_11 * V_11 = F_64 ( V_95 , struct V_11 , V_36 ) ;
struct V_8 * V_9 = F_65 ( V_11 ) ;
struct V_44 * V_45 = V_9 -> V_7 . V_7 . V_45 ;
struct V_22 * V_22 ;
struct V_21 * V_23 ;
int V_16 ;
V_22 = F_66 () ;
if ( ! V_22 )
return NULL ;
V_23 = & V_22 -> V_7 ;
F_67 ( V_45 , V_23 , & V_98 , V_99 ) ;
F_68 ( V_23 , & V_100 ) ;
V_22 -> V_91 = F_57 ;
V_22 -> V_72 = V_11 ;
V_22 -> V_41 = V_41 ;
for ( V_16 = V_101 ; V_16 <= V_102 ; V_16 ++ ) {
F_69 ( & V_22 -> V_7 ,
& V_11 -> V_90 [ V_16 ] -> V_7 . V_7 ) ;
}
F_70 ( V_11 , V_23 ) ;
F_71 ( & V_23 -> V_7 , V_45 -> V_103 . V_104 , 0 ) ;
F_71 ( & V_23 -> V_7 , V_45 -> V_103 . V_105 , 0 ) ;
F_72 ( V_23 , V_97 ) ;
return V_23 ;
}
static void F_73 ( struct V_21 * V_23 )
{
struct V_22 * V_22 = F_6 ( V_23 ) ;
struct V_44 * V_45 = V_23 -> V_45 ;
F_74 ( V_45 ) ;
F_58 ( V_22 ) ;
F_75 ( V_45 ) ;
F_76 ( & V_22 -> V_7 ) ;
}
static void F_77 ( struct V_94 * V_95 ,
struct V_21 * V_23 )
{
struct V_22 * V_22 = F_6 ( V_23 ) ;
struct V_44 * V_45 = V_23 -> V_45 ;
F_78 ( V_23 ) ;
F_74 ( V_45 ) ;
F_61 ( V_22 ) ;
V_22 -> V_72 = NULL ;
F_75 ( V_45 ) ;
F_79 ( & V_22 -> V_7 ) ;
F_12 ( L_6 ) ;
}
static void F_80 ( struct V_94 * V_95 )
{
struct V_11 * V_11 = F_64 ( V_95 , struct V_11 , V_36 ) ;
struct V_8 * V_9 = F_65 ( V_11 ) ;
struct V_44 * V_45 = V_9 -> V_7 . V_7 . V_45 ;
F_81 ( V_45 ) ;
}
static struct V_5 *
F_82 ( struct V_8 * V_9 , enum V_55 V_55 )
{
struct V_5 * V_6 ;
struct V_1 * V_1 ;
struct V_44 * V_45 = V_9 -> V_7 . V_7 . V_45 ;
V_6 = F_83 ( sizeof( * V_6 ) , V_106 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_55 = V_55 ;
V_1 = & V_6 -> V_7 ;
V_6 -> V_10 = V_9 ;
F_84 ( V_45 , & V_1 -> V_7 , & V_107 ,
V_108 , L_7 , F_85 ( V_55 ) ) ;
V_1 -> type = V_109 ;
V_1 -> V_110 = 0x7 ;
V_1 -> V_111 = 0 ;
V_1 -> V_112 = F_1 ;
V_1 -> V_113 = F_11 ;
V_1 -> V_42 = F_15 ;
V_1 -> V_114 = F_20 ;
V_1 -> V_115 = F_34 ;
V_1 -> V_91 = F_36 ;
V_1 -> V_116 = F_37 ;
return V_6 ;
}
static bool
F_86 ( struct V_8 * V_9 )
{
int V_16 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
for ( V_16 = V_101 ; V_16 <= V_102 ; V_16 ++ )
V_11 -> V_90 [ V_16 ] = F_82 ( V_9 , V_16 ) ;
return true ;
}
int
F_87 ( struct V_8 * V_9 , int V_117 )
{
struct V_11 * V_11 = & V_9 -> V_12 ;
struct V_44 * V_45 = V_9 -> V_7 . V_7 . V_45 ;
int V_39 ;
V_11 -> V_118 = true ;
V_11 -> V_36 . V_119 = & V_120 ;
F_86 ( V_9 ) ;
V_39 = F_88 ( & V_11 -> V_36 , V_45 -> V_45 , & V_11 -> V_121 , 16 , 3 , V_117 ) ;
if ( V_39 ) {
V_11 -> V_118 = false ;
return V_39 ;
}
return 0 ;
}
void
F_89 ( struct V_8 * V_9 )
{
struct V_11 * V_11 = & V_9 -> V_12 ;
if ( ! V_11 -> V_118 )
return;
F_90 ( & V_11 -> V_36 ) ;
}

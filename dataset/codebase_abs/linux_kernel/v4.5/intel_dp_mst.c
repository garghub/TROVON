static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 . V_6 ;
struct V_8 * V_9 = F_2 ( & V_2 -> V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_15 * V_16 ;
int V_17 , V_18 ;
int V_19 , V_20 ;
const struct V_21 * V_22 = & V_4 -> V_7 . V_22 ;
struct V_23 * V_23 ;
struct V_24 * V_25 , * V_26 = NULL ;
struct V_27 * V_28 ;
int V_29 ;
V_4 -> V_30 = true ;
V_4 -> V_31 = false ;
V_4 -> V_32 = true ;
V_17 = 24 ;
V_19 = F_3 ( V_13 -> V_33 ) ;
V_4 -> V_19 = V_19 ;
V_4 -> V_34 = 24 ;
V_4 -> V_35 = F_4 ( V_13 ) ;
V_16 = V_4 -> V_7 . V_16 ;
F_5 (state, drm_connector, connector_state, i) {
V_25 = F_6 ( V_23 ) ;
if ( V_28 -> V_36 == & V_2 -> V_7 ) {
V_26 = V_25 ;
break;
}
}
if ( ! V_26 ) {
F_7 ( L_1 ) ;
return false ;
}
if ( F_8 ( & V_13 -> V_37 , V_26 -> V_38 ) )
V_4 -> V_39 = true ;
V_29 = F_9 ( V_22 -> V_40 , V_17 ) ;
V_4 -> V_41 = V_29 ;
V_20 = F_10 ( & V_13 -> V_37 , V_29 ) ;
F_11 ( V_17 , V_19 ,
V_22 -> V_40 ,
V_4 -> V_35 ,
& V_4 -> V_42 ) ;
V_4 -> V_42 . V_43 = V_20 ;
if ( F_12 ( V_6 ) || F_13 ( V_6 ) )
F_14 ( V_4 ) ;
return true ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( & V_2 -> V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_5 * V_6 = V_2 -> V_7 . V_6 ;
struct V_44 * V_45 = V_6 -> V_46 ;
struct V_47 * V_48 = V_2 -> V_7 . V_48 ;
struct V_49 * V_49 = F_16 ( V_48 ) ;
int V_50 ;
F_17 ( L_2 , V_13 -> V_51 ) ;
F_18 ( & V_13 -> V_37 , V_9 -> V_38 ) ;
V_50 = F_19 ( & V_13 -> V_37 ) ;
if ( V_50 ) {
F_7 ( L_3 , V_50 ) ;
}
if ( V_49 -> V_52 -> V_39 ) {
F_20 ( V_2 ) ;
F_21 ( V_45 , V_53 ) ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( & V_2 -> V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
F_17 ( L_2 , V_13 -> V_51 ) ;
F_23 ( & V_13 -> V_37 ) ;
F_24 ( & V_13 -> V_37 ) ;
F_25 ( & V_13 -> V_37 , V_9 -> V_38 ) ;
V_13 -> V_51 -- ;
V_9 -> V_38 = NULL ;
if ( V_13 -> V_51 == 0 ) {
V_11 -> V_7 . V_54 ( & V_11 -> V_7 ) ;
F_26 ( V_13 , V_55 ) ;
}
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( & V_2 -> V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_5 * V_6 = V_2 -> V_7 . V_6 ;
struct V_44 * V_45 = V_6 -> V_46 ;
enum V_38 V_38 = V_11 -> V_38 ;
int V_50 ;
T_1 V_56 ;
struct V_24 * V_26 = NULL , * V_25 ;
int V_20 ;
struct V_47 * V_48 = V_2 -> V_7 . V_48 ;
struct V_49 * V_49 = F_16 ( V_48 ) ;
F_28 (dev, connector) {
if ( V_25 -> V_7 . V_16 -> V_36 == & V_2 -> V_7 ) {
V_26 = V_25 ;
break;
}
}
if ( ! V_26 ) {
F_7 ( L_1 ) ;
return;
}
V_26 -> V_2 = V_2 ;
F_17 ( L_2 , V_13 -> V_51 ) ;
V_9 -> V_38 = V_26 -> V_38 ;
if ( V_13 -> V_51 == 0 ) {
F_29 ( V_2 , V_49 -> V_52 ) ;
F_30 ( V_13 , V_49 -> V_52 ) ;
F_31 ( & V_11 -> V_7 ) ;
F_26 ( V_13 , V_57 ) ;
F_32 ( V_13 ) ;
F_33 ( V_13 ) ;
}
V_50 = F_34 ( & V_13 -> V_37 ,
V_9 -> V_38 ,
V_49 -> V_52 -> V_41 , & V_20 ) ;
if ( V_50 == false ) {
F_7 ( L_4 ) ;
return;
}
V_13 -> V_51 ++ ;
V_56 = F_35 ( F_36 ( V_38 ) ) ;
F_37 ( F_36 ( V_38 ) , V_56 ) ;
V_50 = F_19 ( & V_13 -> V_37 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( & V_2 -> V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_5 * V_6 = V_11 -> V_7 . V_7 . V_6 ;
struct V_44 * V_45 = V_6 -> V_46 ;
struct V_49 * V_48 = F_16 ( V_2 -> V_7 . V_48 ) ;
enum V_38 V_38 = V_11 -> V_38 ;
int V_50 ;
F_17 ( L_2 , V_13 -> V_51 ) ;
if ( F_39 ( ( F_35 ( F_36 ( V_38 ) ) & V_58 ) ,
1 ) )
F_7 ( L_5 ) ;
V_50 = F_23 ( & V_13 -> V_37 ) ;
V_50 = F_24 ( & V_13 -> V_37 ) ;
if ( V_48 -> V_52 -> V_39 ) {
F_40 ( L_6 ,
F_41 ( V_48 -> V_59 ) ) ;
F_42 ( V_45 , V_53 ) ;
F_43 ( V_2 ) ;
}
}
static bool F_44 ( struct V_1 * V_2 ,
enum V_59 * V_59 )
{
struct V_8 * V_9 = F_2 ( & V_2 -> V_7 ) ;
* V_59 = V_9 -> V_59 ;
if ( V_9 -> V_38 )
return true ;
return false ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = F_2 ( & V_2 -> V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_49 * V_48 = F_16 ( V_2 -> V_7 . V_48 ) ;
struct V_5 * V_6 = V_2 -> V_7 . V_6 ;
struct V_44 * V_45 = V_6 -> V_46 ;
enum V_60 V_61 = V_4 -> V_61 ;
T_2 V_56 , V_62 = 0 ;
V_4 -> V_32 = true ;
V_4 -> V_39 =
F_46 ( V_45 , V_48 ) ;
V_56 = F_35 ( F_47 ( V_61 ) ) ;
if ( V_56 & V_63 )
V_62 |= V_64 ;
else
V_62 |= V_65 ;
if ( V_56 & V_66 )
V_62 |= V_67 ;
else
V_62 |= V_68 ;
switch ( V_56 & V_69 ) {
case V_70 :
V_4 -> V_34 = 18 ;
break;
case V_71 :
V_4 -> V_34 = 24 ;
break;
case V_72 :
V_4 -> V_34 = 30 ;
break;
case V_73 :
V_4 -> V_34 = 36 ;
break;
default:
break;
}
V_4 -> V_7 . V_22 . V_62 |= V_62 ;
V_4 -> V_19 =
( ( V_56 & V_74 ) >> V_75 ) + 1 ;
F_48 ( V_48 , V_4 ) ;
F_49 ( & V_11 -> V_7 , V_4 ) ;
}
static int F_50 ( struct V_23 * V_25 )
{
struct V_24 * V_24 = F_6 ( V_25 ) ;
struct V_13 * V_13 = V_24 -> V_76 ;
struct V_77 * V_77 ;
int V_50 ;
V_77 = F_51 ( V_25 , & V_13 -> V_37 , V_24 -> V_38 ) ;
if ( ! V_77 )
return 0 ;
V_50 = F_52 ( V_25 , V_77 ) ;
F_53 ( V_77 ) ;
return V_50 ;
}
static enum V_78
F_54 ( struct V_23 * V_25 , bool V_79 )
{
struct V_24 * V_24 = F_6 ( V_25 ) ;
struct V_13 * V_13 = V_24 -> V_76 ;
return F_55 ( V_25 , & V_13 -> V_37 , V_24 -> V_38 ) ;
}
static int
F_56 ( struct V_23 * V_25 ,
struct V_80 * V_81 ,
T_3 V_82 )
{
return 0 ;
}
static void
F_57 ( struct V_23 * V_25 )
{
struct V_24 * V_24 = F_6 ( V_25 ) ;
if ( ! F_58 ( V_24 -> V_77 ) )
F_53 ( V_24 -> V_77 ) ;
F_59 ( V_25 ) ;
F_53 ( V_25 ) ;
}
static int F_60 ( struct V_23 * V_25 )
{
return F_50 ( V_25 ) ;
}
static enum V_83
F_61 ( struct V_23 * V_25 ,
struct V_21 * V_84 )
{
if ( V_84 -> clock < 10000 )
return V_85 ;
if ( V_84 -> V_62 & V_86 )
return V_87 ;
return V_88 ;
}
static struct V_89 * F_62 ( struct V_23 * V_25 ,
struct V_27 * V_16 )
{
struct V_24 * V_24 = F_6 ( V_25 ) ;
struct V_13 * V_13 = V_24 -> V_76 ;
struct V_49 * V_48 = F_16 ( V_16 -> V_48 ) ;
return & V_13 -> V_90 [ V_48 -> V_59 ] -> V_7 . V_7 ;
}
static struct V_89 * F_63 ( struct V_23 * V_25 )
{
struct V_24 * V_24 = F_6 ( V_25 ) ;
struct V_13 * V_13 = V_24 -> V_76 ;
return & V_13 -> V_90 [ 0 ] -> V_7 . V_7 ;
}
static void F_64 ( struct V_89 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_65 ( V_2 ) ;
F_53 ( V_9 ) ;
}
static bool F_66 ( struct V_24 * V_25 )
{
if ( V_25 -> V_2 && V_25 -> V_7 . V_16 -> V_48 ) {
enum V_59 V_59 ;
if ( ! V_25 -> V_2 -> V_91 ( V_25 -> V_2 , & V_59 ) )
return false ;
return true ;
}
return false ;
}
static void F_67 ( struct V_24 * V_25 )
{
#ifdef F_68
struct V_44 * V_45 = F_69 ( V_25 -> V_7 . V_6 ) ;
if ( V_45 -> V_92 )
F_70 ( & V_45 -> V_92 -> V_93 ,
& V_25 -> V_7 ) ;
#endif
}
static void F_71 ( struct V_24 * V_25 )
{
#ifdef F_68
struct V_44 * V_45 = F_69 ( V_25 -> V_7 . V_6 ) ;
if ( V_45 -> V_92 )
F_72 ( & V_45 -> V_92 -> V_93 ,
& V_25 -> V_7 ) ;
#endif
}
static struct V_23 * F_73 ( struct V_94 * V_95 , struct V_96 * V_38 , const char * V_97 )
{
struct V_13 * V_13 = F_74 ( V_95 , struct V_13 , V_37 ) ;
struct V_10 * V_11 = F_75 ( V_13 ) ;
struct V_5 * V_6 = V_11 -> V_7 . V_7 . V_6 ;
struct V_24 * V_24 ;
struct V_23 * V_25 ;
int V_18 ;
V_24 = F_76 () ;
if ( ! V_24 )
return NULL ;
V_25 = & V_24 -> V_7 ;
F_77 ( V_6 , V_25 , & V_98 , V_99 ) ;
F_78 ( V_25 , & V_100 ) ;
V_24 -> V_101 = V_102 ;
V_24 -> V_91 = F_66 ;
V_24 -> V_76 = V_13 ;
V_24 -> V_38 = V_38 ;
for ( V_18 = V_103 ; V_18 <= V_104 ; V_18 ++ ) {
F_79 ( & V_24 -> V_7 ,
& V_13 -> V_90 [ V_18 ] -> V_7 . V_7 ) ;
}
F_80 ( V_13 , V_25 ) ;
F_81 ( & V_25 -> V_7 , V_6 -> V_105 . V_106 , 0 ) ;
F_81 ( & V_25 -> V_7 , V_6 -> V_105 . V_107 , 0 ) ;
F_82 ( V_25 , V_97 ) ;
return V_25 ;
}
static void F_83 ( struct V_23 * V_25 )
{
struct V_24 * V_24 = F_6 ( V_25 ) ;
struct V_5 * V_6 = V_25 -> V_6 ;
F_84 ( V_6 ) ;
F_67 ( V_24 ) ;
F_85 ( V_6 ) ;
F_86 ( & V_24 -> V_7 ) ;
}
static void F_87 ( struct V_94 * V_95 ,
struct V_23 * V_25 )
{
struct V_24 * V_24 = F_6 ( V_25 ) ;
struct V_5 * V_6 = V_25 -> V_6 ;
F_84 ( V_6 ) ;
if ( V_25 -> V_16 -> V_48 ) {
struct V_108 V_109 ;
int V_50 ;
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
V_109 . V_48 = V_25 -> V_16 -> V_48 ,
V_50 = F_88 ( & V_109 ) ;
F_89 ( V_50 , L_7 , V_50 ) ;
}
F_85 ( V_6 ) ;
V_24 -> V_101 ( V_24 ) ;
F_84 ( V_6 ) ;
F_71 ( V_24 ) ;
F_59 ( V_25 ) ;
F_85 ( V_6 ) ;
F_53 ( V_24 ) ;
F_17 ( L_8 ) ;
}
static void F_90 ( struct V_94 * V_95 )
{
struct V_13 * V_13 = F_74 ( V_95 , struct V_13 , V_37 ) ;
struct V_10 * V_11 = F_75 ( V_13 ) ;
struct V_5 * V_6 = V_11 -> V_7 . V_7 . V_6 ;
F_91 ( V_6 ) ;
}
static struct V_8 *
F_92 ( struct V_10 * V_11 , enum V_59 V_59 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 ;
struct V_5 * V_6 = V_11 -> V_7 . V_7 . V_6 ;
V_9 = F_93 ( sizeof( * V_9 ) , V_110 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_59 = V_59 ;
V_1 = & V_9 -> V_7 ;
V_9 -> V_12 = V_11 ;
F_94 ( V_6 , & V_1 -> V_7 , & V_111 ,
V_112 , NULL ) ;
V_1 -> type = V_113 ;
V_1 -> V_114 = 0x7 ;
V_1 -> V_115 = 0 ;
V_1 -> V_116 = F_1 ;
V_1 -> V_117 = F_15 ;
V_1 -> V_54 = F_22 ;
V_1 -> V_118 = F_27 ;
V_1 -> V_119 = F_38 ;
V_1 -> V_91 = F_44 ;
V_1 -> V_120 = F_45 ;
return V_9 ;
}
static bool
F_95 ( struct V_10 * V_11 )
{
int V_18 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
for ( V_18 = V_103 ; V_18 <= V_104 ; V_18 ++ )
V_13 -> V_90 [ V_18 ] = F_92 ( V_11 , V_18 ) ;
return true ;
}
int
F_96 ( struct V_10 * V_11 , int V_121 )
{
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_5 * V_6 = V_11 -> V_7 . V_7 . V_6 ;
int V_50 ;
V_13 -> V_122 = true ;
V_13 -> V_37 . V_123 = & V_124 ;
F_95 ( V_11 ) ;
V_50 = F_97 ( & V_13 -> V_37 , V_6 -> V_6 , & V_13 -> V_125 , 16 , 3 , V_121 ) ;
if ( V_50 ) {
V_13 -> V_122 = false ;
return V_50 ;
}
return 0 ;
}
void
F_98 ( struct V_10 * V_11 )
{
struct V_13 * V_13 = & V_11 -> V_14 ;
if ( ! V_13 -> V_122 )
return;
F_99 ( & V_13 -> V_37 ) ;
}

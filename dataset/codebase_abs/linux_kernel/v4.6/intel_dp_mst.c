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
V_29 = F_8 ( V_22 -> V_37 , V_17 ) ;
V_4 -> V_38 = V_29 ;
V_20 = F_9 ( & V_13 -> V_39 , V_29 ) ;
F_10 ( V_17 , V_19 ,
V_22 -> V_37 ,
V_4 -> V_35 ,
& V_4 -> V_40 ) ;
V_4 -> V_40 . V_41 = V_20 ;
if ( F_11 ( V_6 ) || F_12 ( V_6 ) )
F_13 ( V_4 ) ;
return true ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( & V_2 -> V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
int V_42 ;
F_15 ( L_2 , V_13 -> V_43 ) ;
F_16 ( & V_13 -> V_39 , V_9 -> V_44 ) ;
V_42 = F_17 ( & V_13 -> V_39 ) ;
if ( V_42 ) {
F_7 ( L_3 , V_42 ) ;
}
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( & V_2 -> V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
F_15 ( L_2 , V_13 -> V_43 ) ;
F_19 ( & V_13 -> V_39 ) ;
F_20 ( & V_13 -> V_39 ) ;
F_21 ( & V_13 -> V_39 , V_9 -> V_44 ) ;
V_13 -> V_43 -- ;
V_9 -> V_44 = NULL ;
if ( V_13 -> V_43 == 0 ) {
V_11 -> V_7 . V_45 ( & V_11 -> V_7 ) ;
F_22 ( V_13 , V_46 ) ;
}
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( & V_2 -> V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_5 * V_6 = V_2 -> V_7 . V_6 ;
struct V_47 * V_48 = V_6 -> V_49 ;
enum V_44 V_44 = V_11 -> V_44 ;
int V_42 ;
T_1 V_50 ;
struct V_24 * V_26 = NULL , * V_25 ;
int V_20 ;
struct V_51 * V_52 = V_2 -> V_7 . V_52 ;
struct V_53 * V_53 = F_24 ( V_52 ) ;
F_25 (dev, connector) {
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
F_15 ( L_2 , V_13 -> V_43 ) ;
V_9 -> V_44 = V_26 -> V_44 ;
if ( V_13 -> V_43 == 0 ) {
F_26 ( & V_11 -> V_7 ) ;
F_27 ( & V_11 -> V_7 , V_53 -> V_54 ) ;
F_28 ( V_13 , V_53 -> V_54 ) ;
F_29 ( & V_11 -> V_7 ) ;
F_22 ( V_13 , V_55 ) ;
F_30 ( V_13 ) ;
F_31 ( V_13 ) ;
}
V_42 = F_32 ( & V_13 -> V_39 ,
V_9 -> V_44 ,
V_53 -> V_54 -> V_38 , & V_20 ) ;
if ( V_42 == false ) {
F_7 ( L_4 ) ;
return;
}
V_13 -> V_43 ++ ;
V_50 = F_33 ( F_34 ( V_44 ) ) ;
F_35 ( F_34 ( V_44 ) , V_50 ) ;
V_42 = F_17 ( & V_13 -> V_39 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( & V_2 -> V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_5 * V_6 = V_11 -> V_7 . V_7 . V_6 ;
struct V_47 * V_48 = V_6 -> V_49 ;
enum V_44 V_44 = V_11 -> V_44 ;
int V_42 ;
F_15 ( L_2 , V_13 -> V_43 ) ;
if ( F_37 ( ( F_33 ( F_34 ( V_44 ) ) & V_56 ) ,
1 ) )
F_7 ( L_5 ) ;
V_42 = F_19 ( & V_13 -> V_39 ) ;
V_42 = F_20 ( & V_13 -> V_39 ) ;
}
static bool F_38 ( struct V_1 * V_2 ,
enum V_57 * V_57 )
{
struct V_8 * V_9 = F_2 ( & V_2 -> V_7 ) ;
* V_57 = V_9 -> V_57 ;
if ( V_9 -> V_44 )
return true ;
return false ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = F_2 ( & V_2 -> V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_53 * V_52 = F_24 ( V_2 -> V_7 . V_52 ) ;
struct V_5 * V_6 = V_2 -> V_7 . V_6 ;
struct V_47 * V_48 = V_6 -> V_49 ;
enum V_58 V_59 = V_4 -> V_59 ;
T_2 V_50 , V_60 = 0 ;
V_4 -> V_32 = true ;
V_50 = F_33 ( F_40 ( V_59 ) ) ;
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
V_4 -> V_34 = 18 ;
break;
case V_69 :
V_4 -> V_34 = 24 ;
break;
case V_70 :
V_4 -> V_34 = 30 ;
break;
case V_71 :
V_4 -> V_34 = 36 ;
break;
default:
break;
}
V_4 -> V_7 . V_22 . V_60 |= V_60 ;
V_4 -> V_19 =
( ( V_50 & V_72 ) >> V_73 ) + 1 ;
F_41 ( V_52 , V_4 ) ;
F_42 ( & V_11 -> V_7 , V_4 ) ;
}
static int F_43 ( struct V_23 * V_25 )
{
struct V_24 * V_24 = F_6 ( V_25 ) ;
struct V_13 * V_13 = V_24 -> V_74 ;
struct V_75 * V_75 ;
int V_42 ;
V_75 = F_44 ( V_25 , & V_13 -> V_39 , V_24 -> V_44 ) ;
if ( ! V_75 )
return 0 ;
V_42 = F_45 ( V_25 , V_75 ) ;
F_46 ( V_75 ) ;
return V_42 ;
}
static enum V_76
F_47 ( struct V_23 * V_25 , bool V_77 )
{
struct V_24 * V_24 = F_6 ( V_25 ) ;
struct V_13 * V_13 = V_24 -> V_74 ;
return F_48 ( V_25 , & V_13 -> V_39 , V_24 -> V_44 ) ;
}
static int
F_49 ( struct V_23 * V_25 ,
struct V_78 * V_79 ,
T_3 V_80 )
{
return 0 ;
}
static void
F_50 ( struct V_23 * V_25 )
{
struct V_24 * V_24 = F_6 ( V_25 ) ;
if ( ! F_51 ( V_24 -> V_75 ) )
F_46 ( V_24 -> V_75 ) ;
F_52 ( V_25 ) ;
F_46 ( V_25 ) ;
}
static int F_53 ( struct V_23 * V_25 )
{
return F_43 ( V_25 ) ;
}
static enum V_81
F_54 ( struct V_23 * V_25 ,
struct V_21 * V_82 )
{
int V_83 = F_55 ( V_25 -> V_6 ) -> V_84 ;
if ( V_82 -> clock < 10000 )
return V_85 ;
if ( V_82 -> V_60 & V_86 )
return V_87 ;
if ( V_82 -> clock > V_83 )
return V_88 ;
return V_89 ;
}
static struct V_90 * F_56 ( struct V_23 * V_25 ,
struct V_27 * V_16 )
{
struct V_24 * V_24 = F_6 ( V_25 ) ;
struct V_13 * V_13 = V_24 -> V_74 ;
struct V_53 * V_52 = F_24 ( V_16 -> V_52 ) ;
return & V_13 -> V_91 [ V_52 -> V_57 ] -> V_7 . V_7 ;
}
static struct V_90 * F_57 ( struct V_23 * V_25 )
{
struct V_24 * V_24 = F_6 ( V_25 ) ;
struct V_13 * V_13 = V_24 -> V_74 ;
return & V_13 -> V_91 [ 0 ] -> V_7 . V_7 ;
}
static void F_58 ( struct V_90 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_59 ( V_2 ) ;
F_46 ( V_9 ) ;
}
static bool F_60 ( struct V_24 * V_25 )
{
if ( V_25 -> V_2 && V_25 -> V_7 . V_16 -> V_52 ) {
enum V_57 V_57 ;
if ( ! V_25 -> V_2 -> V_92 ( V_25 -> V_2 , & V_57 ) )
return false ;
return true ;
}
return false ;
}
static void F_61 ( struct V_24 * V_25 )
{
#ifdef F_62
struct V_47 * V_48 = F_55 ( V_25 -> V_7 . V_6 ) ;
if ( V_48 -> V_93 )
F_63 ( & V_48 -> V_93 -> V_94 ,
& V_25 -> V_7 ) ;
#endif
}
static void F_64 ( struct V_24 * V_25 )
{
#ifdef F_62
struct V_47 * V_48 = F_55 ( V_25 -> V_7 . V_6 ) ;
if ( V_48 -> V_93 )
F_65 ( & V_48 -> V_93 -> V_94 ,
& V_25 -> V_7 ) ;
#endif
}
static struct V_23 * F_66 ( struct V_95 * V_96 , struct V_97 * V_44 , const char * V_98 )
{
struct V_13 * V_13 = F_67 ( V_96 , struct V_13 , V_39 ) ;
struct V_10 * V_11 = F_68 ( V_13 ) ;
struct V_5 * V_6 = V_11 -> V_7 . V_7 . V_6 ;
struct V_24 * V_24 ;
struct V_23 * V_25 ;
int V_18 ;
V_24 = F_69 () ;
if ( ! V_24 )
return NULL ;
V_25 = & V_24 -> V_7 ;
F_70 ( V_6 , V_25 , & V_99 , V_100 ) ;
F_71 ( V_25 , & V_101 ) ;
V_24 -> V_102 = V_103 ;
V_24 -> V_92 = F_60 ;
V_24 -> V_74 = V_13 ;
V_24 -> V_44 = V_44 ;
for ( V_18 = V_104 ; V_18 <= V_105 ; V_18 ++ ) {
F_72 ( & V_24 -> V_7 ,
& V_13 -> V_91 [ V_18 ] -> V_7 . V_7 ) ;
}
F_73 ( V_13 , V_25 ) ;
F_74 ( & V_25 -> V_7 , V_6 -> V_106 . V_107 , 0 ) ;
F_74 ( & V_25 -> V_7 , V_6 -> V_106 . V_108 , 0 ) ;
F_75 ( V_25 , V_98 ) ;
return V_25 ;
}
static void F_76 ( struct V_23 * V_25 )
{
struct V_24 * V_24 = F_6 ( V_25 ) ;
struct V_5 * V_6 = V_25 -> V_6 ;
F_77 ( V_6 ) ;
F_61 ( V_24 ) ;
F_78 ( V_6 ) ;
F_79 ( & V_24 -> V_7 ) ;
}
static void F_80 ( struct V_95 * V_96 ,
struct V_23 * V_25 )
{
struct V_24 * V_24 = F_6 ( V_25 ) ;
struct V_5 * V_6 = V_25 -> V_6 ;
V_24 -> V_102 ( V_24 ) ;
F_77 ( V_6 ) ;
if ( V_25 -> V_16 -> V_52 ) {
struct V_109 V_110 ;
int V_42 ;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
V_110 . V_52 = V_25 -> V_16 -> V_52 ,
V_42 = F_81 ( & V_110 ) ;
F_82 ( V_42 , L_6 , V_42 ) ;
}
F_64 ( V_24 ) ;
F_52 ( V_25 ) ;
F_78 ( V_6 ) ;
F_46 ( V_24 ) ;
F_15 ( L_7 ) ;
}
static void F_83 ( struct V_95 * V_96 )
{
struct V_13 * V_13 = F_67 ( V_96 , struct V_13 , V_39 ) ;
struct V_10 * V_11 = F_68 ( V_13 ) ;
struct V_5 * V_6 = V_11 -> V_7 . V_7 . V_6 ;
F_84 ( V_6 ) ;
}
static struct V_8 *
F_85 ( struct V_10 * V_11 , enum V_57 V_57 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 ;
struct V_5 * V_6 = V_11 -> V_7 . V_7 . V_6 ;
V_9 = F_86 ( sizeof( * V_9 ) , V_111 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_57 = V_57 ;
V_1 = & V_9 -> V_7 ;
V_9 -> V_12 = V_11 ;
F_87 ( V_6 , & V_1 -> V_7 , & V_112 ,
V_113 , NULL ) ;
V_1 -> type = V_114 ;
V_1 -> V_115 = 0x7 ;
V_1 -> V_116 = 0 ;
V_1 -> V_117 = F_1 ;
V_1 -> V_118 = F_14 ;
V_1 -> V_45 = F_18 ;
V_1 -> V_119 = F_23 ;
V_1 -> V_120 = F_36 ;
V_1 -> V_92 = F_38 ;
V_1 -> V_121 = F_39 ;
return V_9 ;
}
static bool
F_88 ( struct V_10 * V_11 )
{
int V_18 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
for ( V_18 = V_104 ; V_18 <= V_105 ; V_18 ++ )
V_13 -> V_91 [ V_18 ] = F_85 ( V_11 , V_18 ) ;
return true ;
}
int
F_89 ( struct V_10 * V_11 , int V_122 )
{
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_5 * V_6 = V_11 -> V_7 . V_7 . V_6 ;
int V_42 ;
V_13 -> V_123 = true ;
V_13 -> V_39 . V_124 = & V_125 ;
F_88 ( V_11 ) ;
V_42 = F_90 ( & V_13 -> V_39 , V_6 -> V_6 , & V_13 -> V_126 , 16 , 3 , V_122 ) ;
if ( V_42 ) {
V_13 -> V_123 = false ;
return V_42 ;
}
return 0 ;
}
void
F_91 ( struct V_10 * V_11 )
{
struct V_13 * V_13 = & V_11 -> V_14 ;
if ( ! V_13 -> V_123 )
return;
F_92 ( & V_13 -> V_39 ) ;
}

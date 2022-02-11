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
struct V_22 * V_22 ;
struct V_23 * V_24 , * V_25 = NULL ;
struct V_26 * V_27 ;
int V_28 ;
V_4 -> V_29 = true ;
V_4 -> V_30 = false ;
V_4 -> V_31 = true ;
V_15 = 24 ;
V_17 = F_3 ( V_11 -> V_32 ) ;
V_19 = F_4 ( V_11 ) ;
if ( V_11 -> V_33 ) {
V_11 -> V_34 = 0 ;
V_11 -> V_35 = F_5 ( V_11 , V_19 ) ;
} else {
V_11 -> V_34 = F_6 ( V_19 ) ;
V_11 -> V_35 = 0 ;
}
V_11 -> V_17 = V_17 ;
V_4 -> V_36 = 24 ;
V_4 -> V_37 = V_19 ;
V_14 = V_4 -> V_7 . V_14 ;
F_7 (state, drm_connector, connector_state, i) {
V_24 = F_8 ( V_22 ) ;
if ( V_27 -> V_38 == & V_2 -> V_7 ) {
V_25 = V_24 ;
break;
}
}
if ( ! V_25 ) {
F_9 ( L_1 ) ;
return false ;
}
V_28 = F_10 ( V_21 -> clock , V_15 ) ;
V_4 -> V_39 = V_28 ;
V_18 = F_11 ( & V_11 -> V_40 , V_28 ) ;
F_12 ( V_15 , V_17 ,
V_21 -> V_41 ,
V_4 -> V_37 ,
& V_4 -> V_42 ) ;
V_4 -> V_42 . V_43 = V_18 ;
return true ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
int V_44 ;
F_14 ( L_2 , V_11 -> V_45 ) ;
F_15 ( & V_11 -> V_40 , V_6 -> V_46 ) ;
V_44 = F_16 ( & V_11 -> V_40 ) ;
if ( V_44 ) {
F_9 ( L_3 , V_44 ) ;
}
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
F_14 ( L_2 , V_11 -> V_45 ) ;
F_18 ( & V_11 -> V_40 ) ;
F_19 ( & V_11 -> V_40 ) ;
F_20 ( & V_11 -> V_40 , V_6 -> V_46 ) ;
V_11 -> V_45 -- ;
V_6 -> V_46 = NULL ;
if ( V_11 -> V_45 == 0 ) {
V_9 -> V_7 . V_47 ( & V_9 -> V_7 ) ;
F_21 ( V_11 , V_48 ) ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
struct V_49 * V_50 = V_2 -> V_7 . V_50 ;
struct V_51 * V_52 = V_50 -> V_53 ;
enum V_46 V_46 = V_9 -> V_46 ;
int V_44 ;
T_1 V_54 ;
struct V_23 * V_25 = NULL , * V_24 ;
int V_18 ;
struct V_55 * V_56 = V_2 -> V_7 . V_56 ;
struct V_57 * V_57 = F_23 ( V_56 ) ;
F_24 (dev, connector) {
if ( V_24 -> V_7 . V_14 -> V_38 == & V_2 -> V_7 ) {
V_25 = V_24 ;
break;
}
}
if ( ! V_25 ) {
F_9 ( L_1 ) ;
return;
}
F_14 ( L_2 , V_11 -> V_45 ) ;
V_6 -> V_46 = V_25 -> V_46 ;
if ( V_11 -> V_45 == 0 ) {
enum V_46 V_46 = F_25 ( V_2 ) ;
if ( F_26 ( V_50 ) -> V_58 < 9 )
F_27 ( F_28 ( V_46 ) ,
V_57 -> V_59 -> V_60 ) ;
F_29 ( & V_9 -> V_7 ) ;
F_21 ( V_11 , V_61 ) ;
F_30 ( V_11 ) ;
F_31 ( V_11 ) ;
F_32 ( V_11 ) ;
}
V_44 = F_33 ( & V_11 -> V_40 ,
V_6 -> V_46 ,
V_57 -> V_59 -> V_39 , & V_18 ) ;
if ( V_44 == false ) {
F_9 ( L_4 ) ;
return;
}
V_11 -> V_45 ++ ;
V_54 = F_34 ( F_35 ( V_46 ) ) ;
F_27 ( F_35 ( V_46 ) , V_54 ) ;
V_44 = F_16 ( & V_11 -> V_40 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
struct V_49 * V_50 = V_9 -> V_7 . V_7 . V_50 ;
struct V_51 * V_52 = V_50 -> V_53 ;
enum V_46 V_46 = V_9 -> V_46 ;
int V_44 ;
F_14 ( L_2 , V_11 -> V_45 ) ;
if ( F_37 ( ( F_34 ( F_35 ( V_46 ) ) & V_62 ) ,
1 ) )
F_9 ( L_5 ) ;
V_44 = F_18 ( & V_11 -> V_40 ) ;
V_44 = F_19 ( & V_11 -> V_40 ) ;
}
static bool F_38 ( struct V_1 * V_2 ,
enum V_63 * V_63 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
* V_63 = V_6 -> V_63 ;
if ( V_6 -> V_46 )
return true ;
return false ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_57 * V_56 = F_23 ( V_2 -> V_7 . V_56 ) ;
struct V_49 * V_50 = V_2 -> V_7 . V_50 ;
struct V_51 * V_52 = V_50 -> V_53 ;
enum V_64 V_65 = V_4 -> V_65 ;
T_2 V_54 , V_66 = 0 ;
V_4 -> V_31 = true ;
V_54 = F_34 ( F_40 ( V_65 ) ) ;
if ( V_54 & V_67 )
V_66 |= V_68 ;
else
V_66 |= V_69 ;
if ( V_54 & V_70 )
V_66 |= V_71 ;
else
V_66 |= V_72 ;
switch ( V_54 & V_73 ) {
case V_74 :
V_4 -> V_36 = 18 ;
break;
case V_75 :
V_4 -> V_36 = 24 ;
break;
case V_76 :
V_4 -> V_36 = 30 ;
break;
case V_77 :
V_4 -> V_36 = 36 ;
break;
default:
break;
}
V_4 -> V_7 . V_21 . V_66 |= V_66 ;
F_41 ( V_56 , V_4 ) ;
F_42 ( & V_9 -> V_7 , V_4 ) ;
}
static int F_43 ( struct V_22 * V_24 )
{
struct V_23 * V_23 = F_8 ( V_24 ) ;
struct V_11 * V_11 = V_23 -> V_78 ;
struct V_79 * V_79 ;
int V_44 ;
V_79 = F_44 ( V_24 , & V_11 -> V_40 , V_23 -> V_46 ) ;
if ( ! V_79 )
return 0 ;
V_44 = F_45 ( V_24 , V_79 ) ;
F_46 ( V_79 ) ;
return V_44 ;
}
static enum V_80
F_47 ( struct V_22 * V_24 , bool V_81 )
{
struct V_23 * V_23 = F_8 ( V_24 ) ;
struct V_11 * V_11 = V_23 -> V_78 ;
return F_48 ( V_24 , & V_11 -> V_40 , V_23 -> V_46 ) ;
}
static int
F_49 ( struct V_22 * V_24 ,
struct V_82 * V_83 ,
T_3 V_84 )
{
return 0 ;
}
static void
F_50 ( struct V_22 * V_24 )
{
struct V_23 * V_23 = F_8 ( V_24 ) ;
if ( ! F_51 ( V_23 -> V_79 ) )
F_46 ( V_23 -> V_79 ) ;
F_52 ( V_24 ) ;
F_46 ( V_24 ) ;
}
static int F_53 ( struct V_22 * V_24 )
{
return F_43 ( V_24 ) ;
}
static enum V_85
F_54 ( struct V_22 * V_24 ,
struct V_20 * V_86 )
{
if ( V_86 -> clock < 10000 )
return V_87 ;
if ( V_86 -> V_66 & V_88 )
return V_89 ;
return V_90 ;
}
static struct V_91 * F_55 ( struct V_22 * V_24 ,
struct V_26 * V_14 )
{
struct V_23 * V_23 = F_8 ( V_24 ) ;
struct V_11 * V_11 = V_23 -> V_78 ;
struct V_57 * V_56 = F_23 ( V_14 -> V_56 ) ;
return & V_11 -> V_92 [ V_56 -> V_63 ] -> V_7 . V_7 ;
}
static struct V_91 * F_56 ( struct V_22 * V_24 )
{
struct V_23 * V_23 = F_8 ( V_24 ) ;
struct V_11 * V_11 = V_23 -> V_78 ;
return & V_11 -> V_92 [ 0 ] -> V_7 . V_7 ;
}
static void F_57 ( struct V_91 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_58 ( V_2 ) ;
F_46 ( V_6 ) ;
}
static bool F_59 ( struct V_23 * V_24 )
{
if ( V_24 -> V_2 ) {
enum V_63 V_63 ;
if ( ! V_24 -> V_2 -> V_93 ( V_24 -> V_2 , & V_63 ) )
return false ;
return true ;
}
return false ;
}
static void F_60 ( struct V_23 * V_24 )
{
#ifdef F_61
struct V_51 * V_52 = F_62 ( V_24 -> V_7 . V_50 ) ;
F_63 ( & V_52 -> V_94 -> V_95 , & V_24 -> V_7 ) ;
#endif
}
static void F_64 ( struct V_23 * V_24 )
{
#ifdef F_61
struct V_51 * V_52 = F_62 ( V_24 -> V_7 . V_50 ) ;
F_65 ( & V_52 -> V_94 -> V_95 , & V_24 -> V_7 ) ;
#endif
}
static struct V_22 * F_66 ( struct V_96 * V_97 , struct V_98 * V_46 , const char * V_99 )
{
struct V_11 * V_11 = F_67 ( V_97 , struct V_11 , V_40 ) ;
struct V_8 * V_9 = F_68 ( V_11 ) ;
struct V_49 * V_50 = V_9 -> V_7 . V_7 . V_50 ;
struct V_23 * V_23 ;
struct V_22 * V_24 ;
int V_16 ;
V_23 = F_69 () ;
if ( ! V_23 )
return NULL ;
V_24 = & V_23 -> V_7 ;
F_70 ( V_50 , V_24 , & V_100 , V_101 ) ;
F_71 ( V_24 , & V_102 ) ;
V_23 -> V_103 = V_104 ;
V_23 -> V_93 = F_59 ;
V_23 -> V_78 = V_11 ;
V_23 -> V_46 = V_46 ;
for ( V_16 = V_105 ; V_16 <= V_106 ; V_16 ++ ) {
F_72 ( & V_23 -> V_7 ,
& V_11 -> V_92 [ V_16 ] -> V_7 . V_7 ) ;
}
F_73 ( V_11 , V_24 ) ;
F_74 ( & V_24 -> V_7 , V_50 -> V_107 . V_108 , 0 ) ;
F_74 ( & V_24 -> V_7 , V_50 -> V_107 . V_109 , 0 ) ;
F_75 ( V_24 , V_99 ) ;
F_76 ( V_50 ) ;
F_77 ( & V_50 -> V_107 . V_110 ) ;
F_60 ( V_23 ) ;
F_78 ( & V_50 -> V_107 . V_110 ) ;
F_79 ( & V_23 -> V_7 ) ;
return V_24 ;
}
static void F_80 ( struct V_96 * V_97 ,
struct V_22 * V_24 )
{
struct V_23 * V_23 = F_8 ( V_24 ) ;
struct V_49 * V_50 = V_24 -> V_50 ;
F_77 ( & V_50 -> V_107 . V_110 ) ;
F_81 ( V_24 , V_48 ) ;
F_78 ( & V_50 -> V_107 . V_110 ) ;
V_23 -> V_103 ( V_23 ) ;
F_77 ( & V_50 -> V_107 . V_110 ) ;
F_64 ( V_23 ) ;
F_52 ( V_24 ) ;
F_78 ( & V_50 -> V_107 . V_110 ) ;
F_76 ( V_50 ) ;
F_46 ( V_23 ) ;
F_14 ( L_6 ) ;
}
static void F_82 ( struct V_96 * V_97 )
{
struct V_11 * V_11 = F_67 ( V_97 , struct V_11 , V_40 ) ;
struct V_8 * V_9 = F_68 ( V_11 ) ;
struct V_49 * V_50 = V_9 -> V_7 . V_7 . V_50 ;
F_83 ( V_50 ) ;
}
static struct V_5 *
F_84 ( struct V_8 * V_9 , enum V_63 V_63 )
{
struct V_5 * V_6 ;
struct V_1 * V_1 ;
struct V_49 * V_50 = V_9 -> V_7 . V_7 . V_50 ;
V_6 = F_85 ( sizeof( * V_6 ) , V_111 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_63 = V_63 ;
V_1 = & V_6 -> V_7 ;
V_6 -> V_10 = V_9 ;
F_86 ( V_50 , & V_1 -> V_7 , & V_112 ,
V_113 ) ;
V_1 -> type = V_114 ;
V_1 -> V_115 = 0x7 ;
V_1 -> V_116 = 0 ;
V_1 -> V_117 = F_1 ;
V_1 -> V_118 = F_13 ;
V_1 -> V_47 = F_17 ;
V_1 -> V_119 = F_22 ;
V_1 -> V_120 = F_36 ;
V_1 -> V_93 = F_38 ;
V_1 -> V_121 = F_39 ;
return V_6 ;
}
static bool
F_87 ( struct V_8 * V_9 )
{
int V_16 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
for ( V_16 = V_105 ; V_16 <= V_106 ; V_16 ++ )
V_11 -> V_92 [ V_16 ] = F_84 ( V_9 , V_16 ) ;
return true ;
}
int
F_88 ( struct V_8 * V_9 , int V_122 )
{
struct V_11 * V_11 = & V_9 -> V_12 ;
struct V_49 * V_50 = V_9 -> V_7 . V_7 . V_50 ;
int V_44 ;
V_11 -> V_123 = true ;
V_11 -> V_40 . V_124 = & V_125 ;
F_87 ( V_9 ) ;
V_44 = F_89 ( & V_11 -> V_40 , V_50 -> V_50 , & V_11 -> V_126 , 16 , 3 , V_122 ) ;
if ( V_44 ) {
V_11 -> V_123 = false ;
return V_44 ;
}
return 0 ;
}
void
F_90 ( struct V_8 * V_9 )
{
struct V_11 * V_11 = & V_9 -> V_12 ;
if ( ! V_11 -> V_123 )
return;
F_91 ( & V_11 -> V_40 ) ;
}

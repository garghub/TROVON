static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 . V_6 ;
struct V_8 * V_9 = F_2 ( & V_2 -> V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_15 * V_16 ;
int V_17 , V_18 ;
int V_19 , V_20 , V_21 ;
struct V_22 * V_23 = & V_4 -> V_7 . V_23 ;
struct V_24 * V_24 ;
struct V_25 * V_26 , * V_27 = NULL ;
struct V_28 * V_29 ;
int V_30 ;
V_4 -> V_31 = true ;
V_4 -> V_32 = false ;
V_4 -> V_33 = true ;
V_17 = 24 ;
V_19 = F_3 ( V_13 -> V_34 ) ;
V_21 = F_4 ( V_13 ) ;
if ( V_13 -> V_35 ) {
V_13 -> V_36 = 0 ;
V_13 -> V_37 = F_5 ( V_13 , V_21 ) ;
} else {
V_13 -> V_36 = F_6 ( V_21 ) ;
V_13 -> V_37 = 0 ;
}
V_13 -> V_19 = V_19 ;
V_4 -> V_38 = 24 ;
V_4 -> V_39 = V_21 ;
V_16 = V_4 -> V_7 . V_16 ;
F_7 (state, drm_connector, connector_state, i) {
V_26 = F_8 ( V_24 ) ;
if ( V_29 -> V_40 == & V_2 -> V_7 ) {
V_27 = V_26 ;
break;
}
}
if ( ! V_27 ) {
F_9 ( L_1 ) ;
return false ;
}
V_30 = F_10 ( V_23 -> clock , V_17 ) ;
V_4 -> V_41 = V_30 ;
V_20 = F_11 ( & V_13 -> V_42 , V_30 ) ;
F_12 ( V_17 , V_19 ,
V_23 -> V_43 ,
V_4 -> V_39 ,
& V_4 -> V_44 ) ;
V_4 -> V_44 . V_45 = V_20 ;
if ( F_13 ( V_6 ) || F_14 ( V_6 ) )
F_15 ( V_4 ) ;
return true ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( & V_2 -> V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
int V_46 ;
F_17 ( L_2 , V_13 -> V_47 ) ;
F_18 ( & V_13 -> V_42 , V_9 -> V_48 ) ;
V_46 = F_19 ( & V_13 -> V_42 ) ;
if ( V_46 ) {
F_9 ( L_3 , V_46 ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( & V_2 -> V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
F_17 ( L_2 , V_13 -> V_47 ) ;
F_21 ( & V_13 -> V_42 ) ;
F_22 ( & V_13 -> V_42 ) ;
F_23 ( & V_13 -> V_42 , V_9 -> V_48 ) ;
V_13 -> V_47 -- ;
V_9 -> V_48 = NULL ;
if ( V_13 -> V_47 == 0 ) {
V_11 -> V_7 . V_49 ( & V_11 -> V_7 ) ;
F_24 ( V_13 , V_50 ) ;
}
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( & V_2 -> V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_5 * V_6 = V_2 -> V_7 . V_6 ;
struct V_51 * V_52 = V_6 -> V_53 ;
enum V_48 V_48 = V_11 -> V_48 ;
int V_46 ;
T_1 V_54 ;
struct V_25 * V_27 = NULL , * V_26 ;
int V_20 ;
struct V_55 * V_56 = V_2 -> V_7 . V_56 ;
struct V_57 * V_57 = F_26 ( V_56 ) ;
F_27 (dev, connector) {
if ( V_26 -> V_7 . V_16 -> V_40 == & V_2 -> V_7 ) {
V_27 = V_26 ;
break;
}
}
if ( ! V_27 ) {
F_9 ( L_1 ) ;
return;
}
V_27 -> V_2 = V_2 ;
F_17 ( L_2 , V_13 -> V_47 ) ;
V_9 -> V_48 = V_27 -> V_48 ;
if ( V_13 -> V_47 == 0 ) {
enum V_48 V_48 = F_28 ( V_2 ) ;
if ( F_29 ( V_6 ) -> V_58 < 9 )
F_30 ( F_31 ( V_48 ) ,
V_57 -> V_59 -> V_60 ) ;
F_32 ( & V_11 -> V_7 ) ;
F_24 ( V_13 , V_61 ) ;
F_33 ( V_13 ) ;
F_34 ( V_13 ) ;
F_35 ( V_13 ) ;
}
V_46 = F_36 ( & V_13 -> V_42 ,
V_9 -> V_48 ,
V_57 -> V_59 -> V_41 , & V_20 ) ;
if ( V_46 == false ) {
F_9 ( L_4 ) ;
return;
}
V_13 -> V_47 ++ ;
V_54 = F_37 ( F_38 ( V_48 ) ) ;
F_30 ( F_38 ( V_48 ) , V_54 ) ;
V_46 = F_19 ( & V_13 -> V_42 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( & V_2 -> V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_5 * V_6 = V_11 -> V_7 . V_7 . V_6 ;
struct V_51 * V_52 = V_6 -> V_53 ;
enum V_48 V_48 = V_11 -> V_48 ;
int V_46 ;
F_17 ( L_2 , V_13 -> V_47 ) ;
if ( F_40 ( ( F_37 ( F_38 ( V_48 ) ) & V_62 ) ,
1 ) )
F_9 ( L_5 ) ;
V_46 = F_21 ( & V_13 -> V_42 ) ;
V_46 = F_22 ( & V_13 -> V_42 ) ;
}
static bool F_41 ( struct V_1 * V_2 ,
enum V_63 * V_63 )
{
struct V_8 * V_9 = F_2 ( & V_2 -> V_7 ) ;
* V_63 = V_9 -> V_63 ;
if ( V_9 -> V_48 )
return true ;
return false ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = F_2 ( & V_2 -> V_7 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_57 * V_56 = F_26 ( V_2 -> V_7 . V_56 ) ;
struct V_5 * V_6 = V_2 -> V_7 . V_6 ;
struct V_51 * V_52 = V_6 -> V_53 ;
enum V_64 V_65 = V_4 -> V_65 ;
T_2 V_54 , V_66 = 0 ;
V_4 -> V_33 = true ;
V_54 = F_37 ( F_43 ( V_65 ) ) ;
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
V_4 -> V_38 = 18 ;
break;
case V_75 :
V_4 -> V_38 = 24 ;
break;
case V_76 :
V_4 -> V_38 = 30 ;
break;
case V_77 :
V_4 -> V_38 = 36 ;
break;
default:
break;
}
V_4 -> V_7 . V_23 . V_66 |= V_66 ;
F_44 ( V_56 , V_4 ) ;
F_45 ( & V_11 -> V_7 , V_4 ) ;
}
static int F_46 ( struct V_24 * V_26 )
{
struct V_25 * V_25 = F_8 ( V_26 ) ;
struct V_13 * V_13 = V_25 -> V_78 ;
struct V_79 * V_79 ;
int V_46 ;
V_79 = F_47 ( V_26 , & V_13 -> V_42 , V_25 -> V_48 ) ;
if ( ! V_79 )
return 0 ;
V_46 = F_48 ( V_26 , V_79 ) ;
F_49 ( V_79 ) ;
return V_46 ;
}
static enum V_80
F_50 ( struct V_24 * V_26 , bool V_81 )
{
struct V_25 * V_25 = F_8 ( V_26 ) ;
struct V_13 * V_13 = V_25 -> V_78 ;
return F_51 ( V_26 , & V_13 -> V_42 , V_25 -> V_48 ) ;
}
static int
F_52 ( struct V_24 * V_26 ,
struct V_82 * V_83 ,
T_3 V_84 )
{
return 0 ;
}
static void
F_53 ( struct V_24 * V_26 )
{
struct V_25 * V_25 = F_8 ( V_26 ) ;
if ( ! F_54 ( V_25 -> V_79 ) )
F_49 ( V_25 -> V_79 ) ;
F_55 ( V_26 ) ;
F_49 ( V_26 ) ;
}
static int F_56 ( struct V_24 * V_26 )
{
return F_46 ( V_26 ) ;
}
static enum V_85
F_57 ( struct V_24 * V_26 ,
struct V_22 * V_86 )
{
if ( V_86 -> clock < 10000 )
return V_87 ;
if ( V_86 -> V_66 & V_88 )
return V_89 ;
return V_90 ;
}
static struct V_91 * F_58 ( struct V_24 * V_26 ,
struct V_28 * V_16 )
{
struct V_25 * V_25 = F_8 ( V_26 ) ;
struct V_13 * V_13 = V_25 -> V_78 ;
struct V_57 * V_56 = F_26 ( V_16 -> V_56 ) ;
return & V_13 -> V_92 [ V_56 -> V_63 ] -> V_7 . V_7 ;
}
static struct V_91 * F_59 ( struct V_24 * V_26 )
{
struct V_25 * V_25 = F_8 ( V_26 ) ;
struct V_13 * V_13 = V_25 -> V_78 ;
return & V_13 -> V_92 [ 0 ] -> V_7 . V_7 ;
}
static void F_60 ( struct V_91 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_61 ( V_2 ) ;
F_49 ( V_9 ) ;
}
static bool F_62 ( struct V_25 * V_26 )
{
if ( V_26 -> V_2 && V_26 -> V_7 . V_16 -> V_56 ) {
enum V_63 V_63 ;
if ( ! V_26 -> V_2 -> V_93 ( V_26 -> V_2 , & V_63 ) )
return false ;
return true ;
}
return false ;
}
static void F_63 ( struct V_25 * V_26 )
{
#ifdef F_64
struct V_51 * V_52 = F_65 ( V_26 -> V_7 . V_6 ) ;
F_66 ( & V_52 -> V_94 -> V_95 , & V_26 -> V_7 ) ;
#endif
}
static void F_67 ( struct V_25 * V_26 )
{
#ifdef F_64
struct V_51 * V_52 = F_65 ( V_26 -> V_7 . V_6 ) ;
F_68 ( & V_52 -> V_94 -> V_95 , & V_26 -> V_7 ) ;
#endif
}
static struct V_24 * F_69 ( struct V_96 * V_97 , struct V_98 * V_48 , const char * V_99 )
{
struct V_13 * V_13 = F_70 ( V_97 , struct V_13 , V_42 ) ;
struct V_10 * V_11 = F_71 ( V_13 ) ;
struct V_5 * V_6 = V_11 -> V_7 . V_7 . V_6 ;
struct V_25 * V_25 ;
struct V_24 * V_26 ;
int V_18 ;
V_25 = F_72 () ;
if ( ! V_25 )
return NULL ;
V_26 = & V_25 -> V_7 ;
F_73 ( V_6 , V_26 , & V_100 , V_101 ) ;
F_74 ( V_26 , & V_102 ) ;
V_25 -> V_103 = V_104 ;
V_25 -> V_93 = F_62 ;
V_25 -> V_78 = V_13 ;
V_25 -> V_48 = V_48 ;
for ( V_18 = V_105 ; V_18 <= V_106 ; V_18 ++ ) {
F_75 ( & V_25 -> V_7 ,
& V_13 -> V_92 [ V_18 ] -> V_7 . V_7 ) ;
}
F_76 ( V_13 , V_26 ) ;
F_77 ( & V_26 -> V_7 , V_6 -> V_107 . V_108 , 0 ) ;
F_77 ( & V_26 -> V_7 , V_6 -> V_107 . V_109 , 0 ) ;
F_78 ( V_26 , V_99 ) ;
return V_26 ;
}
static void F_79 ( struct V_24 * V_26 )
{
struct V_25 * V_25 = F_8 ( V_26 ) ;
struct V_5 * V_6 = V_26 -> V_6 ;
F_80 ( V_6 ) ;
F_63 ( V_25 ) ;
F_81 ( V_6 ) ;
F_82 ( & V_25 -> V_7 ) ;
}
static void F_83 ( struct V_96 * V_97 ,
struct V_24 * V_26 )
{
struct V_25 * V_25 = F_8 ( V_26 ) ;
struct V_5 * V_6 = V_26 -> V_6 ;
F_80 ( V_6 ) ;
if ( V_26 -> V_16 -> V_56 ) {
struct V_110 V_111 ;
int V_46 ;
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
V_111 . V_56 = V_26 -> V_16 -> V_56 ,
V_46 = F_84 ( & V_111 ) ;
F_85 ( V_46 , L_6 , V_46 ) ;
}
F_81 ( V_6 ) ;
V_25 -> V_103 ( V_25 ) ;
F_80 ( V_6 ) ;
F_67 ( V_25 ) ;
F_55 ( V_26 ) ;
F_81 ( V_6 ) ;
F_49 ( V_25 ) ;
F_17 ( L_7 ) ;
}
static void F_86 ( struct V_96 * V_97 )
{
struct V_13 * V_13 = F_70 ( V_97 , struct V_13 , V_42 ) ;
struct V_10 * V_11 = F_71 ( V_13 ) ;
struct V_5 * V_6 = V_11 -> V_7 . V_7 . V_6 ;
F_87 ( V_6 ) ;
}
static struct V_8 *
F_88 ( struct V_10 * V_11 , enum V_63 V_63 )
{
struct V_8 * V_9 ;
struct V_1 * V_1 ;
struct V_5 * V_6 = V_11 -> V_7 . V_7 . V_6 ;
V_9 = F_89 ( sizeof( * V_9 ) , V_112 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_63 = V_63 ;
V_1 = & V_9 -> V_7 ;
V_9 -> V_12 = V_11 ;
F_90 ( V_6 , & V_1 -> V_7 , & V_113 ,
V_114 ) ;
V_1 -> type = V_115 ;
V_1 -> V_116 = 0x7 ;
V_1 -> V_117 = 0 ;
V_1 -> V_118 = F_1 ;
V_1 -> V_119 = F_16 ;
V_1 -> V_49 = F_20 ;
V_1 -> V_120 = F_25 ;
V_1 -> V_121 = F_39 ;
V_1 -> V_93 = F_41 ;
V_1 -> V_122 = F_42 ;
return V_9 ;
}
static bool
F_91 ( struct V_10 * V_11 )
{
int V_18 ;
struct V_13 * V_13 = & V_11 -> V_14 ;
for ( V_18 = V_105 ; V_18 <= V_106 ; V_18 ++ )
V_13 -> V_92 [ V_18 ] = F_88 ( V_11 , V_18 ) ;
return true ;
}
int
F_92 ( struct V_10 * V_11 , int V_123 )
{
struct V_13 * V_13 = & V_11 -> V_14 ;
struct V_5 * V_6 = V_11 -> V_7 . V_7 . V_6 ;
int V_46 ;
V_13 -> V_124 = true ;
V_13 -> V_42 . V_125 = & V_126 ;
F_91 ( V_11 ) ;
V_46 = F_93 ( & V_13 -> V_42 , V_6 -> V_6 , & V_13 -> V_127 , 16 , 3 , V_123 ) ;
if ( V_46 ) {
V_13 -> V_124 = false ;
return V_46 ;
}
return 0 ;
}
void
F_94 ( struct V_10 * V_11 )
{
struct V_13 * V_13 = & V_11 -> V_14 ;
if ( ! V_13 -> V_124 )
return;
F_95 ( & V_13 -> V_42 ) ;
}

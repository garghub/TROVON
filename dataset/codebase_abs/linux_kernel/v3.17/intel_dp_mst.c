static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
struct V_13 * V_14 = V_2 -> V_7 . V_14 ;
int V_15 ;
int V_16 , V_17 ;
struct V_18 * V_19 = & V_4 -> V_19 ;
struct V_20 * V_21 = NULL , * V_20 ;
int V_22 ;
V_4 -> V_23 = true ;
V_4 -> V_24 = false ;
V_4 -> V_25 = true ;
V_15 = 24 ;
V_16 = F_3 ( V_11 -> V_26 ) ;
V_11 -> V_27 = F_4 ( V_11 ) ;
V_11 -> V_16 = V_16 ;
V_4 -> V_28 = 24 ;
V_4 -> V_29 = F_5 ( V_11 -> V_27 ) ;
F_6 (intel_connector, &dev->mode_config.connector_list, base.head) {
if ( V_20 -> V_30 == V_2 ) {
V_21 = V_20 ;
break;
}
}
if ( ! V_21 ) {
F_7 ( L_1 ) ;
return false ;
}
V_22 = F_8 ( V_19 -> clock , V_15 ) ;
V_4 -> V_31 = V_22 ;
V_17 = F_9 ( & V_11 -> V_32 , V_22 ) ;
F_10 ( V_15 , V_16 ,
V_19 -> V_33 ,
V_4 -> V_29 ,
& V_4 -> V_34 ) ;
V_4 -> V_34 . V_35 = V_17 ;
return true ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
int V_36 ;
F_12 ( L_2 , V_11 -> V_37 ) ;
F_13 ( & V_11 -> V_32 , V_6 -> V_38 ) ;
V_36 = F_14 ( & V_11 -> V_32 ) ;
if ( V_36 ) {
F_7 ( L_3 , V_36 ) ;
}
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
F_12 ( L_2 , V_11 -> V_37 ) ;
F_16 ( & V_11 -> V_32 ) ;
F_17 ( & V_11 -> V_32 ) ;
F_18 ( & V_11 -> V_32 , V_6 -> V_38 ) ;
V_11 -> V_37 -- ;
V_6 -> V_38 = NULL ;
if ( V_11 -> V_37 == 0 ) {
V_9 -> V_7 . V_39 ( & V_9 -> V_7 ) ;
F_19 ( V_11 , V_40 ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
struct V_13 * V_14 = V_2 -> V_7 . V_14 ;
struct V_41 * V_42 = V_14 -> V_43 ;
enum V_38 V_38 = V_9 -> V_38 ;
int V_36 ;
T_1 V_44 ;
struct V_20 * V_21 = NULL , * V_20 ;
int V_17 ;
struct V_45 * V_46 = V_2 -> V_7 . V_46 ;
struct V_47 * V_47 = F_21 ( V_46 ) ;
F_6 (intel_connector, &dev->mode_config.connector_list, base.head) {
if ( V_20 -> V_30 == V_2 ) {
V_21 = V_20 ;
break;
}
}
if ( ! V_21 ) {
F_7 ( L_1 ) ;
return;
}
F_12 ( L_2 , V_11 -> V_37 ) ;
V_6 -> V_38 = V_21 -> V_38 ;
if ( V_11 -> V_37 == 0 ) {
enum V_38 V_38 = F_22 ( V_2 ) ;
F_23 ( F_24 ( V_38 ) , V_47 -> V_48 . V_49 ) ;
F_25 ( & V_9 -> V_7 ) ;
F_19 ( V_11 , V_50 ) ;
F_26 ( V_11 ) ;
F_27 ( V_11 ) ;
F_28 ( V_11 ) ;
}
V_36 = F_29 ( & V_11 -> V_32 ,
V_6 -> V_38 , V_47 -> V_48 . V_31 , & V_17 ) ;
if ( V_36 == false ) {
F_7 ( L_4 ) ;
return;
}
V_11 -> V_37 ++ ;
V_44 = F_30 ( F_31 ( V_38 ) ) ;
F_23 ( F_31 ( V_38 ) , V_44 ) ;
V_36 = F_14 ( & V_11 -> V_32 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
struct V_13 * V_14 = V_9 -> V_7 . V_7 . V_14 ;
struct V_41 * V_42 = V_14 -> V_43 ;
enum V_38 V_38 = V_9 -> V_38 ;
int V_36 ;
F_12 ( L_2 , V_11 -> V_37 ) ;
if ( F_33 ( ( F_30 ( F_31 ( V_38 ) ) & V_51 ) ,
1 ) )
F_7 ( L_5 ) ;
V_36 = F_16 ( & V_11 -> V_32 ) ;
V_36 = F_17 ( & V_11 -> V_32 ) ;
}
static bool F_34 ( struct V_1 * V_2 ,
enum V_52 * V_52 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
* V_52 = V_6 -> V_52 ;
if ( V_6 -> V_38 )
return true ;
return false ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_47 * V_46 = F_21 ( V_2 -> V_7 . V_46 ) ;
struct V_13 * V_14 = V_2 -> V_7 . V_14 ;
struct V_41 * V_42 = V_14 -> V_43 ;
enum V_53 V_54 = V_46 -> V_48 . V_54 ;
T_2 V_44 , V_55 = 0 ;
V_4 -> V_25 = true ;
V_44 = F_30 ( F_36 ( V_54 ) ) ;
if ( V_44 & V_56 )
V_55 |= V_57 ;
else
V_55 |= V_58 ;
if ( V_44 & V_59 )
V_55 |= V_60 ;
else
V_55 |= V_61 ;
switch ( V_44 & V_62 ) {
case V_63 :
V_4 -> V_28 = 18 ;
break;
case V_64 :
V_4 -> V_28 = 24 ;
break;
case V_65 :
V_4 -> V_28 = 30 ;
break;
case V_66 :
V_4 -> V_28 = 36 ;
break;
default:
break;
}
V_4 -> V_19 . V_55 |= V_55 ;
F_37 ( V_46 , V_4 ) ;
F_38 ( & V_9 -> V_7 , V_4 ) ;
}
static int F_39 ( struct V_67 * V_68 )
{
struct V_20 * V_20 = F_40 ( V_68 ) ;
struct V_11 * V_11 = V_20 -> V_69 ;
struct V_70 * V_70 ;
int V_36 ;
V_70 = F_41 ( V_68 , & V_11 -> V_32 , V_20 -> V_38 ) ;
if ( ! V_70 )
return 0 ;
V_36 = F_42 ( V_68 , V_70 ) ;
F_43 ( V_70 ) ;
return V_36 ;
}
static enum V_71
F_44 ( struct V_67 * V_68 )
{
struct V_20 * V_20 = F_40 ( V_68 ) ;
struct V_11 * V_11 = V_20 -> V_69 ;
return F_45 ( & V_11 -> V_32 , V_20 -> V_38 ) ;
}
static enum V_71
F_46 ( struct V_67 * V_68 , bool V_72 )
{
enum V_71 V_73 ;
V_73 = F_44 ( V_68 ) ;
return V_73 ;
}
static int
F_47 ( struct V_67 * V_68 ,
struct V_74 * V_75 ,
T_3 V_76 )
{
return 0 ;
}
static void
F_48 ( struct V_67 * V_68 )
{
struct V_20 * V_20 = F_40 ( V_68 ) ;
if ( ! F_49 ( V_20 -> V_70 ) )
F_43 ( V_20 -> V_70 ) ;
F_50 ( V_68 ) ;
F_43 ( V_68 ) ;
}
static int F_51 ( struct V_67 * V_68 )
{
return F_39 ( V_68 ) ;
}
static enum V_77
F_52 ( struct V_67 * V_68 ,
struct V_18 * V_78 )
{
if ( V_78 -> clock < 10000 )
return V_79 ;
if ( V_78 -> V_55 & V_80 )
return V_81 ;
return V_82 ;
}
static struct V_83 * F_53 ( struct V_67 * V_68 )
{
struct V_20 * V_20 = F_40 ( V_68 ) ;
struct V_11 * V_11 = V_20 -> V_69 ;
return & V_11 -> V_84 [ 0 ] -> V_7 . V_7 ;
}
static void F_54 ( struct V_83 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_55 ( V_2 ) ;
F_43 ( V_6 ) ;
}
static bool F_56 ( struct V_20 * V_68 )
{
if ( V_68 -> V_2 ) {
enum V_52 V_52 ;
if ( ! V_68 -> V_2 -> V_85 ( V_68 -> V_2 , & V_52 ) )
return false ;
return true ;
}
return false ;
}
static void F_57 ( struct V_20 * V_68 )
{
#ifdef F_58
struct V_41 * V_42 = F_59 ( V_68 -> V_7 . V_14 ) ;
F_60 ( & V_42 -> V_86 -> V_87 , & V_68 -> V_7 ) ;
#endif
}
static void F_61 ( struct V_20 * V_68 )
{
#ifdef F_58
struct V_41 * V_42 = F_59 ( V_68 -> V_7 . V_14 ) ;
F_62 ( & V_42 -> V_86 -> V_87 , & V_68 -> V_7 ) ;
#endif
}
static struct V_67 * F_63 ( struct V_88 * V_89 , struct V_90 * V_38 , char * V_91 )
{
struct V_11 * V_11 = F_64 ( V_89 , struct V_11 , V_32 ) ;
struct V_8 * V_9 = F_65 ( V_11 ) ;
struct V_13 * V_14 = V_9 -> V_7 . V_7 . V_14 ;
struct V_20 * V_20 ;
struct V_67 * V_68 ;
int V_92 ;
V_20 = F_66 ( sizeof( * V_20 ) , V_93 ) ;
if ( ! V_20 )
return NULL ;
V_68 = & V_20 -> V_7 ;
F_67 ( V_14 , V_68 , & V_94 , V_95 ) ;
F_68 ( V_68 , & V_96 ) ;
V_20 -> V_97 = V_98 ;
V_20 -> V_85 = F_56 ;
V_20 -> V_69 = V_11 ;
V_20 -> V_38 = V_38 ;
for ( V_92 = V_99 ; V_92 <= V_100 ; V_92 ++ ) {
F_69 ( & V_20 -> V_7 ,
& V_11 -> V_84 [ V_92 ] -> V_7 . V_7 ) ;
}
F_70 ( V_11 , V_68 ) ;
F_71 ( & V_68 -> V_7 , V_14 -> V_101 . V_102 , 0 ) ;
F_72 ( V_68 , V_91 ) ;
F_73 ( V_14 ) ;
F_74 ( & V_14 -> V_101 . V_103 ) ;
F_57 ( V_20 ) ;
F_75 ( & V_14 -> V_101 . V_103 ) ;
F_76 ( & V_20 -> V_7 ) ;
return V_68 ;
}
static void F_77 ( struct V_88 * V_89 ,
struct V_67 * V_68 )
{
struct V_20 * V_20 = F_40 ( V_68 ) ;
struct V_13 * V_14 = V_68 -> V_14 ;
F_74 ( & V_14 -> V_101 . V_103 ) ;
F_78 ( V_68 , V_40 ) ;
F_75 ( & V_14 -> V_101 . V_103 ) ;
V_20 -> V_97 ( V_20 ) ;
F_74 ( & V_14 -> V_101 . V_103 ) ;
F_61 ( V_20 ) ;
F_50 ( V_68 ) ;
F_75 ( & V_14 -> V_101 . V_103 ) ;
F_73 ( V_14 ) ;
F_43 ( V_20 ) ;
F_12 ( L_6 ) ;
}
static void F_79 ( struct V_88 * V_89 )
{
struct V_11 * V_11 = F_64 ( V_89 , struct V_11 , V_32 ) ;
struct V_8 * V_9 = F_65 ( V_11 ) ;
struct V_13 * V_14 = V_9 -> V_7 . V_7 . V_14 ;
F_80 ( V_14 ) ;
}
static struct V_5 *
F_81 ( struct V_8 * V_9 , enum V_52 V_52 )
{
struct V_5 * V_6 ;
struct V_1 * V_1 ;
struct V_13 * V_14 = V_9 -> V_7 . V_7 . V_14 ;
V_6 = F_66 ( sizeof( * V_6 ) , V_93 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_52 = V_52 ;
V_1 = & V_6 -> V_7 ;
V_6 -> V_10 = V_9 ;
F_82 ( V_14 , & V_1 -> V_7 , & V_104 ,
V_105 ) ;
V_1 -> type = V_106 ;
V_1 -> V_107 = 0x7 ;
V_1 -> V_108 = 0 ;
V_1 -> V_109 = F_1 ;
V_1 -> V_110 = F_11 ;
V_1 -> V_39 = F_15 ;
V_1 -> V_111 = F_20 ;
V_1 -> V_112 = F_32 ;
V_1 -> V_85 = F_34 ;
V_1 -> V_113 = F_35 ;
return V_6 ;
}
static bool
F_83 ( struct V_8 * V_9 )
{
int V_92 ;
struct V_11 * V_11 = & V_9 -> V_12 ;
for ( V_92 = V_99 ; V_92 <= V_100 ; V_92 ++ )
V_11 -> V_84 [ V_92 ] = F_81 ( V_9 , V_92 ) ;
return true ;
}
int
F_84 ( struct V_8 * V_9 , int V_114 )
{
struct V_11 * V_11 = & V_9 -> V_12 ;
struct V_13 * V_14 = V_9 -> V_7 . V_7 . V_14 ;
int V_36 ;
V_11 -> V_115 = true ;
V_11 -> V_32 . V_116 = & V_117 ;
F_83 ( V_9 ) ;
V_36 = F_85 ( & V_11 -> V_32 , V_14 -> V_14 , & V_11 -> V_118 , 16 , 3 , V_114 ) ;
if ( V_36 ) {
V_11 -> V_115 = false ;
return V_36 ;
}
return 0 ;
}
void
F_86 ( struct V_8 * V_9 )
{
struct V_11 * V_11 = & V_9 -> V_12 ;
if ( ! V_11 -> V_115 )
return;
F_87 ( & V_11 -> V_32 ) ;
}

static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int
F_3 ( struct V_5 * V_6 )
{
return F_4 ( V_6 -> V_7 ) ;
}
static void
F_5 ( struct V_5 * V_6 )
{
F_6 ( V_6 -> V_7 ) ;
}
static int F_7 ( struct V_1 * V_8 )
{
int V_9 ;
V_8 -> V_10 . V_11 = V_12 ;
V_8 -> V_10 . V_13 = sizeof( struct V_14 ) ;
V_8 -> V_10 . V_15 = & F_3 ;
V_8 -> V_10 . V_16 = & F_5 ;
V_9 = F_8 ( & V_8 -> V_10 ) ;
if ( V_9 ) {
F_9 ( L_1 , V_9 ) ;
return V_9 ;
}
V_8 -> V_17 . V_18 =
V_8 -> V_10 . V_7 ;
V_8 -> V_17 . V_6 . V_11 = V_19 ;
V_8 -> V_17 . V_6 . V_13 = sizeof( struct V_20 ) ;
V_8 -> V_17 . V_6 . V_15 = & V_21 ;
V_8 -> V_17 . V_6 . V_16 = & V_22 ;
V_9 = F_8 ( & V_8 -> V_17 . V_6 ) ;
if ( V_9 ) {
F_9 ( L_2 , V_9 ) ;
F_10 ( & V_8 -> V_10 ) ;
return V_9 ;
}
return 0 ;
}
static void
F_11 ( struct V_1 * V_8 )
{
F_10 ( & V_8 -> V_17 . V_6 ) ;
F_10 ( & V_8 -> V_10 ) ;
V_8 -> V_10 . V_16 = NULL ;
}
static void F_12 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_2 ( V_24 , struct V_25 , V_26 ) ;
F_13 ( & V_26 -> V_27 ) ;
F_14 ( V_26 ) ;
}
static bool F_15 ( struct V_23 * V_26 )
{
return V_26 -> V_28 == & F_12 ;
}
static int
F_16 ( struct V_2 * V_4 , T_1 type ,
struct V_29 * V_30 )
{
switch ( type ) {
case V_31 :
V_30 -> V_32 = V_33 ;
V_30 -> V_34 = V_35 ;
V_30 -> V_36 = V_37 ;
break;
case V_38 :
V_30 -> V_39 = & V_40 ;
V_30 -> V_32 = V_41 |
V_33 ;
V_30 -> V_34 = V_42 |
V_43 ;
V_30 -> V_36 = V_43 ;
break;
default:
F_9 ( L_3 , type ) ;
return - V_44 ;
}
return 0 ;
}
void F_17 ( struct V_25 * V_26 , int V_45 )
{
T_1 V_46 = 0 ;
T_1 V_47 ;
V_26 -> V_48 . V_48 = V_26 -> V_49 ;
V_26 -> V_48 . V_50 = V_26 -> V_49 ;
if ( V_45 & V_51 )
V_26 -> V_49 [ V_46 ++ ] . V_32 = V_43 |
V_42 | V_51 ;
if ( V_45 & V_52 )
V_26 -> V_49 [ V_46 ++ ] . V_32 = V_35 |
V_52 ;
if ( ! V_46 )
V_26 -> V_49 [ V_46 ++ ] . V_32 = V_35 |
V_52 ;
V_26 -> V_48 . V_53 = V_46 ;
V_26 -> V_48 . V_54 = V_46 ;
for ( V_47 = 0 ; V_47 < V_46 ; V_47 ++ ) {
V_26 -> V_49 [ V_47 ] . V_55 = 0 ;
V_26 -> V_49 [ V_47 ] . V_56 = 0 ;
}
}
static void
F_18 ( struct V_23 * V_26 , struct V_57 * V_58 )
{
struct V_25 * V_59 = V_25 ( V_26 ) ;
if ( ! F_15 ( V_26 ) )
return;
F_17 ( V_59 , V_52 ) ;
* V_58 = V_59 -> V_48 ;
}
static int F_19 ( struct V_23 * V_26 ,
struct V_60 * V_61 )
{
struct V_25 * V_59 = V_25 ( V_26 ) ;
return F_20 ( & V_59 -> V_27 . V_62 ,
V_61 -> V_63 ) ;
}
static int F_21 ( struct V_2 * V_4 ,
struct V_64 * V_65 )
{
struct V_29 * V_30 = & V_4 -> V_30 [ V_65 -> V_66 ] ;
struct V_1 * V_8 = F_1 ( V_4 ) ;
V_65 -> V_67 . V_68 = NULL ;
V_65 -> V_67 . V_69 = 0 ;
V_65 -> V_67 . V_13 = V_65 -> V_70 << V_71 ;
V_65 -> V_67 . V_72 = 0 ;
V_65 -> V_67 . V_73 = false ;
if ( ! ( V_30 -> V_32 & V_33 ) )
return - V_44 ;
switch ( V_65 -> V_66 ) {
case V_31 :
return 0 ;
case V_38 :
V_65 -> V_67 . V_69 = V_65 -> V_74 << V_71 ;
V_65 -> V_67 . V_72 = F_22 ( V_8 -> V_75 -> V_76 , 0 ) ;
V_65 -> V_67 . V_73 = true ;
break;
default:
return - V_44 ;
}
return 0 ;
}
static void F_23 ( struct V_77 * V_78 )
{
F_24 ( V_78 ) ;
F_14 ( V_78 ) ;
}
static struct V_77 * F_25 ( struct V_2 * V_4 ,
unsigned long V_13 ,
T_1 V_79 ,
struct V_80 * V_81 )
{
struct V_77 * V_78 ;
int V_9 ;
V_78 = F_26 ( sizeof( * V_78 ) , V_82 ) ;
if ( ! V_78 ) {
F_9 ( L_4 ) ;
return NULL ;
}
V_78 -> V_39 = & V_83 ;
V_9 = F_27 ( V_78 , V_4 , V_13 , V_79 , V_81 ) ;
if ( V_9 ) {
F_9 ( L_5 , V_9 ) ;
F_14 ( V_78 ) ;
return NULL ;
}
return V_78 ;
}
static int F_28 ( struct V_77 * V_84 )
{
return F_29 ( V_84 ) ;
}
static void F_30 ( struct V_77 * V_84 )
{
F_31 ( V_84 ) ;
}
int F_32 ( struct V_1 * V_8 )
{
int V_9 ;
struct V_85 * V_75 = V_8 -> V_75 ;
struct V_2 * V_4 = & V_8 -> V_4 ;
V_9 = F_7 ( V_8 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_33 ( & V_8 -> V_4 ,
V_8 -> V_17 . V_6 . V_7 ,
& V_86 ,
V_75 -> V_87 -> V_88 ,
V_89 ,
true ) ;
if ( V_9 ) {
F_11 ( V_8 ) ;
F_9 ( L_6 , V_9 ) ;
return V_9 ;
}
V_9 = F_34 ( V_4 , V_38 ,
V_8 -> V_90 >> V_71 ) ;
if ( V_9 ) {
F_11 ( V_8 ) ;
F_9 ( L_7 , V_9 ) ;
return V_9 ;
}
V_8 -> V_91 = true ;
return 0 ;
}
void F_35 ( struct V_1 * V_8 )
{
if ( ! V_8 -> V_91 )
return;
F_36 ( & V_8 -> V_4 ) ;
F_11 ( V_8 ) ;
V_8 -> V_91 = false ;
}
static void F_37 ( struct V_25 * * V_26 )
{
struct V_23 * V_24 ;
if ( ( * V_26 ) == NULL )
return;
V_24 = & ( ( * V_26 ) -> V_26 ) ;
F_38 ( & V_24 ) ;
* V_26 = NULL ;
}
int F_39 ( struct V_85 * V_75 , int V_13 , int V_92 ,
T_1 V_32 , struct V_25 * * V_93 )
{
struct V_1 * V_8 = V_75 -> V_94 ;
struct V_25 * V_59 ;
T_2 V_95 ;
int V_9 ;
V_59 = F_26 ( sizeof( * V_59 ) , V_82 ) ;
if ( ! V_59 ) {
F_9 ( L_8 ) ;
return - V_96 ;
}
V_9 = F_40 ( V_75 , & V_59 -> V_27 , V_13 ) ;
if ( V_9 ) {
F_9 ( L_9 , V_9 ) ;
F_14 ( V_59 ) ;
return V_9 ;
}
V_59 -> V_26 . V_4 = & V_8 -> V_4 ;
F_17 ( V_59 , V_51 | V_52 ) ;
V_95 = F_41 ( & V_8 -> V_4 , V_13 ,
sizeof( struct V_25 ) ) ;
V_9 = F_42 ( & V_8 -> V_4 , & V_59 -> V_26 , V_13 ,
V_97 , & V_59 -> V_48 ,
V_92 >> V_71 , false , NULL , V_95 ,
NULL , NULL , F_12 ) ;
if ( V_9 ) {
F_37 ( & V_59 ) ;
F_9 ( L_10 , V_9 ) ;
return V_9 ;
}
* V_93 = V_59 ;
return 0 ;
}
int F_43 ( struct V_25 * V_26 , T_1 V_98 , T_3 * V_99 )
{
int V_47 , V_9 ;
if ( V_26 -> V_100 ) {
V_26 -> V_100 ++ ;
if ( V_99 )
* V_99 = V_26 -> V_26 . V_69 ;
return 0 ;
}
F_17 ( V_26 , V_98 ) ;
for ( V_47 = 0 ; V_47 < V_26 -> V_48 . V_53 ; V_47 ++ )
V_26 -> V_49 [ V_47 ] . V_32 |= V_101 ;
V_9 = F_44 ( & V_26 -> V_26 , & V_26 -> V_48 , false , false ) ;
if ( V_9 )
return V_9 ;
V_26 -> V_100 = 1 ;
if ( V_99 )
* V_99 = V_26 -> V_26 . V_69 ;
return 0 ;
}
int F_45 ( struct V_25 * V_26 )
{
int V_47 , V_9 ;
if ( ! V_26 -> V_100 ) {
F_9 ( L_11 , V_26 ) ;
return 0 ;
}
V_26 -> V_100 -- ;
if ( V_26 -> V_100 )
return 0 ;
for ( V_47 = 0 ; V_47 < V_26 -> V_48 . V_53 ; V_47 ++ )
V_26 -> V_49 [ V_47 ] . V_32 &= ~ V_101 ;
V_9 = F_44 ( & V_26 -> V_26 , & V_26 -> V_48 , false , false ) ;
if ( V_9 ) {
F_9 ( L_12 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
int F_46 ( struct V_60 * V_61 , struct V_102 * V_103 )
{
struct V_104 * V_105 ;
struct V_1 * V_8 ;
if ( F_47 ( V_103 -> V_106 < V_89 ) )
return - V_44 ;
V_105 = V_61 -> V_63 ;
V_8 = V_105 -> V_107 -> V_75 -> V_94 ;
return F_48 ( V_61 , V_103 , & V_8 -> V_4 ) ;
}
int F_49 ( struct V_85 * V_75 , T_1 V_13 , bool V_108 ,
struct V_109 * * V_110 )
{
struct V_25 * V_59 ;
int V_9 ;
* V_110 = NULL ;
V_13 = F_50 ( V_13 ) ;
if ( V_13 == 0 ) {
F_9 ( L_13 ) ;
return - V_44 ;
}
V_9 = F_39 ( V_75 , V_13 , 0 , 0 , & V_59 ) ;
if ( V_9 ) {
if ( V_9 != - V_111 )
F_9 ( L_14 , V_9 ) ;
return V_9 ;
}
* V_110 = & V_59 -> V_27 ;
return 0 ;
}
int F_51 ( struct V_104 * V_60 , struct V_85 * V_75 ,
struct V_112 * args )
{
struct V_109 * V_113 ;
T_1 V_114 ;
int V_9 ;
args -> V_115 = F_52 ( args -> V_116 * F_53 ( args -> V_117 , 8 ) , 16 ) ;
args -> V_13 = args -> V_115 * args -> V_118 ;
V_9 = F_49 ( V_75 , args -> V_13 , false ,
& V_113 ) ;
if ( V_9 ) {
F_9 ( L_15 , V_9 ) ;
return V_9 ;
}
V_9 = F_54 ( V_60 , V_113 , & V_114 ) ;
F_55 ( V_113 ) ;
if ( V_9 ) {
F_9 ( L_16 , V_9 ) ;
return V_9 ;
}
args -> V_114 = V_114 ;
return 0 ;
}
void F_56 ( struct V_109 * V_110 )
{
struct V_25 * V_59 = F_57 ( V_110 ) ;
F_37 ( & V_59 ) ;
}
static T_3 F_58 ( struct V_25 * V_26 )
{
return F_59 ( & V_26 -> V_26 . V_62 ) ;
}
int F_60 ( struct V_104 * V_60 , struct V_85 * V_75 ,
T_1 V_114 , T_3 * V_69 )
{
struct V_109 * V_110 ;
struct V_25 * V_26 ;
V_110 = F_61 ( V_60 , V_114 ) ;
if ( ! V_110 )
return - V_119 ;
V_26 = F_57 ( V_110 ) ;
* V_69 = F_58 ( V_26 ) ;
F_55 ( V_110 ) ;
return 0 ;
}
static void F_62 ( struct V_120 * V_121 )
{
struct V_122 * V_123 = F_63 ( V_121 ) ;
F_55 ( V_123 -> V_110 ) ;
F_64 ( V_121 ) ;
F_14 ( V_123 ) ;
}
struct V_122 *
F_65 ( struct V_85 * V_75 ,
const struct V_124 * V_125 ,
struct V_109 * V_110 )
{
struct V_122 * V_123 ;
int V_9 ;
V_123 = F_26 ( sizeof( * V_123 ) , V_82 ) ;
if ( ! V_123 ) {
F_9 ( L_17 ) ;
return F_66 ( - V_96 ) ;
}
F_67 ( V_75 , & V_123 -> V_121 , V_125 ) ;
V_123 -> V_110 = V_110 ;
V_9 = F_68 ( V_75 , & V_123 -> V_121 , & V_126 ) ;
if ( V_9 ) {
F_9 ( L_18 , V_9 ) ;
F_14 ( V_123 ) ;
return F_66 ( V_9 ) ;
}
return V_123 ;
}
static struct V_120 *
F_69 ( struct V_85 * V_75 ,
struct V_104 * V_61 ,
const struct V_124 * V_125 )
{
struct V_109 * V_110 ;
struct V_122 * V_123 ;
F_70 ( L_19 ,
V_125 -> V_116 , V_125 -> V_118 ,
( V_125 -> V_127 ) & 0xff ,
( V_125 -> V_127 >> 8 ) & 0xff ,
( V_125 -> V_127 >> 16 ) & 0xff ,
( V_125 -> V_127 >> 24 ) & 0xff ) ;
V_110 = F_61 ( V_61 , V_125 -> V_128 [ 0 ] ) ;
if ( ! V_110 )
return F_66 ( - V_119 ) ;
V_123 = F_65 ( V_75 , V_125 , V_110 ) ;
if ( F_71 ( V_123 ) ) {
F_55 ( V_110 ) ;
return F_66 ( ( long ) V_123 ) ;
}
return & V_123 -> V_121 ;
}

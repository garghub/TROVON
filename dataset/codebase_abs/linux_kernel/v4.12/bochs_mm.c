static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_5 ) ;
}
static int F_3 ( struct V_6 * V_7 )
{
return F_4 ( V_7 -> V_8 ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
F_6 ( V_7 -> V_8 ) ;
}
static int F_7 ( struct V_1 * V_9 )
{
struct V_6 * V_10 ;
int V_11 ;
V_10 = & V_9 -> V_4 . V_12 ;
V_10 -> V_13 = V_14 ;
V_10 -> V_15 = sizeof( struct V_16 ) ;
V_10 -> V_17 = & F_3 ;
V_10 -> V_18 = & F_5 ;
V_11 = F_8 ( V_10 ) ;
if ( V_11 != 0 ) {
F_9 ( L_1
L_2 ) ;
return V_11 ;
}
V_9 -> V_4 . V_19 . V_20 =
V_9 -> V_4 . V_12 . V_8 ;
V_10 = & V_9 -> V_4 . V_19 . V_7 ;
V_10 -> V_13 = V_21 ;
V_10 -> V_15 = sizeof( struct V_22 ) ;
V_10 -> V_17 = & V_23 ;
V_10 -> V_18 = & V_24 ;
V_11 = F_8 ( V_10 ) ;
if ( V_11 != 0 ) {
F_9 ( L_3 ) ;
F_10 ( & V_9 -> V_4 . V_12 ) ;
return V_11 ;
}
return 0 ;
}
static void F_11 ( struct V_1 * V_9 )
{
if ( V_9 -> V_4 . V_12 . V_18 == NULL )
return;
F_10 ( & V_9 -> V_4 . V_19 . V_7 ) ;
F_10 ( & V_9 -> V_4 . V_12 ) ;
V_9 -> V_4 . V_12 . V_18 = NULL ;
}
static void F_12 ( struct V_25 * V_26 )
{
struct V_27 * V_28 ;
V_28 = F_2 ( V_26 , struct V_27 , V_28 ) ;
F_13 ( & V_28 -> V_29 ) ;
F_14 ( V_28 ) ;
}
static bool F_15 ( struct V_25 * V_28 )
{
if ( V_28 -> V_30 == & F_12 )
return true ;
return false ;
}
static int F_16 ( struct V_2 * V_5 , T_1 type ,
struct V_31 * V_32 )
{
switch ( type ) {
case V_33 :
V_32 -> V_34 = V_35 ;
V_32 -> V_36 = V_37 ;
V_32 -> V_38 = V_39 ;
break;
case V_40 :
V_32 -> V_41 = & V_42 ;
V_32 -> V_34 = V_43 |
V_35 ;
V_32 -> V_36 = V_44 |
V_45 ;
V_32 -> V_38 = V_45 ;
break;
default:
F_9 ( L_4 , ( unsigned ) type ) ;
return - V_46 ;
}
return 0 ;
}
static void
F_17 ( struct V_25 * V_28 , struct V_47 * V_48 )
{
struct V_27 * V_49 = V_27 ( V_28 ) ;
if ( ! F_15 ( V_28 ) )
return;
F_18 ( V_49 , V_50 ) ;
* V_48 = V_49 -> V_51 ;
}
static int F_19 ( struct V_25 * V_28 ,
struct V_52 * V_53 )
{
struct V_27 * V_49 = V_27 ( V_28 ) ;
return F_20 ( & V_49 -> V_29 . V_54 ,
V_53 -> V_55 ) ;
}
static int F_21 ( struct V_2 * V_5 ,
struct V_56 * V_57 )
{
struct V_31 * V_32 = & V_5 -> V_32 [ V_57 -> V_58 ] ;
struct V_1 * V_9 = F_1 ( V_5 ) ;
V_57 -> V_59 . V_60 = NULL ;
V_57 -> V_59 . V_61 = 0 ;
V_57 -> V_59 . V_15 = V_57 -> V_62 << V_63 ;
V_57 -> V_59 . V_64 = 0 ;
V_57 -> V_59 . V_65 = false ;
if ( ! ( V_32 -> V_34 & V_35 ) )
return - V_46 ;
switch ( V_57 -> V_58 ) {
case V_33 :
return 0 ;
case V_40 :
V_57 -> V_59 . V_61 = V_57 -> V_66 << V_63 ;
V_57 -> V_59 . V_64 = V_9 -> V_67 ;
V_57 -> V_59 . V_65 = true ;
break;
default:
return - V_46 ;
break;
}
return 0 ;
}
static void F_22 ( struct V_2 * V_5 ,
struct V_56 * V_57 )
{
}
static void F_23 ( struct V_68 * V_69 )
{
F_24 ( V_69 ) ;
F_14 ( V_69 ) ;
}
static struct V_68 * F_25 ( struct V_2 * V_5 ,
unsigned long V_15 ,
T_1 V_70 ,
struct V_71 * V_72 )
{
struct V_68 * V_69 ;
V_69 = F_26 ( sizeof( struct V_68 ) , V_73 ) ;
if ( V_69 == NULL )
return NULL ;
V_69 -> V_41 = & V_74 ;
if ( F_27 ( V_69 , V_5 , V_15 , V_70 , V_72 ) ) {
F_14 ( V_69 ) ;
return NULL ;
}
return V_69 ;
}
int F_28 ( struct V_1 * V_9 )
{
struct V_2 * V_5 = & V_9 -> V_4 . V_5 ;
int V_75 ;
V_75 = F_7 ( V_9 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_29 ( & V_9 -> V_4 . V_5 ,
V_9 -> V_4 . V_19 . V_7 . V_8 ,
& V_76 ,
V_9 -> V_77 -> V_78 -> V_79 ,
V_80 ,
true ) ;
if ( V_75 ) {
F_9 ( L_5 , V_75 ) ;
return V_75 ;
}
V_75 = F_30 ( V_5 , V_40 ,
V_9 -> V_81 >> V_63 ) ;
if ( V_75 ) {
F_9 ( L_6 , V_75 ) ;
return V_75 ;
}
V_9 -> V_4 . V_82 = true ;
return 0 ;
}
void F_31 ( struct V_1 * V_9 )
{
if ( ! V_9 -> V_4 . V_82 )
return;
F_32 ( & V_9 -> V_4 . V_5 ) ;
F_11 ( V_9 ) ;
V_9 -> V_4 . V_82 = false ;
}
static void F_18 ( struct V_27 * V_28 , int V_83 )
{
unsigned V_84 ;
T_2 V_85 = 0 ;
V_28 -> V_51 . V_51 = V_28 -> V_86 ;
V_28 -> V_51 . V_87 = V_28 -> V_86 ;
if ( V_83 & V_88 ) {
V_28 -> V_86 [ V_85 ++ ] . V_34 = V_45
| V_44
| V_88 ;
}
if ( V_83 & V_50 ) {
V_28 -> V_86 [ V_85 ++ ] . V_34 = V_37
| V_50 ;
}
if ( ! V_85 ) {
V_28 -> V_86 [ V_85 ++ ] . V_34 = V_37
| V_50 ;
}
for ( V_84 = 0 ; V_84 < V_85 ; ++ V_84 ) {
V_28 -> V_86 [ V_84 ] . V_89 = 0 ;
V_28 -> V_86 [ V_84 ] . V_90 = 0 ;
}
V_28 -> V_51 . V_91 = V_85 ;
V_28 -> V_51 . V_92 = V_85 ;
}
static inline T_3 F_33 ( struct V_27 * V_28 )
{
return V_28 -> V_28 . V_61 ;
}
int F_34 ( struct V_27 * V_28 , T_2 V_93 , T_3 * V_94 )
{
int V_84 , V_75 ;
if ( V_28 -> V_95 ) {
V_28 -> V_95 ++ ;
if ( V_94 )
* V_94 = F_33 ( V_28 ) ;
return 0 ;
}
F_18 ( V_28 , V_93 ) ;
for ( V_84 = 0 ; V_84 < V_28 -> V_51 . V_91 ; V_84 ++ )
V_28 -> V_86 [ V_84 ] . V_34 |= V_96 ;
V_75 = F_35 ( & V_28 -> V_28 , & V_28 -> V_51 , false , false ) ;
if ( V_75 )
return V_75 ;
V_28 -> V_95 = 1 ;
if ( V_94 )
* V_94 = F_33 ( V_28 ) ;
return 0 ;
}
int F_36 ( struct V_27 * V_28 )
{
int V_84 , V_75 ;
if ( ! V_28 -> V_95 ) {
F_9 ( L_7 , V_28 ) ;
return 0 ;
}
V_28 -> V_95 -- ;
if ( V_28 -> V_95 )
return 0 ;
for ( V_84 = 0 ; V_84 < V_28 -> V_51 . V_91 ; V_84 ++ )
V_28 -> V_86 [ V_84 ] . V_34 &= ~ V_96 ;
V_75 = F_35 ( & V_28 -> V_28 , & V_28 -> V_51 , false , false ) ;
if ( V_75 )
return V_75 ;
return 0 ;
}
int F_37 ( struct V_52 * V_53 , struct V_97 * V_98 )
{
struct V_99 * V_100 ;
struct V_1 * V_9 ;
if ( F_38 ( V_98 -> V_101 < V_80 ) )
return - V_46 ;
V_100 = V_53 -> V_55 ;
V_9 = V_100 -> V_102 -> V_77 -> V_103 ;
return F_39 ( V_53 , V_98 , & V_9 -> V_4 . V_5 ) ;
}
static int F_40 ( struct V_104 * V_77 , int V_15 , int V_105 ,
T_1 V_34 , struct V_27 * * V_106 )
{
struct V_1 * V_9 = V_77 -> V_103 ;
struct V_27 * V_49 ;
T_4 V_107 ;
int V_75 ;
V_49 = F_26 ( sizeof( struct V_27 ) , V_73 ) ;
if ( ! V_49 )
return - V_108 ;
V_75 = F_41 ( V_77 , & V_49 -> V_29 , V_15 ) ;
if ( V_75 ) {
F_14 ( V_49 ) ;
return V_75 ;
}
V_49 -> V_28 . V_5 = & V_9 -> V_4 . V_5 ;
V_49 -> V_28 . V_5 -> V_109 = V_77 -> V_78 -> V_79 ;
F_18 ( V_49 , V_88 | V_50 ) ;
V_107 = F_42 ( & V_9 -> V_4 . V_5 , V_15 ,
sizeof( struct V_27 ) ) ;
V_75 = F_43 ( & V_9 -> V_4 . V_5 , & V_49 -> V_28 , V_15 ,
V_110 , & V_49 -> V_51 ,
V_105 >> V_63 , false , NULL , V_107 ,
NULL , NULL , F_12 ) ;
if ( V_75 )
return V_75 ;
* V_106 = V_49 ;
return 0 ;
}
int F_44 ( struct V_104 * V_77 , T_2 V_15 , bool V_111 ,
struct V_112 * * V_113 )
{
struct V_27 * V_49 ;
int V_75 ;
* V_113 = NULL ;
V_15 = F_45 ( V_15 ) ;
if ( V_15 == 0 )
return - V_46 ;
V_75 = F_40 ( V_77 , V_15 , 0 , 0 , & V_49 ) ;
if ( V_75 ) {
if ( V_75 != - V_114 )
F_9 ( L_8 ) ;
return V_75 ;
}
* V_113 = & V_49 -> V_29 ;
return 0 ;
}
int F_46 ( struct V_99 * V_52 , struct V_104 * V_77 ,
struct V_115 * args )
{
struct V_112 * V_116 ;
T_2 V_117 ;
int V_75 ;
args -> V_118 = args -> V_119 * ( ( args -> V_120 + 7 ) / 8 ) ;
args -> V_15 = args -> V_118 * args -> V_121 ;
V_75 = F_44 ( V_77 , args -> V_15 , false ,
& V_116 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_47 ( V_52 , V_116 , & V_117 ) ;
F_48 ( V_116 ) ;
if ( V_75 )
return V_75 ;
args -> V_117 = V_117 ;
return 0 ;
}
static void F_49 ( struct V_27 * * V_28 )
{
struct V_25 * V_26 ;
if ( ( * V_28 ) == NULL )
return;
V_26 = & ( ( * V_28 ) -> V_28 ) ;
F_50 ( & V_26 ) ;
* V_28 = NULL ;
}
void F_51 ( struct V_112 * V_113 )
{
struct V_27 * V_27 = F_52 ( V_113 ) ;
F_49 ( & V_27 ) ;
}
int F_53 ( struct V_99 * V_52 , struct V_104 * V_77 ,
T_1 V_117 , T_5 * V_61 )
{
struct V_112 * V_113 ;
struct V_27 * V_28 ;
V_113 = F_54 ( V_52 , V_117 ) ;
if ( V_113 == NULL )
return - V_122 ;
V_28 = F_52 ( V_113 ) ;
* V_61 = F_55 ( V_28 ) ;
F_48 ( V_113 ) ;
return 0 ;
}
static void F_56 ( struct V_123 * V_124 )
{
struct V_125 * V_126 = F_57 ( V_124 ) ;
F_48 ( V_126 -> V_113 ) ;
F_58 ( V_124 ) ;
F_14 ( V_124 ) ;
}
int F_59 ( struct V_104 * V_77 ,
struct V_125 * V_127 ,
const struct V_128 * V_129 ,
struct V_112 * V_113 )
{
int V_75 ;
F_60 ( V_77 , & V_127 -> V_64 , V_129 ) ;
V_127 -> V_113 = V_113 ;
V_75 = F_61 ( V_77 , & V_127 -> V_64 , & V_130 ) ;
if ( V_75 ) {
F_9 ( L_9 , V_75 ) ;
return V_75 ;
}
return 0 ;
}
static struct V_123 *
F_62 ( struct V_104 * V_77 ,
struct V_99 * V_53 ,
const struct V_128 * V_129 )
{
struct V_112 * V_113 ;
struct V_125 * V_126 ;
int V_75 ;
F_63 ( L_10 ,
V_129 -> V_119 , V_129 -> V_121 ,
( V_129 -> V_131 ) & 0xff ,
( V_129 -> V_131 >> 8 ) & 0xff ,
( V_129 -> V_131 >> 16 ) & 0xff ,
( V_129 -> V_131 >> 24 ) & 0xff ) ;
if ( V_129 -> V_131 != V_132 )
return F_64 ( - V_122 ) ;
V_113 = F_54 ( V_53 , V_129 -> V_133 [ 0 ] ) ;
if ( V_113 == NULL )
return F_64 ( - V_122 ) ;
V_126 = F_26 ( sizeof( * V_126 ) , V_73 ) ;
if ( ! V_126 ) {
F_48 ( V_113 ) ;
return F_64 ( - V_108 ) ;
}
V_75 = F_59 ( V_77 , V_126 , V_129 , V_113 ) ;
if ( V_75 ) {
F_48 ( V_113 ) ;
F_14 ( V_126 ) ;
return F_64 ( V_75 ) ;
}
return & V_126 -> V_64 ;
}

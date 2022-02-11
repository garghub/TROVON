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
return F_20 ( & V_49 -> V_29 . V_54 , V_53 ) ;
}
static int F_21 ( struct V_2 * V_5 ,
struct V_55 * V_56 )
{
struct V_31 * V_32 = & V_5 -> V_32 [ V_56 -> V_57 ] ;
struct V_1 * V_9 = F_1 ( V_5 ) ;
V_56 -> V_58 . V_59 = NULL ;
V_56 -> V_58 . V_60 = 0 ;
V_56 -> V_58 . V_15 = V_56 -> V_61 << V_62 ;
V_56 -> V_58 . V_63 = 0 ;
V_56 -> V_58 . V_64 = false ;
if ( ! ( V_32 -> V_34 & V_35 ) )
return - V_46 ;
switch ( V_56 -> V_57 ) {
case V_33 :
return 0 ;
case V_40 :
V_56 -> V_58 . V_60 = V_56 -> V_65 << V_62 ;
V_56 -> V_58 . V_63 = V_9 -> V_66 ;
V_56 -> V_58 . V_64 = true ;
break;
default:
return - V_46 ;
break;
}
return 0 ;
}
static void F_22 ( struct V_2 * V_5 ,
struct V_55 * V_56 )
{
}
static int F_23 ( struct V_25 * V_28 ,
bool V_67 , bool V_68 ,
bool V_69 ,
struct V_55 * V_70 )
{
return F_24 ( V_28 , V_67 , V_69 , V_70 ) ;
}
static void F_25 ( struct V_71 * V_72 )
{
F_26 ( V_72 ) ;
F_14 ( V_72 ) ;
}
static struct V_71 * F_27 ( struct V_2 * V_5 ,
unsigned long V_15 ,
T_1 V_73 ,
struct V_74 * V_75 )
{
struct V_71 * V_72 ;
V_72 = F_28 ( sizeof( struct V_71 ) , V_76 ) ;
if ( V_72 == NULL )
return NULL ;
V_72 -> V_41 = & V_77 ;
if ( F_29 ( V_72 , V_5 , V_15 , V_73 , V_75 ) ) {
F_14 ( V_72 ) ;
return NULL ;
}
return V_72 ;
}
int F_30 ( struct V_1 * V_9 )
{
struct V_2 * V_5 = & V_9 -> V_4 . V_5 ;
int V_78 ;
V_78 = F_7 ( V_9 ) ;
if ( V_78 )
return V_78 ;
V_78 = F_31 ( & V_9 -> V_4 . V_5 ,
V_9 -> V_4 . V_19 . V_7 . V_8 ,
& V_79 , V_80 ,
true ) ;
if ( V_78 ) {
F_9 ( L_5 , V_78 ) ;
return V_78 ;
}
V_78 = F_32 ( V_5 , V_40 ,
V_9 -> V_81 >> V_62 ) ;
if ( V_78 ) {
F_9 ( L_6 , V_78 ) ;
return V_78 ;
}
V_9 -> V_4 . V_82 = true ;
return 0 ;
}
void F_33 ( struct V_1 * V_9 )
{
if ( ! V_9 -> V_4 . V_82 )
return;
F_34 ( & V_9 -> V_4 . V_5 ) ;
F_11 ( V_9 ) ;
V_9 -> V_4 . V_82 = false ;
}
static void F_18 ( struct V_27 * V_28 , int V_83 )
{
T_2 V_84 = 0 ;
V_28 -> V_51 . V_85 = 0 ;
V_28 -> V_51 . V_86 = 0 ;
V_28 -> V_51 . V_51 = V_28 -> V_87 ;
V_28 -> V_51 . V_88 = V_28 -> V_87 ;
if ( V_83 & V_89 ) {
V_28 -> V_87 [ V_84 ++ ] = V_45 | V_44
| V_89 ;
}
if ( V_83 & V_50 ) {
V_28 -> V_87 [ V_84 ++ ] = V_37 | V_50 ;
}
if ( ! V_84 ) {
V_28 -> V_87 [ V_84 ++ ] = V_37 | V_50 ;
}
V_28 -> V_51 . V_90 = V_84 ;
V_28 -> V_51 . V_91 = V_84 ;
}
static inline T_3 F_35 ( struct V_27 * V_28 )
{
return V_28 -> V_28 . V_60 ;
}
int F_36 ( struct V_27 * V_28 , T_2 V_92 , T_3 * V_93 )
{
int V_94 , V_78 ;
if ( V_28 -> V_95 ) {
V_28 -> V_95 ++ ;
if ( V_93 )
* V_93 = F_35 ( V_28 ) ;
return 0 ;
}
F_18 ( V_28 , V_92 ) ;
for ( V_94 = 0 ; V_94 < V_28 -> V_51 . V_90 ; V_94 ++ )
V_28 -> V_87 [ V_94 ] |= V_96 ;
V_78 = F_37 ( & V_28 -> V_28 , & V_28 -> V_51 , false , false ) ;
if ( V_78 )
return V_78 ;
V_28 -> V_95 = 1 ;
if ( V_93 )
* V_93 = F_35 ( V_28 ) ;
return 0 ;
}
int F_38 ( struct V_27 * V_28 )
{
int V_94 , V_78 ;
if ( ! V_28 -> V_95 ) {
F_9 ( L_7 , V_28 ) ;
return 0 ;
}
V_28 -> V_95 -- ;
if ( V_28 -> V_95 )
return 0 ;
for ( V_94 = 0 ; V_94 < V_28 -> V_51 . V_90 ; V_94 ++ )
V_28 -> V_87 [ V_94 ] &= ~ V_96 ;
V_78 = F_37 ( & V_28 -> V_28 , & V_28 -> V_51 , false , false ) ;
if ( V_78 )
return V_78 ;
return 0 ;
}
int F_39 ( struct V_52 * V_53 , struct V_97 * V_98 )
{
struct V_99 * V_100 ;
struct V_1 * V_9 ;
if ( F_40 ( V_98 -> V_101 < V_80 ) )
return F_41 ( V_53 , V_98 ) ;
V_100 = V_53 -> V_102 ;
V_9 = V_100 -> V_103 -> V_104 -> V_105 ;
return F_42 ( V_53 , V_98 , & V_9 -> V_4 . V_5 ) ;
}
static int F_43 ( struct V_106 * V_104 , int V_15 , int V_107 ,
T_1 V_34 , struct V_27 * * V_108 )
{
struct V_1 * V_9 = V_104 -> V_105 ;
struct V_27 * V_49 ;
T_4 V_109 ;
int V_78 ;
V_49 = F_28 ( sizeof( struct V_27 ) , V_76 ) ;
if ( ! V_49 )
return - V_110 ;
V_78 = F_44 ( V_104 , & V_49 -> V_29 , V_15 ) ;
if ( V_78 ) {
F_14 ( V_49 ) ;
return V_78 ;
}
V_49 -> V_28 . V_5 = & V_9 -> V_4 . V_5 ;
V_49 -> V_28 . V_5 -> V_111 = V_104 -> V_111 ;
F_18 ( V_49 , V_89 | V_50 ) ;
V_109 = F_45 ( & V_9 -> V_4 . V_5 , V_15 ,
sizeof( struct V_27 ) ) ;
V_78 = F_46 ( & V_9 -> V_4 . V_5 , & V_49 -> V_28 , V_15 ,
V_112 , & V_49 -> V_51 ,
V_107 >> V_62 , false , NULL , V_109 ,
NULL , F_12 ) ;
if ( V_78 )
return V_78 ;
* V_108 = V_49 ;
return 0 ;
}
int F_47 ( struct V_106 * V_104 , T_2 V_15 , bool V_113 ,
struct V_114 * * V_115 )
{
struct V_27 * V_49 ;
int V_78 ;
* V_115 = NULL ;
V_15 = F_48 ( V_15 , V_116 ) ;
if ( V_15 == 0 )
return - V_46 ;
V_78 = F_43 ( V_104 , V_15 , 0 , 0 , & V_49 ) ;
if ( V_78 ) {
if ( V_78 != - V_117 )
F_9 ( L_8 ) ;
return V_78 ;
}
* V_115 = & V_49 -> V_29 ;
return 0 ;
}
int F_49 ( struct V_99 * V_52 , struct V_106 * V_104 ,
struct V_118 * args )
{
struct V_114 * V_119 ;
T_2 V_120 ;
int V_78 ;
args -> V_121 = args -> V_122 * ( ( args -> V_123 + 7 ) / 8 ) ;
args -> V_15 = args -> V_121 * args -> V_124 ;
V_78 = F_47 ( V_104 , args -> V_15 , false ,
& V_119 ) ;
if ( V_78 )
return V_78 ;
V_78 = F_50 ( V_52 , V_119 , & V_120 ) ;
F_51 ( V_119 ) ;
if ( V_78 )
return V_78 ;
args -> V_120 = V_120 ;
return 0 ;
}
static void F_52 ( struct V_27 * * V_28 )
{
struct V_25 * V_26 ;
if ( ( * V_28 ) == NULL )
return;
V_26 = & ( ( * V_28 ) -> V_28 ) ;
F_53 ( & V_26 ) ;
if ( V_26 == NULL )
* V_28 = NULL ;
}
void F_54 ( struct V_114 * V_115 )
{
struct V_27 * V_27 = F_55 ( V_115 ) ;
if ( ! V_27 )
return;
F_52 ( & V_27 ) ;
}
int F_56 ( struct V_99 * V_52 , struct V_106 * V_104 ,
T_1 V_120 , T_5 * V_60 )
{
struct V_114 * V_115 ;
int V_78 ;
struct V_27 * V_28 ;
F_57 ( & V_104 -> V_125 ) ;
V_115 = F_58 ( V_104 , V_52 , V_120 ) ;
if ( V_115 == NULL ) {
V_78 = - V_126 ;
goto V_127;
}
V_28 = F_55 ( V_115 ) ;
* V_60 = F_59 ( V_28 ) ;
F_60 ( V_115 ) ;
V_78 = 0 ;
V_127:
F_61 ( & V_104 -> V_125 ) ;
return V_78 ;
}
static void F_62 ( struct V_128 * V_129 )
{
struct V_130 * V_131 = F_63 ( V_129 ) ;
if ( V_131 -> V_115 )
F_51 ( V_131 -> V_115 ) ;
F_64 ( V_129 ) ;
F_14 ( V_129 ) ;
}
int F_65 ( struct V_106 * V_104 ,
struct V_130 * V_132 ,
struct V_133 * V_134 ,
struct V_114 * V_115 )
{
int V_78 ;
F_66 ( & V_132 -> V_63 , V_134 ) ;
V_132 -> V_115 = V_115 ;
V_78 = F_67 ( V_104 , & V_132 -> V_63 , & V_135 ) ;
if ( V_78 ) {
F_9 ( L_9 , V_78 ) ;
return V_78 ;
}
return 0 ;
}
static struct V_128 *
F_68 ( struct V_106 * V_104 ,
struct V_99 * V_53 ,
struct V_133 * V_134 )
{
struct V_114 * V_115 ;
struct V_130 * V_131 ;
int V_78 ;
F_69 ( L_10 ,
V_134 -> V_122 , V_134 -> V_124 ,
( V_134 -> V_136 ) & 0xff ,
( V_134 -> V_136 >> 8 ) & 0xff ,
( V_134 -> V_136 >> 16 ) & 0xff ,
( V_134 -> V_136 >> 24 ) & 0xff ) ;
if ( V_134 -> V_136 != V_137 )
return F_70 ( - V_126 ) ;
V_115 = F_58 ( V_104 , V_53 , V_134 -> V_138 [ 0 ] ) ;
if ( V_115 == NULL )
return F_70 ( - V_126 ) ;
V_131 = F_28 ( sizeof( * V_131 ) , V_76 ) ;
if ( ! V_131 ) {
F_51 ( V_115 ) ;
return F_70 ( - V_110 ) ;
}
V_78 = F_65 ( V_104 , V_131 , V_134 , V_115 ) ;
if ( V_78 ) {
F_51 ( V_115 ) ;
F_14 ( V_131 ) ;
return F_70 ( V_78 ) ;
}
return & V_131 -> V_63 ;
}

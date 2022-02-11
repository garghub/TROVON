static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_1 * V_6 ;
V_5 = F_2 ( V_3 , struct V_4 , V_3 ) ;
V_6 = F_2 ( V_5 , struct V_1 , V_5 ) ;
return V_6 ;
}
static int F_3 ( struct V_7 * V_8 )
{
return F_4 ( V_8 -> V_9 ) ;
}
static void F_5 ( struct V_7 * V_8 )
{
F_6 ( V_8 -> V_9 ) ;
}
static int F_7 ( struct V_1 * V_6 )
{
struct V_7 * V_10 ;
int V_11 ;
V_6 -> V_5 . V_12 = false ;
V_10 = & V_6 -> V_5 . V_13 ;
V_10 -> V_14 = V_15 ;
V_10 -> V_16 = sizeof( struct V_17 ) ;
V_10 -> V_18 = & F_3 ;
V_10 -> V_19 = & F_5 ;
V_11 = F_8 ( V_10 ) ;
if ( V_11 != 0 ) {
F_9 ( L_1
L_2 ) ;
return V_11 ;
}
V_6 -> V_5 . V_20 . V_21 =
V_6 -> V_5 . V_13 . V_9 ;
V_10 = & V_6 -> V_5 . V_20 . V_8 ;
V_10 -> V_14 = V_22 ;
V_10 -> V_16 = sizeof( struct V_23 ) ;
V_10 -> V_18 = & V_24 ;
V_10 -> V_19 = & V_25 ;
V_11 = F_8 ( V_10 ) ;
if ( V_11 != 0 ) {
F_9 ( L_3 ) ;
F_10 ( & V_6 -> V_5 . V_13 ) ;
return V_11 ;
}
V_6 -> V_5 . V_12 = true ;
return 0 ;
}
static void F_11 ( struct V_1 * V_6 )
{
if ( V_6 -> V_5 . V_12 ) {
F_10 ( & V_6 -> V_5 . V_20 . V_8 ) ;
F_10 ( & V_6 -> V_5 . V_13 ) ;
V_6 -> V_5 . V_12 = false ;
}
}
static int F_12 ( struct V_26 * V_27 , struct V_28 * V_29 )
{
struct V_30 * V_31 ;
int V_11 ;
V_31 = (struct V_30 * ) V_27 -> V_32 ;
if ( V_31 == NULL )
return V_33 ;
V_11 = V_34 -> V_35 ( V_27 , V_29 ) ;
return V_11 ;
}
int F_13 ( struct V_36 * V_37 , struct V_26 * V_27 )
{
struct V_38 * V_39 ;
struct V_1 * V_6 ;
int V_11 ;
if ( F_14 ( V_27 -> V_40 < V_41 ) ) {
F_15 ( L_4 ,
V_42 , V_27 -> V_40 ) ;
return - V_43 ;
}
V_39 = V_37 -> V_44 ;
V_6 = V_39 -> V_45 -> V_46 -> V_47 ;
if ( V_6 == NULL ) {
F_9 (
L_5 ) ;
return - V_43 ;
}
F_16 ( V_6 , L_6 ,
V_42 , V_37 -> V_44 , V_27 -> V_40 ) ;
V_11 = F_17 ( V_37 , V_27 , & V_6 -> V_5 . V_3 ) ;
if ( F_14 ( V_11 != 0 ) )
return V_11 ;
if ( F_14 ( V_34 == NULL ) ) {
V_34 = V_27 -> V_48 ;
V_49 = * V_34 ;
V_49 . V_35 = & F_12 ;
}
V_27 -> V_48 = & V_49 ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 , T_1 V_50 )
{
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , T_1 type ,
struct V_51 * V_52 )
{
switch ( type ) {
case V_53 :
V_52 -> V_50 = V_54 ;
V_52 -> V_55 = V_56 ;
V_52 -> V_57 = V_58 ;
break;
case V_59 :
case V_60 :
V_52 -> V_61 = & V_62 ;
V_52 -> V_63 = 0 ;
V_52 -> V_50 = V_64 |
V_54 ;
V_52 -> V_55 = V_56 ;
V_52 -> V_57 = V_58 ;
break;
default:
F_9 ( L_7 , ( unsigned ) type ) ;
return - V_43 ;
}
return 0 ;
}
static void F_20 ( struct V_30 * V_31 ,
struct V_65 * V_66 )
{
struct V_67 * V_68 ;
static struct V_69 V_70 = {
. V_71 = 0 ,
. V_72 = 0 ,
. V_50 = V_56 | V_73
} ;
if ( ! F_21 ( V_31 ) ) {
V_66 -> V_66 = & V_70 ;
V_66 -> V_74 = & V_70 ;
V_66 -> V_75 = 1 ;
V_66 -> V_76 = 1 ;
return;
}
V_68 = F_2 ( V_31 , struct V_67 , V_77 ) ;
F_22 ( V_68 , V_78 , false ) ;
* V_66 = V_68 -> V_66 ;
}
static int F_23 ( struct V_30 * V_31 , struct V_36 * V_37 )
{
struct V_67 * V_68 = F_24 ( V_31 ) ;
return F_25 ( & V_68 -> V_79 . V_80 , V_37 ) ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_81 * V_82 )
{
struct V_51 * V_52 = & V_3 -> V_52 [ V_82 -> V_83 ] ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_82 -> V_84 . V_85 = NULL ;
V_82 -> V_84 . V_86 = 0 ;
V_82 -> V_84 . V_16 = V_82 -> V_87 << V_88 ;
V_82 -> V_84 . V_89 = 0 ;
V_82 -> V_84 . V_90 = false ;
if ( ! ( V_52 -> V_50 & V_54 ) )
return - V_43 ;
switch ( V_82 -> V_83 ) {
case V_53 :
return 0 ;
case V_59 :
V_82 -> V_84 . V_90 = true ;
V_82 -> V_84 . V_89 = V_6 -> V_91 ;
V_82 -> V_84 . V_86 = V_82 -> V_92 << V_88 ;
break;
case V_60 :
V_82 -> V_84 . V_90 = true ;
V_82 -> V_84 . V_89 = V_6 -> V_93 ;
V_82 -> V_84 . V_86 = V_82 -> V_92 << V_88 ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static void F_27 ( struct V_2 * V_3 ,
struct V_81 * V_82 )
{
}
static int F_28 ( struct V_94 * V_95 ,
struct V_81 * V_96 )
{
struct V_97 * V_98 = ( void * ) V_95 ;
V_98 -> V_86 = ( unsigned long ) ( V_96 -> V_92 << V_88 ) ;
if ( ! V_95 -> V_87 ) {
F_29 ( 1 , L_8 ,
V_95 -> V_87 , V_96 , V_95 ) ;
}
return - 1 ;
}
static int F_30 ( struct V_94 * V_95 )
{
return - 1 ;
}
static void F_31 ( struct V_94 * V_95 )
{
struct V_97 * V_98 = ( void * ) V_95 ;
F_32 ( & V_98 -> V_95 ) ;
F_33 ( V_98 ) ;
}
static int F_34 ( struct V_94 * V_95 )
{
int V_11 ;
if ( V_95 -> V_99 != V_100 )
return 0 ;
V_11 = F_35 ( V_95 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static void F_36 ( struct V_94 * V_95 )
{
F_37 ( V_95 ) ;
}
static struct V_94 * F_38 ( struct V_2 * V_3 ,
unsigned long V_16 , T_1 V_101 ,
struct V_102 * V_103 )
{
struct V_1 * V_6 ;
struct V_97 * V_98 ;
V_6 = F_1 ( V_3 ) ;
V_98 = F_39 ( sizeof( struct V_97 ) , V_104 ) ;
if ( V_98 == NULL )
return NULL ;
V_98 -> V_95 . V_95 . V_61 = & V_105 ;
V_98 -> V_6 = V_6 ;
if ( F_40 ( & V_98 -> V_95 , V_3 , V_16 , V_101 ,
V_103 ) ) {
F_33 ( V_98 ) ;
return NULL ;
}
return & V_98 -> V_95 . V_95 ;
}
static void F_41 ( struct V_30 * V_31 ,
struct V_81 * V_106 )
{
struct V_81 * V_107 = & V_31 -> V_82 ;
F_42 ( V_107 -> V_108 != NULL ) ;
* V_107 = * V_106 ;
V_106 -> V_108 = NULL ;
}
static int F_43 ( struct V_30 * V_31 ,
bool V_109 , bool V_110 ,
bool V_111 ,
struct V_81 * V_106 )
{
struct V_81 * V_107 = & V_31 -> V_82 ;
if ( V_107 -> V_83 == V_53 && V_31 -> V_95 == NULL ) {
F_41 ( V_31 , V_106 ) ;
return 0 ;
}
return F_44 ( V_31 , V_109 , V_111 , V_106 ) ;
}
static void F_45 ( struct V_30 * V_31 ,
struct V_81 * V_106 )
{
struct V_67 * V_68 ;
struct V_1 * V_6 ;
if ( ! F_21 ( V_31 ) )
return;
V_68 = F_2 ( V_31 , struct V_67 , V_77 ) ;
V_6 = V_68 -> V_79 . V_46 -> V_47 ;
if ( V_31 -> V_82 . V_83 == V_60 && V_68 -> V_112 )
F_46 ( V_6 , V_68 , V_106 ? true : false ) ;
}
int F_47 ( struct V_1 * V_6 )
{
int V_11 ;
int V_113 ;
V_11 = F_7 ( V_6 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_48 ( & V_6 -> V_5 . V_3 ,
V_6 -> V_5 . V_20 . V_8 . V_9 ,
& V_114 ,
V_6 -> V_115 -> V_116 -> V_117 ,
V_41 , 0 ) ;
if ( V_11 ) {
F_9 ( L_9 , V_11 ) ;
return V_11 ;
}
V_113 = V_6 -> V_118 -> V_119 / V_120 ;
V_11 = F_49 ( & V_6 -> V_5 . V_3 , V_59 ,
V_113 ) ;
if ( V_11 ) {
F_9 ( L_10 ) ;
return V_11 ;
}
V_11 = F_49 ( & V_6 -> V_5 . V_3 , V_60 ,
V_6 -> V_121 / V_120 ) ;
if ( V_11 ) {
F_9 ( L_11 ) ;
return V_11 ;
}
F_50 ( L_12 ,
( unsigned ) V_6 -> V_122 / ( 1024 * 1024 ) ) ;
F_50 ( L_13 ,
( ( unsigned ) V_113 * V_120 ) / ( 1024 * 1024 ) ) ;
F_50 ( L_14 ,
( unsigned ) V_6 -> V_121 / ( 1024 * 1024 ) ) ;
V_11 = F_51 ( V_6 ) ;
if ( V_11 ) {
F_9 ( L_15 ) ;
return V_11 ;
}
return 0 ;
}
void F_52 ( struct V_1 * V_6 )
{
F_53 ( & V_6 -> V_5 . V_3 , V_59 ) ;
F_53 ( & V_6 -> V_5 . V_3 , V_60 ) ;
F_54 ( & V_6 -> V_5 . V_3 ) ;
F_11 ( V_6 ) ;
F_50 ( L_16 ) ;
}
static int F_55 ( struct V_123 * V_124 , void * V_125 )
{
struct V_126 * V_127 = (struct V_126 * ) V_124 -> V_128 ;
struct V_129 * V_130 = (struct V_129 * ) V_127 -> V_131 -> V_125 ;
struct V_132 * V_46 = V_127 -> V_45 -> V_46 ;
struct V_1 * V_133 = V_46 -> V_47 ;
int V_134 ;
struct V_23 * V_135 = V_133 -> V_5 . V_3 . V_135 ;
F_56 ( & V_135 -> V_136 ) ;
V_134 = F_57 ( V_124 , V_130 ) ;
F_58 ( & V_135 -> V_136 ) ;
return V_134 ;
}
static int F_51 ( struct V_1 * V_6 )
{
#if F_59 ( V_137 )
static struct V_138 V_139 [ V_140 ] ;
static char V_141 [ V_140 ] [ 32 ] ;
unsigned V_142 ;
for ( V_142 = 0 ; V_142 < V_140 ; V_142 ++ ) {
if ( V_142 == 0 )
sprintf ( V_141 [ V_142 ] , L_17 ) ;
else
sprintf ( V_141 [ V_142 ] , L_18 ) ;
V_139 [ V_142 ] . V_143 = V_141 [ V_142 ] ;
V_139 [ V_142 ] . V_144 = & F_55 ;
V_139 [ V_142 ] . V_145 = 0 ;
if ( V_142 == 0 )
V_139 [ V_142 ] . V_125 = V_6 -> V_5 . V_3 . V_52 [ V_59 ] . V_146 ;
else
V_139 [ V_142 ] . V_125 = V_6 -> V_5 . V_3 . V_52 [ V_60 ] . V_146 ;
}
return F_60 ( V_6 , V_139 , V_142 ) ;
#else
return 0 ;
#endif
}

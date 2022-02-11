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
V_68 = F_22 ( V_31 ) ;
F_23 ( V_68 , V_77 , false ) ;
* V_66 = V_68 -> V_66 ;
}
static int F_24 ( struct V_30 * V_31 , struct V_36 * V_37 )
{
struct V_67 * V_68 = F_22 ( V_31 ) ;
return F_25 ( & V_68 -> V_78 . V_79 , V_37 ) ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_80 * V_81 )
{
struct V_51 * V_52 = & V_3 -> V_52 [ V_81 -> V_82 ] ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
V_81 -> V_83 . V_84 = NULL ;
V_81 -> V_83 . V_85 = 0 ;
V_81 -> V_83 . V_16 = V_81 -> V_86 << V_87 ;
V_81 -> V_83 . V_88 = 0 ;
V_81 -> V_83 . V_89 = false ;
if ( ! ( V_52 -> V_50 & V_54 ) )
return - V_43 ;
switch ( V_81 -> V_82 ) {
case V_53 :
return 0 ;
case V_59 :
V_81 -> V_83 . V_89 = true ;
V_81 -> V_83 . V_88 = V_6 -> V_90 ;
V_81 -> V_83 . V_85 = V_81 -> V_91 << V_87 ;
break;
case V_60 :
V_81 -> V_83 . V_89 = true ;
V_81 -> V_83 . V_88 = V_6 -> V_92 ;
V_81 -> V_83 . V_85 = V_81 -> V_91 << V_87 ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static void F_27 ( struct V_2 * V_3 ,
struct V_80 * V_81 )
{
}
static int F_28 ( struct V_93 * V_94 ,
struct V_80 * V_95 )
{
struct V_96 * V_97 = ( void * ) V_94 ;
V_97 -> V_85 = ( unsigned long ) ( V_95 -> V_91 << V_87 ) ;
if ( ! V_94 -> V_86 ) {
F_29 ( 1 , L_8 ,
V_94 -> V_86 , V_95 , V_94 ) ;
}
return - 1 ;
}
static int F_30 ( struct V_93 * V_94 )
{
return - 1 ;
}
static void F_31 ( struct V_93 * V_94 )
{
struct V_96 * V_97 = ( void * ) V_94 ;
F_32 ( & V_97 -> V_94 ) ;
F_33 ( V_97 ) ;
}
static int F_34 ( struct V_93 * V_94 )
{
int V_11 ;
if ( V_94 -> V_98 != V_99 )
return 0 ;
V_11 = F_35 ( V_94 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static void F_36 ( struct V_93 * V_94 )
{
F_37 ( V_94 ) ;
}
static struct V_93 * F_38 ( struct V_2 * V_3 ,
unsigned long V_16 , T_1 V_100 ,
struct V_101 * V_102 )
{
struct V_1 * V_6 ;
struct V_96 * V_97 ;
V_6 = F_1 ( V_3 ) ;
V_97 = F_39 ( sizeof( struct V_96 ) , V_103 ) ;
if ( V_97 == NULL )
return NULL ;
V_97 -> V_94 . V_94 . V_61 = & V_104 ;
V_97 -> V_6 = V_6 ;
if ( F_40 ( & V_97 -> V_94 , V_3 , V_16 , V_100 ,
V_102 ) ) {
F_33 ( V_97 ) ;
return NULL ;
}
return & V_97 -> V_94 . V_94 ;
}
static void F_41 ( struct V_30 * V_31 ,
struct V_80 * V_105 )
{
struct V_80 * V_106 = & V_31 -> V_81 ;
F_42 ( V_106 -> V_107 != NULL ) ;
* V_106 = * V_105 ;
V_105 -> V_107 = NULL ;
}
static int F_43 ( struct V_30 * V_31 ,
bool V_108 , bool V_109 ,
bool V_110 ,
struct V_80 * V_105 )
{
struct V_80 * V_106 = & V_31 -> V_81 ;
int V_111 ;
V_111 = F_44 ( V_31 , V_109 , V_110 ) ;
if ( V_111 )
return V_111 ;
if ( V_106 -> V_82 == V_53 && V_31 -> V_94 == NULL ) {
F_41 ( V_31 , V_105 ) ;
return 0 ;
}
return F_45 ( V_31 , V_108 , V_109 ,
V_110 , V_105 ) ;
}
static void F_46 ( struct V_30 * V_31 ,
struct V_80 * V_105 )
{
struct V_67 * V_68 ;
struct V_1 * V_6 ;
if ( ! F_21 ( V_31 ) )
return;
V_68 = F_22 ( V_31 ) ;
V_6 = V_68 -> V_78 . V_46 -> V_47 ;
if ( V_31 -> V_81 . V_82 == V_60 && V_68 -> V_112 )
F_47 ( V_6 , V_68 , V_105 ? true : false ) ;
}
int F_48 ( struct V_1 * V_6 )
{
int V_11 ;
int V_113 ;
V_11 = F_7 ( V_6 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_49 ( & V_6 -> V_5 . V_3 ,
V_6 -> V_5 . V_20 . V_8 . V_9 ,
& V_114 ,
V_6 -> V_115 -> V_116 -> V_117 ,
V_41 , 0 ) ;
if ( V_11 ) {
F_9 ( L_9 , V_11 ) ;
return V_11 ;
}
V_113 = V_6 -> V_118 -> V_119 / V_120 ;
V_11 = F_50 ( & V_6 -> V_5 . V_3 , V_59 ,
V_113 ) ;
if ( V_11 ) {
F_9 ( L_10 ) ;
return V_11 ;
}
V_11 = F_50 ( & V_6 -> V_5 . V_3 , V_60 ,
V_6 -> V_121 / V_120 ) ;
if ( V_11 ) {
F_9 ( L_11 ) ;
return V_11 ;
}
F_51 ( L_12 ,
( unsigned ) V_6 -> V_122 / ( 1024 * 1024 ) ) ;
F_51 ( L_13 ,
( ( unsigned ) V_113 * V_120 ) / ( 1024 * 1024 ) ) ;
F_51 ( L_14 ,
( unsigned ) V_6 -> V_121 / ( 1024 * 1024 ) ) ;
V_11 = F_52 ( V_6 ) ;
if ( V_11 ) {
F_9 ( L_15 ) ;
return V_11 ;
}
return 0 ;
}
void F_53 ( struct V_1 * V_6 )
{
F_54 ( & V_6 -> V_5 . V_3 , V_59 ) ;
F_54 ( & V_6 -> V_5 . V_3 , V_60 ) ;
F_55 ( & V_6 -> V_5 . V_3 ) ;
F_11 ( V_6 ) ;
F_51 ( L_16 ) ;
}
static int F_56 ( struct V_123 * V_124 , void * V_125 )
{
struct V_126 * V_127 = (struct V_126 * ) V_124 -> V_128 ;
struct V_129 * V_130 = (struct V_129 * ) V_127 -> V_131 -> V_125 ;
struct V_132 * V_46 = V_127 -> V_45 -> V_46 ;
struct V_1 * V_133 = V_46 -> V_47 ;
int V_111 ;
struct V_23 * V_134 = V_133 -> V_5 . V_3 . V_134 ;
F_57 ( & V_134 -> V_135 ) ;
V_111 = F_58 ( V_124 , V_130 ) ;
F_59 ( & V_134 -> V_135 ) ;
return V_111 ;
}
static int F_52 ( struct V_1 * V_6 )
{
#if F_60 ( V_136 )
static struct V_137 V_138 [ V_139 ] ;
static char V_140 [ V_139 ] [ 32 ] ;
unsigned V_141 ;
for ( V_141 = 0 ; V_141 < V_139 ; V_141 ++ ) {
if ( V_141 == 0 )
sprintf ( V_140 [ V_141 ] , L_17 ) ;
else
sprintf ( V_140 [ V_141 ] , L_18 ) ;
V_138 [ V_141 ] . V_142 = V_140 [ V_141 ] ;
V_138 [ V_141 ] . V_143 = & F_56 ;
V_138 [ V_141 ] . V_144 = 0 ;
if ( V_141 == 0 )
V_138 [ V_141 ] . V_125 = V_6 -> V_5 . V_3 . V_52 [ V_59 ] . V_145 ;
else
V_138 [ V_141 ] . V_125 = V_6 -> V_5 . V_3 . V_52 [ V_60 ] . V_145 ;
}
return F_61 ( V_6 , V_138 , V_141 ) ;
#else
return 0 ;
#endif
}

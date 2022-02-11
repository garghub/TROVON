T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return F_3 ( V_3 -> V_4 ) ;
}
static int F_4 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
if ( V_6 -> V_9 )
return - V_10 ;
if ( ( V_6 -> V_11 & V_8 -> V_12 ) == 0 )
return - V_10 ;
V_8 -> V_13 = V_6 ;
V_6 -> V_9 = V_8 ;
return 0 ;
}
static void F_5 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
V_6 -> V_9 -> V_13 = NULL ;
V_6 -> V_9 = NULL ;
}
static void F_6 ( struct V_5 * V_6 )
{
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_3 * V_3 = V_14 [ V_6 -> V_12 ] ;
F_8 ( V_3 -> V_4 , & V_3 -> V_15 ) ;
F_9 ( V_3 -> V_4 ,
& V_3 -> V_16 ) ;
F_10 ( & V_3 -> V_17 , true ) ;
return 0 ;
}
static void F_11 ( struct V_5 * V_6 )
{
struct V_3 * V_3 = V_14 [ V_6 -> V_12 ] ;
F_10 ( & V_3 -> V_17 , false ) ;
}
static void F_12 ( struct V_5 * V_6 ,
const struct V_18 * V_16 )
{
struct V_3 * V_3 = V_14 [ V_6 -> V_12 ] ;
F_13 ( L_1 , V_3 -> V_19 ) ;
V_3 -> V_16 = * V_16 ;
V_3 -> V_20 = true ;
}
static void F_14 ( struct V_5 * V_6 ,
const struct V_21 * V_22 )
{
struct V_3 * V_3 = V_14 [ V_6 -> V_12 ] ;
F_13 ( L_1 , V_3 -> V_19 ) ;
F_15 ( V_3 -> V_4 , V_22 ) ;
}
static int F_16 (
struct V_5 * V_6 ,
void (* F_17)( void * ) , void * V_23 )
{
return 0 ;
}
static void F_18 (
struct V_5 * V_6 ,
void (* F_17)( void * ) , void * V_23 )
{
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_13 ( L_1 , V_3 -> V_19 ) ;
F_20 ( V_3 -> V_24 . V_25 ) ;
F_21 ( V_2 -> V_26 , & V_3 -> V_27 ) ;
F_22 ( V_2 ) ;
F_23 ( V_3 ) ;
}
static void F_24 ( struct V_1 * V_2 , int V_28 )
{
struct V_29 * V_30 = V_2 -> V_26 -> V_31 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
bool V_32 = ( V_28 == V_33 ) ;
int V_34 ;
F_13 ( L_2 , V_3 -> V_19 , V_28 ) ;
if ( V_32 != V_3 -> V_32 ) {
V_3 -> V_32 = V_32 ;
V_3 -> V_20 = true ;
F_25 ( V_2 , & V_3 -> V_35 ) ;
F_20 ( F_26 ( V_3 -> V_36 , V_28 ) ) ;
for ( V_34 = 0 ; V_34 < V_30 -> V_37 ; V_34 ++ ) {
struct V_38 * V_36 = V_30 -> V_39 [ V_34 ] ;
if ( V_36 -> V_2 == V_2 )
F_20 ( F_26 ( V_36 , V_28 ) ) ;
}
}
}
static bool F_27 ( struct V_1 * V_2 ,
const struct V_40 * V_28 ,
struct V_40 * V_41 )
{
return true ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_40 * V_28 ,
struct V_40 * V_41 ,
int V_42 , int V_43 ,
struct V_44 * V_45 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_28 = V_41 ;
F_13 ( L_3 ,
V_3 -> V_19 , V_28 -> V_17 . V_12 , V_28 -> V_19 ,
V_28 -> V_46 , V_28 -> clock ,
V_28 -> V_47 , V_28 -> V_48 ,
V_28 -> V_49 , V_28 -> V_50 ,
V_28 -> V_51 , V_28 -> V_52 ,
V_28 -> V_53 , V_28 -> V_54 ,
V_28 -> type , V_28 -> V_55 ) ;
F_29 ( & V_3 -> V_16 , V_28 ) ;
V_3 -> V_20 = true ;
return F_30 ( V_3 -> V_36 , V_2 , V_2 -> V_56 -> V_57 ,
0 , 0 , V_28 -> V_47 , V_28 -> V_51 ,
V_42 << 16 , V_43 << 16 ,
V_28 -> V_47 << 16 , V_28 -> V_51 << 16 ,
NULL , NULL ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_13 ( L_1 , V_3 -> V_19 ) ;
F_24 ( V_2 , V_58 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_13 ( L_1 , V_3 -> V_19 ) ;
F_24 ( V_2 , V_33 ) ;
}
static int F_33 ( struct V_1 * V_2 , int V_42 , int V_43 ,
struct V_44 * V_45 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_38 * V_36 = V_3 -> V_36 ;
struct V_40 * V_28 = & V_2 -> V_28 ;
return F_30 ( V_36 , V_2 , V_2 -> V_56 -> V_57 ,
0 , 0 , V_28 -> V_47 , V_28 -> V_51 ,
V_42 << 16 , V_43 << 16 ,
V_28 -> V_47 << 16 , V_28 -> V_51 << 16 ,
NULL , NULL ) ;
}
static void F_34 ( void * V_59 )
{
struct V_1 * V_2 = V_59 ;
struct V_60 * V_26 = V_2 -> V_26 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
unsigned long V_55 ;
F_35 ( & V_26 -> V_61 , V_55 ) ;
if ( V_3 -> V_62 )
F_36 ( V_26 , V_3 -> V_63 , V_3 -> V_62 ) ;
V_3 -> V_62 = NULL ;
V_3 -> V_45 = NULL ;
F_37 ( & V_26 -> V_61 , V_55 ) ;
}
static void F_38 ( struct V_64 * V_65 )
{
struct V_3 * V_3 =
F_39 ( V_65 , struct V_3 , V_66 ) ;
struct V_1 * V_2 = & V_3 -> V_17 ;
struct V_40 * V_28 = & V_2 -> V_28 ;
struct V_67 * V_68 ;
F_40 ( & V_2 -> V_69 ) ;
F_30 ( V_3 -> V_36 , V_2 , V_2 -> V_56 -> V_57 ,
0 , 0 , V_28 -> V_47 , V_28 -> V_51 ,
V_2 -> V_42 << 16 , V_2 -> V_43 << 16 ,
V_28 -> V_47 << 16 , V_28 -> V_51 << 16 ,
F_34 , V_2 ) ;
F_41 ( & V_2 -> V_69 ) ;
V_68 = F_42 ( V_2 -> V_56 -> V_57 , 0 ) ;
F_43 ( V_68 ) ;
}
static void F_44 ( void * V_59 )
{
struct V_1 * V_2 = V_59 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_29 * V_30 = V_2 -> V_26 -> V_31 ;
F_45 ( V_30 -> V_70 , & V_3 -> V_66 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_44 * V_57 ,
struct V_71 * V_62 ,
T_1 V_72 )
{
struct V_60 * V_26 = V_2 -> V_26 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_38 * V_56 = V_2 -> V_56 ;
struct V_67 * V_68 ;
unsigned long V_55 ;
F_13 ( L_4 , V_56 -> V_57 ? V_56 -> V_57 -> V_17 . V_12 : - 1 ,
V_57 -> V_17 . V_12 , V_62 ) ;
F_35 ( & V_26 -> V_61 , V_55 ) ;
if ( V_3 -> V_45 ) {
F_37 ( & V_26 -> V_61 , V_55 ) ;
F_47 ( V_26 -> V_26 , L_5 ) ;
return - V_10 ;
}
V_3 -> V_62 = V_62 ;
V_3 -> V_45 = V_56 -> V_57 = V_57 ;
F_37 ( & V_26 -> V_61 , V_55 ) ;
V_68 = F_42 ( V_57 , 0 ) ;
F_48 ( V_68 ) ;
F_49 ( V_68 , V_73 , F_44 , V_2 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_74 * V_75 , T_2 V_76 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_29 * V_30 = V_2 -> V_26 -> V_31 ;
if ( V_75 == V_30 -> V_77 ) {
V_2 -> V_78 =
! ! ( V_76 & ( ( 1LL << V_79 ) | ( 1LL << V_80 ) ) ) ;
}
return F_51 ( V_3 -> V_36 , V_75 , V_76 ) ;
}
const struct V_18 * F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return & V_3 -> V_16 ;
}
enum V_81 F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return V_3 -> V_4 ;
}
static void F_54 ( struct V_82 * V_83 , T_1 V_84 )
{
struct V_3 * V_3 =
F_39 ( V_83 , struct V_3 , V_27 ) ;
struct V_1 * V_2 = & V_3 -> V_17 ;
F_55 ( L_6 , V_3 -> V_19 , V_84 ) ;
F_56 ( V_2 -> V_26 , & V_3 -> V_27 ) ;
}
static void F_57 ( struct V_82 * V_83 , T_1 V_84 )
{
struct V_3 * V_3 =
F_39 ( V_83 , struct V_3 , V_24 ) ;
struct V_1 * V_2 = & V_3 -> V_17 ;
if ( ! V_3 -> V_27 . V_25 )
F_58 ( V_2 -> V_26 , & V_3 -> V_27 ) ;
if ( ! F_59 ( V_3 -> V_4 ) ) {
struct V_29 * V_30 =
V_2 -> V_26 -> V_31 ;
F_13 ( L_7 , V_3 -> V_19 ) ;
F_56 ( V_2 -> V_26 , & V_3 -> V_24 ) ;
F_45 ( V_30 -> V_70 , & V_3 -> V_85 ) ;
}
}
static void F_60 ( struct V_64 * V_65 )
{
struct V_3 * V_3 =
F_39 ( V_65 , struct V_3 , V_85 ) ;
struct V_1 * V_2 = & V_3 -> V_17 ;
struct V_60 * V_26 = V_2 -> V_26 ;
struct V_86 * V_35 , * V_87 ;
bool V_88 ;
F_40 ( & V_2 -> V_69 ) ;
F_61 () ;
if ( V_3 -> V_24 . V_25 )
goto V_89;
F_62 (apply, n,
&omap_crtc->pending_applies, pending_node) {
V_35 -> V_90 ( V_35 ) ;
F_63 ( & V_35 -> V_91 ) ;
}
V_88 = ! F_64 ( & V_3 -> V_92 ) ;
F_62 (apply, n,
&omap_crtc->queued_applies, queued_node) {
V_35 -> V_93 ( V_35 ) ;
F_63 ( & V_35 -> V_94 ) ;
V_35 -> V_95 = false ;
F_65 ( & V_35 -> V_91 ,
& V_3 -> V_96 ) ;
}
if ( V_88 ) {
enum V_81 V_4 = V_3 -> V_4 ;
F_13 ( L_8 , V_3 -> V_19 ) ;
if ( F_66 ( V_4 ) ) {
F_67 ( V_26 , & V_3 -> V_24 ) ;
F_68 ( V_4 ) ;
} else {
struct V_29 * V_30 = V_26 -> V_31 ;
F_45 ( V_30 -> V_70 , & V_3 -> V_85 ) ;
}
}
V_89:
F_69 () ;
F_41 ( & V_2 -> V_69 ) ;
}
int F_25 ( struct V_1 * V_2 ,
struct V_86 * V_35 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_20 ( ! F_70 ( & V_2 -> V_69 ) ) ;
if ( V_35 -> V_95 )
return 0 ;
V_35 -> V_95 = true ;
F_65 ( & V_35 -> V_94 , & V_3 -> V_92 ) ;
if ( F_64 ( & V_3 -> V_96 ) ) {
struct V_29 * V_30 = V_2 -> V_26 -> V_31 ;
F_45 ( V_30 -> V_70 , & V_3 -> V_85 ) ;
}
return 0 ;
}
static void F_10 ( struct V_1 * V_2 , bool V_97 )
{
struct V_60 * V_26 = V_2 -> V_26 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
enum V_81 V_4 = V_3 -> V_4 ;
struct V_98 * V_99 ;
T_3 V_100 , V_101 ;
int V_102 ;
if ( F_66 ( V_4 ) == V_97 )
return;
F_21 ( V_2 -> V_26 , & V_3 -> V_27 ) ;
V_100 = F_71 ( V_4 ) ;
V_101 = F_3 ( V_4 ) ;
if ( V_97 ) {
V_99 = F_72 ( V_26 , V_101 , 1 ) ;
} else {
if ( V_100 )
V_99 = F_72 ( V_26 , V_100 , 1 ) ;
else
V_99 = F_72 ( V_26 , V_101 , 2 ) ;
}
F_73 ( V_4 , V_97 ) ;
V_102 = V_98 ( V_26 , V_99 , F_74 ( 100 ) ) ;
if ( V_102 ) {
F_47 ( V_26 -> V_26 , L_9 ,
V_3 -> V_19 , V_97 ? L_10 : L_11 ) ;
}
F_67 ( V_2 -> V_26 , & V_3 -> V_27 ) ;
}
static void F_75 ( struct V_86 * V_35 )
{
struct V_3 * V_3 =
F_39 ( V_35 , struct V_3 , V_35 ) ;
struct V_1 * V_2 = & V_3 -> V_17 ;
struct V_103 * V_104 = NULL ;
F_13 ( L_12 , V_3 -> V_19 ,
V_3 -> V_32 , V_3 -> V_20 ) ;
if ( V_3 -> V_20 ) {
struct V_29 * V_30 = V_2 -> V_26 -> V_31 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_30 -> V_105 ; V_34 ++ ) {
if ( V_30 -> V_106 [ V_34 ] -> V_2 == V_2 ) {
V_104 = V_30 -> V_106 [ V_34 ] ;
break;
}
}
}
if ( V_3 -> V_107 && V_104 != V_3 -> V_107 )
F_76 ( V_3 -> V_107 , false ) ;
V_3 -> V_107 = V_104 ;
if ( ! V_3 -> V_32 ) {
if ( V_104 )
F_76 ( V_104 , false ) ;
} else {
if ( V_104 ) {
F_76 ( V_104 , false ) ;
F_77 ( V_104 , V_3 -> V_6 ,
& V_3 -> V_16 ) ;
F_76 ( V_104 , true ) ;
}
}
V_3 -> V_20 = false ;
}
static void F_78 ( struct V_86 * V_35 )
{
}
void F_79 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_108 = 0 ;
while ( ! F_64 ( & V_3 -> V_96 ) ||
! F_64 ( & V_3 -> V_92 ) ||
V_3 -> V_62 || V_3 -> V_45 ) {
if ( ++ V_108 > 10 ) {
F_47 ( V_2 -> V_26 -> V_26 ,
L_13 ) ;
break;
}
F_80 ( F_74 ( 20 ) ) ;
}
}
void F_81 ( void )
{
F_82 ( & V_109 ) ;
}
void F_83 ( void )
{
F_84 () ;
}
struct V_1 * F_85 ( struct V_60 * V_26 ,
struct V_38 * V_36 , enum V_81 V_4 , int V_12 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_3 ;
struct V_110 * V_15 ;
F_13 ( L_1 , V_111 [ V_4 ] ) ;
V_3 = F_86 ( sizeof( * V_3 ) , V_112 ) ;
if ( ! V_3 )
goto V_113;
V_2 = & V_3 -> V_17 ;
F_87 ( & V_3 -> V_66 , F_38 ) ;
F_87 ( & V_3 -> V_85 , F_60 ) ;
F_88 ( & V_3 -> V_96 ) ;
F_88 ( & V_3 -> V_92 ) ;
V_3 -> V_35 . V_93 = F_75 ;
V_3 -> V_35 . V_90 = F_78 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_36 = V_36 ;
V_3 -> V_36 -> V_2 = V_2 ;
V_3 -> V_19 = V_111 [ V_4 ] ;
V_3 -> V_63 = V_12 ;
V_3 -> V_24 . V_114 = F_1 ( V_2 ) ;
V_3 -> V_24 . V_83 = F_57 ;
V_3 -> V_27 . V_114 =
F_89 ( V_4 ) ;
V_3 -> V_27 . V_83 = F_54 ;
F_67 ( V_26 , & V_3 -> V_27 ) ;
V_3 -> V_6 = F_90 ( V_4 ) ;
V_15 = & V_3 -> V_15 ;
V_15 -> V_115 = 0x00000000 ;
V_15 -> V_116 = 0x00000000 ;
V_15 -> V_117 = V_118 ;
V_15 -> V_119 = false ;
F_91 ( V_26 , V_2 , & V_120 ) ;
F_92 ( V_2 , & V_121 ) ;
F_93 ( V_3 -> V_36 , & V_2 -> V_17 ) ;
V_14 [ V_4 ] = V_3 ;
return V_2 ;
V_113:
if ( V_2 )
F_19 ( V_2 ) ;
return NULL ;
}

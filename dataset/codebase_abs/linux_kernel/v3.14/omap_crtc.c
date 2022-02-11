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
return 0 ;
}
static void F_8 ( struct V_5 * V_6 )
{
}
static void F_9 ( struct V_5 * V_6 ,
const struct V_14 * V_15 )
{
struct V_3 * V_3 = V_16 [ V_6 -> V_12 ] ;
F_10 ( L_1 , V_3 -> V_17 ) ;
V_3 -> V_15 = * V_15 ;
V_3 -> V_18 = true ;
}
static void F_11 ( struct V_5 * V_6 ,
const struct V_19 * V_20 )
{
struct V_3 * V_3 = V_16 [ V_6 -> V_12 ] ;
F_10 ( L_1 , V_3 -> V_17 ) ;
F_12 ( V_3 -> V_4 , V_20 ) ;
}
static int F_13 (
struct V_5 * V_6 ,
void (* F_14)( void * ) , void * V_21 )
{
return 0 ;
}
static void F_15 (
struct V_5 * V_6 ,
void (* F_14)( void * ) , void * V_21 )
{
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_10 ( L_1 , V_3 -> V_17 ) ;
F_17 ( V_3 -> V_22 . V_23 ) ;
F_18 ( V_2 -> V_24 , & V_3 -> V_25 ) ;
V_3 -> V_26 -> V_27 -> V_28 ( V_3 -> V_26 ) ;
F_19 ( V_2 ) ;
F_20 ( V_3 ) ;
}
static void F_21 ( struct V_1 * V_2 , int V_29 )
{
struct V_30 * V_31 = V_2 -> V_24 -> V_32 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
bool V_33 = ( V_29 == V_34 ) ;
int V_35 ;
F_10 ( L_2 , V_3 -> V_17 , V_29 ) ;
if ( V_33 != V_3 -> V_33 ) {
V_3 -> V_33 = V_33 ;
V_3 -> V_18 = true ;
F_22 ( V_2 , & V_3 -> V_36 ) ;
F_17 ( F_23 ( V_3 -> V_26 , V_29 ) ) ;
for ( V_35 = 0 ; V_35 < V_31 -> V_37 ; V_35 ++ ) {
struct V_38 * V_26 = V_31 -> V_39 [ V_35 ] ;
if ( V_26 -> V_2 == V_2 )
F_17 ( F_23 ( V_26 , V_29 ) ) ;
}
}
}
static bool F_24 ( struct V_1 * V_2 ,
const struct V_40 * V_29 ,
struct V_40 * V_41 )
{
return true ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_40 * V_29 ,
struct V_40 * V_41 ,
int V_42 , int V_43 ,
struct V_44 * V_45 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_29 = V_41 ;
F_10 ( L_3 ,
V_3 -> V_17 , V_29 -> V_46 . V_12 , V_29 -> V_17 ,
V_29 -> V_47 , V_29 -> clock ,
V_29 -> V_48 , V_29 -> V_49 ,
V_29 -> V_50 , V_29 -> V_51 ,
V_29 -> V_52 , V_29 -> V_53 ,
V_29 -> V_54 , V_29 -> V_55 ,
V_29 -> type , V_29 -> V_56 ) ;
F_26 ( & V_3 -> V_15 , V_29 ) ;
V_3 -> V_18 = true ;
return F_27 ( V_3 -> V_26 , V_2 , V_2 -> V_57 ,
0 , 0 , V_29 -> V_48 , V_29 -> V_52 ,
V_42 << 16 , V_43 << 16 ,
V_29 -> V_48 << 16 , V_29 -> V_52 << 16 ,
NULL , NULL ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_10 ( L_1 , V_3 -> V_17 ) ;
F_21 ( V_2 , V_58 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_10 ( L_1 , V_3 -> V_17 ) ;
F_21 ( V_2 , V_34 ) ;
}
static int F_30 ( struct V_1 * V_2 , int V_42 , int V_43 ,
struct V_44 * V_45 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_38 * V_26 = V_3 -> V_26 ;
struct V_40 * V_29 = & V_2 -> V_29 ;
return F_27 ( V_26 , V_2 , V_2 -> V_57 ,
0 , 0 , V_29 -> V_48 , V_29 -> V_52 ,
V_42 << 16 , V_43 << 16 ,
V_29 -> V_48 << 16 , V_29 -> V_52 << 16 ,
NULL , NULL ) ;
}
static void F_31 ( void * V_59 )
{
struct V_1 * V_2 = V_59 ;
struct V_60 * V_24 = V_2 -> V_24 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
unsigned long V_56 ;
F_32 ( & V_24 -> V_61 , V_56 ) ;
if ( V_3 -> V_62 )
F_33 ( V_24 , V_3 -> V_63 , V_3 -> V_62 ) ;
V_3 -> V_62 = NULL ;
V_3 -> V_45 = NULL ;
F_34 ( & V_24 -> V_61 , V_56 ) ;
}
static void F_35 ( struct V_64 * V_65 )
{
struct V_3 * V_3 =
F_36 ( V_65 , struct V_3 , V_66 ) ;
struct V_1 * V_2 = & V_3 -> V_46 ;
struct V_40 * V_29 = & V_2 -> V_29 ;
struct V_67 * V_68 ;
F_37 ( & V_2 -> V_69 ) ;
F_27 ( V_3 -> V_26 , V_2 , V_2 -> V_57 ,
0 , 0 , V_29 -> V_48 , V_29 -> V_52 ,
V_2 -> V_42 << 16 , V_2 -> V_43 << 16 ,
V_29 -> V_48 << 16 , V_29 -> V_52 << 16 ,
F_31 , V_2 ) ;
F_38 ( & V_2 -> V_69 ) ;
V_68 = F_39 ( V_2 -> V_57 , 0 ) ;
F_40 ( V_68 ) ;
}
static void F_41 ( void * V_59 )
{
struct V_1 * V_2 = V_59 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_30 * V_31 = V_2 -> V_24 -> V_32 ;
F_42 ( V_31 -> V_70 , & V_3 -> V_66 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_44 * V_57 ,
struct V_71 * V_62 ,
T_1 V_72 )
{
struct V_60 * V_24 = V_2 -> V_24 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_67 * V_68 ;
F_10 ( L_4 , V_2 -> V_57 ? V_2 -> V_57 -> V_46 . V_12 : - 1 ,
V_57 -> V_46 . V_12 , V_62 ) ;
if ( V_3 -> V_45 ) {
F_44 ( V_24 -> V_24 , L_5 ) ;
return - V_10 ;
}
V_3 -> V_62 = V_62 ;
V_2 -> V_57 = V_57 ;
V_68 = F_39 ( V_57 , 0 ) ;
F_45 ( V_68 ) ;
F_46 ( V_68 , V_73 , F_41 , V_2 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_74 * V_75 , T_2 V_76 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_30 * V_31 = V_2 -> V_24 -> V_32 ;
if ( V_75 == V_31 -> V_77 ) {
V_2 -> V_78 =
! ! ( V_76 & ( ( 1LL << V_79 ) | ( 1LL << V_80 ) ) ) ;
}
return F_48 ( V_3 -> V_26 , V_75 , V_76 ) ;
}
const struct V_14 * F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return & V_3 -> V_15 ;
}
enum V_81 F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return V_3 -> V_4 ;
}
static void F_51 ( struct V_82 * V_83 , T_1 V_84 )
{
struct V_3 * V_3 =
F_36 ( V_83 , struct V_3 , V_25 ) ;
struct V_1 * V_2 = & V_3 -> V_46 ;
F_52 ( L_6 , V_3 -> V_17 , V_84 ) ;
F_53 ( V_2 -> V_24 , & V_3 -> V_25 ) ;
}
static void F_54 ( struct V_82 * V_83 , T_1 V_84 )
{
struct V_3 * V_3 =
F_36 ( V_83 , struct V_3 , V_22 ) ;
struct V_1 * V_2 = & V_3 -> V_46 ;
if ( ! V_3 -> V_25 . V_23 )
F_55 ( V_2 -> V_24 , & V_3 -> V_25 ) ;
if ( ! F_56 ( V_3 -> V_4 ) ) {
struct V_30 * V_31 =
V_2 -> V_24 -> V_32 ;
F_10 ( L_7 , V_3 -> V_17 ) ;
F_53 ( V_2 -> V_24 , & V_3 -> V_22 ) ;
F_42 ( V_31 -> V_70 , & V_3 -> V_85 ) ;
}
}
static void F_57 ( struct V_64 * V_65 )
{
struct V_3 * V_3 =
F_36 ( V_65 , struct V_3 , V_85 ) ;
struct V_1 * V_2 = & V_3 -> V_46 ;
struct V_60 * V_24 = V_2 -> V_24 ;
struct V_86 * V_36 , * V_87 ;
bool V_88 ;
F_37 ( & V_2 -> V_69 ) ;
F_58 () ;
if ( V_3 -> V_22 . V_23 )
goto V_89;
F_59 (apply, n,
&omap_crtc->pending_applies, pending_node) {
V_36 -> V_90 ( V_36 ) ;
F_60 ( & V_36 -> V_91 ) ;
}
V_88 = ! F_61 ( & V_3 -> V_92 ) ;
F_59 (apply, n,
&omap_crtc->queued_applies, queued_node) {
V_36 -> V_93 ( V_36 ) ;
F_60 ( & V_36 -> V_94 ) ;
V_36 -> V_95 = false ;
F_62 ( & V_36 -> V_91 ,
& V_3 -> V_96 ) ;
}
if ( V_88 ) {
enum V_81 V_4 = V_3 -> V_4 ;
F_10 ( L_8 , V_3 -> V_17 ) ;
if ( F_63 ( V_4 ) ) {
F_64 ( V_24 , & V_3 -> V_22 ) ;
F_65 ( V_4 ) ;
} else {
struct V_30 * V_31 = V_24 -> V_32 ;
F_42 ( V_31 -> V_70 , & V_3 -> V_85 ) ;
}
}
V_89:
F_66 () ;
F_38 ( & V_2 -> V_69 ) ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_86 * V_36 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_17 ( ! F_67 ( & V_2 -> V_69 ) ) ;
if ( V_36 -> V_95 )
return 0 ;
V_36 -> V_95 = true ;
F_62 ( & V_36 -> V_94 , & V_3 -> V_92 ) ;
if ( F_61 ( & V_3 -> V_96 ) ) {
struct V_30 * V_31 = V_2 -> V_24 -> V_32 ;
F_42 ( V_31 -> V_70 , & V_3 -> V_85 ) ;
}
return 0 ;
}
static void F_68 ( struct V_1 * V_2 , bool V_97 )
{
struct V_60 * V_24 = V_2 -> V_24 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
enum V_81 V_4 = V_3 -> V_4 ;
struct V_98 * V_99 = NULL ;
if ( F_63 ( V_4 ) == V_97 )
return;
F_18 ( V_2 -> V_24 , & V_3 -> V_25 ) ;
if ( F_69 ( V_4 ) ) {
if ( ! V_97 ) {
V_99 = F_70 ( V_24 ,
F_69 ( V_4 ) , 1 ) ;
}
} else {
V_99 = F_70 ( V_24 ,
F_3 ( V_4 ) , 2 ) ;
}
F_71 ( V_4 , V_97 ) ;
if ( V_99 ) {
int V_100 = V_98 ( V_24 , V_99 , F_72 ( 100 ) ) ;
if ( V_100 ) {
F_44 ( V_24 -> V_24 , L_9 ,
V_3 -> V_17 , V_97 ? L_10 : L_11 ) ;
}
}
F_64 ( V_2 -> V_24 , & V_3 -> V_25 ) ;
}
static void F_73 ( struct V_86 * V_36 )
{
struct V_3 * V_3 =
F_36 ( V_36 , struct V_3 , V_36 ) ;
struct V_1 * V_2 = & V_3 -> V_46 ;
struct V_101 * V_102 = NULL ;
F_10 ( L_12 , V_3 -> V_17 ,
V_3 -> V_33 , V_3 -> V_18 ) ;
if ( V_3 -> V_18 ) {
struct V_30 * V_31 = V_2 -> V_24 -> V_32 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_31 -> V_103 ; V_35 ++ ) {
if ( V_31 -> V_104 [ V_35 ] -> V_2 == V_2 ) {
V_102 = V_31 -> V_104 [ V_35 ] ;
break;
}
}
}
if ( ! V_3 -> V_33 ) {
F_68 ( & V_3 -> V_46 , false ) ;
if ( V_102 )
F_74 ( V_102 , false ) ;
} else {
if ( V_102 ) {
F_74 ( V_102 , false ) ;
F_75 ( V_102 , V_3 -> V_6 ,
& V_3 -> V_15 ) ;
F_74 ( V_102 , true ) ;
V_3 -> V_18 = false ;
}
F_76 ( V_3 -> V_4 , & V_3 -> V_105 ) ;
F_77 ( V_3 -> V_4 ,
& V_3 -> V_15 ) ;
F_68 ( & V_3 -> V_46 , true ) ;
}
V_3 -> V_18 = false ;
}
static void F_78 ( struct V_86 * V_36 )
{
}
void F_79 ( void )
{
F_80 ( & V_106 ) ;
}
void F_81 ( void )
{
F_82 () ;
}
struct V_1 * F_83 ( struct V_60 * V_24 ,
struct V_38 * V_26 , enum V_81 V_4 , int V_12 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_3 ;
struct V_107 * V_105 ;
F_10 ( L_1 , V_108 [ V_4 ] ) ;
V_3 = F_84 ( sizeof( * V_3 ) , V_109 ) ;
if ( ! V_3 )
goto V_110;
V_2 = & V_3 -> V_46 ;
F_85 ( & V_3 -> V_66 , F_35 ) ;
F_85 ( & V_3 -> V_85 , F_57 ) ;
F_86 ( & V_3 -> V_96 ) ;
F_86 ( & V_3 -> V_92 ) ;
V_3 -> V_36 . V_93 = F_73 ;
V_3 -> V_36 . V_90 = F_78 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_26 = V_26 ;
V_3 -> V_26 -> V_2 = V_2 ;
V_3 -> V_17 = V_108 [ V_4 ] ;
V_3 -> V_63 = V_12 ;
V_3 -> V_22 . V_111 = F_1 ( V_2 ) ;
V_3 -> V_22 . V_83 = F_54 ;
V_3 -> V_25 . V_111 =
F_87 ( V_4 ) ;
V_3 -> V_25 . V_83 = F_51 ;
F_64 ( V_24 , & V_3 -> V_25 ) ;
V_3 -> V_6 = F_88 ( V_4 ) ;
V_105 = & V_3 -> V_105 ;
V_105 -> V_112 = 0x00000000 ;
V_105 -> V_113 = 0x00000000 ;
V_105 -> V_114 = V_115 ;
V_105 -> V_116 = false ;
F_89 ( V_24 , V_2 , & V_117 ) ;
F_90 ( V_2 , & V_118 ) ;
F_91 ( V_3 -> V_26 , & V_2 -> V_46 ) ;
V_16 [ V_4 ] = V_3 ;
return V_2 ;
V_110:
if ( V_2 )
F_16 ( V_2 ) ;
return NULL ;
}

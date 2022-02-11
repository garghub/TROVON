T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return F_3 ( V_3 -> V_4 ) ;
}
static void F_4 ( struct V_5 * V_6 )
{
}
static int F_5 ( struct V_5 * V_6 )
{
return 0 ;
}
static void F_6 ( struct V_5 * V_6 )
{
}
static void F_7 ( struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
struct V_3 * V_3 = F_8 ( V_6 , struct V_3 , V_6 ) ;
F_9 ( L_1 , V_3 -> V_9 ) ;
V_3 -> V_8 = * V_8 ;
V_3 -> V_10 = true ;
}
static void F_10 ( struct V_5 * V_6 ,
const struct V_11 * V_12 )
{
struct V_3 * V_3 = F_8 ( V_6 , struct V_3 , V_6 ) ;
F_9 ( L_1 , V_3 -> V_9 ) ;
F_11 ( V_3 -> V_4 , V_12 ) ;
}
static int F_12 (
struct V_5 * V_6 ,
void (* F_13)( void * ) , void * V_13 )
{
return 0 ;
}
static void F_14 (
struct V_5 * V_6 ,
void (* F_13)( void * ) , void * V_13 )
{
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_9 ( L_1 , V_3 -> V_9 ) ;
F_16 ( V_3 -> V_14 . V_15 ) ;
F_17 ( V_2 -> V_16 , & V_3 -> V_17 ) ;
V_3 -> V_18 -> V_19 -> V_20 ( V_3 -> V_18 ) ;
F_18 ( V_2 ) ;
F_19 ( V_3 ) ;
}
static void F_20 ( struct V_1 * V_2 , int V_21 )
{
struct V_22 * V_23 = V_2 -> V_16 -> V_24 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
bool V_25 = ( V_21 == V_26 ) ;
int V_27 ;
F_9 ( L_2 , V_3 -> V_9 , V_21 ) ;
if ( V_25 != V_3 -> V_25 ) {
V_3 -> V_25 = V_25 ;
V_3 -> V_10 = true ;
F_21 ( V_2 , & V_3 -> V_28 ) ;
F_16 ( F_22 ( V_3 -> V_18 , V_21 ) ) ;
for ( V_27 = 0 ; V_27 < V_23 -> V_29 ; V_27 ++ ) {
struct V_30 * V_18 = V_23 -> V_31 [ V_27 ] ;
if ( V_18 -> V_2 == V_2 )
F_16 ( F_22 ( V_18 , V_21 ) ) ;
}
}
}
static bool F_23 ( struct V_1 * V_2 ,
const struct V_32 * V_21 ,
struct V_32 * V_33 )
{
return true ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_32 * V_21 ,
struct V_32 * V_33 ,
int V_34 , int V_35 ,
struct V_36 * V_37 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_21 = V_33 ;
F_9 ( L_3 ,
V_3 -> V_9 , V_21 -> V_38 . V_39 , V_21 -> V_9 ,
V_21 -> V_40 , V_21 -> clock ,
V_21 -> V_41 , V_21 -> V_42 ,
V_21 -> V_43 , V_21 -> V_44 ,
V_21 -> V_45 , V_21 -> V_46 ,
V_21 -> V_47 , V_21 -> V_48 ,
V_21 -> type , V_21 -> V_49 ) ;
F_25 ( & V_3 -> V_8 , V_21 ) ;
V_3 -> V_10 = true ;
return F_26 ( V_3 -> V_18 , V_2 , V_2 -> V_50 ,
0 , 0 , V_21 -> V_41 , V_21 -> V_45 ,
V_34 << 16 , V_35 << 16 ,
V_21 -> V_41 << 16 , V_21 -> V_45 << 16 ,
NULL , NULL ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_9 ( L_1 , V_3 -> V_9 ) ;
F_20 ( V_2 , V_51 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_9 ( L_1 , V_3 -> V_9 ) ;
F_20 ( V_2 , V_26 ) ;
}
static int F_29 ( struct V_1 * V_2 , int V_34 , int V_35 ,
struct V_36 * V_37 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_30 * V_18 = V_3 -> V_18 ;
struct V_32 * V_21 = & V_2 -> V_21 ;
return F_26 ( V_18 , V_2 , V_2 -> V_50 ,
0 , 0 , V_21 -> V_41 , V_21 -> V_45 ,
V_34 << 16 , V_35 << 16 ,
V_21 -> V_41 << 16 , V_21 -> V_45 << 16 ,
NULL , NULL ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
}
static void F_31 ( void * V_52 )
{
struct V_1 * V_2 = V_52 ;
struct V_53 * V_16 = V_2 -> V_16 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
unsigned long V_49 ;
F_32 ( & V_16 -> V_54 , V_49 ) ;
if ( V_3 -> V_55 )
F_33 ( V_16 , V_3 -> V_56 , V_3 -> V_55 ) ;
V_3 -> V_55 = NULL ;
V_3 -> V_37 = NULL ;
F_34 ( & V_16 -> V_54 , V_49 ) ;
}
static void F_35 ( struct V_57 * V_58 )
{
struct V_3 * V_3 =
F_8 ( V_58 , struct V_3 , V_59 ) ;
struct V_1 * V_2 = & V_3 -> V_38 ;
struct V_32 * V_21 = & V_2 -> V_21 ;
struct V_60 * V_61 ;
F_36 ( & V_2 -> V_62 ) ;
F_26 ( V_3 -> V_18 , V_2 , V_2 -> V_50 ,
0 , 0 , V_21 -> V_41 , V_21 -> V_45 ,
V_2 -> V_34 << 16 , V_2 -> V_35 << 16 ,
V_21 -> V_41 << 16 , V_21 -> V_45 << 16 ,
F_31 , V_2 ) ;
F_37 ( & V_2 -> V_62 ) ;
V_61 = F_38 ( V_2 -> V_50 , 0 ) ;
F_39 ( V_61 ) ;
}
static void F_40 ( void * V_52 )
{
struct V_1 * V_2 = V_52 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_22 * V_23 = V_2 -> V_16 -> V_24 ;
F_41 ( V_23 -> V_63 , & V_3 -> V_59 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_36 * V_50 ,
struct V_64 * V_55 )
{
struct V_53 * V_16 = V_2 -> V_16 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_60 * V_61 ;
F_9 ( L_4 , V_2 -> V_50 ? V_2 -> V_50 -> V_38 . V_39 : - 1 ,
V_50 -> V_38 . V_39 , V_55 ) ;
if ( V_3 -> V_37 ) {
F_43 ( V_16 -> V_16 , L_5 ) ;
return - V_65 ;
}
V_3 -> V_55 = V_55 ;
V_2 -> V_50 = V_50 ;
V_61 = F_38 ( V_50 , 0 ) ;
F_44 ( V_61 ) ;
F_45 ( V_61 , V_66 , F_40 , V_2 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_67 * V_68 , T_2 V_69 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_22 * V_23 = V_2 -> V_16 -> V_24 ;
if ( V_68 == V_23 -> V_70 ) {
V_2 -> V_71 =
! ! ( V_69 & ( ( 1LL << V_72 ) | ( 1LL << V_73 ) ) ) ;
}
return F_47 ( V_3 -> V_18 , V_68 , V_69 ) ;
}
const struct V_7 * F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return & V_3 -> V_8 ;
}
enum V_74 F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return V_3 -> V_4 ;
}
static void F_50 ( struct V_75 * V_76 , T_1 V_77 )
{
struct V_3 * V_3 =
F_8 ( V_76 , struct V_3 , V_17 ) ;
struct V_1 * V_2 = & V_3 -> V_38 ;
F_51 ( L_6 , V_3 -> V_9 , V_77 ) ;
F_17 ( V_2 -> V_16 , & V_3 -> V_17 ) ;
}
static void F_52 ( struct V_75 * V_76 , T_1 V_77 )
{
struct V_3 * V_3 =
F_8 ( V_76 , struct V_3 , V_14 ) ;
struct V_1 * V_2 = & V_3 -> V_38 ;
if ( ! V_3 -> V_17 . V_15 )
F_53 ( V_2 -> V_16 , & V_3 -> V_17 ) ;
if ( ! F_54 ( V_3 -> V_4 ) ) {
struct V_22 * V_23 =
V_2 -> V_16 -> V_24 ;
F_9 ( L_7 , V_3 -> V_9 ) ;
F_17 ( V_2 -> V_16 , & V_3 -> V_14 ) ;
F_41 ( V_23 -> V_63 , & V_3 -> V_78 ) ;
}
}
static void F_55 ( struct V_57 * V_58 )
{
struct V_3 * V_3 =
F_8 ( V_58 , struct V_3 , V_78 ) ;
struct V_1 * V_2 = & V_3 -> V_38 ;
struct V_53 * V_16 = V_2 -> V_16 ;
struct V_79 * V_28 , * V_80 ;
bool V_81 ;
F_36 ( & V_2 -> V_62 ) ;
F_56 () ;
if ( V_3 -> V_14 . V_15 )
goto V_82;
F_57 (apply, n,
&omap_crtc->pending_applies, pending_node) {
V_28 -> V_83 ( V_28 ) ;
F_58 ( & V_28 -> V_84 ) ;
}
V_81 = ! F_59 ( & V_3 -> V_85 ) ;
F_57 (apply, n,
&omap_crtc->queued_applies, queued_node) {
V_28 -> V_86 ( V_28 ) ;
F_58 ( & V_28 -> V_87 ) ;
V_28 -> V_88 = false ;
F_60 ( & V_28 -> V_84 ,
& V_3 -> V_89 ) ;
}
if ( V_81 ) {
enum V_74 V_4 = V_3 -> V_4 ;
F_9 ( L_8 , V_3 -> V_9 ) ;
if ( F_61 ( V_4 ) ) {
F_53 ( V_16 , & V_3 -> V_14 ) ;
F_62 ( V_4 ) ;
} else {
struct V_22 * V_23 = V_16 -> V_24 ;
F_41 ( V_23 -> V_63 , & V_3 -> V_78 ) ;
}
}
V_82:
F_63 () ;
F_37 ( & V_2 -> V_62 ) ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_79 * V_28 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_16 ( ! F_64 ( & V_2 -> V_62 ) ) ;
if ( V_28 -> V_88 )
return 0 ;
V_28 -> V_88 = true ;
F_60 ( & V_28 -> V_87 , & V_3 -> V_85 ) ;
if ( F_59 ( & V_3 -> V_89 ) ) {
struct V_22 * V_23 = V_2 -> V_16 -> V_24 ;
F_41 ( V_23 -> V_63 , & V_3 -> V_78 ) ;
}
return 0 ;
}
static void F_65 ( struct V_1 * V_2 , bool V_90 )
{
struct V_53 * V_16 = V_2 -> V_16 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
enum V_74 V_4 = V_3 -> V_4 ;
struct V_91 * V_92 = NULL ;
if ( F_61 ( V_4 ) == V_90 )
return;
F_17 ( V_2 -> V_16 , & V_3 -> V_17 ) ;
if ( F_66 ( V_4 ) ) {
if ( ! V_90 ) {
V_92 = F_67 ( V_16 ,
F_66 ( V_4 ) , 1 ) ;
}
} else {
V_92 = F_67 ( V_16 ,
F_3 ( V_4 ) , 2 ) ;
}
F_68 ( V_4 , V_90 ) ;
if ( V_92 ) {
int V_93 = V_91 ( V_16 , V_92 , F_69 ( 100 ) ) ;
if ( V_93 ) {
F_43 ( V_16 -> V_16 , L_9 ,
V_3 -> V_9 , V_90 ? L_10 : L_11 ) ;
}
}
F_53 ( V_2 -> V_16 , & V_3 -> V_17 ) ;
}
static void F_70 ( struct V_79 * V_28 )
{
struct V_3 * V_3 =
F_8 ( V_28 , struct V_3 , V_28 ) ;
struct V_1 * V_2 = & V_3 -> V_38 ;
struct V_94 * V_95 = NULL ;
F_9 ( L_12 , V_3 -> V_9 ,
V_3 -> V_25 , V_3 -> V_10 ) ;
if ( V_3 -> V_10 ) {
struct V_22 * V_23 = V_2 -> V_16 -> V_24 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_23 -> V_96 ; V_27 ++ ) {
if ( V_23 -> V_97 [ V_27 ] -> V_2 == V_2 ) {
V_95 = V_23 -> V_97 [ V_27 ] ;
break;
}
}
}
if ( ! V_3 -> V_25 ) {
F_65 ( & V_3 -> V_38 , false ) ;
if ( V_95 )
F_71 ( V_95 , false ) ;
} else {
if ( V_95 ) {
F_71 ( V_95 , false ) ;
F_72 ( V_95 , & V_3 -> V_6 ,
& V_3 -> V_8 ) ;
F_71 ( V_95 , true ) ;
V_3 -> V_10 = false ;
}
F_73 ( V_3 -> V_4 , & V_3 -> V_98 ) ;
F_74 ( V_3 -> V_4 ,
& V_3 -> V_8 ) ;
F_65 ( & V_3 -> V_38 , true ) ;
}
V_3 -> V_10 = false ;
}
static void F_75 ( struct V_79 * V_28 )
{
}
struct V_1 * F_76 ( struct V_53 * V_16 ,
struct V_30 * V_18 , enum V_74 V_4 , int V_39 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_3 ;
struct V_99 * V_98 ;
F_9 ( L_1 , V_100 [ V_4 ] ) ;
V_3 = F_77 ( sizeof( * V_3 ) , V_101 ) ;
if ( ! V_3 )
goto V_102;
V_2 = & V_3 -> V_38 ;
F_78 ( & V_3 -> V_59 , F_35 ) ;
F_78 ( & V_3 -> V_78 , F_55 ) ;
F_79 ( & V_3 -> V_89 ) ;
F_79 ( & V_3 -> V_85 ) ;
V_3 -> V_28 . V_86 = F_70 ;
V_3 -> V_28 . V_83 = F_75 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_18 = V_18 ;
V_3 -> V_18 -> V_2 = V_2 ;
V_3 -> V_9 = V_100 [ V_4 ] ;
V_3 -> V_56 = V_39 ;
V_3 -> V_14 . V_103 = F_1 ( V_2 ) ;
V_3 -> V_14 . V_76 = F_52 ;
V_3 -> V_17 . V_103 =
F_80 ( V_4 ) ;
V_3 -> V_17 . V_76 = F_50 ;
F_53 ( V_16 , & V_3 -> V_17 ) ;
V_3 -> V_6 . V_39 = V_4 ;
F_81 ( & V_104 ) ;
V_98 = & V_3 -> V_98 ;
V_98 -> V_105 = 0x00000000 ;
V_98 -> V_106 = 0x00000000 ;
V_98 -> V_107 = V_108 ;
V_98 -> V_109 = false ;
F_82 ( V_16 , V_2 , & V_110 ) ;
F_83 ( V_2 , & V_111 ) ;
F_84 ( V_3 -> V_18 , & V_2 -> V_38 ) ;
return V_2 ;
V_102:
if ( V_2 )
F_15 ( V_2 ) ;
return NULL ;
}

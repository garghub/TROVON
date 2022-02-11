static void F_1 ( struct V_1 * V_2 )
{
}
static int F_2 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
}
static void F_4 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_5 = F_5 ( V_2 , struct V_5 , V_2 ) ;
F_6 ( L_1 , V_5 -> V_6 ) ;
V_5 -> V_4 = * V_4 ;
V_5 -> V_7 = true ;
}
static void F_7 ( struct V_1 * V_2 ,
const struct V_8 * V_9 )
{
struct V_5 * V_5 = F_5 ( V_2 , struct V_5 , V_2 ) ;
F_6 ( L_1 , V_5 -> V_6 ) ;
F_8 ( V_5 -> V_10 , V_9 ) ;
}
static int F_9 (
struct V_1 * V_2 ,
void (* F_10)( void * ) , void * V_11 )
{
return 0 ;
}
static void F_11 (
struct V_1 * V_2 ,
void (* F_10)( void * ) , void * V_11 )
{
}
static void F_12 ( struct V_12 * V_13 )
{
struct V_5 * V_5 = F_13 ( V_13 ) ;
F_6 ( L_1 , V_5 -> V_6 ) ;
F_14 ( V_5 -> V_14 . V_15 ) ;
F_15 ( V_13 -> V_16 , & V_5 -> V_17 ) ;
V_5 -> V_18 -> V_19 -> V_20 ( V_5 -> V_18 ) ;
F_16 ( V_13 ) ;
F_17 ( V_5 ) ;
}
static void F_18 ( struct V_12 * V_13 , int V_21 )
{
struct V_22 * V_23 = V_13 -> V_16 -> V_24 ;
struct V_5 * V_5 = F_13 ( V_13 ) ;
bool V_25 = ( V_21 == V_26 ) ;
int V_27 ;
F_6 ( L_2 , V_5 -> V_6 , V_21 ) ;
if ( V_25 != V_5 -> V_25 ) {
V_5 -> V_25 = V_25 ;
V_5 -> V_7 = true ;
F_19 ( V_13 , & V_5 -> V_28 ) ;
F_14 ( F_20 ( V_5 -> V_18 , V_21 ) ) ;
for ( V_27 = 0 ; V_27 < V_23 -> V_29 ; V_27 ++ ) {
struct V_30 * V_18 = V_23 -> V_31 [ V_27 ] ;
if ( V_18 -> V_13 == V_13 )
F_14 ( F_20 ( V_18 , V_21 ) ) ;
}
}
}
static bool F_21 ( struct V_12 * V_13 ,
const struct V_32 * V_21 ,
struct V_32 * V_33 )
{
return true ;
}
static int F_22 ( struct V_12 * V_13 ,
struct V_32 * V_21 ,
struct V_32 * V_33 ,
int V_34 , int V_35 ,
struct V_36 * V_37 )
{
struct V_5 * V_5 = F_13 ( V_13 ) ;
V_21 = V_33 ;
F_6 ( L_3 ,
V_5 -> V_6 , V_21 -> V_38 . V_39 , V_21 -> V_6 ,
V_21 -> V_40 , V_21 -> clock ,
V_21 -> V_41 , V_21 -> V_42 ,
V_21 -> V_43 , V_21 -> V_44 ,
V_21 -> V_45 , V_21 -> V_46 ,
V_21 -> V_47 , V_21 -> V_48 ,
V_21 -> type , V_21 -> V_49 ) ;
F_23 ( & V_5 -> V_4 , V_21 ) ;
V_5 -> V_7 = true ;
return F_24 ( V_5 -> V_18 , V_13 , V_13 -> V_50 ,
0 , 0 , V_21 -> V_41 , V_21 -> V_45 ,
V_34 << 16 , V_35 << 16 ,
V_21 -> V_41 << 16 , V_21 -> V_45 << 16 ,
NULL , NULL ) ;
}
static void F_25 ( struct V_12 * V_13 )
{
struct V_5 * V_5 = F_13 ( V_13 ) ;
F_6 ( L_1 , V_5 -> V_6 ) ;
F_18 ( V_13 , V_51 ) ;
}
static void F_26 ( struct V_12 * V_13 )
{
struct V_5 * V_5 = F_13 ( V_13 ) ;
F_6 ( L_1 , V_5 -> V_6 ) ;
F_18 ( V_13 , V_26 ) ;
}
static int F_27 ( struct V_12 * V_13 , int V_34 , int V_35 ,
struct V_36 * V_37 )
{
struct V_5 * V_5 = F_13 ( V_13 ) ;
struct V_30 * V_18 = V_5 -> V_18 ;
struct V_32 * V_21 = & V_13 -> V_21 ;
return F_24 ( V_18 , V_13 , V_13 -> V_50 ,
0 , 0 , V_21 -> V_41 , V_21 -> V_45 ,
V_34 << 16 , V_35 << 16 ,
V_21 -> V_41 << 16 , V_21 -> V_45 << 16 ,
NULL , NULL ) ;
}
static void F_28 ( struct V_12 * V_13 )
{
}
static void F_29 ( void * V_52 )
{
struct V_12 * V_13 = V_52 ;
struct V_53 * V_16 = V_13 -> V_16 ;
struct V_5 * V_5 = F_13 ( V_13 ) ;
unsigned long V_49 ;
F_30 ( & V_16 -> V_54 , V_49 ) ;
if ( V_5 -> V_55 )
F_31 ( V_16 , V_5 -> V_56 , V_5 -> V_55 ) ;
V_5 -> V_55 = NULL ;
V_5 -> V_37 = NULL ;
F_32 ( & V_16 -> V_54 , V_49 ) ;
}
static void F_33 ( struct V_57 * V_58 )
{
struct V_5 * V_5 =
F_5 ( V_58 , struct V_5 , V_59 ) ;
struct V_12 * V_13 = & V_5 -> V_38 ;
struct V_53 * V_16 = V_13 -> V_16 ;
struct V_32 * V_21 = & V_13 -> V_21 ;
struct V_60 * V_61 ;
F_34 ( & V_16 -> V_62 . V_63 ) ;
F_24 ( V_5 -> V_18 , V_13 , V_13 -> V_50 ,
0 , 0 , V_21 -> V_41 , V_21 -> V_45 ,
V_13 -> V_34 << 16 , V_13 -> V_35 << 16 ,
V_21 -> V_41 << 16 , V_21 -> V_45 << 16 ,
F_29 , V_13 ) ;
F_35 ( & V_16 -> V_62 . V_63 ) ;
V_61 = F_36 ( V_13 -> V_50 , 0 ) ;
F_37 ( V_61 ) ;
}
static void F_38 ( void * V_52 )
{
struct V_12 * V_13 = V_52 ;
struct V_5 * V_5 = F_13 ( V_13 ) ;
struct V_22 * V_23 = V_13 -> V_16 -> V_24 ;
F_39 ( V_23 -> V_64 , & V_5 -> V_59 ) ;
}
static int F_40 ( struct V_12 * V_13 ,
struct V_36 * V_50 ,
struct V_65 * V_55 )
{
struct V_53 * V_16 = V_13 -> V_16 ;
struct V_5 * V_5 = F_13 ( V_13 ) ;
struct V_60 * V_61 ;
F_6 ( L_4 , V_13 -> V_50 ? V_13 -> V_50 -> V_38 . V_39 : - 1 ,
V_50 -> V_38 . V_39 , V_55 ) ;
if ( V_5 -> V_37 ) {
F_41 ( V_16 -> V_16 , L_5 ) ;
return - V_66 ;
}
V_5 -> V_55 = V_55 ;
V_13 -> V_50 = V_50 ;
V_61 = F_36 ( V_50 , 0 ) ;
F_42 ( V_61 ) ;
F_43 ( V_61 , V_67 , F_38 , V_13 ) ;
return 0 ;
}
static int F_44 ( struct V_12 * V_13 ,
struct V_68 * V_69 , T_1 V_70 )
{
struct V_5 * V_5 = F_13 ( V_13 ) ;
struct V_22 * V_23 = V_13 -> V_16 -> V_24 ;
if ( V_69 == V_23 -> V_71 ) {
V_13 -> V_72 =
! ! ( V_70 & ( ( 1LL << V_73 ) | ( 1LL << V_74 ) ) ) ;
}
return F_45 ( V_5 -> V_18 , V_69 , V_70 ) ;
}
const struct V_3 * F_46 ( struct V_12 * V_13 )
{
struct V_5 * V_5 = F_13 ( V_13 ) ;
return & V_5 -> V_4 ;
}
enum V_75 F_47 ( struct V_12 * V_13 )
{
struct V_5 * V_5 = F_13 ( V_13 ) ;
return V_5 -> V_10 ;
}
static void F_48 ( struct V_76 * V_77 , T_2 V_78 )
{
struct V_5 * V_5 =
F_5 ( V_77 , struct V_5 , V_17 ) ;
struct V_12 * V_13 = & V_5 -> V_38 ;
F_49 ( L_6 , V_5 -> V_6 , V_78 ) ;
F_15 ( V_13 -> V_16 , & V_5 -> V_17 ) ;
}
static void F_50 ( struct V_76 * V_77 , T_2 V_78 )
{
struct V_5 * V_5 =
F_5 ( V_77 , struct V_5 , V_14 ) ;
struct V_12 * V_13 = & V_5 -> V_38 ;
if ( ! V_5 -> V_17 . V_15 )
F_51 ( V_13 -> V_16 , & V_5 -> V_17 ) ;
if ( ! F_52 ( V_5 -> V_10 ) ) {
struct V_22 * V_23 =
V_13 -> V_16 -> V_24 ;
F_6 ( L_7 , V_5 -> V_6 ) ;
F_15 ( V_13 -> V_16 , & V_5 -> V_14 ) ;
F_39 ( V_23 -> V_64 , & V_5 -> V_79 ) ;
}
}
static void F_53 ( struct V_57 * V_58 )
{
struct V_5 * V_5 =
F_5 ( V_58 , struct V_5 , V_79 ) ;
struct V_12 * V_13 = & V_5 -> V_38 ;
struct V_53 * V_16 = V_13 -> V_16 ;
struct V_80 * V_28 , * V_81 ;
bool V_82 ;
F_34 ( & V_16 -> V_62 . V_63 ) ;
F_54 () ;
if ( V_5 -> V_14 . V_15 )
goto V_83;
F_55 (apply, n,
&omap_crtc->pending_applies, pending_node) {
V_28 -> V_84 ( V_28 ) ;
F_56 ( & V_28 -> V_85 ) ;
}
V_82 = ! F_57 ( & V_5 -> V_86 ) ;
F_55 (apply, n,
&omap_crtc->queued_applies, queued_node) {
V_28 -> V_87 ( V_28 ) ;
F_56 ( & V_28 -> V_88 ) ;
V_28 -> V_89 = false ;
F_58 ( & V_28 -> V_85 ,
& V_5 -> V_90 ) ;
}
if ( V_82 ) {
enum V_75 V_10 = V_5 -> V_10 ;
F_6 ( L_8 , V_5 -> V_6 ) ;
if ( F_59 ( V_10 ) ) {
F_51 ( V_16 , & V_5 -> V_14 ) ;
F_60 ( V_10 ) ;
} else {
struct V_22 * V_23 = V_16 -> V_24 ;
F_39 ( V_23 -> V_64 , & V_5 -> V_79 ) ;
}
}
V_83:
F_61 () ;
F_35 ( & V_16 -> V_62 . V_63 ) ;
}
int F_19 ( struct V_12 * V_13 ,
struct V_80 * V_28 )
{
struct V_5 * V_5 = F_13 ( V_13 ) ;
struct V_53 * V_16 = V_13 -> V_16 ;
F_14 ( ! F_62 ( & V_16 -> V_62 . V_63 ) ) ;
if ( V_28 -> V_89 )
return 0 ;
V_28 -> V_89 = true ;
F_58 ( & V_28 -> V_88 , & V_5 -> V_86 ) ;
if ( F_57 ( & V_5 -> V_90 ) ) {
struct V_22 * V_23 = V_13 -> V_16 -> V_24 ;
F_39 ( V_23 -> V_64 , & V_5 -> V_79 ) ;
}
return 0 ;
}
static void F_63 ( struct V_12 * V_13 , bool V_91 )
{
struct V_53 * V_16 = V_13 -> V_16 ;
struct V_5 * V_5 = F_13 ( V_13 ) ;
enum V_75 V_10 = V_5 -> V_10 ;
struct V_92 * V_93 = NULL ;
if ( F_59 ( V_10 ) == V_91 )
return;
F_15 ( V_13 -> V_16 , & V_5 -> V_17 ) ;
if ( F_64 ( V_10 ) ) {
if ( ! V_91 ) {
V_93 = F_65 ( V_16 ,
F_64 ( V_10 ) , 1 ) ;
}
} else {
V_93 = F_65 ( V_16 ,
F_66 ( V_10 ) , 2 ) ;
}
F_67 ( V_10 , V_91 ) ;
if ( V_93 ) {
int V_94 = V_92 ( V_16 , V_93 , F_68 ( 100 ) ) ;
if ( V_94 ) {
F_41 ( V_16 -> V_16 , L_9 ,
V_5 -> V_6 , V_91 ? L_10 : L_11 ) ;
}
}
F_51 ( V_13 -> V_16 , & V_5 -> V_17 ) ;
}
static void F_69 ( struct V_80 * V_28 )
{
struct V_5 * V_5 =
F_5 ( V_28 , struct V_5 , V_28 ) ;
struct V_12 * V_13 = & V_5 -> V_38 ;
struct V_95 * V_96 = NULL ;
F_6 ( L_12 , V_5 -> V_6 ,
V_5 -> V_25 , V_5 -> V_7 ) ;
if ( V_5 -> V_7 ) {
struct V_22 * V_23 = V_13 -> V_16 -> V_24 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_23 -> V_97 ; V_27 ++ ) {
if ( V_23 -> V_98 [ V_27 ] -> V_13 == V_13 ) {
V_96 = V_23 -> V_98 [ V_27 ] ;
break;
}
}
}
if ( ! V_5 -> V_25 ) {
F_63 ( & V_5 -> V_38 , false ) ;
if ( V_96 )
F_70 ( V_96 , false ) ;
} else {
if ( V_96 ) {
F_70 ( V_96 , false ) ;
F_71 ( V_96 , & V_5 -> V_2 ,
& V_5 -> V_4 ) ;
F_70 ( V_96 , true ) ;
V_5 -> V_7 = false ;
}
F_72 ( V_5 -> V_10 , & V_5 -> V_99 ) ;
F_73 ( V_5 -> V_10 ,
& V_5 -> V_4 ) ;
F_63 ( & V_5 -> V_38 , true ) ;
}
V_5 -> V_7 = false ;
}
static void F_74 ( struct V_80 * V_28 )
{
}
struct V_12 * F_75 ( struct V_53 * V_16 ,
struct V_30 * V_18 , enum V_75 V_10 , int V_39 )
{
struct V_12 * V_13 = NULL ;
struct V_5 * V_5 ;
struct V_100 * V_99 ;
F_6 ( L_1 , V_101 [ V_10 ] ) ;
V_5 = F_76 ( sizeof( * V_5 ) , V_102 ) ;
if ( ! V_5 ) {
F_41 ( V_16 -> V_16 , L_13 ) ;
goto V_103;
}
V_13 = & V_5 -> V_38 ;
F_77 ( & V_5 -> V_59 , F_33 ) ;
F_77 ( & V_5 -> V_79 , F_53 ) ;
F_78 ( & V_5 -> V_90 ) ;
F_78 ( & V_5 -> V_86 ) ;
V_5 -> V_28 . V_87 = F_69 ;
V_5 -> V_28 . V_84 = F_74 ;
V_5 -> V_14 . V_104 = F_79 ( V_39 ) ;
V_5 -> V_14 . V_77 = F_50 ;
V_5 -> V_17 . V_104 =
F_80 ( V_10 ) ;
V_5 -> V_17 . V_77 = F_48 ;
F_51 ( V_16 , & V_5 -> V_17 ) ;
V_5 -> V_10 = V_10 ;
V_5 -> V_18 = V_18 ;
V_5 -> V_18 -> V_13 = V_13 ;
V_5 -> V_6 = V_101 [ V_10 ] ;
V_5 -> V_56 = V_39 ;
V_5 -> V_2 . V_39 = V_10 ;
F_81 ( & V_105 ) ;
V_99 = & V_5 -> V_99 ;
V_99 -> V_106 = 0x00000000 ;
V_99 -> V_107 = 0x00000000 ;
V_99 -> V_108 = V_109 ;
V_99 -> V_110 = false ;
F_82 ( V_16 , V_13 , & V_111 ) ;
F_83 ( V_13 , & V_112 ) ;
F_84 ( V_5 -> V_18 , & V_13 -> V_38 ) ;
return V_13 ;
V_103:
if ( V_13 )
F_12 ( V_13 ) ;
return NULL ;
}

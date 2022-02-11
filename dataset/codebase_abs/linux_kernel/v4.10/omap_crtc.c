T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return F_3 ( V_3 -> V_4 ) ;
}
struct V_5 * F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return & V_3 -> V_6 ;
}
enum V_7 F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return V_3 -> V_4 ;
}
int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return F_7 ( V_3 -> V_8 ,
! V_3 -> V_9 ,
F_8 ( 250 ) ) ;
}
static int F_9 ( enum V_7 V_4 ,
struct V_10 * V_11 )
{
if ( V_12 [ V_4 ] )
return - V_13 ;
if ( ( F_10 ( V_4 ) & V_11 -> V_14 ) == 0 )
return - V_13 ;
V_12 [ V_4 ] = V_11 ;
V_11 -> V_15 = true ;
return 0 ;
}
static void F_11 ( enum V_7 V_4 ,
struct V_10 * V_11 )
{
V_12 [ V_4 ] = NULL ;
V_11 -> V_15 = false ;
}
static void F_12 ( enum V_7 V_4 )
{
}
static void F_13 ( struct V_1 * V_2 , bool V_16 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
enum V_7 V_4 = V_3 -> V_4 ;
struct V_19 * V_20 ;
T_2 V_21 , V_22 ;
int V_23 ;
if ( V_12 [ V_4 ] -> V_24 == V_25 ) {
F_14 ( V_4 , V_16 ) ;
return;
}
if ( F_15 ( V_4 ) == V_16 )
return;
if ( V_3 -> V_4 == V_26 ) {
V_3 -> V_27 = true ;
}
V_21 = F_16 ( V_4 ) ;
V_22 = F_3 ( V_4 ) ;
if ( V_16 ) {
V_20 = F_17 ( V_18 , V_22 , 1 ) ;
} else {
if ( V_21 )
V_20 = F_17 ( V_18 , V_21 , 1 ) ;
else
V_20 = F_17 ( V_18 , V_22 , 2 ) ;
}
F_14 ( V_4 , V_16 ) ;
V_23 = V_19 ( V_18 , V_20 , F_8 ( 100 ) ) ;
if ( V_23 ) {
F_18 ( V_18 -> V_18 , L_1 ,
V_3 -> V_28 , V_16 ? L_2 : L_3 ) ;
}
if ( V_3 -> V_4 == V_26 ) {
V_3 -> V_27 = false ;
F_19 () ;
}
}
static int F_20 ( enum V_7 V_4 )
{
struct V_3 * V_3 = V_29 [ V_4 ] ;
struct V_30 V_31 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_32 = 0x00000000 ;
V_31 . V_33 = 0x00000000 ;
V_31 . V_34 = V_35 ;
V_31 . V_36 = false ;
F_21 ( V_3 -> V_4 , & V_31 ) ;
F_22 ( V_3 -> V_4 ,
& V_3 -> V_6 ) ;
F_13 ( & V_3 -> V_37 , true ) ;
return 0 ;
}
static void F_23 ( enum V_7 V_4 )
{
struct V_3 * V_3 = V_29 [ V_4 ] ;
F_13 ( & V_3 -> V_37 , false ) ;
}
static void F_24 ( enum V_7 V_4 ,
const struct V_5 * V_6 )
{
struct V_3 * V_3 = V_29 [ V_4 ] ;
F_25 ( L_4 , V_3 -> V_28 ) ;
V_3 -> V_6 = * V_6 ;
}
static void F_26 ( enum V_7 V_4 ,
const struct V_38 * V_39 )
{
struct V_3 * V_3 = V_29 [ V_4 ] ;
F_25 ( L_4 , V_3 -> V_28 ) ;
F_27 ( V_3 -> V_4 , V_39 ) ;
}
static int F_28 (
enum V_7 V_4 ,
void (* F_29)( void * ) , void * V_40 )
{
return 0 ;
}
static void F_30 (
enum V_7 V_4 ,
void (* F_29)( void * ) , void * V_40 )
{
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_41 * V_42 ;
struct V_17 * V_18 = V_2 -> V_18 ;
unsigned long V_43 ;
V_42 = V_2 -> V_44 -> V_42 ;
if ( ! V_42 )
return;
F_32 ( & V_18 -> V_45 , V_43 ) ;
F_33 ( V_2 , V_42 ) ;
F_34 ( & V_18 -> V_45 , V_43 ) ;
}
static void F_35 ( struct V_46 * V_47 , T_1 V_48 )
{
struct V_3 * V_3 =
F_36 ( V_47 , struct V_3 , V_49 ) ;
if ( V_3 -> V_27 ) {
V_48 &= ~ V_50 ;
if ( ! V_48 )
return;
}
F_37 ( L_5 , V_3 -> V_28 , V_48 ) ;
}
static void F_38 ( struct V_46 * V_47 , T_1 V_48 )
{
struct V_3 * V_3 =
F_36 ( V_47 , struct V_3 , V_51 ) ;
struct V_17 * V_18 = V_3 -> V_37 . V_18 ;
if ( F_39 ( V_3 -> V_4 ) )
return;
F_25 ( L_6 , V_3 -> V_28 ) ;
F_40 ( V_18 , & V_3 -> V_51 ) ;
F_41 () ;
F_42 ( ! V_3 -> V_9 ) ;
V_3 -> V_9 = false ;
F_43 () ;
F_31 ( & V_3 -> V_37 ) ;
F_44 ( & V_3 -> V_8 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_25 ( L_4 , V_3 -> V_28 ) ;
F_42 ( V_3 -> V_51 . V_52 ) ;
F_46 ( V_2 -> V_18 , & V_3 -> V_49 ) ;
F_47 ( V_2 ) ;
F_48 ( V_3 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_25 ( L_4 , V_3 -> V_28 ) ;
F_41 () ;
F_42 ( V_3 -> V_9 ) ;
V_3 -> V_9 = true ;
F_43 () ;
F_50 ( V_2 -> V_18 , & V_3 -> V_51 ) ;
F_51 ( V_2 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_25 ( L_4 , V_3 -> V_28 ) ;
F_53 ( V_2 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_53 * V_54 = & V_2 -> V_44 -> V_55 ;
F_25 ( L_7 ,
V_3 -> V_28 , V_54 -> V_37 . V_14 , V_54 -> V_28 ,
V_54 -> V_56 , V_54 -> clock ,
V_54 -> V_57 , V_54 -> V_58 , V_54 -> V_59 , V_54 -> V_60 ,
V_54 -> V_61 , V_54 -> V_62 , V_54 -> V_63 , V_54 -> V_64 ,
V_54 -> type , V_54 -> V_43 ) ;
F_55 ( V_54 , & V_3 -> V_6 ) ;
V_3 -> V_6 . V_43 |= V_65 |
V_66 |
V_67 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_68 * V_44 )
{
if ( V_44 -> V_69 && V_44 -> V_70 ) {
T_3 V_71 = V_44 -> V_70 -> V_71 /
sizeof( struct V_72 ) ;
if ( V_71 < 2 )
return - V_13 ;
}
return 0 ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_68 * V_73 )
{
}
static void F_58 ( struct V_1 * V_2 ,
struct V_68 * V_73 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_42 ( V_3 -> V_51 . V_52 ) ;
if ( V_2 -> V_44 -> V_69 ) {
struct V_72 * V_74 = NULL ;
T_3 V_71 = 0 ;
if ( V_2 -> V_44 -> V_70 ) {
V_74 = (struct V_72 * )
V_2 -> V_44 -> V_70 -> V_40 ;
V_71 = V_2 -> V_44 -> V_70 -> V_71 /
sizeof( * V_74 ) ;
}
F_59 ( V_3 -> V_4 , V_74 , V_71 ) ;
}
if ( F_15 ( V_3 -> V_4 ) ) {
F_25 ( L_8 , V_3 -> V_28 ) ;
F_41 () ;
F_42 ( V_3 -> V_9 ) ;
V_3 -> V_9 = true ;
F_43 () ;
F_60 ( V_3 -> V_4 ) ;
F_50 ( V_2 -> V_18 , & V_3 -> V_51 ) ;
}
}
static bool F_61 ( struct V_1 * V_2 ,
struct V_75 * V_76 )
{
struct V_17 * V_18 = V_2 -> V_18 ;
struct V_77 * V_78 = V_18 -> V_79 ;
return V_76 == V_78 -> V_80 ||
V_76 == V_2 -> V_81 -> V_82 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_68 * V_44 ,
struct V_75 * V_76 ,
T_4 V_83 )
{
if ( F_61 ( V_2 , V_76 ) ) {
struct V_84 * V_85 ;
struct V_86 * V_87 = V_2 -> V_81 ;
V_85 = F_63 ( V_44 -> V_44 , V_87 ) ;
if ( F_64 ( V_85 ) )
return F_65 ( V_85 ) ;
return F_66 ( V_87 , V_85 ,
V_76 , V_83 ) ;
}
return - V_13 ;
}
static int F_67 ( struct V_1 * V_2 ,
const struct V_68 * V_44 ,
struct V_75 * V_76 ,
T_4 * V_83 )
{
if ( F_61 ( V_2 , V_76 ) ) {
return F_68 ( & V_2 -> V_81 -> V_37 ,
V_76 , V_83 ) ;
}
return - V_13 ;
}
void F_69 ( void )
{
F_70 ( & V_88 ) ;
}
void F_71 ( void )
{
F_72 () ;
}
struct V_1 * F_73 ( struct V_17 * V_18 ,
struct V_86 * V_87 , enum V_7 V_4 , int V_14 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_3 ;
int V_23 ;
F_25 ( L_4 , V_89 [ V_4 ] ) ;
V_3 = F_74 ( sizeof( * V_3 ) , V_90 ) ;
if ( ! V_3 )
return NULL ;
V_2 = & V_3 -> V_37 ;
F_75 ( & V_3 -> V_8 ) ;
V_3 -> V_4 = V_4 ;
V_3 -> V_28 = V_89 [ V_4 ] ;
V_3 -> V_51 . V_91 = F_1 ( V_2 ) ;
V_3 -> V_51 . V_47 = F_38 ;
V_3 -> V_49 . V_91 =
F_76 ( V_4 ) ;
V_3 -> V_49 . V_47 = F_35 ;
F_50 ( V_18 , & V_3 -> V_49 ) ;
V_23 = F_77 ( V_18 , V_2 , V_87 , NULL ,
& V_92 , NULL ) ;
if ( V_23 < 0 ) {
F_48 ( V_3 ) ;
return NULL ;
}
F_78 ( V_2 , & V_93 ) ;
if ( F_79 ( V_4 ) ) {
T_3 V_94 = 256 ;
F_80 ( V_2 , 0 , false , V_94 ) ;
F_81 ( V_2 , V_94 ) ;
}
F_82 ( V_2 -> V_81 , & V_2 -> V_37 ) ;
V_29 [ V_4 ] = V_3 ;
return V_2 ;
}

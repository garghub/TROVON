struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
return & V_4 -> V_5 ;
}
enum V_6 F_3 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
return V_4 -> V_7 ;
}
static bool F_4 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
unsigned long V_8 ;
bool V_9 ;
F_5 ( & V_3 -> V_10 -> V_11 , V_8 ) ;
V_9 = V_4 -> V_9 ;
F_6 ( & V_3 -> V_10 -> V_11 , V_8 ) ;
return V_9 ;
}
int F_7 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
return F_8 ( V_4 -> V_12 ,
! F_4 ( V_3 ) ,
F_9 ( 250 ) ) ;
}
static int F_10 ( enum V_6 V_7 ,
struct V_13 * V_14 )
{
if ( V_15 [ V_7 ] )
return - V_16 ;
if ( ( F_11 ( V_7 ) & V_14 -> V_17 ) == 0 )
return - V_16 ;
V_15 [ V_7 ] = V_14 ;
V_14 -> V_18 = true ;
return 0 ;
}
static void F_12 ( enum V_6 V_7 ,
struct V_13 * V_14 )
{
V_15 [ V_7 ] = NULL ;
V_14 -> V_18 = false ;
}
static void F_13 ( enum V_6 V_7 )
{
}
static void F_14 ( struct V_2 * V_3 , bool V_19 )
{
struct V_20 * V_10 = V_3 -> V_10 ;
struct V_4 * V_4 = F_2 ( V_3 ) ;
enum V_6 V_7 = V_4 -> V_7 ;
struct V_21 * V_22 ;
T_1 V_23 , V_24 ;
int V_25 ;
if ( F_15 ( V_4 -> V_26 == V_19 ) )
return;
if ( V_15 [ V_7 ] -> V_27 == V_28 ) {
F_16 ( V_7 , V_19 ) ;
V_4 -> V_26 = V_19 ;
return;
}
if ( V_4 -> V_7 == V_29 ) {
V_4 -> V_30 = true ;
}
V_23 = F_17 ( V_7 ) ;
V_24 = F_18 ( V_7 ) ;
if ( V_19 ) {
V_22 = F_19 ( V_10 , V_24 , 1 ) ;
} else {
if ( V_23 )
V_22 = F_19 ( V_10 , V_23 , 1 ) ;
else
V_22 = F_19 ( V_10 , V_24 , 2 ) ;
}
F_16 ( V_7 , V_19 ) ;
V_4 -> V_26 = V_19 ;
V_25 = V_21 ( V_10 , V_22 , F_9 ( 100 ) ) ;
if ( V_25 ) {
F_20 ( V_10 -> V_10 , L_1 ,
V_4 -> V_31 , V_19 ? L_2 : L_3 ) ;
}
if ( V_4 -> V_7 == V_29 ) {
V_4 -> V_30 = false ;
F_21 () ;
}
}
static int F_22 ( enum V_6 V_7 )
{
struct V_4 * V_4 = V_32 [ V_7 ] ;
struct V_33 V_34 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_35 = 0x00000000 ;
V_34 . V_36 = 0x00000000 ;
V_34 . V_37 = V_38 ;
V_34 . V_39 = false ;
F_23 ( V_4 -> V_7 , & V_34 ) ;
F_24 ( V_4 -> V_7 ,
& V_4 -> V_5 ) ;
F_14 ( & V_4 -> V_40 , true ) ;
return 0 ;
}
static void F_25 ( enum V_6 V_7 )
{
struct V_4 * V_4 = V_32 [ V_7 ] ;
F_14 ( & V_4 -> V_40 , false ) ;
}
static void F_26 ( enum V_6 V_7 ,
const struct V_1 * V_5 )
{
struct V_4 * V_4 = V_32 [ V_7 ] ;
F_27 ( L_4 , V_4 -> V_31 ) ;
V_4 -> V_5 = * V_5 ;
}
static void F_28 ( enum V_6 V_7 ,
const struct V_41 * V_42 )
{
struct V_4 * V_4 = V_32 [ V_7 ] ;
F_27 ( L_4 , V_4 -> V_31 ) ;
F_29 ( V_4 -> V_7 , V_42 ) ;
}
static int F_30 (
enum V_6 V_7 ,
void (* F_31)( void * ) , void * V_43 )
{
return 0 ;
}
static void F_32 (
enum V_6 V_7 ,
void (* F_31)( void * ) , void * V_43 )
{
}
void F_33 ( struct V_2 * V_3 , T_2 V_44 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
if ( V_4 -> V_30 ) {
V_44 &= ~ V_45 ;
if ( ! V_44 )
return;
}
F_34 ( L_5 , V_4 -> V_31 , V_44 ) ;
}
void F_35 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
bool V_9 ;
F_36 ( & V_3 -> V_10 -> V_11 ) ;
if ( F_37 ( V_4 -> V_7 ) ) {
F_38 ( & V_3 -> V_10 -> V_11 ) ;
return;
}
if ( V_4 -> V_46 ) {
F_39 ( V_3 , V_4 -> V_46 ) ;
V_4 -> V_46 = NULL ;
}
V_9 = V_4 -> V_9 ;
V_4 -> V_9 = false ;
F_38 ( & V_3 -> V_10 -> V_11 ) ;
if ( V_9 )
F_40 ( V_3 ) ;
F_41 ( & V_4 -> V_12 ) ;
F_27 ( L_6 , V_4 -> V_31 ) ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
F_27 ( L_4 , V_4 -> V_31 ) ;
F_43 ( V_3 ) ;
F_44 ( V_4 ) ;
}
static void F_45 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
int V_25 ;
F_27 ( L_4 , V_4 -> V_31 ) ;
F_46 ( & V_3 -> V_10 -> V_11 ) ;
F_47 ( V_3 ) ;
V_25 = F_48 ( V_3 ) ;
F_15 ( V_25 != 0 ) ;
F_15 ( V_4 -> V_9 ) ;
V_4 -> V_9 = true ;
F_49 ( & V_3 -> V_10 -> V_11 ) ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
F_27 ( L_4 , V_4 -> V_31 ) ;
F_51 ( V_3 ) ;
}
static void F_52 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
struct V_47 * V_48 = & V_3 -> V_49 -> V_50 ;
F_27 ( L_7 ,
V_4 -> V_31 , V_48 -> V_40 . V_17 , V_48 -> V_31 ,
V_48 -> V_51 , V_48 -> clock ,
V_48 -> V_52 , V_48 -> V_53 , V_48 -> V_54 , V_48 -> V_55 ,
V_48 -> V_56 , V_48 -> V_57 , V_48 -> V_58 , V_48 -> V_59 ,
V_48 -> type , V_48 -> V_8 ) ;
F_53 ( V_48 , & V_4 -> V_5 ) ;
V_4 -> V_5 . V_8 |= V_60 |
V_61 |
V_62 ;
}
static int F_54 ( struct V_2 * V_3 ,
struct V_63 * V_49 )
{
if ( V_49 -> V_64 && V_49 -> V_65 ) {
T_3 V_66 = V_49 -> V_65 -> V_66 /
sizeof( struct V_67 ) ;
if ( V_66 < 2 )
return - V_16 ;
}
return 0 ;
}
static void F_55 ( struct V_2 * V_3 ,
struct V_63 * V_68 )
{
}
static void F_56 ( struct V_2 * V_3 ,
struct V_63 * V_68 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
int V_25 ;
if ( V_3 -> V_49 -> V_64 ) {
struct V_67 * V_69 = NULL ;
T_3 V_66 = 0 ;
if ( V_3 -> V_49 -> V_65 ) {
V_69 = (struct V_67 * )
V_3 -> V_49 -> V_65 -> V_43 ;
V_66 = V_3 -> V_49 -> V_65 -> V_66 /
sizeof( * V_69 ) ;
}
F_57 ( V_4 -> V_7 , V_69 , V_66 ) ;
}
if ( ! V_4 -> V_26 )
return;
F_27 ( L_8 , V_4 -> V_31 ) ;
V_25 = F_48 ( V_3 ) ;
F_15 ( V_25 != 0 ) ;
F_46 ( & V_3 -> V_10 -> V_11 ) ;
F_58 ( V_4 -> V_7 ) ;
F_15 ( V_4 -> V_9 ) ;
V_4 -> V_9 = true ;
if ( V_3 -> V_49 -> V_46 )
V_4 -> V_46 = V_3 -> V_49 -> V_46 ;
F_49 ( & V_3 -> V_10 -> V_11 ) ;
}
static bool F_59 ( struct V_2 * V_3 ,
struct V_70 * V_71 )
{
struct V_20 * V_10 = V_3 -> V_10 ;
struct V_72 * V_73 = V_10 -> V_74 ;
return V_71 == V_73 -> V_75 ||
V_71 == V_3 -> V_76 -> V_77 ;
}
static int F_60 ( struct V_2 * V_3 ,
struct V_63 * V_49 ,
struct V_70 * V_71 ,
T_4 V_78 )
{
if ( F_59 ( V_3 , V_71 ) ) {
struct V_79 * V_80 ;
struct V_81 * V_82 = V_3 -> V_76 ;
V_80 = F_61 ( V_49 -> V_49 , V_82 ) ;
if ( F_62 ( V_80 ) )
return F_63 ( V_80 ) ;
return F_64 ( V_82 , V_80 ,
V_71 , V_78 ) ;
}
return - V_16 ;
}
static int F_65 ( struct V_2 * V_3 ,
const struct V_63 * V_49 ,
struct V_70 * V_71 ,
T_4 * V_78 )
{
if ( F_59 ( V_3 , V_71 ) ) {
return F_66 ( & V_3 -> V_76 -> V_40 ,
V_71 , V_78 ) ;
}
return - V_16 ;
}
void F_67 ( void )
{
F_68 ( & V_83 ) ;
}
void F_69 ( void )
{
F_70 () ;
}
struct V_2 * F_71 ( struct V_20 * V_10 ,
struct V_81 * V_82 , enum V_6 V_7 , int V_17 )
{
struct V_2 * V_3 = NULL ;
struct V_4 * V_4 ;
int V_25 ;
F_27 ( L_4 , V_84 [ V_7 ] ) ;
V_4 = F_72 ( sizeof( * V_4 ) , V_85 ) ;
if ( ! V_4 )
return NULL ;
V_3 = & V_4 -> V_40 ;
F_73 ( & V_4 -> V_12 ) ;
V_4 -> V_7 = V_7 ;
V_4 -> V_31 = V_84 [ V_7 ] ;
V_25 = F_74 ( V_10 , V_3 , V_82 , NULL ,
& V_86 , NULL ) ;
if ( V_25 < 0 ) {
F_44 ( V_4 ) ;
return NULL ;
}
F_75 ( V_3 , & V_87 ) ;
if ( F_76 ( V_7 ) ) {
T_3 V_88 = 256 ;
F_77 ( V_3 , 0 , false , V_88 ) ;
F_78 ( V_3 , V_88 ) ;
}
F_79 ( V_3 -> V_76 , & V_3 -> V_40 ) ;
V_32 [ V_7 ] = V_4 ;
return V_3 ;
}

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
const struct V_15 * V_15 = F_11 () ;
if ( V_16 [ V_7 ] )
return - V_17 ;
if ( ( V_15 -> V_18 ( V_7 ) & V_14 -> V_19 ) == 0 )
return - V_17 ;
V_16 [ V_7 ] = V_14 ;
V_14 -> V_20 = true ;
return 0 ;
}
static void F_12 ( enum V_6 V_7 ,
struct V_13 * V_14 )
{
V_16 [ V_7 ] = NULL ;
V_14 -> V_20 = false ;
}
static void F_13 ( enum V_6 V_7 )
{
}
static void F_14 ( struct V_2 * V_3 , bool V_21 )
{
struct V_22 * V_10 = V_3 -> V_10 ;
struct V_23 * V_24 = V_10 -> V_25 ;
struct V_4 * V_4 = F_2 ( V_3 ) ;
enum V_6 V_7 = V_4 -> V_7 ;
struct V_26 * V_27 ;
T_1 V_28 , V_29 ;
int V_30 ;
if ( F_15 ( V_4 -> V_31 == V_21 ) )
return;
if ( V_16 [ V_7 ] -> V_32 == V_33 ) {
V_24 -> V_15 -> V_34 ( V_7 , V_21 ) ;
V_4 -> V_31 = V_21 ;
return;
}
if ( V_4 -> V_7 == V_35 ) {
V_4 -> V_36 = true ;
}
V_28 = V_24 -> V_15 -> V_37 ( V_7 ) ;
V_29 = V_24 -> V_15 -> V_38 ( V_7 ) ;
if ( V_21 ) {
V_27 = F_16 ( V_10 , V_29 , 1 ) ;
} else {
if ( V_28 )
V_27 = F_16 ( V_10 , V_28 , 1 ) ;
else
V_27 = F_16 ( V_10 , V_29 , 2 ) ;
}
V_24 -> V_15 -> V_34 ( V_7 , V_21 ) ;
V_4 -> V_31 = V_21 ;
V_30 = V_26 ( V_10 , V_27 , F_9 ( 100 ) ) ;
if ( V_30 ) {
F_17 ( V_10 -> V_10 , L_1 ,
V_4 -> V_39 , V_21 ? L_2 : L_3 ) ;
}
if ( V_4 -> V_7 == V_35 ) {
V_4 -> V_36 = false ;
F_18 () ;
}
}
static int F_19 ( enum V_6 V_7 )
{
struct V_4 * V_4 = V_40 [ V_7 ] ;
struct V_23 * V_24 = V_4 -> V_41 . V_10 -> V_25 ;
V_24 -> V_15 -> V_42 ( V_4 -> V_7 , & V_4 -> V_5 ) ;
F_14 ( & V_4 -> V_41 , true ) ;
return 0 ;
}
static void F_20 ( enum V_6 V_7 )
{
struct V_4 * V_4 = V_40 [ V_7 ] ;
F_14 ( & V_4 -> V_41 , false ) ;
}
static void F_21 ( enum V_6 V_7 ,
const struct V_1 * V_5 )
{
struct V_4 * V_4 = V_40 [ V_7 ] ;
F_22 ( L_4 , V_4 -> V_39 ) ;
V_4 -> V_5 = * V_5 ;
}
static void F_23 ( enum V_6 V_7 ,
const struct V_43 * V_44 )
{
struct V_4 * V_4 = V_40 [ V_7 ] ;
struct V_23 * V_24 = V_4 -> V_41 . V_10 -> V_25 ;
F_22 ( L_4 , V_4 -> V_39 ) ;
V_24 -> V_15 -> V_45 ( V_4 -> V_7 , V_44 ) ;
}
static int F_24 (
enum V_6 V_7 ,
void (* F_25)( void * ) , void * V_46 )
{
return 0 ;
}
static void F_26 (
enum V_6 V_7 ,
void (* F_25)( void * ) , void * V_46 )
{
}
void F_27 ( struct V_2 * V_3 , T_2 V_47 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
if ( V_4 -> V_36 ) {
V_47 &= ~ V_48 ;
if ( ! V_47 )
return;
}
F_28 ( L_5 , V_4 -> V_39 , V_47 ) ;
}
void F_29 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
struct V_22 * V_10 = V_4 -> V_41 . V_10 ;
struct V_23 * V_24 = V_10 -> V_25 ;
bool V_9 ;
F_30 ( & V_3 -> V_10 -> V_11 ) ;
if ( V_24 -> V_15 -> V_49 ( V_4 -> V_7 ) ) {
F_31 ( & V_3 -> V_10 -> V_11 ) ;
return;
}
if ( V_4 -> V_50 ) {
F_32 ( V_3 , V_4 -> V_50 ) ;
V_4 -> V_50 = NULL ;
}
V_9 = V_4 -> V_9 ;
V_4 -> V_9 = false ;
F_31 ( & V_3 -> V_10 -> V_11 ) ;
if ( V_9 )
F_33 ( V_3 ) ;
F_34 ( & V_4 -> V_12 ) ;
F_22 ( L_6 , V_4 -> V_39 ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_23 * V_24 = V_3 -> V_10 -> V_25 ;
struct V_4 * V_4 = F_2 ( V_3 ) ;
struct V_51 V_52 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_53 = 0x000000 ;
V_52 . V_54 = false ;
V_52 . V_55 = false ;
V_52 . V_56 = false ;
V_24 -> V_15 -> V_57 ( V_4 -> V_7 , & V_52 ) ;
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
F_22 ( L_4 , V_4 -> V_39 ) ;
F_37 ( V_3 ) ;
F_38 ( V_4 ) ;
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
F_15 ( V_4 -> V_9 ) ;
V_4 -> V_9 = true ;
if ( V_3 -> V_58 -> V_50 ) {
V_4 -> V_50 = V_3 -> V_58 -> V_50 ;
V_3 -> V_58 -> V_50 = NULL ;
}
}
static void F_40 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
int V_30 ;
F_22 ( L_4 , V_4 -> V_39 ) ;
F_41 ( & V_3 -> V_10 -> V_11 ) ;
F_42 ( V_3 ) ;
V_30 = F_43 ( V_3 ) ;
F_15 ( V_30 != 0 ) ;
F_39 ( V_3 ) ;
F_44 ( & V_3 -> V_10 -> V_11 ) ;
}
static void F_45 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
F_22 ( L_4 , V_4 -> V_39 ) ;
F_41 ( & V_3 -> V_10 -> V_11 ) ;
if ( V_3 -> V_58 -> V_50 ) {
F_32 ( V_3 , V_3 -> V_58 -> V_50 ) ;
V_3 -> V_58 -> V_50 = NULL ;
}
F_44 ( & V_3 -> V_10 -> V_11 ) ;
F_46 ( V_3 ) ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
struct V_59 * V_60 = & V_3 -> V_58 -> V_61 ;
struct V_23 * V_24 = V_3 -> V_10 -> V_25 ;
const T_1 V_62 = V_63 | V_64 |
V_65 | V_66 |
V_67 | V_68 ;
unsigned int V_69 ;
F_22 ( L_7 ,
V_4 -> V_39 , V_60 -> V_41 . V_19 , V_60 -> V_39 ,
V_60 -> V_70 , V_60 -> clock ,
V_60 -> V_71 , V_60 -> V_72 , V_60 -> V_73 , V_60 -> V_74 ,
V_60 -> V_75 , V_60 -> V_76 , V_60 -> V_77 , V_60 -> V_78 ,
V_60 -> type , V_60 -> V_8 ) ;
F_48 ( V_60 , & V_4 -> V_5 ) ;
for ( V_69 = 0 ; V_69 < V_24 -> V_79 ; ++ V_69 ) {
struct V_80 * V_81 = V_24 -> V_82 [ V_69 ] ;
if ( V_81 -> V_3 == V_3 ) {
struct V_13 * V_83 ;
V_83 = F_49 ( V_81 ) ;
if ( V_83 ) {
struct V_1 V_5 = { 0 } ;
V_83 -> V_84 -> V_85 ( V_83 , & V_5 ) ;
V_4 -> V_5 . V_8 |= V_5 . V_8 & V_62 ;
}
break;
}
}
}
static int F_50 ( struct V_2 * V_3 ,
struct V_86 * V_58 )
{
if ( V_58 -> V_87 && V_58 -> V_88 ) {
T_3 V_89 = V_58 -> V_88 -> V_89 /
sizeof( struct V_90 ) ;
if ( V_89 < 2 )
return - V_17 ;
}
return 0 ;
}
static void F_51 ( struct V_2 * V_3 ,
struct V_86 * V_91 )
{
}
static void F_52 ( struct V_2 * V_3 ,
struct V_86 * V_91 )
{
struct V_23 * V_24 = V_3 -> V_10 -> V_25 ;
struct V_4 * V_4 = F_2 ( V_3 ) ;
int V_30 ;
if ( V_3 -> V_58 -> V_87 ) {
struct V_90 * V_92 = NULL ;
T_3 V_89 = 0 ;
if ( V_3 -> V_58 -> V_88 ) {
V_92 = (struct V_90 * )
V_3 -> V_58 -> V_88 -> V_46 ;
V_89 = V_3 -> V_58 -> V_88 -> V_89 /
sizeof( * V_92 ) ;
}
V_24 -> V_15 -> V_93 ( V_4 -> V_7 , V_92 , V_89 ) ;
}
F_35 ( V_3 ) ;
if ( ! V_4 -> V_31 )
return;
F_22 ( L_8 , V_4 -> V_39 ) ;
V_30 = F_43 ( V_3 ) ;
F_15 ( V_30 != 0 ) ;
F_41 ( & V_3 -> V_10 -> V_11 ) ;
V_24 -> V_15 -> V_94 ( V_4 -> V_7 ) ;
F_39 ( V_3 ) ;
F_44 ( & V_3 -> V_10 -> V_11 ) ;
}
static bool F_53 ( struct V_2 * V_3 ,
struct V_95 * V_96 )
{
struct V_22 * V_10 = V_3 -> V_10 ;
struct V_23 * V_24 = V_10 -> V_25 ;
return V_96 == V_24 -> V_97 ||
V_96 == V_3 -> V_98 -> V_99 ;
}
static int F_54 ( struct V_2 * V_3 ,
struct V_86 * V_58 ,
struct V_95 * V_96 ,
T_4 V_100 )
{
if ( F_53 ( V_3 , V_96 ) ) {
struct V_101 * V_102 ;
struct V_103 * V_104 = V_3 -> V_98 ;
V_102 = F_55 ( V_58 -> V_58 , V_104 ) ;
if ( F_56 ( V_102 ) )
return F_57 ( V_102 ) ;
return F_58 ( V_104 , V_102 ,
V_96 , V_100 ) ;
}
return - V_17 ;
}
static int F_59 ( struct V_2 * V_3 ,
const struct V_86 * V_58 ,
struct V_95 * V_96 ,
T_4 * V_100 )
{
if ( F_53 ( V_3 , V_96 ) ) {
return F_60 ( & V_3 -> V_98 -> V_41 ,
V_96 , V_100 ) ;
}
return - V_17 ;
}
void F_61 ( void )
{
memset ( V_40 , 0 , sizeof( V_40 ) ) ;
F_62 ( & V_105 ) ;
}
void F_63 ( void )
{
F_64 () ;
}
struct V_2 * F_65 ( struct V_22 * V_10 ,
struct V_103 * V_104 , struct V_13 * V_83 )
{
struct V_23 * V_24 = V_10 -> V_25 ;
struct V_2 * V_3 = NULL ;
struct V_4 * V_4 ;
enum V_6 V_7 ;
struct V_13 * V_106 ;
int V_30 ;
V_106 = F_66 ( V_83 ) ;
V_7 = V_106 -> V_107 ;
F_67 ( V_106 ) ;
F_22 ( L_4 , V_108 [ V_7 ] ) ;
if ( F_15 ( V_40 [ V_7 ] != NULL ) )
return F_68 ( - V_17 ) ;
V_4 = F_69 ( sizeof( * V_4 ) , V_109 ) ;
if ( ! V_4 )
return F_68 ( - V_110 ) ;
V_3 = & V_4 -> V_41 ;
F_70 ( & V_4 -> V_12 ) ;
V_4 -> V_7 = V_7 ;
V_4 -> V_39 = V_108 [ V_7 ] ;
V_30 = F_71 ( V_10 , V_3 , V_104 , NULL ,
& V_111 , NULL ) ;
if ( V_30 < 0 ) {
F_17 ( V_10 -> V_10 , L_9 ,
V_112 , V_83 -> V_39 ) ;
F_38 ( V_4 ) ;
return F_68 ( V_30 ) ;
}
F_72 ( V_3 , & V_113 ) ;
if ( V_24 -> V_15 -> V_114 ( V_7 ) ) {
T_3 V_115 = 256 ;
F_73 ( V_3 , 0 , false , V_115 ) ;
F_74 ( V_3 , V_115 ) ;
}
F_75 ( V_3 -> V_98 , & V_3 -> V_41 ) ;
V_40 [ V_7 ] = V_4 ;
return V_3 ;
}

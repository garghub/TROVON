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
F_8 ( 50 ) ) ;
}
static int F_9 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
if ( V_11 -> V_14 )
return - V_15 ;
if ( ( V_11 -> V_16 & V_13 -> V_17 ) == 0 )
return - V_15 ;
V_13 -> V_18 = V_11 ;
V_11 -> V_14 = V_13 ;
return 0 ;
}
static void F_10 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
V_11 -> V_14 -> V_18 = NULL ;
V_11 -> V_14 = NULL ;
}
static void F_11 ( struct V_10 * V_11 )
{
}
static void F_12 ( struct V_1 * V_2 , bool V_19 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
enum V_7 V_4 = V_3 -> V_4 ;
struct V_22 * V_23 ;
T_2 V_24 , V_25 ;
int V_26 ;
if ( F_13 ( V_4 ) == V_19 )
return;
if ( V_3 -> V_4 == V_27 ) {
V_3 -> V_28 = true ;
}
V_24 = F_14 ( V_4 ) ;
V_25 = F_3 ( V_4 ) ;
if ( V_19 ) {
V_23 = F_15 ( V_21 , V_25 , 1 ) ;
} else {
if ( V_24 )
V_23 = F_15 ( V_21 , V_24 , 1 ) ;
else
V_23 = F_15 ( V_21 , V_25 , 2 ) ;
}
F_16 ( V_4 , V_19 ) ;
V_26 = V_22 ( V_21 , V_23 , F_8 ( 100 ) ) ;
if ( V_26 ) {
F_17 ( V_21 -> V_21 , L_1 ,
V_3 -> V_29 , V_19 ? L_2 : L_3 ) ;
}
if ( V_3 -> V_4 == V_27 ) {
V_3 -> V_28 = false ;
F_18 () ;
}
}
static int F_19 ( struct V_10 * V_11 )
{
struct V_3 * V_3 = V_30 [ V_11 -> V_17 ] ;
struct V_31 V_32 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_33 = 0x00000000 ;
V_32 . V_34 = 0x00000000 ;
V_32 . V_35 = V_36 ;
V_32 . V_37 = false ;
F_20 ( V_3 -> V_4 , & V_32 ) ;
F_21 ( V_3 -> V_4 ,
& V_3 -> V_6 ) ;
F_12 ( & V_3 -> V_38 , true ) ;
return 0 ;
}
static void F_22 ( struct V_10 * V_11 )
{
struct V_3 * V_3 = V_30 [ V_11 -> V_17 ] ;
F_12 ( & V_3 -> V_38 , false ) ;
}
static void F_23 ( struct V_10 * V_11 ,
const struct V_5 * V_6 )
{
struct V_3 * V_3 = V_30 [ V_11 -> V_17 ] ;
F_24 ( L_4 , V_3 -> V_29 ) ;
V_3 -> V_6 = * V_6 ;
}
static void F_25 ( struct V_10 * V_11 ,
const struct V_39 * V_40 )
{
struct V_3 * V_3 = V_30 [ V_11 -> V_17 ] ;
F_24 ( L_4 , V_3 -> V_29 ) ;
F_26 ( V_3 -> V_4 , V_40 ) ;
}
static int F_27 (
struct V_10 * V_11 ,
void (* F_28)( void * ) , void * V_41 )
{
return 0 ;
}
static void F_29 (
struct V_10 * V_11 ,
void (* F_28)( void * ) , void * V_41 )
{
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
struct V_20 * V_21 = V_2 -> V_21 ;
unsigned long V_44 ;
V_43 = V_2 -> V_45 -> V_43 ;
if ( ! V_43 )
return;
F_31 ( & V_21 -> V_46 , V_44 ) ;
F_32 ( & V_43 -> V_38 . V_47 ) ;
if ( V_43 -> V_38 . V_48 )
F_33 ( V_2 , V_43 ) ;
else
V_43 -> V_38 . V_49 ( & V_43 -> V_38 ) ;
F_34 ( & V_21 -> V_46 , V_44 ) ;
}
static void F_35 ( struct V_50 * V_51 , T_1 V_52 )
{
struct V_3 * V_3 =
F_36 ( V_51 , struct V_3 , V_53 ) ;
if ( V_3 -> V_28 ) {
V_52 &= ~ V_54 ;
if ( ! V_52 )
return;
}
F_37 ( L_5 , V_3 -> V_29 , V_52 ) ;
}
static void F_38 ( struct V_50 * V_51 , T_1 V_52 )
{
struct V_3 * V_3 =
F_36 ( V_51 , struct V_3 , V_55 ) ;
struct V_20 * V_21 = V_3 -> V_38 . V_21 ;
if ( F_39 ( V_3 -> V_4 ) )
return;
F_24 ( L_6 , V_3 -> V_29 ) ;
F_40 ( V_21 , & V_3 -> V_55 ) ;
F_41 () ;
F_42 ( ! V_3 -> V_9 ) ;
V_3 -> V_9 = false ;
F_43 () ;
F_30 ( & V_3 -> V_38 ) ;
F_44 ( & V_3 -> V_8 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_24 ( L_4 , V_3 -> V_29 ) ;
F_42 ( V_3 -> V_55 . V_56 ) ;
F_46 ( V_2 -> V_21 , & V_3 -> V_53 ) ;
F_47 ( V_2 ) ;
F_48 ( V_3 ) ;
}
static bool F_49 ( struct V_1 * V_2 ,
const struct V_57 * V_58 ,
struct V_57 * V_59 )
{
return true ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_24 ( L_4 , V_3 -> V_29 ) ;
F_41 () ;
F_42 ( V_3 -> V_9 ) ;
V_3 -> V_9 = true ;
F_43 () ;
F_51 ( V_2 -> V_21 , & V_3 -> V_55 ) ;
F_52 ( V_2 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_24 ( L_4 , V_3 -> V_29 ) ;
F_54 ( V_2 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_57 * V_58 = & V_2 -> V_45 -> V_59 ;
F_24 ( L_7 ,
V_3 -> V_29 , V_58 -> V_38 . V_17 , V_58 -> V_29 ,
V_58 -> V_60 , V_58 -> clock ,
V_58 -> V_61 , V_58 -> V_62 , V_58 -> V_63 , V_58 -> V_64 ,
V_58 -> V_65 , V_58 -> V_66 , V_58 -> V_67 , V_58 -> V_68 ,
V_58 -> type , V_58 -> V_44 ) ;
F_56 ( & V_3 -> V_6 , V_58 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_42 ( V_3 -> V_55 . V_56 ) ;
if ( F_13 ( V_3 -> V_4 ) ) {
F_24 ( L_8 , V_3 -> V_29 ) ;
F_41 () ;
F_42 ( V_3 -> V_9 ) ;
V_3 -> V_9 = true ;
F_43 () ;
F_59 ( V_3 -> V_4 ) ;
F_51 ( V_2 -> V_21 , & V_3 -> V_55 ) ;
}
V_2 -> V_69 = ! ! ( V_2 -> V_70 -> V_45 -> V_71 &
( F_60 ( V_72 ) | F_60 ( V_73 ) ) ) ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_74 * V_45 ,
struct V_75 * V_76 ,
T_3 V_77 )
{
struct V_78 * V_79 ;
struct V_80 * V_81 = V_2 -> V_70 ;
V_79 = F_62 ( V_45 -> V_45 , V_81 ) ;
if ( ! V_79 )
return - V_15 ;
return F_63 ( V_81 , V_79 , V_76 , V_77 ) ;
}
static int F_64 ( struct V_1 * V_2 ,
const struct V_74 * V_45 ,
struct V_75 * V_76 ,
T_3 * V_77 )
{
return F_65 ( & V_2 -> V_70 -> V_38 , V_76 ,
V_77 ) ;
}
void F_66 ( void )
{
F_67 ( & V_82 ) ;
}
void F_68 ( void )
{
F_69 () ;
}
struct V_1 * F_70 ( struct V_20 * V_21 ,
struct V_80 * V_81 , enum V_7 V_4 , int V_17 )
{
struct V_1 * V_2 = NULL ;
struct V_3 * V_3 ;
int V_26 ;
F_24 ( L_4 , V_83 [ V_4 ] ) ;
V_3 = F_71 ( sizeof( * V_3 ) , V_84 ) ;
if ( ! V_3 )
return NULL ;
V_2 = & V_3 -> V_38 ;
F_72 ( & V_3 -> V_8 ) ;
V_3 -> V_4 = V_4 ;
V_3 -> V_29 = V_83 [ V_4 ] ;
V_3 -> V_55 . V_85 = F_1 ( V_2 ) ;
V_3 -> V_55 . V_51 = F_38 ;
V_3 -> V_53 . V_85 =
F_73 ( V_4 ) ;
V_3 -> V_53 . V_51 = F_35 ;
F_51 ( V_21 , & V_3 -> V_53 ) ;
V_3 -> V_11 = F_74 ( V_4 ) ;
V_26 = F_75 ( V_21 , V_2 , V_81 , NULL ,
& V_86 ) ;
if ( V_26 < 0 ) {
F_48 ( V_3 ) ;
return NULL ;
}
F_76 ( V_2 , & V_87 ) ;
F_77 ( V_2 -> V_70 , & V_2 -> V_38 ) ;
V_30 [ V_4 ] = V_3 ;
return V_2 ;
}

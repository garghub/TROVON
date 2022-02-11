static bool F_1 ( const struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * V_5 )
{
const T_1 * V_6 ;
T_1 V_7 [ 2 ] ;
V_6 = F_2 ( V_2 , V_3 + F_3 ( struct V_8 , V_9 ) ,
sizeof( V_10 ) * 2 , V_7 ) ;
if ( V_6 == NULL )
return false ;
V_5 -> V_11 . V_12 . V_13 = V_6 [ 0 ] ;
V_5 -> V_14 . V_12 . V_13 = V_6 [ 1 ] ;
return true ;
}
static bool F_4 ( struct V_4 * V_5 ,
const struct V_4 * V_15 )
{
V_5 -> V_11 . V_12 . V_13 = V_15 -> V_14 . V_12 . V_13 ;
V_5 -> V_14 . V_12 . V_13 = V_15 -> V_11 . V_12 . V_13 ;
return true ;
}
static void F_5 ( struct V_16 * V_17 ,
const struct V_4 * V_5 )
{
F_6 ( V_17 , L_1 ,
& V_5 -> V_11 . V_12 . V_13 , & V_5 -> V_14 . V_12 . V_13 ) ;
}
static int F_7 ( const struct V_1 * V_2 , unsigned int V_3 ,
unsigned int * V_18 , T_2 * V_19 )
{
const struct V_8 * V_20 ;
struct V_8 V_21 ;
V_20 = F_2 ( V_2 , V_3 , sizeof( V_21 ) , & V_21 ) ;
if ( V_20 == NULL )
return - V_22 ;
if ( V_20 -> V_23 & F_8 ( V_24 ) )
return - V_22 ;
* V_18 = V_3 + ( V_20 -> V_25 << 2 ) ;
* V_19 = V_20 -> V_26 ;
if ( * V_18 > V_2 -> V_27 ) {
F_9 ( L_2
L_3 ,
V_3 , V_20 -> V_25 << 2 , V_2 -> V_27 ) ;
return - V_22 ;
}
return V_22 ;
}
static unsigned int F_10 ( void * V_28 ,
struct V_1 * V_2 ,
const struct V_29 * V_30 )
{
struct V_31 * V_32 ;
enum V_33 V_34 ;
const struct V_35 * V_36 ;
const struct V_37 * V_38 ;
V_32 = F_11 ( V_2 , & V_34 ) ;
if ( ! V_32 || V_34 == V_39 )
return V_22 ;
V_36 = F_12 ( V_32 ) ;
if ( ! V_36 )
return V_22 ;
V_38 = F_13 ( V_36 -> V_38 ) ;
if ( ! V_38 )
return V_22 ;
return V_38 -> V_36 ( V_2 , F_14 ( V_2 ) + F_15 ( V_2 ) ,
V_32 , V_34 ) ;
}
static unsigned int F_16 ( void * V_28 ,
struct V_1 * V_2 ,
const struct V_29 * V_30 )
{
struct V_31 * V_32 ;
enum V_33 V_34 ;
V_32 = F_11 ( V_2 , & V_34 ) ;
if ( ! V_32 || V_34 == V_39 )
goto V_40;
if ( F_17 ( V_41 , & V_32 -> V_42 ) &&
! F_18 ( V_2 ) ) {
if ( ! F_19 ( V_2 , V_32 , V_34 , F_15 ( V_2 ) ) ) {
F_20 ( F_21 ( V_32 ) , V_43 ) ;
return V_44 ;
}
}
V_40:
return F_22 ( V_2 ) ;
}
static unsigned int F_23 ( void * V_28 ,
struct V_1 * V_2 ,
const struct V_29 * V_30 )
{
return F_24 ( V_30 -> V_45 , V_46 , V_30 -> V_47 , V_2 ) ;
}
static unsigned int F_25 ( void * V_28 ,
struct V_1 * V_2 ,
const struct V_29 * V_30 )
{
if ( V_2 -> V_27 < sizeof( struct V_8 ) ||
F_15 ( V_2 ) < sizeof( struct V_8 ) )
return V_22 ;
return F_24 ( V_30 -> V_45 , V_46 , V_30 -> V_47 , V_2 ) ;
}
static int
F_26 ( struct V_48 * V_49 , int V_50 , void T_3 * V_51 , int * V_27 )
{
const struct V_52 * V_53 = F_27 ( V_49 ) ;
const struct V_54 * V_55 ;
struct V_4 V_5 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_11 . V_12 . V_13 = V_53 -> V_56 ;
V_5 . V_11 . V_57 . V_58 . V_59 = V_53 -> V_60 ;
V_5 . V_14 . V_12 . V_13 = V_53 -> V_61 ;
V_5 . V_14 . V_57 . V_58 . V_59 = V_53 -> V_62 ;
V_5 . V_11 . V_63 = V_46 ;
V_5 . V_14 . V_19 = V_49 -> V_64 ;
if ( V_49 -> V_64 != V_65 && V_49 -> V_64 != V_66 ) {
F_9 ( L_4 ) ;
return - V_67 ;
}
if ( ( unsigned int ) * V_27 < sizeof( struct V_68 ) ) {
F_9 ( L_5 ,
* V_27 , sizeof( struct V_68 ) ) ;
return - V_69 ;
}
V_55 = F_28 ( F_29 ( V_49 ) , & V_70 , & V_5 ) ;
if ( V_55 ) {
struct V_68 sin ;
struct V_31 * V_32 = F_30 ( V_55 ) ;
sin . V_71 = V_72 ;
sin . V_73 = V_32 -> V_74 [ V_75 ]
. V_5 . V_14 . V_57 . V_58 . V_59 ;
sin . V_76 . V_77 = V_32 -> V_74 [ V_75 ]
. V_5 . V_14 . V_12 . V_13 ;
memset ( sin . V_78 , 0 , sizeof( sin . V_78 ) ) ;
F_9 ( L_6 ,
& sin . V_76 . V_77 , F_31 ( sin . V_73 ) ) ;
F_32 ( V_32 ) ;
if ( F_33 ( V_51 , & sin , sizeof( sin ) ) != 0 )
return - V_79 ;
else
return 0 ;
}
F_9 ( L_7 ,
& V_5 . V_11 . V_12 . V_13 , F_31 ( V_5 . V_11 . V_57 . V_58 . V_59 ) ,
& V_5 . V_14 . V_12 . V_13 , F_31 ( V_5 . V_14 . V_57 . V_58 . V_59 ) ) ;
return - V_80 ;
}
static int F_34 ( struct V_1 * V_2 ,
const struct V_4 * V_5 )
{
if ( F_35 ( V_2 , V_81 , V_5 -> V_11 . V_12 . V_13 ) ||
F_35 ( V_2 , V_82 , V_5 -> V_14 . V_12 . V_13 ) )
goto V_83;
return 0 ;
V_83:
return - 1 ;
}
static int F_36 ( struct V_84 * V_85 [] ,
struct V_4 * V_86 )
{
if ( ! V_85 [ V_81 ] || ! V_85 [ V_82 ] )
return - V_69 ;
V_86 -> V_11 . V_12 . V_13 = F_37 ( V_85 [ V_81 ] ) ;
V_86 -> V_14 . V_12 . V_13 = F_37 ( V_85 [ V_82 ] ) ;
return 0 ;
}
static int F_38 ( void )
{
return F_39 ( V_87 , V_88 + 1 ) ;
}
static int F_40 ( struct V_45 * V_45 )
{
struct V_89 * V_90 = F_41 ( V_45 , V_91 ) ;
int V_92 = 0 ;
F_42 ( & V_93 ) ;
V_90 -> V_94 ++ ;
if ( V_90 -> V_94 > 1 )
goto V_95;
V_92 = F_43 ( V_45 ) ;
if ( V_92 ) {
V_90 -> V_94 = 0 ;
goto V_95;
}
V_92 = F_44 ( V_45 , V_96 ,
F_45 ( V_96 ) ) ;
if ( V_92 )
V_90 -> V_94 = 0 ;
V_95:
F_46 ( & V_93 ) ;
return V_92 ;
}
static void F_47 ( struct V_45 * V_45 )
{
struct V_89 * V_90 = F_41 ( V_45 , V_91 ) ;
F_42 ( & V_93 ) ;
if ( V_90 -> V_94 && ( -- V_90 -> V_94 == 0 ) )
F_48 ( V_45 , V_96 ,
F_45 ( V_96 ) ) ;
F_46 ( & V_93 ) ;
}
static int F_49 ( struct V_45 * V_45 )
{
int V_97 = 0 ;
V_97 = F_50 ( V_45 , V_98 ,
F_45 ( V_98 ) ) ;
if ( V_97 < 0 )
return V_97 ;
V_97 = F_51 ( V_45 , & V_99 ) ;
if ( V_97 < 0 ) {
F_52 ( L_8 ) ;
F_53 ( V_45 , V_98 ,
F_45 ( V_98 ) ) ;
}
return V_97 ;
}
static void F_54 ( struct V_45 * V_45 )
{
F_55 ( V_45 , & V_99 ) ;
F_53 ( V_45 , V_98 ,
F_45 ( V_98 ) ) ;
}
static int T_4 F_56 ( void )
{
int V_97 = 0 ;
F_57 () ;
V_97 = F_58 ( & V_100 ) ;
if ( V_97 < 0 ) {
F_52 ( L_9 ) ;
return V_97 ;
}
V_97 = F_59 ( & V_101 ) ;
if ( V_97 < 0 ) {
F_52 ( L_10 ) ;
goto V_102;
}
V_97 = F_60 ( V_98 ,
F_45 ( V_98 ) ) ;
if ( V_97 < 0 )
goto V_103;
V_97 = F_61 ( & V_99 ) ;
if ( V_97 < 0 ) {
F_52 ( L_11 ) ;
goto V_104;
}
return V_97 ;
V_104:
F_62 ( V_98 ,
F_45 ( V_98 ) ) ;
V_103:
F_63 ( & V_101 ) ;
V_102:
F_64 ( & V_100 ) ;
return V_97 ;
}
static void T_5 F_65 ( void )
{
F_66 () ;
F_67 ( & V_99 ) ;
F_62 ( V_98 ,
F_45 ( V_98 ) ) ;
F_63 ( & V_101 ) ;
F_64 ( & V_100 ) ;
}

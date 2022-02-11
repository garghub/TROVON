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
static int F_5 ( const struct V_1 * V_2 , unsigned int V_3 ,
unsigned int * V_16 , T_2 * V_17 )
{
const struct V_8 * V_18 ;
struct V_8 V_19 ;
V_18 = F_2 ( V_2 , V_3 , sizeof( V_19 ) , & V_19 ) ;
if ( V_18 == NULL )
return - V_20 ;
if ( V_18 -> V_21 & F_6 ( V_22 ) )
return - V_20 ;
* V_16 = V_3 + ( V_18 -> V_23 << 2 ) ;
* V_17 = V_18 -> V_24 ;
if ( * V_16 > V_2 -> V_25 ) {
F_7 ( L_1
L_2 ,
V_3 , V_18 -> V_23 << 2 , V_2 -> V_25 ) ;
return - V_20 ;
}
return V_20 ;
}
static unsigned int F_8 ( void * V_26 ,
struct V_1 * V_2 ,
const struct V_27 * V_28 )
{
struct V_29 * V_30 ;
enum V_31 V_32 ;
const struct V_33 * V_34 ;
const struct V_35 * V_36 ;
V_30 = F_9 ( V_2 , & V_32 ) ;
if ( ! V_30 || V_32 == V_37 )
return V_20 ;
V_34 = F_10 ( V_30 ) ;
if ( ! V_34 )
return V_20 ;
V_36 = F_11 ( V_34 -> V_36 ) ;
if ( ! V_36 )
return V_20 ;
return V_36 -> V_34 ( V_2 , F_12 ( V_2 ) + F_13 ( V_2 ) ,
V_30 , V_32 ) ;
}
static unsigned int F_14 ( void * V_26 ,
struct V_1 * V_2 ,
const struct V_27 * V_28 )
{
struct V_29 * V_30 ;
enum V_31 V_32 ;
V_30 = F_9 ( V_2 , & V_32 ) ;
if ( ! V_30 || V_32 == V_37 )
goto V_38;
if ( F_15 ( V_39 , & V_30 -> V_40 ) &&
! F_16 ( V_2 ) ) {
if ( ! F_17 ( V_2 , V_30 , V_32 , F_13 ( V_2 ) ) ) {
F_18 ( F_19 ( V_30 ) , V_41 ) ;
return V_42 ;
}
}
V_38:
return F_20 ( V_2 ) ;
}
static unsigned int F_21 ( void * V_26 ,
struct V_1 * V_2 ,
const struct V_27 * V_28 )
{
return F_22 ( V_28 -> V_43 , V_44 , V_28 -> V_45 , V_2 ) ;
}
static unsigned int F_23 ( void * V_26 ,
struct V_1 * V_2 ,
const struct V_27 * V_28 )
{
if ( V_2 -> V_25 < sizeof( struct V_8 ) ||
F_13 ( V_2 ) < sizeof( struct V_8 ) )
return V_20 ;
if ( F_24 ( F_25 ( V_2 ) ) )
return V_20 ;
return F_22 ( V_28 -> V_43 , V_44 , V_28 -> V_45 , V_2 ) ;
}
static int
F_26 ( struct V_46 * V_47 , int V_48 , void T_3 * V_49 , int * V_25 )
{
const struct V_50 * V_51 = F_27 ( V_47 ) ;
const struct V_52 * V_53 ;
struct V_4 V_5 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_11 . V_12 . V_13 = V_51 -> V_54 ;
V_5 . V_11 . V_55 . V_56 . V_57 = V_51 -> V_58 ;
V_5 . V_14 . V_12 . V_13 = V_51 -> V_59 ;
V_5 . V_14 . V_55 . V_56 . V_57 = V_51 -> V_60 ;
V_5 . V_11 . V_61 = V_44 ;
V_5 . V_14 . V_17 = V_47 -> V_62 ;
if ( V_47 -> V_62 != V_63 && V_47 -> V_62 != V_64 ) {
F_7 ( L_3 ) ;
return - V_65 ;
}
if ( ( unsigned int ) * V_25 < sizeof( struct V_66 ) ) {
F_7 ( L_4 ,
* V_25 , sizeof( struct V_66 ) ) ;
return - V_67 ;
}
V_53 = F_28 ( F_29 ( V_47 ) , & V_68 , & V_5 ) ;
if ( V_53 ) {
struct V_66 sin ;
struct V_29 * V_30 = F_30 ( V_53 ) ;
sin . V_69 = V_70 ;
sin . V_71 = V_30 -> V_72 [ V_73 ]
. V_5 . V_14 . V_55 . V_56 . V_57 ;
sin . V_74 . V_75 = V_30 -> V_72 [ V_73 ]
. V_5 . V_14 . V_12 . V_13 ;
memset ( sin . V_76 , 0 , sizeof( sin . V_76 ) ) ;
F_7 ( L_5 ,
& sin . V_74 . V_75 , F_31 ( sin . V_71 ) ) ;
F_32 ( V_30 ) ;
if ( F_33 ( V_49 , & sin , sizeof( sin ) ) != 0 )
return - V_77 ;
else
return 0 ;
}
F_7 ( L_6 ,
& V_5 . V_11 . V_12 . V_13 , F_31 ( V_5 . V_11 . V_55 . V_56 . V_57 ) ,
& V_5 . V_14 . V_12 . V_13 , F_31 ( V_5 . V_14 . V_55 . V_56 . V_57 ) ) ;
return - V_78 ;
}
static int F_34 ( struct V_1 * V_2 ,
const struct V_4 * V_5 )
{
if ( F_35 ( V_2 , V_79 , V_5 -> V_11 . V_12 . V_13 ) ||
F_35 ( V_2 , V_80 , V_5 -> V_14 . V_12 . V_13 ) )
goto V_81;
return 0 ;
V_81:
return - 1 ;
}
static int F_36 ( struct V_82 * V_83 [] ,
struct V_4 * V_84 )
{
if ( ! V_83 [ V_79 ] || ! V_83 [ V_80 ] )
return - V_67 ;
V_84 -> V_11 . V_12 . V_13 = F_37 ( V_83 [ V_79 ] ) ;
V_84 -> V_14 . V_12 . V_13 = F_37 ( V_83 [ V_80 ] ) ;
return 0 ;
}
static int F_38 ( struct V_43 * V_43 )
{
struct V_85 * V_86 = F_39 ( V_43 , V_87 ) ;
int V_88 = 0 ;
F_40 ( & V_89 ) ;
V_86 -> V_90 ++ ;
if ( V_86 -> V_90 > 1 )
goto V_91;
V_88 = F_41 ( V_43 ) ;
if ( V_88 ) {
V_86 -> V_90 = 0 ;
goto V_91;
}
V_88 = F_42 ( V_43 , V_92 ,
F_43 ( V_92 ) ) ;
if ( V_88 )
V_86 -> V_90 = 0 ;
V_91:
F_44 ( & V_89 ) ;
return V_88 ;
}
static void F_45 ( struct V_43 * V_43 )
{
struct V_85 * V_86 = F_39 ( V_43 , V_87 ) ;
F_40 ( & V_89 ) ;
if ( V_86 -> V_90 && ( -- V_86 -> V_90 == 0 ) )
F_46 ( V_43 , V_92 ,
F_43 ( V_92 ) ) ;
F_44 ( & V_89 ) ;
}
static int F_47 ( struct V_43 * V_43 )
{
return F_48 ( V_43 , V_93 ,
F_43 ( V_93 ) ) ;
}
static void F_49 ( struct V_43 * V_43 )
{
F_50 ( V_43 , V_93 ,
F_43 ( V_93 ) ) ;
}
static int T_4 F_51 ( void )
{
int V_94 = 0 ;
F_52 () ;
#if F_53 ( V_95 )
if ( F_54 ( F_55 ( V_96 , V_97 + 1 ) !=
V_98 . V_99 ) )
return - V_67 ;
#endif
V_94 = F_56 ( & V_100 ) ;
if ( V_94 < 0 ) {
F_57 ( L_7 ) ;
return V_94 ;
}
V_94 = F_58 ( & V_101 ) ;
if ( V_94 < 0 ) {
F_57 ( L_8 ) ;
goto V_102;
}
V_94 = F_59 ( V_93 ,
F_43 ( V_93 ) ) ;
if ( V_94 < 0 )
goto V_103;
V_94 = F_60 ( & V_98 ) ;
if ( V_94 < 0 ) {
F_57 ( L_9 ) ;
goto V_104;
}
return V_94 ;
V_104:
F_61 ( V_93 ,
F_43 ( V_93 ) ) ;
V_103:
F_62 ( & V_101 ) ;
V_102:
F_63 ( & V_100 ) ;
return V_94 ;
}
static void T_5 F_64 ( void )
{
F_65 () ;
F_66 ( & V_98 ) ;
F_61 ( V_93 ,
F_43 ( V_93 ) ) ;
F_62 ( & V_101 ) ;
F_63 ( & V_100 ) ;
}

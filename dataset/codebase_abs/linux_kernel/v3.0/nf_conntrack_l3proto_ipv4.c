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
static int F_5 ( struct V_16 * V_17 ,
const struct V_4 * V_5 )
{
return F_6 ( V_17 , L_1 ,
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
return V_27 ;
}
static unsigned int F_9 ( unsigned int V_28 ,
struct V_1 * V_2 ,
const struct V_29 * V_30 ,
const struct V_29 * V_31 ,
int (* F_10)( struct V_1 * ) )
{
struct V_32 * V_33 ;
enum V_34 V_35 ;
const struct V_36 * V_37 ;
const struct V_38 * V_39 ;
unsigned int V_40 ;
V_33 = F_11 ( V_2 , & V_35 ) ;
if ( ! V_33 || V_35 == V_41 )
goto V_31;
V_37 = F_12 ( V_33 ) ;
if ( ! V_37 )
goto V_31;
V_39 = F_13 ( V_37 -> V_39 ) ;
if ( ! V_39 )
goto V_31;
V_40 = V_39 -> V_37 ( V_2 , F_14 ( V_2 ) + F_15 ( V_2 ) ,
V_33 , V_35 ) ;
if ( V_40 != V_27 ) {
F_16 ( V_42 , V_28 , V_2 , V_30 , V_31 , NULL ,
L_2 , V_39 -> V_43 ) ;
return V_40 ;
}
if ( F_17 ( V_44 , & V_33 -> V_45 ) &&
! F_18 ( V_2 ) ) {
F_19 (nf_nat_seq_adjust_hook) V_46 ;
V_46 = F_13 ( V_47 ) ;
if ( ! V_46 || ! V_46 ( V_2 , V_33 , V_35 ) ) {
F_20 ( F_21 ( V_33 ) , V_48 ) ;
return V_22 ;
}
}
V_31:
return F_22 ( V_2 ) ;
}
static unsigned int F_23 ( unsigned int V_28 ,
struct V_1 * V_2 ,
const struct V_29 * V_30 ,
const struct V_29 * V_31 ,
int (* F_10)( struct V_1 * ) )
{
return F_24 ( F_25 ( V_30 ) , V_49 , V_28 , V_2 ) ;
}
static unsigned int F_26 ( unsigned int V_28 ,
struct V_1 * V_2 ,
const struct V_29 * V_30 ,
const struct V_29 * V_31 ,
int (* F_10)( struct V_1 * ) )
{
if ( V_2 -> V_50 < sizeof( struct V_8 ) ||
F_15 ( V_2 ) < sizeof( struct V_8 ) )
return V_27 ;
return F_24 ( F_25 ( V_31 ) , V_49 , V_28 , V_2 ) ;
}
static int
F_27 ( struct V_51 * V_52 , int V_53 , void T_3 * V_54 , int * V_50 )
{
const struct V_55 * V_56 = F_28 ( V_52 ) ;
const struct V_57 * V_58 ;
struct V_4 V_5 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_11 . V_12 . V_13 = V_56 -> V_59 ;
V_5 . V_11 . V_60 . V_61 . V_62 = V_56 -> V_63 ;
V_5 . V_14 . V_12 . V_13 = V_56 -> V_64 ;
V_5 . V_14 . V_60 . V_61 . V_62 = V_56 -> V_65 ;
V_5 . V_11 . V_66 = V_49 ;
V_5 . V_14 . V_19 = V_52 -> V_67 ;
if ( V_52 -> V_67 != V_68 && V_52 -> V_67 != V_69 ) {
F_29 ( L_3 ) ;
return - V_70 ;
}
if ( ( unsigned int ) * V_50 < sizeof( struct V_71 ) ) {
F_29 ( L_4 ,
* V_50 , sizeof( struct V_71 ) ) ;
return - V_72 ;
}
V_58 = F_30 ( F_31 ( V_52 ) , V_73 , & V_5 ) ;
if ( V_58 ) {
struct V_71 sin ;
struct V_32 * V_33 = F_32 ( V_58 ) ;
sin . V_74 = V_75 ;
sin . V_76 = V_33 -> V_77 [ V_78 ]
. V_5 . V_14 . V_60 . V_61 . V_62 ;
sin . V_79 . V_80 = V_33 -> V_77 [ V_78 ]
. V_5 . V_14 . V_12 . V_13 ;
memset ( sin . V_81 , 0 , sizeof( sin . V_81 ) ) ;
F_29 ( L_5 ,
& sin . V_79 . V_80 , F_33 ( sin . V_76 ) ) ;
F_34 ( V_33 ) ;
if ( F_35 ( V_54 , & sin , sizeof( sin ) ) != 0 )
return - V_82 ;
else
return 0 ;
}
F_29 ( L_6 ,
& V_5 . V_11 . V_12 . V_13 , F_33 ( V_5 . V_11 . V_60 . V_61 . V_62 ) ,
& V_5 . V_14 . V_12 . V_13 , F_33 ( V_5 . V_14 . V_60 . V_61 . V_62 ) ) ;
return - V_83 ;
}
static int F_36 ( struct V_1 * V_2 ,
const struct V_4 * V_5 )
{
F_37 ( V_2 , V_84 , V_5 -> V_11 . V_12 . V_13 ) ;
F_37 ( V_2 , V_85 , V_5 -> V_14 . V_12 . V_13 ) ;
return 0 ;
V_86:
return - 1 ;
}
static int F_38 ( struct V_87 * V_88 [] ,
struct V_4 * V_89 )
{
if ( ! V_88 [ V_84 ] || ! V_88 [ V_85 ] )
return - V_72 ;
V_89 -> V_11 . V_12 . V_13 = F_39 ( V_88 [ V_84 ] ) ;
V_89 -> V_14 . V_12 . V_13 = F_39 ( V_88 [ V_85 ] ) ;
return 0 ;
}
static int F_40 ( void )
{
return F_41 ( V_90 , V_91 + 1 ) ;
}
static int T_4 F_42 ( void )
{
int V_40 = 0 ;
F_43 () ;
F_44 () ;
V_40 = F_45 ( & V_92 ) ;
if ( V_40 < 0 ) {
F_46 ( V_93 L_7 ) ;
return V_40 ;
}
V_40 = F_47 ( & V_94 ) ;
if ( V_40 < 0 ) {
F_48 ( L_8 ) ;
goto V_95;
}
V_40 = F_47 ( & V_96 ) ;
if ( V_40 < 0 ) {
F_48 ( L_9 ) ;
goto V_97;
}
V_40 = F_47 ( & V_98 ) ;
if ( V_40 < 0 ) {
F_48 ( L_10 ) ;
goto V_99;
}
V_40 = F_49 ( & V_100 ) ;
if ( V_40 < 0 ) {
F_48 ( L_11 ) ;
goto V_101;
}
V_40 = F_50 ( V_102 ,
F_51 ( V_102 ) ) ;
if ( V_40 < 0 ) {
F_48 ( L_12 ) ;
goto V_103;
}
#if F_52 ( V_104 ) && F_52 ( V_105 )
V_40 = F_53 () ;
if ( V_40 < 0 )
goto V_106;
#endif
return V_40 ;
#if F_52 ( V_104 ) && F_52 ( V_105 )
V_106:
F_54 ( V_102 , F_51 ( V_102 ) ) ;
#endif
V_103:
F_55 ( & V_100 ) ;
V_101:
F_56 ( & V_98 ) ;
V_99:
F_56 ( & V_96 ) ;
V_97:
F_56 ( & V_94 ) ;
V_95:
F_57 ( & V_92 ) ;
return V_40 ;
}
static void T_5 F_58 ( void )
{
F_59 () ;
#if F_52 ( V_104 ) && F_52 ( V_105 )
F_60 () ;
#endif
F_54 ( V_102 , F_51 ( V_102 ) ) ;
F_55 ( & V_100 ) ;
F_56 ( & V_98 ) ;
F_56 ( & V_96 ) ;
F_56 ( & V_94 ) ;
F_57 ( & V_92 ) ;
}
void F_61 ( void )
{
return;
}

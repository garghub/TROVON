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
if ( * V_18 > V_2 -> V_27 ) {
F_9 ( L_2
L_3 ,
V_3 , V_20 -> V_25 << 2 , V_2 -> V_27 ) ;
return - V_22 ;
}
return V_22 ;
}
static unsigned int F_10 ( unsigned int V_28 ,
struct V_1 * V_2 ,
const struct V_29 * V_30 ,
const struct V_29 * V_31 ,
int (* F_11)( struct V_1 * ) )
{
struct V_32 * V_33 ;
enum V_34 V_35 ;
const struct V_36 * V_37 ;
const struct V_38 * V_39 ;
unsigned int V_40 ;
V_33 = F_12 ( V_2 , & V_35 ) ;
if ( ! V_33 || V_35 == V_41 )
return V_22 ;
V_37 = F_13 ( V_33 ) ;
if ( ! V_37 )
return V_22 ;
V_39 = F_14 ( V_37 -> V_39 ) ;
if ( ! V_39 )
return V_22 ;
V_40 = V_39 -> V_37 ( V_2 , F_15 ( V_2 ) + F_16 ( V_2 ) ,
V_33 , V_35 ) ;
if ( V_40 != V_22 && ( V_40 & V_42 ) != V_43 ) {
F_17 ( V_44 , V_28 , V_2 , V_30 , V_31 , NULL ,
L_4 , V_39 -> V_45 ) ;
}
return V_40 ;
}
static unsigned int F_18 ( unsigned int V_28 ,
struct V_1 * V_2 ,
const struct V_29 * V_30 ,
const struct V_29 * V_31 ,
int (* F_11)( struct V_1 * ) )
{
struct V_32 * V_33 ;
enum V_34 V_35 ;
V_33 = F_12 ( V_2 , & V_35 ) ;
if ( ! V_33 || V_35 == V_41 )
goto V_31;
if ( F_19 ( V_46 , & V_33 -> V_47 ) &&
! F_20 ( V_2 ) ) {
F_21 (nf_nat_seq_adjust_hook) V_48 ;
V_48 = F_14 ( V_49 ) ;
if ( ! V_48 || ! V_48 ( V_2 , V_33 , V_35 ) ) {
F_22 ( F_23 ( V_33 ) , V_50 ) ;
return V_51 ;
}
}
V_31:
return F_24 ( V_2 ) ;
}
static unsigned int F_25 ( unsigned int V_28 ,
struct V_1 * V_2 ,
const struct V_29 * V_30 ,
const struct V_29 * V_31 ,
int (* F_11)( struct V_1 * ) )
{
return F_26 ( F_27 ( V_30 ) , V_52 , V_28 , V_2 ) ;
}
static unsigned int F_28 ( unsigned int V_28 ,
struct V_1 * V_2 ,
const struct V_29 * V_30 ,
const struct V_29 * V_31 ,
int (* F_11)( struct V_1 * ) )
{
if ( V_2 -> V_27 < sizeof( struct V_8 ) ||
F_16 ( V_2 ) < sizeof( struct V_8 ) )
return V_22 ;
return F_26 ( F_27 ( V_31 ) , V_52 , V_28 , V_2 ) ;
}
static int
F_29 ( struct V_53 * V_54 , int V_55 , void T_3 * V_56 , int * V_27 )
{
const struct V_57 * V_58 = F_30 ( V_54 ) ;
const struct V_59 * V_60 ;
struct V_4 V_5 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_11 . V_12 . V_13 = V_58 -> V_61 ;
V_5 . V_11 . V_62 . V_63 . V_64 = V_58 -> V_65 ;
V_5 . V_14 . V_12 . V_13 = V_58 -> V_66 ;
V_5 . V_14 . V_62 . V_63 . V_64 = V_58 -> V_67 ;
V_5 . V_11 . V_68 = V_52 ;
V_5 . V_14 . V_19 = V_54 -> V_69 ;
if ( V_54 -> V_69 != V_70 && V_54 -> V_69 != V_71 ) {
F_9 ( L_5 ) ;
return - V_72 ;
}
if ( ( unsigned int ) * V_27 < sizeof( struct V_73 ) ) {
F_9 ( L_6 ,
* V_27 , sizeof( struct V_73 ) ) ;
return - V_74 ;
}
V_60 = F_31 ( F_32 ( V_54 ) , V_75 , & V_5 ) ;
if ( V_60 ) {
struct V_73 sin ;
struct V_32 * V_33 = F_33 ( V_60 ) ;
sin . V_76 = V_77 ;
sin . V_78 = V_33 -> V_79 [ V_80 ]
. V_5 . V_14 . V_62 . V_63 . V_64 ;
sin . V_81 . V_82 = V_33 -> V_79 [ V_80 ]
. V_5 . V_14 . V_12 . V_13 ;
memset ( sin . V_83 , 0 , sizeof( sin . V_83 ) ) ;
F_9 ( L_7 ,
& sin . V_81 . V_82 , F_34 ( sin . V_78 ) ) ;
F_35 ( V_33 ) ;
if ( F_36 ( V_56 , & sin , sizeof( sin ) ) != 0 )
return - V_84 ;
else
return 0 ;
}
F_9 ( L_8 ,
& V_5 . V_11 . V_12 . V_13 , F_34 ( V_5 . V_11 . V_62 . V_63 . V_64 ) ,
& V_5 . V_14 . V_12 . V_13 , F_34 ( V_5 . V_14 . V_62 . V_63 . V_64 ) ) ;
return - V_85 ;
}
static int F_37 ( struct V_1 * V_2 ,
const struct V_4 * V_5 )
{
if ( F_38 ( V_2 , V_86 , V_5 -> V_11 . V_12 . V_13 ) ||
F_38 ( V_2 , V_87 , V_5 -> V_14 . V_12 . V_13 ) )
goto V_88;
return 0 ;
V_88:
return - 1 ;
}
static int F_39 ( struct V_89 * V_90 [] ,
struct V_4 * V_91 )
{
if ( ! V_90 [ V_86 ] || ! V_90 [ V_87 ] )
return - V_74 ;
V_91 -> V_11 . V_12 . V_13 = F_40 ( V_90 [ V_86 ] ) ;
V_91 -> V_14 . V_12 . V_13 = F_40 ( V_90 [ V_87 ] ) ;
return 0 ;
}
static int F_41 ( void )
{
return F_42 ( V_92 , V_93 + 1 ) ;
}
static int F_43 ( struct V_94 * V_94 )
{
#if F_44 ( V_95 ) && F_44 ( V_96 )
struct V_97 * V_30 = & V_94 -> V_33 . V_98 ;
V_30 -> V_99 = F_45 ( V_100 ,
sizeof( V_100 ) ,
V_101 ) ;
if ( ! V_30 -> V_99 )
return - V_102 ;
V_30 -> V_99 [ 0 ] . V_103 = & V_104 ;
V_30 -> V_99 [ 1 ] . V_103 = & V_94 -> V_33 . V_105 ;
V_30 -> V_99 [ 2 ] . V_103 = & V_94 -> V_33 . V_106 ;
V_30 -> V_99 [ 3 ] . V_103 = & V_94 -> V_33 . V_107 ;
V_30 -> V_99 [ 4 ] . V_103 = & V_94 -> V_33 . V_108 ;
#endif
return 0 ;
}
static int F_46 ( struct V_94 * V_94 )
{
int V_40 = 0 ;
V_40 = F_47 ( V_94 ,
& V_109 ) ;
if ( V_40 < 0 ) {
F_48 ( L_9 ) ;
goto V_110;
}
V_40 = F_47 ( V_94 ,
& V_111 ) ;
if ( V_40 < 0 ) {
F_48 ( L_10 ) ;
goto V_112;
}
V_40 = F_47 ( V_94 ,
& V_113 ) ;
if ( V_40 < 0 ) {
F_48 ( L_11 ) ;
goto V_114;
}
V_40 = F_49 ( V_94 ,
& V_115 ) ;
if ( V_40 < 0 ) {
F_48 ( L_12 ) ;
goto V_116;
}
return 0 ;
V_116:
F_50 ( V_94 ,
& V_113 ) ;
V_114:
F_50 ( V_94 ,
& V_111 ) ;
V_112:
F_50 ( V_94 ,
& V_109 ) ;
V_110:
return V_40 ;
}
static void F_51 ( struct V_94 * V_94 )
{
F_52 ( V_94 ,
& V_115 ) ;
F_50 ( V_94 ,
& V_113 ) ;
F_50 ( V_94 ,
& V_111 ) ;
F_50 ( V_94 ,
& V_109 ) ;
}
static int T_4 F_53 ( void )
{
int V_40 = 0 ;
F_54 () ;
F_55 () ;
V_40 = F_56 ( & V_117 ) ;
if ( V_40 < 0 ) {
F_57 ( V_118 L_13 ) ;
return V_40 ;
}
V_40 = F_58 ( & V_119 ) ;
if ( V_40 < 0 ) {
F_48 ( L_14 ) ;
goto V_120;
}
V_40 = F_59 ( V_121 ,
F_60 ( V_121 ) ) ;
if ( V_40 < 0 ) {
F_48 ( L_15 ) ;
goto V_122;
}
#if F_44 ( V_123 ) && F_44 ( V_96 )
V_40 = F_61 () ;
if ( V_40 < 0 )
goto V_124;
#endif
return V_40 ;
#if F_44 ( V_123 ) && F_44 ( V_96 )
V_124:
F_62 ( V_121 , F_60 ( V_121 ) ) ;
#endif
V_122:
F_63 ( & V_119 ) ;
V_120:
F_64 ( & V_117 ) ;
return V_40 ;
}
static void T_5 F_65 ( void )
{
F_66 () ;
#if F_44 ( V_123 ) && F_44 ( V_96 )
F_67 () ;
#endif
F_62 ( V_121 , F_60 ( V_121 ) ) ;
F_63 ( & V_119 ) ;
F_64 ( & V_117 ) ;
}
void F_68 ( void )
{
return;
}

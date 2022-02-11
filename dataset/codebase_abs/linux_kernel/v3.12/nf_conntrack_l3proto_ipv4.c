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
V_33 = F_12 ( V_2 , & V_35 ) ;
if ( ! V_33 || V_35 == V_40 )
return V_22 ;
V_37 = F_13 ( V_33 ) ;
if ( ! V_37 )
return V_22 ;
V_39 = F_14 ( V_37 -> V_39 ) ;
if ( ! V_39 )
return V_22 ;
return V_39 -> V_37 ( V_2 , F_15 ( V_2 ) + F_16 ( V_2 ) ,
V_33 , V_35 ) ;
}
static unsigned int F_17 ( unsigned int V_28 ,
struct V_1 * V_2 ,
const struct V_29 * V_30 ,
const struct V_29 * V_31 ,
int (* F_11)( struct V_1 * ) )
{
struct V_32 * V_33 ;
enum V_34 V_35 ;
V_33 = F_12 ( V_2 , & V_35 ) ;
if ( ! V_33 || V_35 == V_40 )
goto V_31;
if ( F_18 ( V_41 , & V_33 -> V_42 ) &&
! F_19 ( V_2 ) ) {
if ( ! F_20 ( V_2 , V_33 , V_35 , F_16 ( V_2 ) ) ) {
F_21 ( F_22 ( V_33 ) , V_43 ) ;
return V_44 ;
}
}
V_31:
return F_23 ( V_2 ) ;
}
static unsigned int F_24 ( unsigned int V_28 ,
struct V_1 * V_2 ,
const struct V_29 * V_30 ,
const struct V_29 * V_31 ,
int (* F_11)( struct V_1 * ) )
{
return F_25 ( F_26 ( V_30 ) , V_45 , V_28 , V_2 ) ;
}
static unsigned int F_27 ( unsigned int V_28 ,
struct V_1 * V_2 ,
const struct V_29 * V_30 ,
const struct V_29 * V_31 ,
int (* F_11)( struct V_1 * ) )
{
if ( V_2 -> V_27 < sizeof( struct V_8 ) ||
F_16 ( V_2 ) < sizeof( struct V_8 ) )
return V_22 ;
return F_25 ( F_26 ( V_31 ) , V_45 , V_28 , V_2 ) ;
}
static int
F_28 ( struct V_46 * V_47 , int V_48 , void T_3 * V_49 , int * V_27 )
{
const struct V_50 * V_51 = F_29 ( V_47 ) ;
const struct V_52 * V_53 ;
struct V_4 V_5 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_11 . V_12 . V_13 = V_51 -> V_54 ;
V_5 . V_11 . V_55 . V_56 . V_57 = V_51 -> V_58 ;
V_5 . V_14 . V_12 . V_13 = V_51 -> V_59 ;
V_5 . V_14 . V_55 . V_56 . V_57 = V_51 -> V_60 ;
V_5 . V_11 . V_61 = V_45 ;
V_5 . V_14 . V_19 = V_47 -> V_62 ;
if ( V_47 -> V_62 != V_63 && V_47 -> V_62 != V_64 ) {
F_9 ( L_4 ) ;
return - V_65 ;
}
if ( ( unsigned int ) * V_27 < sizeof( struct V_66 ) ) {
F_9 ( L_5 ,
* V_27 , sizeof( struct V_66 ) ) ;
return - V_67 ;
}
V_53 = F_30 ( F_31 ( V_47 ) , V_68 , & V_5 ) ;
if ( V_53 ) {
struct V_66 sin ;
struct V_32 * V_33 = F_32 ( V_53 ) ;
sin . V_69 = V_70 ;
sin . V_71 = V_33 -> V_72 [ V_73 ]
. V_5 . V_14 . V_55 . V_56 . V_57 ;
sin . V_74 . V_75 = V_33 -> V_72 [ V_73 ]
. V_5 . V_14 . V_12 . V_13 ;
memset ( sin . V_76 , 0 , sizeof( sin . V_76 ) ) ;
F_9 ( L_6 ,
& sin . V_74 . V_75 , F_33 ( sin . V_71 ) ) ;
F_34 ( V_33 ) ;
if ( F_35 ( V_49 , & sin , sizeof( sin ) ) != 0 )
return - V_77 ;
else
return 0 ;
}
F_9 ( L_7 ,
& V_5 . V_11 . V_12 . V_13 , F_33 ( V_5 . V_11 . V_55 . V_56 . V_57 ) ,
& V_5 . V_14 . V_12 . V_13 , F_33 ( V_5 . V_14 . V_55 . V_56 . V_57 ) ) ;
return - V_78 ;
}
static int F_36 ( struct V_1 * V_2 ,
const struct V_4 * V_5 )
{
if ( F_37 ( V_2 , V_79 , V_5 -> V_11 . V_12 . V_13 ) ||
F_37 ( V_2 , V_80 , V_5 -> V_14 . V_12 . V_13 ) )
goto V_81;
return 0 ;
V_81:
return - 1 ;
}
static int F_38 ( struct V_82 * V_83 [] ,
struct V_4 * V_84 )
{
if ( ! V_83 [ V_79 ] || ! V_83 [ V_80 ] )
return - V_67 ;
V_84 -> V_11 . V_12 . V_13 = F_39 ( V_83 [ V_79 ] ) ;
V_84 -> V_14 . V_12 . V_13 = F_39 ( V_83 [ V_80 ] ) ;
return 0 ;
}
static int F_40 ( void )
{
return F_41 ( V_85 , V_86 + 1 ) ;
}
static int F_42 ( struct V_87 * V_87 )
{
#if F_43 ( V_88 ) && F_43 ( V_89 )
struct V_90 * V_30 = & V_87 -> V_33 . V_91 ;
V_30 -> V_92 = F_44 ( V_93 ,
sizeof( V_93 ) ,
V_94 ) ;
if ( ! V_30 -> V_92 )
return - V_95 ;
V_30 -> V_92 [ 0 ] . V_96 = & V_97 ;
V_30 -> V_92 [ 1 ] . V_96 = & V_87 -> V_33 . V_98 ;
V_30 -> V_92 [ 2 ] . V_96 = & V_87 -> V_33 . V_99 ;
V_30 -> V_92 [ 3 ] . V_96 = & V_87 -> V_33 . V_100 ;
V_30 -> V_92 [ 4 ] . V_96 = & V_87 -> V_33 . V_101 ;
#endif
return 0 ;
}
static int F_45 ( struct V_87 * V_87 )
{
int V_102 = 0 ;
V_102 = F_46 ( V_87 , & V_103 ) ;
if ( V_102 < 0 ) {
F_47 ( L_8 ) ;
goto V_104;
}
V_102 = F_46 ( V_87 , & V_105 ) ;
if ( V_102 < 0 ) {
F_47 ( L_9 ) ;
goto V_106;
}
V_102 = F_46 ( V_87 , & V_107 ) ;
if ( V_102 < 0 ) {
F_47 ( L_10 ) ;
goto V_108;
}
V_102 = F_48 ( V_87 , & V_109 ) ;
if ( V_102 < 0 ) {
F_47 ( L_11 ) ;
goto V_110;
}
return 0 ;
V_110:
F_49 ( V_87 , & V_107 ) ;
V_108:
F_49 ( V_87 , & V_105 ) ;
V_106:
F_49 ( V_87 , & V_103 ) ;
V_104:
return V_102 ;
}
static void F_50 ( struct V_87 * V_87 )
{
F_51 ( V_87 , & V_109 ) ;
F_49 ( V_87 , & V_107 ) ;
F_49 ( V_87 , & V_105 ) ;
F_49 ( V_87 , & V_103 ) ;
}
static int T_4 F_52 ( void )
{
int V_102 = 0 ;
F_53 () ;
F_54 () ;
V_102 = F_55 ( & V_111 ) ;
if ( V_102 < 0 ) {
F_56 ( V_112 L_12 ) ;
return V_102 ;
}
V_102 = F_57 ( & V_113 ) ;
if ( V_102 < 0 ) {
F_47 ( L_13 ) ;
goto V_114;
}
V_102 = F_58 ( V_115 ,
F_59 ( V_115 ) ) ;
if ( V_102 < 0 ) {
F_47 ( L_14 ) ;
goto V_116;
}
V_102 = F_60 ( & V_103 ) ;
if ( V_102 < 0 ) {
F_47 ( L_15 ) ;
goto V_117;
}
V_102 = F_60 ( & V_105 ) ;
if ( V_102 < 0 ) {
F_47 ( L_16 ) ;
goto V_118;
}
V_102 = F_60 ( & V_107 ) ;
if ( V_102 < 0 ) {
F_47 ( L_17 ) ;
goto V_119;
}
V_102 = F_61 ( & V_109 ) ;
if ( V_102 < 0 ) {
F_47 ( L_18 ) ;
goto V_120;
}
#if F_43 ( V_121 ) && F_43 ( V_89 )
V_102 = F_62 () ;
if ( V_102 < 0 )
goto V_122;
#endif
return V_102 ;
#if F_43 ( V_121 ) && F_43 ( V_89 )
V_122:
F_63 ( & V_109 ) ;
#endif
V_120:
F_64 ( & V_107 ) ;
V_119:
F_64 ( & V_105 ) ;
V_118:
F_64 ( & V_103 ) ;
V_117:
F_65 ( V_115 , F_59 ( V_115 ) ) ;
V_116:
F_66 ( & V_113 ) ;
V_114:
F_67 ( & V_111 ) ;
return V_102 ;
}
static void T_5 F_68 ( void )
{
F_69 () ;
#if F_43 ( V_121 ) && F_43 ( V_89 )
F_70 () ;
#endif
F_63 ( & V_109 ) ;
F_64 ( & V_107 ) ;
F_64 ( & V_105 ) ;
F_64 ( & V_103 ) ;
F_65 ( V_115 , F_59 ( V_115 ) ) ;
F_66 ( & V_113 ) ;
F_67 ( & V_111 ) ;
}
void F_71 ( void )
{
return;
}

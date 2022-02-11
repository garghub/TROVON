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
static unsigned int F_10 ( const struct V_28 * V_29 ,
struct V_1 * V_2 ,
const struct V_30 * V_31 )
{
struct V_32 * V_33 ;
enum V_34 V_35 ;
const struct V_36 * V_37 ;
const struct V_38 * V_39 ;
V_33 = F_11 ( V_2 , & V_35 ) ;
if ( ! V_33 || V_35 == V_40 )
return V_22 ;
V_37 = F_12 ( V_33 ) ;
if ( ! V_37 )
return V_22 ;
V_39 = F_13 ( V_37 -> V_39 ) ;
if ( ! V_39 )
return V_22 ;
return V_39 -> V_37 ( V_2 , F_14 ( V_2 ) + F_15 ( V_2 ) ,
V_33 , V_35 ) ;
}
static unsigned int F_16 ( const struct V_28 * V_29 ,
struct V_1 * V_2 ,
const struct V_30 * V_31 )
{
struct V_32 * V_33 ;
enum V_34 V_35 ;
V_33 = F_11 ( V_2 , & V_35 ) ;
if ( ! V_33 || V_35 == V_40 )
goto V_41;
if ( F_17 ( V_42 , & V_33 -> V_43 ) &&
! F_18 ( V_2 ) ) {
if ( ! F_19 ( V_2 , V_33 , V_35 , F_15 ( V_2 ) ) ) {
F_20 ( F_21 ( V_33 ) , V_44 ) ;
return V_45 ;
}
}
V_41:
return F_22 ( V_2 ) ;
}
static unsigned int F_23 ( const struct V_28 * V_29 ,
struct V_1 * V_2 ,
const struct V_30 * V_31 )
{
return F_24 ( F_25 ( V_31 -> V_46 ) , V_47 , V_29 -> V_48 , V_2 ) ;
}
static unsigned int F_26 ( const struct V_28 * V_29 ,
struct V_1 * V_2 ,
const struct V_30 * V_31 )
{
if ( V_2 -> V_27 < sizeof( struct V_8 ) ||
F_15 ( V_2 ) < sizeof( struct V_8 ) )
return V_22 ;
return F_24 ( F_25 ( V_31 -> V_41 ) , V_47 , V_29 -> V_48 , V_2 ) ;
}
static int
F_27 ( struct V_49 * V_50 , int V_51 , void T_3 * V_52 , int * V_27 )
{
const struct V_53 * V_54 = F_28 ( V_50 ) ;
const struct V_55 * V_56 ;
struct V_4 V_5 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_11 . V_12 . V_13 = V_54 -> V_57 ;
V_5 . V_11 . V_58 . V_59 . V_60 = V_54 -> V_61 ;
V_5 . V_14 . V_12 . V_13 = V_54 -> V_62 ;
V_5 . V_14 . V_58 . V_59 . V_60 = V_54 -> V_63 ;
V_5 . V_11 . V_64 = V_47 ;
V_5 . V_14 . V_19 = V_50 -> V_65 ;
if ( V_50 -> V_65 != V_66 && V_50 -> V_65 != V_67 ) {
F_9 ( L_4 ) ;
return - V_68 ;
}
if ( ( unsigned int ) * V_27 < sizeof( struct V_69 ) ) {
F_9 ( L_5 ,
* V_27 , sizeof( struct V_69 ) ) ;
return - V_70 ;
}
V_56 = F_29 ( F_30 ( V_50 ) , & V_71 , & V_5 ) ;
if ( V_56 ) {
struct V_69 sin ;
struct V_32 * V_33 = F_31 ( V_56 ) ;
sin . V_72 = V_73 ;
sin . V_74 = V_33 -> V_75 [ V_76 ]
. V_5 . V_14 . V_58 . V_59 . V_60 ;
sin . V_77 . V_78 = V_33 -> V_75 [ V_76 ]
. V_5 . V_14 . V_12 . V_13 ;
memset ( sin . V_79 , 0 , sizeof( sin . V_79 ) ) ;
F_9 ( L_6 ,
& sin . V_77 . V_78 , F_32 ( sin . V_74 ) ) ;
F_33 ( V_33 ) ;
if ( F_34 ( V_52 , & sin , sizeof( sin ) ) != 0 )
return - V_80 ;
else
return 0 ;
}
F_9 ( L_7 ,
& V_5 . V_11 . V_12 . V_13 , F_32 ( V_5 . V_11 . V_58 . V_59 . V_60 ) ,
& V_5 . V_14 . V_12 . V_13 , F_32 ( V_5 . V_14 . V_58 . V_59 . V_60 ) ) ;
return - V_81 ;
}
static int F_35 ( struct V_1 * V_2 ,
const struct V_4 * V_5 )
{
if ( F_36 ( V_2 , V_82 , V_5 -> V_11 . V_12 . V_13 ) ||
F_36 ( V_2 , V_83 , V_5 -> V_14 . V_12 . V_13 ) )
goto V_84;
return 0 ;
V_84:
return - 1 ;
}
static int F_37 ( struct V_85 * V_86 [] ,
struct V_4 * V_87 )
{
if ( ! V_86 [ V_82 ] || ! V_86 [ V_83 ] )
return - V_70 ;
V_87 -> V_11 . V_12 . V_13 = F_38 ( V_86 [ V_82 ] ) ;
V_87 -> V_14 . V_12 . V_13 = F_38 ( V_86 [ V_83 ] ) ;
return 0 ;
}
static int F_39 ( void )
{
return F_40 ( V_88 , V_89 + 1 ) ;
}
static int F_41 ( struct V_90 * V_90 )
{
#if F_42 ( V_91 ) && F_42 ( V_92 )
struct V_93 * V_46 = & V_90 -> V_33 . V_94 ;
V_46 -> V_95 = F_43 ( V_96 ,
sizeof( V_96 ) ,
V_97 ) ;
if ( ! V_46 -> V_95 )
return - V_98 ;
V_46 -> V_95 [ 0 ] . V_99 = & V_100 ;
V_46 -> V_95 [ 1 ] . V_99 = & V_90 -> V_33 . V_101 ;
V_46 -> V_95 [ 2 ] . V_99 = & V_90 -> V_33 . V_102 ;
V_46 -> V_95 [ 3 ] . V_99 = & V_90 -> V_33 . V_103 ;
V_46 -> V_95 [ 4 ] . V_99 = & V_90 -> V_33 . V_104 ;
#endif
return 0 ;
}
static int F_44 ( struct V_90 * V_90 )
{
int V_105 = 0 ;
V_105 = F_45 ( V_90 , & V_106 ) ;
if ( V_105 < 0 ) {
F_46 ( L_8 ) ;
goto V_107;
}
V_105 = F_45 ( V_90 , & V_108 ) ;
if ( V_105 < 0 ) {
F_46 ( L_9 ) ;
goto V_109;
}
V_105 = F_45 ( V_90 , & V_110 ) ;
if ( V_105 < 0 ) {
F_46 ( L_10 ) ;
goto V_111;
}
V_105 = F_47 ( V_90 , & V_112 ) ;
if ( V_105 < 0 ) {
F_46 ( L_11 ) ;
goto V_113;
}
return 0 ;
V_113:
F_48 ( V_90 , & V_110 ) ;
V_111:
F_48 ( V_90 , & V_108 ) ;
V_109:
F_48 ( V_90 , & V_106 ) ;
V_107:
return V_105 ;
}
static void F_49 ( struct V_90 * V_90 )
{
F_50 ( V_90 , & V_112 ) ;
F_48 ( V_90 , & V_110 ) ;
F_48 ( V_90 , & V_108 ) ;
F_48 ( V_90 , & V_106 ) ;
}
static int T_4 F_51 ( void )
{
int V_105 = 0 ;
F_52 () ;
F_53 () ;
V_105 = F_54 ( & V_114 ) ;
if ( V_105 < 0 ) {
F_55 ( V_115 L_12 ) ;
return V_105 ;
}
V_105 = F_56 ( & V_116 ) ;
if ( V_105 < 0 ) {
F_46 ( L_13 ) ;
goto V_117;
}
V_105 = F_57 ( V_118 ,
F_58 ( V_118 ) ) ;
if ( V_105 < 0 ) {
F_46 ( L_14 ) ;
goto V_119;
}
V_105 = F_59 ( & V_106 ) ;
if ( V_105 < 0 ) {
F_46 ( L_15 ) ;
goto V_120;
}
V_105 = F_59 ( & V_108 ) ;
if ( V_105 < 0 ) {
F_46 ( L_16 ) ;
goto V_121;
}
V_105 = F_59 ( & V_110 ) ;
if ( V_105 < 0 ) {
F_46 ( L_17 ) ;
goto V_122;
}
V_105 = F_60 ( & V_112 ) ;
if ( V_105 < 0 ) {
F_46 ( L_18 ) ;
goto V_123;
}
#if F_42 ( V_124 ) && F_42 ( V_92 )
V_105 = F_61 () ;
if ( V_105 < 0 )
goto V_125;
#endif
return V_105 ;
#if F_42 ( V_124 ) && F_42 ( V_92 )
V_125:
F_62 ( & V_112 ) ;
#endif
V_123:
F_63 ( & V_110 ) ;
V_122:
F_63 ( & V_108 ) ;
V_121:
F_63 ( & V_106 ) ;
V_120:
F_64 ( V_118 , F_58 ( V_118 ) ) ;
V_119:
F_65 ( & V_116 ) ;
V_117:
F_66 ( & V_114 ) ;
return V_105 ;
}
static void T_5 F_67 ( void )
{
F_68 () ;
#if F_42 ( V_124 ) && F_42 ( V_92 )
F_69 () ;
#endif
F_62 ( & V_112 ) ;
F_63 ( & V_110 ) ;
F_63 ( & V_108 ) ;
F_63 ( & V_106 ) ;
F_64 ( V_118 , F_58 ( V_118 ) ) ;
F_65 ( & V_116 ) ;
F_66 ( & V_114 ) ;
}

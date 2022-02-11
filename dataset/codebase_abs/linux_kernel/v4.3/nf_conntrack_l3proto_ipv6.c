static bool F_1 ( const struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * V_5 )
{
const T_1 * V_6 ;
T_1 V_7 [ 8 ] ;
V_6 = F_2 ( V_2 , V_3 + F_3 ( struct V_8 , V_9 ) ,
sizeof( V_7 ) , V_7 ) ;
if ( V_6 == NULL )
return false ;
memcpy ( V_5 -> V_10 . V_11 . V_12 , V_6 , sizeof( V_5 -> V_10 . V_11 . V_12 ) ) ;
memcpy ( V_5 -> V_13 . V_11 . V_12 , V_6 + 4 , sizeof( V_5 -> V_13 . V_11 . V_12 ) ) ;
return true ;
}
static bool F_4 ( struct V_4 * V_5 ,
const struct V_4 * V_14 )
{
memcpy ( V_5 -> V_10 . V_11 . V_12 , V_14 -> V_13 . V_11 . V_12 , sizeof( V_5 -> V_10 . V_11 . V_12 ) ) ;
memcpy ( V_5 -> V_13 . V_11 . V_12 , V_14 -> V_10 . V_11 . V_12 , sizeof( V_5 -> V_13 . V_11 . V_12 ) ) ;
return true ;
}
static void F_5 ( struct V_15 * V_16 ,
const struct V_4 * V_5 )
{
F_6 ( V_16 , L_1 ,
V_5 -> V_10 . V_11 . V_12 , V_5 -> V_13 . V_11 . V_12 ) ;
}
static int F_7 ( const struct V_1 * V_2 , unsigned int V_3 ,
unsigned int * V_17 , T_2 * V_18 )
{
unsigned int V_19 = V_3 + sizeof( struct V_8 ) ;
T_3 V_20 ;
int V_21 ;
T_4 V_22 ;
if ( F_8 ( V_2 , V_3 + F_3 ( struct V_8 , V_22 ) ,
& V_22 , sizeof( V_22 ) ) != 0 ) {
F_9 ( L_2 ) ;
return - V_23 ;
}
V_21 = F_10 ( V_2 , V_19 , & V_22 , & V_20 ) ;
if ( V_21 < 0 || ( V_20 & F_11 ( ~ 0x7 ) ) != 0 ) {
F_9 ( L_3 ) ;
return - V_23 ;
}
* V_17 = V_21 ;
* V_18 = V_22 ;
return V_23 ;
}
static unsigned int F_12 ( const struct V_24 * V_25 ,
struct V_1 * V_2 ,
const struct V_26 * V_27 )
{
struct V_28 * V_29 ;
const struct V_30 * V_31 ;
const struct V_32 * V_33 ;
enum V_34 V_35 ;
T_3 V_20 ;
int V_21 ;
T_4 V_22 ;
V_29 = F_13 ( V_2 , & V_35 ) ;
if ( ! V_29 || V_35 == V_36 )
return V_23 ;
V_31 = F_14 ( V_29 ) ;
if ( ! V_31 )
return V_23 ;
V_33 = F_15 ( V_31 -> V_33 ) ;
if ( ! V_33 )
return V_23 ;
V_22 = F_16 ( V_2 ) -> V_22 ;
V_21 = F_10 ( V_2 , sizeof( struct V_8 ) , & V_22 ,
& V_20 ) ;
if ( V_21 < 0 || ( V_20 & F_11 ( ~ 0x7 ) ) != 0 ) {
F_9 ( L_4 ) ;
return V_23 ;
}
return V_33 -> V_31 ( V_2 , V_21 , V_29 , V_35 ) ;
}
static unsigned int F_17 ( const struct V_24 * V_25 ,
struct V_1 * V_2 ,
const struct V_26 * V_27 )
{
struct V_28 * V_29 ;
enum V_34 V_35 ;
unsigned char V_37 = F_16 ( V_2 ) -> V_22 ;
int V_21 ;
T_3 V_20 ;
V_29 = F_13 ( V_2 , & V_35 ) ;
if ( ! V_29 || V_35 == V_36 )
goto V_38;
V_21 = F_10 ( V_2 , sizeof( struct V_8 ) , & V_37 ,
& V_20 ) ;
if ( V_21 < 0 || ( V_20 & F_11 ( ~ 0x7 ) ) != 0 ) {
F_9 ( L_4 ) ;
goto V_38;
}
if ( F_18 ( V_39 , & V_29 -> V_40 ) &&
! F_19 ( V_2 ) ) {
if ( ! F_20 ( V_2 , V_29 , V_35 , V_21 ) ) {
F_21 ( F_22 ( V_29 ) , V_41 ) ;
return V_42 ;
}
}
V_38:
return F_23 ( V_2 ) ;
}
static unsigned int F_24 ( const struct V_24 * V_25 ,
struct V_1 * V_2 ,
const struct V_26 * V_27 )
{
return F_25 ( F_26 ( V_27 -> V_43 ) , V_44 , V_25 -> V_45 , V_2 ) ;
}
static unsigned int F_27 ( const struct V_24 * V_25 ,
struct V_1 * V_2 ,
const struct V_26 * V_27 )
{
if ( V_2 -> V_46 < sizeof( struct V_8 ) ) {
F_28 ( L_5 ) ;
return V_23 ;
}
return F_25 ( F_26 ( V_27 -> V_38 ) , V_44 , V_25 -> V_45 , V_2 ) ;
}
static int
F_29 ( struct V_47 * V_48 , int V_49 , void T_5 * V_50 , int * V_46 )
{
const struct V_51 * V_52 = F_30 ( V_48 ) ;
const struct V_53 * V_54 = F_31 ( V_48 ) ;
const struct V_55 * V_56 ;
struct V_57 V_58 ;
struct V_4 V_5 = { . V_10 . V_59 = V_60 } ;
struct V_28 * V_29 ;
V_5 . V_10 . V_11 . V_61 = V_48 -> V_62 ;
V_5 . V_10 . V_63 . V_64 . V_65 = V_52 -> V_66 ;
V_5 . V_13 . V_11 . V_61 = V_48 -> V_67 ;
V_5 . V_13 . V_63 . V_64 . V_65 = V_52 -> V_68 ;
V_5 . V_13 . V_18 = V_48 -> V_69 ;
if ( V_48 -> V_69 != V_70 && V_48 -> V_69 != V_71 )
return - V_72 ;
if ( * V_46 < 0 || ( unsigned int ) * V_46 < sizeof( V_58 ) )
return - V_73 ;
V_56 = F_32 ( F_33 ( V_48 ) , & V_74 , & V_5 ) ;
if ( ! V_56 ) {
F_9 ( L_6 ,
& V_5 . V_10 . V_11 . V_12 , F_34 ( V_5 . V_10 . V_63 . V_64 . V_65 ) ,
& V_5 . V_13 . V_11 . V_12 , F_34 ( V_5 . V_13 . V_63 . V_64 . V_65 ) ) ;
return - V_75 ;
}
V_29 = F_35 ( V_56 ) ;
V_58 . V_76 = V_77 ;
V_58 . V_78 = V_29 -> V_79 [ V_80 ] . V_5 . V_13 . V_63 . V_64 . V_65 ;
V_58 . V_81 = V_54 -> V_82 & V_83 ;
memcpy ( & V_58 . V_84 ,
& V_29 -> V_79 [ V_80 ] . V_5 . V_13 . V_11 . V_61 ,
sizeof( V_58 . V_84 ) ) ;
F_36 ( V_29 ) ;
V_58 . V_85 = F_37 ( & V_58 . V_84 ,
V_48 -> V_86 ) ;
return F_38 ( V_50 , & V_58 , sizeof( V_58 ) ) ? - V_87 : 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
const struct V_4 * V_5 )
{
if ( F_40 ( V_2 , V_88 , & V_5 -> V_10 . V_11 . V_61 ) ||
F_40 ( V_2 , V_89 , & V_5 -> V_13 . V_11 . V_61 ) )
goto V_90;
return 0 ;
V_90:
return - 1 ;
}
static int F_41 ( struct V_91 * V_92 [] ,
struct V_4 * V_93 )
{
if ( ! V_92 [ V_88 ] || ! V_92 [ V_89 ] )
return - V_73 ;
V_93 -> V_10 . V_11 . V_61 = F_42 ( V_92 [ V_88 ] ) ;
V_93 -> V_13 . V_11 . V_61 = F_42 ( V_92 [ V_89 ] ) ;
return 0 ;
}
static int F_43 ( void )
{
return F_44 ( V_94 , V_95 + 1 ) ;
}
static int F_45 ( struct V_96 * V_96 )
{
int V_97 = 0 ;
V_97 = F_46 ( V_96 , & V_98 ) ;
if ( V_97 < 0 ) {
F_47 ( L_7 ) ;
goto V_38;
}
V_97 = F_46 ( V_96 , & V_99 ) ;
if ( V_97 < 0 ) {
F_47 ( L_8 ) ;
goto V_100;
}
V_97 = F_46 ( V_96 , & V_101 ) ;
if ( V_97 < 0 ) {
F_47 ( L_9 ) ;
goto V_102;
}
V_97 = F_48 ( V_96 , & V_103 ) ;
if ( V_97 < 0 ) {
F_47 ( L_10 ) ;
goto V_104;
}
return 0 ;
V_104:
F_49 ( V_96 , & V_101 ) ;
V_102:
F_49 ( V_96 , & V_99 ) ;
V_100:
F_49 ( V_96 , & V_98 ) ;
V_38:
return V_97 ;
}
static void F_50 ( struct V_96 * V_96 )
{
F_51 ( V_96 , & V_103 ) ;
F_49 ( V_96 , & V_101 ) ;
F_49 ( V_96 , & V_99 ) ;
F_49 ( V_96 , & V_98 ) ;
}
static int T_6 F_52 ( void )
{
int V_97 = 0 ;
F_53 () ;
F_54 () ;
V_97 = F_55 ( & V_105 ) ;
if ( V_97 < 0 ) {
F_47 ( L_11 ) ;
return V_97 ;
}
V_97 = F_56 ( & V_106 ) ;
if ( V_97 < 0 )
goto V_107;
V_97 = F_57 ( V_108 ,
F_58 ( V_108 ) ) ;
if ( V_97 < 0 ) {
F_47 ( L_12
L_13 ) ;
goto V_109;
}
V_97 = F_59 ( & V_98 ) ;
if ( V_97 < 0 ) {
F_47 ( L_14 ) ;
goto V_110;
}
V_97 = F_59 ( & V_99 ) ;
if ( V_97 < 0 ) {
F_47 ( L_15 ) ;
goto V_100;
}
V_97 = F_59 ( & V_101 ) ;
if ( V_97 < 0 ) {
F_47 ( L_16 ) ;
goto V_102;
}
V_97 = F_60 ( & V_103 ) ;
if ( V_97 < 0 ) {
F_47 ( L_17 ) ;
goto V_104;
}
return V_97 ;
V_104:
F_61 ( & V_101 ) ;
V_102:
F_61 ( & V_99 ) ;
V_100:
F_61 ( & V_98 ) ;
V_110:
F_62 ( V_108 , F_58 ( V_108 ) ) ;
V_109:
F_63 ( & V_106 ) ;
V_107:
F_64 ( & V_105 ) ;
return V_97 ;
}
static void T_7 F_65 ( void )
{
F_66 () ;
F_67 ( & V_103 ) ;
F_61 ( & V_98 ) ;
F_61 ( & V_99 ) ;
F_61 ( & V_101 ) ;
F_62 ( V_108 , F_58 ( V_108 ) ) ;
F_63 ( & V_106 ) ;
F_64 ( & V_105 ) ;
}

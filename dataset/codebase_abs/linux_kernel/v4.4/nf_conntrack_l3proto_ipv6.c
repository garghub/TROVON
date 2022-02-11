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
static unsigned int F_12 ( void * V_24 ,
struct V_1 * V_2 ,
const struct V_25 * V_26 )
{
struct V_27 * V_28 ;
const struct V_29 * V_30 ;
const struct V_31 * V_32 ;
enum V_33 V_34 ;
T_3 V_20 ;
int V_21 ;
T_4 V_22 ;
V_28 = F_13 ( V_2 , & V_34 ) ;
if ( ! V_28 || V_34 == V_35 )
return V_23 ;
V_30 = F_14 ( V_28 ) ;
if ( ! V_30 )
return V_23 ;
V_32 = F_15 ( V_30 -> V_32 ) ;
if ( ! V_32 )
return V_23 ;
V_22 = F_16 ( V_2 ) -> V_22 ;
V_21 = F_10 ( V_2 , sizeof( struct V_8 ) , & V_22 ,
& V_20 ) ;
if ( V_21 < 0 || ( V_20 & F_11 ( ~ 0x7 ) ) != 0 ) {
F_9 ( L_4 ) ;
return V_23 ;
}
return V_32 -> V_30 ( V_2 , V_21 , V_28 , V_34 ) ;
}
static unsigned int F_17 ( void * V_24 ,
struct V_1 * V_2 ,
const struct V_25 * V_26 )
{
struct V_27 * V_28 ;
enum V_33 V_34 ;
unsigned char V_36 = F_16 ( V_2 ) -> V_22 ;
int V_21 ;
T_3 V_20 ;
V_28 = F_13 ( V_2 , & V_34 ) ;
if ( ! V_28 || V_34 == V_35 )
goto V_37;
V_21 = F_10 ( V_2 , sizeof( struct V_8 ) , & V_36 ,
& V_20 ) ;
if ( V_21 < 0 || ( V_20 & F_11 ( ~ 0x7 ) ) != 0 ) {
F_9 ( L_4 ) ;
goto V_37;
}
if ( F_18 ( V_38 , & V_28 -> V_39 ) &&
! F_19 ( V_2 ) ) {
if ( ! F_20 ( V_2 , V_28 , V_34 , V_21 ) ) {
F_21 ( F_22 ( V_28 ) , V_40 ) ;
return V_41 ;
}
}
V_37:
return F_23 ( V_2 ) ;
}
static unsigned int F_24 ( void * V_24 ,
struct V_1 * V_2 ,
const struct V_25 * V_26 )
{
return F_25 ( V_26 -> V_42 , V_43 , V_26 -> V_44 , V_2 ) ;
}
static unsigned int F_26 ( void * V_24 ,
struct V_1 * V_2 ,
const struct V_25 * V_26 )
{
if ( V_2 -> V_45 < sizeof( struct V_8 ) ) {
F_27 ( L_5 ) ;
return V_23 ;
}
return F_25 ( V_26 -> V_42 , V_43 , V_26 -> V_44 , V_2 ) ;
}
static int
F_28 ( struct V_46 * V_47 , int V_48 , void T_5 * V_49 , int * V_45 )
{
const struct V_50 * V_51 = F_29 ( V_47 ) ;
const struct V_52 * V_53 = F_30 ( V_47 ) ;
const struct V_54 * V_55 ;
struct V_56 V_57 ;
struct V_4 V_5 = { . V_10 . V_58 = V_59 } ;
struct V_27 * V_28 ;
V_5 . V_10 . V_11 . V_60 = V_47 -> V_61 ;
V_5 . V_10 . V_62 . V_63 . V_64 = V_51 -> V_65 ;
V_5 . V_13 . V_11 . V_60 = V_47 -> V_66 ;
V_5 . V_13 . V_62 . V_63 . V_64 = V_51 -> V_67 ;
V_5 . V_13 . V_18 = V_47 -> V_68 ;
if ( V_47 -> V_68 != V_69 && V_47 -> V_68 != V_70 )
return - V_71 ;
if ( * V_45 < 0 || ( unsigned int ) * V_45 < sizeof( V_57 ) )
return - V_72 ;
V_55 = F_31 ( F_32 ( V_47 ) , & V_73 , & V_5 ) ;
if ( ! V_55 ) {
F_9 ( L_6 ,
& V_5 . V_10 . V_11 . V_12 , F_33 ( V_5 . V_10 . V_62 . V_63 . V_64 ) ,
& V_5 . V_13 . V_11 . V_12 , F_33 ( V_5 . V_13 . V_62 . V_63 . V_64 ) ) ;
return - V_74 ;
}
V_28 = F_34 ( V_55 ) ;
V_57 . V_75 = V_76 ;
V_57 . V_77 = V_28 -> V_78 [ V_79 ] . V_5 . V_13 . V_62 . V_63 . V_64 ;
V_57 . V_80 = V_53 -> V_81 & V_82 ;
memcpy ( & V_57 . V_83 ,
& V_28 -> V_78 [ V_79 ] . V_5 . V_13 . V_11 . V_60 ,
sizeof( V_57 . V_83 ) ) ;
F_35 ( V_28 ) ;
V_57 . V_84 = F_36 ( & V_57 . V_83 ,
V_47 -> V_85 ) ;
return F_37 ( V_49 , & V_57 , sizeof( V_57 ) ) ? - V_86 : 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
const struct V_4 * V_5 )
{
if ( F_39 ( V_2 , V_87 , & V_5 -> V_10 . V_11 . V_60 ) ||
F_39 ( V_2 , V_88 , & V_5 -> V_13 . V_11 . V_60 ) )
goto V_89;
return 0 ;
V_89:
return - 1 ;
}
static int F_40 ( struct V_90 * V_91 [] ,
struct V_4 * V_92 )
{
if ( ! V_91 [ V_87 ] || ! V_91 [ V_88 ] )
return - V_72 ;
V_92 -> V_10 . V_11 . V_60 = F_41 ( V_91 [ V_87 ] ) ;
V_92 -> V_13 . V_11 . V_60 = F_41 ( V_91 [ V_88 ] ) ;
return 0 ;
}
static int F_42 ( void )
{
return F_43 ( V_93 , V_94 + 1 ) ;
}
static int F_44 ( struct V_42 * V_42 )
{
int V_95 = 0 ;
V_95 = F_45 ( V_42 , & V_96 ) ;
if ( V_95 < 0 ) {
F_46 ( L_7 ) ;
goto V_37;
}
V_95 = F_45 ( V_42 , & V_97 ) ;
if ( V_95 < 0 ) {
F_46 ( L_8 ) ;
goto V_98;
}
V_95 = F_45 ( V_42 , & V_99 ) ;
if ( V_95 < 0 ) {
F_46 ( L_9 ) ;
goto V_100;
}
V_95 = F_47 ( V_42 , & V_101 ) ;
if ( V_95 < 0 ) {
F_46 ( L_10 ) ;
goto V_102;
}
return 0 ;
V_102:
F_48 ( V_42 , & V_99 ) ;
V_100:
F_48 ( V_42 , & V_97 ) ;
V_98:
F_48 ( V_42 , & V_96 ) ;
V_37:
return V_95 ;
}
static void F_49 ( struct V_42 * V_42 )
{
F_50 ( V_42 , & V_101 ) ;
F_48 ( V_42 , & V_99 ) ;
F_48 ( V_42 , & V_97 ) ;
F_48 ( V_42 , & V_96 ) ;
}
static int T_6 F_51 ( void )
{
int V_95 = 0 ;
F_52 () ;
F_53 () ;
V_95 = F_54 ( & V_103 ) ;
if ( V_95 < 0 ) {
F_46 ( L_11 ) ;
return V_95 ;
}
V_95 = F_55 ( & V_104 ) ;
if ( V_95 < 0 )
goto V_105;
V_95 = F_56 ( V_106 ,
F_57 ( V_106 ) ) ;
if ( V_95 < 0 ) {
F_46 ( L_12
L_13 ) ;
goto V_107;
}
V_95 = F_58 ( & V_96 ) ;
if ( V_95 < 0 ) {
F_46 ( L_14 ) ;
goto V_108;
}
V_95 = F_58 ( & V_97 ) ;
if ( V_95 < 0 ) {
F_46 ( L_15 ) ;
goto V_98;
}
V_95 = F_58 ( & V_99 ) ;
if ( V_95 < 0 ) {
F_46 ( L_16 ) ;
goto V_100;
}
V_95 = F_59 ( & V_101 ) ;
if ( V_95 < 0 ) {
F_46 ( L_17 ) ;
goto V_102;
}
return V_95 ;
V_102:
F_60 ( & V_99 ) ;
V_100:
F_60 ( & V_97 ) ;
V_98:
F_60 ( & V_96 ) ;
V_108:
F_61 ( V_106 , F_57 ( V_106 ) ) ;
V_107:
F_62 ( & V_104 ) ;
V_105:
F_63 ( & V_103 ) ;
return V_95 ;
}
static void T_7 F_64 ( void )
{
F_65 () ;
F_66 ( & V_101 ) ;
F_60 ( & V_96 ) ;
F_60 ( & V_97 ) ;
F_60 ( & V_99 ) ;
F_61 ( V_106 , F_57 ( V_106 ) ) ;
F_62 ( & V_104 ) ;
F_63 ( & V_103 ) ;
}

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
static int F_5 ( struct V_15 * V_16 ,
const struct V_4 * V_5 )
{
return F_6 ( V_16 , L_1 ,
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
static unsigned int F_12 ( unsigned int V_24 ,
struct V_1 * V_2 ,
const struct V_25 * V_26 ,
const struct V_25 * V_27 ,
int (* F_13)( struct V_1 * ) )
{
struct V_28 * V_29 ;
const struct V_30 * V_31 ;
const struct V_32 * V_33 ;
enum V_34 V_35 ;
T_3 V_20 ;
int V_21 ;
T_4 V_22 ;
V_29 = F_14 ( V_2 , & V_35 ) ;
if ( ! V_29 || V_35 == V_36 )
return V_23 ;
V_31 = F_15 ( V_29 ) ;
if ( ! V_31 )
return V_23 ;
V_33 = F_16 ( V_31 -> V_33 ) ;
if ( ! V_33 )
return V_23 ;
V_22 = F_17 ( V_2 ) -> V_22 ;
V_21 = F_10 ( V_2 , sizeof( struct V_8 ) , & V_22 ,
& V_20 ) ;
if ( V_21 < 0 || ( V_20 & F_11 ( ~ 0x7 ) ) != 0 ) {
F_9 ( L_4 ) ;
return V_23 ;
}
return V_33 -> V_31 ( V_2 , V_21 , V_29 , V_35 ) ;
}
static unsigned int F_18 ( unsigned int V_24 ,
struct V_1 * V_2 ,
const struct V_25 * V_26 ,
const struct V_25 * V_27 ,
int (* F_13)( struct V_1 * ) )
{
struct V_28 * V_29 ;
enum V_34 V_35 ;
unsigned char V_37 = F_17 ( V_2 ) -> V_22 ;
int V_21 ;
T_3 V_20 ;
V_29 = F_14 ( V_2 , & V_35 ) ;
if ( ! V_29 || V_35 == V_36 )
goto V_27;
V_21 = F_10 ( V_2 , sizeof( struct V_8 ) , & V_37 ,
& V_20 ) ;
if ( V_21 < 0 || ( V_20 & F_11 ( ~ 0x7 ) ) != 0 ) {
F_9 ( L_4 ) ;
goto V_27;
}
if ( F_19 ( V_38 , & V_29 -> V_39 ) &&
! F_20 ( V_2 ) ) {
if ( ! F_21 ( V_2 , V_29 , V_35 , V_21 ) ) {
F_22 ( F_23 ( V_29 ) , V_40 ) ;
return V_41 ;
}
}
V_27:
return F_24 ( V_2 ) ;
}
static unsigned int F_25 ( struct V_42 * V_42 ,
unsigned int V_24 ,
struct V_1 * V_2 ,
const struct V_25 * V_26 ,
const struct V_25 * V_27 ,
int (* F_13)( struct V_1 * ) )
{
struct V_1 * V_43 = V_2 -> V_44 ;
const struct V_30 * V_31 ;
struct V_28 * V_29 ;
enum V_34 V_35 ;
if ( V_43 ) {
if ( ! V_43 -> V_45 ) {
unsigned int V_46 ;
V_46 = F_26 ( V_42 , V_47 , V_24 , V_43 ) ;
if ( V_46 != V_23 )
return V_46 ;
}
V_29 = F_14 ( V_43 , & V_35 ) ;
if ( V_29 != NULL && ! F_27 ( V_29 ) ) {
V_31 = F_15 ( V_29 ) ;
if ( ( V_31 && V_31 -> V_33 ) || ! F_28 ( V_29 ) ) {
F_29 ( V_43 ) ;
F_30 ( V_48 , V_24 , V_43 ,
(struct V_25 * ) V_26 ,
(struct V_25 * ) V_27 ,
F_13 , V_49 + 1 ) ;
return F_31 ( - V_50 ) ;
}
}
F_32 ( V_43 -> V_45 ) ;
V_2 -> V_45 = V_43 -> V_45 ;
V_2 -> V_51 = V_43 -> V_51 ;
return V_23 ;
}
return F_26 ( V_42 , V_47 , V_24 , V_2 ) ;
}
static unsigned int F_33 ( unsigned int V_24 ,
struct V_1 * V_2 ,
const struct V_25 * V_26 ,
const struct V_25 * V_27 ,
int (* F_13)( struct V_1 * ) )
{
return F_25 ( F_34 ( V_26 ) , V_24 , V_2 , V_26 , V_27 , F_13 ) ;
}
static unsigned int F_35 ( unsigned int V_24 ,
struct V_1 * V_2 ,
const struct V_25 * V_26 ,
const struct V_25 * V_27 ,
int (* F_13)( struct V_1 * ) )
{
if ( V_2 -> V_52 < sizeof( struct V_8 ) ) {
F_36 ( L_5 ) ;
return V_23 ;
}
return F_25 ( F_34 ( V_27 ) , V_24 , V_2 , V_26 , V_27 , F_13 ) ;
}
static int
F_37 ( struct V_53 * V_54 , int V_55 , void T_5 * V_56 , int * V_52 )
{
const struct V_57 * V_58 = F_38 ( V_54 ) ;
const struct V_59 * V_60 = F_39 ( V_54 ) ;
const struct V_61 * V_62 ;
struct V_63 V_64 ;
struct V_4 V_5 = { . V_10 . V_65 = V_48 } ;
struct V_28 * V_29 ;
V_5 . V_10 . V_11 . V_66 = V_60 -> V_67 ;
V_5 . V_10 . V_68 . V_69 . V_70 = V_58 -> V_71 ;
V_5 . V_13 . V_11 . V_66 = V_60 -> V_72 ;
V_5 . V_13 . V_68 . V_69 . V_70 = V_58 -> V_73 ;
V_5 . V_13 . V_18 = V_54 -> V_74 ;
if ( V_54 -> V_74 != V_75 && V_54 -> V_74 != V_76 )
return - V_77 ;
if ( * V_52 < 0 || ( unsigned int ) * V_52 < sizeof( V_64 ) )
return - V_78 ;
V_62 = F_40 ( F_41 ( V_54 ) , V_79 , & V_5 ) ;
if ( ! V_62 ) {
F_9 ( L_6 ,
& V_5 . V_10 . V_11 . V_12 , F_42 ( V_5 . V_10 . V_68 . V_69 . V_70 ) ,
& V_5 . V_13 . V_11 . V_12 , F_42 ( V_5 . V_13 . V_68 . V_69 . V_70 ) ) ;
return - V_80 ;
}
V_29 = F_43 ( V_62 ) ;
V_64 . V_81 = V_82 ;
V_64 . V_83 = V_29 -> V_84 [ V_85 ] . V_5 . V_13 . V_68 . V_69 . V_70 ;
V_64 . V_86 = V_60 -> V_87 & V_88 ;
memcpy ( & V_64 . V_89 ,
& V_29 -> V_84 [ V_85 ] . V_5 . V_13 . V_11 . V_66 ,
sizeof( V_64 . V_89 ) ) ;
F_44 ( V_29 ) ;
V_64 . V_90 = F_45 ( & V_64 . V_89 ,
V_54 -> V_91 ) ;
return F_46 ( V_56 , & V_64 , sizeof( V_64 ) ) ? - V_92 : 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
const struct V_4 * V_5 )
{
if ( F_48 ( V_2 , V_93 , sizeof( T_1 ) * 4 ,
& V_5 -> V_10 . V_11 . V_12 ) ||
F_48 ( V_2 , V_94 , sizeof( T_1 ) * 4 ,
& V_5 -> V_13 . V_11 . V_12 ) )
goto V_95;
return 0 ;
V_95:
return - 1 ;
}
static int F_49 ( struct V_96 * V_97 [] ,
struct V_4 * V_98 )
{
if ( ! V_97 [ V_93 ] || ! V_97 [ V_94 ] )
return - V_78 ;
memcpy ( & V_98 -> V_10 . V_11 . V_12 , F_50 ( V_97 [ V_93 ] ) ,
sizeof( T_1 ) * 4 ) ;
memcpy ( & V_98 -> V_13 . V_11 . V_12 , F_50 ( V_97 [ V_94 ] ) ,
sizeof( T_1 ) * 4 ) ;
return 0 ;
}
static int F_51 ( void )
{
return F_52 ( V_99 , V_100 + 1 ) ;
}
static int F_53 ( struct V_42 * V_42 )
{
int V_46 = 0 ;
V_46 = F_54 ( V_42 , & V_101 ) ;
if ( V_46 < 0 ) {
F_55 ( L_7 ) ;
goto V_27;
}
V_46 = F_54 ( V_42 , & V_102 ) ;
if ( V_46 < 0 ) {
F_55 ( L_8 ) ;
goto V_103;
}
V_46 = F_54 ( V_42 , & V_104 ) ;
if ( V_46 < 0 ) {
F_55 ( L_9 ) ;
goto V_105;
}
V_46 = F_56 ( V_42 , & V_106 ) ;
if ( V_46 < 0 ) {
F_55 ( L_10 ) ;
goto V_107;
}
return 0 ;
V_107:
F_57 ( V_42 , & V_104 ) ;
V_105:
F_57 ( V_42 , & V_102 ) ;
V_103:
F_57 ( V_42 , & V_101 ) ;
V_27:
return V_46 ;
}
static void F_58 ( struct V_42 * V_42 )
{
F_59 ( V_42 , & V_106 ) ;
F_57 ( V_42 , & V_104 ) ;
F_57 ( V_42 , & V_102 ) ;
F_57 ( V_42 , & V_101 ) ;
}
static int T_6 F_60 ( void )
{
int V_46 = 0 ;
F_61 () ;
F_62 () ;
V_46 = F_63 ( & V_108 ) ;
if ( V_46 < 0 ) {
F_55 ( L_11 ) ;
return V_46 ;
}
V_46 = F_64 ( & V_109 ) ;
if ( V_46 < 0 )
goto V_110;
V_46 = F_65 ( V_111 ,
F_66 ( V_111 ) ) ;
if ( V_46 < 0 ) {
F_55 ( L_12
L_13 ) ;
goto V_112;
}
V_46 = F_67 ( & V_101 ) ;
if ( V_46 < 0 ) {
F_55 ( L_14 ) ;
goto V_113;
}
V_46 = F_67 ( & V_102 ) ;
if ( V_46 < 0 ) {
F_55 ( L_15 ) ;
goto V_103;
}
V_46 = F_67 ( & V_104 ) ;
if ( V_46 < 0 ) {
F_55 ( L_16 ) ;
goto V_105;
}
V_46 = F_68 ( & V_106 ) ;
if ( V_46 < 0 ) {
F_55 ( L_17 ) ;
goto V_107;
}
return V_46 ;
V_107:
F_69 ( & V_104 ) ;
V_105:
F_69 ( & V_102 ) ;
V_103:
F_69 ( & V_101 ) ;
V_113:
F_70 ( V_111 , F_66 ( V_111 ) ) ;
V_112:
F_71 ( & V_109 ) ;
V_110:
F_72 ( & V_108 ) ;
return V_46 ;
}
static void T_7 F_73 ( void )
{
F_74 () ;
F_75 ( & V_106 ) ;
F_69 ( & V_101 ) ;
F_69 ( & V_102 ) ;
F_69 ( & V_104 ) ;
F_70 ( V_111 , F_66 ( V_111 ) ) ;
F_71 ( & V_109 ) ;
F_72 ( & V_108 ) ;
}

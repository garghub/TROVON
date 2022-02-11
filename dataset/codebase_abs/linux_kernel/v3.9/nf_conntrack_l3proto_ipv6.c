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
F_21 (nf_nat_seq_adjust_hook) V_40 ;
V_40 = F_16 ( V_41 ) ;
if ( ! V_40 ||
! V_40 ( V_2 , V_29 , V_35 , V_21 ) ) {
F_22 ( F_23 ( V_29 ) , V_42 ) ;
return V_43 ;
}
}
V_27:
return F_24 ( V_2 ) ;
}
static unsigned int F_25 ( struct V_44 * V_44 ,
unsigned int V_24 ,
struct V_1 * V_2 ,
const struct V_25 * V_26 ,
const struct V_25 * V_27 ,
int (* F_13)( struct V_1 * ) )
{
struct V_1 * V_45 = V_2 -> V_46 ;
const struct V_30 * V_31 ;
struct V_28 * V_29 ;
enum V_34 V_35 ;
if ( V_45 ) {
if ( ! V_45 -> V_47 ) {
unsigned int V_48 ;
V_48 = F_26 ( V_44 , V_49 , V_24 , V_45 ) ;
if ( V_48 != V_23 )
return V_48 ;
}
V_29 = F_14 ( V_45 , & V_35 ) ;
if ( V_29 != NULL && ! F_27 ( V_29 ) ) {
V_31 = F_15 ( V_29 ) ;
if ( ( V_31 && V_31 -> V_33 ) || ! F_28 ( V_29 ) ) {
F_29 ( V_2 ) ;
F_30 ( V_50 , V_24 , V_45 ,
(struct V_25 * ) V_26 ,
(struct V_25 * ) V_27 ,
F_13 , V_51 + 1 ) ;
return F_31 ( - V_52 ) ;
}
}
F_32 ( V_45 -> V_47 ) ;
V_2 -> V_47 = V_45 -> V_47 ;
V_2 -> V_53 = V_45 -> V_53 ;
return V_23 ;
}
return F_26 ( V_44 , V_49 , V_24 , V_2 ) ;
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
if ( V_2 -> V_54 < sizeof( struct V_8 ) ) {
F_36 ( L_5 ) ;
return V_23 ;
}
return F_25 ( F_34 ( V_27 ) , V_24 , V_2 , V_26 , V_27 , F_13 ) ;
}
static int
F_37 ( struct V_55 * V_56 , int V_57 , void T_5 * V_58 , int * V_54 )
{
const struct V_59 * V_60 = F_38 ( V_56 ) ;
const struct V_61 * V_62 = F_39 ( V_56 ) ;
const struct V_63 * V_64 ;
struct V_65 V_66 ;
struct V_4 V_5 = { . V_10 . V_67 = V_50 } ;
struct V_28 * V_29 ;
V_5 . V_10 . V_11 . V_68 = V_62 -> V_69 ;
V_5 . V_10 . V_70 . V_71 . V_72 = V_60 -> V_73 ;
V_5 . V_13 . V_11 . V_68 = V_62 -> V_74 ;
V_5 . V_13 . V_70 . V_71 . V_72 = V_60 -> V_75 ;
V_5 . V_13 . V_18 = V_56 -> V_76 ;
if ( V_56 -> V_76 != V_77 && V_56 -> V_76 != V_78 )
return - V_79 ;
if ( * V_54 < 0 || ( unsigned int ) * V_54 < sizeof( V_66 ) )
return - V_80 ;
V_64 = F_40 ( F_41 ( V_56 ) , V_81 , & V_5 ) ;
if ( ! V_64 ) {
F_9 ( L_6 ,
& V_5 . V_10 . V_11 . V_12 , F_42 ( V_5 . V_10 . V_70 . V_71 . V_72 ) ,
& V_5 . V_13 . V_11 . V_12 , F_42 ( V_5 . V_13 . V_70 . V_71 . V_72 ) ) ;
return - V_82 ;
}
V_29 = F_43 ( V_64 ) ;
V_66 . V_83 = V_84 ;
V_66 . V_85 = V_29 -> V_86 [ V_87 ] . V_5 . V_13 . V_70 . V_71 . V_72 ;
V_66 . V_88 = V_62 -> V_89 & V_90 ;
memcpy ( & V_66 . V_91 ,
& V_29 -> V_86 [ V_87 ] . V_5 . V_13 . V_11 . V_68 ,
sizeof( V_66 . V_91 ) ) ;
F_44 ( V_29 ) ;
if ( F_45 ( & V_66 . V_91 ) & V_92 )
V_66 . V_93 = V_56 -> V_94 ;
else
V_66 . V_93 = 0 ;
return F_46 ( V_58 , & V_66 , sizeof( V_66 ) ) ? - V_95 : 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
const struct V_4 * V_5 )
{
if ( F_48 ( V_2 , V_96 , sizeof( T_1 ) * 4 ,
& V_5 -> V_10 . V_11 . V_12 ) ||
F_48 ( V_2 , V_97 , sizeof( T_1 ) * 4 ,
& V_5 -> V_13 . V_11 . V_12 ) )
goto V_98;
return 0 ;
V_98:
return - 1 ;
}
static int F_49 ( struct V_99 * V_100 [] ,
struct V_4 * V_101 )
{
if ( ! V_100 [ V_96 ] || ! V_100 [ V_97 ] )
return - V_80 ;
memcpy ( & V_101 -> V_10 . V_11 . V_12 , F_50 ( V_100 [ V_96 ] ) ,
sizeof( T_1 ) * 4 ) ;
memcpy ( & V_101 -> V_13 . V_11 . V_12 , F_50 ( V_100 [ V_97 ] ) ,
sizeof( T_1 ) * 4 ) ;
return 0 ;
}
static int F_51 ( void )
{
return F_52 ( V_102 , V_103 + 1 ) ;
}
static int F_53 ( struct V_44 * V_44 )
{
int V_48 = 0 ;
V_48 = F_54 ( V_44 , & V_104 ) ;
if ( V_48 < 0 ) {
F_55 ( L_7 ) ;
goto V_27;
}
V_48 = F_54 ( V_44 , & V_105 ) ;
if ( V_48 < 0 ) {
F_55 ( L_8 ) ;
goto V_106;
}
V_48 = F_54 ( V_44 , & V_107 ) ;
if ( V_48 < 0 ) {
F_55 ( L_9 ) ;
goto V_108;
}
V_48 = F_56 ( V_44 , & V_109 ) ;
if ( V_48 < 0 ) {
F_55 ( L_10 ) ;
goto V_110;
}
return 0 ;
V_110:
F_57 ( V_44 , & V_107 ) ;
V_108:
F_57 ( V_44 , & V_105 ) ;
V_106:
F_57 ( V_44 , & V_104 ) ;
V_27:
return V_48 ;
}
static void F_58 ( struct V_44 * V_44 )
{
F_59 ( V_44 , & V_109 ) ;
F_57 ( V_44 , & V_107 ) ;
F_57 ( V_44 , & V_105 ) ;
F_57 ( V_44 , & V_104 ) ;
}
static int T_6 F_60 ( void )
{
int V_48 = 0 ;
F_61 () ;
F_62 () ;
V_48 = F_63 ( & V_111 ) ;
if ( V_48 < 0 ) {
F_55 ( L_11 ) ;
return V_48 ;
}
V_48 = F_64 ( & V_112 ) ;
if ( V_48 < 0 )
goto V_113;
V_48 = F_65 ( V_114 ,
F_66 ( V_114 ) ) ;
if ( V_48 < 0 ) {
F_55 ( L_12
L_13 ) ;
goto V_115;
}
V_48 = F_67 ( & V_104 ) ;
if ( V_48 < 0 ) {
F_55 ( L_14 ) ;
goto V_116;
}
V_48 = F_67 ( & V_105 ) ;
if ( V_48 < 0 ) {
F_55 ( L_15 ) ;
goto V_106;
}
V_48 = F_67 ( & V_107 ) ;
if ( V_48 < 0 ) {
F_55 ( L_16 ) ;
goto V_108;
}
V_48 = F_68 ( & V_109 ) ;
if ( V_48 < 0 ) {
F_55 ( L_17 ) ;
goto V_110;
}
return V_48 ;
V_110:
F_69 ( & V_107 ) ;
V_108:
F_69 ( & V_105 ) ;
V_106:
F_69 ( & V_104 ) ;
V_116:
F_70 ( V_114 , F_66 ( V_114 ) ) ;
V_115:
F_71 ( & V_112 ) ;
V_113:
F_72 ( & V_111 ) ;
return V_48 ;
}
static void T_7 F_73 ( void )
{
F_74 () ;
F_75 ( & V_109 ) ;
F_69 ( & V_104 ) ;
F_69 ( & V_105 ) ;
F_69 ( & V_107 ) ;
F_70 ( V_114 , F_66 ( V_114 ) ) ;
F_71 ( & V_112 ) ;
F_72 ( & V_111 ) ;
}

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
unsigned int V_36 ;
T_3 V_20 ;
int V_21 ;
T_4 V_22 ;
V_29 = F_14 ( V_2 , & V_35 ) ;
if ( ! V_29 || V_35 == V_37 )
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
V_36 = V_33 -> V_31 ( V_2 , V_21 , V_29 , V_35 ) ;
if ( V_36 != V_23 && ( V_36 & V_38 ) != V_39 ) {
F_18 ( V_40 , V_24 , V_2 , V_26 , V_27 , NULL ,
L_5 , V_33 -> V_41 ) ;
}
return V_36 ;
}
static unsigned int F_19 ( unsigned int V_24 ,
struct V_1 * V_2 ,
const struct V_25 * V_26 ,
const struct V_25 * V_27 ,
int (* F_13)( struct V_1 * ) )
{
struct V_28 * V_29 ;
enum V_34 V_35 ;
unsigned char V_42 = F_17 ( V_2 ) -> V_22 ;
int V_21 ;
T_3 V_20 ;
V_29 = F_14 ( V_2 , & V_35 ) ;
if ( ! V_29 || V_35 == V_37 )
goto V_27;
V_21 = F_10 ( V_2 , sizeof( struct V_8 ) , & V_42 ,
& V_20 ) ;
if ( V_21 < 0 || ( V_20 & F_11 ( ~ 0x7 ) ) != 0 ) {
F_9 ( L_4 ) ;
goto V_27;
}
if ( F_20 ( V_43 , & V_29 -> V_44 ) &&
! F_21 ( V_2 ) ) {
F_22 (nf_nat_seq_adjust_hook) V_45 ;
V_45 = F_16 ( V_46 ) ;
if ( ! V_45 ||
! V_45 ( V_2 , V_29 , V_35 , V_21 ) ) {
F_23 ( F_24 ( V_29 ) , V_47 ) ;
return V_48 ;
}
}
V_27:
return F_25 ( V_2 ) ;
}
static unsigned int F_26 ( struct V_49 * V_49 ,
unsigned int V_24 ,
struct V_1 * V_2 ,
const struct V_25 * V_26 ,
const struct V_25 * V_27 ,
int (* F_13)( struct V_1 * ) )
{
struct V_1 * V_50 = V_2 -> V_51 ;
const struct V_30 * V_31 ;
struct V_28 * V_29 ;
enum V_34 V_35 ;
if ( V_50 ) {
if ( ! V_50 -> V_52 ) {
unsigned int V_36 ;
V_36 = F_27 ( V_49 , V_53 , V_24 , V_50 ) ;
if ( V_36 != V_23 )
return V_36 ;
}
V_29 = F_14 ( V_50 , & V_35 ) ;
if ( V_29 != NULL && ! F_28 ( V_29 ) ) {
V_31 = F_15 ( V_29 ) ;
if ( ( V_31 && V_31 -> V_33 ) || ! F_29 ( V_29 ) ) {
F_30 ( V_2 ) ;
F_31 ( V_40 , V_24 , V_50 ,
(struct V_25 * ) V_26 ,
(struct V_25 * ) V_27 ,
F_13 , V_54 + 1 ) ;
return F_32 ( - V_55 ) ;
}
}
F_33 ( V_50 -> V_52 ) ;
V_2 -> V_52 = V_50 -> V_52 ;
V_2 -> V_56 = V_50 -> V_56 ;
return V_23 ;
}
return F_27 ( V_49 , V_53 , V_24 , V_2 ) ;
}
static unsigned int F_34 ( unsigned int V_24 ,
struct V_1 * V_2 ,
const struct V_25 * V_26 ,
const struct V_25 * V_27 ,
int (* F_13)( struct V_1 * ) )
{
return F_26 ( F_35 ( V_26 ) , V_24 , V_2 , V_26 , V_27 , F_13 ) ;
}
static unsigned int F_36 ( unsigned int V_24 ,
struct V_1 * V_2 ,
const struct V_25 * V_26 ,
const struct V_25 * V_27 ,
int (* F_13)( struct V_1 * ) )
{
if ( V_2 -> V_57 < sizeof( struct V_8 ) ) {
F_37 ( L_6 ) ;
return V_23 ;
}
return F_26 ( F_35 ( V_27 ) , V_24 , V_2 , V_26 , V_27 , F_13 ) ;
}
static int
F_38 ( struct V_58 * V_59 , int V_60 , void T_5 * V_61 , int * V_57 )
{
const struct V_62 * V_63 = F_39 ( V_59 ) ;
const struct V_64 * V_65 = F_40 ( V_59 ) ;
const struct V_66 * V_67 ;
struct V_68 V_69 ;
struct V_4 V_5 = { . V_10 . V_70 = V_40 } ;
struct V_28 * V_29 ;
V_5 . V_10 . V_11 . V_71 = V_65 -> V_72 ;
V_5 . V_10 . V_73 . V_74 . V_75 = V_63 -> V_76 ;
V_5 . V_13 . V_11 . V_71 = V_65 -> V_77 ;
V_5 . V_13 . V_73 . V_74 . V_75 = V_63 -> V_78 ;
V_5 . V_13 . V_18 = V_59 -> V_79 ;
if ( V_59 -> V_79 != V_80 && V_59 -> V_79 != V_81 )
return - V_82 ;
if ( * V_57 < 0 || ( unsigned int ) * V_57 < sizeof( V_69 ) )
return - V_83 ;
V_67 = F_41 ( F_42 ( V_59 ) , V_84 , & V_5 ) ;
if ( ! V_67 ) {
F_9 ( L_7 ,
& V_5 . V_10 . V_11 . V_12 , F_43 ( V_5 . V_10 . V_73 . V_74 . V_75 ) ,
& V_5 . V_13 . V_11 . V_12 , F_43 ( V_5 . V_13 . V_73 . V_74 . V_75 ) ) ;
return - V_85 ;
}
V_29 = F_44 ( V_67 ) ;
V_69 . V_86 = V_87 ;
V_69 . V_88 = V_29 -> V_89 [ V_90 ] . V_5 . V_13 . V_73 . V_74 . V_75 ;
V_69 . V_91 = V_65 -> V_92 & V_93 ;
memcpy ( & V_69 . V_94 ,
& V_29 -> V_89 [ V_90 ] . V_5 . V_13 . V_11 . V_71 ,
sizeof( V_69 . V_94 ) ) ;
F_45 ( V_29 ) ;
if ( F_46 ( & V_69 . V_94 ) & V_95 )
V_69 . V_96 = V_59 -> V_97 ;
else
V_69 . V_96 = 0 ;
return F_47 ( V_61 , & V_69 , sizeof( V_69 ) ) ? - V_98 : 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
const struct V_4 * V_5 )
{
if ( F_49 ( V_2 , V_99 , sizeof( T_1 ) * 4 ,
& V_5 -> V_10 . V_11 . V_12 ) ||
F_49 ( V_2 , V_100 , sizeof( T_1 ) * 4 ,
& V_5 -> V_13 . V_11 . V_12 ) )
goto V_101;
return 0 ;
V_101:
return - 1 ;
}
static int F_50 ( struct V_102 * V_103 [] ,
struct V_4 * V_104 )
{
if ( ! V_103 [ V_99 ] || ! V_103 [ V_100 ] )
return - V_83 ;
memcpy ( & V_104 -> V_10 . V_11 . V_12 , F_51 ( V_103 [ V_99 ] ) ,
sizeof( T_1 ) * 4 ) ;
memcpy ( & V_104 -> V_13 . V_11 . V_12 , F_51 ( V_103 [ V_100 ] ) ,
sizeof( T_1 ) * 4 ) ;
return 0 ;
}
static int F_52 ( void )
{
return F_53 ( V_105 , V_106 + 1 ) ;
}
static int F_54 ( struct V_49 * V_49 )
{
int V_36 = 0 ;
V_36 = F_55 ( V_49 ,
& V_107 ) ;
if ( V_36 < 0 ) {
F_56 ( V_108 L_8 ) ;
goto V_27;
}
V_36 = F_55 ( V_49 ,
& V_109 ) ;
if ( V_36 < 0 ) {
F_56 ( V_108 L_9 ) ;
goto V_110;
}
V_36 = F_55 ( V_49 ,
& V_111 ) ;
if ( V_36 < 0 ) {
F_56 ( V_108 L_10 ) ;
goto V_112;
}
V_36 = F_57 ( V_49 ,
& V_113 ) ;
if ( V_36 < 0 ) {
F_56 ( V_108 L_11 ) ;
goto V_114;
}
return 0 ;
V_114:
F_58 ( V_49 ,
& V_111 ) ;
V_112:
F_58 ( V_49 ,
& V_109 ) ;
V_110:
F_58 ( V_49 ,
& V_107 ) ;
V_27:
return V_36 ;
}
static void F_59 ( struct V_49 * V_49 )
{
F_60 ( V_49 ,
& V_113 ) ;
F_58 ( V_49 ,
& V_111 ) ;
F_58 ( V_49 ,
& V_109 ) ;
F_58 ( V_49 ,
& V_107 ) ;
}
static int T_6 F_61 ( void )
{
int V_36 = 0 ;
F_62 () ;
F_63 () ;
V_36 = F_64 ( & V_115 ) ;
if ( V_36 < 0 ) {
F_65 ( L_12 ) ;
return V_36 ;
}
V_36 = F_66 ( & V_116 ) ;
if ( V_36 < 0 )
goto V_117;
V_36 = F_67 ( V_118 ,
F_68 ( V_118 ) ) ;
if ( V_36 < 0 ) {
F_65 ( L_13
L_14 ) ;
goto V_119;
}
return V_36 ;
V_119:
F_69 ( & V_116 ) ;
V_117:
F_70 ( & V_115 ) ;
return V_36 ;
}
static void T_7 F_71 ( void )
{
F_72 () ;
F_73 ( V_118 , F_68 ( V_118 ) ) ;
F_69 ( & V_116 ) ;
F_70 ( & V_115 ) ;
}

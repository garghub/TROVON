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
static int F_5 ( const struct V_1 * V_2 , unsigned int V_3 ,
unsigned int * V_15 , T_2 * V_16 )
{
unsigned int V_17 = V_3 + sizeof( struct V_8 ) ;
T_3 V_18 ;
int V_19 ;
T_4 V_20 ;
if ( F_6 ( V_2 , V_3 + F_3 ( struct V_8 , V_20 ) ,
& V_20 , sizeof( V_20 ) ) != 0 ) {
F_7 ( L_1 ) ;
return - V_21 ;
}
V_19 = F_8 ( V_2 , V_17 , & V_20 , & V_18 ) ;
if ( V_19 < 0 || ( V_18 & F_9 ( ~ 0x7 ) ) != 0 ) {
F_7 ( L_2 ) ;
return - V_21 ;
}
* V_15 = V_19 ;
* V_16 = V_20 ;
return V_21 ;
}
static unsigned int F_10 ( void * V_22 ,
struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_25 * V_26 ;
const struct V_27 * V_28 ;
const struct V_29 * V_30 ;
enum V_31 V_32 ;
T_3 V_18 ;
int V_19 ;
T_4 V_20 ;
V_26 = F_11 ( V_2 , & V_32 ) ;
if ( ! V_26 || V_32 == V_33 )
return V_21 ;
V_28 = F_12 ( V_26 ) ;
if ( ! V_28 )
return V_21 ;
V_30 = F_13 ( V_28 -> V_30 ) ;
if ( ! V_30 )
return V_21 ;
V_20 = F_14 ( V_2 ) -> V_20 ;
V_19 = F_8 ( V_2 , sizeof( struct V_8 ) , & V_20 ,
& V_18 ) ;
if ( V_19 < 0 || ( V_18 & F_9 ( ~ 0x7 ) ) != 0 ) {
F_7 ( L_3 ) ;
return V_21 ;
}
return V_30 -> V_28 ( V_2 , V_19 , V_26 , V_32 ) ;
}
static unsigned int F_15 ( void * V_22 ,
struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_25 * V_26 ;
enum V_31 V_32 ;
unsigned char V_34 = F_14 ( V_2 ) -> V_20 ;
int V_19 ;
T_3 V_18 ;
V_26 = F_11 ( V_2 , & V_32 ) ;
if ( ! V_26 || V_32 == V_33 )
goto V_35;
V_19 = F_8 ( V_2 , sizeof( struct V_8 ) , & V_34 ,
& V_18 ) ;
if ( V_19 < 0 || ( V_18 & F_9 ( ~ 0x7 ) ) != 0 ) {
F_7 ( L_3 ) ;
goto V_35;
}
if ( F_16 ( V_36 , & V_26 -> V_37 ) &&
! F_17 ( V_2 ) ) {
if ( ! F_18 ( V_2 , V_26 , V_32 , V_19 ) ) {
F_19 ( F_20 ( V_26 ) , V_38 ) ;
return V_39 ;
}
}
V_35:
return F_21 ( V_2 ) ;
}
static unsigned int F_22 ( void * V_22 ,
struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
return F_23 ( V_24 -> V_40 , V_41 , V_24 -> V_42 , V_2 ) ;
}
static unsigned int F_24 ( void * V_22 ,
struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
if ( V_2 -> V_43 < sizeof( struct V_8 ) ) {
F_25 ( L_4 ) ;
return V_21 ;
}
return F_23 ( V_24 -> V_40 , V_41 , V_24 -> V_42 , V_2 ) ;
}
static int
F_26 ( struct V_44 * V_45 , int V_46 , void T_5 * V_47 , int * V_43 )
{
const struct V_48 * V_49 = F_27 ( V_45 ) ;
const struct V_50 * V_51 = F_28 ( V_45 ) ;
const struct V_52 * V_53 ;
struct V_54 V_55 ;
struct V_4 V_5 = { . V_10 . V_56 = V_57 } ;
struct V_25 * V_26 ;
V_5 . V_10 . V_11 . V_58 = V_45 -> V_59 ;
V_5 . V_10 . V_60 . V_61 . V_62 = V_49 -> V_63 ;
V_5 . V_13 . V_11 . V_58 = V_45 -> V_64 ;
V_5 . V_13 . V_60 . V_61 . V_62 = V_49 -> V_65 ;
V_5 . V_13 . V_16 = V_45 -> V_66 ;
if ( V_45 -> V_66 != V_67 && V_45 -> V_66 != V_68 )
return - V_69 ;
if ( * V_43 < 0 || ( unsigned int ) * V_43 < sizeof( V_55 ) )
return - V_70 ;
V_53 = F_29 ( F_30 ( V_45 ) , & V_71 , & V_5 ) ;
if ( ! V_53 ) {
F_7 ( L_5 ,
& V_5 . V_10 . V_11 . V_12 , F_31 ( V_5 . V_10 . V_60 . V_61 . V_62 ) ,
& V_5 . V_13 . V_11 . V_12 , F_31 ( V_5 . V_13 . V_60 . V_61 . V_62 ) ) ;
return - V_72 ;
}
V_26 = F_32 ( V_53 ) ;
V_55 . V_73 = V_74 ;
V_55 . V_75 = V_26 -> V_76 [ V_77 ] . V_5 . V_13 . V_60 . V_61 . V_62 ;
V_55 . V_78 = V_51 -> V_79 & V_80 ;
memcpy ( & V_55 . V_81 ,
& V_26 -> V_76 [ V_77 ] . V_5 . V_13 . V_11 . V_58 ,
sizeof( V_55 . V_81 ) ) ;
F_33 ( V_26 ) ;
V_55 . V_82 = F_34 ( & V_55 . V_81 ,
V_45 -> V_83 ) ;
return F_35 ( V_47 , & V_55 , sizeof( V_55 ) ) ? - V_84 : 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
const struct V_4 * V_5 )
{
if ( F_37 ( V_2 , V_85 , & V_5 -> V_10 . V_11 . V_58 ) ||
F_37 ( V_2 , V_86 , & V_5 -> V_13 . V_11 . V_58 ) )
goto V_87;
return 0 ;
V_87:
return - 1 ;
}
static int F_38 ( struct V_88 * V_89 [] ,
struct V_4 * V_90 )
{
if ( ! V_89 [ V_85 ] || ! V_89 [ V_86 ] )
return - V_70 ;
V_90 -> V_10 . V_11 . V_58 = F_39 ( V_89 [ V_85 ] ) ;
V_90 -> V_13 . V_11 . V_58 = F_39 ( V_89 [ V_86 ] ) ;
return 0 ;
}
static int F_40 ( struct V_40 * V_40 )
{
struct V_91 * V_92 = F_41 ( V_40 , V_93 ) ;
int V_94 = 0 ;
F_42 ( & V_95 ) ;
V_92 -> V_96 ++ ;
if ( V_92 -> V_96 > 1 )
goto V_97;
V_94 = F_43 ( V_40 ) ;
if ( V_94 < 0 ) {
V_92 -> V_96 = 0 ;
goto V_97;
}
V_94 = F_44 ( V_40 , V_98 ,
F_45 ( V_98 ) ) ;
if ( V_94 )
V_92 -> V_96 = 0 ;
V_97:
F_46 ( & V_95 ) ;
return V_94 ;
}
static void F_47 ( struct V_40 * V_40 )
{
struct V_91 * V_92 = F_41 ( V_40 , V_93 ) ;
F_42 ( & V_95 ) ;
if ( V_92 -> V_96 && ( -- V_92 -> V_96 == 0 ) )
F_48 ( V_40 , V_98 ,
F_45 ( V_98 ) ) ;
F_46 ( & V_95 ) ;
}
static int F_49 ( struct V_40 * V_40 )
{
return F_50 ( V_40 , V_99 ,
F_45 ( V_99 ) ) ;
}
static void F_51 ( struct V_40 * V_40 )
{
F_52 ( V_40 , V_99 ,
F_45 ( V_99 ) ) ;
}
static int T_6 F_53 ( void )
{
int V_100 = 0 ;
F_54 () ;
#if F_55 ( V_101 )
if ( F_56 ( F_57 ( V_102 , V_103 + 1 ) !=
V_104 . V_105 ) )
return - V_70 ;
#endif
V_100 = F_58 ( & V_106 ) ;
if ( V_100 < 0 ) {
F_59 ( L_6 ) ;
return V_100 ;
}
V_100 = F_60 ( & V_107 ) ;
if ( V_100 < 0 )
goto V_108;
V_100 = F_61 ( V_99 ,
F_45 ( V_99 ) ) ;
if ( V_100 < 0 )
goto V_109;
V_100 = F_62 ( & V_104 ) ;
if ( V_100 < 0 ) {
F_59 ( L_7 ) ;
goto V_110;
}
return V_100 ;
V_110:
F_63 ( V_99 ,
F_45 ( V_99 ) ) ;
V_109:
F_64 ( & V_107 ) ;
V_108:
F_65 ( & V_106 ) ;
return V_100 ;
}
static void T_7 F_66 ( void )
{
F_67 () ;
F_68 ( & V_104 ) ;
F_63 ( V_99 ,
F_45 ( V_99 ) ) ;
F_64 ( & V_107 ) ;
F_65 ( & V_106 ) ;
}

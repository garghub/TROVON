static bool F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 [ 0 ] & V_3 ;
}
static bool F_2 ( struct V_4 * V_5 , int V_6 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
T_1 V_10 ;
V_10 = F_3 ( F_4 ( V_6 ) ) &
V_11 ;
return ( V_10 == V_12 ) ||
( V_10 == V_13 ) ;
}
static void F_5 ( struct V_1 * V_1 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_17 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_19 * V_20 = F_7 ( V_17 -> V_18 . V_18 . V_20 ) ;
T_2 V_21 = F_8 ( V_20 -> V_22 -> V_23 ) ;
T_2 V_24 = F_9 ( V_20 -> V_22 -> V_23 ) ;
T_1 * V_25 = ( T_1 * ) V_15 ;
unsigned int V_26 ;
F_10 ( V_21 , 0 ) ;
F_11 ( V_21 ) ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 += 4 ) {
if ( V_26 < sizeof( struct V_14 ) )
F_10 ( V_24 + V_26 , * V_25 ++ ) ;
else
F_10 ( V_24 + V_26 , 0 ) ;
}
F_10 ( V_21 , V_28 ) ;
F_11 ( V_21 ) ;
}
static void F_12 ( struct V_1 * V_1 )
{
struct V_16 * V_29 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_29 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_30 * V_20 = V_29 -> V_18 . V_18 . V_20 ;
enum V_6 V_6 = F_7 ( V_20 ) -> V_6 ;
T_1 V_10 ;
V_10 = F_3 ( F_13 ( V_6 ) ) ;
V_10 &= ~ V_31 ;
V_10 |= V_32 ;
F_10 ( F_13 ( V_6 ) , V_10 ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_14 V_33 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_34 . V_35 = 0 ;
V_33 . V_34 . V_36 = 0x7 ;
V_33 . V_34 . V_37 = 0x2 ;
V_33 . V_34 . V_38 = 0x8 ;
F_5 ( V_1 , & V_33 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
F_16 ( & V_1 -> V_39 , V_40 ,
V_41 ) ;
}
static void F_17 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_17 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
T_1 V_42 ;
T_1 V_43 , V_44 ;
int V_45 = 0x3 ;
static const T_3 V_46 [] = {
[ 0 ] = V_47 << 4 ,
[ 1 ] = V_48 >> 8 ,
[ 2 ] = V_48 & 0xff ,
[ 3 ] = 1 - 1 ,
[ 4 ] = V_49 ,
} ;
int V_26 ;
F_18 ( sizeof( V_46 ) > 20 ) ;
V_42 = V_1 -> V_50 ( V_1 , 0 ) ;
if ( V_8 -> V_51 . V_52 )
F_16 ( & V_1 -> V_39 , V_40 ,
V_41 | V_53 ) ;
else
F_16 ( & V_1 -> V_39 , V_40 ,
V_41 & ~ V_53 ) ;
V_43 = ( F_19 ( V_5 ) -> V_54 >= 9 ) ?
V_55 : F_20 ( V_5 ) ;
V_44 = ( F_19 ( V_5 ) -> V_54 >= 9 ) ?
V_56 : F_21 ( V_5 ) ;
for ( V_26 = 0 ; V_26 < sizeof( V_46 ) ; V_26 += 4 )
F_10 ( V_43 + V_26 ,
F_22 ( & V_46 [ V_26 ] , sizeof( V_46 ) - V_26 ) ) ;
if ( F_19 ( V_5 ) -> V_54 >= 9 ) {
T_1 V_10 ;
V_10 = F_3 ( V_44 ) ;
V_10 &= ~ V_57 ;
V_10 |= V_58 ;
V_10 &= ~ V_59 ;
V_10 |= ( sizeof( V_46 ) << V_60 ) ;
V_10 &= ~ V_61 ;
F_10 ( V_44 , V_10 ) ;
} else {
F_10 ( V_44 ,
V_62 |
( sizeof( V_46 ) << V_60 ) |
( V_45 << V_63 ) |
( V_42 << V_64 ) ) ;
}
}
static void F_23 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_17 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_30 * V_20 = V_17 -> V_18 . V_18 . V_20 ;
enum V_6 V_6 = F_7 ( V_20 ) -> V_6 ;
F_10 ( F_24 ( V_6 ) ,
V_65 |
V_66 |
V_67 ) ;
}
static void F_25 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_17 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_30 * V_20 = V_17 -> V_18 . V_18 . V_20 ;
enum V_6 V_6 = F_7 ( V_20 ) -> V_6 ;
F_10 ( F_24 ( V_6 ) , F_3 ( F_24 ( V_6 ) ) |
V_68 ) ;
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_17 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
T_1 V_69 = 0x1f ;
T_1 V_70 = V_8 -> V_71 . V_51 . V_70 ?
V_8 -> V_71 . V_51 . V_70 + 1 : 2 ;
T_1 V_10 = 0x0 ;
const T_1 V_72 = V_73 ;
if ( V_8 -> V_51 . V_52 ) {
V_10 |= V_74 ;
V_10 |= V_75 ;
V_10 |= V_76 ;
V_10 |= V_77 ;
} else
V_10 |= V_78 ;
F_10 ( F_27 ( V_5 ) , V_10 |
( F_28 ( V_5 ) ? 0 : V_72 ) |
V_69 << V_79 |
V_70 << V_80 |
V_81 ) ;
}
static bool F_29 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_17 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_30 * V_20 = V_17 -> V_18 . V_18 . V_20 ;
struct V_19 * V_19 = F_7 ( V_20 ) ;
F_30 ( & V_8 -> V_51 . V_82 ) ;
F_31 ( ! F_32 ( & V_5 -> V_83 . V_84 ) ) ;
F_31 ( ! F_32 ( & V_20 -> V_85 ) ) ;
V_8 -> V_51 . V_86 = false ;
if ( F_33 ( V_5 ) && V_17 -> V_87 != V_88 ) {
F_34 ( L_1 ) ;
return false ;
}
if ( ! V_89 . V_90 ) {
F_34 ( L_2 ) ;
return false ;
}
if ( F_33 ( V_5 ) &&
F_3 ( F_35 ( V_19 -> V_22 -> V_23 ) ) &
V_91 ) {
F_34 ( L_3 ) ;
return false ;
}
if ( F_33 ( V_5 ) &&
V_19 -> V_22 -> V_18 . V_92 . V_93 & V_94 ) {
F_34 ( L_4 ) ;
return false ;
}
V_8 -> V_51 . V_86 = true ;
return true ;
}
static void F_36 ( struct V_1 * V_1 )
{
struct V_16 * V_29 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_29 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
F_31 ( F_3 ( F_27 ( V_5 ) ) & V_81 ) ;
F_31 ( V_8 -> V_51 . V_95 ) ;
F_30 ( & V_8 -> V_51 . V_82 ) ;
if ( F_37 ( V_5 ) )
F_26 ( V_1 ) ;
else
F_25 ( V_1 ) ;
V_8 -> V_51 . V_95 = true ;
}
void F_38 ( struct V_1 * V_1 )
{
struct V_16 * V_29 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_29 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
if ( ! F_39 ( V_5 ) ) {
F_34 ( L_5 ) ;
return;
}
if ( ! F_1 ( V_1 ) ) {
F_34 ( L_6 ) ;
return;
}
F_40 ( & V_8 -> V_51 . V_82 ) ;
if ( V_8 -> V_51 . V_96 ) {
F_34 ( L_7 ) ;
goto V_97;
}
if ( ! F_29 ( V_1 ) )
goto V_97;
V_8 -> V_51 . V_52 = V_8 -> V_71 . V_51 . V_98 ;
if ( ( V_1 -> V_2 [ 1 ] & V_99 ) ||
( F_28 ( V_5 ) && V_29 -> V_87 != V_88 ) )
V_8 -> V_51 . V_52 = true ;
V_8 -> V_51 . V_100 = 0 ;
if ( F_37 ( V_5 ) ) {
F_14 ( V_1 ) ;
F_10 ( F_41 ( V_5 ) , V_101 |
V_102 | V_103 ) ;
F_17 ( V_1 ) ;
if ( F_19 ( V_5 ) -> V_54 >= 9 )
F_36 ( V_1 ) ;
} else {
F_12 ( V_1 ) ;
F_15 ( V_1 ) ;
F_23 ( V_1 ) ;
}
V_8 -> V_51 . V_96 = V_1 ;
V_97:
F_42 ( & V_8 -> V_51 . V_82 ) ;
}
static void F_43 ( struct V_1 * V_1 )
{
struct V_16 * V_29 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_29 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_19 * V_19 =
F_7 ( V_29 -> V_18 . V_18 . V_20 ) ;
T_1 V_10 ;
if ( V_8 -> V_51 . V_95 ) {
if ( F_44 ( ( F_3 ( F_4 ( V_19 -> V_6 ) ) &
V_104 ) == 0 , 1 ) )
F_45 ( 1 , L_8 ) ;
V_10 = F_3 ( F_24 ( V_19 -> V_6 ) ) ;
V_10 &= ~ V_68 ;
V_10 &= ~ V_67 ;
V_10 &= ~ V_105 ;
F_10 ( F_24 ( V_19 -> V_6 ) , V_10 ) ;
V_8 -> V_51 . V_95 = false ;
} else {
F_31 ( F_2 ( V_5 , V_19 -> V_6 ) ) ;
}
}
static void F_46 ( struct V_1 * V_1 )
{
struct V_16 * V_29 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_29 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
if ( V_8 -> V_51 . V_95 ) {
F_10 ( F_27 ( V_5 ) ,
F_3 ( F_27 ( V_5 ) ) & ~ V_81 ) ;
if ( F_47 ( ( F_3 ( F_48 ( V_5 ) ) &
V_106 ) == 0 , 2000 , 10 ) )
F_49 ( L_9 ) ;
V_8 -> V_51 . V_95 = false ;
} else {
F_31 ( F_3 ( F_27 ( V_5 ) ) & V_81 ) ;
}
}
void F_50 ( struct V_1 * V_1 )
{
struct V_16 * V_29 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_29 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
F_40 ( & V_8 -> V_51 . V_82 ) ;
if ( ! V_8 -> V_51 . V_96 ) {
F_42 ( & V_8 -> V_51 . V_82 ) ;
return;
}
if ( F_37 ( V_5 ) )
F_46 ( V_1 ) ;
else
F_43 ( V_1 ) ;
V_8 -> V_51 . V_96 = NULL ;
F_42 ( & V_8 -> V_51 . V_82 ) ;
F_51 ( & V_8 -> V_51 . V_107 ) ;
}
static void F_52 ( struct V_108 * V_107 )
{
struct V_7 * V_8 =
F_53 ( V_107 , F_54 ( * V_8 ) , V_51 . V_107 . V_107 ) ;
struct V_1 * V_1 = V_8 -> V_51 . V_96 ;
struct V_30 * V_20 = F_6 ( V_1 ) -> V_18 . V_18 . V_20 ;
enum V_6 V_6 = F_7 ( V_20 ) -> V_6 ;
if ( F_37 ( V_8 -> V_5 ) ) {
if ( F_44 ( ( F_3 ( F_48 ( V_8 -> V_5 ) ) &
V_106 ) == 0 , 50 ) ) {
F_49 ( L_10 ) ;
return;
}
} else {
if ( F_44 ( ( F_3 ( F_4 ( V_6 ) ) &
V_104 ) == 0 , 1 ) ) {
F_49 ( L_10 ) ;
return;
}
}
F_40 ( & V_8 -> V_51 . V_82 ) ;
V_1 = V_8 -> V_51 . V_96 ;
if ( ! V_1 )
goto V_97;
if ( V_8 -> V_51 . V_100 )
goto V_97;
F_36 ( V_1 ) ;
V_97:
F_42 ( & V_8 -> V_51 . V_82 ) ;
}
static void F_55 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_1 * V_1 = V_8 -> V_51 . V_96 ;
struct V_30 * V_20 = F_6 ( V_1 ) -> V_18 . V_18 . V_20 ;
enum V_6 V_6 = F_7 ( V_20 ) -> V_6 ;
T_2 V_10 ;
if ( ! V_8 -> V_51 . V_95 )
return;
if ( F_37 ( V_5 ) ) {
V_10 = F_3 ( F_27 ( V_5 ) ) ;
F_31 ( ! ( V_10 & V_81 ) ) ;
F_10 ( F_27 ( V_5 ) , V_10 & ~ V_81 ) ;
} else {
V_10 = F_3 ( F_24 ( V_6 ) ) ;
V_10 &= ~ V_68 ;
F_10 ( F_24 ( V_6 ) , V_10 ) ;
F_16 ( & V_1 -> V_39 , V_48 ,
V_49 ) ;
}
V_8 -> V_51 . V_95 = false ;
}
void F_56 ( struct V_4 * V_5 ,
unsigned V_109 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_30 * V_20 ;
enum V_6 V_6 ;
F_40 ( & V_8 -> V_51 . V_82 ) ;
if ( ! V_8 -> V_51 . V_96 ) {
F_42 ( & V_8 -> V_51 . V_82 ) ;
return;
}
V_20 = F_6 ( V_8 -> V_51 . V_96 ) -> V_18 . V_18 . V_20 ;
V_6 = F_7 ( V_20 ) -> V_6 ;
F_55 ( V_5 ) ;
V_109 &= F_57 ( V_6 ) ;
V_8 -> V_51 . V_100 |= V_109 ;
F_42 ( & V_8 -> V_51 . V_82 ) ;
}
void F_58 ( struct V_4 * V_5 ,
unsigned V_109 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_30 * V_20 ;
enum V_6 V_6 ;
F_40 ( & V_8 -> V_51 . V_82 ) ;
if ( ! V_8 -> V_51 . V_96 ) {
F_42 ( & V_8 -> V_51 . V_82 ) ;
return;
}
V_20 = F_6 ( V_8 -> V_51 . V_96 ) -> V_18 . V_18 . V_20 ;
V_6 = F_7 ( V_20 ) -> V_6 ;
V_8 -> V_51 . V_100 &= ~ V_109 ;
if ( F_33 ( V_5 ) &&
( V_109 & F_59 ( V_6 ) ) )
F_55 ( V_5 ) ;
if ( ! F_37 ( V_5 ) )
F_55 ( V_5 ) ;
if ( ! V_8 -> V_51 . V_95 && ! V_8 -> V_51 . V_100 )
F_60 ( & V_8 -> V_51 . V_107 ,
F_61 ( 100 ) ) ;
F_42 ( & V_8 -> V_51 . V_82 ) ;
}
void F_62 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
F_63 ( & V_8 -> V_51 . V_107 , F_52 ) ;
F_64 ( & V_8 -> V_51 . V_82 ) ;
}

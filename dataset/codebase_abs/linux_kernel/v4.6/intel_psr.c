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
const struct V_14 * V_15 )
{
struct V_16 * V_17 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_17 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_19 * V_20 = F_7 ( V_17 -> V_18 . V_18 . V_20 ) ;
enum V_21 V_22 = V_20 -> V_23 -> V_22 ;
T_2 V_24 = F_8 ( V_22 ) ;
T_1 * V_25 = ( T_1 * ) V_15 ;
unsigned int V_26 ;
F_9 ( V_24 , 0 ) ;
F_10 ( V_24 ) ;
for ( V_26 = 0 ; V_26 < sizeof( * V_15 ) ; V_26 += 4 ) {
F_9 ( F_11 ( V_22 ,
V_26 >> 2 ) , * V_25 ) ;
V_25 ++ ;
}
for (; V_26 < V_27 ; V_26 += 4 )
F_9 ( F_11 ( V_22 ,
V_26 >> 2 ) , 0 ) ;
F_9 ( V_24 , V_28 ) ;
F_10 ( V_24 ) ;
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
F_9 ( F_13 ( V_6 ) , V_10 ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_14 V_33 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_34 . V_35 = 0 ;
V_33 . V_34 . V_36 = 0x7 ;
V_33 . V_34 . V_37 = 0x3 ;
V_33 . V_34 . V_38 = 0xb ;
F_5 ( V_1 , & V_33 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_14 V_33 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_34 . V_35 = 0 ;
V_33 . V_34 . V_36 = 0x7 ;
V_33 . V_34 . V_37 = 0x2 ;
V_33 . V_34 . V_38 = 0x8 ;
F_5 ( V_1 , & V_33 ) ;
}
static void F_16 ( struct V_1 * V_1 )
{
F_17 ( & V_1 -> V_39 , V_40 ,
V_41 | V_42 ) ;
}
static T_2 F_18 ( struct V_7 * V_8 ,
enum V_43 V_43 )
{
if ( F_19 ( V_8 ) -> V_44 >= 9 )
return F_20 ( V_43 ) ;
else
return V_45 ;
}
static T_2 F_21 ( struct V_7 * V_8 ,
enum V_43 V_43 , int V_46 )
{
if ( F_19 ( V_8 ) -> V_44 >= 9 )
return F_22 ( V_43 , V_46 ) ;
else
return F_23 ( V_46 ) ;
}
static void F_24 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_17 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
T_1 V_47 ;
T_2 V_48 ;
int V_49 = 0x3 ;
static const T_3 V_50 [] = {
[ 0 ] = V_51 << 4 ,
[ 1 ] = V_52 >> 8 ,
[ 2 ] = V_52 & 0xff ,
[ 3 ] = 1 - 1 ,
[ 4 ] = V_53 ,
} ;
enum V_43 V_43 = V_17 -> V_43 ;
int V_26 ;
F_25 ( sizeof( V_50 ) > 20 ) ;
V_47 = V_1 -> V_54 ( V_1 , 0 ) ;
if ( V_8 -> V_55 . V_56 )
F_17 ( & V_1 -> V_39 ,
V_57 ,
V_58 ) ;
V_48 = F_18 ( V_8 , V_43 ) ;
for ( V_26 = 0 ; V_26 < sizeof( V_50 ) ; V_26 += 4 )
F_9 ( F_21 ( V_8 , V_43 , V_26 >> 2 ) ,
F_26 ( & V_50 [ V_26 ] , sizeof( V_50 ) - V_26 ) ) ;
if ( F_19 ( V_5 ) -> V_44 >= 9 ) {
T_1 V_10 ;
V_10 = F_3 ( V_48 ) ;
V_10 &= ~ V_59 ;
V_10 |= V_60 ;
V_10 &= ~ V_61 ;
V_10 |= ( sizeof( V_50 ) << V_62 ) ;
V_10 &= ~ V_63 ;
V_10 &= ~ V_64 ;
V_10 &= ~ V_65 ;
F_9 ( V_48 , V_10 ) ;
} else {
F_9 ( V_48 ,
V_66 |
( sizeof( V_50 ) << V_62 ) |
( V_49 << V_67 ) |
( V_47 << V_68 ) ) ;
}
if ( V_8 -> V_55 . V_69 )
F_17 ( & V_1 -> V_39 , V_40 ,
V_41 | V_42 ) ;
else
F_17 ( & V_1 -> V_39 , V_40 ,
V_41 ) ;
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_17 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_30 * V_20 = V_17 -> V_18 . V_18 . V_20 ;
enum V_6 V_6 = F_7 ( V_20 ) -> V_6 ;
F_9 ( F_28 ( V_6 ) ,
V_70 |
V_71 |
V_72 ) ;
}
static void F_29 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_17 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_30 * V_20 = V_17 -> V_18 . V_18 . V_20 ;
enum V_6 V_6 = F_7 ( V_20 ) -> V_6 ;
F_9 ( F_28 ( V_6 ) , F_3 ( F_28 ( V_6 ) ) |
V_73 ) ;
}
static void F_30 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_17 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
T_1 V_74 = 0x1f ;
T_1 V_75 = F_31 ( 6 , V_8 -> V_76 . V_55 . V_75 ) ;
T_1 V_10 = 0x0 ;
if ( F_32 ( V_5 ) )
V_10 |= V_77 ;
if ( V_8 -> V_55 . V_69 )
V_10 |= V_78 ;
F_9 ( V_79 , V_10 |
V_74 << V_80 |
V_75 << V_81 |
V_82 ) ;
if ( V_8 -> V_55 . V_83 )
F_9 ( V_84 , V_85 |
V_86 | V_87 ) ;
}
static bool F_33 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_17 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_30 * V_20 = V_17 -> V_18 . V_18 . V_20 ;
struct V_19 * V_19 = F_7 ( V_20 ) ;
F_34 ( & V_8 -> V_55 . V_88 ) ;
F_35 ( ! F_36 ( & V_5 -> V_89 . V_90 ) ) ;
F_35 ( ! F_36 ( & V_20 -> V_91 ) ) ;
V_8 -> V_55 . V_92 = false ;
if ( F_37 ( V_5 ) && V_17 -> V_43 != V_93 ) {
F_38 ( L_1 ) ;
return false ;
}
if ( ! V_94 . V_95 ) {
F_38 ( L_2 ) ;
return false ;
}
if ( ( F_39 ( V_5 ) || F_40 ( V_5 ) ) &&
! V_8 -> V_55 . V_69 ) {
F_41 ( L_3 ) ;
return false ;
}
if ( F_32 ( V_5 ) &&
F_3 ( F_42 ( V_19 -> V_23 -> V_22 ) ) &
V_96 ) {
F_38 ( L_4 ) ;
return false ;
}
if ( F_32 ( V_5 ) &&
V_19 -> V_23 -> V_18 . V_97 . V_98 & V_99 ) {
F_38 ( L_5 ) ;
return false ;
}
V_8 -> V_55 . V_92 = true ;
return true ;
}
static void F_43 ( struct V_1 * V_1 )
{
struct V_16 * V_29 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_29 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
F_35 ( F_3 ( V_79 ) & V_82 ) ;
F_35 ( V_8 -> V_55 . V_100 ) ;
F_34 ( & V_8 -> V_55 . V_88 ) ;
if ( F_37 ( V_5 ) )
F_30 ( V_1 ) ;
else
F_29 ( V_1 ) ;
V_8 -> V_55 . V_100 = true ;
}
void F_44 ( struct V_1 * V_1 )
{
struct V_16 * V_29 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_29 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_19 * V_20 = F_7 ( V_29 -> V_18 . V_18 . V_20 ) ;
if ( ! F_45 ( V_5 ) ) {
F_38 ( L_6 ) ;
return;
}
if ( ! F_1 ( V_1 ) ) {
F_38 ( L_7 ) ;
return;
}
F_46 ( & V_8 -> V_55 . V_88 ) ;
if ( V_8 -> V_55 . V_101 ) {
F_38 ( L_8 ) ;
goto V_102;
}
if ( ! F_33 ( V_1 ) )
goto V_102;
V_8 -> V_55 . V_103 = 0 ;
if ( F_37 ( V_5 ) ) {
F_15 ( V_1 ) ;
if ( V_8 -> V_55 . V_83 ) {
if ( V_20 -> V_23 -> V_104 > 3200 ||
V_20 -> V_23 -> V_105 > 2000 )
V_8 -> V_55 . V_83 = false ;
else
F_14 ( V_1 ) ;
}
F_9 ( V_106 , V_107 |
V_108 | V_109 ) ;
F_24 ( V_1 ) ;
if ( F_19 ( V_5 ) -> V_44 >= 9 )
F_43 ( V_1 ) ;
} else {
F_12 ( V_1 ) ;
F_16 ( V_1 ) ;
F_27 ( V_1 ) ;
}
if ( F_19 ( V_5 ) -> V_44 < 9 )
F_47 ( & V_8 -> V_55 . V_110 ,
F_48 ( V_1 -> V_111 * 5 ) ) ;
V_8 -> V_55 . V_101 = V_1 ;
V_102:
F_49 ( & V_8 -> V_55 . V_88 ) ;
}
static void F_50 ( struct V_1 * V_1 )
{
struct V_16 * V_29 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_29 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_19 * V_19 =
F_7 ( V_29 -> V_18 . V_18 . V_20 ) ;
T_1 V_10 ;
if ( V_8 -> V_55 . V_100 ) {
if ( F_51 ( ( F_3 ( F_4 ( V_19 -> V_6 ) ) &
V_112 ) == 0 , 1 ) )
F_52 ( 1 , L_9 ) ;
V_10 = F_3 ( F_28 ( V_19 -> V_6 ) ) ;
V_10 &= ~ V_73 ;
V_10 &= ~ V_72 ;
V_10 &= ~ V_113 ;
F_9 ( F_28 ( V_19 -> V_6 ) , V_10 ) ;
V_8 -> V_55 . V_100 = false ;
} else {
F_35 ( F_2 ( V_5 , V_19 -> V_6 ) ) ;
}
}
static void F_53 ( struct V_1 * V_1 )
{
struct V_16 * V_29 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_29 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
if ( V_8 -> V_55 . V_100 ) {
F_9 ( V_79 ,
F_3 ( V_79 ) & ~ V_82 ) ;
if ( F_54 ( ( F_3 ( V_114 ) &
V_115 ) == 0 , 2000 , 10 ) )
F_41 ( L_10 ) ;
V_8 -> V_55 . V_100 = false ;
} else {
F_35 ( F_3 ( V_79 ) & V_82 ) ;
}
}
void F_55 ( struct V_1 * V_1 )
{
struct V_16 * V_29 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_29 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
F_46 ( & V_8 -> V_55 . V_88 ) ;
if ( ! V_8 -> V_55 . V_101 ) {
F_49 ( & V_8 -> V_55 . V_88 ) ;
return;
}
if ( F_37 ( V_5 ) )
F_53 ( V_1 ) ;
else
F_50 ( V_1 ) ;
F_17 ( & V_1 -> V_39 , V_40 , 0 ) ;
V_8 -> V_55 . V_101 = NULL ;
F_49 ( & V_8 -> V_55 . V_88 ) ;
F_56 ( & V_8 -> V_55 . V_110 ) ;
}
static void F_57 ( struct V_116 * V_110 )
{
struct V_7 * V_8 =
F_58 ( V_110 , F_59 ( * V_8 ) , V_55 . V_110 . V_110 ) ;
struct V_1 * V_1 = V_8 -> V_55 . V_101 ;
struct V_30 * V_20 = F_6 ( V_1 ) -> V_18 . V_18 . V_20 ;
enum V_6 V_6 = F_7 ( V_20 ) -> V_6 ;
if ( F_37 ( V_8 -> V_5 ) ) {
if ( F_51 ( ( F_3 ( V_114 ) &
V_115 ) == 0 , 50 ) ) {
F_41 ( L_11 ) ;
return;
}
} else {
if ( F_51 ( ( F_3 ( F_4 ( V_6 ) ) &
V_112 ) == 0 , 1 ) ) {
F_41 ( L_11 ) ;
return;
}
}
F_46 ( & V_8 -> V_55 . V_88 ) ;
V_1 = V_8 -> V_55 . V_101 ;
if ( ! V_1 )
goto V_102;
if ( V_8 -> V_55 . V_103 )
goto V_102;
F_43 ( V_1 ) ;
V_102:
F_49 ( & V_8 -> V_55 . V_88 ) ;
}
static void F_60 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_1 * V_1 = V_8 -> V_55 . V_101 ;
struct V_30 * V_20 = F_6 ( V_1 ) -> V_18 . V_18 . V_20 ;
enum V_6 V_6 = F_7 ( V_20 ) -> V_6 ;
T_4 V_10 ;
if ( ! V_8 -> V_55 . V_100 )
return;
if ( F_37 ( V_5 ) ) {
V_10 = F_3 ( V_79 ) ;
F_35 ( ! ( V_10 & V_82 ) ) ;
F_9 ( V_79 , V_10 & ~ V_82 ) ;
} else {
V_10 = F_3 ( F_28 ( V_6 ) ) ;
V_10 &= ~ V_73 ;
F_9 ( F_28 ( V_6 ) , V_10 ) ;
F_17 ( & V_1 -> V_39 , V_52 ,
V_53 ) ;
}
V_8 -> V_55 . V_100 = false ;
}
void F_61 ( struct V_4 * V_5 ,
unsigned V_117 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_30 * V_20 ;
enum V_6 V_6 ;
T_4 V_10 ;
if ( ! F_39 ( V_5 ) && ! F_40 ( V_5 ) )
return;
F_46 ( & V_8 -> V_55 . V_88 ) ;
if ( ! V_8 -> V_55 . V_101 ) {
F_49 ( & V_8 -> V_55 . V_88 ) ;
return;
}
V_20 = F_6 ( V_8 -> V_55 . V_101 ) -> V_18 . V_18 . V_20 ;
V_6 = F_7 ( V_20 ) -> V_6 ;
if ( V_117 & F_62 ( V_6 ) ) {
V_10 = F_3 ( F_28 ( V_6 ) ) ;
F_9 ( F_28 ( V_6 ) , V_10 | V_118 ) ;
}
F_49 ( & V_8 -> V_55 . V_88 ) ;
}
void F_63 ( struct V_4 * V_5 ,
unsigned V_117 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_30 * V_20 ;
enum V_6 V_6 ;
F_46 ( & V_8 -> V_55 . V_88 ) ;
if ( ! V_8 -> V_55 . V_101 ) {
F_49 ( & V_8 -> V_55 . V_88 ) ;
return;
}
V_20 = F_6 ( V_8 -> V_55 . V_101 ) -> V_18 . V_18 . V_20 ;
V_6 = F_7 ( V_20 ) -> V_6 ;
V_117 &= F_62 ( V_6 ) ;
V_8 -> V_55 . V_103 |= V_117 ;
if ( V_117 )
F_60 ( V_5 ) ;
F_49 ( & V_8 -> V_55 . V_88 ) ;
}
void F_64 ( struct V_4 * V_5 ,
unsigned V_117 , enum V_119 V_120 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_30 * V_20 ;
enum V_6 V_6 ;
F_46 ( & V_8 -> V_55 . V_88 ) ;
if ( ! V_8 -> V_55 . V_101 ) {
F_49 ( & V_8 -> V_55 . V_88 ) ;
return;
}
V_20 = F_6 ( V_8 -> V_55 . V_101 ) -> V_18 . V_18 . V_20 ;
V_6 = F_7 ( V_20 ) -> V_6 ;
V_117 &= F_62 ( V_6 ) ;
V_8 -> V_55 . V_103 &= ~ V_117 ;
if ( V_117 )
F_60 ( V_5 ) ;
if ( ! V_8 -> V_55 . V_100 && ! V_8 -> V_55 . V_103 )
if ( ! F_65 ( & V_8 -> V_55 . V_110 . V_110 ) )
F_47 ( & V_8 -> V_55 . V_110 ,
F_48 ( 100 ) ) ;
F_49 ( & V_8 -> V_55 . V_88 ) ;
}
void F_66 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
V_8 -> V_121 = F_32 ( V_8 ) ?
V_122 : V_123 ;
if ( V_94 . V_95 == - 1 ) {
if ( F_32 ( V_5 ) || F_67 ( V_5 ) ||
F_39 ( V_5 ) || F_40 ( V_5 ) )
V_94 . V_95 = 1 ;
else
V_94 . V_95 = 0 ;
}
if ( F_32 ( V_5 ) || F_67 ( V_5 ) )
V_8 -> V_55 . V_69 = false ;
else if ( F_39 ( V_5 ) || F_40 ( V_5 ) )
V_8 -> V_55 . V_69 = true ;
else
V_8 -> V_55 . V_69 = V_8 -> V_76 . V_55 . V_124 ;
if ( V_94 . V_95 == 2 && ! V_8 -> V_55 . V_69 ) {
F_38 ( L_12 ) ;
V_8 -> V_55 . V_69 = true ;
}
if ( V_94 . V_95 == 3 && V_8 -> V_55 . V_69 ) {
F_38 ( L_13 ) ;
V_8 -> V_55 . V_69 = false ;
}
F_68 ( & V_8 -> V_55 . V_110 , F_57 ) ;
F_69 ( & V_8 -> V_55 . V_88 ) ;
}

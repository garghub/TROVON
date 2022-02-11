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
static void F_18 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_17 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
T_1 V_43 ;
T_1 V_44 , V_45 ;
int V_46 = 0x3 ;
static const T_3 V_47 [] = {
[ 0 ] = V_48 << 4 ,
[ 1 ] = V_49 >> 8 ,
[ 2 ] = V_49 & 0xff ,
[ 3 ] = 1 - 1 ,
[ 4 ] = V_50 ,
} ;
int V_26 ;
F_19 ( sizeof( V_47 ) > 20 ) ;
V_43 = V_1 -> V_51 ( V_1 , 0 ) ;
F_17 ( & V_1 -> V_39 , V_40 ,
V_41 & ~ V_42 ) ;
if ( V_8 -> V_52 . V_53 )
F_17 ( & V_1 -> V_39 ,
V_54 ,
V_55 ) ;
V_44 = ( F_20 ( V_5 ) -> V_56 >= 9 ) ?
V_57 : F_21 ( V_5 ) ;
V_45 = ( F_20 ( V_5 ) -> V_56 >= 9 ) ?
V_58 : F_22 ( V_5 ) ;
for ( V_26 = 0 ; V_26 < sizeof( V_47 ) ; V_26 += 4 )
F_10 ( V_44 + V_26 ,
F_23 ( & V_47 [ V_26 ] , sizeof( V_47 ) - V_26 ) ) ;
if ( F_20 ( V_5 ) -> V_56 >= 9 ) {
T_1 V_10 ;
V_10 = F_3 ( V_45 ) ;
V_10 &= ~ V_59 ;
V_10 |= V_60 ;
V_10 &= ~ V_61 ;
V_10 |= ( sizeof( V_47 ) << V_62 ) ;
V_10 &= ~ V_63 ;
V_10 &= ~ V_64 ;
V_10 &= ~ V_65 ;
F_10 ( V_45 , V_10 ) ;
} else {
F_10 ( V_45 ,
V_66 |
( sizeof( V_47 ) << V_62 ) |
( V_46 << V_67 ) |
( V_43 << V_68 ) ) ;
}
F_17 ( & V_1 -> V_39 , V_40 , V_41 ) ;
}
static void F_24 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_17 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_30 * V_20 = V_17 -> V_18 . V_18 . V_20 ;
enum V_6 V_6 = F_7 ( V_20 ) -> V_6 ;
F_10 ( F_25 ( V_6 ) ,
V_69 |
V_70 |
V_71 ) ;
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_17 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_30 * V_20 = V_17 -> V_18 . V_18 . V_20 ;
enum V_6 V_6 = F_7 ( V_20 ) -> V_6 ;
F_10 ( F_25 ( V_6 ) , F_3 ( F_25 ( V_6 ) ) |
V_72 ) ;
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_17 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
T_1 V_73 = 0x1f ;
T_1 V_74 = V_8 -> V_75 . V_52 . V_74 ?
V_8 -> V_75 . V_52 . V_74 + 1 : 2 ;
T_1 V_10 = 0x0 ;
const T_1 V_76 = V_77 ;
if ( V_1 -> V_2 [ 1 ] & V_78 ) {
V_10 |= V_79 ;
V_10 |= V_80 ;
V_10 |= V_81 ;
V_74 += 4 ;
}
F_10 ( F_28 ( V_5 ) , V_10 |
( F_29 ( V_5 ) ? 0 : V_76 ) |
V_73 << V_82 |
V_74 << V_83 |
V_84 ) ;
if ( V_8 -> V_52 . V_85 )
F_10 ( V_86 , V_87 |
V_88 | V_89 ) ;
}
static bool F_30 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_17 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_30 * V_20 = V_17 -> V_18 . V_18 . V_20 ;
struct V_19 * V_19 = F_7 ( V_20 ) ;
F_31 ( & V_8 -> V_52 . V_90 ) ;
F_32 ( ! F_33 ( & V_5 -> V_91 . V_92 ) ) ;
F_32 ( ! F_33 ( & V_20 -> V_93 ) ) ;
V_8 -> V_52 . V_94 = false ;
if ( F_34 ( V_5 ) && V_17 -> V_95 != V_96 ) {
F_35 ( L_1 ) ;
return false ;
}
if ( ! V_97 . V_98 ) {
F_35 ( L_2 ) ;
return false ;
}
if ( F_34 ( V_5 ) &&
F_3 ( F_36 ( V_19 -> V_22 -> V_23 ) ) &
V_99 ) {
F_35 ( L_3 ) ;
return false ;
}
if ( F_34 ( V_5 ) &&
V_19 -> V_22 -> V_18 . V_100 . V_101 & V_102 ) {
F_35 ( L_4 ) ;
return false ;
}
if ( ! F_37 ( V_5 ) && ( ( V_8 -> V_75 . V_52 . V_103 ) ||
( V_17 -> V_95 != V_96 ) ) ) {
F_35 ( L_5 ) ;
return false ;
}
V_8 -> V_52 . V_94 = true ;
return true ;
}
static void F_38 ( struct V_1 * V_1 )
{
struct V_16 * V_29 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_29 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
F_32 ( F_3 ( F_28 ( V_5 ) ) & V_84 ) ;
F_32 ( V_8 -> V_52 . V_104 ) ;
F_31 ( & V_8 -> V_52 . V_90 ) ;
if ( F_39 ( V_5 ) )
F_27 ( V_1 ) ;
else
F_26 ( V_1 ) ;
V_8 -> V_52 . V_104 = true ;
}
void F_40 ( struct V_1 * V_1 )
{
struct V_16 * V_29 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_29 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_19 * V_20 = F_7 ( V_29 -> V_18 . V_18 . V_20 ) ;
if ( ! F_41 ( V_5 ) ) {
F_35 ( L_6 ) ;
return;
}
if ( ! F_1 ( V_1 ) ) {
F_35 ( L_7 ) ;
return;
}
F_42 ( & V_8 -> V_52 . V_90 ) ;
if ( V_8 -> V_52 . V_105 ) {
F_35 ( L_8 ) ;
goto V_106;
}
if ( ! F_30 ( V_1 ) )
goto V_106;
V_8 -> V_52 . V_107 = 0 ;
if ( F_39 ( V_5 ) ) {
F_15 ( V_1 ) ;
if ( V_8 -> V_52 . V_85 ) {
if ( V_20 -> V_22 -> V_108 > 3200 ||
V_20 -> V_22 -> V_109 > 2000 )
V_8 -> V_52 . V_85 = false ;
else
F_14 ( V_1 ) ;
}
F_10 ( F_43 ( V_5 ) , V_110 |
V_111 | V_112 ) ;
F_18 ( V_1 ) ;
if ( F_20 ( V_5 ) -> V_56 >= 9 )
F_38 ( V_1 ) ;
} else {
F_12 ( V_1 ) ;
F_16 ( V_1 ) ;
F_24 ( V_1 ) ;
}
V_8 -> V_52 . V_105 = V_1 ;
V_106:
F_44 ( & V_8 -> V_52 . V_90 ) ;
}
static void F_45 ( struct V_1 * V_1 )
{
struct V_16 * V_29 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_29 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_19 * V_19 =
F_7 ( V_29 -> V_18 . V_18 . V_20 ) ;
T_1 V_10 ;
if ( V_8 -> V_52 . V_104 ) {
if ( F_46 ( ( F_3 ( F_4 ( V_19 -> V_6 ) ) &
V_113 ) == 0 , 1 ) )
F_47 ( 1 , L_9 ) ;
V_10 = F_3 ( F_25 ( V_19 -> V_6 ) ) ;
V_10 &= ~ V_72 ;
V_10 &= ~ V_71 ;
V_10 &= ~ V_114 ;
F_10 ( F_25 ( V_19 -> V_6 ) , V_10 ) ;
V_8 -> V_52 . V_104 = false ;
} else {
F_32 ( F_2 ( V_5 , V_19 -> V_6 ) ) ;
}
}
static void F_48 ( struct V_1 * V_1 )
{
struct V_16 * V_29 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_29 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
if ( V_8 -> V_52 . V_104 ) {
F_10 ( F_28 ( V_5 ) ,
F_3 ( F_28 ( V_5 ) ) & ~ V_84 ) ;
if ( F_49 ( ( F_3 ( F_50 ( V_5 ) ) &
V_115 ) == 0 , 2000 , 10 ) )
F_51 ( L_10 ) ;
V_8 -> V_52 . V_104 = false ;
} else {
F_32 ( F_3 ( F_28 ( V_5 ) ) & V_84 ) ;
}
}
void F_52 ( struct V_1 * V_1 )
{
struct V_16 * V_29 = F_6 ( V_1 ) ;
struct V_4 * V_5 = V_29 -> V_18 . V_18 . V_5 ;
struct V_7 * V_8 = V_5 -> V_9 ;
F_42 ( & V_8 -> V_52 . V_90 ) ;
if ( ! V_8 -> V_52 . V_105 ) {
F_44 ( & V_8 -> V_52 . V_90 ) ;
return;
}
if ( F_39 ( V_5 ) )
F_48 ( V_1 ) ;
else
F_45 ( V_1 ) ;
V_8 -> V_52 . V_105 = NULL ;
F_44 ( & V_8 -> V_52 . V_90 ) ;
F_53 ( & V_8 -> V_52 . V_116 ) ;
}
static void F_54 ( struct V_117 * V_116 )
{
struct V_7 * V_8 =
F_55 ( V_116 , F_56 ( * V_8 ) , V_52 . V_116 . V_116 ) ;
struct V_1 * V_1 = V_8 -> V_52 . V_105 ;
struct V_30 * V_20 = F_6 ( V_1 ) -> V_18 . V_18 . V_20 ;
enum V_6 V_6 = F_7 ( V_20 ) -> V_6 ;
if ( F_39 ( V_8 -> V_5 ) ) {
if ( F_46 ( ( F_3 ( F_50 ( V_8 -> V_5 ) ) &
V_115 ) == 0 , 50 ) ) {
F_51 ( L_11 ) ;
return;
}
} else {
if ( F_46 ( ( F_3 ( F_4 ( V_6 ) ) &
V_113 ) == 0 , 1 ) ) {
F_51 ( L_11 ) ;
return;
}
}
F_42 ( & V_8 -> V_52 . V_90 ) ;
V_1 = V_8 -> V_52 . V_105 ;
if ( ! V_1 )
goto V_106;
if ( V_8 -> V_52 . V_107 )
goto V_106;
F_38 ( V_1 ) ;
V_106:
F_44 ( & V_8 -> V_52 . V_90 ) ;
}
static void F_57 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_1 * V_1 = V_8 -> V_52 . V_105 ;
struct V_30 * V_20 = F_6 ( V_1 ) -> V_18 . V_18 . V_20 ;
enum V_6 V_6 = F_7 ( V_20 ) -> V_6 ;
T_2 V_10 ;
if ( ! V_8 -> V_52 . V_104 )
return;
if ( F_39 ( V_5 ) ) {
V_10 = F_3 ( F_28 ( V_5 ) ) ;
F_32 ( ! ( V_10 & V_84 ) ) ;
F_10 ( F_28 ( V_5 ) , V_10 & ~ V_84 ) ;
} else {
V_10 = F_3 ( F_25 ( V_6 ) ) ;
V_10 &= ~ V_72 ;
F_10 ( F_25 ( V_6 ) , V_10 ) ;
F_17 ( & V_1 -> V_39 , V_49 ,
V_50 ) ;
}
V_8 -> V_52 . V_104 = false ;
}
void F_58 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_30 * V_20 ;
enum V_6 V_6 ;
T_2 V_10 ;
if ( ! F_37 ( V_5 ) )
return;
F_42 ( & V_8 -> V_52 . V_90 ) ;
if ( ! V_8 -> V_52 . V_105 ) {
F_44 ( & V_8 -> V_52 . V_90 ) ;
return;
}
V_20 = F_6 ( V_8 -> V_52 . V_105 ) -> V_18 . V_18 . V_20 ;
V_6 = F_7 ( V_20 ) -> V_6 ;
V_10 = F_3 ( F_25 ( V_6 ) ) ;
F_10 ( F_25 ( V_6 ) , V_10 | V_118 ) ;
F_44 ( & V_8 -> V_52 . V_90 ) ;
}
void F_59 ( struct V_4 * V_5 ,
unsigned V_119 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_30 * V_20 ;
enum V_6 V_6 ;
F_42 ( & V_8 -> V_52 . V_90 ) ;
if ( ! V_8 -> V_52 . V_105 ) {
F_44 ( & V_8 -> V_52 . V_90 ) ;
return;
}
V_20 = F_6 ( V_8 -> V_52 . V_105 ) -> V_18 . V_18 . V_20 ;
V_6 = F_7 ( V_20 ) -> V_6 ;
F_57 ( V_5 ) ;
V_119 &= F_60 ( V_6 ) ;
V_8 -> V_52 . V_107 |= V_119 ;
F_44 ( & V_8 -> V_52 . V_90 ) ;
}
void F_61 ( struct V_4 * V_5 ,
unsigned V_119 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_30 * V_20 ;
enum V_6 V_6 ;
F_42 ( & V_8 -> V_52 . V_90 ) ;
if ( ! V_8 -> V_52 . V_105 ) {
F_44 ( & V_8 -> V_52 . V_90 ) ;
return;
}
V_20 = F_6 ( V_8 -> V_52 . V_105 ) -> V_18 . V_18 . V_20 ;
V_6 = F_7 ( V_20 ) -> V_6 ;
V_8 -> V_52 . V_107 &= ~ V_119 ;
if ( F_34 ( V_5 ) &&
( V_119 & F_62 ( V_6 ) ) )
F_57 ( V_5 ) ;
if ( ! F_39 ( V_5 ) )
F_57 ( V_5 ) ;
if ( ! V_8 -> V_52 . V_104 && ! V_8 -> V_52 . V_107 )
F_63 ( & V_8 -> V_52 . V_116 ,
F_64 ( 100 ) ) ;
F_44 ( & V_8 -> V_52 . V_90 ) ;
}
void F_65 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
F_66 ( & V_8 -> V_52 . V_116 , F_54 ) ;
F_67 ( & V_8 -> V_52 . V_90 ) ;
}

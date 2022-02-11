static bool F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 [ 0 ] & V_3 ;
}
static bool F_2 ( struct V_4 * V_5 , int V_6 )
{
struct V_7 * V_8 = F_3 ( V_5 ) ;
T_1 V_9 ;
V_9 = F_4 ( F_5 ( V_6 ) ) &
V_10 ;
return ( V_9 == V_11 ) ||
( V_9 == V_12 ) ;
}
static void F_6 ( struct V_1 * V_1 ,
const struct V_13 * V_14 )
{
struct V_15 * V_16 = F_7 ( V_1 ) ;
struct V_4 * V_5 = V_16 -> V_17 . V_17 . V_5 ;
struct V_7 * V_8 = F_3 ( V_5 ) ;
struct V_18 * V_19 = F_8 ( V_16 -> V_17 . V_17 . V_19 ) ;
enum V_20 V_21 = V_19 -> V_22 -> V_21 ;
T_2 V_23 = F_9 ( V_21 ) ;
T_1 * V_24 = ( T_1 * ) V_14 ;
unsigned int V_25 ;
F_10 ( V_23 , 0 ) ;
F_11 ( V_23 ) ;
for ( V_25 = 0 ; V_25 < sizeof( * V_14 ) ; V_25 += 4 ) {
F_10 ( F_12 ( V_21 ,
V_25 >> 2 ) , * V_24 ) ;
V_24 ++ ;
}
for (; V_25 < V_26 ; V_25 += 4 )
F_10 ( F_12 ( V_21 ,
V_25 >> 2 ) , 0 ) ;
F_10 ( V_23 , V_27 ) ;
F_11 ( V_23 ) ;
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_15 * V_28 = F_7 ( V_1 ) ;
struct V_4 * V_5 = V_28 -> V_17 . V_17 . V_5 ;
struct V_7 * V_8 = F_3 ( V_5 ) ;
struct V_29 * V_19 = V_28 -> V_17 . V_17 . V_19 ;
enum V_6 V_6 = F_8 ( V_19 ) -> V_6 ;
T_1 V_9 ;
V_9 = F_4 ( F_14 ( V_6 ) ) ;
V_9 &= ~ V_30 ;
V_9 |= V_31 ;
F_10 ( F_14 ( V_6 ) , V_9 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_13 V_32 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_33 . V_34 = 0 ;
V_32 . V_33 . V_35 = 0x7 ;
V_32 . V_33 . V_36 = 0x3 ;
V_32 . V_33 . V_37 = 0xb ;
F_6 ( V_1 , & V_32 ) ;
}
static void F_16 ( struct V_1 * V_1 )
{
struct V_13 V_32 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_33 . V_34 = 0 ;
V_32 . V_33 . V_35 = 0x7 ;
V_32 . V_33 . V_36 = 0x2 ;
V_32 . V_33 . V_37 = 0x8 ;
F_6 ( V_1 , & V_32 ) ;
}
static void F_17 ( struct V_1 * V_1 )
{
F_18 ( & V_1 -> V_38 , V_39 ,
V_40 | V_41 ) ;
}
static T_2 F_19 ( struct V_7 * V_8 ,
enum V_42 V_42 )
{
if ( F_20 ( V_8 ) -> V_43 >= 9 )
return F_21 ( V_42 ) ;
else
return V_44 ;
}
static T_2 F_22 ( struct V_7 * V_8 ,
enum V_42 V_42 , int V_45 )
{
if ( F_20 ( V_8 ) -> V_43 >= 9 )
return F_23 ( V_42 , V_45 ) ;
else
return F_24 ( V_45 ) ;
}
static void F_25 ( struct V_1 * V_1 )
{
struct V_15 * V_16 = F_7 ( V_1 ) ;
struct V_4 * V_5 = V_16 -> V_17 . V_17 . V_5 ;
struct V_7 * V_8 = F_3 ( V_5 ) ;
T_1 V_46 ;
T_2 V_47 ;
static const T_3 V_48 [] = {
[ 0 ] = V_49 << 4 ,
[ 1 ] = V_50 >> 8 ,
[ 2 ] = V_50 & 0xff ,
[ 3 ] = 1 - 1 ,
[ 4 ] = V_51 ,
} ;
enum V_42 V_42 = V_16 -> V_42 ;
T_4 V_52 ;
int V_25 ;
F_26 ( sizeof( V_48 ) > 20 ) ;
V_46 = V_1 -> V_53 ( V_1 , 0 ) ;
if ( V_8 -> V_54 . V_55 )
F_18 ( & V_1 -> V_38 ,
V_56 ,
V_57 ) ;
if ( V_8 -> V_54 . V_58 )
F_18 ( & V_1 -> V_38 , V_39 ,
V_40 | V_41 ) ;
else
F_18 ( & V_1 -> V_38 , V_39 ,
V_40 ) ;
V_47 = F_19 ( V_8 , V_42 ) ;
for ( V_25 = 0 ; V_25 < sizeof( V_48 ) ; V_25 += 4 )
F_10 ( F_22 ( V_8 , V_42 , V_25 >> 2 ) ,
F_27 ( & V_48 [ V_25 ] , sizeof( V_48 ) - V_25 ) ) ;
V_52 = V_1 -> V_59 ( V_1 , 0 , sizeof( V_48 ) ,
V_46 ) ;
F_10 ( V_47 , V_52 ) ;
}
static void F_28 ( struct V_1 * V_1 )
{
struct V_15 * V_16 = F_7 ( V_1 ) ;
struct V_4 * V_5 = V_16 -> V_17 . V_17 . V_5 ;
struct V_7 * V_8 = F_3 ( V_5 ) ;
struct V_29 * V_19 = V_16 -> V_17 . V_17 . V_19 ;
enum V_6 V_6 = F_8 ( V_19 ) -> V_6 ;
F_10 ( F_29 ( V_6 ) ,
V_60 |
V_61 |
V_62 ) ;
}
static void F_30 ( struct V_1 * V_1 )
{
struct V_15 * V_16 = F_7 ( V_1 ) ;
struct V_4 * V_5 = V_16 -> V_17 . V_17 . V_5 ;
struct V_7 * V_8 = F_3 ( V_5 ) ;
struct V_29 * V_19 = V_16 -> V_17 . V_17 . V_19 ;
enum V_6 V_6 = F_8 ( V_19 ) -> V_6 ;
F_10 ( F_29 ( V_6 ) , F_4 ( F_29 ( V_6 ) ) |
V_63 ) ;
}
static void F_31 ( struct V_1 * V_1 )
{
struct V_15 * V_16 = F_7 ( V_1 ) ;
struct V_4 * V_5 = V_16 -> V_17 . V_17 . V_5 ;
struct V_7 * V_8 = F_3 ( V_5 ) ;
T_1 V_64 = 0x1f ;
T_1 V_65 = F_32 ( 6 , V_8 -> V_66 . V_54 . V_65 ) ;
T_1 V_9 = V_67 ;
V_9 |= V_64 << V_68 ;
V_9 |= V_65 << V_69 ;
if ( F_33 ( V_5 ) )
V_9 |= V_70 ;
if ( V_8 -> V_54 . V_58 )
V_9 |= V_71 ;
if ( V_8 -> V_66 . V_54 . V_72 > 5 )
V_9 |= V_73 ;
else if ( V_8 -> V_66 . V_54 . V_72 > 1 )
V_9 |= V_74 ;
else if ( V_8 -> V_66 . V_54 . V_72 > 0 )
V_9 |= V_75 ;
else
V_9 |= V_76 ;
if ( V_8 -> V_66 . V_54 . V_77 > 5 )
V_9 |= V_78 ;
else if ( V_8 -> V_66 . V_54 . V_77 > 1 )
V_9 |= V_79 ;
else if ( V_8 -> V_66 . V_54 . V_77 > 0 )
V_9 |= V_80 ;
else
V_9 |= V_81 ;
if ( F_34 ( V_1 ) &&
F_35 ( V_1 -> V_82 ) )
V_9 |= V_83 ;
else
V_9 |= V_84 ;
F_10 ( V_85 , V_9 ) ;
if ( ! V_8 -> V_54 . V_86 )
return;
V_9 = V_87 | V_88 ;
if ( V_8 -> V_66 . V_54 . V_77 > 5 )
V_9 |= V_89 ;
else if ( V_8 -> V_66 . V_54 . V_77 > 1 )
V_9 |= V_90 ;
else if ( V_8 -> V_66 . V_54 . V_77 > 0 )
V_9 |= V_91 ;
else
V_9 |= V_92 ;
F_10 ( V_93 , V_9 ) ;
}
static bool F_36 ( struct V_1 * V_1 )
{
struct V_15 * V_16 = F_7 ( V_1 ) ;
struct V_4 * V_5 = V_16 -> V_17 . V_17 . V_5 ;
struct V_7 * V_8 = F_3 ( V_5 ) ;
struct V_29 * V_19 = V_16 -> V_17 . V_17 . V_19 ;
struct V_18 * V_18 = F_8 ( V_19 ) ;
const struct V_94 * V_95 =
& V_18 -> V_22 -> V_17 . V_95 ;
int V_96 ;
F_37 ( & V_8 -> V_54 . V_97 ) ;
F_38 ( ! F_39 ( & V_5 -> V_98 . V_99 ) ) ;
F_38 ( ! F_39 ( & V_19 -> V_100 ) ) ;
V_8 -> V_54 . V_101 = false ;
if ( F_40 ( V_5 ) && V_16 -> V_42 != V_102 ) {
F_41 ( L_1 ) ;
return false ;
}
if ( ! V_103 . V_104 ) {
F_41 ( L_2 ) ;
return false ;
}
if ( ( F_42 ( V_5 ) || F_43 ( V_5 ) ) &&
! V_8 -> V_54 . V_58 ) {
F_44 ( L_3 ) ;
return false ;
}
if ( F_33 ( V_5 ) &&
F_4 ( F_45 ( V_18 -> V_22 -> V_21 ) ) &
V_105 ) {
F_41 ( L_4 ) ;
return false ;
}
if ( F_33 ( V_5 ) &&
V_95 -> V_106 & V_107 ) {
F_41 ( L_5 ) ;
return false ;
}
V_96 = F_46 ( V_1 -> V_2 ) ;
if ( V_96 < 0 ) {
F_41 ( L_6 ,
V_1 -> V_2 [ 1 ] ) ;
return false ;
}
if ( F_47 ( V_95 , V_96 ) >
V_95 -> V_108 - V_95 -> V_109 - 1 ) {
F_41 ( L_7 ,
V_96 ) ;
return false ;
}
V_8 -> V_54 . V_101 = true ;
return true ;
}
static void F_48 ( struct V_1 * V_1 )
{
struct V_15 * V_28 = F_7 ( V_1 ) ;
struct V_4 * V_5 = V_28 -> V_17 . V_17 . V_5 ;
struct V_7 * V_8 = F_3 ( V_5 ) ;
F_38 ( F_4 ( V_85 ) & V_67 ) ;
F_38 ( V_8 -> V_54 . V_110 ) ;
F_37 ( & V_8 -> V_54 . V_97 ) ;
if ( F_40 ( V_5 ) )
F_31 ( V_1 ) ;
else
F_30 ( V_1 ) ;
V_8 -> V_54 . V_110 = true ;
}
void F_49 ( struct V_1 * V_1 )
{
struct V_15 * V_28 = F_7 ( V_1 ) ;
struct V_4 * V_5 = V_28 -> V_17 . V_17 . V_5 ;
struct V_7 * V_8 = F_3 ( V_5 ) ;
struct V_18 * V_19 = F_8 ( V_28 -> V_17 . V_17 . V_19 ) ;
if ( ! F_50 ( V_5 ) ) {
F_41 ( L_8 ) ;
return;
}
if ( ! F_1 ( V_1 ) ) {
F_41 ( L_9 ) ;
return;
}
F_51 ( & V_8 -> V_54 . V_97 ) ;
if ( V_8 -> V_54 . V_111 ) {
F_41 ( L_10 ) ;
goto V_112;
}
if ( ! F_36 ( V_1 ) )
goto V_112;
V_8 -> V_54 . V_113 = 0 ;
if ( F_40 ( V_5 ) ) {
F_16 ( V_1 ) ;
if ( V_8 -> V_54 . V_86 ) {
if ( V_19 -> V_22 -> V_114 > 3200 ||
V_19 -> V_22 -> V_115 > 2000 )
V_8 -> V_54 . V_86 = false ;
else
F_15 ( V_1 ) ;
}
F_10 ( V_116 , V_117 |
V_118 | V_119 ) ;
F_25 ( V_1 ) ;
if ( F_20 ( V_5 ) -> V_43 >= 9 )
F_48 ( V_1 ) ;
} else {
F_13 ( V_1 ) ;
F_17 ( V_1 ) ;
F_28 ( V_1 ) ;
}
if ( F_20 ( V_5 ) -> V_43 < 9 )
F_52 ( & V_8 -> V_54 . V_120 ,
F_53 ( V_1 -> V_121 * 5 ) ) ;
V_8 -> V_54 . V_111 = V_1 ;
V_112:
F_54 ( & V_8 -> V_54 . V_97 ) ;
}
static void F_55 ( struct V_1 * V_1 )
{
struct V_15 * V_28 = F_7 ( V_1 ) ;
struct V_4 * V_5 = V_28 -> V_17 . V_17 . V_5 ;
struct V_7 * V_8 = F_3 ( V_5 ) ;
struct V_18 * V_18 =
F_8 ( V_28 -> V_17 . V_17 . V_19 ) ;
T_1 V_9 ;
if ( V_8 -> V_54 . V_110 ) {
if ( F_56 ( V_8 ,
F_5 ( V_18 -> V_6 ) ,
V_122 ,
0 ,
1 ) )
F_57 ( 1 , L_11 ) ;
V_9 = F_4 ( F_29 ( V_18 -> V_6 ) ) ;
V_9 &= ~ V_63 ;
V_9 &= ~ V_62 ;
V_9 &= ~ V_123 ;
F_10 ( F_29 ( V_18 -> V_6 ) , V_9 ) ;
V_8 -> V_54 . V_110 = false ;
} else {
F_38 ( F_2 ( V_5 , V_18 -> V_6 ) ) ;
}
}
static void F_58 ( struct V_1 * V_1 )
{
struct V_15 * V_28 = F_7 ( V_1 ) ;
struct V_4 * V_5 = V_28 -> V_17 . V_17 . V_5 ;
struct V_7 * V_8 = F_3 ( V_5 ) ;
if ( V_8 -> V_54 . V_110 ) {
F_10 ( V_85 ,
F_4 ( V_85 ) & ~ V_67 ) ;
if ( F_56 ( V_8 ,
V_124 ,
V_125 ,
0 ,
2000 ) )
F_44 ( L_12 ) ;
V_8 -> V_54 . V_110 = false ;
} else {
F_38 ( F_4 ( V_85 ) & V_67 ) ;
}
}
void F_59 ( struct V_1 * V_1 )
{
struct V_15 * V_28 = F_7 ( V_1 ) ;
struct V_4 * V_5 = V_28 -> V_17 . V_17 . V_5 ;
struct V_7 * V_8 = F_3 ( V_5 ) ;
F_51 ( & V_8 -> V_54 . V_97 ) ;
if ( ! V_8 -> V_54 . V_111 ) {
F_54 ( & V_8 -> V_54 . V_97 ) ;
return;
}
if ( F_40 ( V_5 ) )
F_58 ( V_1 ) ;
else
F_55 ( V_1 ) ;
F_18 ( & V_1 -> V_38 , V_39 , 0 ) ;
V_8 -> V_54 . V_111 = NULL ;
F_54 ( & V_8 -> V_54 . V_97 ) ;
F_60 ( & V_8 -> V_54 . V_120 ) ;
}
static void F_61 ( struct V_126 * V_120 )
{
struct V_7 * V_8 =
F_62 ( V_120 , F_63 ( * V_8 ) , V_54 . V_120 . V_120 ) ;
struct V_1 * V_1 = V_8 -> V_54 . V_111 ;
struct V_29 * V_19 = F_7 ( V_1 ) -> V_17 . V_17 . V_19 ;
enum V_6 V_6 = F_8 ( V_19 ) -> V_6 ;
if ( F_40 ( V_8 ) ) {
if ( F_56 ( V_8 ,
V_124 ,
V_125 ,
0 ,
50 ) ) {
F_44 ( L_13 ) ;
return;
}
} else {
if ( F_56 ( V_8 ,
F_5 ( V_6 ) ,
V_122 ,
0 ,
1 ) ) {
F_44 ( L_13 ) ;
return;
}
}
F_51 ( & V_8 -> V_54 . V_97 ) ;
V_1 = V_8 -> V_54 . V_111 ;
if ( ! V_1 )
goto V_112;
if ( V_8 -> V_54 . V_113 )
goto V_112;
F_48 ( V_1 ) ;
V_112:
F_54 ( & V_8 -> V_54 . V_97 ) ;
}
static void F_64 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = V_8 -> V_54 . V_111 ;
struct V_29 * V_19 = F_7 ( V_1 ) -> V_17 . V_17 . V_19 ;
enum V_6 V_6 = F_8 ( V_19 ) -> V_6 ;
T_4 V_9 ;
if ( ! V_8 -> V_54 . V_110 )
return;
if ( F_40 ( V_8 ) ) {
V_9 = F_4 ( V_85 ) ;
F_38 ( ! ( V_9 & V_67 ) ) ;
F_10 ( V_85 , V_9 & ~ V_67 ) ;
} else {
V_9 = F_4 ( F_29 ( V_6 ) ) ;
V_9 &= ~ V_63 ;
F_10 ( F_29 ( V_6 ) , V_9 ) ;
F_18 ( & V_1 -> V_38 , V_50 ,
V_51 ) ;
}
V_8 -> V_54 . V_110 = false ;
}
void F_65 ( struct V_7 * V_8 ,
unsigned V_127 )
{
struct V_29 * V_19 ;
enum V_6 V_6 ;
T_4 V_9 ;
if ( ! F_42 ( V_8 ) && ! F_43 ( V_8 ) )
return;
F_51 ( & V_8 -> V_54 . V_97 ) ;
if ( ! V_8 -> V_54 . V_111 ) {
F_54 ( & V_8 -> V_54 . V_97 ) ;
return;
}
V_19 = F_7 ( V_8 -> V_54 . V_111 ) -> V_17 . V_17 . V_19 ;
V_6 = F_8 ( V_19 ) -> V_6 ;
if ( V_127 & F_66 ( V_6 ) ) {
V_9 = F_4 ( F_29 ( V_6 ) ) ;
F_10 ( F_29 ( V_6 ) , V_9 | V_128 ) ;
}
F_54 ( & V_8 -> V_54 . V_97 ) ;
}
void F_67 ( struct V_7 * V_8 ,
unsigned V_127 )
{
struct V_29 * V_19 ;
enum V_6 V_6 ;
F_51 ( & V_8 -> V_54 . V_97 ) ;
if ( ! V_8 -> V_54 . V_111 ) {
F_54 ( & V_8 -> V_54 . V_97 ) ;
return;
}
V_19 = F_7 ( V_8 -> V_54 . V_111 ) -> V_17 . V_17 . V_19 ;
V_6 = F_8 ( V_19 ) -> V_6 ;
V_127 &= F_66 ( V_6 ) ;
V_8 -> V_54 . V_113 |= V_127 ;
if ( V_127 )
F_64 ( V_8 ) ;
F_54 ( & V_8 -> V_54 . V_97 ) ;
}
void F_68 ( struct V_7 * V_8 ,
unsigned V_127 , enum V_129 V_130 )
{
struct V_29 * V_19 ;
enum V_6 V_6 ;
F_51 ( & V_8 -> V_54 . V_97 ) ;
if ( ! V_8 -> V_54 . V_111 ) {
F_54 ( & V_8 -> V_54 . V_97 ) ;
return;
}
V_19 = F_7 ( V_8 -> V_54 . V_111 ) -> V_17 . V_17 . V_19 ;
V_6 = F_8 ( V_19 ) -> V_6 ;
V_127 &= F_66 ( V_6 ) ;
V_8 -> V_54 . V_113 &= ~ V_127 ;
if ( V_127 )
F_64 ( V_8 ) ;
if ( ! V_8 -> V_54 . V_110 && ! V_8 -> V_54 . V_113 )
if ( ! F_69 ( & V_8 -> V_54 . V_120 . V_120 ) )
F_52 ( & V_8 -> V_54 . V_120 ,
F_53 ( 100 ) ) ;
F_54 ( & V_8 -> V_54 . V_97 ) ;
}
void F_70 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_3 ( V_5 ) ;
V_8 -> V_131 = F_33 ( V_8 ) ?
V_132 : V_133 ;
if ( V_103 . V_104 == - 1 ) {
if ( F_33 ( V_5 ) || F_71 ( V_5 ) )
V_103 . V_104 = 1 ;
else
V_103 . V_104 = 0 ;
}
if ( F_33 ( V_5 ) || F_71 ( V_5 ) )
V_8 -> V_54 . V_58 = false ;
else if ( F_42 ( V_5 ) || F_43 ( V_5 ) )
V_8 -> V_54 . V_58 = true ;
else
V_8 -> V_54 . V_58 = V_8 -> V_66 . V_54 . V_134 ;
if ( V_103 . V_104 == 2 && ! V_8 -> V_54 . V_58 ) {
F_41 ( L_14 ) ;
V_8 -> V_54 . V_58 = true ;
}
if ( V_103 . V_104 == 3 && V_8 -> V_54 . V_58 ) {
F_41 ( L_15 ) ;
V_8 -> V_54 . V_58 = false ;
}
F_72 ( & V_8 -> V_54 . V_120 , F_61 ) ;
F_73 ( & V_8 -> V_54 . V_97 ) ;
}

static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_2 -> V_3 . V_4 ) ;
}
static struct V_5 * F_3 (
struct V_1 * V_2 ,
T_1 V_6 )
{
int V_7 ;
T_2 V_8 = F_4 ( V_6 ) ;
T_2 V_9 = F_5 ( V_6 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_3 . V_10 ; V_7 ++ ) {
T_2 V_11 = V_8 ;
if ( ! V_2 -> V_3 . V_12 [ V_7 ] . V_13 )
continue;
if ( V_2 -> V_3 . V_12 [ V_7 ] . V_14 )
V_11 = V_9 ;
if ( V_2 -> V_3 . V_12 [ V_7 ] . V_8 == V_11 )
return & V_2 -> V_3 . V_12 [ V_7 ] ;
}
F_6 ( L_1 ,
V_6 , V_8 , V_9 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_3 . V_10 ; V_7 ++ ) {
if ( V_2 -> V_3 . V_12 [ V_7 ] . V_15 )
F_6 ( L_2 , V_7 ,
V_2 -> V_3 . V_12 [ V_7 ] . V_13 ? 'v' : ' ' ,
V_2 -> V_3 . V_12 [ V_7 ] . V_16 ? 'l' : ' ' ,
V_2 -> V_3 . V_12 [ V_7 ] . V_14 ? 't' : ' ' ,
V_2 -> V_3 . V_12 [ V_7 ] . V_8 ,
V_2 -> V_3 . V_12 [ V_7 ] . V_15 ) ;
}
return NULL ;
}
static int F_7 ( struct V_5 * V_17 )
{
return V_17 -> V_14 ? V_18 : V_19 ;
}
static T_2 F_8 ( struct V_5 * V_17 )
{
return ( 1ul << F_7 ( V_17 ) ) - 1 ;
}
static T_2 F_9 ( struct V_5 * V_12 , T_1 V_6 )
{
V_6 &= F_8 ( V_12 ) ;
return ( V_6 >> V_20 ) |
( ( V_12 -> V_15 ) << ( F_7 ( V_12 ) - V_20 ) ) ;
}
static T_2 F_10 ( struct V_1 * V_2 , T_1 V_6 ,
bool V_21 )
{
struct V_5 * V_12 ;
V_12 = F_3 ( V_2 , V_6 ) ;
if ( ! V_12 )
return 0 ;
return F_9 ( V_12 , V_6 ) ;
}
static int F_11 ( int V_22 )
{
switch ( V_22 ) {
case V_23 :
return 16 ;
case V_24 :
return 24 ;
}
return 12 ;
}
static int F_12 ( struct V_5 * V_17 )
{
return F_11 ( V_17 -> V_25 ) ;
}
static T_3 F_13 ( struct V_5 * V_17 , T_1 V_6 )
{
int V_26 = F_12 ( V_17 ) ;
return ( ( V_6 & F_8 ( V_17 ) ) >> V_26 ) ;
}
static T_4 F_14 ( struct V_1 * V_2 ,
struct V_5 * V_17 , T_1 V_6 ,
bool V_27 )
{
struct V_28 * V_29 = F_15 ( V_2 ) ;
T_2 V_30 , V_31 , V_32 ;
T_3 V_33 ;
T_4 V_34 ;
T_2 V_35 ;
V_32 = ( ( 1 << ( ( V_29 -> V_36 & 0x1f ) + 11 ) ) - 1 ) ;
V_35 = F_9 ( V_17 , V_6 ) ;
V_33 = V_17 -> V_14 ? V_37 : V_38 ;
V_30 = F_16 ( V_35 , F_12 ( V_17 ) , V_33 ) ;
if ( V_27 )
V_30 = ~ V_30 ;
V_30 &= ( ( 1ULL << 39ULL ) - 1ULL ) ;
V_30 &= V_32 ;
V_30 <<= 7ULL ;
V_31 = V_29 -> V_36 & 0xfffffffffffc0000ULL ;
V_31 |= V_30 ;
F_6 ( L_3 ,
V_39 , V_29 -> V_36 , V_31 , V_17 -> V_15 ) ;
if ( V_2 -> V_3 . V_40 )
V_34 = V_31 ;
else
V_34 = F_17 ( V_2 -> V_41 , V_31 >> V_42 ) ;
if ( F_18 ( V_34 ) )
return V_34 ;
return V_34 | ( V_31 & ~ V_43 ) ;
}
static T_2 F_19 ( struct V_5 * V_17 , T_1 V_6 )
{
int V_26 = F_12 ( V_17 ) ;
T_2 V_44 ;
V_44 = F_13 ( V_17 , V_6 ) ;
V_44 |= V_17 -> V_15 << ( F_7 ( V_17 ) - V_26 ) ;
if ( V_26 < 16 )
V_44 >>= ( ( 80 - V_26 ) - 56 ) - 8 ;
else
V_44 <<= V_26 - 16 ;
return V_44 ;
}
static int F_20 ( struct V_5 * V_17 , T_2 V_34 )
{
switch ( V_17 -> V_25 ) {
case V_23 :
if ( ( V_34 & 0xf000 ) == 0x1000 )
return V_23 ;
break;
case V_24 :
if ( ( V_34 & 0xff000 ) == 0 )
return V_24 ;
break;
}
return - 1 ;
}
static int F_21 ( struct V_1 * V_2 , T_1 V_6 ,
struct V_45 * V_46 , bool V_21 ,
bool V_47 )
{
struct V_5 * V_17 ;
T_4 V_48 ;
T_2 V_31 [ 16 ] ;
T_2 V_44 = 0 ;
T_2 V_49 , V_34 ;
T_2 V_50 , V_51 ;
T_2 V_52 ;
int V_7 ;
T_5 V_53 , V_54 = 0 ;
bool V_55 = false ;
bool V_27 = false ;
int V_56 ;
T_6 V_57 = V_2 -> V_3 . V_58 ;
if ( F_22 ( V_57 ) &&
F_22 ( ( V_6 & ~ 0xfffULL ) == ( V_57 & ~ 0xfffULL ) ) &&
! ( F_23 ( V_2 ) & V_59 ) ) {
V_46 -> V_6 = V_6 ;
V_46 -> V_60 = F_10 ( V_2 , V_6 , V_21 ) ;
V_46 -> V_61 = V_2 -> V_3 . V_62 | ( V_46 -> V_61 & 0xfff ) ;
V_46 -> V_61 &= V_63 ;
V_46 -> V_64 = true ;
V_46 -> V_65 = true ;
V_46 -> V_66 = true ;
V_46 -> V_67 = V_68 ;
return 0 ;
}
V_17 = F_3 ( V_2 , V_6 ) ;
if ( ! V_17 )
goto V_69;
V_44 = F_19 ( V_17 , V_6 ) ;
V_50 = V_44 & V_70 ;
if ( V_17 -> V_14 )
V_50 |= V_71 ;
if ( V_17 -> V_16 )
V_50 |= V_72 ;
V_50 |= V_73 ;
V_51 = V_74 | V_70 | V_72 | V_73 |
V_75 ;
V_56 = V_17 -> V_16 ? V_24 : V_68 ;
F_24 ( & V_2 -> V_41 -> V_3 . V_76 ) ;
V_77:
V_48 = F_14 ( V_2 , V_17 , V_6 , V_27 ) ;
if ( F_18 ( V_48 ) )
goto V_78;
if( F_25 ( V_31 , ( void V_79 * ) V_48 , sizeof( V_31 ) ) ) {
F_26 ( V_80 L_4 , V_48 ) ;
goto V_78;
}
if ( ( F_23 ( V_2 ) & V_59 ) && V_17 -> V_81 )
V_54 = 4 ;
else if ( ! ( F_23 ( V_2 ) & V_59 ) && V_17 -> V_82 )
V_54 = 4 ;
for ( V_7 = 0 ; V_7 < 16 ; V_7 += 2 ) {
T_2 V_83 = F_27 ( V_31 [ V_7 ] ) ;
T_2 V_84 = F_27 ( V_31 [ V_7 + 1 ] ) ;
if ( ( V_83 & V_51 ) == V_50 ) {
if ( V_17 -> V_16 &&
( V_2 -> V_3 . V_85 & V_86 ) ) {
V_56 = F_20 ( V_17 , V_84 ) ;
if ( V_56 < 0 )
continue;
}
V_55 = true ;
break;
}
}
if ( ! V_55 ) {
if ( V_27 )
goto V_78;
V_50 |= V_75 ;
V_27 = true ;
goto V_77;
}
V_49 = F_27 ( V_31 [ V_7 ] ) ;
V_34 = F_27 ( V_31 [ V_7 + 1 ] ) ;
V_53 = ( V_34 & V_87 ) | V_54 ;
if ( V_34 & V_88 )
V_53 |= 8 ;
V_46 -> V_6 = V_6 ;
V_46 -> V_60 = F_10 ( V_2 , V_6 , V_21 ) ;
V_52 = ( 1ull << F_11 ( V_56 ) ) - 1 ;
V_46 -> V_61 = ( V_34 & V_89 & ~ V_52 ) | ( V_6 & V_52 ) ;
V_46 -> V_67 = V_56 ;
V_46 -> V_64 = ( ( V_34 & V_90 ) ? false : true ) ;
if ( F_22 ( V_2 -> V_3 . V_91 ) &&
! ( F_23 ( V_2 ) & V_59 ) )
V_46 -> V_64 = true ;
V_46 -> V_65 = false ;
V_46 -> V_66 = false ;
switch ( V_53 ) {
case 0 :
case 1 :
case 2 :
case 6 :
V_46 -> V_66 = true ;
case 3 :
case 5 :
case 7 :
case 10 :
V_46 -> V_65 = true ;
break;
}
F_6 ( L_5
L_6 ,
V_6 , V_44 , V_46 -> V_60 , V_46 -> V_61 ) ;
if ( V_46 -> V_65 && ! ( V_34 & V_92 ) ) {
char V_79 * V_93 = ( char V_79 * ) ( V_48 + ( V_7 + 1 ) * sizeof( T_2 ) ) ;
V_34 |= V_92 ;
F_28 ( V_34 >> 8 , V_93 + 6 ) ;
}
if ( V_47 && V_46 -> V_66 && ! ( V_34 & V_94 ) ) {
char V_79 * V_93 = ( char V_79 * ) ( V_48 + ( V_7 + 1 ) * sizeof( T_2 ) ) ;
V_34 |= V_94 ;
F_28 ( V_34 , V_93 + 7 ) ;
}
F_29 ( & V_2 -> V_41 -> V_3 . V_76 ) ;
if ( ! V_46 -> V_65 || ( V_47 && ! V_46 -> V_66 ) )
return - V_95 ;
return 0 ;
V_78:
F_29 ( & V_2 -> V_41 -> V_3 . V_76 ) ;
return - V_96 ;
V_69:
F_6 ( L_7 ) ;
return - V_97 ;
}
static void F_30 ( struct V_1 * V_2 , T_2 V_98 , T_2 V_99 )
{
struct V_28 * V_29 ;
T_2 V_8 , V_9 ;
int V_10 ;
struct V_5 * V_17 ;
F_6 ( L_8 , V_98 , V_99 ) ;
V_29 = F_15 ( V_2 ) ;
V_8 = F_4 ( V_99 ) ;
V_9 = F_5 ( V_99 ) ;
V_10 = V_99 & 0xfff ;
if ( V_10 > V_2 -> V_3 . V_10 )
return;
V_17 = & V_2 -> V_3 . V_12 [ V_10 ] ;
V_17 -> V_16 = ( V_98 & V_100 ) ? 1 : 0 ;
V_17 -> V_14 = ( V_98 & V_71 ) ? 1 : 0 ;
V_17 -> V_8 = V_17 -> V_14 ? V_9 : V_8 ;
V_17 -> V_15 = ( V_98 & ~ V_74 ) >> ( F_7 ( V_17 ) - 16 ) ;
V_17 -> V_13 = ( V_99 & V_101 ) ? 1 : 0 ;
V_17 -> V_82 = ( V_98 & V_102 ) ? 1 : 0 ;
V_17 -> V_81 = ( V_98 & V_103 ) ? 1 : 0 ;
V_17 -> V_104 = ( V_98 & V_105 ) ? 1 : 0 ;
V_17 -> V_106 = ( V_98 & V_107 ) ? 1 : 0 ;
V_17 -> V_25 = V_68 ;
if ( V_17 -> V_16 ) {
if ( V_2 -> V_3 . V_85 & V_86 ) {
switch ( V_98 & V_108 ) {
case V_109 :
V_17 -> V_25 = V_24 ;
break;
case V_110 :
V_17 -> V_25 = V_23 ;
break;
}
} else
V_17 -> V_25 = V_24 ;
}
V_17 -> V_111 = V_99 & ( V_112 | V_101 ) ;
V_17 -> V_113 = V_98 ;
F_31 ( V_2 , V_8 << V_19 ) ;
}
static T_2 F_32 ( struct V_1 * V_2 , T_2 V_10 )
{
struct V_5 * V_17 ;
if ( V_10 > V_2 -> V_3 . V_10 )
return 0 ;
V_17 = & V_2 -> V_3 . V_12 [ V_10 ] ;
return V_17 -> V_111 ;
}
static T_2 F_33 ( struct V_1 * V_2 , T_2 V_10 )
{
struct V_5 * V_17 ;
if ( V_10 > V_2 -> V_3 . V_10 )
return 0 ;
V_17 = & V_2 -> V_3 . V_12 [ V_10 ] ;
return V_17 -> V_113 ;
}
static void F_34 ( struct V_1 * V_2 , T_2 V_114 )
{
struct V_5 * V_17 ;
T_2 V_115 ;
F_6 ( L_9 , V_114 ) ;
V_17 = F_3 ( V_2 , V_114 ) ;
if ( ! V_17 )
return;
F_6 ( L_10 , V_114 , V_17 -> V_8 ) ;
V_17 -> V_13 = false ;
V_17 -> V_111 = 0 ;
V_17 -> V_113 = 0 ;
V_115 = 1ull << F_7 ( V_17 ) ;
F_35 ( V_2 , V_114 & ~ ( V_115 - 1 ) , V_115 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
int V_7 ;
F_6 ( L_11 ) ;
for ( V_7 = 1 ; V_7 < V_2 -> V_3 . V_10 ; V_7 ++ ) {
V_2 -> V_3 . V_12 [ V_7 ] . V_13 = false ;
V_2 -> V_3 . V_12 [ V_7 ] . V_111 = 0 ;
V_2 -> V_3 . V_12 [ V_7 ] . V_113 = 0 ;
}
if ( F_23 ( V_2 ) & V_116 ) {
F_37 ( V_2 ) ;
F_31 ( V_2 , F_38 ( V_2 ) ) ;
}
}
static void F_39 ( struct V_1 * V_2 , T_3 V_117 ,
T_6 V_118 )
{
T_2 V_99 = 0 , V_98 = 0 ;
F_6 ( L_12 , V_117 , V_118 ) ;
V_99 |= ( V_117 & 0xf ) << 28 ;
V_99 |= 1 << 27 ;
V_99 |= V_117 ;
V_98 |= ( V_118 & 0xfffffff ) << 12 ;
V_98 |= ( ( V_118 >> 28 ) & 0x7 ) << 9 ;
F_30 ( V_2 , V_98 , V_99 ) ;
}
static void F_40 ( struct V_1 * V_2 , T_6 V_119 ,
bool V_16 )
{
T_2 V_120 = 0xFFFFFFFFFULL ;
long V_7 ;
struct V_1 * V_49 ;
F_6 ( L_13 , V_119 ) ;
if ( V_2 -> V_3 . V_85 & V_121 ) {
if ( V_119 & 1 ) {
if ( ( V_119 & 0xf000 ) == 0x1000 )
V_120 = 0xFFFFFFFF0ULL ;
else
V_120 = 0xFFFFFF000ULL ;
}
} else {
if ( V_16 )
V_120 = 0xFFFFFF000ULL ;
}
F_41 (i, v, vcpu->kvm)
F_42 ( V_49 , V_119 >> 12 , V_120 ) ;
}
static int F_43 ( struct V_1 * V_2 , T_6 V_8 )
{
T_6 V_57 = V_2 -> V_3 . V_58 ;
return V_57 && ! ( F_23 ( V_2 ) & V_59 ) &&
( V_57 >> V_19 ) == V_8 ;
}
static int F_44 ( struct V_1 * V_2 , T_6 V_8 ,
T_2 * V_15 )
{
T_6 V_114 = V_8 << V_19 ;
struct V_5 * V_12 ;
T_2 V_122 = V_8 ;
T_6 V_57 = V_2 -> V_3 . V_58 ;
int V_123 = V_23 ;
T_2 V_124 = F_23 ( V_2 ) ;
if ( V_124 & ( V_125 | V_116 ) ) {
V_12 = F_3 ( V_2 , V_114 ) ;
if ( V_12 ) {
V_122 = V_12 -> V_15 ;
V_123 = V_12 -> V_25 ;
if ( V_12 -> V_14 ) {
V_122 <<= V_18 - V_19 ;
V_122 |= V_8 & ( ( 1ul << ( V_18 - V_19 ) ) - 1 ) ;
V_122 |= V_126 ;
}
}
}
switch ( V_124 & ( V_125 | V_116 ) ) {
case 0 :
V_122 = V_127 | V_8 ;
break;
case V_116 :
V_122 |= V_128 ;
break;
case V_125 :
V_122 |= V_129 ;
break;
case V_125 | V_116 :
if ( ! V_12 )
goto V_130;
break;
default:
F_45 () ;
break;
}
#ifdef F_46
if ( V_123 >= V_23 &&
V_131 [ V_23 ] . V_132 &&
! F_43 ( V_2 , V_8 ) )
V_122 |= V_133 ;
#endif
if ( F_23 ( V_2 ) & V_59 )
V_122 |= V_134 ;
* V_15 = V_122 ;
return 0 ;
V_130:
if ( F_22 ( V_57 ) &&
F_22 ( V_8 == ( V_57 >> V_19 ) ) &&
! ( F_23 ( V_2 ) & V_59 ) ) {
* V_15 = V_127 | V_8 ;
return 0 ;
}
return - V_97 ;
}
static bool F_47 ( struct V_1 * V_2 )
{
return ( F_15 ( V_2 ) -> V_135 [ 5 ] & 0x80 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_136 * V_137 = & V_2 -> V_3 . V_137 ;
V_137 -> V_138 = NULL ;
V_137 -> V_139 = F_39 ;
V_137 -> V_140 = F_30 ;
V_137 -> V_141 = F_32 ;
V_137 -> V_142 = F_33 ;
V_137 -> V_143 = F_34 ;
V_137 -> V_144 = F_36 ;
V_137 -> V_145 = F_21 ;
V_137 -> V_146 = F_1 ;
V_137 -> V_147 = F_40 ;
V_137 -> V_148 = F_44 ;
V_137 -> V_149 = F_10 ;
V_137 -> V_150 = F_47 ;
V_2 -> V_3 . V_85 |= V_151 ;
}

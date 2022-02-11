static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 ;
F_2 ( V_4 -> V_6 . V_7 , V_5 ) ;
return V_5 ;
}
static struct V_8 *
F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_11 * V_14 = & V_4 -> V_6 . V_15 ;
unsigned long V_16 ;
bool V_17 = false ;
if ( V_12 -> V_18 == V_19 ||
( ! F_4 ( V_2 ) && V_12 -> V_20 ) )
return NULL ;
V_10 = & V_2 -> V_21 [ V_12 -> V_18 ] ;
F_5 ( & V_10 -> V_22 , V_16 ) ;
if ( ! F_6 ( & V_10 -> V_23 ) ||
( V_10 -> V_24 == V_12 -> V_25 && V_10 -> V_26 == V_14 -> V_25 ) ) {
F_7 ( & V_10 -> V_23 ) ;
V_10 -> V_24 = V_12 -> V_25 ;
V_10 -> V_26 = V_14 -> V_25 ;
V_17 = true ;
}
F_8 ( & V_10 -> V_22 , V_16 ) ;
if ( V_17 ) {
if ( ! F_4 ( V_2 ) )
V_12 -> V_20 = 1 ;
return NULL ;
}
return & V_27 ;
}
static void F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
if ( F_4 ( V_2 ) || ! V_12 -> V_20 )
return;
V_10 = & V_2 -> V_21 [ V_12 -> V_18 ] ;
F_10 ( & V_10 -> V_23 ) ;
V_12 -> V_20 = 0 ;
}
static T_1 F_11 ( struct V_1 * V_2 , int V_18 )
{
struct V_9 * V_10 ;
unsigned long V_16 ;
T_1 V_25 ;
V_10 = & V_2 -> V_21 [ V_18 ] ;
F_5 ( & V_10 -> V_22 , V_16 ) ;
V_25 = V_10 -> V_25 ;
F_8 ( & V_10 -> V_22 , V_16 ) ;
return V_25 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_28 ;
int V_30 = F_13 ( V_2 ) ;
T_2 V_25 = 0 ;
if ( ! F_14 ( V_29 , V_30 , & V_25 ) ) {
V_25 |= V_31 ;
F_15 ( V_29 , V_30 , V_25 ) ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_28 ;
int V_30 = F_13 ( V_2 ) ;
T_2 V_25 = 0 ;
if ( ! F_14 ( V_29 , V_30 , & V_25 ) ) {
V_25 &= ~ V_31 ;
F_15 ( V_29 , V_30 , V_25 ) ;
}
}
static void F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_28 * V_29 = V_2 -> V_28 ;
struct V_32 * V_33 = & V_4 -> V_6 ;
F_15 ( V_29 , V_33 -> V_34 , V_33 -> V_25 | V_35 ) ;
}
static void F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_28 * V_29 = V_2 -> V_28 ;
struct V_32 * V_33 = & V_4 -> V_6 ;
F_15 ( V_29 , V_33 -> V_34 , V_33 -> V_25 ) ;
}
static T_1 F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_28 * V_29 = V_2 -> V_28 ;
struct V_32 * V_33 = & V_4 -> V_6 ;
T_1 V_5 = 0 ;
F_14 ( V_29 , V_33 -> V_7 , ( T_2 * ) & V_5 ) ;
F_14 ( V_29 , V_33 -> V_7 + 4 , ( T_2 * ) & V_5 + 1 ) ;
return V_5 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_28 ;
F_15 ( V_29 , V_36 , V_37 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_1 V_25 ;
unsigned V_38 ;
V_38 = F_22 ( V_2 ) ;
if ( V_38 ) {
F_2 ( V_38 , V_25 ) ;
V_25 |= V_31 ;
F_23 ( V_38 , V_25 ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
T_1 V_25 ;
unsigned V_38 ;
V_38 = F_22 ( V_2 ) ;
if ( V_38 ) {
F_2 ( V_38 , V_25 ) ;
V_25 &= ~ V_31 ;
F_23 ( V_38 , V_25 ) ;
}
}
static void F_25 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
if ( V_12 -> V_18 != V_19 )
F_23 ( V_12 -> V_39 , F_11 ( V_2 , 0 ) ) ;
F_23 ( V_33 -> V_34 , V_33 -> V_25 | V_35 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
F_23 ( V_33 -> V_34 , V_33 -> V_25 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
unsigned V_38 = F_22 ( V_2 ) ;
if ( V_38 )
F_23 ( V_38 , V_37 ) ;
}
static void F_28 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_9 * V_10 = & V_2 -> V_21 [ 0 ] ;
int V_40 ;
if ( F_4 ( V_2 ) )
return;
for ( V_40 = 0 ; V_40 < 5 ; V_40 ++ ) {
if ( V_12 -> V_20 & ( 0x1 << V_40 ) )
F_29 ( 1 << ( V_40 * 6 ) , & V_10 -> V_23 ) ;
}
V_12 -> V_20 = 0 ;
}
static struct V_8 *
F_30 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 (* F_31)( int V_41 ) )
{
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_9 * V_10 = & V_2 -> V_21 [ 0 ] ;
int V_40 , V_20 = 0 ;
unsigned long V_16 ;
T_1 V_42 ;
if ( V_12 -> V_18 == V_19 )
return NULL ;
F_5 ( & V_10 -> V_22 , V_16 ) ;
for ( V_40 = 0 ; V_40 < 5 ; V_40 ++ ) {
if ( ! ( V_12 -> V_18 & ( 0x1 << V_40 ) ) )
continue;
if ( ! F_4 ( V_2 ) && ( V_12 -> V_20 & ( 0x1 << V_40 ) ) )
continue;
V_42 = F_31 ( 0x1 << V_40 ) ;
if ( ! F_32 ( F_6 ( & V_10 -> V_23 ) , V_40 , 6 ) ||
! ( ( V_12 -> V_25 ^ V_10 -> V_25 ) & V_42 ) ) {
F_33 ( 1 << ( V_40 * 6 ) , & V_10 -> V_23 ) ;
V_10 -> V_25 &= ~ V_42 ;
V_10 -> V_25 |= V_12 -> V_25 & V_42 ;
V_20 |= ( 0x1 << V_40 ) ;
} else {
break;
}
}
F_8 ( & V_10 -> V_22 , V_16 ) ;
if ( V_40 < 5 )
goto V_43;
if ( ! F_4 ( V_2 ) )
V_12 -> V_20 |= V_20 ;
return 0 ;
V_43:
for (; V_40 >= 0 ; V_40 -- ) {
if ( V_20 & ( 0x1 << V_40 ) )
F_29 ( 1 << ( V_40 * 6 ) , & V_10 -> V_23 ) ;
}
return & V_27 ;
}
static T_1 F_34 ( int V_41 )
{
T_1 V_42 = 0 ;
if ( V_41 & 0x1 )
V_42 |= V_44 ;
if ( V_41 & 0x2 )
V_42 |= V_45 ;
if ( V_41 & 0x4 )
V_42 |= V_46 ;
if ( V_41 & 0x8 )
V_42 |= V_47 ;
return V_42 ;
}
static struct V_8 *
F_35 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_30 ( V_2 , V_4 , F_34 ) ;
}
static int F_36 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_13 * V_10 ;
int V_18 = 0 ;
for ( V_10 = V_48 ; V_10 -> V_38 ; V_10 ++ ) {
if ( V_10 -> V_4 != ( V_4 -> V_6 . V_25 & V_10 -> V_49 ) )
continue;
V_18 |= V_10 -> V_18 ;
}
if ( V_18 ) {
V_12 -> V_39 = V_50 +
V_51 * V_2 -> V_52 -> V_53 ;
V_12 -> V_25 = V_4 -> V_54 . V_24 & F_34 ( V_18 ) ;
V_12 -> V_18 = V_18 ;
}
return 0 ;
}
static T_1 F_37 ( struct V_3 * V_4 , int V_55 , bool V_56 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
T_1 V_25 = V_12 -> V_25 ;
if ( V_55 > V_12 -> V_18 )
V_25 <<= 8 * ( V_55 - V_12 -> V_18 ) ;
else
V_25 >>= 8 * ( V_12 -> V_18 - V_55 ) ;
if ( V_56 ) {
V_33 -> V_25 += V_55 - V_12 -> V_18 ;
V_12 -> V_25 = V_25 ;
V_12 -> V_18 = V_55 ;
}
return V_25 ;
}
static struct V_8 *
F_38 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_9 * V_10 = & V_2 -> V_21 [ 0 ] ;
unsigned long V_16 ;
int V_18 = V_12 -> V_18 ;
T_1 V_42 , V_24 = V_12 -> V_25 ;
bool V_17 = false ;
if ( V_12 -> V_18 == V_19 ||
( ! F_4 ( V_2 ) && V_12 -> V_20 ) )
return NULL ;
V_57:
V_42 = 0xff << ( V_18 * 8 ) ;
F_5 ( & V_10 -> V_22 , V_16 ) ;
if ( ! F_32 ( F_6 ( & V_10 -> V_23 ) , V_18 , 8 ) ||
! ( ( V_24 ^ V_10 -> V_25 ) & V_42 ) ) {
F_33 ( 1 << ( V_18 * 8 ) , & V_10 -> V_23 ) ;
V_10 -> V_25 &= ~ V_42 ;
V_10 -> V_25 |= V_24 & V_42 ;
V_17 = true ;
}
F_8 ( & V_10 -> V_22 , V_16 ) ;
if ( ! V_17 ) {
V_18 = ( V_18 + 1 ) % 4 ;
if ( V_18 != V_12 -> V_18 ) {
V_24 = F_37 ( V_4 , V_18 , false ) ;
goto V_57;
}
return & V_27 ;
}
if ( ! F_4 ( V_2 ) ) {
if ( V_18 != V_12 -> V_18 )
F_37 ( V_4 , V_18 , true ) ;
V_12 -> V_20 = 1 ;
}
return NULL ;
}
static void F_39 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_9 * V_10 = & V_2 -> V_21 [ 0 ] ;
if ( F_4 ( V_2 ) || ! V_12 -> V_20 )
return;
F_29 ( 1 << ( V_12 -> V_18 * 8 ) , & V_10 -> V_23 ) ;
V_12 -> V_20 = 0 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
int V_58 = V_33 -> V_25 & V_59 ;
if ( V_58 >= 0xb && V_58 <= 0xe ) {
V_12 -> V_39 = V_60 ;
V_12 -> V_18 = V_58 - 0xb ;
V_12 -> V_25 = V_4 -> V_54 . V_24 & ( 0xff << V_12 -> V_18 ) ;
}
return 0 ;
}
static int F_41 ( int V_61 )
{
struct V_28 * V_62 = NULL ;
int V_40 , V_63 , V_64 ;
int V_65 = 0 ;
T_2 V_25 = 0 ;
while ( 1 ) {
V_62 = F_42 ( V_66 , V_61 , V_62 ) ;
if ( ! V_62 )
break;
V_63 = V_62 -> V_63 -> V_67 ;
V_65 = F_14 ( V_62 , 0x40 , & V_25 ) ;
if ( V_65 )
break;
V_64 = V_25 ;
V_65 = F_14 ( V_62 , 0x54 , & V_25 ) ;
if ( V_65 )
break;
for ( V_40 = 0 ; V_40 < 8 ; V_40 ++ ) {
if ( V_64 == ( ( V_25 >> ( 3 * V_40 ) ) & 0x7 ) ) {
V_68 [ V_63 ] = V_40 ;
break;
}
}
}
if ( V_62 )
F_43 ( V_62 ) ;
return V_65 ? F_44 ( V_65 ) : 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
unsigned V_38 = F_22 ( V_2 ) ;
if ( V_38 )
F_23 ( V_38 , V_69 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_28 ;
F_15 ( V_29 , V_36 , V_69 ) ;
}
static T_1 F_47 ( int V_41 )
{
T_1 V_42 = 0 ;
if ( V_41 & 0x1 )
V_42 |= V_70 ;
if ( V_41 & 0x2 )
V_42 |= V_71 ;
if ( V_41 & 0x4 )
V_42 |= V_72 ;
if ( V_41 & 0x8 )
V_42 |= V_73 ;
if ( V_41 & 0x10 )
V_42 |= V_74 ;
return V_42 ;
}
static struct V_8 *
F_48 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_30 ( V_2 , V_4 , F_47 ) ;
}
static int F_49 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_13 * V_10 ;
int V_18 = 0 ;
for ( V_10 = V_75 ; V_10 -> V_38 ; V_10 ++ ) {
if ( V_10 -> V_4 != ( V_4 -> V_6 . V_25 & V_10 -> V_49 ) )
continue;
V_18 |= V_10 -> V_18 ;
}
if ( V_18 ) {
V_12 -> V_39 = V_50 +
V_51 * V_2 -> V_52 -> V_53 ;
V_12 -> V_25 = V_4 -> V_54 . V_24 & F_47 ( V_18 ) ;
V_12 -> V_18 = V_18 ;
}
return 0 ;
}
static void F_50 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
if ( V_12 -> V_18 != V_19 ) {
T_1 V_76 = F_11 ( V_2 , 0 ) ;
F_23 ( V_12 -> V_39 , V_76 & 0xffffffff ) ;
F_23 ( V_12 -> V_39 + 6 , V_76 >> 32 ) ;
}
F_23 ( V_33 -> V_34 , V_33 -> V_25 | V_35 ) ;
}
static void F_51 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 < V_77 )
F_23 ( V_33 -> V_34 , V_33 -> V_25 | V_78 ) ;
else
F_23 ( V_33 -> V_34 , V_78 ) ;
}
static void F_52 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_23 ( V_4 -> V_6 . V_34 , 0 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_52 -> V_53 == 0 ) {
F_23 ( V_79 ,
V_80 | V_81 ) ;
}
}
static void F_54 ( struct V_1 * V_2 )
{
F_23 ( V_82 , 0 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_23 ( V_82 , V_83 | V_84 ) ;
}
static void F_56 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 < V_77 )
F_23 ( V_33 -> V_34 , V_33 -> V_25 | V_78 ) ;
else
F_23 ( V_33 -> V_34 , V_85 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_23 ( V_86 , V_87 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
unsigned V_38 = F_22 ( V_2 ) ;
T_1 V_25 ;
if ( V_38 ) {
F_2 ( V_38 , V_25 ) ;
V_25 &= ~ ( ( 1ULL << F_59 ( V_2 ) ) - 1 ) ;
if ( F_60 ( V_2 ) )
V_25 &= ~ V_88 ;
F_23 ( V_38 , V_25 ) ;
}
}
static void F_61 ( struct V_1 * V_2 )
{
unsigned V_38 = F_22 ( V_2 ) ;
T_1 V_25 ;
if ( V_38 ) {
F_2 ( V_38 , V_25 ) ;
V_25 |= ( 1ULL << F_59 ( V_2 ) ) - 1 ;
if ( F_60 ( V_2 ) )
V_25 |= V_88 ;
F_23 ( V_38 , V_25 ) ;
}
}
static void F_62 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_23 ( V_4 -> V_6 . V_34 , 0 ) ;
}
static void F_63 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 >= V_77 )
F_23 ( V_33 -> V_34 , V_89 ) ;
else if ( V_2 -> V_52 -> type -> V_90 & V_89 )
F_23 ( V_33 -> V_34 , V_33 -> V_25 | V_91 ) ;
else
F_23 ( V_33 -> V_34 , V_33 -> V_25 | V_89 ) ;
}
static int F_64 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
int V_92 , V_58 ;
V_92 = ( V_33 -> V_25 & V_93 ) >>
V_94 ;
V_58 = ( V_33 -> V_25 & V_95 ) >>
V_96 ;
if ( ( V_92 == 0 && V_58 > 0x3 ) || ( V_92 == 1 && V_58 > 0x6 ) ||
( V_92 == 2 && V_58 != 0x4 ) || V_92 == 3 )
return 0 ;
if ( V_2 -> V_52 -> V_53 == 0 )
V_12 -> V_39 = V_97 ;
else
V_12 -> V_39 = V_98 ;
V_12 -> V_18 = 0 ;
V_12 -> V_25 = V_4 -> V_54 . V_24 ;
V_14 -> V_25 = V_4 -> V_54 . V_26 ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
if ( V_12 -> V_18 != V_19 ) {
F_23 ( V_12 -> V_39 , V_12 -> V_25 ) ;
F_23 ( V_12 -> V_39 + 1 , V_14 -> V_25 ) ;
}
F_23 ( V_33 -> V_34 , V_89 |
( V_33 -> V_25 & V_95 ) ) ;
}
static int F_66 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
if ( ( V_33 -> V_25 & V_99 ) !=
V_100 )
return 0 ;
if ( V_2 -> V_52 -> V_53 == 0 )
V_12 -> V_39 = V_101 ;
else
V_12 -> V_39 = V_102 ;
V_12 -> V_18 = 0 ;
V_12 -> V_25 = V_4 -> V_54 . V_24 ;
V_14 -> V_25 = V_4 -> V_54 . V_26 ;
return 0 ;
}
static void F_67 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
if ( V_12 -> V_18 != V_19 ) {
F_23 ( V_12 -> V_39 , 0 ) ;
F_23 ( V_12 -> V_39 + 1 , V_12 -> V_25 ) ;
F_23 ( V_12 -> V_39 + 2 , V_14 -> V_25 ) ;
F_23 ( V_12 -> V_39 , V_103 ) ;
}
F_23 ( V_33 -> V_34 , V_33 -> V_25 | V_91 ) ;
}
static bool F_68 ( struct V_1 * V_2 , int V_18 , T_1 V_25 )
{
struct V_9 * V_10 ;
unsigned long V_16 ;
bool V_104 = false ;
T_1 V_42 ;
if ( V_18 < V_105 ) {
V_10 = & V_2 -> V_21 [ V_18 ] ;
F_5 ( & V_10 -> V_22 , V_16 ) ;
if ( ! F_6 ( & V_10 -> V_23 ) || V_10 -> V_25 == V_25 ) {
F_7 ( & V_10 -> V_23 ) ;
V_10 -> V_25 = V_25 ;
V_104 = true ;
}
F_8 ( & V_10 -> V_22 , V_16 ) ;
return V_104 ;
}
V_18 -= V_105 ;
if ( F_69 ( V_18 >= 4 ) )
return false ;
if ( V_106 )
V_42 = V_107 ;
else
V_42 = V_108 ;
V_10 = & V_2 -> V_21 [ V_105 ] ;
F_5 ( & V_10 -> V_22 , V_16 ) ;
if ( F_32 ( F_6 ( & V_10 -> V_23 ) , V_18 , 8 ) ) {
if ( V_106 )
V_42 |= F_70 ( V_18 ) ;
else
V_42 |= F_71 ( V_18 ) ;
}
if ( ! F_6 ( & V_10 -> V_23 ) || ! ( ( V_10 -> V_25 ^ V_25 ) & V_42 ) ) {
F_33 ( 1 << ( V_18 * 8 ) , & V_10 -> V_23 ) ;
if ( V_106 )
V_42 = V_107 |
F_70 ( V_18 ) ;
else
V_42 = V_108 |
F_71 ( V_18 ) ;
V_10 -> V_25 &= ~ V_42 ;
V_10 -> V_25 |= ( V_25 & V_42 ) ;
V_104 = true ;
}
F_8 ( & V_10 -> V_22 , V_16 ) ;
return V_104 ;
}
static void F_72 ( struct V_1 * V_2 , int V_18 )
{
struct V_9 * V_10 ;
if ( V_18 < V_105 ) {
V_10 = & V_2 -> V_21 [ V_18 ] ;
F_10 ( & V_10 -> V_23 ) ;
return;
}
V_18 -= V_105 ;
V_10 = & V_2 -> V_21 [ V_105 ] ;
F_29 ( 1 << ( V_18 * 8 ) , & V_10 -> V_23 ) ;
}
static T_1 F_73 ( struct V_3 * V_4 , int V_55 , bool V_56 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
int V_18 , V_109 = F_32 ( V_12 -> V_18 , 0 , 8 ) ;
T_1 V_25 = V_12 -> V_25 ;
V_18 = V_109 - V_105 ;
if ( V_106 )
V_25 &= F_70 ( V_18 ) ;
else
V_25 &= F_71 ( V_18 ) ;
if ( V_55 > V_109 ) {
V_18 = V_55 - V_109 ;
V_25 <<= 3 * V_18 ;
} else {
V_18 = V_109 - V_55 ;
V_25 >>= 3 * V_18 ;
}
if ( V_106 )
V_25 |= V_107 & V_12 -> V_25 ;
else
V_25 |= V_108 & V_12 -> V_25 ;
V_25 |= V_107 & V_12 -> V_25 ;
if ( V_56 ) {
if ( V_55 > V_109 )
V_33 -> V_25 += V_18 << V_110 ;
else
V_33 -> V_25 -= V_18 << V_110 ;
V_12 -> V_25 = V_25 ;
V_12 -> V_18 = ~ 0xff | V_55 ;
}
return V_25 ;
}
static struct V_8 *
F_74 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_11 * V_14 = & V_4 -> V_6 . V_15 ;
int V_40 , V_18 [ 2 ] , V_20 = 0 ;
T_1 V_24 = V_12 -> V_25 ;
V_18 [ 0 ] = F_32 ( V_12 -> V_18 , 0 , 8 ) ;
V_18 [ 1 ] = F_32 ( V_12 -> V_18 , 1 , 8 ) ;
V_57:
for ( V_40 = 0 ; V_40 < 2 ; V_40 ++ ) {
if ( ! F_4 ( V_2 ) && ( V_12 -> V_20 & ( 0x1 << V_40 ) ) )
V_18 [ V_40 ] = 0xff ;
if ( V_18 [ V_40 ] == 0xff )
continue;
if ( ! F_68 ( V_2 , V_18 [ V_40 ] ,
F_32 ( V_24 , V_40 , 32 ) ) )
goto V_43;
V_20 |= ( 0x1 << V_40 ) ;
}
if ( V_14 -> V_18 != V_19 &&
( F_4 ( V_2 ) || ! V_14 -> V_20 ) &&
! F_68 ( V_2 , V_14 -> V_18 , V_14 -> V_25 ) )
goto V_43;
if ( ! F_4 ( V_2 ) ) {
if ( V_18 [ 0 ] != 0xff && V_18 [ 0 ] != F_32 ( V_12 -> V_18 , 0 , 8 ) )
F_73 ( V_4 , V_18 [ 0 ] , true ) ;
V_12 -> V_20 |= V_20 ;
if ( V_14 -> V_18 != V_19 )
V_14 -> V_20 = 1 ;
}
return NULL ;
V_43:
if ( V_18 [ 0 ] != 0xff && ! ( V_20 & 0x1 ) &&
V_18 [ 0 ] >= V_105 ) {
F_75 ( F_32 ( V_12 -> V_18 , 1 , 8 ) != 0xff ) ;
V_18 [ 0 ] -= V_105 ;
V_18 [ 0 ] = ( V_18 [ 0 ] + 1 ) % 4 ;
V_18 [ 0 ] += V_105 ;
if ( V_18 [ 0 ] != F_32 ( V_12 -> V_18 , 0 , 8 ) ) {
V_24 = F_73 ( V_4 , V_18 [ 0 ] , false ) ;
goto V_57;
}
}
if ( V_20 & 0x1 )
F_72 ( V_2 , V_18 [ 0 ] ) ;
if ( V_20 & 0x2 )
F_72 ( V_2 , V_18 [ 1 ] ) ;
return & V_27 ;
}
static void F_76 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_11 * V_14 = & V_4 -> V_6 . V_15 ;
if ( F_4 ( V_2 ) )
return;
if ( V_12 -> V_20 & 0x1 )
F_72 ( V_2 , F_32 ( V_12 -> V_18 , 0 , 8 ) ) ;
if ( V_12 -> V_20 & 0x2 )
F_72 ( V_2 , F_32 ( V_12 -> V_18 , 1 , 8 ) ) ;
V_12 -> V_20 = 0 ;
if ( V_14 -> V_20 ) {
F_72 ( V_2 , V_14 -> V_18 ) ;
V_14 -> V_20 = 0 ;
}
}
static int F_77 ( struct V_13 * V_10 )
{
if ( V_10 -> V_18 < V_105 )
return V_10 -> V_18 ;
return V_10 -> V_18 + ( V_10 -> V_4 >> V_110 ) - 0xd ;
}
static int F_78 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_111 * type = V_2 -> V_52 -> type ;
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_11 * V_14 = & V_4 -> V_6 . V_15 ;
struct V_13 * V_10 ;
unsigned V_38 ;
int V_112 = 0 ;
for ( V_10 = V_113 ; V_10 -> V_38 ; V_10 ++ ) {
if ( V_10 -> V_4 != ( V_4 -> V_6 . V_25 & V_10 -> V_49 ) )
continue;
if ( V_4 -> V_54 . V_24 & ~ V_10 -> V_114 )
return - V_115 ;
V_38 = V_10 -> V_38 + type -> V_116 * V_2 -> V_52 -> V_53 ;
if ( F_69 ( V_38 >= 0xffff || V_10 -> V_18 >= 0xff ) )
return - V_115 ;
if ( V_10 -> V_18 == V_117 )
V_112 = 1 ;
else if ( F_69 ( V_112 > 0 ) )
return - V_115 ;
V_12 -> V_18 &= ~ ( 0xff << ( V_112 * 8 ) ) ;
V_12 -> V_39 &= ~ ( 0xffff << ( V_112 * 16 ) ) ;
V_12 -> V_18 |= F_77 ( V_10 ) << ( V_112 * 8 ) ;
V_12 -> V_39 |= V_38 << ( V_112 * 16 ) ;
V_12 -> V_25 = V_4 -> V_54 . V_24 ;
V_112 ++ ;
}
if ( V_112 == 2 ) {
V_14 -> V_18 = V_118 ;
if ( V_4 -> V_54 . V_26 & V_119 )
V_14 -> V_25 = V_4 -> V_54 . V_26 ;
else
V_14 -> V_25 = ~ 0ULL ;
if ( V_2 -> V_52 -> V_53 == 0 )
V_14 -> V_39 = V_120 ;
else
V_14 -> V_39 = V_121 ;
}
return 0 ;
}
static T_1 F_79 ( struct V_1 * V_2 , int V_18 )
{
struct V_9 * V_10 ;
unsigned long V_16 ;
T_1 V_25 ;
if ( V_18 < V_105 )
return V_2 -> V_21 [ V_18 ] . V_25 ;
V_10 = & V_2 -> V_21 [ V_105 ] ;
F_5 ( & V_10 -> V_22 , V_16 ) ;
V_25 = V_10 -> V_25 ;
F_8 ( & V_10 -> V_22 , V_16 ) ;
return V_25 ;
}
static void F_80 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
int V_18 ;
V_18 = F_32 ( V_12 -> V_18 , 0 , 8 ) ;
if ( V_18 != 0xff )
F_23 ( F_32 ( V_12 -> V_39 , 0 , 16 ) ,
F_79 ( V_2 , V_18 ) ) ;
V_18 = F_32 ( V_12 -> V_18 , 1 , 8 ) ;
if ( V_18 != 0xff )
F_23 ( F_32 ( V_12 -> V_39 , 1 , 16 ) ,
F_79 ( V_2 , V_18 ) ) ;
if ( V_14 -> V_18 != V_19 ) {
F_23 ( V_14 -> V_39 , 0 ) ;
if ( V_14 -> V_25 != ~ 0ULL ) {
F_23 ( V_14 -> V_39 + 1 ,
V_14 -> V_25 & V_122 ) ;
F_23 ( V_14 -> V_39 + 2 , V_123 &
( V_14 -> V_25 >> V_124 ) ) ;
F_23 ( V_14 -> V_39 , V_119 ) ;
}
}
F_23 ( V_33 -> V_34 , V_33 -> V_25 | V_89 ) ;
}
static void F_81 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
if ( V_12 -> V_18 % 2 ) {
V_12 -> V_18 -- ;
V_33 -> V_25 -= 1 << V_125 ;
} else {
V_12 -> V_18 ++ ;
V_33 -> V_25 += 1 << V_125 ;
}
switch ( V_12 -> V_18 % 6 ) {
case 2 :
V_12 -> V_25 >>= 8 ;
break;
case 3 :
V_12 -> V_25 <<= 8 ;
break;
} ;
}
static struct V_8 *
F_82 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
struct V_9 * V_10 ;
unsigned long V_16 ;
int V_18 , V_126 ;
T_1 V_24 ;
bool V_17 = false ;
if ( ! F_4 ( V_2 ) && V_12 -> V_20 )
return NULL ;
V_18 = V_12 -> V_18 % 6 ;
V_24 = V_12 -> V_25 ;
V_57:
V_126 = V_18 ;
if ( V_126 > 2 )
V_126 -- ;
V_126 += ( V_12 -> V_18 / 6 ) * 5 ;
V_10 = & V_2 -> V_21 [ V_126 ] ;
F_5 ( & V_10 -> V_22 , V_16 ) ;
if ( V_18 < 2 ) {
if ( ! F_6 ( & V_10 -> V_23 ) || V_10 -> V_25 == V_12 -> V_25 ) {
F_7 ( & V_10 -> V_23 ) ;
V_10 -> V_25 = V_12 -> V_25 ;
V_17 = true ;
}
} else if ( V_18 == 2 || V_18 == 3 ) {
T_1 V_42 = 0xff << ( ( V_18 - 2 ) * 8 ) ;
if ( ! F_32 ( F_6 ( & V_10 -> V_23 ) , V_18 - 2 , 8 ) ||
! ( ( V_10 -> V_25 ^ V_24 ) & V_42 ) ) {
F_33 ( 1 << ( ( V_18 - 2 ) * 8 ) , & V_10 -> V_23 ) ;
V_10 -> V_25 &= ~ V_42 ;
V_10 -> V_25 |= V_24 & V_42 ;
V_17 = true ;
}
} else {
if ( ! F_6 ( & V_10 -> V_23 ) ||
( V_10 -> V_25 == ( V_33 -> V_25 >> 32 ) &&
V_10 -> V_24 == V_12 -> V_25 &&
V_10 -> V_26 == V_14 -> V_25 ) ) {
F_7 ( & V_10 -> V_23 ) ;
V_10 -> V_25 = ( V_33 -> V_25 >> 32 ) ;
V_10 -> V_24 = V_12 -> V_25 ;
V_10 -> V_26 = V_14 -> V_25 ;
V_17 = true ;
}
}
F_8 ( & V_10 -> V_22 , V_16 ) ;
if ( ! V_17 ) {
if ( V_18 % 2 )
V_18 -- ;
else
V_18 ++ ;
if ( V_18 != V_12 -> V_18 % 6 ) {
if ( V_18 == 2 )
V_24 >>= 8 ;
else if ( V_18 == 3 )
V_24 <<= 8 ;
goto V_57;
}
} else {
if ( ! F_4 ( V_2 ) ) {
if ( V_18 != V_12 -> V_18 % 6 )
F_81 ( V_2 , V_4 ) ;
V_12 -> V_20 = 1 ;
}
return NULL ;
}
return & V_27 ;
}
static void F_83 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
int V_18 , V_126 ;
if ( F_4 ( V_2 ) || ! V_12 -> V_20 )
return;
V_18 = V_12 -> V_18 % 6 ;
V_126 = V_18 ;
if ( V_126 > 2 )
V_126 -- ;
V_126 += ( V_12 -> V_18 / 6 ) * 5 ;
V_10 = & V_2 -> V_21 [ V_126 ] ;
if ( V_18 == 2 || V_18 == 3 )
F_29 ( 1 << ( ( V_18 - 2 ) * 8 ) , & V_10 -> V_23 ) ;
else
F_10 ( & V_10 -> V_23 ) ;
V_12 -> V_20 = 0 ;
}
static int F_84 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_11 * V_14 = & V_4 -> V_6 . V_15 ;
int V_18 ;
V_18 = ( V_4 -> V_6 . V_25 & V_127 ) >>
V_125 ;
if ( V_18 >= 0x18 )
return - V_115 ;
V_12 -> V_18 = V_18 ;
V_12 -> V_25 = V_4 -> V_54 . V_24 ;
switch ( V_18 % 6 ) {
case 4 :
case 5 :
V_33 -> V_25 |= V_4 -> V_54 . V_25 & ( ~ 0ULL << 32 ) ;
V_14 -> V_25 = V_4 -> V_54 . V_26 ;
break;
} ;
return 0 ;
}
static void F_85 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
int V_18 , V_128 ;
V_18 = V_12 -> V_18 ;
V_128 = V_18 / 6 + V_2 -> V_52 -> V_53 * 4 ;
switch ( V_18 % 6 ) {
case 0 :
F_23 ( F_86 ( V_128 ) , V_12 -> V_25 ) ;
break;
case 1 :
F_23 ( F_87 ( V_128 ) , V_12 -> V_25 ) ;
break;
case 2 :
case 3 :
F_23 ( F_88 ( V_128 ) ,
F_11 ( V_2 , 2 + ( V_18 / 6 ) * 5 ) ) ;
break;
case 4 :
F_23 ( F_89 ( V_128 ) ,
V_33 -> V_25 >> 32 ) ;
F_23 ( F_90 ( V_128 ) , V_12 -> V_25 ) ;
F_23 ( F_91 ( V_128 ) , V_14 -> V_25 ) ;
break;
case 5 :
F_23 ( F_92 ( V_128 ) ,
V_33 -> V_25 >> 32 ) ;
F_23 ( F_93 ( V_128 ) , V_12 -> V_25 ) ;
F_23 ( F_94 ( V_128 ) , V_14 -> V_25 ) ;
break;
} ;
F_23 ( V_33 -> V_34 , V_89 |
( V_33 -> V_25 & V_127 ) ) ;
}
static void F_95 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_18 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
V_33 -> V_18 = V_18 ;
V_33 -> V_129 = ++ V_2 -> V_130 [ V_18 ] ;
if ( V_33 -> V_18 == V_77 ) {
V_33 -> V_7 = F_96 ( V_2 ) ;
V_33 -> V_34 = F_97 ( V_2 ) ;
return;
}
V_33 -> V_34 = F_98 ( V_2 , V_33 -> V_18 ) ;
V_33 -> V_7 = F_99 ( V_2 , V_33 -> V_18 ) ;
}
static void F_100 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_131 , V_132 , V_133 ;
int V_134 ;
if ( V_4 -> V_6 . V_18 >= V_77 )
V_134 = 64 - F_101 ( V_2 ) ;
else
V_134 = 64 - F_102 ( V_2 ) ;
V_57:
V_131 = F_103 ( & V_4 -> V_6 . V_131 ) ;
V_132 = F_104 ( V_2 , V_4 ) ;
if ( F_105 ( & V_4 -> V_6 . V_131 , V_132 ) != V_131 )
goto V_57;
V_133 = ( V_132 << V_134 ) - ( V_131 << V_134 ) ;
V_133 >>= V_134 ;
F_106 ( V_133 , & V_4 -> V_5 ) ;
}
static enum V_135 F_107 ( struct V_136 * V_136 )
{
struct V_1 * V_2 ;
unsigned long V_16 ;
int V_137 ;
V_2 = F_108 ( V_136 , struct V_1 , V_136 ) ;
if ( ! V_2 -> V_138 || V_2 -> V_139 != F_109 () )
return V_140 ;
F_110 ( V_16 ) ;
F_111 (bit, box->active_mask, UNCORE_PMC_IDX_MAX)
F_100 ( V_2 , V_2 -> V_141 [ V_137 ] ) ;
F_112 ( V_16 ) ;
F_113 ( V_136 , F_114 ( V_142 ) ) ;
return V_143 ;
}
static void F_115 ( struct V_1 * V_2 )
{
F_116 ( & V_2 -> V_136 ,
F_114 ( V_142 ) , 0 ,
V_144 , 0 ) ;
}
static void F_117 ( struct V_1 * V_2 )
{
F_118 ( & V_2 -> V_136 ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
F_120 ( & V_2 -> V_136 , V_145 , V_146 ) ;
V_2 -> V_136 . V_147 = F_107 ;
}
struct V_1 * F_121 ( struct V_111 * type , int V_139 )
{
struct V_1 * V_2 ;
int V_40 , V_148 ;
V_148 = sizeof( * V_2 ) + type -> V_149 * sizeof( struct V_9 ) ;
V_2 = F_122 ( V_148 , V_150 | V_151 , F_123 ( V_139 ) ) ;
if ( ! V_2 )
return NULL ;
for ( V_40 = 0 ; V_40 < type -> V_149 ; V_40 ++ )
F_124 ( & V_2 -> V_21 [ V_40 ] . V_22 ) ;
F_119 ( V_2 ) ;
F_125 ( & V_2 -> V_152 , 1 ) ;
V_2 -> V_139 = - 1 ;
V_2 -> V_153 = - 1 ;
return V_2 ;
}
static struct V_1 *
F_126 ( struct V_154 * V_52 , int V_139 )
{
struct V_1 * V_2 ;
V_2 = * F_127 ( V_52 -> V_2 , V_139 ) ;
if ( V_2 )
return V_2 ;
F_128 ( & V_155 ) ;
F_129 (box, &pmu->box_list, list) {
if ( V_2 -> V_153 == F_130 ( V_139 ) ) {
F_7 ( & V_2 -> V_152 ) ;
* F_127 ( V_52 -> V_2 , V_139 ) = V_2 ;
break;
}
}
F_131 ( & V_155 ) ;
return * F_127 ( V_52 -> V_2 , V_139 ) ;
}
static struct V_154 * F_132 ( struct V_3 * V_4 )
{
return F_108 ( V_4 -> V_52 , struct V_154 , V_52 ) ;
}
static struct V_1 * F_133 ( struct V_3 * V_4 )
{
return F_126 ( F_132 ( V_4 ) , F_109 () ) ;
}
static int
F_134 ( struct V_1 * V_2 , struct V_3 * V_156 , bool V_157 )
{
struct V_3 * V_4 ;
int V_158 , V_159 ;
V_159 = V_2 -> V_52 -> type -> V_160 ;
if ( V_2 -> V_52 -> type -> V_161 )
V_159 ++ ;
if ( V_2 -> V_162 >= V_159 )
return - V_115 ;
V_158 = V_2 -> V_162 ;
V_2 -> V_163 [ V_158 ] = V_156 ;
V_158 ++ ;
if ( ! V_157 )
return V_158 ;
F_129 (event, &leader->sibling_list, group_entry) {
if ( V_4 -> V_164 <= V_165 )
continue;
if ( V_158 >= V_159 )
return - V_115 ;
V_2 -> V_163 [ V_158 ] = V_4 ;
V_158 ++ ;
}
return V_158 ;
}
static struct V_8 *
F_135 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_111 * type = V_2 -> V_52 -> type ;
struct V_8 * V_166 ;
if ( type -> V_167 -> V_168 ) {
V_166 = type -> V_167 -> V_168 ( V_2 , V_4 ) ;
if ( V_166 )
return V_166 ;
}
if ( V_4 -> V_6 . V_25 == ~ 0ULL )
return & V_169 ;
if ( type -> V_170 ) {
F_136 (c, type->constraints) {
if ( ( V_4 -> V_6 . V_25 & V_166 -> V_171 ) == V_166 -> V_172 )
return V_166 ;
}
}
return & type -> V_173 ;
}
static void F_137 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_52 -> type -> V_167 -> V_174 )
V_2 -> V_52 -> type -> V_167 -> V_174 ( V_2 , V_4 ) ;
}
static int F_138 ( struct V_1 * V_2 , int V_175 [] , int V_158 )
{
unsigned long V_176 [ F_139 ( V_177 ) ] ;
struct V_8 * V_166 , * V_170 [ V_177 ] ;
int V_40 , V_178 , V_179 , V_104 = 0 ;
struct V_32 * V_33 ;
F_140 ( V_176 , V_177 ) ;
for ( V_40 = 0 , V_178 = V_177 , V_179 = 0 ; V_40 < V_158 ; V_40 ++ ) {
V_166 = F_135 ( V_2 , V_2 -> V_163 [ V_40 ] ) ;
V_170 [ V_40 ] = V_166 ;
V_178 = F_141 ( V_178 , V_166 -> V_180 ) ;
V_179 = F_142 ( V_179 , V_166 -> V_180 ) ;
}
for ( V_40 = 0 ; V_40 < V_158 ; V_40 ++ ) {
V_33 = & V_2 -> V_163 [ V_40 ] -> V_6 ;
V_166 = V_170 [ V_40 ] ;
if ( V_33 -> V_18 == - 1 )
break;
if ( ! F_143 ( V_33 -> V_18 , V_166 -> V_181 ) )
break;
if ( F_143 ( V_33 -> V_18 , V_176 ) )
break;
F_144 ( V_33 -> V_18 , V_176 ) ;
if ( V_175 )
V_175 [ V_40 ] = V_33 -> V_18 ;
}
if ( V_40 != V_158 )
V_104 = F_145 ( V_170 , V_158 , V_178 , V_179 , V_175 ) ;
if ( ! V_175 || V_104 ) {
for ( V_40 = 0 ; V_40 < V_158 ; V_40 ++ )
F_137 ( V_2 , V_2 -> V_163 [ V_40 ] ) ;
}
return V_104 ? - V_115 : 0 ;
}
static void F_146 ( struct V_3 * V_4 , int V_16 )
{
struct V_1 * V_2 = F_133 ( V_4 ) ;
int V_18 = V_4 -> V_6 . V_18 ;
if ( F_69 ( ! ( V_4 -> V_6 . V_164 & V_182 ) ) )
return;
if ( F_69 ( V_18 == - 1 || V_18 >= V_177 ) )
return;
V_4 -> V_6 . V_164 = 0 ;
V_2 -> V_141 [ V_18 ] = V_4 ;
V_2 -> V_138 ++ ;
F_144 ( V_18 , V_2 -> V_183 ) ;
F_147 ( & V_4 -> V_6 . V_131 , F_104 ( V_2 , V_4 ) ) ;
F_148 ( V_2 , V_4 ) ;
if ( V_2 -> V_138 == 1 ) {
F_149 ( V_2 ) ;
F_115 ( V_2 ) ;
}
}
static void F_150 ( struct V_3 * V_4 , int V_16 )
{
struct V_1 * V_2 = F_133 ( V_4 ) ;
struct V_32 * V_33 = & V_4 -> V_6 ;
if ( F_151 ( V_33 -> V_18 , V_2 -> V_183 ) ) {
F_152 ( V_2 , V_4 ) ;
V_2 -> V_138 -- ;
V_2 -> V_141 [ V_33 -> V_18 ] = NULL ;
F_69 ( V_33 -> V_164 & V_182 ) ;
V_33 -> V_164 |= V_182 ;
if ( V_2 -> V_138 == 0 ) {
F_153 ( V_2 ) ;
F_117 ( V_2 ) ;
}
}
if ( ( V_16 & V_184 ) && ! ( V_33 -> V_164 & V_185 ) ) {
F_100 ( V_2 , V_4 ) ;
V_33 -> V_164 |= V_185 ;
}
}
static int F_154 ( struct V_3 * V_4 , int V_16 )
{
struct V_1 * V_2 = F_133 ( V_4 ) ;
struct V_32 * V_33 = & V_4 -> V_6 ;
int V_175 [ V_177 ] ;
int V_40 , V_158 , V_104 ;
if ( ! V_2 )
return - V_186 ;
V_104 = V_158 = F_134 ( V_2 , V_4 , false ) ;
if ( V_104 < 0 )
return V_104 ;
V_33 -> V_164 = V_185 | V_182 ;
if ( ! ( V_16 & V_187 ) )
V_33 -> V_164 |= V_188 ;
V_104 = F_138 ( V_2 , V_175 , V_158 ) ;
if ( V_104 )
return V_104 ;
for ( V_40 = 0 ; V_40 < V_2 -> V_162 ; V_40 ++ ) {
V_4 = V_2 -> V_163 [ V_40 ] ;
V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 == V_175 [ V_40 ] &&
V_33 -> V_129 == V_2 -> V_130 [ V_175 [ V_40 ] ] )
continue;
if ( V_33 -> V_164 & V_182 )
V_33 -> V_164 |= V_188 ;
F_150 ( V_4 , V_184 ) ;
}
for ( V_40 = 0 ; V_40 < V_158 ; V_40 ++ ) {
V_4 = V_2 -> V_163 [ V_40 ] ;
V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 != V_175 [ V_40 ] ||
V_33 -> V_129 != V_2 -> V_130 [ V_175 [ V_40 ] ] )
F_95 ( V_2 , V_4 , V_175 [ V_40 ] ) ;
else if ( V_40 < V_2 -> V_162 )
continue;
if ( V_33 -> V_164 & V_188 )
continue;
F_146 ( V_4 , 0 ) ;
}
V_2 -> V_162 = V_158 ;
return 0 ;
}
static void F_155 ( struct V_3 * V_4 , int V_16 )
{
struct V_1 * V_2 = F_133 ( V_4 ) ;
int V_40 ;
F_150 ( V_4 , V_184 ) ;
for ( V_40 = 0 ; V_40 < V_2 -> V_162 ; V_40 ++ ) {
if ( V_4 == V_2 -> V_163 [ V_40 ] ) {
F_137 ( V_2 , V_4 ) ;
while ( ++ V_40 < V_2 -> V_162 )
V_2 -> V_163 [ V_40 - 1 ] = V_2 -> V_163 [ V_40 ] ;
-- V_2 -> V_162 ;
break;
}
}
V_4 -> V_6 . V_18 = - 1 ;
V_4 -> V_6 . V_129 = ~ 0ULL ;
}
static void F_156 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_133 ( V_4 ) ;
F_100 ( V_2 , V_4 ) ;
}
static int F_157 ( struct V_154 * V_52 ,
struct V_3 * V_4 )
{
struct V_3 * V_156 = V_4 -> V_189 ;
struct V_1 * V_190 ;
int V_104 = - V_115 , V_158 ;
V_190 = F_121 ( V_52 -> type , F_109 () ) ;
if ( ! V_190 )
return - V_191 ;
V_190 -> V_52 = V_52 ;
V_158 = F_134 ( V_190 , V_156 , true ) ;
if ( V_158 < 0 )
goto V_192;
V_190 -> V_162 = V_158 ;
V_158 = F_134 ( V_190 , V_4 , false ) ;
if ( V_158 < 0 )
goto V_192;
V_190 -> V_162 = V_158 ;
V_104 = F_138 ( V_190 , NULL , V_158 ) ;
V_192:
F_158 ( V_190 ) ;
return V_104 ;
}
static int F_159 ( struct V_3 * V_4 )
{
struct V_154 * V_52 ;
struct V_1 * V_2 ;
struct V_32 * V_33 = & V_4 -> V_6 ;
int V_104 ;
if ( V_4 -> V_54 . type != V_4 -> V_52 -> type )
return - V_193 ;
V_52 = F_132 ( V_4 ) ;
if ( V_52 -> V_194 < 0 )
return - V_193 ;
if ( V_4 -> V_54 . V_195 || V_4 -> V_54 . V_196 ||
V_4 -> V_54 . V_197 || V_4 -> V_54 . V_198 )
return - V_115 ;
if ( V_33 -> V_199 )
return - V_115 ;
if ( V_4 -> V_139 < 0 )
return - V_115 ;
V_2 = F_126 ( V_52 , V_4 -> V_139 ) ;
if ( ! V_2 || V_2 -> V_139 < 0 )
return - V_115 ;
V_4 -> V_139 = V_2 -> V_139 ;
V_4 -> V_6 . V_18 = - 1 ;
V_4 -> V_6 . V_129 = ~ 0ULL ;
V_4 -> V_6 . V_13 . V_18 = V_19 ;
V_4 -> V_6 . V_15 . V_18 = V_19 ;
if ( V_4 -> V_54 . V_25 == V_200 ) {
if ( ! V_52 -> type -> V_161 )
return - V_115 ;
if ( V_52 -> type -> V_201 && V_52 -> V_53 > 0 )
return - V_115 ;
V_33 -> V_25 = ~ 0ULL ;
} else {
V_33 -> V_25 = V_4 -> V_54 . V_25 & V_52 -> type -> V_90 ;
if ( V_52 -> type -> V_167 -> V_202 ) {
V_104 = V_52 -> type -> V_167 -> V_202 ( V_2 , V_4 ) ;
if ( V_104 )
return V_104 ;
}
}
if ( V_4 -> V_189 != V_4 )
V_104 = F_157 ( V_52 , V_4 ) ;
else
V_104 = 0 ;
return V_104 ;
}
static T_3 F_160 ( struct V_203 * V_204 ,
struct V_205 * V_54 , char * V_206 )
{
int V_158 = F_161 ( V_206 , V_207 - 2 , & V_208 ) ;
V_206 [ V_158 ++ ] = '\n' ;
V_206 [ V_158 ] = '\0' ;
return V_158 ;
}
static int T_4 F_162 ( struct V_154 * V_52 )
{
int V_104 ;
V_52 -> V_52 = (struct V_52 ) {
. V_209 = V_52 -> type -> V_209 ,
. V_210 = V_211 ,
. V_212 = F_159 ,
. V_213 = F_154 ,
. V_214 = F_155 ,
. V_215 = F_146 ,
. V_216 = F_150 ,
. V_217 = F_156 ,
} ;
if ( V_52 -> type -> V_218 == 1 ) {
if ( strlen ( V_52 -> type -> V_219 ) > 0 )
sprintf ( V_52 -> V_219 , L_1 , V_52 -> type -> V_219 ) ;
else
sprintf ( V_52 -> V_219 , L_2 ) ;
} else {
sprintf ( V_52 -> V_219 , L_3 , V_52 -> type -> V_219 ,
V_52 -> V_53 ) ;
}
V_104 = F_163 ( & V_52 -> V_52 , V_52 -> V_219 , - 1 ) ;
return V_104 ;
}
static void T_4 F_164 ( struct V_111 * type )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < type -> V_218 ; V_40 ++ )
F_165 ( type -> V_220 [ V_40 ] . V_2 ) ;
F_158 ( type -> V_220 ) ;
type -> V_220 = NULL ;
F_158 ( type -> V_221 ) ;
type -> V_221 = NULL ;
}
static void T_4 F_166 ( struct V_111 * * V_222 )
{
int V_40 ;
for ( V_40 = 0 ; V_222 [ V_40 ] ; V_40 ++ )
F_164 ( V_222 [ V_40 ] ) ;
}
static int T_4 F_167 ( struct V_111 * type )
{
struct V_154 * V_220 ;
struct V_223 * V_224 ;
struct V_225 * * V_226 ;
int V_40 , V_227 ;
V_220 = F_168 ( sizeof( * V_220 ) * type -> V_218 , V_150 ) ;
if ( ! V_220 )
return - V_191 ;
type -> V_173 = (struct V_8 )
F_169 ( 0 , ( 1ULL << type -> V_160 ) - 1 ,
0 , type -> V_160 , 0 , 0 ) ;
for ( V_40 = 0 ; V_40 < type -> V_218 ; V_40 ++ ) {
V_220 [ V_40 ] . V_194 = - 1 ;
V_220 [ V_40 ] . V_53 = V_40 ;
V_220 [ V_40 ] . type = type ;
F_170 ( & V_220 [ V_40 ] . V_228 ) ;
V_220 [ V_40 ] . V_2 = F_171 ( struct V_1 * ) ;
if ( ! V_220 [ V_40 ] . V_2 )
goto V_43;
}
if ( type -> V_229 ) {
V_40 = 0 ;
while ( type -> V_229 [ V_40 ] . V_54 . V_54 . V_219 )
V_40 ++ ;
V_224 = F_168 ( sizeof( struct V_225 * ) * ( V_40 + 1 ) +
sizeof( * V_224 ) , V_150 ) ;
if ( ! V_224 )
goto V_43;
V_226 = (struct V_225 * * ) ( V_224 + 1 ) ;
V_224 -> V_219 = L_4 ;
V_224 -> V_226 = V_226 ;
for ( V_227 = 0 ; V_227 < V_40 ; V_227 ++ )
V_226 [ V_227 ] = & type -> V_229 [ V_227 ] . V_54 . V_54 ;
type -> V_221 = V_224 ;
}
type -> V_230 = & V_231 ;
type -> V_220 = V_220 ;
return 0 ;
V_43:
F_164 ( type ) ;
return - V_191 ;
}
static int T_4 F_172 ( struct V_111 * * V_222 )
{
int V_40 , V_104 ;
for ( V_40 = 0 ; V_222 [ V_40 ] ; V_40 ++ ) {
V_104 = F_167 ( V_222 [ V_40 ] ) ;
if ( V_104 )
goto V_43;
}
return 0 ;
V_43:
while ( -- V_40 >= 0 )
F_164 ( V_222 [ V_40 ] ) ;
return V_104 ;
}
static int F_173 ( struct V_111 * type , struct V_28 * V_29 )
{
struct V_154 * V_52 ;
struct V_1 * V_2 ;
int V_40 , V_153 ;
V_153 = V_68 [ V_29 -> V_63 -> V_67 ] ;
if ( V_153 < 0 )
return - V_186 ;
V_2 = F_121 ( type , 0 ) ;
if ( ! V_2 )
return - V_191 ;
for ( V_40 = 0 ; V_40 < type -> V_218 ; V_40 ++ ) {
V_52 = & type -> V_220 [ V_40 ] ;
if ( V_52 -> V_194 == V_29 -> V_232 )
break;
if ( V_52 -> V_194 < 0 ) {
V_52 -> V_194 = V_29 -> V_232 ;
break;
}
V_52 = NULL ;
}
if ( ! V_52 ) {
F_158 ( V_2 ) ;
return - V_115 ;
}
V_2 -> V_153 = V_153 ;
V_2 -> V_28 = V_29 ;
V_2 -> V_52 = V_52 ;
F_174 ( V_2 ) ;
F_175 ( V_29 , V_2 ) ;
F_128 ( & V_155 ) ;
F_176 ( & V_2 -> V_233 , & V_52 -> V_228 ) ;
F_131 ( & V_155 ) ;
return 0 ;
}
static void F_177 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_178 ( V_29 ) ;
struct V_154 * V_52 = V_2 -> V_52 ;
int V_139 , V_153 = V_68 [ V_29 -> V_63 -> V_67 ] ;
if ( F_69 ( V_153 != V_2 -> V_153 ) )
return;
F_175 ( V_29 , NULL ) ;
F_128 ( & V_155 ) ;
F_179 ( & V_2 -> V_233 ) ;
F_131 ( & V_155 ) ;
F_180 (cpu) {
if ( * F_127 ( V_52 -> V_2 , V_139 ) == V_2 ) {
* F_127 ( V_52 -> V_2 , V_139 ) = NULL ;
F_10 ( & V_2 -> V_152 ) ;
}
}
F_69 ( F_6 ( & V_2 -> V_152 ) != 1 ) ;
F_158 ( V_2 ) ;
}
static int F_181 ( struct V_28 * V_29 ,
const struct V_234 * V_235 )
{
return F_173 ( V_236 [ V_235 -> V_237 ] , V_29 ) ;
}
static int T_4 F_182 ( void )
{
int V_104 ;
switch ( V_238 . V_239 ) {
case 45 :
V_104 = F_41 ( 0x3ce0 ) ;
if ( V_104 )
return V_104 ;
V_236 = V_240 ;
V_241 = & V_242 ;
break;
case 62 :
V_104 = F_41 ( 0x0e1e ) ;
if ( V_104 )
return V_104 ;
V_236 = V_243 ;
V_241 = & V_244 ;
break;
default:
return 0 ;
}
V_104 = F_172 ( V_236 ) ;
if ( V_104 )
return V_104 ;
V_241 -> V_245 = F_181 ;
V_241 -> remove = F_177 ;
V_104 = F_183 ( V_241 ) ;
if ( V_104 == 0 )
V_246 = true ;
else
F_166 ( V_236 ) ;
return V_104 ;
}
static void T_4 F_184 ( void )
{
if ( V_246 ) {
V_246 = false ;
F_185 ( V_241 ) ;
F_166 ( V_236 ) ;
}
}
static void T_5 F_186 ( void )
{
struct V_1 * V_2 ;
while ( ! F_187 ( & V_247 ) ) {
V_2 = F_188 ( V_247 . V_248 ,
struct V_1 , V_233 ) ;
F_179 ( & V_2 -> V_233 ) ;
F_158 ( V_2 ) ;
}
}
static void T_5 F_189 ( int V_139 )
{
struct V_111 * type ;
struct V_154 * V_52 ;
struct V_1 * V_2 ;
int V_40 , V_227 ;
for ( V_40 = 0 ; V_249 [ V_40 ] ; V_40 ++ ) {
type = V_249 [ V_40 ] ;
for ( V_227 = 0 ; V_227 < type -> V_218 ; V_227 ++ ) {
V_52 = & type -> V_220 [ V_227 ] ;
V_2 = * F_127 ( V_52 -> V_2 , V_139 ) ;
* F_127 ( V_52 -> V_2 , V_139 ) = NULL ;
if ( V_2 && F_190 ( & V_2 -> V_152 ) )
F_191 ( & V_2 -> V_233 , & V_247 ) ;
}
}
}
static int T_5 F_192 ( int V_139 )
{
struct V_111 * type ;
struct V_154 * V_52 ;
struct V_1 * V_2 , * V_250 ;
int V_40 , V_227 , V_251 , V_153 ;
V_153 = F_130 ( V_139 ) ;
for ( V_40 = 0 ; V_249 [ V_40 ] ; V_40 ++ ) {
type = V_249 [ V_40 ] ;
for ( V_227 = 0 ; V_227 < type -> V_218 ; V_227 ++ ) {
V_52 = & type -> V_220 [ V_227 ] ;
V_2 = * F_127 ( V_52 -> V_2 , V_139 ) ;
if ( V_2 && V_2 -> V_153 >= 0 ) {
F_174 ( V_2 ) ;
continue;
}
F_193 (k) {
V_250 = * F_127 ( V_52 -> V_2 , V_251 ) ;
if ( V_250 && V_250 -> V_153 == V_153 ) {
F_7 ( & V_250 -> V_152 ) ;
* F_127 ( V_52 -> V_2 , V_139 ) = V_250 ;
if ( V_2 ) {
F_191 ( & V_2 -> V_233 ,
& V_247 ) ;
V_2 = NULL ;
}
break;
}
}
if ( V_2 ) {
V_2 -> V_153 = V_153 ;
F_174 ( V_2 ) ;
}
}
}
return 0 ;
}
static int T_5 F_194 ( int V_139 , int V_153 )
{
struct V_111 * type ;
struct V_154 * V_52 ;
struct V_1 * V_2 ;
int V_40 , V_227 ;
for ( V_40 = 0 ; V_249 [ V_40 ] ; V_40 ++ ) {
type = V_249 [ V_40 ] ;
for ( V_227 = 0 ; V_227 < type -> V_218 ; V_227 ++ ) {
V_52 = & type -> V_220 [ V_227 ] ;
if ( V_52 -> V_194 < 0 )
V_52 -> V_194 = V_227 ;
V_2 = F_121 ( type , V_139 ) ;
if ( ! V_2 )
return - V_191 ;
V_2 -> V_52 = V_52 ;
V_2 -> V_153 = V_153 ;
* F_127 ( V_52 -> V_2 , V_139 ) = V_2 ;
}
}
return 0 ;
}
static void T_5
F_195 ( struct V_111 * * V_252 , int V_253 , int V_254 )
{
struct V_111 * type ;
struct V_154 * V_52 ;
struct V_1 * V_2 ;
int V_40 , V_227 ;
for ( V_40 = 0 ; V_252 [ V_40 ] ; V_40 ++ ) {
type = V_252 [ V_40 ] ;
for ( V_227 = 0 ; V_227 < type -> V_218 ; V_227 ++ ) {
V_52 = & type -> V_220 [ V_227 ] ;
if ( V_253 < 0 )
V_2 = F_126 ( V_52 , V_254 ) ;
else
V_2 = F_126 ( V_52 , V_253 ) ;
if ( ! V_2 )
continue;
if ( V_253 < 0 ) {
F_69 ( V_2 -> V_139 != - 1 ) ;
V_2 -> V_139 = V_254 ;
continue;
}
F_69 ( V_2 -> V_139 != V_253 ) ;
if ( V_254 >= 0 ) {
F_117 ( V_2 ) ;
F_196 ( & V_52 -> V_52 ,
V_253 , V_254 ) ;
V_2 -> V_139 = V_254 ;
} else {
V_2 -> V_139 = - 1 ;
}
}
}
}
static void T_5 F_197 ( int V_139 )
{
int V_40 , V_153 , V_255 ;
if ( ! F_198 ( V_139 , & V_208 ) )
return;
V_153 = F_130 ( V_139 ) ;
V_255 = - 1 ;
F_193 (i) {
if ( V_40 == V_139 )
continue;
if ( V_153 == F_130 ( V_40 ) ) {
V_255 = V_40 ;
break;
}
}
if ( V_255 >= 0 )
F_199 ( V_255 , & V_208 ) ;
F_195 ( V_249 , V_139 , V_255 ) ;
F_195 ( V_236 , V_139 , V_255 ) ;
}
static void T_5 F_200 ( int V_139 )
{
int V_40 , V_153 ;
V_153 = F_130 ( V_139 ) ;
F_201 (i, &uncore_cpu_mask) {
if ( V_153 == F_130 ( V_40 ) )
return;
}
F_199 ( V_139 , & V_208 ) ;
F_195 ( V_249 , - 1 , V_139 ) ;
F_195 ( V_236 , - 1 , V_139 ) ;
}
static int
T_5 F_202 ( struct V_256 * V_257 , unsigned long V_258 , void * V_259 )
{
unsigned int V_139 = ( long ) V_259 ;
switch ( V_258 & ~ V_260 ) {
case V_261 :
F_194 ( V_139 , - 1 ) ;
break;
case V_262 :
F_192 ( V_139 ) ;
break;
case V_263 :
case V_264 :
F_189 ( V_139 ) ;
break;
case V_265 :
case V_266 :
F_186 () ;
break;
default:
break;
}
switch ( V_258 & ~ V_260 ) {
case V_267 :
case V_262 :
F_200 ( V_139 ) ;
break;
case V_268 :
F_197 ( V_139 ) ;
break;
default:
break;
}
return V_269 ;
}
static void T_4 F_203 ( void * V_270 )
{
F_192 ( F_109 () ) ;
}
static int T_4 F_204 ( void )
{
int V_104 , V_139 , V_271 ;
V_271 = V_238 . V_272 ;
switch ( V_238 . V_239 ) {
case 26 :
case 30 :
case 37 :
case 44 :
V_249 = V_273 ;
break;
case 42 :
case 58 :
if ( V_274 . V_218 > V_271 )
V_274 . V_218 = V_271 ;
V_249 = V_275 ;
break;
case 45 :
if ( V_276 . V_218 > V_271 )
V_276 . V_218 = V_271 ;
V_249 = V_277 ;
break;
case 46 :
V_106 = true ;
case 47 :
if ( ! V_106 )
V_278 . V_229 = V_279 ;
if ( V_280 . V_218 > V_271 )
V_280 . V_218 = V_271 ;
V_249 = V_281 ;
break;
case 62 :
if ( V_282 . V_218 > V_271 )
V_282 . V_218 = V_271 ;
V_249 = V_283 ;
break;
default:
return 0 ;
}
V_104 = F_172 ( V_249 ) ;
if ( V_104 )
return V_104 ;
F_205 () ;
F_193 (cpu) {
int V_40 , V_153 = F_130 ( V_139 ) ;
F_201 (i, &uncore_cpu_mask) {
if ( V_153 == F_130 ( V_40 ) ) {
V_153 = - 1 ;
break;
}
}
if ( V_153 < 0 )
continue;
F_194 ( V_139 , V_153 ) ;
F_200 ( V_139 ) ;
}
F_206 ( F_203 , NULL , 1 ) ;
F_207 ( & V_284 ) ;
F_208 () ;
return 0 ;
}
static int T_4 F_209 ( void )
{
struct V_154 * V_52 ;
struct V_111 * type ;
int V_40 , V_227 ;
for ( V_40 = 0 ; V_249 [ V_40 ] ; V_40 ++ ) {
type = V_249 [ V_40 ] ;
for ( V_227 = 0 ; V_227 < type -> V_218 ; V_227 ++ ) {
V_52 = & type -> V_220 [ V_227 ] ;
F_162 ( V_52 ) ;
}
}
for ( V_40 = 0 ; V_236 [ V_40 ] ; V_40 ++ ) {
type = V_236 [ V_40 ] ;
for ( V_227 = 0 ; V_227 < type -> V_218 ; V_227 ++ ) {
V_52 = & type -> V_220 [ V_227 ] ;
F_162 ( V_52 ) ;
}
}
return 0 ;
}
static int T_4 F_210 ( void )
{
int V_104 ;
if ( V_238 . V_285 != V_286 )
return - V_186 ;
if ( V_287 )
return - V_186 ;
V_104 = F_182 () ;
if ( V_104 )
goto V_43;
V_104 = F_204 () ;
if ( V_104 ) {
F_184 () ;
goto V_43;
}
F_209 () ;
return 0 ;
V_43:
return V_104 ;
}

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
return NULL ;
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
V_42 = 0xffULL << ( V_18 * 8 ) ;
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
static int F_41 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
if ( ( V_33 -> V_25 & V_59 ) == 0x38 ) {
V_12 -> V_18 = 0 ;
V_12 -> V_39 = V_61 ;
V_12 -> V_25 = V_4 -> V_54 . V_24 ;
V_14 -> V_39 = V_62 ;
V_14 -> V_25 = V_4 -> V_54 . V_26 ;
}
return 0 ;
}
static void F_42 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_28 * V_29 = V_2 -> V_28 ;
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
if ( V_12 -> V_18 != V_19 ) {
int V_18 = V_2 -> V_52 -> V_53 + V_63 ;
struct V_28 * V_64 = V_65 [ V_2 -> V_66 ] [ V_18 ] ;
F_43 ( ! V_64 ) ;
if ( V_64 ) {
F_15 ( V_64 , V_12 -> V_39 ,
( T_2 ) V_12 -> V_25 ) ;
F_15 ( V_64 , V_12 -> V_39 + 4 ,
( T_2 ) ( V_12 -> V_25 >> 32 ) ) ;
F_15 ( V_64 , V_14 -> V_39 ,
( T_2 ) V_14 -> V_25 ) ;
F_15 ( V_64 , V_14 -> V_39 + 4 ,
( T_2 ) ( V_14 -> V_25 >> 32 ) ) ;
}
}
F_15 ( V_29 , V_33 -> V_34 , V_33 -> V_25 | V_35 ) ;
}
static int F_44 ( int V_67 )
{
struct V_28 * V_68 = NULL ;
int V_40 , V_69 , V_70 ;
int V_71 = 0 ;
T_2 V_25 = 0 ;
while ( 1 ) {
V_68 = F_45 ( V_72 , V_67 , V_68 ) ;
if ( ! V_68 )
break;
V_69 = V_68 -> V_69 -> V_73 ;
V_71 = F_14 ( V_68 , 0x40 , & V_25 ) ;
if ( V_71 )
break;
V_70 = V_25 ;
V_71 = F_14 ( V_68 , 0x54 , & V_25 ) ;
if ( V_71 )
break;
for ( V_40 = 0 ; V_40 < 8 ; V_40 ++ ) {
if ( V_70 == ( ( V_25 >> ( 3 * V_40 ) ) & 0x7 ) ) {
V_74 [ V_69 ] = V_40 ;
break;
}
}
}
if ( V_68 )
F_46 ( V_68 ) ;
return V_71 ? F_47 ( V_71 ) : 0 ;
}
static void F_48 ( struct V_1 * V_2 )
{
unsigned V_38 = F_22 ( V_2 ) ;
if ( V_38 )
F_23 ( V_38 , V_75 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_28 ;
F_15 ( V_29 , V_36 , V_75 ) ;
}
static T_1 F_50 ( int V_41 )
{
T_1 V_42 = 0 ;
if ( V_41 & 0x1 )
V_42 |= V_76 ;
if ( V_41 & 0x2 )
V_42 |= V_77 ;
if ( V_41 & 0x4 )
V_42 |= V_78 ;
if ( V_41 & 0x8 )
V_42 |= V_79 ;
if ( V_41 & 0x10 )
V_42 |= V_80 ;
return V_42 ;
}
static struct V_8 *
F_51 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_30 ( V_2 , V_4 , F_50 ) ;
}
static int F_52 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_13 * V_10 ;
int V_18 = 0 ;
for ( V_10 = V_81 ; V_10 -> V_38 ; V_10 ++ ) {
if ( V_10 -> V_4 != ( V_4 -> V_6 . V_25 & V_10 -> V_49 ) )
continue;
V_18 |= V_10 -> V_18 ;
}
if ( V_18 ) {
V_12 -> V_39 = V_50 +
V_51 * V_2 -> V_52 -> V_53 ;
V_12 -> V_25 = V_4 -> V_54 . V_24 & F_50 ( V_18 ) ;
V_12 -> V_18 = V_18 ;
}
return 0 ;
}
static void F_53 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
if ( V_12 -> V_18 != V_19 ) {
T_1 V_82 = F_11 ( V_2 , 0 ) ;
F_23 ( V_12 -> V_39 , V_82 & 0xffffffff ) ;
F_23 ( V_12 -> V_39 + 6 , V_82 >> 32 ) ;
}
F_23 ( V_33 -> V_34 , V_33 -> V_25 | V_35 ) ;
}
static void F_54 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 < V_83 )
F_23 ( V_33 -> V_34 , V_33 -> V_25 | V_84 ) ;
else
F_23 ( V_33 -> V_34 , V_84 ) ;
}
static void F_55 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_23 ( V_4 -> V_6 . V_34 , 0 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
if ( V_2 -> V_52 -> V_53 == 0 ) {
F_23 ( V_85 ,
V_86 | V_87 ) ;
}
}
static void F_57 ( struct V_1 * V_2 )
{
F_23 ( V_88 , 0 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
F_23 ( V_88 , V_89 | V_90 ) ;
}
static void F_59 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 < V_83 )
F_23 ( V_33 -> V_34 , V_33 -> V_25 | V_84 ) ;
else
F_23 ( V_33 -> V_34 , V_91 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
F_23 ( V_92 , V_93 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
unsigned V_38 = F_22 ( V_2 ) ;
T_1 V_25 ;
if ( V_38 ) {
F_2 ( V_38 , V_25 ) ;
V_25 &= ~ ( ( 1ULL << F_62 ( V_2 ) ) - 1 ) ;
if ( F_63 ( V_2 ) )
V_25 &= ~ V_94 ;
F_23 ( V_38 , V_25 ) ;
}
}
static void F_64 ( struct V_1 * V_2 )
{
unsigned V_38 = F_22 ( V_2 ) ;
T_1 V_25 ;
if ( V_38 ) {
F_2 ( V_38 , V_25 ) ;
V_25 |= ( 1ULL << F_62 ( V_2 ) ) - 1 ;
if ( F_63 ( V_2 ) )
V_25 |= V_94 ;
F_23 ( V_38 , V_25 ) ;
}
}
static void F_65 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_23 ( V_4 -> V_6 . V_34 , 0 ) ;
}
static void F_66 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 >= V_83 )
F_23 ( V_33 -> V_34 , V_95 ) ;
else if ( V_2 -> V_52 -> type -> V_96 & V_95 )
F_23 ( V_33 -> V_34 , V_33 -> V_25 | V_97 ) ;
else
F_23 ( V_33 -> V_34 , V_33 -> V_25 | V_95 ) ;
}
static int F_67 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
int V_98 , V_58 ;
V_98 = ( V_33 -> V_25 & V_99 ) >>
V_100 ;
V_58 = ( V_33 -> V_25 & V_101 ) >>
V_102 ;
if ( ( V_98 == 0 && V_58 > 0x3 ) || ( V_98 == 1 && V_58 > 0x6 ) ||
( V_98 == 2 && V_58 != 0x4 ) || V_98 == 3 )
return 0 ;
if ( V_2 -> V_52 -> V_53 == 0 )
V_12 -> V_39 = V_103 ;
else
V_12 -> V_39 = V_104 ;
V_12 -> V_18 = 0 ;
V_12 -> V_25 = V_4 -> V_54 . V_24 ;
V_14 -> V_25 = V_4 -> V_54 . V_26 ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
if ( V_12 -> V_18 != V_19 ) {
F_23 ( V_12 -> V_39 , V_12 -> V_25 ) ;
F_23 ( V_12 -> V_39 + 1 , V_14 -> V_25 ) ;
}
F_23 ( V_33 -> V_34 , V_95 |
( V_33 -> V_25 & V_101 ) ) ;
}
static int F_69 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
if ( ( V_33 -> V_25 & V_105 ) !=
V_106 )
return 0 ;
if ( V_2 -> V_52 -> V_53 == 0 )
V_12 -> V_39 = V_107 ;
else
V_12 -> V_39 = V_108 ;
V_12 -> V_18 = 0 ;
V_12 -> V_25 = V_4 -> V_54 . V_24 ;
V_14 -> V_25 = V_4 -> V_54 . V_26 ;
return 0 ;
}
static void F_70 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
if ( V_12 -> V_18 != V_19 ) {
F_23 ( V_12 -> V_39 , 0 ) ;
F_23 ( V_12 -> V_39 + 1 , V_12 -> V_25 ) ;
F_23 ( V_12 -> V_39 + 2 , V_14 -> V_25 ) ;
F_23 ( V_12 -> V_39 , V_109 ) ;
}
F_23 ( V_33 -> V_34 , V_33 -> V_25 | V_97 ) ;
}
static bool F_71 ( struct V_1 * V_2 , int V_18 , T_1 V_25 )
{
struct V_9 * V_10 ;
unsigned long V_16 ;
bool V_110 = false ;
T_1 V_42 ;
if ( V_18 < V_111 ) {
V_10 = & V_2 -> V_21 [ V_18 ] ;
F_5 ( & V_10 -> V_22 , V_16 ) ;
if ( ! F_6 ( & V_10 -> V_23 ) || V_10 -> V_25 == V_25 ) {
F_7 ( & V_10 -> V_23 ) ;
V_10 -> V_25 = V_25 ;
V_110 = true ;
}
F_8 ( & V_10 -> V_22 , V_16 ) ;
return V_110 ;
}
V_18 -= V_111 ;
if ( F_43 ( V_18 >= 4 ) )
return false ;
if ( V_112 )
V_42 = V_113 ;
else
V_42 = V_114 ;
V_10 = & V_2 -> V_21 [ V_111 ] ;
F_5 ( & V_10 -> V_22 , V_16 ) ;
if ( F_32 ( F_6 ( & V_10 -> V_23 ) , V_18 , 8 ) ) {
if ( V_112 )
V_42 |= F_72 ( V_18 ) ;
else
V_42 |= F_73 ( V_18 ) ;
}
if ( ! F_6 ( & V_10 -> V_23 ) || ! ( ( V_10 -> V_25 ^ V_25 ) & V_42 ) ) {
F_33 ( 1 << ( V_18 * 8 ) , & V_10 -> V_23 ) ;
if ( V_112 )
V_42 = V_113 |
F_72 ( V_18 ) ;
else
V_42 = V_114 |
F_73 ( V_18 ) ;
V_10 -> V_25 &= ~ V_42 ;
V_10 -> V_25 |= ( V_25 & V_42 ) ;
V_110 = true ;
}
F_8 ( & V_10 -> V_22 , V_16 ) ;
return V_110 ;
}
static void F_74 ( struct V_1 * V_2 , int V_18 )
{
struct V_9 * V_10 ;
if ( V_18 < V_111 ) {
V_10 = & V_2 -> V_21 [ V_18 ] ;
F_10 ( & V_10 -> V_23 ) ;
return;
}
V_18 -= V_111 ;
V_10 = & V_2 -> V_21 [ V_111 ] ;
F_29 ( 1 << ( V_18 * 8 ) , & V_10 -> V_23 ) ;
}
static T_1 F_75 ( struct V_3 * V_4 , int V_55 , bool V_56 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
T_1 V_18 , V_115 = F_32 ( V_12 -> V_18 , 0 , 8 ) ;
T_1 V_25 = V_12 -> V_25 ;
V_18 = V_115 - V_111 ;
if ( V_112 )
V_25 &= F_72 ( V_18 ) ;
else
V_25 &= F_73 ( V_18 ) ;
if ( V_55 > V_115 ) {
V_18 = V_55 - V_115 ;
V_25 <<= 3 * V_18 ;
} else {
V_18 = V_115 - V_55 ;
V_25 >>= 3 * V_18 ;
}
if ( V_112 )
V_25 |= V_113 & V_12 -> V_25 ;
else
V_25 |= V_114 & V_12 -> V_25 ;
V_25 |= V_113 & V_12 -> V_25 ;
if ( V_56 ) {
if ( V_55 > V_115 )
V_33 -> V_25 += V_18 << V_116 ;
else
V_33 -> V_25 -= V_18 << V_116 ;
V_12 -> V_25 = V_25 ;
V_12 -> V_18 = ~ 0xff | V_55 ;
}
return V_25 ;
}
static struct V_8 *
F_76 ( struct V_1 * V_2 , struct V_3 * V_4 )
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
if ( ! F_71 ( V_2 , V_18 [ V_40 ] ,
F_32 ( V_24 , V_40 , 32 ) ) )
goto V_43;
V_20 |= ( 0x1 << V_40 ) ;
}
if ( V_14 -> V_18 != V_19 &&
( F_4 ( V_2 ) || ! V_14 -> V_20 ) &&
! F_71 ( V_2 , V_14 -> V_18 , V_14 -> V_25 ) )
goto V_43;
if ( ! F_4 ( V_2 ) ) {
if ( V_18 [ 0 ] != 0xff && V_18 [ 0 ] != F_32 ( V_12 -> V_18 , 0 , 8 ) )
F_75 ( V_4 , V_18 [ 0 ] , true ) ;
V_12 -> V_20 |= V_20 ;
if ( V_14 -> V_18 != V_19 )
V_14 -> V_20 = 1 ;
}
return NULL ;
V_43:
if ( V_18 [ 0 ] != 0xff && ! ( V_20 & 0x1 ) &&
V_18 [ 0 ] >= V_111 ) {
F_77 ( F_32 ( V_12 -> V_18 , 1 , 8 ) != 0xff ) ;
V_18 [ 0 ] -= V_111 ;
V_18 [ 0 ] = ( V_18 [ 0 ] + 1 ) % 4 ;
V_18 [ 0 ] += V_111 ;
if ( V_18 [ 0 ] != F_32 ( V_12 -> V_18 , 0 , 8 ) ) {
V_24 = F_75 ( V_4 , V_18 [ 0 ] , false ) ;
goto V_57;
}
}
if ( V_20 & 0x1 )
F_74 ( V_2 , V_18 [ 0 ] ) ;
if ( V_20 & 0x2 )
F_74 ( V_2 , V_18 [ 1 ] ) ;
return & V_27 ;
}
static void F_78 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_11 * V_14 = & V_4 -> V_6 . V_15 ;
if ( F_4 ( V_2 ) )
return;
if ( V_12 -> V_20 & 0x1 )
F_74 ( V_2 , F_32 ( V_12 -> V_18 , 0 , 8 ) ) ;
if ( V_12 -> V_20 & 0x2 )
F_74 ( V_2 , F_32 ( V_12 -> V_18 , 1 , 8 ) ) ;
V_12 -> V_20 = 0 ;
if ( V_14 -> V_20 ) {
F_74 ( V_2 , V_14 -> V_18 ) ;
V_14 -> V_20 = 0 ;
}
}
static int F_79 ( struct V_13 * V_10 )
{
if ( V_10 -> V_18 < V_111 )
return V_10 -> V_18 ;
return V_10 -> V_18 + ( V_10 -> V_4 >> V_116 ) - 0xd ;
}
static int F_80 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_117 * type = V_2 -> V_52 -> type ;
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_11 * V_14 = & V_4 -> V_6 . V_15 ;
struct V_13 * V_10 ;
unsigned V_38 ;
int V_118 = 0 ;
for ( V_10 = V_119 ; V_10 -> V_38 ; V_10 ++ ) {
if ( V_10 -> V_4 != ( V_4 -> V_6 . V_25 & V_10 -> V_49 ) )
continue;
if ( V_4 -> V_54 . V_24 & ~ V_10 -> V_120 )
return - V_121 ;
V_38 = V_10 -> V_38 + type -> V_122 * V_2 -> V_52 -> V_53 ;
if ( F_43 ( V_38 >= 0xffff || V_10 -> V_18 >= 0xff ) )
return - V_121 ;
if ( V_10 -> V_18 == V_123 )
V_118 = 1 ;
else if ( F_43 ( V_118 > 0 ) )
return - V_121 ;
V_12 -> V_18 &= ~ ( 0xff << ( V_118 * 8 ) ) ;
V_12 -> V_39 &= ~ ( 0xffff << ( V_118 * 16 ) ) ;
V_12 -> V_18 |= F_79 ( V_10 ) << ( V_118 * 8 ) ;
V_12 -> V_39 |= V_38 << ( V_118 * 16 ) ;
V_12 -> V_25 = V_4 -> V_54 . V_24 ;
V_118 ++ ;
}
if ( V_118 == 2 ) {
V_14 -> V_18 = V_124 ;
if ( V_4 -> V_54 . V_26 & V_125 )
V_14 -> V_25 = V_4 -> V_54 . V_26 ;
else
V_14 -> V_25 = ~ 0ULL ;
if ( V_2 -> V_52 -> V_53 == 0 )
V_14 -> V_39 = V_126 ;
else
V_14 -> V_39 = V_127 ;
}
return 0 ;
}
static T_1 F_81 ( struct V_1 * V_2 , int V_18 )
{
struct V_9 * V_10 ;
unsigned long V_16 ;
T_1 V_25 ;
if ( V_18 < V_111 )
return V_2 -> V_21 [ V_18 ] . V_25 ;
V_10 = & V_2 -> V_21 [ V_111 ] ;
F_5 ( & V_10 -> V_22 , V_16 ) ;
V_25 = V_10 -> V_25 ;
F_8 ( & V_10 -> V_22 , V_16 ) ;
return V_25 ;
}
static void F_82 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
int V_18 ;
V_18 = F_32 ( V_12 -> V_18 , 0 , 8 ) ;
if ( V_18 != 0xff )
F_23 ( F_32 ( V_12 -> V_39 , 0 , 16 ) ,
F_81 ( V_2 , V_18 ) ) ;
V_18 = F_32 ( V_12 -> V_18 , 1 , 8 ) ;
if ( V_18 != 0xff )
F_23 ( F_32 ( V_12 -> V_39 , 1 , 16 ) ,
F_81 ( V_2 , V_18 ) ) ;
if ( V_14 -> V_18 != V_19 ) {
F_23 ( V_14 -> V_39 , 0 ) ;
if ( V_14 -> V_25 != ~ 0ULL ) {
F_23 ( V_14 -> V_39 + 1 ,
V_14 -> V_25 & V_128 ) ;
F_23 ( V_14 -> V_39 + 2 , V_129 &
( V_14 -> V_25 >> V_130 ) ) ;
F_23 ( V_14 -> V_39 , V_125 ) ;
}
}
F_23 ( V_33 -> V_34 , V_33 -> V_25 | V_95 ) ;
}
static void F_83 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
if ( V_12 -> V_18 % 2 ) {
V_12 -> V_18 -- ;
V_33 -> V_25 -= 1 << V_131 ;
} else {
V_12 -> V_18 ++ ;
V_33 -> V_25 += 1 << V_131 ;
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
F_84 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
struct V_9 * V_10 ;
unsigned long V_16 ;
int V_18 , V_132 ;
T_1 V_24 ;
bool V_17 = false ;
if ( ! F_4 ( V_2 ) && V_12 -> V_20 )
return NULL ;
V_18 = V_12 -> V_18 % 6 ;
V_24 = V_12 -> V_25 ;
V_57:
V_132 = V_18 ;
if ( V_132 > 2 )
V_132 -- ;
V_132 += ( V_12 -> V_18 / 6 ) * 5 ;
V_10 = & V_2 -> V_21 [ V_132 ] ;
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
F_83 ( V_2 , V_4 ) ;
V_12 -> V_20 = 1 ;
}
return NULL ;
}
return & V_27 ;
}
static void F_85 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
int V_18 , V_132 ;
if ( F_4 ( V_2 ) || ! V_12 -> V_20 )
return;
V_18 = V_12 -> V_18 % 6 ;
V_132 = V_18 ;
if ( V_132 > 2 )
V_132 -- ;
V_132 += ( V_12 -> V_18 / 6 ) * 5 ;
V_10 = & V_2 -> V_21 [ V_132 ] ;
if ( V_18 == 2 || V_18 == 3 )
F_29 ( 1 << ( ( V_18 - 2 ) * 8 ) , & V_10 -> V_23 ) ;
else
F_10 ( & V_10 -> V_23 ) ;
V_12 -> V_20 = 0 ;
}
static int F_86 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_11 * V_14 = & V_4 -> V_6 . V_15 ;
int V_18 ;
V_18 = ( V_4 -> V_6 . V_25 & V_133 ) >>
V_131 ;
if ( V_18 >= 0x18 )
return - V_121 ;
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
static void F_87 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
int V_18 , V_134 ;
V_18 = V_12 -> V_18 ;
V_134 = V_18 / 6 + V_2 -> V_52 -> V_53 * 4 ;
switch ( V_18 % 6 ) {
case 0 :
F_23 ( F_88 ( V_134 ) , V_12 -> V_25 ) ;
break;
case 1 :
F_23 ( F_89 ( V_134 ) , V_12 -> V_25 ) ;
break;
case 2 :
case 3 :
F_23 ( F_90 ( V_134 ) ,
F_11 ( V_2 , 2 + ( V_18 / 6 ) * 5 ) ) ;
break;
case 4 :
F_23 ( F_91 ( V_134 ) ,
V_33 -> V_25 >> 32 ) ;
F_23 ( F_92 ( V_134 ) , V_12 -> V_25 ) ;
F_23 ( F_93 ( V_134 ) , V_14 -> V_25 ) ;
break;
case 5 :
F_23 ( F_94 ( V_134 ) ,
V_33 -> V_25 >> 32 ) ;
F_23 ( F_95 ( V_134 ) , V_12 -> V_25 ) ;
F_23 ( F_96 ( V_134 ) , V_14 -> V_25 ) ;
break;
} ;
F_23 ( V_33 -> V_34 , V_95 |
( V_33 -> V_25 & V_133 ) ) ;
}
static void F_97 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_18 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
V_33 -> V_18 = V_18 ;
V_33 -> V_135 = ++ V_2 -> V_136 [ V_18 ] ;
if ( V_33 -> V_18 == V_83 ) {
V_33 -> V_7 = F_98 ( V_2 ) ;
V_33 -> V_34 = F_99 ( V_2 ) ;
return;
}
V_33 -> V_34 = F_100 ( V_2 , V_33 -> V_18 ) ;
V_33 -> V_7 = F_101 ( V_2 , V_33 -> V_18 ) ;
}
static void F_102 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_137 , V_138 , V_139 ;
int V_140 ;
if ( V_4 -> V_6 . V_18 >= V_83 )
V_140 = 64 - F_103 ( V_2 ) ;
else
V_140 = 64 - F_104 ( V_2 ) ;
V_57:
V_137 = F_105 ( & V_4 -> V_6 . V_137 ) ;
V_138 = F_106 ( V_2 , V_4 ) ;
if ( F_107 ( & V_4 -> V_6 . V_137 , V_138 ) != V_137 )
goto V_57;
V_139 = ( V_138 << V_140 ) - ( V_137 << V_140 ) ;
V_139 >>= V_140 ;
F_108 ( V_139 , & V_4 -> V_5 ) ;
}
static enum V_141 F_109 ( struct V_142 * V_142 )
{
struct V_1 * V_2 ;
unsigned long V_16 ;
int V_143 ;
V_2 = F_110 ( V_142 , struct V_1 , V_142 ) ;
if ( ! V_2 -> V_144 || V_2 -> V_145 != F_111 () )
return V_146 ;
F_112 ( V_16 ) ;
F_113 (bit, box->active_mask, UNCORE_PMC_IDX_MAX)
F_102 ( V_2 , V_2 -> V_147 [ V_143 ] ) ;
F_114 ( V_16 ) ;
F_115 ( V_142 , F_116 ( V_148 ) ) ;
return V_149 ;
}
static void F_117 ( struct V_1 * V_2 )
{
F_118 ( & V_2 -> V_142 ,
F_116 ( V_148 ) , 0 ,
V_150 , 0 ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
F_120 ( & V_2 -> V_142 ) ;
}
static void F_121 ( struct V_1 * V_2 )
{
F_122 ( & V_2 -> V_142 , V_151 , V_152 ) ;
V_2 -> V_142 . V_153 = F_109 ;
}
static struct V_1 * F_123 ( struct V_117 * type , int V_154 )
{
struct V_1 * V_2 ;
int V_40 , V_155 ;
V_155 = sizeof( * V_2 ) + type -> V_156 * sizeof( struct V_9 ) ;
V_2 = F_124 ( V_155 , V_157 , V_154 ) ;
if ( ! V_2 )
return NULL ;
for ( V_40 = 0 ; V_40 < type -> V_156 ; V_40 ++ )
F_125 ( & V_2 -> V_21 [ V_40 ] . V_22 ) ;
F_121 ( V_2 ) ;
F_126 ( & V_2 -> V_158 , 1 ) ;
V_2 -> V_145 = - 1 ;
V_2 -> V_66 = - 1 ;
return V_2 ;
}
static struct V_1 *
F_127 ( struct V_159 * V_52 , int V_145 )
{
struct V_1 * V_2 ;
V_2 = * F_128 ( V_52 -> V_2 , V_145 ) ;
if ( V_2 )
return V_2 ;
F_129 ( & V_160 ) ;
F_130 (box, &pmu->box_list, list) {
if ( V_2 -> V_66 == F_131 ( V_145 ) ) {
F_7 ( & V_2 -> V_158 ) ;
* F_128 ( V_52 -> V_2 , V_145 ) = V_2 ;
break;
}
}
F_132 ( & V_160 ) ;
return * F_128 ( V_52 -> V_2 , V_145 ) ;
}
static struct V_159 * F_133 ( struct V_3 * V_4 )
{
return F_110 ( V_4 -> V_52 , struct V_159 , V_52 ) ;
}
static struct V_1 * F_134 ( struct V_3 * V_4 )
{
return F_127 ( F_133 ( V_4 ) , F_111 () ) ;
}
static int
F_135 ( struct V_1 * V_2 , struct V_3 * V_161 , bool V_162 )
{
struct V_3 * V_4 ;
int V_163 , V_164 ;
V_164 = V_2 -> V_52 -> type -> V_165 ;
if ( V_2 -> V_52 -> type -> V_166 )
V_164 ++ ;
if ( V_2 -> V_167 >= V_164 )
return - V_121 ;
V_163 = V_2 -> V_167 ;
V_2 -> V_168 [ V_163 ] = V_161 ;
V_163 ++ ;
if ( ! V_162 )
return V_163 ;
F_130 (event, &leader->sibling_list, group_entry) {
if ( V_4 -> V_169 <= V_170 )
continue;
if ( V_163 >= V_164 )
return - V_121 ;
V_2 -> V_168 [ V_163 ] = V_4 ;
V_163 ++ ;
}
return V_163 ;
}
static struct V_8 *
F_136 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_117 * type = V_2 -> V_52 -> type ;
struct V_8 * V_171 ;
if ( type -> V_172 -> V_173 ) {
V_171 = type -> V_172 -> V_173 ( V_2 , V_4 ) ;
if ( V_171 )
return V_171 ;
}
if ( V_4 -> V_54 . V_25 == V_174 )
return & V_175 ;
if ( type -> V_176 ) {
F_137 (c, type->constraints) {
if ( ( V_4 -> V_6 . V_25 & V_171 -> V_177 ) == V_171 -> V_178 )
return V_171 ;
}
}
return & type -> V_179 ;
}
static void F_138 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_52 -> type -> V_172 -> V_180 )
V_2 -> V_52 -> type -> V_172 -> V_180 ( V_2 , V_4 ) ;
}
static int F_139 ( struct V_1 * V_2 , int V_181 [] , int V_163 )
{
unsigned long V_182 [ F_140 ( V_183 ) ] ;
struct V_8 * V_171 ;
int V_40 , V_184 , V_185 , V_110 = 0 ;
struct V_32 * V_33 ;
F_141 ( V_182 , V_183 ) ;
for ( V_40 = 0 , V_184 = V_183 , V_185 = 0 ; V_40 < V_163 ; V_40 ++ ) {
V_33 = & V_2 -> V_168 [ V_40 ] -> V_6 ;
V_171 = F_136 ( V_2 , V_2 -> V_168 [ V_40 ] ) ;
V_33 -> V_186 = V_171 ;
V_184 = F_142 ( V_184 , V_171 -> V_187 ) ;
V_185 = F_143 ( V_185 , V_171 -> V_187 ) ;
}
for ( V_40 = 0 ; V_40 < V_163 ; V_40 ++ ) {
V_33 = & V_2 -> V_168 [ V_40 ] -> V_6 ;
V_171 = V_33 -> V_186 ;
if ( V_33 -> V_18 == - 1 )
break;
if ( ! F_144 ( V_33 -> V_18 , V_171 -> V_188 ) )
break;
if ( F_144 ( V_33 -> V_18 , V_182 ) )
break;
F_145 ( V_33 -> V_18 , V_182 ) ;
if ( V_181 )
V_181 [ V_40 ] = V_33 -> V_18 ;
}
if ( V_40 != V_163 )
V_110 = F_146 ( V_2 -> V_168 , V_163 ,
V_184 , V_185 , V_181 ) ;
if ( ! V_181 || V_110 ) {
for ( V_40 = 0 ; V_40 < V_163 ; V_40 ++ )
F_138 ( V_2 , V_2 -> V_168 [ V_40 ] ) ;
}
return V_110 ? - V_121 : 0 ;
}
static void F_147 ( struct V_3 * V_4 , int V_16 )
{
struct V_1 * V_2 = F_134 ( V_4 ) ;
int V_18 = V_4 -> V_6 . V_18 ;
if ( F_43 ( ! ( V_4 -> V_6 . V_169 & V_189 ) ) )
return;
if ( F_43 ( V_18 == - 1 || V_18 >= V_183 ) )
return;
V_4 -> V_6 . V_169 = 0 ;
V_2 -> V_147 [ V_18 ] = V_4 ;
V_2 -> V_144 ++ ;
F_145 ( V_18 , V_2 -> V_190 ) ;
F_148 ( & V_4 -> V_6 . V_137 , F_106 ( V_2 , V_4 ) ) ;
F_149 ( V_2 , V_4 ) ;
if ( V_2 -> V_144 == 1 ) {
F_150 ( V_2 ) ;
F_117 ( V_2 ) ;
}
}
static void F_151 ( struct V_3 * V_4 , int V_16 )
{
struct V_1 * V_2 = F_134 ( V_4 ) ;
struct V_32 * V_33 = & V_4 -> V_6 ;
if ( F_152 ( V_33 -> V_18 , V_2 -> V_190 ) ) {
F_153 ( V_2 , V_4 ) ;
V_2 -> V_144 -- ;
V_2 -> V_147 [ V_33 -> V_18 ] = NULL ;
F_43 ( V_33 -> V_169 & V_189 ) ;
V_33 -> V_169 |= V_189 ;
if ( V_2 -> V_144 == 0 ) {
F_154 ( V_2 ) ;
F_119 ( V_2 ) ;
}
}
if ( ( V_16 & V_191 ) && ! ( V_33 -> V_169 & V_192 ) ) {
F_102 ( V_2 , V_4 ) ;
V_33 -> V_169 |= V_192 ;
}
}
static int F_155 ( struct V_3 * V_4 , int V_16 )
{
struct V_1 * V_2 = F_134 ( V_4 ) ;
struct V_32 * V_33 = & V_4 -> V_6 ;
int V_181 [ V_183 ] ;
int V_40 , V_163 , V_110 ;
if ( ! V_2 )
return - V_193 ;
V_110 = V_163 = F_135 ( V_2 , V_4 , false ) ;
if ( V_110 < 0 )
return V_110 ;
V_33 -> V_169 = V_192 | V_189 ;
if ( ! ( V_16 & V_194 ) )
V_33 -> V_169 |= V_195 ;
V_110 = F_139 ( V_2 , V_181 , V_163 ) ;
if ( V_110 )
return V_110 ;
for ( V_40 = 0 ; V_40 < V_2 -> V_167 ; V_40 ++ ) {
V_4 = V_2 -> V_168 [ V_40 ] ;
V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 == V_181 [ V_40 ] &&
V_33 -> V_135 == V_2 -> V_136 [ V_181 [ V_40 ] ] )
continue;
if ( V_33 -> V_169 & V_189 )
V_33 -> V_169 |= V_195 ;
F_151 ( V_4 , V_191 ) ;
}
for ( V_40 = 0 ; V_40 < V_163 ; V_40 ++ ) {
V_4 = V_2 -> V_168 [ V_40 ] ;
V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 != V_181 [ V_40 ] ||
V_33 -> V_135 != V_2 -> V_136 [ V_181 [ V_40 ] ] )
F_97 ( V_2 , V_4 , V_181 [ V_40 ] ) ;
else if ( V_40 < V_2 -> V_167 )
continue;
if ( V_33 -> V_169 & V_195 )
continue;
F_147 ( V_4 , 0 ) ;
}
V_2 -> V_167 = V_163 ;
return 0 ;
}
static void F_156 ( struct V_3 * V_4 , int V_16 )
{
struct V_1 * V_2 = F_134 ( V_4 ) ;
int V_40 ;
F_151 ( V_4 , V_191 ) ;
for ( V_40 = 0 ; V_40 < V_2 -> V_167 ; V_40 ++ ) {
if ( V_4 == V_2 -> V_168 [ V_40 ] ) {
F_138 ( V_2 , V_4 ) ;
while ( ++ V_40 < V_2 -> V_167 )
V_2 -> V_168 [ V_40 - 1 ] = V_2 -> V_168 [ V_40 ] ;
-- V_2 -> V_167 ;
break;
}
}
V_4 -> V_6 . V_18 = - 1 ;
V_4 -> V_6 . V_135 = ~ 0ULL ;
}
static void F_157 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_134 ( V_4 ) ;
F_102 ( V_2 , V_4 ) ;
}
static int F_158 ( struct V_159 * V_52 ,
struct V_3 * V_4 )
{
struct V_3 * V_161 = V_4 -> V_196 ;
struct V_1 * V_197 ;
int V_110 = - V_121 , V_163 ;
V_197 = F_123 ( V_52 -> type , V_198 ) ;
if ( ! V_197 )
return - V_199 ;
V_197 -> V_52 = V_52 ;
V_163 = F_135 ( V_197 , V_161 , true ) ;
if ( V_163 < 0 )
goto V_200;
V_197 -> V_167 = V_163 ;
V_163 = F_135 ( V_197 , V_4 , false ) ;
if ( V_163 < 0 )
goto V_200;
V_197 -> V_167 = V_163 ;
V_110 = F_139 ( V_197 , NULL , V_163 ) ;
V_200:
F_159 ( V_197 ) ;
return V_110 ;
}
static int F_160 ( struct V_3 * V_4 )
{
struct V_159 * V_52 ;
struct V_1 * V_2 ;
struct V_32 * V_33 = & V_4 -> V_6 ;
int V_110 ;
if ( V_4 -> V_54 . type != V_4 -> V_52 -> type )
return - V_201 ;
V_52 = F_133 ( V_4 ) ;
if ( V_52 -> V_202 < 0 )
return - V_201 ;
if ( V_4 -> V_54 . V_203 || V_4 -> V_54 . V_204 ||
V_4 -> V_54 . V_205 || V_4 -> V_54 . V_206 )
return - V_121 ;
if ( V_33 -> V_207 )
return - V_121 ;
if ( V_4 -> V_145 < 0 )
return - V_121 ;
V_2 = F_127 ( V_52 , V_4 -> V_145 ) ;
if ( ! V_2 || V_2 -> V_145 < 0 )
return - V_121 ;
V_4 -> V_145 = V_2 -> V_145 ;
V_4 -> V_6 . V_18 = - 1 ;
V_4 -> V_6 . V_135 = ~ 0ULL ;
V_4 -> V_6 . V_13 . V_18 = V_19 ;
V_4 -> V_6 . V_15 . V_18 = V_19 ;
if ( V_4 -> V_54 . V_25 == V_174 ) {
if ( ! V_52 -> type -> V_166 )
return - V_121 ;
if ( V_52 -> type -> V_208 && V_52 -> V_53 > 0 )
return - V_121 ;
V_33 -> V_25 = 0ULL ;
} else {
V_33 -> V_25 = V_4 -> V_54 . V_25 & V_52 -> type -> V_96 ;
if ( V_52 -> type -> V_172 -> V_209 ) {
V_110 = V_52 -> type -> V_172 -> V_209 ( V_2 , V_4 ) ;
if ( V_110 )
return V_110 ;
}
}
if ( V_4 -> V_196 != V_4 )
V_110 = F_158 ( V_52 , V_4 ) ;
else
V_110 = 0 ;
return V_110 ;
}
static T_3 F_161 ( struct V_210 * V_211 ,
struct V_212 * V_54 , char * V_213 )
{
int V_163 = F_162 ( V_213 , V_214 - 2 , & V_215 ) ;
V_213 [ V_163 ++ ] = '\n' ;
V_213 [ V_163 ] = '\0' ;
return V_163 ;
}
static int T_4 F_163 ( struct V_159 * V_52 )
{
int V_110 ;
V_52 -> V_52 = (struct V_52 ) {
. V_216 = V_52 -> type -> V_216 ,
. V_217 = V_218 ,
. V_219 = F_160 ,
. V_220 = F_155 ,
. V_221 = F_156 ,
. V_222 = F_147 ,
. V_223 = F_151 ,
. V_224 = F_157 ,
} ;
if ( V_52 -> type -> V_225 == 1 ) {
if ( strlen ( V_52 -> type -> V_226 ) > 0 )
sprintf ( V_52 -> V_226 , L_1 , V_52 -> type -> V_226 ) ;
else
sprintf ( V_52 -> V_226 , L_2 ) ;
} else {
sprintf ( V_52 -> V_226 , L_3 , V_52 -> type -> V_226 ,
V_52 -> V_53 ) ;
}
V_110 = F_164 ( & V_52 -> V_52 , V_52 -> V_226 , - 1 ) ;
return V_110 ;
}
static void T_4 F_165 ( struct V_117 * type )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < type -> V_225 ; V_40 ++ )
F_166 ( type -> V_227 [ V_40 ] . V_2 ) ;
F_159 ( type -> V_227 ) ;
type -> V_227 = NULL ;
F_159 ( type -> V_228 ) ;
type -> V_228 = NULL ;
}
static void T_4 F_167 ( struct V_117 * * V_229 )
{
int V_40 ;
for ( V_40 = 0 ; V_229 [ V_40 ] ; V_40 ++ )
F_165 ( V_229 [ V_40 ] ) ;
}
static int T_4 F_168 ( struct V_117 * type )
{
struct V_159 * V_227 ;
struct V_230 * V_231 ;
struct V_232 * * V_233 ;
int V_40 , V_234 ;
V_227 = F_169 ( sizeof( * V_227 ) * type -> V_225 , V_157 ) ;
if ( ! V_227 )
return - V_199 ;
type -> V_179 = (struct V_8 )
F_170 ( 0 , ( 1ULL << type -> V_165 ) - 1 ,
0 , type -> V_165 , 0 , 0 ) ;
for ( V_40 = 0 ; V_40 < type -> V_225 ; V_40 ++ ) {
V_227 [ V_40 ] . V_202 = - 1 ;
V_227 [ V_40 ] . V_53 = V_40 ;
V_227 [ V_40 ] . type = type ;
F_171 ( & V_227 [ V_40 ] . V_235 ) ;
V_227 [ V_40 ] . V_2 = F_172 ( struct V_1 * ) ;
if ( ! V_227 [ V_40 ] . V_2 )
goto V_43;
}
if ( type -> V_236 ) {
V_40 = 0 ;
while ( type -> V_236 [ V_40 ] . V_54 . V_54 . V_226 )
V_40 ++ ;
V_231 = F_169 ( sizeof( struct V_232 * ) * ( V_40 + 1 ) +
sizeof( * V_231 ) , V_157 ) ;
if ( ! V_231 )
goto V_43;
V_233 = (struct V_232 * * ) ( V_231 + 1 ) ;
V_231 -> V_226 = L_4 ;
V_231 -> V_233 = V_233 ;
for ( V_234 = 0 ; V_234 < V_40 ; V_234 ++ )
V_233 [ V_234 ] = & type -> V_236 [ V_234 ] . V_54 . V_54 ;
type -> V_228 = V_231 ;
}
type -> V_237 = & V_238 ;
type -> V_227 = V_227 ;
return 0 ;
V_43:
F_165 ( type ) ;
return - V_199 ;
}
static int T_4 F_173 ( struct V_117 * * V_229 )
{
int V_40 , V_110 ;
for ( V_40 = 0 ; V_229 [ V_40 ] ; V_40 ++ ) {
V_110 = F_168 ( V_229 [ V_40 ] ) ;
if ( V_110 )
goto V_43;
}
return 0 ;
V_43:
while ( -- V_40 >= 0 )
F_165 ( V_229 [ V_40 ] ) ;
return V_110 ;
}
static int F_174 ( struct V_28 * V_29 , const struct V_239 * V_240 )
{
struct V_159 * V_52 ;
struct V_1 * V_2 ;
struct V_117 * type ;
int V_66 ;
V_66 = V_74 [ V_29 -> V_69 -> V_73 ] ;
if ( V_66 < 0 )
return - V_193 ;
if ( F_175 ( V_240 -> V_241 ) == V_242 ) {
V_65 [ V_66 ] [ F_176 ( V_240 -> V_241 ) ] = V_29 ;
F_177 ( V_29 , NULL ) ;
return 0 ;
}
type = V_243 [ F_175 ( V_240 -> V_241 ) ] ;
V_2 = F_123 ( type , V_198 ) ;
if ( ! V_2 )
return - V_199 ;
V_52 = & type -> V_227 [ F_176 ( V_240 -> V_241 ) ] ;
if ( V_52 -> V_202 < 0 )
V_52 -> V_202 = V_29 -> V_244 ;
else
F_43 ( V_52 -> V_202 != V_29 -> V_244 ) ;
V_2 -> V_66 = V_66 ;
V_2 -> V_28 = V_29 ;
V_2 -> V_52 = V_52 ;
F_178 ( V_2 ) ;
F_177 ( V_29 , V_2 ) ;
F_129 ( & V_160 ) ;
F_179 ( & V_2 -> V_245 , & V_52 -> V_235 ) ;
F_132 ( & V_160 ) ;
return 0 ;
}
static void F_180 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_181 ( V_29 ) ;
struct V_159 * V_52 ;
int V_40 , V_145 , V_66 = V_74 [ V_29 -> V_69 -> V_73 ] ;
V_2 = F_181 ( V_29 ) ;
if ( ! V_2 ) {
for ( V_40 = 0 ; V_40 < V_246 ; V_40 ++ ) {
if ( V_65 [ V_66 ] [ V_40 ] == V_29 ) {
V_65 [ V_66 ] [ V_40 ] = NULL ;
break;
}
}
F_43 ( V_40 >= V_246 ) ;
return;
}
V_52 = V_2 -> V_52 ;
if ( F_43 ( V_66 != V_2 -> V_66 ) )
return;
F_177 ( V_29 , NULL ) ;
F_129 ( & V_160 ) ;
F_182 ( & V_2 -> V_245 ) ;
F_132 ( & V_160 ) ;
F_183 (cpu) {
if ( * F_128 ( V_52 -> V_2 , V_145 ) == V_2 ) {
* F_128 ( V_52 -> V_2 , V_145 ) = NULL ;
F_10 ( & V_2 -> V_158 ) ;
}
}
F_43 ( F_6 ( & V_2 -> V_158 ) != 1 ) ;
F_159 ( V_2 ) ;
}
static int T_4 F_184 ( void )
{
int V_110 ;
switch ( V_247 . V_248 ) {
case 45 :
V_110 = F_44 ( 0x3ce0 ) ;
if ( V_110 )
return V_110 ;
V_243 = V_249 ;
V_250 = & V_251 ;
break;
case 62 :
V_110 = F_44 ( 0x0e1e ) ;
if ( V_110 )
return V_110 ;
V_243 = V_252 ;
V_250 = & V_253 ;
break;
default:
return 0 ;
}
V_110 = F_173 ( V_243 ) ;
if ( V_110 )
return V_110 ;
V_250 -> V_254 = F_174 ;
V_250 -> remove = F_180 ;
V_110 = F_185 ( V_250 ) ;
if ( V_110 == 0 )
V_255 = true ;
else
F_167 ( V_243 ) ;
return V_110 ;
}
static void T_4 F_186 ( void )
{
if ( V_255 ) {
V_255 = false ;
F_187 ( V_250 ) ;
F_167 ( V_243 ) ;
}
}
static void F_188 ( void )
{
struct V_1 * V_2 ;
while ( ! F_189 ( & V_256 ) ) {
V_2 = F_190 ( V_256 . V_257 ,
struct V_1 , V_245 ) ;
F_182 ( & V_2 -> V_245 ) ;
F_159 ( V_2 ) ;
}
}
static void F_191 ( int V_145 )
{
struct V_117 * type ;
struct V_159 * V_52 ;
struct V_1 * V_2 ;
int V_40 , V_234 ;
for ( V_40 = 0 ; V_258 [ V_40 ] ; V_40 ++ ) {
type = V_258 [ V_40 ] ;
for ( V_234 = 0 ; V_234 < type -> V_225 ; V_234 ++ ) {
V_52 = & type -> V_227 [ V_234 ] ;
V_2 = * F_128 ( V_52 -> V_2 , V_145 ) ;
* F_128 ( V_52 -> V_2 , V_145 ) = NULL ;
if ( V_2 && F_192 ( & V_2 -> V_158 ) )
F_193 ( & V_2 -> V_245 , & V_256 ) ;
}
}
}
static int F_194 ( int V_145 )
{
struct V_117 * type ;
struct V_159 * V_52 ;
struct V_1 * V_2 , * V_259 ;
int V_40 , V_234 , V_260 , V_66 ;
V_66 = F_131 ( V_145 ) ;
for ( V_40 = 0 ; V_258 [ V_40 ] ; V_40 ++ ) {
type = V_258 [ V_40 ] ;
for ( V_234 = 0 ; V_234 < type -> V_225 ; V_234 ++ ) {
V_52 = & type -> V_227 [ V_234 ] ;
V_2 = * F_128 ( V_52 -> V_2 , V_145 ) ;
if ( V_2 && V_2 -> V_66 >= 0 ) {
F_178 ( V_2 ) ;
continue;
}
F_195 (k) {
V_259 = * F_128 ( V_52 -> V_2 , V_260 ) ;
if ( V_259 && V_259 -> V_66 == V_66 ) {
F_7 ( & V_259 -> V_158 ) ;
* F_128 ( V_52 -> V_2 , V_145 ) = V_259 ;
if ( V_2 ) {
F_193 ( & V_2 -> V_245 ,
& V_256 ) ;
V_2 = NULL ;
}
break;
}
}
if ( V_2 ) {
V_2 -> V_66 = V_66 ;
F_178 ( V_2 ) ;
}
}
}
return 0 ;
}
static int F_196 ( int V_145 , int V_66 )
{
struct V_117 * type ;
struct V_159 * V_52 ;
struct V_1 * V_2 ;
int V_40 , V_234 ;
for ( V_40 = 0 ; V_258 [ V_40 ] ; V_40 ++ ) {
type = V_258 [ V_40 ] ;
for ( V_234 = 0 ; V_234 < type -> V_225 ; V_234 ++ ) {
V_52 = & type -> V_227 [ V_234 ] ;
if ( V_52 -> V_202 < 0 )
V_52 -> V_202 = V_234 ;
V_2 = F_123 ( type , F_197 ( V_145 ) ) ;
if ( ! V_2 )
return - V_199 ;
V_2 -> V_52 = V_52 ;
V_2 -> V_66 = V_66 ;
* F_128 ( V_52 -> V_2 , V_145 ) = V_2 ;
}
}
return 0 ;
}
static void
F_198 ( struct V_117 * * V_261 , int V_262 , int V_263 )
{
struct V_117 * type ;
struct V_159 * V_52 ;
struct V_1 * V_2 ;
int V_40 , V_234 ;
for ( V_40 = 0 ; V_261 [ V_40 ] ; V_40 ++ ) {
type = V_261 [ V_40 ] ;
for ( V_234 = 0 ; V_234 < type -> V_225 ; V_234 ++ ) {
V_52 = & type -> V_227 [ V_234 ] ;
if ( V_262 < 0 )
V_2 = F_127 ( V_52 , V_263 ) ;
else
V_2 = F_127 ( V_52 , V_262 ) ;
if ( ! V_2 )
continue;
if ( V_262 < 0 ) {
F_43 ( V_2 -> V_145 != - 1 ) ;
V_2 -> V_145 = V_263 ;
continue;
}
F_43 ( V_2 -> V_145 != V_262 ) ;
if ( V_263 >= 0 ) {
F_119 ( V_2 ) ;
F_199 ( & V_52 -> V_52 ,
V_262 , V_263 ) ;
V_2 -> V_145 = V_263 ;
} else {
V_2 -> V_145 = - 1 ;
}
}
}
}
static void F_200 ( int V_145 )
{
int V_40 , V_66 , V_264 ;
if ( ! F_201 ( V_145 , & V_215 ) )
return;
V_66 = F_131 ( V_145 ) ;
V_264 = - 1 ;
F_195 (i) {
if ( V_40 == V_145 )
continue;
if ( V_66 == F_131 ( V_40 ) ) {
V_264 = V_40 ;
break;
}
}
if ( V_264 >= 0 )
F_202 ( V_264 , & V_215 ) ;
F_198 ( V_258 , V_145 , V_264 ) ;
F_198 ( V_243 , V_145 , V_264 ) ;
}
static void F_203 ( int V_145 )
{
int V_40 , V_66 ;
V_66 = F_131 ( V_145 ) ;
F_204 (i, &uncore_cpu_mask) {
if ( V_66 == F_131 ( V_40 ) )
return;
}
F_202 ( V_145 , & V_215 ) ;
F_198 ( V_258 , - 1 , V_145 ) ;
F_198 ( V_243 , - 1 , V_145 ) ;
}
static int F_205 ( struct V_265 * V_266 ,
unsigned long V_267 , void * V_268 )
{
unsigned int V_145 = ( long ) V_268 ;
switch ( V_267 & ~ V_269 ) {
case V_270 :
F_196 ( V_145 , - 1 ) ;
break;
case V_271 :
F_194 ( V_145 ) ;
break;
case V_272 :
case V_273 :
F_191 ( V_145 ) ;
break;
case V_274 :
case V_275 :
F_188 () ;
break;
default:
break;
}
switch ( V_267 & ~ V_269 ) {
case V_276 :
case V_271 :
F_203 ( V_145 ) ;
break;
case V_277 :
F_200 ( V_145 ) ;
break;
default:
break;
}
return V_278 ;
}
static void T_4 F_206 ( void * V_279 )
{
F_194 ( F_111 () ) ;
}
static int T_4 F_207 ( void )
{
int V_110 , V_145 , V_280 ;
V_280 = V_247 . V_281 ;
switch ( V_247 . V_248 ) {
case 26 :
case 30 :
case 37 :
case 44 :
V_258 = V_282 ;
break;
case 42 :
case 58 :
if ( V_283 . V_225 > V_280 )
V_283 . V_225 = V_280 ;
V_258 = V_284 ;
break;
case 45 :
if ( V_285 . V_225 > V_280 )
V_285 . V_225 = V_280 ;
V_258 = V_286 ;
break;
case 46 :
V_112 = true ;
case 47 :
if ( ! V_112 )
V_287 . V_236 = V_288 ;
if ( V_289 . V_225 > V_280 )
V_289 . V_225 = V_280 ;
V_258 = V_290 ;
break;
case 62 :
if ( V_291 . V_225 > V_280 )
V_291 . V_225 = V_280 ;
V_258 = V_292 ;
break;
default:
return 0 ;
}
V_110 = F_173 ( V_258 ) ;
if ( V_110 )
return V_110 ;
F_208 () ;
F_195 (cpu) {
int V_40 , V_66 = F_131 ( V_145 ) ;
F_204 (i, &uncore_cpu_mask) {
if ( V_66 == F_131 ( V_40 ) ) {
V_66 = - 1 ;
break;
}
}
if ( V_66 < 0 )
continue;
F_196 ( V_145 , V_66 ) ;
F_203 ( V_145 ) ;
}
F_209 ( F_206 , NULL , 1 ) ;
F_210 ( & V_293 ) ;
F_211 () ;
return 0 ;
}
static int T_4 F_212 ( void )
{
struct V_159 * V_52 ;
struct V_117 * type ;
int V_40 , V_234 ;
for ( V_40 = 0 ; V_258 [ V_40 ] ; V_40 ++ ) {
type = V_258 [ V_40 ] ;
for ( V_234 = 0 ; V_234 < type -> V_225 ; V_234 ++ ) {
V_52 = & type -> V_227 [ V_234 ] ;
F_163 ( V_52 ) ;
}
}
for ( V_40 = 0 ; V_243 [ V_40 ] ; V_40 ++ ) {
type = V_243 [ V_40 ] ;
for ( V_234 = 0 ; V_234 < type -> V_225 ; V_234 ++ ) {
V_52 = & type -> V_227 [ V_234 ] ;
F_163 ( V_52 ) ;
}
}
return 0 ;
}
static int T_4 F_213 ( void )
{
int V_110 ;
if ( V_247 . V_294 != V_295 )
return - V_193 ;
if ( V_296 )
return - V_193 ;
V_110 = F_184 () ;
if ( V_110 )
goto V_43;
V_110 = F_207 () ;
if ( V_110 ) {
F_186 () ;
goto V_43;
}
F_212 () ;
return 0 ;
V_43:
return V_110 ;
}

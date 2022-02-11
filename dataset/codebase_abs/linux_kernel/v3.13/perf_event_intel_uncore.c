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
if ( ! V_71 ) {
V_40 = - 1 ;
for ( V_69 = 255 ; V_69 >= 0 ; V_69 -- ) {
if ( V_74 [ V_69 ] >= 0 )
V_40 = V_74 [ V_69 ] ;
else
V_74 [ V_69 ] = V_40 ;
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
struct V_28 * V_29 = V_2 -> V_28 ;
struct V_32 * V_33 = & V_4 -> V_6 ;
F_15 ( V_29 , V_83 [ V_33 -> V_18 ] ,
V_33 -> V_25 | V_35 ) ;
}
static void F_55 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_28 * V_29 = V_2 -> V_28 ;
struct V_32 * V_33 = & V_4 -> V_6 ;
F_15 ( V_29 , V_83 [ V_33 -> V_18 ] , V_33 -> V_25 ) ;
}
static T_1 F_56 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_28 * V_29 = V_2 -> V_28 ;
struct V_32 * V_33 = & V_4 -> V_6 ;
T_1 V_5 = 0 ;
F_14 ( V_29 , V_84 [ V_33 -> V_18 ] , ( T_2 * ) & V_5 ) ;
F_14 ( V_29 , V_84 [ V_33 -> V_18 ] + 4 , ( T_2 * ) & V_5 + 1 ) ;
return V_5 ;
}
static void F_57 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 < V_85 )
F_23 ( V_33 -> V_34 , V_33 -> V_25 | V_86 ) ;
else
F_23 ( V_33 -> V_34 , V_86 ) ;
}
static void F_58 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_23 ( V_4 -> V_6 . V_34 , 0 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_52 -> V_53 == 0 ) {
F_23 ( V_87 ,
V_88 | V_89 ) ;
}
}
static void F_60 ( struct V_1 * V_2 )
{
F_23 ( V_90 , 0 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
F_23 ( V_90 , V_91 | V_92 ) ;
}
static void F_62 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 < V_85 )
F_23 ( V_33 -> V_34 , V_33 -> V_25 | V_86 ) ;
else
F_23 ( V_33 -> V_34 , V_93 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_23 ( V_94 , V_95 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
unsigned V_38 = F_22 ( V_2 ) ;
T_1 V_25 ;
if ( V_38 ) {
F_2 ( V_38 , V_25 ) ;
V_25 &= ~ ( ( 1ULL << F_65 ( V_2 ) ) - 1 ) ;
if ( F_66 ( V_2 ) )
V_25 &= ~ V_96 ;
F_23 ( V_38 , V_25 ) ;
}
}
static void F_67 ( struct V_1 * V_2 )
{
unsigned V_38 = F_22 ( V_2 ) ;
T_1 V_25 ;
if ( V_38 ) {
F_2 ( V_38 , V_25 ) ;
V_25 |= ( 1ULL << F_65 ( V_2 ) ) - 1 ;
if ( F_66 ( V_2 ) )
V_25 |= V_96 ;
F_23 ( V_38 , V_25 ) ;
}
}
static void F_68 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_23 ( V_4 -> V_6 . V_34 , 0 ) ;
}
static void F_69 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 >= V_85 )
F_23 ( V_33 -> V_34 , V_97 ) ;
else if ( V_2 -> V_52 -> type -> V_98 & V_97 )
F_23 ( V_33 -> V_34 , V_33 -> V_25 | V_99 ) ;
else
F_23 ( V_33 -> V_34 , V_33 -> V_25 | V_97 ) ;
}
static int F_70 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
int V_100 , V_58 ;
V_100 = ( V_33 -> V_25 & V_101 ) >>
V_102 ;
V_58 = ( V_33 -> V_25 & V_103 ) >>
V_104 ;
if ( ( V_100 == 0 && V_58 > 0x3 ) || ( V_100 == 1 && V_58 > 0x6 ) ||
( V_100 == 2 && V_58 != 0x4 ) || V_100 == 3 )
return 0 ;
if ( V_2 -> V_52 -> V_53 == 0 )
V_12 -> V_39 = V_105 ;
else
V_12 -> V_39 = V_106 ;
V_12 -> V_18 = 0 ;
V_12 -> V_25 = V_4 -> V_54 . V_24 ;
V_14 -> V_25 = V_4 -> V_54 . V_26 ;
return 0 ;
}
static void F_71 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
if ( V_12 -> V_18 != V_19 ) {
F_23 ( V_12 -> V_39 , V_12 -> V_25 ) ;
F_23 ( V_12 -> V_39 + 1 , V_14 -> V_25 ) ;
}
F_23 ( V_33 -> V_34 , V_97 |
( V_33 -> V_25 & V_103 ) ) ;
}
static int F_72 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
if ( ( V_33 -> V_25 & V_107 ) !=
V_108 )
return 0 ;
if ( V_2 -> V_52 -> V_53 == 0 )
V_12 -> V_39 = V_109 ;
else
V_12 -> V_39 = V_110 ;
V_12 -> V_18 = 0 ;
V_12 -> V_25 = V_4 -> V_54 . V_24 ;
V_14 -> V_25 = V_4 -> V_54 . V_26 ;
return 0 ;
}
static void F_73 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
if ( V_12 -> V_18 != V_19 ) {
F_23 ( V_12 -> V_39 , 0 ) ;
F_23 ( V_12 -> V_39 + 1 , V_12 -> V_25 ) ;
F_23 ( V_12 -> V_39 + 2 , V_14 -> V_25 ) ;
F_23 ( V_12 -> V_39 , V_111 ) ;
}
F_23 ( V_33 -> V_34 , V_33 -> V_25 | V_99 ) ;
}
static bool F_74 ( struct V_1 * V_2 , int V_18 , T_1 V_25 )
{
struct V_9 * V_10 ;
unsigned long V_16 ;
bool V_112 = false ;
T_1 V_42 ;
if ( V_18 < V_113 ) {
V_10 = & V_2 -> V_21 [ V_18 ] ;
F_5 ( & V_10 -> V_22 , V_16 ) ;
if ( ! F_6 ( & V_10 -> V_23 ) || V_10 -> V_25 == V_25 ) {
F_7 ( & V_10 -> V_23 ) ;
V_10 -> V_25 = V_25 ;
V_112 = true ;
}
F_8 ( & V_10 -> V_22 , V_16 ) ;
return V_112 ;
}
V_18 -= V_113 ;
if ( F_43 ( V_18 >= 4 ) )
return false ;
if ( V_114 )
V_42 = V_115 ;
else
V_42 = V_116 ;
V_10 = & V_2 -> V_21 [ V_113 ] ;
F_5 ( & V_10 -> V_22 , V_16 ) ;
if ( F_32 ( F_6 ( & V_10 -> V_23 ) , V_18 , 8 ) ) {
if ( V_114 )
V_42 |= F_75 ( V_18 ) ;
else
V_42 |= F_76 ( V_18 ) ;
}
if ( ! F_6 ( & V_10 -> V_23 ) || ! ( ( V_10 -> V_25 ^ V_25 ) & V_42 ) ) {
F_33 ( 1 << ( V_18 * 8 ) , & V_10 -> V_23 ) ;
if ( V_114 )
V_42 = V_115 |
F_75 ( V_18 ) ;
else
V_42 = V_116 |
F_76 ( V_18 ) ;
V_10 -> V_25 &= ~ V_42 ;
V_10 -> V_25 |= ( V_25 & V_42 ) ;
V_112 = true ;
}
F_8 ( & V_10 -> V_22 , V_16 ) ;
return V_112 ;
}
static void F_77 ( struct V_1 * V_2 , int V_18 )
{
struct V_9 * V_10 ;
if ( V_18 < V_113 ) {
V_10 = & V_2 -> V_21 [ V_18 ] ;
F_10 ( & V_10 -> V_23 ) ;
return;
}
V_18 -= V_113 ;
V_10 = & V_2 -> V_21 [ V_113 ] ;
F_29 ( 1 << ( V_18 * 8 ) , & V_10 -> V_23 ) ;
}
static T_1 F_78 ( struct V_3 * V_4 , int V_55 , bool V_56 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
T_1 V_18 , V_117 = F_32 ( V_12 -> V_18 , 0 , 8 ) ;
T_1 V_25 = V_12 -> V_25 ;
V_18 = V_117 - V_113 ;
if ( V_114 )
V_25 &= F_75 ( V_18 ) ;
else
V_25 &= F_76 ( V_18 ) ;
if ( V_55 > V_117 ) {
V_18 = V_55 - V_117 ;
V_25 <<= 3 * V_18 ;
} else {
V_18 = V_117 - V_55 ;
V_25 >>= 3 * V_18 ;
}
if ( V_114 )
V_25 |= V_115 & V_12 -> V_25 ;
else
V_25 |= V_116 & V_12 -> V_25 ;
V_25 |= V_115 & V_12 -> V_25 ;
if ( V_56 ) {
if ( V_55 > V_117 )
V_33 -> V_25 += V_18 << V_118 ;
else
V_33 -> V_25 -= V_18 << V_118 ;
V_12 -> V_25 = V_25 ;
V_12 -> V_18 = ~ 0xff | V_55 ;
}
return V_25 ;
}
static struct V_8 *
F_79 ( struct V_1 * V_2 , struct V_3 * V_4 )
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
if ( ! F_74 ( V_2 , V_18 [ V_40 ] ,
F_32 ( V_24 , V_40 , 32 ) ) )
goto V_43;
V_20 |= ( 0x1 << V_40 ) ;
}
if ( V_14 -> V_18 != V_19 &&
( F_4 ( V_2 ) || ! V_14 -> V_20 ) &&
! F_74 ( V_2 , V_14 -> V_18 , V_14 -> V_25 ) )
goto V_43;
if ( ! F_4 ( V_2 ) ) {
if ( V_18 [ 0 ] != 0xff && V_18 [ 0 ] != F_32 ( V_12 -> V_18 , 0 , 8 ) )
F_78 ( V_4 , V_18 [ 0 ] , true ) ;
V_12 -> V_20 |= V_20 ;
if ( V_14 -> V_18 != V_19 )
V_14 -> V_20 = 1 ;
}
return NULL ;
V_43:
if ( V_18 [ 0 ] != 0xff && ! ( V_20 & 0x1 ) &&
V_18 [ 0 ] >= V_113 ) {
F_80 ( F_32 ( V_12 -> V_18 , 1 , 8 ) != 0xff ) ;
V_18 [ 0 ] -= V_113 ;
V_18 [ 0 ] = ( V_18 [ 0 ] + 1 ) % 4 ;
V_18 [ 0 ] += V_113 ;
if ( V_18 [ 0 ] != F_32 ( V_12 -> V_18 , 0 , 8 ) ) {
V_24 = F_78 ( V_4 , V_18 [ 0 ] , false ) ;
goto V_57;
}
}
if ( V_20 & 0x1 )
F_77 ( V_2 , V_18 [ 0 ] ) ;
if ( V_20 & 0x2 )
F_77 ( V_2 , V_18 [ 1 ] ) ;
return & V_27 ;
}
static void F_81 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_11 * V_14 = & V_4 -> V_6 . V_15 ;
if ( F_4 ( V_2 ) )
return;
if ( V_12 -> V_20 & 0x1 )
F_77 ( V_2 , F_32 ( V_12 -> V_18 , 0 , 8 ) ) ;
if ( V_12 -> V_20 & 0x2 )
F_77 ( V_2 , F_32 ( V_12 -> V_18 , 1 , 8 ) ) ;
V_12 -> V_20 = 0 ;
if ( V_14 -> V_20 ) {
F_77 ( V_2 , V_14 -> V_18 ) ;
V_14 -> V_20 = 0 ;
}
}
static int F_82 ( struct V_13 * V_10 )
{
if ( V_10 -> V_18 < V_113 )
return V_10 -> V_18 ;
return V_10 -> V_18 + ( V_10 -> V_4 >> V_118 ) - 0xd ;
}
static int F_83 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_119 * type = V_2 -> V_52 -> type ;
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_11 * V_14 = & V_4 -> V_6 . V_15 ;
struct V_13 * V_10 ;
unsigned V_38 ;
int V_120 = 0 ;
for ( V_10 = V_121 ; V_10 -> V_38 ; V_10 ++ ) {
if ( V_10 -> V_4 != ( V_4 -> V_6 . V_25 & V_10 -> V_49 ) )
continue;
if ( V_4 -> V_54 . V_24 & ~ V_10 -> V_122 )
return - V_123 ;
V_38 = V_10 -> V_38 + type -> V_124 * V_2 -> V_52 -> V_53 ;
if ( F_43 ( V_38 >= 0xffff || V_10 -> V_18 >= 0xff ) )
return - V_123 ;
if ( V_10 -> V_18 == V_125 )
V_120 = 1 ;
else if ( F_43 ( V_120 > 0 ) )
return - V_123 ;
V_12 -> V_18 &= ~ ( 0xff << ( V_120 * 8 ) ) ;
V_12 -> V_39 &= ~ ( 0xffff << ( V_120 * 16 ) ) ;
V_12 -> V_18 |= F_82 ( V_10 ) << ( V_120 * 8 ) ;
V_12 -> V_39 |= V_38 << ( V_120 * 16 ) ;
V_12 -> V_25 = V_4 -> V_54 . V_24 ;
V_120 ++ ;
}
if ( V_120 == 2 ) {
V_14 -> V_18 = V_126 ;
if ( V_4 -> V_54 . V_26 & V_127 )
V_14 -> V_25 = V_4 -> V_54 . V_26 ;
else
V_14 -> V_25 = ~ 0ULL ;
if ( V_2 -> V_52 -> V_53 == 0 )
V_14 -> V_39 = V_128 ;
else
V_14 -> V_39 = V_129 ;
}
return 0 ;
}
static T_1 F_84 ( struct V_1 * V_2 , int V_18 )
{
struct V_9 * V_10 ;
unsigned long V_16 ;
T_1 V_25 ;
if ( V_18 < V_113 )
return V_2 -> V_21 [ V_18 ] . V_25 ;
V_10 = & V_2 -> V_21 [ V_113 ] ;
F_5 ( & V_10 -> V_22 , V_16 ) ;
V_25 = V_10 -> V_25 ;
F_8 ( & V_10 -> V_22 , V_16 ) ;
return V_25 ;
}
static void F_85 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
int V_18 ;
V_18 = F_32 ( V_12 -> V_18 , 0 , 8 ) ;
if ( V_18 != 0xff )
F_23 ( F_32 ( V_12 -> V_39 , 0 , 16 ) ,
F_84 ( V_2 , V_18 ) ) ;
V_18 = F_32 ( V_12 -> V_18 , 1 , 8 ) ;
if ( V_18 != 0xff )
F_23 ( F_32 ( V_12 -> V_39 , 1 , 16 ) ,
F_84 ( V_2 , V_18 ) ) ;
if ( V_14 -> V_18 != V_19 ) {
F_23 ( V_14 -> V_39 , 0 ) ;
if ( V_14 -> V_25 != ~ 0ULL ) {
F_23 ( V_14 -> V_39 + 1 ,
V_14 -> V_25 & V_130 ) ;
F_23 ( V_14 -> V_39 + 2 , V_131 &
( V_14 -> V_25 >> V_132 ) ) ;
F_23 ( V_14 -> V_39 , V_127 ) ;
}
}
F_23 ( V_33 -> V_34 , V_33 -> V_25 | V_97 ) ;
}
static void F_86 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
if ( V_12 -> V_18 % 2 ) {
V_12 -> V_18 -- ;
V_33 -> V_25 -= 1 << V_133 ;
} else {
V_12 -> V_18 ++ ;
V_33 -> V_25 += 1 << V_133 ;
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
F_87 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
struct V_9 * V_10 ;
unsigned long V_16 ;
int V_18 , V_134 ;
T_1 V_24 ;
bool V_17 = false ;
if ( ! F_4 ( V_2 ) && V_12 -> V_20 )
return NULL ;
V_18 = V_12 -> V_18 % 6 ;
V_24 = V_12 -> V_25 ;
V_57:
V_134 = V_18 ;
if ( V_134 > 2 )
V_134 -- ;
V_134 += ( V_12 -> V_18 / 6 ) * 5 ;
V_10 = & V_2 -> V_21 [ V_134 ] ;
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
F_86 ( V_2 , V_4 ) ;
V_12 -> V_20 = 1 ;
}
return NULL ;
}
return & V_27 ;
}
static void F_88 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
int V_18 , V_134 ;
if ( F_4 ( V_2 ) || ! V_12 -> V_20 )
return;
V_18 = V_12 -> V_18 % 6 ;
V_134 = V_18 ;
if ( V_134 > 2 )
V_134 -- ;
V_134 += ( V_12 -> V_18 / 6 ) * 5 ;
V_10 = & V_2 -> V_21 [ V_134 ] ;
if ( V_18 == 2 || V_18 == 3 )
F_29 ( 1 << ( ( V_18 - 2 ) * 8 ) , & V_10 -> V_23 ) ;
else
F_10 ( & V_10 -> V_23 ) ;
V_12 -> V_20 = 0 ;
}
static int F_89 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_11 * V_14 = & V_4 -> V_6 . V_15 ;
int V_18 ;
V_18 = ( V_4 -> V_6 . V_25 & V_135 ) >>
V_133 ;
if ( V_18 >= 0x18 )
return - V_123 ;
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
static void F_90 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
int V_18 , V_136 ;
V_18 = V_12 -> V_18 ;
V_136 = V_18 / 6 + V_2 -> V_52 -> V_53 * 4 ;
switch ( V_18 % 6 ) {
case 0 :
F_23 ( F_91 ( V_136 ) , V_12 -> V_25 ) ;
break;
case 1 :
F_23 ( F_92 ( V_136 ) , V_12 -> V_25 ) ;
break;
case 2 :
case 3 :
F_23 ( F_93 ( V_136 ) ,
F_11 ( V_2 , 2 + ( V_18 / 6 ) * 5 ) ) ;
break;
case 4 :
F_23 ( F_94 ( V_136 ) ,
V_33 -> V_25 >> 32 ) ;
F_23 ( F_95 ( V_136 ) , V_12 -> V_25 ) ;
F_23 ( F_96 ( V_136 ) , V_14 -> V_25 ) ;
break;
case 5 :
F_23 ( F_97 ( V_136 ) ,
V_33 -> V_25 >> 32 ) ;
F_23 ( F_98 ( V_136 ) , V_12 -> V_25 ) ;
F_23 ( F_99 ( V_136 ) , V_14 -> V_25 ) ;
break;
} ;
F_23 ( V_33 -> V_34 , V_97 |
( V_33 -> V_25 & V_135 ) ) ;
}
static void F_100 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_18 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
V_33 -> V_18 = V_18 ;
V_33 -> V_137 = ++ V_2 -> V_138 [ V_18 ] ;
if ( V_33 -> V_18 == V_85 ) {
V_33 -> V_7 = F_101 ( V_2 ) ;
V_33 -> V_34 = F_102 ( V_2 ) ;
return;
}
V_33 -> V_34 = F_103 ( V_2 , V_33 -> V_18 ) ;
V_33 -> V_7 = F_104 ( V_2 , V_33 -> V_18 ) ;
}
static void F_105 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_139 , V_140 , V_141 ;
int V_142 ;
if ( V_4 -> V_6 . V_18 >= V_85 )
V_142 = 64 - F_106 ( V_2 ) ;
else
V_142 = 64 - F_107 ( V_2 ) ;
V_57:
V_139 = F_108 ( & V_4 -> V_6 . V_139 ) ;
V_140 = F_109 ( V_2 , V_4 ) ;
if ( F_110 ( & V_4 -> V_6 . V_139 , V_140 ) != V_139 )
goto V_57;
V_141 = ( V_140 << V_142 ) - ( V_139 << V_142 ) ;
V_141 >>= V_142 ;
F_111 ( V_141 , & V_4 -> V_5 ) ;
}
static enum V_143 F_112 ( struct V_144 * V_144 )
{
struct V_1 * V_2 ;
unsigned long V_16 ;
int V_145 ;
V_2 = F_113 ( V_144 , struct V_1 , V_144 ) ;
if ( ! V_2 -> V_146 || V_2 -> V_147 != F_114 () )
return V_148 ;
F_115 ( V_16 ) ;
F_116 (bit, box->active_mask, UNCORE_PMC_IDX_MAX)
F_105 ( V_2 , V_2 -> V_149 [ V_145 ] ) ;
F_117 ( V_16 ) ;
F_118 ( V_144 , F_119 ( V_150 ) ) ;
return V_151 ;
}
static void F_120 ( struct V_1 * V_2 )
{
F_121 ( & V_2 -> V_144 ,
F_119 ( V_150 ) , 0 ,
V_152 , 0 ) ;
}
static void F_122 ( struct V_1 * V_2 )
{
F_123 ( & V_2 -> V_144 ) ;
}
static void F_124 ( struct V_1 * V_2 )
{
F_125 ( & V_2 -> V_144 , V_153 , V_154 ) ;
V_2 -> V_144 . V_155 = F_112 ;
}
static struct V_1 * F_126 ( struct V_119 * type , int V_156 )
{
struct V_1 * V_2 ;
int V_40 , V_157 ;
V_157 = sizeof( * V_2 ) + type -> V_158 * sizeof( struct V_9 ) ;
V_2 = F_127 ( V_157 , V_159 , V_156 ) ;
if ( ! V_2 )
return NULL ;
for ( V_40 = 0 ; V_40 < type -> V_158 ; V_40 ++ )
F_128 ( & V_2 -> V_21 [ V_40 ] . V_22 ) ;
F_124 ( V_2 ) ;
F_129 ( & V_2 -> V_160 , 1 ) ;
V_2 -> V_147 = - 1 ;
V_2 -> V_66 = - 1 ;
return V_2 ;
}
static struct V_1 *
F_130 ( struct V_161 * V_52 , int V_147 )
{
struct V_1 * V_2 ;
V_2 = * F_131 ( V_52 -> V_2 , V_147 ) ;
if ( V_2 )
return V_2 ;
F_132 ( & V_162 ) ;
F_133 (box, &pmu->box_list, list) {
if ( V_2 -> V_66 == F_134 ( V_147 ) ) {
F_7 ( & V_2 -> V_160 ) ;
* F_131 ( V_52 -> V_2 , V_147 ) = V_2 ;
break;
}
}
F_135 ( & V_162 ) ;
return * F_131 ( V_52 -> V_2 , V_147 ) ;
}
static struct V_161 * F_136 ( struct V_3 * V_4 )
{
return F_113 ( V_4 -> V_52 , struct V_161 , V_52 ) ;
}
static struct V_1 * F_137 ( struct V_3 * V_4 )
{
return F_130 ( F_136 ( V_4 ) , F_114 () ) ;
}
static int
F_138 ( struct V_1 * V_2 , struct V_3 * V_163 , bool V_164 )
{
struct V_3 * V_4 ;
int V_165 , V_166 ;
V_166 = V_2 -> V_52 -> type -> V_167 ;
if ( V_2 -> V_52 -> type -> V_168 )
V_166 ++ ;
if ( V_2 -> V_169 >= V_166 )
return - V_123 ;
V_165 = V_2 -> V_169 ;
V_2 -> V_170 [ V_165 ] = V_163 ;
V_165 ++ ;
if ( ! V_164 )
return V_165 ;
F_133 (event, &leader->sibling_list, group_entry) {
if ( V_4 -> V_171 <= V_172 )
continue;
if ( V_165 >= V_166 )
return - V_123 ;
V_2 -> V_170 [ V_165 ] = V_4 ;
V_165 ++ ;
}
return V_165 ;
}
static struct V_8 *
F_139 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_119 * type = V_2 -> V_52 -> type ;
struct V_8 * V_173 ;
if ( type -> V_174 -> V_175 ) {
V_173 = type -> V_174 -> V_175 ( V_2 , V_4 ) ;
if ( V_173 )
return V_173 ;
}
if ( V_4 -> V_54 . V_25 == V_176 )
return & V_177 ;
if ( type -> V_178 ) {
F_140 (c, type->constraints) {
if ( ( V_4 -> V_6 . V_25 & V_173 -> V_179 ) == V_173 -> V_180 )
return V_173 ;
}
}
return & type -> V_181 ;
}
static void F_141 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_52 -> type -> V_174 -> V_182 )
V_2 -> V_52 -> type -> V_174 -> V_182 ( V_2 , V_4 ) ;
}
static int F_142 ( struct V_1 * V_2 , int V_183 [] , int V_165 )
{
unsigned long V_184 [ F_143 ( V_185 ) ] ;
struct V_8 * V_173 ;
int V_40 , V_186 , V_187 , V_112 = 0 ;
struct V_32 * V_33 ;
F_144 ( V_184 , V_185 ) ;
for ( V_40 = 0 , V_186 = V_185 , V_187 = 0 ; V_40 < V_165 ; V_40 ++ ) {
V_33 = & V_2 -> V_170 [ V_40 ] -> V_6 ;
V_173 = F_139 ( V_2 , V_2 -> V_170 [ V_40 ] ) ;
V_33 -> V_188 = V_173 ;
V_186 = F_145 ( V_186 , V_173 -> V_189 ) ;
V_187 = F_146 ( V_187 , V_173 -> V_189 ) ;
}
for ( V_40 = 0 ; V_40 < V_165 ; V_40 ++ ) {
V_33 = & V_2 -> V_170 [ V_40 ] -> V_6 ;
V_173 = V_33 -> V_188 ;
if ( V_33 -> V_18 == - 1 )
break;
if ( ! F_147 ( V_33 -> V_18 , V_173 -> V_190 ) )
break;
if ( F_147 ( V_33 -> V_18 , V_184 ) )
break;
F_148 ( V_33 -> V_18 , V_184 ) ;
if ( V_183 )
V_183 [ V_40 ] = V_33 -> V_18 ;
}
if ( V_40 != V_165 )
V_112 = F_149 ( V_2 -> V_170 , V_165 ,
V_186 , V_187 , V_183 ) ;
if ( ! V_183 || V_112 ) {
for ( V_40 = 0 ; V_40 < V_165 ; V_40 ++ )
F_141 ( V_2 , V_2 -> V_170 [ V_40 ] ) ;
}
return V_112 ? - V_123 : 0 ;
}
static void F_150 ( struct V_3 * V_4 , int V_16 )
{
struct V_1 * V_2 = F_137 ( V_4 ) ;
int V_18 = V_4 -> V_6 . V_18 ;
if ( F_43 ( ! ( V_4 -> V_6 . V_171 & V_191 ) ) )
return;
if ( F_43 ( V_18 == - 1 || V_18 >= V_185 ) )
return;
V_4 -> V_6 . V_171 = 0 ;
V_2 -> V_149 [ V_18 ] = V_4 ;
V_2 -> V_146 ++ ;
F_148 ( V_18 , V_2 -> V_192 ) ;
F_151 ( & V_4 -> V_6 . V_139 , F_109 ( V_2 , V_4 ) ) ;
F_152 ( V_2 , V_4 ) ;
if ( V_2 -> V_146 == 1 ) {
F_153 ( V_2 ) ;
F_120 ( V_2 ) ;
}
}
static void F_154 ( struct V_3 * V_4 , int V_16 )
{
struct V_1 * V_2 = F_137 ( V_4 ) ;
struct V_32 * V_33 = & V_4 -> V_6 ;
if ( F_155 ( V_33 -> V_18 , V_2 -> V_192 ) ) {
F_156 ( V_2 , V_4 ) ;
V_2 -> V_146 -- ;
V_2 -> V_149 [ V_33 -> V_18 ] = NULL ;
F_43 ( V_33 -> V_171 & V_191 ) ;
V_33 -> V_171 |= V_191 ;
if ( V_2 -> V_146 == 0 ) {
F_157 ( V_2 ) ;
F_122 ( V_2 ) ;
}
}
if ( ( V_16 & V_193 ) && ! ( V_33 -> V_171 & V_194 ) ) {
F_105 ( V_2 , V_4 ) ;
V_33 -> V_171 |= V_194 ;
}
}
static int F_158 ( struct V_3 * V_4 , int V_16 )
{
struct V_1 * V_2 = F_137 ( V_4 ) ;
struct V_32 * V_33 = & V_4 -> V_6 ;
int V_183 [ V_185 ] ;
int V_40 , V_165 , V_112 ;
if ( ! V_2 )
return - V_195 ;
V_112 = V_165 = F_138 ( V_2 , V_4 , false ) ;
if ( V_112 < 0 )
return V_112 ;
V_33 -> V_171 = V_194 | V_191 ;
if ( ! ( V_16 & V_196 ) )
V_33 -> V_171 |= V_197 ;
V_112 = F_142 ( V_2 , V_183 , V_165 ) ;
if ( V_112 )
return V_112 ;
for ( V_40 = 0 ; V_40 < V_2 -> V_169 ; V_40 ++ ) {
V_4 = V_2 -> V_170 [ V_40 ] ;
V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 == V_183 [ V_40 ] &&
V_33 -> V_137 == V_2 -> V_138 [ V_183 [ V_40 ] ] )
continue;
if ( V_33 -> V_171 & V_191 )
V_33 -> V_171 |= V_197 ;
F_154 ( V_4 , V_193 ) ;
}
for ( V_40 = 0 ; V_40 < V_165 ; V_40 ++ ) {
V_4 = V_2 -> V_170 [ V_40 ] ;
V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 != V_183 [ V_40 ] ||
V_33 -> V_137 != V_2 -> V_138 [ V_183 [ V_40 ] ] )
F_100 ( V_2 , V_4 , V_183 [ V_40 ] ) ;
else if ( V_40 < V_2 -> V_169 )
continue;
if ( V_33 -> V_171 & V_197 )
continue;
F_150 ( V_4 , 0 ) ;
}
V_2 -> V_169 = V_165 ;
return 0 ;
}
static void F_159 ( struct V_3 * V_4 , int V_16 )
{
struct V_1 * V_2 = F_137 ( V_4 ) ;
int V_40 ;
F_154 ( V_4 , V_193 ) ;
for ( V_40 = 0 ; V_40 < V_2 -> V_169 ; V_40 ++ ) {
if ( V_4 == V_2 -> V_170 [ V_40 ] ) {
F_141 ( V_2 , V_4 ) ;
while ( ++ V_40 < V_2 -> V_169 )
V_2 -> V_170 [ V_40 - 1 ] = V_2 -> V_170 [ V_40 ] ;
-- V_2 -> V_169 ;
break;
}
}
V_4 -> V_6 . V_18 = - 1 ;
V_4 -> V_6 . V_137 = ~ 0ULL ;
}
static void F_160 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_137 ( V_4 ) ;
F_105 ( V_2 , V_4 ) ;
}
static int F_161 ( struct V_161 * V_52 ,
struct V_3 * V_4 )
{
struct V_3 * V_163 = V_4 -> V_198 ;
struct V_1 * V_199 ;
int V_112 = - V_123 , V_165 ;
V_199 = F_126 ( V_52 -> type , V_200 ) ;
if ( ! V_199 )
return - V_201 ;
V_199 -> V_52 = V_52 ;
V_165 = F_138 ( V_199 , V_163 , true ) ;
if ( V_165 < 0 )
goto V_202;
V_199 -> V_169 = V_165 ;
V_165 = F_138 ( V_199 , V_4 , false ) ;
if ( V_165 < 0 )
goto V_202;
V_199 -> V_169 = V_165 ;
V_112 = F_142 ( V_199 , NULL , V_165 ) ;
V_202:
F_162 ( V_199 ) ;
return V_112 ;
}
static int F_163 ( struct V_3 * V_4 )
{
struct V_161 * V_52 ;
struct V_1 * V_2 ;
struct V_32 * V_33 = & V_4 -> V_6 ;
int V_112 ;
if ( V_4 -> V_54 . type != V_4 -> V_52 -> type )
return - V_203 ;
V_52 = F_136 ( V_4 ) ;
if ( V_52 -> V_204 < 0 )
return - V_203 ;
if ( V_4 -> V_54 . V_205 || V_4 -> V_54 . V_206 ||
V_4 -> V_54 . V_207 || V_4 -> V_54 . V_208 )
return - V_123 ;
if ( V_33 -> V_209 )
return - V_123 ;
if ( V_4 -> V_147 < 0 )
return - V_123 ;
V_2 = F_130 ( V_52 , V_4 -> V_147 ) ;
if ( ! V_2 || V_2 -> V_147 < 0 )
return - V_123 ;
V_4 -> V_147 = V_2 -> V_147 ;
V_4 -> V_6 . V_18 = - 1 ;
V_4 -> V_6 . V_137 = ~ 0ULL ;
V_4 -> V_6 . V_13 . V_18 = V_19 ;
V_4 -> V_6 . V_15 . V_18 = V_19 ;
if ( V_4 -> V_54 . V_25 == V_176 ) {
if ( ! V_52 -> type -> V_168 )
return - V_123 ;
if ( V_52 -> type -> V_210 && V_52 -> V_53 > 0 )
return - V_123 ;
V_33 -> V_25 = 0ULL ;
} else {
V_33 -> V_25 = V_4 -> V_54 . V_25 & V_52 -> type -> V_98 ;
if ( V_52 -> type -> V_174 -> V_211 ) {
V_112 = V_52 -> type -> V_174 -> V_211 ( V_2 , V_4 ) ;
if ( V_112 )
return V_112 ;
}
}
if ( V_4 -> V_198 != V_4 )
V_112 = F_161 ( V_52 , V_4 ) ;
else
V_112 = 0 ;
return V_112 ;
}
static T_3 F_164 ( struct V_212 * V_213 ,
struct V_214 * V_54 , char * V_215 )
{
int V_165 = F_165 ( V_215 , V_216 - 2 , & V_217 ) ;
V_215 [ V_165 ++ ] = '\n' ;
V_215 [ V_165 ] = '\0' ;
return V_165 ;
}
static int T_4 F_166 ( struct V_161 * V_52 )
{
int V_112 ;
V_52 -> V_52 = (struct V_52 ) {
. V_218 = V_52 -> type -> V_218 ,
. V_219 = V_220 ,
. V_221 = F_163 ,
. V_222 = F_158 ,
. V_223 = F_159 ,
. V_224 = F_150 ,
. V_225 = F_154 ,
. V_226 = F_160 ,
} ;
if ( V_52 -> type -> V_227 == 1 ) {
if ( strlen ( V_52 -> type -> V_228 ) > 0 )
sprintf ( V_52 -> V_228 , L_1 , V_52 -> type -> V_228 ) ;
else
sprintf ( V_52 -> V_228 , L_2 ) ;
} else {
sprintf ( V_52 -> V_228 , L_3 , V_52 -> type -> V_228 ,
V_52 -> V_53 ) ;
}
V_112 = F_167 ( & V_52 -> V_52 , V_52 -> V_228 , - 1 ) ;
return V_112 ;
}
static void T_4 F_168 ( struct V_119 * type )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < type -> V_227 ; V_40 ++ )
F_169 ( type -> V_229 [ V_40 ] . V_2 ) ;
F_162 ( type -> V_229 ) ;
type -> V_229 = NULL ;
F_162 ( type -> V_230 ) ;
type -> V_230 = NULL ;
}
static void T_4 F_170 ( struct V_119 * * V_231 )
{
int V_40 ;
for ( V_40 = 0 ; V_231 [ V_40 ] ; V_40 ++ )
F_168 ( V_231 [ V_40 ] ) ;
}
static int T_4 F_171 ( struct V_119 * type )
{
struct V_161 * V_229 ;
struct V_232 * V_233 ;
struct V_234 * * V_235 ;
int V_40 , V_236 ;
V_229 = F_172 ( sizeof( * V_229 ) * type -> V_227 , V_159 ) ;
if ( ! V_229 )
return - V_201 ;
type -> V_181 = (struct V_8 )
F_173 ( 0 , ( 1ULL << type -> V_167 ) - 1 ,
0 , type -> V_167 , 0 , 0 ) ;
for ( V_40 = 0 ; V_40 < type -> V_227 ; V_40 ++ ) {
V_229 [ V_40 ] . V_204 = - 1 ;
V_229 [ V_40 ] . V_53 = V_40 ;
V_229 [ V_40 ] . type = type ;
F_174 ( & V_229 [ V_40 ] . V_237 ) ;
V_229 [ V_40 ] . V_2 = F_175 ( struct V_1 * ) ;
if ( ! V_229 [ V_40 ] . V_2 )
goto V_43;
}
if ( type -> V_238 ) {
V_40 = 0 ;
while ( type -> V_238 [ V_40 ] . V_54 . V_54 . V_228 )
V_40 ++ ;
V_233 = F_172 ( sizeof( struct V_234 * ) * ( V_40 + 1 ) +
sizeof( * V_233 ) , V_159 ) ;
if ( ! V_233 )
goto V_43;
V_235 = (struct V_234 * * ) ( V_233 + 1 ) ;
V_233 -> V_228 = L_4 ;
V_233 -> V_235 = V_235 ;
for ( V_236 = 0 ; V_236 < V_40 ; V_236 ++ )
V_235 [ V_236 ] = & type -> V_238 [ V_236 ] . V_54 . V_54 ;
type -> V_230 = V_233 ;
}
type -> V_239 = & V_240 ;
type -> V_229 = V_229 ;
return 0 ;
V_43:
F_168 ( type ) ;
return - V_201 ;
}
static int T_4 F_176 ( struct V_119 * * V_231 )
{
int V_40 , V_112 ;
for ( V_40 = 0 ; V_231 [ V_40 ] ; V_40 ++ ) {
V_112 = F_171 ( V_231 [ V_40 ] ) ;
if ( V_112 )
goto V_43;
}
return 0 ;
V_43:
while ( -- V_40 >= 0 )
F_168 ( V_231 [ V_40 ] ) ;
return V_112 ;
}
static int F_177 ( struct V_28 * V_29 , const struct V_241 * V_242 )
{
struct V_161 * V_52 ;
struct V_1 * V_2 ;
struct V_119 * type ;
int V_66 ;
V_66 = V_74 [ V_29 -> V_69 -> V_73 ] ;
if ( V_66 < 0 )
return - V_195 ;
if ( F_178 ( V_242 -> V_243 ) == V_244 ) {
V_65 [ V_66 ] [ F_179 ( V_242 -> V_243 ) ] = V_29 ;
F_180 ( V_29 , NULL ) ;
return 0 ;
}
type = V_245 [ F_178 ( V_242 -> V_243 ) ] ;
V_2 = F_126 ( type , V_200 ) ;
if ( ! V_2 )
return - V_201 ;
V_52 = & type -> V_229 [ F_179 ( V_242 -> V_243 ) ] ;
if ( V_52 -> V_204 < 0 )
V_52 -> V_204 = V_29 -> V_246 ;
else
F_43 ( V_52 -> V_204 != V_29 -> V_246 ) ;
V_2 -> V_66 = V_66 ;
V_2 -> V_28 = V_29 ;
V_2 -> V_52 = V_52 ;
F_181 ( V_2 ) ;
F_180 ( V_29 , V_2 ) ;
F_132 ( & V_162 ) ;
F_182 ( & V_2 -> V_247 , & V_52 -> V_237 ) ;
F_135 ( & V_162 ) ;
return 0 ;
}
static void F_183 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_184 ( V_29 ) ;
struct V_161 * V_52 ;
int V_40 , V_147 , V_66 = V_74 [ V_29 -> V_69 -> V_73 ] ;
V_2 = F_184 ( V_29 ) ;
if ( ! V_2 ) {
for ( V_40 = 0 ; V_40 < V_248 ; V_40 ++ ) {
if ( V_65 [ V_66 ] [ V_40 ] == V_29 ) {
V_65 [ V_66 ] [ V_40 ] = NULL ;
break;
}
}
F_43 ( V_40 >= V_248 ) ;
return;
}
V_52 = V_2 -> V_52 ;
if ( F_43 ( V_66 != V_2 -> V_66 ) )
return;
F_180 ( V_29 , NULL ) ;
F_132 ( & V_162 ) ;
F_185 ( & V_2 -> V_247 ) ;
F_135 ( & V_162 ) ;
F_186 (cpu) {
if ( * F_131 ( V_52 -> V_2 , V_147 ) == V_2 ) {
* F_131 ( V_52 -> V_2 , V_147 ) = NULL ;
F_10 ( & V_2 -> V_160 ) ;
}
}
F_43 ( F_6 ( & V_2 -> V_160 ) != 1 ) ;
F_162 ( V_2 ) ;
}
static int T_4 F_187 ( void )
{
int V_112 ;
switch ( V_249 . V_250 ) {
case 45 :
V_112 = F_44 ( 0x3ce0 ) ;
if ( V_112 )
return V_112 ;
V_245 = V_251 ;
V_252 = & V_253 ;
break;
case 62 :
V_112 = F_44 ( 0x0e1e ) ;
if ( V_112 )
return V_112 ;
V_245 = V_254 ;
V_252 = & V_255 ;
break;
default:
return 0 ;
}
V_112 = F_176 ( V_245 ) ;
if ( V_112 )
return V_112 ;
V_252 -> V_256 = F_177 ;
V_252 -> remove = F_183 ;
V_112 = F_188 ( V_252 ) ;
if ( V_112 == 0 )
V_257 = true ;
else
F_170 ( V_245 ) ;
return V_112 ;
}
static void T_4 F_189 ( void )
{
if ( V_257 ) {
V_257 = false ;
F_190 ( V_252 ) ;
F_170 ( V_245 ) ;
}
}
static void F_191 ( void )
{
struct V_1 * V_2 ;
while ( ! F_192 ( & V_258 ) ) {
V_2 = F_193 ( V_258 . V_259 ,
struct V_1 , V_247 ) ;
F_185 ( & V_2 -> V_247 ) ;
F_162 ( V_2 ) ;
}
}
static void F_194 ( int V_147 )
{
struct V_119 * type ;
struct V_161 * V_52 ;
struct V_1 * V_2 ;
int V_40 , V_236 ;
for ( V_40 = 0 ; V_260 [ V_40 ] ; V_40 ++ ) {
type = V_260 [ V_40 ] ;
for ( V_236 = 0 ; V_236 < type -> V_227 ; V_236 ++ ) {
V_52 = & type -> V_229 [ V_236 ] ;
V_2 = * F_131 ( V_52 -> V_2 , V_147 ) ;
* F_131 ( V_52 -> V_2 , V_147 ) = NULL ;
if ( V_2 && F_195 ( & V_2 -> V_160 ) )
F_196 ( & V_2 -> V_247 , & V_258 ) ;
}
}
}
static int F_197 ( int V_147 )
{
struct V_119 * type ;
struct V_161 * V_52 ;
struct V_1 * V_2 , * V_261 ;
int V_40 , V_236 , V_262 , V_66 ;
V_66 = F_134 ( V_147 ) ;
for ( V_40 = 0 ; V_260 [ V_40 ] ; V_40 ++ ) {
type = V_260 [ V_40 ] ;
for ( V_236 = 0 ; V_236 < type -> V_227 ; V_236 ++ ) {
V_52 = & type -> V_229 [ V_236 ] ;
V_2 = * F_131 ( V_52 -> V_2 , V_147 ) ;
if ( V_2 && V_2 -> V_66 >= 0 ) {
F_181 ( V_2 ) ;
continue;
}
F_198 (k) {
V_261 = * F_131 ( V_52 -> V_2 , V_262 ) ;
if ( V_261 && V_261 -> V_66 == V_66 ) {
F_7 ( & V_261 -> V_160 ) ;
* F_131 ( V_52 -> V_2 , V_147 ) = V_261 ;
if ( V_2 ) {
F_196 ( & V_2 -> V_247 ,
& V_258 ) ;
V_2 = NULL ;
}
break;
}
}
if ( V_2 ) {
V_2 -> V_66 = V_66 ;
F_181 ( V_2 ) ;
}
}
}
return 0 ;
}
static int F_199 ( int V_147 , int V_66 )
{
struct V_119 * type ;
struct V_161 * V_52 ;
struct V_1 * V_2 ;
int V_40 , V_236 ;
for ( V_40 = 0 ; V_260 [ V_40 ] ; V_40 ++ ) {
type = V_260 [ V_40 ] ;
for ( V_236 = 0 ; V_236 < type -> V_227 ; V_236 ++ ) {
V_52 = & type -> V_229 [ V_236 ] ;
if ( V_52 -> V_204 < 0 )
V_52 -> V_204 = V_236 ;
V_2 = F_126 ( type , F_200 ( V_147 ) ) ;
if ( ! V_2 )
return - V_201 ;
V_2 -> V_52 = V_52 ;
V_2 -> V_66 = V_66 ;
* F_131 ( V_52 -> V_2 , V_147 ) = V_2 ;
}
}
return 0 ;
}
static void
F_201 ( struct V_119 * * V_263 , int V_264 , int V_265 )
{
struct V_119 * type ;
struct V_161 * V_52 ;
struct V_1 * V_2 ;
int V_40 , V_236 ;
for ( V_40 = 0 ; V_263 [ V_40 ] ; V_40 ++ ) {
type = V_263 [ V_40 ] ;
for ( V_236 = 0 ; V_236 < type -> V_227 ; V_236 ++ ) {
V_52 = & type -> V_229 [ V_236 ] ;
if ( V_264 < 0 )
V_2 = F_130 ( V_52 , V_265 ) ;
else
V_2 = F_130 ( V_52 , V_264 ) ;
if ( ! V_2 )
continue;
if ( V_264 < 0 ) {
F_43 ( V_2 -> V_147 != - 1 ) ;
V_2 -> V_147 = V_265 ;
continue;
}
F_43 ( V_2 -> V_147 != V_264 ) ;
if ( V_265 >= 0 ) {
F_122 ( V_2 ) ;
F_202 ( & V_52 -> V_52 ,
V_264 , V_265 ) ;
V_2 -> V_147 = V_265 ;
} else {
V_2 -> V_147 = - 1 ;
}
}
}
}
static void F_203 ( int V_147 )
{
int V_40 , V_66 , V_266 ;
if ( ! F_204 ( V_147 , & V_217 ) )
return;
V_66 = F_134 ( V_147 ) ;
V_266 = - 1 ;
F_198 (i) {
if ( V_40 == V_147 )
continue;
if ( V_66 == F_134 ( V_40 ) ) {
V_266 = V_40 ;
break;
}
}
if ( V_266 >= 0 )
F_205 ( V_266 , & V_217 ) ;
F_201 ( V_260 , V_147 , V_266 ) ;
F_201 ( V_245 , V_147 , V_266 ) ;
}
static void F_206 ( int V_147 )
{
int V_40 , V_66 ;
V_66 = F_134 ( V_147 ) ;
F_207 (i, &uncore_cpu_mask) {
if ( V_66 == F_134 ( V_40 ) )
return;
}
F_205 ( V_147 , & V_217 ) ;
F_201 ( V_260 , - 1 , V_147 ) ;
F_201 ( V_245 , - 1 , V_147 ) ;
}
static int F_208 ( struct V_267 * V_268 ,
unsigned long V_269 , void * V_270 )
{
unsigned int V_147 = ( long ) V_270 ;
switch ( V_269 & ~ V_271 ) {
case V_272 :
F_199 ( V_147 , - 1 ) ;
break;
case V_273 :
F_197 ( V_147 ) ;
break;
case V_274 :
case V_275 :
F_194 ( V_147 ) ;
break;
case V_276 :
case V_277 :
F_191 () ;
break;
default:
break;
}
switch ( V_269 & ~ V_271 ) {
case V_278 :
case V_273 :
F_206 ( V_147 ) ;
break;
case V_279 :
F_203 ( V_147 ) ;
break;
default:
break;
}
return V_280 ;
}
static void T_4 F_209 ( void * V_281 )
{
F_197 ( F_114 () ) ;
}
static int T_4 F_210 ( void )
{
int V_112 , V_147 , V_282 ;
V_282 = V_249 . V_283 ;
switch ( V_249 . V_250 ) {
case 26 :
case 30 :
case 37 :
case 44 :
V_260 = V_284 ;
break;
case 42 :
case 58 :
if ( V_285 . V_227 > V_282 )
V_285 . V_227 = V_282 ;
V_260 = V_286 ;
break;
case 45 :
if ( V_287 . V_227 > V_282 )
V_287 . V_227 = V_282 ;
V_260 = V_288 ;
break;
case 46 :
V_114 = true ;
case 47 :
if ( ! V_114 )
V_289 . V_238 = V_290 ;
if ( V_291 . V_227 > V_282 )
V_291 . V_227 = V_282 ;
V_260 = V_292 ;
break;
case 62 :
if ( V_293 . V_227 > V_282 )
V_293 . V_227 = V_282 ;
V_260 = V_294 ;
break;
default:
return 0 ;
}
V_112 = F_176 ( V_260 ) ;
if ( V_112 )
return V_112 ;
F_211 () ;
F_198 (cpu) {
int V_40 , V_66 = F_134 ( V_147 ) ;
F_207 (i, &uncore_cpu_mask) {
if ( V_66 == F_134 ( V_40 ) ) {
V_66 = - 1 ;
break;
}
}
if ( V_66 < 0 )
continue;
F_199 ( V_147 , V_66 ) ;
F_206 ( V_147 ) ;
}
F_212 ( F_209 , NULL , 1 ) ;
F_213 ( & V_295 ) ;
F_214 () ;
return 0 ;
}
static int T_4 F_215 ( void )
{
struct V_161 * V_52 ;
struct V_119 * type ;
int V_40 , V_236 ;
for ( V_40 = 0 ; V_260 [ V_40 ] ; V_40 ++ ) {
type = V_260 [ V_40 ] ;
for ( V_236 = 0 ; V_236 < type -> V_227 ; V_236 ++ ) {
V_52 = & type -> V_229 [ V_236 ] ;
F_166 ( V_52 ) ;
}
}
for ( V_40 = 0 ; V_245 [ V_40 ] ; V_40 ++ ) {
type = V_245 [ V_40 ] ;
for ( V_236 = 0 ; V_236 < type -> V_227 ; V_236 ++ ) {
V_52 = & type -> V_229 [ V_236 ] ;
F_166 ( V_52 ) ;
}
}
return 0 ;
}
static int T_4 F_216 ( void )
{
int V_112 ;
if ( V_249 . V_296 != V_297 )
return - V_195 ;
if ( V_298 )
return - V_195 ;
V_112 = F_187 () ;
if ( V_112 )
goto V_43;
V_112 = F_210 () ;
if ( V_112 ) {
F_189 () ;
goto V_43;
}
F_215 () ;
return 0 ;
V_43:
return V_112 ;
}

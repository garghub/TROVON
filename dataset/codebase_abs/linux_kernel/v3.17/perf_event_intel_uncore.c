static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 , struct V_1 , V_4 ) ;
}
static struct V_5 *
F_3 ( struct V_1 * V_4 , int V_6 )
{
struct V_5 * V_7 ;
V_7 = * F_4 ( V_4 -> V_7 , V_6 ) ;
if ( V_7 )
return V_7 ;
F_5 ( & V_8 ) ;
F_6 (box, &pmu->box_list, list) {
if ( V_7 -> V_9 == F_7 ( V_6 ) ) {
F_8 ( & V_7 -> V_10 ) ;
* F_4 ( V_4 -> V_7 , V_6 ) = V_7 ;
break;
}
}
F_9 ( & V_8 ) ;
return * F_4 ( V_4 -> V_7 , V_6 ) ;
}
static struct V_5 * F_10 ( struct V_2 * V_3 )
{
return F_3 ( F_1 ( V_3 ) , F_11 () ) ;
}
static T_1 F_12 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
T_1 V_11 ;
F_13 ( V_3 -> V_12 . V_13 , V_11 ) ;
return V_11 ;
}
static struct V_14 *
F_14 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 = & V_3 -> V_12 . V_19 ;
struct V_17 * V_20 = & V_3 -> V_12 . V_21 ;
unsigned long V_22 ;
bool V_23 = false ;
if ( V_18 -> V_24 == V_25 ||
( ! F_15 ( V_7 ) && V_18 -> V_26 ) )
return NULL ;
V_16 = & V_7 -> V_27 [ V_18 -> V_24 ] ;
F_16 ( & V_16 -> V_28 , V_22 ) ;
if ( ! F_17 ( & V_16 -> V_29 ) ||
( V_16 -> V_30 == V_18 -> V_31 && V_16 -> V_32 == V_20 -> V_31 ) ) {
F_8 ( & V_16 -> V_29 ) ;
V_16 -> V_30 = V_18 -> V_31 ;
V_16 -> V_32 = V_20 -> V_31 ;
V_23 = true ;
}
F_18 ( & V_16 -> V_28 , V_22 ) ;
if ( V_23 ) {
if ( ! F_15 ( V_7 ) )
V_18 -> V_26 = 1 ;
return NULL ;
}
return & V_33 ;
}
static void F_19 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 = & V_3 -> V_12 . V_19 ;
if ( F_15 ( V_7 ) || ! V_18 -> V_26 )
return;
V_16 = & V_7 -> V_27 [ V_18 -> V_24 ] ;
F_20 ( & V_16 -> V_29 ) ;
V_18 -> V_26 = 0 ;
}
static T_1 F_21 ( struct V_5 * V_7 , int V_24 )
{
struct V_15 * V_16 ;
unsigned long V_22 ;
T_1 V_31 ;
V_16 = & V_7 -> V_27 [ V_24 ] ;
F_16 ( & V_16 -> V_28 , V_22 ) ;
V_31 = V_16 -> V_31 ;
F_18 ( & V_16 -> V_28 , V_22 ) ;
return V_31 ;
}
static void F_22 ( struct V_5 * V_7 )
{
struct V_34 * V_35 = V_7 -> V_34 ;
int V_36 = F_23 ( V_7 ) ;
T_2 V_31 = 0 ;
if ( ! F_24 ( V_35 , V_36 , & V_31 ) ) {
V_31 |= V_37 ;
F_25 ( V_35 , V_36 , V_31 ) ;
}
}
static void F_26 ( struct V_5 * V_7 )
{
struct V_34 * V_35 = V_7 -> V_34 ;
int V_36 = F_23 ( V_7 ) ;
T_2 V_31 = 0 ;
if ( ! F_24 ( V_35 , V_36 , & V_31 ) ) {
V_31 &= ~ V_37 ;
F_25 ( V_35 , V_36 , V_31 ) ;
}
}
static void F_27 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_34 * V_35 = V_7 -> V_34 ;
struct V_38 * V_39 = & V_3 -> V_12 ;
F_25 ( V_35 , V_39 -> V_40 , V_39 -> V_31 | V_41 ) ;
}
static void F_28 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_34 * V_35 = V_7 -> V_34 ;
struct V_38 * V_39 = & V_3 -> V_12 ;
F_25 ( V_35 , V_39 -> V_40 , V_39 -> V_31 ) ;
}
static T_1 F_29 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_34 * V_35 = V_7 -> V_34 ;
struct V_38 * V_39 = & V_3 -> V_12 ;
T_1 V_11 = 0 ;
F_24 ( V_35 , V_39 -> V_13 , ( T_2 * ) & V_11 ) ;
F_24 ( V_35 , V_39 -> V_13 + 4 , ( T_2 * ) & V_11 + 1 ) ;
return V_11 ;
}
static void F_30 ( struct V_5 * V_7 )
{
struct V_34 * V_35 = V_7 -> V_34 ;
F_25 ( V_35 , V_42 , V_43 ) ;
}
static void F_31 ( struct V_5 * V_7 )
{
T_1 V_31 ;
unsigned V_44 ;
V_44 = F_32 ( V_7 ) ;
if ( V_44 ) {
F_13 ( V_44 , V_31 ) ;
V_31 |= V_37 ;
F_33 ( V_44 , V_31 ) ;
}
}
static void F_34 ( struct V_5 * V_7 )
{
T_1 V_31 ;
unsigned V_44 ;
V_44 = F_32 ( V_7 ) ;
if ( V_44 ) {
F_13 ( V_44 , V_31 ) ;
V_31 &= ~ V_37 ;
F_33 ( V_44 , V_31 ) ;
}
}
static void F_35 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_38 * V_39 = & V_3 -> V_12 ;
struct V_17 * V_18 = & V_39 -> V_19 ;
if ( V_18 -> V_24 != V_25 )
F_33 ( V_18 -> V_45 , F_21 ( V_7 , 0 ) ) ;
F_33 ( V_39 -> V_40 , V_39 -> V_31 | V_41 ) ;
}
static void F_36 ( struct V_5 * V_7 ,
struct V_2 * V_3 )
{
struct V_38 * V_39 = & V_3 -> V_12 ;
F_33 ( V_39 -> V_40 , V_39 -> V_31 ) ;
}
static void F_37 ( struct V_5 * V_7 )
{
unsigned V_44 = F_32 ( V_7 ) ;
if ( V_44 )
F_33 ( V_44 , V_43 ) ;
}
static void F_38 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_17 * V_18 = & V_3 -> V_12 . V_19 ;
struct V_15 * V_16 = & V_7 -> V_27 [ 0 ] ;
int V_46 ;
if ( F_15 ( V_7 ) )
return;
for ( V_46 = 0 ; V_46 < 5 ; V_46 ++ ) {
if ( V_18 -> V_26 & ( 0x1 << V_46 ) )
F_39 ( 1 << ( V_46 * 6 ) , & V_16 -> V_29 ) ;
}
V_18 -> V_26 = 0 ;
}
static struct V_14 *
F_40 ( struct V_5 * V_7 , struct V_2 * V_3 ,
T_1 (* F_41)( int V_47 ) )
{
struct V_17 * V_18 = & V_3 -> V_12 . V_19 ;
struct V_15 * V_16 = & V_7 -> V_27 [ 0 ] ;
int V_46 , V_26 = 0 ;
unsigned long V_22 ;
T_1 V_48 ;
if ( V_18 -> V_24 == V_25 )
return NULL ;
F_16 ( & V_16 -> V_28 , V_22 ) ;
for ( V_46 = 0 ; V_46 < 5 ; V_46 ++ ) {
if ( ! ( V_18 -> V_24 & ( 0x1 << V_46 ) ) )
continue;
if ( ! F_15 ( V_7 ) && ( V_18 -> V_26 & ( 0x1 << V_46 ) ) )
continue;
V_48 = F_41 ( 0x1 << V_46 ) ;
if ( ! F_42 ( F_17 ( & V_16 -> V_29 ) , V_46 , 6 ) ||
! ( ( V_18 -> V_31 ^ V_16 -> V_31 ) & V_48 ) ) {
F_43 ( 1 << ( V_46 * 6 ) , & V_16 -> V_29 ) ;
V_16 -> V_31 &= ~ V_48 ;
V_16 -> V_31 |= V_18 -> V_31 & V_48 ;
V_26 |= ( 0x1 << V_46 ) ;
} else {
break;
}
}
F_18 ( & V_16 -> V_28 , V_22 ) ;
if ( V_46 < 5 )
goto V_49;
if ( ! F_15 ( V_7 ) )
V_18 -> V_26 |= V_26 ;
return NULL ;
V_49:
for (; V_46 >= 0 ; V_46 -- ) {
if ( V_26 & ( 0x1 << V_46 ) )
F_39 ( 1 << ( V_46 * 6 ) , & V_16 -> V_29 ) ;
}
return & V_33 ;
}
static T_1 F_44 ( int V_47 )
{
T_1 V_48 = 0 ;
if ( V_47 & 0x1 )
V_48 |= V_50 ;
if ( V_47 & 0x2 )
V_48 |= V_51 ;
if ( V_47 & 0x4 )
V_48 |= V_52 ;
if ( V_47 & 0x8 )
V_48 |= V_53 ;
return V_48 ;
}
static struct V_14 *
F_45 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
return F_40 ( V_7 , V_3 , F_44 ) ;
}
static int F_46 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_17 * V_18 = & V_3 -> V_12 . V_19 ;
struct V_19 * V_16 ;
int V_24 = 0 ;
for ( V_16 = V_54 ; V_16 -> V_44 ; V_16 ++ ) {
if ( V_16 -> V_3 != ( V_3 -> V_12 . V_31 & V_16 -> V_55 ) )
continue;
V_24 |= V_16 -> V_24 ;
}
if ( V_24 ) {
V_18 -> V_45 = V_56 +
V_57 * V_7 -> V_4 -> V_58 ;
V_18 -> V_31 = V_3 -> V_59 . V_30 & F_44 ( V_24 ) ;
V_18 -> V_24 = V_24 ;
}
return 0 ;
}
static T_1 F_47 ( struct V_2 * V_3 , int V_60 , bool V_61 )
{
struct V_38 * V_39 = & V_3 -> V_12 ;
struct V_17 * V_18 = & V_39 -> V_19 ;
T_1 V_31 = V_18 -> V_31 ;
if ( V_60 > V_18 -> V_24 )
V_31 <<= 8 * ( V_60 - V_18 -> V_24 ) ;
else
V_31 >>= 8 * ( V_18 -> V_24 - V_60 ) ;
if ( V_61 ) {
V_39 -> V_31 += V_60 - V_18 -> V_24 ;
V_18 -> V_31 = V_31 ;
V_18 -> V_24 = V_60 ;
}
return V_31 ;
}
static struct V_14 *
F_48 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_17 * V_18 = & V_3 -> V_12 . V_19 ;
struct V_15 * V_16 = & V_7 -> V_27 [ 0 ] ;
unsigned long V_22 ;
int V_24 = V_18 -> V_24 ;
T_1 V_48 , V_30 = V_18 -> V_31 ;
bool V_23 = false ;
if ( V_18 -> V_24 == V_25 ||
( ! F_15 ( V_7 ) && V_18 -> V_26 ) )
return NULL ;
V_62:
V_48 = 0xffULL << ( V_24 * 8 ) ;
F_16 ( & V_16 -> V_28 , V_22 ) ;
if ( ! F_42 ( F_17 ( & V_16 -> V_29 ) , V_24 , 8 ) ||
! ( ( V_30 ^ V_16 -> V_31 ) & V_48 ) ) {
F_43 ( 1 << ( V_24 * 8 ) , & V_16 -> V_29 ) ;
V_16 -> V_31 &= ~ V_48 ;
V_16 -> V_31 |= V_30 & V_48 ;
V_23 = true ;
}
F_18 ( & V_16 -> V_28 , V_22 ) ;
if ( ! V_23 ) {
V_24 = ( V_24 + 1 ) % 4 ;
if ( V_24 != V_18 -> V_24 ) {
V_30 = F_47 ( V_3 , V_24 , false ) ;
goto V_62;
}
return & V_33 ;
}
if ( ! F_15 ( V_7 ) ) {
if ( V_24 != V_18 -> V_24 )
F_47 ( V_3 , V_24 , true ) ;
V_18 -> V_26 = 1 ;
}
return NULL ;
}
static void F_49 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_17 * V_18 = & V_3 -> V_12 . V_19 ;
struct V_15 * V_16 = & V_7 -> V_27 [ 0 ] ;
if ( F_15 ( V_7 ) || ! V_18 -> V_26 )
return;
F_39 ( 1 << ( V_18 -> V_24 * 8 ) , & V_16 -> V_29 ) ;
V_18 -> V_26 = 0 ;
}
static int F_50 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_38 * V_39 = & V_3 -> V_12 ;
struct V_17 * V_18 = & V_39 -> V_19 ;
int V_63 = V_39 -> V_31 & V_64 ;
if ( V_63 >= 0xb && V_63 <= 0xe ) {
V_18 -> V_45 = V_65 ;
V_18 -> V_24 = V_63 - 0xb ;
V_18 -> V_31 = V_3 -> V_59 . V_30 & ( 0xff << V_18 -> V_24 ) ;
}
return 0 ;
}
static int F_51 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_38 * V_39 = & V_3 -> V_12 ;
struct V_17 * V_18 = & V_39 -> V_19 ;
struct V_17 * V_20 = & V_39 -> V_21 ;
if ( ( V_39 -> V_31 & V_64 ) == 0x38 ) {
V_18 -> V_24 = 0 ;
V_18 -> V_45 = V_66 ;
V_18 -> V_31 = V_3 -> V_59 . V_30 ;
V_20 -> V_45 = V_67 ;
V_20 -> V_31 = V_3 -> V_59 . V_32 ;
}
return 0 ;
}
static void F_52 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_34 * V_35 = V_7 -> V_34 ;
struct V_38 * V_39 = & V_3 -> V_12 ;
struct V_17 * V_18 = & V_39 -> V_19 ;
struct V_17 * V_20 = & V_39 -> V_21 ;
if ( V_18 -> V_24 != V_25 ) {
int V_24 = V_7 -> V_4 -> V_58 + V_68 ;
struct V_34 * V_69 = V_70 [ V_7 -> V_9 ] [ V_24 ] ;
F_53 ( ! V_69 ) ;
if ( V_69 ) {
F_25 ( V_69 , V_18 -> V_45 ,
( T_2 ) V_18 -> V_31 ) ;
F_25 ( V_69 , V_18 -> V_45 + 4 ,
( T_2 ) ( V_18 -> V_31 >> 32 ) ) ;
F_25 ( V_69 , V_20 -> V_45 ,
( T_2 ) V_20 -> V_31 ) ;
F_25 ( V_69 , V_20 -> V_45 + 4 ,
( T_2 ) ( V_20 -> V_31 >> 32 ) ) ;
}
}
F_25 ( V_35 , V_39 -> V_40 , V_39 -> V_31 | V_41 ) ;
}
static int F_54 ( int V_71 )
{
struct V_34 * V_72 = NULL ;
int V_46 , V_73 , V_74 ;
int V_75 = 0 ;
T_2 V_31 = 0 ;
while ( 1 ) {
V_72 = F_55 ( V_76 , V_71 , V_72 ) ;
if ( ! V_72 )
break;
V_73 = V_72 -> V_73 -> V_77 ;
V_75 = F_24 ( V_72 , 0x40 , & V_31 ) ;
if ( V_75 )
break;
V_74 = V_31 ;
V_75 = F_24 ( V_72 , 0x54 , & V_31 ) ;
if ( V_75 )
break;
for ( V_46 = 0 ; V_46 < 8 ; V_46 ++ ) {
if ( V_74 == ( ( V_31 >> ( 3 * V_46 ) ) & 0x7 ) ) {
V_78 [ V_73 ] = V_46 ;
break;
}
}
}
if ( ! V_75 ) {
V_46 = - 1 ;
for ( V_73 = 255 ; V_73 >= 0 ; V_73 -- ) {
if ( V_78 [ V_73 ] >= 0 )
V_46 = V_78 [ V_73 ] ;
else
V_78 [ V_73 ] = V_46 ;
}
}
if ( V_72 )
F_56 ( V_72 ) ;
return V_75 ? F_57 ( V_75 ) : 0 ;
}
static void F_58 ( struct V_5 * V_7 )
{
unsigned V_44 = F_32 ( V_7 ) ;
if ( V_44 )
F_33 ( V_44 , V_79 ) ;
}
static void F_59 ( struct V_5 * V_7 )
{
struct V_34 * V_35 = V_7 -> V_34 ;
F_25 ( V_35 , V_42 , V_79 ) ;
}
static T_1 F_60 ( int V_47 )
{
T_1 V_48 = 0 ;
if ( V_47 & 0x1 )
V_48 |= V_80 ;
if ( V_47 & 0x2 )
V_48 |= V_81 ;
if ( V_47 & 0x4 )
V_48 |= V_82 ;
if ( V_47 & 0x8 )
V_48 |= V_83 ;
if ( V_47 & 0x10 )
V_48 |= V_84 ;
return V_48 ;
}
static struct V_14 *
F_61 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
return F_40 ( V_7 , V_3 , F_60 ) ;
}
static int F_62 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_17 * V_18 = & V_3 -> V_12 . V_19 ;
struct V_19 * V_16 ;
int V_24 = 0 ;
for ( V_16 = V_85 ; V_16 -> V_44 ; V_16 ++ ) {
if ( V_16 -> V_3 != ( V_3 -> V_12 . V_31 & V_16 -> V_55 ) )
continue;
V_24 |= V_16 -> V_24 ;
}
if ( V_24 ) {
V_18 -> V_45 = V_56 +
V_57 * V_7 -> V_4 -> V_58 ;
V_18 -> V_31 = V_3 -> V_59 . V_30 & F_60 ( V_24 ) ;
V_18 -> V_24 = V_24 ;
}
return 0 ;
}
static void F_63 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_38 * V_39 = & V_3 -> V_12 ;
struct V_17 * V_18 = & V_39 -> V_19 ;
if ( V_18 -> V_24 != V_25 ) {
T_1 V_86 = F_21 ( V_7 , 0 ) ;
F_33 ( V_18 -> V_45 , V_86 & 0xffffffff ) ;
F_33 ( V_18 -> V_45 + 6 , V_86 >> 32 ) ;
}
F_33 ( V_39 -> V_40 , V_39 -> V_31 | V_41 ) ;
}
static void F_64 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_34 * V_35 = V_7 -> V_34 ;
struct V_38 * V_39 = & V_3 -> V_12 ;
F_25 ( V_35 , V_87 [ V_39 -> V_24 ] ,
V_39 -> V_31 | V_41 ) ;
}
static void F_65 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_34 * V_35 = V_7 -> V_34 ;
struct V_38 * V_39 = & V_3 -> V_12 ;
F_25 ( V_35 , V_87 [ V_39 -> V_24 ] , V_39 -> V_31 ) ;
}
static T_1 F_66 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_34 * V_35 = V_7 -> V_34 ;
struct V_38 * V_39 = & V_3 -> V_12 ;
T_1 V_11 = 0 ;
F_24 ( V_35 , V_88 [ V_39 -> V_24 ] , ( T_2 * ) & V_11 ) ;
F_24 ( V_35 , V_88 [ V_39 -> V_24 ] + 4 , ( T_2 * ) & V_11 + 1 ) ;
return V_11 ;
}
static void F_67 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_38 * V_39 = & V_3 -> V_12 ;
if ( V_39 -> V_24 < V_89 )
F_33 ( V_39 -> V_40 , V_39 -> V_31 | V_90 ) ;
else
F_33 ( V_39 -> V_40 , V_90 ) ;
}
static void F_68 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
F_33 ( V_3 -> V_12 . V_40 , 0 ) ;
}
static void F_69 ( struct V_5 * V_7 )
{
if ( V_7 -> V_4 -> V_58 == 0 ) {
F_33 ( V_91 ,
V_92 | V_93 ) ;
}
}
static void F_70 ( struct V_5 * V_7 )
{
struct V_34 * V_35 = V_7 -> V_34 ;
int V_94 = V_95 ;
T_3 V_96 ;
T_2 V_97 ;
F_24 ( V_35 , V_94 , & V_97 ) ;
V_96 = V_97 ;
#ifdef F_71
F_24 ( V_35 , V_94 + 4 , & V_97 ) ;
V_96 |= ( ( T_3 ) V_97 << 32 ) ;
#endif
V_96 &= ~ ( V_98 - 1 ) ;
V_7 -> V_99 = F_72 ( V_96 , V_100 ) ;
V_7 -> V_101 = V_102 ;
}
static void F_73 ( struct V_5 * V_7 )
{}
static void F_74 ( struct V_5 * V_7 )
{}
static void F_75 ( struct V_5 * V_7 , struct V_2 * V_3 )
{}
static void F_76 ( struct V_5 * V_7 , struct V_2 * V_3 )
{}
static T_1 F_77 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_38 * V_39 = & V_3 -> V_12 ;
return ( T_1 ) * ( unsigned int * ) ( V_7 -> V_99 + V_39 -> V_13 ) ;
}
static int F_78 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_5 * V_7 ;
struct V_38 * V_39 = & V_3 -> V_12 ;
T_1 V_103 = V_3 -> V_59 . V_31 & V_104 ;
int V_24 , V_105 ;
if ( V_3 -> V_59 . type != V_3 -> V_4 -> type )
return - V_106 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_107 < 0 )
return - V_106 ;
if ( V_39 -> V_108 )
return - V_109 ;
if ( V_3 -> V_59 . V_110 ||
V_3 -> V_59 . V_111 ||
V_3 -> V_59 . V_112 ||
V_3 -> V_59 . V_113 ||
V_3 -> V_59 . V_114 ||
V_3 -> V_59 . V_115 ||
V_3 -> V_59 . V_108 )
return - V_109 ;
if ( V_3 -> V_6 < 0 )
return - V_109 ;
if ( V_3 -> V_59 . V_31 & ~ V_104 )
return - V_109 ;
V_7 = F_3 ( V_4 , V_3 -> V_6 ) ;
if ( ! V_7 || V_7 -> V_6 < 0 )
return - V_109 ;
V_3 -> V_6 = V_7 -> V_6 ;
V_3 -> V_12 . V_24 = - 1 ;
V_3 -> V_12 . V_116 = ~ 0ULL ;
V_3 -> V_12 . V_19 . V_24 = V_25 ;
V_3 -> V_12 . V_21 . V_24 = V_25 ;
switch ( V_103 ) {
case V_117 :
V_105 = V_118 ;
V_24 = V_89 ;
break;
case V_119 :
V_105 = V_120 ;
V_24 = V_89 + 1 ;
break;
default:
return - V_109 ;
}
V_3 -> V_12 . V_13 = V_105 ;
V_3 -> V_12 . V_31 = V_103 ;
V_3 -> V_12 . V_24 = V_24 ;
return 0 ;
}
static int F_79 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
return 0 ;
}
static void F_80 ( struct V_2 * V_3 , int V_22 )
{
struct V_5 * V_7 = F_10 ( V_3 ) ;
T_1 V_11 ;
if ( F_53 ( ! ( V_3 -> V_12 . V_121 & V_122 ) ) )
return;
V_3 -> V_12 . V_121 = 0 ;
V_7 -> V_123 ++ ;
F_81 ( & V_3 -> V_124 , & V_7 -> V_125 ) ;
V_11 = F_77 ( V_7 , V_3 ) ;
F_82 ( & V_3 -> V_12 . V_126 , V_11 ) ;
if ( V_7 -> V_123 == 1 )
F_83 ( V_7 ) ;
}
static void F_84 ( struct V_2 * V_3 , int V_22 )
{
struct V_5 * V_7 = F_10 ( V_3 ) ;
struct V_38 * V_39 = & V_3 -> V_12 ;
if ( ! ( V_39 -> V_121 & V_122 ) ) {
V_7 -> V_123 -- ;
F_53 ( V_39 -> V_121 & V_122 ) ;
V_39 -> V_121 |= V_122 ;
F_85 ( & V_3 -> V_124 ) ;
if ( V_7 -> V_123 == 0 )
F_86 ( V_7 ) ;
}
if ( ( V_22 & V_127 ) && ! ( V_39 -> V_121 & V_128 ) ) {
F_87 ( V_7 , V_3 ) ;
V_39 -> V_121 |= V_128 ;
}
}
static int F_88 ( struct V_2 * V_3 , int V_22 )
{
struct V_5 * V_7 = F_10 ( V_3 ) ;
struct V_38 * V_39 = & V_3 -> V_12 ;
if ( ! V_7 )
return - V_129 ;
V_39 -> V_121 = V_128 | V_122 ;
if ( ! ( V_22 & V_130 ) )
V_39 -> V_121 |= V_131 ;
F_80 ( V_3 , 0 ) ;
V_7 -> V_132 ++ ;
return 0 ;
}
static void F_89 ( struct V_2 * V_3 , int V_22 )
{
struct V_5 * V_7 = F_10 ( V_3 ) ;
int V_46 ;
F_84 ( V_3 , V_127 ) ;
for ( V_46 = 0 ; V_46 < V_7 -> V_132 ; V_46 ++ ) {
if ( V_3 == V_7 -> V_133 [ V_46 ] ) {
-- V_7 -> V_132 ;
break;
}
}
}
static int F_90 ( int V_71 )
{
struct V_34 * V_134 = NULL ;
int V_73 ;
V_134 = F_55 ( V_76 , V_71 , V_134 ) ;
if ( ! V_134 )
return - V_135 ;
V_73 = V_134 -> V_73 -> V_77 ;
V_78 [ V_73 ] = 0 ;
F_56 ( V_134 ) ;
return 0 ;
}
static void F_91 ( struct V_5 * V_7 )
{
F_33 ( V_136 , 0 ) ;
}
static void F_92 ( struct V_5 * V_7 )
{
F_33 ( V_136 , V_137 | V_138 ) ;
}
static void F_93 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_38 * V_39 = & V_3 -> V_12 ;
if ( V_39 -> V_24 < V_89 )
F_33 ( V_39 -> V_40 , V_39 -> V_31 | V_90 ) ;
else
F_33 ( V_39 -> V_40 , V_139 ) ;
}
static void F_94 ( struct V_5 * V_7 )
{
F_33 ( V_140 , V_141 ) ;
}
static void F_95 ( struct V_5 * V_7 )
{
unsigned V_44 = F_32 ( V_7 ) ;
T_1 V_31 ;
if ( V_44 ) {
F_13 ( V_44 , V_31 ) ;
V_31 &= ~ ( ( 1ULL << F_96 ( V_7 ) ) - 1 ) ;
if ( F_97 ( V_7 ) )
V_31 &= ~ V_142 ;
F_33 ( V_44 , V_31 ) ;
}
}
static void F_98 ( struct V_5 * V_7 )
{
unsigned V_44 = F_32 ( V_7 ) ;
T_1 V_31 ;
if ( V_44 ) {
F_13 ( V_44 , V_31 ) ;
V_31 |= ( 1ULL << F_96 ( V_7 ) ) - 1 ;
if ( F_97 ( V_7 ) )
V_31 |= V_142 ;
F_33 ( V_44 , V_31 ) ;
}
}
static void F_99 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
F_33 ( V_3 -> V_12 . V_40 , 0 ) ;
}
static void F_100 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_38 * V_39 = & V_3 -> V_12 ;
if ( V_39 -> V_24 >= V_89 )
F_33 ( V_39 -> V_40 , V_143 ) ;
else if ( V_7 -> V_4 -> type -> V_144 & V_143 )
F_33 ( V_39 -> V_40 , V_39 -> V_31 | V_145 ) ;
else
F_33 ( V_39 -> V_40 , V_39 -> V_31 | V_143 ) ;
}
static int F_101 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_38 * V_39 = & V_3 -> V_12 ;
struct V_17 * V_18 = & V_39 -> V_19 ;
struct V_17 * V_20 = & V_39 -> V_21 ;
int V_146 , V_63 ;
V_146 = ( V_39 -> V_31 & V_147 ) >>
V_148 ;
V_63 = ( V_39 -> V_31 & V_149 ) >>
V_150 ;
if ( ( V_146 == 0 && V_63 > 0x3 ) || ( V_146 == 1 && V_63 > 0x6 ) ||
( V_146 == 2 && V_63 != 0x4 ) || V_146 == 3 )
return 0 ;
if ( V_7 -> V_4 -> V_58 == 0 )
V_18 -> V_45 = V_151 ;
else
V_18 -> V_45 = V_152 ;
V_18 -> V_24 = 0 ;
V_18 -> V_31 = V_3 -> V_59 . V_30 ;
V_20 -> V_31 = V_3 -> V_59 . V_32 ;
return 0 ;
}
static void F_102 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_38 * V_39 = & V_3 -> V_12 ;
struct V_17 * V_18 = & V_39 -> V_19 ;
struct V_17 * V_20 = & V_39 -> V_21 ;
if ( V_18 -> V_24 != V_25 ) {
F_33 ( V_18 -> V_45 , V_18 -> V_31 ) ;
F_33 ( V_18 -> V_45 + 1 , V_20 -> V_31 ) ;
}
F_33 ( V_39 -> V_40 , V_143 |
( V_39 -> V_31 & V_149 ) ) ;
}
static int F_103 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_38 * V_39 = & V_3 -> V_12 ;
struct V_17 * V_18 = & V_39 -> V_19 ;
struct V_17 * V_20 = & V_39 -> V_21 ;
if ( ( V_39 -> V_31 & V_153 ) !=
V_154 )
return 0 ;
if ( V_7 -> V_4 -> V_58 == 0 )
V_18 -> V_45 = V_155 ;
else
V_18 -> V_45 = V_156 ;
V_18 -> V_24 = 0 ;
V_18 -> V_31 = V_3 -> V_59 . V_30 ;
V_20 -> V_31 = V_3 -> V_59 . V_32 ;
return 0 ;
}
static void F_104 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_38 * V_39 = & V_3 -> V_12 ;
struct V_17 * V_18 = & V_39 -> V_19 ;
struct V_17 * V_20 = & V_39 -> V_21 ;
if ( V_18 -> V_24 != V_25 ) {
F_33 ( V_18 -> V_45 , 0 ) ;
F_33 ( V_18 -> V_45 + 1 , V_18 -> V_31 ) ;
F_33 ( V_18 -> V_45 + 2 , V_20 -> V_31 ) ;
F_33 ( V_18 -> V_45 , V_157 ) ;
}
F_33 ( V_39 -> V_40 , V_39 -> V_31 | V_145 ) ;
}
static bool F_105 ( struct V_5 * V_7 , int V_24 , T_1 V_31 )
{
struct V_15 * V_16 ;
unsigned long V_22 ;
bool V_158 = false ;
T_1 V_48 ;
if ( V_24 < V_159 ) {
V_16 = & V_7 -> V_27 [ V_24 ] ;
F_16 ( & V_16 -> V_28 , V_22 ) ;
if ( ! F_17 ( & V_16 -> V_29 ) || V_16 -> V_31 == V_31 ) {
F_8 ( & V_16 -> V_29 ) ;
V_16 -> V_31 = V_31 ;
V_158 = true ;
}
F_18 ( & V_16 -> V_28 , V_22 ) ;
return V_158 ;
}
V_24 -= V_159 ;
if ( F_53 ( V_24 >= 4 ) )
return false ;
if ( V_160 )
V_48 = V_161 ;
else
V_48 = V_162 ;
V_16 = & V_7 -> V_27 [ V_159 ] ;
F_16 ( & V_16 -> V_28 , V_22 ) ;
if ( F_42 ( F_17 ( & V_16 -> V_29 ) , V_24 , 8 ) ) {
if ( V_160 )
V_48 |= F_106 ( V_24 ) ;
else
V_48 |= F_107 ( V_24 ) ;
}
if ( ! F_17 ( & V_16 -> V_29 ) || ! ( ( V_16 -> V_31 ^ V_31 ) & V_48 ) ) {
F_43 ( 1 << ( V_24 * 8 ) , & V_16 -> V_29 ) ;
if ( V_160 )
V_48 = V_161 |
F_106 ( V_24 ) ;
else
V_48 = V_162 |
F_107 ( V_24 ) ;
V_16 -> V_31 &= ~ V_48 ;
V_16 -> V_31 |= ( V_31 & V_48 ) ;
V_158 = true ;
}
F_18 ( & V_16 -> V_28 , V_22 ) ;
return V_158 ;
}
static void F_108 ( struct V_5 * V_7 , int V_24 )
{
struct V_15 * V_16 ;
if ( V_24 < V_159 ) {
V_16 = & V_7 -> V_27 [ V_24 ] ;
F_20 ( & V_16 -> V_29 ) ;
return;
}
V_24 -= V_159 ;
V_16 = & V_7 -> V_27 [ V_159 ] ;
F_39 ( 1 << ( V_24 * 8 ) , & V_16 -> V_29 ) ;
}
static T_1 F_109 ( struct V_2 * V_3 , int V_60 , bool V_61 )
{
struct V_38 * V_39 = & V_3 -> V_12 ;
struct V_17 * V_18 = & V_39 -> V_19 ;
T_1 V_24 , V_163 = F_42 ( V_18 -> V_24 , 0 , 8 ) ;
T_1 V_31 = V_18 -> V_31 ;
V_24 = V_163 - V_159 ;
if ( V_160 )
V_31 &= F_106 ( V_24 ) ;
else
V_31 &= F_107 ( V_24 ) ;
if ( V_60 > V_163 ) {
V_24 = V_60 - V_163 ;
V_31 <<= 3 * V_24 ;
} else {
V_24 = V_163 - V_60 ;
V_31 >>= 3 * V_24 ;
}
if ( V_160 )
V_31 |= V_161 & V_18 -> V_31 ;
else
V_31 |= V_162 & V_18 -> V_31 ;
V_31 |= V_161 & V_18 -> V_31 ;
if ( V_61 ) {
if ( V_60 > V_163 )
V_39 -> V_31 += V_24 << V_164 ;
else
V_39 -> V_31 -= V_24 << V_164 ;
V_18 -> V_31 = V_31 ;
V_18 -> V_24 = ~ 0xff | V_60 ;
}
return V_31 ;
}
static struct V_14 *
F_110 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_17 * V_18 = & V_3 -> V_12 . V_19 ;
struct V_17 * V_20 = & V_3 -> V_12 . V_21 ;
int V_46 , V_24 [ 2 ] , V_26 = 0 ;
T_1 V_30 = V_18 -> V_31 ;
V_24 [ 0 ] = F_42 ( V_18 -> V_24 , 0 , 8 ) ;
V_24 [ 1 ] = F_42 ( V_18 -> V_24 , 1 , 8 ) ;
V_62:
for ( V_46 = 0 ; V_46 < 2 ; V_46 ++ ) {
if ( ! F_15 ( V_7 ) && ( V_18 -> V_26 & ( 0x1 << V_46 ) ) )
V_24 [ V_46 ] = 0xff ;
if ( V_24 [ V_46 ] == 0xff )
continue;
if ( ! F_105 ( V_7 , V_24 [ V_46 ] ,
F_42 ( V_30 , V_46 , 32 ) ) )
goto V_49;
V_26 |= ( 0x1 << V_46 ) ;
}
if ( V_20 -> V_24 != V_25 &&
( F_15 ( V_7 ) || ! V_20 -> V_26 ) &&
! F_105 ( V_7 , V_20 -> V_24 , V_20 -> V_31 ) )
goto V_49;
if ( ! F_15 ( V_7 ) ) {
if ( V_24 [ 0 ] != 0xff && V_24 [ 0 ] != F_42 ( V_18 -> V_24 , 0 , 8 ) )
F_109 ( V_3 , V_24 [ 0 ] , true ) ;
V_18 -> V_26 |= V_26 ;
if ( V_20 -> V_24 != V_25 )
V_20 -> V_26 = 1 ;
}
return NULL ;
V_49:
if ( V_24 [ 0 ] != 0xff && ! ( V_26 & 0x1 ) &&
V_24 [ 0 ] >= V_159 ) {
F_111 ( F_42 ( V_18 -> V_24 , 1 , 8 ) != 0xff ) ;
V_24 [ 0 ] -= V_159 ;
V_24 [ 0 ] = ( V_24 [ 0 ] + 1 ) % 4 ;
V_24 [ 0 ] += V_159 ;
if ( V_24 [ 0 ] != F_42 ( V_18 -> V_24 , 0 , 8 ) ) {
V_30 = F_109 ( V_3 , V_24 [ 0 ] , false ) ;
goto V_62;
}
}
if ( V_26 & 0x1 )
F_108 ( V_7 , V_24 [ 0 ] ) ;
if ( V_26 & 0x2 )
F_108 ( V_7 , V_24 [ 1 ] ) ;
return & V_33 ;
}
static void F_112 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_17 * V_18 = & V_3 -> V_12 . V_19 ;
struct V_17 * V_20 = & V_3 -> V_12 . V_21 ;
if ( F_15 ( V_7 ) )
return;
if ( V_18 -> V_26 & 0x1 )
F_108 ( V_7 , F_42 ( V_18 -> V_24 , 0 , 8 ) ) ;
if ( V_18 -> V_26 & 0x2 )
F_108 ( V_7 , F_42 ( V_18 -> V_24 , 1 , 8 ) ) ;
V_18 -> V_26 = 0 ;
if ( V_20 -> V_26 ) {
F_108 ( V_7 , V_20 -> V_24 ) ;
V_20 -> V_26 = 0 ;
}
}
static int F_113 ( struct V_19 * V_16 )
{
if ( V_16 -> V_24 < V_159 )
return V_16 -> V_24 ;
return V_16 -> V_24 + ( V_16 -> V_3 >> V_164 ) - 0xd ;
}
static int F_114 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_165 * type = V_7 -> V_4 -> type ;
struct V_17 * V_18 = & V_3 -> V_12 . V_19 ;
struct V_17 * V_20 = & V_3 -> V_12 . V_21 ;
struct V_19 * V_16 ;
unsigned V_44 ;
int V_166 = 0 ;
for ( V_16 = V_167 ; V_16 -> V_44 ; V_16 ++ ) {
if ( V_16 -> V_3 != ( V_3 -> V_12 . V_31 & V_16 -> V_55 ) )
continue;
if ( V_3 -> V_59 . V_30 & ~ V_16 -> V_168 )
return - V_109 ;
V_44 = V_16 -> V_44 + type -> V_169 * V_7 -> V_4 -> V_58 ;
if ( F_53 ( V_44 >= 0xffff || V_16 -> V_24 >= 0xff ) )
return - V_109 ;
if ( V_16 -> V_24 == V_170 )
V_166 = 1 ;
else if ( F_53 ( V_166 > 0 ) )
return - V_109 ;
V_18 -> V_24 &= ~ ( 0xff << ( V_166 * 8 ) ) ;
V_18 -> V_45 &= ~ ( 0xffff << ( V_166 * 16 ) ) ;
V_18 -> V_24 |= F_113 ( V_16 ) << ( V_166 * 8 ) ;
V_18 -> V_45 |= V_44 << ( V_166 * 16 ) ;
V_18 -> V_31 = V_3 -> V_59 . V_30 ;
V_166 ++ ;
}
if ( V_166 == 2 ) {
V_20 -> V_24 = V_171 ;
if ( V_3 -> V_59 . V_32 & V_172 )
V_20 -> V_31 = V_3 -> V_59 . V_32 ;
else
V_20 -> V_31 = ~ 0ULL ;
if ( V_7 -> V_4 -> V_58 == 0 )
V_20 -> V_45 = V_173 ;
else
V_20 -> V_45 = V_174 ;
}
return 0 ;
}
static T_1 F_115 ( struct V_5 * V_7 , int V_24 )
{
struct V_15 * V_16 ;
unsigned long V_22 ;
T_1 V_31 ;
if ( V_24 < V_159 )
return V_7 -> V_27 [ V_24 ] . V_31 ;
V_16 = & V_7 -> V_27 [ V_159 ] ;
F_16 ( & V_16 -> V_28 , V_22 ) ;
V_31 = V_16 -> V_31 ;
F_18 ( & V_16 -> V_28 , V_22 ) ;
return V_31 ;
}
static void F_116 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_38 * V_39 = & V_3 -> V_12 ;
struct V_17 * V_18 = & V_39 -> V_19 ;
struct V_17 * V_20 = & V_39 -> V_21 ;
int V_24 ;
V_24 = F_42 ( V_18 -> V_24 , 0 , 8 ) ;
if ( V_24 != 0xff )
F_33 ( F_42 ( V_18 -> V_45 , 0 , 16 ) ,
F_115 ( V_7 , V_24 ) ) ;
V_24 = F_42 ( V_18 -> V_24 , 1 , 8 ) ;
if ( V_24 != 0xff )
F_33 ( F_42 ( V_18 -> V_45 , 1 , 16 ) ,
F_115 ( V_7 , V_24 ) ) ;
if ( V_20 -> V_24 != V_25 ) {
F_33 ( V_20 -> V_45 , 0 ) ;
if ( V_20 -> V_31 != ~ 0ULL ) {
F_33 ( V_20 -> V_45 + 1 ,
V_20 -> V_31 & V_175 ) ;
F_33 ( V_20 -> V_45 + 2 , V_176 &
( V_20 -> V_31 >> V_177 ) ) ;
F_33 ( V_20 -> V_45 , V_172 ) ;
}
}
F_33 ( V_39 -> V_40 , V_39 -> V_31 | V_143 ) ;
}
static void F_117 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_38 * V_39 = & V_3 -> V_12 ;
struct V_17 * V_18 = & V_39 -> V_19 ;
if ( V_18 -> V_24 % 2 ) {
V_18 -> V_24 -- ;
V_39 -> V_31 -= 1 << V_178 ;
} else {
V_18 -> V_24 ++ ;
V_39 -> V_31 += 1 << V_178 ;
}
switch ( V_18 -> V_24 % 6 ) {
case 2 :
V_18 -> V_31 >>= 8 ;
break;
case 3 :
V_18 -> V_31 <<= 8 ;
break;
} ;
}
static struct V_14 *
F_118 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_38 * V_39 = & V_3 -> V_12 ;
struct V_17 * V_18 = & V_39 -> V_19 ;
struct V_17 * V_20 = & V_39 -> V_21 ;
struct V_15 * V_16 ;
unsigned long V_22 ;
int V_24 , V_179 ;
T_1 V_30 ;
bool V_23 = false ;
if ( ! F_15 ( V_7 ) && V_18 -> V_26 )
return NULL ;
V_24 = V_18 -> V_24 % 6 ;
V_30 = V_18 -> V_31 ;
V_62:
V_179 = V_24 ;
if ( V_179 > 2 )
V_179 -- ;
V_179 += ( V_18 -> V_24 / 6 ) * 5 ;
V_16 = & V_7 -> V_27 [ V_179 ] ;
F_16 ( & V_16 -> V_28 , V_22 ) ;
if ( V_24 < 2 ) {
if ( ! F_17 ( & V_16 -> V_29 ) || V_16 -> V_31 == V_18 -> V_31 ) {
F_8 ( & V_16 -> V_29 ) ;
V_16 -> V_31 = V_18 -> V_31 ;
V_23 = true ;
}
} else if ( V_24 == 2 || V_24 == 3 ) {
T_1 V_48 = 0xff << ( ( V_24 - 2 ) * 8 ) ;
if ( ! F_42 ( F_17 ( & V_16 -> V_29 ) , V_24 - 2 , 8 ) ||
! ( ( V_16 -> V_31 ^ V_30 ) & V_48 ) ) {
F_43 ( 1 << ( ( V_24 - 2 ) * 8 ) , & V_16 -> V_29 ) ;
V_16 -> V_31 &= ~ V_48 ;
V_16 -> V_31 |= V_30 & V_48 ;
V_23 = true ;
}
} else {
if ( ! F_17 ( & V_16 -> V_29 ) ||
( V_16 -> V_31 == ( V_39 -> V_31 >> 32 ) &&
V_16 -> V_30 == V_18 -> V_31 &&
V_16 -> V_32 == V_20 -> V_31 ) ) {
F_8 ( & V_16 -> V_29 ) ;
V_16 -> V_31 = ( V_39 -> V_31 >> 32 ) ;
V_16 -> V_30 = V_18 -> V_31 ;
V_16 -> V_32 = V_20 -> V_31 ;
V_23 = true ;
}
}
F_18 ( & V_16 -> V_28 , V_22 ) ;
if ( ! V_23 ) {
V_24 ^= 1 ;
if ( V_24 != V_18 -> V_24 % 6 ) {
if ( V_24 == 2 )
V_30 >>= 8 ;
else if ( V_24 == 3 )
V_30 <<= 8 ;
goto V_62;
}
} else {
if ( ! F_15 ( V_7 ) ) {
if ( V_24 != V_18 -> V_24 % 6 )
F_117 ( V_7 , V_3 ) ;
V_18 -> V_26 = 1 ;
}
return NULL ;
}
return & V_33 ;
}
static void F_119 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 = & V_3 -> V_12 . V_19 ;
int V_24 , V_179 ;
if ( F_15 ( V_7 ) || ! V_18 -> V_26 )
return;
V_24 = V_18 -> V_24 % 6 ;
V_179 = V_24 ;
if ( V_179 > 2 )
V_179 -- ;
V_179 += ( V_18 -> V_24 / 6 ) * 5 ;
V_16 = & V_7 -> V_27 [ V_179 ] ;
if ( V_24 == 2 || V_24 == 3 )
F_39 ( 1 << ( ( V_24 - 2 ) * 8 ) , & V_16 -> V_29 ) ;
else
F_20 ( & V_16 -> V_29 ) ;
V_18 -> V_26 = 0 ;
}
static int F_120 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_38 * V_39 = & V_3 -> V_12 ;
struct V_17 * V_18 = & V_3 -> V_12 . V_19 ;
struct V_17 * V_20 = & V_3 -> V_12 . V_21 ;
int V_24 ;
V_24 = ( V_3 -> V_12 . V_31 & V_180 ) >>
V_178 ;
if ( V_24 >= 0x18 )
return - V_109 ;
V_18 -> V_24 = V_24 ;
V_18 -> V_31 = V_3 -> V_59 . V_30 ;
switch ( V_24 % 6 ) {
case 4 :
case 5 :
V_39 -> V_31 |= V_3 -> V_59 . V_31 & ( ~ 0ULL << 32 ) ;
V_20 -> V_31 = V_3 -> V_59 . V_32 ;
break;
} ;
return 0 ;
}
static void F_121 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_38 * V_39 = & V_3 -> V_12 ;
struct V_17 * V_18 = & V_39 -> V_19 ;
struct V_17 * V_20 = & V_39 -> V_21 ;
int V_24 , V_181 ;
V_24 = V_18 -> V_24 ;
V_181 = V_24 / 6 + V_7 -> V_4 -> V_58 * 4 ;
switch ( V_24 % 6 ) {
case 0 :
F_33 ( F_122 ( V_181 ) , V_18 -> V_31 ) ;
break;
case 1 :
F_33 ( F_123 ( V_181 ) , V_18 -> V_31 ) ;
break;
case 2 :
case 3 :
F_33 ( F_124 ( V_181 ) ,
F_21 ( V_7 , 2 + ( V_24 / 6 ) * 5 ) ) ;
break;
case 4 :
F_33 ( F_125 ( V_181 ) ,
V_39 -> V_31 >> 32 ) ;
F_33 ( F_126 ( V_181 ) , V_18 -> V_31 ) ;
F_33 ( F_127 ( V_181 ) , V_20 -> V_31 ) ;
break;
case 5 :
F_33 ( F_128 ( V_181 ) ,
V_39 -> V_31 >> 32 ) ;
F_33 ( F_129 ( V_181 ) , V_18 -> V_31 ) ;
F_33 ( F_130 ( V_181 ) , V_20 -> V_31 ) ;
break;
} ;
F_33 ( V_39 -> V_40 , V_143 |
( V_39 -> V_31 & V_180 ) ) ;
}
static void F_131 ( struct V_5 * V_7 , struct V_2 * V_3 , int V_24 )
{
struct V_38 * V_39 = & V_3 -> V_12 ;
V_39 -> V_24 = V_24 ;
V_39 -> V_116 = ++ V_7 -> V_182 [ V_24 ] ;
if ( V_39 -> V_24 == V_89 ) {
V_39 -> V_13 = F_132 ( V_7 ) ;
V_39 -> V_40 = F_133 ( V_7 ) ;
return;
}
V_39 -> V_40 = F_134 ( V_7 , V_39 -> V_24 ) ;
V_39 -> V_13 = F_135 ( V_7 , V_39 -> V_24 ) ;
}
static void F_87 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
T_1 V_126 , V_183 , V_184 ;
int V_185 ;
if ( V_3 -> V_12 . V_24 >= V_89 )
V_185 = 64 - F_136 ( V_7 ) ;
else
V_185 = 64 - F_137 ( V_7 ) ;
V_62:
V_126 = F_138 ( & V_3 -> V_12 . V_126 ) ;
V_183 = F_139 ( V_7 , V_3 ) ;
if ( F_140 ( & V_3 -> V_12 . V_126 , V_183 ) != V_126 )
goto V_62;
V_184 = ( V_183 << V_185 ) - ( V_126 << V_185 ) ;
V_184 >>= V_185 ;
F_141 ( V_184 , & V_3 -> V_11 ) ;
}
static enum V_186 F_142 ( struct V_187 * V_187 )
{
struct V_5 * V_7 ;
struct V_2 * V_3 ;
unsigned long V_22 ;
int V_188 ;
V_7 = F_2 ( V_187 , struct V_5 , V_187 ) ;
if ( ! V_7 -> V_123 || V_7 -> V_6 != F_11 () )
return V_189 ;
F_143 ( V_22 ) ;
F_6 (event, &box->active_list, active_entry) {
F_87 ( V_7 , V_3 ) ;
}
F_144 (bit, box->active_mask, UNCORE_PMC_IDX_MAX)
F_87 ( V_7 , V_7 -> V_190 [ V_188 ] ) ;
F_145 ( V_22 ) ;
F_146 ( V_187 , F_147 ( V_7 -> V_101 ) ) ;
return V_191 ;
}
static void F_83 ( struct V_5 * V_7 )
{
F_148 ( & V_7 -> V_187 ,
F_147 ( V_7 -> V_101 ) , 0 ,
V_192 , 0 ) ;
}
static void F_86 ( struct V_5 * V_7 )
{
F_149 ( & V_7 -> V_187 ) ;
}
static void F_150 ( struct V_5 * V_7 )
{
F_151 ( & V_7 -> V_187 , V_193 , V_194 ) ;
V_7 -> V_187 . V_195 = F_142 ;
}
static struct V_5 * F_152 ( struct V_165 * type , int V_196 )
{
struct V_5 * V_7 ;
int V_46 , V_197 ;
V_197 = sizeof( * V_7 ) + type -> V_198 * sizeof( struct V_15 ) ;
V_7 = F_153 ( V_197 , V_199 , V_196 ) ;
if ( ! V_7 )
return NULL ;
for ( V_46 = 0 ; V_46 < type -> V_198 ; V_46 ++ )
F_154 ( & V_7 -> V_27 [ V_46 ] . V_28 ) ;
F_150 ( V_7 ) ;
F_155 ( & V_7 -> V_10 , 1 ) ;
V_7 -> V_6 = - 1 ;
V_7 -> V_9 = - 1 ;
V_7 -> V_101 = V_200 ;
F_156 ( & V_7 -> V_125 ) ;
return V_7 ;
}
static int
F_157 ( struct V_5 * V_7 , struct V_2 * V_201 , bool V_202 )
{
struct V_2 * V_3 ;
int V_203 , V_204 ;
V_204 = V_7 -> V_4 -> type -> V_205 ;
if ( V_7 -> V_4 -> type -> V_206 )
V_204 ++ ;
if ( V_7 -> V_132 >= V_204 )
return - V_109 ;
V_203 = V_7 -> V_132 ;
V_7 -> V_133 [ V_203 ] = V_201 ;
V_203 ++ ;
if ( ! V_202 )
return V_203 ;
F_6 (event, &leader->sibling_list, group_entry) {
if ( V_3 -> V_121 <= V_207 )
continue;
if ( V_203 >= V_204 )
return - V_109 ;
V_7 -> V_133 [ V_203 ] = V_3 ;
V_203 ++ ;
}
return V_203 ;
}
static struct V_14 *
F_158 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
struct V_165 * type = V_7 -> V_4 -> type ;
struct V_14 * V_208 ;
if ( type -> V_209 -> V_210 ) {
V_208 = type -> V_209 -> V_210 ( V_7 , V_3 ) ;
if ( V_208 )
return V_208 ;
}
if ( V_3 -> V_59 . V_31 == V_211 )
return & V_212 ;
if ( type -> V_213 ) {
F_159 (c, type->constraints) {
if ( ( V_3 -> V_12 . V_31 & V_208 -> V_214 ) == V_208 -> V_215 )
return V_208 ;
}
}
return & type -> V_216 ;
}
static void F_160 ( struct V_5 * V_7 , struct V_2 * V_3 )
{
if ( V_7 -> V_4 -> type -> V_209 -> V_217 )
V_7 -> V_4 -> type -> V_209 -> V_217 ( V_7 , V_3 ) ;
}
static int F_161 ( struct V_5 * V_7 , int V_218 [] , int V_203 )
{
unsigned long V_219 [ F_162 ( V_220 ) ] ;
struct V_14 * V_208 ;
int V_46 , V_221 , V_222 , V_158 = 0 ;
struct V_38 * V_39 ;
F_163 ( V_219 , V_220 ) ;
for ( V_46 = 0 , V_221 = V_220 , V_222 = 0 ; V_46 < V_203 ; V_46 ++ ) {
V_39 = & V_7 -> V_133 [ V_46 ] -> V_12 ;
V_208 = F_158 ( V_7 , V_7 -> V_133 [ V_46 ] ) ;
V_39 -> V_223 = V_208 ;
V_221 = F_164 ( V_221 , V_208 -> V_224 ) ;
V_222 = F_165 ( V_222 , V_208 -> V_224 ) ;
}
for ( V_46 = 0 ; V_46 < V_203 ; V_46 ++ ) {
V_39 = & V_7 -> V_133 [ V_46 ] -> V_12 ;
V_208 = V_39 -> V_223 ;
if ( V_39 -> V_24 == - 1 )
break;
if ( ! F_166 ( V_39 -> V_24 , V_208 -> V_225 ) )
break;
if ( F_166 ( V_39 -> V_24 , V_219 ) )
break;
F_167 ( V_39 -> V_24 , V_219 ) ;
if ( V_218 )
V_218 [ V_46 ] = V_39 -> V_24 ;
}
if ( V_46 != V_203 )
V_158 = F_168 ( V_7 -> V_133 , V_203 ,
V_221 , V_222 , V_218 ) ;
if ( ! V_218 || V_158 ) {
for ( V_46 = 0 ; V_46 < V_203 ; V_46 ++ )
F_160 ( V_7 , V_7 -> V_133 [ V_46 ] ) ;
}
return V_158 ? - V_109 : 0 ;
}
static void F_169 ( struct V_2 * V_3 , int V_22 )
{
struct V_5 * V_7 = F_10 ( V_3 ) ;
int V_24 = V_3 -> V_12 . V_24 ;
if ( F_53 ( ! ( V_3 -> V_12 . V_121 & V_122 ) ) )
return;
if ( F_53 ( V_24 == - 1 || V_24 >= V_220 ) )
return;
V_3 -> V_12 . V_121 = 0 ;
V_7 -> V_190 [ V_24 ] = V_3 ;
V_7 -> V_123 ++ ;
F_167 ( V_24 , V_7 -> V_226 ) ;
F_82 ( & V_3 -> V_12 . V_126 , F_139 ( V_7 , V_3 ) ) ;
F_170 ( V_7 , V_3 ) ;
if ( V_7 -> V_123 == 1 ) {
F_171 ( V_7 ) ;
F_83 ( V_7 ) ;
}
}
static void F_172 ( struct V_2 * V_3 , int V_22 )
{
struct V_5 * V_7 = F_10 ( V_3 ) ;
struct V_38 * V_39 = & V_3 -> V_12 ;
if ( F_173 ( V_39 -> V_24 , V_7 -> V_226 ) ) {
F_174 ( V_7 , V_3 ) ;
V_7 -> V_123 -- ;
V_7 -> V_190 [ V_39 -> V_24 ] = NULL ;
F_53 ( V_39 -> V_121 & V_122 ) ;
V_39 -> V_121 |= V_122 ;
if ( V_7 -> V_123 == 0 ) {
F_175 ( V_7 ) ;
F_86 ( V_7 ) ;
}
}
if ( ( V_22 & V_127 ) && ! ( V_39 -> V_121 & V_128 ) ) {
F_87 ( V_7 , V_3 ) ;
V_39 -> V_121 |= V_128 ;
}
}
static int F_176 ( struct V_2 * V_3 , int V_22 )
{
struct V_5 * V_7 = F_10 ( V_3 ) ;
struct V_38 * V_39 = & V_3 -> V_12 ;
int V_218 [ V_220 ] ;
int V_46 , V_203 , V_158 ;
if ( ! V_7 )
return - V_129 ;
V_158 = V_203 = F_157 ( V_7 , V_3 , false ) ;
if ( V_158 < 0 )
return V_158 ;
V_39 -> V_121 = V_128 | V_122 ;
if ( ! ( V_22 & V_130 ) )
V_39 -> V_121 |= V_131 ;
V_158 = F_161 ( V_7 , V_218 , V_203 ) ;
if ( V_158 )
return V_158 ;
for ( V_46 = 0 ; V_46 < V_7 -> V_132 ; V_46 ++ ) {
V_3 = V_7 -> V_133 [ V_46 ] ;
V_39 = & V_3 -> V_12 ;
if ( V_39 -> V_24 == V_218 [ V_46 ] &&
V_39 -> V_116 == V_7 -> V_182 [ V_218 [ V_46 ] ] )
continue;
if ( V_39 -> V_121 & V_122 )
V_39 -> V_121 |= V_131 ;
F_172 ( V_3 , V_127 ) ;
}
for ( V_46 = 0 ; V_46 < V_203 ; V_46 ++ ) {
V_3 = V_7 -> V_133 [ V_46 ] ;
V_39 = & V_3 -> V_12 ;
if ( V_39 -> V_24 != V_218 [ V_46 ] ||
V_39 -> V_116 != V_7 -> V_182 [ V_218 [ V_46 ] ] )
F_131 ( V_7 , V_3 , V_218 [ V_46 ] ) ;
else if ( V_46 < V_7 -> V_132 )
continue;
if ( V_39 -> V_121 & V_131 )
continue;
F_169 ( V_3 , 0 ) ;
}
V_7 -> V_132 = V_203 ;
return 0 ;
}
static void F_177 ( struct V_2 * V_3 , int V_22 )
{
struct V_5 * V_7 = F_10 ( V_3 ) ;
int V_46 ;
F_172 ( V_3 , V_127 ) ;
for ( V_46 = 0 ; V_46 < V_7 -> V_132 ; V_46 ++ ) {
if ( V_3 == V_7 -> V_133 [ V_46 ] ) {
F_160 ( V_7 , V_3 ) ;
while ( ++ V_46 < V_7 -> V_132 )
V_7 -> V_133 [ V_46 - 1 ] = V_7 -> V_133 [ V_46 ] ;
-- V_7 -> V_132 ;
break;
}
}
V_3 -> V_12 . V_24 = - 1 ;
V_3 -> V_12 . V_116 = ~ 0ULL ;
}
static void F_178 ( struct V_2 * V_3 )
{
struct V_5 * V_7 = F_10 ( V_3 ) ;
F_87 ( V_7 , V_3 ) ;
}
static int F_179 ( struct V_1 * V_4 ,
struct V_2 * V_3 )
{
struct V_2 * V_201 = V_3 -> V_227 ;
struct V_5 * V_228 ;
int V_158 = - V_109 , V_203 ;
V_228 = F_152 ( V_4 -> type , V_229 ) ;
if ( ! V_228 )
return - V_230 ;
V_228 -> V_4 = V_4 ;
V_203 = F_157 ( V_228 , V_201 , true ) ;
if ( V_203 < 0 )
goto V_231;
V_228 -> V_132 = V_203 ;
V_203 = F_157 ( V_228 , V_3 , false ) ;
if ( V_203 < 0 )
goto V_231;
V_228 -> V_132 = V_203 ;
V_158 = F_161 ( V_228 , NULL , V_203 ) ;
V_231:
F_180 ( V_228 ) ;
return V_158 ;
}
static int F_181 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_5 * V_7 ;
struct V_38 * V_39 = & V_3 -> V_12 ;
int V_158 ;
if ( V_3 -> V_59 . type != V_3 -> V_4 -> type )
return - V_106 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 -> V_107 < 0 )
return - V_106 ;
if ( V_3 -> V_59 . V_110 || V_3 -> V_59 . V_111 ||
V_3 -> V_59 . V_112 || V_3 -> V_59 . V_113 )
return - V_109 ;
if ( V_39 -> V_108 )
return - V_109 ;
if ( V_3 -> V_6 < 0 )
return - V_109 ;
V_7 = F_3 ( V_4 , V_3 -> V_6 ) ;
if ( ! V_7 || V_7 -> V_6 < 0 )
return - V_109 ;
V_3 -> V_6 = V_7 -> V_6 ;
V_3 -> V_12 . V_24 = - 1 ;
V_3 -> V_12 . V_116 = ~ 0ULL ;
V_3 -> V_12 . V_19 . V_24 = V_25 ;
V_3 -> V_12 . V_21 . V_24 = V_25 ;
if ( V_3 -> V_59 . V_31 == V_211 ) {
if ( ! V_4 -> type -> V_206 )
return - V_109 ;
if ( V_4 -> type -> V_232 && V_4 -> V_58 > 0 )
return - V_109 ;
V_39 -> V_31 = 0ULL ;
} else {
V_39 -> V_31 = V_3 -> V_59 . V_31 & V_4 -> type -> V_144 ;
if ( V_4 -> type -> V_209 -> V_233 ) {
V_158 = V_4 -> type -> V_209 -> V_233 ( V_7 , V_3 ) ;
if ( V_158 )
return V_158 ;
}
}
if ( V_3 -> V_227 != V_3 )
V_158 = F_179 ( V_4 , V_3 ) ;
else
V_158 = 0 ;
return V_158 ;
}
static T_4 F_182 ( struct V_234 * V_134 ,
struct V_235 * V_59 , char * V_236 )
{
int V_203 = F_183 ( V_236 , V_98 - 2 , & V_237 ) ;
V_236 [ V_203 ++ ] = '\n' ;
V_236 [ V_203 ] = '\0' ;
return V_203 ;
}
static int T_5 F_184 ( struct V_1 * V_4 )
{
int V_158 ;
if ( ! V_4 -> type -> V_4 ) {
V_4 -> V_4 = (struct V_4 ) {
. V_238 = V_4 -> type -> V_238 ,
. V_239 = V_240 ,
. V_241 = F_181 ,
. V_242 = F_176 ,
. V_243 = F_177 ,
. V_244 = F_169 ,
. V_245 = F_172 ,
. V_246 = F_178 ,
} ;
} else {
V_4 -> V_4 = * V_4 -> type -> V_4 ;
V_4 -> V_4 . V_238 = V_4 -> type -> V_238 ;
}
if ( V_4 -> type -> V_247 == 1 ) {
if ( strlen ( V_4 -> type -> V_248 ) > 0 )
sprintf ( V_4 -> V_248 , L_1 , V_4 -> type -> V_248 ) ;
else
sprintf ( V_4 -> V_248 , L_2 ) ;
} else {
sprintf ( V_4 -> V_248 , L_3 , V_4 -> type -> V_248 ,
V_4 -> V_58 ) ;
}
V_158 = F_185 ( & V_4 -> V_4 , V_4 -> V_248 , - 1 ) ;
return V_158 ;
}
static void T_5 F_186 ( struct V_165 * type )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < type -> V_247 ; V_46 ++ )
F_187 ( type -> V_249 [ V_46 ] . V_7 ) ;
F_180 ( type -> V_249 ) ;
type -> V_249 = NULL ;
F_180 ( type -> V_250 ) ;
type -> V_250 = NULL ;
}
static void T_5 F_188 ( struct V_165 * * V_251 )
{
int V_46 ;
for ( V_46 = 0 ; V_251 [ V_46 ] ; V_46 ++ )
F_186 ( V_251 [ V_46 ] ) ;
}
static int T_5 F_189 ( struct V_165 * type )
{
struct V_1 * V_249 ;
struct V_252 * V_253 ;
struct V_254 * * V_255 ;
int V_46 , V_256 ;
V_249 = F_190 ( sizeof( * V_249 ) * type -> V_247 , V_199 ) ;
if ( ! V_249 )
return - V_230 ;
type -> V_249 = V_249 ;
type -> V_216 = (struct V_14 )
F_191 ( 0 , ( 1ULL << type -> V_205 ) - 1 ,
0 , type -> V_205 , 0 , 0 ) ;
for ( V_46 = 0 ; V_46 < type -> V_247 ; V_46 ++ ) {
V_249 [ V_46 ] . V_107 = - 1 ;
V_249 [ V_46 ] . V_58 = V_46 ;
V_249 [ V_46 ] . type = type ;
F_156 ( & V_249 [ V_46 ] . V_257 ) ;
V_249 [ V_46 ] . V_7 = F_192 ( struct V_5 * ) ;
if ( ! V_249 [ V_46 ] . V_7 )
goto V_49;
}
if ( type -> V_258 ) {
V_46 = 0 ;
while ( type -> V_258 [ V_46 ] . V_59 . V_59 . V_248 )
V_46 ++ ;
V_253 = F_190 ( sizeof( struct V_254 * ) * ( V_46 + 1 ) +
sizeof( * V_253 ) , V_199 ) ;
if ( ! V_253 )
goto V_49;
V_255 = (struct V_254 * * ) ( V_253 + 1 ) ;
V_253 -> V_248 = L_4 ;
V_253 -> V_255 = V_255 ;
for ( V_256 = 0 ; V_256 < V_46 ; V_256 ++ )
V_255 [ V_256 ] = & type -> V_258 [ V_256 ] . V_59 . V_59 ;
type -> V_250 = V_253 ;
}
type -> V_259 = & V_260 ;
return 0 ;
V_49:
F_186 ( type ) ;
return - V_230 ;
}
static int T_5 F_193 ( struct V_165 * * V_251 )
{
int V_46 , V_158 ;
for ( V_46 = 0 ; V_251 [ V_46 ] ; V_46 ++ ) {
V_158 = F_189 ( V_251 [ V_46 ] ) ;
if ( V_158 )
goto V_49;
}
return 0 ;
V_49:
while ( -- V_46 >= 0 )
F_186 ( V_251 [ V_46 ] ) ;
return V_158 ;
}
static int F_194 ( struct V_34 * V_35 , const struct V_261 * V_262 )
{
struct V_1 * V_4 ;
struct V_5 * V_7 ;
struct V_165 * type ;
int V_9 ;
V_9 = V_78 [ V_35 -> V_73 -> V_77 ] ;
if ( V_9 < 0 )
return - V_129 ;
if ( F_195 ( V_262 -> V_263 ) == V_264 ) {
V_70 [ V_9 ] [ F_196 ( V_262 -> V_263 ) ] = V_35 ;
F_197 ( V_35 , NULL ) ;
return 0 ;
}
type = V_265 [ F_195 ( V_262 -> V_263 ) ] ;
V_7 = F_152 ( type , V_229 ) ;
if ( ! V_7 )
return - V_230 ;
V_4 = & type -> V_249 [ F_196 ( V_262 -> V_263 ) ] ;
if ( V_4 -> V_107 < 0 )
V_4 -> V_107 = V_35 -> V_266 ;
else
F_53 ( V_4 -> V_107 != V_35 -> V_266 ) ;
V_7 -> V_9 = V_9 ;
V_7 -> V_34 = V_35 ;
V_7 -> V_4 = V_4 ;
F_198 ( V_7 ) ;
F_197 ( V_35 , V_7 ) ;
F_5 ( & V_8 ) ;
F_81 ( & V_7 -> V_267 , & V_4 -> V_257 ) ;
F_9 ( & V_8 ) ;
return 0 ;
}
static void F_199 ( struct V_34 * V_35 )
{
struct V_5 * V_7 = F_200 ( V_35 ) ;
struct V_1 * V_4 ;
int V_46 , V_6 , V_9 = V_78 [ V_35 -> V_73 -> V_77 ] ;
V_7 = F_200 ( V_35 ) ;
if ( ! V_7 ) {
for ( V_46 = 0 ; V_46 < V_268 ; V_46 ++ ) {
if ( V_70 [ V_9 ] [ V_46 ] == V_35 ) {
V_70 [ V_9 ] [ V_46 ] = NULL ;
break;
}
}
F_53 ( V_46 >= V_268 ) ;
return;
}
V_4 = V_7 -> V_4 ;
if ( F_53 ( V_9 != V_7 -> V_9 ) )
return;
F_197 ( V_35 , NULL ) ;
F_5 ( & V_8 ) ;
F_85 ( & V_7 -> V_267 ) ;
F_9 ( & V_8 ) ;
F_201 (cpu) {
if ( * F_4 ( V_4 -> V_7 , V_6 ) == V_7 ) {
* F_4 ( V_4 -> V_7 , V_6 ) = NULL ;
F_20 ( & V_7 -> V_10 ) ;
}
}
F_53 ( F_17 ( & V_7 -> V_10 ) != 1 ) ;
F_180 ( V_7 ) ;
}
static int T_5 F_202 ( void )
{
int V_158 ;
switch ( V_269 . V_270 ) {
case 45 :
V_158 = F_54 ( 0x3ce0 ) ;
if ( V_158 )
return V_158 ;
V_265 = V_271 ;
V_272 = & V_273 ;
break;
case 62 :
V_158 = F_54 ( 0x0e1e ) ;
if ( V_158 )
return V_158 ;
V_265 = V_274 ;
V_272 = & V_275 ;
break;
case 42 :
V_158 = F_90 ( V_276 ) ;
if ( V_158 )
return V_158 ;
V_265 = V_277 ;
V_272 = & V_278 ;
break;
case 58 :
V_158 = F_90 ( V_279 ) ;
if ( V_158 )
return V_158 ;
V_265 = V_277 ;
V_272 = & V_280 ;
break;
case 60 :
case 69 :
V_158 = F_90 ( V_281 ) ;
if ( V_158 )
return V_158 ;
V_265 = V_277 ;
V_272 = & V_282 ;
break;
default:
return 0 ;
}
V_158 = F_193 ( V_265 ) ;
if ( V_158 )
return V_158 ;
V_272 -> V_283 = F_194 ;
V_272 -> remove = F_199 ;
V_158 = F_203 ( V_272 ) ;
if ( V_158 == 0 )
V_284 = true ;
else
F_188 ( V_265 ) ;
return V_158 ;
}
static void T_5 F_204 ( void )
{
if ( V_284 ) {
V_284 = false ;
F_205 ( V_272 ) ;
F_188 ( V_265 ) ;
}
}
static void F_206 ( void )
{
struct V_5 * V_7 ;
while ( ! F_207 ( & V_285 ) ) {
V_7 = F_208 ( V_285 . V_286 ,
struct V_5 , V_267 ) ;
F_85 ( & V_7 -> V_267 ) ;
F_180 ( V_7 ) ;
}
}
static void F_209 ( int V_6 )
{
struct V_165 * type ;
struct V_1 * V_4 ;
struct V_5 * V_7 ;
int V_46 , V_256 ;
for ( V_46 = 0 ; V_287 [ V_46 ] ; V_46 ++ ) {
type = V_287 [ V_46 ] ;
for ( V_256 = 0 ; V_256 < type -> V_247 ; V_256 ++ ) {
V_4 = & type -> V_249 [ V_256 ] ;
V_7 = * F_4 ( V_4 -> V_7 , V_6 ) ;
* F_4 ( V_4 -> V_7 , V_6 ) = NULL ;
if ( V_7 && F_210 ( & V_7 -> V_10 ) )
F_211 ( & V_7 -> V_267 , & V_285 ) ;
}
}
}
static int F_212 ( int V_6 )
{
struct V_165 * type ;
struct V_1 * V_4 ;
struct V_5 * V_7 , * V_288 ;
int V_46 , V_256 , V_289 , V_9 ;
V_9 = F_7 ( V_6 ) ;
for ( V_46 = 0 ; V_287 [ V_46 ] ; V_46 ++ ) {
type = V_287 [ V_46 ] ;
for ( V_256 = 0 ; V_256 < type -> V_247 ; V_256 ++ ) {
V_4 = & type -> V_249 [ V_256 ] ;
V_7 = * F_4 ( V_4 -> V_7 , V_6 ) ;
if ( V_7 && V_7 -> V_9 >= 0 ) {
F_198 ( V_7 ) ;
continue;
}
F_213 (k) {
V_288 = * F_4 ( V_4 -> V_7 , V_289 ) ;
if ( V_288 && V_288 -> V_9 == V_9 ) {
F_8 ( & V_288 -> V_10 ) ;
* F_4 ( V_4 -> V_7 , V_6 ) = V_288 ;
if ( V_7 ) {
F_211 ( & V_7 -> V_267 ,
& V_285 ) ;
V_7 = NULL ;
}
break;
}
}
if ( V_7 ) {
V_7 -> V_9 = V_9 ;
F_198 ( V_7 ) ;
}
}
}
return 0 ;
}
static int F_214 ( int V_6 , int V_9 )
{
struct V_165 * type ;
struct V_1 * V_4 ;
struct V_5 * V_7 ;
int V_46 , V_256 ;
for ( V_46 = 0 ; V_287 [ V_46 ] ; V_46 ++ ) {
type = V_287 [ V_46 ] ;
for ( V_256 = 0 ; V_256 < type -> V_247 ; V_256 ++ ) {
V_4 = & type -> V_249 [ V_256 ] ;
if ( V_4 -> V_107 < 0 )
V_4 -> V_107 = V_256 ;
V_7 = F_152 ( type , F_215 ( V_6 ) ) ;
if ( ! V_7 )
return - V_230 ;
V_7 -> V_4 = V_4 ;
V_7 -> V_9 = V_9 ;
* F_4 ( V_4 -> V_7 , V_6 ) = V_7 ;
}
}
return 0 ;
}
static void
F_216 ( struct V_165 * * V_290 , int V_291 , int V_292 )
{
struct V_165 * type ;
struct V_1 * V_4 ;
struct V_5 * V_7 ;
int V_46 , V_256 ;
for ( V_46 = 0 ; V_290 [ V_46 ] ; V_46 ++ ) {
type = V_290 [ V_46 ] ;
for ( V_256 = 0 ; V_256 < type -> V_247 ; V_256 ++ ) {
V_4 = & type -> V_249 [ V_256 ] ;
if ( V_291 < 0 )
V_7 = F_3 ( V_4 , V_292 ) ;
else
V_7 = F_3 ( V_4 , V_291 ) ;
if ( ! V_7 )
continue;
if ( V_291 < 0 ) {
F_53 ( V_7 -> V_6 != - 1 ) ;
V_7 -> V_6 = V_292 ;
continue;
}
F_53 ( V_7 -> V_6 != V_291 ) ;
if ( V_292 >= 0 ) {
F_86 ( V_7 ) ;
F_217 ( & V_4 -> V_4 ,
V_291 , V_292 ) ;
V_7 -> V_6 = V_292 ;
} else {
V_7 -> V_6 = - 1 ;
}
}
}
}
static void F_218 ( int V_6 )
{
int V_46 , V_9 , V_293 ;
if ( ! F_219 ( V_6 , & V_237 ) )
return;
V_9 = F_7 ( V_6 ) ;
V_293 = - 1 ;
F_213 (i) {
if ( V_46 == V_6 )
continue;
if ( V_9 == F_7 ( V_46 ) ) {
V_293 = V_46 ;
break;
}
}
if ( V_293 >= 0 )
F_220 ( V_293 , & V_237 ) ;
F_216 ( V_287 , V_6 , V_293 ) ;
F_216 ( V_265 , V_6 , V_293 ) ;
}
static void F_221 ( int V_6 )
{
int V_46 , V_9 ;
V_9 = F_7 ( V_6 ) ;
F_222 (i, &uncore_cpu_mask) {
if ( V_9 == F_7 ( V_46 ) )
return;
}
F_220 ( V_6 , & V_237 ) ;
F_216 ( V_287 , - 1 , V_6 ) ;
F_216 ( V_265 , - 1 , V_6 ) ;
}
static int F_223 ( struct V_294 * V_295 ,
unsigned long V_296 , void * V_297 )
{
unsigned int V_6 = ( long ) V_297 ;
switch ( V_296 & ~ V_298 ) {
case V_299 :
F_214 ( V_6 , - 1 ) ;
break;
case V_300 :
F_212 ( V_6 ) ;
break;
case V_301 :
case V_302 :
F_209 ( V_6 ) ;
break;
case V_303 :
case V_304 :
F_206 () ;
break;
default:
break;
}
switch ( V_296 & ~ V_298 ) {
case V_305 :
case V_300 :
F_221 ( V_6 ) ;
break;
case V_306 :
F_218 ( V_6 ) ;
break;
default:
break;
}
return V_307 ;
}
static void T_5 F_224 ( void * V_308 )
{
F_212 ( F_11 () ) ;
}
static int T_5 F_225 ( void )
{
int V_158 , V_309 ;
V_309 = V_269 . V_310 ;
switch ( V_269 . V_270 ) {
case 26 :
case 30 :
case 37 :
case 44 :
V_287 = V_311 ;
break;
case 42 :
case 58 :
if ( V_312 . V_247 > V_309 )
V_312 . V_247 = V_309 ;
V_287 = V_313 ;
break;
case 45 :
if ( V_314 . V_247 > V_309 )
V_314 . V_247 = V_309 ;
V_287 = V_315 ;
break;
case 46 :
V_160 = true ;
case 47 :
if ( ! V_160 )
V_316 . V_258 = V_317 ;
if ( V_318 . V_247 > V_309 )
V_318 . V_247 = V_309 ;
V_287 = V_319 ;
break;
case 62 :
if ( V_320 . V_247 > V_309 )
V_320 . V_247 = V_309 ;
V_287 = V_321 ;
break;
default:
return 0 ;
}
V_158 = F_193 ( V_287 ) ;
if ( V_158 )
return V_158 ;
return 0 ;
}
static int T_5 F_226 ( void )
{
struct V_1 * V_4 ;
struct V_165 * type ;
int V_46 , V_256 ;
for ( V_46 = 0 ; V_287 [ V_46 ] ; V_46 ++ ) {
type = V_287 [ V_46 ] ;
for ( V_256 = 0 ; V_256 < type -> V_247 ; V_256 ++ ) {
V_4 = & type -> V_249 [ V_256 ] ;
F_184 ( V_4 ) ;
}
}
for ( V_46 = 0 ; V_265 [ V_46 ] ; V_46 ++ ) {
type = V_265 [ V_46 ] ;
for ( V_256 = 0 ; V_256 < type -> V_247 ; V_256 ++ ) {
V_4 = & type -> V_249 [ V_256 ] ;
F_184 ( V_4 ) ;
}
}
return 0 ;
}
static void T_5 F_227 ( void )
{
int V_6 ;
if ( ! F_228 ( & V_237 ) )
return;
F_229 () ;
F_213 (cpu) {
int V_46 , V_9 = F_7 ( V_6 ) ;
F_222 (i, &uncore_cpu_mask) {
if ( V_9 == F_7 ( V_46 ) ) {
V_9 = - 1 ;
break;
}
}
if ( V_9 < 0 )
continue;
F_214 ( V_6 , V_9 ) ;
F_221 ( V_6 ) ;
}
F_230 ( F_224 , NULL , 1 ) ;
F_231 ( & V_322 ) ;
F_232 () ;
}
static int T_5 F_233 ( void )
{
int V_158 ;
if ( V_269 . V_323 != V_324 )
return - V_129 ;
if ( V_325 )
return - V_129 ;
V_158 = F_202 () ;
if ( V_158 )
goto V_49;
V_158 = F_225 () ;
if ( V_158 ) {
F_204 () ;
goto V_49;
}
F_227 () ;
F_226 () ;
return 0 ;
V_49:
return V_158 ;
}

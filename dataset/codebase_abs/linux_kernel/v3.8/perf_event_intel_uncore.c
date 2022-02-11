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
static void F_11 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_28 ;
int V_30 = F_12 ( V_2 ) ;
T_2 V_25 = 0 ;
if ( ! F_13 ( V_29 , V_30 , & V_25 ) ) {
V_25 |= V_31 ;
F_14 ( V_29 , V_30 , V_25 ) ;
}
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_28 ;
int V_30 = F_12 ( V_2 ) ;
T_2 V_25 = 0 ;
if ( ! F_13 ( V_29 , V_30 , & V_25 ) ) {
V_25 &= ~ V_31 ;
F_14 ( V_29 , V_30 , V_25 ) ;
}
}
static void F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_28 * V_29 = V_2 -> V_28 ;
struct V_32 * V_33 = & V_4 -> V_6 ;
F_14 ( V_29 , V_33 -> V_34 , V_33 -> V_25 | V_35 ) ;
}
static void F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_28 * V_29 = V_2 -> V_28 ;
struct V_32 * V_33 = & V_4 -> V_6 ;
F_14 ( V_29 , V_33 -> V_34 , V_33 -> V_25 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_28 * V_29 = V_2 -> V_28 ;
struct V_32 * V_33 = & V_4 -> V_6 ;
T_1 V_5 = 0 ;
F_13 ( V_29 , V_33 -> V_7 , ( T_2 * ) & V_5 ) ;
F_13 ( V_29 , V_33 -> V_7 + 4 , ( T_2 * ) & V_5 + 1 ) ;
return V_5 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_28 ;
F_14 ( V_29 , V_36 , V_37 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_1 V_25 ;
unsigned V_38 ;
V_38 = F_21 ( V_2 ) ;
if ( V_38 ) {
F_2 ( V_38 , V_25 ) ;
V_25 |= V_31 ;
F_22 ( V_38 , V_25 ) ;
}
}
static void F_23 ( struct V_1 * V_2 )
{
T_1 V_25 ;
unsigned V_38 ;
V_38 = F_21 ( V_2 ) ;
if ( V_38 ) {
F_2 ( V_38 , V_25 ) ;
V_25 &= ~ V_31 ;
F_22 ( V_38 , V_25 ) ;
}
}
static void F_24 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
if ( V_12 -> V_18 != V_19 )
F_22 ( V_12 -> V_39 , V_12 -> V_25 ) ;
F_22 ( V_33 -> V_34 , V_33 -> V_25 | V_35 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
F_22 ( V_33 -> V_34 , V_33 -> V_25 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
unsigned V_38 = F_21 ( V_2 ) ;
if ( V_38 )
F_22 ( V_38 , V_37 ) ;
}
static int F_27 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
if ( V_2 -> V_40 -> type == & V_41 ) {
V_12 -> V_39 = V_42 +
V_43 * V_2 -> V_40 -> V_44 ;
V_12 -> V_25 = V_4 -> V_45 . V_24 &
V_46 ;
} else {
if ( V_2 -> V_40 -> type == & V_47 ) {
V_12 -> V_39 = V_48 ;
V_12 -> V_25 = V_4 -> V_45 . V_24 & V_49 ;
} else {
return 0 ;
}
}
V_12 -> V_18 = 0 ;
return 0 ;
}
static int F_28 ( void )
{
struct V_28 * V_50 = NULL ;
int V_51 , V_52 , V_53 ;
int V_54 = 0 ;
T_2 V_25 = 0 ;
while ( 1 ) {
V_50 = F_29 ( V_55 ,
V_56 ,
V_50 ) ;
if ( ! V_50 )
break;
V_52 = V_50 -> V_52 -> V_57 ;
V_54 = F_13 ( V_50 , 0x40 , & V_25 ) ;
if ( V_54 )
break;
V_53 = V_25 ;
V_54 = F_13 ( V_50 , 0x54 , & V_25 ) ;
if ( V_54 )
break;
for ( V_51 = 0 ; V_51 < 8 ; V_51 ++ ) {
if ( V_53 == ( ( V_25 >> ( 3 * V_51 ) ) & 0x7 ) ) {
V_58 [ V_52 ] = V_51 ;
break;
}
}
} ;
if ( V_50 )
F_30 ( V_50 ) ;
return V_54 ? F_31 ( V_54 ) : 0 ;
}
static void F_32 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 < V_59 )
F_22 ( V_33 -> V_34 , V_33 -> V_25 | V_60 ) ;
else
F_22 ( V_33 -> V_34 , V_60 ) ;
}
static void F_33 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_22 ( V_4 -> V_6 . V_34 , 0 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
if ( V_2 -> V_40 -> V_44 == 0 ) {
F_22 ( V_61 ,
V_62 | V_63 ) ;
}
}
static void F_35 ( struct V_1 * V_2 )
{
F_22 ( V_64 , 0 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_22 ( V_64 , V_65 | V_66 ) ;
}
static void F_37 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 < V_59 )
F_22 ( V_33 -> V_34 , V_33 -> V_25 | V_60 ) ;
else
F_22 ( V_33 -> V_34 , V_67 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_22 ( V_68 , V_69 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
unsigned V_38 = F_21 ( V_2 ) ;
T_1 V_25 ;
if ( V_38 ) {
F_2 ( V_38 , V_25 ) ;
V_25 &= ~ ( ( 1ULL << F_40 ( V_2 ) ) - 1 ) ;
if ( F_41 ( V_2 ) )
V_25 &= ~ V_70 ;
F_22 ( V_38 , V_25 ) ;
}
}
static void F_42 ( struct V_1 * V_2 )
{
unsigned V_38 = F_21 ( V_2 ) ;
T_1 V_25 ;
if ( V_38 ) {
F_2 ( V_38 , V_25 ) ;
V_25 |= ( 1ULL << F_40 ( V_2 ) ) - 1 ;
if ( F_41 ( V_2 ) )
V_25 |= V_70 ;
F_22 ( V_38 , V_25 ) ;
}
}
static void F_43 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_22 ( V_4 -> V_6 . V_34 , 0 ) ;
}
static void F_44 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 >= V_59 )
F_22 ( V_33 -> V_34 , V_71 ) ;
else if ( V_2 -> V_40 -> type -> V_72 & V_71 )
F_22 ( V_33 -> V_34 , V_33 -> V_25 | V_73 ) ;
else
F_22 ( V_33 -> V_34 , V_33 -> V_25 | V_71 ) ;
}
static int F_45 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
int V_74 , V_75 ;
V_74 = ( V_33 -> V_25 & V_76 ) >>
V_77 ;
V_75 = ( V_33 -> V_25 & V_78 ) >>
V_79 ;
if ( ( V_74 == 0 && V_75 > 0x3 ) || ( V_74 == 1 && V_75 > 0x6 ) ||
( V_74 == 2 && V_75 != 0x4 ) || V_74 == 3 )
return 0 ;
if ( V_2 -> V_40 -> V_44 == 0 )
V_12 -> V_39 = V_80 ;
else
V_12 -> V_39 = V_81 ;
V_12 -> V_18 = 0 ;
V_12 -> V_25 = V_4 -> V_45 . V_24 ;
V_14 -> V_25 = V_4 -> V_45 . V_26 ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
if ( V_12 -> V_18 != V_19 ) {
F_22 ( V_12 -> V_39 , V_12 -> V_25 ) ;
F_22 ( V_12 -> V_39 + 1 , V_14 -> V_25 ) ;
}
F_22 ( V_33 -> V_34 , V_71 |
( V_33 -> V_25 & V_78 ) ) ;
}
static int F_47 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
if ( ( V_33 -> V_25 & V_82 ) !=
V_83 )
return 0 ;
if ( V_2 -> V_40 -> V_44 == 0 )
V_12 -> V_39 = V_84 ;
else
V_12 -> V_39 = V_85 ;
V_12 -> V_18 = 0 ;
V_12 -> V_25 = V_4 -> V_45 . V_24 ;
V_14 -> V_25 = V_4 -> V_45 . V_26 ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
if ( V_12 -> V_18 != V_19 ) {
F_22 ( V_12 -> V_39 , 0 ) ;
F_22 ( V_12 -> V_39 + 1 , V_12 -> V_25 ) ;
F_22 ( V_12 -> V_39 + 2 , V_14 -> V_25 ) ;
F_22 ( V_12 -> V_39 , V_86 ) ;
}
F_22 ( V_33 -> V_34 , V_33 -> V_25 | V_73 ) ;
}
static bool F_49 ( struct V_1 * V_2 , int V_18 , T_1 V_25 )
{
struct V_9 * V_10 ;
unsigned long V_16 ;
bool V_87 = false ;
T_1 V_88 ;
if ( V_18 < V_89 ) {
V_10 = & V_2 -> V_21 [ V_18 ] ;
F_5 ( & V_10 -> V_22 , V_16 ) ;
if ( ! F_6 ( & V_10 -> V_23 ) || V_10 -> V_25 == V_25 ) {
F_7 ( & V_10 -> V_23 ) ;
V_10 -> V_25 = V_25 ;
V_87 = true ;
}
F_8 ( & V_10 -> V_22 , V_16 ) ;
return V_87 ;
}
V_18 -= V_89 ;
if ( F_50 ( V_18 >= 4 ) )
return false ;
if ( V_90 )
V_88 = V_91 ;
else
V_88 = V_92 ;
V_10 = & V_2 -> V_21 [ V_89 ] ;
F_5 ( & V_10 -> V_22 , V_16 ) ;
if ( F_51 ( F_6 ( & V_10 -> V_23 ) , V_18 , 8 ) ) {
if ( V_90 )
V_88 |= F_52 ( V_18 ) ;
else
V_88 |= F_53 ( V_18 ) ;
}
if ( ! F_6 ( & V_10 -> V_23 ) || ! ( ( V_10 -> V_25 ^ V_25 ) & V_88 ) ) {
F_54 ( 1 << ( V_18 * 8 ) , & V_10 -> V_23 ) ;
if ( V_90 )
V_88 = V_91 |
F_52 ( V_18 ) ;
else
V_88 = V_92 |
F_53 ( V_18 ) ;
V_10 -> V_25 &= ~ V_88 ;
V_10 -> V_25 |= ( V_25 & V_88 ) ;
V_87 = true ;
}
F_8 ( & V_10 -> V_22 , V_16 ) ;
return V_87 ;
}
static void F_55 ( struct V_1 * V_2 , int V_18 )
{
struct V_9 * V_10 ;
if ( V_18 < V_89 ) {
V_10 = & V_2 -> V_21 [ V_18 ] ;
F_10 ( & V_10 -> V_23 ) ;
return;
}
V_18 -= V_89 ;
V_10 = & V_2 -> V_21 [ V_89 ] ;
F_56 ( 1 << ( V_18 * 8 ) , & V_10 -> V_23 ) ;
}
T_1 F_57 ( struct V_3 * V_4 , int V_93 , bool V_94 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
int V_18 , V_95 = F_51 ( V_12 -> V_18 , 0 , 8 ) ;
T_1 V_25 = V_12 -> V_25 ;
V_18 = V_95 - V_89 ;
if ( V_90 )
V_25 &= F_52 ( V_18 ) ;
else
V_25 &= F_53 ( V_18 ) ;
if ( V_93 > V_95 ) {
V_18 = V_93 - V_95 ;
V_25 <<= 3 * V_18 ;
} else {
V_18 = V_95 - V_93 ;
V_25 >>= 3 * V_18 ;
}
if ( V_90 )
V_25 |= V_91 & V_12 -> V_25 ;
else
V_25 |= V_92 & V_12 -> V_25 ;
V_25 |= V_91 & V_12 -> V_25 ;
if ( V_94 ) {
if ( V_93 > V_95 )
V_33 -> V_25 += V_18 << V_96 ;
else
V_33 -> V_25 -= V_18 << V_96 ;
V_12 -> V_25 = V_25 ;
V_12 -> V_18 = ~ 0xff | V_93 ;
}
return V_25 ;
}
static struct V_8 *
F_58 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_11 * V_14 = & V_4 -> V_6 . V_15 ;
int V_51 , V_18 [ 2 ] , V_20 = 0 ;
T_1 V_24 = V_12 -> V_25 ;
V_18 [ 0 ] = F_51 ( V_12 -> V_18 , 0 , 8 ) ;
V_18 [ 1 ] = F_51 ( V_12 -> V_18 , 1 , 8 ) ;
V_97:
for ( V_51 = 0 ; V_51 < 2 ; V_51 ++ ) {
if ( ! F_4 ( V_2 ) && ( V_12 -> V_20 & ( 0x1 << V_51 ) ) )
V_18 [ V_51 ] = 0xff ;
if ( V_18 [ V_51 ] == 0xff )
continue;
if ( ! F_49 ( V_2 , V_18 [ V_51 ] ,
F_51 ( V_24 , V_51 , 32 ) ) )
goto V_98;
V_20 |= ( 0x1 << V_51 ) ;
}
if ( V_14 -> V_18 != V_19 &&
( F_4 ( V_2 ) || ! V_14 -> V_20 ) &&
! F_49 ( V_2 , V_14 -> V_18 , V_14 -> V_25 ) )
goto V_98;
if ( ! F_4 ( V_2 ) ) {
if ( V_18 [ 0 ] != 0xff && V_18 [ 0 ] != F_51 ( V_12 -> V_18 , 0 , 8 ) )
F_57 ( V_4 , V_18 [ 0 ] , true ) ;
V_12 -> V_20 |= V_20 ;
if ( V_14 -> V_18 != V_19 )
V_14 -> V_20 = 1 ;
}
return NULL ;
V_98:
if ( V_18 [ 0 ] != 0xff && ! ( V_20 & 0x1 ) &&
V_18 [ 0 ] >= V_89 ) {
F_59 ( F_51 ( V_12 -> V_18 , 1 , 8 ) != 0xff ) ;
V_18 [ 0 ] -= V_89 ;
V_18 [ 0 ] = ( V_18 [ 0 ] + 1 ) % 4 ;
V_18 [ 0 ] += V_89 ;
if ( V_18 [ 0 ] != F_51 ( V_12 -> V_18 , 0 , 8 ) ) {
V_24 = F_57 ( V_4 , V_18 [ 0 ] , false ) ;
goto V_97;
}
}
if ( V_20 & 0x1 )
F_55 ( V_2 , V_18 [ 0 ] ) ;
if ( V_20 & 0x2 )
F_55 ( V_2 , V_18 [ 1 ] ) ;
return & V_27 ;
}
static void F_60 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_11 * V_14 = & V_4 -> V_6 . V_15 ;
if ( F_4 ( V_2 ) )
return;
if ( V_12 -> V_20 & 0x1 )
F_55 ( V_2 , F_51 ( V_12 -> V_18 , 0 , 8 ) ) ;
if ( V_12 -> V_20 & 0x2 )
F_55 ( V_2 , F_51 ( V_12 -> V_18 , 1 , 8 ) ) ;
V_12 -> V_20 = 0 ;
if ( V_14 -> V_20 ) {
F_55 ( V_2 , V_14 -> V_18 ) ;
V_14 -> V_20 = 0 ;
}
}
static int F_61 ( struct V_13 * V_10 )
{
if ( V_10 -> V_18 < V_89 )
return V_10 -> V_18 ;
return V_10 -> V_18 + ( V_10 -> V_4 >> V_96 ) - 0xd ;
}
static int F_62 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_99 * type = V_2 -> V_40 -> type ;
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_11 * V_14 = & V_4 -> V_6 . V_15 ;
struct V_13 * V_10 ;
unsigned V_38 ;
int V_100 = 0 ;
for ( V_10 = V_101 ; V_10 -> V_38 ; V_10 ++ ) {
if ( V_10 -> V_4 != ( V_4 -> V_6 . V_25 & V_10 -> V_102 ) )
continue;
if ( V_4 -> V_45 . V_24 & ~ V_10 -> V_103 )
return - V_104 ;
V_38 = V_10 -> V_38 + type -> V_105 * V_2 -> V_40 -> V_44 ;
if ( F_50 ( V_38 >= 0xffff || V_10 -> V_18 >= 0xff ) )
return - V_104 ;
if ( V_10 -> V_18 == V_106 )
V_100 = 1 ;
else if ( F_50 ( V_100 > 0 ) )
return - V_104 ;
V_12 -> V_18 &= ~ ( 0xff << ( V_100 * 8 ) ) ;
V_12 -> V_39 &= ~ ( 0xffff << ( V_100 * 16 ) ) ;
V_12 -> V_18 |= F_61 ( V_10 ) << ( V_100 * 8 ) ;
V_12 -> V_39 |= V_38 << ( V_100 * 16 ) ;
V_12 -> V_25 = V_4 -> V_45 . V_24 ;
V_100 ++ ;
}
if ( V_100 == 2 ) {
V_14 -> V_18 = V_107 ;
if ( V_4 -> V_45 . V_26 & V_108 )
V_14 -> V_25 = V_4 -> V_45 . V_26 ;
else
V_14 -> V_25 = ~ 0ULL ;
if ( V_2 -> V_40 -> V_44 == 0 )
V_14 -> V_39 = V_109 ;
else
V_14 -> V_39 = V_110 ;
}
return 0 ;
}
static T_1 F_63 ( struct V_1 * V_2 , int V_18 )
{
struct V_9 * V_10 ;
unsigned long V_16 ;
T_1 V_25 ;
if ( V_18 < V_89 )
return V_2 -> V_21 [ V_18 ] . V_25 ;
V_10 = & V_2 -> V_21 [ V_89 ] ;
F_5 ( & V_10 -> V_22 , V_16 ) ;
V_25 = V_10 -> V_25 ;
F_8 ( & V_10 -> V_22 , V_16 ) ;
return V_25 ;
}
static void F_64 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
int V_18 ;
V_18 = F_51 ( V_12 -> V_18 , 0 , 8 ) ;
if ( V_18 != 0xff )
F_22 ( F_51 ( V_12 -> V_39 , 0 , 16 ) ,
F_63 ( V_2 , V_18 ) ) ;
V_18 = F_51 ( V_12 -> V_18 , 1 , 8 ) ;
if ( V_18 != 0xff )
F_22 ( F_51 ( V_12 -> V_39 , 1 , 16 ) ,
F_63 ( V_2 , V_18 ) ) ;
if ( V_14 -> V_18 != V_19 ) {
F_22 ( V_14 -> V_39 , 0 ) ;
if ( V_14 -> V_25 != ~ 0ULL ) {
F_22 ( V_14 -> V_39 + 1 ,
V_14 -> V_25 & V_111 ) ;
F_22 ( V_14 -> V_39 + 2 , V_112 &
( V_14 -> V_25 >> V_113 ) ) ;
F_22 ( V_14 -> V_39 , V_108 ) ;
}
}
F_22 ( V_33 -> V_34 , V_33 -> V_25 | V_71 ) ;
}
void F_65 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
if ( V_12 -> V_18 % 2 ) {
V_12 -> V_18 -- ;
V_33 -> V_25 -= 1 << V_114 ;
} else {
V_12 -> V_18 ++ ;
V_33 -> V_25 += 1 << V_114 ;
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
F_66 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
struct V_9 * V_10 ;
unsigned long V_16 ;
int V_18 , V_115 ;
T_1 V_24 ;
bool V_17 = false ;
if ( ! F_4 ( V_2 ) && V_12 -> V_20 )
return NULL ;
V_18 = V_12 -> V_18 % 6 ;
V_24 = V_12 -> V_25 ;
V_97:
V_115 = V_18 ;
if ( V_115 > 2 )
V_115 -- ;
V_115 += ( V_12 -> V_18 / 6 ) * 5 ;
V_10 = & V_2 -> V_21 [ V_115 ] ;
F_5 ( & V_10 -> V_22 , V_16 ) ;
if ( V_18 < 2 ) {
if ( ! F_6 ( & V_10 -> V_23 ) || V_10 -> V_25 == V_12 -> V_25 ) {
F_7 ( & V_10 -> V_23 ) ;
V_10 -> V_25 = V_12 -> V_25 ;
V_17 = true ;
}
} else if ( V_18 == 2 || V_18 == 3 ) {
T_1 V_88 = 0xff << ( ( V_18 - 2 ) * 8 ) ;
if ( ! F_51 ( F_6 ( & V_10 -> V_23 ) , V_18 - 2 , 8 ) ||
! ( ( V_10 -> V_25 ^ V_24 ) & V_88 ) ) {
F_54 ( 1 << ( ( V_18 - 2 ) * 8 ) , & V_10 -> V_23 ) ;
V_10 -> V_25 &= ~ V_88 ;
V_10 -> V_25 |= V_24 & V_88 ;
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
goto V_97;
}
} else {
if ( ! F_4 ( V_2 ) ) {
if ( V_18 != V_12 -> V_18 % 6 )
F_65 ( V_2 , V_4 ) ;
V_12 -> V_20 = 1 ;
}
return NULL ;
}
return & V_27 ;
}
static void F_67 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
int V_18 , V_115 ;
if ( F_4 ( V_2 ) || ! V_12 -> V_20 )
return;
V_18 = V_12 -> V_18 % 6 ;
V_115 = V_18 ;
if ( V_115 > 2 )
V_115 -- ;
V_115 += ( V_12 -> V_18 / 6 ) * 5 ;
V_10 = & V_2 -> V_21 [ V_115 ] ;
if ( V_18 == 2 || V_18 == 3 )
F_56 ( 1 << ( ( V_18 - 2 ) * 8 ) , & V_10 -> V_23 ) ;
else
F_10 ( & V_10 -> V_23 ) ;
V_12 -> V_20 = 0 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_11 * V_14 = & V_4 -> V_6 . V_15 ;
int V_18 ;
V_18 = ( V_4 -> V_6 . V_25 & V_116 ) >>
V_114 ;
if ( V_18 >= 0x18 )
return - V_104 ;
V_12 -> V_18 = V_18 ;
V_12 -> V_25 = V_4 -> V_45 . V_24 ;
switch ( V_18 % 6 ) {
case 4 :
case 5 :
V_33 -> V_25 |= V_4 -> V_45 . V_25 & ( ~ 0ULL << 32 ) ;
V_14 -> V_25 = V_4 -> V_45 . V_26 ;
break;
} ;
return 0 ;
}
static T_1 F_69 ( struct V_1 * V_2 , int V_18 )
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
static void F_70 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
int V_18 , V_117 ;
V_18 = V_12 -> V_18 ;
V_117 = V_18 / 6 + V_2 -> V_40 -> V_44 * 4 ;
switch ( V_18 % 6 ) {
case 0 :
F_22 ( F_71 ( V_117 ) , V_12 -> V_25 ) ;
break;
case 1 :
F_22 ( F_72 ( V_117 ) , V_12 -> V_25 ) ;
break;
case 2 :
case 3 :
F_22 ( F_73 ( V_117 ) ,
F_69 ( V_2 , 2 + ( V_18 / 6 ) * 5 ) ) ;
break;
case 4 :
F_22 ( F_74 ( V_117 ) ,
V_33 -> V_25 >> 32 ) ;
F_22 ( F_75 ( V_117 ) , V_12 -> V_25 ) ;
F_22 ( F_76 ( V_117 ) , V_14 -> V_25 ) ;
break;
case 5 :
F_22 ( F_77 ( V_117 ) ,
V_33 -> V_25 >> 32 ) ;
F_22 ( F_78 ( V_117 ) , V_12 -> V_25 ) ;
F_22 ( F_79 ( V_117 ) , V_14 -> V_25 ) ;
break;
} ;
F_22 ( V_33 -> V_34 , V_71 |
( V_33 -> V_25 & V_116 ) ) ;
}
static void F_80 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_18 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
V_33 -> V_18 = V_18 ;
V_33 -> V_118 = ++ V_2 -> V_119 [ V_18 ] ;
if ( V_33 -> V_18 == V_59 ) {
V_33 -> V_7 = F_81 ( V_2 ) ;
V_33 -> V_34 = F_82 ( V_2 ) ;
return;
}
V_33 -> V_34 = F_83 ( V_2 , V_33 -> V_18 ) ;
V_33 -> V_7 = F_84 ( V_2 , V_33 -> V_18 ) ;
}
static void F_85 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_120 , V_121 , V_122 ;
int V_123 ;
if ( V_4 -> V_6 . V_18 >= V_59 )
V_123 = 64 - F_86 ( V_2 ) ;
else
V_123 = 64 - F_87 ( V_2 ) ;
V_97:
V_120 = F_88 ( & V_4 -> V_6 . V_120 ) ;
V_121 = F_89 ( V_2 , V_4 ) ;
if ( F_90 ( & V_4 -> V_6 . V_120 , V_121 ) != V_120 )
goto V_97;
V_122 = ( V_121 << V_123 ) - ( V_120 << V_123 ) ;
V_122 >>= V_123 ;
F_91 ( V_122 , & V_4 -> V_5 ) ;
}
static enum V_124 F_92 ( struct V_125 * V_125 )
{
struct V_1 * V_2 ;
unsigned long V_16 ;
int V_126 ;
V_2 = F_93 ( V_125 , struct V_1 , V_125 ) ;
if ( ! V_2 -> V_127 || V_2 -> V_128 != F_94 () )
return V_129 ;
F_95 ( V_16 ) ;
F_96 (bit, box->active_mask, UNCORE_PMC_IDX_MAX)
F_85 ( V_2 , V_2 -> V_130 [ V_126 ] ) ;
F_97 ( V_16 ) ;
F_98 ( V_125 , F_99 ( V_131 ) ) ;
return V_132 ;
}
static void F_100 ( struct V_1 * V_2 )
{
F_101 ( & V_2 -> V_125 ,
F_99 ( V_131 ) , 0 ,
V_133 , 0 ) ;
}
static void F_102 ( struct V_1 * V_2 )
{
F_103 ( & V_2 -> V_125 ) ;
}
static void F_104 ( struct V_1 * V_2 )
{
F_105 ( & V_2 -> V_125 , V_134 , V_135 ) ;
V_2 -> V_125 . V_136 = F_92 ;
}
struct V_1 * F_106 ( struct V_99 * type , int V_128 )
{
struct V_1 * V_2 ;
int V_51 , V_137 ;
V_137 = sizeof( * V_2 ) + type -> V_138 * sizeof( struct V_9 ) ;
V_2 = F_107 ( V_137 , V_139 | V_140 , F_108 ( V_128 ) ) ;
if ( ! V_2 )
return NULL ;
for ( V_51 = 0 ; V_51 < type -> V_138 ; V_51 ++ )
F_109 ( & V_2 -> V_21 [ V_51 ] . V_22 ) ;
F_104 ( V_2 ) ;
F_110 ( & V_2 -> V_141 , 1 ) ;
V_2 -> V_128 = - 1 ;
V_2 -> V_142 = - 1 ;
return V_2 ;
}
static struct V_1 *
F_111 ( struct V_143 * V_40 , int V_128 )
{
struct V_1 * V_2 ;
V_2 = * F_112 ( V_40 -> V_2 , V_128 ) ;
if ( V_2 )
return V_2 ;
F_113 ( & V_144 ) ;
F_114 (box, &pmu->box_list, list) {
if ( V_2 -> V_142 == F_115 ( V_128 ) ) {
F_7 ( & V_2 -> V_141 ) ;
* F_112 ( V_40 -> V_2 , V_128 ) = V_2 ;
break;
}
}
F_116 ( & V_144 ) ;
return * F_112 ( V_40 -> V_2 , V_128 ) ;
}
static struct V_143 * F_117 ( struct V_3 * V_4 )
{
return F_93 ( V_4 -> V_40 , struct V_143 , V_40 ) ;
}
static struct V_1 * F_118 ( struct V_3 * V_4 )
{
return F_111 ( F_117 ( V_4 ) , F_94 () ) ;
}
static int
F_119 ( struct V_1 * V_2 , struct V_3 * V_145 , bool V_146 )
{
struct V_3 * V_4 ;
int V_147 , V_148 ;
V_148 = V_2 -> V_40 -> type -> V_149 ;
if ( V_2 -> V_40 -> type -> V_150 )
V_148 ++ ;
if ( V_2 -> V_151 >= V_148 )
return - V_104 ;
V_147 = V_2 -> V_151 ;
V_2 -> V_152 [ V_147 ] = V_145 ;
V_147 ++ ;
if ( ! V_146 )
return V_147 ;
F_114 (event, &leader->sibling_list, group_entry) {
if ( V_4 -> V_153 <= V_154 )
continue;
if ( V_147 >= V_148 )
return - V_104 ;
V_2 -> V_152 [ V_147 ] = V_4 ;
V_147 ++ ;
}
return V_147 ;
}
static struct V_8 *
F_120 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_99 * type = V_2 -> V_40 -> type ;
struct V_8 * V_155 ;
if ( type -> V_156 -> V_157 ) {
V_155 = type -> V_156 -> V_157 ( V_2 , V_4 ) ;
if ( V_155 )
return V_155 ;
}
if ( V_4 -> V_6 . V_25 == ~ 0ULL )
return & V_158 ;
if ( type -> V_159 ) {
F_121 (c, type->constraints) {
if ( ( V_4 -> V_6 . V_25 & V_155 -> V_160 ) == V_155 -> V_161 )
return V_155 ;
}
}
return & type -> V_162 ;
}
static void F_122 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_40 -> type -> V_156 -> V_163 )
V_2 -> V_40 -> type -> V_156 -> V_163 ( V_2 , V_4 ) ;
}
static int F_123 ( struct V_1 * V_2 , int V_164 [] , int V_147 )
{
unsigned long V_165 [ F_124 ( V_166 ) ] ;
struct V_8 * V_155 , * V_159 [ V_166 ] ;
int V_51 , V_167 , V_168 , V_87 = 0 ;
struct V_32 * V_33 ;
F_125 ( V_165 , V_166 ) ;
for ( V_51 = 0 , V_167 = V_166 , V_168 = 0 ; V_51 < V_147 ; V_51 ++ ) {
V_155 = F_120 ( V_2 , V_2 -> V_152 [ V_51 ] ) ;
V_159 [ V_51 ] = V_155 ;
V_167 = F_126 ( V_167 , V_155 -> V_169 ) ;
V_168 = F_127 ( V_168 , V_155 -> V_169 ) ;
}
for ( V_51 = 0 ; V_51 < V_147 ; V_51 ++ ) {
V_33 = & V_2 -> V_152 [ V_51 ] -> V_6 ;
V_155 = V_159 [ V_51 ] ;
if ( V_33 -> V_18 == - 1 )
break;
if ( ! F_128 ( V_33 -> V_18 , V_155 -> V_170 ) )
break;
if ( F_128 ( V_33 -> V_18 , V_165 ) )
break;
F_129 ( V_33 -> V_18 , V_165 ) ;
if ( V_164 )
V_164 [ V_51 ] = V_33 -> V_18 ;
}
if ( V_51 != V_147 )
V_87 = F_130 ( V_159 , V_147 , V_167 , V_168 , V_164 ) ;
if ( ! V_164 || V_87 ) {
for ( V_51 = 0 ; V_51 < V_147 ; V_51 ++ )
F_122 ( V_2 , V_2 -> V_152 [ V_51 ] ) ;
}
return V_87 ? - V_104 : 0 ;
}
static void F_131 ( struct V_3 * V_4 , int V_16 )
{
struct V_1 * V_2 = F_118 ( V_4 ) ;
int V_18 = V_4 -> V_6 . V_18 ;
if ( F_50 ( ! ( V_4 -> V_6 . V_153 & V_171 ) ) )
return;
if ( F_50 ( V_18 == - 1 || V_18 >= V_166 ) )
return;
V_4 -> V_6 . V_153 = 0 ;
V_2 -> V_130 [ V_18 ] = V_4 ;
V_2 -> V_127 ++ ;
F_129 ( V_18 , V_2 -> V_172 ) ;
F_132 ( & V_4 -> V_6 . V_120 , F_89 ( V_2 , V_4 ) ) ;
F_133 ( V_2 , V_4 ) ;
if ( V_2 -> V_127 == 1 ) {
F_134 ( V_2 ) ;
F_100 ( V_2 ) ;
}
}
static void F_135 ( struct V_3 * V_4 , int V_16 )
{
struct V_1 * V_2 = F_118 ( V_4 ) ;
struct V_32 * V_33 = & V_4 -> V_6 ;
if ( F_136 ( V_33 -> V_18 , V_2 -> V_172 ) ) {
F_137 ( V_2 , V_4 ) ;
V_2 -> V_127 -- ;
V_2 -> V_130 [ V_33 -> V_18 ] = NULL ;
F_50 ( V_33 -> V_153 & V_171 ) ;
V_33 -> V_153 |= V_171 ;
if ( V_2 -> V_127 == 0 ) {
F_138 ( V_2 ) ;
F_102 ( V_2 ) ;
}
}
if ( ( V_16 & V_173 ) && ! ( V_33 -> V_153 & V_174 ) ) {
F_85 ( V_2 , V_4 ) ;
V_33 -> V_153 |= V_174 ;
}
}
static int F_139 ( struct V_3 * V_4 , int V_16 )
{
struct V_1 * V_2 = F_118 ( V_4 ) ;
struct V_32 * V_33 = & V_4 -> V_6 ;
int V_164 [ V_166 ] ;
int V_51 , V_147 , V_87 ;
if ( ! V_2 )
return - V_175 ;
V_87 = V_147 = F_119 ( V_2 , V_4 , false ) ;
if ( V_87 < 0 )
return V_87 ;
V_33 -> V_153 = V_174 | V_171 ;
if ( ! ( V_16 & V_176 ) )
V_33 -> V_153 |= V_177 ;
V_87 = F_123 ( V_2 , V_164 , V_147 ) ;
if ( V_87 )
return V_87 ;
for ( V_51 = 0 ; V_51 < V_2 -> V_151 ; V_51 ++ ) {
V_4 = V_2 -> V_152 [ V_51 ] ;
V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 == V_164 [ V_51 ] &&
V_33 -> V_118 == V_2 -> V_119 [ V_164 [ V_51 ] ] )
continue;
if ( V_33 -> V_153 & V_171 )
V_33 -> V_153 |= V_177 ;
F_135 ( V_4 , V_173 ) ;
}
for ( V_51 = 0 ; V_51 < V_147 ; V_51 ++ ) {
V_4 = V_2 -> V_152 [ V_51 ] ;
V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 != V_164 [ V_51 ] ||
V_33 -> V_118 != V_2 -> V_119 [ V_164 [ V_51 ] ] )
F_80 ( V_2 , V_4 , V_164 [ V_51 ] ) ;
else if ( V_51 < V_2 -> V_151 )
continue;
if ( V_33 -> V_153 & V_177 )
continue;
F_131 ( V_4 , 0 ) ;
}
V_2 -> V_151 = V_147 ;
return 0 ;
}
static void F_140 ( struct V_3 * V_4 , int V_16 )
{
struct V_1 * V_2 = F_118 ( V_4 ) ;
int V_51 ;
F_135 ( V_4 , V_173 ) ;
for ( V_51 = 0 ; V_51 < V_2 -> V_151 ; V_51 ++ ) {
if ( V_4 == V_2 -> V_152 [ V_51 ] ) {
F_122 ( V_2 , V_4 ) ;
while ( ++ V_51 < V_2 -> V_151 )
V_2 -> V_152 [ V_51 - 1 ] = V_2 -> V_152 [ V_51 ] ;
-- V_2 -> V_151 ;
break;
}
}
V_4 -> V_6 . V_18 = - 1 ;
V_4 -> V_6 . V_118 = ~ 0ULL ;
}
static void F_141 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_118 ( V_4 ) ;
F_85 ( V_2 , V_4 ) ;
}
static int F_142 ( struct V_143 * V_40 ,
struct V_3 * V_4 )
{
struct V_3 * V_145 = V_4 -> V_178 ;
struct V_1 * V_179 ;
int V_87 = - V_104 , V_147 ;
V_179 = F_106 ( V_40 -> type , F_94 () ) ;
if ( ! V_179 )
return - V_180 ;
V_179 -> V_40 = V_40 ;
V_147 = F_119 ( V_179 , V_145 , true ) ;
if ( V_147 < 0 )
goto V_181;
V_179 -> V_151 = V_147 ;
V_147 = F_119 ( V_179 , V_4 , false ) ;
if ( V_147 < 0 )
goto V_181;
V_179 -> V_151 = V_147 ;
V_87 = F_123 ( V_179 , NULL , V_147 ) ;
V_181:
F_143 ( V_179 ) ;
return V_87 ;
}
int F_144 ( struct V_3 * V_4 )
{
struct V_143 * V_40 ;
struct V_1 * V_2 ;
struct V_32 * V_33 = & V_4 -> V_6 ;
int V_87 ;
if ( V_4 -> V_45 . type != V_4 -> V_40 -> type )
return - V_182 ;
V_40 = F_117 ( V_4 ) ;
if ( V_40 -> V_183 < 0 )
return - V_182 ;
if ( V_4 -> V_45 . V_184 || V_4 -> V_45 . V_185 ||
V_4 -> V_45 . V_186 || V_4 -> V_45 . V_187 )
return - V_104 ;
if ( V_33 -> V_188 )
return - V_104 ;
if ( V_4 -> V_128 < 0 )
return - V_104 ;
V_2 = F_111 ( V_40 , V_4 -> V_128 ) ;
if ( ! V_2 || V_2 -> V_128 < 0 )
return - V_104 ;
V_4 -> V_128 = V_2 -> V_128 ;
V_4 -> V_6 . V_18 = - 1 ;
V_4 -> V_6 . V_118 = ~ 0ULL ;
V_4 -> V_6 . V_13 . V_18 = V_19 ;
V_4 -> V_6 . V_15 . V_18 = V_19 ;
if ( V_4 -> V_45 . V_25 == V_189 ) {
if ( ! V_40 -> type -> V_150 )
return - V_104 ;
if ( V_40 -> type -> V_190 && V_40 -> V_44 > 0 )
return - V_104 ;
V_33 -> V_25 = ~ 0ULL ;
} else {
V_33 -> V_25 = V_4 -> V_45 . V_25 & V_40 -> type -> V_72 ;
if ( V_40 -> type -> V_156 -> V_191 ) {
V_87 = V_40 -> type -> V_156 -> V_191 ( V_2 , V_4 ) ;
if ( V_87 )
return V_87 ;
}
}
if ( V_4 -> V_178 != V_4 )
V_87 = F_142 ( V_40 , V_4 ) ;
else
V_87 = 0 ;
return V_87 ;
}
static T_3 F_145 ( struct V_192 * V_193 ,
struct V_194 * V_45 , char * V_195 )
{
int V_147 = F_146 ( V_195 , V_196 - 2 , & V_197 ) ;
V_195 [ V_147 ++ ] = '\n' ;
V_195 [ V_147 ] = '\0' ;
return V_147 ;
}
static int T_4 F_147 ( struct V_143 * V_40 )
{
int V_87 ;
V_40 -> V_40 = (struct V_40 ) {
. V_198 = V_40 -> type -> V_198 ,
. V_199 = V_200 ,
. V_201 = F_144 ,
. V_202 = F_139 ,
. V_203 = F_140 ,
. V_204 = F_131 ,
. V_205 = F_135 ,
. V_206 = F_141 ,
} ;
if ( V_40 -> type -> V_207 == 1 ) {
if ( strlen ( V_40 -> type -> V_208 ) > 0 )
sprintf ( V_40 -> V_208 , L_1 , V_40 -> type -> V_208 ) ;
else
sprintf ( V_40 -> V_208 , L_2 ) ;
} else {
sprintf ( V_40 -> V_208 , L_3 , V_40 -> type -> V_208 ,
V_40 -> V_44 ) ;
}
V_87 = F_148 ( & V_40 -> V_40 , V_40 -> V_208 , - 1 ) ;
return V_87 ;
}
static void T_4 F_149 ( struct V_99 * type )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < type -> V_207 ; V_51 ++ )
F_150 ( type -> V_209 [ V_51 ] . V_2 ) ;
F_143 ( type -> V_209 ) ;
type -> V_209 = NULL ;
F_143 ( type -> V_210 ) ;
type -> V_210 = NULL ;
}
static void T_4 F_151 ( struct V_99 * * V_211 )
{
int V_51 ;
for ( V_51 = 0 ; V_211 [ V_51 ] ; V_51 ++ )
F_149 ( V_211 [ V_51 ] ) ;
}
static int T_4 F_152 ( struct V_99 * type )
{
struct V_143 * V_209 ;
struct V_212 * V_210 ;
struct V_213 * * V_214 ;
int V_51 , V_215 ;
V_209 = F_153 ( sizeof( * V_209 ) * type -> V_207 , V_139 ) ;
if ( ! V_209 )
return - V_180 ;
type -> V_162 = (struct V_8 )
F_154 ( 0 , ( 1ULL << type -> V_149 ) - 1 ,
0 , type -> V_149 , 0 ) ;
for ( V_51 = 0 ; V_51 < type -> V_207 ; V_51 ++ ) {
V_209 [ V_51 ] . V_183 = - 1 ;
V_209 [ V_51 ] . V_44 = V_51 ;
V_209 [ V_51 ] . type = type ;
F_155 ( & V_209 [ V_51 ] . V_216 ) ;
V_209 [ V_51 ] . V_2 = F_156 ( struct V_1 * ) ;
if ( ! V_209 [ V_51 ] . V_2 )
goto V_98;
}
if ( type -> V_217 ) {
V_51 = 0 ;
while ( type -> V_217 [ V_51 ] . V_45 . V_45 . V_208 )
V_51 ++ ;
V_210 = F_153 ( sizeof( struct V_213 * ) * ( V_51 + 1 ) +
sizeof( * V_210 ) , V_139 ) ;
if ( ! V_210 )
goto V_98;
V_214 = (struct V_213 * * ) ( V_210 + 1 ) ;
V_210 -> V_208 = L_4 ;
V_210 -> V_214 = V_214 ;
for ( V_215 = 0 ; V_215 < V_51 ; V_215 ++ )
V_214 [ V_215 ] = & type -> V_217 [ V_215 ] . V_45 . V_45 ;
type -> V_210 = V_210 ;
}
type -> V_218 = & V_219 ;
type -> V_209 = V_209 ;
return 0 ;
V_98:
F_149 ( type ) ;
return - V_180 ;
}
static int T_4 F_157 ( struct V_99 * * V_211 )
{
int V_51 , V_87 ;
for ( V_51 = 0 ; V_211 [ V_51 ] ; V_51 ++ ) {
V_87 = F_152 ( V_211 [ V_51 ] ) ;
if ( V_87 )
goto V_98;
}
return 0 ;
V_98:
while ( -- V_51 >= 0 )
F_149 ( V_211 [ V_51 ] ) ;
return V_87 ;
}
static int F_158 ( struct V_99 * type , struct V_28 * V_29 )
{
struct V_143 * V_40 ;
struct V_1 * V_2 ;
int V_51 , V_142 ;
V_142 = V_58 [ V_29 -> V_52 -> V_57 ] ;
if ( V_142 < 0 )
return - V_175 ;
V_2 = F_106 ( type , 0 ) ;
if ( ! V_2 )
return - V_180 ;
for ( V_51 = 0 ; V_51 < type -> V_207 ; V_51 ++ ) {
V_40 = & type -> V_209 [ V_51 ] ;
if ( V_40 -> V_183 == V_29 -> V_220 )
break;
if ( V_40 -> V_183 < 0 ) {
V_40 -> V_183 = V_29 -> V_220 ;
break;
}
V_40 = NULL ;
}
if ( ! V_40 ) {
F_143 ( V_2 ) ;
return - V_104 ;
}
V_2 -> V_142 = V_142 ;
V_2 -> V_28 = V_29 ;
V_2 -> V_40 = V_40 ;
F_159 ( V_2 ) ;
F_160 ( V_29 , V_2 ) ;
F_113 ( & V_144 ) ;
F_161 ( & V_2 -> V_221 , & V_40 -> V_216 ) ;
F_116 ( & V_144 ) ;
return 0 ;
}
static void F_162 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_163 ( V_29 ) ;
struct V_143 * V_40 = V_2 -> V_40 ;
int V_128 , V_142 = V_58 [ V_29 -> V_52 -> V_57 ] ;
if ( F_50 ( V_142 != V_2 -> V_142 ) )
return;
F_113 ( & V_144 ) ;
F_164 ( & V_2 -> V_221 ) ;
F_116 ( & V_144 ) ;
F_165 (cpu) {
if ( * F_112 ( V_40 -> V_2 , V_128 ) == V_2 ) {
* F_112 ( V_40 -> V_2 , V_128 ) = NULL ;
F_10 ( & V_2 -> V_141 ) ;
}
}
F_50 ( F_6 ( & V_2 -> V_141 ) != 1 ) ;
F_143 ( V_2 ) ;
}
static int F_166 ( struct V_28 * V_29 ,
const struct V_222 * V_223 )
{
struct V_99 * type ;
type = (struct V_99 * ) V_223 -> V_224 ;
return F_158 ( type , V_29 ) ;
}
static int T_4 F_167 ( void )
{
int V_87 ;
switch ( V_225 . V_226 ) {
case 45 :
V_87 = F_28 () ;
if ( V_87 )
return V_87 ;
V_227 = V_228 ;
V_229 = & V_230 ;
break;
default:
return 0 ;
}
V_87 = F_157 ( V_227 ) ;
if ( V_87 )
return V_87 ;
V_229 -> V_231 = F_166 ;
V_229 -> remove = F_162 ;
V_87 = F_168 ( V_229 ) ;
if ( V_87 == 0 )
V_232 = true ;
else
F_151 ( V_227 ) ;
return V_87 ;
}
static void T_4 F_169 ( void )
{
if ( V_232 ) {
V_232 = false ;
F_170 ( V_229 ) ;
F_151 ( V_227 ) ;
}
}
static void T_5 F_171 ( int V_128 )
{
struct V_99 * type ;
struct V_143 * V_40 ;
struct V_1 * V_2 ;
int V_51 , V_215 ;
for ( V_51 = 0 ; V_233 [ V_51 ] ; V_51 ++ ) {
type = V_233 [ V_51 ] ;
for ( V_215 = 0 ; V_215 < type -> V_207 ; V_215 ++ ) {
V_40 = & type -> V_209 [ V_215 ] ;
V_2 = * F_112 ( V_40 -> V_2 , V_128 ) ;
* F_112 ( V_40 -> V_2 , V_128 ) = NULL ;
if ( V_2 && F_172 ( & V_2 -> V_141 ) )
F_143 ( V_2 ) ;
}
}
}
static int T_5 F_173 ( int V_128 )
{
struct V_99 * type ;
struct V_143 * V_40 ;
struct V_1 * V_2 , * V_234 ;
int V_51 , V_215 , V_235 , V_142 ;
V_142 = F_115 ( V_128 ) ;
for ( V_51 = 0 ; V_233 [ V_51 ] ; V_51 ++ ) {
type = V_233 [ V_51 ] ;
for ( V_215 = 0 ; V_215 < type -> V_207 ; V_215 ++ ) {
V_40 = & type -> V_209 [ V_215 ] ;
V_2 = * F_112 ( V_40 -> V_2 , V_128 ) ;
if ( V_2 && V_2 -> V_142 >= 0 ) {
F_159 ( V_2 ) ;
continue;
}
F_174 (k) {
V_234 = * F_112 ( V_40 -> V_2 , V_235 ) ;
if ( V_234 && V_234 -> V_142 == V_142 ) {
F_7 ( & V_234 -> V_141 ) ;
* F_112 ( V_40 -> V_2 , V_128 ) = V_234 ;
F_143 ( V_2 ) ;
V_2 = NULL ;
break;
}
}
if ( V_2 ) {
V_2 -> V_142 = V_142 ;
F_159 ( V_2 ) ;
}
}
}
return 0 ;
}
static int T_5 F_175 ( int V_128 , int V_142 )
{
struct V_99 * type ;
struct V_143 * V_40 ;
struct V_1 * V_2 ;
int V_51 , V_215 ;
for ( V_51 = 0 ; V_233 [ V_51 ] ; V_51 ++ ) {
type = V_233 [ V_51 ] ;
for ( V_215 = 0 ; V_215 < type -> V_207 ; V_215 ++ ) {
V_40 = & type -> V_209 [ V_215 ] ;
if ( V_40 -> V_183 < 0 )
V_40 -> V_183 = V_215 ;
V_2 = F_106 ( type , V_128 ) ;
if ( ! V_2 )
return - V_180 ;
V_2 -> V_40 = V_40 ;
V_2 -> V_142 = V_142 ;
* F_112 ( V_40 -> V_2 , V_128 ) = V_2 ;
}
}
return 0 ;
}
static void T_5
F_176 ( struct V_99 * * V_236 , int V_237 , int V_238 )
{
struct V_99 * type ;
struct V_143 * V_40 ;
struct V_1 * V_2 ;
int V_51 , V_215 ;
for ( V_51 = 0 ; V_236 [ V_51 ] ; V_51 ++ ) {
type = V_236 [ V_51 ] ;
for ( V_215 = 0 ; V_215 < type -> V_207 ; V_215 ++ ) {
V_40 = & type -> V_209 [ V_215 ] ;
if ( V_237 < 0 )
V_2 = F_111 ( V_40 , V_238 ) ;
else
V_2 = F_111 ( V_40 , V_237 ) ;
if ( ! V_2 )
continue;
if ( V_237 < 0 ) {
F_50 ( V_2 -> V_128 != - 1 ) ;
V_2 -> V_128 = V_238 ;
continue;
}
F_50 ( V_2 -> V_128 != V_237 ) ;
if ( V_238 >= 0 ) {
F_102 ( V_2 ) ;
F_177 ( & V_40 -> V_40 ,
V_237 , V_238 ) ;
V_2 -> V_128 = V_238 ;
} else {
V_2 -> V_128 = - 1 ;
}
}
}
}
static void T_5 F_178 ( int V_128 )
{
int V_51 , V_142 , V_239 ;
if ( ! F_179 ( V_128 , & V_197 ) )
return;
V_142 = F_115 ( V_128 ) ;
V_239 = - 1 ;
F_174 (i) {
if ( V_51 == V_128 )
continue;
if ( V_142 == F_115 ( V_51 ) ) {
V_239 = V_51 ;
break;
}
}
if ( V_239 >= 0 )
F_180 ( V_239 , & V_197 ) ;
F_176 ( V_233 , V_128 , V_239 ) ;
F_176 ( V_227 , V_128 , V_239 ) ;
}
static void T_5 F_181 ( int V_128 )
{
int V_51 , V_142 ;
V_142 = F_115 ( V_128 ) ;
F_182 (i, &uncore_cpu_mask) {
if ( V_142 == F_115 ( V_51 ) )
return;
}
F_180 ( V_128 , & V_197 ) ;
F_176 ( V_233 , - 1 , V_128 ) ;
F_176 ( V_227 , - 1 , V_128 ) ;
}
static int
T_5 F_183 ( struct V_240 * V_241 , unsigned long V_242 , void * V_243 )
{
unsigned int V_128 = ( long ) V_243 ;
switch ( V_242 & ~ V_244 ) {
case V_245 :
F_175 ( V_128 , - 1 ) ;
break;
case V_246 :
F_173 ( V_128 ) ;
break;
case V_247 :
case V_248 :
F_171 ( V_128 ) ;
break;
default:
break;
}
switch ( V_242 & ~ V_244 ) {
case V_249 :
case V_246 :
F_181 ( V_128 ) ;
break;
case V_250 :
F_178 ( V_128 ) ;
break;
default:
break;
}
return V_251 ;
}
static void T_4 F_184 ( void * V_252 )
{
F_173 ( F_94 () ) ;
}
static int T_4 F_185 ( void )
{
int V_87 , V_128 , V_253 ;
V_253 = V_225 . V_254 ;
switch ( V_225 . V_226 ) {
case 26 :
case 30 :
case 37 :
case 44 :
V_233 = V_255 ;
break;
case 42 :
if ( V_256 . V_207 > V_253 )
V_256 . V_207 = V_253 ;
V_233 = V_257 ;
break;
case 45 :
if ( V_41 . V_207 > V_253 )
V_41 . V_207 = V_253 ;
V_233 = V_258 ;
break;
case 46 :
V_90 = true ;
case 47 :
if ( ! V_90 )
V_259 . V_217 = V_260 ;
if ( V_261 . V_207 > V_253 )
V_261 . V_207 = V_253 ;
V_233 = V_262 ;
break;
default:
return 0 ;
}
V_87 = F_157 ( V_233 ) ;
if ( V_87 )
return V_87 ;
F_186 () ;
F_174 (cpu) {
int V_51 , V_142 = F_115 ( V_128 ) ;
F_182 (i, &uncore_cpu_mask) {
if ( V_142 == F_115 ( V_51 ) ) {
V_142 = - 1 ;
break;
}
}
if ( V_142 < 0 )
continue;
F_175 ( V_128 , V_142 ) ;
F_181 ( V_128 ) ;
}
F_187 ( F_184 , NULL , 1 ) ;
F_188 ( & V_263 ) ;
F_189 () ;
return 0 ;
}
static int T_4 F_190 ( void )
{
struct V_143 * V_40 ;
struct V_99 * type ;
int V_51 , V_215 ;
for ( V_51 = 0 ; V_233 [ V_51 ] ; V_51 ++ ) {
type = V_233 [ V_51 ] ;
for ( V_215 = 0 ; V_215 < type -> V_207 ; V_215 ++ ) {
V_40 = & type -> V_209 [ V_215 ] ;
F_147 ( V_40 ) ;
}
}
for ( V_51 = 0 ; V_227 [ V_51 ] ; V_51 ++ ) {
type = V_227 [ V_51 ] ;
for ( V_215 = 0 ; V_215 < type -> V_207 ; V_215 ++ ) {
V_40 = & type -> V_209 [ V_215 ] ;
F_147 ( V_40 ) ;
}
}
return 0 ;
}
static int T_4 F_191 ( void )
{
int V_87 ;
if ( V_225 . V_264 != V_265 )
return - V_175 ;
if ( V_266 )
return - V_175 ;
V_87 = F_167 () ;
if ( V_87 )
goto V_98;
V_87 = F_185 () ;
if ( V_87 ) {
F_169 () ;
goto V_98;
}
F_190 () ;
return 0 ;
V_98:
return V_87 ;
}

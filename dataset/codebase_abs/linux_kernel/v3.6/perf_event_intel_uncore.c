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
T_2 V_25 ;
F_13 ( V_29 , V_30 , & V_25 ) ;
V_25 |= V_31 ;
F_14 ( V_29 , V_30 , V_25 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_28 ;
int V_30 = F_12 ( V_2 ) ;
T_2 V_25 ;
F_13 ( V_29 , V_30 , & V_25 ) ;
V_25 &= ~ V_31 ;
F_14 ( V_29 , V_30 , V_25 ) ;
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
T_1 V_5 ;
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
static void F_28 ( void )
{
struct V_28 * V_50 = NULL ;
int V_51 , V_52 , V_53 ;
T_2 V_25 ;
while ( 1 ) {
V_50 = F_29 ( V_54 ,
V_55 ,
V_50 ) ;
if ( ! V_50 )
break;
V_52 = V_50 -> V_52 -> V_56 ;
F_13 ( V_50 , 0x40 , & V_25 ) ;
V_53 = V_25 ;
F_13 ( V_50 , 0x54 , & V_25 ) ;
for ( V_51 = 0 ; V_51 < 8 ; V_51 ++ ) {
if ( V_53 == ( ( V_25 >> ( 3 * V_51 ) ) & 0x7 ) ) {
V_57 [ V_52 ] = V_51 ;
break;
}
}
} ;
return;
}
static void F_30 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 < V_58 )
F_22 ( V_33 -> V_34 , V_33 -> V_25 | V_59 ) ;
else
F_22 ( V_33 -> V_34 , V_59 ) ;
}
static void F_31 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_22 ( V_4 -> V_6 . V_34 , 0 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
if ( V_2 -> V_40 -> V_44 == 0 ) {
F_22 ( V_60 ,
V_61 | V_62 ) ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
F_22 ( V_63 , 0 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_22 ( V_63 , V_64 | V_65 ) ;
}
static void F_35 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 < V_58 )
F_22 ( V_33 -> V_34 , V_33 -> V_25 | V_59 ) ;
else
F_22 ( V_33 -> V_34 , V_66 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_22 ( V_67 , V_68 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
unsigned V_38 = F_21 ( V_2 ) ;
T_1 V_25 ;
if ( V_38 ) {
F_2 ( V_38 , V_25 ) ;
V_25 &= ~ ( ( 1ULL << F_38 ( V_2 ) ) - 1 ) ;
if ( F_39 ( V_2 ) )
V_25 &= ~ V_69 ;
F_22 ( V_38 , V_25 ) ;
}
}
static void F_40 ( struct V_1 * V_2 )
{
unsigned V_38 = F_21 ( V_2 ) ;
T_1 V_25 ;
if ( V_38 ) {
F_2 ( V_38 , V_25 ) ;
V_25 |= ( 1ULL << F_38 ( V_2 ) ) - 1 ;
if ( F_39 ( V_2 ) )
V_25 |= V_69 ;
F_22 ( V_38 , V_25 ) ;
}
}
static void F_41 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_22 ( V_4 -> V_6 . V_34 , 0 ) ;
}
static void F_42 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 >= V_58 )
F_22 ( V_33 -> V_34 , V_70 ) ;
else if ( V_2 -> V_40 -> type -> V_71 & V_70 )
F_22 ( V_33 -> V_34 , V_33 -> V_25 | V_72 ) ;
else
F_22 ( V_33 -> V_34 , V_33 -> V_25 | V_70 ) ;
}
static int F_43 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
int V_73 , V_74 ;
V_73 = ( V_33 -> V_25 & V_75 ) >>
V_76 ;
V_74 = ( V_33 -> V_25 & V_77 ) >>
V_78 ;
if ( ( V_73 == 0 && V_74 > 0x3 ) || ( V_73 == 1 && V_74 > 0x6 ) ||
( V_73 == 2 && V_74 != 0x4 ) || V_73 == 3 )
return 0 ;
if ( V_2 -> V_40 -> V_44 == 0 )
V_12 -> V_39 = V_79 ;
else
V_12 -> V_39 = V_80 ;
V_12 -> V_18 = 0 ;
V_12 -> V_25 = V_4 -> V_45 . V_24 ;
V_14 -> V_25 = V_4 -> V_45 . V_26 ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
if ( V_12 -> V_18 != V_19 ) {
F_22 ( V_12 -> V_39 , V_12 -> V_25 ) ;
F_22 ( V_12 -> V_39 + 1 , V_14 -> V_25 ) ;
}
F_22 ( V_33 -> V_34 , V_70 |
( V_33 -> V_25 & V_77 ) ) ;
}
static int F_45 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
if ( ( V_33 -> V_25 & V_81 ) !=
V_82 )
return 0 ;
if ( V_2 -> V_40 -> V_44 == 0 )
V_12 -> V_39 = V_83 ;
else
V_12 -> V_39 = V_84 ;
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
F_22 ( V_12 -> V_39 , 0 ) ;
F_22 ( V_12 -> V_39 + 1 , V_12 -> V_25 ) ;
F_22 ( V_12 -> V_39 + 2 , V_14 -> V_25 ) ;
F_22 ( V_12 -> V_39 , V_85 ) ;
}
F_22 ( V_33 -> V_34 , V_33 -> V_25 | V_72 ) ;
}
static bool F_47 ( struct V_1 * V_2 , int V_18 , T_1 V_25 )
{
struct V_9 * V_10 ;
unsigned long V_16 ;
bool V_86 = false ;
T_1 V_87 ;
if ( V_18 < V_88 ) {
V_10 = & V_2 -> V_21 [ V_18 ] ;
F_5 ( & V_10 -> V_22 , V_16 ) ;
if ( ! F_6 ( & V_10 -> V_23 ) || V_10 -> V_25 == V_25 ) {
F_7 ( & V_10 -> V_23 ) ;
V_10 -> V_25 = V_25 ;
V_86 = true ;
}
F_8 ( & V_10 -> V_22 , V_16 ) ;
return V_86 ;
}
V_18 -= V_88 ;
if ( F_48 ( V_18 >= 4 ) )
return false ;
if ( V_89 )
V_87 = V_90 ;
else
V_87 = V_91 ;
V_10 = & V_2 -> V_21 [ V_88 ] ;
F_5 ( & V_10 -> V_22 , V_16 ) ;
if ( F_49 ( F_6 ( & V_10 -> V_23 ) , V_18 , 8 ) ) {
if ( V_89 )
V_87 |= F_50 ( V_18 ) ;
else
V_87 |= F_51 ( V_18 ) ;
}
if ( ! F_6 ( & V_10 -> V_23 ) || ! ( ( V_10 -> V_25 ^ V_25 ) & V_87 ) ) {
F_52 ( 1 << ( V_18 * 8 ) , & V_10 -> V_23 ) ;
if ( V_89 )
V_87 = V_90 |
F_50 ( V_18 ) ;
else
V_87 = V_91 |
F_51 ( V_18 ) ;
V_10 -> V_25 &= ~ V_87 ;
V_10 -> V_25 |= ( V_25 & V_87 ) ;
V_86 = true ;
}
F_8 ( & V_10 -> V_22 , V_16 ) ;
return V_86 ;
}
static void F_53 ( struct V_1 * V_2 , int V_18 )
{
struct V_9 * V_10 ;
if ( V_18 < V_88 ) {
V_10 = & V_2 -> V_21 [ V_18 ] ;
F_10 ( & V_10 -> V_23 ) ;
return;
}
V_18 -= V_88 ;
V_10 = & V_2 -> V_21 [ V_88 ] ;
F_54 ( 1 << ( V_18 * 8 ) , & V_10 -> V_23 ) ;
}
T_1 F_55 ( struct V_3 * V_4 , int V_92 , bool V_93 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
int V_18 , V_94 = F_49 ( V_12 -> V_18 , 0 , 8 ) ;
T_1 V_25 = V_12 -> V_25 ;
V_18 = V_94 - V_88 ;
if ( V_89 )
V_25 &= F_50 ( V_18 ) ;
else
V_25 &= F_51 ( V_18 ) ;
if ( V_92 > V_94 ) {
V_18 = V_92 - V_94 ;
V_25 <<= 3 * V_18 ;
} else {
V_18 = V_94 - V_92 ;
V_25 >>= 3 * V_18 ;
}
if ( V_89 )
V_25 |= V_90 & V_12 -> V_25 ;
else
V_25 |= V_91 & V_12 -> V_25 ;
V_25 |= V_90 & V_12 -> V_25 ;
if ( V_93 ) {
if ( V_92 > V_94 )
V_33 -> V_25 += V_18 << V_95 ;
else
V_33 -> V_25 -= V_18 << V_95 ;
V_12 -> V_25 = V_25 ;
V_12 -> V_18 = ~ 0xff | V_92 ;
}
return V_25 ;
}
static struct V_8 *
F_56 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_11 * V_14 = & V_4 -> V_6 . V_15 ;
int V_51 , V_18 [ 2 ] , V_20 = 0 ;
T_1 V_24 = V_12 -> V_25 ;
V_18 [ 0 ] = F_49 ( V_12 -> V_18 , 0 , 8 ) ;
V_18 [ 1 ] = F_49 ( V_12 -> V_18 , 1 , 8 ) ;
V_96:
for ( V_51 = 0 ; V_51 < 2 ; V_51 ++ ) {
if ( ! F_4 ( V_2 ) && ( V_12 -> V_20 & ( 0x1 << V_51 ) ) )
V_18 [ V_51 ] = 0xff ;
if ( V_18 [ V_51 ] == 0xff )
continue;
if ( ! F_47 ( V_2 , V_18 [ V_51 ] ,
F_49 ( V_24 , V_51 , 32 ) ) )
goto V_97;
V_20 |= ( 0x1 << V_51 ) ;
}
if ( V_14 -> V_18 != V_19 &&
( F_4 ( V_2 ) || ! V_14 -> V_20 ) &&
! F_47 ( V_2 , V_14 -> V_18 , V_14 -> V_25 ) )
goto V_97;
if ( ! F_4 ( V_2 ) ) {
if ( V_18 [ 0 ] != 0xff && V_18 [ 0 ] != F_49 ( V_12 -> V_18 , 0 , 8 ) )
F_55 ( V_4 , V_18 [ 0 ] , true ) ;
V_12 -> V_20 |= V_20 ;
if ( V_14 -> V_18 != V_19 )
V_14 -> V_20 = 1 ;
}
return NULL ;
V_97:
if ( V_18 [ 0 ] != 0xff && ! ( V_20 & 0x1 ) &&
V_18 [ 0 ] >= V_88 ) {
F_57 ( F_49 ( V_12 -> V_18 , 1 , 8 ) != 0xff ) ;
V_18 [ 0 ] -= V_88 ;
V_18 [ 0 ] = ( V_18 [ 0 ] + 1 ) % 4 ;
V_18 [ 0 ] += V_88 ;
if ( V_18 [ 0 ] != F_49 ( V_12 -> V_18 , 0 , 8 ) ) {
V_24 = F_55 ( V_4 , V_18 [ 0 ] , false ) ;
goto V_96;
}
}
if ( V_20 & 0x1 )
F_53 ( V_2 , V_18 [ 0 ] ) ;
if ( V_20 & 0x2 )
F_53 ( V_2 , V_18 [ 1 ] ) ;
return & V_27 ;
}
static void F_58 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_11 * V_14 = & V_4 -> V_6 . V_15 ;
if ( F_4 ( V_2 ) )
return;
if ( V_12 -> V_20 & 0x1 )
F_53 ( V_2 , F_49 ( V_12 -> V_18 , 0 , 8 ) ) ;
if ( V_12 -> V_20 & 0x2 )
F_53 ( V_2 , F_49 ( V_12 -> V_18 , 1 , 8 ) ) ;
V_12 -> V_20 = 0 ;
if ( V_14 -> V_20 ) {
F_53 ( V_2 , V_14 -> V_18 ) ;
V_14 -> V_20 = 0 ;
}
}
static int F_59 ( struct V_13 * V_10 )
{
if ( V_10 -> V_18 < V_88 )
return V_10 -> V_18 ;
return V_10 -> V_18 + ( V_10 -> V_4 >> V_95 ) - 0xd ;
}
static int F_60 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_98 * type = V_2 -> V_40 -> type ;
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_11 * V_14 = & V_4 -> V_6 . V_15 ;
struct V_13 * V_10 ;
unsigned V_38 ;
int V_99 = 0 ;
for ( V_10 = V_100 ; V_10 -> V_38 ; V_10 ++ ) {
if ( V_10 -> V_4 != ( V_4 -> V_6 . V_25 & V_10 -> V_101 ) )
continue;
if ( V_4 -> V_45 . V_24 & ~ V_10 -> V_102 )
return - V_103 ;
V_38 = V_10 -> V_38 + type -> V_104 * V_2 -> V_40 -> V_44 ;
if ( F_48 ( V_38 >= 0xffff || V_10 -> V_18 >= 0xff ) )
return - V_103 ;
if ( V_10 -> V_18 == V_105 )
V_99 = 1 ;
else if ( F_48 ( V_99 > 0 ) )
return - V_103 ;
V_12 -> V_18 &= ~ ( 0xff << ( V_99 * 8 ) ) ;
V_12 -> V_39 &= ~ ( 0xffff << ( V_99 * 16 ) ) ;
V_12 -> V_18 |= F_59 ( V_10 ) << ( V_99 * 8 ) ;
V_12 -> V_39 |= V_38 << ( V_99 * 16 ) ;
V_12 -> V_25 = V_4 -> V_45 . V_24 ;
V_99 ++ ;
}
if ( V_99 == 2 ) {
V_14 -> V_18 = V_106 ;
if ( V_4 -> V_45 . V_26 & V_107 )
V_14 -> V_25 = V_4 -> V_45 . V_26 ;
else
V_14 -> V_25 = ~ 0ULL ;
if ( V_2 -> V_40 -> V_44 == 0 )
V_14 -> V_39 = V_108 ;
else
V_14 -> V_39 = V_109 ;
}
return 0 ;
}
static T_1 F_61 ( struct V_1 * V_2 , int V_18 )
{
struct V_9 * V_10 ;
unsigned long V_16 ;
T_1 V_25 ;
if ( V_18 < V_88 )
return V_2 -> V_21 [ V_18 ] . V_25 ;
V_10 = & V_2 -> V_21 [ V_88 ] ;
F_5 ( & V_10 -> V_22 , V_16 ) ;
V_25 = V_10 -> V_25 ;
F_8 ( & V_10 -> V_22 , V_16 ) ;
return V_25 ;
}
static void F_62 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
int V_18 ;
V_18 = F_49 ( V_12 -> V_18 , 0 , 8 ) ;
if ( V_18 != 0xff )
F_22 ( F_49 ( V_12 -> V_39 , 0 , 16 ) ,
F_61 ( V_2 , V_18 ) ) ;
V_18 = F_49 ( V_12 -> V_18 , 1 , 8 ) ;
if ( V_18 != 0xff )
F_22 ( F_49 ( V_12 -> V_39 , 1 , 16 ) ,
F_61 ( V_2 , V_18 ) ) ;
if ( V_14 -> V_18 != V_19 ) {
F_22 ( V_14 -> V_39 , 0 ) ;
if ( V_14 -> V_25 != ~ 0ULL ) {
F_22 ( V_14 -> V_39 + 1 ,
V_14 -> V_25 & V_110 ) ;
F_22 ( V_14 -> V_39 + 2 , V_111 &
( V_14 -> V_25 >> V_112 ) ) ;
F_22 ( V_14 -> V_39 , V_107 ) ;
}
}
F_22 ( V_33 -> V_34 , V_33 -> V_25 | V_70 ) ;
}
void F_63 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
int V_113 ;
if ( V_12 -> V_18 % 2 ) {
V_12 -> V_18 -- ;
V_33 -> V_25 -= 1 << V_114 ;
} else {
V_12 -> V_18 ++ ;
V_33 -> V_25 += 1 << V_114 ;
}
V_113 = V_12 -> V_18 / 6 + V_2 -> V_40 -> V_44 * 4 ;
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
F_64 ( struct V_1 * V_2 , struct V_3 * V_4 )
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
V_96:
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
T_1 V_87 = 0xff << ( ( V_18 - 2 ) * 8 ) ;
if ( ! F_49 ( F_6 ( & V_10 -> V_23 ) , V_18 - 2 , 8 ) ||
! ( ( V_10 -> V_25 ^ V_24 ) & V_87 ) ) {
F_52 ( 1 << ( ( V_18 - 2 ) * 8 ) , & V_10 -> V_23 ) ;
V_10 -> V_25 &= ~ V_87 ;
V_10 -> V_25 |= V_24 & V_87 ;
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
goto V_96;
}
} else {
if ( ! F_4 ( V_2 ) ) {
if ( V_18 != V_12 -> V_18 % 6 )
F_63 ( V_2 , V_4 ) ;
V_12 -> V_20 = 1 ;
}
return NULL ;
}
return & V_27 ;
}
static void F_65 ( struct V_1 * V_2 , struct V_3 * V_4 )
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
F_54 ( 1 << ( ( V_18 - 2 ) * 8 ) , & V_10 -> V_23 ) ;
else
F_10 ( & V_10 -> V_23 ) ;
V_12 -> V_20 = 0 ;
}
static int F_66 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_4 -> V_6 . V_13 ;
struct V_11 * V_14 = & V_4 -> V_6 . V_15 ;
int V_18 ;
V_18 = ( V_4 -> V_6 . V_25 & V_116 ) >>
V_114 ;
if ( V_18 >= 0x18 )
return - V_103 ;
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
static T_1 F_67 ( struct V_1 * V_2 , int V_18 )
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
static void F_68 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
struct V_11 * V_12 = & V_33 -> V_13 ;
struct V_11 * V_14 = & V_33 -> V_15 ;
int V_18 , V_113 ;
V_18 = V_12 -> V_18 ;
V_113 = V_18 / 6 + V_2 -> V_40 -> V_44 * 4 ;
switch ( V_18 % 6 ) {
case 0 :
F_22 ( F_69 ( V_113 ) , V_12 -> V_25 ) ;
break;
case 1 :
F_22 ( F_70 ( V_113 ) , V_12 -> V_25 ) ;
break;
case 2 :
case 3 :
F_22 ( F_71 ( V_113 ) ,
F_67 ( V_2 , 2 + ( V_18 / 6 ) * 5 ) ) ;
break;
case 4 :
F_22 ( F_72 ( V_113 ) ,
V_33 -> V_25 >> 32 ) ;
F_22 ( F_73 ( V_113 ) , V_12 -> V_25 ) ;
F_22 ( F_74 ( V_113 ) , V_14 -> V_25 ) ;
break;
case 5 :
F_22 ( F_75 ( V_113 ) ,
V_33 -> V_25 >> 32 ) ;
F_22 ( F_76 ( V_113 ) , V_12 -> V_25 ) ;
F_22 ( F_77 ( V_113 ) , V_14 -> V_25 ) ;
break;
} ;
F_22 ( V_33 -> V_34 , V_70 |
( V_33 -> V_25 & V_116 ) ) ;
}
static void F_78 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_18 )
{
struct V_32 * V_33 = & V_4 -> V_6 ;
V_33 -> V_18 = V_18 ;
V_33 -> V_117 = ++ V_2 -> V_118 [ V_18 ] ;
if ( V_33 -> V_18 == V_58 ) {
V_33 -> V_7 = F_79 ( V_2 ) ;
V_33 -> V_34 = F_80 ( V_2 ) ;
return;
}
V_33 -> V_34 = F_81 ( V_2 , V_33 -> V_18 ) ;
V_33 -> V_7 = F_82 ( V_2 , V_33 -> V_18 ) ;
}
static void F_83 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_119 , V_120 , V_121 ;
int V_122 ;
if ( V_4 -> V_6 . V_18 >= V_58 )
V_122 = 64 - F_84 ( V_2 ) ;
else
V_122 = 64 - F_85 ( V_2 ) ;
V_96:
V_119 = F_86 ( & V_4 -> V_6 . V_119 ) ;
V_120 = F_87 ( V_2 , V_4 ) ;
if ( F_88 ( & V_4 -> V_6 . V_119 , V_120 ) != V_119 )
goto V_96;
V_121 = ( V_120 << V_122 ) - ( V_119 << V_122 ) ;
V_121 >>= V_122 ;
F_89 ( V_121 , & V_4 -> V_5 ) ;
}
static enum V_123 F_90 ( struct V_124 * V_124 )
{
struct V_1 * V_2 ;
unsigned long V_16 ;
int V_125 ;
V_2 = F_91 ( V_124 , struct V_1 , V_124 ) ;
if ( ! V_2 -> V_126 || V_2 -> V_127 != F_92 () )
return V_128 ;
F_93 ( V_16 ) ;
F_94 (bit, box->active_mask, UNCORE_PMC_IDX_MAX)
F_83 ( V_2 , V_2 -> V_129 [ V_125 ] ) ;
F_95 ( V_16 ) ;
F_96 ( V_124 , F_97 ( V_130 ) ) ;
return V_131 ;
}
static void F_98 ( struct V_1 * V_2 )
{
F_99 ( & V_2 -> V_124 ,
F_97 ( V_130 ) , 0 ,
V_132 , 0 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
F_101 ( & V_2 -> V_124 ) ;
}
static void F_102 ( struct V_1 * V_2 )
{
F_103 ( & V_2 -> V_124 , V_133 , V_134 ) ;
V_2 -> V_124 . V_135 = F_90 ;
}
struct V_1 * F_104 ( struct V_98 * type , int V_127 )
{
struct V_1 * V_2 ;
int V_51 , V_136 ;
V_136 = sizeof( * V_2 ) + type -> V_137 * sizeof( struct V_9 ) ;
V_2 = F_105 ( V_136 , V_138 | V_139 , F_106 ( V_127 ) ) ;
if ( ! V_2 )
return NULL ;
for ( V_51 = 0 ; V_51 < type -> V_137 ; V_51 ++ )
F_107 ( & V_2 -> V_21 [ V_51 ] . V_22 ) ;
F_102 ( V_2 ) ;
F_108 ( & V_2 -> V_140 , 1 ) ;
V_2 -> V_127 = - 1 ;
V_2 -> V_141 = - 1 ;
return V_2 ;
}
static struct V_1 *
F_109 ( struct V_142 * V_40 , int V_127 )
{
static struct V_1 * V_2 ;
V_2 = * F_110 ( V_40 -> V_2 , V_127 ) ;
if ( V_2 )
return V_2 ;
F_111 ( & V_143 ) ;
F_112 (box, &pmu->box_list, list) {
if ( V_2 -> V_141 == F_113 ( V_127 ) ) {
F_7 ( & V_2 -> V_140 ) ;
* F_110 ( V_40 -> V_2 , V_127 ) = V_2 ;
break;
}
}
F_114 ( & V_143 ) ;
return * F_110 ( V_40 -> V_2 , V_127 ) ;
}
static struct V_142 * F_115 ( struct V_3 * V_4 )
{
return F_91 ( V_4 -> V_40 , struct V_142 , V_40 ) ;
}
static struct V_1 * F_116 ( struct V_3 * V_4 )
{
return F_109 ( F_115 ( V_4 ) , F_92 () ) ;
}
static int
F_117 ( struct V_1 * V_2 , struct V_3 * V_144 , bool V_145 )
{
struct V_3 * V_4 ;
int V_146 , V_147 ;
V_147 = V_2 -> V_40 -> type -> V_148 ;
if ( V_2 -> V_40 -> type -> V_149 )
V_147 ++ ;
if ( V_2 -> V_150 >= V_147 )
return - V_103 ;
V_146 = V_2 -> V_150 ;
V_2 -> V_151 [ V_146 ] = V_144 ;
V_146 ++ ;
if ( ! V_145 )
return V_146 ;
F_112 (event, &leader->sibling_list, group_entry) {
if ( V_4 -> V_152 <= V_153 )
continue;
if ( V_146 >= V_147 )
return - V_103 ;
V_2 -> V_151 [ V_146 ] = V_4 ;
V_146 ++ ;
}
return V_146 ;
}
static struct V_8 *
F_118 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_98 * type = V_2 -> V_40 -> type ;
struct V_8 * V_154 ;
if ( type -> V_155 -> V_156 ) {
V_154 = type -> V_155 -> V_156 ( V_2 , V_4 ) ;
if ( V_154 )
return V_154 ;
}
if ( V_4 -> V_6 . V_25 == ~ 0ULL )
return & V_157 ;
if ( type -> V_158 ) {
F_119 (c, type->constraints) {
if ( ( V_4 -> V_6 . V_25 & V_154 -> V_159 ) == V_154 -> V_160 )
return V_154 ;
}
}
return & type -> V_161 ;
}
static void F_120 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_40 -> type -> V_155 -> V_162 )
V_2 -> V_40 -> type -> V_155 -> V_162 ( V_2 , V_4 ) ;
}
static int F_121 ( struct V_1 * V_2 , int V_163 [] , int V_146 )
{
unsigned long V_164 [ F_122 ( V_165 ) ] ;
struct V_8 * V_154 , * V_158 [ V_165 ] ;
int V_51 , V_166 , V_167 , V_86 = 0 ;
struct V_32 * V_33 ;
F_123 ( V_164 , V_165 ) ;
for ( V_51 = 0 , V_166 = V_165 , V_167 = 0 ; V_51 < V_146 ; V_51 ++ ) {
V_154 = F_118 ( V_2 , V_2 -> V_151 [ V_51 ] ) ;
V_158 [ V_51 ] = V_154 ;
V_166 = F_124 ( V_166 , V_154 -> V_168 ) ;
V_167 = F_125 ( V_167 , V_154 -> V_168 ) ;
}
for ( V_51 = 0 ; V_51 < V_146 ; V_51 ++ ) {
V_33 = & V_2 -> V_151 [ V_51 ] -> V_6 ;
V_154 = V_158 [ V_51 ] ;
if ( V_33 -> V_18 == - 1 )
break;
if ( ! F_126 ( V_33 -> V_18 , V_154 -> V_169 ) )
break;
if ( F_126 ( V_33 -> V_18 , V_164 ) )
break;
F_127 ( V_33 -> V_18 , V_164 ) ;
if ( V_163 )
V_163 [ V_51 ] = V_33 -> V_18 ;
}
if ( V_51 != V_146 )
V_86 = F_128 ( V_158 , V_146 , V_166 , V_167 , V_163 ) ;
if ( ! V_163 || V_86 ) {
for ( V_51 = 0 ; V_51 < V_146 ; V_51 ++ )
F_120 ( V_2 , V_2 -> V_151 [ V_51 ] ) ;
}
return V_86 ? - V_103 : 0 ;
}
static void F_129 ( struct V_3 * V_4 , int V_16 )
{
struct V_1 * V_2 = F_116 ( V_4 ) ;
int V_18 = V_4 -> V_6 . V_18 ;
if ( F_48 ( ! ( V_4 -> V_6 . V_152 & V_170 ) ) )
return;
if ( F_48 ( V_18 == - 1 || V_18 >= V_165 ) )
return;
V_4 -> V_6 . V_152 = 0 ;
V_2 -> V_129 [ V_18 ] = V_4 ;
V_2 -> V_126 ++ ;
F_127 ( V_18 , V_2 -> V_171 ) ;
F_130 ( & V_4 -> V_6 . V_119 , F_87 ( V_2 , V_4 ) ) ;
F_131 ( V_2 , V_4 ) ;
if ( V_2 -> V_126 == 1 ) {
F_132 ( V_2 ) ;
F_98 ( V_2 ) ;
}
}
static void F_133 ( struct V_3 * V_4 , int V_16 )
{
struct V_1 * V_2 = F_116 ( V_4 ) ;
struct V_32 * V_33 = & V_4 -> V_6 ;
if ( F_134 ( V_33 -> V_18 , V_2 -> V_171 ) ) {
F_135 ( V_2 , V_4 ) ;
V_2 -> V_126 -- ;
V_2 -> V_129 [ V_33 -> V_18 ] = NULL ;
F_48 ( V_33 -> V_152 & V_170 ) ;
V_33 -> V_152 |= V_170 ;
if ( V_2 -> V_126 == 0 ) {
F_136 ( V_2 ) ;
F_100 ( V_2 ) ;
}
}
if ( ( V_16 & V_172 ) && ! ( V_33 -> V_152 & V_173 ) ) {
F_83 ( V_2 , V_4 ) ;
V_33 -> V_152 |= V_173 ;
}
}
static int F_137 ( struct V_3 * V_4 , int V_16 )
{
struct V_1 * V_2 = F_116 ( V_4 ) ;
struct V_32 * V_33 = & V_4 -> V_6 ;
int V_163 [ V_165 ] ;
int V_51 , V_146 , V_86 ;
if ( ! V_2 )
return - V_174 ;
V_86 = V_146 = F_117 ( V_2 , V_4 , false ) ;
if ( V_86 < 0 )
return V_86 ;
V_33 -> V_152 = V_173 | V_170 ;
if ( ! ( V_16 & V_175 ) )
V_33 -> V_152 |= V_176 ;
V_86 = F_121 ( V_2 , V_163 , V_146 ) ;
if ( V_86 )
return V_86 ;
for ( V_51 = 0 ; V_51 < V_2 -> V_150 ; V_51 ++ ) {
V_4 = V_2 -> V_151 [ V_51 ] ;
V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 == V_163 [ V_51 ] &&
V_33 -> V_117 == V_2 -> V_118 [ V_163 [ V_51 ] ] )
continue;
if ( V_33 -> V_152 & V_170 )
V_33 -> V_152 |= V_176 ;
F_133 ( V_4 , V_172 ) ;
}
for ( V_51 = 0 ; V_51 < V_146 ; V_51 ++ ) {
V_4 = V_2 -> V_151 [ V_51 ] ;
V_33 = & V_4 -> V_6 ;
if ( V_33 -> V_18 != V_163 [ V_51 ] ||
V_33 -> V_117 != V_2 -> V_118 [ V_163 [ V_51 ] ] )
F_78 ( V_2 , V_4 , V_163 [ V_51 ] ) ;
else if ( V_51 < V_2 -> V_150 )
continue;
if ( V_33 -> V_152 & V_176 )
continue;
F_129 ( V_4 , 0 ) ;
}
V_2 -> V_150 = V_146 ;
return 0 ;
}
static void F_138 ( struct V_3 * V_4 , int V_16 )
{
struct V_1 * V_2 = F_116 ( V_4 ) ;
int V_51 ;
F_133 ( V_4 , V_172 ) ;
for ( V_51 = 0 ; V_51 < V_2 -> V_150 ; V_51 ++ ) {
if ( V_4 == V_2 -> V_151 [ V_51 ] ) {
F_120 ( V_2 , V_4 ) ;
while ( ++ V_51 < V_2 -> V_150 )
V_2 -> V_151 [ V_51 - 1 ] = V_2 -> V_151 [ V_51 ] ;
-- V_2 -> V_150 ;
break;
}
}
V_4 -> V_6 . V_18 = - 1 ;
V_4 -> V_6 . V_117 = ~ 0ULL ;
}
static void F_139 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_116 ( V_4 ) ;
F_83 ( V_2 , V_4 ) ;
}
static int F_140 ( struct V_142 * V_40 ,
struct V_3 * V_4 )
{
struct V_3 * V_144 = V_4 -> V_177 ;
struct V_1 * V_178 ;
int V_86 = - V_103 , V_146 ;
V_178 = F_104 ( V_40 -> type , F_92 () ) ;
if ( ! V_178 )
return - V_179 ;
V_178 -> V_40 = V_40 ;
V_146 = F_117 ( V_178 , V_144 , true ) ;
if ( V_146 < 0 )
goto V_180;
V_178 -> V_150 = V_146 ;
V_146 = F_117 ( V_178 , V_4 , false ) ;
if ( V_146 < 0 )
goto V_180;
V_178 -> V_150 = V_146 ;
V_86 = F_121 ( V_178 , NULL , V_146 ) ;
V_180:
F_141 ( V_178 ) ;
return V_86 ;
}
int F_142 ( struct V_3 * V_4 )
{
struct V_142 * V_40 ;
struct V_1 * V_2 ;
struct V_32 * V_33 = & V_4 -> V_6 ;
int V_86 ;
if ( V_4 -> V_45 . type != V_4 -> V_40 -> type )
return - V_181 ;
V_40 = F_115 ( V_4 ) ;
if ( V_40 -> V_182 < 0 )
return - V_181 ;
if ( V_4 -> V_45 . V_183 || V_4 -> V_45 . V_184 ||
V_4 -> V_45 . V_185 || V_4 -> V_45 . V_186 )
return - V_103 ;
if ( V_33 -> V_187 )
return - V_103 ;
if ( V_4 -> V_127 < 0 )
return - V_103 ;
V_2 = F_109 ( V_40 , V_4 -> V_127 ) ;
if ( ! V_2 || V_2 -> V_127 < 0 )
return - V_103 ;
V_4 -> V_127 = V_2 -> V_127 ;
V_4 -> V_6 . V_18 = - 1 ;
V_4 -> V_6 . V_117 = ~ 0ULL ;
V_4 -> V_6 . V_13 . V_18 = V_19 ;
V_4 -> V_6 . V_15 . V_18 = V_19 ;
if ( V_4 -> V_45 . V_25 == V_188 ) {
if ( ! V_40 -> type -> V_149 )
return - V_103 ;
if ( V_40 -> type -> V_189 && V_40 -> V_44 > 0 )
return - V_103 ;
V_33 -> V_25 = ~ 0ULL ;
} else {
V_33 -> V_25 = V_4 -> V_45 . V_25 & V_40 -> type -> V_71 ;
if ( V_40 -> type -> V_155 -> V_190 ) {
V_86 = V_40 -> type -> V_155 -> V_190 ( V_2 , V_4 ) ;
if ( V_86 )
return V_86 ;
}
}
if ( V_4 -> V_177 != V_4 )
V_86 = F_140 ( V_40 , V_4 ) ;
else
V_86 = 0 ;
return V_86 ;
}
static int T_3 F_143 ( struct V_142 * V_40 )
{
int V_86 ;
V_40 -> V_40 = (struct V_40 ) {
. V_191 = V_40 -> type -> V_191 ,
. V_192 = V_193 ,
. V_194 = F_142 ,
. V_195 = F_137 ,
. V_196 = F_138 ,
. V_197 = F_129 ,
. V_198 = F_133 ,
. V_199 = F_139 ,
} ;
if ( V_40 -> type -> V_200 == 1 ) {
if ( strlen ( V_40 -> type -> V_201 ) > 0 )
sprintf ( V_40 -> V_201 , L_1 , V_40 -> type -> V_201 ) ;
else
sprintf ( V_40 -> V_201 , L_2 ) ;
} else {
sprintf ( V_40 -> V_201 , L_3 , V_40 -> type -> V_201 ,
V_40 -> V_44 ) ;
}
V_86 = F_144 ( & V_40 -> V_40 , V_40 -> V_201 , - 1 ) ;
return V_86 ;
}
static void T_3 F_145 ( struct V_98 * type )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < type -> V_200 ; V_51 ++ )
F_146 ( type -> V_202 [ V_51 ] . V_2 ) ;
F_141 ( type -> V_202 ) ;
type -> V_202 = NULL ;
F_141 ( type -> V_191 [ 1 ] ) ;
type -> V_191 [ 1 ] = NULL ;
}
static void T_3 F_147 ( struct V_98 * * V_203 )
{
int V_51 ;
for ( V_51 = 0 ; V_203 [ V_51 ] ; V_51 ++ )
F_145 ( V_203 [ V_51 ] ) ;
}
static int T_3 F_148 ( struct V_98 * type )
{
struct V_142 * V_202 ;
struct V_204 * V_205 ;
struct V_206 * * V_207 ;
int V_51 , V_208 ;
V_202 = F_149 ( sizeof( * V_202 ) * type -> V_200 , V_138 ) ;
if ( ! V_202 )
return - V_179 ;
type -> V_161 = (struct V_8 )
F_150 ( 0 , ( 1ULL << type -> V_148 ) - 1 ,
0 , type -> V_148 , 0 ) ;
for ( V_51 = 0 ; V_51 < type -> V_200 ; V_51 ++ ) {
V_202 [ V_51 ] . V_182 = - 1 ;
V_202 [ V_51 ] . V_44 = V_51 ;
V_202 [ V_51 ] . type = type ;
F_151 ( & V_202 [ V_51 ] . V_209 ) ;
V_202 [ V_51 ] . V_2 = F_152 ( struct V_1 * ) ;
if ( ! V_202 [ V_51 ] . V_2 )
goto V_97;
}
if ( type -> V_210 ) {
V_51 = 0 ;
while ( type -> V_210 [ V_51 ] . V_45 . V_45 . V_201 )
V_51 ++ ;
V_205 = F_149 ( sizeof( struct V_206 * ) * ( V_51 + 1 ) +
sizeof( * V_205 ) , V_138 ) ;
if ( ! V_205 )
goto V_97;
V_207 = (struct V_206 * * ) ( V_205 + 1 ) ;
V_205 -> V_201 = L_4 ;
V_205 -> V_207 = V_207 ;
for ( V_208 = 0 ; V_208 < V_51 ; V_208 ++ )
V_207 [ V_208 ] = & type -> V_210 [ V_208 ] . V_45 . V_45 ;
type -> V_191 [ 1 ] = V_205 ;
}
type -> V_202 = V_202 ;
return 0 ;
V_97:
F_145 ( type ) ;
return - V_179 ;
}
static int T_3 F_153 ( struct V_98 * * V_203 )
{
int V_51 , V_86 ;
for ( V_51 = 0 ; V_203 [ V_51 ] ; V_51 ++ ) {
V_86 = F_148 ( V_203 [ V_51 ] ) ;
if ( V_86 )
goto V_97;
}
return 0 ;
V_97:
while ( -- V_51 >= 0 )
F_145 ( V_203 [ V_51 ] ) ;
return V_86 ;
}
static int T_4 F_154 ( struct V_98 * type , struct V_28 * V_29 )
{
struct V_142 * V_40 ;
struct V_1 * V_2 ;
int V_51 , V_141 ;
V_141 = V_57 [ V_29 -> V_52 -> V_56 ] ;
if ( V_141 < 0 )
return - V_174 ;
V_2 = F_104 ( type , 0 ) ;
if ( ! V_2 )
return - V_179 ;
for ( V_51 = 0 ; V_51 < type -> V_200 ; V_51 ++ ) {
V_40 = & type -> V_202 [ V_51 ] ;
if ( V_40 -> V_182 == V_29 -> V_211 )
break;
if ( V_40 -> V_182 < 0 ) {
V_40 -> V_182 = V_29 -> V_211 ;
break;
}
V_40 = NULL ;
}
if ( ! V_40 ) {
F_141 ( V_2 ) ;
return - V_103 ;
}
V_2 -> V_141 = V_141 ;
V_2 -> V_28 = V_29 ;
V_2 -> V_40 = V_40 ;
F_155 ( V_2 ) ;
F_156 ( V_29 , V_2 ) ;
F_111 ( & V_143 ) ;
F_157 ( & V_2 -> V_212 , & V_40 -> V_209 ) ;
F_114 ( & V_143 ) ;
return 0 ;
}
static void F_158 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = F_159 ( V_29 ) ;
struct V_142 * V_40 = V_2 -> V_40 ;
int V_127 , V_141 = V_57 [ V_29 -> V_52 -> V_56 ] ;
if ( F_48 ( V_141 != V_2 -> V_141 ) )
return;
F_111 ( & V_143 ) ;
F_160 ( & V_2 -> V_212 ) ;
F_114 ( & V_143 ) ;
F_161 (cpu) {
if ( * F_110 ( V_40 -> V_2 , V_127 ) == V_2 ) {
* F_110 ( V_40 -> V_2 , V_127 ) = NULL ;
F_10 ( & V_2 -> V_140 ) ;
}
}
F_48 ( F_6 ( & V_2 -> V_140 ) != 1 ) ;
F_141 ( V_2 ) ;
}
static int T_4 F_162 ( struct V_28 * V_29 ,
const struct V_213 * V_214 )
{
struct V_98 * type ;
type = (struct V_98 * ) V_214 -> V_215 ;
return F_154 ( type , V_29 ) ;
}
static int T_3 F_163 ( void )
{
int V_86 ;
switch ( V_216 . V_217 ) {
case 45 :
V_218 = V_219 ;
V_220 = & V_221 ;
F_28 () ;
break;
default:
return 0 ;
}
V_86 = F_153 ( V_218 ) ;
if ( V_86 )
return V_86 ;
V_220 -> V_222 = F_162 ;
V_220 -> remove = F_158 ;
V_86 = F_164 ( V_220 ) ;
if ( V_86 == 0 )
V_223 = true ;
else
F_147 ( V_218 ) ;
return V_86 ;
}
static void T_3 F_165 ( void )
{
if ( V_223 ) {
V_223 = false ;
F_166 ( V_220 ) ;
F_147 ( V_218 ) ;
}
}
static void T_5 F_167 ( int V_127 )
{
struct V_98 * type ;
struct V_142 * V_40 ;
struct V_1 * V_2 ;
int V_51 , V_208 ;
for ( V_51 = 0 ; V_224 [ V_51 ] ; V_51 ++ ) {
type = V_224 [ V_51 ] ;
for ( V_208 = 0 ; V_208 < type -> V_200 ; V_208 ++ ) {
V_40 = & type -> V_202 [ V_208 ] ;
V_2 = * F_110 ( V_40 -> V_2 , V_127 ) ;
* F_110 ( V_40 -> V_2 , V_127 ) = NULL ;
if ( V_2 && F_168 ( & V_2 -> V_140 ) )
F_141 ( V_2 ) ;
}
}
}
static int T_5 F_169 ( int V_127 )
{
struct V_98 * type ;
struct V_142 * V_40 ;
struct V_1 * V_2 , * V_225 ;
int V_51 , V_208 , V_226 , V_141 ;
V_141 = F_113 ( V_127 ) ;
for ( V_51 = 0 ; V_224 [ V_51 ] ; V_51 ++ ) {
type = V_224 [ V_51 ] ;
for ( V_208 = 0 ; V_208 < type -> V_200 ; V_208 ++ ) {
V_40 = & type -> V_202 [ V_208 ] ;
V_2 = * F_110 ( V_40 -> V_2 , V_127 ) ;
if ( V_2 && V_2 -> V_141 >= 0 ) {
F_155 ( V_2 ) ;
continue;
}
F_170 (k) {
V_225 = * F_110 ( V_40 -> V_2 , V_226 ) ;
if ( V_225 && V_225 -> V_141 == V_141 ) {
F_7 ( & V_225 -> V_140 ) ;
* F_110 ( V_40 -> V_2 , V_127 ) = V_225 ;
F_141 ( V_2 ) ;
V_2 = NULL ;
break;
}
}
if ( V_2 ) {
V_2 -> V_141 = V_141 ;
F_155 ( V_2 ) ;
}
}
}
return 0 ;
}
static int T_5 F_171 ( int V_127 , int V_141 )
{
struct V_98 * type ;
struct V_142 * V_40 ;
struct V_1 * V_2 ;
int V_51 , V_208 ;
for ( V_51 = 0 ; V_224 [ V_51 ] ; V_51 ++ ) {
type = V_224 [ V_51 ] ;
for ( V_208 = 0 ; V_208 < type -> V_200 ; V_208 ++ ) {
V_40 = & type -> V_202 [ V_208 ] ;
if ( V_40 -> V_182 < 0 )
V_40 -> V_182 = V_208 ;
V_2 = F_104 ( type , V_127 ) ;
if ( ! V_2 )
return - V_179 ;
V_2 -> V_40 = V_40 ;
V_2 -> V_141 = V_141 ;
* F_110 ( V_40 -> V_2 , V_127 ) = V_2 ;
}
}
return 0 ;
}
static void T_5
F_172 ( struct V_98 * * V_227 , int V_228 , int V_229 )
{
struct V_98 * type ;
struct V_142 * V_40 ;
struct V_1 * V_2 ;
int V_51 , V_208 ;
for ( V_51 = 0 ; V_227 [ V_51 ] ; V_51 ++ ) {
type = V_227 [ V_51 ] ;
for ( V_208 = 0 ; V_208 < type -> V_200 ; V_208 ++ ) {
V_40 = & type -> V_202 [ V_208 ] ;
if ( V_228 < 0 )
V_2 = F_109 ( V_40 , V_229 ) ;
else
V_2 = F_109 ( V_40 , V_228 ) ;
if ( ! V_2 )
continue;
if ( V_228 < 0 ) {
F_48 ( V_2 -> V_127 != - 1 ) ;
V_2 -> V_127 = V_229 ;
continue;
}
F_48 ( V_2 -> V_127 != V_228 ) ;
if ( V_229 >= 0 ) {
F_100 ( V_2 ) ;
F_173 ( & V_40 -> V_40 ,
V_228 , V_229 ) ;
V_2 -> V_127 = V_229 ;
} else {
V_2 -> V_127 = - 1 ;
}
}
}
}
static void T_5 F_174 ( int V_127 )
{
int V_51 , V_141 , V_230 ;
if ( ! F_175 ( V_127 , & V_231 ) )
return;
V_141 = F_113 ( V_127 ) ;
V_230 = - 1 ;
F_170 (i) {
if ( V_51 == V_127 )
continue;
if ( V_141 == F_113 ( V_51 ) ) {
V_230 = V_51 ;
break;
}
}
if ( V_230 >= 0 )
F_176 ( V_230 , & V_231 ) ;
F_172 ( V_224 , V_127 , V_230 ) ;
F_172 ( V_218 , V_127 , V_230 ) ;
}
static void T_5 F_177 ( int V_127 )
{
int V_51 , V_141 ;
V_141 = F_113 ( V_127 ) ;
F_178 (i, &uncore_cpu_mask) {
if ( V_141 == F_113 ( V_51 ) )
return;
}
F_176 ( V_127 , & V_231 ) ;
F_172 ( V_224 , - 1 , V_127 ) ;
F_172 ( V_218 , - 1 , V_127 ) ;
}
static int
T_5 F_179 ( struct V_232 * V_233 , unsigned long V_234 , void * V_235 )
{
unsigned int V_127 = ( long ) V_235 ;
switch ( V_234 & ~ V_236 ) {
case V_237 :
F_171 ( V_127 , - 1 ) ;
break;
case V_238 :
F_169 ( V_127 ) ;
break;
case V_239 :
case V_240 :
F_167 ( V_127 ) ;
break;
default:
break;
}
switch ( V_234 & ~ V_236 ) {
case V_241 :
case V_238 :
F_177 ( V_127 ) ;
break;
case V_242 :
F_174 ( V_127 ) ;
break;
default:
break;
}
return V_243 ;
}
static void T_3 F_180 ( void * V_244 )
{
F_169 ( F_92 () ) ;
}
static int T_3 F_181 ( void )
{
int V_86 , V_127 , V_245 ;
V_245 = V_216 . V_246 ;
switch ( V_216 . V_217 ) {
case 26 :
case 30 :
case 37 :
case 44 :
V_224 = V_247 ;
break;
case 42 :
if ( V_248 . V_200 > V_245 )
V_248 . V_200 = V_245 ;
V_224 = V_249 ;
break;
case 45 :
if ( V_41 . V_200 > V_245 )
V_41 . V_200 = V_245 ;
V_224 = V_250 ;
break;
case 46 :
V_89 = true ;
case 47 :
if ( ! V_89 )
V_251 . V_210 = V_252 ;
if ( V_253 . V_200 > V_245 )
V_253 . V_200 = V_245 ;
V_224 = V_254 ;
break;
default:
return 0 ;
}
V_86 = F_153 ( V_224 ) ;
if ( V_86 )
return V_86 ;
F_182 () ;
F_170 (cpu) {
int V_51 , V_141 = F_113 ( V_127 ) ;
F_178 (i, &uncore_cpu_mask) {
if ( V_141 == F_113 ( V_51 ) ) {
V_141 = - 1 ;
break;
}
}
if ( V_141 < 0 )
continue;
F_171 ( V_127 , V_141 ) ;
F_177 ( V_127 ) ;
}
F_183 ( F_180 , NULL , 1 ) ;
F_184 ( & V_255 ) ;
F_185 () ;
return 0 ;
}
static int T_3 F_186 ( void )
{
struct V_142 * V_40 ;
struct V_98 * type ;
int V_51 , V_208 ;
for ( V_51 = 0 ; V_224 [ V_51 ] ; V_51 ++ ) {
type = V_224 [ V_51 ] ;
for ( V_208 = 0 ; V_208 < type -> V_200 ; V_208 ++ ) {
V_40 = & type -> V_202 [ V_208 ] ;
F_143 ( V_40 ) ;
}
}
for ( V_51 = 0 ; V_218 [ V_51 ] ; V_51 ++ ) {
type = V_218 [ V_51 ] ;
for ( V_208 = 0 ; V_208 < type -> V_200 ; V_208 ++ ) {
V_40 = & type -> V_202 [ V_208 ] ;
F_143 ( V_40 ) ;
}
}
return 0 ;
}
static int T_3 F_187 ( void )
{
int V_86 ;
if ( V_216 . V_256 != V_257 )
return - V_174 ;
V_86 = F_163 () ;
if ( V_86 )
goto V_97;
V_86 = F_181 () ;
if ( V_86 ) {
F_165 () ;
goto V_97;
}
F_186 () ;
return 0 ;
V_97:
return V_86 ;
}

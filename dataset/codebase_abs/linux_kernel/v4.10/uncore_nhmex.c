static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_3 , 0 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned V_5 = F_5 ( V_2 ) ;
T_1 V_6 ;
if ( V_5 ) {
F_6 ( V_5 , V_6 ) ;
V_6 &= ~ ( ( 1ULL << F_7 ( V_2 ) ) - 1 ) ;
if ( F_8 ( V_2 ) )
V_6 &= ~ V_7 ;
F_2 ( V_5 , V_6 ) ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned V_5 = F_5 ( V_2 ) ;
T_1 V_6 ;
if ( V_5 ) {
F_6 ( V_5 , V_6 ) ;
V_6 |= ( 1ULL << F_7 ( V_2 ) ) - 1 ;
if ( F_8 ( V_2 ) )
V_6 |= V_7 ;
F_2 ( V_5 , V_6 ) ;
}
}
static void F_10 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
F_2 ( V_9 -> V_10 . V_11 , 0 ) ;
}
static void F_11 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_12 * V_13 = & V_9 -> V_10 ;
if ( V_13 -> V_14 >= V_15 )
F_2 ( V_13 -> V_11 , V_16 ) ;
else if ( V_2 -> V_17 -> type -> V_18 & V_16 )
F_2 ( V_13 -> V_11 , V_13 -> V_6 | V_19 ) ;
else
F_2 ( V_13 -> V_11 , V_13 -> V_6 | V_16 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_12 * V_13 = & V_9 -> V_10 ;
struct V_20 * V_21 = & V_13 -> V_22 ;
struct V_20 * V_23 = & V_13 -> V_24 ;
int V_25 , V_26 ;
V_25 = ( V_13 -> V_6 & V_27 ) >>
V_28 ;
V_26 = ( V_13 -> V_6 & V_29 ) >>
V_30 ;
if ( ( V_25 == 0 && V_26 > 0x3 ) || ( V_25 == 1 && V_26 > 0x6 ) ||
( V_25 == 2 && V_26 != 0x4 ) || V_25 == 3 )
return 0 ;
if ( V_2 -> V_17 -> V_31 == 0 )
V_21 -> V_32 = V_33 ;
else
V_21 -> V_32 = V_34 ;
V_21 -> V_14 = 0 ;
V_21 -> V_6 = V_9 -> V_35 . V_36 ;
V_23 -> V_6 = V_9 -> V_35 . V_37 ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_12 * V_13 = & V_9 -> V_10 ;
struct V_20 * V_21 = & V_13 -> V_22 ;
struct V_20 * V_23 = & V_13 -> V_24 ;
if ( V_21 -> V_14 != V_38 ) {
F_2 ( V_21 -> V_32 , V_21 -> V_6 ) ;
F_2 ( V_21 -> V_32 + 1 , V_23 -> V_6 ) ;
}
F_2 ( V_13 -> V_11 , V_16 |
( V_13 -> V_6 & V_29 ) ) ;
}
static int F_14 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_12 * V_13 = & V_9 -> V_10 ;
struct V_20 * V_21 = & V_13 -> V_22 ;
struct V_20 * V_23 = & V_13 -> V_24 ;
if ( ( V_13 -> V_6 & V_39 ) !=
V_40 )
return 0 ;
if ( V_2 -> V_17 -> V_31 == 0 )
V_21 -> V_32 = V_41 ;
else
V_21 -> V_32 = V_42 ;
V_21 -> V_14 = 0 ;
V_21 -> V_6 = V_9 -> V_35 . V_36 ;
V_23 -> V_6 = V_9 -> V_35 . V_37 ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_12 * V_13 = & V_9 -> V_10 ;
struct V_20 * V_21 = & V_13 -> V_22 ;
struct V_20 * V_23 = & V_13 -> V_24 ;
if ( V_21 -> V_14 != V_38 ) {
F_2 ( V_21 -> V_32 , 0 ) ;
F_2 ( V_21 -> V_32 + 1 , V_21 -> V_6 ) ;
F_2 ( V_21 -> V_32 + 2 , V_23 -> V_6 ) ;
F_2 ( V_21 -> V_32 , V_43 ) ;
}
F_2 ( V_13 -> V_11 , V_13 -> V_6 | V_19 ) ;
}
static bool F_16 ( struct V_1 * V_2 , int V_14 , T_1 V_6 )
{
struct V_44 * V_45 ;
unsigned long V_46 ;
bool V_47 = false ;
T_1 V_48 ;
if ( V_14 < V_49 ) {
V_45 = & V_2 -> V_50 [ V_14 ] ;
F_17 ( & V_45 -> V_51 , V_46 ) ;
if ( ! F_18 ( & V_45 -> V_52 ) || V_45 -> V_6 == V_6 ) {
F_19 ( & V_45 -> V_52 ) ;
V_45 -> V_6 = V_6 ;
V_47 = true ;
}
F_20 ( & V_45 -> V_51 , V_46 ) ;
return V_47 ;
}
V_14 -= V_49 ;
if ( F_21 ( V_14 >= 4 ) )
return false ;
if ( V_53 )
V_48 = V_54 ;
else
V_48 = V_55 ;
V_45 = & V_2 -> V_50 [ V_49 ] ;
F_17 ( & V_45 -> V_51 , V_46 ) ;
if ( F_22 ( F_18 ( & V_45 -> V_52 ) , V_14 , 8 ) ) {
if ( V_53 )
V_48 |= F_23 ( V_14 ) ;
else
V_48 |= F_24 ( V_14 ) ;
}
if ( ! F_18 ( & V_45 -> V_52 ) || ! ( ( V_45 -> V_6 ^ V_6 ) & V_48 ) ) {
F_25 ( 1 << ( V_14 * 8 ) , & V_45 -> V_52 ) ;
if ( V_53 )
V_48 = V_54 |
F_23 ( V_14 ) ;
else
V_48 = V_55 |
F_24 ( V_14 ) ;
V_45 -> V_6 &= ~ V_48 ;
V_45 -> V_6 |= ( V_6 & V_48 ) ;
V_47 = true ;
}
F_20 ( & V_45 -> V_51 , V_46 ) ;
return V_47 ;
}
static void F_26 ( struct V_1 * V_2 , int V_14 )
{
struct V_44 * V_45 ;
if ( V_14 < V_49 ) {
V_45 = & V_2 -> V_50 [ V_14 ] ;
F_27 ( & V_45 -> V_52 ) ;
return;
}
V_14 -= V_49 ;
V_45 = & V_2 -> V_50 [ V_49 ] ;
F_28 ( 1 << ( V_14 * 8 ) , & V_45 -> V_52 ) ;
}
static T_1 F_29 ( struct V_8 * V_9 , int V_56 , bool V_57 )
{
struct V_12 * V_13 = & V_9 -> V_10 ;
struct V_20 * V_21 = & V_13 -> V_22 ;
T_1 V_14 , V_58 = F_22 ( V_21 -> V_14 , 0 , 8 ) ;
T_1 V_6 = V_21 -> V_6 ;
V_14 = V_58 - V_49 ;
if ( V_53 )
V_6 &= F_23 ( V_14 ) ;
else
V_6 &= F_24 ( V_14 ) ;
if ( V_56 > V_58 ) {
V_14 = V_56 - V_58 ;
V_6 <<= 3 * V_14 ;
} else {
V_14 = V_58 - V_56 ;
V_6 >>= 3 * V_14 ;
}
if ( V_53 )
V_6 |= V_54 & V_21 -> V_6 ;
else
V_6 |= V_55 & V_21 -> V_6 ;
V_6 |= V_54 & V_21 -> V_6 ;
if ( V_57 ) {
if ( V_56 > V_58 )
V_13 -> V_6 += V_14 << V_59 ;
else
V_13 -> V_6 -= V_14 << V_59 ;
V_21 -> V_6 = V_6 ;
V_21 -> V_14 = ~ 0xff | V_56 ;
}
return V_6 ;
}
static struct V_60 *
F_30 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_20 * V_21 = & V_9 -> V_10 . V_22 ;
struct V_20 * V_23 = & V_9 -> V_10 . V_24 ;
int V_61 , V_14 [ 2 ] , V_62 = 0 ;
T_1 V_36 = V_21 -> V_6 ;
V_14 [ 0 ] = F_22 ( V_21 -> V_14 , 0 , 8 ) ;
V_14 [ 1 ] = F_22 ( V_21 -> V_14 , 1 , 8 ) ;
V_63:
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
if ( ! F_31 ( V_2 ) && ( V_21 -> V_62 & ( 0x1 << V_61 ) ) )
V_14 [ V_61 ] = 0xff ;
if ( V_14 [ V_61 ] == 0xff )
continue;
if ( ! F_16 ( V_2 , V_14 [ V_61 ] ,
F_22 ( V_36 , V_61 , 32 ) ) )
goto V_64;
V_62 |= ( 0x1 << V_61 ) ;
}
if ( V_23 -> V_14 != V_38 &&
( F_31 ( V_2 ) || ! V_23 -> V_62 ) &&
! F_16 ( V_2 , V_23 -> V_14 , V_23 -> V_6 ) )
goto V_64;
if ( ! F_31 ( V_2 ) ) {
if ( V_14 [ 0 ] != 0xff && V_14 [ 0 ] != F_22 ( V_21 -> V_14 , 0 , 8 ) )
F_29 ( V_9 , V_14 [ 0 ] , true ) ;
V_21 -> V_62 |= V_62 ;
if ( V_23 -> V_14 != V_38 )
V_23 -> V_62 = 1 ;
}
return NULL ;
V_64:
if ( V_14 [ 0 ] != 0xff && ! ( V_62 & 0x1 ) &&
V_14 [ 0 ] >= V_49 ) {
F_32 ( F_22 ( V_21 -> V_14 , 1 , 8 ) != 0xff ) ;
V_14 [ 0 ] -= V_49 ;
V_14 [ 0 ] = ( V_14 [ 0 ] + 1 ) % 4 ;
V_14 [ 0 ] += V_49 ;
if ( V_14 [ 0 ] != F_22 ( V_21 -> V_14 , 0 , 8 ) ) {
V_36 = F_29 ( V_9 , V_14 [ 0 ] , false ) ;
goto V_63;
}
}
if ( V_62 & 0x1 )
F_26 ( V_2 , V_14 [ 0 ] ) ;
if ( V_62 & 0x2 )
F_26 ( V_2 , V_14 [ 1 ] ) ;
return & V_65 ;
}
static void F_33 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_20 * V_21 = & V_9 -> V_10 . V_22 ;
struct V_20 * V_23 = & V_9 -> V_10 . V_24 ;
if ( F_31 ( V_2 ) )
return;
if ( V_21 -> V_62 & 0x1 )
F_26 ( V_2 , F_22 ( V_21 -> V_14 , 0 , 8 ) ) ;
if ( V_21 -> V_62 & 0x2 )
F_26 ( V_2 , F_22 ( V_21 -> V_14 , 1 , 8 ) ) ;
V_21 -> V_62 = 0 ;
if ( V_23 -> V_62 ) {
F_26 ( V_2 , V_23 -> V_14 ) ;
V_23 -> V_62 = 0 ;
}
}
static int F_34 ( struct V_22 * V_45 )
{
if ( V_45 -> V_14 < V_49 )
return V_45 -> V_14 ;
return V_45 -> V_14 + ( V_45 -> V_9 >> V_59 ) - 0xd ;
}
static int F_35 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_66 * type = V_2 -> V_17 -> type ;
struct V_20 * V_21 = & V_9 -> V_10 . V_22 ;
struct V_20 * V_23 = & V_9 -> V_10 . V_24 ;
struct V_22 * V_45 ;
unsigned V_5 ;
int V_67 = 0 ;
for ( V_45 = V_68 ; V_45 -> V_5 ; V_45 ++ ) {
if ( V_45 -> V_9 != ( V_9 -> V_10 . V_6 & V_45 -> V_69 ) )
continue;
if ( V_9 -> V_35 . V_36 & ~ V_45 -> V_70 )
return - V_71 ;
V_5 = V_45 -> V_5 + type -> V_72 * V_2 -> V_17 -> V_31 ;
if ( F_21 ( V_5 >= 0xffff || V_45 -> V_14 >= 0xff ) )
return - V_71 ;
if ( V_45 -> V_14 == V_73 )
V_67 = 1 ;
else if ( F_21 ( V_67 > 0 ) )
return - V_71 ;
V_21 -> V_14 &= ~ ( 0xff << ( V_67 * 8 ) ) ;
V_21 -> V_32 &= ~ ( 0xffff << ( V_67 * 16 ) ) ;
V_21 -> V_14 |= F_34 ( V_45 ) << ( V_67 * 8 ) ;
V_21 -> V_32 |= V_5 << ( V_67 * 16 ) ;
V_21 -> V_6 = V_9 -> V_35 . V_36 ;
V_67 ++ ;
}
if ( V_67 == 2 ) {
V_23 -> V_14 = V_74 ;
if ( V_9 -> V_35 . V_37 & V_75 )
V_23 -> V_6 = V_9 -> V_35 . V_37 ;
else
V_23 -> V_6 = ~ 0ULL ;
if ( V_2 -> V_17 -> V_31 == 0 )
V_23 -> V_32 = V_76 ;
else
V_23 -> V_32 = V_77 ;
}
return 0 ;
}
static T_1 F_36 ( struct V_1 * V_2 , int V_14 )
{
struct V_44 * V_45 ;
unsigned long V_46 ;
T_1 V_6 ;
if ( V_14 < V_49 )
return V_2 -> V_50 [ V_14 ] . V_6 ;
V_45 = & V_2 -> V_50 [ V_49 ] ;
F_17 ( & V_45 -> V_51 , V_46 ) ;
V_6 = V_45 -> V_6 ;
F_20 ( & V_45 -> V_51 , V_46 ) ;
return V_6 ;
}
static void F_37 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_12 * V_13 = & V_9 -> V_10 ;
struct V_20 * V_21 = & V_13 -> V_22 ;
struct V_20 * V_23 = & V_13 -> V_24 ;
int V_14 ;
V_14 = F_22 ( V_21 -> V_14 , 0 , 8 ) ;
if ( V_14 != 0xff )
F_2 ( F_22 ( V_21 -> V_32 , 0 , 16 ) ,
F_36 ( V_2 , V_14 ) ) ;
V_14 = F_22 ( V_21 -> V_14 , 1 , 8 ) ;
if ( V_14 != 0xff )
F_2 ( F_22 ( V_21 -> V_32 , 1 , 16 ) ,
F_36 ( V_2 , V_14 ) ) ;
if ( V_23 -> V_14 != V_38 ) {
F_2 ( V_23 -> V_32 , 0 ) ;
if ( V_23 -> V_6 != ~ 0ULL ) {
F_2 ( V_23 -> V_32 + 1 ,
V_23 -> V_6 & V_78 ) ;
F_2 ( V_23 -> V_32 + 2 , V_79 &
( V_23 -> V_6 >> V_80 ) ) ;
F_2 ( V_23 -> V_32 , V_75 ) ;
}
}
F_2 ( V_13 -> V_11 , V_13 -> V_6 | V_16 ) ;
}
static void F_38 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_12 * V_13 = & V_9 -> V_10 ;
struct V_20 * V_21 = & V_13 -> V_22 ;
if ( V_21 -> V_14 % 2 ) {
V_21 -> V_14 -- ;
V_13 -> V_6 -= 1 << V_81 ;
} else {
V_21 -> V_14 ++ ;
V_13 -> V_6 += 1 << V_81 ;
}
switch ( V_21 -> V_14 % 6 ) {
case 2 :
V_21 -> V_6 >>= 8 ;
break;
case 3 :
V_21 -> V_6 <<= 8 ;
break;
}
}
static struct V_60 *
F_39 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_12 * V_13 = & V_9 -> V_10 ;
struct V_20 * V_21 = & V_13 -> V_22 ;
struct V_20 * V_23 = & V_13 -> V_24 ;
struct V_44 * V_45 ;
unsigned long V_46 ;
int V_14 , V_82 ;
T_1 V_36 ;
bool V_83 = false ;
if ( ! F_31 ( V_2 ) && V_21 -> V_62 )
return NULL ;
V_14 = V_21 -> V_14 % 6 ;
V_36 = V_21 -> V_6 ;
V_63:
V_82 = V_14 ;
if ( V_82 > 2 )
V_82 -- ;
V_82 += ( V_21 -> V_14 / 6 ) * 5 ;
V_45 = & V_2 -> V_50 [ V_82 ] ;
F_17 ( & V_45 -> V_51 , V_46 ) ;
if ( V_14 < 2 ) {
if ( ! F_18 ( & V_45 -> V_52 ) || V_45 -> V_6 == V_21 -> V_6 ) {
F_19 ( & V_45 -> V_52 ) ;
V_45 -> V_6 = V_21 -> V_6 ;
V_83 = true ;
}
} else if ( V_14 == 2 || V_14 == 3 ) {
T_1 V_48 = 0xff << ( ( V_14 - 2 ) * 8 ) ;
if ( ! F_22 ( F_18 ( & V_45 -> V_52 ) , V_14 - 2 , 8 ) ||
! ( ( V_45 -> V_6 ^ V_36 ) & V_48 ) ) {
F_25 ( 1 << ( ( V_14 - 2 ) * 8 ) , & V_45 -> V_52 ) ;
V_45 -> V_6 &= ~ V_48 ;
V_45 -> V_6 |= V_36 & V_48 ;
V_83 = true ;
}
} else {
if ( ! F_18 ( & V_45 -> V_52 ) ||
( V_45 -> V_6 == ( V_13 -> V_6 >> 32 ) &&
V_45 -> V_36 == V_21 -> V_6 &&
V_45 -> V_37 == V_23 -> V_6 ) ) {
F_19 ( & V_45 -> V_52 ) ;
V_45 -> V_6 = ( V_13 -> V_6 >> 32 ) ;
V_45 -> V_36 = V_21 -> V_6 ;
V_45 -> V_37 = V_23 -> V_6 ;
V_83 = true ;
}
}
F_20 ( & V_45 -> V_51 , V_46 ) ;
if ( ! V_83 ) {
V_14 ^= 1 ;
if ( V_14 != V_21 -> V_14 % 6 ) {
if ( V_14 == 2 )
V_36 >>= 8 ;
else if ( V_14 == 3 )
V_36 <<= 8 ;
goto V_63;
}
} else {
if ( ! F_31 ( V_2 ) ) {
if ( V_14 != V_21 -> V_14 % 6 )
F_38 ( V_2 , V_9 ) ;
V_21 -> V_62 = 1 ;
}
return NULL ;
}
return & V_65 ;
}
static void F_40 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_44 * V_45 ;
struct V_20 * V_21 = & V_9 -> V_10 . V_22 ;
int V_14 , V_82 ;
if ( F_31 ( V_2 ) || ! V_21 -> V_62 )
return;
V_14 = V_21 -> V_14 % 6 ;
V_82 = V_14 ;
if ( V_82 > 2 )
V_82 -- ;
V_82 += ( V_21 -> V_14 / 6 ) * 5 ;
V_45 = & V_2 -> V_50 [ V_82 ] ;
if ( V_14 == 2 || V_14 == 3 )
F_28 ( 1 << ( ( V_14 - 2 ) * 8 ) , & V_45 -> V_52 ) ;
else
F_27 ( & V_45 -> V_52 ) ;
V_21 -> V_62 = 0 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_12 * V_13 = & V_9 -> V_10 ;
struct V_20 * V_21 = & V_9 -> V_10 . V_22 ;
struct V_20 * V_23 = & V_9 -> V_10 . V_24 ;
int V_14 ;
V_14 = ( V_9 -> V_10 . V_6 & V_84 ) >>
V_81 ;
if ( V_14 >= 0x18 )
return - V_71 ;
V_21 -> V_14 = V_14 ;
V_21 -> V_6 = V_9 -> V_35 . V_36 ;
switch ( V_14 % 6 ) {
case 4 :
case 5 :
V_13 -> V_6 |= V_9 -> V_35 . V_6 & ( ~ 0ULL << 32 ) ;
V_23 -> V_6 = V_9 -> V_35 . V_37 ;
break;
}
return 0 ;
}
static void F_42 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_12 * V_13 = & V_9 -> V_10 ;
struct V_20 * V_21 = & V_13 -> V_22 ;
struct V_20 * V_23 = & V_13 -> V_24 ;
int V_14 , V_85 ;
V_14 = V_21 -> V_14 ;
V_85 = V_14 / 6 + V_2 -> V_17 -> V_31 * 4 ;
switch ( V_14 % 6 ) {
case 0 :
F_2 ( F_43 ( V_85 ) , V_21 -> V_6 ) ;
break;
case 1 :
F_2 ( F_44 ( V_85 ) , V_21 -> V_6 ) ;
break;
case 2 :
case 3 :
F_2 ( F_45 ( V_85 ) ,
F_46 ( V_2 , 2 + ( V_14 / 6 ) * 5 ) ) ;
break;
case 4 :
F_2 ( F_47 ( V_85 ) ,
V_13 -> V_6 >> 32 ) ;
F_2 ( F_48 ( V_85 ) , V_21 -> V_6 ) ;
F_2 ( F_49 ( V_85 ) , V_23 -> V_6 ) ;
break;
case 5 :
F_2 ( F_50 ( V_85 ) ,
V_13 -> V_6 >> 32 ) ;
F_2 ( F_51 ( V_85 ) , V_21 -> V_6 ) ;
F_2 ( F_52 ( V_85 ) , V_23 -> V_6 ) ;
break;
}
F_2 ( V_13 -> V_11 , V_16 |
( V_13 -> V_6 & V_84 ) ) ;
}
void F_53 ( void )
{
if ( V_86 . V_87 == 46 )
V_53 = true ;
else
V_88 . V_89 = V_90 ;
if ( V_91 . V_92 > V_86 . V_93 )
V_91 . V_92 = V_86 . V_93 ;
V_94 = V_95 ;
}

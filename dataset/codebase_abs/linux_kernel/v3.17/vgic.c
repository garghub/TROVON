static T_1 * F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
V_4 >>= 2 ;
if ( ! V_4 )
return V_2 -> V_5 [ V_3 ] . V_6 + ( V_4 ^ V_7 ) ;
else
return V_2 -> V_8 . V_6 + ( ( V_4 - 1 ) ^ V_7 ) ;
}
static int F_2 ( struct V_1 * V_2 ,
int V_3 , int V_9 )
{
if ( V_9 < V_10 )
return F_3 ( V_9 , V_2 -> V_5 [ V_3 ] . V_11 ) ;
return F_3 ( V_9 - V_10 , V_2 -> V_8 . V_11 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_3 ,
int V_9 , int V_12 )
{
unsigned long * V_6 ;
if ( V_9 < V_10 ) {
V_6 = V_2 -> V_5 [ V_3 ] . V_11 ;
} else {
V_6 = V_2 -> V_8 . V_11 ;
V_9 -= V_10 ;
}
if ( V_12 )
F_5 ( V_9 , V_6 ) ;
else
F_6 ( V_9 , V_6 ) ;
}
static unsigned long * F_7 ( struct V_1 * V_2 , int V_3 )
{
if ( F_8 ( V_3 >= V_13 ) )
return NULL ;
return V_2 -> V_5 [ V_3 ] . V_11 ;
}
static unsigned long * F_9 ( struct V_1 * V_2 )
{
return V_2 -> V_8 . V_11 ;
}
static T_1 * F_10 ( struct V_14 * V_2 , int V_3 , T_1 V_4 )
{
V_4 >>= 2 ;
F_11 ( V_4 > ( V_15 / 4 ) ) ;
if ( V_4 < 8 )
return V_2 -> V_5 [ V_3 ] + V_4 ;
else
return V_2 -> V_8 + V_4 - 8 ;
}
static bool F_12 ( struct V_16 * V_17 , int V_9 )
{
struct V_18 * V_19 = & V_17 -> V_20 -> V_21 . V_22 ;
int V_23 ;
V_23 = F_2 ( & V_19 -> V_24 , V_17 -> V_25 , V_9 ) ;
return V_23 == V_26 ;
}
static int F_13 ( struct V_16 * V_17 , int V_9 )
{
struct V_18 * V_19 = & V_17 -> V_20 -> V_21 . V_22 ;
return F_2 ( & V_19 -> V_27 , V_17 -> V_25 , V_9 ) ;
}
static int F_14 ( struct V_16 * V_17 , int V_9 )
{
struct V_18 * V_19 = & V_17 -> V_20 -> V_21 . V_22 ;
return F_2 ( & V_19 -> V_28 , V_17 -> V_25 , V_9 ) ;
}
static void F_15 ( struct V_16 * V_17 , int V_9 )
{
struct V_18 * V_19 = & V_17 -> V_20 -> V_21 . V_22 ;
F_4 ( & V_19 -> V_28 , V_17 -> V_25 , V_9 , 1 ) ;
}
static void F_16 ( struct V_16 * V_17 , int V_9 )
{
struct V_18 * V_19 = & V_17 -> V_20 -> V_21 . V_22 ;
F_4 ( & V_19 -> V_28 , V_17 -> V_25 , V_9 , 0 ) ;
}
static int F_17 ( struct V_16 * V_17 , int V_9 )
{
struct V_18 * V_19 = & V_17 -> V_20 -> V_21 . V_22 ;
return F_2 ( & V_19 -> V_29 , V_17 -> V_25 , V_9 ) ;
}
static void F_18 ( struct V_16 * V_17 , int V_9 )
{
struct V_18 * V_19 = & V_17 -> V_20 -> V_21 . V_22 ;
F_4 ( & V_19 -> V_29 , V_17 -> V_25 , V_9 , 1 ) ;
}
static void F_19 ( struct V_16 * V_17 , int V_9 )
{
struct V_18 * V_19 = & V_17 -> V_20 -> V_21 . V_22 ;
F_4 ( & V_19 -> V_29 , V_17 -> V_25 , V_9 , 0 ) ;
}
static void F_20 ( struct V_16 * V_17 , int V_9 )
{
if ( V_9 < V_10 )
F_5 ( V_9 , V_17 -> V_21 . V_30 . V_31 ) ;
else
F_5 ( V_9 - V_10 ,
V_17 -> V_21 . V_30 . V_32 ) ;
}
static void F_21 ( struct V_16 * V_17 , int V_9 )
{
if ( V_9 < V_10 )
F_6 ( V_9 , V_17 -> V_21 . V_30 . V_31 ) ;
else
F_6 ( V_9 - V_10 ,
V_17 -> V_21 . V_30 . V_32 ) ;
}
static T_1 F_22 ( struct V_33 * V_34 , T_1 V_35 )
{
return F_23 ( * ( ( T_1 * ) V_34 -> V_36 ) ) & V_35 ;
}
static void F_24 ( struct V_33 * V_34 , T_1 V_35 , T_1 V_37 )
{
* ( ( T_1 * ) V_34 -> V_36 ) = F_25 ( V_37 ) & V_35 ;
}
static void F_26 ( struct V_33 * V_34 , T_1 * V_6 ,
T_2 V_4 , int V_38 )
{
int V_39 = ( V_4 & 3 ) * 8 ;
T_1 V_35 = ( 1UL << ( V_34 -> V_40 * 8 ) ) - 1 ;
T_1 V_41 ;
if ( V_6 ) {
V_41 = * V_6 ;
} else {
F_11 ( V_38 != ( V_42 | V_43 ) ) ;
V_41 = 0 ;
}
if ( V_34 -> V_44 ) {
T_1 V_36 = F_22 ( V_34 , V_35 ) << V_39 ;
switch ( F_27 ( V_38 ) ) {
case V_43 :
return;
case V_45 :
V_41 |= V_36 ;
break;
case V_46 :
V_41 &= ~ V_36 ;
break;
case V_47 :
V_41 = ( V_41 & ~ ( V_35 << V_39 ) ) | V_36 ;
break;
}
* V_6 = V_41 ;
} else {
switch ( F_28 ( V_38 ) ) {
case V_42 :
V_41 = 0 ;
case V_48 :
F_24 ( V_34 , V_35 , V_41 >> V_39 ) ;
}
}
}
static bool F_29 ( struct V_16 * V_17 ,
struct V_33 * V_34 , T_2 V_4 )
{
T_1 V_6 ;
T_1 V_39 = V_4 & 3 ;
switch ( V_4 & ~ 3 ) {
case 0 :
V_6 = V_17 -> V_20 -> V_21 . V_22 . V_49 ;
F_26 ( V_34 , & V_6 , V_39 ,
V_48 | V_47 ) ;
if ( V_34 -> V_44 ) {
V_17 -> V_20 -> V_21 . V_22 . V_49 = V_6 & 1 ;
F_30 ( V_17 -> V_20 ) ;
return true ;
}
break;
case 4 :
V_6 = ( F_31 ( & V_17 -> V_20 -> V_50 ) - 1 ) << 5 ;
V_6 |= ( V_15 >> 5 ) - 1 ;
F_26 ( V_34 , & V_6 , V_39 ,
V_48 | V_43 ) ;
break;
case 8 :
V_6 = ( V_51 << 24 ) | ( V_52 << 0 ) ;
F_26 ( V_34 , & V_6 , V_39 ,
V_48 | V_43 ) ;
break;
}
return false ;
}
static bool F_32 ( struct V_16 * V_17 ,
struct V_33 * V_34 , T_2 V_4 )
{
F_26 ( V_34 , NULL , V_4 ,
V_42 | V_43 ) ;
return false ;
}
static bool F_33 ( struct V_16 * V_17 ,
struct V_33 * V_34 ,
T_2 V_4 )
{
T_1 * V_6 = F_1 ( & V_17 -> V_20 -> V_21 . V_22 . V_27 ,
V_17 -> V_25 , V_4 ) ;
F_26 ( V_34 , V_6 , V_4 ,
V_48 | V_45 ) ;
if ( V_34 -> V_44 ) {
F_30 ( V_17 -> V_20 ) ;
return true ;
}
return false ;
}
static bool F_34 ( struct V_16 * V_17 ,
struct V_33 * V_34 ,
T_2 V_4 )
{
T_1 * V_6 = F_1 ( & V_17 -> V_20 -> V_21 . V_22 . V_27 ,
V_17 -> V_25 , V_4 ) ;
F_26 ( V_34 , V_6 , V_4 ,
V_48 | V_46 ) ;
if ( V_34 -> V_44 ) {
if ( V_4 < 4 )
* V_6 |= 0xffff ;
F_35 ( V_17 ) ;
F_30 ( V_17 -> V_20 ) ;
return true ;
}
return false ;
}
static bool F_36 ( struct V_16 * V_17 ,
struct V_33 * V_34 ,
T_2 V_4 )
{
T_1 * V_6 = F_1 ( & V_17 -> V_20 -> V_21 . V_22 . V_29 ,
V_17 -> V_25 , V_4 ) ;
F_26 ( V_34 , V_6 , V_4 ,
V_48 | V_45 ) ;
if ( V_34 -> V_44 ) {
F_30 ( V_17 -> V_20 ) ;
return true ;
}
return false ;
}
static bool F_37 ( struct V_16 * V_17 ,
struct V_33 * V_34 ,
T_2 V_4 )
{
T_1 * V_6 = F_1 ( & V_17 -> V_20 -> V_21 . V_22 . V_29 ,
V_17 -> V_25 , V_4 ) ;
F_26 ( V_34 , V_6 , V_4 ,
V_48 | V_46 ) ;
if ( V_34 -> V_44 ) {
F_30 ( V_17 -> V_20 ) ;
return true ;
}
return false ;
}
static bool F_38 ( struct V_16 * V_17 ,
struct V_33 * V_34 ,
T_2 V_4 )
{
T_1 * V_6 = F_10 ( & V_17 -> V_20 -> V_21 . V_22 . V_53 ,
V_17 -> V_25 , V_4 ) ;
F_26 ( V_34 , V_6 , V_4 ,
V_48 | V_47 ) ;
return false ;
}
static T_1 F_39 ( struct V_20 * V_20 , int V_9 )
{
struct V_18 * V_19 = & V_20 -> V_21 . V_22 ;
int V_54 ;
T_1 V_12 = 0 ;
V_9 -= V_10 ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ )
V_12 |= 1 << ( V_19 -> V_56 [ V_9 + V_54 ] + V_54 * 8 ) ;
return V_12 ;
}
static void F_40 ( struct V_20 * V_20 , T_1 V_12 , int V_9 )
{
struct V_18 * V_19 = & V_20 -> V_21 . V_22 ;
struct V_16 * V_17 ;
int V_54 , V_57 ;
unsigned long * V_58 ;
T_1 V_59 ;
V_9 -= V_10 ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
int V_60 = V_54 * V_61 ;
V_59 = F_41 ( ( V_12 >> V_60 ) & 0xffU ) ;
V_59 = V_59 ? ( V_59 - 1 ) : 0 ;
V_19 -> V_56 [ V_9 + V_54 ] = V_59 ;
F_42 (c, vcpu, kvm) {
V_58 = F_9 ( & V_19 -> V_62 [ V_57 ] ) ;
if ( V_57 == V_59 )
F_5 ( V_9 + V_54 , V_58 ) ;
else
F_6 ( V_9 + V_54 , V_58 ) ;
}
}
}
static bool F_43 ( struct V_16 * V_17 ,
struct V_33 * V_34 ,
T_2 V_4 )
{
T_1 V_6 ;
if ( V_4 < 32 ) {
T_1 V_63 = 1 << V_17 -> V_25 ;
V_63 |= V_63 << 8 ;
V_63 |= V_63 << 16 ;
F_26 ( V_34 , & V_63 , V_4 ,
V_48 | V_43 ) ;
return false ;
}
V_6 = F_39 ( V_17 -> V_20 , V_4 & ~ 3U ) ;
F_26 ( V_34 , & V_6 , V_4 ,
V_48 | V_47 ) ;
if ( V_34 -> V_44 ) {
F_40 ( V_17 -> V_20 , V_6 , V_4 & ~ 3U ) ;
F_30 ( V_17 -> V_20 ) ;
return true ;
}
return false ;
}
static T_1 F_44 ( T_3 V_12 )
{
T_1 V_64 = 0 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < 16 ; V_54 ++ )
V_64 |= ( ( V_12 >> V_54 ) & V_26 ) << ( 2 * V_54 + 1 ) ;
return V_64 ;
}
static T_3 F_45 ( T_1 V_12 )
{
T_3 V_64 = 0 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < 16 ; V_54 ++ )
V_64 |= ( ( V_12 >> ( V_54 * 2 + 1 ) ) & V_26 ) << V_54 ;
return V_64 ;
}
static bool F_46 ( struct V_16 * V_17 ,
struct V_33 * V_34 , T_2 V_4 )
{
T_1 V_12 ;
T_1 * V_6 ;
V_6 = F_1 ( & V_17 -> V_20 -> V_21 . V_22 . V_24 ,
V_17 -> V_25 , V_4 >> 1 ) ;
if ( V_4 & 4 )
V_12 = * V_6 >> 16 ;
else
V_12 = * V_6 & 0xffff ;
V_12 = F_44 ( V_12 ) ;
F_26 ( V_34 , & V_12 , V_4 ,
V_48 | V_47 ) ;
if ( V_34 -> V_44 ) {
if ( V_4 < 8 ) {
* V_6 = ~ 0U ;
return false ;
}
V_12 = F_45 ( V_12 ) ;
if ( V_4 & 4 ) {
* V_6 &= 0xffff ;
* V_6 |= V_12 << 16 ;
} else {
* V_6 &= 0xffff << 16 ;
* V_6 |= V_12 ;
}
}
return false ;
}
static bool F_47 ( struct V_16 * V_17 ,
struct V_33 * V_34 , T_2 V_4 )
{
T_1 V_6 ;
F_26 ( V_34 , & V_6 , V_4 ,
V_42 | V_47 ) ;
if ( V_34 -> V_44 ) {
F_48 ( V_17 , V_6 ) ;
F_30 ( V_17 -> V_20 ) ;
return true ;
}
return false ;
}
static void F_49 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = & V_17 -> V_20 -> V_21 . V_22 ;
struct V_30 * V_30 = & V_17 -> V_21 . V_30 ;
int V_25 = V_17 -> V_25 ;
int V_54 ;
F_50 (i, vgic_cpu->lr_used, vgic_cpu->nr_lr) {
struct V_65 V_66 = F_51 ( V_17 , V_54 ) ;
if ( ( V_66 . V_67 & V_68 ) == V_69 )
continue;
F_18 ( V_17 , V_66 . V_9 ) ;
if ( V_66 . V_9 < V_70 )
V_19 -> V_71 [ V_25 ] [ V_66 . V_9 ] |= 1 << V_66 . V_72 ;
V_66 . V_67 &= ~ V_73 ;
F_52 ( V_17 , V_54 , V_66 ) ;
if ( ! ( V_66 . V_67 & V_68 ) )
F_53 ( V_54 , V_66 . V_9 , V_17 ) ;
F_30 ( V_17 -> V_20 ) ;
}
}
static bool F_54 ( struct V_16 * V_17 ,
struct V_33 * V_34 ,
T_2 V_4 )
{
struct V_18 * V_19 = & V_17 -> V_20 -> V_21 . V_22 ;
int V_74 ;
int V_75 = ( V_4 & ~ 0x3 ) * 4 ;
int V_76 = V_75 + 3 ;
int V_25 = V_17 -> V_25 ;
T_1 V_6 = 0 ;
for ( V_74 = V_75 ; V_74 <= V_76 ; V_74 ++ ) {
int V_60 = 8 * ( V_74 - V_75 ) ;
V_6 |= ( T_1 ) V_19 -> V_71 [ V_25 ] [ V_74 ] << V_60 ;
}
F_24 ( V_34 , ~ 0 , V_6 ) ;
return false ;
}
static bool F_55 ( struct V_16 * V_17 ,
struct V_33 * V_34 ,
T_2 V_4 , bool V_77 )
{
struct V_18 * V_19 = & V_17 -> V_20 -> V_21 . V_22 ;
int V_74 ;
int V_75 = ( V_4 & ~ 0x3 ) * 4 ;
int V_76 = V_75 + 3 ;
int V_25 = V_17 -> V_25 ;
T_1 V_6 ;
bool V_78 = false ;
V_6 = F_22 ( V_34 , ~ 0 ) ;
for ( V_74 = V_75 ; V_74 <= V_76 ; V_74 ++ ) {
T_4 V_35 = V_6 >> ( 8 * ( V_74 - V_75 ) ) ;
if ( V_77 ) {
if ( ( V_19 -> V_71 [ V_25 ] [ V_74 ] & V_35 ) != V_35 )
V_78 = true ;
V_19 -> V_71 [ V_25 ] [ V_74 ] |= V_35 ;
} else {
if ( V_19 -> V_71 [ V_25 ] [ V_74 ] & V_35 )
V_78 = true ;
V_19 -> V_71 [ V_25 ] [ V_74 ] &= ~ V_35 ;
}
}
if ( V_78 )
F_30 ( V_17 -> V_20 ) ;
return V_78 ;
}
static bool F_56 ( struct V_16 * V_17 ,
struct V_33 * V_34 ,
T_2 V_4 )
{
if ( ! V_34 -> V_44 )
return F_54 ( V_17 , V_34 , V_4 ) ;
else
return F_55 ( V_17 , V_34 , V_4 , true ) ;
}
static bool F_57 ( struct V_16 * V_17 ,
struct V_33 * V_34 ,
T_2 V_4 )
{
if ( ! V_34 -> V_44 )
return F_54 ( V_17 , V_34 , V_4 ) ;
else
return F_55 ( V_17 , V_34 , V_4 , false ) ;
}
static const
struct V_79 * F_58 ( const struct V_79 * V_80 ,
struct V_33 * V_34 ,
T_2 V_4 )
{
const struct V_79 * V_81 = V_80 ;
while ( V_81 -> V_40 ) {
if ( V_4 >= V_81 -> V_82 &&
( V_4 + V_34 -> V_40 ) <= ( V_81 -> V_82 + V_81 -> V_40 ) )
return V_81 ;
V_81 ++ ;
}
return NULL ;
}
bool F_59 ( struct V_16 * V_17 , struct V_83 * V_84 ,
struct V_33 * V_34 )
{
const struct V_79 * V_85 ;
struct V_18 * V_19 = & V_17 -> V_20 -> V_21 . V_22 ;
unsigned long V_82 = V_19 -> V_86 ;
bool V_87 ;
unsigned long V_4 ;
if ( ! F_60 ( V_17 -> V_20 ) ||
V_34 -> V_88 < V_82 ||
( V_34 -> V_88 + V_34 -> V_40 ) > ( V_82 + V_89 ) )
return false ;
if ( V_34 -> V_40 > 4 ) {
F_61 ( V_17 , V_34 -> V_88 ) ;
return true ;
}
V_4 = V_34 -> V_88 - V_82 ;
V_85 = F_58 ( V_90 , V_34 , V_4 ) ;
if ( F_8 ( ! V_85 || ! V_85 -> V_91 ) ) {
F_62 ( L_1 ,
V_34 -> V_44 , V_34 -> V_88 , V_34 -> V_40 ) ;
return false ;
}
F_63 ( & V_17 -> V_20 -> V_21 . V_22 . V_92 ) ;
V_4 = V_34 -> V_88 - V_85 -> V_82 - V_82 ;
V_87 = V_85 -> V_91 ( V_17 , V_34 , V_4 ) ;
F_64 ( & V_17 -> V_20 -> V_21 . V_22 . V_92 ) ;
F_65 ( V_84 , V_34 ) ;
F_66 ( V_17 , V_84 ) ;
if ( V_87 )
F_67 ( V_17 -> V_20 ) ;
return true ;
}
static void F_48 ( struct V_16 * V_17 , T_1 V_6 )
{
struct V_20 * V_20 = V_17 -> V_20 ;
struct V_18 * V_19 = & V_20 -> V_21 . V_22 ;
int V_93 = F_31 ( & V_20 -> V_50 ) ;
T_4 V_94 ;
int V_74 , V_38 , V_57 , V_25 ;
V_25 = V_17 -> V_25 ;
V_74 = V_6 & 0xf ;
V_94 = ( V_6 >> 16 ) & 0xff ;
V_38 = ( V_6 >> 24 ) & 3 ;
switch ( V_38 ) {
case 0 :
if ( ! V_94 )
return;
break;
case 1 :
V_94 = ( ( 1 << V_93 ) - 1 ) & ~ ( 1 << V_25 ) & 0xff ;
break;
case 2 :
V_94 = 1 << V_25 ;
break;
}
F_42 (c, vcpu, kvm) {
if ( V_94 & 1 ) {
F_18 ( V_17 , V_74 ) ;
V_19 -> V_71 [ V_57 ] [ V_74 ] |= 1 << V_25 ;
F_68 ( L_2 , V_74 , V_25 , V_57 ) ;
}
V_94 >>= 1 ;
}
}
static int F_69 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = & V_17 -> V_20 -> V_21 . V_22 ;
unsigned long * V_95 , * V_49 , * V_96 , * V_97 ;
unsigned long V_98 , V_32 ;
int V_25 ;
V_25 = V_17 -> V_25 ;
V_96 = V_17 -> V_21 . V_30 . V_31 ;
V_97 = V_17 -> V_21 . V_30 . V_32 ;
V_95 = F_7 ( & V_19 -> V_29 , V_25 ) ;
V_49 = F_7 ( & V_19 -> V_27 , V_25 ) ;
F_70 ( V_96 , V_95 , V_49 , V_10 ) ;
V_95 = F_9 ( & V_19 -> V_29 ) ;
V_49 = F_9 ( & V_19 -> V_27 ) ;
F_70 ( V_97 , V_95 , V_49 , V_99 ) ;
F_70 ( V_97 , V_97 ,
F_9 ( & V_19 -> V_62 [ V_25 ] ) ,
V_99 ) ;
V_98 = F_71 ( V_96 , V_10 ) ;
V_32 = F_71 ( V_97 , V_99 ) ;
return ( V_98 < V_10 ||
V_32 < V_99 ) ;
}
static void F_30 ( struct V_20 * V_20 )
{
struct V_18 * V_19 = & V_20 -> V_21 . V_22 ;
struct V_16 * V_17 ;
int V_57 ;
if ( ! V_19 -> V_49 ) {
F_5 ( 0 , & V_19 -> V_100 ) ;
return;
}
F_42 (c, vcpu, kvm) {
if ( F_69 ( V_17 ) ) {
F_72 ( L_3 , V_57 ) ;
F_5 ( V_57 , & V_19 -> V_100 ) ;
}
}
}
static struct V_65 F_51 ( const struct V_16 * V_17 , int V_66 )
{
return V_101 -> V_102 ( V_17 , V_66 ) ;
}
static void F_52 ( struct V_16 * V_17 , int V_66 ,
struct V_65 V_103 )
{
V_101 -> V_104 ( V_17 , V_66 , V_103 ) ;
}
static void F_73 ( struct V_16 * V_17 , int V_66 ,
struct V_65 V_103 )
{
V_101 -> V_105 ( V_17 , V_66 , V_103 ) ;
}
static inline T_5 F_74 ( struct V_16 * V_17 )
{
return V_101 -> V_106 ( V_17 ) ;
}
static inline T_5 F_75 ( struct V_16 * V_17 )
{
return V_101 -> V_107 ( V_17 ) ;
}
static inline T_1 F_76 ( struct V_16 * V_17 )
{
return V_101 -> V_108 ( V_17 ) ;
}
static inline void F_77 ( struct V_16 * V_17 )
{
V_101 -> V_109 ( V_17 ) ;
}
static inline void F_78 ( struct V_16 * V_17 )
{
V_101 -> V_110 ( V_17 ) ;
}
static inline void F_79 ( struct V_16 * V_17 , struct V_111 * V_112 )
{
V_101 -> V_113 ( V_17 , V_112 ) ;
}
static void F_80 ( struct V_16 * V_17 , struct V_111 * V_112 )
{
V_101 -> V_114 ( V_17 , V_112 ) ;
}
static inline void F_81 ( struct V_16 * V_17 )
{
V_101 -> V_115 ( V_17 ) ;
}
static void F_53 ( int V_116 , int V_9 , struct V_16 * V_17 )
{
struct V_30 * V_30 = & V_17 -> V_21 . V_30 ;
struct V_65 V_103 = F_51 ( V_17 , V_116 ) ;
V_103 . V_67 = 0 ;
F_52 ( V_17 , V_116 , V_103 ) ;
F_6 ( V_116 , V_30 -> V_117 ) ;
V_30 -> V_118 [ V_9 ] = V_119 ;
}
static void F_35 ( struct V_16 * V_17 )
{
struct V_30 * V_30 = & V_17 -> V_21 . V_30 ;
int V_66 ;
F_50 (lr, vgic_cpu->lr_used, vgic->nr_lr) {
struct V_65 V_103 = F_51 ( V_17 , V_66 ) ;
if ( ! F_13 ( V_17 , V_103 . V_9 ) ) {
F_53 ( V_66 , V_103 . V_9 , V_17 ) ;
if ( F_14 ( V_17 , V_103 . V_9 ) )
F_16 ( V_17 , V_103 . V_9 ) ;
}
}
}
static bool F_82 ( struct V_16 * V_17 , T_4 V_120 , int V_9 )
{
struct V_30 * V_30 = & V_17 -> V_21 . V_30 ;
struct V_65 V_103 ;
int V_66 ;
F_11 ( V_120 & ~ 7 ) ;
F_11 ( V_120 && V_9 >= V_70 ) ;
F_11 ( V_9 >= V_15 ) ;
F_68 ( L_4 , V_9 ) ;
V_66 = V_30 -> V_118 [ V_9 ] ;
if ( V_66 != V_119 ) {
V_103 = F_51 ( V_17 , V_66 ) ;
if ( V_103 . V_72 == V_120 ) {
F_68 ( L_5 , V_66 , V_103 . V_9 ) ;
F_11 ( ! F_3 ( V_66 , V_30 -> V_117 ) ) ;
V_103 . V_67 |= V_73 ;
F_52 ( V_17 , V_66 , V_103 ) ;
return true ;
}
}
V_66 = F_83 ( ( unsigned long * ) V_30 -> V_117 ,
V_22 -> V_121 ) ;
if ( V_66 >= V_22 -> V_121 )
return false ;
F_68 ( L_6 , V_66 , V_9 , V_120 ) ;
V_30 -> V_118 [ V_9 ] = V_66 ;
F_5 ( V_66 , V_30 -> V_117 ) ;
V_103 . V_9 = V_9 ;
V_103 . V_72 = V_120 ;
V_103 . V_67 = V_73 ;
if ( ! F_12 ( V_17 , V_9 ) )
V_103 . V_67 |= V_122 ;
F_52 ( V_17 , V_66 , V_103 ) ;
return true ;
}
static bool F_84 ( struct V_16 * V_17 , int V_9 )
{
struct V_18 * V_19 = & V_17 -> V_20 -> V_21 . V_22 ;
unsigned long V_123 ;
int V_25 = V_17 -> V_25 ;
int V_57 ;
V_123 = V_19 -> V_71 [ V_25 ] [ V_9 ] ;
F_50 (c, &sources, VGIC_MAX_CPUS) {
if ( F_82 ( V_17 , V_57 , V_9 ) )
F_6 ( V_57 , & V_123 ) ;
}
V_19 -> V_71 [ V_25 ] [ V_9 ] = V_123 ;
if ( ! V_123 ) {
F_19 ( V_17 , V_9 ) ;
F_21 ( V_17 , V_9 ) ;
return true ;
}
return false ;
}
static bool F_85 ( struct V_16 * V_17 , int V_9 )
{
if ( F_14 ( V_17 , V_9 ) )
return true ;
if ( F_82 ( V_17 , 0 , V_9 ) ) {
if ( F_12 ( V_17 , V_9 ) ) {
F_19 ( V_17 , V_9 ) ;
F_21 ( V_17 , V_9 ) ;
} else {
F_15 ( V_17 , V_9 ) ;
}
return true ;
}
return false ;
}
static void F_86 ( struct V_16 * V_17 )
{
struct V_30 * V_30 = & V_17 -> V_21 . V_30 ;
struct V_18 * V_19 = & V_17 -> V_20 -> V_21 . V_22 ;
int V_54 , V_25 ;
int V_124 = 0 ;
V_25 = V_17 -> V_25 ;
if ( ! F_87 ( V_17 ) ) {
F_72 ( L_7 , V_25 ) ;
goto V_125;
}
F_50 (i, vgic_cpu->pending_percpu, VGIC_NR_SGIS) {
if ( ! F_84 ( V_17 , V_54 ) )
V_124 = 1 ;
}
F_88 (i, vgic_cpu->pending_percpu, VGIC_NR_PRIVATE_IRQS) {
if ( ! F_85 ( V_17 , V_54 ) )
V_124 = 1 ;
}
F_50 (i, vgic_cpu->pending_shared, VGIC_NR_SHARED_IRQS) {
if ( ! F_85 ( V_17 , V_54 + V_10 ) )
V_124 = 1 ;
}
V_125:
if ( V_124 ) {
F_77 ( V_17 ) ;
} else {
F_78 ( V_17 ) ;
F_6 ( V_25 , & V_19 -> V_100 ) ;
}
}
static bool F_89 ( struct V_16 * V_17 )
{
T_1 V_126 = F_76 ( V_17 ) ;
bool V_127 = false ;
F_68 ( L_8 , V_126 ) ;
if ( V_126 & V_128 ) {
T_5 V_129 = F_75 ( V_17 ) ;
unsigned long * V_130 = ( unsigned long * ) & V_129 ;
int V_66 ;
F_50 (lr, eisr_ptr, vgic->nr_lr) {
struct V_65 V_103 = F_51 ( V_17 , V_66 ) ;
F_16 ( V_17 , V_103 . V_9 ) ;
F_90 ( V_103 . V_67 & V_68 ) ;
V_103 . V_67 = 0 ;
F_52 ( V_17 , V_66 , V_103 ) ;
if ( F_17 ( V_17 , V_103 . V_9 ) ) {
F_20 ( V_17 , V_103 . V_9 ) ;
V_127 = true ;
} else {
F_21 ( V_17 , V_103 . V_9 ) ;
}
F_73 ( V_17 , V_66 , V_103 ) ;
}
}
if ( V_126 & V_131 )
F_78 ( V_17 ) ;
return V_127 ;
}
static void F_91 ( struct V_16 * V_17 )
{
struct V_30 * V_30 = & V_17 -> V_21 . V_30 ;
struct V_18 * V_19 = & V_17 -> V_20 -> V_21 . V_22 ;
T_5 V_132 ;
unsigned long * V_133 ;
int V_66 , V_95 ;
bool V_127 ;
V_127 = F_89 ( V_17 ) ;
V_132 = F_74 ( V_17 ) ;
V_133 = ( unsigned long * ) & V_132 ;
F_50 (lr, elrsr_ptr, vgic->nr_lr) {
struct V_65 V_103 ;
if ( ! F_92 ( V_66 , V_30 -> V_117 ) )
continue;
V_103 = F_51 ( V_17 , V_66 ) ;
F_11 ( V_103 . V_9 >= V_15 ) ;
V_30 -> V_118 [ V_103 . V_9 ] = V_119 ;
}
V_95 = F_83 ( V_133 , V_22 -> V_121 ) ;
if ( V_127 || V_95 < V_22 -> V_121 )
F_5 ( V_17 -> V_25 , & V_19 -> V_100 ) ;
}
void F_93 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = & V_17 -> V_20 -> V_21 . V_22 ;
if ( ! F_60 ( V_17 -> V_20 ) )
return;
F_63 ( & V_19 -> V_92 ) ;
F_86 ( V_17 ) ;
F_64 ( & V_19 -> V_92 ) ;
}
void F_94 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = & V_17 -> V_20 -> V_21 . V_22 ;
if ( ! F_60 ( V_17 -> V_20 ) )
return;
F_63 ( & V_19 -> V_92 ) ;
F_91 ( V_17 ) ;
F_64 ( & V_19 -> V_92 ) ;
}
int F_87 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = & V_17 -> V_20 -> V_21 . V_22 ;
if ( ! F_60 ( V_17 -> V_20 ) )
return 0 ;
return F_3 ( V_17 -> V_25 , & V_19 -> V_100 ) ;
}
static void F_67 ( struct V_20 * V_20 )
{
struct V_16 * V_17 ;
int V_57 ;
F_42 (c, vcpu, kvm) {
if ( F_87 ( V_17 ) )
F_95 ( V_17 ) ;
}
}
static int F_96 ( struct V_16 * V_17 , int V_9 , int V_134 )
{
int V_135 = F_12 ( V_17 , V_9 ) ;
int V_67 = F_17 ( V_17 , V_9 ) ;
if ( V_135 )
return V_134 > V_67 ;
else
return V_134 != V_67 ;
}
static bool F_97 ( struct V_20 * V_20 , int V_3 ,
unsigned int V_136 , bool V_134 )
{
struct V_18 * V_19 = & V_20 -> V_21 . V_22 ;
struct V_16 * V_17 ;
int V_135 , V_137 ;
int V_49 ;
bool V_138 = true ;
F_63 ( & V_19 -> V_92 ) ;
V_17 = F_98 ( V_20 , V_3 ) ;
V_135 = F_12 ( V_17 , V_136 ) ;
V_137 = ! V_135 ;
if ( ! F_96 ( V_17 , V_136 , V_134 ) ) {
V_138 = false ;
goto V_139;
}
if ( V_136 >= V_10 ) {
V_3 = V_19 -> V_56 [ V_136 - V_10 ] ;
V_17 = F_98 ( V_20 , V_3 ) ;
}
F_68 ( L_9 , V_136 , V_134 , V_3 ) ;
if ( V_134 )
F_18 ( V_17 , V_136 ) ;
else
F_19 ( V_17 , V_136 ) ;
V_49 = F_13 ( V_17 , V_136 ) ;
if ( ! V_49 ) {
V_138 = false ;
goto V_139;
}
if ( V_137 && F_14 ( V_17 , V_136 ) ) {
V_138 = false ;
goto V_139;
}
if ( V_134 ) {
F_20 ( V_17 , V_136 ) ;
F_5 ( V_3 , & V_19 -> V_100 ) ;
}
V_139:
F_64 ( & V_19 -> V_92 ) ;
return V_138 ;
}
int F_99 ( struct V_20 * V_20 , int V_3 , unsigned int V_136 ,
bool V_134 )
{
if ( F_97 ( V_20 , V_3 , V_136 , V_134 ) )
F_67 ( V_20 ) ;
return 0 ;
}
static T_6 F_100 ( int V_9 , void * V_36 )
{
return V_140 ;
}
int F_101 ( struct V_16 * V_17 )
{
struct V_30 * V_30 = & V_17 -> V_21 . V_30 ;
struct V_18 * V_19 = & V_17 -> V_20 -> V_21 . V_22 ;
int V_54 ;
if ( V_17 -> V_25 >= V_13 )
return - V_141 ;
for ( V_54 = 0 ; V_54 < V_15 ; V_54 ++ ) {
if ( V_54 < V_142 )
F_4 ( & V_19 -> V_27 ,
V_17 -> V_25 , V_54 , 1 ) ;
if ( V_54 < V_10 )
F_4 ( & V_19 -> V_24 ,
V_17 -> V_25 , V_54 , V_26 ) ;
V_30 -> V_118 [ V_54 ] = V_119 ;
}
V_30 -> V_121 = V_22 -> V_121 ;
F_81 ( V_17 ) ;
return 0 ;
}
static void F_102 ( void * V_143 )
{
F_103 ( V_22 -> V_144 , 0 ) ;
}
static int F_104 ( struct V_145 * V_146 ,
unsigned long V_147 , void * V_148 )
{
switch ( V_147 ) {
case V_149 :
case V_150 :
F_102 ( NULL ) ;
break;
case V_151 :
case V_152 :
F_105 ( V_22 -> V_144 ) ;
break;
}
return V_153 ;
}
int F_106 ( void )
{
const struct V_154 * V_155 ;
int (* F_107)( struct V_156 * , const struct V_101 * * ,
const struct V_157 * * );
struct V_156 * V_158 ;
int V_138 ;
V_158 = F_108 ( NULL ,
V_159 , & V_155 ) ;
if ( ! V_158 ) {
F_109 ( L_10 ) ;
return - V_160 ;
}
F_107 = V_155 -> V_36 ;
V_138 = F_107 ( V_158 , & V_101 , & V_22 ) ;
if ( V_138 )
return V_138 ;
V_138 = F_110 ( V_22 -> V_144 , F_100 ,
L_11 , F_111 () ) ;
if ( V_138 ) {
F_109 ( L_12 , V_22 -> V_144 ) ;
return V_138 ;
}
V_138 = F_112 ( & V_161 ) ;
if ( V_138 ) {
F_109 ( L_13 ) ;
goto V_162;
}
F_113 ( V_22 ) ;
F_114 ( F_102 , NULL , 1 ) ;
return 0 ;
V_162:
F_115 ( V_22 -> V_144 , F_111 () ) ;
return V_138 ;
}
int F_116 ( struct V_20 * V_20 )
{
int V_138 = 0 , V_54 ;
if ( ! F_60 ( V_20 ) )
return 0 ;
F_117 ( & V_20 -> V_92 ) ;
if ( F_118 ( V_20 ) )
goto V_139;
if ( F_119 ( V_20 -> V_21 . V_22 . V_86 ) ||
F_119 ( V_20 -> V_21 . V_22 . V_163 ) ) {
F_109 ( L_14 ) ;
V_138 = - V_164 ;
goto V_139;
}
V_138 = F_120 ( V_20 , V_20 -> V_21 . V_22 . V_163 ,
V_22 -> V_165 , V_166 ) ;
if ( V_138 ) {
F_109 ( L_15 ) ;
goto V_139;
}
for ( V_54 = V_10 ; V_54 < V_15 ; V_54 += 4 )
F_40 ( V_20 , 0 , V_54 ) ;
V_20 -> V_21 . V_22 . V_167 = true ;
V_139:
F_121 ( & V_20 -> V_92 ) ;
return V_138 ;
}
int F_122 ( struct V_20 * V_20 )
{
int V_54 , V_168 = - 1 , V_138 = 0 ;
struct V_16 * V_17 ;
F_117 ( & V_20 -> V_92 ) ;
if ( V_20 -> V_21 . V_22 . V_169 ) {
V_138 = - V_170 ;
goto V_139;
}
F_42 (i, vcpu, kvm) {
if ( ! F_123 ( & V_17 -> V_171 ) )
goto V_172;
V_168 = V_54 ;
}
F_42 (i, vcpu, kvm) {
if ( V_17 -> V_21 . V_173 ) {
V_138 = - V_141 ;
goto V_172;
}
}
F_124 ( & V_20 -> V_21 . V_22 . V_92 ) ;
V_20 -> V_21 . V_22 . V_174 = true ;
V_20 -> V_21 . V_22 . V_169 = V_22 -> V_169 ;
V_20 -> V_21 . V_22 . V_86 = V_175 ;
V_20 -> V_21 . V_22 . V_163 = V_175 ;
V_172:
for (; V_168 >= 0 ; V_168 -- ) {
V_17 = F_98 ( V_20 , V_168 ) ;
F_121 ( & V_17 -> V_171 ) ;
}
V_139:
F_121 ( & V_20 -> V_92 ) ;
return V_138 ;
}
static bool F_125 ( struct V_20 * V_20 )
{
T_2 V_19 = V_20 -> V_21 . V_22 . V_86 ;
T_2 V_148 = V_20 -> V_21 . V_22 . V_163 ;
if ( F_119 ( V_19 ) || F_119 ( V_148 ) )
return 0 ;
if ( ( V_19 <= V_148 && V_19 + V_89 > V_148 ) ||
( V_148 <= V_19 && V_148 + V_166 > V_19 ) )
return - V_141 ;
return 0 ;
}
static int F_126 ( struct V_20 * V_20 , T_2 * V_176 ,
T_2 V_177 , T_2 V_178 )
{
int V_138 ;
if ( V_177 & ~ V_179 )
return - V_180 ;
if ( V_177 & ( V_181 - 1 ) )
return - V_182 ;
if ( ! F_119 ( * V_176 ) )
return - V_170 ;
if ( V_177 + V_178 < V_177 )
return - V_182 ;
* V_176 = V_177 ;
V_138 = F_125 ( V_20 ) ;
if ( V_138 )
* V_176 = V_175 ;
return V_138 ;
}
int F_127 ( struct V_20 * V_20 , unsigned long type , T_5 * V_177 , bool V_183 )
{
int V_81 = 0 ;
struct V_18 * V_22 = & V_20 -> V_21 . V_22 ;
F_117 ( & V_20 -> V_92 ) ;
switch ( type ) {
case V_184 :
if ( V_183 ) {
V_81 = F_126 ( V_20 , & V_22 -> V_86 ,
* V_177 , V_89 ) ;
} else {
* V_177 = V_22 -> V_86 ;
}
break;
case V_185 :
if ( V_183 ) {
V_81 = F_126 ( V_20 , & V_22 -> V_163 ,
* V_177 , V_166 ) ;
} else {
* V_177 = V_22 -> V_163 ;
}
break;
default:
V_81 = - V_160 ;
}
F_121 ( & V_20 -> V_92 ) ;
return V_81 ;
}
static bool F_128 ( struct V_16 * V_17 ,
struct V_33 * V_34 , T_2 V_4 )
{
bool V_78 = false ;
struct V_111 V_112 ;
T_1 * V_186 ;
T_1 V_6 ;
F_79 ( V_17 , & V_112 ) ;
switch ( V_4 & ~ 0x3 ) {
case V_187 :
V_186 = & V_112 . V_188 ;
break;
case V_189 :
V_186 = & V_112 . V_190 ;
break;
case V_191 :
V_186 = & V_112 . V_192 ;
break;
case V_193 :
V_186 = & V_112 . V_194 ;
break;
default:
F_129 () ;
}
if ( ! V_34 -> V_44 ) {
V_6 = * V_186 ;
F_24 ( V_34 , ~ 0 , V_6 ) ;
} else {
V_6 = F_22 ( V_34 , ~ 0 ) ;
if ( V_6 != * V_186 ) {
* V_186 = V_6 ;
F_80 ( V_17 , & V_112 ) ;
V_78 = true ;
}
}
return V_78 ;
}
static bool F_130 ( struct V_16 * V_17 ,
struct V_33 * V_34 , T_2 V_4 )
{
return F_128 ( V_17 , V_34 , V_193 ) ;
}
static bool F_131 ( struct V_16 * V_17 ,
struct V_33 * V_34 ,
T_2 V_4 )
{
T_1 V_6 ;
if ( V_34 -> V_44 )
return false ;
V_6 = ( V_51 << 20 ) |
( V_195 << 16 ) |
( V_52 << 0 ) ;
F_24 ( V_34 , ~ 0 , V_6 ) ;
return false ;
}
static int F_132 ( struct V_196 * V_197 ,
struct V_198 * V_199 ,
T_1 * V_6 , bool V_44 )
{
const struct V_79 * V_81 = NULL , * V_80 ;
T_2 V_4 ;
int V_138 , V_3 , V_57 ;
struct V_16 * V_17 , * V_200 ;
struct V_18 * V_22 ;
struct V_33 V_34 ;
V_4 = V_199 -> V_199 & V_201 ;
V_3 = ( V_199 -> V_199 & V_202 ) >>
V_203 ;
F_117 ( & V_197 -> V_20 -> V_92 ) ;
if ( V_3 >= F_31 ( & V_197 -> V_20 -> V_50 ) ) {
V_138 = - V_182 ;
goto V_139;
}
V_17 = F_98 ( V_197 -> V_20 , V_3 ) ;
V_22 = & V_197 -> V_20 -> V_21 . V_22 ;
V_34 . V_40 = 4 ;
V_34 . V_44 = V_44 ;
if ( V_44 )
F_24 ( & V_34 , ~ 0 , * V_6 ) ;
switch ( V_199 -> V_204 ) {
case V_205 :
V_34 . V_88 = V_22 -> V_86 + V_4 ;
V_80 = V_90 ;
break;
case V_206 :
V_34 . V_88 = V_22 -> V_163 + V_4 ;
V_80 = V_207 ;
break;
default:
F_129 () ;
}
V_81 = F_58 ( V_80 , & V_34 , V_4 ) ;
if ( F_8 ( ! V_81 || ! V_81 -> V_91 ) ) {
V_138 = - V_164 ;
goto V_139;
}
F_63 ( & V_22 -> V_92 ) ;
F_42 (c, tmp_vcpu, dev->kvm) {
if ( F_8 ( V_200 -> V_148 != - 1 ) ) {
V_138 = - V_141 ;
goto V_208;
}
}
F_42 (c, tmp_vcpu, dev->kvm)
F_49 ( V_200 ) ;
V_4 -= V_81 -> V_82 ;
V_81 -> V_91 ( V_17 , & V_34 , V_4 ) ;
if ( ! V_44 )
* V_6 = F_22 ( & V_34 , ~ 0 ) ;
V_138 = 0 ;
V_208:
F_64 ( & V_22 -> V_92 ) ;
V_139:
F_121 ( & V_197 -> V_20 -> V_92 ) ;
return V_138 ;
}
static int F_133 ( struct V_196 * V_197 , struct V_198 * V_199 )
{
int V_81 ;
switch ( V_199 -> V_204 ) {
case V_209 : {
T_5 T_7 * V_210 = ( T_5 T_7 * ) ( long ) V_199 -> V_177 ;
T_5 V_177 ;
unsigned long type = ( unsigned long ) V_199 -> V_199 ;
if ( F_134 ( & V_177 , V_210 , sizeof( V_177 ) ) )
return - V_211 ;
V_81 = F_127 ( V_197 -> V_20 , type , & V_177 , true ) ;
return ( V_81 == - V_160 ) ? - V_164 : V_81 ;
}
case V_205 :
case V_206 : {
T_1 T_7 * V_210 = ( T_1 T_7 * ) ( long ) V_199 -> V_177 ;
T_1 V_6 ;
if ( F_135 ( V_6 , V_210 ) )
return - V_211 ;
return F_132 ( V_197 , V_199 , & V_6 , true ) ;
}
}
return - V_164 ;
}
static int F_136 ( struct V_196 * V_197 , struct V_198 * V_199 )
{
int V_81 = - V_164 ;
switch ( V_199 -> V_204 ) {
case V_209 : {
T_5 T_7 * V_210 = ( T_5 T_7 * ) ( long ) V_199 -> V_177 ;
T_5 V_177 ;
unsigned long type = ( unsigned long ) V_199 -> V_199 ;
V_81 = F_127 ( V_197 -> V_20 , type , & V_177 , false ) ;
if ( V_81 )
return ( V_81 == - V_160 ) ? - V_164 : V_81 ;
if ( F_137 ( V_210 , & V_177 , sizeof( V_177 ) ) )
return - V_211 ;
break;
}
case V_205 :
case V_206 : {
T_1 T_7 * V_210 = ( T_1 T_7 * ) ( long ) V_199 -> V_177 ;
T_1 V_6 = 0 ;
V_81 = F_132 ( V_197 , V_199 , & V_6 , false ) ;
if ( V_81 )
return V_81 ;
V_81 = F_138 ( V_6 , V_210 ) ;
break;
}
}
return V_81 ;
}
static int F_139 ( const struct V_79 * V_80 ,
T_2 V_4 )
{
struct V_33 V_212 ;
V_212 . V_40 = 4 ;
if ( F_58 ( V_80 , & V_212 , V_4 ) )
return 0 ;
else
return - V_164 ;
}
static int F_140 ( struct V_196 * V_197 , struct V_198 * V_199 )
{
T_2 V_4 ;
switch ( V_199 -> V_204 ) {
case V_209 :
switch ( V_199 -> V_199 ) {
case V_184 :
case V_185 :
return 0 ;
}
break;
case V_205 :
V_4 = V_199 -> V_199 & V_201 ;
return F_139 ( V_90 , V_4 ) ;
case V_206 :
V_4 = V_199 -> V_199 & V_201 ;
return F_139 ( V_207 , V_4 ) ;
}
return - V_164 ;
}
static void F_141 ( struct V_196 * V_197 )
{
F_142 ( V_197 ) ;
}
static int F_143 ( struct V_196 * V_197 , T_1 type )
{
return F_122 ( V_197 -> V_20 ) ;
}

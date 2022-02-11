static T_1 * F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
V_4 >>= 2 ;
if ( ! V_4 )
return V_2 -> V_5 [ V_3 ] . V_6 ;
else
return V_2 -> V_7 . V_6 + V_4 - 1 ;
}
static int F_2 ( struct V_1 * V_2 ,
int V_3 , int V_8 )
{
if ( V_8 < V_9 )
return F_3 ( V_8 , V_2 -> V_5 [ V_3 ] . V_10 ) ;
return F_3 ( V_8 - V_9 , V_2 -> V_7 . V_10 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_3 ,
int V_8 , int V_11 )
{
unsigned long * V_6 ;
if ( V_8 < V_9 ) {
V_6 = V_2 -> V_5 [ V_3 ] . V_10 ;
} else {
V_6 = V_2 -> V_7 . V_10 ;
V_8 -= V_9 ;
}
if ( V_11 )
F_5 ( V_8 , V_6 ) ;
else
F_6 ( V_8 , V_6 ) ;
}
static unsigned long * F_7 ( struct V_1 * V_2 , int V_3 )
{
if ( F_8 ( V_3 >= V_12 ) )
return NULL ;
return V_2 -> V_5 [ V_3 ] . V_10 ;
}
static unsigned long * F_9 ( struct V_1 * V_2 )
{
return V_2 -> V_7 . V_10 ;
}
static T_1 * F_10 ( struct V_13 * V_2 , int V_3 , T_1 V_4 )
{
V_4 >>= 2 ;
F_11 ( V_4 > ( V_14 / 4 ) ) ;
if ( V_4 < 8 )
return V_2 -> V_5 [ V_3 ] + V_4 ;
else
return V_2 -> V_7 + V_4 - 8 ;
}
static bool F_12 ( struct V_15 * V_16 , int V_8 )
{
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
int V_22 ;
V_22 = F_2 ( & V_18 -> V_23 , V_16 -> V_24 , V_8 ) ;
return V_22 == V_25 ;
}
static int F_13 ( struct V_15 * V_16 , int V_8 )
{
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
return F_2 ( & V_18 -> V_26 , V_16 -> V_24 , V_8 ) ;
}
static int F_14 ( struct V_15 * V_16 , int V_8 )
{
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
return F_2 ( & V_18 -> V_27 , V_16 -> V_24 , V_8 ) ;
}
static void F_15 ( struct V_15 * V_16 , int V_8 )
{
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
F_4 ( & V_18 -> V_27 , V_16 -> V_24 , V_8 , 1 ) ;
}
static void F_16 ( struct V_15 * V_16 , int V_8 )
{
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
F_4 ( & V_18 -> V_27 , V_16 -> V_24 , V_8 , 0 ) ;
}
static int F_17 ( struct V_15 * V_16 , int V_8 )
{
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
return F_2 ( & V_18 -> V_28 , V_16 -> V_24 , V_8 ) ;
}
static void F_18 ( struct V_15 * V_16 , int V_8 )
{
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
F_4 ( & V_18 -> V_28 , V_16 -> V_24 , V_8 , 1 ) ;
}
static void F_19 ( struct V_15 * V_16 , int V_8 )
{
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
F_4 ( & V_18 -> V_28 , V_16 -> V_24 , V_8 , 0 ) ;
}
static void F_20 ( struct V_15 * V_16 , int V_8 )
{
if ( V_8 < V_9 )
F_5 ( V_8 , V_16 -> V_20 . V_29 . V_30 ) ;
else
F_5 ( V_8 - V_9 ,
V_16 -> V_20 . V_29 . V_31 ) ;
}
static void F_21 ( struct V_15 * V_16 , int V_8 )
{
if ( V_8 < V_9 )
F_6 ( V_8 , V_16 -> V_20 . V_29 . V_30 ) ;
else
F_6 ( V_8 - V_9 ,
V_16 -> V_20 . V_29 . V_31 ) ;
}
static T_1 F_22 ( struct V_32 * V_33 , T_1 V_34 )
{
return * ( ( T_1 * ) V_33 -> V_35 ) & V_34 ;
}
static void F_23 ( struct V_32 * V_33 , T_1 V_34 , T_1 V_36 )
{
* ( ( T_1 * ) V_33 -> V_35 ) = V_36 & V_34 ;
}
static void F_24 ( struct V_32 * V_33 , T_1 * V_6 ,
T_2 V_4 , int V_37 )
{
int V_38 = ( V_4 & 3 ) * 8 ;
T_1 V_34 = ( 1UL << ( V_33 -> V_39 * 8 ) ) - 1 ;
T_1 V_40 ;
if ( V_6 ) {
V_40 = * V_6 ;
} else {
F_11 ( V_37 != ( V_41 | V_42 ) ) ;
V_40 = 0 ;
}
if ( V_33 -> V_43 ) {
T_1 V_35 = F_22 ( V_33 , V_34 ) << V_38 ;
switch ( F_25 ( V_37 ) ) {
case V_42 :
return;
case V_44 :
V_40 |= V_35 ;
break;
case V_45 :
V_40 &= ~ V_35 ;
break;
case V_46 :
V_40 = ( V_40 & ~ ( V_34 << V_38 ) ) | V_35 ;
break;
}
* V_6 = V_40 ;
} else {
switch ( F_26 ( V_37 ) ) {
case V_41 :
V_40 = 0 ;
case V_47 :
F_23 ( V_33 , V_34 , V_40 >> V_38 ) ;
}
}
}
static bool F_27 ( struct V_15 * V_16 ,
struct V_32 * V_33 , T_2 V_4 )
{
T_1 V_6 ;
T_1 V_38 = V_4 & 3 ;
switch ( V_4 & ~ 3 ) {
case 0 :
V_6 = V_16 -> V_19 -> V_20 . V_21 . V_48 ;
F_24 ( V_33 , & V_6 , V_38 ,
V_47 | V_46 ) ;
if ( V_33 -> V_43 ) {
V_16 -> V_19 -> V_20 . V_21 . V_48 = V_6 & 1 ;
F_28 ( V_16 -> V_19 ) ;
return true ;
}
break;
case 4 :
V_6 = ( F_29 ( & V_16 -> V_19 -> V_49 ) - 1 ) << 5 ;
V_6 |= ( V_14 >> 5 ) - 1 ;
F_24 ( V_33 , & V_6 , V_38 ,
V_47 | V_42 ) ;
break;
case 8 :
V_6 = ( V_50 << 24 ) | ( V_51 << 0 ) ;
F_24 ( V_33 , & V_6 , V_38 ,
V_47 | V_42 ) ;
break;
}
return false ;
}
static bool F_30 ( struct V_15 * V_16 ,
struct V_32 * V_33 , T_2 V_4 )
{
F_24 ( V_33 , NULL , V_4 ,
V_41 | V_42 ) ;
return false ;
}
static bool F_31 ( struct V_15 * V_16 ,
struct V_32 * V_33 ,
T_2 V_4 )
{
T_1 * V_6 = F_1 ( & V_16 -> V_19 -> V_20 . V_21 . V_26 ,
V_16 -> V_24 , V_4 ) ;
F_24 ( V_33 , V_6 , V_4 ,
V_47 | V_44 ) ;
if ( V_33 -> V_43 ) {
F_28 ( V_16 -> V_19 ) ;
return true ;
}
return false ;
}
static bool F_32 ( struct V_15 * V_16 ,
struct V_32 * V_33 ,
T_2 V_4 )
{
T_1 * V_6 = F_1 ( & V_16 -> V_19 -> V_20 . V_21 . V_26 ,
V_16 -> V_24 , V_4 ) ;
F_24 ( V_33 , V_6 , V_4 ,
V_47 | V_45 ) ;
if ( V_33 -> V_43 ) {
if ( V_4 < 4 )
* V_6 |= 0xffff ;
F_33 ( V_16 ) ;
F_28 ( V_16 -> V_19 ) ;
return true ;
}
return false ;
}
static bool F_34 ( struct V_15 * V_16 ,
struct V_32 * V_33 ,
T_2 V_4 )
{
T_1 * V_6 = F_1 ( & V_16 -> V_19 -> V_20 . V_21 . V_28 ,
V_16 -> V_24 , V_4 ) ;
F_24 ( V_33 , V_6 , V_4 ,
V_47 | V_44 ) ;
if ( V_33 -> V_43 ) {
F_28 ( V_16 -> V_19 ) ;
return true ;
}
return false ;
}
static bool F_35 ( struct V_15 * V_16 ,
struct V_32 * V_33 ,
T_2 V_4 )
{
T_1 * V_6 = F_1 ( & V_16 -> V_19 -> V_20 . V_21 . V_28 ,
V_16 -> V_24 , V_4 ) ;
F_24 ( V_33 , V_6 , V_4 ,
V_47 | V_45 ) ;
if ( V_33 -> V_43 ) {
F_28 ( V_16 -> V_19 ) ;
return true ;
}
return false ;
}
static bool F_36 ( struct V_15 * V_16 ,
struct V_32 * V_33 ,
T_2 V_4 )
{
T_1 * V_6 = F_10 ( & V_16 -> V_19 -> V_20 . V_21 . V_52 ,
V_16 -> V_24 , V_4 ) ;
F_24 ( V_33 , V_6 , V_4 ,
V_47 | V_46 ) ;
return false ;
}
static T_1 F_37 ( struct V_19 * V_19 , int V_8 )
{
struct V_17 * V_18 = & V_19 -> V_20 . V_21 ;
int V_53 ;
T_1 V_11 = 0 ;
V_8 -= V_9 ;
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ )
V_11 |= 1 << ( V_18 -> V_55 [ V_8 + V_53 ] + V_53 * 8 ) ;
return V_11 ;
}
static void F_38 ( struct V_19 * V_19 , T_1 V_11 , int V_8 )
{
struct V_17 * V_18 = & V_19 -> V_20 . V_21 ;
struct V_15 * V_16 ;
int V_53 , V_56 ;
unsigned long * V_57 ;
T_1 V_58 ;
V_8 -= V_9 ;
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ ) {
int V_59 = V_53 * V_60 ;
V_58 = F_39 ( ( V_11 >> V_59 ) & 0xffU ) ;
V_58 = V_58 ? ( V_58 - 1 ) : 0 ;
V_18 -> V_55 [ V_8 + V_53 ] = V_58 ;
F_40 (c, vcpu, kvm) {
V_57 = F_9 ( & V_18 -> V_61 [ V_56 ] ) ;
if ( V_56 == V_58 )
F_5 ( V_8 + V_53 , V_57 ) ;
else
F_6 ( V_8 + V_53 , V_57 ) ;
}
}
}
static bool F_41 ( struct V_15 * V_16 ,
struct V_32 * V_33 ,
T_2 V_4 )
{
T_1 V_6 ;
if ( V_4 < 32 ) {
T_1 V_62 = 1 << V_16 -> V_24 ;
V_62 |= V_62 << 8 ;
V_62 |= V_62 << 16 ;
F_24 ( V_33 , & V_62 , V_4 ,
V_47 | V_42 ) ;
return false ;
}
V_6 = F_37 ( V_16 -> V_19 , V_4 & ~ 3U ) ;
F_24 ( V_33 , & V_6 , V_4 ,
V_47 | V_46 ) ;
if ( V_33 -> V_43 ) {
F_38 ( V_16 -> V_19 , V_6 , V_4 & ~ 3U ) ;
F_28 ( V_16 -> V_19 ) ;
return true ;
}
return false ;
}
static T_1 F_42 ( T_3 V_11 )
{
T_1 V_63 = 0 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < 16 ; V_53 ++ )
V_63 |= ( ( V_11 >> V_53 ) & V_25 ) << ( 2 * V_53 + 1 ) ;
return V_63 ;
}
static T_3 F_43 ( T_1 V_11 )
{
T_3 V_63 = 0 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < 16 ; V_53 ++ )
V_63 |= ( ( V_11 >> ( V_53 * 2 + 1 ) ) & V_25 ) << V_53 ;
return V_63 ;
}
static bool F_44 ( struct V_15 * V_16 ,
struct V_32 * V_33 , T_2 V_4 )
{
T_1 V_11 ;
T_1 * V_6 ;
V_4 >>= 1 ;
V_6 = F_1 ( & V_16 -> V_19 -> V_20 . V_21 . V_23 ,
V_16 -> V_24 , V_4 ) ;
if ( V_4 & 2 )
V_11 = * V_6 >> 16 ;
else
V_11 = * V_6 & 0xffff ;
V_11 = F_42 ( V_11 ) ;
F_24 ( V_33 , & V_11 , V_4 ,
V_47 | V_46 ) ;
if ( V_33 -> V_43 ) {
if ( V_4 < 4 ) {
* V_6 = ~ 0U ;
return false ;
}
V_11 = F_43 ( V_11 ) ;
if ( V_4 & 2 ) {
* V_6 &= 0xffff ;
* V_6 |= V_11 << 16 ;
} else {
* V_6 &= 0xffff << 16 ;
* V_6 |= V_11 ;
}
}
return false ;
}
static bool F_45 ( struct V_15 * V_16 ,
struct V_32 * V_33 , T_2 V_4 )
{
T_1 V_6 ;
F_24 ( V_33 , & V_6 , V_4 ,
V_41 | V_46 ) ;
if ( V_33 -> V_43 ) {
F_46 ( V_16 , V_6 ) ;
F_28 ( V_16 -> V_19 ) ;
return true ;
}
return false ;
}
static void F_47 ( int V_64 , int V_8 , struct V_29 * V_29 )
{
F_6 ( V_64 , V_29 -> V_65 ) ;
V_29 -> V_66 [ V_64 ] &= ~ V_67 ;
V_29 -> V_68 [ V_8 ] = V_69 ;
}
static void F_48 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
struct V_29 * V_29 = & V_16 -> V_20 . V_29 ;
int V_24 = V_16 -> V_24 ;
int V_53 , V_8 , V_70 ;
T_1 * V_71 ;
F_49 (i, vgic_cpu->lr_used, vgic_cpu->nr_lr) {
V_71 = & V_29 -> V_66 [ V_53 ] ;
V_8 = F_50 ( * V_71 ) ;
V_70 = F_51 ( * V_71 ) ;
if ( ( * V_71 & V_67 ) == V_72 )
continue;
F_18 ( V_16 , V_8 ) ;
if ( V_8 < V_73 )
V_18 -> V_74 [ V_24 ] [ V_8 ] |= 1 << V_70 ;
* V_71 &= ~ V_75 ;
if ( ! ( * V_71 & V_67 ) )
F_47 ( V_53 , V_8 , V_29 ) ;
F_28 ( V_16 -> V_19 ) ;
}
}
static bool F_52 ( struct V_15 * V_16 ,
struct V_32 * V_33 ,
T_2 V_4 )
{
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
int V_76 ;
int V_77 = ( V_4 & ~ 0x3 ) * 4 ;
int V_78 = V_77 + 3 ;
int V_24 = V_16 -> V_24 ;
T_1 V_6 = 0 ;
for ( V_76 = V_77 ; V_76 <= V_78 ; V_76 ++ ) {
int V_59 = 8 * ( V_76 - V_77 ) ;
V_6 |= ( T_1 ) V_18 -> V_74 [ V_24 ] [ V_76 ] << V_59 ;
}
F_23 ( V_33 , ~ 0 , V_6 ) ;
return false ;
}
static bool F_53 ( struct V_15 * V_16 ,
struct V_32 * V_33 ,
T_2 V_4 , bool V_79 )
{
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
int V_76 ;
int V_77 = ( V_4 & ~ 0x3 ) * 4 ;
int V_78 = V_77 + 3 ;
int V_24 = V_16 -> V_24 ;
T_1 V_6 ;
bool V_80 = false ;
V_6 = F_22 ( V_33 , ~ 0 ) ;
for ( V_76 = V_77 ; V_76 <= V_78 ; V_76 ++ ) {
T_4 V_34 = V_6 >> ( 8 * ( V_76 - V_77 ) ) ;
if ( V_79 ) {
if ( ( V_18 -> V_74 [ V_24 ] [ V_76 ] & V_34 ) != V_34 )
V_80 = true ;
V_18 -> V_74 [ V_24 ] [ V_76 ] |= V_34 ;
} else {
if ( V_18 -> V_74 [ V_24 ] [ V_76 ] & V_34 )
V_80 = true ;
V_18 -> V_74 [ V_24 ] [ V_76 ] &= ~ V_34 ;
}
}
if ( V_80 )
F_28 ( V_16 -> V_19 ) ;
return V_80 ;
}
static bool F_54 ( struct V_15 * V_16 ,
struct V_32 * V_33 ,
T_2 V_4 )
{
if ( ! V_33 -> V_43 )
return F_52 ( V_16 , V_33 , V_4 ) ;
else
return F_53 ( V_16 , V_33 , V_4 , true ) ;
}
static bool F_55 ( struct V_15 * V_16 ,
struct V_32 * V_33 ,
T_2 V_4 )
{
if ( ! V_33 -> V_43 )
return F_52 ( V_16 , V_33 , V_4 ) ;
else
return F_53 ( V_16 , V_33 , V_4 , false ) ;
}
static const
struct V_81 * F_56 ( const struct V_81 * V_82 ,
struct V_32 * V_33 ,
T_2 V_4 )
{
const struct V_81 * V_83 = V_82 ;
while ( V_83 -> V_39 ) {
if ( V_4 >= V_83 -> V_84 &&
( V_4 + V_33 -> V_39 ) <= ( V_83 -> V_84 + V_83 -> V_39 ) )
return V_83 ;
V_83 ++ ;
}
return NULL ;
}
bool F_57 ( struct V_15 * V_16 , struct V_85 * V_86 ,
struct V_32 * V_33 )
{
const struct V_81 * V_87 ;
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
unsigned long V_84 = V_18 -> V_88 ;
bool V_89 ;
unsigned long V_4 ;
if ( ! F_58 ( V_16 -> V_19 ) ||
V_33 -> V_90 < V_84 ||
( V_33 -> V_90 + V_33 -> V_39 ) > ( V_84 + V_91 ) )
return false ;
if ( V_33 -> V_39 > 4 ) {
F_59 ( V_16 , V_33 -> V_90 ) ;
return true ;
}
V_4 = V_33 -> V_90 - V_84 ;
V_87 = F_56 ( V_92 , V_33 , V_4 ) ;
if ( F_8 ( ! V_87 || ! V_87 -> V_93 ) ) {
F_60 ( L_1 ,
V_33 -> V_43 , V_33 -> V_90 , V_33 -> V_39 ) ;
return false ;
}
F_61 ( & V_16 -> V_19 -> V_20 . V_21 . V_94 ) ;
V_4 = V_33 -> V_90 - V_87 -> V_84 - V_84 ;
V_89 = V_87 -> V_93 ( V_16 , V_33 , V_4 ) ;
F_62 ( & V_16 -> V_19 -> V_20 . V_21 . V_94 ) ;
F_63 ( V_86 , V_33 ) ;
F_64 ( V_16 , V_86 ) ;
if ( V_89 )
F_65 ( V_16 -> V_19 ) ;
return true ;
}
static void F_46 ( struct V_15 * V_16 , T_1 V_6 )
{
struct V_19 * V_19 = V_16 -> V_19 ;
struct V_17 * V_18 = & V_19 -> V_20 . V_21 ;
int V_95 = F_29 ( & V_19 -> V_49 ) ;
T_4 V_96 ;
int V_76 , V_37 , V_56 , V_24 ;
V_24 = V_16 -> V_24 ;
V_76 = V_6 & 0xf ;
V_96 = ( V_6 >> 16 ) & 0xff ;
V_37 = ( V_6 >> 24 ) & 3 ;
switch ( V_37 ) {
case 0 :
if ( ! V_96 )
return;
case 1 :
V_96 = ( ( 1 << V_95 ) - 1 ) & ~ ( 1 << V_24 ) & 0xff ;
break;
case 2 :
V_96 = 1 << V_24 ;
break;
}
F_40 (c, vcpu, kvm) {
if ( V_96 & 1 ) {
F_18 ( V_16 , V_76 ) ;
V_18 -> V_74 [ V_56 ] [ V_76 ] |= 1 << V_24 ;
F_66 ( L_2 , V_76 , V_24 , V_56 ) ;
}
V_96 >>= 1 ;
}
}
static int F_67 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
unsigned long * V_97 , * V_48 , * V_98 , * V_99 ;
unsigned long V_100 , V_31 ;
int V_24 ;
V_24 = V_16 -> V_24 ;
V_98 = V_16 -> V_20 . V_29 . V_30 ;
V_99 = V_16 -> V_20 . V_29 . V_31 ;
V_97 = F_7 ( & V_18 -> V_28 , V_24 ) ;
V_48 = F_7 ( & V_18 -> V_26 , V_24 ) ;
F_68 ( V_98 , V_97 , V_48 , V_9 ) ;
V_97 = F_9 ( & V_18 -> V_28 ) ;
V_48 = F_9 ( & V_18 -> V_26 ) ;
F_68 ( V_99 , V_97 , V_48 , V_101 ) ;
F_68 ( V_99 , V_99 ,
F_9 ( & V_18 -> V_61 [ V_24 ] ) ,
V_101 ) ;
V_100 = F_69 ( V_98 , V_9 ) ;
V_31 = F_69 ( V_99 , V_101 ) ;
return ( V_100 < V_9 ||
V_31 < V_101 ) ;
}
static void F_28 ( struct V_19 * V_19 )
{
struct V_17 * V_18 = & V_19 -> V_20 . V_21 ;
struct V_15 * V_16 ;
int V_56 ;
if ( ! V_18 -> V_48 ) {
F_5 ( 0 , & V_18 -> V_102 ) ;
return;
}
F_40 (c, vcpu, kvm) {
if ( F_67 ( V_16 ) ) {
F_70 ( L_3 , V_56 ) ;
F_5 ( V_56 , & V_18 -> V_102 ) ;
}
}
}
static void F_33 ( struct V_15 * V_16 )
{
struct V_29 * V_29 = & V_16 -> V_20 . V_29 ;
int V_71 ;
F_49 (lr, vgic_cpu->lr_used, vgic_cpu->nr_lr) {
int V_8 = V_29 -> V_66 [ V_71 ] & V_103 ;
if ( ! F_13 ( V_16 , V_8 ) ) {
F_47 ( V_71 , V_8 , V_29 ) ;
if ( F_14 ( V_16 , V_8 ) )
F_16 ( V_16 , V_8 ) ;
}
}
}
static bool F_71 ( struct V_15 * V_16 , T_4 V_104 , int V_8 )
{
struct V_29 * V_29 = & V_16 -> V_20 . V_29 ;
int V_71 ;
F_11 ( V_104 & ~ 7 ) ;
F_11 ( V_104 && V_8 >= V_73 ) ;
F_11 ( V_8 >= V_14 ) ;
F_66 ( L_4 , V_8 ) ;
V_71 = V_29 -> V_68 [ V_8 ] ;
if ( V_71 != V_69 &&
( F_51 ( V_29 -> V_66 [ V_71 ] ) == V_104 ) ) {
F_66 ( L_5 ,
V_71 , V_8 , V_29 -> V_66 [ V_71 ] ) ;
F_11 ( ! F_3 ( V_71 , V_29 -> V_65 ) ) ;
V_29 -> V_66 [ V_71 ] |= V_75 ;
return true ;
}
V_71 = F_72 ( ( unsigned long * ) V_29 -> V_65 ,
V_29 -> V_105 ) ;
if ( V_71 >= V_29 -> V_105 )
return false ;
F_66 ( L_6 , V_71 , V_8 , V_104 ) ;
V_29 -> V_66 [ V_71 ] = F_73 ( V_104 , V_8 ) ;
V_29 -> V_68 [ V_8 ] = V_71 ;
F_5 ( V_71 , V_29 -> V_65 ) ;
if ( ! F_12 ( V_16 , V_8 ) )
V_29 -> V_66 [ V_71 ] |= V_106 ;
return true ;
}
static bool F_74 ( struct V_15 * V_16 , int V_8 )
{
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
unsigned long V_107 ;
int V_24 = V_16 -> V_24 ;
int V_56 ;
V_107 = V_18 -> V_74 [ V_24 ] [ V_8 ] ;
F_49 (c, &sources, VGIC_MAX_CPUS) {
if ( F_71 ( V_16 , V_56 , V_8 ) )
F_6 ( V_56 , & V_107 ) ;
}
V_18 -> V_74 [ V_24 ] [ V_8 ] = V_107 ;
if ( ! V_107 ) {
F_19 ( V_16 , V_8 ) ;
F_21 ( V_16 , V_8 ) ;
return true ;
}
return false ;
}
static bool F_75 ( struct V_15 * V_16 , int V_8 )
{
if ( F_14 ( V_16 , V_8 ) )
return true ;
if ( F_71 ( V_16 , 0 , V_8 ) ) {
if ( F_12 ( V_16 , V_8 ) ) {
F_19 ( V_16 , V_8 ) ;
F_21 ( V_16 , V_8 ) ;
} else {
F_15 ( V_16 , V_8 ) ;
}
return true ;
}
return false ;
}
static void F_76 ( struct V_15 * V_16 )
{
struct V_29 * V_29 = & V_16 -> V_20 . V_29 ;
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
int V_53 , V_24 ;
int V_108 = 0 ;
V_24 = V_16 -> V_24 ;
if ( ! F_77 ( V_16 ) ) {
F_70 ( L_7 , V_24 ) ;
goto V_109;
}
F_49 (i, vgic_cpu->pending_percpu, VGIC_NR_SGIS) {
if ( ! F_74 ( V_16 , V_53 ) )
V_108 = 1 ;
}
F_78 (i, vgic_cpu->pending_percpu, VGIC_NR_PRIVATE_IRQS) {
if ( ! F_75 ( V_16 , V_53 ) )
V_108 = 1 ;
}
F_49 (i, vgic_cpu->pending_shared, VGIC_NR_SHARED_IRQS) {
if ( ! F_75 ( V_16 , V_53 + V_9 ) )
V_108 = 1 ;
}
V_109:
if ( V_108 ) {
V_29 -> V_110 |= V_111 ;
} else {
V_29 -> V_110 &= ~ V_111 ;
F_6 ( V_24 , & V_18 -> V_102 ) ;
}
}
static bool F_79 ( struct V_15 * V_16 )
{
struct V_29 * V_29 = & V_16 -> V_20 . V_29 ;
bool V_112 = false ;
F_66 ( L_8 , V_29 -> V_113 ) ;
if ( V_29 -> V_113 & V_114 ) {
int V_71 , V_8 ;
F_49 (lr, (unsigned long *)vgic_cpu->vgic_eisr,
vgic_cpu->nr_lr) {
V_8 = V_29 -> V_66 [ V_71 ] & V_103 ;
F_16 ( V_16 , V_8 ) ;
V_29 -> V_66 [ V_71 ] &= ~ V_106 ;
if ( F_17 ( V_16 , V_8 ) ) {
F_20 ( V_16 , V_8 ) ;
V_112 = true ;
} else {
F_21 ( V_16 , V_8 ) ;
}
F_5 ( V_71 , ( unsigned long * ) V_29 -> V_115 ) ;
V_29 -> V_66 [ V_71 ] &= ~ V_72 ;
}
}
if ( V_29 -> V_113 & V_116 )
V_29 -> V_110 &= ~ V_111 ;
return V_112 ;
}
static void F_80 ( struct V_15 * V_16 )
{
struct V_29 * V_29 = & V_16 -> V_20 . V_29 ;
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
int V_71 , V_97 ;
bool V_112 ;
V_112 = F_79 ( V_16 ) ;
F_49 (lr, (unsigned long *)vgic_cpu->vgic_elrsr,
vgic_cpu->nr_lr) {
int V_8 ;
if ( ! F_81 ( V_71 , V_29 -> V_65 ) )
continue;
V_8 = V_29 -> V_66 [ V_71 ] & V_103 ;
F_11 ( V_8 >= V_14 ) ;
V_29 -> V_68 [ V_8 ] = V_69 ;
}
V_97 = F_72 ( ( unsigned long * ) V_29 -> V_115 ,
V_29 -> V_105 ) ;
if ( V_112 || V_97 < V_29 -> V_105 )
F_5 ( V_16 -> V_24 , & V_18 -> V_102 ) ;
}
void F_82 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
if ( ! F_58 ( V_16 -> V_19 ) )
return;
F_61 ( & V_18 -> V_94 ) ;
F_76 ( V_16 ) ;
F_62 ( & V_18 -> V_94 ) ;
}
void F_83 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
if ( ! F_58 ( V_16 -> V_19 ) )
return;
F_61 ( & V_18 -> V_94 ) ;
F_80 ( V_16 ) ;
F_62 ( & V_18 -> V_94 ) ;
}
int F_77 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
if ( ! F_58 ( V_16 -> V_19 ) )
return 0 ;
return F_3 ( V_16 -> V_24 , & V_18 -> V_102 ) ;
}
static void F_65 ( struct V_19 * V_19 )
{
struct V_15 * V_16 ;
int V_56 ;
F_40 (c, vcpu, kvm) {
if ( F_77 ( V_16 ) )
F_84 ( V_16 ) ;
}
}
static int F_85 ( struct V_15 * V_16 , int V_8 , int V_117 )
{
int V_118 = F_12 ( V_16 , V_8 ) ;
int V_119 = F_17 ( V_16 , V_8 ) ;
if ( V_118 )
return V_117 > V_119 ;
else
return V_117 != V_119 ;
}
static bool F_86 ( struct V_19 * V_19 , int V_3 ,
unsigned int V_120 , bool V_117 )
{
struct V_17 * V_18 = & V_19 -> V_20 . V_21 ;
struct V_15 * V_16 ;
int V_118 , V_121 ;
int V_48 ;
bool V_122 = true ;
F_61 ( & V_18 -> V_94 ) ;
V_16 = F_87 ( V_19 , V_3 ) ;
V_118 = F_12 ( V_16 , V_120 ) ;
V_121 = ! V_118 ;
if ( ! F_85 ( V_16 , V_120 , V_117 ) ) {
V_122 = false ;
goto V_123;
}
if ( V_120 >= V_9 ) {
V_3 = V_18 -> V_55 [ V_120 - V_9 ] ;
V_16 = F_87 ( V_19 , V_3 ) ;
}
F_66 ( L_9 , V_120 , V_117 , V_3 ) ;
if ( V_117 )
F_18 ( V_16 , V_120 ) ;
else
F_19 ( V_16 , V_120 ) ;
V_48 = F_13 ( V_16 , V_120 ) ;
if ( ! V_48 ) {
V_122 = false ;
goto V_123;
}
if ( V_121 && F_14 ( V_16 , V_120 ) ) {
V_122 = false ;
goto V_123;
}
if ( V_117 ) {
F_20 ( V_16 , V_120 ) ;
F_5 ( V_3 , & V_18 -> V_102 ) ;
}
V_123:
F_62 ( & V_18 -> V_94 ) ;
return V_122 ;
}
int F_88 ( struct V_19 * V_19 , int V_3 , unsigned int V_120 ,
bool V_117 )
{
if ( F_86 ( V_19 , V_3 , V_120 , V_117 ) )
F_65 ( V_19 ) ;
return 0 ;
}
static T_5 F_89 ( int V_8 , void * V_35 )
{
return V_124 ;
}
int F_90 ( struct V_15 * V_16 )
{
struct V_29 * V_29 = & V_16 -> V_20 . V_29 ;
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
int V_53 ;
if ( V_16 -> V_24 >= V_12 )
return - V_125 ;
for ( V_53 = 0 ; V_53 < V_14 ; V_53 ++ ) {
if ( V_53 < V_126 )
F_4 ( & V_18 -> V_26 ,
V_16 -> V_24 , V_53 , 1 ) ;
if ( V_53 < V_9 )
F_4 ( & V_18 -> V_23 ,
V_16 -> V_24 , V_53 , V_25 ) ;
V_29 -> V_68 [ V_53 ] = V_69 ;
}
V_29 -> V_127 = 0 ;
V_29 -> V_105 = V_128 ;
V_29 -> V_110 = V_129 ;
return 0 ;
}
static void F_91 ( void * V_130 )
{
F_92 ( V_131 , 0 ) ;
}
static int F_93 ( struct V_132 * V_133 ,
unsigned long V_134 , void * V_135 )
{
switch ( V_134 ) {
case V_136 :
case V_137 :
F_91 ( NULL ) ;
break;
case V_138 :
case V_139 :
F_94 ( V_131 ) ;
break;
}
return V_140 ;
}
int F_95 ( void )
{
int V_122 ;
struct V_141 V_142 ;
struct V_141 V_143 ;
V_144 = F_96 ( NULL , NULL , L_10 ) ;
if ( ! V_144 ) {
F_97 ( L_11 ) ;
return - V_145 ;
}
V_131 = F_98 ( V_144 , 0 ) ;
if ( ! V_131 ) {
F_97 ( L_12 ) ;
V_122 = - V_146 ;
goto V_123;
}
V_122 = F_99 ( V_131 , F_89 ,
L_13 , F_100 () ) ;
if ( V_122 ) {
F_97 ( L_14 , V_131 ) ;
goto V_123;
}
V_122 = F_101 ( & V_147 ) ;
if ( V_122 ) {
F_97 ( L_15 ) ;
goto V_148;
}
V_122 = F_102 ( V_144 , 2 , & V_142 ) ;
if ( V_122 ) {
F_97 ( L_16 ) ;
goto V_148;
}
V_149 = F_103 ( V_144 , 2 ) ;
if ( ! V_149 ) {
F_97 ( L_17 ) ;
V_122 = - V_150 ;
goto V_148;
}
V_128 = F_104 ( V_149 + V_151 ) ;
V_128 = ( V_128 & 0x3f ) + 1 ;
V_122 = F_105 ( V_149 ,
V_149 + F_106 ( & V_142 ) ,
V_142 . V_152 ) ;
if ( V_122 ) {
F_97 ( L_18 ) ;
goto V_153;
}
F_107 ( L_19 , V_144 -> V_154 ,
V_142 . V_152 , V_131 ) ;
F_108 ( F_91 , NULL , 1 ) ;
if ( F_102 ( V_144 , 3 , & V_143 ) ) {
F_97 ( L_20 ) ;
V_122 = - V_146 ;
goto V_153;
}
V_155 = V_143 . V_152 ;
goto V_123;
V_153:
F_109 ( V_149 ) ;
V_148:
F_110 ( V_131 , F_100 () ) ;
V_123:
F_111 ( V_144 ) ;
return V_122 ;
}
int F_112 ( struct V_19 * V_19 )
{
int V_122 = 0 , V_53 ;
if ( ! F_58 ( V_19 ) )
return 0 ;
F_113 ( & V_19 -> V_94 ) ;
if ( F_114 ( V_19 ) )
goto V_123;
if ( F_115 ( V_19 -> V_20 . V_21 . V_88 ) ||
F_115 ( V_19 -> V_20 . V_21 . V_156 ) ) {
F_97 ( L_21 ) ;
V_122 = - V_146 ;
goto V_123;
}
V_122 = F_116 ( V_19 , V_19 -> V_20 . V_21 . V_156 ,
V_155 , V_157 ) ;
if ( V_122 ) {
F_97 ( L_22 ) ;
goto V_123;
}
for ( V_53 = V_9 ; V_53 < V_14 ; V_53 += 4 )
F_38 ( V_19 , 0 , V_53 ) ;
V_19 -> V_20 . V_21 . V_158 = true ;
V_123:
F_117 ( & V_19 -> V_94 ) ;
return V_122 ;
}
int F_118 ( struct V_19 * V_19 )
{
int V_53 , V_159 = - 1 , V_122 = 0 ;
struct V_15 * V_16 ;
F_113 ( & V_19 -> V_94 ) ;
if ( V_19 -> V_20 . V_21 . V_160 ) {
V_122 = - V_161 ;
goto V_123;
}
F_40 (i, vcpu, kvm) {
if ( ! F_119 ( & V_16 -> V_162 ) )
goto V_163;
V_159 = V_53 ;
}
F_40 (i, vcpu, kvm) {
if ( V_16 -> V_20 . V_164 ) {
V_122 = - V_125 ;
goto V_163;
}
}
F_120 ( & V_19 -> V_20 . V_21 . V_94 ) ;
V_19 -> V_20 . V_21 . V_160 = V_149 ;
V_19 -> V_20 . V_21 . V_88 = V_165 ;
V_19 -> V_20 . V_21 . V_156 = V_165 ;
V_163:
for (; V_159 >= 0 ; V_159 -- ) {
V_16 = F_87 ( V_19 , V_159 ) ;
F_117 ( & V_16 -> V_162 ) ;
}
V_123:
F_117 ( & V_19 -> V_94 ) ;
return V_122 ;
}
static bool F_121 ( struct V_19 * V_19 )
{
T_2 V_18 = V_19 -> V_20 . V_21 . V_88 ;
T_2 V_135 = V_19 -> V_20 . V_21 . V_156 ;
if ( F_115 ( V_18 ) || F_115 ( V_135 ) )
return 0 ;
if ( ( V_18 <= V_135 && V_18 + V_91 > V_135 ) ||
( V_135 <= V_18 && V_135 + V_157 > V_18 ) )
return - V_125 ;
return 0 ;
}
static int F_122 ( struct V_19 * V_19 , T_2 * V_166 ,
T_2 V_167 , T_2 V_168 )
{
int V_122 ;
if ( V_167 & ~ V_169 )
return - V_170 ;
if ( V_167 & ( V_171 - 1 ) )
return - V_172 ;
if ( ! F_115 ( * V_166 ) )
return - V_161 ;
if ( V_167 + V_168 < V_167 )
return - V_172 ;
V_122 = F_121 ( V_19 ) ;
if ( V_122 )
return V_122 ;
* V_166 = V_167 ;
return V_122 ;
}
int F_123 ( struct V_19 * V_19 , unsigned long type , T_6 * V_167 , bool V_173 )
{
int V_83 = 0 ;
struct V_17 * V_21 = & V_19 -> V_20 . V_21 ;
F_113 ( & V_19 -> V_94 ) ;
switch ( type ) {
case V_174 :
if ( V_173 ) {
V_83 = F_122 ( V_19 , & V_21 -> V_88 ,
* V_167 , V_91 ) ;
} else {
* V_167 = V_21 -> V_88 ;
}
break;
case V_175 :
if ( V_173 ) {
V_83 = F_122 ( V_19 , & V_21 -> V_156 ,
* V_167 , V_157 ) ;
} else {
* V_167 = V_21 -> V_156 ;
}
break;
default:
V_83 = - V_145 ;
}
F_117 ( & V_19 -> V_94 ) ;
return V_83 ;
}
static bool F_124 ( struct V_15 * V_16 ,
struct V_32 * V_33 , T_2 V_4 )
{
struct V_29 * V_29 = & V_16 -> V_20 . V_29 ;
T_1 V_6 , V_34 = 0 , V_59 = 0 ;
bool V_80 = false ;
switch ( V_4 & ~ 0x3 ) {
case V_176 :
V_34 = V_177 ;
V_59 = V_178 ;
break;
case V_179 :
V_34 = V_180 ;
V_59 = V_181 ;
break;
case V_182 :
V_34 = V_183 ;
V_59 = V_184 ;
break;
case V_185 :
V_34 = V_186 ;
V_59 = V_187 ;
break;
}
if ( ! V_33 -> V_43 ) {
V_6 = ( V_29 -> V_127 & V_34 ) >> V_59 ;
F_23 ( V_33 , ~ 0 , V_6 ) ;
} else {
V_6 = F_22 ( V_33 , ~ 0 ) ;
V_6 = ( V_6 << V_59 ) & V_34 ;
if ( V_6 != ( V_29 -> V_127 & V_34 ) )
V_80 = true ;
V_29 -> V_127 &= ~ V_34 ;
V_29 -> V_127 |= V_6 ;
}
return V_80 ;
}
static bool F_125 ( struct V_15 * V_16 ,
struct V_32 * V_33 , T_2 V_4 )
{
return F_124 ( V_16 , V_33 , V_185 ) ;
}
static bool F_126 ( struct V_15 * V_16 ,
struct V_32 * V_33 ,
T_2 V_4 )
{
T_1 V_6 ;
if ( V_33 -> V_43 )
return false ;
V_6 = ( V_50 << 20 ) |
( V_188 << 16 ) |
( V_51 << 0 ) ;
F_23 ( V_33 , ~ 0 , V_6 ) ;
return false ;
}
static int F_127 ( struct V_189 * V_190 ,
struct V_191 * V_192 ,
T_1 * V_6 , bool V_43 )
{
const struct V_81 * V_83 = NULL , * V_82 ;
T_2 V_4 ;
int V_122 , V_3 , V_56 ;
struct V_15 * V_16 , * V_193 ;
struct V_17 * V_21 ;
struct V_32 V_33 ;
V_4 = V_192 -> V_192 & V_194 ;
V_3 = ( V_192 -> V_192 & V_195 ) >>
V_196 ;
F_113 ( & V_190 -> V_19 -> V_94 ) ;
if ( V_3 >= F_29 ( & V_190 -> V_19 -> V_49 ) ) {
V_122 = - V_172 ;
goto V_123;
}
V_16 = F_87 ( V_190 -> V_19 , V_3 ) ;
V_21 = & V_190 -> V_19 -> V_20 . V_21 ;
V_33 . V_39 = 4 ;
V_33 . V_43 = V_43 ;
if ( V_43 )
F_23 ( & V_33 , ~ 0 , * V_6 ) ;
switch ( V_192 -> V_197 ) {
case V_198 :
V_33 . V_90 = V_21 -> V_88 + V_4 ;
V_82 = V_92 ;
break;
case V_199 :
V_33 . V_90 = V_21 -> V_156 + V_4 ;
V_82 = V_200 ;
break;
default:
F_128 () ;
}
V_83 = F_56 ( V_82 , & V_33 , V_4 ) ;
if ( F_8 ( ! V_83 || ! V_83 -> V_93 ) ) {
V_122 = - V_146 ;
goto V_123;
}
F_61 ( & V_21 -> V_94 ) ;
F_40 (c, tmp_vcpu, dev->kvm) {
if ( F_8 ( V_193 -> V_135 != - 1 ) ) {
V_122 = - V_125 ;
goto V_201;
}
}
F_40 (c, tmp_vcpu, dev->kvm)
F_48 ( V_193 ) ;
V_4 -= V_83 -> V_84 ;
V_83 -> V_93 ( V_16 , & V_33 , V_4 ) ;
if ( ! V_43 )
* V_6 = F_22 ( & V_33 , ~ 0 ) ;
V_122 = 0 ;
V_201:
F_62 ( & V_21 -> V_94 ) ;
V_123:
F_117 ( & V_190 -> V_19 -> V_94 ) ;
return V_122 ;
}
static int F_129 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
int V_83 ;
switch ( V_192 -> V_197 ) {
case V_202 : {
T_6 T_7 * V_203 = ( T_6 T_7 * ) ( long ) V_192 -> V_167 ;
T_6 V_167 ;
unsigned long type = ( unsigned long ) V_192 -> V_192 ;
if ( F_130 ( & V_167 , V_203 , sizeof( V_167 ) ) )
return - V_204 ;
V_83 = F_123 ( V_190 -> V_19 , type , & V_167 , true ) ;
return ( V_83 == - V_145 ) ? - V_146 : V_83 ;
}
case V_198 :
case V_199 : {
T_1 T_7 * V_203 = ( T_1 T_7 * ) ( long ) V_192 -> V_167 ;
T_1 V_6 ;
if ( F_131 ( V_6 , V_203 ) )
return - V_204 ;
return F_127 ( V_190 , V_192 , & V_6 , true ) ;
}
}
return - V_146 ;
}
static int F_132 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
int V_83 = - V_146 ;
switch ( V_192 -> V_197 ) {
case V_202 : {
T_6 T_7 * V_203 = ( T_6 T_7 * ) ( long ) V_192 -> V_167 ;
T_6 V_167 ;
unsigned long type = ( unsigned long ) V_192 -> V_192 ;
V_83 = F_123 ( V_190 -> V_19 , type , & V_167 , false ) ;
if ( V_83 )
return ( V_83 == - V_145 ) ? - V_146 : V_83 ;
if ( F_133 ( V_203 , & V_167 , sizeof( V_167 ) ) )
return - V_204 ;
break;
}
case V_198 :
case V_199 : {
T_1 T_7 * V_203 = ( T_1 T_7 * ) ( long ) V_192 -> V_167 ;
T_1 V_6 = 0 ;
V_83 = F_127 ( V_190 , V_192 , & V_6 , false ) ;
if ( V_83 )
return V_83 ;
V_83 = F_134 ( V_6 , V_203 ) ;
break;
}
}
return V_83 ;
}
static int F_135 ( const struct V_81 * V_82 ,
T_2 V_4 )
{
struct V_32 V_205 ;
V_205 . V_39 = 4 ;
if ( F_56 ( V_82 , & V_205 , V_4 ) )
return 0 ;
else
return - V_146 ;
}
static int F_136 ( struct V_189 * V_190 , struct V_191 * V_192 )
{
T_2 V_4 ;
switch ( V_192 -> V_197 ) {
case V_202 :
switch ( V_192 -> V_192 ) {
case V_174 :
case V_175 :
return 0 ;
}
break;
case V_198 :
V_4 = V_192 -> V_192 & V_194 ;
return F_135 ( V_92 , V_4 ) ;
case V_199 :
V_4 = V_192 -> V_192 & V_194 ;
return F_135 ( V_200 , V_4 ) ;
}
return - V_146 ;
}
static void F_137 ( struct V_189 * V_190 )
{
F_138 ( V_190 ) ;
}
static int F_139 ( struct V_189 * V_190 , T_1 type )
{
return F_118 ( V_190 -> V_19 ) ;
}

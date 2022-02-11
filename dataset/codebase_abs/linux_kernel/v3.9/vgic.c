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
if ( V_4 < 4 )
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
V_6 = 0x4B00043B ;
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
T_1 * V_6 = F_10 ( & V_16 -> V_19 -> V_20 . V_21 . V_50 ,
V_16 -> V_24 , V_4 ) ;
F_24 ( V_33 , V_6 , V_4 ,
V_47 | V_46 ) ;
return false ;
}
static T_1 F_37 ( struct V_19 * V_19 , int V_8 )
{
struct V_17 * V_18 = & V_19 -> V_20 . V_21 ;
struct V_15 * V_16 ;
int V_51 , V_52 ;
unsigned long * V_53 ;
T_1 V_11 = 0 ;
V_8 -= V_9 ;
F_38 (c, vcpu, kvm) {
V_53 = F_9 ( & V_18 -> V_54 [ V_52 ] ) ;
for ( V_51 = 0 ; V_51 < V_55 ; V_51 ++ )
if ( F_3 ( V_8 + V_51 , V_53 ) )
V_11 |= 1 << ( V_52 + V_51 * 8 ) ;
}
return V_11 ;
}
static void F_39 ( struct V_19 * V_19 , T_1 V_11 , int V_8 )
{
struct V_17 * V_18 = & V_19 -> V_20 . V_21 ;
struct V_15 * V_16 ;
int V_51 , V_52 ;
unsigned long * V_53 ;
T_1 V_56 ;
V_8 -= V_9 ;
for ( V_51 = 0 ; V_51 < V_55 ; V_51 ++ ) {
int V_57 = V_51 * V_58 ;
V_56 = F_40 ( ( V_11 >> V_57 ) & 0xffU ) ;
V_56 = V_56 ? ( V_56 - 1 ) : 0 ;
V_18 -> V_59 [ V_8 + V_51 ] = V_56 ;
F_38 (c, vcpu, kvm) {
V_53 = F_9 ( & V_18 -> V_54 [ V_52 ] ) ;
if ( V_52 == V_56 )
F_5 ( V_8 + V_51 , V_53 ) ;
else
F_6 ( V_8 + V_51 , V_53 ) ;
}
}
}
static bool F_41 ( struct V_15 * V_16 ,
struct V_32 * V_33 ,
T_2 V_4 )
{
T_1 V_6 ;
if ( V_4 < 32 ) {
T_1 V_60 = 1 << V_16 -> V_24 ;
V_60 |= V_60 << 8 ;
V_60 |= V_60 << 16 ;
F_24 ( V_33 , & V_60 , V_4 ,
V_47 | V_42 ) ;
return false ;
}
V_6 = F_37 ( V_16 -> V_19 , V_4 & ~ 3U ) ;
F_24 ( V_33 , & V_6 , V_4 ,
V_47 | V_46 ) ;
if ( V_33 -> V_43 ) {
F_39 ( V_16 -> V_19 , V_6 , V_4 & ~ 3U ) ;
F_28 ( V_16 -> V_19 ) ;
return true ;
}
return false ;
}
static T_1 F_42 ( T_3 V_11 )
{
T_1 V_61 = 0 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < 16 ; V_51 ++ )
V_61 |= ( ( V_11 >> V_51 ) & V_25 ) << ( 2 * V_51 + 1 ) ;
return V_61 ;
}
static T_3 F_43 ( T_1 V_11 )
{
T_3 V_61 = 0 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < 16 ; V_51 ++ )
V_61 |= ( ( V_11 >> ( V_51 * 2 + 1 ) ) & V_25 ) << V_51 ;
return V_61 ;
}
static bool F_44 ( struct V_15 * V_16 ,
struct V_32 * V_33 , T_2 V_4 )
{
T_1 V_11 ;
T_1 * V_6 = F_1 ( & V_16 -> V_19 -> V_20 . V_21 . V_23 ,
V_16 -> V_24 , V_4 >> 1 ) ;
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
static const
struct V_62 * F_47 ( const struct V_62 * V_63 ,
struct V_32 * V_33 ,
T_2 V_64 )
{
const struct V_62 * V_65 = V_63 ;
T_2 V_66 = V_33 -> V_67 - V_64 ;
while ( V_65 -> V_39 ) {
if ( V_66 >= V_65 -> V_64 &&
( V_66 + V_33 -> V_39 ) <= ( V_65 -> V_64 + V_65 -> V_39 ) )
return V_65 ;
V_65 ++ ;
}
return NULL ;
}
bool F_48 ( struct V_15 * V_16 , struct V_68 * V_69 ,
struct V_32 * V_33 )
{
const struct V_62 * V_70 ;
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
unsigned long V_64 = V_18 -> V_71 ;
bool V_72 ;
unsigned long V_4 ;
if ( ! F_49 ( V_16 -> V_19 ) ||
V_33 -> V_67 < V_64 ||
( V_33 -> V_67 + V_33 -> V_39 ) > ( V_64 + V_73 ) )
return false ;
if ( V_33 -> V_39 > 4 ) {
F_50 ( V_16 , V_33 -> V_67 ) ;
return true ;
}
V_70 = F_47 ( V_74 , V_33 , V_64 ) ;
if ( F_8 ( ! V_70 || ! V_70 -> V_75 ) ) {
F_51 ( L_1 ,
V_33 -> V_43 , V_33 -> V_67 , V_33 -> V_39 ) ;
return false ;
}
F_52 ( & V_16 -> V_19 -> V_20 . V_21 . V_76 ) ;
V_4 = V_33 -> V_67 - V_70 -> V_64 - V_64 ;
V_72 = V_70 -> V_75 ( V_16 , V_33 , V_4 ) ;
F_53 ( & V_16 -> V_19 -> V_20 . V_21 . V_76 ) ;
F_54 ( V_69 , V_33 ) ;
F_55 ( V_16 , V_69 ) ;
if ( V_72 )
F_56 ( V_16 -> V_19 ) ;
return true ;
}
static void F_46 ( struct V_15 * V_16 , T_1 V_6 )
{
struct V_19 * V_19 = V_16 -> V_19 ;
struct V_17 * V_18 = & V_19 -> V_20 . V_21 ;
int V_77 = F_29 ( & V_19 -> V_49 ) ;
T_4 V_78 ;
int V_79 , V_37 , V_52 , V_24 ;
V_24 = V_16 -> V_24 ;
V_79 = V_6 & 0xf ;
V_78 = ( V_6 >> 16 ) & 0xff ;
V_37 = ( V_6 >> 24 ) & 3 ;
switch ( V_37 ) {
case 0 :
if ( ! V_78 )
return;
case 1 :
V_78 = ( ( 1 << V_77 ) - 1 ) & ~ ( 1 << V_24 ) & 0xff ;
break;
case 2 :
V_78 = 1 << V_24 ;
break;
}
F_38 (c, vcpu, kvm) {
if ( V_78 & 1 ) {
F_18 ( V_16 , V_79 ) ;
V_18 -> V_80 [ V_52 ] [ V_79 ] |= 1 << V_24 ;
F_57 ( L_2 , V_79 , V_24 , V_52 ) ;
}
V_78 >>= 1 ;
}
}
static int F_58 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
unsigned long * V_81 , * V_48 , * V_82 , * V_83 ;
unsigned long V_84 , V_31 ;
int V_24 ;
V_24 = V_16 -> V_24 ;
V_82 = V_16 -> V_20 . V_29 . V_30 ;
V_83 = V_16 -> V_20 . V_29 . V_31 ;
V_81 = F_7 ( & V_18 -> V_28 , V_24 ) ;
V_48 = F_7 ( & V_18 -> V_26 , V_24 ) ;
F_59 ( V_82 , V_81 , V_48 , V_9 ) ;
V_81 = F_9 ( & V_18 -> V_28 ) ;
V_48 = F_9 ( & V_18 -> V_26 ) ;
F_59 ( V_83 , V_81 , V_48 , V_85 ) ;
F_59 ( V_83 , V_83 ,
F_9 ( & V_18 -> V_54 [ V_24 ] ) ,
V_85 ) ;
V_84 = F_60 ( V_82 , V_9 ) ;
V_31 = F_60 ( V_83 , V_85 ) ;
return ( V_84 < V_9 ||
V_31 < V_85 ) ;
}
static void F_28 ( struct V_19 * V_19 )
{
struct V_17 * V_18 = & V_19 -> V_20 . V_21 ;
struct V_15 * V_16 ;
int V_52 ;
if ( ! V_18 -> V_48 ) {
F_5 ( 0 , & V_18 -> V_86 ) ;
return;
}
F_38 (c, vcpu, kvm) {
if ( F_58 ( V_16 ) ) {
F_61 ( L_3 , V_52 ) ;
F_5 ( V_52 , & V_18 -> V_86 ) ;
}
}
}
static void F_33 ( struct V_15 * V_16 )
{
struct V_29 * V_29 = & V_16 -> V_20 . V_29 ;
int V_87 ;
F_62 (lr, vgic_cpu->lr_used, vgic_cpu->nr_lr) {
int V_8 = V_29 -> V_88 [ V_87 ] & V_89 ;
if ( ! F_13 ( V_16 , V_8 ) ) {
V_29 -> V_90 [ V_8 ] = V_91 ;
F_6 ( V_87 , V_29 -> V_92 ) ;
V_29 -> V_88 [ V_87 ] &= ~ V_93 ;
if ( F_14 ( V_16 , V_8 ) )
F_16 ( V_16 , V_8 ) ;
}
}
}
static bool F_63 ( struct V_15 * V_16 , T_4 V_94 , int V_8 )
{
struct V_29 * V_29 = & V_16 -> V_20 . V_29 ;
int V_87 ;
F_11 ( V_94 & ~ 7 ) ;
F_11 ( V_94 && V_8 >= V_95 ) ;
F_11 ( V_8 >= V_14 ) ;
F_57 ( L_4 , V_8 ) ;
V_87 = V_29 -> V_90 [ V_8 ] ;
if ( V_87 != V_91 &&
( F_64 ( V_29 -> V_88 [ V_87 ] ) == V_94 ) ) {
F_57 ( L_5 ,
V_87 , V_8 , V_29 -> V_88 [ V_87 ] ) ;
F_11 ( ! F_3 ( V_87 , V_29 -> V_92 ) ) ;
V_29 -> V_88 [ V_87 ] |= V_96 ;
return true ;
}
V_87 = F_65 ( ( unsigned long * ) V_29 -> V_92 ,
V_29 -> V_97 ) ;
if ( V_87 >= V_29 -> V_97 )
return false ;
F_57 ( L_6 , V_87 , V_8 , V_94 ) ;
V_29 -> V_88 [ V_87 ] = F_66 ( V_94 , V_8 ) ;
V_29 -> V_90 [ V_8 ] = V_87 ;
F_5 ( V_87 , V_29 -> V_92 ) ;
if ( ! F_12 ( V_16 , V_8 ) )
V_29 -> V_88 [ V_87 ] |= V_98 ;
return true ;
}
static bool F_67 ( struct V_15 * V_16 , int V_8 )
{
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
unsigned long V_99 ;
int V_24 = V_16 -> V_24 ;
int V_52 ;
V_99 = V_18 -> V_80 [ V_24 ] [ V_8 ] ;
F_62 (c, &sources, VGIC_MAX_CPUS) {
if ( F_63 ( V_16 , V_52 , V_8 ) )
F_6 ( V_52 , & V_99 ) ;
}
V_18 -> V_80 [ V_24 ] [ V_8 ] = V_99 ;
if ( ! V_99 ) {
F_19 ( V_16 , V_8 ) ;
F_21 ( V_16 , V_8 ) ;
return true ;
}
return false ;
}
static bool F_68 ( struct V_15 * V_16 , int V_8 )
{
if ( F_14 ( V_16 , V_8 ) )
return true ;
if ( F_63 ( V_16 , 0 , V_8 ) ) {
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
static void F_69 ( struct V_15 * V_16 )
{
struct V_29 * V_29 = & V_16 -> V_20 . V_29 ;
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
int V_51 , V_24 ;
int V_100 = 0 ;
V_24 = V_16 -> V_24 ;
if ( ! F_70 ( V_16 ) ) {
F_61 ( L_7 , V_24 ) ;
goto V_101;
}
F_62 (i, vgic_cpu->pending_percpu, VGIC_NR_SGIS) {
if ( ! F_67 ( V_16 , V_51 ) )
V_100 = 1 ;
}
F_71 (i, vgic_cpu->pending_percpu, VGIC_NR_PRIVATE_IRQS) {
if ( ! F_68 ( V_16 , V_51 ) )
V_100 = 1 ;
}
F_62 (i, vgic_cpu->pending_shared, VGIC_NR_SHARED_IRQS) {
if ( ! F_68 ( V_16 , V_51 + V_9 ) )
V_100 = 1 ;
}
V_101:
if ( V_100 ) {
V_29 -> V_102 |= V_103 ;
} else {
V_29 -> V_102 &= ~ V_103 ;
F_6 ( V_24 , & V_18 -> V_86 ) ;
}
}
static bool F_72 ( struct V_15 * V_16 )
{
struct V_29 * V_29 = & V_16 -> V_20 . V_29 ;
bool V_104 = false ;
F_57 ( L_8 , V_29 -> V_105 ) ;
if ( V_29 -> V_105 & V_106 ) {
int V_87 , V_8 ;
F_62 (lr, (unsigned long *)vgic_cpu->vgic_eisr,
vgic_cpu->nr_lr) {
V_8 = V_29 -> V_88 [ V_87 ] & V_89 ;
F_16 ( V_16 , V_8 ) ;
V_29 -> V_88 [ V_87 ] &= ~ V_98 ;
if ( F_17 ( V_16 , V_8 ) ) {
F_20 ( V_16 , V_8 ) ;
V_104 = true ;
} else {
F_21 ( V_16 , V_8 ) ;
}
F_5 ( V_87 , ( unsigned long * ) V_29 -> V_107 ) ;
V_29 -> V_88 [ V_87 ] &= ~ V_108 ;
}
}
if ( V_29 -> V_105 & V_109 )
V_29 -> V_102 &= ~ V_103 ;
return V_104 ;
}
static void F_73 ( struct V_15 * V_16 )
{
struct V_29 * V_29 = & V_16 -> V_20 . V_29 ;
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
int V_87 , V_81 ;
bool V_104 ;
V_104 = F_72 ( V_16 ) ;
F_62 (lr, (unsigned long *)vgic_cpu->vgic_elrsr,
vgic_cpu->nr_lr) {
int V_8 ;
if ( ! F_74 ( V_87 , V_29 -> V_92 ) )
continue;
V_8 = V_29 -> V_88 [ V_87 ] & V_89 ;
F_11 ( V_8 >= V_14 ) ;
V_29 -> V_90 [ V_8 ] = V_91 ;
}
V_81 = F_65 ( ( unsigned long * ) V_29 -> V_107 ,
V_29 -> V_97 ) ;
if ( V_104 || V_81 < V_29 -> V_97 )
F_5 ( V_16 -> V_24 , & V_18 -> V_86 ) ;
}
void F_75 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
if ( ! F_49 ( V_16 -> V_19 ) )
return;
F_52 ( & V_18 -> V_76 ) ;
F_69 ( V_16 ) ;
F_53 ( & V_18 -> V_76 ) ;
}
void F_76 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
if ( ! F_49 ( V_16 -> V_19 ) )
return;
F_52 ( & V_18 -> V_76 ) ;
F_73 ( V_16 ) ;
F_53 ( & V_18 -> V_76 ) ;
}
int F_70 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
if ( ! F_49 ( V_16 -> V_19 ) )
return 0 ;
return F_3 ( V_16 -> V_24 , & V_18 -> V_86 ) ;
}
static void F_56 ( struct V_19 * V_19 )
{
struct V_15 * V_16 ;
int V_52 ;
F_38 (c, vcpu, kvm) {
if ( F_70 ( V_16 ) )
F_77 ( V_16 ) ;
}
}
static int F_78 ( struct V_15 * V_16 , int V_8 , int V_110 )
{
int V_111 = F_12 ( V_16 , V_8 ) ;
int V_112 = F_17 ( V_16 , V_8 ) ;
if ( V_111 )
return V_110 > V_112 ;
else
return V_110 != V_112 ;
}
static bool F_79 ( struct V_19 * V_19 , int V_3 ,
unsigned int V_113 , bool V_110 )
{
struct V_17 * V_18 = & V_19 -> V_20 . V_21 ;
struct V_15 * V_16 ;
int V_111 , V_114 ;
int V_48 ;
bool V_115 = true ;
F_52 ( & V_18 -> V_76 ) ;
V_16 = F_80 ( V_19 , V_3 ) ;
V_111 = F_12 ( V_16 , V_113 ) ;
V_114 = ! V_111 ;
if ( ! F_78 ( V_16 , V_113 , V_110 ) ) {
V_115 = false ;
goto V_116;
}
if ( V_113 >= V_9 ) {
V_3 = V_18 -> V_59 [ V_113 - V_9 ] ;
V_16 = F_80 ( V_19 , V_3 ) ;
}
F_57 ( L_9 , V_113 , V_110 , V_3 ) ;
if ( V_110 )
F_18 ( V_16 , V_113 ) ;
else
F_19 ( V_16 , V_113 ) ;
V_48 = F_13 ( V_16 , V_113 ) ;
if ( ! V_48 ) {
V_115 = false ;
goto V_116;
}
if ( V_114 && F_14 ( V_16 , V_113 ) ) {
V_115 = false ;
goto V_116;
}
if ( V_110 ) {
F_20 ( V_16 , V_113 ) ;
F_5 ( V_3 , & V_18 -> V_86 ) ;
}
V_116:
F_53 ( & V_18 -> V_76 ) ;
return V_115 ;
}
int F_81 ( struct V_19 * V_19 , int V_3 , unsigned int V_113 ,
bool V_110 )
{
if ( F_79 ( V_19 , V_3 , V_113 , V_110 ) )
F_56 ( V_19 ) ;
return 0 ;
}
static T_5 F_82 ( int V_8 , void * V_35 )
{
return V_117 ;
}
int F_83 ( struct V_15 * V_16 )
{
struct V_29 * V_29 = & V_16 -> V_20 . V_29 ;
struct V_17 * V_18 = & V_16 -> V_19 -> V_20 . V_21 ;
int V_51 ;
if ( ! F_49 ( V_16 -> V_19 ) )
return 0 ;
if ( V_16 -> V_24 >= V_12 )
return - V_118 ;
for ( V_51 = 0 ; V_51 < V_14 ; V_51 ++ ) {
if ( V_51 < V_119 )
F_4 ( & V_18 -> V_26 ,
V_16 -> V_24 , V_51 , 1 ) ;
if ( V_51 < V_9 )
F_4 ( & V_18 -> V_23 ,
V_16 -> V_24 , V_51 , V_25 ) ;
V_29 -> V_90 [ V_51 ] = V_91 ;
}
V_29 -> V_120 = 0 ;
V_29 -> V_97 = V_121 ;
V_29 -> V_102 = V_122 ;
return 0 ;
}
static void F_84 ( void * V_123 )
{
F_85 ( V_124 , 0 ) ;
}
static int F_86 ( struct V_125 * V_126 ,
unsigned long V_127 , void * V_128 )
{
switch ( V_127 ) {
case V_129 :
case V_130 :
F_84 ( NULL ) ;
break;
case V_131 :
case V_132 :
F_87 ( V_124 ) ;
break;
}
return V_133 ;
}
int F_88 ( void )
{
int V_115 ;
struct V_134 V_135 ;
struct V_134 V_136 ;
V_137 = F_89 ( NULL , NULL , L_10 ) ;
if ( ! V_137 ) {
F_90 ( L_11 ) ;
return - V_138 ;
}
V_124 = F_91 ( V_137 , 0 ) ;
if ( ! V_124 ) {
F_90 ( L_12 ) ;
V_115 = - V_139 ;
goto V_116;
}
V_115 = F_92 ( V_124 , F_82 ,
L_13 , F_93 () ) ;
if ( V_115 ) {
F_90 ( L_14 , V_124 ) ;
goto V_116;
}
V_115 = F_94 ( & V_140 ) ;
if ( V_115 ) {
F_90 ( L_15 ) ;
goto V_141;
}
V_115 = F_95 ( V_137 , 2 , & V_135 ) ;
if ( V_115 ) {
F_90 ( L_16 ) ;
goto V_141;
}
V_142 = F_96 ( V_137 , 2 ) ;
if ( ! V_142 ) {
F_90 ( L_17 ) ;
V_115 = - V_143 ;
goto V_141;
}
V_121 = F_97 ( V_142 + V_144 ) ;
V_121 = ( V_121 & 0x3f ) + 1 ;
V_115 = F_98 ( V_142 ,
V_142 + F_99 ( & V_135 ) ,
V_135 . V_145 ) ;
if ( V_115 ) {
F_90 ( L_18 ) ;
goto V_146;
}
F_100 ( L_19 , V_137 -> V_147 ,
V_135 . V_145 , V_124 ) ;
F_101 ( F_84 , NULL , 1 ) ;
if ( F_95 ( V_137 , 3 , & V_136 ) ) {
F_90 ( L_20 ) ;
V_115 = - V_139 ;
goto V_146;
}
V_148 = V_136 . V_145 ;
goto V_116;
V_146:
F_102 ( V_142 ) ;
V_141:
F_103 ( V_124 , F_93 () ) ;
V_116:
F_104 ( V_137 ) ;
return V_115 ;
}
int F_105 ( struct V_19 * V_19 )
{
int V_115 = 0 , V_51 ;
F_106 ( & V_19 -> V_76 ) ;
if ( F_107 ( V_19 ) )
goto V_116;
if ( F_108 ( V_19 -> V_20 . V_21 . V_71 ) ||
F_108 ( V_19 -> V_20 . V_21 . V_149 ) ) {
F_90 ( L_21 ) ;
V_115 = - V_139 ;
goto V_116;
}
V_115 = F_109 ( V_19 , V_19 -> V_20 . V_21 . V_149 ,
V_148 , V_150 ) ;
if ( V_115 ) {
F_90 ( L_22 ) ;
goto V_116;
}
for ( V_51 = V_9 ; V_51 < V_14 ; V_51 += 4 )
F_39 ( V_19 , 0 , V_51 ) ;
F_110 ( V_19 ) ;
V_19 -> V_20 . V_21 . V_151 = true ;
V_116:
F_111 ( & V_19 -> V_76 ) ;
return V_115 ;
}
int F_112 ( struct V_19 * V_19 )
{
int V_115 = 0 ;
F_106 ( & V_19 -> V_76 ) ;
if ( F_29 ( & V_19 -> V_49 ) || V_19 -> V_20 . V_21 . V_152 ) {
V_115 = - V_153 ;
goto V_116;
}
F_113 ( & V_19 -> V_20 . V_21 . V_76 ) ;
V_19 -> V_20 . V_21 . V_152 = V_142 ;
V_19 -> V_20 . V_21 . V_71 = V_154 ;
V_19 -> V_20 . V_21 . V_149 = V_154 ;
V_116:
F_111 ( & V_19 -> V_76 ) ;
return V_115 ;
}
static bool F_114 ( struct V_19 * V_19 )
{
T_2 V_18 = V_19 -> V_20 . V_21 . V_71 ;
T_2 V_128 = V_19 -> V_20 . V_21 . V_149 ;
if ( F_108 ( V_18 ) || F_108 ( V_128 ) )
return 0 ;
if ( ( V_18 <= V_128 && V_18 + V_73 > V_128 ) ||
( V_128 <= V_18 && V_128 + V_150 > V_18 ) )
return - V_118 ;
return 0 ;
}
static int F_115 ( struct V_19 * V_19 , T_2 * V_155 ,
T_2 V_66 , T_2 V_156 )
{
int V_115 ;
if ( ! F_108 ( * V_155 ) )
return - V_153 ;
if ( V_66 + V_156 < V_66 )
return - V_157 ;
V_115 = F_114 ( V_19 ) ;
if ( V_115 )
return V_115 ;
* V_155 = V_66 ;
return V_115 ;
}
int F_116 ( struct V_19 * V_19 , unsigned long type , T_6 V_66 )
{
int V_65 = 0 ;
struct V_17 * V_21 = & V_19 -> V_20 . V_21 ;
if ( V_66 & ~ V_158 )
return - V_159 ;
if ( V_66 & ~ V_160 )
return - V_157 ;
F_106 ( & V_19 -> V_76 ) ;
switch ( type ) {
case V_161 :
V_65 = F_115 ( V_19 , & V_21 -> V_71 ,
V_66 , V_73 ) ;
break;
case V_162 :
V_65 = F_115 ( V_19 , & V_21 -> V_149 ,
V_66 , V_150 ) ;
break;
default:
V_65 = - V_138 ;
}
F_111 ( & V_19 -> V_76 ) ;
return V_65 ;
}

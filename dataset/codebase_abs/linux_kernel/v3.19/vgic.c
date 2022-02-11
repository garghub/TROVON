static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 ;
V_5 = V_3 + F_2 ( V_4 - V_6 ) ;
V_2 -> V_7 = F_3 ( sizeof( unsigned long ) * V_5 , V_8 ) ;
if ( ! V_2 -> V_7 )
return - V_9 ;
V_2 -> V_10 = V_2 -> V_7 + V_3 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
V_2 -> V_10 = NULL ;
}
static unsigned long * F_6 ( T_1 * V_11 )
{
#if F_7 ( V_12 ) && V_13 == 32
* V_11 = ( * V_11 >> 32 ) | ( * V_11 << 32 ) ;
#endif
return ( unsigned long * ) V_11 ;
}
static T_2 * F_8 ( struct V_1 * V_14 ,
int V_15 , T_2 V_16 )
{
V_16 >>= 2 ;
if ( ! V_16 )
return ( T_2 * ) ( V_14 -> V_7 + V_15 ) + V_17 ;
else
return ( T_2 * ) ( V_14 -> V_10 ) + ( ( V_16 - 1 ) ^ V_17 ) ;
}
static int F_9 ( struct V_1 * V_14 ,
int V_15 , int V_18 )
{
if ( V_18 < V_6 )
return F_10 ( V_18 , V_14 -> V_7 + V_15 ) ;
return F_10 ( V_18 - V_6 , V_14 -> V_10 ) ;
}
static void F_11 ( struct V_1 * V_14 , int V_15 ,
int V_18 , int V_11 )
{
unsigned long * V_19 ;
if ( V_18 < V_6 ) {
V_19 = V_14 -> V_7 + V_15 ;
} else {
V_19 = V_14 -> V_10 ;
V_18 -= V_6 ;
}
if ( V_11 )
F_12 ( V_18 , V_19 ) ;
else
F_13 ( V_18 , V_19 ) ;
}
static unsigned long * F_14 ( struct V_1 * V_14 , int V_15 )
{
return V_14 -> V_7 + V_15 ;
}
static unsigned long * F_15 ( struct V_1 * V_14 )
{
return V_14 -> V_10 ;
}
static int F_16 ( struct V_20 * V_14 , int V_3 , int V_4 )
{
int V_21 ;
V_21 = V_3 * V_6 ;
V_21 += V_4 - V_6 ;
V_14 -> V_7 = F_3 ( V_21 , V_8 ) ;
if ( ! V_14 -> V_7 )
return - V_9 ;
V_14 -> V_10 = V_14 -> V_7 + V_3 * V_6 / sizeof( T_2 ) ;
return 0 ;
}
static void F_17 ( struct V_20 * V_2 )
{
F_5 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
V_2 -> V_10 = NULL ;
}
static T_2 * F_18 ( struct V_20 * V_14 , int V_15 , T_2 V_16 )
{
T_2 * V_19 ;
if ( V_16 < V_6 ) {
V_19 = V_14 -> V_7 ;
V_16 += V_15 * V_6 ;
} else {
V_19 = V_14 -> V_10 ;
V_16 -= V_6 ;
}
return V_19 + ( V_16 / sizeof( T_2 ) ) ;
}
static bool F_19 ( struct V_22 * V_23 , int V_18 )
{
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
int V_29 ;
V_29 = F_9 ( & V_25 -> V_30 , V_23 -> V_31 , V_18 ) ;
return V_29 == V_32 ;
}
static int F_20 ( struct V_22 * V_23 , int V_18 )
{
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
return F_9 ( & V_25 -> V_33 , V_23 -> V_31 , V_18 ) ;
}
static int F_21 ( struct V_22 * V_23 , int V_18 )
{
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
return F_9 ( & V_25 -> V_34 , V_23 -> V_31 , V_18 ) ;
}
static void F_22 ( struct V_22 * V_23 , int V_18 )
{
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
F_11 ( & V_25 -> V_34 , V_23 -> V_31 , V_18 , 1 ) ;
}
static void F_23 ( struct V_22 * V_23 , int V_18 )
{
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
F_11 ( & V_25 -> V_34 , V_23 -> V_31 , V_18 , 0 ) ;
}
static int F_24 ( struct V_22 * V_23 , int V_18 )
{
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
return F_9 ( & V_25 -> V_35 , V_23 -> V_31 , V_18 ) ;
}
static void F_25 ( struct V_22 * V_23 , int V_18 )
{
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
F_11 ( & V_25 -> V_35 , V_23 -> V_31 , V_18 , 1 ) ;
}
static void F_26 ( struct V_22 * V_23 , int V_18 )
{
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
F_11 ( & V_25 -> V_35 , V_23 -> V_31 , V_18 , 0 ) ;
}
static int F_27 ( struct V_22 * V_23 , int V_18 )
{
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
return F_9 ( & V_25 -> V_36 , V_23 -> V_31 , V_18 ) ;
}
static void F_28 ( struct V_22 * V_23 , int V_18 )
{
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
F_11 ( & V_25 -> V_36 , V_23 -> V_31 , V_18 , 0 ) ;
}
static int F_29 ( struct V_22 * V_23 , int V_18 )
{
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
return F_9 ( & V_25 -> V_37 , V_23 -> V_31 , V_18 ) ;
}
static void F_30 ( struct V_22 * V_23 , int V_18 )
{
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
F_11 ( & V_25 -> V_37 , V_23 -> V_31 , V_18 , 1 ) ;
}
static void F_31 ( struct V_22 * V_23 , int V_18 )
{
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
F_11 ( & V_25 -> V_37 , V_23 -> V_31 , V_18 , 0 ) ;
}
static void F_32 ( struct V_22 * V_23 , int V_18 )
{
if ( V_18 < V_6 )
F_12 ( V_18 , V_23 -> V_27 . V_38 . V_39 ) ;
else
F_12 ( V_18 - V_6 ,
V_23 -> V_27 . V_38 . V_40 ) ;
}
static void F_33 ( struct V_22 * V_23 , int V_18 )
{
if ( V_18 < V_6 )
F_13 ( V_18 , V_23 -> V_27 . V_38 . V_39 ) ;
else
F_13 ( V_18 - V_6 ,
V_23 -> V_27 . V_38 . V_40 ) ;
}
static bool F_34 ( struct V_22 * V_23 , int V_18 )
{
return F_19 ( V_23 , V_18 ) || ! F_21 ( V_23 , V_18 ) ;
}
static T_2 F_35 ( struct V_41 * V_42 , T_2 V_43 )
{
return F_36 ( * ( ( T_2 * ) V_42 -> V_44 ) ) & V_43 ;
}
static void F_37 ( struct V_41 * V_42 , T_2 V_43 , T_2 V_45 )
{
* ( ( T_2 * ) V_42 -> V_44 ) = F_38 ( V_45 ) & V_43 ;
}
static void F_39 ( struct V_41 * V_42 , T_2 * V_19 ,
T_3 V_16 , int V_46 )
{
int V_47 = ( V_16 & 3 ) * 8 ;
T_2 V_43 = ( 1UL << ( V_42 -> V_48 * 8 ) ) - 1 ;
T_2 V_49 ;
if ( V_19 ) {
V_49 = * V_19 ;
} else {
F_40 ( V_46 != ( V_50 | V_51 ) ) ;
V_49 = 0 ;
}
if ( V_42 -> V_52 ) {
T_2 V_44 = F_35 ( V_42 , V_43 ) << V_47 ;
switch ( F_41 ( V_46 ) ) {
case V_51 :
return;
case V_53 :
V_49 |= V_44 ;
break;
case V_54 :
V_49 &= ~ V_44 ;
break;
case V_55 :
V_49 = ( V_49 & ~ ( V_43 << V_47 ) ) | V_44 ;
break;
}
* V_19 = V_49 ;
} else {
switch ( F_42 ( V_46 ) ) {
case V_50 :
V_49 = 0 ;
case V_56 :
F_37 ( V_42 , V_43 , V_49 >> V_47 ) ;
}
}
}
static bool F_43 ( struct V_22 * V_23 ,
struct V_41 * V_42 , T_3 V_16 )
{
T_2 V_19 ;
T_2 V_47 = V_16 & 3 ;
switch ( V_16 & ~ 3 ) {
case 0 :
V_19 = V_23 -> V_26 -> V_27 . V_28 . V_57 ;
F_39 ( V_42 , & V_19 , V_47 ,
V_56 | V_55 ) ;
if ( V_42 -> V_52 ) {
V_23 -> V_26 -> V_27 . V_28 . V_57 = V_19 & 1 ;
F_44 ( V_23 -> V_26 ) ;
return true ;
}
break;
case 4 :
V_19 = ( F_45 ( & V_23 -> V_26 -> V_58 ) - 1 ) << 5 ;
V_19 |= ( V_23 -> V_26 -> V_27 . V_28 . V_4 >> 5 ) - 1 ;
F_39 ( V_42 , & V_19 , V_47 ,
V_56 | V_51 ) ;
break;
case 8 :
V_19 = ( V_59 << 24 ) | ( V_60 << 0 ) ;
F_39 ( V_42 , & V_19 , V_47 ,
V_56 | V_51 ) ;
break;
}
return false ;
}
static bool F_46 ( struct V_22 * V_23 ,
struct V_41 * V_42 , T_3 V_16 )
{
F_39 ( V_42 , NULL , V_16 ,
V_50 | V_51 ) ;
return false ;
}
static bool F_47 ( struct V_22 * V_23 ,
struct V_41 * V_42 ,
T_3 V_16 )
{
T_2 * V_19 = F_8 ( & V_23 -> V_26 -> V_27 . V_28 . V_33 ,
V_23 -> V_31 , V_16 ) ;
F_39 ( V_42 , V_19 , V_16 ,
V_56 | V_53 ) ;
if ( V_42 -> V_52 ) {
F_44 ( V_23 -> V_26 ) ;
return true ;
}
return false ;
}
static bool F_48 ( struct V_22 * V_23 ,
struct V_41 * V_42 ,
T_3 V_16 )
{
T_2 * V_19 = F_8 ( & V_23 -> V_26 -> V_27 . V_28 . V_33 ,
V_23 -> V_31 , V_16 ) ;
F_39 ( V_42 , V_19 , V_16 ,
V_56 | V_54 ) ;
if ( V_42 -> V_52 ) {
if ( V_16 < 4 )
* V_19 |= 0xffff ;
F_49 ( V_23 ) ;
F_44 ( V_23 -> V_26 ) ;
return true ;
}
return false ;
}
static bool F_50 ( struct V_22 * V_23 ,
struct V_41 * V_42 ,
T_3 V_16 )
{
T_2 * V_19 , V_61 ;
T_2 V_62 ;
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
V_19 = F_8 ( & V_25 -> V_30 , V_23 -> V_31 , V_16 ) ;
V_62 = ( ~ ( * V_19 ) ) ;
V_19 = F_8 ( & V_25 -> V_37 , V_23 -> V_31 , V_16 ) ;
V_61 = * V_19 ;
F_39 ( V_42 , V_19 , V_16 ,
V_56 | V_53 ) ;
if ( V_42 -> V_52 ) {
V_19 = F_8 ( & V_25 -> V_36 ,
V_23 -> V_31 , V_16 ) ;
F_39 ( V_42 , V_19 , V_16 ,
V_56 | V_53 ) ;
* V_19 &= V_62 ;
if ( V_16 < 2 ) {
* V_19 &= ~ 0xffff ;
* V_19 |= V_61 & 0xffff ;
}
F_44 ( V_23 -> V_26 ) ;
return true ;
}
return false ;
}
static bool F_51 ( struct V_22 * V_23 ,
struct V_41 * V_42 ,
T_3 V_16 )
{
T_2 * V_63 ;
T_2 * V_19 , V_61 ;
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
V_19 = F_8 ( & V_25 -> V_37 , V_23 -> V_31 , V_16 ) ;
V_61 = * V_19 ;
F_39 ( V_42 , V_19 , V_16 ,
V_56 | V_54 ) ;
if ( V_42 -> V_52 ) {
V_63 = F_8 ( & V_25 -> V_35 ,
V_23 -> V_31 , V_16 ) ;
V_19 = F_8 ( & V_25 -> V_37 ,
V_23 -> V_31 , V_16 ) ;
* V_19 |= * V_63 ;
if ( V_16 < 2 ) {
* V_19 &= ~ 0xffff ;
* V_19 |= V_61 & 0xffff ;
}
V_19 = F_8 ( & V_25 -> V_36 ,
V_23 -> V_31 , V_16 ) ;
F_39 ( V_42 , V_19 , V_16 ,
V_56 | V_54 ) ;
F_44 ( V_23 -> V_26 ) ;
return true ;
}
return false ;
}
static bool F_52 ( struct V_22 * V_23 ,
struct V_41 * V_42 ,
T_3 V_16 )
{
T_2 * V_19 = F_18 ( & V_23 -> V_26 -> V_27 . V_28 . V_64 ,
V_23 -> V_31 , V_16 ) ;
F_39 ( V_42 , V_19 , V_16 ,
V_56 | V_55 ) ;
return false ;
}
static T_2 F_53 ( struct V_26 * V_26 , int V_18 )
{
struct V_24 * V_25 = & V_26 -> V_27 . V_28 ;
int V_65 ;
T_2 V_11 = 0 ;
V_18 -= V_6 ;
for ( V_65 = 0 ; V_65 < V_66 ; V_65 ++ )
V_11 |= 1 << ( V_25 -> V_67 [ V_18 + V_65 ] + V_65 * 8 ) ;
return V_11 ;
}
static void F_54 ( struct V_26 * V_26 , T_2 V_11 , int V_18 )
{
struct V_24 * V_25 = & V_26 -> V_27 . V_28 ;
struct V_22 * V_23 ;
int V_65 , V_68 ;
unsigned long * V_69 ;
T_2 V_70 ;
V_18 -= V_6 ;
for ( V_65 = 0 ; V_65 < V_66 ; V_65 ++ ) {
int V_71 = V_65 * V_72 ;
V_70 = F_55 ( ( V_11 >> V_71 ) & 0xffU ) ;
V_70 = V_70 ? ( V_70 - 1 ) : 0 ;
V_25 -> V_67 [ V_18 + V_65 ] = V_70 ;
F_56 (c, vcpu, kvm) {
V_69 = F_15 ( & V_25 -> V_73 [ V_68 ] ) ;
if ( V_68 == V_70 )
F_12 ( V_18 + V_65 , V_69 ) ;
else
F_13 ( V_18 + V_65 , V_69 ) ;
}
}
}
static bool F_57 ( struct V_22 * V_23 ,
struct V_41 * V_42 ,
T_3 V_16 )
{
T_2 V_19 ;
if ( V_16 < 32 ) {
T_2 V_74 = 1 << V_23 -> V_31 ;
V_74 |= V_74 << 8 ;
V_74 |= V_74 << 16 ;
F_39 ( V_42 , & V_74 , V_16 ,
V_56 | V_51 ) ;
return false ;
}
V_19 = F_53 ( V_23 -> V_26 , V_16 & ~ 3U ) ;
F_39 ( V_42 , & V_19 , V_16 ,
V_56 | V_55 ) ;
if ( V_42 -> V_52 ) {
F_54 ( V_23 -> V_26 , V_19 , V_16 & ~ 3U ) ;
F_44 ( V_23 -> V_26 ) ;
return true ;
}
return false ;
}
static T_2 F_58 ( T_4 V_11 )
{
T_2 V_75 = 0 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < 16 ; V_65 ++ )
V_75 |= ( ( V_11 >> V_65 ) & V_32 ) << ( 2 * V_65 + 1 ) ;
return V_75 ;
}
static T_4 F_59 ( T_2 V_11 )
{
T_4 V_75 = 0 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < 16 ; V_65 ++ )
V_75 |= ( ( V_11 >> ( V_65 * 2 + 1 ) ) & V_32 ) << V_65 ;
return V_75 ;
}
static bool F_60 ( struct V_22 * V_23 ,
struct V_41 * V_42 , T_3 V_16 )
{
T_2 V_11 ;
T_2 * V_19 ;
V_19 = F_8 ( & V_23 -> V_26 -> V_27 . V_28 . V_30 ,
V_23 -> V_31 , V_16 >> 1 ) ;
if ( V_16 & 4 )
V_11 = * V_19 >> 16 ;
else
V_11 = * V_19 & 0xffff ;
V_11 = F_58 ( V_11 ) ;
F_39 ( V_42 , & V_11 , V_16 ,
V_56 | V_55 ) ;
if ( V_42 -> V_52 ) {
if ( V_16 < 8 ) {
* V_19 = ~ 0U ;
return false ;
}
V_11 = F_59 ( V_11 ) ;
if ( V_16 & 4 ) {
* V_19 &= 0xffff ;
* V_19 |= V_11 << 16 ;
} else {
* V_19 &= 0xffff << 16 ;
* V_19 |= V_11 ;
}
}
return false ;
}
static bool F_61 ( struct V_22 * V_23 ,
struct V_41 * V_42 , T_3 V_16 )
{
T_2 V_19 ;
F_39 ( V_42 , & V_19 , V_16 ,
V_50 | V_55 ) ;
if ( V_42 -> V_52 ) {
F_62 ( V_23 , V_19 ) ;
F_44 ( V_23 -> V_26 ) ;
return true ;
}
return false ;
}
static void F_63 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
struct V_38 * V_38 = & V_23 -> V_27 . V_38 ;
int V_31 = V_23 -> V_31 ;
int V_65 ;
F_64 (i, vgic_cpu->lr_used, vgic_cpu->nr_lr) {
struct V_76 V_77 = F_65 ( V_23 , V_65 ) ;
if ( ( V_77 . V_78 & V_79 ) == V_80 )
continue;
F_30 ( V_23 , V_77 . V_18 ) ;
if ( V_77 . V_18 < V_81 )
* F_66 ( V_25 , V_31 , V_77 . V_18 ) |= 1 << V_77 . V_82 ;
V_77 . V_78 &= ~ V_83 ;
F_67 ( V_23 , V_65 , V_77 ) ;
if ( ! ( V_77 . V_78 & V_79 ) ) {
F_68 ( V_65 , V_77 . V_18 , V_23 ) ;
F_23 ( V_23 , V_77 . V_18 ) ;
}
F_44 ( V_23 -> V_26 ) ;
}
}
static bool F_69 ( struct V_22 * V_23 ,
struct V_41 * V_42 ,
T_3 V_16 )
{
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
int V_84 ;
int V_85 = ( V_16 & ~ 0x3 ) ;
int V_86 = V_85 + 3 ;
int V_31 = V_23 -> V_31 ;
T_2 V_19 = 0 ;
for ( V_84 = V_85 ; V_84 <= V_86 ; V_84 ++ ) {
int V_71 = 8 * ( V_84 - V_85 ) ;
V_19 |= ( ( T_2 ) * F_66 ( V_25 , V_31 , V_84 ) ) << V_71 ;
}
F_37 ( V_42 , ~ 0 , V_19 ) ;
return false ;
}
static bool F_70 ( struct V_22 * V_23 ,
struct V_41 * V_42 ,
T_3 V_16 , bool V_87 )
{
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
int V_84 ;
int V_85 = ( V_16 & ~ 0x3 ) ;
int V_86 = V_85 + 3 ;
int V_31 = V_23 -> V_31 ;
T_2 V_19 ;
bool V_88 = false ;
V_19 = F_35 ( V_42 , ~ 0 ) ;
for ( V_84 = V_85 ; V_84 <= V_86 ; V_84 ++ ) {
T_5 V_43 = V_19 >> ( 8 * ( V_84 - V_85 ) ) ;
T_5 * V_89 = F_66 ( V_25 , V_31 , V_84 ) ;
if ( V_87 ) {
if ( ( * V_89 & V_43 ) != V_43 )
V_88 = true ;
* V_89 |= V_43 ;
} else {
if ( * V_89 & V_43 )
V_88 = true ;
* V_89 &= ~ V_43 ;
}
}
if ( V_88 )
F_44 ( V_23 -> V_26 ) ;
return V_88 ;
}
static bool F_71 ( struct V_22 * V_23 ,
struct V_41 * V_42 ,
T_3 V_16 )
{
if ( ! V_42 -> V_52 )
return F_69 ( V_23 , V_42 , V_16 ) ;
else
return F_70 ( V_23 , V_42 , V_16 , true ) ;
}
static bool F_72 ( struct V_22 * V_23 ,
struct V_41 * V_42 ,
T_3 V_16 )
{
if ( ! V_42 -> V_52 )
return F_69 ( V_23 , V_42 , V_16 ) ;
else
return F_70 ( V_23 , V_42 , V_16 , false ) ;
}
static const
struct V_90 * F_73 ( const struct V_90 * V_91 ,
struct V_41 * V_42 ,
T_3 V_16 )
{
const struct V_90 * V_92 = V_91 ;
while ( V_92 -> V_48 ) {
if ( V_16 >= V_92 -> V_93 &&
( V_16 + V_42 -> V_48 ) <= ( V_92 -> V_93 + V_92 -> V_48 ) )
return V_92 ;
V_92 ++ ;
}
return NULL ;
}
static bool F_74 ( const struct V_24 * V_25 ,
const struct V_90 * V_94 ,
unsigned long V_16 )
{
int V_18 ;
if ( ! V_94 -> V_95 )
return true ;
V_18 = V_16 * 8 / V_94 -> V_95 ;
if ( V_18 >= V_25 -> V_4 )
return false ;
return true ;
}
bool F_75 ( struct V_22 * V_23 , struct V_96 * V_97 ,
struct V_41 * V_42 )
{
const struct V_90 * V_94 ;
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
unsigned long V_93 = V_25 -> V_98 ;
bool V_99 ;
unsigned long V_16 ;
if ( ! F_76 ( V_23 -> V_26 ) ||
V_42 -> V_100 < V_93 ||
( V_42 -> V_100 + V_42 -> V_48 ) > ( V_93 + V_101 ) )
return false ;
if ( V_42 -> V_48 > 4 ) {
F_77 ( V_23 , V_42 -> V_100 ) ;
return true ;
}
V_16 = V_42 -> V_100 - V_93 ;
V_94 = F_73 ( V_102 , V_42 , V_16 ) ;
if ( F_78 ( ! V_94 || ! V_94 -> V_103 ) ) {
F_79 ( L_1 ,
V_42 -> V_52 , V_42 -> V_100 , V_42 -> V_48 ) ;
return false ;
}
F_80 ( & V_23 -> V_26 -> V_27 . V_28 . V_104 ) ;
V_16 = V_42 -> V_100 - V_94 -> V_93 - V_93 ;
if ( F_74 ( V_25 , V_94 , V_16 ) ) {
V_99 = V_94 -> V_103 ( V_23 , V_42 , V_16 ) ;
} else {
F_39 ( V_42 , NULL , V_16 ,
V_50 | V_51 ) ;
V_99 = false ;
}
F_81 ( & V_23 -> V_26 -> V_27 . V_28 . V_104 ) ;
F_82 ( V_97 , V_42 ) ;
F_83 ( V_23 , V_97 ) ;
if ( V_99 )
F_84 ( V_23 -> V_26 ) ;
return true ;
}
static T_5 * F_66 ( struct V_24 * V_25 , int V_31 , int V_84 )
{
return V_25 -> V_105 + V_31 * V_81 + V_84 ;
}
static void F_62 ( struct V_22 * V_23 , T_2 V_19 )
{
struct V_26 * V_26 = V_23 -> V_26 ;
struct V_24 * V_25 = & V_26 -> V_27 . V_28 ;
int V_106 = F_45 ( & V_26 -> V_58 ) ;
T_5 V_107 ;
int V_84 , V_46 , V_68 , V_31 ;
V_31 = V_23 -> V_31 ;
V_84 = V_19 & 0xf ;
V_107 = ( V_19 >> 16 ) & 0xff ;
V_46 = ( V_19 >> 24 ) & 3 ;
switch ( V_46 ) {
case 0 :
if ( ! V_107 )
return;
break;
case 1 :
V_107 = ( ( 1 << V_106 ) - 1 ) & ~ ( 1 << V_31 ) & 0xff ;
break;
case 2 :
V_107 = 1 << V_31 ;
break;
}
F_56 (c, vcpu, kvm) {
if ( V_107 & 1 ) {
F_30 ( V_23 , V_84 ) ;
* F_66 ( V_25 , V_68 , V_84 ) |= 1 << V_31 ;
F_85 ( L_2 , V_84 , V_31 , V_68 ) ;
}
V_107 >>= 1 ;
}
}
static int F_86 ( struct V_24 * V_25 )
{
return V_25 -> V_4 - V_6 ;
}
static int F_87 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
unsigned long * V_108 , * V_57 , * V_109 , * V_110 ;
unsigned long V_111 , V_40 ;
int V_112 = F_86 ( V_25 ) ;
int V_31 ;
V_31 = V_23 -> V_31 ;
V_109 = V_23 -> V_27 . V_38 . V_39 ;
V_110 = V_23 -> V_27 . V_38 . V_40 ;
V_108 = F_14 ( & V_25 -> V_37 , V_31 ) ;
V_57 = F_14 ( & V_25 -> V_33 , V_31 ) ;
F_88 ( V_109 , V_108 , V_57 , V_6 ) ;
V_108 = F_15 ( & V_25 -> V_37 ) ;
V_57 = F_15 ( & V_25 -> V_33 ) ;
F_88 ( V_110 , V_108 , V_57 , V_112 ) ;
F_88 ( V_110 , V_110 ,
F_15 ( & V_25 -> V_73 [ V_31 ] ) ,
V_112 ) ;
V_111 = F_89 ( V_109 , V_6 ) ;
V_40 = F_89 ( V_110 , V_112 ) ;
return ( V_111 < V_6 ||
V_40 < F_86 ( V_25 ) ) ;
}
static void F_44 ( struct V_26 * V_26 )
{
struct V_24 * V_25 = & V_26 -> V_27 . V_28 ;
struct V_22 * V_23 ;
int V_68 ;
if ( ! V_25 -> V_57 ) {
F_12 ( 0 , V_25 -> V_113 ) ;
return;
}
F_56 (c, vcpu, kvm) {
if ( F_87 ( V_23 ) ) {
F_90 ( L_3 , V_68 ) ;
F_12 ( V_68 , V_25 -> V_113 ) ;
}
}
}
static struct V_76 F_65 ( const struct V_22 * V_23 , int V_77 )
{
return V_114 -> V_115 ( V_23 , V_77 ) ;
}
static void F_67 ( struct V_22 * V_23 , int V_77 ,
struct V_76 V_116 )
{
V_114 -> V_117 ( V_23 , V_77 , V_116 ) ;
}
static void F_91 ( struct V_22 * V_23 , int V_77 ,
struct V_76 V_116 )
{
V_114 -> V_118 ( V_23 , V_77 , V_116 ) ;
}
static inline T_1 F_92 ( struct V_22 * V_23 )
{
return V_114 -> V_119 ( V_23 ) ;
}
static inline T_1 F_93 ( struct V_22 * V_23 )
{
return V_114 -> V_120 ( V_23 ) ;
}
static inline T_2 F_94 ( struct V_22 * V_23 )
{
return V_114 -> V_121 ( V_23 ) ;
}
static inline void F_95 ( struct V_22 * V_23 )
{
V_114 -> V_122 ( V_23 ) ;
}
static inline void F_96 ( struct V_22 * V_23 )
{
V_114 -> V_123 ( V_23 ) ;
}
static inline void F_97 ( struct V_22 * V_23 , struct V_124 * V_125 )
{
V_114 -> V_126 ( V_23 , V_125 ) ;
}
static void F_98 ( struct V_22 * V_23 , struct V_124 * V_125 )
{
V_114 -> V_127 ( V_23 , V_125 ) ;
}
static inline void F_99 ( struct V_22 * V_23 )
{
V_114 -> V_128 ( V_23 ) ;
}
static void F_68 ( int V_129 , int V_18 , struct V_22 * V_23 )
{
struct V_38 * V_38 = & V_23 -> V_27 . V_38 ;
struct V_76 V_116 = F_65 ( V_23 , V_129 ) ;
V_116 . V_78 = 0 ;
F_67 ( V_23 , V_129 , V_116 ) ;
F_13 ( V_129 , V_38 -> V_130 ) ;
V_38 -> V_131 [ V_18 ] = V_132 ;
}
static void F_49 ( struct V_22 * V_23 )
{
struct V_38 * V_38 = & V_23 -> V_27 . V_38 ;
int V_77 ;
F_64 (lr, vgic_cpu->lr_used, vgic->nr_lr) {
struct V_76 V_116 = F_65 ( V_23 , V_77 ) ;
if ( ! F_20 ( V_23 , V_116 . V_18 ) ) {
F_68 ( V_77 , V_116 . V_18 , V_23 ) ;
if ( F_21 ( V_23 , V_116 . V_18 ) )
F_23 ( V_23 , V_116 . V_18 ) ;
}
}
}
static bool F_100 ( struct V_22 * V_23 , T_5 V_133 , int V_18 )
{
struct V_38 * V_38 = & V_23 -> V_27 . V_38 ;
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
struct V_76 V_116 ;
int V_77 ;
F_40 ( V_133 & ~ 7 ) ;
F_40 ( V_133 && V_18 >= V_81 ) ;
F_40 ( V_18 >= V_25 -> V_4 ) ;
F_85 ( L_4 , V_18 ) ;
V_77 = V_38 -> V_131 [ V_18 ] ;
if ( V_77 != V_132 ) {
V_116 = F_65 ( V_23 , V_77 ) ;
if ( V_116 . V_82 == V_133 ) {
F_85 ( L_5 , V_77 , V_116 . V_18 ) ;
F_40 ( ! F_10 ( V_77 , V_38 -> V_130 ) ) ;
V_116 . V_78 |= V_83 ;
F_67 ( V_23 , V_77 , V_116 ) ;
return true ;
}
}
V_77 = F_101 ( ( unsigned long * ) V_38 -> V_130 ,
V_28 -> V_134 ) ;
if ( V_77 >= V_28 -> V_134 )
return false ;
F_85 ( L_6 , V_77 , V_18 , V_133 ) ;
V_38 -> V_131 [ V_18 ] = V_77 ;
F_12 ( V_77 , V_38 -> V_130 ) ;
V_116 . V_18 = V_18 ;
V_116 . V_82 = V_133 ;
V_116 . V_78 = V_83 ;
if ( ! F_19 ( V_23 , V_18 ) )
V_116 . V_78 |= V_135 ;
F_67 ( V_23 , V_77 , V_116 ) ;
return true ;
}
static bool F_102 ( struct V_22 * V_23 , int V_18 )
{
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
unsigned long V_136 ;
int V_31 = V_23 -> V_31 ;
int V_68 ;
V_136 = * F_66 ( V_25 , V_31 , V_18 ) ;
F_64 (c, &sources, dist->nr_cpus) {
if ( F_100 ( V_23 , V_68 , V_18 ) )
F_13 ( V_68 , & V_136 ) ;
}
* F_66 ( V_25 , V_31 , V_18 ) = V_136 ;
if ( ! V_136 ) {
F_31 ( V_23 , V_18 ) ;
F_33 ( V_23 , V_18 ) ;
return true ;
}
return false ;
}
static bool F_103 ( struct V_22 * V_23 , int V_18 )
{
if ( ! F_34 ( V_23 , V_18 ) )
return true ;
if ( F_100 ( V_23 , 0 , V_18 ) ) {
if ( F_19 ( V_23 , V_18 ) ) {
F_31 ( V_23 , V_18 ) ;
F_33 ( V_23 , V_18 ) ;
} else {
F_22 ( V_23 , V_18 ) ;
}
return true ;
}
return false ;
}
static void F_104 ( struct V_22 * V_23 )
{
struct V_38 * V_38 = & V_23 -> V_27 . V_38 ;
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
int V_65 , V_31 ;
int V_137 = 0 ;
V_31 = V_23 -> V_31 ;
if ( ! F_105 ( V_23 ) ) {
F_90 ( L_7 , V_31 ) ;
goto V_138;
}
F_64 (i, vgic_cpu->pending_percpu, VGIC_NR_SGIS) {
if ( ! F_102 ( V_23 , V_65 ) )
V_137 = 1 ;
}
F_106 (i, vgic_cpu->pending_percpu, VGIC_NR_PRIVATE_IRQS) {
if ( ! F_103 ( V_23 , V_65 ) )
V_137 = 1 ;
}
F_64 (i, vgic_cpu->pending_shared, vgic_nr_shared_irqs(dist)) {
if ( ! F_103 ( V_23 , V_65 + V_6 ) )
V_137 = 1 ;
}
V_138:
if ( V_137 ) {
F_95 ( V_23 ) ;
} else {
F_96 ( V_23 ) ;
F_13 ( V_31 , V_25 -> V_113 ) ;
}
}
static bool F_107 ( struct V_22 * V_23 )
{
T_2 V_139 = F_94 ( V_23 ) ;
bool V_140 = false ;
F_85 ( L_8 , V_139 ) ;
if ( V_139 & V_141 ) {
T_1 V_142 = F_93 ( V_23 ) ;
unsigned long * V_143 = F_6 ( & V_142 ) ;
int V_77 ;
F_64 (lr, eisr_ptr, vgic->nr_lr) {
struct V_76 V_116 = F_65 ( V_23 , V_77 ) ;
F_108 ( F_19 ( V_23 , V_116 . V_18 ) ) ;
F_23 ( V_23 , V_116 . V_18 ) ;
F_108 ( V_116 . V_78 & V_79 ) ;
V_116 . V_78 = 0 ;
F_67 ( V_23 , V_77 , V_116 ) ;
F_28 ( V_23 , V_116 . V_18 ) ;
if ( F_24 ( V_23 , V_116 . V_18 ) ) {
F_32 ( V_23 , V_116 . V_18 ) ;
V_140 = true ;
} else {
F_31 ( V_23 , V_116 . V_18 ) ;
F_33 ( V_23 , V_116 . V_18 ) ;
}
F_91 ( V_23 , V_77 , V_116 ) ;
}
}
if ( V_139 & V_144 )
F_96 ( V_23 ) ;
return V_140 ;
}
static void F_109 ( struct V_22 * V_23 )
{
struct V_38 * V_38 = & V_23 -> V_27 . V_38 ;
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
T_1 V_145 ;
unsigned long * V_146 ;
int V_77 , V_108 ;
bool V_140 ;
V_140 = F_107 ( V_23 ) ;
V_145 = F_92 ( V_23 ) ;
V_146 = F_6 ( & V_145 ) ;
F_64 (lr, elrsr_ptr, vgic->nr_lr) {
struct V_76 V_116 ;
if ( ! F_110 ( V_77 , V_38 -> V_130 ) )
continue;
V_116 = F_65 ( V_23 , V_77 ) ;
F_40 ( V_116 . V_18 >= V_25 -> V_4 ) ;
V_38 -> V_131 [ V_116 . V_18 ] = V_132 ;
}
V_108 = F_101 ( V_146 , V_28 -> V_134 ) ;
if ( V_140 || V_108 < V_28 -> V_134 )
F_12 ( V_23 -> V_31 , V_25 -> V_113 ) ;
}
void F_111 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
if ( ! F_76 ( V_23 -> V_26 ) )
return;
F_80 ( & V_25 -> V_104 ) ;
F_104 ( V_23 ) ;
F_81 ( & V_25 -> V_104 ) ;
}
void F_112 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
if ( ! F_76 ( V_23 -> V_26 ) )
return;
F_80 ( & V_25 -> V_104 ) ;
F_109 ( V_23 ) ;
F_81 ( & V_25 -> V_104 ) ;
}
int F_105 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = & V_23 -> V_26 -> V_27 . V_28 ;
if ( ! F_76 ( V_23 -> V_26 ) )
return 0 ;
return F_10 ( V_23 -> V_31 , V_25 -> V_113 ) ;
}
static void F_84 ( struct V_26 * V_26 )
{
struct V_22 * V_23 ;
int V_68 ;
F_56 (c, vcpu, kvm) {
if ( F_105 ( V_23 ) )
F_113 ( V_23 ) ;
}
}
static int F_114 ( struct V_22 * V_23 , int V_18 , int V_147 )
{
int V_148 = F_19 ( V_23 , V_18 ) ;
if ( V_148 ) {
int V_78 = F_29 ( V_23 , V_18 ) ;
return V_147 > V_78 ;
} else {
int V_78 = F_24 ( V_23 , V_18 ) ;
return V_147 != V_78 ;
}
}
static int F_115 ( struct V_26 * V_26 , int V_15 ,
unsigned int V_149 , bool V_147 )
{
struct V_24 * V_25 = & V_26 -> V_27 . V_28 ;
struct V_22 * V_23 ;
int V_148 , V_150 ;
int V_57 ;
bool V_151 = true ;
F_80 ( & V_25 -> V_104 ) ;
V_23 = F_116 ( V_26 , V_15 ) ;
V_148 = F_19 ( V_23 , V_149 ) ;
V_150 = ! V_148 ;
if ( ! F_114 ( V_23 , V_149 , V_147 ) ) {
V_151 = false ;
goto V_152;
}
if ( V_149 >= V_6 ) {
V_15 = V_25 -> V_67 [ V_149 - V_6 ] ;
V_23 = F_116 ( V_26 , V_15 ) ;
}
F_85 ( L_9 , V_149 , V_147 , V_15 ) ;
if ( V_147 ) {
if ( V_150 )
F_25 ( V_23 , V_149 ) ;
F_30 ( V_23 , V_149 ) ;
} else {
if ( V_150 ) {
F_26 ( V_23 , V_149 ) ;
if ( ! F_27 ( V_23 , V_149 ) )
F_31 ( V_23 , V_149 ) ;
}
V_151 = false ;
goto V_152;
}
V_57 = F_20 ( V_23 , V_149 ) ;
if ( ! V_57 ) {
V_151 = false ;
goto V_152;
}
if ( ! F_34 ( V_23 , V_149 ) ) {
V_151 = false ;
goto V_152;
}
if ( V_147 ) {
F_32 ( V_23 , V_149 ) ;
F_12 ( V_15 , V_25 -> V_113 ) ;
}
V_152:
F_81 ( & V_25 -> V_104 ) ;
return V_151 ? V_15 : - V_153 ;
}
int F_117 ( struct V_26 * V_26 , int V_15 , unsigned int V_149 ,
bool V_147 )
{
int V_151 = 0 ;
int V_31 ;
if ( F_78 ( ! F_118 ( V_26 ) ) ) {
F_119 ( & V_26 -> V_104 ) ;
V_151 = F_120 ( V_26 ) ;
F_121 ( & V_26 -> V_104 ) ;
if ( V_151 )
goto V_152;
}
V_31 = F_115 ( V_26 , V_15 , V_149 , V_147 ) ;
if ( V_31 >= 0 ) {
F_113 ( F_116 ( V_26 , V_31 ) ) ;
}
V_152:
return V_151 ;
}
static T_6 F_122 ( int V_18 , void * V_44 )
{
return V_154 ;
}
void F_123 ( struct V_22 * V_23 )
{
struct V_38 * V_38 = & V_23 -> V_27 . V_38 ;
F_5 ( V_38 -> V_40 ) ;
F_5 ( V_38 -> V_131 ) ;
V_38 -> V_40 = NULL ;
V_38 -> V_131 = NULL ;
}
static int F_124 ( struct V_22 * V_23 , int V_4 )
{
struct V_38 * V_38 = & V_23 -> V_27 . V_38 ;
int V_155 = ( V_4 - V_6 ) / 8 ;
V_38 -> V_40 = F_3 ( V_155 , V_8 ) ;
V_38 -> V_131 = F_125 ( V_4 , V_8 ) ;
if ( ! V_38 -> V_40 || ! V_38 -> V_131 ) {
F_123 ( V_23 ) ;
return - V_9 ;
}
memset ( V_38 -> V_131 , V_132 , V_4 ) ;
V_38 -> V_134 = V_28 -> V_134 ;
return 0 ;
}
void F_126 ( struct V_26 * V_26 )
{
struct V_24 * V_25 = & V_26 -> V_27 . V_28 ;
struct V_22 * V_23 ;
int V_65 ;
F_56 (i, vcpu, kvm)
F_123 ( V_23 ) ;
F_4 ( & V_25 -> V_33 ) ;
F_4 ( & V_25 -> V_35 ) ;
F_4 ( & V_25 -> V_37 ) ;
F_4 ( & V_25 -> V_36 ) ;
F_4 ( & V_25 -> V_34 ) ;
F_4 ( & V_25 -> V_30 ) ;
F_17 ( & V_25 -> V_64 ) ;
if ( V_25 -> V_73 ) {
for ( V_65 = 0 ; V_65 < V_25 -> V_3 ; V_65 ++ )
F_4 ( & V_25 -> V_73 [ V_65 ] ) ;
}
F_5 ( V_25 -> V_105 ) ;
F_5 ( V_25 -> V_67 ) ;
F_5 ( V_25 -> V_73 ) ;
F_5 ( V_25 -> V_113 ) ;
V_25 -> V_105 = NULL ;
V_25 -> V_67 = NULL ;
V_25 -> V_73 = NULL ;
V_25 -> V_113 = NULL ;
V_25 -> V_3 = 0 ;
}
static int F_120 ( struct V_26 * V_26 )
{
struct V_24 * V_25 = & V_26 -> V_27 . V_28 ;
struct V_22 * V_23 ;
int V_3 , V_4 ;
int V_151 , V_65 , V_31 ;
if ( F_118 ( V_26 ) )
return 0 ;
V_3 = V_25 -> V_3 = F_45 ( & V_26 -> V_58 ) ;
if ( ! V_3 )
return - V_153 ;
if ( ! V_25 -> V_4 )
V_25 -> V_4 = V_156 ;
V_4 = V_25 -> V_4 ;
V_151 = F_1 ( & V_25 -> V_33 , V_3 , V_4 ) ;
V_151 |= F_1 ( & V_25 -> V_35 , V_3 , V_4 ) ;
V_151 |= F_1 ( & V_25 -> V_37 , V_3 , V_4 ) ;
V_151 |= F_1 ( & V_25 -> V_36 , V_3 , V_4 ) ;
V_151 |= F_1 ( & V_25 -> V_34 , V_3 , V_4 ) ;
V_151 |= F_1 ( & V_25 -> V_30 , V_3 , V_4 ) ;
V_151 |= F_16 ( & V_25 -> V_64 , V_3 , V_4 ) ;
if ( V_151 )
goto V_152;
V_25 -> V_105 = F_3 ( V_3 * V_81 , V_8 ) ;
V_25 -> V_67 = F_3 ( V_4 - V_6 , V_8 ) ;
V_25 -> V_73 = F_3 ( sizeof( * V_25 -> V_73 ) * V_3 ,
V_8 ) ;
V_25 -> V_113 = F_3 ( F_2 ( V_3 ) * sizeof( long ) ,
V_8 ) ;
if ( ! V_25 -> V_105 ||
! V_25 -> V_67 ||
! V_25 -> V_73 ||
! V_25 -> V_113 ) {
V_151 = - V_9 ;
goto V_152;
}
for ( V_65 = 0 ; V_65 < V_3 ; V_65 ++ )
V_151 |= F_1 ( & V_25 -> V_73 [ V_65 ] ,
V_3 , V_4 ) ;
if ( V_151 )
goto V_152;
for ( V_65 = V_6 ; V_65 < V_25 -> V_4 ; V_65 += 4 )
F_54 ( V_26 , 0 , V_65 ) ;
F_56 (vcpu_id, vcpu, kvm) {
V_151 = F_124 ( V_23 , V_4 ) ;
if ( V_151 ) {
F_127 ( L_10 ) ;
break;
}
for ( V_65 = 0 ; V_65 < V_25 -> V_4 ; V_65 ++ ) {
if ( V_65 < V_157 )
F_11 ( & V_25 -> V_33 ,
V_23 -> V_31 , V_65 , 1 ) ;
if ( V_65 < V_6 )
F_11 ( & V_25 -> V_30 ,
V_23 -> V_31 , V_65 ,
V_32 ) ;
}
F_99 ( V_23 ) ;
}
V_152:
if ( V_151 )
F_126 ( V_26 ) ;
return V_151 ;
}
int F_128 ( struct V_26 * V_26 )
{
int V_151 = 0 ;
if ( ! F_76 ( V_26 ) )
return 0 ;
F_119 ( & V_26 -> V_104 ) ;
if ( F_129 ( V_26 ) )
goto V_152;
if ( F_130 ( V_26 -> V_27 . V_28 . V_98 ) ||
F_130 ( V_26 -> V_27 . V_28 . V_158 ) ) {
F_127 ( L_11 ) ;
V_151 = - V_159 ;
goto V_152;
}
V_151 = F_120 ( V_26 ) ;
if ( V_151 ) {
F_127 ( L_12 ) ;
goto V_152;
}
V_151 = F_131 ( V_26 , V_26 -> V_27 . V_28 . V_158 ,
V_28 -> V_160 , V_161 ,
true ) ;
if ( V_151 ) {
F_127 ( L_13 ) ;
goto V_152;
}
V_26 -> V_27 . V_28 . V_162 = true ;
V_152:
if ( V_151 )
F_126 ( V_26 ) ;
F_121 ( & V_26 -> V_104 ) ;
return V_151 ;
}
int F_132 ( struct V_26 * V_26 )
{
int V_65 , V_163 = - 1 , V_151 ;
struct V_22 * V_23 ;
F_119 ( & V_26 -> V_104 ) ;
if ( V_26 -> V_27 . V_28 . V_164 ) {
V_151 = - V_165 ;
goto V_152;
}
V_151 = - V_166 ;
F_56 (i, vcpu, kvm) {
if ( ! F_133 ( & V_23 -> V_167 ) )
goto V_168;
V_163 = V_65 ;
}
F_56 (i, vcpu, kvm) {
if ( V_23 -> V_27 . V_169 )
goto V_168;
}
V_151 = 0 ;
F_134 ( & V_26 -> V_27 . V_28 . V_104 ) ;
V_26 -> V_27 . V_28 . V_170 = true ;
V_26 -> V_27 . V_28 . V_164 = V_28 -> V_164 ;
V_26 -> V_27 . V_28 . V_98 = V_171 ;
V_26 -> V_27 . V_28 . V_158 = V_171 ;
V_168:
for (; V_163 >= 0 ; V_163 -- ) {
V_23 = F_116 ( V_26 , V_163 ) ;
F_121 ( & V_23 -> V_167 ) ;
}
V_152:
F_121 ( & V_26 -> V_104 ) ;
return V_151 ;
}
static int F_135 ( struct V_26 * V_26 )
{
T_3 V_25 = V_26 -> V_27 . V_28 . V_98 ;
T_3 V_172 = V_26 -> V_27 . V_28 . V_158 ;
if ( F_130 ( V_25 ) || F_130 ( V_172 ) )
return 0 ;
if ( ( V_25 <= V_172 && V_25 + V_101 > V_172 ) ||
( V_172 <= V_25 && V_172 + V_161 > V_25 ) )
return - V_166 ;
return 0 ;
}
static int F_136 ( struct V_26 * V_26 , T_3 * V_173 ,
T_3 V_174 , T_3 V_21 )
{
int V_151 ;
if ( V_174 & ~ V_175 )
return - V_176 ;
if ( V_174 & ( V_177 - 1 ) )
return - V_153 ;
if ( ! F_130 ( * V_173 ) )
return - V_165 ;
if ( V_174 + V_21 < V_174 )
return - V_153 ;
* V_173 = V_174 ;
V_151 = F_135 ( V_26 ) ;
if ( V_151 )
* V_173 = V_171 ;
return V_151 ;
}
int F_137 ( struct V_26 * V_26 , unsigned long type , T_1 * V_174 , bool V_178 )
{
int V_92 = 0 ;
struct V_24 * V_28 = & V_26 -> V_27 . V_28 ;
F_119 ( & V_26 -> V_104 ) ;
switch ( type ) {
case V_179 :
if ( V_178 ) {
V_92 = F_136 ( V_26 , & V_28 -> V_98 ,
* V_174 , V_101 ) ;
} else {
* V_174 = V_28 -> V_98 ;
}
break;
case V_180 :
if ( V_178 ) {
V_92 = F_136 ( V_26 , & V_28 -> V_158 ,
* V_174 , V_161 ) ;
} else {
* V_174 = V_28 -> V_158 ;
}
break;
default:
V_92 = - V_181 ;
}
F_121 ( & V_26 -> V_104 ) ;
return V_92 ;
}
static bool F_138 ( struct V_22 * V_23 ,
struct V_41 * V_42 , T_3 V_16 )
{
bool V_88 = false ;
struct V_124 V_125 ;
T_2 * V_182 ;
T_2 V_19 ;
F_97 ( V_23 , & V_125 ) ;
switch ( V_16 & ~ 0x3 ) {
case V_183 :
V_182 = & V_125 . V_184 ;
break;
case V_185 :
V_182 = & V_125 . V_186 ;
break;
case V_187 :
V_182 = & V_125 . V_188 ;
break;
case V_189 :
V_182 = & V_125 . V_190 ;
break;
default:
F_139 () ;
}
if ( ! V_42 -> V_52 ) {
V_19 = * V_182 ;
F_37 ( V_42 , ~ 0 , V_19 ) ;
} else {
V_19 = F_35 ( V_42 , ~ 0 ) ;
if ( V_19 != * V_182 ) {
* V_182 = V_19 ;
F_98 ( V_23 , & V_125 ) ;
V_88 = true ;
}
}
return V_88 ;
}
static bool F_140 ( struct V_22 * V_23 ,
struct V_41 * V_42 , T_3 V_16 )
{
return F_138 ( V_23 , V_42 , V_189 ) ;
}
static bool F_141 ( struct V_22 * V_23 ,
struct V_41 * V_42 ,
T_3 V_16 )
{
T_2 V_19 ;
if ( V_42 -> V_52 )
return false ;
V_19 = ( V_59 << 20 ) |
( V_191 << 16 ) |
( V_60 << 0 ) ;
F_37 ( V_42 , ~ 0 , V_19 ) ;
return false ;
}
static int F_142 ( struct V_192 * V_193 ,
struct V_194 * V_195 ,
T_2 * V_19 , bool V_52 )
{
const struct V_90 * V_92 = NULL , * V_91 ;
T_3 V_16 ;
int V_151 , V_15 , V_68 ;
struct V_22 * V_23 , * V_196 ;
struct V_24 * V_28 ;
struct V_41 V_42 ;
V_16 = V_195 -> V_195 & V_197 ;
V_15 = ( V_195 -> V_195 & V_198 ) >>
V_199 ;
F_119 ( & V_193 -> V_26 -> V_104 ) ;
V_151 = F_120 ( V_193 -> V_26 ) ;
if ( V_151 )
goto V_152;
if ( V_15 >= F_45 ( & V_193 -> V_26 -> V_58 ) ) {
V_151 = - V_153 ;
goto V_152;
}
V_23 = F_116 ( V_193 -> V_26 , V_15 ) ;
V_28 = & V_193 -> V_26 -> V_27 . V_28 ;
V_42 . V_48 = 4 ;
V_42 . V_52 = V_52 ;
if ( V_52 )
F_37 ( & V_42 , ~ 0 , * V_19 ) ;
switch ( V_195 -> V_200 ) {
case V_201 :
V_42 . V_100 = V_28 -> V_98 + V_16 ;
V_91 = V_102 ;
break;
case V_202 :
V_42 . V_100 = V_28 -> V_158 + V_16 ;
V_91 = V_203 ;
break;
default:
F_139 () ;
}
V_92 = F_73 ( V_91 , & V_42 , V_16 ) ;
if ( F_78 ( ! V_92 || ! V_92 -> V_103 ) ) {
V_151 = - V_159 ;
goto V_152;
}
F_80 ( & V_28 -> V_104 ) ;
F_56 (c, tmp_vcpu, dev->kvm) {
if ( F_78 ( V_196 -> V_172 != - 1 ) ) {
V_151 = - V_166 ;
goto V_204;
}
}
F_56 (c, tmp_vcpu, dev->kvm)
F_63 ( V_196 ) ;
V_16 -= V_92 -> V_93 ;
V_92 -> V_103 ( V_23 , & V_42 , V_16 ) ;
if ( ! V_52 )
* V_19 = F_35 ( & V_42 , ~ 0 ) ;
V_151 = 0 ;
V_204:
F_81 ( & V_28 -> V_104 ) ;
V_152:
F_121 ( & V_193 -> V_26 -> V_104 ) ;
return V_151 ;
}
static int F_143 ( struct V_192 * V_193 , struct V_194 * V_195 )
{
int V_92 ;
switch ( V_195 -> V_200 ) {
case V_205 : {
T_1 T_7 * V_206 = ( T_1 T_7 * ) ( long ) V_195 -> V_174 ;
T_1 V_174 ;
unsigned long type = ( unsigned long ) V_195 -> V_195 ;
if ( F_144 ( & V_174 , V_206 , sizeof( V_174 ) ) )
return - V_207 ;
V_92 = F_137 ( V_193 -> V_26 , type , & V_174 , true ) ;
return ( V_92 == - V_181 ) ? - V_159 : V_92 ;
}
case V_201 :
case V_202 : {
T_2 T_7 * V_206 = ( T_2 T_7 * ) ( long ) V_195 -> V_174 ;
T_2 V_19 ;
if ( F_145 ( V_19 , V_206 ) )
return - V_207 ;
return F_142 ( V_193 , V_195 , & V_19 , true ) ;
}
case V_208 : {
T_2 T_7 * V_206 = ( T_2 T_7 * ) ( long ) V_195 -> V_174 ;
T_2 V_11 ;
int V_151 = 0 ;
if ( F_145 ( V_11 , V_206 ) )
return - V_207 ;
if ( V_11 < ( V_6 + 32 ) ||
V_11 > V_209 ||
( V_11 & 31 ) )
return - V_153 ;
F_119 ( & V_193 -> V_26 -> V_104 ) ;
if ( F_129 ( V_193 -> V_26 ) || V_193 -> V_26 -> V_27 . V_28 . V_4 )
V_151 = - V_166 ;
else
V_193 -> V_26 -> V_27 . V_28 . V_4 = V_11 ;
F_121 ( & V_193 -> V_26 -> V_104 ) ;
return V_151 ;
}
}
return - V_159 ;
}
static int F_146 ( struct V_192 * V_193 , struct V_194 * V_195 )
{
int V_92 = - V_159 ;
switch ( V_195 -> V_200 ) {
case V_205 : {
T_1 T_7 * V_206 = ( T_1 T_7 * ) ( long ) V_195 -> V_174 ;
T_1 V_174 ;
unsigned long type = ( unsigned long ) V_195 -> V_195 ;
V_92 = F_137 ( V_193 -> V_26 , type , & V_174 , false ) ;
if ( V_92 )
return ( V_92 == - V_181 ) ? - V_159 : V_92 ;
if ( F_147 ( V_206 , & V_174 , sizeof( V_174 ) ) )
return - V_207 ;
break;
}
case V_201 :
case V_202 : {
T_2 T_7 * V_206 = ( T_2 T_7 * ) ( long ) V_195 -> V_174 ;
T_2 V_19 = 0 ;
V_92 = F_142 ( V_193 , V_195 , & V_19 , false ) ;
if ( V_92 )
return V_92 ;
V_92 = F_148 ( V_19 , V_206 ) ;
break;
}
case V_208 : {
T_2 T_7 * V_206 = ( T_2 T_7 * ) ( long ) V_195 -> V_174 ;
V_92 = F_148 ( V_193 -> V_26 -> V_27 . V_28 . V_4 , V_206 ) ;
break;
}
}
return V_92 ;
}
static int F_149 ( const struct V_90 * V_91 ,
T_3 V_16 )
{
struct V_41 V_210 ;
V_210 . V_48 = 4 ;
if ( F_73 ( V_91 , & V_210 , V_16 ) )
return 0 ;
else
return - V_159 ;
}
static int F_150 ( struct V_192 * V_193 , struct V_194 * V_195 )
{
T_3 V_16 ;
switch ( V_195 -> V_200 ) {
case V_205 :
switch ( V_195 -> V_195 ) {
case V_179 :
case V_180 :
return 0 ;
}
break;
case V_201 :
V_16 = V_195 -> V_195 & V_197 ;
return F_149 ( V_102 , V_16 ) ;
case V_202 :
V_16 = V_195 -> V_195 & V_197 ;
return F_149 ( V_203 , V_16 ) ;
case V_208 :
return 0 ;
}
return - V_159 ;
}
static void F_151 ( struct V_192 * V_193 )
{
F_5 ( V_193 ) ;
}
static int F_152 ( struct V_192 * V_193 , T_2 type )
{
return F_132 ( V_193 -> V_26 ) ;
}
static void F_153 ( void * V_211 )
{
F_154 ( V_28 -> V_212 , 0 ) ;
}
static int F_155 ( struct V_213 * V_214 ,
unsigned long V_215 , void * V_172 )
{
switch ( V_215 ) {
case V_216 :
case V_217 :
F_153 ( NULL ) ;
break;
case V_218 :
case V_219 :
F_156 ( V_28 -> V_212 ) ;
break;
}
return V_220 ;
}
int F_157 ( void )
{
const struct V_221 * V_222 ;
const int (* F_158)( struct V_223 * , const struct V_114 * * ,
const struct V_224 * * );
struct V_223 * V_225 ;
int V_151 ;
V_225 = F_159 ( NULL ,
V_226 , & V_222 ) ;
if ( ! V_225 ) {
F_127 ( L_14 ) ;
return - V_181 ;
}
F_158 = V_222 -> V_44 ;
V_151 = F_158 ( V_225 , & V_114 , & V_28 ) ;
if ( V_151 )
return V_151 ;
V_151 = F_160 ( V_28 -> V_212 , F_122 ,
L_15 , F_161 () ) ;
if ( V_151 ) {
F_127 ( L_16 , V_28 -> V_212 ) ;
return V_151 ;
}
V_151 = F_162 ( & V_227 ) ;
if ( V_151 ) {
F_127 ( L_17 ) ;
goto V_228;
}
F_163 ( V_28 ) ;
F_164 ( F_153 , NULL , 1 ) ;
return F_165 ( & V_229 ,
V_230 ) ;
V_228:
F_166 ( V_28 -> V_212 , F_161 () ) ;
return V_151 ;
}

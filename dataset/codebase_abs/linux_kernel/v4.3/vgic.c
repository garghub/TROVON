static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
V_2 -> V_5 -> V_6 . V_7 . V_8 . F_1 ( V_2 , V_3 , V_4 ) ;
}
static bool F_2 ( struct V_1 * V_2 , int V_3 )
{
return V_2 -> V_5 -> V_6 . V_7 . V_8 . F_2 ( V_2 , V_3 ) ;
}
int F_3 ( struct V_5 * V_5 )
{
return V_5 -> V_6 . V_7 . V_8 . V_9 ( V_5 , V_7 ) ;
}
static int F_4 ( struct V_10 * V_11 , int V_12 , int V_13 )
{
int V_14 ;
V_14 = V_12 + F_5 ( V_13 - V_15 ) ;
V_11 -> V_16 = F_6 ( sizeof( unsigned long ) * V_14 , V_17 ) ;
if ( ! V_11 -> V_16 )
return - V_18 ;
V_11 -> V_19 = V_11 -> V_16 + V_12 ;
return 0 ;
}
static void F_7 ( struct V_10 * V_11 )
{
F_8 ( V_11 -> V_16 ) ;
V_11 -> V_16 = NULL ;
V_11 -> V_19 = NULL ;
}
static unsigned long * F_9 ( T_1 * V_20 )
{
#if F_10 ( V_21 ) && V_22 == 32
* V_20 = ( * V_20 >> 32 ) | ( * V_20 << 32 ) ;
#endif
return ( unsigned long * ) V_20 ;
}
T_2 * F_11 ( struct V_10 * V_23 , int V_24 , T_2 V_25 )
{
V_25 >>= 2 ;
if ( ! V_25 )
return ( T_2 * ) ( V_23 -> V_16 + V_24 ) + V_26 ;
else
return ( T_2 * ) ( V_23 -> V_19 ) + ( ( V_25 - 1 ) ^ V_26 ) ;
}
static int F_12 ( struct V_10 * V_23 ,
int V_24 , int V_3 )
{
if ( V_3 < V_15 )
return F_13 ( V_3 , V_23 -> V_16 + V_24 ) ;
return F_13 ( V_3 - V_15 , V_23 -> V_19 ) ;
}
void F_14 ( struct V_10 * V_23 , int V_24 ,
int V_3 , int V_20 )
{
unsigned long * V_27 ;
if ( V_3 < V_15 ) {
V_27 = V_23 -> V_16 + V_24 ;
} else {
V_27 = V_23 -> V_19 ;
V_3 -= V_15 ;
}
if ( V_20 )
F_15 ( V_3 , V_27 ) ;
else
F_16 ( V_3 , V_27 ) ;
}
static unsigned long * F_17 ( struct V_10 * V_23 , int V_24 )
{
return V_23 -> V_16 + V_24 ;
}
unsigned long * F_18 ( struct V_10 * V_23 )
{
return V_23 -> V_19 ;
}
static int F_19 ( struct V_28 * V_23 , int V_12 , int V_13 )
{
int V_29 ;
V_29 = V_12 * V_15 ;
V_29 += V_13 - V_15 ;
V_23 -> V_16 = F_6 ( V_29 , V_17 ) ;
if ( ! V_23 -> V_16 )
return - V_18 ;
V_23 -> V_19 = V_23 -> V_16 + V_12 * V_15 / sizeof( T_2 ) ;
return 0 ;
}
static void F_20 ( struct V_28 * V_11 )
{
F_8 ( V_11 -> V_16 ) ;
V_11 -> V_16 = NULL ;
V_11 -> V_19 = NULL ;
}
T_2 * F_21 ( struct V_28 * V_23 , int V_24 , T_2 V_25 )
{
T_2 * V_27 ;
if ( V_25 < V_15 ) {
V_27 = V_23 -> V_16 ;
V_25 += V_24 * V_15 ;
} else {
V_27 = V_23 -> V_19 ;
V_25 -= V_15 ;
}
return V_27 + ( V_25 / sizeof( T_2 ) ) ;
}
static bool F_22 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
int V_32 ;
V_32 = F_12 ( & V_31 -> V_33 , V_2 -> V_34 , V_3 ) ;
return V_32 == V_35 ;
}
static int F_23 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
return F_12 ( & V_31 -> V_36 , V_2 -> V_34 , V_3 ) ;
}
static int F_24 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
return F_12 ( & V_31 -> V_37 , V_2 -> V_34 , V_3 ) ;
}
static int F_25 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
return F_12 ( & V_31 -> V_38 , V_2 -> V_34 , V_3 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
F_14 ( & V_31 -> V_37 , V_2 -> V_34 , V_3 , 1 ) ;
}
static void F_27 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
F_14 ( & V_31 -> V_37 , V_2 -> V_34 , V_3 , 0 ) ;
}
static void F_28 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
F_14 ( & V_31 -> V_38 , V_2 -> V_34 , V_3 , 1 ) ;
}
static void F_29 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
F_14 ( & V_31 -> V_38 , V_2 -> V_34 , V_3 , 0 ) ;
}
static int F_30 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
return F_12 ( & V_31 -> V_39 , V_2 -> V_34 , V_3 ) ;
}
static void F_31 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
F_14 ( & V_31 -> V_39 , V_2 -> V_34 , V_3 , 1 ) ;
}
static void F_32 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
F_14 ( & V_31 -> V_39 , V_2 -> V_34 , V_3 , 0 ) ;
}
static int F_33 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
return F_12 ( & V_31 -> V_40 , V_2 -> V_34 , V_3 ) ;
}
static void F_34 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
F_14 ( & V_31 -> V_40 , V_2 -> V_34 , V_3 , 0 ) ;
}
static int F_35 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
return F_12 ( & V_31 -> V_41 , V_2 -> V_34 , V_3 ) ;
}
void F_36 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
F_14 ( & V_31 -> V_41 , V_2 -> V_34 , V_3 , 1 ) ;
}
void F_37 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
F_14 ( & V_31 -> V_41 , V_2 -> V_34 , V_3 , 0 ) ;
}
static void F_38 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 < V_15 )
F_15 ( V_3 , V_2 -> V_6 . V_42 . V_43 ) ;
else
F_15 ( V_3 - V_15 ,
V_2 -> V_6 . V_42 . V_44 ) ;
}
void F_39 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 < V_15 )
F_16 ( V_3 , V_2 -> V_6 . V_42 . V_43 ) ;
else
F_16 ( V_3 - V_15 ,
V_2 -> V_6 . V_42 . V_44 ) ;
}
static bool F_40 ( struct V_1 * V_2 , int V_3 )
{
return ! F_24 ( V_2 , V_3 ) ;
}
void F_41 ( struct V_45 * V_46 , T_2 * V_27 ,
T_3 V_25 , int V_47 )
{
int V_48 = ( V_25 & 3 ) * 8 ;
T_2 V_49 = ( 1UL << ( V_46 -> V_50 * 8 ) ) - 1 ;
T_2 V_51 ;
if ( V_27 ) {
V_51 = * V_27 ;
} else {
F_42 ( V_47 != ( V_52 | V_53 ) ) ;
V_51 = 0 ;
}
if ( V_46 -> V_54 ) {
T_2 V_55 = F_43 ( V_46 , V_49 ) << V_48 ;
switch ( F_44 ( V_47 ) ) {
case V_53 :
return;
case V_56 :
V_51 |= V_55 ;
break;
case V_57 :
V_51 &= ~ V_55 ;
break;
case V_58 :
V_51 = ( V_51 & ~ ( V_49 << V_48 ) ) | V_55 ;
break;
}
* V_27 = V_51 ;
} else {
switch ( F_45 ( V_47 ) ) {
case V_52 :
V_51 = 0 ;
case V_59 :
F_46 ( V_46 , V_49 , V_51 >> V_48 ) ;
}
}
}
bool F_47 ( struct V_1 * V_2 , struct V_45 * V_46 ,
T_3 V_25 )
{
F_41 ( V_46 , NULL , V_25 ,
V_52 | V_53 ) ;
return false ;
}
bool F_48 ( struct V_5 * V_5 , struct V_45 * V_46 ,
T_3 V_25 , int V_34 , int V_60 )
{
T_2 * V_27 ;
int V_47 = V_59 | V_60 ;
struct V_1 * V_61 = F_49 ( V_5 , V_34 ) ;
V_27 = F_11 ( & V_5 -> V_6 . V_7 . V_36 , V_34 , V_25 ) ;
F_41 ( V_46 , V_27 , V_25 , V_47 ) ;
if ( V_46 -> V_54 ) {
if ( V_60 & V_57 ) {
if ( V_25 < 4 )
* V_27 |= 0xffff ;
F_50 ( V_61 ) ;
}
F_51 ( V_5 ) ;
return true ;
}
return false ;
}
bool F_52 ( struct V_5 * V_5 ,
struct V_45 * V_46 ,
T_3 V_25 , int V_34 )
{
T_2 * V_27 , V_62 ;
T_2 V_63 ;
int V_47 = V_59 | V_56 ;
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
V_27 = F_11 ( & V_31 -> V_33 , V_34 , V_25 ) ;
V_63 = ( ~ ( * V_27 ) ) ;
V_27 = F_11 ( & V_31 -> V_41 , V_34 , V_25 ) ;
V_62 = * V_27 ;
F_41 ( V_46 , V_27 , V_25 , V_47 ) ;
if ( V_46 -> V_54 ) {
V_27 = F_11 ( & V_31 -> V_40 ,
V_34 , V_25 ) ;
F_41 ( V_46 , V_27 , V_25 , V_47 ) ;
* V_27 &= V_63 ;
if ( V_25 < 2 ) {
* V_27 &= ~ 0xffff ;
* V_27 |= V_62 & 0xffff ;
}
F_51 ( V_5 ) ;
return true ;
}
return false ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_42 * V_42 = & V_2 -> V_6 . V_42 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
F_54 () ;
V_65 = & V_42 -> V_70 ;
F_55 (entry, root, entry) {
V_69 = & V_67 -> V_69 ;
if ( ! F_35 ( V_2 , V_69 -> V_71 ) &&
! F_25 ( V_2 , V_69 -> V_71 ) )
V_69 -> V_72 = false ;
}
F_56 () ;
}
bool F_57 ( struct V_5 * V_5 ,
struct V_45 * V_46 ,
T_3 V_25 , int V_34 )
{
T_2 * V_73 ;
T_2 * V_27 , V_62 ;
int V_47 = V_59 | V_57 ;
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
V_27 = F_11 ( & V_31 -> V_41 , V_34 , V_25 ) ;
V_62 = * V_27 ;
F_41 ( V_46 , V_27 , V_25 , V_47 ) ;
if ( V_46 -> V_54 ) {
V_73 = F_11 ( & V_31 -> V_39 ,
V_34 , V_25 ) ;
V_27 = F_11 ( & V_31 -> V_41 , V_34 , V_25 ) ;
* V_27 |= * V_73 ;
if ( V_25 < 2 ) {
* V_27 &= ~ 0xffff ;
* V_27 |= V_62 & 0xffff ;
}
V_27 = F_11 ( & V_31 -> V_40 ,
V_34 , V_25 ) ;
F_41 ( V_46 , V_27 , V_25 , V_47 ) ;
F_53 ( F_49 ( V_5 , V_34 ) ) ;
F_51 ( V_5 ) ;
return true ;
}
return false ;
}
bool F_58 ( struct V_5 * V_5 ,
struct V_45 * V_46 ,
T_3 V_25 , int V_34 )
{
T_2 * V_27 ;
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
V_27 = F_11 ( & V_31 -> V_38 , V_34 , V_25 ) ;
F_41 ( V_46 , V_27 , V_25 ,
V_59 | V_56 ) ;
if ( V_46 -> V_54 ) {
F_51 ( V_5 ) ;
return true ;
}
return false ;
}
bool F_59 ( struct V_5 * V_5 ,
struct V_45 * V_46 ,
T_3 V_25 , int V_34 )
{
T_2 * V_27 ;
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
V_27 = F_11 ( & V_31 -> V_38 , V_34 , V_25 ) ;
F_41 ( V_46 , V_27 , V_25 ,
V_59 | V_57 ) ;
if ( V_46 -> V_54 ) {
F_53 ( F_49 ( V_5 , V_34 ) ) ;
F_51 ( V_5 ) ;
return true ;
}
return false ;
}
static T_2 F_60 ( T_4 V_20 )
{
T_2 V_74 = 0 ;
int V_75 ;
for ( V_75 = 0 ; V_75 < 16 ; V_75 ++ )
V_74 |= ( ( V_20 >> V_75 ) & V_35 ) << ( 2 * V_75 + 1 ) ;
return V_74 ;
}
static T_4 F_61 ( T_2 V_20 )
{
T_4 V_74 = 0 ;
int V_75 ;
for ( V_75 = 0 ; V_75 < 16 ; V_75 ++ )
V_74 |= ( ( V_20 >> ( V_75 * 2 + 1 ) ) & V_35 ) << V_75 ;
return V_74 ;
}
bool F_62 ( T_2 * V_27 , struct V_45 * V_46 ,
T_3 V_25 )
{
T_2 V_20 ;
if ( V_25 & 4 )
V_20 = * V_27 >> 16 ;
else
V_20 = * V_27 & 0xffff ;
V_20 = F_60 ( V_20 ) ;
F_41 ( V_46 , & V_20 , V_25 ,
V_59 | V_58 ) ;
if ( V_46 -> V_54 ) {
if ( V_25 < 8 ) {
* V_27 = ~ 0U ;
return false ;
}
V_20 = F_61 ( V_20 ) ;
if ( V_25 & 4 ) {
* V_27 &= 0xffff ;
* V_27 |= V_20 << 16 ;
} else {
* V_27 &= 0xffff << 16 ;
* V_27 |= V_20 ;
}
}
return false ;
}
void F_63 ( struct V_1 * V_2 )
{
struct V_42 * V_42 = & V_2 -> V_6 . V_42 ;
int V_75 ;
F_64 (i, vgic_cpu->lr_used, vgic_cpu->nr_lr) {
struct V_76 V_77 = F_65 ( V_2 , V_75 ) ;
F_42 ( ! ( V_77 . V_78 & V_79 ) ) ;
if ( V_77 . V_3 < V_80 )
F_1 ( V_2 , V_77 . V_3 , V_77 . V_4 ) ;
if ( V_77 . V_78 & V_81 ) {
F_28 ( V_2 , V_77 . V_3 ) ;
V_77 . V_78 &= ~ V_81 ;
}
if ( V_77 . V_78 & V_82 ) {
F_36 ( V_2 , V_77 . V_3 ) ;
V_77 . V_78 &= ~ V_82 ;
}
F_66 ( V_2 , V_75 , V_77 ) ;
F_42 ( V_77 . V_78 & V_79 ) ;
F_67 ( V_75 , V_77 . V_3 , V_2 ) ;
F_27 ( V_2 , V_77 . V_3 ) ;
F_51 ( V_2 -> V_5 ) ;
}
}
const
struct V_83 * F_68 ( const struct V_83 * V_84 ,
int V_50 , T_5 V_25 )
{
while ( V_84 -> V_50 ) {
if ( V_25 >= V_84 -> V_85 &&
( V_25 + V_50 ) <= ( V_84 -> V_85 + V_84 -> V_50 ) )
return V_84 ;
V_84 ++ ;
}
return NULL ;
}
static bool F_69 ( const struct V_30 * V_31 ,
const struct V_83 * V_86 ,
unsigned long V_25 )
{
int V_3 ;
if ( ! V_86 -> V_87 )
return true ;
V_3 = V_25 * 8 / V_86 -> V_87 ;
if ( V_3 >= V_31 -> V_13 )
return false ;
return true ;
}
static bool F_70 ( struct V_1 * V_2 ,
struct V_45 * V_46 ,
unsigned long V_25 ,
const struct V_83 * V_86 )
{
struct V_45 V_88 ;
bool V_89 ;
if ( F_71 ( V_46 -> V_50 <= 4 ) )
return V_86 -> V_90 ( V_2 , V_46 , V_25 ) ;
V_88 . V_50 = 4 ;
V_88 . V_54 = V_46 -> V_54 ;
V_88 . V_16 = V_46 -> V_16 ;
V_88 . V_91 = V_46 -> V_91 + 4 ;
V_88 . V_55 = & ( ( T_2 * ) V_46 -> V_55 ) [ 1 ] ;
V_89 = V_86 -> V_90 ( V_2 , & V_88 , V_25 + 4 ) ;
V_88 . V_91 = V_46 -> V_91 ;
V_88 . V_55 = & ( ( T_2 * ) V_46 -> V_55 ) [ 0 ] ;
V_89 |= V_86 -> V_90 ( V_2 , & V_88 , V_25 ) ;
return V_89 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_92 * V_93 , T_5 V_94 ,
int V_50 , void * V_20 , bool V_54 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
struct V_95 * V_96 = F_73 ( V_93 ,
struct V_95 , V_97 ) ;
struct V_98 * V_99 = V_2 -> V_99 ;
const struct V_83 * V_86 ;
struct V_45 V_46 ;
bool V_100 ;
T_5 V_25 ;
V_25 = V_94 - V_96 -> V_94 ;
V_86 = F_68 ( V_96 -> V_101 , V_50 , V_25 ) ;
if ( F_74 ( ! V_86 || ! V_86 -> V_90 ) ) {
F_75 ( L_1 , V_54 , V_94 , V_50 ) ;
return - V_102 ;
}
V_46 . V_91 = V_94 ;
V_46 . V_50 = V_50 ;
V_46 . V_54 = V_54 ;
V_46 . V_55 = V_20 ;
V_46 . V_16 = V_96 -> V_103 ;
F_76 ( & V_31 -> V_104 ) ;
V_25 -= V_86 -> V_85 ;
if ( F_69 ( V_31 , V_86 , V_25 ) ) {
V_100 = F_70 ( V_2 , & V_46 , V_25 , V_86 ) ;
} else {
if ( ! V_54 )
memset ( V_20 , 0 , V_50 ) ;
V_100 = false ;
}
F_77 ( & V_31 -> V_104 ) ;
V_99 -> V_46 . V_54 = V_54 ;
V_99 -> V_46 . V_50 = V_50 ;
V_99 -> V_46 . V_91 = V_94 ;
memcpy ( V_99 -> V_46 . V_55 , V_20 , V_50 ) ;
F_78 ( V_2 , V_99 ) ;
if ( V_100 )
F_79 ( V_2 -> V_5 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
T_5 V_94 , int V_50 , void * V_20 )
{
return F_72 ( V_2 , V_93 , V_94 , V_50 , V_20 , false ) ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
T_5 V_94 , int V_50 , const void * V_20 )
{
return F_72 ( V_2 , V_93 , V_94 , V_50 , ( void * ) V_20 ,
true ) ;
}
int F_82 ( struct V_5 * V_5 , T_5 V_85 , int V_50 ,
const struct V_83 * V_84 ,
int V_105 ,
struct V_95 * V_96 )
{
struct V_1 * V_2 = NULL ;
int V_89 ;
if ( V_105 >= 0 )
V_2 = F_49 ( V_5 , V_105 ) ;
V_96 -> V_94 = V_85 ;
V_96 -> V_50 = V_50 ;
V_96 -> V_101 = V_84 ;
V_96 -> V_103 = V_2 ;
F_83 ( & V_96 -> V_97 , & V_106 ) ;
F_84 ( & V_5 -> V_107 ) ;
V_89 = F_85 ( V_5 , V_108 , V_85 , V_50 ,
& V_96 -> V_97 ) ;
F_86 ( & V_5 -> V_107 ) ;
if ( V_89 )
V_96 -> V_97 . V_109 = NULL ;
return V_89 ;
}
static int F_87 ( struct V_30 * V_31 )
{
return V_31 -> V_13 - V_15 ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
unsigned long * V_72 , * V_110 , * V_111 , * V_112 ;
unsigned long V_113 , V_114 ;
int V_115 = F_87 ( V_31 ) ;
int V_34 ;
V_34 = V_2 -> V_34 ;
V_111 = V_2 -> V_6 . V_42 . V_116 ;
V_112 = V_2 -> V_6 . V_42 . V_114 ;
V_72 = F_17 ( & V_31 -> V_38 , V_34 ) ;
V_110 = F_17 ( & V_31 -> V_36 , V_34 ) ;
F_89 ( V_111 , V_72 , V_110 , V_15 ) ;
V_72 = F_18 ( & V_31 -> V_38 ) ;
V_110 = F_18 ( & V_31 -> V_36 ) ;
F_89 ( V_112 , V_72 , V_110 , V_115 ) ;
F_89 ( V_112 , V_112 ,
F_18 ( & V_31 -> V_117 [ V_34 ] ) ,
V_115 ) ;
V_113 = F_90 ( V_111 , V_15 ) ;
V_114 = F_90 ( V_112 , V_115 ) ;
return ( V_113 < V_15 ||
V_114 < V_115 ) ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
unsigned long * V_118 , * V_110 , * V_119 , * V_120 ;
unsigned long V_121 , V_44 ;
int V_115 = F_87 ( V_31 ) ;
int V_34 ;
V_34 = V_2 -> V_34 ;
V_119 = V_2 -> V_6 . V_42 . V_43 ;
V_120 = V_2 -> V_6 . V_42 . V_44 ;
if ( ! V_31 -> V_110 ) {
F_92 ( V_119 , V_15 ) ;
F_92 ( V_120 , V_115 ) ;
return 0 ;
}
V_118 = F_17 ( & V_31 -> V_41 , V_34 ) ;
V_110 = F_17 ( & V_31 -> V_36 , V_34 ) ;
F_89 ( V_119 , V_118 , V_110 , V_15 ) ;
V_118 = F_18 ( & V_31 -> V_41 ) ;
V_110 = F_18 ( & V_31 -> V_36 ) ;
F_89 ( V_120 , V_118 , V_110 , V_115 ) ;
F_89 ( V_120 , V_120 ,
F_18 ( & V_31 -> V_117 [ V_34 ] ) ,
V_115 ) ;
V_121 = F_90 ( V_119 , V_15 ) ;
V_44 = F_90 ( V_120 , V_115 ) ;
return ( V_121 < V_15 ||
V_44 < F_87 ( V_31 ) ) ;
}
void F_51 ( struct V_5 * V_5 )
{
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
struct V_1 * V_2 ;
int V_122 ;
F_93 (c, vcpu, kvm) {
if ( F_91 ( V_2 ) )
F_15 ( V_122 , V_31 -> V_123 ) ;
if ( F_88 ( V_2 ) )
F_15 ( V_122 , V_31 -> V_124 ) ;
else
F_16 ( V_122 , V_31 -> V_124 ) ;
}
}
static struct V_76 F_65 ( const struct V_1 * V_2 , int V_77 )
{
return V_125 -> V_126 ( V_2 , V_77 ) ;
}
static void F_66 ( struct V_1 * V_2 , int V_77 ,
struct V_76 V_127 )
{
V_125 -> V_128 ( V_2 , V_77 , V_127 ) ;
}
static void F_94 ( struct V_1 * V_2 , int V_77 ,
struct V_76 V_127 )
{
V_125 -> V_129 ( V_2 , V_77 , V_127 ) ;
}
static inline T_1 F_95 ( struct V_1 * V_2 )
{
return V_125 -> V_130 ( V_2 ) ;
}
static inline T_1 F_96 ( struct V_1 * V_2 )
{
return V_125 -> V_131 ( V_2 ) ;
}
static inline void F_97 ( struct V_1 * V_2 )
{
V_125 -> V_132 ( V_2 ) ;
}
static inline T_2 F_98 ( struct V_1 * V_2 )
{
return V_125 -> V_133 ( V_2 ) ;
}
static inline void F_99 ( struct V_1 * V_2 )
{
V_125 -> V_134 ( V_2 ) ;
}
static inline void F_100 ( struct V_1 * V_2 )
{
V_125 -> V_135 ( V_2 ) ;
}
void F_101 ( struct V_1 * V_2 , struct V_136 * V_137 )
{
V_125 -> V_138 ( V_2 , V_137 ) ;
}
void F_102 ( struct V_1 * V_2 , struct V_136 * V_137 )
{
V_125 -> V_139 ( V_2 , V_137 ) ;
}
static inline void F_103 ( struct V_1 * V_2 )
{
V_125 -> V_140 ( V_2 ) ;
}
static void F_67 ( int V_141 , int V_3 , struct V_1 * V_2 )
{
struct V_42 * V_42 = & V_2 -> V_6 . V_42 ;
struct V_76 V_127 = F_65 ( V_2 , V_141 ) ;
if ( V_127 . V_78 & V_82 ) {
F_36 ( V_2 , V_3 ) ;
V_127 . V_142 = 0 ;
}
V_127 . V_78 = 0 ;
F_66 ( V_2 , V_141 , V_127 ) ;
F_16 ( V_141 , V_42 -> V_143 ) ;
V_42 -> V_144 [ V_3 ] = V_145 ;
F_94 ( V_2 , V_141 , V_127 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_42 * V_42 = & V_2 -> V_6 . V_42 ;
int V_77 ;
F_64 (lr, vgic_cpu->lr_used, vgic->nr_lr) {
struct V_76 V_127 = F_65 ( V_2 , V_77 ) ;
if ( ! F_23 ( V_2 , V_127 . V_3 ) ) {
F_67 ( V_77 , V_127 . V_3 , V_2 ) ;
if ( F_24 ( V_2 , V_127 . V_3 ) )
F_27 ( V_2 , V_127 . V_3 ) ;
}
}
}
static void F_104 ( struct V_1 * V_2 , int V_3 ,
int V_141 , struct V_76 V_127 )
{
if ( F_25 ( V_2 , V_3 ) ) {
V_127 . V_78 |= V_81 ;
F_105 ( L_2 , V_127 . V_78 ) ;
F_29 ( V_2 , V_3 ) ;
F_51 ( V_2 -> V_5 ) ;
} else {
F_106 ( ! F_35 ( V_2 , V_3 ) ) ;
V_127 . V_78 |= V_82 ;
F_105 ( L_3 , V_127 . V_78 ) ;
}
if ( ! F_22 ( V_2 , V_3 ) )
V_127 . V_78 |= V_146 ;
if ( V_127 . V_3 >= V_80 ) {
struct V_68 * V_69 ;
V_69 = F_107 ( V_2 , V_3 ) ;
if ( V_69 ) {
V_127 . V_142 = V_69 -> V_147 ;
V_127 . V_78 |= V_148 ;
V_127 . V_78 &= ~ V_146 ;
F_26 ( V_2 , V_3 ) ;
}
}
F_66 ( V_2 , V_141 , V_127 ) ;
F_94 ( V_2 , V_141 , V_127 ) ;
}
bool F_108 ( struct V_1 * V_2 , T_6 V_149 , int V_3 )
{
struct V_42 * V_42 = & V_2 -> V_6 . V_42 ;
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
struct V_76 V_127 ;
int V_77 ;
F_42 ( V_149 & ~ 7 ) ;
F_42 ( V_149 && V_3 >= V_80 ) ;
F_42 ( V_3 >= V_31 -> V_13 ) ;
F_105 ( L_4 , V_3 ) ;
V_77 = V_42 -> V_144 [ V_3 ] ;
if ( V_77 != V_145 ) {
V_127 = F_65 ( V_2 , V_77 ) ;
if ( V_127 . V_4 == V_149 ) {
F_105 ( L_5 , V_77 , V_127 . V_3 ) ;
F_42 ( ! F_13 ( V_77 , V_42 -> V_143 ) ) ;
F_104 ( V_2 , V_3 , V_77 , V_127 ) ;
return true ;
}
}
V_77 = F_109 ( ( unsigned long * ) V_42 -> V_143 ,
V_7 -> V_150 ) ;
if ( V_77 >= V_7 -> V_150 )
return false ;
F_105 ( L_6 , V_77 , V_3 , V_149 ) ;
V_42 -> V_144 [ V_3 ] = V_77 ;
F_15 ( V_77 , V_42 -> V_143 ) ;
V_127 . V_3 = V_3 ;
V_127 . V_4 = V_149 ;
V_127 . V_78 = 0 ;
F_104 ( V_2 , V_3 , V_77 , V_127 ) ;
return true ;
}
static bool F_110 ( struct V_1 * V_2 , int V_3 )
{
if ( ! F_40 ( V_2 , V_3 ) )
return true ;
if ( F_108 ( V_2 , 0 , V_3 ) ) {
if ( F_22 ( V_2 , V_3 ) ) {
F_37 ( V_2 , V_3 ) ;
F_39 ( V_2 , V_3 ) ;
} else {
F_26 ( V_2 , V_3 ) ;
}
return true ;
}
return false ;
}
static void F_111 ( struct V_1 * V_2 )
{
struct V_42 * V_42 = & V_2 -> V_6 . V_42 ;
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
unsigned long * V_151 , * V_152 ;
int V_75 , V_34 ;
int V_153 = 0 ;
int V_115 = F_87 ( V_31 ) ;
V_34 = V_2 -> V_34 ;
V_151 = V_2 -> V_6 . V_42 . V_154 ;
V_152 = V_2 -> V_6 . V_42 . V_155 ;
F_112 ( V_151 , V_42 -> V_43 , V_42 -> V_116 ,
V_15 ) ;
F_112 ( V_152 , V_42 -> V_44 , V_42 -> V_114 ,
V_115 ) ;
if ( ! F_113 ( V_2 ) && ! F_114 ( V_2 ) )
goto V_156;
F_64 (i, pa_percpu, VGIC_NR_SGIS) {
if ( ! F_2 ( V_2 , V_75 ) )
V_153 = 1 ;
}
F_115 (i, pa_percpu, VGIC_NR_PRIVATE_IRQS) {
if ( ! F_110 ( V_2 , V_75 ) )
V_153 = 1 ;
}
F_64 (i, pa_shared, nr_shared) {
if ( ! F_110 ( V_2 , V_75 + V_15 ) )
V_153 = 1 ;
}
V_156:
if ( V_153 ) {
F_99 ( V_2 ) ;
} else {
F_100 ( V_2 ) ;
F_16 ( V_34 , V_31 -> V_123 ) ;
}
}
static bool F_116 ( struct V_1 * V_2 )
{
T_2 V_157 = F_98 ( V_2 ) ;
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
bool V_158 = false ;
struct V_5 * V_5 = V_2 -> V_5 ;
F_105 ( L_7 , V_157 ) ;
if ( V_157 & V_159 ) {
T_1 V_160 = F_96 ( V_2 ) ;
unsigned long * V_161 = F_9 ( & V_160 ) ;
int V_77 ;
F_64 (lr, eisr_ptr, vgic->nr_lr) {
struct V_76 V_127 = F_65 ( V_2 , V_77 ) ;
F_106 ( F_22 ( V_2 , V_127 . V_3 ) ) ;
F_76 ( & V_31 -> V_104 ) ;
F_27 ( V_2 , V_127 . V_3 ) ;
F_106 ( V_127 . V_78 & V_79 ) ;
V_127 . V_78 = 0 ;
F_66 ( V_2 , V_77 , V_127 ) ;
F_34 ( V_2 , V_127 . V_3 ) ;
F_77 ( & V_31 -> V_104 ) ;
F_117 ( V_5 , 0 ,
V_127 . V_3 - V_15 ) ;
F_76 ( & V_31 -> V_104 ) ;
if ( F_30 ( V_2 , V_127 . V_3 ) ) {
F_38 ( V_2 , V_127 . V_3 ) ;
V_158 = true ;
} else {
F_37 ( V_2 , V_127 . V_3 ) ;
F_39 ( V_2 , V_127 . V_3 ) ;
}
F_77 ( & V_31 -> V_104 ) ;
F_94 ( V_2 , V_77 , V_127 ) ;
}
}
if ( V_157 & V_162 )
F_100 ( V_2 ) ;
F_97 ( V_2 ) ;
return V_158 ;
}
static int F_118 ( struct V_1 * V_2 , struct V_76 V_127 )
{
struct V_68 * V_69 ;
int V_89 ;
if ( ! ( V_127 . V_78 & V_148 ) )
return 0 ;
V_69 = F_107 ( V_2 , V_127 . V_3 ) ;
F_42 ( ! V_69 ) ;
V_89 = F_119 ( V_69 -> V_3 ,
V_163 ,
& V_69 -> V_72 ) ;
F_106 ( V_89 ) ;
if ( V_69 -> V_72 )
return 0 ;
return 1 ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_42 * V_42 = & V_2 -> V_6 . V_42 ;
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
T_1 V_164 ;
unsigned long * V_165 ;
int V_77 , V_118 ;
bool V_158 ;
V_158 = F_116 ( V_2 ) ;
V_164 = F_95 ( V_2 ) ;
V_165 = F_9 ( & V_164 ) ;
for ( V_77 = 0 ; V_77 < V_7 -> V_150 ; V_77 ++ ) {
struct V_76 V_127 ;
if ( ! F_13 ( V_77 , V_42 -> V_143 ) )
continue;
V_127 = F_65 ( V_2 , V_77 ) ;
if ( F_118 ( V_2 , V_127 ) ) {
V_127 . V_78 = 0 ;
V_127 . V_142 = 0 ;
F_66 ( V_2 , V_77 , V_127 ) ;
F_27 ( V_2 , V_127 . V_3 ) ;
F_15 ( V_77 , V_165 ) ;
}
if ( ! F_13 ( V_77 , V_165 ) )
continue;
F_16 ( V_77 , V_42 -> V_143 ) ;
F_42 ( V_127 . V_3 >= V_31 -> V_13 ) ;
V_42 -> V_144 [ V_127 . V_3 ] = V_145 ;
}
V_118 = F_109 ( V_165 , V_7 -> V_150 ) ;
if ( V_158 || V_118 < V_7 -> V_150 )
F_15 ( V_2 -> V_34 , V_31 -> V_123 ) ;
}
void F_121 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
if ( ! F_122 ( V_2 -> V_5 ) )
return;
F_76 ( & V_31 -> V_104 ) ;
F_111 ( V_2 ) ;
F_77 ( & V_31 -> V_104 ) ;
}
void F_123 ( struct V_1 * V_2 )
{
if ( ! F_122 ( V_2 -> V_5 ) )
return;
F_120 ( V_2 ) ;
}
int F_113 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
if ( ! F_122 ( V_2 -> V_5 ) )
return 0 ;
return F_13 ( V_2 -> V_34 , V_31 -> V_123 ) ;
}
int F_114 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
if ( ! F_122 ( V_2 -> V_5 ) )
return 0 ;
return F_13 ( V_2 -> V_34 , V_31 -> V_124 ) ;
}
void F_79 ( struct V_5 * V_5 )
{
struct V_1 * V_2 ;
int V_122 ;
F_93 (c, vcpu, kvm) {
if ( F_113 ( V_2 ) )
F_124 ( V_2 ) ;
}
}
static int F_125 ( struct V_1 * V_2 , int V_3 , int V_166 )
{
int V_167 = F_22 ( V_2 , V_3 ) ;
if ( V_167 ) {
int V_78 = F_35 ( V_2 , V_3 ) ;
return V_166 > V_78 ;
} else {
int V_78 = F_30 ( V_2 , V_3 ) ;
return V_166 != V_78 ;
}
}
static int F_126 ( struct V_5 * V_5 , int V_24 ,
struct V_68 * V_69 ,
unsigned int V_168 , bool V_166 )
{
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
struct V_1 * V_2 ;
int V_167 , V_169 ;
int V_110 ;
bool V_89 = true , V_170 = true ;
if ( V_168 >= F_127 ( V_5 -> V_6 . V_7 . V_13 , 1020 ) )
return - V_171 ;
F_76 ( & V_31 -> V_104 ) ;
V_2 = F_49 ( V_5 , V_24 ) ;
V_167 = F_22 ( V_2 , V_168 ) ;
V_169 = ! V_167 ;
if ( ! F_125 ( V_2 , V_168 , V_166 ) ) {
V_89 = false ;
goto V_172;
}
if ( V_168 >= V_15 ) {
V_24 = V_31 -> V_173 [ V_168 - V_15 ] ;
if ( V_24 == V_174 ) {
V_24 = 0 ;
V_170 = false ;
}
V_2 = F_49 ( V_5 , V_24 ) ;
}
F_105 ( L_8 , V_168 , V_166 , V_24 ) ;
if ( V_166 ) {
if ( V_169 )
F_31 ( V_2 , V_168 ) ;
F_36 ( V_2 , V_168 ) ;
} else {
if ( V_169 ) {
F_32 ( V_2 , V_168 ) ;
if ( ! F_33 ( V_2 , V_168 ) ) {
F_37 ( V_2 , V_168 ) ;
F_39 ( V_2 , V_168 ) ;
if ( ! F_91 ( V_2 ) )
F_16 ( V_24 , V_31 -> V_123 ) ;
}
}
V_89 = false ;
goto V_172;
}
V_110 = F_23 ( V_2 , V_168 ) ;
if ( ! V_110 || ! V_170 ) {
V_89 = false ;
goto V_172;
}
if ( ! F_40 ( V_2 , V_168 ) ) {
V_89 = false ;
goto V_172;
}
if ( V_166 ) {
F_38 ( V_2 , V_168 ) ;
F_15 ( V_24 , V_31 -> V_123 ) ;
}
V_172:
F_77 ( & V_31 -> V_104 ) ;
if ( V_89 ) {
F_124 ( F_49 ( V_5 , V_24 ) ) ;
}
return 0 ;
}
static int F_128 ( struct V_5 * V_5 )
{
int V_89 = 0 ;
if ( F_74 ( ! F_129 ( V_5 ) ) ) {
if ( V_5 -> V_6 . V_7 . V_175 != V_176 )
return - V_177 ;
F_84 ( & V_5 -> V_104 ) ;
V_89 = F_130 ( V_5 ) ;
F_86 ( & V_5 -> V_104 ) ;
}
return V_89 ;
}
int F_131 ( struct V_5 * V_5 , int V_24 , unsigned int V_168 ,
bool V_166 )
{
struct V_68 * V_69 ;
int V_89 ;
V_89 = F_128 ( V_5 ) ;
if ( V_89 )
return V_89 ;
V_69 = F_107 ( F_49 ( V_5 , V_24 ) , V_168 ) ;
if ( V_69 )
return - V_171 ;
return F_126 ( V_5 , V_24 , NULL , V_168 , V_166 ) ;
}
int F_132 ( struct V_5 * V_5 , int V_24 ,
struct V_68 * V_69 , bool V_166 )
{
int V_89 ;
V_89 = F_128 ( V_5 ) ;
if ( V_89 )
return V_89 ;
return F_126 ( V_5 , V_24 , V_69 , V_69 -> V_71 , V_166 ) ;
}
static T_7 F_133 ( int V_3 , void * V_55 )
{
return V_178 ;
}
static struct V_64 * F_134 ( struct V_1 * V_2 ,
int V_71 )
{
if ( V_71 < V_15 )
return & V_2 -> V_6 . V_42 . V_70 ;
else
return & V_2 -> V_5 -> V_6 . V_7 . V_70 ;
}
struct V_68 * F_135 ( struct V_1 * V_2 ,
int V_71 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
struct V_64 * V_65 = F_134 ( V_2 , V_71 ) ;
struct V_68 * V_69 ;
struct V_66 * V_67 ;
struct V_179 * V_180 ;
struct V_181 * V_55 ;
int V_147 ;
V_180 = F_136 ( V_3 ) ;
if ( ! V_180 ) {
F_137 ( L_9 , V_182 ) ;
return F_138 ( - V_171 ) ;
}
V_55 = F_139 ( V_180 ) ;
while ( V_55 -> V_183 )
V_55 = V_55 -> V_183 ;
V_147 = V_55 -> V_142 ;
V_67 = F_6 ( sizeof( * V_67 ) , V_17 ) ;
if ( ! V_67 )
return F_138 ( - V_18 ) ;
F_76 ( & V_31 -> V_184 ) ;
V_69 = F_107 ( V_2 , V_71 ) ;
if ( V_69 ) {
if ( V_69 -> V_147 != V_147 ||
V_69 -> V_3 != V_3 )
V_69 = F_138 ( - V_171 ) ;
goto V_172;
}
V_69 = & V_67 -> V_69 ;
V_69 -> V_71 = V_71 ;
V_69 -> V_147 = V_147 ;
V_69 -> V_3 = V_3 ;
F_140 ( & V_67 -> V_67 , V_65 ) ;
V_172:
F_77 ( & V_31 -> V_184 ) ;
if ( F_141 ( V_69 ) || V_69 != & V_67 -> V_69 )
F_8 ( V_67 ) ;
return V_69 ;
}
static struct V_68 * F_107 ( struct V_1 * V_2 ,
int V_71 )
{
struct V_64 * V_65 = F_134 ( V_2 , V_71 ) ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
F_54 () ;
F_55 (entry, root, entry) {
V_69 = & V_67 -> V_69 ;
if ( V_69 -> V_71 == V_71 ) {
F_56 () ;
return V_69 ;
}
}
F_56 () ;
return NULL ;
}
static void F_142 ( struct V_185 * V_186 )
{
struct V_66 * V_67 ;
V_67 = F_73 ( V_186 , struct V_66 , V_186 ) ;
F_8 ( V_67 ) ;
}
bool F_143 ( struct V_68 * V_69 )
{
F_42 ( ! V_69 ) ;
return V_69 -> V_72 ;
}
void F_144 ( struct V_68 * V_69 , bool V_72 )
{
F_42 ( ! V_69 ) ;
V_69 -> V_72 = V_72 ;
}
int F_145 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
struct V_66 * V_67 ;
struct V_64 * V_65 ;
if ( ! V_69 )
return - V_171 ;
V_65 = F_134 ( V_2 , V_69 -> V_71 ) ;
F_76 ( & V_31 -> V_184 ) ;
F_146 (entry, root, entry) {
if ( & V_67 -> V_69 == V_69 ) {
F_147 ( & V_67 -> V_67 ) ;
F_148 ( & V_67 -> V_186 , F_142 ) ;
break;
}
}
F_77 ( & V_31 -> V_184 ) ;
return 0 ;
}
static void F_149 ( struct V_5 * V_5 , struct V_64 * V_65 )
{
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
struct V_66 * V_67 ;
F_76 ( & V_31 -> V_184 ) ;
F_146 (entry, root, entry) {
F_147 ( & V_67 -> V_67 ) ;
F_148 ( & V_67 -> V_186 , F_142 ) ;
}
F_77 ( & V_31 -> V_184 ) ;
}
void F_150 ( struct V_1 * V_2 )
{
struct V_42 * V_42 = & V_2 -> V_6 . V_42 ;
F_8 ( V_42 -> V_44 ) ;
F_8 ( V_42 -> V_114 ) ;
F_8 ( V_42 -> V_155 ) ;
F_8 ( V_42 -> V_144 ) ;
F_149 ( V_2 -> V_5 , & V_42 -> V_70 ) ;
V_42 -> V_44 = NULL ;
V_42 -> V_114 = NULL ;
V_42 -> V_155 = NULL ;
V_42 -> V_144 = NULL ;
}
static int F_151 ( struct V_1 * V_2 , int V_13 )
{
struct V_42 * V_42 = & V_2 -> V_6 . V_42 ;
int V_187 = ( V_13 - V_15 ) / 8 ;
V_42 -> V_44 = F_6 ( V_187 , V_17 ) ;
V_42 -> V_114 = F_6 ( V_187 , V_17 ) ;
V_42 -> V_155 = F_6 ( V_187 , V_17 ) ;
V_42 -> V_144 = F_152 ( V_13 , V_17 ) ;
if ( ! V_42 -> V_44
|| ! V_42 -> V_114
|| ! V_42 -> V_155
|| ! V_42 -> V_144 ) {
F_150 ( V_2 ) ;
return - V_18 ;
}
memset ( V_42 -> V_144 , V_145 , V_13 ) ;
V_42 -> V_150 = V_7 -> V_150 ;
return 0 ;
}
void F_153 ( struct V_1 * V_2 )
{
struct V_42 * V_42 = & V_2 -> V_6 . V_42 ;
F_154 ( & V_42 -> V_70 ) ;
}
int F_155 ( void )
{
return V_7 -> V_188 ;
}
void F_156 ( struct V_5 * V_5 )
{
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
struct V_1 * V_2 ;
int V_75 ;
F_93 (i, vcpu, kvm)
F_150 ( V_2 ) ;
F_7 ( & V_31 -> V_36 ) ;
F_7 ( & V_31 -> V_39 ) ;
F_7 ( & V_31 -> V_41 ) ;
F_7 ( & V_31 -> V_40 ) ;
F_7 ( & V_31 -> V_37 ) ;
F_7 ( & V_31 -> V_33 ) ;
F_20 ( & V_31 -> V_189 ) ;
if ( V_31 -> V_117 ) {
for ( V_75 = 0 ; V_75 < V_31 -> V_12 ; V_75 ++ )
F_7 ( & V_31 -> V_117 [ V_75 ] ) ;
}
F_8 ( V_31 -> V_190 ) ;
F_8 ( V_31 -> V_173 ) ;
F_8 ( V_31 -> V_191 ) ;
F_8 ( V_31 -> V_117 ) ;
F_8 ( V_31 -> V_123 ) ;
F_8 ( V_31 -> V_124 ) ;
F_149 ( V_5 , & V_31 -> V_70 ) ;
V_31 -> V_190 = NULL ;
V_31 -> V_173 = NULL ;
V_31 -> V_117 = NULL ;
V_31 -> V_123 = NULL ;
V_31 -> V_124 = NULL ;
V_31 -> V_12 = 0 ;
}
int F_130 ( struct V_5 * V_5 )
{
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
struct V_1 * V_2 ;
int V_12 , V_13 ;
int V_89 , V_75 , V_34 ;
if ( F_129 ( V_5 ) )
return 0 ;
V_12 = V_31 -> V_12 = F_157 ( & V_5 -> V_192 ) ;
if ( ! V_12 )
return - V_193 ;
if ( ! V_31 -> V_13 )
V_31 -> V_13 = V_194 ;
V_13 = V_31 -> V_13 ;
V_89 = F_4 ( & V_31 -> V_36 , V_12 , V_13 ) ;
V_89 |= F_4 ( & V_31 -> V_39 , V_12 , V_13 ) ;
V_89 |= F_4 ( & V_31 -> V_41 , V_12 , V_13 ) ;
V_89 |= F_4 ( & V_31 -> V_40 , V_12 , V_13 ) ;
V_89 |= F_4 ( & V_31 -> V_37 , V_12 , V_13 ) ;
V_89 |= F_4 ( & V_31 -> V_38 , V_12 , V_13 ) ;
V_89 |= F_4 ( & V_31 -> V_33 , V_12 , V_13 ) ;
V_89 |= F_19 ( & V_31 -> V_189 , V_12 , V_13 ) ;
if ( V_89 )
goto V_172;
V_31 -> V_190 = F_6 ( V_12 * V_80 , V_17 ) ;
V_31 -> V_173 = F_6 ( V_13 - V_15 , V_17 ) ;
V_31 -> V_117 = F_6 ( sizeof( * V_31 -> V_117 ) * V_12 ,
V_17 ) ;
V_31 -> V_123 = F_6 ( F_5 ( V_12 ) * sizeof( long ) ,
V_17 ) ;
V_31 -> V_124 = F_6 ( F_5 ( V_12 ) * sizeof( long ) ,
V_17 ) ;
if ( ! V_31 -> V_190 ||
! V_31 -> V_173 ||
! V_31 -> V_117 ||
! V_31 -> V_123 ||
! V_31 -> V_124 ) {
V_89 = - V_18 ;
goto V_172;
}
for ( V_75 = 0 ; V_75 < V_12 ; V_75 ++ )
V_89 |= F_4 ( & V_31 -> V_117 [ V_75 ] ,
V_12 , V_13 ) ;
if ( V_89 )
goto V_172;
V_89 = V_5 -> V_6 . V_7 . V_8 . V_195 ( V_5 ) ;
if ( V_89 )
goto V_172;
F_93 (vcpu_id, vcpu, kvm) {
V_89 = F_151 ( V_2 , V_13 ) ;
if ( V_89 ) {
F_137 ( L_10 ) ;
break;
}
for ( V_75 = 0 ; V_75 < V_31 -> V_13 ; V_75 ++ ) {
if ( V_75 < V_196 )
F_14 ( & V_31 -> V_36 ,
V_2 -> V_34 , V_75 , 1 ) ;
if ( V_75 < V_15 )
F_14 ( & V_31 -> V_33 ,
V_2 -> V_34 , V_75 ,
V_35 ) ;
}
F_103 ( V_2 ) ;
}
V_172:
if ( V_89 )
F_156 ( V_5 ) ;
return V_89 ;
}
static int F_158 ( struct V_5 * V_5 , int type )
{
switch ( type ) {
case V_176 :
F_159 ( V_5 ) ;
break;
#ifdef F_160
case V_197 :
F_161 ( V_5 ) ;
break;
#endif
default:
return - V_193 ;
}
if ( F_157 ( & V_5 -> V_192 ) > V_5 -> V_6 . V_198 )
return - V_199 ;
return 0 ;
}
void F_162 ( struct V_5 * V_5 )
{
F_163 ( & V_5 -> V_6 . V_7 . V_104 ) ;
F_163 ( & V_5 -> V_6 . V_7 . V_184 ) ;
F_154 ( & V_5 -> V_6 . V_7 . V_70 ) ;
}
int F_164 ( struct V_5 * V_5 , T_2 type )
{
int V_75 , V_200 = - 1 , V_89 ;
struct V_1 * V_2 ;
F_84 ( & V_5 -> V_104 ) ;
if ( F_122 ( V_5 ) ) {
V_89 = - V_201 ;
goto V_172;
}
if ( type == V_176 && ! V_7 -> V_202 ) {
V_89 = - V_193 ;
goto V_172;
}
V_89 = - V_177 ;
F_93 (i, vcpu, kvm) {
if ( ! F_165 ( & V_2 -> V_203 ) )
goto V_204;
V_200 = V_75 ;
}
F_93 (i, vcpu, kvm) {
if ( V_2 -> V_6 . V_205 )
goto V_204;
}
V_89 = 0 ;
V_89 = F_158 ( V_5 , type ) ;
if ( V_89 )
goto V_204;
V_5 -> V_6 . V_7 . V_206 = true ;
V_5 -> V_6 . V_7 . V_175 = type ;
V_5 -> V_6 . V_7 . V_207 = V_7 -> V_207 ;
V_5 -> V_6 . V_7 . V_208 = V_209 ;
V_5 -> V_6 . V_7 . V_210 = V_209 ;
V_5 -> V_6 . V_7 . V_211 = V_209 ;
V_204:
for (; V_200 >= 0 ; V_200 -- ) {
V_2 = F_49 ( V_5 , V_200 ) ;
F_86 ( & V_2 -> V_203 ) ;
}
V_172:
F_86 ( & V_5 -> V_104 ) ;
return V_89 ;
}
static int F_166 ( struct V_5 * V_5 )
{
T_3 V_31 = V_5 -> V_6 . V_7 . V_208 ;
T_3 V_212 = V_5 -> V_6 . V_7 . V_210 ;
if ( F_167 ( V_31 ) || F_167 ( V_212 ) )
return 0 ;
if ( ( V_31 <= V_212 && V_31 + V_213 > V_212 ) ||
( V_212 <= V_31 && V_212 + V_214 > V_31 ) )
return - V_177 ;
return 0 ;
}
static int F_168 ( struct V_5 * V_5 , T_3 * V_215 ,
T_3 V_94 , T_3 V_29 )
{
int V_89 ;
if ( V_94 & ~ V_216 )
return - V_199 ;
if ( V_94 & ( V_217 - 1 ) )
return - V_171 ;
if ( ! F_167 ( * V_215 ) )
return - V_201 ;
if ( V_94 + V_29 < V_94 )
return - V_171 ;
* V_215 = V_94 ;
V_89 = F_166 ( V_5 ) ;
if ( V_89 )
* V_215 = V_209 ;
return V_89 ;
}
int F_169 ( struct V_5 * V_5 , unsigned long type , T_1 * V_94 , bool V_218 )
{
int V_219 = 0 ;
struct V_30 * V_7 = & V_5 -> V_6 . V_7 ;
int V_220 ;
T_3 * V_221 , V_222 ;
T_3 V_223 ;
F_84 ( & V_5 -> V_104 ) ;
switch ( type ) {
case V_224 :
V_220 = V_176 ;
V_221 = & V_7 -> V_208 ;
V_222 = V_213 ;
V_223 = V_217 ;
break;
case V_225 :
V_220 = V_176 ;
V_221 = & V_7 -> V_210 ;
V_222 = V_214 ;
V_223 = V_217 ;
break;
#ifdef F_160
case V_226 :
V_220 = V_197 ;
V_221 = & V_7 -> V_208 ;
V_222 = V_227 ;
V_223 = V_228 ;
break;
case V_229 :
V_220 = V_197 ;
V_221 = & V_7 -> V_211 ;
V_222 = V_230 ;
V_223 = V_228 ;
break;
#endif
default:
V_219 = - V_193 ;
goto V_172;
}
if ( V_7 -> V_175 != V_220 ) {
V_219 = - V_193 ;
goto V_172;
}
if ( V_218 ) {
if ( ! F_170 ( * V_94 , V_223 ) )
V_219 = - V_171 ;
else
V_219 = F_168 ( V_5 , V_221 , * V_94 ,
V_222 ) ;
} else {
* V_94 = * V_221 ;
}
V_172:
F_86 ( & V_5 -> V_104 ) ;
return V_219 ;
}
int F_171 ( struct V_231 * V_97 , struct V_232 * V_233 )
{
int V_219 ;
switch ( V_233 -> V_234 ) {
case V_235 : {
T_1 T_8 * V_236 = ( T_1 T_8 * ) ( long ) V_233 -> V_94 ;
T_1 V_94 ;
unsigned long type = ( unsigned long ) V_233 -> V_233 ;
if ( F_172 ( & V_94 , V_236 , sizeof( V_94 ) ) )
return - V_237 ;
V_219 = F_169 ( V_97 -> V_5 , type , & V_94 , true ) ;
return ( V_219 == - V_193 ) ? - V_102 : V_219 ;
}
case V_238 : {
T_2 T_8 * V_236 = ( T_2 T_8 * ) ( long ) V_233 -> V_94 ;
T_2 V_20 ;
int V_89 = 0 ;
if ( F_173 ( V_20 , V_236 ) )
return - V_237 ;
if ( V_20 < ( V_15 + 32 ) ||
V_20 > V_239 ||
( V_20 & 31 ) )
return - V_171 ;
F_84 ( & V_97 -> V_5 -> V_104 ) ;
if ( F_174 ( V_97 -> V_5 ) || V_97 -> V_5 -> V_6 . V_7 . V_13 )
V_89 = - V_177 ;
else
V_97 -> V_5 -> V_6 . V_7 . V_13 = V_20 ;
F_86 ( & V_97 -> V_5 -> V_104 ) ;
return V_89 ;
}
case V_240 : {
switch ( V_233 -> V_233 ) {
case V_241 :
V_219 = F_130 ( V_97 -> V_5 ) ;
return V_219 ;
}
break;
}
}
return - V_102 ;
}
int F_175 ( struct V_231 * V_97 , struct V_232 * V_233 )
{
int V_219 = - V_102 ;
switch ( V_233 -> V_234 ) {
case V_235 : {
T_1 T_8 * V_236 = ( T_1 T_8 * ) ( long ) V_233 -> V_94 ;
T_1 V_94 ;
unsigned long type = ( unsigned long ) V_233 -> V_233 ;
V_219 = F_169 ( V_97 -> V_5 , type , & V_94 , false ) ;
if ( V_219 )
return ( V_219 == - V_193 ) ? - V_102 : V_219 ;
if ( F_176 ( V_236 , & V_94 , sizeof( V_94 ) ) )
return - V_237 ;
break;
}
case V_238 : {
T_2 T_8 * V_236 = ( T_2 T_8 * ) ( long ) V_233 -> V_94 ;
V_219 = F_177 ( V_97 -> V_5 -> V_6 . V_7 . V_13 , V_236 ) ;
break;
}
}
return V_219 ;
}
int F_178 ( const struct V_83 * V_84 , T_3 V_25 )
{
if ( F_68 ( V_84 , 4 , V_25 ) )
return 0 ;
else
return - V_102 ;
}
static void F_179 ( void * V_242 )
{
F_180 ( V_7 -> V_243 , 0 ) ;
}
static int F_181 ( struct V_244 * V_245 ,
unsigned long V_246 , void * V_212 )
{
switch ( V_246 ) {
case V_247 :
case V_248 :
F_179 ( NULL ) ;
break;
case V_249 :
case V_250 :
F_182 ( V_7 -> V_243 ) ;
break;
}
return V_251 ;
}
int F_183 ( void )
{
const struct V_252 * V_253 ;
const int (* F_184)( struct V_254 * , const struct V_125 * * ,
const struct V_255 * * );
struct V_254 * V_256 ;
int V_89 ;
V_256 = F_185 ( NULL ,
V_257 , & V_253 ) ;
if ( ! V_256 ) {
F_137 ( L_11 ) ;
return - V_193 ;
}
F_184 = V_253 -> V_55 ;
V_89 = F_184 ( V_256 , & V_125 , & V_7 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_186 ( V_7 -> V_243 , F_133 ,
L_12 , F_187 () ) ;
if ( V_89 ) {
F_137 ( L_13 , V_7 -> V_243 ) ;
return V_89 ;
}
V_89 = F_188 ( & V_258 ) ;
if ( V_89 ) {
F_137 ( L_14 ) ;
goto V_259;
}
F_189 ( F_179 , NULL , 1 ) ;
return 0 ;
V_259:
F_190 ( V_7 -> V_243 , F_187 () ) ;
return V_89 ;
}
int F_191 ( struct V_5 * V_5 ,
struct V_260 * V_261 ,
int V_262 )
{
return 0 ;
}
int F_192 ( struct V_5 * V_5 , unsigned V_263 , unsigned V_264 )
{
return V_264 ;
}
int F_193 ( struct V_5 * V_5 , int V_265 ,
T_2 V_3 , int V_166 , bool V_266 )
{
unsigned int V_267 = V_3 + V_15 ;
F_194 ( V_3 , V_166 , V_265 ) ;
F_42 ( ! F_129 ( V_5 ) ) ;
return F_131 ( V_5 , 0 , V_267 , V_166 ) ;
}
int F_195 ( struct V_260 * V_268 ,
struct V_5 * V_5 , int V_265 ,
int V_166 , bool V_266 )
{
return 0 ;
}

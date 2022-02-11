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
return F_22 ( V_2 , V_3 ) || ! F_24 ( V_2 , V_3 ) ;
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
bool F_53 ( struct V_5 * V_5 ,
struct V_45 * V_46 ,
T_3 V_25 , int V_34 )
{
T_2 * V_64 ;
T_2 * V_27 , V_62 ;
int V_47 = V_59 | V_57 ;
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
V_27 = F_11 ( & V_31 -> V_41 , V_34 , V_25 ) ;
V_62 = * V_27 ;
F_41 ( V_46 , V_27 , V_25 , V_47 ) ;
if ( V_46 -> V_54 ) {
V_64 = F_11 ( & V_31 -> V_39 ,
V_34 , V_25 ) ;
V_27 = F_11 ( & V_31 -> V_41 , V_34 , V_25 ) ;
* V_27 |= * V_64 ;
if ( V_25 < 2 ) {
* V_27 &= ~ 0xffff ;
* V_27 |= V_62 & 0xffff ;
}
V_27 = F_11 ( & V_31 -> V_40 ,
V_34 , V_25 ) ;
F_41 ( V_46 , V_27 , V_25 , V_47 ) ;
F_51 ( V_5 ) ;
return true ;
}
return false ;
}
bool F_54 ( struct V_5 * V_5 ,
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
bool F_55 ( struct V_5 * V_5 ,
struct V_45 * V_46 ,
T_3 V_25 , int V_34 )
{
T_2 * V_27 ;
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
V_27 = F_11 ( & V_31 -> V_38 , V_34 , V_25 ) ;
F_41 ( V_46 , V_27 , V_25 ,
V_59 | V_57 ) ;
if ( V_46 -> V_54 ) {
F_51 ( V_5 ) ;
return true ;
}
return false ;
}
static T_2 F_56 ( T_4 V_20 )
{
T_2 V_65 = 0 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < 16 ; V_66 ++ )
V_65 |= ( ( V_20 >> V_66 ) & V_35 ) << ( 2 * V_66 + 1 ) ;
return V_65 ;
}
static T_4 F_57 ( T_2 V_20 )
{
T_4 V_65 = 0 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < 16 ; V_66 ++ )
V_65 |= ( ( V_20 >> ( V_66 * 2 + 1 ) ) & V_35 ) << V_66 ;
return V_65 ;
}
bool F_58 ( T_2 * V_27 , struct V_45 * V_46 ,
T_3 V_25 )
{
T_2 V_20 ;
if ( V_25 & 4 )
V_20 = * V_27 >> 16 ;
else
V_20 = * V_27 & 0xffff ;
V_20 = F_56 ( V_20 ) ;
F_41 ( V_46 , & V_20 , V_25 ,
V_59 | V_58 ) ;
if ( V_46 -> V_54 ) {
if ( V_25 < 8 ) {
* V_27 = ~ 0U ;
return false ;
}
V_20 = F_57 ( V_20 ) ;
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
void F_59 ( struct V_1 * V_2 )
{
struct V_42 * V_42 = & V_2 -> V_6 . V_42 ;
int V_66 ;
F_60 (i, vgic_cpu->lr_used, vgic_cpu->nr_lr) {
struct V_67 V_68 = F_61 ( V_2 , V_66 ) ;
F_42 ( ! ( V_68 . V_69 & V_70 ) ) ;
if ( V_68 . V_3 < V_71 )
F_1 ( V_2 , V_68 . V_3 , V_68 . V_4 ) ;
if ( V_68 . V_69 & V_72 ) {
F_28 ( V_2 , V_68 . V_3 ) ;
V_68 . V_69 &= ~ V_72 ;
}
if ( V_68 . V_69 & V_73 ) {
F_36 ( V_2 , V_68 . V_3 ) ;
V_68 . V_69 &= ~ V_73 ;
}
F_62 ( V_2 , V_66 , V_68 ) ;
F_42 ( V_68 . V_69 & V_70 ) ;
F_63 ( V_66 , V_68 . V_3 , V_2 ) ;
F_27 ( V_2 , V_68 . V_3 ) ;
F_51 ( V_2 -> V_5 ) ;
}
}
const
struct V_74 * F_64 ( const struct V_74 * V_75 ,
int V_50 , T_5 V_25 )
{
while ( V_75 -> V_50 ) {
if ( V_25 >= V_75 -> V_76 &&
( V_25 + V_50 ) <= ( V_75 -> V_76 + V_75 -> V_50 ) )
return V_75 ;
V_75 ++ ;
}
return NULL ;
}
static bool F_65 ( const struct V_30 * V_31 ,
const struct V_74 * V_77 ,
unsigned long V_25 )
{
int V_3 ;
if ( ! V_77 -> V_78 )
return true ;
V_3 = V_25 * 8 / V_77 -> V_78 ;
if ( V_3 >= V_31 -> V_13 )
return false ;
return true ;
}
static bool F_66 ( struct V_1 * V_2 ,
struct V_45 * V_46 ,
unsigned long V_25 ,
const struct V_74 * V_77 )
{
struct V_45 V_79 ;
bool V_80 ;
if ( F_67 ( V_46 -> V_50 <= 4 ) )
return V_77 -> V_81 ( V_2 , V_46 , V_25 ) ;
V_79 . V_50 = 4 ;
V_79 . V_54 = V_46 -> V_54 ;
V_79 . V_16 = V_46 -> V_16 ;
V_79 . V_82 = V_46 -> V_82 + 4 ;
V_79 . V_55 = & ( ( T_2 * ) V_46 -> V_55 ) [ 1 ] ;
V_80 = V_77 -> V_81 ( V_2 , & V_79 , V_25 + 4 ) ;
V_79 . V_82 = V_46 -> V_82 ;
V_79 . V_55 = & ( ( T_2 * ) V_46 -> V_55 ) [ 0 ] ;
V_80 |= V_77 -> V_81 ( V_2 , & V_79 , V_25 ) ;
return V_80 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_83 * V_84 , T_5 V_85 ,
int V_50 , void * V_20 , bool V_54 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
struct V_86 * V_87 = F_69 ( V_84 ,
struct V_86 , V_88 ) ;
struct V_89 * V_90 = V_2 -> V_90 ;
const struct V_74 * V_77 ;
struct V_45 V_46 ;
bool V_91 ;
T_5 V_25 ;
V_25 = V_85 - V_87 -> V_85 ;
V_77 = F_64 ( V_87 -> V_92 , V_50 , V_25 ) ;
if ( F_70 ( ! V_77 || ! V_77 -> V_81 ) ) {
F_71 ( L_1 , V_54 , V_85 , V_50 ) ;
return - V_93 ;
}
V_46 . V_82 = V_85 ;
V_46 . V_50 = V_50 ;
V_46 . V_54 = V_54 ;
V_46 . V_55 = V_20 ;
V_46 . V_16 = V_87 -> V_94 ;
F_72 ( & V_31 -> V_95 ) ;
V_25 -= V_77 -> V_76 ;
if ( F_65 ( V_31 , V_77 , V_25 ) ) {
V_91 = F_66 ( V_2 , & V_46 , V_25 , V_77 ) ;
} else {
if ( ! V_54 )
memset ( V_20 , 0 , V_50 ) ;
V_91 = false ;
}
F_73 ( & V_31 -> V_95 ) ;
V_90 -> V_46 . V_54 = V_54 ;
V_90 -> V_46 . V_50 = V_50 ;
V_90 -> V_46 . V_82 = V_85 ;
memcpy ( V_90 -> V_46 . V_55 , V_20 , V_50 ) ;
F_74 ( V_2 , V_90 ) ;
if ( V_91 )
F_75 ( V_2 -> V_5 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_83 * V_84 ,
T_5 V_85 , int V_50 , void * V_20 )
{
return F_68 ( V_2 , V_84 , V_85 , V_50 , V_20 , false ) ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_83 * V_84 ,
T_5 V_85 , int V_50 , const void * V_20 )
{
return F_68 ( V_2 , V_84 , V_85 , V_50 , ( void * ) V_20 ,
true ) ;
}
int F_78 ( struct V_5 * V_5 , T_5 V_76 , int V_50 ,
const struct V_74 * V_75 ,
int V_96 ,
struct V_86 * V_87 )
{
struct V_1 * V_2 = NULL ;
int V_80 ;
if ( V_96 >= 0 )
V_2 = F_49 ( V_5 , V_96 ) ;
V_87 -> V_85 = V_76 ;
V_87 -> V_50 = V_50 ;
V_87 -> V_92 = V_75 ;
V_87 -> V_94 = V_2 ;
F_79 ( & V_87 -> V_88 , & V_97 ) ;
F_80 ( & V_5 -> V_98 ) ;
V_80 = F_81 ( V_5 , V_99 , V_76 , V_50 ,
& V_87 -> V_88 ) ;
F_82 ( & V_5 -> V_98 ) ;
if ( V_80 )
V_87 -> V_88 . V_100 = NULL ;
return V_80 ;
}
static int F_83 ( struct V_30 * V_31 )
{
return V_31 -> V_13 - V_15 ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
unsigned long * V_101 , * V_102 , * V_103 , * V_104 ;
unsigned long V_105 , V_106 ;
int V_107 = F_83 ( V_31 ) ;
int V_34 ;
V_34 = V_2 -> V_34 ;
V_103 = V_2 -> V_6 . V_42 . V_108 ;
V_104 = V_2 -> V_6 . V_42 . V_106 ;
V_101 = F_17 ( & V_31 -> V_38 , V_34 ) ;
V_102 = F_17 ( & V_31 -> V_36 , V_34 ) ;
F_85 ( V_103 , V_101 , V_102 , V_15 ) ;
V_101 = F_18 ( & V_31 -> V_38 ) ;
V_102 = F_18 ( & V_31 -> V_36 ) ;
F_85 ( V_104 , V_101 , V_102 , V_107 ) ;
F_85 ( V_104 , V_104 ,
F_18 ( & V_31 -> V_109 [ V_34 ] ) ,
V_107 ) ;
V_105 = F_86 ( V_103 , V_15 ) ;
V_106 = F_86 ( V_104 , V_107 ) ;
return ( V_105 < V_15 ||
V_106 < V_107 ) ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
unsigned long * V_110 , * V_102 , * V_111 , * V_112 ;
unsigned long V_113 , V_44 ;
int V_107 = F_83 ( V_31 ) ;
int V_34 ;
V_34 = V_2 -> V_34 ;
V_111 = V_2 -> V_6 . V_42 . V_43 ;
V_112 = V_2 -> V_6 . V_42 . V_44 ;
V_110 = F_17 ( & V_31 -> V_41 , V_34 ) ;
V_102 = F_17 ( & V_31 -> V_36 , V_34 ) ;
F_85 ( V_111 , V_110 , V_102 , V_15 ) ;
V_110 = F_18 ( & V_31 -> V_41 ) ;
V_102 = F_18 ( & V_31 -> V_36 ) ;
F_85 ( V_112 , V_110 , V_102 , V_107 ) ;
F_85 ( V_112 , V_112 ,
F_18 ( & V_31 -> V_109 [ V_34 ] ) ,
V_107 ) ;
V_113 = F_86 ( V_111 , V_15 ) ;
V_44 = F_86 ( V_112 , V_107 ) ;
return ( V_113 < V_15 ||
V_44 < F_83 ( V_31 ) ) ;
}
void F_51 ( struct V_5 * V_5 )
{
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
struct V_1 * V_2 ;
int V_114 ;
if ( ! V_31 -> V_102 ) {
F_15 ( 0 , V_31 -> V_115 ) ;
return;
}
F_88 (c, vcpu, kvm) {
if ( F_87 ( V_2 ) )
F_15 ( V_114 , V_31 -> V_115 ) ;
if ( F_84 ( V_2 ) )
F_15 ( V_114 , V_31 -> V_116 ) ;
else
F_16 ( V_114 , V_31 -> V_116 ) ;
}
}
static struct V_67 F_61 ( const struct V_1 * V_2 , int V_68 )
{
return V_117 -> V_118 ( V_2 , V_68 ) ;
}
static void F_62 ( struct V_1 * V_2 , int V_68 ,
struct V_67 V_119 )
{
V_117 -> V_120 ( V_2 , V_68 , V_119 ) ;
}
static void F_89 ( struct V_1 * V_2 , int V_68 ,
struct V_67 V_119 )
{
V_117 -> V_121 ( V_2 , V_68 , V_119 ) ;
}
static inline T_1 F_90 ( struct V_1 * V_2 )
{
return V_117 -> V_122 ( V_2 ) ;
}
static inline T_1 F_91 ( struct V_1 * V_2 )
{
return V_117 -> V_123 ( V_2 ) ;
}
static inline void F_92 ( struct V_1 * V_2 )
{
V_117 -> V_124 ( V_2 ) ;
}
static inline T_2 F_93 ( struct V_1 * V_2 )
{
return V_117 -> V_125 ( V_2 ) ;
}
static inline void F_94 ( struct V_1 * V_2 )
{
V_117 -> V_126 ( V_2 ) ;
}
static inline void F_95 ( struct V_1 * V_2 )
{
V_117 -> V_127 ( V_2 ) ;
}
void F_96 ( struct V_1 * V_2 , struct V_128 * V_129 )
{
V_117 -> V_130 ( V_2 , V_129 ) ;
}
void F_97 ( struct V_1 * V_2 , struct V_128 * V_129 )
{
V_117 -> V_131 ( V_2 , V_129 ) ;
}
static inline void F_98 ( struct V_1 * V_2 )
{
V_117 -> V_132 ( V_2 ) ;
}
static void F_63 ( int V_133 , int V_3 , struct V_1 * V_2 )
{
struct V_42 * V_42 = & V_2 -> V_6 . V_42 ;
struct V_67 V_119 = F_61 ( V_2 , V_133 ) ;
V_119 . V_69 = 0 ;
F_62 ( V_2 , V_133 , V_119 ) ;
F_16 ( V_133 , V_42 -> V_134 ) ;
V_42 -> V_135 [ V_3 ] = V_136 ;
F_89 ( V_2 , V_133 , V_119 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_42 * V_42 = & V_2 -> V_6 . V_42 ;
int V_68 ;
F_60 (lr, vgic_cpu->lr_used, vgic->nr_lr) {
struct V_67 V_119 = F_61 ( V_2 , V_68 ) ;
if ( ! F_23 ( V_2 , V_119 . V_3 ) ) {
F_63 ( V_68 , V_119 . V_3 , V_2 ) ;
if ( F_24 ( V_2 , V_119 . V_3 ) )
F_27 ( V_2 , V_119 . V_3 ) ;
}
}
}
static void F_99 ( struct V_1 * V_2 , int V_3 ,
int V_133 , struct V_67 V_119 )
{
if ( F_25 ( V_2 , V_3 ) ) {
V_119 . V_69 |= V_72 ;
F_100 ( L_2 , V_119 . V_69 ) ;
F_29 ( V_2 , V_3 ) ;
F_51 ( V_2 -> V_5 ) ;
} else if ( F_35 ( V_2 , V_3 ) ) {
V_119 . V_69 |= V_73 ;
F_100 ( L_3 , V_119 . V_69 ) ;
}
if ( ! F_22 ( V_2 , V_3 ) )
V_119 . V_69 |= V_137 ;
F_62 ( V_2 , V_133 , V_119 ) ;
F_89 ( V_2 , V_133 , V_119 ) ;
}
bool F_101 ( struct V_1 * V_2 , T_6 V_138 , int V_3 )
{
struct V_42 * V_42 = & V_2 -> V_6 . V_42 ;
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
struct V_67 V_119 ;
int V_68 ;
F_42 ( V_138 & ~ 7 ) ;
F_42 ( V_138 && V_3 >= V_71 ) ;
F_42 ( V_3 >= V_31 -> V_13 ) ;
F_100 ( L_4 , V_3 ) ;
V_68 = V_42 -> V_135 [ V_3 ] ;
if ( V_68 != V_136 ) {
V_119 = F_61 ( V_2 , V_68 ) ;
if ( V_119 . V_4 == V_138 ) {
F_100 ( L_5 , V_68 , V_119 . V_3 ) ;
F_42 ( ! F_13 ( V_68 , V_42 -> V_134 ) ) ;
F_99 ( V_2 , V_3 , V_68 , V_119 ) ;
return true ;
}
}
V_68 = F_102 ( ( unsigned long * ) V_42 -> V_134 ,
V_7 -> V_139 ) ;
if ( V_68 >= V_7 -> V_139 )
return false ;
F_100 ( L_6 , V_68 , V_3 , V_138 ) ;
V_42 -> V_135 [ V_3 ] = V_68 ;
F_15 ( V_68 , V_42 -> V_134 ) ;
V_119 . V_3 = V_3 ;
V_119 . V_4 = V_138 ;
V_119 . V_69 = 0 ;
F_99 ( V_2 , V_3 , V_68 , V_119 ) ;
return true ;
}
static bool F_103 ( struct V_1 * V_2 , int V_3 )
{
if ( ! F_40 ( V_2 , V_3 ) )
return true ;
if ( F_101 ( V_2 , 0 , V_3 ) ) {
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
static void F_104 ( struct V_1 * V_2 )
{
struct V_42 * V_42 = & V_2 -> V_6 . V_42 ;
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
unsigned long * V_140 , * V_141 ;
int V_66 , V_34 ;
int V_142 = 0 ;
int V_107 = F_83 ( V_31 ) ;
V_34 = V_2 -> V_34 ;
V_140 = V_2 -> V_6 . V_42 . V_143 ;
V_141 = V_2 -> V_6 . V_42 . V_144 ;
F_105 ( V_140 , V_42 -> V_43 , V_42 -> V_108 ,
V_15 ) ;
F_105 ( V_141 , V_42 -> V_44 , V_42 -> V_106 ,
V_107 ) ;
if ( ! F_106 ( V_2 ) && ! F_107 ( V_2 ) )
goto V_145;
F_60 (i, pa_percpu, VGIC_NR_SGIS) {
if ( ! F_2 ( V_2 , V_66 ) )
V_142 = 1 ;
}
F_108 (i, pa_percpu, VGIC_NR_PRIVATE_IRQS) {
if ( ! F_103 ( V_2 , V_66 ) )
V_142 = 1 ;
}
F_60 (i, pa_shared, nr_shared) {
if ( ! F_103 ( V_2 , V_66 + V_15 ) )
V_142 = 1 ;
}
V_145:
if ( V_142 ) {
F_94 ( V_2 ) ;
} else {
F_95 ( V_2 ) ;
F_16 ( V_34 , V_31 -> V_115 ) ;
}
}
static bool F_109 ( struct V_1 * V_2 )
{
T_2 V_146 = F_93 ( V_2 ) ;
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
bool V_147 = false ;
struct V_5 * V_5 = V_2 -> V_5 ;
F_100 ( L_7 , V_146 ) ;
if ( V_146 & V_148 ) {
T_1 V_149 = F_91 ( V_2 ) ;
unsigned long * V_150 = F_9 ( & V_149 ) ;
int V_68 ;
F_60 (lr, eisr_ptr, vgic->nr_lr) {
struct V_67 V_119 = F_61 ( V_2 , V_68 ) ;
F_110 ( F_22 ( V_2 , V_119 . V_3 ) ) ;
F_72 ( & V_31 -> V_95 ) ;
F_27 ( V_2 , V_119 . V_3 ) ;
F_110 ( V_119 . V_69 & V_70 ) ;
V_119 . V_69 = 0 ;
F_62 ( V_2 , V_68 , V_119 ) ;
F_34 ( V_2 , V_119 . V_3 ) ;
F_73 ( & V_31 -> V_95 ) ;
F_111 ( V_5 , 0 ,
V_119 . V_3 - V_15 ) ;
F_72 ( & V_31 -> V_95 ) ;
if ( F_30 ( V_2 , V_119 . V_3 ) ) {
F_38 ( V_2 , V_119 . V_3 ) ;
V_147 = true ;
} else {
F_37 ( V_2 , V_119 . V_3 ) ;
F_39 ( V_2 , V_119 . V_3 ) ;
}
F_73 ( & V_31 -> V_95 ) ;
F_89 ( V_2 , V_68 , V_119 ) ;
}
}
if ( V_146 & V_151 )
F_95 ( V_2 ) ;
F_92 ( V_2 ) ;
return V_147 ;
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_42 * V_42 = & V_2 -> V_6 . V_42 ;
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
T_1 V_152 ;
unsigned long * V_153 ;
int V_68 , V_110 ;
bool V_147 ;
V_147 = F_109 ( V_2 ) ;
V_152 = F_90 ( V_2 ) ;
V_153 = F_9 ( & V_152 ) ;
F_60 (lr, elrsr_ptr, vgic->nr_lr) {
struct V_67 V_119 ;
if ( ! F_113 ( V_68 , V_42 -> V_134 ) )
continue;
V_119 = F_61 ( V_2 , V_68 ) ;
F_42 ( V_119 . V_3 >= V_31 -> V_13 ) ;
V_42 -> V_135 [ V_119 . V_3 ] = V_136 ;
}
V_110 = F_102 ( V_153 , V_7 -> V_139 ) ;
if ( V_147 || V_110 < V_7 -> V_139 )
F_15 ( V_2 -> V_34 , V_31 -> V_115 ) ;
}
void F_114 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
if ( ! F_115 ( V_2 -> V_5 ) )
return;
F_72 ( & V_31 -> V_95 ) ;
F_104 ( V_2 ) ;
F_73 ( & V_31 -> V_95 ) ;
}
void F_116 ( struct V_1 * V_2 )
{
if ( ! F_115 ( V_2 -> V_5 ) )
return;
F_112 ( V_2 ) ;
}
int F_106 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
if ( ! F_115 ( V_2 -> V_5 ) )
return 0 ;
return F_13 ( V_2 -> V_34 , V_31 -> V_115 ) ;
}
int F_107 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
if ( ! F_115 ( V_2 -> V_5 ) )
return 0 ;
return F_13 ( V_2 -> V_34 , V_31 -> V_116 ) ;
}
void F_75 ( struct V_5 * V_5 )
{
struct V_1 * V_2 ;
int V_114 ;
F_88 (c, vcpu, kvm) {
if ( F_106 ( V_2 ) )
F_117 ( V_2 ) ;
}
}
static int F_118 ( struct V_1 * V_2 , int V_3 , int V_154 )
{
int V_155 = F_22 ( V_2 , V_3 ) ;
if ( V_155 ) {
int V_69 = F_35 ( V_2 , V_3 ) ;
return V_154 > V_69 ;
} else {
int V_69 = F_30 ( V_2 , V_3 ) ;
return V_154 != V_69 ;
}
}
static int F_119 ( struct V_5 * V_5 , int V_24 ,
unsigned int V_156 , bool V_154 )
{
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
struct V_1 * V_2 ;
int V_155 , V_157 ;
int V_102 ;
bool V_80 = true , V_158 = true ;
F_72 ( & V_31 -> V_95 ) ;
V_2 = F_49 ( V_5 , V_24 ) ;
V_155 = F_22 ( V_2 , V_156 ) ;
V_157 = ! V_155 ;
if ( ! F_118 ( V_2 , V_156 , V_154 ) ) {
V_80 = false ;
goto V_159;
}
if ( V_156 >= V_15 ) {
V_24 = V_31 -> V_160 [ V_156 - V_15 ] ;
if ( V_24 == V_161 ) {
V_24 = 0 ;
V_158 = false ;
}
V_2 = F_49 ( V_5 , V_24 ) ;
}
F_100 ( L_8 , V_156 , V_154 , V_24 ) ;
if ( V_154 ) {
if ( V_157 )
F_31 ( V_2 , V_156 ) ;
F_36 ( V_2 , V_156 ) ;
} else {
if ( V_157 ) {
F_32 ( V_2 , V_156 ) ;
if ( ! F_33 ( V_2 , V_156 ) )
F_37 ( V_2 , V_156 ) ;
}
V_80 = false ;
goto V_159;
}
V_102 = F_23 ( V_2 , V_156 ) ;
if ( ! V_102 || ! V_158 ) {
V_80 = false ;
goto V_159;
}
if ( ! F_40 ( V_2 , V_156 ) ) {
V_80 = false ;
goto V_159;
}
if ( V_154 ) {
F_38 ( V_2 , V_156 ) ;
F_15 ( V_24 , V_31 -> V_115 ) ;
}
V_159:
F_73 ( & V_31 -> V_95 ) ;
return V_80 ? V_24 : - V_162 ;
}
int F_120 ( struct V_5 * V_5 , int V_24 , unsigned int V_156 ,
bool V_154 )
{
int V_80 = 0 ;
int V_34 ;
if ( F_70 ( ! F_121 ( V_5 ) ) ) {
if ( V_5 -> V_6 . V_7 . V_163 != V_164 ) {
V_80 = - V_165 ;
goto V_159;
}
F_80 ( & V_5 -> V_95 ) ;
V_80 = F_122 ( V_5 ) ;
F_82 ( & V_5 -> V_95 ) ;
if ( V_80 )
goto V_159;
}
if ( V_156 >= F_123 ( V_5 -> V_6 . V_7 . V_13 , 1020 ) )
return - V_162 ;
V_34 = F_119 ( V_5 , V_24 , V_156 , V_154 ) ;
if ( V_34 >= 0 ) {
F_117 ( F_49 ( V_5 , V_34 ) ) ;
}
V_159:
return V_80 ;
}
static T_7 F_124 ( int V_3 , void * V_55 )
{
return V_166 ;
}
void F_125 ( struct V_1 * V_2 )
{
struct V_42 * V_42 = & V_2 -> V_6 . V_42 ;
F_8 ( V_42 -> V_44 ) ;
F_8 ( V_42 -> V_106 ) ;
F_8 ( V_42 -> V_144 ) ;
F_8 ( V_42 -> V_135 ) ;
V_42 -> V_44 = NULL ;
V_42 -> V_106 = NULL ;
V_42 -> V_144 = NULL ;
V_42 -> V_135 = NULL ;
}
static int F_126 ( struct V_1 * V_2 , int V_13 )
{
struct V_42 * V_42 = & V_2 -> V_6 . V_42 ;
int V_167 = ( V_13 - V_15 ) / 8 ;
V_42 -> V_44 = F_6 ( V_167 , V_17 ) ;
V_42 -> V_106 = F_6 ( V_167 , V_17 ) ;
V_42 -> V_144 = F_6 ( V_167 , V_17 ) ;
V_42 -> V_135 = F_127 ( V_13 , V_17 ) ;
if ( ! V_42 -> V_44
|| ! V_42 -> V_106
|| ! V_42 -> V_144
|| ! V_42 -> V_135 ) {
F_125 ( V_2 ) ;
return - V_18 ;
}
memset ( V_42 -> V_135 , V_136 , V_13 ) ;
V_42 -> V_139 = V_7 -> V_139 ;
return 0 ;
}
int F_128 ( void )
{
return V_7 -> V_168 ;
}
void F_129 ( struct V_5 * V_5 )
{
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
struct V_1 * V_2 ;
int V_66 ;
F_88 (i, vcpu, kvm)
F_125 ( V_2 ) ;
F_7 ( & V_31 -> V_36 ) ;
F_7 ( & V_31 -> V_39 ) ;
F_7 ( & V_31 -> V_41 ) ;
F_7 ( & V_31 -> V_40 ) ;
F_7 ( & V_31 -> V_37 ) ;
F_7 ( & V_31 -> V_33 ) ;
F_20 ( & V_31 -> V_169 ) ;
if ( V_31 -> V_109 ) {
for ( V_66 = 0 ; V_66 < V_31 -> V_12 ; V_66 ++ )
F_7 ( & V_31 -> V_109 [ V_66 ] ) ;
}
F_8 ( V_31 -> V_170 ) ;
F_8 ( V_31 -> V_160 ) ;
F_8 ( V_31 -> V_171 ) ;
F_8 ( V_31 -> V_109 ) ;
F_8 ( V_31 -> V_115 ) ;
F_8 ( V_31 -> V_116 ) ;
V_31 -> V_170 = NULL ;
V_31 -> V_160 = NULL ;
V_31 -> V_109 = NULL ;
V_31 -> V_115 = NULL ;
V_31 -> V_116 = NULL ;
V_31 -> V_12 = 0 ;
}
int F_122 ( struct V_5 * V_5 )
{
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
struct V_1 * V_2 ;
int V_12 , V_13 ;
int V_80 , V_66 , V_34 ;
if ( F_121 ( V_5 ) )
return 0 ;
V_12 = V_31 -> V_12 = F_130 ( & V_5 -> V_172 ) ;
if ( ! V_12 )
return - V_173 ;
if ( ! V_31 -> V_13 )
V_31 -> V_13 = V_174 ;
V_13 = V_31 -> V_13 ;
V_80 = F_4 ( & V_31 -> V_36 , V_12 , V_13 ) ;
V_80 |= F_4 ( & V_31 -> V_39 , V_12 , V_13 ) ;
V_80 |= F_4 ( & V_31 -> V_41 , V_12 , V_13 ) ;
V_80 |= F_4 ( & V_31 -> V_40 , V_12 , V_13 ) ;
V_80 |= F_4 ( & V_31 -> V_37 , V_12 , V_13 ) ;
V_80 |= F_4 ( & V_31 -> V_38 , V_12 , V_13 ) ;
V_80 |= F_4 ( & V_31 -> V_33 , V_12 , V_13 ) ;
V_80 |= F_19 ( & V_31 -> V_169 , V_12 , V_13 ) ;
if ( V_80 )
goto V_159;
V_31 -> V_170 = F_6 ( V_12 * V_71 , V_17 ) ;
V_31 -> V_160 = F_6 ( V_13 - V_15 , V_17 ) ;
V_31 -> V_109 = F_6 ( sizeof( * V_31 -> V_109 ) * V_12 ,
V_17 ) ;
V_31 -> V_115 = F_6 ( F_5 ( V_12 ) * sizeof( long ) ,
V_17 ) ;
V_31 -> V_116 = F_6 ( F_5 ( V_12 ) * sizeof( long ) ,
V_17 ) ;
if ( ! V_31 -> V_170 ||
! V_31 -> V_160 ||
! V_31 -> V_109 ||
! V_31 -> V_115 ||
! V_31 -> V_116 ) {
V_80 = - V_18 ;
goto V_159;
}
for ( V_66 = 0 ; V_66 < V_12 ; V_66 ++ )
V_80 |= F_4 ( & V_31 -> V_109 [ V_66 ] ,
V_12 , V_13 ) ;
if ( V_80 )
goto V_159;
V_80 = V_5 -> V_6 . V_7 . V_8 . V_175 ( V_5 ) ;
if ( V_80 )
goto V_159;
F_88 (vcpu_id, vcpu, kvm) {
V_80 = F_126 ( V_2 , V_13 ) ;
if ( V_80 ) {
F_131 ( L_9 ) ;
break;
}
for ( V_66 = 0 ; V_66 < V_31 -> V_13 ; V_66 ++ ) {
if ( V_66 < V_176 )
F_14 ( & V_31 -> V_36 ,
V_2 -> V_34 , V_66 , 1 ) ;
if ( V_66 < V_15 )
F_14 ( & V_31 -> V_33 ,
V_2 -> V_34 , V_66 ,
V_35 ) ;
}
F_98 ( V_2 ) ;
}
V_159:
if ( V_80 )
F_129 ( V_5 ) ;
return V_80 ;
}
static int F_132 ( struct V_5 * V_5 , int type )
{
switch ( type ) {
case V_164 :
F_133 ( V_5 ) ;
break;
#ifdef F_134
case V_177 :
F_135 ( V_5 ) ;
break;
#endif
default:
return - V_173 ;
}
if ( F_130 ( & V_5 -> V_172 ) > V_5 -> V_6 . V_178 )
return - V_179 ;
return 0 ;
}
int F_136 ( struct V_5 * V_5 , T_2 type )
{
int V_66 , V_180 = - 1 , V_80 ;
struct V_1 * V_2 ;
F_80 ( & V_5 -> V_95 ) ;
if ( F_115 ( V_5 ) ) {
V_80 = - V_181 ;
goto V_159;
}
if ( type == V_164 && ! V_7 -> V_182 ) {
V_80 = - V_173 ;
goto V_159;
}
V_80 = - V_165 ;
F_88 (i, vcpu, kvm) {
if ( ! F_137 ( & V_2 -> V_183 ) )
goto V_184;
V_180 = V_66 ;
}
F_88 (i, vcpu, kvm) {
if ( V_2 -> V_6 . V_185 )
goto V_184;
}
V_80 = 0 ;
V_80 = F_132 ( V_5 , type ) ;
if ( V_80 )
goto V_184;
F_138 ( & V_5 -> V_6 . V_7 . V_95 ) ;
V_5 -> V_6 . V_7 . V_186 = true ;
V_5 -> V_6 . V_7 . V_163 = type ;
V_5 -> V_6 . V_7 . V_187 = V_7 -> V_187 ;
V_5 -> V_6 . V_7 . V_188 = V_189 ;
V_5 -> V_6 . V_7 . V_190 = V_189 ;
V_5 -> V_6 . V_7 . V_191 = V_189 ;
V_184:
for (; V_180 >= 0 ; V_180 -- ) {
V_2 = F_49 ( V_5 , V_180 ) ;
F_82 ( & V_2 -> V_183 ) ;
}
V_159:
F_82 ( & V_5 -> V_95 ) ;
return V_80 ;
}
static int F_139 ( struct V_5 * V_5 )
{
T_3 V_31 = V_5 -> V_6 . V_7 . V_188 ;
T_3 V_192 = V_5 -> V_6 . V_7 . V_190 ;
if ( F_140 ( V_31 ) || F_140 ( V_192 ) )
return 0 ;
if ( ( V_31 <= V_192 && V_31 + V_193 > V_192 ) ||
( V_192 <= V_31 && V_192 + V_194 > V_31 ) )
return - V_165 ;
return 0 ;
}
static int F_141 ( struct V_5 * V_5 , T_3 * V_195 ,
T_3 V_85 , T_3 V_29 )
{
int V_80 ;
if ( V_85 & ~ V_196 )
return - V_179 ;
if ( V_85 & ( V_197 - 1 ) )
return - V_162 ;
if ( ! F_140 ( * V_195 ) )
return - V_181 ;
if ( V_85 + V_29 < V_85 )
return - V_162 ;
* V_195 = V_85 ;
V_80 = F_139 ( V_5 ) ;
if ( V_80 )
* V_195 = V_189 ;
return V_80 ;
}
int F_142 ( struct V_5 * V_5 , unsigned long type , T_1 * V_85 , bool V_198 )
{
int V_199 = 0 ;
struct V_30 * V_7 = & V_5 -> V_6 . V_7 ;
int V_200 ;
T_3 * V_201 , V_202 ;
T_3 V_203 ;
F_80 ( & V_5 -> V_95 ) ;
switch ( type ) {
case V_204 :
V_200 = V_164 ;
V_201 = & V_7 -> V_188 ;
V_202 = V_193 ;
V_203 = V_197 ;
break;
case V_205 :
V_200 = V_164 ;
V_201 = & V_7 -> V_190 ;
V_202 = V_194 ;
V_203 = V_197 ;
break;
#ifdef F_134
case V_206 :
V_200 = V_177 ;
V_201 = & V_7 -> V_188 ;
V_202 = V_207 ;
V_203 = V_208 ;
break;
case V_209 :
V_200 = V_177 ;
V_201 = & V_7 -> V_191 ;
V_202 = V_210 ;
V_203 = V_208 ;
break;
#endif
default:
V_199 = - V_173 ;
goto V_159;
}
if ( V_7 -> V_163 != V_200 ) {
V_199 = - V_173 ;
goto V_159;
}
if ( V_198 ) {
if ( ! F_143 ( * V_85 , V_203 ) )
V_199 = - V_162 ;
else
V_199 = F_141 ( V_5 , V_201 , * V_85 ,
V_202 ) ;
} else {
* V_85 = * V_201 ;
}
V_159:
F_82 ( & V_5 -> V_95 ) ;
return V_199 ;
}
int F_144 ( struct V_211 * V_88 , struct V_212 * V_213 )
{
int V_199 ;
switch ( V_213 -> V_214 ) {
case V_215 : {
T_1 T_8 * V_216 = ( T_1 T_8 * ) ( long ) V_213 -> V_85 ;
T_1 V_85 ;
unsigned long type = ( unsigned long ) V_213 -> V_213 ;
if ( F_145 ( & V_85 , V_216 , sizeof( V_85 ) ) )
return - V_217 ;
V_199 = F_142 ( V_88 -> V_5 , type , & V_85 , true ) ;
return ( V_199 == - V_173 ) ? - V_93 : V_199 ;
}
case V_218 : {
T_2 T_8 * V_216 = ( T_2 T_8 * ) ( long ) V_213 -> V_85 ;
T_2 V_20 ;
int V_80 = 0 ;
if ( F_146 ( V_20 , V_216 ) )
return - V_217 ;
if ( V_20 < ( V_15 + 32 ) ||
V_20 > V_219 ||
( V_20 & 31 ) )
return - V_162 ;
F_80 ( & V_88 -> V_5 -> V_95 ) ;
if ( F_147 ( V_88 -> V_5 ) || V_88 -> V_5 -> V_6 . V_7 . V_13 )
V_80 = - V_165 ;
else
V_88 -> V_5 -> V_6 . V_7 . V_13 = V_20 ;
F_82 ( & V_88 -> V_5 -> V_95 ) ;
return V_80 ;
}
case V_220 : {
switch ( V_213 -> V_213 ) {
case V_221 :
V_199 = F_122 ( V_88 -> V_5 ) ;
return V_199 ;
}
break;
}
}
return - V_93 ;
}
int F_148 ( struct V_211 * V_88 , struct V_212 * V_213 )
{
int V_199 = - V_93 ;
switch ( V_213 -> V_214 ) {
case V_215 : {
T_1 T_8 * V_216 = ( T_1 T_8 * ) ( long ) V_213 -> V_85 ;
T_1 V_85 ;
unsigned long type = ( unsigned long ) V_213 -> V_213 ;
V_199 = F_142 ( V_88 -> V_5 , type , & V_85 , false ) ;
if ( V_199 )
return ( V_199 == - V_173 ) ? - V_93 : V_199 ;
if ( F_149 ( V_216 , & V_85 , sizeof( V_85 ) ) )
return - V_217 ;
break;
}
case V_218 : {
T_2 T_8 * V_216 = ( T_2 T_8 * ) ( long ) V_213 -> V_85 ;
V_199 = F_150 ( V_88 -> V_5 -> V_6 . V_7 . V_13 , V_216 ) ;
break;
}
}
return V_199 ;
}
int F_151 ( const struct V_74 * V_75 , T_3 V_25 )
{
if ( F_64 ( V_75 , 4 , V_25 ) )
return 0 ;
else
return - V_93 ;
}
static void F_152 ( void * V_222 )
{
F_153 ( V_7 -> V_223 , 0 ) ;
}
static int F_154 ( struct V_224 * V_225 ,
unsigned long V_226 , void * V_192 )
{
switch ( V_226 ) {
case V_227 :
case V_228 :
F_152 ( NULL ) ;
break;
case V_229 :
case V_230 :
F_155 ( V_7 -> V_223 ) ;
break;
}
return V_231 ;
}
int F_156 ( void )
{
const struct V_232 * V_233 ;
const int (* F_157)( struct V_234 * , const struct V_117 * * ,
const struct V_235 * * );
struct V_234 * V_236 ;
int V_80 ;
V_236 = F_158 ( NULL ,
V_237 , & V_233 ) ;
if ( ! V_236 ) {
F_131 ( L_10 ) ;
return - V_173 ;
}
F_157 = V_233 -> V_55 ;
V_80 = F_157 ( V_236 , & V_117 , & V_7 ) ;
if ( V_80 )
return V_80 ;
V_80 = F_159 ( V_7 -> V_223 , F_124 ,
L_11 , F_160 () ) ;
if ( V_80 ) {
F_131 ( L_12 , V_7 -> V_223 ) ;
return V_80 ;
}
V_80 = F_161 ( & V_238 ) ;
if ( V_80 ) {
F_131 ( L_13 ) ;
goto V_239;
}
F_162 ( F_152 , NULL , 1 ) ;
return 0 ;
V_239:
F_163 ( V_7 -> V_223 , F_160 () ) ;
return V_80 ;
}
int F_164 ( struct V_5 * V_5 ,
struct V_240 * V_241 ,
int V_242 )
{
return 0 ;
}
int F_165 ( struct V_5 * V_5 , unsigned V_243 , unsigned V_244 )
{
return V_244 ;
}
int F_166 ( struct V_5 * V_5 , int V_245 ,
T_2 V_3 , int V_154 , bool V_246 )
{
unsigned int V_247 = V_3 + V_15 ;
F_167 ( V_3 , V_154 , V_245 ) ;
F_42 ( ! F_121 ( V_5 ) ) ;
return F_120 ( V_5 , 0 , V_247 , V_154 ) ;
}
int F_168 ( struct V_240 * V_248 ,
struct V_5 * V_5 , int V_245 ,
int V_154 , bool V_246 )
{
return 0 ;
}

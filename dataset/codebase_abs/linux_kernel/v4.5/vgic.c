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
if ( ! F_30 ( V_2 , V_3 ) ) {
F_35 ( V_2 , V_3 ) ;
if ( ! F_36 ( V_2 ) )
F_16 ( V_2 -> V_34 , V_31 -> V_41 ) ;
}
}
static int F_37 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
return F_12 ( & V_31 -> V_42 , V_2 -> V_34 , V_3 ) ;
}
void F_38 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
F_14 ( & V_31 -> V_42 , V_2 -> V_34 , V_3 , 1 ) ;
}
void F_35 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
F_14 ( & V_31 -> V_42 , V_2 -> V_34 , V_3 , 0 ) ;
}
static void F_39 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 < V_15 )
F_15 ( V_3 , V_2 -> V_6 . V_43 . V_44 ) ;
else
F_15 ( V_3 - V_15 ,
V_2 -> V_6 . V_43 . V_45 ) ;
}
void F_40 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 < V_15 )
F_16 ( V_3 , V_2 -> V_6 . V_43 . V_44 ) ;
else
F_16 ( V_3 - V_15 ,
V_2 -> V_6 . V_43 . V_45 ) ;
}
static bool F_41 ( struct V_1 * V_2 , int V_3 )
{
return ! F_24 ( V_2 , V_3 ) ;
}
void F_42 ( struct V_46 * V_47 , T_2 * V_27 ,
T_3 V_25 , int V_48 )
{
int V_49 = ( V_25 & 3 ) * 8 ;
T_2 V_50 = ( 1UL << ( V_47 -> V_51 * 8 ) ) - 1 ;
T_2 V_52 ;
if ( V_27 ) {
V_52 = * V_27 ;
} else {
F_43 ( V_48 != ( V_53 | V_54 ) ) ;
V_52 = 0 ;
}
if ( V_47 -> V_55 ) {
T_2 V_56 = F_44 ( V_47 , V_50 ) << V_49 ;
switch ( F_45 ( V_48 ) ) {
case V_54 :
return;
case V_57 :
V_52 |= V_56 ;
break;
case V_58 :
V_52 &= ~ V_56 ;
break;
case V_59 :
V_52 = ( V_52 & ~ ( V_50 << V_49 ) ) | V_56 ;
break;
}
* V_27 = V_52 ;
} else {
switch ( F_46 ( V_48 ) ) {
case V_53 :
V_52 = 0 ;
case V_60 :
F_47 ( V_47 , V_50 , V_52 >> V_49 ) ;
}
}
}
bool F_48 ( struct V_1 * V_2 , struct V_46 * V_47 ,
T_3 V_25 )
{
F_42 ( V_47 , NULL , V_25 ,
V_53 | V_54 ) ;
return false ;
}
bool F_49 ( struct V_5 * V_5 , struct V_46 * V_47 ,
T_3 V_25 , int V_34 , int V_61 )
{
T_2 * V_27 ;
int V_48 = V_60 | V_61 ;
struct V_1 * V_62 = F_50 ( V_5 , V_34 ) ;
V_27 = F_11 ( & V_5 -> V_6 . V_7 . V_36 , V_34 , V_25 ) ;
F_42 ( V_47 , V_27 , V_25 , V_48 ) ;
if ( V_47 -> V_55 ) {
if ( V_61 & V_58 ) {
if ( V_25 < 4 )
* V_27 |= 0xffff ;
F_51 ( V_62 ) ;
}
F_52 ( V_5 ) ;
return true ;
}
return false ;
}
bool F_53 ( struct V_5 * V_5 ,
struct V_46 * V_47 ,
T_3 V_25 , int V_34 )
{
T_2 * V_27 , V_63 ;
T_2 V_64 ;
int V_48 = V_60 | V_57 ;
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
V_27 = F_11 ( & V_31 -> V_33 , V_34 , V_25 ) ;
V_64 = ( ~ ( * V_27 ) ) ;
V_27 = F_11 ( & V_31 -> V_42 , V_34 , V_25 ) ;
V_63 = * V_27 ;
F_42 ( V_47 , V_27 , V_25 , V_48 ) ;
if ( V_47 -> V_55 ) {
V_27 = F_11 ( & V_31 -> V_40 ,
V_34 , V_25 ) ;
F_42 ( V_47 , V_27 , V_25 , V_48 ) ;
* V_27 &= V_64 ;
if ( V_25 < 2 ) {
* V_27 &= ~ 0xffff ;
* V_27 |= V_63 & 0xffff ;
}
F_52 ( V_5 ) ;
return true ;
}
return false ;
}
bool F_54 ( struct V_5 * V_5 ,
struct V_46 * V_47 ,
T_3 V_25 , int V_34 )
{
T_2 * V_65 ;
T_2 * V_27 , V_63 ;
int V_48 = V_60 | V_58 ;
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
V_27 = F_11 ( & V_31 -> V_42 , V_34 , V_25 ) ;
V_63 = * V_27 ;
F_42 ( V_47 , V_27 , V_25 , V_48 ) ;
if ( V_47 -> V_55 ) {
V_65 = F_11 ( & V_31 -> V_39 ,
V_34 , V_25 ) ;
V_27 = F_11 ( & V_31 -> V_42 , V_34 , V_25 ) ;
* V_27 |= * V_65 ;
if ( V_25 < 2 ) {
* V_27 &= ~ 0xffff ;
* V_27 |= V_63 & 0xffff ;
}
V_27 = F_11 ( & V_31 -> V_40 ,
V_34 , V_25 ) ;
F_42 ( V_47 , V_27 , V_25 , V_48 ) ;
F_52 ( V_5 ) ;
return true ;
}
return false ;
}
bool F_55 ( struct V_5 * V_5 ,
struct V_46 * V_47 ,
T_3 V_25 , int V_34 )
{
T_2 * V_27 ;
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
V_27 = F_11 ( & V_31 -> V_38 , V_34 , V_25 ) ;
F_42 ( V_47 , V_27 , V_25 ,
V_60 | V_57 ) ;
if ( V_47 -> V_55 ) {
F_52 ( V_5 ) ;
return true ;
}
return false ;
}
bool F_56 ( struct V_5 * V_5 ,
struct V_46 * V_47 ,
T_3 V_25 , int V_34 )
{
T_2 * V_27 ;
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
V_27 = F_11 ( & V_31 -> V_38 , V_34 , V_25 ) ;
F_42 ( V_47 , V_27 , V_25 ,
V_60 | V_58 ) ;
if ( V_47 -> V_55 ) {
F_52 ( V_5 ) ;
return true ;
}
return false ;
}
static T_2 F_57 ( T_4 V_20 )
{
T_2 V_66 = 0 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < 16 ; V_67 ++ )
V_66 |= ( ( V_20 >> V_67 ) & V_35 ) << ( 2 * V_67 + 1 ) ;
return V_66 ;
}
static T_4 F_58 ( T_2 V_20 )
{
T_4 V_66 = 0 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < 16 ; V_67 ++ )
V_66 |= ( ( V_20 >> ( V_67 * 2 + 1 ) ) & V_35 ) << V_67 ;
return V_66 ;
}
bool F_59 ( T_2 * V_27 , struct V_46 * V_47 ,
T_3 V_25 )
{
T_2 V_20 ;
if ( V_25 & 4 )
V_20 = * V_27 >> 16 ;
else
V_20 = * V_27 & 0xffff ;
V_20 = F_57 ( V_20 ) ;
F_42 ( V_47 , & V_20 , V_25 ,
V_60 | V_59 ) ;
if ( V_47 -> V_55 ) {
if ( V_25 < 8 )
return false ;
V_20 = F_58 ( V_20 ) ;
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
void F_60 ( struct V_1 * V_2 )
{
struct V_43 * V_43 = & V_2 -> V_6 . V_43 ;
T_1 V_68 = F_61 ( V_2 ) ;
unsigned long * V_69 = F_9 ( & V_68 ) ;
int V_67 ;
F_62 (i, elrsr_ptr, vgic_cpu->nr_lr) {
struct V_70 V_71 = F_63 ( V_2 , V_67 ) ;
F_43 ( ! ( V_71 . V_72 & V_73 ) ) ;
if ( V_71 . V_3 < V_74 )
F_1 ( V_2 , V_71 . V_3 , V_71 . V_4 ) ;
if ( V_71 . V_72 & V_75 )
F_28 ( V_2 , V_71 . V_3 ) ;
F_64 ( V_67 , V_2 ) ;
F_52 ( V_2 -> V_5 ) ;
}
}
const
struct V_76 * F_65 ( const struct V_76 * V_77 ,
int V_51 , T_5 V_25 )
{
while ( V_77 -> V_51 ) {
if ( V_25 >= V_77 -> V_78 &&
( V_25 + V_51 ) <= ( V_77 -> V_78 + V_77 -> V_51 ) )
return V_77 ;
V_77 ++ ;
}
return NULL ;
}
static bool F_66 ( const struct V_30 * V_31 ,
const struct V_76 * V_79 ,
unsigned long V_25 )
{
int V_3 ;
if ( ! V_79 -> V_80 )
return true ;
V_3 = V_25 * 8 / V_79 -> V_80 ;
if ( V_3 >= V_31 -> V_13 )
return false ;
return true ;
}
static bool F_67 ( struct V_1 * V_2 ,
struct V_46 * V_47 ,
unsigned long V_25 ,
const struct V_76 * V_79 )
{
struct V_46 V_81 ;
bool V_82 ;
if ( F_68 ( V_47 -> V_51 <= 4 ) )
return V_79 -> V_83 ( V_2 , V_47 , V_25 ) ;
V_81 . V_51 = 4 ;
V_81 . V_55 = V_47 -> V_55 ;
V_81 . V_16 = V_47 -> V_16 ;
V_81 . V_84 = V_47 -> V_84 + 4 ;
V_81 . V_56 = & ( ( T_2 * ) V_47 -> V_56 ) [ 1 ] ;
V_82 = V_79 -> V_83 ( V_2 , & V_81 , V_25 + 4 ) ;
V_81 . V_84 = V_47 -> V_84 ;
V_81 . V_56 = & ( ( T_2 * ) V_47 -> V_56 ) [ 0 ] ;
V_82 |= V_79 -> V_83 ( V_2 , & V_81 , V_25 ) ;
return V_82 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_85 * V_86 , T_5 V_87 ,
int V_51 , void * V_20 , bool V_55 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
struct V_88 * V_89 = F_70 ( V_86 ,
struct V_88 , V_90 ) ;
struct V_91 * V_92 = V_2 -> V_92 ;
const struct V_76 * V_79 ;
struct V_46 V_47 ;
bool V_93 ;
T_5 V_25 ;
V_25 = V_87 - V_89 -> V_87 ;
V_79 = F_65 ( V_89 -> V_94 , V_51 , V_25 ) ;
if ( F_71 ( ! V_79 || ! V_79 -> V_83 ) ) {
F_72 ( L_1 , V_55 , V_87 , V_51 ) ;
return - V_95 ;
}
V_47 . V_84 = V_87 ;
V_47 . V_51 = V_51 ;
V_47 . V_55 = V_55 ;
V_47 . V_56 = V_20 ;
V_47 . V_16 = V_89 -> V_96 ;
F_73 ( & V_31 -> V_97 ) ;
V_25 -= V_79 -> V_78 ;
if ( F_66 ( V_31 , V_79 , V_25 ) ) {
V_93 = F_67 ( V_2 , & V_47 , V_25 , V_79 ) ;
} else {
if ( ! V_55 )
memset ( V_20 , 0 , V_51 ) ;
V_93 = false ;
}
F_74 ( & V_31 -> V_97 ) ;
V_92 -> V_47 . V_55 = V_55 ;
V_92 -> V_47 . V_51 = V_51 ;
V_92 -> V_47 . V_84 = V_87 ;
memcpy ( V_92 -> V_47 . V_56 , V_20 , V_51 ) ;
F_75 ( V_2 , V_92 ) ;
if ( V_93 )
F_76 ( V_2 -> V_5 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_85 * V_86 ,
T_5 V_87 , int V_51 , void * V_20 )
{
return F_69 ( V_2 , V_86 , V_87 , V_51 , V_20 , false ) ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_85 * V_86 ,
T_5 V_87 , int V_51 , const void * V_20 )
{
return F_69 ( V_2 , V_86 , V_87 , V_51 , ( void * ) V_20 ,
true ) ;
}
int F_79 ( struct V_5 * V_5 , T_5 V_78 , int V_51 ,
const struct V_76 * V_77 ,
int V_98 ,
struct V_88 * V_89 )
{
struct V_1 * V_2 = NULL ;
int V_82 ;
if ( V_98 >= 0 )
V_2 = F_50 ( V_5 , V_98 ) ;
V_89 -> V_87 = V_78 ;
V_89 -> V_51 = V_51 ;
V_89 -> V_94 = V_77 ;
V_89 -> V_96 = V_2 ;
F_80 ( & V_89 -> V_90 , & V_99 ) ;
F_81 ( & V_5 -> V_100 ) ;
V_82 = F_82 ( V_5 , V_101 , V_78 , V_51 ,
& V_89 -> V_90 ) ;
F_83 ( & V_5 -> V_100 ) ;
if ( V_82 )
V_89 -> V_90 . V_102 = NULL ;
return V_82 ;
}
static int F_84 ( struct V_30 * V_31 )
{
return V_31 -> V_13 - V_15 ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
unsigned long * V_103 , * V_104 , * V_105 , * V_106 ;
unsigned long V_107 , V_108 ;
int V_109 = F_84 ( V_31 ) ;
int V_34 ;
V_34 = V_2 -> V_34 ;
V_105 = V_2 -> V_6 . V_43 . V_110 ;
V_106 = V_2 -> V_6 . V_43 . V_108 ;
V_103 = F_17 ( & V_31 -> V_38 , V_34 ) ;
V_104 = F_17 ( & V_31 -> V_36 , V_34 ) ;
F_86 ( V_105 , V_103 , V_104 , V_15 ) ;
V_103 = F_18 ( & V_31 -> V_38 ) ;
V_104 = F_18 ( & V_31 -> V_36 ) ;
F_86 ( V_106 , V_103 , V_104 , V_109 ) ;
F_86 ( V_106 , V_106 ,
F_18 ( & V_31 -> V_111 [ V_34 ] ) ,
V_109 ) ;
V_107 = F_87 ( V_105 , V_15 ) ;
V_108 = F_87 ( V_106 , V_109 ) ;
return ( V_107 < V_15 ||
V_108 < V_109 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
unsigned long * V_112 , * V_104 , * V_113 , * V_114 ;
unsigned long V_115 , V_45 ;
int V_109 = F_84 ( V_31 ) ;
int V_34 ;
V_34 = V_2 -> V_34 ;
V_113 = V_2 -> V_6 . V_43 . V_44 ;
V_114 = V_2 -> V_6 . V_43 . V_45 ;
if ( ! V_31 -> V_104 ) {
F_88 ( V_113 , V_15 ) ;
F_88 ( V_114 , V_109 ) ;
return 0 ;
}
V_112 = F_17 ( & V_31 -> V_42 , V_34 ) ;
V_104 = F_17 ( & V_31 -> V_36 , V_34 ) ;
F_86 ( V_113 , V_112 , V_104 , V_15 ) ;
V_112 = F_18 ( & V_31 -> V_42 ) ;
V_104 = F_18 ( & V_31 -> V_36 ) ;
F_86 ( V_114 , V_112 , V_104 , V_109 ) ;
F_86 ( V_114 , V_114 ,
F_18 ( & V_31 -> V_111 [ V_34 ] ) ,
V_109 ) ;
V_115 = F_87 ( V_113 , V_15 ) ;
V_45 = F_87 ( V_114 , V_109 ) ;
return ( V_115 < V_15 ||
V_45 < F_84 ( V_31 ) ) ;
}
void F_52 ( struct V_5 * V_5 )
{
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
struct V_1 * V_2 ;
int V_116 ;
F_89 (c, vcpu, kvm) {
if ( F_36 ( V_2 ) )
F_15 ( V_116 , V_31 -> V_41 ) ;
if ( F_85 ( V_2 ) )
F_15 ( V_116 , V_31 -> V_117 ) ;
else
F_16 ( V_116 , V_31 -> V_117 ) ;
}
}
static struct V_70 F_63 ( const struct V_1 * V_2 , int V_71 )
{
return V_118 -> V_119 ( V_2 , V_71 ) ;
}
static void F_90 ( struct V_1 * V_2 , int V_71 ,
struct V_70 V_120 )
{
V_118 -> V_121 ( V_2 , V_71 , V_120 ) ;
}
static inline T_1 F_61 ( struct V_1 * V_2 )
{
return V_118 -> V_122 ( V_2 ) ;
}
static inline T_1 F_91 ( struct V_1 * V_2 )
{
return V_118 -> V_123 ( V_2 ) ;
}
static inline void F_92 ( struct V_1 * V_2 )
{
V_118 -> V_124 ( V_2 ) ;
}
static inline T_2 F_93 ( struct V_1 * V_2 )
{
return V_118 -> V_125 ( V_2 ) ;
}
static inline void F_94 ( struct V_1 * V_2 )
{
V_118 -> V_126 ( V_2 ) ;
}
static inline void F_95 ( struct V_1 * V_2 )
{
V_118 -> V_127 ( V_2 ) ;
}
void F_96 ( struct V_1 * V_2 , struct V_128 * V_129 )
{
V_118 -> V_130 ( V_2 , V_129 ) ;
}
void F_97 ( struct V_1 * V_2 , struct V_128 * V_129 )
{
V_118 -> V_131 ( V_2 , V_129 ) ;
}
static inline void F_98 ( struct V_1 * V_2 )
{
V_118 -> V_132 ( V_2 ) ;
}
static void F_64 ( int V_133 , struct V_1 * V_2 )
{
struct V_70 V_120 = F_63 ( V_2 , V_133 ) ;
F_27 ( V_2 , V_120 . V_3 ) ;
if ( V_120 . V_72 & V_134 ) {
F_38 ( V_2 , V_120 . V_3 ) ;
V_120 . V_135 = 0 ;
}
V_120 . V_72 = 0 ;
F_90 ( V_2 , V_133 , V_120 ) ;
}
static bool F_99 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
return F_13 ( V_2 -> V_34 , V_31 -> V_117 ) ;
}
bool F_100 ( struct V_1 * V_2 , struct V_136 * V_137 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_2 -> V_6 . V_43 . V_138 ; V_67 ++ ) {
struct V_70 V_120 = F_63 ( V_2 , V_67 ) ;
if ( V_120 . V_3 == V_137 -> V_139 && V_120 . V_72 & V_75 )
return true ;
}
return F_25 ( V_2 , V_137 -> V_139 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
T_1 V_68 = F_61 ( V_2 ) ;
unsigned long * V_69 = F_9 ( & V_68 ) ;
int V_71 ;
F_62 (lr, elrsr_ptr, vgic->nr_lr) {
struct V_70 V_120 = F_63 ( V_2 , V_71 ) ;
if ( ! F_23 ( V_2 , V_120 . V_3 ) )
F_64 ( V_71 , V_2 ) ;
}
}
static void F_101 ( struct V_1 * V_2 , int V_3 ,
int V_133 , struct V_70 V_120 )
{
if ( F_25 ( V_2 , V_3 ) ) {
V_120 . V_72 |= V_75 ;
F_102 ( L_2 , V_120 . V_72 ) ;
F_29 ( V_2 , V_3 ) ;
F_52 ( V_2 -> V_5 ) ;
} else {
F_103 ( ! F_37 ( V_2 , V_3 ) ) ;
V_120 . V_72 |= V_134 ;
F_102 ( L_3 , V_120 . V_72 ) ;
}
if ( ! F_22 ( V_2 , V_3 ) )
V_120 . V_72 |= V_140 ;
if ( V_120 . V_3 >= V_74 ) {
struct V_136 * V_137 ;
V_137 = F_104 ( V_2 , V_3 ) ;
if ( V_137 ) {
V_120 . V_135 = V_137 -> V_141 ;
V_120 . V_72 |= V_142 ;
V_120 . V_72 &= ~ V_140 ;
F_26 ( V_2 , V_3 ) ;
}
}
F_90 ( V_2 , V_133 , V_120 ) ;
}
bool F_105 ( struct V_1 * V_2 , T_6 V_143 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
T_1 V_68 = F_61 ( V_2 ) ;
unsigned long * V_69 = F_9 ( & V_68 ) ;
struct V_70 V_120 ;
int V_71 ;
F_43 ( V_143 & ~ 7 ) ;
F_43 ( V_143 && V_3 >= V_74 ) ;
F_43 ( V_3 >= V_31 -> V_13 ) ;
F_102 ( L_4 , V_3 ) ;
F_62 (lr, elrsr_ptr, vgic->nr_lr) {
V_120 = F_63 ( V_2 , V_71 ) ;
if ( V_120 . V_3 == V_3 && V_120 . V_4 == V_143 ) {
F_102 ( L_5 , V_71 , V_120 . V_3 ) ;
F_101 ( V_2 , V_3 , V_71 , V_120 ) ;
return true ;
}
}
V_71 = F_87 ( V_69 , V_7 -> V_138 ) ;
if ( V_71 >= V_7 -> V_138 )
return false ;
F_102 ( L_6 , V_71 , V_3 , V_143 ) ;
V_120 . V_3 = V_3 ;
V_120 . V_4 = V_143 ;
V_120 . V_72 = 0 ;
F_101 ( V_2 , V_3 , V_71 , V_120 ) ;
return true ;
}
static bool F_106 ( struct V_1 * V_2 , int V_3 )
{
if ( ! F_41 ( V_2 , V_3 ) )
return true ;
if ( F_105 ( V_2 , 0 , V_3 ) ) {
if ( F_22 ( V_2 , V_3 ) ) {
F_35 ( V_2 , V_3 ) ;
F_40 ( V_2 , V_3 ) ;
} else {
F_26 ( V_2 , V_3 ) ;
}
return true ;
}
return false ;
}
static void F_107 ( struct V_1 * V_2 )
{
struct V_43 * V_43 = & V_2 -> V_6 . V_43 ;
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
unsigned long * V_144 , * V_145 ;
int V_67 , V_34 ;
int V_146 = 0 ;
int V_109 = F_84 ( V_31 ) ;
V_34 = V_2 -> V_34 ;
V_144 = V_2 -> V_6 . V_43 . V_147 ;
V_145 = V_2 -> V_6 . V_43 . V_148 ;
F_108 ( V_144 , V_43 -> V_44 , V_43 -> V_110 ,
V_15 ) ;
F_108 ( V_145 , V_43 -> V_45 , V_43 -> V_108 ,
V_109 ) ;
if ( ! F_109 ( V_2 ) && ! F_99 ( V_2 ) )
goto V_149;
F_110 (i, pa_percpu, VGIC_NR_SGIS) {
if ( ! F_2 ( V_2 , V_67 ) )
V_146 = 1 ;
}
F_111 (i, pa_percpu, VGIC_NR_PRIVATE_IRQS) {
if ( ! F_106 ( V_2 , V_67 ) )
V_146 = 1 ;
}
F_110 (i, pa_shared, nr_shared) {
if ( ! F_106 ( V_2 , V_67 + V_15 ) )
V_146 = 1 ;
}
V_149:
if ( V_146 ) {
F_94 ( V_2 ) ;
} else {
F_95 ( V_2 ) ;
F_16 ( V_34 , V_31 -> V_41 ) ;
}
}
static int F_112 ( struct V_1 * V_2 ,
int V_71 , struct V_70 V_120 )
{
int V_112 = 0 ;
F_34 ( V_2 , V_120 . V_3 ) ;
F_27 ( V_2 , V_120 . V_3 ) ;
if ( F_22 ( V_2 , V_120 . V_3 ) ) {
F_43 ( ! ( V_120 . V_72 & V_142 ) ) ;
V_112 = F_37 ( V_2 , V_120 . V_3 ) ;
} else {
if ( F_30 ( V_2 , V_120 . V_3 ) ) {
F_39 ( V_2 , V_120 . V_3 ) ;
V_112 = 1 ;
} else {
F_35 ( V_2 , V_120 . V_3 ) ;
F_40 ( V_2 , V_120 . V_3 ) ;
}
}
V_120 . V_72 = 0 ;
V_120 . V_135 = 0 ;
F_90 ( V_2 , V_71 , V_120 ) ;
return V_112 ;
}
static bool F_113 ( struct V_1 * V_2 )
{
T_2 V_150 = F_93 ( V_2 ) ;
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
struct V_5 * V_5 = V_2 -> V_5 ;
int V_151 = 0 ;
F_102 ( L_7 , V_150 ) ;
if ( V_150 & V_152 ) {
T_1 V_153 = F_91 ( V_2 ) ;
unsigned long * V_154 = F_9 ( & V_153 ) ;
int V_71 ;
F_110 (lr, eisr_ptr, vgic->nr_lr) {
struct V_70 V_120 = F_63 ( V_2 , V_71 ) ;
F_103 ( F_22 ( V_2 , V_120 . V_3 ) ) ;
F_103 ( V_120 . V_72 & V_73 ) ;
F_114 ( V_5 , 0 ,
V_120 . V_3 - V_15 ) ;
F_73 ( & V_31 -> V_97 ) ;
V_151 |= F_112 ( V_2 , V_71 , V_120 ) ;
F_74 ( & V_31 -> V_97 ) ;
}
}
if ( V_150 & V_155 )
F_95 ( V_2 ) ;
F_92 ( V_2 ) ;
return V_151 ;
}
static bool F_115 ( struct V_1 * V_2 , int V_71 , struct V_70 V_120 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
bool V_151 ;
if ( ! ( V_120 . V_72 & V_142 ) )
return false ;
if ( V_120 . V_72 & V_75 )
return false ;
F_73 ( & V_31 -> V_97 ) ;
V_151 = F_112 ( V_2 , V_71 , V_120 ) ;
F_74 ( & V_31 -> V_97 ) ;
return V_151 ;
}
static void F_116 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
T_1 V_68 ;
unsigned long * V_69 ;
int V_71 , V_112 ;
bool V_151 ;
V_151 = F_113 ( V_2 ) ;
for ( V_71 = 0 ; V_71 < V_7 -> V_138 ; V_71 ++ ) {
struct V_70 V_120 = F_63 ( V_2 , V_71 ) ;
V_151 |= F_115 ( V_2 , V_71 , V_120 ) ;
F_43 ( V_120 . V_3 >= V_31 -> V_13 ) ;
}
V_68 = F_61 ( V_2 ) ;
V_69 = F_9 ( & V_68 ) ;
V_112 = F_117 ( V_69 , V_7 -> V_138 ) ;
if ( V_151 || V_112 < V_7 -> V_138 )
F_15 ( V_2 -> V_34 , V_31 -> V_41 ) ;
}
void F_118 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
if ( ! F_119 ( V_2 -> V_5 ) )
return;
F_73 ( & V_31 -> V_97 ) ;
F_107 ( V_2 ) ;
F_74 ( & V_31 -> V_97 ) ;
}
void F_120 ( struct V_1 * V_2 )
{
if ( ! F_119 ( V_2 -> V_5 ) )
return;
F_116 ( V_2 ) ;
}
int F_109 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
if ( ! F_119 ( V_2 -> V_5 ) )
return 0 ;
return F_13 ( V_2 -> V_34 , V_31 -> V_41 ) ;
}
void F_76 ( struct V_5 * V_5 )
{
struct V_1 * V_2 ;
int V_116 ;
F_89 (c, vcpu, kvm) {
if ( F_109 ( V_2 ) )
F_121 ( V_2 ) ;
}
}
static int F_122 ( struct V_1 * V_2 , int V_3 , int V_156 )
{
int V_157 = F_22 ( V_2 , V_3 ) ;
if ( V_157 ) {
int V_72 = F_37 ( V_2 , V_3 ) ;
return V_156 > V_72 ;
} else {
int V_72 = F_30 ( V_2 , V_3 ) ;
return V_156 != V_72 ;
}
}
static int F_123 ( struct V_5 * V_5 , int V_24 ,
struct V_136 * V_137 ,
unsigned int V_158 , bool V_156 )
{
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
struct V_1 * V_2 ;
int V_157 , V_159 ;
int V_104 ;
bool V_82 = true , V_160 = true ;
F_124 ( V_24 , V_158 , V_156 ) ;
if ( V_158 >= F_125 ( V_5 -> V_6 . V_7 . V_13 , 1020 ) )
return - V_161 ;
F_73 ( & V_31 -> V_97 ) ;
V_2 = F_50 ( V_5 , V_24 ) ;
V_157 = F_22 ( V_2 , V_158 ) ;
V_159 = ! V_157 ;
if ( ! F_122 ( V_2 , V_158 , V_156 ) ) {
V_82 = false ;
goto V_162;
}
if ( V_158 >= V_15 ) {
V_24 = V_31 -> V_163 [ V_158 - V_15 ] ;
if ( V_24 == V_164 ) {
V_24 = 0 ;
V_160 = false ;
}
V_2 = F_50 ( V_5 , V_24 ) ;
}
F_102 ( L_8 , V_158 , V_156 , V_24 ) ;
if ( V_156 ) {
if ( V_159 )
F_31 ( V_2 , V_158 ) ;
F_38 ( V_2 , V_158 ) ;
} else {
if ( V_159 ) {
F_32 ( V_2 , V_158 ) ;
if ( ! F_33 ( V_2 , V_158 ) ) {
F_35 ( V_2 , V_158 ) ;
F_40 ( V_2 , V_158 ) ;
if ( ! F_36 ( V_2 ) )
F_16 ( V_24 , V_31 -> V_41 ) ;
}
}
V_82 = false ;
goto V_162;
}
V_104 = F_23 ( V_2 , V_158 ) ;
if ( ! V_104 || ! V_160 ) {
V_82 = false ;
goto V_162;
}
if ( ! F_41 ( V_2 , V_158 ) ) {
V_82 = false ;
goto V_162;
}
if ( V_156 ) {
F_39 ( V_2 , V_158 ) ;
F_15 ( V_24 , V_31 -> V_41 ) ;
}
V_162:
F_74 ( & V_31 -> V_97 ) ;
if ( V_82 ) {
F_121 ( F_50 ( V_5 , V_24 ) ) ;
}
return 0 ;
}
static int F_126 ( struct V_5 * V_5 )
{
int V_82 = 0 ;
if ( F_71 ( ! F_127 ( V_5 ) ) ) {
if ( V_5 -> V_6 . V_7 . V_165 != V_166 )
return - V_167 ;
F_81 ( & V_5 -> V_97 ) ;
V_82 = F_128 ( V_5 ) ;
F_83 ( & V_5 -> V_97 ) ;
}
return V_82 ;
}
int F_129 ( struct V_5 * V_5 , int V_24 , unsigned int V_158 ,
bool V_156 )
{
struct V_136 * V_137 ;
int V_82 ;
V_82 = F_126 ( V_5 ) ;
if ( V_82 )
return V_82 ;
V_137 = F_104 ( F_50 ( V_5 , V_24 ) , V_158 ) ;
if ( V_137 )
return - V_161 ;
return F_123 ( V_5 , V_24 , NULL , V_158 , V_156 ) ;
}
int F_130 ( struct V_5 * V_5 , int V_24 ,
struct V_136 * V_137 , bool V_156 )
{
int V_82 ;
V_82 = F_126 ( V_5 ) ;
if ( V_82 )
return V_82 ;
return F_123 ( V_5 , V_24 , V_137 , V_137 -> V_139 , V_156 ) ;
}
static T_7 F_131 ( int V_3 , void * V_56 )
{
return V_168 ;
}
static struct V_169 * F_132 ( struct V_1 * V_2 ,
int V_139 )
{
if ( V_139 < V_15 )
return & V_2 -> V_6 . V_43 . V_170 ;
else
return & V_2 -> V_5 -> V_6 . V_7 . V_170 ;
}
struct V_136 * F_133 ( struct V_1 * V_2 ,
int V_139 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
struct V_169 * V_171 = F_132 ( V_2 , V_139 ) ;
struct V_136 * V_137 ;
struct V_172 * V_173 ;
struct V_174 * V_175 ;
struct V_176 * V_56 ;
int V_141 ;
V_175 = F_134 ( V_3 ) ;
if ( ! V_175 ) {
F_135 ( L_9 , V_177 ) ;
return F_136 ( - V_161 ) ;
}
V_56 = F_137 ( V_175 ) ;
while ( V_56 -> V_178 )
V_56 = V_56 -> V_178 ;
V_141 = V_56 -> V_135 ;
V_173 = F_6 ( sizeof( * V_173 ) , V_17 ) ;
if ( ! V_173 )
return F_136 ( - V_18 ) ;
F_73 ( & V_31 -> V_179 ) ;
V_137 = F_104 ( V_2 , V_139 ) ;
if ( V_137 ) {
if ( V_137 -> V_141 != V_141 ||
V_137 -> V_3 != V_3 )
V_137 = F_136 ( - V_161 ) ;
goto V_162;
}
V_137 = & V_173 -> V_137 ;
V_137 -> V_139 = V_139 ;
V_137 -> V_141 = V_141 ;
V_137 -> V_3 = V_3 ;
F_138 ( & V_173 -> V_173 , V_171 ) ;
V_162:
F_74 ( & V_31 -> V_179 ) ;
if ( F_139 ( V_137 ) || V_137 != & V_173 -> V_137 )
F_8 ( V_173 ) ;
return V_137 ;
}
static struct V_136 * F_104 ( struct V_1 * V_2 ,
int V_139 )
{
struct V_169 * V_171 = F_132 ( V_2 , V_139 ) ;
struct V_172 * V_173 ;
struct V_136 * V_137 ;
F_140 () ;
F_141 (entry, root, entry) {
V_137 = & V_173 -> V_137 ;
if ( V_137 -> V_139 == V_139 ) {
F_142 () ;
return V_137 ;
}
}
F_142 () ;
return NULL ;
}
static void F_143 ( struct V_180 * V_181 )
{
struct V_172 * V_173 ;
V_173 = F_70 ( V_181 , struct V_172 , V_181 ) ;
F_8 ( V_173 ) ;
}
int F_144 ( struct V_1 * V_2 , struct V_136 * V_137 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
struct V_172 * V_173 ;
struct V_169 * V_171 ;
if ( ! V_137 )
return - V_161 ;
V_171 = F_132 ( V_2 , V_137 -> V_139 ) ;
F_73 ( & V_31 -> V_179 ) ;
F_145 (entry, root, entry) {
if ( & V_173 -> V_137 == V_137 ) {
F_146 ( & V_173 -> V_173 ) ;
F_147 ( & V_173 -> V_181 , F_143 ) ;
break;
}
}
F_74 ( & V_31 -> V_179 ) ;
return 0 ;
}
static void F_148 ( struct V_5 * V_5 , struct V_169 * V_171 )
{
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
struct V_172 * V_173 ;
F_73 ( & V_31 -> V_179 ) ;
F_145 (entry, root, entry) {
F_146 ( & V_173 -> V_173 ) ;
F_147 ( & V_173 -> V_181 , F_143 ) ;
}
F_74 ( & V_31 -> V_179 ) ;
}
void F_149 ( struct V_1 * V_2 )
{
struct V_43 * V_43 = & V_2 -> V_6 . V_43 ;
F_8 ( V_43 -> V_45 ) ;
F_8 ( V_43 -> V_108 ) ;
F_8 ( V_43 -> V_148 ) ;
F_148 ( V_2 -> V_5 , & V_43 -> V_170 ) ;
V_43 -> V_45 = NULL ;
V_43 -> V_108 = NULL ;
V_43 -> V_148 = NULL ;
}
static int F_150 ( struct V_1 * V_2 , int V_13 )
{
struct V_43 * V_43 = & V_2 -> V_6 . V_43 ;
int V_14 = F_5 ( V_13 - V_15 ) ;
int V_182 = V_14 * sizeof( unsigned long ) ;
V_43 -> V_45 = F_6 ( V_182 , V_17 ) ;
V_43 -> V_108 = F_6 ( V_182 , V_17 ) ;
V_43 -> V_148 = F_6 ( V_182 , V_17 ) ;
if ( ! V_43 -> V_45
|| ! V_43 -> V_108
|| ! V_43 -> V_148 ) {
F_149 ( V_2 ) ;
return - V_18 ;
}
V_43 -> V_138 = V_7 -> V_138 ;
return 0 ;
}
void F_151 ( struct V_1 * V_2 )
{
struct V_43 * V_43 = & V_2 -> V_6 . V_43 ;
F_152 ( & V_43 -> V_170 ) ;
}
int F_153 ( void )
{
return V_7 -> V_183 ;
}
void F_154 ( struct V_5 * V_5 )
{
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
struct V_1 * V_2 ;
int V_67 ;
F_89 (i, vcpu, kvm)
F_149 ( V_2 ) ;
F_7 ( & V_31 -> V_36 ) ;
F_7 ( & V_31 -> V_39 ) ;
F_7 ( & V_31 -> V_42 ) ;
F_7 ( & V_31 -> V_40 ) ;
F_7 ( & V_31 -> V_37 ) ;
F_7 ( & V_31 -> V_33 ) ;
F_20 ( & V_31 -> V_184 ) ;
if ( V_31 -> V_111 ) {
for ( V_67 = 0 ; V_67 < V_31 -> V_12 ; V_67 ++ )
F_7 ( & V_31 -> V_111 [ V_67 ] ) ;
}
F_8 ( V_31 -> V_185 ) ;
F_8 ( V_31 -> V_163 ) ;
F_8 ( V_31 -> V_186 ) ;
F_8 ( V_31 -> V_111 ) ;
F_8 ( V_31 -> V_41 ) ;
F_8 ( V_31 -> V_117 ) ;
F_148 ( V_5 , & V_31 -> V_170 ) ;
V_31 -> V_185 = NULL ;
V_31 -> V_163 = NULL ;
V_31 -> V_111 = NULL ;
V_31 -> V_41 = NULL ;
V_31 -> V_117 = NULL ;
V_31 -> V_12 = 0 ;
}
int F_128 ( struct V_5 * V_5 )
{
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
struct V_1 * V_2 ;
int V_12 , V_13 ;
int V_82 , V_67 , V_34 ;
if ( F_127 ( V_5 ) )
return 0 ;
V_12 = V_31 -> V_12 = F_155 ( & V_5 -> V_187 ) ;
if ( ! V_12 )
return - V_188 ;
if ( ! V_31 -> V_13 )
V_31 -> V_13 = V_189 ;
V_13 = V_31 -> V_13 ;
V_82 = F_4 ( & V_31 -> V_36 , V_12 , V_13 ) ;
V_82 |= F_4 ( & V_31 -> V_39 , V_12 , V_13 ) ;
V_82 |= F_4 ( & V_31 -> V_42 , V_12 , V_13 ) ;
V_82 |= F_4 ( & V_31 -> V_40 , V_12 , V_13 ) ;
V_82 |= F_4 ( & V_31 -> V_37 , V_12 , V_13 ) ;
V_82 |= F_4 ( & V_31 -> V_38 , V_12 , V_13 ) ;
V_82 |= F_4 ( & V_31 -> V_33 , V_12 , V_13 ) ;
V_82 |= F_19 ( & V_31 -> V_184 , V_12 , V_13 ) ;
if ( V_82 )
goto V_162;
V_31 -> V_185 = F_6 ( V_12 * V_74 , V_17 ) ;
V_31 -> V_163 = F_6 ( V_13 - V_15 , V_17 ) ;
V_31 -> V_111 = F_6 ( sizeof( * V_31 -> V_111 ) * V_12 ,
V_17 ) ;
V_31 -> V_41 = F_6 ( F_5 ( V_12 ) * sizeof( long ) ,
V_17 ) ;
V_31 -> V_117 = F_6 ( F_5 ( V_12 ) * sizeof( long ) ,
V_17 ) ;
if ( ! V_31 -> V_185 ||
! V_31 -> V_163 ||
! V_31 -> V_111 ||
! V_31 -> V_41 ||
! V_31 -> V_117 ) {
V_82 = - V_18 ;
goto V_162;
}
for ( V_67 = 0 ; V_67 < V_12 ; V_67 ++ )
V_82 |= F_4 ( & V_31 -> V_111 [ V_67 ] ,
V_12 , V_13 ) ;
if ( V_82 )
goto V_162;
V_82 = V_5 -> V_6 . V_7 . V_8 . V_190 ( V_5 ) ;
if ( V_82 )
goto V_162;
F_89 (vcpu_id, vcpu, kvm) {
V_82 = F_150 ( V_2 , V_13 ) ;
if ( V_82 ) {
F_135 ( L_10 ) ;
break;
}
for ( V_67 = 0 ; V_67 < V_15 ; V_67 ++ ) {
if ( V_67 < V_74 ) {
F_14 ( & V_31 -> V_36 ,
V_2 -> V_34 , V_67 , 1 ) ;
F_14 ( & V_31 -> V_33 ,
V_2 -> V_34 , V_67 ,
V_35 ) ;
} else if ( V_67 < V_15 ) {
F_14 ( & V_31 -> V_33 ,
V_2 -> V_34 , V_67 ,
V_191 ) ;
}
}
F_98 ( V_2 ) ;
}
V_162:
if ( V_82 )
F_154 ( V_5 ) ;
return V_82 ;
}
static int F_156 ( struct V_5 * V_5 , int type )
{
switch ( type ) {
case V_166 :
F_157 ( V_5 ) ;
break;
#ifdef F_158
case V_192 :
F_159 ( V_5 ) ;
break;
#endif
default:
return - V_188 ;
}
if ( F_155 ( & V_5 -> V_187 ) > V_5 -> V_6 . V_193 )
return - V_194 ;
return 0 ;
}
void F_160 ( struct V_5 * V_5 )
{
F_161 ( & V_5 -> V_6 . V_7 . V_97 ) ;
F_161 ( & V_5 -> V_6 . V_7 . V_179 ) ;
F_152 ( & V_5 -> V_6 . V_7 . V_170 ) ;
}
int F_162 ( struct V_5 * V_5 , T_2 type )
{
int V_67 , V_195 = - 1 , V_82 ;
struct V_1 * V_2 ;
F_81 ( & V_5 -> V_97 ) ;
if ( F_119 ( V_5 ) ) {
V_82 = - V_196 ;
goto V_162;
}
if ( type == V_166 && ! V_7 -> V_197 ) {
V_82 = - V_188 ;
goto V_162;
}
V_82 = - V_167 ;
F_89 (i, vcpu, kvm) {
if ( ! F_163 ( & V_2 -> V_198 ) )
goto V_199;
V_195 = V_67 ;
}
F_89 (i, vcpu, kvm) {
if ( V_2 -> V_6 . V_200 )
goto V_199;
}
V_82 = 0 ;
V_82 = F_156 ( V_5 , type ) ;
if ( V_82 )
goto V_199;
V_5 -> V_6 . V_7 . V_201 = true ;
V_5 -> V_6 . V_7 . V_165 = type ;
V_5 -> V_6 . V_7 . V_202 = V_7 -> V_202 ;
V_5 -> V_6 . V_7 . V_203 = V_204 ;
V_5 -> V_6 . V_7 . V_205 = V_204 ;
V_5 -> V_6 . V_7 . V_206 = V_204 ;
V_199:
for (; V_195 >= 0 ; V_195 -- ) {
V_2 = F_50 ( V_5 , V_195 ) ;
F_83 ( & V_2 -> V_198 ) ;
}
V_162:
F_83 ( & V_5 -> V_97 ) ;
return V_82 ;
}
static int F_164 ( struct V_5 * V_5 )
{
T_3 V_31 = V_5 -> V_6 . V_7 . V_203 ;
T_3 V_207 = V_5 -> V_6 . V_7 . V_205 ;
if ( F_165 ( V_31 ) || F_165 ( V_207 ) )
return 0 ;
if ( ( V_31 <= V_207 && V_31 + V_208 > V_207 ) ||
( V_207 <= V_31 && V_207 + V_209 > V_31 ) )
return - V_167 ;
return 0 ;
}
static int F_166 ( struct V_5 * V_5 , T_3 * V_210 ,
T_3 V_87 , T_3 V_29 )
{
int V_82 ;
if ( V_87 & ~ V_211 )
return - V_194 ;
if ( V_87 & ( V_212 - 1 ) )
return - V_161 ;
if ( ! F_165 ( * V_210 ) )
return - V_196 ;
if ( V_87 + V_29 < V_87 )
return - V_161 ;
* V_210 = V_87 ;
V_82 = F_164 ( V_5 ) ;
if ( V_82 )
* V_210 = V_204 ;
return V_82 ;
}
int F_167 ( struct V_5 * V_5 , unsigned long type , T_1 * V_87 , bool V_213 )
{
int V_214 = 0 ;
struct V_30 * V_7 = & V_5 -> V_6 . V_7 ;
int V_215 ;
T_3 * V_216 , V_217 ;
T_3 V_218 ;
F_81 ( & V_5 -> V_97 ) ;
switch ( type ) {
case V_219 :
V_215 = V_166 ;
V_216 = & V_7 -> V_203 ;
V_217 = V_208 ;
V_218 = V_212 ;
break;
case V_220 :
V_215 = V_166 ;
V_216 = & V_7 -> V_205 ;
V_217 = V_209 ;
V_218 = V_212 ;
break;
#ifdef F_158
case V_221 :
V_215 = V_192 ;
V_216 = & V_7 -> V_203 ;
V_217 = V_222 ;
V_218 = V_223 ;
break;
case V_224 :
V_215 = V_192 ;
V_216 = & V_7 -> V_206 ;
V_217 = V_225 ;
V_218 = V_223 ;
break;
#endif
default:
V_214 = - V_188 ;
goto V_162;
}
if ( V_7 -> V_165 != V_215 ) {
V_214 = - V_188 ;
goto V_162;
}
if ( V_213 ) {
if ( ! F_168 ( * V_87 , V_218 ) )
V_214 = - V_161 ;
else
V_214 = F_166 ( V_5 , V_216 , * V_87 ,
V_217 ) ;
} else {
* V_87 = * V_216 ;
}
V_162:
F_83 ( & V_5 -> V_97 ) ;
return V_214 ;
}
int F_169 ( struct V_226 * V_90 , struct V_227 * V_228 )
{
int V_214 ;
switch ( V_228 -> V_229 ) {
case V_230 : {
T_1 T_8 * V_231 = ( T_1 T_8 * ) ( long ) V_228 -> V_87 ;
T_1 V_87 ;
unsigned long type = ( unsigned long ) V_228 -> V_228 ;
if ( F_170 ( & V_87 , V_231 , sizeof( V_87 ) ) )
return - V_232 ;
V_214 = F_167 ( V_90 -> V_5 , type , & V_87 , true ) ;
return ( V_214 == - V_188 ) ? - V_95 : V_214 ;
}
case V_233 : {
T_2 T_8 * V_231 = ( T_2 T_8 * ) ( long ) V_228 -> V_87 ;
T_2 V_20 ;
int V_82 = 0 ;
if ( F_171 ( V_20 , V_231 ) )
return - V_232 ;
if ( V_20 < ( V_15 + 32 ) ||
V_20 > V_234 ||
( V_20 & 31 ) )
return - V_161 ;
F_81 ( & V_90 -> V_5 -> V_97 ) ;
if ( F_172 ( V_90 -> V_5 ) || V_90 -> V_5 -> V_6 . V_7 . V_13 )
V_82 = - V_167 ;
else
V_90 -> V_5 -> V_6 . V_7 . V_13 = V_20 ;
F_83 ( & V_90 -> V_5 -> V_97 ) ;
return V_82 ;
}
case V_235 : {
switch ( V_228 -> V_228 ) {
case V_236 :
V_214 = F_128 ( V_90 -> V_5 ) ;
return V_214 ;
}
break;
}
}
return - V_95 ;
}
int F_173 ( struct V_226 * V_90 , struct V_227 * V_228 )
{
int V_214 = - V_95 ;
switch ( V_228 -> V_229 ) {
case V_230 : {
T_1 T_8 * V_231 = ( T_1 T_8 * ) ( long ) V_228 -> V_87 ;
T_1 V_87 ;
unsigned long type = ( unsigned long ) V_228 -> V_228 ;
V_214 = F_167 ( V_90 -> V_5 , type , & V_87 , false ) ;
if ( V_214 )
return ( V_214 == - V_188 ) ? - V_95 : V_214 ;
if ( F_174 ( V_231 , & V_87 , sizeof( V_87 ) ) )
return - V_232 ;
break;
}
case V_233 : {
T_2 T_8 * V_231 = ( T_2 T_8 * ) ( long ) V_228 -> V_87 ;
V_214 = F_175 ( V_90 -> V_5 -> V_6 . V_7 . V_13 , V_231 ) ;
break;
}
}
return V_214 ;
}
int F_176 ( const struct V_76 * V_77 , T_3 V_25 )
{
if ( F_65 ( V_77 , 4 , V_25 ) )
return 0 ;
else
return - V_95 ;
}
static void F_177 ( void * V_237 )
{
F_178 ( V_7 -> V_238 , 0 ) ;
}
static int F_179 ( struct V_239 * V_240 ,
unsigned long V_241 , void * V_207 )
{
switch ( V_241 ) {
case V_242 :
case V_243 :
F_177 ( NULL ) ;
break;
case V_244 :
case V_245 :
F_180 ( V_7 -> V_238 ) ;
break;
}
return V_246 ;
}
int F_181 ( void )
{
const struct V_247 * V_248 ;
const int (* F_182)( struct V_249 * , const struct V_118 * * ,
const struct V_250 * * );
struct V_249 * V_251 ;
int V_82 ;
V_251 = F_183 ( NULL ,
V_252 , & V_248 ) ;
if ( ! V_251 ) {
F_135 ( L_11 ) ;
return - V_188 ;
}
F_182 = V_248 -> V_56 ;
V_82 = F_182 ( V_251 , & V_118 , & V_7 ) ;
if ( V_82 )
return V_82 ;
V_82 = F_184 ( V_7 -> V_238 , F_131 ,
L_12 , F_185 () ) ;
if ( V_82 ) {
F_135 ( L_13 , V_7 -> V_238 ) ;
return V_82 ;
}
V_82 = F_186 ( & V_253 ) ;
if ( V_82 ) {
F_135 ( L_14 ) ;
goto V_254;
}
F_187 ( F_177 , NULL , 1 ) ;
return 0 ;
V_254:
F_188 ( V_7 -> V_238 , F_185 () ) ;
return V_82 ;
}
int F_189 ( struct V_5 * V_5 ,
struct V_255 * V_256 ,
int V_257 )
{
return 0 ;
}
int F_190 ( struct V_5 * V_5 , unsigned V_258 , unsigned V_259 )
{
return V_259 ;
}
int F_191 ( struct V_5 * V_5 , int V_260 ,
T_2 V_3 , int V_156 , bool V_261 )
{
unsigned int V_262 = V_3 + V_15 ;
F_192 ( V_3 , V_156 , V_260 ) ;
F_43 ( ! F_127 ( V_5 ) ) ;
return F_129 ( V_5 , 0 , V_262 , V_156 ) ;
}
int F_193 ( struct V_255 * V_263 ,
struct V_5 * V_5 , int V_260 ,
int V_156 , bool V_261 )
{
return 0 ;
}

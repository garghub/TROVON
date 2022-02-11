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
static void F_25 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
F_14 ( & V_31 -> V_37 , V_2 -> V_34 , V_3 , 1 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
F_14 ( & V_31 -> V_37 , V_2 -> V_34 , V_3 , 0 ) ;
}
static int F_27 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
return F_12 ( & V_31 -> V_38 , V_2 -> V_34 , V_3 ) ;
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
F_14 ( & V_31 -> V_39 , V_2 -> V_34 , V_3 , 0 ) ;
}
static int F_32 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
return F_12 ( & V_31 -> V_40 , V_2 -> V_34 , V_3 ) ;
}
void F_33 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
F_14 ( & V_31 -> V_40 , V_2 -> V_34 , V_3 , 1 ) ;
}
void F_34 ( struct V_1 * V_2 , int V_3 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
F_14 ( & V_31 -> V_40 , V_2 -> V_34 , V_3 , 0 ) ;
}
static void F_35 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 < V_15 )
F_15 ( V_3 , V_2 -> V_6 . V_41 . V_42 ) ;
else
F_15 ( V_3 - V_15 ,
V_2 -> V_6 . V_41 . V_43 ) ;
}
void F_36 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 < V_15 )
F_16 ( V_3 , V_2 -> V_6 . V_41 . V_42 ) ;
else
F_16 ( V_3 - V_15 ,
V_2 -> V_6 . V_41 . V_43 ) ;
}
static bool F_37 ( struct V_1 * V_2 , int V_3 )
{
return F_22 ( V_2 , V_3 ) || ! F_24 ( V_2 , V_3 ) ;
}
void F_38 ( struct V_44 * V_45 , T_2 * V_27 ,
T_3 V_25 , int V_46 )
{
int V_47 = ( V_25 & 3 ) * 8 ;
T_2 V_48 = ( 1UL << ( V_45 -> V_49 * 8 ) ) - 1 ;
T_2 V_50 ;
if ( V_27 ) {
V_50 = * V_27 ;
} else {
F_39 ( V_46 != ( V_51 | V_52 ) ) ;
V_50 = 0 ;
}
if ( V_45 -> V_53 ) {
T_2 V_54 = F_40 ( V_45 , V_48 ) << V_47 ;
switch ( F_41 ( V_46 ) ) {
case V_52 :
return;
case V_55 :
V_50 |= V_54 ;
break;
case V_56 :
V_50 &= ~ V_54 ;
break;
case V_57 :
V_50 = ( V_50 & ~ ( V_48 << V_47 ) ) | V_54 ;
break;
}
* V_27 = V_50 ;
} else {
switch ( F_42 ( V_46 ) ) {
case V_51 :
V_50 = 0 ;
case V_58 :
F_43 ( V_45 , V_48 , V_50 >> V_47 ) ;
}
}
}
bool F_44 ( struct V_1 * V_2 , struct V_44 * V_45 ,
T_3 V_25 )
{
F_38 ( V_45 , NULL , V_25 ,
V_51 | V_52 ) ;
return false ;
}
bool F_45 ( struct V_5 * V_5 , struct V_44 * V_45 ,
T_3 V_25 , int V_34 , int V_59 )
{
T_2 * V_27 ;
int V_46 = V_58 | V_59 ;
struct V_1 * V_60 = F_46 ( V_5 , V_34 ) ;
V_27 = F_11 ( & V_5 -> V_6 . V_7 . V_36 , V_34 , V_25 ) ;
F_38 ( V_45 , V_27 , V_25 , V_46 ) ;
if ( V_45 -> V_53 ) {
if ( V_59 & V_56 ) {
if ( V_25 < 4 )
* V_27 |= 0xffff ;
F_47 ( V_60 ) ;
}
F_48 ( V_5 ) ;
return true ;
}
return false ;
}
bool F_49 ( struct V_5 * V_5 ,
struct V_44 * V_45 ,
T_3 V_25 , int V_34 )
{
T_2 * V_27 , V_61 ;
T_2 V_62 ;
int V_46 = V_58 | V_55 ;
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
V_27 = F_11 ( & V_31 -> V_33 , V_34 , V_25 ) ;
V_62 = ( ~ ( * V_27 ) ) ;
V_27 = F_11 ( & V_31 -> V_40 , V_34 , V_25 ) ;
V_61 = * V_27 ;
F_38 ( V_45 , V_27 , V_25 , V_46 ) ;
if ( V_45 -> V_53 ) {
V_27 = F_11 ( & V_31 -> V_39 ,
V_34 , V_25 ) ;
F_38 ( V_45 , V_27 , V_25 , V_46 ) ;
* V_27 &= V_62 ;
if ( V_25 < 2 ) {
* V_27 &= ~ 0xffff ;
* V_27 |= V_61 & 0xffff ;
}
F_48 ( V_5 ) ;
return true ;
}
return false ;
}
bool F_50 ( struct V_5 * V_5 ,
struct V_44 * V_45 ,
T_3 V_25 , int V_34 )
{
T_2 * V_63 ;
T_2 * V_27 , V_61 ;
int V_46 = V_58 | V_56 ;
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
V_27 = F_11 ( & V_31 -> V_40 , V_34 , V_25 ) ;
V_61 = * V_27 ;
F_38 ( V_45 , V_27 , V_25 , V_46 ) ;
if ( V_45 -> V_53 ) {
V_63 = F_11 ( & V_31 -> V_38 ,
V_34 , V_25 ) ;
V_27 = F_11 ( & V_31 -> V_40 , V_34 , V_25 ) ;
* V_27 |= * V_63 ;
if ( V_25 < 2 ) {
* V_27 &= ~ 0xffff ;
* V_27 |= V_61 & 0xffff ;
}
V_27 = F_11 ( & V_31 -> V_39 ,
V_34 , V_25 ) ;
F_38 ( V_45 , V_27 , V_25 , V_46 ) ;
F_48 ( V_5 ) ;
return true ;
}
return false ;
}
static T_2 F_51 ( T_4 V_20 )
{
T_2 V_64 = 0 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < 16 ; V_65 ++ )
V_64 |= ( ( V_20 >> V_65 ) & V_35 ) << ( 2 * V_65 + 1 ) ;
return V_64 ;
}
static T_4 F_52 ( T_2 V_20 )
{
T_4 V_64 = 0 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < 16 ; V_65 ++ )
V_64 |= ( ( V_20 >> ( V_65 * 2 + 1 ) ) & V_35 ) << V_65 ;
return V_64 ;
}
bool F_53 ( T_2 * V_27 , struct V_44 * V_45 ,
T_3 V_25 )
{
T_2 V_20 ;
if ( V_25 & 4 )
V_20 = * V_27 >> 16 ;
else
V_20 = * V_27 & 0xffff ;
V_20 = F_51 ( V_20 ) ;
F_38 ( V_45 , & V_20 , V_25 ,
V_58 | V_57 ) ;
if ( V_45 -> V_53 ) {
if ( V_25 < 8 ) {
* V_27 = ~ 0U ;
return false ;
}
V_20 = F_52 ( V_20 ) ;
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
void F_54 ( struct V_1 * V_2 )
{
struct V_41 * V_41 = & V_2 -> V_6 . V_41 ;
int V_65 ;
F_55 (i, vgic_cpu->lr_used, vgic_cpu->nr_lr) {
struct V_66 V_67 = F_56 ( V_2 , V_65 ) ;
if ( ( V_67 . V_68 & V_69 ) == V_70 )
continue;
F_33 ( V_2 , V_67 . V_3 ) ;
if ( V_67 . V_3 < V_71 )
F_1 ( V_2 , V_67 . V_3 , V_67 . V_4 ) ;
V_67 . V_68 &= ~ V_72 ;
F_57 ( V_2 , V_65 , V_67 ) ;
if ( ! ( V_67 . V_68 & V_69 ) ) {
F_58 ( V_65 , V_67 . V_3 , V_2 ) ;
F_26 ( V_2 , V_67 . V_3 ) ;
}
F_48 ( V_2 -> V_5 ) ;
}
}
const
struct V_73 * F_59 ( const struct V_73 * V_74 ,
struct V_44 * V_45 ,
T_3 V_25 )
{
const struct V_73 * V_75 = V_74 ;
while ( V_75 -> V_49 ) {
if ( V_25 >= V_75 -> V_76 &&
( V_25 + V_45 -> V_49 ) <= ( V_75 -> V_76 + V_75 -> V_49 ) )
return V_75 ;
V_75 ++ ;
}
return NULL ;
}
static bool F_60 ( const struct V_30 * V_31 ,
const struct V_73 * V_77 ,
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
static bool F_61 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
unsigned long V_25 ,
const struct V_73 * V_77 )
{
T_2 * V_79 = ( void * ) V_45 -> V_54 ;
struct V_44 V_80 ;
bool V_81 ;
if ( F_62 ( V_45 -> V_49 <= 4 ) )
return V_77 -> V_82 ( V_2 , V_45 , V_25 ) ;
V_80 . V_49 = 4 ;
V_80 . V_53 = V_45 -> V_53 ;
V_80 . V_16 = V_45 -> V_16 ;
V_80 . V_83 = V_45 -> V_83 + 4 ;
if ( V_45 -> V_53 )
* ( T_2 * ) V_80 . V_54 = V_79 [ 1 ] ;
V_81 = V_77 -> V_82 ( V_2 , & V_80 , V_25 + 4 ) ;
if ( ! V_45 -> V_53 )
V_79 [ 1 ] = * ( T_2 * ) V_80 . V_54 ;
V_80 . V_83 = V_45 -> V_83 ;
if ( V_45 -> V_53 )
* ( T_2 * ) V_80 . V_54 = V_79 [ 0 ] ;
V_81 |= V_77 -> V_82 ( V_2 , & V_80 , V_25 ) ;
if ( ! V_45 -> V_53 )
V_79 [ 0 ] = * ( T_2 * ) V_80 . V_54 ;
return V_81 ;
}
bool F_63 ( struct V_1 * V_2 , struct V_84 * V_85 ,
struct V_44 * V_45 ,
const struct V_73 * V_74 ,
unsigned long V_86 )
{
const struct V_73 * V_77 ;
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
bool V_87 ;
unsigned long V_25 ;
V_25 = V_45 -> V_83 - V_86 ;
V_77 = F_59 ( V_74 , V_45 , V_25 ) ;
if ( F_64 ( ! V_77 || ! V_77 -> V_82 ) ) {
F_65 ( L_1 ,
V_45 -> V_53 , V_45 -> V_83 , V_45 -> V_49 ) ;
return false ;
}
F_66 ( & V_2 -> V_5 -> V_6 . V_7 . V_88 ) ;
V_25 -= V_77 -> V_76 ;
if ( F_60 ( V_31 , V_77 , V_25 ) ) {
V_87 = F_61 ( V_2 , V_45 , V_25 , V_77 ) ;
} else {
if ( ! V_45 -> V_53 )
memset ( V_45 -> V_54 , 0 , V_45 -> V_49 ) ;
V_87 = false ;
}
F_67 ( & V_2 -> V_5 -> V_6 . V_7 . V_88 ) ;
F_68 ( V_85 , V_45 ) ;
F_69 ( V_2 , V_85 ) ;
if ( V_87 )
F_70 ( V_2 -> V_5 ) ;
return true ;
}
bool F_71 ( struct V_1 * V_2 , struct V_84 * V_85 ,
struct V_44 * V_45 )
{
if ( ! F_72 ( V_2 -> V_5 ) )
return false ;
return V_2 -> V_5 -> V_6 . V_7 . V_8 . V_82 ( V_2 , V_85 , V_45 ) ;
}
static int F_73 ( struct V_30 * V_31 )
{
return V_31 -> V_13 - V_15 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
unsigned long * V_89 , * V_90 , * V_91 , * V_92 ;
unsigned long V_93 , V_43 ;
int V_94 = F_73 ( V_31 ) ;
int V_34 ;
V_34 = V_2 -> V_34 ;
V_91 = V_2 -> V_6 . V_41 . V_42 ;
V_92 = V_2 -> V_6 . V_41 . V_43 ;
V_89 = F_17 ( & V_31 -> V_40 , V_34 ) ;
V_90 = F_17 ( & V_31 -> V_36 , V_34 ) ;
F_75 ( V_91 , V_89 , V_90 , V_15 ) ;
V_89 = F_18 ( & V_31 -> V_40 ) ;
V_90 = F_18 ( & V_31 -> V_36 ) ;
F_75 ( V_92 , V_89 , V_90 , V_94 ) ;
F_75 ( V_92 , V_92 ,
F_18 ( & V_31 -> V_95 [ V_34 ] ) ,
V_94 ) ;
V_93 = F_76 ( V_91 , V_15 ) ;
V_43 = F_76 ( V_92 , V_94 ) ;
return ( V_93 < V_15 ||
V_43 < F_73 ( V_31 ) ) ;
}
void F_48 ( struct V_5 * V_5 )
{
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
struct V_1 * V_2 ;
int V_96 ;
if ( ! V_31 -> V_90 ) {
F_15 ( 0 , V_31 -> V_97 ) ;
return;
}
F_77 (c, vcpu, kvm) {
if ( F_74 ( V_2 ) ) {
F_78 ( L_2 , V_96 ) ;
F_15 ( V_96 , V_31 -> V_97 ) ;
}
}
}
static struct V_66 F_56 ( const struct V_1 * V_2 , int V_67 )
{
return V_98 -> V_99 ( V_2 , V_67 ) ;
}
static void F_57 ( struct V_1 * V_2 , int V_67 ,
struct V_66 V_100 )
{
V_98 -> V_101 ( V_2 , V_67 , V_100 ) ;
}
static void F_79 ( struct V_1 * V_2 , int V_67 ,
struct V_66 V_100 )
{
V_98 -> V_102 ( V_2 , V_67 , V_100 ) ;
}
static inline T_1 F_80 ( struct V_1 * V_2 )
{
return V_98 -> V_103 ( V_2 ) ;
}
static inline T_1 F_81 ( struct V_1 * V_2 )
{
return V_98 -> V_104 ( V_2 ) ;
}
static inline void F_82 ( struct V_1 * V_2 )
{
V_98 -> V_105 ( V_2 ) ;
}
static inline T_2 F_83 ( struct V_1 * V_2 )
{
return V_98 -> V_106 ( V_2 ) ;
}
static inline void F_84 ( struct V_1 * V_2 )
{
V_98 -> V_107 ( V_2 ) ;
}
static inline void F_85 ( struct V_1 * V_2 )
{
V_98 -> V_108 ( V_2 ) ;
}
void F_86 ( struct V_1 * V_2 , struct V_109 * V_110 )
{
V_98 -> V_111 ( V_2 , V_110 ) ;
}
void F_87 ( struct V_1 * V_2 , struct V_109 * V_110 )
{
V_98 -> V_112 ( V_2 , V_110 ) ;
}
static inline void F_88 ( struct V_1 * V_2 )
{
V_98 -> V_113 ( V_2 ) ;
}
static void F_58 ( int V_114 , int V_3 , struct V_1 * V_2 )
{
struct V_41 * V_41 = & V_2 -> V_6 . V_41 ;
struct V_66 V_100 = F_56 ( V_2 , V_114 ) ;
V_100 . V_68 = 0 ;
F_57 ( V_2 , V_114 , V_100 ) ;
F_16 ( V_114 , V_41 -> V_115 ) ;
V_41 -> V_116 [ V_3 ] = V_117 ;
F_79 ( V_2 , V_114 , V_100 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_41 * V_41 = & V_2 -> V_6 . V_41 ;
int V_67 ;
F_55 (lr, vgic_cpu->lr_used, vgic->nr_lr) {
struct V_66 V_100 = F_56 ( V_2 , V_67 ) ;
if ( ! F_23 ( V_2 , V_100 . V_3 ) ) {
F_58 ( V_67 , V_100 . V_3 , V_2 ) ;
if ( F_24 ( V_2 , V_100 . V_3 ) )
F_26 ( V_2 , V_100 . V_3 ) ;
}
}
}
bool F_89 ( struct V_1 * V_2 , T_5 V_118 , int V_3 )
{
struct V_41 * V_41 = & V_2 -> V_6 . V_41 ;
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
struct V_66 V_100 ;
int V_67 ;
F_39 ( V_118 & ~ 7 ) ;
F_39 ( V_118 && V_3 >= V_71 ) ;
F_39 ( V_3 >= V_31 -> V_13 ) ;
F_90 ( L_3 , V_3 ) ;
V_67 = V_41 -> V_116 [ V_3 ] ;
if ( V_67 != V_117 ) {
V_100 = F_56 ( V_2 , V_67 ) ;
if ( V_100 . V_4 == V_118 ) {
F_90 ( L_4 , V_67 , V_100 . V_3 ) ;
F_39 ( ! F_13 ( V_67 , V_41 -> V_115 ) ) ;
V_100 . V_68 |= V_72 ;
F_57 ( V_2 , V_67 , V_100 ) ;
F_79 ( V_2 , V_67 , V_100 ) ;
return true ;
}
}
V_67 = F_91 ( ( unsigned long * ) V_41 -> V_115 ,
V_7 -> V_119 ) ;
if ( V_67 >= V_7 -> V_119 )
return false ;
F_90 ( L_5 , V_67 , V_3 , V_118 ) ;
V_41 -> V_116 [ V_3 ] = V_67 ;
F_15 ( V_67 , V_41 -> V_115 ) ;
V_100 . V_3 = V_3 ;
V_100 . V_4 = V_118 ;
V_100 . V_68 = V_72 ;
if ( ! F_22 ( V_2 , V_3 ) )
V_100 . V_68 |= V_120 ;
F_57 ( V_2 , V_67 , V_100 ) ;
F_79 ( V_2 , V_67 , V_100 ) ;
return true ;
}
static bool F_92 ( struct V_1 * V_2 , int V_3 )
{
if ( ! F_37 ( V_2 , V_3 ) )
return true ;
if ( F_89 ( V_2 , 0 , V_3 ) ) {
if ( F_22 ( V_2 , V_3 ) ) {
F_34 ( V_2 , V_3 ) ;
F_36 ( V_2 , V_3 ) ;
} else {
F_25 ( V_2 , V_3 ) ;
}
return true ;
}
return false ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_41 * V_41 = & V_2 -> V_6 . V_41 ;
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
int V_65 , V_34 ;
int V_121 = 0 ;
V_34 = V_2 -> V_34 ;
if ( ! F_94 ( V_2 ) ) {
F_78 ( L_6 , V_34 ) ;
goto V_122;
}
F_55 (i, vgic_cpu->pending_percpu, VGIC_NR_SGIS) {
if ( ! F_2 ( V_2 , V_65 ) )
V_121 = 1 ;
}
F_95 (i, vgic_cpu->pending_percpu, VGIC_NR_PRIVATE_IRQS) {
if ( ! F_92 ( V_2 , V_65 ) )
V_121 = 1 ;
}
F_55 (i, vgic_cpu->pending_shared, vgic_nr_shared_irqs(dist)) {
if ( ! F_92 ( V_2 , V_65 + V_15 ) )
V_121 = 1 ;
}
V_122:
if ( V_121 ) {
F_84 ( V_2 ) ;
} else {
F_85 ( V_2 ) ;
F_16 ( V_34 , V_31 -> V_97 ) ;
}
}
static bool F_96 ( struct V_1 * V_2 )
{
T_2 V_123 = F_83 ( V_2 ) ;
bool V_124 = false ;
F_90 ( L_7 , V_123 ) ;
if ( V_123 & V_125 ) {
T_1 V_126 = F_81 ( V_2 ) ;
unsigned long * V_127 = F_9 ( & V_126 ) ;
int V_67 ;
F_55 (lr, eisr_ptr, vgic->nr_lr) {
struct V_66 V_100 = F_56 ( V_2 , V_67 ) ;
F_97 ( F_22 ( V_2 , V_100 . V_3 ) ) ;
F_26 ( V_2 , V_100 . V_3 ) ;
F_97 ( V_100 . V_68 & V_69 ) ;
V_100 . V_68 = 0 ;
F_57 ( V_2 , V_67 , V_100 ) ;
F_31 ( V_2 , V_100 . V_3 ) ;
if ( F_27 ( V_2 , V_100 . V_3 ) ) {
F_35 ( V_2 , V_100 . V_3 ) ;
V_124 = true ;
} else {
F_34 ( V_2 , V_100 . V_3 ) ;
F_36 ( V_2 , V_100 . V_3 ) ;
}
F_79 ( V_2 , V_67 , V_100 ) ;
}
}
if ( V_123 & V_128 )
F_85 ( V_2 ) ;
F_82 ( V_2 ) ;
return V_124 ;
}
static void F_98 ( struct V_1 * V_2 )
{
struct V_41 * V_41 = & V_2 -> V_6 . V_41 ;
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
T_1 V_129 ;
unsigned long * V_130 ;
int V_67 , V_89 ;
bool V_124 ;
V_124 = F_96 ( V_2 ) ;
V_129 = F_80 ( V_2 ) ;
V_130 = F_9 ( & V_129 ) ;
F_55 (lr, elrsr_ptr, vgic->nr_lr) {
struct V_66 V_100 ;
if ( ! F_99 ( V_67 , V_41 -> V_115 ) )
continue;
V_100 = F_56 ( V_2 , V_67 ) ;
F_39 ( V_100 . V_3 >= V_31 -> V_13 ) ;
V_41 -> V_116 [ V_100 . V_3 ] = V_117 ;
}
V_89 = F_91 ( V_130 , V_7 -> V_119 ) ;
if ( V_124 || V_89 < V_7 -> V_119 )
F_15 ( V_2 -> V_34 , V_31 -> V_97 ) ;
}
void F_100 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
if ( ! F_72 ( V_2 -> V_5 ) )
return;
F_66 ( & V_31 -> V_88 ) ;
F_93 ( V_2 ) ;
F_67 ( & V_31 -> V_88 ) ;
}
void F_101 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
if ( ! F_72 ( V_2 -> V_5 ) )
return;
F_66 ( & V_31 -> V_88 ) ;
F_98 ( V_2 ) ;
F_67 ( & V_31 -> V_88 ) ;
}
int F_94 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_5 -> V_6 . V_7 ;
if ( ! F_72 ( V_2 -> V_5 ) )
return 0 ;
return F_13 ( V_2 -> V_34 , V_31 -> V_97 ) ;
}
void F_70 ( struct V_5 * V_5 )
{
struct V_1 * V_2 ;
int V_96 ;
F_77 (c, vcpu, kvm) {
if ( F_94 ( V_2 ) )
F_102 ( V_2 ) ;
}
}
static int F_103 ( struct V_1 * V_2 , int V_3 , int V_131 )
{
int V_132 = F_22 ( V_2 , V_3 ) ;
if ( V_132 ) {
int V_68 = F_32 ( V_2 , V_3 ) ;
return V_131 > V_68 ;
} else {
int V_68 = F_27 ( V_2 , V_3 ) ;
return V_131 != V_68 ;
}
}
static int F_104 ( struct V_5 * V_5 , int V_24 ,
unsigned int V_133 , bool V_131 )
{
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
struct V_1 * V_2 ;
int V_132 , V_134 ;
int V_90 ;
bool V_81 = true , V_135 = true ;
F_66 ( & V_31 -> V_88 ) ;
V_2 = F_46 ( V_5 , V_24 ) ;
V_132 = F_22 ( V_2 , V_133 ) ;
V_134 = ! V_132 ;
if ( ! F_103 ( V_2 , V_133 , V_131 ) ) {
V_81 = false ;
goto V_136;
}
if ( V_133 >= V_15 ) {
V_24 = V_31 -> V_137 [ V_133 - V_15 ] ;
if ( V_24 == V_138 ) {
V_24 = 0 ;
V_135 = false ;
}
V_2 = F_46 ( V_5 , V_24 ) ;
}
F_90 ( L_8 , V_133 , V_131 , V_24 ) ;
if ( V_131 ) {
if ( V_134 )
F_28 ( V_2 , V_133 ) ;
F_33 ( V_2 , V_133 ) ;
} else {
if ( V_134 ) {
F_29 ( V_2 , V_133 ) ;
if ( ! F_30 ( V_2 , V_133 ) )
F_34 ( V_2 , V_133 ) ;
}
V_81 = false ;
goto V_136;
}
V_90 = F_23 ( V_2 , V_133 ) ;
if ( ! V_90 || ! V_135 ) {
V_81 = false ;
goto V_136;
}
if ( ! F_37 ( V_2 , V_133 ) ) {
V_81 = false ;
goto V_136;
}
if ( V_131 ) {
F_35 ( V_2 , V_133 ) ;
F_15 ( V_24 , V_31 -> V_97 ) ;
}
V_136:
F_67 ( & V_31 -> V_88 ) ;
return V_81 ? V_24 : - V_139 ;
}
int F_105 ( struct V_5 * V_5 , int V_24 , unsigned int V_133 ,
bool V_131 )
{
int V_81 = 0 ;
int V_34 ;
if ( F_64 ( ! F_106 ( V_5 ) ) ) {
if ( V_5 -> V_6 . V_7 . V_140 != V_141 ) {
V_81 = - V_142 ;
goto V_136;
}
F_107 ( & V_5 -> V_88 ) ;
V_81 = F_108 ( V_5 ) ;
F_109 ( & V_5 -> V_88 ) ;
if ( V_81 )
goto V_136;
}
V_34 = F_104 ( V_5 , V_24 , V_133 , V_131 ) ;
if ( V_34 >= 0 ) {
F_102 ( F_46 ( V_5 , V_34 ) ) ;
}
V_136:
return V_81 ;
}
static T_6 F_110 ( int V_3 , void * V_54 )
{
return V_143 ;
}
void F_111 ( struct V_1 * V_2 )
{
struct V_41 * V_41 = & V_2 -> V_6 . V_41 ;
F_8 ( V_41 -> V_43 ) ;
F_8 ( V_41 -> V_116 ) ;
V_41 -> V_43 = NULL ;
V_41 -> V_116 = NULL ;
}
static int F_112 ( struct V_1 * V_2 , int V_13 )
{
struct V_41 * V_41 = & V_2 -> V_6 . V_41 ;
int V_144 = ( V_13 - V_15 ) / 8 ;
V_41 -> V_43 = F_6 ( V_144 , V_17 ) ;
V_41 -> V_116 = F_113 ( V_13 , V_17 ) ;
if ( ! V_41 -> V_43 || ! V_41 -> V_116 ) {
F_111 ( V_2 ) ;
return - V_18 ;
}
memset ( V_41 -> V_116 , V_117 , V_13 ) ;
V_41 -> V_119 = V_7 -> V_119 ;
return 0 ;
}
int F_114 ( void )
{
return V_7 -> V_145 ;
}
void F_115 ( struct V_5 * V_5 )
{
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
struct V_1 * V_2 ;
int V_65 ;
F_77 (i, vcpu, kvm)
F_111 ( V_2 ) ;
F_7 ( & V_31 -> V_36 ) ;
F_7 ( & V_31 -> V_38 ) ;
F_7 ( & V_31 -> V_40 ) ;
F_7 ( & V_31 -> V_39 ) ;
F_7 ( & V_31 -> V_37 ) ;
F_7 ( & V_31 -> V_33 ) ;
F_20 ( & V_31 -> V_146 ) ;
if ( V_31 -> V_95 ) {
for ( V_65 = 0 ; V_65 < V_31 -> V_12 ; V_65 ++ )
F_7 ( & V_31 -> V_95 [ V_65 ] ) ;
}
F_8 ( V_31 -> V_147 ) ;
F_8 ( V_31 -> V_137 ) ;
F_8 ( V_31 -> V_148 ) ;
F_8 ( V_31 -> V_95 ) ;
F_8 ( V_31 -> V_97 ) ;
V_31 -> V_147 = NULL ;
V_31 -> V_137 = NULL ;
V_31 -> V_95 = NULL ;
V_31 -> V_97 = NULL ;
V_31 -> V_12 = 0 ;
}
int F_108 ( struct V_5 * V_5 )
{
struct V_30 * V_31 = & V_5 -> V_6 . V_7 ;
struct V_1 * V_2 ;
int V_12 , V_13 ;
int V_81 , V_65 , V_34 ;
if ( F_106 ( V_5 ) )
return 0 ;
V_12 = V_31 -> V_12 = F_116 ( & V_5 -> V_149 ) ;
if ( ! V_12 )
return - V_150 ;
if ( ! V_31 -> V_13 )
V_31 -> V_13 = V_151 ;
V_13 = V_31 -> V_13 ;
V_81 = F_4 ( & V_31 -> V_36 , V_12 , V_13 ) ;
V_81 |= F_4 ( & V_31 -> V_38 , V_12 , V_13 ) ;
V_81 |= F_4 ( & V_31 -> V_40 , V_12 , V_13 ) ;
V_81 |= F_4 ( & V_31 -> V_39 , V_12 , V_13 ) ;
V_81 |= F_4 ( & V_31 -> V_37 , V_12 , V_13 ) ;
V_81 |= F_4 ( & V_31 -> V_33 , V_12 , V_13 ) ;
V_81 |= F_19 ( & V_31 -> V_146 , V_12 , V_13 ) ;
if ( V_81 )
goto V_136;
V_31 -> V_147 = F_6 ( V_12 * V_71 , V_17 ) ;
V_31 -> V_137 = F_6 ( V_13 - V_15 , V_17 ) ;
V_31 -> V_95 = F_6 ( sizeof( * V_31 -> V_95 ) * V_12 ,
V_17 ) ;
V_31 -> V_97 = F_6 ( F_5 ( V_12 ) * sizeof( long ) ,
V_17 ) ;
if ( ! V_31 -> V_147 ||
! V_31 -> V_137 ||
! V_31 -> V_95 ||
! V_31 -> V_97 ) {
V_81 = - V_18 ;
goto V_136;
}
for ( V_65 = 0 ; V_65 < V_12 ; V_65 ++ )
V_81 |= F_4 ( & V_31 -> V_95 [ V_65 ] ,
V_12 , V_13 ) ;
if ( V_81 )
goto V_136;
V_81 = V_5 -> V_6 . V_7 . V_8 . V_152 ( V_5 ) ;
if ( V_81 )
goto V_136;
F_77 (vcpu_id, vcpu, kvm) {
V_81 = F_112 ( V_2 , V_13 ) ;
if ( V_81 ) {
F_117 ( L_9 ) ;
break;
}
for ( V_65 = 0 ; V_65 < V_31 -> V_13 ; V_65 ++ ) {
if ( V_65 < V_153 )
F_14 ( & V_31 -> V_36 ,
V_2 -> V_34 , V_65 , 1 ) ;
if ( V_65 < V_15 )
F_14 ( & V_31 -> V_33 ,
V_2 -> V_34 , V_65 ,
V_35 ) ;
}
F_88 ( V_2 ) ;
}
V_136:
if ( V_81 )
F_115 ( V_5 ) ;
return V_81 ;
}
static int F_118 ( struct V_5 * V_5 , int type )
{
switch ( type ) {
case V_141 :
F_119 ( V_5 ) ;
break;
#ifdef F_120
case V_154 :
F_121 ( V_5 ) ;
break;
#endif
default:
return - V_150 ;
}
if ( F_116 ( & V_5 -> V_149 ) > V_5 -> V_6 . V_155 )
return - V_156 ;
return 0 ;
}
int F_122 ( struct V_5 * V_5 , T_2 type )
{
int V_65 , V_157 = - 1 , V_81 ;
struct V_1 * V_2 ;
F_107 ( & V_5 -> V_88 ) ;
if ( F_72 ( V_5 ) ) {
V_81 = - V_158 ;
goto V_136;
}
if ( type == V_141 && ! V_7 -> V_159 ) {
V_81 = - V_150 ;
goto V_136;
}
V_81 = - V_142 ;
F_77 (i, vcpu, kvm) {
if ( ! F_123 ( & V_2 -> V_160 ) )
goto V_161;
V_157 = V_65 ;
}
F_77 (i, vcpu, kvm) {
if ( V_2 -> V_6 . V_162 )
goto V_161;
}
V_81 = 0 ;
V_81 = F_118 ( V_5 , type ) ;
if ( V_81 )
goto V_161;
F_124 ( & V_5 -> V_6 . V_7 . V_88 ) ;
V_5 -> V_6 . V_7 . V_163 = true ;
V_5 -> V_6 . V_7 . V_140 = type ;
V_5 -> V_6 . V_7 . V_164 = V_7 -> V_164 ;
V_5 -> V_6 . V_7 . V_165 = V_166 ;
V_5 -> V_6 . V_7 . V_167 = V_166 ;
V_5 -> V_6 . V_7 . V_168 = V_166 ;
V_161:
for (; V_157 >= 0 ; V_157 -- ) {
V_2 = F_46 ( V_5 , V_157 ) ;
F_109 ( & V_2 -> V_160 ) ;
}
V_136:
F_109 ( & V_5 -> V_88 ) ;
return V_81 ;
}
static int F_125 ( struct V_5 * V_5 )
{
T_3 V_31 = V_5 -> V_6 . V_7 . V_165 ;
T_3 V_169 = V_5 -> V_6 . V_7 . V_167 ;
if ( F_126 ( V_31 ) || F_126 ( V_169 ) )
return 0 ;
if ( ( V_31 <= V_169 && V_31 + V_170 > V_169 ) ||
( V_169 <= V_31 && V_169 + V_171 > V_31 ) )
return - V_142 ;
return 0 ;
}
static int F_127 ( struct V_5 * V_5 , T_3 * V_172 ,
T_3 V_173 , T_3 V_29 )
{
int V_81 ;
if ( V_173 & ~ V_174 )
return - V_156 ;
if ( V_173 & ( V_175 - 1 ) )
return - V_139 ;
if ( ! F_126 ( * V_172 ) )
return - V_158 ;
if ( V_173 + V_29 < V_173 )
return - V_139 ;
* V_172 = V_173 ;
V_81 = F_125 ( V_5 ) ;
if ( V_81 )
* V_172 = V_166 ;
return V_81 ;
}
int F_128 ( struct V_5 * V_5 , unsigned long type , T_1 * V_173 , bool V_176 )
{
int V_75 = 0 ;
struct V_30 * V_7 = & V_5 -> V_6 . V_7 ;
int V_177 ;
T_3 * V_178 , V_179 ;
T_3 V_180 ;
F_107 ( & V_5 -> V_88 ) ;
switch ( type ) {
case V_181 :
V_177 = V_141 ;
V_178 = & V_7 -> V_165 ;
V_179 = V_170 ;
V_180 = V_175 ;
break;
case V_182 :
V_177 = V_141 ;
V_178 = & V_7 -> V_167 ;
V_179 = V_171 ;
V_180 = V_175 ;
break;
#ifdef F_120
case V_183 :
V_177 = V_154 ;
V_178 = & V_7 -> V_165 ;
V_179 = V_184 ;
V_180 = V_185 ;
break;
case V_186 :
V_177 = V_154 ;
V_178 = & V_7 -> V_168 ;
V_179 = V_187 ;
V_180 = V_185 ;
break;
#endif
default:
V_75 = - V_150 ;
goto V_136;
}
if ( V_7 -> V_140 != V_177 ) {
V_75 = - V_150 ;
goto V_136;
}
if ( V_176 ) {
if ( ! F_129 ( * V_173 , V_180 ) )
V_75 = - V_139 ;
else
V_75 = F_127 ( V_5 , V_178 , * V_173 ,
V_179 ) ;
} else {
* V_173 = * V_178 ;
}
V_136:
F_109 ( & V_5 -> V_88 ) ;
return V_75 ;
}
int F_130 ( struct V_188 * V_189 , struct V_190 * V_191 )
{
int V_75 ;
switch ( V_191 -> V_192 ) {
case V_193 : {
T_1 T_7 * V_194 = ( T_1 T_7 * ) ( long ) V_191 -> V_173 ;
T_1 V_173 ;
unsigned long type = ( unsigned long ) V_191 -> V_191 ;
if ( F_131 ( & V_173 , V_194 , sizeof( V_173 ) ) )
return - V_195 ;
V_75 = F_128 ( V_189 -> V_5 , type , & V_173 , true ) ;
return ( V_75 == - V_150 ) ? - V_196 : V_75 ;
}
case V_197 : {
T_2 T_7 * V_194 = ( T_2 T_7 * ) ( long ) V_191 -> V_173 ;
T_2 V_20 ;
int V_81 = 0 ;
if ( F_132 ( V_20 , V_194 ) )
return - V_195 ;
if ( V_20 < ( V_15 + 32 ) ||
V_20 > V_198 ||
( V_20 & 31 ) )
return - V_139 ;
F_107 ( & V_189 -> V_5 -> V_88 ) ;
if ( F_133 ( V_189 -> V_5 ) || V_189 -> V_5 -> V_6 . V_7 . V_13 )
V_81 = - V_142 ;
else
V_189 -> V_5 -> V_6 . V_7 . V_13 = V_20 ;
F_109 ( & V_189 -> V_5 -> V_88 ) ;
return V_81 ;
}
case V_199 : {
switch ( V_191 -> V_191 ) {
case V_200 :
V_75 = F_108 ( V_189 -> V_5 ) ;
return V_75 ;
}
break;
}
}
return - V_196 ;
}
int F_134 ( struct V_188 * V_189 , struct V_190 * V_191 )
{
int V_75 = - V_196 ;
switch ( V_191 -> V_192 ) {
case V_193 : {
T_1 T_7 * V_194 = ( T_1 T_7 * ) ( long ) V_191 -> V_173 ;
T_1 V_173 ;
unsigned long type = ( unsigned long ) V_191 -> V_191 ;
V_75 = F_128 ( V_189 -> V_5 , type , & V_173 , false ) ;
if ( V_75 )
return ( V_75 == - V_150 ) ? - V_196 : V_75 ;
if ( F_135 ( V_194 , & V_173 , sizeof( V_173 ) ) )
return - V_195 ;
break;
}
case V_197 : {
T_2 T_7 * V_194 = ( T_2 T_7 * ) ( long ) V_191 -> V_173 ;
V_75 = F_136 ( V_189 -> V_5 -> V_6 . V_7 . V_13 , V_194 ) ;
break;
}
}
return V_75 ;
}
int F_137 ( const struct V_73 * V_74 , T_3 V_25 )
{
struct V_44 V_201 ;
V_201 . V_49 = 4 ;
if ( F_59 ( V_74 , & V_201 , V_25 ) )
return 0 ;
else
return - V_196 ;
}
static void F_138 ( void * V_202 )
{
F_139 ( V_7 -> V_203 , 0 ) ;
}
static int F_140 ( struct V_204 * V_205 ,
unsigned long V_206 , void * V_169 )
{
switch ( V_206 ) {
case V_207 :
case V_208 :
F_138 ( NULL ) ;
break;
case V_209 :
case V_210 :
F_141 ( V_7 -> V_203 ) ;
break;
}
return V_211 ;
}
int F_142 ( void )
{
const struct V_212 * V_213 ;
const int (* F_143)( struct V_214 * , const struct V_98 * * ,
const struct V_215 * * );
struct V_214 * V_216 ;
int V_81 ;
V_216 = F_144 ( NULL ,
V_217 , & V_213 ) ;
if ( ! V_216 ) {
F_117 ( L_10 ) ;
return - V_150 ;
}
F_143 = V_213 -> V_54 ;
V_81 = F_143 ( V_216 , & V_98 , & V_7 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_145 ( V_7 -> V_203 , F_110 ,
L_11 , F_146 () ) ;
if ( V_81 ) {
F_117 ( L_12 , V_7 -> V_203 ) ;
return V_81 ;
}
V_81 = F_147 ( & V_218 ) ;
if ( V_81 ) {
F_117 ( L_13 ) ;
goto V_219;
}
F_148 ( V_7 ) ;
F_149 ( F_138 , NULL , 1 ) ;
return 0 ;
V_219:
F_150 ( V_7 -> V_203 , F_146 () ) ;
return V_81 ;
}

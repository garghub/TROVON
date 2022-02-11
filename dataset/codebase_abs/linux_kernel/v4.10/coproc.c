static inline void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
T_1 V_5 )
{
F_2 ( V_2 , V_4 -> V_6 ) = V_5 & 0xffffffff ;
F_2 ( V_2 , V_4 -> V_6 + 1 ) = V_5 >> 32 ;
}
static inline T_1 F_3 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
T_1 V_5 ;
V_5 = F_2 ( V_2 , V_4 -> V_6 + 1 ) ;
V_5 = V_5 << 32 ;
V_5 = V_5 | F_2 ( V_2 , V_4 -> V_6 ) ;
return V_5 ;
}
int F_4 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
F_5 ( V_2 ) ;
return 1 ;
}
int F_6 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
F_5 ( V_2 ) ;
return 1 ;
}
int F_7 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
F_5 ( V_2 ) ;
return 1 ;
}
int F_8 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
F_5 ( V_2 ) ;
return 1 ;
}
static void F_9 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
F_2 ( V_2 , V_9 ) = ( ( F_10 () & V_10 ) |
( ( V_2 -> V_11 >> 2 ) << V_12 ) |
( V_2 -> V_11 & 3 ) ) ;
}
static bool F_11 ( struct V_1 * V_2 ,
const struct V_13 * V_14 ,
const struct V_3 * V_4 )
{
if ( V_14 -> V_15 )
return F_12 ( V_2 , V_14 ) ;
* F_13 ( V_2 , V_14 -> V_16 ) = F_2 ( V_2 , V_17 ) ;
return true ;
}
static bool F_14 ( struct V_1 * V_2 ,
const struct V_13 * V_14 ,
const struct V_3 * V_4 )
{
if ( V_14 -> V_15 )
return F_15 ( V_2 , V_14 ) ;
return F_16 ( V_2 , V_14 ) ;
}
static bool F_17 ( struct V_1 * V_2 ,
const struct V_13 * V_14 ,
const struct V_3 * V_4 )
{
if ( V_14 -> V_15 )
return F_12 ( V_2 , V_14 ) ;
* F_13 ( V_2 , V_14 -> V_16 ) = F_2 ( V_2 , V_18 ) ;
return true ;
}
static void F_18 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
T_2 V_19 , V_20 ;
asm volatile("mrc p15, 1, %0, c9, c0, 2\n" : "=r" (l2ctlr));
V_19 &= ~ ( 3 << 24 ) ;
V_20 = F_19 ( & V_2 -> V_21 -> V_22 ) - 1 ;
V_20 -= ( V_2 -> V_11 & ~ 3 ) ;
V_20 = F_20 ( V_20 , 3U ) ;
V_19 |= ( V_20 & 3 ) << 24 ;
F_2 ( V_2 , V_18 ) = V_19 ;
}
static void F_21 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
T_2 V_23 ;
asm volatile("mrc p15, 0, %0, c1, c0, 1\n" : "=r" (actlr));
if ( F_19 ( & V_2 -> V_21 -> V_22 ) > 1 )
V_23 |= 1U << 6 ;
else
V_23 &= ~ ( 1U << 6 ) ;
F_2 ( V_2 , V_17 ) = V_23 ;
}
static bool F_22 ( struct V_1 * V_2 ,
const struct V_13 * V_14 ,
const struct V_3 * V_4 )
{
if ( V_14 -> V_15 )
return F_12 ( V_2 , V_14 ) ;
* F_13 ( V_2 , V_14 -> V_16 ) = 0 ;
return true ;
}
static bool F_23 ( struct V_1 * V_2 ,
const struct V_13 * V_14 ,
const struct V_3 * V_4 )
{
if ( ! V_14 -> V_15 )
return F_24 ( V_2 , V_14 ) ;
F_25 ( V_2 ) ;
return true ;
}
bool F_26 ( struct V_1 * V_2 ,
const struct V_13 * V_14 ,
const struct V_3 * V_4 )
{
bool V_24 = F_27 ( V_2 ) ;
F_28 ( ! V_14 -> V_15 ) ;
F_2 ( V_2 , V_4 -> V_6 ) = * F_13 ( V_2 , V_14 -> V_16 ) ;
if ( V_14 -> V_25 )
F_2 ( V_2 , V_4 -> V_6 + 1 ) = * F_13 ( V_2 , V_14 -> V_26 ) ;
F_29 ( V_2 , V_24 ) ;
return true ;
}
static bool F_30 ( struct V_1 * V_2 ,
const struct V_13 * V_14 ,
const struct V_3 * V_4 )
{
T_1 V_6 ;
if ( ! V_14 -> V_15 )
return F_24 ( V_2 , V_14 ) ;
V_6 = ( T_1 ) * F_13 ( V_2 , V_14 -> V_26 ) << 32 ;
V_6 |= * F_13 ( V_2 , V_14 -> V_16 ) ;
F_31 ( V_2 , V_6 ) ;
return true ;
}
static bool F_32 ( struct V_1 * V_2 ,
const struct V_13 * V_14 ,
const struct V_3 * V_4 )
{
if ( V_14 -> V_15 )
return F_12 ( V_2 , V_14 ) ;
* F_13 ( V_2 , V_14 -> V_16 ) = V_2 -> V_27 . V_28 . V_29 . V_30 ;
return true ;
}
static bool F_33 ( struct V_1 * V_2 ,
const struct V_13 * V_14 ,
const struct V_3 * V_4 )
{
if ( V_14 -> V_15 )
return F_12 ( V_2 , V_14 ) ;
else
return F_16 ( V_2 , V_14 ) ;
}
static int F_34 ( const struct V_3 * V_31 , unsigned int V_32 )
{
unsigned int V_33 ;
for ( V_33 = 1 ; V_33 < V_32 ; V_33 ++ ) {
if ( F_35 ( & V_31 [ V_33 - 1 ] , & V_31 [ V_33 ] ) >= 0 ) {
F_36 ( L_1 , V_31 , V_33 - 1 ) ;
return 1 ;
}
}
return 0 ;
}
void F_37 ( struct V_34 * V_31 )
{
F_28 ( F_34 ( V_31 -> V_31 , V_31 -> V_35 ) ) ;
V_36 [ V_31 -> V_37 ] = V_31 ;
}
static const struct V_3 * F_38 ( unsigned V_37 , T_3 * V_35 )
{
struct V_34 * V_31 ;
V_31 = V_36 [ V_37 ] ;
* V_35 = V_31 -> V_35 ;
return V_31 -> V_31 ;
}
static int F_39 ( const void * V_38 , const void * V_39 )
{
const unsigned long V_40 = ( unsigned long ) V_38 ;
const struct V_3 * V_4 = V_39 ;
return V_40 - F_40 ( V_4 ) ;
}
static const struct V_3 * F_41 ( const struct V_13 * V_41 ,
const struct V_3 V_31 [] ,
unsigned int V_35 )
{
unsigned long V_40 = F_40 ( V_41 ) ;
return bsearch ( ( void * ) V_40 , V_31 , V_35 , sizeof( V_31 [ 0 ] ) , F_39 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
const struct V_13 * V_41 )
{
T_3 V_35 ;
const struct V_3 * V_31 , * V_4 ;
F_43 ( V_41 -> V_42 , V_41 -> V_16 , V_41 -> V_43 ,
V_41 -> V_44 , V_41 -> V_45 , V_41 -> V_15 ) ;
V_31 = F_38 ( V_2 -> V_27 . V_37 , & V_35 ) ;
V_4 = F_41 ( V_41 , V_31 , V_35 ) ;
if ( ! V_4 )
V_4 = F_41 ( V_41 , V_46 , F_44 ( V_46 ) ) ;
if ( F_45 ( V_4 ) ) {
F_28 ( ! V_4 -> V_47 ) ;
if ( F_45 ( V_4 -> V_47 ( V_2 , V_41 , V_4 ) ) ) {
F_46 ( V_2 , F_47 ( V_2 ) ) ;
return 1 ;
}
} else {
F_36 ( L_2 ,
* F_48 ( V_2 ) ) ;
F_49 ( V_41 ) ;
}
F_5 ( V_2 ) ;
return 1 ;
}
int F_50 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_13 V_41 ;
V_41 . V_43 = ( F_51 ( V_2 ) >> 1 ) & 0xf ;
V_41 . V_16 = ( F_51 ( V_2 ) >> 5 ) & 0xf ;
V_41 . V_15 = ( ( F_51 ( V_2 ) & 1 ) == 0 ) ;
V_41 . V_25 = true ;
V_41 . V_42 = ( F_51 ( V_2 ) >> 16 ) & 0xf ;
V_41 . V_45 = 0 ;
V_41 . V_26 = ( F_51 ( V_2 ) >> 10 ) & 0xf ;
V_41 . V_44 = 0 ;
return F_42 ( V_2 , & V_41 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
const struct V_3 * V_31 , T_3 V_35 )
{
unsigned long V_33 ;
for ( V_33 = 0 ; V_33 < V_35 ; V_33 ++ )
if ( V_31 [ V_33 ] . V_48 )
V_31 [ V_33 ] . V_48 ( V_2 , & V_31 [ V_33 ] ) ;
}
int F_53 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_13 V_41 ;
V_41 . V_44 = ( F_51 ( V_2 ) >> 1 ) & 0xf ;
V_41 . V_16 = ( F_51 ( V_2 ) >> 5 ) & 0xf ;
V_41 . V_15 = ( ( F_51 ( V_2 ) & 1 ) == 0 ) ;
V_41 . V_25 = false ;
V_41 . V_43 = ( F_51 ( V_2 ) >> 10 ) & 0xf ;
V_41 . V_42 = ( F_51 ( V_2 ) >> 14 ) & 0x7 ;
V_41 . V_45 = ( F_51 ( V_2 ) >> 17 ) & 0x7 ;
V_41 . V_26 = 0 ;
return F_42 ( V_2 , & V_41 ) ;
}
static bool F_54 ( T_1 V_49 , struct V_13 * V_41 )
{
switch ( V_49 & V_50 ) {
case V_51 :
if ( V_49 & ~ ( V_52 | V_50
| V_53
| V_54
| V_55
| V_56
| V_57 ) )
return false ;
V_41 -> V_25 = false ;
V_41 -> V_43 = ( ( V_49 & V_54 )
>> V_58 ) ;
V_41 -> V_44 = ( ( V_49 & V_55 )
>> V_59 ) ;
V_41 -> V_42 = ( ( V_49 & V_56 )
>> V_60 ) ;
V_41 -> V_45 = ( ( V_49 & V_57 )
>> V_61 ) ;
return true ;
case V_62 :
if ( V_49 & ~ ( V_52 | V_50
| V_53
| V_55
| V_56 ) )
return false ;
V_41 -> V_25 = true ;
V_41 -> V_43 = ( ( V_49 & V_55 )
>> V_59 ) ;
V_41 -> V_42 = ( ( V_49 & V_56 )
>> V_60 ) ;
V_41 -> V_45 = 0 ;
V_41 -> V_44 = 0 ;
return true ;
default:
return false ;
}
}
static const struct V_3 * F_55 ( struct V_1 * V_2 ,
T_1 V_49 )
{
T_3 V_35 ;
const struct V_3 * V_31 , * V_4 ;
struct V_13 V_41 ;
if ( ( V_49 & V_53 ) >> V_63 != 15 )
return NULL ;
if ( ! F_54 ( V_49 , & V_41 ) )
return NULL ;
V_31 = F_38 ( V_2 -> V_27 . V_37 , & V_35 ) ;
V_4 = F_41 ( & V_41 , V_31 , V_35 ) ;
if ( ! V_4 )
V_4 = F_41 ( & V_41 , V_46 , F_44 ( V_46 ) ) ;
if ( V_4 && ! V_4 -> V_6 )
V_4 = NULL ;
return V_4 ;
}
static int F_56 ( void * V_5 , const void T_4 * V_64 , T_1 V_49 )
{
if ( F_57 ( V_5 , V_64 , F_58 ( V_49 ) ) != 0 )
return - V_65 ;
return 0 ;
}
static int F_59 ( void T_4 * V_64 , const void * V_5 , T_1 V_49 )
{
if ( F_60 ( V_64 , V_5 , F_58 ( V_49 ) ) != 0 )
return - V_65 ;
return 0 ;
}
static int F_61 ( T_1 V_49 , void T_4 * V_64 )
{
struct V_13 V_41 ;
const struct V_3 * V_4 ;
int V_66 ;
if ( ! F_54 ( V_49 , & V_41 ) )
return - V_67 ;
V_4 = F_41 ( & V_41 , V_68 , F_44 ( V_68 ) ) ;
if ( ! V_4 )
return - V_67 ;
V_66 = - V_67 ;
if ( F_58 ( V_49 ) == 4 ) {
T_2 V_5 = V_4 -> V_5 ;
V_66 = F_59 ( V_64 , & V_5 , V_49 ) ;
} else if ( F_58 ( V_49 ) == 8 ) {
V_66 = F_59 ( V_64 , & V_4 -> V_5 , V_49 ) ;
}
return V_66 ;
}
static int F_62 ( T_1 V_49 , void T_4 * V_64 )
{
struct V_13 V_41 ;
const struct V_3 * V_4 ;
int V_69 ;
T_1 V_5 ;
if ( ! F_54 ( V_49 , & V_41 ) )
return - V_67 ;
V_4 = F_41 ( & V_41 , V_68 , F_44 ( V_68 ) ) ;
if ( ! V_4 )
return - V_67 ;
V_69 = - V_67 ;
if ( F_58 ( V_49 ) == 4 ) {
T_2 V_70 ;
V_69 = F_56 ( & V_70 , V_64 , V_49 ) ;
if ( ! V_69 )
V_5 = V_70 ;
} else if ( F_58 ( V_49 ) == 8 ) {
V_69 = F_56 ( & V_5 , V_64 , V_49 ) ;
}
if ( V_69 )
return V_69 ;
if ( V_4 -> V_5 != V_5 )
return - V_71 ;
return 0 ;
}
static bool F_63 ( T_2 V_5 )
{
T_2 V_72 , V_73 ;
if ( V_5 >= V_74 )
return false ;
V_72 = ( V_5 >> 1 ) ;
V_73 = ( V_75 >> ( V_72 * 3 ) ) & 7 ;
switch ( V_73 ) {
case 0 :
return false ;
case 1 :
return ( V_5 & 1 ) ;
case 2 :
case 4 :
return ! ( V_5 & 1 ) ;
case 3 :
return true ;
default:
return false ;
}
}
static T_2 F_64 ( T_2 V_76 )
{
T_2 V_77 ;
F_65 () ;
asm volatile("mcr p15, 2, %0, c0, c0, 0" : : "r" (csselr));
F_66 () ;
asm volatile("mrc p15, 1, %0, c0, c0, 0" : "=r" (ccsidr));
F_67 () ;
return V_77 ;
}
static int F_68 ( T_1 V_49 , void T_4 * V_64 )
{
T_2 V_5 ;
T_2 T_4 * V_78 = V_64 ;
if ( V_49 & ~ ( V_52 | V_50 | V_53
| ( ( 1 << V_63 ) - 1 ) ) )
return - V_67 ;
switch ( V_49 & V_79 ) {
case V_80 :
if ( F_58 ( V_49 ) != 4 )
return - V_67 ;
V_5 = ( V_49 & V_81 )
>> V_82 ;
if ( ! F_63 ( V_5 ) )
return - V_67 ;
return F_69 ( F_64 ( V_5 ) , V_78 ) ;
default:
return - V_67 ;
}
}
static int F_70 ( T_1 V_49 , void T_4 * V_64 )
{
T_2 V_5 , V_83 ;
T_2 T_4 * V_78 = V_64 ;
if ( V_49 & ~ ( V_52 | V_50 | V_53
| ( ( 1 << V_63 ) - 1 ) ) )
return - V_67 ;
switch ( V_49 & V_79 ) {
case V_80 :
if ( F_58 ( V_49 ) != 4 )
return - V_67 ;
V_5 = ( V_49 & V_81 )
>> V_82 ;
if ( ! F_63 ( V_5 ) )
return - V_67 ;
if ( F_71 ( V_83 , V_78 ) )
return - V_65 ;
if ( V_83 != F_64 ( V_5 ) )
return - V_71 ;
return 0 ;
default:
return - V_67 ;
}
}
static unsigned int F_72 ( void )
{
if ( ( ( F_73 ( V_84 ) & V_85 ) >> V_86 ) == 2 )
return 32 ;
else
return 16 ;
}
static unsigned int F_74 ( void )
{
return F_72 () + F_44 ( V_87 ) ;
}
static int F_75 ( T_1 T_4 * V_88 )
{
unsigned int V_33 ;
const T_1 V_89 = V_90 | V_51 | V_91 ;
const T_1 V_92 = V_90 | V_62 | V_91 ;
for ( V_33 = 0 ; V_33 < F_72 () ; V_33 ++ ) {
if ( F_69 ( ( V_92 | V_93 ) + V_33 ,
V_88 ) )
return - V_65 ;
V_88 ++ ;
}
for ( V_33 = 0 ; V_33 < F_44 ( V_87 ) ; V_33 ++ ) {
if ( F_69 ( V_89 | V_87 [ V_33 ] , V_88 ) )
return - V_65 ;
V_88 ++ ;
}
return F_74 () ;
}
static int F_76 ( const struct V_1 * V_2 , T_1 V_49 , void T_4 * V_64 )
{
T_2 V_94 = ( V_49 & V_95 ) ;
T_2 V_5 ;
if ( V_49 & ~ ( V_52 | V_50 | V_53
| ( ( 1 << V_63 ) - 1 ) ) )
return - V_67 ;
if ( V_94 < F_72 () ) {
if ( F_58 ( V_49 ) != 8 )
return - V_67 ;
return F_59 ( V_64 , & V_2 -> V_27 . V_96 . V_97 . V_98 [ V_94 ] ,
V_49 ) ;
}
if ( F_58 ( V_49 ) != 4 )
return - V_67 ;
switch ( V_94 ) {
case V_99 :
return F_59 ( V_64 , & V_2 -> V_27 . V_96 . V_97 . V_100 , V_49 ) ;
case V_101 :
return F_59 ( V_64 , & V_2 -> V_27 . V_96 . V_97 . V_102 , V_49 ) ;
case V_103 :
return F_59 ( V_64 , & V_2 -> V_27 . V_96 . V_97 . V_104 , V_49 ) ;
case V_105 :
return F_59 ( V_64 , & V_2 -> V_27 . V_96 . V_97 . V_106 , V_49 ) ;
case V_107 :
V_5 = F_73 ( V_84 ) ;
return F_59 ( V_64 , & V_5 , V_49 ) ;
case V_108 :
V_5 = F_73 ( V_109 ) ;
return F_59 ( V_64 , & V_5 , V_49 ) ;
case V_110 :
V_5 = F_73 ( V_111 ) ;
return F_59 ( V_64 , & V_5 , V_49 ) ;
default:
return - V_67 ;
}
}
static int F_77 ( struct V_1 * V_2 , T_1 V_49 , const void T_4 * V_64 )
{
T_2 V_94 = ( V_49 & V_95 ) ;
T_2 V_5 ;
if ( V_49 & ~ ( V_52 | V_50 | V_53
| ( ( 1 << V_63 ) - 1 ) ) )
return - V_67 ;
if ( V_94 < F_72 () ) {
if ( F_58 ( V_49 ) != 8 )
return - V_67 ;
return F_56 ( & V_2 -> V_27 . V_96 . V_97 . V_98 [ V_94 ] ,
V_64 , V_49 ) ;
}
if ( F_58 ( V_49 ) != 4 )
return - V_67 ;
switch ( V_94 ) {
case V_99 :
return F_56 ( & V_2 -> V_27 . V_96 . V_97 . V_100 , V_64 , V_49 ) ;
case V_101 :
return F_56 ( & V_2 -> V_27 . V_96 . V_97 . V_102 , V_64 , V_49 ) ;
case V_103 :
return F_56 ( & V_2 -> V_27 . V_96 . V_97 . V_104 , V_64 , V_49 ) ;
case V_105 :
return F_56 ( & V_2 -> V_27 . V_96 . V_97 . V_106 , V_64 , V_49 ) ;
case V_107 :
if ( F_56 ( & V_5 , V_64 , V_49 ) )
return - V_65 ;
if ( V_5 != F_73 ( V_84 ) )
return - V_71 ;
return 0 ;
case V_108 :
if ( F_56 ( & V_5 , V_64 , V_49 ) )
return - V_65 ;
if ( V_5 != F_73 ( V_109 ) )
return - V_71 ;
return 0 ;
case V_110 :
if ( F_56 ( & V_5 , V_64 , V_49 ) )
return - V_65 ;
if ( V_5 != F_73 ( V_111 ) )
return - V_71 ;
return 0 ;
default:
return - V_67 ;
}
}
static unsigned int F_74 ( void )
{
return 0 ;
}
static int F_75 ( T_1 T_4 * V_88 )
{
return 0 ;
}
static int F_76 ( const struct V_1 * V_2 , T_1 V_49 , void T_4 * V_64 )
{
return - V_67 ;
}
static int F_77 ( struct V_1 * V_2 , T_1 V_49 , const void T_4 * V_64 )
{
return - V_67 ;
}
int F_78 ( struct V_1 * V_2 , const struct V_112 * V_6 )
{
const struct V_3 * V_4 ;
void T_4 * V_64 = ( void T_4 * ) ( long ) V_6 -> V_113 ;
int V_66 ;
if ( ( V_6 -> V_49 & V_53 ) == V_114 )
return F_68 ( V_6 -> V_49 , V_64 ) ;
if ( ( V_6 -> V_49 & V_53 ) == V_91 )
return F_76 ( V_2 , V_6 -> V_49 , V_64 ) ;
V_4 = F_55 ( V_2 , V_6 -> V_49 ) ;
if ( ! V_4 )
return F_61 ( V_6 -> V_49 , V_64 ) ;
V_66 = - V_67 ;
if ( F_58 ( V_6 -> V_49 ) == 8 ) {
T_1 V_5 ;
V_5 = F_3 ( V_2 , V_4 ) ;
V_66 = F_59 ( V_64 , & V_5 , V_6 -> V_49 ) ;
} else if ( F_58 ( V_6 -> V_49 ) == 4 ) {
V_66 = F_59 ( V_64 , & F_2 ( V_2 , V_4 -> V_6 ) , V_6 -> V_49 ) ;
}
return V_66 ;
}
int F_79 ( struct V_1 * V_2 , const struct V_112 * V_6 )
{
const struct V_3 * V_4 ;
void T_4 * V_64 = ( void T_4 * ) ( long ) V_6 -> V_113 ;
int V_66 ;
if ( ( V_6 -> V_49 & V_53 ) == V_114 )
return F_70 ( V_6 -> V_49 , V_64 ) ;
if ( ( V_6 -> V_49 & V_53 ) == V_91 )
return F_77 ( V_2 , V_6 -> V_49 , V_64 ) ;
V_4 = F_55 ( V_2 , V_6 -> V_49 ) ;
if ( ! V_4 )
return F_62 ( V_6 -> V_49 , V_64 ) ;
V_66 = - V_67 ;
if ( F_58 ( V_6 -> V_49 ) == 8 ) {
T_1 V_5 ;
V_66 = F_56 ( & V_5 , V_64 , V_6 -> V_49 ) ;
if ( ! V_66 )
F_1 ( V_2 , V_4 , V_5 ) ;
} else if ( F_58 ( V_6 -> V_49 ) == 4 ) {
V_66 = F_56 ( & F_2 ( V_2 , V_4 -> V_6 ) , V_64 , V_6 -> V_49 ) ;
}
return V_66 ;
}
static unsigned int F_80 ( void )
{
unsigned int V_33 , V_115 = 0 ;
for ( V_33 = 0 ; V_33 < V_74 ; V_33 ++ )
if ( F_63 ( V_33 ) )
V_115 ++ ;
return V_115 ;
}
static int F_81 ( T_1 T_4 * V_88 )
{
T_1 V_5 = V_90 | V_51 | V_114 ;
unsigned int V_33 ;
V_5 |= V_80 ;
for ( V_33 = 0 ; V_33 < V_74 ; V_33 ++ ) {
if ( ! F_63 ( V_33 ) )
continue;
if ( F_69 ( V_5 | V_33 , V_88 ) )
return - V_65 ;
V_88 ++ ;
}
return 0 ;
}
static T_1 F_82 ( const struct V_3 * V_6 )
{
T_1 V_5 = V_90 | ( 15 << V_63 ) ;
if ( V_6 -> V_25 ) {
V_5 |= V_62 ;
V_5 |= ( V_6 -> V_42 << V_60 ) ;
V_5 |= ( V_6 -> V_43 << V_59 ) ;
} else {
V_5 |= V_51 ;
V_5 |= ( V_6 -> V_42 << V_60 ) ;
V_5 |= ( V_6 -> V_45 << V_61 ) ;
V_5 |= ( V_6 -> V_44 << V_59 ) ;
V_5 |= ( V_6 -> V_43 << V_58 ) ;
}
return V_5 ;
}
static bool F_83 ( const struct V_3 * V_6 , T_1 T_4 * * V_116 )
{
if ( ! * V_116 )
return true ;
if ( F_69 ( F_82 ( V_6 ) , * V_116 ) )
return false ;
( * V_116 ) ++ ;
return true ;
}
static int F_84 ( struct V_1 * V_2 , T_1 T_4 * V_116 )
{
const struct V_3 * V_117 , * V_118 , * V_119 , * V_120 ;
unsigned int V_121 = 0 ;
T_3 V_35 ;
V_117 = F_38 ( V_2 -> V_27 . V_37 , & V_35 ) ;
V_119 = V_117 + V_35 ;
V_118 = V_46 ;
V_120 = V_46 + F_44 ( V_46 ) ;
F_28 ( V_117 == V_119 || V_118 == V_120 ) ;
while ( V_117 || V_118 ) {
int V_122 = F_35 ( V_117 , V_118 ) ;
if ( V_122 <= 0 ) {
if ( V_117 -> V_6 ) {
if ( ! F_83 ( V_117 , & V_116 ) )
return - V_65 ;
V_121 ++ ;
}
} else {
if ( V_118 -> V_6 ) {
if ( ! F_83 ( V_118 , & V_116 ) )
return - V_65 ;
V_121 ++ ;
}
}
if ( V_122 <= 0 && ++ V_117 == V_119 )
V_117 = NULL ;
if ( V_122 >= 0 && ++ V_118 == V_120 )
V_118 = NULL ;
}
return V_121 ;
}
unsigned long F_85 ( struct V_1 * V_2 )
{
return F_44 ( V_68 )
+ F_80 ()
+ F_74 ()
+ F_84 ( V_2 , ( T_1 T_4 * ) NULL ) ;
}
int F_86 ( struct V_1 * V_2 , T_1 T_4 * V_88 )
{
unsigned int V_33 ;
int V_69 ;
for ( V_33 = 0 ; V_33 < F_44 ( V_68 ) ; V_33 ++ ) {
if ( F_69 ( F_82 ( & V_68 [ V_33 ] ) , V_88 ) )
return - V_65 ;
V_88 ++ ;
}
V_69 = F_84 ( V_2 , V_88 ) ;
if ( V_69 < 0 )
return V_69 ;
V_88 += V_69 ;
V_69 = F_75 ( V_88 ) ;
if ( V_69 < 0 )
return V_69 ;
V_88 += V_69 ;
return F_81 ( V_88 ) ;
}
void F_87 ( void )
{
unsigned int V_33 ;
F_28 ( F_34 ( V_46 , F_44 ( V_46 ) ) ) ;
F_28 ( F_34 ( V_68 , F_44 ( V_68 ) ) ) ;
for ( V_33 = 0 ; V_33 < F_44 ( V_68 ) ; V_33 ++ )
V_68 [ V_33 ] . V_48 ( NULL , & V_68 [ V_33 ] ) ;
asm volatile("mrc p15, 1, %0, c0, c0, 1" : "=r" (cache_levels));
for ( V_33 = 0 ; V_33 < 7 ; V_33 ++ )
if ( ( ( V_75 >> ( V_33 * 3 ) ) & 7 ) == 0 )
break;
V_75 &= ( 1 << ( V_33 * 3 ) ) - 1 ;
}
void F_88 ( struct V_1 * V_2 )
{
T_3 V_35 ;
const struct V_3 * V_31 ;
memset ( V_2 -> V_27 . V_96 . V_123 , 0x42 , sizeof( V_2 -> V_27 . V_96 . V_123 ) ) ;
F_52 ( V_2 , V_46 , F_44 ( V_46 ) ) ;
V_31 = F_38 ( V_2 -> V_27 . V_37 , & V_35 ) ;
F_52 ( V_2 , V_31 , V_35 ) ;
for ( V_35 = 1 ; V_35 < V_124 ; V_35 ++ )
if ( F_2 ( V_2 , V_35 ) == 0x42424242 )
F_89 ( L_3 , V_35 ) ;
}

static bool F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
F_2 ( 1 , L_1 ) ;
F_3 ( V_4 ) ;
F_4 ( V_2 ) ;
return false ;
}
static bool F_5 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
F_2 ( 1 , L_2 ) ;
F_3 ( V_4 ) ;
F_4 ( V_2 ) ;
return false ;
}
static inline void F_6 ( struct V_1 * V_2 ,
const struct V_5 * V_6 ,
T_1 V_7 )
{
F_7 ( V_2 , V_6 -> V_8 ) = V_7 & 0xffffffff ;
F_7 ( V_2 , V_6 -> V_8 + 1 ) = V_7 >> 32 ;
}
static inline T_1 F_8 ( struct V_1 * V_2 ,
const struct V_5 * V_6 )
{
T_1 V_7 ;
V_7 = F_7 ( V_2 , V_6 -> V_8 + 1 ) ;
V_7 = V_7 << 32 ;
V_7 = V_7 | F_7 ( V_2 , V_6 -> V_8 ) ;
return V_7 ;
}
int F_9 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
F_4 ( V_2 ) ;
return 1 ;
}
int F_10 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
F_4 ( V_2 ) ;
return 1 ;
}
int F_11 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
F_4 ( V_2 ) ;
return 1 ;
}
static void F_12 ( struct V_1 * V_2 , const struct V_5 * V_6 )
{
F_7 ( V_2 , V_11 ) = ( ( F_13 () & V_12 ) |
( ( V_2 -> V_13 >> 2 ) << V_14 ) |
( V_2 -> V_13 & 3 ) ) ;
}
static bool F_14 ( struct V_1 * V_2 ,
const struct V_3 * V_15 ,
const struct V_5 * V_6 )
{
if ( V_15 -> V_16 )
return F_15 ( V_2 , V_15 ) ;
* F_16 ( V_2 , V_15 -> V_17 ) = F_7 ( V_2 , V_18 ) ;
return true ;
}
static bool F_17 ( struct V_1 * V_2 ,
const struct V_3 * V_15 ,
const struct V_5 * V_6 )
{
if ( V_15 -> V_16 )
return F_1 ( V_2 , V_15 ) ;
return F_18 ( V_2 , V_15 ) ;
}
static bool F_19 ( struct V_1 * V_2 ,
const struct V_3 * V_15 ,
const struct V_5 * V_6 )
{
if ( V_15 -> V_16 )
return F_15 ( V_2 , V_15 ) ;
* F_16 ( V_2 , V_15 -> V_17 ) = F_7 ( V_2 , V_19 ) ;
return true ;
}
static void F_20 ( struct V_1 * V_2 , const struct V_5 * V_6 )
{
T_2 V_20 , V_21 ;
asm volatile("mrc p15, 1, %0, c9, c0, 2\n" : "=r" (l2ctlr));
V_20 &= ~ ( 3 << 24 ) ;
V_21 = F_21 ( & V_2 -> V_22 -> V_23 ) - 1 ;
V_21 -= ( V_2 -> V_13 & ~ 3 ) ;
V_21 = F_22 ( V_21 , 3U ) ;
V_20 |= ( V_21 & 3 ) << 24 ;
F_7 ( V_2 , V_19 ) = V_20 ;
}
static void F_23 ( struct V_1 * V_2 , const struct V_5 * V_6 )
{
T_2 V_24 ;
asm volatile("mrc p15, 0, %0, c1, c0, 1\n" : "=r" (actlr));
if ( F_21 ( & V_2 -> V_22 -> V_23 ) > 1 )
V_24 |= 1U << 6 ;
else
V_24 &= ~ ( 1U << 6 ) ;
F_7 ( V_2 , V_18 ) = V_24 ;
}
static bool F_24 ( struct V_1 * V_2 ,
const struct V_3 * V_15 ,
const struct V_5 * V_6 )
{
if ( V_15 -> V_16 )
return F_15 ( V_2 , V_15 ) ;
* F_16 ( V_2 , V_15 -> V_17 ) = 0 ;
return true ;
}
static bool F_25 ( struct V_1 * V_2 ,
const struct V_3 * V_15 ,
const struct V_5 * V_6 )
{
if ( ! V_15 -> V_16 )
return F_5 ( V_2 , V_15 ) ;
F_26 ( V_2 ) ;
return true ;
}
bool F_27 ( struct V_1 * V_2 ,
const struct V_3 * V_15 ,
const struct V_5 * V_6 )
{
bool V_25 = F_28 ( V_2 ) ;
F_29 ( ! V_15 -> V_16 ) ;
F_7 ( V_2 , V_6 -> V_8 ) = * F_16 ( V_2 , V_15 -> V_17 ) ;
if ( V_15 -> V_26 )
F_7 ( V_2 , V_6 -> V_8 + 1 ) = * F_16 ( V_2 , V_15 -> V_27 ) ;
F_30 ( V_2 , V_25 ) ;
return true ;
}
static bool F_31 ( struct V_1 * V_2 ,
const struct V_3 * V_15 ,
const struct V_5 * V_6 )
{
T_1 V_8 ;
if ( ! V_15 -> V_16 )
return F_5 ( V_2 , V_15 ) ;
V_8 = ( T_1 ) * F_16 ( V_2 , V_15 -> V_27 ) << 32 ;
V_8 |= * F_16 ( V_2 , V_15 -> V_17 ) ;
F_32 ( V_2 , V_8 ) ;
return true ;
}
static bool F_33 ( struct V_1 * V_2 ,
const struct V_3 * V_15 ,
const struct V_5 * V_6 )
{
if ( V_15 -> V_16 )
return F_15 ( V_2 , V_15 ) ;
* F_16 ( V_2 , V_15 -> V_17 ) = V_2 -> V_28 . V_29 . V_30 . V_31 ;
return true ;
}
static bool F_34 ( struct V_1 * V_2 ,
const struct V_3 * V_15 ,
const struct V_5 * V_6 )
{
if ( V_15 -> V_16 )
return F_15 ( V_2 , V_15 ) ;
else
return F_18 ( V_2 , V_15 ) ;
}
static int F_35 ( const struct V_5 * V_32 , unsigned int V_33 )
{
unsigned int V_34 ;
for ( V_34 = 1 ; V_34 < V_33 ; V_34 ++ ) {
if ( F_36 ( & V_32 [ V_34 - 1 ] , & V_32 [ V_34 ] ) >= 0 ) {
F_37 ( L_3 , V_32 , V_34 - 1 ) ;
return 1 ;
}
}
return 0 ;
}
void F_38 ( struct V_35 * V_32 )
{
F_29 ( F_35 ( V_32 -> V_32 , V_32 -> V_36 ) ) ;
V_37 [ V_32 -> V_38 ] = V_32 ;
}
static const struct V_5 * F_39 ( unsigned V_38 , T_3 * V_36 )
{
struct V_35 * V_32 ;
V_32 = V_37 [ V_38 ] ;
* V_36 = V_32 -> V_36 ;
return V_32 -> V_32 ;
}
static int F_40 ( const void * V_39 , const void * V_40 )
{
const unsigned long V_41 = ( unsigned long ) V_39 ;
const struct V_5 * V_6 = V_40 ;
return V_41 - F_41 ( V_6 ) ;
}
static const struct V_5 * F_42 ( const struct V_3 * V_4 ,
const struct V_5 V_32 [] ,
unsigned int V_36 )
{
unsigned long V_41 = F_41 ( V_4 ) ;
return bsearch ( ( void * ) V_41 , V_32 , V_36 , sizeof( V_32 [ 0 ] ) , F_40 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
T_3 V_36 ;
const struct V_5 * V_32 , * V_6 ;
F_44 ( V_4 -> V_42 , V_4 -> V_17 , V_4 -> V_43 ,
V_4 -> V_44 , V_4 -> V_45 , V_4 -> V_16 ) ;
V_32 = F_39 ( V_2 -> V_28 . V_38 , & V_36 ) ;
V_6 = F_42 ( V_4 , V_32 , V_36 ) ;
if ( ! V_6 )
V_6 = F_42 ( V_4 , V_46 , F_45 ( V_46 ) ) ;
if ( F_46 ( V_6 ) ) {
F_29 ( ! V_6 -> V_47 ) ;
if ( F_46 ( V_6 -> V_47 ( V_2 , V_4 , V_6 ) ) ) {
F_47 ( V_2 , F_48 ( V_2 ) ) ;
}
} else {
F_37 ( L_4 ,
* F_49 ( V_2 ) ) ;
F_3 ( V_4 ) ;
F_4 ( V_2 ) ;
}
return 1 ;
}
static struct V_3 F_50 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
V_4 . V_43 = ( F_51 ( V_2 ) >> 1 ) & 0xf ;
V_4 . V_17 = ( F_51 ( V_2 ) >> 5 ) & 0xf ;
V_4 . V_16 = ( ( F_51 ( V_2 ) & 1 ) == 0 ) ;
V_4 . V_26 = true ;
V_4 . V_42 = ( F_51 ( V_2 ) >> 16 ) & 0xf ;
V_4 . V_45 = 0 ;
V_4 . V_27 = ( F_51 ( V_2 ) >> 10 ) & 0xf ;
V_4 . V_44 = 0 ;
return V_4 ;
}
int F_52 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_3 V_4 = F_50 ( V_2 ) ;
return F_43 ( V_2 , & V_4 ) ;
}
int F_53 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_3 V_4 = F_50 ( V_2 ) ;
F_34 ( V_2 , & V_4 , NULL ) ;
F_47 ( V_2 , F_48 ( V_2 ) ) ;
return 1 ;
}
static void F_54 ( struct V_1 * V_2 ,
const struct V_5 * V_32 , T_3 V_36 )
{
unsigned long V_34 ;
for ( V_34 = 0 ; V_34 < V_36 ; V_34 ++ )
if ( V_32 [ V_34 ] . V_48 )
V_32 [ V_34 ] . V_48 ( V_2 , & V_32 [ V_34 ] ) ;
}
static struct V_3 F_55 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
V_4 . V_44 = ( F_51 ( V_2 ) >> 1 ) & 0xf ;
V_4 . V_17 = ( F_51 ( V_2 ) >> 5 ) & 0xf ;
V_4 . V_16 = ( ( F_51 ( V_2 ) & 1 ) == 0 ) ;
V_4 . V_26 = false ;
V_4 . V_43 = ( F_51 ( V_2 ) >> 10 ) & 0xf ;
V_4 . V_42 = ( F_51 ( V_2 ) >> 14 ) & 0x7 ;
V_4 . V_45 = ( F_51 ( V_2 ) >> 17 ) & 0x7 ;
V_4 . V_27 = 0 ;
return V_4 ;
}
int F_56 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_3 V_4 = F_55 ( V_2 ) ;
return F_43 ( V_2 , & V_4 ) ;
}
int F_57 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_3 V_4 = F_55 ( V_2 ) ;
F_34 ( V_2 , & V_4 , NULL ) ;
F_47 ( V_2 , F_48 ( V_2 ) ) ;
return 1 ;
}
static bool F_58 ( T_1 V_49 , struct V_3 * V_4 )
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
V_4 -> V_26 = false ;
V_4 -> V_43 = ( ( V_49 & V_54 )
>> V_58 ) ;
V_4 -> V_44 = ( ( V_49 & V_55 )
>> V_59 ) ;
V_4 -> V_42 = ( ( V_49 & V_56 )
>> V_60 ) ;
V_4 -> V_45 = ( ( V_49 & V_57 )
>> V_61 ) ;
return true ;
case V_62 :
if ( V_49 & ~ ( V_52 | V_50
| V_53
| V_55
| V_56 ) )
return false ;
V_4 -> V_26 = true ;
V_4 -> V_43 = ( ( V_49 & V_55 )
>> V_59 ) ;
V_4 -> V_42 = ( ( V_49 & V_56 )
>> V_60 ) ;
V_4 -> V_45 = 0 ;
V_4 -> V_44 = 0 ;
return true ;
default:
return false ;
}
}
static const struct V_5 * F_59 ( struct V_1 * V_2 ,
T_1 V_49 )
{
T_3 V_36 ;
const struct V_5 * V_32 , * V_6 ;
struct V_3 V_4 ;
if ( ( V_49 & V_53 ) >> V_63 != 15 )
return NULL ;
if ( ! F_58 ( V_49 , & V_4 ) )
return NULL ;
V_32 = F_39 ( V_2 -> V_28 . V_38 , & V_36 ) ;
V_6 = F_42 ( & V_4 , V_32 , V_36 ) ;
if ( ! V_6 )
V_6 = F_42 ( & V_4 , V_46 , F_45 ( V_46 ) ) ;
if ( V_6 && ! V_6 -> V_8 )
V_6 = NULL ;
return V_6 ;
}
static int F_60 ( void * V_7 , const void T_4 * V_64 , T_1 V_49 )
{
if ( F_61 ( V_7 , V_64 , F_62 ( V_49 ) ) != 0 )
return - V_65 ;
return 0 ;
}
static int F_63 ( void T_4 * V_64 , const void * V_7 , T_1 V_49 )
{
if ( F_64 ( V_64 , V_7 , F_62 ( V_49 ) ) != 0 )
return - V_65 ;
return 0 ;
}
static int F_65 ( T_1 V_49 , void T_4 * V_64 )
{
struct V_3 V_4 ;
const struct V_5 * V_6 ;
int V_66 ;
if ( ! F_58 ( V_49 , & V_4 ) )
return - V_67 ;
V_6 = F_42 ( & V_4 , V_68 , F_45 ( V_68 ) ) ;
if ( ! V_6 )
return - V_67 ;
V_66 = - V_67 ;
if ( F_62 ( V_49 ) == 4 ) {
T_2 V_7 = V_6 -> V_7 ;
V_66 = F_63 ( V_64 , & V_7 , V_49 ) ;
} else if ( F_62 ( V_49 ) == 8 ) {
V_66 = F_63 ( V_64 , & V_6 -> V_7 , V_49 ) ;
}
return V_66 ;
}
static int F_66 ( T_1 V_49 , void T_4 * V_64 )
{
struct V_3 V_4 ;
const struct V_5 * V_6 ;
int V_69 ;
T_1 V_7 ;
if ( ! F_58 ( V_49 , & V_4 ) )
return - V_67 ;
V_6 = F_42 ( & V_4 , V_68 , F_45 ( V_68 ) ) ;
if ( ! V_6 )
return - V_67 ;
V_69 = - V_67 ;
if ( F_62 ( V_49 ) == 4 ) {
T_2 V_70 ;
V_69 = F_60 ( & V_70 , V_64 , V_49 ) ;
if ( ! V_69 )
V_7 = V_70 ;
} else if ( F_62 ( V_49 ) == 8 ) {
V_69 = F_60 ( & V_7 , V_64 , V_49 ) ;
}
if ( V_69 )
return V_69 ;
if ( V_6 -> V_7 != V_7 )
return - V_71 ;
return 0 ;
}
static bool F_67 ( T_2 V_7 )
{
T_2 V_72 , V_73 ;
if ( V_7 >= V_74 )
return false ;
V_72 = ( V_7 >> 1 ) ;
V_73 = ( V_75 >> ( V_72 * 3 ) ) & 7 ;
switch ( V_73 ) {
case 0 :
return false ;
case 1 :
return ( V_7 & 1 ) ;
case 2 :
case 4 :
return ! ( V_7 & 1 ) ;
case 3 :
return true ;
default:
return false ;
}
}
static T_2 F_68 ( T_2 V_76 )
{
T_2 V_77 ;
F_69 () ;
asm volatile("mcr p15, 2, %0, c0, c0, 0" : : "r" (csselr));
F_70 () ;
asm volatile("mrc p15, 1, %0, c0, c0, 0" : "=r" (ccsidr));
F_71 () ;
return V_77 ;
}
static int F_72 ( T_1 V_49 , void T_4 * V_64 )
{
T_2 V_7 ;
T_2 T_4 * V_78 = V_64 ;
if ( V_49 & ~ ( V_52 | V_50 | V_53
| ( ( 1 << V_63 ) - 1 ) ) )
return - V_67 ;
switch ( V_49 & V_79 ) {
case V_80 :
if ( F_62 ( V_49 ) != 4 )
return - V_67 ;
V_7 = ( V_49 & V_81 )
>> V_82 ;
if ( ! F_67 ( V_7 ) )
return - V_67 ;
return F_73 ( F_68 ( V_7 ) , V_78 ) ;
default:
return - V_67 ;
}
}
static int F_74 ( T_1 V_49 , void T_4 * V_64 )
{
T_2 V_7 , V_83 ;
T_2 T_4 * V_78 = V_64 ;
if ( V_49 & ~ ( V_52 | V_50 | V_53
| ( ( 1 << V_63 ) - 1 ) ) )
return - V_67 ;
switch ( V_49 & V_79 ) {
case V_80 :
if ( F_62 ( V_49 ) != 4 )
return - V_67 ;
V_7 = ( V_49 & V_81 )
>> V_82 ;
if ( ! F_67 ( V_7 ) )
return - V_67 ;
if ( F_75 ( V_83 , V_78 ) )
return - V_65 ;
if ( V_83 != F_68 ( V_7 ) )
return - V_71 ;
return 0 ;
default:
return - V_67 ;
}
}
static unsigned int F_76 ( void )
{
if ( ( ( F_77 ( V_84 ) & V_85 ) >> V_86 ) == 2 )
return 32 ;
else
return 16 ;
}
static unsigned int F_78 ( void )
{
return F_76 () + F_45 ( V_87 ) ;
}
static int F_79 ( T_1 T_4 * V_88 )
{
unsigned int V_34 ;
const T_1 V_89 = V_90 | V_51 | V_91 ;
const T_1 V_92 = V_90 | V_62 | V_91 ;
for ( V_34 = 0 ; V_34 < F_76 () ; V_34 ++ ) {
if ( F_73 ( ( V_92 | V_93 ) + V_34 ,
V_88 ) )
return - V_65 ;
V_88 ++ ;
}
for ( V_34 = 0 ; V_34 < F_45 ( V_87 ) ; V_34 ++ ) {
if ( F_73 ( V_89 | V_87 [ V_34 ] , V_88 ) )
return - V_65 ;
V_88 ++ ;
}
return F_78 () ;
}
static int F_80 ( const struct V_1 * V_2 , T_1 V_49 , void T_4 * V_64 )
{
T_2 V_94 = ( V_49 & V_95 ) ;
T_2 V_7 ;
if ( V_49 & ~ ( V_52 | V_50 | V_53
| ( ( 1 << V_63 ) - 1 ) ) )
return - V_67 ;
if ( V_94 < F_76 () ) {
if ( F_62 ( V_49 ) != 8 )
return - V_67 ;
return F_63 ( V_64 , & V_2 -> V_28 . V_96 . V_97 . V_98 [ V_94 ] ,
V_49 ) ;
}
if ( F_62 ( V_49 ) != 4 )
return - V_67 ;
switch ( V_94 ) {
case V_99 :
return F_63 ( V_64 , & V_2 -> V_28 . V_96 . V_97 . V_100 , V_49 ) ;
case V_101 :
return F_63 ( V_64 , & V_2 -> V_28 . V_96 . V_97 . V_102 , V_49 ) ;
case V_103 :
return F_63 ( V_64 , & V_2 -> V_28 . V_96 . V_97 . V_104 , V_49 ) ;
case V_105 :
return F_63 ( V_64 , & V_2 -> V_28 . V_96 . V_97 . V_106 , V_49 ) ;
case V_107 :
V_7 = F_77 ( V_84 ) ;
return F_63 ( V_64 , & V_7 , V_49 ) ;
case V_108 :
V_7 = F_77 ( V_109 ) ;
return F_63 ( V_64 , & V_7 , V_49 ) ;
case V_110 :
V_7 = F_77 ( V_111 ) ;
return F_63 ( V_64 , & V_7 , V_49 ) ;
default:
return - V_67 ;
}
}
static int F_81 ( struct V_1 * V_2 , T_1 V_49 , const void T_4 * V_64 )
{
T_2 V_94 = ( V_49 & V_95 ) ;
T_2 V_7 ;
if ( V_49 & ~ ( V_52 | V_50 | V_53
| ( ( 1 << V_63 ) - 1 ) ) )
return - V_67 ;
if ( V_94 < F_76 () ) {
if ( F_62 ( V_49 ) != 8 )
return - V_67 ;
return F_60 ( & V_2 -> V_28 . V_96 . V_97 . V_98 [ V_94 ] ,
V_64 , V_49 ) ;
}
if ( F_62 ( V_49 ) != 4 )
return - V_67 ;
switch ( V_94 ) {
case V_99 :
return F_60 ( & V_2 -> V_28 . V_96 . V_97 . V_100 , V_64 , V_49 ) ;
case V_101 :
return F_60 ( & V_2 -> V_28 . V_96 . V_97 . V_102 , V_64 , V_49 ) ;
case V_103 :
return F_60 ( & V_2 -> V_28 . V_96 . V_97 . V_104 , V_64 , V_49 ) ;
case V_105 :
return F_60 ( & V_2 -> V_28 . V_96 . V_97 . V_106 , V_64 , V_49 ) ;
case V_107 :
if ( F_60 ( & V_7 , V_64 , V_49 ) )
return - V_65 ;
if ( V_7 != F_77 ( V_84 ) )
return - V_71 ;
return 0 ;
case V_108 :
if ( F_60 ( & V_7 , V_64 , V_49 ) )
return - V_65 ;
if ( V_7 != F_77 ( V_109 ) )
return - V_71 ;
return 0 ;
case V_110 :
if ( F_60 ( & V_7 , V_64 , V_49 ) )
return - V_65 ;
if ( V_7 != F_77 ( V_111 ) )
return - V_71 ;
return 0 ;
default:
return - V_67 ;
}
}
static unsigned int F_78 ( void )
{
return 0 ;
}
static int F_79 ( T_1 T_4 * V_88 )
{
return 0 ;
}
static int F_80 ( const struct V_1 * V_2 , T_1 V_49 , void T_4 * V_64 )
{
return - V_67 ;
}
static int F_81 ( struct V_1 * V_2 , T_1 V_49 , const void T_4 * V_64 )
{
return - V_67 ;
}
int F_82 ( struct V_1 * V_2 , const struct V_112 * V_8 )
{
const struct V_5 * V_6 ;
void T_4 * V_64 = ( void T_4 * ) ( long ) V_8 -> V_113 ;
int V_66 ;
if ( ( V_8 -> V_49 & V_53 ) == V_114 )
return F_72 ( V_8 -> V_49 , V_64 ) ;
if ( ( V_8 -> V_49 & V_53 ) == V_91 )
return F_80 ( V_2 , V_8 -> V_49 , V_64 ) ;
V_6 = F_59 ( V_2 , V_8 -> V_49 ) ;
if ( ! V_6 )
return F_65 ( V_8 -> V_49 , V_64 ) ;
V_66 = - V_67 ;
if ( F_62 ( V_8 -> V_49 ) == 8 ) {
T_1 V_7 ;
V_7 = F_8 ( V_2 , V_6 ) ;
V_66 = F_63 ( V_64 , & V_7 , V_8 -> V_49 ) ;
} else if ( F_62 ( V_8 -> V_49 ) == 4 ) {
V_66 = F_63 ( V_64 , & F_7 ( V_2 , V_6 -> V_8 ) , V_8 -> V_49 ) ;
}
return V_66 ;
}
int F_83 ( struct V_1 * V_2 , const struct V_112 * V_8 )
{
const struct V_5 * V_6 ;
void T_4 * V_64 = ( void T_4 * ) ( long ) V_8 -> V_113 ;
int V_66 ;
if ( ( V_8 -> V_49 & V_53 ) == V_114 )
return F_74 ( V_8 -> V_49 , V_64 ) ;
if ( ( V_8 -> V_49 & V_53 ) == V_91 )
return F_81 ( V_2 , V_8 -> V_49 , V_64 ) ;
V_6 = F_59 ( V_2 , V_8 -> V_49 ) ;
if ( ! V_6 )
return F_66 ( V_8 -> V_49 , V_64 ) ;
V_66 = - V_67 ;
if ( F_62 ( V_8 -> V_49 ) == 8 ) {
T_1 V_7 ;
V_66 = F_60 ( & V_7 , V_64 , V_8 -> V_49 ) ;
if ( ! V_66 )
F_6 ( V_2 , V_6 , V_7 ) ;
} else if ( F_62 ( V_8 -> V_49 ) == 4 ) {
V_66 = F_60 ( & F_7 ( V_2 , V_6 -> V_8 ) , V_64 , V_8 -> V_49 ) ;
}
return V_66 ;
}
static unsigned int F_84 ( void )
{
unsigned int V_34 , V_115 = 0 ;
for ( V_34 = 0 ; V_34 < V_74 ; V_34 ++ )
if ( F_67 ( V_34 ) )
V_115 ++ ;
return V_115 ;
}
static int F_85 ( T_1 T_4 * V_88 )
{
T_1 V_7 = V_90 | V_51 | V_114 ;
unsigned int V_34 ;
V_7 |= V_80 ;
for ( V_34 = 0 ; V_34 < V_74 ; V_34 ++ ) {
if ( ! F_67 ( V_34 ) )
continue;
if ( F_73 ( V_7 | V_34 , V_88 ) )
return - V_65 ;
V_88 ++ ;
}
return 0 ;
}
static T_1 F_86 ( const struct V_5 * V_8 )
{
T_1 V_7 = V_90 | ( 15 << V_63 ) ;
if ( V_8 -> V_26 ) {
V_7 |= V_62 ;
V_7 |= ( V_8 -> V_42 << V_60 ) ;
V_7 |= ( V_8 -> V_43 << V_59 ) ;
} else {
V_7 |= V_51 ;
V_7 |= ( V_8 -> V_42 << V_60 ) ;
V_7 |= ( V_8 -> V_45 << V_61 ) ;
V_7 |= ( V_8 -> V_44 << V_59 ) ;
V_7 |= ( V_8 -> V_43 << V_58 ) ;
}
return V_7 ;
}
static bool F_87 ( const struct V_5 * V_8 , T_1 T_4 * * V_116 )
{
if ( ! * V_116 )
return true ;
if ( F_73 ( F_86 ( V_8 ) , * V_116 ) )
return false ;
( * V_116 ) ++ ;
return true ;
}
static int F_88 ( struct V_1 * V_2 , T_1 T_4 * V_116 )
{
const struct V_5 * V_117 , * V_118 , * V_119 , * V_120 ;
unsigned int V_121 = 0 ;
T_3 V_36 ;
V_117 = F_39 ( V_2 -> V_28 . V_38 , & V_36 ) ;
V_119 = V_117 + V_36 ;
V_118 = V_46 ;
V_120 = V_46 + F_45 ( V_46 ) ;
F_29 ( V_117 == V_119 || V_118 == V_120 ) ;
while ( V_117 || V_118 ) {
int V_122 = F_36 ( V_117 , V_118 ) ;
if ( V_122 <= 0 ) {
if ( V_117 -> V_8 ) {
if ( ! F_87 ( V_117 , & V_116 ) )
return - V_65 ;
V_121 ++ ;
}
} else {
if ( V_118 -> V_8 ) {
if ( ! F_87 ( V_118 , & V_116 ) )
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
unsigned long F_89 ( struct V_1 * V_2 )
{
return F_45 ( V_68 )
+ F_84 ()
+ F_78 ()
+ F_88 ( V_2 , ( T_1 T_4 * ) NULL ) ;
}
int F_90 ( struct V_1 * V_2 , T_1 T_4 * V_88 )
{
unsigned int V_34 ;
int V_69 ;
for ( V_34 = 0 ; V_34 < F_45 ( V_68 ) ; V_34 ++ ) {
if ( F_73 ( F_86 ( & V_68 [ V_34 ] ) , V_88 ) )
return - V_65 ;
V_88 ++ ;
}
V_69 = F_88 ( V_2 , V_88 ) ;
if ( V_69 < 0 )
return V_69 ;
V_88 += V_69 ;
V_69 = F_79 ( V_88 ) ;
if ( V_69 < 0 )
return V_69 ;
V_88 += V_69 ;
return F_85 ( V_88 ) ;
}
void F_91 ( void )
{
unsigned int V_34 ;
F_29 ( F_35 ( V_46 , F_45 ( V_46 ) ) ) ;
F_29 ( F_35 ( V_68 , F_45 ( V_68 ) ) ) ;
for ( V_34 = 0 ; V_34 < F_45 ( V_68 ) ; V_34 ++ )
V_68 [ V_34 ] . V_48 ( NULL , & V_68 [ V_34 ] ) ;
asm volatile("mrc p15, 1, %0, c0, c0, 1" : "=r" (cache_levels));
for ( V_34 = 0 ; V_34 < 7 ; V_34 ++ )
if ( ( ( V_75 >> ( V_34 * 3 ) ) & 7 ) == 0 )
break;
V_75 &= ( 1 << ( V_34 * 3 ) ) - 1 ;
}
void F_92 ( struct V_1 * V_2 )
{
T_3 V_36 ;
const struct V_5 * V_32 ;
memset ( V_2 -> V_28 . V_96 . V_123 , 0x42 , sizeof( V_2 -> V_28 . V_96 . V_123 ) ) ;
F_54 ( V_2 , V_46 , F_45 ( V_46 ) ) ;
V_32 = F_39 ( V_2 -> V_28 . V_38 , & V_36 ) ;
F_54 ( V_2 , V_32 , V_36 ) ;
for ( V_36 = 1 ; V_36 < V_124 ; V_36 ++ )
if ( F_7 ( V_2 , V_36 ) == 0x42424242 )
F_93 ( L_5 , V_36 ) ;
}

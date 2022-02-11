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
if ( V_14 -> V_15 )
return F_12 ( V_2 , V_14 ) ;
else
return F_16 ( V_2 , V_14 ) ;
}
static int F_31 ( const struct V_3 * V_27 , unsigned int V_28 )
{
unsigned int V_29 ;
for ( V_29 = 1 ; V_29 < V_28 ; V_29 ++ ) {
if ( F_32 ( & V_27 [ V_29 - 1 ] , & V_27 [ V_29 ] ) >= 0 ) {
F_33 ( L_1 , V_27 , V_29 - 1 ) ;
return 1 ;
}
}
return 0 ;
}
void F_34 ( struct V_30 * V_27 )
{
F_28 ( F_31 ( V_27 -> V_27 , V_27 -> V_31 ) ) ;
V_32 [ V_27 -> V_33 ] = V_27 ;
}
static const struct V_3 * F_35 ( unsigned V_33 , T_3 * V_31 )
{
struct V_30 * V_27 ;
V_27 = V_32 [ V_33 ] ;
* V_31 = V_27 -> V_31 ;
return V_27 -> V_27 ;
}
static int F_36 ( const void * V_34 , const void * V_35 )
{
const unsigned long V_36 = ( unsigned long ) V_34 ;
const struct V_3 * V_4 = V_35 ;
return V_36 - F_37 ( V_4 ) ;
}
static const struct V_3 * F_38 ( const struct V_13 * V_37 ,
const struct V_3 V_27 [] ,
unsigned int V_31 )
{
unsigned long V_36 = F_37 ( V_37 ) ;
return bsearch ( ( void * ) V_36 , V_27 , V_31 , sizeof( V_27 [ 0 ] ) , F_36 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
const struct V_13 * V_37 )
{
T_3 V_31 ;
const struct V_3 * V_27 , * V_4 ;
F_40 ( V_37 -> V_38 , V_37 -> V_16 , V_37 -> V_39 ,
V_37 -> V_40 , V_37 -> V_41 , V_37 -> V_15 ) ;
V_27 = F_35 ( V_2 -> V_42 . V_33 , & V_31 ) ;
V_4 = F_38 ( V_37 , V_27 , V_31 ) ;
if ( ! V_4 )
V_4 = F_38 ( V_37 , V_43 , F_41 ( V_43 ) ) ;
if ( F_42 ( V_4 ) ) {
F_28 ( ! V_4 -> V_44 ) ;
if ( F_42 ( V_4 -> V_44 ( V_2 , V_37 , V_4 ) ) ) {
F_43 ( V_2 , F_44 ( V_2 ) ) ;
return 1 ;
}
} else {
F_33 ( L_2 ,
* F_45 ( V_2 ) ) ;
F_46 ( V_37 ) ;
}
F_5 ( V_2 ) ;
return 1 ;
}
int F_47 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_13 V_37 ;
V_37 . V_39 = ( F_48 ( V_2 ) >> 1 ) & 0xf ;
V_37 . V_16 = ( F_48 ( V_2 ) >> 5 ) & 0xf ;
V_37 . V_15 = ( ( F_48 ( V_2 ) & 1 ) == 0 ) ;
V_37 . V_25 = true ;
V_37 . V_38 = ( F_48 ( V_2 ) >> 16 ) & 0xf ;
V_37 . V_41 = 0 ;
V_37 . V_26 = ( F_48 ( V_2 ) >> 10 ) & 0xf ;
V_37 . V_40 = 0 ;
return F_39 ( V_2 , & V_37 ) ;
}
static void F_49 ( struct V_1 * V_2 ,
const struct V_3 * V_27 , T_3 V_31 )
{
unsigned long V_29 ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ )
if ( V_27 [ V_29 ] . V_45 )
V_27 [ V_29 ] . V_45 ( V_2 , & V_27 [ V_29 ] ) ;
}
int F_50 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_13 V_37 ;
V_37 . V_40 = ( F_48 ( V_2 ) >> 1 ) & 0xf ;
V_37 . V_16 = ( F_48 ( V_2 ) >> 5 ) & 0xf ;
V_37 . V_15 = ( ( F_48 ( V_2 ) & 1 ) == 0 ) ;
V_37 . V_25 = false ;
V_37 . V_39 = ( F_48 ( V_2 ) >> 10 ) & 0xf ;
V_37 . V_38 = ( F_48 ( V_2 ) >> 14 ) & 0x7 ;
V_37 . V_41 = ( F_48 ( V_2 ) >> 17 ) & 0x7 ;
V_37 . V_26 = 0 ;
return F_39 ( V_2 , & V_37 ) ;
}
static bool F_51 ( T_1 V_46 , struct V_13 * V_37 )
{
switch ( V_46 & V_47 ) {
case V_48 :
if ( V_46 & ~ ( V_49 | V_47
| V_50
| V_51
| V_52
| V_53
| V_54 ) )
return false ;
V_37 -> V_25 = false ;
V_37 -> V_39 = ( ( V_46 & V_51 )
>> V_55 ) ;
V_37 -> V_40 = ( ( V_46 & V_52 )
>> V_56 ) ;
V_37 -> V_38 = ( ( V_46 & V_53 )
>> V_57 ) ;
V_37 -> V_41 = ( ( V_46 & V_54 )
>> V_58 ) ;
return true ;
case V_59 :
if ( V_46 & ~ ( V_49 | V_47
| V_50
| V_52
| V_53 ) )
return false ;
V_37 -> V_25 = true ;
V_37 -> V_39 = ( ( V_46 & V_52 )
>> V_56 ) ;
V_37 -> V_38 = ( ( V_46 & V_53 )
>> V_57 ) ;
V_37 -> V_41 = 0 ;
V_37 -> V_40 = 0 ;
return true ;
default:
return false ;
}
}
static const struct V_3 * F_52 ( struct V_1 * V_2 ,
T_1 V_46 )
{
T_3 V_31 ;
const struct V_3 * V_27 , * V_4 ;
struct V_13 V_37 ;
if ( ( V_46 & V_50 ) >> V_60 != 15 )
return NULL ;
if ( ! F_51 ( V_46 , & V_37 ) )
return NULL ;
V_27 = F_35 ( V_2 -> V_42 . V_33 , & V_31 ) ;
V_4 = F_38 ( & V_37 , V_27 , V_31 ) ;
if ( ! V_4 )
V_4 = F_38 ( & V_37 , V_43 , F_41 ( V_43 ) ) ;
if ( V_4 && ! V_4 -> V_6 )
V_4 = NULL ;
return V_4 ;
}
static int F_53 ( void * V_5 , const void T_4 * V_61 , T_1 V_46 )
{
if ( F_54 ( V_5 , V_61 , F_55 ( V_46 ) ) != 0 )
return - V_62 ;
return 0 ;
}
static int F_56 ( void T_4 * V_61 , const void * V_5 , T_1 V_46 )
{
if ( F_57 ( V_61 , V_5 , F_55 ( V_46 ) ) != 0 )
return - V_62 ;
return 0 ;
}
static int F_58 ( T_1 V_46 , void T_4 * V_61 )
{
struct V_13 V_37 ;
const struct V_3 * V_4 ;
int V_63 ;
if ( ! F_51 ( V_46 , & V_37 ) )
return - V_64 ;
V_4 = F_38 ( & V_37 , V_65 , F_41 ( V_65 ) ) ;
if ( ! V_4 )
return - V_64 ;
V_63 = - V_64 ;
if ( F_55 ( V_46 ) == 4 ) {
T_2 V_5 = V_4 -> V_5 ;
V_63 = F_56 ( V_61 , & V_5 , V_46 ) ;
} else if ( F_55 ( V_46 ) == 8 ) {
V_63 = F_56 ( V_61 , & V_4 -> V_5 , V_46 ) ;
}
return V_63 ;
}
static int F_59 ( T_1 V_46 , void T_4 * V_61 )
{
struct V_13 V_37 ;
const struct V_3 * V_4 ;
int V_66 ;
T_1 V_5 ;
if ( ! F_51 ( V_46 , & V_37 ) )
return - V_64 ;
V_4 = F_38 ( & V_37 , V_65 , F_41 ( V_65 ) ) ;
if ( ! V_4 )
return - V_64 ;
V_66 = - V_64 ;
if ( F_55 ( V_46 ) == 4 ) {
T_2 V_67 ;
V_66 = F_53 ( & V_67 , V_61 , V_46 ) ;
if ( ! V_66 )
V_5 = V_67 ;
} else if ( F_55 ( V_46 ) == 8 ) {
V_66 = F_53 ( & V_5 , V_61 , V_46 ) ;
}
if ( V_66 )
return V_66 ;
if ( V_4 -> V_5 != V_5 )
return - V_68 ;
return 0 ;
}
static bool F_60 ( T_2 V_5 )
{
T_2 V_69 , V_70 ;
if ( V_5 >= V_71 )
return false ;
V_69 = ( V_5 >> 1 ) ;
V_70 = ( V_72 >> ( V_69 * 3 ) ) & 7 ;
switch ( V_70 ) {
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
static T_2 F_61 ( T_2 V_73 )
{
T_2 V_74 ;
F_62 () ;
asm volatile("mcr p15, 2, %0, c0, c0, 0" : : "r" (csselr));
F_63 () ;
asm volatile("mrc p15, 1, %0, c0, c0, 0" : "=r" (ccsidr));
F_64 () ;
return V_74 ;
}
static int F_65 ( T_1 V_46 , void T_4 * V_61 )
{
T_2 V_5 ;
T_2 T_4 * V_75 = V_61 ;
if ( V_46 & ~ ( V_49 | V_47 | V_50
| ( ( 1 << V_60 ) - 1 ) ) )
return - V_64 ;
switch ( V_46 & V_76 ) {
case V_77 :
if ( F_55 ( V_46 ) != 4 )
return - V_64 ;
V_5 = ( V_46 & V_78 )
>> V_79 ;
if ( ! F_60 ( V_5 ) )
return - V_64 ;
return F_66 ( F_61 ( V_5 ) , V_75 ) ;
default:
return - V_64 ;
}
}
static int F_67 ( T_1 V_46 , void T_4 * V_61 )
{
T_2 V_5 , V_80 ;
T_2 T_4 * V_75 = V_61 ;
if ( V_46 & ~ ( V_49 | V_47 | V_50
| ( ( 1 << V_60 ) - 1 ) ) )
return - V_64 ;
switch ( V_46 & V_76 ) {
case V_77 :
if ( F_55 ( V_46 ) != 4 )
return - V_64 ;
V_5 = ( V_46 & V_78 )
>> V_79 ;
if ( ! F_60 ( V_5 ) )
return - V_64 ;
if ( F_68 ( V_80 , V_75 ) )
return - V_62 ;
if ( V_80 != F_61 ( V_5 ) )
return - V_68 ;
return 0 ;
default:
return - V_64 ;
}
}
static unsigned int F_69 ( void )
{
if ( ( ( F_70 ( V_81 ) & V_82 ) >> V_83 ) == 2 )
return 32 ;
else
return 16 ;
}
static unsigned int F_71 ( void )
{
return F_69 () + F_41 ( V_84 ) ;
}
static int F_72 ( T_1 T_4 * V_85 )
{
unsigned int V_29 ;
const T_1 V_86 = V_87 | V_48 | V_88 ;
const T_1 V_89 = V_87 | V_59 | V_88 ;
for ( V_29 = 0 ; V_29 < F_69 () ; V_29 ++ ) {
if ( F_66 ( ( V_89 | V_90 ) + V_29 ,
V_85 ) )
return - V_62 ;
V_85 ++ ;
}
for ( V_29 = 0 ; V_29 < F_41 ( V_84 ) ; V_29 ++ ) {
if ( F_66 ( V_86 | V_84 [ V_29 ] , V_85 ) )
return - V_62 ;
V_85 ++ ;
}
return F_71 () ;
}
static int F_73 ( const struct V_1 * V_2 , T_1 V_46 , void T_4 * V_61 )
{
T_2 V_91 = ( V_46 & V_92 ) ;
T_2 V_5 ;
if ( V_46 & ~ ( V_49 | V_47 | V_50
| ( ( 1 << V_60 ) - 1 ) ) )
return - V_64 ;
if ( V_91 < F_69 () ) {
if ( F_55 ( V_46 ) != 8 )
return - V_64 ;
return F_56 ( V_61 , & V_2 -> V_42 . V_93 . V_94 . V_95 [ V_91 ] ,
V_46 ) ;
}
if ( F_55 ( V_46 ) != 4 )
return - V_64 ;
switch ( V_91 ) {
case V_96 :
return F_56 ( V_61 , & V_2 -> V_42 . V_93 . V_94 . V_97 , V_46 ) ;
case V_98 :
return F_56 ( V_61 , & V_2 -> V_42 . V_93 . V_94 . V_99 , V_46 ) ;
case V_100 :
return F_56 ( V_61 , & V_2 -> V_42 . V_93 . V_94 . V_101 , V_46 ) ;
case V_102 :
return F_56 ( V_61 , & V_2 -> V_42 . V_93 . V_94 . V_103 , V_46 ) ;
case V_104 :
V_5 = F_70 ( V_81 ) ;
return F_56 ( V_61 , & V_5 , V_46 ) ;
case V_105 :
V_5 = F_70 ( V_106 ) ;
return F_56 ( V_61 , & V_5 , V_46 ) ;
case V_107 :
V_5 = F_70 ( V_108 ) ;
return F_56 ( V_61 , & V_5 , V_46 ) ;
default:
return - V_64 ;
}
}
static int F_74 ( struct V_1 * V_2 , T_1 V_46 , const void T_4 * V_61 )
{
T_2 V_91 = ( V_46 & V_92 ) ;
T_2 V_5 ;
if ( V_46 & ~ ( V_49 | V_47 | V_50
| ( ( 1 << V_60 ) - 1 ) ) )
return - V_64 ;
if ( V_91 < F_69 () ) {
if ( F_55 ( V_46 ) != 8 )
return - V_64 ;
return F_53 ( & V_2 -> V_42 . V_93 . V_94 . V_95 [ V_91 ] ,
V_61 , V_46 ) ;
}
if ( F_55 ( V_46 ) != 4 )
return - V_64 ;
switch ( V_91 ) {
case V_96 :
return F_53 ( & V_2 -> V_42 . V_93 . V_94 . V_97 , V_61 , V_46 ) ;
case V_98 :
return F_53 ( & V_2 -> V_42 . V_93 . V_94 . V_99 , V_61 , V_46 ) ;
case V_100 :
return F_53 ( & V_2 -> V_42 . V_93 . V_94 . V_101 , V_61 , V_46 ) ;
case V_102 :
return F_53 ( & V_2 -> V_42 . V_93 . V_94 . V_103 , V_61 , V_46 ) ;
case V_104 :
if ( F_53 ( & V_5 , V_61 , V_46 ) )
return - V_62 ;
if ( V_5 != F_70 ( V_81 ) )
return - V_68 ;
return 0 ;
case V_105 :
if ( F_53 ( & V_5 , V_61 , V_46 ) )
return - V_62 ;
if ( V_5 != F_70 ( V_106 ) )
return - V_68 ;
return 0 ;
case V_107 :
if ( F_53 ( & V_5 , V_61 , V_46 ) )
return - V_62 ;
if ( V_5 != F_70 ( V_108 ) )
return - V_68 ;
return 0 ;
default:
return - V_64 ;
}
}
static unsigned int F_71 ( void )
{
return 0 ;
}
static int F_72 ( T_1 T_4 * V_85 )
{
return 0 ;
}
static int F_73 ( const struct V_1 * V_2 , T_1 V_46 , void T_4 * V_61 )
{
return - V_64 ;
}
static int F_74 ( struct V_1 * V_2 , T_1 V_46 , const void T_4 * V_61 )
{
return - V_64 ;
}
int F_75 ( struct V_1 * V_2 , const struct V_109 * V_6 )
{
const struct V_3 * V_4 ;
void T_4 * V_61 = ( void T_4 * ) ( long ) V_6 -> V_110 ;
int V_63 ;
if ( ( V_6 -> V_46 & V_50 ) == V_111 )
return F_65 ( V_6 -> V_46 , V_61 ) ;
if ( ( V_6 -> V_46 & V_50 ) == V_88 )
return F_73 ( V_2 , V_6 -> V_46 , V_61 ) ;
V_4 = F_52 ( V_2 , V_6 -> V_46 ) ;
if ( ! V_4 )
return F_58 ( V_6 -> V_46 , V_61 ) ;
V_63 = - V_64 ;
if ( F_55 ( V_6 -> V_46 ) == 8 ) {
T_1 V_5 ;
V_5 = F_3 ( V_2 , V_4 ) ;
V_63 = F_56 ( V_61 , & V_5 , V_6 -> V_46 ) ;
} else if ( F_55 ( V_6 -> V_46 ) == 4 ) {
V_63 = F_56 ( V_61 , & F_2 ( V_2 , V_4 -> V_6 ) , V_6 -> V_46 ) ;
}
return V_63 ;
}
int F_76 ( struct V_1 * V_2 , const struct V_109 * V_6 )
{
const struct V_3 * V_4 ;
void T_4 * V_61 = ( void T_4 * ) ( long ) V_6 -> V_110 ;
int V_63 ;
if ( ( V_6 -> V_46 & V_50 ) == V_111 )
return F_67 ( V_6 -> V_46 , V_61 ) ;
if ( ( V_6 -> V_46 & V_50 ) == V_88 )
return F_74 ( V_2 , V_6 -> V_46 , V_61 ) ;
V_4 = F_52 ( V_2 , V_6 -> V_46 ) ;
if ( ! V_4 )
return F_59 ( V_6 -> V_46 , V_61 ) ;
V_63 = - V_64 ;
if ( F_55 ( V_6 -> V_46 ) == 8 ) {
T_1 V_5 ;
V_63 = F_53 ( & V_5 , V_61 , V_6 -> V_46 ) ;
if ( ! V_63 )
F_1 ( V_2 , V_4 , V_5 ) ;
} else if ( F_55 ( V_6 -> V_46 ) == 4 ) {
V_63 = F_53 ( & F_2 ( V_2 , V_4 -> V_6 ) , V_61 , V_6 -> V_46 ) ;
}
return V_63 ;
}
static unsigned int F_77 ( void )
{
unsigned int V_29 , V_112 = 0 ;
for ( V_29 = 0 ; V_29 < V_71 ; V_29 ++ )
if ( F_60 ( V_29 ) )
V_112 ++ ;
return V_112 ;
}
static int F_78 ( T_1 T_4 * V_85 )
{
T_1 V_5 = V_87 | V_48 | V_111 ;
unsigned int V_29 ;
V_5 |= V_77 ;
for ( V_29 = 0 ; V_29 < V_71 ; V_29 ++ ) {
if ( ! F_60 ( V_29 ) )
continue;
if ( F_66 ( V_5 | V_29 , V_85 ) )
return - V_62 ;
V_85 ++ ;
}
return 0 ;
}
static T_1 F_79 ( const struct V_3 * V_6 )
{
T_1 V_5 = V_87 | ( 15 << V_60 ) ;
if ( V_6 -> V_25 ) {
V_5 |= V_59 ;
V_5 |= ( V_6 -> V_38 << V_57 ) ;
V_5 |= ( V_6 -> V_39 << V_56 ) ;
} else {
V_5 |= V_48 ;
V_5 |= ( V_6 -> V_38 << V_57 ) ;
V_5 |= ( V_6 -> V_41 << V_58 ) ;
V_5 |= ( V_6 -> V_40 << V_56 ) ;
V_5 |= ( V_6 -> V_39 << V_55 ) ;
}
return V_5 ;
}
static bool F_80 ( const struct V_3 * V_6 , T_1 T_4 * * V_113 )
{
if ( ! * V_113 )
return true ;
if ( F_66 ( F_79 ( V_6 ) , * V_113 ) )
return false ;
( * V_113 ) ++ ;
return true ;
}
static int F_81 ( struct V_1 * V_2 , T_1 T_4 * V_113 )
{
const struct V_3 * V_114 , * V_115 , * V_116 , * V_117 ;
unsigned int V_118 = 0 ;
T_3 V_31 ;
V_114 = F_35 ( V_2 -> V_42 . V_33 , & V_31 ) ;
V_116 = V_114 + V_31 ;
V_115 = V_43 ;
V_117 = V_43 + F_41 ( V_43 ) ;
F_28 ( V_114 == V_116 || V_115 == V_117 ) ;
while ( V_114 || V_115 ) {
int V_119 = F_32 ( V_114 , V_115 ) ;
if ( V_119 <= 0 ) {
if ( V_114 -> V_6 ) {
if ( ! F_80 ( V_114 , & V_113 ) )
return - V_62 ;
V_118 ++ ;
}
} else {
if ( V_115 -> V_6 ) {
if ( ! F_80 ( V_115 , & V_113 ) )
return - V_62 ;
V_118 ++ ;
}
}
if ( V_119 <= 0 && ++ V_114 == V_116 )
V_114 = NULL ;
if ( V_119 >= 0 && ++ V_115 == V_117 )
V_115 = NULL ;
}
return V_118 ;
}
unsigned long F_82 ( struct V_1 * V_2 )
{
return F_41 ( V_65 )
+ F_77 ()
+ F_71 ()
+ F_81 ( V_2 , ( T_1 T_4 * ) NULL ) ;
}
int F_83 ( struct V_1 * V_2 , T_1 T_4 * V_85 )
{
unsigned int V_29 ;
int V_66 ;
for ( V_29 = 0 ; V_29 < F_41 ( V_65 ) ; V_29 ++ ) {
if ( F_66 ( F_79 ( & V_65 [ V_29 ] ) , V_85 ) )
return - V_62 ;
V_85 ++ ;
}
V_66 = F_81 ( V_2 , V_85 ) ;
if ( V_66 < 0 )
return V_66 ;
V_85 += V_66 ;
V_66 = F_72 ( V_85 ) ;
if ( V_66 < 0 )
return V_66 ;
V_85 += V_66 ;
return F_78 ( V_85 ) ;
}
void F_84 ( void )
{
unsigned int V_29 ;
F_28 ( F_31 ( V_43 , F_41 ( V_43 ) ) ) ;
F_28 ( F_31 ( V_65 , F_41 ( V_65 ) ) ) ;
for ( V_29 = 0 ; V_29 < F_41 ( V_65 ) ; V_29 ++ )
V_65 [ V_29 ] . V_45 ( NULL , & V_65 [ V_29 ] ) ;
asm volatile("mrc p15, 1, %0, c0, c0, 1" : "=r" (cache_levels));
for ( V_29 = 0 ; V_29 < 7 ; V_29 ++ )
if ( ( ( V_72 >> ( V_29 * 3 ) ) & 7 ) == 0 )
break;
V_72 &= ( 1 << ( V_29 * 3 ) ) - 1 ;
}
void F_85 ( struct V_1 * V_2 )
{
T_3 V_31 ;
const struct V_3 * V_27 ;
memset ( V_2 -> V_42 . V_93 . V_120 , 0x42 , sizeof( V_2 -> V_42 . V_93 . V_120 ) ) ;
F_49 ( V_2 , V_43 , F_41 ( V_43 ) ) ;
V_27 = F_35 ( V_2 -> V_42 . V_33 , & V_31 ) ;
F_49 ( V_2 , V_27 , V_31 ) ;
for ( V_31 = 1 ; V_31 < V_121 ; V_31 ++ )
if ( F_2 ( V_2 , V_31 ) == 0x42424242 )
F_86 ( L_3 , V_31 ) ;
}

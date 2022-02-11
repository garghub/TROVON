static inline void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
T_1 V_5 )
{
V_2 -> V_6 . V_7 [ V_4 -> V_8 ] = V_5 & 0xffffffff ;
V_2 -> V_6 . V_7 [ V_4 -> V_8 + 1 ] = V_5 >> 32 ;
}
static inline T_1 F_2 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
T_1 V_5 ;
V_5 = V_2 -> V_6 . V_7 [ V_4 -> V_8 + 1 ] ;
V_5 = V_5 << 32 ;
V_5 = V_5 | V_2 -> V_6 . V_7 [ V_4 -> V_8 ] ;
return V_5 ;
}
int F_3 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
F_4 ( V_2 ) ;
return 1 ;
}
int F_5 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
F_4 ( V_2 ) ;
return 1 ;
}
int F_6 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
F_4 ( V_2 ) ;
return 1 ;
}
int F_7 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
F_4 ( V_2 ) ;
return 1 ;
}
static void F_8 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
V_2 -> V_6 . V_7 [ V_11 ] = ( ( F_9 () & V_12 ) |
( ( V_2 -> V_13 >> 2 ) << V_14 ) |
( V_2 -> V_13 & 3 ) ) ;
}
static bool F_10 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
const struct V_3 * V_4 )
{
if ( V_16 -> V_17 )
return F_11 ( V_2 , V_16 ) ;
* F_12 ( V_2 , V_16 -> V_18 ) = V_2 -> V_6 . V_7 [ V_19 ] ;
return true ;
}
static bool F_13 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
const struct V_3 * V_4 )
{
if ( V_16 -> V_17 )
return F_14 ( V_2 , V_16 ) ;
return F_15 ( V_2 , V_16 ) ;
}
static bool F_16 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
const struct V_3 * V_4 )
{
if ( V_16 -> V_17 )
return F_11 ( V_2 , V_16 ) ;
* F_12 ( V_2 , V_16 -> V_18 ) = V_2 -> V_6 . V_7 [ V_20 ] ;
return true ;
}
static void F_17 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
T_2 V_21 , V_22 ;
asm volatile("mrc p15, 1, %0, c9, c0, 2\n" : "=r" (l2ctlr));
V_21 &= ~ ( 3 << 24 ) ;
V_22 = F_18 ( & V_2 -> V_23 -> V_24 ) - 1 ;
V_22 -= ( V_2 -> V_13 & ~ 3 ) ;
V_22 = F_19 ( V_22 , 3U ) ;
V_21 |= ( V_22 & 3 ) << 24 ;
V_2 -> V_6 . V_7 [ V_20 ] = V_21 ;
}
static void F_20 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
T_2 V_25 ;
asm volatile("mrc p15, 0, %0, c1, c0, 1\n" : "=r" (actlr));
if ( F_18 ( & V_2 -> V_23 -> V_24 ) > 1 )
V_25 |= 1U << 6 ;
else
V_25 &= ~ ( 1U << 6 ) ;
V_2 -> V_6 . V_7 [ V_19 ] = V_25 ;
}
static bool F_21 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
const struct V_3 * V_4 )
{
if ( V_16 -> V_17 )
return F_11 ( V_2 , V_16 ) ;
* F_12 ( V_2 , V_16 -> V_18 ) = 0 ;
return true ;
}
static bool F_22 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
const struct V_3 * V_4 )
{
unsigned long V_5 ;
int V_26 ;
if ( ! V_16 -> V_17 )
return F_23 ( V_2 , V_16 ) ;
V_26 = F_24 () ;
F_25 ( & V_2 -> V_6 . V_27 ) ;
F_26 ( V_26 , & V_2 -> V_6 . V_27 ) ;
if ( V_26 != V_2 -> V_6 . V_28 ) {
F_27 () ;
goto V_29;
}
V_5 = * F_12 ( V_2 , V_16 -> V_18 ) ;
switch ( V_16 -> V_30 ) {
case 6 :
case 14 :
asm volatile("mcr p15, 0, %0, c7, c14, 2" : : "r" (val));
break;
case 10 :
asm volatile("mcr p15, 0, %0, c7, c10, 2" : : "r" (val));
break;
}
V_29:
F_28 () ;
return true ;
}
static bool F_29 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
const struct V_3 * V_4 )
{
F_30 ( ! V_16 -> V_17 ) ;
V_2 -> V_6 . V_7 [ V_4 -> V_8 ] = * F_12 ( V_2 , V_16 -> V_18 ) ;
if ( V_16 -> V_31 )
V_2 -> V_6 . V_7 [ V_4 -> V_8 + 1 ] = * F_12 ( V_2 , V_16 -> V_32 ) ;
return true ;
}
bool F_31 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
const struct V_3 * V_4 )
{
F_29 ( V_2 , V_16 , V_4 ) ;
if ( F_32 ( V_2 ) ) {
V_2 -> V_6 . V_33 &= ~ V_34 ;
F_33 ( V_2 -> V_23 ) ;
}
return true ;
}
static bool F_34 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
const struct V_3 * V_4 )
{
if ( V_16 -> V_17 )
return F_11 ( V_2 , V_16 ) ;
else
return F_15 ( V_2 , V_16 ) ;
}
void F_35 ( struct V_35 * V_36 )
{
unsigned int V_37 ;
for ( V_37 = 1 ; V_37 < V_36 -> V_38 ; V_37 ++ )
F_30 ( F_36 ( & V_36 -> V_36 [ V_37 - 1 ] ,
& V_36 -> V_36 [ V_37 ] ) >= 0 ) ;
V_39 [ V_36 -> V_40 ] = V_36 ;
}
static const struct V_3 * F_37 ( unsigned V_40 , T_3 * V_38 )
{
struct V_35 * V_36 ;
V_36 = V_39 [ V_40 ] ;
* V_38 = V_36 -> V_38 ;
return V_36 -> V_36 ;
}
static const struct V_3 * F_38 ( const struct V_15 * V_41 ,
const struct V_3 V_36 [] ,
unsigned int V_38 )
{
unsigned int V_37 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
const struct V_3 * V_4 = & V_36 [ V_37 ] ;
if ( V_41 -> V_31 != V_4 -> V_42 )
continue;
if ( V_41 -> V_43 != V_4 -> V_43 )
continue;
if ( V_41 -> V_30 != V_4 -> V_30 )
continue;
if ( V_41 -> V_44 != V_4 -> V_44 )
continue;
if ( V_41 -> V_45 != V_4 -> V_45 )
continue;
return V_4 ;
}
return NULL ;
}
static int F_39 ( struct V_1 * V_2 ,
const struct V_15 * V_41 )
{
T_3 V_38 ;
const struct V_3 * V_36 , * V_4 ;
F_40 ( V_41 -> V_44 , V_41 -> V_18 , V_41 -> V_43 ,
V_41 -> V_30 , V_41 -> V_45 , V_41 -> V_17 ) ;
V_36 = F_37 ( V_2 -> V_6 . V_40 , & V_38 ) ;
V_4 = F_38 ( V_41 , V_36 , V_38 ) ;
if ( ! V_4 )
V_4 = F_38 ( V_41 , V_46 , F_41 ( V_46 ) ) ;
if ( F_42 ( V_4 ) ) {
F_30 ( ! V_4 -> V_47 ) ;
if ( F_42 ( V_4 -> V_47 ( V_2 , V_41 , V_4 ) ) ) {
F_43 ( V_2 , F_44 ( V_2 ) ) ;
return 1 ;
}
} else {
F_45 ( L_1 ,
* F_46 ( V_2 ) ) ;
F_47 ( V_41 ) ;
}
F_4 ( V_2 ) ;
return 1 ;
}
int F_48 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_15 V_41 ;
V_41 . V_43 = ( F_49 ( V_2 ) >> 1 ) & 0xf ;
V_41 . V_18 = ( F_49 ( V_2 ) >> 5 ) & 0xf ;
V_41 . V_17 = ( ( F_49 ( V_2 ) & 1 ) == 0 ) ;
V_41 . V_31 = true ;
V_41 . V_44 = ( F_49 ( V_2 ) >> 16 ) & 0xf ;
V_41 . V_45 = 0 ;
V_41 . V_32 = ( F_49 ( V_2 ) >> 10 ) & 0xf ;
V_41 . V_30 = 0 ;
return F_39 ( V_2 , & V_41 ) ;
}
static void F_50 ( struct V_1 * V_2 ,
const struct V_3 * V_36 , T_3 V_38 )
{
unsigned long V_37 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ )
if ( V_36 [ V_37 ] . V_48 )
V_36 [ V_37 ] . V_48 ( V_2 , & V_36 [ V_37 ] ) ;
}
int F_51 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_15 V_41 ;
V_41 . V_30 = ( F_49 ( V_2 ) >> 1 ) & 0xf ;
V_41 . V_18 = ( F_49 ( V_2 ) >> 5 ) & 0xf ;
V_41 . V_17 = ( ( F_49 ( V_2 ) & 1 ) == 0 ) ;
V_41 . V_31 = false ;
V_41 . V_43 = ( F_49 ( V_2 ) >> 10 ) & 0xf ;
V_41 . V_44 = ( F_49 ( V_2 ) >> 14 ) & 0x7 ;
V_41 . V_45 = ( F_49 ( V_2 ) >> 17 ) & 0x7 ;
V_41 . V_32 = 0 ;
return F_39 ( V_2 , & V_41 ) ;
}
static bool F_52 ( T_1 V_49 , struct V_15 * V_41 )
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
V_41 -> V_31 = false ;
V_41 -> V_43 = ( ( V_49 & V_54 )
>> V_58 ) ;
V_41 -> V_30 = ( ( V_49 & V_55 )
>> V_59 ) ;
V_41 -> V_44 = ( ( V_49 & V_56 )
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
V_41 -> V_31 = true ;
V_41 -> V_43 = ( ( V_49 & V_55 )
>> V_59 ) ;
V_41 -> V_44 = ( ( V_49 & V_56 )
>> V_60 ) ;
V_41 -> V_45 = 0 ;
V_41 -> V_30 = 0 ;
return true ;
default:
return false ;
}
}
static const struct V_3 * F_53 ( struct V_1 * V_2 ,
T_1 V_49 )
{
T_3 V_38 ;
const struct V_3 * V_36 , * V_4 ;
struct V_15 V_41 ;
if ( ( V_49 & V_53 ) >> V_63 != 15 )
return NULL ;
if ( ! F_52 ( V_49 , & V_41 ) )
return NULL ;
V_36 = F_37 ( V_2 -> V_6 . V_40 , & V_38 ) ;
V_4 = F_38 ( & V_41 , V_36 , V_38 ) ;
if ( ! V_4 )
V_4 = F_38 ( & V_41 , V_46 , F_41 ( V_46 ) ) ;
if ( V_4 && ! V_4 -> V_8 )
V_4 = NULL ;
return V_4 ;
}
static int F_54 ( void * V_5 , const void T_4 * V_64 , T_1 V_49 )
{
if ( F_55 ( V_5 , V_64 , F_56 ( V_49 ) ) != 0 )
return - V_65 ;
return 0 ;
}
static int F_57 ( void T_4 * V_64 , const void * V_5 , T_1 V_49 )
{
if ( F_58 ( V_64 , V_5 , F_56 ( V_49 ) ) != 0 )
return - V_65 ;
return 0 ;
}
static int F_59 ( T_1 V_49 , void T_4 * V_64 )
{
struct V_15 V_41 ;
const struct V_3 * V_4 ;
int V_66 ;
if ( ! F_52 ( V_49 , & V_41 ) )
return - V_67 ;
V_4 = F_38 ( & V_41 , V_68 , F_41 ( V_68 ) ) ;
if ( ! V_4 )
return - V_67 ;
V_66 = - V_67 ;
if ( F_56 ( V_49 ) == 4 ) {
T_2 V_5 = V_4 -> V_5 ;
V_66 = F_57 ( V_64 , & V_5 , V_49 ) ;
} else if ( F_56 ( V_49 ) == 8 ) {
V_66 = F_57 ( V_64 , & V_4 -> V_5 , V_49 ) ;
}
return V_66 ;
}
static int F_60 ( T_1 V_49 , void T_4 * V_64 )
{
struct V_15 V_41 ;
const struct V_3 * V_4 ;
int V_69 ;
T_1 V_5 ;
if ( ! F_52 ( V_49 , & V_41 ) )
return - V_67 ;
V_4 = F_38 ( & V_41 , V_68 , F_41 ( V_68 ) ) ;
if ( ! V_4 )
return - V_67 ;
V_69 = - V_67 ;
if ( F_56 ( V_49 ) == 4 ) {
T_2 V_70 ;
V_69 = F_54 ( & V_70 , V_64 , V_49 ) ;
if ( ! V_69 )
V_5 = V_70 ;
} else if ( F_56 ( V_49 ) == 8 ) {
V_69 = F_54 ( & V_5 , V_64 , V_49 ) ;
}
if ( V_69 )
return V_69 ;
if ( V_4 -> V_5 != V_5 )
return - V_71 ;
return 0 ;
}
static bool F_61 ( T_2 V_5 )
{
T_2 V_72 , V_73 ;
if ( V_5 >= V_74 )
return - V_67 ;
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
static T_2 F_62 ( T_2 V_76 )
{
T_2 V_77 ;
F_63 () ;
asm volatile("mcr p15, 2, %0, c0, c0, 0" : : "r" (csselr));
F_64 () ;
asm volatile("mrc p15, 1, %0, c0, c0, 0" : "=r" (ccsidr));
F_65 () ;
return V_77 ;
}
static int F_66 ( T_1 V_49 , void T_4 * V_64 )
{
T_2 V_5 ;
T_2 T_4 * V_78 = V_64 ;
if ( V_49 & ~ ( V_52 | V_50 | V_53
| ( ( 1 << V_63 ) - 1 ) ) )
return - V_67 ;
switch ( V_49 & V_79 ) {
case V_80 :
if ( F_56 ( V_49 ) != 4 )
return - V_67 ;
V_5 = ( V_49 & V_81 )
>> V_82 ;
if ( ! F_61 ( V_5 ) )
return - V_67 ;
return F_67 ( F_62 ( V_5 ) , V_78 ) ;
default:
return - V_67 ;
}
}
static int F_68 ( T_1 V_49 , void T_4 * V_64 )
{
T_2 V_5 , V_83 ;
T_2 T_4 * V_78 = V_64 ;
if ( V_49 & ~ ( V_52 | V_50 | V_53
| ( ( 1 << V_63 ) - 1 ) ) )
return - V_67 ;
switch ( V_49 & V_79 ) {
case V_80 :
if ( F_56 ( V_49 ) != 4 )
return - V_67 ;
V_5 = ( V_49 & V_81 )
>> V_82 ;
if ( ! F_61 ( V_5 ) )
return - V_67 ;
if ( F_69 ( V_83 , V_78 ) )
return - V_65 ;
if ( V_83 != F_62 ( V_5 ) )
return - V_71 ;
return 0 ;
default:
return - V_67 ;
}
}
static unsigned int F_70 ( void )
{
if ( ( ( F_71 ( V_84 ) & V_85 ) >> V_86 ) == 2 )
return 32 ;
else
return 16 ;
}
static unsigned int F_72 ( void )
{
return F_70 () + F_41 ( V_87 ) ;
}
static int F_73 ( T_1 T_4 * V_88 )
{
unsigned int V_37 ;
const T_1 V_89 = V_90 | V_51 | V_91 ;
const T_1 V_92 = V_90 | V_62 | V_91 ;
for ( V_37 = 0 ; V_37 < F_70 () ; V_37 ++ ) {
if ( F_67 ( ( V_92 | V_93 ) + V_37 ,
V_88 ) )
return - V_65 ;
V_88 ++ ;
}
for ( V_37 = 0 ; V_37 < F_41 ( V_87 ) ; V_37 ++ ) {
if ( F_67 ( V_89 | V_87 [ V_37 ] , V_88 ) )
return - V_65 ;
V_88 ++ ;
}
return F_72 () ;
}
static int F_74 ( const struct V_1 * V_2 , T_1 V_49 , void T_4 * V_64 )
{
T_2 V_94 = ( V_49 & V_95 ) ;
T_2 V_5 ;
if ( V_49 & ~ ( V_52 | V_50 | V_53
| ( ( 1 << V_63 ) - 1 ) ) )
return - V_67 ;
if ( V_94 < F_70 () ) {
if ( F_56 ( V_49 ) != 8 )
return - V_67 ;
return F_57 ( V_64 , & V_2 -> V_6 . V_96 . V_97 [ V_94 ] ,
V_49 ) ;
}
if ( F_56 ( V_49 ) != 4 )
return - V_67 ;
switch ( V_94 ) {
case V_98 :
return F_57 ( V_64 , & V_2 -> V_6 . V_96 . V_99 , V_49 ) ;
case V_100 :
return F_57 ( V_64 , & V_2 -> V_6 . V_96 . V_101 , V_49 ) ;
case V_102 :
return F_57 ( V_64 , & V_2 -> V_6 . V_96 . V_103 , V_49 ) ;
case V_104 :
return F_57 ( V_64 , & V_2 -> V_6 . V_96 . V_105 , V_49 ) ;
case V_106 :
V_5 = F_71 ( V_84 ) ;
return F_57 ( V_64 , & V_5 , V_49 ) ;
case V_107 :
V_5 = F_71 ( V_108 ) ;
return F_57 ( V_64 , & V_5 , V_49 ) ;
case V_109 :
V_5 = F_71 ( V_110 ) ;
return F_57 ( V_64 , & V_5 , V_49 ) ;
default:
return - V_67 ;
}
}
static int F_75 ( struct V_1 * V_2 , T_1 V_49 , const void T_4 * V_64 )
{
T_2 V_94 = ( V_49 & V_95 ) ;
T_2 V_5 ;
if ( V_49 & ~ ( V_52 | V_50 | V_53
| ( ( 1 << V_63 ) - 1 ) ) )
return - V_67 ;
if ( V_94 < F_70 () ) {
if ( F_56 ( V_49 ) != 8 )
return - V_67 ;
return F_54 ( & V_2 -> V_6 . V_96 . V_97 [ V_94 ] ,
V_64 , V_49 ) ;
}
if ( F_56 ( V_49 ) != 4 )
return - V_67 ;
switch ( V_94 ) {
case V_98 :
return F_54 ( & V_2 -> V_6 . V_96 . V_99 , V_64 , V_49 ) ;
case V_100 :
return F_54 ( & V_2 -> V_6 . V_96 . V_101 , V_64 , V_49 ) ;
case V_102 :
return F_54 ( & V_2 -> V_6 . V_96 . V_103 , V_64 , V_49 ) ;
case V_104 :
return F_54 ( & V_2 -> V_6 . V_96 . V_105 , V_64 , V_49 ) ;
case V_106 :
if ( F_54 ( & V_5 , V_64 , V_49 ) )
return - V_65 ;
if ( V_5 != F_71 ( V_84 ) )
return - V_71 ;
return 0 ;
case V_107 :
if ( F_54 ( & V_5 , V_64 , V_49 ) )
return - V_65 ;
if ( V_5 != F_71 ( V_108 ) )
return - V_71 ;
return 0 ;
case V_109 :
if ( F_54 ( & V_5 , V_64 , V_49 ) )
return - V_65 ;
if ( V_5 != F_71 ( V_110 ) )
return - V_71 ;
return 0 ;
default:
return - V_67 ;
}
}
static unsigned int F_72 ( void )
{
return 0 ;
}
static int F_73 ( T_1 T_4 * V_88 )
{
return 0 ;
}
static int F_74 ( const struct V_1 * V_2 , T_1 V_49 , void T_4 * V_64 )
{
return - V_67 ;
}
static int F_75 ( struct V_1 * V_2 , T_1 V_49 , const void T_4 * V_64 )
{
return - V_67 ;
}
int F_76 ( struct V_1 * V_2 , const struct V_111 * V_8 )
{
const struct V_3 * V_4 ;
void T_4 * V_64 = ( void T_4 * ) ( long ) V_8 -> V_112 ;
int V_66 ;
if ( ( V_8 -> V_49 & V_53 ) == V_113 )
return F_66 ( V_8 -> V_49 , V_64 ) ;
if ( ( V_8 -> V_49 & V_53 ) == V_91 )
return F_74 ( V_2 , V_8 -> V_49 , V_64 ) ;
V_4 = F_53 ( V_2 , V_8 -> V_49 ) ;
if ( ! V_4 )
return F_59 ( V_8 -> V_49 , V_64 ) ;
V_66 = - V_67 ;
if ( F_56 ( V_8 -> V_49 ) == 8 ) {
T_1 V_5 ;
V_5 = F_2 ( V_2 , V_4 ) ;
V_66 = F_57 ( V_64 , & V_5 , V_8 -> V_49 ) ;
} else if ( F_56 ( V_8 -> V_49 ) == 4 ) {
V_66 = F_57 ( V_64 , & V_2 -> V_6 . V_7 [ V_4 -> V_8 ] , V_8 -> V_49 ) ;
}
return V_66 ;
}
int F_77 ( struct V_1 * V_2 , const struct V_111 * V_8 )
{
const struct V_3 * V_4 ;
void T_4 * V_64 = ( void T_4 * ) ( long ) V_8 -> V_112 ;
int V_66 ;
if ( ( V_8 -> V_49 & V_53 ) == V_113 )
return F_68 ( V_8 -> V_49 , V_64 ) ;
if ( ( V_8 -> V_49 & V_53 ) == V_91 )
return F_75 ( V_2 , V_8 -> V_49 , V_64 ) ;
V_4 = F_53 ( V_2 , V_8 -> V_49 ) ;
if ( ! V_4 )
return F_60 ( V_8 -> V_49 , V_64 ) ;
V_66 = - V_67 ;
if ( F_56 ( V_8 -> V_49 ) == 8 ) {
T_1 V_5 ;
V_66 = F_54 ( & V_5 , V_64 , V_8 -> V_49 ) ;
if ( ! V_66 )
F_1 ( V_2 , V_4 , V_5 ) ;
} else if ( F_56 ( V_8 -> V_49 ) == 4 ) {
V_66 = F_54 ( & V_2 -> V_6 . V_7 [ V_4 -> V_8 ] , V_64 , V_8 -> V_49 ) ;
}
return V_66 ;
}
static unsigned int F_78 ( void )
{
unsigned int V_37 , V_114 = 0 ;
for ( V_37 = 0 ; V_37 < V_74 ; V_37 ++ )
if ( F_61 ( V_37 ) )
V_114 ++ ;
return V_114 ;
}
static int F_79 ( T_1 T_4 * V_88 )
{
T_1 V_5 = V_90 | V_51 | V_113 ;
unsigned int V_37 ;
V_5 |= V_80 ;
for ( V_37 = 0 ; V_37 < V_74 ; V_37 ++ ) {
if ( ! F_61 ( V_37 ) )
continue;
if ( F_67 ( V_5 | V_37 , V_88 ) )
return - V_65 ;
V_88 ++ ;
}
return 0 ;
}
static T_1 F_80 ( const struct V_3 * V_8 )
{
T_1 V_5 = V_90 | ( 15 << V_63 ) ;
if ( V_8 -> V_42 ) {
V_5 |= V_62 ;
V_5 |= ( V_8 -> V_44 << V_60 ) ;
V_5 |= ( V_8 -> V_43 << V_59 ) ;
} else {
V_5 |= V_51 ;
V_5 |= ( V_8 -> V_44 << V_60 ) ;
V_5 |= ( V_8 -> V_45 << V_61 ) ;
V_5 |= ( V_8 -> V_30 << V_59 ) ;
V_5 |= ( V_8 -> V_43 << V_58 ) ;
}
return V_5 ;
}
static bool F_81 ( const struct V_3 * V_8 , T_1 T_4 * * V_115 )
{
if ( ! * V_115 )
return true ;
if ( F_67 ( F_80 ( V_8 ) , * V_115 ) )
return false ;
( * V_115 ) ++ ;
return true ;
}
static int F_82 ( struct V_1 * V_2 , T_1 T_4 * V_115 )
{
const struct V_3 * V_116 , * V_117 , * V_118 , * V_119 ;
unsigned int V_120 = 0 ;
T_3 V_38 ;
V_116 = F_37 ( V_2 -> V_6 . V_40 , & V_38 ) ;
V_118 = V_116 + V_38 ;
V_117 = V_46 ;
V_119 = V_46 + F_41 ( V_46 ) ;
F_30 ( V_116 == V_118 || V_117 == V_119 ) ;
while ( V_116 || V_117 ) {
int V_121 = F_36 ( V_116 , V_117 ) ;
if ( V_121 <= 0 ) {
if ( V_116 -> V_8 ) {
if ( ! F_81 ( V_116 , & V_115 ) )
return - V_65 ;
V_120 ++ ;
}
} else {
if ( V_117 -> V_8 ) {
if ( ! F_81 ( V_117 , & V_115 ) )
return - V_65 ;
V_120 ++ ;
}
}
if ( V_121 <= 0 && ++ V_116 == V_118 )
V_116 = NULL ;
if ( V_121 >= 0 && ++ V_117 == V_119 )
V_117 = NULL ;
}
return V_120 ;
}
unsigned long F_83 ( struct V_1 * V_2 )
{
return F_41 ( V_68 )
+ F_78 ()
+ F_72 ()
+ F_82 ( V_2 , ( T_1 T_4 * ) NULL ) ;
}
int F_84 ( struct V_1 * V_2 , T_1 T_4 * V_88 )
{
unsigned int V_37 ;
int V_69 ;
for ( V_37 = 0 ; V_37 < F_41 ( V_68 ) ; V_37 ++ ) {
if ( F_67 ( F_80 ( & V_68 [ V_37 ] ) , V_88 ) )
return - V_65 ;
V_88 ++ ;
}
V_69 = F_82 ( V_2 , V_88 ) ;
if ( V_69 < 0 )
return V_69 ;
V_88 += V_69 ;
V_69 = F_73 ( V_88 ) ;
if ( V_69 < 0 )
return V_69 ;
V_88 += V_69 ;
return F_79 ( V_88 ) ;
}
void F_85 ( void )
{
unsigned int V_37 ;
for ( V_37 = 1 ; V_37 < F_41 ( V_46 ) ; V_37 ++ )
F_30 ( F_36 ( & V_46 [ V_37 - 1 ] , & V_46 [ V_37 ] ) >= 0 ) ;
for ( V_37 = 0 ; V_37 < F_41 ( V_68 ) ; V_37 ++ )
V_68 [ V_37 ] . V_48 ( NULL , & V_68 [ V_37 ] ) ;
asm volatile("mrc p15, 1, %0, c0, c0, 1" : "=r" (cache_levels));
for ( V_37 = 0 ; V_37 < 7 ; V_37 ++ )
if ( ( ( V_75 >> ( V_37 * 3 ) ) & 7 ) == 0 )
break;
V_75 &= ( 1 << ( V_37 * 3 ) ) - 1 ;
}
void F_86 ( struct V_1 * V_2 )
{
T_3 V_38 ;
const struct V_3 * V_36 ;
memset ( V_2 -> V_6 . V_7 , 0x42 , sizeof( V_2 -> V_6 . V_7 ) ) ;
F_50 ( V_2 , V_46 , F_41 ( V_46 ) ) ;
V_36 = F_37 ( V_2 -> V_6 . V_40 , & V_38 ) ;
F_50 ( V_2 , V_36 , V_38 ) ;
for ( V_38 = 1 ; V_38 < V_122 ; V_38 ++ )
if ( V_2 -> V_6 . V_7 [ V_38 ] == 0x42424242 )
F_87 ( L_2 , V_38 ) ;
}

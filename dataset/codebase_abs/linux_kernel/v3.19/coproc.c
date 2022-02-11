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
if ( ! V_16 -> V_17 )
return F_23 ( V_2 , V_16 ) ;
F_24 ( V_2 ) ;
return true ;
}
bool F_25 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
const struct V_3 * V_4 )
{
bool V_26 = F_26 ( V_2 ) ;
F_27 ( ! V_16 -> V_17 ) ;
V_2 -> V_6 . V_7 [ V_4 -> V_8 ] = * F_12 ( V_2 , V_16 -> V_18 ) ;
if ( V_16 -> V_27 )
V_2 -> V_6 . V_7 [ V_4 -> V_8 + 1 ] = * F_12 ( V_2 , V_16 -> V_28 ) ;
F_28 ( V_2 , V_26 ) ;
return true ;
}
static bool F_29 ( struct V_1 * V_2 ,
const struct V_15 * V_16 ,
const struct V_3 * V_4 )
{
if ( V_16 -> V_17 )
return F_11 ( V_2 , V_16 ) ;
else
return F_15 ( V_2 , V_16 ) ;
}
void F_30 ( struct V_29 * V_30 )
{
unsigned int V_31 ;
for ( V_31 = 1 ; V_31 < V_30 -> V_32 ; V_31 ++ )
F_27 ( F_31 ( & V_30 -> V_30 [ V_31 - 1 ] ,
& V_30 -> V_30 [ V_31 ] ) >= 0 ) ;
V_33 [ V_30 -> V_34 ] = V_30 ;
}
static const struct V_3 * F_32 ( unsigned V_34 , T_3 * V_32 )
{
struct V_29 * V_30 ;
V_30 = V_33 [ V_34 ] ;
* V_32 = V_30 -> V_32 ;
return V_30 -> V_30 ;
}
static const struct V_3 * F_33 ( const struct V_15 * V_35 ,
const struct V_3 V_30 [] ,
unsigned int V_32 )
{
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
const struct V_3 * V_4 = & V_30 [ V_31 ] ;
if ( V_35 -> V_27 != V_4 -> V_36 )
continue;
if ( V_35 -> V_37 != V_4 -> V_37 )
continue;
if ( V_35 -> V_38 != V_4 -> V_38 )
continue;
if ( V_35 -> V_39 != V_4 -> V_39 )
continue;
if ( V_35 -> V_40 != V_4 -> V_40 )
continue;
return V_4 ;
}
return NULL ;
}
static int F_34 ( struct V_1 * V_2 ,
const struct V_15 * V_35 )
{
T_3 V_32 ;
const struct V_3 * V_30 , * V_4 ;
F_35 ( V_35 -> V_39 , V_35 -> V_18 , V_35 -> V_37 ,
V_35 -> V_38 , V_35 -> V_40 , V_35 -> V_17 ) ;
V_30 = F_32 ( V_2 -> V_6 . V_34 , & V_32 ) ;
V_4 = F_33 ( V_35 , V_30 , V_32 ) ;
if ( ! V_4 )
V_4 = F_33 ( V_35 , V_41 , F_36 ( V_41 ) ) ;
if ( F_37 ( V_4 ) ) {
F_27 ( ! V_4 -> V_42 ) ;
if ( F_37 ( V_4 -> V_42 ( V_2 , V_35 , V_4 ) ) ) {
F_38 ( V_2 , F_39 ( V_2 ) ) ;
return 1 ;
}
} else {
F_40 ( L_1 ,
* F_41 ( V_2 ) ) ;
F_42 ( V_35 ) ;
}
F_4 ( V_2 ) ;
return 1 ;
}
int F_43 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_15 V_35 ;
V_35 . V_37 = ( F_44 ( V_2 ) >> 1 ) & 0xf ;
V_35 . V_18 = ( F_44 ( V_2 ) >> 5 ) & 0xf ;
V_35 . V_17 = ( ( F_44 ( V_2 ) & 1 ) == 0 ) ;
V_35 . V_27 = true ;
V_35 . V_39 = ( F_44 ( V_2 ) >> 16 ) & 0xf ;
V_35 . V_40 = 0 ;
V_35 . V_28 = ( F_44 ( V_2 ) >> 10 ) & 0xf ;
V_35 . V_38 = 0 ;
return F_34 ( V_2 , & V_35 ) ;
}
static void F_45 ( struct V_1 * V_2 ,
const struct V_3 * V_30 , T_3 V_32 )
{
unsigned long V_31 ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ )
if ( V_30 [ V_31 ] . V_43 )
V_30 [ V_31 ] . V_43 ( V_2 , & V_30 [ V_31 ] ) ;
}
int F_46 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_15 V_35 ;
V_35 . V_38 = ( F_44 ( V_2 ) >> 1 ) & 0xf ;
V_35 . V_18 = ( F_44 ( V_2 ) >> 5 ) & 0xf ;
V_35 . V_17 = ( ( F_44 ( V_2 ) & 1 ) == 0 ) ;
V_35 . V_27 = false ;
V_35 . V_37 = ( F_44 ( V_2 ) >> 10 ) & 0xf ;
V_35 . V_39 = ( F_44 ( V_2 ) >> 14 ) & 0x7 ;
V_35 . V_40 = ( F_44 ( V_2 ) >> 17 ) & 0x7 ;
V_35 . V_28 = 0 ;
return F_34 ( V_2 , & V_35 ) ;
}
static bool F_47 ( T_1 V_44 , struct V_15 * V_35 )
{
switch ( V_44 & V_45 ) {
case V_46 :
if ( V_44 & ~ ( V_47 | V_45
| V_48
| V_49
| V_50
| V_51
| V_52 ) )
return false ;
V_35 -> V_27 = false ;
V_35 -> V_37 = ( ( V_44 & V_49 )
>> V_53 ) ;
V_35 -> V_38 = ( ( V_44 & V_50 )
>> V_54 ) ;
V_35 -> V_39 = ( ( V_44 & V_51 )
>> V_55 ) ;
V_35 -> V_40 = ( ( V_44 & V_52 )
>> V_56 ) ;
return true ;
case V_57 :
if ( V_44 & ~ ( V_47 | V_45
| V_48
| V_50
| V_51 ) )
return false ;
V_35 -> V_27 = true ;
V_35 -> V_37 = ( ( V_44 & V_50 )
>> V_54 ) ;
V_35 -> V_39 = ( ( V_44 & V_51 )
>> V_55 ) ;
V_35 -> V_40 = 0 ;
V_35 -> V_38 = 0 ;
return true ;
default:
return false ;
}
}
static const struct V_3 * F_48 ( struct V_1 * V_2 ,
T_1 V_44 )
{
T_3 V_32 ;
const struct V_3 * V_30 , * V_4 ;
struct V_15 V_35 ;
if ( ( V_44 & V_48 ) >> V_58 != 15 )
return NULL ;
if ( ! F_47 ( V_44 , & V_35 ) )
return NULL ;
V_30 = F_32 ( V_2 -> V_6 . V_34 , & V_32 ) ;
V_4 = F_33 ( & V_35 , V_30 , V_32 ) ;
if ( ! V_4 )
V_4 = F_33 ( & V_35 , V_41 , F_36 ( V_41 ) ) ;
if ( V_4 && ! V_4 -> V_8 )
V_4 = NULL ;
return V_4 ;
}
static int F_49 ( void * V_5 , const void T_4 * V_59 , T_1 V_44 )
{
if ( F_50 ( V_5 , V_59 , F_51 ( V_44 ) ) != 0 )
return - V_60 ;
return 0 ;
}
static int F_52 ( void T_4 * V_59 , const void * V_5 , T_1 V_44 )
{
if ( F_53 ( V_59 , V_5 , F_51 ( V_44 ) ) != 0 )
return - V_60 ;
return 0 ;
}
static int F_54 ( T_1 V_44 , void T_4 * V_59 )
{
struct V_15 V_35 ;
const struct V_3 * V_4 ;
int V_61 ;
if ( ! F_47 ( V_44 , & V_35 ) )
return - V_62 ;
V_4 = F_33 ( & V_35 , V_63 , F_36 ( V_63 ) ) ;
if ( ! V_4 )
return - V_62 ;
V_61 = - V_62 ;
if ( F_51 ( V_44 ) == 4 ) {
T_2 V_5 = V_4 -> V_5 ;
V_61 = F_52 ( V_59 , & V_5 , V_44 ) ;
} else if ( F_51 ( V_44 ) == 8 ) {
V_61 = F_52 ( V_59 , & V_4 -> V_5 , V_44 ) ;
}
return V_61 ;
}
static int F_55 ( T_1 V_44 , void T_4 * V_59 )
{
struct V_15 V_35 ;
const struct V_3 * V_4 ;
int V_64 ;
T_1 V_5 ;
if ( ! F_47 ( V_44 , & V_35 ) )
return - V_62 ;
V_4 = F_33 ( & V_35 , V_63 , F_36 ( V_63 ) ) ;
if ( ! V_4 )
return - V_62 ;
V_64 = - V_62 ;
if ( F_51 ( V_44 ) == 4 ) {
T_2 V_65 ;
V_64 = F_49 ( & V_65 , V_59 , V_44 ) ;
if ( ! V_64 )
V_5 = V_65 ;
} else if ( F_51 ( V_44 ) == 8 ) {
V_64 = F_49 ( & V_5 , V_59 , V_44 ) ;
}
if ( V_64 )
return V_64 ;
if ( V_4 -> V_5 != V_5 )
return - V_66 ;
return 0 ;
}
static bool F_56 ( T_2 V_5 )
{
T_2 V_67 , V_68 ;
if ( V_5 >= V_69 )
return false ;
V_67 = ( V_5 >> 1 ) ;
V_68 = ( V_70 >> ( V_67 * 3 ) ) & 7 ;
switch ( V_68 ) {
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
static T_2 F_57 ( T_2 V_71 )
{
T_2 V_72 ;
F_58 () ;
asm volatile("mcr p15, 2, %0, c0, c0, 0" : : "r" (csselr));
F_59 () ;
asm volatile("mrc p15, 1, %0, c0, c0, 0" : "=r" (ccsidr));
F_60 () ;
return V_72 ;
}
static int F_61 ( T_1 V_44 , void T_4 * V_59 )
{
T_2 V_5 ;
T_2 T_4 * V_73 = V_59 ;
if ( V_44 & ~ ( V_47 | V_45 | V_48
| ( ( 1 << V_58 ) - 1 ) ) )
return - V_62 ;
switch ( V_44 & V_74 ) {
case V_75 :
if ( F_51 ( V_44 ) != 4 )
return - V_62 ;
V_5 = ( V_44 & V_76 )
>> V_77 ;
if ( ! F_56 ( V_5 ) )
return - V_62 ;
return F_62 ( F_57 ( V_5 ) , V_73 ) ;
default:
return - V_62 ;
}
}
static int F_63 ( T_1 V_44 , void T_4 * V_59 )
{
T_2 V_5 , V_78 ;
T_2 T_4 * V_73 = V_59 ;
if ( V_44 & ~ ( V_47 | V_45 | V_48
| ( ( 1 << V_58 ) - 1 ) ) )
return - V_62 ;
switch ( V_44 & V_74 ) {
case V_75 :
if ( F_51 ( V_44 ) != 4 )
return - V_62 ;
V_5 = ( V_44 & V_76 )
>> V_77 ;
if ( ! F_56 ( V_5 ) )
return - V_62 ;
if ( F_64 ( V_78 , V_73 ) )
return - V_60 ;
if ( V_78 != F_57 ( V_5 ) )
return - V_66 ;
return 0 ;
default:
return - V_62 ;
}
}
static unsigned int F_65 ( void )
{
if ( ( ( F_66 ( V_79 ) & V_80 ) >> V_81 ) == 2 )
return 32 ;
else
return 16 ;
}
static unsigned int F_67 ( void )
{
return F_65 () + F_36 ( V_82 ) ;
}
static int F_68 ( T_1 T_4 * V_83 )
{
unsigned int V_31 ;
const T_1 V_84 = V_85 | V_46 | V_86 ;
const T_1 V_87 = V_85 | V_57 | V_86 ;
for ( V_31 = 0 ; V_31 < F_65 () ; V_31 ++ ) {
if ( F_62 ( ( V_87 | V_88 ) + V_31 ,
V_83 ) )
return - V_60 ;
V_83 ++ ;
}
for ( V_31 = 0 ; V_31 < F_36 ( V_82 ) ; V_31 ++ ) {
if ( F_62 ( V_84 | V_82 [ V_31 ] , V_83 ) )
return - V_60 ;
V_83 ++ ;
}
return F_67 () ;
}
static int F_69 ( const struct V_1 * V_2 , T_1 V_44 , void T_4 * V_59 )
{
T_2 V_89 = ( V_44 & V_90 ) ;
T_2 V_5 ;
if ( V_44 & ~ ( V_47 | V_45 | V_48
| ( ( 1 << V_58 ) - 1 ) ) )
return - V_62 ;
if ( V_89 < F_65 () ) {
if ( F_51 ( V_44 ) != 8 )
return - V_62 ;
return F_52 ( V_59 , & V_2 -> V_6 . V_91 . V_92 [ V_89 ] ,
V_44 ) ;
}
if ( F_51 ( V_44 ) != 4 )
return - V_62 ;
switch ( V_89 ) {
case V_93 :
return F_52 ( V_59 , & V_2 -> V_6 . V_91 . V_94 , V_44 ) ;
case V_95 :
return F_52 ( V_59 , & V_2 -> V_6 . V_91 . V_96 , V_44 ) ;
case V_97 :
return F_52 ( V_59 , & V_2 -> V_6 . V_91 . V_98 , V_44 ) ;
case V_99 :
return F_52 ( V_59 , & V_2 -> V_6 . V_91 . V_100 , V_44 ) ;
case V_101 :
V_5 = F_66 ( V_79 ) ;
return F_52 ( V_59 , & V_5 , V_44 ) ;
case V_102 :
V_5 = F_66 ( V_103 ) ;
return F_52 ( V_59 , & V_5 , V_44 ) ;
case V_104 :
V_5 = F_66 ( V_105 ) ;
return F_52 ( V_59 , & V_5 , V_44 ) ;
default:
return - V_62 ;
}
}
static int F_70 ( struct V_1 * V_2 , T_1 V_44 , const void T_4 * V_59 )
{
T_2 V_89 = ( V_44 & V_90 ) ;
T_2 V_5 ;
if ( V_44 & ~ ( V_47 | V_45 | V_48
| ( ( 1 << V_58 ) - 1 ) ) )
return - V_62 ;
if ( V_89 < F_65 () ) {
if ( F_51 ( V_44 ) != 8 )
return - V_62 ;
return F_49 ( & V_2 -> V_6 . V_91 . V_92 [ V_89 ] ,
V_59 , V_44 ) ;
}
if ( F_51 ( V_44 ) != 4 )
return - V_62 ;
switch ( V_89 ) {
case V_93 :
return F_49 ( & V_2 -> V_6 . V_91 . V_94 , V_59 , V_44 ) ;
case V_95 :
return F_49 ( & V_2 -> V_6 . V_91 . V_96 , V_59 , V_44 ) ;
case V_97 :
return F_49 ( & V_2 -> V_6 . V_91 . V_98 , V_59 , V_44 ) ;
case V_99 :
return F_49 ( & V_2 -> V_6 . V_91 . V_100 , V_59 , V_44 ) ;
case V_101 :
if ( F_49 ( & V_5 , V_59 , V_44 ) )
return - V_60 ;
if ( V_5 != F_66 ( V_79 ) )
return - V_66 ;
return 0 ;
case V_102 :
if ( F_49 ( & V_5 , V_59 , V_44 ) )
return - V_60 ;
if ( V_5 != F_66 ( V_103 ) )
return - V_66 ;
return 0 ;
case V_104 :
if ( F_49 ( & V_5 , V_59 , V_44 ) )
return - V_60 ;
if ( V_5 != F_66 ( V_105 ) )
return - V_66 ;
return 0 ;
default:
return - V_62 ;
}
}
static unsigned int F_67 ( void )
{
return 0 ;
}
static int F_68 ( T_1 T_4 * V_83 )
{
return 0 ;
}
static int F_69 ( const struct V_1 * V_2 , T_1 V_44 , void T_4 * V_59 )
{
return - V_62 ;
}
static int F_70 ( struct V_1 * V_2 , T_1 V_44 , const void T_4 * V_59 )
{
return - V_62 ;
}
int F_71 ( struct V_1 * V_2 , const struct V_106 * V_8 )
{
const struct V_3 * V_4 ;
void T_4 * V_59 = ( void T_4 * ) ( long ) V_8 -> V_107 ;
int V_61 ;
if ( ( V_8 -> V_44 & V_48 ) == V_108 )
return F_61 ( V_8 -> V_44 , V_59 ) ;
if ( ( V_8 -> V_44 & V_48 ) == V_86 )
return F_69 ( V_2 , V_8 -> V_44 , V_59 ) ;
V_4 = F_48 ( V_2 , V_8 -> V_44 ) ;
if ( ! V_4 )
return F_54 ( V_8 -> V_44 , V_59 ) ;
V_61 = - V_62 ;
if ( F_51 ( V_8 -> V_44 ) == 8 ) {
T_1 V_5 ;
V_5 = F_2 ( V_2 , V_4 ) ;
V_61 = F_52 ( V_59 , & V_5 , V_8 -> V_44 ) ;
} else if ( F_51 ( V_8 -> V_44 ) == 4 ) {
V_61 = F_52 ( V_59 , & V_2 -> V_6 . V_7 [ V_4 -> V_8 ] , V_8 -> V_44 ) ;
}
return V_61 ;
}
int F_72 ( struct V_1 * V_2 , const struct V_106 * V_8 )
{
const struct V_3 * V_4 ;
void T_4 * V_59 = ( void T_4 * ) ( long ) V_8 -> V_107 ;
int V_61 ;
if ( ( V_8 -> V_44 & V_48 ) == V_108 )
return F_63 ( V_8 -> V_44 , V_59 ) ;
if ( ( V_8 -> V_44 & V_48 ) == V_86 )
return F_70 ( V_2 , V_8 -> V_44 , V_59 ) ;
V_4 = F_48 ( V_2 , V_8 -> V_44 ) ;
if ( ! V_4 )
return F_55 ( V_8 -> V_44 , V_59 ) ;
V_61 = - V_62 ;
if ( F_51 ( V_8 -> V_44 ) == 8 ) {
T_1 V_5 ;
V_61 = F_49 ( & V_5 , V_59 , V_8 -> V_44 ) ;
if ( ! V_61 )
F_1 ( V_2 , V_4 , V_5 ) ;
} else if ( F_51 ( V_8 -> V_44 ) == 4 ) {
V_61 = F_49 ( & V_2 -> V_6 . V_7 [ V_4 -> V_8 ] , V_59 , V_8 -> V_44 ) ;
}
return V_61 ;
}
static unsigned int F_73 ( void )
{
unsigned int V_31 , V_109 = 0 ;
for ( V_31 = 0 ; V_31 < V_69 ; V_31 ++ )
if ( F_56 ( V_31 ) )
V_109 ++ ;
return V_109 ;
}
static int F_74 ( T_1 T_4 * V_83 )
{
T_1 V_5 = V_85 | V_46 | V_108 ;
unsigned int V_31 ;
V_5 |= V_75 ;
for ( V_31 = 0 ; V_31 < V_69 ; V_31 ++ ) {
if ( ! F_56 ( V_31 ) )
continue;
if ( F_62 ( V_5 | V_31 , V_83 ) )
return - V_60 ;
V_83 ++ ;
}
return 0 ;
}
static T_1 F_75 ( const struct V_3 * V_8 )
{
T_1 V_5 = V_85 | ( 15 << V_58 ) ;
if ( V_8 -> V_36 ) {
V_5 |= V_57 ;
V_5 |= ( V_8 -> V_39 << V_55 ) ;
V_5 |= ( V_8 -> V_37 << V_54 ) ;
} else {
V_5 |= V_46 ;
V_5 |= ( V_8 -> V_39 << V_55 ) ;
V_5 |= ( V_8 -> V_40 << V_56 ) ;
V_5 |= ( V_8 -> V_38 << V_54 ) ;
V_5 |= ( V_8 -> V_37 << V_53 ) ;
}
return V_5 ;
}
static bool F_76 ( const struct V_3 * V_8 , T_1 T_4 * * V_110 )
{
if ( ! * V_110 )
return true ;
if ( F_62 ( F_75 ( V_8 ) , * V_110 ) )
return false ;
( * V_110 ) ++ ;
return true ;
}
static int F_77 ( struct V_1 * V_2 , T_1 T_4 * V_110 )
{
const struct V_3 * V_111 , * V_112 , * V_113 , * V_114 ;
unsigned int V_115 = 0 ;
T_3 V_32 ;
V_111 = F_32 ( V_2 -> V_6 . V_34 , & V_32 ) ;
V_113 = V_111 + V_32 ;
V_112 = V_41 ;
V_114 = V_41 + F_36 ( V_41 ) ;
F_27 ( V_111 == V_113 || V_112 == V_114 ) ;
while ( V_111 || V_112 ) {
int V_116 = F_31 ( V_111 , V_112 ) ;
if ( V_116 <= 0 ) {
if ( V_111 -> V_8 ) {
if ( ! F_76 ( V_111 , & V_110 ) )
return - V_60 ;
V_115 ++ ;
}
} else {
if ( V_112 -> V_8 ) {
if ( ! F_76 ( V_112 , & V_110 ) )
return - V_60 ;
V_115 ++ ;
}
}
if ( V_116 <= 0 && ++ V_111 == V_113 )
V_111 = NULL ;
if ( V_116 >= 0 && ++ V_112 == V_114 )
V_112 = NULL ;
}
return V_115 ;
}
unsigned long F_78 ( struct V_1 * V_2 )
{
return F_36 ( V_63 )
+ F_73 ()
+ F_67 ()
+ F_77 ( V_2 , ( T_1 T_4 * ) NULL ) ;
}
int F_79 ( struct V_1 * V_2 , T_1 T_4 * V_83 )
{
unsigned int V_31 ;
int V_64 ;
for ( V_31 = 0 ; V_31 < F_36 ( V_63 ) ; V_31 ++ ) {
if ( F_62 ( F_75 ( & V_63 [ V_31 ] ) , V_83 ) )
return - V_60 ;
V_83 ++ ;
}
V_64 = F_77 ( V_2 , V_83 ) ;
if ( V_64 < 0 )
return V_64 ;
V_83 += V_64 ;
V_64 = F_68 ( V_83 ) ;
if ( V_64 < 0 )
return V_64 ;
V_83 += V_64 ;
return F_74 ( V_83 ) ;
}
void F_80 ( void )
{
unsigned int V_31 ;
for ( V_31 = 1 ; V_31 < F_36 ( V_41 ) ; V_31 ++ )
F_27 ( F_31 ( & V_41 [ V_31 - 1 ] , & V_41 [ V_31 ] ) >= 0 ) ;
for ( V_31 = 0 ; V_31 < F_36 ( V_63 ) ; V_31 ++ )
V_63 [ V_31 ] . V_43 ( NULL , & V_63 [ V_31 ] ) ;
asm volatile("mrc p15, 1, %0, c0, c0, 1" : "=r" (cache_levels));
for ( V_31 = 0 ; V_31 < 7 ; V_31 ++ )
if ( ( ( V_70 >> ( V_31 * 3 ) ) & 7 ) == 0 )
break;
V_70 &= ( 1 << ( V_31 * 3 ) ) - 1 ;
}
void F_81 ( struct V_1 * V_2 )
{
T_3 V_32 ;
const struct V_3 * V_30 ;
memset ( V_2 -> V_6 . V_7 , 0x42 , sizeof( V_2 -> V_6 . V_7 ) ) ;
F_45 ( V_2 , V_41 , F_36 ( V_41 ) ) ;
V_30 = F_32 ( V_2 -> V_6 . V_34 , & V_32 ) ;
F_45 ( V_2 , V_30 , V_32 ) ;
for ( V_32 = 1 ; V_32 < V_117 ; V_32 ++ )
if ( V_2 -> V_6 . V_7 [ V_32 ] == 0x42424242 )
F_82 ( L_2 , V_32 ) ;
}

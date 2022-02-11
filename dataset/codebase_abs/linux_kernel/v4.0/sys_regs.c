static T_1 F_1 ( T_1 V_1 )
{
T_1 V_2 ;
F_2 () ;
asm volatile("msr csselr_el1, %x0" : : "r" (csselr));
F_3 () ;
asm volatile("mrs %0, ccsidr_el1" : "=r" (ccsidr));
F_4 () ;
return V_2 ;
}
static bool F_5 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( ! V_6 -> V_9 )
return F_6 ( V_4 , V_6 ) ;
F_7 ( V_4 ) ;
return true ;
}
static bool F_8 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
unsigned long V_10 ;
bool V_11 = F_9 ( V_4 ) ;
F_10 ( ! V_6 -> V_9 ) ;
V_10 = * F_11 ( V_4 , V_6 -> V_12 ) ;
if ( ! V_6 -> V_13 ) {
F_12 ( V_4 , V_8 -> V_14 ) = V_10 ;
} else {
if ( ! V_6 -> V_15 )
F_13 ( V_4 , V_8 -> V_14 ) = V_10 >> 32 ;
F_14 ( V_4 , V_8 -> V_14 ) = V_10 & 0xffffffffUL ;
}
F_15 ( V_4 , V_11 ) ;
return true ;
}
static bool F_16 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
T_2 V_10 ;
if ( ! V_6 -> V_9 )
return F_6 ( V_4 , V_6 ) ;
V_10 = * F_11 ( V_4 , V_6 -> V_12 ) ;
F_17 ( V_4 , V_10 ) ;
return true ;
}
static bool F_18 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 )
return F_19 ( V_4 , V_6 ) ;
else
return F_20 ( V_4 , V_6 ) ;
}
static bool F_21 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
return F_19 ( V_4 , V_6 ) ;
} else {
* F_11 ( V_4 , V_6 -> V_12 ) = ( 1 << 3 ) ;
return true ;
}
}
static bool F_22 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
return F_19 ( V_4 , V_6 ) ;
} else {
T_1 V_10 ;
asm volatile("mrs %0, dbgauthstatus_el1" : "=r" (val));
* F_11 ( V_4 , V_6 -> V_12 ) = V_10 ;
return true ;
}
}
static bool F_23 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
F_12 ( V_4 , V_8 -> V_14 ) = * F_11 ( V_4 , V_6 -> V_12 ) ;
V_4 -> V_16 . V_17 |= V_18 ;
} else {
* F_11 ( V_4 , V_6 -> V_12 ) = F_12 ( V_4 , V_8 -> V_14 ) ;
}
return true ;
}
static void F_24 ( struct V_3 * V_4 , const struct V_7 * V_8 )
{
T_2 V_19 ;
asm volatile("mrs %0, amair_el1\n" : "=r" (amair));
F_12 ( V_4 , V_20 ) = V_19 ;
}
static void F_25 ( struct V_3 * V_4 , const struct V_7 * V_8 )
{
T_2 V_21 ;
V_21 = ( V_4 -> V_22 & 0x0f ) << F_26 ( 0 ) ;
V_21 |= ( ( V_4 -> V_22 >> 4 ) & 0xff ) << F_26 ( 1 ) ;
V_21 |= ( ( V_4 -> V_22 >> 12 ) & 0xff ) << F_26 ( 2 ) ;
F_12 ( V_4 , V_23 ) = ( 1ULL << 31 ) | V_21 ;
}
static bool F_27 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
return F_19 ( V_4 , V_6 ) ;
} else {
T_2 V_24 = F_28 ( V_25 ) ;
T_2 V_26 = F_28 ( V_27 ) ;
T_1 V_28 = ! ! ( ( V_26 >> 12 ) & 0xf ) ;
* F_11 ( V_4 , V_6 -> V_12 ) = ( ( ( ( V_24 >> 20 ) & 0xf ) << 28 ) |
( ( ( V_24 >> 12 ) & 0xf ) << 24 ) |
( ( ( V_24 >> 28 ) & 0xf ) << 20 ) |
( 6 << 16 ) | ( V_28 << 14 ) | ( V_28 << 12 ) ) ;
return true ;
}
}
static bool F_29 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
F_30 ( V_4 , V_8 -> V_14 ) = * F_11 ( V_4 , V_6 -> V_12 ) ;
V_4 -> V_16 . V_17 |= V_18 ;
} else {
* F_11 ( V_4 , V_6 -> V_12 ) = F_30 ( V_4 , V_8 -> V_14 ) ;
}
return true ;
}
void F_31 ( unsigned int V_29 ,
struct V_30 * V_31 )
{
V_32 [ V_29 ] = V_31 ;
}
static const struct V_7 * F_32 ( unsigned V_29 ,
bool V_33 ,
T_3 * V_34 )
{
struct V_30 * V_31 ;
V_31 = V_32 [ V_29 ] ;
if ( V_33 ) {
* V_34 = V_31 -> V_35 . V_34 ;
return V_31 -> V_35 . V_31 ;
} else {
* V_34 = V_31 -> V_36 . V_34 ;
return V_31 -> V_36 . V_31 ;
}
}
static const struct V_7 * F_33 ( const struct V_5 * V_37 ,
const struct V_7 V_31 [] ,
unsigned int V_34 )
{
unsigned int V_38 ;
for ( V_38 = 0 ; V_38 < V_34 ; V_38 ++ ) {
const struct V_7 * V_8 = & V_31 [ V_38 ] ;
if ( V_37 -> V_39 != V_8 -> V_39 )
continue;
if ( V_37 -> V_40 != V_8 -> V_40 )
continue;
if ( V_37 -> V_41 != V_8 -> V_41 )
continue;
if ( V_37 -> V_42 != V_8 -> V_42 )
continue;
if ( V_37 -> V_43 != V_8 -> V_43 )
continue;
return V_8 ;
}
return NULL ;
}
int F_34 ( struct V_3 * V_4 , struct V_44 * V_45 )
{
F_35 ( V_4 ) ;
return 1 ;
}
static int F_36 ( struct V_3 * V_4 ,
const struct V_5 * V_37 ,
const struct V_7 * V_31 ,
T_3 V_34 )
{
const struct V_7 * V_8 ;
if ( ! V_31 )
return - 1 ;
V_8 = F_33 ( V_37 , V_31 , V_34 ) ;
if ( V_8 ) {
F_10 ( ! V_8 -> V_46 ) ;
if ( F_37 ( V_8 -> V_46 ( V_4 , V_37 , V_8 ) ) ) {
F_38 ( V_4 , F_39 ( V_4 ) ) ;
}
return 0 ;
}
return - 1 ;
}
static void F_40 ( struct V_3 * V_4 ,
struct V_5 * V_37 )
{
T_4 V_47 = F_41 ( V_4 ) ;
int V_48 ;
switch( V_47 ) {
case V_49 :
case V_50 :
V_48 = 15 ;
break;
case V_51 :
case V_52 :
V_48 = 14 ;
break;
default:
F_42 ( ( V_48 = - 1 ) ) ;
}
F_43 ( L_1 ,
V_48 , * F_44 ( V_4 ) ) ;
F_45 ( V_37 ) ;
F_35 ( V_4 ) ;
}
static int F_46 ( struct V_3 * V_4 ,
const struct V_7 * V_53 ,
T_3 V_54 ,
const struct V_7 * V_55 ,
T_3 V_56 )
{
struct V_5 V_37 ;
T_1 V_57 = F_47 ( V_4 ) ;
int V_58 = ( V_57 >> 10 ) & 0xf ;
V_37 . V_13 = true ;
V_37 . V_15 = false ;
V_37 . V_42 = ( V_57 >> 1 ) & 0xf ;
V_37 . V_12 = ( V_57 >> 5 ) & 0xf ;
V_37 . V_9 = ( ( V_57 & 1 ) == 0 ) ;
V_37 . V_39 = 0 ;
V_37 . V_40 = ( V_57 >> 16 ) & 0xf ;
V_37 . V_43 = 0 ;
V_37 . V_41 = 0 ;
if ( V_37 . V_9 ) {
T_2 V_10 = * F_11 ( V_4 , V_37 . V_12 ) ;
V_10 &= 0xffffffff ;
V_10 |= * F_11 ( V_4 , V_58 ) << 32 ;
* F_11 ( V_4 , V_37 . V_12 ) = V_10 ;
}
if ( ! F_36 ( V_4 , & V_37 , V_55 , V_56 ) )
goto V_59;
if ( ! F_36 ( V_4 , & V_37 , V_53 , V_54 ) )
goto V_59;
F_40 ( V_4 , & V_37 ) ;
V_59:
if ( ! V_37 . V_9 ) {
T_2 V_10 = * F_11 ( V_4 , V_37 . V_12 ) ;
V_10 >>= 32 ;
* F_11 ( V_4 , V_58 ) = V_10 ;
}
return 1 ;
}
static int F_48 ( struct V_3 * V_4 ,
const struct V_7 * V_53 ,
T_3 V_54 ,
const struct V_7 * V_55 ,
T_3 V_56 )
{
struct V_5 V_37 ;
T_1 V_57 = F_47 ( V_4 ) ;
V_37 . V_13 = true ;
V_37 . V_15 = true ;
V_37 . V_42 = ( V_57 >> 1 ) & 0xf ;
V_37 . V_12 = ( V_57 >> 5 ) & 0xf ;
V_37 . V_9 = ( ( V_57 & 1 ) == 0 ) ;
V_37 . V_41 = ( V_57 >> 10 ) & 0xf ;
V_37 . V_39 = 0 ;
V_37 . V_40 = ( V_57 >> 14 ) & 0x7 ;
V_37 . V_43 = ( V_57 >> 17 ) & 0x7 ;
if ( ! F_36 ( V_4 , & V_37 , V_55 , V_56 ) )
return 1 ;
if ( ! F_36 ( V_4 , & V_37 , V_53 , V_54 ) )
return 1 ;
F_40 ( V_4 , & V_37 ) ;
return 1 ;
}
int F_49 ( struct V_3 * V_4 , struct V_44 * V_45 )
{
const struct V_7 * V_55 ;
T_3 V_34 ;
V_55 = F_32 ( V_4 -> V_16 . V_29 , false , & V_34 ) ;
return F_46 ( V_4 ,
V_60 , F_50 ( V_60 ) ,
V_55 , V_34 ) ;
}
int F_51 ( struct V_3 * V_4 , struct V_44 * V_45 )
{
const struct V_7 * V_55 ;
T_3 V_34 ;
V_55 = F_32 ( V_4 -> V_16 . V_29 , false , & V_34 ) ;
return F_48 ( V_4 ,
V_61 , F_50 ( V_61 ) ,
V_55 , V_34 ) ;
}
int F_52 ( struct V_3 * V_4 , struct V_44 * V_45 )
{
return F_46 ( V_4 ,
V_62 , F_50 ( V_62 ) ,
NULL , 0 ) ;
}
int F_53 ( struct V_3 * V_4 , struct V_44 * V_45 )
{
return F_48 ( V_4 ,
V_63 , F_50 ( V_63 ) ,
NULL , 0 ) ;
}
static int F_54 ( struct V_3 * V_4 ,
const struct V_5 * V_37 )
{
T_3 V_34 ;
const struct V_7 * V_31 , * V_8 ;
V_31 = F_32 ( V_4 -> V_16 . V_29 , true , & V_34 ) ;
V_8 = F_33 ( V_37 , V_31 , V_34 ) ;
if ( ! V_8 )
V_8 = F_33 ( V_37 , V_64 , F_50 ( V_64 ) ) ;
if ( F_37 ( V_8 ) ) {
F_10 ( ! V_8 -> V_46 ) ;
if ( F_37 ( V_8 -> V_46 ( V_4 , V_37 , V_8 ) ) ) {
F_38 ( V_4 , F_39 ( V_4 ) ) ;
return 1 ;
}
} else {
F_43 ( L_2 ,
* F_44 ( V_4 ) ) ;
F_45 ( V_37 ) ;
}
F_35 ( V_4 ) ;
return 1 ;
}
static void F_55 ( struct V_3 * V_4 ,
const struct V_7 * V_31 , T_3 V_34 )
{
unsigned long V_38 ;
for ( V_38 = 0 ; V_38 < V_34 ; V_38 ++ )
if ( V_31 [ V_38 ] . V_65 )
V_31 [ V_38 ] . V_65 ( V_4 , & V_31 [ V_38 ] ) ;
}
int F_56 ( struct V_3 * V_4 , struct V_44 * V_45 )
{
struct V_5 V_37 ;
unsigned long V_66 = F_47 ( V_4 ) ;
V_37 . V_13 = false ;
V_37 . V_15 = false ;
V_37 . V_39 = ( V_66 >> 20 ) & 3 ;
V_37 . V_40 = ( V_66 >> 14 ) & 0x7 ;
V_37 . V_41 = ( V_66 >> 10 ) & 0xf ;
V_37 . V_42 = ( V_66 >> 1 ) & 0xf ;
V_37 . V_43 = ( V_66 >> 17 ) & 0x7 ;
V_37 . V_12 = ( V_66 >> 5 ) & 0x1f ;
V_37 . V_9 = ! ( V_66 & 1 ) ;
return F_54 ( V_4 , & V_37 ) ;
}
static bool F_57 ( T_2 V_67 , struct V_5 * V_37 )
{
switch ( V_67 & V_68 ) {
case V_69 :
if ( V_67 & ~ ( V_70 | V_68
| V_71
| V_72
| V_73
| V_74
| V_75
| V_76 ) )
return false ;
V_37 -> V_39 = ( ( V_67 & V_72 )
>> V_77 ) ;
V_37 -> V_40 = ( ( V_67 & V_73 )
>> V_78 ) ;
V_37 -> V_41 = ( ( V_67 & V_74 )
>> V_79 ) ;
V_37 -> V_42 = ( ( V_67 & V_75 )
>> V_80 ) ;
V_37 -> V_43 = ( ( V_67 & V_76 )
>> V_81 ) ;
return true ;
default:
return false ;
}
}
static const struct V_7 * F_58 ( struct V_3 * V_4 ,
T_2 V_67 )
{
T_3 V_34 ;
const struct V_7 * V_31 , * V_8 ;
struct V_5 V_37 ;
if ( ( V_67 & V_71 ) != V_82 )
return NULL ;
if ( ! F_57 ( V_67 , & V_37 ) )
return NULL ;
V_31 = F_32 ( V_4 -> V_16 . V_29 , true , & V_34 ) ;
V_8 = F_33 ( & V_37 , V_31 , V_34 ) ;
if ( ! V_8 )
V_8 = F_33 ( & V_37 , V_64 , F_50 ( V_64 ) ) ;
if ( V_8 && ! V_8 -> V_14 )
V_8 = NULL ;
return V_8 ;
}
static int F_59 ( T_2 * V_10 , const void T_5 * V_83 , T_2 V_67 )
{
if ( F_60 ( V_10 , V_83 , F_61 ( V_67 ) ) != 0 )
return - V_84 ;
return 0 ;
}
static int F_62 ( void T_5 * V_83 , const T_2 * V_10 , T_2 V_67 )
{
if ( F_63 ( V_83 , V_10 , F_61 ( V_67 ) ) != 0 )
return - V_84 ;
return 0 ;
}
static int F_64 ( T_2 V_67 , void T_5 * V_83 )
{
struct V_5 V_37 ;
const struct V_7 * V_8 ;
if ( ! F_57 ( V_67 , & V_37 ) )
return - V_85 ;
V_8 = F_33 ( & V_37 , V_86 , F_50 ( V_86 ) ) ;
if ( ! V_8 )
return - V_85 ;
return F_62 ( V_83 , & V_8 -> V_10 , V_67 ) ;
}
static int F_65 ( T_2 V_67 , void T_5 * V_83 )
{
struct V_5 V_37 ;
const struct V_7 * V_8 ;
int V_87 ;
T_2 V_10 = 0 ;
if ( ! F_57 ( V_67 , & V_37 ) )
return - V_85 ;
V_8 = F_33 ( & V_37 , V_86 , F_50 ( V_86 ) ) ;
if ( ! V_8 )
return - V_85 ;
V_87 = F_59 ( & V_10 , V_83 , V_67 ) ;
if ( V_87 )
return V_87 ;
if ( V_8 -> V_10 != V_10 )
return - V_88 ;
return 0 ;
}
static bool F_66 ( T_1 V_10 )
{
T_1 V_89 , V_90 ;
if ( V_10 >= V_91 )
return false ;
V_89 = ( V_10 >> 1 ) ;
V_90 = ( V_92 >> ( V_89 * 3 ) ) & 7 ;
switch ( V_90 ) {
case 0 :
return false ;
case 1 :
return ( V_10 & 1 ) ;
case 2 :
case 4 :
return ! ( V_10 & 1 ) ;
case 3 :
return true ;
default:
return false ;
}
}
static int F_67 ( T_2 V_67 , void T_5 * V_83 )
{
T_1 V_10 ;
T_1 T_5 * V_93 = V_83 ;
if ( V_67 & ~ ( V_70 | V_68 | V_71
| ( ( 1 << V_94 ) - 1 ) ) )
return - V_85 ;
switch ( V_67 & V_95 ) {
case V_96 :
if ( F_61 ( V_67 ) != 4 )
return - V_85 ;
V_10 = ( V_67 & V_97 )
>> V_98 ;
if ( ! F_66 ( V_10 ) )
return - V_85 ;
return F_68 ( F_1 ( V_10 ) , V_93 ) ;
default:
return - V_85 ;
}
}
static int F_69 ( T_2 V_67 , void T_5 * V_83 )
{
T_1 V_10 , V_99 ;
T_1 T_5 * V_93 = V_83 ;
if ( V_67 & ~ ( V_70 | V_68 | V_71
| ( ( 1 << V_94 ) - 1 ) ) )
return - V_85 ;
switch ( V_67 & V_95 ) {
case V_96 :
if ( F_61 ( V_67 ) != 4 )
return - V_85 ;
V_10 = ( V_67 & V_97 )
>> V_98 ;
if ( ! F_66 ( V_10 ) )
return - V_85 ;
if ( F_70 ( V_99 , V_93 ) )
return - V_84 ;
if ( V_99 != F_1 ( V_10 ) )
return - V_88 ;
return 0 ;
default:
return - V_85 ;
}
}
int F_71 ( struct V_3 * V_4 , const struct V_100 * V_14 )
{
const struct V_7 * V_8 ;
void T_5 * V_83 = ( void T_5 * ) ( unsigned long ) V_14 -> V_101 ;
if ( ( V_14 -> V_67 & V_71 ) == V_102 )
return F_67 ( V_14 -> V_67 , V_83 ) ;
if ( F_61 ( V_14 -> V_67 ) != sizeof( V_103 ) )
return - V_85 ;
V_8 = F_58 ( V_4 , V_14 -> V_67 ) ;
if ( ! V_8 )
return F_64 ( V_14 -> V_67 , V_83 ) ;
return F_62 ( V_83 , & F_12 ( V_4 , V_8 -> V_14 ) , V_14 -> V_67 ) ;
}
int F_72 ( struct V_3 * V_4 , const struct V_100 * V_14 )
{
const struct V_7 * V_8 ;
void T_5 * V_83 = ( void T_5 * ) ( unsigned long ) V_14 -> V_101 ;
if ( ( V_14 -> V_67 & V_71 ) == V_102 )
return F_69 ( V_14 -> V_67 , V_83 ) ;
if ( F_61 ( V_14 -> V_67 ) != sizeof( V_103 ) )
return - V_85 ;
V_8 = F_58 ( V_4 , V_14 -> V_67 ) ;
if ( ! V_8 )
return F_65 ( V_14 -> V_67 , V_83 ) ;
return F_59 ( & F_12 ( V_4 , V_8 -> V_14 ) , V_83 , V_14 -> V_67 ) ;
}
static unsigned int F_73 ( void )
{
unsigned int V_38 , V_104 = 0 ;
for ( V_38 = 0 ; V_38 < V_91 ; V_38 ++ )
if ( F_66 ( V_38 ) )
V_104 ++ ;
return V_104 ;
}
static int F_74 ( T_2 T_5 * V_105 )
{
T_2 V_10 = V_106 | V_107 | V_102 ;
unsigned int V_38 ;
V_10 |= V_96 ;
for ( V_38 = 0 ; V_38 < V_91 ; V_38 ++ ) {
if ( ! F_66 ( V_38 ) )
continue;
if ( F_68 ( V_10 | V_38 , V_105 ) )
return - V_84 ;
V_105 ++ ;
}
return 0 ;
}
static T_2 F_75 ( const struct V_7 * V_14 )
{
return ( V_106 | V_69 |
V_82 |
( V_14 -> V_39 << V_77 ) |
( V_14 -> V_40 << V_78 ) |
( V_14 -> V_41 << V_79 ) |
( V_14 -> V_42 << V_80 ) |
( V_14 -> V_43 << V_81 ) ) ;
}
static bool F_76 ( const struct V_7 * V_14 , T_2 T_5 * * V_108 )
{
if ( ! * V_108 )
return true ;
if ( F_68 ( F_75 ( V_14 ) , * V_108 ) )
return false ;
( * V_108 ) ++ ;
return true ;
}
static int F_77 ( struct V_3 * V_4 , T_2 T_5 * V_108 )
{
const struct V_7 * V_109 , * V_110 , * V_111 , * V_112 ;
unsigned int V_113 = 0 ;
T_3 V_34 ;
V_109 = F_32 ( V_4 -> V_16 . V_29 , true , & V_34 ) ;
V_111 = V_109 + V_34 ;
V_110 = V_64 ;
V_112 = V_64 + F_50 ( V_64 ) ;
F_10 ( V_109 == V_111 || V_110 == V_112 ) ;
while ( V_109 || V_110 ) {
int V_114 = F_78 ( V_109 , V_110 ) ;
if ( V_114 <= 0 ) {
if ( V_109 -> V_14 ) {
if ( ! F_76 ( V_109 , & V_108 ) )
return - V_84 ;
V_113 ++ ;
}
} else {
if ( V_110 -> V_14 ) {
if ( ! F_76 ( V_110 , & V_108 ) )
return - V_84 ;
V_113 ++ ;
}
}
if ( V_114 <= 0 && ++ V_109 == V_111 )
V_109 = NULL ;
if ( V_114 >= 0 && ++ V_110 == V_112 )
V_110 = NULL ;
}
return V_113 ;
}
unsigned long F_79 ( struct V_3 * V_4 )
{
return F_50 ( V_86 )
+ F_73 ()
+ F_77 ( V_4 , ( T_2 T_5 * ) NULL ) ;
}
int F_80 ( struct V_3 * V_4 , T_2 T_5 * V_105 )
{
unsigned int V_38 ;
int V_87 ;
for ( V_38 = 0 ; V_38 < F_50 ( V_86 ) ; V_38 ++ ) {
if ( F_68 ( F_75 ( & V_86 [ V_38 ] ) , V_105 ) )
return - V_84 ;
V_105 ++ ;
}
V_87 = F_77 ( V_4 , V_105 ) ;
if ( V_87 < 0 )
return V_87 ;
V_105 += V_87 ;
return F_74 ( V_105 ) ;
}
static int F_81 ( const struct V_7 * V_31 , unsigned int V_115 )
{
unsigned int V_38 ;
for ( V_38 = 1 ; V_38 < V_115 ; V_38 ++ ) {
if ( F_78 ( & V_31 [ V_38 - 1 ] , & V_31 [ V_38 ] ) >= 0 ) {
F_43 ( L_3 , V_31 , V_38 - 1 ) ;
return 1 ;
}
}
return 0 ;
}
void F_82 ( void )
{
unsigned int V_38 ;
struct V_7 V_116 ;
F_10 ( F_81 ( V_64 , F_50 ( V_64 ) ) ) ;
F_10 ( F_81 ( V_63 , F_50 ( V_63 ) ) ) ;
F_10 ( F_81 ( V_62 , F_50 ( V_62 ) ) ) ;
F_10 ( F_81 ( V_61 , F_50 ( V_61 ) ) ) ;
F_10 ( F_81 ( V_60 , F_50 ( V_60 ) ) ) ;
F_10 ( F_81 ( V_86 , F_50 ( V_86 ) ) ) ;
for ( V_38 = 0 ; V_38 < F_50 ( V_86 ) ; V_38 ++ )
V_86 [ V_38 ] . V_65 ( NULL , & V_86 [ V_38 ] ) ;
F_83 ( NULL , & V_116 ) ;
V_92 = V_116 . V_10 ;
for ( V_38 = 0 ; V_38 < 7 ; V_38 ++ )
if ( ( ( V_92 >> ( V_38 * 3 ) ) & 7 ) == 0 )
break;
V_92 &= ( 1 << ( V_38 * 3 ) ) - 1 ;
}
void F_84 ( struct V_3 * V_4 )
{
T_3 V_34 ;
const struct V_7 * V_31 ;
memset ( & V_4 -> V_16 . V_117 . V_118 , 0x42 , sizeof( V_4 -> V_16 . V_117 . V_118 ) ) ;
F_55 ( V_4 , V_64 , F_50 ( V_64 ) ) ;
V_31 = F_32 ( V_4 -> V_16 . V_29 , true , & V_34 ) ;
F_55 ( V_4 , V_31 , V_34 ) ;
for ( V_34 = 1 ; V_34 < V_119 ; V_34 ++ )
if ( F_12 ( V_4 , V_34 ) == 0x4242424242424242 )
F_85 ( L_4 , V_34 ) ;
}

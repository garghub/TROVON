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
static void F_5 ( T_1 V_3 )
{
asm volatile("dc cisw, %x0" : : "r" (val));
F_6 () ;
}
static void F_7 ( T_1 V_3 )
{
asm volatile("dc csw, %x0" : : "r" (val));
F_6 () ;
}
static bool F_8 ( struct V_4 * V_5 ,
const struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
unsigned long V_3 ;
int V_10 ;
if ( ! V_7 -> V_11 )
return F_9 ( V_5 , V_7 ) ;
V_10 = F_10 () ;
F_11 ( & V_5 -> V_12 . V_13 ) ;
F_12 ( V_10 , & V_5 -> V_12 . V_13 ) ;
if ( V_10 != V_5 -> V_12 . V_14 ) {
F_13 () ;
goto V_15;
}
V_3 = * F_14 ( V_5 , V_7 -> V_16 ) ;
switch ( V_7 -> V_17 ) {
case 6 :
case 14 :
F_5 ( V_3 ) ;
break;
case 10 :
F_7 ( V_3 ) ;
break;
}
V_15:
F_15 () ;
return true ;
}
static bool F_16 ( struct V_4 * V_5 ,
const struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
if ( V_7 -> V_11 )
return F_17 ( V_5 , V_7 ) ;
else
return F_18 ( V_5 , V_7 ) ;
}
static void F_19 ( struct V_4 * V_5 , const struct V_8 * V_9 )
{
T_2 V_18 ;
asm volatile("mrs %0, amair_el1\n" : "=r" (amair));
F_20 ( V_5 , V_19 ) = V_18 ;
}
static void F_21 ( struct V_4 * V_5 , const struct V_8 * V_9 )
{
F_20 ( V_5 , V_20 ) = ( 1UL << 31 ) | ( V_5 -> V_21 & 0xff ) ;
}
void F_22 ( unsigned int V_22 ,
struct V_23 * V_24 )
{
V_25 [ V_22 ] = V_24 ;
}
static const struct V_8 * F_23 ( unsigned V_22 ,
bool V_26 ,
T_3 * V_27 )
{
struct V_23 * V_24 ;
V_24 = V_25 [ V_22 ] ;
if ( V_26 ) {
* V_27 = V_24 -> V_28 . V_27 ;
return V_24 -> V_28 . V_24 ;
} else {
* V_27 = V_24 -> V_29 . V_27 ;
return V_24 -> V_29 . V_24 ;
}
}
static const struct V_8 * F_24 ( const struct V_6 * V_30 ,
const struct V_8 V_24 [] ,
unsigned int V_27 )
{
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < V_27 ; V_31 ++ ) {
const struct V_8 * V_9 = & V_24 [ V_31 ] ;
if ( V_30 -> V_32 != V_9 -> V_32 )
continue;
if ( V_30 -> V_33 != V_9 -> V_33 )
continue;
if ( V_30 -> V_34 != V_9 -> V_34 )
continue;
if ( V_30 -> V_17 != V_9 -> V_17 )
continue;
if ( V_30 -> V_35 != V_9 -> V_35 )
continue;
return V_9 ;
}
return NULL ;
}
int F_25 ( struct V_4 * V_5 , struct V_36 * V_37 )
{
F_26 ( V_5 ) ;
return 1 ;
}
int F_27 ( struct V_4 * V_5 , struct V_36 * V_37 )
{
F_26 ( V_5 ) ;
return 1 ;
}
static void F_28 ( struct V_4 * V_5 ,
const struct V_6 * V_30 )
{
T_3 V_27 ;
const struct V_8 * V_24 , * V_9 ;
V_24 = F_23 ( V_5 -> V_12 . V_22 , false , & V_27 ) ;
V_9 = F_24 ( V_30 , V_24 , V_27 ) ;
if ( ! V_9 )
V_9 = F_24 ( V_30 , V_38 , F_29 ( V_38 ) ) ;
if ( F_30 ( V_9 ) ) {
F_31 ( ! V_9 -> V_39 ) ;
if ( F_30 ( V_9 -> V_39 ( V_5 , V_30 , V_9 ) ) ) {
F_32 ( V_5 , F_33 ( V_5 ) ) ;
return;
}
}
F_34 ( L_1 , * F_35 ( V_5 ) ) ;
F_36 ( V_30 ) ;
F_26 ( V_5 ) ;
}
int F_37 ( struct V_4 * V_5 , struct V_36 * V_37 )
{
struct V_6 V_30 ;
T_1 V_40 = F_38 ( V_5 ) ;
int V_41 = ( V_40 >> 10 ) & 0xf ;
V_30 . V_17 = ( V_40 >> 1 ) & 0xf ;
V_30 . V_16 = ( V_40 >> 5 ) & 0xf ;
V_30 . V_11 = ( ( V_40 & 1 ) == 0 ) ;
V_30 . V_32 = 0 ;
V_30 . V_33 = ( V_40 >> 16 ) & 0xf ;
V_30 . V_35 = 0 ;
V_30 . V_34 = 0 ;
if ( V_30 . V_11 ) {
T_2 V_3 = * F_14 ( V_5 , V_30 . V_16 ) ;
V_3 &= 0xffffffff ;
V_3 |= * F_14 ( V_5 , V_41 ) << 32 ;
* F_14 ( V_5 , V_30 . V_16 ) = V_3 ;
}
F_28 ( V_5 , & V_30 ) ;
if ( ! V_30 . V_11 ) {
T_2 V_3 = * F_14 ( V_5 , V_30 . V_16 ) ;
V_3 >>= 32 ;
* F_14 ( V_5 , V_41 ) = V_3 ;
}
return 1 ;
}
int F_39 ( struct V_4 * V_5 , struct V_36 * V_37 )
{
struct V_6 V_30 ;
T_1 V_40 = F_38 ( V_5 ) ;
V_30 . V_17 = ( V_40 >> 1 ) & 0xf ;
V_30 . V_16 = ( V_40 >> 5 ) & 0xf ;
V_30 . V_11 = ( ( V_40 & 1 ) == 0 ) ;
V_30 . V_34 = ( V_40 >> 10 ) & 0xf ;
V_30 . V_32 = 0 ;
V_30 . V_33 = ( V_40 >> 14 ) & 0x7 ;
V_30 . V_35 = ( V_40 >> 17 ) & 0x7 ;
F_28 ( V_5 , & V_30 ) ;
return 1 ;
}
static int F_40 ( struct V_4 * V_5 ,
const struct V_6 * V_30 )
{
T_3 V_27 ;
const struct V_8 * V_24 , * V_9 ;
V_24 = F_23 ( V_5 -> V_12 . V_22 , true , & V_27 ) ;
V_9 = F_24 ( V_30 , V_24 , V_27 ) ;
if ( ! V_9 )
V_9 = F_24 ( V_30 , V_42 , F_29 ( V_42 ) ) ;
if ( F_30 ( V_9 ) ) {
F_31 ( ! V_9 -> V_39 ) ;
if ( F_30 ( V_9 -> V_39 ( V_5 , V_30 , V_9 ) ) ) {
F_32 ( V_5 , F_33 ( V_5 ) ) ;
return 1 ;
}
} else {
F_34 ( L_2 ,
* F_35 ( V_5 ) ) ;
F_36 ( V_30 ) ;
}
F_26 ( V_5 ) ;
return 1 ;
}
static void F_41 ( struct V_4 * V_5 ,
const struct V_8 * V_24 , T_3 V_27 )
{
unsigned long V_31 ;
for ( V_31 = 0 ; V_31 < V_27 ; V_31 ++ )
if ( V_24 [ V_31 ] . V_43 )
V_24 [ V_31 ] . V_43 ( V_5 , & V_24 [ V_31 ] ) ;
}
int F_42 ( struct V_4 * V_5 , struct V_36 * V_37 )
{
struct V_6 V_30 ;
unsigned long V_44 = F_38 ( V_5 ) ;
V_30 . V_32 = ( V_44 >> 20 ) & 3 ;
V_30 . V_33 = ( V_44 >> 14 ) & 0x7 ;
V_30 . V_34 = ( V_44 >> 10 ) & 0xf ;
V_30 . V_17 = ( V_44 >> 1 ) & 0xf ;
V_30 . V_35 = ( V_44 >> 17 ) & 0x7 ;
V_30 . V_16 = ( V_44 >> 5 ) & 0x1f ;
V_30 . V_11 = ! ( V_44 & 1 ) ;
return F_40 ( V_5 , & V_30 ) ;
}
static bool F_43 ( T_2 V_45 , struct V_6 * V_30 )
{
switch ( V_45 & V_46 ) {
case V_47 :
if ( V_45 & ~ ( V_48 | V_46
| V_49
| V_50
| V_51
| V_52
| V_53
| V_54 ) )
return false ;
V_30 -> V_32 = ( ( V_45 & V_50 )
>> V_55 ) ;
V_30 -> V_33 = ( ( V_45 & V_51 )
>> V_56 ) ;
V_30 -> V_34 = ( ( V_45 & V_52 )
>> V_57 ) ;
V_30 -> V_17 = ( ( V_45 & V_53 )
>> V_58 ) ;
V_30 -> V_35 = ( ( V_45 & V_54 )
>> V_59 ) ;
return true ;
default:
return false ;
}
}
static const struct V_8 * F_44 ( struct V_4 * V_5 ,
T_2 V_45 )
{
T_3 V_27 ;
const struct V_8 * V_24 , * V_9 ;
struct V_6 V_30 ;
if ( ( V_45 & V_49 ) != V_60 )
return NULL ;
if ( ! F_43 ( V_45 , & V_30 ) )
return NULL ;
V_24 = F_23 ( V_5 -> V_12 . V_22 , true , & V_27 ) ;
V_9 = F_24 ( & V_30 , V_24 , V_27 ) ;
if ( ! V_9 )
V_9 = F_24 ( & V_30 , V_42 , F_29 ( V_42 ) ) ;
if ( V_9 && ! V_9 -> V_61 )
V_9 = NULL ;
return V_9 ;
}
static int F_45 ( void * V_3 , const void T_4 * V_62 , T_2 V_45 )
{
if ( F_46 ( V_3 , V_62 , F_47 ( V_45 ) ) != 0 )
return - V_63 ;
return 0 ;
}
static int F_48 ( void T_4 * V_62 , const void * V_3 , T_2 V_45 )
{
if ( F_49 ( V_62 , V_3 , F_47 ( V_45 ) ) != 0 )
return - V_63 ;
return 0 ;
}
static int F_50 ( T_2 V_45 , void T_4 * V_62 )
{
struct V_6 V_30 ;
const struct V_8 * V_9 ;
if ( ! F_43 ( V_45 , & V_30 ) )
return - V_64 ;
V_9 = F_24 ( & V_30 , V_65 , F_29 ( V_65 ) ) ;
if ( ! V_9 )
return - V_64 ;
return F_48 ( V_62 , & V_9 -> V_3 , V_45 ) ;
}
static int F_51 ( T_2 V_45 , void T_4 * V_62 )
{
struct V_6 V_30 ;
const struct V_8 * V_9 ;
int V_66 ;
T_2 V_3 = 0 ;
if ( ! F_43 ( V_45 , & V_30 ) )
return - V_64 ;
V_9 = F_24 ( & V_30 , V_65 , F_29 ( V_65 ) ) ;
if ( ! V_9 )
return - V_64 ;
V_66 = F_45 ( & V_3 , V_62 , V_45 ) ;
if ( V_66 )
return V_66 ;
if ( V_9 -> V_3 != V_3 )
return - V_67 ;
return 0 ;
}
static bool F_52 ( T_1 V_3 )
{
T_1 V_68 , V_69 ;
if ( V_3 >= V_70 )
return - V_64 ;
V_68 = ( V_3 >> 1 ) ;
V_69 = ( V_71 >> ( V_68 * 3 ) ) & 7 ;
switch ( V_69 ) {
case 0 :
return false ;
case 1 :
return ( V_3 & 1 ) ;
case 2 :
case 4 :
return ! ( V_3 & 1 ) ;
case 3 :
return true ;
default:
return false ;
}
}
static int F_53 ( T_2 V_45 , void T_4 * V_62 )
{
T_1 V_3 ;
T_1 T_4 * V_72 = V_62 ;
if ( V_45 & ~ ( V_48 | V_46 | V_49
| ( ( 1 << V_73 ) - 1 ) ) )
return - V_64 ;
switch ( V_45 & V_74 ) {
case V_75 :
if ( F_47 ( V_45 ) != 4 )
return - V_64 ;
V_3 = ( V_45 & V_76 )
>> V_77 ;
if ( ! F_52 ( V_3 ) )
return - V_64 ;
return F_54 ( F_1 ( V_3 ) , V_72 ) ;
default:
return - V_64 ;
}
}
static int F_55 ( T_2 V_45 , void T_4 * V_62 )
{
T_1 V_3 , V_78 ;
T_1 T_4 * V_72 = V_62 ;
if ( V_45 & ~ ( V_48 | V_46 | V_49
| ( ( 1 << V_73 ) - 1 ) ) )
return - V_64 ;
switch ( V_45 & V_74 ) {
case V_75 :
if ( F_47 ( V_45 ) != 4 )
return - V_64 ;
V_3 = ( V_45 & V_76 )
>> V_77 ;
if ( ! F_52 ( V_3 ) )
return - V_64 ;
if ( F_56 ( V_78 , V_72 ) )
return - V_63 ;
if ( V_78 != F_1 ( V_3 ) )
return - V_67 ;
return 0 ;
default:
return - V_64 ;
}
}
int F_57 ( struct V_4 * V_5 , const struct V_79 * V_61 )
{
const struct V_8 * V_9 ;
void T_4 * V_62 = ( void T_4 * ) ( unsigned long ) V_61 -> V_80 ;
if ( ( V_61 -> V_45 & V_49 ) == V_81 )
return F_53 ( V_61 -> V_45 , V_62 ) ;
if ( F_47 ( V_61 -> V_45 ) != sizeof( V_82 ) )
return - V_64 ;
V_9 = F_44 ( V_5 , V_61 -> V_45 ) ;
if ( ! V_9 )
return F_50 ( V_61 -> V_45 , V_62 ) ;
return F_48 ( V_62 , & F_20 ( V_5 , V_9 -> V_61 ) , V_61 -> V_45 ) ;
}
int F_58 ( struct V_4 * V_5 , const struct V_79 * V_61 )
{
const struct V_8 * V_9 ;
void T_4 * V_62 = ( void T_4 * ) ( unsigned long ) V_61 -> V_80 ;
if ( ( V_61 -> V_45 & V_49 ) == V_81 )
return F_55 ( V_61 -> V_45 , V_62 ) ;
if ( F_47 ( V_61 -> V_45 ) != sizeof( V_82 ) )
return - V_64 ;
V_9 = F_44 ( V_5 , V_61 -> V_45 ) ;
if ( ! V_9 )
return F_51 ( V_61 -> V_45 , V_62 ) ;
return F_45 ( & F_20 ( V_5 , V_9 -> V_61 ) , V_62 , V_61 -> V_45 ) ;
}
static unsigned int F_59 ( void )
{
unsigned int V_31 , V_83 = 0 ;
for ( V_31 = 0 ; V_31 < V_70 ; V_31 ++ )
if ( F_52 ( V_31 ) )
V_83 ++ ;
return V_83 ;
}
static int F_60 ( T_2 T_4 * V_84 )
{
T_2 V_3 = V_85 | V_86 | V_81 ;
unsigned int V_31 ;
V_3 |= V_75 ;
for ( V_31 = 0 ; V_31 < V_70 ; V_31 ++ ) {
if ( ! F_52 ( V_31 ) )
continue;
if ( F_54 ( V_3 | V_31 , V_84 ) )
return - V_63 ;
V_84 ++ ;
}
return 0 ;
}
static T_2 F_61 ( const struct V_8 * V_61 )
{
return ( V_87 | V_47 |
V_60 |
( V_61 -> V_32 << V_55 ) |
( V_61 -> V_33 << V_56 ) |
( V_61 -> V_34 << V_57 ) |
( V_61 -> V_17 << V_58 ) |
( V_61 -> V_35 << V_59 ) ) ;
}
static bool F_62 ( const struct V_8 * V_61 , T_2 T_4 * * V_88 )
{
if ( ! * V_88 )
return true ;
if ( F_54 ( F_61 ( V_61 ) , * V_88 ) )
return false ;
( * V_88 ) ++ ;
return true ;
}
static int F_63 ( struct V_4 * V_5 , T_2 T_4 * V_88 )
{
const struct V_8 * V_89 , * V_90 , * V_91 , * V_92 ;
unsigned int V_93 = 0 ;
T_3 V_27 ;
V_89 = F_23 ( V_5 -> V_12 . V_22 , true , & V_27 ) ;
V_91 = V_89 + V_27 ;
V_90 = V_42 ;
V_92 = V_42 + F_29 ( V_42 ) ;
F_31 ( V_89 == V_91 || V_90 == V_92 ) ;
while ( V_89 || V_90 ) {
int V_94 = F_64 ( V_89 , V_90 ) ;
if ( V_94 <= 0 ) {
if ( V_89 -> V_61 ) {
if ( ! F_62 ( V_89 , & V_88 ) )
return - V_63 ;
V_93 ++ ;
}
} else {
if ( V_90 -> V_61 ) {
if ( ! F_62 ( V_90 , & V_88 ) )
return - V_63 ;
V_93 ++ ;
}
}
if ( V_94 <= 0 && ++ V_89 == V_91 )
V_89 = NULL ;
if ( V_94 >= 0 && ++ V_90 == V_92 )
V_90 = NULL ;
}
return V_93 ;
}
unsigned long F_65 ( struct V_4 * V_5 )
{
return F_29 ( V_65 )
+ F_59 ()
+ F_63 ( V_5 , ( T_2 T_4 * ) NULL ) ;
}
int F_66 ( struct V_4 * V_5 , T_2 T_4 * V_84 )
{
unsigned int V_31 ;
int V_66 ;
for ( V_31 = 0 ; V_31 < F_29 ( V_65 ) ; V_31 ++ ) {
if ( F_54 ( F_61 ( & V_65 [ V_31 ] ) , V_84 ) )
return - V_63 ;
V_84 ++ ;
}
V_66 = F_63 ( V_5 , V_84 ) ;
if ( V_66 < 0 )
return V_66 ;
V_84 += V_66 ;
return F_60 ( V_84 ) ;
}
void F_67 ( void )
{
unsigned int V_31 ;
struct V_8 V_95 ;
for ( V_31 = 1 ; V_31 < F_29 ( V_42 ) ; V_31 ++ )
F_31 ( F_64 ( & V_42 [ V_31 - 1 ] , & V_42 [ V_31 ] ) >= 0 ) ;
for ( V_31 = 0 ; V_31 < F_29 ( V_65 ) ; V_31 ++ )
V_65 [ V_31 ] . V_43 ( NULL , & V_65 [ V_31 ] ) ;
F_68 ( NULL , & V_95 ) ;
V_71 = V_95 . V_3 ;
for ( V_31 = 0 ; V_31 < 7 ; V_31 ++ )
if ( ( ( V_71 >> ( V_31 * 3 ) ) & 7 ) == 0 )
break;
V_71 &= ( 1 << ( V_31 * 3 ) ) - 1 ;
}
void F_69 ( struct V_4 * V_5 )
{
T_3 V_27 ;
const struct V_8 * V_24 ;
memset ( & V_5 -> V_12 . V_96 . V_97 , 0x42 , sizeof( V_5 -> V_12 . V_96 . V_97 ) ) ;
F_41 ( V_5 , V_42 , F_29 ( V_42 ) ) ;
V_24 = F_23 ( V_5 -> V_12 . V_22 , true , & V_27 ) ;
F_41 ( V_5 , V_24 , V_27 ) ;
for ( V_27 = 1 ; V_27 < V_98 ; V_27 ++ )
if ( F_20 ( V_5 , V_27 ) == 0x4242424242424242 )
F_70 ( L_3 , V_27 ) ;
}

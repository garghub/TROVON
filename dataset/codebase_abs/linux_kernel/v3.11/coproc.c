int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_2 ) ;
return 1 ;
}
int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_2 ) ;
return 1 ;
}
int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_2 ) ;
return 1 ;
}
int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_2 ) ;
return 1 ;
}
static bool F_6 ( struct V_1 * V_2 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
unsigned long V_9 ;
int V_10 ;
if ( ! V_6 -> V_11 )
return F_7 ( V_2 , V_6 ) ;
V_10 = F_8 () ;
F_9 ( & V_2 -> V_12 . V_13 ) ;
F_10 ( V_10 , & V_2 -> V_12 . V_13 ) ;
if ( V_10 != V_2 -> V_12 . V_14 ) {
F_11 () ;
goto V_15;
}
V_9 = * F_12 ( V_2 , V_6 -> V_16 ) ;
switch ( V_6 -> V_17 ) {
case 6 :
case 14 :
asm volatile("mcr p15, 0, %0, c7, c14, 2" : : "r" (val));
break;
case 10 :
asm volatile("mcr p15, 0, %0, c7, c10, 2" : : "r" (val));
break;
}
V_15:
F_13 () ;
return true ;
}
static bool F_14 ( struct V_1 * V_2 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_11 )
return F_15 ( V_2 , V_6 ) ;
else
return F_16 ( V_2 , V_6 ) ;
}
void F_17 ( struct V_18 * V_19 )
{
V_20 [ V_19 -> V_21 ] = V_19 ;
}
static const struct V_7 * F_18 ( unsigned V_21 , T_1 * V_22 )
{
struct V_18 * V_19 ;
V_19 = V_20 [ V_21 ] ;
* V_22 = V_19 -> V_22 ;
return V_19 -> V_19 ;
}
static const struct V_7 * F_19 ( const struct V_5 * V_23 ,
const struct V_7 V_19 [] ,
unsigned int V_22 )
{
unsigned int V_24 ;
for ( V_24 = 0 ; V_24 < V_22 ; V_24 ++ ) {
const struct V_7 * V_8 = & V_19 [ V_24 ] ;
if ( V_23 -> V_25 != V_8 -> V_26 )
continue;
if ( V_23 -> V_27 != V_8 -> V_27 )
continue;
if ( V_23 -> V_17 != V_8 -> V_17 )
continue;
if ( V_23 -> V_28 != V_8 -> V_28 )
continue;
if ( V_23 -> V_29 != V_8 -> V_29 )
continue;
return V_8 ;
}
return NULL ;
}
static int F_20 ( struct V_1 * V_2 ,
const struct V_5 * V_23 )
{
T_1 V_22 ;
const struct V_7 * V_19 , * V_8 ;
F_21 ( V_23 -> V_28 , V_23 -> V_16 , V_23 -> V_27 ,
V_23 -> V_17 , V_23 -> V_29 , V_23 -> V_11 ) ;
V_19 = F_18 ( V_2 -> V_12 . V_21 , & V_22 ) ;
V_8 = F_19 ( V_23 , V_19 , V_22 ) ;
if ( ! V_8 )
V_8 = F_19 ( V_23 , V_30 , F_22 ( V_30 ) ) ;
if ( F_23 ( V_8 ) ) {
F_24 ( ! V_8 -> V_31 ) ;
if ( F_23 ( V_8 -> V_31 ( V_2 , V_23 , V_8 ) ) ) {
F_25 ( V_2 , F_26 ( V_2 ) ) ;
return 1 ;
}
} else {
F_27 ( L_1 ,
* F_28 ( V_2 ) ) ;
F_29 ( V_23 ) ;
}
F_2 ( V_2 ) ;
return 1 ;
}
int F_30 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_23 ;
V_23 . V_17 = ( F_31 ( V_2 ) >> 1 ) & 0xf ;
V_23 . V_16 = ( F_31 ( V_2 ) >> 5 ) & 0xf ;
V_23 . V_11 = ( ( F_31 ( V_2 ) & 1 ) == 0 ) ;
V_23 . V_25 = true ;
V_23 . V_28 = ( F_31 ( V_2 ) >> 16 ) & 0xf ;
V_23 . V_29 = 0 ;
V_23 . V_32 = ( F_31 ( V_2 ) >> 10 ) & 0xf ;
V_23 . V_27 = 0 ;
return F_20 ( V_2 , & V_23 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
const struct V_7 * V_19 , T_1 V_22 )
{
unsigned long V_24 ;
for ( V_24 = 0 ; V_24 < V_22 ; V_24 ++ )
if ( V_19 [ V_24 ] . V_33 )
V_19 [ V_24 ] . V_33 ( V_2 , & V_19 [ V_24 ] ) ;
}
int F_33 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_23 ;
V_23 . V_17 = ( F_31 ( V_2 ) >> 1 ) & 0xf ;
V_23 . V_16 = ( F_31 ( V_2 ) >> 5 ) & 0xf ;
V_23 . V_11 = ( ( F_31 ( V_2 ) & 1 ) == 0 ) ;
V_23 . V_25 = false ;
V_23 . V_27 = ( F_31 ( V_2 ) >> 10 ) & 0xf ;
V_23 . V_28 = ( F_31 ( V_2 ) >> 14 ) & 0x7 ;
V_23 . V_29 = ( F_31 ( V_2 ) >> 17 ) & 0x7 ;
V_23 . V_32 = 0 ;
return F_20 ( V_2 , & V_23 ) ;
}
static bool F_34 ( T_2 V_34 , struct V_5 * V_23 )
{
switch ( V_34 & V_35 ) {
case V_36 :
if ( V_34 & ~ ( V_37 | V_35
| V_38
| V_39
| V_40
| V_41
| V_42 ) )
return false ;
V_23 -> V_25 = false ;
V_23 -> V_27 = ( ( V_34 & V_39 )
>> V_43 ) ;
V_23 -> V_17 = ( ( V_34 & V_40 )
>> V_44 ) ;
V_23 -> V_28 = ( ( V_34 & V_41 )
>> V_45 ) ;
V_23 -> V_29 = ( ( V_34 & V_42 )
>> V_46 ) ;
return true ;
case V_47 :
if ( V_34 & ~ ( V_37 | V_35
| V_38
| V_40
| V_41 ) )
return false ;
V_23 -> V_25 = true ;
V_23 -> V_27 = ( ( V_34 & V_40 )
>> V_44 ) ;
V_23 -> V_28 = ( ( V_34 & V_41 )
>> V_45 ) ;
V_23 -> V_29 = 0 ;
V_23 -> V_17 = 0 ;
return true ;
default:
return false ;
}
}
static const struct V_7 * F_35 ( struct V_1 * V_2 ,
T_2 V_34 )
{
T_1 V_22 ;
const struct V_7 * V_19 , * V_8 ;
struct V_5 V_23 ;
if ( ( V_34 & V_38 ) >> V_48 != 15 )
return NULL ;
if ( ! F_34 ( V_34 , & V_23 ) )
return NULL ;
V_19 = F_18 ( V_2 -> V_12 . V_21 , & V_22 ) ;
V_8 = F_19 ( & V_23 , V_19 , V_22 ) ;
if ( ! V_8 )
V_8 = F_19 ( & V_23 , V_30 , F_22 ( V_30 ) ) ;
if ( V_8 && ! V_8 -> V_49 )
V_8 = NULL ;
return V_8 ;
}
static int F_36 ( void * V_9 , const void T_3 * V_50 , T_2 V_34 )
{
if ( F_37 ( V_9 , V_50 , F_38 ( V_34 ) ) != 0 )
return - V_51 ;
return 0 ;
}
static int F_39 ( void T_3 * V_50 , const void * V_9 , T_2 V_34 )
{
if ( F_40 ( V_50 , V_9 , F_38 ( V_34 ) ) != 0 )
return - V_51 ;
return 0 ;
}
static int F_41 ( T_2 V_34 , void T_3 * V_50 )
{
struct V_5 V_23 ;
const struct V_7 * V_8 ;
if ( ! F_34 ( V_34 , & V_23 ) )
return - V_52 ;
V_8 = F_19 ( & V_23 , V_53 , F_22 ( V_53 ) ) ;
if ( ! V_8 )
return - V_52 ;
return F_39 ( V_50 , & V_8 -> V_9 , V_34 ) ;
}
static int F_42 ( T_2 V_34 , void T_3 * V_50 )
{
struct V_5 V_23 ;
const struct V_7 * V_8 ;
int V_54 ;
T_2 V_9 = 0 ;
if ( ! F_34 ( V_34 , & V_23 ) )
return - V_52 ;
V_8 = F_19 ( & V_23 , V_53 , F_22 ( V_53 ) ) ;
if ( ! V_8 )
return - V_52 ;
V_54 = F_36 ( & V_9 , V_50 , V_34 ) ;
if ( V_54 )
return V_54 ;
if ( V_8 -> V_9 != V_9 )
return - V_55 ;
return 0 ;
}
static bool F_43 ( T_4 V_9 )
{
T_4 V_56 , V_57 ;
if ( V_9 >= V_58 )
return - V_52 ;
V_56 = ( V_9 >> 1 ) ;
V_57 = ( V_59 >> ( V_56 * 3 ) ) & 7 ;
switch ( V_57 ) {
case 0 :
return false ;
case 1 :
return ( V_9 & 1 ) ;
case 2 :
case 4 :
return ! ( V_9 & 1 ) ;
case 3 :
return true ;
default:
return false ;
}
}
static T_4 F_44 ( T_4 V_60 )
{
T_4 V_61 ;
F_45 () ;
asm volatile("mcr p15, 2, %0, c0, c0, 0" : : "r" (csselr));
F_46 () ;
asm volatile("mrc p15, 1, %0, c0, c0, 0" : "=r" (ccsidr));
F_47 () ;
return V_61 ;
}
static int F_48 ( T_2 V_34 , void T_3 * V_50 )
{
T_4 V_9 ;
T_4 T_3 * V_62 = V_50 ;
if ( V_34 & ~ ( V_37 | V_35 | V_38
| ( ( 1 << V_48 ) - 1 ) ) )
return - V_52 ;
switch ( V_34 & V_63 ) {
case V_64 :
if ( F_38 ( V_34 ) != 4 )
return - V_52 ;
V_9 = ( V_34 & V_65 )
>> V_66 ;
if ( ! F_43 ( V_9 ) )
return - V_52 ;
return F_49 ( F_44 ( V_9 ) , V_62 ) ;
default:
return - V_52 ;
}
}
static int F_50 ( T_2 V_34 , void T_3 * V_50 )
{
T_4 V_9 , V_67 ;
T_4 T_3 * V_62 = V_50 ;
if ( V_34 & ~ ( V_37 | V_35 | V_38
| ( ( 1 << V_48 ) - 1 ) ) )
return - V_52 ;
switch ( V_34 & V_63 ) {
case V_64 :
if ( F_38 ( V_34 ) != 4 )
return - V_52 ;
V_9 = ( V_34 & V_65 )
>> V_66 ;
if ( ! F_43 ( V_9 ) )
return - V_52 ;
if ( F_51 ( V_67 , V_62 ) )
return - V_51 ;
if ( V_67 != F_44 ( V_9 ) )
return - V_55 ;
return 0 ;
default:
return - V_52 ;
}
}
static unsigned int F_52 ( void )
{
if ( ( ( F_53 ( V_68 ) & V_69 ) >> V_70 ) == 2 )
return 32 ;
else
return 16 ;
}
static unsigned int F_54 ( void )
{
return F_52 () + F_22 ( V_71 ) ;
}
static int F_55 ( T_2 T_3 * V_72 )
{
unsigned int V_24 ;
const T_2 V_73 = V_74 | V_36 | V_75 ;
const T_2 V_76 = V_74 | V_47 | V_75 ;
for ( V_24 = 0 ; V_24 < F_52 () ; V_24 ++ ) {
if ( F_49 ( ( V_76 | V_77 ) + V_24 ,
V_72 ) )
return - V_51 ;
V_72 ++ ;
}
for ( V_24 = 0 ; V_24 < F_22 ( V_71 ) ; V_24 ++ ) {
if ( F_49 ( V_73 | V_71 [ V_24 ] , V_72 ) )
return - V_51 ;
V_72 ++ ;
}
return F_54 () ;
}
static int F_56 ( const struct V_1 * V_2 , T_2 V_34 , void T_3 * V_50 )
{
T_4 V_78 = ( V_34 & V_79 ) ;
T_4 V_9 ;
if ( V_34 & ~ ( V_37 | V_35 | V_38
| ( ( 1 << V_48 ) - 1 ) ) )
return - V_52 ;
if ( V_78 < F_52 () ) {
if ( F_38 ( V_34 ) != 8 )
return - V_52 ;
return F_39 ( V_50 , & V_2 -> V_12 . V_80 . V_81 [ V_78 ] ,
V_34 ) ;
}
if ( F_38 ( V_34 ) != 4 )
return - V_52 ;
switch ( V_78 ) {
case V_82 :
return F_39 ( V_50 , & V_2 -> V_12 . V_80 . V_83 , V_34 ) ;
case V_84 :
return F_39 ( V_50 , & V_2 -> V_12 . V_80 . V_85 , V_34 ) ;
case V_86 :
return F_39 ( V_50 , & V_2 -> V_12 . V_80 . V_87 , V_34 ) ;
case V_88 :
return F_39 ( V_50 , & V_2 -> V_12 . V_80 . V_89 , V_34 ) ;
case V_90 :
V_9 = F_53 ( V_68 ) ;
return F_39 ( V_50 , & V_9 , V_34 ) ;
case V_91 :
V_9 = F_53 ( V_92 ) ;
return F_39 ( V_50 , & V_9 , V_34 ) ;
case V_93 :
V_9 = F_53 ( V_94 ) ;
return F_39 ( V_50 , & V_9 , V_34 ) ;
default:
return - V_52 ;
}
}
static int F_57 ( struct V_1 * V_2 , T_2 V_34 , const void T_3 * V_50 )
{
T_4 V_78 = ( V_34 & V_79 ) ;
T_4 V_9 ;
if ( V_34 & ~ ( V_37 | V_35 | V_38
| ( ( 1 << V_48 ) - 1 ) ) )
return - V_52 ;
if ( V_78 < F_52 () ) {
if ( F_38 ( V_34 ) != 8 )
return - V_52 ;
return F_36 ( & V_2 -> V_12 . V_80 . V_81 [ V_78 ] ,
V_50 , V_34 ) ;
}
if ( F_38 ( V_34 ) != 4 )
return - V_52 ;
switch ( V_78 ) {
case V_82 :
return F_36 ( & V_2 -> V_12 . V_80 . V_83 , V_50 , V_34 ) ;
case V_84 :
return F_36 ( & V_2 -> V_12 . V_80 . V_85 , V_50 , V_34 ) ;
case V_86 :
return F_36 ( & V_2 -> V_12 . V_80 . V_87 , V_50 , V_34 ) ;
case V_88 :
return F_36 ( & V_2 -> V_12 . V_80 . V_89 , V_50 , V_34 ) ;
case V_90 :
if ( F_36 ( & V_9 , V_50 , V_34 ) )
return - V_51 ;
if ( V_9 != F_53 ( V_68 ) )
return - V_55 ;
return 0 ;
case V_91 :
if ( F_36 ( & V_9 , V_50 , V_34 ) )
return - V_51 ;
if ( V_9 != F_53 ( V_92 ) )
return - V_55 ;
return 0 ;
case V_93 :
if ( F_36 ( & V_9 , V_50 , V_34 ) )
return - V_51 ;
if ( V_9 != F_53 ( V_94 ) )
return - V_55 ;
return 0 ;
default:
return - V_52 ;
}
}
static unsigned int F_54 ( void )
{
return 0 ;
}
static int F_55 ( T_2 T_3 * V_72 )
{
return 0 ;
}
static int F_56 ( const struct V_1 * V_2 , T_2 V_34 , void T_3 * V_50 )
{
return - V_52 ;
}
static int F_57 ( struct V_1 * V_2 , T_2 V_34 , const void T_3 * V_50 )
{
return - V_52 ;
}
int F_58 ( struct V_1 * V_2 , const struct V_95 * V_49 )
{
const struct V_7 * V_8 ;
void T_3 * V_50 = ( void T_3 * ) ( long ) V_49 -> V_96 ;
if ( ( V_49 -> V_34 & V_38 ) == V_97 )
return F_48 ( V_49 -> V_34 , V_50 ) ;
if ( ( V_49 -> V_34 & V_38 ) == V_75 )
return F_56 ( V_2 , V_49 -> V_34 , V_50 ) ;
V_8 = F_35 ( V_2 , V_49 -> V_34 ) ;
if ( ! V_8 )
return F_41 ( V_49 -> V_34 , V_50 ) ;
return F_39 ( V_50 , & V_2 -> V_12 . V_98 [ V_8 -> V_49 ] , V_49 -> V_34 ) ;
}
int F_59 ( struct V_1 * V_2 , const struct V_95 * V_49 )
{
const struct V_7 * V_8 ;
void T_3 * V_50 = ( void T_3 * ) ( long ) V_49 -> V_96 ;
if ( ( V_49 -> V_34 & V_38 ) == V_97 )
return F_50 ( V_49 -> V_34 , V_50 ) ;
if ( ( V_49 -> V_34 & V_38 ) == V_75 )
return F_57 ( V_2 , V_49 -> V_34 , V_50 ) ;
V_8 = F_35 ( V_2 , V_49 -> V_34 ) ;
if ( ! V_8 )
return F_42 ( V_49 -> V_34 , V_50 ) ;
return F_36 ( & V_2 -> V_12 . V_98 [ V_8 -> V_49 ] , V_50 , V_49 -> V_34 ) ;
}
static unsigned int F_60 ( void )
{
unsigned int V_24 , V_99 = 0 ;
for ( V_24 = 0 ; V_24 < V_58 ; V_24 ++ )
if ( F_43 ( V_24 ) )
V_99 ++ ;
return V_99 ;
}
static int F_61 ( T_2 T_3 * V_72 )
{
T_2 V_9 = V_74 | V_36 | V_97 ;
unsigned int V_24 ;
V_9 |= V_64 ;
for ( V_24 = 0 ; V_24 < V_58 ; V_24 ++ ) {
if ( ! F_43 ( V_24 ) )
continue;
if ( F_49 ( V_9 | V_24 , V_72 ) )
return - V_51 ;
V_72 ++ ;
}
return 0 ;
}
static T_2 F_62 ( const struct V_7 * V_49 )
{
T_2 V_9 = V_74 | ( 15 << V_48 ) ;
if ( V_49 -> V_26 ) {
V_9 |= V_47 ;
V_9 |= ( V_49 -> V_28 << V_45 ) ;
V_9 |= ( V_49 -> V_27 << V_44 ) ;
} else {
V_9 |= V_36 ;
V_9 |= ( V_49 -> V_28 << V_45 ) ;
V_9 |= ( V_49 -> V_29 << V_46 ) ;
V_9 |= ( V_49 -> V_17 << V_44 ) ;
V_9 |= ( V_49 -> V_27 << V_43 ) ;
}
return V_9 ;
}
static bool F_63 ( const struct V_7 * V_49 , T_2 T_3 * * V_100 )
{
if ( ! * V_100 )
return true ;
if ( F_49 ( F_62 ( V_49 ) , * V_100 ) )
return false ;
( * V_100 ) ++ ;
return true ;
}
static int F_64 ( struct V_1 * V_2 , T_2 T_3 * V_100 )
{
const struct V_7 * V_101 , * V_102 , * V_103 , * V_104 ;
unsigned int V_105 = 0 ;
T_1 V_22 ;
V_101 = F_18 ( V_2 -> V_12 . V_21 , & V_22 ) ;
V_103 = V_101 + V_22 ;
V_102 = V_30 ;
V_104 = V_30 + F_22 ( V_30 ) ;
F_24 ( V_101 == V_103 || V_102 == V_104 ) ;
while ( V_101 || V_102 ) {
int V_106 = F_65 ( V_101 , V_102 ) ;
if ( V_106 <= 0 ) {
if ( V_101 -> V_49 ) {
if ( ! F_63 ( V_101 , & V_100 ) )
return - V_51 ;
V_105 ++ ;
}
} else {
if ( V_102 -> V_49 ) {
if ( ! F_63 ( V_102 , & V_100 ) )
return - V_51 ;
V_105 ++ ;
}
}
if ( V_106 <= 0 && ++ V_101 == V_103 )
V_101 = NULL ;
if ( V_106 >= 0 && ++ V_102 == V_104 )
V_102 = NULL ;
}
return V_105 ;
}
unsigned long F_66 ( struct V_1 * V_2 )
{
return F_22 ( V_53 )
+ F_60 ()
+ F_54 ()
+ F_64 ( V_2 , ( T_2 T_3 * ) NULL ) ;
}
int F_67 ( struct V_1 * V_2 , T_2 T_3 * V_72 )
{
unsigned int V_24 ;
int V_54 ;
for ( V_24 = 0 ; V_24 < F_22 ( V_53 ) ; V_24 ++ ) {
if ( F_49 ( F_62 ( & V_53 [ V_24 ] ) , V_72 ) )
return - V_51 ;
V_72 ++ ;
}
V_54 = F_64 ( V_2 , V_72 ) ;
if ( V_54 < 0 )
return V_54 ;
V_72 += V_54 ;
V_54 = F_55 ( V_72 ) ;
if ( V_54 < 0 )
return V_54 ;
V_72 += V_54 ;
return F_61 ( V_72 ) ;
}
void F_68 ( void )
{
unsigned int V_24 ;
for ( V_24 = 1 ; V_24 < F_22 ( V_30 ) ; V_24 ++ )
F_24 ( F_65 ( & V_30 [ V_24 - 1 ] , & V_30 [ V_24 ] ) >= 0 ) ;
for ( V_24 = 0 ; V_24 < F_22 ( V_53 ) ; V_24 ++ )
V_53 [ V_24 ] . V_33 ( NULL , & V_53 [ V_24 ] ) ;
asm volatile("mrc p15, 1, %0, c0, c0, 1" : "=r" (cache_levels));
for ( V_24 = 0 ; V_24 < 7 ; V_24 ++ )
if ( ( ( V_59 >> ( V_24 * 3 ) ) & 7 ) == 0 )
break;
V_59 &= ( 1 << ( V_24 * 3 ) ) - 1 ;
}
void F_69 ( struct V_1 * V_2 )
{
T_1 V_22 ;
const struct V_7 * V_19 ;
memset ( V_2 -> V_12 . V_98 , 0x42 , sizeof( V_2 -> V_12 . V_98 ) ) ;
F_32 ( V_2 , V_30 , F_22 ( V_30 ) ) ;
V_19 = F_18 ( V_2 -> V_12 . V_21 , & V_22 ) ;
F_32 ( V_2 , V_19 , V_22 ) ;
for ( V_22 = 1 ; V_22 < V_107 ; V_22 ++ )
if ( V_2 -> V_12 . V_98 [ V_22 ] == 0x42424242 )
F_70 ( L_2 , V_22 ) ;
}

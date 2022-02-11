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
T_1 V_9 ;
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
static const struct V_7 * F_18 ( unsigned V_21 , T_2 * V_22 )
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
T_2 V_22 ;
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
F_25 ( V_2 , ( V_2 -> V_12 . V_32 >> 25 ) & 1 ) ;
return 1 ;
}
} else {
F_26 ( L_1 ,
* F_27 ( V_2 ) ) ;
F_28 ( V_23 ) ;
}
F_2 ( V_2 ) ;
return 1 ;
}
int F_29 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_23 ;
V_23 . V_17 = ( V_2 -> V_12 . V_32 >> 1 ) & 0xf ;
V_23 . V_16 = ( V_2 -> V_12 . V_32 >> 5 ) & 0xf ;
V_23 . V_11 = ( ( V_2 -> V_12 . V_32 & 1 ) == 0 ) ;
V_23 . V_25 = true ;
V_23 . V_28 = ( V_2 -> V_12 . V_32 >> 16 ) & 0xf ;
V_23 . V_29 = 0 ;
V_23 . V_33 = ( V_2 -> V_12 . V_32 >> 10 ) & 0xf ;
V_23 . V_27 = 0 ;
return F_20 ( V_2 , & V_23 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
const struct V_7 * V_19 , T_2 V_22 )
{
unsigned long V_24 ;
for ( V_24 = 0 ; V_24 < V_22 ; V_24 ++ )
if ( V_19 [ V_24 ] . V_34 )
V_19 [ V_24 ] . V_34 ( V_2 , & V_19 [ V_24 ] ) ;
}
int F_31 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_23 ;
V_23 . V_17 = ( V_2 -> V_12 . V_32 >> 1 ) & 0xf ;
V_23 . V_16 = ( V_2 -> V_12 . V_32 >> 5 ) & 0xf ;
V_23 . V_11 = ( ( V_2 -> V_12 . V_32 & 1 ) == 0 ) ;
V_23 . V_25 = false ;
V_23 . V_27 = ( V_2 -> V_12 . V_32 >> 10 ) & 0xf ;
V_23 . V_28 = ( V_2 -> V_12 . V_32 >> 14 ) & 0x7 ;
V_23 . V_29 = ( V_2 -> V_12 . V_32 >> 17 ) & 0x7 ;
V_23 . V_33 = 0 ;
return F_20 ( V_2 , & V_23 ) ;
}
static bool F_32 ( T_3 V_35 , struct V_5 * V_23 )
{
switch ( V_35 & V_36 ) {
case V_37 :
if ( V_35 & ~ ( V_38 | V_36
| V_39
| V_40
| V_41
| V_42
| V_43 ) )
return false ;
V_23 -> V_25 = false ;
V_23 -> V_27 = ( ( V_35 & V_40 )
>> V_44 ) ;
V_23 -> V_17 = ( ( V_35 & V_41 )
>> V_45 ) ;
V_23 -> V_28 = ( ( V_35 & V_42 )
>> V_46 ) ;
V_23 -> V_29 = ( ( V_35 & V_43 )
>> V_47 ) ;
return true ;
case V_48 :
if ( V_35 & ~ ( V_38 | V_36
| V_39
| V_41
| V_42 ) )
return false ;
V_23 -> V_25 = true ;
V_23 -> V_17 = ( ( V_35 & V_41 )
>> V_45 ) ;
V_23 -> V_28 = ( ( V_35 & V_42 )
>> V_46 ) ;
V_23 -> V_29 = 0 ;
V_23 -> V_27 = 0 ;
return true ;
default:
return false ;
}
}
static const struct V_7 * F_33 ( struct V_1 * V_2 ,
T_3 V_35 )
{
T_2 V_22 ;
const struct V_7 * V_19 , * V_8 ;
struct V_5 V_23 ;
if ( ( V_35 & V_39 ) >> V_49 != 15 )
return NULL ;
if ( ! F_32 ( V_35 , & V_23 ) )
return NULL ;
V_19 = F_18 ( V_2 -> V_12 . V_21 , & V_22 ) ;
V_8 = F_19 ( & V_23 , V_19 , V_22 ) ;
if ( ! V_8 )
V_8 = F_19 ( & V_23 , V_30 , F_22 ( V_30 ) ) ;
if ( V_8 && ! V_8 -> V_50 )
V_8 = NULL ;
return V_8 ;
}
static int F_34 ( void * V_9 , const void T_4 * V_51 , T_3 V_35 )
{
if ( F_35 ( V_9 , V_51 , F_36 ( V_35 ) ) != 0 )
return - V_52 ;
return 0 ;
}
static int F_37 ( void T_4 * V_51 , const void * V_9 , T_3 V_35 )
{
if ( F_38 ( V_51 , V_9 , F_36 ( V_35 ) ) != 0 )
return - V_52 ;
return 0 ;
}
static int F_39 ( T_3 V_35 , void T_4 * V_51 )
{
struct V_5 V_23 ;
const struct V_7 * V_8 ;
if ( ! F_32 ( V_35 , & V_23 ) )
return - V_53 ;
V_8 = F_19 ( & V_23 , V_54 , F_22 ( V_54 ) ) ;
if ( ! V_8 )
return - V_53 ;
return F_37 ( V_51 , & V_8 -> V_9 , V_35 ) ;
}
static int F_40 ( T_3 V_35 , void T_4 * V_51 )
{
struct V_5 V_23 ;
const struct V_7 * V_8 ;
int V_55 ;
T_3 V_9 = 0 ;
if ( ! F_32 ( V_35 , & V_23 ) )
return - V_53 ;
V_8 = F_19 ( & V_23 , V_54 , F_22 ( V_54 ) ) ;
if ( ! V_8 )
return - V_53 ;
V_55 = F_34 ( & V_9 , V_51 , V_35 ) ;
if ( V_55 )
return V_55 ;
if ( V_8 -> V_9 != V_9 )
return - V_56 ;
return 0 ;
}
static bool F_41 ( T_1 V_9 )
{
T_1 V_57 , V_58 ;
if ( V_9 >= V_59 )
return - V_53 ;
V_57 = ( V_9 >> 1 ) ;
V_58 = ( V_60 >> ( V_57 * 3 ) ) & 7 ;
switch ( V_58 ) {
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
static T_1 F_42 ( T_1 V_61 )
{
T_1 V_62 ;
F_43 () ;
asm volatile("mcr p15, 2, %0, c0, c0, 0" : : "r" (csselr));
F_44 () ;
asm volatile("mrc p15, 1, %0, c0, c0, 0" : "=r" (ccsidr));
F_45 () ;
return V_62 ;
}
static int F_46 ( T_3 V_35 , void T_4 * V_51 )
{
T_1 V_9 ;
T_1 T_4 * V_63 = V_51 ;
if ( V_35 & ~ ( V_38 | V_36 | V_39
| ( ( 1 << V_49 ) - 1 ) ) )
return - V_53 ;
switch ( V_35 & V_64 ) {
case V_65 :
if ( F_36 ( V_35 ) != 4 )
return - V_53 ;
V_9 = ( V_35 & V_66 )
>> V_67 ;
if ( ! F_41 ( V_9 ) )
return - V_53 ;
return F_47 ( F_42 ( V_9 ) , V_63 ) ;
default:
return - V_53 ;
}
}
static int F_48 ( T_3 V_35 , void T_4 * V_51 )
{
T_1 V_9 , V_68 ;
T_1 T_4 * V_63 = V_51 ;
if ( V_35 & ~ ( V_38 | V_36 | V_39
| ( ( 1 << V_49 ) - 1 ) ) )
return - V_53 ;
switch ( V_35 & V_64 ) {
case V_65 :
if ( F_36 ( V_35 ) != 4 )
return - V_53 ;
V_9 = ( V_35 & V_66 )
>> V_67 ;
if ( ! F_41 ( V_9 ) )
return - V_53 ;
if ( F_49 ( V_68 , V_63 ) )
return - V_52 ;
if ( V_68 != F_42 ( V_9 ) )
return - V_56 ;
return 0 ;
default:
return - V_53 ;
}
}
static unsigned int F_50 ( void )
{
if ( ( ( F_51 ( V_69 ) & V_70 ) >> V_71 ) == 2 )
return 32 ;
else
return 16 ;
}
static unsigned int F_52 ( void )
{
return F_50 () + F_22 ( V_72 ) ;
}
static int F_53 ( T_3 T_4 * V_73 )
{
unsigned int V_24 ;
const T_3 V_74 = V_75 | V_37 | V_76 ;
const T_3 V_77 = V_75 | V_48 | V_76 ;
for ( V_24 = 0 ; V_24 < F_50 () ; V_24 ++ ) {
if ( F_47 ( ( V_77 | V_78 ) + V_24 ,
V_73 ) )
return - V_52 ;
V_73 ++ ;
}
for ( V_24 = 0 ; V_24 < F_22 ( V_72 ) ; V_24 ++ ) {
if ( F_47 ( V_74 | V_72 [ V_24 ] , V_73 ) )
return - V_52 ;
V_73 ++ ;
}
return F_52 () ;
}
static int F_54 ( const struct V_1 * V_2 , T_3 V_35 , void T_4 * V_51 )
{
T_1 V_79 = ( V_35 & V_80 ) ;
T_1 V_9 ;
if ( V_35 & ~ ( V_38 | V_36 | V_39
| ( ( 1 << V_49 ) - 1 ) ) )
return - V_53 ;
if ( V_79 < F_50 () ) {
if ( F_36 ( V_35 ) != 8 )
return - V_53 ;
return F_37 ( V_51 , & V_2 -> V_12 . V_81 . V_82 [ V_79 ] ,
V_35 ) ;
}
if ( F_36 ( V_35 ) != 4 )
return - V_53 ;
switch ( V_79 ) {
case V_83 :
return F_37 ( V_51 , & V_2 -> V_12 . V_81 . V_84 , V_35 ) ;
case V_85 :
return F_37 ( V_51 , & V_2 -> V_12 . V_81 . V_86 , V_35 ) ;
case V_87 :
return F_37 ( V_51 , & V_2 -> V_12 . V_81 . V_88 , V_35 ) ;
case V_89 :
return F_37 ( V_51 , & V_2 -> V_12 . V_81 . V_90 , V_35 ) ;
case V_91 :
V_9 = F_51 ( V_69 ) ;
return F_37 ( V_51 , & V_9 , V_35 ) ;
case V_92 :
V_9 = F_51 ( V_93 ) ;
return F_37 ( V_51 , & V_9 , V_35 ) ;
case V_94 :
V_9 = F_51 ( V_95 ) ;
return F_37 ( V_51 , & V_9 , V_35 ) ;
default:
return - V_53 ;
}
}
static int F_55 ( struct V_1 * V_2 , T_3 V_35 , const void T_4 * V_51 )
{
T_1 V_79 = ( V_35 & V_80 ) ;
T_1 V_9 ;
if ( V_35 & ~ ( V_38 | V_36 | V_39
| ( ( 1 << V_49 ) - 1 ) ) )
return - V_53 ;
if ( V_79 < F_50 () ) {
if ( F_36 ( V_35 ) != 8 )
return - V_53 ;
return F_34 ( & V_2 -> V_12 . V_81 . V_82 [ V_79 ] ,
V_51 , V_35 ) ;
}
if ( F_36 ( V_35 ) != 4 )
return - V_53 ;
switch ( V_79 ) {
case V_83 :
return F_34 ( & V_2 -> V_12 . V_81 . V_84 , V_51 , V_35 ) ;
case V_85 :
return F_34 ( & V_2 -> V_12 . V_81 . V_86 , V_51 , V_35 ) ;
case V_87 :
return F_34 ( & V_2 -> V_12 . V_81 . V_88 , V_51 , V_35 ) ;
case V_89 :
return F_34 ( & V_2 -> V_12 . V_81 . V_90 , V_51 , V_35 ) ;
case V_91 :
if ( F_34 ( & V_9 , V_51 , V_35 ) )
return - V_52 ;
if ( V_9 != F_51 ( V_69 ) )
return - V_56 ;
return 0 ;
case V_92 :
if ( F_34 ( & V_9 , V_51 , V_35 ) )
return - V_52 ;
if ( V_9 != F_51 ( V_93 ) )
return - V_56 ;
return 0 ;
case V_94 :
if ( F_34 ( & V_9 , V_51 , V_35 ) )
return - V_52 ;
if ( V_9 != F_51 ( V_95 ) )
return - V_56 ;
return 0 ;
default:
return - V_53 ;
}
}
static unsigned int F_52 ( void )
{
return 0 ;
}
static int F_53 ( T_3 T_4 * V_73 )
{
return 0 ;
}
static int F_54 ( const struct V_1 * V_2 , T_3 V_35 , void T_4 * V_51 )
{
return - V_53 ;
}
static int F_55 ( struct V_1 * V_2 , T_3 V_35 , const void T_4 * V_51 )
{
return - V_53 ;
}
int F_56 ( struct V_1 * V_2 , const struct V_96 * V_50 )
{
const struct V_7 * V_8 ;
void T_4 * V_51 = ( void T_4 * ) ( long ) V_50 -> V_97 ;
if ( ( V_50 -> V_35 & V_39 ) == V_98 )
return F_46 ( V_50 -> V_35 , V_51 ) ;
if ( ( V_50 -> V_35 & V_39 ) == V_76 )
return F_54 ( V_2 , V_50 -> V_35 , V_51 ) ;
V_8 = F_33 ( V_2 , V_50 -> V_35 ) ;
if ( ! V_8 )
return F_39 ( V_50 -> V_35 , V_51 ) ;
return F_37 ( V_51 , & V_2 -> V_12 . V_99 [ V_8 -> V_50 ] , V_50 -> V_35 ) ;
}
int F_57 ( struct V_1 * V_2 , const struct V_96 * V_50 )
{
const struct V_7 * V_8 ;
void T_4 * V_51 = ( void T_4 * ) ( long ) V_50 -> V_97 ;
if ( ( V_50 -> V_35 & V_39 ) == V_98 )
return F_48 ( V_50 -> V_35 , V_51 ) ;
if ( ( V_50 -> V_35 & V_39 ) == V_76 )
return F_55 ( V_2 , V_50 -> V_35 , V_51 ) ;
V_8 = F_33 ( V_2 , V_50 -> V_35 ) ;
if ( ! V_8 )
return F_40 ( V_50 -> V_35 , V_51 ) ;
return F_34 ( & V_2 -> V_12 . V_99 [ V_8 -> V_50 ] , V_51 , V_50 -> V_35 ) ;
}
static unsigned int F_58 ( void )
{
unsigned int V_24 , V_100 = 0 ;
for ( V_24 = 0 ; V_24 < V_59 ; V_24 ++ )
if ( F_41 ( V_24 ) )
V_100 ++ ;
return V_100 ;
}
static int F_59 ( T_3 T_4 * V_73 )
{
T_3 V_9 = V_75 | V_37 | V_98 ;
unsigned int V_24 ;
V_9 |= V_65 ;
for ( V_24 = 0 ; V_24 < V_59 ; V_24 ++ ) {
if ( ! F_41 ( V_24 ) )
continue;
if ( F_47 ( V_9 | V_24 , V_73 ) )
return - V_52 ;
V_73 ++ ;
}
return 0 ;
}
static T_3 F_60 ( const struct V_7 * V_50 )
{
T_3 V_9 = V_75 | ( 15 << V_49 ) ;
if ( V_50 -> V_26 ) {
V_9 |= V_48 ;
V_9 |= ( V_50 -> V_28 << V_46 ) ;
V_9 |= ( V_50 -> V_17 << V_45 ) ;
} else {
V_9 |= V_37 ;
V_9 |= ( V_50 -> V_28 << V_46 ) ;
V_9 |= ( V_50 -> V_29 << V_47 ) ;
V_9 |= ( V_50 -> V_17 << V_45 ) ;
V_9 |= ( V_50 -> V_27 << V_44 ) ;
}
return V_9 ;
}
static bool F_61 ( const struct V_7 * V_50 , T_3 T_4 * * V_101 )
{
if ( ! * V_101 )
return true ;
if ( F_47 ( F_60 ( V_50 ) , * V_101 ) )
return false ;
( * V_101 ) ++ ;
return true ;
}
static int F_62 ( struct V_1 * V_2 , T_3 T_4 * V_101 )
{
const struct V_7 * V_102 , * V_103 , * V_104 , * V_105 ;
unsigned int V_106 = 0 ;
T_2 V_22 ;
V_102 = F_18 ( V_2 -> V_12 . V_21 , & V_22 ) ;
V_104 = V_102 + V_22 ;
V_103 = V_30 ;
V_105 = V_30 + F_22 ( V_30 ) ;
F_24 ( V_102 == V_104 || V_103 == V_105 ) ;
while ( V_102 || V_103 ) {
int V_107 = F_63 ( V_102 , V_103 ) ;
if ( V_107 <= 0 ) {
if ( V_102 -> V_50 ) {
if ( ! F_61 ( V_102 , & V_101 ) )
return - V_52 ;
V_106 ++ ;
}
} else {
if ( V_103 -> V_50 ) {
if ( ! F_61 ( V_103 , & V_101 ) )
return - V_52 ;
V_106 ++ ;
}
}
if ( V_107 <= 0 && ++ V_102 == V_104 )
V_102 = NULL ;
if ( V_107 >= 0 && ++ V_103 == V_105 )
V_103 = NULL ;
}
return V_106 ;
}
unsigned long F_64 ( struct V_1 * V_2 )
{
return F_22 ( V_54 )
+ F_58 ()
+ F_52 ()
+ F_62 ( V_2 , ( T_3 T_4 * ) NULL ) ;
}
int F_65 ( struct V_1 * V_2 , T_3 T_4 * V_73 )
{
unsigned int V_24 ;
int V_55 ;
for ( V_24 = 0 ; V_24 < F_22 ( V_54 ) ; V_24 ++ ) {
if ( F_47 ( F_60 ( & V_54 [ V_24 ] ) , V_73 ) )
return - V_52 ;
V_73 ++ ;
}
V_55 = F_62 ( V_2 , V_73 ) ;
if ( V_55 < 0 )
return V_55 ;
V_73 += V_55 ;
V_55 = F_53 ( V_73 ) ;
if ( V_55 < 0 )
return V_55 ;
V_73 += V_55 ;
return F_59 ( V_73 ) ;
}
void F_66 ( void )
{
unsigned int V_24 ;
for ( V_24 = 1 ; V_24 < F_22 ( V_30 ) ; V_24 ++ )
F_24 ( F_63 ( & V_30 [ V_24 - 1 ] , & V_30 [ V_24 ] ) >= 0 ) ;
for ( V_24 = 0 ; V_24 < F_22 ( V_54 ) ; V_24 ++ )
V_54 [ V_24 ] . V_34 ( NULL , & V_54 [ V_24 ] ) ;
asm volatile("mrc p15, 1, %0, c0, c0, 1" : "=r" (cache_levels));
for ( V_24 = 0 ; V_24 < 7 ; V_24 ++ )
if ( ( ( V_60 >> ( V_24 * 3 ) ) & 7 ) == 0 )
break;
V_60 &= ( 1 << ( V_24 * 3 ) ) - 1 ;
}
void F_67 ( struct V_1 * V_2 )
{
T_2 V_22 ;
const struct V_7 * V_19 ;
memset ( V_2 -> V_12 . V_99 , 0x42 , sizeof( V_2 -> V_12 . V_99 ) ) ;
F_30 ( V_2 , V_30 , F_22 ( V_30 ) ) ;
V_19 = F_18 ( V_2 -> V_12 . V_21 , & V_22 ) ;
F_30 ( V_2 , V_19 , V_22 ) ;
for ( V_22 = 1 ; V_22 < V_108 ; V_22 ++ )
if ( V_2 -> V_12 . V_99 [ V_22 ] == 0x42424242 )
F_68 ( L_2 , V_22 ) ;
}

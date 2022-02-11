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
F_24 ( V_19 , V_8 -> V_14 , V_6 -> V_9 , * F_11 ( V_4 , V_6 -> V_12 ) ) ;
return true ;
}
static inline void F_25 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
T_2 * V_20 )
{
T_2 V_10 = * F_11 ( V_4 , V_6 -> V_12 ) ;
if ( V_6 -> V_15 ) {
V_10 &= 0xffffffffUL ;
V_10 |= ( ( * V_20 >> 32 ) << 32 ) ;
}
* V_20 = V_10 ;
V_4 -> V_16 . V_17 |= V_18 ;
}
static inline void F_26 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
T_2 * V_20 )
{
T_2 V_10 = * V_20 ;
if ( V_6 -> V_15 )
V_10 &= 0xffffffffUL ;
* F_11 ( V_4 , V_6 -> V_12 ) = V_10 ;
}
static inline bool F_27 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_21 )
{
T_2 * V_20 = & V_4 -> V_16 . V_22 . V_23 [ V_21 -> V_14 ] ;
if ( V_6 -> V_9 )
F_25 ( V_4 , V_6 , V_20 ) ;
else
F_26 ( V_4 , V_6 , V_20 ) ;
F_24 ( V_19 , V_21 -> V_14 , V_6 -> V_9 , * V_20 ) ;
return true ;
}
static int F_28 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_14 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_23 [ V_21 -> V_14 ] ;
if ( F_29 ( V_8 , V_25 , F_30 ( V_14 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_14 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_23 [ V_21 -> V_14 ] ;
if ( F_32 ( V_25 , V_8 , F_30 ( V_14 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static inline void F_33 ( struct V_3 * V_4 ,
const struct V_7 * V_21 )
{
V_4 -> V_16 . V_22 . V_23 [ V_21 -> V_14 ] = V_21 -> V_10 ;
}
static inline bool F_34 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_21 )
{
T_2 * V_20 = & V_4 -> V_16 . V_22 . V_28 [ V_21 -> V_14 ] ;
if ( V_6 -> V_9 )
F_25 ( V_4 , V_6 , V_20 ) ;
else
F_26 ( V_4 , V_6 , V_20 ) ;
F_24 ( V_19 , V_21 -> V_14 , V_6 -> V_9 , * V_20 ) ;
return true ;
}
static int F_35 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_14 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_28 [ V_21 -> V_14 ] ;
if ( F_29 ( V_8 , V_25 , F_30 ( V_14 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static int F_36 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_14 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_28 [ V_21 -> V_14 ] ;
if ( F_32 ( V_25 , V_8 , F_30 ( V_14 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static inline void F_37 ( struct V_3 * V_4 ,
const struct V_7 * V_21 )
{
V_4 -> V_16 . V_22 . V_28 [ V_21 -> V_14 ] = V_21 -> V_10 ;
}
static inline bool F_38 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_21 )
{
T_2 * V_20 = & V_4 -> V_16 . V_22 . V_29 [ V_21 -> V_14 ] ;
if ( V_6 -> V_9 )
F_25 ( V_4 , V_6 , V_20 ) ;
else
F_26 ( V_4 , V_6 , V_20 ) ;
F_24 ( V_19 , V_21 -> V_14 , V_6 -> V_9 ,
V_4 -> V_16 . V_22 . V_29 [ V_21 -> V_14 ] ) ;
return true ;
}
static int F_39 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_14 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_29 [ V_21 -> V_14 ] ;
if ( F_29 ( V_8 , V_25 , F_30 ( V_14 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static int F_40 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_14 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_29 [ V_21 -> V_14 ] ;
if ( F_32 ( V_25 , V_8 , F_30 ( V_14 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static inline void F_41 ( struct V_3 * V_4 ,
const struct V_7 * V_21 )
{
V_4 -> V_16 . V_22 . V_29 [ V_21 -> V_14 ] = V_21 -> V_10 ;
}
static inline bool F_42 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_21 )
{
T_2 * V_20 = & V_4 -> V_16 . V_22 . V_30 [ V_21 -> V_14 ] ;
if ( V_6 -> V_9 )
F_25 ( V_4 , V_6 , V_20 ) ;
else
F_26 ( V_4 , V_6 , V_20 ) ;
F_24 ( V_19 , V_21 -> V_14 , V_6 -> V_9 , * V_20 ) ;
return true ;
}
static int F_43 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_14 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_30 [ V_21 -> V_14 ] ;
if ( F_29 ( V_8 , V_25 , F_30 ( V_14 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static int F_44 ( struct V_3 * V_4 , const struct V_7 * V_21 ,
const struct V_24 * V_14 , void T_3 * V_25 )
{
T_4 * V_8 = & V_4 -> V_16 . V_22 . V_30 [ V_21 -> V_14 ] ;
if ( F_32 ( V_25 , V_8 , F_30 ( V_14 -> V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static inline void F_45 ( struct V_3 * V_4 ,
const struct V_7 * V_21 )
{
V_4 -> V_16 . V_22 . V_30 [ V_21 -> V_14 ] = V_21 -> V_10 ;
}
static void F_46 ( struct V_3 * V_4 , const struct V_7 * V_8 )
{
T_2 V_31 ;
asm volatile("mrs %0, amair_el1\n" : "=r" (amair));
F_12 ( V_4 , V_32 ) = V_31 ;
}
static void F_47 ( struct V_3 * V_4 , const struct V_7 * V_8 )
{
T_2 V_33 ;
V_33 = ( V_4 -> V_34 & 0x0f ) << F_48 ( 0 ) ;
V_33 |= ( ( V_4 -> V_34 >> 4 ) & 0xff ) << F_48 ( 1 ) ;
V_33 |= ( ( V_4 -> V_34 >> 12 ) & 0xff ) << F_48 ( 2 ) ;
F_12 ( V_4 , V_35 ) = ( 1ULL << 31 ) | V_33 ;
}
static bool F_49 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
return F_19 ( V_4 , V_6 ) ;
} else {
T_2 V_36 = F_50 ( V_37 ) ;
T_2 V_38 = F_50 ( V_39 ) ;
T_1 V_40 = ! ! ( ( V_38 >> 12 ) & 0xf ) ;
* F_11 ( V_4 , V_6 -> V_12 ) = ( ( ( ( V_36 >> 20 ) & 0xf ) << 28 ) |
( ( ( V_36 >> 12 ) & 0xf ) << 24 ) |
( ( ( V_36 >> 28 ) & 0xf ) << 20 ) |
( 6 << 16 ) | ( V_40 << 14 ) | ( V_40 << 12 ) ) ;
return true ;
}
}
static bool F_51 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( V_6 -> V_9 ) {
F_52 ( V_4 , V_8 -> V_14 ) = * F_11 ( V_4 , V_6 -> V_12 ) ;
V_4 -> V_16 . V_17 |= V_18 ;
} else {
* F_11 ( V_4 , V_6 -> V_12 ) = F_52 ( V_4 , V_8 -> V_14 ) ;
}
return true ;
}
static inline bool F_53 ( struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_21 )
{
T_2 * V_20 = & V_4 -> V_16 . V_22 . V_23 [ V_21 -> V_14 ] ;
if ( V_6 -> V_9 ) {
T_2 V_10 = * V_20 ;
V_10 &= 0xffffffffUL ;
V_10 |= * F_11 ( V_4 , V_6 -> V_12 ) << 32 ;
* V_20 = V_10 ;
V_4 -> V_16 . V_17 |= V_18 ;
} else {
* F_11 ( V_4 , V_6 -> V_12 ) = * V_20 >> 32 ;
}
F_24 ( V_19 , V_21 -> V_14 , V_6 -> V_9 , * V_20 ) ;
return true ;
}
void F_54 ( unsigned int V_41 ,
struct V_42 * V_43 )
{
V_44 [ V_41 ] = V_43 ;
}
static const struct V_7 * F_55 ( unsigned V_41 ,
bool V_45 ,
T_5 * V_46 )
{
struct V_42 * V_43 ;
V_43 = V_44 [ V_41 ] ;
if ( V_45 ) {
* V_46 = V_43 -> V_47 . V_46 ;
return V_43 -> V_47 . V_43 ;
} else {
* V_46 = V_43 -> V_48 . V_46 ;
return V_43 -> V_48 . V_43 ;
}
}
static const struct V_7 * F_56 ( const struct V_5 * V_49 ,
const struct V_7 V_43 [] ,
unsigned int V_46 )
{
unsigned int V_50 ;
for ( V_50 = 0 ; V_50 < V_46 ; V_50 ++ ) {
const struct V_7 * V_8 = & V_43 [ V_50 ] ;
if ( V_49 -> V_51 != V_8 -> V_51 )
continue;
if ( V_49 -> V_52 != V_8 -> V_52 )
continue;
if ( V_49 -> V_53 != V_8 -> V_53 )
continue;
if ( V_49 -> V_54 != V_8 -> V_54 )
continue;
if ( V_49 -> V_55 != V_8 -> V_55 )
continue;
return V_8 ;
}
return NULL ;
}
int F_57 ( struct V_3 * V_4 , struct V_56 * V_57 )
{
F_58 ( V_4 ) ;
return 1 ;
}
static int F_59 ( struct V_3 * V_4 ,
const struct V_5 * V_49 ,
const struct V_7 * V_43 ,
T_5 V_46 )
{
const struct V_7 * V_8 ;
if ( ! V_43 )
return - 1 ;
V_8 = F_56 ( V_49 , V_43 , V_46 ) ;
if ( V_8 ) {
F_10 ( ! V_8 -> V_58 ) ;
if ( F_60 ( V_8 -> V_58 ( V_4 , V_49 , V_8 ) ) ) {
F_61 ( V_4 , F_62 ( V_4 ) ) ;
}
return 0 ;
}
return - 1 ;
}
static void F_63 ( struct V_3 * V_4 ,
struct V_5 * V_49 )
{
T_6 V_59 = F_64 ( V_4 ) ;
int V_60 ;
switch( V_59 ) {
case V_61 :
case V_62 :
V_60 = 15 ;
break;
case V_63 :
case V_64 :
V_60 = 14 ;
break;
default:
F_65 ( ( V_60 = - 1 ) ) ;
}
F_66 ( L_1 ,
V_60 , * F_67 ( V_4 ) ) ;
F_68 ( V_49 ) ;
F_58 ( V_4 ) ;
}
static int F_69 ( struct V_3 * V_4 ,
const struct V_7 * V_65 ,
T_5 V_66 ,
const struct V_7 * V_67 ,
T_5 V_68 )
{
struct V_5 V_49 ;
T_1 V_69 = F_70 ( V_4 ) ;
int V_70 = ( V_69 >> 10 ) & 0xf ;
V_49 . V_13 = true ;
V_49 . V_15 = false ;
V_49 . V_54 = ( V_69 >> 1 ) & 0xf ;
V_49 . V_12 = ( V_69 >> 5 ) & 0xf ;
V_49 . V_9 = ( ( V_69 & 1 ) == 0 ) ;
V_49 . V_51 = 0 ;
V_49 . V_52 = ( V_69 >> 16 ) & 0xf ;
V_49 . V_55 = 0 ;
V_49 . V_53 = 0 ;
if ( V_49 . V_9 ) {
T_2 V_10 = * F_11 ( V_4 , V_49 . V_12 ) ;
V_10 &= 0xffffffff ;
V_10 |= * F_11 ( V_4 , V_70 ) << 32 ;
* F_11 ( V_4 , V_49 . V_12 ) = V_10 ;
}
if ( ! F_59 ( V_4 , & V_49 , V_67 , V_68 ) )
goto V_71;
if ( ! F_59 ( V_4 , & V_49 , V_65 , V_66 ) )
goto V_71;
F_63 ( V_4 , & V_49 ) ;
V_71:
if ( ! V_49 . V_9 ) {
T_2 V_10 = * F_11 ( V_4 , V_49 . V_12 ) ;
V_10 >>= 32 ;
* F_11 ( V_4 , V_70 ) = V_10 ;
}
return 1 ;
}
static int F_71 ( struct V_3 * V_4 ,
const struct V_7 * V_65 ,
T_5 V_66 ,
const struct V_7 * V_67 ,
T_5 V_68 )
{
struct V_5 V_49 ;
T_1 V_69 = F_70 ( V_4 ) ;
V_49 . V_13 = true ;
V_49 . V_15 = true ;
V_49 . V_54 = ( V_69 >> 1 ) & 0xf ;
V_49 . V_12 = ( V_69 >> 5 ) & 0xf ;
V_49 . V_9 = ( ( V_69 & 1 ) == 0 ) ;
V_49 . V_53 = ( V_69 >> 10 ) & 0xf ;
V_49 . V_51 = 0 ;
V_49 . V_52 = ( V_69 >> 14 ) & 0x7 ;
V_49 . V_55 = ( V_69 >> 17 ) & 0x7 ;
if ( ! F_59 ( V_4 , & V_49 , V_67 , V_68 ) )
return 1 ;
if ( ! F_59 ( V_4 , & V_49 , V_65 , V_66 ) )
return 1 ;
F_63 ( V_4 , & V_49 ) ;
return 1 ;
}
int F_72 ( struct V_3 * V_4 , struct V_56 * V_57 )
{
const struct V_7 * V_67 ;
T_5 V_46 ;
V_67 = F_55 ( V_4 -> V_16 . V_41 , false , & V_46 ) ;
return F_69 ( V_4 ,
V_72 , F_73 ( V_72 ) ,
V_67 , V_46 ) ;
}
int F_74 ( struct V_3 * V_4 , struct V_56 * V_57 )
{
const struct V_7 * V_67 ;
T_5 V_46 ;
V_67 = F_55 ( V_4 -> V_16 . V_41 , false , & V_46 ) ;
return F_71 ( V_4 ,
V_73 , F_73 ( V_73 ) ,
V_67 , V_46 ) ;
}
int F_75 ( struct V_3 * V_4 , struct V_56 * V_57 )
{
return F_69 ( V_4 ,
V_74 , F_73 ( V_74 ) ,
NULL , 0 ) ;
}
int F_76 ( struct V_3 * V_4 , struct V_56 * V_57 )
{
return F_71 ( V_4 ,
V_75 , F_73 ( V_75 ) ,
NULL , 0 ) ;
}
static int F_77 ( struct V_3 * V_4 ,
const struct V_5 * V_49 )
{
T_5 V_46 ;
const struct V_7 * V_43 , * V_8 ;
V_43 = F_55 ( V_4 -> V_16 . V_41 , true , & V_46 ) ;
V_8 = F_56 ( V_49 , V_43 , V_46 ) ;
if ( ! V_8 )
V_8 = F_56 ( V_49 , V_76 , F_73 ( V_76 ) ) ;
if ( F_60 ( V_8 ) ) {
F_10 ( ! V_8 -> V_58 ) ;
if ( F_60 ( V_8 -> V_58 ( V_4 , V_49 , V_8 ) ) ) {
F_61 ( V_4 , F_62 ( V_4 ) ) ;
return 1 ;
}
} else {
F_66 ( L_2 ,
* F_67 ( V_4 ) ) ;
F_68 ( V_49 ) ;
}
F_58 ( V_4 ) ;
return 1 ;
}
static void F_78 ( struct V_3 * V_4 ,
const struct V_7 * V_43 , T_5 V_46 )
{
unsigned long V_50 ;
for ( V_50 = 0 ; V_50 < V_46 ; V_50 ++ )
if ( V_43 [ V_50 ] . V_77 )
V_43 [ V_50 ] . V_77 ( V_4 , & V_43 [ V_50 ] ) ;
}
int F_79 ( struct V_3 * V_4 , struct V_56 * V_57 )
{
struct V_5 V_49 ;
unsigned long V_78 = F_70 ( V_4 ) ;
F_80 ( V_78 ) ;
V_49 . V_13 = false ;
V_49 . V_15 = false ;
V_49 . V_51 = ( V_78 >> 20 ) & 3 ;
V_49 . V_52 = ( V_78 >> 14 ) & 0x7 ;
V_49 . V_53 = ( V_78 >> 10 ) & 0xf ;
V_49 . V_54 = ( V_78 >> 1 ) & 0xf ;
V_49 . V_55 = ( V_78 >> 17 ) & 0x7 ;
V_49 . V_12 = ( V_78 >> 5 ) & 0x1f ;
V_49 . V_9 = ! ( V_78 & 1 ) ;
return F_77 ( V_4 , & V_49 ) ;
}
static bool F_81 ( T_2 V_26 , struct V_5 * V_49 )
{
switch ( V_26 & V_79 ) {
case V_80 :
if ( V_26 & ~ ( V_81 | V_79
| V_82
| V_83
| V_84
| V_85
| V_86
| V_87 ) )
return false ;
V_49 -> V_51 = ( ( V_26 & V_83 )
>> V_88 ) ;
V_49 -> V_52 = ( ( V_26 & V_84 )
>> V_89 ) ;
V_49 -> V_53 = ( ( V_26 & V_85 )
>> V_90 ) ;
V_49 -> V_54 = ( ( V_26 & V_86 )
>> V_91 ) ;
V_49 -> V_55 = ( ( V_26 & V_87 )
>> V_92 ) ;
return true ;
default:
return false ;
}
}
static const struct V_7 * F_82 ( struct V_3 * V_4 ,
T_2 V_26 )
{
T_5 V_46 ;
const struct V_7 * V_43 , * V_8 ;
struct V_5 V_49 ;
if ( ( V_26 & V_82 ) != V_93 )
return NULL ;
if ( ! F_81 ( V_26 , & V_49 ) )
return NULL ;
V_43 = F_55 ( V_4 -> V_16 . V_41 , true , & V_46 ) ;
V_8 = F_56 ( & V_49 , V_43 , V_46 ) ;
if ( ! V_8 )
V_8 = F_56 ( & V_49 , V_76 , F_73 ( V_76 ) ) ;
if ( V_8 && ! V_8 -> V_14 )
V_8 = NULL ;
return V_8 ;
}
static int F_83 ( T_2 * V_10 , const void T_3 * V_25 , T_2 V_26 )
{
if ( F_29 ( V_10 , V_25 , F_30 ( V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static int F_84 ( void T_3 * V_25 , const T_2 * V_10 , T_2 V_26 )
{
if ( F_32 ( V_25 , V_10 , F_30 ( V_26 ) ) != 0 )
return - V_27 ;
return 0 ;
}
static int F_85 ( T_2 V_26 , void T_3 * V_25 )
{
struct V_5 V_49 ;
const struct V_7 * V_8 ;
if ( ! F_81 ( V_26 , & V_49 ) )
return - V_94 ;
V_8 = F_56 ( & V_49 , V_95 , F_73 ( V_95 ) ) ;
if ( ! V_8 )
return - V_94 ;
return F_84 ( V_25 , & V_8 -> V_10 , V_26 ) ;
}
static int F_86 ( T_2 V_26 , void T_3 * V_25 )
{
struct V_5 V_49 ;
const struct V_7 * V_8 ;
int V_96 ;
T_2 V_10 = 0 ;
if ( ! F_81 ( V_26 , & V_49 ) )
return - V_94 ;
V_8 = F_56 ( & V_49 , V_95 , F_73 ( V_95 ) ) ;
if ( ! V_8 )
return - V_94 ;
V_96 = F_83 ( & V_10 , V_25 , V_26 ) ;
if ( V_96 )
return V_96 ;
if ( V_8 -> V_10 != V_10 )
return - V_97 ;
return 0 ;
}
static bool F_87 ( T_1 V_10 )
{
T_1 V_98 , V_99 ;
if ( V_10 >= V_100 )
return false ;
V_98 = ( V_10 >> 1 ) ;
V_99 = ( V_101 >> ( V_98 * 3 ) ) & 7 ;
switch ( V_99 ) {
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
static int F_88 ( T_2 V_26 , void T_3 * V_25 )
{
T_1 V_10 ;
T_1 T_3 * V_102 = V_25 ;
if ( V_26 & ~ ( V_81 | V_79 | V_82
| ( ( 1 << V_103 ) - 1 ) ) )
return - V_94 ;
switch ( V_26 & V_104 ) {
case V_105 :
if ( F_30 ( V_26 ) != 4 )
return - V_94 ;
V_10 = ( V_26 & V_106 )
>> V_107 ;
if ( ! F_87 ( V_10 ) )
return - V_94 ;
return F_89 ( F_1 ( V_10 ) , V_102 ) ;
default:
return - V_94 ;
}
}
static int F_90 ( T_2 V_26 , void T_3 * V_25 )
{
T_1 V_10 , V_108 ;
T_1 T_3 * V_102 = V_25 ;
if ( V_26 & ~ ( V_81 | V_79 | V_82
| ( ( 1 << V_103 ) - 1 ) ) )
return - V_94 ;
switch ( V_26 & V_104 ) {
case V_105 :
if ( F_30 ( V_26 ) != 4 )
return - V_94 ;
V_10 = ( V_26 & V_106 )
>> V_107 ;
if ( ! F_87 ( V_10 ) )
return - V_94 ;
if ( F_91 ( V_108 , V_102 ) )
return - V_27 ;
if ( V_108 != F_1 ( V_10 ) )
return - V_97 ;
return 0 ;
default:
return - V_94 ;
}
}
int F_92 ( struct V_3 * V_4 , const struct V_24 * V_14 )
{
const struct V_7 * V_8 ;
void T_3 * V_25 = ( void T_3 * ) ( unsigned long ) V_14 -> V_109 ;
if ( ( V_14 -> V_26 & V_82 ) == V_110 )
return F_88 ( V_14 -> V_26 , V_25 ) ;
if ( F_30 ( V_14 -> V_26 ) != sizeof( T_4 ) )
return - V_94 ;
V_8 = F_82 ( V_4 , V_14 -> V_26 ) ;
if ( ! V_8 )
return F_85 ( V_14 -> V_26 , V_25 ) ;
if ( V_8 -> F_91 )
return ( V_8 -> F_91 ) ( V_4 , V_8 , V_14 , V_25 ) ;
return F_84 ( V_25 , & F_12 ( V_4 , V_8 -> V_14 ) , V_14 -> V_26 ) ;
}
int F_93 ( struct V_3 * V_4 , const struct V_24 * V_14 )
{
const struct V_7 * V_8 ;
void T_3 * V_25 = ( void T_3 * ) ( unsigned long ) V_14 -> V_109 ;
if ( ( V_14 -> V_26 & V_82 ) == V_110 )
return F_90 ( V_14 -> V_26 , V_25 ) ;
if ( F_30 ( V_14 -> V_26 ) != sizeof( T_4 ) )
return - V_94 ;
V_8 = F_82 ( V_4 , V_14 -> V_26 ) ;
if ( ! V_8 )
return F_86 ( V_14 -> V_26 , V_25 ) ;
if ( V_8 -> V_111 )
return ( V_8 -> V_111 ) ( V_4 , V_8 , V_14 , V_25 ) ;
return F_83 ( & F_12 ( V_4 , V_8 -> V_14 ) , V_25 , V_14 -> V_26 ) ;
}
static unsigned int F_94 ( void )
{
unsigned int V_50 , V_112 = 0 ;
for ( V_50 = 0 ; V_50 < V_100 ; V_50 ++ )
if ( F_87 ( V_50 ) )
V_112 ++ ;
return V_112 ;
}
static int F_95 ( T_2 T_3 * V_113 )
{
T_2 V_10 = V_114 | V_115 | V_110 ;
unsigned int V_50 ;
V_10 |= V_105 ;
for ( V_50 = 0 ; V_50 < V_100 ; V_50 ++ ) {
if ( ! F_87 ( V_50 ) )
continue;
if ( F_89 ( V_10 | V_50 , V_113 ) )
return - V_27 ;
V_113 ++ ;
}
return 0 ;
}
static T_2 F_96 ( const struct V_7 * V_14 )
{
return ( V_114 | V_80 |
V_93 |
( V_14 -> V_51 << V_88 ) |
( V_14 -> V_52 << V_89 ) |
( V_14 -> V_53 << V_90 ) |
( V_14 -> V_54 << V_91 ) |
( V_14 -> V_55 << V_92 ) ) ;
}
static bool F_97 ( const struct V_7 * V_14 , T_2 T_3 * * V_116 )
{
if ( ! * V_116 )
return true ;
if ( F_89 ( F_96 ( V_14 ) , * V_116 ) )
return false ;
( * V_116 ) ++ ;
return true ;
}
static int F_98 ( struct V_3 * V_4 , T_2 T_3 * V_116 )
{
const struct V_7 * V_117 , * V_118 , * V_119 , * V_120 ;
unsigned int V_121 = 0 ;
T_5 V_46 ;
V_117 = F_55 ( V_4 -> V_16 . V_41 , true , & V_46 ) ;
V_119 = V_117 + V_46 ;
V_118 = V_76 ;
V_120 = V_76 + F_73 ( V_76 ) ;
F_10 ( V_117 == V_119 || V_118 == V_120 ) ;
while ( V_117 || V_118 ) {
int V_122 = F_99 ( V_117 , V_118 ) ;
if ( V_122 <= 0 ) {
if ( V_117 -> V_14 ) {
if ( ! F_97 ( V_117 , & V_116 ) )
return - V_27 ;
V_121 ++ ;
}
} else {
if ( V_118 -> V_14 ) {
if ( ! F_97 ( V_118 , & V_116 ) )
return - V_27 ;
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
unsigned long F_100 ( struct V_3 * V_4 )
{
return F_73 ( V_95 )
+ F_94 ()
+ F_98 ( V_4 , ( T_2 T_3 * ) NULL ) ;
}
int F_101 ( struct V_3 * V_4 , T_2 T_3 * V_113 )
{
unsigned int V_50 ;
int V_96 ;
for ( V_50 = 0 ; V_50 < F_73 ( V_95 ) ; V_50 ++ ) {
if ( F_89 ( F_96 ( & V_95 [ V_50 ] ) , V_113 ) )
return - V_27 ;
V_113 ++ ;
}
V_96 = F_98 ( V_4 , V_113 ) ;
if ( V_96 < 0 )
return V_96 ;
V_113 += V_96 ;
return F_95 ( V_113 ) ;
}
static int F_102 ( const struct V_7 * V_43 , unsigned int V_123 )
{
unsigned int V_50 ;
for ( V_50 = 1 ; V_50 < V_123 ; V_50 ++ ) {
if ( F_99 ( & V_43 [ V_50 - 1 ] , & V_43 [ V_50 ] ) >= 0 ) {
F_66 ( L_3 , V_43 , V_50 - 1 ) ;
return 1 ;
}
}
return 0 ;
}
void F_103 ( void )
{
unsigned int V_50 ;
struct V_7 V_124 ;
F_10 ( F_102 ( V_76 , F_73 ( V_76 ) ) ) ;
F_10 ( F_102 ( V_75 , F_73 ( V_75 ) ) ) ;
F_10 ( F_102 ( V_74 , F_73 ( V_74 ) ) ) ;
F_10 ( F_102 ( V_73 , F_73 ( V_73 ) ) ) ;
F_10 ( F_102 ( V_72 , F_73 ( V_72 ) ) ) ;
F_10 ( F_102 ( V_95 , F_73 ( V_95 ) ) ) ;
for ( V_50 = 0 ; V_50 < F_73 ( V_95 ) ; V_50 ++ )
V_95 [ V_50 ] . V_77 ( NULL , & V_95 [ V_50 ] ) ;
F_104 ( NULL , & V_124 ) ;
V_101 = V_124 . V_10 ;
for ( V_50 = 0 ; V_50 < 7 ; V_50 ++ )
if ( ( ( V_101 >> ( V_50 * 3 ) ) & 7 ) == 0 )
break;
V_101 &= ( 1 << ( V_50 * 3 ) ) - 1 ;
}
void F_105 ( struct V_3 * V_4 )
{
T_5 V_46 ;
const struct V_7 * V_43 ;
memset ( & V_4 -> V_16 . V_125 . V_126 , 0x42 , sizeof( V_4 -> V_16 . V_125 . V_126 ) ) ;
F_78 ( V_4 , V_76 , F_73 ( V_76 ) ) ;
V_43 = F_55 ( V_4 -> V_16 . V_41 , true , & V_46 ) ;
F_78 ( V_4 , V_43 , V_46 ) ;
for ( V_46 = 1 ; V_46 < V_127 ; V_46 ++ )
if ( F_12 ( V_4 , V_46 ) == 0x4242424242424242 )
F_106 ( L_4 , V_46 ) ;
}

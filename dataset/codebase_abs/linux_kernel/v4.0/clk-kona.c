static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( ( 1 << V_2 ) - 1 ) << V_1 ;
}
static inline T_1 F_2 ( T_1 V_3 , T_1 V_1 , T_1 V_2 )
{
return ( V_3 & F_1 ( V_1 , V_2 ) ) >> V_1 ;
}
static inline T_1 F_3 ( T_1 V_3 , T_1 V_1 , T_1 V_2 , T_1 V_4 )
{
T_1 V_5 = F_1 ( V_1 , V_2 ) ;
return ( V_3 & ~ V_5 ) | ( V_4 << V_1 ) ;
}
T_2 F_4 ( T_2 V_6 , unsigned long V_7 )
{
T_2 V_8 ;
V_8 = V_6 + ( ( T_2 ) V_7 >> 1 ) ;
( void ) F_5 ( V_8 , V_7 ) ;
return V_8 ;
}
static inline T_2 F_6 ( struct V_9 * div , T_1 V_10 )
{
return ( T_2 ) V_10 + ( ( T_2 ) 1 << div -> V_11 . V_12 . V_13 ) ;
}
T_2 F_7 ( struct V_9 * div , T_1 V_14 , T_1 V_15 )
{
T_2 V_16 ;
F_8 ( ! V_14 ) ;
F_8 ( V_15 >= V_17 ) ;
V_16 = ( T_2 ) V_14 * V_17 + V_15 ;
V_16 <<= div -> V_11 . V_12 . V_13 ;
return F_4 ( V_16 , V_17 ) ;
}
static inline T_2
F_9 ( struct V_9 * div )
{
if ( F_10 ( div ) )
return ( T_2 ) div -> V_11 . V_18 ;
return F_6 ( div , 0 ) ;
}
T_2 F_11 ( struct V_9 * div )
{
T_1 V_10 ;
if ( F_10 ( div ) )
return ( T_2 ) div -> V_11 . V_18 ;
V_10 = ( ( T_1 ) 1 << div -> V_11 . V_12 . V_2 ) - 1 ;
return F_6 ( div , V_10 ) ;
}
static inline T_1
F_12 ( struct V_9 * div , T_2 V_19 )
{
F_8 ( V_19 < F_9 ( div ) ) ;
F_8 ( V_19 > F_11 ( div ) ) ;
return ( T_1 ) ( V_19 - ( ( T_2 ) 1 << div -> V_11 . V_12 . V_13 ) ) ;
}
static inline T_2
F_13 ( struct V_9 * div , T_1 V_20 )
{
if ( F_10 ( div ) )
return ( T_2 ) V_20 ;
return ( T_2 ) V_20 << div -> V_11 . V_12 . V_13 ;
}
static inline T_1 F_14 ( struct V_21 * V_22 , T_1 V_23 )
{
return F_15 ( V_22 -> V_24 + V_23 ) ;
}
static inline void
F_16 ( struct V_21 * V_22 , T_1 V_23 , T_1 V_3 )
{
F_17 ( V_3 , V_22 -> V_24 + V_23 ) ;
}
static inline unsigned long F_18 ( struct V_21 * V_22 )
{
unsigned long V_25 ;
F_19 ( & V_22 -> V_26 , V_25 ) ;
return V_25 ;
}
static inline void F_20 ( struct V_21 * V_22 , unsigned long V_25 )
{
F_21 ( & V_22 -> V_26 , V_25 ) ;
}
static inline void F_22 ( struct V_21 * V_22 )
{
if ( V_22 -> V_27 ) {
F_23 ( L_1 , V_28 ,
V_22 -> V_29 ) ;
return;
}
V_22 -> V_27 = true ;
F_16 ( V_22 , 0 , V_30 | 1 ) ;
}
static inline void F_24 ( struct V_21 * V_22 )
{
if ( ! V_22 -> V_27 ) {
F_23 ( L_2 , V_28 ,
V_22 -> V_29 ) ;
return;
}
F_16 ( V_22 , 0 , V_30 ) ;
V_22 -> V_27 = false ;
}
static inline bool
F_25 ( struct V_21 * V_22 , T_1 V_23 , T_1 V_31 , bool V_32 )
{
unsigned int V_33 ;
T_1 V_34 = 1 << V_31 ;
for ( V_33 = 0 ; V_33 < V_35 ; V_33 ++ ) {
T_1 V_4 ;
bool V_36 ;
V_4 = F_14 ( V_22 , V_23 ) ;
V_36 = ( V_4 & V_34 ) != 0 ;
if ( V_36 == V_32 )
return true ;
F_26 ( 1 ) ;
}
F_27 ( L_3 , V_28 ,
V_22 -> V_29 , V_23 , V_31 , V_32 ? L_4 : L_5 ) ;
return false ;
}
static bool F_28 ( struct V_21 * V_22 , bool V_37 )
{
struct V_38 * V_39 = & V_22 -> V_40 . V_39 ;
T_1 V_41 ;
T_1 V_42 ;
T_1 V_5 ;
bool V_43 ;
if ( ! F_29 ( V_39 ) )
return true ;
V_41 = V_39 -> V_41 ;
V_42 = V_39 -> V_42 ;
V_43 = F_25 ( V_22 , V_41 , V_42 , false ) ;
if ( ! V_43 ) {
F_23 ( L_6 ,
V_28 , V_22 -> V_29 ) ;
return false ;
}
V_5 = ( T_1 ) 1 << V_42 ;
if ( V_37 )
V_5 |= 1 << V_39 -> V_44 ;
else
V_5 |= 1 << V_39 -> V_45 ;
F_16 ( V_22 , V_41 , V_5 ) ;
V_43 = F_25 ( V_22 , V_41 , V_42 , false ) ;
if ( ! V_43 )
F_23 ( L_7 ,
V_28 , V_22 -> V_29 ) ;
return V_43 ;
}
static bool F_30 ( struct V_21 * V_22 )
{
struct V_46 * V_47 = & V_22 -> V_40 . V_47 ;
T_1 V_41 ;
T_1 V_48 ;
bool V_43 ;
if ( ! F_31 ( V_47 ) )
return true ;
V_41 = V_47 -> V_41 ;
V_48 = V_47 -> V_31 ;
V_43 = F_25 ( V_22 , V_41 , V_48 , false ) ;
if ( ! V_43 ) {
F_23 ( L_8 ,
V_28 , V_22 -> V_29 ) ;
return false ;
}
F_16 ( V_22 , V_41 , ( T_1 ) 1 << V_48 ) ;
V_43 = F_25 ( V_22 , V_41 , V_48 , false ) ;
if ( ! V_43 )
F_23 ( L_9 ,
V_28 , V_22 -> V_29 ) ;
return V_43 ;
}
static bool F_32 ( struct V_21 * V_22 , struct V_49 * V_40 )
{
T_1 V_41 ;
T_1 V_5 ;
int V_50 ;
bool V_43 ;
if ( ! F_33 ( V_40 ) )
return true ;
if ( ! F_30 ( V_22 ) ) {
F_23 ( L_10 ,
V_28 , V_22 -> V_29 ) ;
return false ;
}
V_41 = V_40 -> V_41 ;
V_5 = ( T_1 ) 1 << V_40 -> V_31 ;
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ ) {
T_1 V_3 ;
V_3 = F_14 ( V_22 , V_41 ) ;
V_3 |= V_5 ;
F_16 ( V_22 , V_41 , V_3 ) ;
V_41 += sizeof( T_1 ) ;
}
V_43 = F_28 ( V_22 , true ) ;
if ( ! V_43 )
F_23 ( L_11 ,
V_28 , V_22 -> V_29 ) ;
return V_43 ;
}
static bool
F_34 ( struct V_21 * V_22 , struct V_52 * V_53 )
{
T_1 V_34 ;
T_1 V_3 ;
if ( ! F_35 ( V_53 ) )
return true ;
V_34 = 1 << V_53 -> V_54 ;
V_3 = F_14 ( V_22 , V_53 -> V_41 ) ;
return ( V_3 & V_34 ) != 0 ;
}
static bool
F_36 ( struct V_21 * V_22 , struct V_52 * V_53 )
{
long V_25 ;
bool V_43 ;
if ( ! F_35 ( V_53 ) )
return true ;
V_25 = F_18 ( V_22 ) ;
V_43 = F_34 ( V_22 , V_53 ) ;
F_20 ( V_22 , V_25 ) ;
return V_43 ;
}
static bool
F_37 ( struct V_21 * V_22 , struct V_52 * V_53 )
{
T_1 V_3 ;
T_1 V_5 ;
bool V_55 = false ;
F_8 ( ! F_35 ( V_53 ) ) ;
if ( ! F_38 ( V_53 ) )
return true ;
V_3 = F_14 ( V_22 , V_53 -> V_41 ) ;
if ( F_39 ( V_53 ) ) {
V_5 = ( T_1 ) 1 << V_53 -> V_56 ;
if ( F_40 ( V_53 ) )
V_3 |= V_5 ;
else
V_3 &= ~ V_5 ;
}
V_5 = ( T_1 ) 1 << V_53 -> V_57 ;
if ( F_40 ( V_53 ) && ( V_55 = F_41 ( V_53 ) ) &&
! F_42 ( V_53 ) )
V_3 |= V_5 ;
else
V_3 &= ~ V_5 ;
F_16 ( V_22 , V_53 -> V_41 , V_3 ) ;
if ( ! F_40 ( V_53 ) )
return true ;
return F_25 ( V_22 , V_53 -> V_41 , V_53 -> V_54 , V_55 ) ;
}
static bool F_43 ( struct V_21 * V_22 , struct V_52 * V_53 )
{
if ( ! F_35 ( V_53 ) )
return true ;
return F_37 ( V_22 , V_53 ) ;
}
static bool
F_44 ( struct V_21 * V_22 , struct V_52 * V_53 , bool V_47 )
{
bool V_43 ;
if ( ! F_35 ( V_53 ) || ! F_40 ( V_53 ) )
return true ;
if ( ! V_47 && F_42 ( V_53 ) ) {
F_27 ( L_12 ,
V_28 ) ;
return true ;
}
if ( V_47 == F_41 ( V_53 ) )
return true ;
F_45 ( V_53 ) ;
V_43 = F_37 ( V_22 , V_53 ) ;
if ( ! V_43 )
F_45 ( V_53 ) ;
return V_43 ;
}
static int F_46 ( struct V_21 * V_22 , const char * V_29 ,
struct V_52 * V_53 , bool V_47 )
{
unsigned long V_25 ;
bool V_58 ;
if ( ! F_35 ( V_53 ) || ! F_40 ( V_53 ) )
return 0 ;
if ( ! V_47 && F_42 ( V_53 ) )
return 0 ;
V_25 = F_18 ( V_22 ) ;
F_22 ( V_22 ) ;
V_58 = F_44 ( V_22 , V_53 , V_47 ) ;
F_24 ( V_22 ) ;
F_20 ( V_22 , V_25 ) ;
if ( V_58 )
return 0 ;
F_23 ( L_13 , V_28 ,
V_47 ? L_14 : L_15 , V_29 ) ;
return - V_59 ;
}
static bool F_47 ( struct V_21 * V_22 , struct V_60 * V_61 )
{
T_1 V_41 ;
T_1 V_3 ;
T_1 V_5 ;
if ( ! F_48 ( V_61 ) )
return true ;
V_41 = V_61 -> V_41 ;
V_5 = ( T_1 ) 1 << V_61 -> V_57 ;
V_5 |= ( T_1 ) 1 << V_61 -> V_62 ;
V_3 = F_14 ( V_22 , V_41 ) ;
V_3 |= V_5 ;
F_16 ( V_22 , V_41 , V_3 ) ;
return true ;
}
static bool F_49 ( struct V_21 * V_22 , struct V_63 * V_64 )
{
F_16 ( V_22 , V_64 -> V_41 , 1 << V_64 -> V_31 ) ;
return F_25 ( V_22 , V_64 -> V_41 , V_64 -> V_31 , false ) ;
}
static T_2 F_50 ( struct V_21 * V_22 , struct V_9 * div )
{
unsigned long V_25 ;
T_1 V_3 ;
T_1 V_10 ;
if ( F_10 ( div ) )
return ( T_2 ) div -> V_11 . V_18 ;
V_25 = F_18 ( V_22 ) ;
V_3 = F_14 ( V_22 , div -> V_11 . V_12 . V_41 ) ;
F_20 ( V_22 , V_25 ) ;
V_10 = F_2 ( V_3 , div -> V_11 . V_12 . V_1 , div -> V_11 . V_12 . V_2 ) ;
return F_6 ( div , V_10 ) ;
}
static int F_51 ( struct V_21 * V_22 , struct V_52 * V_53 ,
struct V_9 * div , struct V_63 * V_64 )
{
bool V_55 ;
T_1 V_10 ;
T_1 V_3 ;
int V_43 = 0 ;
F_8 ( F_10 ( div ) ) ;
if ( div -> V_11 . V_12 . V_19 == V_65 ) {
V_3 = F_14 ( V_22 , div -> V_11 . V_12 . V_41 ) ;
V_10 = F_2 ( V_3 , div -> V_11 . V_12 . V_1 ,
div -> V_11 . V_12 . V_2 ) ;
div -> V_11 . V_12 . V_19 = F_6 ( div , V_10 ) ;
return 0 ;
}
V_10 = F_12 ( div , div -> V_11 . V_12 . V_19 ) ;
V_55 = F_34 ( V_22 , V_53 ) ;
if ( ! V_55 && ! F_44 ( V_22 , V_53 , true ) ) {
V_43 = - V_66 ;
goto V_67;
}
V_3 = F_14 ( V_22 , div -> V_11 . V_12 . V_41 ) ;
V_3 = F_3 ( V_3 , div -> V_11 . V_12 . V_1 , div -> V_11 . V_12 . V_2 ,
V_10 ) ;
F_16 ( V_22 , div -> V_11 . V_12 . V_41 , V_3 ) ;
if ( ! F_49 ( V_22 , V_64 ) )
V_43 = - V_59 ;
if ( ! V_55 && ! F_44 ( V_22 , V_53 , false ) )
V_43 = V_43 ? V_43 : - V_66 ;
V_67:
return V_43 ;
}
static bool F_52 ( struct V_21 * V_22 , struct V_52 * V_53 ,
struct V_9 * div , struct V_63 * V_64 )
{
if ( ! F_53 ( div ) || F_10 ( div ) )
return true ;
return ! F_51 ( V_22 , V_53 , div , V_64 ) ;
}
static int F_54 ( struct V_21 * V_22 , struct V_52 * V_53 ,
struct V_9 * div , struct V_63 * V_64 ,
T_2 V_19 )
{
unsigned long V_25 ;
T_2 V_68 ;
int V_43 ;
F_8 ( F_10 ( div ) ) ;
V_68 = div -> V_11 . V_12 . V_19 ;
if ( V_68 == V_19 )
return 0 ;
div -> V_11 . V_12 . V_19 = V_19 ;
V_25 = F_18 ( V_22 ) ;
F_22 ( V_22 ) ;
V_43 = F_51 ( V_22 , V_53 , div , V_64 ) ;
F_24 ( V_22 ) ;
F_20 ( V_22 , V_25 ) ;
if ( V_43 )
div -> V_11 . V_12 . V_19 = V_68 ;
return V_43 ;
}
static unsigned long F_55 ( struct V_21 * V_22 ,
struct V_9 * div , struct V_9 * V_69 ,
unsigned long V_70 )
{
T_2 V_71 ;
T_2 V_19 ;
T_2 V_8 ;
if ( ! F_53 ( div ) )
return V_70 ;
if ( V_70 > ( unsigned long ) V_72 )
return 0 ;
if ( V_69 && F_53 ( V_69 ) ) {
T_2 V_73 ;
V_73 = F_13 ( V_69 , V_70 ) ;
V_73 = F_13 ( div , V_73 ) ;
V_19 = F_50 ( V_22 , V_69 ) ;
V_71 = F_4 ( V_73 ,
V_19 ) ;
} else {
V_71 = F_13 ( div , V_70 ) ;
}
V_19 = F_50 ( V_22 , div ) ;
V_8 = F_4 ( V_71 , V_19 ) ;
return ( unsigned long ) V_8 ;
}
static long F_56 ( struct V_21 * V_22 , struct V_9 * div ,
struct V_9 * V_69 ,
unsigned long V_20 , unsigned long V_70 ,
T_2 * V_19 )
{
T_2 V_71 ;
T_2 V_74 ;
T_2 V_75 ;
T_2 V_76 ;
T_2 V_8 ;
F_8 ( ! F_53 ( div ) ) ;
F_8 ( ! V_20 ) ;
F_8 ( V_70 > ( T_2 ) V_72 ) ;
if ( F_53 ( V_69 ) ) {
T_2 V_73 ;
T_2 V_77 ;
V_73 = F_13 ( V_69 , V_70 ) ;
V_73 = F_13 ( div , V_73 ) ;
V_77 = F_50 ( V_22 , V_69 ) ;
V_71 = F_4 ( V_73 ,
V_77 ) ;
} else {
V_71 = F_13 ( div , V_70 ) ;
}
if ( ! F_10 ( div ) ) {
V_76 = F_4 ( V_71 ,
V_20 ) ;
V_74 = F_9 ( div ) ;
V_75 = F_11 ( div ) ;
if ( V_76 > V_75 )
V_76 = V_75 ;
else if ( V_76 < V_74 )
V_76 = V_74 ;
} else {
V_76 = F_50 ( V_22 , div ) ;
}
V_8 = F_4 ( V_71 , V_76 ) ;
if ( V_19 )
* V_19 = V_76 ;
return ( long ) V_8 ;
}
static T_3 F_57 ( struct V_78 * V_79 , T_3 V_80 )
{
T_3 V_50 ;
F_8 ( V_79 -> V_81 > ( T_1 ) V_82 ) ;
for ( V_50 = 0 ; V_50 < V_79 -> V_81 ; V_50 ++ )
if ( V_79 -> V_80 [ V_50 ] == V_80 )
return V_50 ;
return V_83 ;
}
static T_3 F_58 ( struct V_21 * V_22 , struct V_78 * V_79 )
{
unsigned long V_25 ;
T_1 V_3 ;
T_1 V_80 ;
T_3 V_84 ;
if ( ! F_59 ( V_79 ) )
return 0 ;
V_25 = F_18 ( V_22 ) ;
V_3 = F_14 ( V_22 , V_79 -> V_41 ) ;
F_20 ( V_22 , V_25 ) ;
V_80 = F_2 ( V_3 , V_79 -> V_1 , V_79 -> V_2 ) ;
V_84 = F_57 ( V_79 , V_80 ) ;
if ( V_84 == V_83 )
F_23 ( L_16 ,
V_28 , V_80 , V_22 -> V_29 , V_79 -> V_41 ) ;
return V_84 ;
}
static int
F_60 ( struct V_21 * V_22 , struct V_52 * V_53 ,
struct V_78 * V_79 , struct V_63 * V_64 )
{
T_1 V_80 ;
T_1 V_3 ;
bool V_55 ;
int V_43 = 0 ;
F_8 ( ! F_59 ( V_79 ) ) ;
if ( V_79 -> V_85 == V_83 ) {
T_3 V_84 ;
V_3 = F_14 ( V_22 , V_79 -> V_41 ) ;
V_80 = F_2 ( V_3 , V_79 -> V_1 , V_79 -> V_2 ) ;
V_84 = F_57 ( V_79 , V_80 ) ;
if ( V_84 == V_83 )
return - V_86 ;
V_79 -> V_85 = V_84 ;
return 0 ;
}
F_8 ( ( T_1 ) V_79 -> V_85 >= V_79 -> V_81 ) ;
V_80 = V_79 -> V_80 [ V_79 -> V_85 ] ;
V_55 = F_34 ( V_22 , V_53 ) ;
if ( ! V_55 && ! F_44 ( V_22 , V_53 , true ) )
return - V_66 ;
V_3 = F_14 ( V_22 , V_79 -> V_41 ) ;
V_3 = F_3 ( V_3 , V_79 -> V_1 , V_79 -> V_2 , V_80 ) ;
F_16 ( V_22 , V_79 -> V_41 , V_3 ) ;
if ( ! F_49 ( V_22 , V_64 ) )
V_43 = - V_59 ;
if ( ! V_55 && ! F_44 ( V_22 , V_53 , false ) )
V_43 = V_43 ? V_43 : - V_66 ;
return V_43 ;
}
static bool F_61 ( struct V_21 * V_22 , struct V_52 * V_53 ,
struct V_78 * V_79 , struct V_63 * V_64 )
{
if ( ! F_59 ( V_79 ) )
return true ;
return ! F_60 ( V_22 , V_53 , V_79 , V_64 ) ;
}
static int F_62 ( struct V_21 * V_22 , struct V_52 * V_53 ,
struct V_78 * V_79 , struct V_63 * V_64 ,
T_3 V_84 )
{
unsigned long V_25 ;
T_3 V_68 ;
int V_43 ;
V_68 = V_79 -> V_85 ;
if ( V_68 == V_84 )
return 0 ;
V_79 -> V_85 = V_84 ;
V_25 = F_18 ( V_22 ) ;
F_22 ( V_22 ) ;
V_43 = F_60 ( V_22 , V_53 , V_79 , V_64 ) ;
F_24 ( V_22 ) ;
F_20 ( V_22 , V_25 ) ;
if ( V_43 )
V_79 -> V_85 = V_68 ;
return V_43 ;
}
static int F_63 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = F_64 ( V_88 ) ;
struct V_52 * V_53 = & V_90 -> V_11 . V_91 -> V_53 ;
return F_46 ( V_90 -> V_22 , V_90 -> V_92 . V_29 , V_53 , true ) ;
}
static void F_65 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = F_64 ( V_88 ) ;
struct V_52 * V_53 = & V_90 -> V_11 . V_91 -> V_53 ;
( void ) F_46 ( V_90 -> V_22 , V_90 -> V_92 . V_29 , V_53 , false ) ;
}
static int F_66 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = F_64 ( V_88 ) ;
struct V_52 * V_53 = & V_90 -> V_11 . V_91 -> V_53 ;
return F_36 ( V_90 -> V_22 , V_53 ) ? 1 : 0 ;
}
static unsigned long F_67 ( struct V_87 * V_88 ,
unsigned long V_70 )
{
struct V_89 * V_90 = F_64 ( V_88 ) ;
struct V_93 * V_94 = V_90 -> V_11 . V_91 ;
return F_55 ( V_90 -> V_22 , & V_94 -> div , & V_94 -> V_69 ,
V_70 ) ;
}
static long F_68 ( struct V_87 * V_88 , unsigned long V_20 ,
unsigned long * V_70 )
{
struct V_89 * V_90 = F_64 ( V_88 ) ;
struct V_9 * div = & V_90 -> V_11 . V_91 -> div ;
if ( ! F_53 ( div ) )
return F_69 ( V_88 -> V_95 ) ;
return F_56 ( V_90 -> V_22 , div , & V_90 -> V_11 . V_91 -> V_69 ,
V_20 ? V_20 : 1 , * V_70 , NULL ) ;
}
static long F_70 ( struct V_87 * V_88 , unsigned long V_20 ,
unsigned long V_96 ,
unsigned long V_97 ,
unsigned long * V_98 , struct V_87 * * V_99 )
{
struct V_89 * V_90 = F_64 ( V_88 ) ;
struct V_95 * V_95 = V_88 -> V_95 ;
struct V_95 * V_100 ;
unsigned long V_70 ;
unsigned long V_101 ;
unsigned long V_102 ;
T_1 V_81 ;
T_1 V_103 ;
F_71 ( V_90 -> V_92 . V_25 & V_104 ) ;
V_81 = ( T_1 ) V_90 -> V_92 . V_105 ;
if ( V_81 < 2 )
return F_68 ( V_88 , V_20 , V_98 ) ;
V_100 = F_72 ( V_95 ) ;
V_70 = F_69 ( V_100 ) ;
V_102 = F_68 ( V_88 , V_20 , & V_70 ) ;
V_101 = abs ( V_102 - V_20 ) ;
for ( V_103 = 0 ; V_103 < V_81 ; V_103 ++ ) {
struct V_95 * V_106 = F_73 ( V_95 , V_103 ) ;
unsigned long V_107 ;
unsigned long V_108 ;
F_8 ( ! V_106 ) ;
if ( V_106 == V_100 )
continue;
V_70 = F_69 ( V_106 ) ;
V_108 = F_68 ( V_88 , V_20 , & V_70 ) ;
V_107 = abs ( V_108 - V_20 ) ;
if ( V_107 < V_101 ) {
V_101 = V_107 ;
V_102 = V_108 ;
* V_99 = F_74 ( V_106 ) ;
* V_98 = V_70 ;
}
}
return V_102 ;
}
static int F_75 ( struct V_87 * V_88 , T_3 V_84 )
{
struct V_89 * V_90 = F_64 ( V_88 ) ;
struct V_93 * V_94 = V_90 -> V_11 . V_91 ;
struct V_78 * V_79 = & V_94 -> V_79 ;
struct V_63 * V_64 ;
int V_43 ;
F_8 ( V_84 >= V_79 -> V_81 ) ;
if ( ! F_59 ( V_79 ) )
return 0 ;
V_64 = F_76 ( & V_94 -> V_109 ) ? & V_94 -> V_109
: & V_94 -> V_64 ;
V_43 = F_62 ( V_90 -> V_22 , & V_94 -> V_53 , V_79 , V_64 , V_84 ) ;
if ( V_43 == - V_66 ) {
F_23 ( L_17 , V_28 ,
V_90 -> V_92 . V_29 ) ;
V_43 = - V_59 ;
} else if ( V_43 == - V_59 ) {
F_23 ( L_18 , V_28 ,
V_64 == & V_94 -> V_109 ? L_19 : L_20 ,
V_90 -> V_92 . V_29 ) ;
}
return V_43 ;
}
static T_3 F_77 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = F_64 ( V_88 ) ;
struct V_93 * V_94 = V_90 -> V_11 . V_91 ;
T_3 V_84 ;
V_84 = F_58 ( V_90 -> V_22 , & V_94 -> V_79 ) ;
return V_84 == V_83 ? 0 : V_84 ;
}
static int F_78 ( struct V_87 * V_88 , unsigned long V_20 ,
unsigned long V_70 )
{
struct V_89 * V_90 = F_64 ( V_88 ) ;
struct V_93 * V_94 = V_90 -> V_11 . V_91 ;
struct V_9 * div = & V_94 -> div ;
T_2 V_19 = 0 ;
int V_43 ;
if ( V_70 > ( unsigned long ) V_72 )
return - V_86 ;
if ( V_20 == F_69 ( V_88 -> V_95 ) )
return 0 ;
if ( ! F_53 ( div ) )
return V_20 == V_70 ? 0 : - V_86 ;
if ( F_10 ( & V_94 -> div ) )
return V_20 == V_70 ? 0 : - V_86 ;
( void ) F_56 ( V_90 -> V_22 , div , & V_94 -> V_69 ,
V_20 ? V_20 : 1 , V_70 , & V_19 ) ;
V_43 = F_54 ( V_90 -> V_22 , & V_94 -> V_53 , & V_94 -> div ,
& V_94 -> V_64 , V_19 ) ;
if ( V_43 == - V_66 ) {
F_23 ( L_17 , V_28 ,
V_90 -> V_92 . V_29 ) ;
V_43 = - V_59 ;
} else if ( V_43 == - V_59 ) {
F_23 ( L_21 , V_28 ,
V_90 -> V_92 . V_29 ) ;
}
return V_43 ;
}
static bool F_79 ( struct V_89 * V_90 )
{
struct V_21 * V_22 = V_90 -> V_22 ;
struct V_93 * V_91 = V_90 -> V_11 . V_91 ;
const char * V_29 = V_90 -> V_92 . V_29 ;
struct V_63 * V_64 ;
F_8 ( V_90 -> type != V_110 ) ;
if ( ! F_32 ( V_22 , & V_91 -> V_40 ) ) {
F_23 ( L_22 ,
V_28 , V_29 ) ;
return false ;
}
if ( ! F_43 ( V_22 , & V_91 -> V_53 ) ) {
F_23 ( L_23 , V_28 , V_29 ) ;
return false ;
}
if ( ! F_47 ( V_22 , & V_91 -> V_61 ) ) {
F_23 ( L_24 , V_28 , V_29 ) ;
return false ;
}
if ( ! F_52 ( V_22 , & V_91 -> V_53 , & V_91 -> div , & V_91 -> V_64 ) ) {
F_23 ( L_25 , V_28 ,
V_29 ) ;
return false ;
}
V_64 = F_76 ( & V_91 -> V_109 ) ? & V_91 -> V_109
: & V_91 -> V_64 ;
if ( ! F_52 ( V_22 , & V_91 -> V_53 , & V_91 -> V_69 , V_64 ) ) {
F_23 ( L_26 , V_28 ,
V_29 ) ;
return false ;
}
if ( ! F_61 ( V_22 , & V_91 -> V_53 , & V_91 -> V_79 , V_64 ) ) {
F_23 ( L_27 , V_28 ,
V_29 ) ;
return false ;
}
return true ;
}
static bool F_80 ( struct V_89 * V_90 )
{
switch ( V_90 -> type ) {
case V_110 :
return F_79 ( V_90 ) ;
default:
F_81 () ;
}
return - V_86 ;
}
bool T_4 F_82 ( struct V_21 * V_22 )
{
unsigned long V_25 ;
unsigned int V_103 ;
struct V_95 * * V_111 = V_22 -> V_112 . V_111 ;
bool V_58 = true ;
V_25 = F_18 ( V_22 ) ;
F_22 ( V_22 ) ;
for ( V_103 = 0 ; V_103 < V_22 -> V_112 . V_113 ; V_103 ++ ) {
struct V_89 * V_90 ;
if ( ! V_111 [ V_103 ] )
continue;
V_90 = F_64 ( F_74 ( V_111 [ V_103 ] ) ) ;
V_58 &= F_80 ( V_90 ) ;
}
F_24 ( V_22 ) ;
F_20 ( V_22 , V_25 ) ;
return V_58 ;
}

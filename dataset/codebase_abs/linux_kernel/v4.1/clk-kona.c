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
static inline T_2 F_4 ( struct V_6 * div , T_1 V_7 )
{
return ( T_2 ) V_7 + ( ( T_2 ) 1 << div -> V_8 . V_9 . V_10 ) ;
}
T_2 F_5 ( struct V_6 * div , T_1 V_11 , T_1 V_12 )
{
T_2 V_13 ;
F_6 ( ! V_11 ) ;
F_6 ( V_12 >= V_14 ) ;
V_13 = ( T_2 ) V_11 * V_14 + V_12 ;
V_13 <<= div -> V_8 . V_9 . V_10 ;
return F_7 ( V_13 , V_14 ) ;
}
static inline T_2
F_8 ( struct V_6 * div )
{
if ( F_9 ( div ) )
return ( T_2 ) div -> V_8 . V_15 ;
return F_4 ( div , 0 ) ;
}
T_2 F_10 ( struct V_6 * div )
{
T_1 V_7 ;
if ( F_9 ( div ) )
return ( T_2 ) div -> V_8 . V_15 ;
V_7 = ( ( T_1 ) 1 << div -> V_8 . V_9 . V_2 ) - 1 ;
return F_4 ( div , V_7 ) ;
}
static inline T_1
F_11 ( struct V_6 * div , T_2 V_16 )
{
F_6 ( V_16 < F_8 ( div ) ) ;
F_6 ( V_16 > F_10 ( div ) ) ;
return ( T_1 ) ( V_16 - ( ( T_2 ) 1 << div -> V_8 . V_9 . V_10 ) ) ;
}
static inline T_2
F_12 ( struct V_6 * div , T_1 V_17 )
{
if ( F_9 ( div ) )
return ( T_2 ) V_17 ;
return ( T_2 ) V_17 << div -> V_8 . V_9 . V_10 ;
}
static inline T_1 F_13 ( struct V_18 * V_19 , T_1 V_20 )
{
return F_14 ( V_19 -> V_21 + V_20 ) ;
}
static inline void
F_15 ( struct V_18 * V_19 , T_1 V_20 , T_1 V_3 )
{
F_16 ( V_3 , V_19 -> V_21 + V_20 ) ;
}
static inline unsigned long F_17 ( struct V_18 * V_19 )
{
unsigned long V_22 ;
F_18 ( & V_19 -> V_23 , V_22 ) ;
return V_22 ;
}
static inline void F_19 ( struct V_18 * V_19 , unsigned long V_22 )
{
F_20 ( & V_19 -> V_23 , V_22 ) ;
}
static inline void F_21 ( struct V_18 * V_19 )
{
if ( V_19 -> V_24 ) {
F_22 ( L_1 , V_25 ,
V_19 -> V_26 ) ;
return;
}
V_19 -> V_24 = true ;
F_15 ( V_19 , 0 , V_27 | 1 ) ;
}
static inline void F_23 ( struct V_18 * V_19 )
{
if ( ! V_19 -> V_24 ) {
F_22 ( L_2 , V_25 ,
V_19 -> V_26 ) ;
return;
}
F_15 ( V_19 , 0 , V_27 ) ;
V_19 -> V_24 = false ;
}
static inline bool
F_24 ( struct V_18 * V_19 , T_1 V_20 , T_1 V_28 , bool V_29 )
{
unsigned int V_30 ;
T_1 V_31 = 1 << V_28 ;
for ( V_30 = 0 ; V_30 < V_32 ; V_30 ++ ) {
T_1 V_4 ;
bool V_33 ;
V_4 = F_13 ( V_19 , V_20 ) ;
V_33 = ( V_4 & V_31 ) != 0 ;
if ( V_33 == V_29 )
return true ;
F_25 ( 1 ) ;
}
F_26 ( L_3 , V_25 ,
V_19 -> V_26 , V_20 , V_28 , V_29 ? L_4 : L_5 ) ;
return false ;
}
static bool F_27 ( struct V_18 * V_19 , bool V_34 )
{
struct V_35 * V_36 = & V_19 -> V_37 . V_36 ;
T_1 V_38 ;
T_1 V_39 ;
T_1 V_5 ;
bool V_40 ;
if ( ! F_28 ( V_36 ) )
return true ;
V_38 = V_36 -> V_38 ;
V_39 = V_36 -> V_39 ;
V_40 = F_24 ( V_19 , V_38 , V_39 , false ) ;
if ( ! V_40 ) {
F_22 ( L_6 ,
V_25 , V_19 -> V_26 ) ;
return false ;
}
V_5 = ( T_1 ) 1 << V_39 ;
if ( V_34 )
V_5 |= 1 << V_36 -> V_41 ;
else
V_5 |= 1 << V_36 -> V_42 ;
F_15 ( V_19 , V_38 , V_5 ) ;
V_40 = F_24 ( V_19 , V_38 , V_39 , false ) ;
if ( ! V_40 )
F_22 ( L_7 ,
V_25 , V_19 -> V_26 ) ;
return V_40 ;
}
static bool F_29 ( struct V_18 * V_19 )
{
struct V_43 * V_44 = & V_19 -> V_37 . V_44 ;
T_1 V_38 ;
T_1 V_45 ;
bool V_40 ;
if ( ! F_30 ( V_44 ) )
return true ;
V_38 = V_44 -> V_38 ;
V_45 = V_44 -> V_28 ;
V_40 = F_24 ( V_19 , V_38 , V_45 , false ) ;
if ( ! V_40 ) {
F_22 ( L_8 ,
V_25 , V_19 -> V_26 ) ;
return false ;
}
F_15 ( V_19 , V_38 , ( T_1 ) 1 << V_45 ) ;
V_40 = F_24 ( V_19 , V_38 , V_45 , false ) ;
if ( ! V_40 )
F_22 ( L_9 ,
V_25 , V_19 -> V_26 ) ;
return V_40 ;
}
static bool F_31 ( struct V_18 * V_19 , struct V_46 * V_37 )
{
T_1 V_38 ;
T_1 V_5 ;
int V_47 ;
bool V_40 ;
if ( ! F_32 ( V_37 ) )
return true ;
if ( ! F_29 ( V_19 ) ) {
F_22 ( L_10 ,
V_25 , V_19 -> V_26 ) ;
return false ;
}
V_38 = V_37 -> V_38 ;
V_5 = ( T_1 ) 1 << V_37 -> V_28 ;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
T_1 V_3 ;
V_3 = F_13 ( V_19 , V_38 ) ;
V_3 |= V_5 ;
F_15 ( V_19 , V_38 , V_3 ) ;
V_38 += sizeof( T_1 ) ;
}
V_40 = F_27 ( V_19 , true ) ;
if ( ! V_40 )
F_22 ( L_11 ,
V_25 , V_19 -> V_26 ) ;
return V_40 ;
}
static bool
F_33 ( struct V_18 * V_19 , struct V_49 * V_50 )
{
T_1 V_31 ;
T_1 V_3 ;
if ( ! F_34 ( V_50 ) )
return true ;
V_31 = 1 << V_50 -> V_51 ;
V_3 = F_13 ( V_19 , V_50 -> V_38 ) ;
return ( V_3 & V_31 ) != 0 ;
}
static bool
F_35 ( struct V_18 * V_19 , struct V_49 * V_50 )
{
long V_22 ;
bool V_40 ;
if ( ! F_34 ( V_50 ) )
return true ;
V_22 = F_17 ( V_19 ) ;
V_40 = F_33 ( V_19 , V_50 ) ;
F_19 ( V_19 , V_22 ) ;
return V_40 ;
}
static bool
F_36 ( struct V_18 * V_19 , struct V_49 * V_50 )
{
T_1 V_3 ;
T_1 V_5 ;
bool V_52 = false ;
F_6 ( ! F_34 ( V_50 ) ) ;
if ( ! F_37 ( V_50 ) )
return true ;
V_3 = F_13 ( V_19 , V_50 -> V_38 ) ;
if ( F_38 ( V_50 ) ) {
V_5 = ( T_1 ) 1 << V_50 -> V_53 ;
if ( F_39 ( V_50 ) )
V_3 |= V_5 ;
else
V_3 &= ~ V_5 ;
}
V_5 = ( T_1 ) 1 << V_50 -> V_54 ;
if ( F_39 ( V_50 ) && ( V_52 = F_40 ( V_50 ) ) &&
! F_41 ( V_50 ) )
V_3 |= V_5 ;
else
V_3 &= ~ V_5 ;
F_15 ( V_19 , V_50 -> V_38 , V_3 ) ;
if ( ! F_39 ( V_50 ) )
return true ;
return F_24 ( V_19 , V_50 -> V_38 , V_50 -> V_51 , V_52 ) ;
}
static bool F_42 ( struct V_18 * V_19 , struct V_49 * V_50 )
{
if ( ! F_34 ( V_50 ) )
return true ;
return F_36 ( V_19 , V_50 ) ;
}
static bool
F_43 ( struct V_18 * V_19 , struct V_49 * V_50 , bool V_44 )
{
bool V_40 ;
if ( ! F_34 ( V_50 ) || ! F_39 ( V_50 ) )
return true ;
if ( ! V_44 && F_41 ( V_50 ) ) {
F_26 ( L_12 ,
V_25 ) ;
return true ;
}
if ( V_44 == F_40 ( V_50 ) )
return true ;
F_44 ( V_50 ) ;
V_40 = F_36 ( V_19 , V_50 ) ;
if ( ! V_40 )
F_44 ( V_50 ) ;
return V_40 ;
}
static int F_45 ( struct V_18 * V_19 , const char * V_26 ,
struct V_49 * V_50 , bool V_44 )
{
unsigned long V_22 ;
bool V_55 ;
if ( ! F_34 ( V_50 ) || ! F_39 ( V_50 ) )
return 0 ;
if ( ! V_44 && F_41 ( V_50 ) )
return 0 ;
V_22 = F_17 ( V_19 ) ;
F_21 ( V_19 ) ;
V_55 = F_43 ( V_19 , V_50 , V_44 ) ;
F_23 ( V_19 ) ;
F_19 ( V_19 , V_22 ) ;
if ( V_55 )
return 0 ;
F_22 ( L_13 , V_25 ,
V_44 ? L_14 : L_15 , V_26 ) ;
return - V_56 ;
}
static bool F_46 ( struct V_18 * V_19 , struct V_57 * V_58 )
{
T_1 V_38 ;
T_1 V_3 ;
T_1 V_5 ;
if ( ! F_47 ( V_58 ) )
return true ;
V_38 = V_58 -> V_38 ;
V_5 = ( T_1 ) 1 << V_58 -> V_54 ;
V_5 |= ( T_1 ) 1 << V_58 -> V_59 ;
V_3 = F_13 ( V_19 , V_38 ) ;
V_3 |= V_5 ;
F_15 ( V_19 , V_38 , V_3 ) ;
return true ;
}
static bool F_48 ( struct V_18 * V_19 , struct V_60 * V_61 )
{
F_15 ( V_19 , V_61 -> V_38 , 1 << V_61 -> V_28 ) ;
return F_24 ( V_19 , V_61 -> V_38 , V_61 -> V_28 , false ) ;
}
static T_2 F_49 ( struct V_18 * V_19 , struct V_6 * div )
{
unsigned long V_22 ;
T_1 V_3 ;
T_1 V_7 ;
if ( F_9 ( div ) )
return ( T_2 ) div -> V_8 . V_15 ;
V_22 = F_17 ( V_19 ) ;
V_3 = F_13 ( V_19 , div -> V_8 . V_9 . V_38 ) ;
F_19 ( V_19 , V_22 ) ;
V_7 = F_2 ( V_3 , div -> V_8 . V_9 . V_1 , div -> V_8 . V_9 . V_2 ) ;
return F_4 ( div , V_7 ) ;
}
static int F_50 ( struct V_18 * V_19 , struct V_49 * V_50 ,
struct V_6 * div , struct V_60 * V_61 )
{
bool V_52 ;
T_1 V_7 ;
T_1 V_3 ;
int V_40 = 0 ;
F_6 ( F_9 ( div ) ) ;
if ( div -> V_8 . V_9 . V_16 == V_62 ) {
V_3 = F_13 ( V_19 , div -> V_8 . V_9 . V_38 ) ;
V_7 = F_2 ( V_3 , div -> V_8 . V_9 . V_1 ,
div -> V_8 . V_9 . V_2 ) ;
div -> V_8 . V_9 . V_16 = F_4 ( div , V_7 ) ;
return 0 ;
}
V_7 = F_11 ( div , div -> V_8 . V_9 . V_16 ) ;
V_52 = F_33 ( V_19 , V_50 ) ;
if ( ! V_52 && ! F_43 ( V_19 , V_50 , true ) ) {
V_40 = - V_63 ;
goto V_64;
}
V_3 = F_13 ( V_19 , div -> V_8 . V_9 . V_38 ) ;
V_3 = F_3 ( V_3 , div -> V_8 . V_9 . V_1 , div -> V_8 . V_9 . V_2 ,
V_7 ) ;
F_15 ( V_19 , div -> V_8 . V_9 . V_38 , V_3 ) ;
if ( ! F_48 ( V_19 , V_61 ) )
V_40 = - V_56 ;
if ( ! V_52 && ! F_43 ( V_19 , V_50 , false ) )
V_40 = V_40 ? V_40 : - V_63 ;
V_64:
return V_40 ;
}
static bool F_51 ( struct V_18 * V_19 , struct V_49 * V_50 ,
struct V_6 * div , struct V_60 * V_61 )
{
if ( ! F_52 ( div ) || F_9 ( div ) )
return true ;
return ! F_50 ( V_19 , V_50 , div , V_61 ) ;
}
static int F_53 ( struct V_18 * V_19 , struct V_49 * V_50 ,
struct V_6 * div , struct V_60 * V_61 ,
T_2 V_16 )
{
unsigned long V_22 ;
T_2 V_65 ;
int V_40 ;
F_6 ( F_9 ( div ) ) ;
V_65 = div -> V_8 . V_9 . V_16 ;
if ( V_65 == V_16 )
return 0 ;
div -> V_8 . V_9 . V_16 = V_16 ;
V_22 = F_17 ( V_19 ) ;
F_21 ( V_19 ) ;
V_40 = F_50 ( V_19 , V_50 , div , V_61 ) ;
F_23 ( V_19 ) ;
F_19 ( V_19 , V_22 ) ;
if ( V_40 )
div -> V_8 . V_9 . V_16 = V_65 ;
return V_40 ;
}
static unsigned long F_54 ( struct V_18 * V_19 ,
struct V_6 * div , struct V_6 * V_66 ,
unsigned long V_67 )
{
T_2 V_68 ;
T_2 V_16 ;
T_2 V_69 ;
if ( ! F_52 ( div ) )
return V_67 ;
if ( V_67 > ( unsigned long ) V_70 )
return 0 ;
if ( V_66 && F_52 ( V_66 ) ) {
T_2 V_71 ;
V_71 = F_12 ( V_66 , V_67 ) ;
V_71 = F_12 ( div , V_71 ) ;
V_16 = F_49 ( V_19 , V_66 ) ;
V_68 = F_7 ( V_71 ,
V_16 ) ;
} else {
V_68 = F_12 ( div , V_67 ) ;
}
V_16 = F_49 ( V_19 , div ) ;
V_69 = F_7 ( V_68 , V_16 ) ;
return ( unsigned long ) V_69 ;
}
static long F_55 ( struct V_18 * V_19 , struct V_6 * div ,
struct V_6 * V_66 ,
unsigned long V_17 , unsigned long V_67 ,
T_2 * V_16 )
{
T_2 V_68 ;
T_2 V_72 ;
T_2 V_73 ;
T_2 V_74 ;
T_2 V_69 ;
F_6 ( ! F_52 ( div ) ) ;
F_6 ( ! V_17 ) ;
F_6 ( V_67 > ( T_2 ) V_70 ) ;
if ( F_52 ( V_66 ) ) {
T_2 V_71 ;
T_2 V_75 ;
V_71 = F_12 ( V_66 , V_67 ) ;
V_71 = F_12 ( div , V_71 ) ;
V_75 = F_49 ( V_19 , V_66 ) ;
V_68 = F_7 ( V_71 ,
V_75 ) ;
} else {
V_68 = F_12 ( div , V_67 ) ;
}
if ( ! F_9 ( div ) ) {
V_74 = F_7 ( V_68 ,
V_17 ) ;
V_72 = F_8 ( div ) ;
V_73 = F_10 ( div ) ;
if ( V_74 > V_73 )
V_74 = V_73 ;
else if ( V_74 < V_72 )
V_74 = V_72 ;
} else {
V_74 = F_49 ( V_19 , div ) ;
}
V_69 = F_7 ( V_68 , V_74 ) ;
if ( V_16 )
* V_16 = V_74 ;
return ( long ) V_69 ;
}
static T_3 F_56 ( struct V_76 * V_77 , T_3 V_78 )
{
T_3 V_47 ;
F_6 ( V_77 -> V_79 > ( T_1 ) V_80 ) ;
for ( V_47 = 0 ; V_47 < V_77 -> V_79 ; V_47 ++ )
if ( V_77 -> V_78 [ V_47 ] == V_78 )
return V_47 ;
return V_81 ;
}
static T_3 F_57 ( struct V_18 * V_19 , struct V_76 * V_77 )
{
unsigned long V_22 ;
T_1 V_3 ;
T_1 V_78 ;
T_3 V_82 ;
if ( ! F_58 ( V_77 ) )
return 0 ;
V_22 = F_17 ( V_19 ) ;
V_3 = F_13 ( V_19 , V_77 -> V_38 ) ;
F_19 ( V_19 , V_22 ) ;
V_78 = F_2 ( V_3 , V_77 -> V_1 , V_77 -> V_2 ) ;
V_82 = F_56 ( V_77 , V_78 ) ;
if ( V_82 == V_81 )
F_22 ( L_16 ,
V_25 , V_78 , V_19 -> V_26 , V_77 -> V_38 ) ;
return V_82 ;
}
static int
F_59 ( struct V_18 * V_19 , struct V_49 * V_50 ,
struct V_76 * V_77 , struct V_60 * V_61 )
{
T_1 V_78 ;
T_1 V_3 ;
bool V_52 ;
int V_40 = 0 ;
F_6 ( ! F_58 ( V_77 ) ) ;
if ( V_77 -> V_83 == V_81 ) {
T_3 V_82 ;
V_3 = F_13 ( V_19 , V_77 -> V_38 ) ;
V_78 = F_2 ( V_3 , V_77 -> V_1 , V_77 -> V_2 ) ;
V_82 = F_56 ( V_77 , V_78 ) ;
if ( V_82 == V_81 )
return - V_84 ;
V_77 -> V_83 = V_82 ;
return 0 ;
}
F_6 ( ( T_1 ) V_77 -> V_83 >= V_77 -> V_79 ) ;
V_78 = V_77 -> V_78 [ V_77 -> V_83 ] ;
V_52 = F_33 ( V_19 , V_50 ) ;
if ( ! V_52 && ! F_43 ( V_19 , V_50 , true ) )
return - V_63 ;
V_3 = F_13 ( V_19 , V_77 -> V_38 ) ;
V_3 = F_3 ( V_3 , V_77 -> V_1 , V_77 -> V_2 , V_78 ) ;
F_15 ( V_19 , V_77 -> V_38 , V_3 ) ;
if ( ! F_48 ( V_19 , V_61 ) )
V_40 = - V_56 ;
if ( ! V_52 && ! F_43 ( V_19 , V_50 , false ) )
V_40 = V_40 ? V_40 : - V_63 ;
return V_40 ;
}
static bool F_60 ( struct V_18 * V_19 , struct V_49 * V_50 ,
struct V_76 * V_77 , struct V_60 * V_61 )
{
if ( ! F_58 ( V_77 ) )
return true ;
return ! F_59 ( V_19 , V_50 , V_77 , V_61 ) ;
}
static int F_61 ( struct V_18 * V_19 , struct V_49 * V_50 ,
struct V_76 * V_77 , struct V_60 * V_61 ,
T_3 V_82 )
{
unsigned long V_22 ;
T_3 V_65 ;
int V_40 ;
V_65 = V_77 -> V_83 ;
if ( V_65 == V_82 )
return 0 ;
V_77 -> V_83 = V_82 ;
V_22 = F_17 ( V_19 ) ;
F_21 ( V_19 ) ;
V_40 = F_59 ( V_19 , V_50 , V_77 , V_61 ) ;
F_23 ( V_19 ) ;
F_19 ( V_19 , V_22 ) ;
if ( V_40 )
V_77 -> V_83 = V_65 ;
return V_40 ;
}
static int F_62 ( struct V_85 * V_86 )
{
struct V_87 * V_88 = F_63 ( V_86 ) ;
struct V_49 * V_50 = & V_88 -> V_8 . V_89 -> V_50 ;
return F_45 ( V_88 -> V_19 , V_88 -> V_90 . V_26 , V_50 , true ) ;
}
static void F_64 ( struct V_85 * V_86 )
{
struct V_87 * V_88 = F_63 ( V_86 ) ;
struct V_49 * V_50 = & V_88 -> V_8 . V_89 -> V_50 ;
( void ) F_45 ( V_88 -> V_19 , V_88 -> V_90 . V_26 , V_50 , false ) ;
}
static int F_65 ( struct V_85 * V_86 )
{
struct V_87 * V_88 = F_63 ( V_86 ) ;
struct V_49 * V_50 = & V_88 -> V_8 . V_89 -> V_50 ;
return F_35 ( V_88 -> V_19 , V_50 ) ? 1 : 0 ;
}
static unsigned long F_66 ( struct V_85 * V_86 ,
unsigned long V_67 )
{
struct V_87 * V_88 = F_63 ( V_86 ) ;
struct V_91 * V_92 = V_88 -> V_8 . V_89 ;
return F_54 ( V_88 -> V_19 , & V_92 -> div , & V_92 -> V_66 ,
V_67 ) ;
}
static long F_67 ( struct V_85 * V_86 , unsigned long V_17 ,
unsigned long * V_67 )
{
struct V_87 * V_88 = F_63 ( V_86 ) ;
struct V_6 * div = & V_88 -> V_8 . V_89 -> div ;
if ( ! F_52 ( div ) )
return F_68 ( V_86 -> V_93 ) ;
return F_55 ( V_88 -> V_19 , div , & V_88 -> V_8 . V_89 -> V_66 ,
V_17 ? V_17 : 1 , * V_67 , NULL ) ;
}
static long F_69 ( struct V_85 * V_86 , unsigned long V_17 ,
unsigned long V_94 ,
unsigned long V_95 ,
unsigned long * V_96 , struct V_85 * * V_97 )
{
struct V_87 * V_88 = F_63 ( V_86 ) ;
struct V_93 * V_93 = V_86 -> V_93 ;
struct V_93 * V_98 ;
unsigned long V_67 ;
unsigned long V_99 ;
unsigned long V_100 ;
T_1 V_79 ;
T_1 V_101 ;
F_70 ( V_88 -> V_90 . V_22 & V_102 ) ;
V_79 = ( T_1 ) V_88 -> V_90 . V_103 ;
if ( V_79 < 2 )
return F_67 ( V_86 , V_17 , V_96 ) ;
V_98 = F_71 ( V_93 ) ;
V_67 = F_68 ( V_98 ) ;
V_100 = F_67 ( V_86 , V_17 , & V_67 ) ;
V_99 = abs ( V_100 - V_17 ) ;
for ( V_101 = 0 ; V_101 < V_79 ; V_101 ++ ) {
struct V_93 * V_104 = F_72 ( V_93 , V_101 ) ;
unsigned long V_105 ;
unsigned long V_106 ;
F_6 ( ! V_104 ) ;
if ( V_104 == V_98 )
continue;
V_67 = F_68 ( V_104 ) ;
V_106 = F_67 ( V_86 , V_17 , & V_67 ) ;
V_105 = abs ( V_106 - V_17 ) ;
if ( V_105 < V_99 ) {
V_99 = V_105 ;
V_100 = V_106 ;
* V_97 = F_73 ( V_104 ) ;
* V_96 = V_67 ;
}
}
return V_100 ;
}
static int F_74 ( struct V_85 * V_86 , T_3 V_82 )
{
struct V_87 * V_88 = F_63 ( V_86 ) ;
struct V_91 * V_92 = V_88 -> V_8 . V_89 ;
struct V_76 * V_77 = & V_92 -> V_77 ;
struct V_60 * V_61 ;
int V_40 ;
F_6 ( V_82 >= V_77 -> V_79 ) ;
if ( ! F_58 ( V_77 ) )
return 0 ;
V_61 = F_75 ( & V_92 -> V_107 ) ? & V_92 -> V_107
: & V_92 -> V_61 ;
V_40 = F_61 ( V_88 -> V_19 , & V_92 -> V_50 , V_77 , V_61 , V_82 ) ;
if ( V_40 == - V_63 ) {
F_22 ( L_17 , V_25 ,
V_88 -> V_90 . V_26 ) ;
V_40 = - V_56 ;
} else if ( V_40 == - V_56 ) {
F_22 ( L_18 , V_25 ,
V_61 == & V_92 -> V_107 ? L_19 : L_20 ,
V_88 -> V_90 . V_26 ) ;
}
return V_40 ;
}
static T_3 F_76 ( struct V_85 * V_86 )
{
struct V_87 * V_88 = F_63 ( V_86 ) ;
struct V_91 * V_92 = V_88 -> V_8 . V_89 ;
T_3 V_82 ;
V_82 = F_57 ( V_88 -> V_19 , & V_92 -> V_77 ) ;
return V_82 == V_81 ? 0 : V_82 ;
}
static int F_77 ( struct V_85 * V_86 , unsigned long V_17 ,
unsigned long V_67 )
{
struct V_87 * V_88 = F_63 ( V_86 ) ;
struct V_91 * V_92 = V_88 -> V_8 . V_89 ;
struct V_6 * div = & V_92 -> div ;
T_2 V_16 = 0 ;
int V_40 ;
if ( V_67 > ( unsigned long ) V_70 )
return - V_84 ;
if ( V_17 == F_68 ( V_86 -> V_93 ) )
return 0 ;
if ( ! F_52 ( div ) )
return V_17 == V_67 ? 0 : - V_84 ;
if ( F_9 ( & V_92 -> div ) )
return V_17 == V_67 ? 0 : - V_84 ;
( void ) F_55 ( V_88 -> V_19 , div , & V_92 -> V_66 ,
V_17 ? V_17 : 1 , V_67 , & V_16 ) ;
V_40 = F_53 ( V_88 -> V_19 , & V_92 -> V_50 , & V_92 -> div ,
& V_92 -> V_61 , V_16 ) ;
if ( V_40 == - V_63 ) {
F_22 ( L_17 , V_25 ,
V_88 -> V_90 . V_26 ) ;
V_40 = - V_56 ;
} else if ( V_40 == - V_56 ) {
F_22 ( L_21 , V_25 ,
V_88 -> V_90 . V_26 ) ;
}
return V_40 ;
}
static bool F_78 ( struct V_87 * V_88 )
{
struct V_18 * V_19 = V_88 -> V_19 ;
struct V_91 * V_89 = V_88 -> V_8 . V_89 ;
const char * V_26 = V_88 -> V_90 . V_26 ;
struct V_60 * V_61 ;
F_6 ( V_88 -> type != V_108 ) ;
if ( ! F_31 ( V_19 , & V_89 -> V_37 ) ) {
F_22 ( L_22 ,
V_25 , V_26 ) ;
return false ;
}
if ( ! F_42 ( V_19 , & V_89 -> V_50 ) ) {
F_22 ( L_23 , V_25 , V_26 ) ;
return false ;
}
if ( ! F_46 ( V_19 , & V_89 -> V_58 ) ) {
F_22 ( L_24 , V_25 , V_26 ) ;
return false ;
}
if ( ! F_51 ( V_19 , & V_89 -> V_50 , & V_89 -> div , & V_89 -> V_61 ) ) {
F_22 ( L_25 , V_25 ,
V_26 ) ;
return false ;
}
V_61 = F_75 ( & V_89 -> V_107 ) ? & V_89 -> V_107
: & V_89 -> V_61 ;
if ( ! F_51 ( V_19 , & V_89 -> V_50 , & V_89 -> V_66 , V_61 ) ) {
F_22 ( L_26 , V_25 ,
V_26 ) ;
return false ;
}
if ( ! F_60 ( V_19 , & V_89 -> V_50 , & V_89 -> V_77 , V_61 ) ) {
F_22 ( L_27 , V_25 ,
V_26 ) ;
return false ;
}
return true ;
}
static bool F_79 ( struct V_87 * V_88 )
{
switch ( V_88 -> type ) {
case V_108 :
return F_78 ( V_88 ) ;
default:
F_80 () ;
}
return - V_84 ;
}
bool T_4 F_81 ( struct V_18 * V_19 )
{
unsigned long V_22 ;
unsigned int V_101 ;
struct V_93 * * V_109 = V_19 -> V_110 . V_109 ;
bool V_55 = true ;
V_22 = F_17 ( V_19 ) ;
F_21 ( V_19 ) ;
for ( V_101 = 0 ; V_101 < V_19 -> V_110 . V_111 ; V_101 ++ ) {
struct V_87 * V_88 ;
if ( ! V_109 [ V_101 ] )
continue;
V_88 = F_63 ( F_73 ( V_109 [ V_101 ] ) ) ;
V_55 &= F_79 ( V_88 ) ;
}
F_23 ( V_19 ) ;
F_19 ( V_19 , V_22 ) ;
return V_55 ;
}

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
return false ;
}
static bool
F_27 ( struct V_21 * V_22 , struct V_37 * V_38 )
{
T_1 V_34 ;
T_1 V_3 ;
if ( ! F_28 ( V_38 ) )
return true ;
V_34 = 1 << V_38 -> V_39 ;
V_3 = F_14 ( V_22 , V_38 -> V_40 ) ;
return ( V_3 & V_34 ) != 0 ;
}
static bool
F_29 ( struct V_21 * V_22 , struct V_37 * V_38 )
{
long V_25 ;
bool V_41 ;
if ( ! F_28 ( V_38 ) )
return true ;
V_25 = F_18 ( V_22 ) ;
V_41 = F_27 ( V_22 , V_38 ) ;
F_20 ( V_22 , V_25 ) ;
return V_41 ;
}
static bool
F_30 ( struct V_21 * V_22 , struct V_37 * V_38 )
{
T_1 V_3 ;
T_1 V_5 ;
bool V_42 = false ;
F_8 ( ! F_28 ( V_38 ) ) ;
if ( ! F_31 ( V_38 ) )
return true ;
V_3 = F_14 ( V_22 , V_38 -> V_40 ) ;
if ( F_32 ( V_38 ) ) {
V_5 = ( T_1 ) 1 << V_38 -> V_43 ;
if ( F_33 ( V_38 ) )
V_3 |= V_5 ;
else
V_3 &= ~ V_5 ;
}
V_5 = ( T_1 ) 1 << V_38 -> V_44 ;
if ( F_33 ( V_38 ) && ( V_42 = F_34 ( V_38 ) ) &&
! F_35 ( V_38 ) )
V_3 |= V_5 ;
else
V_3 &= ~ V_5 ;
F_16 ( V_22 , V_38 -> V_40 , V_3 ) ;
if ( ! F_33 ( V_38 ) )
return true ;
return F_25 ( V_22 , V_38 -> V_40 , V_38 -> V_39 , V_42 ) ;
}
static bool F_36 ( struct V_21 * V_22 , struct V_37 * V_38 )
{
if ( ! F_28 ( V_38 ) )
return true ;
return F_30 ( V_22 , V_38 ) ;
}
static bool
F_37 ( struct V_21 * V_22 , struct V_37 * V_38 , bool V_45 )
{
bool V_41 ;
if ( ! F_28 ( V_38 ) || ! F_33 ( V_38 ) )
return true ;
if ( ! V_45 && F_35 ( V_38 ) ) {
F_38 ( L_3 ,
V_28 ) ;
return true ;
}
if ( V_45 == F_34 ( V_38 ) )
return true ;
F_39 ( V_38 ) ;
V_41 = F_30 ( V_22 , V_38 ) ;
if ( ! V_41 )
F_39 ( V_38 ) ;
return V_41 ;
}
static int F_40 ( struct V_21 * V_22 , const char * V_29 ,
struct V_37 * V_38 , bool V_45 )
{
unsigned long V_25 ;
bool V_46 ;
if ( ! F_28 ( V_38 ) || ! F_33 ( V_38 ) )
return 0 ;
if ( ! V_45 && F_35 ( V_38 ) )
return 0 ;
V_25 = F_18 ( V_22 ) ;
F_22 ( V_22 ) ;
V_46 = F_37 ( V_22 , V_38 , V_45 ) ;
F_24 ( V_22 ) ;
F_20 ( V_22 , V_25 ) ;
if ( V_46 )
return 0 ;
F_23 ( L_4 , V_28 ,
V_45 ? L_5 : L_6 , V_29 ) ;
return - V_47 ;
}
static bool F_41 ( struct V_21 * V_22 , struct V_48 * V_49 )
{
F_16 ( V_22 , V_49 -> V_40 , 1 << V_49 -> V_31 ) ;
return F_25 ( V_22 , V_49 -> V_40 , V_49 -> V_31 , false ) ;
}
static T_2 F_42 ( struct V_21 * V_22 , struct V_9 * div )
{
unsigned long V_25 ;
T_1 V_3 ;
T_1 V_10 ;
if ( F_10 ( div ) )
return ( T_2 ) div -> V_11 . V_18 ;
V_25 = F_18 ( V_22 ) ;
V_3 = F_14 ( V_22 , div -> V_11 . V_12 . V_40 ) ;
F_20 ( V_22 , V_25 ) ;
V_10 = F_2 ( V_3 , div -> V_11 . V_12 . V_1 , div -> V_11 . V_12 . V_2 ) ;
return F_6 ( div , V_10 ) ;
}
static int F_43 ( struct V_21 * V_22 , struct V_37 * V_38 ,
struct V_9 * div , struct V_48 * V_49 )
{
bool V_42 ;
T_1 V_10 ;
T_1 V_3 ;
int V_41 = 0 ;
F_8 ( F_10 ( div ) ) ;
if ( div -> V_11 . V_12 . V_19 == V_50 ) {
V_3 = F_14 ( V_22 , div -> V_11 . V_12 . V_40 ) ;
V_10 = F_2 ( V_3 , div -> V_11 . V_12 . V_1 ,
div -> V_11 . V_12 . V_2 ) ;
div -> V_11 . V_12 . V_19 = F_6 ( div , V_10 ) ;
return 0 ;
}
V_10 = F_12 ( div , div -> V_11 . V_12 . V_19 ) ;
V_42 = F_27 ( V_22 , V_38 ) ;
if ( ! V_42 && ! F_37 ( V_22 , V_38 , true ) ) {
V_41 = - V_51 ;
goto V_52;
}
V_3 = F_14 ( V_22 , div -> V_11 . V_12 . V_40 ) ;
V_3 = F_3 ( V_3 , div -> V_11 . V_12 . V_1 , div -> V_11 . V_12 . V_2 ,
V_10 ) ;
F_16 ( V_22 , div -> V_11 . V_12 . V_40 , V_3 ) ;
if ( ! F_41 ( V_22 , V_49 ) )
V_41 = - V_47 ;
if ( ! V_42 && ! F_37 ( V_22 , V_38 , false ) )
V_41 = V_41 ? V_41 : - V_51 ;
V_52:
return V_41 ;
}
static bool F_44 ( struct V_21 * V_22 , struct V_37 * V_38 ,
struct V_9 * div , struct V_48 * V_49 )
{
if ( ! F_45 ( div ) || F_10 ( div ) )
return true ;
return ! F_43 ( V_22 , V_38 , div , V_49 ) ;
}
static int F_46 ( struct V_21 * V_22 , struct V_37 * V_38 ,
struct V_9 * div , struct V_48 * V_49 ,
T_2 V_19 )
{
unsigned long V_25 ;
T_2 V_53 ;
int V_41 ;
F_8 ( F_10 ( div ) ) ;
V_53 = div -> V_11 . V_12 . V_19 ;
if ( V_53 == V_19 )
return 0 ;
div -> V_11 . V_12 . V_19 = V_19 ;
V_25 = F_18 ( V_22 ) ;
F_22 ( V_22 ) ;
V_41 = F_43 ( V_22 , V_38 , div , V_49 ) ;
F_24 ( V_22 ) ;
F_20 ( V_22 , V_25 ) ;
if ( V_41 )
div -> V_11 . V_12 . V_19 = V_53 ;
return V_41 ;
}
static unsigned long F_47 ( struct V_21 * V_22 ,
struct V_9 * div , struct V_9 * V_54 ,
unsigned long V_55 )
{
T_2 V_56 ;
T_2 V_19 ;
T_2 V_8 ;
if ( ! F_45 ( div ) )
return V_55 ;
if ( V_55 > ( unsigned long ) V_57 )
return 0 ;
if ( V_54 && F_45 ( V_54 ) ) {
T_2 V_58 ;
V_58 = F_13 ( V_54 , V_55 ) ;
V_58 = F_13 ( div , V_58 ) ;
V_19 = F_42 ( V_22 , V_54 ) ;
V_56 = F_4 ( V_58 ,
V_19 ) ;
} else {
V_56 = F_13 ( div , V_55 ) ;
}
V_19 = F_42 ( V_22 , div ) ;
V_8 = F_4 ( V_56 , V_19 ) ;
return ( unsigned long ) V_8 ;
}
static long F_48 ( struct V_21 * V_22 , struct V_9 * div ,
struct V_9 * V_54 ,
unsigned long V_20 , unsigned long V_55 ,
T_2 * V_19 )
{
T_2 V_56 ;
T_2 V_59 ;
T_2 V_60 ;
T_2 V_61 ;
T_2 V_8 ;
F_8 ( ! F_45 ( div ) ) ;
F_8 ( ! V_20 ) ;
F_8 ( V_55 > ( T_2 ) V_57 ) ;
if ( F_45 ( V_54 ) ) {
T_2 V_58 ;
T_2 V_62 ;
V_58 = F_13 ( V_54 , V_55 ) ;
V_58 = F_13 ( div , V_58 ) ;
V_62 = F_42 ( V_22 , V_54 ) ;
V_56 = F_4 ( V_58 ,
V_62 ) ;
} else {
V_56 = F_13 ( div , V_55 ) ;
}
if ( ! F_10 ( div ) ) {
V_61 = F_4 ( V_56 ,
V_20 ) ;
V_59 = F_9 ( div ) ;
V_60 = F_11 ( div ) ;
if ( V_61 > V_60 )
V_61 = V_60 ;
else if ( V_61 < V_59 )
V_61 = V_59 ;
} else {
V_61 = F_42 ( V_22 , div ) ;
}
V_8 = F_4 ( V_56 , V_61 ) ;
if ( V_19 )
* V_19 = V_61 ;
return ( long ) V_8 ;
}
static T_3 F_49 ( struct V_63 * V_64 , T_3 V_65 )
{
T_3 V_66 ;
F_8 ( V_64 -> V_67 > ( T_1 ) V_68 ) ;
for ( V_66 = 0 ; V_66 < V_64 -> V_67 ; V_66 ++ )
if ( V_64 -> V_65 [ V_66 ] == V_65 )
return V_66 ;
return V_69 ;
}
static T_3 F_50 ( struct V_21 * V_22 , struct V_63 * V_64 )
{
unsigned long V_25 ;
T_1 V_3 ;
T_1 V_65 ;
T_3 V_70 ;
if ( ! F_51 ( V_64 ) )
return 0 ;
V_25 = F_18 ( V_22 ) ;
V_3 = F_14 ( V_22 , V_64 -> V_40 ) ;
F_20 ( V_22 , V_25 ) ;
V_65 = F_2 ( V_3 , V_64 -> V_1 , V_64 -> V_2 ) ;
V_70 = F_49 ( V_64 , V_65 ) ;
if ( V_70 == V_69 )
F_23 ( L_7 ,
V_28 , V_65 , V_22 -> V_29 , V_64 -> V_40 ) ;
return V_70 ;
}
static int
F_52 ( struct V_21 * V_22 , struct V_37 * V_38 ,
struct V_63 * V_64 , struct V_48 * V_49 )
{
T_1 V_65 ;
T_1 V_3 ;
bool V_42 ;
int V_41 = 0 ;
F_8 ( ! F_51 ( V_64 ) ) ;
if ( V_64 -> V_71 == V_69 ) {
T_3 V_70 ;
V_3 = F_14 ( V_22 , V_64 -> V_40 ) ;
V_65 = F_2 ( V_3 , V_64 -> V_1 , V_64 -> V_2 ) ;
V_70 = F_49 ( V_64 , V_65 ) ;
if ( V_70 == V_69 )
return - V_72 ;
V_64 -> V_71 = V_70 ;
return 0 ;
}
F_8 ( ( T_1 ) V_64 -> V_71 >= V_64 -> V_67 ) ;
V_65 = V_64 -> V_65 [ V_64 -> V_71 ] ;
V_42 = F_27 ( V_22 , V_38 ) ;
if ( ! V_42 && ! F_37 ( V_22 , V_38 , true ) )
return - V_51 ;
V_3 = F_14 ( V_22 , V_64 -> V_40 ) ;
V_3 = F_3 ( V_3 , V_64 -> V_1 , V_64 -> V_2 , V_65 ) ;
F_16 ( V_22 , V_64 -> V_40 , V_3 ) ;
if ( ! F_41 ( V_22 , V_49 ) )
V_41 = - V_47 ;
if ( ! V_42 && ! F_37 ( V_22 , V_38 , false ) )
V_41 = V_41 ? V_41 : - V_51 ;
return V_41 ;
}
static bool F_53 ( struct V_21 * V_22 , struct V_37 * V_38 ,
struct V_63 * V_64 , struct V_48 * V_49 )
{
if ( ! F_51 ( V_64 ) )
return true ;
return ! F_52 ( V_22 , V_38 , V_64 , V_49 ) ;
}
static int F_54 ( struct V_21 * V_22 , struct V_37 * V_38 ,
struct V_63 * V_64 , struct V_48 * V_49 ,
T_3 V_70 )
{
unsigned long V_25 ;
T_3 V_53 ;
int V_41 ;
V_53 = V_64 -> V_71 ;
if ( V_53 == V_70 )
return 0 ;
V_64 -> V_71 = V_70 ;
V_25 = F_18 ( V_22 ) ;
F_22 ( V_22 ) ;
V_41 = F_52 ( V_22 , V_38 , V_64 , V_49 ) ;
F_24 ( V_22 ) ;
F_20 ( V_22 , V_25 ) ;
if ( V_41 )
V_64 -> V_71 = V_53 ;
return V_41 ;
}
static int F_55 ( struct V_73 * V_74 )
{
struct V_75 * V_76 = F_56 ( V_74 ) ;
struct V_37 * V_38 = & V_76 -> V_11 . V_77 -> V_38 ;
return F_40 ( V_76 -> V_22 , V_76 -> V_29 , V_38 , true ) ;
}
static void F_57 ( struct V_73 * V_74 )
{
struct V_75 * V_76 = F_56 ( V_74 ) ;
struct V_37 * V_38 = & V_76 -> V_11 . V_77 -> V_38 ;
( void ) F_40 ( V_76 -> V_22 , V_76 -> V_29 , V_38 , false ) ;
}
static int F_58 ( struct V_73 * V_74 )
{
struct V_75 * V_76 = F_56 ( V_74 ) ;
struct V_37 * V_38 = & V_76 -> V_11 . V_77 -> V_38 ;
return F_29 ( V_76 -> V_22 , V_38 ) ? 1 : 0 ;
}
static unsigned long F_59 ( struct V_73 * V_74 ,
unsigned long V_55 )
{
struct V_75 * V_76 = F_56 ( V_74 ) ;
struct V_78 * V_79 = V_76 -> V_11 . V_77 ;
return F_47 ( V_76 -> V_22 , & V_79 -> div , & V_79 -> V_54 ,
V_55 ) ;
}
static long F_60 ( struct V_73 * V_74 , unsigned long V_20 ,
unsigned long * V_55 )
{
struct V_75 * V_76 = F_56 ( V_74 ) ;
struct V_9 * div = & V_76 -> V_11 . V_77 -> div ;
if ( ! F_45 ( div ) )
return F_61 ( V_74 -> V_80 ) ;
return F_48 ( V_76 -> V_22 , div , & V_76 -> V_11 . V_77 -> V_54 ,
V_20 ? V_20 : 1 , * V_55 , NULL ) ;
}
static int F_62 ( struct V_73 * V_74 , T_3 V_70 )
{
struct V_75 * V_76 = F_56 ( V_74 ) ;
struct V_78 * V_79 = V_76 -> V_11 . V_77 ;
struct V_63 * V_64 = & V_79 -> V_64 ;
struct V_48 * V_49 ;
int V_41 ;
F_8 ( V_70 >= V_64 -> V_67 ) ;
if ( ! F_51 ( V_64 ) )
return 0 ;
V_49 = F_63 ( & V_79 -> V_81 ) ? & V_79 -> V_81
: & V_79 -> V_49 ;
V_41 = F_54 ( V_76 -> V_22 , & V_79 -> V_38 , V_64 , V_49 , V_70 ) ;
if ( V_41 == - V_51 ) {
F_23 ( L_8 , V_28 , V_76 -> V_29 ) ;
V_41 = - V_47 ;
} else if ( V_41 == - V_47 ) {
F_23 ( L_9 , V_28 ,
V_49 == & V_79 -> V_81 ? L_10 : L_11 ,
V_76 -> V_29 ) ;
}
return V_41 ;
}
static T_3 F_64 ( struct V_73 * V_74 )
{
struct V_75 * V_76 = F_56 ( V_74 ) ;
struct V_78 * V_79 = V_76 -> V_11 . V_77 ;
T_3 V_70 ;
V_70 = F_50 ( V_76 -> V_22 , & V_79 -> V_64 ) ;
return V_70 == V_69 ? 0 : V_70 ;
}
static int F_65 ( struct V_73 * V_74 , unsigned long V_20 ,
unsigned long V_55 )
{
struct V_75 * V_76 = F_56 ( V_74 ) ;
struct V_78 * V_79 = V_76 -> V_11 . V_77 ;
struct V_9 * div = & V_79 -> div ;
T_2 V_19 = 0 ;
int V_41 ;
if ( V_55 > ( unsigned long ) V_57 )
return - V_72 ;
if ( V_20 == F_61 ( V_74 -> V_80 ) )
return 0 ;
if ( ! F_45 ( div ) )
return V_20 == V_55 ? 0 : - V_72 ;
if ( F_10 ( & V_79 -> div ) )
return V_20 == V_55 ? 0 : - V_72 ;
( void ) F_48 ( V_76 -> V_22 , div , & V_79 -> V_54 ,
V_20 ? V_20 : 1 , V_55 , & V_19 ) ;
V_41 = F_46 ( V_76 -> V_22 , & V_79 -> V_38 , & V_79 -> div ,
& V_79 -> V_49 , V_19 ) ;
if ( V_41 == - V_51 ) {
F_23 ( L_8 , V_28 , V_76 -> V_29 ) ;
V_41 = - V_47 ;
} else if ( V_41 == - V_47 ) {
F_23 ( L_12 , V_28 , V_76 -> V_29 ) ;
}
return V_41 ;
}
static bool F_66 ( struct V_75 * V_76 )
{
struct V_21 * V_22 = V_76 -> V_22 ;
struct V_78 * V_77 = V_76 -> V_11 . V_77 ;
const char * V_29 = V_76 -> V_29 ;
struct V_48 * V_49 ;
F_8 ( V_76 -> type != V_82 ) ;
if ( ! F_36 ( V_22 , & V_77 -> V_38 ) ) {
F_23 ( L_13 , V_28 , V_29 ) ;
return false ;
}
if ( ! F_44 ( V_22 , & V_77 -> V_38 , & V_77 -> div , & V_77 -> V_49 ) ) {
F_23 ( L_14 , V_28 ,
V_29 ) ;
return false ;
}
V_49 = F_63 ( & V_77 -> V_81 ) ? & V_77 -> V_81
: & V_77 -> V_49 ;
if ( ! F_44 ( V_22 , & V_77 -> V_38 , & V_77 -> V_54 , V_49 ) ) {
F_23 ( L_15 , V_28 ,
V_29 ) ;
return false ;
}
if ( ! F_53 ( V_22 , & V_77 -> V_38 , & V_77 -> V_64 , V_49 ) ) {
F_23 ( L_16 , V_28 ,
V_29 ) ;
return false ;
}
return true ;
}
static bool F_67 ( struct V_75 * V_76 )
{
switch ( V_76 -> type ) {
case V_82 :
return F_66 ( V_76 ) ;
default:
F_68 () ;
}
return - V_72 ;
}
bool T_4 F_69 ( struct V_21 * V_22 )
{
unsigned long V_25 ;
unsigned int V_83 ;
struct V_80 * * V_84 = V_22 -> V_79 . V_84 ;
bool V_46 = true ;
V_25 = F_18 ( V_22 ) ;
F_22 ( V_22 ) ;
for ( V_83 = 0 ; V_83 < V_22 -> V_79 . V_85 ; V_83 ++ ) {
struct V_75 * V_76 ;
if ( ! V_84 [ V_83 ] )
continue;
V_76 = F_56 ( F_70 ( V_84 [ V_83 ] ) ) ;
V_46 &= F_67 ( V_76 ) ;
}
F_24 ( V_22 ) ;
F_20 ( V_22 , V_25 ) ;
return V_46 ;
}

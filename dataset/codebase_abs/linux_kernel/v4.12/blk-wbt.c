static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 && V_2 -> V_3 != 0 ;
}
static bool F_2 ( T_1 * V_4 , int V_5 )
{
int V_6 = F_3 ( V_4 ) ;
for (; ; ) {
int V_7 ;
if ( V_6 >= V_5 )
return false ;
V_7 = F_4 ( V_4 , V_6 , V_6 + 1 ) ;
if ( V_7 == V_6 )
break;
V_6 = V_7 ;
}
return true ;
}
static void F_5 ( struct V_1 * V_2 , unsigned long * V_8 )
{
if ( F_1 ( V_2 ) ) {
const unsigned long V_6 = V_9 ;
if ( V_6 != * V_8 )
* V_8 = V_6 ;
}
}
static bool F_6 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = & V_2 -> V_12 -> V_13 -> V_11 ;
return F_7 ( V_9 , V_11 -> V_14 + V_15 ) ;
}
static inline struct V_16 * F_8 ( struct V_1 * V_2 , bool V_17 )
{
return & V_2 -> V_16 [ V_17 ] ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
struct V_16 * V_20 = & V_2 -> V_16 [ V_18 ] ;
if ( F_10 ( & V_20 -> V_21 ) )
F_11 ( & V_20 -> V_21 ) ;
}
}
void F_12 ( struct V_1 * V_2 , enum V_22 V_23 )
{
struct V_16 * V_20 ;
int V_24 , V_25 ;
if ( ! ( V_23 & V_26 ) )
return;
V_20 = F_8 ( V_2 , V_23 & V_27 ) ;
V_24 = F_13 ( & V_20 -> V_24 ) ;
if ( F_14 ( ! F_1 ( V_2 ) ) ) {
F_9 ( V_2 ) ;
return;
}
if ( V_2 -> V_28 && ! F_6 ( V_2 ) )
V_25 = 0 ;
else
V_25 = V_2 -> V_3 ;
if ( V_24 && V_24 >= V_25 )
return;
if ( F_10 ( & V_20 -> V_21 ) ) {
int V_29 = V_25 - V_24 ;
if ( ! V_24 || V_29 >= V_2 -> V_30 / 2 )
F_11 ( & V_20 -> V_21 ) ;
}
}
void F_15 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
if ( ! V_2 )
return;
if ( ! F_16 ( V_32 ) ) {
if ( V_2 -> V_33 == V_32 ) {
V_2 -> V_34 = 0 ;
V_2 -> V_33 = NULL ;
}
if ( F_17 ( V_32 ) )
F_5 ( V_2 , & V_2 -> V_35 ) ;
F_18 ( V_32 ) ;
} else {
F_19 ( V_32 == V_2 -> V_33 ) ;
F_12 ( V_2 , F_20 ( V_32 ) ) ;
F_18 ( V_32 ) ;
}
}
static bool F_21 ( struct V_1 * V_2 )
{
unsigned int V_36 ;
bool V_37 = false ;
if ( ! V_2 -> V_38 ) {
V_2 -> V_39 = V_2 -> V_3 = V_2 -> V_30 = 0 ;
return false ;
}
if ( V_2 -> V_40 == 1 ) {
if ( V_2 -> V_41 > 0 )
V_2 -> V_39 = V_2 -> V_3 = 1 ;
else {
V_2 -> V_39 = V_2 -> V_3 = 2 ;
V_37 = true ;
}
V_2 -> V_30 = 1 ;
} else {
V_36 = F_22 (unsigned int, RWB_DEF_DEPTH, rwb->queue_depth) ;
if ( V_2 -> V_41 > 0 )
V_36 = 1 + ( ( V_36 - 1 ) >> F_23 ( 31 , V_2 -> V_41 ) ) ;
else if ( V_2 -> V_41 < 0 ) {
unsigned int V_42 = 3 * V_2 -> V_40 / 4 ;
V_36 = 1 + ( ( V_36 - 1 ) << - V_2 -> V_41 ) ;
if ( V_36 > V_42 ) {
V_36 = V_42 ;
V_37 = true ;
}
}
V_2 -> V_39 = V_36 ;
V_2 -> V_3 = ( V_2 -> V_39 + 1 ) / 2 ;
V_2 -> V_30 = ( V_2 -> V_39 + 3 ) / 4 ;
}
return V_37 ;
}
static inline bool F_24 ( struct V_43 * V_32 )
{
return ( V_32 [ V_44 ] . V_45 >= 1 &&
V_32 [ V_46 ] . V_45 >= V_47 ) ;
}
static T_2 F_25 ( struct V_1 * V_2 )
{
T_2 V_48 , V_49 = F_26 ( V_2 -> V_34 ) ;
if ( ! V_49 || ! V_2 -> V_33 )
return 0 ;
V_48 = F_27 ( F_28 () ) ;
return V_48 - V_49 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_43 * V_32 )
{
struct V_13 * V_50 = V_2 -> V_12 -> V_13 ;
T_2 V_51 ;
V_51 = F_25 ( V_2 ) ;
if ( V_51 > V_2 -> V_52 ||
( V_51 > V_2 -> V_38 && ! V_32 [ V_44 ] . V_45 ) ) {
F_30 ( V_50 , V_51 ) ;
return V_53 ;
}
if ( ! F_24 ( V_32 ) ) {
if ( V_32 [ V_46 ] . V_45 || F_6 ( V_2 ) ||
F_31 ( V_2 ) )
return V_54 ;
return V_55 ;
}
if ( V_32 [ V_44 ] . F_23 > V_2 -> V_38 ) {
F_30 ( V_50 , V_32 [ V_44 ] . F_23 ) ;
F_32 ( V_50 , V_32 ) ;
return V_53 ;
}
if ( V_2 -> V_41 )
F_32 ( V_50 , V_32 ) ;
return V_56 ;
}
static void F_33 ( struct V_1 * V_2 , const char * V_57 )
{
struct V_13 * V_50 = V_2 -> V_12 -> V_13 ;
F_34 ( V_50 , V_57 , V_2 -> V_41 , V_2 -> V_52 ,
V_2 -> V_30 , V_2 -> V_3 , V_2 -> V_39 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
if ( V_2 -> V_58 )
return;
V_2 -> V_41 -- ;
V_2 -> V_59 = 0 ;
V_2 -> V_58 = F_21 ( V_2 ) ;
F_9 ( V_2 ) ;
F_33 ( V_2 , L_1 ) ;
}
static void F_36 ( struct V_1 * V_2 , bool V_60 )
{
if ( V_2 -> V_39 == 1 )
return;
if ( V_2 -> V_41 < 0 && V_60 )
V_2 -> V_41 = 0 ;
else
V_2 -> V_41 ++ ;
V_2 -> V_58 = false ;
V_2 -> V_59 = 0 ;
F_21 ( V_2 ) ;
F_33 ( V_2 , L_2 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 > 0 ) {
V_2 -> V_52 = F_38 ( V_2 -> V_61 << 4 ,
F_39 ( ( V_2 -> V_41 + 1 ) << 8 ) ) ;
} else {
V_2 -> V_52 = V_2 -> V_61 ;
}
F_40 ( V_2 -> V_62 , V_2 -> V_52 ) ;
}
static void F_41 ( struct V_63 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_64 ;
unsigned int V_24 = F_31 ( V_2 ) ;
int V_65 ;
V_65 = F_29 ( V_2 , V_62 -> V_32 ) ;
F_42 ( V_2 -> V_12 -> V_13 , V_65 , V_2 -> V_41 ,
V_24 ) ;
switch ( V_65 ) {
case V_53 :
F_36 ( V_2 , true ) ;
break;
case V_56 :
F_35 ( V_2 ) ;
break;
case V_54 :
F_35 ( V_2 ) ;
break;
case V_55 :
if ( ++ V_2 -> V_59 < V_66 )
break;
if ( V_2 -> V_41 > 0 )
F_35 ( V_2 ) ;
else if ( V_2 -> V_41 < 0 )
F_36 ( V_2 , false ) ;
break;
default:
break;
}
if ( V_2 -> V_41 || V_24 )
F_37 ( V_2 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
V_2 -> V_41 = 0 ;
V_2 -> V_58 = false ;
F_21 ( V_2 ) ;
F_9 ( V_2 ) ;
}
static bool F_44 ( struct V_1 * V_2 )
{
const unsigned long V_48 = V_9 ;
return F_7 ( V_48 , V_2 -> V_67 + V_15 / 10 ) ||
F_7 ( V_48 , V_2 -> V_35 + V_15 / 10 ) ;
}
static inline unsigned int F_45 ( struct V_1 * V_2 , unsigned long V_68 )
{
unsigned int V_25 ;
if ( ( V_68 & V_69 ) || F_6 ( V_2 ) || F_46 () )
V_25 = V_2 -> V_39 ;
else if ( ( V_68 & V_70 ) || F_44 ( V_2 ) ) {
V_25 = V_2 -> V_30 ;
} else
V_25 = V_2 -> V_3 ;
return V_25 ;
}
static inline bool F_47 ( struct V_1 * V_2 , struct V_16 * V_20 ,
T_3 * V_21 , unsigned long V_68 )
{
if ( ! F_1 ( V_2 ) ) {
F_48 ( & V_20 -> V_24 ) ;
return true ;
}
if ( F_10 ( & V_20 -> V_21 ) &&
V_20 -> V_21 . V_71 . V_72 != & V_21 -> V_71 )
return false ;
return F_2 ( & V_20 -> V_24 , F_45 ( V_2 , V_68 ) ) ;
}
static void F_49 ( struct V_1 * V_2 , unsigned long V_68 , T_4 * V_73 )
__releases( V_73 )
__acquires( V_73 )
{
struct V_16 * V_20 = F_8 ( V_2 , F_46 () ) ;
F_50 ( V_21 ) ;
if ( F_47 ( V_2 , V_20 , & V_21 , V_68 ) )
return;
do {
F_51 ( & V_20 -> V_21 , & V_21 ,
V_74 ) ;
if ( F_47 ( V_2 , V_20 , & V_21 , V_68 ) )
break;
if ( V_73 ) {
F_52 ( V_73 ) ;
F_53 () ;
F_54 ( V_73 ) ;
} else
F_53 () ;
} while ( 1 );
F_55 ( & V_20 -> V_21 , & V_21 ) ;
}
static inline bool F_56 ( struct V_1 * V_2 , struct V_75 * V_75 )
{
const int V_76 = F_57 ( V_75 ) ;
if ( V_76 != V_77 )
return false ;
if ( ( V_75 -> V_78 & ( V_79 | V_80 ) ) == ( V_79 | V_80 ) )
return false ;
return true ;
}
enum V_22 F_58 ( struct V_1 * V_2 , struct V_75 * V_75 , T_4 * V_73 )
{
unsigned int V_37 = 0 ;
if ( ! F_1 ( V_2 ) )
return 0 ;
if ( F_57 ( V_75 ) == V_81 )
V_37 = V_82 ;
if ( ! F_56 ( V_2 , V_75 ) ) {
if ( V_37 & V_82 )
F_5 ( V_2 , & V_2 -> V_67 ) ;
return V_37 ;
}
F_49 ( V_2 , V_75 -> V_78 , V_73 ) ;
if ( ! F_59 ( V_2 -> V_62 ) )
F_37 ( V_2 ) ;
if ( F_46 () )
V_37 |= V_27 ;
return V_37 | V_26 ;
}
void F_60 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
if ( ! F_1 ( V_2 ) )
return;
if ( F_17 ( V_32 ) && ! V_2 -> V_34 ) {
V_2 -> V_33 = V_32 ;
V_2 -> V_34 = F_61 ( V_32 ) ;
}
}
void F_62 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
if ( ! F_1 ( V_2 ) )
return;
if ( V_32 == V_2 -> V_33 ) {
V_2 -> V_34 = 0 ;
V_2 -> V_33 = NULL ;
}
}
void F_63 ( struct V_1 * V_2 , unsigned int V_36 )
{
if ( V_2 ) {
V_2 -> V_40 = V_36 ;
F_43 ( V_2 ) ;
}
}
void F_64 ( struct V_1 * V_2 , bool V_83 )
{
if ( V_2 )
V_2 -> V_28 = V_83 ;
}
void F_65 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_1 ;
if ( V_2 && V_2 -> V_86 == V_87 )
F_66 ( V_85 ) ;
}
void F_67 ( struct V_84 * V_85 )
{
if ( V_85 -> V_1 )
return;
if ( ! F_68 ( V_88 , & V_85 -> V_89 ) )
return;
if ( ( V_85 -> V_90 && F_69 ( V_91 ) ) ||
( V_85 -> V_92 && F_69 ( V_93 ) ) )
F_70 ( V_85 ) ;
}
T_2 F_71 ( struct V_84 * V_85 )
{
if ( F_72 ( V_85 ) )
return 2000000ULL ;
else
return 75000000ULL ;
}
static int F_73 ( const struct V_94 * V_95 )
{
return F_74 ( V_95 ) ;
}
int F_70 ( struct V_84 * V_85 )
{
struct V_1 * V_2 ;
int V_18 ;
F_75 ( V_96 > V_97 ) ;
V_2 = F_76 ( sizeof( * V_2 ) , V_98 ) ;
if ( ! V_2 )
return - V_99 ;
V_2 -> V_62 = F_77 ( F_41 , F_73 , 2 , V_2 ) ;
if ( ! V_2 -> V_62 ) {
F_78 ( V_2 ) ;
return - V_99 ;
}
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
F_79 ( & V_2 -> V_16 [ V_18 ] . V_24 , 0 ) ;
F_80 ( & V_2 -> V_16 [ V_18 ] . V_21 ) ;
}
V_2 -> V_28 = 1 ;
V_2 -> V_40 = V_100 ;
V_2 -> V_35 = V_2 -> V_67 = V_9 ;
V_2 -> V_12 = V_85 ;
V_2 -> V_61 = V_101 ;
V_2 -> V_86 = V_87 ;
F_43 ( V_2 ) ;
V_85 -> V_1 = V_2 ;
F_81 ( V_85 , V_2 -> V_62 ) ;
V_2 -> V_38 = F_71 ( V_85 ) ;
F_63 ( V_2 , F_82 ( V_85 ) ) ;
F_64 ( V_2 , F_68 ( V_102 , & V_85 -> V_89 ) ) ;
return 0 ;
}
void F_66 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = V_85 -> V_1 ;
if ( V_2 ) {
F_83 ( V_85 , V_2 -> V_62 ) ;
F_84 ( V_2 -> V_62 ) ;
V_85 -> V_1 = NULL ;
F_78 ( V_2 ) ;
}
}

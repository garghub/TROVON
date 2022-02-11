static const struct V_1 * F_1 (
struct V_2 * V_3 , unsigned long V_4 )
{
const struct V_1 * V_5 = V_3 -> V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
if ( V_4 == V_5 [ V_6 ] . V_4 )
return & V_5 [ V_6 ] ;
}
return NULL ;
}
static long F_2 ( struct V_8 * V_9 ,
unsigned long V_10 , unsigned long * V_11 )
{
struct V_2 * V_3 = F_3 ( V_9 ) ;
const struct V_1 * V_5 = V_3 -> V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
if ( V_10 >= V_5 [ V_6 ] . V_4 )
return V_5 [ V_6 ] . V_4 ;
}
return V_5 [ V_6 - 1 ] . V_4 ;
}
static int F_4 ( struct V_2 * V_3 )
{
struct V_12 * V_13 = V_3 -> V_14 -> V_13 ;
unsigned int V_15 ;
int V_16 = 24000000 , V_17 ;
while ( V_16 > 0 ) {
V_17 = F_5 ( V_13 , V_3 -> V_18 , & V_15 ) ;
if ( V_17 ) {
F_6 ( L_1 ,
V_19 , V_17 ) ;
return V_17 ;
}
if ( V_15 & F_7 ( V_3 -> V_20 ) )
return 0 ;
V_16 -- ;
}
F_6 ( L_2 , V_19 ) ;
return - V_21 ;
}
static void F_8 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
T_1 V_22 ;
V_22 = F_9 ( V_3 -> V_23 + F_10 ( 0 ) ) ;
V_4 -> V_24 = ( ( V_22 >> V_25 )
& V_26 ) ;
V_4 -> V_27 = ( ( V_22 >> V_28 )
& V_29 ) ;
V_22 = F_9 ( V_3 -> V_23 + F_10 ( 1 ) ) ;
V_4 -> V_30 = ( ( V_22 >> V_31 )
& V_32 ) ;
V_4 -> V_33 = ( ( V_22 >> V_34 )
& V_35 ) ;
V_4 -> V_36 = ( ( V_22 >> V_37 )
& V_38 ) ;
V_22 = F_9 ( V_3 -> V_23 + F_10 ( 2 ) ) ;
V_4 -> V_39 = ( ( V_22 >> V_40 )
& V_41 ) ;
}
static unsigned long F_11 ( struct V_8 * V_9 ,
unsigned long V_11 )
{
struct V_2 * V_3 = F_3 ( V_9 ) ;
struct V_1 V_42 ;
T_2 V_43 = V_11 ;
F_8 ( V_3 , & V_42 ) ;
V_43 *= V_42 . V_24 ;
F_12 ( V_43 , V_42 . V_30 ) ;
if ( V_42 . V_36 == 0 ) {
T_2 V_44 = V_11 * V_42 . V_39 ;
F_12 ( V_44 , V_42 . V_30 ) ;
V_43 += V_44 >> 24 ;
}
F_12 ( V_43 , V_42 . V_27 ) ;
F_12 ( V_43 , V_42 . V_33 ) ;
return ( unsigned long ) V_43 ;
}
static int F_13 ( struct V_2 * V_3 ,
const struct V_1 * V_4 )
{
const struct V_45 * V_46 = V_3 -> V_46 ;
struct V_47 * V_48 = & V_3 -> V_48 ;
struct V_1 V_42 ;
T_1 V_22 ;
int V_49 = 0 ;
int V_50 ;
int V_17 ;
F_14 ( L_3 ,
V_19 , V_4 -> V_4 , V_4 -> V_24 , V_4 -> V_27 , V_4 -> V_30 ,
V_4 -> V_33 , V_4 -> V_36 , V_4 -> V_39 ) ;
F_8 ( V_3 , & V_42 ) ;
V_42 . V_4 = 0 ;
V_50 = V_46 -> V_51 ( & V_48 -> V_9 ) ;
if ( V_50 == V_52 ) {
V_46 -> V_53 ( & V_48 -> V_9 , V_54 ) ;
V_49 = 1 ;
}
F_15 ( F_16 ( V_4 -> V_24 , V_26 ,
V_25 ) |
F_16 ( V_4 -> V_27 , V_29 ,
V_28 ) ,
V_3 -> V_23 + F_10 ( 0 ) ) ;
F_15 ( F_16 ( V_4 -> V_30 , V_32 ,
V_31 ) |
F_16 ( V_4 -> V_33 , V_35 ,
V_34 ) |
F_16 ( V_4 -> V_36 , V_38 ,
V_37 ) ,
V_3 -> V_23 + F_10 ( 1 ) ) ;
V_22 = F_9 ( V_3 -> V_23 + F_10 ( 2 ) ) ;
V_22 &= ~ ( V_41 << V_40 ) ;
V_22 |= V_4 -> V_39 << V_40 ;
F_15 ( V_22 , V_3 -> V_23 + F_10 ( 2 ) ) ;
V_17 = F_4 ( V_3 ) ;
if ( V_17 ) {
F_17 ( L_4 ,
V_19 ) ;
F_13 ( V_3 , & V_42 ) ;
}
if ( V_49 )
V_46 -> V_53 ( & V_48 -> V_9 , V_52 ) ;
return V_17 ;
}
static int F_18 ( struct V_8 * V_9 , unsigned long V_10 ,
unsigned long V_11 )
{
struct V_2 * V_3 = F_3 ( V_9 ) ;
const struct V_1 * V_4 ;
F_14 ( L_5 ,
V_19 , F_19 ( V_9 -> V_55 ) , V_10 , V_11 ) ;
V_4 = F_1 ( V_3 , V_10 ) ;
if ( ! V_4 ) {
F_6 ( L_6 , V_19 ,
V_10 , F_19 ( V_9 -> V_55 ) ) ;
return - V_56 ;
}
return F_13 ( V_3 , V_4 ) ;
}
static int F_20 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = F_3 ( V_9 ) ;
F_21 ( F_16 ( 0 , V_57 , 0 ) ,
V_3 -> V_23 + F_10 ( 1 ) ) ;
F_4 ( V_3 ) ;
return 0 ;
}
static void F_22 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = F_3 ( V_9 ) ;
F_21 ( F_16 ( V_57 ,
V_57 , 0 ) ,
V_3 -> V_23 + F_10 ( 1 ) ) ;
}
static int F_23 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = F_3 ( V_9 ) ;
T_1 V_22 = F_24 ( V_3 -> V_23 + F_10 ( 1 ) ) ;
return ! ( V_22 & V_57 ) ;
}
static void F_25 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = F_3 ( V_9 ) ;
const struct V_1 * V_4 ;
struct V_1 V_42 ;
unsigned long V_10 ;
if ( ! ( V_3 -> V_58 & V_59 ) )
return;
V_10 = F_26 ( V_9 ) ;
V_4 = F_1 ( V_3 , V_10 ) ;
if ( ! V_4 )
return;
F_8 ( V_3 , & V_42 ) ;
F_14 ( L_7 , V_19 , F_19 ( V_9 -> V_55 ) ,
V_10 ) ;
F_14 ( L_8 ,
V_42 . V_24 , V_42 . V_27 , V_42 . V_30 , V_42 . V_33 ,
V_42 . V_36 , V_42 . V_39 ) ;
F_14 ( L_9 ,
V_4 -> V_24 , V_4 -> V_27 , V_4 -> V_30 , V_4 -> V_33 ,
V_4 -> V_36 , V_4 -> V_39 ) ;
if ( V_4 -> V_24 != V_42 . V_24 || V_4 -> V_27 != V_42 . V_27 ||
V_4 -> V_30 != V_42 . V_30 || V_4 -> V_33 != V_42 . V_33 ||
V_4 -> V_36 != V_42 . V_36 ||
( ! V_42 . V_36 && ( V_4 -> V_39 != V_42 . V_39 ) ) ) {
struct V_55 * V_60 = F_27 ( V_9 -> V_55 ) ;
if ( ! V_60 ) {
F_17 ( L_10 ,
V_19 , F_19 ( V_9 -> V_55 ) ) ;
return;
}
F_14 ( L_11 ,
V_19 , F_19 ( V_9 -> V_55 ) ) ;
F_13 ( V_3 , V_4 ) ;
}
}
static void F_28 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
T_1 V_22 ;
V_22 = F_9 ( V_3 -> V_23 + F_29 ( 0 ) ) ;
V_4 -> V_61 = ( ( V_22 >> V_62 )
& V_63 ) + 1 ;
V_4 -> V_64 = ( ( V_22 >> V_65 )
& V_66 ) + 1 ;
V_22 = F_9 ( V_3 -> V_23 + F_29 ( 1 ) ) ;
V_4 -> V_67 = ( ( V_22 >> V_68 )
& V_69 ) + 1 ;
V_22 = F_9 ( V_3 -> V_23 + F_29 ( 2 ) ) ;
V_4 -> V_70 = ( ( V_22 >> V_71 )
& V_72 ) + 1 ;
}
static unsigned long F_30 ( struct V_8 * V_9 ,
unsigned long V_11 )
{
struct V_2 * V_3 = F_3 ( V_9 ) ;
struct V_1 V_42 ;
T_2 V_43 = V_11 ;
T_1 V_22 ;
V_22 = F_9 ( V_3 -> V_23 + F_29 ( 3 ) ) ;
if ( V_22 & V_73 ) {
F_14 ( L_12 , V_19 ,
F_31 ( V_9 ) ) ;
return V_11 ;
}
F_28 ( V_3 , & V_42 ) ;
V_43 *= V_42 . V_67 ;
F_12 ( V_43 , V_42 . V_61 ) ;
F_12 ( V_43 , V_42 . V_64 ) ;
return ( unsigned long ) V_43 ;
}
static int F_32 ( struct V_2 * V_3 ,
const struct V_1 * V_4 )
{
const struct V_45 * V_46 = V_3 -> V_46 ;
struct V_47 * V_48 = & V_3 -> V_48 ;
struct V_1 V_42 ;
int V_49 = 0 ;
int V_50 ;
int V_17 ;
F_14 ( L_13 ,
V_19 , V_4 -> V_4 , V_4 -> V_61 , V_4 -> V_64 , V_4 -> V_67 ) ;
F_28 ( V_3 , & V_42 ) ;
V_42 . V_4 = 0 ;
V_50 = V_46 -> V_51 ( & V_48 -> V_9 ) ;
if ( V_50 == V_52 ) {
V_46 -> V_53 ( & V_48 -> V_9 , V_54 ) ;
V_49 = 1 ;
}
F_21 ( F_16 ( V_74 , V_74 , 0 ) ,
V_3 -> V_23 + F_29 ( 3 ) ) ;
F_21 ( F_16 ( V_4 -> V_61 - 1 , V_63 ,
V_62 ) |
F_16 ( V_4 -> V_64 - 1 , V_66 ,
V_65 ) ,
V_3 -> V_23 + F_29 ( 0 ) ) ;
F_15 ( F_16 ( V_4 -> V_67 - 1 , V_69 ,
V_68 ) ,
V_3 -> V_23 + F_29 ( 1 ) ) ;
F_15 ( F_16 ( V_4 -> V_70 - 1 , V_72 ,
V_71 ) ,
V_3 -> V_23 + F_29 ( 2 ) ) ;
F_21 ( F_16 ( 0 , V_74 , 0 ) ,
V_3 -> V_23 + F_29 ( 3 ) ) ;
F_33 ( F_34 ( V_4 -> V_61 ) ) ;
V_17 = F_4 ( V_3 ) ;
if ( V_17 ) {
F_17 ( L_4 ,
V_19 ) ;
F_32 ( V_3 , & V_42 ) ;
}
if ( V_49 )
V_46 -> V_53 ( & V_48 -> V_9 , V_52 ) ;
return V_17 ;
}
static int F_35 ( struct V_8 * V_9 , unsigned long V_10 ,
unsigned long V_11 )
{
struct V_2 * V_3 = F_3 ( V_9 ) ;
const struct V_1 * V_4 ;
F_14 ( L_5 ,
V_19 , F_31 ( V_9 ) , V_10 , V_11 ) ;
V_4 = F_1 ( V_3 , V_10 ) ;
if ( ! V_4 ) {
F_6 ( L_6 , V_19 ,
V_10 , F_31 ( V_9 ) ) ;
return - V_56 ;
}
return F_32 ( V_3 , V_4 ) ;
}
static int F_36 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = F_3 ( V_9 ) ;
F_21 ( F_16 ( 0 , V_75 , 0 ) ,
V_3 -> V_23 + F_29 ( 3 ) ) ;
F_4 ( V_3 ) ;
return 0 ;
}
static void F_37 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = F_3 ( V_9 ) ;
F_21 ( F_16 ( V_75 ,
V_75 , 0 ) ,
V_3 -> V_23 + F_29 ( 3 ) ) ;
}
static int F_38 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = F_3 ( V_9 ) ;
T_1 V_22 = F_24 ( V_3 -> V_23 + F_29 ( 3 ) ) ;
return ! ( V_22 & V_75 ) ;
}
static void F_39 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = F_3 ( V_9 ) ;
const struct V_1 * V_4 ;
struct V_1 V_42 ;
unsigned long V_10 ;
if ( ! ( V_3 -> V_58 & V_59 ) )
return;
V_10 = F_26 ( V_9 ) ;
V_4 = F_1 ( V_3 , V_10 ) ;
if ( ! V_4 )
return;
F_28 ( V_3 , & V_42 ) ;
F_14 ( L_14 ,
V_19 , F_31 ( V_9 ) , V_10 , V_4 -> V_61 , V_42 . V_61 ,
V_4 -> V_64 , V_42 . V_64 , V_4 -> V_67 , V_42 . V_67 , V_4 -> V_70 , V_42 . V_70 ) ;
if ( V_4 -> V_61 != V_42 . V_61 || V_4 -> V_64 != V_42 . V_64 || V_4 -> V_67 != V_42 . V_67
|| V_4 -> V_70 != V_42 . V_70 ) {
F_14 ( L_11 ,
V_19 , F_31 ( V_9 ) ) ;
F_32 ( V_3 , V_4 ) ;
}
}
static int F_40 ( struct V_2 * V_3 )
{
T_1 V_22 ;
int V_16 = 24000000 ;
while ( V_16 > 0 ) {
V_22 = F_9 ( V_3 -> V_23 + F_41 ( 2 ) ) ;
if ( V_22 & V_76 )
return 0 ;
V_16 -- ;
}
F_6 ( L_2 , V_19 ) ;
return - V_21 ;
}
static void F_42 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
T_1 V_22 ;
V_22 = F_9 ( V_3 -> V_23 + F_41 ( 0 ) ) ;
V_4 -> V_24 = ( ( V_22 >> V_77 )
& V_78 ) ;
V_22 = F_9 ( V_3 -> V_23 + F_41 ( 1 ) ) ;
V_4 -> V_30 = ( ( V_22 >> V_79 )
& V_80 ) ;
V_4 -> V_27 = ( ( V_22 >> V_81 )
& V_82 ) ;
V_4 -> V_33 = ( ( V_22 >> V_83 )
& V_84 ) ;
V_22 = F_9 ( V_3 -> V_23 + F_41 ( 2 ) ) ;
V_4 -> V_39 = ( ( V_22 >> V_85 )
& V_86 ) ;
V_22 = F_9 ( V_3 -> V_23 + F_41 ( 3 ) ) ;
V_4 -> V_36 = ( ( V_22 >> V_87 )
& V_88 ) ;
}
static unsigned long F_43 ( struct V_8 * V_9 ,
unsigned long V_11 )
{
struct V_2 * V_3 = F_3 ( V_9 ) ;
struct V_1 V_42 ;
T_2 V_43 = V_11 ;
F_42 ( V_3 , & V_42 ) ;
V_43 *= V_42 . V_24 ;
F_12 ( V_43 , V_42 . V_30 ) ;
if ( V_42 . V_36 == 0 ) {
T_2 V_44 = V_11 * V_42 . V_39 ;
F_12 ( V_44 , V_42 . V_30 ) ;
V_43 += V_44 >> 24 ;
}
F_12 ( V_43 , V_42 . V_27 ) ;
F_12 ( V_43 , V_42 . V_33 ) ;
return ( unsigned long ) V_43 ;
}
static int F_44 ( struct V_2 * V_3 ,
const struct V_1 * V_4 )
{
const struct V_45 * V_46 = V_3 -> V_46 ;
struct V_47 * V_48 = & V_3 -> V_48 ;
struct V_1 V_42 ;
T_1 V_22 ;
int V_49 = 0 ;
int V_50 ;
int V_17 ;
F_14 ( L_3 ,
V_19 , V_4 -> V_4 , V_4 -> V_24 , V_4 -> V_27 , V_4 -> V_30 ,
V_4 -> V_33 , V_4 -> V_36 , V_4 -> V_39 ) ;
F_42 ( V_3 , & V_42 ) ;
V_42 . V_4 = 0 ;
V_50 = V_46 -> V_51 ( & V_48 -> V_9 ) ;
if ( V_50 == V_52 ) {
V_46 -> V_53 ( & V_48 -> V_9 , V_54 ) ;
V_49 = 1 ;
}
F_15 ( F_16 ( V_4 -> V_24 , V_78 ,
V_77 ) ,
V_3 -> V_23 + F_41 ( 0 ) ) ;
F_15 ( F_16 ( V_4 -> V_30 , V_80 ,
V_79 ) |
F_16 ( V_4 -> V_27 , V_82 ,
V_81 ) |
F_16 ( V_4 -> V_33 , V_84 ,
V_83 ) ,
V_3 -> V_23 + F_41 ( 1 ) ) ;
V_22 = F_9 ( V_3 -> V_23 + F_41 ( 2 ) ) ;
V_22 &= ~ ( V_86 << V_85 ) ;
V_22 |= V_4 -> V_39 << V_85 ;
F_15 ( V_22 , V_3 -> V_23 + F_41 ( 2 ) ) ;
F_15 ( F_16 ( V_4 -> V_36 , V_88 ,
V_87 ) ,
V_3 -> V_23 + F_41 ( 3 ) ) ;
V_17 = F_40 ( V_3 ) ;
if ( V_17 ) {
F_17 ( L_4 ,
V_19 ) ;
F_44 ( V_3 , & V_42 ) ;
}
if ( V_49 )
V_46 -> V_53 ( & V_48 -> V_9 , V_52 ) ;
return V_17 ;
}
static int F_45 ( struct V_8 * V_9 , unsigned long V_10 ,
unsigned long V_11 )
{
struct V_2 * V_3 = F_3 ( V_9 ) ;
const struct V_1 * V_4 ;
F_14 ( L_5 ,
V_19 , F_19 ( V_9 -> V_55 ) , V_10 , V_11 ) ;
V_4 = F_1 ( V_3 , V_10 ) ;
if ( ! V_4 ) {
F_6 ( L_6 , V_19 ,
V_10 , F_19 ( V_9 -> V_55 ) ) ;
return - V_56 ;
}
return F_44 ( V_3 , V_4 ) ;
}
static int F_46 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = F_3 ( V_9 ) ;
F_21 ( F_16 ( 0 , V_89 , 0 ) ,
V_3 -> V_23 + F_41 ( 3 ) ) ;
F_40 ( V_3 ) ;
return 0 ;
}
static void F_47 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = F_3 ( V_9 ) ;
F_21 ( F_16 ( V_89 ,
V_89 , 0 ) ,
V_3 -> V_23 + F_41 ( 3 ) ) ;
}
static int F_48 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = F_3 ( V_9 ) ;
T_1 V_22 = F_24 ( V_3 -> V_23 + F_41 ( 3 ) ) ;
return ! ( V_22 & V_89 ) ;
}
static void F_49 ( struct V_8 * V_9 )
{
struct V_2 * V_3 = F_3 ( V_9 ) ;
const struct V_1 * V_4 ;
struct V_1 V_42 ;
unsigned long V_10 ;
if ( ! ( V_3 -> V_58 & V_59 ) )
return;
V_10 = F_26 ( V_9 ) ;
V_4 = F_1 ( V_3 , V_10 ) ;
if ( ! V_4 )
return;
F_42 ( V_3 , & V_42 ) ;
F_14 ( L_7 , V_19 , F_19 ( V_9 -> V_55 ) ,
V_10 ) ;
F_14 ( L_8 ,
V_42 . V_24 , V_42 . V_27 , V_42 . V_30 , V_42 . V_33 ,
V_42 . V_36 , V_42 . V_39 ) ;
F_14 ( L_9 ,
V_4 -> V_24 , V_4 -> V_27 , V_4 -> V_30 , V_4 -> V_33 ,
V_4 -> V_36 , V_4 -> V_39 ) ;
if ( V_4 -> V_24 != V_42 . V_24 || V_4 -> V_27 != V_42 . V_27 ||
V_4 -> V_30 != V_42 . V_30 || V_4 -> V_33 != V_42 . V_33 ||
V_4 -> V_36 != V_42 . V_36 ||
( ! V_42 . V_36 && ( V_4 -> V_39 != V_42 . V_39 ) ) ) {
struct V_55 * V_60 = F_27 ( V_9 -> V_55 ) ;
if ( ! V_60 ) {
F_17 ( L_10 ,
V_19 , F_19 ( V_9 -> V_55 ) ) ;
return;
}
F_14 ( L_11 ,
V_19 , F_19 ( V_9 -> V_55 ) ) ;
F_44 ( V_3 , V_4 ) ;
}
}
struct V_55 * F_50 ( struct V_90 * V_14 ,
enum V_91 V_92 ,
const char * V_93 , const char * const * V_94 ,
T_3 V_95 , int V_96 , int V_97 ,
int V_20 , int V_98 , int V_99 ,
struct V_1 * V_5 ,
unsigned long V_58 , T_3 V_100 )
{
const char * V_101 [ 3 ] ;
struct V_102 V_103 ;
struct V_2 * V_3 ;
struct V_47 * V_48 ;
struct V_55 * V_104 , * V_105 ;
char V_106 [ 20 ] ;
if ( ( V_92 != V_107 && V_95 != 2 ) ||
( V_92 == V_107 && V_95 != 1 ) ) {
F_6 ( L_15 , V_19 ) ;
return F_51 ( - V_56 ) ;
}
snprintf ( V_106 , sizeof( V_106 ) , L_16 , V_93 ) ;
V_3 = F_52 ( sizeof( * V_3 ) , V_108 ) ;
if ( ! V_3 )
return F_51 ( - V_109 ) ;
V_3 -> V_46 = & V_110 ;
V_48 = & V_3 -> V_48 ;
V_48 -> V_111 = V_14 -> V_23 + V_98 ;
V_48 -> V_112 = V_99 ;
if ( V_92 == V_107 )
V_48 -> V_113 = V_114 ;
else
V_48 -> V_113 = V_115 ;
V_48 -> V_58 = 0 ;
V_48 -> V_116 = & V_14 -> V_116 ;
V_48 -> V_9 . V_103 = & V_103 ;
if ( V_92 == V_117 ||
V_92 == V_118 ||
V_92 == V_107 ||
V_92 == V_119 )
V_48 -> V_58 |= V_120 ;
V_101 [ 0 ] = V_94 [ 0 ] ;
V_101 [ 1 ] = V_106 ;
V_101 [ 2 ] = V_94 [ 1 ] ;
V_103 . V_93 = V_93 ;
V_103 . V_58 = V_121 ;
V_103 . V_122 = V_3 -> V_46 ;
V_103 . V_94 = V_101 ;
if ( V_92 == V_107 )
V_103 . V_95 = 2 ;
else
V_103 . V_95 = F_53 ( V_101 ) ;
V_105 = F_54 ( NULL , & V_48 -> V_9 ) ;
if ( F_55 ( V_105 ) )
goto V_123;
V_103 . V_93 = V_106 ;
V_103 . V_58 = V_58 | V_124 ;
V_103 . V_94 = & V_94 [ 0 ] ;
V_103 . V_95 = 1 ;
if ( V_5 ) {
int V_125 ;
for ( V_125 = 0 ; V_5 [ V_125 ] . V_4 != 0 ; )
V_125 ++ ;
V_3 -> V_7 = V_125 ;
V_3 -> V_5 = F_56 ( V_5 ,
V_3 -> V_7 *
sizeof( struct V_1 ) ,
V_108 ) ;
F_57 ( ! V_3 -> V_5 ,
L_17 ,
V_19 , V_93 ) ;
}
switch ( V_92 ) {
case V_117 :
case V_107 :
if ( ! V_3 -> V_5 || F_55 ( V_14 -> V_13 ) )
V_103 . V_122 = & V_126 ;
else
V_103 . V_122 = & V_127 ;
break;
case V_118 :
if ( ! V_3 -> V_5 || F_55 ( V_14 -> V_13 ) )
V_103 . V_122 = & V_128 ;
else
V_103 . V_122 = & V_129 ;
break;
case V_119 :
if ( ! V_3 -> V_5 )
V_103 . V_122 = & V_130 ;
else
V_103 . V_122 = & V_131 ;
break;
default:
F_17 ( L_18 ,
V_19 , V_93 ) ;
}
V_3 -> V_9 . V_103 = & V_103 ;
V_3 -> type = V_92 ;
V_3 -> V_23 = V_14 -> V_23 + V_96 ;
V_3 -> V_18 = V_97 ;
V_3 -> V_20 = V_20 ;
V_3 -> V_58 = V_100 ;
V_3 -> V_116 = & V_14 -> V_116 ;
V_3 -> V_14 = V_14 ;
V_104 = F_54 ( NULL , & V_3 -> V_9 ) ;
if ( F_55 ( V_104 ) ) {
F_6 ( L_19 ,
V_19 , V_93 , F_58 ( V_104 ) ) ;
goto V_132;
}
return V_105 ;
V_132:
F_59 ( V_105 ) ;
V_105 = V_104 ;
V_123:
F_60 ( V_3 ) ;
return V_105 ;
}

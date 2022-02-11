static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) ) ;
}
int F_4 ( struct V_2 * V_3 , int V_4 , T_1 V_5 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return F_5 ( V_1 -> V_6 , V_4 , V_5 ) ;
}
int F_6 ( struct V_2 * V_3 , int V_4 , int V_7 , T_1 * V_5 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return F_7 ( V_1 -> V_6 , V_4 , V_5 , V_7 ) ;
}
int F_8 ( struct V_2 * V_3 , int V_4 , T_1 * V_5 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned int V_8 ;
int V_9 ;
V_9 = F_9 ( V_1 -> V_6 , V_4 , & V_8 ) ;
if ( ! V_9 )
* V_5 = V_8 ;
return V_9 ;
}
int F_10 ( struct V_2 * V_3 , int V_4 , int V_7 , T_1 * V_5 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return F_11 ( V_1 -> V_6 , V_4 , V_5 , V_7 ) ;
}
int F_12 ( struct V_2 * V_3 , int V_4 , T_1 V_10 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return F_13 ( V_1 -> V_6 , V_4 , V_10 , V_10 ) ;
}
int F_14 ( struct V_2 * V_3 , int V_4 , T_1 V_10 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return F_13 ( V_1 -> V_6 , V_4 , V_10 , 0 ) ;
}
int F_15 ( struct V_2 * V_3 , int V_4 , T_1 V_5 , T_1 V_11 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return F_13 ( V_1 -> V_6 , V_4 , V_11 , V_5 ) ;
}
static int F_16 ( struct V_2 * V_3 , void * V_12 )
{
F_17 ( F_18 ( V_3 ) ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_1 )
{
return F_20 ( V_1 -> V_3 , NULL , F_16 ) ;
}
static void F_21 ( struct V_13 * V_14 )
{
struct V_1 * V_1 = F_22 ( V_14 ) ;
F_23 ( & V_1 -> V_15 ) ;
}
static void F_24 ( struct V_13 * V_13 )
{
struct V_1 * V_1 = F_22 ( V_13 ) ;
unsigned int V_16 = V_13 -> V_17 - V_1 -> V_18 ;
const struct V_19 * V_14 = & V_20 [ V_16 ] ;
V_1 -> V_21 [ V_14 -> V_21 ] &= ~ V_14 -> V_22 ;
V_1 -> V_23 |= ( 1 << V_16 ) ;
}
static void F_25 ( struct V_13 * V_13 )
{
struct V_1 * V_1 = F_22 ( V_13 ) ;
unsigned int V_16 = V_13 -> V_17 - V_1 -> V_18 ;
const struct V_19 * V_14 = & V_20 [ V_16 ] ;
V_1 -> V_21 [ V_14 -> V_21 ] |= V_14 -> V_22 ;
V_1 -> V_23 &= ~ ( 1 << V_16 ) ;
}
static void F_26 ( struct V_13 * V_14 )
{
struct V_1 * V_1 = F_22 ( V_14 ) ;
int V_24 ;
for ( V_24 = 0 ; V_24 < F_27 ( V_1 -> V_21 ) ; V_24 ++ ) {
int V_9 ;
V_9 = F_4 ( V_1 -> V_3 ,
V_25 + V_24 ,
V_1 -> V_21 [ V_24 ] ) ;
F_28 ( V_9 ) ;
}
F_29 ( & V_1 -> V_15 ) ;
}
static T_2 F_30 ( int V_17 , void * V_14 )
{
struct V_1 * V_1 = V_14 ;
T_3 V_26 ;
int V_9 = 0 ;
V_9 = F_10 ( V_1 -> V_3 , V_27 ,
sizeof( V_26 ) , ( T_1 * ) & V_26 ) ;
if ( V_9 < 0 ) {
F_31 ( V_1 -> V_3 , L_1 ) ;
return V_28 ;
}
V_26 = F_32 ( V_26 ) ;
while ( V_26 ) {
int V_24 = F_33 ( V_26 ) ;
if ( V_1 -> V_23 & ( 1 << V_24 ) )
F_34 ( V_1 -> V_18 + V_24 ) ;
V_26 &= ~ ( 1 << V_24 ) ;
}
return V_29 ;
}
static int T_4 F_35 ( struct V_1 * V_1 , int V_17 ,
int V_18 )
{
int V_24 , V_9 ;
T_5 V_30 [ 4 ] ;
if ( ! V_18 ) {
F_36 ( V_1 -> V_3 , L_2 ) ;
return - V_31 ;
}
F_37 ( & V_1 -> V_15 ) ;
for ( V_24 = 0 ; V_24 < 5 ; V_24 ++ ) {
V_1 -> V_21 [ V_24 ] = 0xff ;
F_4 ( V_1 -> V_3 , V_25 + V_24 , 0xff ) ;
}
F_10 ( V_1 -> V_3 , V_27 , sizeof( V_30 ) , V_30 ) ;
V_1 -> V_18 = V_18 ;
V_1 -> V_32 . V_33 = L_3 ;
V_1 -> V_32 . V_34 = F_24 ;
V_1 -> V_32 . V_35 = F_25 ;
V_1 -> V_32 . V_36 = F_21 ;
V_1 -> V_32 . V_37 = F_26 ;
for ( V_24 = 0 ; V_24 < F_27 ( V_20 ) ; V_24 ++ ) {
int V_16 = V_24 + V_1 -> V_18 ;
F_38 ( V_16 , V_1 ) ;
F_39 ( V_16 , & V_1 -> V_32 ,
V_38 ) ;
F_40 ( V_16 , 1 ) ;
#ifdef F_41
F_42 ( V_16 , V_39 ) ;
#endif
}
V_9 = F_43 ( V_17 , NULL , F_30 , V_40 ,
L_3 , V_1 ) ;
if ( ! V_9 ) {
F_44 ( V_1 -> V_3 , 1 ) ;
F_45 ( V_17 ) ;
}
return V_9 ;
}
static int T_4 F_46 ( struct V_1 * V_1 ,
struct V_41 * V_42 )
{
struct V_43 * V_44 ;
struct V_45 * V_46 ;
int V_24 , V_9 = 0 ;
for ( V_24 = 0 ; V_24 < V_42 -> V_47 ; V_24 ++ ) {
V_44 = & V_42 -> V_48 [ V_24 ] ;
V_46 = F_47 ( V_44 -> V_33 , V_44 -> V_49 ) ;
if ( ! V_46 ) {
V_9 = - V_50 ;
goto V_51;
}
V_46 -> V_3 . V_52 = V_1 -> V_3 ;
V_46 -> V_3 . V_53 = V_44 -> V_53 ;
V_46 -> V_3 . V_54 = V_44 -> V_54 ;
V_9 = F_48 ( V_46 ) ;
if ( V_9 ) {
F_49 ( V_46 ) ;
goto V_51;
}
}
return 0 ;
V_51:
F_19 ( V_1 ) ;
return V_9 ;
}
static struct V_41 * F_50 ( struct V_55 * V_56 )
{
const unsigned int V_57 = F_27 ( V_58 ) ;
struct V_59 * V_60 = V_56 -> V_3 . V_54 ;
struct V_41 * V_42 ;
struct V_43 * V_61 ;
struct V_59 * V_62 ;
const char * V_63 = NULL ;
unsigned int V_64 ;
unsigned int V_24 , V_65 ;
int V_66 ;
V_62 = F_51 ( V_60 , L_4 ) ;
if ( ! V_62 )
return NULL ;
V_66 = F_52 ( & V_56 -> V_3 , V_62 , V_58 , V_57 ) ;
if ( V_66 < 0 ) {
F_53 ( V_62 ) ;
return NULL ;
}
F_53 ( V_62 ) ;
V_64 = V_66 ;
V_61 = F_54 ( & V_56 -> V_3 , V_64 * sizeof( * V_61 ) , V_67 ) ;
if ( ! V_61 )
return NULL ;
for ( V_24 = 0 , V_65 = 0 ; V_24 < V_57 && V_65 < V_64 ; V_24 ++ ) {
struct V_68 * V_69 ;
if ( ! V_58 [ V_24 ] . V_70 )
continue;
V_69 = V_58 [ V_24 ] . V_70 ;
V_61 [ V_65 ] . V_33 = L_5 ;
V_61 [ V_65 ] . V_53 = V_58 [ V_24 ] . V_70 ;
V_61 [ V_65 ] . V_49 = ( int ) V_58 [ V_24 ] . V_71 ;
if ( V_61 [ V_65 ] . V_49 == V_72 )
V_63 = V_69 -> V_73 . V_33 ;
if ( ( V_61 [ V_65 ] . V_49 == V_74 ) ||
( V_61 [ V_65 ] . V_49 == V_75 ) )
V_69 -> V_76 = V_63 ;
V_61 [ V_65 ] . V_54 = V_58 [ V_24 ] . V_54 ;
V_65 ++ ;
}
V_42 = F_54 ( & V_56 -> V_3 , sizeof( * V_42 ) , V_67 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_47 = V_64 ;
V_42 -> V_48 = V_61 ;
V_42 -> V_77 = - 1 ;
V_42 -> V_18 = - 1 ;
V_42 -> V_78 = F_55 ( V_60 , L_6 ) ;
return V_42 ;
}
static struct V_41 * F_50 ( struct V_55 * V_56 )
{
return NULL ;
}
static bool F_56 ( struct V_2 * V_3 , unsigned int V_4 )
{
if ( ( V_4 >= V_25 ) && ( V_4 <= V_79 ) )
return false ;
return true ;
}
static void F_57 ( void )
{
if ( F_14 ( V_80 , V_81 , V_82 ) )
return;
F_12 ( V_80 , V_81 , V_83 ) ;
}
static int T_4 F_58 ( struct V_55 * V_56 ,
const struct V_84 * V_49 )
{
struct V_41 * V_42 = V_56 -> V_3 . V_53 ;
struct V_1 * V_1 ;
int V_9 ;
if ( ! V_42 && V_56 -> V_3 . V_54 )
V_42 = F_50 ( V_56 ) ;
if ( ! V_42 ) {
F_31 ( & V_56 -> V_3 , L_7 ) ;
return - V_85 ;
}
V_9 = F_59 ( V_56 , V_86 ) ;
if ( V_9 < 0 ) {
F_31 ( & V_56 -> V_3 , L_8 , V_9 ) ;
return - V_87 ;
}
F_60 ( & V_56 -> V_3 , L_9 , V_9 ) ;
V_1 = F_54 ( & V_56 -> V_3 , sizeof( * V_1 ) , V_67 ) ;
if ( V_1 == NULL ) {
F_31 ( & V_56 -> V_3 , L_10 ) ;
return - V_50 ;
}
V_1 -> V_56 = V_56 ;
V_1 -> V_3 = & V_56 -> V_3 ;
F_61 ( V_56 , V_1 ) ;
V_1 -> V_6 = F_62 ( V_56 ,
& V_88 ) ;
if ( F_63 ( V_1 -> V_6 ) ) {
V_9 = F_64 ( V_1 -> V_6 ) ;
F_31 ( & V_56 -> V_3 , L_11 , V_9 ) ;
return V_9 ;
}
if ( V_56 -> V_17 ) {
V_9 = F_35 ( V_1 , V_56 -> V_17 ,
V_42 -> V_18 ) ;
if ( V_9 ) {
F_31 ( & V_56 -> V_3 , L_12 , V_9 ) ;
return V_9 ;
}
}
V_9 = F_65 ( V_1 -> V_3 , - 1 ,
V_89 , F_27 ( V_89 ) ,
NULL , 0 , NULL ) ;
if ( V_9 < 0 ) {
F_31 ( & V_56 -> V_3 , L_13 , V_9 ) ;
goto V_90;
}
V_9 = F_46 ( V_1 , V_42 ) ;
if ( V_9 ) {
F_31 ( & V_56 -> V_3 , L_14 , V_9 ) ;
goto V_91;
}
if ( V_42 -> V_78 && ! V_92 ) {
V_80 = & V_56 -> V_3 ;
V_92 = F_57 ;
}
return 0 ;
V_91:
F_66 ( V_1 -> V_3 ) ;
V_90:
if ( V_56 -> V_17 )
F_67 ( V_56 -> V_17 , V_1 ) ;
return V_9 ;
}
static int T_6 F_68 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = F_2 ( V_56 ) ;
F_19 ( V_1 ) ;
F_66 ( V_1 -> V_3 ) ;
if ( V_56 -> V_17 )
F_67 ( V_56 -> V_17 , V_1 ) ;
return 0 ;
}
static int T_7 F_69 ( void )
{
return F_70 ( & V_93 ) ;
}
static void T_8 F_71 ( void )
{
F_72 ( & V_93 ) ;
}

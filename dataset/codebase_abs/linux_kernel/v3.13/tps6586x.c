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
int F_16 ( struct V_2 * V_3 , int V_12 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return F_17 ( V_1 -> V_13 , V_12 ) ;
}
static int F_18 ( struct V_2 * V_3 , void * V_14 )
{
F_19 ( F_20 ( V_3 ) ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_1 )
{
return F_22 ( V_1 -> V_3 , NULL , F_18 ) ;
}
static void F_23 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_24 ( V_16 ) ;
F_25 ( & V_1 -> V_17 ) ;
}
static void F_26 ( struct V_15 * V_15 )
{
struct V_1 * V_1 = F_24 ( V_15 ) ;
unsigned int V_18 = V_15 -> V_19 ;
const struct V_20 * V_16 = & V_21 [ V_18 ] ;
V_1 -> V_22 [ V_16 -> V_22 ] &= ~ V_16 -> V_23 ;
V_1 -> V_24 |= ( 1 << V_18 ) ;
}
static void F_27 ( struct V_15 * V_15 )
{
struct V_1 * V_1 = F_24 ( V_15 ) ;
unsigned int V_18 = V_15 -> V_19 ;
const struct V_20 * V_16 = & V_21 [ V_18 ] ;
V_1 -> V_22 [ V_16 -> V_22 ] |= V_16 -> V_23 ;
V_1 -> V_24 &= ~ ( 1 << V_18 ) ;
}
static void F_28 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_24 ( V_16 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < F_29 ( V_1 -> V_22 ) ; V_25 ++ ) {
int V_9 ;
V_9 = F_4 ( V_1 -> V_3 ,
V_26 + V_25 ,
V_1 -> V_22 [ V_25 ] ) ;
F_30 ( V_9 ) ;
}
F_31 ( & V_1 -> V_17 ) ;
}
static int F_32 ( struct V_15 * V_15 , unsigned int V_27 )
{
struct V_1 * V_1 = F_24 ( V_15 ) ;
return F_33 ( V_1 -> V_12 , V_27 ) ;
}
static int F_34 ( struct V_13 * V_28 , unsigned int V_29 ,
T_2 V_30 )
{
struct V_1 * V_1 = V_28 -> V_31 ;
F_35 ( V_29 , V_1 ) ;
F_36 ( V_29 , & V_32 , V_33 ) ;
F_37 ( V_29 , 1 ) ;
#ifdef F_38
F_39 ( V_29 , V_34 ) ;
#else
F_40 ( V_29 ) ;
#endif
return 0 ;
}
static T_3 F_41 ( int V_12 , void * V_16 )
{
struct V_1 * V_1 = V_16 ;
T_4 V_35 ;
int V_9 = 0 ;
V_9 = F_10 ( V_1 -> V_3 , V_36 ,
sizeof( V_35 ) , ( T_1 * ) & V_35 ) ;
if ( V_9 < 0 ) {
F_42 ( V_1 -> V_3 , L_1 ) ;
return V_37 ;
}
V_35 = F_43 ( V_35 ) ;
while ( V_35 ) {
int V_25 = F_44 ( V_35 ) ;
if ( V_1 -> V_24 & ( 1 << V_25 ) )
F_45 (
F_46 ( V_1 -> V_13 , V_25 ) ) ;
V_35 &= ~ ( 1 << V_25 ) ;
}
return V_38 ;
}
static int F_47 ( struct V_1 * V_1 , int V_12 ,
int V_39 )
{
int V_25 , V_9 ;
T_5 V_40 [ 4 ] ;
int V_41 ;
int V_42 = F_29 ( V_21 ) ;
V_1 -> V_12 = V_12 ;
F_48 ( & V_1 -> V_17 ) ;
for ( V_25 = 0 ; V_25 < 5 ; V_25 ++ ) {
V_1 -> V_22 [ V_25 ] = 0xff ;
F_4 ( V_1 -> V_3 , V_26 + V_25 , 0xff ) ;
}
F_10 ( V_1 -> V_3 , V_36 , sizeof( V_40 ) , V_40 ) ;
if ( V_39 > 0 ) {
V_41 = F_49 ( V_39 , 0 , V_42 , - 1 ) ;
if ( V_41 < 0 ) {
F_42 ( V_1 -> V_3 ,
L_2 , V_41 ) ;
return V_41 ;
}
} else {
V_41 = 0 ;
}
V_1 -> V_13 = F_50 ( V_1 -> V_3 -> V_43 ,
V_42 , V_41 , & V_44 ,
V_1 ) ;
if ( ! V_1 -> V_13 ) {
F_42 ( V_1 -> V_3 , L_3 ) ;
return - V_45 ;
}
V_9 = F_51 ( V_12 , NULL , F_41 , V_46 ,
L_4 , V_1 ) ;
if ( ! V_9 )
F_52 ( V_1 -> V_3 , 1 ) ;
return V_9 ;
}
static int F_53 ( struct V_1 * V_1 ,
struct V_47 * V_48 )
{
struct V_49 * V_50 ;
struct V_51 * V_52 ;
int V_25 , V_9 = 0 ;
for ( V_25 = 0 ; V_25 < V_48 -> V_53 ; V_25 ++ ) {
V_50 = & V_48 -> V_54 [ V_25 ] ;
V_52 = F_54 ( V_50 -> V_55 , V_50 -> V_56 ) ;
if ( ! V_52 ) {
V_9 = - V_45 ;
goto V_57;
}
V_52 -> V_3 . V_58 = V_1 -> V_3 ;
V_52 -> V_3 . V_59 = V_50 -> V_59 ;
V_52 -> V_3 . V_43 = V_50 -> V_43 ;
V_9 = F_55 ( V_52 ) ;
if ( V_9 ) {
F_56 ( V_52 ) ;
goto V_57;
}
}
return 0 ;
V_57:
F_21 ( V_1 ) ;
return V_9 ;
}
static struct V_47 * F_57 ( struct V_60 * V_61 )
{
struct V_62 * V_63 = V_61 -> V_3 . V_43 ;
struct V_47 * V_48 ;
V_48 = F_58 ( & V_61 -> V_3 , sizeof( * V_48 ) , V_64 ) ;
if ( ! V_48 ) {
F_42 ( & V_61 -> V_3 , L_5 ) ;
return NULL ;
}
V_48 -> V_53 = 0 ;
V_48 -> V_54 = NULL ;
V_48 -> V_65 = - 1 ;
V_48 -> V_39 = - 1 ;
V_48 -> V_66 = F_59 ( V_63 , L_6 ) ;
return V_48 ;
}
static struct V_47 * F_57 ( struct V_60 * V_61 )
{
return NULL ;
}
static bool F_60 ( struct V_2 * V_3 , unsigned int V_4 )
{
if ( ( V_4 >= V_26 ) && ( V_4 <= V_67 ) )
return false ;
return true ;
}
static void F_61 ( void )
{
if ( F_14 ( V_68 , V_69 , V_70 ) )
return;
F_12 ( V_68 , V_69 , V_71 ) ;
}
static int F_62 ( struct V_60 * V_61 ,
const struct V_72 * V_56 )
{
struct V_47 * V_48 = F_63 ( & V_61 -> V_3 ) ;
struct V_1 * V_1 ;
int V_9 ;
if ( ! V_48 && V_61 -> V_3 . V_43 )
V_48 = F_57 ( V_61 ) ;
if ( ! V_48 ) {
F_42 ( & V_61 -> V_3 , L_7 ) ;
return - V_73 ;
}
V_9 = F_64 ( V_61 , V_74 ) ;
if ( V_9 < 0 ) {
F_42 ( & V_61 -> V_3 , L_8 , V_9 ) ;
return - V_75 ;
}
F_65 ( & V_61 -> V_3 , L_9 , V_9 ) ;
V_1 = F_58 ( & V_61 -> V_3 , sizeof( * V_1 ) , V_64 ) ;
if ( V_1 == NULL ) {
F_42 ( & V_61 -> V_3 , L_10 ) ;
return - V_45 ;
}
V_1 -> V_61 = V_61 ;
V_1 -> V_3 = & V_61 -> V_3 ;
F_66 ( V_61 , V_1 ) ;
V_1 -> V_6 = F_67 ( V_61 ,
& V_76 ) ;
if ( F_68 ( V_1 -> V_6 ) ) {
V_9 = F_69 ( V_1 -> V_6 ) ;
F_42 ( & V_61 -> V_3 , L_11 , V_9 ) ;
return V_9 ;
}
if ( V_61 -> V_12 ) {
V_9 = F_47 ( V_1 , V_61 -> V_12 ,
V_48 -> V_39 ) ;
if ( V_9 ) {
F_42 ( & V_61 -> V_3 , L_12 , V_9 ) ;
return V_9 ;
}
}
V_9 = F_70 ( V_1 -> V_3 , - 1 ,
V_77 , F_29 ( V_77 ) ,
NULL , 0 , V_1 -> V_13 ) ;
if ( V_9 < 0 ) {
F_42 ( & V_61 -> V_3 , L_13 , V_9 ) ;
goto V_78;
}
V_9 = F_53 ( V_1 , V_48 ) ;
if ( V_9 ) {
F_42 ( & V_61 -> V_3 , L_14 , V_9 ) ;
goto V_79;
}
if ( V_48 -> V_66 && ! V_80 ) {
V_68 = & V_61 -> V_3 ;
V_80 = F_61 ;
}
return 0 ;
V_79:
F_71 ( V_1 -> V_3 ) ;
V_78:
if ( V_61 -> V_12 )
F_72 ( V_61 -> V_12 , V_1 ) ;
return V_9 ;
}
static int F_73 ( struct V_60 * V_61 )
{
struct V_1 * V_1 = F_2 ( V_61 ) ;
F_21 ( V_1 ) ;
F_71 ( V_1 -> V_3 ) ;
if ( V_61 -> V_12 )
F_72 ( V_61 -> V_12 , V_1 ) ;
return 0 ;
}
static int T_6 F_74 ( void )
{
return F_75 ( & V_81 ) ;
}
static void T_7 F_76 ( void )
{
F_77 ( & V_81 ) ;
}

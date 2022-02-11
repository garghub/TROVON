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
static int F_32 ( struct V_13 * V_27 , unsigned int V_28 ,
T_2 V_29 )
{
struct V_1 * V_1 = V_27 -> V_30 ;
F_33 ( V_28 , V_1 ) ;
F_34 ( V_28 , & V_31 , V_32 ) ;
F_35 ( V_28 , 1 ) ;
#ifdef F_36
F_37 ( V_28 , V_33 ) ;
#else
F_38 ( V_28 ) ;
#endif
return 0 ;
}
static T_3 F_39 ( int V_12 , void * V_16 )
{
struct V_1 * V_1 = V_16 ;
T_4 V_34 ;
int V_9 = 0 ;
V_9 = F_10 ( V_1 -> V_3 , V_35 ,
sizeof( V_34 ) , ( T_1 * ) & V_34 ) ;
if ( V_9 < 0 ) {
F_40 ( V_1 -> V_3 , L_1 ) ;
return V_36 ;
}
V_34 = F_41 ( V_34 ) ;
while ( V_34 ) {
int V_25 = F_42 ( V_34 ) ;
if ( V_1 -> V_24 & ( 1 << V_25 ) )
F_43 (
F_44 ( V_1 -> V_13 , V_25 ) ) ;
V_34 &= ~ ( 1 << V_25 ) ;
}
return V_37 ;
}
static int F_45 ( struct V_1 * V_1 , int V_12 ,
int V_38 )
{
int V_25 , V_9 ;
T_5 V_39 [ 4 ] ;
int V_40 ;
int V_41 = F_29 ( V_21 ) ;
F_46 ( & V_1 -> V_17 ) ;
for ( V_25 = 0 ; V_25 < 5 ; V_25 ++ ) {
V_1 -> V_22 [ V_25 ] = 0xff ;
F_4 ( V_1 -> V_3 , V_26 + V_25 , 0xff ) ;
}
F_10 ( V_1 -> V_3 , V_35 , sizeof( V_39 ) , V_39 ) ;
if ( V_38 > 0 ) {
V_40 = F_47 ( V_38 , 0 , V_41 , - 1 ) ;
if ( V_40 < 0 ) {
F_40 ( V_1 -> V_3 ,
L_2 , V_40 ) ;
return V_40 ;
}
} else {
V_40 = 0 ;
}
V_1 -> V_13 = F_48 ( V_1 -> V_3 -> V_42 ,
V_41 , V_40 , & V_43 ,
V_1 ) ;
if ( ! V_1 -> V_13 ) {
F_40 ( V_1 -> V_3 , L_3 ) ;
return - V_44 ;
}
V_9 = F_49 ( V_12 , NULL , F_39 , V_45 ,
L_4 , V_1 ) ;
if ( ! V_9 ) {
F_50 ( V_1 -> V_3 , 1 ) ;
F_51 ( V_12 ) ;
}
return V_9 ;
}
static int F_52 ( struct V_1 * V_1 ,
struct V_46 * V_47 )
{
struct V_48 * V_49 ;
struct V_50 * V_51 ;
int V_25 , V_9 = 0 ;
for ( V_25 = 0 ; V_25 < V_47 -> V_52 ; V_25 ++ ) {
V_49 = & V_47 -> V_53 [ V_25 ] ;
V_51 = F_53 ( V_49 -> V_54 , V_49 -> V_55 ) ;
if ( ! V_51 ) {
V_9 = - V_44 ;
goto V_56;
}
V_51 -> V_3 . V_57 = V_1 -> V_3 ;
V_51 -> V_3 . V_58 = V_49 -> V_58 ;
V_51 -> V_3 . V_42 = V_49 -> V_42 ;
V_9 = F_54 ( V_51 ) ;
if ( V_9 ) {
F_55 ( V_51 ) ;
goto V_56;
}
}
return 0 ;
V_56:
F_21 ( V_1 ) ;
return V_9 ;
}
static struct V_46 * F_56 ( struct V_59 * V_60 )
{
struct V_61 * V_62 = V_60 -> V_3 . V_42 ;
struct V_46 * V_47 ;
V_47 = F_57 ( & V_60 -> V_3 , sizeof( * V_47 ) , V_63 ) ;
if ( ! V_47 ) {
F_40 ( & V_60 -> V_3 , L_5 ) ;
return NULL ;
}
V_47 -> V_52 = 0 ;
V_47 -> V_53 = NULL ;
V_47 -> V_64 = - 1 ;
V_47 -> V_38 = - 1 ;
V_47 -> V_65 = F_58 ( V_62 , L_6 ) ;
return V_47 ;
}
static struct V_46 * F_56 ( struct V_59 * V_60 )
{
return NULL ;
}
static bool F_59 ( struct V_2 * V_3 , unsigned int V_4 )
{
if ( ( V_4 >= V_26 ) && ( V_4 <= V_66 ) )
return false ;
return true ;
}
static void F_60 ( void )
{
if ( F_14 ( V_67 , V_68 , V_69 ) )
return;
F_12 ( V_67 , V_68 , V_70 ) ;
}
static int F_61 ( struct V_59 * V_60 ,
const struct V_71 * V_55 )
{
struct V_46 * V_47 = V_60 -> V_3 . V_58 ;
struct V_1 * V_1 ;
int V_9 ;
if ( ! V_47 && V_60 -> V_3 . V_42 )
V_47 = F_56 ( V_60 ) ;
if ( ! V_47 ) {
F_40 ( & V_60 -> V_3 , L_7 ) ;
return - V_72 ;
}
V_9 = F_62 ( V_60 , V_73 ) ;
if ( V_9 < 0 ) {
F_40 ( & V_60 -> V_3 , L_8 , V_9 ) ;
return - V_74 ;
}
F_63 ( & V_60 -> V_3 , L_9 , V_9 ) ;
V_1 = F_57 ( & V_60 -> V_3 , sizeof( * V_1 ) , V_63 ) ;
if ( V_1 == NULL ) {
F_40 ( & V_60 -> V_3 , L_10 ) ;
return - V_44 ;
}
V_1 -> V_60 = V_60 ;
V_1 -> V_3 = & V_60 -> V_3 ;
F_64 ( V_60 , V_1 ) ;
V_1 -> V_6 = F_65 ( V_60 ,
& V_75 ) ;
if ( F_66 ( V_1 -> V_6 ) ) {
V_9 = F_67 ( V_1 -> V_6 ) ;
F_40 ( & V_60 -> V_3 , L_11 , V_9 ) ;
return V_9 ;
}
if ( V_60 -> V_12 ) {
V_9 = F_45 ( V_1 , V_60 -> V_12 ,
V_47 -> V_38 ) ;
if ( V_9 ) {
F_40 ( & V_60 -> V_3 , L_12 , V_9 ) ;
return V_9 ;
}
}
V_9 = F_68 ( V_1 -> V_3 , - 1 ,
V_76 , F_29 ( V_76 ) ,
NULL , 0 , V_1 -> V_13 ) ;
if ( V_9 < 0 ) {
F_40 ( & V_60 -> V_3 , L_13 , V_9 ) ;
goto V_77;
}
V_9 = F_52 ( V_1 , V_47 ) ;
if ( V_9 ) {
F_40 ( & V_60 -> V_3 , L_14 , V_9 ) ;
goto V_78;
}
if ( V_47 -> V_65 && ! V_79 ) {
V_67 = & V_60 -> V_3 ;
V_79 = F_60 ;
}
return 0 ;
V_78:
F_69 ( V_1 -> V_3 ) ;
V_77:
if ( V_60 -> V_12 )
F_70 ( V_60 -> V_12 , V_1 ) ;
return V_9 ;
}
static int F_71 ( struct V_59 * V_60 )
{
struct V_1 * V_1 = F_2 ( V_60 ) ;
F_21 ( V_1 ) ;
F_69 ( V_1 -> V_3 ) ;
if ( V_60 -> V_12 )
F_70 ( V_60 -> V_12 , V_1 ) ;
return 0 ;
}
static int T_6 F_72 ( void )
{
return F_73 ( & V_80 ) ;
}
static void T_7 F_74 ( void )
{
F_75 ( & V_80 ) ;
}

int F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_3 ( V_6 -> V_7 , V_3 , V_4 ) ;
}
int F_4 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_8 ;
int V_9 ;
V_9 = F_5 ( V_6 -> V_7 , V_3 , & V_8 ) ;
if ( ! V_9 )
* V_4 = V_8 ;
return V_9 ;
}
int F_6 ( struct V_1 * V_2 , int V_3 , T_1 V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_7 ( V_6 -> V_7 , V_3 , F_8 ( V_10 ) , ~ 0u ) ;
}
int F_9 ( struct V_1 * V_2 , int V_3 , T_1 V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_7 ( V_6 -> V_7 , V_3 , F_8 ( V_10 ) , 0u ) ;
}
static void F_10 ( struct V_11 * V_12 )
{
struct V_5 * V_5 = F_11 ( V_12 ) ;
F_12 ( & V_5 -> V_13 ) ;
}
static void F_13 ( struct V_11 * V_11 )
{
struct V_5 * V_5 = F_11 ( V_11 ) ;
unsigned int V_14 = V_11 -> V_15 ;
const struct V_16 * V_12 = & V_17 [ V_14 ] ;
F_6 ( V_5 -> V_2 , ( V_18 + V_12 -> V_19 ) ,
V_12 -> V_20 ) ;
}
static void F_14 ( struct V_11 * V_11 )
{
struct V_5 * V_5 = F_11 ( V_11 ) ;
unsigned int V_14 = V_11 -> V_21 - V_5 -> V_22 ;
const struct V_16 * V_12 = & V_17 [ V_14 ] ;
F_9 ( V_5 -> V_2 , ( V_18 + V_12 -> V_19 ) ,
V_12 -> V_20 ) ;
}
static void F_15 ( struct V_11 * V_12 )
{
struct V_5 * V_5 = F_11 ( V_12 ) ;
F_16 ( & V_5 -> V_13 ) ;
}
static T_2 F_17 ( int V_21 , void * V_12 )
{
struct V_5 * V_5 = V_12 ;
int V_9 = 0 ;
T_3 V_23 , V_24 ;
unsigned long int V_25 = 0 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
V_9 = F_4 ( V_5 -> V_2 , V_18 + V_26 , & V_24 ) ;
if ( V_9 < 0 ) {
F_18 ( V_5 -> V_2 ,
L_1 ,
V_18 + V_26 ) ;
return V_28 ;
}
V_9 = F_4 ( V_5 -> V_2 , V_29 + V_26 ,
& V_23 ) ;
if ( V_9 < 0 ) {
F_18 ( V_5 -> V_2 ,
L_2 ,
V_29 + V_26 ) ;
return V_28 ;
}
if ( V_23 ) {
V_23 &= ( ~ V_24 ) ;
V_9 = F_1 ( V_5 -> V_2 ,
V_29 + V_26 , V_23 ) ;
if ( V_9 < 0 ) {
F_18 ( V_5 -> V_2 ,
L_3 ) ;
return V_28 ;
}
V_25 |= ( V_23 << ( V_26 * 8 ) ) ;
}
}
F_19 (i, &acks, ARRAY_SIZE(tps65090_irqs))
F_20 ( V_5 -> V_22 + V_26 ) ;
return V_25 ? V_30 : V_28 ;
}
static int T_4 F_21 ( struct V_5 * V_5 , int V_21 ,
int V_22 )
{
int V_26 , V_9 ;
if ( ! V_22 ) {
F_18 ( V_5 -> V_2 , L_4 ) ;
return - V_31 ;
}
F_22 ( & V_5 -> V_13 ) ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ )
F_1 ( V_5 -> V_2 , V_18 + V_26 , 0xFF ) ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ )
F_1 ( V_5 -> V_2 , V_29 + V_26 , 0xff ) ;
V_5 -> V_22 = V_22 ;
V_5 -> V_32 . V_33 = L_5 ;
V_5 -> V_32 . V_34 = F_13 ;
V_5 -> V_32 . V_35 = F_14 ;
V_5 -> V_32 . V_36 = F_10 ;
V_5 -> V_32 . V_37 = F_15 ;
for ( V_26 = 0 ; V_26 < F_23 ( V_17 ) ; V_26 ++ ) {
int V_14 = V_26 + V_5 -> V_22 ;
F_24 ( V_14 , V_5 ) ;
F_25 ( V_14 , & V_5 -> V_32 ,
V_38 ) ;
F_26 ( V_14 , 1 ) ;
#ifdef F_27
F_28 ( V_14 , V_39 ) ;
#endif
}
V_9 = F_29 ( V_21 , NULL , F_17 , V_40 ,
L_5 , V_5 ) ;
if ( ! V_9 ) {
F_30 ( V_5 -> V_2 , 1 ) ;
F_31 ( V_21 ) ;
}
return V_9 ;
}
static bool F_32 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( ( V_3 == V_29 ) || ( V_3 == V_29 ) )
return true ;
else
return false ;
}
static int T_4 F_33 ( struct V_41 * V_42 ,
const struct V_43 * V_44 )
{
struct V_45 * V_46 = V_42 -> V_2 . V_47 ;
struct V_5 * V_5 ;
int V_9 ;
if ( ! V_46 ) {
F_18 ( & V_42 -> V_2 , L_6 ) ;
return - V_31 ;
}
V_5 = F_34 ( & V_42 -> V_2 , sizeof( struct V_5 ) ,
V_48 ) ;
if ( V_5 == NULL )
return - V_49 ;
V_5 -> V_42 = V_42 ;
V_5 -> V_2 = & V_42 -> V_2 ;
F_35 ( V_42 , V_5 ) ;
F_22 ( & V_5 -> V_50 ) ;
if ( V_42 -> V_21 ) {
V_9 = F_21 ( V_5 , V_42 -> V_21 , V_46 -> V_22 ) ;
if ( V_9 ) {
F_18 ( & V_42 -> V_2 , L_7 ,
V_9 ) ;
goto V_51;
}
}
V_5 -> V_7 = F_36 ( V_5 -> V_42 ,
& V_52 ) ;
if ( F_37 ( V_5 -> V_7 ) ) {
V_9 = F_38 ( V_5 -> V_7 ) ;
F_18 ( & V_42 -> V_2 , L_8 , V_9 ) ;
goto V_53;
}
V_9 = F_39 ( V_5 -> V_2 , - 1 , V_54 ,
F_23 ( V_54 ) , NULL , 0 ) ;
if ( V_9 ) {
F_18 ( & V_42 -> V_2 , L_9 ,
V_9 ) ;
goto V_53;
}
return 0 ;
V_53:
if ( V_42 -> V_21 )
F_40 ( V_42 -> V_21 , V_5 ) ;
V_51:
return V_9 ;
}
static int T_5 F_41 ( struct V_41 * V_42 )
{
struct V_5 * V_5 = F_42 ( V_42 ) ;
F_43 ( V_5 -> V_2 ) ;
if ( V_42 -> V_21 )
F_40 ( V_42 -> V_21 , V_5 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = F_45 ( V_2 ) ;
if ( V_42 -> V_21 )
F_46 ( V_42 -> V_21 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = F_45 ( V_2 ) ;
if ( V_42 -> V_21 )
F_48 ( V_42 -> V_21 ) ;
return 0 ;
}
static int T_6 F_49 ( void )
{
return F_50 ( & V_55 ) ;
}
static void T_7 F_51 ( void )
{
F_52 ( & V_55 ) ;
}

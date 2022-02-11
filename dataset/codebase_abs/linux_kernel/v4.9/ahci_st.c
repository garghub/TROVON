static void F_1 ( void T_1 * V_1 )
{
unsigned long V_2 , V_3 ;
V_3 = ( 0x02 << V_4 ) |
( 0x04 << V_5 ) |
( 0x08 << V_6 ) |
( 0x0C << V_7 ) ;
V_2 = F_2 ( V_1 + V_8 ) ;
F_3 ( V_2 | V_9 , V_1 + V_8 ) ;
F_3 ( V_3 | V_9 , V_1 + V_8 ) ;
F_3 ( V_3 , V_1 + V_8 ) ;
}
static int F_4 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
int V_17 ;
if ( V_15 -> V_18 ) {
V_17 = F_5 ( V_15 -> V_18 ) ;
if ( V_17 ) {
F_6 ( V_13 , L_1 ) ;
return V_17 ;
}
}
if ( V_15 -> V_19 ) {
V_17 = F_5 ( V_15 -> V_19 ) ;
if ( V_17 ) {
F_6 ( V_13 , L_2 ) ;
return V_17 ;
}
}
if ( V_15 -> V_20 ) {
V_17 = F_5 ( V_15 -> V_20 ) ;
if ( V_17 ) {
F_6 ( V_13 , L_3 ) ;
return V_17 ;
}
}
return 0 ;
}
static void F_7 ( struct V_21 * V_22 )
{
struct V_10 * V_11 = V_22 -> V_23 ;
struct V_14 * V_15 = V_11 -> V_16 ;
struct V_12 * V_13 = V_22 -> V_13 ;
int V_17 ;
if ( V_15 -> V_18 ) {
V_17 = F_8 ( V_15 -> V_18 ) ;
if ( V_17 )
F_6 ( V_13 , L_4 ) ;
}
F_9 ( V_11 ) ;
}
static int F_10 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
V_15 -> V_18 = F_11 ( V_13 , L_5 ) ;
if ( F_12 ( V_15 -> V_18 ) ) {
F_13 ( V_13 , L_6 ) ;
V_15 -> V_18 = NULL ;
}
V_15 -> V_19 = F_11 ( V_13 , L_7 ) ;
if ( F_12 ( V_15 -> V_19 ) ) {
F_13 ( V_13 , L_8 ) ;
V_15 -> V_19 = NULL ;
}
V_15 -> V_20 = F_11 ( V_13 , L_9 ) ;
if ( F_12 ( V_15 -> V_20 ) ) {
F_14 ( V_13 , L_10 ) ;
V_15 -> V_20 = NULL ;
}
return F_4 ( V_11 , V_13 ) ;
}
static int F_15 ( struct V_24 * V_25 )
{
struct V_12 * V_13 = & V_25 -> V_13 ;
struct V_14 * V_15 ;
struct V_10 * V_11 ;
int V_17 ;
V_15 = F_16 ( & V_25 -> V_13 , sizeof( * V_15 ) , V_26 ) ;
if ( ! V_15 )
return - V_27 ;
V_11 = F_17 ( V_25 ) ;
if ( F_12 ( V_11 ) )
return F_18 ( V_11 ) ;
V_11 -> V_16 = V_15 ;
V_17 = F_10 ( V_11 , & V_25 -> V_13 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_19 ( V_11 ) ;
if ( V_17 )
return V_17 ;
F_1 ( V_11 -> V_1 ) ;
F_20 ( V_13 -> V_28 ,
L_11 , & V_11 -> V_29 ) ;
V_17 = F_21 ( V_25 , V_11 , & V_30 ,
& V_31 ) ;
if ( V_17 ) {
F_9 ( V_11 ) ;
return V_17 ;
}
return 0 ;
}
static int F_22 ( struct V_12 * V_13 )
{
struct V_21 * V_22 = F_23 ( V_13 ) ;
struct V_10 * V_11 = V_22 -> V_23 ;
struct V_14 * V_15 = V_11 -> V_16 ;
int V_17 ;
V_17 = F_24 ( V_13 ) ;
if ( V_17 )
return V_17 ;
if ( V_15 -> V_18 ) {
V_17 = F_8 ( V_15 -> V_18 ) ;
if ( V_17 ) {
F_6 ( V_13 , L_12 ) ;
return V_17 ;
}
}
F_9 ( V_11 ) ;
return 0 ;
}
static int F_25 ( struct V_12 * V_13 )
{
struct V_21 * V_22 = F_23 ( V_13 ) ;
struct V_10 * V_11 = V_22 -> V_23 ;
int V_17 ;
V_17 = F_19 ( V_11 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_4 ( V_11 , V_13 ) ;
if ( V_17 ) {
F_9 ( V_11 ) ;
return V_17 ;
}
F_1 ( V_11 -> V_1 ) ;
return F_26 ( V_13 ) ;
}

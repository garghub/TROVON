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
static int F_4 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_14 ;
if ( V_13 -> V_15 ) {
V_14 = F_6 ( V_13 -> V_15 ) ;
if ( V_14 ) {
F_7 ( V_11 , L_1 ) ;
return V_14 ;
}
}
F_1 ( V_13 -> V_16 -> V_1 ) ;
if ( V_13 -> V_17 ) {
V_14 = F_6 ( V_13 -> V_17 ) ;
if ( V_14 ) {
F_7 ( V_11 , L_2 ) ;
return V_14 ;
}
}
if ( V_13 -> V_18 ) {
V_14 = F_6 ( V_13 -> V_18 ) ;
if ( V_14 ) {
F_7 ( V_11 , L_3 ) ;
return V_14 ;
}
}
return 0 ;
}
static void F_8 ( struct V_19 * V_20 )
{
struct V_21 * V_16 = V_20 -> V_22 ;
struct V_10 * V_11 = V_20 -> V_11 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_14 ;
if ( V_13 -> V_15 ) {
V_14 = F_9 ( V_13 -> V_15 ) ;
if ( V_14 )
F_7 ( V_11 , L_4 ) ;
}
F_10 ( V_16 ) ;
}
static int F_11 ( struct V_23 * V_24 )
{
struct V_12 * V_13 = F_12 ( V_24 ) ;
V_13 -> V_15 = F_13 ( & V_24 -> V_11 , L_5 ) ;
if ( F_14 ( V_13 -> V_15 ) ) {
F_15 ( & V_24 -> V_11 , L_6 ) ;
V_13 -> V_15 = NULL ;
}
V_13 -> V_17 = F_13 ( & V_24 -> V_11 , L_7 ) ;
if ( F_14 ( V_13 -> V_17 ) ) {
F_15 ( & V_24 -> V_11 , L_8 ) ;
V_13 -> V_17 = NULL ;
}
V_13 -> V_18 = F_13 ( & V_24 -> V_11 , L_9 ) ;
if ( F_14 ( V_13 -> V_18 ) ) {
F_16 ( & V_24 -> V_11 , L_10 ) ;
V_13 -> V_18 = NULL ;
}
return F_4 ( & V_24 -> V_11 ) ;
}
static int F_17 ( struct V_23 * V_24 )
{
struct V_12 * V_13 ;
struct V_21 * V_16 ;
int V_14 ;
V_13 = F_18 ( & V_24 -> V_11 , sizeof( * V_13 ) , V_25 ) ;
if ( ! V_13 )
return - V_26 ;
F_19 ( V_24 , V_13 ) ;
V_16 = F_20 ( V_24 ) ;
if ( F_14 ( V_16 ) )
return F_21 ( V_16 ) ;
V_13 -> V_16 = V_16 ;
V_14 = F_11 ( V_24 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_22 ( V_16 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_23 ( V_24 , V_16 , & V_27 , 0 , 0 ) ;
if ( V_14 ) {
F_10 ( V_16 ) ;
return V_14 ;
}
return 0 ;
}
static int F_24 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_21 * V_16 = V_13 -> V_16 ;
int V_14 ;
V_14 = F_25 ( V_11 ) ;
if ( V_14 )
return V_14 ;
if ( V_13 -> V_15 ) {
V_14 = F_9 ( V_13 -> V_15 ) ;
if ( V_14 ) {
F_7 ( V_11 , L_11 ) ;
return V_14 ;
}
}
F_10 ( V_16 ) ;
return 0 ;
}
static int F_26 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
struct V_21 * V_16 = V_13 -> V_16 ;
int V_14 ;
V_14 = F_22 ( V_16 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_4 ( V_11 ) ;
if ( V_14 ) {
F_10 ( V_16 ) ;
return V_14 ;
}
return F_27 ( V_11 ) ;
}

int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( V_5 == V_6 ) {
F_2 ( & F_3 ( V_2 ) , L_1 ,
V_6 ) ;
return - V_7 ;
}
F_4 ( & V_8 ) ;
F_5 (itr, &accel_table) {
struct V_1 * V_9 =
F_6 ( V_4 , struct V_1 , V_10 ) ;
if ( V_9 == V_2 ) {
F_7 ( & V_8 ) ;
return - V_11 ;
}
}
F_8 ( & V_2 -> V_12 , 0 ) ;
F_9 ( & V_2 -> V_10 , & V_13 ) ;
V_2 -> V_14 = V_5 ++ ;
F_7 ( & V_8 ) ;
return 0 ;
}
struct V_3 * F_10 ( void )
{
return & V_13 ;
}
void F_11 ( struct V_1 * V_2 )
{
F_4 ( & V_8 ) ;
F_12 ( & V_2 -> V_10 ) ;
V_5 -- ;
F_7 ( & V_8 ) ;
}
struct V_1 * F_13 ( void )
{
struct V_1 * V_15 = NULL ;
if ( ! F_14 ( & V_13 ) )
V_15 = F_15 ( & V_13 , struct V_1 ,
V_10 ) ;
return V_15 ;
}
struct V_1 * F_16 ( struct V_16 * V_16 )
{
struct V_3 * V_4 ;
F_4 ( & V_8 ) ;
F_5 (itr, &accel_table) {
struct V_1 * V_9 =
F_6 ( V_4 , struct V_1 , V_10 ) ;
if ( V_9 -> V_17 . V_16 == V_16 ) {
F_7 ( & V_8 ) ;
return V_9 ;
}
}
F_7 ( & V_8 ) ;
return NULL ;
}
struct V_1 * F_17 ( T_1 V_18 )
{
struct V_3 * V_4 ;
F_4 ( & V_8 ) ;
F_5 (itr, &accel_table) {
struct V_1 * V_9 =
F_6 ( V_4 , struct V_1 , V_10 ) ;
if ( V_9 -> V_14 == V_18 ) {
F_7 ( & V_8 ) ;
return V_9 ;
}
}
F_7 ( & V_8 ) ;
return NULL ;
}
int F_18 ( T_1 V_18 )
{
if ( V_18 == V_19 )
return 0 ;
if ( F_17 ( V_18 ) )
return 0 ;
return - V_20 ;
}
void F_19 ( T_1 * V_21 )
{
struct V_3 * V_4 ;
* V_21 = 0 ;
F_5 (itr, &accel_table) {
( * V_21 ) ++ ;
}
}
int F_20 ( struct V_1 * V_2 )
{
return F_21 ( & V_2 -> V_12 ) != 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
if ( F_23 ( 1 , & V_2 -> V_12 ) == 1 )
if ( ! F_24 ( V_2 -> V_22 ) )
return - V_7 ;
return 0 ;
}
void F_25 ( struct V_1 * V_2 )
{
if ( F_26 ( 1 , & V_2 -> V_12 ) == 0 )
F_27 ( V_2 -> V_22 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
return F_29 ( V_23 , & V_2 -> V_24 ) ;
}
int F_30 ( struct V_1 * V_2 )
{
return F_29 ( V_25 , & V_2 -> V_24 ) ;
}

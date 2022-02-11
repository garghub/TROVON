void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( & V_2 -> V_4 ) ;
V_2 -> V_5 = V_3 ;
F_3 ( & V_2 -> V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_6 ;
F_5 ( V_2 ,
V_7 , V_8 ,
F_6 ( V_9 ) ) ;
V_6 = F_7 ( V_2 ,
V_7 ,
V_8 ,
F_6 ( V_9 ) ,
V_10 ,
L_1 ) ;
if ( ( F_8 ( V_2 , V_7 ) &
F_6 ( V_9 ) ) !=
F_6 ( V_9 ) ) {
F_9 ( V_2 -> V_11 , L_2 ) ;
V_6 = - V_12 ;
}
return V_6 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_6 ;
F_11 ( V_2 -> V_11 , L_3 , V_13 ) ;
F_5 ( V_2 , V_7 ,
V_8 , 0 ) ;
V_6 = F_7 ( V_2 ,
V_7 ,
V_8 ,
0 ,
V_10 ,
L_4 ) ;
if ( ( F_8 ( V_2 , V_7 ) &
F_6 ( V_9 ) ) != 0 ) {
F_9 ( V_2 -> V_11 , L_5 ) ;
V_6 = - V_12 ;
}
return V_6 ;
}
static bool F_12 ( struct V_1 * V_2 )
{
int V_14 ;
bool V_15 ;
V_14 = F_8 ( V_2 , V_7 ) ;
V_15 = ( ( V_14 & F_13 ( V_9 ) ) &&
( V_14 & F_14 ( V_9 ) ) &&
! ( V_14 & F_6 ( V_9 ) ) &&
! ( V_14 & F_15 ( V_9 ) ) ) ;
F_11 ( V_2 -> V_11 , L_6 , V_15 ) ;
return V_15 ;
}
static int F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_7 ,
F_8 ( V_2 , V_7 ) &
F_15 ( V_9 ) ) ;
return F_4 ( V_2 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_10 ( V_2 ) ;
if ( V_6 < 0 ) {
F_11 ( V_2 -> V_11 , L_7 ) ;
return V_6 ;
}
F_11 ( V_2 -> V_11 , L_8 ) ;
F_17 ( V_2 , V_7 ,
F_8 ( V_2 , V_7 ) &
~ F_15 ( V_9 ) ) ;
if ( ! F_12 ( V_2 ) ) {
F_16 ( V_2 ) ;
F_9 ( V_2 -> V_11 , L_9 ) ;
V_6 = - V_12 ;
}
return V_6 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_6 ;
F_5 ( V_2 , V_7 ,
V_16 , F_14 ( V_9 ) ) ;
V_6 = F_7 ( V_2 ,
V_7 ,
V_17 ,
F_13 ( V_9 ) ,
V_18 ,
L_10 ) ;
if ( ( F_8 ( V_2 , V_7 ) &
F_13 ( V_9 ) ) !=
F_13 ( V_9 ) ) {
F_9 ( V_2 -> V_11 , L_11 ) ;
V_6 = - V_12 ;
}
return V_6 ;
}
static int F_20 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_7 ,
V_16 , 0 ) ;
return F_7 ( V_2 ,
V_7 ,
V_16 ,
0 ,
V_19 ,
L_12 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_19 ( V_2 ) ;
if ( V_6 < 0 ) {
F_11 ( V_2 -> V_11 , L_13 ) ;
return V_6 ;
}
return F_18 ( V_2 ) ;
}
int F_22 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_16 ( V_2 ) ;
if ( V_6 < 0 ) {
F_9 ( V_2 -> V_11 , L_14 ) ;
return V_6 ;
}
V_6 = F_20 ( V_2 ) ;
if ( V_6 < 0 ) {
F_9 ( V_2 -> V_11 , L_15 ) ;
return V_6 ;
}
if ( F_12 ( V_2 ) ) {
F_9 ( V_2 -> V_11 , L_16 ) ;
V_6 = - V_12 ;
}
return V_6 ;
}
int F_23 ( struct V_1 * V_2 )
{
int V_6 ;
if ( F_12 ( V_2 ) ) {
F_11 ( V_2 -> V_11 , L_17 ) ;
V_6 = F_16 ( V_2 ) ;
if ( V_6 < 0 ) {
F_9 ( V_2 -> V_11 , L_18 ) ;
return V_6 ;
}
V_6 = F_18 ( V_2 ) ;
if ( V_6 < 0 ) {
F_9 ( V_2 -> V_11 , L_19 ) ;
return V_6 ;
}
} else {
F_11 ( V_2 -> V_11 , L_20 ) ;
V_6 = F_22 ( V_2 ) ;
if ( V_6 < 0 ) {
F_9 ( V_2 -> V_11 , L_21 ) ;
return V_6 ;
}
V_6 = F_21 ( V_2 ) ;
}
return V_6 ;
}
T_1 F_24 ( int V_20 , void * V_21 )
{
struct V_1 * V_2 = V_21 ;
T_2 V_14 ;
T_1 V_22 = V_23 ;
F_25 ( & V_2 -> V_24 ) ;
V_14 = F_8 ( V_2 , V_25 ) ;
V_2 -> V_26 = V_14 ;
if ( V_14 & V_27 ) {
F_26 ( V_2 ) ;
V_22 = V_28 ;
}
if ( V_14 & V_29 ) {
F_27 ( V_2 ) ;
V_22 = V_28 ;
}
F_28 ( & V_2 -> V_24 ) ;
return V_22 ;
}
int F_29 ( struct V_1 * V_2 )
{
return V_2 -> V_30 . V_31 ( V_2 ) ;
}
int F_30 ( struct V_1 * V_2 )
{
return V_2 -> V_30 . V_32 ( V_2 ) ;
}
struct V_1 * F_31 ( struct V_33 * V_11 ,
struct V_34 * V_35 , int V_20 )
{
int V_6 ;
struct V_1 * V_36 ;
V_36 = F_32 ( V_11 , sizeof( * V_36 ) , V_37 ) ;
if ( V_36 == NULL )
return NULL ;
F_33 ( & V_36 -> V_24 ) ;
F_34 ( & V_36 -> V_4 ) ;
V_36 -> V_11 = V_11 ;
V_36 -> V_35 = V_35 ;
V_36 -> V_20 = V_20 ;
V_36 -> V_38 = V_35 -> V_38 ;
V_36 -> V_39 = V_35 -> V_39 ;
if ( V_36 -> V_38 -> V_40 ) {
V_6 = V_36 -> V_38 -> V_40 ( V_36 , NULL ) ;
if ( V_6 < 0 )
return NULL ;
}
V_6 = F_35 ( V_36 -> V_20 , V_36 -> V_38 -> V_41 ,
V_35 -> V_42 , V_43 , L_22 , V_36 ) ;
if ( V_6 ) {
F_9 ( V_36 -> V_11 , L_23 ,
V_36 -> V_20 ) ;
return NULL ;
}
return V_36 ;
}
void F_36 ( struct V_1 * V_44 )
{
F_26 ( V_44 ) ;
F_37 ( V_44 -> V_20 , V_44 ) ;
F_22 ( V_44 ) ;
}
bool F_38 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 == V_45 ) ;
}

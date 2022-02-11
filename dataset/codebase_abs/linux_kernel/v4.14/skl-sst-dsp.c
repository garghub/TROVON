void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( & V_2 -> V_4 ) ;
V_2 -> V_5 = V_3 ;
F_3 ( & V_2 -> V_4 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_9 ;
V_7 -> V_10 . V_3 [ V_11 ] = V_12 ;
V_7 -> V_10 . V_13 [ V_11 ] = 1 ;
for ( V_9 = V_11 + 1 ; V_9 < V_7 -> V_10 . V_14 ; V_9 ++ ) {
V_7 -> V_10 . V_3 [ V_9 ] = V_15 ;
V_7 -> V_10 . V_13 [ V_9 ] = 0 ;
}
}
unsigned int F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_16 , V_17 ;
T_1 V_18 ;
V_16 = F_6 ( V_7 -> V_10 . V_14 ) ;
V_18 = F_7 ( V_2 , V_19 ) ;
V_17 = ( V_18 & F_8 ( V_16 ) ) >>
V_20 ;
V_17 &= ( ~ V_18 & F_9 ( V_16 ) ) >>
V_21 ;
V_17 &= ( ~ V_18 & F_10 ( V_16 ) ) >>
V_22 ;
V_17 &= V_16 ;
F_11 ( V_2 -> V_23 , L_1 , V_17 ) ;
return V_17 ;
}
static int
F_12 ( struct V_1 * V_2 , unsigned int V_16 )
{
int V_24 ;
F_13 ( V_2 ,
V_19 , F_9 ( V_16 ) ,
F_9 ( V_16 ) ) ;
V_24 = F_14 ( V_2 ,
V_19 ,
F_9 ( V_16 ) ,
F_9 ( V_16 ) ,
V_25 ,
L_2 ) ;
if ( ( F_7 ( V_2 , V_19 ) &
F_9 ( V_16 ) ) !=
F_9 ( V_16 ) ) {
F_15 ( V_2 -> V_23 , L_3 ,
V_16 ) ;
V_24 = - V_26 ;
}
return V_24 ;
}
int F_16 (
struct V_1 * V_2 , unsigned int V_16 )
{
int V_24 ;
F_11 ( V_2 -> V_23 , L_4 , V_27 ) ;
F_13 ( V_2 , V_19 ,
F_9 ( V_16 ) , 0 ) ;
V_24 = F_14 ( V_2 ,
V_19 ,
F_9 ( V_16 ) ,
0 ,
V_25 ,
L_5 ) ;
if ( ( F_7 ( V_2 , V_19 ) &
F_9 ( V_16 ) ) != 0 ) {
F_15 ( V_2 -> V_23 , L_6 ,
V_16 ) ;
V_24 = - V_26 ;
}
return V_24 ;
}
static bool
F_17 ( struct V_1 * V_2 , unsigned int V_16 )
{
int V_18 ;
bool V_28 ;
V_18 = F_7 ( V_2 , V_19 ) ;
V_28 = ( ( V_18 & F_8 ( V_16 ) ) &&
( V_18 & F_18 ( V_16 ) ) &&
! ( V_18 & F_9 ( V_16 ) ) &&
! ( V_18 & F_10 ( V_16 ) ) ) ;
F_11 ( V_2 -> V_23 , L_7 ,
V_28 , V_16 ) ;
return V_28 ;
}
static int F_19 ( struct V_1 * V_2 , unsigned int V_16 )
{
F_13 ( V_2 , V_19 ,
F_10 ( V_16 ) ,
F_10 ( V_16 ) ) ;
return F_12 ( V_2 , V_16 ) ;
}
int F_20 ( struct V_1 * V_2 , unsigned int V_16 )
{
int V_24 ;
V_24 = F_16 ( V_2 , V_16 ) ;
if ( V_24 < 0 )
return V_24 ;
F_11 ( V_2 -> V_23 , L_8 , V_16 ) ;
F_13 ( V_2 , V_19 ,
F_10 ( V_16 ) , 0 ) ;
if ( ! F_17 ( V_2 , V_16 ) ) {
F_19 ( V_2 , V_16 ) ;
F_15 ( V_2 -> V_23 , L_9 ,
V_16 ) ;
V_24 = - V_26 ;
}
return V_24 ;
}
int F_21 ( struct V_1 * V_2 , unsigned int V_16 )
{
int V_24 ;
F_13 ( V_2 , V_19 ,
F_18 ( V_16 ) ,
F_18 ( V_16 ) ) ;
V_24 = F_14 ( V_2 ,
V_19 ,
F_8 ( V_16 ) ,
F_8 ( V_16 ) ,
V_29 ,
L_10 ) ;
if ( ( F_7 ( V_2 , V_19 ) &
F_8 ( V_16 ) ) !=
F_8 ( V_16 ) ) {
F_15 ( V_2 -> V_23 , L_11 ,
V_16 ) ;
V_24 = - V_26 ;
}
return V_24 ;
}
int F_22 ( struct V_1 * V_2 , unsigned int V_16 )
{
F_13 ( V_2 , V_19 ,
F_18 ( V_16 ) , 0 ) ;
return F_14 ( V_2 ,
V_19 ,
F_8 ( V_16 ) ,
0 ,
V_30 ,
L_12 ) ;
}
int F_23 ( struct V_1 * V_2 , unsigned int V_16 )
{
int V_24 ;
V_24 = F_21 ( V_2 , V_16 ) ;
if ( V_24 < 0 ) {
F_15 ( V_2 -> V_23 , L_13 ,
V_16 ) ;
return V_24 ;
}
return F_20 ( V_2 , V_16 ) ;
}
int F_24 ( struct V_1 * V_2 , unsigned int V_16 )
{
int V_24 ;
V_24 = F_19 ( V_2 , V_16 ) ;
if ( V_24 < 0 ) {
F_15 ( V_2 -> V_23 , L_14 ,
V_16 ) ;
return V_24 ;
}
V_24 = F_22 ( V_2 , V_16 ) ;
if ( V_24 < 0 ) {
F_15 ( V_2 -> V_23 , L_15 ,
V_16 , V_24 ) ;
return V_24 ;
}
if ( F_17 ( V_2 , V_16 ) ) {
F_15 ( V_2 -> V_23 , L_16 ,
V_16 , V_24 ) ;
V_24 = - V_26 ;
}
return V_24 ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_24 ;
if ( F_17 ( V_2 , V_31 ) ) {
V_24 = F_19 ( V_2 , V_31 ) ;
if ( V_24 < 0 ) {
F_15 ( V_2 -> V_23 , L_17 , V_24 ) ;
return V_24 ;
}
V_24 = F_20 ( V_2 , V_31 ) ;
if ( V_24 < 0 ) {
F_15 ( V_2 -> V_23 , L_18 , V_24 ) ;
return V_24 ;
}
} else {
V_24 = F_24 ( V_2 , V_31 ) ;
if ( V_24 < 0 ) {
F_15 ( V_2 -> V_23 , L_19 , V_24 ) ;
return V_24 ;
}
V_24 = F_23 ( V_2 , V_31 ) ;
}
return V_24 ;
}
T_2 F_26 ( int V_32 , void * V_33 )
{
struct V_1 * V_2 = V_33 ;
T_1 V_18 ;
T_2 V_34 = V_35 ;
F_27 ( & V_2 -> V_36 ) ;
V_18 = F_7 ( V_2 , V_37 ) ;
V_2 -> V_38 = V_18 ;
if ( V_18 == 0xffffffff ) {
F_28 ( & V_2 -> V_36 ) ;
return V_35 ;
}
if ( V_18 & V_39 ) {
F_29 ( V_2 ) ;
V_34 = V_40 ;
}
if ( V_18 & V_41 ) {
F_30 ( V_2 ) ;
V_34 = V_40 ;
}
F_28 ( & V_2 -> V_36 ) ;
return V_34 ;
}
int F_31 ( struct V_1 * V_2 , unsigned int V_42 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_24 = 0 ;
if ( V_42 >= V_7 -> V_10 . V_14 ) {
F_15 ( V_2 -> V_23 , L_20 , V_42 ) ;
return - V_43 ;
}
V_7 -> V_10 . V_13 [ V_42 ] ++ ;
if ( V_7 -> V_10 . V_3 [ V_42 ] == V_15 ) {
V_24 = V_2 -> V_44 . V_45 ( V_2 , V_42 ) ;
if ( V_24 < 0 ) {
F_15 ( V_2 -> V_23 , L_21 , V_42 ) ;
goto V_46;
}
}
V_46:
F_11 ( V_2 -> V_23 , L_22 ,
V_42 , V_7 -> V_10 . V_3 [ V_42 ] ,
V_7 -> V_10 . V_13 [ V_42 ] ) ;
return V_24 ;
}
int F_32 ( struct V_1 * V_2 , unsigned int V_42 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_24 = 0 ;
if ( V_42 >= V_7 -> V_10 . V_14 ) {
F_15 ( V_2 -> V_23 , L_20 , V_42 ) ;
return - V_43 ;
}
if ( ( -- V_7 -> V_10 . V_13 [ V_42 ] == 0 ) &&
( V_7 -> V_10 . V_3 [ V_42 ] != V_15 ) ) {
V_24 = V_2 -> V_44 . V_47 ( V_2 , V_42 ) ;
if ( V_24 < 0 ) {
F_15 ( V_2 -> V_23 , L_23 ,
V_42 , V_24 ) ;
V_7 -> V_10 . V_13 [ V_42 ] ++ ;
}
}
F_11 ( V_2 -> V_23 , L_22 ,
V_42 , V_7 -> V_10 . V_3 [ V_42 ] ,
V_7 -> V_10 . V_13 [ V_42 ] ) ;
return V_24 ;
}
int F_33 ( struct V_1 * V_2 )
{
return F_31 ( V_2 , V_11 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
return F_32 ( V_2 , V_11 ) ;
}
struct V_1 * F_35 ( struct V_48 * V_23 ,
struct V_49 * V_50 , int V_32 )
{
int V_24 ;
struct V_1 * V_51 ;
V_51 = F_36 ( V_23 , sizeof( * V_51 ) , V_52 ) ;
if ( V_51 == NULL )
return NULL ;
F_37 ( & V_51 -> V_36 ) ;
F_38 ( & V_51 -> V_4 ) ;
V_51 -> V_23 = V_23 ;
V_51 -> V_50 = V_50 ;
V_51 -> V_32 = V_32 ;
V_51 -> V_53 = V_50 -> V_53 ;
V_51 -> V_8 = V_50 -> V_8 ;
if ( V_51 -> V_53 -> V_54 ) {
V_24 = V_51 -> V_53 -> V_54 ( V_51 , NULL ) ;
if ( V_24 < 0 )
return NULL ;
}
V_24 = F_39 ( V_51 -> V_32 , V_51 -> V_53 -> V_55 ,
V_50 -> V_56 , V_57 , L_24 , V_51 ) ;
if ( V_24 ) {
F_15 ( V_51 -> V_23 , L_25 ,
V_51 -> V_32 ) ;
return NULL ;
}
return V_51 ;
}
void F_40 ( struct V_1 * V_58 )
{
F_29 ( V_58 ) ;
F_41 ( V_58 -> V_32 , V_58 ) ;
F_42 ( V_58 ) ;
F_24 ( V_58 , V_31 ) ;
}
bool F_43 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 == V_12 ) ;
}

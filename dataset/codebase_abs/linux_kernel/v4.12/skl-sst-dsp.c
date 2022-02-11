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
for ( V_9 = V_11 + 1 ; V_9 < V_14 ; V_9 ++ ) {
V_7 -> V_10 . V_3 [ V_9 ] = V_15 ;
V_7 -> V_10 . V_13 [ V_9 ] = 0 ;
}
}
unsigned int F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_16 , V_17 ;
T_1 V_18 ;
V_16 = F_6 ( V_7 -> V_10 . V_19 ) ;
V_18 = F_7 ( V_2 , V_20 ) ;
V_17 = ( V_18 & F_8 ( V_16 ) ) >>
V_21 ;
V_17 &= ( ~ V_18 & F_9 ( V_16 ) ) >>
V_22 ;
V_17 &= ( ~ V_18 & F_10 ( V_16 ) ) >>
V_23 ;
V_17 &= V_16 ;
F_11 ( V_2 -> V_24 , L_1 , V_17 ) ;
return V_17 ;
}
static int
F_12 ( struct V_1 * V_2 , unsigned int V_16 )
{
int V_25 ;
F_13 ( V_2 ,
V_20 , F_9 ( V_16 ) ,
F_9 ( V_16 ) ) ;
V_25 = F_14 ( V_2 ,
V_20 ,
F_9 ( V_16 ) ,
F_9 ( V_16 ) ,
V_26 ,
L_2 ) ;
if ( ( F_7 ( V_2 , V_20 ) &
F_9 ( V_16 ) ) !=
F_9 ( V_16 ) ) {
F_15 ( V_2 -> V_24 , L_3 ,
V_16 ) ;
V_25 = - V_27 ;
}
return V_25 ;
}
int F_16 (
struct V_1 * V_2 , unsigned int V_16 )
{
int V_25 ;
F_11 ( V_2 -> V_24 , L_4 , V_28 ) ;
F_13 ( V_2 , V_20 ,
F_9 ( V_16 ) , 0 ) ;
V_25 = F_14 ( V_2 ,
V_20 ,
F_9 ( V_16 ) ,
0 ,
V_26 ,
L_5 ) ;
if ( ( F_7 ( V_2 , V_20 ) &
F_9 ( V_16 ) ) != 0 ) {
F_15 ( V_2 -> V_24 , L_6 ,
V_16 ) ;
V_25 = - V_27 ;
}
return V_25 ;
}
static bool
F_17 ( struct V_1 * V_2 , unsigned int V_16 )
{
int V_18 ;
bool V_29 ;
V_18 = F_7 ( V_2 , V_20 ) ;
V_29 = ( ( V_18 & F_8 ( V_16 ) ) &&
( V_18 & F_18 ( V_16 ) ) &&
! ( V_18 & F_9 ( V_16 ) ) &&
! ( V_18 & F_10 ( V_16 ) ) ) ;
F_11 ( V_2 -> V_24 , L_7 ,
V_29 , V_16 ) ;
return V_29 ;
}
static int F_19 ( struct V_1 * V_2 , unsigned int V_16 )
{
F_13 ( V_2 , V_20 ,
F_10 ( V_16 ) ,
F_10 ( V_16 ) ) ;
return F_12 ( V_2 , V_16 ) ;
}
int F_20 ( struct V_1 * V_2 , unsigned int V_16 )
{
int V_25 ;
V_25 = F_16 ( V_2 , V_16 ) ;
if ( V_25 < 0 )
return V_25 ;
F_11 ( V_2 -> V_24 , L_8 , V_16 ) ;
F_13 ( V_2 , V_20 ,
F_10 ( V_16 ) , 0 ) ;
if ( ! F_17 ( V_2 , V_16 ) ) {
F_19 ( V_2 , V_16 ) ;
F_15 ( V_2 -> V_24 , L_9 ,
V_16 ) ;
V_25 = - V_27 ;
}
return V_25 ;
}
int F_21 ( struct V_1 * V_2 , unsigned int V_16 )
{
int V_25 ;
F_13 ( V_2 , V_20 ,
F_18 ( V_16 ) ,
F_18 ( V_16 ) ) ;
V_25 = F_14 ( V_2 ,
V_20 ,
F_8 ( V_16 ) ,
F_8 ( V_16 ) ,
V_30 ,
L_10 ) ;
if ( ( F_7 ( V_2 , V_20 ) &
F_8 ( V_16 ) ) !=
F_8 ( V_16 ) ) {
F_15 ( V_2 -> V_24 , L_11 ,
V_16 ) ;
V_25 = - V_27 ;
}
return V_25 ;
}
int F_22 ( struct V_1 * V_2 , unsigned int V_16 )
{
F_13 ( V_2 , V_20 ,
F_18 ( V_16 ) , 0 ) ;
return F_14 ( V_2 ,
V_20 ,
F_8 ( V_16 ) ,
0 ,
V_31 ,
L_12 ) ;
}
int F_23 ( struct V_1 * V_2 , unsigned int V_16 )
{
int V_25 ;
V_25 = F_21 ( V_2 , V_16 ) ;
if ( V_25 < 0 ) {
F_15 ( V_2 -> V_24 , L_13 ,
V_16 ) ;
return V_25 ;
}
return F_20 ( V_2 , V_16 ) ;
}
int F_24 ( struct V_1 * V_2 , unsigned int V_16 )
{
int V_25 ;
V_25 = F_19 ( V_2 , V_16 ) ;
if ( V_25 < 0 ) {
F_15 ( V_2 -> V_24 , L_14 ,
V_16 ) ;
return V_25 ;
}
V_25 = F_22 ( V_2 , V_16 ) ;
if ( V_25 < 0 ) {
F_15 ( V_2 -> V_24 , L_15 ,
V_16 , V_25 ) ;
return V_25 ;
}
if ( F_17 ( V_2 , V_16 ) ) {
F_15 ( V_2 -> V_24 , L_16 ,
V_16 , V_25 ) ;
V_25 = - V_27 ;
}
return V_25 ;
}
int F_25 ( struct V_1 * V_2 )
{
int V_25 ;
if ( F_17 ( V_2 , V_32 ) ) {
V_25 = F_19 ( V_2 , V_32 ) ;
if ( V_25 < 0 ) {
F_15 ( V_2 -> V_24 , L_17 , V_25 ) ;
return V_25 ;
}
V_25 = F_20 ( V_2 , V_32 ) ;
if ( V_25 < 0 ) {
F_15 ( V_2 -> V_24 , L_18 , V_25 ) ;
return V_25 ;
}
} else {
V_25 = F_24 ( V_2 , V_32 ) ;
if ( V_25 < 0 ) {
F_15 ( V_2 -> V_24 , L_19 , V_25 ) ;
return V_25 ;
}
V_25 = F_23 ( V_2 , V_32 ) ;
}
return V_25 ;
}
T_2 F_26 ( int V_33 , void * V_34 )
{
struct V_1 * V_2 = V_34 ;
T_1 V_18 ;
T_2 V_35 = V_36 ;
F_27 ( & V_2 -> V_37 ) ;
V_18 = F_7 ( V_2 , V_38 ) ;
V_2 -> V_39 = V_18 ;
if ( V_18 == 0xffffffff ) {
F_28 ( & V_2 -> V_37 ) ;
return V_36 ;
}
if ( V_18 & V_40 ) {
F_29 ( V_2 ) ;
V_35 = V_41 ;
}
if ( V_18 & V_42 ) {
F_30 ( V_2 ) ;
V_35 = V_41 ;
}
F_28 ( & V_2 -> V_37 ) ;
return V_35 ;
}
int F_31 ( struct V_1 * V_2 , unsigned int V_43 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_25 = 0 ;
if ( V_43 >= V_7 -> V_10 . V_19 ) {
F_15 ( V_2 -> V_24 , L_20 , V_43 ) ;
return - V_44 ;
}
if ( V_7 -> V_10 . V_3 [ V_43 ] == V_15 ) {
V_25 = V_2 -> V_45 . V_46 ( V_2 , V_43 ) ;
if ( V_25 < 0 ) {
F_15 ( V_2 -> V_24 , L_21 , V_43 ) ;
goto V_47;
}
}
V_7 -> V_10 . V_13 [ V_43 ] ++ ;
V_47:
F_11 ( V_2 -> V_24 , L_22 ,
V_43 , V_7 -> V_10 . V_3 [ V_43 ] ,
V_7 -> V_10 . V_13 [ V_43 ] ) ;
return V_25 ;
}
int F_32 ( struct V_1 * V_2 , unsigned int V_43 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_25 = 0 ;
if ( V_43 >= V_7 -> V_10 . V_19 ) {
F_15 ( V_2 -> V_24 , L_20 , V_43 ) ;
return - V_44 ;
}
if ( ( -- V_7 -> V_10 . V_13 [ V_43 ] == 0 ) &&
( V_7 -> V_10 . V_3 [ V_43 ] != V_15 ) ) {
V_25 = V_2 -> V_45 . V_48 ( V_2 , V_43 ) ;
if ( V_25 < 0 ) {
F_15 ( V_2 -> V_24 , L_23 ,
V_43 , V_25 ) ;
V_7 -> V_10 . V_13 [ V_43 ] ++ ;
}
}
F_11 ( V_2 -> V_24 , L_22 ,
V_43 , V_7 -> V_10 . V_3 [ V_43 ] ,
V_7 -> V_10 . V_13 [ V_43 ] ) ;
return V_25 ;
}
int F_33 ( struct V_1 * V_2 )
{
return F_31 ( V_2 , V_11 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
return F_32 ( V_2 , V_11 ) ;
}
struct V_1 * F_35 ( struct V_49 * V_24 ,
struct V_50 * V_51 , int V_33 )
{
int V_25 ;
struct V_1 * V_52 ;
V_52 = F_36 ( V_24 , sizeof( * V_52 ) , V_53 ) ;
if ( V_52 == NULL )
return NULL ;
F_37 ( & V_52 -> V_37 ) ;
F_38 ( & V_52 -> V_4 ) ;
V_52 -> V_24 = V_24 ;
V_52 -> V_51 = V_51 ;
V_52 -> V_33 = V_33 ;
V_52 -> V_54 = V_51 -> V_54 ;
V_52 -> V_8 = V_51 -> V_8 ;
if ( V_52 -> V_54 -> V_55 ) {
V_25 = V_52 -> V_54 -> V_55 ( V_52 , NULL ) ;
if ( V_25 < 0 )
return NULL ;
}
V_25 = F_39 ( V_52 -> V_33 , V_52 -> V_54 -> V_56 ,
V_51 -> V_57 , V_58 , L_24 , V_52 ) ;
if ( V_25 ) {
F_15 ( V_52 -> V_24 , L_25 ,
V_52 -> V_33 ) ;
return NULL ;
}
return V_52 ;
}
void F_40 ( struct V_1 * V_59 )
{
F_29 ( V_59 ) ;
F_41 ( V_59 -> V_33 , V_59 ) ;
F_42 ( V_59 ) ;
F_24 ( V_59 , V_32 ) ;
}
bool F_43 ( struct V_1 * V_2 )
{
return ( V_2 -> V_5 == V_12 ) ;
}

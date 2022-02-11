static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 = V_5 -> V_7 & V_8 ? 1 : 0 ;
unsigned long V_9 ( V_7 ) ;
T_1 V_10 ;
V_6 ^= V_3 ;
if ( V_5 -> V_11 )
F_3 ( V_5 -> V_11 , V_7 ) ;
if ( V_5 -> V_7 & V_12 ) {
V_10 = F_4 ( V_5 -> V_13 + 16 ) ;
if ( V_6 )
V_10 |= F_4 ( V_5 -> V_13 ) ;
} else {
V_10 = F_5 ( V_5 -> V_10 ) ;
if ( V_6 )
V_10 |= F_4 ( V_5 -> V_13 ) ;
else
V_10 &= ~ F_4 ( V_5 -> V_13 ) ;
}
F_6 ( V_10 , V_5 -> V_10 ) ;
if ( V_5 -> V_11 )
F_7 ( V_5 -> V_11 , V_7 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 1 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_1 V_10 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_10 = F_5 ( V_5 -> V_10 ) ;
if ( V_5 -> V_7 & V_8 )
V_10 ^= F_4 ( V_5 -> V_13 ) ;
V_10 &= F_4 ( V_5 -> V_13 ) ;
return V_10 ? 1 : 0 ;
}
struct V_14 * F_11 ( struct V_15 * V_16 , const char * V_17 ,
const char * V_18 , unsigned long V_7 ,
void T_2 * V_10 , T_3 V_13 ,
T_3 V_19 , T_4 * V_11 )
{
struct V_4 * V_5 ;
struct V_14 * V_14 ;
struct V_20 V_21 ;
if ( V_19 & V_12 ) {
if ( V_13 > 16 ) {
F_12 ( L_1 ) ;
return F_13 ( - V_22 ) ;
}
}
V_5 = F_14 ( sizeof( struct V_4 ) , V_23 ) ;
if ( ! V_5 ) {
F_12 ( L_2 , V_24 ) ;
return F_13 ( - V_25 ) ;
}
V_21 . V_17 = V_17 ;
V_21 . V_26 = & V_27 ;
V_21 . V_7 = V_7 | V_28 ;
V_21 . V_29 = ( V_18 ? & V_18 : NULL ) ;
V_21 . V_30 = ( V_18 ? 1 : 0 ) ;
V_5 -> V_10 = V_10 ;
V_5 -> V_13 = V_13 ;
V_5 -> V_7 = V_19 ;
V_5 -> V_11 = V_11 ;
V_5 -> V_2 . V_21 = & V_21 ;
V_14 = F_15 ( V_16 , & V_5 -> V_2 ) ;
if ( F_16 ( V_14 ) )
F_17 ( V_5 ) ;
return V_14 ;
}

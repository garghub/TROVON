static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 = V_5 -> V_7 & V_8 ? 1 : 0 ;
unsigned long V_7 = 0 ;
T_1 V_9 ;
V_6 ^= V_3 ;
if ( V_5 -> V_10 )
F_3 ( V_5 -> V_10 , V_7 ) ;
if ( V_5 -> V_7 & V_11 ) {
V_9 = F_4 ( V_5 -> V_12 + 16 ) ;
if ( V_6 )
V_9 |= F_4 ( V_5 -> V_12 ) ;
} else {
V_9 = F_5 ( V_5 -> V_9 ) ;
if ( V_6 )
V_9 |= F_4 ( V_5 -> V_12 ) ;
else
V_9 &= ~ F_4 ( V_5 -> V_12 ) ;
}
F_6 ( V_9 , V_5 -> V_9 ) ;
if ( V_5 -> V_10 )
F_7 ( V_5 -> V_10 , V_7 ) ;
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
T_1 V_9 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_9 = F_5 ( V_5 -> V_9 ) ;
if ( V_5 -> V_7 & V_8 )
V_9 ^= F_4 ( V_5 -> V_12 ) ;
V_9 &= F_4 ( V_5 -> V_12 ) ;
return V_9 ? 1 : 0 ;
}
struct V_13 * F_11 ( struct V_14 * V_15 , const char * V_16 ,
const char * V_17 , unsigned long V_7 ,
void T_2 * V_9 , T_3 V_12 ,
T_3 V_18 , T_4 * V_10 )
{
struct V_4 * V_5 ;
struct V_13 * V_13 ;
struct V_19 V_20 ;
if ( V_18 & V_11 ) {
if ( V_12 > 16 ) {
F_12 ( L_1 ) ;
return F_13 ( - V_21 ) ;
}
}
V_5 = F_14 ( sizeof( struct V_4 ) , V_22 ) ;
if ( ! V_5 ) {
F_12 ( L_2 , V_23 ) ;
return F_13 ( - V_24 ) ;
}
V_20 . V_16 = V_16 ;
V_20 . V_25 = & V_26 ;
V_20 . V_7 = V_7 | V_27 ;
V_20 . V_28 = ( V_17 ? & V_17 : NULL ) ;
V_20 . V_29 = ( V_17 ? 1 : 0 ) ;
V_5 -> V_9 = V_9 ;
V_5 -> V_12 = V_12 ;
V_5 -> V_7 = V_18 ;
V_5 -> V_10 = V_10 ;
V_5 -> V_2 . V_20 = & V_20 ;
V_13 = F_15 ( V_15 , & V_5 -> V_2 ) ;
if ( F_16 ( V_13 ) )
F_17 ( V_5 ) ;
return V_13 ;
}

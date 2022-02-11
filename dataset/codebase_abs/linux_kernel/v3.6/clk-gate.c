static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 = V_5 -> V_7 & V_8 ? 1 : 0 ;
unsigned long V_7 = 0 ;
T_1 V_9 ;
V_6 ^= V_3 ;
if ( V_5 -> V_10 )
F_3 ( V_5 -> V_10 , V_7 ) ;
V_9 = F_4 ( V_5 -> V_9 ) ;
if ( V_6 )
V_9 |= F_5 ( V_5 -> V_11 ) ;
else
V_9 &= ~ F_5 ( V_5 -> V_11 ) ;
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
V_9 = F_4 ( V_5 -> V_9 ) ;
if ( V_5 -> V_7 & V_8 )
V_9 ^= F_5 ( V_5 -> V_11 ) ;
V_9 &= F_5 ( V_5 -> V_11 ) ;
return V_9 ? 1 : 0 ;
}
struct V_12 * F_11 ( struct V_13 * V_14 , const char * V_15 ,
const char * V_16 , unsigned long V_7 ,
void T_2 * V_9 , T_3 V_11 ,
T_3 V_17 , T_4 * V_10 )
{
struct V_4 * V_5 ;
struct V_12 * V_12 ;
struct V_18 V_19 ;
V_5 = F_12 ( sizeof( struct V_4 ) , V_20 ) ;
if ( ! V_5 ) {
F_13 ( L_1 , V_21 ) ;
return F_14 ( - V_22 ) ;
}
V_19 . V_15 = V_15 ;
V_19 . V_23 = & V_24 ;
V_19 . V_7 = V_7 | V_25 ;
V_19 . V_26 = ( V_16 ? & V_16 : NULL ) ;
V_19 . V_27 = ( V_16 ? 1 : 0 ) ;
V_5 -> V_9 = V_9 ;
V_5 -> V_11 = V_11 ;
V_5 -> V_7 = V_17 ;
V_5 -> V_10 = V_10 ;
V_5 -> V_2 . V_19 = & V_19 ;
V_12 = F_15 ( V_14 , & V_5 -> V_2 ) ;
if ( F_16 ( V_12 ) )
F_17 ( V_5 ) ;
return V_12 ;
}

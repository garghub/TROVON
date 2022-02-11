static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = F_3 ( V_4 -> V_6 - 1 , 0 ) ;
unsigned int V_7 ;
F_4 ( V_4 -> V_8 , V_4 -> V_9 , & V_7 ) ;
V_7 >>= V_4 -> V_10 ;
V_7 &= V_5 ;
return V_7 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = F_3 ( V_4 -> V_6 + V_4 -> V_10 - 1 , V_4 -> V_10 ) ;
unsigned int V_7 ;
V_7 = V_11 ;
V_7 <<= V_4 -> V_10 ;
if ( V_4 -> V_12 & V_13 )
return F_6 ( V_4 -> V_8 , V_4 -> V_9 , V_7 | ( V_5 << 16 ) ) ;
else
return F_7 ( V_4 -> V_8 , V_4 -> V_9 , V_5 , V_7 ) ;
}
struct V_14 * F_8 ( const char * V_15 ,
const char * const * V_16 , T_1 V_17 ,
int V_12 , struct V_8 * V_8 , int V_9 ,
int V_10 , int V_6 , int V_18 )
{
struct V_3 * V_19 ;
struct V_20 V_21 ;
struct V_14 * V_14 ;
if ( F_9 ( V_8 ) ) {
F_10 ( L_1 , V_22 ) ;
return F_11 ( - V_23 ) ;
}
V_19 = F_12 ( sizeof( * V_19 ) , V_24 ) ;
if ( ! V_19 )
return F_11 ( - V_25 ) ;
V_21 . V_15 = V_15 ;
V_21 . V_12 = V_12 ;
V_21 . V_17 = V_17 ;
V_21 . V_16 = V_16 ;
V_21 . V_26 = & V_27 ;
V_19 -> V_2 . V_21 = & V_21 ;
V_19 -> V_8 = V_8 ;
V_19 -> V_9 = V_9 ;
V_19 -> V_10 = V_10 ;
V_19 -> V_6 = V_6 ;
V_19 -> V_12 = V_18 ;
V_14 = F_13 ( NULL , & V_19 -> V_2 ) ;
if ( F_9 ( V_14 ) )
F_14 ( V_19 ) ;
return V_14 ;
}

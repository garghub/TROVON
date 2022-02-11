static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 = 0 ;
unsigned long V_6 ;
T_1 V_7 ;
if ( V_4 -> V_8 )
F_3 ( V_4 -> V_8 , V_5 ) ;
V_7 = F_4 ( V_4 -> V_9 ) ;
V_7 &= ~ V_4 -> V_10 ;
V_7 |= V_4 -> V_11 ;
F_5 ( V_7 , V_4 -> V_9 ) ;
if ( V_4 -> V_8 )
F_6 ( V_4 -> V_8 , V_5 ) ;
if ( V_4 -> V_5 & V_12 ) {
V_6 = F_7 ( V_2 ) ;
F_8 ( 2000000 / V_6 ) ;
}
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 = 0 ;
T_1 V_7 ;
if ( V_4 -> V_8 )
F_3 ( V_4 -> V_8 , V_5 ) ;
V_7 = F_4 ( V_4 -> V_9 ) ;
V_7 &= ~ V_4 -> V_10 ;
V_7 |= V_4 -> V_13 ;
F_5 ( V_7 , V_4 -> V_9 ) ;
if ( V_4 -> V_8 )
F_6 ( V_4 -> V_8 , V_5 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 = 0 ;
T_1 V_7 ;
if ( V_4 -> V_8 )
F_3 ( V_4 -> V_8 , V_5 ) ;
V_7 = F_4 ( V_4 -> V_9 ) ;
if ( V_4 -> V_8 )
F_6 ( V_4 -> V_8 , V_5 ) ;
return ( V_7 & V_4 -> V_10 ) == V_4 -> V_11 ;
}
struct V_14 * F_11 ( struct V_15 * V_16 , const char * V_17 ,
const char * V_18 , unsigned long V_5 ,
void T_2 * V_9 , T_1 V_10 , T_1 V_11 , T_1 V_13 ,
unsigned int V_19 , T_3 * V_8 )
{
struct V_3 * V_4 ;
struct V_14 * V_14 ;
struct V_20 V_21 ;
V_4 = F_12 ( sizeof( * V_4 ) , V_22 ) ;
if ( ! V_4 ) {
F_13 ( L_1 , V_23 , V_17 ) ;
return F_14 ( - V_24 ) ;
}
V_21 . V_17 = V_17 ;
V_21 . V_25 = & V_26 ;
V_21 . V_5 = V_5 | V_27 ;
V_21 . V_28 = ( V_18 ? & V_18 : NULL ) ;
V_21 . V_29 = ( V_18 ? 1 : 0 ) ;
V_4 -> V_9 = V_9 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_11 = V_11 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_5 = V_19 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_2 . V_21 = & V_21 ;
V_14 = F_15 ( V_16 , & V_4 -> V_2 ) ;
if ( F_16 ( V_14 ) )
F_17 ( V_4 ) ;
return V_14 ;
}

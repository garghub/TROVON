static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return V_3 / V_4 ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
unsigned long V_7 = F_4 ( V_2 -> V_8 ) ;
T_1 V_9 ;
T_2 V_10 ;
T_1 V_11 = 0 ;
V_9 = F_5 ( V_6 -> V_12 ) >> ( V_6 -> V_13 ) ;
V_10 = ( V_9 & V_14 ) * 90 ;
if ( V_9 & V_15 ) {
unsigned long V_16 = ( V_17 / 10 ) *
36 * ( V_7 / 1000000 ) ;
V_11 = ( V_9 & V_18 ) ;
V_11 >>= V_19 ;
V_10 += F_6 ( V_11 * V_16 , 10000 ) ;
}
return V_10 % 360 ;
}
static int F_7 ( struct V_1 * V_2 , int V_10 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
unsigned long V_7 = F_4 ( V_2 -> V_8 ) ;
T_3 V_20 , V_21 ;
T_3 V_11 ;
T_1 V_9 ;
T_1 V_22 ;
V_20 = V_10 / 90 ;
V_21 = ( V_10 % 90 ) ;
V_22 = 10000000 ;
V_22 *= V_21 ;
V_22 = F_6 ( V_22 ,
( V_7 / 1000 ) * 36 *
( V_17 / 10 ) ) ;
V_11 = ( T_3 ) F_8 ( T_1 , V_22 , 255 ) ;
V_9 = V_11 ? V_15 : 0 ;
V_9 |= V_11 << V_19 ;
V_9 |= V_20 ;
F_9 ( F_10 ( V_9 , 0x07ff , V_6 -> V_13 ) , V_6 -> V_12 ) ;
F_11 ( L_1 ,
F_12 ( V_2 ) , V_10 , V_11 ,
V_6 -> V_12 , V_9 >> ( V_6 -> V_13 ) ,
F_2 ( V_2 )
) ;
return 0 ;
}
struct V_8 * F_13 ( const char * V_23 ,
const char * const * V_24 , T_3 V_25 ,
void T_4 * V_12 , int V_13 )
{
struct V_26 V_27 ;
struct V_5 * V_6 ;
struct V_8 * V_8 ;
V_6 = F_14 ( sizeof( * V_6 ) , V_28 ) ;
if ( ! V_6 )
return NULL ;
V_27 . V_23 = V_23 ;
V_27 . V_25 = V_25 ;
V_27 . V_24 = V_24 ;
V_27 . V_29 = & V_30 ;
V_6 -> V_2 . V_27 = & V_27 ;
V_6 -> V_12 = V_12 ;
V_6 -> V_13 = V_13 ;
if ( V_6 -> V_13 == V_31 )
F_9 ( F_10 ( V_32 ,
V_32 ,
V_6 -> V_13 ) , V_6 -> V_12 ) ;
V_8 = F_15 ( NULL , & V_6 -> V_2 ) ;
if ( F_16 ( V_8 ) )
goto V_33;
return V_8 ;
V_33:
F_17 ( V_6 ) ;
return NULL ;
}

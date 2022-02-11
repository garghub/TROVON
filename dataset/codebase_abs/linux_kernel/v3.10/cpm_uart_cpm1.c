void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 -> V_4 , V_3 ) ;
}
void T_1 * F_3 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
return F_4 ( V_6 , 1 ) ;
}
void F_5 ( struct V_1 * V_2 , void T_1 * V_7 )
{
F_6 ( V_7 ) ;
}
int F_7 ( struct V_1 * V_8 , unsigned int V_9 )
{
int V_10 , V_11 ;
T_2 * V_12 ;
unsigned long V_13 ;
T_2 * V_14 ;
T_3 V_15 = 0 ;
F_8 ( L_1 , V_8 -> V_2 . line ) ;
V_10 = sizeof( V_16 ) * ( V_8 -> V_17 + V_8 -> V_18 ) ;
V_13 = F_9 ( V_10 , 8 ) ;
if ( F_10 ( V_13 ) ) {
F_11 ( V_19
L_2 ) ;
return - V_20 ;
}
V_12 = F_12 ( V_13 ) ;
V_11 = F_13 ( V_8 -> V_17 * V_8 -> V_21 ) +
F_13 ( V_8 -> V_18 * V_8 -> V_22 ) ;
if ( V_9 ) {
V_14 = ( T_2 * ) F_12 ( F_9 ( V_11 , 8 ) ) ;
V_15 = ( V_23 ) F_14 ( V_14 ) ;
} else
V_14 = F_15 ( V_8 -> V_2 . V_24 , V_11 , & V_15 ,
V_25 ) ;
if ( V_14 == NULL ) {
F_16 ( V_13 ) ;
F_11 ( V_19
L_3 ) ;
return - V_20 ;
}
V_8 -> V_26 = V_13 ;
V_8 -> V_14 = V_14 ;
V_8 -> V_15 = V_15 ;
V_8 -> V_27 = V_11 ;
V_8 -> V_28 = V_14 ;
V_8 -> V_29 = V_8 -> V_28 + F_13 ( V_8 -> V_17
* V_8 -> V_21 ) ;
V_8 -> V_30 = ( V_16 T_1 V_31 * ) V_12 ;
V_8 -> V_32 = V_8 -> V_30 + V_8 -> V_17 ;
return 0 ;
}
void F_17 ( struct V_1 * V_8 )
{
F_18 ( V_8 -> V_2 . V_24 , F_13 ( V_8 -> V_17 *
V_8 -> V_21 ) +
F_13 ( V_8 -> V_18 *
V_8 -> V_22 ) , V_8 -> V_14 ,
V_8 -> V_15 ) ;
F_16 ( V_8 -> V_26 ) ;
}

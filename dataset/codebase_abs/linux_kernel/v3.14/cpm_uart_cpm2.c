void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 -> V_4 , V_3 ) ;
}
void T_1 * F_3 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
void T_1 * V_7 ;
unsigned long V_8 ;
struct V_9 V_10 ;
T_2 V_11 ;
if ( F_4 ( V_2 ) && V_2 -> V_12 )
return V_2 -> V_12 ;
else if ( ! F_4 ( V_2 ) && V_2 -> V_13 )
return V_2 -> V_13 ;
if ( F_5 ( V_6 , 1 , & V_10 ) )
return NULL ;
V_11 = F_6 ( & V_10 ) ;
V_7 = F_7 ( V_10 . V_14 , V_11 ) ;
if ( ! V_7 )
return NULL ;
if ( ! F_4 ( V_2 ) )
return V_7 ;
if ( V_11 != 2 ) {
F_8 ( V_15 L_1
L_2
L_3
L_4 ,
V_2 -> V_2 . line ) ;
return V_7 ;
}
V_8 = F_9 ( V_16 , 64 ) ;
F_10 ( V_7 , V_8 ) ;
F_11 ( V_7 ) ;
return F_12 ( V_8 ) ;
}
void F_13 ( struct V_1 * V_2 , void T_1 * V_7 )
{
if ( ! F_4 ( V_2 ) )
F_11 ( V_7 ) ;
}
int F_14 ( struct V_1 * V_17 , unsigned int V_18 )
{
int V_19 , V_20 ;
T_3 T_1 * V_21 ;
unsigned long V_22 ;
T_3 * V_23 ;
T_4 V_24 = 0 ;
F_15 ( L_5 , V_17 -> V_2 . line ) ;
V_19 = sizeof( V_25 ) * ( V_17 -> V_26 + V_17 -> V_27 ) ;
V_22 = F_9 ( V_19 , 8 ) ;
if ( F_16 ( V_22 ) ) {
F_8 ( V_28
L_6 ) ;
return - V_29 ;
}
V_21 = F_17 ( V_22 ) ;
V_20 = F_18 ( V_17 -> V_26 * V_17 -> V_30 ) +
F_18 ( V_17 -> V_27 * V_17 -> V_31 ) ;
if ( V_18 ) {
V_23 = F_19 ( V_20 , V_32 ) ;
V_24 = F_20 ( V_23 ) ;
}
else
V_23 = F_21 ( V_17 -> V_2 . V_33 , V_20 , & V_24 ,
V_34 ) ;
if ( V_23 == NULL ) {
F_22 ( V_22 ) ;
F_8 ( V_28
L_7 ) ;
return - V_29 ;
}
V_17 -> V_35 = V_22 ;
V_17 -> V_23 = V_23 ;
V_17 -> V_24 = V_24 ;
V_17 -> V_36 = V_20 ;
V_17 -> V_37 = V_23 ;
V_17 -> V_38 = V_17 -> V_37 + F_18 ( V_17 -> V_26
* V_17 -> V_30 ) ;
V_17 -> V_39 = ( V_25 T_1 * ) V_21 ;
V_17 -> V_40 = V_17 -> V_39 + V_17 -> V_26 ;
return 0 ;
}
void F_23 ( struct V_1 * V_17 )
{
F_24 ( V_17 -> V_2 . V_33 , F_18 ( V_17 -> V_26 *
V_17 -> V_30 ) +
F_18 ( V_17 -> V_27 *
V_17 -> V_31 ) , ( void V_41 * ) V_17 -> V_23 ,
V_17 -> V_24 ) ;
F_22 ( V_17 -> V_35 ) ;
}

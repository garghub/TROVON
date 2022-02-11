int F_1 ( struct V_1 * V_2 , int V_3 ,
T_1 V_4 , void * V_5 , T_2 V_6 ,
unsigned int V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_10 , V_11 , V_12 = 0 ;
V_10 = V_7 & V_13 ;
for (; ; ) {
if ( ! ( V_7 & V_14 ) ) {
V_10 = V_9 -> V_10 ;
F_3 () ;
}
V_11 = F_4 ( V_9 -> V_15 , V_3 ,
V_9 -> V_16 , V_10 ,
V_9 -> V_17 , V_4 ,
V_5 , V_6 ) ;
if ( V_11 == V_18 )
return 0 ;
if ( V_11 == V_19 && ( V_7 & V_14 ) )
return - V_20 ;
if ( F_5 ( V_11 ) || ++ V_12 >= 3 ) {
if ( ! ( V_7 & V_21 ) )
F_6 ( & V_2 -> V_9 ,
L_1 ,
F_7 ( V_11 ) ) ;
return - V_22 ;
}
F_8 ( V_23 ) ;
}
}
void F_9 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
T_1 V_26 , V_27 ;
V_26 = F_10 () ;
V_27 = F_2 ( V_2 ) -> V_15 -> V_28
+ F_11 ( V_29 ) ;
if ( F_12 ( V_27 , V_26 ) )
V_27 -= V_26 ;
else
V_27 = 0 ;
F_13 ( V_30 , V_25 , V_27 ) ;
}

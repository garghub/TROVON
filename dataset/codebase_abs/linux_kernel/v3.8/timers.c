static T_1 F_1 ( int V_1 , void * V_2 )
{
V_3 &= 0 ;
V_4 += V_5 ;
return F_2 ( V_1 , V_2 ) ;
}
static T_2 F_3 ( struct V_6 * V_7 )
{
unsigned long V_8 ;
T_3 V_9 ;
F_4 ( V_8 ) ;
V_9 = V_4 + V_10 ;
F_5 ( V_8 ) ;
return V_9 ;
}
void F_6 ( T_4 V_11 )
{
V_12 = 0 ;
F_7 ( V_13 , & V_14 ) ;
V_12 = V_15 | V_16 | V_17 ;
V_18 = V_19 ;
V_20 = V_5 ;
V_12 |= V_21 ;
F_8 ( & V_22 , V_5 * V_23 ) ;
F_2 = V_11 ;
}
int F_9 ( int V_24 , struct V_25 * V_26 )
{
if ( ! V_24 ) {
long V_27 = V_28 ;
V_26 -> V_29 = V_26 -> V_30 = V_26 -> V_31 = 1 ;
V_26 -> V_32 = ( V_27 >> 24 ) % 24 ;
V_26 -> V_33 = ( V_27 >> 16 ) % 60 ;
V_26 -> V_34 = V_27 % 60 ;
}
return 0 ;
}

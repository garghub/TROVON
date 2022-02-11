static inline int F_1 ( T_1 V_1 )
{
const T_1 V_2 = V_3 | V_3 ;
return ( ( V_1 & V_2 ) == V_2 ) ;
}
static void F_2 ( struct V_4 * V_5 )
{
void T_2 * V_6 ;
T_1 T_2 * V_7 ;
T_1 T_2 * V_8 ;
T_1 V_1 = 0 ;
int V_9 ;
if ( ! F_3 ( V_10 ) &&
! F_3 ( V_11 ) )
return;
V_6 = F_4 ( F_5 ( V_5 , 0 ) ,
F_6 ( V_5 , 0 ) ) ;
if ( ! V_6 ) {
F_7 ( V_12 L_1 ) ;
return;
}
V_7 = V_6 + V_13 ;
V_8 = V_6 + V_14 ;
V_1 |= V_15 ;
F_8 ( V_7 , V_1 ) ;
V_1 |= V_16 ;
F_8 ( V_7 , V_1 ) ;
F_9 ( 10 ) ;
V_1 |= V_17 ;
F_8 ( V_7 , V_1 ) ;
F_9 ( 50 ) ;
V_1 |= V_18 ;
F_8 ( V_7 , V_1 ) ;
V_1 |= ( V_3 | V_19 ) ;
F_8 ( V_7 , V_1 ) ;
V_9 = 0 ;
while ( ! F_1 ( F_10 ( V_7 ) ) ) {
F_9 ( 10 ) ;
if ( V_9 ++ > V_20 ) {
F_7 ( V_12 L_2 ,
F_10 ( V_7 ) ) ;
break;
}
}
F_8 ( V_8 , V_21 ) ;
F_11 ( V_6 ) ;
}

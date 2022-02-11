static bool F_1 ( struct V_1 * V_2 , void T_1 * V_3 , T_2 V_4 ,
T_2 V_5 , int V_6 )
{
unsigned long V_7 = V_8 + V_6 ;
T_2 V_9 ;
do {
V_9 = F_2 ( V_3 ) ;
if ( ( V_9 & V_4 ) == V_5 )
return true ;
F_3 () ;
F_4 ( 10 ) ;
} while ( ! F_5 ( V_8 , V_7 ) );
F_6 ( V_2 , L_1 , V_3 ) ;
return false ;
}
void F_7 ( struct V_10 * V_11 , T_2 V_12 , T_2 V_5 )
{
struct V_1 * V_2 = V_11 -> V_13 -> V_2 ;
void T_1 * V_14 = V_11 -> V_14 ;
F_8 ( V_12 , V_14 + V_15 ) ;
F_1 ( V_2 , V_14 + V_15 , 0x0100 , 0x0000 , 100 ) ;
F_8 ( V_5 , V_14 + V_16 ) ;
F_1 ( V_2 , V_14 + V_15 , 0x0100 , 0x0000 , 100 ) ;
}
int F_9 ( struct V_10 * V_11 )
{
if ( V_11 -> V_17 )
return 0 ;
V_11 -> V_17 = 1 ;
V_11 -> V_14 = F_10 ( V_11 -> V_13 -> V_18 [ 1 ] , V_19 ) ;
if ( ! V_11 -> V_14 )
return - V_20 ;
return 0 ;
}
void F_11 ( struct V_10 * V_11 )
{
if ( V_11 -> V_14 )
F_12 ( V_11 -> V_14 ) ;
}

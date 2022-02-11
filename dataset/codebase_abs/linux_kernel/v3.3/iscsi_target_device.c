int F_1 (
struct V_1 * V_2 ,
T_1 V_3 )
{
T_2 V_4 = F_2 ( (struct V_5 * ) & V_3 ) ;
return F_3 ( & V_2 -> V_6 , V_4 ) ;
}
int F_4 (
struct V_1 * V_2 ,
unsigned char * V_7 ,
T_1 V_3 )
{
T_2 V_4 = F_2 ( (struct V_5 * ) & V_3 ) ;
return F_5 ( & V_2 -> V_6 , V_4 ) ;
}
void F_6 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
if ( V_9 -> V_12 -> V_13 )
return;
V_11 = V_9 -> V_14 -> V_10 ;
V_9 -> V_15 = V_11 -> V_16 ;
V_9 -> V_17 = ( V_9 -> V_17 + V_11 -> V_16 ) - 1 ;
}
void F_7 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
if ( V_2 -> V_18 || V_2 -> V_19 )
return;
V_2 -> V_19 = 1 ;
F_8 ( & V_9 -> V_20 ) ;
V_9 -> V_17 += 1 ;
F_9 ( L_1 , V_9 -> V_17 ) ;
F_10 ( & V_9 -> V_20 ) ;
}

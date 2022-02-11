struct V_1 * F_1 ( unsigned long V_2 ,
unsigned long V_3 ,
bool V_4 )
{
int V_5 ;
unsigned long V_6 , V_7 ;
unsigned long V_8 ;
struct V_1 * V_9 ;
V_6 = V_2 >> V_10 ;
V_7 = ( V_2 + V_3 - 1 ) >> V_10 ;
V_8 = V_7 - V_6 + 1 ;
V_9 = F_2 ( V_8 ) ;
if ( ! V_9 )
return F_3 ( - V_11 ) ;
V_5 = F_4 ( V_2 , V_8 , V_4 , 1 , V_9 ) ;
if ( V_5 < 0 )
goto V_12;
if ( V_5 != V_8 ) {
V_5 = - V_13 ;
goto V_14;
}
return V_9 ;
V_14:
F_5 ( V_9 ) ;
V_12:
F_6 ( V_9 ) ;
return F_3 ( V_5 ) ;
}
void F_7 ( struct V_1 * V_9 )
{
F_5 ( V_9 ) ;
F_6 ( V_9 ) ;
}
static void F_8 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
F_9 ( L_1 ,
V_20 , V_18 , F_10 ( V_18 -> V_21 ) , V_16 -> V_22 ,
V_16 -> V_23 ) ;
F_11 ( V_18 -> V_21 ) ;
}
static void F_12 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
F_9 ( L_1 ,
V_20 , V_18 , F_10 ( V_18 -> V_21 ) , V_16 -> V_22 ,
V_16 -> V_23 ) ;
V_18 -> V_24 ( V_18 -> V_25 ) ;
}

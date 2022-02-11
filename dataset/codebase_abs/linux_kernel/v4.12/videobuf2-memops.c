struct V_1 * F_1 ( unsigned long V_2 ,
unsigned long V_3 ,
bool V_4 )
{
int V_5 ;
unsigned long V_6 , V_7 ;
unsigned long V_8 ;
struct V_1 * V_9 ;
unsigned int V_10 = V_11 ;
if ( V_4 )
V_10 |= V_12 ;
V_6 = V_2 >> V_13 ;
V_7 = ( V_2 + V_3 - 1 ) >> V_13 ;
V_8 = V_7 - V_6 + 1 ;
V_9 = F_2 ( V_8 ) ;
if ( ! V_9 )
return F_3 ( - V_14 ) ;
V_5 = F_4 ( V_2 & V_15 , V_8 , V_10 , V_9 ) ;
if ( V_5 < 0 )
goto V_16;
if ( V_5 != V_8 ) {
V_5 = - V_17 ;
goto V_18;
}
return V_9 ;
V_18:
F_5 ( V_9 ) ;
V_16:
F_6 ( V_9 ) ;
return F_3 ( V_5 ) ;
}
void F_7 ( struct V_1 * V_9 )
{
F_5 ( V_9 ) ;
F_6 ( V_9 ) ;
}
static void F_8 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_23 ;
F_9 ( L_1 ,
V_24 , V_22 , F_10 ( V_22 -> V_25 ) , V_20 -> V_26 ,
V_20 -> V_27 ) ;
F_11 ( V_22 -> V_25 ) ;
}
static void F_12 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_23 ;
F_9 ( L_1 ,
V_24 , V_22 , F_10 ( V_22 -> V_25 ) , V_20 -> V_26 ,
V_20 -> V_27 ) ;
V_22 -> V_28 ( V_22 -> V_29 ) ;
}

static void F_1 ( struct V_1 * V_2 , void T_1 * V_3 ,
void T_1 * V_4 )
{
unsigned int V_5 ;
V_5 = F_2 ( V_3 ) ;
V_5 &= ~ F_3 ( 0 ) ;
F_4 ( V_5 , V_3 ) ;
V_5 = F_5 ( V_6 + 1 ) | F_6 ( 1 ) |
F_7 ( 4 ) | F_8 ( 1 ) | F_9 ( 3 ) |
F_10 ( 1 ) ;
F_4 ( V_5 , V_4 + V_7 ) ;
}
static int F_11 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_9 -> V_2 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
void T_1 * V_3 ;
int V_14 ;
V_11 = F_12 ( V_9 ) ;
if ( F_13 ( V_11 ) )
return F_14 ( V_11 ) ;
V_14 = F_15 ( V_11 ) ;
if ( V_14 )
return V_14 ;
V_13 = F_16 ( V_9 , V_15 , 1 ) ;
if ( ! V_13 )
goto V_16;
V_3 = F_17 ( V_2 , V_13 -> V_17 , F_18 ( V_13 ) ) ;
if ( ! V_3 )
goto V_16;
F_1 ( V_2 , V_3 , V_11 -> V_18 ) ;
V_14 = F_19 ( V_9 , V_11 , & V_19 ,
0 , 0 , 0 ) ;
if ( V_14 )
goto V_16;
return 0 ;
V_16:
F_20 ( V_11 ) ;
return V_14 ;
}

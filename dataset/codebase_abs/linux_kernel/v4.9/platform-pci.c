static unsigned long F_1 ( unsigned long V_1 )
{
unsigned long V_2 ;
V_2 = V_3 + V_4 ;
V_4 += V_1 ;
F_2 ( V_4 > V_5 ) ;
return V_2 ;
}
static int F_3 ( struct V_6 * V_7 ,
const struct V_8 * V_9 )
{
int V_10 , V_11 ;
long V_12 ;
long V_13 , V_14 ;
unsigned int V_15 ;
unsigned long V_16 ;
if ( ! F_4 () )
return - V_17 ;
V_10 = F_5 ( V_7 ) ;
if ( V_10 )
return V_10 ;
V_12 = F_6 ( V_7 , 0 ) ;
V_13 = F_6 ( V_7 , 1 ) ;
V_14 = F_7 ( V_7 , 1 ) ;
if ( V_13 == 0 || V_12 == 0 ) {
F_8 ( & V_7 -> V_18 , L_1 ) ;
V_11 = - V_19 ;
goto V_20;
}
V_11 = F_9 ( V_7 , 1 , V_21 ) ;
if ( V_11 < 0 )
goto V_20;
V_11 = F_9 ( V_7 , 0 , V_21 ) ;
if ( V_11 < 0 )
goto V_22;
V_3 = V_13 ;
V_5 = V_14 ;
V_15 = F_10 () ;
V_16 = F_1 ( V_23 * V_15 ) ;
V_11 = F_11 ( V_16 ) ;
if ( V_11 )
goto V_24;
V_11 = F_12 () ;
if ( V_11 )
goto V_25;
F_13 ( NULL ) ;
return 0 ;
V_25:
F_14 () ;
V_24:
F_15 ( V_7 , 0 ) ;
V_22:
F_15 ( V_7 , 1 ) ;
V_20:
F_16 ( V_7 ) ;
return V_11 ;
}
static int T_1 F_17 ( void )
{
return F_18 ( & V_26 ) ;
}

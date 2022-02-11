static int F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 )
return - V_4 ;
return 0 ;
}
static struct V_1 * F_2 ( struct V_1 * V_2 ,
T_1 V_5 )
{
struct V_1 * V_6 = F_3 ( - V_4 ) ;
T_1 V_7 ;
int V_8 = V_9 ;
struct V_10 * V_11 ;
int V_12 = V_2 -> V_12 ;
T_2 V_13 = V_2 -> V_13 ;
int V_14 ;
bool V_15 ;
if ( F_4 ( F_5 ( V_2 ) -> V_16 &
~ ( V_17 |
V_18 |
V_19 |
V_20 |
V_21 |
V_22 ) ) )
goto V_23;
if ( F_4 ( ! F_6 ( V_2 , sizeof( * V_11 ) ) ) )
goto V_23;
V_11 = (struct V_10 * ) F_7 ( V_2 ) ;
if ( V_11 -> V_24 & V_25 )
V_8 += V_9 ;
if ( V_11 -> V_24 & V_26 )
V_8 += V_9 ;
if ( V_11 -> V_24 & V_27 ) {
V_8 += V_9 ;
V_15 = true ;
} else
V_15 = false ;
V_2 -> V_13 = V_11 -> V_13 ;
V_2 -> V_3 = 0 ;
if ( F_4 ( ! F_6 ( V_2 , V_8 ) ) )
goto V_23;
F_8 ( V_2 , V_8 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 , F_11 ( V_2 ) ) ;
V_2 -> V_12 = F_11 ( V_2 ) ;
V_7 = V_2 -> V_28 -> V_29 & F_12 ( V_2 ) ;
V_6 = F_13 ( V_2 , V_7 ) ;
if ( ! V_6 || F_14 ( V_6 ) )
goto V_23;
V_2 = V_6 ;
V_14 = F_15 ( V_2 ) ;
do {
F_16 ( V_2 , V_8 ) ;
if ( V_15 ) {
T_3 * V_30 ;
if ( F_17 ( V_2 ) ) {
int V_31 ;
V_31 = F_18 ( V_2 ) ;
if ( V_31 ) {
F_19 ( V_6 ) ;
V_6 = F_3 ( V_31 ) ;
goto V_23;
}
}
V_11 = (struct V_10 * ) ( V_2 -> V_32 ) ;
V_30 = ( T_3 * ) ( V_11 + 1 ) ;
* V_30 = 0 ;
* ( V_33 * ) V_30 = F_20 ( F_21 ( V_2 , 0 , V_2 -> V_34 , 0 ) ) ;
}
F_16 ( V_2 , V_14 - V_8 ) ;
F_22 ( V_2 ) ;
V_2 -> V_3 = 1 ;
F_9 ( V_2 ) ;
F_10 ( V_2 , V_12 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_13 = V_13 ;
} while ( ( V_2 = V_2 -> V_35 ) );
V_23:
return V_6 ;
}
int T_4 F_23 ( void )
{
return F_24 ( & V_36 , V_37 ) ;
}
void T_5 F_25 ( void )
{
F_26 ( & V_36 , V_37 ) ;
}

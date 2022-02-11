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
T_2 V_12 = V_2 -> V_13 ;
int V_14 = V_2 -> V_14 ;
T_3 V_15 = V_2 -> V_15 ;
int V_16 ;
bool V_17 ;
if ( F_4 ( F_5 ( V_2 ) -> V_18 &
~ ( V_19 |
V_20 |
V_21 |
V_22 |
V_23 |
V_24 |
V_25 ) ) )
goto V_26;
if ( F_4 ( ! F_6 ( V_2 , sizeof( * V_11 ) ) ) )
goto V_26;
V_11 = (struct V_10 * ) F_7 ( V_2 ) ;
if ( V_11 -> V_27 & V_28 )
V_8 += V_9 ;
if ( V_11 -> V_27 & V_29 )
V_8 += V_9 ;
if ( V_11 -> V_27 & V_30 ) {
V_8 += V_9 ;
V_17 = true ;
} else
V_17 = false ;
if ( F_4 ( ! F_6 ( V_2 , V_8 ) ) )
goto V_26;
V_2 -> V_15 = V_11 -> V_15 ;
V_2 -> V_3 = 0 ;
F_8 ( V_2 , V_8 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 , F_11 ( V_2 ) ) ;
V_2 -> V_14 = F_11 ( V_2 ) ;
V_7 = V_2 -> V_31 -> V_32 & F_12 ( V_2 ) ;
V_6 = F_13 ( V_2 , V_7 ) ;
if ( ! V_6 || F_14 ( V_6 ) ) {
F_15 ( V_2 , V_15 , V_8 , V_12 , V_14 ) ;
goto V_26;
}
V_2 = V_6 ;
V_16 = F_16 ( V_2 ) ;
do {
F_17 ( V_2 , V_8 ) ;
if ( V_17 ) {
T_4 * V_33 ;
if ( F_18 ( V_2 ) ) {
int V_34 ;
V_34 = F_19 ( V_2 ) ;
if ( V_34 ) {
F_20 ( V_6 ) ;
V_6 = F_3 ( V_34 ) ;
goto V_26;
}
}
V_11 = (struct V_10 * ) ( V_2 -> V_35 ) ;
V_33 = ( T_4 * ) ( V_11 + 1 ) ;
* V_33 = 0 ;
* ( V_36 * ) V_33 = F_21 ( F_22 ( V_2 , 0 , V_2 -> V_37 , 0 ) ) ;
}
F_17 ( V_2 , V_16 - V_8 ) ;
F_23 ( V_2 ) ;
V_2 -> V_3 = 1 ;
F_9 ( V_2 ) ;
F_10 ( V_2 , V_14 ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_15 = V_15 ;
} while ( ( V_2 = V_2 -> V_38 ) );
V_26:
return V_6 ;
}
int T_5 F_24 ( void )
{
return F_25 ( & V_39 , V_40 ) ;
}
void T_6 F_26 ( void )
{
F_27 ( & V_39 , V_40 ) ;
}

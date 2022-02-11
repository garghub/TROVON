static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = ( void * ) V_2 -> V_6 ;
int V_7 , V_8 , V_9 = 0 ;
for ( V_8 = 0 ; V_8 < 20 ; V_8 ++ ) {
V_7 = ( F_2 ( V_5 -> V_10 + V_11 ) &
V_12 ) ;
if ( ! V_7 || ! V_3 ) {
V_9 = 1 ;
break;
}
F_3 ( 10 ) ;
}
return V_9 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 * V_13 )
{
struct V_4 * V_5 = ( void * ) V_2 -> V_6 ;
* V_13 = F_2 ( V_5 -> V_10 + V_14 ) ;
return 4 ;
}
static void F_5 ( struct V_4 * V_5 , bool V_15 )
{
T_1 V_16 ;
V_16 = F_6 ( V_5 -> V_17 + V_18 ) ;
if ( V_15 )
V_16 |= V_19 ;
else
V_16 &= ~ V_19 ;
F_7 ( V_16 , V_5 -> V_17 + V_18 ) ;
}
void F_8 ( struct V_20 * V_21 )
{
struct V_4 * V_5 = V_21 -> V_5 ;
struct V_22 * V_23 = NULL ;
struct V_1 * V_2 = NULL ;
int V_24 ;
V_23 = F_9 ( NULL , V_25 ) ;
if ( ! V_23 || ! F_10 ( V_23 ) )
return;
V_5 -> V_10 = F_11 ( V_23 , 0 ) ;
F_12 ( V_23 ) ;
if ( ! V_5 -> V_10 )
goto V_26;
V_2 = F_13 ( sizeof( * V_2 ) , V_27 ) ;
if ( ! V_2 )
goto V_26;
V_2 -> V_28 = V_29 ;
V_2 -> V_30 = F_1 ;
V_2 -> V_31 = F_4 ;
V_2 -> V_6 = ( unsigned long ) V_5 ;
V_21 -> V_23 = V_2 ;
F_5 ( V_5 , true ) ;
F_14 ( V_5 -> V_10 + V_32 , V_33 ) ;
V_24 = F_15 ( V_21 -> V_34 , V_21 -> V_23 ) ;
if ( V_24 ) {
F_5 ( V_5 , false ) ;
F_16 ( V_21 -> V_34 , L_1 ,
V_24 ) ;
goto V_26;
}
return;
V_26:
F_12 ( V_23 ) ;
F_17 ( V_5 -> V_10 ) ;
F_18 ( V_2 ) ;
V_5 -> V_10 = NULL ;
V_21 -> V_23 = NULL ;
}
void F_19 ( struct V_20 * V_21 )
{
if ( V_21 && V_21 -> V_23 ) {
struct V_4 * V_5 = V_21 -> V_5 ;
F_20 ( V_21 -> V_34 , V_21 -> V_23 ) ;
F_5 ( V_5 , false ) ;
F_17 ( V_5 -> V_10 ) ;
F_18 ( V_21 -> V_23 ) ;
}
}

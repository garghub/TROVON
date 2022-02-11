static struct V_1 * F_1 ( struct V_2 * V_2 , struct V_3 * V_4 )
{
char * V_5 ;
if ( ! V_4 -> V_6 [ V_7 ] )
return NULL ;
V_5 = F_2 ( V_4 -> V_6 [ V_7 ] ) ;
F_3 ( 5 , L_1 , V_8 , V_5 ) ;
return F_4 ( V_2 , V_5 ) ;
}
static int F_5 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_1 * V_11 ;
struct V_12 * V_13 ;
T_1 V_14 ;
if ( ! V_4 -> V_6 [ V_15 ] )
return - V_16 ;
V_14 = F_6 ( V_4 -> V_6 [ V_15 ] ) ;
F_3 ( 5 , L_2 , V_8 , V_14 ) ;
V_11 = F_1 ( & V_17 , V_4 ) ;
if ( ! V_11 )
return - V_18 ;
V_13 = (struct V_12 * ) V_11 -> V_19 ;
if ( ! V_13 ) {
F_7 ( V_11 ) ;
return - V_18 ;
}
V_13 -> V_14 = V_14 ;
F_7 ( V_11 ) ;
return 0 ;
}
static int F_8 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
struct V_1 * V_11 ;
struct V_12 * V_13 ;
struct V_9 * V_20 ;
void * V_21 ;
int V_22 = - V_23 ;
V_11 = F_1 ( & V_17 , V_4 ) ;
if ( ! V_11 )
return - V_18 ;
V_20 = F_9 ( V_24 , V_25 ) ;
if ( ! V_20 ) {
F_7 ( V_11 ) ;
return - V_26 ;
}
V_13 = (struct V_12 * ) V_11 -> V_19 ;
if ( ! V_13 ) {
V_22 = - V_18 ;
goto V_27;
}
V_21 = F_10 ( V_20 , V_4 -> V_28 , V_4 -> V_29 ,
& V_30 , 0 , V_31 ) ;
if ( V_21 == NULL ) {
V_22 = - V_32 ;
goto V_27;
}
if( F_11 ( V_20 , V_7 ,
V_11 -> V_33 ) )
goto V_27;
if( F_12 ( V_20 , V_15 , V_13 -> V_14 ) )
goto V_27;
F_13 ( V_20 , V_21 ) ;
return F_14 ( V_20 , V_4 ) ;
V_27:
F_15 ( V_20 ) ;
F_7 ( V_11 ) ;
return V_22 ;
}
int F_16 ( void )
{
return F_17 ( & V_30 ,
V_34 , F_18 ( V_34 ) ) ;
}
void F_19 ( void )
{
F_20 ( & V_30 ) ;
}

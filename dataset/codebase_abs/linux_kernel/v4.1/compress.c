void F_1 ( const struct V_1 * V_2 , const void * V_3 ,
int V_4 , void * V_5 , int * V_6 , int * V_7 )
{
int V_8 ;
struct V_9 * V_10 = V_11 [ * V_7 ] ;
if ( * V_7 == V_12 )
goto V_13;
if ( V_4 < V_14 )
goto V_13;
if ( V_10 -> V_15 )
F_2 ( V_10 -> V_15 ) ;
V_8 = F_3 ( V_10 -> V_16 , V_3 , V_4 , V_5 ,
( unsigned int * ) V_6 ) ;
if ( V_10 -> V_15 )
F_4 ( V_10 -> V_15 ) ;
if ( F_5 ( V_8 ) ) {
F_6 ( V_2 , L_1 ,
V_4 , V_10 -> V_17 , V_8 ) ;
goto V_13;
}
if ( V_4 - * V_6 < V_18 )
goto V_13;
return;
V_13:
memcpy ( V_5 , V_3 , V_4 ) ;
* V_6 = V_4 ;
* V_7 = V_12 ;
}
int F_7 ( const struct V_1 * V_2 , const void * V_3 ,
int V_4 , void * V_5 , int * V_6 , int V_7 )
{
int V_8 ;
struct V_9 * V_10 ;
if ( F_5 ( V_7 < 0 || V_7 >= V_19 ) ) {
F_8 ( V_2 , L_2 , V_7 ) ;
return - V_20 ;
}
V_10 = V_11 [ V_7 ] ;
if ( F_5 ( ! V_10 -> V_21 ) ) {
F_8 ( V_2 , L_3 , V_10 -> V_17 ) ;
return - V_20 ;
}
if ( V_7 == V_12 ) {
memcpy ( V_5 , V_3 , V_4 ) ;
* V_6 = V_4 ;
return 0 ;
}
if ( V_10 -> V_22 )
F_2 ( V_10 -> V_22 ) ;
V_8 = F_9 ( V_10 -> V_16 , V_3 , V_4 , V_5 ,
( unsigned int * ) V_6 ) ;
if ( V_10 -> V_22 )
F_4 ( V_10 -> V_22 ) ;
if ( V_8 )
F_8 ( V_2 , L_4 ,
V_4 , V_10 -> V_17 , V_8 ) ;
return V_8 ;
}
static int T_1 F_10 ( struct V_9 * V_10 )
{
if ( V_10 -> V_21 ) {
V_10 -> V_16 = F_11 ( V_10 -> V_21 , 0 , 0 ) ;
if ( F_12 ( V_10 -> V_16 ) ) {
F_13 ( L_5 ,
V_23 -> V_24 , V_10 -> V_17 , F_14 ( V_10 -> V_16 ) ) ;
return F_14 ( V_10 -> V_16 ) ;
}
}
V_11 [ V_10 -> V_7 ] = V_10 ;
return 0 ;
}
static void F_15 ( struct V_9 * V_10 )
{
if ( V_10 -> V_21 )
F_16 ( V_10 -> V_16 ) ;
return;
}
int T_1 F_17 ( void )
{
int V_8 ;
V_8 = F_10 ( & V_25 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_10 ( & V_26 ) ;
if ( V_8 )
goto V_27;
V_11 [ V_12 ] = & V_28 ;
return 0 ;
V_27:
F_15 ( & V_25 ) ;
return V_8 ;
}
void F_18 ( void )
{
F_15 ( & V_25 ) ;
F_15 ( & V_26 ) ;
}

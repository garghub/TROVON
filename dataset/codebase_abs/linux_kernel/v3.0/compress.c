void F_1 ( const void * V_1 , int V_2 , void * V_3 , int * V_4 ,
int * V_5 )
{
int V_6 ;
struct V_7 * V_8 = V_9 [ * V_5 ] ;
if ( * V_5 == V_10 )
goto V_11;
if ( V_2 < V_12 )
goto V_11;
if ( V_8 -> V_13 )
F_2 ( V_8 -> V_13 ) ;
V_6 = F_3 ( V_8 -> V_14 , V_1 , V_2 , V_3 ,
( unsigned int * ) V_4 ) ;
if ( V_8 -> V_13 )
F_4 ( V_8 -> V_13 ) ;
if ( F_5 ( V_6 ) ) {
F_6 ( L_1
L_2 ,
V_2 , V_8 -> V_15 , V_6 ) ;
goto V_11;
}
if ( V_2 - * V_4 < V_16 )
goto V_11;
return;
V_11:
memcpy ( V_3 , V_1 , V_2 ) ;
* V_4 = V_2 ;
* V_5 = V_10 ;
}
int F_7 ( const void * V_1 , int V_2 , void * V_3 ,
int * V_4 , int V_5 )
{
int V_6 ;
struct V_7 * V_8 ;
if ( F_5 ( V_5 < 0 || V_5 >= V_17 ) ) {
F_8 ( L_3 , V_5 ) ;
return - V_18 ;
}
V_8 = V_9 [ V_5 ] ;
if ( F_5 ( ! V_8 -> V_19 ) ) {
F_8 ( L_4 , V_8 -> V_15 ) ;
return - V_18 ;
}
if ( V_5 == V_10 ) {
memcpy ( V_3 , V_1 , V_2 ) ;
* V_4 = V_2 ;
return 0 ;
}
if ( V_8 -> V_20 )
F_2 ( V_8 -> V_20 ) ;
V_6 = F_9 ( V_8 -> V_14 , V_1 , V_2 , V_3 ,
( unsigned int * ) V_4 ) ;
if ( V_8 -> V_20 )
F_4 ( V_8 -> V_20 ) ;
if ( V_6 )
F_8 ( L_5
L_6 , V_2 , V_8 -> V_15 , V_6 ) ;
return V_6 ;
}
static int T_1 F_10 ( struct V_7 * V_8 )
{
if ( V_8 -> V_19 ) {
V_8 -> V_14 = F_11 ( V_8 -> V_19 , 0 , 0 ) ;
if ( F_12 ( V_8 -> V_14 ) ) {
F_8 ( L_7 ,
V_8 -> V_15 , F_13 ( V_8 -> V_14 ) ) ;
return F_13 ( V_8 -> V_14 ) ;
}
}
V_9 [ V_8 -> V_5 ] = V_8 ;
return 0 ;
}
static void F_14 ( struct V_7 * V_8 )
{
if ( V_8 -> V_19 )
F_15 ( V_8 -> V_14 ) ;
return;
}
int T_1 F_16 ( void )
{
int V_6 ;
V_6 = F_10 ( & V_21 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_10 ( & V_22 ) ;
if ( V_6 )
goto V_23;
V_9 [ V_10 ] = & V_24 ;
return 0 ;
V_23:
F_14 ( & V_21 ) ;
return V_6 ;
}
void F_17 ( void )
{
F_14 ( & V_21 ) ;
F_14 ( & V_22 ) ;
}

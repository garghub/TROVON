static int F_1 ( unsigned int V_1 )
{
struct V_2 * V_3 = V_4 -> V_3 ;
int V_5 ;
for ( V_5 = 0 ;
V_3 [ V_5 ] . V_6 != V_7 ; V_5 ++ )
if ( V_3 [ V_5 ] . V_6 == V_1 )
break;
if ( V_3 [ V_5 ] . V_6 == V_7 )
return - V_8 ;
return V_5 ;
}
static int F_2 ( unsigned int V_9 )
{
struct V_2 * V_3 = V_4 -> V_3 ;
unsigned int * V_10 = V_4 -> V_10 ;
struct V_11 * V_12 = F_3 ( 0 ) ;
unsigned int V_13 , V_14 = 0 ;
unsigned int V_15 = V_4 -> V_15 ;
unsigned int V_16 ;
int V_5 , V_17 ;
int V_18 = 0 ;
V_16 = V_12 -> V_19 ;
V_17 = F_1 ( V_16 ) ;
if ( V_17 < 0 ) {
V_18 = V_17 ;
goto V_20;
}
V_5 = F_1 ( V_9 ) ;
if ( V_5 < 0 ) {
V_18 = V_5 ;
goto V_20;
}
if ( V_4 -> V_21 != NULL ) {
if ( V_4 -> V_21 ( V_17 , V_5 ) &&
( V_3 [ V_5 ] . V_6 < V_15 ) &&
( V_3 [ V_17 ] . V_6 < V_15 ) )
V_14 = V_10 [ V_4 -> V_22 ] ;
}
V_13 = V_10 [ V_5 ] ;
if ( ( V_9 > V_16 ) && ! V_14 ) {
V_18 = F_4 ( V_23 , V_13 , V_13 ) ;
if ( V_18 ) {
F_5 ( L_1 ,
V_24 , V_13 ) ;
return V_18 ;
}
}
if ( V_14 ) {
V_18 = F_4 ( V_23 , V_14 ,
V_14 ) ;
if ( V_18 ) {
F_5 ( L_1 ,
V_24 , V_14 ) ;
return V_18 ;
}
}
V_4 -> V_25 ( V_17 , V_5 ) ;
if ( ( V_9 < V_16 ) ||
( ( V_9 > V_16 ) && V_14 ) ) {
V_18 = F_4 ( V_23 , V_13 ,
V_13 ) ;
if ( V_18 ) {
F_5 ( L_1 ,
V_24 , V_13 ) ;
goto V_20;
}
}
V_20:
F_6 ( V_12 ) ;
return V_18 ;
}
static int F_7 ( struct V_11 * V_12 , unsigned int V_5 )
{
return F_2 ( V_4 -> V_3 [ V_5 ] . V_6 ) ;
}
static int F_8 ( struct V_11 * V_12 )
{
V_12 -> V_26 = V_4 -> V_27 ;
V_12 -> V_28 = V_29 ;
return F_9 ( V_12 , V_4 -> V_3 , 100000 ) ;
}
static int F_10 ( struct V_30 * V_31 )
{
int V_18 = - V_8 ;
V_4 = F_11 ( sizeof( * V_4 ) , V_32 ) ;
if ( ! V_4 )
return - V_33 ;
if ( F_12 () )
V_18 = F_13 ( V_4 ) ;
else if ( F_14 () || F_15 () )
V_18 = F_16 ( V_4 ) ;
else if ( F_17 () )
V_18 = F_18 ( V_4 ) ;
else
return 0 ;
if ( V_18 )
goto V_34;
if ( V_4 -> V_25 == NULL ) {
F_5 ( L_2 , V_24 ) ;
goto V_34;
}
V_23 = F_19 ( NULL , L_3 ) ;
if ( F_20 ( V_23 ) ) {
F_5 ( L_4 , V_24 ) ;
goto V_34;
}
V_29 = F_21 ( V_4 -> V_27 ) / 1000 ;
if ( ! F_22 ( & V_35 ) )
return 0 ;
F_5 ( L_5 , V_24 ) ;
F_23 ( V_23 ) ;
V_34:
F_24 ( V_4 ) ;
return - V_8 ;
}

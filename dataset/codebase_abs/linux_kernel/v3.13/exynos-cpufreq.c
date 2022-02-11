static unsigned int F_1 ( unsigned int V_1 )
{
return F_2 ( V_2 -> V_3 ) / 1000 ;
}
static int F_3 ( unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
for ( V_7 = 0 ;
V_6 [ V_7 ] . V_8 != V_9 ; V_7 ++ )
if ( V_6 [ V_7 ] . V_8 == V_4 )
break;
if ( V_6 [ V_7 ] . V_8 == V_9 )
return - V_10 ;
return V_7 ;
}
static int F_4 ( unsigned int V_11 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned int * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_5 ( 0 ) ;
unsigned int V_15 , V_16 = 0 ;
unsigned int V_17 = V_2 -> V_17 ;
unsigned int V_18 ;
int V_7 , V_19 ;
int V_20 = 0 ;
V_18 = V_14 -> V_21 ;
V_19 = F_3 ( V_18 ) ;
if ( V_19 < 0 ) {
V_20 = V_19 ;
goto V_22;
}
V_7 = F_3 ( V_11 ) ;
if ( V_7 < 0 ) {
V_20 = V_7 ;
goto V_22;
}
if ( V_2 -> V_23 != NULL ) {
if ( V_2 -> V_23 ( V_19 , V_7 ) &&
( V_6 [ V_7 ] . V_8 < V_17 ) &&
( V_6 [ V_19 ] . V_8 < V_17 ) )
V_16 = V_12 [ V_2 -> V_24 ] ;
}
V_15 = V_12 [ V_7 ] ;
if ( ( V_11 > V_18 ) && ! V_16 ) {
V_20 = F_6 ( V_25 , V_15 , V_15 ) ;
if ( V_20 ) {
F_7 ( L_1 ,
V_26 , V_15 ) ;
return V_20 ;
}
}
if ( V_16 ) {
V_20 = F_6 ( V_25 , V_16 ,
V_16 ) ;
if ( V_20 ) {
F_7 ( L_1 ,
V_26 , V_16 ) ;
return V_20 ;
}
}
V_2 -> V_27 ( V_19 , V_7 ) ;
if ( ( V_11 < V_18 ) ||
( ( V_11 > V_18 ) && V_16 ) ) {
V_20 = F_6 ( V_25 , V_15 ,
V_15 ) ;
if ( V_20 ) {
F_7 ( L_1 ,
V_26 , V_15 ) ;
goto V_22;
}
}
V_22:
F_8 ( V_14 ) ;
return V_20 ;
}
static int F_9 ( struct V_13 * V_14 , unsigned int V_7 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_20 = 0 ;
F_10 ( & V_28 ) ;
if ( V_29 )
goto V_22;
V_20 = F_4 ( V_6 [ V_7 ] . V_8 ) ;
V_22:
F_11 ( & V_28 ) ;
return V_20 ;
}
static int F_12 ( struct V_13 * V_14 )
{
return 0 ;
}
static int F_13 ( struct V_13 * V_14 )
{
return 0 ;
}
static int F_14 ( struct V_30 * V_31 ,
unsigned long V_32 , void * V_33 )
{
int V_20 ;
switch ( V_32 ) {
case V_34 :
F_10 ( & V_28 ) ;
V_29 = true ;
F_11 ( & V_28 ) ;
V_20 = F_4 ( V_35 ) ;
if ( V_20 < 0 )
return V_36 ;
break;
case V_37 :
F_10 ( & V_28 ) ;
V_29 = false ;
F_11 ( & V_28 ) ;
break;
}
return V_38 ;
}
static int F_15 ( struct V_13 * V_14 )
{
return F_16 ( V_14 , V_2 -> V_6 , 100000 ) ;
}
static int T_1 F_17 ( void )
{
int V_20 = - V_10 ;
V_2 = F_18 ( sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 )
return - V_40 ;
if ( F_19 () )
V_20 = F_20 ( V_2 ) ;
else if ( F_21 () || F_22 () )
V_20 = F_23 ( V_2 ) ;
else if ( F_24 () )
V_20 = F_25 ( V_2 ) ;
else
return 0 ;
if ( V_20 )
goto V_41;
if ( V_2 -> V_27 == NULL ) {
F_7 ( L_2 , V_26 ) ;
goto V_41;
}
V_25 = F_26 ( NULL , L_3 ) ;
if ( F_27 ( V_25 ) ) {
F_7 ( L_4 , V_26 ) ;
goto V_41;
}
V_35 = F_1 ( 0 ) ;
F_28 ( & V_42 ) ;
if ( F_29 ( & V_43 ) ) {
F_7 ( L_5 , V_26 ) ;
goto V_44;
}
return 0 ;
V_44:
F_30 ( & V_42 ) ;
F_31 ( V_25 ) ;
V_41:
F_32 ( V_2 ) ;
return - V_10 ;
}

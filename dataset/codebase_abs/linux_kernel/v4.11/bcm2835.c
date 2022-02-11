static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
return 0 ;
}
static int F_3 ( struct V_3 * V_4 )
{
return F_1 ( V_4 -> V_5 ) ;
}
static int F_4 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_1 * * V_10 )
{
struct V_1 * V_2 ;
int V_11 ;
static struct V_12 V_13 = {
. V_14 = F_3 ,
} ;
* V_10 = NULL ;
V_2 = F_5 ( sizeof( * V_2 ) , V_15 ) ;
if ( ! V_2 )
return - V_16 ;
V_2 -> V_7 = V_7 ;
V_11 = F_6 ( V_7 , V_17 , V_2 , & V_13 ) ;
if ( V_11 < 0 ) {
F_1 ( V_2 ) ;
return V_11 ;
}
* V_10 = V_2 ;
return 0 ;
}
static int F_7 ( struct V_8 * V_9 )
{
struct V_4 * V_18 = & V_9 -> V_18 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
T_1 V_19 ;
int V_11 , V_20 ;
V_11 = F_8 ( V_18 -> V_21 , L_1 ,
& V_19 ) ;
if ( V_11 ) {
F_9 ( V_18 , L_2 ) ;
return V_11 ;
}
if ( V_19 == 0 || V_19 > V_22 ) {
V_19 = V_22 ;
F_10 ( V_18 , L_3 ,
V_19 ) ;
}
V_11 = F_11 ( & V_9 -> V_18 , - 1 , NULL , V_23 , 0 , & V_7 ) ;
if ( V_11 ) {
F_9 ( V_18 , L_4 ) ;
return V_11 ;
}
F_12 ( V_7 , V_18 ) ;
strcpy ( V_7 -> V_24 , L_5 ) ;
strcpy ( V_7 -> V_25 , L_6 ) ;
sprintf ( V_7 -> V_26 , L_7 , V_7 -> V_25 ) ;
V_11 = F_4 ( V_7 , V_9 , & V_2 ) ;
if ( V_11 < 0 ) {
F_9 ( V_18 , L_8 ) ;
goto V_27;
}
V_11 = F_13 ( V_2 ) ;
if ( V_11 < 0 ) {
F_9 ( V_18 , L_9 ) ;
goto V_27;
}
V_11 = F_14 ( V_2 ) ;
if ( V_11 < 0 ) {
F_9 ( V_18 , L_10 ) ;
goto V_27;
}
V_11 = F_15 ( V_2 ) ;
if ( V_11 < 0 ) {
F_9 ( V_18 , L_11 ) ;
goto V_27;
}
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ ) {
V_2 -> V_28 |= ( 1 << V_20 ) ;
V_2 -> V_9 [ V_20 ] = V_9 ;
}
V_11 = F_16 ( V_7 ) ;
if ( V_11 ) {
F_9 ( V_18 , L_12 ) ;
goto V_27;
}
V_29 = V_7 ;
V_30 = V_2 ;
F_17 ( V_9 , V_7 ) ;
F_18 ( L_13 , V_19 ) ;
return 0 ;
V_27:
F_19 ( V_7 ) ;
return V_11 ;
}
static int F_20 ( struct V_8 * V_9 )
{
int V_31 ;
void * V_32 ;
V_32 = F_21 ( V_9 ) ;
if ( V_32 == ( void * ) V_29 ) {
F_19 ( (struct V_6 * ) V_32 ) ;
V_29 = NULL ;
V_30 = NULL ;
} else {
V_31 = ( int ) ( long ) V_32 ;
if ( V_29 ) {
F_22 ( ! V_30 ) ;
V_31 = ( int ) ( long ) V_32 ;
F_22 ( ! V_31 || V_31 > V_22 ) ;
V_30 -> V_28 &= ~ ( 1 << V_31 ) ;
F_22 ( ! V_30 -> V_28 ) ;
}
}
F_17 ( V_9 , NULL ) ;
return 0 ;
}
static int F_23 ( struct V_8 * V_9 ,
T_2 V_33 )
{
return 0 ;
}
static int F_24 ( struct V_8 * V_9 )
{
return 0 ;
}
static int F_25 ( void )
{
int V_34 ;
V_34 = F_26 ( & V_35 ) ;
if ( V_34 )
F_27 ( L_14 , V_34 ) ;
return V_34 ;
}
static void F_28 ( void )
{
F_29 ( & V_35 ) ;
}

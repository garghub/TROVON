void F_1 ( T_1 V_1 )
{
V_2 = V_1 ;
}
T_1 F_2 ( void )
{
return V_2 ;
}
void F_3 ( void * V_3 )
{
F_4 ( & V_4 ) ;
}
void F_5 ( void * V_3 )
{
F_6 ( & V_4 ) ;
}
static void F_7 ( struct V_5 * V_6 ,
const char * V_7 , T_1 * V_8 )
{
* V_8 = 0 ;
F_8 ( V_6 ) ;
while ( V_6 ) {
if ( F_9 ( V_6 , V_7 , V_8 ) == 0 ) {
F_10 ( V_6 ) ;
return;
}
V_6 = F_11 ( V_6 ) ;
}
}
int F_12 ( struct V_5 * V_6 , T_1 * V_1 ,
T_1 * V_9 , T_1 * V_10 )
{
F_7 ( V_6 , L_1 , V_1 ) ;
if ( * V_1 == V_11 )
* V_1 = V_2 ;
if ( F_13 ( V_2 == V_11 ) )
return - V_12 ;
F_7 ( V_6 , L_2 , V_9 ) ;
F_7 ( V_6 , L_3 , V_10 ) ;
return 0 ;
}
static void F_14 ( struct V_13 * V_14 , void * V_15 )
{
struct V_16 * V_17 = F_15 ( V_14 -> V_18 ) ;
struct V_19 * V_19 = V_15 ;
V_17 -> V_20 -> V_21 ( V_19 , V_17 -> V_22 ) ;
}
struct V_19 * F_16 ( struct V_13 * V_14 )
{
struct V_16 * V_17 ;
struct V_19 * V_19 ;
struct V_19 * * V_15 ;
if ( F_13 ( V_14 -> V_18 -> V_23 != V_24 ) )
return F_17 ( - V_25 ) ;
V_17 = F_15 ( V_14 -> V_18 ) ;
if ( F_13 ( ! V_17 ) )
return F_17 ( - V_12 ) ;
V_15 = F_18 ( F_14 , sizeof( * V_15 ) ,
V_26 ) ;
if ( ! V_15 )
return F_17 ( - V_27 ) ;
V_19 = ( V_17 -> V_20 -> V_28 ) ( V_14 , V_17 -> V_22 ) ;
if ( F_19 ( V_19 ) ) {
F_20 ( V_15 ) ;
return V_19 ;
}
* V_15 = V_19 ;
F_21 ( V_14 , V_15 ) ;
return V_19 ;
}
struct V_13 * F_22 ( struct V_13 * V_18 ,
struct V_29 * V_20 , void * V_22 )
{
struct V_13 * V_14 ;
struct V_16 * V_17 ;
if ( ! V_24 ) {
V_24 = F_23 ( V_30 ,
L_4 ) ;
if ( F_19 ( V_24 ) )
return ( void * ) V_24 ;
}
V_14 = F_24 ( V_24 , V_18 , 0 ,
NULL , L_5 , F_25 ( V_18 ) ) ;
if ( F_19 ( V_14 ) )
return V_14 ;
V_17 = F_26 ( V_14 , sizeof( * V_17 ) , V_26 ) ;
if ( ! V_17 ) {
F_27 ( V_14 ) ;
F_28 ( V_14 ) ;
return F_17 ( - V_27 ) ;
}
V_17 -> V_20 = V_20 ;
V_17 -> V_22 = V_22 ;
F_29 ( V_14 , V_17 ) ;
F_30 ( V_18 , L_6 ,
F_25 ( V_14 ) , V_18 -> V_31 ) ;
return V_14 ;
}
static int F_31 ( struct V_13 * V_14 , const void * V_32 )
{
const struct V_5 * V_6 = V_32 ;
F_30 ( V_14 , L_7 ,
V_14 -> V_18 -> V_31 , V_6 ) ;
return V_14 -> V_18 -> V_31 == V_6 ;
}
static int F_32 ( struct V_5 * V_6 )
{
struct V_5 * V_17 ;
struct V_13 * V_18 ;
int V_33 ;
V_17 = F_33 ( V_6 , L_8 , 0 ) ;
if ( ! V_17 )
return - V_12 ;
V_18 = F_34 ( V_24 , NULL , V_17 ,
F_31 ) ;
F_10 ( V_17 ) ;
if ( F_13 ( ! V_18 ) )
return - V_25 ;
V_33 = F_35 ( V_6 , NULL , NULL , V_18 ) ;
F_27 ( V_18 ) ;
return V_33 ;
}
static int T_2 F_36 ( void )
{
int V_34 = 0 ;
struct V_5 * V_6 ;
F_37 (node, NULL, L_9 ) {
V_34 = F_32 ( V_6 ) ;
if ( V_34 ) {
F_10 ( V_6 ) ;
break;
}
}
return V_34 ;
}

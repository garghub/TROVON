static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
int V_5 ;
V_5 = F_2 ( V_4 -> V_6 [ 0 ] , & V_4 -> V_7 ) ;
if ( V_5 < 0 ) {
if ( V_5 == - V_8 )
return V_9 ;
F_3 ( V_10 L_1 ,
- V_5 ) ;
F_4 ( V_4 -> V_5 ) ;
}
F_5 ( & V_4 -> V_11 ) ;
V_4 -> V_5 = V_5 ;
F_6 ( & V_4 -> V_11 , & V_4 -> V_12 -> V_13 ) ;
F_7 ( & V_4 -> V_12 -> V_14 ) ;
return V_15 ;
}
static int F_8 ( struct V_16 * V_12 )
{
struct V_3 * V_4 ;
int V_5 , V_6 [ 2 ] , V_17 ;
V_5 = F_9 ( V_12 -> V_5 , V_6 , & V_17 ) ;
if ( V_5 < 0 ) {
if ( V_5 != - V_8 )
F_3 ( V_10 L_2
L_3 , - V_5 ) ;
goto V_18;
}
V_4 = F_10 ( sizeof( * V_4 ) , V_19 ) ;
if ( V_4 == NULL ) {
F_3 ( V_10 L_4
L_5 ) ;
goto V_20;
}
* V_4 = ( (struct V_3 )
{ . V_11 = F_11 ( V_4 -> V_11 ) ,
. V_5 = V_5 ,
. V_6 = { V_6 [ 0 ] , V_6 [ 1 ] } ,
. V_21 = V_17 ,
. V_12 = V_12 } ) ;
if ( F_12 ( V_22 , V_6 [ 0 ] , V_23 , F_1 ,
V_24 , L_6 , V_4 ) ) {
F_3 ( V_10 L_7
L_8 ) ;
goto V_25;
}
if ( F_13 ( & V_12 -> V_26 ) == 0 ) {
F_14 ( V_5 , V_27 , sizeof( V_27 ) ) ;
F_3 ( V_10 L_9 ) ;
}
F_6 ( & V_4 -> V_11 , & V_12 -> V_28 ) ;
return 1 ;
V_25:
F_15 ( V_4 ) ;
V_20:
F_4 ( V_5 ) ;
F_16 ( V_17 , 1 ) ;
V_18:
return 0 ;
}
static void F_17 ( struct V_29 * V_30 )
{
struct V_16 * V_12 ;
struct V_31 * V_32 ;
unsigned long V_33 ;
F_18 ( V_33 ) ;
F_19 (ele, &ports) {
V_12 = F_20 ( V_32 , struct V_16 , V_11 ) ;
if ( ! V_12 -> V_34 )
continue;
F_21 ( V_12 -> V_5 , V_35 ) ;
while ( F_8 ( V_12 ) )
;
V_12 -> V_34 = 0 ;
}
F_22 ( V_33 ) ;
}
static T_1 F_23 ( int V_1 , void * V_2 )
{
struct V_16 * V_12 = V_2 ;
V_12 -> V_34 = 1 ;
F_24 ( & V_36 ) ;
return V_15 ;
}
void * F_25 ( int V_37 )
{
struct V_31 * V_32 ;
struct V_16 * V_12 ;
struct V_38 * V_39 = NULL ;
int V_5 ;
F_26 ( & V_40 ) ;
F_19 (ele, &ports) {
V_12 = F_20 ( V_32 , struct V_16 , V_11 ) ;
if ( V_12 -> V_12 == V_37 )
goto V_41;
}
V_12 = F_10 ( sizeof( struct V_16 ) , V_42 ) ;
if ( V_12 == NULL ) {
F_3 ( V_10 L_10 ) ;
goto V_18;
}
V_5 = F_27 ( V_37 ) ;
if ( V_5 < 0 ) {
F_3 ( V_10 L_11 ,
V_37 , - V_5 ) ;
goto V_25;
}
if ( F_12 ( V_35 , V_5 , V_23 , F_23 ,
V_24 , L_12 , V_12 ) ) {
F_3 ( V_10 L_13 , V_37 ) ;
goto V_20;
}
* V_12 = ( (struct V_16 )
{ . V_11 = F_11 ( V_12 -> V_11 ) ,
. V_26 = F_28 ( 0 ) ,
. V_34 = 0 ,
. V_12 = V_37 ,
. V_5 = V_5 ,
. V_28 = F_11 ( V_12 -> V_28 ) ,
. V_13 = F_11 (port->connections) } ) ;
F_29 ( & V_12 -> V_43 ) ;
F_30 ( & V_12 -> V_14 ) ;
F_6 ( & V_12 -> V_11 , & V_44 ) ;
V_41:
V_39 = F_10 ( sizeof( struct V_38 ) , V_42 ) ;
if ( V_39 == NULL ) {
F_3 ( V_10 L_14 ) ;
goto V_18;
}
* V_39 = ( (struct V_38 ) { . V_12 = V_12 ,
. V_7 = - 1 ,
. V_21 = - 1 } ) ;
goto V_18;
V_20:
F_4 ( V_5 ) ;
V_25:
F_15 ( V_12 ) ;
V_18:
F_31 ( & V_40 ) ;
return V_39 ;
}
int F_32 ( void * V_2 )
{
struct V_38 * V_39 = V_2 ;
struct V_3 * V_4 ;
struct V_16 * V_12 = V_39 -> V_12 ;
int V_5 ;
F_33 ( & V_12 -> V_26 ) ;
while ( 1 ) {
V_5 = - V_45 ;
if ( F_34 ( & V_12 -> V_14 ) )
goto V_18;
F_35 ( & V_12 -> V_43 ) ;
V_4 = F_20 ( V_12 -> V_13 . V_46 , struct V_3 ,
V_11 ) ;
F_5 ( & V_4 -> V_11 ) ;
F_36 ( & V_12 -> V_43 ) ;
F_37 ( V_4 -> V_6 [ 0 ] , 1 , 1 ) ;
F_4 ( V_4 -> V_6 [ 0 ] ) ;
F_37 ( V_4 -> V_6 [ 1 ] , 1 , 1 ) ;
F_4 ( V_4 -> V_6 [ 1 ] ) ;
F_38 ( V_22 , V_4 ) ;
if ( V_4 -> V_5 >= 0 )
break;
F_4 ( V_4 -> V_5 ) ;
F_15 ( V_4 ) ;
}
V_5 = V_4 -> V_5 ;
V_39 -> V_7 = V_4 -> V_7 ;
V_39 -> V_21 = V_4 -> V_21 ;
F_15 ( V_4 ) ;
V_18:
F_39 ( & V_12 -> V_26 ) ;
return V_5 ;
}
void F_40 ( void * V_47 )
{
struct V_38 * V_39 = V_47 ;
if ( V_39 -> V_7 != - 1 )
F_16 ( V_39 -> V_7 , 0 ) ;
if ( V_39 -> V_21 != - 1 )
F_16 ( V_39 -> V_21 , 1 ) ;
V_39 -> V_7 = - 1 ;
V_39 -> V_21 = - 1 ;
}
void F_41 ( void * V_47 )
{
struct V_38 * V_39 = V_47 ;
F_40 ( V_39 ) ;
F_15 ( V_39 ) ;
}
static void F_42 ( void )
{
struct V_31 * V_32 ;
struct V_16 * V_12 ;
F_19 (ele, &ports) {
V_12 = F_20 ( V_32 , struct V_16 , V_11 ) ;
F_43 ( V_12 -> V_5 ) ;
F_4 ( V_12 -> V_5 ) ;
}
}

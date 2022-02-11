int F_1 ( void )
{
unsigned long V_1 ;
int V_2 ;
F_2 ( & V_3 , V_1 ) ;
V_2 = F_3 ( V_4 , V_5 ) ;
if ( V_2 >= V_5 ) {
V_2 = - V_6 ;
goto V_7;
}
if ( F_4 ( V_2 , V_8 ) ) {
V_2 = - V_6 ;
goto V_7;
}
F_5 ( V_2 , V_4 ) ;
V_7:
F_6 ( & V_3 , V_1 ) ;
return V_2 ;
}
int F_7 ( void )
{
int V_2 ;
if ( F_8 ( & V_9 ) )
return - V_10 ;
V_2 = F_1 () ;
if ( V_2 < 0 )
F_9 ( & V_9 ) ;
return V_2 ;
}
int F_10 ( int V_2 )
{
unsigned long V_1 ;
if ( V_2 < 0 || V_2 >= V_5 ) {
F_11 ( L_1 ,
V_11 , V_2 ) ;
return - V_12 ;
}
F_2 ( & V_3 , V_1 ) ;
F_12 ( V_2 , V_4 ) ;
F_5 ( V_2 , V_8 ) ;
F_6 ( & V_3 , V_1 ) ;
return 0 ;
}
int F_13 ( int V_2 )
{
int V_13 ;
V_13 = F_10 ( V_2 ) ;
if ( V_13 )
return V_13 ;
F_9 ( & V_9 ) ;
return 0 ;
}
int F_14 ( T_1 V_2 , struct V_14 * V_15 )
{
if ( V_2 >= V_5 ) {
F_11 ( L_2 , V_11 ) ;
return - V_12 ;
}
if ( ! V_15 ) {
F_11 ( L_3 , V_11 ) ;
return - V_12 ;
}
F_15 ( V_16 , F_16 ( V_2 , V_4 ) ) ;
memcpy ( V_15 , & V_17 [ V_2 ] , sizeof( * V_15 ) ) ;
return 0 ;
}
static int F_17 ( struct V_18 * V_19 ,
unsigned long V_20 , void * V_15 )
{
struct V_14 * V_21 = V_15 ;
unsigned long V_1 ;
T_1 V_2 ;
if ( V_20 != V_22 )
return 0 ;
V_2 = F_18 ( V_21 -> V_23 [ 0 ] ) ;
memcpy ( & V_17 [ V_2 ] , V_21 , sizeof( * V_21 ) ) ;
F_2 ( & V_3 , V_1 ) ;
F_12 ( V_2 , V_4 ) ;
F_6 ( & V_3 , V_1 ) ;
F_19 ( & V_16 ) ;
return 0 ;
}
static int T_2 F_20 ( void )
{
struct V_24 * V_25 ;
const T_3 * V_26 ;
int V_27 ;
V_25 = F_21 ( L_4 ) ;
if ( ! V_25 ) {
F_11 ( L_5 , V_11 ) ;
V_27 = - V_28 ;
goto V_7;
}
V_26 = F_22 ( V_25 , L_6 , NULL ) ;
if ( ! V_26 ) {
F_11 ( L_7 ,
V_11 , V_25 -> V_29 ) ;
V_27 = - V_28 ;
goto V_30;
}
V_5 = F_23 ( V_26 ) ;
if ( V_5 > V_31 )
V_5 = V_31 ;
V_27 = F_24 ( V_22 ,
& V_32 ) ;
if ( V_27 ) {
F_11 ( L_8 ,
V_11 , V_27 ) ;
goto V_30;
}
V_17 = F_25 (
sizeof( * V_17 ) * V_5 ,
V_33 ) ;
if ( ! V_17 ) {
F_11 ( L_9
L_10 , V_11 ) ;
V_27 = - V_34 ;
goto V_30;
}
F_26 ( & V_9 , V_5 - 1 ) ;
V_30:
F_27 ( V_25 ) ;
V_7:
return V_27 ;
}

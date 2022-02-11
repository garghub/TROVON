static int T_1 F_1 ( void )
{
unsigned long V_1 ;
void T_2 * V_2 ;
if ( ! F_2 () ) {
F_3 ( L_1 ) ;
return - V_3 ;
}
V_1 = F_4 () ;
if ( ! V_1 ) {
F_3 ( L_2 ) ;
return - V_4 ;
}
V_2 = F_5 ( ( V_5 ) V_1 , V_6 ) ;
if ( ! V_2 ) {
F_3 ( L_3 ,
V_1 , V_6 ) ;
return - V_7 ;
}
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static void T_1 F_8 ( unsigned int V_8 )
{
static T_3 V_9 = { V_10 } ;
struct V_11 * V_12 ;
int V_13 ;
F_9 ( V_14 ) ;
V_12 = F_10 ( L_4 ) ;
F_9 ( ! V_12 ) ;
if ( F_11 ( V_12 , V_15 , & V_14 ) ) {
F_3 ( L_5 V_15 L_6 ,
V_12 -> V_16 ) ;
V_13 = - V_4 ;
goto V_17;
}
V_13 = F_1 () ;
V_17:
F_12 ( V_12 ) ;
if ( V_13 ) {
F_9 ( V_13 != - V_4 ) ;
F_13 ( L_7 ) ;
F_14 ( & V_9 ) ;
}
}
static int F_15 ( unsigned int V_18 , struct V_19 * V_20 )
{
void T_2 * V_21 ;
V_5 V_22 ;
T_4 V_23 ;
T_5 V_24 ;
T_5 V_25 ;
bool V_26 = false ;
V_24 = F_16 ( V_18 ) ;
if ( V_24 & ~ V_27 ) {
F_3 ( L_8 , V_24 , V_27 ) ;
return - V_28 ;
}
if ( ! V_14 ) {
F_3 ( L_9 ) ;
return - V_28 ;
}
V_21 = F_17 ( ( V_5 ) V_14 , sizeof( T_5 ) ) ;
if ( ! V_21 ) {
F_3 ( L_10 , V_24 ) ;
return - V_29 ;
}
V_22 = F_18 ( V_30 ) ;
F_9 ( V_22 & V_27 ) ;
F_9 ( V_22 > ( V_5 ) V_31 ) ;
V_25 = ( T_5 ) V_22 | V_24 ;
F_19 ( V_25 , V_21 ) ;
F_20 () ;
V_23 = F_21 () ;
while ( ! V_26 && F_22 ( V_21 ) == V_25 )
V_26 = F_21 () - V_23 > V_32 ;
F_7 ( V_21 ) ;
if ( ! V_26 )
return 0 ;
F_3 ( L_11 , V_24 ) ;
return - V_29 ;
}

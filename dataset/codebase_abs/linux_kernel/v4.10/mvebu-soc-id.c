int F_1 ( T_1 * V_1 , T_1 * V_2 )
{
if ( V_3 ) {
* V_1 = V_4 ;
* V_2 = V_5 ;
return 0 ;
} else
return - V_6 ;
}
static int T_2 F_2 ( void )
{
struct V_7 * V_8 ;
int V_9 = 0 ;
void T_3 * V_10 ;
struct V_11 * V_11 ;
struct V_7 * V_12 ;
V_8 = F_3 ( NULL , V_13 ) ;
if ( ! V_8 )
return V_9 ;
V_12 = F_4 ( V_8 , NULL ) ;
if ( V_12 == NULL ) {
F_5 ( L_1 ) ;
V_9 = - V_14 ;
goto V_15;
}
V_11 = F_6 ( V_12 , NULL ) ;
if ( F_7 ( V_11 ) ) {
F_5 ( L_2 ) ;
V_9 = - V_14 ;
goto V_15;
}
V_9 = F_8 ( V_11 ) ;
if ( V_9 ) {
F_5 ( L_3 ) ;
goto V_15;
}
V_10 = F_9 ( V_12 , 0 ) ;
if ( V_10 == NULL ) {
F_5 ( L_4 ) ;
V_9 = - V_14 ;
goto V_16;
}
V_4 = F_10 ( V_10 + V_17 ) >> 16 ;
V_5 = F_10 ( V_10 + V_18 ) & V_19 ;
V_3 = true ;
F_11 ( L_5 , V_4 , V_5 ) ;
F_12 ( V_10 ) ;
V_16:
if ( ! F_13 ( V_12 ) || ! F_14 ( V_20 ) ) {
F_15 ( V_11 ) ;
F_16 ( V_11 ) ;
}
V_15:
F_17 ( V_12 ) ;
F_17 ( V_8 ) ;
return V_9 ;
}
static int T_2 F_18 ( void )
{
if ( ! F_19 ( & V_4 , & V_5 ) ) {
V_3 = true ;
F_11 ( L_5 , V_4 , V_5 ) ;
return 0 ;
}
return F_2 () ;
}
static int T_2 F_20 ( void )
{
struct V_21 * V_22 ;
struct V_23 * V_24 ;
if ( ! V_3 )
return 0 ;
V_22 = F_21 ( sizeof( * V_22 ) , V_25 ) ;
if ( ! V_22 )
return - V_14 ;
V_22 -> V_26 = F_22 ( V_25 , L_6 ) ;
V_22 -> V_27 = F_22 ( V_25 , L_7 , V_5 ) ;
V_22 -> V_28 = F_22 ( V_25 , L_7 , V_4 ) ;
V_24 = F_23 ( V_22 ) ;
if ( F_7 ( V_24 ) ) {
F_24 ( V_22 -> V_26 ) ;
F_24 ( V_22 -> V_27 ) ;
F_24 ( V_22 -> V_28 ) ;
F_24 ( V_22 ) ;
}
return 0 ;
}

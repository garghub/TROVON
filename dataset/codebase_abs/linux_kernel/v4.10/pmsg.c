static T_1 F_1 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
T_5 V_5 ;
int V_6 ;
if ( ! V_3 )
return 0 ;
if ( ! F_2 ( V_7 , V_2 , V_3 ) )
return - V_8 ;
F_3 ( & V_9 ) ;
V_6 = V_10 -> V_11 ( V_12 , 0 , & V_5 , 0 , V_2 , 0 , V_3 ,
V_10 ) ;
F_4 ( & V_9 ) ;
return V_6 ? V_6 : V_3 ;
}
static char * F_5 ( struct V_13 * V_14 , T_6 * V_15 )
{
if ( V_15 )
* V_15 = 0220 ;
return NULL ;
}
void F_6 ( void )
{
struct V_13 * V_16 ;
V_17 = F_7 ( 0 , V_18 , & V_19 ) ;
if ( V_17 < 0 ) {
F_8 ( L_1 ) ;
goto V_20;
}
V_21 = F_9 ( V_22 , V_18 ) ;
if ( F_10 ( V_21 ) ) {
F_8 ( L_2 ) ;
goto V_23;
}
V_21 -> V_24 = F_5 ;
V_16 = F_11 ( V_21 , NULL , F_12 ( V_17 , 0 ) ,
NULL , L_3 , V_18 , 0 ) ;
if ( F_10 ( V_16 ) ) {
F_8 ( L_4 ) ;
goto V_25;
}
return;
V_25:
F_13 ( V_21 ) ;
V_23:
F_14 ( V_17 , V_18 ) ;
V_20:
return;
}
void F_15 ( void )
{
F_16 ( V_21 , F_12 ( V_17 , 0 ) ) ;
F_13 ( V_21 ) ;
F_14 ( V_17 , V_18 ) ;
}

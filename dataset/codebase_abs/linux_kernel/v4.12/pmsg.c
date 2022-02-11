static T_1 F_1 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 V_6 = {
. type = V_7 ,
. V_8 = V_3 ,
. V_9 = V_10 ,
} ;
int V_11 ;
if ( ! V_3 )
return 0 ;
if ( ! F_2 ( V_12 , V_2 , V_3 ) )
return - V_13 ;
F_3 ( & V_14 ) ;
V_11 = V_10 -> V_15 ( & V_6 , V_2 ) ;
F_4 ( & V_14 ) ;
return V_11 ? V_11 : V_3 ;
}
static char * F_5 ( struct V_16 * V_17 , T_5 * V_18 )
{
if ( V_18 )
* V_18 = 0220 ;
return NULL ;
}
void F_6 ( void )
{
struct V_16 * V_19 ;
V_20 = F_7 ( 0 , V_21 , & V_22 ) ;
if ( V_20 < 0 ) {
F_8 ( L_1 ) ;
goto V_23;
}
V_24 = F_9 ( V_25 , V_21 ) ;
if ( F_10 ( V_24 ) ) {
F_8 ( L_2 ) ;
goto V_26;
}
V_24 -> V_27 = F_5 ;
V_19 = F_11 ( V_24 , NULL , F_12 ( V_20 , 0 ) ,
NULL , L_3 , V_21 , 0 ) ;
if ( F_10 ( V_19 ) ) {
F_8 ( L_4 ) ;
goto V_28;
}
return;
V_28:
F_13 ( V_24 ) ;
V_26:
F_14 ( V_20 , V_21 ) ;
V_23:
return;
}
void F_15 ( void )
{
F_16 ( V_24 , F_12 ( V_20 , 0 ) ) ;
F_13 ( V_24 ) ;
F_14 ( V_20 , V_21 ) ;
}

static T_1 F_1 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
T_3 V_5 , V_6 ;
char * V_7 ;
if ( ! V_3 )
return 0 ;
if ( ! F_2 ( V_8 , V_2 , V_3 ) )
return - V_9 ;
V_6 = V_3 ;
if ( V_6 > V_10 )
V_6 = V_10 ;
V_7 = F_3 ( V_6 ) ;
F_4 ( & V_11 ) ;
for ( V_5 = 0 ; V_5 < V_3 ; ) {
T_3 V_12 = F_5 ( V_3 - V_5 , V_6 ) ;
T_5 V_13 ;
long V_14 ;
V_14 = F_6 ( V_7 , V_2 + V_5 , V_12 ) ;
if ( F_7 ( V_14 != 0 ) ) {
F_8 ( & V_11 ) ;
F_9 ( V_7 ) ;
return - V_9 ;
}
V_15 -> V_16 ( V_17 , 0 , & V_13 , 0 , V_7 , 0 , V_12 ,
V_15 ) ;
V_5 += V_12 ;
}
F_8 ( & V_11 ) ;
F_9 ( V_7 ) ;
return V_3 ;
}
static char * F_10 ( struct V_18 * V_19 , T_6 * V_20 )
{
if ( V_20 )
* V_20 = 0220 ;
return NULL ;
}
void F_11 ( void )
{
struct V_18 * V_21 ;
V_22 = F_12 ( 0 , V_23 , & V_24 ) ;
if ( V_22 < 0 ) {
F_13 ( L_1 ) ;
goto V_25;
}
V_26 = F_14 ( V_27 , V_23 ) ;
if ( F_15 ( V_26 ) ) {
F_13 ( L_2 ) ;
goto V_28;
}
V_26 -> V_29 = F_10 ;
V_21 = F_16 ( V_26 , NULL , F_17 ( V_22 , 0 ) ,
NULL , L_3 , V_23 , 0 ) ;
if ( F_15 ( V_21 ) ) {
F_13 ( L_4 ) ;
goto V_30;
}
return;
V_30:
F_18 ( V_26 ) ;
V_28:
F_19 ( V_22 , V_23 ) ;
V_25:
return;
}

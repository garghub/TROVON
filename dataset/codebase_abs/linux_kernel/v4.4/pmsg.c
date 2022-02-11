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
if ( ! V_7 )
return - V_11 ;
F_4 ( & V_12 ) ;
for ( V_5 = 0 ; V_5 < V_3 ; ) {
T_3 V_13 = F_5 ( V_3 - V_5 , V_6 ) ;
T_5 V_14 ;
long V_15 ;
V_15 = F_6 ( V_7 , V_2 + V_5 , V_13 ) ;
if ( F_7 ( V_15 != 0 ) ) {
F_8 ( & V_12 ) ;
F_9 ( V_7 ) ;
return - V_9 ;
}
V_16 -> V_17 ( V_18 , 0 , & V_14 , 0 , V_7 , 0 , V_13 ,
V_16 ) ;
V_5 += V_13 ;
}
F_8 ( & V_12 ) ;
F_9 ( V_7 ) ;
return V_3 ;
}
static char * F_10 ( struct V_19 * V_20 , T_6 * V_21 )
{
if ( V_21 )
* V_21 = 0220 ;
return NULL ;
}
void F_11 ( void )
{
struct V_19 * V_22 ;
V_23 = F_12 ( 0 , V_24 , & V_25 ) ;
if ( V_23 < 0 ) {
F_13 ( L_1 ) ;
goto V_26;
}
V_27 = F_14 ( V_28 , V_24 ) ;
if ( F_15 ( V_27 ) ) {
F_13 ( L_2 ) ;
goto V_29;
}
V_27 -> V_30 = F_10 ;
V_22 = F_16 ( V_27 , NULL , F_17 ( V_23 , 0 ) ,
NULL , L_3 , V_24 , 0 ) ;
if ( F_15 ( V_22 ) ) {
F_13 ( L_4 ) ;
goto V_31;
}
return;
V_31:
F_18 ( V_27 ) ;
V_29:
F_19 ( V_23 , V_24 ) ;
V_26:
return;
}
void F_20 ( void )
{
F_21 ( V_27 , F_17 ( V_23 , 0 ) ) ;
F_18 ( V_27 ) ;
F_19 ( V_23 , V_24 ) ;
}

static T_1 F_1 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 V_6 ;
int V_7 ;
if ( ! V_3 )
return 0 ;
F_2 ( & V_6 , V_8 ) ;
V_6 . type = V_9 ;
V_6 . V_10 = V_3 ;
if ( ! F_3 ( V_11 , V_2 , V_3 ) )
return - V_12 ;
F_4 ( & V_13 ) ;
V_7 = V_8 -> V_14 ( & V_6 , V_2 ) ;
F_5 ( & V_13 ) ;
return V_7 ? V_7 : V_3 ;
}
static char * F_6 ( struct V_15 * V_16 , T_5 * V_17 )
{
if ( V_17 )
* V_17 = 0220 ;
return NULL ;
}
void F_7 ( void )
{
struct V_15 * V_18 ;
V_19 = F_8 ( 0 , V_20 , & V_21 ) ;
if ( V_19 < 0 ) {
F_9 ( L_1 ) ;
goto V_22;
}
V_23 = F_10 ( V_24 , V_20 ) ;
if ( F_11 ( V_23 ) ) {
F_9 ( L_2 ) ;
goto V_25;
}
V_23 -> V_26 = F_6 ;
V_18 = F_12 ( V_23 , NULL , F_13 ( V_19 , 0 ) ,
NULL , L_3 , V_20 , 0 ) ;
if ( F_11 ( V_18 ) ) {
F_9 ( L_4 ) ;
goto V_27;
}
return;
V_27:
F_14 ( V_23 ) ;
V_25:
F_15 ( V_19 , V_20 ) ;
V_22:
return;
}
void F_16 ( void )
{
F_17 ( V_23 , F_13 ( V_19 , 0 ) ) ;
F_14 ( V_23 ) ;
F_15 ( V_19 , V_20 ) ;
}

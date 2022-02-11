T_1 F_1 ( char * V_1 , T_2 V_2 , T_3 V_3 )
{
const char * V_4 ;
T_1 V_5 ;
T_3 V_6 = 0 ;
T_4 V_7 , V_8 ;
if ( ! V_9 )
return - V_10 ;
V_7 = F_2 ( F_3 ( V_9 -> V_7 ) ) ;
F_4 () ;
V_4 = F_5 ( F_6 ( V_9 -> V_11 ) ) ;
if ( V_7 & V_12 ) {
V_7 &= V_13 ;
V_8 = F_2 ( V_9 -> V_14 ) - V_7 ;
V_5 = F_7 ( V_1 , V_3 , & V_2 ,
V_4 + V_7 , V_8 ) ;
if ( V_5 < 0 )
goto V_15;
V_6 = V_5 ;
V_1 += V_6 ;
V_3 -= V_6 ;
V_2 -= V_8 ;
if ( V_3 <= 0 )
goto V_15;
}
if ( V_7 > F_2 ( V_9 -> V_14 ) ) {
F_8 ( L_1 ) ;
return - V_16 ;
}
V_5 = F_7 ( V_1 , V_3 , & V_2 , V_4 , V_7 ) ;
if ( V_5 < 0 )
goto V_15;
V_5 += V_6 ;
V_15:
return V_5 ;
}
static T_1 F_9 ( struct V_17 * V_17 , struct V_18 * V_19 ,
struct V_20 * V_21 , char * V_1 ,
T_2 V_2 , T_3 V_3 )
{
return F_1 ( V_1 , V_2 , V_3 ) ;
}
void T_5 F_10 ( void )
{
T_6 V_22 ;
struct V_23 * V_24 ;
if ( F_11 ( V_25 , L_2 , & V_22 ) ) {
F_12 ( L_3 ) ;
return;
}
V_24 = F_5 ( V_22 ) ;
if ( ! V_24 ) {
F_12 ( L_4 ) ;
return;
}
if ( F_6 ( V_24 -> V_26 ) != V_27 ) {
F_12 ( L_5 ) ;
return;
}
V_9 = V_24 ;
}
void T_5 F_13 ( void )
{
if ( ! V_9 ) {
F_12 ( L_6 ) ;
return;
}
if ( F_14 ( V_28 , & V_29 ) != 0 )
F_12 ( L_7 ) ;
}

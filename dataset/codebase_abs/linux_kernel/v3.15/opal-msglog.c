static T_1 F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 , char * V_6 ,
T_2 V_7 , T_3 V_8 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
const char * V_12 ;
T_3 V_13 , V_14 = 0 ;
T_4 V_15 , V_16 ;
if ( ! V_10 )
return - V_17 ;
V_15 = F_2 ( F_3 ( V_10 -> V_15 ) ) ;
F_4 () ;
V_12 = F_5 ( F_6 ( V_10 -> V_18 ) ) ;
if ( V_15 & V_19 ) {
V_15 &= V_20 ;
V_16 = F_2 ( V_10 -> V_21 ) - V_15 ;
V_13 = F_7 ( V_6 , V_8 , & V_7 ,
V_12 + V_15 , V_16 ) ;
if ( V_13 < 0 )
goto V_22;
V_14 = V_13 ;
V_6 += V_14 ;
V_8 -= V_14 ;
V_7 -= V_16 ;
}
if ( V_15 > F_2 ( V_10 -> V_21 ) ) {
F_8 ( L_1 ) ;
return - V_23 ;
}
V_13 = F_7 ( V_6 , V_8 , & V_7 , V_12 , V_15 ) ;
if ( V_13 < 0 )
goto V_22;
V_13 += V_14 ;
V_22:
return V_13 ;
}
void T_5 F_9 ( void )
{
T_6 V_24 ;
struct V_9 * V_10 ;
if ( F_10 ( V_25 , L_2 , & V_24 ) ) {
F_11 ( L_3 ) ;
return;
}
V_10 = F_5 ( V_24 ) ;
if ( ! V_10 ) {
F_11 ( L_4 ) ;
return;
}
if ( F_6 ( V_10 -> V_26 ) != V_27 ) {
F_11 ( L_5 ) ;
return;
}
V_28 . V_11 = V_10 ;
if ( F_12 ( V_29 , & V_28 ) != 0 )
F_11 ( L_6 ) ;
}

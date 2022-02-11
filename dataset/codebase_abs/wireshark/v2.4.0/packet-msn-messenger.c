static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_3 * V_5 ;
T_5 * V_6 ;
T_6 V_7 = 0 ;
const T_7 * line ;
T_6 V_8 ;
int V_9 ;
F_2 ( V_2 -> V_10 , V_11 , L_1 ) ;
V_9 = F_3 ( V_1 , V_7 , - 1 , & V_8 , FALSE ) ;
line = F_4 ( V_1 , V_7 , V_9 ) ;
F_5 ( V_2 -> V_10 , V_12 ,
F_6 ( F_7 () , line , V_9 ) ) ;
if ( V_3 ) {
V_6 = F_8 ( V_3 , V_13 , V_1 , V_7 , - 1 ,
V_14 ) ;
V_5 = F_9 ( V_6 , V_15 ) ;
while ( F_10 ( V_1 , V_7 ) ) {
F_3 ( V_1 , V_7 , - 1 ,
& V_8 , FALSE ) ;
F_11 ( V_5 , V_1 , V_7 , V_8 - V_7 ) ;
V_7 = V_8 ;
}
}
return F_12 ( V_1 ) ;
}
void
F_13 ( void )
{
static T_6 * V_16 [] = {
& V_15 ,
} ;
V_13 = F_14 ( L_2 , L_1 , L_3 ) ;
F_15 ( V_16 , F_16 ( V_16 ) ) ;
}
void
F_17 ( void )
{
T_8 V_17 ;
V_17 = F_18 ( F_1 , V_13 ) ;
F_19 ( L_4 , V_18 , V_17 ) ;
F_20 ( L_5 , L_6 , V_17 ) ;
}

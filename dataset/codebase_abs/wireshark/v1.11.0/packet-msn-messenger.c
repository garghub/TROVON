static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_3 * V_4 ;
T_4 * V_5 ;
T_5 V_6 = 0 ;
const T_6 * line ;
T_5 V_7 ;
int V_8 ;
F_2 ( V_2 -> V_9 , V_10 , L_1 ) ;
V_8 = F_3 ( V_1 , V_6 , - 1 , & V_7 , FALSE ) ;
line = F_4 ( V_1 , V_6 , V_8 ) ;
F_5 ( V_2 -> V_9 , V_11 ,
F_6 ( line , V_8 ) ) ;
if ( V_3 ) {
V_5 = F_7 ( V_3 , V_12 , V_1 , V_6 , - 1 ,
V_13 ) ;
V_4 = F_8 ( V_5 , V_14 ) ;
while ( F_9 ( V_1 , V_6 ) ) {
F_3 ( V_1 , V_6 , - 1 ,
& V_7 , FALSE ) ;
F_10 ( V_4 , V_1 , V_6 ,
V_7 - V_6 , L_2 ,
F_11 ( V_1 , V_6 , V_7 - V_6 ) ) ;
V_6 = V_7 ;
}
}
}
void
F_12 ( void )
{
static T_5 * V_15 [] = {
& V_14 ,
} ;
V_12 = F_13 ( L_3 , L_1 , L_4 ) ;
F_14 ( V_15 , F_15 ( V_15 ) ) ;
}
void
F_16 ( void )
{
T_7 V_16 ;
V_16 = F_17 ( F_1 , V_12 ) ;
F_18 ( L_5 , V_17 , V_16 ) ;
F_19 ( L_6 , L_7 , V_16 ) ;
}

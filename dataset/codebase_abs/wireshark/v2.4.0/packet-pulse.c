static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 * V_5 ;
T_3 * V_6 ;
T_6 V_7 ;
const char * V_8 ;
T_7 V_9 ;
if ( F_2 ( V_1 ) < 4 )
return 0 ;
V_9 = V_10 ;
V_7 = F_3 ( V_1 , 0 ) ;
V_8 = F_4 ( V_7 , V_11 ) ;
if ( V_8 == NULL ) {
V_7 = F_5 ( V_1 , 0 ) ;
V_8 = F_4 ( V_7 , V_11 ) ;
if ( V_8 == NULL ) {
return 0 ;
}
V_9 = V_12 ;
}
F_6 ( V_2 -> V_13 , V_14 , L_1 ) ;
F_6 ( V_2 -> V_13 , V_15 , V_8 ) ;
if ( V_3 ) {
V_5 = F_7 ( V_3 , V_16 , V_1 , 0 ,
- 1 , V_9 ) ;
V_6 = F_8 ( V_5 , V_17 ) ;
F_7 ( V_6 , V_18 , V_1 , 0 , 4 , V_9 ) ;
}
return 4 ;
}
void
F_9 ( void )
{
static T_8 V_19 [] = {
{ & V_18 ,
{ L_2 , L_3 ,
V_20 , V_21 , F_10 ( V_11 ) , 0x0 ,
NULL , V_22 } } ,
} ;
static T_9 * V_23 [] = {
& V_17 ,
} ;
V_16 = F_11 ( L_4 , L_1 , L_5 ) ;
F_12 ( V_16 , V_19 , F_13 ( V_19 ) ) ;
F_14 ( V_23 , F_13 ( V_23 ) ) ;
}
void
F_15 ( void )
{
T_10 V_24 ;
V_24 = F_16 ( F_1 , V_16 ) ;
F_17 ( L_6 , V_25 , V_24 ) ;
}

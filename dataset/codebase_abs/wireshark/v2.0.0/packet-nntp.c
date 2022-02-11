static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
const T_4 * type ;
T_3 * V_4 ;
T_5 * V_5 ;
T_6 V_6 = 0 ;
T_6 V_7 ;
int V_8 ;
if ( V_2 -> V_9 == V_2 -> V_10 )
type = L_1 ;
else
type = L_2 ;
F_2 ( V_2 -> V_11 , V_12 , L_3 ) ;
V_8 = F_3 ( V_1 , V_6 , - 1 , & V_7 , FALSE ) ;
F_4 ( V_2 -> V_11 , V_13 , L_4 , type ,
F_5 ( V_1 , V_6 , V_8 ) ) ;
if ( V_3 ) {
V_5 = F_6 ( V_3 , V_14 , V_1 , V_6 , - 1 ,
V_15 ) ;
V_4 = F_7 ( V_5 , V_16 ) ;
if ( V_2 -> V_9 == V_2 -> V_10 ) {
V_5 = F_8 ( V_4 ,
V_17 , V_1 , 0 , 0 , TRUE ) ;
} else {
V_5 = F_8 ( V_4 ,
V_18 , V_1 , 0 , 0 , TRUE ) ;
}
F_9 ( V_5 ) ;
while ( F_10 ( V_1 , V_6 ) ) {
F_3 ( V_1 , V_6 , - 1 , & V_7 ,
FALSE ) ;
F_11 ( V_4 , V_1 , V_6 , V_7 - V_6 ) ;
V_6 = V_7 ;
}
}
}
void
F_12 ( void )
{
static T_7 V_19 [] = {
{ & V_18 ,
{ L_2 , L_5 ,
V_20 , V_21 , NULL , 0x0 ,
L_6 , V_22 } } ,
{ & V_17 ,
{ L_1 , L_7 ,
V_20 , V_21 , NULL , 0x0 ,
L_8 , V_22 } }
} ;
static T_6 * V_23 [] = {
& V_16 ,
} ;
V_14 = F_13 ( L_9 ,
L_3 , L_10 ) ;
F_14 ( V_14 , V_19 , F_15 ( V_19 ) ) ;
F_16 ( V_23 , F_15 ( V_23 ) ) ;
}
void
F_17 ( void )
{
T_8 V_24 ;
V_24 = F_18 ( F_1 , V_14 ) ;
F_19 ( L_11 , V_25 , V_24 ) ;
}

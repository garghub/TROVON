static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
const T_5 * type ;
T_3 * V_5 ;
T_6 * V_6 ;
T_7 V_7 = 0 ;
T_7 V_8 ;
int V_9 ;
if ( V_2 -> V_10 == V_2 -> V_11 )
type = L_1 ;
else
type = L_2 ;
F_2 ( V_2 -> V_12 , V_13 , L_3 ) ;
V_9 = F_3 ( V_1 , V_7 , - 1 , & V_8 , FALSE ) ;
F_4 ( V_2 -> V_12 , V_14 , L_4 , type ,
F_5 ( V_1 , V_7 , V_9 ) ) ;
if ( V_3 ) {
V_6 = F_6 ( V_3 , V_15 , V_1 , V_7 , - 1 ,
V_16 ) ;
V_5 = F_7 ( V_6 , V_17 ) ;
if ( V_2 -> V_10 == V_2 -> V_11 ) {
V_6 = F_8 ( V_5 ,
V_18 , V_1 , 0 , 0 , TRUE ) ;
} else {
V_6 = F_8 ( V_5 ,
V_19 , V_1 , 0 , 0 , TRUE ) ;
}
F_9 ( V_6 ) ;
while ( F_10 ( V_1 , V_7 ) ) {
F_3 ( V_1 , V_7 , - 1 , & V_8 ,
FALSE ) ;
F_11 ( V_5 , V_1 , V_7 , V_8 - V_7 ) ;
V_7 = V_8 ;
}
}
return F_12 ( V_1 ) ;
}
void
F_13 ( void )
{
static T_8 V_20 [] = {
{ & V_19 ,
{ L_2 , L_5 ,
V_21 , V_22 , NULL , 0x0 ,
L_6 , V_23 } } ,
{ & V_18 ,
{ L_1 , L_7 ,
V_21 , V_22 , NULL , 0x0 ,
L_8 , V_23 } }
} ;
static T_7 * V_24 [] = {
& V_17 ,
} ;
V_15 = F_14 ( L_9 ,
L_3 , L_10 ) ;
F_15 ( V_15 , V_20 , F_16 ( V_20 ) ) ;
F_17 ( V_24 , F_16 ( V_24 ) ) ;
}
void
F_18 ( void )
{
T_9 V_25 ;
V_25 = F_19 ( F_1 , V_15 ) ;
F_20 ( L_11 , V_26 , V_25 ) ;
}

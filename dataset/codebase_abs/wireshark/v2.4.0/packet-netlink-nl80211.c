static int
F_1 ( T_1 * V_1 , void * V_2 , T_2 * V_3 , int V_4 , int V_5 , int V_6 )
{
enum V_7 type = (enum V_7 ) V_4 ;
T_3 * V_8 = ( T_3 * ) V_2 ;
switch ( type ) {
default:
if ( V_6 ) {
if ( V_6 == 2 ) {
F_2 ( V_3 , & V_9 , V_1 , V_5 , V_6 , V_8 -> V_10 ) ;
} else if ( V_6 == 4 ) {
F_2 ( V_3 , & V_11 , V_1 , V_5 , V_6 , V_8 -> V_10 ) ;
} else {
F_2 ( V_3 , & V_12 , V_1 , V_5 , V_6 , V_8 -> V_10 ) ;
}
V_5 += V_6 ;
}
break;
}
return V_5 ;
}
static int
F_3 ( T_1 * V_1 , T_4 * V_13 , T_2 * V_3 , void * V_2 )
{
T_3 * V_8 = ( T_3 * ) V_2 ;
T_2 * V_14 ;
T_5 * V_15 ;
int V_5 ;
F_4 ( V_8 ) ;
F_5 ( V_13 -> V_16 , V_17 , L_1 ) ;
F_6 ( V_13 -> V_16 , V_18 ) ;
V_5 = F_7 ( V_1 , V_8 , & V_19 ) ;
V_15 = F_2 ( V_3 , F_8 ( V_20 ) , V_1 , V_5 , - 1 , V_21 ) ;
V_14 = F_9 ( V_15 , V_22 ) ;
V_5 = F_10 ( V_1 , & V_23 , V_24 , V_8 , V_8 -> V_2 , V_14 , V_5 , - 1 , F_1 ) ;
return V_5 ;
}
void
F_11 ( void )
{
#ifndef F_12
static T_6 * V_25 [] = {
& V_19 ,
& V_23 ,
& V_12 ,
& V_9 ,
& V_11 ,
} ;
#endif
static T_7 * V_26 [] = {
& V_22 ,
& V_24 ,
} ;
V_20 = F_13 ( L_2 , L_1 , L_1 ) ;
V_27 = F_8 ( V_20 ) ;
F_14 ( V_20 , V_25 , F_15 ( V_25 ) ) ;
F_16 ( V_26 , F_15 ( V_26 ) ) ;
V_28 = F_17 ( F_3 , V_20 ) ;
}
void
F_18 ( void )
{
F_19 ( L_3 , L_1 , V_28 ) ;
}

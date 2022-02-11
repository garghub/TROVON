static int F_1 ( T_1 * V_1 , int V_2 ,
void T_2 * V_3 , T_3 * V_4 ,
T_4 * V_5 )
{
T_5 * V_6 = ( T_5 * ) V_1 -> V_7 ;
if ( ! V_6 )
return - V_8 ;
if ( V_2 )
F_2 ( V_6 , 0 ) ;
else {
char V_9 [ 32 ] ;
char * V_7 ;
int V_10 = snprintf ( V_9 , 32 , L_1 , F_3 ( V_6 ) ) ;
if ( V_10 >= 32 )
return - V_11 ;
V_10 = strlen ( V_9 ) ;
if ( * V_5 > V_10 ) {
* V_4 = 0 ;
return 0 ;
}
V_7 = & V_9 [ * V_5 ] ;
V_10 -= * V_5 ;
if ( V_10 > * V_4 )
V_10 = * V_4 ;
if ( V_10 && F_4 ( V_3 , V_9 , V_10 ) )
return - V_11 ;
* V_4 = V_10 ;
* V_5 += V_10 ;
}
return 0 ;
}
void F_5 ( void )
{
F_6 ( L_2 ) ;
F_7 ( V_12 ) ;
if ( V_13 ) {
F_8 ( V_13 ) ;
V_13 = NULL ;
}
F_9 ( & V_14 ) ;
F_10 ( V_15 ) ;
F_10 ( V_16 ) ;
}
int F_11 ( void )
{
F_6 ( L_3 ) ;
F_6 ( L_4 , V_17 ) ;
F_6 ( L_5 , V_18 ) ;
F_6 ( L_6 ,
V_18 * V_19 ) ;
F_6 ( L_7 , V_20 ) ;
V_12 = F_12 ( L_8 , 0 , 0 ) ;
if ( ! V_12 )
return - V_21 ;
if ( ! V_13 )
V_13 =
F_13 ( V_22 ) ;
V_15 = F_14 ( L_9 ,
sizeof( struct V_23 ) ,
0 ,
V_24 ,
NULL ) ;
if ( ! V_15 ) {
F_15 ( V_25 L_10 ) ;
goto V_26;
}
V_16 =
F_14 ( L_11 ,
sizeof( struct V_27 ) ,
0 ,
V_24 ,
NULL ) ;
if ( ! V_16 ) {
F_15 ( V_25 L_12 ) ;
goto V_28;
}
F_16 ( & V_14 ) ;
return 0 ;
V_28:
F_10 ( V_15 ) ;
V_26:
F_8 ( V_13 ) ;
F_7 ( V_12 ) ;
return - V_21 ;
}

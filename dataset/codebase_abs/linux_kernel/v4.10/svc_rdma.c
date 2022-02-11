static int F_1 ( struct V_1 * V_2 , int V_3 ,
void T_1 * V_4 , T_2 * V_5 ,
T_3 * V_6 )
{
T_4 * V_7 = ( T_4 * ) V_2 -> V_8 ;
if ( ! V_7 )
return - V_9 ;
if ( V_3 )
F_2 ( V_7 , 0 ) ;
else {
char V_10 [ 32 ] ;
char * V_8 ;
int V_11 = snprintf ( V_10 , 32 , L_1 , F_3 ( V_7 ) ) ;
if ( V_11 >= 32 )
return - V_12 ;
V_11 = strlen ( V_10 ) ;
if ( * V_6 > V_11 ) {
* V_5 = 0 ;
return 0 ;
}
V_8 = & V_10 [ * V_6 ] ;
V_11 -= * V_6 ;
if ( V_11 > * V_5 )
V_11 = * V_5 ;
if ( V_11 && F_4 ( V_4 , V_10 , V_11 ) )
return - V_12 ;
* V_5 = V_11 ;
* V_6 += V_11 ;
}
return 0 ;
}
void F_5 ( void )
{
F_6 ( L_2 ) ;
F_7 ( V_13 ) ;
if ( V_14 ) {
F_8 ( V_14 ) ;
V_14 = NULL ;
}
#if F_9 ( V_15 )
F_10 ( & V_16 ) ;
#endif
F_10 ( & V_17 ) ;
}
int F_11 ( void )
{
F_6 ( L_3 ) ;
F_6 ( L_4 , V_18 ) ;
F_6 ( L_5 , V_19 ) ;
F_6 ( L_6 ,
V_19 * V_20 ) ;
F_6 ( L_7 , V_21 ) ;
F_6 ( L_8 , V_22 ) ;
V_13 = F_12 ( L_9 , 0 , 0 ) ;
if ( ! V_13 )
return - V_23 ;
if ( ! V_14 )
V_14 =
F_13 ( V_24 ) ;
F_14 ( & V_17 ) ;
#if F_9 ( V_15 )
F_14 ( & V_16 ) ;
#endif
return 0 ;
}

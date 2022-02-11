static T_1 * F_1 ( void )
{
return F_2 () ;
}
static T_2 * F_3 ( T_3 * V_1 ,
T_1 * V_2 , T_2 * V_3 )
{
T_4 * V_4 ;
for( V_4 = V_1 -> V_5 ; V_4 -> V_6 ; V_4 ++ ) {
if( F_4 ( V_2 , V_4 -> V_7 ) )
F_5 ( V_4 -> V_6 , NULL , & V_3 ) ;
}
return V_3 ;
}
static T_1 * F_6 ( T_3 * V_1 ,
T_5 * V_8 , T_2 * V_9 )
{
T_6 * V_10 ;
T_1 * V_11 ;
int V_12 ;
T_4 * V_4 ;
if( ! ( V_11 = F_2 () ) ) {
F_7 ( V_13 , V_14 ) ;
return NULL ;
}
for( V_12 = 0 ; V_12 < F_8 ( V_9 ) ; V_12 ++ ) {
V_10 = ( T_6 * ) F_9 ( V_9 , V_12 ) ;
for( V_4 = V_1 -> V_5 ; V_4 -> V_6 ;
V_4 ++ ) {
if( ! strcmp ( V_4 -> V_15 , V_10 -> V_16 ) ||
! strcmp ( V_4 -> V_6 , V_10 -> V_16 ) ) {
F_10 ( V_11 , V_4 -> V_7 , 1 ) ;
break;
}
}
if( ! V_4 -> V_6 ) {
F_7 ( V_13 , V_17 ) ;
F_11 ( V_10 ) ;
F_12 ( V_11 ) ;
return NULL ;
}
}
return V_11 ;
}

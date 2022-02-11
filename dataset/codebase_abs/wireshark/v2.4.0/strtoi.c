T_1 F_1 ( const T_2 * V_1 , const T_2 * * V_2 , T_3 * V_3 )
{
T_2 * V_4 ;
T_3 V_5 ;
F_2 ( V_3 ) ;
if ( ! V_1 ) {
V_6 = V_7 ;
return FALSE ;
}
V_6 = 0 ;
V_5 = F_3 ( V_1 , & V_4 , 10 ) ;
if ( ( V_5 == 0 && V_4 == V_1 ) || ( V_2 == NULL && * V_4 != '\0' ) ) {
* V_3 = 0 ;
if ( V_2 != NULL )
* V_2 = V_4 ;
V_6 = V_7 ;
return FALSE ;
}
if ( ( V_5 == V_8 || V_5 == V_9 ) && V_6 == V_10 ) {
* V_3 = V_5 ;
if ( V_2 != NULL )
* V_2 = V_4 ;
return FALSE ;
}
if ( V_2 != NULL )
* V_2 = V_4 ;
* V_3 = V_5 ;
return TRUE ;
}
static T_1 F_4 ( const T_2 * V_1 , const T_2 * * V_2 , T_4 * V_3 , int V_11 )
{
T_2 * V_4 ;
T_4 V_5 ;
F_2 ( V_3 ) ;
if ( ! V_1 ) {
V_6 = V_7 ;
return FALSE ;
}
if ( V_1 [ 0 ] == '-' || V_1 [ 0 ] == '+' ) {
* V_3 = 0 ;
if ( V_2 != NULL )
* V_2 = V_1 ;
V_6 = V_7 ;
return FALSE ;
}
V_6 = 0 ;
V_5 = F_5 ( V_1 , & V_4 , V_11 ) ;
if ( ( V_5 == 0 && V_4 == V_1 ) || ( V_2 == NULL && * V_4 != '\0' ) ) {
* V_3 = 0 ;
if ( V_2 != NULL )
* V_2 = V_4 ;
V_6 = V_7 ;
return FALSE ;
}
if ( V_5 == V_12 && V_6 == V_10 ) {
* V_3 = V_5 ;
if ( V_2 != NULL )
* V_2 = V_4 ;
return FALSE ;
}
if ( V_2 != NULL )
* V_2 = V_4 ;
* V_3 = V_5 ;
return TRUE ;
}
T_1 F_6 ( const T_2 * V_1 , const T_2 * * V_2 , T_4 * V_3 )
{
return F_4 ( V_1 , V_2 , V_3 , 10 ) ;
}
T_1 F_7 ( const T_2 * V_1 , const T_2 * * V_2 , T_4 * V_3 )
{
return F_4 ( V_1 , V_2 , V_3 , 16 ) ;
}

static int
F_1 (
void * V_1 ,
T_1 * T_2 V_2 ,
T_3 * T_4 V_2 ,
const void * V_3 )
{
T_5 * V_4 = V_1 ;
const T_6 * V_5 = V_3 ;
switch ( V_5 -> V_6 )
{
case V_7 :
V_4 -> V_8 [ V_5 -> V_9 ] ++ ;
break;
case V_10 :
V_4 -> V_11 [ V_5 -> V_9 ] ++ ;
break;
default:
return ( 0 ) ;
}
return ( 1 ) ;
}
static void
F_2 (
void * V_1 )
{
T_5 * V_4 = V_1 ;
T_7 V_12 ;
printf ( L_1 ) ;
printf ( L_2 ) ;
printf ( L_3 ) ;
printf ( L_4 ) ;
V_12 = 0 ;
while ( V_13 [ V_12 ] . V_14 )
{
if ( V_4 -> V_8 [ V_13 [ V_12 ] . V_15 ] > 0 )
{
printf ( L_5 ,
V_13 [ V_12 ] . V_15 ,
V_13 [ V_12 ] . V_14 ,
V_4 -> V_8 [ V_13 [ V_12 ] . V_15 ] ) ;
}
V_12 ++ ;
}
printf ( L_6 ) ;
printf ( L_4 ) ;
V_12 = 0 ;
while ( V_16 [ V_12 ] . V_14 )
{
if ( V_4 -> V_11 [ V_16 [ V_12 ] . V_15 ] > 0 )
{
printf ( L_5 ,
V_16 [ V_12 ] . V_15 ,
V_16 [ V_12 ] . V_14 ,
V_4 -> V_11 [ V_16 [ V_12 ] . V_15 ] ) ;
}
V_12 ++ ;
}
printf ( L_7 ) ;
}
static void
F_3 ( const char * T_8 V_2 , void * T_9 V_2 )
{
T_5 * V_4 ;
T_10 * V_17 ;
V_4 = F_4 ( sizeof( T_5 ) ) ;
memset ( V_4 , 0 , sizeof( T_5 ) ) ;
V_17 =
F_5 ( L_8 , V_4 , NULL , 0 ,
NULL ,
F_1 ,
F_2 ) ;
if ( V_17 != NULL )
{
F_6 ( V_4 ) ;
F_7 ( V_17 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_8 ( void )
{
F_9 ( L_9 , F_3 , NULL ) ;
}

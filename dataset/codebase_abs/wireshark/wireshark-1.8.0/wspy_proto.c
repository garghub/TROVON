T_1 * F_1 ( const T_2 V_1 )
{
T_1 * V_2 = F_2 ( sizeof( T_1 ) * V_1 ) ;
return V_2 ;
}
void F_3 ( T_1 * V_2 )
{
if ( V_2 ) {
F_4 ( V_2 ) ;
}
}
void F_5 ( T_1 * V_2 , T_2 V_3 ,
int * V_4 , const char * V_5 , const char * V_6 ,
enum V_7 type , int V_8 , const void * V_9 ,
T_3 V_10 , const char * V_11 )
{
V_2 [ V_3 ] . V_4 = V_4 ;
V_2 [ V_3 ] . V_12 . V_5 = V_5 ;
V_2 [ V_3 ] . V_12 . V_6 = V_6 ;
V_2 [ V_3 ] . V_12 . type = type ;
V_2 [ V_3 ] . V_12 . V_8 = V_8 ;
V_2 [ V_3 ] . V_12 . V_9 = V_9 ;
V_2 [ V_3 ] . V_12 . V_10 = V_10 ;
V_2 [ V_3 ] . V_12 . V_11 = V_11 ;
V_2 [ V_3 ] . V_12 . V_13 = 0 ;
V_2 [ V_3 ] . V_12 . V_14 = 0 ;
V_2 [ V_3 ] . V_12 . V_15 = V_16 ;
V_2 [ V_3 ] . V_12 . V_17 = 0 ;
V_2 [ V_3 ] . V_12 . V_18 = NULL ;
V_2 [ V_3 ] . V_12 . V_19 = NULL ;
}
void F_6 ( T_1 * V_2 , T_2 V_1 )
{
T_2 V_20 ;
if ( ! V_2 )
return;
for ( V_20 = 0 ; V_20 < V_1 ; V_20 ++ ) {
printf ( L_1 , V_2 [ V_20 ] . V_12 . V_5 ,
V_2 [ V_20 ] . V_12 . V_6 ,
V_2 [ V_20 ] . V_12 . V_11 ) ;
}
}

int main ( int V_1 , char * V_2 [] )
{
T_1 V_3 = V_4 , V_5 = V_6 , V_7 ;
int V_8 = 0 ;
struct V_9 * V_10 = NULL ;
if ( V_1 >= 2 )
V_5 = strtoul ( V_2 [ 1 ] , NULL , 0 ) ;
printf ( L_1 ) ;
for ( V_7 = V_3 ; V_7 <= V_5 - sizeof( struct V_9 ) ; V_7 += 4 ) {
V_10 = (struct V_9 * ) V_7 ;
if ( ( V_10 -> V_11 == V_12 ) && ( V_10 -> V_13 == V_14 ) &&
( V_10 -> V_15 == V_7 ) ) {
V_8 = 1 ;
break;
}
}
if ( ! V_8 )
printf ( L_2 ) ;
else {
printf ( L_3 , V_10 -> V_16 , ( T_1 ) & V_10 -> V_17 ) ;
puts ( L_4 ) ;
fflush ( stdout ) ;
F_1 ( 1 , & V_10 -> V_17 , V_10 -> V_16 ) ;
fflush ( stdout ) ;
puts ( L_5 ) ;
}
return ( 0 ) ;
}

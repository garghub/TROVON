int
main ( int V_1 , char * * V_2 )
{
unsigned char V_3 [ V_4 ] ;
union { short V_5 ; char V_6 [ 2 ] ; } V_7 ;
if ( fread ( V_3 , 1 , V_4 , V_8 ) != V_4 ) {
fprintf ( V_9 , L_1 ) ;
return 1 ;
}
if ( memcmp ( V_3 , V_10 , V_11 ) != 0 ) {
fprintf ( V_9 , L_2 ) ;
return 1 ;
}
switch ( V_3 [ V_12 ] ) {
case V_13 :
printf ( L_3 ) ;
break;
case V_14 :
printf ( L_4 ) ;
break;
default:
exit ( 1 ) ;
}
switch ( V_3 [ V_15 ] ) {
case V_16 :
printf ( L_5 ) ;
break;
case V_17 :
printf ( L_6 ) ;
break;
default:
exit ( 1 ) ;
}
if (sizeof( unsigned long ) == 4 ) {
printf ( L_7 ) ;
} else if (sizeof( unsigned long ) == 8 ) {
printf ( L_8 ) ;
}
V_7 . V_5 = 0x0102 ;
if ( memcmp ( V_7 . V_6 , L_9 , 2 ) == 0 )
printf ( L_10 ) ;
else if ( memcmp ( V_7 . V_6 , L_11 , 2 ) == 0 )
printf ( L_12 ) ;
else
exit ( 1 ) ;
return 0 ;
}

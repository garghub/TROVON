int main ( int V_1 , char * * V_2 ) {
T_1 V_3 [ 0x100 ] ;
T_2 V_4 ;
const char * V_5 ;
int V_6 , V_7 ;
int V_8 = 1 ;
int V_9 = 1 ;
if ( V_1 != 2 ) {
printf ( L_1 , V_2 [ 0 ] ) ;
return 1 ;
}
V_5 = V_2 [ 1 ] ;
V_4 = F_1 ( L_2 , V_5 ) ;
if ( V_4 == ( T_2 ) - 1 ) {
perror ( L_3 ) ;
return 2 ;
}
F_2 ( V_4 ) ;
for ( V_6 = 0x00 ; V_6 < 0x100 ; V_6 ++ ) {
unsigned char V_10 [ 1 ] , V_11 [ 2 ] ;
T_3 V_12 = 1 , V_13 = 2 ;
char * V_14 = ( char * ) V_10 ;
char * V_15 = ( char * ) V_11 ;
T_3 V_16 ;
V_10 [ 0 ] = V_6 ;
V_4 = F_1 ( L_4 , V_5 ) ;
if ( V_4 == ( T_2 ) - 1 ) {
perror ( L_3 ) ;
return 2 ;
}
V_16 = F_3 ( V_4 , & V_14 , & V_12 , & V_15 , & V_13 ) ;
if ( V_16 == ( T_3 ) - 1 && V_17 == V_18 ) {
V_3 [ V_6 ] = V_19 ;
F_2 ( V_4 ) ;
continue;
}
if ( V_16 == ( T_3 ) - 1 ) {
perror ( L_5 ) ;
F_2 ( V_4 ) ;
return 4 ;
}
F_2 ( V_4 ) ;
if ( V_16 != 0 || V_12 != 0 || V_13 != 0 ) {
fprintf ( V_20 , L_6 , V_6 , V_16 , V_12 , V_13 ) ;
return 3 ;
}
if ( V_6 < 0x80 && ( V_11 [ 0 ] != 0 || V_11 [ 1 ] != V_6 ) )
V_8 = 0 ;
if ( V_6 < 0xA0 && ( V_11 [ 0 ] != 0 || V_11 [ 1 ] != V_6 ) )
V_9 = 0 ;
V_3 [ V_6 ] = ( V_11 [ 0 ] << 8 ) | V_11 [ 1 ] ;
}
V_9 = 0 ;
printf ( L_7 , V_2 [ 0 ] , V_5 ) ;
if ( V_9 )
V_6 = 0xA0 ;
else if ( V_8 )
V_6 = 0x80 ;
else
V_6 = 0 ;
printf ( L_8 , V_5 , 0x100 - V_6 ) ;
while ( V_6 < 0x100 ) {
int V_21 = V_6 ;
printf ( L_9 ) ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ , V_6 ++ ) {
if ( V_3 [ V_6 ] == V_19 )
printf ( L_10 ) ;
else
printf ( L_11 , V_3 [ V_6 ] ) ;
}
if ( ( V_21 & 0xf ) == 0 )
printf ( L_12 , V_21 ) ;
else
printf ( L_13 , V_6 - 1 ) ;
printf ( L_14 ) ;
}
printf ( L_15 ) ;
return 0 ;
}

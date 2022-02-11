static T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
T_1 V_3 = 0 ;
while ( V_2 ) {
if ( V_2 & 1 )
V_3 ^= V_1 ;
V_1 = ( V_1 << 1 ) ^ ( V_1 & 0x80 ? 0x1d : 0 ) ;
V_2 >>= 1 ;
}
return V_3 ;
}
static T_1 F_2 ( T_1 V_1 , int V_2 )
{
T_1 V_3 = 1 ;
V_2 %= 255 ;
if ( V_2 < 0 )
V_2 += 255 ;
while ( V_2 ) {
if ( V_2 & 1 )
V_3 = F_1 ( V_3 , V_1 ) ;
V_1 = F_1 ( V_1 , V_1 ) ;
V_2 >>= 1 ;
}
return V_3 ;
}
int main ( int V_4 , char * V_5 [] )
{
int V_6 , V_7 , V_8 ;
T_1 V_3 ;
T_1 V_9 [ 256 ] , V_10 [ 256 ] ;
printf ( L_1 ) ;
printf ( L_2 ) ;
printf ( L_3
L_4
L_5 ) ;
for ( V_6 = 0 ; V_6 < 256 ; V_6 ++ ) {
printf ( L_6 ) ;
for ( V_7 = 0 ; V_7 < 256 ; V_7 += 8 ) {
printf ( L_7 ) ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ )
printf ( L_8 , F_1 ( V_6 , V_7 + V_8 ) ,
( V_8 == 7 ) ? '\n' : ' ' ) ;
}
printf ( L_9 ) ;
}
printf ( L_10 ) ;
printf ( L_11 ) ;
printf ( L_12 ) ;
printf ( L_13 ) ;
printf ( L_3
L_14
L_5 ) ;
for ( V_6 = 0 ; V_6 < 256 ; V_6 ++ ) {
printf ( L_6 ) ;
for ( V_7 = 0 ; V_7 < 16 ; V_7 += 8 ) {
printf ( L_7 ) ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ )
printf ( L_8 , F_1 ( V_6 , V_7 + V_8 ) ,
( V_8 == 7 ) ? '\n' : ' ' ) ;
}
for ( V_7 = 0 ; V_7 < 16 ; V_7 += 8 ) {
printf ( L_7 ) ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ )
printf ( L_8 , F_1 ( V_6 , ( V_7 + V_8 ) << 4 ) ,
( V_8 == 7 ) ? '\n' : ' ' ) ;
}
printf ( L_9 ) ;
}
printf ( L_10 ) ;
printf ( L_11 ) ;
printf ( L_15 ) ;
printf ( L_13 ) ;
V_3 = 1 ;
printf ( L_16
L_17 L_5 ) ;
for ( V_6 = 0 ; V_6 < 256 ; V_6 += 8 ) {
printf ( L_18 ) ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ ) {
V_9 [ V_6 + V_7 ] = V_3 ;
printf ( L_8 , V_3 , ( V_7 == 7 ) ? '\n' : ' ' ) ;
V_3 = F_1 ( V_3 , 2 ) ;
if ( V_3 == 1 )
V_3 = 0 ;
}
}
printf ( L_10 ) ;
printf ( L_11 ) ;
printf ( L_19 ) ;
printf ( L_13 ) ;
printf ( L_16
L_20 L_5 ) ;
for ( V_6 = 0 ; V_6 < 256 ; V_6 += 8 ) {
printf ( L_18 ) ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ ) {
V_10 [ V_6 + V_7 ] = V_3 = F_2 ( V_6 + V_7 , 254 ) ;
printf ( L_8 , V_3 , ( V_7 == 7 ) ? '\n' : ' ' ) ;
}
}
printf ( L_10 ) ;
printf ( L_11 ) ;
printf ( L_21 ) ;
printf ( L_13 ) ;
printf ( L_16
L_22 L_5 ) ;
for ( V_6 = 0 ; V_6 < 256 ; V_6 += 8 ) {
printf ( L_18 ) ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ )
printf ( L_8 , V_10 [ V_9 [ V_6 + V_7 ] ^ 1 ] ,
( V_7 == 7 ) ? '\n' : ' ' ) ;
}
printf ( L_10 ) ;
printf ( L_11 ) ;
printf ( L_23 ) ;
printf ( L_13 ) ;
return 0 ;
}

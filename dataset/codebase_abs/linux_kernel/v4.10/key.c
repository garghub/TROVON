char * F_1 ( const T_1 * V_1 , int V_2 , T_2 type )
{
unsigned char V_3 , V_4 ;
unsigned int V_5 ;
char * V_6 ;
int V_7 , V_8 , V_9 , V_10 , V_11 , V_12 ;
F_2 ( L_1 , V_2 ) ;
F_3 ( V_2 < 2 || V_2 > 514 ) ;
V_3 = V_1 [ 0 ] + V_1 [ 1 ] ;
V_12 = 1 ;
for ( V_7 = 2 ; V_7 < V_2 ; V_7 ++ ) {
V_4 = V_1 [ V_7 ] ;
V_3 += V_4 ;
V_12 &= V_13 [ V_4 ] ;
}
if ( V_12 ) {
V_9 = V_2 - 2 ;
V_9 += 2 ;
V_9 += 5 ;
V_9 += 3 * 2 ;
V_9 += 1 ;
} else {
V_2 = ( V_2 + 2 ) / 3 ;
V_9 = V_2 * 4 ;
V_9 += 5 ;
V_9 += 3 * 2 ;
V_9 += 1 ;
}
V_9 += 1 ;
F_4 ( L_2 , V_9 ) ;
V_6 = F_5 ( V_9 , V_14 ) ;
if ( ! V_6 )
return NULL ;
V_8 = 0 ;
sprintf ( V_6 , L_3 , ( unsigned ) V_3 , 0 ) ;
V_8 = 5 ;
V_11 = V_8 - 1 ;
if ( V_12 ) {
V_5 = * ( V_15 * ) V_1 ;
V_1 += 2 ;
V_6 [ V_8 + 1 ] = V_16 [ V_5 & 63 ] ;
V_5 >>= 6 ;
V_6 [ V_8 ] = V_16 [ V_5 & 63 ] ;
V_8 += 2 ;
V_10 = 250 ;
for ( V_7 = V_2 ; V_7 > 0 ; V_7 -- ) {
if ( V_10 <= 0 ) {
V_6 [ V_8 ++ ] = '\0' ;
V_11 = V_8 ;
V_6 [ V_8 ++ ] = '+' ;
V_10 = 252 ;
}
V_6 [ V_8 ++ ] = * V_1 ++ ;
ASSERT ( V_8 < V_9 ) ;
}
switch ( type ) {
case V_17 : type = 'I' ; break;
case V_18 : type = 'D' ; break;
default: type = 'S' ; break;
}
} else {
V_10 = 252 ;
for ( V_7 = V_2 ; V_7 > 0 ; V_7 -- ) {
if ( V_10 <= 0 ) {
V_6 [ V_8 ++ ] = '\0' ;
V_11 = V_8 ;
V_6 [ V_8 ++ ] = '+' ;
V_10 = 252 ;
}
V_5 = * V_1 ++ ;
V_5 |= * V_1 ++ << 8 ;
V_5 |= * V_1 ++ << 16 ;
F_4 ( L_4 , V_5 ) ;
V_6 [ V_8 ++ ] = V_16 [ V_5 & 63 ] ;
V_5 >>= 6 ;
V_6 [ V_8 ++ ] = V_16 [ V_5 & 63 ] ;
V_5 >>= 6 ;
V_6 [ V_8 ++ ] = V_16 [ V_5 & 63 ] ;
V_5 >>= 6 ;
V_6 [ V_8 ++ ] = V_16 [ V_5 & 63 ] ;
ASSERT ( V_8 < V_9 ) ;
}
switch ( type ) {
case V_17 : type = 'J' ; break;
case V_18 : type = 'E' ; break;
default: type = 'T' ; break;
}
}
V_6 [ V_11 ] = type ;
V_6 [ V_8 ++ ] = 0 ;
V_6 [ V_8 ] = 0 ;
F_6 ( L_5 , V_6 , V_8 ) ;
return V_6 ;
}

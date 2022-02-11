unsigned long
F_1 ( const T_1 * V_1 , T_2 V_2 )
{
unsigned long V_3 = 0 ;
while ( * V_1 ++ != 0 && V_3 < V_2 )
V_3 ++ ;
return V_3 ;
}
unsigned long
F_2 ( const T_1 * V_1 )
{
return F_1 ( V_1 , ~ 0UL ) ;
}
unsigned long
F_3 ( const T_1 * V_4 , unsigned long V_2 )
{
return F_1 ( V_4 , V_2 / sizeof( T_1 ) ) * sizeof( T_1 ) ;
}
int
F_4 ( const T_1 * V_5 , const T_1 * V_6 , T_2 V_7 )
{
while ( 1 ) {
if ( V_7 == 0 )
return 0 ;
if ( * V_5 < * V_6 )
return - 1 ;
if ( * V_5 > * V_6 )
return 1 ;
if ( * V_5 == 0 )
return 0 ;
V_5 ++ ;
V_6 ++ ;
V_7 -- ;
}
}
unsigned long
F_5 ( const T_1 * V_8 )
{
unsigned long V_9 ;
unsigned long V_10 = 0 ;
for ( V_9 = 0 ; V_8 [ V_9 ] ; V_9 ++ ) {
T_3 V_11 = V_8 [ V_9 ] ;
if ( V_11 >= 0x800 )
V_10 += 3 ;
else if ( V_11 >= 0x80 )
V_10 += 2 ;
else
V_10 += 1 ;
}
return V_10 ;
}
unsigned long
F_6 ( T_4 * V_12 , const T_1 * V_8 , unsigned long V_2 )
{
unsigned int V_9 ;
unsigned long V_10 = 0 ;
unsigned long V_13 = F_1 ( V_8 , V_2 ) ;
for ( V_9 = 0 ; V_2 && V_9 < V_13 ; V_9 ++ ) {
T_3 V_11 = V_8 [ V_9 ] ;
if ( V_11 >= 0x800 ) {
if ( V_2 < 3 )
break;
V_2 -= 3 ;
V_12 [ V_10 ++ ] = 0xe0 | ( V_11 & 0xf000 ) >> 12 ;
V_12 [ V_10 ++ ] = 0x80 | ( V_11 & 0x0fc0 ) >> 6 ;
V_12 [ V_10 ++ ] = 0x80 | ( V_11 & 0x003f ) ;
} else if ( V_11 >= 0x80 ) {
if ( V_2 < 2 )
break;
V_2 -= 2 ;
V_12 [ V_10 ++ ] = 0xc0 | ( V_11 & 0x7c0 ) >> 6 ;
V_12 [ V_10 ++ ] = 0x80 | ( V_11 & 0x03f ) ;
} else {
V_2 -= 1 ;
V_12 [ V_10 ++ ] = V_11 & 0x7f ;
}
}
if ( V_2 )
V_12 [ V_10 ] = '\0' ;
return V_10 ;
}

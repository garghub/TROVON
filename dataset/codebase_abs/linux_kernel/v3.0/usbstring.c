static int F_1 ( const char * V_1 , T_1 * V_2 , unsigned V_3 )
{
int V_4 = 0 ;
T_2 V_5 ;
T_3 V_6 ;
while ( V_3 != 0 && ( V_5 = ( T_2 ) * V_1 ++ ) != 0 ) {
if ( F_2 ( V_5 & 0x80 ) ) {
if ( ( V_5 & 0xe0 ) == 0xc0 ) {
V_6 = ( V_5 & 0x1f ) << 6 ;
V_5 = ( T_2 ) * V_1 ++ ;
if ( ( V_5 & 0xc0 ) != 0x80 )
goto V_7;
V_5 &= 0x3f ;
V_6 |= V_5 ;
} else if ( ( V_5 & 0xf0 ) == 0xe0 ) {
V_6 = ( V_5 & 0x0f ) << 12 ;
V_5 = ( T_2 ) * V_1 ++ ;
if ( ( V_5 & 0xc0 ) != 0x80 )
goto V_7;
V_5 &= 0x3f ;
V_6 |= V_5 << 6 ;
V_5 = ( T_2 ) * V_1 ++ ;
if ( ( V_5 & 0xc0 ) != 0x80 )
goto V_7;
V_5 &= 0x3f ;
V_6 |= V_5 ;
if ( 0xd800 <= V_6 && V_6 <= 0xdfff )
goto V_7;
} else
goto V_7;
} else
V_6 = V_5 ;
F_3 ( V_6 , V_2 ++ ) ;
V_4 ++ ;
V_3 -- ;
}
return V_4 ;
V_7:
return - 1 ;
}
int
F_4 ( struct V_8 * V_9 , int V_10 , T_2 * V_11 )
{
struct V_12 * V_1 ;
int V_3 ;
if ( V_10 == 0 ) {
V_11 [ 0 ] = 4 ;
V_11 [ 1 ] = V_13 ;
V_11 [ 2 ] = ( T_2 ) V_9 -> V_14 ;
V_11 [ 3 ] = ( T_2 ) ( V_9 -> V_14 >> 8 ) ;
return 4 ;
}
for ( V_1 = V_9 -> V_15 ; V_1 && V_1 -> V_1 ; V_1 ++ )
if ( V_1 -> V_10 == V_10 )
break;
if ( ! V_1 || ! V_1 -> V_1 )
return - V_16 ;
V_3 = F_5 ( ( V_17 ) 126 , strlen ( V_1 -> V_1 ) ) ;
memset ( V_11 + 2 , 0 , 2 * V_3 ) ;
V_3 = F_1 ( V_1 -> V_1 , ( T_1 * ) & V_11 [ 2 ] , V_3 ) ;
if ( V_3 < 0 )
return - V_16 ;
V_11 [ 0 ] = ( V_3 + 1 ) * 2 ;
V_11 [ 1 ] = V_13 ;
return V_11 [ 0 ] ;
}

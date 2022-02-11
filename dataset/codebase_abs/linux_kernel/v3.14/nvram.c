void * F_1 ( const struct V_1 * V_2 , T_1 * V_3 )
{
T_2 * V_4 ;
T_1 V_5 ;
T_1 V_6 ;
T_1 V_7 ;
T_2 V_8 ;
bool V_9 ;
T_1 V_10 ;
T_3 V_11 ;
V_4 = F_2 ( V_2 -> V_12 + 1 + 3 + sizeof( V_11 ) , V_13 ) ;
if ( ! V_4 )
return NULL ;
V_6 = 0 ;
V_7 = 0 ;
V_9 = false ;
for ( V_5 = 0 ; V_5 < V_2 -> V_12 ; V_5 ++ ) {
V_8 = V_2 -> V_14 [ V_5 ] ;
if ( V_8 == 0 )
break;
if ( V_8 == '\r' )
continue;
if ( V_9 && ( V_8 != '\n' ) )
continue;
V_9 = false ;
if ( V_8 == '#' ) {
V_9 = true ;
continue;
}
if ( V_8 == '\n' ) {
if ( V_7 == 0 )
continue;
V_4 [ V_6 ] = 0 ;
V_6 ++ ;
V_7 = 0 ;
continue;
}
V_4 [ V_6 ] = V_8 ;
V_6 ++ ;
V_7 ++ ;
}
V_7 = V_6 ;
* V_3 = F_3 ( V_6 + 1 , 4 ) ;
while ( V_7 != * V_3 ) {
V_4 [ V_7 ] = 0 ;
V_7 ++ ;
}
V_10 = * V_3 / 4 ;
V_10 = ( ~ V_10 << 16 ) | ( V_10 & 0x0000FFFF ) ;
V_11 = F_4 ( V_10 ) ;
memcpy ( & V_4 [ * V_3 ] , & V_11 , sizeof( V_11 ) ) ;
* V_3 += sizeof( V_11 ) ;
return V_4 ;
}
void F_5 ( void * V_4 )
{
F_6 ( V_4 ) ;
}

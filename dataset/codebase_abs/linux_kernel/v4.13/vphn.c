int F_1 ( const long * V_1 , T_1 * V_2 )
{
T_2 V_3 [ V_4 ] ;
int V_5 , V_6 = 0 ;
const T_3 * V_7 = ( const T_3 * ) V_3 ;
T_4 V_8 = 0 ;
bool V_9 = false ;
#define F_2 (0xffff)
#define F_3 (0x8000)
#define F_4 (~VPHN_FIELD_MSB)
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ )
V_3 [ V_5 ] = F_5 ( V_1 [ V_5 ] ) ;
for ( V_5 = 1 ; V_5 < V_10 ; V_5 ++ ) {
T_4 V_11 = F_6 ( V_7 ++ ) ;
if ( V_9 ) {
V_2 [ ++ V_6 ] =
F_7 ( V_8 << 16 | V_11 ) ;
V_9 = false ;
} else if ( V_11 == F_2 )
break;
else if ( V_11 & F_3 ) {
V_2 [ ++ V_6 ] =
F_7 ( V_11 & F_4 ) ;
} else {
V_8 = V_11 ;
V_9 = true ;
}
}
V_2 [ 0 ] = F_7 ( V_6 ) ;
return V_6 ;
}

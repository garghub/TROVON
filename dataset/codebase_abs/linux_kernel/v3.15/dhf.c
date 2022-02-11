static int
F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
int V_3 = V_4 ;
T_3 * V_5 ;
switch ( V_1 -> V_6 -> V_7 ) {
case V_8 :
case V_9 :
break;
default:
F_2 (DO_ASSERT, fw->identity->typ)
V_3 = V_10 ;
return V_3 ;
}
V_2 = V_1 -> V_11 ;
V_5 = NULL ;
while ( V_2 -> V_12 && V_5 == NULL ) {
if ( V_2 -> V_7 == V_13 ) {
V_5 = F_3 ( ( void * ) V_2 , & V_14 ) ;
}
V_2 ++ ;
}
F_2 (i, 0 )
if ( V_5 ) {
V_2 = V_1 -> V_11 ;
V_5 = NULL ;
while ( V_2 -> V_12 && V_5 == NULL ) {
if ( V_2 -> V_7 == V_15 ) {
V_5 = F_3 ( ( void * ) V_2 , & V_16 ) ;
}
V_2 ++ ;
}
F_2 (i, 0 )
}
if ( V_5 == NULL ) {
V_3 = V_10 ;
}
return V_3 ;
}
int
F_4 ( T_1 * V_1 )
{
int V_3 = V_4 ;
T_4 * V_2 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < sizeof( V_17 ) && V_1 -> V_17 [ V_5 ] == V_17 [ V_5 ] ; V_5 ++ )
;
if ( V_5 != sizeof( V_17 ) ||
V_1 -> V_17 [ V_5 ] != 0x01 ||
V_1 -> V_17 [ V_5 + 1 ] != ( 'L' ) )
V_3 = V_10 ;
else {
V_1 -> V_18 = ( T_4 V_19 * ) ( ( char * ) V_1 -> V_18 + ( V_20 ) V_1 ) ;
V_1 -> V_6 = ( V_21 V_19 * ) ( ( char * ) V_1 -> V_6 + ( V_20 ) V_1 ) ;
V_1 -> V_11 = ( T_2 V_19 * ) ( ( char * ) V_1 -> V_11 + ( V_20 ) V_1 ) ;
for ( V_5 = 0 ; V_1 -> V_2 [ V_5 ] ; V_5 ++ )
V_1 -> V_2 [ V_5 ] = ( ( char * ) V_1 -> V_2 [ V_5 ] + ( V_20 ) V_1 ) ;
V_2 = V_1 -> V_18 ;
while ( V_2 -> V_12 ) {
V_2 -> V_22 = ( char * ) V_2 -> V_22 + ( V_20 ) V_1 ;
V_2 ++ ;
}
}
return V_3 ;
}
int
F_5 ( void * V_23 , T_1 * V_1 )
{
int V_3 = V_4 ;
T_5 V_24 = V_25 ;
T_4 * V_2 = V_1 -> V_18 ;
T_6 V_26 ;
int V_5 ;
F_2 (fw != NULL, 0 )
for ( V_5 = 0 ; V_5 < sizeof( V_17 ) && V_1 -> V_17 [ V_5 ] == V_17 [ V_5 ] ; V_5 ++ )
;
if ( V_5 != sizeof( V_17 ) ||
V_1 -> V_17 [ V_5 ] != 0x01 ||
( V_1 -> V_17 [ V_5 + 1 ] != 'C' && V_1 -> V_17 [ V_5 + 1 ] != ( 'L' ) ) )
V_3 = V_10 ;
while ( ( V_3 == V_4 ) && ( ( V_26 = V_24 -> V_26 ) != NULL ) ) {
V_26 -> V_12 = V_24 ++ -> V_12 ;
V_3 = F_6 ( V_26 ) ;
F_2 (rc == HCF_SUCCESS, rc)
F_2 (rc == HCF_SUCCESS, ltvp->typ)
F_2 (rc == HCF_SUCCESS, ltvp->len)
}
if ( V_3 == V_4 )
V_3 = F_1 ( V_1 ) ;
if ( V_3 == V_4 ) {
while ( V_3 == V_4 && V_2 -> V_12 ) {
V_3 = F_7 ( V_2 ) ;
V_2 ++ ;
}
}
F_2 (rc == HCF_SUCCESS, rc)
return V_3 ;
}

T_1 * F_1 ( T_2 * V_1 , T_1 * V_2 , unsigned char V_3 )
{
int V_4 , V_5 ;
if ( V_2 == ( T_1 * ) NULL ) {
V_4 = 0 ;
} else {
for ( V_5 = 0 ; V_5 < F_2 ( V_1 ) ; V_5 ++ )
if ( V_2 == F_3 ( V_1 , V_5 ) )
break;
V_4 = V_5 ;
if ( V_4 == F_2 ( V_1 ) ) {
F_4 ( L_1 , V_2 ) ;
return ( T_1 * ) NULL ;
}
V_4 ++ ;
}
for (; V_4 < F_2 ( V_1 ) ; V_4 ++ ) {
V_2 = F_3 ( V_1 , V_4 ) ;
if ( F_5 ( V_2 ) == V_3 )
return V_2 ;
}
return ( T_1 * ) NULL ;
}
T_1 * F_6 ( T_2 * V_1 , unsigned char V_3 )
{
return F_1 ( V_1 , ( T_1 * ) NULL , V_3 ) ;
}
T_2 * F_7 ( T_2 * V_6 , unsigned char V_7 )
{
while ( V_6 ) {
if ( V_6 -> V_7 == V_7 )
return V_6 ;
V_6 = F_8 ( V_6 ) ;
}
return ( T_2 * ) NULL ;
}
T_2 * F_9 ( T_2 * V_6 , unsigned char V_7 )
{
while ( V_6 ) {
if ( F_10 ( V_6 -> V_7 ) == F_10 ( V_7 ) )
return V_6 ;
V_6 = F_8 ( V_6 ) ;
}
return ( T_2 * ) NULL ;
}
T_3 F_11 ( T_4 V_8 )
{
return F_12 ( V_8 ) ;
}
T_5 * F_13 ( T_6 V_9 , int V_10 )
{
T_2 * V_1 ;
T_5 * V_11 ;
if ( ! ( V_1 = F_7 ( ( T_2 * ) F_14 ( V_9 ) , V_12 ) ) )
return ( T_5 * ) NULL ;
if ( ! ( V_11 = ( T_5 * ) F_6 ( V_1 , V_13 ) ) )
return ( T_5 * ) NULL ;
do {
if ( ( V_11 -> V_14 . V_15 ) == V_10 )
return V_11 ;
} while ( ( V_11 = ( T_5 * ) F_1 ( V_1 , ( T_1 * ) V_11 ,
V_13 ) ) );
return ( T_5 * ) NULL ;
}
T_5 * F_15 ( T_4 V_8 )
{
T_6 V_9 ;
int V_10 ;
T_5 * V_11 ;
T_7 * V_16 = V_17 ;
T_3 V_18 ;
if ( ! ( V_8 < V_19 ) ) {
F_4 ( L_2 , V_8 ) ;
return NULL ;
}
V_18 = F_11 ( V_8 ) ;
if ( V_18 == V_20 )
return NULL ;
if ( ( V_9 = V_16 -> V_21 [ V_18 ] ) == V_22 )
return NULL ;
for ( V_10 = 0 ; V_10 < V_23 ; V_10 ++ ) {
V_11 = F_13 ( V_9 , V_10 ) ;
if ( V_11 && V_11 -> V_14 . V_24 == V_8 )
return V_11 ;
}
return NULL ;
}
int F_16 ( T_4 V_8 )
{
T_5 * V_11 ;
if ( ( V_11 = F_15 ( V_8 ) ) == NULL )
return - 1 ;
return V_11 -> V_14 . V_15 ;
}

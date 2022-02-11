int F_1 ( T_1 * V_1 )
{
if ( ! V_1 ) {
return - 1 ;
}
return V_1 -> V_2 ;
}
const char * F_2 ( T_1 * V_1 )
{
return V_1 -> V_3 ;
}
T_2 F_3 ( T_1 * V_1 )
{
return V_1 -> V_4 ;
}
T_3 F_4 ( T_1 * V_1 ) {
return V_1 -> V_5 ;
}
const T_4 * F_5 ( T_1 * V_1 )
{
return V_1 -> V_6 ;
}
void
F_6 ( const int V_2 , const char * V_7 , T_3 V_5 , T_3 V_8 , const T_4 * V_6 ,
T_2 V_9 , T_5 V_10 )
{
T_1 * V_11 ;
F_7 ( V_9 ) ;
V_11 = F_8 ( F_9 () , T_1 ) ;
V_11 -> V_2 = V_2 ;
if ( V_7 != NULL )
V_11 -> V_3 = V_7 ;
else
V_11 -> V_3 = F_10 ( V_2 ) ;
V_11 -> V_4 = V_9 ;
V_11 -> V_5 = V_5 ;
V_11 -> V_8 = V_8 ;
V_11 -> V_6 = V_6 ;
V_11 -> V_12 = V_10 ;
if ( V_13 == NULL )
V_13 = F_11 ( F_9 () ) ;
F_12 ( V_13 , F_10 ( V_2 ) , V_11 , 0 ) ;
}
void F_13 ( T_6 * V_11 , T_7 V_14 , void * V_15 )
{
T_3 V_16 ;
for ( V_16 = 0 ; V_16 < V_11 -> V_17 ; V_16 ++ )
{
F_14 ( V_11 -> V_18 [ V_16 ] . V_1 ) ;
}
F_14 ( V_11 -> V_18 ) ;
V_11 -> V_18 = NULL ;
V_11 -> V_17 = 0 ;
if ( V_14 )
V_14 ( V_11 , V_15 ) ;
}
void F_15 ( T_6 * V_11 , T_8 V_14 , void * V_15 )
{
T_3 V_16 = 0 ;
for ( V_16 = 0 ; V_16 < V_11 -> V_17 ; V_16 ++ )
memset ( V_11 -> V_18 [ V_16 ] . V_1 , 0 , sizeof( V_19 ) * V_11 -> V_18 [ V_16 ] . V_20 ) ;
if ( V_14 )
V_14 ( V_11 , V_15 ) ;
}
T_1 * F_16 ( const char * V_21 )
{
return ( T_1 * ) F_17 ( V_13 , V_21 , 0 ) ;
}
T_9 * F_18 ( T_1 * V_1 )
{
T_10 * V_22 = F_19 ( F_10 ( V_1 -> V_2 ) ) ;
F_20 ( V_22 , L_1 ) ;
return F_21 ( V_22 , FALSE ) ;
}
void F_22 ( T_1 * V_1 , const char * V_23 , const char * * V_24 , char * * V_25 )
{
T_9 * V_22 = F_18 ( V_1 ) ;
T_3 V_26 = ( T_3 ) strlen ( V_22 ) ;
* V_24 = NULL ;
* V_25 = NULL ;
if ( ! strncmp ( V_23 , V_22 , V_26 ) )
{
if ( V_23 [ V_26 ] == ',' )
{
* V_24 = V_23 + V_26 + 1 ;
}
}
if ( V_1 -> V_12 )
V_1 -> V_12 ( V_23 , V_24 , V_25 ) ;
F_14 ( V_22 ) ;
}
void F_23 ( T_1 * V_1 , T_6 * V_11 , T_11 V_14 , void * V_15 )
{
T_3 V_16 ;
V_11 -> V_17 = V_1 -> V_5 ;
V_11 -> V_18 = F_24 ( V_27 , V_1 -> V_5 ) ;
for ( V_16 = 0 ; V_16 < V_11 -> V_17 ; V_16 ++ )
{
V_11 -> V_18 [ V_16 ] . V_20 = V_1 -> V_8 ;
V_11 -> V_18 [ V_16 ] . V_1 = F_24 ( V_19 , V_1 -> V_8 ) ;
}
if ( V_14 )
V_14 ( V_11 , V_15 ) ;
}
void F_25 ( T_12 V_28 , T_13 V_29 )
{
F_26 ( V_13 , V_28 , V_29 ) ;
}

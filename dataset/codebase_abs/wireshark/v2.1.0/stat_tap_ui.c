static T_1
F_1 ( T_2 V_1 , T_2 V_2 )
{
return strcmp ( ( ( const V_3 * ) V_1 ) -> V_4 , ( ( const V_3 * ) V_2 ) -> V_4 ) ;
}
void
F_2 ( T_3 * V_5 , void * V_6 )
{
V_3 * V_7 ;
V_7 = ( V_3 * ) F_3 ( sizeof( V_3 ) ) ;
V_7 -> V_4 = V_5 -> V_8 ;
V_7 -> V_9 = V_5 -> V_10 ;
V_7 -> V_6 = V_6 ;
V_11 = F_4 ( V_11 , V_7 , F_1 ) ;
}
T_4
F_5 ( char * V_12 )
{
T_5 * V_13 ;
V_3 * V_14 ;
T_6 * V_15 ;
for( V_13 = F_6 ( V_11 ) ; V_13 ; V_13 = F_7 ( V_13 ) ) {
V_14 = ( V_3 * ) V_13 -> V_16 ;
if( ! strncmp ( V_14 -> V_4 , V_12 , strlen ( V_14 -> V_4 ) ) ) {
V_15 = ( T_6 * ) F_3 ( sizeof ( T_6 ) ) ;
V_15 -> V_14 = V_14 ;
V_15 -> V_17 = F_8 ( V_12 ) ;
V_18 = F_9 ( V_18 , V_15 ) ;
return TRUE ;
}
}
return FALSE ;
}
void
F_10 ( void )
{
T_5 * V_13 ;
V_3 * V_14 ;
for( V_13 = V_11 ; V_13 ; V_13 = F_11 ( V_13 ) ) {
V_14 = ( V_3 * ) V_13 -> V_16 ;
fprintf ( V_19 , L_1 , V_14 -> V_4 ) ;
}
}
void
F_12 ( void )
{
T_6 * V_20 ;
while( V_18 ) {
V_20 = ( T_6 * ) V_18 -> V_16 ;
(* V_20 -> V_14 -> V_9 )( V_20 -> V_17 , V_20 -> V_14 -> V_6 ) ;
F_13 ( V_20 -> V_17 ) ;
F_13 ( V_20 ) ;
V_18 = F_14 ( V_18 , V_20 ) ;
}
}
static T_1
F_15 ( T_2 V_21 , T_2 V_22 )
{
const T_7 * V_1 = ( const T_7 * ) V_21 ;
const T_7 * V_2 = ( const T_7 * ) V_22 ;
return F_16 ( V_1 -> V_8 , V_2 -> V_8 ) ;
}
void F_17 ( T_7 * V_5 )
{
V_23 = F_18 ( V_23 , V_5 , F_15 ) ;
}
void F_19 ( T_8 V_9 , T_9 V_24 )
{
F_20 ( V_23 , V_9 , V_24 ) ;
}
void F_21 ( T_7 * V_25 , const char * V_26 , const char * * V_27 , char * * V_28 )
{
T_10 V_29 = ( T_10 ) strlen ( V_25 -> V_8 ) ;
* V_27 = NULL ;
* V_28 = NULL ;
if ( ! strncmp ( V_26 , V_25 -> V_8 , V_29 ) )
{
if ( V_26 [ V_29 ] == ',' )
{
* V_27 = V_26 + V_29 + 1 ;
}
}
if ( V_25 -> V_30 )
V_25 -> V_30 ( V_26 , V_27 , V_28 ) ;
}
T_11 * F_22 ( const char * V_31 , int V_32 , int V_33 ,
const char * V_34 , T_12 V_35 , void * V_36 )
{
T_11 * V_37 = F_23 ( T_11 , 1 ) ;
V_37 -> V_38 = V_31 ;
V_37 -> V_33 = V_33 ;
V_37 -> V_32 = V_32 ;
V_37 -> V_34 = V_34 ;
V_37 -> V_39 = F_23 ( V_40 * , V_33 ) ;
if ( V_35 )
V_35 ( V_37 , V_36 ) ;
return V_37 ;
}
void F_24 ( T_7 * V_25 , T_11 * V_41 )
{
if ( V_25 -> V_42 == NULL )
V_25 -> V_42 = F_25 ( FALSE , TRUE , sizeof( T_11 * ) ) ;
F_26 ( V_25 -> V_42 , V_25 -> V_42 -> V_29 , V_41 ) ;
}
void F_27 ( T_11 * V_43 , T_10 V_44 , T_10 V_32 , const V_40 * V_45 )
{
if( V_44 >= V_43 -> V_33 ) {
T_10 V_46 = V_43 -> V_33 ;
T_10 V_47 ;
V_43 -> V_33 = V_44 + 1 ;
V_43 -> V_39 = ( V_40 * * ) F_28 ( V_43 -> V_39 , sizeof( V_40 * ) * ( V_43 -> V_33 ) ) ;
for( V_47 = V_46 ; V_47 < V_43 -> V_33 ; V_47 ++ ) {
V_43 -> V_39 [ V_47 ] = F_23 ( V_40 , V_43 -> V_32 ) ;
}
}
memcpy ( V_43 -> V_39 [ V_44 ] , V_45 , V_32 * sizeof( V_40 ) ) ;
}
V_40 * F_29 ( const T_11 * V_43 , T_10 V_44 , T_10 V_48 )
{
V_40 * V_49 ;
F_30 ( V_44 < V_43 -> V_33 ) ;
V_49 = V_43 -> V_39 [ V_44 ] ;
F_30 ( V_48 < V_43 -> V_32 ) ;
return & V_49 [ V_48 ] ;
}
void F_31 ( T_11 * V_43 , T_10 V_44 , T_10 V_48 , V_40 * V_50 )
{
V_40 * V_49 ;
F_30 ( V_44 < V_43 -> V_33 ) ;
V_49 = V_43 -> V_39 [ V_44 ] ;
F_30 ( V_48 < V_43 -> V_32 ) ;
V_49 [ V_48 ] = * V_50 ;
}
void F_32 ( T_7 * V_25 , T_13 V_35 , void * V_51 )
{
T_10 V_47 = 0 ;
T_11 * V_43 ;
for ( V_47 = 0 ; V_47 < V_25 -> V_42 -> V_29 ; V_47 ++ )
{
V_43 = F_33 ( V_25 -> V_42 , T_11 * , V_47 ) ;
if ( V_35 )
V_35 ( V_43 , V_51 ) ;
if ( V_25 -> V_52 )
V_25 -> V_52 ( V_43 ) ;
}
}
void F_34 ( T_7 * V_25 , T_14 V_35 , void * V_51 )
{
T_10 V_47 = 0 , V_53 , V_48 ;
T_11 * V_43 ;
V_40 * V_50 ;
for ( V_47 = 0 ; V_47 < V_25 -> V_42 -> V_29 ; V_47 ++ )
{
V_43 = F_33 ( V_25 -> V_42 , T_11 * , V_47 ) ;
if ( V_35 )
V_35 ( V_43 , V_51 ) ;
for ( V_53 = 0 ; V_53 < V_43 -> V_33 ; V_53 ++ )
{
for ( V_48 = 0 ; V_48 < V_43 -> V_32 ; V_48 ++ )
{
V_50 = F_29 ( V_43 , V_53 , V_48 ) ;
if ( V_25 -> V_54 )
V_25 -> V_54 ( V_43 , V_53 , V_48 , V_50 ) ;
}
F_13 ( V_43 -> V_39 [ V_53 ] ) ;
}
F_13 ( V_43 -> V_39 ) ;
F_13 ( V_43 ) ;
}
F_35 ( V_25 -> V_42 , 0 ) ;
}

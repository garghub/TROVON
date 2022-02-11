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
int F_3 ( T_1 * V_1 )
{
return V_1 -> V_4 ;
}
T_2 F_4 ( T_1 * V_1 )
{
return V_1 -> V_5 ;
}
void F_5 ( T_1 * V_1 , void * V_6 )
{
V_1 -> V_7 = V_6 ;
}
void * F_6 ( T_1 * V_1 )
{
return V_1 -> V_7 ;
}
void
F_7 ( T_3 * V_8 )
{
int V_9 ;
for( V_9 = 0 ; V_9 < V_8 -> V_10 ; V_9 ++ ) {
F_8 ( V_8 -> V_11 [ V_9 ] . V_12 ) ;
V_8 -> V_11 [ V_9 ] . V_12 = NULL ;
}
F_8 ( V_8 -> V_13 ) ;
V_8 -> V_13 = NULL ;
F_8 ( V_8 -> V_11 ) ;
V_8 -> V_11 = NULL ;
V_8 -> V_10 = 0 ;
}
void F_9 ( T_1 * V_1 , T_4 * V_14 , T_5 V_15 , void * V_16 )
{
T_6 V_9 = 0 ;
T_3 * V_17 ;
for ( V_9 = 0 ; V_9 < V_14 -> V_18 ; V_9 ++ )
{
V_17 = F_10 ( V_14 , T_3 * , V_9 ) ;
if ( V_15 )
V_15 ( V_17 , V_16 ) ;
F_7 ( V_17 ) ;
}
F_11 ( V_14 , 0 ) ;
F_8 ( V_1 -> V_7 ) ;
V_1 -> V_7 = NULL ;
}
static void F_12 ( T_3 * V_8 )
{
int V_9 ;
for( V_9 = 0 ; V_9 < V_8 -> V_10 ; V_9 ++ ) {
F_13 ( & V_8 -> V_11 [ V_9 ] . V_19 ) ;
}
}
void F_14 ( T_4 * V_14 , T_7 V_15 , void * V_16 )
{
T_6 V_9 = 0 ;
T_3 * V_17 ;
for ( V_9 = 0 ; V_9 < V_14 -> V_18 ; V_9 ++ )
{
V_17 = F_10 ( V_14 , T_3 * , V_9 ) ;
if ( V_15 )
V_15 ( V_17 , V_16 ) ;
F_12 ( V_17 ) ;
}
}
T_1 * F_15 ( const char * V_20 )
{
return ( T_1 * ) F_16 ( V_21 , V_20 , 0 ) ;
}
T_8 * F_17 ( T_1 * V_1 )
{
T_9 * V_22 = F_18 ( F_19 ( V_1 -> V_2 ) ) ;
F_20 ( V_22 , L_1 ) ;
return F_21 ( V_22 , FALSE ) ;
}
void F_22 ( T_1 * V_1 , const char * V_23 , const char * * V_24 , char * * V_25 )
{
T_8 * V_22 = F_17 ( V_1 ) ;
T_6 V_18 = ( V_26 ) strlen ( V_22 ) ;
T_6 V_27 = V_18 ;
* V_24 = NULL ;
* V_25 = NULL ;
if( ! strncmp ( V_23 , V_22 , V_18 ) )
{
if ( V_1 -> V_28 != NULL )
{
V_27 = V_1 -> V_28 ( V_1 , V_23 + V_18 , V_25 ) ;
if ( * V_25 != NULL )
return;
if ( V_27 > 0 )
V_27 += V_18 ;
}
if ( V_23 [ V_27 ] == ',' )
{
* V_24 = V_23 + V_27 + 1 ;
}
}
F_8 ( V_22 ) ;
}
void F_23 ( T_1 * V_1 , T_4 * V_14 , T_10 V_15 , void * V_16 )
{
V_1 -> V_29 ( V_1 , V_14 , V_15 , V_16 ) ;
}
void
F_24 ( const int V_2 , const char * V_30 , int V_4 , T_2 V_31 , T_11 V_32 , T_12 V_28 )
{
T_1 * V_33 ;
F_25 ( V_32 ) ;
F_25 ( V_31 ) ;
V_33 = F_26 ( F_27 () , T_1 ) ;
V_33 -> V_2 = V_2 ;
if ( V_30 != NULL )
V_33 -> V_3 = V_30 ;
else
V_33 -> V_3 = F_19 ( V_2 ) ;
V_33 -> V_4 = V_4 ;
V_33 -> V_5 = V_31 ;
V_33 -> V_29 = V_32 ;
V_33 -> V_28 = V_28 ;
V_33 -> V_7 = NULL ;
if ( V_21 == NULL )
V_21 = F_28 ( F_27 () ) ;
F_29 ( V_21 , F_19 ( V_2 ) , V_33 , 0 ) ;
}
void F_30 ( T_13 V_34 , T_14 V_35 )
{
F_31 ( V_21 , V_34 , V_35 ) ;
}
T_3 *
F_32 ( const char * V_20 , const char * V_36 , T_4 * V_14 , int V_10 , const char * V_37 ,
const char * V_13 , T_10 V_15 , void * V_38 , void * V_39 )
{
int V_9 ;
T_3 * V_33 = F_33 ( T_3 , 1 ) ;
if( V_13 ) {
V_33 -> V_13 = F_34 ( V_13 ) ;
} else {
V_33 -> V_13 = NULL ;
}
V_33 -> V_20 = V_20 ;
V_33 -> V_36 = V_36 ;
V_33 -> V_37 = V_37 ;
V_33 -> V_10 = V_10 ;
V_33 -> V_11 = ( V_40 * ) F_35 ( sizeof( V_40 ) * V_10 ) ;
for( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
F_13 ( & V_33 -> V_11 [ V_9 ] . V_19 ) ;
V_33 -> V_11 [ V_9 ] . V_41 = 0 ;
V_33 -> V_11 [ V_9 ] . V_12 = NULL ;
}
F_36 ( V_14 , V_14 -> V_18 , V_33 ) ;
V_33 -> V_39 = V_39 ;
if ( V_15 )
V_15 ( V_33 , V_38 ) ;
return V_33 ;
}
void
F_37 ( T_3 * V_8 , int V_42 , const char * V_12 )
{
if( V_42 >= V_8 -> V_10 ) {
int V_43 = V_8 -> V_10 ;
int V_9 ;
V_8 -> V_10 = V_42 + 1 ;
V_8 -> V_11 = ( V_40 * ) F_38 ( V_8 -> V_11 , sizeof( V_40 ) * ( V_8 -> V_10 ) ) ;
for( V_9 = V_43 ; V_9 < V_8 -> V_10 ; V_9 ++ ) {
F_13 ( & V_8 -> V_11 [ V_9 ] . V_19 ) ;
V_8 -> V_11 [ V_9 ] . V_41 = V_9 ;
V_8 -> V_11 [ V_9 ] . V_12 = NULL ;
}
}
V_8 -> V_11 [ V_42 ] . V_41 = V_42 ;
V_8 -> V_11 [ V_42 ] . V_12 = F_34 ( V_12 ) ;
}
void
F_39 ( T_3 * V_8 , int V_42 , const T_15 * V_44 , T_16 * V_45 )
{
V_40 * V_46 ;
T_15 V_47 , V_48 ;
F_40 ( V_42 >= 0 && V_42 < V_8 -> V_10 ) ;
V_46 = & V_8 -> V_11 [ V_42 ] ;
V_47 = V_45 -> V_49 ;
F_41 ( & V_48 , & V_47 , V_44 ) ;
F_42 ( & V_46 -> V_19 , & V_48 , V_45 ) ;
}

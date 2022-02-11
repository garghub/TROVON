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
T_6 V_9 , V_21 = F_16 ( V_22 ) ;
T_1 * V_1 ;
T_8 * V_23 ;
for ( V_9 = 0 ; V_9 < V_21 ; V_9 ++ ) {
V_23 = F_17 ( V_22 , V_9 ) ;
V_1 = ( T_1 * ) V_23 -> V_6 ;
if ( strcmp ( V_20 , F_18 ( V_1 -> V_2 ) ) == 0 )
return V_1 ;
}
return NULL ;
}
T_9 * F_19 ( T_1 * V_1 )
{
T_10 * V_24 = F_20 ( F_18 ( V_1 -> V_2 ) ) ;
F_21 ( V_24 , L_1 ) ;
return F_22 ( V_24 , FALSE ) ;
}
void F_23 ( T_1 * V_1 , const char * V_25 , const char * * V_26 , char * * V_27 )
{
T_9 * V_24 = F_19 ( V_1 ) ;
T_6 V_18 = ( V_28 ) strlen ( V_24 ) ;
T_6 V_29 = V_18 ;
* V_26 = NULL ;
* V_27 = NULL ;
if( ! strncmp ( V_25 , V_24 , V_18 ) )
{
if ( V_1 -> V_30 != NULL )
{
V_29 = V_1 -> V_30 ( V_1 , V_25 + V_18 , V_27 ) ;
if ( * V_27 != NULL )
return;
if ( V_29 > 0 )
V_29 += V_18 ;
}
if ( V_25 [ V_29 ] == ',' )
{
* V_26 = V_25 + V_29 + 1 ;
}
}
F_8 ( V_24 ) ;
}
void F_24 ( T_1 * V_1 , T_4 * V_14 , T_11 V_15 , void * V_16 )
{
V_1 -> V_31 ( V_1 , V_14 , V_15 , V_16 ) ;
}
static T_12
F_25 ( T_13 V_32 , T_13 V_33 )
{
const T_1 * V_34 = ( const T_1 * ) V_32 ;
const T_1 * V_35 = ( const T_1 * ) V_33 ;
return F_26 ( F_27 ( F_28 ( V_34 -> V_2 ) ) , F_27 ( F_28 ( V_35 -> V_2 ) ) ) ;
}
void
F_29 ( const int V_2 , const char * V_36 , int V_4 , T_2 V_37 , T_14 V_38 , T_15 V_30 )
{
T_1 * V_39 ;
F_30 ( V_38 ) ;
F_30 ( V_37 ) ;
V_39 = F_31 ( T_1 , 1 ) ;
V_39 -> V_2 = V_2 ;
if ( V_36 != NULL )
V_39 -> V_3 = V_36 ;
else
V_39 -> V_3 = F_18 ( V_2 ) ;
V_39 -> V_4 = V_4 ;
V_39 -> V_5 = V_37 ;
V_39 -> V_31 = V_38 ;
V_39 -> V_30 = V_30 ;
V_39 -> V_7 = NULL ;
V_22 = F_32 ( V_22 , V_39 , F_25 ) ;
}
void F_33 ( T_16 V_40 , T_17 V_41 )
{
F_34 ( V_22 , V_40 , V_41 ) ;
}
T_3 *
F_35 ( const char * V_20 , const char * V_42 , T_4 * V_14 , int V_10 , const char * V_43 ,
const char * V_13 , T_11 V_15 , void * V_44 , void * V_45 )
{
int V_9 ;
T_3 * V_39 = F_31 ( T_3 , 1 ) ;
if( V_13 ) {
V_39 -> V_13 = F_36 ( V_13 ) ;
} else {
V_39 -> V_13 = NULL ;
}
V_39 -> V_20 = V_20 ;
V_39 -> V_42 = V_42 ;
V_39 -> V_43 = V_43 ;
V_39 -> V_10 = V_10 ;
V_39 -> V_11 = ( V_46 * ) F_37 ( sizeof( V_46 ) * V_10 ) ;
for( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
F_13 ( & V_39 -> V_11 [ V_9 ] . V_19 ) ;
V_39 -> V_11 [ V_9 ] . V_47 = 0 ;
V_39 -> V_11 [ V_9 ] . V_12 = NULL ;
}
F_38 ( V_14 , V_14 -> V_18 , V_39 ) ;
V_39 -> V_45 = V_45 ;
if ( V_15 )
V_15 ( V_39 , V_44 ) ;
return V_39 ;
}
void
F_39 ( T_3 * V_8 , int V_48 , const char * V_12 )
{
if( V_48 >= V_8 -> V_10 ) {
int V_49 = V_8 -> V_10 ;
int V_9 ;
V_8 -> V_10 = V_48 + 1 ;
V_8 -> V_11 = ( V_46 * ) F_40 ( V_8 -> V_11 , sizeof( V_46 ) * ( V_8 -> V_10 ) ) ;
for( V_9 = V_49 ; V_9 < V_8 -> V_10 ; V_9 ++ ) {
F_13 ( & V_8 -> V_11 [ V_9 ] . V_19 ) ;
V_8 -> V_11 [ V_9 ] . V_47 = V_9 ;
V_8 -> V_11 [ V_9 ] . V_12 = NULL ;
}
}
V_8 -> V_11 [ V_48 ] . V_47 = V_48 ;
V_8 -> V_11 [ V_48 ] . V_12 = F_36 ( V_12 ) ;
}
void
F_41 ( T_3 * V_8 , int V_48 , const T_18 * V_50 , T_19 * V_51 )
{
V_46 * V_52 ;
T_18 V_53 , V_54 ;
F_42 ( V_48 >= 0 && V_48 < V_8 -> V_10 ) ;
V_52 = & V_8 -> V_11 [ V_48 ] ;
V_53 = V_51 -> V_55 ;
F_43 ( & V_54 , & V_53 , V_50 ) ;
F_44 ( & V_52 -> V_19 , & V_54 , V_51 ) ;
}

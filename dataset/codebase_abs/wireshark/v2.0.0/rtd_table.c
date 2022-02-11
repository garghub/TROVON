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
static T_5
F_6 ( T_6 V_7 , T_6 V_8 )
{
const T_1 * V_9 = ( T_1 * ) V_7 ;
const T_1 * V_10 = ( T_1 * ) V_8 ;
return F_7 ( F_8 ( F_9 ( V_9 -> V_2 ) ) , F_8 ( F_9 ( V_10 -> V_2 ) ) ) ;
}
void
F_10 ( const int V_2 , const char * V_11 , T_3 V_5 , T_3 V_12 , const T_4 * V_6 ,
T_2 V_13 , T_7 V_14 )
{
T_1 * V_15 ;
F_11 ( V_13 ) ;
V_15 = F_12 ( T_1 , 1 ) ;
V_15 -> V_2 = V_2 ;
if ( V_11 != NULL )
V_15 -> V_3 = V_11 ;
else
V_15 -> V_3 = F_13 ( V_2 ) ;
V_15 -> V_4 = V_13 ;
V_15 -> V_5 = V_5 ;
V_15 -> V_12 = V_12 ;
V_15 -> V_6 = V_6 ;
V_15 -> V_16 = V_14 ;
V_17 = F_14 ( V_17 , V_15 , F_6 ) ;
}
void F_15 ( T_8 * V_15 , T_9 V_18 , void * V_19 )
{
T_3 V_20 ;
for ( V_20 = 0 ; V_20 < V_15 -> V_21 ; V_20 ++ )
{
F_16 ( V_15 -> V_22 [ V_20 ] . V_1 ) ;
}
F_16 ( V_15 -> V_22 ) ;
V_15 -> V_22 = NULL ;
V_15 -> V_21 = 0 ;
if ( V_18 )
V_18 ( V_15 , V_19 ) ;
}
void F_17 ( T_8 * V_15 , T_10 V_18 , void * V_19 )
{
T_3 V_20 = 0 ;
for ( V_20 = 0 ; V_20 < V_15 -> V_21 ; V_20 ++ )
memset ( V_15 -> V_22 [ V_20 ] . V_1 , 0 , sizeof( V_23 ) * V_15 -> V_22 [ V_20 ] . V_24 ) ;
if ( V_18 )
V_18 ( V_15 , V_19 ) ;
}
T_1 * F_18 ( const char * V_25 )
{
T_3 V_20 , V_26 = F_19 ( V_17 ) ;
T_1 * V_1 ;
T_11 * V_27 ;
for ( V_20 = 0 ; V_20 < V_26 ; V_20 ++ ) {
V_27 = F_20 ( V_17 , V_20 ) ;
V_1 = ( T_1 * ) V_27 -> V_28 ;
if ( strcmp ( V_25 , F_13 ( V_1 -> V_2 ) ) == 0 )
return V_1 ;
}
return NULL ;
}
T_12 * F_21 ( T_1 * V_1 )
{
T_13 * V_29 = F_22 ( F_13 ( V_1 -> V_2 ) ) ;
F_23 ( V_29 , L_1 ) ;
return F_24 ( V_29 , FALSE ) ;
}
void F_25 ( T_1 * V_1 , const char * V_30 , const char * * V_31 , char * * V_32 )
{
T_12 * V_29 = F_21 ( V_1 ) ;
T_3 V_33 = ( T_3 ) strlen ( V_29 ) ;
* V_31 = NULL ;
* V_32 = NULL ;
if ( ! strncmp ( V_30 , V_29 , V_33 ) )
{
if ( V_30 [ V_33 ] == ',' )
{
* V_31 = V_30 + V_33 + 1 ;
}
}
if ( V_1 -> V_16 )
V_1 -> V_16 ( V_30 , V_31 , V_32 ) ;
F_16 ( V_29 ) ;
}
void F_26 ( T_1 * V_1 , T_8 * V_15 , T_14 V_18 , void * V_19 )
{
T_3 V_20 ;
V_15 -> V_21 = V_1 -> V_5 ;
V_15 -> V_22 = F_27 ( V_34 , V_1 -> V_5 ) ;
for ( V_20 = 0 ; V_20 < V_15 -> V_21 ; V_20 ++ )
{
V_15 -> V_22 [ V_20 ] . V_24 = V_1 -> V_12 ;
V_15 -> V_22 [ V_20 ] . V_1 = F_27 ( V_23 , V_1 -> V_12 ) ;
}
if ( V_18 )
V_18 ( V_15 , V_19 ) ;
}
void F_28 ( T_15 V_35 , T_16 V_36 )
{
F_29 ( V_17 , V_35 , V_36 ) ;
}

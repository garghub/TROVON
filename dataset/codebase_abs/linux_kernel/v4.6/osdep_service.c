inline int F_1 ( int V_1 )
{
if ( V_1 >= 0 )
return V_2 ;
return V_3 ;
}
T_1 * F_2 ( T_2 V_4 )
{
return F_3 ( V_4 , F_4 () ? V_5 : V_6 ) ;
}
void * F_5 ( int V_7 , int V_8 , int V_9 )
{
int V_10 ;
void * * V_11 = F_6 ( V_7 * sizeof( void * ) + V_7 * V_8 * V_9 , V_6 ) ;
if ( ! V_11 ) {
F_7 ( L_1 , V_12 ) ;
return NULL ;
}
for ( V_10 = 0 ; V_10 < V_7 ; V_10 ++ )
V_11 [ V_10 ] = ( ( char * ) ( V_11 + V_7 ) ) + V_10 * V_8 * V_9 ;
return V_11 ;
}
T_2 F_8 ( struct V_13 * V_14 )
{
if ( F_9 ( V_14 ) )
return V_3 ;
return V_2 ;
}
void F_10 ( struct V_15 * V_16 )
{
F_11 ( & ( V_16 -> V_17 ) ) ;
F_12 ( & ( V_16 -> V_18 ) ) ;
}
struct V_19 * F_13 ( int V_20 ,
void * V_21 )
{
struct V_19 * V_22 ;
struct V_23 * V_24 ;
V_22 = F_14 ( sizeof( struct V_23 ) , 4 ) ;
if ( ! V_22 )
goto RETURN;
V_24 = F_15 ( V_22 ) ;
V_24 -> V_25 = V_21 ;
V_24 -> V_20 = V_20 ;
RETURN:
return V_22 ;
}
void F_16 ( struct V_19 * V_26 )
{
struct V_23 * V_24 ;
if ( ! V_26 )
goto RETURN;
V_24 = F_15 ( V_26 ) ;
if ( ! V_24 -> V_25 )
goto RETURN;
F_17 ( V_24 -> V_25 ) ;
F_18 ( V_26 ) ;
RETURN:
return;
}
T_3 F_19 ( T_3 V_27 , T_3 V_28 )
{
return F_20 ( V_27 , V_28 ) ;
}
void F_21 ( T_1 * * V_29 , T_2 * V_30 )
{
* V_30 = 0 ;
F_22 ( * V_29 ) ;
* V_29 = NULL ;
}
void F_23 ( T_1 * * V_29 , T_2 * V_30 , T_1 * V_31 , T_2 V_32 )
{
T_2 V_33 = 0 ;
T_1 * V_34 = NULL ;
T_1 * V_35 = NULL ;
if ( ! V_29 || ! V_30 )
return;
if ( ! V_31 || ! V_32 )
goto V_36;
V_35 = F_24 ( V_32 ) ;
if ( V_35 ) {
V_33 = V_32 ;
memcpy ( V_35 , V_31 , V_33 ) ;
}
V_36:
V_34 = * V_29 ;
* V_30 = 0 ;
* V_29 = V_35 ;
* V_30 = V_33 ;
F_22 ( V_34 ) ;
}

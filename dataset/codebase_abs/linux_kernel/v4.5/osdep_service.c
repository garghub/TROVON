inline int F_1 ( int V_1 )
{
if ( V_1 >= 0 )
return V_2 ;
return V_3 ;
}
T_1 * F_2 ( T_2 V_4 )
{
T_1 * V_5 = NULL ;
V_5 = F_3 ( V_4 , F_4 () ? V_6 : V_7 ) ;
return V_5 ;
}
void * F_5 ( int V_8 , int V_9 , int V_10 )
{
int V_11 ;
void * * V_12 = F_6 ( V_8 * sizeof( void * ) + V_8 * V_9 * V_10 , V_7 ) ;
if ( ! V_12 ) {
F_7 ( L_1 , V_13 ) ;
return NULL ;
}
for ( V_11 = 0 ; V_11 < V_8 ; V_11 ++ )
V_12 [ V_11 ] = ( ( char * ) ( V_12 + V_8 ) ) + V_11 * V_9 * V_10 ;
return V_12 ;
}
T_2 F_8 ( struct V_14 * V_15 )
{
if ( F_9 ( V_15 ) )
return V_3 ;
else
return V_2 ;
}
void F_10 ( struct V_16 * V_17 )
{
F_11 ( & ( V_17 -> V_18 ) ) ;
F_12 ( & ( V_17 -> V_19 ) ) ;
}
struct V_20 * F_13 ( int V_21 ,
void * V_22 )
{
struct V_20 * V_23 ;
struct V_24 * V_25 ;
V_23 = F_14 ( sizeof( struct V_24 ) , 4 ) ;
if ( ! V_23 )
goto RETURN;
V_25 = F_15 ( V_23 ) ;
V_25 -> V_26 = V_22 ;
V_25 -> V_21 = V_21 ;
RETURN:
return V_23 ;
}
void F_16 ( struct V_20 * V_27 )
{
struct V_24 * V_25 ;
if ( ! V_27 )
goto RETURN;
V_25 = F_15 ( V_27 ) ;
if ( ! V_25 -> V_26 )
goto RETURN;
F_17 ( V_25 -> V_26 ) ;
F_18 ( V_27 ) ;
RETURN:
return;
}
T_3 F_19 ( T_3 V_28 , T_3 V_29 )
{
return F_20 ( V_28 , V_29 ) ;
}
void F_21 ( T_1 * * V_30 , T_2 * V_31 )
{
* V_31 = 0 ;
F_22 ( * V_30 ) ;
* V_30 = NULL ;
}
void F_23 ( T_1 * * V_30 , T_2 * V_31 , T_1 * V_32 , T_2 V_33 )
{
T_2 V_34 = 0 ;
T_1 * V_35 = NULL ;
T_1 * V_36 = NULL ;
if ( ! V_30 || ! V_31 )
return;
if ( ! V_32 || ! V_33 )
goto V_37;
V_36 = F_24 ( V_33 ) ;
if ( V_36 ) {
V_34 = V_33 ;
memcpy ( V_36 , V_32 , V_34 ) ;
}
V_37:
V_35 = * V_30 ;
* V_31 = 0 ;
* V_30 = V_36 ;
* V_31 = V_34 ;
F_22 ( V_35 ) ;
}

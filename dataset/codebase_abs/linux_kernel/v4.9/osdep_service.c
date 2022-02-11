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
void F_8 ( struct V_13 * V_14 )
{
F_9 ( & ( V_14 -> V_15 ) ) ;
F_10 ( & ( V_14 -> V_16 ) ) ;
}
struct V_17 * F_11 ( void * V_18 )
{
struct V_17 * V_19 ;
struct V_20 * V_21 ;
V_19 = F_12 ( sizeof( struct V_20 ) , 4 ) ;
if ( ! V_19 )
goto RETURN;
V_21 = F_13 ( V_19 ) ;
V_21 -> V_22 = V_18 ;
RETURN:
return V_19 ;
}
void F_14 ( struct V_17 * V_23 )
{
struct V_20 * V_21 ;
if ( ! V_23 )
goto RETURN;
V_21 = F_13 ( V_23 ) ;
if ( ! V_21 -> V_22 )
goto RETURN;
F_15 ( V_21 -> V_22 ) ;
F_16 ( V_23 ) ;
RETURN:
return;
}
T_3 F_17 ( T_3 V_24 , T_3 V_25 )
{
return F_18 ( V_24 , V_25 ) ;
}
void F_19 ( T_1 * * V_26 , T_2 * V_27 )
{
* V_27 = 0 ;
F_20 ( * V_26 ) ;
* V_26 = NULL ;
}
void F_21 ( T_1 * * V_26 , T_2 * V_27 , T_1 * V_28 , T_2 V_29 )
{
T_2 V_30 = 0 ;
T_1 * V_31 = NULL ;
T_1 * V_32 = NULL ;
if ( ! V_26 || ! V_27 )
return;
if ( ! V_28 || ! V_29 )
goto V_33;
V_32 = F_22 ( V_29 ) ;
if ( V_32 ) {
V_30 = V_29 ;
memcpy ( V_32 , V_28 , V_30 ) ;
}
V_33:
V_31 = * V_26 ;
* V_27 = 0 ;
* V_26 = V_32 ;
* V_27 = V_30 ;
F_20 ( V_31 ) ;
}

T_1 * F_1 ( T_2 V_1 )
{
return F_2 ( V_1 , F_3 () ? V_2 : V_3 ) ;
}
void * F_4 ( int V_4 , int V_5 , int V_6 )
{
int V_7 ;
void * * V_8 = F_5 ( V_4 * sizeof( void * ) + V_4 * V_5 * V_6 , V_3 ) ;
if ( ! V_8 )
goto V_9;
for ( V_7 = 0 ; V_7 < V_4 ; V_7 ++ )
V_8 [ V_7 ] = ( ( char * ) ( V_8 + V_4 ) ) + V_7 * V_5 * V_6 ;
V_9:
return V_8 ;
}
void F_6 ( struct V_10 * V_11 )
{
F_7 ( & V_11 -> V_12 ) ;
F_8 ( & V_11 -> V_13 ) ;
}
struct V_14 * F_9 ( void * V_15 )
{
struct V_14 * V_16 ;
struct V_17 * V_18 ;
V_16 = F_10 ( sizeof( struct V_17 ) , 4 ) ;
if ( ! V_16 )
goto RETURN;
V_18 = F_11 ( V_16 ) ;
V_18 -> V_19 = V_15 ;
RETURN:
return V_16 ;
}
void F_12 ( struct V_14 * V_20 )
{
struct V_17 * V_18 ;
if ( ! V_20 )
goto RETURN;
V_18 = F_11 ( V_20 ) ;
if ( ! V_18 -> V_19 )
goto RETURN;
F_13 ( V_18 -> V_19 ) ;
F_14 ( V_20 ) ;
RETURN:
return;
}
T_3 F_15 ( T_3 V_21 , T_3 V_22 )
{
return F_16 ( V_21 , V_22 ) ;
}
void F_17 ( T_1 * * V_23 , T_2 * V_24 )
{
* V_24 = 0 ;
F_18 ( * V_23 ) ;
* V_23 = NULL ;
}
void F_19 ( T_1 * * V_23 , T_2 * V_24 , T_1 * V_25 , T_2 V_26 )
{
T_2 V_27 = 0 ;
T_1 * V_28 = NULL ;
T_1 * V_29 = NULL ;
if ( ! V_23 || ! V_24 )
return;
if ( ! V_25 || ! V_26 )
goto V_30;
V_29 = F_20 ( V_26 ) ;
if ( V_29 ) {
V_27 = V_26 ;
memcpy ( V_29 , V_25 , V_27 ) ;
}
V_30:
V_28 = * V_23 ;
* V_24 = 0 ;
* V_23 = V_29 ;
* V_24 = V_27 ;
F_18 ( V_28 ) ;
}

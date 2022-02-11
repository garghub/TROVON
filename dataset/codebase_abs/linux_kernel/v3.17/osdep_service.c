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
void * * V_12 = ( void * * ) F_6 ( V_8 * sizeof( void * ) + V_8 * V_9 * V_10 , V_7 ) ;
if ( V_12 == NULL ) {
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
inline T_3 F_13 ( T_2 V_20 )
{
return F_14 ( V_21 - V_20 ) ;
}
struct V_22 * F_15 ( int V_23 ,
void * V_24 )
{
struct V_22 * V_25 ;
struct V_26 * V_27 ;
V_25 = F_16 ( sizeof( struct V_26 ) , 4 ) ;
if ( ! V_25 )
goto RETURN;
V_27 = F_17 ( V_25 ) ;
V_27 -> V_28 = V_24 ;
V_27 -> V_23 = V_23 ;
RETURN:
return V_25 ;
}
void F_18 ( struct V_22 * V_29 )
{
struct V_26 * V_27 ;
if ( ! V_29 )
goto RETURN;
V_27 = F_17 ( V_29 ) ;
if ( ! V_27 -> V_28 )
goto RETURN;
F_19 ( V_27 -> V_28 ) ;
F_20 ( V_29 ) ;
RETURN:
return;
}
T_4 F_21 ( T_4 V_30 , T_4 V_31 )
{
return F_22 ( V_30 , V_31 ) ;
}
void F_23 ( T_1 * * V_32 , T_2 * V_33 )
{
* V_33 = 0 ;
F_24 ( * V_32 ) ;
* V_32 = NULL ;
}
void F_25 ( T_1 * * V_32 , T_2 * V_33 , T_1 * V_34 , T_2 V_35 )
{
T_2 V_36 = 0 , V_37 = 0 ;
T_1 * V_38 = NULL ;
T_1 * V_39 = NULL ;
if ( ! V_32 || ! V_33 )
return;
if ( ! V_34 || ! V_35 )
goto V_40;
V_39 = F_26 ( V_35 ) ;
if ( V_39 ) {
V_37 = V_35 ;
memcpy ( V_39 , V_34 , V_37 ) ;
}
V_40:
V_38 = * V_32 ;
V_36 = * V_33 ;
* V_33 = 0 ;
* V_32 = V_39 ;
* V_33 = V_37 ;
F_24 ( V_38 ) ;
}

T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 , T_2 * V_3 , T_3 * V_4 )
{
F_3 ( V_5 , V_6 ) ;
return ( 0 ) ;
}
static int F_4 ( T_2 * V_7 , T_2 * V_8 , const T_2 * V_9 ,
const T_2 * V_10 , T_4 * V_11 , T_5 * V_12 )
{
F_3 ( V_13 , V_6 ) ;
return ( 0 ) ;
}
static int F_5 ( T_2 * V_14 , unsigned char * V_15 , int V_16 )
{
int V_17 ;
V_17 = F_6 ( V_14 ) ;
if ( V_17 > V_16 )
{
F_3 ( V_18 , V_19 ) ;
return ( 0 ) ;
}
memset ( V_15 , 0 , ( unsigned int ) V_16 ) ;
if ( ! F_7 ( V_14 , & ( V_15 [ V_16 - V_17 ] ) ) )
return ( 0 ) ;
return ( 1 ) ;
}
static T_2 * F_8 ( unsigned char * V_14 , T_2 * V_15 , int V_16 )
{
int V_17 ;
T_2 * V_20 ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ )
if ( V_14 [ V_17 ] ) break;
V_20 = F_9 ( & ( V_14 [ V_17 ] ) , V_16 - V_17 , V_15 ) ;
return ( V_20 ) ;
}
static int F_10 ( T_6 * V_14 , T_3 * V_15 )
{
V_15 -> V_21 = F_8 ( V_14 -> V_10 , NULL , V_22 ) ;
V_15 -> V_23 = F_8 ( V_14 -> V_23 , NULL , V_22 ) ;
if ( ( V_15 -> V_21 == NULL ) || ( V_15 -> V_23 == NULL ) ) return ( 0 ) ;
return ( 1 ) ;
}
static int F_11 ( T_3 * V_14 , T_6 * V_15 )
{
V_15 -> V_24 = F_12 ( V_14 -> V_21 ) ;
if ( ! F_5 ( V_14 -> V_21 , V_15 -> V_10 , V_22 ) ) return ( 0 ) ;
if ( ! F_5 ( V_14 -> V_23 , V_15 -> V_23 , V_22 ) ) return ( 0 ) ;
return ( 1 ) ;
}
static int F_13 ( T_7 * V_14 , T_3 * V_15 )
{
if ( ( V_15 -> V_21 = F_8 ( V_14 -> V_10 , NULL , V_22 ) ) == NULL )
return ( 0 ) ;
if ( ( V_15 -> V_23 = F_8 ( V_14 -> V_23 , NULL , V_22 ) ) == NULL )
return ( 0 ) ;
if ( ( V_15 -> V_25 = F_8 ( V_14 -> V_25 , NULL , V_22 ) ) == NULL )
return ( 0 ) ;
if ( ( V_15 -> V_9 = F_8 ( V_14 -> V_26 [ 0 ] , NULL , V_27 ) ) == NULL )
return ( 0 ) ;
if ( ( V_15 -> V_28 = F_8 ( V_14 -> V_26 [ 1 ] , NULL , V_27 ) ) == NULL )
return ( 0 ) ;
if ( ( V_15 -> V_29 = F_8 ( V_14 -> V_30 [ 0 ] , NULL , V_27 ) )
== NULL )
return ( 0 ) ;
if ( ( V_15 -> V_31 = F_8 ( V_14 -> V_30 [ 1 ] , NULL , V_27 ) )
== NULL )
return ( 0 ) ;
if ( ( V_15 -> V_32 = F_8 ( V_14 -> V_33 , NULL , V_27 ) ) == NULL )
return ( 0 ) ;
return ( 1 ) ;
}
static int F_14 ( T_3 * V_14 , T_7 * V_15 )
{
V_15 -> V_24 = F_12 ( V_14 -> V_21 ) ;
if ( ! F_5 ( V_14 -> V_21 , V_15 -> V_10 , V_22 ) ) return ( 0 ) ;
if ( ! F_5 ( V_14 -> V_23 , V_15 -> V_23 , V_22 ) ) return ( 0 ) ;
if ( ! F_5 ( V_14 -> V_25 , V_15 -> V_25 , V_22 ) ) return ( 0 ) ;
if ( ! F_5 ( V_14 -> V_9 , V_15 -> V_26 [ 0 ] , V_27 ) ) return ( 0 ) ;
if ( ! F_5 ( V_14 -> V_28 , V_15 -> V_26 [ 1 ] , V_27 ) ) return ( 0 ) ;
if ( ! F_5 ( V_14 -> V_29 , V_15 -> V_30 [ 0 ] , V_27 ) ) return ( 0 ) ;
if ( ! F_5 ( V_14 -> V_31 , V_15 -> V_30 [ 1 ] , V_27 ) ) return ( 0 ) ;
if ( ! F_5 ( V_14 -> V_32 , V_15 -> V_33 , V_27 ) ) return ( 0 ) ;
return ( 1 ) ;
}
int F_15 ( int V_34 , unsigned char * V_14 , unsigned char * V_15 ,
T_3 * V_4 , int V_35 )
{
int V_17 , V_36 = - 1 ;
T_7 V_37 ;
if ( ! F_14 ( V_4 , & V_37 ) )
goto V_38;
if ( ( V_17 = F_16 ( V_15 , & V_36 , V_14 , V_34 , & V_37 ) ) != 0 )
{
F_3 ( V_39 , V_17 ) ;
V_36 = - 1 ;
}
V_38:
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
return ( V_36 ) ;
}
int F_17 ( int V_34 , unsigned char * V_14 , unsigned char * V_15 ,
T_3 * V_4 , int V_35 )
{
int V_17 , V_36 = - 1 ;
T_7 V_37 ;
if ( V_35 != V_40 )
{
F_3 ( V_41 , V_42 ) ;
goto V_38;
}
if ( ! F_14 ( V_4 , & V_37 ) )
goto V_38;
if ( ( V_17 = F_18 ( V_15 , & V_36 , V_14 , V_34 , & V_37 ) ) != 0 )
{
F_3 ( V_41 , V_17 ) ;
V_36 = - 1 ;
}
V_38:
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
return ( V_36 ) ;
}
int F_19 ( int V_34 , unsigned char * V_14 , unsigned char * V_15 ,
T_3 * V_4 , int V_35 )
{
int V_17 , V_36 = - 1 ;
T_6 V_37 ;
if ( ! F_11 ( V_4 , & V_37 ) )
goto V_38;
if ( ( V_17 = F_20 ( V_15 , & V_36 , V_14 , V_34 , & V_37 ) ) != 0 )
{
F_3 ( V_43 , V_17 ) ;
V_36 = - 1 ;
}
V_38:
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
return ( V_36 ) ;
}
int F_21 ( int V_34 , unsigned char * V_14 , unsigned char * V_15 ,
T_3 * V_4 , int V_35 )
{
int V_36 = - 1 ;
int V_17 ;
T_6 V_37 ;
T_8 V_44 ;
unsigned char V_45 [ 16 ] ;
if ( V_35 != V_40 && V_35 != V_46 )
{
F_3 ( V_47 , V_42 ) ;
goto V_38;
}
F_22 ( & V_44 ) ;
F_23 ( ( unsigned int * ) & V_17 , & V_44 ) ;
while ( V_17 > 0 )
{
F_24 ( V_45 , 16 ) ;
F_25 ( & V_44 , V_45 , ( unsigned int ) ( ( V_17 > 16 ) ? 16 : V_17 ) ) ;
V_17 -= 16 ;
}
if ( ! F_11 ( V_4 , & V_37 ) )
goto V_38;
if ( ( V_17 = F_26 ( V_15 , & V_36 , V_14 , V_34 , & V_37 , & V_44 ) ) != 0 )
{
F_3 ( V_47 , V_17 ) ;
V_36 = - 1 ;
goto V_38;
}
V_38:
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
F_27 ( & V_44 ) ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
return ( V_36 ) ;
}

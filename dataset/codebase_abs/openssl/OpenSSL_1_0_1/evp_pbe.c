int main ( int V_1 , char * * V_2 )
{
int V_3 , V_4 , V_5 ;
T_1 * V_6 , * V_7 ;
for ( V_3 = 0 ; V_3 < sizeof( V_8 ) / sizeof( T_1 ) ; V_3 ++ )
{
V_6 = V_8 + V_3 ;
fprintf ( V_9 , L_1 , V_6 -> V_10 , V_6 -> V_11 ,
F_1 ( V_6 -> V_11 ) ) ;
if ( F_2 ( V_6 -> V_10 , V_6 -> V_11 ,
& V_5 , & V_4 , 0 ) )
fprintf ( V_9 , L_2 ,
F_1 ( V_5 ) ,
F_1 ( V_4 ) ) ;
else
fprintf ( V_9 , L_3 ) ;
}
return 0 ;
}
int F_3 ( T_2 * V_12 , const char * V_13 , int V_14 ,
T_3 * V_15 , T_4 * V_16 , int V_17 )
{
const T_5 * V_18 ;
const T_6 * V_19 ;
int V_20 , V_21 ;
T_7 * V_22 ;
if ( ! F_2 ( V_23 , F_4 ( V_12 ) ,
& V_20 , & V_21 , & V_22 ) )
{
char V_24 [ 80 ] ;
F_5 ( V_25 , V_26 ) ;
if ( ! V_12 ) F_6 ( V_24 , L_4 , sizeof V_24 ) ;
else F_7 ( V_24 , sizeof V_24 , V_12 ) ;
F_8 ( 2 , L_5 , V_24 ) ;
return 0 ;
}
if( ! V_13 )
V_14 = 0 ;
else if ( V_14 == - 1 )
V_14 = strlen ( V_13 ) ;
if ( V_20 == - 1 )
V_18 = NULL ;
else
{
V_18 = F_9 ( V_20 ) ;
if ( ! V_18 )
{
F_5 ( V_25 , V_27 ) ;
return 0 ;
}
}
if ( V_21 == - 1 )
V_19 = NULL ;
else
{
V_19 = F_10 ( V_21 ) ;
if ( ! V_19 )
{
F_5 ( V_25 , V_28 ) ;
return 0 ;
}
}
if ( ! V_22 ( V_16 , V_13 , V_14 , V_15 , V_18 , V_19 , V_17 ) )
{
F_5 ( V_25 , V_29 ) ;
return 0 ;
}
return 1 ;
}
static int F_11 ( const T_1 * V_30 , const T_1 * V_31 )
{
int V_32 = V_30 -> V_10 - V_31 -> V_10 ;
if ( V_32 )
return V_32 ;
else
return V_30 -> V_11 - V_31 -> V_11 ;
}
static int F_12 ( const T_1 * const * V_33 , const T_1 * const * V_34 )
{
int V_32 = ( * V_33 ) -> V_10 - ( * V_34 ) -> V_10 ;
if ( V_32 )
return V_32 ;
else
return ( * V_33 ) -> V_11 - ( * V_34 ) -> V_11 ;
}
int F_13 ( int V_10 , int V_11 , int V_20 , int V_21 ,
T_7 * V_22 )
{
T_1 * V_35 ;
if ( ! V_36 )
V_36 = F_14 ( F_12 ) ;
if ( ! ( V_35 = ( T_1 * ) F_15 ( sizeof( T_1 ) ) ) )
{
F_5 ( V_37 , V_38 ) ;
return 0 ;
}
V_35 -> V_10 = V_10 ;
V_35 -> V_11 = V_11 ;
V_35 -> V_20 = V_20 ;
V_35 -> V_21 = V_21 ;
V_35 -> V_22 = V_22 ;
F_16 ( V_36 , V_35 ) ;
return 1 ;
}
int F_17 ( int V_39 , const T_5 * V_18 , const T_6 * V_19 ,
T_7 * V_22 )
{
int V_20 , V_21 ;
if ( V_18 )
V_20 = F_18 ( V_18 ) ;
else
V_20 = - 1 ;
if ( V_19 )
V_21 = F_19 ( V_19 ) ;
else
V_21 = - 1 ;
return F_13 ( V_23 , V_39 ,
V_20 , V_21 , V_22 ) ;
}
int F_2 ( int type , int V_11 ,
int * V_40 , int * V_41 , T_7 * * V_42 )
{
T_1 * V_43 = NULL , V_44 ;
int V_3 ;
if ( V_11 == V_45 )
return 0 ;
V_44 . V_10 = type ;
V_44 . V_11 = V_11 ;
if ( V_36 )
{
V_3 = F_20 ( V_36 , & V_44 ) ;
if ( V_3 != - 1 )
V_43 = F_21 ( V_36 , V_3 ) ;
}
if ( V_43 == NULL )
{
V_43 = F_22 ( & V_44 , V_8 ,
sizeof( V_8 ) / sizeof( T_1 ) ) ;
}
if ( V_43 == NULL )
return 0 ;
if ( V_40 )
* V_40 = V_43 -> V_20 ;
if ( V_41 )
* V_41 = V_43 -> V_21 ;
if ( V_42 )
* V_42 = V_43 -> V_22 ;
return 1 ;
}
static void F_23 ( T_1 * V_46 )
{
F_24 ( V_46 ) ;
}
void F_25 ( void )
{
F_26 ( V_36 , F_23 ) ;
V_36 = NULL ;
}

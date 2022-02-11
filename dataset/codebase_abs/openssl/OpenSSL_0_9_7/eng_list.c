static void F_1 ( void )
{
T_1 * V_1 = V_2 ;
while( V_1 != NULL )
{
F_2 ( V_1 ) ;
V_1 = V_2 ;
}
return;
}
static int F_3 ( T_1 * V_3 )
{
int V_4 = 0 ;
T_1 * V_1 = NULL ;
if( V_3 == NULL )
{
F_4 ( V_5 ,
V_6 ) ;
return 0 ;
}
V_1 = V_2 ;
while( V_1 && ! V_4 )
{
V_4 = ( strcmp ( V_1 -> V_7 , V_3 -> V_7 ) == 0 ) ;
V_1 = V_1 -> V_8 ;
}
if( V_4 )
{
F_4 ( V_5 ,
V_9 ) ;
return 0 ;
}
if( V_2 == NULL )
{
if( V_10 )
{
F_4 ( V_5 ,
V_11 ) ;
return 0 ;
}
V_2 = V_3 ;
V_3 -> V_12 = NULL ;
F_5 ( F_1 ) ;
}
else
{
if( ( V_10 == NULL ) ||
( V_10 -> V_8 != NULL ) )
{
F_4 ( V_5 ,
V_11 ) ;
return 0 ;
}
V_10 -> V_8 = V_3 ;
V_3 -> V_12 = V_10 ;
}
V_3 -> V_13 ++ ;
F_6 (e, 0 , 1 )
V_10 = V_3 ;
V_3 -> V_8 = NULL ;
return 1 ;
}
static int F_7 ( T_1 * V_3 )
{
T_1 * V_1 ;
if( V_3 == NULL )
{
F_4 ( V_14 ,
V_6 ) ;
return 0 ;
}
V_1 = V_2 ;
while( V_1 && ( V_1 != V_3 ) )
V_1 = V_1 -> V_8 ;
if( V_1 == NULL )
{
F_4 ( V_14 ,
V_15 ) ;
return 0 ;
}
if( V_3 -> V_8 )
V_3 -> V_8 -> V_12 = V_3 -> V_12 ;
if( V_3 -> V_12 )
V_3 -> V_12 -> V_8 = V_3 -> V_8 ;
if( V_2 == V_3 )
V_2 = V_3 -> V_8 ;
if( V_10 == V_3 )
V_10 = V_3 -> V_12 ;
F_8 ( V_3 , 0 ) ;
return 1 ;
}
T_1 * F_9 ( void )
{
T_1 * V_16 ;
F_10 ( V_17 ) ;
V_16 = V_2 ;
if( V_16 )
{
V_16 -> V_13 ++ ;
F_6 (ret, 0 , 1 )
}
F_11 ( V_17 ) ;
return V_16 ;
}
T_1 * F_12 ( void )
{
T_1 * V_16 ;
F_10 ( V_17 ) ;
V_16 = V_10 ;
if( V_16 )
{
V_16 -> V_13 ++ ;
F_6 (ret, 0 , 1 )
}
F_11 ( V_17 ) ;
return V_16 ;
}
T_1 * F_13 ( T_1 * V_3 )
{
T_1 * V_16 = NULL ;
if( V_3 == NULL )
{
F_4 ( V_18 ,
V_6 ) ;
return 0 ;
}
F_10 ( V_17 ) ;
V_16 = V_3 -> V_8 ;
if( V_16 )
{
V_16 -> V_13 ++ ;
F_6 (ret, 0 , 1 )
}
F_11 ( V_17 ) ;
F_14 ( V_3 ) ;
return V_16 ;
}
T_1 * F_15 ( T_1 * V_3 )
{
T_1 * V_16 = NULL ;
if( V_3 == NULL )
{
F_4 ( V_19 ,
V_6 ) ;
return 0 ;
}
F_10 ( V_17 ) ;
V_16 = V_3 -> V_12 ;
if( V_16 )
{
V_16 -> V_13 ++ ;
F_6 (ret, 0 , 1 )
}
F_11 ( V_17 ) ;
F_14 ( V_3 ) ;
return V_16 ;
}
int F_16 ( T_1 * V_3 )
{
int V_20 = 1 ;
if( V_3 == NULL )
{
F_4 ( V_21 ,
V_6 ) ;
return 0 ;
}
if( ( V_3 -> V_7 == NULL ) || ( V_3 -> V_22 == NULL ) )
{
F_4 ( V_21 ,
V_23 ) ;
}
F_10 ( V_17 ) ;
if( ! F_3 ( V_3 ) )
{
F_4 ( V_21 ,
V_11 ) ;
V_20 = 0 ;
}
F_11 ( V_17 ) ;
return V_20 ;
}
int F_2 ( T_1 * V_3 )
{
int V_20 = 1 ;
if( V_3 == NULL )
{
F_4 ( V_24 ,
V_6 ) ;
return 0 ;
}
F_10 ( V_17 ) ;
if( ! F_7 ( V_3 ) )
{
F_4 ( V_24 ,
V_11 ) ;
V_20 = 0 ;
}
F_11 ( V_17 ) ;
return V_20 ;
}
static void F_17 ( T_1 * V_25 , const T_1 * V_26 )
{
V_25 -> V_7 = V_26 -> V_7 ;
V_25 -> V_22 = V_26 -> V_22 ;
#ifndef F_18
V_25 -> V_27 = V_26 -> V_27 ;
#endif
#ifndef F_19
V_25 -> V_28 = V_26 -> V_28 ;
#endif
#ifndef F_20
V_25 -> V_29 = V_26 -> V_29 ;
#endif
V_25 -> V_30 = V_26 -> V_30 ;
V_25 -> V_31 = V_26 -> V_31 ;
V_25 -> V_32 = V_26 -> V_32 ;
V_25 -> V_33 = V_26 -> V_33 ;
V_25 -> V_34 = V_26 -> V_34 ;
V_25 -> V_35 = V_26 -> V_35 ;
V_25 -> V_36 = V_26 -> V_36 ;
V_25 -> V_37 = V_26 -> V_37 ;
V_25 -> V_38 = V_26 -> V_38 ;
V_25 -> V_39 = V_26 -> V_39 ;
V_25 -> V_40 = V_26 -> V_40 ;
}
T_1 * F_21 ( const char * V_7 )
{
T_1 * V_1 ;
if( V_7 == NULL )
{
F_4 ( V_41 ,
V_6 ) ;
return NULL ;
}
F_10 ( V_17 ) ;
V_1 = V_2 ;
while( V_1 && ( strcmp ( V_7 , V_1 -> V_7 ) != 0 ) )
V_1 = V_1 -> V_8 ;
if( V_1 )
{
if( V_1 -> V_40 & V_42 )
{
T_1 * V_43 = F_22 () ;
if( ! V_43 )
V_1 = NULL ;
else
{
F_17 ( V_43 , V_1 ) ;
V_1 = V_43 ;
}
}
else
{
V_1 -> V_13 ++ ;
F_6 (iterator, 0 , 1 )
}
}
F_11 ( V_17 ) ;
if( V_1 == NULL )
{
F_4 ( V_41 ,
V_44 ) ;
F_23 ( 2 , L_1 , V_7 ) ;
}
return V_1 ;
}
int F_24 ( T_1 * V_3 )
{
if ( V_3 == NULL )
{
F_4 ( V_45 , V_6 ) ;
return 0 ;
}
F_25 ( & V_3 -> V_13 , 1 , V_17 ) ;
return 1 ;
}

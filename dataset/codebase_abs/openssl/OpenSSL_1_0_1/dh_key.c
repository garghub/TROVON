int F_1 ( T_1 * V_1 )
{
#ifdef F_2
if ( F_3 () && ! ( V_1 -> V_2 -> V_3 & V_4 )
&& ! ( V_1 -> V_3 & V_5 ) )
{
F_4 ( V_6 , V_7 ) ;
return 0 ;
}
#endif
return V_1 -> V_2 -> V_8 ( V_1 ) ;
}
int F_5 ( unsigned char * V_9 , const T_2 * V_10 , T_1 * V_1 )
{
#ifdef F_2
if ( F_3 () && ! ( V_1 -> V_2 -> V_3 & V_4 )
&& ! ( V_1 -> V_3 & V_5 ) )
{
F_4 ( V_11 , V_7 ) ;
return 0 ;
}
#endif
return V_1 -> V_2 -> V_12 ( V_9 , V_10 , V_1 ) ;
}
const T_3 * F_6 ( void )
{
return & V_13 ;
}
static int V_8 ( T_1 * V_1 )
{
int V_14 = 0 ;
int V_15 = 0 ;
unsigned V_16 ;
T_4 * V_17 ;
T_5 * V_18 = NULL ;
T_2 * V_10 = NULL , * V_19 = NULL ;
V_17 = F_7 () ;
if ( V_17 == NULL ) goto V_20;
if ( V_1 -> V_19 == NULL )
{
V_19 = F_8 () ;
if ( V_19 == NULL ) goto V_20;
V_15 = 1 ;
}
else
V_19 = V_1 -> V_19 ;
if ( V_1 -> V_10 == NULL )
{
V_10 = F_8 () ;
if ( V_10 == NULL ) goto V_20;
}
else
V_10 = V_1 -> V_10 ;
if ( V_1 -> V_3 & V_21 )
{
V_18 = F_9 ( & V_1 -> V_22 ,
V_23 , V_1 -> V_24 , V_17 ) ;
if ( ! V_18 )
goto V_20;
}
if ( V_15 )
{
if ( V_1 -> V_25 )
{
do
{
if ( ! F_10 ( V_19 , V_1 -> V_25 ) )
goto V_20;
}
while ( F_11 ( V_19 ) || F_12 ( V_19 ) );
}
else
{
V_16 = V_1 -> V_26 ? V_1 -> V_26 : F_13 ( V_1 -> V_24 ) - 1 ;
if ( ! F_14 ( V_19 , V_16 , 0 , 0 ) ) goto V_20;
}
}
{
T_2 V_27 ;
T_2 * V_28 ;
if ( ( V_1 -> V_3 & V_29 ) == 0 )
{
F_15 ( & V_27 ) ;
V_28 = & V_27 ;
F_16 ( V_28 , V_19 , V_30 ) ;
}
else
V_28 = V_19 ;
if ( ! V_1 -> V_2 -> V_31 ( V_1 , V_10 , V_1 -> V_32 , V_28 , V_1 -> V_24 , V_17 , V_18 ) ) goto V_20;
}
V_1 -> V_10 = V_10 ;
V_1 -> V_19 = V_19 ;
V_14 = 1 ;
V_20:
if ( V_14 != 1 )
F_4 ( V_33 , V_34 ) ;
if ( ( V_10 != NULL ) && ( V_1 -> V_10 == NULL ) ) F_17 ( V_10 ) ;
if ( ( V_19 != NULL ) && ( V_1 -> V_19 == NULL ) ) F_17 ( V_19 ) ;
F_18 ( V_17 ) ;
return ( V_14 ) ;
}
static int V_12 ( unsigned char * V_9 , const T_2 * V_10 , T_1 * V_1 )
{
T_4 * V_17 = NULL ;
T_5 * V_18 = NULL ;
T_2 * V_35 ;
int V_36 = - 1 ;
int V_37 ;
if ( F_13 ( V_1 -> V_24 ) > V_38 )
{
F_4 ( V_39 , V_40 ) ;
goto V_20;
}
V_17 = F_7 () ;
if ( V_17 == NULL ) goto V_20;
F_19 ( V_17 ) ;
V_35 = F_20 ( V_17 ) ;
if ( V_1 -> V_19 == NULL )
{
F_4 ( V_39 , V_41 ) ;
goto V_20;
}
if ( V_1 -> V_3 & V_21 )
{
V_18 = F_9 ( & V_1 -> V_22 ,
V_23 , V_1 -> V_24 , V_17 ) ;
if ( ( V_1 -> V_3 & V_29 ) == 0 )
{
F_21 ( V_1 -> V_19 , V_30 ) ;
}
if ( ! V_18 )
goto V_20;
}
if ( ! F_22 ( V_1 , V_10 , & V_37 ) || V_37 )
{
F_4 ( V_39 , V_42 ) ;
goto V_20;
}
if ( ! V_1 -> V_2 -> V_31 ( V_1 , V_35 , V_10 , V_1 -> V_19 , V_1 -> V_24 , V_17 , V_18 ) )
{
F_4 ( V_39 , V_34 ) ;
goto V_20;
}
V_36 = F_23 ( V_35 , V_9 ) ;
V_20:
if ( V_17 != NULL )
{
F_24 ( V_17 ) ;
F_18 ( V_17 ) ;
}
return ( V_36 ) ;
}
static int F_25 ( const T_1 * V_1 , T_2 * V_43 ,
const T_2 * V_44 , const T_2 * V_24 ,
const T_2 * V_45 , T_4 * V_17 ,
T_5 * V_46 )
{
if ( V_44 -> V_47 == 1 && ( ( V_1 -> V_3 & V_29 ) != 0 ) )
{
T_6 V_48 = V_44 -> V_49 [ 0 ] ;
return F_26 ( V_43 , V_48 , V_24 , V_45 , V_17 , V_46 ) ;
}
else
return F_27 ( V_43 , V_44 , V_24 , V_45 , V_17 , V_46 ) ;
}
static int F_28 ( T_1 * V_1 )
{
V_1 -> V_3 |= V_21 ;
return ( 1 ) ;
}
static int F_29 ( T_1 * V_1 )
{
if( V_1 -> V_22 )
F_30 ( V_1 -> V_22 ) ;
return ( 1 ) ;
}

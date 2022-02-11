int F_1 ( T_1 * V_1 , T_1 * V_2 , T_1 * V_3 , const T_1 * V_4 , T_2 * V_5 )
{
T_1 * V_6 ;
int V_7 = 0 ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
F_2 ( V_4 ) ;
F_3 ( V_5 ) ;
if ( ( V_6 = F_4 ( V_5 ) ) == NULL ) goto V_8;
if ( V_2 == V_3 )
{ if ( ! F_5 ( V_6 , V_2 , V_5 ) ) goto V_8; }
else
{ if ( ! F_6 ( V_6 , V_2 , V_3 , V_5 ) ) goto V_8; }
if ( ! F_7 ( V_1 , V_6 , V_4 , V_5 ) ) goto V_8;
V_7 = 1 ;
V_8:
F_8 ( V_5 ) ;
return ( V_7 ) ;
}
int F_9 ( T_1 * V_7 , T_1 * V_2 , T_1 * V_9 , T_2 * V_5 )
{
int V_10 , V_11 , V_1 = 0 ;
T_1 * V_12 , * V_13 ;
F_3 ( V_5 ) ;
if ( ( V_7 == V_2 ) || ( V_7 == V_9 ) )
V_13 = F_4 ( V_5 ) ;
else
V_13 = V_7 ;
if ( ( V_12 = F_4 ( V_5 ) ) == NULL ) goto V_8;
if ( F_10 ( V_12 , V_2 ) == NULL ) goto V_8;
V_11 = F_11 ( V_9 ) ;
if ( F_12 ( V_9 ) )
{ if ( F_10 ( V_13 , V_2 ) == NULL ) goto V_8; }
else { if ( ! F_13 ( V_13 ) ) goto V_8; }
for ( V_10 = 1 ; V_10 < V_11 ; V_10 ++ )
{
if ( ! F_5 ( V_12 , V_12 , V_5 ) ) goto V_8;
if ( F_14 ( V_9 , V_10 ) )
{
if ( ! F_6 ( V_13 , V_13 , V_12 , V_5 ) ) goto V_8;
}
}
V_1 = 1 ;
V_8:
if ( V_7 != V_13 ) F_10 ( V_7 , V_13 ) ;
F_8 ( V_5 ) ;
return ( V_1 ) ;
}
void F_15 ( void )
{
void * V_14 ;
int V_15 ;
unsigned int V_16 [ 1024 ] ;
static int V_17 ;
if( V_17 )
return;
V_17 = 1 ;
F_16 ( ( void * ) V_16 , 1024 ) ;
V_14 = F_17 ( L_1 , V_18 ) ;
if ( V_14 == ( void * ) NULL )
{
return;
}
V_19 =
( V_20 * ) F_18 ( V_14 , L_2 ) ;
if ( V_19 )
{
V_15 = (* V_19)( 0L , V_16 ) ;
if ( V_15 != 0 )
{
printf ( L_3 ) ;
printf ( L_4 ) ;
return;
}
}
else
{
return ;
}
V_21 =
( V_22 * ) F_18 ( V_14 , L_5 ) ;
if ( V_21 == NULL )
{
return;
}
V_23 =
( V_24 * ) F_18 ( V_14 , L_6 ) ;
if ( V_23 == NULL )
{
return;
}
V_25 = 1 ;
return;
}
int F_19 ( T_1 * V_7 , T_1 * V_2 , const T_1 * V_9 , const T_1 * V_4 )
{
unsigned char * V_26 ;
unsigned char * V_27 ;
unsigned char * V_28 ;
unsigned char * V_29 ;
int V_30 , V_31 , V_32 , V_1 ;
T_3 V_33 ;
F_15 () ;
if( ! V_25 )
return 0 ;
# define F_20 128
V_30 = F_21 ( V_2 ) ;
V_31 = F_21 ( V_9 ) ;
V_32 = F_21 ( V_4 ) ;
if( V_30 <= F_20 && V_31 <= F_20 && V_32 <= F_20 )
{
int V_34 = V_32 ;
assert ( V_30 <= V_32 ) ;
V_26 = F_22 ( V_34 ) ;
memset ( V_26 , '\0' , V_32 ) ;
F_23 ( V_2 , V_26 + V_34 - V_30 ) ;
V_27 = F_22 ( V_31 ) ;
F_23 ( V_9 , V_27 ) ;
V_28 = F_22 ( V_34 ) ;
memset ( V_28 , '\0' , V_32 ) ;
F_23 ( V_4 , V_28 + V_34 - V_32 ) ;
V_29 = F_22 ( V_34 ) ;
memset ( & V_33 , '\0' , sizeof V_33 ) ;
V_33 . V_35 . V_36 = V_27 ;
V_33 . V_35 . V_37 = V_31 ;
V_33 . V_38 . V_36 = V_28 ;
V_33 . V_38 . V_37 = V_34 ;
V_1 = (* V_21)( & V_33 , V_29 , V_26 , V_33 . V_38 . V_37 ) ;
if( ! V_1 )
{
F_24 ( V_29 , V_33 . V_38 . V_37 , V_7 ) ;
return 1 ;
}
}
return 0 ;
}
int F_25 ( T_1 * V_7 , T_1 * V_2 , const T_1 * V_9 , const T_1 * V_4 ,
T_2 * V_5 )
{
int V_1 ;
F_2 ( V_2 ) ;
F_2 ( V_9 ) ;
F_2 ( V_4 ) ;
#ifdef F_26
if( F_19 ( V_7 , V_2 , V_9 , V_4 ) )
return 1 ;
V_39 = 1 ;
#endif
#ifdef F_27
if ( F_12 ( V_4 ) )
{ V_1 = F_28 ( V_7 , V_2 , V_9 , V_4 , V_5 , NULL ) ; }
else
#endif
#ifdef F_29
{ V_1 = F_30 ( V_7 , V_2 , V_9 , V_4 , V_5 ) ; }
#else
{ V_1 = F_31 ( V_7 , V_2 , V_9 , V_4 , V_5 ) ; }
#endif
#ifdef F_26
V_39 = 0 ;
#endif
return ( V_1 ) ;
}
int F_30 ( T_1 * V_7 , const T_1 * V_2 , const T_1 * V_9 ,
const T_1 * V_4 , T_2 * V_5 )
{
int V_10 , V_40 , V_11 , V_1 = 0 , V_41 , V_42 , V_43 , V_44 ;
int V_45 = 1 , V_46 = 0 ;
T_1 * V_47 ;
T_1 V_48 [ V_49 ] ;
T_4 V_50 ;
V_11 = F_11 ( V_9 ) ;
if ( V_11 == 0 )
{
F_13 ( V_7 ) ;
return ( 1 ) ;
}
F_3 ( V_5 ) ;
if ( ( V_47 = F_4 ( V_5 ) ) == NULL ) goto V_8;
F_32 ( & V_50 ) ;
if ( F_33 ( & V_50 , V_4 , V_5 ) <= 0 ) goto V_8;
F_34 ( & ( V_48 [ 0 ] ) ) ;
V_46 = 1 ;
if ( ! F_7 ( & ( V_48 [ 0 ] ) , V_2 , V_4 , V_5 ) ) goto V_8;
if ( ! F_35 ( V_47 , & ( V_48 [ 0 ] ) , & ( V_48 [ 0 ] ) , & V_50 , V_5 ) )
goto V_8;
if ( V_11 <= 17 )
V_43 = 1 ;
else if ( V_11 >= 256 )
V_43 = 5 ;
else if ( V_11 >= 128 )
V_43 = 4 ;
else
V_43 = 3 ;
V_40 = 1 << ( V_43 - 1 ) ;
for ( V_10 = 1 ; V_10 < V_40 ; V_10 ++ )
{
F_34 ( & V_48 [ V_10 ] ) ;
if ( ! F_35 ( & ( V_48 [ V_10 ] ) , & ( V_48 [ V_10 - 1 ] ) , V_47 , & V_50 , V_5 ) )
goto V_8;
}
V_46 = V_10 ;
V_45 = 1 ;
V_44 = 0 ;
V_41 = V_11 - 1 ;
V_42 = 0 ;
if ( ! F_13 ( V_7 ) ) goto V_8;
for (; ; )
{
if ( F_14 ( V_9 , V_41 ) == 0 )
{
if ( ! V_45 )
if ( ! F_35 ( V_7 , V_7 , V_7 , & V_50 , V_5 ) )
goto V_8;
if ( V_41 == 0 ) break;
V_41 -- ;
continue;
}
V_40 = V_41 ;
V_44 = 1 ;
V_42 = 0 ;
for ( V_10 = 1 ; V_10 < V_43 ; V_10 ++ )
{
if ( V_41 - V_10 < 0 ) break;
if ( F_14 ( V_9 , V_41 - V_10 ) )
{
V_44 <<= ( V_10 - V_42 ) ;
V_44 |= 1 ;
V_42 = V_10 ;
}
}
V_40 = V_42 + 1 ;
if ( ! V_45 )
for ( V_10 = 0 ; V_10 < V_40 ; V_10 ++ )
{
if ( ! F_35 ( V_7 , V_7 , V_7 , & V_50 , V_5 ) )
goto V_8;
}
if ( ! F_35 ( V_7 , V_7 , & ( V_48 [ V_44 >> 1 ] ) , & V_50 , V_5 ) )
goto V_8;
V_41 -= V_42 + 1 ;
V_44 = 0 ;
V_45 = 0 ;
if ( V_41 < 0 ) break;
}
V_1 = 1 ;
V_8:
F_8 ( V_5 ) ;
for ( V_10 = 0 ; V_10 < V_46 ; V_10 ++ )
F_36 ( & ( V_48 [ V_10 ] ) ) ;
F_37 ( & V_50 ) ;
return ( V_1 ) ;
}
int F_28 ( T_1 * V_13 , T_1 * V_2 , const T_1 * V_9 ,
const T_1 * V_4 , T_2 * V_5 , T_5 * V_51 )
{
int V_10 , V_40 , V_11 , V_1 = 0 , V_41 , V_42 , V_43 , V_44 ;
int V_45 = 1 , V_46 = 0 ;
T_1 * V_52 , * V_7 ;
T_1 * V_47 ;
T_1 V_48 [ V_49 ] ;
T_5 * V_53 = NULL ;
F_2 ( V_2 ) ;
F_2 ( V_9 ) ;
F_2 ( V_4 ) ;
#ifdef F_26
if( ! V_39 && F_19 ( V_13 , V_2 , V_9 , V_4 ) )
return 1 ;
#endif
if ( ! ( V_4 -> V_52 [ 0 ] & 1 ) )
{
F_38 ( V_54 , V_55 ) ;
return ( 0 ) ;
}
V_11 = F_11 ( V_9 ) ;
if ( V_11 == 0 )
{
F_13 ( V_13 ) ;
return ( 1 ) ;
}
F_3 ( V_5 ) ;
V_52 = F_4 ( V_5 ) ;
V_7 = F_4 ( V_5 ) ;
if ( V_52 == NULL || V_7 == NULL ) goto V_8;
#if 1
if ( V_51 != NULL )
V_53 = V_51 ;
else
#endif
{
if ( ( V_53 = F_39 () ) == NULL ) goto V_8;
if ( ! F_40 ( V_53 , V_4 , V_5 ) ) goto V_8;
}
F_34 ( & V_48 [ 0 ] ) ;
V_46 = 1 ;
if ( F_41 ( V_2 , V_4 ) >= 0 )
{
F_7 ( & ( V_48 [ 0 ] ) , V_2 , V_4 , V_5 ) ;
V_47 = & ( V_48 [ 0 ] ) ;
}
else
V_47 = V_2 ;
if ( ! F_42 ( & ( V_48 [ 0 ] ) , V_47 , V_53 , V_5 ) ) goto V_8;
if ( ! F_43 ( V_52 , & ( V_48 [ 0 ] ) , & ( V_48 [ 0 ] ) , V_53 , V_5 ) ) goto V_8;
if ( V_11 <= 20 )
V_43 = 1 ;
else if ( V_11 >= 256 )
V_43 = 5 ;
else if ( V_11 >= 128 )
V_43 = 4 ;
else
V_43 = 3 ;
V_40 = 1 << ( V_43 - 1 ) ;
for ( V_10 = 1 ; V_10 < V_40 ; V_10 ++ )
{
F_34 ( & ( V_48 [ V_10 ] ) ) ;
if ( ! F_43 ( & ( V_48 [ V_10 ] ) , & ( V_48 [ V_10 - 1 ] ) , V_52 , V_53 , V_5 ) )
goto V_8;
}
V_46 = V_10 ;
V_45 = 1 ;
V_44 = 0 ;
V_41 = V_11 - 1 ;
V_42 = 0 ;
if ( ! F_42 ( V_7 , F_44 () , V_53 , V_5 ) ) goto V_8;
for (; ; )
{
if ( F_14 ( V_9 , V_41 ) == 0 )
{
if ( ! V_45 )
{
if ( ! F_43 ( V_7 , V_7 , V_7 , V_53 , V_5 ) )
goto V_8;
}
if ( V_41 == 0 ) break;
V_41 -- ;
continue;
}
V_40 = V_41 ;
V_44 = 1 ;
V_42 = 0 ;
for ( V_10 = 1 ; V_10 < V_43 ; V_10 ++ )
{
if ( V_41 - V_10 < 0 ) break;
if ( F_14 ( V_9 , V_41 - V_10 ) )
{
V_44 <<= ( V_10 - V_42 ) ;
V_44 |= 1 ;
V_42 = V_10 ;
}
}
V_40 = V_42 + 1 ;
if ( ! V_45 )
for ( V_10 = 0 ; V_10 < V_40 ; V_10 ++ )
{
if ( ! F_43 ( V_7 , V_7 , V_7 , V_53 , V_5 ) )
goto V_8;
}
if ( ! F_43 ( V_7 , V_7 , & ( V_48 [ V_44 >> 1 ] ) , V_53 , V_5 ) )
goto V_8;
V_41 -= V_42 + 1 ;
V_44 = 0 ;
V_45 = 0 ;
if ( V_41 < 0 ) break;
}
F_45 ( V_13 , V_7 , V_53 , V_5 ) ;
V_1 = 1 ;
V_8:
if ( ( V_51 == NULL ) && ( V_53 != NULL ) ) F_46 ( V_53 ) ;
F_8 ( V_5 ) ;
for ( V_10 = 0 ; V_10 < V_46 ; V_10 ++ )
F_36 ( & ( V_48 [ V_10 ] ) ) ;
return ( V_1 ) ;
}
int F_31 ( T_1 * V_7 , T_1 * V_2 , T_1 * V_9 , T_1 * V_4 ,
T_2 * V_5 )
{
int V_10 , V_40 , V_11 , V_1 = 0 , V_41 , V_42 , V_43 , V_44 , V_46 = 0 ;
int V_45 = 1 ;
T_1 * V_52 ;
T_1 V_48 [ V_49 ] ;
V_11 = F_11 ( V_9 ) ;
if ( V_11 == 0 )
{
F_13 ( V_7 ) ;
return ( 1 ) ;
}
F_3 ( V_5 ) ;
if ( ( V_52 = F_4 ( V_5 ) ) == NULL ) goto V_8;
F_34 ( & ( V_48 [ 0 ] ) ) ;
V_46 = 1 ;
if ( ! F_7 ( & ( V_48 [ 0 ] ) , V_2 , V_4 , V_5 ) ) goto V_8;
if ( ! F_1 ( V_52 , & ( V_48 [ 0 ] ) , & ( V_48 [ 0 ] ) , V_4 , V_5 ) )
goto V_8;
if ( V_11 <= 17 )
V_43 = 1 ;
else if ( V_11 >= 256 )
V_43 = 5 ;
else if ( V_11 >= 128 )
V_43 = 4 ;
else
V_43 = 3 ;
V_40 = 1 << ( V_43 - 1 ) ;
for ( V_10 = 1 ; V_10 < V_40 ; V_10 ++ )
{
F_34 ( & ( V_48 [ V_10 ] ) ) ;
if ( ! F_1 ( & ( V_48 [ V_10 ] ) , & ( V_48 [ V_10 - 1 ] ) , V_52 , V_4 , V_5 ) )
goto V_8;
}
V_46 = V_10 ;
V_45 = 1 ;
V_44 = 0 ;
V_41 = V_11 - 1 ;
V_42 = 0 ;
if ( ! F_13 ( V_7 ) ) goto V_8;
for (; ; )
{
if ( F_14 ( V_9 , V_41 ) == 0 )
{
if ( ! V_45 )
if ( ! F_1 ( V_7 , V_7 , V_7 , V_4 , V_5 ) )
goto V_8;
if ( V_41 == 0 ) break;
V_41 -- ;
continue;
}
V_40 = V_41 ;
V_44 = 1 ;
V_42 = 0 ;
for ( V_10 = 1 ; V_10 < V_43 ; V_10 ++ )
{
if ( V_41 - V_10 < 0 ) break;
if ( F_14 ( V_9 , V_41 - V_10 ) )
{
V_44 <<= ( V_10 - V_42 ) ;
V_44 |= 1 ;
V_42 = V_10 ;
}
}
V_40 = V_42 + 1 ;
if ( ! V_45 )
for ( V_10 = 0 ; V_10 < V_40 ; V_10 ++ )
{
if ( ! F_1 ( V_7 , V_7 , V_7 , V_4 , V_5 ) )
goto V_8;
}
if ( ! F_1 ( V_7 , V_7 , & ( V_48 [ V_44 >> 1 ] ) , V_4 , V_5 ) )
goto V_8;
V_41 -= V_42 + 1 ;
V_44 = 0 ;
V_45 = 0 ;
if ( V_41 < 0 ) break;
}
V_1 = 1 ;
V_8:
F_8 ( V_5 ) ;
for ( V_10 = 0 ; V_10 < V_46 ; V_10 ++ )
F_36 ( & ( V_48 [ V_10 ] ) ) ;
return ( V_1 ) ;
}

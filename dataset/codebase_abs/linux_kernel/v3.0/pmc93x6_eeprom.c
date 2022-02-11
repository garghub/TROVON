STATIC void
F_1 ( void )
{
long V_1 ;
int V_2 ;
V_3 [ 0 ] = 0 ;
for ( V_1 = 1 ; V_1 < sizeof ( V_3 ) ; V_1 <<= 1 )
for ( V_2 = 0 ; V_2 < V_1 ; V_2 ++ )
V_3 [ V_1 + V_2 ] = ( char ) ( V_3 [ V_2 ] | ( 0x80 / V_1 ) ) ;
V_4 = TRUE ;
}
STATIC void
F_2 ( void )
{
int V_5 ;
for ( V_5 = 20 ; V_5 ; -- V_5 )
{
F_3 () ;
}
}
void
F_4 ( long V_6 , long V_7 , int V_8 )
{
T_1 V_9 ;
while ( -- V_8 >= 0 )
{
V_9 = ( V_7 & V_10 ) ? 1 : 0 ;
V_9 |= V_11 ;
V_7 >>= 1 ;
F_2 () ;
F_5 ( ( T_1 * ) V_6 , V_9 ) ;
}
}
T_1
F_6 ( long V_6 )
{
T_1 V_12 ;
T_1 V_7 ;
int V_8 ;
V_12 = F_7 ( ( T_1 * ) V_6 ) ;
V_7 = 0 ;
V_8 = V_13 ;
while ( -- V_8 >= 0 )
{
F_2 () ;
V_12 = F_7 ( ( T_1 * ) V_6 ) ;
V_7 <<= 1 ;
V_7 |= ( V_12 & V_14 ) ? 1 : 0 ;
}
return V_7 ;
}
STATIC void
F_8 ( long V_6 )
{
F_4 ( V_6 , V_15 , V_16 ) ;
F_5 ( ( T_1 * ) V_6 , 0 ) ;
}
STATIC void
F_9 ( long V_6 )
{
F_4 ( V_6 , V_17 , V_16 ) ;
F_5 ( ( T_1 * ) V_6 , 0 ) ;
}
T_1
F_10 ( long V_6 , long V_18 )
{
T_1 V_7 ;
if ( ! V_4 )
F_1 () ;
V_18 = V_3 [ 0x7F & V_18 ] ;
V_18 <<= 2 ;
V_18 |= V_19 ;
F_4 ( V_6 , V_18 , V_16 ) ;
V_7 = F_6 ( V_6 ) ;
F_5 ( ( T_1 * ) V_6 , 0 ) ;
return ( V_7 & 0x000000FF ) ;
}
int
F_11 ( long V_6 , long V_18 , T_1 V_7 )
{
volatile T_1 V_20 ;
int V_8 ;
if ( ! V_4 )
F_1 () ;
V_18 = V_3 [ 0x7F & V_18 ] ;
V_18 <<= 2 ;
V_18 |= V_21 ;
F_4 ( V_6 , V_18 , V_16 ) ;
V_7 = V_3 [ 0xFF & V_7 ] ;
F_4 ( V_6 , V_7 , V_13 ) ;
F_5 ( ( T_1 * ) V_6 , 0 ) ;
F_5 ( ( T_1 * ) V_6 , V_11 ) ;
V_20 = F_7 ( ( T_1 * ) V_6 ) ;
V_20 = F_7 ( ( T_1 * ) V_6 ) ;
if ( V_20 & V_14 )
{
V_20 = F_7 ( ( T_1 * ) V_6 ) ;
if ( V_20 & V_14 )
{
F_5 ( ( T_1 * ) V_6 , 0 ) ;
return ( 1 ) ;
}
}
V_8 = 1000 ;
while ( V_8 -- )
{
for ( V_20 = 0 ; V_20 < 0x10 ; V_20 ++ )
F_3 () ;
if ( F_7 ( ( T_1 * ) V_6 ) & V_14 )
break;
}
if ( V_8 == - 1 )
return ( 2 ) ;
return ( 0 ) ;
}
long
F_12 ( char * V_22 , int V_23 )
{
long V_24 = 0 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_23 ; ++ V_25 )
{
V_24 <<= 8 ;
V_24 |= V_22 [ V_25 ] & 0xFF ;
}
return V_24 ;
}
void
F_13 ( char * V_22 , long V_24 , int V_23 )
{
int V_25 = V_23 ;
while ( -- V_25 >= 0 )
{
V_22 [ V_25 ] = ( char ) ( V_24 & 0xFF ) ;
V_24 >>= 8 ;
}
}
void
F_14 ( long V_6 , long V_18 , char * V_26 , int V_23 )
{
while ( -- V_23 >= 0 )
* V_26 ++ = ( char ) F_10 ( V_6 , V_18 ++ ) ;
}
void
F_15 ( long V_6 , long V_18 , char * V_26 , int V_23 )
{
F_9 ( V_6 ) ;
while ( -- V_23 >= 0 )
F_11 ( V_6 , V_18 ++ , * V_26 ++ ) ;
F_8 ( V_6 ) ;
}
T_1
F_16 ( void * V_27 )
{
T_2 * V_28 = V_27 ;
T_1 V_29 ;
F_17 (
( V_30 * ) & V_28 -> type ,
( T_1 ) F_18 ( V_31 , V_32 ) ,
( T_1 ) 0 ,
( T_1 * ) & V_29 ) ;
#ifdef F_19
F_20 ( L_1 , V_29 ) ;
#endif
return ~ V_29 ;
}
T_1
F_21 ( void * V_27 )
{
T_2 * V_28 = V_27 ;
T_1 V_29 ;
F_17 (
( V_30 * ) & V_28 -> type ,
( T_1 ) F_18 ( T_2 , V_32 ) ,
( T_1 ) 0 ,
( T_1 * ) & V_29 ) ;
F_17 (
( V_30 * ) & V_28 -> V_33 [ 0 ] ,
( T_1 ) ( sizeof ( T_2 ) - F_18 ( T_2 , V_33 ) ) ,
( T_1 ) V_29 ,
( T_1 * ) & V_29 ) ;
#ifdef F_19
F_20 ( L_2 , V_29 ) ;
#endif
return V_29 ;
}
void
F_22 ( T_1 V_6 , T_1 V_34 )
{
T_3 V_35 ;
T_1 V_29 ;
T_4 V_36 ;
int V_2 ;
V_36 = F_23 () ;
for ( V_2 = 0 ; V_2 < sizeof ( T_2 ) ; ++ V_2 )
V_35 . V_37 [ V_2 ] = V_38 [ V_2 ] ;
F_13 ( & V_35 . V_39 . V_40 [ 3 ] , V_34 , 3 ) ;
F_13 ( & V_35 . V_39 . V_41 [ 0 ] , V_36 , 4 ) ;
V_29 = F_21 ( & V_35 ) ;
F_13 ( & V_35 . V_39 . V_32 [ 0 ] , V_29 , 4 ) ;
#ifdef F_24
for ( V_2 = 0 ; V_2 < sizeof ( T_2 ) ; ++ V_2 )
F_20 ( L_3 , V_2 , V_35 . V_37 [ V_2 ] & 0xFF ) ;
#endif
F_15 ( V_6 , V_42 , ( char * ) & V_35 , sizeof ( T_2 ) ) ;
}
char
F_25 ( void * V_27 )
{
V_31 * V_43 = V_27 ;
T_2 * V_44 = V_27 ;
T_1 V_45 , V_46 ;
V_45 = F_12 ( & V_43 -> V_32 [ 0 ] , sizeof ( V_43 -> V_32 ) ) ;
#ifdef F_19
F_20 ( L_4 , V_45 ) ;
#endif
if ( ( V_43 -> type == V_47 ) &&
( F_16 ( ( void * ) V_43 ) == V_45 ) )
return V_47 ;
V_46 = F_12 ( & V_44 -> V_32 [ 0 ] , sizeof ( V_44 -> V_32 ) ) ;
#ifdef F_19
F_20 ( L_5 , V_46 ) ;
#endif
if ( ( V_44 -> type == V_48 ) &&
( F_21 ( ( void * ) V_44 ) == V_46 ) )
return V_48 ;
return V_49 ;
}

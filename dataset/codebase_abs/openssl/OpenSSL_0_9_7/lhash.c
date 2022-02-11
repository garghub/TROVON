T_1 * F_1 ( T_2 V_1 , T_3 V_2 )
{
T_1 * V_3 ;
int V_4 ;
if ( ( V_3 = ( T_1 * ) F_2 ( sizeof( T_1 ) ) ) == NULL )
goto V_5;
if ( ( V_3 -> V_6 = ( V_7 * * ) F_2 ( sizeof( V_7 * ) * V_8 ) ) == NULL )
goto V_9;
for ( V_4 = 0 ; V_4 < V_8 ; V_4 ++ )
V_3 -> V_6 [ V_4 ] = NULL ;
V_3 -> V_10 = ( ( V_2 == NULL ) ? ( T_3 ) strcmp : V_2 ) ;
V_3 -> V_11 = ( ( V_1 == NULL ) ? ( T_2 ) V_12 : V_1 ) ;
V_3 -> V_13 = V_8 / 2 ;
V_3 -> V_14 = V_8 ;
V_3 -> V_15 = 0 ;
V_3 -> V_16 = V_8 / 2 ;
V_3 -> V_17 = V_18 ;
V_3 -> V_19 = V_20 ;
V_3 -> V_21 = 0 ;
V_3 -> V_22 = 0 ;
V_3 -> V_23 = 0 ;
V_3 -> V_24 = 0 ;
V_3 -> V_25 = 0 ;
V_3 -> V_26 = 0 ;
V_3 -> V_27 = 0 ;
V_3 -> V_28 = 0 ;
V_3 -> V_29 = 0 ;
V_3 -> V_30 = 0 ;
V_3 -> V_31 = 0 ;
V_3 -> V_32 = 0 ;
V_3 -> V_33 = 0 ;
V_3 -> V_34 = 0 ;
V_3 -> error = 0 ;
return ( V_3 ) ;
V_9:
F_3 ( V_3 ) ;
V_5:
return ( NULL ) ;
}
void F_4 ( T_1 * V_35 )
{
unsigned int V_4 ;
V_7 * V_36 , * V_37 ;
if ( V_35 == NULL )
return;
for ( V_4 = 0 ; V_4 < V_35 -> V_13 ; V_4 ++ )
{
V_36 = V_35 -> V_6 [ V_4 ] ;
while ( V_36 != NULL )
{
V_37 = V_36 -> V_38 ;
F_3 ( V_36 ) ;
V_36 = V_37 ;
}
}
F_3 ( V_35 -> V_6 ) ;
F_3 ( V_35 ) ;
}
void * F_5 ( T_1 * V_35 , const void * V_39 )
{
unsigned long V_11 ;
V_7 * V_37 , * * V_40 ;
const void * V_3 ;
V_35 -> error = 0 ;
if ( V_35 -> V_17 <= ( V_35 -> V_21 * V_41 / V_35 -> V_13 ) )
F_6 ( V_35 ) ;
V_40 = F_7 ( V_35 , V_39 , & V_11 ) ;
if ( * V_40 == NULL )
{
if ( ( V_37 = ( V_7 * ) F_2 ( sizeof( V_7 ) ) ) == NULL )
{
V_35 -> error ++ ;
return ( NULL ) ;
}
V_37 -> V_39 = V_39 ;
V_37 -> V_38 = NULL ;
#ifndef F_8
V_37 -> V_11 = V_11 ;
#endif
* V_40 = V_37 ;
V_3 = NULL ;
V_35 -> V_28 ++ ;
V_35 -> V_21 ++ ;
}
else
{
V_3 = ( * V_40 ) -> V_39 ;
( * V_40 ) -> V_39 = V_39 ;
V_35 -> V_29 ++ ;
}
return ( ( void * ) V_3 ) ;
}
void * F_9 ( T_1 * V_35 , const void * V_39 )
{
unsigned long V_11 ;
V_7 * V_37 , * * V_40 ;
const void * V_3 ;
V_35 -> error = 0 ;
V_40 = F_7 ( V_35 , V_39 , & V_11 ) ;
if ( * V_40 == NULL )
{
V_35 -> V_31 ++ ;
return ( NULL ) ;
}
else
{
V_37 = * V_40 ;
* V_40 = V_37 -> V_38 ;
V_3 = V_37 -> V_39 ;
F_3 ( V_37 ) ;
V_35 -> V_30 ++ ;
}
V_35 -> V_21 -- ;
if ( ( V_35 -> V_13 > V_8 ) &&
( V_35 -> V_19 >= ( V_35 -> V_21 * V_41 / V_35 -> V_13 ) ) )
F_10 ( V_35 ) ;
return ( ( void * ) V_3 ) ;
}
void * F_11 ( T_1 * V_35 , const void * V_39 )
{
unsigned long V_11 ;
V_7 * * V_40 ;
const void * V_3 ;
V_35 -> error = 0 ;
V_40 = F_7 ( V_35 , V_39 , & V_11 ) ;
if ( * V_40 == NULL )
{
V_35 -> V_33 ++ ;
return ( NULL ) ;
}
else
{
V_3 = ( * V_40 ) -> V_39 ;
V_35 -> V_32 ++ ;
}
return ( ( void * ) V_3 ) ;
}
static void F_12 ( T_1 * V_35 , int V_42 , T_4 V_43 ,
T_5 V_44 , void * V_45 )
{
int V_4 ;
V_7 * V_46 , * V_36 ;
for ( V_4 = V_35 -> V_13 - 1 ; V_4 >= 0 ; V_4 -- )
{
V_46 = V_35 -> V_6 [ V_4 ] ;
while ( V_46 != NULL )
{
V_36 = V_46 -> V_38 ;
if( V_42 )
V_44 ( V_46 -> V_39 , V_45 ) ;
else
V_43 ( V_46 -> V_39 ) ;
V_46 = V_36 ;
}
}
}
void F_13 ( T_1 * V_35 , T_4 V_43 )
{
F_12 ( V_35 , 0 , V_43 , ( T_5 ) 0 , NULL ) ;
}
void F_14 ( T_1 * V_35 , T_5 V_43 , void * V_45 )
{
F_12 ( V_35 , 1 , ( T_4 ) 0 , V_43 , V_45 ) ;
}
static void F_6 ( T_1 * V_35 )
{
V_7 * * V_36 , * * V_47 , * * V_48 , * V_49 ;
unsigned int V_15 , V_4 , V_50 ;
unsigned long V_11 , V_51 ;
V_35 -> V_13 ++ ;
V_35 -> V_22 ++ ;
V_15 = ( int ) V_35 -> V_15 ++ ;
V_47 = & ( V_35 -> V_6 [ V_15 ] ) ;
V_48 = & ( V_35 -> V_6 [ V_15 + ( int ) V_35 -> V_16 ] ) ;
* V_48 = NULL ;
V_51 = V_35 -> V_14 ;
for ( V_49 = * V_47 ; V_49 != NULL ; )
{
#ifndef F_8
V_11 = V_49 -> V_11 ;
#else
V_11 = V_35 -> V_11 ( V_49 -> V_39 ) ;
V_35 -> V_26 ++ ;
#endif
if ( ( V_11 % V_51 ) != V_15 )
{
* V_47 = ( * V_47 ) -> V_38 ;
V_49 -> V_38 = * V_48 ;
* V_48 = V_49 ;
}
else
V_47 = & ( ( * V_47 ) -> V_38 ) ;
V_49 = * V_47 ;
}
if ( ( V_35 -> V_15 ) >= V_35 -> V_16 )
{
V_50 = ( int ) V_35 -> V_14 * 2 ;
V_36 = ( V_7 * * ) F_15 ( V_35 -> V_6 ,
( unsigned int ) sizeof( V_7 * ) * V_50 ) ;
if ( V_36 == NULL )
{
V_35 -> error ++ ;
V_35 -> V_15 = 0 ;
return;
}
for ( V_4 = ( int ) V_35 -> V_14 ; V_4 < V_50 ; V_4 ++ )
V_36 [ V_4 ] = NULL ;
V_35 -> V_16 = V_35 -> V_14 ;
V_35 -> V_14 = V_50 ;
V_35 -> V_23 ++ ;
V_35 -> V_15 = 0 ;
V_35 -> V_6 = V_36 ;
}
}
static void F_10 ( T_1 * V_35 )
{
V_7 * * V_36 , * V_47 , * V_49 ;
V_49 = V_35 -> V_6 [ V_35 -> V_15 + V_35 -> V_16 - 1 ] ;
V_35 -> V_6 [ V_35 -> V_15 + V_35 -> V_16 - 1 ] = NULL ;
if ( V_35 -> V_15 == 0 )
{
V_36 = ( V_7 * * ) F_15 ( V_35 -> V_6 ,
( unsigned int ) ( sizeof( V_7 * ) * V_35 -> V_16 ) ) ;
if ( V_36 == NULL )
{
V_35 -> error ++ ;
return;
}
V_35 -> V_25 ++ ;
V_35 -> V_14 /= 2 ;
V_35 -> V_16 /= 2 ;
V_35 -> V_15 = V_35 -> V_16 - 1 ;
V_35 -> V_6 = V_36 ;
}
else
V_35 -> V_15 -- ;
V_35 -> V_13 -- ;
V_35 -> V_24 ++ ;
V_47 = V_35 -> V_6 [ ( int ) V_35 -> V_15 ] ;
if ( V_47 == NULL )
V_35 -> V_6 [ ( int ) V_35 -> V_15 ] = V_49 ;
else
{
while ( V_47 -> V_38 != NULL )
V_47 = V_47 -> V_38 ;
V_47 -> V_38 = V_49 ;
}
}
static V_7 * * F_7 ( T_1 * V_35 , const void * V_39 , unsigned long * V_52 )
{
V_7 * * V_3 , * V_47 ;
unsigned long V_11 , V_37 ;
int (* F_16)();
V_11 = ( * ( V_35 -> V_11 ) ) ( V_39 ) ;
V_35 -> V_26 ++ ;
* V_52 = V_11 ;
V_37 = V_11 % V_35 -> V_16 ;
if ( V_37 < V_35 -> V_15 )
V_37 = V_11 % V_35 -> V_14 ;
F_16 = V_35 -> V_10 ;
V_3 = & ( V_35 -> V_6 [ ( int ) V_37 ] ) ;
for ( V_47 = * V_3 ; V_47 != NULL ; V_47 = V_47 -> V_38 )
{
#ifndef F_8
V_35 -> V_34 ++ ;
if ( V_47 -> V_11 != V_11 )
{
V_3 = & ( V_47 -> V_38 ) ;
continue;
}
#endif
V_35 -> V_27 ++ ;
if( F_16 ( V_47 -> V_39 , V_39 ) == 0 )
break;
V_3 = & ( V_47 -> V_38 ) ;
}
return ( V_3 ) ;
}
unsigned long V_12 ( const char * V_2 )
{
unsigned long V_3 = 0 ;
long V_36 ;
unsigned long V_53 ;
int V_54 ;
if ( ( V_2 == NULL ) || ( * V_2 == '\0' ) )
return ( V_3 ) ;
V_36 = 0x100 ;
while ( * V_2 )
{
V_53 = V_36 | ( * V_2 ) ;
V_36 += 0x100 ;
V_54 = ( int ) ( ( V_53 >> 2 ) ^ V_53 ) & 0x0f ;
V_3 = ( V_3 << V_54 ) | ( V_3 >> ( 32 - V_54 ) ) ;
V_3 &= 0xFFFFFFFFL ;
V_3 ^= V_53 * V_53 ;
V_2 ++ ;
}
return ( ( V_3 >> 16 ) ^ V_3 ) ;
}
unsigned long F_17 ( const T_1 * V_35 )
{
return V_35 ? V_35 -> V_21 : 0 ;
}

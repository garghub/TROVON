int F_1 ( const T_1 * V_1 , const T_1 * V_2 )
{
int V_3 ;
T_2 * V_4 , * V_5 ;
V_4 = V_1 -> V_6 ;
V_5 = V_2 -> V_6 ;
V_3 = F_2 ( V_4 -> V_7 , V_5 -> V_7 ) ;
if ( V_3 ) return ( V_3 ) ;
return ( F_3 ( V_4 -> V_8 , V_5 -> V_8 ) ) ;
}
unsigned long F_4 ( T_1 * V_1 )
{
unsigned long V_9 = 0 ;
T_3 V_10 ;
unsigned char V_11 [ 16 ] ;
char V_12 [ 256 ] ;
F_5 ( V_1 -> V_6 -> V_8 , V_12 , 256 ) ;
V_9 = strlen ( V_12 ) ;
F_6 ( & V_10 ) ;
F_7 ( & V_10 , ( unsigned char * ) V_12 , V_9 ) ;
F_7 ( & V_10 , ( unsigned char * ) V_1 -> V_6 -> V_7 -> V_13 ,
( unsigned long ) V_1 -> V_6 -> V_7 -> V_14 ) ;
F_8 ( & ( V_11 [ 0 ] ) , & V_10 ) ;
V_9 = ( ( ( unsigned long ) V_11 [ 0 ] ) | ( ( unsigned long ) V_11 [ 1 ] << 8L ) |
( ( unsigned long ) V_11 [ 2 ] << 16L ) | ( ( unsigned long ) V_11 [ 3 ] << 24L )
) & 0xffffffffL ;
return ( V_9 ) ;
}
int F_9 ( const T_1 * V_1 , const T_1 * V_2 )
{
return ( F_3 ( V_1 -> V_6 -> V_8 , V_2 -> V_6 -> V_8 ) ) ;
}
int F_10 ( const T_1 * V_1 , const T_1 * V_2 )
{
return ( F_3 ( V_1 -> V_6 -> V_15 , V_2 -> V_6 -> V_15 ) ) ;
}
int F_11 ( const T_4 * V_1 , const T_4 * V_2 )
{
return ( F_3 ( V_1 -> V_16 -> V_8 , V_2 -> V_16 -> V_8 ) ) ;
}
T_5 * F_12 ( T_1 * V_1 )
{
return ( V_1 -> V_6 -> V_8 ) ;
}
unsigned long F_13 ( T_1 * V_17 )
{
return ( F_14 ( V_17 -> V_6 -> V_8 ) ) ;
}
T_5 * F_15 ( T_1 * V_1 )
{
return ( V_1 -> V_6 -> V_15 ) ;
}
T_6 * F_16 ( T_1 * V_1 )
{
return ( V_1 -> V_6 -> V_7 ) ;
}
unsigned long F_17 ( T_1 * V_17 )
{
return ( F_14 ( V_17 -> V_6 -> V_15 ) ) ;
}
int F_18 ( const T_1 * V_1 , const T_1 * V_2 )
{
F_19 ( ( T_1 * ) V_1 , - 1 , 0 ) ;
F_19 ( ( T_1 * ) V_2 , - 1 , 0 ) ;
return memcmp ( V_1 -> V_18 , V_2 -> V_18 , V_19 ) ;
}
int F_3 ( const T_5 * V_1 , const T_5 * V_2 )
{
int V_3 , V_20 ;
T_7 * V_21 , * V_22 ;
if ( F_20 ( V_1 -> V_23 )
!= F_20 ( V_2 -> V_23 ) )
return F_20 ( V_1 -> V_23 )
- F_20 ( V_2 -> V_23 ) ;
for ( V_3 = F_20 ( V_1 -> V_23 ) - 1 ; V_3 >= 0 ; V_3 -- )
{
V_21 = F_21 ( V_1 -> V_23 , V_3 ) ;
V_22 = F_21 ( V_2 -> V_23 , V_3 ) ;
V_20 = V_21 -> V_24 -> V_14 - V_22 -> V_24 -> V_14 ;
if ( V_20 ) return ( V_20 ) ;
V_20 = memcmp ( V_21 -> V_24 -> V_13 , V_22 -> V_24 -> V_13 ,
V_21 -> V_24 -> V_14 ) ;
if ( V_20 ) return ( V_20 ) ;
V_20 = V_21 -> V_25 - V_22 -> V_25 ;
if ( V_20 ) return ( V_20 ) ;
}
for ( V_3 = F_20 ( V_1 -> V_23 ) - 1 ; V_3 >= 0 ; V_3 -- )
{
V_21 = F_21 ( V_1 -> V_23 , V_3 ) ;
V_22 = F_21 ( V_2 -> V_23 , V_3 ) ;
V_20 = F_22 ( V_21 -> V_26 , V_22 -> V_26 ) ;
if ( V_20 ) return ( V_20 ) ;
}
return ( 0 ) ;
}
unsigned long F_14 ( T_5 * V_17 )
{
unsigned long V_9 = 0 ;
unsigned char V_11 [ 16 ] ;
unsigned char V_12 [ 256 ] , * V_27 , * V_28 ;
int V_3 ;
V_3 = F_23 ( V_17 , NULL ) ;
if ( V_3 > sizeof( V_12 ) )
V_27 = F_24 ( V_3 ) ;
else
V_27 = V_12 ;
V_28 = V_27 ;
F_23 ( V_17 , & V_28 ) ;
F_25 ( ( unsigned char * ) V_27 , V_3 , & ( V_11 [ 0 ] ) ) ;
if ( V_27 != V_12 ) F_26 ( V_27 ) ;
V_9 = ( ( ( unsigned long ) V_11 [ 0 ] ) | ( ( unsigned long ) V_11 [ 1 ] << 8L ) |
( ( unsigned long ) V_11 [ 2 ] << 16L ) | ( ( unsigned long ) V_11 [ 3 ] << 24L )
) & 0xffffffffL ;
return ( V_9 ) ;
}
T_8 * F_27 ( T_1 * V_17 )
{
if ( ( V_17 == NULL ) || ( V_17 -> V_6 == NULL ) )
return ( NULL ) ;
return ( F_28 ( V_17 -> V_6 -> V_29 ) ) ;
}
int F_29 ( T_1 * V_17 , T_8 * V_30 )
{
T_8 * V_31 = NULL ;
int V_32 = 0 ;
V_31 = F_27 ( V_17 ) ;
if ( V_31 -> type != V_30 -> type )
{
F_30 ( V_33 , V_34 ) ;
goto V_35;
}
switch ( V_30 -> type )
{
#ifndef F_31
case V_36 :
if ( F_32 ( V_31 -> V_37 . V_38 -> V_39 , V_30 -> V_37 . V_38 -> V_39 ) != 0
|| F_32 ( V_31 -> V_37 . V_38 -> V_40 , V_30 -> V_37 . V_38 -> V_40 ) != 0 )
{
F_30 ( V_33 , V_41 ) ;
goto V_35;
}
break;
#endif
#ifndef F_33
case V_42 :
if ( F_32 ( V_31 -> V_37 . V_43 -> V_44 , V_30 -> V_37 . V_43 -> V_44 ) != 0 )
{
F_30 ( V_33 , V_41 ) ;
goto V_35;
}
break;
#endif
#ifndef F_34
case V_45 :
F_30 ( V_33 , V_46 ) ;
goto V_35;
#endif
default:
F_30 ( V_33 , V_47 ) ;
goto V_35;
}
V_32 = 1 ;
V_35:
F_35 ( V_31 ) ;
return ( V_32 ) ;
}

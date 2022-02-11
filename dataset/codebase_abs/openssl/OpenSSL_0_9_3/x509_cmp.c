int F_1 ( T_1 * V_1 , T_1 * V_2 )
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
int F_9 ( T_1 * V_1 , T_1 * V_2 )
{
return ( F_3 ( V_1 -> V_6 -> V_8 , V_2 -> V_6 -> V_8 ) ) ;
}
int F_10 ( T_1 * V_1 , T_1 * V_2 )
{
return ( F_3 ( V_1 -> V_6 -> V_15 , V_2 -> V_6 -> V_15 ) ) ;
}
int F_11 ( T_4 * V_1 , T_4 * V_2 )
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
int F_3 ( T_5 * V_1 , T_5 * V_2 )
{
int V_3 , V_18 ;
T_7 * V_19 , * V_20 ;
if ( F_18 ( V_1 -> V_21 )
!= F_18 ( V_2 -> V_21 ) )
return F_18 ( V_1 -> V_21 )
- F_18 ( V_2 -> V_21 ) ;
for ( V_3 = F_18 ( V_1 -> V_21 ) - 1 ; V_3 >= 0 ; V_3 -- )
{
V_19 = F_19 ( V_1 -> V_21 , V_3 ) ;
V_20 = F_19 ( V_2 -> V_21 , V_3 ) ;
V_18 = V_19 -> V_22 -> V_14 - V_20 -> V_22 -> V_14 ;
if ( V_18 ) return ( V_18 ) ;
V_18 = memcmp ( V_19 -> V_22 -> V_13 , V_20 -> V_22 -> V_13 ,
V_19 -> V_22 -> V_14 ) ;
if ( V_18 ) return ( V_18 ) ;
V_18 = V_19 -> V_23 - V_20 -> V_23 ;
if ( V_18 ) return ( V_18 ) ;
}
for ( V_3 = F_18 ( V_1 -> V_21 ) - 1 ; V_3 >= 0 ; V_3 -- )
{
V_19 = F_19 ( V_1 -> V_21 , V_3 ) ;
V_20 = F_19 ( V_2 -> V_21 , V_3 ) ;
V_18 = F_20 ( V_19 -> V_24 , V_20 -> V_24 ) ;
if ( V_18 ) return ( V_18 ) ;
}
return ( 0 ) ;
}
unsigned long F_14 ( T_5 * V_17 )
{
unsigned long V_9 = 0 ;
unsigned char V_11 [ 16 ] ;
unsigned char V_12 [ 256 ] , * V_25 , * V_26 ;
int V_3 ;
V_3 = F_21 ( V_17 , NULL ) ;
if ( V_3 > sizeof( V_12 ) )
V_25 = Malloc ( V_3 ) ;
else
V_25 = V_12 ;
V_26 = V_25 ;
F_21 ( V_17 , & V_26 ) ;
F_22 ( ( unsigned char * ) V_25 , V_3 , & ( V_11 [ 0 ] ) ) ;
if ( V_25 != V_12 ) Free ( V_25 ) ;
V_9 = ( ( ( unsigned long ) V_11 [ 0 ] ) | ( ( unsigned long ) V_11 [ 1 ] << 8L ) |
( ( unsigned long ) V_11 [ 2 ] << 16L ) | ( ( unsigned long ) V_11 [ 3 ] << 24L )
) & 0xffffffffL ;
return ( V_9 ) ;
}
T_8 * F_23 ( T_1 * V_17 )
{
if ( ( V_17 == NULL ) || ( V_17 -> V_6 == NULL ) )
return ( NULL ) ;
return ( F_24 ( V_17 -> V_6 -> V_27 ) ) ;
}
int F_25 ( T_1 * V_17 , T_8 * V_28 )
{
T_8 * V_29 = NULL ;
int V_30 = 0 ;
V_29 = F_23 ( V_17 ) ;
if ( V_29 -> type != V_28 -> type )
{
F_26 ( V_31 , V_32 ) ;
goto V_33;
}
switch ( V_28 -> type )
{
#ifndef F_27
case V_34 :
if ( F_28 ( V_29 -> V_35 . V_36 -> V_37 , V_28 -> V_35 . V_36 -> V_37 ) != 0
|| F_28 ( V_29 -> V_35 . V_36 -> V_38 , V_28 -> V_35 . V_36 -> V_38 ) != 0 )
{
F_26 ( V_31 , V_39 ) ;
goto V_33;
}
break;
#endif
#ifndef F_29
case V_40 :
if ( F_28 ( V_29 -> V_35 . V_41 -> V_42 , V_28 -> V_35 . V_41 -> V_42 ) != 0 )
{
F_26 ( V_31 , V_39 ) ;
goto V_33;
}
break;
#endif
#ifndef F_30
case V_43 :
F_26 ( V_31 , V_44 ) ;
goto V_33;
#endif
default:
F_26 ( V_31 , V_45 ) ;
goto V_33;
}
V_30 = 1 ;
V_33:
F_31 ( V_29 ) ;
return ( V_30 ) ;
}

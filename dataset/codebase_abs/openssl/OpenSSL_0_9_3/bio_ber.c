T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 )
{
T_3 * V_3 ;
V_3 = ( T_3 * ) Malloc ( sizeof( T_3 ) ) ;
if ( V_3 == NULL ) return ( 0 ) ;
memset ( ( char * ) V_3 , 0 , sizeof( T_3 ) ) ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = ( char * ) V_3 ;
V_2 -> V_6 = 0 ;
return ( 1 ) ;
}
static int F_3 ( T_2 * V_7 )
{
T_3 * V_8 ;
if ( V_7 == NULL ) return ( 0 ) ;
V_8 = ( T_3 * ) V_7 -> V_5 ;
memset ( V_7 -> V_5 , 0 , sizeof( T_3 ) ) ;
Free ( V_7 -> V_5 ) ;
V_7 -> V_5 = NULL ;
V_7 -> V_4 = 0 ;
V_7 -> V_6 = 0 ;
return ( 1 ) ;
}
int F_4 ( T_2 * V_9 , T_3 * V_3 )
{
char V_10 [ 64 ] ;
int V_11 , V_12 , V_13 ;
int V_14 ;
unsigned char * V_15 ;
unsigned long T_4
int V_16 ;
int V_17 ;
long V_18 ;
F_5 ( V_8 ) ;
if ( V_3 -> V_19 != 0 )
{
V_15 = V_3 -> V_10 ;
V_12 = V_3 -> V_19 ;
V_13 = V_3 -> V_20 - V_12 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ )
{
V_15 [ 0 ] = V_15 [ V_12 ] ;
V_15 ++ ;
}
V_3 -> V_20 - V_12 ;
V_3 -> V_19 = 0 ;
}
V_11 = V_21 - V_3 -> V_20 ;
if ( V_11 )
{
V_11 = F_6 ( V_9 -> V_22 , & ( V_3 -> V_10 [ V_3 -> V_20 ] ) , V_11 ) ;
if ( V_11 <= 0 )
{
F_7 ( V_8 ) ;
return ( V_11 ) ;
}
else
V_3 -> V_20 += V_11 ;
}
V_18 = V_3 -> V_20 ;
V_15 = V_3 -> V_10 ;
V_14 = F_8 ( & V_15 , & T_4 , & V_16 , & V_17 , V_18 ) ;
if ( V_14 & 0x80 )
{
if ( ( V_3 -> V_20 < V_21 ) &&
( F_9 ( F_10 () ) == V_23 ) )
{
F_11 () ;
F_12 ( V_8 ) ;
}
return ( - 1 ) ;
}
if ( ( V_3 -> V_16 >= 0 ) && ( V_3 -> V_16 != V_16 ) )
{
F_13 ( V_24 , V_25 ) ;
sprintf ( V_10 , L_1 , V_3 -> V_16 , V_16 ) ;
F_14 ( 1 , V_10 ) ;
return ( - 1 ) ;
}
if ( V_14 & 0x01 )
if ( V_14 & V_26 )
}
static int F_15 ( T_2 * V_8 , char * V_27 , int V_28 )
{
int V_14 = 0 , V_11 , V_13 ;
T_3 * V_3 ;
F_5 ( V_8 ) ;
if ( V_27 == NULL ) return ( 0 ) ;
V_3 = ( T_3 * ) V_8 -> V_5 ;
if ( ( V_3 == NULL ) || ( V_8 -> V_22 == NULL ) ) return ( 0 ) ;
if ( V_3 -> V_29 ) return ( 0 ) ;
V_30:
if ( V_3 -> V_31 > 0 )
{
if ( V_3 -> V_31 < V_28 )
V_13 = V_3 -> V_31 ;
else
V_13 = V_28 ;
V_11 = F_6 ( V_8 -> V_22 , V_27 , V_13 ) ;
if ( V_11 <= 0 )
{
F_7 ( V_8 ) ;
return ( V_11 ) ;
}
V_3 -> V_31 -= V_11 ;
V_28 -= V_11 ;
V_14 += V_11 ;
if ( V_3 -> V_31 <= 0 )
{
V_3 -> V_32 -- ;
if ( V_3 -> V_32 <= 0 )
V_3 -> V_29 = 1 ;
}
if ( V_28 <= 0 )
return ( V_14 ) ;
else
goto V_30;
}
else
{
}
}
static int F_16 ( T_2 * V_8 , char * V_33 , int V_34 )
{
int V_14 = 0 , V_13 , V_11 ;
T_5 * V_3 ;
V_3 = ( T_5 * ) V_8 -> V_5 ;
V_14 = V_34 ;
F_5 ( V_8 ) ;
V_13 = V_3 -> V_20 - V_3 -> V_19 ;
while ( V_13 > 0 )
{
V_11 = F_17 ( V_8 -> V_22 , & ( V_3 -> V_10 [ V_3 -> V_19 ] ) , V_13 ) ;
if ( V_11 <= 0 )
{
F_7 ( V_8 ) ;
return ( V_11 ) ;
}
V_3 -> V_19 += V_11 ;
V_13 -= V_11 ;
}
if ( ( V_33 == NULL ) || ( V_34 <= 0 ) ) return ( 0 ) ;
V_3 -> V_19 = 0 ;
while ( V_34 > 0 )
{
V_13 = ( V_34 > V_35 ) ? V_35 : V_34 ;
F_18 ( & ( V_3 -> V_36 ) ,
( unsigned char * ) V_3 -> V_10 , & V_3 -> V_20 ,
( unsigned char * ) V_33 , V_13 ) ;
V_34 -= V_13 ;
V_33 += V_13 ;
V_3 -> V_19 = 0 ;
V_13 = V_3 -> V_20 ;
while ( V_13 > 0 )
{
V_11 = F_17 ( V_8 -> V_22 , & ( V_3 -> V_10 [ V_3 -> V_19 ] ) , V_13 ) ;
if ( V_11 <= 0 )
{
F_7 ( V_8 ) ;
return ( V_11 ) ;
}
V_13 -= V_11 ;
V_3 -> V_19 += V_11 ;
}
V_3 -> V_20 = 0 ;
V_3 -> V_19 = 0 ;
}
F_7 ( V_8 ) ;
return ( V_14 ) ;
}
static long F_19 ( T_2 * V_8 , int V_37 , long V_38 , char * V_5 )
{
T_2 * V_39 ;
T_5 * V_3 , * V_40 ;
long V_14 = 1 ;
int V_11 ;
V_3 = ( T_5 * ) V_8 -> V_5 ;
switch ( V_37 )
{
case V_41 :
V_3 -> V_42 = 1 ;
V_3 -> V_29 = 0 ;
F_20 ( & ( V_3 -> V_36 ) , NULL , NULL , NULL ,
V_3 -> V_36 . V_43 ) ;
V_14 = F_21 ( V_8 -> V_22 , V_37 , V_38 , V_5 ) ;
break;
case V_44 :
if ( V_3 -> V_45 <= 0 )
V_14 = 1 ;
else
V_14 = F_21 ( V_8 -> V_22 , V_37 , V_38 , V_5 ) ;
break;
case V_46 :
V_14 = V_3 -> V_20 - V_3 -> V_19 ;
if ( V_14 <= 0 )
V_14 = F_21 ( V_8 -> V_22 , V_37 , V_38 , V_5 ) ;
break;
case V_47 :
V_14 = V_3 -> V_20 - V_3 -> V_19 ;
if ( V_14 <= 0 )
V_14 = F_21 ( V_8 -> V_22 , V_37 , V_38 , V_5 ) ;
break;
case V_48 :
V_30:
while ( V_3 -> V_20 != V_3 -> V_19 )
{
V_11 = F_16 ( V_8 , NULL , 0 ) ;
if ( V_11 < 0 )
{
V_14 = V_11 ;
break;
}
}
if ( ! V_3 -> V_29 )
{
V_3 -> V_29 = 1 ;
V_3 -> V_19 = 0 ;
V_14 = F_22 ( & ( V_3 -> V_36 ) ,
( unsigned char * ) V_3 -> V_10 ,
& ( V_3 -> V_20 ) ) ;
V_3 -> V_42 = ( int ) V_14 ;
if ( V_14 <= 0 ) break;
goto V_30;
}
V_14 = F_21 ( V_8 -> V_22 , V_37 , V_38 , V_5 ) ;
break;
case V_49 :
V_14 = ( long ) V_3 -> V_42 ;
break;
case V_50 :
F_5 ( V_8 ) ;
V_14 = F_21 ( V_8 -> V_22 , V_37 , V_38 , V_5 ) ;
F_7 ( V_8 ) ;
break;
case V_51 :
V_39 = ( T_2 * ) V_5 ;
V_40 = ( T_5 * ) V_39 -> V_5 ;
memcpy ( & ( V_40 -> V_36 ) , & ( V_3 -> V_36 ) , sizeof( V_3 -> V_36 ) ) ;
V_39 -> V_4 = 1 ;
break;
default:
V_14 = F_21 ( V_8 -> V_22 , V_37 , V_38 , V_5 ) ;
break;
}
return ( V_14 ) ;
}
void F_23 ( T_2 * V_8 , T_6 * V_52 , unsigned char * V_53 , unsigned char * V_11 ,
int V_54 )
{
T_5 * V_3 ;
if ( V_8 == NULL ) return;
if ( ( V_8 -> V_55 != NULL ) &&
( V_8 -> V_55 ( V_8 , V_56 , ( char * ) V_52 , V_57 , V_54 , 0L ) <= 0 ) )
return;
V_8 -> V_4 = 1 ;
V_3 = ( T_5 * ) V_8 -> V_5 ;
F_20 ( & ( V_3 -> V_36 ) , V_52 , V_53 , V_11 , V_54 ) ;
if ( V_8 -> V_55 != NULL )
V_8 -> V_55 ( V_8 , V_56 , ( char * ) V_52 , V_57 , V_54 , 1L ) ;
}

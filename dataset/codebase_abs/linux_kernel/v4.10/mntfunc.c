static void F_1 ( unsigned char * V_1 , ... )
{
}
static void * F_2 ( void * V_2 , T_1 * V_3 ,
int V_4 )
{
if ( V_3 -> type == V_5 ) {
F_3 ( ( L_1 ) ) ;
} else if ( V_3 -> type == V_6 ) {
if ( V_4 ) {
F_4 () ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_8 = F_1 ;
} else {
memcpy ( & V_7 , V_3 , sizeof( V_7 ) ) ;
V_8 = ( V_9 ) V_7 . V_10 ;
F_5 ( L_2 , V_11 , V_12 ) ;
}
} else if ( ( V_3 -> type > 0 ) && ( V_3 -> type < 16 ) ) {
if ( V_4 ) {
F_6 ( V_3 ) ;
} else {
F_7 ( V_3 ) ;
}
}
return ( NULL ) ;
}
static int T_2 F_8 ( void )
{
int V_1 = 0 ;
int V_13 = 0 ;
T_3 V_14 ;
T_1 V_15 [ V_16 ] ;
F_9 ( V_15 , sizeof( V_15 ) ) ;
for ( V_1 = 0 ; V_1 < V_16 ; V_1 ++ ) {
if ( V_15 [ V_1 ] . type == V_5 ) {
V_13 = 1 ;
memcpy ( & V_17 , & V_15 [ V_1 ] , sizeof( V_17 ) ) ;
V_14 . V_18 . V_19 . V_20 = 0 ;
V_14 . V_18 . V_19 . V_21 =
V_22 ;
V_14 . V_18 . V_23 . V_24 = ( void * ) F_2 ;
V_14 . V_18 . V_23 . V_2 = NULL ;
V_17 . V_10 ( ( V_25 * ) & V_14 ) ;
if ( V_14 . V_18 . V_19 . V_21 != 0xff )
return ( 0 ) ;
V_26 = V_14 . V_18 . V_23 . V_27 ;
V_14 . V_28 . V_19 . V_20 = 0 ;
V_14 . V_28 . V_19 . V_21 =
V_29 ;
V_14 . V_28 . V_23 . V_30 =
( void * ) & V_31 ;
V_17 . V_10 ( ( V_25 * ) & V_14 ) ;
if ( V_14 . V_28 . V_19 . V_21 != 0xff )
return ( 0 ) ;
} else if ( ( V_15 [ V_1 ] . type > 0 )
&& ( V_15 [ V_1 ] . type < 16 ) ) {
F_7 ( & V_15 [ V_1 ] ) ;
}
}
return ( V_13 ) ;
}
static void T_4 F_10 ( void )
{
T_3 V_14 ;
V_14 . V_18 . V_19 . V_20 = 0 ;
V_14 . V_18 . V_19 . V_21 = V_32 ;
V_14 . V_18 . V_23 . V_27 = V_26 ;
V_17 . V_10 ( ( V_25 * ) & V_14 ) ;
V_14 . V_33 . V_19 . V_20 = 0 ;
V_14 . V_33 . V_19 . V_21 = V_34 ;
V_14 . V_33 . V_23 . V_35 =
( V_36 ) V_31 . V_10 ;
V_17 . V_10 ( ( V_25 * ) & V_14 ) ;
}
int F_11 ( void T_5 * V_37 , int V_38 )
{
T_6 V_39 [ 128 ] ;
T_7 V_40 , V_41 , V_42 ;
int V_43 = 0 ;
if ( V_38 < ( 3 * sizeof( T_7 ) ) )
return ( - V_44 ) ;
if ( F_12 ( NULL , ( void * ) & V_39 [ 0 ] ,
V_37 , 3 * sizeof( T_7 ) ) ) {
return ( - V_44 ) ;
}
V_40 = * ( T_7 * ) & V_39 [ 0 ] ;
V_41 = * ( T_7 * ) & V_39 [ 4 ] ;
V_42 = * ( T_7 * ) & V_39 [ 8 ] ;
switch ( V_40 ) {
case V_45 :
if ( ( V_43 = F_13 ( V_41 , V_39 , sizeof( V_39 ) ) ) > 0 ) {
if ( ( V_38 < V_43 ) || F_14
( NULL , V_37 , ( void * ) & V_39 [ 0 ] , V_43 ) )
V_43 = - V_44 ;
} else {
V_43 = - V_46 ;
}
break;
case V_47 :
if ( ( V_43 = F_15 ( V_41 , ( T_6 * ) V_39 ) ) > 0 ) {
if ( ( V_38 < V_43 ) || F_14
( NULL , V_37 , ( void * ) & V_39 [ 0 ] , V_43 ) )
V_43 = - V_44 ;
} else {
V_43 = - V_48 ;
}
break;
case V_49 :
if ( ( V_43 = F_16 ( V_41 , V_42 ) ) <= 0 ) {
V_43 = - V_48 ;
}
break;
case V_50 :
if ( ! V_42 ) {
V_43 = F_17 ( 1 , L_3 ) ;
} else if ( V_42 < sizeof( V_39 ) ) {
if ( F_12 ( NULL , V_39 , ( char T_5 * ) V_37 + 12 , V_42 ) ) {
V_43 = - V_44 ;
} else {
V_43 = F_17 ( ( int ) V_42 , V_39 ) ;
}
} else {
V_43 = - V_46 ;
}
break;
case V_51 :
if ( ( V_43 = F_18 ( sizeof( V_39 ) , V_39 ) ) > 0 ) {
if ( F_14 ( NULL , V_37 , V_39 , V_43 ) )
V_43 = - V_44 ;
} else {
V_43 = - V_48 ;
}
break;
case V_52 : {
T_8 V_53 ;
T_9 V_54 ;
T_10 * V_55 ;
T_6 * V_56 ;
if ( ! ( V_56 = F_19 ( 0 , V_42 ) ) ) {
return ( - V_57 ) ;
}
for (; ; ) {
if ( ! ( V_55 =
F_20 ( & V_54 , & V_53 ) ) ) {
break;
}
if ( V_54 > V_42 ) {
F_21 ( 0 , & V_53 ) ;
V_43 = - V_46 ;
break;
}
V_43 = V_54 ;
memcpy ( V_56 , V_55 , V_54 ) ;
F_21 ( 1 , & V_53 ) ;
if ( ( V_38 < V_54 ) ||
F_14 ( NULL , V_37 , ( void * ) V_56 , V_54 ) )
V_43 = - V_44 ;
break;
}
F_22 ( 0 , V_56 ) ;
}
break;
case V_58 : {
T_8 V_53 ;
T_9 V_54 ;
T_10 * V_55 ;
T_6 * V_56 = NULL ;
int V_59 = 0 ;
if ( V_42 < 4096 ) {
V_43 = - V_46 ;
break;
}
if ( ! ( V_56 = F_19 ( 0 , V_42 ) ) ) {
return ( - V_57 ) ;
}
for (; ; ) {
if ( ! ( V_55 =
F_20 ( & V_54 , & V_53 ) ) ) {
break;
}
if ( ( V_54 + 8 ) > V_42 ) {
F_21 ( 0 , & V_53 ) ;
break;
}
V_56 [ V_59 ++ ] = ( T_6 ) V_54 ;
V_56 [ V_59 ++ ] = ( T_6 ) ( V_54 >> 8 ) ;
V_56 [ V_59 ++ ] = 0 ;
V_56 [ V_59 ++ ] = 0 ;
memcpy ( & V_56 [ V_59 ] , V_55 , V_54 ) ;
F_21 ( 1 , & V_53 ) ;
V_59 += V_54 ;
V_42 -= ( V_54 + 4 ) ;
}
V_56 [ V_59 ++ ] = 0 ;
V_56 [ V_59 ++ ] = 0 ;
V_56 [ V_59 ++ ] = 0 ;
V_56 [ V_59 ++ ] = 0 ;
if ( ( V_38 < V_59 ) || F_14 ( NULL , V_37 , ( void * ) V_56 , V_59 ) ) {
V_43 = - V_44 ;
} else {
V_43 = V_59 ;
}
F_22 ( 0 , V_56 ) ;
}
break;
default:
V_43 = - V_46 ;
}
return ( V_43 ) ;
}
int T_2 F_23 ( int * V_60 , void * * V_61 ,
unsigned long V_62 )
{
if ( * V_60 < 64 ) {
* V_60 = 64 ;
}
if ( * V_60 > 512 ) {
* V_60 = 512 ;
}
* V_60 *= 1024 ;
if ( V_62 ) {
* V_61 = ( void * ) V_62 ;
} else {
while ( ( * V_60 >= ( 64 * 1024 ) )
&&
( ! ( * V_61 = F_19 ( 0 , * V_60 ) ) ) ) {
* V_60 -= 1024 ;
}
if ( ! * V_61 ) {
F_3 ( ( L_4 ) ) ;
return ( 0 ) ;
}
}
if ( F_24 ( * V_61 , * V_60 , ( V_62 == 0 ) ) ) {
if ( ! V_62 ) {
F_22 ( 0 , * V_61 ) ;
}
F_3 ( ( L_5 ) ) ;
return ( 0 ) ;
}
if ( ! F_8 () ) {
F_3 ( ( L_6 ) ) ;
F_25 () ;
if ( ! V_62 ) {
F_22 ( 0 , * V_61 ) ;
}
return ( 0 ) ;
}
return ( 1 ) ;
}
void T_4 F_26 ( void )
{
void * V_61 ;
int V_63 = 100 ;
F_4 () ;
while ( F_27 () && V_63 -- ) {
F_28 ( 10 ) ;
}
F_10 () ;
if ( ( V_61 = F_25 () ) ) {
F_22 ( 0 , V_61 ) ;
}
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_8 = F_1 ;
}

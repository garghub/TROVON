static void F_1 ( unsigned char * V_1 , ... )
{
#ifdef F_2
T_1 V_2 ;
va_start ( V_2 , V_1 ) ;
F_3 ( ( V_1 , V_2 ) ) ;
va_end ( V_2 ) ;
#endif
}
void F_4 ( void ) {
memset ( & V_3 [ 0 ] , 0x00 , sizeof( V_3 ) ) ;
memset ( & V_4 [ 0 ] , 0x00 , sizeof( V_4 ) ) ;
F_5 ( & V_5 , L_1 ) ;
}
void F_6 ( void ) {
F_7 ( & V_5 , L_1 ) ;
}
static int F_8 ( T_2 * V_6 ) {
T_3 V_7 ;
int V_8 ;
if ( V_6 -> type == V_9 ) {
if ( V_6 -> V_10 ) {
V_11 . V_10 = V_6 -> V_10 ;
V_12 = ( V_13 ) V_6 -> V_10 ;
F_9 ( & V_11 , 0 ) ;
F_10 ((L_2, d->request))
} else {
F_10 ((L_3))
F_9 ( & V_11 , 1 ) ;
V_11 . V_10 = ( V_14 ) F_1 ;
V_12 = F_1 ;
}
return ( V_15 ) ;
}
for ( V_8 = 0 ; V_8 < V_15 ; V_8 ++ ) {
F_11 ( & V_5 , & V_7 , L_4 ) ;
if ( V_3 [ V_8 ] . type == 0 ) {
memcpy ( & V_3 [ V_8 ] , V_6 , sizeof( * V_6 ) ) ;
V_16 ++ ;
F_12 ( & V_5 , & V_7 , L_4 ) ;
F_9 ( V_6 , 0 ) ;
F_10 ((L_5, (i+1), d->request))
return ( V_8 + 1 ) ;
}
F_12 ( & V_5 , & V_7 , L_4 ) ;
}
F_13 ((L_6))
return ( - 1 ) ;
}
static int F_14 ( V_14 V_10 ) {
T_3 V_7 ;
int V_8 ;
if ( V_10 == V_11 . V_10 ) {
F_10 ((L_3))
V_12 = F_1 ;
F_9 ( & V_11 , 1 ) ;
V_11 . V_10 = ( V_14 ) F_1 ;
return ( 0 ) ;
}
for ( V_8 = 0 ; ( V_16 && ( V_8 < V_15 ) ) ; V_8 ++ ) {
if ( V_3 [ V_8 ] . V_10 == V_10 ) {
F_9 ( & V_3 [ V_8 ] , 1 ) ;
F_11 ( & V_5 , & V_7 , L_7 ) ;
memset ( & V_3 [ V_8 ] , 0x00 , sizeof( V_3 [ 0 ] ) ) ;
V_16 -- ;
F_12 ( & V_5 , & V_7 , L_7 ) ;
F_10 ((L_8, (i+1), request))
return ( 0 ) ;
}
}
F_13 ((L_9, request))
return ( - 1 ) ;
}
static int F_15 ( T_2 * V_17 , int V_18 ) {
T_3 V_7 ;
int V_19 , V_20 ;
memset ( V_17 , 0x00 , V_18 ) ;
V_18 /= sizeof( T_2 ) ;
F_10 ((L_10, length, Adapters+2))
F_11 ( & V_5 , & V_7 , L_11 ) ;
for ( V_19 = 0 , V_20 = 0 ;
( V_16 && ( V_19 < V_15 ) && ( V_20 < V_18 ) ) ;
V_19 ++ ) {
if ( V_3 [ V_19 ] . type ) {
memcpy ( & V_17 [ V_20 ] , & V_3 [ V_19 ] , sizeof( T_2 ) ) ;
V_20 ++ ;
}
}
F_12 ( & V_5 , & V_7 , L_11 ) ;
if ( V_20 < V_18 ) {
memcpy ( & V_17 [ V_20 ] , & V_11 , sizeof( T_2 ) ) ;
V_20 ++ ;
} else {
F_13 ((L_12))
}
if ( V_20 < V_18 ) {
memcpy ( & V_17 [ V_20 ] , & V_21 , sizeof( T_2 ) ) ;
V_20 ++ ;
} else {
F_13 ((L_13))
}
F_10 ((L_14, dst))
return ( V_20 == V_18 ) ;
}
static void T_4 F_16 (\
T_5 T_6 * V_22 ) {
T_7 * V_23 = ( T_7 * ) V_22 ;
if ( V_22 -> V_24 ) {
V_22 -> V_25 = V_26 ;
F_13 ((L_15, e->Req))
return;
}
switch ( V_22 -> V_25 ) {
case V_27 : {
T_8 * V_28 = & V_23 -> V_29 . V_30 ;
V_28 -> V_31 = F_17 (\
( V_32 ) V_28 -> V_33 ,
( void T_6 * ) V_28 -> V_34 ) ;
V_22 -> V_25 = 0xff ;
} break;
case V_35 : {
T_8 * V_28 = & V_23 -> V_29 . V_30 ;
F_18 ( V_28 -> V_31 ) ;
V_22 -> V_25 = 0xff ;
} break;
case V_36 : {
T_9 * V_28 = & V_23 -> V_37 . V_30 ;
if ( F_8 ( ( T_2 * ) V_28 -> V_38 ) < 0 ) {
V_22 -> V_25 = V_26 ;
} else {
V_22 -> V_25 = 0xff ;
}
} break;
case V_39 : {
T_10 * V_28 = & V_23 -> V_40 . V_30 ;
if ( F_14 ( ( V_14 ) V_28 -> V_41 ) < 0 ) {
V_22 -> V_25 = V_26 ;
} else {
V_22 -> V_25 = 0xff ;
}
} break;
case V_42 : {
T_11 * V_28 =\
& V_23 -> V_43 . V_30 ;
if ( F_15 ( ( T_2 * ) V_28 -> V_17 ,
( int ) V_28 -> V_18 ) ) {
V_22 -> V_25 = V_26 ;
} else {
V_22 -> V_25 = 0xff ;
}
} break;
default:
F_13 ((L_16, e->Rc))
V_22 -> V_25 = V_26 ;
}
}
static T_12 F_17 (\
V_32 V_33 ,
void T_6 * V_34 ) {
T_3 V_7 ;
T_12 V_8 ;
for ( V_8 = 0 ; V_8 < V_44 ; V_8 ++ ) {
F_11 ( & V_5 , & V_7 , L_17 ) ;
if ( ! V_4 [ V_8 ] . V_33 ) {
V_4 [ V_8 ] . V_33 = V_33 ;
V_4 [ V_8 ] . V_34 = V_34 ;
F_12 ( & V_5 , & V_7 , L_17 ) ;
F_10 ((L_18, i+1, callback))
return ( V_8 + 1 ) ;
}
F_12 ( & V_5 , & V_7 , L_17 ) ;
}
F_13 ((L_19))
return ( 0 ) ;
}
static void F_18 ( T_12 V_31 ) {
T_3 V_7 ;
if ( V_31 && ( ( -- V_31 ) < V_44 ) ) {
F_11 ( & V_5 , & V_7 , L_20 ) ;
V_4 [ V_31 ] . V_33 = NULL ;
V_4 [ V_31 ] . V_34 = NULL ;
F_12 ( & V_5 , & V_7 , L_20 ) ;
F_10 ((L_21, (int)(handle+1)))
return;
}
F_13 ((L_22, handle))
}
static void F_9 ( T_2 * V_6 , int V_45 ) {
int V_8 , V_46 ;
T_13 V_47 ;
T_3 V_7 ;
for ( V_8 = 0 ; V_8 < V_44 ; V_8 ++ ) {
V_46 = 0 ;
F_11 ( & V_5 , & V_7 , L_23 ) ;
if ( V_4 [ V_8 ] . V_33 ) {
memcpy ( & V_47 , & V_4 [ V_8 ] , sizeof( V_47 ) ) ;
V_46 = 1 ;
}
F_12 ( & V_5 , & V_7 , L_23 ) ;
if ( V_46 ) {
( * ( V_47 . V_33 ) ) ( V_47 . V_34 , V_6 , V_45 ) ;
}
}
}
void T_4 F_19 ( void T_6 * V_17 ,
int V_18 ) {
F_15 ( V_17 , V_18 ) ;
}

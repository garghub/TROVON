static int F_1 ( struct V_1 * V_2 , unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = V_7 . V_8 ;
unsigned long V_9 ;
for ( V_9 = 0 ; ( V_9 < V_10 [ 3 ] . V_11 ) ; V_9 += 0x100000 ) {
F_2 ( 0xff , 0x55 , V_9 , & V_7 , V_6 ,
V_6 -> V_12 , NULL ) ;
}
return ( V_13 ) ;
}
static int T_1 F_3 ( void )
{
volatile unsigned long * V_14 ;
unsigned long V_15 , V_16 ;
int V_17 = 0 ;
#ifdef F_4
volatile unsigned long * V_18 , * V_19 ;
unsigned long V_20 , V_21 ;
unsigned long V_22 , V_23 ;
unsigned long V_24 , V_25 ;
int V_26 , V_27 , V_28 ;
int V_29 ;
#endif
int V_30 = 0 ;
V_31 = ( void * ) F_5 ( 0xfffef000 , 4096 ) ;
if ( V_31 == NULL ) {
F_6 ( L_1 ) ;
return ( - V_32 ) ;
}
* ( ( unsigned char * ) ( V_31 + 0xc64 ) ) = 0x01 ;
V_14 = ( volatile unsigned long * ) ( V_31 + 0xc4 ) ;
#ifdef F_4
V_26 = 0 ;
V_27 = V_33 ;
V_18 = ( volatile unsigned long * ) ( V_31 + 0xc0 ) ;
V_28 = V_34 ;
V_19 = ( volatile unsigned long * ) ( V_31 + 0xbc ) ;
V_20 = * V_14 ;
V_21 = * V_18 ;
* V_18 = 0 ;
* V_19 = 0 ;
#endif
V_15 = 0x20000000 ;
V_16 = V_35 ;
* V_14 = F_7 ( V_36 , V_15 , V_16 ) ;
__asm__ ("wbinvd");
V_37 . V_38 = V_15 ;
V_37 . V_39 = F_5 ( V_15 , V_16 ) ;
if ( ! V_37 . V_39 ) {
F_6 ( L_2 ) ;
F_8 ( V_31 ) ;
return ( - V_32 ) ;
}
F_9 ( & V_37 ) ;
if ( ( V_40 = F_10 ( L_3 , & V_37 ) ) ) {
F_6 ( V_41 L_4 ,
( int ) ( V_40 -> V_11 >> 10 ) ) ;
V_40 -> V_42 = V_43 ;
V_17 = V_44 ;
if ( V_40 -> V_11 < V_35 )
V_17 -- ;
#ifdef F_4
V_16 = F_11 ( V_21 ) ;
if ( V_16 < ( 32 * 1024 * 1024 ) )
V_16 = ( 32 * 1024 * 1024 ) ;
V_22 = V_15 + V_16 ;
#endif
} else {
#ifdef F_4
V_26 ++ ;
if ( ! V_21 ) {
V_27 = V_36 ;
V_18 = ( volatile unsigned long * )
( V_31 + 0xc4 ) ;
V_28 = V_33 ;
V_19 = ( volatile unsigned long * )
( V_31 + 0xc0 ) ;
V_22 = F_12 ( V_20 ) ;
V_16 = F_11 ( V_20 ) ;
} else {
V_27 = V_33 ;
V_18 = ( volatile unsigned long * )
( V_31 + 0xc0 ) ;
V_28 = V_36 ;
V_19 = ( volatile unsigned long * )
( V_31 + 0xc4 ) ;
V_22 = F_12 ( V_21 ) ;
V_16 = F_11 ( V_21 ) ;
}
V_40 = NULL ;
F_8 ( V_37 . V_39 ) ;
V_37 . V_39 = NULL ;
#else
V_30 = - V_45 ;
goto V_46;
#endif
}
#ifdef F_4
if ( V_16 < ( 32 * 1024 * 1024 ) )
V_16 = ( 32 * 1024 * 1024 ) ;
* V_18 = F_7 ( V_27 , V_22 , V_16 ) ;
* V_19 = 0 ;
V_7 . V_11 = V_16 ;
V_7 . V_38 = V_22 ;
V_7 . V_39 = F_5 ( V_22 , V_16 ) ;
if ( ! V_7 . V_39 ) {
F_6 ( L_5 ) ;
V_30 = - V_32 ;
goto V_46;
}
F_9 ( & V_7 ) ;
V_47 = F_10 ( L_6 , & V_7 ) ;
if ( ! V_47 ) {
V_30 = - V_45 ;
goto V_48;
}
V_23 = V_47 -> V_11 ;
* V_18 = F_7 ( V_27 , V_22 , V_23 ) ;
V_24 = V_22 + V_23 ;
* V_19 = F_7 ( V_28 , V_24 , V_16 ) ;
__asm__ ("wbinvd");
V_16 += V_23 ;
F_13 ( V_47 ) ;
V_47 = NULL ;
F_8 ( V_7 . V_39 ) ;
V_7 . V_11 = V_16 ;
V_7 . V_39 = F_5 ( V_22 , V_16 ) ;
if ( ! V_7 . V_39 ) {
F_6 ( L_7 ) ;
V_30 = - V_32 ;
goto V_46;
}
V_47 = F_10 ( L_6 , & V_7 ) ;
if ( ! V_47 ) {
V_30 = - V_45 ;
goto V_48;
}
V_25 = V_47 -> V_11 - V_23 ;
if ( V_25 > 0 ) {
* V_19 = F_7 ( V_28 , V_24 , V_25 ) ;
__asm__ ("wbinvd");
} else {
* V_19 = 0 ;
}
F_6 ( V_41 L_8 ,
( unsigned long long ) ( V_47 -> V_11 >> 10 ) ) ;
V_47 -> V_42 = V_43 ;
V_29 = F_14 ( V_10 ) ;
if ( V_26 ) {
V_10 [ 1 ] . V_11 = ( V_23 + V_25 ) -
( 1024 * 1024 + V_47 -> V_49 ) ;
V_10 [ 3 ] . V_11 = V_23 + V_25 ;
V_10 [ 4 ] . V_50 =
( V_23 + V_25 ) - V_47 -> V_49 ;
V_10 [ 4 ] . V_11 = V_47 -> V_49 ;
V_10 [ 5 ] . V_50 =
V_10 [ 4 ] . V_50 ;
V_10 [ 5 ] . V_11 =
V_10 [ 4 ] . V_11 ;
} else {
V_29 -= 2 ;
}
V_30 = F_15 ( V_47 , V_10 ,
V_29 ) ;
if ( V_30 )
goto V_51;
#endif
if ( V_40 ) {
V_30 = F_15 ( V_40 , V_52 ,
V_17 ) ;
if ( V_30 )
goto V_53;
}
#ifdef F_4
F_16 ( & V_54 ) ;
#endif
return V_30 ;
V_53:
#ifdef F_4
F_17 ( V_47 ) ;
V_51:
F_13 ( V_47 ) ;
V_48:
F_8 ( V_7 . V_39 ) ;
#endif
V_46:
F_8 ( V_31 ) ;
F_8 ( V_37 . V_39 ) ;
return V_30 ;
}
static void T_2 F_18 ( void )
{
#ifdef F_4
F_19 ( & V_54 ) ;
#endif
if ( V_40 ) {
F_17 ( V_40 ) ;
F_13 ( V_40 ) ;
}
if ( V_31 ) {
F_8 ( V_31 ) ;
V_31 = NULL ;
}
if ( V_37 . V_39 ) {
F_8 ( V_37 . V_39 ) ;
V_37 . V_39 = NULL ;
}
#ifdef F_4
if ( V_47 ) {
F_17 ( V_47 ) ;
F_13 ( V_47 ) ;
}
if ( V_7 . V_39 ) {
F_8 ( V_7 . V_39 ) ;
V_7 . V_39 = NULL ;
}
#endif
}

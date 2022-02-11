static void T_1 F_1 ( char * V_1 , int V_2 )
{
extern unsigned long V_3 ;
unsigned long * V_4 ;
unsigned long V_5 ;
unsigned long V_6 , V_7 ;
unsigned long V_8 , V_9 ;
V_4 = ( unsigned long * ) V_3 ;
V_5 = V_4 [ 1 ] ;
V_6 = V_4 [ 2 ] ;
V_7 = V_4 [ 3 ] ;
V_8 = V_4 [ 4 ] ;
V_9 = V_4 [ 5 ] ;
if ( V_8 && V_9 )
strncpy ( V_1 , ( const char * ) V_8 , V_2 ) ;
#if F_2 ( V_10 )
if ( V_6 && V_7 &&
( V_7 > V_6 ) ) {
V_11 = V_6 ;
V_12 = V_7 ;
V_13 = V_14 ;
F_3 ( V_15 L_1 ,
V_11 , V_12 ) ;
}
#endif
}
void T_1 F_4 ( char * * V_16 )
{
int V_17 ;
V_18 = F_5 ( V_19 ) ;
V_20 = V_21 ;
V_22 . V_23 = ( unsigned long ) & V_24 ;
V_22 . V_25 = ( unsigned long ) & V_26 ;
V_22 . V_27 = ( unsigned long ) & V_28 ;
V_22 . V_29 = ( unsigned long ) 0 ;
F_6 ( & V_30 [ 0 ] , sizeof( V_30 ) ) ;
#if F_2 ( V_31 )
strncpy ( & V_30 [ 0 ] , V_32 , sizeof( V_30 ) ) ;
V_30 [ sizeof( V_30 ) - 1 ] = 0 ;
#endif
#if F_2 ( V_33 )
#if F_2 ( V_31 )
V_30 [ strlen ( V_32 ) ] = ' ' ;
F_1 (
& V_30 [ ( strlen ( V_32 ) + 1 ) ] ,
( sizeof( V_30 ) -
( strlen ( V_32 ) + 1 ) ) ) ;
#else
F_1 ( & V_30 [ 0 ] , sizeof( V_30 ) ) ;
#endif
V_30 [ sizeof( V_30 ) - 1 ] = 0 ;
#endif
F_3 ( V_15 L_2 V_34 L_3 ) ;
#ifdef F_7
F_3 ( V_15 L_4 ) ;
#endif
#ifdef F_8
F_3 ( V_15 L_5 ) ;
#endif
#ifdef F_9
F_3 ( V_15 L_6 ) ;
#ifdef F_10
F_3 ( V_15 L_7 ) ;
#endif
#ifdef F_11
F_3 ( V_15 L_8 ) ;
#endif
#endif
F_3 ( V_15 L_9 ) ;
#if F_2 ( V_35 ) && F_2 ( V_36 )
F_3 ( V_15 L_10 ) ;
#endif
#if F_2 ( V_35 ) && F_2 ( V_37 )
F_3 ( V_15 L_11 ) ;
#endif
#ifdef F_12
F_3 ( V_15 L_12 ) ;
#endif
#ifdef F_13
F_3 ( V_15 L_13 ) ;
#endif
F_14 ( L_14 ,
V_24 , V_26 , V_38 , V_28 , V_39 , V_40 ) ;
F_14 ( L_15 ,
V_40 , V_18 , V_18 , V_20 ) ;
* V_16 = & V_30 [ 0 ] ;
memcpy ( V_41 , V_30 , V_42 ) ;
V_41 [ V_42 - 1 ] = 0 ;
#if F_2 ( V_43 ) && F_2 ( V_44 )
V_45 = & V_46 ;
#endif
V_47 = F_15 ( V_18 ) ;
V_48 = V_49 = F_15 ( V_20 ) ;
V_17 = F_16 (
F_17 ( 0 ) ,
V_47 ,
F_15 ( V_50 ) ,
V_48 ) ;
F_18 ( V_18 , V_20 - V_18 ) ;
F_19 ( V_18 , V_17 , V_51 ) ;
#if F_2 ( V_33 ) && F_2 ( V_10 )
if ( ( V_11 > 0 ) && ( V_11 < V_12 ) &&
( V_12 < V_20 ) )
F_19 ( V_11 , V_12 - V_11 ,
V_51 ) ;
#endif
F_20 () ;
}
static int F_21 ( struct V_52 * V_53 , void * V_54 )
{
char * V_55 , * V_56 , * V_57 ;
T_2 V_58 ;
V_55 = V_34 ;
V_56 = L_16 ;
V_57 = L_16 ;
V_58 = ( V_59 * V_60 ) * V_61 ;
F_22 ( V_53 , L_17
L_18
L_19
L_20
L_21
L_22 ,
V_55 , V_56 , V_57 ,
V_58 / 1000000 ,
( V_58 / 100000 ) % 10 ,
( V_59 * V_60 ) / 500000 ,
( ( V_59 * V_60 ) / 5000 ) % 100 ,
( V_59 * V_60 ) ) ;
return 0 ;
}
static void * F_23 ( struct V_52 * V_53 , T_3 * V_62 )
{
return * V_62 < V_63 ? ( ( void * ) 0x12345678 ) : NULL ;
}
static void * F_24 ( struct V_52 * V_53 , void * V_54 , T_3 * V_62 )
{
++ * V_62 ;
return F_23 ( V_53 , V_62 ) ;
}
static void F_25 ( struct V_52 * V_53 , void * V_54 )
{
}

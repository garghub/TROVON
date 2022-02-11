void T_1 F_1 ( char * * V_1 )
{
int V_2 ;
V_3 = F_2 ( V_4 ) ;
V_5 = V_6 ;
V_7 . V_8 = ( unsigned long ) & V_9 ;
V_7 . V_10 = ( unsigned long ) & V_11 ;
V_7 . V_12 = ( unsigned long ) & V_13 ;
V_7 . V_14 = ( unsigned long ) 0 ;
F_3 ( & V_15 [ 0 ] , sizeof( V_15 ) ) ;
#if F_4 ( V_16 )
strncpy ( & V_15 [ 0 ] , V_17 , sizeof( V_15 ) ) ;
V_15 [ sizeof( V_15 ) - 1 ] = 0 ;
#endif
F_5 ( & V_15 [ 0 ] , sizeof( V_15 ) ) ;
F_6 ( L_1 V_18 L_2 ) ;
#ifdef F_7
F_6 ( L_3 ) ;
#endif
#ifdef F_8
F_6 ( L_4 ) ;
#endif
#ifdef F_9
F_6 ( L_5 ) ;
#ifdef F_10
F_6 ( L_6 ) ;
#endif
#ifdef F_11
F_6 ( L_7 ) ;
#endif
#endif
F_6 ( L_8 ) ;
#if F_4 ( V_19 ) && F_4 ( V_20 )
F_6 ( L_9 ) ;
#endif
#if F_4 ( V_19 ) && F_4 ( V_21 )
F_6 ( L_10 ) ;
#endif
#ifdef F_12
F_6 ( L_11 ) ;
#endif
#ifdef F_13
F_6 ( L_12 ) ;
#endif
F_14 ( L_13 ,
V_9 , V_11 , V_22 , V_13 , V_23 , V_24 ) ;
F_14 ( L_14 ,
V_24 , V_3 , V_3 , V_5 ) ;
* V_1 = & V_15 [ 0 ] ;
memcpy ( V_25 , V_15 , V_26 ) ;
V_25 [ V_26 - 1 ] = 0 ;
#if F_4 ( V_27 ) && F_4 ( V_28 )
V_29 = & V_30 ;
#endif
V_31 = F_15 ( V_3 ) ;
V_32 = V_33 = F_15 ( V_5 ) ;
V_2 = F_16 (
F_17 ( 0 ) ,
V_31 ,
F_15 ( V_34 ) ,
V_32 ) ;
F_18 ( V_3 , V_5 - V_3 ) ;
F_19 ( V_3 , V_2 , V_35 ) ;
#if F_4 ( V_36 ) && F_4 ( V_37 )
if ( ( V_38 > 0 ) && ( V_38 < V_39 ) &&
( V_39 < V_5 ) )
F_19 ( V_38 , V_39 - V_38 ,
V_35 ) ;
#endif
F_20 () ;
}
static int F_21 ( struct V_40 * V_41 , void * V_42 )
{
char * V_43 , * V_44 , * V_45 ;
T_2 V_46 ;
V_43 = V_18 ;
V_44 = L_15 ;
V_45 = L_15 ;
V_46 = ( V_47 * V_48 ) * V_49 ;
F_22 ( V_41 , L_16
L_17
L_18
L_19
L_20
L_21 ,
V_43 , V_44 , V_45 ,
V_46 / 1000000 ,
( V_46 / 100000 ) % 10 ,
( V_47 * V_48 ) / 500000 ,
( ( V_47 * V_48 ) / 5000 ) % 100 ,
( V_47 * V_48 ) ) ;
return 0 ;
}
static void * F_23 ( struct V_40 * V_41 , T_3 * V_50 )
{
return * V_50 < V_51 ? ( ( void * ) 0x12345678 ) : NULL ;
}
static void * F_24 ( struct V_40 * V_41 , void * V_42 , T_3 * V_50 )
{
++ * V_50 ;
return F_23 ( V_41 , V_50 ) ;
}
static void F_25 ( struct V_40 * V_41 , void * V_42 )
{
}

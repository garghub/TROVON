static int T_1 F_1 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = V_1 -> V_3 . V_4 . V_5 ;
if ( V_2 < F_2 ( V_6 ) )
memcpy ( V_6 [ V_2 ] . V_7 , V_1 -> V_3 . V_4 . V_8 ,
sizeof( V_6 [ V_2 ] . V_7 ) ) ;
return 0 ;
}
static void T_1 F_3 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 , V_13 , 0 ) ;
const T_2 * V_7 ;
void T_3 * V_14 ;
struct V_15 * V_16 ;
if ( ! V_12 )
return;
if ( V_10 -> V_17 >= F_2 ( V_6 ) )
return;
V_7 = V_6 [ V_10 -> V_17 ] . V_7 ;
if ( ! F_5 ( V_7 ) )
return;
V_14 = ( void T_3 V_18 * ) V_12 -> V_19 ;
V_16 = F_6 ( & V_10 -> V_20 , L_1 ) ;
if ( F_7 ( V_16 ) )
return;
F_8 ( V_16 ) ;
F_9 ( ( V_7 [ 3 ] << 24 ) | ( V_7 [ 2 ] << 16 )
| ( V_7 [ 1 ] << 8 ) | V_7 [ 0 ] , V_14 + 0x98 ) ;
F_9 ( ( V_7 [ 5 ] << 8 ) | V_7 [ 4 ] , V_14 + 0x9c ) ;
F_10 ( V_16 ) ;
F_11 ( V_16 ) ;
}
static void T_1 F_12 ( void )
{
struct V_15 * V_21 ;
struct V_15 * V_22 ;
V_21 = F_6 ( NULL , L_2 ) ;
if ( F_7 ( V_21 ) )
goto V_23;
V_22 = F_6 ( NULL , L_3 ) ;
if ( F_7 ( V_22 ) )
goto V_24;
if ( F_13 ( V_21 , V_22 ) ) {
F_14 ( L_4 ) ;
goto V_25;
}
F_15 ( V_26 , ( 1 << 30 ) , V_27 , 0 ) ;
V_28 . V_29 = V_21 ;
V_25:
F_11 ( V_22 ) ;
V_24:
F_11 ( V_21 ) ;
V_23:
return;
}
static void T_1 F_12 ( void )
{
}
void T_1 F_16 ( void )
{
#ifdef F_17
F_18 ( 0 , 1 , 0 ) ;
#else
F_18 ( 1 , 0 , 0 ) ;
#endif
F_18 ( 3 , 2 , 0 ) ;
F_19 ( 0 ) ;
}
static int T_1 F_20 ( void )
{
F_21 ( V_30 , V_31 ) ;
#ifdef F_22
F_23 ( & V_32 , & V_33 ) ;
F_24 ( 3 , & V_32 ) ;
F_25 ( 0 , & V_34 ) ;
#endif
#ifdef F_17
F_26 ( 1 ) ;
#else
F_26 ( 0 ) ;
#endif
F_26 ( 2 ) ;
#ifndef F_27
F_3 ( F_28 ( 0 , & V_35 [ 0 ] ) ) ;
#endif
#ifndef F_29
F_30 ( 0 , V_36 , F_2 ( V_36 ) ) ;
#endif
#ifdef F_31
F_30 ( 1 , V_37 , F_2 ( V_37 ) ) ;
#endif
#ifndef F_17
F_32 ( 0 , & V_38 ) ;
#endif
#ifdef F_33
F_3 ( F_28 ( 1 , & V_35 [ 1 ] ) ) ;
#else
F_34 ( 0 , & V_39 ,
V_40 , V_41 ,
V_42 | V_43 ) ;
#endif
F_35 ( 0 , NULL ) ;
#ifndef F_36
F_37 ( 0 , V_44 ) ;
#endif
F_38 () ;
F_12 () ;
return 0 ;
}

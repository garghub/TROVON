static struct V_1 * F_1 ( int V_2 , int * V_3 )
{
* V_3 = F_2 ( V_4 ) ;
return V_4 ;
}
static int T_1 F_3 ( struct V_5 * V_5 )
{
int V_6 ;
V_6 = V_5 -> V_7 . V_8 . V_9 ;
if ( V_6 < F_2 ( V_10 ) )
memcpy ( V_10 [ V_6 ] . V_11 , V_5 -> V_7 . V_8 . V_12 ,
sizeof( V_10 [ V_6 ] . V_11 ) ) ;
return 0 ;
}
static void T_1 F_4 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_5 ( V_14 , V_17 , 0 ) ;
const T_2 * V_11 ;
void T_3 * V_18 ;
struct V_19 * V_20 ;
if ( ! V_16 )
return;
if ( V_14 -> V_21 >= F_2 ( V_10 ) )
return;
V_11 = V_10 [ V_14 -> V_21 ] . V_11 ;
if ( ! F_6 ( V_11 ) )
return;
V_18 = ( void T_3 V_22 * ) V_16 -> V_23 ;
V_20 = F_7 ( & V_14 -> V_24 , L_1 ) ;
if ( F_8 ( V_20 ) )
return;
F_9 ( V_20 ) ;
F_10 ( ( V_11 [ 3 ] << 24 ) | ( V_11 [ 2 ] << 16 )
| ( V_11 [ 1 ] << 8 ) | V_11 [ 0 ] , V_18 + 0x98 ) ;
F_10 ( ( V_11 [ 5 ] << 8 ) | V_11 [ 4 ] , V_18 + 0x9c ) ;
F_11 ( V_20 ) ;
F_12 ( V_20 ) ;
}
static void T_1 F_13 ( void )
{
struct V_19 * V_25 ;
struct V_19 * V_26 ;
V_25 = F_7 ( NULL , L_2 ) ;
if ( F_8 ( V_25 ) )
goto V_27;
V_26 = F_7 ( NULL , L_3 ) ;
if ( F_8 ( V_26 ) )
goto V_28;
if ( F_14 ( V_25 , V_26 ) ) {
F_15 ( L_4 ) ;
goto V_29;
}
F_16 ( V_30 , ( 1 << 30 ) , V_31 , 0 ) ;
V_32 . V_33 = V_25 ;
V_29:
F_12 ( V_26 ) ;
V_28:
F_12 ( V_25 ) ;
V_27:
return;
}
static void T_1 F_13 ( void )
{
}
void T_1 F_17 ( void )
{
#ifdef F_18
F_19 ( 0 , 1 , 0 ) ;
#else
F_19 ( 1 , 0 , 0 ) ;
#endif
F_19 ( 3 , 2 , 0 ) ;
F_20 ( 0 ) ;
}
static int T_1 F_21 ( void )
{
F_22 ( V_34 , V_35 ) ;
#ifdef F_23
F_24 ( & V_36 , & V_37 ) ;
F_25 ( 3 , & V_36 ) ;
F_26 ( 0 , & V_38 ) ;
#endif
#ifdef F_18
F_27 ( 1 ) ;
#else
F_27 ( 0 ) ;
#endif
F_27 ( 2 ) ;
#ifndef F_28
F_4 ( F_29 ( 0 , & V_39 [ 0 ] ) ) ;
#endif
#ifndef F_30
F_31 ( 0 , V_40 , F_2 ( V_40 ) ) ;
#endif
#ifdef F_32
F_31 ( 1 , V_41 , F_2 ( V_41 ) ) ;
#endif
#ifndef F_18
F_33 ( 0 , & V_42 ) ;
#endif
#ifdef F_34
F_4 ( F_29 ( 1 , & V_39 [ 1 ] ) ) ;
#else
F_35 ( 0 , & V_43 ,
V_44 , V_45 ,
V_46 | V_47 ) ;
#endif
F_36 ( 0 , NULL ) ;
#ifndef F_37
F_38 ( 0 , V_48 ) ;
#endif
F_39 () ;
F_13 () ;
return 0 ;
}

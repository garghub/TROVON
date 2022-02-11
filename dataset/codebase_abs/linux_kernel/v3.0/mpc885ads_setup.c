static void F_1 ( int V_1 , int V_2 )
{
if ( V_2 )
F_2 ( & V_3 [ 1 ] , V_4 ) ;
else
F_3 ( & V_3 [ 1 ] , V_4 ) ;
}
static int F_4 ( int V_1 , int V_5 , int V_6 )
{
T_1 V_7 = 0 ;
switch ( V_5 ) {
case 0 :
break;
case 33 :
V_7 |= V_8 ;
break;
case 50 :
V_7 |= V_9 ;
break;
default:
return 1 ;
}
switch ( V_6 ) {
case 0 :
break;
case 33 :
case 50 :
if ( V_5 == V_6 )
V_7 |= V_10 ;
else
return 1 ;
break;
case 120 :
if ( ( V_5 == 33 ) || ( V_5 == 50 ) )
V_7 |= V_11 ;
else
return 1 ;
default:
return 1 ;
}
F_2 ( & V_3 [ 1 ] , 0x00610000 ) ;
F_3 ( & V_3 [ 1 ] , V_7 ) ;
return 0 ;
}
static void T_2 F_5 ( void )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < F_6 ( V_13 ) ; V_12 ++ ) {
struct V_14 * V_15 = & V_13 [ V_12 ] ;
F_7 ( V_15 -> V_16 , V_15 -> V_15 , V_15 -> V_17 ) ;
}
F_8 ( V_18 , V_19 , V_20 ) ;
F_8 ( V_21 , V_22 , V_20 ) ;
F_8 ( V_23 , V_24 , V_25 ) ;
F_8 ( V_23 , V_26 , V_27 ) ;
F_2 ( & V_28 -> V_29 . V_30 , 0x00000180 ) ;
}
static void T_2 F_9 ( void )
{
struct V_31 * V_32 ;
F_10 () ;
F_5 () ;
V_32 = F_11 ( NULL , NULL , L_1 ) ;
if ( ! V_32 ) {
F_12 ( V_33 L_2 ) ;
return;
}
V_3 = F_13 ( V_32 , 0 ) ;
V_34 = F_13 ( V_32 , 1 ) ;
F_14 ( V_32 ) ;
if ( ! V_3 || ! V_34 ) {
F_12 ( V_33 L_3 ) ;
return;
}
F_2 ( & V_3 [ 1 ] , V_35 ) ;
#ifdef F_15
F_3 ( & V_3 [ 1 ] , V_36 ) ;
#else
F_2 ( & V_3 [ 1 ] , V_36 ) ;
#endif
F_2 ( V_34 , V_37 ) ;
F_3 ( V_34 , V_38 ) ;
F_16 ( 1000 ) ;
F_2 ( V_34 , V_38 ) ;
#ifdef F_15
F_2 ( V_34 , V_39 ) ;
F_3 ( V_34 , V_40 ) ;
F_16 ( 1000 ) ;
F_2 ( V_34 , V_40 ) ;
#else
F_3 ( V_34 , V_39 ) ;
#endif
#ifdef F_17
F_2 ( & V_3 [ 4 ] , V_41 ) ;
F_16 ( 1000 ) ;
F_3 ( & V_3 [ 4 ] , V_41 ) ;
F_3 ( & V_3 [ 1 ] , V_42 ) ;
V_32 = F_18 ( L_4 ) ;
#else
V_32 = F_18 ( L_5 ) ;
#endif
if ( V_32 ) {
F_19 ( V_32 ) ;
F_14 ( V_32 ) ;
}
#ifdef F_20
V_43 . V_44 = F_1 ;
V_43 . V_45 = F_4 ;
#endif
}
static int T_2 F_21 ( void )
{
unsigned long V_46 = F_22 () ;
return F_23 ( V_46 , L_6 ) ;
}
static int T_2 F_24 ( void )
{
F_25 ( NULL , V_47 , NULL ) ;
return 0 ;
}

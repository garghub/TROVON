static T_1 F_1 ( void )
{
return V_1 ;
}
static void T_2 F_2 ( void )
{
int V_2 ;
T_3 V_3 = 0 ;
F_3 ( 171 , V_4 ) ;
F_3 ( 172 , V_4 ) ;
F_3 ( 173 , V_4 ) ;
V_2 = F_4 ( V_5 ,
F_5 ( V_5 ) ) ;
if ( V_2 < 0 ) {
F_6 ( V_6 L_1 ) ;
V_1 = V_7 ;
return;
}
V_3 = F_7 ( 171 ) | ( F_7 ( 172 ) << 1 )
| ( F_7 ( 173 ) << 2 ) ;
F_8 ( V_5 ,
F_5 ( V_5 ) ) ;
switch ( V_3 ) {
case 7 :
F_6 ( V_8 L_2 ) ;
V_1 = V_9 ;
break;
case 6 :
F_6 ( V_8 L_3 ) ;
V_1 = V_10 ;
break;
case 5 :
F_6 ( V_8 L_4 ) ;
V_1 = V_11 ;
break;
case 0 :
F_6 ( V_8 L_5 ) ;
V_1 = V_12 ;
break;
default:
F_6 ( V_8 L_6 , V_3 ) ;
V_1 = V_7 ;
}
}
static int F_9 ( struct V_13 * V_14 )
{
if ( F_10 ( V_14 -> V_15 ) )
F_11 ( V_14 -> V_15 , 1 ) ;
return 0 ;
}
static void F_12 ( struct V_13 * V_14 )
{
if ( F_10 ( V_14 -> V_15 ) )
F_11 ( V_14 -> V_15 , 0 ) ;
}
static void T_2 F_13 ( void )
{
int V_16 ;
V_16 = F_14 ( V_17 . V_15 , V_18 ,
L_7 ) ;
if ( V_16 < 0 )
F_6 ( V_6 L_8 ) ;
}
static int F_15 ( struct V_19 * V_20 ,
unsigned V_21 , unsigned V_22 )
{
int V_16 , V_23 ;
if ( F_1 () == V_12 ) {
V_24 [ 0 ] . V_25 = - V_26 ;
} else if ( ( F_1 () == V_10 ) ||
( F_1 () == V_11 ) ) {
F_3 ( 23 , V_27 ) ;
V_24 [ 0 ] . V_25 = 23 ;
} else {
F_3 ( 29 , V_27 ) ;
}
V_24 [ 0 ] . V_28 = V_21 + 0 ;
F_16 ( V_24 ) ;
V_29 . V_20 = V_24 [ 0 ] . V_20 ;
V_30 . V_20 = V_24 [ 0 ] . V_20 ;
if ( F_1 () == V_12 ) {
V_23 = V_31 ;
V_17 . V_15 = 129 ;
V_16 = F_14 ( V_21 + 1 , V_18 ,
L_9 ) ;
if ( V_16 )
F_17 ( L_10 ,
V_32 ) ;
V_16 = F_14 ( V_21 + 2 , V_31 ,
L_11 ) ;
if ( V_16 )
F_17 ( L_12 ,
V_32 ) ;
} else {
V_23 = V_18 ;
V_17 . V_15 = 170 ;
if ( F_14 ( V_21 + 1 , V_33 , L_13 ) )
F_17 ( L_14 , V_32 ) ;
}
F_14 ( V_21 + V_34 , V_23 , L_15 ) ;
V_35 [ 2 ] . V_21 = V_21 + V_34 + 1 ;
return 0 ;
}
static int T_2 F_18 ( void )
{
F_19 ( L_16 , & V_36 ) ;
F_20 ( 3 , 100 , V_37 , F_5 ( V_37 ) ) ;
return 0 ;
}
static void T_2 F_21 ( void )
{
F_22 () ;
F_23 ( V_38 ,
V_38 ) ;
}
static void T_2 F_24 ( void )
{
F_25 () ;
#ifdef F_26
F_27 ( 12 ) ;
#endif
}
static void T_2 F_28 ( void )
{
int V_16 = 0 ;
if ( F_29 () ) {
F_17 ( L_17 , V_32 ) ;
return;
}
if ( F_1 () == V_12 ) {
struct V_39 * V_40 = F_30 ( L_18 ) ;
struct V_39 * V_41 = F_30 ( L_19 ) ;
struct V_19 * V_20 ;
if ( ! V_40 || ! V_41 ) {
F_17 ( L_20 ,
V_32 , V_40 , V_41 ) ;
return;
}
V_20 = & V_40 -> V_42 -> V_43 . V_20 ;
V_16 = F_31 ( V_20 , 800000000 ) ;
V_20 = & V_41 -> V_42 -> V_43 . V_20 ;
V_16 |= F_31 ( V_20 , 660000000 ) ;
if ( V_16 ) {
F_17 ( L_21 ,
V_32 , V_16 ) ;
V_20 = & V_40 -> V_42 -> V_43 . V_20 ;
F_32 ( V_20 , 800000000 ) ;
V_20 = & V_41 -> V_42 -> V_43 . V_20 ;
F_32 ( V_20 , 660000000 ) ;
}
}
return;
}
static void T_2 F_33 ( void )
{
F_34 ( V_44 , V_45 ) ;
F_2 () ;
F_18 () ;
F_35 ( V_46 ,
F_5 ( V_46 ) ) ;
F_36 ( & V_47 ) ;
F_37 () ;
F_3 ( 170 , V_27 ) ;
F_14 ( 170 , V_31 , L_22 ) ;
F_38 ( NULL ) ;
F_39 ( & V_48 ) ;
F_40 ( V_49 , V_50 ,
F_5 ( V_50 ) ) ;
F_41 ( L_23 , V_51 ) ;
F_41 ( L_24 , V_52 ) ;
F_41 ( L_25 , V_52 ) ;
F_13 () ;
F_28 () ;
}

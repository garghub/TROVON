static void T_1 F_1 ( void )
{
int V_1 ;
T_2 V_2 = 0 ;
F_2 ( 171 , V_3 ) ;
F_2 ( 172 , V_3 ) ;
F_2 ( 173 , V_3 ) ;
V_1 = F_3 ( V_4 ,
F_4 ( V_4 ) ) ;
if ( V_1 < 0 ) {
F_5 ( V_5 L_1 ) ;
V_6 = V_7 ;
return;
}
V_2 = F_6 ( 171 ) | ( F_6 ( 172 ) << 1 )
| ( F_6 ( 173 ) << 2 ) ;
F_7 ( V_4 ,
F_4 ( V_4 ) ) ;
switch ( V_2 ) {
case 7 :
F_5 ( V_8 L_2 ) ;
V_6 = V_9 ;
V_10 . V_11 = 29 ;
V_10 . V_12 = 170 ;
V_10 . V_13 = 7 ;
break;
case 6 :
F_5 ( V_8 L_3 ) ;
V_6 = V_14 ;
V_10 . V_11 = 23 ;
V_10 . V_12 = 170 ;
V_10 . V_13 = 7 ;
break;
case 5 :
F_5 ( V_8 L_4 ) ;
V_6 = V_15 ;
V_10 . V_11 = 23 ;
V_10 . V_12 = 170 ;
V_10 . V_13 = 7 ;
break;
case 0 :
F_5 ( V_8 L_5 ) ;
V_6 = V_16 ;
V_10 . V_17 = 1 ;
V_10 . V_18 &= ~ V_19 ;
break;
case 2 :
F_5 ( V_8 L_6 ) ;
V_6 = V_20 ;
V_10 . V_18 &= ~ V_19 ;
break;
default:
F_5 ( V_8 L_7 , V_2 ) ;
V_6 = V_7 ;
}
}
static int F_8 ( struct V_21 * V_22 ,
unsigned V_23 , unsigned V_24 )
{
int V_25 ;
V_26 [ 0 ] . V_27 = V_10 . V_11 ;
V_26 [ 0 ] . V_28 = V_23 + 0 ;
F_9 ( V_26 ) ;
if ( F_10 () ) {
V_25 = F_11 ( V_23 + 1 , V_29 ,
L_8 ) ;
if ( V_25 )
F_12 ( L_9 ,
V_30 ) ;
V_10 . V_12 = V_23 + 2 ;
} else {
if ( F_11 ( V_23 + 1 , V_31 , L_10 ) )
F_12 ( L_11 , V_30 ) ;
}
V_32 . V_33 = V_10 . V_12 ;
F_13 ( & V_34 ) ;
F_13 ( & V_35 ) ;
F_13 ( & V_36 ) ;
V_37 [ 0 ] . V_38 = V_23 + V_39 ;
V_37 [ 0 ] . V_40 = V_10 . V_17 ;
F_14 ( V_37 , F_4 ( V_37 ) ) ;
return 0 ;
}
static int T_1 F_15 ( void )
{
F_16 ( & V_41 ,
V_42 | V_43 |
V_44 ,
V_45 | V_46 ) ;
V_41 . V_47 -> V_48 . V_49 = L_12 ;
F_17 ( L_13 , & V_41 ) ;
F_18 ( 3 , 100 , V_50 , F_4 ( V_50 ) ) ;
return 0 ;
}
static int T_1 F_19 ( void )
{
int V_25 = 0 ;
if ( ! F_20 () )
return 0 ;
V_25 = F_21 () ;
if ( V_25 < 0 && ( V_25 != - V_51 ) ) {
F_12 ( L_14 , V_30 ) ;
return V_25 ;
}
if ( F_10 () ) {
struct V_21 * V_52 , * V_53 ;
V_52 = F_22 ( 0 ) ;
V_53 = F_23 ( L_15 ) ;
if ( ! V_52 || F_24 ( V_53 ) ) {
F_12 ( L_16 ,
V_30 , V_52 , V_53 ) ;
return - V_54 ;
}
V_25 = F_25 ( V_52 , 800000000 ) ;
V_25 |= F_25 ( V_53 , 660000000 ) ;
if ( V_25 ) {
F_12 ( L_17 ,
V_30 , V_25 ) ;
F_26 ( V_52 , 800000000 ) ;
F_26 ( V_53 , 660000000 ) ;
}
}
return 0 ;
}
static void T_1 F_27 ( void )
{
F_28 ( V_55 , V_56 ) ;
F_1 () ;
if ( F_29 ( V_10 . V_11 ) )
F_2 ( V_10 . V_11 , V_57 ) ;
V_26 [ 0 ] . V_58 = V_10 . V_18 ;
F_30 ( V_26 ) ;
F_15 () ;
V_59 [ 0 ] . V_23 = V_10 . V_13 ;
F_31 ( V_60 ,
F_4 ( V_60 ) ) ;
if ( F_29 ( V_10 . V_12 ) )
F_2 ( V_10 . V_12 , V_61 ) ;
F_32 ( & V_62 ) ;
F_33 () ;
F_34 ( V_63 ,
V_63 ) ;
F_35 ( L_18 , 0 , L_19 ) ;
F_36 ( NULL ) ;
F_37 ( & V_64 ) ;
F_38 ( V_65 ,
F_4 ( V_65 ) , V_66 ,
V_67 , NULL ) ;
F_39 ( L_20 , NULL ) ;
F_40 ( L_21 , V_68 ) ;
F_40 ( L_22 , V_61 ) ;
F_40 ( L_23 , V_61 ) ;
F_41 ( V_69 , F_4 ( V_69 ) ) ;
}

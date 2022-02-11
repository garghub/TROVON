void F_1 ( void )
{
if ( V_1 && V_2 ) {
F_2 ( F_3 ( V_1 ) , V_1 ) ;
F_2 ( F_3 ( V_2 ) , V_2 ) ;
F_4 () ;
}
}
int T_1 F_5 ( void )
{
V_3 = F_6 ( V_4 , V_5 ) ;
V_6 = F_7 ( V_3 , V_5 ) ;
return 0 ;
}
void T_1 F_8 ( void )
{
struct V_7 V_8 [ 1 ] ;
V_8 [ 0 ] . V_9 = V_10 ;
V_8 [ 0 ] . V_11 = F_9 ( V_6 ) ;
V_8 [ 0 ] . V_12 = V_3 ;
V_8 [ 0 ] . type = V_13 ;
F_10 ( V_8 , F_11 ( V_8 ) ) ;
V_1 = ( void V_14 * ) V_8 [ 0 ] . V_9 ;
V_2 = ( void V_14 * ) V_15 ;
F_12 ( L_1 ,
( long long ) V_6 , V_8 [ 0 ] . V_9 ) ;
}
void T_1 F_8 ( void )
{}
void F_13 ( void )
{
if ( V_16 )
F_2 ( 0x0 , V_16 + V_17 ) ;
}
void F_14 ( void )
{
if ( V_16 )
F_2 ( 0x1 , V_16 + V_17 ) ;
}
bool F_15 ( void )
{
return ! ( F_3 ( V_16 + V_17 ) & 0x1 ) ;
}
void F_16 ( void )
{
T_2 V_18 = F_3 ( V_19 + V_20 ) ;
T_2 V_21 = F_3 ( V_16 + V_22 ) ;
T_2 V_23 = F_3 ( V_19 + V_24 ) ;
if ( V_18 && ! ( V_21 & F_17 ( V_25 ) ) ) {
F_18 ( L_2 , V_26 ) ;
F_2 ( 1 , V_19 + V_20 ) ;
if ( ! ( V_23 & V_27 ) ) {
F_2 ( 1 , V_19 + V_28 ) ;
V_23 |= V_29 ;
F_2 ( V_23 , V_19 + V_24 ) ;
}
}
}
void V_14 * F_19 ( void )
{
return V_30 ;
}
static void F_20 ( unsigned long V_31 , unsigned V_32 )
{
unsigned V_33 ;
switch ( V_32 ) {
case V_34 :
V_33 = V_35 ;
break;
case V_36 :
V_33 = V_37 ;
break;
case V_38 :
V_33 = V_39 ;
break;
case V_40 :
V_33 = V_41 ;
break;
case V_42 :
F_21 ( L_3 ) ;
return;
default:
F_22 ( 1 , L_4 , V_32 ) ;
return;
}
F_23 ( V_33 , V_31 ) ;
}
int T_1 F_24 ( void )
{
T_2 V_43 ;
V_30 = F_25 ( V_44 , V_45 ) ;
if ( F_26 ( ! V_30 ) )
return - V_46 ;
V_43 = V_47 |
V_48 |
V_49 ;
V_50 . V_51 = F_20 ;
if ( F_27 () )
F_28 ( V_43 , 0xcf9fffff ) ;
else
F_29 ( V_30 , V_43 , 0xcf9fffff ) ;
return 0 ;
}
void V_14 * F_30 ( void )
{
return V_52 ;
}
static int T_1 F_31 ( void )
{
unsigned long V_53 ;
if ( F_32 () )
V_53 = V_54 ;
else if ( F_33 () )
V_53 = V_55 ;
else
return - V_46 ;
V_52 = F_25 ( V_53 , V_56 ) ;
if ( F_26 ( ! V_52 ) )
return - V_46 ;
return 0 ;
}
void T_1 F_34 ( void )
{
struct V_57 * V_58 ;
if ( ! F_35 () )
goto V_59;
V_58 = F_36 ( NULL , NULL , L_5 ) ;
V_16 = F_37 ( V_58 , 0 ) ;
F_26 ( ! V_16 ) ;
V_58 = F_36 ( NULL , NULL , L_6 ) ;
V_19 = F_37 ( V_58 , 0 ) ;
F_26 ( ! V_19 ) ;
V_59:
F_38 () ;
#ifdef F_39
F_40 () ;
#endif
F_41 () ;
}

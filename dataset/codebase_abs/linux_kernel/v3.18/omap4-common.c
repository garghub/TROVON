void F_1 ( void )
{
if ( V_1 && V_2 ) {
F_2 ( F_3 ( V_1 ) , V_1 ) ;
F_2 ( F_3 ( V_2 ) , V_2 ) ;
F_4 () ;
}
}
static int T_1 F_5 ( void )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_4 = F_6 ( NULL , NULL , L_1 ) ;
if ( ! V_4 )
F_7 ( L_2 ,
V_7 ) ;
V_6 = F_8 ( V_4 , L_3 , 0 ) ;
if ( ! V_6 )
F_7 ( L_4 ,
V_7 ) ;
else
V_2 = ( void * ) F_9 ( V_6 , V_8 ) ;
return 0 ;
}
int T_1 F_10 ( void )
{
V_9 = F_11 ( V_8 , V_10 ) ;
V_11 = F_12 ( V_9 , V_10 ) ;
return 0 ;
}
void T_1 F_13 ( void )
{
struct V_12 V_13 [ 1 ] ;
V_13 [ 0 ] . V_14 = V_15 ;
V_13 [ 0 ] . V_16 = F_14 ( V_11 ) ;
V_13 [ 0 ] . V_17 = V_9 ;
V_13 [ 0 ] . type = V_18 ;
F_15 ( V_13 , F_16 ( V_13 ) ) ;
V_1 = ( void V_19 * ) V_13 [ 0 ] . V_14 ;
F_17 ( L_5 ,
( long long ) V_11 , V_13 [ 0 ] . V_14 ) ;
}
void T_1 F_13 ( void )
{}
void F_18 ( void )
{
if ( V_20 )
F_2 ( 0x0 , V_20 + V_21 ) ;
}
void F_19 ( void )
{
if ( V_20 )
F_2 ( 0x1 , V_20 + V_21 ) ;
}
bool F_20 ( void )
{
return ! ( F_3 ( V_20 + V_21 ) & 0x1 ) ;
}
void F_21 ( void )
{
T_2 V_22 = F_3 ( V_23 + V_24 ) ;
T_2 V_25 = F_3 ( V_20 + V_26 ) ;
T_2 V_27 = F_3 ( V_23 + V_28 ) ;
if ( V_22 && ! ( V_25 & F_22 ( V_29 ) ) ) {
F_7 ( L_6 , V_7 ) ;
F_2 ( 1 , V_23 + V_24 ) ;
if ( ! ( V_27 & V_30 ) ) {
F_2 ( 1 , V_23 + V_31 ) ;
V_27 |= V_32 ;
F_2 ( V_27 , V_23 + V_28 ) ;
}
}
}
void V_19 * F_23 ( void )
{
return V_33 ;
}
static void F_24 ( unsigned long V_34 , unsigned V_35 )
{
unsigned V_36 ;
switch ( V_35 ) {
case V_37 :
V_36 = V_38 ;
break;
case V_39 :
V_36 = V_40 ;
break;
case V_41 :
V_36 = V_42 ;
break;
case V_43 :
V_36 = V_44 ;
break;
case V_45 :
F_25 ( L_7 ) ;
return;
default:
F_26 ( 1 , L_8 , V_35 ) ;
return;
}
F_27 ( V_36 , V_34 ) ;
}
int T_1 F_28 ( void )
{
T_2 V_46 ;
V_33 = F_29 ( V_47 , V_48 ) ;
if ( F_30 ( ! V_33 ) )
return - V_49 ;
V_46 = V_50 |
V_51 |
V_52 ;
V_53 . V_54 = F_24 ;
if ( F_31 () )
F_32 ( V_46 , 0xcf9fffff ) ;
else
F_33 ( V_33 , V_46 , 0xcf9fffff ) ;
return 0 ;
}
void V_19 * F_34 ( void )
{
return V_55 ;
}
static int T_1 F_35 ( void )
{
unsigned long V_56 ;
if ( F_36 () )
V_56 = V_57 ;
else if ( F_37 () )
V_56 = V_58 ;
else
return - V_49 ;
V_55 = F_29 ( V_56 , V_59 ) ;
if ( F_30 ( ! V_55 ) )
return - V_49 ;
return 0 ;
}
void T_1 F_38 ( void )
{
struct V_3 * V_4 ;
if ( ! F_39 () )
goto V_60;
V_4 = F_6 ( NULL , NULL , L_9 ) ;
V_20 = F_40 ( V_4 , 0 ) ;
F_30 ( ! V_20 ) ;
V_4 = F_6 ( NULL , NULL , L_10 ) ;
V_23 = F_40 ( V_4 , 0 ) ;
F_30 ( ! V_23 ) ;
V_60:
F_41 () ;
#ifdef F_42
F_43 () ;
#endif
F_44 () ;
}

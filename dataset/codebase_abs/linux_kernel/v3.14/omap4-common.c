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
void T_1 F_13 ( void )
{
void V_14 * V_16 ;
V_17 = F_14 ( V_18 , V_19 ) ;
F_15 ( ! V_17 ) ;
V_20 = F_14 ( V_21 , V_19 ) ;
F_15 ( ! V_20 ) ;
V_16 = F_14 ( V_22 , V_23 ) ;
F_15 ( ! V_16 ) ;
F_16 () ;
F_17 ( 0 , 29 , V_17 , V_16 ) ;
}
void F_18 ( void )
{
if ( V_17 )
F_19 ( 0x0 , V_17 + V_24 ) ;
}
void F_20 ( void )
{
if ( V_17 )
F_19 ( 0x1 , V_17 + V_24 ) ;
}
bool F_21 ( void )
{
return ! ( F_22 ( V_17 + V_24 ) & 0x1 ) ;
}
void F_23 ( void )
{
T_2 V_25 = F_22 ( V_20 + V_26 ) ;
T_2 V_27 = F_22 ( V_17 + V_28 ) ;
T_2 V_29 = F_22 ( V_20 + V_30 ) ;
if ( V_25 && ! ( V_27 & F_24 ( V_31 ) ) ) {
F_25 ( L_2 , V_32 ) ;
F_19 ( 1 , V_20 + V_26 ) ;
if ( ! ( V_29 & V_33 ) ) {
F_19 ( 1 , V_20 + V_34 ) ;
V_29 |= V_35 ;
F_19 ( V_29 , V_20 + V_30 ) ;
}
}
}
void V_14 * F_26 ( void )
{
return V_36 ;
}
static void F_27 ( void )
{
F_28 () ;
F_29 ( 0x102 , 0x0 ) ;
}
static void F_30 ( unsigned long V_37 )
{
F_29 ( 0x100 , V_37 ) ;
}
static int T_1 F_31 ( void )
{
T_2 V_38 = 0 ;
if ( ! F_32 () )
return - V_39 ;
V_36 = F_14 ( V_40 , V_19 ) ;
if ( F_33 ( ! V_36 ) )
return - V_41 ;
V_38 = ( ( 1 << V_42 ) |
( 0x1 << 25 ) |
( 0x1 << V_43 ) |
( 0x1 << V_44 ) ) ;
if ( F_34 () == V_45 ) {
V_38 |= 0x2 << V_46 ;
} else {
V_38 |= ( ( 0x3 << V_46 ) |
( 1 << V_47 ) |
( 1 << V_48 ) |
( 1 << V_49 ) |
( 1 << V_50 ) ) ;
}
if ( F_34 () != V_45 )
F_29 ( 0x109 , V_38 ) ;
F_29 ( 0x102 , 0x1 ) ;
if ( F_35 () )
F_36 ( V_38 , V_51 ) ;
else
F_37 ( V_36 , V_38 , V_51 ) ;
V_52 . V_53 = F_27 ;
V_52 . V_54 = F_30 ;
return 0 ;
}
void V_14 * F_38 ( void )
{
return V_55 ;
}
static int T_1 F_39 ( void )
{
unsigned long V_56 ;
if ( F_32 () )
V_56 = V_57 ;
else if ( F_40 () )
V_56 = V_58 ;
else
return - V_41 ;
V_55 = F_14 ( V_56 , V_59 ) ;
if ( F_33 ( ! V_55 ) )
return - V_41 ;
return 0 ;
}
void T_1 F_41 ( void )
{
struct V_60 * V_61 ;
if ( ! F_42 () )
goto V_62;
V_61 = F_43 ( NULL , NULL , L_3 ) ;
V_17 = F_44 ( V_61 , 0 ) ;
F_33 ( ! V_17 ) ;
V_61 = F_43 ( NULL , NULL , L_4 ) ;
V_20 = F_44 ( V_61 , 0 ) ;
F_33 ( ! V_20 ) ;
V_62:
F_16 () ;
F_45 () ;
}

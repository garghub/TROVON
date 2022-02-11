static void F_1 ( void )
{
if ( V_1 )
F_2 ( 0 , V_1 ) ;
}
void F_3 ( void )
{
if ( V_1 && V_2 ) {
F_2 ( F_4 ( V_1 ) , V_1 ) ;
F_2 ( F_4 ( V_2 ) , V_2 ) ;
F_5 () ;
}
}
static int T_1 F_6 ( void )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_4 = F_7 ( NULL , NULL , L_1 ) ;
if ( ! V_4 )
F_8 ( L_2 ,
V_7 ) ;
V_6 = F_9 ( V_4 , L_3 , 0 ) ;
if ( ! V_6 )
F_8 ( L_4 ,
V_7 ) ;
else
V_2 = ( void * ) F_10 ( V_6 , V_8 ) ;
return 0 ;
}
void T_1 F_11 ( void )
{
V_9 = F_12 ( V_8 , V_10 ) ;
V_11 = F_13 ( V_9 , V_10 ) ;
}
void T_1 F_14 ( void )
{
struct V_12 V_13 [ 1 ] ;
V_13 [ 0 ] . V_14 = V_15 ;
V_13 [ 0 ] . V_16 = F_15 ( V_11 ) ;
V_13 [ 0 ] . V_17 = V_9 ;
V_13 [ 0 ] . type = V_18 ;
F_16 ( V_13 , F_17 ( V_13 ) ) ;
V_1 = ( void V_19 * ) V_13 [ 0 ] . V_14 ;
F_18 ( L_5 ,
& V_11 , V_1 ) ;
V_20 = F_1 ;
}
void F_19 ( void )
{
if ( V_21 )
F_2 ( 0x0 , V_21 + V_22 ) ;
}
void F_20 ( void )
{
if ( V_21 )
F_2 ( 0x1 , V_21 + V_22 ) ;
}
bool F_21 ( void )
{
return ! ( F_4 ( V_21 + V_22 ) & 0x1 ) ;
}
void F_22 ( void )
{
T_2 V_23 = F_4 ( V_24 + V_25 ) ;
T_2 V_26 = F_4 ( V_21 + V_27 ) ;
T_2 V_28 = F_4 ( V_24 + V_29 ) ;
if ( V_23 && ! ( V_26 & F_23 ( V_30 ) ) ) {
F_8 ( L_6 , V_7 ) ;
F_2 ( 1 , V_24 + V_25 ) ;
if ( ! ( V_28 & V_31 ) ) {
F_2 ( 1 , V_24 + V_32 ) ;
V_28 |= V_33 ;
F_2 ( V_28 , V_24 + V_29 ) ;
}
}
}
void V_19 * F_24 ( void )
{
return V_34 ;
}
void F_25 ( unsigned long V_35 , unsigned V_36 )
{
unsigned V_37 ;
switch ( V_36 ) {
case V_38 :
V_37 = V_39 ;
break;
case V_40 :
V_37 = V_41 ;
break;
case V_42 :
V_37 = V_43 ;
break;
case V_44 :
V_37 = V_45 ;
break;
case V_46 :
F_26 ( L_7 ) ;
return;
default:
F_27 ( 1 , L_8 , V_36 ) ;
return;
}
F_28 ( V_37 , V_35 ) ;
}
int T_1 F_29 ( void )
{
V_34 = F_30 ( V_47 , V_48 ) ;
if ( F_31 ( ! V_34 ) )
return - V_49 ;
return 0 ;
}
void V_19 * F_32 ( void )
{
return V_50 ;
}
void T_1 F_33 ( void )
{
unsigned long V_51 ;
if ( F_34 () )
V_51 = V_52 ;
else if ( F_35 () )
V_51 = V_53 ;
else
return;
V_50 = F_30 ( V_51 , V_54 ) ;
if ( F_31 ( ! V_50 ) )
return;
}
unsigned int F_36 ( unsigned int V_55 )
{
struct V_56 V_57 ;
unsigned int V_58 ;
if ( ! V_59 )
V_59 = F_37 ( NULL , V_60 ) ;
if ( F_31 ( ! V_59 ) )
return V_55 ;
V_57 . V_4 = V_59 ;
V_57 . V_61 = 3 ;
V_57 . args [ 0 ] = 0 ;
V_57 . args [ 1 ] = V_55 - V_62 ;
V_57 . args [ 2 ] = V_63 ;
V_58 = F_38 ( & V_57 ) ;
if ( F_31 ( ! V_58 ) )
V_58 = V_55 ;
return V_58 ;
}
void T_1 F_39 ( void )
{
struct V_3 * V_4 ;
V_59 = F_37 ( NULL , V_60 ) ;
if ( F_31 ( ! V_59 ) ) {
F_40 ( L_9 ) ;
F_40 ( L_10 ) ;
}
if ( ! F_41 () )
goto V_64;
V_4 = F_7 ( NULL , NULL , L_11 ) ;
V_21 = F_42 ( V_4 , 0 ) ;
F_31 ( ! V_21 ) ;
V_4 = F_7 ( NULL , NULL , L_12 ) ;
V_24 = F_42 ( V_4 , 0 ) ;
F_31 ( ! V_24 ) ;
V_64:
F_43 () ;
}

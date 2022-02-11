void F_1 ( void )
{
if ( V_1 )
F_2 ( 0x0 , V_1 + V_2 ) ;
}
void F_3 ( void )
{
if ( V_1 )
F_2 ( 0x1 , V_1 + V_2 ) ;
}
bool F_4 ( void )
{
return ! ( F_5 ( V_1 + V_2 ) & 0x1 ) ;
}
void F_6 ( void )
{
T_1 V_3 = F_5 ( V_4 + V_5 ) ;
T_1 V_6 = F_5 ( V_1 + V_7 ) ;
T_1 V_8 = F_5 ( V_4 + V_9 ) ;
if ( V_3 && ! ( V_6 & F_7 ( V_10 ) ) ) {
F_8 ( L_1 , V_11 ) ;
F_2 ( 1 , V_4 + V_5 ) ;
if ( ! ( V_8 & V_12 ) ) {
F_2 ( 1 , V_4 + V_13 ) ;
V_8 |= V_14 ;
F_2 ( V_8 , V_4 + V_9 ) ;
}
}
}
void T_2 * F_9 ( void )
{
return V_15 ;
}
void F_10 ( unsigned long V_16 , unsigned V_17 )
{
unsigned V_18 ;
switch ( V_17 ) {
case V_19 :
V_18 = V_20 ;
break;
case V_21 :
V_18 = V_22 ;
break;
case V_23 :
V_18 = V_24 ;
break;
case V_25 :
V_18 = V_26 ;
break;
case V_27 :
F_11 ( L_2 ) ;
return;
default:
F_12 ( 1 , L_3 , V_17 ) ;
return;
}
F_13 ( V_18 , V_16 ) ;
}
int T_3 F_14 ( void )
{
V_15 = F_15 ( V_28 , V_29 ) ;
if ( F_16 ( ! V_15 ) )
return - V_30 ;
return 0 ;
}
void T_2 * F_17 ( void )
{
return V_31 ;
}
static int T_3 F_18 ( void )
{
unsigned long V_32 ;
if ( F_19 () )
V_32 = V_33 ;
else if ( F_20 () )
V_32 = V_34 ;
else
return - V_30 ;
V_31 = F_15 ( V_32 , V_35 ) ;
if ( F_16 ( ! V_31 ) )
return - V_30 ;
return 0 ;
}
unsigned int F_21 ( unsigned int V_36 )
{
struct V_37 V_38 ;
unsigned int V_39 ;
if ( ! V_40 )
V_40 = F_22 ( NULL , V_41 ) ;
if ( F_16 ( ! V_40 ) )
return V_36 ;
V_38 . V_42 = V_40 ;
V_38 . V_43 = 3 ;
V_38 . args [ 0 ] = 0 ;
V_38 . args [ 1 ] = V_36 - V_44 ;
V_38 . args [ 2 ] = V_45 ;
V_39 = F_23 ( & V_38 ) ;
if ( F_16 ( ! V_39 ) )
V_39 = V_36 ;
return V_39 ;
}
void T_3 F_24 ( void )
{
struct V_46 * V_42 ;
V_40 = F_22 ( NULL , V_41 ) ;
if ( F_16 ( ! V_40 ) ) {
F_25 ( L_4 ) ;
F_25 ( L_5 ) ;
}
if ( ! F_26 () )
goto V_47;
V_42 = F_27 ( NULL , NULL , L_6 ) ;
V_1 = F_28 ( V_42 , 0 ) ;
F_16 ( ! V_1 ) ;
V_42 = F_27 ( NULL , NULL , L_7 ) ;
V_4 = F_28 ( V_42 , 0 ) ;
F_16 ( ! V_4 ) ;
V_47:
F_29 () ;
}

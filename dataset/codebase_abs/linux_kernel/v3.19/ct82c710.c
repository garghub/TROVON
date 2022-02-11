static T_1 F_1 ( int V_1 , void * V_2 )
{
return F_2 ( V_3 , F_3 ( V_4 ) , 0 ) ;
}
static int F_4 ( void )
{
int V_5 = 60000 ;
while ( ( F_3 ( V_6 ) & ( V_7 | V_8 | V_9 ) )
!= ( V_9 | V_8 ) && V_5 ) {
if ( F_5 ( V_6 ) & V_7 ) F_5 ( V_4 ) ;
F_6 ( 1 ) ;
V_5 -- ;
}
return ! V_5 ;
}
static void F_7 ( struct V_10 * V_10 )
{
if ( F_4 () )
F_8 ( V_11 L_1 ) ;
F_9 ( F_5 ( V_6 ) & ~ ( V_12 | V_13 ) , V_6 ) ;
if ( F_4 () )
F_8 ( V_11 L_1 ) ;
F_10 ( V_14 , NULL ) ;
}
static int F_11 ( struct V_10 * V_10 )
{
unsigned char V_15 ;
int V_16 ;
V_16 = F_12 ( V_14 , F_1 , 0 , L_2 , NULL ) ;
if ( V_16 )
return V_16 ;
V_15 = F_5 ( V_6 ) ;
V_15 |= ( V_12 | V_17 ) ;
F_9 ( V_15 , V_6 ) ;
V_15 &= ~ ( V_17 ) ;
F_9 ( V_15 , V_6 ) ;
V_15 |= V_13 ;
F_9 ( V_15 , V_6 ) ;
while ( F_4 () ) {
F_8 ( V_18 L_3 ) ;
V_15 &= ~ ( V_12 | V_13 ) ;
F_9 ( V_15 , V_6 ) ;
F_10 ( V_14 , NULL ) ;
return - V_19 ;
}
return 0 ;
}
static int F_13 ( struct V_10 * V_20 , unsigned char V_21 )
{
if ( F_4 () ) return - 1 ;
F_9 ( V_21 , V_4 ) ;
return 0 ;
}
static int T_2 F_14 ( void )
{
F_9 ( 0x55 , 0x2fa ) ;
F_9 ( 0xaa , 0x3fa ) ;
F_9 ( 0x36 , 0x3fa ) ;
F_9 ( 0xe4 , 0x3fa ) ;
F_9 ( 0x1b , 0x2fa ) ;
F_9 ( 0x0f , 0x390 ) ;
if ( F_5 ( 0x391 ) != 0xe4 )
return - V_22 ;
F_9 ( 0x0d , 0x390 ) ;
V_23 . V_24 = F_5 ( 0x391 ) << 2 ;
V_23 . V_25 = V_23 . V_24 + 1 ;
V_23 . V_26 = V_27 ;
F_9 ( 0x0f , 0x390 ) ;
F_9 ( 0x0f , 0x391 ) ;
return 0 ;
}
static int F_15 ( struct V_28 * V_29 )
{
V_3 = F_16 ( sizeof( struct V_10 ) , V_30 ) ;
if ( ! V_3 )
return - V_31 ;
V_3 -> V_32 . type = V_33 ;
V_3 -> V_29 . V_34 = & V_29 -> V_29 ;
V_3 -> V_35 = F_11 ;
V_3 -> V_36 = F_7 ;
V_3 -> V_37 = F_13 ;
F_17 ( V_3 -> V_38 , L_4 ,
sizeof( V_3 -> V_38 ) ) ;
snprintf ( V_3 -> V_39 , sizeof( V_3 -> V_39 ) ,
L_5 , ( unsigned long long ) V_4 ) ;
F_18 ( V_3 ) ;
F_8 ( V_40 L_6 ,
( unsigned long long ) V_4 , V_14 ) ;
return 0 ;
}
static int F_19 ( struct V_28 * V_29 )
{
F_20 ( V_3 ) ;
return 0 ;
}
static int T_2 F_21 ( void )
{
int error ;
error = F_14 () ;
if ( error )
return error ;
error = F_22 ( & V_41 ) ;
if ( error )
return error ;
V_42 = F_23 ( L_2 , - 1 ) ;
if ( ! V_42 ) {
error = - V_31 ;
goto V_43;
}
error = F_24 ( V_42 , & V_23 , 1 ) ;
if ( error )
goto V_44;
error = F_25 ( V_42 ) ;
if ( error )
goto V_44;
return 0 ;
V_44:
F_26 ( V_42 ) ;
V_43:
F_27 ( & V_41 ) ;
return error ;
}
static void T_3 F_28 ( void )
{
F_29 ( V_42 ) ;
F_27 ( & V_41 ) ;
}

static T_1 F_1 ( void )
{
return V_1 . V_2 ;
}
static T_1 F_2 ( void )
{
return V_1 . V_3 ;
}
static T_1 F_3 ( void )
{
return V_1 . V_4 ;
}
T_1 F_4 ( void )
{
T_1 V_5 = F_5 ( V_6 ) ;
if ( ( V_5 & ( 1 << 2 ) ) == ( 1 << 2 ) )
return 1 ;
else
return 0 ;
}
T_1 F_6 ( T_1 V_7 , T_1 V_8 )
{
T_1 V_9 , V_4 ;
T_1 V_10 = V_11 ;
unsigned long V_12 ;
if ( ( V_11 == V_7 ) && ! V_8 )
return V_10 ;
if ( V_7 == V_13 )
V_9 = F_1 () ;
else if ( V_7 == V_14 )
V_9 = F_2 () ;
else
return V_10 ;
V_4 = F_3 () ;
F_7 ( V_12 ) ;
if ( F_8 () )
F_9 ( 0xffff , V_15 ) ;
else
F_9 ( 0xffff , V_16 ) ;
F_10 ( V_7 , V_9 , V_4 ) ;
V_11 = V_7 ;
F_11 ( V_12 ) ;
return V_10 ;
}
void F_12 ( T_1 V_17 )
{
unsigned long V_18 ;
T_1 V_19 = 0 ;
V_1 . V_4 = ! ( ( F_5 ( V_20 ) & 0x3 ) == 0x1 ) ;
if ( F_13 () )
V_1 . V_21 = 1 ;
else
V_1 . V_21 = 0 ;
if ( V_1 . V_4 != V_22 )
return;
if ( ( ( V_1 . V_3 & ( 1 << 2 ) ) == V_23 ) )
V_1 . V_24 = V_25 ;
else
V_1 . V_24 = V_26 ;
if ( V_1 . V_21 == 0 ) {
V_19 = F_5 ( V_6 ) ;
V_18 = F_5 ( V_27 ) & 0xff00 ;
} else {
V_19 = F_5 ( V_28 ) ;
V_18 = F_5 ( V_29 ) & 0xff00 ;
}
if ( V_17 ) {
V_19 &= ~ 0xff00 ;
V_19 |= V_18 ;
}
V_1 . V_3 = ( V_19 | ( 3 << 8 ) ) ;
F_14 ( & V_1 . V_2 ,
V_1 . V_3 ,
V_1 . V_21 ,
V_17 ) ;
V_1 . V_2 &= 0xff00 ;
V_1 . V_2 |=
( ( V_1 . V_3 & 0xF ) | ( 1 << 2 ) ) ;
V_1 . V_2 |= ( ( 1 << 1 ) | ( 3 << 8 ) ) ;
}

static T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned char V_4 )
{
switch ( V_4 ) {
case V_5 :
case V_6 :
F_2 ( V_7 , 0 ) ;
F_2 ( V_8 , 1 ) ;
break;
case V_9 :
F_2 ( V_7 , 0 ) ;
F_2 ( V_8 , 0 ) ;
break;
}
return V_10 | V_11 | V_12 |
V_13 | V_14 ;
}
static void F_3 ( void )
{
int V_15 ;
V_15 = F_4 ( V_8 , L_1 ) ;
if ( ! V_15 )
V_15 = F_4 ( V_7 ,
L_2 ) ;
if ( V_15 ) {
F_5 ( L_3 ) ;
return;
}
F_2 ( V_7 , 0 ) ;
F_2 ( V_8 , 1 ) ;
F_6 ( & V_16 , V_17 ) ;
}
void F_7 ( void )
{
V_16 . V_18 = V_19 ;
V_8 = V_20 ;
V_7 = V_21 ;
F_3 () ;
}
void T_2 F_8 ( void )
{
F_9 ( & V_22 , V_17 ) ;
F_10 ( & V_23 , V_17 ) ;
}
void T_2 F_11 ( void )
{
V_16 . V_24 &= ~ V_25 ;
F_10 ( & V_23 , V_17 ) ;
V_16 . V_18 = V_26 ;
V_16 . V_27 = true ;
V_8 = V_28 ;
V_7 = V_29 ;
F_3 () ;
}
void T_2 F_12 ( void )
{
F_9 ( & V_22 , V_17 ) ;
F_10 ( & V_23 , V_17 ) ;
V_16 . V_18 = V_30 ;
V_8 = V_31 ;
V_7 = V_32 ;
F_3 () ;
F_13 ( & V_33 , V_17 ) ;
}

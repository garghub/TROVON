static T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned char V_4 )
{
if ( V_4 == V_5 )
F_2 ( V_6 , 1 ) ;
else if ( V_4 == V_7 )
F_2 ( V_6 , 0 ) ;
return V_8 | V_9 | V_10 |
V_11 | V_12 ;
}
static void F_3 ( void )
{
int V_13 ;
V_13 = F_4 ( V_14 , L_1 ) ;
if ( ! V_13 )
V_13 = F_4 ( V_15 ,
L_2 ) ;
if ( V_13 ) {
F_5 ( L_3 ) ;
return;
}
F_6 ( V_15 , 0 ) ;
F_6 ( V_14 , 1 ) ;
if ( F_7 () )
F_8 ( & V_16 , 0x10480180 ) ;
else
F_8 ( & V_16 , 0 ) ;
}
void F_9 ( void )
{
V_16 . V_17 = V_18 ;
V_14 = V_6 ;
V_15 = V_19 ;
F_3 () ;
}
void T_2 F_10 ( void )
{
T_1 V_20 = 0 ;
if ( F_7 () )
V_20 = 0x10480180 ;
if ( ! F_11 () )
V_21 . V_22 |= V_23 ;
F_12 ( & V_21 , V_20 ) ;
F_13 ( & V_24 , V_20 ) ;
if ( F_14 () ) {
V_16 . V_17 = V_25 ;
V_14 = V_26 ;
V_15 = V_27 ;
F_3 () ;
}
}

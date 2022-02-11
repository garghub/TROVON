static T_1 T_2 F_1 ( void )
{
return V_1 ? F_2 ( V_1 ) : 0 ;
}
void F_3 ( struct V_2 * V_3 )
{
unsigned long long V_4 ;
T_3 V_5 ;
struct V_2 * V_6 = & V_7 ;
V_8 = V_9 ;
V_9 = V_1 ? F_2 ( V_1 ) : 0 ;
V_5 = V_9 - V_8 ;
V_4 = F_4 ( V_5 , V_10 , V_11 ) ;
F_5 ( V_6 , V_4 ) ;
* V_3 = * V_6 ;
}
int T_4 F_6 ( void )
{
static char V_12 [] V_13 = V_14
L_1 ;
if ( F_7 () || F_8 () ) {
T_1 V_15 ;
unsigned long V_16 = V_17 ;
void T_5 * V_18 ;
struct V_19 * V_20 ;
if ( F_7 () ) {
V_15 = V_21 ;
V_16 = V_22 ;
} else if ( F_9 () )
V_15 = V_23 + 0x10 ;
else if ( F_10 () )
V_15 = V_24 + 0x10 ;
else if ( F_11 () )
V_15 = V_25 + 0x10 ;
else if ( F_12 () )
V_15 = V_26 + 0x10 ;
else
return - V_27 ;
V_18 = F_13 ( V_15 , V_16 ) ;
if ( ! V_18 )
return - V_27 ;
V_20 = F_14 ( NULL , L_2 ) ;
if ( ! F_15 ( V_20 ) )
F_16 ( V_20 ) ;
V_1 = V_18 ;
F_17 ( & V_10 , & V_11 ,
32768 , V_28 , 120000 ) ;
if ( F_18 ( V_18 , L_3 , 32768 , 250 , 32 ,
V_29 ) )
F_19 ( V_12 , L_3 ) ;
F_20 ( F_1 , 32 , 32768 ) ;
}
return 0 ;
}

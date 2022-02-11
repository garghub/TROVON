static inline unsigned long long T_1 F_1 ( void )
{
T_2 V_1 = V_2 ? F_2 ( V_2 ) : 0 ;
return F_3 ( & V_3 , V_1 , ( T_2 ) ~ 0 , V_4 , V_5 ) ;
}
unsigned long long T_1 F_4 ( void )
{
return F_1 () ;
}
unsigned long long T_1 F_5 ( void )
{
return F_1 () ;
}
static void T_1 F_6 ( void )
{
T_2 V_1 = V_2 ? F_2 ( V_2 ) : 0 ;
F_7 ( & V_3 , V_1 , ( T_2 ) ~ 0 ) ;
}
void F_8 ( struct V_6 * V_7 )
{
unsigned long long V_8 ;
T_3 V_9 ;
struct V_6 * V_10 = & V_11 ;
V_12 = V_13 ;
V_13 = V_2 ? F_2 ( V_2 ) : 0 ;
V_9 = V_13 - V_12 ;
V_8 = F_9 ( V_9 , V_14 , V_15 ) ;
F_10 ( V_10 , V_8 ) ;
* V_7 = * V_10 ;
}
int T_4 F_11 ( void )
{
static char V_16 [] V_17 = V_18
L_1 ;
if ( F_12 () || F_13 () ) {
T_2 V_19 ;
unsigned long V_20 = V_21 ;
void T_5 * V_22 ;
struct V_23 * V_24 ;
if ( F_12 () ) {
V_19 = V_25 ;
V_20 = V_26 ;
} else if ( F_14 () )
V_19 = V_27 + 0x10 ;
else if ( F_15 () )
V_19 = V_28 + 0x10 ;
else if ( F_16 () )
V_19 = V_29 + 0x10 ;
else if ( F_17 () )
V_19 = V_30 + 0x10 ;
else
return - V_31 ;
V_22 = F_18 ( V_19 , V_20 ) ;
if ( ! V_22 )
return - V_31 ;
V_24 = F_19 ( NULL , L_2 ) ;
if ( ! F_20 ( V_24 ) )
F_21 ( V_24 ) ;
V_2 = V_22 ;
F_22 ( & V_14 , & V_15 ,
32768 , V_32 , 120000 ) ;
if ( F_23 ( V_22 , L_3 , 32768 , 250 , 32 ,
V_33 ) )
F_24 ( V_16 , L_3 ) ;
F_25 ( & V_3 , F_6 , 32 ,
32768 , V_4 , V_5 ) ;
}
return 0 ;
}

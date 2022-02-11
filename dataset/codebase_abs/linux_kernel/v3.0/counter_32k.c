static T_1 T_2 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 ) - V_4 ;
}
static T_1 T_2 F_3 ( struct V_1 * V_2 )
{
return F_2 ( V_5 + 0x10 ) - V_4 ;
}
static T_1 T_2 F_4 ( struct V_1 * V_2 )
{
return F_2 ( V_6 + 0x10 ) - V_4 ;
}
static T_1 T_2 F_5 ( struct V_1 * V_2 )
{
return F_2 ( V_7 + 0x10 ) - V_4 ;
}
static T_1 T_2 F_6 ( struct V_1 * V_2 )
{
return F_2 ( V_8 + 0x10 ) - V_4 ;
}
static T_1 T_2 F_7 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline unsigned long long T_2 F_8 ( void )
{
T_3 V_9 = V_10 . V_11 ( & V_10 ) ;
return F_9 ( & V_12 , V_9 , ( T_3 ) ~ 0 , V_13 , V_14 ) ;
}
unsigned long long T_2 F_10 ( void )
{
return F_8 () ;
}
unsigned long long T_2 F_11 ( void )
{
return F_8 () ;
}
static void T_2 F_12 ( void )
{
T_3 V_9 = V_10 . V_11 ( & V_10 ) ;
F_13 ( & V_12 , V_9 , ( T_3 ) ~ 0 ) ;
}
void F_14 ( struct V_15 * V_16 )
{
unsigned long long V_17 ;
T_4 V_18 ;
struct V_15 * V_19 = & V_20 ;
V_21 = V_22 ;
V_22 = V_10 . V_11 ( & V_10 ) ;
V_18 = V_22 - V_21 ;
V_17 = F_15 ( V_18 ,
V_10 . V_23 , V_10 . V_24 ) ;
F_16 ( V_19 , V_17 ) ;
* V_16 = * V_19 ;
}
int T_5 F_17 ( void )
{
static char V_25 [] V_26 = V_27
L_1 ;
if ( F_18 () || F_19 () ) {
struct V_28 * V_29 ;
if ( F_18 () )
V_10 . V_11 = F_1 ;
else if ( F_20 () )
V_10 . V_11 = F_3 ;
else if ( F_21 () )
V_10 . V_11 = F_4 ;
else if ( F_22 () )
V_10 . V_11 = F_5 ;
else if ( F_23 () )
V_10 . V_11 = F_6 ;
else
return - V_30 ;
V_29 = F_24 ( NULL , L_2 ) ;
if ( ! F_25 ( V_29 ) )
F_26 ( V_29 ) ;
V_4 = V_10 . V_11 ( & V_10 ) ;
if ( F_27 ( & V_10 , 32768 ) )
F_28 ( V_25 , V_10 . V_31 ) ;
F_29 ( & V_12 , F_12 , 32 ,
32768 , V_13 , V_14 ) ;
}
return 0 ;
}

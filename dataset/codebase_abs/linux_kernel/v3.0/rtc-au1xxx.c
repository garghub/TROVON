static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_5 ;
V_5 = F_2 ( V_6 ) ;
F_3 ( V_5 , V_4 ) ;
return F_4 ( V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_5 ;
F_6 ( V_4 , & V_5 ) ;
F_7 ( V_5 , V_7 ) ;
F_8 () ;
while ( F_2 ( V_8 ) & V_9 )
F_9 ( 1 ) ;
return 0 ;
}
static int T_1 F_10 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
unsigned long V_5 ;
int V_14 ;
V_5 = F_2 ( V_8 ) ;
if ( ! ( V_5 & V_15 ) ) {
F_11 ( & V_11 -> V_2 , L_1 ) ;
V_14 = - V_16 ;
goto V_17;
}
V_14 = - V_18 ;
if ( F_2 ( V_19 ) != 32767 ) {
V_5 = 0x00100000 ;
while ( ( F_2 ( V_8 ) & V_20 ) && -- V_5 )
F_9 ( 1 ) ;
if ( ! V_5 ) {
F_11 ( & V_11 -> V_2 , L_2 ) ;
goto V_17;
}
F_7 ( 32767 , V_19 ) ;
F_8 () ;
}
while ( F_2 ( V_8 ) & V_9 )
F_9 ( 1 ) ;
V_13 = F_12 ( L_3 , & V_11 -> V_2 ,
& V_21 , V_22 ) ;
if ( F_13 ( V_13 ) ) {
V_14 = F_14 ( V_13 ) ;
goto V_17;
}
F_15 ( V_11 , V_13 ) ;
return 0 ;
V_17:
return V_14 ;
}
static int T_2 F_16 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_17 ( V_11 ) ;
F_18 ( V_13 ) ;
F_15 ( V_11 , NULL ) ;
return 0 ;
}
static int T_3 F_19 ( void )
{
return F_20 ( & V_23 , F_10 ) ;
}
static void T_4 F_21 ( void )
{
F_22 ( & V_23 ) ;
}

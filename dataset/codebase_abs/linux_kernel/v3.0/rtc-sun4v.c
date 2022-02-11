static unsigned long F_1 ( void )
{
unsigned long V_1 , time ;
int V_2 = 10000 ;
V_3:
V_1 = F_2 ( & time ) ;
if ( V_1 == V_4 )
return time ;
if ( V_1 == V_5 ) {
if ( -- V_2 > 0 ) {
F_3 ( 100 ) ;
goto V_3;
}
F_4 ( V_6 L_1 ) ;
return 0 ;
}
F_4 ( V_6 L_2 ) ;
return 0 ;
}
static int F_5 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
F_6 ( F_1 () , V_10 ) ;
return 0 ;
}
static int F_7 ( unsigned long V_11 )
{
unsigned long V_1 ;
int V_2 = 10000 ;
V_3:
V_1 = F_8 ( V_11 ) ;
if ( V_1 == V_4 )
return 0 ;
if ( V_1 == V_5 ) {
if ( -- V_2 > 0 ) {
F_3 ( 100 ) ;
goto V_3;
}
F_4 ( V_6 L_3 ) ;
return - V_12 ;
}
F_4 ( V_6 L_4 ) ;
return - V_13 ;
}
static int F_9 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
unsigned long V_11 ;
int V_14 ;
V_14 = F_10 ( V_10 , & V_11 ) ;
if ( V_14 )
return V_14 ;
return F_7 ( V_11 ) ;
}
static int T_1 F_11 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_12 ( L_5 , & V_16 -> V_8 ,
& V_19 , V_20 ) ;
if ( F_13 ( V_18 ) )
return F_14 ( V_18 ) ;
F_15 ( V_16 , V_18 ) ;
return 0 ;
}
static int T_2 F_16 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_17 ( V_16 ) ;
F_18 ( V_18 ) ;
return 0 ;
}
static int T_1 F_19 ( void )
{
return F_20 ( & V_21 , F_11 ) ;
}
static void T_2 F_21 ( void )
{
F_22 ( & V_21 ) ;
}

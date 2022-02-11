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
F_4 ( L_1 ) ;
return 0 ;
}
F_4 ( L_2 ) ;
return 0 ;
}
static int F_5 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
F_6 ( F_1 () , V_9 ) ;
return 0 ;
}
static int F_7 ( unsigned long V_10 )
{
unsigned long V_1 ;
int V_2 = 10000 ;
V_3:
V_1 = F_8 ( V_10 ) ;
if ( V_1 == V_4 )
return 0 ;
if ( V_1 == V_5 ) {
if ( -- V_2 > 0 ) {
F_3 ( 100 ) ;
goto V_3;
}
F_4 ( L_3 ) ;
return - V_11 ;
}
F_4 ( L_4 ) ;
return - V_12 ;
}
static int F_9 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
unsigned long V_10 ;
int V_13 ;
V_13 = F_10 ( V_9 , & V_10 ) ;
if ( V_13 )
return V_13 ;
return F_7 ( V_10 ) ;
}
static int T_1 F_11 ( struct V_14 * V_15 )
{
struct V_16 * V_17 ;
V_17 = F_12 ( & V_15 -> V_7 , L_5 ,
& V_18 , V_19 ) ;
if ( F_13 ( V_17 ) )
return F_14 ( V_17 ) ;
F_15 ( V_15 , V_17 ) ;
return 0 ;
}

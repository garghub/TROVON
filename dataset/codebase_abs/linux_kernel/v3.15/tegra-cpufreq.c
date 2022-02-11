static int F_1 ( unsigned long V_1 )
{
int V_2 ;
F_2 ( V_3 ) ;
V_2 = F_3 ( V_4 , V_5 ) ;
if ( V_2 ) {
F_4 ( L_1 ) ;
goto V_6;
}
if ( V_1 == F_5 ( V_5 ) )
goto V_6;
V_2 = F_6 ( V_3 , V_1 ) ;
if ( V_2 ) {
F_4 ( L_2 , V_1 ) ;
goto V_6;
}
V_2 = F_3 ( V_4 , V_3 ) ;
if ( V_2 ) {
F_4 ( L_3 ) ;
goto V_6;
}
V_6:
F_7 ( V_3 ) ;
return V_2 ;
}
static int F_8 ( struct V_7 * V_8 ,
unsigned long V_1 )
{
int V_2 = 0 ;
if ( V_1 >= 816000 )
F_6 ( V_9 , 600000000 ) ;
else if ( V_1 >= 456000 )
F_6 ( V_9 , 300000000 ) ;
else
F_6 ( V_9 , 100000000 ) ;
V_2 = F_1 ( V_1 * 1000 ) ;
if ( V_2 )
F_4 ( L_4 ,
V_1 ) ;
return V_2 ;
}
static int F_9 ( struct V_7 * V_8 , unsigned int V_10 )
{
return F_8 ( V_8 , V_11 [ V_10 ] . V_12 ) ;
}
static int F_10 ( struct V_7 * V_8 )
{
int V_2 ;
if ( V_8 -> V_13 >= V_14 )
return - V_15 ;
F_2 ( V_9 ) ;
F_2 ( V_4 ) ;
V_2 = F_11 ( V_8 , V_11 , 300 * 1000 ) ;
if ( V_2 ) {
F_7 ( V_4 ) ;
F_7 ( V_9 ) ;
return V_2 ;
}
V_8 -> V_16 = V_4 ;
V_8 -> V_17 = V_11 [ 0 ] . V_12 ;
return 0 ;
}
static int F_12 ( struct V_7 * V_8 )
{
F_7 ( V_4 ) ;
F_7 ( V_9 ) ;
return 0 ;
}
static int T_1 F_13 ( void )
{
V_4 = F_14 ( NULL , L_5 ) ;
if ( F_15 ( V_4 ) )
return F_16 ( V_4 ) ;
V_3 = F_14 ( NULL , L_6 ) ;
if ( F_15 ( V_3 ) )
return F_16 ( V_3 ) ;
V_5 = F_14 ( NULL , L_7 ) ;
if ( F_15 ( V_5 ) )
return F_16 ( V_5 ) ;
V_9 = F_14 ( L_8 , L_9 ) ;
if ( F_15 ( V_9 ) ) {
F_17 ( V_4 ) ;
return F_16 ( V_9 ) ;
}
return F_18 ( & V_18 ) ;
}
static void T_2 F_19 ( void )
{
F_20 ( & V_18 ) ;
F_17 ( V_9 ) ;
F_17 ( V_4 ) ;
}

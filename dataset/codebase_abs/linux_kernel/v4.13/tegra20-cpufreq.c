static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_4 = F_2 ( V_5 ) / 1000 ;
if ( ( V_6 [ V_3 ] . V_7 == V_4 ) || ( V_2 -> V_8 == V_4 ) )
return 0 ;
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
int V_9 ;
F_4 ( V_10 ) ;
V_9 = F_5 ( V_11 , V_5 ) ;
if ( V_9 )
F_6 ( V_10 ) ;
else
V_12 = true ;
return V_9 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned long V_13 = V_6 [ V_3 ] . V_7 ;
unsigned int V_4 = F_2 ( V_5 ) / 1000 ;
int V_9 = 0 ;
if ( V_13 >= 816000 )
F_8 ( V_14 , 600000000 ) ;
else if ( V_13 >= 456000 )
F_8 ( V_14 , 300000000 ) ;
else
F_8 ( V_14 , 100000000 ) ;
if ( V_13 == V_4 )
return F_5 ( V_11 , V_5 ) ;
V_9 = F_8 ( V_10 , V_13 * 1000 ) ;
if ( V_9 )
F_9 ( L_1 , V_13 ) ;
V_9 = F_5 ( V_11 , V_10 ) ;
F_10 ( V_9 ) ;
if ( V_12 ) {
F_6 ( V_10 ) ;
V_12 = false ;
}
return V_9 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_9 ;
if ( V_2 -> V_15 >= V_16 )
return - V_17 ;
F_4 ( V_14 ) ;
F_4 ( V_11 ) ;
V_9 = F_12 ( V_2 , V_6 , 300 * 1000 ) ;
if ( V_9 ) {
F_6 ( V_11 ) ;
F_6 ( V_14 ) ;
return V_9 ;
}
V_2 -> V_18 = V_11 ;
V_2 -> V_19 = V_6 [ 0 ] . V_7 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
F_6 ( V_11 ) ;
F_6 ( V_14 ) ;
return 0 ;
}
static int T_1 F_14 ( void )
{
V_11 = F_15 ( NULL , L_2 ) ;
if ( F_16 ( V_11 ) )
return F_17 ( V_11 ) ;
V_10 = F_15 ( NULL , L_3 ) ;
if ( F_16 ( V_10 ) )
return F_17 ( V_10 ) ;
V_5 = F_15 ( NULL , L_4 ) ;
if ( F_16 ( V_5 ) )
return F_17 ( V_5 ) ;
V_14 = F_15 ( L_5 , L_6 ) ;
if ( F_16 ( V_14 ) ) {
F_18 ( V_11 ) ;
return F_17 ( V_14 ) ;
}
return F_19 ( & V_20 ) ;
}
static void T_2 F_20 ( void )
{
F_21 ( & V_20 ) ;
F_18 ( V_14 ) ;
F_18 ( V_11 ) ;
}

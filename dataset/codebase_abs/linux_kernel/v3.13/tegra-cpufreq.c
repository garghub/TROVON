static unsigned int F_1 ( unsigned int V_1 )
{
unsigned long V_2 ;
if ( V_1 >= V_3 )
return 0 ;
V_2 = F_2 ( V_4 ) / 1000 ;
return V_2 ;
}
static int F_3 ( unsigned long V_2 )
{
int V_5 ;
F_4 ( V_6 ) ;
V_5 = F_5 ( V_4 , V_7 ) ;
if ( V_5 ) {
F_6 ( L_1 ) ;
goto V_8;
}
if ( V_2 == F_2 ( V_7 ) )
goto V_8;
V_5 = F_7 ( V_6 , V_2 ) ;
if ( V_5 ) {
F_6 ( L_2 , V_2 ) ;
goto V_8;
}
V_5 = F_5 ( V_4 , V_6 ) ;
if ( V_5 ) {
F_6 ( L_3 ) ;
goto V_8;
}
V_8:
F_8 ( V_6 ) ;
return V_5 ;
}
static int F_9 ( struct V_9 * V_10 ,
unsigned long V_2 )
{
int V_5 = 0 ;
if ( F_1 ( 0 ) == V_2 )
return V_5 ;
if ( V_2 >= 816000 )
F_7 ( V_11 , 600000000 ) ;
else if ( V_2 >= 456000 )
F_7 ( V_11 , 300000000 ) ;
else
F_7 ( V_11 , 100000000 ) ;
V_5 = F_3 ( V_2 * 1000 ) ;
if ( V_5 )
F_6 ( L_4 ,
V_2 ) ;
return V_5 ;
}
static unsigned long F_10 ( void )
{
unsigned long V_2 = 0 ;
int V_12 ;
F_11 (i)
V_2 = F_12 ( V_2 , V_13 [ V_12 ] ) ;
return V_2 ;
}
static int F_13 ( struct V_9 * V_10 , unsigned int V_14 )
{
unsigned int V_15 ;
int V_5 = 0 ;
F_14 ( & V_16 ) ;
if ( V_17 )
goto V_8;
V_15 = V_18 [ V_14 ] . V_19 ;
V_13 [ V_10 -> V_1 ] = V_15 ;
V_5 = F_9 ( V_10 , F_10 () ) ;
V_8:
F_15 ( & V_16 ) ;
return V_5 ;
}
static int F_16 ( struct V_20 * V_21 , unsigned long V_22 ,
void * V_23 )
{
F_14 ( & V_16 ) ;
if ( V_22 == V_24 ) {
struct V_9 * V_10 = F_17 ( 0 ) ;
V_17 = true ;
F_18 ( L_5 ,
V_18 [ 0 ] . V_19 ) ;
F_9 ( V_10 , V_18 [ 0 ] . V_19 ) ;
F_19 ( V_10 ) ;
} else if ( V_22 == V_25 ) {
V_17 = false ;
}
F_15 ( & V_16 ) ;
return V_26 ;
}
static int F_20 ( struct V_9 * V_10 )
{
int V_5 ;
if ( V_10 -> V_1 >= V_3 )
return - V_27 ;
F_4 ( V_11 ) ;
F_4 ( V_4 ) ;
V_13 [ V_10 -> V_1 ] = F_1 ( V_10 -> V_1 ) ;
V_5 = F_21 ( V_10 , V_18 , 300 * 1000 ) ;
if ( V_5 ) {
F_8 ( V_4 ) ;
F_8 ( V_11 ) ;
return V_5 ;
}
if ( V_10 -> V_1 == 0 )
F_22 ( & V_28 ) ;
return 0 ;
}
static int F_23 ( struct V_9 * V_10 )
{
F_24 ( V_10 -> V_1 ) ;
F_8 ( V_4 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static int T_1 F_25 ( void )
{
V_4 = F_26 ( NULL , L_6 ) ;
if ( F_27 ( V_4 ) )
return F_28 ( V_4 ) ;
V_6 = F_26 ( NULL , L_7 ) ;
if ( F_27 ( V_6 ) )
return F_28 ( V_6 ) ;
V_7 = F_26 ( NULL , L_8 ) ;
if ( F_27 ( V_7 ) )
return F_28 ( V_7 ) ;
V_11 = F_26 ( L_9 , L_10 ) ;
if ( F_27 ( V_11 ) ) {
F_29 ( V_4 ) ;
return F_28 ( V_11 ) ;
}
return F_30 ( & V_29 ) ;
}
static void T_2 F_31 ( void )
{
F_32 ( & V_29 ) ;
F_29 ( V_11 ) ;
F_29 ( V_4 ) ;
}

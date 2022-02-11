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
int V_2 = - V_11 ;
F_10 ( & V_12 ) ;
if ( ! V_13 )
V_2 = F_8 ( V_8 ,
V_14 [ V_10 ] . V_15 ) ;
F_11 ( & V_12 ) ;
return V_2 ;
}
static int F_12 ( struct V_16 * V_17 , unsigned long V_18 ,
void * V_19 )
{
F_10 ( & V_12 ) ;
if ( V_18 == V_20 ) {
struct V_7 * V_8 = F_13 ( 0 ) ;
V_13 = true ;
F_14 ( L_5 ,
V_14 [ 0 ] . V_15 ) ;
if ( F_5 ( V_4 ) / 1000 != V_14 [ 0 ] . V_15 )
F_8 ( V_8 , V_14 [ 0 ] . V_15 ) ;
F_15 ( V_8 ) ;
} else if ( V_18 == V_21 ) {
V_13 = false ;
}
F_11 ( & V_12 ) ;
return V_22 ;
}
static int F_16 ( struct V_7 * V_8 )
{
int V_2 ;
if ( V_8 -> V_23 >= V_24 )
return - V_25 ;
F_2 ( V_9 ) ;
F_2 ( V_4 ) ;
V_2 = F_17 ( V_8 , V_14 , 300 * 1000 ) ;
if ( V_2 ) {
F_7 ( V_4 ) ;
F_7 ( V_9 ) ;
return V_2 ;
}
if ( V_8 -> V_23 == 0 )
F_18 ( & V_26 ) ;
V_8 -> V_27 = V_4 ;
return 0 ;
}
static int F_19 ( struct V_7 * V_8 )
{
F_20 ( V_8 -> V_23 ) ;
F_7 ( V_4 ) ;
F_7 ( V_9 ) ;
return 0 ;
}
static int T_1 F_21 ( void )
{
V_4 = F_22 ( NULL , L_6 ) ;
if ( F_23 ( V_4 ) )
return F_24 ( V_4 ) ;
V_3 = F_22 ( NULL , L_7 ) ;
if ( F_23 ( V_3 ) )
return F_24 ( V_3 ) ;
V_5 = F_22 ( NULL , L_8 ) ;
if ( F_23 ( V_5 ) )
return F_24 ( V_5 ) ;
V_9 = F_22 ( L_9 , L_10 ) ;
if ( F_23 ( V_9 ) ) {
F_25 ( V_4 ) ;
return F_24 ( V_9 ) ;
}
return F_26 ( & V_28 ) ;
}
static void T_2 F_27 ( void )
{
F_28 ( & V_28 ) ;
F_25 ( V_9 ) ;
F_25 ( V_4 ) ;
}

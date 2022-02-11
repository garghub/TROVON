static void F_1 ( char * V_1 , int V_2 )
{
F_2 ( V_3 L_1 , V_2 ,
V_1 ) ;
}
static int F_3 ( char * V_4 , char * * V_5 )
{
return F_4 ( V_6 , F_5 ( V_6 ) , V_4 , & V_7 ,
V_5 ) ;
}
static int F_6 ( char * V_2 , char * V_4 , int V_8 , char * * V_5 )
{
return F_7 ( V_2 , V_6 , F_5 ( V_6 ) , V_4 ,
V_8 , V_5 ) ;
}
static int F_8 ( int V_9 , char * * V_5 )
{
return F_9 ( V_6 , F_5 ( V_6 ) , V_9 ,
V_5 ) ;
}
static int F_10 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
int V_14 = F_11 ( V_6 , V_11 ) ;
if ( V_14 )
F_2 ( V_15 L_2 ,
V_11 -> V_16 , V_14 ) ;
return V_14 ;
}
static void F_12 ( struct V_17 * V_18 , const char * string ,
unsigned V_19 )
{
struct line * line = & V_6 [ V_18 -> V_16 ] ;
unsigned long V_20 ;
F_13 ( & line -> V_21 , V_20 ) ;
F_14 ( & line -> V_22 , string , V_19 ) ;
F_15 ( & line -> V_21 , V_20 ) ;
}
static struct V_23 * F_16 ( struct V_17 * V_18 , int * V_16 )
{
* V_16 = V_18 -> V_16 ;
return V_24 ;
}
static int F_17 ( struct V_17 * V_25 , char * V_26 )
{
struct line * line = & V_6 [ V_25 -> V_16 ] ;
return F_18 ( line , V_25 ) ;
}
static int F_19 ( void )
{
char * V_27 ;
F_2 ( V_3 L_3 ,
V_28 ) ;
V_24 = F_20 ( & V_29 , & V_30 , V_6 ,
F_5 ( V_6 ) ) ;
V_27 = F_21 ( V_7 . V_31 ) ;
if ( V_27 != NULL )
V_7 . V_31 = V_27 ;
F_22 ( V_6 , F_5 ( V_6 ) , & V_7 ) ;
V_32 = 1 ;
F_23 ( & V_33 ) ;
return 0 ;
}
static void F_24 ( void )
{
if ( ! V_32 )
return;
F_25 ( V_6 , F_5 ( V_6 ) ) ;
}
static int F_26 ( char * V_4 )
{
char * error ;
int V_34 ;
V_34 = F_27 ( V_6 , F_5 ( V_6 ) , V_4 , & error ) ;
if( V_34 < 0 )
F_2 ( V_15 L_4
L_5 , V_4 , error ) ;
return 1 ;
}

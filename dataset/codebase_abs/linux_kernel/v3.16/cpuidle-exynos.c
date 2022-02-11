static int F_1 ( unsigned long V_1 )
{
F_2 () ;
F_3 () ;
return 1 ;
}
static int F_4 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
int V_6 )
{
F_5 () ;
F_6 ( 0 , F_1 ) ;
F_7 () ;
return V_6 ;
}
static int F_8 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
int V_6 )
{
int V_7 = V_6 ;
if ( F_9 () > 1 || V_3 -> V_8 != 0 )
V_7 = V_5 -> V_9 ;
if ( V_7 == 0 )
return F_10 ( V_3 , V_5 , V_7 ) ;
else
return F_4 ( V_3 , V_5 , V_7 ) ;
}
static int F_11 ( struct V_10 * V_11 )
{
int V_12 ;
F_2 = ( void * ) ( V_11 -> V_3 . V_13 ) ;
V_12 = F_12 ( & V_14 , NULL ) ;
if ( V_12 ) {
F_13 ( & V_11 -> V_3 , L_1 ) ;
return V_12 ;
}
return 0 ;
}

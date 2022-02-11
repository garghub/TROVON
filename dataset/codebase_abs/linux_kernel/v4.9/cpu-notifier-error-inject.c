static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = V_2 -> error ;
if ( V_3 )
F_2 ( L_1 , V_3 , V_2 -> V_4 ) ;
return V_3 ;
}
static int F_3 ( unsigned int V_5 )
{
if ( ! V_6 )
return F_1 ( & V_7 . V_8 [ 0 ] ) ;
else
return F_1 ( & V_7 . V_8 [ 1 ] ) ;
}
static int F_4 ( unsigned int V_5 )
{
if ( ! V_6 )
return F_1 ( & V_7 . V_8 [ 2 ] ) ;
else
return F_1 ( & V_7 . V_8 [ 3 ] ) ;
}
static int F_5 ( void )
{
int V_9 ;
V_10 = F_6 ( L_2 , V_11 ,
& V_7 , V_12 ) ;
if ( F_7 ( V_10 ) )
return F_8 ( V_10 ) ;
V_9 = F_9 ( V_13 ,
L_3 ,
F_3 ,
F_4 ) ;
if ( V_9 )
F_10 ( V_10 ) ;
return V_9 ;
}
static void F_11 ( void )
{
F_12 ( V_13 ) ;
F_10 ( V_10 ) ;
}

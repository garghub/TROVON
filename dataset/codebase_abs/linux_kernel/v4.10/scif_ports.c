static int F_1 ( int V_1 , int V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
return - V_7 ;
F_3 ( & V_8 . V_9 ) ;
V_3 = F_4 ( & V_10 , V_5 , V_1 , V_2 , V_6 ) ;
if ( V_3 >= 0 )
V_5 -> V_11 ++ ;
F_5 ( & V_8 . V_9 ) ;
return V_3 ;
}
int F_6 ( T_1 V_5 )
{
return F_1 ( V_5 , V_5 + 1 ) ;
}
int F_7 ( void )
{
return F_1 ( V_12 + 1 , V_13 ) ;
}
void F_8 ( T_1 V_3 )
{
struct V_4 * V_5 ;
if ( ! V_3 )
return;
F_3 ( & V_8 . V_9 ) ;
V_5 = F_9 ( & V_10 , V_3 ) ;
if ( V_5 )
V_5 -> V_11 ++ ;
F_5 ( & V_8 . V_9 ) ;
}
void F_10 ( T_1 V_3 )
{
struct V_4 * V_5 ;
if ( ! V_3 )
return;
F_3 ( & V_8 . V_9 ) ;
V_5 = F_9 ( & V_10 , V_3 ) ;
if ( V_5 ) {
V_5 -> V_11 -- ;
if ( ! V_5 -> V_11 ) {
F_11 ( & V_10 , V_3 ) ;
F_12 ( V_5 ) ;
}
}
F_5 ( & V_8 . V_9 ) ;
}

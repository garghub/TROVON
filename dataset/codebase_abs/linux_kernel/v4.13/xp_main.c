void
F_1 ( void )
{
memset ( & V_1 , 0 , sizeof( V_1 ) ) ;
}
enum V_2
F_2 ( int V_3 , T_1 V_4 , void * V_5 , T_2 V_6 ,
T_2 V_7 , T_3 V_8 , T_3 V_9 )
{
struct V_10 * V_11 ;
F_3 ( V_3 < 0 || V_3 >= V_12 ) ;
F_3 ( V_6 == 0 || V_7 == 0 ) ;
F_3 ( V_4 == NULL ) ;
F_3 ( V_8 == 0 || V_9 > V_8 ) ;
if ( F_4 ( V_6 ) > V_13 )
return V_14 ;
V_11 = & V_15 [ V_3 ] ;
if ( F_5 ( & V_11 -> V_16 ) != 0 )
return V_17 ;
if ( V_11 -> V_4 != NULL ) {
F_6 ( & V_11 -> V_16 ) ;
return V_18 ;
}
V_11 -> V_19 = F_4 ( V_6 ) ;
V_11 -> V_7 = V_7 ;
V_11 -> V_8 = V_8 ;
V_11 -> V_9 = V_9 ;
V_11 -> V_5 = V_5 ;
V_11 -> V_4 = V_4 ;
F_6 ( & V_11 -> V_16 ) ;
if ( V_1 . V_20 )
V_1 . V_20 ( V_3 ) ;
return V_21 ;
}
void
F_7 ( int V_3 )
{
struct V_10 * V_11 ;
F_3 ( V_3 < 0 || V_3 >= V_12 ) ;
V_11 = & V_15 [ V_3 ] ;
F_8 ( & V_11 -> V_16 ) ;
if ( V_11 -> V_4 == NULL ) {
F_6 ( & V_11 -> V_16 ) ;
return;
}
V_11 -> V_4 = NULL ;
V_11 -> V_5 = NULL ;
V_11 -> V_7 = 0 ;
V_11 -> V_19 = 0 ;
V_11 -> V_8 = 0 ;
V_11 -> V_9 = 0 ;
if ( V_1 . V_22 )
V_1 . V_22 ( V_3 ) ;
F_6 ( & V_11 -> V_16 ) ;
return;
}
int T_4
F_9 ( void )
{
enum V_2 V_23 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_12 ; V_3 ++ )
F_10 ( & V_15 [ V_3 ] . V_16 ) ;
if ( F_11 () )
V_23 = F_12 () ;
else if ( F_13 () )
V_23 = F_14 () ;
else
V_23 = 0 ;
if ( V_23 != V_21 )
return V_23 ;
return 0 ;
}
void T_5
F_15 ( void )
{
if ( F_11 () )
F_16 () ;
else if ( F_13 () )
F_17 () ;
}

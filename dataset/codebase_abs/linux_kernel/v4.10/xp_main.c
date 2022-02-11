static enum V_1
F_1 ( void )
{
return V_2 ;
}
void
F_2 ( void )
{
V_3 . V_4 = ( void ( * ) ( int ) ) F_1 ;
V_3 . V_5 = ( void ( * ) ( int ) ) F_1 ;
V_3 . V_6 = (enum V_1 ( * ) ( short , int , V_7 , void * , V_8 ) )
F_1 ;
V_3 . V_9 = (enum V_1 ( * ) ( short , int , V_7 , void * ,
V_8 , V_10 ,
void * ) ) F_1 ;
V_3 . V_11 = ( void ( * ) ( short , int , void * ) )
F_1 ;
V_3 . V_12 = (enum V_1 ( * ) ( short , void * ) )
F_1 ;
}
enum V_1
F_3 ( int V_13 , T_1 V_14 , void * V_15 , V_8 V_16 ,
V_8 V_17 , V_7 V_18 , V_7 V_19 )
{
struct V_20 * V_21 ;
F_4 ( V_13 < 0 || V_13 >= V_22 ) ;
F_4 ( V_16 == 0 || V_17 == 0 ) ;
F_4 ( V_14 == NULL ) ;
F_4 ( V_18 == 0 || V_19 > V_18 ) ;
if ( F_5 ( V_16 ) > V_23 )
return V_24 ;
V_21 = & V_25 [ V_13 ] ;
if ( F_6 ( & V_21 -> V_26 ) != 0 )
return V_27 ;
if ( V_21 -> V_14 != NULL ) {
F_7 ( & V_21 -> V_26 ) ;
return V_28 ;
}
V_21 -> V_29 = F_5 ( V_16 ) ;
V_21 -> V_17 = V_17 ;
V_21 -> V_18 = V_18 ;
V_21 -> V_19 = V_19 ;
V_21 -> V_15 = V_15 ;
V_21 -> V_14 = V_14 ;
F_7 ( & V_21 -> V_26 ) ;
V_3 . V_4 ( V_13 ) ;
return V_30 ;
}
void
F_8 ( int V_13 )
{
struct V_20 * V_21 ;
F_4 ( V_13 < 0 || V_13 >= V_22 ) ;
V_21 = & V_25 [ V_13 ] ;
F_9 ( & V_21 -> V_26 ) ;
if ( V_21 -> V_14 == NULL ) {
F_7 ( & V_21 -> V_26 ) ;
return;
}
V_21 -> V_14 = NULL ;
V_21 -> V_15 = NULL ;
V_21 -> V_17 = 0 ;
V_21 -> V_29 = 0 ;
V_21 -> V_18 = 0 ;
V_21 -> V_19 = 0 ;
V_3 . V_5 ( V_13 ) ;
F_7 ( & V_21 -> V_26 ) ;
return;
}
int T_2
F_10 ( void )
{
enum V_1 V_31 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_22 ; V_13 ++ )
F_11 ( & V_25 [ V_13 ] . V_26 ) ;
if ( F_12 () )
V_31 = F_13 () ;
else if ( F_14 () )
V_31 = F_15 () ;
else
V_31 = 0 ;
if ( V_31 != V_30 )
return V_31 ;
return 0 ;
}
void T_3
F_16 ( void )
{
if ( F_12 () )
F_17 () ;
else if ( F_14 () )
F_18 () ;
}

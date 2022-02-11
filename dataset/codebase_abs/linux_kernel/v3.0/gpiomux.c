int F_1 ( unsigned V_1 ,
T_1 V_2 ,
T_1 V_3 )
{
struct V_4 * V_5 = V_6 + V_1 ;
unsigned long V_7 ;
T_1 V_8 ;
if ( V_1 >= V_9 )
return - V_10 ;
F_2 ( & V_11 , V_7 ) ;
if ( V_2 & V_12 )
V_5 -> V_2 = V_2 ;
if ( V_3 & V_12 )
V_5 -> V_3 = V_3 ;
V_8 = V_5 -> V_13 ? V_2 : V_3 ;
if ( V_8 & V_12 )
F_3 ( V_1 , V_8 ) ;
F_4 ( & V_11 , V_7 ) ;
return 0 ;
}
int F_5 ( unsigned V_1 )
{
struct V_4 * V_5 = V_6 + V_1 ;
unsigned long V_7 ;
if ( V_1 >= V_9 )
return - V_10 ;
F_2 ( & V_11 , V_7 ) ;
if ( V_5 -> V_13 ++ == 0 && V_5 -> V_2 & V_12 )
F_3 ( V_1 , V_5 -> V_2 ) ;
F_4 ( & V_11 , V_7 ) ;
return 0 ;
}
int F_6 ( unsigned V_1 )
{
struct V_4 * V_5 = V_6 + V_1 ;
unsigned long V_7 ;
if ( V_1 >= V_9 )
return - V_10 ;
F_2 ( & V_11 , V_7 ) ;
F_7 ( V_5 -> V_13 == 0 ) ;
if ( -- V_5 -> V_13 == 0 && V_5 -> V_3 & V_12 )
F_3 ( V_1 , V_5 -> V_3 ) ;
F_4 ( & V_11 , V_7 ) ;
return 0 ;
}
static int T_2 F_8 ( void )
{
unsigned V_14 ;
for ( V_14 = 0 ; V_14 < V_9 ; ++ V_14 ) {
V_6 [ V_14 ] . V_13 = 0 ;
if ( ! ( V_6 [ V_14 ] . V_3 & V_12 ) )
continue;
F_3 ( V_14 , V_6 [ V_14 ] . V_3 ) ;
}
return 0 ;
}

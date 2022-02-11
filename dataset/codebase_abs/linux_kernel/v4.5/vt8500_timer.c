static T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( 10 ) ;
F_3 ( 3 , V_4 + V_5 ) ;
while ( ( F_4 ( ( V_4 + V_6 ) ) & V_7 )
&& -- V_3 )
F_5 () ;
return F_4 ( V_4 + V_8 ) ;
}
static int F_6 ( unsigned long V_9 ,
struct V_10 * V_11 )
{
int V_3 = F_2 ( 10 ) ;
T_1 V_12 = V_1 . V_13 ( & V_1 ) + V_9 ;
while ( ( F_4 ( V_4 + V_6 ) & V_14 )
&& -- V_3 )
F_5 () ;
F_3 ( ( unsigned long ) V_12 , V_4 + V_15 ) ;
if ( ( signed ) ( V_12 - V_1 . V_13 ( & V_1 ) ) <= V_16 )
return - V_17 ;
F_3 ( 1 , V_4 + V_18 ) ;
return 0 ;
}
static int F_7 ( struct V_10 * V_11 )
{
F_3 ( F_4 ( V_4 + V_5 ) | 1 , V_4 + V_5 ) ;
F_3 ( 0 , V_4 + V_18 ) ;
return 0 ;
}
static T_2 F_8 ( int V_19 , void * V_20 )
{
struct V_10 * V_11 = V_20 ;
F_3 ( 0xf , V_4 + V_21 ) ;
V_11 -> V_22 ( V_11 ) ;
return V_23 ;
}
static void T_3 F_9 ( struct V_24 * V_25 )
{
int V_26 ;
V_4 = F_10 ( V_25 , 0 ) ;
if ( ! V_4 ) {
F_11 ( L_1 ,
V_27 ) ;
return;
}
V_26 = F_12 ( V_25 , 0 ) ;
if ( ! V_26 ) {
F_11 ( L_2 ,
V_27 ) ;
return;
}
F_3 ( 1 , V_4 + V_5 ) ;
F_3 ( 0xf , V_4 + V_21 ) ;
F_3 ( ~ 0 , V_4 + V_15 ) ;
if ( F_13 ( & V_1 , V_28 ) )
F_11 ( L_3 ,
V_27 , V_1 . V_29 ) ;
V_30 . V_31 = F_14 ( 0 ) ;
if ( F_15 ( V_26 , & V_19 ) )
F_11 ( L_4 , V_27 ,
V_30 . V_29 ) ;
F_16 ( & V_30 , V_28 ,
V_16 * 2 , 0xf0000000 ) ;
}

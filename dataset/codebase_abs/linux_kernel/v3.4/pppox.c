int F_1 ( int V_1 , const struct V_2 * V_3 )
{
if ( V_1 < 0 || V_1 > V_4 )
return - V_5 ;
if ( V_6 [ V_1 ] )
return - V_7 ;
V_6 [ V_1 ] = V_3 ;
return 0 ;
}
void F_2 ( int V_1 )
{
if ( V_1 >= 0 && V_1 <= V_4 )
V_6 [ V_1 ] = NULL ;
}
void F_3 ( struct V_8 * V_9 )
{
if ( V_9 -> V_10 & ( V_11 | V_12 | V_13 ) ) {
F_4 ( & F_5 ( V_9 ) -> V_14 ) ;
V_9 -> V_10 = V_15 ;
}
}
int F_6 ( struct V_16 * V_8 , unsigned int V_17 , unsigned long V_18 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_19 * V_20 = F_5 ( V_9 ) ;
int V_21 ;
F_7 ( V_9 ) ;
switch ( V_17 ) {
case V_22 : {
int V_23 ;
V_21 = - V_24 ;
if ( ! ( V_9 -> V_10 & V_12 ) )
break;
V_21 = - V_5 ;
V_23 = F_8 ( & V_20 -> V_14 ) ;
if ( F_9 ( V_23 , ( int V_25 * ) V_18 ) )
break;
V_21 = 0 ;
V_9 -> V_10 |= V_11 ;
break;
}
default:
V_21 = V_6 [ V_9 -> V_26 ] -> V_27 ?
V_6 [ V_9 -> V_26 ] -> V_27 ( V_8 , V_17 , V_18 ) : - V_28 ;
}
F_10 ( V_9 ) ;
return V_21 ;
}
static int F_11 ( struct V_29 * V_29 , struct V_16 * V_8 , int V_30 ,
int V_31 )
{
int V_21 = - V_32 ;
if ( V_30 < 0 || V_30 > V_4 )
goto V_33;
V_21 = - V_34 ;
if ( ! V_6 [ V_30 ] )
F_12 ( L_1 , V_30 ) ;
if ( ! V_6 [ V_30 ] ||
! F_13 ( V_6 [ V_30 ] -> V_35 ) )
goto V_33;
V_21 = V_6 [ V_30 ] -> F_14 ( V_29 , V_8 ) ;
F_15 ( V_6 [ V_30 ] -> V_35 ) ;
V_33:
return V_21 ;
}
static int T_1 F_16 ( void )
{
return F_17 ( & V_36 ) ;
}
static void T_2 F_18 ( void )
{
F_19 ( V_37 ) ;
}

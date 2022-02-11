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
if ( V_9 -> V_10 & ( V_11 | V_12 ) ) {
F_4 ( & F_5 ( V_9 ) -> V_13 ) ;
V_9 -> V_10 = V_14 ;
}
}
int F_6 ( struct V_15 * V_8 , unsigned int V_16 , unsigned long V_17 )
{
struct V_8 * V_9 = V_8 -> V_9 ;
struct V_18 * V_19 = F_5 ( V_9 ) ;
int V_20 ;
F_7 ( V_9 ) ;
switch ( V_16 ) {
case V_21 : {
int V_22 ;
V_20 = - V_23 ;
if ( ! ( V_9 -> V_10 & V_12 ) )
break;
V_20 = - V_5 ;
V_22 = F_8 ( & V_19 -> V_13 ) ;
if ( F_9 ( V_22 , ( int V_24 * ) V_17 ) )
break;
V_20 = 0 ;
V_9 -> V_10 |= V_11 ;
break;
}
default:
V_20 = V_6 [ V_9 -> V_25 ] -> V_26 ?
V_6 [ V_9 -> V_25 ] -> V_26 ( V_8 , V_16 , V_17 ) : - V_27 ;
}
F_10 ( V_9 ) ;
return V_20 ;
}
static int F_11 ( struct V_28 * V_28 , struct V_15 * V_8 , int V_29 ,
int V_30 )
{
int V_20 = - V_31 ;
if ( V_29 < 0 || V_29 > V_4 )
goto V_32;
V_20 = - V_33 ;
if ( ! V_6 [ V_29 ] )
F_12 ( L_1 , V_34 , V_29 ) ;
if ( ! V_6 [ V_29 ] ||
! F_13 ( V_6 [ V_29 ] -> V_35 ) )
goto V_32;
V_20 = V_6 [ V_29 ] -> F_14 ( V_28 , V_8 , V_30 ) ;
F_15 ( V_6 [ V_29 ] -> V_35 ) ;
V_32:
return V_20 ;
}
static int T_1 F_16 ( void )
{
return F_17 ( & V_36 ) ;
}
static void T_2 F_18 ( void )
{
F_19 ( V_34 ) ;
}

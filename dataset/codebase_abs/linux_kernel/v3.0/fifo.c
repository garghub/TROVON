static void F_1 ( struct V_1 * V_1 , unsigned int * V_2 )
{
int V_3 = * V_2 ;
while ( V_3 == * V_2 ) {
F_2 ( V_1 -> V_4 ) ;
if ( F_3 ( V_5 ) )
break;
}
}
static void F_4 ( struct V_1 * V_1 )
{
F_5 ( & V_1 -> V_4 -> V_6 ) ;
}
static int F_6 ( struct V_1 * V_1 , struct V_7 * V_8 )
{
struct V_9 * V_10 ;
int V_11 ;
F_7 ( & V_1 -> V_12 ) ;
V_10 = V_1 -> V_4 ;
if ( ! V_10 ) {
V_11 = - V_13 ;
V_10 = F_8 ( V_1 ) ;
if ( ! V_10 )
goto V_14;
V_1 -> V_4 = V_10 ;
}
V_8 -> V_15 = 0 ;
V_8 -> V_16 &= ( V_17 | V_18 ) ;
switch ( V_8 -> V_16 ) {
case V_17 :
V_8 -> V_19 = & V_20 ;
V_10 -> V_21 ++ ;
if ( V_10 -> V_22 ++ == 0 )
F_4 ( V_1 ) ;
if ( ! V_10 -> V_23 ) {
if ( ( V_8 -> V_24 & V_25 ) ) {
V_8 -> V_15 = V_10 -> V_26 ;
} else {
F_1 ( V_1 , & V_10 -> V_26 ) ;
if( F_3 ( V_5 ) )
goto V_27;
}
}
break;
case V_18 :
V_11 = - V_28 ;
if ( ( V_8 -> V_24 & V_25 ) && ! V_10 -> V_22 )
goto V_29;
V_8 -> V_19 = & V_30 ;
V_10 -> V_26 ++ ;
if ( ! V_10 -> V_23 ++ )
F_4 ( V_1 ) ;
if ( ! V_10 -> V_22 ) {
F_1 ( V_1 , & V_10 -> V_21 ) ;
if ( F_3 ( V_5 ) )
goto V_31;
}
break;
case V_17 | V_18 :
V_8 -> V_19 = & V_32 ;
V_10 -> V_22 ++ ;
V_10 -> V_23 ++ ;
V_10 -> V_21 ++ ;
V_10 -> V_26 ++ ;
if ( V_10 -> V_22 == 1 || V_10 -> V_23 == 1 )
F_4 ( V_1 ) ;
break;
default:
V_11 = - V_33 ;
goto V_29;
}
F_9 ( & V_1 -> V_12 ) ;
return 0 ;
V_27:
if ( ! -- V_10 -> V_22 )
F_5 ( & V_10 -> V_6 ) ;
V_11 = - V_34 ;
goto V_29;
V_31:
if ( ! -- V_10 -> V_23 )
F_5 ( & V_10 -> V_6 ) ;
V_11 = - V_34 ;
goto V_29;
V_29:
if ( ! V_10 -> V_22 && ! V_10 -> V_23 )
F_10 ( V_1 ) ;
V_14:
F_9 ( & V_1 -> V_12 ) ;
return V_11 ;
}

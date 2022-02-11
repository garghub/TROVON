static int F_1 ( struct V_1 * V_1 , unsigned int * V_2 )
{
int V_3 = * V_2 ;
while ( V_3 == * V_2 ) {
F_2 ( V_1 -> V_4 ) ;
if ( F_3 ( V_5 ) )
break;
}
return V_3 == * V_2 ? - V_6 : 0 ;
}
static void F_4 ( struct V_1 * V_1 )
{
F_5 ( & V_1 -> V_4 -> V_7 ) ;
}
static int F_6 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_10 * V_11 ;
int V_12 ;
F_7 ( & V_1 -> V_13 ) ;
V_11 = V_1 -> V_4 ;
if ( ! V_11 ) {
V_12 = - V_14 ;
V_11 = F_8 ( V_1 ) ;
if ( ! V_11 )
goto V_15;
V_1 -> V_4 = V_11 ;
}
V_9 -> V_16 = 0 ;
V_9 -> V_17 &= ( V_18 | V_19 ) ;
switch ( V_9 -> V_17 ) {
case V_18 :
V_9 -> V_20 = & V_21 ;
V_11 -> V_22 ++ ;
if ( V_11 -> V_23 ++ == 0 )
F_4 ( V_1 ) ;
if ( ! V_11 -> V_24 ) {
if ( ( V_9 -> V_25 & V_26 ) ) {
V_9 -> V_16 = V_11 -> V_27 ;
} else {
if ( F_1 ( V_1 , & V_11 -> V_27 ) )
goto V_28;
}
}
break;
case V_19 :
V_12 = - V_29 ;
if ( ( V_9 -> V_25 & V_26 ) && ! V_11 -> V_23 )
goto V_30;
V_9 -> V_20 = & V_31 ;
V_11 -> V_27 ++ ;
if ( ! V_11 -> V_24 ++ )
F_4 ( V_1 ) ;
if ( ! V_11 -> V_23 ) {
if ( F_1 ( V_1 , & V_11 -> V_22 ) )
goto V_32;
}
break;
case V_18 | V_19 :
V_9 -> V_20 = & V_33 ;
V_11 -> V_23 ++ ;
V_11 -> V_24 ++ ;
V_11 -> V_22 ++ ;
V_11 -> V_27 ++ ;
if ( V_11 -> V_23 == 1 || V_11 -> V_24 == 1 )
F_4 ( V_1 ) ;
break;
default:
V_12 = - V_34 ;
goto V_30;
}
F_9 ( & V_1 -> V_13 ) ;
return 0 ;
V_28:
if ( ! -- V_11 -> V_23 )
F_5 ( & V_11 -> V_7 ) ;
V_12 = - V_6 ;
goto V_30;
V_32:
if ( ! -- V_11 -> V_24 )
F_5 ( & V_11 -> V_7 ) ;
V_12 = - V_6 ;
goto V_30;
V_30:
if ( ! V_11 -> V_23 && ! V_11 -> V_24 )
F_10 ( V_1 ) ;
V_15:
F_9 ( & V_1 -> V_13 ) ;
return V_12 ;
}

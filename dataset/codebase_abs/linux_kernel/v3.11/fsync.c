static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = NULL ;
struct V_1 * V_3 ;
int V_4 = 0 ;
if ( ! F_2 ( V_1 , V_5 ) )
return 0 ;
V_1 = F_3 ( V_1 ) ;
while ( F_2 ( V_1 , V_5 ) ) {
F_4 ( V_1 , V_5 ) ;
V_2 = F_5 ( V_1 ) ;
if ( ! V_2 )
break;
V_3 = F_3 ( V_2 -> V_6 -> V_7 ) ;
F_6 ( V_2 ) ;
if ( ! V_3 )
break;
F_7 ( V_1 ) ;
V_1 = V_3 ;
V_4 = F_8 ( V_1 -> V_8 ) ;
if ( V_4 )
break;
V_4 = F_9 ( V_1 , 1 ) ;
if ( V_4 )
break;
}
F_7 ( V_1 ) ;
return V_4 ;
}
int F_10 ( struct V_9 * V_9 , T_1 V_10 , T_1 V_11 , int V_12 )
{
struct V_1 * V_1 = V_9 -> V_13 -> V_14 ;
struct V_15 * V_16 = F_11 ( V_1 ) ;
T_2 * V_17 = F_12 ( V_1 -> V_18 ) -> V_19 ;
int V_4 = 0 , V_20 ;
T_3 V_21 ;
bool V_22 = false ;
F_13 ( F_14 () == NULL ) ;
F_15 ( V_9 , V_12 ) ;
if ( V_1 -> V_18 -> V_23 & V_24 ) {
F_16 () ;
if ( F_12 ( V_1 -> V_18 ) -> V_25 & V_26 )
V_4 = - V_27 ;
goto V_28;
}
if ( ! V_17 ) {
V_4 = F_17 ( V_9 , V_10 , V_11 , V_12 ) ;
if ( ! V_4 && ! F_18 ( & V_1 -> V_29 ) )
V_4 = F_1 ( V_1 ) ;
goto V_28;
}
V_4 = F_19 ( V_1 -> V_8 , V_10 , V_11 ) ;
if ( V_4 )
return V_4 ;
if ( F_20 ( V_1 ) ) {
V_4 = F_21 ( V_1 -> V_18 ) ;
goto V_28;
}
V_21 = V_12 ? V_16 -> V_30 : V_16 -> V_31 ;
if ( V_17 -> V_32 & V_33 &&
! F_22 ( V_17 , V_21 ) )
V_22 = true ;
V_4 = F_23 ( V_17 , V_21 ) ;
if ( V_22 ) {
V_20 = F_24 ( V_1 -> V_18 -> V_34 , V_35 , NULL ) ;
if ( ! V_4 )
V_4 = V_20 ;
}
V_28:
F_25 ( V_1 , V_4 ) ;
return V_4 ;
}

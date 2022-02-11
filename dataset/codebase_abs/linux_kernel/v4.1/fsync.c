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
V_3 = F_3 ( F_6 ( V_2 -> V_6 ) ) ;
F_7 ( V_2 ) ;
if ( ! V_3 )
break;
F_8 ( V_1 ) ;
V_1 = V_3 ;
V_4 = F_9 ( V_1 -> V_7 ) ;
if ( V_4 )
break;
V_4 = F_10 ( V_1 , 1 ) ;
if ( V_4 )
break;
}
F_8 ( V_1 ) ;
return V_4 ;
}
int F_11 ( struct V_8 * V_8 , T_1 V_9 , T_1 V_10 , int V_11 )
{
struct V_1 * V_1 = V_8 -> V_12 -> V_13 ;
struct V_14 * V_15 = F_12 ( V_1 ) ;
T_2 * V_16 = F_13 ( V_1 -> V_17 ) -> V_18 ;
int V_4 = 0 , V_19 ;
T_3 V_20 ;
bool V_21 = false ;
F_14 ( F_15 () == NULL ) ;
F_16 ( V_8 , V_11 ) ;
if ( V_1 -> V_17 -> V_22 & V_23 ) {
F_17 () ;
if ( F_13 ( V_1 -> V_17 ) -> V_24 & V_25 )
V_4 = - V_26 ;
goto V_27;
}
if ( ! V_16 ) {
V_4 = F_18 ( V_8 , V_9 , V_10 , V_11 ) ;
if ( ! V_4 && ! F_19 ( & V_1 -> V_28 ) )
V_4 = F_1 ( V_1 ) ;
goto V_27;
}
V_4 = F_20 ( V_1 -> V_7 , V_9 , V_10 ) ;
if ( V_4 )
return V_4 ;
if ( F_21 ( V_1 ) ) {
V_4 = F_22 ( V_1 -> V_17 ) ;
goto V_27;
}
V_20 = V_11 ? V_15 -> V_29 : V_15 -> V_30 ;
if ( V_16 -> V_31 & V_32 &&
! F_23 ( V_16 , V_20 ) )
V_21 = true ;
V_4 = F_24 ( V_16 , V_20 ) ;
if ( V_21 ) {
V_19 = F_25 ( V_1 -> V_17 -> V_33 , V_34 , NULL ) ;
if ( ! V_4 )
V_4 = V_19 ;
}
V_27:
F_26 ( V_1 , V_4 ) ;
return V_4 ;
}

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
static int F_10 ( struct V_1 * V_1 , int V_9 )
{
int V_10 ;
int V_4 ;
V_4 = F_8 ( V_1 -> V_8 ) ;
if ( ! ( V_1 -> V_11 & V_12 ) )
return V_4 ;
if ( V_9 && ! ( V_1 -> V_11 & V_13 ) )
return V_4 ;
V_10 = F_9 ( V_1 , 1 ) ;
if ( V_4 == 0 )
V_4 = V_10 ;
return V_4 ;
}
int F_11 ( struct V_14 * V_14 , T_1 V_15 , T_1 V_16 , int V_9 )
{
struct V_1 * V_1 = V_14 -> V_17 -> V_18 ;
struct V_19 * V_20 = F_12 ( V_1 ) ;
T_2 * V_21 = F_13 ( V_1 -> V_22 ) -> V_23 ;
int V_4 , V_10 ;
T_3 V_24 ;
bool V_25 = false ;
F_14 ( F_15 () == NULL ) ;
F_16 ( V_14 , V_9 ) ;
V_4 = F_17 ( V_1 -> V_8 , V_15 , V_16 ) ;
if ( V_4 )
return V_4 ;
F_18 ( & V_1 -> V_26 ) ;
if ( V_1 -> V_22 -> V_27 & V_28 )
goto V_29;
V_4 = F_19 ( V_1 ) ;
if ( V_4 < 0 )
goto V_29;
if ( ! V_21 ) {
V_4 = F_10 ( V_1 , V_9 ) ;
if ( ! V_4 && ! F_20 ( & V_1 -> V_30 ) )
V_4 = F_1 ( V_1 ) ;
goto V_29;
}
if ( F_21 ( V_1 ) ) {
V_4 = F_22 ( V_1 -> V_22 ) ;
goto V_29;
}
V_24 = V_9 ? V_20 -> V_31 : V_20 -> V_32 ;
if ( V_21 -> V_33 & V_34 &&
! F_23 ( V_21 , V_24 ) )
V_25 = true ;
F_24 ( V_21 , V_24 ) ;
V_4 = F_25 ( V_21 , V_24 ) ;
if ( V_25 ) {
V_10 = F_26 ( V_1 -> V_22 -> V_35 , V_36 , NULL ) ;
if ( ! V_4 )
V_4 = V_10 ;
}
V_29:
F_27 ( & V_1 -> V_26 ) ;
F_28 ( V_1 , V_4 ) ;
return V_4 ;
}

static int F_1 ( struct V_1 * V_1 )
{
struct V_2 V_3 ;
struct V_4 * V_4 = NULL ;
struct V_1 * V_5 ;
int V_6 = 0 ;
if ( ! F_2 ( V_1 , V_7 ) )
return 0 ;
V_1 = F_3 ( V_1 ) ;
while ( F_2 ( V_1 , V_7 ) ) {
F_4 ( V_1 , V_7 ) ;
V_4 = F_5 ( V_1 ) ;
if ( ! V_4 )
break;
V_5 = F_3 ( V_4 -> V_8 -> V_9 ) ;
F_6 ( V_4 ) ;
if ( ! V_5 )
break;
F_7 ( V_1 ) ;
V_1 = V_5 ;
V_6 = F_8 ( V_1 -> V_10 ) ;
if ( V_6 )
break;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_11 = V_12 ;
V_3 . V_13 = 0 ;
V_6 = F_9 ( V_1 , & V_3 ) ;
if ( V_6 )
break;
}
F_7 ( V_1 ) ;
return V_6 ;
}
static int F_10 ( struct V_1 * V_1 , int V_14 )
{
int V_15 ;
int V_6 ;
V_6 = F_8 ( V_1 -> V_10 ) ;
if ( ! ( V_1 -> V_16 & V_17 ) )
return V_6 ;
if ( V_14 && ! ( V_1 -> V_16 & V_18 ) )
return V_6 ;
V_15 = F_11 ( V_1 , 1 ) ;
if ( V_6 == 0 )
V_6 = V_15 ;
return V_6 ;
}
int F_12 ( struct V_19 * V_19 , T_1 V_20 , T_1 V_21 , int V_14 )
{
struct V_1 * V_1 = V_19 -> V_22 -> V_23 ;
struct V_24 * V_25 = F_13 ( V_1 ) ;
T_2 * V_26 = F_14 ( V_1 -> V_27 ) -> V_28 ;
int V_6 , V_15 ;
T_3 V_29 ;
bool V_30 = false ;
F_15 ( F_16 () == NULL ) ;
F_17 ( V_19 , V_14 ) ;
V_6 = F_18 ( V_1 -> V_10 , V_20 , V_21 ) ;
if ( V_6 )
return V_6 ;
F_19 ( & V_1 -> V_31 ) ;
if ( V_1 -> V_27 -> V_32 & V_33 )
goto V_34;
V_6 = F_20 ( V_1 ) ;
if ( V_6 < 0 )
goto V_34;
if ( ! V_26 ) {
V_6 = F_10 ( V_1 , V_14 ) ;
if ( ! V_6 && ! F_21 ( & V_1 -> V_35 ) )
V_6 = F_1 ( V_1 ) ;
goto V_34;
}
if ( F_22 ( V_1 ) ) {
V_6 = F_23 ( V_1 -> V_27 ) ;
goto V_34;
}
V_29 = V_14 ? V_25 -> V_36 : V_25 -> V_37 ;
if ( V_26 -> V_38 & V_39 &&
! F_24 ( V_26 , V_29 ) )
V_30 = true ;
F_25 ( V_26 , V_29 ) ;
V_6 = F_26 ( V_26 , V_29 ) ;
if ( V_30 ) {
V_15 = F_27 ( V_1 -> V_27 -> V_40 , V_41 , NULL ) ;
if ( ! V_6 )
V_6 = V_15 ;
}
V_34:
F_28 ( & V_1 -> V_31 ) ;
F_29 ( V_1 , V_6 ) ;
return V_6 ;
}

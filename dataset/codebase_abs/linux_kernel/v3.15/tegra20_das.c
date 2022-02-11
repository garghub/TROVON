static inline void F_1 ( T_1 V_1 , T_1 V_2 )
{
F_2 ( V_3 -> V_4 , V_1 , V_2 ) ;
}
static inline T_1 F_3 ( T_1 V_1 )
{
T_1 V_2 ;
F_4 ( V_3 -> V_4 , V_1 , & V_2 ) ;
return V_2 ;
}
int F_5 ( int V_5 , int V_6 )
{
T_1 V_7 ;
T_1 V_1 ;
if ( ! V_3 )
return - V_8 ;
V_7 = V_9 +
( V_5 * V_10 ) ;
V_1 = V_6 << V_11 ;
F_1 ( V_7 , V_1 ) ;
return 0 ;
}
int F_6 ( int V_5 , int V_12 , int V_13 ,
int V_14 , int V_15 )
{
T_1 V_7 ;
T_1 V_1 ;
if ( ! V_3 )
return - V_8 ;
V_7 = V_9 +
( V_5 * V_10 ) ;
V_1 = V_12 << V_11 |
! ! V_15 << V_16 |
! ! V_14 << V_17 |
! ! V_13 << V_18 ;
F_1 ( V_7 , V_1 ) ;
return 0 ;
}
int F_7 ( int V_6 , int V_5 )
{
T_1 V_7 ;
T_1 V_1 ;
if ( ! V_3 )
return - V_8 ;
V_7 = V_19 +
( V_6 * V_20 ) ;
V_1 = V_5 << V_21 |
V_5 << V_22 |
V_5 << V_23 ;
F_1 ( V_7 , V_1 ) ;
return 0 ;
}
static bool F_8 ( struct V_24 * V_25 , unsigned int V_1 )
{
if ( ( V_1 >= V_9 ) &&
( V_1 <= F_9 ( V_26 ) ) )
return true ;
if ( ( V_1 >= V_19 ) &&
( V_1 <= F_9 ( V_27 ) ) )
return true ;
return false ;
}
static int F_10 ( struct V_28 * V_29 )
{
struct V_30 * V_31 , * V_32 ;
void T_2 * V_33 ;
int V_34 = 0 ;
if ( V_3 )
return - V_8 ;
V_3 = F_11 ( & V_29 -> V_25 , sizeof( struct V_35 ) , V_36 ) ;
if ( ! V_3 ) {
F_12 ( & V_29 -> V_25 , L_1 ) ;
V_34 = - V_37 ;
goto V_38;
}
V_3 -> V_25 = & V_29 -> V_25 ;
V_31 = F_13 ( V_29 , V_39 , 0 ) ;
if ( ! V_31 ) {
F_12 ( & V_29 -> V_25 , L_2 ) ;
V_34 = - V_8 ;
goto V_38;
}
V_32 = F_14 ( & V_29 -> V_25 , V_31 -> V_40 ,
F_15 ( V_31 ) , V_29 -> V_41 ) ;
if ( ! V_32 ) {
F_12 ( & V_29 -> V_25 , L_3 ) ;
V_34 = - V_42 ;
goto V_38;
}
V_33 = F_16 ( & V_29 -> V_25 , V_31 -> V_40 , F_15 ( V_31 ) ) ;
if ( ! V_33 ) {
F_12 ( & V_29 -> V_25 , L_4 ) ;
V_34 = - V_37 ;
goto V_38;
}
V_3 -> V_4 = F_17 ( & V_29 -> V_25 , V_33 ,
& V_43 ) ;
if ( F_18 ( V_3 -> V_4 ) ) {
F_12 ( & V_29 -> V_25 , L_5 ) ;
V_34 = F_19 ( V_3 -> V_4 ) ;
goto V_38;
}
V_34 = F_5 ( V_44 ,
V_45 ) ;
if ( V_34 ) {
F_12 ( & V_29 -> V_25 , L_6 ) ;
goto V_38;
}
V_34 = F_7 ( V_46 ,
V_47 ) ;
if ( V_34 ) {
F_12 ( & V_29 -> V_25 , L_7 ) ;
goto V_38;
}
V_34 = F_5 ( V_48 ,
V_49 ) ;
if ( V_34 ) {
F_12 ( & V_29 -> V_25 , L_6 ) ;
goto V_38;
}
V_34 = F_7 ( V_50 ,
V_51 ) ;
if ( V_34 ) {
F_12 ( & V_29 -> V_25 , L_7 ) ;
goto V_38;
}
F_20 ( V_29 , V_3 ) ;
return 0 ;
V_38:
V_3 = NULL ;
return V_34 ;
}
static int F_21 ( struct V_28 * V_29 )
{
if ( ! V_3 )
return - V_8 ;
V_3 = NULL ;
return 0 ;
}

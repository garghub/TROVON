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
struct V_30 * V_31 ;
void T_2 * V_32 ;
int V_33 = 0 ;
if ( V_3 )
return - V_8 ;
V_3 = F_11 ( & V_29 -> V_25 , sizeof( struct V_34 ) , V_35 ) ;
if ( ! V_3 ) {
V_33 = - V_36 ;
goto V_37;
}
V_3 -> V_25 = & V_29 -> V_25 ;
V_31 = F_12 ( V_29 , V_38 , 0 ) ;
V_32 = F_13 ( & V_29 -> V_25 , V_31 ) ;
if ( F_14 ( V_32 ) ) {
V_33 = F_15 ( V_32 ) ;
goto V_37;
}
V_3 -> V_4 = F_16 ( & V_29 -> V_25 , V_32 ,
& V_39 ) ;
if ( F_14 ( V_3 -> V_4 ) ) {
F_17 ( & V_29 -> V_25 , L_1 ) ;
V_33 = F_15 ( V_3 -> V_4 ) ;
goto V_37;
}
V_33 = F_5 ( V_40 ,
V_41 ) ;
if ( V_33 ) {
F_17 ( & V_29 -> V_25 , L_2 ) ;
goto V_37;
}
V_33 = F_7 ( V_42 ,
V_43 ) ;
if ( V_33 ) {
F_17 ( & V_29 -> V_25 , L_3 ) ;
goto V_37;
}
V_33 = F_5 ( V_44 ,
V_45 ) ;
if ( V_33 ) {
F_17 ( & V_29 -> V_25 , L_2 ) ;
goto V_37;
}
V_33 = F_7 ( V_46 ,
V_47 ) ;
if ( V_33 ) {
F_17 ( & V_29 -> V_25 , L_3 ) ;
goto V_37;
}
F_18 ( V_29 , V_3 ) ;
return 0 ;
V_37:
V_3 = NULL ;
return V_33 ;
}
static int F_19 ( struct V_28 * V_29 )
{
if ( ! V_3 )
return - V_8 ;
V_3 = NULL ;
return 0 ;
}

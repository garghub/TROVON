static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
unsigned int V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , V_2 -> V_8 + V_3 , & V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_4 = V_5 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
return F_4 ( V_2 -> V_7 , V_2 -> V_8 + V_3 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
unsigned int V_9 ;
int V_6 ;
T_2 V_10 = 0 ;
V_6 = F_1 ( V_2 , V_11 , & V_10 ) ;
if ( V_6 < 0 )
return V_6 ;
V_9 = V_10 & V_12 ;
if ( V_9 > V_2 -> V_9 ) {
V_2 -> V_13 = ( V_9 - 1 ) * V_14 +
V_2 -> V_15 * V_16 +
V_17 + V_18 ;
} else if ( V_9 < V_2 -> V_9 ) {
V_2 -> V_13 = V_9 * V_14 +
V_2 -> V_15 * V_16 -
V_17 + V_18 ;
}
V_2 -> V_9 = V_9 ;
return 0 ;
}
static int F_6 ( void * V_4 , int * V_13 )
{
struct V_1 * V_2 = V_4 ;
int V_6 , V_19 ;
if ( ! V_13 )
return - V_20 ;
if ( F_7 ( V_2 -> V_21 ) ) {
V_6 = F_5 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
} else {
V_6 = F_8 ( V_2 -> V_21 , & V_19 ) ;
if ( V_6 < 0 )
return V_6 ;
V_2 -> V_13 = V_19 ;
}
* V_13 = V_2 -> V_13 < 0 ? 0 : V_2 -> V_13 ;
return 0 ;
}
static T_3 F_9 ( int V_22 , void * V_4 )
{
struct V_1 * V_2 = V_4 ;
F_10 ( V_2 -> V_23 , V_24 ) ;
return V_25 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_6 ;
T_2 V_10 ;
V_2 -> V_15 = V_26 ;
V_2 -> V_13 = V_27 ;
V_6 = F_1 ( V_2 , V_11 , & V_10 ) ;
if ( V_6 < 0 )
return V_6 ;
V_2 -> V_9 = V_10 & V_12 ;
if ( V_2 -> V_9 )
V_2 -> V_13 = V_2 -> V_15 * V_16 +
( V_2 -> V_9 - 1 ) * V_14 +
V_18 ;
V_10 = V_2 -> V_15 & V_28 ;
V_6 = F_3 ( V_2 , V_29 , V_10 ) ;
if ( V_6 < 0 )
return V_6 ;
V_10 = V_30 ;
V_6 = F_3 ( V_2 , V_31 , V_10 ) ;
return V_6 ;
}
static int F_12 ( struct V_32 * V_33 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 ;
T_2 type , V_36 ;
T_4 V_37 [ 2 ] ;
int V_6 , V_22 ;
V_35 = V_33 -> V_38 . V_39 ;
V_2 = F_13 ( & V_33 -> V_38 , sizeof( * V_2 ) , V_40 ) ;
if ( ! V_2 )
return - V_41 ;
F_14 ( & V_33 -> V_38 , V_2 ) ;
V_2 -> V_7 = F_15 ( V_33 -> V_38 . V_42 , NULL ) ;
if ( ! V_2 -> V_7 )
return - V_43 ;
V_6 = F_16 ( V_35 , L_1 , V_37 , 2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_22 = F_17 ( V_33 , 0 ) ;
if ( V_22 < 0 )
return V_22 ;
V_2 -> V_21 = F_18 ( & V_33 -> V_38 , L_2 ) ;
if ( F_19 ( V_2 -> V_21 ) == - V_44 )
return F_19 ( V_2 -> V_21 ) ;
V_2 -> V_8 = V_37 [ 0 ] ;
V_6 = F_1 ( V_2 , V_45 , & type ) ;
if ( V_6 < 0 ) {
F_20 ( & V_33 -> V_38 , L_3 ) ;
goto V_46;
}
V_6 = F_1 ( V_2 , V_47 , & V_36 ) ;
if ( V_6 < 0 ) {
F_20 ( & V_33 -> V_38 , L_4 ) ;
goto V_46;
}
if ( type != V_48 || V_36 != V_49 ) {
F_20 ( & V_33 -> V_38 , L_5 ,
type , V_36 ) ;
V_6 = - V_50 ;
goto V_46;
}
V_6 = F_11 ( V_2 ) ;
if ( V_6 < 0 ) {
F_20 ( & V_33 -> V_38 , L_6 ) ;
goto V_46;
}
V_6 = F_21 ( & V_33 -> V_38 , V_22 , NULL , F_9 ,
V_51 , V_35 -> V_52 , V_2 ) ;
if ( V_6 < 0 )
goto V_46;
V_2 -> V_23 = F_22 ( & V_33 -> V_38 , 0 , V_2 ,
& V_53 ) ;
if ( F_7 ( V_2 -> V_23 ) ) {
F_20 ( & V_33 -> V_38 , L_7 ) ;
V_6 = F_19 ( V_2 -> V_23 ) ;
goto V_46;
}
return 0 ;
V_46:
if ( ! F_7 ( V_2 -> V_21 ) )
F_23 ( V_2 -> V_21 ) ;
return V_6 ;
}
static int F_24 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_25 ( & V_33 -> V_38 ) ;
if ( ! F_7 ( V_2 -> V_21 ) )
F_23 ( V_2 -> V_21 ) ;
return 0 ;
}

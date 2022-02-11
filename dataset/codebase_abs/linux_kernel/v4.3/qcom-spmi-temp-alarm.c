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
F_10 ( V_2 -> V_23 ) ;
return V_24 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_6 ;
T_2 V_10 ;
V_2 -> V_15 = V_25 ;
V_2 -> V_13 = V_26 ;
V_6 = F_1 ( V_2 , V_11 , & V_10 ) ;
if ( V_6 < 0 )
return V_6 ;
V_2 -> V_9 = V_10 & V_12 ;
if ( V_2 -> V_9 )
V_2 -> V_13 = V_2 -> V_15 * V_16 +
( V_2 -> V_9 - 1 ) * V_14 +
V_18 ;
V_10 = V_2 -> V_15 & V_27 ;
V_6 = F_3 ( V_2 , V_28 , V_10 ) ;
if ( V_6 < 0 )
return V_6 ;
V_10 = V_29 ;
V_6 = F_3 ( V_2 , V_30 , V_10 ) ;
return V_6 ;
}
static int F_12 ( struct V_31 * V_32 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 ;
T_2 type , V_35 ;
T_4 V_36 [ 2 ] ;
int V_6 , V_22 ;
V_34 = V_32 -> V_37 . V_38 ;
V_2 = F_13 ( & V_32 -> V_37 , sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 )
return - V_40 ;
F_14 ( & V_32 -> V_37 , V_2 ) ;
V_2 -> V_7 = F_15 ( V_32 -> V_37 . V_41 , NULL ) ;
if ( ! V_2 -> V_7 )
return - V_42 ;
V_6 = F_16 ( V_34 , L_1 , V_36 , 2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_22 = F_17 ( V_32 , 0 ) ;
if ( V_22 < 0 )
return V_22 ;
V_2 -> V_21 = F_18 ( & V_32 -> V_37 , L_2 ) ;
if ( F_19 ( V_2 -> V_21 ) == - V_43 )
return F_19 ( V_2 -> V_21 ) ;
V_2 -> V_8 = V_36 [ 0 ] ;
V_6 = F_1 ( V_2 , V_44 , & type ) ;
if ( V_6 < 0 ) {
F_20 ( & V_32 -> V_37 , L_3 ) ;
goto V_45;
}
V_6 = F_1 ( V_2 , V_46 , & V_35 ) ;
if ( V_6 < 0 ) {
F_20 ( & V_32 -> V_37 , L_4 ) ;
goto V_45;
}
if ( type != V_47 || V_35 != V_48 ) {
F_20 ( & V_32 -> V_37 , L_5 ,
type , V_35 ) ;
V_6 = - V_49 ;
goto V_45;
}
V_6 = F_11 ( V_2 ) ;
if ( V_6 < 0 ) {
F_20 ( & V_32 -> V_37 , L_6 ) ;
goto V_45;
}
V_6 = F_21 ( & V_32 -> V_37 , V_22 , NULL , F_9 ,
V_50 , V_34 -> V_51 , V_2 ) ;
if ( V_6 < 0 )
goto V_45;
V_2 -> V_23 = F_22 ( & V_32 -> V_37 , 0 , V_2 ,
& V_52 ) ;
if ( F_7 ( V_2 -> V_23 ) ) {
F_20 ( & V_32 -> V_37 , L_7 ) ;
V_6 = F_19 ( V_2 -> V_23 ) ;
goto V_45;
}
return 0 ;
V_45:
if ( ! F_7 ( V_2 -> V_21 ) )
F_23 ( V_2 -> V_21 ) ;
return V_6 ;
}
static int F_24 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_25 ( & V_32 -> V_37 ) ;
F_26 ( & V_32 -> V_37 , V_2 -> V_23 ) ;
if ( ! F_7 ( V_2 -> V_21 ) )
F_23 ( V_2 -> V_21 ) ;
return 0 ;
}

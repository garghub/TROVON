static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
int V_5 )
{
F_2 ( V_2 -> V_6 , V_3 , V_4 , V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
int V_5 )
{
F_4 ( V_2 -> V_6 , V_3 , V_4 , V_5 ) ;
}
static T_1 F_5 ( struct V_7 * V_8 ,
struct V_1 * V_2 ,
void * V_9 ,
T_2 V_4 ,
int V_5
)
{
T_1 V_10 = 0 ;
struct V_11 * V_12 ;
V_12 = F_6 ( sizeof( struct V_11 ) , V_13 ) ;
if ( ! V_12 )
return 0 ;
V_10 = F_7 ( V_2 -> V_6 , V_9 , V_4 , V_5 ) ;
V_12 -> V_5 = V_5 ;
if ( F_8 ( V_2 -> V_6 , V_10 ) ) {
F_9 ( V_12 ) ;
return 0 ;
}
V_12 -> V_14 = V_10 ;
V_12 -> V_6 = V_2 -> V_6 ;
V_12 -> V_4 = V_4 ;
F_10 ( & V_12 -> V_15 , & V_8 -> V_16 ) ;
return V_10 ;
}
static void F_11 ( struct V_11 * V_17 )
{
F_12 ( V_17 -> V_6 ,
V_17 -> V_14 ,
V_17 -> V_4 ,
V_17 -> V_5 ) ;
}
static int F_13 ( struct V_18 * V_19 )
{
struct V_20 * V_6 = & V_19 -> V_6 ;
struct V_1 * V_21 ;
int V_22 = 0 ;
int V_23 ;
V_21 = F_14 ( NULL , V_6 , & V_24 ) ;
if ( ! V_21 )
return - V_25 ;
F_15 ( V_6 , V_21 ) ;
V_22 = F_16 ( V_6 -> V_26 , 0 , & V_21 -> V_27 ) ;
if ( V_22 ) {
F_17 ( V_21 -> V_6 ,
L_1 ) ;
goto V_28;
}
if ( ! F_18 ( V_21 -> V_27 . V_29 ,
F_19 ( & V_21 -> V_27 ) , V_30 ) ) {
F_20 ( V_21 -> V_6 ,
L_2 ) ;
V_22 = - V_31 ;
goto V_28;
}
V_21 -> V_32 = F_21 ( V_6 -> V_26 , 0 ) ;
if ( ! V_21 -> V_32 ) {
F_20 ( V_21 -> V_6 ,
L_3 ) ;
goto V_33;
}
V_23 = F_22 ( V_6 -> V_26 , 0 ) ;
V_22 = F_23 ( V_23 , V_34 , 0 , V_30 , V_21 ) ;
if ( V_22 ) {
F_20 ( V_21 -> V_6 ,
L_4 ) ;
V_22 = - V_35 ;
goto V_36;
}
V_22 = F_24 ( V_21 ) ;
if ( ! V_22 )
return 0 ;
F_25 ( V_23 , V_21 ) ;
V_36:
F_26 ( V_21 -> V_32 ) ;
V_33:
F_27 ( V_21 -> V_27 . V_29 ,
F_19 ( & V_21 -> V_27 ) ) ;
V_28:
F_28 ( & V_21 -> V_37 , V_21 ) ;
F_9 ( V_21 ) ;
return V_22 ;
}
static int F_29 ( struct V_18 * V_19 )
{
struct V_20 * V_6 = & V_19 -> V_6 ;
struct V_1 * V_21 = F_30 ( V_6 ) ;
int V_23 = F_22 ( V_6 -> V_26 , 0 ) ;
F_31 ( V_21 ) ;
F_25 ( V_23 , V_21 ) ;
F_26 ( V_21 -> V_32 ) ;
F_27 ( V_21 -> V_27 . V_29 ,
F_19 ( & V_21 -> V_27 ) ) ;
F_28 ( & V_21 -> V_37 , V_21 ) ;
F_9 ( V_21 ) ;
return 0 ;
}

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
static void F_5 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
int V_5 )
{
}
static T_1 F_6 ( struct V_7 * V_8 ,
struct V_1 * V_2 ,
void * V_9 ,
T_2 V_4 ,
int V_5
)
{
T_1 V_10 = 0 ;
struct V_11 * V_12 ;
V_12 = F_7 ( sizeof( struct V_11 ) , V_13 ) ;
if ( ! V_12 )
return 0 ;
V_10 = F_8 ( V_2 -> V_6 , V_9 , V_4 , V_5 ) ;
V_12 -> V_5 = V_5 ;
if ( F_9 ( V_2 -> V_6 , V_10 ) ) {
F_10 ( V_12 ) ;
return 0 ;
}
V_12 -> V_14 = V_10 ;
V_12 -> V_6 = V_2 -> V_6 ;
V_12 -> V_4 = V_4 ;
F_11 ( & V_12 -> V_15 , & V_8 -> V_16 ) ;
return V_10 ;
}
static void F_12 ( struct V_11 * V_17 )
{
F_13 ( V_17 -> V_6 ,
V_17 -> V_14 ,
V_17 -> V_4 ,
V_17 -> V_5 ) ;
}
static int F_14 ( struct V_18 * V_19 )
{
struct V_20 * V_6 = & V_19 -> V_6 ;
struct V_1 * V_21 ;
int V_22 = 0 ;
int V_23 ;
struct V_24 * V_25 = & V_26 ;
if ( F_15 ( V_6 -> V_27 , L_1 ) )
V_25 = & V_28 ;
V_21 = F_16 ( NULL , V_6 , V_25 ) ;
if ( ! V_21 )
return - V_29 ;
F_17 ( V_6 , V_21 ) ;
V_22 = F_18 ( V_6 -> V_27 , 0 , & V_21 -> V_30 ) ;
if ( V_22 ) {
F_19 ( V_21 -> V_6 ,
L_2 ) ;
goto V_31;
}
if ( ! F_20 ( V_21 -> V_30 . V_32 ,
F_21 ( & V_21 -> V_30 ) , V_33 ) ) {
F_22 ( V_21 -> V_6 ,
L_3 ) ;
V_22 = - V_34 ;
goto V_31;
}
V_21 -> V_35 = F_23 ( V_6 -> V_27 , 0 ) ;
if ( ! V_21 -> V_35 ) {
F_22 ( V_21 -> V_6 ,
L_4 ) ;
V_22 = - V_36 ;
goto V_37;
}
V_23 = F_24 ( V_6 -> V_27 , 0 ) ;
V_22 = F_25 ( V_23 , V_38 , 0 , V_33 , V_21 ) ;
if ( V_22 ) {
F_22 ( V_21 -> V_6 ,
L_5 ) ;
V_22 = - V_39 ;
goto V_40;
}
V_22 = F_26 ( V_21 ) ;
if ( ! V_22 )
return 0 ;
F_27 ( V_23 , V_21 ) ;
V_40:
F_28 ( V_21 -> V_35 ) ;
V_37:
F_29 ( V_21 -> V_30 . V_32 ,
F_21 ( & V_21 -> V_30 ) ) ;
V_31:
F_30 ( & V_21 -> V_41 , V_21 ) ;
F_10 ( V_21 ) ;
return V_22 ;
}
static int F_31 ( struct V_18 * V_19 )
{
struct V_20 * V_6 = & V_19 -> V_6 ;
struct V_1 * V_21 = F_32 ( V_6 ) ;
int V_23 = F_24 ( V_6 -> V_27 , 0 ) ;
F_33 ( V_21 ) ;
F_27 ( V_23 , V_21 ) ;
F_28 ( V_21 -> V_35 ) ;
F_29 ( V_21 -> V_30 . V_32 ,
F_21 ( & V_21 -> V_30 ) ) ;
F_30 ( & V_21 -> V_41 , V_21 ) ;
F_10 ( V_21 ) ;
return 0 ;
}

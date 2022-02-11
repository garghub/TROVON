static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_7 * V_8 ;
T_1 V_9 , V_10 ;
V_8 = F_3 ( sizeof( * V_8 ) , V_11 ) ;
if ( ! V_8 )
return - V_12 ;
V_9 = V_13 * V_14 ;
V_10 = ( V_5 -> V_15 . V_16 >> V_17 ) - V_9 ;
F_4 ( & V_8 -> V_18 , V_9 , V_10 ) ;
F_5 ( & V_8 -> V_19 ) ;
F_6 ( & V_8 -> V_20 , V_3 ) ;
V_2 -> V_21 = V_8 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_21 ;
F_8 ( & V_8 -> V_19 ) ;
if ( ! F_9 ( & V_8 -> V_18 ) ) {
F_10 ( & V_8 -> V_19 ) ;
return - V_22 ;
}
F_11 ( & V_8 -> V_18 ) ;
F_10 ( & V_8 -> V_19 ) ;
F_12 ( V_8 ) ;
V_2 -> V_21 = NULL ;
return 0 ;
}
bool F_13 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = V_24 -> V_27 ;
return ( V_26 -> V_9 != V_28 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
const struct V_31 * V_32 ,
struct V_23 * V_24 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_7 * V_8 = V_2 -> V_21 ;
struct V_25 * V_26 = V_24 -> V_27 ;
enum V_33 V_34 ;
unsigned long V_35 , V_36 ;
int V_37 ;
if ( F_13 ( V_24 ) )
return 0 ;
if ( V_32 )
V_35 = V_32 -> V_35 ;
else
V_35 = 0 ;
if ( V_32 && V_32 -> V_36 )
V_36 = V_32 -> V_36 ;
else
V_36 = V_5 -> V_38 . V_39 ;
V_34 = V_40 ;
if ( V_32 && V_32 -> V_41 & V_42 )
V_34 = V_43 ;
F_8 ( & V_8 -> V_19 ) ;
V_37 = F_15 ( & V_8 -> V_18 , V_26 ,
V_24 -> V_44 , V_24 -> V_45 , 0 ,
V_35 , V_36 , V_34 ) ;
F_10 ( & V_8 -> V_19 ) ;
if ( ! V_37 )
V_24 -> V_9 = V_26 -> V_9 ;
return V_37 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
const struct V_31 * V_32 ,
struct V_23 * V_24 )
{
struct V_7 * V_8 = V_2 -> V_21 ;
struct V_25 * V_26 ;
int V_37 ;
F_8 ( & V_8 -> V_19 ) ;
if ( F_17 ( & V_8 -> V_20 ) < V_24 -> V_44 ) {
F_10 ( & V_8 -> V_19 ) ;
return 0 ;
}
F_18 ( V_24 -> V_44 , & V_8 -> V_20 ) ;
F_10 ( & V_8 -> V_19 ) ;
V_26 = F_3 ( sizeof( * V_26 ) , V_11 ) ;
if ( ! V_26 ) {
V_37 = - V_12 ;
goto V_46;
}
V_26 -> V_9 = V_28 ;
V_26 -> V_10 = V_24 -> V_44 ;
V_24 -> V_27 = V_26 ;
if ( V_32 -> V_35 || V_32 -> V_36 || V_32 -> V_41 & V_42 ) {
V_37 = F_14 ( V_2 , V_30 , V_32 , V_24 ) ;
if ( F_19 ( V_37 ) ) {
F_12 ( V_26 ) ;
V_24 -> V_27 = NULL ;
V_37 = 0 ;
goto V_46;
}
} else {
V_24 -> V_9 = V_26 -> V_9 ;
}
return 0 ;
V_46:
F_20 ( V_24 -> V_44 , & V_8 -> V_20 ) ;
return V_37 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_7 * V_8 = V_2 -> V_21 ;
struct V_25 * V_26 = V_24 -> V_27 ;
if ( ! V_26 )
return;
F_8 ( & V_8 -> V_19 ) ;
if ( V_26 -> V_9 != V_28 )
F_22 ( V_26 ) ;
F_10 ( & V_8 -> V_19 ) ;
F_20 ( V_24 -> V_44 , & V_8 -> V_20 ) ;
F_12 ( V_26 ) ;
V_24 -> V_27 = NULL ;
}
T_1 F_23 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_21 ;
return ( V_47 ) ( V_2 -> V_10 - F_17 ( & V_8 -> V_20 ) ) * V_48 ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_7 * V_8 = V_2 -> V_21 ;
F_8 ( & V_8 -> V_19 ) ;
F_25 ( & V_8 -> V_18 , V_50 ) ;
F_10 ( & V_8 -> V_19 ) ;
F_26 ( V_50 , L_1 ,
V_2 -> V_10 , ( V_47 ) F_17 ( & V_8 -> V_20 ) ,
F_23 ( V_2 ) >> 20 ) ;
}

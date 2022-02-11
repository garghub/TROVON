static bool F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return V_3 < V_4 ;
}
static bool F_2 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return ( V_3 >= V_5 && V_3 < V_6 ) ;
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
return ( F_1 ( V_2 , V_3 ) ||
F_2 ( V_2 , V_3 ) ) ;
}
static bool F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
return ( V_3 == V_7 || V_3 == V_8 ||
V_3 == V_9 ) ;
}
static bool F_5 ( struct V_1 * V_2 , unsigned int V_3 )
{
return ( V_3 == V_5 ||
V_3 == V_10 ||
V_3 == V_11 ) ;
}
static bool F_6 ( struct V_1 * V_2 , unsigned int V_3 )
{
return ( F_4 ( V_2 , V_3 ) ||
F_5 ( V_2 , V_3 ) ) ;
}
static bool F_7 ( struct V_1 * V_2 , unsigned int V_3 )
{
return ( F_6 ( V_2 , V_3 ) ||
V_3 == V_12 || V_3 == V_13 ||
V_3 == V_14 ) ;
}
static bool F_8 ( struct V_1 * V_2 , unsigned int V_3 )
{
return ( F_5 ( V_2 , V_3 ) ||
V_3 == V_15 ||
V_3 == V_16 ||
V_3 == V_17 ||
V_3 == V_18 ||
V_3 == V_19 ||
V_3 == V_20 ||
V_3 == V_21 ) ;
}
static bool F_9 ( struct V_1 * V_2 , unsigned int V_3 )
{
return ( F_7 ( V_2 , V_3 ) ||
F_8 ( V_2 , V_3 ) ) ;
}
static int F_10 ( struct V_22 * V_23 ,
const struct V_24 * V_25 )
{
struct V_26 * V_27 = NULL ;
const struct V_28 * V_29 ;
unsigned int V_30 ;
int V_31 = 0 ;
const struct V_32 * V_33 ;
const struct V_34 * V_35 ;
const struct V_36 * V_37 ;
int V_38 ;
V_27 = F_11 ( & V_23 -> V_2 ,
sizeof( struct V_26 ) , V_39 ) ;
if ( ! V_27 )
return - V_40 ;
if ( V_23 -> V_2 . V_41 ) {
V_29 = F_12 ( V_42 , V_23 -> V_2 . V_41 ) ;
if ( ! V_29 )
return - V_43 ;
V_27 -> type = ( unsigned long ) V_29 -> V_30 ;
} else
V_27 -> type = V_25 -> V_44 ;
F_13 ( V_23 , V_27 ) ;
V_27 -> V_2 = & V_23 -> V_2 ;
V_27 -> V_23 = V_23 ;
V_27 -> V_45 = V_23 -> V_45 ;
if ( V_27 -> type == V_46 ) {
V_33 = & V_47 ;
V_35 = & V_48 ;
V_37 = V_49 ;
V_38 = F_14 ( V_49 ) ;
} else {
V_33 = & V_50 ;
V_35 = & V_51 ;
V_37 = V_52 ;
V_38 = F_14 ( V_52 ) ;
}
V_27 -> V_53 = F_15 ( V_23 , V_33 ) ;
if ( F_16 ( V_27 -> V_53 ) ) {
V_31 = F_17 ( V_27 -> V_53 ) ;
F_18 ( V_27 -> V_2 , L_1 ,
V_31 ) ;
return V_31 ;
}
V_31 = F_19 ( V_27 -> V_53 , V_54 , & V_30 ) ;
if ( V_31 < 0 ) {
F_18 ( V_27 -> V_2 ,
L_2 ) ;
return - V_55 ;
}
V_31 = F_20 ( V_27 -> V_53 , V_27 -> V_45 ,
V_56 | V_57 |
V_58 , 0 , V_35 ,
& V_27 -> V_59 ) ;
if ( V_31 < 0 ) {
F_18 ( & V_23 -> V_2 , L_3 , V_31 ) ;
return V_31 ;
}
V_31 = F_21 ( V_27 -> V_2 , - 1 , V_37 , V_38 , NULL , 0 , NULL ) ;
if ( V_31 < 0 ) {
F_18 ( & V_23 -> V_2 , L_4 , V_31 ) ;
goto V_60;
}
return 0 ;
V_60:
F_22 ( V_27 -> V_45 , V_27 -> V_59 ) ;
return V_31 ;
}
static int F_23 ( struct V_22 * V_23 )
{
struct V_26 * V_27 = F_24 ( V_23 ) ;
F_25 ( V_27 -> V_2 ) ;
F_22 ( V_27 -> V_45 , V_27 -> V_59 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_27 ( V_2 ) ;
struct V_26 * V_27 = F_24 ( V_23 ) ;
if ( F_28 ( V_2 ) )
F_29 ( V_27 -> V_45 ) ;
F_30 ( V_27 -> V_45 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_27 ( V_2 ) ;
struct V_26 * V_27 = F_24 ( V_23 ) ;
if ( F_28 ( V_2 ) )
F_32 ( V_27 -> V_45 ) ;
F_33 ( V_27 -> V_45 ) ;
return 0 ;
}
static int T_1 F_34 ( void )
{
return F_35 ( & V_61 ) ;
}
static void T_2 F_36 ( void )
{
F_37 ( & V_61 ) ;
}

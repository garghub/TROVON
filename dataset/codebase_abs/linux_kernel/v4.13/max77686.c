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
static int F_10 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = NULL ;
unsigned int V_26 ;
int V_27 = 0 ;
const struct V_28 * V_29 ;
const struct V_30 * V_31 ;
const struct V_32 * V_33 ;
int V_34 ;
V_25 = F_11 ( & V_23 -> V_2 ,
sizeof( struct V_24 ) , V_35 ) ;
if ( ! V_25 )
return - V_36 ;
F_12 ( V_23 , V_25 ) ;
V_25 -> type = ( unsigned long ) F_13 ( & V_23 -> V_2 ) ;
V_25 -> V_2 = & V_23 -> V_2 ;
V_25 -> V_23 = V_23 ;
V_25 -> V_37 = V_23 -> V_37 ;
if ( V_25 -> type == V_38 ) {
V_29 = & V_39 ;
V_31 = & V_40 ;
V_33 = V_41 ;
V_34 = F_14 ( V_41 ) ;
} else {
V_29 = & V_42 ;
V_31 = & V_43 ;
V_33 = V_44 ;
V_34 = F_14 ( V_44 ) ;
}
V_25 -> V_45 = F_15 ( V_23 , V_29 ) ;
if ( F_16 ( V_25 -> V_45 ) ) {
V_27 = F_17 ( V_25 -> V_45 ) ;
F_18 ( V_25 -> V_2 , L_1 ,
V_27 ) ;
return V_27 ;
}
V_27 = F_19 ( V_25 -> V_45 , V_46 , & V_26 ) ;
if ( V_27 < 0 ) {
F_18 ( V_25 -> V_2 ,
L_2 ) ;
return - V_47 ;
}
V_27 = F_20 ( & V_23 -> V_2 , V_25 -> V_45 ,
V_25 -> V_37 ,
V_48 | V_49 |
V_50 , 0 , V_31 ,
& V_25 -> V_51 ) ;
if ( V_27 < 0 ) {
F_18 ( & V_23 -> V_2 , L_3 , V_27 ) ;
return V_27 ;
}
V_27 = F_21 ( V_25 -> V_2 , - 1 , V_33 , V_34 , NULL ,
0 , NULL ) ;
if ( V_27 < 0 ) {
F_18 ( & V_23 -> V_2 , L_4 , V_27 ) ;
return V_27 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_23 ( V_2 ) ;
struct V_24 * V_25 = F_24 ( V_23 ) ;
if ( F_25 ( V_2 ) )
F_26 ( V_25 -> V_37 ) ;
F_27 ( V_25 -> V_37 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_23 ( V_2 ) ;
struct V_24 * V_25 = F_24 ( V_23 ) ;
if ( F_25 ( V_2 ) )
F_29 ( V_25 -> V_37 ) ;
F_30 ( V_25 -> V_37 ) ;
return 0 ;
}

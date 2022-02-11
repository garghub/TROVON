static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
int V_6 ;
if ( V_5 -> V_7 ) {
V_6 = F_2 ( V_5 -> V_7 ) ;
if ( V_6 )
return V_6 ;
}
if ( V_5 -> V_8 == V_9 ) {
F_3 ( V_5 -> V_10 , V_11 ) ;
F_4 ( V_5 -> V_10 ) ;
V_5 -> V_12 = 1 ;
} else {
F_3 ( V_5 -> V_10 , V_13 ) ;
F_5 ( V_5 -> V_10 ) ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( V_5 -> V_12 ) {
F_7 ( V_5 -> V_10 ) ;
V_5 -> V_12 = 0 ;
}
F_8 ( V_5 -> V_10 ) ;
if ( V_5 -> V_7 )
F_9 ( V_5 -> V_7 ) ;
}
static void F_10 ( void * V_3 , unsigned int V_14 )
{
struct V_4 * V_5 = V_3 ;
if ( V_5 -> V_8 != V_15 )
return;
if ( V_5 -> V_12 ) {
F_7 ( V_5 -> V_10 ) ;
V_5 -> V_12 = 0 ;
}
F_8 ( V_5 -> V_10 ) ;
if ( V_14 == 1000 ) {
F_3 ( V_5 -> V_10 , V_11 ) ;
F_4 ( V_5 -> V_10 ) ;
V_5 -> V_12 = 1 ;
} else {
F_3 ( V_5 -> V_10 , V_13 ) ;
F_5 ( V_5 -> V_10 ) ;
}
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
struct V_18 V_19 ;
struct V_4 * V_5 ;
struct V_20 * V_21 = & V_2 -> V_21 ;
int V_6 ;
V_6 = F_12 ( V_2 , & V_19 ) ;
if ( V_6 )
return V_6 ;
V_17 = F_13 ( V_2 , & V_19 . V_22 ) ;
if ( F_14 ( V_17 ) )
return F_15 ( V_17 ) ;
V_5 = F_16 ( V_21 , sizeof( * V_5 ) , V_23 ) ;
if ( ! V_5 )
return - V_24 ;
V_5 -> V_8 = F_17 ( V_21 -> V_25 ) ;
V_5 -> V_10 = F_18 ( V_21 , L_1 ) ;
if ( F_14 ( V_5 -> V_10 ) ) {
F_19 ( V_21 , L_2 ) ;
return F_15 ( V_5 -> V_10 ) ;
}
V_5 -> V_7 = F_20 ( V_21 , L_3 ) ;
if ( F_14 ( V_5 -> V_7 ) ) {
if ( F_15 ( V_5 -> V_7 ) == - V_26 )
return - V_26 ;
F_21 ( V_21 , L_4 ) ;
V_5 -> V_7 = NULL ;
}
V_17 -> V_27 = 1 ;
V_17 -> V_28 = true ;
V_17 -> V_29 = V_5 ;
V_17 -> V_30 = F_1 ;
V_17 -> exit = F_6 ;
V_17 -> V_31 = F_10 ;
V_6 = F_1 ( V_2 , V_17 -> V_29 ) ;
if ( V_6 )
return V_6 ;
return F_22 ( & V_2 -> V_21 , V_17 , & V_19 ) ;
}

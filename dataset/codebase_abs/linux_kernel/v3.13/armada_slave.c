static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 0 ;
if ( V_4 ) {
struct V_6 * V_7 = F_3 ( V_4 ) ;
V_5 = V_7 -> V_8 -> V_9 ( V_4 , V_2 ) ;
}
return V_5 ;
}
static void F_4 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_3 ( V_4 ) ;
struct V_10 * V_11 = F_5 ( V_4 ) ;
if ( V_7 -> V_8 )
V_7 -> V_8 -> V_12 ( V_4 ) ;
if ( V_11 )
F_6 ( V_11 -> V_13 ) ;
F_7 ( & V_7 -> V_14 ) ;
F_8 ( V_7 ) ;
}
static int
F_9 ( struct V_1 * V_2 , const void * V_15 )
{
const struct V_16 * V_17 = V_15 ;
struct V_6 * V_7 ;
struct V_18 * V_19 ;
int V_20 ;
V_2 -> V_21 = V_17 -> V_21 ;
V_2 -> V_22 = V_17 -> V_22 ;
V_2 -> V_23 = V_17 -> V_23 ;
F_10 ( V_2 , & V_24 ) ;
V_7 = F_11 ( sizeof( * V_7 ) , V_25 ) ;
if ( ! V_7 )
return - V_26 ;
V_7 -> V_14 . V_27 = V_17 -> V_28 ;
V_19 = F_12 ( V_17 -> V_29 ) ;
if ( ! V_19 ) {
F_8 ( V_7 ) ;
return - V_30 ;
}
V_20 = F_13 ( V_2 -> V_31 , & V_7 -> V_14 ,
& V_32 ,
V_33 ) ;
if ( V_20 ) {
F_14 ( L_1 ) ;
F_6 ( V_19 ) ;
F_8 ( V_7 ) ;
return V_20 ;
}
V_20 = F_15 ( V_2 -> V_31 , V_7 , V_19 , & V_17 -> V_34 ) ;
F_6 ( V_19 ) ;
if ( V_20 ) {
F_14 ( L_2 ) ;
F_4 ( & V_7 -> V_14 ) ;
return V_20 ;
}
F_16 ( & V_7 -> V_14 , & V_35 ) ;
V_20 = V_7 -> V_8 -> V_36 ( & V_7 -> V_14 , V_2 ) ;
if ( V_20 ) {
F_4 ( & V_7 -> V_14 ) ;
return V_20 ;
}
V_20 = F_17 ( V_2 , & V_7 -> V_14 ) ;
if ( V_20 ) {
F_4 ( & V_7 -> V_14 ) ;
return V_20 ;
}
V_2 -> V_37 = & V_7 -> V_14 ;
return V_20 ;
}
int F_18 ( struct V_38 * V_31 ,
const struct V_16 * V_17 )
{
return F_19 ( V_31 , & V_39 , V_17 ) ;
}

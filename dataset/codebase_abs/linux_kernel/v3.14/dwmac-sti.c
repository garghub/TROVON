static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = 0 , V_5 = 0 ;
if ( V_3 == V_6 ) {
if ( V_2 -> V_7 == V_8 ||
V_2 -> V_7 == V_9 ) {
V_4 = V_10 ;
} else if ( V_2 -> V_7 == V_11 ) {
if ( V_2 -> V_12 ) {
V_4 = V_13 ;
} else {
V_4 = V_14 ;
V_5 = 50000000 ;
}
} else if ( F_2 ( V_2 -> V_7 ) ) {
V_4 = V_14 ;
V_5 = 25000000 ;
}
if ( V_4 == V_14 && V_2 -> V_15 )
F_3 ( V_2 -> V_15 , V_5 ) ;
} else if ( V_3 == V_16 ) {
if ( V_2 -> V_17 )
V_4 = V_18 ;
else
V_4 = V_10 ;
}
F_4 ( V_2 -> V_19 , V_2 -> V_20 ,
V_21 , V_22 [ V_4 ] ) ;
}
static void F_5 ( struct V_23 * V_24 , void * V_25 )
{
struct V_1 * V_2 = V_25 ;
if ( V_2 -> V_15 )
F_6 ( V_2 -> V_15 ) ;
}
static void F_7 ( void * V_25 , unsigned int V_3 )
{
struct V_1 * V_2 = V_25 ;
F_1 ( V_2 , V_3 ) ;
return;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 = & V_24 -> V_29 ;
struct V_30 * V_31 = V_29 -> V_32 ;
struct V_19 * V_19 ;
int V_33 ;
if ( ! V_31 )
return - V_34 ;
V_27 = F_9 ( V_24 , V_35 , L_1 ) ;
if ( ! V_27 )
return - V_36 ;
V_19 = F_10 ( V_31 , L_2 ) ;
if ( F_11 ( V_19 ) )
return F_12 ( V_19 ) ;
V_2 -> V_29 = V_29 ;
V_2 -> V_7 = F_13 ( V_31 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_20 = V_27 -> V_37 ;
V_2 -> V_12 = F_14 ( V_31 , L_3 ) ;
V_2 -> V_17 = false ;
if ( F_15 ( V_2 -> V_7 ) ) {
const char * V_38 ;
V_33 = F_16 ( V_31 , L_4 , & V_38 ) ;
if ( V_33 < 0 ) {
F_17 ( V_29 , L_5 ) ;
return V_33 ;
}
if ( ! strcasecmp ( V_38 , L_6 ) )
V_2 -> V_17 = true ;
}
V_2 -> V_15 = F_18 ( V_29 , L_7 ) ;
if ( F_11 ( V_2 -> V_15 ) )
V_2 -> V_15 = NULL ;
return 0 ;
}
static int F_19 ( struct V_23 * V_24 , void * V_25 )
{
struct V_1 * V_2 = V_25 ;
struct V_19 * V_19 = V_2 -> V_19 ;
int V_39 = V_2 -> V_7 ;
T_1 V_20 = V_2 -> V_20 ;
T_1 V_40 , V_3 ;
if ( V_2 -> V_15 )
F_20 ( V_2 -> V_15 ) ;
F_4 ( V_19 , V_20 , V_41 , V_42 [ V_39 ] ) ;
V_40 = ( V_39 == V_43 ) ? 0 : V_44 ;
F_4 ( V_19 , V_20 , V_45 , V_40 ) ;
if ( F_15 ( V_39 ) )
V_3 = V_16 ;
else
V_3 = V_6 ;
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static void * F_21 ( struct V_23 * V_24 )
{
struct V_1 * V_2 ;
int V_46 ;
V_2 = F_22 ( & V_24 -> V_29 , sizeof( * V_2 ) , V_47 ) ;
if ( ! V_2 )
return F_23 ( - V_48 ) ;
V_46 = F_8 ( V_2 , V_24 ) ;
if ( V_46 ) {
F_17 ( & V_24 -> V_29 , L_8 ) ;
return F_23 ( V_46 ) ;
}
return V_2 ;
}

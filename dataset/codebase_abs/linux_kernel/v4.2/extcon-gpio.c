static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 =
F_2 ( F_3 ( V_2 ) , struct V_4 ,
V_2 ) ;
V_3 = F_4 ( V_5 -> V_6 ) ;
if ( V_5 -> V_7 )
V_3 = ! V_3 ;
F_5 ( V_5 -> V_8 , V_3 ) ;
}
static T_1 F_6 ( int V_9 , void * V_10 )
{
struct V_4 * V_11 = V_10 ;
F_7 ( V_12 , & V_11 -> V_2 ,
V_11 -> V_13 ) ;
return V_14 ;
}
static T_2 F_8 ( struct V_15 * V_8 , char * V_16 )
{
struct V_17 * V_18 = V_8 -> V_18 . V_19 ;
struct V_4 * V_11 = F_9 ( V_18 ) ;
const char * V_3 ;
if ( F_10 ( V_8 ) )
V_3 = V_11 -> V_20 ;
else
V_3 = V_11 -> V_21 ;
if ( V_3 )
return sprintf ( V_16 , L_1 , V_3 ) ;
return - V_22 ;
}
static int F_11 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_12 ( & V_24 -> V_18 ) ;
struct V_4 * V_11 ;
int V_27 ;
if ( ! V_26 )
return - V_28 ;
if ( ! V_26 -> V_29 ) {
F_13 ( & V_24 -> V_18 , L_2 ) ;
return - V_22 ;
}
V_11 = F_14 ( & V_24 -> V_18 , sizeof( struct V_4 ) ,
V_30 ) ;
if ( ! V_11 )
return - V_31 ;
V_11 -> V_8 = F_15 ( & V_24 -> V_18 , NULL ) ;
if ( F_16 ( V_11 -> V_8 ) ) {
F_13 ( & V_24 -> V_18 , L_3 ) ;
return - V_31 ;
}
V_11 -> V_6 = V_26 -> V_6 ;
V_11 -> V_7 = V_26 -> V_7 ;
V_11 -> V_20 = V_26 -> V_20 ;
V_11 -> V_21 = V_26 -> V_21 ;
V_11 -> V_32 = V_26 -> V_32 ;
if ( V_26 -> V_20 && V_26 -> V_21 )
V_11 -> V_8 -> V_33 = F_8 ;
V_27 = F_17 ( & V_24 -> V_18 , V_11 -> V_6 , V_34 ,
V_24 -> V_35 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_26 -> V_36 ) {
V_27 = F_18 ( V_11 -> V_6 ,
V_26 -> V_36 * 1000 ) ;
if ( V_27 < 0 )
V_11 -> V_13 =
F_19 ( V_26 -> V_36 ) ;
}
V_27 = F_20 ( & V_24 -> V_18 , V_11 -> V_8 ) ;
if ( V_27 < 0 )
return V_27 ;
F_21 ( & V_11 -> V_2 , F_1 ) ;
V_11 -> V_9 = F_22 ( V_11 -> V_6 ) ;
if ( V_11 -> V_9 < 0 )
return V_11 -> V_9 ;
V_27 = F_23 ( V_11 -> V_9 , F_6 ,
V_26 -> V_29 , V_24 -> V_35 ,
V_11 ) ;
if ( V_27 < 0 )
return V_27 ;
F_24 ( V_24 , V_11 ) ;
F_1 ( & V_11 -> V_2 . V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_23 * V_24 )
{
struct V_4 * V_11 = F_26 ( V_24 ) ;
F_27 ( & V_11 -> V_2 ) ;
F_28 ( V_11 -> V_9 , V_11 ) ;
return 0 ;
}
static int F_29 ( struct V_17 * V_18 )
{
struct V_4 * V_11 ;
V_11 = F_9 ( V_18 ) ;
if ( V_11 -> V_32 )
F_7 ( V_12 ,
& V_11 -> V_2 , V_11 -> V_13 ) ;
return 0 ;
}

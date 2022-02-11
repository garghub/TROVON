static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = F_3 ( V_2 ) ;
if ( V_6 -> V_7 )
V_6 -> V_7 ( V_2 , V_8 ) ;
if ( V_4 -> V_9 -> V_10 )
F_4 ( V_4 -> V_9 -> V_10 , V_2 -> V_11 ,
false ) ;
V_4 -> V_12 = false ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = F_3 ( V_2 ) ;
if ( V_4 -> V_9 -> V_10 )
F_4 ( V_4 -> V_9 -> V_10 , V_2 -> V_11 ,
true ) ;
if ( V_6 -> V_7 )
V_6 -> V_7 ( V_2 , V_13 ) ;
V_4 -> V_12 = true ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_18 * V_19 = & V_15 -> V_19 ;
const struct V_18 * V_20 = & V_15 -> V_20 ;
if ( V_4 -> V_9 -> V_10 )
F_7 ( V_4 -> V_9 -> V_10 ,
V_19 ) ;
if ( V_6 -> V_21 == NULL )
return 0 ;
return V_6 -> V_21 ( V_2 , V_20 , V_19 ) ? 0 : - V_22 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_18 * V_20 ,
struct V_18 * V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = F_3 ( V_2 ) ;
if ( V_6 -> V_23 )
V_6 -> V_23 ( V_2 , V_20 , V_19 ) ;
F_9 ( V_2 -> V_11 , V_4 -> V_9 -> V_24 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_12 )
F_1 ( V_2 ) ;
F_11 ( V_2 ) ;
F_12 ( V_4 -> V_25 ) ;
}
int F_13 ( struct V_26 * V_27 ,
struct V_28 * V_9 , struct V_29 * V_30 )
{
struct V_1 * V_2 = F_14 ( V_9 ) ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct V_3 * V_4 ;
int V_35 ;
V_4 = F_15 ( V_27 -> V_25 , sizeof( * V_4 ) , V_36 ) ;
if ( V_4 == NULL )
return - V_37 ;
V_34 = F_16 ( V_30 ) ;
if ( ! V_34 || ! F_17 ( V_34 ) ) {
F_18 ( V_27 -> V_25 ,
L_1 ,
F_19 ( V_30 ) ) ;
return - V_38 ;
}
V_4 -> V_25 = & V_34 -> V_25 ;
if ( V_4 -> V_25 -> V_32 == NULL ) {
F_18 ( V_27 -> V_25 ,
L_2 ,
F_20 ( V_4 -> V_25 ) ) ;
V_35 = - V_38 ;
goto error;
}
V_32 = F_21 ( F_22 ( V_4 -> V_25 -> V_32 ) ) ;
V_35 = V_32 -> V_39 ( V_34 , V_27 -> V_40 , & V_9 -> V_41 ) ;
if ( V_35 < 0 )
goto error;
V_35 = F_23 ( V_27 -> V_40 , V_2 , & V_42 ,
V_43 , NULL ) ;
if ( V_35 < 0 )
goto error;
F_24 ( V_2 , & V_44 ) ;
V_9 -> V_45 = V_4 ;
V_4 -> V_9 = V_9 ;
return 0 ;
error:
F_12 ( V_4 -> V_25 ) ;
return V_35 ;
}

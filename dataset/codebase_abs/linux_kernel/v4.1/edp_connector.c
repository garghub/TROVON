static enum V_1 F_1 (
struct V_2 * V_3 , bool V_4 )
{
struct V_5 * V_5 = F_2 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
F_3 ( L_1 ) ;
return F_4 ( V_7 -> V_8 ) ?
V_9 : V_10 ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_5 * V_5 = F_2 ( V_3 ) ;
F_3 ( L_1 ) ;
F_6 ( V_3 ) ;
F_7 ( V_3 ) ;
F_8 ( V_5 ) ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_5 * V_5 = F_2 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_11 * V_12 = NULL ;
int V_13 = 0 ;
F_3 ( L_1 ) ;
V_13 = F_10 ( V_7 -> V_8 , V_3 , & V_12 ) ;
if ( V_13 )
return V_13 ;
F_11 ( V_3 , V_12 ) ;
if ( V_12 )
V_13 = F_12 ( V_3 , V_12 ) ;
return V_13 ;
}
static int F_13 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
struct V_5 * V_5 = F_2 ( V_3 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_16 * V_17 = V_3 -> V_18 -> V_19 ;
struct V_20 * V_21 = V_17 -> V_21 ;
long V_22 , V_23 ;
V_23 = 1000 * V_15 -> clock ;
V_22 = V_21 -> V_24 -> V_25 ( V_21 ,
V_23 , V_5 -> V_7 -> V_26 ) ;
F_3 ( L_2 , V_23 , V_22 ) ;
if ( V_22 != V_23 )
return V_27 ;
if ( ! F_14 (
V_7 -> V_8 , V_15 -> clock , NULL , NULL ) )
return V_27 ;
if ( V_3 -> V_28 . V_29 > 8 )
return V_30 ;
return V_31 ;
}
static struct V_32 *
F_15 ( struct V_2 * V_3 )
{
struct V_5 * V_5 = F_2 ( V_3 ) ;
F_3 ( L_1 ) ;
return V_5 -> V_7 -> V_26 ;
}
struct V_2 * F_16 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = NULL ;
struct V_5 * V_5 ;
int V_13 ;
V_5 = F_17 ( sizeof( * V_5 ) , V_33 ) ;
if ( ! V_5 ) {
V_13 = - V_34 ;
goto V_35;
}
V_5 -> V_7 = V_7 ;
V_3 = & V_5 -> V_36 ;
V_13 = F_18 ( V_7 -> V_18 , V_3 , & V_37 ,
V_38 ) ;
if ( V_13 )
goto V_35;
F_19 ( V_3 , & V_39 ) ;
V_3 -> V_40 = V_41 ;
V_3 -> V_42 = false ;
V_3 -> V_43 = false ;
V_13 = F_20 ( V_3 ) ;
if ( V_13 )
goto V_35;
F_21 ( V_3 , V_7 -> V_26 ) ;
return V_3 ;
V_35:
if ( V_3 )
F_5 ( V_3 ) ;
return F_22 ( V_13 ) ;
}

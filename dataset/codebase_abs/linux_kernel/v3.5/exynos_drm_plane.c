static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , int V_7 , int V_8 ,
unsigned int V_9 , unsigned int V_10 ,
T_1 V_11 , T_1 V_12 ,
T_1 V_13 , T_1 V_14 )
{
struct V_15 * V_15 =
F_2 ( V_2 , struct V_15 , V_16 ) ;
struct V_17 * V_18 = & V_15 -> V_18 ;
struct V_19 V_20 ;
int V_21 ;
F_3 ( L_1 , __LINE__ , V_22 ) ;
memset ( & V_20 , 0 , sizeof( struct V_19 ) ) ;
V_20 . V_7 = V_7 ;
V_20 . V_8 = V_8 ;
V_20 . V_9 = V_9 ;
V_20 . V_10 = V_10 ;
V_20 . V_23 = V_11 >> 16 ;
V_20 . V_24 = V_12 >> 16 ;
V_20 . V_13 = V_13 >> 16 ;
V_20 . V_14 = V_14 >> 16 ;
V_21 = F_4 ( V_18 , V_6 , & V_4 -> V_25 , & V_20 ) ;
if ( V_21 < 0 )
return V_21 ;
F_5 ( V_4 , V_18 ,
V_26 ) ;
F_5 ( V_4 , & V_18 -> V_27 ,
V_28 ) ;
V_15 -> V_29 = true ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_15 * V_15 =
F_2 ( V_2 , struct V_15 , V_16 ) ;
struct V_17 * V_18 = & V_15 -> V_18 ;
F_3 ( L_1 , __LINE__ , V_22 ) ;
if ( ! V_15 -> V_29 )
return 0 ;
F_5 ( V_2 -> V_4 , & V_18 -> V_27 ,
V_30 ) ;
V_15 -> V_29 = false ;
V_15 -> V_18 . V_27 = V_31 ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_15 * V_15 =
F_2 ( V_2 , struct V_15 , V_16 ) ;
F_3 ( L_1 , __LINE__ , V_22 ) ;
F_6 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_15 ) ;
}
int F_10 ( struct V_32 * V_33 , unsigned int V_34 )
{
struct V_15 * V_15 ;
T_1 V_35 ;
V_15 = F_11 ( sizeof( struct V_15 ) , V_36 ) ;
if ( ! V_15 )
return - V_37 ;
V_35 = ( 1 << V_38 ) - 1 ;
V_15 -> V_18 . V_27 = V_31 ;
return F_12 ( V_33 , & V_15 -> V_16 , V_35 ,
& V_39 , V_40 , F_13 ( V_40 ) ,
false ) ;
}
int F_14 ( struct V_32 * V_33 , void * V_41 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 = V_41 ;
struct V_46 * V_47 ;
struct V_1 * V_2 ;
struct V_15 * V_15 ;
int V_21 = 0 ;
F_3 ( L_1 , __LINE__ , V_22 ) ;
if ( ! F_15 ( V_33 , V_48 ) )
return - V_49 ;
if ( V_45 -> V_27 < 0 || V_45 -> V_27 >= V_50 ) {
if ( V_45 -> V_27 != V_31 ) {
F_16 ( L_2 ) ;
return - V_49 ;
}
}
F_17 ( & V_33 -> V_51 . V_52 ) ;
V_47 = F_18 ( V_33 , V_45 -> V_53 ,
V_54 ) ;
if ( ! V_47 ) {
F_3 ( L_3 ,
V_45 -> V_53 ) ;
V_21 = - V_49 ;
goto V_55;
}
V_2 = F_19 ( V_47 ) ;
V_15 = F_2 ( V_2 , struct V_15 , V_16 ) ;
V_15 -> V_18 . V_27 = V_45 -> V_27 ;
V_55:
F_20 ( & V_33 -> V_51 . V_52 ) ;
return V_21 ;
}

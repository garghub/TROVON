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
unsigned int V_21 = V_11 >> 16 ;
unsigned int V_22 = V_12 >> 16 ;
int V_23 ;
F_3 ( L_1 , __LINE__ , V_24 ) ;
memset ( & V_20 , 0 , sizeof( struct V_19 ) ) ;
V_20 . V_7 = V_7 ;
V_20 . V_8 = V_8 ;
V_20 . V_9 = V_9 ;
V_20 . V_10 = V_10 ;
V_20 . V_25 = V_21 ;
V_20 . V_26 = V_22 ;
V_23 = F_4 ( V_18 , V_6 , & V_4 -> V_27 , & V_20 ) ;
if ( V_23 < 0 )
return V_23 ;
F_5 ( V_4 , V_18 ,
V_28 ) ;
F_5 ( V_4 , & V_18 -> V_29 ,
V_30 ) ;
V_15 -> V_31 = true ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_15 * V_15 =
F_2 ( V_2 , struct V_15 , V_16 ) ;
struct V_17 * V_18 = & V_15 -> V_18 ;
F_3 ( L_1 , __LINE__ , V_24 ) ;
if ( ! V_15 -> V_31 )
return 0 ;
F_5 ( V_2 -> V_4 , & V_18 -> V_29 ,
V_32 ) ;
V_15 -> V_31 = false ;
V_15 -> V_18 . V_29 = V_33 ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_15 * V_15 =
F_2 ( V_2 , struct V_15 , V_16 ) ;
F_3 ( L_1 , __LINE__ , V_24 ) ;
F_6 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_15 ) ;
}
int F_10 ( struct V_34 * V_35 , unsigned int V_36 )
{
struct V_15 * V_15 ;
T_1 V_37 ;
V_15 = F_11 ( sizeof( struct V_15 ) , V_38 ) ;
if ( ! V_15 )
return - V_39 ;
V_37 = ( 1 << V_40 ) - 1 ;
V_15 -> V_18 . V_29 = V_33 ;
return F_12 ( V_35 , & V_15 -> V_16 , V_37 ,
& V_41 , NULL , 0 , false ) ;
}
int F_13 ( struct V_34 * V_35 , void * V_42 ,
struct V_43 * V_44 )
{
struct V_45 * V_46 = V_42 ;
struct V_47 * V_48 ;
struct V_1 * V_2 ;
struct V_15 * V_15 ;
int V_23 = 0 ;
F_3 ( L_1 , __LINE__ , V_24 ) ;
if ( ! F_14 ( V_35 , V_49 ) )
return - V_50 ;
if ( V_46 -> V_29 < 0 || V_46 -> V_29 >= V_51 ) {
if ( V_46 -> V_29 != V_33 ) {
F_15 ( L_2 ) ;
return - V_50 ;
}
}
F_16 ( & V_35 -> V_52 . V_53 ) ;
V_48 = F_17 ( V_35 , V_46 -> V_54 ,
V_55 ) ;
if ( ! V_48 ) {
F_3 ( L_3 ,
V_46 -> V_54 ) ;
V_23 = - V_50 ;
goto V_56;
}
V_2 = F_18 ( V_48 ) ;
V_15 = F_2 ( V_2 , struct V_15 , V_16 ) ;
V_15 -> V_18 . V_29 = V_46 -> V_29 ;
V_56:
F_19 ( & V_35 -> V_52 . V_53 ) ;
return V_23 ;
}

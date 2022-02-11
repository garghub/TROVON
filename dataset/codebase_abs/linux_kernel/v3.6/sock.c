static int F_1 ( struct V_1 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
F_2 ( L_1 , V_2 , V_3 ) ;
if ( ! V_3 )
return 0 ;
F_3 ( V_3 ) ;
F_4 ( V_3 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_4 , unsigned long V_5 )
{
void T_1 * V_6 = ( void T_1 * ) V_5 ;
struct V_7 V_8 ;
struct V_9 V_10 ;
struct V_11 V_12 ;
struct V_13 V_14 ;
struct V_1 * V_15 ;
struct V_1 * V_16 ;
int V_17 ;
F_2 ( L_2 , V_4 , V_5 ) ;
switch ( V_4 ) {
case V_18 :
if ( ! F_6 ( V_19 ) )
return - V_20 ;
if ( F_7 ( & V_8 , V_6 , sizeof( V_8 ) ) )
return - V_21 ;
V_15 = F_8 ( V_8 . V_22 , & V_17 ) ;
if ( ! V_15 )
return V_17 ;
V_16 = F_8 ( V_8 . V_23 , & V_17 ) ;
if ( ! V_16 ) {
F_9 ( V_15 ) ;
return V_17 ;
}
if ( V_15 -> V_3 -> V_24 != V_25 ||
V_16 -> V_3 -> V_24 != V_25 ) {
F_9 ( V_15 ) ;
F_9 ( V_16 ) ;
return - V_26 ;
}
V_17 = F_10 ( & V_8 , V_15 , V_16 ) ;
if ( ! V_17 ) {
if ( F_11 ( V_6 , & V_8 , sizeof( V_8 ) ) )
V_17 = - V_21 ;
} else {
F_9 ( V_15 ) ;
F_9 ( V_16 ) ;
}
return V_17 ;
case V_27 :
if ( ! F_6 ( V_19 ) )
return - V_20 ;
if ( F_7 ( & V_10 , V_6 , sizeof( V_10 ) ) )
return - V_21 ;
return F_12 ( & V_10 ) ;
case V_28 :
if ( F_7 ( & V_12 , V_6 , sizeof( V_12 ) ) )
return - V_21 ;
if ( V_12 . V_29 <= 0 )
return - V_30 ;
V_17 = F_13 ( & V_12 ) ;
if ( ! V_17 && F_11 ( V_6 , & V_12 , sizeof( V_12 ) ) )
return - V_21 ;
return V_17 ;
case V_31 :
if ( F_7 ( & V_14 , V_6 , sizeof( V_14 ) ) )
return - V_21 ;
V_17 = F_14 ( & V_14 ) ;
if ( ! V_17 && F_11 ( V_6 , & V_14 , sizeof( V_14 ) ) )
return - V_21 ;
return V_17 ;
}
return - V_30 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_4 , unsigned long V_5 )
{
if ( V_4 == V_28 ) {
struct V_11 V_12 ;
T_2 V_32 ;
int V_17 ;
if ( F_16 ( V_12 . V_29 , ( T_2 T_1 * ) V_5 ) ||
F_16 ( V_32 , ( T_2 T_1 * ) ( V_5 + 4 ) ) )
return - V_21 ;
V_12 . V_14 = F_17 ( V_32 ) ;
if ( V_12 . V_29 <= 0 )
return - V_30 ;
V_17 = F_13 ( & V_12 ) ;
if ( ! V_17 && F_18 ( V_12 . V_29 , ( T_2 T_1 * ) V_5 ) )
V_17 = - V_21 ;
return V_17 ;
} else if ( V_4 == V_18 ) {
struct V_33 V_8 ;
struct V_7 T_1 * V_34 ;
V_34 = F_19 ( sizeof( * V_34 ) ) ;
if ( F_7 ( & V_8 , ( void T_1 * ) V_5 , sizeof( V_8 ) ) )
return - V_21 ;
if ( F_18 ( V_8 . V_22 , & V_34 -> V_22 ) ||
F_18 ( V_8 . V_23 , & V_34 -> V_23 ) ||
F_18 ( V_8 . V_35 , & V_34 -> V_35 ) ||
F_18 ( V_8 . V_36 , & V_34 -> V_36 ) ||
F_18 ( F_17 ( V_8 . V_37 ) , & V_34 -> V_37 ) ||
F_18 ( V_8 . V_38 , & V_34 -> V_38 ) ||
F_18 ( V_8 . V_39 , & V_34 -> V_39 ) ||
F_18 ( V_8 . V_40 , & V_34 -> V_40 ) ||
F_18 ( V_8 . V_41 , & V_34 -> V_41 ) ||
F_18 ( V_8 . V_42 , & V_34 -> V_42 ) ||
F_18 ( V_8 . V_43 , & V_34 -> V_43 ) ||
F_18 ( V_8 . V_44 , & V_34 -> V_44 ) ||
F_11 ( & V_34 -> V_45 [ 0 ] , & V_8 . V_45 [ 0 ] , 128 ) )
return - V_21 ;
V_5 = ( unsigned long ) V_34 ;
}
return F_5 ( V_2 , V_4 , V_5 ) ;
}
static int F_20 ( struct V_46 * V_46 , struct V_1 * V_2 , int V_47 ,
int V_48 )
{
struct V_2 * V_3 ;
F_2 ( L_3 , V_2 ) ;
if ( V_2 -> type != V_49 )
return - V_50 ;
V_3 = F_21 ( V_46 , V_51 , V_52 , & V_53 ) ;
if ( ! V_3 )
return - V_54 ;
F_22 ( V_2 , V_3 ) ;
V_2 -> V_55 = & V_56 ;
V_2 -> V_57 = V_58 ;
F_23 ( V_3 , V_59 ) ;
V_3 -> V_60 = V_47 ;
V_3 -> V_24 = V_61 ;
return 0 ;
}
int T_3 F_24 ( void )
{
int V_17 ;
V_17 = F_25 ( & V_53 , 0 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_26 ( V_62 , & V_63 ) ;
if ( V_17 < 0 )
goto error;
return 0 ;
error:
F_27 ( L_4 ) ;
F_28 ( & V_53 ) ;
return V_17 ;
}
void T_4 F_29 ( void )
{
if ( F_30 ( V_62 ) < 0 )
F_27 ( L_5 ) ;
F_28 ( & V_53 ) ;
}

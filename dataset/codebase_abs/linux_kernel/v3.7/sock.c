static int F_1 ( struct V_1 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
F_2 ( L_1 , V_2 , V_3 ) ;
if ( ! V_3 )
return 0 ;
F_3 ( & V_4 , V_3 ) ;
F_4 ( V_3 ) ;
F_5 ( V_3 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_5 , unsigned long V_6 )
{
void T_1 * V_7 = ( void T_1 * ) V_6 ;
struct V_8 V_9 ;
struct V_10 V_11 ;
struct V_12 V_13 ;
struct V_14 V_15 ;
struct V_1 * V_16 ;
struct V_1 * V_17 ;
int V_18 ;
F_2 ( L_2 , V_5 , V_6 ) ;
switch ( V_5 ) {
case V_19 :
if ( ! F_7 ( V_20 ) )
return - V_21 ;
if ( F_8 ( & V_9 , V_7 , sizeof( V_9 ) ) )
return - V_22 ;
V_16 = F_9 ( V_9 . V_23 , & V_18 ) ;
if ( ! V_16 )
return V_18 ;
V_17 = F_9 ( V_9 . V_24 , & V_18 ) ;
if ( ! V_17 ) {
F_10 ( V_16 ) ;
return V_18 ;
}
if ( V_16 -> V_3 -> V_25 != V_26 ||
V_17 -> V_3 -> V_25 != V_26 ) {
F_10 ( V_16 ) ;
F_10 ( V_17 ) ;
return - V_27 ;
}
V_18 = F_11 ( & V_9 , V_16 , V_17 ) ;
if ( ! V_18 ) {
if ( F_12 ( V_7 , & V_9 , sizeof( V_9 ) ) )
V_18 = - V_22 ;
} else {
F_10 ( V_16 ) ;
F_10 ( V_17 ) ;
}
return V_18 ;
case V_28 :
if ( ! F_7 ( V_20 ) )
return - V_21 ;
if ( F_8 ( & V_11 , V_7 , sizeof( V_11 ) ) )
return - V_22 ;
return F_13 ( & V_11 ) ;
case V_29 :
if ( F_8 ( & V_13 , V_7 , sizeof( V_13 ) ) )
return - V_22 ;
if ( V_13 . V_30 <= 0 )
return - V_31 ;
V_18 = F_14 ( & V_13 ) ;
if ( ! V_18 && F_12 ( V_7 , & V_13 , sizeof( V_13 ) ) )
return - V_22 ;
return V_18 ;
case V_32 :
if ( F_8 ( & V_15 , V_7 , sizeof( V_15 ) ) )
return - V_22 ;
V_18 = F_15 ( & V_15 ) ;
if ( ! V_18 && F_12 ( V_7 , & V_15 , sizeof( V_15 ) ) )
return - V_22 ;
return V_18 ;
}
return - V_31 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned int V_5 , unsigned long V_6 )
{
if ( V_5 == V_29 ) {
struct V_12 V_13 ;
T_2 V_33 ;
int V_18 ;
if ( F_17 ( V_13 . V_30 , ( T_2 T_1 * ) V_6 ) ||
F_17 ( V_33 , ( T_2 T_1 * ) ( V_6 + 4 ) ) )
return - V_22 ;
V_13 . V_15 = F_18 ( V_33 ) ;
if ( V_13 . V_30 <= 0 )
return - V_31 ;
V_18 = F_14 ( & V_13 ) ;
if ( ! V_18 && F_19 ( V_13 . V_30 , ( T_2 T_1 * ) V_6 ) )
V_18 = - V_22 ;
return V_18 ;
} else if ( V_5 == V_19 ) {
struct V_34 V_9 ;
struct V_8 T_1 * V_35 ;
V_35 = F_20 ( sizeof( * V_35 ) ) ;
if ( F_8 ( & V_9 , ( void T_1 * ) V_6 , sizeof( V_9 ) ) )
return - V_22 ;
if ( F_19 ( V_9 . V_23 , & V_35 -> V_23 ) ||
F_19 ( V_9 . V_24 , & V_35 -> V_24 ) ||
F_19 ( V_9 . V_36 , & V_35 -> V_36 ) ||
F_19 ( V_9 . V_37 , & V_35 -> V_37 ) ||
F_19 ( F_18 ( V_9 . V_38 ) , & V_35 -> V_38 ) ||
F_19 ( V_9 . V_39 , & V_35 -> V_39 ) ||
F_19 ( V_9 . V_40 , & V_35 -> V_40 ) ||
F_19 ( V_9 . V_41 , & V_35 -> V_41 ) ||
F_19 ( V_9 . V_42 , & V_35 -> V_42 ) ||
F_19 ( V_9 . V_43 , & V_35 -> V_43 ) ||
F_19 ( V_9 . V_44 , & V_35 -> V_44 ) ||
F_19 ( V_9 . V_45 , & V_35 -> V_45 ) ||
F_12 ( & V_35 -> V_46 [ 0 ] , & V_9 . V_46 [ 0 ] , 128 ) )
return - V_22 ;
V_6 = ( unsigned long ) V_35 ;
}
return F_6 ( V_2 , V_5 , V_6 ) ;
}
static int F_21 ( struct V_47 * V_47 , struct V_1 * V_2 , int V_48 ,
int V_49 )
{
struct V_2 * V_3 ;
F_2 ( L_3 , V_2 ) ;
if ( V_2 -> type != V_50 )
return - V_51 ;
V_3 = F_22 ( V_47 , V_52 , V_53 , & V_54 ) ;
if ( ! V_3 )
return - V_55 ;
F_23 ( V_2 , V_3 ) ;
V_2 -> V_56 = & V_57 ;
V_2 -> V_58 = V_59 ;
F_24 ( V_3 , V_60 ) ;
V_3 -> V_61 = V_48 ;
V_3 -> V_25 = V_62 ;
F_25 ( & V_4 , V_3 ) ;
return 0 ;
}
int T_3 F_26 ( void )
{
int V_18 ;
V_18 = F_27 ( & V_54 , 0 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_28 ( V_63 , & V_64 ) ;
if ( V_18 < 0 ) {
F_29 ( L_4 ) ;
goto error;
}
V_18 = F_30 ( V_65 , & V_66 , L_5 , & V_4 , NULL ) ;
if ( V_18 < 0 ) {
F_29 ( L_6 ) ;
F_31 ( V_63 ) ;
goto error;
}
F_32 ( L_7 ) ;
return 0 ;
error:
F_29 ( L_4 ) ;
F_33 ( & V_54 ) ;
return V_18 ;
}
void T_4 F_34 ( void )
{
F_35 ( & V_66 , L_5 ) ;
if ( F_31 ( V_63 ) < 0 )
F_29 ( L_8 ) ;
F_33 ( & V_54 ) ;
}

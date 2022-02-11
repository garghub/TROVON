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
V_18 = F_11 ( & V_9 , V_16 , V_17 ) ;
if ( ! V_18 && F_12 ( V_7 , & V_9 , sizeof( V_9 ) ) )
V_18 = - V_22 ;
F_10 ( V_16 ) ;
F_10 ( V_17 ) ;
return V_18 ;
case V_25 :
if ( ! F_7 ( V_20 ) )
return - V_21 ;
if ( F_8 ( & V_11 , V_7 , sizeof( V_11 ) ) )
return - V_22 ;
return F_13 ( & V_11 ) ;
case V_26 :
if ( F_8 ( & V_13 , V_7 , sizeof( V_13 ) ) )
return - V_22 ;
if ( V_13 . V_27 <= 0 )
return - V_28 ;
V_18 = F_14 ( & V_13 ) ;
if ( ! V_18 && F_12 ( V_7 , & V_13 , sizeof( V_13 ) ) )
return - V_22 ;
return V_18 ;
case V_29 :
if ( F_8 ( & V_15 , V_7 , sizeof( V_15 ) ) )
return - V_22 ;
V_18 = F_15 ( & V_15 ) ;
if ( ! V_18 && F_12 ( V_7 , & V_15 , sizeof( V_15 ) ) )
return - V_22 ;
return V_18 ;
}
return - V_28 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned int V_5 , unsigned long V_6 )
{
if ( V_5 == V_26 ) {
struct V_12 V_13 ;
T_2 V_30 ;
int V_18 ;
if ( F_17 ( V_13 . V_27 , ( T_2 T_1 * ) V_6 ) ||
F_17 ( V_30 , ( T_2 T_1 * ) ( V_6 + 4 ) ) )
return - V_22 ;
V_13 . V_15 = F_18 ( V_30 ) ;
if ( V_13 . V_27 <= 0 )
return - V_28 ;
V_18 = F_14 ( & V_13 ) ;
if ( ! V_18 && F_19 ( V_13 . V_27 , ( T_2 T_1 * ) V_6 ) )
V_18 = - V_22 ;
return V_18 ;
} else if ( V_5 == V_19 ) {
struct V_31 V_9 ;
struct V_8 T_1 * V_32 ;
V_32 = F_20 ( sizeof( * V_32 ) ) ;
if ( F_8 ( & V_9 , ( void T_1 * ) V_6 , sizeof( V_9 ) ) )
return - V_22 ;
if ( F_19 ( V_9 . V_23 , & V_32 -> V_23 ) ||
F_19 ( V_9 . V_24 , & V_32 -> V_24 ) ||
F_19 ( V_9 . V_33 , & V_32 -> V_33 ) ||
F_19 ( V_9 . V_34 , & V_32 -> V_34 ) ||
F_19 ( F_18 ( V_9 . V_35 ) , & V_32 -> V_35 ) ||
F_19 ( V_9 . V_36 , & V_32 -> V_36 ) ||
F_19 ( V_9 . V_37 , & V_32 -> V_37 ) ||
F_19 ( V_9 . V_38 , & V_32 -> V_38 ) ||
F_19 ( V_9 . V_39 , & V_32 -> V_39 ) ||
F_19 ( V_9 . V_40 , & V_32 -> V_40 ) ||
F_19 ( V_9 . V_41 , & V_32 -> V_41 ) ||
F_19 ( V_9 . V_42 , & V_32 -> V_42 ) ||
F_12 ( & V_32 -> V_43 [ 0 ] , & V_9 . V_43 [ 0 ] , 128 ) )
return - V_22 ;
V_6 = ( unsigned long ) V_32 ;
}
return F_6 ( V_2 , V_5 , V_6 ) ;
}
static int F_21 ( struct V_44 * V_44 , struct V_1 * V_2 , int V_45 ,
int V_46 )
{
struct V_2 * V_3 ;
F_2 ( L_3 , V_2 ) ;
if ( V_2 -> type != V_47 )
return - V_48 ;
V_3 = F_22 ( V_44 , V_49 , V_50 , & V_51 ) ;
if ( ! V_3 )
return - V_52 ;
F_23 ( V_2 , V_3 ) ;
V_2 -> V_53 = & V_54 ;
V_2 -> V_55 = V_56 ;
F_24 ( V_3 , V_57 ) ;
V_3 -> V_58 = V_45 ;
V_3 -> V_59 = V_60 ;
F_25 ( & V_4 , V_3 ) ;
return 0 ;
}
int T_3 F_26 ( void )
{
int V_18 ;
V_18 = F_27 ( & V_51 , 0 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_28 ( V_61 , & V_62 ) ;
if ( V_18 < 0 ) {
F_29 ( L_4 ) ;
goto error;
}
V_18 = F_30 ( & V_63 , L_5 , & V_4 , NULL ) ;
if ( V_18 < 0 ) {
F_29 ( L_6 ) ;
F_31 ( V_61 ) ;
goto error;
}
F_32 ( L_7 ) ;
return 0 ;
error:
F_33 ( & V_51 ) ;
return V_18 ;
}
void T_4 F_34 ( void )
{
F_35 ( & V_63 , L_5 ) ;
F_31 ( V_61 ) ;
F_33 ( & V_51 ) ;
}

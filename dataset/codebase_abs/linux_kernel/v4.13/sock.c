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
struct V_7 V_8 ;
struct V_9 V_10 ;
struct V_11 V_12 ;
struct V_13 V_14 ;
struct V_1 * V_15 ;
void T_1 * V_16 = ( void T_1 * ) V_6 ;
T_2 V_17 = F_7 ( V_18 ) ;
int V_19 ;
F_2 ( L_2 , V_5 , V_6 ) ;
switch ( V_5 ) {
case V_20 :
if ( ! F_8 ( V_21 ) )
return - V_22 ;
if ( F_9 ( & V_10 , V_16 , sizeof( V_10 ) ) )
return - V_23 ;
V_15 = F_10 ( V_10 . V_2 , & V_19 ) ;
if ( ! V_15 )
return V_19 ;
if ( V_15 -> V_3 -> V_24 != V_25 ) {
F_11 ( V_15 ) ;
return - V_26 ;
}
V_10 . V_27 [ sizeof( V_10 . V_27 ) - 1 ] = 0 ;
V_19 = F_12 ( & V_10 , V_15 ) ;
if ( ! V_19 ) {
if ( F_13 ( V_16 , & V_10 , sizeof( V_10 ) ) )
V_19 = - V_23 ;
} else
F_11 ( V_15 ) ;
return V_19 ;
case V_28 :
if ( ! F_8 ( V_21 ) )
return - V_22 ;
if ( F_9 ( & V_12 , V_16 , sizeof( V_12 ) ) )
return - V_23 ;
return F_14 ( & V_12 ) ;
case V_29 :
if ( F_9 ( & V_8 , V_16 , sizeof( V_8 ) ) )
return - V_23 ;
if ( V_8 . V_30 <= 0 )
return - V_31 ;
V_19 = F_15 ( & V_8 ) ;
if ( ! V_19 && F_13 ( V_16 , & V_8 , sizeof( V_8 ) ) )
return - V_23 ;
return V_19 ;
case V_32 :
if ( F_9 ( & V_14 , V_16 , sizeof( V_14 ) ) )
return - V_23 ;
V_19 = F_16 ( & V_14 ) ;
if ( ! V_19 && F_13 ( V_16 , & V_14 , sizeof( V_14 ) ) )
return - V_23 ;
return V_19 ;
case V_33 :
if ( F_13 ( V_16 , & V_17 , sizeof( V_17 ) ) )
return - V_23 ;
return 0 ;
default:
return - V_31 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned int V_5 , unsigned long V_6 )
{
if ( V_5 == V_29 ) {
struct V_7 V_8 ;
T_3 V_34 ;
int V_19 ;
if ( F_18 ( V_8 . V_30 , ( T_3 T_1 * ) V_6 ) ||
F_18 ( V_34 , ( T_3 T_1 * ) ( V_6 + 4 ) ) )
return - V_23 ;
V_8 . V_14 = F_19 ( V_34 ) ;
if ( V_8 . V_30 <= 0 )
return - V_31 ;
V_19 = F_15 ( & V_8 ) ;
if ( ! V_19 && F_20 ( V_8 . V_30 , ( T_3 T_1 * ) V_6 ) )
V_19 = - V_23 ;
return V_19 ;
}
return F_6 ( V_2 , V_5 , V_6 ) ;
}
static int F_21 ( struct V_35 * V_35 , struct V_1 * V_2 , int V_36 ,
int V_37 )
{
struct V_2 * V_3 ;
F_2 ( L_3 , V_2 ) ;
if ( V_2 -> type != V_38 )
return - V_39 ;
V_3 = F_22 ( V_35 , V_40 , V_41 , & V_42 , V_37 ) ;
if ( ! V_3 )
return - V_43 ;
F_23 ( V_2 , V_3 ) ;
V_2 -> V_44 = & V_45 ;
V_2 -> V_46 = V_47 ;
F_24 ( V_3 , V_48 ) ;
V_3 -> V_49 = V_36 ;
V_3 -> V_24 = V_50 ;
F_25 ( & V_4 , V_3 ) ;
return 0 ;
}
int T_4 F_26 ( void )
{
int V_19 ;
V_19 = F_27 ( & V_42 , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_28 ( V_51 , & V_52 ) ;
if ( V_19 < 0 ) {
F_29 ( L_4 ) ;
goto error;
}
V_19 = F_30 ( & V_53 , L_5 , & V_4 , NULL ) ;
if ( V_19 < 0 ) {
F_29 ( L_6 ) ;
F_31 ( V_51 ) ;
goto error;
}
F_32 ( L_7 ) ;
return 0 ;
error:
F_33 ( & V_42 ) ;
return V_19 ;
}
void T_5 F_34 ( void )
{
F_35 ( & V_53 , L_5 ) ;
F_31 ( V_51 ) ;
F_33 ( & V_42 ) ;
}

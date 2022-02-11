static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 type , T_1 V_5 , int V_6 , T_2 V_7 )
{
struct V_8 * V_8 = F_2 ( V_2 -> V_9 ) ;
T_2 V_10 ;
const struct V_11 * V_12 = ( const struct V_11 * ) V_2 -> V_13 ;
struct V_14 * V_15 =
(struct V_14 * ) ( V_2 -> V_13 + V_6 ) ;
struct V_16 * V_17 ;
if ( type != V_18 && type != V_19 )
return;
V_10 = F_3 ( F_4 ( V_15 -> V_20 ) ) ;
V_17 = F_5 ( V_8 , V_2 -> V_21 , ( const V_22 * ) & V_12 -> V_23 ,
V_10 , V_24 , V_25 ) ;
if ( ! V_17 )
return;
F_6 ( L_1 ,
V_10 , & V_12 -> V_23 ) ;
F_7 ( V_17 ) ;
}
static struct V_16 * F_8 ( struct V_16 * V_17 )
{
struct V_8 * V_8 = F_9 ( V_17 ) ;
struct V_16 * V_26 = NULL ;
V_26 = F_10 ( V_8 ) ;
if ( ! V_26 )
goto V_27;
V_26 -> V_28 . V_29 = V_30 ;
V_26 -> V_28 . V_10 = F_11 ( V_8 , ( V_22 * ) & V_17 -> V_31 . V_32 ) ;
if ( ! V_26 -> V_28 . V_10 )
goto error;
memcpy ( V_26 -> V_28 . V_23 . V_33 , V_17 -> V_28 . V_23 . V_33 , sizeof( struct V_34 ) ) ;
memcpy ( & V_26 -> V_35 , & V_17 -> V_35 , sizeof( V_26 -> V_35 ) ) ;
V_26 -> V_31 . V_36 = V_25 ;
V_26 -> V_31 . V_37 = V_17 -> V_31 . V_37 ;
memcpy ( V_26 -> V_31 . V_32 . V_33 , V_17 -> V_31 . V_32 . V_33 , sizeof( struct V_34 ) ) ;
memcpy ( & V_26 -> V_21 , & V_17 -> V_21 , sizeof( V_26 -> V_21 ) ) ;
if ( F_12 ( V_26 ) )
goto error;
F_13 ( & V_26 -> V_38 , 1 ) ;
V_27:
return V_26 ;
error:
V_26 -> V_39 . V_40 = V_41 ;
F_7 ( V_26 ) ;
V_26 = NULL ;
goto V_27;
}
static int F_14 ( struct V_16 * V_17 )
{
struct V_8 * V_8 = F_9 ( V_17 ) ;
int V_42 = 0 ;
struct V_16 * V_26 = NULL ;
T_2 V_10 ;
T_3 V_21 = V_17 -> V_21 . V_43 & V_17 -> V_21 . V_44 ;
V_10 = F_15 ( V_8 , ( V_22 * ) & V_17 -> V_31 . V_32 ) ;
if ( V_10 )
V_26 = F_5 ( V_8 , V_21 , ( V_22 * ) & V_17 -> V_28 . V_23 ,
V_10 , V_30 , V_25 ) ;
if ( ! V_26 ) {
V_26 = F_8 ( V_17 ) ;
if ( ! V_26 ) {
V_42 = - V_45 ;
goto V_27;
}
F_16 ( V_26 ) ;
F_17 ( V_26 ) ;
}
V_17 -> V_46 = V_26 ;
F_18 ( & V_26 -> V_38 ) ;
V_27:
return V_42 ;
}
static int F_19 ( struct V_16 * V_17 )
{
int V_42 = - V_45 ;
V_17 -> V_31 . V_47 = 0 ;
switch ( V_17 -> V_31 . V_37 ) {
case V_48 :
break;
case V_49 :
V_17 -> V_31 . V_47 += sizeof( struct V_11 ) ;
break;
default:
goto V_27;
}
V_42 = F_20 ( V_17 ) ;
if ( V_42 )
goto V_27;
if ( V_17 -> V_31 . V_37 == V_49 ) {
V_42 = F_14 ( V_17 ) ;
if ( V_42 )
goto V_27;
}
V_42 = 0 ;
V_27:
return V_42 ;
}
static int T_4 F_21 ( void )
{
if ( F_22 ( & V_50 , V_25 ) < 0 ) {
F_23 ( L_2 , V_51 ) ;
return - V_52 ;
}
if ( F_24 ( & V_53 , V_24 ) < 0 ) {
F_23 ( L_3 , V_51 ) ;
F_25 ( & V_50 , V_25 ) ;
return - V_52 ;
}
return 0 ;
}
static void T_5 F_26 ( void )
{
if ( F_27 ( & V_53 , V_24 ) < 0 )
F_23 ( L_4 , V_51 ) ;
if ( F_25 ( & V_50 , V_25 ) < 0 )
F_23 ( L_5 , V_51 ) ;
}

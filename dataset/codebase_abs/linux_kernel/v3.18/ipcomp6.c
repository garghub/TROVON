static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 type , T_1 V_5 , int V_6 , T_2 V_7 )
{
struct V_8 * V_8 = F_2 ( V_2 -> V_9 ) ;
T_2 V_10 ;
const struct V_11 * V_12 = ( const struct V_11 * ) V_2 -> V_13 ;
struct V_14 * V_15 =
(struct V_14 * ) ( V_2 -> V_13 + V_6 ) ;
struct V_16 * V_17 ;
if ( type != V_18 &&
type != V_19 )
return 0 ;
V_10 = F_3 ( F_4 ( V_15 -> V_20 ) ) ;
V_17 = F_5 ( V_8 , V_2 -> V_21 , ( const V_22 * ) & V_12 -> V_23 ,
V_10 , V_24 , V_25 ) ;
if ( ! V_17 )
return 0 ;
if ( type == V_19 )
F_6 ( V_2 , V_8 , V_2 -> V_9 -> V_26 , 0 ) ;
else
F_7 ( V_2 , V_8 , V_7 , 0 , 0 ) ;
F_8 ( V_17 ) ;
return 0 ;
}
static struct V_16 * F_9 ( struct V_16 * V_17 )
{
struct V_8 * V_8 = F_10 ( V_17 ) ;
struct V_16 * V_27 = NULL ;
V_27 = F_11 ( V_8 ) ;
if ( ! V_27 )
goto V_28;
V_27 -> V_29 . V_30 = V_31 ;
V_27 -> V_29 . V_10 = F_12 ( V_8 , ( V_22 * ) & V_17 -> V_32 . V_33 ) ;
if ( ! V_27 -> V_29 . V_10 )
goto error;
memcpy ( V_27 -> V_29 . V_23 . V_34 , V_17 -> V_29 . V_23 . V_34 , sizeof( struct V_35 ) ) ;
memcpy ( & V_27 -> V_36 , & V_17 -> V_36 , sizeof( V_27 -> V_36 ) ) ;
V_27 -> V_32 . V_37 = V_25 ;
V_27 -> V_32 . V_38 = V_17 -> V_32 . V_38 ;
memcpy ( V_27 -> V_32 . V_33 . V_34 , V_17 -> V_32 . V_33 . V_34 , sizeof( struct V_35 ) ) ;
memcpy ( & V_27 -> V_21 , & V_17 -> V_21 , sizeof( V_27 -> V_21 ) ) ;
if ( F_13 ( V_27 ) )
goto error;
F_14 ( & V_27 -> V_39 , 1 ) ;
V_28:
return V_27 ;
error:
V_27 -> V_40 . V_41 = V_42 ;
F_8 ( V_27 ) ;
V_27 = NULL ;
goto V_28;
}
static int F_15 ( struct V_16 * V_17 )
{
struct V_8 * V_8 = F_10 ( V_17 ) ;
int V_43 = 0 ;
struct V_16 * V_27 = NULL ;
T_2 V_10 ;
T_3 V_21 = V_17 -> V_21 . V_44 & V_17 -> V_21 . V_45 ;
V_10 = F_16 ( V_8 , ( V_22 * ) & V_17 -> V_32 . V_33 ) ;
if ( V_10 )
V_27 = F_5 ( V_8 , V_21 , ( V_22 * ) & V_17 -> V_29 . V_23 ,
V_10 , V_31 , V_25 ) ;
if ( ! V_27 ) {
V_27 = F_9 ( V_17 ) ;
if ( ! V_27 ) {
V_43 = - V_46 ;
goto V_28;
}
F_17 ( V_27 ) ;
F_18 ( V_27 ) ;
}
V_17 -> V_47 = V_27 ;
F_19 ( & V_27 -> V_39 ) ;
V_28:
return V_43 ;
}
static int F_20 ( struct V_16 * V_17 )
{
int V_43 = - V_46 ;
V_17 -> V_32 . V_48 = 0 ;
switch ( V_17 -> V_32 . V_38 ) {
case V_49 :
break;
case V_50 :
V_17 -> V_32 . V_48 += sizeof( struct V_11 ) ;
break;
default:
goto V_28;
}
V_43 = F_21 ( V_17 ) ;
if ( V_43 )
goto V_28;
if ( V_17 -> V_32 . V_38 == V_50 ) {
V_43 = F_15 ( V_17 ) ;
if ( V_43 )
goto V_28;
}
V_43 = 0 ;
V_28:
return V_43 ;
}
static int F_22 ( struct V_1 * V_2 , int V_43 )
{
return 0 ;
}
static int T_4 F_23 ( void )
{
if ( F_24 ( & V_51 , V_25 ) < 0 ) {
F_25 ( L_1 , V_52 ) ;
return - V_53 ;
}
if ( F_26 ( & V_54 , V_24 ) < 0 ) {
F_25 ( L_2 , V_52 ) ;
F_27 ( & V_51 , V_25 ) ;
return - V_53 ;
}
return 0 ;
}
static void T_5 F_28 ( void )
{
if ( F_29 ( & V_54 , V_24 ) < 0 )
F_25 ( L_3 , V_52 ) ;
if ( F_27 ( & V_51 , V_25 ) < 0 )
F_25 ( L_4 , V_52 ) ;
}

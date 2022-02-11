static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 -> V_5 ) ;
T_2 V_6 ;
const struct V_7 * V_8 = ( const struct V_7 * ) V_2 -> V_9 ;
struct V_10 * V_11 = (struct V_10 * ) ( V_2 -> V_9 + ( V_8 -> V_12 << 2 ) ) ;
struct V_13 * V_14 ;
switch ( F_3 ( V_2 ) -> type ) {
case V_15 :
if ( F_3 ( V_2 ) -> V_16 != V_17 )
return;
case V_18 :
break;
default:
return;
}
V_6 = F_4 ( F_5 ( V_11 -> V_19 ) ) ;
V_14 = F_6 ( V_4 , V_2 -> V_20 , ( const V_21 * ) & V_8 -> V_22 ,
V_6 , V_23 , V_24 ) ;
if ( ! V_14 )
return;
if ( F_3 ( V_2 ) -> type == V_15 ) {
F_7 ( & V_25 ) ;
F_8 ( V_4 ) ;
F_9 ( V_2 , V_4 , V_3 , 0 , 0 , V_23 , 0 ) ;
} else
F_10 ( V_2 , V_4 , 0 , 0 , V_23 , 0 ) ;
F_11 ( V_14 ) ;
}
static struct V_13 * F_12 ( struct V_13 * V_14 )
{
struct V_4 * V_4 = F_13 ( V_14 ) ;
struct V_13 * V_26 ;
V_26 = F_14 ( V_4 ) ;
if ( V_26 == NULL )
goto V_27;
V_26 -> V_28 . V_29 = V_30 ;
V_26 -> V_28 . V_6 = V_14 -> V_31 . V_32 . V_33 ;
V_26 -> V_28 . V_22 . V_33 = V_14 -> V_28 . V_22 . V_33 ;
memcpy ( & V_26 -> V_34 , & V_14 -> V_34 , sizeof( V_26 -> V_34 ) ) ;
V_26 -> V_31 . V_35 = V_24 ;
V_26 -> V_31 . V_36 = V_14 -> V_31 . V_36 ;
V_26 -> V_31 . V_32 . V_33 = V_14 -> V_31 . V_32 . V_33 ;
V_26 -> V_31 . V_37 = V_14 -> V_31 . V_37 ;
V_26 -> V_31 . V_38 = V_14 -> V_31 . V_38 ;
memcpy ( & V_26 -> V_20 , & V_14 -> V_20 , sizeof( V_26 -> V_20 ) ) ;
if ( F_15 ( V_26 ) )
goto error;
F_16 ( & V_26 -> V_39 , 1 ) ;
V_27:
return V_26 ;
error:
V_26 -> V_40 . V_41 = V_42 ;
F_11 ( V_26 ) ;
V_26 = NULL ;
goto V_27;
}
static int F_17 ( struct V_13 * V_14 )
{
struct V_4 * V_4 = F_13 ( V_14 ) ;
int V_43 = 0 ;
struct V_13 * V_26 ;
T_1 V_20 = V_14 -> V_20 . V_44 & V_14 -> V_20 . V_45 ;
V_26 = F_6 ( V_4 , V_20 , ( V_21 * ) & V_14 -> V_28 . V_22 . V_33 ,
V_14 -> V_31 . V_32 . V_33 , V_30 , V_24 ) ;
if ( ! V_26 ) {
V_26 = F_12 ( V_14 ) ;
if ( ! V_26 ) {
V_43 = - V_46 ;
goto V_27;
}
F_18 ( V_26 ) ;
F_19 ( V_26 ) ;
}
V_14 -> V_47 = V_26 ;
F_7 ( & V_26 -> V_39 ) ;
V_27:
return V_43 ;
}
static int F_20 ( struct V_13 * V_14 )
{
int V_43 = - V_46 ;
V_14 -> V_31 . V_48 = 0 ;
switch ( V_14 -> V_31 . V_36 ) {
case V_49 :
break;
case V_50 :
V_14 -> V_31 . V_48 += sizeof( struct V_7 ) ;
break;
default:
goto V_27;
}
V_43 = F_21 ( V_14 ) ;
if ( V_43 )
goto V_27;
if ( V_14 -> V_31 . V_36 == V_50 ) {
V_43 = F_17 ( V_14 ) ;
if ( V_43 )
goto V_27;
}
V_43 = 0 ;
V_27:
return V_43 ;
}
static int T_3 F_22 ( void )
{
if ( F_23 ( & V_51 , V_24 ) < 0 ) {
F_24 ( L_1 , V_52 ) ;
return - V_53 ;
}
if ( F_25 ( & V_54 , V_23 ) < 0 ) {
F_24 ( L_2 , V_52 ) ;
F_26 ( & V_51 , V_24 ) ;
return - V_53 ;
}
return 0 ;
}
static void T_4 F_27 ( void )
{
if ( F_28 ( & V_54 , V_23 ) < 0 )
F_24 ( L_3 , V_52 ) ;
if ( F_26 ( & V_51 , V_24 ) < 0 )
F_24 ( L_4 , V_52 ) ;
}

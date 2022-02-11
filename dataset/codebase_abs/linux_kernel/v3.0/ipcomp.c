static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 -> V_5 ) ;
T_2 V_6 ;
const struct V_7 * V_8 = ( const struct V_7 * ) V_2 -> V_9 ;
struct V_10 * V_11 = (struct V_10 * ) ( V_2 -> V_9 + ( V_8 -> V_12 << 2 ) ) ;
struct V_13 * V_14 ;
if ( F_3 ( V_2 ) -> type != V_15 ||
F_3 ( V_2 ) -> V_16 != V_17 )
return;
V_6 = F_4 ( F_5 ( V_11 -> V_18 ) ) ;
V_14 = F_6 ( V_4 , V_2 -> V_19 , ( const V_20 * ) & V_8 -> V_21 ,
V_6 , V_22 , V_23 ) ;
if ( ! V_14 )
return;
F_7 ( V_24 L_1 ,
V_6 , & V_8 -> V_21 ) ;
F_8 ( V_14 ) ;
}
static struct V_13 * F_9 ( struct V_13 * V_14 )
{
struct V_4 * V_4 = F_10 ( V_14 ) ;
struct V_13 * V_25 ;
V_25 = F_11 ( V_4 ) ;
if ( V_25 == NULL )
goto V_26;
V_25 -> V_27 . V_28 = V_29 ;
V_25 -> V_27 . V_6 = V_14 -> V_30 . V_31 . V_32 ;
V_25 -> V_27 . V_21 . V_32 = V_14 -> V_27 . V_21 . V_32 ;
memcpy ( & V_25 -> V_33 , & V_14 -> V_33 , sizeof( V_25 -> V_33 ) ) ;
V_25 -> V_30 . V_34 = V_23 ;
V_25 -> V_30 . V_35 = V_14 -> V_30 . V_35 ;
V_25 -> V_30 . V_31 . V_32 = V_14 -> V_30 . V_31 . V_32 ;
V_25 -> V_30 . V_36 = V_14 -> V_30 . V_36 ;
memcpy ( & V_25 -> V_19 , & V_14 -> V_19 , sizeof( V_25 -> V_19 ) ) ;
if ( F_12 ( V_25 ) )
goto error;
F_13 ( & V_25 -> V_37 , 1 ) ;
V_26:
return V_25 ;
error:
V_25 -> V_38 . V_39 = V_40 ;
F_8 ( V_25 ) ;
V_25 = NULL ;
goto V_26;
}
static int F_14 ( struct V_13 * V_14 )
{
struct V_4 * V_4 = F_10 ( V_14 ) ;
int V_41 = 0 ;
struct V_13 * V_25 ;
T_1 V_19 = V_14 -> V_19 . V_42 & V_14 -> V_19 . V_43 ;
V_25 = F_6 ( V_4 , V_19 , ( V_20 * ) & V_14 -> V_27 . V_21 . V_32 ,
V_14 -> V_30 . V_31 . V_32 , V_29 , V_23 ) ;
if ( ! V_25 ) {
V_25 = F_9 ( V_14 ) ;
if ( ! V_25 ) {
V_41 = - V_44 ;
goto V_26;
}
F_15 ( V_25 ) ;
F_16 ( V_25 ) ;
}
V_14 -> V_45 = V_25 ;
F_17 ( & V_25 -> V_37 ) ;
V_26:
return V_41 ;
}
static int F_18 ( struct V_13 * V_14 )
{
int V_41 = - V_44 ;
V_14 -> V_30 . V_46 = 0 ;
switch ( V_14 -> V_30 . V_35 ) {
case V_47 :
break;
case V_48 :
V_14 -> V_30 . V_46 += sizeof( struct V_7 ) ;
break;
default:
goto V_26;
}
V_41 = F_19 ( V_14 ) ;
if ( V_41 )
goto V_26;
if ( V_14 -> V_30 . V_35 == V_48 ) {
V_41 = F_14 ( V_14 ) ;
if ( V_41 )
goto V_26;
}
V_41 = 0 ;
V_26:
return V_41 ;
}
static int T_3 F_20 ( void )
{
if ( F_21 ( & V_49 , V_23 ) < 0 ) {
F_22 ( V_50 L_2 ) ;
return - V_51 ;
}
if ( F_23 ( & V_52 , V_22 ) < 0 ) {
F_22 ( V_50 L_3 ) ;
F_24 ( & V_49 , V_23 ) ;
return - V_51 ;
}
return 0 ;
}
static void T_4 F_25 ( void )
{
if ( F_26 ( & V_52 , V_22 ) < 0 )
F_22 ( V_50 L_4 ) ;
if ( F_24 ( & V_49 , V_23 ) < 0 )
F_22 ( V_50 L_5 ) ;
}

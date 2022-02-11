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
if ( F_3 ( V_2 ) -> type == V_15 )
F_7 ( V_2 , V_4 , V_3 , 0 , 0 , V_23 , 0 ) ;
else
F_8 ( V_2 , V_4 , 0 , 0 , V_23 , 0 ) ;
F_9 ( V_14 ) ;
}
static struct V_13 * F_10 ( struct V_13 * V_14 )
{
struct V_4 * V_4 = F_11 ( V_14 ) ;
struct V_13 * V_25 ;
V_25 = F_12 ( V_4 ) ;
if ( V_25 == NULL )
goto V_26;
V_25 -> V_27 . V_28 = V_29 ;
V_25 -> V_27 . V_6 = V_14 -> V_30 . V_31 . V_32 ;
V_25 -> V_27 . V_22 . V_32 = V_14 -> V_27 . V_22 . V_32 ;
memcpy ( & V_25 -> V_33 , & V_14 -> V_33 , sizeof( V_25 -> V_33 ) ) ;
V_25 -> V_30 . V_34 = V_24 ;
V_25 -> V_30 . V_35 = V_14 -> V_30 . V_35 ;
V_25 -> V_30 . V_31 . V_32 = V_14 -> V_30 . V_31 . V_32 ;
V_25 -> V_30 . V_36 = V_14 -> V_30 . V_36 ;
memcpy ( & V_25 -> V_20 , & V_14 -> V_20 , sizeof( V_25 -> V_20 ) ) ;
if ( F_13 ( V_25 ) )
goto error;
F_14 ( & V_25 -> V_37 , 1 ) ;
V_26:
return V_25 ;
error:
V_25 -> V_38 . V_39 = V_40 ;
F_9 ( V_25 ) ;
V_25 = NULL ;
goto V_26;
}
static int F_15 ( struct V_13 * V_14 )
{
struct V_4 * V_4 = F_11 ( V_14 ) ;
int V_41 = 0 ;
struct V_13 * V_25 ;
T_1 V_20 = V_14 -> V_20 . V_42 & V_14 -> V_20 . V_43 ;
V_25 = F_6 ( V_4 , V_20 , ( V_21 * ) & V_14 -> V_27 . V_22 . V_32 ,
V_14 -> V_30 . V_31 . V_32 , V_29 , V_24 ) ;
if ( ! V_25 ) {
V_25 = F_10 ( V_14 ) ;
if ( ! V_25 ) {
V_41 = - V_44 ;
goto V_26;
}
F_16 ( V_25 ) ;
F_17 ( V_25 ) ;
}
V_14 -> V_45 = V_25 ;
F_18 ( & V_25 -> V_37 ) ;
V_26:
return V_41 ;
}
static int F_19 ( struct V_13 * V_14 )
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
V_41 = F_20 ( V_14 ) ;
if ( V_41 )
goto V_26;
if ( V_14 -> V_30 . V_35 == V_48 ) {
V_41 = F_15 ( V_14 ) ;
if ( V_41 )
goto V_26;
}
V_41 = 0 ;
V_26:
return V_41 ;
}
static int T_3 F_21 ( void )
{
if ( F_22 ( & V_49 , V_24 ) < 0 ) {
F_23 ( L_1 , V_50 ) ;
return - V_51 ;
}
if ( F_24 ( & V_52 , V_23 ) < 0 ) {
F_23 ( L_2 , V_50 ) ;
F_25 ( & V_49 , V_24 ) ;
return - V_51 ;
}
return 0 ;
}
static void T_4 F_26 ( void )
{
if ( F_27 ( & V_52 , V_23 ) < 0 )
F_23 ( L_3 , V_50 ) ;
if ( F_25 ( & V_49 , V_24 ) < 0 )
F_23 ( L_4 , V_50 ) ;
}

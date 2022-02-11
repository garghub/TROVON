static T_1 F_1 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
T_2 V_5 = sizeof( struct V_6 ) , V_7 = F_2 ( V_4 ) ;
const struct V_8 * V_9 = V_2 -> V_9 ;
const struct V_10 * V_11 ;
struct V_12 V_13 ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
switch ( F_3 ( V_2 ) ) {
case V_14 :
V_13 . V_15 . V_16 . V_17 = F_4 ( V_9 ) -> V_18 ;
V_5 = sizeof( struct V_19 ) + sizeof( struct V_20 ) ;
break;
case V_21 :
V_13 . V_15 . V_22 . V_17 = F_5 ( V_9 ) -> V_18 ;
V_5 = sizeof( struct V_6 ) + sizeof( struct V_20 ) ;
break;
}
V_11 = F_6 ( F_3 ( V_2 ) ) ;
if ( V_11 ) {
struct V_3 * V_23 = NULL ;
V_11 -> V_24 ( F_7 ( V_2 ) , & V_23 , & V_13 , false ) ;
if ( V_23 ) {
V_7 = F_8 ( V_7 , F_2 ( V_23 ) ) ;
F_9 ( V_23 ) ;
}
}
if ( V_7 <= V_5 || V_7 > 0xffff )
return V_25 ;
return V_7 - V_5 ;
}
static void F_10 ( const struct V_26 * V_27 ,
struct V_28 * V_29 ,
const struct V_1 * V_2 )
{
const struct V_30 * V_31 = F_11 ( V_27 ) ;
const struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_32 = & V_29 -> V_33 [ V_31 -> V_34 ] ;
const struct V_3 * V_23 ;
V_23 = F_12 ( V_9 ) ;
if ( ! V_23 )
goto V_35;
switch ( V_31 -> V_36 ) {
#ifdef F_13
case V_37 :
* V_32 = V_23 -> V_38 ;
break;
#endif
case V_39 :
if ( F_3 ( V_2 ) != V_14 )
goto V_35;
* V_32 = ( V_40 T_2 ) F_14 ( ( const struct V_41 * ) V_23 ,
F_4 ( V_9 ) -> V_17 ) ;
break;
case V_42 :
if ( F_3 ( V_2 ) != V_21 )
goto V_35;
memcpy ( V_32 , F_15 ( (struct V_43 * ) V_23 ,
& F_5 ( V_9 ) -> V_17 ) ,
sizeof( struct V_44 ) ) ;
break;
case V_45 :
F_16 ( V_32 , F_1 ( V_2 , V_23 ) ) ;
break;
default:
F_17 ( 1 ) ;
goto V_35;
}
return;
V_35:
V_29 -> V_46 . V_47 = V_48 ;
}
static int F_18 ( const struct V_49 * V_50 ,
const struct V_26 * V_27 ,
const struct V_51 * const V_52 [] )
{
struct V_30 * V_31 = F_11 ( V_27 ) ;
unsigned int V_53 ;
if ( V_52 [ V_54 ] == NULL ||
V_52 [ V_55 ] == NULL )
return - V_56 ;
V_31 -> V_36 = F_19 ( F_20 ( V_52 [ V_54 ] ) ) ;
switch ( V_31 -> V_36 ) {
#ifdef F_13
case V_37 :
#endif
case V_39 :
V_53 = sizeof( T_2 ) ;
break;
case V_42 :
V_53 = sizeof( struct V_44 ) ;
break;
case V_45 :
V_53 = sizeof( T_1 ) ;
break;
default:
return - V_57 ;
}
V_31 -> V_34 = F_21 ( V_52 [ V_55 ] ) ;
return F_22 ( V_50 , V_31 -> V_34 , NULL ,
V_58 , V_53 ) ;
}
static int F_23 ( struct V_8 * V_9 ,
const struct V_26 * V_27 )
{
const struct V_30 * V_31 = F_11 ( V_27 ) ;
if ( F_24 ( V_9 , V_54 , F_25 ( V_31 -> V_36 ) ) )
goto V_59;
if ( F_26 ( V_9 , V_55 , V_31 -> V_34 ) )
goto V_59;
return 0 ;
V_59:
return - 1 ;
}
static int F_27 ( const struct V_49 * V_50 , const struct V_26 * V_27 ,
const struct V_60 * * V_33 )
{
const struct V_30 * V_31 = F_11 ( V_27 ) ;
unsigned int V_61 ;
switch ( V_31 -> V_36 ) {
case V_39 :
case V_42 :
case V_37 :
return 0 ;
case V_45 :
V_61 = ( 1 << V_62 ) |
( 1 << V_63 ) |
( 1 << V_64 ) ;
break;
default:
return - V_56 ;
}
return F_28 ( V_50 -> V_65 , V_61 ) ;
}
static int T_3 F_29 ( void )
{
return F_30 ( & V_66 ) ;
}
static void T_4 F_31 ( void )
{
F_32 ( & V_66 ) ;
}

int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 = {
. V_7 = V_4 ,
} ;
int V_8 ;
V_8 = F_2 ( V_9 ,
F_3 ( V_2 ) , 0 , & V_6 ) ;
V_4 -> V_10 = V_6 . V_11 ;
return V_8 ;
}
static int F_4 ( struct V_12 * V_11 , struct V_13 * V_2 ,
int V_14 , struct V_5 * V_6 )
{
struct V_1 * V_15 = & V_2 -> V_16 . V_17 ;
int V_8 = - V_18 ;
struct V_19 * V_20 ;
switch( V_11 -> V_21 ) {
case V_22 :
break;
case V_23 :
V_8 = - V_24 ;
goto V_25;
case V_26 :
V_8 = - V_27 ;
goto V_25;
case V_28 :
default:
V_8 = - V_29 ;
goto V_25;
}
V_20 = F_5 ( V_11 -> V_30 , 0 ) ;
if ( V_20 == NULL )
goto V_25;
V_8 = V_20 -> V_31 ( V_20 , V_15 , (struct V_3 * ) V_6 -> V_7 ) ;
if ( V_8 > 0 )
V_8 = - V_18 ;
V_25:
return V_8 ;
}
static int F_6 ( struct V_12 * V_11 , struct V_13 * V_32 , int V_14 )
{
struct V_33 * V_10 = (struct V_33 * ) V_11 ;
struct V_1 * V_15 = & V_32 -> V_16 . V_17 ;
T_1 V_34 = V_15 -> V_34 ;
T_1 V_35 = V_15 -> V_35 ;
if ( ( ( V_35 ^ V_10 -> V_36 ) & V_10 -> V_37 ) ||
( ( V_34 ^ V_10 -> V_38 ) & V_10 -> V_39 ) )
return 0 ;
return 1 ;
}
static int F_7 ( struct V_12 * V_11 , struct V_40 * V_41 ,
struct V_42 * V_43 ,
struct V_44 * * V_45 )
{
int V_8 = - V_29 ;
struct V_33 * V_10 = (struct V_33 * ) V_11 ;
if ( V_43 -> V_46 )
goto V_25;
if ( V_11 -> V_30 == V_47 ) {
if ( V_11 -> V_21 == V_22 ) {
struct V_19 * V_30 ;
V_30 = F_8 () ;
if ( V_30 == NULL ) {
V_8 = - V_48 ;
goto V_25;
}
V_11 -> V_30 = V_30 -> V_49 ;
}
}
if ( V_43 -> V_50 )
V_10 -> V_36 = F_9 ( V_45 [ V_51 ] ) ;
if ( V_43 -> V_52 )
V_10 -> V_38 = F_9 ( V_45 [ V_53 ] ) ;
V_10 -> V_50 = V_43 -> V_50 ;
V_10 -> V_37 = F_10 ( V_10 -> V_50 ) ;
V_10 -> V_52 = V_43 -> V_52 ;
V_10 -> V_39 = F_10 ( V_10 -> V_52 ) ;
V_8 = 0 ;
V_25:
return V_8 ;
}
static int F_11 ( struct V_12 * V_11 , struct V_42 * V_43 ,
struct V_44 * * V_45 )
{
struct V_33 * V_10 = (struct V_33 * ) V_11 ;
if ( V_43 -> V_50 && ( V_10 -> V_50 != V_43 -> V_50 ) )
return 0 ;
if ( V_43 -> V_52 && ( V_10 -> V_52 != V_43 -> V_52 ) )
return 0 ;
if ( V_43 -> V_50 && ( V_10 -> V_36 != F_9 ( V_45 [ V_51 ] ) ) )
return 0 ;
if ( V_43 -> V_52 && ( V_10 -> V_38 != F_9 ( V_45 [ V_53 ] ) ) )
return 0 ;
return 1 ;
}
unsigned int F_12 ( T_1 V_54 )
{
struct V_1 V_15 = { . V_34 = V_54 } ;
struct V_3 V_4 ;
unsigned int V_55 = V_56 ;
struct V_19 * V_45 = F_5 ( V_57 , 0 ) ;
V_4 . V_10 = NULL ;
if ( V_45 ) {
if ( ! V_45 -> V_31 ( V_45 , & V_15 , & V_4 ) ) {
V_55 = V_4 . type ;
F_13 ( & V_4 ) ;
}
}
return V_55 ;
}
static int F_14 ( struct V_12 * V_11 , struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_33 * V_10 = (struct V_33 * ) V_11 ;
V_43 -> V_52 = V_10 -> V_52 ;
V_43 -> V_50 = V_10 -> V_50 ;
V_43 -> V_46 = 0 ;
if ( ( V_10 -> V_52 &&
F_15 ( V_41 , V_53 , V_10 -> V_38 ) ) ||
( V_10 -> V_50 &&
F_15 ( V_41 , V_51 , V_10 -> V_36 ) ) )
goto V_58;
return 0 ;
V_58:
return - V_48 ;
}
static void F_16 ( struct V_59 * V_60 )
{
F_17 ( - 1 ) ;
}
void T_2 F_18 ( void )
{
V_9 =
F_19 ( & V_61 , & V_62 ) ;
F_20 ( F_21 ( V_9 ) ) ;
F_20 ( F_22 ( V_9 , 0x7fff ,
V_63 , 0 ) ) ;
}
void T_3 F_23 ( void )
{
F_24 () ;
F_25 ( V_9 ) ;
F_26 () ;
F_27 () ;
}

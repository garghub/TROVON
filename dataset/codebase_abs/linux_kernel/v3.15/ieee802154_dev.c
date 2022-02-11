int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_3 * V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
int V_9 = 0 ;
F_3 () ;
if ( V_4 -> type == V_10 ) {
F_4 ( & V_4 -> V_8 -> V_11 ) ;
F_5 (subif, &priv->hw->slaves, list) {
if ( V_5 != V_4 && V_5 -> type == V_4 -> type &&
V_5 -> V_12 ) {
F_6 ( & V_4 -> V_8 -> V_11 ) ;
return - V_13 ;
}
}
F_6 ( & V_4 -> V_8 -> V_11 ) ;
}
F_4 ( & V_4 -> V_8 -> V_11 ) ;
V_4 -> V_12 = true ;
F_6 ( & V_4 -> V_8 -> V_11 ) ;
if ( V_7 -> V_14 ++ == 0 ) {
V_9 = V_7 -> V_15 -> V_16 ( & V_7 -> V_8 ) ;
F_7 ( V_9 ) ;
if ( V_9 )
goto V_17;
}
if ( V_7 -> V_15 -> V_18 ) {
T_1 V_19 = F_8 ( V_2 -> V_20 ) ;
V_9 = V_7 -> V_15 -> V_18 ( & V_7 -> V_8 , V_19 ) ;
F_7 ( V_9 ) ;
if ( V_9 )
goto V_17;
F_9 ( V_2 ) ;
}
F_10 ( V_2 ) ;
return 0 ;
V_17:
V_4 -> V_8 -> V_14 -- ;
return V_9 ;
}
int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_4 -> V_8 ;
F_3 () ;
F_12 ( V_2 ) ;
F_4 ( & V_4 -> V_8 -> V_11 ) ;
V_4 -> V_12 = false ;
F_6 ( & V_4 -> V_8 -> V_11 ) ;
if ( ! -- V_7 -> V_14 )
V_7 -> V_15 -> V_21 ( & V_7 -> V_8 ) ;
return 0 ;
}
static int
F_13 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
int V_17 ;
V_7 = F_14 ( V_23 ) ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_8 = V_7 ;
V_2 -> V_24 = V_7 -> V_8 . V_25 ;
F_15 ( V_2 , & V_7 -> V_23 -> V_2 ) ;
F_4 ( & V_7 -> V_11 ) ;
if ( ! V_7 -> V_12 ) {
F_6 ( & V_7 -> V_11 ) ;
return - V_26 ;
}
F_6 ( & V_7 -> V_11 ) ;
V_17 = F_16 ( V_2 ) ;
if ( V_17 < 0 )
return V_17 ;
F_17 () ;
F_4 ( & V_7 -> V_11 ) ;
F_18 ( & V_4 -> V_27 , & V_7 -> V_28 ) ;
F_6 ( & V_7 -> V_11 ) ;
F_19 () ;
return 0 ;
}
static void
F_20 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
struct V_3 * V_29 ;
F_3 () ;
V_29 = F_2 ( V_2 ) ;
F_21 ( V_29 -> V_8 -> V_23 != V_23 ) ;
F_4 ( & V_29 -> V_8 -> V_11 ) ;
F_22 ( & V_29 -> V_27 ) ;
F_6 ( & V_29 -> V_8 -> V_11 ) ;
F_23 () ;
F_24 ( V_29 -> V_2 ) ;
}
static struct V_1 *
F_25 ( struct V_22 * V_23 , const char * V_30 , int type )
{
struct V_1 * V_2 ;
int V_17 = - V_31 ;
switch ( type ) {
case V_32 :
V_2 = F_26 ( sizeof( struct V_3 ) ,
V_30 , V_33 ) ;
break;
case V_10 :
V_2 = F_26 ( sizeof( struct V_3 ) ,
V_30 , V_34 ) ;
break;
default:
V_2 = NULL ;
V_17 = - V_35 ;
break;
}
if ( ! V_2 )
goto V_17;
V_17 = F_13 ( V_23 , V_2 ) ;
if ( V_17 )
goto V_36;
F_27 ( V_2 ) ;
return V_2 ;
V_36:
F_28 ( V_2 ) ;
V_17:
return F_29 ( V_17 ) ;
}
static int F_30 ( struct V_22 * V_23 , int V_37 )
{
struct V_6 * V_4 = F_14 ( V_23 ) ;
return V_4 -> V_15 -> V_38 ( & V_4 -> V_8 , V_37 ) ;
}
static int F_31 ( struct V_22 * V_23 , bool V_39 )
{
struct V_6 * V_4 = F_14 ( V_23 ) ;
return V_4 -> V_15 -> V_40 ( & V_4 -> V_8 , V_39 ) ;
}
static int F_32 ( struct V_22 * V_23 , T_2 V_41 )
{
struct V_6 * V_4 = F_14 ( V_23 ) ;
return V_4 -> V_15 -> V_42 ( & V_4 -> V_8 , V_41 ) ;
}
static int F_33 ( struct V_22 * V_23 , T_3 V_43 )
{
struct V_6 * V_4 = F_14 ( V_23 ) ;
return V_4 -> V_15 -> V_44 ( & V_4 -> V_8 , V_43 ) ;
}
static int F_34 ( struct V_22 * V_23 , T_2 V_45 ,
T_2 V_46 , T_2 V_47 )
{
struct V_6 * V_4 = F_14 ( V_23 ) ;
return V_4 -> V_15 -> V_48 ( & V_4 -> V_8 , V_45 , V_46 , V_47 ) ;
}
static int F_35 ( struct V_22 * V_23 , T_4 V_47 )
{
struct V_6 * V_4 = F_14 ( V_23 ) ;
return V_4 -> V_15 -> V_49 ( & V_4 -> V_8 , V_47 ) ;
}
struct V_50 *
F_36 ( T_5 V_51 , struct V_52 * V_15 )
{
struct V_22 * V_23 ;
struct V_6 * V_4 ;
T_5 V_53 ;
if ( ! V_15 || ! V_15 -> V_54 || ! V_15 -> V_55 || ! V_15 -> V_16 ||
! V_15 -> V_21 || ! V_15 -> V_56 ) {
F_37 ( L_1 ) ;
return NULL ;
}
V_53 = F_38 ( sizeof( * V_4 ) , V_57 ) + V_51 ;
V_23 = F_39 ( V_53 ) ;
if ( ! V_23 ) {
F_37 ( L_2 ) ;
return NULL ;
}
V_4 = F_14 ( V_23 ) ;
V_4 -> V_8 . V_23 = V_4 -> V_23 = V_23 ;
V_4 -> V_8 . V_4 = ( char * ) V_4 + F_38 ( sizeof( * V_4 ) , V_57 ) ;
V_4 -> V_15 = V_15 ;
F_40 ( & V_4 -> V_28 ) ;
F_41 ( & V_4 -> V_11 ) ;
return & V_4 -> V_8 ;
}
void F_42 ( struct V_50 * V_8 )
{
struct V_6 * V_4 = F_43 ( V_8 ) ;
F_21 ( ! F_44 ( & V_4 -> V_28 ) ) ;
F_45 ( & V_4 -> V_11 ) ;
F_46 ( V_4 -> V_23 ) ;
}
int F_47 ( struct V_50 * V_2 )
{
struct V_6 * V_4 = F_43 ( V_2 ) ;
int V_58 = - V_31 ;
V_4 -> V_59 =
F_48 ( F_49 ( V_4 -> V_23 ) ) ;
if ( ! V_4 -> V_59 )
goto V_60;
F_50 ( V_4 -> V_23 , V_4 -> V_8 . V_61 ) ;
V_4 -> V_23 -> V_62 = F_25 ;
V_4 -> V_23 -> V_63 = F_20 ;
if ( V_4 -> V_15 -> V_38 )
V_4 -> V_23 -> V_38 = F_30 ;
if ( V_4 -> V_15 -> V_40 )
V_4 -> V_23 -> V_40 = F_31 ;
if ( V_4 -> V_15 -> V_42 )
V_4 -> V_23 -> V_42 = F_32 ;
if ( V_4 -> V_15 -> V_44 )
V_4 -> V_23 -> V_44 = F_33 ;
if ( V_4 -> V_15 -> V_48 )
V_4 -> V_23 -> V_48 = F_34 ;
if ( V_4 -> V_15 -> V_49 )
V_4 -> V_23 -> V_49 = F_35 ;
V_58 = F_51 ( V_4 -> V_23 ) ;
if ( V_58 < 0 )
goto V_64;
F_17 () ;
F_4 ( & V_4 -> V_11 ) ;
V_4 -> V_12 = V_65 ;
F_6 ( & V_4 -> V_11 ) ;
F_19 () ;
return 0 ;
V_64:
F_52 ( V_4 -> V_59 ) ;
V_60:
return V_58 ;
}
void F_53 ( struct V_50 * V_2 )
{
struct V_6 * V_4 = F_43 ( V_2 ) ;
struct V_3 * V_29 , * V_66 ;
F_54 ( V_4 -> V_59 ) ;
F_52 ( V_4 -> V_59 ) ;
F_17 () ;
F_4 ( & V_4 -> V_11 ) ;
V_4 -> V_12 = V_67 ;
F_6 ( & V_4 -> V_11 ) ;
F_55 (sdata, next, &priv->slaves, list) {
F_4 ( & V_29 -> V_8 -> V_11 ) ;
F_56 ( & V_29 -> V_27 ) ;
F_6 ( & V_29 -> V_8 -> V_11 ) ;
F_24 ( V_29 -> V_2 ) ;
}
F_19 () ;
F_57 ( V_4 -> V_23 ) ;
}

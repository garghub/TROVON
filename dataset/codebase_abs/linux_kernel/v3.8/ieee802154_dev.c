int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
int V_8 = 0 ;
if ( V_6 -> V_9 ++ == 0 ) {
V_8 = V_6 -> V_10 -> V_11 ( & V_6 -> V_7 ) ;
F_3 ( V_8 ) ;
if ( V_8 )
goto V_12;
}
if ( V_6 -> V_10 -> V_13 ) {
V_8 = V_6 -> V_10 -> V_13 ( & V_6 -> V_7 , V_2 -> V_14 ) ;
F_3 ( V_8 ) ;
if ( V_8 )
goto V_12;
F_4 ( V_2 ) ;
}
F_5 ( V_2 ) ;
return 0 ;
V_12:
V_4 -> V_7 -> V_9 -- ;
return V_8 ;
}
int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
F_7 ( V_2 ) ;
if ( ! -- V_6 -> V_9 )
V_6 -> V_10 -> V_15 ( & V_6 -> V_7 ) ;
return 0 ;
}
static int
F_8 ( struct V_16 * V_17 , struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_12 ;
V_6 = F_9 ( V_17 ) ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_7 = V_6 ;
V_2 -> V_18 = V_6 -> V_7 . V_19 ;
F_10 ( V_2 , & V_6 -> V_17 -> V_2 ) ;
F_11 ( & V_6 -> V_20 ) ;
if ( ! V_6 -> V_21 ) {
F_12 ( & V_6 -> V_20 ) ;
return - V_22 ;
}
F_12 ( & V_6 -> V_20 ) ;
V_12 = F_13 ( V_2 ) ;
if ( V_12 < 0 )
return V_12 ;
F_14 () ;
F_11 ( & V_6 -> V_20 ) ;
F_15 ( & V_4 -> V_23 , & V_6 -> V_24 ) ;
F_12 ( & V_6 -> V_20 ) ;
F_16 () ;
return 0 ;
}
static void
F_17 ( struct V_16 * V_17 , struct V_1 * V_2 )
{
struct V_3 * V_25 ;
F_18 () ;
V_25 = F_2 ( V_2 ) ;
F_19 ( V_25 -> V_7 -> V_17 != V_17 ) ;
F_11 ( & V_25 -> V_7 -> V_20 ) ;
F_20 ( & V_25 -> V_23 ) ;
F_12 ( & V_25 -> V_7 -> V_20 ) ;
F_21 () ;
F_22 ( V_25 -> V_2 ) ;
}
static struct V_1 *
F_23 ( struct V_16 * V_17 , const char * V_26 , int type )
{
struct V_1 * V_2 ;
int V_12 = - V_27 ;
switch ( type ) {
case V_28 :
V_2 = F_24 ( sizeof( struct V_3 ) ,
V_26 , V_29 ) ;
break;
case V_30 :
V_2 = F_24 ( sizeof( struct V_3 ) ,
V_26 , V_31 ) ;
break;
default:
V_2 = NULL ;
V_12 = - V_32 ;
break;
}
if ( ! V_2 )
goto V_12;
V_12 = F_8 ( V_17 , V_2 ) ;
if ( V_12 )
goto V_33;
F_25 ( V_2 ) ;
return V_2 ;
V_33:
F_26 ( V_2 ) ;
V_12:
return F_27 ( V_12 ) ;
}
struct V_34 *
F_28 ( T_1 V_35 , struct V_36 * V_10 )
{
struct V_16 * V_17 ;
struct V_5 * V_4 ;
T_1 V_37 ;
if ( ! V_10 || ! V_10 -> V_38 || ! V_10 -> V_39 || ! V_10 -> V_11 ||
! V_10 -> V_15 || ! V_10 -> V_40 ) {
F_29 ( V_41
L_1 ) ;
return NULL ;
}
V_37 = F_30 ( sizeof( * V_4 ) , V_42 ) + V_35 ;
V_17 = F_31 ( V_37 ) ;
if ( ! V_17 ) {
F_29 ( V_41
L_2 ) ;
return NULL ;
}
V_4 = F_9 ( V_17 ) ;
V_4 -> V_7 . V_17 = V_4 -> V_17 = V_17 ;
V_4 -> V_7 . V_4 = ( char * ) V_4 + F_30 ( sizeof( * V_4 ) , V_42 ) ;
V_4 -> V_10 = V_10 ;
F_32 ( & V_4 -> V_24 ) ;
F_33 ( & V_4 -> V_20 ) ;
return & V_4 -> V_7 ;
}
void F_34 ( struct V_34 * V_7 )
{
struct V_5 * V_4 = F_35 ( V_7 ) ;
F_19 ( ! F_36 ( & V_4 -> V_24 ) ) ;
F_37 ( & V_4 -> V_20 ) ;
F_38 ( V_4 -> V_17 ) ;
}
int F_39 ( struct V_34 * V_2 )
{
struct V_5 * V_4 = F_35 ( V_2 ) ;
int V_43 = - V_27 ;
V_4 -> V_44 =
F_40 ( F_41 ( V_4 -> V_17 ) ) ;
if ( ! V_4 -> V_44 )
goto V_45;
F_42 ( V_4 -> V_17 , V_4 -> V_7 . V_46 ) ;
V_4 -> V_17 -> V_47 = F_23 ;
V_4 -> V_17 -> V_48 = F_17 ;
V_43 = F_43 ( V_4 -> V_17 ) ;
if ( V_43 < 0 )
goto V_49;
F_14 () ;
F_11 ( & V_4 -> V_20 ) ;
V_4 -> V_21 = V_50 ;
F_12 ( & V_4 -> V_20 ) ;
F_16 () ;
return 0 ;
V_49:
F_44 ( V_4 -> V_44 ) ;
V_45:
return V_43 ;
}
void F_45 ( struct V_34 * V_2 )
{
struct V_5 * V_4 = F_35 ( V_2 ) ;
struct V_3 * V_25 , * V_51 ;
F_46 ( V_4 -> V_44 ) ;
F_44 ( V_4 -> V_44 ) ;
F_14 () ;
F_11 ( & V_4 -> V_20 ) ;
V_4 -> V_21 = V_52 ;
F_12 ( & V_4 -> V_20 ) ;
F_47 (sdata, next, &priv->slaves, list) {
F_11 ( & V_25 -> V_7 -> V_20 ) ;
F_48 ( & V_25 -> V_23 ) ;
F_12 ( & V_25 -> V_7 -> V_20 ) ;
F_22 ( V_25 -> V_2 ) ;
}
F_16 () ;
F_49 ( V_4 -> V_17 ) ;
}

int F_1 ( struct V_1 * V_2 )
{
struct V_1 T_1 * * V_3 ;
struct V_1 * V_4 ;
int V_5 = - V_6 ;
int V_7 = V_2 -> V_7 ;
F_2 ( & V_8 ) ;
for ( V_3 = & V_9 ;
( V_4 = F_3 ( * V_3 ,
F_4 ( & V_8 ) ) ) != NULL ;
V_3 = & V_4 -> V_10 ) {
if ( V_4 -> V_7 > V_7 )
break;
if ( V_4 -> V_7 == V_7 )
goto V_11;
}
V_2 -> V_10 = * V_3 ;
F_5 ( * V_3 , V_2 ) ;
V_5 = 0 ;
V_11:
F_6 ( & V_8 ) ;
return V_5 ;
}
int F_7 ( struct V_1 * V_2 )
{
struct V_1 T_1 * * V_3 ;
struct V_1 * V_4 ;
int V_5 = - V_12 ;
F_2 ( & V_8 ) ;
for ( V_3 = & V_9 ;
( V_4 = F_3 ( * V_3 ,
F_4 ( & V_8 ) ) ) != NULL ;
V_3 = & V_4 -> V_10 ) {
if ( V_4 == V_2 ) {
* V_3 = V_2 -> V_10 ;
V_5 = 0 ;
break;
}
}
F_6 ( & V_8 ) ;
F_8 () ;
return V_5 ;
}
static inline void F_9 ( struct V_13 * V_14 )
{
const struct V_15 * V_16 = F_10 ( V_14 ) ;
struct V_15 * V_17 = F_11 ( V_14 ) ;
if ( F_12 ( F_13 ( V_16 ) ) )
F_14 ( V_17 ) ;
}
static int F_15 ( struct V_18 * V_19 , struct V_13 * V_14 )
{
struct V_20 * V_21 = F_16 ( V_14 ) ;
struct V_15 * V_22 ;
int V_23 ;
F_17 ( V_14 , - V_19 -> V_24 . V_25 ) ;
V_14 -> V_26 = V_14 -> V_27 +
F_18 ( struct V_15 , V_28 ) ;
V_14 -> V_29 = V_14 -> V_27 + sizeof( * V_22 ) ;
V_22 = F_10 ( V_14 ) ;
V_22 -> V_30 = 6 ;
memcpy ( V_22 -> V_31 , F_19 ( V_14 ) -> V_31 ,
sizeof( V_22 -> V_31 ) ) ;
V_22 -> V_28 = F_20 ( F_16 ( V_14 ) -> V_32 -> V_33 ) ;
if ( V_19 -> V_24 . V_34 & V_35 )
V_23 = 0 ;
else
V_23 = F_19 ( V_14 ) -> V_36 ;
V_23 = F_21 ( V_23 , F_19 ( V_14 ) -> V_36 ) ;
if ( V_19 -> V_24 . V_37 & V_38 )
V_23 &= ~ V_39 ;
F_22 ( V_22 , 0 , V_23 ) ;
V_22 -> V_40 = F_23 ( V_21 -> V_41 ) ;
V_22 -> V_42 = * (struct V_43 * ) & V_19 -> V_24 . V_42 ;
V_22 -> V_44 = * (struct V_43 * ) & V_19 -> V_45 . V_44 ;
return 0 ;
}
static int F_24 ( struct V_18 * V_19 , struct V_13 * V_14 )
{
struct V_1 * V_2 ;
int V_11 = - V_46 ;
if ( F_19 ( V_14 ) -> V_47 != V_48 )
goto V_49;
if ( ! F_25 ( V_14 , sizeof( struct V_15 ) ) )
goto V_49;
F_26 (rcv_notify_handlers, handler)
V_2 -> V_2 ( V_14 ) ;
V_11 = F_27 ( V_14 , V_50 ) ;
if ( V_11 )
goto V_49;
if ( V_19 -> V_24 . V_37 & V_51 )
F_28 ( F_13 ( F_10 ( V_14 ) ) ,
F_11 ( V_14 ) ) ;
if ( ! ( V_19 -> V_24 . V_37 & V_38 ) )
F_9 ( V_14 ) ;
F_29 ( V_14 ) ;
F_30 ( V_14 ) ;
V_11 = 0 ;
V_49:
return V_11 ;
}
static int T_2 F_31 ( void )
{
return F_32 ( & V_52 , V_53 ) ;
}
static void T_3 F_33 ( void )
{
int V_11 ;
V_11 = F_34 ( & V_52 , V_53 ) ;
F_35 ( V_11 ) ;
}

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
struct V_15 * V_16 = F_10 ( V_14 ) ;
if ( F_11 ( F_12 ( V_14 ) -> V_17 ) )
F_13 ( V_16 ) ;
}
static int F_14 ( struct V_18 * V_19 , struct V_13 * V_14 )
{
struct V_20 * V_21 = F_15 ( V_14 ) ;
struct V_15 * V_22 ;
int V_23 ;
F_16 ( V_14 , - V_19 -> V_24 . V_25 ) ;
V_14 -> V_26 = V_14 -> V_27 +
F_17 ( struct V_15 , V_28 ) ;
V_14 -> V_29 = V_14 -> V_27 + sizeof( * V_22 ) ;
V_22 = F_18 ( V_14 ) ;
V_22 -> V_30 = 5 ;
V_22 -> V_31 = 4 ;
V_22 -> V_28 = F_19 ( F_15 ( V_14 ) -> V_32 -> V_33 ) ;
V_22 -> V_17 = F_20 ( F_12 ( V_14 ) -> V_17 ,
F_12 ( V_14 ) -> V_17 ) ;
V_23 = V_19 -> V_24 . V_23 ;
if ( V_23 & V_34 )
F_21 ( V_22 ) ;
V_22 -> V_35 = ( V_23 & V_36 ) ?
0 : ( F_12 ( V_14 ) -> V_35 & F_22 ( V_37 ) ) ;
F_23 ( V_22 , V_21 -> V_38 , NULL ) ;
V_22 -> V_39 = F_24 ( V_21 -> V_38 ) ;
V_22 -> V_40 = V_19 -> V_24 . V_40 . V_41 ;
V_22 -> V_42 = V_19 -> V_43 . V_42 . V_41 ;
return 0 ;
}
static int F_25 ( struct V_18 * V_19 , struct V_13 * V_14 )
{
struct V_1 * V_2 ;
int V_11 = - V_44 ;
if ( F_12 ( V_14 ) -> V_28 != V_45 )
goto V_46;
if ( ! F_26 ( V_14 , sizeof( struct V_15 ) ) )
goto V_46;
F_27 (rcv_notify_handlers, handler)
V_2 -> V_2 ( V_14 ) ;
if ( F_28 ( V_14 ) &&
( V_11 = F_29 ( V_14 , 0 , 0 , V_47 ) ) )
goto V_46;
if ( V_19 -> V_24 . V_23 & V_48 )
F_30 ( F_12 ( V_14 ) -> V_17 , F_10 ( V_14 ) ) ;
if ( ! ( V_19 -> V_24 . V_23 & V_34 ) )
F_9 ( V_14 ) ;
F_31 ( V_14 ) ;
F_32 ( V_14 ) ;
V_11 = 0 ;
V_46:
return V_11 ;
}
static int T_2 F_33 ( void )
{
return F_34 ( & V_49 , V_50 ) ;
}
static void T_3 F_35 ( void )
{
int V_11 ;
V_11 = F_36 ( & V_49 , V_50 ) ;
F_37 ( V_11 ) ;
}

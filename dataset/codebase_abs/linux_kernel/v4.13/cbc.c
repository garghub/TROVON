static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 ;
F_3 ( V_8 , V_10 ) ;
F_4 ( V_8 , F_5 ( V_2 ) &
V_10 ) ;
V_9 = F_6 ( V_8 , V_3 , V_4 ) ;
F_7 ( V_2 , F_8 ( V_8 ) &
V_11 ) ;
return V_9 ;
}
static inline void F_9 ( struct V_1 * V_12 ,
const T_1 * V_13 , T_1 * V_14 )
{
struct V_5 * V_6 = F_2 ( V_12 ) ;
F_10 ( V_6 -> V_8 , V_14 , V_13 ) ;
}
static int F_11 ( struct V_15 * V_16 )
{
return F_12 ( V_16 , F_9 ) ;
}
static inline void F_13 ( struct V_1 * V_12 ,
const T_1 * V_13 , T_1 * V_14 )
{
struct V_5 * V_6 = F_2 ( V_12 ) ;
F_14 ( V_6 -> V_8 , V_14 , V_13 ) ;
}
static int F_15 ( struct V_15 * V_16 )
{
struct V_1 * V_12 = F_16 ( V_16 ) ;
struct V_17 V_18 ;
int V_9 ;
V_9 = F_17 ( & V_18 , V_16 , false ) ;
while ( V_18 . V_19 ) {
V_9 = F_18 ( & V_18 , V_12 ,
F_13 ) ;
V_9 = F_19 ( & V_18 , V_9 ) ;
}
return V_9 ;
}
static int F_20 ( struct V_1 * V_12 )
{
struct V_20 * V_21 = F_21 ( V_12 ) ;
struct V_22 * V_23 = F_22 ( V_21 ) ;
struct V_5 * V_6 = F_2 ( V_12 ) ;
struct V_7 * V_24 ;
V_24 = F_23 ( V_23 ) ;
if ( F_24 ( V_24 ) )
return F_25 ( V_24 ) ;
V_6 -> V_8 = V_24 ;
return 0 ;
}
static void F_26 ( struct V_1 * V_12 )
{
struct V_5 * V_6 = F_2 ( V_12 ) ;
F_27 ( V_6 -> V_8 ) ;
}
static void F_28 ( struct V_20 * V_21 )
{
F_29 ( F_22 ( V_21 ) ) ;
F_30 ( V_21 ) ;
}
static int F_31 ( struct V_25 * V_26 , struct V_27 * * V_28 )
{
struct V_20 * V_21 ;
struct V_29 * V_30 ;
struct V_22 * V_23 ;
struct V_31 * V_32 ;
T_2 V_33 ;
int V_9 ;
V_9 = F_32 ( V_28 , V_34 ) ;
if ( V_9 )
return V_9 ;
V_21 = F_33 ( sizeof( * V_21 ) + sizeof( * V_23 ) , V_35 ) ;
if ( ! V_21 )
return - V_36 ;
V_30 = F_34 ( V_28 ) ;
V_9 = F_25 ( V_30 ) ;
if ( F_24 ( V_30 ) )
goto V_37;
V_33 = V_38 |
F_35 ( V_30 -> type , V_30 -> V_33 ,
V_39 ) ;
V_32 = F_36 ( V_28 , V_40 , V_33 ) ;
V_9 = F_25 ( V_32 ) ;
if ( F_24 ( V_32 ) )
goto V_37;
V_23 = F_22 ( V_21 ) ;
V_9 = F_37 ( V_23 , V_32 , F_38 ( V_21 ) ,
V_38 ) ;
F_39 ( V_32 ) ;
if ( V_9 )
goto V_37;
V_9 = F_40 ( F_38 ( V_21 ) , L_1 , V_32 ) ;
if ( V_9 )
goto V_41;
V_9 = - V_42 ;
if ( ! F_41 ( V_32 -> V_43 ) )
goto V_41;
V_21 -> V_32 . V_44 . V_45 = V_32 -> V_45 ;
V_21 -> V_32 . V_44 . V_43 = V_32 -> V_43 ;
V_21 -> V_32 . V_44 . V_46 = V_32 -> V_46 ;
V_21 -> V_32 . V_47 = V_32 -> V_43 ;
V_21 -> V_32 . V_48 = V_32 -> V_49 . V_50 ;
V_21 -> V_32 . V_51 = V_32 -> V_49 . V_52 ;
V_21 -> V_32 . V_44 . V_53 = sizeof( struct V_5 ) ;
V_21 -> V_32 . V_54 = F_20 ;
V_21 -> V_32 . exit = F_26 ;
V_21 -> V_32 . V_55 = F_1 ;
V_21 -> V_32 . V_56 = F_11 ;
V_21 -> V_32 . V_57 = F_15 ;
V_21 -> free = F_28 ;
V_9 = F_42 ( V_26 , V_21 ) ;
if ( V_9 )
goto V_41;
V_58:
return V_9 ;
V_41:
F_43 ( V_23 ) ;
V_37:
F_30 ( V_21 ) ;
goto V_58;
}
static int T_3 F_44 ( void )
{
return F_45 ( & V_59 ) ;
}
static void T_4 F_46 ( void )
{
F_47 ( & V_59 ) ;
}

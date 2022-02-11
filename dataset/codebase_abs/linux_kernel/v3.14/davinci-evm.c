static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
struct V_11 * V_12 = V_6 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
int V_16 = 0 ;
unsigned V_17 = ( (struct V_18 * )
F_2 ( V_14 ) ) -> V_17 ;
V_16 = F_3 ( V_9 , 0 , V_17 , V_19 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_3 ( V_10 , 0 , V_17 , V_19 ) ;
if ( V_16 < 0 )
return V_16 ;
return 0 ;
}
static int F_4 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_12 ;
struct V_20 * V_21 = & V_12 -> V_21 ;
struct V_22 * V_23 = V_12 -> V_15 -> V_24 -> V_25 ;
int V_16 ;
F_5 ( V_21 , V_26 ,
F_6 ( V_26 ) ) ;
if ( V_23 ) {
V_16 = F_7 ( V_12 -> V_15 ,
L_1 ) ;
if ( V_16 )
return V_16 ;
} else {
F_8 ( V_21 , V_27 , F_6 ( V_27 ) ) ;
}
F_9 ( V_21 , L_2 ) ;
F_9 ( V_21 , L_3 ) ;
F_9 ( V_21 , L_4 ) ;
F_10 ( V_21 , L_5 ) ;
F_10 ( V_21 , L_6 ) ;
F_10 ( V_21 , L_7 ) ;
F_10 ( V_21 , L_8 ) ;
return 0 ;
}
static int F_11 ( struct V_28 * V_29 )
{
struct V_22 * V_23 = V_29 -> V_24 . V_25 ;
const struct V_30 * V_31 =
F_12 ( F_13 ( V_32 ) , & V_29 -> V_24 ) ;
struct V_33 * V_34 = (struct V_33 * ) V_31 -> V_35 ;
struct V_18 * V_36 = NULL ;
int V_16 = 0 ;
V_37 . V_38 = V_34 ;
V_34 -> V_39 = F_14 ( V_23 , L_9 , 0 ) ;
if ( ! V_34 -> V_39 )
return - V_40 ;
V_34 -> V_41 = F_14 ( V_23 , L_10 , 0 ) ;
if ( ! V_34 -> V_41 )
return - V_40 ;
V_34 -> V_42 = V_34 -> V_41 ;
V_37 . V_24 = & V_29 -> V_24 ;
V_16 = F_15 ( & V_37 , L_11 ) ;
if ( V_16 )
return V_16 ;
V_36 = F_16 ( & V_29 -> V_24 , sizeof( * V_36 ) , V_43 ) ;
if ( ! V_36 )
return - V_44 ;
V_16 = F_17 ( V_23 , L_12 , & V_36 -> V_17 ) ;
if ( V_16 < 0 )
return - V_40 ;
F_18 ( & V_37 , V_36 ) ;
V_16 = F_19 ( & V_29 -> V_24 , & V_37 ) ;
if ( V_16 )
F_20 ( & V_29 -> V_24 , L_13 , V_16 ) ;
return V_16 ;
}
static int F_21 ( struct V_28 * V_29 )
{
struct V_13 * V_15 = F_22 ( V_29 ) ;
F_23 ( V_15 ) ;
return 0 ;
}
static int T_1 F_24 ( void )
{
struct V_13 * V_45 ;
int V_46 ;
int V_16 ;
#if F_25 ( V_47 )
if ( F_26 () )
return F_27 ( & V_48 ) ;
#endif
if ( F_28 () ) {
V_45 = & V_49 ;
V_46 = 0 ;
} else if ( F_29 () ) {
V_45 = & V_50 ;
V_46 = 1 ;
} else if ( F_30 () ) {
V_45 = & V_51 ;
V_46 = 0 ;
} else if ( F_31 () ) {
V_45 = & V_52 ;
V_46 = 0 ;
} else if ( F_32 () ) {
V_45 = & V_53 ;
V_46 = 1 ;
} else if ( F_33 () ) {
V_45 = & V_54 ;
V_46 = 0 ;
} else
return - V_40 ;
V_55 = F_34 ( L_14 , V_46 ) ;
if ( ! V_55 )
return - V_44 ;
F_35 ( V_55 , V_45 ) ;
V_16 = F_36 ( V_55 ) ;
if ( V_16 )
F_37 ( V_55 ) ;
return V_16 ;
}
static void T_2 F_38 ( void )
{
#if F_25 ( V_47 )
if ( F_26 () ) {
F_39 ( & V_48 ) ;
return;
}
#endif
F_40 ( V_55 ) ;
}

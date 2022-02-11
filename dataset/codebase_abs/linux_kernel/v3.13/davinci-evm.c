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
V_16 = F_3 ( V_9 , V_19 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_3 ( V_10 , V_19 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_4 ( V_9 , 0 , V_17 , V_20 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_4 ( V_10 , 0 , V_17 , V_20 ) ;
if ( V_16 < 0 )
return V_16 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_10 = V_6 -> V_10 ;
return F_3 ( V_10 , V_19 ) ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_12 ;
struct V_21 * V_22 = & V_12 -> V_22 ;
struct V_23 * V_24 = V_12 -> V_15 -> V_25 -> V_26 ;
int V_16 ;
F_7 ( V_22 , V_27 ,
F_8 ( V_27 ) ) ;
if ( V_24 ) {
V_16 = F_9 ( V_12 -> V_15 ,
L_1 ) ;
if ( V_16 )
return V_16 ;
} else {
F_10 ( V_22 , V_28 , F_8 ( V_28 ) ) ;
}
F_11 ( V_22 , L_2 ) ;
F_11 ( V_22 , L_3 ) ;
F_11 ( V_22 , L_4 ) ;
F_12 ( V_22 , L_5 ) ;
F_12 ( V_22 , L_6 ) ;
F_12 ( V_22 , L_7 ) ;
F_12 ( V_22 , L_8 ) ;
return 0 ;
}
static int F_13 ( struct V_29 * V_30 )
{
struct V_23 * V_24 = V_30 -> V_25 . V_26 ;
const struct V_31 * V_32 =
F_14 ( F_15 ( V_33 ) , & V_30 -> V_25 ) ;
struct V_34 * V_35 = (struct V_34 * ) V_32 -> V_36 ;
struct V_18 * V_37 = NULL ;
int V_16 = 0 ;
V_38 . V_39 = V_35 ;
V_35 -> V_40 = F_16 ( V_24 , L_9 , 0 ) ;
if ( ! V_35 -> V_40 )
return - V_41 ;
V_35 -> V_42 = F_16 ( V_24 , L_10 , 0 ) ;
if ( ! V_35 -> V_42 )
return - V_41 ;
V_35 -> V_43 = V_35 -> V_42 ;
V_38 . V_25 = & V_30 -> V_25 ;
V_16 = F_17 ( & V_38 , L_11 ) ;
if ( V_16 )
return V_16 ;
V_37 = F_18 ( & V_30 -> V_25 , sizeof( * V_37 ) , V_44 ) ;
if ( ! V_37 )
return - V_45 ;
V_16 = F_19 ( V_24 , L_12 , & V_37 -> V_17 ) ;
if ( V_16 < 0 )
return - V_41 ;
F_20 ( & V_38 , V_37 ) ;
V_16 = F_21 ( & V_30 -> V_25 , & V_38 ) ;
if ( V_16 )
F_22 ( & V_30 -> V_25 , L_13 , V_16 ) ;
return V_16 ;
}
static int F_23 ( struct V_29 * V_30 )
{
struct V_13 * V_15 = F_24 ( V_30 ) ;
F_25 ( V_15 ) ;
return 0 ;
}
static int T_1 F_26 ( void )
{
struct V_13 * V_46 ;
int V_47 ;
int V_16 ;
#if F_27 ( V_48 )
if ( F_28 () )
return F_29 ( & V_49 ) ;
#endif
if ( F_30 () ) {
V_46 = & V_50 ;
V_47 = 0 ;
} else if ( F_31 () ) {
V_46 = & V_51 ;
V_47 = 1 ;
} else if ( F_32 () ) {
V_46 = & V_52 ;
V_47 = 0 ;
} else if ( F_33 () ) {
V_46 = & V_53 ;
V_47 = 0 ;
} else if ( F_34 () ) {
V_46 = & V_54 ;
V_47 = 1 ;
} else if ( F_35 () ) {
V_46 = & V_55 ;
V_47 = 0 ;
} else
return - V_41 ;
V_56 = F_36 ( L_14 , V_47 ) ;
if ( ! V_56 )
return - V_45 ;
F_37 ( V_56 , V_46 ) ;
V_16 = F_38 ( V_56 ) ;
if ( V_16 )
F_39 ( V_56 ) ;
return V_16 ;
}
static void T_2 F_40 ( void )
{
#if F_27 ( V_48 )
if ( F_28 () ) {
F_41 ( & V_49 ) ;
return;
}
#endif
F_42 ( V_56 ) ;
}

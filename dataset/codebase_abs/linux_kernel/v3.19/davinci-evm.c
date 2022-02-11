static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 =
F_2 ( V_7 ) ;
if ( V_10 -> V_11 )
return F_3 ( V_10 -> V_11 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 =
F_2 ( V_7 ) ;
if ( V_10 -> V_11 )
F_5 ( V_10 -> V_11 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_14 * V_16 = V_4 -> V_16 ;
struct V_6 * V_7 = V_4 -> V_8 ;
int V_17 = 0 ;
unsigned V_18 = ( (struct V_9 * )
F_2 ( V_7 ) ) -> V_18 ;
V_17 = F_7 ( V_15 , 0 , V_18 , V_19 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_7 ( V_16 , 0 , V_18 , V_19 ) ;
if ( V_17 < 0 )
return V_17 ;
return 0 ;
}
static int F_8 ( struct V_3 * V_4 )
{
struct V_6 * V_8 = V_4 -> V_8 ;
struct V_20 * V_21 = V_4 -> V_21 ;
struct V_22 * V_23 = V_8 -> V_24 -> V_25 ;
int V_17 ;
F_9 ( & V_8 -> V_26 , V_27 ,
F_10 ( V_27 ) ) ;
if ( V_23 ) {
V_17 = F_11 ( V_8 , L_1 ) ;
if ( V_17 )
return V_17 ;
} else {
F_12 ( & V_8 -> V_26 , V_28 ,
F_10 ( V_28 ) ) ;
}
F_13 ( & V_21 -> V_26 , L_2 ) ;
F_13 ( & V_21 -> V_26 , L_3 ) ;
F_13 ( & V_21 -> V_26 , L_4 ) ;
return 0 ;
}
static int F_14 ( struct V_29 * V_30 )
{
struct V_22 * V_23 = V_30 -> V_24 . V_25 ;
const struct V_31 * V_32 =
F_15 ( F_16 ( V_33 ) , & V_30 -> V_24 ) ;
struct V_34 * V_35 = (struct V_34 * ) V_32 -> V_36 ;
struct V_9 * V_10 = NULL ;
struct V_37 * V_11 ;
int V_17 = 0 ;
V_38 . V_39 = V_35 ;
V_35 -> V_40 = F_17 ( V_23 , L_5 , 0 ) ;
if ( ! V_35 -> V_40 )
return - V_41 ;
V_35 -> V_42 = F_17 ( V_23 , L_6 , 0 ) ;
if ( ! V_35 -> V_42 )
return - V_41 ;
V_35 -> V_43 = V_35 -> V_42 ;
V_38 . V_24 = & V_30 -> V_24 ;
V_17 = F_18 ( & V_38 , L_7 ) ;
if ( V_17 )
return V_17 ;
V_11 = F_19 ( & V_30 -> V_24 , L_8 ) ;
if ( F_20 ( V_11 ) == - V_44 ) {
return - V_44 ;
} else if ( F_21 ( V_11 ) ) {
F_22 ( & V_30 -> V_24 , L_9 ) ;
V_11 = NULL ;
}
V_10 = F_23 ( & V_30 -> V_24 , sizeof( * V_10 ) , V_45 ) ;
if ( ! V_10 )
return - V_46 ;
V_10 -> V_11 = V_11 ;
V_17 = F_24 ( V_23 , L_10 , & V_10 -> V_18 ) ;
if ( V_17 < 0 ) {
if ( ! V_10 -> V_11 ) {
F_25 ( & V_30 -> V_24 ,
L_11 ) ;
return - V_41 ;
}
V_10 -> V_18 = F_26 ( V_10 -> V_11 ) ;
} else if ( V_10 -> V_11 ) {
unsigned int V_47 = V_10 -> V_18 ;
F_27 ( V_10 -> V_11 , V_10 -> V_18 ) ;
V_10 -> V_18 = F_26 ( V_10 -> V_11 ) ;
if ( V_10 -> V_18 != V_47 )
F_28 ( & V_30 -> V_24 ,
L_12 ,
V_47 , V_10 -> V_18 ) ;
}
F_29 ( & V_38 , V_10 ) ;
V_17 = F_30 ( & V_30 -> V_24 , & V_38 ) ;
if ( V_17 )
F_25 ( & V_30 -> V_24 , L_13 , V_17 ) ;
return V_17 ;
}
static int F_31 ( struct V_29 * V_30 )
{
struct V_6 * V_8 = F_32 ( V_30 ) ;
F_33 ( V_8 ) ;
return 0 ;
}
static int T_1 F_34 ( void )
{
struct V_6 * V_48 ;
int V_49 ;
int V_17 ;
#if F_35 ( V_50 )
if ( F_36 () )
return F_37 ( & V_51 ) ;
#endif
if ( F_38 () ) {
V_48 = & V_52 ;
V_49 = 0 ;
} else if ( F_39 () ) {
V_48 = & V_53 ;
V_49 = 1 ;
} else if ( F_40 () ) {
V_48 = & V_54 ;
V_49 = 0 ;
} else if ( F_41 () ) {
V_48 = & V_55 ;
V_49 = 0 ;
} else if ( F_42 () ) {
V_48 = & V_56 ;
V_49 = 1 ;
} else if ( F_43 () ) {
V_48 = & V_57 ;
V_49 = 0 ;
} else
return - V_41 ;
V_58 = F_44 ( L_14 , V_49 ) ;
if ( ! V_58 )
return - V_46 ;
F_45 ( V_58 , V_48 ) ;
V_17 = F_46 ( V_58 ) ;
if ( V_17 )
F_47 ( V_58 ) ;
return V_17 ;
}
static void T_2 F_48 ( void )
{
#if F_35 ( V_50 )
if ( F_36 () ) {
F_49 ( & V_51 ) ;
return;
}
#endif
F_50 ( V_58 ) ;
}

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
struct V_20 * V_21 = V_8 -> V_22 -> V_23 ;
int V_17 ;
F_9 ( & V_8 -> V_24 , V_25 ,
F_10 ( V_25 ) ) ;
if ( V_21 ) {
V_17 = F_11 ( V_8 , L_1 ) ;
if ( V_17 )
return V_17 ;
} else {
F_12 ( & V_8 -> V_24 , V_26 ,
F_10 ( V_26 ) ) ;
}
F_13 ( & V_8 -> V_24 , L_2 ) ;
F_13 ( & V_8 -> V_24 , L_3 ) ;
F_13 ( & V_8 -> V_24 , L_4 ) ;
return 0 ;
}
static int F_14 ( struct V_27 * V_28 )
{
struct V_20 * V_21 = V_28 -> V_22 . V_23 ;
const struct V_29 * V_30 =
F_15 ( F_16 ( V_31 ) , & V_28 -> V_22 ) ;
struct V_32 * V_33 = (struct V_32 * ) V_30 -> V_34 ;
struct V_9 * V_10 = NULL ;
struct V_35 * V_11 ;
int V_17 = 0 ;
V_36 . V_37 = V_33 ;
V_33 -> V_38 = F_17 ( V_21 , L_5 , 0 ) ;
if ( ! V_33 -> V_38 )
return - V_39 ;
V_33 -> V_40 = F_17 ( V_21 , L_6 , 0 ) ;
if ( ! V_33 -> V_40 )
return - V_39 ;
V_33 -> V_41 = V_33 -> V_40 ;
V_36 . V_22 = & V_28 -> V_22 ;
V_17 = F_18 ( & V_36 , L_7 ) ;
if ( V_17 )
return V_17 ;
V_11 = F_19 ( & V_28 -> V_22 , L_8 ) ;
if ( F_20 ( V_11 ) == - V_42 ) {
return - V_42 ;
} else if ( F_21 ( V_11 ) ) {
F_22 ( & V_28 -> V_22 , L_9 ) ;
V_11 = NULL ;
}
V_10 = F_23 ( & V_28 -> V_22 , sizeof( * V_10 ) , V_43 ) ;
if ( ! V_10 )
return - V_44 ;
V_10 -> V_11 = V_11 ;
V_17 = F_24 ( V_21 , L_10 , & V_10 -> V_18 ) ;
if ( V_17 < 0 ) {
if ( ! V_10 -> V_11 ) {
F_25 ( & V_28 -> V_22 ,
L_11 ) ;
return - V_39 ;
}
V_10 -> V_18 = F_26 ( V_10 -> V_11 ) ;
} else if ( V_10 -> V_11 ) {
unsigned int V_45 = V_10 -> V_18 ;
F_27 ( V_10 -> V_11 , V_10 -> V_18 ) ;
V_10 -> V_18 = F_26 ( V_10 -> V_11 ) ;
if ( V_10 -> V_18 != V_45 )
F_28 ( & V_28 -> V_22 ,
L_12 ,
V_45 , V_10 -> V_18 ) ;
}
F_29 ( & V_36 , V_10 ) ;
V_17 = F_30 ( & V_28 -> V_22 , & V_36 ) ;
if ( V_17 )
F_25 ( & V_28 -> V_22 , L_13 , V_17 ) ;
return V_17 ;
}
static int T_1 F_31 ( void )
{
struct V_6 * V_46 ;
int V_47 ;
int V_17 ;
#if F_32 ( V_48 )
if ( F_33 () )
return F_34 ( & V_49 ) ;
#endif
if ( F_35 () ) {
V_46 = & V_50 ;
V_47 = 0 ;
} else if ( F_36 () ) {
V_46 = & V_51 ;
V_47 = 1 ;
} else if ( F_37 () ) {
V_46 = & V_52 ;
V_47 = 0 ;
} else if ( F_38 () ) {
V_46 = & V_53 ;
V_47 = 0 ;
} else if ( F_39 () ) {
V_46 = & V_54 ;
V_47 = 1 ;
} else if ( F_40 () ) {
V_46 = & V_55 ;
V_47 = 0 ;
} else
return - V_39 ;
V_56 = F_41 ( L_14 , V_47 ) ;
if ( ! V_56 )
return - V_44 ;
F_42 ( V_56 , V_46 ) ;
V_17 = F_43 ( V_56 ) ;
if ( V_17 )
F_44 ( V_56 ) ;
return V_17 ;
}
static void T_2 F_45 ( void )
{
#if F_32 ( V_48 )
if ( F_33 () ) {
F_46 ( & V_49 ) ;
return;
}
#endif
F_47 ( V_56 ) ;
}

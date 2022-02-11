static struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_5 * V_6 = V_3 -> V_7 ;
const T_1 * V_8 ;
struct V_9 * V_10 ;
V_4 = F_2 ( V_3 , sizeof( struct V_1 ) ,
V_11 ) ;
if ( ! V_4 )
return F_3 ( - V_12 ) ;
V_4 -> V_10 = F_4 ( V_3 , V_3 -> V_7 ) ;
if ( ! V_4 -> V_10 )
return F_3 ( - V_13 ) ;
V_10 = V_4 -> V_10 ;
V_10 -> V_14 . V_15 = 0 ;
V_4 -> V_16 = V_10 -> V_14 . V_17 ;
if ( V_10 -> V_14 . V_18 == V_10 -> V_14 . V_19 ) {
V_4 -> V_20 = V_10 -> V_14 . V_18 ;
} else {
F_5 ( V_3 ,
L_1 ) ;
return F_3 ( - V_13 ) ;
}
if ( V_10 -> V_14 . V_21 )
V_4 -> V_22 = true ;
V_4 -> V_23 = F_6 ( V_6 , L_2 , 0 ) ;
if ( ( V_4 -> V_23 == - V_24 ) || ( V_4 -> V_23 == - V_25 ) )
return F_3 ( - V_25 ) ;
V_8 = F_7 ( V_6 , L_3 , NULL ) ;
if ( V_8 )
V_4 -> V_26 = F_8 ( * V_8 ) ;
if ( F_9 ( V_6 , L_4 , NULL ) )
V_4 -> V_27 = true ;
if ( F_9 ( V_6 , L_5 , NULL ) )
V_4 -> V_28 = true ;
if ( F_9 ( V_6 , L_6 , NULL ) )
V_4 -> V_29 = L_7 ;
return V_4 ;
}
static int F_10 ( struct V_30 * V_3 )
{
struct V_31 * V_32 = F_11 ( V_3 ) ;
if ( V_32 -> V_20 )
return V_32 -> V_20 ;
else
return - V_13 ;
}
static int F_12 ( struct V_30 * V_3 ,
unsigned V_33 )
{
struct V_31 * V_32 = F_11 ( V_3 ) ;
if ( V_33 != 0 )
return - V_13 ;
return V_32 -> V_20 ;
}
static int T_2 F_13 ( struct V_34 * V_35 )
{
struct V_1 * V_4 ;
struct V_31 * V_36 ;
struct V_37 V_38 = { } ;
int V_39 ;
if ( V_35 -> V_3 . V_7 ) {
V_4 = F_1 ( & V_35 -> V_3 ) ;
if ( F_14 ( V_4 ) )
return F_15 ( V_4 ) ;
} else {
V_4 = V_35 -> V_3 . V_40 ;
}
if ( ! V_4 )
return - V_12 ;
V_36 = F_2 ( & V_35 -> V_3 , sizeof( struct V_31 ) ,
V_11 ) ;
if ( V_36 == NULL ) {
F_5 ( & V_35 -> V_3 , L_8 ) ;
V_39 = - V_12 ;
goto V_41;
}
V_36 -> V_42 . V_17 = F_16 ( V_4 -> V_16 , V_11 ) ;
if ( V_36 -> V_42 . V_17 == NULL ) {
F_5 ( & V_35 -> V_3 , L_9 ) ;
V_39 = - V_12 ;
goto V_41;
}
V_36 -> V_42 . type = V_43 ;
V_36 -> V_42 . V_44 = V_45 ;
V_36 -> V_42 . V_46 = & V_47 ;
V_36 -> V_42 . V_48 = V_4 -> V_26 ;
if ( V_4 -> V_29 ) {
V_36 -> V_42 . V_16 = F_16 ( V_4 -> V_29 ,
V_11 ) ;
if ( ! V_36 -> V_42 . V_16 ) {
F_5 ( & V_35 -> V_3 ,
L_10 ) ;
V_39 = - V_12 ;
goto V_49;
}
}
if ( V_4 -> V_20 )
V_36 -> V_42 . V_50 = 1 ;
V_36 -> V_20 = V_4 -> V_20 ;
if ( V_4 -> V_23 >= 0 )
V_38 . V_51 = V_4 -> V_23 ;
V_38 . V_52 = ! V_4 -> V_27 ;
if ( V_4 -> V_22 ) {
if ( V_4 -> V_27 ) {
V_38 . V_53 |= V_54 ;
} else {
V_38 . V_53 |= V_55 ;
}
} else {
if ( V_4 -> V_27 ) {
V_38 . V_53 |= V_55 ;
} else {
V_38 . V_53 |= V_54 ;
}
}
if ( V_4 -> V_28 )
V_38 . V_53 |= V_56 ;
V_38 . V_3 = & V_35 -> V_3 ;
V_38 . V_10 = V_4 -> V_10 ;
V_38 . V_57 = V_36 ;
V_38 . V_7 = V_35 -> V_3 . V_7 ;
V_36 -> V_3 = F_17 ( & V_36 -> V_42 , & V_38 ) ;
if ( F_14 ( V_36 -> V_3 ) ) {
V_39 = F_15 ( V_36 -> V_3 ) ;
F_5 ( & V_35 -> V_3 , L_11 , V_39 ) ;
goto V_58;
}
F_18 ( V_35 , V_36 ) ;
F_19 ( & V_35 -> V_3 , L_12 , V_36 -> V_42 . V_17 ,
V_36 -> V_20 ) ;
return 0 ;
V_58:
F_20 ( V_36 -> V_42 . V_16 ) ;
V_49:
F_20 ( V_36 -> V_42 . V_17 ) ;
V_41:
return V_39 ;
}
static int T_3 F_21 ( struct V_34 * V_35 )
{
struct V_31 * V_36 = F_22 ( V_35 ) ;
F_23 ( V_36 -> V_3 ) ;
F_20 ( V_36 -> V_42 . V_16 ) ;
F_20 ( V_36 -> V_42 . V_17 ) ;
return 0 ;
}
static int T_4 F_24 ( void )
{
return F_25 ( & V_59 ) ;
}
static void T_5 F_26 ( void )
{
F_27 ( & V_59 ) ;
}

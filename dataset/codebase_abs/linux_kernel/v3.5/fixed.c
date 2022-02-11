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
return NULL ;
V_4 -> V_10 = F_3 ( V_3 , V_3 -> V_7 ) ;
if ( ! V_4 -> V_10 )
return NULL ;
V_10 = V_4 -> V_10 ;
V_10 -> V_12 . V_13 = 0 ;
V_4 -> V_14 = V_10 -> V_12 . V_15 ;
if ( V_10 -> V_12 . V_16 == V_10 -> V_12 . V_17 ) {
V_4 -> V_18 = V_10 -> V_12 . V_16 ;
} else {
F_4 ( V_3 ,
L_1 ) ;
return NULL ;
}
if ( V_10 -> V_12 . V_19 )
V_4 -> V_20 = true ;
V_4 -> V_21 = F_5 ( V_6 , L_2 , 0 ) ;
V_8 = F_6 ( V_6 , L_3 , NULL ) ;
if ( V_8 )
V_4 -> V_22 = F_7 ( * V_8 ) ;
if ( F_8 ( V_6 , L_4 , NULL ) )
V_4 -> V_23 = true ;
if ( F_8 ( V_6 , L_5 , NULL ) )
V_4 -> V_24 = true ;
return V_4 ;
}
static int F_9 ( struct V_25 * V_3 )
{
struct V_26 * V_27 = F_10 ( V_3 ) ;
return V_27 -> V_28 ;
}
static int F_11 ( struct V_25 * V_3 )
{
struct V_26 * V_27 = F_10 ( V_3 ) ;
F_12 ( V_27 -> V_21 , V_27 -> V_23 ) ;
V_27 -> V_28 = true ;
return 0 ;
}
static int F_13 ( struct V_25 * V_3 )
{
struct V_26 * V_27 = F_10 ( V_3 ) ;
F_12 ( V_27 -> V_21 , ! V_27 -> V_23 ) ;
V_27 -> V_28 = false ;
return 0 ;
}
static int F_14 ( struct V_25 * V_3 )
{
struct V_26 * V_27 = F_10 ( V_3 ) ;
return V_27 -> V_22 ;
}
static int F_15 ( struct V_25 * V_3 )
{
struct V_26 * V_27 = F_10 ( V_3 ) ;
if ( V_27 -> V_18 )
return V_27 -> V_18 ;
else
return - V_29 ;
}
static int F_16 ( struct V_25 * V_3 ,
unsigned V_30 )
{
struct V_26 * V_27 = F_10 ( V_3 ) ;
if ( V_30 != 0 )
return - V_29 ;
return V_27 -> V_18 ;
}
static int T_2 F_17 ( struct V_31 * V_32 )
{
struct V_1 * V_4 ;
struct V_26 * V_33 ;
struct V_34 V_35 = { } ;
int V_36 ;
if ( V_32 -> V_3 . V_7 )
V_4 = F_1 ( & V_32 -> V_3 ) ;
else
V_4 = V_32 -> V_3 . V_37 ;
if ( ! V_4 )
return - V_38 ;
V_33 = F_2 ( & V_32 -> V_3 , sizeof( struct V_26 ) ,
V_11 ) ;
if ( V_33 == NULL ) {
F_4 ( & V_32 -> V_3 , L_6 ) ;
V_36 = - V_38 ;
goto V_39;
}
V_33 -> V_40 . V_15 = F_18 ( V_4 -> V_14 , V_11 ) ;
if ( V_33 -> V_40 . V_15 == NULL ) {
F_4 ( & V_32 -> V_3 , L_7 ) ;
V_36 = - V_38 ;
goto V_39;
}
V_33 -> V_40 . type = V_41 ;
V_33 -> V_40 . V_42 = V_43 ;
if ( V_4 -> V_18 )
V_33 -> V_40 . V_44 = 1 ;
V_33 -> V_18 = V_4 -> V_18 ;
V_33 -> V_21 = V_4 -> V_21 ;
V_33 -> V_22 = V_4 -> V_22 ;
if ( F_19 ( V_4 -> V_21 ) ) {
int V_45 ;
V_33 -> V_23 = V_4 -> V_23 ;
if ( ! V_4 -> V_21 )
F_20 ( & V_32 -> V_3 ,
L_8 ) ;
V_33 -> V_28 = V_4 -> V_20 ;
V_36 = V_33 -> V_28 ?
V_4 -> V_23 : ! V_4 -> V_23 ;
V_45 = V_36 ? V_46 : V_47 ;
if ( V_4 -> V_24 )
V_45 |= V_48 ;
V_36 = F_21 ( V_4 -> V_21 , V_45 ,
V_4 -> V_14 ) ;
if ( V_36 ) {
F_4 ( & V_32 -> V_3 ,
L_9 ,
V_4 -> V_21 , V_36 ) ;
goto V_49;
}
V_33 -> V_40 . V_50 = & V_51 ;
} else {
V_33 -> V_40 . V_50 = & V_52 ;
}
V_35 . V_3 = & V_32 -> V_3 ;
V_35 . V_10 = V_4 -> V_10 ;
V_35 . V_53 = V_33 ;
V_35 . V_7 = V_32 -> V_3 . V_7 ;
V_33 -> V_3 = F_22 ( & V_33 -> V_40 , & V_35 ) ;
if ( F_23 ( V_33 -> V_3 ) ) {
V_36 = F_24 ( V_33 -> V_3 ) ;
F_4 ( & V_32 -> V_3 , L_10 , V_36 ) ;
goto V_54;
}
F_25 ( V_32 , V_33 ) ;
F_26 ( & V_32 -> V_3 , L_11 , V_33 -> V_40 . V_15 ,
V_33 -> V_18 ) ;
return 0 ;
V_54:
if ( F_19 ( V_4 -> V_21 ) )
F_27 ( V_4 -> V_21 ) ;
V_49:
F_28 ( V_33 -> V_40 . V_15 ) ;
V_39:
return V_36 ;
}
static int T_3 F_29 ( struct V_31 * V_32 )
{
struct V_26 * V_33 = F_30 ( V_32 ) ;
F_31 ( V_33 -> V_3 ) ;
if ( F_19 ( V_33 -> V_21 ) )
F_27 ( V_33 -> V_21 ) ;
F_28 ( V_33 -> V_40 . V_15 ) ;
return 0 ;
}
static int T_4 F_32 ( void )
{
return F_33 ( & V_55 ) ;
}
static void T_5 F_34 ( void )
{
F_35 ( & V_55 ) ;
}

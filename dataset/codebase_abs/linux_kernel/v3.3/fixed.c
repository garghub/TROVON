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
return V_4 ;
}
static int F_9 ( struct V_24 * V_3 )
{
struct V_25 * V_26 = F_10 ( V_3 ) ;
return V_26 -> V_27 ;
}
static int F_11 ( struct V_24 * V_3 )
{
struct V_25 * V_26 = F_10 ( V_3 ) ;
if ( F_12 ( V_26 -> V_21 ) ) {
F_13 ( V_26 -> V_21 , V_26 -> V_23 ) ;
V_26 -> V_27 = true ;
}
return 0 ;
}
static int F_14 ( struct V_24 * V_3 )
{
struct V_25 * V_26 = F_10 ( V_3 ) ;
if ( F_12 ( V_26 -> V_21 ) ) {
F_13 ( V_26 -> V_21 , ! V_26 -> V_23 ) ;
V_26 -> V_27 = false ;
}
return 0 ;
}
static int F_15 ( struct V_24 * V_3 )
{
struct V_25 * V_26 = F_10 ( V_3 ) ;
return V_26 -> V_22 ;
}
static int F_16 ( struct V_24 * V_3 )
{
struct V_25 * V_26 = F_10 ( V_3 ) ;
if ( V_26 -> V_18 )
return V_26 -> V_18 ;
else
return - V_28 ;
}
static int F_17 ( struct V_24 * V_3 ,
unsigned V_29 )
{
struct V_25 * V_26 = F_10 ( V_3 ) ;
if ( V_29 != 0 )
return - V_28 ;
return V_26 -> V_18 ;
}
static int T_2 F_18 ( struct V_30 * V_31 )
{
struct V_1 * V_4 ;
struct V_25 * V_32 ;
int V_33 ;
if ( V_31 -> V_3 . V_7 )
V_4 = F_1 ( & V_31 -> V_3 ) ;
else
V_4 = V_31 -> V_3 . V_34 ;
if ( ! V_4 )
return - V_35 ;
V_32 = F_19 ( sizeof( struct V_25 ) , V_11 ) ;
if ( V_32 == NULL ) {
F_4 ( & V_31 -> V_3 , L_5 ) ;
V_33 = - V_35 ;
goto V_36;
}
V_32 -> V_37 . V_15 = F_20 ( V_4 -> V_14 , V_11 ) ;
if ( V_32 -> V_37 . V_15 == NULL ) {
F_4 ( & V_31 -> V_3 , L_6 ) ;
V_33 = - V_35 ;
goto V_36;
}
V_32 -> V_37 . type = V_38 ;
V_32 -> V_37 . V_39 = V_40 ;
V_32 -> V_37 . V_41 = & V_42 ;
V_32 -> V_37 . V_43 = 1 ;
V_32 -> V_18 = V_4 -> V_18 ;
V_32 -> V_21 = V_4 -> V_21 ;
V_32 -> V_22 = V_4 -> V_22 ;
if ( F_12 ( V_4 -> V_21 ) ) {
V_32 -> V_23 = V_4 -> V_23 ;
if ( ! V_4 -> V_21 )
F_21 ( & V_31 -> V_3 ,
L_7 ) ;
V_33 = F_22 ( V_4 -> V_21 , V_4 -> V_14 ) ;
if ( V_33 ) {
F_4 ( & V_31 -> V_3 ,
L_8 ,
V_4 -> V_21 , V_33 ) ;
goto V_44;
}
V_32 -> V_27 = V_4 -> V_20 ;
V_33 = V_32 -> V_27 ?
V_4 -> V_23 : ! V_4 -> V_23 ;
V_33 = F_23 ( V_4 -> V_21 , V_33 ) ;
if ( V_33 ) {
F_4 ( & V_31 -> V_3 ,
L_9 ,
V_4 -> V_21 , V_33 ) ;
goto V_45;
}
} else {
V_32 -> V_27 = true ;
}
V_32 -> V_3 = F_24 ( & V_32 -> V_37 , & V_31 -> V_3 ,
V_4 -> V_10 , V_32 ,
V_31 -> V_3 . V_7 ) ;
if ( F_25 ( V_32 -> V_3 ) ) {
V_33 = F_26 ( V_32 -> V_3 ) ;
F_4 ( & V_31 -> V_3 , L_10 , V_33 ) ;
goto V_45;
}
F_27 ( V_31 , V_32 ) ;
F_28 ( & V_31 -> V_3 , L_11 , V_32 -> V_37 . V_15 ,
V_32 -> V_18 ) ;
return 0 ;
V_45:
if ( F_12 ( V_4 -> V_21 ) )
F_29 ( V_4 -> V_21 ) ;
V_44:
F_30 ( V_32 -> V_37 . V_15 ) ;
V_36:
F_30 ( V_32 ) ;
return V_33 ;
}
static int T_3 F_31 ( struct V_30 * V_31 )
{
struct V_25 * V_32 = F_32 ( V_31 ) ;
F_33 ( V_32 -> V_3 ) ;
if ( F_12 ( V_32 -> V_21 ) )
F_29 ( V_32 -> V_21 ) ;
F_30 ( V_32 -> V_37 . V_15 ) ;
F_30 ( V_32 ) ;
return 0 ;
}
static int T_4 F_34 ( void )
{
return F_35 ( & V_46 ) ;
}
static void T_5 F_36 ( void )
{
F_37 ( & V_46 ) ;
}

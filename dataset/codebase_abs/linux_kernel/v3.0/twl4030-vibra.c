static void F_1 ( void )
{
T_1 V_1 ;
F_2 ( V_2 , & V_1 , V_3 ) ;
V_1 &= ~ 0x03 ;
F_3 ( V_2 , V_3 , V_1 ) ;
}
static void F_4 ( struct V_4 * V_5 )
{
T_1 V_1 ;
F_5 ( V_6 ) ;
F_2 ( V_7 ,
& V_1 , V_8 ) ;
F_3 ( V_7 ,
( V_1 | V_9 ) , V_8 ) ;
F_5 ( V_10 ) ;
V_5 -> V_11 = true ;
}
static void F_6 ( struct V_4 * V_5 )
{
T_1 V_1 ;
F_2 ( V_7 ,
& V_1 , V_8 ) ;
F_3 ( V_7 ,
( V_1 & ~ V_9 ) , V_8 ) ;
F_7 ( V_10 ) ;
F_7 ( V_6 ) ;
V_5 -> V_11 = false ;
}
static void F_8 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = F_9 ( V_13 ,
struct V_4 , V_14 ) ;
int V_15 ;
int V_16 ;
T_1 V_1 ;
V_15 = V_5 -> V_17 ;
V_16 = V_5 -> V_18 ;
F_2 ( V_7 ,
& V_1 , V_8 ) ;
if ( V_16 && ( ! V_5 -> V_19 || ! ( V_1 & V_20 ) ) ) {
if ( ! V_5 -> V_11 )
F_4 ( V_5 ) ;
F_2 ( V_7 ,
& V_1 , V_8 ) ;
V_1 = ( V_15 ) ? ( V_1 | V_21 ) :
( V_1 & ~ V_21 ) ;
F_3 ( V_7 ,
V_1 , V_8 ) ;
F_3 ( V_7 ,
256 - V_16 , V_22 ) ;
} else {
if ( V_5 -> V_11 )
F_6 ( V_5 ) ;
}
}
static int F_10 ( struct V_23 * V_24 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_4 * V_5 = F_11 ( V_24 ) ;
V_5 -> V_18 = V_27 -> V_28 . V_29 . V_30 >> 8 ;
if ( ! V_5 -> V_18 )
V_5 -> V_18 = V_27 -> V_28 . V_29 . V_31 >> 9 ;
V_5 -> V_17 = V_27 -> V_17 < V_32 ? 0 : 1 ;
F_12 ( V_5 -> V_33 , & V_5 -> V_14 ) ;
return 0 ;
}
static int F_13 ( struct V_23 * V_24 )
{
struct V_4 * V_5 = F_11 ( V_24 ) ;
V_5 -> V_33 = F_14 ( L_1 ) ;
if ( V_5 -> V_33 == NULL ) {
F_15 ( & V_24 -> V_34 , L_2 ) ;
return - V_35 ;
}
return 0 ;
}
static void F_16 ( struct V_23 * V_24 )
{
struct V_4 * V_5 = F_11 ( V_24 ) ;
F_17 ( & V_5 -> V_14 ) ;
F_18 ( & V_5 -> V_14 , F_8 ) ;
F_19 ( V_5 -> V_33 ) ;
V_5 -> V_33 = NULL ;
if ( V_5 -> V_11 )
F_6 ( V_5 ) ;
}
static int F_20 ( struct V_36 * V_34 )
{
struct V_37 * V_38 = F_21 ( V_34 ) ;
struct V_4 * V_5 = F_22 ( V_38 ) ;
if ( V_5 -> V_11 )
F_6 ( V_5 ) ;
return 0 ;
}
static int F_23 ( struct V_36 * V_34 )
{
F_1 () ;
return 0 ;
}
static int T_2 F_24 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = V_38 -> V_34 . V_41 ;
struct V_4 * V_5 ;
int V_42 ;
if ( ! V_40 ) {
F_25 ( & V_38 -> V_34 , L_3 ) ;
return - V_43 ;
}
V_5 = F_26 ( sizeof( * V_5 ) , V_44 ) ;
if ( ! V_5 )
return - V_35 ;
V_5 -> V_34 = & V_38 -> V_34 ;
V_5 -> V_19 = V_40 -> V_19 ;
F_18 ( & V_5 -> V_14 , F_8 ) ;
V_5 -> V_23 = F_27 () ;
if ( V_5 -> V_23 == NULL ) {
F_15 ( & V_38 -> V_34 , L_4 ) ;
V_42 = - V_35 ;
goto V_45;
}
F_28 ( V_5 -> V_23 , V_5 ) ;
V_5 -> V_23 -> V_46 = L_5 ;
V_5 -> V_23 -> V_47 . V_48 = 1 ;
V_5 -> V_23 -> V_34 . V_49 = V_38 -> V_34 . V_49 ;
V_5 -> V_23 -> V_50 = F_13 ;
V_5 -> V_23 -> V_51 = F_16 ;
F_29 ( V_52 , V_5 -> V_23 -> V_53 ) ;
V_42 = F_30 ( V_5 -> V_23 , NULL , F_10 ) ;
if ( V_42 < 0 ) {
F_25 ( & V_38 -> V_34 , L_6 ) ;
goto V_54;
}
V_42 = F_31 ( V_5 -> V_23 ) ;
if ( V_42 < 0 ) {
F_25 ( & V_38 -> V_34 , L_7 ) ;
goto V_55;
}
F_1 () ;
F_32 ( V_38 , V_5 ) ;
return 0 ;
V_55:
F_33 ( V_5 -> V_23 ) ;
V_54:
F_34 ( V_5 -> V_23 ) ;
V_45:
F_35 ( V_5 ) ;
return V_42 ;
}
static int T_3 F_36 ( struct V_37 * V_38 )
{
struct V_4 * V_5 = F_22 ( V_38 ) ;
F_37 ( V_5 -> V_23 ) ;
F_35 ( V_5 ) ;
F_32 ( V_38 , NULL ) ;
return 0 ;
}
static int T_4 F_38 ( void )
{
return F_39 ( & V_56 ) ;
}
static void T_5 F_40 ( void )
{
F_41 ( & V_56 ) ;
}

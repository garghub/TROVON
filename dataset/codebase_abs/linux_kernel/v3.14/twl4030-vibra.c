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
F_12 ( & V_5 -> V_14 ) ;
return 0 ;
}
static void F_13 ( struct V_23 * V_24 )
{
struct V_4 * V_5 = F_11 ( V_24 ) ;
F_14 ( & V_5 -> V_14 ) ;
if ( V_5 -> V_11 )
F_6 ( V_5 ) ;
}
static int F_15 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = F_16 ( V_34 ) ;
struct V_4 * V_5 = F_17 ( V_36 ) ;
if ( V_5 -> V_11 )
F_6 ( V_5 ) ;
return 0 ;
}
static int F_18 ( struct V_33 * V_34 )
{
F_1 () ;
return 0 ;
}
static bool F_19 ( struct V_37 * V_38 ,
struct V_39 * V_40 )
{
if ( V_38 && V_38 -> V_19 )
return true ;
if ( F_20 ( V_40 , L_1 ) ) {
F_21 ( V_40 ) ;
return true ;
}
return false ;
}
static int F_22 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = F_23 ( & V_36 -> V_34 ) ;
struct V_39 * V_41 = V_36 -> V_34 . V_42 -> V_43 ;
struct V_4 * V_5 ;
int V_44 ;
if ( ! V_38 && ! V_41 ) {
F_24 ( & V_36 -> V_34 , L_2 ) ;
return - V_45 ;
}
V_5 = F_25 ( & V_36 -> V_34 , sizeof( * V_5 ) , V_46 ) ;
if ( ! V_5 )
return - V_47 ;
V_5 -> V_34 = & V_36 -> V_34 ;
V_5 -> V_19 = F_19 ( V_38 , V_41 ) ;
F_26 ( & V_5 -> V_14 , F_8 ) ;
V_5 -> V_23 = F_27 ( & V_36 -> V_34 ) ;
if ( V_5 -> V_23 == NULL ) {
F_28 ( & V_36 -> V_34 , L_3 ) ;
return - V_47 ;
}
F_29 ( V_5 -> V_23 , V_5 ) ;
V_5 -> V_23 -> V_48 = L_4 ;
V_5 -> V_23 -> V_49 . V_50 = 1 ;
V_5 -> V_23 -> V_34 . V_42 = V_36 -> V_34 . V_42 ;
V_5 -> V_23 -> V_51 = F_13 ;
F_30 ( V_52 , V_5 -> V_23 -> V_53 ) ;
V_44 = F_31 ( V_5 -> V_23 , NULL , F_10 ) ;
if ( V_44 < 0 ) {
F_24 ( & V_36 -> V_34 , L_5 ) ;
return V_44 ;
}
V_44 = F_32 ( V_5 -> V_23 ) ;
if ( V_44 < 0 ) {
F_24 ( & V_36 -> V_34 , L_6 ) ;
goto V_54;
}
F_1 () ;
F_33 ( V_36 , V_5 ) ;
return 0 ;
V_54:
F_34 ( V_5 -> V_23 ) ;
return V_44 ;
}

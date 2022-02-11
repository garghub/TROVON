static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
int V_4 ;
unsigned int V_5 = V_2 -> V_6 ;
if ( V_3 )
V_5 |= ( ( V_2 -> V_7 << V_8 ) & V_9 ) ;
else
V_5 &= ~ V_9 ;
V_4 = F_2 ( V_2 -> V_10 , V_11 , V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_6 = V_5 ;
return 0 ;
}
static void F_3 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 , struct V_1 , V_13 ) ;
int V_4 ;
unsigned int V_5 ;
V_4 = F_5 ( V_2 -> V_10 , V_11 , & V_5 ) ;
if ( V_4 < 0 )
return;
if ( V_2 -> V_14 ) {
V_2 -> V_15 = true ;
V_2 -> V_7 = ( ( V_16 * V_2 -> V_14 ) / V_17 ) +
V_18 ;
V_2 -> V_7 /= 100 ;
} else {
V_2 -> V_15 = false ;
V_2 -> V_7 = V_18 / 100 ;
}
F_1 ( V_2 , V_2 -> V_15 ) ;
}
static void F_6 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_20 ) ;
F_8 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_15 )
F_1 ( V_2 , false ) ;
}
static int F_9 ( struct V_19 * V_20 , void * V_21 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = F_7 ( V_20 ) ;
V_2 -> V_14 = V_23 -> V_24 . V_25 . V_26 >> 8 ;
if ( ! V_2 -> V_14 )
V_2 -> V_14 = V_23 -> V_24 . V_25 . V_27 >> 9 ;
F_10 ( & V_2 -> V_13 ) ;
return 0 ;
}
static int F_11 ( struct V_28 * V_29 )
{
struct V_1 * V_2 ;
struct V_19 * V_19 ;
int error ;
unsigned int V_5 ;
V_2 = F_12 ( & V_29 -> V_20 , sizeof( * V_2 ) , V_30 ) ;
if ( ! V_2 )
return - V_31 ;
V_2 -> V_10 = F_13 ( V_29 -> V_20 . V_32 , NULL ) ;
if ( ! V_2 -> V_10 )
return - V_33 ;
V_19 = F_14 ( & V_29 -> V_20 ) ;
if ( ! V_19 )
return - V_31 ;
F_15 ( & V_2 -> V_13 , F_3 ) ;
V_2 -> V_34 = V_19 ;
error = F_5 ( V_2 -> V_10 , V_11 , & V_5 ) ;
if ( error < 0 )
return error ;
V_5 &= ~ V_35 ;
error = F_2 ( V_2 -> V_10 , V_11 , V_5 ) ;
if ( error < 0 )
return error ;
V_2 -> V_6 = V_5 ;
V_19 -> V_36 = L_1 ;
V_19 -> V_37 . V_38 = 1 ;
V_19 -> V_39 = F_6 ;
F_16 ( V_19 , V_2 ) ;
F_17 ( V_2 -> V_34 , V_40 , V_41 ) ;
error = F_18 ( V_19 , NULL ,
F_9 ) ;
if ( error ) {
F_19 ( & V_29 -> V_20 ,
L_2 ) ;
return error ;
}
error = F_20 ( V_19 ) ;
if ( error ) {
F_19 ( & V_29 -> V_20 , L_3 ) ;
return error ;
}
F_21 ( V_29 , V_2 ) ;
return 0 ;
}
static int T_1 F_22 ( struct V_42 * V_20 )
{
struct V_1 * V_2 = F_23 ( V_20 ) ;
F_1 ( V_2 , false ) ;
return 0 ;
}

static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
int V_4 ;
unsigned int V_5 = V_2 -> V_6 ;
const struct V_7 * V_8 = V_2 -> V_8 ;
if ( V_3 )
V_5 |= ( V_2 -> V_9 << V_8 -> V_10 ) & V_8 -> V_11 ;
else
V_5 &= ~ V_8 -> V_11 ;
V_4 = F_2 ( V_2 -> V_12 , V_8 -> V_13 , V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_6 = V_5 ;
if ( V_8 -> V_14 )
V_4 = F_3 ( V_2 -> V_12 , V_8 -> V_15 ,
V_3 ? V_8 -> V_14 : 0 , V_5 ) ;
return V_4 ;
}
static void F_4 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_5 ( V_17 , struct V_1 , V_17 ) ;
const struct V_7 * V_8 = V_2 -> V_8 ;
int V_4 ;
unsigned int V_5 ;
V_4 = F_6 ( V_2 -> V_12 , V_8 -> V_13 , & V_5 ) ;
if ( V_4 < 0 )
return;
if ( V_2 -> V_18 ) {
V_2 -> V_19 = true ;
V_2 -> V_9 = ( ( V_20 * V_2 -> V_18 ) / V_21 ) +
V_22 ;
V_2 -> V_9 /= 100 ;
} else {
V_2 -> V_19 = false ;
V_2 -> V_9 = V_22 / 100 ;
}
F_1 ( V_2 , V_2 -> V_19 ) ;
}
static void F_7 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_8 ( V_24 ) ;
F_9 ( & V_2 -> V_17 ) ;
if ( V_2 -> V_19 )
F_1 ( V_2 , false ) ;
}
static int F_10 ( struct V_23 * V_24 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_8 ( V_24 ) ;
V_2 -> V_18 = V_27 -> V_28 . V_29 . V_30 >> 8 ;
if ( ! V_2 -> V_18 )
V_2 -> V_18 = V_27 -> V_28 . V_29 . V_31 >> 9 ;
F_11 ( & V_2 -> V_17 ) ;
return 0 ;
}
static int F_12 ( struct V_32 * V_33 )
{
struct V_1 * V_2 ;
struct V_23 * V_23 ;
int error ;
unsigned int V_5 ;
const struct V_7 * V_8 ;
V_2 = F_13 ( & V_33 -> V_24 , sizeof( * V_2 ) , V_34 ) ;
if ( ! V_2 )
return - V_35 ;
V_2 -> V_12 = F_14 ( V_33 -> V_24 . V_36 , NULL ) ;
if ( ! V_2 -> V_12 )
return - V_37 ;
V_23 = F_15 ( & V_33 -> V_24 ) ;
if ( ! V_23 )
return - V_35 ;
F_16 ( & V_2 -> V_17 , F_4 ) ;
V_2 -> V_38 = V_23 ;
V_8 = F_17 ( & V_33 -> V_24 ) ;
error = F_6 ( V_2 -> V_12 , V_8 -> V_13 , & V_5 ) ;
if ( error < 0 )
return error ;
V_5 &= V_8 -> V_39 ;
error = F_2 ( V_2 -> V_12 , V_8 -> V_13 , V_5 ) ;
if ( error < 0 )
return error ;
V_2 -> V_8 = V_8 ;
V_2 -> V_6 = V_5 ;
V_23 -> V_40 = L_1 ;
V_23 -> V_41 . V_42 = 1 ;
V_23 -> V_43 = F_7 ;
F_18 ( V_23 , V_2 ) ;
F_19 ( V_2 -> V_38 , V_44 , V_45 ) ;
error = F_20 ( V_23 , NULL ,
F_10 ) ;
if ( error ) {
F_21 ( & V_33 -> V_24 ,
L_2 ) ;
return error ;
}
error = F_22 ( V_23 ) ;
if ( error ) {
F_21 ( & V_33 -> V_24 , L_3 ) ;
return error ;
}
F_23 ( V_33 , V_2 ) ;
return 0 ;
}
static int T_1 F_24 ( struct V_46 * V_24 )
{
struct V_1 * V_2 = F_25 ( V_24 ) ;
F_1 ( V_2 , false ) ;
return 0 ;
}

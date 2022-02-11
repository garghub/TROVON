static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
if ( V_3 )
return - V_6 ;
V_5 -> V_7 = 36 ;
V_5 -> V_8 = 6 ;
if ( V_2 -> V_9 == 128 ) {
V_5 -> V_7 *= 2 ;
V_5 -> V_8 *= 2 ;
}
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
int V_10 = 36 , V_11 = 6 ;
if ( V_3 > 1 )
return - V_6 ;
if ( V_2 -> V_9 == 128 ) {
V_10 *= 2 ;
V_11 *= 2 ;
}
if ( ! V_3 ) {
V_5 -> V_8 = 2 ;
V_5 -> V_7 = V_11 - 2 ;
} else {
V_5 -> V_8 = V_11 + V_10 ;
V_5 -> V_7 = V_2 -> V_9 - V_5 -> V_8 ;
}
return 0 ;
}
static void F_3 ( struct V_12 * V_13 ,
struct V_1 * V_2 , struct V_14 * * V_15 ,
int * V_16 )
{
struct V_17 * V_18 = F_4 ( V_2 ) ;
if ( V_18 -> V_19 == 12 ) {
* V_15 = V_20 ;
* V_16 = F_5 ( V_20 ) ;
} else {
* V_15 = V_21 ;
* V_16 = F_5 ( V_21 ) ;
}
F_6 ( V_2 , & V_22 ) ;
}
static int T_1 F_7 ( void )
{
V_23 . V_24 . V_25 = & V_26 ;
V_27 . V_24 . V_25 = & V_28 ;
V_29 . V_24 . V_25 = & V_30 ;
V_31 . V_24 . V_25 = & V_32 ;
F_8 ( & V_33 ) ;
F_8 ( & V_34 ) ;
F_9 ( V_35 ,
F_5 ( V_35 ) ) ;
F_10 ( V_36 , F_5 ( V_36 ) ) ;
F_11 ( V_37 , F_5 ( V_37 ) ) ;
return F_12 ( V_38 ,
F_5 ( V_38 ) ) ;
}
static int T_1 F_13 ( void )
{
F_14 ( V_39 L_1 ) ;
if ( F_7 () )
F_15 ( L_2 ) ;
return 0 ;
}

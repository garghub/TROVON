void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 = V_6 -> V_7 ;
void T_3 * V_8 = V_6 -> V_9 + ( V_10 << V_7 ) ;
void T_3 * V_11 = V_6 -> V_9 + ( V_12 << V_7 ) ;
F_3 ( ~ V_13 & V_3 , V_8 ) ;
F_3 ( V_4 , V_11 ) ;
}
T_2 F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 = V_6 -> V_7 ;
void T_3 * V_8 = V_6 -> V_9 + ( V_10 << V_7 ) ;
void T_3 * V_11 = V_6 -> V_9 + ( V_12 << V_7 ) ;
F_3 ( V_13 | V_3 , V_8 ) ;
return F_5 ( V_11 ) ;
}
static int F_6 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 . V_16 ;
int V_17 ;
V_17 = F_4 ( V_2 , 0x28 ) ;
F_1 ( V_2 , 0x28 , V_17 & 0x7f ) ;
F_7 ( V_2 , L_1 , V_17 & 0x7f ) ;
return 0 ;
}
static int F_8 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_2 . V_16 ;
int V_17 ;
V_17 = F_4 ( V_2 , 0x28 ) ;
F_1 ( V_2 , 0x28 , V_17 | 0x80 ) ;
F_7 ( V_2 , L_2 , V_17 | 0x80 ) ;
return 0 ;
}
static int T_4 F_9 ( struct V_14 * V_15 )
{
struct V_18 * V_19 = V_15 -> V_2 . V_20 ;
struct V_1 * V_2 = & V_15 -> V_2 ;
struct V_5 * V_6 ;
struct V_21 * V_22 ;
int V_23 ;
int V_24 = 0 ;
V_22 = F_10 ( V_15 , V_25 , 0 ) ;
if ( V_22 ) {
V_26 [ 1 ] . V_27 = V_25 | ( V_22 -> V_27 &
( V_28 | V_29 ) ) ;
V_24 = V_22 -> V_30 ;
}
V_22 = F_10 ( V_15 , V_31 , 0 ) ;
if ( ! V_22 )
return - V_32 ;
if ( ! F_11 ( V_22 -> V_30 , F_12 ( V_22 ) , L_3 ) )
return - V_33 ;
V_6 = F_13 ( sizeof( struct V_5 ) , V_34 ) ;
if ( ! V_6 )
return - V_35 ;
F_14 ( V_15 , V_6 ) ;
V_6 -> V_9 = F_15 ( V_22 -> V_30 , F_12 ( V_22 ) ) ;
if ( ! V_6 -> V_9 ) {
F_16 ( V_2 , L_4 ) ;
F_17 ( V_6 ) ;
return - V_35 ;
}
V_6 -> V_7 = ( F_12 ( V_22 ) - 5 ) >> 3 ;
if ( V_19 && V_19 -> V_36 ) {
V_37 . V_36 = V_19 -> V_36 ;
V_26 [ 0 ] . V_38 = ( 5 << V_6 -> V_7 ) - 1 ;
V_23 = F_18 ( & V_15 -> V_2 , V_15 -> V_39 ,
& V_40 , 1 , V_22 , V_24 , NULL ) ;
if ( V_23 < 0 )
F_19 ( V_2 , L_5 ) ;
}
if ( V_19 && V_19 -> V_41 ) {
V_42 . V_20 = V_19 -> V_41 ;
V_42 . V_43 = sizeof( struct V_44 ) ;
V_23 = F_18 ( & V_15 -> V_2 , V_15 -> V_39 , & V_42 , 1 , V_22 ,
0 , NULL ) ;
if ( V_23 < 0 )
F_19 ( V_2 , L_6 ) ;
}
return 0 ;
}
static int F_20 ( struct V_14 * V_15 )
{
struct V_5 * V_6 = F_21 ( V_15 ) ;
struct V_21 * V_22 ;
F_22 ( & V_15 -> V_2 ) ;
F_23 ( V_6 -> V_9 ) ;
V_22 = F_10 ( V_15 , V_31 , 0 ) ;
F_24 ( V_22 -> V_30 , F_12 ( V_22 ) ) ;
F_17 ( V_6 ) ;
return 0 ;
}

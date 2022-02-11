static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
F_2 ( V_2 -> V_8 , L_1 ) ;
F_2 ( V_2 -> V_8 , L_2 , V_7 [ 0 ] , V_7 [ 1 ] ) ;
if ( V_6 -> V_9 != 2 )
return - V_10 ;
if ( V_7 [ 0 ] ) {
V_4 -> V_11 &= ~ V_7 [ 0 ] ;
V_4 -> V_11 |= V_7 [ 0 ] & V_7 [ 1 ] ;
F_2 ( V_2 -> V_8 , L_3 , V_4 -> V_11 ,
V_2 -> V_12 + V_13 -> V_14 ) ;
F_3 ( V_4 -> V_11 , V_2 -> V_12 + V_13 -> V_14 ) ;
}
return 2 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
F_2 ( V_2 -> V_8 , L_4 ) ;
F_2 ( V_2 -> V_8 , L_2 , V_7 [ 0 ] , V_7 [ 1 ] ) ;
if ( V_6 -> V_9 != 2 )
return - V_10 ;
V_7 [ 1 ] = F_5 ( V_2 -> V_12 + V_13 -> V_15 ) ;
return 2 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_18 * V_19 = NULL ;
struct V_3 * V_4 ;
F_7 ( L_5 , V_2 -> V_20 ) ;
V_2 -> V_21 = V_13 -> V_22 ;
if ( F_8 ( V_2 , sizeof( struct V_23 ) ) < 0 )
return - V_24 ;
if ( F_9 ( V_2 , 2 ) < 0 )
return - V_24 ;
F_10 (pcidev) {
if ( V_19 -> V_25 == V_26 &&
V_19 -> V_27 == V_28 ) {
if ( V_17 -> V_29 [ 0 ] || V_17 -> V_29 [ 1 ] ) {
if ( V_17 -> V_29 [ 0 ] != V_19 -> V_30 -> V_31 ||
V_17 -> V_29 [ 1 ] != F_11 ( V_19 -> V_32 ) ) {
continue;
}
}
V_33 -> V_18 = V_19 ;
if ( F_12 ( V_19 , L_6 ) ) {
F_7
( L_7 ) ;
return - V_34 ;
}
V_2 -> V_12 = F_13 ( V_19 , 0 ) ;
F_7 ( L_8 , V_2 -> V_12 ) ;
V_2 -> V_35 = V_36 + 0 ;
V_4 = V_2 -> V_37 + 0 ;
V_4 -> type = V_38 ;
V_4 -> V_39 = V_40 ;
V_4 -> V_41 = 16 ;
V_4 -> V_42 = 1 ;
V_4 -> V_43 = & V_44 ;
V_4 -> V_45 = F_4 ;
V_4 = V_2 -> V_37 + 1 ;
V_4 -> type = V_46 ;
V_4 -> V_39 = V_47 ;
V_4 -> V_41 = 16 ;
V_4 -> V_42 = 1 ;
V_4 -> V_43 = & V_44 ;
V_4 -> V_45 = F_1 ;
F_7 ( L_9 ) ;
return 1 ;
}
}
F_7 ( L_10 ) ;
return - V_34 ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( V_33 && V_33 -> V_18 ) {
if ( V_2 -> V_12 )
F_15 ( V_33 -> V_18 ) ;
F_16 ( V_33 -> V_18 ) ;
}
}
static int T_1 F_17 ( struct V_18 * V_2 ,
const struct V_48 * V_49 )
{
return F_18 ( V_2 , & V_50 ) ;
}
static void T_2 F_19 ( struct V_18 * V_2 )
{
F_20 ( V_2 ) ;
}

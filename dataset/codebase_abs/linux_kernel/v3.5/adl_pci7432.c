static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
F_2 ( V_8 L_1 ) ;
F_2 ( V_8 L_2 , V_7 [ 0 ] , V_7 [ 1 ] ) ;
if ( V_6 -> V_9 != 2 )
return - V_10 ;
if ( V_7 [ 0 ] ) {
V_4 -> V_11 &= ~ V_7 [ 0 ] ;
V_4 -> V_11 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
F_2 ( V_8 L_3 , V_4 -> V_11 ,
V_2 -> V_12 + V_13 ) ;
F_3 ( V_4 -> V_11 & 0xffffffff , V_2 -> V_12 + V_13 ) ;
}
return 2 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
F_2 ( V_8 L_4 ) ;
F_2 ( V_8 L_2 , V_7 [ 0 ] , V_7 [ 1 ] ) ;
if ( V_6 -> V_9 != 2 )
return - V_10 ;
V_7 [ 1 ] = F_5 ( V_2 -> V_12 + V_14 ) & 0xffffffff ;
F_2 ( V_8 L_5 , V_7 [ 1 ] ) ;
return 2 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = NULL ;
struct V_3 * V_4 ;
int V_19 , V_20 ;
F_2 ( V_21 L_6 , V_2 -> V_22 ) ;
V_2 -> V_23 = L_7 ;
V_19 = V_16 -> V_24 [ 0 ] ;
V_20 = V_16 -> V_24 [ 1 ] ;
if ( F_7 ( V_2 , sizeof( struct V_25 ) ) < 0 )
return - V_26 ;
if ( F_8 ( V_2 , 2 ) < 0 )
return - V_26 ;
F_9 (pcidev) {
if ( V_18 -> V_27 == V_28 &&
V_18 -> V_29 == V_30 ) {
if ( V_19 || V_20 ) {
if ( V_18 -> V_19 -> V_31 != V_19
|| F_10 ( V_18 -> V_32 ) != V_20 ) {
continue;
}
}
V_33 -> V_17 = V_18 ;
if ( F_11 ( V_18 , L_8 ) < 0 ) {
F_2 ( V_34 L_9 ,
V_2 -> V_22 ) ;
return - V_35 ;
}
V_2 -> V_12 = F_12 ( V_18 , 2 ) ;
F_2 ( V_21 L_10 ,
V_2 -> V_12 ) ;
V_4 = V_2 -> V_36 + 0 ;
V_4 -> type = V_37 ;
V_4 -> V_38 =
V_39 | V_40 | V_41 ;
V_4 -> V_42 = 32 ;
V_4 -> V_43 = 1 ;
V_4 -> V_44 = 32 ;
V_4 -> V_45 = 0x00000000 ;
V_4 -> V_46 = & V_47 ;
V_4 -> V_48 = F_4 ;
V_4 = V_2 -> V_36 + 1 ;
V_4 -> type = V_49 ;
V_4 -> V_38 =
V_50 | V_40 | V_41 ;
V_4 -> V_42 = 32 ;
V_4 -> V_43 = 1 ;
V_4 -> V_44 = 32 ;
V_4 -> V_45 = 0xffffffff ;
V_4 -> V_46 = & V_47 ;
V_4 -> V_48 = F_1 ;
F_2 ( V_8 L_11 ,
V_2 -> V_22 ) ;
return 1 ;
}
}
F_2 ( V_34 L_12 ,
V_2 -> V_22 , V_19 , V_20 ) ;
return - V_35 ;
}
static void F_13 ( struct V_1 * V_2 )
{
if ( V_33 && V_33 -> V_17 ) {
if ( V_2 -> V_12 )
F_14 ( V_33 -> V_17 ) ;
F_15 ( V_33 -> V_17 ) ;
}
}
static int T_1 F_16 ( struct V_17 * V_2 ,
const struct V_51 * V_52 )
{
return F_17 ( V_2 , & V_53 ) ;
}
static void T_2 F_18 ( struct V_17 * V_2 )
{
F_19 ( V_2 ) ;
}

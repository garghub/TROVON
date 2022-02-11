static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
if ( V_6 -> V_8 != 2 )
return - V_9 ;
if ( V_7 [ 0 ] ) {
V_4 -> V_10 &= ~ V_7 [ 0 ] ;
V_4 -> V_10 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
F_2 ( ( V_4 -> V_10 << 16 ) & 0xffffffff , V_2 -> V_11 + V_12 ) ;
}
return 2 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
if ( V_6 -> V_8 != 2 )
return - V_9 ;
V_7 [ 1 ] = F_4 ( V_2 -> V_11 + V_13 ) & 0xffffffff ;
return 2 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = NULL ;
struct V_3 * V_4 ;
int V_18 , V_19 ;
F_6 ( V_20 L_1 , V_2 -> V_21 ) ;
V_2 -> V_22 = L_2 ;
V_18 = V_15 -> V_23 [ 0 ] ;
V_19 = V_15 -> V_23 [ 1 ] ;
if ( F_7 ( V_2 , sizeof( struct V_24 ) ) < 0 )
return - V_25 ;
if ( F_8 ( V_2 , 2 ) < 0 )
return - V_25 ;
F_9 (pcidev) {
if ( V_17 -> V_26 == V_27 &&
V_17 -> V_28 == V_29 ) {
if ( V_18 || V_19 ) {
if ( V_17 -> V_18 -> V_30 != V_18 ||
F_10 ( V_17 -> V_31 ) != V_19 ) {
continue;
}
}
V_32 -> V_16 = V_17 ;
break;
}
}
if ( V_17 == NULL ) {
F_6 ( V_33 L_3 ,
V_2 -> V_21 , V_18 , V_19 ) ;
return - V_34 ;
}
if ( F_11 ( V_17 , L_4 ) < 0 ) {
F_6 ( V_33 L_5 ,
V_2 -> V_21 ) ;
return - V_34 ;
}
V_2 -> V_11 = F_12 ( V_17 , 2 ) ;
F_6 ( V_35 L_6 , V_2 -> V_11 ) ;
V_4 = V_2 -> V_36 + 0 ;
V_4 -> type = V_37 ;
V_4 -> V_38 = V_39 | V_40 | V_41 ;
V_4 -> V_42 = 16 ;
V_4 -> V_43 = 1 ;
V_4 -> V_44 = & V_45 ;
V_4 -> V_46 = F_1 ;
V_4 = V_2 -> V_36 + 1 ;
V_4 -> type = V_47 ;
V_4 -> V_38 = V_48 | V_40 | V_41 ;
V_4 -> V_42 = 16 ;
V_4 -> V_43 = 1 ;
V_4 -> V_44 = & V_45 ;
V_4 -> V_46 = F_3 ;
F_6 ( V_35 L_7 ) ;
return 1 ;
}
static void F_13 ( struct V_1 * V_2 )
{
if ( V_32 && V_32 -> V_16 ) {
if ( V_2 -> V_11 )
F_14 ( V_32 -> V_16 ) ;
F_15 ( V_32 -> V_16 ) ;
}
}
static int T_1 F_16 ( struct V_16 * V_2 ,
const struct V_49 * V_50 )
{
return F_17 ( V_2 , & V_51 ) ;
}
static void T_2 F_18 ( struct V_16 * V_2 )
{
F_19 ( V_2 ) ;
}

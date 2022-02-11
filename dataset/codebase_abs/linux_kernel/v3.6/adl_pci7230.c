static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
if ( V_7 [ 0 ] ) {
V_4 -> V_8 &= ~ V_7 [ 0 ] ;
V_4 -> V_8 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
F_2 ( ( V_4 -> V_8 << 16 ) & 0xffffffff , V_2 -> V_9 + V_10 ) ;
}
return V_6 -> V_11 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
V_7 [ 1 ] = F_4 ( V_2 -> V_9 + V_12 ) & 0xffffffff ;
return V_6 -> V_11 ;
}
static struct V_13 * F_5 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_13 * V_16 = NULL ;
int V_17 = V_15 -> V_18 [ 0 ] ;
int V_19 = V_15 -> V_18 [ 1 ] ;
F_6 (pcidev) {
if ( V_16 -> V_20 != V_21 ||
V_16 -> V_22 != V_23 )
continue;
if ( V_17 || V_19 ) {
if ( V_16 -> V_17 -> V_24 != V_17 ||
F_7 ( V_16 -> V_25 ) != V_19 )
continue;
}
return V_16 ;
}
F_8 ( V_26 L_1 ,
V_2 -> V_27 , V_17 , V_19 ) ;
return NULL ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_3 * V_4 ;
struct V_13 * V_16 ;
int V_28 ;
F_8 ( V_29 L_2 , V_2 -> V_27 ) ;
V_2 -> V_30 = L_3 ;
V_28 = F_10 ( V_2 , 2 ) ;
if ( V_28 )
return V_28 ;
V_16 = F_5 ( V_2 , V_15 ) ;
if ( ! V_16 )
return - V_31 ;
F_11 ( V_2 , & V_16 -> V_2 ) ;
if ( F_12 ( V_16 , L_4 ) < 0 ) {
F_8 ( V_26 L_5 ,
V_2 -> V_27 ) ;
return - V_31 ;
}
V_2 -> V_9 = F_13 ( V_16 , 2 ) ;
F_8 ( V_32 L_6 , V_2 -> V_9 ) ;
V_4 = V_2 -> V_33 + 0 ;
V_4 -> type = V_34 ;
V_4 -> V_35 = V_36 | V_37 | V_38 ;
V_4 -> V_39 = 16 ;
V_4 -> V_40 = 1 ;
V_4 -> V_41 = & V_42 ;
V_4 -> V_43 = F_1 ;
V_4 = V_2 -> V_33 + 1 ;
V_4 -> type = V_44 ;
V_4 -> V_35 = V_45 | V_37 | V_38 ;
V_4 -> V_39 = 16 ;
V_4 -> V_40 = 1 ;
V_4 -> V_41 = & V_42 ;
V_4 -> V_43 = F_3 ;
F_8 ( V_32 L_7 ) ;
return 1 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_13 * V_16 = F_15 ( V_2 ) ;
if ( V_16 ) {
if ( V_2 -> V_9 )
F_16 ( V_16 ) ;
F_17 ( V_16 ) ;
}
}
static int T_1 F_18 ( struct V_13 * V_2 ,
const struct V_46 * V_47 )
{
return F_19 ( V_2 , & V_48 ) ;
}
static void T_2 F_20 ( struct V_13 * V_2 )
{
F_21 ( V_2 ) ;
}

static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
F_2 ( V_8 L_1 ) ;
F_2 ( V_8 L_2 , V_7 [ 0 ] , V_7 [ 1 ] ) ;
if ( V_7 [ 0 ] ) {
V_4 -> V_9 &= ~ V_7 [ 0 ] ;
V_4 -> V_9 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
F_2 ( V_8 L_3 , V_4 -> V_9 ,
V_2 -> V_10 + V_11 ) ;
F_3 ( V_4 -> V_9 & 0xffffffff , V_2 -> V_10 + V_11 ) ;
}
return V_6 -> V_12 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
F_2 ( V_8 L_4 ) ;
F_2 ( V_8 L_2 , V_7 [ 0 ] , V_7 [ 1 ] ) ;
V_7 [ 1 ] = F_5 ( V_2 -> V_10 + V_13 ) & 0xffffffff ;
F_2 ( V_8 L_5 , V_7 [ 1 ] ) ;
return V_6 -> V_12 ;
}
static struct V_14 * F_6 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_14 * V_17 = NULL ;
int V_18 = V_16 -> V_19 [ 0 ] ;
int V_20 = V_16 -> V_19 [ 1 ] ;
F_7 (pcidev) {
if ( V_17 -> V_21 != V_22 ||
V_17 -> V_23 != V_24 )
continue;
if ( V_18 || V_20 ) {
if ( V_17 -> V_18 -> V_25 != V_18 ||
F_8 ( V_17 -> V_26 ) != V_20 )
continue;
}
return V_17 ;
}
F_2 ( V_27
L_6 ,
V_2 -> V_28 , V_18 , V_20 ) ;
return NULL ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_14 * V_17 ;
struct V_3 * V_4 ;
int V_29 ;
F_2 ( V_30 L_7 , V_2 -> V_28 ) ;
V_2 -> V_31 = L_8 ;
V_29 = F_10 ( V_2 , 2 ) ;
if ( V_29 )
return V_29 ;
V_17 = F_6 ( V_2 , V_16 ) ;
if ( ! V_17 )
return - V_32 ;
F_11 ( V_2 , & V_17 -> V_2 ) ;
if ( F_12 ( V_17 , L_9 ) < 0 ) {
F_2 ( V_27 L_10 ,
V_2 -> V_28 ) ;
return - V_32 ;
}
V_2 -> V_10 = F_13 ( V_17 , 2 ) ;
F_2 ( V_30 L_11 , V_2 -> V_10 ) ;
V_4 = V_2 -> V_33 + 0 ;
V_4 -> type = V_34 ;
V_4 -> V_35 = V_36 | V_37 | V_38 ;
V_4 -> V_39 = 32 ;
V_4 -> V_40 = 1 ;
V_4 -> V_41 = 32 ;
V_4 -> V_42 = 0x00000000 ;
V_4 -> V_43 = & V_44 ;
V_4 -> V_45 = F_4 ;
V_4 = V_2 -> V_33 + 1 ;
V_4 -> type = V_46 ;
V_4 -> V_35 = V_47 | V_37 | V_38 ;
V_4 -> V_39 = 32 ;
V_4 -> V_40 = 1 ;
V_4 -> V_41 = 32 ;
V_4 -> V_42 = 0xffffffff ;
V_4 -> V_43 = & V_44 ;
V_4 -> V_45 = F_1 ;
F_2 ( V_8 L_12 , V_2 -> V_28 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_14 * V_17 = F_15 ( V_2 ) ;
if ( V_17 ) {
if ( V_2 -> V_10 )
F_16 ( V_17 ) ;
F_17 ( V_17 ) ;
}
}
static int T_1 F_18 ( struct V_14 * V_2 ,
const struct V_48 * V_49 )
{
return F_19 ( V_2 , & V_50 ) ;
}
static void T_2 F_20 ( struct V_14 * V_2 )
{
F_21 ( V_2 ) ;
}

static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
F_2 ( V_2 -> V_8 , L_1 ) ;
F_2 ( V_2 -> V_8 , L_2 , V_7 [ 0 ] , V_7 [ 1 ] ) ;
if ( V_7 [ 0 ] ) {
V_4 -> V_9 &= ~ V_7 [ 0 ] ;
V_4 -> V_9 |= V_7 [ 0 ] & V_7 [ 1 ] ;
F_2 ( V_2 -> V_8 , L_3 , V_4 -> V_9 ,
V_2 -> V_10 + V_11 -> V_12 ) ;
F_3 ( V_4 -> V_9 , V_2 -> V_10 + V_11 -> V_12 ) ;
}
return V_6 -> V_13 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
F_2 ( V_2 -> V_8 , L_4 ) ;
F_2 ( V_2 -> V_8 , L_2 , V_7 [ 0 ] , V_7 [ 1 ] ) ;
V_7 [ 1 ] = F_5 ( V_2 -> V_10 + V_11 -> V_14 ) ;
return V_6 -> V_13 ;
}
static struct V_15 * F_6 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_15 * V_18 = NULL ;
int V_19 = V_17 -> V_20 [ 0 ] ;
int V_21 = V_17 -> V_20 [ 1 ] ;
F_7 (pcidev) {
if ( V_19 || V_21 ) {
if ( V_19 != V_18 -> V_19 -> V_22 ||
V_21 != F_8 ( V_18 -> V_23 ) )
continue;
}
if ( V_18 -> V_24 != V_25 ||
V_18 -> V_26 != V_27 )
continue;
V_2 -> V_28 = V_29 + 0 ;
return V_18 ;
}
F_9 ( V_2 -> V_8 ,
L_5 ,
V_19 , V_21 ) ;
return NULL ;
}
static int F_10 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_15 * V_18 ;
struct V_3 * V_4 ;
int V_30 ;
F_11 ( L_6 , V_2 -> V_31 ) ;
V_2 -> V_32 = V_11 -> V_33 ;
V_30 = F_12 ( V_2 , 2 ) ;
if ( V_30 )
return V_30 ;
V_18 = F_6 ( V_2 , V_17 ) ;
if ( ! V_18 )
return - V_34 ;
F_13 ( V_2 , & V_18 -> V_2 ) ;
if ( F_14 ( V_18 , L_7 ) ) {
F_11 ( L_8 ) ;
return - V_34 ;
}
V_2 -> V_10 = F_15 ( V_18 , 0 ) ;
F_11 ( L_9 , V_2 -> V_10 ) ;
V_4 = V_2 -> V_35 + 0 ;
V_4 -> type = V_36 ;
V_4 -> V_37 = V_38 ;
V_4 -> V_39 = 16 ;
V_4 -> V_40 = 1 ;
V_4 -> V_41 = & V_42 ;
V_4 -> V_43 = F_4 ;
V_4 = V_2 -> V_35 + 1 ;
V_4 -> type = V_44 ;
V_4 -> V_37 = V_45 ;
V_4 -> V_39 = 16 ;
V_4 -> V_40 = 1 ;
V_4 -> V_41 = & V_42 ;
V_4 -> V_43 = F_1 ;
F_11 ( L_10 ) ;
return 1 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_15 * V_18 = F_17 ( V_2 ) ;
if ( V_18 ) {
if ( V_2 -> V_10 )
F_18 ( V_18 ) ;
F_19 ( V_18 ) ;
}
}
static int T_1 F_20 ( struct V_15 * V_2 ,
const struct V_46 * V_47 )
{
return F_21 ( V_2 , & V_48 ) ;
}
static void T_2 F_22 ( struct V_15 * V_2 )
{
F_23 ( V_2 ) ;
}

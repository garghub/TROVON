static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = NULL ;
struct V_7 * V_8 ;
int V_9 , V_10 ;
int V_11 ;
F_2 ( V_12 L_1 , V_2 -> V_13 ) ;
V_2 -> V_14 = L_2 ;
V_9 = V_4 -> V_15 [ 0 ] ;
V_10 = V_4 -> V_15 [ 1 ] ;
if ( F_3 ( V_2 , sizeof( struct V_16 ) ) < 0 )
return - V_17 ;
if ( F_4 ( V_2 , 4 ) < 0 )
return - V_17 ;
F_5 (pcidev) {
if ( V_6 -> V_18 == V_19 &&
V_6 -> V_20 == V_21 ) {
if ( V_9 || V_10 ) {
if ( V_6 -> V_9 -> V_22 != V_9
|| F_6 ( V_6 -> V_23 ) != V_10 ) {
continue;
}
}
V_24 -> V_5 = V_6 ;
if ( F_7 ( V_6 , L_3 ) < 0 ) {
F_2 ( V_25 L_4 ,
V_2 -> V_13 ) ;
return - V_26 ;
}
V_2 -> V_27 = F_8 ( V_6 , 2 ) ;
F_2 ( V_12 L_5 ,
V_2 -> V_27 ) ;
V_8 = V_2 -> V_28 + 0 ;
F_9 ( V_2 , V_8 , NULL ,
( unsigned long ) ( V_2 -> V_27 ) ) ;
V_8 = V_2 -> V_28 + 1 ;
V_11 = F_9 ( V_2 , V_8 , NULL ,
( unsigned long ) ( V_2 -> V_27 +
V_29 ) ) ;
if ( V_11 < 0 )
return V_11 ;
V_8 = V_2 -> V_28 + 2 ;
V_11 = F_9 ( V_2 , V_8 , NULL ,
( unsigned long ) ( V_2 -> V_27 +
V_30 ) ) ;
if ( V_11 < 0 )
return V_11 ;
V_8 = V_2 -> V_28 + 3 ;
V_11 = F_9 ( V_2 , V_8 , NULL ,
( unsigned long ) ( V_2 -> V_27 +
V_31 ) ) ;
if ( V_11 < 0 )
return V_11 ;
F_2 ( V_32 L_6 ,
V_2 -> V_13 ) ;
return 1 ;
}
}
F_2 ( V_25 L_7 ,
V_2 -> V_13 , V_9 , V_10 ) ;
return - V_26 ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_24 && V_24 -> V_5 ) {
if ( V_2 -> V_27 )
F_11 ( V_24 -> V_5 ) ;
F_12 ( V_24 -> V_5 ) ;
}
if ( V_2 -> V_28 ) {
F_13 ( V_2 , V_2 -> V_28 + 0 ) ;
F_13 ( V_2 , V_2 -> V_28 + 1 ) ;
F_13 ( V_2 , V_2 -> V_28 + 2 ) ;
F_13 ( V_2 , V_2 -> V_28 + 3 ) ;
}
}
static int T_1 F_14 ( struct V_5 * V_2 ,
const struct V_33 * V_34 )
{
return F_15 ( V_2 , & V_35 ) ;
}
static void T_2 F_16 ( struct V_5 * V_2 )
{
F_17 ( V_2 ) ;
}

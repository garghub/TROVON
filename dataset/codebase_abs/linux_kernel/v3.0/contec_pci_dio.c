static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = NULL ;
struct V_7 * V_8 ;
F_2 ( L_1 , V_2 -> V_9 ) ;
V_2 -> V_10 = V_11 -> V_12 ;
if ( F_3 ( V_2 , sizeof( struct V_13 ) ) < 0 )
return - V_14 ;
if ( F_4 ( V_2 , 2 ) < 0 )
return - V_14 ;
F_5 (pcidev) {
if ( V_6 -> V_15 == V_16 &&
V_6 -> V_17 == V_18 ) {
if ( V_4 -> V_19 [ 0 ] || V_4 -> V_19 [ 1 ] ) {
if ( V_4 -> V_19 [ 0 ] != V_6 -> V_20 -> V_21 ||
V_4 -> V_19 [ 1 ] != F_6 ( V_6 -> V_22 ) ) {
continue;
}
}
V_23 -> V_5 = V_6 ;
if ( F_7 ( V_6 , L_2 ) ) {
F_2
( L_3 ) ;
return - V_24 ;
}
V_2 -> V_25 = F_8 ( V_6 , 0 ) ;
F_2 ( L_4 , V_2 -> V_25 ) ;
V_2 -> V_26 = V_27 + 0 ;
V_8 = V_2 -> V_28 + 0 ;
V_8 -> type = V_29 ;
V_8 -> V_30 = V_31 ;
V_8 -> V_32 = 16 ;
V_8 -> V_33 = 1 ;
V_8 -> V_34 = & V_35 ;
V_8 -> V_36 = V_37 ;
V_8 = V_2 -> V_28 + 1 ;
V_8 -> type = V_38 ;
V_8 -> V_30 = V_39 ;
V_8 -> V_32 = 16 ;
V_8 -> V_33 = 1 ;
V_8 -> V_34 = & V_35 ;
V_8 -> V_36 = V_40 ;
F_2 ( L_5 ) ;
return 1 ;
}
}
F_2 ( L_6 ) ;
return - V_24 ;
}
static int F_9 ( struct V_1 * V_2 )
{
F_2 ( L_7 , V_2 -> V_9 ) ;
if ( V_23 && V_23 -> V_5 ) {
if ( V_2 -> V_25 )
F_10 ( V_23 -> V_5 ) ;
F_11 ( V_23 -> V_5 ) ;
}
return 0 ;
}
static int V_40 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_41 * V_42 , unsigned int * V_43 )
{
F_2 ( L_8 ) ;
F_2 ( L_9 , V_43 [ 0 ] , V_43 [ 1 ] ) ;
if ( V_42 -> V_44 != 2 )
return - V_45 ;
if ( V_43 [ 0 ] ) {
V_8 -> V_46 &= ~ V_43 [ 0 ] ;
V_8 -> V_46 |= V_43 [ 0 ] & V_43 [ 1 ] ;
F_2 ( L_10 , V_8 -> V_46 ,
V_2 -> V_25 + V_11 -> V_47 ) ;
F_12 ( V_8 -> V_46 , V_2 -> V_25 + V_11 -> V_47 ) ;
}
return 2 ;
}
static int V_37 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_41 * V_42 , unsigned int * V_43 )
{
F_2 ( L_11 ) ;
F_2 ( L_9 , V_43 [ 0 ] , V_43 [ 1 ] ) ;
if ( V_42 -> V_44 != 2 )
return - V_45 ;
V_43 [ 1 ] = F_13 ( V_2 -> V_25 + V_11 -> V_48 ) ;
return 2 ;
}
static int T_1 F_14 ( struct V_5 * V_2 ,
const struct V_49 * V_50 )
{
return F_15 ( V_2 , V_51 . V_52 ) ;
}
static void T_2 F_16 ( struct V_5 * V_2 )
{
F_17 ( V_2 ) ;
}
static int T_3 F_18 ( void )
{
int V_53 ;
V_53 = F_19 ( & V_51 ) ;
if ( V_53 < 0 )
return V_53 ;
V_54 . V_12 = ( char * ) V_51 . V_52 ;
return F_20 ( & V_54 ) ;
}
static void T_4 F_21 ( void )
{
F_22 ( & V_54 ) ;
F_23 ( & V_51 ) ;
}

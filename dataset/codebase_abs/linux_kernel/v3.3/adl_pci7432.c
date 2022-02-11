static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = NULL ;
struct V_7 * V_8 ;
int V_9 , V_10 ;
F_2 ( V_11 L_1 , V_2 -> V_12 ) ;
V_2 -> V_13 = L_2 ;
V_9 = V_4 -> V_14 [ 0 ] ;
V_10 = V_4 -> V_14 [ 1 ] ;
if ( F_3 ( V_2 , sizeof( struct V_15 ) ) < 0 )
return - V_16 ;
if ( F_4 ( V_2 , 2 ) < 0 )
return - V_16 ;
F_5 (pcidev) {
if ( V_6 -> V_17 == V_18 &&
V_6 -> V_19 == V_20 ) {
if ( V_9 || V_10 ) {
if ( V_6 -> V_9 -> V_21 != V_9
|| F_6 ( V_6 -> V_22 ) != V_10 ) {
continue;
}
}
V_23 -> V_5 = V_6 ;
if ( F_7 ( V_6 , L_3 ) < 0 ) {
F_2 ( V_24 L_4 ,
V_2 -> V_12 ) ;
return - V_25 ;
}
V_2 -> V_26 = F_8 ( V_6 , 2 ) ;
F_2 ( V_11 L_5 ,
V_2 -> V_26 ) ;
V_8 = V_2 -> V_27 + 0 ;
V_8 -> type = V_28 ;
V_8 -> V_29 =
V_30 | V_31 | V_32 ;
V_8 -> V_33 = 32 ;
V_8 -> V_34 = 1 ;
V_8 -> V_35 = 32 ;
V_8 -> V_36 = 0x00000000 ;
V_8 -> V_37 = & V_38 ;
V_8 -> V_39 = V_40 ;
V_8 = V_2 -> V_27 + 1 ;
V_8 -> type = V_41 ;
V_8 -> V_29 =
V_42 | V_31 | V_32 ;
V_8 -> V_33 = 32 ;
V_8 -> V_34 = 1 ;
V_8 -> V_35 = 32 ;
V_8 -> V_36 = 0xffffffff ;
V_8 -> V_37 = & V_38 ;
V_8 -> V_39 = V_43 ;
F_2 ( V_44 L_6 ,
V_2 -> V_12 ) ;
return 1 ;
}
}
F_2 ( V_24 L_7 ,
V_2 -> V_12 , V_9 , V_10 ) ;
return - V_25 ;
}
static int F_9 ( struct V_1 * V_2 )
{
F_2 ( V_11 L_8 , V_2 -> V_12 ) ;
if ( V_23 && V_23 -> V_5 ) {
if ( V_2 -> V_26 )
F_10 ( V_23 -> V_5 ) ;
F_11 ( V_23 -> V_5 ) ;
}
return 0 ;
}
static int V_43 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_45 * V_46 ,
unsigned int * V_47 )
{
F_2 ( V_44 L_9 ) ;
F_2 ( V_44 L_10 , V_47 [ 0 ] , V_47 [ 1 ] ) ;
if ( V_46 -> V_48 != 2 )
return - V_49 ;
if ( V_47 [ 0 ] ) {
V_8 -> V_50 &= ~ V_47 [ 0 ] ;
V_8 -> V_50 |= ( V_47 [ 0 ] & V_47 [ 1 ] ) ;
F_2 ( V_44 L_11 , V_8 -> V_50 ,
V_2 -> V_26 + V_51 ) ;
F_12 ( V_8 -> V_50 & 0xffffffff , V_2 -> V_26 + V_51 ) ;
}
return 2 ;
}
static int V_40 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_45 * V_46 ,
unsigned int * V_47 )
{
F_2 ( V_44 L_12 ) ;
F_2 ( V_44 L_10 , V_47 [ 0 ] , V_47 [ 1 ] ) ;
if ( V_46 -> V_48 != 2 )
return - V_49 ;
V_47 [ 1 ] = F_13 ( V_2 -> V_26 + V_52 ) & 0xffffffff ;
F_2 ( V_44 L_13 , V_47 [ 1 ] ) ;
return 2 ;
}
static int T_1 F_14 ( struct V_5 * V_2 ,
const struct V_53
* V_54 )
{
return F_15 ( V_2 , V_55 . V_56 ) ;
}
static void T_2 F_16 ( struct V_5 * V_2 )
{
F_17 ( V_2 ) ;
}
static int T_3 F_18 ( void )
{
int V_57 ;
V_57 = F_19 ( & V_55 ) ;
if ( V_57 < 0 )
return V_57 ;
V_58 . V_59 =
( char * ) V_55 . V_56 ;
return F_20 ( & V_58 ) ;
}
static void T_4 F_21 ( void )
{
F_22 ( & V_58 ) ;
F_23 ( & V_55 ) ;
}

static void T_1 F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
if ( V_2 -> V_3 . V_4 == 2 && V_2 -> V_5 -> V_6 == 0x5354 ) {
F_3 ( V_2 , 0x894 , 0x00fe00fe ) ;
F_3 ( V_2 , 0x89c , F_4 ( V_2 , 0x89c ) | 0x1 ) ;
}
#endif
}
static void T_1 F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_7 == V_8 ) {
F_3 ( V_2 , 0x200 , 0x7ff ) ;
F_3 ( V_2 , 0x400 , F_4 ( V_2 , 0x400 ) & ~ 8 ) ;
F_4 ( V_2 , 0x400 ) ;
F_3 ( V_2 , 0x304 , F_4 ( V_2 , 0x304 ) & ~ 0x100 ) ;
F_4 ( V_2 , 0x304 ) ;
F_6 ( 1 ) ;
F_1 ( V_2 ) ;
}
}
static T_2 T_1 F_7 ( struct V_1 * V_2 )
{
T_2 V_9 = 0 ;
if ( V_2 -> V_3 . V_7 == V_10 )
V_9 |= V_11 ;
F_8 ( V_2 , V_9 ) ;
F_5 ( V_2 ) ;
return V_9 ;
}
static struct V_12 * T_1
F_9 ( struct V_1 * V_2 , bool V_13 , T_2 V_14 , T_2 V_15 )
{
struct V_12 * V_16 ;
struct V_17 V_18 [ 2 ] ;
int V_19 = - V_20 ;
memset ( V_18 , 0 , sizeof( V_18 ) ) ;
V_18 [ 0 ] . V_21 = V_14 ;
V_18 [ 0 ] . V_22 = V_18 [ 0 ] . V_21 + V_15 - 1 ;
V_18 [ 0 ] . V_9 = V_23 ;
V_18 [ 1 ] . V_21 = V_2 -> V_24 ;
V_18 [ 1 ] . V_9 = V_25 ;
V_16 = F_10 ( V_13 ? L_1 :
L_2 , 0 ) ;
if ( ! V_16 )
return NULL ;
V_16 -> V_2 . V_26 = V_2 -> V_2 ;
V_16 -> V_2 . V_27 = & V_16 -> V_2 . V_28 ;
V_19 = F_11 ( V_16 , V_18 ,
F_12 ( V_18 ) ) ;
if ( V_19 )
goto V_29;
if ( V_13 )
V_19 = F_13 ( V_16 , & V_30 ,
sizeof( V_30 ) ) ;
else
V_19 = F_13 ( V_16 , & V_31 ,
sizeof( V_31 ) ) ;
if ( V_19 )
goto V_29;
V_19 = F_14 ( V_16 ) ;
if ( V_19 )
goto V_29;
return V_16 ;
V_29:
F_15 ( V_16 ) ;
return F_16 ( V_19 ) ;
}
static int T_1 F_17 ( struct V_1 * V_2 ,
const struct V_32 * V_3 )
{
int V_33 , V_34 ;
int V_21 , V_15 ;
T_3 V_35 ;
T_3 V_7 = V_2 -> V_3 . V_7 ;
struct V_36 * V_37 ;
V_35 = ( V_2 -> V_5 -> V_6 & 0xFF00 ) ;
if ( V_35 != 0x4700 && V_35 != 0x5300 )
return - V_38 ;
if ( F_18 ( V_2 -> V_39 , F_19 ( 32 ) ) ||
F_20 ( V_2 -> V_39 , F_19 ( 32 ) ) )
return - V_40 ;
V_37 = F_21 ( sizeof( struct V_36 ) , V_41 ) ;
if ( ! V_37 )
return - V_20 ;
V_37 -> V_42 = F_7 ( V_2 ) ;
V_34 = F_4 ( V_2 , V_43 ) ;
V_21 = F_22 ( V_34 ) ;
V_15 = ( V_7 == V_8 ) ? 0x800 : F_23 ( V_34 ) ;
V_37 -> V_44 = F_9 ( V_2 , true , V_21 , V_15 ) ;
if ( F_24 ( V_37 -> V_44 ) ) {
V_33 = F_25 ( V_37 -> V_44 ) ;
goto V_45;
}
if ( V_7 == V_8 ) {
V_21 = F_22 ( V_34 ) + 0x800 ;
V_37 -> V_46 = F_9 ( V_2 , false , V_21 , V_15 ) ;
if ( F_24 ( V_37 -> V_46 ) ) {
V_33 = F_25 ( V_37 -> V_46 ) ;
goto V_47;
}
}
F_26 ( V_2 , V_37 ) ;
return 0 ;
V_47:
F_27 ( V_37 -> V_44 ) ;
V_45:
F_28 ( V_37 ) ;
return V_33 ;
}
static void T_4 F_29 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_30 ( V_2 ) ;
struct V_12 * V_44 = V_37 -> V_44 ;
struct V_12 * V_46 = V_37 -> V_46 ;
if ( V_44 )
F_27 ( V_44 ) ;
if ( V_46 )
F_27 ( V_46 ) ;
F_31 ( V_2 , 0 ) ;
}
static void T_4 F_32 ( struct V_1 * V_2 )
{
F_31 ( V_2 , 0 ) ;
}
static int F_33 ( struct V_1 * V_2 , T_5 V_48 )
{
F_31 ( V_2 , 0 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = F_30 ( V_2 ) ;
F_8 ( V_2 , V_37 -> V_42 ) ;
return 0 ;
}
static int T_6 F_35 ( void )
{
return F_36 ( & V_49 ) ;
}
static void T_7 F_37 ( void )
{
F_38 ( & V_49 ) ;
}

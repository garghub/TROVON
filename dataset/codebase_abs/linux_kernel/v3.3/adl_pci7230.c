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
if ( V_6 -> V_9 -> V_21 != V_9 ||
F_6 ( V_6 -> V_22 ) != V_10 ) {
continue;
}
}
V_23 -> V_5 = V_6 ;
break;
}
}
if ( V_6 == NULL ) {
F_2 ( V_24 L_3 ,
V_2 -> V_12 , V_9 , V_10 ) ;
return - V_25 ;
}
if ( F_7 ( V_6 , L_4 ) < 0 ) {
F_2 ( V_24 L_5 ,
V_2 -> V_12 ) ;
return - V_25 ;
}
V_2 -> V_26 = F_8 ( V_6 , 2 ) ;
F_2 ( V_27 L_6 , V_2 -> V_26 ) ;
V_8 = V_2 -> V_28 + 0 ;
V_8 -> type = V_29 ;
V_8 -> V_30 = V_31 | V_32 | V_33 ;
V_8 -> V_34 = 16 ;
V_8 -> V_35 = 1 ;
V_8 -> V_36 = & V_37 ;
V_8 -> V_38 = V_39 ;
V_8 = V_2 -> V_28 + 1 ;
V_8 -> type = V_40 ;
V_8 -> V_30 = V_41 | V_32 | V_33 ;
V_8 -> V_34 = 16 ;
V_8 -> V_35 = 1 ;
V_8 -> V_36 = & V_37 ;
V_8 -> V_38 = V_42 ;
F_2 ( V_27 L_7 ) ;
return 1 ;
}
static int F_9 ( struct V_1 * V_2 )
{
F_2 ( V_27 L_8 , V_2 -> V_12 ) ;
if ( V_23 && V_23 -> V_5 ) {
if ( V_2 -> V_26 )
F_10 ( V_23 -> V_5 ) ;
F_11 ( V_23 -> V_5 ) ;
}
return 0 ;
}
static int V_39 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_43 * V_44 ,
unsigned int * V_45 )
{
if ( V_44 -> V_46 != 2 )
return - V_47 ;
if ( V_45 [ 0 ] ) {
V_8 -> V_48 &= ~ V_45 [ 0 ] ;
V_8 -> V_48 |= ( V_45 [ 0 ] & V_45 [ 1 ] ) ;
F_12 ( ( V_8 -> V_48 << 16 ) & 0xffffffff , V_2 -> V_26 + V_49 ) ;
}
return 2 ;
}
static int V_42 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_43 * V_44 ,
unsigned int * V_45 )
{
if ( V_44 -> V_46 != 2 )
return - V_47 ;
V_45 [ 1 ] = F_13 ( V_2 -> V_26 + V_50 ) & 0xffffffff ;
return 2 ;
}
static int T_1 F_14 ( struct V_5 * V_2 ,
const struct V_51
* V_52 )
{
return F_15 ( V_2 , V_53 . V_54 ) ;
}
static void T_2 F_16 ( struct V_5 * V_2 )
{
F_17 ( V_2 ) ;
}
static int T_3 F_18 ( void )
{
int V_55 ;
V_55 = F_19 ( & V_53 ) ;
if ( V_55 < 0 )
return V_55 ;
V_56 . V_57 =
( char * ) V_53 . V_54 ;
return F_20 ( & V_56 ) ;
}
static void T_4 F_21 ( void )
{
F_22 ( & V_56 ) ;
F_23 ( & V_53 ) ;
}

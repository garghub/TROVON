static void F_1 ( T_1 * V_1 , T_2 * V_2 )
{
const T_3 V_3 = V_2 -> V_4 ;
T_3 V_5 = ( V_3 & 0x10 ) >> 4 , V_6 = 0 , V_7 = 0 ;
V_6 = V_1 -> V_8 ? V_9 : V_10 ;
V_7 = ( V_3 & 3 ) | ( V_5 << 2 ) ;
F_2 ( V_6 , V_11 ) ;
F_2 ( V_7 , V_12 ) ;
V_7 = V_13 ;
F_2 ( V_14 , V_11 ) ;
F_2 ( V_7 , V_12 ) ;
}
static void F_3 ( T_1 * V_1 , T_2 * V_2 )
{
struct V_15 * V_16 = F_4 ( V_1 -> V_16 ) ;
int V_17 = V_18 ? V_18 : 33 ;
const unsigned long V_19 = 1000000 / V_17 ;
unsigned int V_20 ;
struct V_21 V_22 ;
T_3 V_23 , V_24 ;
if ( V_2 -> V_25 > 1 ) {
V_16 = F_5 ( V_16 -> V_26 , V_16 -> V_27 + 1 ) ;
if ( ! V_16 ) {
F_6 ( V_28 L_1
L_2 ,
V_2 -> V_29 ) ;
return;
}
}
F_7 ( V_2 , V_2 -> V_30 , & V_22 , V_19 , 1 ) ;
V_23 = F_8 ( V_22 . V_31 - 1 , 0 , 15 ) |
( F_8 ( V_22 . V_32 - 1 , 0 , 15 ) << 4 ) ;
V_24 = F_8 ( V_22 . V_33 - 1 , 0 , 15 ) |
( F_8 ( V_22 . V_34 - 1 , 0 , 15 ) << 4 ) ;
if ( ( V_2 -> V_25 & 1 ) == 0 ) {
F_9 ( V_16 , V_35 , & V_20 ) ;
V_20 &= ( ~ 0xF ) ;
V_20 |= F_8 ( V_22 . V_36 - 1 , 0 , 15 ) ;
F_10 ( V_16 , V_35 , V_20 ) ;
F_11 ( V_16 , V_37 , V_23 ) ;
F_11 ( V_16 , V_38 , V_23 ) ;
F_11 ( V_16 , V_39 , V_24 ) ;
} else {
F_9 ( V_16 , V_35 , & V_20 ) ;
V_20 &= ( ~ 0xF0 ) ;
V_20 |= ( F_8 ( V_22 . V_36 - 1 , 0 , 15 ) << 4 ) ;
F_10 ( V_16 , V_35 , V_20 ) ;
F_11 ( V_16 , V_40 , V_23 ) ;
F_11 ( V_16 , V_41 , V_23 ) ;
F_11 ( V_16 , V_42 , V_24 ) ;
}
if ( V_2 -> V_25 > 1 )
F_12 ( V_16 ) ;
}
static void F_13 ( T_1 * V_1 )
{
static T_1 * V_43 ;
struct V_15 * V_16 = F_4 ( V_1 -> V_16 ) ;
if ( F_14 ( V_16 -> V_27 ) == 1 )
V_43 = V_1 ;
else {
V_1 -> V_44 = V_43 ;
V_1 -> V_8 = 1 ;
}
}
static int F_15 ( struct V_15 * V_16 ,
const struct V_45 * V_46 )
{
struct V_15 * V_47 ;
int V_48 = - V_49 ;
if ( ( V_16 -> V_50 >> 8 ) == V_51 &&
F_14 ( V_16 -> V_27 ) == 1 ) {
V_47 = F_5 ( V_16 -> V_26 , V_16 -> V_27 + 1 ) ;
V_48 = F_16 ( V_16 , V_47 , & V_52 , NULL ) ;
if ( V_48 )
F_12 ( V_47 ) ;
}
return V_48 ;
}
static void F_17 ( struct V_15 * V_16 )
{
struct V_53 * V_54 = F_18 ( V_16 ) ;
struct V_15 * V_47 = V_54 -> V_16 [ 1 ] ? F_4 ( V_54 -> V_16 [ 1 ] ) : NULL ;
F_19 ( V_16 ) ;
F_12 ( V_47 ) ;
}
static int T_4 F_20 ( void )
{
return F_21 ( & V_55 ) ;
}
static void T_5 F_22 ( void )
{
F_23 ( & V_55 ) ;
}

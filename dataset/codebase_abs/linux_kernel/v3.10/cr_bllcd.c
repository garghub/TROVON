static int F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 . V_5 ;
T_1 V_6 = V_7 + V_8 ;
T_1 V_9 = F_2 ( V_6 ) ;
if ( V_2 -> V_4 . V_10 == V_11 )
V_3 = V_11 ;
if ( V_2 -> V_4 . V_12 == V_11 )
V_3 = V_11 ;
if ( V_2 -> V_4 . V_10 == V_13 )
V_3 = V_13 ;
if ( V_2 -> V_4 . V_12 == V_13 )
V_3 = V_13 ;
if ( V_3 == V_11 ) {
V_9 &= ~ V_14 ;
F_3 ( V_9 , V_6 ) ;
} else if ( V_3 == V_13 ) {
V_9 |= V_14 ;
F_3 ( V_9 , V_6 ) ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
T_1 V_6 = V_7 + V_8 ;
T_1 V_9 = F_2 ( V_6 ) ;
T_2 V_3 ;
if ( V_9 & V_14 )
V_3 = V_13 ;
else
V_3 = V_11 ;
return V_3 ;
}
static void F_5 ( void )
{
T_1 V_6 = V_7 + V_8 ;
T_1 V_9 = F_2 ( V_6 ) ;
if ( ! ( V_9 & V_15 ) ) {
if ( V_9 & 0x00000001 ) {
V_9 &= ~ V_16 ;
F_3 ( V_9 , V_6 ) ;
}
F_6 ( V_17 / 10 ) ;
V_9 |= V_15 ;
F_3 ( V_9 , V_6 ) ;
}
if ( ! ( V_9 & V_16 ) ) {
F_6 ( V_17 / 10 ) ;
F_3 ( V_9 | V_16 , V_6 ) ;
}
}
static void F_7 ( void )
{
T_1 V_6 = V_7 + V_8 ;
T_1 V_9 = F_2 ( V_6 ) ;
if ( V_9 & V_16 ) {
V_9 &= ~ V_16 ;
F_3 ( V_9 , V_6 ) ;
}
if ( V_9 & V_15 ) {
F_6 ( V_17 / 10 ) ;
F_3 ( V_9 & ~ V_15 , V_6 ) ;
}
}
static int F_8 ( struct V_18 * V_19 , int V_10 )
{
if ( V_10 == V_11 )
F_5 () ;
if ( V_10 == V_13 )
F_7 () ;
return 0 ;
}
static int F_9 ( struct V_20 * V_21 )
{
struct V_22 V_4 ;
struct V_1 * V_23 ;
struct V_18 * V_24 ;
struct V_25 * V_26 ;
T_2 V_27 ;
V_28 = F_10 ( V_29 ,
V_30 , NULL ) ;
if ( ! V_28 ) {
F_11 ( L_1 ) ;
return - V_31 ;
}
F_12 ( V_28 , V_32 , & V_27 ) ;
if ( ! ( V_27 & V_33 ) ) {
F_11 ( L_2 ) ;
F_13 ( V_28 ) ;
return - V_31 ;
}
memset ( & V_4 , 0 , sizeof( struct V_22 ) ) ;
V_4 . type = V_34 ;
V_23 = F_14 ( L_3 , & V_21 -> V_35 , NULL ,
& V_36 , & V_4 ) ;
if ( F_15 ( V_23 ) ) {
F_13 ( V_28 ) ;
return F_16 ( V_23 ) ;
}
V_24 = F_17 ( L_4 , & V_21 -> V_35 , NULL , & V_37 ) ;
if ( F_15 ( V_24 ) ) {
F_18 ( V_23 ) ;
F_13 ( V_28 ) ;
return F_16 ( V_24 ) ;
}
F_19 ( V_28 , V_38 ,
& V_7 ) ;
V_7 &= ~ 0x3F ;
V_26 = F_20 ( & V_21 -> V_35 , sizeof( * V_26 ) , V_39 ) ;
if ( ! V_26 ) {
F_21 ( V_24 ) ;
F_18 ( V_23 ) ;
F_13 ( V_28 ) ;
return - V_40 ;
}
V_26 -> V_41 = V_23 ;
V_26 -> V_42 = V_24 ;
V_26 -> V_41 -> V_4 . V_10 = V_11 ;
V_26 -> V_41 -> V_4 . V_5 = 0 ;
F_1 ( V_26 -> V_41 ) ;
F_8 ( V_26 -> V_42 , V_11 ) ;
F_22 ( V_21 , V_26 ) ;
return 0 ;
}
static int F_23 ( struct V_20 * V_21 )
{
struct V_25 * V_26 = F_24 ( V_21 ) ;
V_26 -> V_41 -> V_4 . V_10 = V_13 ;
V_26 -> V_41 -> V_4 . V_5 = 0 ;
V_26 -> V_41 -> V_4 . V_43 = 0 ;
F_1 ( V_26 -> V_41 ) ;
F_8 ( V_26 -> V_42 , V_13 ) ;
F_18 ( V_26 -> V_41 ) ;
F_21 ( V_26 -> V_42 ) ;
F_13 ( V_28 ) ;
return 0 ;
}
static int T_3 F_25 ( void )
{
int V_44 = F_26 ( & V_45 ) ;
if ( V_44 )
return V_44 ;
V_26 = F_27 ( L_5 , - 1 , NULL , 0 ) ;
if ( F_15 ( V_26 ) ) {
F_28 ( & V_45 ) ;
return F_16 ( V_26 ) ;
}
F_29 ( L_6 ) ;
return 0 ;
}
static void T_4 F_30 ( void )
{
F_31 ( V_26 ) ;
F_28 ( & V_45 ) ;
}

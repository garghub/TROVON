static void F_1 ( struct V_1 * V_2 , unsigned V_3 , int V_4 )
{
T_1 V_5 ;
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
F_3 ( & V_7 -> V_8 ) ;
V_5 = F_4 ( & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_12 ) ;
if ( V_4 )
V_5 |= ( 1 << V_3 ) ;
else
V_5 &= ~ ( 1 << V_3 ) ;
F_5 ( V_5 , & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_12 ) ;
F_6 ( & V_7 -> V_8 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
return F_4 ( & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_13 ) & ( 1 << V_3 ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 ,
int V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
T_1 V_14 ;
T_1 V_5 ;
F_3 ( & V_7 -> V_8 ) ;
V_14 = F_4 ( & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_14 ) &
( ( 1 << V_15 [ V_7 -> V_11 ] ) - 1 ) ;
V_14 |= ( 1 << V_3 ) ;
F_5 ( V_14 , & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_14 ) ;
V_5 = F_4 ( & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_12 ) ;
if ( V_4 )
V_5 |= ( 1 << V_3 ) ;
else
V_5 &= ~ ( 1 << V_3 ) ;
F_5 ( V_5 , & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_12 ) ;
F_6 ( & V_7 -> V_8 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
T_1 V_14 ;
F_3 ( & V_7 -> V_8 ) ;
V_14 = F_4 ( & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_14 ) &
( ( 1 << V_15 [ V_7 -> V_11 ] ) - 1 ) ;
V_14 &= ~ ( 1 << V_3 ) ;
F_5 ( V_14 , & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_14 ) ;
F_6 ( & V_7 -> V_8 ) ;
return 0 ;
}
static void F_10 ( struct V_6 * V_7 )
{
V_7 -> V_16 . V_17 = F_4 ( & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_12 ) ;
V_7 -> V_16 . V_18 = F_4 ( & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_14 ) ;
}
static void F_11 ( struct V_6 * V_7 )
{
F_5 ( V_7 -> V_16 . V_17 , & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_12 ) ;
F_5 ( V_7 -> V_16 . V_18 , & V_7 -> V_9 -> V_10 [ V_7 -> V_11 ] . V_14 ) ;
}
static void F_12 ( struct V_6 * V_7 , int V_19 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
V_2 -> V_20 = F_13 ( V_7 -> V_21 ) ;
V_2 -> V_22 = V_23 ;
V_2 -> V_24 = F_9 ;
V_2 -> V_25 = F_7 ;
V_2 -> V_26 = F_8 ;
V_2 -> V_27 = F_1 ;
V_2 -> V_28 = NULL ;
V_2 -> V_29 = - 1 ;
V_2 -> V_30 = V_19 ;
V_2 -> V_31 = 0 ;
}
static int T_2 F_14 ( struct V_32 * V_33 ,
const struct V_34 * V_35 )
{
int V_36 ;
int V_37 ;
struct V_6 * V_7 ;
void T_3 * V_29 ;
void T_3 * V_38 ;
V_36 = F_15 ( V_33 ) ;
if ( V_36 ) {
F_16 ( & V_33 -> V_21 , L_1 , V_39 ) ;
goto V_40;
}
V_36 = F_17 ( V_33 , V_41 ) ;
if ( V_36 ) {
F_16 ( & V_33 -> V_21 , L_2 , V_36 ) ;
goto V_42;
}
V_29 = F_18 ( V_33 , 1 , 0 ) ;
if ( V_29 == 0 ) {
F_16 ( & V_33 -> V_21 , L_3 , V_39 ) ;
V_36 = - V_43 ;
goto V_44;
}
V_38 = F_19 ( sizeof( * V_7 ) * 8 , V_45 ) ;
if ( V_38 == NULL ) {
F_16 ( & V_33 -> V_21 , L_4 , V_39 ) ;
V_36 = - V_43 ;
goto V_46;
}
V_7 = V_38 ;
for ( V_37 = 0 ; V_37 < 8 ; V_37 ++ , V_7 ++ ) {
V_7 -> V_21 = & V_33 -> V_21 ;
V_7 -> V_29 = V_29 ;
V_7 -> V_9 = V_7 -> V_29 ;
V_7 -> V_11 = V_37 ;
F_20 ( & V_7 -> V_8 ) ;
F_12 ( V_7 , V_15 [ V_37 ] ) ;
V_36 = F_21 ( & V_7 -> V_2 ) ;
if ( V_36 ) {
F_16 ( & V_33 -> V_21 , L_5 ) ;
goto V_47;
}
}
V_7 = V_38 ;
F_22 ( V_33 , V_7 ) ;
return 0 ;
V_47:
for (; V_37 != 0 ; V_37 -- ) {
V_7 -- ;
V_36 = F_23 ( & V_7 -> V_2 ) ;
if ( V_36 )
F_16 ( & V_33 -> V_21 , L_6 , V_37 ) ;
}
F_24 ( V_38 ) ;
V_46:
F_25 ( V_33 , V_29 ) ;
V_44:
F_26 ( V_33 ) ;
V_42:
F_27 ( V_33 ) ;
V_40:
F_16 ( & V_33 -> V_21 , L_7 , V_39 , V_36 ) ;
return V_36 ;
}
static void T_4 F_28 ( struct V_32 * V_33 )
{
int V_48 ;
int V_37 ;
struct V_6 * V_7 = F_29 ( V_33 ) ;
void T_3 * V_38 ;
V_38 = V_7 ;
for ( V_37 = 0 ; V_37 < 8 ; V_37 ++ , V_7 ++ ) {
V_48 = F_23 ( & V_7 -> V_2 ) ;
if ( V_48 )
F_16 ( & V_33 -> V_21 , L_8 ) ;
}
V_7 = V_38 ;
F_25 ( V_33 , V_7 -> V_29 ) ;
F_26 ( V_33 ) ;
F_27 ( V_33 ) ;
F_24 ( V_7 ) ;
}
static int F_30 ( struct V_32 * V_33 , T_5 V_49 )
{
T_6 V_36 ;
struct V_6 * V_7 = F_29 ( V_33 ) ;
F_10 ( V_7 ) ;
F_11 ( V_7 ) ;
V_36 = F_31 ( V_33 ) ;
if ( V_36 ) {
F_16 ( & V_33 -> V_21 , L_9 , V_36 ) ;
return V_36 ;
}
F_27 ( V_33 ) ;
F_32 ( V_33 , V_50 ) ;
V_36 = F_33 ( V_33 , V_50 , 1 ) ;
if ( V_36 )
F_16 ( & V_33 -> V_21 , L_10 , V_36 ) ;
return 0 ;
}
static int F_34 ( struct V_32 * V_33 )
{
T_6 V_36 ;
struct V_6 * V_7 = F_29 ( V_33 ) ;
V_36 = F_33 ( V_33 , V_50 , 0 ) ;
F_32 ( V_33 , V_50 ) ;
V_36 = F_15 ( V_33 ) ;
if ( V_36 ) {
F_16 ( & V_33 -> V_21 , L_11 , V_36 ) ;
return V_36 ;
}
F_35 ( V_33 ) ;
F_5 ( 0x01 , & V_7 -> V_9 -> V_51 ) ;
F_5 ( 0x00 , & V_7 -> V_9 -> V_51 ) ;
F_11 ( V_7 ) ;
return 0 ;
}
static int T_7 F_36 ( void )
{
return F_37 ( & V_52 ) ;
}
static void T_8 F_38 ( void )
{
F_39 ( & V_52 ) ;
}

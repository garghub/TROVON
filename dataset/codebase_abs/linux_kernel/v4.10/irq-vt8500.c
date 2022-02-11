static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
void T_1 * V_7 = V_4 -> V_7 ;
void T_1 * V_8 = V_7 + V_9 + ( V_2 -> V_10 < 32 ? 0 : 4 ) ;
T_2 V_11 , V_12 ;
T_3 V_13 ;
V_11 = F_2 ( V_7 + V_14 + V_2 -> V_10 ) & V_15 ;
if ( V_11 ) {
V_13 = F_3 ( V_8 ) ;
V_13 |= ( 1 << ( V_2 -> V_10 & 0x1f ) ) ;
F_4 ( V_13 , V_8 ) ;
} else {
V_12 = F_2 ( V_7 + V_14 + V_2 -> V_10 ) ;
V_12 &= ~ V_16 ;
F_5 ( V_12 , V_7 + V_14 + V_2 -> V_10 ) ;
}
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
void T_1 * V_7 = V_4 -> V_7 ;
T_2 V_12 ;
V_12 = F_2 ( V_7 + V_14 + V_2 -> V_10 ) ;
V_12 |= V_16 ;
F_5 ( V_12 , V_7 + V_14 + V_2 -> V_10 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_17 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
void T_1 * V_7 = V_4 -> V_7 ;
T_2 V_12 ;
V_12 = F_2 ( V_7 + V_14 + V_2 -> V_10 ) ;
V_12 &= ~ V_15 ;
switch ( V_17 ) {
case V_18 :
return - V_19 ;
case V_20 :
V_12 |= V_21 ;
F_8 ( V_2 , V_22 ) ;
break;
case V_23 :
V_12 |= V_24 ;
F_8 ( V_2 , V_25 ) ;
break;
case V_26 :
V_12 |= V_27 ;
F_8 ( V_2 , V_25 ) ;
break;
}
F_5 ( V_12 , V_7 + V_14 + V_2 -> V_10 ) ;
return 0 ;
}
static void T_4 F_9 ( void T_1 * V_7 )
{
T_3 V_28 ;
F_4 ( V_29 , V_7 + V_30 ) ;
F_4 ( 0x00 , V_7 + V_31 ) ;
for ( V_28 = 0 ; V_28 < 64 ; V_28 ++ )
F_5 ( V_32 | V_33 , V_7 + V_14 + V_28 ) ;
}
static int F_10 ( struct V_34 * V_35 , unsigned int V_36 ,
T_5 V_37 )
{
F_11 ( V_36 , & V_38 , V_22 ) ;
return 0 ;
}
static void T_6 F_12 ( struct V_39 * V_40 )
{
T_3 V_41 , V_28 ;
int V_42 ;
void T_1 * V_7 ;
for ( V_28 = 0 ; V_28 < V_43 ; V_28 ++ ) {
V_7 = V_44 [ V_28 ] . V_7 ;
V_42 = F_13 ( V_7 ) & 0x3F ;
if ( V_42 == 63 ) {
V_41 = F_13 ( V_7 + V_9 + 4 ) ;
if ( ! ( V_41 & F_14 ( 31 ) ) )
continue;
}
F_15 ( V_44 [ V_28 ] . V_5 , V_42 , V_40 ) ;
}
}
static int T_4 F_16 ( struct V_45 * V_46 ,
struct V_45 * V_47 )
{
int V_48 , V_28 ;
struct V_45 * V_49 = V_46 ;
if ( V_43 == V_50 ) {
F_17 ( L_1 ,
V_51 ) ;
goto V_52;
}
V_44 [ V_43 ] . V_7 = F_18 ( V_49 , 0 ) ;
V_44 [ V_43 ] . V_5 = F_19 ( V_46 , 64 ,
& V_53 , & V_44 [ V_43 ] ) ;
if ( ! V_44 [ V_43 ] . V_7 ) {
F_17 ( L_2 , V_51 ) ;
goto V_52;
}
if ( ! V_44 [ V_43 ] . V_5 ) {
F_17 ( L_3 , V_51 ) ;
goto V_52;
}
F_20 ( F_12 ) ;
F_9 ( V_44 [ V_43 ] . V_7 ) ;
F_21 ( L_4 ) ;
V_43 ++ ;
if ( F_22 ( V_49 ) != 0 ) {
if ( F_22 ( V_49 ) != 8 ) {
F_17 ( L_5 ,
V_51 ) ;
return - V_19 ;
}
for ( V_28 = 0 ; V_28 < 8 ; V_28 ++ ) {
V_48 = F_23 ( V_49 , V_28 ) ;
F_24 ( V_48 ) ;
}
F_21 ( L_6 ) ;
}
V_52:
return 0 ;
}

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
F_8 ( V_2 -> V_22 , V_23 ) ;
break;
case V_24 :
V_12 |= V_25 ;
F_8 ( V_2 -> V_22 , V_26 ) ;
break;
case V_27 :
V_12 |= V_28 ;
F_8 ( V_2 -> V_22 , V_26 ) ;
break;
}
F_5 ( V_12 , V_7 + V_14 + V_2 -> V_10 ) ;
return 0 ;
}
static void T_4 F_9 ( void T_1 * V_7 )
{
T_3 V_29 ;
F_4 ( V_30 , V_7 + V_31 ) ;
F_4 ( 0x00 , V_7 + V_32 ) ;
for ( V_29 = 0 ; V_29 < 64 ; V_29 ++ )
F_5 ( V_33 | V_34 , V_7 + V_14 + V_29 ) ;
}
static int F_10 ( struct V_35 * V_36 , unsigned int V_37 ,
T_5 V_38 )
{
F_11 ( V_37 , & V_39 , V_23 ) ;
F_12 ( V_37 , V_40 ) ;
return 0 ;
}
static T_6
void T_7 F_13 ( struct V_41 * V_42 )
{
T_3 V_43 , V_29 ;
int V_44 , V_37 ;
void T_1 * V_7 ;
for ( V_29 = 0 ; V_29 < V_45 ; V_29 ++ ) {
V_7 = V_46 [ V_29 ] . V_7 ;
V_44 = F_14 ( V_7 ) & 0x3F ;
if ( V_44 == 63 ) {
V_43 = F_14 ( V_7 + V_9 + 4 ) ;
if ( ! ( V_43 & F_15 ( 31 ) ) )
continue;
}
V_37 = F_16 ( V_46 [ V_29 ] . V_5 , V_44 ) ;
F_17 ( V_37 , V_42 ) ;
}
}
static int T_4 F_18 ( struct V_47 * V_48 ,
struct V_47 * V_49 )
{
int V_22 , V_29 ;
struct V_47 * V_50 = V_48 ;
if ( V_45 == V_51 ) {
F_19 ( L_1 ,
V_52 ) ;
goto V_53;
}
V_46 [ V_45 ] . V_7 = F_20 ( V_50 , 0 ) ;
V_46 [ V_45 ] . V_5 = F_21 ( V_48 , 64 ,
& V_54 , & V_46 [ V_45 ] ) ;
if ( ! V_46 [ V_45 ] . V_7 ) {
F_19 ( L_2 , V_52 ) ;
goto V_53;
}
if ( ! V_46 [ V_45 ] . V_5 ) {
F_19 ( L_3 , V_52 ) ;
goto V_53;
}
F_22 ( F_13 ) ;
F_9 ( V_46 [ V_45 ] . V_7 ) ;
F_23 ( L_4 ) ;
V_45 ++ ;
if ( F_24 ( V_50 ) != 0 ) {
if ( F_24 ( V_50 ) != 8 ) {
F_19 ( L_5 ,
V_52 ) ;
return - V_19 ;
}
for ( V_29 = 0 ; V_29 < 8 ; V_29 ++ ) {
V_22 = F_25 ( V_50 , V_29 ) ;
F_26 ( V_22 ) ;
}
F_23 ( L_6 ) ;
}
V_53:
return 0 ;
}

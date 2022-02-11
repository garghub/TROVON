static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_5 , V_6 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_7 , V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_8 , V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_3 ( V_2 ) ;
F_6 ( V_9 , 0x80 ) ;
}
static T_1 F_7 ( T_2 * V_10 , T_2 V_11 )
{
T_2 V_12 , V_13 , V_14 ;
T_2 V_15 [ V_16 * V_17 + 4 ] ;
T_2 V_18 = 0 ;
T_1 V_19 = 0xFFFFFFFF ;
V_15 [ V_18 ++ ] = 1 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ ) {
V_13 = ( V_10 [ V_12 ] & 0x80 ) ? 1 : 0 ;
V_14 = V_10 [ V_12 ] & 0x7f ;
if ( ( V_13 == 1 ) && ( V_14 >= 2 * V_20 + 1 ) ) {
goto V_21;
} else if ( ( V_14 >= V_22 ) &&
( V_14 <= V_20 ) ) {
V_15 [ V_18 ++ ] = V_13 ;
} else if ( ( V_14 > V_20 ) &&
( V_14 <= 2 * V_20 ) ) {
V_15 [ V_18 ++ ] = V_13 ;
V_15 [ V_18 ++ ] = V_13 ;
} else {
goto V_23;
}
if ( V_18 >= V_16 * V_17 )
goto V_21;
if ( ( V_18 == V_16 * V_17 - 1 )
&& ( V_15 [ V_18 - 1 ] == 0 ) ) {
V_15 [ V_18 ++ ] = 1 ;
goto V_21;
}
}
V_21:
if ( V_18 == ( V_16 * V_17 - 1 ) )
V_15 [ V_18 ++ ] = 1 ;
if ( V_18 == V_16 * V_17 ) {
V_19 = 0 ;
for ( V_12 = 0 ; V_12 < ( V_16 * V_17 ) ;
V_12 = V_12 + 2 ) {
if ( ( V_15 [ V_12 ] == 1 ) &&
( V_15 [ V_12 + 1 ] == 0 ) ) {
V_19 |= ( 1 << ( V_16 -
( V_12 / 2 ) - 1 ) ) ;
} else if ( ( V_15 [ V_12 ] == 0 ) &&
( V_15 [ V_12 + 1 ] == 1 ) ) {
} else {
V_19 = 0xFFFFFFFF ;
goto V_23;
}
}
}
V_23:
return V_19 ;
}
static void F_8 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_9 ( V_25 , struct V_1 , V_25 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_26 * V_26 = V_2 -> V_26 ;
T_1 V_27 , V_28 , V_29 , V_30 ;
T_2 V_12 , V_31 , V_32 , V_33 , V_34 , V_35 ;
V_27 = F_10 ( V_9 ) ;
if ( V_27 & V_36 ) {
V_31 = ( T_2 ) F_10 ( V_37 ) ;
if ( V_31 < 4 )
goto V_38;
V_32 = V_31 / 4 ;
if ( V_31 % 4 )
V_32 += 1 ;
for ( V_12 = 0 ; V_12 < V_32 ; V_12 ++ ) {
V_28 = F_10 ( V_39 + ( V_12 * 4 ) ) ;
V_2 -> V_40 [ V_12 * 4 + 0 ] = ( T_2 ) ( V_28 ) ;
V_2 -> V_40 [ V_12 * 4 + 1 ] = ( T_2 ) ( V_28 >> 8 ) ;
V_2 -> V_40 [ V_12 * 4 + 2 ] = ( T_2 ) ( V_28 >> 16 ) ;
V_2 -> V_40 [ V_12 * 4 + 3 ] = ( T_2 ) ( V_28 >> 24 ) ;
}
V_29 = F_7 ( V_2 -> V_40 , V_31 ) ;
if ( V_29 != 0xFFFFFFFF ) {
V_33 = V_29 & 0x3F ;
V_34 = ( V_29 & 0x7C0 ) >> 6 ;
V_35 = ( V_29 & 0x800 ) ? 1 : 0 ;
V_30 = V_34 << 8 | V_33 ;
F_11 ( V_26 , V_41 , V_30 , V_35 ) ;
}
}
V_38:
F_12 ( V_9 , 0x04 ) ;
F_1 ( V_2 ) ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_42 )
{
int V_43 = 0 ;
if ( V_42 & V_6 ) {
F_3 ( V_2 ) ;
F_4 ( V_2 ) ;
F_14 ( & V_2 -> V_25 ) ;
V_43 = 1 ;
}
return V_43 ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_44 , 0x00140070 ) ;
F_16 ( 20 ) ;
F_12 ( V_9 , 0x90 ) ;
F_1 ( V_2 ) ;
}
int F_17 ( struct V_3 * V_4 )
{
int V_45 ;
struct V_26 * V_26 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
V_26 = F_18 () ;
if ( ! V_26 )
return - V_46 ;
snprintf ( V_2 -> V_47 , sizeof( V_2 -> V_47 ) , L_1 ,
V_4 -> V_48 -> V_49 ) ;
snprintf ( V_2 -> V_50 , sizeof( V_2 -> V_50 ) , L_2 ,
F_19 ( V_4 -> V_51 ) ) ;
V_26 -> V_52 = L_3 ;
V_26 -> V_50 = V_2 -> V_50 ;
V_26 -> V_47 = V_2 -> V_47 ;
V_26 -> V_53 . V_54 = V_55 ;
V_26 -> V_53 . V_56 = 1 ;
V_26 -> V_53 . V_57 = V_4 -> V_51 -> V_58 ;
V_26 -> V_53 . V_59 = V_4 -> V_51 -> V_60 ;
V_26 -> V_4 . V_61 = & V_4 -> V_51 -> V_4 ;
V_26 -> V_62 = V_63 ;
V_26 -> V_64 = V_4 -> V_48 -> V_65 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_4 = V_4 ;
F_20 ( & V_2 -> V_25 , F_8 ) ;
F_3 ( V_2 ) ;
V_45 = F_21 ( V_26 ) ;
if ( V_45 )
goto V_66;
return 0 ;
V_66:
F_22 ( V_26 ) ;
return V_45 ;
}
void F_23 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_26 * V_26 = V_2 -> V_26 ;
F_5 ( V_2 ) ;
F_24 ( V_26 ) ;
V_2 -> V_26 = NULL ;
}

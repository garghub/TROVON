static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned char V_7 [ V_8 ] ;
int V_9 , V_10 , V_11 ;
int V_12 , V_13 , V_14 = 0 ;
int V_15 ;
V_15 = F_2 ( V_4 -> V_16 , V_17 , V_8 , V_7 ) ;
if ( V_15 < 0 )
goto V_18;
V_11 = V_7 [ 1 ] & ( 1 << 6 ) ;
V_9 = ( ( V_7 [ 0 ] & 0xFF ) << 4 ) | ( V_7 [ 1 ] & 0x0F ) ;
V_10 = ( ( V_7 [ 2 ] & 0xFF ) << 4 ) | ( V_7 [ 3 ] & 0x0F ) ;
V_12 = ( ( V_7 [ 4 ] & 0xFF ) << 4 ) | ( V_7 [ 5 ] & 0x0F ) ;
V_13 = ( ( V_7 [ 6 ] & 0xFF ) << 4 ) | ( V_7 [ 7 ] & 0x0F ) ;
if ( V_11 ) {
if ( ( V_9 != 0 ) && ( V_12 != 0 ) && ( V_4 -> V_19 != 0 ) ) {
V_14 = V_13 / V_12 - 1 ;
V_14 = ( V_14 * V_4 -> V_19 * V_9 ) >> V_20 ;
F_3 ( V_6 -> V_21 , L_1 ,
V_12 , V_13 , V_14 ) ;
}
F_4 ( V_4 -> V_22 , V_23 , V_9 ) ;
F_4 ( V_4 -> V_22 , V_24 , V_10 ) ;
F_4 ( V_4 -> V_22 , V_25 , V_14 ) ;
F_5 ( V_4 -> V_22 , V_26 , 1 ) ;
F_3 ( V_6 -> V_21 , L_2 , V_9 , V_10 ) ;
} else {
F_4 ( V_4 -> V_22 , V_25 , 0 ) ;
F_5 ( V_4 -> V_22 , V_26 , 0 ) ;
F_3 ( V_6 -> V_21 , L_3 ) ;
}
F_6 ( V_4 -> V_22 ) ;
V_18:
return V_27 ;
}
static int F_7 ( struct V_28 * V_21 )
{
struct V_3 * V_4 = F_8 ( V_21 ) ;
int V_2 , V_15 ;
V_2 = V_29 | V_30 | V_31
| V_32 | V_33 ;
V_15 = F_9 ( V_4 -> V_16 , V_34 , V_2 , V_2 ) ;
if ( V_15 < 0 )
goto V_18;
return 0 ;
V_18:
return V_15 ;
}
static void F_10 ( struct V_28 * V_21 )
{
struct V_3 * V_4 = F_8 ( V_21 ) ;
int V_2 ;
V_2 = V_29 | V_30 | V_31
| V_32 | V_33 ;
F_9 ( V_4 -> V_16 , V_34 , V_2 , 0 ) ;
}
static int T_2 F_11 ( struct V_35 * V_36 )
{
struct V_5 * V_6 = F_12 ( V_36 -> V_21 . V_37 ) ;
struct V_38 * V_39 = \
V_36 -> V_21 . V_37 -> V_40 ;
struct V_41 * V_42 = NULL ;
struct V_3 * V_4 ;
int V_1 , V_15 ;
V_1 = F_13 ( V_36 , 0 ) ;
if ( V_1 < 0 ) {
F_14 ( & V_36 -> V_21 , L_4 ) ;
return - V_43 ;
}
if ( ! V_39 ) {
F_14 ( & V_36 -> V_21 , L_5 ) ;
return - V_43 ;
}
V_42 = V_39 -> V_4 ;
if ( ! V_42 ) {
F_14 ( & V_36 -> V_21 , L_6 ) ;
return - V_43 ;
}
V_4 = F_15 ( sizeof( struct V_3 ) , V_44 ) ;
if ( V_4 == NULL )
return - V_45 ;
F_16 ( & V_36 -> V_21 , V_4 ) ;
V_4 -> V_22 = F_17 () ;
if ( V_4 -> V_22 == NULL ) {
F_14 ( & V_36 -> V_21 , L_7 ) ;
V_15 = - V_45 ;
goto V_18;
}
V_4 -> V_22 -> V_46 = L_8 ;
V_4 -> V_22 -> V_47 = L_9 ;
V_4 -> V_22 -> V_48 . V_49 = V_50 ;
V_4 -> V_22 -> V_21 . V_37 = & V_36 -> V_21 ;
V_4 -> V_22 -> V_51 = F_7 ;
V_4 -> V_22 -> V_52 = F_10 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_16 = ( V_6 -> V_48 == V_53 ) ? V_6 -> V_54 : V_6 -> V_55 ;
V_4 -> V_1 = V_1 + V_6 -> V_56 ;
V_4 -> V_19 = V_42 -> V_19 ;
F_18 ( V_4 -> V_22 , V_4 ) ;
V_15 = F_19 ( V_4 -> V_1 , NULL , F_1 ,
V_57 , L_10 , V_4 ) ;
if ( V_15 < 0 )
goto V_58;
F_20 ( V_59 , V_4 -> V_22 -> V_60 ) ;
F_20 ( V_23 , V_4 -> V_22 -> V_61 ) ;
F_20 ( V_24 , V_4 -> V_22 -> V_61 ) ;
F_20 ( V_25 , V_4 -> V_22 -> V_61 ) ;
F_20 ( V_62 , V_4 -> V_22 -> V_60 ) ;
F_20 ( V_63 , V_4 -> V_22 -> V_60 ) ;
F_20 ( V_26 , V_4 -> V_22 -> V_64 ) ;
F_21 ( V_4 -> V_22 , V_23 , 0 , 1 << V_20 , 0 , 0 ) ;
F_21 ( V_4 -> V_22 , V_24 , 0 , 1 << V_20 , 0 , 0 ) ;
F_21 ( V_4 -> V_22 , V_25 , 0 , 1 << V_20 ,
0 , 0 ) ;
V_15 = F_22 ( V_4 -> V_22 ) ;
if ( V_15 < 0 ) {
F_14 ( V_6 -> V_21 , L_11 ) ;
goto V_65;
}
F_23 ( V_36 , V_4 ) ;
return 0 ;
V_65:
F_24 ( V_4 -> V_1 , V_4 ) ;
V_58:
F_25 ( V_4 -> V_22 ) ;
V_18:
F_26 ( V_4 ) ;
return V_15 ;
}
static int T_3 F_27 ( struct V_35 * V_36 )
{
struct V_3 * V_4 = F_28 ( V_36 ) ;
F_29 ( V_4 -> V_22 ) ;
F_24 ( V_4 -> V_1 , V_4 ) ;
F_23 ( V_36 , NULL ) ;
F_26 ( V_4 ) ;
return 0 ;
}

static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_5 = V_4 -> V_6 ;
unsigned char V_7 [ F_2 ( V_4 -> V_7 ) ] ;
unsigned int V_8 , V_9 , V_10 , V_11 ;
T_2 * V_12 = ( T_2 * ) V_7 ;
F_3 ( V_13 ,
V_4 -> V_14 + V_15 ) ;
* V_12 = F_4 ( V_4 -> V_14 + V_16 ) ;
* ( V_12 + 1 ) = F_4 ( V_4 -> V_14
+ V_17 ) ;
for ( V_9 = 0 ; V_9 < V_4 -> V_18 ; V_9 ++ ) {
V_11 = V_7 [ V_9 ] ^ V_4 -> V_7 [ V_9 ] ;
if ( ! V_11 )
continue;
for ( V_8 = 0 ; V_8 < V_4 -> V_19 ; V_8 ++ ) {
if ( V_11 & ( 1 << V_8 ) ) {
V_10 = F_5 ( V_9 , V_8 ,
V_4 -> V_20 ) ;
F_6 ( V_5 , V_21 , V_22 , V_10 ) ;
F_7 ( V_5 ,
V_4 -> V_23 [ V_10 ] ,
V_7 [ V_9 ] & ( 1 << V_8 ) ) ;
}
}
}
F_8 ( V_5 ) ;
memcpy ( V_4 -> V_7 , V_7 ,
sizeof( V_4 -> V_7 ) ) ;
F_3 ( F_4 ( V_4 -> V_14 + V_24 ) ,
V_4 -> V_14 + V_24 ) ;
F_3 ( V_25 | V_26 ,
V_4 -> V_14 + V_15 ) ;
return V_27 ;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_10 ( V_6 ) ;
F_11 ( V_6 -> V_28 . V_29 ) ;
F_12 ( V_4 -> V_1 ) ;
F_3 ( V_30 ,
V_4 -> V_14 + V_31 ) ;
F_3 ( V_32 ,
V_4 -> V_14 + V_33 ) ;
F_3 ( V_13 ,
V_4 -> V_14 + V_24 ) ;
F_3 ( V_25 | V_26 ,
V_4 -> V_14 + V_15 ) ;
F_3 ( V_34 | V_35 ,
V_4 -> V_14 + V_36 ) ;
F_13 ( V_4 -> V_1 ) ;
return 0 ;
}
static void F_14 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_10 ( V_6 ) ;
F_12 ( V_4 -> V_1 ) ;
F_3 ( V_13 ,
V_4 -> V_14 + V_15 ) ;
F_3 ( F_4 ( V_4 -> V_14 + V_24 ) ,
V_4 -> V_14 + V_24 ) ;
F_13 ( V_4 -> V_1 ) ;
F_15 ( V_6 -> V_28 . V_29 ) ;
}
static int T_3 F_16 ( struct V_37 * V_38 )
{
const struct V_39 * V_40 ;
struct V_3 * V_4 ;
struct V_5 * V_5 ;
struct V_41 * V_42 ;
T_4 V_43 ;
unsigned int V_20 , V_44 ;
int V_1 ;
int error ;
V_40 = V_38 -> V_28 . V_45 ;
if ( ! V_40 ) {
F_17 ( & V_38 -> V_28 , L_1 ) ;
return - V_46 ;
}
V_42 = F_18 ( V_38 , V_47 , 0 ) ;
if ( ! V_42 ) {
F_17 ( & V_38 -> V_28 , L_2 ) ;
return - V_46 ;
}
V_1 = F_19 ( V_38 , 0 ) ;
if ( ! V_1 ) {
F_17 ( & V_38 -> V_28 , L_3 ) ;
return - V_46 ;
}
if ( ! V_40 -> V_48 ) {
F_17 ( & V_38 -> V_28 , L_4 ) ;
return - V_46 ;
}
V_20 = F_20 ( V_40 -> V_19 ) ;
V_44 = V_40 -> V_18 << V_20 ;
V_4 = F_21 ( sizeof( struct V_3 ) +
V_44 * sizeof( V_4 -> V_23 [ 0 ] ) ,
V_49 ) ;
if ( ! V_4 ) {
F_17 ( & V_38 -> V_28 , L_5 ) ;
return - V_50 ;
}
V_43 = F_22 ( V_42 ) ;
V_42 = F_23 ( V_42 -> V_51 , V_43 , V_38 -> V_52 ) ;
if ( ! V_42 ) {
F_17 ( & V_38 -> V_28 , L_6 ) ;
error = - V_53 ;
goto V_54;
}
V_4 -> V_14 = F_24 ( V_42 -> V_51 , F_22 ( V_42 ) ) ;
if ( ! V_4 -> V_14 ) {
F_17 ( & V_38 -> V_28 , L_7 ) ;
error = - V_50 ;
goto V_55;
}
V_4 -> V_1 = V_1 ;
V_4 -> V_20 = V_20 ;
V_4 -> V_18 = V_40 -> V_18 ;
V_4 -> V_19 = V_40 -> V_19 ;
V_4 -> V_6 = V_5 = F_25 () ;
if ( ! V_5 ) {
error = - V_50 ;
goto V_56;
}
V_5 -> V_52 = V_38 -> V_52 ;
V_5 -> V_28 . V_29 = & V_38 -> V_28 ;
V_5 -> V_57 . V_58 = V_59 ;
V_5 -> V_57 . V_60 = 0x0001 ;
V_5 -> V_57 . V_61 = 0x0001 ;
V_5 -> V_57 . V_62 = 0x0001 ;
V_5 -> V_63 = F_9 ;
V_5 -> V_64 = F_14 ;
V_5 -> V_65 = V_4 -> V_23 ;
V_5 -> V_66 = sizeof( V_4 -> V_23 [ 0 ] ) ;
V_5 -> V_67 = V_44 ;
F_26 ( V_68 , V_5 -> V_69 ) ;
F_26 ( V_70 , V_5 -> V_69 ) ;
F_27 ( V_5 , V_21 , V_22 ) ;
F_28 ( V_5 , V_4 ) ;
F_29 ( V_40 -> V_48 , V_20 ,
V_5 -> V_65 , V_5 -> V_71 ) ;
error = F_30 ( V_4 -> V_1 , F_1 ,
V_72 ,
L_8 , V_4 ) ;
if ( error ) {
F_17 ( & V_38 -> V_28 , L_9 ) ;
goto V_73;
}
F_31 ( & V_38 -> V_28 ) ;
error = F_32 ( V_4 -> V_6 ) ;
if ( error < 0 ) {
F_17 ( & V_38 -> V_28 , L_10 ) ;
goto V_74;
}
F_33 ( V_38 , V_4 ) ;
return 0 ;
V_74:
F_34 ( & V_38 -> V_28 ) ;
F_35 ( V_4 -> V_1 , V_4 ) ;
V_73:
F_36 ( V_5 ) ;
V_56:
F_37 ( V_4 -> V_14 ) ;
V_55:
F_38 ( V_42 -> V_51 , V_43 ) ;
V_54:
F_39 ( V_4 ) ;
return error ;
}
static int T_5 F_40 ( struct V_37 * V_38 )
{
struct V_3 * V_4 = F_41 ( V_38 ) ;
struct V_41 * V_42 ;
F_35 ( V_4 -> V_1 , V_4 ) ;
F_34 ( & V_38 -> V_28 ) ;
F_42 ( V_4 -> V_6 ) ;
F_37 ( V_4 -> V_14 ) ;
V_42 = F_18 ( V_38 , V_47 , 0 ) ;
F_38 ( V_42 -> V_51 , F_22 ( V_42 ) ) ;
F_39 ( V_4 ) ;
F_33 ( V_38 , NULL ) ;
return 0 ;
}

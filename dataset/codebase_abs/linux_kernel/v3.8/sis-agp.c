static int F_1 ( void )
{
T_1 V_1 ;
int V_2 ;
struct V_3 * V_4 ;
F_2 ( V_5 -> V_6 , V_7 , & V_1 ) ;
V_4 = F_3 ( V_5 -> V_8 -> V_9 ) ;
for ( V_2 = 0 ; V_2 < V_5 -> V_8 -> V_10 ; V_2 ++ ) {
if ( ( V_1 == V_4 [ V_2 ] . V_11 ) ||
( ( V_1 & ~ ( 0x07 ) ) ==
( V_4 [ V_2 ] . V_11 & ~ ( 0x07 ) ) ) ) {
V_5 -> V_12 =
V_5 -> V_13 = ( void * ) ( V_4 + V_2 ) ;
V_5 -> V_14 = V_2 ;
return V_4 [ V_2 ] . V_15 ;
}
}
return 0 ;
}
static void F_4 ( struct V_16 * V_17 )
{
F_5 ( V_5 -> V_6 , V_18 , 0x02 ) ;
}
static int F_6 ( void )
{
T_2 V_19 ;
struct V_3 * V_13 ;
V_13 = F_3 ( V_5 -> V_13 ) ;
F_5 ( V_5 -> V_6 , V_20 , 0x05 ) ;
F_7 ( V_5 -> V_6 , V_21 , & V_19 ) ;
V_5 -> V_22 = ( V_19 & V_23 ) ;
F_8 ( V_5 -> V_6 , V_24 ,
V_5 -> V_25 ) ;
F_5 ( V_5 -> V_6 , V_7 ,
V_13 -> V_11 ) ;
return 0 ;
}
static void F_9 ( void )
{
struct V_3 * V_12 ;
V_12 = F_3 ( V_5 -> V_12 ) ;
F_5 ( V_5 -> V_6 , V_7 ,
( V_12 -> V_11 & ~ ( 0x03 ) ) ) ;
}
static void F_10 ( struct V_26 * V_27 , T_2 V_28 )
{
struct V_29 * V_30 = NULL ;
T_2 V_31 ;
int V_32 ;
F_11 ( & V_5 -> V_6 -> V_6 , L_1 ,
V_5 -> V_33 , V_5 -> V_34 ) ;
F_7 ( V_5 -> V_6 , V_5 -> V_35 + V_36 , & V_31 ) ;
V_31 = F_12 ( V_27 , V_28 , V_31 ) ;
V_31 |= V_37 ;
V_32 = ( V_31 & 0x7 ) << 2 ;
F_13 (device) {
T_1 V_38 = F_14 ( V_30 , V_39 ) ;
if ( ! V_38 )
continue;
F_11 ( & V_5 -> V_6 -> V_6 , L_2 ,
F_15 ( V_30 ) , V_32 ) ;
F_8 ( V_30 , V_38 + V_40 , V_31 ) ;
if ( V_30 -> V_30 == V_27 -> V_6 -> V_30 ) {
F_11 ( & V_5 -> V_6 -> V_6 , L_3 ) ;
F_16 ( 10 ) ;
}
}
}
static void F_17 ( struct V_26 * V_27 )
{
int V_2 ;
for ( V_2 = 0 ; V_41 [ V_2 ] != 0 ; ++ V_2 )
if ( V_27 -> V_6 -> V_30 == V_41 [ V_2 ] )
break;
if ( V_41 [ V_2 ] || V_42 )
V_43 . V_44 = F_10 ;
if ( ( V_5 -> V_33 == 3 && V_5 -> V_34 >= 5
&& V_45 != 0 ) || V_45 == 1 ) {
V_43 . V_9 = V_46 ;
V_43 . V_47 = V_48 ;
V_43 . V_10 = V_49 ;
V_43 . V_50 = V_51 ;
V_43 . V_52 = V_53 ;
V_43 . V_54 = V_55 ;
V_43 . V_56 = V_57 ;
}
}
static int F_18 ( struct V_29 * V_58 , const struct V_59 * V_60 )
{
struct V_26 * V_27 ;
T_1 V_61 ;
V_61 = F_14 ( V_58 , V_39 ) ;
if ( ! V_61 )
return - V_62 ;
F_11 ( & V_58 -> V_6 , L_4 ,
V_58 -> V_63 , V_58 -> V_30 ) ;
V_27 = F_19 () ;
if ( ! V_27 )
return - V_64 ;
V_27 -> V_8 = & V_43 ;
V_27 -> V_6 = V_58 ;
V_27 -> V_35 = V_61 ;
F_20 ( V_27 ) ;
F_7 ( V_58 , V_27 -> V_35 + V_36 , & V_27 -> V_28 ) ;
F_17 ( V_27 ) ;
F_21 ( V_58 , V_27 ) ;
return F_22 ( V_27 ) ;
}
static void F_23 ( struct V_29 * V_58 )
{
struct V_26 * V_27 = F_24 ( V_58 ) ;
F_25 ( V_27 ) ;
F_26 ( V_27 ) ;
}
static int F_27 ( struct V_29 * V_58 , T_3 V_65 )
{
F_28 ( V_58 ) ;
F_29 ( V_58 , F_30 ( V_58 , V_65 ) ) ;
return 0 ;
}
static int F_31 ( struct V_29 * V_58 )
{
F_29 ( V_58 , V_66 ) ;
F_32 ( V_58 ) ;
return V_43 . V_50 () ;
}
static int T_4 F_33 ( void )
{
if ( V_67 )
return - V_68 ;
return F_34 ( & V_69 ) ;
}
static void T_5 F_35 ( void )
{
F_36 ( & V_69 ) ;
}

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
struct V_3 * V_13 ;
V_13 = F_3 ( V_5 -> V_13 ) ;
F_5 ( V_5 -> V_6 , V_19 , 0x05 ) ;
V_5 -> V_20 = F_7 ( V_5 -> V_6 ,
V_21 ) ;
F_8 ( V_5 -> V_6 , V_22 ,
V_5 -> V_23 ) ;
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
static void F_10 ( struct V_24 * V_25 , T_2 V_26 )
{
struct V_27 * V_28 = NULL ;
T_2 V_29 ;
int V_30 ;
F_11 ( & V_5 -> V_6 -> V_6 , L_1 ,
V_5 -> V_31 , V_5 -> V_32 ) ;
F_12 ( V_5 -> V_6 , V_5 -> V_33 + V_34 , & V_29 ) ;
V_29 = F_13 ( V_25 , V_26 , V_29 ) ;
V_29 |= V_35 ;
V_30 = ( V_29 & 0x7 ) << 2 ;
F_14 (device) {
T_1 V_36 = F_15 ( V_28 , V_37 ) ;
if ( ! V_36 )
continue;
F_11 ( & V_5 -> V_6 -> V_6 , L_2 ,
F_16 ( V_28 ) , V_30 ) ;
F_8 ( V_28 , V_36 + V_38 , V_29 ) ;
if ( V_28 -> V_28 == V_25 -> V_6 -> V_28 ) {
F_11 ( & V_5 -> V_6 -> V_6 , L_3 ) ;
F_17 ( 10 ) ;
}
}
}
static void F_18 ( struct V_24 * V_25 )
{
int V_2 ;
for ( V_2 = 0 ; V_39 [ V_2 ] != 0 ; ++ V_2 )
if ( V_25 -> V_6 -> V_28 == V_39 [ V_2 ] )
break;
if ( V_39 [ V_2 ] || V_40 )
V_41 . V_42 = F_10 ;
if ( ( V_5 -> V_31 == 3 && V_5 -> V_32 >= 5
&& V_43 != 0 ) || V_43 == 1 ) {
V_41 . V_9 = V_44 ;
V_41 . V_45 = V_46 ;
V_41 . V_10 = V_47 ;
V_41 . V_48 = V_49 ;
V_41 . V_50 = V_51 ;
V_41 . V_52 = V_53 ;
V_41 . V_54 = V_55 ;
}
}
static int F_19 ( struct V_27 * V_56 , const struct V_57 * V_58 )
{
struct V_24 * V_25 ;
T_1 V_59 ;
V_59 = F_15 ( V_56 , V_37 ) ;
if ( ! V_59 )
return - V_60 ;
F_11 ( & V_56 -> V_6 , L_4 ,
V_56 -> V_61 , V_56 -> V_28 ) ;
V_25 = F_20 () ;
if ( ! V_25 )
return - V_62 ;
V_25 -> V_8 = & V_41 ;
V_25 -> V_6 = V_56 ;
V_25 -> V_33 = V_59 ;
F_21 ( V_25 ) ;
F_12 ( V_56 , V_25 -> V_33 + V_34 , & V_25 -> V_26 ) ;
F_18 ( V_25 ) ;
F_22 ( V_56 , V_25 ) ;
return F_23 ( V_25 ) ;
}
static void F_24 ( struct V_27 * V_56 )
{
struct V_24 * V_25 = F_25 ( V_56 ) ;
F_26 ( V_25 ) ;
F_27 ( V_25 ) ;
}
static int F_28 ( struct V_27 * V_56 , T_3 V_63 )
{
F_29 ( V_56 ) ;
F_30 ( V_56 , F_31 ( V_56 , V_63 ) ) ;
return 0 ;
}
static int F_32 ( struct V_27 * V_56 )
{
F_30 ( V_56 , V_64 ) ;
F_33 ( V_56 ) ;
return V_41 . V_48 () ;
}
static int T_4 F_34 ( void )
{
if ( V_65 )
return - V_66 ;
return F_35 ( & V_67 ) ;
}
static void T_5 F_36 ( void )
{
F_37 ( & V_67 ) ;
}

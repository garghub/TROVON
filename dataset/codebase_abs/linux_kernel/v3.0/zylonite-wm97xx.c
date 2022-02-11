static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( 1 ) ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ )
V_4 ;
}
static int F_3 ( struct V_1 * V_2 )
{
T_1 V_5 , V_6 , V_7 = 0x100 | V_8 ;
int V_9 = 0 ;
static T_1 V_10 , V_11 ;
F_2 ( 1 ) ;
if ( V_11 > 5 ) {
V_11 = 0 ;
return V_12 ;
}
V_5 = V_4 ;
if ( V_5 == V_10 ) {
V_11 ++ ;
return V_13 ;
}
V_10 = V_5 ;
do {
if ( V_9 )
V_5 = V_4 ;
V_6 = V_4 ;
if ( V_14 )
V_7 = V_4 ;
F_4 ( V_2 -> V_15 , L_1 ,
V_5 , V_6 , V_7 ) ;
if ( ( V_5 & V_16 ) != V_17 ||
( V_6 & V_16 ) != V_18 ||
( V_7 & V_16 ) != V_8 )
goto V_19;
V_11 = 0 ;
F_5 ( V_2 -> V_20 , V_21 , V_5 & 0xfff ) ;
F_5 ( V_2 -> V_20 , V_22 , V_6 & 0xfff ) ;
F_5 ( V_2 -> V_20 , V_23 , V_7 & 0xfff ) ;
F_6 ( V_2 -> V_20 , V_24 , ( V_7 != 0 ) ) ;
F_7 ( V_2 -> V_20 ) ;
V_9 ++ ;
} while ( V_9 < V_25 [ V_26 ] . V_9 );
V_19:
return V_27 | V_13 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_28 ;
if ( V_2 -> V_29 == NULL )
return - V_30 ;
for ( V_28 = 0 ; V_28 < F_9 ( V_25 ) ; V_28 ++ ) {
if ( V_2 -> V_31 != V_25 [ V_28 ] . V_31 )
continue;
V_26 = V_28 ;
if ( V_32 <= V_25 [ V_28 ] . V_33 )
break;
}
V_2 -> V_34 = V_25 [ V_26 ] . V_35 ;
V_2 -> V_36 = V_37 ;
F_10 ( V_2 -> V_15 ,
L_2 ,
V_25 [ V_26 ] . V_33 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 , int V_38 )
{
if ( V_38 )
F_12 ( V_2 -> V_39 ) ;
else
F_13 ( V_2 -> V_39 ) ;
}
static int F_14 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_15 ( V_41 ) ;
int V_42 ;
if ( F_16 () )
V_42 = F_17 ( V_43 ) ;
else
V_42 = F_17 ( V_44 ) ;
V_2 -> V_39 = F_18 ( V_42 ) ;
F_19 ( F_18 ( V_42 ) , V_45 ) ;
F_20 ( V_2 , V_46 , V_47 ,
V_48 ,
V_49 ,
V_50 ) ;
F_20 ( V_2 , V_51 , V_52 ,
V_48 ,
V_53 ,
V_54 ) ;
return F_21 ( V_2 , & V_55 ) ;
}
static int F_22 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_15 ( V_41 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static int T_2 F_24 ( void )
{
return F_25 ( & V_56 ) ;
}
static void T_3 F_26 ( void )
{
F_27 ( & V_56 ) ;
}

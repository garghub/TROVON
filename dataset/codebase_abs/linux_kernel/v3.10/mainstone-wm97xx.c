static void F_1 ( struct V_1 * V_2 )
{
F_2 ( 1 ) ;
while ( V_3 & ( 1 << 2 ) )
V_4 ;
}
static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_5 ;
F_2 ( 1 ) ;
for ( V_5 = 0 ; V_5 < 16 ; V_5 ++ )
V_4 ;
}
static int F_3 ( struct V_1 * V_2 )
{
T_1 V_6 , V_7 , V_8 = 0x100 | V_9 ;
int V_10 = 0 ;
F_2 ( 1 ) ;
if ( V_11 > 5 ) {
V_11 = 0 ;
return V_12 ;
}
V_6 = V_4 ;
if ( V_6 == V_13 ) {
V_11 ++ ;
return V_14 ;
}
V_13 = V_6 ;
do {
if ( V_10 )
V_6 = V_4 ;
V_7 = V_4 ;
if ( V_15 )
V_8 = V_4 ;
F_4 ( V_2 -> V_16 , L_1 ,
V_6 , V_7 , V_8 ) ;
if ( ( V_6 & V_17 ) != V_18 ||
( V_7 & V_17 ) != V_19 ||
( V_8 & V_17 ) != V_9 )
goto V_20;
V_11 = 0 ;
F_5 ( V_2 -> V_21 , V_22 , V_6 & 0xfff ) ;
F_5 ( V_2 -> V_21 , V_23 , V_7 & 0xfff ) ;
F_5 ( V_2 -> V_21 , V_24 , V_8 & 0xfff ) ;
F_6 ( V_2 -> V_21 , V_25 , ( V_8 != 0 ) ) ;
F_7 ( V_2 -> V_21 ) ;
V_10 ++ ;
} while ( V_10 < V_26 [ V_27 ] . V_10 );
V_20:
return V_28 | V_14 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_29 = 0 , V_30 = 0 ;
if ( V_2 -> V_31 == NULL )
return - V_32 ;
for ( V_29 = 0 ; V_29 < F_9 ( V_26 ) ; V_29 ++ ) {
if ( V_2 -> V_33 != V_26 [ V_29 ] . V_33 )
continue;
V_27 = V_29 ;
if ( V_34 <= V_26 [ V_29 ] . V_35 )
break;
}
V_2 -> V_36 = V_26 [ V_27 ] . V_37 ;
V_2 -> V_38 = V_39 ;
F_10 ( V_2 -> V_16 ,
L_2 ,
V_26 [ V_27 ] . V_35 ) ;
if ( F_11 () || F_12 () || F_13 () ) {
V_40 = 1 ;
V_41 = 27 ;
V_2 -> V_42 = V_43 ;
} else if ( F_14 () && V_40 )
V_41 = 4 ;
if ( V_41 ) {
V_30 = F_15 ( V_41 , L_3 ) ;
if ( V_30 )
goto V_44;
V_30 = F_16 ( V_41 ) ;
if ( V_30 ) {
F_17 ( V_41 ) ;
goto V_44;
}
V_2 -> V_45 = F_18 ( V_41 ) ;
F_19 ( V_2 -> V_45 , V_46 ) ;
} else
V_40 = 0 ;
if ( V_40 ) {
switch ( V_2 -> V_33 ) {
case V_47 :
break;
case V_48 :
case V_49 :
F_20 ( V_2 , V_50 , V_51 ,
V_52 ,
V_53 ,
V_54 ) ;
F_20 ( V_2 , V_55 , V_56 ,
V_52 ,
V_57 ,
V_58 ) ;
break;
default:
F_21 ( V_2 -> V_16 ,
L_4 ) ;
V_40 = 0 ;
break;
}
}
V_44:
return V_30 ;
}
static void F_22 ( struct V_1 * V_2 )
{
if ( V_40 ) {
if ( V_41 )
F_17 ( V_41 ) ;
V_2 -> V_45 = 0 ;
}
}
static void F_23 ( struct V_1 * V_2 , int V_59 )
{
if ( V_59 )
F_24 ( V_2 -> V_45 ) ;
else
F_25 ( V_2 -> V_45 ) ;
}
static int F_26 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_27 ( V_61 ) ;
return F_28 ( V_2 , & V_62 ) ;
}
static int F_29 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_27 ( V_61 ) ;
F_30 ( V_2 ) ;
return 0 ;
}

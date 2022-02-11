static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 , V_6 , sizeof( V_4 -> V_5 ) ) ;
F_2 ( V_4 -> V_7 , V_8 ,
sizeof( V_4 -> V_7 ) ) ;
F_2 ( V_4 -> V_9 , L_1 , sizeof( V_4 -> V_9 ) ) ;
F_2 ( V_4 -> V_10 , F_3 ( V_2 -> V_11 . V_12 -> V_12 ) ,
sizeof( V_4 -> V_10 ) ) ;
}
static int
F_4 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_15 V_16 = { 0 } ;
int V_17 = 0 ;
struct V_18 * V_19 = F_5 ( V_2 ) ;
V_17 = F_6 ( V_19 -> V_20 , 0 , V_19 -> V_21 , & V_16 ) ;
if ( V_17 ) {
F_7 ( V_2 , L_2 , V_17 ) ;
goto V_22;
}
if ( V_16 . V_23 & V_24 )
V_14 -> V_25 . V_26 = V_27 ;
if ( ! ( V_16 . V_23 & V_28 ) )
V_14 -> V_25 . V_29 = V_30 ;
V_14 -> V_25 . V_31 = V_16 . V_32 ;
V_22:
return V_17 ;
}
static int
F_8 ( struct V_1 * V_2 ,
const struct V_13 * V_14 )
{
struct V_33 V_34 = { 0 } ;
struct V_18 * V_19 = F_5 ( V_2 ) ;
int V_17 = 0 ;
F_9 ( V_2 , L_3 ) ;
if ( F_10 ( V_2 ) ) {
F_11 ( V_2 , L_4 ) ;
return - V_35 ;
}
V_34 . V_32 = V_14 -> V_25 . V_31 ;
if ( V_14 -> V_25 . V_26 == V_27 )
V_34 . V_23 |= V_24 ;
else
V_34 . V_23 &= ~ V_24 ;
if ( V_14 -> V_25 . V_29 == V_36 )
V_34 . V_23 |= V_28 ;
else
V_34 . V_23 &= ~ V_28 ;
V_17 = F_12 ( V_19 -> V_20 , 0 , V_19 -> V_21 , & V_34 ) ;
if ( V_17 )
F_9 ( V_2 , L_5 , V_17 ) ;
return V_17 ;
}
static void F_13 ( struct V_1 * V_37 , T_1 V_38 ,
T_2 * V_39 )
{
T_2 * V_40 = V_39 ;
int V_41 ;
switch ( V_38 ) {
case V_42 :
for ( V_41 = 0 ; V_41 < V_43 ; V_41 ++ ) {
F_2 ( V_40 , V_44 [ V_41 ] , V_45 ) ;
V_40 += V_45 ;
}
for ( V_41 = 0 ; V_41 < V_46 ; V_41 ++ ) {
F_2 ( V_40 , V_47 [ V_41 ] , V_45 ) ;
V_40 += V_45 ;
}
break;
}
}
static int F_14 ( struct V_1 * V_2 , int V_48 )
{
switch ( V_48 ) {
case V_42 :
return V_43 + V_46 ;
default:
return - V_49 ;
}
}
static void F_15 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
T_3 * V_39 )
{
int V_41 = 0 ;
int V_52 , V_53 , V_17 ;
int V_54 ;
union V_55 V_56 ;
T_3 V_57 = 0 ;
T_3 V_58 = 0 , V_59 = 0 ;
struct V_18 * V_19 = F_5 ( V_2 ) ;
struct V_60 * V_61 ;
struct V_62 * V_63 ;
memset ( V_39 , 0 ,
sizeof( T_3 ) * ( V_43 + V_46 ) ) ;
for ( V_52 = 0 ; V_52 <= 2 ; V_52 ++ ) {
V_17 = F_16 ( V_19 -> V_20 , 0 , V_19 -> V_21 ,
V_52 , & V_56 ) ;
if ( V_17 != 0 )
F_17 ( V_2 , L_6 , V_52 ) ;
switch ( V_52 ) {
case 0 :
V_54 = sizeof( V_56 . V_64 ) / sizeof( T_3 ) ;
break;
case 1 :
V_54 = sizeof( V_56 . V_65 ) / sizeof( T_3 ) ;
break;
case 2 :
V_54 = sizeof( V_56 . V_66 ) / sizeof( T_3 ) ;
break;
}
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ )
* ( V_39 + V_41 ++ ) = V_56 . V_67 . V_68 [ V_53 ] ;
}
F_18 (k) {
V_61 = F_19 ( V_19 -> V_69 , V_53 ) ;
for ( V_52 = 0 ; V_52 < sizeof( * V_61 ) / sizeof( V_70 ) ; V_52 ++ )
* ( ( V_70 * ) V_39 + V_41 + V_52 ) += * ( ( V_70 * ) V_61 + V_52 ) ;
}
V_41 += V_52 ;
for ( V_52 = 0 ; V_52 < V_19 -> V_71 ; V_52 ++ ) {
V_63 = & V_19 -> V_72 [ V_52 ] -> V_51 ;
V_57 += V_63 -> V_57 ;
V_58 += V_63 -> V_73 ;
V_59 += V_63 -> V_59 ;
}
* ( V_39 + V_41 ++ ) = V_58 ;
* ( V_39 + V_41 ++ ) = V_59 ;
* ( V_39 + V_41 ++ ) = V_57 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_74 * V_75 , T_1 * V_76 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
switch ( V_75 -> V_77 ) {
case V_78 :
V_75 -> V_39 = V_19 -> V_79 ;
break;
case V_80 :
V_75 -> V_39 = F_21 ( V_19 ) ;
break;
default:
return - V_49 ;
}
return 0 ;
}

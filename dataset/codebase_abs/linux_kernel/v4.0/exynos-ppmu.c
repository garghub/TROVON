static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( ! strcmp ( V_2 -> V_5 -> V_6 , V_4 [ V_3 ] . V_6 ) )
return V_4 [ V_3 ] . V_7 ;
return - V_8 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_11 ;
F_5 ( V_12 |
V_13 |
V_14 |
V_15 |
V_16 ,
V_10 -> V_17 . V_18 + V_19 ) ;
V_11 = F_6 ( V_10 -> V_17 . V_18 + V_20 ) ;
V_11 &= ~ V_21 ;
F_5 ( V_11 , V_10 -> V_17 . V_18 + V_20 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_7 = F_1 ( V_2 ) ;
T_1 V_11 , V_22 ;
if ( V_7 < 0 )
return V_7 ;
V_22 = F_6 ( V_10 -> V_17 . V_18 + V_23 ) ;
V_22 |= ( V_12 | ( V_24 << V_7 ) ) ;
F_5 ( V_22 , V_10 -> V_17 . V_18 + V_23 ) ;
F_5 ( V_25 | V_26 ,
V_10 -> V_17 . V_18 + F_8 ( V_7 ) ) ;
V_11 = F_6 ( V_10 -> V_17 . V_18 + V_20 ) ;
V_11 &= ~ ( V_21
| V_27
| V_28 ) ;
V_11 |= ( V_24 << V_29 ) ;
V_11 |= ( V_24 << V_30 ) ;
V_11 |= ( V_24 << V_31 ) ;
F_5 ( V_11 , V_10 -> V_17 . V_18 + V_20 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_7 = F_1 ( V_2 ) ;
T_1 V_11 , V_34 ;
if ( V_7 < 0 )
return - V_8 ;
V_11 = F_6 ( V_10 -> V_17 . V_18 + V_20 ) ;
V_11 &= ~ V_21 ;
F_5 ( V_11 , V_10 -> V_17 . V_18 + V_20 ) ;
V_33 -> V_35 = F_6 ( V_10 -> V_17 . V_18 + V_36 ) ;
switch ( V_7 ) {
case V_37 :
case V_38 :
case V_39 :
V_33 -> V_40
= F_6 ( V_10 -> V_17 . V_18 + F_10 ( V_7 ) ) ;
break;
case V_41 :
V_33 -> V_40 =
( ( F_6 ( V_10 -> V_17 . V_18 + V_42 ) << 8 )
| F_6 ( V_10 -> V_17 . V_18 + V_43 ) ) ;
break;
default:
return - V_8 ;
}
V_34 = F_6 ( V_10 -> V_17 . V_18 + V_19 ) ;
V_34 |= ( V_12 | ( V_24 << V_7 ) ) ;
F_5 ( V_34 , V_10 -> V_17 . V_18 + V_19 ) ;
F_11 ( & V_2 -> V_44 , L_1 , V_2 -> V_5 -> V_6 ,
V_33 -> V_40 , V_33 -> V_35 ) ;
return 0 ;
}
static int F_12 ( struct V_45 * V_46 ,
struct V_9 * V_10 )
{
struct V_47 * V_5 ;
struct V_48 * V_44 = V_10 -> V_44 ;
struct V_45 * V_49 , * V_50 ;
int V_3 , V_51 , V_52 ;
V_49 = F_13 ( V_46 , L_2 ) ;
if ( ! V_49 ) {
F_14 ( V_44 ,
L_3 ) ;
return - V_8 ;
}
V_52 = F_15 ( V_49 ) ;
V_5 = F_16 ( V_44 , sizeof( * V_5 ) * V_52 , V_53 ) ;
if ( ! V_5 )
return - V_54 ;
V_10 -> V_55 = V_52 ;
V_51 = 0 ;
F_17 (events_np, node) {
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( ! V_4 [ V_3 ] . V_6 )
continue;
if ( ! F_18 ( V_50 -> V_6 , V_4 [ V_3 ] . V_6 ) )
break;
}
if ( V_3 == F_2 ( V_4 ) ) {
F_19 ( V_44 ,
L_4 ,
V_50 -> V_6 ) ;
continue;
}
V_5 [ V_51 ] . V_56 = & V_57 ;
V_5 [ V_51 ] . V_58 = V_10 ;
F_20 ( V_50 , L_5 , & V_5 [ V_51 ] . V_6 ) ;
V_51 ++ ;
F_21 ( V_50 ) ;
}
V_10 -> V_5 = V_5 ;
F_21 ( V_49 ) ;
return 0 ;
}
static int F_22 ( struct V_9 * V_10 )
{
struct V_48 * V_44 = V_10 -> V_44 ;
struct V_45 * V_46 = V_44 -> V_59 ;
int V_60 = 0 ;
if ( ! V_46 ) {
F_14 ( V_44 , L_6 ) ;
return - V_8 ;
}
V_10 -> V_17 . V_18 = F_23 ( V_46 , 0 ) ;
if ( F_24 ( V_10 -> V_17 . V_18 ) ) {
F_14 ( V_44 , L_7 ) ;
return - V_54 ;
}
V_10 -> V_17 . V_61 = F_25 ( V_44 , L_8 ) ;
if ( F_26 ( V_10 -> V_17 . V_61 ) ) {
V_10 -> V_17 . V_61 = NULL ;
F_19 ( V_44 , L_9 ) ;
}
V_60 = F_12 ( V_46 , V_10 ) ;
if ( V_60 < 0 ) {
F_14 ( V_44 , L_10 ) ;
goto V_62;
}
return 0 ;
V_62:
F_27 ( V_10 -> V_17 . V_18 ) ;
return V_60 ;
}
static int F_28 ( struct V_63 * V_64 )
{
struct V_9 * V_10 ;
struct V_1 * * V_2 ;
struct V_47 * V_5 ;
int V_3 , V_60 = 0 , V_65 ;
V_10 = F_16 ( & V_64 -> V_44 , sizeof( * V_10 ) , V_53 ) ;
if ( ! V_10 )
return - V_54 ;
F_29 ( & V_10 -> V_66 ) ;
V_10 -> V_44 = & V_64 -> V_44 ;
V_60 = F_22 ( V_10 ) ;
if ( V_60 < 0 ) {
F_14 ( & V_64 -> V_44 ,
L_11 ) ;
return V_60 ;
}
V_5 = V_10 -> V_5 ;
V_65 = sizeof( struct V_1 * ) * V_10 -> V_55 ;
V_10 -> V_2 = F_16 ( & V_64 -> V_44 , V_65 , V_53 ) ;
if ( ! V_10 -> V_2 ) {
F_14 ( & V_64 -> V_44 ,
L_12 ) ;
return - V_54 ;
}
V_2 = V_10 -> V_2 ;
F_30 ( V_64 , V_10 ) ;
for ( V_3 = 0 ; V_3 < V_10 -> V_55 ; V_3 ++ ) {
V_2 [ V_3 ] = F_31 ( & V_64 -> V_44 , & V_5 [ V_3 ] ) ;
if ( F_26 ( V_2 [ V_3 ] ) ) {
V_60 = F_32 ( V_2 [ V_3 ] ) ;
F_14 ( & V_64 -> V_44 ,
L_13 ) ;
goto V_62;
}
}
F_33 ( V_10 -> V_17 . V_61 ) ;
return 0 ;
V_62:
F_27 ( V_10 -> V_17 . V_18 ) ;
return V_60 ;
}
static int F_34 ( struct V_63 * V_64 )
{
struct V_9 * V_10 = F_35 ( V_64 ) ;
F_36 ( V_10 -> V_17 . V_61 ) ;
F_27 ( V_10 -> V_17 . V_18 ) ;
return 0 ;
}

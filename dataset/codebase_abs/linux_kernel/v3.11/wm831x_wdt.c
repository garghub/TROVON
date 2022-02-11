static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_6 ;
F_3 ( & V_4 -> V_7 ) ;
V_6 = F_4 ( V_5 ) ;
if ( V_6 == 0 ) {
V_6 = F_5 ( V_5 , V_8 ,
V_9 , V_9 ) ;
F_6 ( V_5 ) ;
} else {
F_7 ( V_5 -> V_10 , L_1 ,
V_6 ) ;
}
F_8 ( & V_4 -> V_7 ) ;
return V_6 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_6 ;
F_3 ( & V_4 -> V_7 ) ;
V_6 = F_4 ( V_5 ) ;
if ( V_6 == 0 ) {
V_6 = F_5 ( V_5 , V_8 ,
V_9 , 0 ) ;
F_6 ( V_5 ) ;
} else {
F_7 ( V_5 -> V_10 , L_1 ,
V_6 ) ;
}
F_8 ( & V_4 -> V_7 ) ;
return V_6 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_6 ;
T_1 V_11 ;
F_3 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_12 ) {
F_11 ( V_4 -> V_12 ,
V_4 -> V_13 ) ;
V_4 -> V_13 = ! V_4 -> V_13 ;
V_6 = 0 ;
goto V_14;
}
V_11 = F_12 ( V_5 , V_8 ) ;
if ( ! ( V_11 & V_15 ) ) {
F_7 ( V_5 -> V_10 , L_2 ) ;
V_6 = - V_16 ;
goto V_14;
}
V_11 |= V_17 ;
V_6 = F_4 ( V_5 ) ;
if ( V_6 == 0 ) {
V_6 = F_13 ( V_5 , V_8 , V_11 ) ;
F_6 ( V_5 ) ;
} else {
F_7 ( V_5 -> V_10 , L_1 ,
V_6 ) ;
}
V_14:
F_8 ( & V_4 -> V_7 ) ;
return V_6 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned int V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_6 , V_19 ;
for ( V_19 = 0 ; V_19 < F_15 ( V_20 ) ; V_19 ++ )
if ( V_20 [ V_19 ] . time == V_18 )
break;
if ( V_19 == F_15 ( V_20 ) )
return - V_16 ;
V_6 = F_4 ( V_5 ) ;
if ( V_6 == 0 ) {
V_6 = F_5 ( V_5 , V_8 ,
V_21 ,
V_20 [ V_19 ] . V_22 ) ;
F_6 ( V_5 ) ;
} else {
F_7 ( V_5 -> V_10 , L_1 ,
V_6 ) ;
}
V_2 -> V_18 = V_18 ;
return V_6 ;
}
static int F_16 ( struct V_23 * V_24 )
{
struct V_5 * V_5 = F_17 ( V_24 -> V_10 . V_25 ) ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_3 * V_4 ;
struct V_1 * V_30 ;
int V_11 , V_6 , V_19 ;
V_6 = F_12 ( V_5 , V_8 ) ;
if ( V_6 < 0 ) {
F_7 ( V_5 -> V_10 , L_3 ,
V_6 ) ;
goto V_31;
}
V_11 = V_6 ;
if ( V_11 & V_32 )
F_18 ( V_5 -> V_10 , L_4 ) ;
V_4 = F_19 ( & V_24 -> V_10 , sizeof( * V_4 ) ,
V_33 ) ;
if ( ! V_4 ) {
F_7 ( V_5 -> V_10 , L_5 ) ;
V_6 = - V_34 ;
goto V_31;
}
F_20 ( & V_4 -> V_7 ) ;
V_4 -> V_5 = V_5 ;
V_30 = & V_4 -> V_35 ;
V_30 -> V_36 = & V_37 ;
V_30 -> V_38 = & V_39 ;
F_21 ( V_30 , V_40 ) ;
F_22 ( V_30 , V_4 ) ;
V_11 = F_12 ( V_5 , V_8 ) ;
V_11 &= V_21 ;
for ( V_19 = 0 ; V_19 < F_15 ( V_20 ) ; V_19 ++ )
if ( V_20 [ V_19 ] . V_22 == V_11 )
break;
if ( V_19 == F_15 ( V_20 ) )
F_18 ( V_5 -> V_10 ,
L_6 , V_11 ) ;
else
V_30 -> V_18 = V_20 [ V_19 ] . time ;
if ( V_24 -> V_10 . V_25 -> V_41 ) {
V_27 = V_24 -> V_10 . V_25 -> V_41 ;
V_29 = V_27 -> V_42 ;
} else {
V_29 = NULL ;
}
if ( V_29 ) {
V_11 &= ~ ( V_43 | V_44 |
V_15 ) ;
V_11 |= V_29 -> V_45 << V_46 ;
V_11 |= V_29 -> V_47 << V_48 ;
V_11 |= V_29 -> V_49 << V_50 ;
if ( V_29 -> V_12 ) {
V_6 = F_23 ( & V_24 -> V_10 ,
V_29 -> V_12 ,
V_51 ,
L_7 ) ;
if ( V_6 < 0 ) {
F_7 ( V_5 -> V_10 ,
L_8 ,
V_6 ) ;
goto V_31;
}
V_4 -> V_12 = V_29 -> V_12 ;
V_11 |= V_15 ;
}
V_6 = F_4 ( V_5 ) ;
if ( V_6 == 0 ) {
V_6 = F_13 ( V_5 , V_8 , V_11 ) ;
F_6 ( V_5 ) ;
} else {
F_7 ( V_5 -> V_10 ,
L_1 , V_6 ) ;
goto V_31;
}
}
V_6 = F_24 ( & V_4 -> V_35 ) ;
if ( V_6 != 0 ) {
F_7 ( V_5 -> V_10 , L_9 ,
V_6 ) ;
goto V_31;
}
F_25 ( V_24 , V_4 ) ;
return 0 ;
V_31:
return V_6 ;
}
static int F_26 ( struct V_23 * V_24 )
{
struct V_3 * V_4 = F_27 ( V_24 ) ;
F_28 ( & V_4 -> V_35 ) ;
return 0 ;
}

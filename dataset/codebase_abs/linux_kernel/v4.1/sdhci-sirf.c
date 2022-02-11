static void F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 , V_5 ) ;
V_4 &= ~ ( V_6 | V_7 ) ;
if ( V_3 == V_8 )
V_4 |= V_7 ;
else if ( V_3 == V_9 )
V_4 |= V_6 ;
F_3 ( V_2 , V_4 , V_5 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_2 V_10 )
{
int V_11 = 3 ;
T_1 V_12 , V_13 [ V_14 ] ;
T_1 V_15 = 0 ;
int V_16 = 0 , V_17 = 0 ;
int V_18 = - 1 , V_19 = 0 , V_20 = - 1 , V_21 = 0 ;
T_3 V_22 ;
struct V_23 * V_24 = V_2 -> V_24 ;
V_22 = F_5 ( V_2 , V_25 ) ;
V_22 &= ~ 0x3fff ;
V_26:
V_12 = 0 ;
do {
F_6 ( V_2 ,
V_22 | V_12 ,
V_25 ) ;
if ( ! F_7 ( V_24 ) ) {
V_13 [ V_15 ++ ] = V_12 ;
F_8 ( F_9 ( V_24 ) , L_1 ,
F_10 ( V_24 ) , V_12 ) ;
if ( V_18 == - 1 )
V_18 = V_12 ;
V_19 = V_12 ;
V_21 ++ ;
if ( V_12 == ( V_14 - 1 )
&& V_21 > V_17 )
V_20 = ( V_18 + V_19 ) / 2 ;
} else {
F_8 ( F_9 ( V_24 ) , L_2 ,
F_10 ( V_24 ) , V_12 ) ;
if ( V_21 > V_17 ) {
V_20 = ( V_18 + V_19 ) / 2 ;
V_17 = V_21 ;
}
V_18 = - 1 ;
V_19 = V_21 = 0 ;
}
} while ( ++ V_12 < F_11 ( V_13 ) );
if ( V_15 && V_20 > 0 ) {
V_12 = V_20 ;
F_6 ( V_2 ,
V_22 | V_12 ,
V_25 ) ;
F_8 ( F_9 ( V_24 ) , L_3 ,
F_10 ( V_24 ) , V_12 ) ;
} else {
if ( -- V_11 )
goto V_26;
F_8 ( F_9 ( V_24 ) , L_4 ,
F_10 ( V_24 ) ) ;
V_16 = - V_27 ;
}
return V_16 ;
}
static int F_12 ( struct V_28 * V_29 )
{
struct V_1 * V_2 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
struct V_34 * V_34 ;
int V_35 ;
int V_36 ;
V_34 = F_13 ( & V_29 -> V_37 , NULL ) ;
if ( F_14 ( V_34 ) ) {
F_15 ( & V_29 -> V_37 , L_5 ) ;
return F_16 ( V_34 ) ;
}
if ( V_29 -> V_37 . V_38 )
V_35 = F_17 ( V_29 -> V_37 . V_38 , L_6 , 0 ) ;
else
V_35 = - V_39 ;
V_2 = F_18 ( V_29 , & V_40 , sizeof( struct V_32 ) ) ;
if ( F_14 ( V_2 ) )
return F_16 ( V_2 ) ;
V_31 = F_19 ( V_2 ) ;
V_31 -> V_34 = V_34 ;
V_33 = F_20 ( V_31 ) ;
V_33 -> V_35 = V_35 ;
F_21 ( V_29 ) ;
V_36 = F_22 ( V_31 -> V_34 ) ;
if ( V_36 )
goto V_41;
V_36 = F_23 ( V_2 ) ;
if ( V_36 )
goto V_42;
if ( F_24 ( V_33 -> V_35 ) ) {
V_36 = F_25 ( V_2 -> V_24 , V_33 -> V_35 , 0 ) ;
if ( V_36 ) {
F_15 ( & V_29 -> V_37 , L_7 ,
V_36 ) ;
goto V_43;
}
F_26 ( V_2 -> V_24 ) ;
}
return 0 ;
V_43:
F_27 ( V_2 , 0 ) ;
V_42:
F_28 ( V_31 -> V_34 ) ;
V_41:
F_29 ( V_29 ) ;
return V_36 ;
}
static int F_30 ( struct V_44 * V_37 )
{
struct V_1 * V_2 = F_31 ( V_37 ) ;
struct V_30 * V_31 = F_19 ( V_2 ) ;
int V_36 ;
V_36 = F_32 ( V_2 ) ;
if ( V_36 )
return V_36 ;
F_33 ( V_31 -> V_34 ) ;
return 0 ;
}
static int F_34 ( struct V_44 * V_37 )
{
struct V_1 * V_2 = F_31 ( V_37 ) ;
struct V_30 * V_31 = F_19 ( V_2 ) ;
int V_36 ;
V_36 = F_35 ( V_31 -> V_34 ) ;
if ( V_36 ) {
F_8 ( V_37 , L_8 ) ;
return V_36 ;
}
return F_36 ( V_2 ) ;
}

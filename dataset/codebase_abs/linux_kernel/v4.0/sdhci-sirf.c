static unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
return F_4 ( V_6 -> V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_8 )
{
T_1 V_9 ;
V_9 = F_6 ( V_2 , V_10 ) ;
V_9 &= ~ ( V_11 | V_12 ) ;
if ( V_8 == V_13 )
V_9 |= V_12 ;
else if ( V_8 == V_14 )
V_9 |= V_11 ;
F_7 ( V_2 , V_9 , V_10 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_2 V_15 )
{
int V_16 = 3 ;
T_1 V_17 , V_18 [ V_19 ] ;
T_1 V_20 = 0 ;
int V_21 , V_22 = 0 ;
int V_23 = - 1 , V_24 = 0 , V_25 = - 1 , V_26 = 0 ;
T_3 V_27 ;
struct V_28 * V_29 = V_2 -> V_29 ;
V_27 = F_9 ( V_2 , V_30 ) ;
V_27 &= ~ 0x3fff ;
V_31:
V_17 = 0 ;
do {
F_10 ( V_2 ,
V_27 | V_17 | ( V_17 << 7 ) | ( V_17 << 16 ) ,
V_30 ) ;
if ( ! F_11 ( V_29 ) ) {
V_18 [ V_20 ++ ] = V_17 ;
F_12 ( F_13 ( V_29 ) , L_1 ,
F_14 ( V_29 ) , V_17 ) ;
if ( V_23 == - 1 )
V_23 = V_17 ;
V_24 = V_17 ;
V_26 ++ ;
if ( V_17 == ( V_19 - 1 )
&& V_26 > V_22 )
V_25 = ( V_23 + V_24 ) / 2 ;
} else {
F_12 ( F_13 ( V_29 ) , L_2 ,
F_14 ( V_29 ) , V_17 ) ;
if ( V_26 > V_22 ) {
V_25 = ( V_23 + V_24 ) / 2 ;
V_22 = V_26 ;
}
V_23 = - 1 ;
V_24 = V_26 = 0 ;
}
} while ( ++ V_17 < F_15 ( V_18 ) );
if ( V_20 && V_25 > 0 ) {
V_17 = V_25 ;
F_10 ( V_2 ,
V_27 | V_17 | ( V_17 << 7 ) | ( V_17 << 16 ) ,
V_30 ) ;
F_12 ( F_13 ( V_29 ) , L_3 ,
F_14 ( V_29 ) , V_17 ) ;
} else {
if ( -- V_16 )
goto V_31;
F_12 ( F_13 ( V_29 ) , L_4 ,
F_14 ( V_29 ) ) ;
V_21 = - V_32 ;
}
return V_21 ;
}
static int F_16 ( struct V_33 * V_34 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_7 ;
int V_35 ;
int V_36 ;
V_7 = F_17 ( & V_34 -> V_37 , NULL ) ;
if ( F_18 ( V_7 ) ) {
F_19 ( & V_34 -> V_37 , L_5 ) ;
return F_20 ( V_7 ) ;
}
if ( V_34 -> V_37 . V_38 )
V_35 = F_21 ( V_34 -> V_37 . V_38 , L_6 , 0 ) ;
else
V_35 = - V_39 ;
V_2 = F_22 ( V_34 , & V_40 , sizeof( struct V_5 ) ) ;
if ( F_18 ( V_2 ) )
return F_20 ( V_2 ) ;
V_4 = F_2 ( V_2 ) ;
V_6 = F_3 ( V_4 ) ;
V_6 -> V_7 = V_7 ;
V_6 -> V_35 = V_35 ;
F_23 ( V_34 ) ;
V_36 = F_24 ( V_6 -> V_7 ) ;
if ( V_36 )
goto V_41;
V_36 = F_25 ( V_2 ) ;
if ( V_36 )
goto V_42;
if ( F_26 ( V_6 -> V_35 ) ) {
V_36 = F_27 ( V_2 -> V_29 , V_6 -> V_35 , 0 ) ;
if ( V_36 ) {
F_19 ( & V_34 -> V_37 , L_7 ,
V_36 ) ;
goto V_43;
}
F_28 ( V_2 -> V_29 ) ;
}
return 0 ;
V_43:
F_29 ( V_2 , 0 ) ;
V_42:
F_30 ( V_6 -> V_7 ) ;
V_41:
F_31 ( V_34 ) ;
return V_36 ;
}
static int F_32 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_33 ( V_34 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_34 ( V_34 ) ;
F_30 ( V_6 -> V_7 ) ;
return 0 ;
}
static int F_35 ( struct V_44 * V_37 )
{
struct V_1 * V_2 = F_36 ( V_37 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_36 ;
V_36 = F_37 ( V_2 ) ;
if ( V_36 )
return V_36 ;
F_38 ( V_6 -> V_7 ) ;
return 0 ;
}
static int F_39 ( struct V_44 * V_37 )
{
struct V_1 * V_2 = F_36 ( V_37 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_36 ;
V_36 = F_40 ( V_6 -> V_7 ) ;
if ( V_36 ) {
F_12 ( V_37 , L_8 ) ;
return V_36 ;
}
return F_41 ( V_2 ) ;
}

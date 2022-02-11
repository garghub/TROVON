static inline int F_1 ( int V_1 )
{
return 365 + ( F_2 ( V_1 ) ? 1 : 0 ) ;
}
static void F_3 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_4 ( V_3 ) ;
T_1 V_6 ;
V_6 = F_5 ( V_5 -> V_7 + V_8 ) ;
V_6 |= V_9 ;
F_6 ( V_6 , V_5 -> V_7 + V_8 ) ;
V_6 &= ~ V_9 ;
F_7 ( V_6 , V_5 -> V_7 + V_8 ) ;
}
static void F_8 ( struct V_2 * V_3 , bool V_10 )
{
struct V_4 * V_5 = F_4 ( V_3 ) ;
T_1 V_6 ;
V_6 = F_5 ( V_5 -> V_7 + V_11 ) ;
if ( V_10 ) {
if ( ( V_6 & V_12 ) == 0x5a )
return;
F_6 ( 0x5a , V_5 -> V_7 + V_11 ) ;
} else {
F_6 ( 0 , V_5 -> V_7 + V_11 ) ;
}
}
static int F_9 ( struct V_2 * V_3 , struct V_13 * V_14 )
{
struct V_4 * V_5 = F_4 ( V_3 ) ;
T_2 V_15 ;
T_1 V_16 ;
unsigned int V_1 ;
int V_17 = 0 ;
while ( true ) {
V_14 -> V_18 = ( F_5 ( V_5 -> V_7 + V_19 ) & V_20 ) >> 1 ;
V_14 -> V_21 = F_5 ( V_5 -> V_7 + V_22 ) & V_23 ;
V_14 -> V_24 = F_5 ( V_5 -> V_7 + V_25 ) & V_26 ;
V_15 = F_5 ( V_5 -> V_7 + V_27 ) & V_28 ;
V_15 |= ( F_5 ( V_5 -> V_7 + V_29 ) & V_30 ) << 8 ;
V_16 = ( F_5 ( V_5 -> V_7 + V_19 ) & V_20 ) >> 1 ;
V_17 ++ ;
if ( V_16 == V_14 -> V_18 )
break;
if ( V_17 >= 3 )
return - V_31 ;
}
if ( V_17 > 1 )
F_10 ( V_3 , L_1 , V_32 , V_17 ) ;
V_1 = V_5 -> V_33 ;
while ( V_15 >= F_1 ( V_1 ) ) {
V_15 -= F_1 ( V_1 ) ;
V_1 ++ ;
}
V_14 -> V_34 = V_1 - 1900 ;
V_14 -> V_35 = V_15 ;
V_14 -> V_36 = 0 ;
while ( V_15 >= F_11 ( V_14 -> V_36 , V_1 ) ) {
V_15 -= F_11 ( V_14 -> V_36 , V_1 ) ;
V_14 -> V_36 ++ ;
}
V_14 -> V_37 = V_15 + 1 ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 , struct V_13 * V_14 )
{
struct V_4 * V_5 = F_4 ( V_3 ) ;
unsigned int V_15 ;
int V_38 ;
if ( 1900 + V_14 -> V_34 < V_5 -> V_33 )
return - V_31 ;
V_15 = 0 ;
for ( V_38 = V_5 -> V_33 ; V_38 < 1900 + V_14 -> V_34 ; V_38 ++ )
V_15 += F_1 ( V_38 ) ;
V_15 += V_14 -> V_35 ;
if ( V_15 > 0x7fff )
return - V_31 ;
F_8 ( V_3 , false ) ;
F_6 ( ( V_14 -> V_18 << 1 ) & V_20 , V_5 -> V_7 + V_19 ) ;
F_6 ( V_14 -> V_21 & V_23 , V_5 -> V_7 + V_22 ) ;
F_6 ( V_14 -> V_24 & V_26 , V_5 -> V_7 + V_25 ) ;
F_6 ( V_15 & V_28 , V_5 -> V_7 + V_27 ) ;
F_6 ( ( V_15 >> 8 ) & V_30 , V_5 -> V_7 + V_29 ) ;
F_8 ( V_3 , true ) ;
return 0 ;
}
static int F_13 ( struct V_39 * V_40 )
{
struct V_4 * V_5 ;
struct V_41 * V_42 ;
T_1 V_6 ;
int V_43 ;
V_5 = F_14 ( & V_40 -> V_3 , sizeof( * V_5 ) , V_44 ) ;
if ( ! V_5 )
return - V_45 ;
F_15 ( V_40 , V_5 ) ;
V_5 -> V_33 = 2014 ;
V_42 = F_16 ( V_40 , V_46 , 0 ) ;
V_5 -> V_7 = F_17 ( & V_40 -> V_3 , V_42 ) ;
if ( F_18 ( V_5 -> V_7 ) )
return F_19 ( V_5 -> V_7 ) ;
V_5 -> V_47 = F_20 ( V_40 -> V_3 . V_48 , 0 ) ;
if ( F_18 ( V_5 -> V_47 ) )
return F_19 ( V_5 -> V_47 ) ;
V_43 = F_21 ( V_5 -> V_47 ) ;
if ( V_43 ) {
F_22 ( V_5 -> V_47 ) ;
return V_43 ;
}
V_6 = F_5 ( V_5 -> V_7 + V_49 ) ;
if ( ! ( V_6 & V_50 ) ) {
F_6 ( V_50 , V_5 -> V_7 + V_49 ) ;
F_3 ( & V_40 -> V_3 ) ;
F_6 ( 0 , V_5 -> V_7 + V_22 ) ;
F_6 ( 0 , V_5 -> V_7 + V_25 ) ;
F_6 ( 0 , V_5 -> V_7 + V_27 ) ;
F_6 ( 0 , V_5 -> V_7 + V_29 ) ;
}
F_8 ( & V_40 -> V_3 , true ) ;
V_5 -> V_51 = F_23 ( & V_40 -> V_3 , L_2 ,
& V_52 , V_53 ) ;
if ( F_18 ( V_5 -> V_51 ) ) {
F_24 ( & V_40 -> V_3 , L_3 ) ;
F_25 ( V_5 -> V_47 ) ;
F_22 ( V_5 -> V_47 ) ;
return F_19 ( V_5 -> V_51 ) ;
}
return 0 ;
}
static int F_26 ( struct V_39 * V_40 )
{
struct V_4 * V_5 = F_27 ( V_40 ) ;
F_8 ( & V_40 -> V_3 , false ) ;
F_25 ( V_5 -> V_47 ) ;
F_22 ( V_5 -> V_47 ) ;
return 0 ;
}

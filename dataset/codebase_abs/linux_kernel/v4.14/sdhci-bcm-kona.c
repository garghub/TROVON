static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
unsigned long V_4 ;
V_4 = V_5 + F_2 ( 100 ) ;
V_3 = F_3 ( V_2 , V_6 ) ;
V_3 |= V_7 ;
F_4 ( V_2 , V_3 , V_6 ) ;
while ( ! ( F_3 ( V_2 , V_6 ) & V_7 ) ) {
if ( F_5 ( V_4 ) ) {
F_6 ( L_1 ) ;
return - V_8 ;
}
}
V_3 = F_3 ( V_2 , V_6 ) ;
V_3 &= ~ V_7 ;
F_7 ( 1000 , 5000 ) ;
F_4 ( V_2 , V_3 , V_6 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = F_3 ( V_2 , V_9 ) ;
V_3 |= V_10 ;
F_4 ( V_2 , V_3 , V_9 ) ;
V_3 = F_3 ( V_2 , V_6 ) ;
V_3 |= V_11 ;
F_7 ( 1000 , 5000 ) ;
F_4 ( V_2 , V_3 , V_6 ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_12 )
{
struct V_13 * V_14 = F_10 ( V_2 ) ;
struct V_15 * V_16 = F_11 ( V_14 ) ;
T_1 V_3 ;
F_12 ( & V_16 -> V_17 ) ;
F_13 ( 20 ) ;
V_3 = F_3 ( V_2 , V_18 ) ;
if ( V_12 ) {
int V_19 ;
V_19 = F_14 ( V_2 -> V_20 ) ;
if ( V_19 >= 0 )
V_3 = ( V_3 & ~ V_21 ) |
( ( V_19 ) ? V_21 : 0 ) ;
V_3 |= V_22 ;
F_4 ( V_2 , V_3 , V_18 ) ;
} else {
V_3 &= ~ V_22 ;
F_4 ( V_2 , V_3 , V_18 ) ;
}
F_15 ( & V_16 -> V_17 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
if ( F_17 ( V_2 -> V_20 ) > 0 ) {
F_18 ( F_19 ( V_2 -> V_20 ) ,
L_2 ) ;
F_9 ( V_2 , 1 ) ;
} else {
F_18 ( F_19 ( V_2 -> V_20 ) ,
L_3 ) ;
F_9 ( V_2 , 0 ) ;
}
}
static void F_20 ( struct V_1 * V_2 ,
T_2 V_23 )
{
if ( V_23 != V_24 )
F_13 ( 740 ) ;
}
static int F_21 ( struct V_25 * V_26 )
{
struct V_15 * V_16 = NULL ;
struct V_13 * V_14 ;
struct V_27 * V_28 = & V_26 -> V_28 ;
struct V_1 * V_2 ;
int V_19 ;
V_19 = 0 ;
V_2 = F_22 ( V_26 , & V_29 ,
sizeof( * V_16 ) ) ;
if ( F_23 ( V_2 ) )
return F_24 ( V_2 ) ;
F_18 ( V_28 , L_4 , V_30 , V_2 -> V_31 ) ;
V_14 = F_10 ( V_2 ) ;
V_16 = F_11 ( V_14 ) ;
F_25 ( & V_16 -> V_17 ) ;
V_19 = F_26 ( V_2 -> V_20 ) ;
if ( V_19 )
goto V_32;
if ( ! V_2 -> V_20 -> V_33 ) {
F_27 ( & V_26 -> V_28 , L_5 ) ;
V_19 = - V_34 ;
goto V_32;
}
V_14 -> V_35 = F_28 ( V_28 , NULL ) ;
if ( F_23 ( V_14 -> V_35 ) ) {
F_27 ( V_28 , L_6 ) ;
V_19 = F_24 ( V_14 -> V_35 ) ;
goto V_32;
}
V_19 = F_29 ( V_14 -> V_35 , V_2 -> V_20 -> V_33 ) ;
if ( V_19 ) {
F_27 ( V_28 , L_7 ) ;
goto V_32;
}
V_19 = F_30 ( V_14 -> V_35 ) ;
if ( V_19 ) {
F_27 ( V_28 , L_8 ) ;
goto V_32;
}
F_18 ( V_28 , L_9 ,
F_31 ( V_2 -> V_20 ) ? 'N' : 'Y' ) ;
F_18 ( V_28 , L_10 ,
( F_17 ( V_2 -> V_20 ) != - V_36 ) ? 'Y' : 'N' ,
( F_14 ( V_2 -> V_20 ) != - V_36 ) ? 'Y' : 'N' ) ;
if ( ! F_31 ( V_2 -> V_20 ) )
V_2 -> V_37 |= V_38 ;
F_18 ( V_28 , L_11 ,
( V_2 -> V_20 -> V_39 & V_40 ) ? 'Y' : 'N' ) ;
V_19 = F_1 ( V_2 ) ;
if ( V_19 )
goto V_41;
F_8 ( V_2 ) ;
V_19 = F_32 ( V_2 ) ;
if ( V_19 ) {
F_27 ( V_28 , L_12 ) ;
goto V_42;
}
if ( ! F_31 ( V_2 -> V_20 ) ) {
V_19 = F_9 ( V_2 , 1 ) ;
if ( V_19 ) {
F_27 ( V_28 ,
L_13 ) ;
goto V_43;
}
}
if ( F_17 ( V_2 -> V_20 ) > 0 )
F_9 ( V_2 , 1 ) ;
F_18 ( V_28 , L_14 ) ;
return 0 ;
V_43:
F_33 ( V_2 , 0 ) ;
V_42:
F_1 ( V_2 ) ;
V_41:
F_34 ( V_14 -> V_35 ) ;
V_32:
F_35 ( V_26 ) ;
F_27 ( V_28 , L_15 , V_19 ) ;
return V_19 ;
}

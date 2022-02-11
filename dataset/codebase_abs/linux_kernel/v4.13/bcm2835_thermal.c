static int F_1 ( T_1 V_1 , int V_2 , int V_3 )
{
return V_2 + V_3 * V_1 ;
}
static int F_2 ( int V_4 , int V_2 , int V_3 )
{
V_4 -= V_2 ;
V_4 /= V_3 ;
if ( V_4 < 0 )
V_4 = 0 ;
if ( V_4 >= F_3 ( V_5 ) )
V_4 = F_3 ( V_5 ) - 1 ;
return V_4 ;
}
static int F_4 ( void * V_6 , int * V_4 )
{
struct V_7 * V_8 = V_6 ;
T_1 V_9 = F_5 ( V_8 -> V_10 + V_11 ) ;
if ( ! ( V_9 & V_12 ) )
return - V_13 ;
V_9 &= V_14 ;
* V_4 = F_1 (
V_9 ,
F_6 ( V_8 -> V_15 ) ,
F_7 ( V_8 -> V_15 ) ) ;
return 0 ;
}
static void F_8 ( struct V_16 * V_17 )
{
struct V_18 * V_15 = F_9 ( V_17 ) ;
struct V_7 * V_8 = V_15 -> V_19 ;
struct V_20 * V_21 ;
V_8 -> V_22 = F_10 ( L_1 , NULL ) ;
if ( ! V_8 -> V_22 )
return;
V_21 = F_11 ( & V_17 -> V_23 , sizeof( * V_21 ) , V_24 ) ;
if ( ! V_21 )
return;
V_21 -> V_10 = V_25 ;
V_21 -> V_26 = F_12 ( V_25 ) ;
V_21 -> V_27 = V_8 -> V_10 ;
F_13 ( L_2 , 0444 , V_8 -> V_22 , V_21 ) ;
}
static int F_14 ( struct V_16 * V_17 )
{
const struct V_28 * V_29 ;
struct V_18 * V_15 ;
struct V_7 * V_8 ;
struct V_30 * V_31 ;
int V_32 = 0 ;
T_1 V_9 ;
unsigned long V_33 ;
V_8 = F_11 ( & V_17 -> V_23 , sizeof( * V_8 ) , V_24 ) ;
if ( ! V_8 )
return - V_34 ;
V_29 = F_15 ( V_35 ,
& V_17 -> V_23 ) ;
if ( ! V_29 )
return - V_36 ;
V_31 = F_16 ( V_17 , V_37 , 0 ) ;
V_8 -> V_10 = F_17 ( & V_17 -> V_23 , V_31 ) ;
if ( F_18 ( V_8 -> V_10 ) ) {
V_32 = F_19 ( V_8 -> V_10 ) ;
F_20 ( & V_17 -> V_23 , L_3 , V_32 ) ;
return V_32 ;
}
V_8 -> V_38 = F_21 ( & V_17 -> V_23 , NULL ) ;
if ( F_18 ( V_8 -> V_38 ) ) {
V_32 = F_19 ( V_8 -> V_38 ) ;
if ( V_32 != - V_39 )
F_20 ( & V_17 -> V_23 , L_4 , V_32 ) ;
return V_32 ;
}
V_32 = F_22 ( V_8 -> V_38 ) ;
if ( V_32 )
return V_32 ;
V_33 = F_23 ( V_8 -> V_38 ) ;
if ( ( V_33 < 1920000 ) || ( V_33 > 5000000 ) )
F_24 ( & V_17 -> V_23 ,
L_5 ,
V_8 -> V_38 , V_8 -> V_38 ) ;
V_15 = F_25 ( & V_17 -> V_23 , 0 , V_8 ,
& V_40 ) ;
if ( F_18 ( V_15 ) ) {
V_32 = F_19 ( V_15 ) ;
F_20 ( & V_17 -> V_23 ,
L_6 ,
V_32 ) ;
goto V_41;
}
V_9 = F_5 ( V_8 -> V_10 + V_42 ) ;
if ( ! ( V_9 & V_43 ) ) {
int V_44 , V_2 , V_3 ;
V_3 = F_7 ( V_15 ) ;
V_2 = F_6 ( V_15 ) ;
V_32 = V_15 -> V_45 -> V_46 ( V_15 , 0 , & V_44 ) ;
if ( V_32 < 0 ) {
F_20 ( & V_17 -> V_23 ,
L_7 ,
V_32 ) ;
goto V_47;
}
V_9 = ( V_48 <<
V_49 ) |
V_50 ;
V_9 |= ( 0xFE << V_51 ) ;
V_9 |= F_2 ( V_44 ,
V_2 ,
V_3 )
<< V_52 ;
F_26 ( V_9 , V_8 -> V_10 + V_42 ) ;
V_9 |= V_43 ;
F_26 ( V_9 , V_8 -> V_10 + V_42 ) ;
}
V_8 -> V_15 = V_15 ;
F_27 ( V_17 , V_15 ) ;
F_8 ( V_17 ) ;
return 0 ;
V_47:
F_28 ( & V_17 -> V_23 , V_15 ) ;
V_41:
F_29 ( V_8 -> V_38 ) ;
return V_32 ;
}
static int F_30 ( struct V_16 * V_17 )
{
struct V_18 * V_15 = F_9 ( V_17 ) ;
struct V_7 * V_8 = V_15 -> V_19 ;
F_31 ( V_8 -> V_22 ) ;
F_28 ( & V_17 -> V_23 , V_15 ) ;
F_29 ( V_8 -> V_38 ) ;
return 0 ;
}

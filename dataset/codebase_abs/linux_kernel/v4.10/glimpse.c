T_1 F_1 ( struct V_1 * V_1 )
{
T_1 V_2 = 0 ;
struct V_3 * V_4 = F_2 ( V_1 ) ;
void * V_5 [ 1 ] ;
if ( V_1 -> V_6 )
V_2 += F_3 ( & V_1 -> V_6 -> V_7 ,
V_5 , 0 , 1 ,
V_8 ) ;
if ( V_2 == 0 && F_4 ( & V_4 -> V_9 ) > 0 )
V_2 = 1 ;
return ( V_2 > 0 ) ? 1 : 0 ;
}
int F_5 ( const struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_1 * V_1 , struct V_14 * V_15 , int V_16 )
{
const struct V_17 * V_18 = F_6 ( & V_15 -> V_19 ) ;
struct V_20 * V_21 = F_7 ( V_11 ) ;
struct V_22 * V_23 = & V_21 -> V_24 ;
int V_25 = 0 ;
F_8 ( V_26 , L_1 V_27 L_2 , F_9 ( V_18 ) ) ;
* V_23 = V_28 ;
V_23 -> V_29 = V_15 ;
V_23 -> V_30 = V_31 ;
V_23 -> V_32 = V_33 | V_34 ;
if ( V_16 )
V_23 -> V_32 |= V_35 ;
V_25 = F_10 ( V_11 , V_13 , V_21 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ! V_16 ) {
F_11 ( V_11 , V_1 ) ;
if ( F_12 ( V_1 ) > 0 && ! V_1 -> V_36 ) {
V_1 -> V_36 = F_1 ( V_1 ) ;
}
}
F_13 ( V_11 , V_21 ) ;
return V_25 ;
}
static int F_14 ( struct V_1 * V_1 , struct V_10 * * V_37 ,
struct V_12 * * V_38 , int * V_39 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_40 * V_41 = F_15 ( V_1 ) ;
struct V_14 * V_15 = V_41 -> V_42 ;
int V_25 ;
if ( F_16 ( V_1 -> V_43 ) ) {
V_11 = F_17 ( V_39 ) ;
if ( ! F_18 ( V_11 ) ) {
V_13 = F_19 ( V_11 ) ;
V_13 -> V_44 = V_15 ;
* V_37 = V_11 ;
* V_38 = V_13 ;
V_25 = 1 ;
} else {
V_25 = F_20 ( V_11 ) ;
}
} else {
V_25 = 0 ;
}
return V_25 ;
}
int F_21 ( struct V_1 * V_1 , int V_16 )
{
struct V_10 * V_11 = NULL ;
struct V_12 * V_13 = NULL ;
int V_25 ;
int V_39 ;
V_25 = F_14 ( V_1 , & V_11 , & V_13 , & V_39 ) ;
if ( V_25 > 0 ) {
V_45:
V_13 -> V_46 = 1 ;
V_25 = F_22 ( V_11 , V_13 , V_47 , V_13 -> V_44 ) ;
if ( V_25 > 0 )
V_25 = V_13 -> V_48 ;
else if ( V_25 == 0 )
V_25 = F_5 ( V_11 , V_13 , V_1 , V_13 -> V_44 ,
V_16 ) ;
F_23 ( V_49 , 2 ) ;
F_24 ( V_11 , V_13 ) ;
if ( F_25 ( V_13 -> V_50 ) )
goto V_45;
F_26 ( V_11 , & V_39 ) ;
}
return V_25 ;
}

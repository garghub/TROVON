T_1 F_1 ( struct V_1 * V_1 )
{
T_1 V_2 = 0 ;
struct V_3 * V_4 = F_2 ( V_1 ) ;
void * V_5 [ 1 ] ;
if ( V_1 -> V_6 != NULL )
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
struct V_17 * V_18 = & F_6 ( V_11 ) -> V_19 ;
struct V_20 * V_21 = F_7 ( V_1 ) ;
const struct V_22 * V_23 = F_8 ( & V_15 -> V_24 ) ;
struct V_25 * V_26 = F_9 ( V_11 ) ;
struct V_27 * V_28 ;
int V_29 ;
V_30 ;
V_29 = 0 ;
if ( ! ( V_21 -> V_31 & V_32 ) ) {
F_10 ( V_33 , L_1 V_34 L_2 , F_11 ( V_23 ) ) ;
if ( V_21 -> V_35 ) {
* V_18 = V_36 ;
V_18 -> V_37 = V_15 ;
V_18 -> V_38 = V_39 ;
V_18 -> V_40 = V_41 | V_42 ;
if ( V_16 )
V_18 -> V_40 |= V_43 ;
V_26 -> V_44 = 1 ;
V_28 = F_12 ( V_11 , V_13 , V_18 , L_3 ,
V_45 ) ;
V_26 -> V_44 = 0 ;
if ( V_28 == NULL )
RETURN ( 0 ) ;
if ( F_13 ( V_28 ) )
RETURN ( F_14 ( V_28 ) ) ;
F_15 ( V_16 == 0 ) ;
V_29 = F_16 ( V_11 , V_28 ) ;
if ( V_29 == 0 ) {
F_17 ( V_11 , V_1 ) ;
if ( F_18 ( V_1 ) > 0 &&
V_1 -> V_46 == 0 ) {
V_1 -> V_46 = F_1 ( V_1 ) ;
}
F_19 ( V_11 , V_28 ) ;
}
F_20 ( V_11 , V_28 , L_3 , V_45 ) ;
} else {
F_10 ( V_33 , L_4 ) ;
F_17 ( V_11 , V_1 ) ;
}
}
RETURN ( V_29 ) ;
}
static int F_21 ( struct V_1 * V_1 , struct V_10 * * V_47 ,
struct V_12 * * V_48 , int * V_49 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_20 * V_21 = F_7 ( V_1 ) ;
struct V_14 * V_15 = V_21 -> V_50 ;
int V_29 ;
if ( F_22 ( F_23 ( V_1 ) ) ) {
V_11 = F_24 ( V_49 ) ;
if ( ! F_13 ( V_11 ) ) {
V_13 = F_25 ( V_11 ) ;
V_13 -> V_51 = V_15 ;
* V_47 = V_11 ;
* V_48 = V_13 ;
V_29 = + 1 ;
} else
V_29 = F_14 ( V_11 ) ;
} else
V_29 = 0 ;
return V_29 ;
}
int F_26 ( struct V_1 * V_1 , int V_16 )
{
struct V_10 * V_11 = NULL ;
struct V_12 * V_13 = NULL ;
int V_29 ;
int V_49 ;
V_30 ;
V_29 = F_21 ( V_1 , & V_11 , & V_13 , & V_49 ) ;
if ( V_29 > 0 ) {
V_52:
V_13 -> V_53 = 1 ;
V_29 = F_27 ( V_11 , V_13 , V_54 , V_13 -> V_51 ) ;
if ( V_29 > 0 )
V_29 = V_13 -> V_55 ;
else if ( V_29 == 0 )
V_29 = F_5 ( V_11 , V_13 , V_1 , V_13 -> V_51 ,
V_16 ) ;
F_28 ( V_56 , 2 ) ;
F_29 ( V_11 , V_13 ) ;
if ( F_30 ( V_13 -> V_57 ) )
goto V_52;
F_31 ( V_11 , & V_49 ) ;
}
RETURN ( V_29 ) ;
}
int F_32 ( struct V_1 * V_1 )
{
struct V_10 * V_11 = NULL ;
struct V_12 * V_13 = NULL ;
struct V_58 * V_59 ;
struct V_14 * V_15 ;
struct V_17 * V_18 ;
struct V_27 * V_28 ;
int V_29 ;
int V_49 ;
V_30 ;
if ( ! F_7 ( V_1 ) -> V_35 )
RETURN ( 0 ) ;
V_29 = F_21 ( V_1 , & V_11 , & V_13 , & V_49 ) ;
if ( V_29 <= 0 )
RETURN ( V_29 ) ;
V_15 = V_13 -> V_51 ;
V_29 = F_27 ( V_11 , V_13 , V_54 , V_15 ) ;
if ( V_29 > 0 )
V_29 = V_13 -> V_55 ;
else if ( V_29 == 0 ) {
V_59 = F_6 ( V_11 ) ;
V_18 = & V_59 -> V_19 ;
* V_18 = V_36 ;
V_18 -> V_37 = V_15 ;
V_28 = F_33 ( V_11 , V_13 , V_18 , L_5 , V_45 ) ;
if ( V_28 != NULL ) {
F_17 ( V_11 , V_1 ) ;
F_19 ( V_11 , V_28 ) ;
F_20 ( V_11 , V_28 , L_5 , V_45 ) ;
V_29 = 0 ;
} else
V_29 = - V_60 ;
}
F_29 ( V_11 , V_13 ) ;
F_31 ( V_11 , & V_49 ) ;
RETURN ( V_29 ) ;
}

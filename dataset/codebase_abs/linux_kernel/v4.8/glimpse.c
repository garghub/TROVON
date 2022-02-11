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
struct V_17 * V_18 = F_6 ( V_1 ) ;
const struct V_19 * V_20 = F_7 ( & V_15 -> V_21 ) ;
int V_22 ;
V_22 = 0 ;
if ( ! ( V_18 -> V_23 & V_24 ) ) {
F_8 ( V_25 , L_1 V_26 L_2 , F_9 ( V_20 ) ) ;
if ( V_18 -> V_27 ) {
struct V_28 * V_29 = F_10 ( V_11 ) ;
struct V_30 * V_31 = & V_29 -> V_32 ;
* V_31 = V_33 ;
V_31 -> V_34 = V_15 ;
V_31 -> V_35 = V_36 ;
V_31 -> V_37 = V_38 | V_39 ;
if ( V_16 )
V_31 -> V_37 |= V_40 ;
V_22 = F_11 ( V_11 , V_13 , V_29 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( ! V_16 ) {
F_12 ( V_11 , V_1 ) ;
if ( F_13 ( V_1 ) > 0 &&
V_1 -> V_41 == 0 ) {
V_1 -> V_41 = F_1 ( V_1 ) ;
}
}
F_14 ( V_11 , V_29 ) ;
} else {
F_8 ( V_25 , L_3 ) ;
F_12 ( V_11 , V_1 ) ;
}
}
return V_22 ;
}
static int F_15 ( struct V_1 * V_1 , struct V_10 * * V_42 ,
struct V_12 * * V_43 , int * V_44 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_17 * V_18 = F_6 ( V_1 ) ;
struct V_14 * V_15 = V_18 -> V_45 ;
int V_22 ;
if ( F_16 ( V_1 -> V_46 ) ) {
V_11 = F_17 ( V_44 ) ;
if ( ! F_18 ( V_11 ) ) {
V_13 = F_19 ( V_11 ) ;
V_13 -> V_47 = V_15 ;
* V_42 = V_11 ;
* V_43 = V_13 ;
V_22 = 1 ;
} else {
V_22 = F_20 ( V_11 ) ;
}
} else {
V_22 = 0 ;
}
return V_22 ;
}
int F_21 ( struct V_1 * V_1 , int V_16 )
{
struct V_10 * V_11 = NULL ;
struct V_12 * V_13 = NULL ;
int V_22 ;
int V_44 ;
V_22 = F_15 ( V_1 , & V_11 , & V_13 , & V_44 ) ;
if ( V_22 > 0 ) {
V_48:
V_13 -> V_49 = 1 ;
V_22 = F_22 ( V_11 , V_13 , V_50 , V_13 -> V_47 ) ;
if ( V_22 > 0 )
V_22 = V_13 -> V_51 ;
else if ( V_22 == 0 )
V_22 = F_5 ( V_11 , V_13 , V_1 , V_13 -> V_47 ,
V_16 ) ;
F_23 ( V_52 , 2 ) ;
F_24 ( V_11 , V_13 ) ;
if ( F_25 ( V_13 -> V_53 ) )
goto V_48;
F_26 ( V_11 , & V_44 ) ;
}
return V_22 ;
}
int F_27 ( struct V_1 * V_1 )
{
struct V_10 * V_11 = NULL ;
struct V_12 * V_13 = NULL ;
struct V_14 * V_15 ;
int V_22 ;
int V_44 ;
if ( ! F_6 ( V_1 ) -> V_27 )
return 0 ;
V_22 = F_15 ( V_1 , & V_11 , & V_13 , & V_44 ) ;
if ( V_22 <= 0 )
return V_22 ;
V_15 = V_13 -> V_47 ;
V_22 = F_22 ( V_11 , V_13 , V_50 , V_15 ) ;
if ( V_22 > 0 ) {
V_22 = V_13 -> V_51 ;
} else if ( V_22 == 0 ) {
struct V_28 * V_29 = F_10 ( V_11 ) ;
V_29 -> V_32 = V_33 ;
V_29 -> V_32 . V_37 = V_54 ;
V_29 -> V_32 . V_34 = V_15 ;
V_22 = F_11 ( V_11 , V_13 , V_29 ) ;
if ( V_22 == 0 ) {
F_12 ( V_11 , V_1 ) ;
F_14 ( V_11 , V_29 ) ;
}
}
F_24 ( V_11 , V_13 ) ;
F_26 ( V_11 , & V_44 ) ;
return V_22 ;
}

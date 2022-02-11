static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
enum V_4 V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_9 ;
unsigned int V_10 ;
unsigned int V_11 = 1000 ;
int V_12 ;
if ( ! V_9 )
return - V_13 ;
V_12 = F_2 ( V_9 , V_14 ,
V_15 | V_16 |
V_17 |
V_18 |
V_19 | V_20 ,
F_3 ( 4 ) | F_4 ( 4 ) ) ;
if ( V_12 )
return V_12 ;
V_12 = F_5 ( V_9 , V_21 , & V_10 ) ;
if ( V_12 )
return V_12 ;
if ( V_5 == V_22 ) {
V_10 &= ~ V_23 ;
V_10 |= F_6 ( V_3 ) ;
} else {
V_10 &= ~ V_24 ;
V_10 |= F_7 ( V_3 ) ;
}
F_8 ( V_9 , V_21 , V_10 ) ;
F_2 ( V_9 , V_14 ,
V_20 | V_18 |
V_19 ,
F_3 ( 4 ) | F_4 ( 4 ) |
V_19 ) ;
do {
V_12 = F_5 ( V_9 , V_25 , & V_10 ) ;
if ( V_12 )
return V_12 ;
} while ( -- V_11 && ! ( V_10 & V_26 ) );
if ( ! V_11 ) {
F_9 ( V_2 -> V_27 , L_1 , V_28 ) ;
return - V_29 ;
}
return 0 ;
}
static int F_10 ( struct V_30 * V_31 , T_1 V_32 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
struct V_33 * V_34 = V_31 -> V_34 ;
int V_12 , V_35 = 0 , V_36 = 0 , V_37 = 0 , V_3 , V_38 = 0 ;
for ( V_3 = 1 ; V_3 < 128 ; V_3 ++ ) {
V_12 = F_1 ( V_2 , V_3 , V_22 ) ;
if ( ! V_12 && F_11 ( V_34 , V_32 , NULL ) ) {
if ( V_36 >= 0 ) {
V_37 = V_3 - 1 ;
if ( ( V_37 - V_36 ) > V_35 ) {
V_38 = ( V_36 + V_37 ) >> 1 ;
V_35 = V_37 - V_36 ;
}
}
V_36 = - 1 ;
V_37 = 0 ;
continue;
}
if ( V_36 < 0 )
V_36 = V_3 ;
}
if ( V_36 >= 0 ) {
V_37 = V_3 - 1 ;
if ( ( V_37 - V_36 ) > V_35 ) {
V_38 = ( V_36 + V_37 ) >> 1 ;
V_35 = V_37 - V_36 ;
}
}
if ( V_38 < 0 )
return - V_29 ;
F_12 ( V_2 -> V_27 , L_2 , V_28 ,
V_36 , V_37 ) ;
return F_1 ( V_2 , V_38 , V_22 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
int V_12 ;
V_12 = F_1 ( V_2 , 32 , V_41 ) ;
if ( V_12 < 0 )
return - V_29 ;
return 0 ;
}
static int F_14 ( struct V_30 * V_31 , T_1 V_32 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
if ( V_2 -> V_42 == 0x290a )
return F_10 ( V_31 , V_32 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = V_2 -> V_27 -> V_45 ;
struct V_43 * V_46 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_12 ;
V_46 = F_16 ( V_44 , L_3 , 0 ) ;
if ( V_46 ) {
V_9 = F_17 ( V_46 ) ;
F_18 ( V_46 ) ;
if ( F_19 ( V_9 ) ) {
V_12 = F_20 ( V_9 ) ;
if ( V_12 != - V_47 )
F_9 ( V_2 -> V_27 , L_4 ,
V_12 ) ;
return V_12 ;
}
} else {
return 0 ;
}
V_7 = F_21 ( V_2 -> V_27 , sizeof( * V_7 ) , V_48 ) ;
if ( ! V_7 )
return - V_49 ;
V_7 -> V_9 = V_9 ;
V_2 -> V_7 = V_7 ;
return 0 ;
}
static int F_22 ( struct V_50 * V_51 )
{
const struct V_52 * V_53 ;
const struct V_54 * V_55 ;
V_55 = F_23 ( V_56 , V_51 -> V_27 . V_45 ) ;
V_53 = V_55 -> V_57 ;
return F_24 ( V_51 , V_53 ) ;
}

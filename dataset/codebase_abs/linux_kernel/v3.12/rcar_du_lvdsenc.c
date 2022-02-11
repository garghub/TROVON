static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
const struct V_8 * V_9 = & V_7 -> V_10 . V_9 ;
unsigned int V_11 = V_9 -> clock ;
T_1 V_12 ;
T_1 V_13 ;
int V_14 ;
if ( V_2 -> V_15 == V_16 )
return 0 ;
V_14 = F_4 ( V_2 -> clock ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_11 <= 38000 )
V_13 = V_17 | V_18 | V_19 ;
else if ( V_11 <= 60000 )
V_13 = V_17 | V_18 | V_20 ;
else if ( V_11 <= 121000 )
V_13 = V_17 | V_18 | V_21 ;
else
V_13 = V_22 ;
F_1 ( V_2 , V_23 , V_13 ) ;
F_1 ( V_2 , V_24 , V_25 |
V_26 | V_27 |
V_28 ) ;
F_1 ( V_2 , V_29 ,
F_5 ( 0 , 0 ) | F_5 ( 1 , 3 ) |
F_5 ( 2 , 2 ) | F_5 ( 3 , 1 ) ) ;
V_12 = V_30 | V_31 ;
if ( V_7 -> V_32 == 2 )
V_12 |= V_33 ;
F_1 ( V_2 , V_34 , V_12 ) ;
F_1 ( V_2 , V_35 , F_6 ( 3 ) | F_6 ( 2 ) |
F_6 ( 1 ) | F_6 ( 0 ) | V_36 ) ;
V_12 |= V_37 ;
F_1 ( V_2 , V_34 , V_12 ) ;
F_7 ( 100 , 150 ) ;
V_12 |= V_38 ;
F_1 ( V_2 , V_34 , V_12 ) ;
V_2 -> V_15 = V_16 ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
if ( V_2 -> V_15 == V_39 )
return;
F_1 ( V_2 , V_34 , 0 ) ;
F_1 ( V_2 , V_35 , 0 ) ;
F_9 ( V_2 -> clock ) ;
V_2 -> V_15 = V_39 ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_40 * V_10 , int V_9 )
{
if ( V_9 == V_39 ) {
F_8 ( V_2 ) ;
return 0 ;
} else if ( V_10 ) {
struct V_6 * V_7 = F_11 ( V_10 ) ;
return F_3 ( V_2 , V_7 ) ;
} else
return - V_41 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_44 * V_45 ;
char V_46 [ 7 ] ;
sprintf ( V_46 , L_1 , V_2 -> V_32 ) ;
V_45 = F_13 ( V_43 , V_47 , V_46 ) ;
if ( V_45 == NULL ) {
F_14 ( & V_43 -> V_48 , L_2 ,
V_46 ) ;
return - V_41 ;
}
V_2 -> V_5 = F_15 ( & V_43 -> V_48 , V_45 ) ;
if ( V_2 -> V_5 == NULL ) {
F_14 ( & V_43 -> V_48 , L_3 ,
V_46 ) ;
return - V_49 ;
}
V_2 -> clock = F_16 ( & V_43 -> V_48 , V_46 ) ;
if ( F_17 ( V_2 -> clock ) ) {
F_14 ( & V_43 -> V_48 , L_4 , V_46 ) ;
return F_18 ( V_2 -> clock ) ;
}
return 0 ;
}
int F_19 ( struct V_50 * V_51 )
{
struct V_42 * V_43 = F_20 ( V_51 -> V_48 ) ;
struct V_1 * V_2 ;
unsigned int V_52 ;
int V_14 ;
for ( V_52 = 0 ; V_52 < V_51 -> V_53 -> V_54 ; ++ V_52 ) {
V_2 = F_21 ( & V_43 -> V_48 , sizeof( * V_2 ) , V_55 ) ;
if ( V_2 == NULL ) {
F_14 ( & V_43 -> V_48 , L_5 ) ;
return - V_49 ;
}
V_2 -> V_48 = V_51 ;
V_2 -> V_32 = V_52 ;
V_2 -> V_56 = V_52 ? V_57 : V_58 ;
V_2 -> V_15 = V_39 ;
V_14 = F_12 ( V_2 , V_43 ) ;
if ( V_14 < 0 )
return V_14 ;
V_51 -> V_2 [ V_52 ] = V_2 ;
}
return 0 ;
}

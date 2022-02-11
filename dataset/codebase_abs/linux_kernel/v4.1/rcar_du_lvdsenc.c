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
T_1 V_14 ;
int V_15 ;
if ( V_2 -> V_16 )
return 0 ;
V_15 = F_4 ( V_2 -> clock ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_11 <= 38000 )
V_14 = V_17 | V_18 | V_19 ;
else if ( V_11 <= 60000 )
V_14 = V_17 | V_18 | V_20 ;
else if ( V_11 <= 121000 )
V_14 = V_17 | V_18 | V_21 ;
else
V_14 = V_22 ;
F_1 ( V_2 , V_23 , V_14 ) ;
F_1 ( V_2 , V_24 , V_25 |
V_26 | V_27 |
V_28 ) ;
if ( F_5 ( V_2 -> V_29 , V_30 ) )
V_13 = F_6 ( 0 , 0 ) | F_6 ( 1 , 3 )
| F_6 ( 2 , 2 ) | F_6 ( 3 , 1 ) ;
else
V_13 = F_6 ( 0 , 0 ) | F_6 ( 1 , 1 )
| F_6 ( 2 , 2 ) | F_6 ( 3 , 3 ) ;
F_1 ( V_2 , V_31 , V_13 ) ;
V_12 = V_32 | V_33 ;
if ( V_7 -> V_34 == 2 )
V_12 |= V_35 ;
F_1 ( V_2 , V_36 , V_12 ) ;
F_1 ( V_2 , V_37 , F_7 ( 3 ) | F_7 ( 2 ) |
F_7 ( 1 ) | F_7 ( 0 ) | V_38 ) ;
V_12 |= V_39 ;
F_1 ( V_2 , V_36 , V_12 ) ;
F_8 ( 100 , 150 ) ;
V_12 |= V_40 ;
F_1 ( V_2 , V_36 , V_12 ) ;
V_2 -> V_16 = true ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_16 )
return;
F_1 ( V_2 , V_36 , 0 ) ;
F_1 ( V_2 , V_37 , 0 ) ;
F_10 ( V_2 -> clock ) ;
V_2 -> V_16 = false ;
}
int F_11 ( struct V_1 * V_2 , struct V_41 * V_10 ,
bool V_42 )
{
if ( ! V_42 ) {
F_9 ( V_2 ) ;
return 0 ;
} else if ( V_10 ) {
struct V_6 * V_7 = F_12 ( V_10 ) ;
return F_3 ( V_2 , V_7 ) ;
} else
return - V_43 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
struct V_46 * V_47 ;
char V_48 [ 7 ] ;
sprintf ( V_48 , L_1 , V_2 -> V_34 ) ;
V_47 = F_14 ( V_45 , V_49 , V_48 ) ;
V_2 -> V_5 = F_15 ( & V_45 -> V_29 , V_47 ) ;
if ( F_16 ( V_2 -> V_5 ) )
return F_17 ( V_2 -> V_5 ) ;
V_2 -> clock = F_18 ( & V_45 -> V_29 , V_48 ) ;
if ( F_16 ( V_2 -> clock ) ) {
F_19 ( & V_45 -> V_29 , L_2 , V_48 ) ;
return F_17 ( V_2 -> clock ) ;
}
return 0 ;
}
int F_20 ( struct V_50 * V_51 )
{
struct V_44 * V_45 = F_21 ( V_51 -> V_29 ) ;
struct V_1 * V_2 ;
unsigned int V_52 ;
int V_15 ;
for ( V_52 = 0 ; V_52 < V_51 -> V_53 -> V_54 ; ++ V_52 ) {
V_2 = F_22 ( & V_45 -> V_29 , sizeof( * V_2 ) , V_55 ) ;
if ( V_2 == NULL ) {
F_19 ( & V_45 -> V_29 , L_3 ) ;
return - V_56 ;
}
V_2 -> V_29 = V_51 ;
V_2 -> V_34 = V_52 ;
V_2 -> V_57 = V_52 ? V_58 : V_59 ;
V_2 -> V_16 = false ;
V_15 = F_13 ( V_2 , V_45 ) ;
if ( V_15 < 0 )
return V_15 ;
V_51 -> V_2 [ V_52 ] = V_2 ;
}
return 0 ;
}

static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
const struct V_8 * V_9 = & V_7 -> V_10 . V_9 ;
unsigned int V_11 = V_9 -> clock ;
T_1 V_12 ;
T_1 V_13 ;
if ( V_11 < 39000 )
V_13 = V_14 | V_15 | V_16 ;
else if ( V_11 < 61000 )
V_13 = V_14 | V_15 | V_17 ;
else if ( V_11 < 121000 )
V_13 = V_14 | V_15 | V_18 ;
else
V_13 = V_19 ;
F_1 ( V_2 , V_20 , V_13 ) ;
V_12 = V_21 | V_22 ;
if ( V_7 -> V_23 == 2 )
V_12 |= V_24 ;
F_1 ( V_2 , V_25 , V_12 ) ;
F_1 ( V_2 , V_26 ,
F_4 ( 3 ) | F_4 ( 2 ) |
F_4 ( 1 ) | F_4 ( 0 ) |
V_27 ) ;
V_12 |= V_28 ;
F_1 ( V_2 , V_25 , V_12 ) ;
F_5 ( 100 , 150 ) ;
V_12 |= V_29 ;
F_1 ( V_2 , V_25 , V_12 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
const struct V_8 * V_9 = & V_7 -> V_10 . V_9 ;
unsigned int V_11 = V_9 -> clock ;
T_1 V_12 ;
T_1 V_13 ;
if ( V_11 < 42000 )
V_13 = V_30 ;
else if ( V_11 < 85000 )
V_13 = V_31 ;
else if ( V_11 < 128000 )
V_13 = V_32 ;
else
V_13 = V_33 ;
F_1 ( V_2 , V_20 , V_13 ) ;
F_1 ( V_2 , V_26 ,
F_7 ( 3 ) | F_7 ( 2 ) |
F_7 ( 1 ) | F_7 ( 0 ) |
V_34 ) ;
V_12 = V_28 ;
F_1 ( V_2 , V_25 , V_12 ) ;
V_12 |= V_35 ;
F_1 ( V_2 , V_25 , V_12 ) ;
F_5 ( 100 , 150 ) ;
V_12 |= V_29 ;
F_1 ( V_2 , V_25 , V_12 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
T_1 V_36 ;
int V_37 ;
if ( V_2 -> V_38 )
return 0 ;
V_37 = F_9 ( V_2 -> clock ) ;
if ( V_37 < 0 )
return V_37 ;
F_1 ( V_2 , V_39 , V_40 |
V_41 | V_42 |
V_43 ) ;
if ( F_10 ( V_2 -> V_44 , V_45 ) )
V_36 = F_11 ( 0 , 0 ) | F_11 ( 1 , 3 )
| F_11 ( 2 , 2 ) | F_11 ( 3 , 1 ) ;
else
V_36 = F_11 ( 0 , 0 ) | F_11 ( 1 , 1 )
| F_11 ( 2 , 2 ) | F_11 ( 3 , 3 ) ;
F_1 ( V_2 , V_46 , V_36 ) ;
if ( V_2 -> V_44 -> V_47 -> V_48 < 3 )
F_3 ( V_2 , V_7 ) ;
else
F_6 ( V_2 , V_7 ) ;
V_2 -> V_38 = true ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_38 )
return;
F_1 ( V_2 , V_25 , 0 ) ;
F_1 ( V_2 , V_26 , 0 ) ;
F_13 ( V_2 -> clock ) ;
V_2 -> V_38 = false ;
}
int F_14 ( struct V_1 * V_2 , struct V_49 * V_10 ,
bool V_50 )
{
if ( ! V_50 ) {
F_12 ( V_2 ) ;
return 0 ;
} else if ( V_10 ) {
struct V_6 * V_7 = F_15 ( V_10 ) ;
return F_8 ( V_2 , V_7 ) ;
} else
return - V_51 ;
}
void F_16 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_52 * V_53 = V_2 -> V_44 ;
if ( V_53 -> V_47 -> V_48 < 3 )
V_9 -> clock = F_17 ( V_9 -> clock , 30000 , 150000 ) ;
else
V_9 -> clock = F_17 ( V_9 -> clock , 25175 , 148500 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_56 * V_57 ;
char V_58 [ 7 ] ;
sprintf ( V_58 , L_1 , V_2 -> V_23 ) ;
V_57 = F_19 ( V_55 , V_59 , V_58 ) ;
V_2 -> V_5 = F_20 ( & V_55 -> V_44 , V_57 ) ;
if ( F_21 ( V_2 -> V_5 ) )
return F_22 ( V_2 -> V_5 ) ;
V_2 -> clock = F_23 ( & V_55 -> V_44 , V_58 ) ;
if ( F_21 ( V_2 -> clock ) ) {
F_24 ( & V_55 -> V_44 , L_2 , V_58 ) ;
return F_22 ( V_2 -> clock ) ;
}
return 0 ;
}
int F_25 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = F_26 ( V_53 -> V_44 ) ;
struct V_1 * V_2 ;
unsigned int V_60 ;
int V_37 ;
for ( V_60 = 0 ; V_60 < V_53 -> V_47 -> V_61 ; ++ V_60 ) {
V_2 = F_27 ( & V_55 -> V_44 , sizeof( * V_2 ) , V_62 ) ;
if ( V_2 == NULL )
return - V_63 ;
V_2 -> V_44 = V_53 ;
V_2 -> V_23 = V_60 ;
V_2 -> V_64 = V_60 ? V_65 : V_66 ;
V_2 -> V_38 = false ;
V_37 = F_18 ( V_2 , V_55 ) ;
if ( V_37 < 0 )
return V_37 ;
V_53 -> V_2 [ V_60 ] = V_2 ;
}
return 0 ;
}

static inline T_1 F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_6 * V_7 ,
int * V_8 , int * V_9 )
{
int V_10 ;
V_10 = ( F_6 ( ( V_8 [ 1 ] - V_8 [ 2 ] ) * 137 )
/ ( V_8 [ 0 ] - V_8 [ 2 ] ) ) - F_6 ( 41 ) ;
V_7 -> V_11 = F_7 ( F_6 ( V_9 [ 1 ] - V_9 [ 2 ] ) ,
V_10 - F_6 ( V_12 ) ) ;
V_7 -> V_13 = F_6 ( V_9 [ 2 ] ) - V_7 -> V_11 * V_12 ;
V_7 -> V_14 = F_7 ( F_6 ( V_9 [ 1 ] - V_9 [ 0 ] ) ,
V_10 - F_6 ( V_15 ) ) ;
V_7 -> V_16 = F_6 ( V_9 [ 0 ] ) - V_7 -> V_14 * V_15 ;
}
static int F_8 ( int V_17 )
{
int V_18 , V_19 ;
V_19 = V_17 >= 0 ? V_20 / 2 :
- V_20 / 2 ;
V_18 = ( V_17 + V_19 ) / V_20 ;
return V_18 * V_20 ;
}
static int F_9 ( void * V_21 , int * V_17 )
{
struct V_1 * V_2 = V_21 ;
int V_22 , V_23 , V_24 ;
T_1 V_3 ;
F_10 ( & V_2 -> V_25 ) ;
V_3 = F_1 ( V_2 , V_26 ) & V_27 ;
V_23 = F_7 ( F_6 ( V_3 ) - V_2 -> V_7 . V_13 , V_2 -> V_7 . V_11 ) ;
V_24 = F_7 ( F_6 ( V_3 ) - V_2 -> V_7 . V_16 , V_2 -> V_7 . V_14 ) ;
V_22 = F_11 ( ( V_23 + V_24 ) / 2 ) ;
F_12 ( & V_2 -> V_25 ) ;
if ( ( V_22 < F_13 ( - 40 ) ) || ( V_22 > F_13 ( 125 ) ) )
return - V_28 ;
* V_17 = F_8 ( V_22 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_29 , V_30 ) ;
F_3 ( V_2 , V_29 , 0x0 ) ;
F_15 ( 1000 , 2000 ) ;
F_3 ( V_2 , V_29 , V_31 ) ;
F_3 ( V_2 , V_32 , 0x3F ) ;
F_3 ( V_2 , V_29 ,
V_31 | V_33 | V_30 | V_34 ) ;
F_15 ( 100 , 200 ) ;
F_3 ( V_2 , V_29 ,
V_31 | V_33 | V_30 | V_34 |
V_35 | V_36 ) ;
F_15 ( 1000 , 2000 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_1 V_37 ;
V_37 = F_1 ( V_2 , V_38 ) ;
V_37 &= ~ V_39 ;
F_3 ( V_2 , V_38 , V_37 ) ;
F_15 ( 1000 , 2000 ) ;
F_3 ( V_2 , V_32 , 0x3F ) ;
V_37 = F_1 ( V_2 , V_38 ) ;
V_37 |= V_40 ;
F_3 ( V_2 , V_38 , V_37 ) ;
}
static int F_17 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = & V_42 -> V_44 ;
F_18 ( V_44 ) ;
F_19 ( V_44 ) ;
return 0 ;
}
static int F_20 ( struct V_41 * V_42 )
{
struct V_45 * V_46 ;
struct V_43 * V_44 = & V_42 -> V_44 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
int V_51 , V_52 ;
const struct V_53 * V_54 =
F_21 ( V_44 ) ;
int V_8 [ 3 ] = { 2351 , 1509 , 435 } ;
int V_9 [ V_55 ] [ 3 ] = {
{ 3248 , 2800 , 2221 } ,
{ 3245 , 2795 , 2216 } ,
{ 3250 , 2805 , 2237 } ,
} ;
V_46 = F_22 ( V_44 , sizeof( * V_46 ) , V_56 ) ;
if ( ! V_46 )
return - V_57 ;
F_23 ( V_42 , V_46 ) ;
F_24 ( V_44 ) ;
F_25 ( V_44 ) ;
for ( V_52 = 0 ; V_52 < V_55 ; V_52 ++ ) {
struct V_1 * V_2 ;
V_2 = F_22 ( V_44 , sizeof( * V_2 ) , V_56 ) ;
if ( ! V_2 ) {
V_51 = - V_57 ;
goto V_58;
}
V_48 = F_26 ( V_42 , V_59 , V_52 ) ;
if ( ! V_48 )
break;
V_2 -> V_4 = F_27 ( V_44 , V_48 ) ;
if ( F_28 ( V_2 -> V_4 ) ) {
V_51 = F_29 ( V_2 -> V_4 ) ;
goto V_58;
}
V_46 -> V_60 [ V_52 ] = V_2 ;
F_30 ( & V_2 -> V_25 ) ;
V_54 -> V_61 ( V_2 ) ;
F_5 ( & V_2 -> V_7 , V_8 , V_9 [ V_52 ] ) ;
V_50 = F_31 ( V_44 , V_52 , V_2 ,
& V_62 ) ;
if ( F_28 ( V_50 ) ) {
F_32 ( V_44 , L_1 ) ;
V_51 = F_29 ( V_50 ) ;
goto V_58;
}
V_2 -> V_50 = V_50 ;
}
return 0 ;
V_58:
F_17 ( V_42 ) ;
return V_51 ;
}

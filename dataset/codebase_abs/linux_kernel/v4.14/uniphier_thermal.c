static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
T_1 V_5 ;
T_1 V_6 [ 2 ] ;
int V_7 ;
F_2 ( V_4 , V_2 -> V_8 -> V_9 + V_10 ,
V_11 , 0 ) ;
V_7 = F_3 ( V_4 , V_2 -> V_8 -> V_12 + V_13 , & V_5 ) ;
if ( V_7 )
return V_7 ;
if ( ! V_5 ) {
V_7 = F_4 ( V_2 -> V_14 -> V_15 ,
L_1 ,
V_6 ,
F_5 ( V_6 ) ) ;
if ( V_7 )
return V_7 ;
F_6 ( V_4 , V_2 -> V_8 -> V_16 ,
V_17 | F_7 ( V_6 [ 0 ] ) |
V_18 | F_8 ( V_6 [ 1 ] ) ) ;
}
F_2 ( V_4 , V_2 -> V_8 -> V_9 + V_19 ,
V_20 , V_21 ) ;
F_2 ( V_4 , V_2 -> V_8 -> V_9 + V_22 ,
V_23 | V_24 ,
V_23 | V_25 ) ;
F_2 ( V_4 , V_2 -> V_8 -> V_12 + V_26 ,
V_27 , V_28 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_29 ,
T_1 V_30 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
F_2 ( V_4 , V_2 -> V_8 -> V_12 + V_31 + ( V_29 << 2 ) ,
V_32 | V_33 ,
V_32 |
F_10 ( V_30 / 1000 ) ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
int V_34 ;
T_1 V_35 = 0 ;
for ( V_34 = 0 ; V_34 < V_36 ; V_34 ++ )
if ( V_2 -> V_37 [ V_34 ] )
V_35 |= F_12 ( V_34 ) ;
F_2 ( V_4 , V_2 -> V_8 -> V_12 + V_38 ,
V_39 , V_35 ) ;
F_2 ( V_4 , V_2 -> V_8 -> V_9 + V_10 ,
V_11 , V_11 ) ;
F_13 ( 700 , 1500 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_3 ;
F_2 ( V_4 , V_2 -> V_8 -> V_12 + V_38 ,
V_39 , 0 ) ;
F_2 ( V_4 , V_2 -> V_8 -> V_9 + V_10 ,
V_11 , 0 ) ;
F_13 ( 1000 , 2000 ) ;
}
static int F_15 ( void * V_8 , int * V_40 )
{
struct V_1 * V_2 = V_8 ;
struct V_3 * V_4 = V_2 -> V_3 ;
int V_7 ;
T_1 V_30 ;
V_7 = F_3 ( V_4 , V_2 -> V_8 -> V_12 + V_41 , & V_30 ) ;
if ( V_7 )
return V_7 ;
* V_40 = F_16 ( V_30 , V_42 - 1 ) * 1000 ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_1 V_43 = 0 , V_35 = 0 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_36 ; V_34 ++ ) {
V_43 |= ( F_18 ( V_34 ) | F_19 ( V_34 ) ) ;
V_35 |= F_18 ( V_34 ) ;
}
F_2 ( V_2 -> V_3 ,
V_2 -> V_8 -> V_12 + V_38 , V_43 , V_35 ) ;
}
static T_2 F_20 ( int V_44 , void * V_45 )
{
struct V_1 * V_2 = V_45 ;
F_21 ( V_44 ) ;
F_17 ( V_2 ) ;
return V_46 ;
}
static T_2 F_22 ( int V_44 , void * V_45 )
{
struct V_1 * V_2 = V_45 ;
F_23 ( V_2 -> V_47 , V_48 ) ;
return V_49 ;
}
static int F_24 ( struct V_50 * V_51 )
{
struct V_52 * V_14 = & V_51 -> V_14 ;
struct V_3 * V_3 ;
struct V_53 * V_54 ;
struct V_1 * V_2 ;
const struct V_55 * V_56 ;
int V_34 , V_7 , V_44 , V_57 , V_58 = V_59 ;
V_2 = F_25 ( V_14 , sizeof( * V_2 ) , V_60 ) ;
if ( ! V_2 )
return - V_61 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_8 = F_26 ( V_14 ) ;
if ( F_27 ( ! V_2 -> V_8 ) )
return - V_62 ;
V_44 = F_28 ( V_51 , 0 ) ;
if ( V_44 < 0 )
return V_44 ;
V_54 = F_29 ( V_14 -> V_15 ) ;
V_3 = F_30 ( V_54 ) ;
F_31 ( V_54 ) ;
if ( F_32 ( V_3 ) ) {
F_33 ( V_14 , L_2 ,
F_34 ( V_3 ) ) ;
return F_34 ( V_3 ) ;
}
V_2 -> V_3 = V_3 ;
V_7 = F_1 ( V_2 ) ;
if ( V_7 ) {
F_33 ( V_14 , L_3 ) ;
return V_7 ;
}
V_7 = F_35 ( V_14 , V_44 , F_20 ,
F_22 ,
0 , L_4 , V_2 ) ;
if ( V_7 )
return V_7 ;
F_36 ( V_51 , V_2 ) ;
V_2 -> V_47 = F_37 ( V_14 , 0 , V_2 ,
& V_63 ) ;
if ( F_32 ( V_2 -> V_47 ) ) {
F_33 ( V_14 , L_5 ) ;
return F_34 ( V_2 -> V_47 ) ;
}
V_56 = F_38 ( V_2 -> V_47 ) ;
V_57 = F_39 ( V_2 -> V_47 ) ;
if ( V_57 > V_36 ) {
F_33 ( V_14 , L_6 ) ;
return - V_64 ;
}
for ( V_34 = 0 ; V_34 < V_57 ; V_34 ++ ) {
if ( V_56 [ V_34 ] . type == V_65 &&
V_56 [ V_34 ] . V_66 < V_58 )
V_58 = V_56 [ V_34 ] . V_66 ;
F_9 ( V_2 , V_34 , V_56 [ V_34 ] . V_66 ) ;
V_2 -> V_37 [ V_34 ] = true ;
}
if ( V_58 > V_67 ) {
F_33 ( V_14 , L_7 ,
V_67 ) ;
return - V_62 ;
}
F_11 ( V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_41 ( V_51 ) ;
F_14 ( V_2 ) ;
return 0 ;
}

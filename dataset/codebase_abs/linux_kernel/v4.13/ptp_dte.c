static void F_1 ( void T_1 * V_1 , T_2 V_2 )
{
T_3 V_3 , V_4 ;
V_3 = ( T_3 ) ( ( V_2 >> V_5 ) & V_6 ) ;
if ( V_3 != V_6 )
V_3 ++ ;
V_4 = ( T_3 ) ( ( ( V_2 >> V_7 ) & V_8 ) <<
V_9 ) ;
F_2 ( 0 , ( V_1 + V_10 ) ) ;
F_2 ( V_3 , ( V_1 + V_11 ) ) ;
F_2 ( V_4 , ( V_1 + V_12 ) ) ;
}
static T_2 F_3 ( void T_1 * V_1 )
{
T_3 V_3 , V_4 ;
T_2 V_2 ;
V_4 = F_4 ( V_1 + V_12 ) & V_8 ;
V_3 = F_4 ( V_1 + V_11 ) ;
V_2 = ( ( T_2 ) V_4 << V_7 ) |
( ( T_2 ) V_3 << V_5 ) ;
return V_2 ;
}
static void F_5 ( struct V_13 * V_13 , T_2 V_14 )
{
T_2 V_2 ;
V_2 = F_3 ( V_13 -> V_1 ) ;
if ( ( V_14 < 0 ) && ( abs ( V_14 ) > V_2 ) ) {
if ( V_13 -> V_15 ) {
V_2 += V_16 + V_14 ;
V_13 -> V_15 -- ;
} else {
V_2 = 0 ;
}
} else {
V_2 += V_14 ;
if ( V_2 > V_16 ) {
V_13 -> V_15 ++ ;
V_2 -= V_16 ;
}
}
F_1 ( V_13 -> V_1 , V_2 ) ;
V_13 -> V_17 = ( V_2 >> V_18 ) &
V_19 ;
}
static T_2 F_6 ( struct V_13 * V_13 )
{
T_3 V_20 ;
T_2 V_2 = 0 ;
V_2 = F_3 ( V_13 -> V_1 ) ;
V_20 = ( V_2 >> V_18 ) & V_19 ;
if ( V_20 < V_13 -> V_17 )
V_13 -> V_15 ++ ;
V_13 -> V_17 = V_20 ;
V_2 += ( T_2 ) ( F_7 ( V_21 ) * V_13 -> V_15 ) ;
return V_2 ;
}
static int F_8 ( struct V_22 * V_23 , T_4 V_24 )
{
T_3 V_25 ;
unsigned long V_26 ;
struct V_13 * V_13 = F_9 ( V_23 , struct V_13 , V_27 ) ;
if ( abs ( V_24 ) > V_13 -> V_27 . V_28 ) {
F_10 ( V_13 -> V_29 , L_1 ) ;
return - V_30 ;
}
if ( V_24 < 0 )
V_25 = V_31 - F_11 ( V_24 ) ;
else
V_25 = V_31 + F_11 ( V_24 ) ;
F_12 ( & V_13 -> V_32 , V_26 ) ;
F_2 ( V_25 , V_13 -> V_1 + V_33 ) ;
F_13 ( & V_13 -> V_32 , V_26 ) ;
return 0 ;
}
static int F_14 ( struct V_22 * V_23 , T_2 V_14 )
{
unsigned long V_26 ;
struct V_13 * V_13 = F_9 ( V_23 , struct V_13 , V_27 ) ;
F_12 ( & V_13 -> V_32 , V_26 ) ;
F_5 ( V_13 , V_14 ) ;
F_13 ( & V_13 -> V_32 , V_26 ) ;
return 0 ;
}
static int F_15 ( struct V_22 * V_23 , struct V_34 * V_35 )
{
unsigned long V_26 ;
struct V_13 * V_13 = F_9 ( V_23 , struct V_13 , V_27 ) ;
F_12 ( & V_13 -> V_32 , V_26 ) ;
* V_35 = F_16 ( F_6 ( V_13 ) ) ;
F_13 ( & V_13 -> V_32 , V_26 ) ;
return 0 ;
}
static int F_17 ( struct V_22 * V_23 ,
const struct V_34 * V_35 )
{
unsigned long V_26 ;
struct V_13 * V_13 = F_9 ( V_23 , struct V_13 , V_27 ) ;
F_12 ( & V_13 -> V_32 , V_26 ) ;
F_2 ( 0 , V_13 -> V_1 + V_33 ) ;
F_1 ( V_13 -> V_1 , F_18 ( V_35 ) ) ;
V_13 -> V_17 = 0 ;
V_13 -> V_15 = 0 ;
F_2 ( V_31 , V_13 -> V_1 + V_33 ) ;
F_13 ( & V_13 -> V_32 , V_26 ) ;
return 0 ;
}
static int F_19 ( struct V_22 * V_23 ,
struct V_36 * V_37 , int V_38 )
{
return - V_39 ;
}
static int F_20 ( struct V_40 * V_41 )
{
struct V_13 * V_13 ;
struct V_42 * V_29 = & V_41 -> V_29 ;
struct V_43 * V_44 ;
V_13 = F_21 ( V_29 , sizeof( struct V_13 ) , V_45 ) ;
if ( ! V_13 )
return - V_46 ;
V_44 = F_22 ( V_41 , V_47 , 0 ) ;
V_13 -> V_1 = F_23 ( V_29 , V_44 ) ;
if ( F_24 ( V_13 -> V_1 ) ) {
F_10 ( V_29 ,
L_2 , V_48 ) ;
return F_25 ( V_13 -> V_1 ) ;
}
F_26 ( & V_13 -> V_32 ) ;
V_13 -> V_29 = V_29 ;
V_13 -> V_27 = V_49 ;
V_13 -> V_50 = F_27 ( & V_13 -> V_27 , & V_41 -> V_29 ) ;
if ( F_24 ( V_13 -> V_50 ) ) {
F_10 ( V_29 ,
L_3 , V_48 ) ;
return F_25 ( V_13 -> V_50 ) ;
}
F_28 ( V_41 , V_13 ) ;
F_29 ( V_29 , L_4 ) ;
return 0 ;
}
static int F_30 ( struct V_40 * V_41 )
{
struct V_13 * V_13 = F_31 ( V_41 ) ;
T_5 V_51 ;
F_32 ( V_13 -> V_50 ) ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ )
F_2 ( 0 , V_13 -> V_1 + ( V_51 * sizeof( T_3 ) ) ) ;
return 0 ;
}
static int F_33 ( struct V_42 * V_29 )
{
struct V_40 * V_41 = F_34 ( V_29 ) ;
struct V_13 * V_13 = F_31 ( V_41 ) ;
T_5 V_51 ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ ) {
V_13 -> V_53 [ V_51 ] =
F_4 ( V_13 -> V_1 + ( V_51 * sizeof( T_3 ) ) ) ;
}
F_2 ( 0 , V_13 -> V_1 + V_33 ) ;
return 0 ;
}
static int F_35 ( struct V_42 * V_29 )
{
struct V_40 * V_41 = F_34 ( V_29 ) ;
struct V_13 * V_13 = F_31 ( V_41 ) ;
T_5 V_51 ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ ) {
if ( ( V_51 * sizeof( T_3 ) ) != V_12 )
F_2 ( V_13 -> V_53 [ V_51 ] ,
( V_13 -> V_1 + ( V_51 * sizeof( T_3 ) ) ) ) ;
else
F_2 ( ( ( V_13 -> V_53 [ V_51 ] &
V_8 ) << V_9 ) ,
( V_13 -> V_1 + ( V_51 * sizeof( T_3 ) ) ) ) ;
}
return 0 ;
}

static void F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
int V_5 ;
if ( ( V_2 -> V_6 % 2 ) == 0 )
V_2 -> V_7 = V_4 ;
else {
V_2 -> V_7 |= V_4 << 4 ;
V_5 = V_2 -> V_6 / 2 ;
if ( V_5 < F_2 ( V_2 -> V_8 ) )
V_2 -> V_8 [ V_5 ] = V_2 -> V_7 ;
}
V_2 -> V_6 ++ ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_9 ) ;
if ( V_2 -> V_6 % 2 )
F_1 ( V_2 , V_9 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_10 ) ;
F_1 ( V_2 , V_11 ) ;
F_1 ( V_2 , V_12 ) ;
F_1 ( V_2 , V_13 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_14 )
{
T_1 V_15 ;
V_15 = 0x80 ;
for ( V_15 = 0x80 ; V_15 > 0 ; V_15 >>= 1 )
F_1 ( V_2 , ( V_14 & V_15 ) ? V_16 : V_17 ) ;
F_1 ( V_2 , V_18 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_2 V_19 )
{
int V_20 , V_21 ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ ) {
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ )
F_1 ( V_2 , V_22 ) ;
F_1 ( V_2 , ( V_20 == V_19 - 1 ) ? V_16 : V_17 ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_12 ) ;
F_1 ( V_2 , V_11 ) ;
F_1 ( V_2 , V_10 ) ;
}
static void F_8 ( struct V_1 * V_2 , struct V_23 * V_24 , int V_25 )
{
int V_20 , V_21 ;
bool V_26 ;
V_2 -> V_6 = 0 ;
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ ) {
V_26 = ! ! ( V_24 [ V_20 ] . V_27 & V_28 ) ;
F_4 ( V_2 ) ;
F_5 ( V_2 , V_24 [ V_20 ] . V_29 << 1 | V_26 ) ;
if ( V_26 )
F_6 ( V_2 , V_24 [ V_20 ] . V_30 ) ;
else
for ( V_21 = 0 ; V_21 < V_24 [ V_20 ] . V_30 ; V_21 ++ )
F_5 ( V_2 , V_24 [ V_20 ] . V_31 [ V_21 ] ) ;
}
if ( V_25 > 0 ) {
F_7 ( V_2 ) ;
F_3 ( V_2 ) ;
}
}
static int F_9 ( struct V_32 * V_33 , T_2 * V_34 , int V_35 )
{
int V_20 ;
T_2 V_36 ;
for ( V_20 = 0 ; V_20 < V_35 ; V_20 ++ ) {
V_36 = F_10 ( V_33 -> V_37 [ 0 ] + V_38 ) ;
if ( ! ( V_36 & V_39 ) )
break;
F_11 ( 500 , 750 ) ;
}
if ( V_20 >= V_35 )
return - V_40 ;
if ( V_34 )
* V_34 = V_36 ;
return 0 ;
}
static int F_12 ( struct V_32 * V_33 , T_2 V_29 )
{
T_2 V_41 ;
if ( F_9 ( V_33 , NULL , 50 ) ) {
F_13 ( & V_33 -> V_42 -> V_43 , L_1 ,
V_44 ) ;
return - V_40 ;
}
F_14 ( V_45 | V_29 , V_33 -> V_37 [ 0 ] + V_46 ) ;
F_11 ( 200 , 300 ) ;
if ( F_9 ( V_33 , & V_41 , 500 ) || ( V_41 & V_47 ) ) {
F_13 ( & V_33 -> V_42 -> V_43 , L_2 , V_44 ) ;
return - V_40 ;
}
return 0 ;
}
int F_15 ( struct V_32 * V_33 )
{
F_10 ( V_33 -> V_37 [ 0 ] + V_38 ) ;
return F_12 ( V_33 , V_48 ) ;
}
int F_16 ( struct V_32 * V_33 )
{
F_11 ( 1000 , 2000 ) ;
return F_12 ( V_33 , V_49 ) ;
}
void F_17 ( struct V_32 * V_33 )
{
F_14 ( V_50 , V_33 -> V_37 [ 0 ] + V_46 ) ;
}
int
F_18 ( struct V_51 * V_52 , struct V_23 * V_24 , int V_25 )
{
struct V_32 * V_33 ;
struct V_1 * V_2 ;
int V_20 ;
void T_3 * V_53 ;
V_33 = F_19 ( V_52 ) ;
V_2 = V_33 -> V_54 ;
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ )
if ( V_24 [ V_20 ] . V_27 & V_55 ) {
F_13 ( & V_33 -> V_42 -> V_43 ,
L_3 ,
V_44 ) ;
return - V_56 ;
}
F_8 ( V_2 , V_24 , V_25 ) ;
F_20 ( V_33 -> V_37 [ 1 ] + V_57 + V_58 / 2 ,
V_2 -> V_8 , V_2 -> V_6 ) ;
if ( F_12 ( V_33 , V_58 ) < 0 )
return - V_40 ;
V_53 = V_33 -> V_37 [ 1 ] + V_57 ;
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ )
if ( ( V_24 [ V_20 ] . V_27 & V_28 ) && V_24 [ V_20 ] . V_30 > 0 ) {
F_21 ( V_24 [ V_20 ] . V_31 , V_53 , V_24 [ V_20 ] . V_30 ) ;
V_53 += V_24 [ V_20 ] . V_30 ;
}
return V_25 ;
}
T_2 F_22 ( struct V_51 * V_52 )
{
return V_59 ;
}

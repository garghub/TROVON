static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_8 , V_9 = F_3 ( V_2 -> V_10 * 2 ) ;
int V_11 ;
F_4 ( & V_7 -> V_12 ) ;
for ( V_11 = 0 ; V_11 < V_5 ; V_11 ++ ) {
V_8 = F_5 ( V_7 -> V_13 + V_14 ) ;
V_8 &= ~ ( 0xff << 8 ) ;
V_8 |= ( ( V_3 + V_11 ) << 8 ) ;
F_6 ( V_8 , V_7 -> V_13 + V_14 ) ;
V_8 = F_7 ( V_7 -> V_13 + V_14 ) ;
if ( V_4 & 0x1 )
V_8 |= V_15 ;
else
V_8 &= ~ V_15 ;
V_8 &= ~ V_9 ;
F_8 ( V_8 , V_7 -> V_13 + V_14 ) ;
V_8 = F_7 ( V_7 -> V_13 + V_14 ) ;
V_8 |= V_9 ;
F_8 ( V_8 , V_7 -> V_13 + V_14 ) ;
V_8 = F_7 ( V_7 -> V_13 + V_14 ) ;
V_8 &= ~ V_9 ;
F_8 ( V_8 , V_7 -> V_13 + V_14 ) ;
V_4 >>= 1 ;
}
F_9 ( & V_7 -> V_12 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_16 )
{
T_1 V_17 , V_18 ;
if ( ! V_2 -> V_19 )
return;
V_17 = V_20 | V_21 |
V_22 | V_23 ;
V_18 = F_5 ( V_2 -> V_19 ) ;
if ( V_16 )
V_18 |= V_17 ;
else
V_18 &= ~ V_17 ;
F_6 ( V_18 , V_2 -> V_19 ) ;
}
static int F_11 ( struct V_2 * V_24 )
{
struct V_1 * V_2 = F_12 ( V_24 ) ;
struct V_6 * V_4 = F_2 ( V_2 ) ;
int V_25 ;
V_25 = F_13 ( V_2 -> V_26 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_14 ( V_2 -> V_27 ) ;
if ( V_25 ) {
F_15 ( V_2 -> V_26 ) ;
return V_25 ;
}
F_1 ( V_2 , V_28 , 0x14 , 5 ) ;
F_1 ( V_2 , V_29 , V_4 -> V_30 , 2 ) ;
F_10 ( V_2 , 1 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_24 )
{
struct V_1 * V_2 = F_12 ( V_24 ) ;
F_10 ( V_2 , 0 ) ;
F_17 ( V_2 -> V_27 ) ;
F_15 ( V_2 -> V_26 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_24 )
{
struct V_1 * V_2 = F_12 ( V_24 ) ;
int V_25 = 0 ;
if ( V_2 -> V_31 )
V_25 = F_19 ( V_2 -> V_31 ) ;
return V_25 ;
}
static int F_20 ( struct V_2 * V_24 )
{
struct V_1 * V_2 = F_12 ( V_24 ) ;
if ( V_2 -> V_31 )
F_21 ( V_2 -> V_31 ) ;
return 0 ;
}
static struct V_2 * F_22 ( struct V_32 * V_33 ,
struct V_34 * args )
{
struct V_6 * V_4 = F_23 ( V_33 ) ;
if ( F_24 ( args -> args [ 0 ] == 0 || args -> args [ 0 ] >= V_4 -> V_35 ) )
return F_25 ( - V_36 ) ;
return V_4 -> V_37 [ args -> args [ 0 ] ] . V_2 ;
}
static int F_26 ( struct V_38 * V_39 )
{
struct V_6 * V_4 ;
struct V_32 * V_33 = & V_39 -> V_33 ;
struct V_40 * V_41 = V_33 -> V_42 ;
struct V_43 * V_43 ;
bool V_44 ;
struct V_45 * V_46 ;
int V_11 ;
V_4 = F_27 ( V_33 , sizeof( * V_4 ) , V_47 ) ;
if ( ! V_4 )
return - V_48 ;
F_28 ( & V_4 -> V_12 ) ;
if ( F_29 ( V_41 , L_1 ) )
V_4 -> V_35 = 2 ;
else
V_4 -> V_35 = 3 ;
if ( F_29 ( V_41 , L_2 ) )
V_4 -> V_30 = 3 ;
else
V_4 -> V_30 = 2 ;
if ( F_29 ( V_41 , L_3 ) )
V_44 = true ;
else
V_44 = false ;
V_46 = F_30 ( V_39 , V_49 , L_4 ) ;
V_4 -> V_13 = F_31 ( V_33 , V_46 ) ;
if ( F_32 ( V_4 -> V_13 ) )
return F_33 ( V_4 -> V_13 ) ;
for ( V_11 = 1 ; V_11 < V_4 -> V_35 ; V_11 ++ ) {
struct V_1 * V_2 = V_4 -> V_37 + V_11 ;
char V_50 [ 16 ] ;
snprintf ( V_50 , sizeof( V_50 ) , L_5 , V_11 ) ;
V_2 -> V_31 = F_34 ( V_33 , V_50 ) ;
if ( F_32 ( V_2 -> V_31 ) ) {
if ( F_33 ( V_2 -> V_31 ) == - V_51 )
return - V_51 ;
V_2 -> V_31 = NULL ;
}
if ( V_44 )
snprintf ( V_50 , sizeof( V_50 ) , L_6 , V_11 ) ;
else
F_35 ( V_50 , L_7 , sizeof( V_50 ) ) ;
V_2 -> V_26 = F_36 ( V_33 , V_50 ) ;
if ( F_32 ( V_2 -> V_26 ) ) {
F_37 ( V_33 , L_8 , V_50 ) ;
return F_33 ( V_2 -> V_26 ) ;
}
snprintf ( V_50 , sizeof( V_50 ) , L_9 , V_11 ) ;
V_2 -> V_27 = F_38 ( V_33 , V_50 ) ;
if ( F_32 ( V_2 -> V_27 ) ) {
F_37 ( V_33 , L_10 , V_50 ) ;
return F_33 ( V_2 -> V_27 ) ;
}
if ( V_11 ) {
snprintf ( V_50 , sizeof( V_50 ) , L_11 , V_11 ) ;
V_46 = F_30 ( V_39 ,
V_49 , V_50 ) ;
V_2 -> V_19 = F_31 ( V_33 , V_46 ) ;
if ( F_32 ( V_2 -> V_19 ) )
return F_33 ( V_2 -> V_19 ) ;
}
V_2 -> V_2 = F_39 ( V_33 , NULL , & V_52 , NULL ) ;
if ( F_32 ( V_2 -> V_2 ) ) {
F_37 ( V_33 , L_12 , V_11 ) ;
return F_33 ( V_2 -> V_2 ) ;
}
V_2 -> V_10 = V_11 ;
F_40 ( V_2 -> V_2 , & V_4 -> V_37 [ V_11 ] ) ;
}
F_41 ( V_33 , V_4 ) ;
V_43 = F_42 ( V_33 , F_22 ) ;
return F_43 ( V_43 ) ;
}

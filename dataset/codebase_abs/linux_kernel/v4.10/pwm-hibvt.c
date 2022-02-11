static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( void T_1 * V_4 , T_2 V_5 ,
T_2 V_6 , T_2 V_7 )
{
void T_1 * V_8 = V_4 + V_5 ;
T_2 V_9 ;
V_9 = F_4 ( V_8 ) ;
V_9 &= ~ V_6 ;
V_9 |= ( V_7 & V_6 ) ;
F_5 ( V_9 , V_8 ) ;
}
static void F_6 ( struct V_2 * V_3 , struct V_10 * V_11 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
F_3 ( V_12 -> V_4 , F_7 ( V_11 -> V_13 ) ,
V_14 , 0x1 ) ;
}
static void F_8 ( struct V_2 * V_3 , struct V_10 * V_11 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
F_3 ( V_12 -> V_4 , F_7 ( V_11 -> V_13 ) ,
V_14 , 0x0 ) ;
}
static void F_9 ( struct V_2 * V_3 , struct V_10 * V_11 ,
int V_15 , int V_16 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_2 V_17 , V_18 , V_19 ;
V_17 = F_10 ( F_11 ( V_12 -> V_20 ) , 1000000 ) ;
V_18 = F_10 ( V_17 * V_16 , 1000 ) ;
V_19 = F_10 ( V_18 * V_15 , V_16 ) ;
F_3 ( V_12 -> V_4 , F_12 ( V_11 -> V_13 ) ,
V_21 , V_18 ) ;
F_3 ( V_12 -> V_4 , F_13 ( V_11 -> V_13 ) ,
V_22 , V_19 ) ;
}
static void F_14 ( struct V_2 * V_3 ,
struct V_10 * V_11 ,
enum V_23 V_24 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
if ( V_24 == V_25 )
F_3 ( V_12 -> V_4 , F_7 ( V_11 -> V_13 ) ,
V_26 , ( 0x1 << V_27 ) ) ;
else
F_3 ( V_12 -> V_4 , F_7 ( V_11 -> V_13 ) ,
V_26 , ( 0x0 << V_27 ) ) ;
}
static void F_15 ( struct V_2 * V_3 , struct V_10 * V_11 ,
struct V_28 * V_29 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
void T_1 * V_4 ;
T_2 V_17 , V_9 ;
V_17 = F_10 ( F_11 ( V_12 -> V_20 ) , 1000000 ) ;
V_4 = V_12 -> V_4 ;
V_9 = F_4 ( V_4 + F_12 ( V_11 -> V_13 ) ) ;
V_29 -> V_18 = F_10 ( V_9 * 1000 , V_17 ) ;
V_9 = F_4 ( V_4 + F_13 ( V_11 -> V_13 ) ) ;
V_29 -> V_30 = F_10 ( V_9 * 1000 , V_17 ) ;
V_9 = F_4 ( V_4 + F_7 ( V_11 -> V_13 ) ) ;
V_29 -> V_31 = ( V_14 & V_9 ) ;
}
static int F_16 ( struct V_2 * V_3 , struct V_10 * V_11 ,
struct V_28 * V_29 )
{
if ( V_29 -> V_24 != V_11 -> V_29 . V_24 )
F_14 ( V_3 , V_11 , V_29 -> V_24 ) ;
if ( V_29 -> V_18 != V_11 -> V_29 . V_18 ||
V_29 -> V_30 != V_11 -> V_29 . V_30 )
F_9 ( V_3 , V_11 , V_29 -> V_30 , V_29 -> V_18 ) ;
if ( V_29 -> V_31 != V_11 -> V_29 . V_31 ) {
if ( V_29 -> V_31 )
F_6 ( V_3 , V_11 ) ;
else
F_8 ( V_3 , V_11 ) ;
}
return 0 ;
}
static int F_17 ( struct V_32 * V_33 )
{
const struct V_34 * V_35 =
F_18 ( & V_33 -> V_36 ) ;
struct V_1 * V_2 ;
struct V_37 * V_38 ;
int V_39 ;
int V_40 ;
V_2 = F_19 ( & V_33 -> V_36 , sizeof( * V_2 ) , V_41 ) ;
if ( V_2 == NULL )
return - V_42 ;
V_2 -> V_20 = F_20 ( & V_33 -> V_36 , NULL ) ;
if ( F_21 ( V_2 -> V_20 ) ) {
F_22 ( & V_33 -> V_36 , L_1 ,
F_23 ( V_2 -> V_20 ) ) ;
return F_23 ( V_2 -> V_20 ) ;
}
V_2 -> V_3 . V_43 = & V_44 ;
V_2 -> V_3 . V_36 = & V_33 -> V_36 ;
V_2 -> V_3 . V_4 = - 1 ;
V_2 -> V_3 . V_45 = V_35 -> V_46 ;
V_2 -> V_3 . V_47 = V_48 ;
V_2 -> V_3 . V_49 = 3 ;
V_38 = F_24 ( V_33 , V_50 , 0 ) ;
V_2 -> V_4 = F_25 ( & V_33 -> V_36 , V_38 ) ;
if ( F_21 ( V_2 -> V_4 ) )
return F_23 ( V_2 -> V_4 ) ;
V_39 = F_26 ( V_2 -> V_20 ) ;
if ( V_39 < 0 )
return V_39 ;
V_2 -> V_51 = F_27 ( & V_33 -> V_36 , NULL ) ;
if ( F_21 ( V_2 -> V_51 ) ) {
F_28 ( V_2 -> V_20 ) ;
return F_23 ( V_2 -> V_51 ) ;
}
F_29 ( V_2 -> V_51 ) ;
F_30 ( 30 ) ;
F_31 ( V_2 -> V_51 ) ;
V_39 = F_32 ( & V_2 -> V_3 ) ;
if ( V_39 < 0 ) {
F_28 ( V_2 -> V_20 ) ;
return V_39 ;
}
for ( V_40 = 0 ; V_40 < V_2 -> V_3 . V_45 ; V_40 ++ ) {
F_3 ( V_2 -> V_4 , F_7 ( V_40 ) ,
V_52 , ( 0x1 << V_53 ) ) ;
}
F_33 ( V_33 , V_2 ) ;
return 0 ;
}
static int F_34 ( struct V_32 * V_33 )
{
struct V_1 * V_2 ;
V_2 = F_35 ( V_33 ) ;
F_29 ( V_2 -> V_51 ) ;
F_30 ( 30 ) ;
F_31 ( V_2 -> V_51 ) ;
F_28 ( V_2 -> V_20 ) ;
return F_36 ( & V_2 -> V_3 ) ;
}

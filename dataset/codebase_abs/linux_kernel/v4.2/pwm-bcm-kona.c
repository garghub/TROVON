static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_1 * V_5 , unsigned int V_6 )
{
unsigned int V_7 = F_4 ( V_5 -> V_8 + V_9 ) ;
V_7 |= 1 << F_5 ( V_6 ) ;
V_7 &= ~ ( 1 << F_6 ( V_6 ) ) ;
F_7 ( V_7 , V_5 -> V_8 + V_9 ) ;
V_7 &= ~ ( 1 << F_5 ( V_6 ) ) ;
V_7 |= 1 << F_6 ( V_6 ) ;
F_7 ( V_7 , V_5 -> V_8 + V_9 ) ;
}
static int F_8 ( struct V_2 * V_4 , struct V_10 * V_11 ,
int V_12 , int V_13 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
T_1 V_14 , div , V_15 ;
unsigned long V_16 = V_17 , V_18 , V_19 ;
unsigned int V_7 , V_6 = V_11 -> V_20 ;
V_15 = F_9 ( V_5 -> V_21 ) ;
while ( 1 ) {
div = 1000000000 ;
div *= 1 + V_16 ;
V_14 = V_15 * V_13 ;
V_18 = F_10 ( V_14 , div ) ;
V_14 = V_15 * V_12 ;
V_19 = F_10 ( V_14 , div ) ;
if ( V_18 < V_22 || V_19 < V_23 )
return - V_24 ;
if ( V_18 <= V_25 && V_19 <= V_26 )
break;
if ( ++ V_16 > V_27 )
return - V_24 ;
}
if ( F_11 ( V_28 , & V_11 -> V_29 ) ) {
V_7 = F_4 ( V_5 -> V_8 + V_30 ) ;
V_7 &= ~ F_12 ( V_6 ) ;
V_7 |= V_16 << F_13 ( V_6 ) ;
F_7 ( V_7 , V_5 -> V_8 + V_30 ) ;
F_7 ( V_18 , V_5 -> V_8 + F_14 ( V_6 ) ) ;
F_7 ( V_19 , V_5 -> V_8 + F_15 ( V_6 ) ) ;
F_3 ( V_5 , V_6 ) ;
}
return 0 ;
}
static int F_16 ( struct V_2 * V_4 , struct V_10 * V_11 ,
enum V_31 V_32 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_6 = V_11 -> V_20 ;
unsigned int V_7 ;
int V_33 ;
V_33 = F_17 ( V_5 -> V_21 ) ;
if ( V_33 < 0 ) {
F_18 ( V_4 -> V_34 , L_1 , V_33 ) ;
return V_33 ;
}
V_7 = F_4 ( V_5 -> V_8 + V_9 ) ;
if ( V_32 == V_35 )
V_7 |= 1 << F_19 ( V_6 ) ;
else
V_7 &= ~ ( 1 << F_19 ( V_6 ) ) ;
F_7 ( V_7 , V_5 -> V_8 + V_9 ) ;
F_3 ( V_5 , V_6 ) ;
F_20 ( 400 ) ;
F_21 ( V_5 -> V_21 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_4 , struct V_10 * V_11 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_33 ;
V_33 = F_17 ( V_5 -> V_21 ) ;
if ( V_33 < 0 ) {
F_18 ( V_4 -> V_34 , L_1 , V_33 ) ;
return V_33 ;
}
V_33 = F_8 ( V_4 , V_11 , V_11 -> V_36 , V_11 -> V_37 ) ;
if ( V_33 < 0 ) {
F_21 ( V_5 -> V_21 ) ;
return V_33 ;
}
return 0 ;
}
static void F_23 ( struct V_2 * V_4 , struct V_10 * V_11 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_6 = V_11 -> V_20 ;
F_7 ( 0 , V_5 -> V_8 + F_15 ( V_6 ) ) ;
F_3 ( V_5 , V_6 ) ;
F_20 ( 400 ) ;
F_21 ( V_5 -> V_21 ) ;
}
static int F_24 ( struct V_38 * V_39 )
{
struct V_1 * V_5 ;
struct V_40 * V_41 ;
unsigned int V_6 ;
unsigned int V_7 = 0 ;
int V_33 = 0 ;
V_5 = F_25 ( & V_39 -> V_34 , sizeof( * V_5 ) , V_42 ) ;
if ( V_5 == NULL )
return - V_43 ;
F_26 ( V_39 , V_5 ) ;
V_5 -> V_4 . V_34 = & V_39 -> V_34 ;
V_5 -> V_4 . V_44 = & V_45 ;
V_5 -> V_4 . V_8 = - 1 ;
V_5 -> V_4 . V_46 = 6 ;
V_5 -> V_4 . V_47 = V_48 ;
V_5 -> V_4 . V_49 = 3 ;
V_5 -> V_4 . V_50 = true ;
V_41 = F_27 ( V_39 , V_51 , 0 ) ;
V_5 -> V_8 = F_28 ( & V_39 -> V_34 , V_41 ) ;
if ( F_29 ( V_5 -> V_8 ) )
return F_30 ( V_5 -> V_8 ) ;
V_5 -> V_21 = F_31 ( & V_39 -> V_34 , NULL ) ;
if ( F_29 ( V_5 -> V_21 ) ) {
F_18 ( & V_39 -> V_34 , L_2 ,
F_30 ( V_5 -> V_21 ) ) ;
return F_30 ( V_5 -> V_21 ) ;
}
V_33 = F_17 ( V_5 -> V_21 ) ;
if ( V_33 < 0 ) {
F_18 ( & V_39 -> V_34 , L_1 , V_33 ) ;
return V_33 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_4 . V_46 ; V_6 ++ )
V_7 |= ( 1 << F_32 ( V_6 ) ) ;
F_7 ( V_7 , V_5 -> V_8 + V_9 ) ;
F_21 ( V_5 -> V_21 ) ;
V_33 = F_33 ( & V_5 -> V_4 , V_52 ) ;
if ( V_33 < 0 )
F_18 ( & V_39 -> V_34 , L_3 , V_33 ) ;
return V_33 ;
}
static int F_34 ( struct V_38 * V_39 )
{
struct V_1 * V_5 = F_35 ( V_39 ) ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_4 . V_46 ; V_6 ++ )
if ( F_11 ( V_28 , & V_5 -> V_4 . V_53 [ V_6 ] . V_29 ) )
F_21 ( V_5 -> V_21 ) ;
return F_36 ( & V_5 -> V_4 ) ;
}

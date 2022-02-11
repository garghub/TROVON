static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_1 * V_5 ,
unsigned int V_6 )
{
unsigned int V_7 = F_4 ( V_5 -> V_8 + V_9 ) ;
V_7 |= 1 << F_5 ( V_6 ) ;
V_7 &= ~ ( 1 << F_6 ( V_6 ) ) ;
F_7 ( V_7 , V_5 -> V_8 + V_9 ) ;
F_8 ( 400 ) ;
}
static void F_9 ( struct V_1 * V_5 , unsigned int V_6 )
{
unsigned int V_7 = F_4 ( V_5 -> V_8 + V_9 ) ;
V_7 &= ~ ( 1 << F_5 ( V_6 ) ) ;
V_7 |= 1 << F_6 ( V_6 ) ;
F_7 ( V_7 , V_5 -> V_8 + V_9 ) ;
F_8 ( 400 ) ;
}
static int F_10 ( struct V_2 * V_4 , struct V_10 * V_11 ,
int V_12 , int V_13 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
T_1 V_14 , div , V_15 ;
unsigned long V_16 = V_17 , V_18 , V_19 ;
unsigned int V_7 , V_6 = V_11 -> V_20 ;
V_15 = F_11 ( V_5 -> V_21 ) ;
while ( 1 ) {
div = 1000000000 ;
div *= 1 + V_16 ;
V_14 = V_15 * V_13 ;
V_18 = F_12 ( V_14 , div ) ;
V_14 = V_15 * V_12 ;
V_19 = F_12 ( V_14 , div ) ;
if ( V_18 < V_22 || V_19 < V_23 )
return - V_24 ;
if ( V_18 <= V_25 && V_19 <= V_26 )
break;
if ( ++ V_16 > V_27 )
return - V_24 ;
}
if ( F_13 ( V_11 ) ) {
F_3 ( V_5 , V_6 ) ;
V_7 = F_4 ( V_5 -> V_8 + V_28 ) ;
V_7 &= ~ F_14 ( V_6 ) ;
V_7 |= V_16 << F_15 ( V_6 ) ;
F_7 ( V_7 , V_5 -> V_8 + V_28 ) ;
F_7 ( V_18 , V_5 -> V_8 + F_16 ( V_6 ) ) ;
F_7 ( V_19 , V_5 -> V_8 + F_17 ( V_6 ) ) ;
F_9 ( V_5 , V_6 ) ;
}
return 0 ;
}
static int F_18 ( struct V_2 * V_4 , struct V_10 * V_11 ,
enum V_29 V_30 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_6 = V_11 -> V_20 ;
unsigned int V_7 ;
int V_31 ;
V_31 = F_19 ( V_5 -> V_21 ) ;
if ( V_31 < 0 ) {
F_20 ( V_4 -> V_32 , L_1 , V_31 ) ;
return V_31 ;
}
F_3 ( V_5 , V_6 ) ;
V_7 = F_4 ( V_5 -> V_8 + V_9 ) ;
if ( V_30 == V_33 )
V_7 |= 1 << F_21 ( V_6 ) ;
else
V_7 &= ~ ( 1 << F_21 ( V_6 ) ) ;
F_7 ( V_7 , V_5 -> V_8 + V_9 ) ;
F_9 ( V_5 , V_6 ) ;
F_22 ( V_5 -> V_21 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_4 , struct V_10 * V_11 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_31 ;
V_31 = F_19 ( V_5 -> V_21 ) ;
if ( V_31 < 0 ) {
F_20 ( V_4 -> V_32 , L_1 , V_31 ) ;
return V_31 ;
}
V_31 = F_10 ( V_4 , V_11 , F_24 ( V_11 ) ,
F_25 ( V_11 ) ) ;
if ( V_31 < 0 ) {
F_22 ( V_5 -> V_21 ) ;
return V_31 ;
}
return 0 ;
}
static void F_26 ( struct V_2 * V_4 , struct V_10 * V_11 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
unsigned int V_6 = V_11 -> V_20 ;
unsigned int V_7 ;
F_3 ( V_5 , V_6 ) ;
F_7 ( 0 , V_5 -> V_8 + F_17 ( V_6 ) ) ;
F_7 ( 0 , V_5 -> V_8 + F_16 ( V_6 ) ) ;
V_7 = F_4 ( V_5 -> V_8 + V_28 ) ;
V_7 &= ~ F_14 ( V_6 ) ;
F_7 ( V_7 , V_5 -> V_8 + V_28 ) ;
F_9 ( V_5 , V_6 ) ;
F_22 ( V_5 -> V_21 ) ;
}
static int F_27 ( struct V_34 * V_35 )
{
struct V_1 * V_5 ;
struct V_36 * V_37 ;
unsigned int V_6 ;
unsigned int V_7 = 0 ;
int V_31 = 0 ;
V_5 = F_28 ( & V_35 -> V_32 , sizeof( * V_5 ) , V_38 ) ;
if ( V_5 == NULL )
return - V_39 ;
F_29 ( V_35 , V_5 ) ;
V_5 -> V_4 . V_32 = & V_35 -> V_32 ;
V_5 -> V_4 . V_40 = & V_41 ;
V_5 -> V_4 . V_8 = - 1 ;
V_5 -> V_4 . V_42 = 6 ;
V_5 -> V_4 . V_43 = V_44 ;
V_5 -> V_4 . V_45 = 3 ;
V_37 = F_30 ( V_35 , V_46 , 0 ) ;
V_5 -> V_8 = F_31 ( & V_35 -> V_32 , V_37 ) ;
if ( F_32 ( V_5 -> V_8 ) )
return F_33 ( V_5 -> V_8 ) ;
V_5 -> V_21 = F_34 ( & V_35 -> V_32 , NULL ) ;
if ( F_32 ( V_5 -> V_21 ) ) {
F_20 ( & V_35 -> V_32 , L_2 ,
F_33 ( V_5 -> V_21 ) ) ;
return F_33 ( V_5 -> V_21 ) ;
}
V_31 = F_19 ( V_5 -> V_21 ) ;
if ( V_31 < 0 ) {
F_20 ( & V_35 -> V_32 , L_1 , V_31 ) ;
return V_31 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_4 . V_42 ; V_6 ++ )
V_7 |= ( 1 << F_35 ( V_6 ) ) ;
F_7 ( V_7 , V_5 -> V_8 + V_9 ) ;
F_22 ( V_5 -> V_21 ) ;
V_31 = F_36 ( & V_5 -> V_4 , V_47 ) ;
if ( V_31 < 0 )
F_20 ( & V_35 -> V_32 , L_3 , V_31 ) ;
return V_31 ;
}
static int F_37 ( struct V_34 * V_35 )
{
struct V_1 * V_5 = F_38 ( V_35 ) ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_4 . V_42 ; V_6 ++ )
if ( F_13 ( & V_5 -> V_4 . V_48 [ V_6 ] ) )
F_22 ( V_5 -> V_21 ) ;
return F_39 ( & V_5 -> V_4 ) ;
}

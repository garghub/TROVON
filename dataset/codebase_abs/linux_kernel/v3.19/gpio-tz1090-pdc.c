static inline void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline unsigned int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 ,
unsigned int V_8 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_9 ;
int V_10 ;
F_7 ( V_10 ) ;
V_9 = F_3 ( V_2 , V_11 ) ;
V_9 |= F_8 ( V_8 ) ;
F_1 ( V_2 , V_11 , V_9 ) ;
F_9 ( V_10 ) ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 ,
unsigned int V_8 ,
int V_12 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_9 ;
int V_10 ;
F_7 ( V_10 ) ;
if ( V_8 < 6 ) {
V_9 = F_3 ( V_2 , V_13 ) ;
if ( V_12 )
V_9 |= F_8 ( V_8 ) ;
else
V_9 &= ~ F_8 ( V_8 ) ;
F_1 ( V_2 , V_13 , V_9 ) ;
}
V_9 = F_3 ( V_2 , V_11 ) ;
V_9 &= ~ F_8 ( V_8 ) ;
F_1 ( V_2 , V_11 , V_9 ) ;
F_9 ( V_10 ) ;
return 0 ;
}
static int F_11 ( struct V_6 * V_7 , unsigned int V_8 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
return F_3 ( V_2 , V_14 ) & F_8 ( V_8 ) ;
}
static void F_12 ( struct V_6 * V_7 , unsigned int V_8 ,
int V_12 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_9 ;
int V_10 ;
if ( V_8 >= 6 )
return;
F_7 ( V_10 ) ;
V_9 = F_3 ( V_2 , V_13 ) ;
if ( V_12 )
V_9 |= F_8 ( V_8 ) ;
else
V_9 &= ~ F_8 ( V_8 ) ;
F_1 ( V_2 , V_13 , V_9 ) ;
F_9 ( V_10 ) ;
}
static int F_13 ( struct V_6 * V_7 , unsigned int V_8 )
{
return F_14 ( V_7 -> V_15 + V_8 ) ;
}
static void F_15 ( struct V_6 * V_7 , unsigned int V_8 )
{
F_16 ( V_7 -> V_15 + V_8 ) ;
}
static int F_17 ( struct V_6 * V_7 , unsigned int V_8 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned int V_16 = V_8 - V_17 ;
int V_18 ;
if ( V_16 >= V_19 )
return - V_20 ;
V_18 = V_2 -> V_18 [ V_16 ] ;
if ( ! V_18 )
return - V_20 ;
return V_18 ;
}
static int F_18 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_25 . V_26 ;
struct V_27 * V_28 ;
struct V_1 * V_2 ;
unsigned int V_29 ;
if ( ! V_24 ) {
F_19 ( & V_22 -> V_25 , L_1 ) ;
return - V_30 ;
}
V_28 = F_20 ( V_22 , V_31 , 0 ) ;
if ( ! V_28 ) {
F_19 ( & V_22 -> V_25 , L_2 ) ;
return - V_30 ;
}
V_2 = F_21 ( & V_22 -> V_25 , sizeof( * V_2 ) , V_32 ) ;
if ( ! V_2 ) {
F_19 ( & V_22 -> V_25 , L_3 ) ;
return - V_33 ;
}
V_2 -> V_5 = F_22 ( & V_22 -> V_25 , V_28 -> V_34 ,
V_28 -> V_35 - V_28 -> V_34 ) ;
if ( ! V_2 -> V_5 ) {
F_19 ( & V_22 -> V_25 , L_4 ) ;
return - V_33 ;
}
V_2 -> V_7 . V_36 = L_5 ;
V_2 -> V_7 . V_25 = & V_22 -> V_25 ;
V_2 -> V_7 . V_37 = F_5 ;
V_2 -> V_7 . V_38 = F_10 ;
V_2 -> V_7 . V_39 = F_11 ;
V_2 -> V_7 . V_40 = F_12 ;
V_2 -> V_7 . free = F_15 ;
V_2 -> V_7 . V_41 = F_13 ;
V_2 -> V_7 . V_42 = F_17 ;
V_2 -> V_7 . V_26 = V_24 ;
V_2 -> V_7 . V_15 = V_43 ;
V_2 -> V_7 . V_44 = V_45 ;
for ( V_29 = 0 ; V_29 < V_19 ; ++ V_29 )
V_2 -> V_18 [ V_29 ] = F_23 ( V_24 , V_29 ) ;
F_24 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int T_2 F_25 ( void )
{
return F_26 ( & V_46 ) ;
}

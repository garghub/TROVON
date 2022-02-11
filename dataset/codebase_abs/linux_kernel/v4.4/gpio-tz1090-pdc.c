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
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned int V_15 = V_8 - V_16 ;
int V_17 ;
if ( V_15 >= V_18 )
return - V_19 ;
V_17 = V_2 -> V_17 [ V_15 ] ;
if ( ! V_17 )
return - V_19 ;
return V_17 ;
}
static int F_14 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 . V_25 ;
struct V_26 * V_27 ;
struct V_1 * V_2 ;
unsigned int V_28 ;
if ( ! V_23 ) {
F_15 ( & V_21 -> V_24 , L_1 ) ;
return - V_29 ;
}
V_27 = F_16 ( V_21 , V_30 , 0 ) ;
if ( ! V_27 ) {
F_15 ( & V_21 -> V_24 , L_2 ) ;
return - V_29 ;
}
V_2 = F_17 ( & V_21 -> V_24 , sizeof( * V_2 ) , V_31 ) ;
if ( ! V_2 ) {
F_15 ( & V_21 -> V_24 , L_3 ) ;
return - V_32 ;
}
V_2 -> V_5 = F_18 ( & V_21 -> V_24 , V_27 -> V_33 ,
F_19 ( V_27 ) ) ;
if ( ! V_2 -> V_5 ) {
F_15 ( & V_21 -> V_24 , L_4 ) ;
return - V_32 ;
}
V_2 -> V_7 . V_34 = L_5 ;
V_2 -> V_7 . V_24 = & V_21 -> V_24 ;
V_2 -> V_7 . V_35 = F_5 ;
V_2 -> V_7 . V_36 = F_10 ;
V_2 -> V_7 . V_37 = F_11 ;
V_2 -> V_7 . V_38 = F_12 ;
V_2 -> V_7 . free = V_39 ;
V_2 -> V_7 . V_40 = V_41 ;
V_2 -> V_7 . V_42 = F_13 ;
V_2 -> V_7 . V_25 = V_23 ;
V_2 -> V_7 . V_43 = V_44 ;
V_2 -> V_7 . V_45 = V_46 ;
for ( V_28 = 0 ; V_28 < V_18 ; ++ V_28 )
V_2 -> V_17 [ V_28 ] = F_20 ( V_23 , V_28 ) ;
F_21 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int T_2 F_22 ( void )
{
return F_23 ( & V_47 ) ;
}

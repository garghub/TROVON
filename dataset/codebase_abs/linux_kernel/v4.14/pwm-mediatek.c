static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_7 ;
V_7 = F_4 ( V_6 -> V_8 [ V_9 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_4 ( V_6 -> V_8 [ V_10 ] ) ;
if ( V_7 < 0 )
goto V_11;
V_7 = F_4 ( V_6 -> V_8 [ V_12 + V_5 -> V_13 ] ) ;
if ( V_7 < 0 )
goto V_14;
return 0 ;
V_14:
F_5 ( V_6 -> V_8 [ V_10 ] ) ;
V_11:
F_5 ( V_6 -> V_8 [ V_9 ] ) ;
return V_7 ;
}
static void F_6 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_5 ( V_6 -> V_8 [ V_12 + V_5 -> V_13 ] ) ;
F_5 ( V_6 -> V_8 [ V_10 ] ) ;
F_5 ( V_6 -> V_8 [ V_9 ] ) ;
}
static inline T_1 F_7 ( struct V_1 * V_3 , unsigned int V_15 ,
unsigned int V_16 )
{
return F_8 ( V_3 -> V_17 + 0x10 + ( V_15 * 0x40 ) + V_16 ) ;
}
static inline void F_9 ( struct V_1 * V_3 ,
unsigned int V_15 , unsigned int V_16 ,
T_1 V_18 )
{
F_10 ( V_18 , V_3 -> V_17 + 0x10 + ( V_15 * 0x40 ) + V_16 ) ;
}
static int F_11 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_19 , int V_20 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_21 * V_21 = V_6 -> V_8 [ V_12 + V_5 -> V_13 ] ;
T_1 V_22 , V_23 = 0 ;
int V_7 ;
V_7 = F_3 ( V_3 , V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
V_22 = V_24 / F_12 ( V_21 ) ;
while ( V_20 / V_22 > 8191 ) {
V_22 *= 2 ;
V_23 ++ ;
}
if ( V_23 > V_25 ) {
F_6 ( V_3 , V_5 ) ;
F_13 ( V_3 -> V_26 , L_1 , V_20 ) ;
return - V_27 ;
}
F_9 ( V_6 , V_5 -> V_13 , V_28 , F_14 ( 15 ) | V_23 ) ;
F_9 ( V_6 , V_5 -> V_13 , V_29 , V_20 / V_22 ) ;
F_9 ( V_6 , V_5 -> V_13 , V_30 , V_19 / V_22 ) ;
F_6 ( V_3 , V_5 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_18 ;
int V_7 ;
V_7 = F_3 ( V_3 , V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
V_18 = F_8 ( V_6 -> V_17 ) ;
V_18 |= F_14 ( V_5 -> V_13 ) ;
F_10 ( V_18 , V_6 -> V_17 ) ;
return 0 ;
}
static void F_16 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_18 ;
V_18 = F_8 ( V_6 -> V_17 ) ;
V_18 &= ~ F_14 ( V_5 -> V_13 ) ;
F_10 ( V_18 , V_6 -> V_17 ) ;
F_6 ( V_3 , V_5 ) ;
}
static int F_17 ( struct V_31 * V_32 )
{
struct V_1 * V_6 ;
struct V_33 * V_34 ;
unsigned int V_35 ;
int V_7 ;
V_6 = F_18 ( & V_32 -> V_26 , sizeof( * V_6 ) , V_36 ) ;
if ( ! V_6 )
return - V_37 ;
V_34 = F_19 ( V_32 , V_38 , 0 ) ;
V_6 -> V_17 = F_20 ( & V_32 -> V_26 , V_34 ) ;
if ( F_21 ( V_6 -> V_17 ) )
return F_22 ( V_6 -> V_17 ) ;
for ( V_35 = 0 ; V_35 < V_39 ; V_35 ++ ) {
V_6 -> V_8 [ V_35 ] = F_23 ( & V_32 -> V_26 , V_40 [ V_35 ] ) ;
if ( F_21 ( V_6 -> V_8 [ V_35 ] ) )
return F_22 ( V_6 -> V_8 [ V_35 ] ) ;
}
F_24 ( V_32 , V_6 ) ;
V_6 -> V_3 . V_26 = & V_32 -> V_26 ;
V_6 -> V_3 . V_41 = & V_42 ;
V_6 -> V_3 . V_43 = - 1 ;
V_6 -> V_3 . V_44 = 5 ;
V_7 = F_25 ( & V_6 -> V_3 ) ;
if ( V_7 < 0 ) {
F_13 ( & V_32 -> V_26 , L_2 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_26 ( struct V_31 * V_32 )
{
struct V_1 * V_6 = F_27 ( V_32 ) ;
return F_28 ( & V_6 -> V_3 ) ;
}

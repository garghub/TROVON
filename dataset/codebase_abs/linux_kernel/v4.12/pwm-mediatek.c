static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_3 , unsigned int V_4 ,
unsigned int V_5 )
{
return F_4 ( V_3 -> V_6 + 0x10 + ( V_4 * 0x40 ) + V_5 ) ;
}
static inline void F_5 ( struct V_1 * V_3 ,
unsigned int V_4 , unsigned int V_5 ,
T_1 V_7 )
{
F_6 ( V_7 , V_3 -> V_6 + 0x10 + ( V_4 * 0x40 ) + V_5 ) ;
}
static int F_7 ( struct V_2 * V_3 , struct V_8 * V_9 ,
int V_10 , int V_11 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_13 * V_13 = V_12 -> V_14 [ V_15 + V_9 -> V_16 ] ;
T_1 V_17 , V_18 = 0 ;
V_17 = V_19 / F_8 ( V_13 ) ;
while ( V_11 / V_17 > 8191 ) {
V_17 *= 2 ;
V_18 ++ ;
}
if ( V_18 > 7 )
return - V_20 ;
F_5 ( V_12 , V_9 -> V_16 , V_21 , F_9 ( 15 ) | F_9 ( 3 ) | V_18 ) ;
F_5 ( V_12 , V_9 -> V_16 , V_22 , V_11 / V_17 ) ;
F_5 ( V_12 , V_9 -> V_16 , V_23 , V_10 / V_17 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_1 V_7 ;
int V_24 ;
V_24 = F_11 ( V_12 -> V_14 [ V_15 + V_9 -> V_16 ] ) ;
if ( V_24 < 0 )
return V_24 ;
V_7 = F_4 ( V_12 -> V_6 ) ;
V_7 |= F_9 ( V_9 -> V_16 ) ;
F_6 ( V_7 , V_12 -> V_6 ) ;
return 0 ;
}
static void F_12 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_1 V_7 ;
V_7 = F_4 ( V_12 -> V_6 ) ;
V_7 &= ~ F_9 ( V_9 -> V_16 ) ;
F_6 ( V_7 , V_12 -> V_6 ) ;
F_13 ( V_12 -> V_14 [ V_15 + V_9 -> V_16 ] ) ;
}
static int F_14 ( struct V_25 * V_26 )
{
struct V_1 * V_12 ;
struct V_27 * V_28 ;
unsigned int V_29 ;
int V_24 ;
V_12 = F_15 ( & V_26 -> V_30 , sizeof( * V_12 ) , V_31 ) ;
if ( ! V_12 )
return - V_32 ;
V_28 = F_16 ( V_26 , V_33 , 0 ) ;
V_12 -> V_6 = F_17 ( & V_26 -> V_30 , V_28 ) ;
if ( F_18 ( V_12 -> V_6 ) )
return F_19 ( V_12 -> V_6 ) ;
for ( V_29 = 0 ; V_29 < V_34 ; V_29 ++ ) {
V_12 -> V_14 [ V_29 ] = F_20 ( & V_26 -> V_30 , V_35 [ V_29 ] ) ;
if ( F_18 ( V_12 -> V_14 [ V_29 ] ) )
return F_19 ( V_12 -> V_14 [ V_29 ] ) ;
}
V_24 = F_11 ( V_12 -> V_14 [ V_36 ] ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_11 ( V_12 -> V_14 [ V_37 ] ) ;
if ( V_24 < 0 )
goto V_38;
F_21 ( V_26 , V_12 ) ;
V_12 -> V_3 . V_30 = & V_26 -> V_30 ;
V_12 -> V_3 . V_39 = & V_40 ;
V_12 -> V_3 . V_41 = - 1 ;
V_12 -> V_3 . V_42 = 5 ;
V_24 = F_22 ( & V_12 -> V_3 ) ;
if ( V_24 < 0 ) {
F_23 ( & V_26 -> V_30 , L_1 , V_24 ) ;
goto V_43;
}
return 0 ;
V_43:
F_13 ( V_12 -> V_14 [ V_37 ] ) ;
V_38:
F_13 ( V_12 -> V_14 [ V_36 ] ) ;
return V_24 ;
}
static int F_24 ( struct V_25 * V_26 )
{
struct V_1 * V_12 = F_25 ( V_26 ) ;
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < V_12 -> V_3 . V_42 ; V_29 ++ )
F_26 ( & V_12 -> V_3 . V_44 [ V_29 ] ) ;
return F_27 ( & V_12 -> V_3 ) ;
}

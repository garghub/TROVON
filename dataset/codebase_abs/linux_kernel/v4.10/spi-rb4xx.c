static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_6 , int V_5 )
{
T_1 V_7 ;
V_7 = V_6 ;
if ( V_5 & F_6 ( 0 ) )
V_7 |= V_8 ;
F_3 ( V_2 , V_9 , V_7 ) ;
F_3 ( V_2 , V_9 , V_7 | V_10 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_6 , T_2 V_11 )
{
int V_12 ;
for ( V_12 = 7 ; V_12 >= 0 ; V_12 -- )
F_5 ( V_2 , V_6 , V_11 >> V_12 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , T_1 V_6 ,
T_2 V_5 )
{
T_1 V_7 ;
V_7 = V_6 ;
if ( V_5 & F_6 ( 1 ) )
V_7 |= V_8 ;
if ( V_5 & F_6 ( 0 ) )
V_7 |= V_13 ;
F_3 ( V_2 , V_9 , V_7 ) ;
F_3 ( V_2 , V_9 , V_7 | V_10 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_6 , T_2 V_11 )
{
F_8 ( V_2 , V_6 , V_11 >> 6 ) ;
F_8 ( V_2 , V_6 , V_11 >> 4 ) ;
F_8 ( V_2 , V_6 , V_11 >> 2 ) ;
F_8 ( V_2 , V_6 , V_11 >> 0 ) ;
}
static void F_10 ( struct V_14 * V_15 , bool V_16 )
{
struct V_1 * V_2 = F_11 ( V_15 -> V_17 ) ;
if ( V_16 )
F_3 ( V_2 , V_9 ,
V_18 | V_19 ) ;
}
static int F_12 ( struct V_20 * V_17 ,
struct V_14 * V_15 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_11 ( V_17 ) ;
int V_12 ;
T_1 V_6 ;
T_2 * V_23 ;
const T_2 * V_24 ;
if ( V_15 -> V_25 == 2 )
V_6 = V_18 ;
else
V_6 = V_19 ;
V_24 = V_22 -> V_24 ;
V_23 = V_22 -> V_23 ;
for ( V_12 = 0 ; V_12 < V_22 -> V_26 ; ++ V_12 ) {
if ( V_22 -> V_27 == V_28 )
F_9 ( V_2 , V_6 , V_24 [ V_12 ] ) ;
else
F_7 ( V_2 , V_6 , V_24 [ V_12 ] ) ;
if ( ! V_23 )
continue;
V_23 [ V_12 ] = F_1 ( V_2 , V_29 ) ;
}
F_13 ( V_17 ) ;
return 0 ;
}
static int F_14 ( struct V_30 * V_31 )
{
struct V_20 * V_17 ;
struct V_32 * V_33 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
int V_36 ;
void T_3 * V_37 ;
V_35 = F_15 ( V_31 , V_38 , 0 ) ;
V_37 = F_16 ( & V_31 -> V_39 , V_35 ) ;
if ( F_17 ( V_37 ) )
return F_18 ( V_37 ) ;
V_17 = F_19 ( & V_31 -> V_39 , sizeof( * V_2 ) ) ;
if ( ! V_17 )
return - V_40 ;
V_33 = F_20 ( & V_31 -> V_39 , L_1 ) ;
if ( F_17 ( V_33 ) )
return F_18 ( V_33 ) ;
V_17 -> V_41 = 0 ;
V_17 -> V_42 = 3 ;
V_17 -> V_43 = V_44 ;
V_17 -> V_45 = F_6 ( 7 ) ;
V_17 -> V_46 = V_47 ;
V_17 -> V_48 = F_12 ;
V_17 -> V_49 = F_10 ;
V_36 = F_21 ( & V_31 -> V_39 , V_17 ) ;
if ( V_36 ) {
F_22 ( & V_31 -> V_39 , L_2 ) ;
return V_36 ;
}
V_36 = F_23 ( V_33 ) ;
if ( V_36 )
return V_36 ;
V_2 = F_11 ( V_17 ) ;
V_2 -> V_4 = V_37 ;
V_2 -> V_32 = V_33 ;
F_24 ( V_31 , V_2 ) ;
F_3 ( V_2 , V_50 , V_51 ) ;
return 0 ;
}
static int F_25 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_26 ( V_31 ) ;
F_27 ( V_2 -> V_32 ) ;
return 0 ;
}

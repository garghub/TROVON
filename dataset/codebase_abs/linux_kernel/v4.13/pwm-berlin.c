static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_3 ,
unsigned int V_4 , unsigned long V_5 )
{
return F_4 ( V_3 -> V_6 + V_4 * 0x10 + V_5 ) ;
}
static inline void F_5 ( struct V_1 * V_3 ,
unsigned int V_4 , T_1 V_7 ,
unsigned long V_5 )
{
F_6 ( V_7 , V_3 -> V_6 + V_4 * 0x10 + V_5 ) ;
}
static int F_7 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_10 * V_4 ;
V_4 = F_8 ( sizeof( * V_4 ) , V_11 ) ;
if ( ! V_4 )
return - V_12 ;
return F_9 ( V_9 , V_4 ) ;
}
static void F_10 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_10 * V_4 = F_11 ( V_9 ) ;
F_9 ( V_9 , NULL ) ;
F_12 ( V_4 ) ;
}
static int F_13 ( struct V_2 * V_3 , struct V_8 * V_13 ,
int V_14 , int V_15 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
unsigned int V_16 ;
T_1 V_7 , V_17 , V_18 ;
T_2 V_19 , V_20 ;
V_19 = F_14 ( V_9 -> V_21 ) ;
V_19 *= V_15 ;
F_15 ( V_19 , V_22 ) ;
for ( V_16 = 0 ; V_16 < F_16 ( V_23 ) ; V_16 ++ ) {
V_20 = V_19 ;
F_15 ( V_20 , V_23 [ V_16 ] ) ;
if ( V_20 <= V_24 )
break;
}
if ( V_20 > V_24 )
return - V_25 ;
V_18 = V_20 ;
V_19 = V_20 * V_14 ;
F_15 ( V_19 , V_15 ) ;
V_17 = V_19 ;
V_7 = F_3 ( V_9 , V_13 -> V_26 , V_27 ) ;
V_7 &= ~ V_28 ;
V_7 |= V_16 ;
F_5 ( V_9 , V_13 -> V_26 , V_7 , V_27 ) ;
F_5 ( V_9 , V_13 -> V_26 , V_17 , V_29 ) ;
F_5 ( V_9 , V_13 -> V_26 , V_18 , V_30 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_8 * V_13 ,
enum V_31 V_32 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
T_1 V_7 ;
V_7 = F_3 ( V_9 , V_13 -> V_26 , V_27 ) ;
if ( V_32 == V_33 )
V_7 &= ~ V_34 ;
else
V_7 |= V_34 ;
F_5 ( V_9 , V_13 -> V_26 , V_7 , V_27 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 , struct V_8 * V_13 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
T_1 V_7 ;
V_7 = F_3 ( V_9 , V_13 -> V_26 , V_35 ) ;
V_7 |= V_36 ;
F_5 ( V_9 , V_13 -> V_26 , V_7 , V_35 ) ;
return 0 ;
}
static void F_19 ( struct V_2 * V_3 ,
struct V_8 * V_13 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
T_1 V_7 ;
V_7 = F_3 ( V_9 , V_13 -> V_26 , V_35 ) ;
V_7 &= ~ V_36 ;
F_5 ( V_9 , V_13 -> V_26 , V_7 , V_35 ) ;
}
static int F_20 ( struct V_37 * V_38 )
{
struct V_1 * V_9 ;
struct V_39 * V_40 ;
int V_41 ;
V_9 = F_21 ( & V_38 -> V_42 , sizeof( * V_9 ) , V_11 ) ;
if ( ! V_9 )
return - V_12 ;
V_40 = F_22 ( V_38 , V_43 , 0 ) ;
V_9 -> V_6 = F_23 ( & V_38 -> V_42 , V_40 ) ;
if ( F_24 ( V_9 -> V_6 ) )
return F_25 ( V_9 -> V_6 ) ;
V_9 -> V_21 = F_26 ( & V_38 -> V_42 , NULL ) ;
if ( F_24 ( V_9 -> V_21 ) )
return F_25 ( V_9 -> V_21 ) ;
V_41 = F_27 ( V_9 -> V_21 ) ;
if ( V_41 )
return V_41 ;
V_9 -> V_3 . V_42 = & V_38 -> V_42 ;
V_9 -> V_3 . V_44 = & V_45 ;
V_9 -> V_3 . V_6 = - 1 ;
V_9 -> V_3 . V_46 = 4 ;
V_9 -> V_3 . V_47 = V_48 ;
V_9 -> V_3 . V_49 = 3 ;
V_41 = F_28 ( & V_9 -> V_3 ) ;
if ( V_41 < 0 ) {
F_29 ( & V_38 -> V_42 , L_1 , V_41 ) ;
F_30 ( V_9 -> V_21 ) ;
return V_41 ;
}
F_31 ( V_38 , V_9 ) ;
return 0 ;
}
static int F_32 ( struct V_37 * V_38 )
{
struct V_1 * V_9 = F_33 ( V_38 ) ;
int V_41 ;
V_41 = F_34 ( & V_9 -> V_3 ) ;
F_30 ( V_9 -> V_21 ) ;
return V_41 ;
}
static int F_35 ( struct V_50 * V_42 )
{
struct V_1 * V_9 = F_36 ( V_42 ) ;
unsigned int V_51 ;
for ( V_51 = 0 ; V_51 < V_9 -> V_3 . V_46 ; V_51 ++ ) {
struct V_10 * V_4 ;
V_4 = F_11 ( & V_9 -> V_3 . V_52 [ V_51 ] ) ;
if ( ! V_4 )
continue;
V_4 -> V_53 = F_3 ( V_9 , V_51 , V_36 ) ;
V_4 -> V_54 = F_3 ( V_9 , V_51 , V_27 ) ;
V_4 -> V_17 = F_3 ( V_9 , V_51 , V_29 ) ;
V_4 -> V_55 = F_3 ( V_9 , V_51 , V_30 ) ;
}
F_30 ( V_9 -> V_21 ) ;
return 0 ;
}
static int F_37 ( struct V_50 * V_42 )
{
struct V_1 * V_9 = F_36 ( V_42 ) ;
unsigned int V_51 ;
int V_41 ;
V_41 = F_27 ( V_9 -> V_21 ) ;
if ( V_41 )
return V_41 ;
for ( V_51 = 0 ; V_51 < V_9 -> V_3 . V_46 ; V_51 ++ ) {
struct V_10 * V_4 ;
V_4 = F_11 ( & V_9 -> V_3 . V_52 [ V_51 ] ) ;
if ( ! V_4 )
continue;
F_5 ( V_9 , V_51 , V_4 -> V_54 , V_27 ) ;
F_5 ( V_9 , V_51 , V_4 -> V_17 , V_29 ) ;
F_5 ( V_9 , V_51 , V_4 -> V_55 , V_30 ) ;
F_5 ( V_9 , V_51 , V_4 -> V_53 , V_36 ) ;
}
return 0 ;
}

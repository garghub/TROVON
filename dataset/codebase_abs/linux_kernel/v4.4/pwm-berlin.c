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
static int F_7 ( struct V_2 * V_3 , struct V_8 * V_9 ,
int V_10 , int V_11 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
unsigned int V_13 ;
T_1 V_7 , V_14 , V_15 ;
T_2 V_16 , V_17 ;
V_16 = F_8 ( V_12 -> V_18 ) ;
V_16 *= V_11 ;
F_9 ( V_16 , V_19 ) ;
for ( V_13 = 0 ; V_13 < F_10 ( V_20 ) ; V_13 ++ ) {
V_17 = V_16 ;
F_9 ( V_17 , V_20 [ V_13 ] ) ;
if ( V_17 <= V_21 )
break;
}
if ( V_17 > V_21 )
return - V_22 ;
V_15 = V_17 ;
V_16 = V_17 * V_10 ;
F_9 ( V_16 , V_11 ) ;
V_14 = V_16 ;
V_7 = F_3 ( V_12 , V_9 -> V_23 , V_24 ) ;
V_7 &= ~ V_25 ;
V_7 |= V_13 ;
F_5 ( V_12 , V_9 -> V_23 , V_7 , V_24 ) ;
F_5 ( V_12 , V_9 -> V_23 , V_14 , V_26 ) ;
F_5 ( V_12 , V_9 -> V_23 , V_15 , V_27 ) ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 ,
struct V_8 * V_9 ,
enum V_28 V_29 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_1 V_7 ;
V_7 = F_3 ( V_12 , V_9 -> V_23 , V_24 ) ;
if ( V_29 == V_30 )
V_7 &= ~ V_31 ;
else
V_7 |= V_31 ;
F_5 ( V_12 , V_9 -> V_23 , V_7 , V_24 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_1 V_7 ;
V_7 = F_3 ( V_12 , V_9 -> V_23 , V_32 ) ;
V_7 |= V_33 ;
F_5 ( V_12 , V_9 -> V_23 , V_7 , V_32 ) ;
return 0 ;
}
static void F_13 ( struct V_2 * V_3 ,
struct V_8 * V_9 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_1 V_7 ;
V_7 = F_3 ( V_12 , V_9 -> V_23 , V_32 ) ;
V_7 &= ~ V_33 ;
F_5 ( V_12 , V_9 -> V_23 , V_7 , V_32 ) ;
}
static int F_14 ( struct V_34 * V_35 )
{
struct V_1 * V_12 ;
struct V_36 * V_37 ;
int V_38 ;
V_12 = F_15 ( & V_35 -> V_39 , sizeof( * V_12 ) , V_40 ) ;
if ( ! V_12 )
return - V_41 ;
V_37 = F_16 ( V_35 , V_42 , 0 ) ;
V_12 -> V_6 = F_17 ( & V_35 -> V_39 , V_37 ) ;
if ( F_18 ( V_12 -> V_6 ) )
return F_19 ( V_12 -> V_6 ) ;
V_12 -> V_18 = F_20 ( & V_35 -> V_39 , NULL ) ;
if ( F_18 ( V_12 -> V_18 ) )
return F_19 ( V_12 -> V_18 ) ;
V_38 = F_21 ( V_12 -> V_18 ) ;
if ( V_38 )
return V_38 ;
V_12 -> V_3 . V_39 = & V_35 -> V_39 ;
V_12 -> V_3 . V_43 = & V_44 ;
V_12 -> V_3 . V_6 = - 1 ;
V_12 -> V_3 . V_45 = 4 ;
V_12 -> V_3 . V_46 = true ;
V_12 -> V_3 . V_47 = V_48 ;
V_12 -> V_3 . V_49 = 3 ;
V_38 = F_22 ( & V_12 -> V_3 ) ;
if ( V_38 < 0 ) {
F_23 ( & V_35 -> V_39 , L_1 , V_38 ) ;
F_24 ( V_12 -> V_18 ) ;
return V_38 ;
}
F_25 ( V_35 , V_12 ) ;
return 0 ;
}
static int F_26 ( struct V_34 * V_35 )
{
struct V_1 * V_12 = F_27 ( V_35 ) ;
int V_38 ;
V_38 = F_28 ( & V_12 -> V_3 ) ;
F_24 ( V_12 -> V_18 ) ;
return V_38 ;
}

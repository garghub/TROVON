static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_4 , unsigned int V_5 ,
unsigned int V_6 )
{
return F_4 ( V_4 -> V_7 + ( V_5 + 1 ) * 0x10 + V_6 ) ;
}
static inline void F_5 ( struct V_1 * V_4 , unsigned int V_5 ,
unsigned int V_6 , T_1 V_8 )
{
F_6 ( V_8 , V_4 -> V_7 + ( V_5 + 1 ) * 0x10 + V_6 ) ;
}
static void F_7 ( struct V_1 * V_4 , unsigned int V_5 ,
unsigned int V_6 , T_1 V_9 , T_1 V_8 )
{
T_1 V_10 ;
V_10 = F_3 ( V_4 , V_5 , V_6 ) ;
V_10 &= ~ V_9 ;
V_10 |= V_8 & V_9 ;
F_5 ( V_4 , V_5 , V_6 , V_10 ) ;
}
static void F_8 ( struct V_2 * V_3 , struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned long V_15 ;
unsigned int div ;
T_1 V_8 ;
T_2 V_16 ;
V_8 = F_3 ( V_4 , V_12 -> V_5 , V_17 ) ;
if ( V_8 & V_18 )
V_14 -> V_19 = V_20 ;
else
V_14 -> V_19 = V_21 ;
if ( V_8 & V_22 )
V_14 -> V_23 = true ;
else
V_14 -> V_23 = false ;
div = ( V_8 & V_24 ) >> V_25 ;
V_15 = F_9 ( V_4 -> V_26 ) ;
V_16 = F_3 ( V_4 , V_12 -> V_5 , V_27 ) ;
V_16 *= div * V_28 ;
V_14 -> V_29 = F_10 ( V_16 , V_15 ) ;
V_16 = F_3 ( V_4 , V_12 -> V_5 , V_30 ) ;
V_16 *= div * V_28 ;
V_14 -> V_31 = F_10 ( V_16 , V_15 ) ;
}
static int F_11 ( struct V_2 * V_3 , struct V_11 * V_12 ,
unsigned int V_32 , unsigned int V_33 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_34 , V_35 ;
unsigned long long V_36 ;
unsigned int div = 1 ;
unsigned long V_15 ;
V_15 = F_9 ( V_4 -> V_26 ) ;
while ( 1 ) {
V_36 = V_15 / div ;
V_36 = V_36 * V_33 ;
F_12 ( V_36 , V_28 ) ;
if ( V_36 < V_37 )
break;
div ++ ;
if ( div > V_38 )
return - V_39 ;
}
V_34 = V_36 ;
V_36 *= V_32 ;
F_12 ( V_36 , V_33 ) ;
V_35 = V_36 ;
if ( F_13 ( V_12 ) )
F_7 ( V_4 , V_12 -> V_5 , V_17 , V_22 , 0 ) ;
F_7 ( V_4 , V_12 -> V_5 , V_17 , V_24 ,
F_14 ( div ) ) ;
F_5 ( V_4 , V_12 -> V_5 , V_27 , V_34 ) ;
F_5 ( V_4 , V_12 -> V_5 , V_30 , V_35 ) ;
if ( F_13 ( V_12 ) )
F_7 ( V_4 , V_12 -> V_5 , V_17 ,
V_22 , V_22 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 , struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_13 V_40 ;
int V_41 ;
F_16 ( V_12 , & V_40 ) ;
if ( V_14 -> V_19 != V_40 . V_19 )
F_7 ( V_4 , V_12 -> V_5 , V_17 , V_18 ,
( V_14 -> V_19 == V_21 ) ?
0 : V_18 ) ;
if ( V_14 -> V_29 != V_40 . V_29 ||
V_14 -> V_31 != V_40 . V_31 ) {
V_41 = F_11 ( V_3 , V_12 , V_14 -> V_31 ,
V_14 -> V_29 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_14 -> V_23 != V_40 . V_23 ) {
if ( V_14 -> V_23 ) {
V_41 = F_17 ( V_4 -> V_26 ) ;
if ( V_41 )
return V_41 ;
F_7 ( V_4 , V_12 -> V_5 , V_17 ,
V_22 , V_22 ) ;
} else {
F_7 ( V_4 , V_12 -> V_5 , V_17 ,
V_22 , 0 ) ;
F_18 ( V_4 -> V_26 ) ;
}
}
return 0 ;
}
static int F_19 ( struct V_42 * V_43 )
{
struct V_1 * V_4 ;
struct V_44 * V_45 ;
unsigned int V_46 ;
int V_41 ;
V_4 = F_20 ( & V_43 -> V_47 , sizeof( * V_4 ) , V_48 ) ;
if ( ! V_4 )
return - V_49 ;
V_45 = F_21 ( V_43 , V_50 , 0 ) ;
V_4 -> V_7 = F_22 ( & V_43 -> V_47 , V_45 ) ;
if ( F_23 ( V_4 -> V_7 ) )
return F_24 ( V_4 -> V_7 ) ;
V_4 -> V_51 = F_25 ( & V_43 -> V_47 , L_1 ) ;
if ( F_23 ( V_4 -> V_51 ) )
return F_24 ( V_4 -> V_51 ) ;
V_4 -> V_26 = F_25 ( & V_43 -> V_47 , L_2 ) ;
if ( F_23 ( V_4 -> V_26 ) )
return F_24 ( V_4 -> V_26 ) ;
V_41 = F_17 ( V_4 -> V_51 ) ;
if ( V_41 )
return V_41 ;
V_4 -> V_3 . V_47 = & V_43 -> V_47 ;
V_4 -> V_3 . V_52 = & V_53 ;
V_4 -> V_3 . V_7 = - 1 ;
V_4 -> V_3 . V_54 = 4 ;
V_4 -> V_3 . V_55 = V_56 ;
V_4 -> V_3 . V_57 = 3 ;
for ( V_46 = 0 ; V_46 < V_4 -> V_3 . V_54 ; V_46 ++ )
F_7 ( V_4 , V_46 , V_17 , V_22 , 0 ) ;
V_41 = F_26 ( & V_4 -> V_3 ) ;
if ( V_41 < 0 ) {
F_27 ( & V_43 -> V_47 , L_3 , V_41 ) ;
return V_41 ;
}
F_28 ( V_43 , V_4 ) ;
return 0 ;
}
static int F_29 ( struct V_42 * V_43 )
{
struct V_1 * V_4 = F_30 ( V_43 ) ;
int V_41 ;
V_41 = F_31 ( & V_4 -> V_3 ) ;
F_18 ( V_4 -> V_51 ) ;
return V_41 ;
}

static inline T_1 F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
if ( F_2 ( V_4 ) && F_2 ( V_5 ) )
return F_3 ( V_2 -> V_6 + V_3 ) ;
else
return F_4 ( V_2 -> V_6 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_7 ,
unsigned int V_3 )
{
if ( F_2 ( V_4 ) && F_2 ( V_5 ) )
F_6 ( V_7 , V_2 -> V_6 + V_3 ) ;
else
F_7 ( V_7 , V_2 -> V_6 + V_3 ) ;
}
static inline struct V_1 * F_8 ( struct V_8 * V_9 )
{
return F_9 ( V_9 , struct V_1 , V_9 ) ;
}
static int F_10 ( struct V_8 * V_9 , struct V_10 * V_11 ,
int V_12 , int V_13 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
unsigned long V_14 , V_15 , V_16 = V_17 ;
unsigned int V_18 = V_11 -> V_19 ;
T_1 V_7 ;
if ( V_12 == V_13 ) {
V_15 = V_20 ;
V_14 = V_20 - 1 ;
goto V_21;
}
while ( 1 ) {
T_2 V_22 , V_23 ;
V_22 = ( T_2 ) F_11 ( V_2 -> V_24 ) * ( T_2 ) V_16 ;
F_12 ( V_22 , 1 << V_25 ) ;
V_23 = V_13 * V_22 ;
F_12 ( V_23 , V_26 ) ;
V_14 = V_23 ;
V_23 = ( V_12 + 1 ) * V_22 ;
F_12 ( V_23 , V_26 ) ;
V_15 = V_23 ;
if ( V_14 == V_27 || ( V_15 < V_28 && V_12 ) )
return - V_29 ;
if ( V_14 <= V_20 && V_15 <= V_20 )
break;
V_16 >>= 1 ;
if ( V_16 < V_30 )
return - V_29 ;
}
V_21:
F_13 ( & V_2 -> V_31 ) ;
F_5 ( V_2 , V_16 >> 8 , F_14 ( V_18 ) ) ;
F_5 ( V_2 , V_16 & 0xff , F_15 ( V_18 ) ) ;
V_7 = F_1 ( V_2 , V_32 ) ;
V_7 |= V_33 << ( V_18 * V_34 ) ;
F_5 ( V_2 , V_7 , V_32 ) ;
F_5 ( V_2 , V_14 , F_16 ( V_18 ) ) ;
F_5 ( V_2 , V_15 , F_17 ( V_18 ) ) ;
F_18 ( & V_2 -> V_31 ) ;
return 0 ;
}
static inline void F_19 ( struct V_1 * V_2 ,
unsigned int V_18 , bool V_35 )
{
unsigned int V_36 = V_18 * V_34 ;
T_1 V_7 ;
F_13 ( & V_2 -> V_31 ) ;
V_7 = F_1 ( V_2 , V_37 ) ;
if ( V_35 ) {
V_7 &= ~ ( V_38 << V_36 ) ;
V_7 |= ( V_39 | V_40 ) << V_36 ;
} else {
V_7 &= ~ ( ( V_39 | V_40 ) << V_36 ) ;
V_7 |= V_38 << V_36 ;
}
F_5 ( V_2 , V_7 , V_37 ) ;
F_18 ( & V_2 -> V_31 ) ;
}
static int F_20 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
F_19 ( V_2 , V_11 -> V_19 , true ) ;
return 0 ;
}
static void F_21 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
F_19 ( V_2 , V_11 -> V_19 , false ) ;
}
static int F_22 ( struct V_41 * V_42 )
{
struct V_1 * V_2 ;
struct V_43 * V_44 ;
int V_45 ;
V_2 = F_23 ( & V_42 -> V_46 , sizeof( * V_2 ) , V_47 ) ;
if ( ! V_2 )
return - V_48 ;
F_24 ( & V_2 -> V_31 ) ;
V_2 -> V_24 = F_25 ( & V_42 -> V_46 , NULL ) ;
if ( F_26 ( V_2 -> V_24 ) ) {
F_27 ( & V_42 -> V_46 , L_1 ) ;
return F_28 ( V_2 -> V_24 ) ;
}
V_45 = F_29 ( V_2 -> V_24 ) ;
if ( V_45 < 0 ) {
F_27 ( & V_42 -> V_46 , L_2 , V_45 ) ;
return V_45 ;
}
F_30 ( V_42 , V_2 ) ;
V_2 -> V_9 . V_46 = & V_42 -> V_46 ;
V_2 -> V_9 . V_49 = & V_50 ;
V_2 -> V_9 . V_6 = - 1 ;
V_2 -> V_9 . V_51 = 2 ;
V_2 -> V_9 . V_52 = true ;
V_44 = F_31 ( V_42 , V_53 , 0 ) ;
V_2 -> V_6 = F_32 ( & V_42 -> V_46 , V_44 ) ;
if ( ! V_2 -> V_6 ) {
V_45 = - V_48 ;
goto V_54;
}
V_45 = F_33 ( & V_2 -> V_9 ) ;
if ( V_45 ) {
F_27 ( & V_42 -> V_46 , L_3 , V_45 ) ;
goto V_54;
}
return 0 ;
V_54:
F_34 ( V_2 -> V_24 ) ;
return V_45 ;
}
static int F_35 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_36 ( V_42 ) ;
int V_45 ;
V_45 = F_37 ( & V_2 -> V_9 ) ;
F_34 ( V_2 -> V_24 ) ;
return V_45 ;
}
static int F_38 ( struct V_55 * V_46 )
{
struct V_1 * V_2 = F_39 ( V_46 ) ;
F_40 ( V_2 -> V_24 ) ;
return 0 ;
}
static int F_41 ( struct V_55 * V_46 )
{
struct V_1 * V_2 = F_39 ( V_46 ) ;
F_42 ( V_2 -> V_24 ) ;
return 0 ;
}

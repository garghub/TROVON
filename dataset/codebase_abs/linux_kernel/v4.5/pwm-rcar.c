static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_4 , T_1 V_5 ,
unsigned int V_6 )
{
F_4 ( V_5 , V_4 -> V_7 + V_6 ) ;
}
static T_1 F_5 ( struct V_1 * V_4 , unsigned int V_6 )
{
return F_6 ( V_4 -> V_7 + V_6 ) ;
}
static void F_7 ( struct V_1 * V_4 , T_1 V_8 , T_1 V_5 ,
unsigned int V_6 )
{
T_1 V_9 ;
V_9 = F_5 ( V_4 , V_6 ) ;
V_9 &= ~ V_8 ;
V_9 |= V_5 & V_8 ;
F_3 ( V_4 , V_9 , V_6 ) ;
}
static int F_8 ( struct V_1 * V_4 , int V_10 )
{
unsigned long V_11 = F_9 ( V_4 -> V_12 ) ;
unsigned long long V_13 ;
unsigned int div ;
if ( V_11 == 0 )
return - V_14 ;
for ( div = 0 ; div <= V_15 ; div ++ ) {
V_13 = ( unsigned long long ) V_16 * V_17 *
( 1 << div ) ;
F_10 ( V_13 , V_11 ) ;
if ( V_10 <= V_13 )
break;
}
return ( div <= V_15 ) ? div : - V_18 ;
}
static void F_11 ( struct V_1 * V_4 ,
unsigned int div )
{
T_1 V_9 ;
V_9 = F_5 ( V_4 , V_19 ) ;
V_9 &= ~ ( V_20 | V_21 ) ;
if ( div & 1 )
V_9 |= V_20 ;
div >>= 1 ;
V_9 |= div << V_22 ;
F_3 ( V_4 , V_9 , V_19 ) ;
}
static int F_12 ( struct V_1 * V_4 , int div , int V_23 ,
int V_10 )
{
unsigned long long V_24 , V_25 ;
unsigned long V_11 = F_9 ( V_4 -> V_12 ) ;
T_1 V_26 , V_27 ;
V_24 = ( unsigned long long ) V_16 * 100ULL * ( 1 << div ) ;
F_10 ( V_24 , V_11 ) ;
V_25 = V_10 * 100ULL ;
F_10 ( V_25 , V_24 ) ;
V_26 = ( V_25 << V_28 ) & V_29 ;
V_25 = V_23 * 100ULL ;
F_10 ( V_25 , V_24 ) ;
V_27 = V_25 & V_30 ;
if ( V_26 == 0 || V_27 == 0 )
return - V_14 ;
F_3 ( V_4 , V_26 | V_27 , V_31 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 , struct V_32 * V_33 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_14 ( V_4 -> V_12 ) ;
}
static void F_15 ( struct V_2 * V_3 , struct V_32 * V_33 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_16 ( V_4 -> V_12 ) ;
}
static int F_17 ( struct V_2 * V_3 , struct V_32 * V_33 ,
int V_23 , int V_10 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int div , V_34 ;
div = F_8 ( V_4 , V_10 ) ;
if ( div < 0 )
return div ;
if ( ! F_18 ( V_35 , & V_33 -> V_36 ) && ! V_23 )
return 0 ;
F_7 ( V_4 , V_37 , V_37 , V_19 ) ;
V_34 = F_12 ( V_4 , div , V_23 , V_10 ) ;
if ( ! V_34 )
F_11 ( V_4 , div ) ;
F_7 ( V_4 , V_37 , 0 , V_19 ) ;
return V_34 ;
}
static int F_19 ( struct V_2 * V_3 , struct V_32 * V_33 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_9 ;
V_9 = F_5 ( V_4 , V_31 ) ;
if ( ( V_9 & V_29 ) == 0 ||
( V_9 & V_30 ) == 0 )
return - V_14 ;
F_7 ( V_4 , V_38 , V_38 , V_19 ) ;
return 0 ;
}
static void F_20 ( struct V_2 * V_3 , struct V_32 * V_33 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_7 ( V_4 , V_38 , 0 , V_19 ) ;
}
static int F_21 ( struct V_39 * V_40 )
{
struct V_1 * V_41 ;
struct V_42 * V_43 ;
int V_34 ;
V_41 = F_22 ( & V_40 -> V_44 , sizeof( * V_41 ) , V_45 ) ;
if ( V_41 == NULL )
return - V_46 ;
V_43 = F_23 ( V_40 , V_47 , 0 ) ;
V_41 -> V_7 = F_24 ( & V_40 -> V_44 , V_43 ) ;
if ( F_25 ( V_41 -> V_7 ) )
return F_26 ( V_41 -> V_7 ) ;
V_41 -> V_12 = F_27 ( & V_40 -> V_44 , NULL ) ;
if ( F_25 ( V_41 -> V_12 ) ) {
F_28 ( & V_40 -> V_44 , L_1 ) ;
return F_26 ( V_41 -> V_12 ) ;
}
F_29 ( V_40 , V_41 ) ;
V_41 -> V_3 . V_44 = & V_40 -> V_44 ;
V_41 -> V_3 . V_48 = & V_49 ;
V_41 -> V_3 . V_7 = - 1 ;
V_41 -> V_3 . V_50 = 1 ;
V_34 = F_30 ( & V_41 -> V_3 ) ;
if ( V_34 < 0 ) {
F_28 ( & V_40 -> V_44 , L_2 , V_34 ) ;
return V_34 ;
}
F_31 ( & V_40 -> V_44 ) ;
return 0 ;
}
static int F_32 ( struct V_39 * V_40 )
{
struct V_1 * V_41 = F_33 ( V_40 ) ;
F_34 ( & V_40 -> V_44 ) ;
return F_35 ( & V_41 -> V_3 ) ;
}

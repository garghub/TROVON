static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
unsigned V_5 = 0 ;
do {
if ( F_2 ( V_5 > 1 ) )
F_3 ( 5 ) ;
V_4 = F_4 ( V_2 -> V_6 + V_3 ) ;
V_5 ++ ;
} while ( ( V_4 & V_7 ) && V_5 < V_8 );
#ifdef F_5
if ( V_5 > V_2 -> V_9 )
V_2 -> V_9 = V_5 ;
#endif
if ( V_4 & V_7 )
return - V_10 ;
V_4 &= V_11 ;
return V_4 ;
}
static int F_6 ( struct V_12 * V_13 , void * V_14 )
{
int V_15 , V_16 ;
unsigned long V_17 ;
struct V_1 * V_2 = V_13 -> V_18 ;
if ( ! V_2 ) {
F_7 ( V_13 , L_1 ) ;
return 0 ;
}
F_8 ( & V_2 -> V_19 , V_17 ) ;
V_15 = F_1 ( V_2 , V_20 ) ;
V_16 = F_1 ( V_2 , V_21 ) ;
F_9 ( & V_2 -> V_19 , V_17 ) ;
if ( V_15 < 0 || V_16 < 0 ) {
F_7 ( V_13 , L_2 ) ;
} else {
int V_22 , V_23 , V_24 , V_25 , V_26 ;
V_22 = V_15 & V_27 ;
V_26 = ( V_15 & V_28 ) >> V_29 ;
V_23 = V_16 & V_27 ;
V_24 = F_10 ( V_22 , V_2 ) ;
V_25 = F_10 ( V_23 , V_2 ) ;
F_11 ( V_13 ,
L_3
L_4
L_5
L_6 ,
V_26 , V_2 -> V_30 ,
V_24 , V_22 , V_22 ,
V_25 , V_23 , V_23 ,
V_2 -> V_9 ) ;
}
return 0 ;
}
static int F_12 ( struct V_31 * V_31 , struct V_32 * V_32 )
{
return F_13 ( V_32 , F_6 , V_31 -> V_33 ) ;
}
static void F_14 ( struct V_34 * V_35 )
{
struct V_36 * V_37 ;
struct V_1 * V_2 = F_15 ( V_35 ) ;
if ( ! V_2 )
return;
V_2 -> V_38 = NULL ;
V_37 = F_16 ( V_39 , NULL ) ;
if ( F_17 ( V_37 ) )
return;
if ( F_18 ( L_7 , V_40 | V_41 , V_37 , V_2 ,
& V_42 ) )
V_2 -> V_38 = V_37 ;
else
F_19 ( V_37 ) ;
}
static void F_20 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_15 ( V_35 ) ;
if ( V_2 && V_2 -> V_38 ) {
F_19 ( V_2 -> V_38 ) ;
V_2 -> V_38 = NULL ;
}
}
static void F_14 ( struct V_34 * V_35 ) {}
static void F_20 ( struct V_34 * V_35 ) {}
static int F_21 ( struct V_1 * V_2 ,
unsigned V_43 , unsigned V_44 )
{
int V_4 ;
unsigned long V_17 ;
int V_45 = 0 ;
F_8 ( & V_2 -> V_19 , V_17 ) ;
V_4 = F_1 ( V_2 , V_20 ) ;
if ( V_4 < 0 ) {
V_45 = V_4 ;
} else {
V_4 &= ~ V_43 ;
V_4 |= V_44 ;
F_22 ( V_4 , V_2 -> V_6 + V_20 ) ;
}
F_9 ( & V_2 -> V_19 , V_17 ) ;
return V_45 ;
}
static int F_23 ( struct V_1 * V_2 )
{
if ( V_2 -> V_30 > V_46 )
return - V_47 ;
return F_21 ( V_2 , V_28 ,
V_2 -> V_30 << V_29 ) ;
}
static int F_24 ( struct V_48 * V_49 ,
unsigned V_50 )
{
struct V_1 * V_2 = F_25 ( V_49 ) ;
return F_21 ( V_2 , V_27 ,
F_26 ( V_49 -> V_51 , V_2 ) |
V_50 ) ;
}
static int F_27 ( struct V_48 * V_49 ,
unsigned int V_52 )
{
V_49 -> V_51 = V_52 ;
return 0 ;
}
static unsigned int F_28 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_25 ( V_49 ) ;
int V_4 ;
unsigned long V_17 ;
F_8 ( & V_2 -> V_19 , V_17 ) ;
V_4 = F_1 ( V_2 , V_21 ) ;
F_9 ( & V_2 -> V_19 , V_17 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_10 ( V_4 & V_27 , V_2 ) ;
}
static int F_29 ( struct V_48 * V_49 )
{
return F_24 ( V_49 ,
V_53 | V_54 ) ;
}
static int F_30 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_25 ( V_49 ) ;
return F_21 ( V_2 , V_53 |
V_54 , 0 ) ;
}
static void F_31 ( struct V_34 * V_35 )
{
F_30 ( & V_55 ) ;
}
static int F_32 ( struct V_34 * V_35 )
{
struct V_56 * V_57 = & V_35 -> V_57 ;
struct V_1 * V_2 ;
struct V_58 * V_26 ;
int V_45 ;
V_2 = F_33 ( V_57 , sizeof( * V_2 ) , V_59 ) ;
if ( ! V_2 )
return - V_60 ;
V_26 = F_34 ( V_35 , V_61 , 0 ) ;
V_2 -> V_6 = F_35 ( V_57 , V_26 ) ;
if ( F_36 ( V_2 -> V_6 ) )
return - V_62 ;
V_2 -> V_30 = V_63 ;
V_45 = F_23 ( V_2 ) ;
if ( V_45 ) {
F_37 ( V_57 , L_8 , V_45 ) ;
return V_45 ;
}
F_38 ( & V_2 -> V_19 ) ;
F_39 ( V_35 , V_2 ) ;
F_40 ( & V_55 , V_2 ) ;
V_55 . V_64 = & V_35 -> V_57 ;
V_45 = F_24 ( & V_55 , 0 ) ;
if ( V_45 ) {
F_37 ( V_57 , L_9 ) ;
return V_45 ;
}
V_45 = F_41 ( & V_55 ) ;
if ( V_45 ) {
F_37 ( V_57 , L_10 ) ;
return V_45 ;
}
F_14 ( V_35 ) ;
F_42 ( V_57 , L_11 ) ;
return 0 ;
}
static int F_43 ( struct V_34 * V_35 )
{
F_20 ( V_35 ) ;
F_31 ( V_35 ) ;
F_44 ( & V_55 ) ;
F_42 ( & V_35 -> V_57 , L_12 ) ;
return 0 ;
}

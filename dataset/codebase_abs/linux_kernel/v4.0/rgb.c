static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_4 * V_5 ,
const struct V_6 * V_7 ,
unsigned int V_8 )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
F_4 ( V_5 , V_7 [ V_9 ] . V_10 , V_7 [ V_9 ] . V_11 ) ;
}
static void F_5 ( struct V_12 * V_13 ,
int V_14 )
{
}
static enum V_15
F_6 ( struct V_12 * V_13 ,
struct V_16 * V_14 )
{
return V_17 ;
}
static void F_7 ( struct V_18 * V_19 , int V_14 )
{
}
static void F_8 ( struct V_18 * V_19 )
{
}
static void F_9 ( struct V_18 * V_19 )
{
}
static void F_10 ( struct V_18 * V_19 ,
struct V_16 * V_14 ,
struct V_16 * V_20 )
{
struct V_2 * V_3 = F_11 ( V_19 ) ;
struct V_1 * V_21 = F_1 ( V_3 ) ;
T_1 V_10 ;
if ( V_3 -> V_22 )
F_12 ( V_3 -> V_22 ) ;
F_3 ( V_21 -> V_5 , V_23 , F_13 ( V_23 ) ) ;
V_10 = V_24 | V_25 ;
F_4 ( V_21 -> V_5 , V_10 , V_26 ) ;
V_10 = F_14 ( V_21 -> V_5 , F_15 ( 1 ) ) ;
V_10 &= ~ V_27 ;
V_10 &= ~ V_28 ;
F_4 ( V_21 -> V_5 , V_10 , F_15 ( 1 ) ) ;
V_10 = V_29 | V_30 |
V_31 ;
F_4 ( V_21 -> V_5 , V_10 , V_32 ) ;
V_10 = V_33 | V_34 ;
F_4 ( V_21 -> V_5 , V_10 , V_35 ) ;
F_16 ( V_21 -> V_5 ) ;
if ( V_3 -> V_22 )
F_17 ( V_3 -> V_22 ) ;
}
static void F_18 ( struct V_18 * V_19 )
{
struct V_2 * V_3 = F_11 ( V_19 ) ;
struct V_1 * V_21 = F_1 ( V_3 ) ;
if ( V_3 -> V_22 )
F_19 ( V_3 -> V_22 ) ;
F_3 ( V_21 -> V_5 , V_36 , F_13 ( V_36 ) ) ;
F_16 ( V_21 -> V_5 ) ;
if ( V_3 -> V_22 )
F_20 ( V_3 -> V_22 ) ;
}
static int
F_21 ( struct V_18 * V_19 ,
struct V_37 * V_38 ,
struct V_39 * V_40 )
{
struct V_2 * V_3 = F_11 ( V_19 ) ;
struct V_4 * V_5 = F_22 ( V_40 -> V_41 ) ;
unsigned long V_42 = V_38 -> V_14 . clock * 1000 ;
struct V_1 * V_21 = F_1 ( V_3 ) ;
unsigned int div ;
int V_43 ;
div = ( ( F_23 ( V_21 -> V_44 ) * 2 ) / V_42 ) - 2 ;
V_42 = 0 ;
V_43 = F_24 ( V_5 , V_38 , V_21 -> V_45 ,
V_42 , div ) ;
if ( V_43 < 0 ) {
F_25 ( V_3 -> V_46 , L_1 , V_43 ) ;
return V_43 ;
}
return V_43 ;
}
int F_26 ( struct V_4 * V_5 )
{
struct V_47 * V_48 ;
struct V_1 * V_21 ;
int V_43 ;
V_48 = F_27 ( V_5 -> V_46 -> V_49 , L_2 ) ;
if ( ! V_48 || ! F_28 ( V_48 ) )
return - V_50 ;
V_21 = F_29 ( V_5 -> V_46 , sizeof( * V_21 ) , V_51 ) ;
if ( ! V_21 )
return - V_52 ;
V_21 -> V_3 . V_46 = V_5 -> V_46 ;
V_21 -> V_3 . V_49 = V_48 ;
V_21 -> V_5 = V_5 ;
V_43 = F_30 ( & V_21 -> V_3 ) ;
if ( V_43 < 0 )
return V_43 ;
V_21 -> V_44 = F_31 ( V_5 -> V_46 , NULL ) ;
if ( F_32 ( V_21 -> V_44 ) ) {
F_25 ( V_5 -> V_46 , L_3 ) ;
return F_33 ( V_21 -> V_44 ) ;
}
V_21 -> V_45 = F_31 ( V_5 -> V_46 , L_4 ) ;
if ( F_32 ( V_21 -> V_45 ) ) {
F_25 ( V_5 -> V_46 , L_5 ) ;
return F_33 ( V_21 -> V_45 ) ;
}
V_43 = F_34 ( V_21 -> V_44 , V_21 -> V_45 ) ;
if ( V_43 < 0 ) {
F_25 ( V_5 -> V_46 , L_6 , V_43 ) ;
return V_43 ;
}
V_5 -> V_21 = & V_21 -> V_3 ;
return 0 ;
}
int F_35 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_21 )
return 0 ;
F_36 ( V_5 -> V_21 ) ;
V_5 -> V_21 = NULL ;
return 0 ;
}
int F_37 ( struct V_53 * V_54 , struct V_4 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_21 ;
int V_43 ;
if ( ! V_5 -> V_21 )
return - V_50 ;
F_38 ( V_54 , & V_3 -> V_13 , & V_55 ,
V_56 ) ;
F_39 ( & V_3 -> V_13 ,
& V_57 ) ;
V_3 -> V_13 . V_58 = V_59 ;
F_40 ( V_54 , & V_3 -> V_19 , & V_60 ,
V_61 ) ;
F_41 ( & V_3 -> V_19 ,
& V_62 ) ;
F_42 ( & V_3 -> V_13 ,
& V_3 -> V_19 ) ;
F_43 ( & V_3 -> V_13 ) ;
V_43 = F_44 ( V_54 , V_3 ) ;
if ( V_43 < 0 ) {
F_25 ( V_3 -> V_46 , L_7 , V_43 ) ;
return V_43 ;
}
V_3 -> V_19 . V_63 = F_45 ( & V_5 -> V_64 ) ;
return 0 ;
}
int F_46 ( struct V_4 * V_5 )
{
if ( V_5 -> V_21 )
F_47 ( V_5 -> V_21 ) ;
return 0 ;
}

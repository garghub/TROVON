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
static enum V_12
F_5 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
return V_17 ;
}
static void F_6 ( struct V_18 * V_19 )
{
struct V_2 * V_3 = F_7 ( V_19 ) ;
struct V_1 * V_20 = F_1 ( V_3 ) ;
if ( V_3 -> V_21 )
F_8 ( V_3 -> V_21 ) ;
F_3 ( V_20 -> V_5 , V_22 , F_9 ( V_22 ) ) ;
F_10 ( V_20 -> V_5 ) ;
if ( V_3 -> V_21 )
F_11 ( V_3 -> V_21 ) ;
}
static void F_12 ( struct V_18 * V_19 )
{
struct V_2 * V_3 = F_7 ( V_19 ) ;
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_10 ;
if ( V_3 -> V_21 )
F_13 ( V_3 -> V_21 ) ;
F_3 ( V_20 -> V_5 , V_23 , F_9 ( V_23 ) ) ;
V_10 = V_24 | V_25 ;
F_4 ( V_20 -> V_5 , V_10 , V_26 ) ;
V_10 = F_14 ( V_20 -> V_5 , F_15 ( 1 ) ) ;
V_10 &= ~ V_27 ;
V_10 &= ~ V_28 ;
F_4 ( V_20 -> V_5 , V_10 , F_15 ( 1 ) ) ;
V_10 = V_29 | V_30 |
V_31 ;
F_4 ( V_20 -> V_5 , V_10 , V_32 ) ;
V_10 = V_33 | V_34 ;
F_4 ( V_20 -> V_5 , V_10 , V_35 ) ;
F_10 ( V_20 -> V_5 ) ;
if ( V_3 -> V_21 )
F_16 ( V_3 -> V_21 ) ;
}
static int
F_17 ( struct V_18 * V_19 ,
struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_2 * V_3 = F_7 ( V_19 ) ;
struct V_4 * V_5 = F_18 ( V_39 -> V_40 ) ;
unsigned long V_41 = V_37 -> V_16 . clock * 1000 ;
struct V_1 * V_20 = F_1 ( V_3 ) ;
unsigned int div ;
int V_42 ;
div = ( ( F_19 ( V_20 -> V_43 ) * 2 ) / V_41 ) - 2 ;
V_41 = 0 ;
V_42 = F_20 ( V_5 , V_37 , V_20 -> V_44 ,
V_41 , div ) ;
if ( V_42 < 0 ) {
F_21 ( V_3 -> V_45 , L_1 , V_42 ) ;
return V_42 ;
}
return V_42 ;
}
int F_22 ( struct V_4 * V_5 )
{
struct V_46 * V_47 ;
struct V_1 * V_20 ;
int V_42 ;
V_47 = F_23 ( V_5 -> V_45 -> V_48 , L_2 ) ;
if ( ! V_47 || ! F_24 ( V_47 ) )
return - V_49 ;
V_20 = F_25 ( V_5 -> V_45 , sizeof( * V_20 ) , V_50 ) ;
if ( ! V_20 )
return - V_51 ;
V_20 -> V_3 . V_45 = V_5 -> V_45 ;
V_20 -> V_3 . V_48 = V_47 ;
V_20 -> V_5 = V_5 ;
V_42 = F_26 ( & V_20 -> V_3 ) ;
if ( V_42 < 0 )
return V_42 ;
V_20 -> V_43 = F_27 ( V_5 -> V_45 , NULL ) ;
if ( F_28 ( V_20 -> V_43 ) ) {
F_21 ( V_5 -> V_45 , L_3 ) ;
return F_29 ( V_20 -> V_43 ) ;
}
V_20 -> V_44 = F_27 ( V_5 -> V_45 , L_4 ) ;
if ( F_28 ( V_20 -> V_44 ) ) {
F_21 ( V_5 -> V_45 , L_5 ) ;
return F_29 ( V_20 -> V_44 ) ;
}
V_42 = F_30 ( V_20 -> V_43 , V_20 -> V_44 ) ;
if ( V_42 < 0 ) {
F_21 ( V_5 -> V_45 , L_6 , V_42 ) ;
return V_42 ;
}
V_5 -> V_20 = & V_20 -> V_3 ;
return 0 ;
}
int F_31 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_20 )
return 0 ;
F_32 ( V_5 -> V_20 ) ;
V_5 -> V_20 = NULL ;
return 0 ;
}
int F_33 ( struct V_52 * V_53 , struct V_4 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_20 ;
int V_42 ;
if ( ! V_5 -> V_20 )
return - V_49 ;
F_34 ( V_53 , & V_3 -> V_14 , & V_54 ,
V_55 ) ;
F_35 ( & V_3 -> V_14 ,
& V_56 ) ;
V_3 -> V_14 . V_57 = V_58 ;
F_36 ( V_53 , & V_3 -> V_19 , & V_59 ,
V_60 , NULL ) ;
F_37 ( & V_3 -> V_19 ,
& V_61 ) ;
F_38 ( & V_3 -> V_14 ,
& V_3 -> V_19 ) ;
F_39 ( & V_3 -> V_14 ) ;
V_42 = F_40 ( V_53 , V_3 ) ;
if ( V_42 < 0 ) {
F_21 ( V_3 -> V_45 , L_7 , V_42 ) ;
return V_42 ;
}
V_3 -> V_19 . V_62 = F_41 ( & V_5 -> V_63 ) ;
return 0 ;
}
int F_42 ( struct V_4 * V_5 )
{
if ( V_5 -> V_20 )
F_43 ( V_5 -> V_20 ) ;
return 0 ;
}

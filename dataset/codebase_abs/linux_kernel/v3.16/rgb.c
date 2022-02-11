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
static int F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
unsigned long V_10 ;
if ( V_12 -> V_13 )
return 0 ;
F_3 ( V_12 -> V_5 , V_14 , F_6 ( V_14 ) ) ;
V_10 = V_15 | V_16 ;
F_4 ( V_12 -> V_5 , V_10 , V_17 ) ;
V_10 = F_7 ( V_12 -> V_5 , F_8 ( 1 ) ) ;
V_10 &= ~ V_18 ;
V_10 &= ~ V_19 ;
F_4 ( V_12 -> V_5 , V_10 , F_8 ( 1 ) ) ;
V_10 = V_20 | V_21 |
V_22 ;
F_4 ( V_12 -> V_5 , V_10 , V_23 ) ;
V_10 = V_24 | V_25 ;
F_4 ( V_12 -> V_5 , V_10 , V_26 ) ;
V_10 = F_7 ( V_12 -> V_5 , V_27 ) ;
V_10 &= ~ V_28 ;
V_10 |= V_29 ;
F_4 ( V_12 -> V_5 , V_10 , V_27 ) ;
V_10 = F_7 ( V_12 -> V_5 , V_30 ) ;
V_10 |= V_31 | V_32 | V_33 | V_34 |
V_35 | V_36 | V_37 ;
F_4 ( V_12 -> V_5 , V_10 , V_30 ) ;
F_4 ( V_12 -> V_5 , V_38 << 8 , V_39 ) ;
F_4 ( V_12 -> V_5 , V_38 , V_39 ) ;
V_12 -> V_13 = true ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
unsigned long V_10 ;
if ( ! V_12 -> V_13 )
return 0 ;
V_10 = F_7 ( V_12 -> V_5 , V_30 ) ;
V_10 &= ~ ( V_31 | V_32 | V_33 | V_34 |
V_35 | V_36 | V_37 ) ;
F_4 ( V_12 -> V_5 , V_10 , V_30 ) ;
V_10 = F_7 ( V_12 -> V_5 , V_27 ) ;
V_10 &= ~ V_28 ;
F_4 ( V_12 -> V_5 , V_10 , V_27 ) ;
F_4 ( V_12 -> V_5 , V_38 << 8 , V_39 ) ;
F_4 ( V_12 -> V_5 , V_38 , V_39 ) ;
F_3 ( V_12 -> V_5 , V_40 , F_6 ( V_40 ) ) ;
V_12 -> V_13 = false ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_41 * V_41 , unsigned long V_42 ,
unsigned int * div )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
int V_43 ;
V_43 = F_11 ( V_41 , V_12 -> V_44 ) ;
if ( V_43 < 0 ) {
F_12 ( V_3 -> V_45 , L_1 , V_43 ) ;
return V_43 ;
}
* div = ( ( F_13 ( V_41 ) * 2 ) / V_42 ) - 2 ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 ,
struct V_46 * V_47 ,
enum V_48 * V_49 )
{
* V_49 = V_50 ;
return 0 ;
}
int F_15 ( struct V_4 * V_5 )
{
struct V_51 * V_52 ;
struct V_1 * V_12 ;
int V_43 ;
V_52 = F_16 ( V_5 -> V_45 -> V_53 , L_2 ) ;
if ( ! V_52 || ! F_17 ( V_52 ) )
return - V_54 ;
V_12 = F_18 ( V_5 -> V_45 , sizeof( * V_12 ) , V_55 ) ;
if ( ! V_12 )
return - V_56 ;
V_12 -> V_3 . V_45 = V_5 -> V_45 ;
V_12 -> V_3 . V_53 = V_52 ;
V_12 -> V_5 = V_5 ;
V_43 = F_19 ( & V_12 -> V_3 ) ;
if ( V_43 < 0 )
return V_43 ;
V_12 -> V_41 = F_20 ( V_5 -> V_45 , NULL ) ;
if ( F_21 ( V_12 -> V_41 ) ) {
F_12 ( V_5 -> V_45 , L_3 ) ;
return F_22 ( V_12 -> V_41 ) ;
}
V_12 -> V_44 = F_20 ( V_5 -> V_45 , L_4 ) ;
if ( F_21 ( V_12 -> V_44 ) ) {
F_12 ( V_5 -> V_45 , L_5 ) ;
return F_22 ( V_12 -> V_44 ) ;
}
V_43 = F_11 ( V_12 -> V_41 , V_12 -> V_44 ) ;
if ( V_43 < 0 ) {
F_12 ( V_5 -> V_45 , L_6 , V_43 ) ;
return V_43 ;
}
V_5 -> V_12 = & V_12 -> V_3 ;
return 0 ;
}
int F_23 ( struct V_4 * V_5 )
{
int V_43 ;
if ( ! V_5 -> V_12 )
return 0 ;
V_43 = F_24 ( V_5 -> V_12 ) ;
if ( V_43 < 0 )
return V_43 ;
return 0 ;
}
int F_25 ( struct V_57 * V_58 , struct V_4 * V_5 )
{
struct V_1 * V_12 = F_1 ( V_5 -> V_12 ) ;
int V_43 ;
if ( ! V_5 -> V_12 )
return - V_54 ;
V_12 -> V_3 . type = V_59 ;
V_12 -> V_3 . V_60 = & V_61 ;
V_43 = F_26 ( V_5 -> V_62 . V_45 , & V_12 -> V_3 ) ;
if ( V_43 < 0 ) {
F_12 ( V_5 -> V_45 , L_7 , V_43 ) ;
return V_43 ;
}
V_12 -> V_3 . V_63 . V_64 = F_27 ( & V_5 -> V_62 ) ;
return 0 ;
}
int F_28 ( struct V_4 * V_5 )
{
if ( V_5 -> V_12 ) {
int V_43 ;
V_43 = F_29 ( V_5 -> V_12 ) ;
if ( V_43 < 0 ) {
F_12 ( V_5 -> V_45 , L_8 , V_43 ) ;
return V_43 ;
}
V_43 = F_30 ( V_5 -> V_12 ) ;
if ( V_43 < 0 ) {
F_12 ( V_5 -> V_45 , L_9 , V_43 ) ;
return V_43 ;
}
V_5 -> V_12 = NULL ;
}
return 0 ;
}

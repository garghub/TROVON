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
struct V_41 * V_41 , unsigned long V_42 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
return F_11 ( V_41 , V_12 -> V_43 ) ;
}
static int F_12 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
enum V_46 * V_47 )
{
* V_47 = V_48 ;
return 0 ;
}
int F_13 ( struct V_4 * V_5 )
{
struct V_49 * V_50 ;
struct V_1 * V_12 ;
int V_51 ;
V_50 = F_14 ( V_5 -> V_52 -> V_53 , L_1 ) ;
if ( ! V_50 || ! F_15 ( V_50 ) )
return - V_54 ;
V_12 = F_16 ( V_5 -> V_52 , sizeof( * V_12 ) , V_55 ) ;
if ( ! V_12 )
return - V_56 ;
V_12 -> V_3 . V_52 = V_5 -> V_52 ;
V_12 -> V_3 . V_53 = V_50 ;
V_12 -> V_5 = V_5 ;
V_51 = F_17 ( & V_12 -> V_3 ) ;
if ( V_51 < 0 )
return V_51 ;
V_12 -> V_41 = F_18 ( V_5 -> V_52 , NULL ) ;
if ( F_19 ( V_12 -> V_41 ) ) {
F_20 ( V_5 -> V_52 , L_2 ) ;
return F_21 ( V_12 -> V_41 ) ;
}
V_12 -> V_43 = F_18 ( V_5 -> V_52 , L_3 ) ;
if ( F_19 ( V_12 -> V_43 ) ) {
F_20 ( V_5 -> V_52 , L_4 ) ;
return F_21 ( V_12 -> V_43 ) ;
}
V_51 = F_11 ( V_12 -> V_41 , V_12 -> V_43 ) ;
if ( V_51 < 0 ) {
F_20 ( V_5 -> V_52 , L_5 , V_51 ) ;
return V_51 ;
}
V_5 -> V_12 = & V_12 -> V_3 ;
return 0 ;
}
int F_22 ( struct V_4 * V_5 )
{
int V_51 ;
if ( ! V_5 -> V_12 )
return 0 ;
V_51 = F_23 ( V_5 -> V_12 ) ;
if ( V_51 < 0 )
return V_51 ;
return 0 ;
}
int F_24 ( struct V_57 * V_58 , struct V_4 * V_5 )
{
struct V_1 * V_12 = F_1 ( V_5 -> V_12 ) ;
int V_51 ;
if ( ! V_5 -> V_12 )
return - V_54 ;
V_12 -> V_3 . type = V_59 ;
V_12 -> V_3 . V_60 = & V_61 ;
V_51 = F_25 ( V_5 -> V_62 . V_52 , & V_12 -> V_3 ) ;
if ( V_51 < 0 ) {
F_20 ( V_5 -> V_52 , L_6 , V_51 ) ;
return V_51 ;
}
V_12 -> V_3 . V_63 . V_64 = F_26 ( & V_5 -> V_62 ) ;
return 0 ;
}
int F_27 ( struct V_4 * V_5 )
{
if ( V_5 -> V_12 ) {
int V_51 ;
V_51 = F_28 ( V_5 -> V_12 ) ;
if ( V_51 < 0 ) {
F_20 ( V_5 -> V_52 , L_7 , V_51 ) ;
return V_51 ;
}
V_51 = F_29 ( V_5 -> V_12 ) ;
if ( V_51 < 0 ) {
F_20 ( V_5 -> V_52 , L_8 , V_51 ) ;
return V_51 ;
}
V_5 -> V_12 = NULL ;
}
return 0 ;
}

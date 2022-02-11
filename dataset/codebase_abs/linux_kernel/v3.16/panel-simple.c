static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_4 . V_6 ;
struct V_7 * V_8 = V_3 -> V_4 . V_8 ;
struct V_9 * V_10 ;
unsigned int V_11 , V_12 = 0 ;
if ( ! V_3 -> V_13 )
return 0 ;
for ( V_11 = 0 ; V_11 < V_3 -> V_13 -> V_14 ; V_11 ++ ) {
const struct V_9 * V_15 = & V_3 -> V_13 -> V_16 [ V_11 ] ;
V_10 = F_4 ( V_8 , V_15 ) ;
if ( ! V_10 ) {
F_5 ( V_8 -> V_17 , L_1 ,
V_15 -> V_18 , V_15 -> V_19 , V_15 -> V_20 ) ;
continue;
}
F_6 ( V_10 ) ;
F_7 ( V_6 , V_10 ) ;
V_12 ++ ;
}
V_6 -> V_21 . V_22 = V_3 -> V_13 -> V_23 . V_24 ;
V_6 -> V_21 . V_25 = V_3 -> V_13 -> V_23 . V_26 ;
return V_12 ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_27 = F_1 ( V_3 ) ;
if ( ! V_27 -> V_28 )
return 0 ;
if ( V_27 -> V_29 ) {
V_27 -> V_29 -> V_30 . V_31 = V_32 ;
F_9 ( V_27 -> V_29 ) ;
}
if ( V_27 -> V_33 )
F_10 ( V_27 -> V_33 , 0 ) ;
F_11 ( V_27 -> V_34 ) ;
V_27 -> V_28 = false ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_27 = F_1 ( V_3 ) ;
int V_35 ;
if ( V_27 -> V_28 )
return 0 ;
V_35 = F_13 ( V_27 -> V_34 ) ;
if ( V_35 < 0 ) {
F_5 ( V_3 -> V_17 , L_2 , V_35 ) ;
return V_35 ;
}
if ( V_27 -> V_33 )
F_10 ( V_27 -> V_33 , 1 ) ;
if ( V_27 -> V_29 ) {
V_27 -> V_29 -> V_30 . V_31 = V_36 ;
F_9 ( V_27 -> V_29 ) ;
}
V_27 -> V_28 = true ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_27 = F_1 ( V_3 ) ;
int V_12 = 0 ;
if ( V_27 -> V_37 ) {
struct V_38 * V_38 = F_15 ( V_3 -> V_6 , V_27 -> V_37 ) ;
F_16 ( V_3 -> V_6 , V_38 ) ;
if ( V_38 ) {
V_12 += F_17 ( V_3 -> V_6 , V_38 ) ;
F_18 ( V_38 ) ;
}
}
V_12 += F_3 ( V_27 ) ;
return V_12 ;
}
static int F_19 ( struct V_39 * V_17 , const struct V_40 * V_13 )
{
struct V_41 * V_29 , * V_37 ;
struct V_1 * V_3 ;
int V_35 ;
V_3 = F_20 ( V_17 , sizeof( * V_3 ) , V_42 ) ;
if ( ! V_3 )
return - V_43 ;
V_3 -> V_28 = false ;
V_3 -> V_13 = V_13 ;
V_3 -> V_34 = F_21 ( V_17 , L_3 ) ;
if ( F_22 ( V_3 -> V_34 ) )
return F_23 ( V_3 -> V_34 ) ;
V_3 -> V_33 = F_24 ( V_17 , L_4 ) ;
if ( F_22 ( V_3 -> V_33 ) ) {
V_35 = F_23 ( V_3 -> V_33 ) ;
if ( V_35 != - V_44 ) {
F_5 ( V_17 , L_5 , V_35 ) ;
return V_35 ;
}
V_3 -> V_33 = NULL ;
} else {
V_35 = F_25 ( V_3 -> V_33 , 0 ) ;
if ( V_35 < 0 ) {
F_5 ( V_17 , L_6 , V_35 ) ;
return V_35 ;
}
}
V_29 = F_26 ( V_17 -> V_45 , L_7 , 0 ) ;
if ( V_29 ) {
V_3 -> V_29 = F_27 ( V_29 ) ;
F_28 ( V_29 ) ;
if ( ! V_3 -> V_29 )
return - V_46 ;
}
V_37 = F_26 ( V_17 -> V_45 , L_8 , 0 ) ;
if ( V_37 ) {
V_3 -> V_37 = F_29 ( V_37 ) ;
F_28 ( V_37 ) ;
if ( ! V_3 -> V_37 ) {
V_35 = - V_46 ;
goto V_47;
}
}
F_30 ( & V_3 -> V_4 ) ;
V_3 -> V_4 . V_17 = V_17 ;
V_3 -> V_4 . V_48 = & V_49 ;
V_35 = F_31 ( & V_3 -> V_4 ) ;
if ( V_35 < 0 )
goto V_50;
F_32 ( V_17 , V_3 ) ;
return 0 ;
V_50:
if ( V_3 -> V_37 )
F_33 ( & V_3 -> V_37 -> V_17 ) ;
V_47:
if ( V_3 -> V_29 )
F_33 ( & V_3 -> V_29 -> V_17 ) ;
return V_35 ;
}
static int F_34 ( struct V_39 * V_17 )
{
struct V_1 * V_3 = F_35 ( V_17 ) ;
F_36 ( & V_3 -> V_4 ) ;
F_37 ( & V_3 -> V_4 ) ;
F_8 ( & V_3 -> V_4 ) ;
if ( V_3 -> V_37 )
F_33 ( & V_3 -> V_37 -> V_17 ) ;
if ( V_3 -> V_29 )
F_33 ( & V_3 -> V_29 -> V_17 ) ;
return 0 ;
}
static void F_38 ( struct V_39 * V_17 )
{
struct V_1 * V_3 = F_35 ( V_17 ) ;
F_8 ( & V_3 -> V_4 ) ;
}
static int F_39 ( struct V_51 * V_52 )
{
const struct V_53 * V_54 ;
V_54 = F_40 ( V_55 , V_52 -> V_17 . V_45 ) ;
if ( ! V_54 )
return - V_56 ;
return F_19 ( & V_52 -> V_17 , V_54 -> V_57 ) ;
}
static int F_41 ( struct V_51 * V_52 )
{
return F_34 ( & V_52 -> V_17 ) ;
}
static void F_42 ( struct V_51 * V_52 )
{
F_38 ( & V_52 -> V_17 ) ;
}
static int F_43 ( struct V_58 * V_59 )
{
const struct V_60 * V_13 ;
const struct V_53 * V_54 ;
int V_35 ;
V_54 = F_40 ( V_61 , V_59 -> V_17 . V_45 ) ;
if ( ! V_54 )
return - V_56 ;
V_13 = V_54 -> V_57 ;
V_35 = F_19 ( & V_59 -> V_17 , & V_13 -> V_13 ) ;
if ( V_35 < 0 )
return V_35 ;
V_59 -> V_62 = V_13 -> V_63 ;
V_59 -> V_64 = V_13 -> V_64 ;
V_59 -> V_65 = V_13 -> V_65 ;
return F_44 ( V_59 ) ;
}
static int F_45 ( struct V_58 * V_59 )
{
int V_35 ;
V_35 = F_46 ( V_59 ) ;
if ( V_35 < 0 )
F_5 ( & V_59 -> V_17 , L_9 , V_35 ) ;
return F_34 ( & V_59 -> V_17 ) ;
}
static void F_47 ( struct V_58 * V_59 )
{
F_38 ( & V_59 -> V_17 ) ;
}
static int T_1 F_48 ( void )
{
int V_35 ;
V_35 = F_49 ( & V_66 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( F_50 ( V_67 ) ) {
V_35 = F_51 ( & V_68 ) ;
if ( V_35 < 0 )
return V_35 ;
}
return 0 ;
}
static void T_2 F_52 ( void )
{
if ( F_50 ( V_67 ) )
F_53 ( & V_68 ) ;
F_54 ( & V_66 ) ;
}

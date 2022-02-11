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
V_6 -> V_21 . V_22 = V_3 -> V_13 -> V_22 ;
V_6 -> V_21 . V_23 = V_3 -> V_13 -> V_24 . V_25 ;
V_6 -> V_21 . V_26 = V_3 -> V_13 -> V_24 . V_27 ;
return V_12 ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_28 = F_1 ( V_3 ) ;
if ( ! V_28 -> V_29 )
return 0 ;
if ( V_28 -> V_30 ) {
V_28 -> V_30 -> V_31 . V_32 = V_33 ;
F_9 ( V_28 -> V_30 ) ;
}
if ( V_28 -> V_13 -> V_34 . V_35 )
F_10 ( V_28 -> V_13 -> V_34 . V_35 ) ;
V_28 -> V_29 = false ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_28 = F_1 ( V_3 ) ;
if ( ! V_28 -> V_36 )
return 0 ;
if ( V_28 -> V_37 )
F_12 ( V_28 -> V_37 , 0 ) ;
F_13 ( V_28 -> V_38 ) ;
if ( V_28 -> V_13 -> V_34 . V_39 )
F_10 ( V_28 -> V_13 -> V_34 . V_39 ) ;
V_28 -> V_36 = false ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_28 = F_1 ( V_3 ) ;
int V_40 ;
if ( V_28 -> V_36 )
return 0 ;
V_40 = F_15 ( V_28 -> V_38 ) ;
if ( V_40 < 0 ) {
F_5 ( V_3 -> V_17 , L_2 , V_40 ) ;
return V_40 ;
}
if ( V_28 -> V_37 )
F_12 ( V_28 -> V_37 , 1 ) ;
if ( V_28 -> V_13 -> V_34 . V_41 )
F_10 ( V_28 -> V_13 -> V_34 . V_41 ) ;
V_28 -> V_36 = true ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_28 = F_1 ( V_3 ) ;
if ( V_28 -> V_29 )
return 0 ;
if ( V_28 -> V_13 -> V_34 . V_42 )
F_10 ( V_28 -> V_13 -> V_34 . V_42 ) ;
if ( V_28 -> V_30 ) {
V_28 -> V_30 -> V_31 . V_32 = V_43 ;
F_9 ( V_28 -> V_30 ) ;
}
V_28 -> V_29 = true ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_28 = F_1 ( V_3 ) ;
int V_12 = 0 ;
if ( V_28 -> V_44 ) {
struct V_45 * V_45 = F_18 ( V_3 -> V_6 , V_28 -> V_44 ) ;
F_19 ( V_3 -> V_6 , V_45 ) ;
if ( V_45 ) {
V_12 += F_20 ( V_3 -> V_6 , V_45 ) ;
F_21 ( V_45 ) ;
}
}
V_12 += F_3 ( V_28 ) ;
return V_12 ;
}
static int F_22 ( struct V_46 * V_17 , const struct V_47 * V_13 )
{
struct V_48 * V_30 , * V_44 ;
struct V_1 * V_3 ;
int V_40 ;
V_3 = F_23 ( V_17 , sizeof( * V_3 ) , V_49 ) ;
if ( ! V_3 )
return - V_50 ;
V_3 -> V_29 = false ;
V_3 -> V_36 = false ;
V_3 -> V_13 = V_13 ;
V_3 -> V_38 = F_24 ( V_17 , L_3 ) ;
if ( F_25 ( V_3 -> V_38 ) )
return F_26 ( V_3 -> V_38 ) ;
V_3 -> V_37 = F_27 ( V_17 , L_4 ) ;
if ( F_25 ( V_3 -> V_37 ) ) {
V_40 = F_26 ( V_3 -> V_37 ) ;
F_5 ( V_17 , L_5 , V_40 ) ;
return V_40 ;
}
if ( V_3 -> V_37 ) {
V_40 = F_28 ( V_3 -> V_37 , 0 ) ;
if ( V_40 < 0 ) {
F_5 ( V_17 , L_6 , V_40 ) ;
return V_40 ;
}
}
V_30 = F_29 ( V_17 -> V_51 , L_7 , 0 ) ;
if ( V_30 ) {
V_3 -> V_30 = F_30 ( V_30 ) ;
F_31 ( V_30 ) ;
if ( ! V_3 -> V_30 )
return - V_52 ;
}
V_44 = F_29 ( V_17 -> V_51 , L_8 , 0 ) ;
if ( V_44 ) {
V_3 -> V_44 = F_32 ( V_44 ) ;
F_31 ( V_44 ) ;
if ( ! V_3 -> V_44 ) {
V_40 = - V_52 ;
goto V_53;
}
}
F_33 ( & V_3 -> V_4 ) ;
V_3 -> V_4 . V_17 = V_17 ;
V_3 -> V_4 . V_54 = & V_55 ;
V_40 = F_34 ( & V_3 -> V_4 ) ;
if ( V_40 < 0 )
goto V_56;
F_35 ( V_17 , V_3 ) ;
return 0 ;
V_56:
if ( V_3 -> V_44 )
F_36 ( & V_3 -> V_44 -> V_17 ) ;
V_53:
if ( V_3 -> V_30 )
F_36 ( & V_3 -> V_30 -> V_17 ) ;
return V_40 ;
}
static int F_37 ( struct V_46 * V_17 )
{
struct V_1 * V_3 = F_38 ( V_17 ) ;
F_39 ( & V_3 -> V_4 ) ;
F_40 ( & V_3 -> V_4 ) ;
F_8 ( & V_3 -> V_4 ) ;
if ( V_3 -> V_44 )
F_36 ( & V_3 -> V_44 -> V_17 ) ;
if ( V_3 -> V_30 )
F_36 ( & V_3 -> V_30 -> V_17 ) ;
return 0 ;
}
static void F_41 ( struct V_46 * V_17 )
{
struct V_1 * V_3 = F_38 ( V_17 ) ;
F_8 ( & V_3 -> V_4 ) ;
}
static int F_42 ( struct V_57 * V_58 )
{
const struct V_59 * V_60 ;
V_60 = F_43 ( V_61 , V_58 -> V_17 . V_51 ) ;
if ( ! V_60 )
return - V_62 ;
return F_22 ( & V_58 -> V_17 , V_60 -> V_63 ) ;
}
static int F_44 ( struct V_57 * V_58 )
{
return F_37 ( & V_58 -> V_17 ) ;
}
static void F_45 ( struct V_57 * V_58 )
{
F_41 ( & V_58 -> V_17 ) ;
}
static int F_46 ( struct V_64 * V_65 )
{
const struct V_66 * V_13 ;
const struct V_59 * V_60 ;
int V_40 ;
V_60 = F_43 ( V_67 , V_65 -> V_17 . V_51 ) ;
if ( ! V_60 )
return - V_62 ;
V_13 = V_60 -> V_63 ;
V_40 = F_22 ( & V_65 -> V_17 , & V_13 -> V_13 ) ;
if ( V_40 < 0 )
return V_40 ;
V_65 -> V_68 = V_13 -> V_69 ;
V_65 -> V_70 = V_13 -> V_70 ;
V_65 -> V_71 = V_13 -> V_71 ;
return F_47 ( V_65 ) ;
}
static int F_48 ( struct V_64 * V_65 )
{
int V_40 ;
V_40 = F_49 ( V_65 ) ;
if ( V_40 < 0 )
F_5 ( & V_65 -> V_17 , L_9 , V_40 ) ;
return F_37 ( & V_65 -> V_17 ) ;
}
static void F_50 ( struct V_64 * V_65 )
{
F_41 ( & V_65 -> V_17 ) ;
}
static int T_1 F_51 ( void )
{
int V_40 ;
V_40 = F_52 ( & V_72 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( F_53 ( V_73 ) ) {
V_40 = F_54 ( & V_74 ) ;
if ( V_40 < 0 )
return V_40 ;
}
return 0 ;
}
static void T_2 F_55 ( void )
{
if ( F_53 ( V_73 ) )
F_56 ( & V_74 ) ;
F_57 ( & V_72 ) ;
}

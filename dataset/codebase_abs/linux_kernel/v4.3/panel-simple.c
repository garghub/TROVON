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
const struct V_15 * V_16 = & V_3 -> V_13 -> V_17 [ V_11 ] ;
struct V_18 V_19 ;
F_4 ( V_16 , & V_19 ) ;
V_10 = F_5 ( V_8 ) ;
if ( ! V_10 ) {
F_6 ( V_8 -> V_20 , L_1 ,
V_16 -> V_21 . V_22 , V_16 -> V_23 . V_22 ) ;
continue;
}
F_7 ( & V_19 , V_10 ) ;
F_8 ( V_10 ) ;
F_9 ( V_6 , V_10 ) ;
V_12 ++ ;
}
for ( V_11 = 0 ; V_11 < V_3 -> V_13 -> V_24 ; V_11 ++ ) {
const struct V_9 * V_25 = & V_3 -> V_13 -> V_26 [ V_11 ] ;
V_10 = F_10 ( V_8 , V_25 ) ;
if ( ! V_10 ) {
F_6 ( V_8 -> V_20 , L_2 ,
V_25 -> V_27 , V_25 -> V_28 , V_25 -> V_29 ) ;
continue;
}
F_8 ( V_10 ) ;
F_9 ( V_6 , V_10 ) ;
V_12 ++ ;
}
V_6 -> V_30 . V_31 = V_3 -> V_13 -> V_31 ;
V_6 -> V_30 . V_32 = V_3 -> V_13 -> V_33 . V_34 ;
V_6 -> V_30 . V_35 = V_3 -> V_13 -> V_33 . V_36 ;
if ( V_3 -> V_13 -> V_37 )
F_11 ( & V_6 -> V_30 ,
& V_3 -> V_13 -> V_37 , 1 ) ;
return V_12 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_38 = F_1 ( V_3 ) ;
if ( ! V_38 -> V_39 )
return 0 ;
if ( V_38 -> V_40 ) {
V_38 -> V_40 -> V_41 . V_42 = V_43 ;
F_13 ( V_38 -> V_40 ) ;
}
if ( V_38 -> V_13 -> V_44 . V_45 )
F_14 ( V_38 -> V_13 -> V_44 . V_45 ) ;
V_38 -> V_39 = false ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_38 = F_1 ( V_3 ) ;
if ( ! V_38 -> V_46 )
return 0 ;
if ( V_38 -> V_47 )
F_16 ( V_38 -> V_47 , 0 ) ;
F_17 ( V_38 -> V_48 ) ;
if ( V_38 -> V_13 -> V_44 . V_49 )
F_14 ( V_38 -> V_13 -> V_44 . V_49 ) ;
V_38 -> V_46 = false ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_38 = F_1 ( V_3 ) ;
int V_50 ;
if ( V_38 -> V_46 )
return 0 ;
V_50 = F_19 ( V_38 -> V_48 ) ;
if ( V_50 < 0 ) {
F_6 ( V_3 -> V_20 , L_3 , V_50 ) ;
return V_50 ;
}
if ( V_38 -> V_47 )
F_16 ( V_38 -> V_47 , 1 ) ;
if ( V_38 -> V_13 -> V_44 . V_51 )
F_14 ( V_38 -> V_13 -> V_44 . V_51 ) ;
V_38 -> V_46 = true ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_38 = F_1 ( V_3 ) ;
if ( V_38 -> V_39 )
return 0 ;
if ( V_38 -> V_13 -> V_44 . V_52 )
F_14 ( V_38 -> V_13 -> V_44 . V_52 ) ;
if ( V_38 -> V_40 ) {
V_38 -> V_40 -> V_41 . V_42 = V_53 ;
F_13 ( V_38 -> V_40 ) ;
}
V_38 -> V_39 = true ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_38 = F_1 ( V_3 ) ;
int V_12 = 0 ;
if ( V_38 -> V_54 ) {
struct V_55 * V_55 = F_22 ( V_3 -> V_6 , V_38 -> V_54 ) ;
F_23 ( V_3 -> V_6 , V_55 ) ;
if ( V_55 ) {
V_12 += F_24 ( V_3 -> V_6 , V_55 ) ;
F_25 ( V_55 ) ;
}
}
V_12 += F_3 ( V_38 ) ;
return V_12 ;
}
static int F_26 ( struct V_2 * V_3 ,
unsigned int V_14 ,
struct V_15 * V_17 )
{
struct V_1 * V_38 = F_1 ( V_3 ) ;
unsigned int V_11 ;
if ( V_38 -> V_13 -> V_14 < V_14 )
V_14 = V_38 -> V_13 -> V_14 ;
if ( V_17 )
for ( V_11 = 0 ; V_11 < V_14 ; V_11 ++ )
V_17 [ V_11 ] = V_38 -> V_13 -> V_17 [ V_11 ] ;
return V_38 -> V_13 -> V_14 ;
}
static int F_27 ( struct V_56 * V_20 , const struct V_57 * V_13 )
{
struct V_58 * V_40 , * V_54 ;
struct V_1 * V_3 ;
int V_50 ;
V_3 = F_28 ( V_20 , sizeof( * V_3 ) , V_59 ) ;
if ( ! V_3 )
return - V_60 ;
V_3 -> V_39 = false ;
V_3 -> V_46 = false ;
V_3 -> V_13 = V_13 ;
V_3 -> V_48 = F_29 ( V_20 , L_4 ) ;
if ( F_30 ( V_3 -> V_48 ) )
return F_31 ( V_3 -> V_48 ) ;
V_3 -> V_47 = F_32 ( V_20 , L_5 ,
V_61 ) ;
if ( F_30 ( V_3 -> V_47 ) ) {
V_50 = F_31 ( V_3 -> V_47 ) ;
F_6 ( V_20 , L_6 , V_50 ) ;
return V_50 ;
}
V_40 = F_33 ( V_20 -> V_62 , L_7 , 0 ) ;
if ( V_40 ) {
V_3 -> V_40 = F_34 ( V_40 ) ;
F_35 ( V_40 ) ;
if ( ! V_3 -> V_40 )
return - V_63 ;
}
V_54 = F_33 ( V_20 -> V_62 , L_8 , 0 ) ;
if ( V_54 ) {
V_3 -> V_54 = F_36 ( V_54 ) ;
F_35 ( V_54 ) ;
if ( ! V_3 -> V_54 ) {
V_50 = - V_63 ;
goto V_64;
}
}
F_37 ( & V_3 -> V_4 ) ;
V_3 -> V_4 . V_20 = V_20 ;
V_3 -> V_4 . V_65 = & V_66 ;
V_50 = F_38 ( & V_3 -> V_4 ) ;
if ( V_50 < 0 )
goto V_67;
F_39 ( V_20 , V_3 ) ;
return 0 ;
V_67:
if ( V_3 -> V_54 )
F_40 ( & V_3 -> V_54 -> V_20 ) ;
V_64:
if ( V_3 -> V_40 )
F_40 ( & V_3 -> V_40 -> V_20 ) ;
return V_50 ;
}
static int F_41 ( struct V_56 * V_20 )
{
struct V_1 * V_3 = F_42 ( V_20 ) ;
F_43 ( & V_3 -> V_4 ) ;
F_44 ( & V_3 -> V_4 ) ;
F_12 ( & V_3 -> V_4 ) ;
if ( V_3 -> V_54 )
F_40 ( & V_3 -> V_54 -> V_20 ) ;
if ( V_3 -> V_40 )
F_40 ( & V_3 -> V_40 -> V_20 ) ;
return 0 ;
}
static void F_45 ( struct V_56 * V_20 )
{
struct V_1 * V_3 = F_42 ( V_20 ) ;
F_12 ( & V_3 -> V_4 ) ;
}
static int F_46 ( struct V_68 * V_69 )
{
const struct V_70 * V_71 ;
V_71 = F_47 ( V_72 , V_69 -> V_20 . V_62 ) ;
if ( ! V_71 )
return - V_73 ;
return F_27 ( & V_69 -> V_20 , V_71 -> V_74 ) ;
}
static int F_48 ( struct V_68 * V_69 )
{
return F_41 ( & V_69 -> V_20 ) ;
}
static void F_49 ( struct V_68 * V_69 )
{
F_45 ( & V_69 -> V_20 ) ;
}
static int F_50 ( struct V_75 * V_76 )
{
const struct V_77 * V_13 ;
const struct V_70 * V_71 ;
int V_50 ;
V_71 = F_47 ( V_78 , V_76 -> V_20 . V_62 ) ;
if ( ! V_71 )
return - V_73 ;
V_13 = V_71 -> V_74 ;
V_50 = F_27 ( & V_76 -> V_20 , & V_13 -> V_13 ) ;
if ( V_50 < 0 )
return V_50 ;
V_76 -> V_79 = V_13 -> V_80 ;
V_76 -> V_81 = V_13 -> V_81 ;
V_76 -> V_82 = V_13 -> V_82 ;
return F_51 ( V_76 ) ;
}
static int F_52 ( struct V_75 * V_76 )
{
int V_50 ;
V_50 = F_53 ( V_76 ) ;
if ( V_50 < 0 )
F_6 ( & V_76 -> V_20 , L_9 , V_50 ) ;
return F_41 ( & V_76 -> V_20 ) ;
}
static void F_54 ( struct V_75 * V_76 )
{
F_45 ( & V_76 -> V_20 ) ;
}
static int T_1 F_55 ( void )
{
int V_50 ;
V_50 = F_56 ( & V_83 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( F_57 ( V_84 ) ) {
V_50 = F_58 ( & V_85 ) ;
if ( V_50 < 0 )
return V_50 ;
}
return 0 ;
}
static void T_2 F_59 ( void )
{
if ( F_57 ( V_84 ) )
F_60 ( & V_85 ) ;
F_61 ( & V_83 ) ;
}

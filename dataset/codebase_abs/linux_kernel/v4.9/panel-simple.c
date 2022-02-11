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
V_10 -> type |= V_24 ;
if ( V_3 -> V_13 -> V_25 == 1 )
V_10 -> type |= V_26 ;
F_8 ( V_6 , V_10 ) ;
V_12 ++ ;
}
for ( V_11 = 0 ; V_11 < V_3 -> V_13 -> V_25 ; V_11 ++ ) {
const struct V_9 * V_27 = & V_3 -> V_13 -> V_28 [ V_11 ] ;
V_10 = F_9 ( V_8 , V_27 ) ;
if ( ! V_10 ) {
F_6 ( V_8 -> V_20 , L_2 ,
V_27 -> V_29 , V_27 -> V_30 , V_27 -> V_31 ) ;
continue;
}
V_10 -> type |= V_24 ;
if ( V_3 -> V_13 -> V_25 == 1 )
V_10 -> type |= V_26 ;
F_10 ( V_10 ) ;
F_8 ( V_6 , V_10 ) ;
V_12 ++ ;
}
V_6 -> V_32 . V_33 = V_3 -> V_13 -> V_33 ;
V_6 -> V_32 . V_34 = V_3 -> V_13 -> V_35 . V_36 ;
V_6 -> V_32 . V_37 = V_3 -> V_13 -> V_35 . V_38 ;
if ( V_3 -> V_13 -> V_39 )
F_11 ( & V_6 -> V_32 ,
& V_3 -> V_13 -> V_39 , 1 ) ;
V_6 -> V_32 . V_40 = V_3 -> V_13 -> V_40 ;
return V_12 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
if ( ! V_41 -> V_42 )
return 0 ;
if ( V_41 -> V_43 ) {
V_41 -> V_43 -> V_44 . V_45 = V_46 ;
V_41 -> V_43 -> V_44 . V_47 |= V_48 ;
F_13 ( V_41 -> V_43 ) ;
}
if ( V_41 -> V_13 -> V_49 . V_50 )
F_14 ( V_41 -> V_13 -> V_49 . V_50 ) ;
V_41 -> V_42 = false ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
if ( ! V_41 -> V_51 )
return 0 ;
if ( V_41 -> V_52 )
F_16 ( V_41 -> V_52 , 0 ) ;
F_17 ( V_41 -> V_53 ) ;
if ( V_41 -> V_13 -> V_49 . V_54 )
F_14 ( V_41 -> V_13 -> V_49 . V_54 ) ;
V_41 -> V_51 = false ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
int V_55 ;
if ( V_41 -> V_51 )
return 0 ;
V_55 = F_19 ( V_41 -> V_53 ) ;
if ( V_55 < 0 ) {
F_6 ( V_3 -> V_20 , L_3 , V_55 ) ;
return V_55 ;
}
if ( V_41 -> V_52 )
F_16 ( V_41 -> V_52 , 1 ) ;
if ( V_41 -> V_13 -> V_49 . V_56 )
F_14 ( V_41 -> V_13 -> V_49 . V_56 ) ;
V_41 -> V_51 = true ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
if ( V_41 -> V_42 )
return 0 ;
if ( V_41 -> V_13 -> V_49 . V_57 )
F_14 ( V_41 -> V_13 -> V_49 . V_57 ) ;
if ( V_41 -> V_43 ) {
V_41 -> V_43 -> V_44 . V_47 &= ~ V_48 ;
V_41 -> V_43 -> V_44 . V_45 = V_58 ;
F_13 ( V_41 -> V_43 ) ;
}
V_41 -> V_42 = true ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
int V_12 = 0 ;
if ( V_41 -> V_59 ) {
struct V_60 * V_60 = F_22 ( V_3 -> V_6 , V_41 -> V_59 ) ;
F_23 ( V_3 -> V_6 , V_60 ) ;
if ( V_60 ) {
V_12 += F_24 ( V_3 -> V_6 , V_60 ) ;
F_25 ( V_60 ) ;
}
}
V_12 += F_3 ( V_41 ) ;
return V_12 ;
}
static int F_26 ( struct V_2 * V_3 ,
unsigned int V_14 ,
struct V_15 * V_17 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
unsigned int V_11 ;
if ( V_41 -> V_13 -> V_14 < V_14 )
V_14 = V_41 -> V_13 -> V_14 ;
if ( V_17 )
for ( V_11 = 0 ; V_11 < V_14 ; V_11 ++ )
V_17 [ V_11 ] = V_41 -> V_13 -> V_17 [ V_11 ] ;
return V_41 -> V_13 -> V_14 ;
}
static int F_27 ( struct V_61 * V_20 , const struct V_62 * V_13 )
{
struct V_63 * V_43 , * V_59 ;
struct V_1 * V_3 ;
int V_55 ;
V_3 = F_28 ( V_20 , sizeof( * V_3 ) , V_64 ) ;
if ( ! V_3 )
return - V_65 ;
V_3 -> V_42 = false ;
V_3 -> V_51 = false ;
V_3 -> V_13 = V_13 ;
V_3 -> V_53 = F_29 ( V_20 , L_4 ) ;
if ( F_30 ( V_3 -> V_53 ) )
return F_31 ( V_3 -> V_53 ) ;
V_3 -> V_52 = F_32 ( V_20 , L_5 ,
V_66 ) ;
if ( F_30 ( V_3 -> V_52 ) ) {
V_55 = F_31 ( V_3 -> V_52 ) ;
F_6 ( V_20 , L_6 , V_55 ) ;
return V_55 ;
}
V_43 = F_33 ( V_20 -> V_67 , L_7 , 0 ) ;
if ( V_43 ) {
V_3 -> V_43 = F_34 ( V_43 ) ;
F_35 ( V_43 ) ;
if ( ! V_3 -> V_43 )
return - V_68 ;
}
V_59 = F_33 ( V_20 -> V_67 , L_8 , 0 ) ;
if ( V_59 ) {
V_3 -> V_59 = F_36 ( V_59 ) ;
F_35 ( V_59 ) ;
if ( ! V_3 -> V_59 ) {
V_55 = - V_68 ;
goto V_69;
}
}
F_37 ( & V_3 -> V_4 ) ;
V_3 -> V_4 . V_20 = V_20 ;
V_3 -> V_4 . V_70 = & V_71 ;
V_55 = F_38 ( & V_3 -> V_4 ) ;
if ( V_55 < 0 )
goto V_72;
F_39 ( V_20 , V_3 ) ;
return 0 ;
V_72:
if ( V_3 -> V_59 )
F_40 ( & V_3 -> V_59 -> V_20 ) ;
V_69:
if ( V_3 -> V_43 )
F_40 ( & V_3 -> V_43 -> V_20 ) ;
return V_55 ;
}
static int F_41 ( struct V_61 * V_20 )
{
struct V_1 * V_3 = F_42 ( V_20 ) ;
F_43 ( & V_3 -> V_4 ) ;
F_44 ( & V_3 -> V_4 ) ;
F_12 ( & V_3 -> V_4 ) ;
if ( V_3 -> V_59 )
F_40 ( & V_3 -> V_59 -> V_20 ) ;
if ( V_3 -> V_43 )
F_40 ( & V_3 -> V_43 -> V_20 ) ;
return 0 ;
}
static void F_45 ( struct V_61 * V_20 )
{
struct V_1 * V_3 = F_42 ( V_20 ) ;
F_12 ( & V_3 -> V_4 ) ;
}
static int F_46 ( struct V_73 * V_74 )
{
const struct V_75 * V_76 ;
V_76 = F_47 ( V_77 , V_74 -> V_20 . V_67 ) ;
if ( ! V_76 )
return - V_78 ;
return F_27 ( & V_74 -> V_20 , V_76 -> V_79 ) ;
}
static int F_48 ( struct V_73 * V_74 )
{
return F_41 ( & V_74 -> V_20 ) ;
}
static void F_49 ( struct V_73 * V_74 )
{
F_45 ( & V_74 -> V_20 ) ;
}
static int F_50 ( struct V_80 * V_81 )
{
const struct V_82 * V_13 ;
const struct V_75 * V_76 ;
int V_55 ;
V_76 = F_47 ( V_83 , V_81 -> V_20 . V_67 ) ;
if ( ! V_76 )
return - V_78 ;
V_13 = V_76 -> V_79 ;
V_55 = F_27 ( & V_81 -> V_20 , & V_13 -> V_13 ) ;
if ( V_55 < 0 )
return V_55 ;
V_81 -> V_84 = V_13 -> V_85 ;
V_81 -> V_86 = V_13 -> V_86 ;
V_81 -> V_87 = V_13 -> V_87 ;
return F_51 ( V_81 ) ;
}
static int F_52 ( struct V_80 * V_81 )
{
int V_55 ;
V_55 = F_53 ( V_81 ) ;
if ( V_55 < 0 )
F_6 ( & V_81 -> V_20 , L_9 , V_55 ) ;
return F_41 ( & V_81 -> V_20 ) ;
}
static void F_54 ( struct V_80 * V_81 )
{
F_45 ( & V_81 -> V_20 ) ;
}
static int T_1 F_55 ( void )
{
int V_55 ;
V_55 = F_56 ( & V_88 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( F_57 ( V_89 ) ) {
V_55 = F_58 ( & V_90 ) ;
if ( V_55 < 0 )
return V_55 ;
}
return 0 ;
}
static void T_2 F_59 ( void )
{
if ( F_57 ( V_89 ) )
F_60 ( & V_90 ) ;
F_61 ( & V_88 ) ;
}

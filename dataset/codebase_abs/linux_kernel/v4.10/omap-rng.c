static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 + V_2 -> V_5 -> V_6 [ V_3 ] ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_2 V_3 ,
T_1 V_7 )
{
F_4 ( V_7 , V_2 -> V_4 + V_2 -> V_5 -> V_6 [ V_3 ] ) ;
}
static int F_5 ( struct V_8 * V_9 , void * V_10 , T_3 V_11 ,
bool V_12 )
{
struct V_1 * V_2 ;
int V_13 , V_14 ;
V_2 = (struct V_1 * ) V_9 -> V_2 ;
if ( V_11 < V_2 -> V_5 -> V_15 )
return 0 ;
for ( V_13 = 0 ; V_13 < 20 ; V_13 ++ ) {
V_14 = V_2 -> V_5 -> V_16 ( V_2 ) ;
if ( V_14 || ! V_12 )
break;
F_6 ( 10 ) ;
}
if ( ! V_14 )
return 0 ;
F_7 ( V_10 , V_2 -> V_4 + V_2 -> V_5 -> V_6 [ V_17 ] ,
V_2 -> V_5 -> V_15 ) ;
if ( V_2 -> V_5 -> V_6 [ V_18 ] )
F_3 ( V_2 , V_18 , V_19 ) ;
return V_2 -> V_5 -> V_15 ;
}
static int F_8 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_9 -> V_2 ;
return V_2 -> V_5 -> V_20 ( V_2 ) ;
}
static void F_9 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_9 -> V_2 ;
V_2 -> V_5 -> V_21 ( V_2 ) ;
}
static inline T_1 F_10 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_22 ) ? 0 : 1 ;
}
static int F_11 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_23 , 0x1 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_23 , 0x0 ) ;
}
static inline T_1 F_13 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_22 ) & V_24 ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_1 V_7 ;
if ( F_1 ( V_2 , V_25 ) & V_26 )
return 0 ;
V_7 = 0x5 << V_27 ;
V_7 |= V_28 << V_29 ;
F_3 ( V_2 , V_30 , V_7 ) ;
F_3 ( V_2 , V_31 , 0x0 ) ;
F_3 ( V_2 , V_32 , V_33 ) ;
V_7 = V_26 ;
F_3 ( V_2 , V_25 , V_7 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_1 V_7 ;
if ( F_1 ( V_2 , V_25 ) & V_26 )
return 0 ;
V_7 = V_34 << V_27 ;
V_7 |= V_28 << V_29 ;
F_3 ( V_2 , V_30 , V_7 ) ;
F_3 ( V_2 , V_31 , 0x0 ) ;
F_3 ( V_2 , V_32 , V_33 ) ;
V_7 = V_35 << V_36 ;
V_7 |= V_37 << V_38 ;
F_3 ( V_2 , V_39 , V_7 ) ;
V_7 = V_40 << V_41 ;
V_7 |= V_26 ;
F_3 ( V_2 , V_25 , V_7 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_1 ( V_2 , V_25 ) ;
V_7 &= ~ V_26 ;
F_3 ( V_2 , V_25 , V_7 ) ;
}
static T_4 F_17 ( int V_42 , void * V_43 )
{
struct V_1 * V_2 = V_43 ;
T_1 V_44 , V_45 ;
F_3 ( V_2 , V_46 , 0x0 ) ;
F_3 ( V_2 , V_47 , 0x0 ) ;
V_45 = F_1 ( V_2 , V_32 ) ;
V_44 = ~ V_45 & V_48 ;
V_44 = V_44 | F_1 ( V_2 , V_31 ) ;
V_45 = V_33 ;
F_3 ( V_2 , V_31 , V_44 ) ;
F_3 ( V_2 , V_32 , V_45 ) ;
F_3 ( V_2 , V_18 , V_49 ) ;
return V_50 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
const struct V_53 * V_54 ;
struct V_55 * V_56 = & V_52 -> V_56 ;
int V_42 , V_57 ;
V_54 = F_19 ( F_20 ( V_58 ) , V_56 ) ;
if ( ! V_54 ) {
F_21 ( V_56 , L_1 ) ;
return - V_59 ;
}
V_2 -> V_5 = V_54 -> V_10 ;
if ( F_22 ( V_56 -> V_60 , L_2 ) ||
F_22 ( V_56 -> V_60 , L_3 ) ) {
V_42 = F_23 ( V_52 , 0 ) ;
if ( V_42 < 0 ) {
F_21 ( V_56 , L_4 ,
V_61 , V_42 ) ;
return V_42 ;
}
V_57 = F_24 ( V_56 , V_42 , F_17 ,
V_62 , F_25 ( V_56 ) , V_2 ) ;
if ( V_57 ) {
F_21 ( V_56 , L_5 ,
V_42 , V_57 ) ;
return V_57 ;
}
F_3 ( V_2 , V_63 , V_64 ) ;
V_2 -> V_65 = F_26 ( V_52 -> V_56 . V_60 , 0 ) ;
if ( F_27 ( V_2 -> V_65 ) && F_28 ( V_2 -> V_65 ) == - V_66 )
return - V_66 ;
if ( ! F_27 ( V_2 -> V_65 ) ) {
V_57 = F_29 ( V_2 -> V_65 ) ;
if ( V_57 )
F_21 ( & V_52 -> V_56 , L_6
L_7 , V_57 ) ;
}
}
return 0 ;
}
static int F_18 ( struct V_1 * V_67 ,
struct V_51 * V_52 )
{
return - V_59 ;
}
static int F_30 ( struct V_1 * V_67 )
{
V_67 -> V_5 = & V_68 ;
return 0 ;
}
static int F_31 ( struct V_51 * V_52 )
{
struct V_1 * V_2 ;
struct V_69 * V_70 ;
struct V_55 * V_56 = & V_52 -> V_56 ;
int V_71 ;
V_2 = F_32 ( V_56 , sizeof( struct V_1 ) , V_72 ) ;
if ( ! V_2 )
return - V_73 ;
V_2 -> V_9 . V_74 = F_5 ;
V_2 -> V_9 . V_20 = F_8 ;
V_2 -> V_9 . V_21 = F_9 ;
V_2 -> V_9 . V_2 = ( unsigned long ) V_2 ;
F_33 ( V_52 , V_2 ) ;
V_2 -> V_56 = V_56 ;
V_70 = F_34 ( V_52 , V_75 , 0 ) ;
V_2 -> V_4 = F_35 ( V_56 , V_70 ) ;
if ( F_27 ( V_2 -> V_4 ) ) {
V_71 = F_28 ( V_2 -> V_4 ) ;
goto V_76;
}
V_2 -> V_9 . V_77 = F_36 ( V_56 , F_25 ( V_56 ) , V_72 ) ;
if ( ! V_2 -> V_9 . V_77 ) {
V_71 = - V_73 ;
goto V_76;
}
F_37 ( & V_52 -> V_56 ) ;
V_71 = F_38 ( & V_52 -> V_56 ) ;
if ( V_71 < 0 ) {
F_21 ( & V_52 -> V_56 , L_8 , V_71 ) ;
F_39 ( & V_52 -> V_56 ) ;
goto V_76;
}
V_71 = ( V_56 -> V_60 ) ? F_18 ( V_2 , V_52 ) :
F_30 ( V_2 ) ;
if ( V_71 )
goto V_78;
V_71 = F_40 ( & V_2 -> V_9 ) ;
if ( V_71 )
goto V_78;
F_41 ( & V_52 -> V_56 , L_9 ,
F_1 ( V_2 , V_79 ) ) ;
return 0 ;
V_78:
V_2 -> V_4 = NULL ;
F_42 ( & V_52 -> V_56 ) ;
F_43 ( & V_52 -> V_56 ) ;
if ( ! F_27 ( V_2 -> V_65 ) )
F_44 ( V_2 -> V_65 ) ;
V_76:
F_21 ( V_56 , L_10 ) ;
return V_71 ;
}
static int F_45 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_46 ( V_52 ) ;
F_47 ( & V_2 -> V_9 ) ;
V_2 -> V_5 -> V_21 ( V_2 ) ;
F_42 ( & V_52 -> V_56 ) ;
F_43 ( & V_52 -> V_56 ) ;
if ( ! F_27 ( V_2 -> V_65 ) )
F_44 ( V_2 -> V_65 ) ;
return 0 ;
}
static int T_5 F_48 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_49 ( V_56 ) ;
V_2 -> V_5 -> V_21 ( V_2 ) ;
F_42 ( V_56 ) ;
return 0 ;
}
static int T_5 F_50 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_49 ( V_56 ) ;
int V_71 ;
V_71 = F_38 ( V_56 ) ;
if ( V_71 < 0 ) {
F_21 ( V_56 , L_8 , V_71 ) ;
F_39 ( V_56 ) ;
return V_71 ;
}
V_2 -> V_5 -> V_20 ( V_2 ) ;
return 0 ;
}

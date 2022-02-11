static inline T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
return F_2 ( V_2 -> V_4 + V_2 -> V_5 -> V_6 [ V_3 ] ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_2 V_3 ,
T_1 V_7 )
{
F_4 ( V_7 , V_2 -> V_4 + V_2 -> V_5 -> V_6 [ V_3 ] ) ;
}
static int F_5 ( struct V_8 * V_9 , int V_10 )
{
struct V_1 * V_2 ;
int V_11 , V_12 ;
V_2 = (struct V_1 * ) V_9 -> V_2 ;
for ( V_12 = 0 ; V_12 < 20 ; V_12 ++ ) {
V_11 = V_2 -> V_5 -> V_13 ( V_2 ) ;
if ( V_11 || ! V_10 )
break;
F_6 ( 10 ) ;
}
return V_11 ;
}
static int F_7 ( struct V_8 * V_9 , T_1 * V_11 )
{
struct V_1 * V_2 ;
T_1 V_14 , V_12 ;
V_2 = (struct V_1 * ) V_9 -> V_2 ;
V_14 = V_2 -> V_5 -> V_14 ;
for ( V_12 = 0 ; V_12 < V_14 / sizeof( T_1 ) ; V_12 ++ )
V_11 [ V_12 ] = F_1 ( V_2 , V_15 + V_12 ) ;
if ( V_2 -> V_5 -> V_6 [ V_16 ] )
F_3 ( V_2 , V_16 , V_17 ) ;
return V_14 ;
}
static int F_8 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_9 -> V_2 ;
return V_2 -> V_5 -> V_18 ( V_2 ) ;
}
static void F_9 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_9 -> V_2 ;
V_2 -> V_5 -> V_19 ( V_2 ) ;
}
static inline T_1 F_10 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_20 ) ? 0 : 1 ;
}
static int F_11 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_21 , 0x1 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_21 , 0x0 ) ;
}
static inline T_1 F_13 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_20 ) & V_22 ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_1 V_7 ;
if ( F_1 ( V_2 , V_23 ) & V_24 )
return 0 ;
V_7 = V_25 << V_26 ;
V_7 |= V_27 << V_28 ;
F_3 ( V_2 , V_29 , V_7 ) ;
F_3 ( V_2 , V_30 , 0x0 ) ;
F_3 ( V_2 , V_31 , V_32 ) ;
V_7 = V_33 << V_34 ;
V_7 |= V_35 << V_36 ;
F_3 ( V_2 , V_37 , V_7 ) ;
V_7 = V_38 << V_39 ;
V_7 |= V_24 ;
F_3 ( V_2 , V_23 , V_7 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_1 ( V_2 , V_23 ) ;
V_7 &= ~ V_24 ;
F_3 ( V_2 , V_23 , V_7 ) ;
}
static T_3 F_16 ( int V_40 , void * V_41 )
{
struct V_1 * V_2 = V_41 ;
T_1 V_42 , V_43 ;
F_3 ( V_2 , V_44 , 0x0 ) ;
F_3 ( V_2 , V_45 , 0x0 ) ;
V_43 = F_1 ( V_2 , V_31 ) ;
V_42 = ~ V_43 & V_46 ;
V_42 = V_42 | F_1 ( V_2 , V_30 ) ;
V_43 = V_32 ;
F_3 ( V_2 , V_30 , V_42 ) ;
F_3 ( V_2 , V_31 , V_43 ) ;
F_3 ( V_2 , V_16 , V_47 ) ;
return V_48 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
const struct V_51 * V_52 ;
struct V_53 * V_54 = & V_50 -> V_54 ;
int V_40 , V_55 ;
V_52 = F_18 ( F_19 ( V_56 ) , V_54 ) ;
if ( ! V_52 ) {
F_20 ( V_54 , L_1 ) ;
return - V_57 ;
}
V_2 -> V_5 = V_52 -> V_11 ;
if ( F_21 ( V_54 -> V_58 , L_2 ) ) {
V_40 = F_22 ( V_50 , 0 ) ;
if ( V_40 < 0 ) {
F_20 ( V_54 , L_3 ,
V_59 , V_40 ) ;
return V_40 ;
}
V_55 = F_23 ( V_54 , V_40 , F_16 ,
V_60 , F_24 ( V_54 ) , V_2 ) ;
if ( V_55 ) {
F_20 ( V_54 , L_4 ,
V_40 , V_55 ) ;
return V_55 ;
}
F_3 ( V_2 , V_61 , V_62 ) ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_63 ,
struct V_49 * V_50 )
{
return - V_57 ;
}
static int F_25 ( struct V_1 * V_63 )
{
V_63 -> V_5 = & V_64 ;
return 0 ;
}
static int F_26 ( struct V_49 * V_50 )
{
struct V_1 * V_2 ;
struct V_65 * V_66 ;
struct V_53 * V_54 = & V_50 -> V_54 ;
int V_67 ;
V_2 = F_27 ( V_54 , sizeof( struct V_1 ) , V_68 ) ;
if ( ! V_2 )
return - V_69 ;
V_70 . V_2 = ( unsigned long ) V_2 ;
F_28 ( V_50 , V_2 ) ;
V_2 -> V_54 = V_54 ;
V_66 = F_29 ( V_50 , V_71 , 0 ) ;
V_2 -> V_4 = F_30 ( V_54 , V_66 ) ;
if ( F_31 ( V_2 -> V_4 ) ) {
V_67 = F_32 ( V_2 -> V_4 ) ;
goto V_72;
}
F_33 ( & V_50 -> V_54 ) ;
V_67 = F_34 ( & V_50 -> V_54 ) ;
if ( V_67 < 0 ) {
F_20 ( & V_50 -> V_54 , L_5 , V_67 ) ;
F_35 ( & V_50 -> V_54 ) ;
goto V_72;
}
V_67 = ( V_54 -> V_58 ) ? F_17 ( V_2 , V_50 ) :
F_25 ( V_2 ) ;
if ( V_67 )
goto V_72;
V_67 = F_36 ( & V_70 ) ;
if ( V_67 )
goto V_73;
F_37 ( & V_50 -> V_54 , L_6 ,
F_1 ( V_2 , V_74 ) ) ;
return 0 ;
V_73:
V_2 -> V_4 = NULL ;
F_38 ( & V_50 -> V_54 ) ;
V_72:
F_20 ( V_54 , L_7 ) ;
return V_67 ;
}
static int F_39 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_40 ( V_50 ) ;
F_41 ( & V_70 ) ;
V_2 -> V_5 -> V_19 ( V_2 ) ;
F_42 ( & V_50 -> V_54 ) ;
F_38 ( & V_50 -> V_54 ) ;
return 0 ;
}
static int T_4 F_43 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_44 ( V_54 ) ;
V_2 -> V_5 -> V_19 ( V_2 ) ;
F_42 ( V_54 ) ;
return 0 ;
}
static int T_4 F_45 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_44 ( V_54 ) ;
int V_67 ;
V_67 = F_34 ( V_54 ) ;
if ( V_67 < 0 ) {
F_20 ( V_54 , L_5 , V_67 ) ;
F_35 ( V_54 ) ;
return V_67 ;
}
V_2 -> V_5 -> V_18 ( V_2 ) ;
return 0 ;
}

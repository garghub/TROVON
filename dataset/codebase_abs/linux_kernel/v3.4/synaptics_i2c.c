static inline void F_1 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 = V_5 / V_3 ;
V_2 -> V_6 = V_3 ;
}
static T_1 F_2 ( struct V_7 * V_8 , T_2 V_9 )
{
int V_10 ;
V_10 = F_3 ( V_8 , V_11 , V_9 >> 8 ) ;
if ( V_10 == 0 )
V_10 = F_4 ( V_8 , V_9 & 0xff ) ;
return V_10 ;
}
static T_1 F_5 ( struct V_7 * V_8 , T_2 V_9 , T_3 V_12 )
{
int V_10 ;
V_10 = F_3 ( V_8 , V_11 , V_9 >> 8 ) ;
if ( V_10 == 0 )
V_10 = F_3 ( V_8 , V_9 & 0xff , V_12 ) ;
return V_10 ;
}
static T_1 F_6 ( struct V_7 * V_8 , T_2 V_9 )
{
int V_10 ;
V_10 = F_3 ( V_8 , V_11 , V_9 >> 8 ) ;
if ( V_10 == 0 )
V_10 = F_7 ( V_8 , V_9 & 0xff ) ;
return V_10 ;
}
static int F_8 ( struct V_7 * V_8 )
{
int V_10 , V_13 ;
T_3 V_14 ;
V_10 = F_5 ( V_8 , V_15 , 0xc1 ) ;
if ( V_10 )
return V_10 ;
V_14 = ( V_16 ) ? 0 : V_17 | V_18 ;
V_10 = F_5 ( V_8 , V_19 , V_14 ) ;
if ( V_10 )
return V_10 ;
V_13 = F_2 ( V_8 , V_20 ) ;
V_13 |= V_21 ? 1 << V_22 : 0 ;
V_13 |= V_23 ? 1 << V_24 : 0 ;
V_13 |= V_25 ? 1 << V_26 : 0 ;
V_10 = F_5 ( V_8 , V_20 , V_13 ) ;
if ( V_10 )
return V_10 ;
return 0 ;
}
static int F_9 ( struct V_7 * V_8 )
{
int V_10 ;
V_10 = F_5 ( V_8 , V_27 , V_28 ) ;
if ( V_10 ) {
F_10 ( & V_8 -> V_29 , L_1 ) ;
} else {
F_11 ( V_30 ) ;
V_10 = F_8 ( V_8 ) ;
if ( V_10 )
F_10 ( & V_8 -> V_29 , L_2 ) ;
}
return V_10 ;
}
static int F_12 ( struct V_7 * V_8 )
{
int V_31 , V_10 = 0 ;
V_31 = F_4 ( V_8 , V_32 ) &
( V_33 | V_34 ) ;
if ( V_31 != V_33 )
V_10 = F_9 ( V_8 ) ;
return V_10 ;
}
static bool F_13 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
int V_37 , V_38 ;
T_1 V_39 ;
T_4 V_40 , V_41 ;
if ( F_12 ( V_2 -> V_8 ) )
return 0 ;
V_39 = F_2 ( V_2 -> V_8 , V_42 ) ;
V_38 = ( V_39 >> V_43 ) & 0x1 ;
V_37 = F_6 ( V_2 -> V_8 , V_44 ) & 0xffff ;
V_40 = V_37 & 0xff ;
V_41 = ( V_37 >> V_45 ) & 0xff ;
F_14 ( V_36 , V_46 , V_38 ) ;
F_15 ( V_36 , V_47 , V_40 ) ;
F_15 ( V_36 , V_48 , - V_41 ) ;
F_16 ( V_36 ) ;
return V_37 || V_38 ;
}
static void F_17 ( struct V_1 * V_2 ,
unsigned long V_49 )
{
unsigned long V_50 ;
F_18 ( & V_2 -> V_51 , V_50 ) ;
F_19 ( & V_2 -> V_52 ) ;
F_20 ( & V_2 -> V_52 , V_49 ) ;
F_21 ( & V_2 -> V_51 , V_50 ) ;
}
static T_5 F_22 ( int V_53 , void * V_54 )
{
struct V_1 * V_2 = V_54 ;
F_17 ( V_2 , 0 ) ;
return V_55 ;
}
static void F_23 ( struct V_1 * V_2 )
{
bool V_56 = false ;
if ( V_3 != V_2 -> V_6 )
F_1 ( V_2 , V_3 ) ;
if ( V_21 != V_2 -> V_57 ) {
V_2 -> V_57 = V_21 ;
V_56 = true ;
}
if ( V_25 != V_2 -> V_58 ) {
V_2 -> V_58 = V_25 ;
V_56 = true ;
}
if ( V_23 != V_2 -> V_59 ) {
V_2 -> V_59 = V_23 ;
V_56 = true ;
}
if ( V_56 )
F_9 ( V_2 -> V_8 ) ;
}
static unsigned long F_24 ( struct V_1 * V_2 ,
bool V_60 )
{
unsigned long V_49 , V_61 ;
if ( V_16 ) {
V_49 = V_2 -> V_4 ;
if ( V_60 ) {
V_2 -> V_62 = 0 ;
} else {
V_61 = V_63 / V_2 -> V_4 ;
if ( V_2 -> V_62 < V_61 )
V_2 -> V_62 ++ ;
else
V_49 = V_64 ;
}
return F_25 ( V_49 ) ;
} else {
V_49 = F_25 ( V_65 ) ;
return F_26 ( V_49 ) ;
}
}
static void F_27 ( struct V_66 * V_67 )
{
bool V_60 ;
struct V_1 * V_2 =
F_28 ( V_67 , struct V_1 , V_52 . V_67 ) ;
unsigned long V_49 ;
F_23 ( V_2 ) ;
V_60 = F_13 ( V_2 ) ;
V_49 = F_24 ( V_2 , V_60 ) ;
F_17 ( V_2 , V_49 ) ;
}
static int F_29 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_30 ( V_36 ) ;
int V_10 ;
V_10 = F_9 ( V_2 -> V_8 ) ;
if ( V_10 )
return V_10 ;
if ( V_16 )
F_17 ( V_2 ,
F_25 ( V_64 ) ) ;
return 0 ;
}
static void F_31 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_30 ( V_36 ) ;
if ( ! V_16 )
F_5 ( V_2 -> V_8 , V_19 , 0 ) ;
F_32 ( & V_2 -> V_52 ) ;
F_5 ( V_2 -> V_8 , V_15 , V_68 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
V_36 -> V_69 = V_2 -> V_8 -> V_69 ;
V_36 -> V_70 = V_2 -> V_8 -> V_71 -> V_69 ;
V_36 -> V_72 . V_73 = V_74 ;
V_36 -> V_72 . V_75 = F_6 ( V_2 -> V_8 ,
V_76 ) ;
V_36 -> V_29 . V_77 = & V_2 -> V_8 -> V_29 ;
V_36 -> V_78 = F_29 ;
V_36 -> V_79 = F_31 ;
F_34 ( V_36 , V_2 ) ;
F_35 ( V_80 , V_36 -> V_81 ) ;
F_35 ( V_47 , V_36 -> V_82 ) ;
F_35 ( V_48 , V_36 -> V_82 ) ;
F_35 ( V_83 , V_36 -> V_81 ) ;
F_35 ( V_46 , V_36 -> V_84 ) ;
}
static struct V_1 * F_36 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
V_2 = F_37 ( sizeof( struct V_1 ) , V_85 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_8 = V_8 ;
V_2 -> V_57 = V_21 ;
V_2 -> V_6 = V_3 ;
F_1 ( V_2 , V_3 ) ;
F_38 ( & V_2 -> V_52 , F_27 ) ;
F_39 ( & V_2 -> V_51 ) ;
return V_2 ;
}
static int T_6 F_40 ( struct V_7 * V_8 ,
const struct V_86 * V_54 )
{
int V_10 ;
struct V_1 * V_2 ;
V_2 = F_36 ( V_8 ) ;
if ( ! V_2 )
return - V_87 ;
V_10 = F_9 ( V_8 ) ;
if ( V_10 )
goto V_88;
if ( V_8 -> V_53 < 1 )
V_16 = true ;
V_2 -> V_36 = F_41 () ;
if ( ! V_2 -> V_36 ) {
V_10 = - V_87 ;
goto V_88;
}
F_33 ( V_2 ) ;
if ( ! V_16 ) {
F_42 ( & V_2 -> V_8 -> V_29 ,
L_3 , V_2 -> V_8 -> V_53 ) ;
V_10 = F_43 ( V_2 -> V_8 -> V_53 , F_22 ,
V_89 ,
V_90 , V_2 ) ;
if ( V_10 ) {
F_44 ( & V_2 -> V_8 -> V_29 ,
L_4
L_5 , V_10 ) ;
V_16 = true ;
F_5 ( V_2 -> V_8 ,
V_19 , 0 ) ;
}
}
if ( V_16 )
F_42 ( & V_2 -> V_8 -> V_29 ,
L_6 , V_3 ) ;
V_10 = F_45 ( V_2 -> V_36 ) ;
if ( V_10 ) {
F_10 ( & V_8 -> V_29 ,
L_7 , V_10 ) ;
goto V_91;
}
F_46 ( V_8 , V_2 ) ;
return 0 ;
V_91:
F_47 ( V_2 -> V_36 ) ;
V_88:
F_48 ( V_2 ) ;
return V_10 ;
}
static int T_7 F_49 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_50 ( V_8 ) ;
if ( ! V_16 )
F_51 ( V_8 -> V_53 , V_2 ) ;
F_52 ( V_2 -> V_36 ) ;
F_48 ( V_2 ) ;
return 0 ;
}
static int F_53 ( struct V_92 * V_29 )
{
struct V_7 * V_8 = F_54 ( V_29 ) ;
struct V_1 * V_2 = F_50 ( V_8 ) ;
F_32 ( & V_2 -> V_52 ) ;
F_5 ( V_2 -> V_8 , V_15 , V_68 ) ;
return 0 ;
}
static int F_55 ( struct V_92 * V_29 )
{
int V_10 ;
struct V_7 * V_8 = F_54 ( V_29 ) ;
struct V_1 * V_2 = F_50 ( V_8 ) ;
V_10 = F_9 ( V_8 ) ;
if ( V_10 )
return V_10 ;
F_17 ( V_2 ,
F_25 ( V_64 ) ) ;
return 0 ;
}

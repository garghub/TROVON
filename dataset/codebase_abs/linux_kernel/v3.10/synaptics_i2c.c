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
F_19 ( V_52 , & V_2 -> V_53 , V_49 ) ;
F_20 ( & V_2 -> V_51 , V_50 ) ;
}
static T_5 F_21 ( int V_54 , void * V_55 )
{
struct V_1 * V_2 = V_55 ;
F_17 ( V_2 , 0 ) ;
return V_56 ;
}
static void F_22 ( struct V_1 * V_2 )
{
bool V_57 = false ;
if ( V_3 != V_2 -> V_6 )
F_1 ( V_2 , V_3 ) ;
if ( V_21 != V_2 -> V_58 ) {
V_2 -> V_58 = V_21 ;
V_57 = true ;
}
if ( V_25 != V_2 -> V_59 ) {
V_2 -> V_59 = V_25 ;
V_57 = true ;
}
if ( V_23 != V_2 -> V_60 ) {
V_2 -> V_60 = V_23 ;
V_57 = true ;
}
if ( V_57 )
F_9 ( V_2 -> V_8 ) ;
}
static unsigned long F_23 ( struct V_1 * V_2 ,
bool V_61 )
{
unsigned long V_49 , V_62 ;
if ( V_16 ) {
V_49 = V_2 -> V_4 ;
if ( V_61 ) {
V_2 -> V_63 = 0 ;
} else {
V_62 = V_64 / V_2 -> V_4 ;
if ( V_2 -> V_63 < V_62 )
V_2 -> V_63 ++ ;
else
V_49 = V_65 ;
}
return F_24 ( V_49 ) ;
} else {
V_49 = F_24 ( V_66 ) ;
return F_25 ( V_49 ) ;
}
}
static void F_26 ( struct V_67 * V_68 )
{
bool V_61 ;
struct V_1 * V_2 =
F_27 ( V_68 , struct V_1 , V_53 . V_68 ) ;
unsigned long V_49 ;
F_22 ( V_2 ) ;
V_61 = F_13 ( V_2 ) ;
V_49 = F_23 ( V_2 , V_61 ) ;
F_17 ( V_2 , V_49 ) ;
}
static int F_28 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_29 ( V_36 ) ;
int V_10 ;
V_10 = F_9 ( V_2 -> V_8 ) ;
if ( V_10 )
return V_10 ;
if ( V_16 )
F_17 ( V_2 ,
F_24 ( V_65 ) ) ;
return 0 ;
}
static void F_30 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_29 ( V_36 ) ;
if ( ! V_16 )
F_5 ( V_2 -> V_8 , V_19 , 0 ) ;
F_31 ( & V_2 -> V_53 ) ;
F_5 ( V_2 -> V_8 , V_15 , V_69 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
V_36 -> V_70 = V_2 -> V_8 -> V_70 ;
V_36 -> V_71 = V_2 -> V_8 -> V_72 -> V_70 ;
V_36 -> V_73 . V_74 = V_75 ;
V_36 -> V_73 . V_76 = F_6 ( V_2 -> V_8 ,
V_77 ) ;
V_36 -> V_29 . V_78 = & V_2 -> V_8 -> V_29 ;
V_36 -> V_79 = F_28 ;
V_36 -> V_80 = F_30 ;
F_33 ( V_36 , V_2 ) ;
F_34 ( V_81 , V_36 -> V_82 ) ;
F_34 ( V_47 , V_36 -> V_83 ) ;
F_34 ( V_48 , V_36 -> V_83 ) ;
F_34 ( V_84 , V_36 -> V_82 ) ;
F_34 ( V_46 , V_36 -> V_85 ) ;
}
static struct V_1 * F_35 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
V_2 = F_36 ( sizeof( struct V_1 ) , V_86 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_8 = V_8 ;
V_2 -> V_58 = V_21 ;
V_2 -> V_6 = V_3 ;
F_1 ( V_2 , V_3 ) ;
F_37 ( & V_2 -> V_53 , F_26 ) ;
F_38 ( & V_2 -> V_51 ) ;
return V_2 ;
}
static int F_39 ( struct V_7 * V_8 ,
const struct V_87 * V_55 )
{
int V_10 ;
struct V_1 * V_2 ;
V_2 = F_35 ( V_8 ) ;
if ( ! V_2 )
return - V_88 ;
V_10 = F_9 ( V_8 ) ;
if ( V_10 )
goto V_89;
if ( V_8 -> V_54 < 1 )
V_16 = true ;
V_2 -> V_36 = F_40 () ;
if ( ! V_2 -> V_36 ) {
V_10 = - V_88 ;
goto V_89;
}
F_32 ( V_2 ) ;
if ( ! V_16 ) {
F_41 ( & V_2 -> V_8 -> V_29 ,
L_3 , V_2 -> V_8 -> V_54 ) ;
V_10 = F_42 ( V_2 -> V_8 -> V_54 , F_21 ,
V_90 ,
V_91 , V_2 ) ;
if ( V_10 ) {
F_43 ( & V_2 -> V_8 -> V_29 ,
L_4
L_5 , V_10 ) ;
V_16 = true ;
F_5 ( V_2 -> V_8 ,
V_19 , 0 ) ;
}
}
if ( V_16 )
F_41 ( & V_2 -> V_8 -> V_29 ,
L_6 , V_3 ) ;
V_10 = F_44 ( V_2 -> V_36 ) ;
if ( V_10 ) {
F_10 ( & V_8 -> V_29 ,
L_7 , V_10 ) ;
goto V_92;
}
F_45 ( V_8 , V_2 ) ;
return 0 ;
V_92:
F_46 ( V_2 -> V_36 ) ;
V_89:
F_47 ( V_2 ) ;
return V_10 ;
}
static int F_48 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_49 ( V_8 ) ;
if ( ! V_16 )
F_50 ( V_8 -> V_54 , V_2 ) ;
F_51 ( V_2 -> V_36 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
static int F_52 ( struct V_93 * V_29 )
{
struct V_7 * V_8 = F_53 ( V_29 ) ;
struct V_1 * V_2 = F_49 ( V_8 ) ;
F_31 ( & V_2 -> V_53 ) ;
F_5 ( V_2 -> V_8 , V_15 , V_69 ) ;
return 0 ;
}
static int F_54 ( struct V_93 * V_29 )
{
int V_10 ;
struct V_7 * V_8 = F_53 ( V_29 ) ;
struct V_1 * V_2 = F_49 ( V_8 ) ;
V_10 = F_9 ( V_8 ) ;
if ( V_10 )
return V_10 ;
F_17 ( V_2 ,
F_24 ( V_65 ) ) ;
return 0 ;
}

static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( ( V_3 & 0xff ) < V_4 ) ;
return F_3 ( V_2 , V_3 , V_2 -> V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_6 )
{
F_2 ( ( V_3 & 0xff ) < V_4 ) ;
F_5 ( V_2 , V_3 , V_6 , V_2 -> V_5 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 == 1 )
F_7 ( V_2 -> V_8 . V_9 , V_2 -> V_10 ) ;
F_7 ( V_2 -> V_8 . V_11 , V_2 -> V_12 ) ;
F_4 ( V_2 , V_13 ,
V_2 -> V_8 . V_14 ) ;
F_4 ( V_2 , V_15 ,
V_2 -> V_8 . V_16 ) ;
F_4 ( V_2 , V_17 ,
V_2 -> V_8 . V_18 ) ;
F_4 ( V_2 , V_19 ,
V_2 -> V_8 . V_20 ) ;
F_4 ( V_2 , V_21 ,
V_2 -> V_8 . V_22 ) ;
F_7 ( V_2 -> V_8 . V_23 , V_2 -> V_24 ) ;
F_4 ( V_2 , V_25 ,
V_2 -> V_8 . V_26 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_27 ;
if ( ! V_2 -> V_10 )
return;
V_27 = 0 ;
while ( ! ( F_9 ( V_2 -> V_10 ) & 1 ) ) {
V_27 ++ ;
if ( V_27 > 100000 ) {
F_10 ( V_28 L_1 ) ;
return;
}
}
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
if ( V_2 -> V_29 -> V_30 != 1 ) {
F_4 ( V_2 , V_21 , 0x06 ) ;
F_8 ( V_2 ) ;
}
F_13 ( V_2 , 0 , 0 ) ;
F_14 ( V_2 ) ;
V_2 -> V_5 = 1 ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = V_2 -> V_29 -> V_33 . V_34 ;
int V_35 ;
V_2 -> V_36 = F_16 ( & V_2 -> V_29 -> V_33 , L_2 ) ;
if ( F_17 ( F_18 ( V_2 -> V_36 ) ) ) {
V_2 -> V_36 = NULL ;
F_19 ( & V_2 -> V_29 -> V_33 , L_3 ) ;
return - V_37 ;
}
if ( V_32 -> V_38 )
F_11 ( V_2 ) ;
V_35 = F_20 ( V_2 , V_39 ) ;
V_2 -> V_5 = 1 ;
return V_35 ;
}
struct V_1 * F_21 ( void )
{
struct V_1 * V_2 = NULL , * V_40 ;
unsigned long V_41 ;
int V_35 = 0 ;
F_22 ( & V_42 , V_41 ) ;
F_23 (t, &omap_timer_list, node) {
if ( V_40 -> V_43 )
continue;
V_2 = V_40 ;
V_2 -> V_43 = 1 ;
break;
}
if ( V_2 ) {
V_35 = F_15 ( V_2 ) ;
if ( V_35 ) {
V_2 -> V_43 = 0 ;
V_2 = NULL ;
}
}
F_24 ( & V_42 , V_41 ) ;
if ( ! V_2 )
F_25 ( L_4 , V_44 ) ;
return V_2 ;
}
struct V_1 * F_26 ( int V_30 )
{
struct V_1 * V_2 = NULL , * V_40 ;
unsigned long V_41 ;
int V_35 = 0 ;
F_22 ( & V_42 , V_41 ) ;
F_23 (t, &omap_timer_list, node) {
if ( V_40 -> V_29 -> V_30 == V_30 && ! V_40 -> V_43 ) {
V_2 = V_40 ;
V_2 -> V_43 = 1 ;
break;
}
}
if ( V_2 ) {
V_35 = F_15 ( V_2 ) ;
if ( V_35 ) {
V_2 -> V_43 = 0 ;
V_2 = NULL ;
}
}
F_24 ( & V_42 , V_41 ) ;
if ( ! V_2 )
F_25 ( L_5 , V_44 , V_30 ) ;
return V_2 ;
}
int F_27 ( struct V_1 * V_2 )
{
if ( F_28 ( ! V_2 ) )
return - V_37 ;
F_29 ( V_2 -> V_36 ) ;
F_2 ( ! V_2 -> V_43 ) ;
V_2 -> V_43 = 0 ;
return 0 ;
}
void F_12 ( struct V_1 * V_2 )
{
F_30 ( & V_2 -> V_29 -> V_33 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
F_31 ( & V_2 -> V_29 -> V_33 ) ;
}
int F_32 ( struct V_1 * V_2 )
{
if ( V_2 )
return V_2 -> V_45 ;
return - V_37 ;
}
T_2 F_33 ( T_2 V_46 )
{
int V_47 = 0 ;
struct V_1 * V_2 = NULL ;
unsigned long V_41 ;
if ( ! ( V_46 & ( 1 << 1 ) ) )
return V_46 ;
F_22 ( & V_42 , V_41 ) ;
F_23 (timer, &omap_timer_list, node) {
T_1 V_48 ;
V_48 = F_1 ( V_2 , V_25 ) ;
if ( V_48 & V_49 ) {
if ( ( ( F_34 ( V_50 ) >> ( V_47 * 2 ) ) & 0x03 ) == 0 )
V_46 &= ~ ( 1 << 1 ) ;
else
V_46 &= ~ ( 1 << 2 ) ;
}
V_47 ++ ;
}
F_24 ( & V_42 , V_41 ) ;
return V_46 ;
}
struct V_51 * F_35 ( struct V_1 * V_2 )
{
if ( V_2 )
return V_2 -> V_36 ;
return NULL ;
}
T_2 F_33 ( T_2 V_46 )
{
F_36 () ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 )
{
if ( F_28 ( ! V_2 || F_38 ( & V_2 -> V_29 -> V_33 ) ) ) {
F_39 ( L_6 , V_44 ) ;
return - V_37 ;
}
F_4 ( V_2 , V_52 , 0 ) ;
return 0 ;
}
int F_40 ( struct V_1 * V_2 )
{
T_1 V_48 ;
if ( F_28 ( ! V_2 ) )
return - V_37 ;
F_12 ( V_2 ) ;
if ( V_2 -> V_53 ) {
T_1 V_54 =
V_2 -> V_55 ( & V_2 -> V_29 -> V_33 ) ;
if ( V_54 != V_2 -> V_56 )
F_6 ( V_2 ) ;
}
V_48 = F_1 ( V_2 , V_25 ) ;
if ( ! ( V_48 & V_49 ) ) {
V_48 |= V_49 ;
F_4 ( V_2 , V_25 , V_48 ) ;
}
V_2 -> V_8 . V_26 = V_48 ;
return 0 ;
}
int F_41 ( struct V_1 * V_2 )
{
unsigned long V_57 = 0 ;
struct V_31 * V_32 ;
if ( F_28 ( ! V_2 ) )
return - V_37 ;
V_32 = V_2 -> V_29 -> V_33 . V_34 ;
if ( ! V_32 -> V_38 )
V_57 = F_42 ( V_2 -> V_36 ) ;
F_43 ( V_2 , V_2 -> V_5 , V_57 ) ;
if ( V_2 -> V_53 && V_2 -> V_55 )
V_2 -> V_56 =
V_2 -> V_55 ( & V_2 -> V_29 -> V_33 ) ;
V_2 -> V_8 . V_26 =
F_1 ( V_2 , V_25 ) ;
V_2 -> V_8 . V_11 = F_9 ( V_2 -> V_12 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , int V_58 )
{
int V_35 ;
struct V_31 * V_32 ;
if ( F_28 ( ! V_2 ) )
return - V_37 ;
V_32 = V_2 -> V_29 -> V_33 . V_34 ;
if ( V_58 < 0 || V_58 >= 3 )
return - V_37 ;
V_35 = V_32 -> V_59 ( V_2 -> V_29 , V_58 ) ;
return V_35 ;
}
int F_44 ( struct V_1 * V_2 , int V_60 ,
unsigned int V_61 )
{
T_1 V_48 ;
if ( F_28 ( ! V_2 ) )
return - V_37 ;
F_12 ( V_2 ) ;
V_48 = F_1 ( V_2 , V_25 ) ;
if ( V_60 )
V_48 |= V_62 ;
else
V_48 &= ~ V_62 ;
F_4 ( V_2 , V_25 , V_48 ) ;
F_4 ( V_2 , V_17 , V_61 ) ;
F_4 ( V_2 , V_52 , 0 ) ;
V_2 -> V_8 . V_26 = V_48 ;
V_2 -> V_8 . V_18 = V_61 ;
F_14 ( V_2 ) ;
return 0 ;
}
int F_45 ( struct V_1 * V_2 , int V_60 ,
unsigned int V_61 )
{
T_1 V_48 ;
if ( F_28 ( ! V_2 ) )
return - V_37 ;
F_12 ( V_2 ) ;
if ( V_2 -> V_53 ) {
T_1 V_54 =
V_2 -> V_55 ( & V_2 -> V_29 -> V_33 ) ;
if ( V_54 != V_2 -> V_56 )
F_6 ( V_2 ) ;
}
V_48 = F_1 ( V_2 , V_25 ) ;
if ( V_60 ) {
V_48 |= V_62 ;
F_4 ( V_2 , V_17 , V_61 ) ;
} else {
V_48 &= ~ V_62 ;
}
V_48 |= V_49 ;
F_46 ( V_2 , V_48 , V_61 , V_2 -> V_5 ) ;
V_2 -> V_8 . V_26 = V_48 ;
V_2 -> V_8 . V_18 = V_61 ;
V_2 -> V_8 . V_16 = V_61 ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 , int V_63 ,
unsigned int V_64 )
{
T_1 V_48 ;
if ( F_28 ( ! V_2 ) )
return - V_37 ;
F_12 ( V_2 ) ;
V_48 = F_1 ( V_2 , V_25 ) ;
if ( V_63 )
V_48 |= V_65 ;
else
V_48 &= ~ V_65 ;
F_4 ( V_2 , V_25 , V_48 ) ;
F_4 ( V_2 , V_19 , V_64 ) ;
V_2 -> V_8 . V_26 = V_48 ;
V_2 -> V_8 . V_20 = V_64 ;
F_14 ( V_2 ) ;
return 0 ;
}
int F_48 ( struct V_1 * V_2 , int V_66 ,
int V_67 , int V_68 )
{
T_1 V_48 ;
if ( F_28 ( ! V_2 ) )
return - V_37 ;
F_12 ( V_2 ) ;
V_48 = F_1 ( V_2 , V_25 ) ;
V_48 &= ~ ( V_69 | V_70 |
V_71 | ( 0x03 << 10 ) ) ;
if ( V_66 )
V_48 |= V_70 ;
if ( V_67 )
V_48 |= V_71 ;
V_48 |= V_68 << 10 ;
F_4 ( V_2 , V_25 , V_48 ) ;
V_2 -> V_8 . V_26 = V_48 ;
F_14 ( V_2 ) ;
return 0 ;
}
int F_49 ( struct V_1 * V_2 , int V_72 )
{
T_1 V_48 ;
if ( F_28 ( ! V_2 ) )
return - V_37 ;
F_12 ( V_2 ) ;
V_48 = F_1 ( V_2 , V_25 ) ;
V_48 &= ~ ( V_73 | ( 0x07 << 2 ) ) ;
if ( V_72 >= 0x00 && V_72 <= 0x07 ) {
V_48 |= V_73 ;
V_48 |= V_72 << 2 ;
}
F_4 ( V_2 , V_25 , V_48 ) ;
V_2 -> V_8 . V_26 = V_48 ;
F_14 ( V_2 ) ;
return 0 ;
}
int F_50 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
if ( F_28 ( ! V_2 ) )
return - V_37 ;
F_12 ( V_2 ) ;
F_51 ( V_2 , V_6 ) ;
V_2 -> V_8 . V_23 = V_6 ;
V_2 -> V_8 . V_14 = V_6 ;
F_14 ( V_2 ) ;
return 0 ;
}
unsigned int F_52 ( struct V_1 * V_2 )
{
unsigned int V_48 ;
if ( F_28 ( ! V_2 || F_38 ( & V_2 -> V_29 -> V_33 ) ) ) {
F_39 ( L_6 , V_44 ) ;
return 0 ;
}
V_48 = F_9 ( V_2 -> V_12 ) ;
return V_48 ;
}
int F_53 ( struct V_1 * V_2 , unsigned int V_6 )
{
if ( F_28 ( ! V_2 || F_38 ( & V_2 -> V_29 -> V_33 ) ) )
return - V_37 ;
F_54 ( V_2 , V_6 ) ;
V_2 -> V_8 . V_11 = V_6 ;
return 0 ;
}
unsigned int F_55 ( struct V_1 * V_2 )
{
if ( F_28 ( ! V_2 || F_38 ( & V_2 -> V_29 -> V_33 ) ) ) {
F_39 ( L_7 , V_44 ) ;
return 0 ;
}
return F_56 ( V_2 , V_2 -> V_5 ) ;
}
int F_57 ( struct V_1 * V_2 , unsigned int V_6 )
{
if ( F_28 ( ! V_2 || F_38 ( & V_2 -> V_29 -> V_33 ) ) ) {
F_39 ( L_6 , V_44 ) ;
return - V_37 ;
}
F_4 ( V_2 , V_15 , V_6 ) ;
V_2 -> V_8 . V_16 = V_6 ;
return 0 ;
}
int F_58 ( void )
{
struct V_1 * V_2 ;
F_23 (timer, &omap_timer_list, node) {
if ( ! V_2 -> V_43 )
continue;
if ( F_1 ( V_2 , V_25 ) &
V_49 ) {
return 1 ;
}
}
return 0 ;
}
static int T_3 F_59 ( struct V_74 * V_29 )
{
int V_35 ;
unsigned long V_41 ;
struct V_1 * V_2 ;
struct V_75 * V_76 , * V_45 , * V_77 ;
struct V_31 * V_32 = V_29 -> V_33 . V_34 ;
if ( ! V_32 ) {
F_19 ( & V_29 -> V_33 , L_8 , V_44 ) ;
return - V_78 ;
}
V_45 = F_60 ( V_29 , V_79 , 0 ) ;
if ( F_28 ( ! V_45 ) ) {
F_19 ( & V_29 -> V_33 , L_9 , V_44 ) ;
return - V_78 ;
}
V_76 = F_60 ( V_29 , V_80 , 0 ) ;
if ( F_28 ( ! V_76 ) ) {
F_19 ( & V_29 -> V_33 , L_10 , V_44 ) ;
return - V_78 ;
}
V_77 = F_61 ( V_76 -> V_81 , F_62 ( V_76 ) ,
V_29 -> V_82 ) ;
if ( ! V_77 ) {
F_19 ( & V_29 -> V_33 , L_11 , V_44 ) ;
return - V_83 ;
}
V_2 = F_63 ( sizeof( struct V_1 ) , V_84 ) ;
if ( ! V_2 ) {
F_19 ( & V_29 -> V_33 , L_12 ,
V_44 ) ;
V_35 = - V_85 ;
goto V_86;
}
V_2 -> V_87 = F_64 ( V_76 -> V_81 , F_62 ( V_76 ) ) ;
if ( ! V_2 -> V_87 ) {
F_19 ( & V_29 -> V_33 , L_13 , V_44 ) ;
V_35 = - V_85 ;
goto V_88;
}
V_2 -> V_30 = V_29 -> V_30 ;
V_2 -> V_45 = V_45 -> V_81 ;
V_2 -> V_43 = V_32 -> V_43 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_53 = V_32 -> V_53 ;
V_2 -> V_55 = V_32 -> V_55 ;
if ( ! V_32 -> V_38 ) {
F_65 ( & V_29 -> V_33 ) ;
F_66 ( & V_29 -> V_33 ) ;
}
if ( ! V_2 -> V_43 ) {
F_30 ( & V_29 -> V_33 ) ;
F_67 ( V_2 ) ;
F_31 ( & V_29 -> V_33 ) ;
}
F_22 ( & V_42 , V_41 ) ;
F_68 ( & V_2 -> V_89 , & V_90 ) ;
F_24 ( & V_42 , V_41 ) ;
F_69 ( & V_29 -> V_33 , L_14 ) ;
return 0 ;
V_88:
F_70 ( V_2 ) ;
V_86:
F_71 ( V_76 -> V_81 , F_62 ( V_76 ) ) ;
return V_35 ;
}
static int T_4 F_72 ( struct V_74 * V_29 )
{
struct V_1 * V_2 ;
unsigned long V_41 ;
int V_35 = - V_37 ;
F_22 ( & V_42 , V_41 ) ;
F_23 (timer, &omap_timer_list, node)
if ( V_2 -> V_29 -> V_30 == V_29 -> V_30 ) {
F_73 ( & V_2 -> V_89 ) ;
F_70 ( V_2 ) ;
V_35 = 0 ;
break;
}
F_24 ( & V_42 , V_41 ) ;
return V_35 ;
}
static int T_5 F_74 ( void )
{
return F_75 ( & V_91 ) ;
}
static void T_6 F_76 ( void )
{
F_77 ( & V_91 ) ;
}

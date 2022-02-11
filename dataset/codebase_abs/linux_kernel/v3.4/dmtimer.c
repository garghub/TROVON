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
F_7 ( V_2 -> V_7 . V_8 ,
V_2 -> V_9 + V_10 ) ;
if ( V_2 -> V_11 == 1 )
F_7 ( V_2 -> V_7 . V_12 , V_2 -> V_13 ) ;
F_7 ( V_2 -> V_7 . V_14 , V_2 -> V_15 ) ;
F_4 ( V_2 , V_16 ,
V_2 -> V_7 . V_17 ) ;
F_4 ( V_2 , V_18 ,
V_2 -> V_7 . V_19 ) ;
F_4 ( V_2 , V_20 ,
V_2 -> V_7 . V_21 ) ;
F_4 ( V_2 , V_22 ,
V_2 -> V_7 . V_23 ) ;
F_4 ( V_2 , V_24 ,
V_2 -> V_7 . V_25 ) ;
F_7 ( V_2 -> V_7 . V_26 , V_2 -> V_27 ) ;
F_4 ( V_2 , V_28 ,
V_2 -> V_7 . V_29 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_30 ;
if ( ! V_2 -> V_13 )
return;
V_30 = 0 ;
while ( ! ( F_9 ( V_2 -> V_13 ) & 1 ) ) {
V_30 ++ ;
if ( V_30 > 100000 ) {
F_10 ( V_31 L_1 ) ;
return;
}
}
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
if ( V_2 -> V_32 -> V_33 != 1 ) {
F_4 ( V_2 , V_24 , 0x06 ) ;
F_8 ( V_2 ) ;
}
F_13 ( V_2 , 0 , 0 ) ;
F_14 ( V_2 ) ;
V_2 -> V_5 = 1 ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_32 -> V_36 . V_37 ;
int V_38 ;
V_2 -> V_39 = F_16 ( & V_2 -> V_32 -> V_36 , L_2 ) ;
if ( F_17 ( F_18 ( V_2 -> V_39 ) ) ) {
V_2 -> V_39 = NULL ;
F_19 ( & V_2 -> V_32 -> V_36 , L_3 ) ;
return - V_40 ;
}
if ( V_35 -> V_41 )
F_11 ( V_2 ) ;
V_38 = F_20 ( V_2 , V_42 ) ;
V_2 -> V_5 = 1 ;
return V_38 ;
}
struct V_1 * F_21 ( void )
{
struct V_1 * V_2 = NULL , * V_43 ;
unsigned long V_44 ;
int V_38 = 0 ;
F_22 ( & V_45 , V_44 ) ;
F_23 (t, &omap_timer_list, node) {
if ( V_43 -> V_46 )
continue;
V_2 = V_43 ;
V_2 -> V_46 = 1 ;
break;
}
if ( V_2 ) {
V_38 = F_15 ( V_2 ) ;
if ( V_38 ) {
V_2 -> V_46 = 0 ;
V_2 = NULL ;
}
}
F_24 ( & V_45 , V_44 ) ;
if ( ! V_2 )
F_25 ( L_4 , V_47 ) ;
return V_2 ;
}
struct V_1 * F_26 ( int V_33 )
{
struct V_1 * V_2 = NULL , * V_43 ;
unsigned long V_44 ;
int V_38 = 0 ;
F_22 ( & V_45 , V_44 ) ;
F_23 (t, &omap_timer_list, node) {
if ( V_43 -> V_32 -> V_33 == V_33 && ! V_43 -> V_46 ) {
V_2 = V_43 ;
V_2 -> V_46 = 1 ;
break;
}
}
if ( V_2 ) {
V_38 = F_15 ( V_2 ) ;
if ( V_38 ) {
V_2 -> V_46 = 0 ;
V_2 = NULL ;
}
}
F_24 ( & V_45 , V_44 ) ;
if ( ! V_2 )
F_25 ( L_5 , V_47 , V_33 ) ;
return V_2 ;
}
int F_27 ( struct V_1 * V_2 )
{
if ( F_28 ( ! V_2 ) )
return - V_40 ;
F_29 ( V_2 -> V_39 ) ;
F_2 ( ! V_2 -> V_46 ) ;
V_2 -> V_46 = 0 ;
return 0 ;
}
void F_12 ( struct V_1 * V_2 )
{
F_30 ( & V_2 -> V_32 -> V_36 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
F_31 ( & V_2 -> V_32 -> V_36 ) ;
}
int F_32 ( struct V_1 * V_2 )
{
if ( V_2 )
return V_2 -> V_48 ;
return - V_40 ;
}
T_2 F_33 ( T_2 V_49 )
{
int V_50 = 0 ;
struct V_1 * V_2 = NULL ;
unsigned long V_44 ;
if ( ! ( V_49 & ( 1 << 1 ) ) )
return V_49 ;
F_22 ( & V_45 , V_44 ) ;
F_23 (timer, &omap_timer_list, node) {
T_1 V_51 ;
V_51 = F_1 ( V_2 , V_28 ) ;
if ( V_51 & V_52 ) {
if ( ( ( F_34 ( V_53 ) >> ( V_50 * 2 ) ) & 0x03 ) == 0 )
V_49 &= ~ ( 1 << 1 ) ;
else
V_49 &= ~ ( 1 << 2 ) ;
}
V_50 ++ ;
}
F_24 ( & V_45 , V_44 ) ;
return V_49 ;
}
struct V_54 * F_35 ( struct V_1 * V_2 )
{
if ( V_2 )
return V_2 -> V_39 ;
return NULL ;
}
T_2 F_33 ( T_2 V_49 )
{
F_36 () ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 )
{
if ( F_28 ( ! V_2 || F_38 ( & V_2 -> V_32 -> V_36 ) ) ) {
F_39 ( L_6 , V_47 ) ;
return - V_40 ;
}
F_4 ( V_2 , V_55 , 0 ) ;
return 0 ;
}
int F_40 ( struct V_1 * V_2 )
{
T_1 V_51 ;
if ( F_28 ( ! V_2 ) )
return - V_40 ;
F_12 ( V_2 ) ;
if ( V_2 -> V_56 ) {
T_1 V_57 =
V_2 -> V_58 ( & V_2 -> V_32 -> V_36 ) ;
if ( V_57 != V_2 -> V_59 )
F_6 ( V_2 ) ;
}
V_51 = F_1 ( V_2 , V_28 ) ;
if ( ! ( V_51 & V_52 ) ) {
V_51 |= V_52 ;
F_4 ( V_2 , V_28 , V_51 ) ;
}
V_2 -> V_7 . V_29 = V_51 ;
return 0 ;
}
int F_41 ( struct V_1 * V_2 )
{
unsigned long V_60 = 0 ;
struct V_34 * V_35 = V_2 -> V_32 -> V_36 . V_37 ;
if ( F_28 ( ! V_2 ) )
return - V_40 ;
if ( ! V_35 -> V_41 )
V_60 = F_42 ( V_2 -> V_39 ) ;
F_43 ( V_2 , V_2 -> V_5 , V_60 ) ;
if ( V_2 -> V_56 && V_2 -> V_58 )
V_2 -> V_59 =
V_2 -> V_58 ( & V_2 -> V_32 -> V_36 ) ;
V_2 -> V_7 . V_29 =
F_1 ( V_2 , V_28 ) ;
V_2 -> V_7 . V_14 = F_9 ( V_2 -> V_15 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , int V_61 )
{
int V_38 ;
struct V_34 * V_35 ;
if ( F_28 ( ! V_2 ) )
return - V_40 ;
V_35 = V_2 -> V_32 -> V_36 . V_37 ;
if ( V_61 < 0 || V_61 >= 3 )
return - V_40 ;
V_38 = V_35 -> V_62 ( V_2 -> V_32 , V_61 ) ;
return V_38 ;
}
int F_44 ( struct V_1 * V_2 , int V_63 ,
unsigned int V_64 )
{
T_1 V_51 ;
if ( F_28 ( ! V_2 ) )
return - V_40 ;
F_12 ( V_2 ) ;
V_51 = F_1 ( V_2 , V_28 ) ;
if ( V_63 )
V_51 |= V_65 ;
else
V_51 &= ~ V_65 ;
F_4 ( V_2 , V_28 , V_51 ) ;
F_4 ( V_2 , V_20 , V_64 ) ;
F_4 ( V_2 , V_55 , 0 ) ;
V_2 -> V_7 . V_29 = V_51 ;
V_2 -> V_7 . V_21 = V_64 ;
F_14 ( V_2 ) ;
return 0 ;
}
int F_45 ( struct V_1 * V_2 , int V_63 ,
unsigned int V_64 )
{
T_1 V_51 ;
if ( F_28 ( ! V_2 ) )
return - V_40 ;
F_12 ( V_2 ) ;
if ( V_2 -> V_56 ) {
T_1 V_57 =
V_2 -> V_58 ( & V_2 -> V_32 -> V_36 ) ;
if ( V_57 != V_2 -> V_59 )
F_6 ( V_2 ) ;
}
V_51 = F_1 ( V_2 , V_28 ) ;
if ( V_63 ) {
V_51 |= V_65 ;
F_4 ( V_2 , V_20 , V_64 ) ;
} else {
V_51 &= ~ V_65 ;
}
V_51 |= V_52 ;
F_46 ( V_2 , V_51 , V_64 , V_2 -> V_5 ) ;
V_2 -> V_7 . V_29 = V_51 ;
V_2 -> V_7 . V_21 = V_64 ;
V_2 -> V_7 . V_19 = V_64 ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 , int V_66 ,
unsigned int V_67 )
{
T_1 V_51 ;
if ( F_28 ( ! V_2 ) )
return - V_40 ;
F_12 ( V_2 ) ;
V_51 = F_1 ( V_2 , V_28 ) ;
if ( V_66 )
V_51 |= V_68 ;
else
V_51 &= ~ V_68 ;
F_4 ( V_2 , V_28 , V_51 ) ;
F_4 ( V_2 , V_22 , V_67 ) ;
V_2 -> V_7 . V_29 = V_51 ;
V_2 -> V_7 . V_23 = V_67 ;
F_14 ( V_2 ) ;
return 0 ;
}
int F_48 ( struct V_1 * V_2 , int V_69 ,
int V_70 , int V_71 )
{
T_1 V_51 ;
if ( F_28 ( ! V_2 ) )
return - V_40 ;
F_12 ( V_2 ) ;
V_51 = F_1 ( V_2 , V_28 ) ;
V_51 &= ~ ( V_72 | V_73 |
V_74 | ( 0x03 << 10 ) ) ;
if ( V_69 )
V_51 |= V_73 ;
if ( V_70 )
V_51 |= V_74 ;
V_51 |= V_71 << 10 ;
F_4 ( V_2 , V_28 , V_51 ) ;
V_2 -> V_7 . V_29 = V_51 ;
F_14 ( V_2 ) ;
return 0 ;
}
int F_49 ( struct V_1 * V_2 , int V_75 )
{
T_1 V_51 ;
if ( F_28 ( ! V_2 ) )
return - V_40 ;
F_12 ( V_2 ) ;
V_51 = F_1 ( V_2 , V_28 ) ;
V_51 &= ~ ( V_76 | ( 0x07 << 2 ) ) ;
if ( V_75 >= 0x00 && V_75 <= 0x07 ) {
V_51 |= V_76 ;
V_51 |= V_75 << 2 ;
}
F_4 ( V_2 , V_28 , V_51 ) ;
V_2 -> V_7 . V_29 = V_51 ;
F_14 ( V_2 ) ;
return 0 ;
}
int F_50 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
if ( F_28 ( ! V_2 ) )
return - V_40 ;
F_12 ( V_2 ) ;
F_51 ( V_2 , V_6 ) ;
V_2 -> V_7 . V_26 = V_6 ;
V_2 -> V_7 . V_17 = V_6 ;
F_14 ( V_2 ) ;
return 0 ;
}
unsigned int F_52 ( struct V_1 * V_2 )
{
unsigned int V_51 ;
if ( F_28 ( ! V_2 || F_38 ( & V_2 -> V_32 -> V_36 ) ) ) {
F_39 ( L_6 , V_47 ) ;
return 0 ;
}
V_51 = F_9 ( V_2 -> V_15 ) ;
return V_51 ;
}
int F_53 ( struct V_1 * V_2 , unsigned int V_6 )
{
if ( F_28 ( ! V_2 || F_38 ( & V_2 -> V_32 -> V_36 ) ) )
return - V_40 ;
F_54 ( V_2 , V_6 ) ;
V_2 -> V_7 . V_14 = V_6 ;
return 0 ;
}
unsigned int F_55 ( struct V_1 * V_2 )
{
if ( F_28 ( ! V_2 || F_38 ( & V_2 -> V_32 -> V_36 ) ) ) {
F_39 ( L_7 , V_47 ) ;
return 0 ;
}
return F_56 ( V_2 , V_2 -> V_5 ) ;
}
int F_57 ( struct V_1 * V_2 , unsigned int V_6 )
{
if ( F_28 ( ! V_2 || F_38 ( & V_2 -> V_32 -> V_36 ) ) ) {
F_39 ( L_6 , V_47 ) ;
return - V_40 ;
}
F_4 ( V_2 , V_18 , V_6 ) ;
V_2 -> V_7 . V_19 = V_6 ;
return 0 ;
}
int F_58 ( void )
{
struct V_1 * V_2 ;
F_23 (timer, &omap_timer_list, node) {
if ( ! V_2 -> V_46 )
continue;
if ( F_1 ( V_2 , V_28 ) &
V_52 ) {
return 1 ;
}
}
return 0 ;
}
static int T_3 F_59 ( struct V_77 * V_32 )
{
int V_38 ;
unsigned long V_44 ;
struct V_1 * V_2 ;
struct V_78 * V_79 , * V_48 , * V_80 ;
struct V_34 * V_35 = V_32 -> V_36 . V_37 ;
if ( ! V_35 ) {
F_19 ( & V_32 -> V_36 , L_8 , V_47 ) ;
return - V_81 ;
}
V_48 = F_60 ( V_32 , V_82 , 0 ) ;
if ( F_28 ( ! V_48 ) ) {
F_19 ( & V_32 -> V_36 , L_9 , V_47 ) ;
return - V_81 ;
}
V_79 = F_60 ( V_32 , V_83 , 0 ) ;
if ( F_28 ( ! V_79 ) ) {
F_19 ( & V_32 -> V_36 , L_10 , V_47 ) ;
return - V_81 ;
}
V_80 = F_61 ( V_79 -> V_84 , F_62 ( V_79 ) ,
V_32 -> V_85 ) ;
if ( ! V_80 ) {
F_19 ( & V_32 -> V_36 , L_11 , V_47 ) ;
return - V_86 ;
}
V_2 = F_63 ( sizeof( struct V_1 ) , V_87 ) ;
if ( ! V_2 ) {
F_19 ( & V_32 -> V_36 , L_12 ,
V_47 ) ;
V_38 = - V_88 ;
goto V_89;
}
V_2 -> V_9 = F_64 ( V_79 -> V_84 , F_62 ( V_79 ) ) ;
if ( ! V_2 -> V_9 ) {
F_19 ( & V_32 -> V_36 , L_13 , V_47 ) ;
V_38 = - V_88 ;
goto V_90;
}
V_2 -> V_33 = V_32 -> V_33 ;
V_2 -> V_48 = V_48 -> V_84 ;
V_2 -> V_46 = V_35 -> V_46 ;
V_2 -> V_32 = V_32 ;
V_2 -> V_56 = V_35 -> V_56 ;
V_2 -> V_58 = V_35 -> V_58 ;
if ( ! V_35 -> V_41 ) {
F_65 ( & V_32 -> V_36 ) ;
F_66 ( & V_32 -> V_36 ) ;
}
if ( ! V_2 -> V_46 ) {
F_30 ( & V_32 -> V_36 ) ;
F_67 ( V_2 ) ;
F_31 ( & V_32 -> V_36 ) ;
}
F_22 ( & V_45 , V_44 ) ;
F_68 ( & V_2 -> V_91 , & V_92 ) ;
F_24 ( & V_45 , V_44 ) ;
F_69 ( & V_32 -> V_36 , L_14 ) ;
return 0 ;
V_90:
F_70 ( V_2 ) ;
V_89:
F_71 ( V_79 -> V_84 , F_62 ( V_79 ) ) ;
return V_38 ;
}
static int T_4 F_72 ( struct V_77 * V_32 )
{
struct V_1 * V_2 ;
unsigned long V_44 ;
int V_38 = - V_40 ;
F_22 ( & V_45 , V_44 ) ;
F_23 (timer, &omap_timer_list, node)
if ( V_2 -> V_32 -> V_33 == V_32 -> V_33 ) {
F_73 ( & V_2 -> V_91 ) ;
F_70 ( V_2 ) ;
V_38 = 0 ;
break;
}
F_24 ( & V_45 , V_44 ) ;
return V_38 ;
}
static int T_5 F_74 ( void )
{
return F_75 ( & V_93 ) ;
}
static void T_6 F_76 ( void )
{
F_77 ( & V_93 ) ;
}

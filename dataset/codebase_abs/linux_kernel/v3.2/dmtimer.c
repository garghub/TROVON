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
F_4 ( V_2 , V_7 ,
V_2 -> V_8 . V_9 ) ;
if ( V_2 -> V_10 > 1 )
F_7 ( V_2 -> V_8 . V_11 , V_2 -> V_12 ) ;
F_7 ( V_2 -> V_8 . V_13 , V_2 -> V_14 ) ;
F_4 ( V_2 , V_15 ,
V_2 -> V_8 . V_16 ) ;
F_4 ( V_2 , V_17 ,
V_2 -> V_8 . V_18 ) ;
F_4 ( V_2 , V_19 ,
V_2 -> V_8 . V_20 ) ;
F_4 ( V_2 , V_21 ,
V_2 -> V_8 . V_22 ) ;
F_4 ( V_2 , V_23 ,
V_2 -> V_8 . V_24 ) ;
F_7 ( V_2 -> V_8 . V_25 , V_2 -> V_26 ) ;
F_4 ( V_2 , V_27 ,
V_2 -> V_8 . V_28 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_29 ;
if ( ! V_2 -> V_12 )
return;
V_29 = 0 ;
while ( ! ( F_9 ( V_2 -> V_12 ) & 1 ) ) {
V_29 ++ ;
if ( V_29 > 100000 ) {
F_10 ( V_30 L_1 ) ;
return;
}
}
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
if ( V_2 -> V_31 -> V_32 != 1 ) {
F_4 ( V_2 , V_23 , 0x06 ) ;
F_8 ( V_2 ) ;
}
F_13 ( V_2 , 0 , 0 ) ;
F_14 ( V_2 ) ;
V_2 -> V_5 = 1 ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_31 -> V_35 . V_36 ;
int V_37 ;
V_2 -> V_38 = F_16 ( & V_2 -> V_31 -> V_35 , L_2 ) ;
if ( F_17 ( F_18 ( V_2 -> V_38 ) ) ) {
V_2 -> V_38 = NULL ;
F_19 ( & V_2 -> V_31 -> V_35 , L_3 ) ;
return - V_39 ;
}
if ( V_34 -> V_40 )
F_11 ( V_2 ) ;
V_37 = F_20 ( V_2 , V_41 ) ;
V_2 -> V_5 = 1 ;
return V_37 ;
}
struct V_1 * F_21 ( void )
{
struct V_1 * V_2 = NULL , * V_42 ;
unsigned long V_43 ;
int V_37 = 0 ;
F_22 ( & V_44 , V_43 ) ;
F_23 (t, &omap_timer_list, node) {
if ( V_42 -> V_45 )
continue;
V_2 = V_42 ;
V_2 -> V_45 = 1 ;
break;
}
if ( V_2 ) {
V_37 = F_15 ( V_2 ) ;
if ( V_37 ) {
V_2 -> V_45 = 0 ;
V_2 = NULL ;
}
}
F_24 ( & V_44 , V_43 ) ;
if ( ! V_2 )
F_25 ( L_4 , V_46 ) ;
return V_2 ;
}
struct V_1 * F_26 ( int V_32 )
{
struct V_1 * V_2 = NULL , * V_42 ;
unsigned long V_43 ;
int V_37 = 0 ;
F_22 ( & V_44 , V_43 ) ;
F_23 (t, &omap_timer_list, node) {
if ( V_42 -> V_31 -> V_32 == V_32 && ! V_42 -> V_45 ) {
V_2 = V_42 ;
V_2 -> V_45 = 1 ;
break;
}
}
if ( V_2 ) {
V_37 = F_15 ( V_2 ) ;
if ( V_37 ) {
V_2 -> V_45 = 0 ;
V_2 = NULL ;
}
}
F_24 ( & V_44 , V_43 ) ;
if ( ! V_2 )
F_25 ( L_5 , V_46 , V_32 ) ;
return V_2 ;
}
int F_27 ( struct V_1 * V_2 )
{
if ( F_28 ( ! V_2 ) )
return - V_39 ;
F_29 ( V_2 -> V_38 ) ;
F_2 ( ! V_2 -> V_45 ) ;
V_2 -> V_45 = 0 ;
return 0 ;
}
void F_12 ( struct V_1 * V_2 )
{
F_30 ( & V_2 -> V_31 -> V_35 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
F_31 ( & V_2 -> V_31 -> V_35 ) ;
}
int F_32 ( struct V_1 * V_2 )
{
if ( V_2 )
return V_2 -> V_47 ;
return - V_39 ;
}
T_2 F_33 ( T_2 V_48 )
{
int V_49 = 0 ;
struct V_1 * V_2 = NULL ;
unsigned long V_43 ;
if ( ! ( V_48 & ( 1 << 1 ) ) )
return V_48 ;
F_22 ( & V_44 , V_43 ) ;
F_23 (timer, &omap_timer_list, node) {
T_1 V_50 ;
V_50 = F_1 ( V_2 , V_27 ) ;
if ( V_50 & V_51 ) {
if ( ( ( F_34 ( V_52 ) >> ( V_49 * 2 ) ) & 0x03 ) == 0 )
V_48 &= ~ ( 1 << 1 ) ;
else
V_48 &= ~ ( 1 << 2 ) ;
}
V_49 ++ ;
}
F_24 ( & V_44 , V_43 ) ;
return V_48 ;
}
struct V_53 * F_35 ( struct V_1 * V_2 )
{
if ( V_2 )
return V_2 -> V_38 ;
return NULL ;
}
T_2 F_33 ( T_2 V_48 )
{
F_36 () ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 )
{
if ( F_28 ( ! V_2 || F_38 ( & V_2 -> V_31 -> V_35 ) ) ) {
F_39 ( L_6 , V_46 ) ;
return - V_39 ;
}
F_4 ( V_2 , V_54 , 0 ) ;
return 0 ;
}
int F_40 ( struct V_1 * V_2 )
{
T_1 V_50 ;
if ( F_28 ( ! V_2 ) )
return - V_39 ;
F_12 ( V_2 ) ;
if ( V_2 -> V_55 ) {
T_1 V_56 =
V_2 -> V_57 ( & V_2 -> V_31 -> V_35 ) ;
if ( V_56 != V_2 -> V_58 )
F_6 ( V_2 ) ;
}
V_50 = F_1 ( V_2 , V_27 ) ;
if ( ! ( V_50 & V_51 ) ) {
V_50 |= V_51 ;
F_4 ( V_2 , V_27 , V_50 ) ;
}
V_2 -> V_8 . V_28 = V_50 ;
return 0 ;
}
int F_41 ( struct V_1 * V_2 )
{
unsigned long V_59 = 0 ;
struct V_33 * V_34 = V_2 -> V_31 -> V_35 . V_36 ;
if ( F_28 ( ! V_2 ) )
return - V_39 ;
if ( ! V_34 -> V_40 )
V_59 = F_42 ( V_2 -> V_38 ) ;
F_43 ( V_2 , V_2 -> V_5 , V_59 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , int V_60 )
{
int V_37 ;
struct V_33 * V_34 ;
if ( F_28 ( ! V_2 ) )
return - V_39 ;
V_34 = V_2 -> V_31 -> V_35 . V_36 ;
if ( V_60 < 0 || V_60 >= 3 )
return - V_39 ;
V_37 = V_34 -> V_61 ( V_2 -> V_31 , V_60 ) ;
return V_37 ;
}
int F_44 ( struct V_1 * V_2 , int V_62 ,
unsigned int V_63 )
{
T_1 V_50 ;
if ( F_28 ( ! V_2 ) )
return - V_39 ;
F_12 ( V_2 ) ;
V_50 = F_1 ( V_2 , V_27 ) ;
if ( V_62 )
V_50 |= V_64 ;
else
V_50 &= ~ V_64 ;
F_4 ( V_2 , V_27 , V_50 ) ;
F_4 ( V_2 , V_19 , V_63 ) ;
F_4 ( V_2 , V_54 , 0 ) ;
V_2 -> V_8 . V_28 = V_50 ;
V_2 -> V_8 . V_20 = V_63 ;
F_14 ( V_2 ) ;
return 0 ;
}
int F_45 ( struct V_1 * V_2 , int V_62 ,
unsigned int V_63 )
{
T_1 V_50 ;
if ( F_28 ( ! V_2 ) )
return - V_39 ;
F_12 ( V_2 ) ;
if ( V_2 -> V_55 ) {
T_1 V_56 =
V_2 -> V_57 ( & V_2 -> V_31 -> V_35 ) ;
if ( V_56 != V_2 -> V_58 )
F_6 ( V_2 ) ;
}
V_50 = F_1 ( V_2 , V_27 ) ;
if ( V_62 ) {
V_50 |= V_64 ;
F_4 ( V_2 , V_19 , V_63 ) ;
} else {
V_50 &= ~ V_64 ;
}
V_50 |= V_51 ;
F_46 ( V_2 , V_50 , V_63 , V_2 -> V_5 ) ;
V_2 -> V_8 . V_28 = V_50 ;
V_2 -> V_8 . V_20 = V_63 ;
V_2 -> V_8 . V_18 = V_63 ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 , int V_65 ,
unsigned int V_66 )
{
T_1 V_50 ;
if ( F_28 ( ! V_2 ) )
return - V_39 ;
F_12 ( V_2 ) ;
V_50 = F_1 ( V_2 , V_27 ) ;
if ( V_65 )
V_50 |= V_67 ;
else
V_50 &= ~ V_67 ;
F_4 ( V_2 , V_27 , V_50 ) ;
F_4 ( V_2 , V_21 , V_66 ) ;
V_2 -> V_8 . V_28 = V_50 ;
V_2 -> V_8 . V_22 = V_66 ;
F_14 ( V_2 ) ;
return 0 ;
}
int F_48 ( struct V_1 * V_2 , int V_68 ,
int V_69 , int V_70 )
{
T_1 V_50 ;
if ( F_28 ( ! V_2 ) )
return - V_39 ;
F_12 ( V_2 ) ;
V_50 = F_1 ( V_2 , V_27 ) ;
V_50 &= ~ ( V_71 | V_72 |
V_73 | ( 0x03 << 10 ) ) ;
if ( V_68 )
V_50 |= V_72 ;
if ( V_69 )
V_50 |= V_73 ;
V_50 |= V_70 << 10 ;
F_4 ( V_2 , V_27 , V_50 ) ;
V_2 -> V_8 . V_28 = V_50 ;
F_14 ( V_2 ) ;
return 0 ;
}
int F_49 ( struct V_1 * V_2 , int V_74 )
{
T_1 V_50 ;
if ( F_28 ( ! V_2 ) )
return - V_39 ;
F_12 ( V_2 ) ;
V_50 = F_1 ( V_2 , V_27 ) ;
V_50 &= ~ ( V_75 | ( 0x07 << 2 ) ) ;
if ( V_74 >= 0x00 && V_74 <= 0x07 ) {
V_50 |= V_75 ;
V_50 |= V_74 << 2 ;
}
F_4 ( V_2 , V_27 , V_50 ) ;
V_2 -> V_8 . V_28 = V_50 ;
F_14 ( V_2 ) ;
return 0 ;
}
int F_50 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
if ( F_28 ( ! V_2 ) )
return - V_39 ;
F_12 ( V_2 ) ;
F_51 ( V_2 , V_6 ) ;
V_2 -> V_8 . V_25 = V_6 ;
V_2 -> V_8 . V_16 = V_6 ;
F_14 ( V_2 ) ;
return 0 ;
}
unsigned int F_52 ( struct V_1 * V_2 )
{
unsigned int V_50 ;
if ( F_28 ( ! V_2 || F_38 ( & V_2 -> V_31 -> V_35 ) ) ) {
F_39 ( L_6 , V_46 ) ;
return 0 ;
}
V_50 = F_9 ( V_2 -> V_14 ) ;
return V_50 ;
}
int F_53 ( struct V_1 * V_2 , unsigned int V_6 )
{
if ( F_28 ( ! V_2 || F_38 ( & V_2 -> V_31 -> V_35 ) ) )
return - V_39 ;
F_54 ( V_2 , V_6 ) ;
V_2 -> V_8 . V_13 = V_6 ;
return 0 ;
}
unsigned int F_55 ( struct V_1 * V_2 )
{
if ( F_28 ( ! V_2 || F_38 ( & V_2 -> V_31 -> V_35 ) ) ) {
F_39 ( L_7 , V_46 ) ;
return 0 ;
}
return F_56 ( V_2 , V_2 -> V_5 ) ;
}
int F_57 ( struct V_1 * V_2 , unsigned int V_6 )
{
if ( F_28 ( ! V_2 || F_38 ( & V_2 -> V_31 -> V_35 ) ) ) {
F_39 ( L_6 , V_46 ) ;
return - V_39 ;
}
F_4 ( V_2 , V_17 , V_6 ) ;
V_2 -> V_8 . V_18 = V_6 ;
return 0 ;
}
int F_58 ( void )
{
struct V_1 * V_2 ;
F_23 (timer, &omap_timer_list, node) {
if ( ! V_2 -> V_45 )
continue;
if ( F_1 ( V_2 , V_27 ) &
V_51 ) {
return 1 ;
}
}
return 0 ;
}
static int T_3 F_59 ( struct V_76 * V_31 )
{
int V_37 ;
unsigned long V_43 ;
struct V_1 * V_2 ;
struct V_77 * V_78 , * V_47 , * V_79 ;
struct V_33 * V_34 = V_31 -> V_35 . V_36 ;
if ( ! V_34 ) {
F_19 ( & V_31 -> V_35 , L_8 , V_46 ) ;
return - V_80 ;
}
V_47 = F_60 ( V_31 , V_81 , 0 ) ;
if ( F_28 ( ! V_47 ) ) {
F_19 ( & V_31 -> V_35 , L_9 , V_46 ) ;
return - V_80 ;
}
V_78 = F_60 ( V_31 , V_82 , 0 ) ;
if ( F_28 ( ! V_78 ) ) {
F_19 ( & V_31 -> V_35 , L_10 , V_46 ) ;
return - V_80 ;
}
V_79 = F_61 ( V_78 -> V_83 , F_62 ( V_78 ) ,
V_31 -> V_84 ) ;
if ( ! V_79 ) {
F_19 ( & V_31 -> V_35 , L_11 , V_46 ) ;
return - V_85 ;
}
V_2 = F_63 ( sizeof( struct V_1 ) , V_86 ) ;
if ( ! V_2 ) {
F_19 ( & V_31 -> V_35 , L_12 ,
V_46 ) ;
V_37 = - V_87 ;
goto V_88;
}
V_2 -> V_89 = F_64 ( V_78 -> V_83 , F_62 ( V_78 ) ) ;
if ( ! V_2 -> V_89 ) {
F_19 ( & V_31 -> V_35 , L_13 , V_46 ) ;
V_37 = - V_87 ;
goto V_90;
}
V_2 -> V_32 = V_31 -> V_32 ;
V_2 -> V_47 = V_47 -> V_83 ;
V_2 -> V_45 = V_34 -> V_45 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_55 = V_34 -> V_55 ;
V_2 -> V_57 = V_34 -> V_57 ;
if ( ! V_34 -> V_40 ) {
F_65 ( & V_31 -> V_35 ) ;
F_66 ( & V_31 -> V_35 ) ;
}
if ( ! V_2 -> V_45 ) {
F_30 ( & V_31 -> V_35 ) ;
F_67 ( V_2 ) ;
F_31 ( & V_31 -> V_35 ) ;
}
F_22 ( & V_44 , V_43 ) ;
F_68 ( & V_2 -> V_91 , & V_92 ) ;
F_24 ( & V_44 , V_43 ) ;
F_69 ( & V_31 -> V_35 , L_14 ) ;
return 0 ;
V_90:
F_70 ( V_2 ) ;
V_88:
F_71 ( V_78 -> V_83 , F_62 ( V_78 ) ) ;
return V_37 ;
}
static int T_4 F_72 ( struct V_76 * V_31 )
{
struct V_1 * V_2 ;
unsigned long V_43 ;
int V_37 = - V_39 ;
F_22 ( & V_44 , V_43 ) ;
F_23 (timer, &omap_timer_list, node)
if ( V_2 -> V_31 -> V_32 == V_31 -> V_32 ) {
F_73 ( & V_2 -> V_91 ) ;
F_70 ( V_2 ) ;
V_37 = 0 ;
break;
}
F_24 ( & V_44 , V_43 ) ;
return V_37 ;
}
static int T_5 F_74 ( void )
{
return F_75 ( & V_93 ) ;
}
static void T_6 F_76 ( void )
{
F_77 ( & V_93 ) ;
}

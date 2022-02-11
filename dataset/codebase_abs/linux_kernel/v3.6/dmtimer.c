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
int V_31 ;
if ( ! ( V_2 -> V_32 & V_33 ) ) {
V_2 -> V_34 = F_16 ( & V_2 -> V_29 -> V_35 , L_2 ) ;
if ( F_17 ( F_18 ( V_2 -> V_34 ) ) ) {
V_2 -> V_34 = NULL ;
F_19 ( & V_2 -> V_29 -> V_35 , L_3 ) ;
return - V_36 ;
}
}
if ( V_2 -> V_32 & V_33 )
F_11 ( V_2 ) ;
V_31 = F_20 ( V_2 , V_37 ) ;
V_2 -> V_5 = 1 ;
return V_31 ;
}
static inline T_1 F_21 ( int V_30 )
{
return ( V_38 & ( 1 << ( V_30 - 1 ) ) ) ? 1 : 0 ;
}
int F_22 ( int V_30 )
{
if ( F_21 ( V_30 ) )
return - V_39 ;
V_38 |= ( 1 << ( V_30 - 1 ) ) ;
return 0 ;
}
struct V_1 * F_23 ( void )
{
struct V_1 * V_2 = NULL , * V_40 ;
unsigned long V_41 ;
int V_31 = 0 ;
F_24 ( & V_42 , V_41 ) ;
F_25 (t, &omap_timer_list, node) {
if ( V_40 -> V_43 )
continue;
V_2 = V_40 ;
V_2 -> V_43 = 1 ;
break;
}
F_26 ( & V_42 , V_41 ) ;
if ( V_2 ) {
V_31 = F_15 ( V_2 ) ;
if ( V_31 ) {
V_2 -> V_43 = 0 ;
V_2 = NULL ;
}
}
if ( ! V_2 )
F_27 ( L_4 , V_44 ) ;
return V_2 ;
}
struct V_1 * F_28 ( int V_30 )
{
struct V_1 * V_2 = NULL , * V_40 ;
unsigned long V_41 ;
int V_31 = 0 ;
F_24 ( & V_42 , V_41 ) ;
F_25 (t, &omap_timer_list, node) {
if ( V_40 -> V_29 -> V_30 == V_30 && ! V_40 -> V_43 ) {
V_2 = V_40 ;
V_2 -> V_43 = 1 ;
break;
}
}
F_26 ( & V_42 , V_41 ) ;
if ( V_2 ) {
V_31 = F_15 ( V_2 ) ;
if ( V_31 ) {
V_2 -> V_43 = 0 ;
V_2 = NULL ;
}
}
if ( ! V_2 )
F_27 ( L_5 , V_44 , V_30 ) ;
return V_2 ;
}
int F_29 ( struct V_1 * V_2 )
{
if ( F_30 ( ! V_2 ) )
return - V_36 ;
F_31 ( V_2 -> V_34 ) ;
F_2 ( ! V_2 -> V_43 ) ;
V_2 -> V_43 = 0 ;
return 0 ;
}
void F_12 ( struct V_1 * V_2 )
{
F_32 ( & V_2 -> V_29 -> V_35 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_29 -> V_35 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
if ( V_2 )
return V_2 -> V_45 ;
return - V_36 ;
}
T_2 F_35 ( T_2 V_46 )
{
int V_47 = 0 ;
struct V_1 * V_2 = NULL ;
unsigned long V_41 ;
if ( ! ( V_46 & ( 1 << 1 ) ) )
return V_46 ;
F_24 ( & V_42 , V_41 ) ;
F_25 (timer, &omap_timer_list, node) {
T_1 V_48 ;
V_48 = F_1 ( V_2 , V_25 ) ;
if ( V_48 & V_49 ) {
if ( ( ( F_36 ( V_50 ) >> ( V_47 * 2 ) ) & 0x03 ) == 0 )
V_46 &= ~ ( 1 << 1 ) ;
else
V_46 &= ~ ( 1 << 2 ) ;
}
V_47 ++ ;
}
F_26 ( & V_42 , V_41 ) ;
return V_46 ;
}
struct V_51 * F_37 ( struct V_1 * V_2 )
{
if ( V_2 )
return V_2 -> V_34 ;
return NULL ;
}
T_2 F_35 ( T_2 V_46 )
{
F_38 () ;
return 0 ;
}
int F_39 ( struct V_1 * V_2 )
{
if ( F_30 ( ! V_2 || F_40 ( & V_2 -> V_29 -> V_35 ) ) ) {
F_41 ( L_6 , V_44 ) ;
return - V_36 ;
}
F_4 ( V_2 , V_52 , 0 ) ;
return 0 ;
}
int F_42 ( struct V_1 * V_2 )
{
T_1 V_48 ;
if ( F_30 ( ! V_2 ) )
return - V_36 ;
F_12 ( V_2 ) ;
if ( ! ( V_2 -> V_32 & V_53 ) ) {
if ( F_43 ( & V_2 -> V_29 -> V_35 ) !=
V_2 -> V_54 )
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
int F_44 ( struct V_1 * V_2 )
{
unsigned long V_55 = 0 ;
if ( F_30 ( ! V_2 ) )
return - V_36 ;
if ( ! ( V_2 -> V_32 & V_33 ) )
V_55 = F_45 ( V_2 -> V_34 ) ;
F_46 ( V_2 , V_2 -> V_5 , V_55 ) ;
if ( ! ( V_2 -> V_32 & V_53 ) )
V_2 -> V_54 =
F_43 ( & V_2 -> V_29 -> V_35 ) ;
V_2 -> V_8 . V_26 =
F_1 ( V_2 , V_25 ) ;
V_2 -> V_8 . V_11 = F_9 ( V_2 -> V_12 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , int V_56 )
{
int V_31 ;
char * V_57 = NULL ;
struct V_51 * V_34 , * V_58 ;
struct V_59 * V_60 ;
if ( F_30 ( ! V_2 ) )
return - V_36 ;
V_60 = V_2 -> V_29 -> V_35 . V_61 ;
if ( V_56 < 0 || V_56 >= 3 )
return - V_36 ;
if ( V_60 -> V_62 )
return V_60 -> V_62 ( V_2 -> V_29 , V_56 ) ;
V_34 = F_16 ( & V_2 -> V_29 -> V_35 , L_2 ) ;
if ( F_18 ( V_34 ) ) {
F_41 ( L_7 , V_44 ) ;
return - V_36 ;
}
switch ( V_56 ) {
case V_63 :
V_57 = L_8 ;
break;
case V_37 :
V_57 = L_9 ;
break;
case V_64 :
V_57 = L_10 ;
break;
}
V_58 = F_16 ( & V_2 -> V_29 -> V_35 , V_57 ) ;
if ( F_18 ( V_58 ) ) {
F_41 ( L_11 , V_44 , V_57 ) ;
V_31 = - V_36 ;
goto V_65;
}
V_31 = F_47 ( V_34 , V_58 ) ;
if ( F_48 ( V_31 ) )
F_41 ( L_12 , V_44 ,
V_57 ) ;
F_31 ( V_58 ) ;
V_65:
F_31 ( V_34 ) ;
return V_31 ;
}
int F_49 ( struct V_1 * V_2 , int V_66 ,
unsigned int V_67 )
{
T_1 V_48 ;
if ( F_30 ( ! V_2 ) )
return - V_36 ;
F_12 ( V_2 ) ;
V_48 = F_1 ( V_2 , V_25 ) ;
if ( V_66 )
V_48 |= V_68 ;
else
V_48 &= ~ V_68 ;
F_4 ( V_2 , V_25 , V_48 ) ;
F_4 ( V_2 , V_17 , V_67 ) ;
F_4 ( V_2 , V_52 , 0 ) ;
V_2 -> V_8 . V_26 = V_48 ;
V_2 -> V_8 . V_18 = V_67 ;
F_14 ( V_2 ) ;
return 0 ;
}
int F_50 ( struct V_1 * V_2 , int V_66 ,
unsigned int V_67 )
{
T_1 V_48 ;
if ( F_30 ( ! V_2 ) )
return - V_36 ;
F_12 ( V_2 ) ;
if ( ! ( V_2 -> V_32 & V_53 ) ) {
if ( F_43 ( & V_2 -> V_29 -> V_35 ) !=
V_2 -> V_54 )
F_6 ( V_2 ) ;
}
V_48 = F_1 ( V_2 , V_25 ) ;
if ( V_66 ) {
V_48 |= V_68 ;
F_4 ( V_2 , V_17 , V_67 ) ;
} else {
V_48 &= ~ V_68 ;
}
V_48 |= V_49 ;
F_51 ( V_2 , V_48 , V_67 , V_2 -> V_5 ) ;
V_2 -> V_8 . V_26 = V_48 ;
V_2 -> V_8 . V_18 = V_67 ;
V_2 -> V_8 . V_16 = V_67 ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 , int V_69 ,
unsigned int V_70 )
{
T_1 V_48 ;
if ( F_30 ( ! V_2 ) )
return - V_36 ;
F_12 ( V_2 ) ;
V_48 = F_1 ( V_2 , V_25 ) ;
if ( V_69 )
V_48 |= V_71 ;
else
V_48 &= ~ V_71 ;
F_4 ( V_2 , V_25 , V_48 ) ;
F_4 ( V_2 , V_19 , V_70 ) ;
V_2 -> V_8 . V_26 = V_48 ;
V_2 -> V_8 . V_20 = V_70 ;
F_14 ( V_2 ) ;
return 0 ;
}
int F_53 ( struct V_1 * V_2 , int V_72 ,
int V_73 , int V_74 )
{
T_1 V_48 ;
if ( F_30 ( ! V_2 ) )
return - V_36 ;
F_12 ( V_2 ) ;
V_48 = F_1 ( V_2 , V_25 ) ;
V_48 &= ~ ( V_75 | V_76 |
V_77 | ( 0x03 << 10 ) ) ;
if ( V_72 )
V_48 |= V_76 ;
if ( V_73 )
V_48 |= V_77 ;
V_48 |= V_74 << 10 ;
F_4 ( V_2 , V_25 , V_48 ) ;
V_2 -> V_8 . V_26 = V_48 ;
F_14 ( V_2 ) ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 , int V_78 )
{
T_1 V_48 ;
if ( F_30 ( ! V_2 ) )
return - V_36 ;
F_12 ( V_2 ) ;
V_48 = F_1 ( V_2 , V_25 ) ;
V_48 &= ~ ( V_79 | ( 0x07 << 2 ) ) ;
if ( V_78 >= 0x00 && V_78 <= 0x07 ) {
V_48 |= V_79 ;
V_48 |= V_78 << 2 ;
}
F_4 ( V_2 , V_25 , V_48 ) ;
V_2 -> V_8 . V_26 = V_48 ;
F_14 ( V_2 ) ;
return 0 ;
}
int F_55 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
if ( F_30 ( ! V_2 ) )
return - V_36 ;
F_12 ( V_2 ) ;
F_56 ( V_2 , V_6 ) ;
V_2 -> V_8 . V_23 = V_6 ;
V_2 -> V_8 . V_14 = V_6 ;
F_14 ( V_2 ) ;
return 0 ;
}
unsigned int F_57 ( struct V_1 * V_2 )
{
unsigned int V_48 ;
if ( F_30 ( ! V_2 || F_40 ( & V_2 -> V_29 -> V_35 ) ) ) {
F_41 ( L_6 , V_44 ) ;
return 0 ;
}
V_48 = F_9 ( V_2 -> V_12 ) ;
return V_48 ;
}
int F_58 ( struct V_1 * V_2 , unsigned int V_6 )
{
if ( F_30 ( ! V_2 || F_40 ( & V_2 -> V_29 -> V_35 ) ) )
return - V_36 ;
F_59 ( V_2 , V_6 ) ;
V_2 -> V_8 . V_11 = V_6 ;
return 0 ;
}
unsigned int F_60 ( struct V_1 * V_2 )
{
if ( F_30 ( ! V_2 || F_40 ( & V_2 -> V_29 -> V_35 ) ) ) {
F_41 ( L_13 , V_44 ) ;
return 0 ;
}
return F_61 ( V_2 , V_2 -> V_5 ) ;
}
int F_62 ( struct V_1 * V_2 , unsigned int V_6 )
{
if ( F_30 ( ! V_2 || F_40 ( & V_2 -> V_29 -> V_35 ) ) ) {
F_41 ( L_6 , V_44 ) ;
return - V_36 ;
}
F_4 ( V_2 , V_15 , V_6 ) ;
V_2 -> V_8 . V_16 = V_6 ;
return 0 ;
}
int F_63 ( void )
{
struct V_1 * V_2 ;
F_25 (timer, &omap_timer_list, node) {
if ( ! V_2 -> V_43 )
continue;
if ( F_1 ( V_2 , V_25 ) &
V_49 ) {
return 1 ;
}
}
return 0 ;
}
static int T_3 F_64 ( struct V_80 * V_29 )
{
unsigned long V_41 ;
struct V_1 * V_2 ;
struct V_81 * V_82 , * V_45 ;
struct V_83 * V_35 = & V_29 -> V_35 ;
struct V_59 * V_60 = V_29 -> V_35 . V_61 ;
if ( ! V_60 ) {
F_19 ( V_35 , L_14 , V_44 ) ;
return - V_39 ;
}
V_45 = F_65 ( V_29 , V_84 , 0 ) ;
if ( F_30 ( ! V_45 ) ) {
F_19 ( V_35 , L_15 , V_44 ) ;
return - V_39 ;
}
V_82 = F_65 ( V_29 , V_85 , 0 ) ;
if ( F_30 ( ! V_82 ) ) {
F_19 ( V_35 , L_16 , V_44 ) ;
return - V_39 ;
}
V_2 = F_66 ( V_35 , sizeof( struct V_1 ) , V_86 ) ;
if ( ! V_2 ) {
F_19 ( V_35 , L_17 , V_44 ) ;
return - V_87 ;
}
V_2 -> V_88 = F_67 ( V_35 , V_82 ) ;
if ( ! V_2 -> V_88 ) {
F_19 ( V_35 , L_18 , V_44 ) ;
return - V_87 ;
}
V_2 -> V_30 = V_29 -> V_30 ;
V_2 -> V_45 = V_45 -> V_89 ;
V_2 -> V_43 = F_21 ( V_2 -> V_30 ) ;
V_2 -> V_29 = V_29 ;
V_2 -> V_32 = V_60 -> V_90 ;
if ( ! ( V_2 -> V_32 & V_33 ) ) {
F_68 ( V_35 ) ;
F_69 ( V_35 ) ;
}
if ( ! V_2 -> V_43 ) {
F_32 ( V_35 ) ;
F_70 ( V_2 ) ;
F_71 ( V_35 ) ;
}
F_24 ( & V_42 , V_41 ) ;
F_72 ( & V_2 -> V_91 , & V_92 ) ;
F_26 ( & V_42 , V_41 ) ;
F_73 ( V_35 , L_19 ) ;
return 0 ;
}
static int T_4 F_74 ( struct V_80 * V_29 )
{
struct V_1 * V_2 ;
unsigned long V_41 ;
int V_31 = - V_36 ;
F_24 ( & V_42 , V_41 ) ;
F_25 (timer, &omap_timer_list, node)
if ( V_2 -> V_29 -> V_30 == V_29 -> V_30 ) {
F_75 ( & V_2 -> V_91 ) ;
V_31 = 0 ;
break;
}
F_26 ( & V_42 , V_41 ) ;
return V_31 ;
}
static int T_5 F_76 ( void )
{
return F_77 ( & V_93 ) ;
}
static void T_6 F_78 ( void )
{
F_79 ( & V_93 ) ;
}

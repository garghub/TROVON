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
F_4 ( V_2 , V_10 ,
V_2 -> V_8 . V_11 ) ;
F_4 ( V_2 , V_12 ,
V_2 -> V_8 . V_13 ) ;
F_4 ( V_2 , V_14 ,
V_2 -> V_8 . V_15 ) ;
F_4 ( V_2 , V_16 ,
V_2 -> V_8 . V_17 ) ;
F_7 ( V_2 -> V_8 . V_18 , V_2 -> V_19 ) ;
F_4 ( V_2 , V_20 ,
V_2 -> V_8 . V_21 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
T_1 V_22 , V_23 = 100000 ;
if ( V_2 -> V_24 != 1 )
return - V_25 ;
F_4 ( V_2 , V_16 , 0x06 ) ;
do {
V_22 = F_3 ( V_2 ,
V_26 , 0 ) ;
} while ( ! V_22 && V_23 -- );
if ( ! V_23 ) {
F_9 ( & V_2 -> V_27 -> V_28 , L_1 ) ;
return - V_29 ;
}
V_22 = F_3 ( V_2 , V_30 , 0 ) ;
V_22 |= 0x2 << 0x3 ;
F_5 ( V_2 , V_30 , V_22 , 0 ) ;
V_2 -> V_5 = 0 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_31 ;
if ( ! ( V_2 -> V_32 & V_33 ) ) {
V_2 -> V_34 = F_11 ( & V_2 -> V_27 -> V_28 , L_2 ) ;
if ( F_12 ( F_13 ( V_2 -> V_34 ) ) ) {
V_2 -> V_34 = NULL ;
F_9 ( & V_2 -> V_27 -> V_28 , L_3 ) ;
return - V_25 ;
}
}
F_14 ( V_2 ) ;
if ( V_2 -> V_32 & V_33 ) {
V_31 = F_8 ( V_2 ) ;
if ( V_31 ) {
F_15 ( V_2 ) ;
return V_31 ;
}
}
F_16 ( V_2 ) ;
F_15 ( V_2 ) ;
return F_17 ( V_2 , V_35 ) ;
}
static inline T_1 F_18 ( int V_36 )
{
return ( V_37 & ( 1 << ( V_36 - 1 ) ) ) ? 1 : 0 ;
}
int F_19 ( int V_36 )
{
if ( F_18 ( V_36 ) )
return - V_38 ;
V_37 |= ( 1 << ( V_36 - 1 ) ) ;
return 0 ;
}
struct V_1 * F_20 ( void )
{
struct V_1 * V_2 = NULL , * V_39 ;
unsigned long V_40 ;
int V_41 = 0 ;
F_21 ( & V_42 , V_40 ) ;
F_22 (t, &omap_timer_list, node) {
if ( V_39 -> V_43 )
continue;
V_2 = V_39 ;
V_2 -> V_43 = 1 ;
break;
}
F_23 ( & V_42 , V_40 ) ;
if ( V_2 ) {
V_41 = F_10 ( V_2 ) ;
if ( V_41 ) {
V_2 -> V_43 = 0 ;
V_2 = NULL ;
}
}
if ( ! V_2 )
F_24 ( L_4 , V_44 ) ;
return V_2 ;
}
struct V_1 * F_25 ( int V_36 )
{
struct V_1 * V_2 = NULL , * V_39 ;
unsigned long V_40 ;
int V_41 = 0 ;
if ( F_26 () ) {
F_27 ( L_5 ,
V_44 ) ;
return NULL ;
}
F_21 ( & V_42 , V_40 ) ;
F_22 (t, &omap_timer_list, node) {
if ( V_39 -> V_27 -> V_36 == V_36 && ! V_39 -> V_43 ) {
V_2 = V_39 ;
V_2 -> V_43 = 1 ;
break;
}
}
F_23 ( & V_42 , V_40 ) ;
if ( V_2 ) {
V_41 = F_10 ( V_2 ) ;
if ( V_41 ) {
V_2 -> V_43 = 0 ;
V_2 = NULL ;
}
}
if ( ! V_2 )
F_24 ( L_6 , V_44 , V_36 ) ;
return V_2 ;
}
struct V_1 * F_28 ( T_1 V_45 )
{
struct V_1 * V_2 = NULL , * V_39 ;
unsigned long V_40 ;
if ( ! V_45 )
return NULL ;
F_21 ( & V_42 , V_40 ) ;
F_22 (t, &omap_timer_list, node) {
if ( ( ! V_39 -> V_43 ) && ( ( V_39 -> V_32 & V_45 ) == V_45 ) ) {
if ( V_2 )
V_2 -> V_43 = 0 ;
V_2 = V_39 ;
V_2 -> V_43 = 1 ;
if ( V_39 -> V_32 == V_45 )
break;
}
}
F_23 ( & V_42 , V_40 ) ;
if ( V_2 && F_10 ( V_2 ) ) {
V_2 -> V_43 = 0 ;
V_2 = NULL ;
}
if ( ! V_2 )
F_24 ( L_4 , V_44 ) ;
return V_2 ;
}
int F_29 ( struct V_1 * V_2 )
{
if ( F_30 ( ! V_2 ) )
return - V_25 ;
F_31 ( V_2 -> V_34 ) ;
F_2 ( ! V_2 -> V_43 ) ;
V_2 -> V_43 = 0 ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
F_32 ( & V_2 -> V_27 -> V_28 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_27 -> V_28 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
if ( V_2 )
return V_2 -> V_46 ;
return - V_25 ;
}
T_2 F_35 ( T_2 V_47 )
{
int V_48 = 0 ;
struct V_1 * V_2 = NULL ;
unsigned long V_40 ;
if ( ! ( V_47 & ( 1 << 1 ) ) )
return V_47 ;
F_21 ( & V_42 , V_40 ) ;
F_22 (timer, &omap_timer_list, node) {
T_1 V_22 ;
V_22 = F_1 ( V_2 , V_20 ) ;
if ( V_22 & V_49 ) {
if ( ( ( F_36 ( V_50 ) >> ( V_48 * 2 ) ) & 0x03 ) == 0 )
V_47 &= ~ ( 1 << 1 ) ;
else
V_47 &= ~ ( 1 << 2 ) ;
}
V_48 ++ ;
}
F_23 ( & V_42 , V_40 ) ;
return V_47 ;
}
struct V_51 * F_37 ( struct V_1 * V_2 )
{
if ( V_2 )
return V_2 -> V_34 ;
return NULL ;
}
T_2 F_35 ( T_2 V_47 )
{
F_38 () ;
return 0 ;
}
int F_39 ( struct V_1 * V_2 )
{
if ( F_30 ( ! V_2 || F_40 ( & V_2 -> V_27 -> V_28 ) ) ) {
F_41 ( L_7 , V_44 ) ;
return - V_25 ;
}
F_4 ( V_2 , V_52 , 0 ) ;
return 0 ;
}
int F_42 ( struct V_1 * V_2 )
{
T_1 V_22 ;
if ( F_30 ( ! V_2 ) )
return - V_25 ;
F_14 ( V_2 ) ;
if ( ! ( V_2 -> V_32 & V_53 ) ) {
if ( V_2 -> V_54 &&
V_2 -> V_54 ( & V_2 -> V_27 -> V_28 ) !=
V_2 -> V_55 )
F_6 ( V_2 ) ;
}
V_22 = F_1 ( V_2 , V_20 ) ;
if ( ! ( V_22 & V_49 ) ) {
V_22 |= V_49 ;
F_4 ( V_2 , V_20 , V_22 ) ;
}
V_2 -> V_8 . V_21 = V_22 ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 )
{
unsigned long V_56 = 0 ;
if ( F_30 ( ! V_2 ) )
return - V_25 ;
if ( ! ( V_2 -> V_32 & V_33 ) )
V_56 = F_44 ( V_2 -> V_34 ) ;
F_45 ( V_2 , V_2 -> V_5 , V_56 ) ;
if ( ! ( V_2 -> V_32 & V_53 ) ) {
if ( V_2 -> V_54 )
V_2 -> V_55 =
V_2 -> V_54 ( & V_2 -> V_27 -> V_28 ) ;
}
V_2 -> V_8 . V_21 =
F_1 ( V_2 , V_20 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , int V_57 )
{
int V_41 ;
char * V_58 = NULL ;
struct V_51 * V_59 ;
struct V_60 * V_61 ;
if ( F_30 ( ! V_2 ) )
return - V_25 ;
V_61 = V_2 -> V_27 -> V_28 . V_62 ;
if ( V_57 < 0 || V_57 >= 3 )
return - V_25 ;
if ( V_61 && V_61 -> V_63 )
return V_61 -> V_63 ( V_2 -> V_27 , V_57 ) ;
if ( ! V_2 -> V_34 )
return - V_25 ;
switch ( V_57 ) {
case V_64 :
V_58 = L_8 ;
break;
case V_35 :
V_58 = L_9 ;
break;
case V_65 :
V_58 = L_10 ;
break;
}
V_59 = F_11 ( & V_2 -> V_27 -> V_28 , V_58 ) ;
if ( F_13 ( V_59 ) ) {
F_41 ( L_11 , V_44 , V_58 ) ;
return - V_25 ;
}
V_41 = F_46 ( V_2 -> V_34 , V_59 ) ;
if ( F_47 ( V_41 ) )
F_41 ( L_12 , V_44 ,
V_58 ) ;
F_31 ( V_59 ) ;
return V_41 ;
}
int F_48 ( struct V_1 * V_2 , int V_66 ,
unsigned int V_67 )
{
T_1 V_22 ;
if ( F_30 ( ! V_2 ) )
return - V_25 ;
F_14 ( V_2 ) ;
V_22 = F_1 ( V_2 , V_20 ) ;
if ( V_66 )
V_22 |= V_68 ;
else
V_22 &= ~ V_68 ;
F_4 ( V_2 , V_20 , V_22 ) ;
F_4 ( V_2 , V_12 , V_67 ) ;
F_4 ( V_2 , V_52 , 0 ) ;
V_2 -> V_8 . V_21 = V_22 ;
V_2 -> V_8 . V_13 = V_67 ;
F_15 ( V_2 ) ;
return 0 ;
}
int F_49 ( struct V_1 * V_2 , int V_66 ,
unsigned int V_67 )
{
T_1 V_22 ;
if ( F_30 ( ! V_2 ) )
return - V_25 ;
F_14 ( V_2 ) ;
if ( ! ( V_2 -> V_32 & V_53 ) ) {
if ( V_2 -> V_54 &&
V_2 -> V_54 ( & V_2 -> V_27 -> V_28 ) !=
V_2 -> V_55 )
F_6 ( V_2 ) ;
}
V_22 = F_1 ( V_2 , V_20 ) ;
if ( V_66 ) {
V_22 |= V_68 ;
F_4 ( V_2 , V_12 , V_67 ) ;
} else {
V_22 &= ~ V_68 ;
}
V_22 |= V_49 ;
F_50 ( V_2 , V_22 , V_67 , V_2 -> V_5 ) ;
V_2 -> V_8 . V_21 = V_22 ;
V_2 -> V_8 . V_13 = V_67 ;
V_2 -> V_8 . V_11 = V_67 ;
return 0 ;
}
int F_51 ( struct V_1 * V_2 , int V_69 ,
unsigned int V_70 )
{
T_1 V_22 ;
if ( F_30 ( ! V_2 ) )
return - V_25 ;
F_14 ( V_2 ) ;
V_22 = F_1 ( V_2 , V_20 ) ;
if ( V_69 )
V_22 |= V_71 ;
else
V_22 &= ~ V_71 ;
F_4 ( V_2 , V_14 , V_70 ) ;
F_4 ( V_2 , V_20 , V_22 ) ;
V_2 -> V_8 . V_21 = V_22 ;
V_2 -> V_8 . V_15 = V_70 ;
F_15 ( V_2 ) ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 , int V_72 ,
int V_73 , int V_74 )
{
T_1 V_22 ;
if ( F_30 ( ! V_2 ) )
return - V_25 ;
F_14 ( V_2 ) ;
V_22 = F_1 ( V_2 , V_20 ) ;
V_22 &= ~ ( V_75 | V_76 |
V_77 | ( 0x03 << 10 ) ) ;
if ( V_72 )
V_22 |= V_76 ;
if ( V_73 )
V_22 |= V_77 ;
V_22 |= V_74 << 10 ;
F_4 ( V_2 , V_20 , V_22 ) ;
V_2 -> V_8 . V_21 = V_22 ;
F_15 ( V_2 ) ;
return 0 ;
}
int F_53 ( struct V_1 * V_2 , int V_78 )
{
T_1 V_22 ;
if ( F_30 ( ! V_2 ) )
return - V_25 ;
F_14 ( V_2 ) ;
V_22 = F_1 ( V_2 , V_20 ) ;
V_22 &= ~ ( V_79 | ( 0x07 << 2 ) ) ;
if ( V_78 >= 0x00 && V_78 <= 0x07 ) {
V_22 |= V_79 ;
V_22 |= V_78 << 2 ;
}
F_4 ( V_2 , V_20 , V_22 ) ;
V_2 -> V_8 . V_21 = V_22 ;
F_15 ( V_2 ) ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
if ( F_30 ( ! V_2 ) )
return - V_25 ;
F_14 ( V_2 ) ;
F_55 ( V_2 , V_6 ) ;
V_2 -> V_8 . V_18 = V_6 ;
V_2 -> V_8 . V_9 = V_6 ;
F_15 ( V_2 ) ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 , T_1 V_80 )
{
T_1 V_22 = V_80 ;
if ( F_30 ( ! V_2 ) )
return - V_25 ;
F_14 ( V_2 ) ;
if ( V_2 -> V_24 == 1 )
V_22 = F_57 ( V_2 -> V_19 ) & ~ V_80 ;
F_7 ( V_22 , V_2 -> V_81 ) ;
V_22 = F_1 ( V_2 , V_7 ) & ~ V_80 ;
F_4 ( V_2 , V_7 , V_22 ) ;
V_2 -> V_8 . V_18 &= ~ V_80 ;
V_2 -> V_8 . V_9 &= ~ V_80 ;
F_15 ( V_2 ) ;
return 0 ;
}
unsigned int F_58 ( struct V_1 * V_2 )
{
unsigned int V_22 ;
if ( F_30 ( ! V_2 || F_40 ( & V_2 -> V_27 -> V_28 ) ) ) {
F_41 ( L_7 , V_44 ) ;
return 0 ;
}
V_22 = F_57 ( V_2 -> V_82 ) ;
return V_22 ;
}
int F_59 ( struct V_1 * V_2 , unsigned int V_6 )
{
if ( F_30 ( ! V_2 || F_40 ( & V_2 -> V_27 -> V_28 ) ) )
return - V_25 ;
F_60 ( V_2 , V_6 ) ;
return 0 ;
}
unsigned int F_61 ( struct V_1 * V_2 )
{
if ( F_30 ( ! V_2 || F_40 ( & V_2 -> V_27 -> V_28 ) ) ) {
F_41 ( L_13 , V_44 ) ;
return 0 ;
}
return F_62 ( V_2 , V_2 -> V_5 ) ;
}
int F_63 ( struct V_1 * V_2 , unsigned int V_6 )
{
if ( F_30 ( ! V_2 || F_40 ( & V_2 -> V_27 -> V_28 ) ) ) {
F_41 ( L_7 , V_44 ) ;
return - V_25 ;
}
F_4 ( V_2 , V_10 , V_6 ) ;
V_2 -> V_8 . V_11 = V_6 ;
return 0 ;
}
int F_64 ( void )
{
struct V_1 * V_2 ;
F_22 (timer, &omap_timer_list, node) {
if ( ! V_2 -> V_43 )
continue;
if ( F_1 ( V_2 , V_20 ) &
V_49 ) {
return 1 ;
}
}
return 0 ;
}
static int F_65 ( struct V_83 * V_27 )
{
unsigned long V_40 ;
struct V_1 * V_2 ;
struct V_84 * V_85 , * V_46 ;
struct V_86 * V_28 = & V_27 -> V_28 ;
struct V_60 * V_61 = V_27 -> V_28 . V_62 ;
if ( ! V_61 && ! V_28 -> V_87 ) {
F_9 ( V_28 , L_14 , V_44 ) ;
return - V_38 ;
}
V_46 = F_66 ( V_27 , V_88 , 0 ) ;
if ( F_30 ( ! V_46 ) ) {
F_9 ( V_28 , L_15 , V_44 ) ;
return - V_38 ;
}
V_85 = F_66 ( V_27 , V_89 , 0 ) ;
if ( F_30 ( ! V_85 ) ) {
F_9 ( V_28 , L_16 , V_44 ) ;
return - V_38 ;
}
V_2 = F_67 ( V_28 , sizeof( struct V_1 ) , V_90 ) ;
if ( ! V_2 ) {
F_9 ( V_28 , L_17 , V_44 ) ;
return - V_91 ;
}
V_2 -> V_92 = F_68 ( V_28 , V_85 ) ;
if ( F_69 ( V_2 -> V_92 ) )
return F_70 ( V_2 -> V_92 ) ;
if ( V_28 -> V_87 ) {
if ( F_71 ( V_28 -> V_87 , L_18 , NULL ) )
V_2 -> V_32 |= V_53 ;
if ( F_71 ( V_28 -> V_87 , L_19 , NULL ) )
V_2 -> V_32 |= V_93 ;
if ( F_71 ( V_28 -> V_87 , L_20 , NULL ) )
V_2 -> V_32 |= V_94 ;
if ( F_71 ( V_28 -> V_87 , L_21 , NULL ) )
V_2 -> V_32 |= V_95 ;
} else {
V_2 -> V_36 = V_27 -> V_36 ;
V_2 -> V_96 = V_61 -> V_97 ;
V_2 -> V_32 = V_61 -> V_98 ;
V_2 -> V_43 = F_18 ( V_2 -> V_36 ) ;
V_2 -> V_54 = V_61 -> V_54 ;
}
V_2 -> V_46 = V_46 -> V_99 ;
V_2 -> V_27 = V_27 ;
if ( ! ( V_2 -> V_32 & V_33 ) ) {
F_72 ( V_28 ) ;
F_73 ( V_28 ) ;
}
if ( ! V_2 -> V_43 ) {
F_32 ( V_28 ) ;
F_74 ( V_2 ) ;
F_75 ( V_28 ) ;
}
F_21 ( & V_42 , V_40 ) ;
F_76 ( & V_2 -> V_100 , & V_101 ) ;
F_23 ( & V_42 , V_40 ) ;
F_77 ( V_28 , L_22 ) ;
return 0 ;
}
static int F_78 ( struct V_83 * V_27 )
{
struct V_1 * V_2 ;
unsigned long V_40 ;
int V_41 = - V_25 ;
F_21 ( & V_42 , V_40 ) ;
F_22 (timer, &omap_timer_list, node)
if ( ! strcmp ( F_79 ( & V_2 -> V_27 -> V_28 ) ,
F_79 ( & V_27 -> V_28 ) ) ) {
F_80 ( & V_2 -> V_100 ) ;
V_41 = 0 ;
break;
}
F_23 ( & V_42 , V_40 ) ;
return V_41 ;
}

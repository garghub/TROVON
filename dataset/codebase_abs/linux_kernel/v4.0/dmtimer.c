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
static struct V_1 * F_20 ( int V_39 , void * V_40 )
{
struct V_1 * V_2 = NULL , * V_41 ;
struct V_42 * V_43 = NULL ;
unsigned long V_44 ;
T_1 V_45 = 0 ;
int V_36 = 0 ;
switch ( V_39 ) {
case V_46 :
V_36 = * ( int * ) V_40 ;
break;
case V_47 :
V_45 = * ( T_1 * ) V_40 ;
break;
case V_48 :
V_43 = (struct V_42 * ) V_40 ;
break;
default:
break;
}
F_21 ( & V_49 , V_44 ) ;
F_22 (t, &omap_timer_list, node) {
if ( V_41 -> V_50 )
continue;
switch ( V_39 ) {
case V_46 :
if ( V_36 == V_41 -> V_27 -> V_36 ) {
V_2 = V_41 ;
V_2 -> V_50 = 1 ;
goto V_51;
}
break;
case V_47 :
if ( V_45 == ( V_41 -> V_32 & V_45 ) ) {
if ( V_2 )
V_2 -> V_50 = 0 ;
V_2 = V_41 ;
V_2 -> V_50 = 1 ;
if ( V_41 -> V_32 == V_45 )
goto V_51;
}
break;
case V_48 :
if ( V_43 == V_41 -> V_27 -> V_28 . V_52 ) {
V_2 = V_41 ;
V_2 -> V_50 = 1 ;
goto V_51;
}
break;
default:
V_2 = V_41 ;
V_2 -> V_50 = 1 ;
goto V_51;
}
}
V_51:
F_23 ( & V_49 , V_44 ) ;
if ( V_2 && F_10 ( V_2 ) ) {
V_2 -> V_50 = 0 ;
V_2 = NULL ;
}
if ( ! V_2 )
F_24 ( L_4 , V_53 ) ;
return V_2 ;
}
struct V_1 * F_25 ( void )
{
return F_20 ( V_54 , NULL ) ;
}
struct V_1 * F_26 ( int V_36 )
{
if ( F_27 () ) {
F_28 ( L_5 ,
V_53 ) ;
return NULL ;
}
return F_20 ( V_46 , & V_36 ) ;
}
struct V_1 * F_29 ( T_1 V_45 )
{
return F_20 ( V_47 , & V_45 ) ;
}
struct V_1 * F_30 ( struct V_42 * V_43 )
{
if ( ! V_43 )
return NULL ;
return F_20 ( V_48 , V_43 ) ;
}
int F_31 ( struct V_1 * V_2 )
{
if ( F_32 ( ! V_2 ) )
return - V_25 ;
F_33 ( V_2 -> V_34 ) ;
F_2 ( ! V_2 -> V_50 ) ;
V_2 -> V_50 = 0 ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
int V_55 ;
F_34 ( & V_2 -> V_27 -> V_28 ) ;
if ( ! ( V_2 -> V_32 & V_56 ) ) {
if ( V_2 -> V_57 ) {
V_55 = V_2 -> V_57 ( & V_2 -> V_27 -> V_28 ) ;
if ( V_55 != V_2 -> V_58 ) {
F_6 ( V_2 ) ;
V_2 -> V_58 = V_55 ;
}
} else {
F_6 ( V_2 ) ;
}
}
}
void F_15 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_27 -> V_28 ) ;
}
int F_36 ( struct V_1 * V_2 )
{
if ( V_2 )
return V_2 -> V_59 ;
return - V_25 ;
}
T_2 F_37 ( T_2 V_60 )
{
int V_61 = 0 ;
struct V_1 * V_2 = NULL ;
unsigned long V_44 ;
if ( ! ( V_60 & ( 1 << 1 ) ) )
return V_60 ;
F_21 ( & V_49 , V_44 ) ;
F_22 (timer, &omap_timer_list, node) {
T_1 V_22 ;
V_22 = F_1 ( V_2 , V_20 ) ;
if ( V_22 & V_62 ) {
if ( ( ( F_38 ( V_63 ) >> ( V_61 * 2 ) ) & 0x03 ) == 0 )
V_60 &= ~ ( 1 << 1 ) ;
else
V_60 &= ~ ( 1 << 2 ) ;
}
V_61 ++ ;
}
F_23 ( & V_49 , V_44 ) ;
return V_60 ;
}
struct V_64 * F_39 ( struct V_1 * V_2 )
{
if ( V_2 && ! F_13 ( V_2 -> V_34 ) )
return V_2 -> V_34 ;
return NULL ;
}
T_2 F_37 ( T_2 V_60 )
{
F_40 () ;
return 0 ;
}
int F_41 ( struct V_1 * V_2 )
{
if ( F_32 ( ! V_2 || F_42 ( & V_2 -> V_27 -> V_28 ) ) ) {
F_43 ( L_6 , V_53 ) ;
return - V_25 ;
}
F_4 ( V_2 , V_65 , 0 ) ;
return 0 ;
}
int F_44 ( struct V_1 * V_2 )
{
T_1 V_22 ;
if ( F_32 ( ! V_2 ) )
return - V_25 ;
F_14 ( V_2 ) ;
V_22 = F_1 ( V_2 , V_20 ) ;
if ( ! ( V_22 & V_62 ) ) {
V_22 |= V_62 ;
F_4 ( V_2 , V_20 , V_22 ) ;
}
V_2 -> V_8 . V_21 = V_22 ;
return 0 ;
}
int F_45 ( struct V_1 * V_2 )
{
unsigned long V_66 = 0 ;
if ( F_32 ( ! V_2 ) )
return - V_25 ;
if ( ! ( V_2 -> V_32 & V_33 ) )
V_66 = F_46 ( V_2 -> V_34 ) ;
F_47 ( V_2 , V_2 -> V_5 , V_66 ) ;
V_2 -> V_8 . V_21 =
F_1 ( V_2 , V_20 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , int V_67 )
{
int V_68 ;
char * V_69 = NULL ;
struct V_64 * V_70 ;
struct V_71 * V_72 ;
if ( F_32 ( ! V_2 ) )
return - V_25 ;
V_72 = V_2 -> V_27 -> V_28 . V_73 ;
if ( V_67 < 0 || V_67 >= 3 )
return - V_25 ;
if ( V_72 && V_72 -> V_74 )
return V_72 -> V_74 ( V_2 -> V_27 , V_67 ) ;
if ( F_13 ( V_2 -> V_34 ) )
return - V_25 ;
switch ( V_67 ) {
case V_75 :
V_69 = L_7 ;
break;
case V_35 :
V_69 = L_8 ;
break;
case V_76 :
V_69 = L_9 ;
break;
}
V_70 = F_11 ( & V_2 -> V_27 -> V_28 , V_69 ) ;
if ( F_13 ( V_70 ) ) {
F_43 ( L_10 , V_53 , V_69 ) ;
return - V_25 ;
}
V_68 = F_48 ( V_2 -> V_34 , V_70 ) ;
if ( V_68 < 0 )
F_43 ( L_11 , V_53 ,
V_69 ) ;
F_33 ( V_70 ) ;
return V_68 ;
}
int F_49 ( struct V_1 * V_2 , int V_77 ,
unsigned int V_78 )
{
T_1 V_22 ;
if ( F_32 ( ! V_2 ) )
return - V_25 ;
F_14 ( V_2 ) ;
V_22 = F_1 ( V_2 , V_20 ) ;
if ( V_77 )
V_22 |= V_79 ;
else
V_22 &= ~ V_79 ;
F_4 ( V_2 , V_20 , V_22 ) ;
F_4 ( V_2 , V_12 , V_78 ) ;
F_4 ( V_2 , V_65 , 0 ) ;
V_2 -> V_8 . V_21 = V_22 ;
V_2 -> V_8 . V_13 = V_78 ;
F_15 ( V_2 ) ;
return 0 ;
}
int F_50 ( struct V_1 * V_2 , int V_77 ,
unsigned int V_78 )
{
T_1 V_22 ;
if ( F_32 ( ! V_2 ) )
return - V_25 ;
F_14 ( V_2 ) ;
V_22 = F_1 ( V_2 , V_20 ) ;
if ( V_77 ) {
V_22 |= V_79 ;
F_4 ( V_2 , V_12 , V_78 ) ;
} else {
V_22 &= ~ V_79 ;
}
V_22 |= V_62 ;
F_51 ( V_2 , V_22 , V_78 , V_2 -> V_5 ) ;
V_2 -> V_8 . V_21 = V_22 ;
V_2 -> V_8 . V_13 = V_78 ;
V_2 -> V_8 . V_11 = V_78 ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 , int V_80 ,
unsigned int V_81 )
{
T_1 V_22 ;
if ( F_32 ( ! V_2 ) )
return - V_25 ;
F_14 ( V_2 ) ;
V_22 = F_1 ( V_2 , V_20 ) ;
if ( V_80 )
V_22 |= V_82 ;
else
V_22 &= ~ V_82 ;
F_4 ( V_2 , V_14 , V_81 ) ;
F_4 ( V_2 , V_20 , V_22 ) ;
V_2 -> V_8 . V_21 = V_22 ;
V_2 -> V_8 . V_15 = V_81 ;
F_15 ( V_2 ) ;
return 0 ;
}
int F_53 ( struct V_1 * V_2 , int V_83 ,
int V_84 , int V_85 )
{
T_1 V_22 ;
if ( F_32 ( ! V_2 ) )
return - V_25 ;
F_14 ( V_2 ) ;
V_22 = F_1 ( V_2 , V_20 ) ;
V_22 &= ~ ( V_86 | V_87 |
V_88 | ( 0x03 << 10 ) ) ;
if ( V_83 )
V_22 |= V_87 ;
if ( V_84 )
V_22 |= V_88 ;
V_22 |= V_85 << 10 ;
F_4 ( V_2 , V_20 , V_22 ) ;
V_2 -> V_8 . V_21 = V_22 ;
F_15 ( V_2 ) ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 , int V_89 )
{
T_1 V_22 ;
if ( F_32 ( ! V_2 ) )
return - V_25 ;
F_14 ( V_2 ) ;
V_22 = F_1 ( V_2 , V_20 ) ;
V_22 &= ~ ( V_90 | ( 0x07 << 2 ) ) ;
if ( V_89 >= 0x00 && V_89 <= 0x07 ) {
V_22 |= V_90 ;
V_22 |= V_89 << 2 ;
}
F_4 ( V_2 , V_20 , V_22 ) ;
V_2 -> V_8 . V_21 = V_22 ;
F_15 ( V_2 ) ;
return 0 ;
}
int F_55 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
if ( F_32 ( ! V_2 ) )
return - V_25 ;
F_14 ( V_2 ) ;
F_56 ( V_2 , V_6 ) ;
V_2 -> V_8 . V_18 = V_6 ;
V_2 -> V_8 . V_9 = V_6 ;
F_15 ( V_2 ) ;
return 0 ;
}
int F_57 ( struct V_1 * V_2 , T_1 V_91 )
{
T_1 V_22 = V_91 ;
if ( F_32 ( ! V_2 ) )
return - V_25 ;
F_14 ( V_2 ) ;
if ( V_2 -> V_24 == 1 )
V_22 = F_58 ( V_2 -> V_19 ) & ~ V_91 ;
F_7 ( V_22 , V_2 -> V_92 ) ;
V_22 = F_1 ( V_2 , V_7 ) & ~ V_91 ;
F_4 ( V_2 , V_7 , V_22 ) ;
V_2 -> V_8 . V_18 &= ~ V_91 ;
V_2 -> V_8 . V_9 &= ~ V_91 ;
F_15 ( V_2 ) ;
return 0 ;
}
unsigned int F_59 ( struct V_1 * V_2 )
{
unsigned int V_22 ;
if ( F_32 ( ! V_2 || F_42 ( & V_2 -> V_27 -> V_28 ) ) ) {
F_43 ( L_6 , V_53 ) ;
return 0 ;
}
V_22 = F_58 ( V_2 -> V_93 ) ;
return V_22 ;
}
int F_60 ( struct V_1 * V_2 , unsigned int V_6 )
{
if ( F_32 ( ! V_2 || F_42 ( & V_2 -> V_27 -> V_28 ) ) )
return - V_25 ;
F_61 ( V_2 , V_6 ) ;
return 0 ;
}
unsigned int F_62 ( struct V_1 * V_2 )
{
if ( F_32 ( ! V_2 || F_42 ( & V_2 -> V_27 -> V_28 ) ) ) {
F_43 ( L_12 , V_53 ) ;
return 0 ;
}
return F_63 ( V_2 , V_2 -> V_5 ) ;
}
int F_64 ( struct V_1 * V_2 , unsigned int V_6 )
{
if ( F_32 ( ! V_2 || F_42 ( & V_2 -> V_27 -> V_28 ) ) ) {
F_43 ( L_6 , V_53 ) ;
return - V_25 ;
}
F_4 ( V_2 , V_10 , V_6 ) ;
V_2 -> V_8 . V_11 = V_6 ;
return 0 ;
}
int F_65 ( void )
{
struct V_1 * V_2 ;
F_22 (timer, &omap_timer_list, node) {
if ( ! V_2 -> V_50 )
continue;
if ( F_1 ( V_2 , V_20 ) &
V_62 ) {
return 1 ;
}
}
return 0 ;
}
static int F_66 ( struct V_94 * V_27 )
{
unsigned long V_44 ;
struct V_1 * V_2 ;
struct V_95 * V_96 , * V_59 ;
struct V_97 * V_28 = & V_27 -> V_28 ;
const struct V_98 * V_81 ;
const struct V_71 * V_72 ;
int V_68 ;
V_81 = F_67 ( F_68 ( V_99 ) , V_28 ) ;
V_72 = V_81 ? V_81 -> V_40 : V_28 -> V_73 ;
if ( ! V_72 && ! V_28 -> V_52 ) {
F_9 ( V_28 , L_13 , V_53 ) ;
return - V_38 ;
}
V_59 = F_69 ( V_27 , V_100 , 0 ) ;
if ( F_32 ( ! V_59 ) ) {
F_9 ( V_28 , L_14 , V_53 ) ;
return - V_38 ;
}
V_96 = F_69 ( V_27 , V_101 , 0 ) ;
if ( F_32 ( ! V_96 ) ) {
F_9 ( V_28 , L_15 , V_53 ) ;
return - V_38 ;
}
V_2 = F_70 ( V_28 , sizeof( struct V_1 ) , V_102 ) ;
if ( ! V_2 ) {
F_9 ( V_28 , L_16 , V_53 ) ;
return - V_103 ;
}
V_2 -> V_34 = F_71 ( - V_38 ) ;
V_2 -> V_104 = F_72 ( V_28 , V_96 ) ;
if ( F_13 ( V_2 -> V_104 ) )
return F_73 ( V_2 -> V_104 ) ;
if ( V_28 -> V_52 ) {
if ( F_74 ( V_28 -> V_52 , L_17 , NULL ) )
V_2 -> V_32 |= V_56 ;
if ( F_74 ( V_28 -> V_52 , L_18 , NULL ) )
V_2 -> V_32 |= V_105 ;
if ( F_74 ( V_28 -> V_52 , L_19 , NULL ) )
V_2 -> V_32 |= V_106 ;
if ( F_74 ( V_28 -> V_52 , L_20 , NULL ) )
V_2 -> V_32 |= V_107 ;
} else {
V_2 -> V_36 = V_27 -> V_36 ;
V_2 -> V_32 = V_72 -> V_108 ;
V_2 -> V_50 = F_18 ( V_2 -> V_36 ) ;
V_2 -> V_57 = V_72 -> V_57 ;
}
if ( V_72 )
V_2 -> V_109 = V_72 -> V_110 ;
V_2 -> V_59 = V_59 -> V_111 ;
V_2 -> V_27 = V_27 ;
if ( ! ( V_2 -> V_32 & V_33 ) ) {
F_75 ( V_28 ) ;
F_76 ( V_28 ) ;
}
if ( ! V_2 -> V_50 ) {
V_68 = F_34 ( V_28 ) ;
if ( V_68 < 0 ) {
F_9 ( V_28 , L_21 ,
V_53 ) ;
goto V_112;
}
F_77 ( V_2 ) ;
F_78 ( V_28 ) ;
}
F_21 ( & V_49 , V_44 ) ;
F_79 ( & V_2 -> V_113 , & V_114 ) ;
F_23 ( & V_49 , V_44 ) ;
F_80 ( V_28 , L_22 ) ;
return 0 ;
V_112:
F_81 ( V_28 ) ;
F_82 ( V_28 ) ;
return V_68 ;
}
static int F_83 ( struct V_94 * V_27 )
{
struct V_1 * V_2 ;
unsigned long V_44 ;
int V_68 = - V_25 ;
F_21 ( & V_49 , V_44 ) ;
F_22 (timer, &omap_timer_list, node)
if ( ! strcmp ( F_84 ( & V_2 -> V_27 -> V_28 ) ,
F_84 ( & V_27 -> V_28 ) ) ) {
F_85 ( & V_2 -> V_113 ) ;
V_68 = 0 ;
break;
}
F_23 ( & V_49 , V_44 ) ;
F_82 ( & V_27 -> V_28 ) ;
return V_68 ;
}

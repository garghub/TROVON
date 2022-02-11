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
struct V_32 * V_33 ;
if ( ! V_2 -> V_34 )
return - V_35 ;
V_33 = F_11 ( & V_2 -> V_27 -> V_28 , NULL ) ;
if ( F_12 ( V_33 ) )
return - V_35 ;
V_31 = F_13 ( V_2 -> V_34 , V_33 ) ;
if ( V_31 < 0 )
F_14 ( L_2 , V_36 ) ;
F_15 ( V_33 ) ;
return V_31 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_37 ;
if ( ! ( V_2 -> V_38 & V_39 ) ) {
V_2 -> V_34 = F_11 ( & V_2 -> V_27 -> V_28 , L_3 ) ;
if ( F_17 ( F_12 ( V_2 -> V_34 ) ) ) {
F_9 ( & V_2 -> V_27 -> V_28 , L_4 ) ;
return - V_25 ;
}
}
F_18 ( V_2 ) ;
if ( V_2 -> V_38 & V_39 ) {
V_37 = F_8 ( V_2 ) ;
if ( V_37 ) {
F_19 ( V_2 ) ;
return V_37 ;
}
}
F_20 ( V_2 ) ;
F_19 ( V_2 ) ;
V_37 = F_10 ( V_2 ) ;
if ( V_37 == - V_35 )
return F_21 ( V_2 , V_40 ) ;
return V_37 ;
}
static inline T_1 F_22 ( int V_41 )
{
return ( V_42 & ( 1 << ( V_41 - 1 ) ) ) ? 1 : 0 ;
}
int F_23 ( int V_41 )
{
if ( F_22 ( V_41 ) )
return - V_35 ;
V_42 |= ( 1 << ( V_41 - 1 ) ) ;
return 0 ;
}
static struct V_1 * F_24 ( int V_43 , void * V_44 )
{
struct V_1 * V_2 = NULL , * V_45 ;
struct V_46 * V_47 = NULL ;
unsigned long V_48 ;
T_1 V_49 = 0 ;
int V_41 = 0 ;
switch ( V_43 ) {
case V_50 :
V_41 = * ( int * ) V_44 ;
break;
case V_51 :
V_49 = * ( T_1 * ) V_44 ;
break;
case V_52 :
V_47 = (struct V_46 * ) V_44 ;
break;
default:
break;
}
F_25 ( & V_53 , V_48 ) ;
F_26 (t, &omap_timer_list, node) {
if ( V_45 -> V_54 )
continue;
switch ( V_43 ) {
case V_50 :
if ( V_41 == V_45 -> V_27 -> V_41 ) {
V_2 = V_45 ;
V_2 -> V_54 = 1 ;
goto V_55;
}
break;
case V_51 :
if ( V_49 == ( V_45 -> V_38 & V_49 ) ) {
if ( V_2 )
V_2 -> V_54 = 0 ;
V_2 = V_45 ;
V_2 -> V_54 = 1 ;
if ( V_45 -> V_38 == V_49 )
goto V_55;
}
break;
case V_52 :
if ( V_47 == V_45 -> V_27 -> V_28 . V_56 ) {
V_2 = V_45 ;
V_2 -> V_54 = 1 ;
goto V_55;
}
break;
default:
V_2 = V_45 ;
V_2 -> V_54 = 1 ;
goto V_55;
}
}
V_55:
F_27 ( & V_53 , V_48 ) ;
if ( V_2 && F_16 ( V_2 ) ) {
V_2 -> V_54 = 0 ;
V_2 = NULL ;
}
if ( ! V_2 )
F_28 ( L_5 , V_36 ) ;
return V_2 ;
}
struct V_1 * F_29 ( void )
{
return F_24 ( V_57 , NULL ) ;
}
struct V_1 * F_30 ( int V_41 )
{
if ( F_31 () ) {
F_32 ( L_6 ,
V_36 ) ;
return NULL ;
}
return F_24 ( V_50 , & V_41 ) ;
}
struct V_1 * F_33 ( T_1 V_49 )
{
return F_24 ( V_51 , & V_49 ) ;
}
struct V_1 * F_34 ( struct V_46 * V_47 )
{
if ( ! V_47 )
return NULL ;
return F_24 ( V_52 , V_47 ) ;
}
int F_35 ( struct V_1 * V_2 )
{
if ( F_36 ( ! V_2 ) )
return - V_25 ;
F_15 ( V_2 -> V_34 ) ;
F_2 ( ! V_2 -> V_54 ) ;
V_2 -> V_54 = 0 ;
return 0 ;
}
void F_18 ( struct V_1 * V_2 )
{
int V_58 ;
F_37 ( & V_2 -> V_27 -> V_28 ) ;
if ( ! ( V_2 -> V_38 & V_59 ) ) {
if ( V_2 -> V_60 ) {
V_58 = V_2 -> V_60 ( & V_2 -> V_27 -> V_28 ) ;
if ( V_58 != V_2 -> V_61 ) {
F_6 ( V_2 ) ;
V_2 -> V_61 = V_58 ;
}
} else {
F_6 ( V_2 ) ;
}
}
}
void F_19 ( struct V_1 * V_2 )
{
F_38 ( & V_2 -> V_27 -> V_28 ) ;
}
int F_39 ( struct V_1 * V_2 )
{
if ( V_2 )
return V_2 -> V_62 ;
return - V_25 ;
}
T_2 F_40 ( T_2 V_63 )
{
int V_64 = 0 ;
struct V_1 * V_2 = NULL ;
unsigned long V_48 ;
if ( ! ( V_63 & ( 1 << 1 ) ) )
return V_63 ;
F_25 ( & V_53 , V_48 ) ;
F_26 (timer, &omap_timer_list, node) {
T_1 V_22 ;
V_22 = F_1 ( V_2 , V_20 ) ;
if ( V_22 & V_65 ) {
if ( ( ( F_41 ( V_66 ) >> ( V_64 * 2 ) ) & 0x03 ) == 0 )
V_63 &= ~ ( 1 << 1 ) ;
else
V_63 &= ~ ( 1 << 2 ) ;
}
V_64 ++ ;
}
F_27 ( & V_53 , V_48 ) ;
return V_63 ;
}
struct V_32 * F_42 ( struct V_1 * V_2 )
{
if ( V_2 && ! F_12 ( V_2 -> V_34 ) )
return V_2 -> V_34 ;
return NULL ;
}
T_2 F_40 ( T_2 V_63 )
{
F_43 () ;
return 0 ;
}
int F_44 ( struct V_1 * V_2 )
{
if ( F_36 ( ! V_2 || F_45 ( & V_2 -> V_27 -> V_28 ) ) ) {
F_14 ( L_7 , V_36 ) ;
return - V_25 ;
}
F_4 ( V_2 , V_67 , 0 ) ;
return 0 ;
}
int F_46 ( struct V_1 * V_2 )
{
T_1 V_22 ;
if ( F_36 ( ! V_2 ) )
return - V_25 ;
F_18 ( V_2 ) ;
V_22 = F_1 ( V_2 , V_20 ) ;
if ( ! ( V_22 & V_65 ) ) {
V_22 |= V_65 ;
F_4 ( V_2 , V_20 , V_22 ) ;
}
V_2 -> V_8 . V_21 = V_22 ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 )
{
unsigned long V_68 = 0 ;
if ( F_36 ( ! V_2 ) )
return - V_25 ;
if ( ! ( V_2 -> V_38 & V_39 ) )
V_68 = F_48 ( V_2 -> V_34 ) ;
F_49 ( V_2 , V_2 -> V_5 , V_68 ) ;
V_2 -> V_8 . V_21 =
F_1 ( V_2 , V_20 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , int V_69 )
{
int V_31 ;
char * V_70 = NULL ;
struct V_32 * V_33 ;
struct V_71 * V_72 ;
if ( F_36 ( ! V_2 ) )
return - V_25 ;
V_72 = V_2 -> V_27 -> V_28 . V_73 ;
if ( V_69 < 0 || V_69 >= 3 )
return - V_25 ;
if ( V_72 && V_72 -> V_74 )
return V_72 -> V_74 ( V_2 -> V_27 , V_69 ) ;
if ( F_12 ( V_2 -> V_34 ) )
return - V_25 ;
#if F_50 ( V_75 )
if ( F_51 ( F_52 ( V_2 -> V_34 ) ) < 2 )
return 0 ;
#endif
switch ( V_69 ) {
case V_76 :
V_70 = L_8 ;
break;
case V_40 :
V_70 = L_9 ;
break;
case V_77 :
V_70 = L_10 ;
break;
}
V_33 = F_11 ( & V_2 -> V_27 -> V_28 , V_70 ) ;
if ( F_12 ( V_33 ) ) {
F_14 ( L_11 , V_36 , V_70 ) ;
return - V_25 ;
}
V_31 = F_13 ( V_2 -> V_34 , V_33 ) ;
if ( V_31 < 0 )
F_14 ( L_12 , V_36 ,
V_70 ) ;
F_15 ( V_33 ) ;
return V_31 ;
}
int F_53 ( struct V_1 * V_2 , int V_78 ,
unsigned int V_79 )
{
T_1 V_22 ;
if ( F_36 ( ! V_2 ) )
return - V_25 ;
F_18 ( V_2 ) ;
V_22 = F_1 ( V_2 , V_20 ) ;
if ( V_78 )
V_22 |= V_80 ;
else
V_22 &= ~ V_80 ;
F_4 ( V_2 , V_20 , V_22 ) ;
F_4 ( V_2 , V_12 , V_79 ) ;
F_4 ( V_2 , V_67 , 0 ) ;
V_2 -> V_8 . V_21 = V_22 ;
V_2 -> V_8 . V_13 = V_79 ;
F_19 ( V_2 ) ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 , int V_78 ,
unsigned int V_79 )
{
T_1 V_22 ;
if ( F_36 ( ! V_2 ) )
return - V_25 ;
F_18 ( V_2 ) ;
V_22 = F_1 ( V_2 , V_20 ) ;
if ( V_78 ) {
V_22 |= V_80 ;
F_4 ( V_2 , V_12 , V_79 ) ;
} else {
V_22 &= ~ V_80 ;
}
V_22 |= V_65 ;
F_55 ( V_2 , V_22 , V_79 , V_2 -> V_5 ) ;
V_2 -> V_8 . V_21 = V_22 ;
V_2 -> V_8 . V_13 = V_79 ;
V_2 -> V_8 . V_11 = V_79 ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 , int V_81 ,
unsigned int V_82 )
{
T_1 V_22 ;
if ( F_36 ( ! V_2 ) )
return - V_25 ;
F_18 ( V_2 ) ;
V_22 = F_1 ( V_2 , V_20 ) ;
if ( V_81 )
V_22 |= V_83 ;
else
V_22 &= ~ V_83 ;
F_4 ( V_2 , V_14 , V_82 ) ;
F_4 ( V_2 , V_20 , V_22 ) ;
V_2 -> V_8 . V_21 = V_22 ;
V_2 -> V_8 . V_15 = V_82 ;
F_19 ( V_2 ) ;
return 0 ;
}
int F_57 ( struct V_1 * V_2 , int V_84 ,
int V_85 , int V_86 )
{
T_1 V_22 ;
if ( F_36 ( ! V_2 ) )
return - V_25 ;
F_18 ( V_2 ) ;
V_22 = F_1 ( V_2 , V_20 ) ;
V_22 &= ~ ( V_87 | V_88 |
V_89 | ( 0x03 << 10 ) ) ;
if ( V_84 )
V_22 |= V_88 ;
if ( V_85 )
V_22 |= V_89 ;
V_22 |= V_86 << 10 ;
F_4 ( V_2 , V_20 , V_22 ) ;
V_2 -> V_8 . V_21 = V_22 ;
F_19 ( V_2 ) ;
return 0 ;
}
int F_58 ( struct V_1 * V_2 , int V_90 )
{
T_1 V_22 ;
if ( F_36 ( ! V_2 ) )
return - V_25 ;
F_18 ( V_2 ) ;
V_22 = F_1 ( V_2 , V_20 ) ;
V_22 &= ~ ( V_91 | ( 0x07 << 2 ) ) ;
if ( V_90 >= 0x00 && V_90 <= 0x07 ) {
V_22 |= V_91 ;
V_22 |= V_90 << 2 ;
}
F_4 ( V_2 , V_20 , V_22 ) ;
V_2 -> V_8 . V_21 = V_22 ;
F_19 ( V_2 ) ;
return 0 ;
}
int F_59 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
if ( F_36 ( ! V_2 ) )
return - V_25 ;
F_18 ( V_2 ) ;
F_60 ( V_2 , V_6 ) ;
V_2 -> V_8 . V_18 = V_6 ;
V_2 -> V_8 . V_9 = V_6 ;
F_19 ( V_2 ) ;
return 0 ;
}
int F_61 ( struct V_1 * V_2 , T_1 V_92 )
{
T_1 V_22 = V_92 ;
if ( F_36 ( ! V_2 ) )
return - V_25 ;
F_18 ( V_2 ) ;
if ( V_2 -> V_24 == 1 )
V_22 = F_62 ( V_2 -> V_19 ) & ~ V_92 ;
F_7 ( V_22 , V_2 -> V_93 ) ;
V_22 = F_1 ( V_2 , V_7 ) & ~ V_92 ;
F_4 ( V_2 , V_7 , V_22 ) ;
V_2 -> V_8 . V_18 &= ~ V_92 ;
V_2 -> V_8 . V_9 &= ~ V_92 ;
F_19 ( V_2 ) ;
return 0 ;
}
unsigned int F_63 ( struct V_1 * V_2 )
{
unsigned int V_22 ;
if ( F_36 ( ! V_2 || F_45 ( & V_2 -> V_27 -> V_28 ) ) ) {
F_14 ( L_7 , V_36 ) ;
return 0 ;
}
V_22 = F_62 ( V_2 -> V_94 ) ;
return V_22 ;
}
int F_64 ( struct V_1 * V_2 , unsigned int V_6 )
{
if ( F_36 ( ! V_2 || F_45 ( & V_2 -> V_27 -> V_28 ) ) )
return - V_25 ;
F_65 ( V_2 , V_6 ) ;
return 0 ;
}
unsigned int F_66 ( struct V_1 * V_2 )
{
if ( F_36 ( ! V_2 || F_45 ( & V_2 -> V_27 -> V_28 ) ) ) {
F_14 ( L_13 , V_36 ) ;
return 0 ;
}
return F_67 ( V_2 , V_2 -> V_5 ) ;
}
int F_68 ( struct V_1 * V_2 , unsigned int V_6 )
{
if ( F_36 ( ! V_2 || F_45 ( & V_2 -> V_27 -> V_28 ) ) ) {
F_14 ( L_7 , V_36 ) ;
return - V_25 ;
}
F_4 ( V_2 , V_10 , V_6 ) ;
V_2 -> V_8 . V_11 = V_6 ;
return 0 ;
}
int F_69 ( void )
{
struct V_1 * V_2 ;
F_26 (timer, &omap_timer_list, node) {
if ( ! V_2 -> V_54 )
continue;
if ( F_1 ( V_2 , V_20 ) &
V_65 ) {
return 1 ;
}
}
return 0 ;
}
static int F_70 ( struct V_95 * V_27 )
{
unsigned long V_48 ;
struct V_1 * V_2 ;
struct V_96 * V_97 , * V_62 ;
struct V_98 * V_28 = & V_27 -> V_28 ;
const struct V_99 * V_82 ;
const struct V_71 * V_72 ;
int V_31 ;
V_82 = F_71 ( F_72 ( V_100 ) , V_28 ) ;
V_72 = V_82 ? V_82 -> V_44 : V_28 -> V_73 ;
if ( ! V_72 && ! V_28 -> V_56 ) {
F_9 ( V_28 , L_14 , V_36 ) ;
return - V_35 ;
}
V_62 = F_73 ( V_27 , V_101 , 0 ) ;
if ( F_36 ( ! V_62 ) ) {
F_9 ( V_28 , L_15 , V_36 ) ;
return - V_35 ;
}
V_97 = F_73 ( V_27 , V_102 , 0 ) ;
if ( F_36 ( ! V_97 ) ) {
F_9 ( V_28 , L_16 , V_36 ) ;
return - V_35 ;
}
V_2 = F_74 ( V_28 , sizeof( struct V_1 ) , V_103 ) ;
if ( ! V_2 ) {
F_9 ( V_28 , L_17 , V_36 ) ;
return - V_104 ;
}
V_2 -> V_34 = F_75 ( - V_35 ) ;
V_2 -> V_105 = F_76 ( V_28 , V_97 ) ;
if ( F_12 ( V_2 -> V_105 ) )
return F_77 ( V_2 -> V_105 ) ;
if ( V_28 -> V_56 ) {
if ( F_78 ( V_28 -> V_56 , L_18 , NULL ) )
V_2 -> V_38 |= V_59 ;
if ( F_78 ( V_28 -> V_56 , L_19 , NULL ) )
V_2 -> V_38 |= V_106 ;
if ( F_78 ( V_28 -> V_56 , L_20 , NULL ) )
V_2 -> V_38 |= V_107 ;
if ( F_78 ( V_28 -> V_56 , L_21 , NULL ) )
V_2 -> V_38 |= V_108 ;
} else {
V_2 -> V_41 = V_27 -> V_41 ;
V_2 -> V_38 = V_72 -> V_109 ;
V_2 -> V_54 = F_22 ( V_2 -> V_41 ) ;
V_2 -> V_60 = V_72 -> V_60 ;
}
if ( V_72 )
V_2 -> V_110 = V_72 -> V_111 ;
V_2 -> V_62 = V_62 -> V_112 ;
V_2 -> V_27 = V_27 ;
if ( ! ( V_2 -> V_38 & V_39 ) ) {
F_79 ( V_28 ) ;
F_80 ( V_28 ) ;
}
if ( ! V_2 -> V_54 ) {
V_31 = F_37 ( V_28 ) ;
if ( V_31 < 0 ) {
F_9 ( V_28 , L_22 ,
V_36 ) ;
goto V_113;
}
F_81 ( V_2 ) ;
F_82 ( V_28 ) ;
}
F_25 ( & V_53 , V_48 ) ;
F_83 ( & V_2 -> V_114 , & V_115 ) ;
F_27 ( & V_53 , V_48 ) ;
F_84 ( V_28 , L_23 ) ;
return 0 ;
V_113:
F_85 ( V_28 ) ;
F_86 ( V_28 ) ;
return V_31 ;
}
static int F_87 ( struct V_95 * V_27 )
{
struct V_1 * V_2 ;
unsigned long V_48 ;
int V_31 = - V_25 ;
F_25 ( & V_53 , V_48 ) ;
F_26 (timer, &omap_timer_list, node)
if ( ! strcmp ( F_88 ( & V_2 -> V_27 -> V_28 ) ,
F_88 ( & V_27 -> V_28 ) ) ) {
F_89 ( & V_2 -> V_114 ) ;
V_31 = 0 ;
break;
}
F_27 ( & V_53 , V_48 ) ;
F_86 ( & V_27 -> V_28 ) ;
return V_31 ;
}

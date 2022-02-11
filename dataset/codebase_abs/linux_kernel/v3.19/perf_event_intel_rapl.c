static inline T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_2 -> V_4 . V_5 , V_3 ) ;
return V_3 ;
}
static inline T_1 F_3 ( T_1 V_6 )
{
return V_6 << ( 32 - F_4 ( V_7 ) -> V_8 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_4 ;
T_1 V_11 , V_12 ;
T_2 V_13 , V_14 ;
int V_15 = V_16 ;
V_17:
V_11 = F_6 ( & V_10 -> V_18 ) ;
F_2 ( V_2 -> V_4 . V_5 , V_12 ) ;
if ( F_7 ( & V_10 -> V_18 , V_11 ,
V_12 ) != V_11 ) {
F_8 () ;
goto V_17;
}
V_13 = ( V_12 << V_15 ) - ( V_11 << V_15 ) ;
V_13 >>= V_15 ;
V_14 = F_3 ( V_13 ) ;
F_9 ( V_14 , & V_2 -> V_19 ) ;
return V_12 ;
}
static void F_10 ( struct V_7 * V_20 )
{
F_11 ( & V_20 -> V_21 ,
V_20 -> V_22 , 0 ,
V_23 , 0 ) ;
}
static void F_12 ( struct V_7 * V_20 )
{
F_13 ( & V_20 -> V_21 ) ;
}
static enum V_24 F_14 ( struct V_21 * V_21 )
{
struct V_7 * V_20 = F_4 ( V_7 ) ;
struct V_1 * V_2 ;
unsigned long V_25 ;
if ( ! V_20 -> V_26 )
return V_27 ;
F_15 ( & V_20 -> V_28 , V_25 ) ;
F_16 (event, &pmu->active_list, active_entry) {
F_5 ( V_2 ) ;
}
F_17 ( & V_20 -> V_28 , V_25 ) ;
F_18 ( V_21 , V_20 -> V_22 ) ;
return V_29 ;
}
static void F_19 ( struct V_7 * V_20 )
{
struct V_21 * V_30 = & V_20 -> V_21 ;
F_20 ( V_30 , V_31 , V_32 ) ;
V_30 -> V_33 = F_14 ;
}
static void F_21 ( struct V_7 * V_20 ,
struct V_1 * V_2 )
{
if ( F_22 ( ! ( V_2 -> V_4 . V_34 & V_35 ) ) )
return;
V_2 -> V_4 . V_34 = 0 ;
F_23 ( & V_2 -> V_36 , & V_20 -> V_37 ) ;
F_24 ( & V_2 -> V_4 . V_18 , F_1 ( V_2 ) ) ;
V_20 -> V_26 ++ ;
if ( V_20 -> V_26 == 1 )
F_10 ( V_20 ) ;
}
static void F_25 ( struct V_1 * V_2 , int V_38 )
{
struct V_7 * V_20 = F_4 ( V_7 ) ;
unsigned long V_25 ;
F_15 ( & V_20 -> V_28 , V_25 ) ;
F_21 ( V_20 , V_2 ) ;
F_17 ( & V_20 -> V_28 , V_25 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_38 )
{
struct V_7 * V_20 = F_4 ( V_7 ) ;
struct V_9 * V_10 = & V_2 -> V_4 ;
unsigned long V_25 ;
F_15 ( & V_20 -> V_28 , V_25 ) ;
if ( ! ( V_10 -> V_34 & V_35 ) ) {
F_22 ( V_20 -> V_26 <= 0 ) ;
V_20 -> V_26 -- ;
if ( V_20 -> V_26 == 0 )
F_12 ( V_20 ) ;
F_27 ( & V_2 -> V_36 ) ;
F_22 ( V_10 -> V_34 & V_35 ) ;
V_10 -> V_34 |= V_35 ;
}
if ( ( V_38 & V_39 ) && ! ( V_10 -> V_34 & V_40 ) ) {
F_5 ( V_2 ) ;
V_10 -> V_34 |= V_40 ;
}
F_17 ( & V_20 -> V_28 , V_25 ) ;
}
static int F_28 ( struct V_1 * V_2 , int V_38 )
{
struct V_7 * V_20 = F_4 ( V_7 ) ;
struct V_9 * V_10 = & V_2 -> V_4 ;
unsigned long V_25 ;
F_15 ( & V_20 -> V_28 , V_25 ) ;
V_10 -> V_34 = V_40 | V_35 ;
if ( V_38 & V_41 )
F_21 ( V_20 , V_2 ) ;
F_17 ( & V_20 -> V_28 , V_25 ) ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 , int V_25 )
{
F_26 ( V_2 , V_39 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
T_1 V_42 = V_2 -> V_43 . V_44 & V_45 ;
int V_46 , V_47 , V_48 = 0 ;
if ( V_2 -> V_43 . type != V_49 . type )
return - V_50 ;
if ( V_2 -> V_43 . V_44 & ~ V_45 )
return - V_51 ;
switch ( V_42 ) {
case V_52 :
V_46 = V_53 ;
V_47 = V_54 ;
break;
case V_55 :
V_46 = V_56 ;
V_47 = V_57 ;
break;
case V_58 :
V_46 = V_59 ;
V_47 = V_60 ;
break;
case V_61 :
V_46 = V_62 ;
V_47 = V_63 ;
break;
default:
return - V_51 ;
}
if ( ! ( V_64 & ( 1 << V_46 ) ) )
return - V_51 ;
if ( V_2 -> V_43 . V_65 ||
V_2 -> V_43 . V_66 ||
V_2 -> V_43 . V_67 ||
V_2 -> V_43 . V_68 ||
V_2 -> V_43 . V_69 ||
V_2 -> V_43 . V_70 ||
V_2 -> V_43 . V_71 )
return - V_51 ;
V_2 -> V_4 . V_5 = V_47 ;
V_2 -> V_4 . V_44 = V_42 ;
V_2 -> V_4 . V_72 = V_46 ;
return V_48 ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
}
static T_3 F_32 ( struct V_73 * V_74 ,
struct V_75 * V_43 , char * V_76 )
{
return F_33 ( true , V_76 , & V_77 ) ;
}
static T_3 F_34 ( struct V_73 * V_74 ,
struct V_75 * V_43 ,
char * V_78 )
{
struct V_79 * V_80 = \
F_35 ( V_43 , struct V_79 , V_43 ) ;
if ( V_80 -> V_81 )
return sprintf ( V_78 , L_1 , V_80 -> V_81 ) ;
return 0 ;
}
static void F_36 ( int V_82 )
{
struct V_7 * V_20 = F_37 ( V_7 , V_82 ) ;
int V_83 , V_84 = F_38 ( V_82 ) ;
int V_85 = - 1 ;
F_39 (i) {
if ( V_83 == V_82 )
continue;
if ( V_84 == F_38 ( V_83 ) ) {
V_85 = V_83 ;
break;
}
}
if ( F_40 ( V_82 , & V_77 ) && V_85 >= 0 )
F_41 ( V_85 , & V_77 ) ;
F_42 ( F_43 ( & V_77 ) ) ;
if ( V_85 >= 0 )
F_44 ( V_20 -> V_20 , V_82 , V_85 ) ;
F_12 ( V_20 ) ;
}
static void F_45 ( int V_82 )
{
int V_83 , V_84 = F_38 ( V_82 ) ;
F_46 (i, &rapl_cpu_mask) {
if ( V_84 == F_38 ( V_83 ) )
return;
}
F_41 ( V_82 , & V_77 ) ;
}
static int F_47 ( int V_82 )
{
struct V_7 * V_20 = F_37 ( V_7 , V_82 ) ;
int V_84 = F_38 ( V_82 ) ;
T_1 V_86 ;
T_1 V_87 ;
if ( V_20 )
return 0 ;
if ( V_84 < 0 )
return - 1 ;
if ( F_48 ( V_88 , & V_87 ) )
return - 1 ;
V_20 = F_49 ( sizeof( * V_20 ) , V_89 , F_50 ( V_82 ) ) ;
if ( ! V_20 )
return - 1 ;
F_51 ( & V_20 -> V_28 ) ;
F_52 ( & V_20 -> V_37 ) ;
V_20 -> V_8 = ( V_87 >> 8 ) & 0x1FULL ;
V_20 -> V_20 = & V_49 ;
if ( V_20 -> V_8 < 32 )
V_86 = ( 1000 / ( 2 * 100 ) ) * ( 1ULL << ( 32 - V_20 -> V_8 - 1 ) ) ;
else
V_86 = 2 ;
V_20 -> V_22 = F_53 ( V_86 ) ;
F_19 ( V_20 ) ;
F_37 ( V_7 , V_82 ) = V_20 ;
F_37 ( V_90 , V_82 ) = NULL ;
return 0 ;
}
static void F_54 ( int V_82 )
{
struct V_7 * V_20 = F_37 ( V_90 , V_82 ) ;
F_55 ( V_20 ) ;
F_37 ( V_90 , V_82 ) = NULL ;
}
static int F_56 ( int V_82 )
{
struct V_7 * V_20 = F_37 ( V_7 , V_82 ) ;
if ( ! V_20 )
return 0 ;
F_37 ( V_7 , V_82 ) = NULL ;
F_37 ( V_90 , V_82 ) = V_20 ;
return 0 ;
}
static int F_57 ( struct V_91 * V_92 ,
unsigned long V_93 , void * V_94 )
{
unsigned int V_82 = ( long ) V_94 ;
switch ( V_93 & ~ V_95 ) {
case V_96 :
F_47 ( V_82 ) ;
break;
case V_97 :
F_45 ( V_82 ) ;
break;
case V_98 :
case V_99 :
F_56 ( V_82 ) ;
break;
case V_100 :
case V_101 :
F_54 ( V_82 ) ;
break;
case V_102 :
F_36 ( V_82 ) ;
break;
default:
break;
}
return V_103 ;
}
static int T_4 F_58 ( void )
{
struct V_7 * V_20 ;
int V_82 , V_48 ;
if ( ! F_59 ( V_104 ) )
return 0 ;
switch ( V_105 . V_106 ) {
case 42 :
case 58 :
V_64 = V_107 ;
V_108 . V_109 = V_110 ;
break;
case 60 :
case 69 :
V_64 = V_111 ;
V_108 . V_109 = V_112 ;
break;
case 45 :
case 62 :
V_64 = V_113 ;
V_108 . V_109 = V_114 ;
break;
default:
return 0 ;
}
F_60 () ;
F_39 (cpu) {
V_48 = F_47 ( V_82 ) ;
if ( V_48 )
goto V_115;
F_45 ( V_82 ) ;
}
F_61 ( F_57 ) ;
V_48 = F_62 ( & V_49 , L_2 , - 1 ) ;
if ( F_42 ( V_48 ) ) {
F_63 ( L_3 , V_48 ) ;
F_64 () ;
return - 1 ;
}
V_20 = F_4 ( V_7 ) ;
F_63 ( L_4
L_5
L_6
L_7 ,
V_20 -> V_8 ,
F_65 ( V_64 ) ,
F_66 ( V_20 -> V_22 ) ) ;
V_115:
F_64 () ;
return 0 ;
}

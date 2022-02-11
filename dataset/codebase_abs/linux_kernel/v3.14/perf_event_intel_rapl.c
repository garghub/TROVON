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
int V_77 = F_33 ( V_76 , V_78 - 2 , & V_79 ) ;
V_76 [ V_77 ++ ] = '\n' ;
V_76 [ V_77 ] = '\0' ;
return V_77 ;
}
static void F_34 ( int V_80 )
{
struct V_7 * V_20 = F_35 ( V_7 , V_80 ) ;
int V_81 , V_82 = F_36 ( V_80 ) ;
int V_83 = - 1 ;
F_37 (i) {
if ( V_81 == V_80 )
continue;
if ( V_82 == F_36 ( V_81 ) ) {
V_83 = V_81 ;
break;
}
}
if ( F_38 ( V_80 , & V_79 ) && V_83 >= 0 )
F_39 ( V_83 , & V_79 ) ;
F_40 ( F_41 ( & V_79 ) ) ;
if ( V_83 >= 0 )
F_42 ( V_20 -> V_20 , V_80 , V_83 ) ;
F_12 ( V_20 ) ;
}
static void F_43 ( int V_80 )
{
int V_81 , V_82 = F_36 ( V_80 ) ;
F_44 (i, &rapl_cpu_mask) {
if ( V_82 == F_36 ( V_81 ) )
return;
}
F_39 ( V_80 , & V_79 ) ;
}
static int F_45 ( int V_80 )
{
struct V_7 * V_20 = F_35 ( V_7 , V_80 ) ;
int V_82 = F_36 ( V_80 ) ;
T_1 V_84 ;
if ( V_20 )
return 0 ;
if ( V_82 < 0 )
return - 1 ;
V_20 = F_46 ( sizeof( * V_20 ) , V_85 , F_47 ( V_80 ) ) ;
if ( ! V_20 )
return - 1 ;
F_48 ( & V_20 -> V_28 ) ;
F_49 ( & V_20 -> V_37 ) ;
F_2 ( V_86 , V_20 -> V_8 ) ;
V_20 -> V_8 = ( V_20 -> V_8 >> 8 ) & 0x1FULL ;
V_20 -> V_20 = & V_49 ;
if ( V_20 -> V_8 < 32 )
V_84 = ( 1000 / ( 2 * 100 ) ) * ( 1ULL << ( 32 - V_20 -> V_8 - 1 ) ) ;
else
V_84 = 2 ;
V_20 -> V_22 = F_50 ( V_84 ) ;
F_19 ( V_20 ) ;
F_35 ( V_7 , V_80 ) = V_20 ;
F_35 ( V_87 , V_80 ) = NULL ;
return 0 ;
}
static void F_51 ( int V_80 )
{
struct V_7 * V_20 = F_35 ( V_87 , V_80 ) ;
F_52 ( V_20 ) ;
F_35 ( V_87 , V_80 ) = NULL ;
}
static int F_53 ( int V_80 )
{
struct V_7 * V_20 = F_35 ( V_7 , V_80 ) ;
if ( ! V_20 )
return 0 ;
F_35 ( V_7 , V_80 ) = NULL ;
F_35 ( V_87 , V_80 ) = V_20 ;
return 0 ;
}
static int F_54 ( struct V_88 * V_89 ,
unsigned long V_90 , void * V_91 )
{
unsigned int V_80 = ( long ) V_91 ;
switch ( V_90 & ~ V_92 ) {
case V_93 :
F_45 ( V_80 ) ;
break;
case V_94 :
F_43 ( V_80 ) ;
break;
case V_95 :
case V_96 :
F_53 ( V_80 ) ;
break;
case V_97 :
case V_98 :
F_51 ( V_80 ) ;
break;
case V_99 :
F_34 ( V_80 ) ;
break;
default:
break;
}
return V_100 ;
}
static int T_4 F_55 ( void )
{
struct V_7 * V_20 ;
int V_80 , V_48 ;
if ( ! F_56 ( V_101 ) )
return 0 ;
switch ( V_102 . V_103 ) {
case 42 :
case 58 :
case 60 :
case 69 :
V_64 = V_104 ;
V_105 . V_106 = V_107 ;
break;
case 45 :
case 62 :
V_64 = V_108 ;
V_105 . V_106 = V_109 ;
break;
default:
return 0 ;
}
F_57 () ;
F_37 (cpu) {
F_45 ( V_80 ) ;
F_43 ( V_80 ) ;
}
F_58 ( F_54 ) ;
V_48 = F_59 ( & V_49 , L_1 , - 1 ) ;
if ( F_40 ( V_48 ) ) {
F_60 ( L_2 , V_48 ) ;
F_61 () ;
return - 1 ;
}
V_20 = F_4 ( V_7 ) ;
F_60 ( L_3
L_4
L_5
L_6 ,
V_20 -> V_8 ,
F_62 ( V_64 ) ,
F_63 ( V_20 -> V_22 ) ) ;
F_61 () ;
return 0 ;
}

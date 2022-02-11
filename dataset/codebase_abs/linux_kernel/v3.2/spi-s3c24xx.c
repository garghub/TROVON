static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static void F_3 ( struct V_5 * V_6 , int V_7 , int V_8 )
{
F_4 ( V_6 -> V_9 , V_8 ) ;
}
static void F_5 ( struct V_2 * V_6 , int V_10 )
{
struct V_11 * V_7 = V_6 -> V_12 ;
struct V_1 * V_13 = F_1 ( V_6 ) ;
unsigned int V_14 = V_6 -> V_15 & V_16 ? 1 : 0 ;
switch ( V_10 ) {
case V_17 :
V_13 -> V_18 ( V_13 -> V_19 , V_6 -> V_20 , V_14 ^ 1 ) ;
F_6 ( V_7 -> V_21 , V_13 -> V_22 + V_23 ) ;
break;
case V_24 :
F_6 ( V_7 -> V_21 | V_25 ,
V_13 -> V_22 + V_23 ) ;
V_13 -> V_18 ( V_13 -> V_19 , V_6 -> V_20 , V_14 ) ;
break;
}
}
static int F_7 ( struct V_2 * V_6 ,
struct V_26 * V_27 )
{
struct V_1 * V_13 = F_1 ( V_6 ) ;
struct V_11 * V_7 = V_6 -> V_12 ;
unsigned int V_28 ;
unsigned int V_29 ;
unsigned int div ;
unsigned long V_30 ;
V_28 = V_27 ? V_27 -> V_31 : V_6 -> V_31 ;
V_29 = V_27 ? V_27 -> V_32 : V_6 -> V_33 ;
if ( ! V_28 )
V_28 = 8 ;
if ( ! V_29 )
V_29 = V_6 -> V_33 ;
if ( V_28 != 8 ) {
F_8 ( & V_6 -> V_34 , L_1 , V_28 ) ;
return - V_35 ;
}
if ( V_6 -> V_15 != V_7 -> V_15 ) {
T_1 V_21 = V_36 | V_25 ;
if ( V_6 -> V_15 & V_37 )
V_21 |= V_38 ;
if ( V_6 -> V_15 & V_39 )
V_21 |= V_40 ;
V_7 -> V_15 = V_6 -> V_15 ;
V_7 -> V_21 = V_21 ;
}
if ( V_7 -> V_29 != V_29 ) {
V_30 = F_9 ( V_13 -> V_30 ) ;
div = F_10 ( V_30 , V_29 * 2 ) - 1 ;
if ( div > 255 )
div = 255 ;
F_11 ( & V_6 -> V_34 , L_2 ,
div , V_29 , V_30 / ( 2 * ( div + 1 ) ) ) ;
V_7 -> V_29 = V_29 ;
V_7 -> V_41 = div ;
}
return 0 ;
}
static int F_12 ( struct V_2 * V_6 ,
struct V_26 * V_27 )
{
struct V_11 * V_7 = V_6 -> V_12 ;
struct V_1 * V_13 = F_1 ( V_6 ) ;
int V_42 ;
V_42 = F_7 ( V_6 , V_27 ) ;
if ( ! V_42 )
F_6 ( V_7 -> V_41 , V_13 -> V_22 + V_43 ) ;
return V_42 ;
}
static int F_13 ( struct V_2 * V_6 )
{
struct V_11 * V_7 = V_6 -> V_12 ;
struct V_1 * V_13 = F_1 ( V_6 ) ;
int V_42 ;
if ( ! V_7 ) {
V_7 = F_14 ( sizeof( struct V_11 ) , V_44 ) ;
if ( ! V_7 ) {
F_8 ( & V_6 -> V_34 , L_3 ) ;
return - V_45 ;
}
V_7 -> V_21 = V_36 ;
V_7 -> V_29 = - 1 ;
V_6 -> V_12 = V_7 ;
}
V_42 = F_7 ( V_6 , NULL ) ;
if ( V_42 )
return V_42 ;
F_15 ( & V_13 -> V_46 . V_47 ) ;
if ( ! V_13 -> V_46 . V_48 ) {
V_13 -> V_46 . V_49 ( V_6 , V_17 ) ;
}
F_16 ( & V_13 -> V_46 . V_47 ) ;
return 0 ;
}
static void F_17 ( struct V_2 * V_6 )
{
F_18 ( V_6 -> V_12 ) ;
}
static inline unsigned int F_19 ( struct V_1 * V_13 , int V_50 )
{
return V_13 -> V_51 ? V_13 -> V_51 [ V_50 ] : 0 ;
}
static inline T_2 F_20 ( unsigned int V_52 )
{
return 1 << ( V_52 - V_53 ) ;
}
void F_21 ( struct V_1 * V_13 )
{
struct V_54 V_22 ;
enum V_55 V_15 ;
struct V_56 * V_57 ;
int V_42 ;
if ( ! V_13 -> V_58 ) {
V_42 = F_22 ( & V_13 -> V_59 ) ;
if ( V_42 )
return;
}
if ( V_13 -> V_51 && ! V_13 -> V_60 )
V_15 = V_61 ;
else if ( V_13 -> V_60 && ! V_13 -> V_51 )
V_15 = V_62 ;
else
V_15 = V_63 ;
V_22 . V_64 [ V_65 ] = ( long ) V_13 -> V_22 ;
V_22 . V_64 [ V_66 ] = ( long ) V_13 -> V_60 ;
V_22 . V_64 [ V_67 ] = ( long ) V_13 -> V_51 + 1 ;
V_22 . V_64 [ V_68 ] = V_13 -> V_69 - 1 ;
V_22 . V_64 [ V_70 ] = ( long ) V_71 ;
F_23 ( & V_22 ) ;
if ( V_13 -> V_72 != V_15 ) {
T_2 * V_73 ;
V_13 -> V_72 = V_15 ;
switch ( V_15 ) {
case V_61 :
V_57 = & V_74 ;
break;
case V_62 :
V_57 = & V_75 ;
break;
case V_63 :
V_57 = & V_76 ;
break;
default:
V_57 = NULL ;
}
F_24 ( ! V_57 ) ;
V_73 = ( T_2 * ) & V_57 -> V_77 [ V_57 -> V_78 ] ;
* V_73 = F_20 ( V_13 -> V_52 ) ;
F_25 ( & V_57 -> V_77 , V_57 -> V_79 ) ;
}
F_26 ( V_13 -> V_52 , true ) ;
V_13 -> V_72 = V_15 ;
V_13 -> V_80 = 1 ;
}
static int F_27 ( void * V_81 , int V_82 )
{
struct V_1 * V_13 = V_81 ;
int V_42 = 0 ;
if ( V_82 ) {
if ( V_13 -> V_80 )
V_42 = - V_83 ;
V_13 -> V_72 = V_84 ;
V_13 -> V_58 = 0 ;
} else {
V_13 -> V_58 = 1 ;
}
return V_42 ;
}
static inline void F_28 ( struct V_1 * V_13 )
{
V_13 -> V_59 . V_85 = V_13 ;
V_13 -> V_59 . V_86 = F_29 ( V_13 -> V_34 ) ;
V_13 -> V_59 . V_87 = F_27 ;
}
static inline bool F_30 ( struct V_1 * V_13 )
{
return V_13 -> V_19 -> V_88 ;
}
static inline bool F_31 ( struct V_1 * V_6 )
{
return V_6 -> V_80 ;
}
static inline void F_28 ( struct V_1 * V_89 ) { }
static inline void F_21 ( struct V_1 * V_89 ) { }
static inline bool F_30 ( struct V_1 * V_89 ) { return false ; }
static inline bool F_31 ( struct V_1 * V_89 ) { return false ; }
static int F_32 ( struct V_2 * V_6 , struct V_26 * V_27 )
{
struct V_1 * V_13 = F_1 ( V_6 ) ;
V_13 -> V_51 = V_27 -> V_90 ;
V_13 -> V_60 = V_27 -> V_91 ;
V_13 -> V_69 = V_27 -> V_69 ;
V_13 -> V_50 = 0 ;
F_33 ( & V_13 -> V_92 ) ;
V_13 -> V_80 = 0 ;
if ( F_30 ( V_13 ) && V_27 -> V_69 >= 3 )
F_21 ( V_13 ) ;
F_6 ( F_19 ( V_13 , 0 ) , V_13 -> V_22 + V_93 ) ;
F_34 ( & V_13 -> V_92 ) ;
return V_13 -> V_50 ;
}
static T_3 F_35 ( int V_52 , void * V_34 )
{
struct V_1 * V_13 = V_34 ;
unsigned int V_94 = F_36 ( V_13 -> V_22 + V_95 ) ;
unsigned int V_50 = V_13 -> V_50 ;
if ( V_94 & V_96 ) {
F_11 ( V_13 -> V_34 , L_4 ) ;
F_37 ( & V_13 -> V_92 ) ;
goto V_97;
}
if ( ! ( V_94 & V_98 ) ) {
F_11 ( V_13 -> V_34 , L_5 ) ;
F_37 ( & V_13 -> V_92 ) ;
goto V_97;
}
if ( ! F_31 ( V_13 ) ) {
V_13 -> V_50 ++ ;
if ( V_13 -> V_60 )
V_13 -> V_60 [ V_50 ] = F_36 ( V_13 -> V_22 + V_99 ) ;
V_50 ++ ;
if ( V_50 < V_13 -> V_69 )
F_6 ( F_19 ( V_13 , V_50 ) , V_13 -> V_22 + V_93 ) ;
else
F_37 ( & V_13 -> V_92 ) ;
} else {
V_13 -> V_50 = V_13 -> V_69 ;
V_13 -> V_80 = 0 ;
if ( V_13 -> V_60 )
V_13 -> V_60 [ V_13 -> V_69 - 1 ] = F_36 ( V_13 -> V_22 + V_99 ) ;
F_37 ( & V_13 -> V_92 ) ;
}
V_97:
return V_100 ;
}
static void F_38 ( struct V_1 * V_13 )
{
F_39 ( V_13 -> V_30 ) ;
F_6 ( 0xff , V_13 -> V_22 + V_43 ) ;
F_6 ( V_101 , V_13 -> V_22 + V_102 ) ;
F_6 ( V_36 , V_13 -> V_22 + V_23 ) ;
if ( V_13 -> V_19 ) {
if ( V_13 -> V_18 == F_3 )
F_40 ( V_13 -> V_19 -> V_9 , 1 ) ;
if ( V_13 -> V_19 -> V_103 )
V_13 -> V_19 -> V_103 ( V_13 -> V_19 , 1 ) ;
}
}
static int T_4 F_41 ( struct V_104 * V_105 )
{
struct V_5 * V_19 ;
struct V_1 * V_13 ;
struct V_106 * V_4 ;
struct V_107 * V_108 ;
int V_109 = 0 ;
V_4 = F_42 ( & V_105 -> V_34 , sizeof( struct V_1 ) ) ;
if ( V_4 == NULL ) {
F_8 ( & V_105 -> V_34 , L_6 ) ;
V_109 = - V_45 ;
goto V_110;
}
V_13 = F_2 ( V_4 ) ;
memset ( V_13 , 0 , sizeof( struct V_1 ) ) ;
V_13 -> V_4 = F_43 ( V_4 ) ;
V_13 -> V_19 = V_19 = V_105 -> V_34 . V_111 ;
V_13 -> V_34 = & V_105 -> V_34 ;
if ( V_19 == NULL ) {
F_8 ( & V_105 -> V_34 , L_7 ) ;
V_109 = - V_112 ;
goto V_113;
}
F_44 ( V_105 , V_13 ) ;
F_33 ( & V_13 -> V_92 ) ;
F_28 ( V_13 ) ;
V_4 -> V_114 = V_39 | V_37 | V_16 ;
V_4 -> V_115 = V_13 -> V_19 -> V_116 ;
V_4 -> V_117 = V_19 -> V_117 ;
V_13 -> V_46 . V_4 = V_13 -> V_4 ;
V_13 -> V_46 . V_118 = F_12 ;
V_13 -> V_46 . V_49 = F_5 ;
V_13 -> V_46 . V_119 = F_32 ;
V_13 -> V_4 -> V_120 = F_13 ;
V_13 -> V_4 -> V_121 = F_17 ;
F_11 ( V_13 -> V_34 , L_8 , & V_13 -> V_46 ) ;
V_108 = F_45 ( V_105 , V_122 , 0 ) ;
if ( V_108 == NULL ) {
F_8 ( & V_105 -> V_34 , L_9 ) ;
V_109 = - V_112 ;
goto V_123;
}
V_13 -> V_124 = F_46 ( V_108 -> V_125 , F_47 ( V_108 ) ,
V_105 -> V_86 ) ;
if ( V_13 -> V_124 == NULL ) {
F_8 ( & V_105 -> V_34 , L_10 ) ;
V_109 = - V_126 ;
goto V_123;
}
V_13 -> V_22 = F_48 ( V_108 -> V_125 , F_47 ( V_108 ) ) ;
if ( V_13 -> V_22 == NULL ) {
F_8 ( & V_105 -> V_34 , L_11 ) ;
V_109 = - V_126 ;
goto V_127;
}
V_13 -> V_52 = F_49 ( V_105 , 0 ) ;
if ( V_13 -> V_52 < 0 ) {
F_8 ( & V_105 -> V_34 , L_12 ) ;
V_109 = - V_112 ;
goto V_128;
}
V_109 = F_50 ( V_13 -> V_52 , F_35 , 0 , V_105 -> V_86 , V_13 ) ;
if ( V_109 ) {
F_8 ( & V_105 -> V_34 , L_13 ) ;
goto V_128;
}
V_13 -> V_30 = F_51 ( & V_105 -> V_34 , L_14 ) ;
if ( F_52 ( V_13 -> V_30 ) ) {
F_8 ( & V_105 -> V_34 , L_15 ) ;
V_109 = F_53 ( V_13 -> V_30 ) ;
goto V_129;
}
if ( ! V_19 -> V_18 ) {
if ( V_19 -> V_9 < 0 ) {
F_8 ( & V_105 -> V_34 , L_16 ) ;
goto V_130;
}
V_109 = F_54 ( V_19 -> V_9 , F_29 ( & V_105 -> V_34 ) ) ;
if ( V_109 ) {
F_8 ( & V_105 -> V_34 , L_17 ) ;
goto V_130;
}
V_13 -> V_18 = F_3 ;
F_40 ( V_19 -> V_9 , 1 ) ;
} else
V_13 -> V_18 = V_19 -> V_18 ;
F_38 ( V_13 ) ;
V_109 = F_55 ( & V_13 -> V_46 ) ;
if ( V_109 ) {
F_8 ( & V_105 -> V_34 , L_18 ) ;
goto V_130;
}
return 0 ;
V_130:
if ( V_13 -> V_18 == F_3 )
F_56 ( V_19 -> V_9 ) ;
F_57 ( V_13 -> V_30 ) ;
F_58 ( V_13 -> V_30 ) ;
V_129:
F_59 ( V_13 -> V_52 , V_13 ) ;
V_128:
F_60 ( V_13 -> V_22 ) ;
V_127:
F_61 ( V_13 -> V_124 ) ;
F_18 ( V_13 -> V_124 ) ;
V_123:
V_113:
F_62 ( V_13 -> V_4 ) ;
V_110:
return V_109 ;
}
static int T_5 F_63 ( struct V_104 * V_34 )
{
struct V_1 * V_13 = F_64 ( V_34 ) ;
F_44 ( V_34 , NULL ) ;
F_65 ( & V_13 -> V_46 ) ;
F_57 ( V_13 -> V_30 ) ;
F_58 ( V_13 -> V_30 ) ;
F_59 ( V_13 -> V_52 , V_13 ) ;
F_60 ( V_13 -> V_22 ) ;
if ( V_13 -> V_18 == F_3 )
F_56 ( V_13 -> V_19 -> V_9 ) ;
F_61 ( V_13 -> V_124 ) ;
F_18 ( V_13 -> V_124 ) ;
F_62 ( V_13 -> V_4 ) ;
return 0 ;
}
static int F_66 ( struct V_131 * V_34 )
{
struct V_1 * V_13 = F_64 ( F_67 ( V_34 ) ) ;
if ( V_13 -> V_19 && V_13 -> V_19 -> V_103 )
V_13 -> V_19 -> V_103 ( V_13 -> V_19 , 0 ) ;
F_57 ( V_13 -> V_30 ) ;
return 0 ;
}
static int F_68 ( struct V_131 * V_34 )
{
struct V_1 * V_13 = F_64 ( F_67 ( V_34 ) ) ;
F_38 ( V_13 ) ;
return 0 ;
}

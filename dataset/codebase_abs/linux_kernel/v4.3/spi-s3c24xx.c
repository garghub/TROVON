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
unsigned int div ;
unsigned long V_29 ;
V_28 = V_27 ? V_27 -> V_30 : V_6 -> V_31 ;
if ( ! V_28 )
V_28 = V_6 -> V_31 ;
if ( V_6 -> V_15 != V_7 -> V_15 ) {
T_1 V_21 = V_32 | V_25 ;
if ( V_6 -> V_15 & V_33 )
V_21 |= V_34 ;
if ( V_6 -> V_15 & V_35 )
V_21 |= V_36 ;
V_7 -> V_15 = V_6 -> V_15 ;
V_7 -> V_21 = V_21 ;
}
if ( V_7 -> V_28 != V_28 ) {
V_29 = F_8 ( V_13 -> V_29 ) ;
div = F_9 ( V_29 , V_28 * 2 ) - 1 ;
if ( div > 255 )
div = 255 ;
F_10 ( & V_6 -> V_37 , L_1 ,
div , V_28 , V_29 / ( 2 * ( div + 1 ) ) ) ;
V_7 -> V_28 = V_28 ;
V_7 -> V_38 = div ;
}
return 0 ;
}
static int F_11 ( struct V_2 * V_6 ,
struct V_26 * V_27 )
{
struct V_11 * V_7 = V_6 -> V_12 ;
struct V_1 * V_13 = F_1 ( V_6 ) ;
int V_39 ;
V_39 = F_7 ( V_6 , V_27 ) ;
if ( ! V_39 )
F_6 ( V_7 -> V_38 , V_13 -> V_22 + V_40 ) ;
return V_39 ;
}
static int F_12 ( struct V_2 * V_6 )
{
struct V_11 * V_7 = V_6 -> V_12 ;
struct V_1 * V_13 = F_1 ( V_6 ) ;
int V_39 ;
if ( ! V_7 ) {
V_7 = F_13 ( & V_6 -> V_37 ,
sizeof( struct V_11 ) ,
V_41 ) ;
if ( ! V_7 )
return - V_42 ;
V_7 -> V_21 = V_32 ;
V_7 -> V_28 = - 1 ;
V_6 -> V_12 = V_7 ;
}
V_39 = F_7 ( V_6 , NULL ) ;
if ( V_39 )
return V_39 ;
F_14 ( & V_13 -> V_43 . V_44 ) ;
if ( ! V_13 -> V_43 . V_45 ) {
V_13 -> V_43 . V_46 ( V_6 , V_17 ) ;
}
F_15 ( & V_13 -> V_43 . V_44 ) ;
return 0 ;
}
static inline unsigned int F_16 ( struct V_1 * V_13 , int V_47 )
{
return V_13 -> V_48 ? V_13 -> V_48 [ V_47 ] : 0 ;
}
static inline T_2 F_17 ( unsigned int V_49 )
{
return 1 << ( V_49 - V_50 ) ;
}
static void F_18 ( struct V_1 * V_13 )
{
struct V_51 V_22 ;
enum V_52 V_15 ;
struct V_53 * V_54 ;
int V_39 ;
if ( ! V_13 -> V_55 ) {
V_39 = F_19 ( & V_13 -> V_56 ) ;
if ( V_39 )
return;
}
if ( V_13 -> V_48 && ! V_13 -> V_57 )
V_15 = V_58 ;
else if ( V_13 -> V_57 && ! V_13 -> V_48 )
V_15 = V_59 ;
else
V_15 = V_60 ;
V_22 . V_61 [ V_62 ] = ( long ) V_13 -> V_22 ;
V_22 . V_61 [ V_63 ] = ( long ) V_13 -> V_57 ;
V_22 . V_61 [ V_64 ] = ( long ) V_13 -> V_48 + 1 ;
V_22 . V_61 [ V_65 ] = V_13 -> V_66 - 1 ;
V_22 . V_61 [ V_67 ] = ( long ) V_68 ;
F_20 ( & V_22 ) ;
if ( V_13 -> V_69 != V_15 ) {
T_2 * V_70 ;
V_13 -> V_69 = V_15 ;
switch ( V_15 ) {
case V_58 :
V_54 = & V_71 ;
break;
case V_59 :
V_54 = & V_72 ;
break;
case V_60 :
V_54 = & V_73 ;
break;
default:
V_54 = NULL ;
}
F_21 ( ! V_54 ) ;
V_70 = ( T_2 * ) & V_54 -> V_74 [ V_54 -> V_75 ] ;
* V_70 = F_17 ( V_13 -> V_49 ) ;
F_22 ( & V_54 -> V_74 , V_54 -> V_76 ) ;
}
F_23 ( V_13 -> V_49 , true ) ;
V_13 -> V_69 = V_15 ;
V_13 -> V_77 = 1 ;
}
static int F_24 ( void * V_78 , int V_79 )
{
struct V_1 * V_13 = V_78 ;
int V_39 = 0 ;
if ( V_79 ) {
if ( V_13 -> V_77 )
V_39 = - V_80 ;
V_13 -> V_69 = V_81 ;
V_13 -> V_55 = 0 ;
} else {
V_13 -> V_55 = 1 ;
}
return V_39 ;
}
static inline void F_25 ( struct V_1 * V_13 )
{
V_13 -> V_56 . V_82 = V_13 ;
V_13 -> V_56 . V_83 = F_26 ( V_13 -> V_37 ) ;
V_13 -> V_56 . V_84 = F_24 ;
}
static inline bool F_27 ( struct V_1 * V_13 )
{
return V_13 -> V_19 -> V_85 ;
}
static inline bool F_28 ( struct V_1 * V_6 )
{
return V_6 -> V_77 ;
}
static inline void F_25 ( struct V_1 * V_86 ) { }
static inline void F_18 ( struct V_1 * V_86 ) { }
static inline bool F_27 ( struct V_1 * V_86 ) { return false ; }
static inline bool F_28 ( struct V_1 * V_86 ) { return false ; }
static int F_29 ( struct V_2 * V_6 , struct V_26 * V_27 )
{
struct V_1 * V_13 = F_1 ( V_6 ) ;
V_13 -> V_48 = V_27 -> V_87 ;
V_13 -> V_57 = V_27 -> V_88 ;
V_13 -> V_66 = V_27 -> V_66 ;
V_13 -> V_47 = 0 ;
F_30 ( & V_13 -> V_89 ) ;
V_13 -> V_77 = 0 ;
if ( F_27 ( V_13 ) && V_27 -> V_66 >= 3 )
F_18 ( V_13 ) ;
F_6 ( F_16 ( V_13 , 0 ) , V_13 -> V_22 + V_90 ) ;
F_31 ( & V_13 -> V_89 ) ;
return V_13 -> V_47 ;
}
static T_3 F_32 ( int V_49 , void * V_37 )
{
struct V_1 * V_13 = V_37 ;
unsigned int V_91 = F_33 ( V_13 -> V_22 + V_92 ) ;
unsigned int V_47 = V_13 -> V_47 ;
if ( V_91 & V_93 ) {
F_10 ( V_13 -> V_37 , L_2 ) ;
F_34 ( & V_13 -> V_89 ) ;
goto V_94;
}
if ( ! ( V_91 & V_95 ) ) {
F_10 ( V_13 -> V_37 , L_3 ) ;
F_34 ( & V_13 -> V_89 ) ;
goto V_94;
}
if ( ! F_28 ( V_13 ) ) {
V_13 -> V_47 ++ ;
if ( V_13 -> V_57 )
V_13 -> V_57 [ V_47 ] = F_33 ( V_13 -> V_22 + V_96 ) ;
V_47 ++ ;
if ( V_47 < V_13 -> V_66 )
F_6 ( F_16 ( V_13 , V_47 ) , V_13 -> V_22 + V_90 ) ;
else
F_34 ( & V_13 -> V_89 ) ;
} else {
V_13 -> V_47 = V_13 -> V_66 ;
V_13 -> V_77 = 0 ;
if ( V_13 -> V_57 )
V_13 -> V_57 [ V_13 -> V_66 - 1 ] = F_33 ( V_13 -> V_22 + V_96 ) ;
F_34 ( & V_13 -> V_89 ) ;
}
V_94:
return V_97 ;
}
static void F_35 ( struct V_1 * V_13 )
{
F_36 ( V_13 -> V_29 ) ;
F_6 ( 0xff , V_13 -> V_22 + V_40 ) ;
F_6 ( V_98 , V_13 -> V_22 + V_99 ) ;
F_6 ( V_32 , V_13 -> V_22 + V_23 ) ;
if ( V_13 -> V_19 ) {
if ( V_13 -> V_18 == F_3 )
F_37 ( V_13 -> V_19 -> V_9 , 1 ) ;
if ( V_13 -> V_19 -> V_100 )
V_13 -> V_19 -> V_100 ( V_13 -> V_19 , 1 ) ;
}
}
static int F_38 ( struct V_101 * V_102 )
{
struct V_5 * V_19 ;
struct V_1 * V_13 ;
struct V_103 * V_4 ;
struct V_104 * V_105 ;
int V_106 = 0 ;
V_4 = F_39 ( & V_102 -> V_37 , sizeof( struct V_1 ) ) ;
if ( V_4 == NULL ) {
F_40 ( & V_102 -> V_37 , L_4 ) ;
return - V_42 ;
}
V_13 = F_2 ( V_4 ) ;
V_13 -> V_4 = V_4 ;
V_13 -> V_19 = V_19 = F_41 ( & V_102 -> V_37 ) ;
V_13 -> V_37 = & V_102 -> V_37 ;
if ( V_19 == NULL ) {
F_40 ( & V_102 -> V_37 , L_5 ) ;
V_106 = - V_107 ;
goto V_108;
}
F_42 ( V_102 , V_13 ) ;
F_30 ( & V_13 -> V_89 ) ;
F_25 ( V_13 ) ;
V_4 -> V_109 = V_35 | V_33 | V_16 ;
V_4 -> V_110 = V_13 -> V_19 -> V_111 ;
V_4 -> V_112 = V_19 -> V_112 ;
V_4 -> V_113 = F_43 ( 8 ) ;
V_13 -> V_43 . V_4 = V_13 -> V_4 ;
V_13 -> V_43 . V_114 = F_11 ;
V_13 -> V_43 . V_46 = F_5 ;
V_13 -> V_43 . V_115 = F_29 ;
V_13 -> V_4 -> V_116 = F_12 ;
F_10 ( V_13 -> V_37 , L_6 , & V_13 -> V_43 ) ;
V_105 = F_44 ( V_102 , V_117 , 0 ) ;
V_13 -> V_22 = F_45 ( & V_102 -> V_37 , V_105 ) ;
if ( F_46 ( V_13 -> V_22 ) ) {
V_106 = F_47 ( V_13 -> V_22 ) ;
goto V_108;
}
V_13 -> V_49 = F_48 ( V_102 , 0 ) ;
if ( V_13 -> V_49 < 0 ) {
F_40 ( & V_102 -> V_37 , L_7 ) ;
V_106 = - V_107 ;
goto V_108;
}
V_106 = F_49 ( & V_102 -> V_37 , V_13 -> V_49 , F_32 , 0 ,
V_102 -> V_83 , V_13 ) ;
if ( V_106 ) {
F_40 ( & V_102 -> V_37 , L_8 ) ;
goto V_108;
}
V_13 -> V_29 = F_50 ( & V_102 -> V_37 , L_9 ) ;
if ( F_46 ( V_13 -> V_29 ) ) {
F_40 ( & V_102 -> V_37 , L_10 ) ;
V_106 = F_47 ( V_13 -> V_29 ) ;
goto V_108;
}
if ( ! V_19 -> V_18 ) {
if ( V_19 -> V_9 < 0 ) {
F_40 ( & V_102 -> V_37 , L_11 ) ;
V_106 = - V_118 ;
goto V_119;
}
V_106 = F_51 ( & V_102 -> V_37 , V_19 -> V_9 ,
F_26 ( & V_102 -> V_37 ) ) ;
if ( V_106 ) {
F_40 ( & V_102 -> V_37 , L_12 ) ;
goto V_119;
}
V_13 -> V_18 = F_3 ;
F_37 ( V_19 -> V_9 , 1 ) ;
} else
V_13 -> V_18 = V_19 -> V_18 ;
F_35 ( V_13 ) ;
V_106 = F_52 ( & V_13 -> V_43 ) ;
if ( V_106 ) {
F_40 ( & V_102 -> V_37 , L_13 ) ;
goto V_119;
}
return 0 ;
V_119:
F_53 ( V_13 -> V_29 ) ;
V_108:
F_54 ( V_13 -> V_4 ) ;
return V_106 ;
}
static int F_55 ( struct V_101 * V_37 )
{
struct V_1 * V_13 = F_56 ( V_37 ) ;
F_57 ( & V_13 -> V_43 ) ;
F_53 ( V_13 -> V_29 ) ;
F_54 ( V_13 -> V_4 ) ;
return 0 ;
}
static int F_58 ( struct V_120 * V_37 )
{
struct V_1 * V_13 = F_59 ( V_37 ) ;
int V_39 ;
V_39 = F_60 ( V_13 -> V_4 ) ;
if ( V_39 )
return V_39 ;
if ( V_13 -> V_19 && V_13 -> V_19 -> V_100 )
V_13 -> V_19 -> V_100 ( V_13 -> V_19 , 0 ) ;
F_53 ( V_13 -> V_29 ) ;
return 0 ;
}
static int F_61 ( struct V_120 * V_37 )
{
struct V_1 * V_13 = F_59 ( V_37 ) ;
F_35 ( V_13 ) ;
return F_62 ( V_13 -> V_4 ) ;
}

static inline T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline T_2 F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_4 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , unsigned int V_3 , T_1 V_5 )
{
F_6 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , unsigned int V_3 , T_2 V_5 )
{
F_8 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_6 , V_7 ) ;
F_7 ( V_2 , V_8 , V_9 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_6 , 0 ) ;
F_7 ( V_2 , V_8 , 0 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
}
static void F_12 ( struct V_1 * V_2 )
{
}
static void F_13 ( struct V_1 * V_2 )
{
int V_10 ;
T_1 V_11 ;
for ( V_10 = 0 ; V_10 < 50 ; V_10 ++ ) {
V_11 = F_1 ( V_2 , V_12 ) ;
if ( ! ( V_11 & V_13 ) )
break;
F_14 ( 1 ) ;
}
}
static T_3 F_15 ( int V_14 , void * V_15 )
{
struct V_1 * V_2 = V_15 ;
unsigned long V_16 = 0 ;
T_1 V_17 ;
V_17 = F_1 ( V_2 , V_12 ) ;
if ( V_17 & V_18 ) {
V_2 -> type -> V_19 ( V_2 ) ;
F_5 ( V_2 , V_12 , V_18 ) ;
V_2 -> type -> V_20 ( V_2 ) ;
V_16 |= V_21 | V_22 ;
}
if ( V_17 & V_23 )
V_16 |= V_21 | V_24 ;
F_16 ( V_2 -> V_2 , 1 , V_16 ) ;
return V_25 ;
}
static int F_17 ( struct V_26 * V_27 , unsigned int V_28 )
{
struct V_1 * V_2 = F_18 ( V_27 ) ;
T_1 V_3 , V_29 = 0 ;
F_19 () ;
F_13 ( V_2 ) ;
V_3 = F_1 ( V_2 , V_30 ) ;
if ( V_2 -> type -> V_31 )
V_29 = F_1 ( V_2 , V_32 ) ;
if ( V_28 ) {
V_3 |= V_33 ;
V_29 |= V_34 ;
} else {
V_3 &= ~ V_33 ;
V_29 &= ~ V_34 ;
}
F_13 ( V_2 ) ;
V_2 -> type -> V_19 ( V_2 ) ;
F_5 ( V_2 , V_30 , V_3 ) ;
if ( V_2 -> type -> V_31 )
F_5 ( V_2 , V_32 , V_29 ) ;
V_2 -> type -> V_20 ( V_2 ) ;
F_20 () ;
return 0 ;
}
static int F_21 ( struct V_35 * V_36 )
{
if ( F_22 ( V_36 ) != 0 )
return - V_37 ;
V_36 -> V_38 = F_23 ( V_36 -> V_38 ) ;
V_36 -> V_39 = F_23 ( V_36 -> V_39 ) ;
V_36 -> V_40 = F_23 ( V_36 -> V_40 ) ;
V_36 -> V_41 = F_23 ( V_36 -> V_41 ) ;
V_36 -> V_42 = F_23 ( V_36 -> V_42 + 1 ) ;
if ( V_36 -> V_43 < 100 || V_36 -> V_43 > 199 )
return - V_37 ;
V_36 -> V_43 = F_23 ( V_36 -> V_43 - 100 ) ;
return 0 ;
}
static void F_24 ( struct V_35 * V_36 )
{
V_36 -> V_38 = F_25 ( V_36 -> V_38 ) ;
V_36 -> V_39 = F_25 ( V_36 -> V_39 ) ;
V_36 -> V_40 = F_25 ( V_36 -> V_40 ) ;
V_36 -> V_41 = F_25 ( V_36 -> V_41 ) ;
V_36 -> V_42 = F_25 ( V_36 -> V_42 ) - 1 ;
V_36 -> V_43 = F_25 ( V_36 -> V_43 ) + 100 ;
}
static void F_26 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
V_36 -> V_38 = F_1 ( V_2 , V_44 ) ;
V_36 -> V_39 = F_1 ( V_2 , V_45 ) ;
V_36 -> V_40 = F_1 ( V_2 , V_46 ) ;
V_36 -> V_41 = F_1 ( V_2 , V_47 ) ;
V_36 -> V_42 = F_1 ( V_2 , V_48 ) ;
V_36 -> V_43 = F_1 ( V_2 , V_49 ) ;
}
static int F_27 ( struct V_26 * V_27 , struct V_35 * V_36 )
{
struct V_1 * V_2 = F_18 ( V_27 ) ;
F_19 () ;
F_13 ( V_2 ) ;
F_26 ( V_2 , V_36 ) ;
F_20 () ;
F_24 ( V_36 ) ;
return 0 ;
}
static int F_28 ( struct V_26 * V_27 , struct V_35 * V_36 )
{
struct V_1 * V_2 = F_18 ( V_27 ) ;
if ( F_21 ( V_36 ) < 0 )
return - V_37 ;
F_19 () ;
F_13 ( V_2 ) ;
V_2 -> type -> V_19 ( V_2 ) ;
F_5 ( V_2 , V_49 , V_36 -> V_43 ) ;
F_5 ( V_2 , V_48 , V_36 -> V_42 ) ;
F_5 ( V_2 , V_47 , V_36 -> V_41 ) ;
F_5 ( V_2 , V_46 , V_36 -> V_40 ) ;
F_5 ( V_2 , V_45 , V_36 -> V_39 ) ;
F_5 ( V_2 , V_44 , V_36 -> V_38 ) ;
V_2 -> type -> V_20 ( V_2 ) ;
F_20 () ;
return 0 ;
}
static int F_29 ( struct V_26 * V_27 , struct V_50 * V_51 )
{
struct V_1 * V_2 = F_18 ( V_27 ) ;
T_1 V_52 ;
F_19 () ;
F_13 ( V_2 ) ;
V_51 -> time . V_38 = F_1 ( V_2 , V_53 ) ;
V_51 -> time . V_39 = F_1 ( V_2 , V_54 ) ;
V_51 -> time . V_40 = F_1 ( V_2 , V_55 ) ;
V_51 -> time . V_41 = F_1 ( V_2 , V_56 ) ;
V_51 -> time . V_42 = F_1 ( V_2 , V_57 ) ;
V_51 -> time . V_43 = F_1 ( V_2 , V_58 ) ;
F_20 () ;
F_24 ( & V_51 -> time ) ;
V_52 = F_1 ( V_2 , V_30 ) ;
V_51 -> V_28 = ! ! ( V_52 & V_33 ) ;
return 0 ;
}
static int F_30 ( struct V_26 * V_27 , struct V_50 * V_51 )
{
struct V_1 * V_2 = F_18 ( V_27 ) ;
T_1 V_3 , V_29 = 0 ;
if ( F_21 ( & V_51 -> time ) < 0 )
return - V_37 ;
F_19 () ;
F_13 ( V_2 ) ;
V_2 -> type -> V_19 ( V_2 ) ;
F_5 ( V_2 , V_58 , V_51 -> time . V_43 ) ;
F_5 ( V_2 , V_57 , V_51 -> time . V_42 ) ;
F_5 ( V_2 , V_56 , V_51 -> time . V_41 ) ;
F_5 ( V_2 , V_55 , V_51 -> time . V_40 ) ;
F_5 ( V_2 , V_54 , V_51 -> time . V_39 ) ;
F_5 ( V_2 , V_53 , V_51 -> time . V_38 ) ;
V_3 = F_1 ( V_2 , V_30 ) ;
if ( V_2 -> type -> V_31 )
V_29 = F_1 ( V_2 , V_32 ) ;
if ( V_51 -> V_28 ) {
V_3 |= V_33 ;
V_29 |= V_34 ;
} else {
V_3 &= ~ V_33 ;
V_29 &= ~ V_34 ;
}
F_5 ( V_2 , V_30 , V_3 ) ;
if ( V_2 -> type -> V_31 )
F_5 ( V_2 , V_32 , V_29 ) ;
V_2 -> type -> V_20 ( V_2 ) ;
F_20 () ;
return 0 ;
}
static void F_31 ( void )
{
struct V_1 * V_2 = V_59 ;
struct V_35 V_36 ;
unsigned long V_60 ;
T_2 V_5 ;
V_2 -> type -> V_19 ( V_2 ) ;
V_5 = F_3 ( V_2 , V_61 ) ;
F_7 ( V_2 , V_61 , V_5 | V_62 ) ;
F_26 ( V_2 , & V_36 ) ;
F_24 ( & V_36 ) ;
F_32 ( & V_36 , & V_60 ) ;
F_33 ( V_60 + 2 , & V_36 ) ;
if ( F_21 ( & V_36 ) < 0 ) {
F_34 ( & V_2 -> V_2 -> V_27 , L_1 ) ;
return;
}
F_13 ( V_2 ) ;
F_5 ( V_2 , V_63 , V_36 . V_38 ) ;
F_5 ( V_2 , V_64 , V_36 . V_39 ) ;
F_5 ( V_2 , V_65 , V_36 . V_40 ) ;
F_5 ( V_2 , V_66 , V_36 . V_41 ) ;
F_5 ( V_2 , V_67 , V_36 . V_42 ) ;
F_5 ( V_2 , V_68 , V_36 . V_43 ) ;
V_5 = F_1 ( V_2 , V_30 ) ;
F_7 ( V_2 , V_30 ,
V_5 | V_69 ) ;
V_2 -> type -> V_20 ( V_2 ) ;
F_35 ( 2500 ) ;
}
static int F_36 ( struct V_70 * V_71 )
{
return 0 ;
}
static const char * F_37 ( struct V_70 * V_71 ,
unsigned int V_72 )
{
return NULL ;
}
static int F_38 ( struct V_70 * V_71 ,
unsigned int V_73 , unsigned long * V_74 )
{
struct V_1 * V_2 = F_39 ( V_71 ) ;
unsigned int V_75 = F_40 ( * V_74 ) ;
T_2 V_5 ;
T_4 V_76 = 0 ;
V_2 -> type -> V_19 ( V_2 ) ;
V_5 = F_3 ( V_2 , V_61 ) ;
V_2 -> type -> V_20 ( V_2 ) ;
switch ( V_75 ) {
case V_77 :
if ( ! ( V_5 & F_41 ( V_73 ) ) )
return - V_37 ;
break;
case V_78 :
if ( V_5 & F_42 ( V_73 ) )
return - V_37 ;
break;
default:
return - V_79 ;
} ;
* V_74 = F_43 ( V_75 , V_76 ) ;
return 0 ;
}
static int F_44 ( struct V_70 * V_71 ,
unsigned int V_73 , unsigned long * V_80 ,
unsigned int V_81 )
{
struct V_1 * V_2 = F_39 ( V_71 ) ;
T_2 V_5 ;
unsigned int V_75 ;
T_4 V_82 ;
int V_83 ;
V_2 -> type -> V_19 ( V_2 ) ;
V_5 = F_3 ( V_2 , V_61 ) ;
V_2 -> type -> V_20 ( V_2 ) ;
V_5 |= F_42 ( V_73 ) ;
for ( V_83 = 0 ; V_83 < V_81 ; V_83 ++ ) {
V_75 = F_40 ( V_80 [ V_83 ] ) ;
V_82 = F_45 ( V_80 [ V_83 ] ) ;
switch ( V_75 ) {
case V_77 :
if ( V_82 )
V_5 |= F_41 ( V_73 ) ;
else
V_5 &= ~ F_41 ( V_73 ) ;
break;
case V_78 :
V_5 &= ~ F_42 ( V_73 ) ;
break;
default:
F_34 ( & V_2 -> V_2 -> V_27 , L_2 ,
V_75 ) ;
return - V_79 ;
}
}
V_2 -> type -> V_19 ( V_2 ) ;
F_7 ( V_2 , V_61 , V_5 ) ;
V_2 -> type -> V_20 ( V_2 ) ;
return 0 ;
}
static int F_46 ( struct V_84 * V_85 )
{
struct V_1 * V_2 ;
struct V_86 * V_87 ;
T_1 V_3 , V_88 , V_89 ;
const struct V_90 * V_91 ;
const struct V_92 * V_93 ;
int V_94 ;
V_2 = F_47 ( & V_85 -> V_27 , sizeof( * V_2 ) , V_95 ) ;
if ( ! V_2 )
return - V_96 ;
V_93 = F_48 ( V_97 , & V_85 -> V_27 ) ;
if ( V_93 ) {
V_2 -> type = V_93 -> V_98 ;
V_2 -> V_99 = V_2 -> type -> V_100 &&
F_49 ( V_85 -> V_27 . V_101 ,
L_3 ) ;
} else {
V_91 = F_50 ( V_85 ) ;
V_2 -> type = ( void * ) V_91 -> V_102 ;
}
V_2 -> V_103 = F_51 ( V_85 , 0 ) ;
if ( V_2 -> V_103 <= 0 )
return - V_104 ;
V_2 -> V_105 = F_51 ( V_85 , 1 ) ;
if ( V_2 -> V_105 <= 0 )
return - V_104 ;
V_2 -> V_106 = F_52 ( & V_85 -> V_27 , L_4 ) ;
if ( ! F_53 ( V_2 -> V_106 ) )
V_2 -> V_107 = true ;
else
V_2 -> V_106 = F_52 ( & V_85 -> V_27 , L_5 ) ;
if ( ! F_53 ( V_2 -> V_106 ) )
F_54 ( V_2 -> V_106 ) ;
V_87 = F_55 ( V_85 , V_108 , 0 ) ;
V_2 -> V_4 = F_56 ( & V_85 -> V_27 , V_87 ) ;
if ( F_53 ( V_2 -> V_4 ) )
return F_57 ( V_2 -> V_4 ) ;
F_58 ( V_85 , V_2 ) ;
F_59 ( & V_85 -> V_27 ) ;
F_60 ( & V_85 -> V_27 ) ;
V_2 -> type -> V_19 ( V_2 ) ;
F_7 ( V_2 , V_30 , 0 ) ;
if ( V_2 -> type -> V_109 ) {
V_3 = F_1 ( V_2 , V_110 ) ;
F_7 ( V_2 , V_110 ,
V_3 | V_111 ) ;
}
V_3 = F_1 ( V_2 , V_12 ) ;
V_88 = V_18 ;
if ( V_2 -> type -> V_100 )
V_88 |= V_112 ;
if ( V_2 -> type -> V_113 ) {
V_88 |= V_114 ;
if ( V_3 & V_114 )
F_61 ( & V_85 -> V_27 , L_6 ) ;
}
if ( V_3 & V_88 )
F_5 ( V_2 , V_12 , V_3 & V_88 ) ;
V_3 = F_1 ( V_2 , V_115 ) ;
if ( V_3 & V_116 )
F_61 ( & V_85 -> V_27 , L_7 ) ;
V_89 = V_3 & ( V_117 | V_118 ) ;
V_89 |= V_116 ;
if ( V_89 & V_117 )
F_61 ( & V_85 -> V_27 , L_8 ) ;
if ( V_3 != V_89 )
F_5 ( V_2 , V_115 , V_89 ) ;
if ( V_2 -> V_107 ) {
V_3 = F_1 ( V_2 , V_110 ) ;
V_3 &= ~ V_119 ;
V_3 |= V_111 | V_120 ;
F_7 ( V_2 , V_110 , V_3 ) ;
}
V_2 -> type -> V_20 ( V_2 ) ;
F_62 ( & V_85 -> V_27 , true ) ;
V_2 -> V_2 = F_63 ( & V_85 -> V_27 , V_85 -> V_121 ,
& V_122 , V_123 ) ;
if ( F_53 ( V_2 -> V_2 ) ) {
V_94 = F_57 ( V_2 -> V_2 ) ;
goto V_124;
}
V_94 = F_64 ( & V_85 -> V_27 , V_2 -> V_103 , F_15 , 0 ,
F_65 ( & V_2 -> V_2 -> V_27 ) , V_2 ) ;
if ( V_94 )
goto V_124;
if ( V_2 -> V_103 != V_2 -> V_105 ) {
V_94 = F_64 ( & V_85 -> V_27 , V_2 -> V_105 , F_15 , 0 ,
F_65 ( & V_2 -> V_2 -> V_27 ) , V_2 ) ;
if ( V_94 )
goto V_124;
}
if ( V_2 -> V_99 ) {
if ( ! V_125 ) {
V_59 = V_2 ;
V_125 = F_31 ;
}
}
V_126 . V_121 = F_65 ( & V_85 -> V_27 ) ;
V_2 -> V_71 = F_66 ( & V_126 , & V_85 -> V_27 , V_2 ) ;
if ( F_53 ( V_2 -> V_71 ) ) {
F_34 ( & V_85 -> V_27 , L_9 ) ;
return F_57 ( V_2 -> V_71 ) ;
}
return 0 ;
V_124:
F_62 ( & V_85 -> V_27 , false ) ;
V_2 -> type -> V_20 ( V_2 ) ;
F_67 ( & V_85 -> V_27 ) ;
F_68 ( & V_85 -> V_27 ) ;
return V_94 ;
}
static int T_5 F_69 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = F_70 ( V_85 ) ;
T_1 V_3 ;
if ( V_125 == F_31 &&
V_59 == V_2 ) {
V_125 = NULL ;
V_59 = NULL ;
}
F_62 ( & V_85 -> V_27 , 0 ) ;
if ( ! F_53 ( V_2 -> V_106 ) )
F_71 ( V_2 -> V_106 ) ;
V_2 -> type -> V_19 ( V_2 ) ;
F_5 ( V_2 , V_30 , 0 ) ;
if ( V_2 -> V_107 ) {
V_3 = F_1 ( V_2 , V_110 ) ;
V_3 &= ~ V_120 ;
F_5 ( V_2 , V_110 , V_3 ) ;
}
V_2 -> type -> V_20 ( V_2 ) ;
F_67 ( & V_85 -> V_27 ) ;
F_68 ( & V_85 -> V_27 ) ;
F_72 ( V_2 -> V_71 ) ;
return 0 ;
}
static int F_73 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_18 ( V_27 ) ;
V_2 -> V_127 = F_1 ( V_2 , V_30 ) ;
V_2 -> type -> V_19 ( V_2 ) ;
if ( F_74 ( V_27 ) )
F_75 ( V_2 -> V_105 ) ;
else
F_5 ( V_2 , V_30 , 0 ) ;
V_2 -> type -> V_20 ( V_2 ) ;
V_2 -> V_128 = true ;
return 0 ;
}
static int F_76 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_18 ( V_27 ) ;
V_2 -> type -> V_19 ( V_2 ) ;
if ( F_74 ( V_27 ) )
F_77 ( V_2 -> V_105 ) ;
else
F_5 ( V_2 , V_30 , V_2 -> V_127 ) ;
V_2 -> type -> V_20 ( V_2 ) ;
V_2 -> V_128 = false ;
return 0 ;
}
static int F_78 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_18 ( V_27 ) ;
if ( V_2 -> V_128 && ! V_2 -> V_107 )
return - V_129 ;
return 0 ;
}
static int F_79 ( struct V_26 * V_27 )
{
return 0 ;
}
static void F_80 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = F_70 ( V_85 ) ;
T_1 V_88 ;
V_2 -> type -> V_19 ( V_2 ) ;
V_88 = F_1 ( V_2 , V_30 ) ;
V_88 &= V_33 ;
F_5 ( V_2 , V_30 , V_88 ) ;
V_2 -> type -> V_20 ( V_2 ) ;
}

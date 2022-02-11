static inline T_1 F_1 ( const void T_2 * V_1 , unsigned V_2 )
{ return F_2 ( V_1 + V_2 ) ; }
static inline T_3 F_3 ( const void T_2 * V_1 , unsigned V_2 )
{ return F_4 ( V_1 + V_2 ) ; }
static inline void F_5 ( void T_2 * V_1 , unsigned V_2 , T_1 V_3 )
{ F_6 ( V_3 , V_1 + V_2 ) ; }
static inline void F_7 ( void T_2 * V_1 , unsigned V_2 , T_3 V_3 )
{ F_8 ( V_3 , V_1 + V_2 ) ; }
static void F_9 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_7 )
{
T_3 V_8 ;
V_8 = F_10 ( V_5 -> V_9 [ V_6 ] ) ;
if ( V_7 ) {
V_8 &= ~ ( V_10 | V_11 ) ;
V_8 |= V_12 | V_13 ;
} else {
V_8 |= V_10 | V_11 ;
}
F_11 ( V_8 , V_5 -> V_9 [ V_6 ] ) ;
}
static void F_12 ( struct V_14 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
struct V_18 * V_19 = F_13 ( V_16 -> V_20 ) ;
struct V_4 * V_5 = F_14 ( V_19 ) ;
const struct V_21 * V_22 = V_5 -> V_22 ;
void T_2 * V_23 = V_14 -> V_24 ;
T_3 V_25 , V_26 ;
V_25 = ( ( V_14 -> V_25 & V_22 -> V_27 ) << V_22 -> V_28 ) |
( ( V_14 -> V_25 & V_22 -> V_29 ) << V_22 -> V_30 ) ;
V_26 = ( V_22 -> V_31 & ~ V_32 ) ;
F_7 ( V_23 , V_22 -> V_33 , V_25 ) ;
F_7 ( V_23 , V_22 -> V_34 , V_26 ) ;
F_7 ( V_23 , V_22 -> V_34 ,
( 1 << V_22 -> V_35 ) << V_22 -> V_36 ) ;
}
static void F_15 ( struct V_14 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
struct V_18 * V_19 = F_13 ( V_16 -> V_20 ) ;
struct V_4 * V_5 = F_14 ( V_19 ) ;
const struct V_21 * V_22 = V_5 -> V_22 ;
void T_2 * V_23 = V_14 -> V_24 ;
F_7 ( V_23 , V_22 -> V_37 , V_22 -> V_31 ) ;
F_7 ( V_23 , V_22 -> V_38 ,
V_22 -> V_39 | V_22 -> V_40 ) ;
F_5 ( V_14 -> V_41 , V_42 , 0 ) ;
F_7 ( V_23 , V_22 -> V_43 , 0 ) ;
}
static void F_16 ( unsigned long V_44 )
{
struct V_14 * V_14 = ( void * ) V_44 ;
void T_2 * V_41 = V_14 -> V_41 ;
struct V_15 * V_16 = V_14 -> V_17 ;
struct V_18 * V_19 = F_13 ( V_16 ) ;
struct V_4 * V_5 = F_17 ( V_16 -> V_20 ) ;
const struct V_21 * V_22 = V_5 -> V_22 ;
T_1 V_45 ;
unsigned long V_46 ;
V_45 = F_1 ( V_41 , V_42 ) ;
F_18 ( V_14 -> V_17 , L_1 , V_45 ,
F_19 ( V_14 -> V_47 -> V_48 ) ) ;
F_20 ( & V_14 -> V_49 , V_46 ) ;
switch ( V_14 -> V_47 -> V_48 ) {
case V_50 :
V_45 &= ~ V_51 ;
F_5 ( V_14 -> V_41 , V_42 , V_45 ) ;
V_45 = F_1 ( V_14 -> V_41 , V_42 ) ;
if ( V_45 & V_52 ) {
V_14 -> V_47 -> V_48 = V_53 ;
F_21 ( V_14 ) ;
} else {
V_14 -> V_47 -> V_48 = V_54 ;
F_22 ( V_14 ) ;
}
break;
case V_55 :
V_14 -> V_47 -> V_48 = V_56 ;
F_7 ( V_14 -> V_24 , V_22 -> V_34 ,
V_57 << V_22 -> V_36 ) ;
break;
case V_53 :
V_45 = F_1 ( V_41 , V_42 ) ;
if ( V_45 & V_52 )
F_23 ( & V_5 -> V_58 [ V_19 -> V_6 ] ,
V_59 + V_22 -> V_60 * V_61 ) ;
else
V_14 -> V_47 -> V_48 = V_54 ;
break;
default:
break;
}
F_24 ( & V_14 -> V_49 , V_46 ) ;
}
static void F_25 ( struct V_14 * V_14 , unsigned long V_62 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
struct V_18 * V_19 = F_13 ( V_16 ) ;
struct V_4 * V_5 = F_17 ( V_16 -> V_20 ) ;
if ( V_62 == 0 )
V_62 = V_59 + F_26 ( 3 ) ;
if ( V_14 -> V_63 || ( V_14 -> V_64 == 0 &&
V_14 -> V_47 -> V_48 == V_50 ) ) {
F_18 ( V_14 -> V_17 , L_2 ,
F_19 ( V_14 -> V_47 -> V_48 ) ) ;
F_27 ( & V_5 -> V_58 [ V_19 -> V_6 ] ) ;
V_5 -> V_65 [ V_19 -> V_6 ] = V_59 ;
return;
}
if ( F_28 ( V_5 -> V_65 [ V_19 -> V_6 ] , V_62 ) &&
F_29 ( & V_5 -> V_58 [ V_19 -> V_6 ] ) ) {
F_18 ( V_14 -> V_17 ,
L_3 ) ;
return;
}
V_5 -> V_65 [ V_19 -> V_6 ] = V_62 ;
F_18 ( V_14 -> V_17 , L_4 ,
F_19 ( V_14 -> V_47 -> V_48 ) ,
F_30 ( V_62 - V_59 ) ) ;
F_23 ( & V_5 -> V_58 [ V_19 -> V_6 ] , V_62 ) ;
}
static T_4 F_31 ( int V_66 , void * V_67 )
{
struct V_14 * V_14 = V_67 ;
void T_2 * V_23 = V_14 -> V_24 ;
struct V_15 * V_16 = V_14 -> V_17 ;
struct V_18 * V_19 = F_13 ( V_16 ) ;
struct V_4 * V_5 = F_17 ( V_16 -> V_20 ) ;
const struct V_21 * V_22 = V_5 -> V_22 ;
unsigned long V_46 ;
T_4 V_68 = V_69 ;
T_3 V_70 , V_71 ;
F_20 ( & V_14 -> V_49 , V_46 ) ;
V_70 = F_3 ( V_23 , V_22 -> V_72 ) ;
V_14 -> V_73 = ( V_70 & V_22 -> V_40 ) >> V_22 -> V_30 ;
V_14 -> V_74 = ( V_70 & V_22 -> V_39 ) >> V_22 -> V_28 ;
if ( V_70 )
F_7 ( V_23 , V_22 -> V_72 , V_70 ) ;
V_71 = F_3 ( V_23 , V_22 -> V_75 ) ;
if ( ! V_71 && ! V_70 )
goto V_43;
V_14 -> V_76 = ( V_71 & V_22 -> V_31 ) >> V_22 -> V_36 ;
if ( V_71 )
F_7 ( V_23 , V_22 -> V_75 , V_71 ) ;
F_18 ( V_14 -> V_17 , L_5 ,
V_71 , V_70 ) ;
if ( V_71 & V_77 )
F_32 ( L_6 ) ;
if ( V_71 & ( ( 1 << V_22 -> V_35 ) << V_22 -> V_36 ) ) {
int V_35 = F_3 ( V_23 , V_22 -> V_78 ) ;
void T_2 * V_41 = V_14 -> V_41 ;
T_1 V_45 = F_1 ( V_41 , V_42 ) ;
int V_79 ;
V_79 = V_14 -> V_76 & V_57 ;
if ( V_79 ) {
V_14 -> V_76 &= ~ V_57 ;
V_14 -> V_47 -> V_48 = V_55 ;
F_23 ( & V_5 -> V_58 [ V_19 -> V_6 ] ,
V_59 + V_22 -> V_60 * V_61 ) ;
F_33 ( L_7 ) ;
} else if ( V_35 ) {
V_14 -> V_63 = 1 ;
F_22 ( V_14 ) ;
V_14 -> V_47 -> V_80 -> V_81 = 1 ;
V_14 -> V_47 -> V_48 = V_56 ;
F_27 ( & V_5 -> V_58 [ V_19 -> V_6 ] ) ;
} else {
V_14 -> V_63 = 0 ;
F_21 ( V_14 ) ;
V_14 -> V_47 -> V_80 -> V_81 = 0 ;
V_14 -> V_47 -> V_48 = V_53 ;
}
F_18 ( V_14 -> V_17 , L_8 ,
V_35 ? L_9 : L_10 ,
F_19 ( V_14 -> V_47 -> V_48 ) ,
V_79 ? L_11 : L_12 ,
V_45 ) ;
V_68 = V_82 ;
}
if ( V_14 -> V_74 || V_14 -> V_73 || V_14 -> V_76 )
V_68 |= F_34 ( V_14 ) ;
V_43:
if ( V_68 == V_82 || V_70 || V_71 )
F_7 ( V_23 , V_22 -> V_43 , 1 ) ;
if ( V_14 -> V_47 -> V_48 == V_53 )
F_23 ( & V_5 -> V_58 [ V_19 -> V_6 ] ,
V_59 + V_22 -> V_60 * V_61 ) ;
F_24 ( & V_14 -> V_49 , V_46 ) ;
return V_68 ;
}
static int F_35 ( struct V_14 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
struct V_18 * V_19 = F_13 ( V_16 ) ;
struct V_4 * V_5 = F_17 ( V_16 -> V_20 ) ;
const struct V_21 * V_22 = V_5 -> V_22 ;
void T_2 * V_23 = V_14 -> V_24 ;
T_3 V_83 , V_84 ;
int V_78 ;
V_14 -> V_41 += V_22 -> V_85 ;
F_36 () ;
V_14 -> V_47 = F_37 ( V_86 ) ;
if ( F_38 ( V_14 -> V_47 ) )
return - V_87 ;
V_83 = F_3 ( V_23 , V_22 -> V_88 ) ;
if ( ! V_83 ) {
V_78 = - V_89 ;
goto V_90;
}
F_39 ( & V_5 -> V_58 [ V_19 -> V_6 ] , F_16 , ( unsigned long ) V_14 ) ;
F_7 ( V_23 , V_22 -> V_91 , ( 1 << V_22 -> V_92 ) ) ;
F_9 ( V_5 , V_19 -> V_6 , 1 ) ;
V_14 -> V_93 = F_31 ;
V_84 = F_3 ( V_23 , V_22 -> V_94 ) ;
V_84 &= ~ ( 1 << V_22 -> V_95 ) ;
F_7 ( V_14 -> V_24 , V_22 -> V_94 , V_84 ) ;
F_7 ( V_23 , V_22 -> V_43 , 0 ) ;
return 0 ;
V_90:
F_40 ( V_14 -> V_47 ) ;
F_41 () ;
return V_78 ;
}
static int F_42 ( struct V_14 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
struct V_18 * V_19 = F_13 ( V_16 ) ;
struct V_4 * V_5 = F_17 ( V_16 -> V_20 ) ;
F_43 ( & V_5 -> V_58 [ V_19 -> V_6 ] ) ;
F_9 ( V_5 , V_19 -> V_6 , 0 ) ;
F_40 ( V_14 -> V_47 ) ;
F_41 () ;
return 0 ;
}
static int F_44 ( struct V_4 * V_5 , T_1 V_6 )
{
struct V_15 * V_16 = V_5 -> V_16 ;
struct V_18 * V_19 = F_13 ( V_16 ) ;
struct V_96 * V_97 = V_16 -> V_98 ;
struct V_99 * V_100 = V_19 -> V_16 . V_101 ;
struct V_102 * V_103 ;
struct V_18 * V_14 ;
struct V_104 * V_105 ;
struct V_104 V_106 [ 2 ] ;
char V_107 [ 11 ] ;
int V_68 ;
V_106 [ 0 ] . V_108 = V_109 [ V_6 ] ;
V_106 [ 0 ] . V_110 = V_106 [ 0 ] . V_108 + V_111 - 1 ;
V_106 [ 0 ] . V_46 = V_112 ;
V_5 -> V_9 [ V_6 ] = F_45 ( & V_19 -> V_16 , V_106 ) ;
if ( F_46 ( V_5 -> V_9 [ V_6 ] ) ) {
V_68 = F_47 ( V_5 -> V_9 [ V_6 ] ) ;
goto V_90;
}
V_105 = F_48 ( V_19 , V_112 , V_6 + 1 ) ;
if ( ! V_105 ) {
F_49 ( V_16 , L_13 , V_6 ) ;
V_68 = - V_89 ;
goto V_90;
}
V_105 -> V_20 = NULL ;
V_106 [ 0 ] = * V_105 ;
V_105 = F_48 ( V_19 , V_113 , V_6 + 1 ) ;
if ( ! V_105 ) {
F_49 ( V_16 , L_14 , V_6 ) ;
V_68 = - V_89 ;
goto V_90;
}
V_105 -> V_20 = NULL ;
V_106 [ 1 ] = * V_105 ;
V_106 [ 1 ] . V_114 = L_15 ;
V_14 = F_50 ( L_16 , V_115 ) ;
if ( ! V_14 ) {
F_49 ( V_16 , L_17 ) ;
V_68 = - V_116 ;
goto V_90;
}
V_14 -> V_16 . V_20 = V_16 ;
V_14 -> V_16 . V_117 = & V_118 ;
V_14 -> V_16 . V_119 = V_118 ;
V_5 -> V_14 [ V_6 ] = V_14 ;
V_68 = F_51 ( V_14 , V_106 , 2 ) ;
if ( V_68 ) {
F_49 ( V_16 , L_18 ) ;
goto V_120;
}
if ( V_100 ) {
V_97 = F_52 ( & V_19 -> V_16 , sizeof( * V_97 ) , V_121 ) ;
if ( ! V_97 ) {
F_49 ( & V_19 -> V_16 ,
L_19 ) ;
V_68 = - V_116 ;
goto V_120;
}
V_103 = F_52 ( & V_19 -> V_16 , sizeof( * V_103 ) , V_121 ) ;
if ( ! V_103 ) {
F_49 ( & V_19 -> V_16 ,
L_20 ) ;
goto V_120;
}
F_53 ( V_100 , L_21 , ( T_3 * ) & V_103 -> V_122 ) ;
F_53 ( V_100 , L_22 , ( T_3 * ) & V_103 -> V_123 ) ;
snprintf ( V_107 , sizeof( V_107 ) , L_23 , V_6 ) ;
F_53 ( V_100 , V_107 , ( T_3 * ) & V_97 -> V_124 ) ;
F_53 ( V_100 , L_24 , ( T_3 * ) & V_97 -> V_125 ) ;
V_103 -> V_126 = F_54 ( V_100 , L_25 ) ;
V_97 -> V_103 = V_103 ;
}
V_97 -> V_127 = & V_128 ;
V_68 = F_55 ( V_14 , V_97 , sizeof( * V_97 ) ) ;
if ( V_68 ) {
F_49 ( V_16 , L_26 ) ;
goto V_120;
}
V_68 = F_56 ( V_14 ) ;
if ( V_68 ) {
F_49 ( V_16 , L_27 ) ;
goto V_120;
}
return 0 ;
V_120:
F_57 ( V_14 ) ;
V_90:
return V_68 ;
}
static int F_58 ( struct V_18 * V_19 )
{
struct V_99 * V_100 = V_19 -> V_16 . V_101 ;
const struct V_129 * V_130 ;
const struct V_21 * V_22 ;
struct V_4 * V_5 ;
struct V_104 * V_131 ;
int V_68 , V_132 ;
V_130 = F_59 ( V_133 , V_100 ) ;
if ( ! V_130 ) {
F_49 ( & V_19 -> V_16 , L_28 ) ;
V_68 = - V_134 ;
goto V_90;
}
V_22 = V_130 -> V_3 ;
V_5 = F_60 ( sizeof( * V_5 ) , V_121 ) ;
if ( ! V_5 ) {
F_49 ( & V_19 -> V_16 , L_29 ) ;
V_68 = - V_116 ;
goto V_90;
}
V_131 = F_48 ( V_19 , V_112 , 0 ) ;
if ( ! V_131 ) {
F_49 ( & V_19 -> V_16 , L_30 ) ;
V_68 = - V_89 ;
goto V_135;
}
V_5 -> V_16 = & V_19 -> V_16 ;
V_5 -> V_22 = F_61 ( V_22 , sizeof( * V_22 ) , V_121 ) ;
if ( ! V_5 -> V_22 ) {
F_49 ( & V_19 -> V_16 , L_31 ) ;
V_68 = - V_116 ;
goto V_135;
}
F_62 ( V_19 , V_5 ) ;
F_63 ( & V_19 -> V_16 ) ;
V_68 = F_64 ( & V_19 -> V_16 ) ;
if ( V_68 < 0 ) {
F_49 ( & V_19 -> V_16 , L_32 ) ;
goto V_120;
}
for ( V_132 = 0 ; V_132 < V_22 -> V_136 ; V_132 ++ ) {
V_68 = F_44 ( V_5 , V_132 ) ;
if ( V_68 != 0 ) {
F_49 ( & V_19 -> V_16 , L_33 ) ;
for ( V_132 -- ; V_132 >= 0 ; V_132 -- )
F_65 ( V_5 -> V_14 [ V_132 ] ) ;
goto V_137;
}
}
return 0 ;
V_137:
F_66 ( & V_19 -> V_16 ) ;
V_120:
F_67 ( & V_19 -> V_16 ) ;
F_68 ( V_5 -> V_22 ) ;
V_135:
F_68 ( V_5 ) ;
V_90:
return V_68 ;
}
static int F_69 ( struct V_18 * V_19 )
{
struct V_4 * V_5 = F_14 ( V_19 ) ;
const struct V_21 * V_22 = V_5 -> V_22 ;
int V_132 ;
for ( V_132 = 0 ; V_132 < V_22 -> V_136 ; V_132 ++ )
F_65 ( V_5 -> V_14 [ V_132 ] ) ;
F_66 ( & V_19 -> V_16 ) ;
F_67 ( & V_19 -> V_16 ) ;
F_68 ( V_5 -> V_22 ) ;
F_68 ( V_5 ) ;
return 0 ;
}
static int F_70 ( struct V_15 * V_16 )
{
struct V_18 * V_19 = F_13 ( V_16 -> V_20 ) ;
struct V_4 * V_5 = F_14 ( V_19 ) ;
const struct V_21 * V_22 = V_5 -> V_22 ;
int V_132 ;
for ( V_132 = 0 ; V_132 < V_22 -> V_136 ; V_132 ++ )
F_9 ( V_5 , V_132 , 0 ) ;
return 0 ;
}
static int F_71 ( struct V_15 * V_16 )
{
struct V_18 * V_19 = F_13 ( V_16 -> V_20 ) ;
struct V_4 * V_5 = F_14 ( V_19 ) ;
const struct V_21 * V_22 = V_5 -> V_22 ;
int V_132 ;
for ( V_132 = 0 ; V_132 < V_22 -> V_136 ; V_132 ++ )
F_9 ( V_5 , V_132 , 1 ) ;
return 0 ;
}
static int T_5 F_72 ( void )
{
return F_73 ( & V_138 ) ;
}
static void T_6 F_74 ( void )
{
F_75 ( & V_138 ) ;
}

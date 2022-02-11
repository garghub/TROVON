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
V_78 = - V_87 ;
goto V_89;
}
F_39 ( & V_5 -> V_58 [ V_19 -> V_6 ] , F_16 , ( unsigned long ) V_14 ) ;
F_7 ( V_23 , V_22 -> V_90 , ( 1 << V_22 -> V_91 ) ) ;
F_9 ( V_5 , V_19 -> V_6 , 1 ) ;
V_14 -> V_92 = F_31 ;
V_84 = F_3 ( V_23 , V_22 -> V_93 ) ;
V_84 &= ~ ( 1 << V_22 -> V_94 ) ;
F_7 ( V_14 -> V_24 , V_22 -> V_93 , V_84 ) ;
F_7 ( V_23 , V_22 -> V_43 , 0 ) ;
return 0 ;
V_89:
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
struct V_95 * V_96 = V_16 -> V_97 ;
struct V_98 * V_99 = V_19 -> V_16 . V_100 ;
struct V_101 * V_102 ;
struct V_18 * V_14 ;
struct V_103 * V_104 ;
struct V_103 V_105 [ 2 ] ;
char V_106 [ 11 ] ;
int V_68 ;
V_105 [ 0 ] . V_107 = V_108 [ V_6 ] ;
V_105 [ 0 ] . V_109 = V_105 [ 0 ] . V_107 + V_110 - 1 ;
V_105 [ 0 ] . V_46 = V_111 ;
V_5 -> V_9 [ V_6 ] = F_45 ( & V_19 -> V_16 , V_105 ) ;
if ( V_5 -> V_9 [ V_6 ] == NULL ) {
F_46 ( V_16 , L_13 , V_6 ) ;
V_68 = - V_87 ;
goto V_89;
}
V_104 = F_47 ( V_19 , V_111 , V_6 + 1 ) ;
if ( ! V_104 ) {
F_46 ( V_16 , L_14 , V_6 ) ;
V_68 = - V_87 ;
goto V_89;
}
V_104 -> V_20 = NULL ;
V_105 [ 0 ] = * V_104 ;
V_104 = F_47 ( V_19 , V_112 , V_6 + 1 ) ;
if ( ! V_104 ) {
F_46 ( V_16 , L_15 , V_6 ) ;
V_68 = - V_87 ;
goto V_89;
}
V_104 -> V_20 = NULL ;
V_105 [ 1 ] = * V_104 ;
V_105 [ 1 ] . V_113 = L_16 ;
V_14 = F_48 ( L_17 , V_114 ) ;
if ( ! V_14 ) {
F_46 ( V_16 , L_18 ) ;
V_68 = - V_115 ;
goto V_89;
}
V_14 -> V_16 . V_20 = V_16 ;
V_14 -> V_16 . V_116 = & V_117 ;
V_14 -> V_16 . V_118 = V_117 ;
V_5 -> V_14 [ V_6 ] = V_14 ;
V_68 = F_49 ( V_14 , V_105 , 2 ) ;
if ( V_68 ) {
F_46 ( V_16 , L_19 ) ;
goto V_119;
}
if ( V_99 ) {
V_96 = F_50 ( & V_19 -> V_16 , sizeof( * V_96 ) , V_120 ) ;
if ( ! V_96 ) {
F_46 ( & V_19 -> V_16 ,
L_20 ) ;
V_68 = - V_115 ;
goto V_119;
}
V_102 = F_50 ( & V_19 -> V_16 , sizeof( * V_102 ) , V_120 ) ;
if ( ! V_102 ) {
F_46 ( & V_19 -> V_16 ,
L_21 ) ;
goto V_119;
}
F_51 ( V_99 , L_22 , ( T_3 * ) & V_102 -> V_121 ) ;
F_51 ( V_99 , L_23 , ( T_3 * ) & V_102 -> V_122 ) ;
snprintf ( V_106 , sizeof( V_106 ) , L_24 , V_6 ) ;
F_51 ( V_99 , V_106 , ( T_3 * ) & V_96 -> V_123 ) ;
F_51 ( V_99 , L_25 , ( T_3 * ) & V_96 -> V_124 ) ;
V_102 -> V_125 = F_52 ( V_99 , L_26 ) ;
V_96 -> V_102 = V_102 ;
}
V_96 -> V_126 = & V_127 ;
V_68 = F_53 ( V_14 , V_96 , sizeof( * V_96 ) ) ;
if ( V_68 ) {
F_46 ( V_16 , L_27 ) ;
goto V_119;
}
V_68 = F_54 ( V_14 ) ;
if ( V_68 ) {
F_46 ( V_16 , L_28 ) ;
goto V_119;
}
return 0 ;
V_119:
F_55 ( V_14 ) ;
V_89:
return V_68 ;
}
static int F_56 ( struct V_18 * V_19 )
{
struct V_98 * V_99 = V_19 -> V_16 . V_100 ;
const struct V_128 * V_129 ;
const struct V_21 * V_22 ;
struct V_4 * V_5 ;
struct V_103 * V_130 ;
int V_68 , V_131 ;
V_129 = F_57 ( V_132 , V_99 ) ;
if ( ! V_129 ) {
F_46 ( & V_19 -> V_16 , L_29 ) ;
V_68 = - V_133 ;
goto V_89;
}
V_22 = V_129 -> V_3 ;
V_5 = F_58 ( sizeof( * V_5 ) , V_120 ) ;
if ( ! V_5 ) {
F_46 ( & V_19 -> V_16 , L_30 ) ;
V_68 = - V_115 ;
goto V_89;
}
V_130 = F_47 ( V_19 , V_111 , 0 ) ;
if ( ! V_130 ) {
F_46 ( & V_19 -> V_16 , L_31 ) ;
V_68 = - V_87 ;
goto V_134;
}
V_5 -> V_16 = & V_19 -> V_16 ;
V_5 -> V_22 = F_59 ( V_22 , sizeof( * V_22 ) , V_120 ) ;
if ( ! V_5 -> V_22 ) {
F_46 ( & V_19 -> V_16 , L_32 ) ;
V_68 = - V_115 ;
goto V_134;
}
F_60 ( V_19 , V_5 ) ;
F_61 ( & V_19 -> V_16 ) ;
V_68 = F_62 ( & V_19 -> V_16 ) ;
if ( V_68 < 0 ) {
F_46 ( & V_19 -> V_16 , L_33 ) ;
goto V_119;
}
for ( V_131 = 0 ; V_131 < V_22 -> V_135 ; V_131 ++ ) {
V_68 = F_44 ( V_5 , V_131 ) ;
if ( V_68 != 0 ) {
F_46 ( & V_19 -> V_16 , L_34 ) ;
for ( V_131 -- ; V_131 >= 0 ; V_131 -- )
F_63 ( V_5 -> V_14 [ V_131 ] ) ;
goto V_136;
}
}
return 0 ;
V_136:
F_64 ( & V_19 -> V_16 ) ;
V_119:
F_65 ( & V_19 -> V_16 ) ;
F_66 ( V_5 -> V_22 ) ;
V_134:
F_66 ( V_5 ) ;
V_89:
return V_68 ;
}
static int F_67 ( struct V_18 * V_19 )
{
struct V_4 * V_5 = F_14 ( V_19 ) ;
const struct V_21 * V_22 = V_5 -> V_22 ;
int V_131 ;
for ( V_131 = 0 ; V_131 < V_22 -> V_135 ; V_131 ++ )
F_63 ( V_5 -> V_14 [ V_131 ] ) ;
F_64 ( & V_19 -> V_16 ) ;
F_65 ( & V_19 -> V_16 ) ;
F_66 ( V_5 -> V_22 ) ;
F_66 ( V_5 ) ;
return 0 ;
}
static int F_68 ( struct V_15 * V_16 )
{
struct V_18 * V_19 = F_13 ( V_16 -> V_20 ) ;
struct V_4 * V_5 = F_14 ( V_19 ) ;
const struct V_21 * V_22 = V_5 -> V_22 ;
int V_131 ;
for ( V_131 = 0 ; V_131 < V_22 -> V_135 ; V_131 ++ )
F_9 ( V_5 , V_131 , 0 ) ;
return 0 ;
}
static int F_69 ( struct V_15 * V_16 )
{
struct V_18 * V_19 = F_13 ( V_16 -> V_20 ) ;
struct V_4 * V_5 = F_14 ( V_19 ) ;
const struct V_21 * V_22 = V_5 -> V_22 ;
int V_131 ;
for ( V_131 = 0 ; V_131 < V_22 -> V_135 ; V_131 ++ )
F_9 ( V_5 , V_131 , 1 ) ;
return 0 ;
}
static int T_5 F_70 ( void )
{
return F_71 ( & V_137 ) ;
}
static void T_6 F_72 ( void )
{
F_73 ( & V_137 ) ;
}

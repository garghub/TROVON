static inline T_1 F_1 ( const void T_2 * V_1 , unsigned V_2 )
{ return F_2 ( V_1 + V_2 ) ; }
static inline T_3 F_3 ( const void T_2 * V_1 , unsigned V_2 )
{ return F_4 ( V_1 + V_2 ) ; }
static inline void F_5 ( void T_2 * V_1 , unsigned V_2 , T_1 V_3 )
{ F_6 ( V_3 , V_1 + V_2 ) ; }
static inline void F_7 ( void T_2 * V_1 , unsigned V_2 , T_3 V_3 )
{ F_8 ( V_3 , V_1 + V_2 ) ; }
static void F_9 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = F_10 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = F_11 ( V_9 ) ;
const struct V_13 * V_14 = V_12 -> V_14 ;
void T_2 * V_15 = V_4 -> V_16 ;
T_3 V_17 , V_18 ;
V_17 = ( ( V_4 -> V_17 & V_14 -> V_19 ) << V_14 -> V_20 ) |
( ( V_4 -> V_17 & V_14 -> V_21 ) << V_14 -> V_22 ) ;
V_18 = ( V_14 -> V_23 & ~ V_24 ) ;
F_7 ( V_15 , V_14 -> V_25 , V_17 ) ;
F_7 ( V_15 , V_14 -> V_26 , V_18 ) ;
F_7 ( V_15 , V_14 -> V_26 ,
( 1 << V_14 -> V_27 ) << V_14 -> V_28 ) ;
}
static void F_12 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = F_10 ( V_6 -> V_10 ) ;
struct V_11 * V_12 = F_11 ( V_9 ) ;
const struct V_13 * V_14 = V_12 -> V_14 ;
void T_2 * V_15 = V_4 -> V_16 ;
F_7 ( V_15 , V_14 -> V_29 , V_14 -> V_23 ) ;
F_7 ( V_15 , V_14 -> V_30 ,
V_14 -> V_31 | V_14 -> V_32 ) ;
F_5 ( V_4 -> V_33 , V_34 , 0 ) ;
F_7 ( V_15 , V_14 -> V_35 , 0 ) ;
}
static void F_13 ( unsigned long V_36 )
{
struct V_4 * V_4 = ( void * ) V_36 ;
void T_2 * V_33 = V_4 -> V_33 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = F_10 ( V_6 ) ;
struct V_11 * V_12 = F_14 ( V_6 -> V_10 ) ;
const struct V_13 * V_14 = V_12 -> V_14 ;
T_1 V_37 ;
unsigned long V_38 ;
V_37 = F_1 ( V_33 , V_34 ) ;
F_15 ( V_4 -> V_7 , L_1 , V_37 ,
F_16 ( V_4 -> V_39 -> V_40 ) ) ;
F_17 ( & V_4 -> V_41 , V_38 ) ;
switch ( V_4 -> V_39 -> V_40 ) {
case V_42 :
V_37 &= ~ V_43 ;
F_5 ( V_4 -> V_33 , V_34 , V_37 ) ;
V_37 = F_1 ( V_4 -> V_33 , V_34 ) ;
if ( V_37 & V_44 ) {
V_4 -> V_39 -> V_40 = V_45 ;
F_18 ( V_4 ) ;
} else {
V_4 -> V_39 -> V_40 = V_46 ;
F_19 ( V_4 ) ;
}
break;
case V_47 :
V_4 -> V_39 -> V_40 = V_48 ;
F_7 ( V_4 -> V_16 , V_14 -> V_26 ,
V_49 << V_14 -> V_28 ) ;
break;
case V_45 :
V_37 = F_1 ( V_33 , V_34 ) ;
if ( V_37 & V_44 )
F_20 ( & V_12 -> V_50 [ V_9 -> V_51 ] ,
V_52 + V_14 -> V_53 * V_54 ) ;
else
V_4 -> V_39 -> V_40 = V_46 ;
break;
default:
break;
}
F_21 ( & V_4 -> V_41 , V_38 ) ;
}
static void F_22 ( struct V_4 * V_4 , unsigned long V_55 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = F_10 ( V_6 ) ;
struct V_11 * V_12 = F_14 ( V_6 -> V_10 ) ;
if ( V_55 == 0 )
V_55 = V_52 + F_23 ( 3 ) ;
if ( V_4 -> V_56 || ( V_4 -> V_57 == 0 &&
V_4 -> V_39 -> V_40 == V_42 ) ) {
F_15 ( V_4 -> V_7 , L_2 ,
F_16 ( V_4 -> V_39 -> V_40 ) ) ;
F_24 ( & V_12 -> V_50 [ V_9 -> V_51 ] ) ;
V_12 -> V_58 [ V_9 -> V_51 ] = V_52 ;
return;
}
if ( F_25 ( V_12 -> V_58 [ V_9 -> V_51 ] , V_55 ) &&
F_26 ( & V_12 -> V_50 [ V_9 -> V_51 ] ) ) {
F_15 ( V_4 -> V_7 ,
L_3 ) ;
return;
}
V_12 -> V_58 [ V_9 -> V_51 ] = V_55 ;
F_15 ( V_4 -> V_7 , L_4 ,
F_16 ( V_4 -> V_39 -> V_40 ) ,
F_27 ( V_55 - V_52 ) ) ;
F_20 ( & V_12 -> V_50 [ V_9 -> V_51 ] , V_55 ) ;
}
static T_4 F_28 ( int V_59 , void * V_60 )
{
struct V_4 * V_4 = V_60 ;
void T_2 * V_15 = V_4 -> V_16 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = F_10 ( V_6 ) ;
struct V_11 * V_12 = F_14 ( V_6 -> V_10 ) ;
const struct V_13 * V_14 = V_12 -> V_14 ;
unsigned long V_38 ;
T_4 V_61 = V_62 ;
T_3 V_63 , V_64 ;
F_17 ( & V_4 -> V_41 , V_38 ) ;
V_63 = F_3 ( V_15 , V_14 -> V_65 ) ;
V_4 -> V_66 = ( V_63 & V_14 -> V_32 ) >> V_14 -> V_22 ;
V_4 -> V_67 = ( V_63 & V_14 -> V_31 ) >> V_14 -> V_20 ;
if ( V_63 )
F_7 ( V_15 , V_14 -> V_65 , V_63 ) ;
V_64 = F_3 ( V_15 , V_14 -> V_68 ) ;
if ( ! V_64 && ! V_63 )
goto V_35;
V_4 -> V_69 = ( V_64 & V_14 -> V_23 ) >> V_14 -> V_28 ;
if ( V_64 )
F_7 ( V_15 , V_14 -> V_68 , V_64 ) ;
F_15 ( V_4 -> V_7 , L_5 ,
V_64 , V_63 ) ;
if ( V_64 & V_70 )
F_29 ( L_6 ) ;
if ( V_64 & ( ( 1 << V_14 -> V_27 ) << V_14 -> V_28 ) ) {
int V_27 = F_3 ( V_15 , V_14 -> V_71 ) ;
void T_2 * V_33 = V_4 -> V_33 ;
T_1 V_37 = F_1 ( V_33 , V_34 ) ;
int V_72 ;
V_72 = V_4 -> V_69 & V_49 ;
if ( V_72 ) {
V_4 -> V_69 &= ~ V_49 ;
V_4 -> V_39 -> V_40 = V_47 ;
F_20 ( & V_12 -> V_50 [ V_9 -> V_51 ] ,
V_52 + V_14 -> V_53 * V_54 ) ;
F_30 ( L_7 ) ;
} else if ( V_27 ) {
V_4 -> V_56 = 1 ;
F_19 ( V_4 ) ;
V_4 -> V_39 -> V_73 -> V_74 = 1 ;
V_4 -> V_39 -> V_40 = V_48 ;
F_24 ( & V_12 -> V_50 [ V_9 -> V_51 ] ) ;
} else {
V_4 -> V_56 = 0 ;
F_18 ( V_4 ) ;
V_4 -> V_39 -> V_73 -> V_74 = 0 ;
V_4 -> V_39 -> V_40 = V_45 ;
}
F_15 ( V_4 -> V_7 , L_8 ,
V_27 ? L_9 : L_10 ,
F_16 ( V_4 -> V_39 -> V_40 ) ,
V_72 ? L_11 : L_12 ,
V_37 ) ;
V_61 = V_75 ;
}
if ( V_4 -> V_67 || V_4 -> V_66 || V_4 -> V_69 )
V_61 |= F_31 ( V_4 ) ;
V_35:
if ( V_61 == V_75 || V_63 || V_64 )
F_7 ( V_15 , V_14 -> V_35 , 1 ) ;
if ( V_4 -> V_39 -> V_40 == V_45 )
F_20 ( & V_12 -> V_50 [ V_9 -> V_51 ] ,
V_52 + V_14 -> V_53 * V_54 ) ;
F_21 ( & V_4 -> V_41 , V_38 ) ;
return V_61 ;
}
static int F_32 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_76 * V_77 = V_6 -> V_78 ;
struct V_8 * V_9 = F_10 ( V_6 ) ;
struct V_11 * V_12 = F_14 ( V_6 -> V_10 ) ;
const struct V_13 * V_14 = V_12 -> V_14 ;
struct V_79 * V_3 = V_77 -> V_80 ;
void T_2 * V_15 = V_4 -> V_16 ;
T_3 V_81 , V_82 ;
int V_71 ;
V_4 -> V_33 += V_14 -> V_83 ;
V_4 -> V_39 = F_33 ( V_84 ) ;
if ( F_34 ( V_4 -> V_39 ) )
return - V_85 ;
V_81 = F_3 ( V_15 , V_14 -> V_86 ) ;
if ( ! V_81 ) {
V_71 = - V_85 ;
goto V_87;
}
F_35 ( & V_12 -> V_50 [ V_9 -> V_51 ] , F_13 , ( unsigned long ) V_4 ) ;
F_7 ( V_15 , V_14 -> V_88 , ( 1 << V_14 -> V_89 ) ) ;
if ( V_3 -> V_90 )
V_3 -> V_90 ( 1 ) ;
V_4 -> V_91 = F_28 ;
V_82 = F_3 ( V_15 , V_14 -> V_92 ) ;
V_82 &= ~ ( 1 << V_14 -> V_93 ) ;
F_7 ( V_4 -> V_16 , V_14 -> V_92 , V_82 ) ;
F_7 ( V_15 , V_14 -> V_35 , 0 ) ;
return 0 ;
V_87:
F_36 ( V_4 -> V_39 ) ;
F_37 () ;
return V_71 ;
}
static int F_38 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_76 * V_77 = V_6 -> V_78 ;
struct V_79 * V_3 = V_77 -> V_80 ;
struct V_8 * V_9 = F_10 ( V_6 ) ;
struct V_11 * V_12 = F_14 ( V_6 -> V_10 ) ;
F_39 ( & V_12 -> V_50 [ V_9 -> V_51 ] ) ;
if ( V_3 -> V_90 )
V_3 -> V_90 ( 0 ) ;
F_36 ( V_4 -> V_39 ) ;
F_37 () ;
return 0 ;
}
static int T_5 F_40 ( struct V_11 * V_12 , T_1 V_51 )
{
struct V_5 * V_6 = V_12 -> V_6 ;
struct V_8 * V_9 = F_10 ( V_6 ) ;
struct V_76 * V_94 = V_6 -> V_78 ;
struct V_95 * V_96 = V_9 -> V_6 . V_97 ;
struct V_98 * V_99 ;
struct V_8 * V_4 ;
struct V_100 * V_101 ;
struct V_100 V_102 [ 2 ] ;
char V_103 [ 11 ] ;
int V_61 , V_104 ;
snprintf ( V_103 , sizeof( V_103 ) , L_13 , V_51 ) ;
V_101 = F_41 ( V_9 , V_105 , V_103 ) ;
if ( ! V_101 ) {
F_42 ( V_6 , L_14 , V_103 ) ;
V_61 = - V_85 ;
goto V_87;
}
V_101 -> V_10 = NULL ;
V_102 [ 0 ] = * V_101 ;
snprintf ( V_103 , sizeof( V_103 ) , L_15 , V_51 ) ;
V_101 = F_41 ( V_9 , V_106 , V_103 ) ;
if ( ! V_101 ) {
F_42 ( V_6 , L_16 , V_103 ) ;
V_61 = - V_85 ;
goto V_87;
}
V_101 -> V_10 = NULL ;
V_102 [ 1 ] = * V_101 ;
V_102 [ 1 ] . V_107 = L_17 ;
V_104 = F_43 ( V_6 , V_108 ) ;
if ( V_104 < 0 ) {
F_42 ( V_6 , L_18 ) ;
V_61 = - V_109 ;
goto V_87;
}
V_4 = F_44 ( L_19 , V_104 ) ;
if ( ! V_4 ) {
F_42 ( V_6 , L_20 ) ;
V_61 = - V_109 ;
goto V_110;
}
V_4 -> V_51 = V_104 ;
V_4 -> V_6 . V_10 = V_6 ;
V_4 -> V_6 . V_111 = & V_112 ;
V_4 -> V_6 . V_113 = V_112 ;
V_12 -> V_4 [ V_51 ] = V_4 ;
V_61 = F_45 ( V_4 , V_102 , 2 ) ;
if ( V_61 ) {
F_42 ( V_6 , L_21 ) ;
goto V_114;
}
if ( V_96 ) {
V_94 = F_46 ( & V_9 -> V_6 , sizeof( * V_94 ) , V_108 ) ;
if ( ! V_94 ) {
F_42 ( & V_9 -> V_6 ,
L_22 ) ;
V_61 = - V_109 ;
goto V_114;
}
V_99 = F_46 ( & V_9 -> V_6 , sizeof( * V_99 ) , V_108 ) ;
if ( ! V_99 ) {
F_42 ( & V_9 -> V_6 ,
L_23 ) ;
goto V_114;
}
F_47 ( V_96 , L_24 , ( T_3 * ) & V_99 -> V_115 ) ;
F_47 ( V_96 , L_25 , ( T_3 * ) & V_99 -> V_116 ) ;
snprintf ( V_103 , sizeof( V_103 ) , L_26 , V_51 ) ;
F_47 ( V_96 , V_103 , ( T_3 * ) & V_94 -> V_117 ) ;
F_47 ( V_96 , L_27 , ( T_3 * ) & V_94 -> V_118 ) ;
V_99 -> V_119 = F_48 ( V_96 , L_28 ) ;
V_94 -> V_99 = V_99 ;
}
V_94 -> V_120 = & V_121 ;
V_61 = F_49 ( V_4 , V_94 , sizeof( * V_94 ) ) ;
if ( V_61 ) {
F_42 ( V_6 , L_29 ) ;
goto V_114;
}
V_61 = F_50 ( V_4 ) ;
if ( V_61 ) {
F_42 ( V_6 , L_30 ) ;
goto V_114;
}
return 0 ;
V_114:
F_51 ( V_4 ) ;
V_110:
F_52 ( V_6 , V_104 ) ;
V_87:
return V_61 ;
}
static void F_53 ( struct V_11 * V_12 , T_1 V_51 )
{
F_52 ( V_12 -> V_6 , V_12 -> V_4 [ V_51 ] -> V_51 ) ;
F_54 ( V_12 -> V_4 [ V_51 ] ) ;
F_51 ( V_12 -> V_4 [ V_51 ] ) ;
}
static int T_5 F_55 ( struct V_8 * V_9 )
{
struct V_95 * V_96 = V_9 -> V_6 . V_97 ;
const struct V_122 * V_123 ;
const struct V_13 * V_14 ;
struct V_11 * V_12 ;
struct V_100 * V_124 ;
int V_61 , V_125 ;
V_123 = F_56 ( V_126 , V_96 ) ;
if ( ! V_123 ) {
F_42 ( & V_9 -> V_6 , L_31 ) ;
V_61 = - V_127 ;
goto V_87;
}
V_14 = V_123 -> V_3 ;
V_12 = F_57 ( sizeof( * V_12 ) , V_108 ) ;
if ( ! V_12 ) {
F_42 ( & V_9 -> V_6 , L_32 ) ;
V_61 = - V_109 ;
goto V_87;
}
V_124 = F_58 ( V_9 , V_105 , 0 ) ;
if ( ! V_124 ) {
F_42 ( & V_9 -> V_6 , L_33 ) ;
V_61 = - V_85 ;
goto V_110;
}
V_12 -> V_6 = & V_9 -> V_6 ;
V_12 -> V_14 = F_59 ( V_14 , sizeof( * V_14 ) , V_108 ) ;
if ( ! V_12 -> V_14 ) {
F_42 ( & V_9 -> V_6 , L_34 ) ;
V_61 = - V_109 ;
goto V_110;
}
F_60 ( V_9 , V_12 ) ;
F_61 ( & V_9 -> V_6 ) ;
V_61 = F_62 ( & V_9 -> V_6 ) ;
if ( V_61 < 0 ) {
F_42 ( & V_9 -> V_6 , L_35 ) ;
goto V_114;
}
for ( V_125 = 0 ; V_125 < V_14 -> V_128 ; V_125 ++ ) {
V_61 = F_40 ( V_12 , V_125 ) ;
if ( V_61 != 0 ) {
F_42 ( & V_9 -> V_6 , L_36 ) ;
for ( V_125 -- ; V_125 >= 0 ; V_125 -- )
F_53 ( V_12 , V_125 ) ;
goto V_129;
}
}
return 0 ;
V_129:
F_63 ( & V_9 -> V_6 ) ;
V_114:
F_64 ( & V_9 -> V_6 ) ;
F_65 ( V_12 -> V_14 ) ;
V_110:
F_65 ( V_12 ) ;
V_87:
return V_61 ;
}
static int T_6 F_66 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = F_11 ( V_9 ) ;
const struct V_13 * V_14 = V_12 -> V_14 ;
int V_125 ;
for ( V_125 = 0 ; V_125 < V_14 -> V_128 ; V_125 ++ )
F_53 ( V_12 , V_125 ) ;
F_63 ( & V_9 -> V_6 ) ;
F_64 ( & V_9 -> V_6 ) ;
F_65 ( V_12 -> V_14 ) ;
F_65 ( V_12 ) ;
return 0 ;
}
static int F_67 ( struct V_5 * V_6 )
{
struct V_76 * V_77 = V_6 -> V_78 ;
struct V_79 * V_3 = V_77 -> V_80 ;
if ( V_3 -> V_90 )
V_3 -> V_90 ( 0 ) ;
return 0 ;
}
static int F_68 ( struct V_5 * V_6 )
{
struct V_76 * V_77 = V_6 -> V_78 ;
struct V_79 * V_3 = V_77 -> V_80 ;
if ( V_3 -> V_90 )
V_3 -> V_90 ( 1 ) ;
return 0 ;
}
static int T_7 F_69 ( void )
{
return F_70 ( & V_130 ) ;
}
static void T_8 F_71 ( void )
{
F_72 ( & V_130 ) ;
}

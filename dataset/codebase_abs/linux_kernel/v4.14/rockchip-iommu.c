static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_4 )
{
T_2 V_5 = V_4 * sizeof( V_6 ) ;
F_2 ( & V_2 -> V_7 -> V_8 , V_3 , V_5 , V_9 ) ;
}
static struct V_1 * F_3 ( struct V_10 * V_2 )
{
return F_4 ( V_2 , struct V_1 , V_11 ) ;
}
static inline T_3 F_5 ( V_6 V_12 )
{
return ( T_3 ) V_12 & V_13 ;
}
static inline bool F_6 ( V_6 V_12 )
{
return V_12 & V_14 ;
}
static inline V_6 F_7 ( T_1 V_15 )
{
return ( V_15 & V_13 ) | V_14 ;
}
static inline T_3 F_8 ( V_6 V_16 )
{
return ( T_3 ) V_16 & V_17 ;
}
static inline bool F_9 ( V_6 V_16 )
{
return V_16 & V_18 ;
}
static V_6 F_10 ( T_3 V_19 , int V_20 )
{
V_6 V_21 = 0 ;
V_21 |= ( V_20 & V_22 ) ? V_23 : 0 ;
V_21 |= ( V_20 & V_24 ) ? V_25 : 0 ;
V_19 &= V_17 ;
return V_19 | V_21 | V_18 ;
}
static V_6 F_11 ( V_6 V_16 )
{
return V_16 & ~ V_18 ;
}
static V_6 F_12 ( T_1 V_26 )
{
return ( V_6 ) ( V_26 & V_27 ) >> V_28 ;
}
static V_6 F_13 ( T_1 V_26 )
{
return ( V_6 ) ( V_26 & V_29 ) >> V_30 ;
}
static V_6 F_14 ( T_1 V_26 )
{
return ( V_6 ) ( V_26 & V_31 ) >> V_32 ;
}
static V_6 F_15 ( void T_4 * V_33 , V_6 V_34 )
{
return F_16 ( V_33 + V_34 ) ;
}
static void F_17 ( void T_4 * V_33 , V_6 V_34 , V_6 V_35 )
{
F_18 ( V_35 , V_33 + V_34 ) ;
}
static void F_19 ( struct V_36 * V_37 , V_6 V_38 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_37 -> V_40 ; V_39 ++ )
F_18 ( V_38 , V_37 -> V_41 [ V_39 ] + V_42 ) ;
}
static void F_20 ( void T_4 * V_33 , V_6 V_38 )
{
F_18 ( V_38 , V_33 + V_42 ) ;
}
static void F_21 ( struct V_36 * V_37 , T_1 V_26 ,
T_2 V_5 )
{
int V_39 ;
T_1 V_43 = V_26 + V_5 ;
for ( V_39 = 0 ; V_39 < V_37 -> V_40 ; V_39 ++ )
for (; V_26 < V_43 ; V_26 += V_44 )
F_17 ( V_37 -> V_41 [ V_39 ] , V_45 , V_26 ) ;
}
static bool F_22 ( struct V_36 * V_37 )
{
bool V_46 = true ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_37 -> V_40 ; V_39 ++ )
V_46 &= ! ! ( F_15 ( V_37 -> V_41 [ V_39 ] , V_47 ) &
V_48 ) ;
return V_46 ;
}
static bool F_23 ( struct V_36 * V_37 )
{
bool V_49 = true ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_37 -> V_40 ; V_39 ++ )
V_49 &= ! ! ( F_15 ( V_37 -> V_41 [ V_39 ] , V_47 ) &
V_50 ) ;
return V_49 ;
}
static int F_24 ( struct V_36 * V_37 )
{
int V_51 , V_39 ;
if ( F_22 ( V_37 ) )
return 0 ;
if ( ! F_23 ( V_37 ) )
return 0 ;
F_19 ( V_37 , V_52 ) ;
V_51 = F_25 ( F_22 ( V_37 ) , 1 ) ;
if ( V_51 )
for ( V_39 = 0 ; V_39 < V_37 -> V_40 ; V_39 ++ )
F_26 ( V_37 -> V_8 , L_1 ,
F_15 ( V_37 -> V_41 [ V_39 ] , V_47 ) ) ;
return V_51 ;
}
static int F_27 ( struct V_36 * V_37 )
{
int V_51 , V_39 ;
if ( ! F_22 ( V_37 ) )
return 0 ;
F_19 ( V_37 , V_53 ) ;
V_51 = F_25 ( ! F_22 ( V_37 ) , 1 ) ;
if ( V_51 )
for ( V_39 = 0 ; V_39 < V_37 -> V_40 ; V_39 ++ )
F_26 ( V_37 -> V_8 , L_2 ,
F_15 ( V_37 -> V_41 [ V_39 ] , V_47 ) ) ;
return V_51 ;
}
static int F_28 ( struct V_36 * V_37 )
{
int V_51 , V_39 ;
if ( F_23 ( V_37 ) )
return 0 ;
F_19 ( V_37 , V_54 ) ;
V_51 = F_25 ( F_23 ( V_37 ) , 1 ) ;
if ( V_51 )
for ( V_39 = 0 ; V_39 < V_37 -> V_40 ; V_39 ++ )
F_26 ( V_37 -> V_8 , L_3 ,
F_15 ( V_37 -> V_41 [ V_39 ] , V_47 ) ) ;
return V_51 ;
}
static int F_29 ( struct V_36 * V_37 )
{
int V_51 , V_39 ;
if ( ! F_23 ( V_37 ) )
return 0 ;
F_19 ( V_37 , V_55 ) ;
V_51 = F_25 ( ! F_23 ( V_37 ) , 1 ) ;
if ( V_51 )
for ( V_39 = 0 ; V_39 < V_37 -> V_40 ; V_39 ++ )
F_26 ( V_37 -> V_8 , L_4 ,
F_15 ( V_37 -> V_41 [ V_39 ] , V_47 ) ) ;
return V_51 ;
}
static int F_30 ( struct V_36 * V_37 )
{
int V_51 , V_39 ;
V_6 V_56 ;
if ( V_37 -> V_57 )
return 0 ;
for ( V_39 = 0 ; V_39 < V_37 -> V_40 ; V_39 ++ ) {
F_17 ( V_37 -> V_41 [ V_39 ] , V_58 , V_59 ) ;
V_56 = F_15 ( V_37 -> V_41 [ V_39 ] , V_58 ) ;
if ( V_56 != ( V_59 & V_13 ) ) {
F_26 ( V_37 -> V_8 , L_5 ) ;
return - V_60 ;
}
}
F_19 ( V_37 , V_61 ) ;
for ( V_39 = 0 ; V_39 < V_37 -> V_40 ; V_39 ++ ) {
V_51 = F_25 ( F_15 ( V_37 -> V_41 [ V_39 ] , V_58 ) == 0x00000000 ,
V_62 ) ;
if ( V_51 ) {
F_26 ( V_37 -> V_8 , L_6 ) ;
return V_51 ;
}
}
return 0 ;
}
static void F_31 ( struct V_36 * V_37 , int V_63 , T_1 V_26 )
{
void T_4 * V_33 = V_37 -> V_41 [ V_63 ] ;
V_6 V_64 , V_65 , V_66 ;
V_6 V_67 ;
T_3 V_68 , V_69 ;
V_6 * V_56 ;
V_6 V_12 ;
T_3 V_70 = 0 ;
V_6 * V_71 = NULL ;
V_6 V_16 = 0 ;
T_3 V_72 = 0 ;
V_6 V_73 = 0 ;
V_64 = F_12 ( V_26 ) ;
V_65 = F_13 ( V_26 ) ;
V_66 = F_14 ( V_26 ) ;
V_67 = F_15 ( V_33 , V_58 ) ;
V_68 = ( T_3 ) V_67 ;
V_69 = V_68 + ( 4 * V_64 ) ;
V_56 = F_32 ( V_69 ) ;
V_12 = * V_56 ;
if ( ! F_6 ( V_12 ) )
goto V_74;
V_70 = F_5 ( V_12 ) + ( V_65 * 4 ) ;
V_71 = F_32 ( V_70 ) ;
V_16 = * V_71 ;
if ( ! F_9 ( V_16 ) )
goto V_74;
V_72 = F_8 ( V_16 ) + V_66 ;
V_73 = V_16 & V_75 ;
V_74:
F_26 ( V_37 -> V_8 , L_7 ,
& V_26 , V_64 , V_65 , V_66 ) ;
F_26 ( V_37 -> V_8 , L_8 ,
& V_68 , & V_69 , V_12 ,
F_6 ( V_12 ) , & V_70 , V_16 ,
F_9 ( V_16 ) , & V_72 , V_73 ) ;
}
static T_5 F_33 ( int V_76 , void * V_77 )
{
struct V_36 * V_37 = V_77 ;
V_6 V_78 ;
V_6 V_79 ;
T_1 V_26 ;
T_5 V_51 = V_80 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_37 -> V_40 ; V_39 ++ ) {
V_79 = F_15 ( V_37 -> V_41 [ V_39 ] , V_81 ) ;
if ( V_79 == 0 )
continue;
V_51 = V_82 ;
V_26 = F_15 ( V_37 -> V_41 [ V_39 ] , V_83 ) ;
if ( V_79 & V_84 ) {
int V_21 ;
V_78 = F_15 ( V_37 -> V_41 [ V_39 ] , V_47 ) ;
V_21 = ( V_78 & V_85 ) ?
V_86 : V_87 ;
F_26 ( V_37 -> V_8 , L_9 ,
& V_26 ,
( V_21 == V_86 ) ? L_10 : L_11 ) ;
F_31 ( V_37 , V_39 , V_26 ) ;
if ( V_37 -> V_11 )
F_34 ( V_37 -> V_11 , V_37 -> V_8 , V_26 ,
V_21 ) ;
else
F_26 ( V_37 -> V_8 , L_12 ) ;
F_20 ( V_37 -> V_41 [ V_39 ] , V_88 ) ;
F_20 ( V_37 -> V_41 [ V_39 ] , V_89 ) ;
}
if ( V_79 & V_90 )
F_26 ( V_37 -> V_8 , L_13 , & V_26 ) ;
if ( V_79 & ~ V_91 )
F_26 ( V_37 -> V_8 , L_14 ,
V_79 ) ;
F_17 ( V_37 -> V_41 [ V_39 ] , V_92 , V_79 ) ;
}
return V_51 ;
}
static T_3 F_35 ( struct V_10 * V_11 ,
T_1 V_26 )
{
struct V_1 * V_93 = F_3 ( V_11 ) ;
unsigned long V_21 ;
T_3 V_94 , V_95 = 0 ;
V_6 V_12 , V_16 ;
V_6 * V_96 ;
F_36 ( & V_93 -> V_97 , V_21 ) ;
V_12 = V_93 -> V_98 [ F_12 ( V_26 ) ] ;
if ( ! F_6 ( V_12 ) )
goto V_99;
V_94 = F_5 ( V_12 ) ;
V_96 = ( V_6 * ) F_32 ( V_94 ) ;
V_16 = V_96 [ F_13 ( V_26 ) ] ;
if ( ! F_9 ( V_16 ) )
goto V_99;
V_95 = F_8 ( V_16 ) + F_14 ( V_26 ) ;
V_99:
F_37 ( & V_93 -> V_97 , V_21 ) ;
return V_95 ;
}
static void F_38 ( struct V_1 * V_93 ,
T_1 V_26 , T_2 V_5 )
{
struct V_100 * V_101 ;
unsigned long V_21 ;
F_36 ( & V_93 -> V_102 , V_21 ) ;
F_39 (pos, &rk_domain->iommus) {
struct V_36 * V_37 ;
V_37 = F_40 ( V_101 , struct V_36 , V_103 ) ;
F_21 ( V_37 , V_26 , V_5 ) ;
}
F_37 ( & V_93 -> V_102 , V_21 ) ;
}
static void F_41 ( struct V_1 * V_93 ,
T_1 V_26 , T_2 V_5 )
{
F_38 ( V_93 , V_26 , V_44 ) ;
if ( V_5 > V_44 )
F_38 ( V_93 , V_26 + V_5 - V_44 ,
V_44 ) ;
}
static V_6 * F_42 ( struct V_1 * V_93 ,
T_1 V_26 )
{
struct V_104 * V_8 = & V_93 -> V_7 -> V_8 ;
V_6 * V_96 , * V_56 ;
V_6 V_64 , V_12 ;
T_3 V_94 ;
T_1 V_15 ;
F_43 ( & V_93 -> V_97 ) ;
V_64 = F_12 ( V_26 ) ;
V_56 = & V_93 -> V_98 [ V_64 ] ;
V_12 = * V_56 ;
if ( F_6 ( V_12 ) )
goto V_105;
V_96 = ( V_6 * ) F_44 ( V_106 | V_107 ) ;
if ( ! V_96 )
return F_45 ( - V_108 ) ;
V_15 = F_46 ( V_8 , V_96 , V_44 , V_9 ) ;
if ( F_47 ( V_8 , V_15 ) ) {
F_26 ( V_8 , L_15 ) ;
F_48 ( ( unsigned long ) V_96 ) ;
return F_45 ( - V_108 ) ;
}
V_12 = F_7 ( V_15 ) ;
* V_56 = V_12 ;
F_1 ( V_93 , V_15 , V_109 ) ;
F_1 ( V_93 ,
V_93 -> V_110 + V_64 * sizeof( V_6 ) , 1 ) ;
V_105:
V_94 = F_5 ( V_12 ) ;
return ( V_6 * ) F_32 ( V_94 ) ;
}
static T_2 F_49 ( struct V_1 * V_93 ,
V_6 * V_71 , T_1 V_111 ,
T_2 V_5 )
{
unsigned int V_112 ;
unsigned int V_113 = V_5 / V_44 ;
F_43 ( & V_93 -> V_97 ) ;
for ( V_112 = 0 ; V_112 < V_113 ; V_112 ++ ) {
V_6 V_16 = V_71 [ V_112 ] ;
if ( ! F_9 ( V_16 ) )
break;
V_71 [ V_112 ] = F_11 ( V_16 ) ;
}
F_1 ( V_93 , V_111 , V_112 ) ;
return V_112 * V_44 ;
}
static int F_50 ( struct V_1 * V_93 , V_6 * V_71 ,
T_1 V_111 , T_1 V_26 ,
T_3 V_114 , T_2 V_5 , int V_20 )
{
unsigned int V_112 ;
unsigned int V_113 = V_5 / V_44 ;
T_3 V_115 ;
F_43 ( & V_93 -> V_97 ) ;
for ( V_112 = 0 ; V_112 < V_113 ; V_112 ++ ) {
V_6 V_16 = V_71 [ V_112 ] ;
if ( F_9 ( V_16 ) )
goto V_116;
V_71 [ V_112 ] = F_10 ( V_114 , V_20 ) ;
V_114 += V_44 ;
}
F_1 ( V_93 , V_111 , V_113 ) ;
F_41 ( V_93 , V_26 , V_5 ) ;
return 0 ;
V_116:
F_49 ( V_93 , V_71 , V_111 ,
V_112 * V_44 ) ;
V_26 += V_112 * V_44 ;
V_115 = F_8 ( V_71 [ V_112 ] ) ;
F_51 ( L_16 ,
& V_26 , & V_115 , & V_114 , V_20 ) ;
return - V_117 ;
}
static int F_52 ( struct V_10 * V_11 , unsigned long V_118 ,
T_3 V_114 , T_2 V_5 , int V_20 )
{
struct V_1 * V_93 = F_3 ( V_11 ) ;
unsigned long V_21 ;
T_1 V_111 , V_26 = ( T_1 ) V_118 ;
V_6 * V_96 , * V_71 ;
V_6 V_64 , V_65 ;
int V_51 ;
F_36 ( & V_93 -> V_97 , V_21 ) ;
V_96 = F_42 ( V_93 , V_26 ) ;
if ( F_53 ( V_96 ) ) {
F_37 ( & V_93 -> V_97 , V_21 ) ;
return F_54 ( V_96 ) ;
}
V_64 = V_93 -> V_98 [ F_12 ( V_26 ) ] ;
V_65 = F_13 ( V_26 ) ;
V_71 = & V_96 [ V_65 ] ;
V_111 = F_5 ( V_64 ) + V_65 * sizeof( V_6 ) ;
V_51 = F_50 ( V_93 , V_71 , V_111 , V_26 ,
V_114 , V_5 , V_20 ) ;
F_37 ( & V_93 -> V_97 , V_21 ) ;
return V_51 ;
}
static T_2 F_55 ( struct V_10 * V_11 , unsigned long V_118 ,
T_2 V_5 )
{
struct V_1 * V_93 = F_3 ( V_11 ) ;
unsigned long V_21 ;
T_1 V_111 , V_26 = ( T_1 ) V_118 ;
T_3 V_94 ;
V_6 V_12 ;
V_6 * V_71 ;
T_2 V_119 ;
F_36 ( & V_93 -> V_97 , V_21 ) ;
V_12 = V_93 -> V_98 [ F_12 ( V_26 ) ] ;
if ( ! F_6 ( V_12 ) ) {
F_37 ( & V_93 -> V_97 , V_21 ) ;
return 0 ;
}
V_94 = F_5 ( V_12 ) ;
V_71 = ( V_6 * ) F_32 ( V_94 ) + F_13 ( V_26 ) ;
V_111 = V_94 + F_13 ( V_26 ) * sizeof( V_6 ) ;
V_119 = F_49 ( V_93 , V_71 , V_111 , V_5 ) ;
F_37 ( & V_93 -> V_97 , V_21 ) ;
F_38 ( V_93 , V_26 , V_119 ) ;
return V_119 ;
}
static struct V_36 * F_56 ( struct V_104 * V_8 )
{
struct V_120 * V_121 ;
struct V_104 * V_122 ;
struct V_36 * V_36 ;
V_121 = F_57 ( V_8 ) ;
if ( ! V_121 )
return NULL ;
V_122 = F_58 ( V_121 ) ;
V_36 = F_59 ( V_122 ) ;
F_60 ( V_121 ) ;
return V_36 ;
}
static int F_61 ( struct V_10 * V_11 ,
struct V_104 * V_8 )
{
struct V_36 * V_37 ;
struct V_1 * V_93 = F_3 ( V_11 ) ;
unsigned long V_21 ;
int V_51 , V_39 ;
V_37 = F_56 ( V_8 ) ;
if ( ! V_37 )
return 0 ;
V_51 = F_24 ( V_37 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_30 ( V_37 ) ;
if ( V_51 )
return V_51 ;
V_37 -> V_11 = V_11 ;
for ( V_39 = 0 ; V_39 < V_37 -> V_123 ; V_39 ++ ) {
V_51 = F_62 ( V_37 -> V_8 , V_37 -> V_76 [ V_39 ] , F_33 ,
V_124 , F_63 ( V_8 ) , V_37 ) ;
if ( V_51 )
return V_51 ;
}
for ( V_39 = 0 ; V_39 < V_37 -> V_40 ; V_39 ++ ) {
F_17 ( V_37 -> V_41 [ V_39 ] , V_58 ,
V_93 -> V_110 ) ;
F_20 ( V_37 -> V_41 [ V_39 ] , V_88 ) ;
F_17 ( V_37 -> V_41 [ V_39 ] , V_125 , V_91 ) ;
}
V_51 = F_28 ( V_37 ) ;
if ( V_51 )
return V_51 ;
F_36 ( & V_93 -> V_102 , V_21 ) ;
F_64 ( & V_37 -> V_103 , & V_93 -> V_126 ) ;
F_37 ( & V_93 -> V_102 , V_21 ) ;
F_65 ( V_8 , L_17 ) ;
F_27 ( V_37 ) ;
return 0 ;
}
static void F_66 ( struct V_10 * V_11 ,
struct V_104 * V_8 )
{
struct V_36 * V_37 ;
struct V_1 * V_93 = F_3 ( V_11 ) ;
unsigned long V_21 ;
int V_39 ;
V_37 = F_56 ( V_8 ) ;
if ( ! V_37 )
return;
F_36 ( & V_93 -> V_102 , V_21 ) ;
F_67 ( & V_37 -> V_103 ) ;
F_37 ( & V_93 -> V_102 , V_21 ) ;
F_24 ( V_37 ) ;
F_29 ( V_37 ) ;
for ( V_39 = 0 ; V_39 < V_37 -> V_40 ; V_39 ++ ) {
F_17 ( V_37 -> V_41 [ V_39 ] , V_125 , 0 ) ;
F_17 ( V_37 -> V_41 [ V_39 ] , V_58 , 0 ) ;
}
F_27 ( V_37 ) ;
for ( V_39 = 0 ; V_39 < V_37 -> V_123 ; V_39 ++ )
F_68 ( V_37 -> V_8 , V_37 -> V_76 [ V_39 ] , V_37 ) ;
V_37 -> V_11 = NULL ;
F_65 ( V_8 , L_18 ) ;
}
static struct V_10 * F_69 ( unsigned type )
{
struct V_1 * V_93 ;
struct V_127 * V_7 ;
struct V_104 * V_122 ;
if ( type != V_128 && type != V_129 )
return NULL ;
V_7 = F_70 ( L_19 ,
V_130 , NULL , 0 ) ;
if ( F_53 ( V_7 ) )
return NULL ;
V_93 = F_71 ( & V_7 -> V_8 , sizeof( * V_93 ) , V_131 ) ;
if ( ! V_93 )
goto V_132;
V_93 -> V_7 = V_7 ;
if ( type == V_129 &&
F_72 ( & V_93 -> V_11 ) )
goto V_132;
V_93 -> V_98 = ( V_6 * ) F_44 ( V_131 | V_107 ) ;
if ( ! V_93 -> V_98 )
goto V_133;
V_122 = & V_7 -> V_8 ;
V_93 -> V_110 = F_46 ( V_122 , V_93 -> V_98 ,
V_44 , V_9 ) ;
if ( F_47 ( V_122 , V_93 -> V_110 ) ) {
F_26 ( V_122 , L_20 ) ;
goto V_134;
}
F_1 ( V_93 , V_93 -> V_110 , V_135 ) ;
F_73 ( & V_93 -> V_102 ) ;
F_73 ( & V_93 -> V_97 ) ;
F_74 ( & V_93 -> V_126 ) ;
V_93 -> V_11 . V_136 . V_137 = 0 ;
V_93 -> V_11 . V_136 . V_138 = F_75 ( 32 ) ;
V_93 -> V_11 . V_136 . V_139 = true ;
return & V_93 -> V_11 ;
V_134:
F_48 ( ( unsigned long ) V_93 -> V_98 ) ;
V_133:
if ( type == V_129 )
F_76 ( & V_93 -> V_11 ) ;
V_132:
F_77 ( V_7 ) ;
return NULL ;
}
static void F_78 ( struct V_10 * V_11 )
{
struct V_1 * V_93 = F_3 ( V_11 ) ;
int V_39 ;
F_79 ( ! F_80 ( & V_93 -> V_126 ) ) ;
for ( V_39 = 0 ; V_39 < V_135 ; V_39 ++ ) {
V_6 V_12 = V_93 -> V_98 [ V_39 ] ;
if ( F_6 ( V_12 ) ) {
T_3 V_94 = F_5 ( V_12 ) ;
V_6 * V_96 = F_32 ( V_94 ) ;
F_81 ( & V_93 -> V_7 -> V_8 , V_94 ,
V_44 , V_9 ) ;
F_48 ( ( unsigned long ) V_96 ) ;
}
}
F_81 ( & V_93 -> V_7 -> V_8 , V_93 -> V_110 ,
V_44 , V_9 ) ;
F_48 ( ( unsigned long ) V_93 -> V_98 ) ;
if ( V_11 -> type == V_129 )
F_76 ( & V_93 -> V_11 ) ;
F_77 ( V_93 -> V_7 ) ;
}
static bool F_82 ( struct V_104 * V_8 )
{
struct V_140 * V_141 = V_8 -> V_142 ;
int V_51 ;
V_51 = F_83 ( V_141 , L_21 , L_22 ) ;
return ( V_51 > 0 ) ;
}
static int F_84 ( struct V_120 * V_121 ,
struct V_104 * V_8 )
{
struct V_140 * V_141 = V_8 -> V_142 ;
struct V_127 * V_143 ;
int V_51 ;
struct V_144 args ;
V_51 = F_85 ( V_141 , L_21 , L_22 , 0 ,
& args ) ;
if ( V_51 ) {
F_26 ( V_8 , L_23 ,
V_141 , V_51 ) ;
return V_51 ;
}
if ( args . V_145 != 0 ) {
F_26 ( V_8 , L_24 ,
args . V_141 , args . V_145 ) ;
return - V_146 ;
}
V_143 = F_86 ( args . V_141 ) ;
F_87 ( args . V_141 ) ;
if ( ! V_143 ) {
F_26 ( V_8 , L_25 , args . V_141 ) ;
return - V_147 ;
}
F_88 ( V_121 , & V_143 -> V_8 , NULL ) ;
return 0 ;
}
static int F_89 ( struct V_104 * V_8 )
{
struct V_120 * V_121 ;
struct V_36 * V_37 ;
int V_51 ;
if ( ! F_82 ( V_8 ) )
return - V_148 ;
V_121 = F_57 ( V_8 ) ;
if ( ! V_121 ) {
V_121 = F_90 () ;
if ( F_53 ( V_121 ) ) {
F_26 ( V_8 , L_26 ) ;
return F_54 ( V_121 ) ;
}
}
V_51 = F_91 ( V_121 , V_8 ) ;
if ( V_51 )
goto V_149;
V_51 = F_84 ( V_121 , V_8 ) ;
if ( V_51 )
goto V_150;
V_37 = F_56 ( V_8 ) ;
if ( V_37 )
F_92 ( & V_37 -> V_37 , V_8 ) ;
F_60 ( V_121 ) ;
return 0 ;
V_150:
F_93 ( V_8 ) ;
V_149:
F_60 ( V_121 ) ;
return V_51 ;
}
static void F_94 ( struct V_104 * V_8 )
{
struct V_36 * V_37 ;
if ( ! F_82 ( V_8 ) )
return;
V_37 = F_56 ( V_8 ) ;
if ( V_37 )
F_95 ( & V_37 -> V_37 , V_8 ) ;
F_93 ( V_8 ) ;
}
static int F_96 ( struct V_127 * V_7 )
{
struct V_104 * V_8 = & V_7 -> V_8 ;
V_8 -> V_151 = F_71 ( V_8 , sizeof( * V_8 -> V_151 ) , V_131 ) ;
if ( ! V_8 -> V_151 )
return - V_108 ;
F_97 ( V_8 , 0 , F_75 ( 32 ) , NULL , false ) ;
F_98 ( V_8 , F_75 ( 32 ) ) ;
F_99 ( V_8 , F_75 ( 32 ) ) ;
return 0 ;
}
static int F_100 ( struct V_127 * V_7 )
{
struct V_104 * V_8 = & V_7 -> V_8 ;
struct V_36 * V_37 ;
struct V_152 * V_153 ;
int V_154 = V_7 -> V_155 ;
int V_156 , V_39 ;
V_37 = F_71 ( V_8 , sizeof( * V_37 ) , V_131 ) ;
if ( ! V_37 )
return - V_108 ;
F_101 ( V_7 , V_37 ) ;
V_37 -> V_8 = V_8 ;
V_37 -> V_40 = 0 ;
V_37 -> V_41 = F_71 ( V_8 , sizeof( * V_37 -> V_41 ) * V_154 ,
V_131 ) ;
if ( ! V_37 -> V_41 )
return - V_108 ;
for ( V_39 = 0 ; V_39 < V_154 ; V_39 ++ ) {
V_153 = F_102 ( V_7 , V_157 , V_39 ) ;
if ( ! V_153 )
continue;
V_37 -> V_41 [ V_39 ] = F_103 ( & V_7 -> V_8 , V_153 ) ;
if ( F_53 ( V_37 -> V_41 [ V_39 ] ) )
continue;
V_37 -> V_40 ++ ;
}
if ( V_37 -> V_40 == 0 )
return F_54 ( V_37 -> V_41 [ 0 ] ) ;
V_37 -> V_123 = F_104 ( V_7 ) ;
if ( V_37 -> V_123 < 0 )
return V_37 -> V_123 ;
if ( V_37 -> V_123 == 0 )
return - V_158 ;
V_37 -> V_76 = F_105 ( V_8 , V_37 -> V_123 , sizeof( * V_37 -> V_76 ) ,
V_131 ) ;
if ( ! V_37 -> V_76 )
return - V_108 ;
for ( V_39 = 0 ; V_39 < V_37 -> V_123 ; V_39 ++ ) {
V_37 -> V_76 [ V_39 ] = F_106 ( V_7 , V_39 ) ;
if ( V_37 -> V_76 [ V_39 ] < 0 ) {
F_26 ( V_8 , L_27 , V_37 -> V_76 [ V_39 ] ) ;
return - V_158 ;
}
}
V_37 -> V_57 = F_107 ( V_8 ,
L_28 ) ;
V_156 = F_108 ( & V_37 -> V_37 , V_8 , NULL , F_63 ( V_8 ) ) ;
if ( V_156 )
return V_156 ;
F_109 ( & V_37 -> V_37 , & V_159 ) ;
V_156 = F_110 ( & V_37 -> V_37 ) ;
return V_156 ;
}
static int F_111 ( struct V_127 * V_7 )
{
struct V_36 * V_37 = F_112 ( V_7 ) ;
if ( V_37 ) {
F_113 ( & V_37 -> V_37 ) ;
F_114 ( & V_37 -> V_37 ) ;
}
return 0 ;
}
static int T_6 F_115 ( void )
{
struct V_140 * V_141 ;
int V_51 ;
V_141 = F_116 ( NULL , V_160 ) ;
if ( ! V_141 )
return 0 ;
F_87 ( V_141 ) ;
V_51 = F_117 ( & V_161 , & V_159 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_118 ( & V_162 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_118 ( & V_163 ) ;
if ( V_51 )
F_119 ( & V_162 ) ;
return V_51 ;
}
static void T_7 F_120 ( void )
{
F_119 ( & V_163 ) ;
F_119 ( & V_162 ) ;
}

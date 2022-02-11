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
for ( V_39 = 0 ; V_39 < V_37 -> V_40 ; V_39 ++ ) {
F_17 ( V_37 -> V_41 [ V_39 ] , V_57 , V_58 ) ;
V_56 = F_15 ( V_37 -> V_41 [ V_39 ] , V_57 ) ;
if ( V_56 != ( V_58 & V_13 ) ) {
F_26 ( V_37 -> V_8 , L_5 ) ;
return - V_59 ;
}
}
F_19 ( V_37 , V_60 ) ;
for ( V_39 = 0 ; V_39 < V_37 -> V_40 ; V_39 ++ ) {
V_51 = F_25 ( F_15 ( V_37 -> V_41 [ V_39 ] , V_57 ) == 0x00000000 ,
V_61 ) ;
if ( V_51 ) {
F_26 ( V_37 -> V_8 , L_6 ) ;
return V_51 ;
}
}
return 0 ;
}
static void F_31 ( struct V_36 * V_37 , int V_62 , T_1 V_26 )
{
void T_4 * V_33 = V_37 -> V_41 [ V_62 ] ;
V_6 V_63 , V_64 , V_65 ;
V_6 V_66 ;
T_3 V_67 , V_68 ;
V_6 * V_56 ;
V_6 V_12 ;
T_3 V_69 = 0 ;
V_6 * V_70 = NULL ;
V_6 V_16 = 0 ;
T_3 V_71 = 0 ;
V_6 V_72 = 0 ;
V_63 = F_12 ( V_26 ) ;
V_64 = F_13 ( V_26 ) ;
V_65 = F_14 ( V_26 ) ;
V_66 = F_15 ( V_33 , V_57 ) ;
V_67 = ( T_3 ) V_66 ;
V_68 = V_67 + ( 4 * V_63 ) ;
V_56 = F_32 ( V_68 ) ;
V_12 = * V_56 ;
if ( ! F_6 ( V_12 ) )
goto V_73;
V_69 = F_5 ( V_12 ) + ( V_64 * 4 ) ;
V_70 = F_32 ( V_69 ) ;
V_16 = * V_70 ;
if ( ! F_9 ( V_16 ) )
goto V_73;
V_71 = F_8 ( V_16 ) + V_65 ;
V_72 = V_16 & V_74 ;
V_73:
F_26 ( V_37 -> V_8 , L_7 ,
& V_26 , V_63 , V_64 , V_65 ) ;
F_26 ( V_37 -> V_8 , L_8 ,
& V_67 , & V_68 , V_12 ,
F_6 ( V_12 ) , & V_69 , V_16 ,
F_9 ( V_16 ) , & V_71 , V_72 ) ;
}
static T_5 F_33 ( int V_75 , void * V_76 )
{
struct V_36 * V_37 = V_76 ;
V_6 V_77 ;
V_6 V_78 ;
T_1 V_26 ;
T_5 V_51 = V_79 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_37 -> V_40 ; V_39 ++ ) {
V_78 = F_15 ( V_37 -> V_41 [ V_39 ] , V_80 ) ;
if ( V_78 == 0 )
continue;
V_51 = V_81 ;
V_26 = F_15 ( V_37 -> V_41 [ V_39 ] , V_82 ) ;
if ( V_78 & V_83 ) {
int V_21 ;
V_77 = F_15 ( V_37 -> V_41 [ V_39 ] , V_47 ) ;
V_21 = ( V_77 & V_84 ) ?
V_85 : V_86 ;
F_26 ( V_37 -> V_8 , L_9 ,
& V_26 ,
( V_21 == V_85 ) ? L_10 : L_11 ) ;
F_31 ( V_37 , V_39 , V_26 ) ;
if ( V_37 -> V_11 )
F_34 ( V_37 -> V_11 , V_37 -> V_8 , V_26 ,
V_21 ) ;
else
F_26 ( V_37 -> V_8 , L_12 ) ;
F_20 ( V_37 -> V_41 [ V_39 ] , V_87 ) ;
F_20 ( V_37 -> V_41 [ V_39 ] , V_88 ) ;
}
if ( V_78 & V_89 )
F_26 ( V_37 -> V_8 , L_13 , & V_26 ) ;
if ( V_78 & ~ V_90 )
F_26 ( V_37 -> V_8 , L_14 ,
V_78 ) ;
F_17 ( V_37 -> V_41 [ V_39 ] , V_91 , V_78 ) ;
}
return V_51 ;
}
static T_3 F_35 ( struct V_10 * V_11 ,
T_1 V_26 )
{
struct V_1 * V_92 = F_3 ( V_11 ) ;
unsigned long V_21 ;
T_3 V_93 , V_94 = 0 ;
V_6 V_12 , V_16 ;
V_6 * V_95 ;
F_36 ( & V_92 -> V_96 , V_21 ) ;
V_12 = V_92 -> V_97 [ F_12 ( V_26 ) ] ;
if ( ! F_6 ( V_12 ) )
goto V_98;
V_93 = F_5 ( V_12 ) ;
V_95 = ( V_6 * ) F_32 ( V_93 ) ;
V_16 = V_95 [ F_13 ( V_26 ) ] ;
if ( ! F_9 ( V_16 ) )
goto V_98;
V_94 = F_8 ( V_16 ) + F_14 ( V_26 ) ;
V_98:
F_37 ( & V_92 -> V_96 , V_21 ) ;
return V_94 ;
}
static void F_38 ( struct V_1 * V_92 ,
T_1 V_26 , T_2 V_5 )
{
struct V_99 * V_100 ;
unsigned long V_21 ;
F_36 ( & V_92 -> V_101 , V_21 ) ;
F_39 (pos, &rk_domain->iommus) {
struct V_36 * V_37 ;
V_37 = F_40 ( V_100 , struct V_36 , V_102 ) ;
F_21 ( V_37 , V_26 , V_5 ) ;
}
F_37 ( & V_92 -> V_101 , V_21 ) ;
}
static void F_41 ( struct V_1 * V_92 ,
T_1 V_26 , T_2 V_5 )
{
F_38 ( V_92 , V_26 , V_44 ) ;
if ( V_5 > V_44 )
F_38 ( V_92 , V_26 + V_5 - V_44 ,
V_44 ) ;
}
static V_6 * F_42 ( struct V_1 * V_92 ,
T_1 V_26 )
{
struct V_103 * V_8 = & V_92 -> V_7 -> V_8 ;
V_6 * V_95 , * V_56 ;
V_6 V_63 , V_12 ;
T_3 V_93 ;
T_1 V_15 ;
F_43 ( & V_92 -> V_96 ) ;
V_63 = F_12 ( V_26 ) ;
V_56 = & V_92 -> V_97 [ V_63 ] ;
V_12 = * V_56 ;
if ( F_6 ( V_12 ) )
goto V_104;
V_95 = ( V_6 * ) F_44 ( V_105 | V_106 ) ;
if ( ! V_95 )
return F_45 ( - V_107 ) ;
V_15 = F_46 ( V_8 , V_95 , V_44 , V_9 ) ;
if ( F_47 ( V_8 , V_15 ) ) {
F_26 ( V_8 , L_15 ) ;
F_48 ( ( unsigned long ) V_95 ) ;
return F_45 ( - V_107 ) ;
}
V_12 = F_7 ( V_15 ) ;
* V_56 = V_12 ;
F_1 ( V_92 , V_15 , V_108 ) ;
F_1 ( V_92 ,
V_92 -> V_109 + V_63 * sizeof( V_6 ) , 1 ) ;
V_104:
V_93 = F_5 ( V_12 ) ;
return ( V_6 * ) F_32 ( V_93 ) ;
}
static T_2 F_49 ( struct V_1 * V_92 ,
V_6 * V_70 , T_1 V_110 ,
T_2 V_5 )
{
unsigned int V_111 ;
unsigned int V_112 = V_5 / V_44 ;
F_43 ( & V_92 -> V_96 ) ;
for ( V_111 = 0 ; V_111 < V_112 ; V_111 ++ ) {
V_6 V_16 = V_70 [ V_111 ] ;
if ( ! F_9 ( V_16 ) )
break;
V_70 [ V_111 ] = F_11 ( V_16 ) ;
}
F_1 ( V_92 , V_110 , V_111 ) ;
return V_111 * V_44 ;
}
static int F_50 ( struct V_1 * V_92 , V_6 * V_70 ,
T_1 V_110 , T_1 V_26 ,
T_3 V_113 , T_2 V_5 , int V_20 )
{
unsigned int V_111 ;
unsigned int V_112 = V_5 / V_44 ;
T_3 V_114 ;
F_43 ( & V_92 -> V_96 ) ;
for ( V_111 = 0 ; V_111 < V_112 ; V_111 ++ ) {
V_6 V_16 = V_70 [ V_111 ] ;
if ( F_9 ( V_16 ) )
goto V_115;
V_70 [ V_111 ] = F_10 ( V_113 , V_20 ) ;
V_113 += V_44 ;
}
F_1 ( V_92 , V_110 , V_112 ) ;
F_41 ( V_92 , V_26 , V_5 ) ;
return 0 ;
V_115:
F_49 ( V_92 , V_70 , V_110 ,
V_111 * V_44 ) ;
V_26 += V_111 * V_44 ;
V_114 = F_8 ( V_70 [ V_111 ] ) ;
F_51 ( L_16 ,
& V_26 , & V_114 , & V_113 , V_20 ) ;
return - V_116 ;
}
static int F_52 ( struct V_10 * V_11 , unsigned long V_117 ,
T_3 V_113 , T_2 V_5 , int V_20 )
{
struct V_1 * V_92 = F_3 ( V_11 ) ;
unsigned long V_21 ;
T_1 V_110 , V_26 = ( T_1 ) V_117 ;
V_6 * V_95 , * V_70 ;
V_6 V_63 , V_64 ;
int V_51 ;
F_36 ( & V_92 -> V_96 , V_21 ) ;
V_95 = F_42 ( V_92 , V_26 ) ;
if ( F_53 ( V_95 ) ) {
F_37 ( & V_92 -> V_96 , V_21 ) ;
return F_54 ( V_95 ) ;
}
V_63 = V_92 -> V_97 [ F_12 ( V_26 ) ] ;
V_64 = F_13 ( V_26 ) ;
V_70 = & V_95 [ V_64 ] ;
V_110 = F_5 ( V_63 ) + V_64 * sizeof( V_6 ) ;
V_51 = F_50 ( V_92 , V_70 , V_110 , V_26 ,
V_113 , V_5 , V_20 ) ;
F_37 ( & V_92 -> V_96 , V_21 ) ;
return V_51 ;
}
static T_2 F_55 ( struct V_10 * V_11 , unsigned long V_117 ,
T_2 V_5 )
{
struct V_1 * V_92 = F_3 ( V_11 ) ;
unsigned long V_21 ;
T_1 V_110 , V_26 = ( T_1 ) V_117 ;
T_3 V_93 ;
V_6 V_12 ;
V_6 * V_70 ;
T_2 V_118 ;
F_36 ( & V_92 -> V_96 , V_21 ) ;
V_12 = V_92 -> V_97 [ F_12 ( V_26 ) ] ;
if ( ! F_6 ( V_12 ) ) {
F_37 ( & V_92 -> V_96 , V_21 ) ;
return 0 ;
}
V_93 = F_5 ( V_12 ) ;
V_70 = ( V_6 * ) F_32 ( V_93 ) + F_13 ( V_26 ) ;
V_110 = V_93 + F_13 ( V_26 ) * sizeof( V_6 ) ;
V_118 = F_49 ( V_92 , V_70 , V_110 , V_5 ) ;
F_37 ( & V_92 -> V_96 , V_21 ) ;
F_38 ( V_92 , V_26 , V_118 ) ;
return V_118 ;
}
static struct V_36 * F_56 ( struct V_103 * V_8 )
{
struct V_119 * V_120 ;
struct V_103 * V_121 ;
struct V_36 * V_36 ;
V_120 = F_57 ( V_8 ) ;
if ( ! V_120 )
return NULL ;
V_121 = F_58 ( V_120 ) ;
V_36 = F_59 ( V_121 ) ;
F_60 ( V_120 ) ;
return V_36 ;
}
static int F_61 ( struct V_10 * V_11 ,
struct V_103 * V_8 )
{
struct V_36 * V_37 ;
struct V_1 * V_92 = F_3 ( V_11 ) ;
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
V_51 = F_62 ( V_37 -> V_8 , V_37 -> V_75 , F_33 ,
V_122 , F_63 ( V_8 ) , V_37 ) ;
if ( V_51 )
return V_51 ;
for ( V_39 = 0 ; V_39 < V_37 -> V_40 ; V_39 ++ ) {
F_17 ( V_37 -> V_41 [ V_39 ] , V_57 ,
V_92 -> V_109 ) ;
F_20 ( V_37 -> V_41 [ V_39 ] , V_87 ) ;
F_17 ( V_37 -> V_41 [ V_39 ] , V_123 , V_90 ) ;
}
V_51 = F_28 ( V_37 ) ;
if ( V_51 )
return V_51 ;
F_36 ( & V_92 -> V_101 , V_21 ) ;
F_64 ( & V_37 -> V_102 , & V_92 -> V_124 ) ;
F_37 ( & V_92 -> V_101 , V_21 ) ;
F_65 ( V_8 , L_17 ) ;
F_27 ( V_37 ) ;
return 0 ;
}
static void F_66 ( struct V_10 * V_11 ,
struct V_103 * V_8 )
{
struct V_36 * V_37 ;
struct V_1 * V_92 = F_3 ( V_11 ) ;
unsigned long V_21 ;
int V_39 ;
V_37 = F_56 ( V_8 ) ;
if ( ! V_37 )
return;
F_36 ( & V_92 -> V_101 , V_21 ) ;
F_67 ( & V_37 -> V_102 ) ;
F_37 ( & V_92 -> V_101 , V_21 ) ;
F_24 ( V_37 ) ;
F_29 ( V_37 ) ;
for ( V_39 = 0 ; V_39 < V_37 -> V_40 ; V_39 ++ ) {
F_17 ( V_37 -> V_41 [ V_39 ] , V_123 , 0 ) ;
F_17 ( V_37 -> V_41 [ V_39 ] , V_57 , 0 ) ;
}
F_27 ( V_37 ) ;
F_68 ( V_37 -> V_8 , V_37 -> V_75 , V_37 ) ;
V_37 -> V_11 = NULL ;
F_65 ( V_8 , L_18 ) ;
}
static struct V_10 * F_69 ( unsigned type )
{
struct V_1 * V_92 ;
struct V_125 * V_7 ;
struct V_103 * V_121 ;
if ( type != V_126 && type != V_127 )
return NULL ;
V_7 = F_70 ( L_19 ,
V_128 , NULL , 0 ) ;
if ( F_53 ( V_7 ) )
return NULL ;
V_92 = F_71 ( & V_7 -> V_8 , sizeof( * V_92 ) , V_129 ) ;
if ( ! V_92 )
goto V_130;
V_92 -> V_7 = V_7 ;
if ( type == V_127 &&
F_72 ( & V_92 -> V_11 ) )
goto V_130;
V_92 -> V_97 = ( V_6 * ) F_44 ( V_129 | V_106 ) ;
if ( ! V_92 -> V_97 )
goto V_131;
V_121 = & V_7 -> V_8 ;
V_92 -> V_109 = F_46 ( V_121 , V_92 -> V_97 ,
V_44 , V_9 ) ;
if ( F_47 ( V_121 , V_92 -> V_109 ) ) {
F_26 ( V_121 , L_20 ) ;
goto V_132;
}
F_1 ( V_92 , V_92 -> V_109 , V_133 ) ;
F_73 ( & V_92 -> V_101 ) ;
F_73 ( & V_92 -> V_96 ) ;
F_74 ( & V_92 -> V_124 ) ;
V_92 -> V_11 . V_134 . V_135 = 0 ;
V_92 -> V_11 . V_134 . V_136 = F_75 ( 32 ) ;
V_92 -> V_11 . V_134 . V_137 = true ;
return & V_92 -> V_11 ;
V_132:
F_48 ( ( unsigned long ) V_92 -> V_97 ) ;
V_131:
if ( type == V_127 )
F_76 ( & V_92 -> V_11 ) ;
V_130:
F_77 ( V_7 ) ;
return NULL ;
}
static void F_78 ( struct V_10 * V_11 )
{
struct V_1 * V_92 = F_3 ( V_11 ) ;
int V_39 ;
F_79 ( ! F_80 ( & V_92 -> V_124 ) ) ;
for ( V_39 = 0 ; V_39 < V_133 ; V_39 ++ ) {
V_6 V_12 = V_92 -> V_97 [ V_39 ] ;
if ( F_6 ( V_12 ) ) {
T_3 V_93 = F_5 ( V_12 ) ;
V_6 * V_95 = F_32 ( V_93 ) ;
F_81 ( & V_92 -> V_7 -> V_8 , V_93 ,
V_44 , V_9 ) ;
F_48 ( ( unsigned long ) V_95 ) ;
}
}
F_81 ( & V_92 -> V_7 -> V_8 , V_92 -> V_109 ,
V_44 , V_9 ) ;
F_48 ( ( unsigned long ) V_92 -> V_97 ) ;
if ( V_11 -> type == V_127 )
F_76 ( & V_92 -> V_11 ) ;
F_77 ( V_92 -> V_7 ) ;
}
static bool F_82 ( struct V_103 * V_8 )
{
struct V_138 * V_139 = V_8 -> V_140 ;
int V_51 ;
V_51 = F_83 ( V_139 , L_21 , L_22 ) ;
return ( V_51 > 0 ) ;
}
static int F_84 ( struct V_119 * V_120 ,
struct V_103 * V_8 )
{
struct V_138 * V_139 = V_8 -> V_140 ;
struct V_125 * V_141 ;
int V_51 ;
struct V_142 args ;
V_51 = F_85 ( V_139 , L_21 , L_22 , 0 ,
& args ) ;
if ( V_51 ) {
F_26 ( V_8 , L_23 ,
V_139 -> V_143 , V_51 ) ;
return V_51 ;
}
if ( args . V_144 != 0 ) {
F_26 ( V_8 , L_24 ,
args . V_139 -> V_143 , args . V_144 ) ;
return - V_145 ;
}
V_141 = F_86 ( args . V_139 ) ;
F_87 ( args . V_139 ) ;
if ( ! V_141 ) {
F_26 ( V_8 , L_25 , args . V_139 -> V_143 ) ;
return - V_146 ;
}
F_88 ( V_120 , & V_141 -> V_8 , NULL ) ;
return 0 ;
}
static int F_89 ( struct V_103 * V_8 )
{
struct V_119 * V_120 ;
struct V_36 * V_37 ;
int V_51 ;
if ( ! F_82 ( V_8 ) )
return - V_147 ;
V_120 = F_57 ( V_8 ) ;
if ( ! V_120 ) {
V_120 = F_90 () ;
if ( F_53 ( V_120 ) ) {
F_26 ( V_8 , L_26 ) ;
return F_54 ( V_120 ) ;
}
}
V_51 = F_91 ( V_120 , V_8 ) ;
if ( V_51 )
goto V_148;
V_51 = F_84 ( V_120 , V_8 ) ;
if ( V_51 )
goto V_149;
V_37 = F_56 ( V_8 ) ;
if ( V_37 )
F_92 ( & V_37 -> V_37 , V_8 ) ;
F_60 ( V_120 ) ;
return 0 ;
V_149:
F_93 ( V_8 ) ;
V_148:
F_60 ( V_120 ) ;
return V_51 ;
}
static void F_94 ( struct V_103 * V_8 )
{
struct V_36 * V_37 ;
if ( ! F_82 ( V_8 ) )
return;
V_37 = F_56 ( V_8 ) ;
if ( V_37 )
F_95 ( & V_37 -> V_37 , V_8 ) ;
F_93 ( V_8 ) ;
}
static int F_96 ( struct V_125 * V_7 )
{
struct V_103 * V_8 = & V_7 -> V_8 ;
V_8 -> V_150 = F_71 ( V_8 , sizeof( * V_8 -> V_150 ) , V_129 ) ;
if ( ! V_8 -> V_150 )
return - V_107 ;
F_97 ( V_8 , 0 , F_75 ( 32 ) , NULL , false ) ;
F_98 ( V_8 , F_75 ( 32 ) ) ;
F_99 ( V_8 , F_75 ( 32 ) ) ;
return 0 ;
}
static int F_100 ( struct V_125 * V_7 )
{
struct V_103 * V_8 = & V_7 -> V_8 ;
struct V_36 * V_37 ;
struct V_151 * V_152 ;
int V_153 = V_7 -> V_154 ;
int V_155 , V_39 ;
V_37 = F_71 ( V_8 , sizeof( * V_37 ) , V_129 ) ;
if ( ! V_37 )
return - V_107 ;
F_101 ( V_7 , V_37 ) ;
V_37 -> V_8 = V_8 ;
V_37 -> V_40 = 0 ;
V_37 -> V_41 = F_71 ( V_8 , sizeof( * V_37 -> V_41 ) * V_153 ,
V_129 ) ;
if ( ! V_37 -> V_41 )
return - V_107 ;
for ( V_39 = 0 ; V_39 < V_153 ; V_39 ++ ) {
V_152 = F_102 ( V_7 , V_156 , V_39 ) ;
if ( ! V_152 )
continue;
V_37 -> V_41 [ V_39 ] = F_103 ( & V_7 -> V_8 , V_152 ) ;
if ( F_53 ( V_37 -> V_41 [ V_39 ] ) )
continue;
V_37 -> V_40 ++ ;
}
if ( V_37 -> V_40 == 0 )
return F_54 ( V_37 -> V_41 [ 0 ] ) ;
V_37 -> V_75 = F_104 ( V_7 , 0 ) ;
if ( V_37 -> V_75 < 0 ) {
F_26 ( V_8 , L_27 , V_37 -> V_75 ) ;
return - V_157 ;
}
V_155 = F_105 ( & V_37 -> V_37 , V_8 , NULL , F_63 ( V_8 ) ) ;
if ( V_155 )
return V_155 ;
F_106 ( & V_37 -> V_37 , & V_158 ) ;
V_155 = F_107 ( & V_37 -> V_37 ) ;
return V_155 ;
}
static int F_108 ( struct V_125 * V_7 )
{
struct V_36 * V_37 = F_109 ( V_7 ) ;
if ( V_37 ) {
F_110 ( & V_37 -> V_37 ) ;
F_111 ( & V_37 -> V_37 ) ;
}
return 0 ;
}
static int T_6 F_112 ( void )
{
struct V_138 * V_139 ;
int V_51 ;
V_139 = F_113 ( NULL , V_159 ) ;
if ( ! V_139 )
return 0 ;
F_87 ( V_139 ) ;
V_51 = F_114 ( & V_160 , & V_158 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_115 ( & V_161 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_115 ( & V_162 ) ;
if ( V_51 )
F_116 ( & V_161 ) ;
return V_51 ;
}
static void T_7 F_117 ( void )
{
F_116 ( & V_162 ) ;
F_116 ( & V_161 ) ;
}

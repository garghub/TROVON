static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
int V_7 ;
F_2 ( & V_4 -> V_8 ) ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
struct V_10 * V_11 = & V_4 -> V_12 [ V_7 ] ;
if ( ! V_11 -> V_13 )
continue;
F_3 ( & V_4 -> V_8 ) ;
F_4 ( V_2 , V_6 , V_11 -> V_14 ) ;
F_2 ( & V_4 -> V_8 ) ;
}
F_3 ( & V_4 -> V_8 ) ;
}
static inline void F_5 ( int V_15 , struct V_16 * V_17 )
{
int V_18 ;
V_18 = V_15 << V_19 ;
V_20 -> V_21 [ V_15 ] . V_22 = V_17 ;
F_6 ( V_18 , V_23 ) ;
if ( V_24 [ V_18 ] . V_25 . V_26 )
F_7 ( V_18 ) ;
else
F_8 ( F_9 ( V_18 ) ,
V_27 ) ;
}
static inline void F_5 ( int V_15 , struct V_16 * V_17 ) { }
static inline int F_10 ( int V_28 ,
struct V_29 * V_21 , int V_30 , int V_31 )
{
bool V_32 ;
int V_33 ;
union V_34 V_35 , V_36 ;
for ( V_33 = V_28 + 1 ; V_33 < V_30 ; V_33 ++ ) {
V_35 = V_36 = F_11 ( V_21 [ V_33 ] . V_37 ) ;
if ( ! V_35 . V_38 || V_35 . V_39 )
continue;
V_36 . V_39 = V_31 ;
V_32 = F_12 ( & V_21 [ V_33 ] . V_37 . V_40 ,
V_35 . V_40 , V_36 . V_40 ) == V_35 . V_40 ;
if ( V_32 ) {
F_13 () ;
return V_33 ;
}
}
return - 1 ;
}
static inline int F_14 ( int V_31 )
{
int V_33 ;
int V_41 = F_15 () >> V_19 ;
struct V_29 * V_21 = V_20 -> V_21 ;
V_33 = F_10 ( V_41 , V_21 , F_16 () , V_31 ) ;
if ( V_33 == - 1 )
V_33 = F_10 ( V_33 , V_21 , V_41 , V_31 ) ;
return V_33 ;
}
static void F_17 ( struct V_16 * V_17 ,
struct V_16 * V_42 )
{
struct V_5 * V_43 = V_42 -> V_44 . V_6 ;
int V_45 ;
int V_15 ;
V_17 -> V_46 . V_47 ++ ;
F_18 ( V_48 , & V_17 -> V_44 . V_49 ) ;
if ( V_17 == V_42 ) {
F_19 ( V_50 , F_20 ( V_50 ) | V_51 ) ;
return;
}
V_45 = V_17 -> V_44 . V_52 ;
if ( V_45 < 0 || V_45 >= V_53 ) {
V_15 = - 1 ;
if ( V_20 && V_54 )
V_15 = F_14 ( V_55 ) ;
if ( V_15 != - 1 ) {
F_5 ( V_15 , V_17 ) ;
} else {
V_43 -> V_39 |= V_55 ;
V_43 -> V_56 = V_17 ;
}
return;
}
F_21 () ;
F_22 ( V_45 ) ;
}
static void F_23 ( struct V_16 * V_17 )
{
F_24 ( V_48 ,
& V_17 -> V_44 . V_49 ) ;
F_19 ( V_50 , F_20 ( V_50 ) & ~ V_51 ) ;
}
static inline bool F_25 ( struct V_5 * V_6 ,
union V_57 V_35 ,
union V_57 V_36 )
{
struct V_16 * V_42 = V_58 -> V_25 . V_16 ;
bool V_32 ;
V_36 . V_59 = ( V_36 . V_60 && ( V_36 . V_61 < V_36 . V_62 ) ) ;
V_32 = F_12 ( & V_6 -> V_11 . V_40 , V_35 . V_40 , V_36 . V_40 ) == V_35 . V_40 ;
if ( ! V_32 )
goto V_63;
if ( V_36 . V_59 )
F_17 ( V_6 -> V_17 , V_42 ) ;
V_42 -> V_44 . V_6 -> V_64 = V_36 ;
V_42 -> V_44 . V_6 -> V_65 = V_6 -> V_17 ;
V_63:
return V_32 ;
}
static inline int F_26 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
return ( V_2 -> V_66 || V_6 -> V_39 ) ? V_67 : V_68 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_1 V_69 ;
F_28 () ;
F_29 (icsid, icp->resend_map, xics->max_icsid + 1 ) {
struct V_3 * V_4 = V_2 -> V_4 [ V_69 ] ;
if ( ! F_30 ( V_69 , V_6 -> V_70 ) )
continue;
if ( ! V_4 )
continue;
F_1 ( V_2 , V_4 , V_6 ) ;
}
}
static bool F_31 ( struct V_5 * V_6 , T_1 V_71 , T_2 V_72 ,
T_1 * V_73 )
{
union V_57 V_74 , V_75 ;
bool V_32 ;
do {
V_74 = V_75 = F_11 ( V_6 -> V_11 ) ;
* V_73 = 0 ;
V_32 = V_75 . V_62 > V_72 &&
V_75 . V_76 > V_72 &&
V_75 . V_61 > V_72 ;
if ( V_32 ) {
* V_73 = V_75 . V_60 ;
V_75 . V_60 = V_71 ;
V_75 . V_61 = V_72 ;
} else {
V_75 . V_77 = true ;
}
} while ( ! F_25 ( V_6 , V_74 , V_75 ) );
return V_32 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_1 V_78 )
{
struct V_10 * V_11 ;
struct V_3 * V_4 ;
T_1 V_73 ;
T_3 V_79 ;
V_80:
V_4 = F_32 ( V_2 , V_78 , & V_79 ) ;
if ( ! V_4 ) {
V_2 -> V_81 ++ ;
return;
}
V_11 = & V_4 -> V_12 [ V_79 ] ;
F_2 ( & V_4 -> V_8 ) ;
if ( ! V_6 || V_11 -> V_82 != V_6 -> V_83 ) {
V_6 = F_33 ( V_2 -> V_84 , V_11 -> V_82 ) ;
if ( ! V_6 ) {
V_2 -> V_85 ++ ;
goto V_86;
}
}
V_11 -> V_13 = 0 ;
if ( V_11 -> V_72 == V_87 ) {
V_11 -> V_88 = 1 ;
goto V_86;
}
if ( F_31 ( V_6 , V_78 , V_11 -> V_72 , & V_73 ) ) {
if ( V_73 && V_73 != V_89 ) {
F_3 ( & V_4 -> V_8 ) ;
V_78 = V_73 ;
goto V_80;
}
} else {
F_18 ( V_4 -> V_69 , V_6 -> V_70 ) ;
V_11 -> V_13 = 1 ;
F_21 () ;
if ( ! V_6 -> V_11 . V_77 ) {
F_3 ( & V_4 -> V_8 ) ;
goto V_80;
}
}
V_86:
F_3 ( & V_4 -> V_8 ) ;
}
static void F_34 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_2 V_90 )
{
union V_57 V_74 , V_75 ;
bool V_13 ;
do {
V_74 = V_75 = F_11 ( V_6 -> V_11 ) ;
V_75 . V_62 = V_90 ;
if ( V_75 . V_76 < V_90 &&
V_75 . V_76 <= V_75 . V_61 ) {
V_75 . V_61 = V_75 . V_76 ;
V_75 . V_60 = V_89 ;
}
V_13 = V_75 . V_77 ;
V_75 . V_77 = 0 ;
} while ( ! F_25 ( V_6 , V_74 , V_75 ) );
if ( V_13 ) {
V_6 -> V_91 ++ ;
F_27 ( V_2 , V_6 ) ;
}
}
unsigned long F_35 ( struct V_16 * V_17 )
{
union V_57 V_74 , V_75 ;
struct V_1 * V_2 = V_17 -> V_84 -> V_44 . V_2 ;
struct V_5 * V_6 = V_17 -> V_44 . V_6 ;
T_1 V_92 ;
if ( ! V_2 || ! V_2 -> V_93 )
return V_67 ;
F_23 ( V_6 -> V_17 ) ;
do {
V_74 = V_75 = F_11 ( V_6 -> V_11 ) ;
V_92 = V_74 . V_60 | ( ( ( T_1 ) V_74 . V_62 ) << 24 ) ;
if ( ! V_74 . V_60 )
break;
V_75 . V_62 = V_75 . V_61 ;
V_75 . V_61 = 0xff ;
V_75 . V_60 = 0 ;
} while ( ! F_25 ( V_6 , V_74 , V_75 ) );
V_17 -> V_44 . V_94 [ 4 ] = V_92 ;
return F_26 ( V_2 , V_6 ) ;
}
int F_36 ( struct V_16 * V_17 , unsigned long V_82 ,
unsigned long V_76 )
{
union V_57 V_74 , V_75 ;
struct V_1 * V_2 = V_17 -> V_84 -> V_44 . V_2 ;
struct V_5 * V_6 , * V_43 = V_17 -> V_44 . V_6 ;
T_1 V_73 ;
bool V_13 ;
bool V_95 ;
if ( ! V_2 || ! V_2 -> V_93 )
return V_67 ;
V_95 = V_43 -> V_83 == V_82 ;
if ( V_95 )
V_6 = V_43 ;
else
V_6 = F_33 ( V_17 -> V_84 , V_82 ) ;
if ( ! V_6 )
return V_96 ;
do {
V_74 = V_75 = F_11 ( V_6 -> V_11 ) ;
V_75 . V_76 = V_76 ;
V_73 = 0 ;
V_13 = false ;
if ( V_76 < V_75 . V_62 ) {
if ( V_76 <= V_75 . V_61 ) {
V_73 = V_75 . V_60 ;
V_75 . V_61 = V_76 ;
V_75 . V_60 = V_89 ;
}
}
if ( V_76 > V_74 . V_76 ) {
V_13 = V_75 . V_77 ;
V_75 . V_77 = 0 ;
}
} while ( ! F_25 ( V_6 , V_74 , V_75 ) );
if ( V_73 && V_73 != V_89 ) {
V_43 -> V_97 ++ ;
F_4 ( V_2 , V_6 , V_73 ) ;
}
if ( V_13 ) {
V_43 -> V_91 ++ ;
F_27 ( V_2 , V_6 ) ;
}
return F_26 ( V_2 , V_43 ) ;
}
int F_37 ( struct V_16 * V_17 , unsigned long V_62 )
{
union V_57 V_74 , V_75 ;
struct V_1 * V_2 = V_17 -> V_84 -> V_44 . V_2 ;
struct V_5 * V_6 = V_17 -> V_44 . V_6 ;
T_1 V_73 ;
if ( ! V_2 || ! V_2 -> V_93 )
return V_67 ;
if ( V_62 > V_6 -> V_11 . V_62 ) {
F_34 ( V_2 , V_6 , V_62 ) ;
goto V_63;
} else if ( V_62 == V_6 -> V_11 . V_62 )
return V_68 ;
F_23 ( V_6 -> V_17 ) ;
do {
V_74 = V_75 = F_11 ( V_6 -> V_11 ) ;
V_73 = 0 ;
V_75 . V_62 = V_62 ;
if ( V_62 <= V_75 . V_61 ) {
V_73 = V_75 . V_60 ;
V_75 . V_60 = 0 ;
V_75 . V_61 = 0xff ;
}
} while ( ! F_25 ( V_6 , V_74 , V_75 ) );
if ( V_73 && V_73 != V_89 ) {
V_6 -> V_97 ++ ;
F_4 ( V_2 , V_6 , V_73 ) ;
}
V_63:
return F_26 ( V_2 , V_6 ) ;
}
int F_38 ( struct V_16 * V_17 , unsigned long V_92 )
{
struct V_1 * V_2 = V_17 -> V_84 -> V_44 . V_2 ;
struct V_5 * V_6 = V_17 -> V_44 . V_6 ;
struct V_3 * V_4 ;
struct V_10 * V_11 ;
T_1 V_71 = V_92 & 0x00ffffff ;
T_3 V_79 ;
if ( ! V_2 || ! V_2 -> V_93 )
return V_67 ;
F_34 ( V_2 , V_6 , V_92 >> 24 ) ;
if ( V_71 == V_89 )
goto V_63;
V_4 = F_32 ( V_2 , V_71 , & V_79 ) ;
if ( ! V_4 )
goto V_63;
V_11 = & V_4 -> V_12 [ V_79 ] ;
if ( V_11 -> V_98 ) {
V_6 -> V_97 ++ ;
F_4 ( V_2 , V_6 , V_71 ) ;
}
if ( ! F_39 ( & V_17 -> V_84 -> V_99 ) ) {
V_6 -> V_39 |= V_100 ;
V_6 -> V_101 = V_71 ;
}
if ( V_11 -> V_102 ) {
++ V_17 -> V_46 . V_103 ;
if ( V_11 -> V_104 != - 1 ) {
int V_105 = F_40 () ;
V_105 = F_41 ( V_105 ) ;
++ V_17 -> V_46 . V_106 ;
if ( V_11 -> V_104 != V_105 ) {
++ V_17 -> V_46 . V_107 ;
F_42 ( V_11 -> V_102 , V_105 ) ;
}
V_11 -> V_104 = - 1 ;
}
}
V_63:
return F_26 ( V_2 , V_6 ) ;
}
static void F_43 ( struct V_108 * V_109 , T_1 V_110 , T_4 V_92 , bool * V_80 )
{
unsigned long V_26 ;
T_5 V_111 ;
V_111 = F_44 ( V_109 , V_110 ) ;
if ( V_111 )
V_112 = V_111 ;
F_45 () ;
V_26 = V_58 -> V_25 . V_26 ;
if ( V_26 ) {
F_46 ( V_26 + V_113 , V_92 ) ;
} else {
V_111 = F_47 ( F_48 ( V_92 ) ) ;
* V_80 = V_111 > 0 ;
}
}
static int F_42 ( unsigned int V_114 , int V_115 )
{
unsigned int V_116 = F_9 ( V_115 ) << 2 ;
return F_49 ( V_114 , V_116 , V_117 ) ;
}
static inline void F_50 ( unsigned int T_6 * V_118 )
{
unsigned long V_119 ;
unsigned int * V_120 ;
int V_45 = F_15 () ;
V_120 = F_51 ( V_118 , V_45 ) ;
V_119 = ( unsigned long ) V_120 ;
if ( F_52 ( V_119 ) == V_121 ) {
V_119 = F_53 ( V_120 ) ;
V_120 = ( unsigned int * ) V_119 ;
}
++ * V_120 ;
}
static void F_54 ( struct V_122 * V_123 )
{
F_50 ( V_123 -> V_124 ) ;
F_55 ( V_125 . V_126 ) ;
}
long F_56 ( struct V_16 * V_17 ,
T_4 V_92 ,
struct V_127 * V_128 ,
struct V_129 * V_130 ,
bool * V_80 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
T_1 V_71 ;
V_71 = V_128 -> V_131 ;
V_2 = V_17 -> V_84 -> V_44 . V_2 ;
V_6 = V_17 -> V_44 . V_6 ;
F_54 ( V_128 -> V_123 ) ;
F_4 ( V_2 , V_6 , V_71 ) ;
F_43 ( F_57 ( V_128 -> V_123 ) , V_128 -> V_132 , V_92 ,
V_80 ) ;
if ( F_26 ( V_2 , V_6 ) == V_67 )
return 2 ;
else
return - 2 ;
}
static void F_58 ( int V_31 , void * V_133 )
{
switch ( V_31 ) {
case V_55 :
V_20 -> V_134 ( V_133 ) ;
break;
default:
F_59 ( 1 , L_1 , V_31 , V_133 ) ;
break;
}
}
void F_60 ( void )
{
int V_33 ;
unsigned int V_45 = F_15 () ;
struct V_29 * V_135 ;
V_33 = V_45 >> V_19 ;
V_135 = & V_20 -> V_21 [ V_33 ] ;
if ( V_135 -> V_22 ) {
F_58 ( V_135 -> V_37 . V_39 ,
V_135 -> V_22 ) ;
V_135 -> V_22 = NULL ;
F_13 () ;
V_135 -> V_37 . V_39 = 0 ;
}
}

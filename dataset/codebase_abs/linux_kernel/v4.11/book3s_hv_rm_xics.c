static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
struct V_9 * V_10 = & V_4 -> V_11 [ V_7 ] ;
if ( V_10 -> V_12 )
F_2 ( V_2 , V_6 , V_10 -> V_13 , true ) ;
}
}
static inline void F_3 ( int V_14 , struct V_15 * V_16 )
{
int V_17 ;
V_17 = V_14 << V_18 ;
V_19 -> V_20 [ V_14 ] . V_21 = V_16 ;
F_4 ( V_17 , V_22 ) ;
F_5 ( V_17 , 1 ) ;
F_6 () ;
F_7 ( V_17 ) ;
}
static inline void F_3 ( int V_14 , struct V_15 * V_16 ) { }
static inline int F_8 ( int V_23 ,
struct V_24 * V_20 , int V_25 , int V_26 )
{
bool V_27 ;
int V_28 ;
union V_29 V_30 , V_31 ;
for ( V_28 = V_23 + 1 ; V_28 < V_25 ; V_28 ++ ) {
V_30 = V_31 = F_9 ( V_20 [ V_28 ] . V_32 ) ;
if ( ! V_30 . V_33 || V_30 . V_34 )
continue;
V_31 . V_34 = V_26 ;
V_27 = F_10 ( & V_20 [ V_28 ] . V_32 . V_35 ,
V_30 . V_35 , V_31 . V_35 ) == V_30 . V_35 ;
if ( V_27 ) {
F_11 () ;
return V_28 ;
}
}
return - 1 ;
}
static inline int F_12 ( int V_26 )
{
int V_28 ;
int V_36 = F_13 () >> V_18 ;
struct V_24 * V_20 = V_19 -> V_20 ;
V_28 = F_8 ( V_36 , V_20 , F_14 () , V_26 ) ;
if ( V_28 == - 1 )
V_28 = F_8 ( V_28 , V_20 , V_36 , V_26 ) ;
return V_28 ;
}
static void F_15 ( struct V_15 * V_16 ,
struct V_15 * V_37 )
{
struct V_5 * V_38 = V_37 -> V_39 . V_6 ;
int V_40 ;
int V_14 ;
V_16 -> V_41 . V_42 ++ ;
F_16 ( V_43 , & V_16 -> V_39 . V_44 ) ;
if ( V_16 == V_37 ) {
F_17 ( V_45 , F_18 ( V_45 ) | V_46 ) ;
return;
}
V_40 = V_16 -> V_39 . V_47 ;
if ( V_40 < 0 || V_40 >= V_48 ) {
V_14 = - 1 ;
if ( V_19 && V_49 )
V_14 = F_12 ( V_50 ) ;
if ( V_14 != - 1 ) {
F_3 ( V_14 , V_16 ) ;
} else {
V_38 -> V_34 |= V_50 ;
V_38 -> V_51 = V_16 ;
}
return;
}
F_6 () ;
F_7 ( V_40 ) ;
}
static void F_19 ( struct V_15 * V_16 )
{
F_20 ( V_43 ,
& V_16 -> V_39 . V_44 ) ;
F_17 ( V_45 , F_18 ( V_45 ) & ~ V_46 ) ;
}
static inline bool F_21 ( struct V_5 * V_6 ,
union V_52 V_30 ,
union V_52 V_31 )
{
struct V_15 * V_37 = V_53 -> V_54 . V_15 ;
bool V_27 ;
V_31 . V_55 = ( V_31 . V_56 && ( V_31 . V_57 < V_31 . V_58 ) ) ;
V_27 = F_10 ( & V_6 -> V_10 . V_35 , V_30 . V_35 , V_31 . V_35 ) == V_30 . V_35 ;
if ( ! V_27 )
goto V_59;
if ( V_31 . V_55 )
F_15 ( V_6 -> V_16 , V_37 ) ;
V_37 -> V_39 . V_6 -> V_60 = V_31 ;
V_37 -> V_39 . V_6 -> V_61 = V_6 -> V_16 ;
V_59:
return V_27 ;
}
static inline int F_22 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
return ( V_2 -> V_62 || V_6 -> V_34 ) ? V_63 : V_64 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_1 V_65 ;
F_24 () ;
F_25 (icsid, icp->resend_map, xics->max_icsid + 1 ) {
struct V_3 * V_4 = V_2 -> V_4 [ V_65 ] ;
if ( ! F_26 ( V_65 , V_6 -> V_66 ) )
continue;
if ( ! V_4 )
continue;
F_1 ( V_2 , V_4 , V_6 ) ;
}
}
static bool F_27 ( struct V_5 * V_6 , T_1 V_67 , T_2 V_68 ,
T_1 * V_69 )
{
union V_52 V_70 , V_71 ;
bool V_27 ;
do {
V_70 = V_71 = F_9 ( V_6 -> V_10 ) ;
* V_69 = 0 ;
V_27 = V_71 . V_58 > V_68 &&
V_71 . V_72 > V_68 &&
V_71 . V_57 > V_68 ;
if ( V_27 ) {
* V_69 = V_71 . V_56 ;
V_71 . V_56 = V_67 ;
V_71 . V_57 = V_68 ;
} else {
V_71 . V_73 = true ;
}
} while ( ! F_21 ( V_6 , V_70 , V_71 ) );
return V_27 ;
}
static void F_2 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_1 V_74 , bool V_75 )
{
struct V_9 * V_10 ;
struct V_3 * V_4 ;
T_1 V_69 ;
T_3 V_76 ;
V_77:
V_4 = F_28 ( V_2 , V_74 , & V_76 ) ;
if ( ! V_4 ) {
V_2 -> V_78 ++ ;
return;
}
V_10 = & V_4 -> V_11 [ V_76 ] ;
F_29 ( & V_4 -> V_79 ) ;
if ( ! V_6 || V_10 -> V_80 != V_6 -> V_81 ) {
V_6 = F_30 ( V_2 -> V_82 , V_10 -> V_80 ) ;
if ( ! V_6 ) {
V_2 -> V_83 ++ ;
goto V_84;
}
}
if ( V_75 )
if ( ! V_10 -> V_12 )
goto V_84;
V_10 -> V_12 = 0 ;
if ( V_10 -> V_68 == V_85 ) {
V_10 -> V_86 = 1 ;
goto V_84;
}
if ( F_27 ( V_6 , V_74 , V_10 -> V_68 , & V_69 ) ) {
if ( V_69 && V_69 != V_87 ) {
F_31 ( & V_4 -> V_79 ) ;
V_6 -> V_88 ++ ;
V_74 = V_69 ;
V_75 = 0 ;
goto V_77;
}
} else {
V_10 -> V_12 = 1 ;
F_11 () ;
F_16 ( V_4 -> V_65 , V_6 -> V_66 ) ;
F_6 () ;
if ( ! V_6 -> V_10 . V_73 ) {
V_10 -> V_12 = 0 ;
F_31 ( & V_4 -> V_79 ) ;
V_75 = 0 ;
goto V_77;
}
}
V_84:
F_31 ( & V_4 -> V_79 ) ;
}
static void F_32 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_2 V_89 )
{
union V_52 V_70 , V_71 ;
bool V_12 ;
do {
V_70 = V_71 = F_9 ( V_6 -> V_10 ) ;
V_71 . V_58 = V_89 ;
if ( V_71 . V_72 < V_89 &&
V_71 . V_72 <= V_71 . V_57 ) {
V_71 . V_57 = V_71 . V_72 ;
V_71 . V_56 = V_87 ;
}
V_12 = V_71 . V_73 ;
V_71 . V_73 = 0 ;
} while ( ! F_21 ( V_6 , V_70 , V_71 ) );
if ( V_12 ) {
V_6 -> V_90 ++ ;
F_23 ( V_2 , V_6 ) ;
}
}
unsigned long F_33 ( struct V_15 * V_16 )
{
union V_52 V_70 , V_71 ;
struct V_1 * V_2 = V_16 -> V_82 -> V_39 . V_2 ;
struct V_5 * V_6 = V_16 -> V_39 . V_6 ;
T_1 V_91 ;
if ( ! V_2 || ! V_2 -> V_92 )
return V_63 ;
F_19 ( V_6 -> V_16 ) ;
do {
V_70 = V_71 = F_9 ( V_6 -> V_10 ) ;
V_91 = V_70 . V_56 | ( ( ( T_1 ) V_70 . V_58 ) << 24 ) ;
if ( ! V_70 . V_56 )
break;
V_71 . V_58 = V_71 . V_57 ;
V_71 . V_57 = 0xff ;
V_71 . V_56 = 0 ;
} while ( ! F_21 ( V_6 , V_70 , V_71 ) );
V_16 -> V_39 . V_93 [ 4 ] = V_91 ;
return F_22 ( V_2 , V_6 ) ;
}
int F_34 ( struct V_15 * V_16 , unsigned long V_80 ,
unsigned long V_72 )
{
union V_52 V_70 , V_71 ;
struct V_1 * V_2 = V_16 -> V_82 -> V_39 . V_2 ;
struct V_5 * V_6 , * V_38 = V_16 -> V_39 . V_6 ;
T_1 V_69 ;
bool V_12 ;
bool V_94 ;
if ( ! V_2 || ! V_2 -> V_92 )
return V_63 ;
V_94 = V_38 -> V_81 == V_80 ;
if ( V_94 )
V_6 = V_38 ;
else
V_6 = F_30 ( V_16 -> V_82 , V_80 ) ;
if ( ! V_6 )
return V_95 ;
do {
V_70 = V_71 = F_9 ( V_6 -> V_10 ) ;
V_71 . V_72 = V_72 ;
V_69 = 0 ;
V_12 = false ;
if ( V_72 < V_71 . V_58 ) {
if ( V_72 <= V_71 . V_57 ) {
V_69 = V_71 . V_56 ;
V_71 . V_57 = V_72 ;
V_71 . V_56 = V_87 ;
}
}
if ( V_72 > V_70 . V_72 ) {
V_12 = V_71 . V_73 ;
V_71 . V_73 = 0 ;
}
} while ( ! F_21 ( V_6 , V_70 , V_71 ) );
if ( V_69 && V_69 != V_87 ) {
V_38 -> V_88 ++ ;
F_2 ( V_2 , V_6 , V_69 , false ) ;
}
if ( V_12 ) {
V_38 -> V_90 ++ ;
F_23 ( V_2 , V_6 ) ;
}
return F_22 ( V_2 , V_38 ) ;
}
int F_35 ( struct V_15 * V_16 , unsigned long V_58 )
{
union V_52 V_70 , V_71 ;
struct V_1 * V_2 = V_16 -> V_82 -> V_39 . V_2 ;
struct V_5 * V_6 = V_16 -> V_39 . V_6 ;
T_1 V_69 ;
if ( ! V_2 || ! V_2 -> V_92 )
return V_63 ;
if ( V_58 > V_6 -> V_10 . V_58 ) {
F_32 ( V_2 , V_6 , V_58 ) ;
goto V_59;
} else if ( V_58 == V_6 -> V_10 . V_58 )
return V_64 ;
F_19 ( V_6 -> V_16 ) ;
do {
V_70 = V_71 = F_9 ( V_6 -> V_10 ) ;
V_69 = 0 ;
V_71 . V_58 = V_58 ;
if ( V_58 <= V_71 . V_57 ) {
V_69 = V_71 . V_56 ;
V_71 . V_56 = 0 ;
V_71 . V_57 = 0xff ;
}
} while ( ! F_21 ( V_6 , V_70 , V_71 ) );
if ( V_69 && V_69 != V_87 ) {
V_6 -> V_88 ++ ;
F_2 ( V_2 , V_6 , V_69 , false ) ;
}
V_59:
return F_22 ( V_2 , V_6 ) ;
}
static int F_36 ( struct V_15 * V_16 , T_1 V_67 )
{
struct V_1 * V_2 = V_16 -> V_82 -> V_39 . V_2 ;
struct V_5 * V_6 = V_16 -> V_39 . V_6 ;
struct V_3 * V_4 ;
struct V_9 * V_10 ;
T_3 V_76 ;
T_1 V_96 , V_97 ;
V_4 = F_28 ( V_2 , V_67 , & V_76 ) ;
if ( ! V_4 )
goto V_59;
V_10 = & V_4 -> V_11 [ V_76 ] ;
if ( V_10 -> V_98 )
V_97 = V_10 -> V_99 ;
else
do {
V_96 = V_10 -> V_99 ;
V_97 = V_96 >> 1 ;
} while ( F_37 ( & V_10 -> V_99 , V_96 , V_97 ) != V_96 );
if ( V_97 & V_100 )
F_2 ( V_2 , NULL , V_67 , false ) ;
if ( ! F_38 ( & V_16 -> V_82 -> V_101 ) ) {
V_6 -> V_34 |= V_102 ;
V_6 -> V_103 = V_67 ;
}
if ( V_10 -> V_104 ) {
++ V_16 -> V_41 . V_105 ;
if ( V_10 -> V_106 != - 1 ) {
int V_107 = F_39 () ;
V_107 = F_40 ( V_107 ) ;
++ V_16 -> V_41 . V_108 ;
if ( V_10 -> V_106 != V_107 ) {
++ V_16 -> V_41 . V_109 ;
F_41 ( V_10 -> V_104 , V_107 ) ;
}
V_10 -> V_106 = - 1 ;
}
}
V_59:
return F_22 ( V_2 , V_6 ) ;
}
int F_42 ( struct V_15 * V_16 , unsigned long V_91 )
{
struct V_1 * V_2 = V_16 -> V_82 -> V_39 . V_2 ;
struct V_5 * V_6 = V_16 -> V_39 . V_6 ;
T_1 V_67 = V_91 & 0x00ffffff ;
if ( ! V_2 || ! V_2 -> V_92 )
return V_63 ;
F_32 ( V_2 , V_6 , V_91 >> 24 ) ;
if ( V_67 == V_87 )
return F_22 ( V_2 , V_6 ) ;
return F_36 ( V_16 , V_67 ) ;
}
static void F_43 ( struct V_110 * V_111 , T_1 V_112 , T_4 V_91 , bool * V_77 )
{
unsigned long V_113 ;
T_5 V_114 ;
V_114 = F_44 ( V_111 , V_112 ) ;
if ( V_114 )
V_115 = V_114 ;
F_45 () ;
V_113 = V_53 -> V_54 . V_113 ;
if ( V_113 ) {
F_46 ( V_113 + V_116 , V_91 ) ;
} else {
V_114 = F_47 ( F_48 ( V_91 ) ) ;
* V_77 = V_114 > 0 ;
}
}
static int F_41 ( unsigned int V_117 , int V_118 )
{
unsigned int V_119 = F_49 ( V_118 ) << 2 ;
return F_50 ( V_117 , V_119 , V_120 ) ;
}
static inline void F_51 ( unsigned int T_6 * V_121 )
{
unsigned long V_122 ;
unsigned int * V_123 ;
int V_40 = F_13 () ;
V_123 = F_52 ( V_121 , V_40 ) ;
V_122 = ( unsigned long ) V_123 ;
if ( F_53 ( V_122 ) == V_124 ) {
V_122 = F_54 ( V_123 ) ;
V_123 = ( unsigned int * ) V_122 ;
}
++ * V_123 ;
}
static void F_55 ( struct V_125 * V_126 )
{
F_51 ( V_126 -> V_127 ) ;
F_56 ( V_128 . V_129 ) ;
}
long F_57 ( struct V_15 * V_16 ,
T_4 V_91 ,
struct V_130 * V_131 ,
struct V_132 * V_133 ,
bool * V_77 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_9 * V_10 ;
T_1 V_67 ;
T_3 V_76 ;
T_1 V_96 , V_97 ;
V_67 = V_131 -> V_134 ;
V_2 = V_16 -> V_82 -> V_39 . V_2 ;
V_6 = V_16 -> V_39 . V_6 ;
F_55 ( V_131 -> V_126 ) ;
V_4 = F_28 ( V_2 , V_67 , & V_76 ) ;
if ( ! V_4 )
return 2 ;
V_10 = & V_4 -> V_11 [ V_76 ] ;
do {
V_96 = V_10 -> V_99 ;
V_97 = ( ( V_96 << 1 ) & 3 ) | V_100 ;
} while ( F_37 ( & V_10 -> V_99 , V_96 , V_97 ) != V_96 );
if ( V_97 == V_100 )
F_2 ( V_2 , V_6 , V_67 , false ) ;
F_43 ( F_58 ( V_131 -> V_126 ) , V_131 -> V_135 , V_91 ,
V_77 ) ;
if ( F_22 ( V_2 , V_6 ) == V_63 )
return 2 ;
else
return - 2 ;
}
static void F_59 ( int V_26 , void * V_136 )
{
switch ( V_26 ) {
case V_50 :
V_19 -> V_137 ( V_136 ) ;
break;
default:
F_60 ( 1 , L_1 , V_26 , V_136 ) ;
break;
}
}
void F_61 ( void )
{
int V_28 ;
unsigned int V_40 = F_13 () ;
struct V_24 * V_138 ;
V_28 = V_40 >> V_18 ;
V_138 = & V_19 -> V_20 [ V_28 ] ;
if ( V_138 -> V_21 ) {
F_59 ( V_138 -> V_32 . V_34 ,
V_138 -> V_21 ) ;
V_138 -> V_21 = NULL ;
F_11 () ;
V_138 -> V_32 . V_34 = 0 ;
}
}

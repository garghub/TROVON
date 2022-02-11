static void * F_1 ( struct V_1 * V_2 )
{
void * V_3 = F_2 ( V_2 ) ;
V_2 -> V_4 += V_2 -> V_5 ;
if ( V_2 -> V_4 > V_2 -> V_6 ) {
V_2 -> V_4 -= V_2 -> V_5 ;
V_3 = NULL ;
} else if ( ( ( V_7 ) V_3 ) & ( V_8 - 1 ) ) {
F_3 ( L_1 ) ;
V_3 = NULL ;
}
return V_3 ;
}
static int F_4 ( struct V_1 * V_2 , const T_1 V_9 ,
const T_1 V_5 , const T_1 V_10 )
{
int V_11 = V_12 / V_5 ;
int V_13 , V_14 ;
if ( ( V_5 > V_12 ) || ( ! V_11 ) ) {
F_3 ( L_2 ,
( int ) V_12 , ( int ) V_5 ) ;
return - V_15 ;
}
V_2 -> V_6 = V_9 * V_5 ;
V_2 -> V_16 = F_5 ( V_9 * sizeof( void * ) , V_17 ) ;
if ( ! V_2 -> V_16 ) {
F_3 ( L_3 ) ;
return - V_18 ;
}
V_13 = 0 ;
while ( V_13 < V_9 ) {
T_2 * V_19 = ( T_2 * ) F_6 ( V_17 ) ;
if ( ! V_19 )
goto V_20;
for ( V_14 = 0 ; V_14 < V_11 && V_13 < V_9 ; V_14 ++ ) {
( V_2 -> V_16 ) [ V_13 ] = (struct V_21 * ) V_19 ;
V_19 += V_5 ;
V_13 ++ ;
}
}
V_2 -> V_4 = 0 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_22 = 1 ;
return 0 ;
V_20:
for ( V_13 = 0 ; V_13 < V_9 ; V_13 += V_11 ) {
if ( ! ( V_2 -> V_16 ) [ V_13 ] )
break;
F_7 ( ( unsigned long ) ( V_2 -> V_16 ) [ V_13 ] ) ;
}
return - V_18 ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_11 = V_12 / V_2 -> V_5 ;
int V_13 , V_23 ;
if ( ! V_2 || ! V_2 -> V_16 )
return;
V_23 = V_2 -> V_6 / V_2 -> V_5 ;
for ( V_13 = 0 ; V_13 < V_23 ; V_13 += V_11 )
F_7 ( ( unsigned long ) ( V_2 -> V_16 ) [ V_13 ] ) ;
F_9 ( V_2 -> V_16 ) ;
}
struct V_24 * F_10 ( struct V_25 * V_26 ,
int V_27 , V_7 V_28 , T_1 V_29 )
{
struct V_24 * V_30 ;
struct V_31 V_32 ;
V_7 * V_33 , V_34 , V_35 ;
T_1 V_36 , V_37 , V_38 ;
int V_39 ;
void * V_40 ;
V_30 = F_11 ( sizeof( * V_30 ) , V_17 ) ;
if ( ! V_30 ) {
F_3 ( L_4 ) ;
goto V_20;
}
V_30 -> V_41 . V_42 = V_27 ;
V_30 -> V_41 . V_29 = V_29 ;
V_30 -> V_41 . V_28 = V_28 ;
V_30 -> V_26 = V_26 ;
V_33 = & V_30 -> V_43 ;
V_36 = 0 ;
V_37 = 0 ;
V_34 = F_12 ( V_26 -> V_44 , & V_30 -> V_41 ,
& V_30 -> V_43 , & V_30 -> V_45 ) ;
if ( V_34 != V_46 ) {
F_3 ( L_5 ) ;
goto V_47;
}
V_39 = F_4 ( & V_30 -> V_1 , V_30 -> V_41 . V_23 ,
V_8 , sizeof( struct V_48 ) ) ;
if ( V_39 )
goto V_49;
for ( V_38 = 0 ; V_38 < V_30 -> V_41 . V_23 ; V_38 ++ ) {
V_40 = F_1 ( & V_30 -> V_1 ) ;
if ( ! V_40 ) {
F_3 ( L_6 ) ;
goto V_50;
}
V_35 = F_13 ( V_40 ) ;
V_34 = F_14 ( V_26 -> V_44 ,
0 , V_51 ,
V_30 -> V_43 , V_35 , 1 ) ;
if ( V_34 < V_46 ) {
F_3 ( L_7 ,
V_30 , V_34 , V_38 , V_30 -> V_41 . V_23 ) ;
goto V_50;
}
if ( V_38 == ( V_30 -> V_41 . V_23 - 1 ) ) {
V_40 = F_1 ( & V_30 -> V_1 ) ;
if ( ( V_34 != V_46 ) || ( V_40 ) ) {
F_3 ( L_8 ,
V_34 ) ;
goto V_50;
}
} else {
if ( V_34 != V_52 ) {
F_3 ( L_9 ,
V_34 ) ;
goto V_50;
}
}
}
F_15 ( & V_30 -> V_1 ) ;
V_32 = V_30 -> V_45 . V_53 ;
F_16 ( V_30 ) ;
F_17 ( V_30 ) ;
return V_30 ;
V_50:
F_8 ( & V_30 -> V_1 ) ;
V_49:
F_18 ( V_26 -> V_44 , V_30 -> V_43 , V_54 ) ;
V_47:
F_9 ( V_30 ) ;
V_20:
return NULL ;
}
V_7 F_19 ( struct V_24 * V_30 , V_7 V_55 )
{
V_7 V_34 ;
V_7 V_56 = V_30 -> V_26 -> V_44 ;
V_34 = F_18 ( V_56 , V_30 -> V_43 , V_55 ) ;
if ( V_34 != V_46 )
return V_34 ;
F_8 ( & V_30 -> V_1 ) ;
F_9 ( V_30 ) ;
return V_34 ;
}
int F_20 ( struct V_24 * V_30 )
{
V_7 V_34 , V_57 , V_58 ;
if ( ! V_30 )
return 0 ;
F_21 ( & V_30 -> V_45 ) ;
V_34 = F_19 ( V_30 , V_59 ) ;
if ( V_34 == V_60 ) {
F_22 ( V_30 -> V_26 , V_30 -> V_43 , & V_57 , & V_58 ) ;
V_34 = F_19 ( V_30 , V_54 ) ;
}
if ( V_34 != V_46 ) {
F_3 ( L_10 ) ;
return - V_61 ;
}
return 0 ;
}
struct V_62 * F_23 ( struct V_25 * V_26 ,
const enum V_63 type ,
const T_1 V_64 , const T_2 V_65 )
{
int V_39 , V_13 ;
V_7 V_34 , V_35 ;
void * V_40 ;
struct V_62 * V_66 ;
V_66 = F_11 ( sizeof( * V_66 ) , V_17 ) ;
if ( ! V_66 ) {
F_3 ( L_11 ) ;
return NULL ;
}
V_66 -> V_26 = V_26 ;
V_66 -> V_41 . type = type ;
V_66 -> V_41 . V_64 = V_64 ;
V_66 -> V_41 . V_65 = V_65 ;
F_24 ( & V_66 -> V_67 ) ;
V_34 = F_25 ( V_26 -> V_44 ,
& V_66 -> V_41 , & V_66 -> V_43 ) ;
if ( V_34 != V_46 ) {
F_3 ( L_12 ) ;
goto V_47;
}
V_39 = F_4 ( & V_66 -> V_1 , V_66 -> V_41 . V_23 ,
V_8 , sizeof( struct V_68 ) ) ;
if ( V_39 ) {
F_3 ( L_13 ) ;
goto V_49;
}
for ( V_13 = 0 ; V_13 < V_66 -> V_41 . V_23 ; V_13 ++ ) {
V_40 = F_1 ( & V_66 -> V_1 ) ;
if ( ! V_40 ) {
F_3 ( L_6 ) ;
V_34 = V_69 ;
goto V_50;
}
V_35 = F_13 ( V_40 ) ;
V_34 = F_14 ( V_26 -> V_44 , 0 ,
V_70 ,
V_66 -> V_43 , V_35 , 1 ) ;
if ( V_13 == ( V_66 -> V_41 . V_23 - 1 ) ) {
V_40 = F_1 ( & V_66 -> V_1 ) ;
if ( ( V_34 != V_46 ) || ( V_40 ) )
goto V_50;
} else {
if ( V_34 != V_52 )
goto V_50;
}
}
F_15 ( & V_66 -> V_1 ) ;
return V_66 ;
V_50:
F_8 ( & V_66 -> V_1 ) ;
V_49:
F_18 ( V_26 -> V_44 , V_66 -> V_43 , V_54 ) ;
V_47:
F_9 ( V_66 ) ;
return NULL ;
}
struct V_68 * F_26 ( struct V_62 * V_66 )
{
struct V_68 * V_71 ;
unsigned long V_72 ;
F_27 ( & V_66 -> V_67 , V_72 ) ;
V_71 = F_28 ( & V_66 -> V_1 ) ;
F_29 ( & V_66 -> V_67 , V_72 ) ;
return V_71 ;
}
V_7 F_30 ( struct V_62 * V_66 , V_7 V_55 )
{
V_7 V_34 ;
unsigned long V_72 ;
F_27 ( & V_66 -> V_67 , V_72 ) ;
V_34 = F_18 ( V_66 -> V_26 -> V_44 , V_66 -> V_43 , V_55 ) ;
F_29 ( & V_66 -> V_67 , V_72 ) ;
if ( V_34 != V_46 )
return V_34 ;
F_8 ( & V_66 -> V_1 ) ;
F_9 ( V_66 ) ;
return V_34 ;
}
int F_31 ( struct V_62 * V_66 )
{
V_7 V_34 , V_57 , V_58 ;
if ( ! V_66 )
return 0 ;
F_21 ( & V_66 -> V_45 ) ;
V_34 = F_30 ( V_66 , V_59 ) ;
if ( V_34 == V_60 ) {
F_22 ( V_66 -> V_26 , V_66 -> V_43 , & V_57 , & V_58 ) ;
V_34 = F_30 ( V_66 , V_54 ) ;
}
if ( V_34 != V_46 ) {
F_3 ( L_14 ) ;
return - V_61 ;
}
return 0 ;
}
int F_32 ( struct V_73 * V_74 , struct V_1 * V_1 ,
int V_23 , int V_75 , int V_76 ,
struct V_25 * V_26 , int V_77 )
{
V_7 V_34 , V_35 ;
int V_39 , V_78 ;
void * V_40 ;
V_39 = F_4 ( V_1 , V_23 , V_8 , V_75 ) ;
if ( V_39 )
return V_39 ;
for ( V_78 = 0 ; V_78 < V_23 ; V_78 ++ ) {
V_40 = F_1 ( V_1 ) ;
if ( ! V_40 ) {
F_3 ( L_6 ) ;
goto V_50;
}
V_35 = F_13 ( V_40 ) ;
V_34 = F_14 ( V_26 -> V_44 ,
0 , V_77 ,
V_74 -> V_43 , V_35 , 1 ) ;
if ( V_34 < V_46 ) {
F_3 ( L_15 ) ;
goto V_50;
}
}
F_15 ( V_1 ) ;
return 0 ;
V_50:
F_8 ( V_1 ) ;
return - V_61 ;
}
static inline T_1 F_33 ( T_2 V_79 )
{
return 128 << V_79 ;
}
struct V_73 * F_34 ( struct V_25 * V_26 ,
T_1 V_80 , struct V_81 * V_82 )
{
int V_39 ;
V_7 V_34 ;
struct V_73 * V_74 ;
T_1 V_83 , V_84 ;
T_1 V_85 , V_86 ;
V_74 = F_11 ( sizeof( * V_74 ) , V_17 ) ;
if ( ! V_74 ) {
F_3 ( L_16 ) ;
return NULL ;
}
V_74 -> V_26 = V_26 ;
V_34 = F_35 ( V_26 -> V_44 , V_82 , V_80 ,
& V_74 -> V_43 , & V_74 -> V_45 ) ;
if ( V_34 != V_46 ) {
F_3 ( L_17 ) ;
goto V_47;
}
V_83 = F_33 ( V_82 -> V_87 ) ;
V_84 = F_33 ( V_82 -> V_88 ) ;
V_85 = F_33 ( V_82 -> V_89 ) ;
V_86 = F_33 ( V_82 -> V_90 ) ;
V_39 = F_32 ( V_74 , & V_74 -> V_91 , V_82 -> V_92 ,
V_83 ,
V_82 -> V_87 , V_26 ,
0 ) ;
if ( V_39 ) {
F_3 ( L_18 , V_39 ) ;
goto V_49;
}
V_39 = F_32 ( V_74 , & V_74 -> V_93 ,
V_82 -> V_94 ,
V_84 ,
V_82 -> V_88 ,
V_26 , 1 ) ;
if ( V_39 ) {
F_3 ( L_19 , V_39 ) ;
goto V_95;
}
if ( V_82 -> V_96 > 1 ) {
V_39 = F_32 ( V_74 , & V_74 -> V_97 ,
V_82 -> V_98 ,
V_85 ,
V_82 -> V_89 ,
V_26 , 2 ) ;
if ( V_39 ) {
F_3 ( L_20 , V_39 ) ;
goto V_99;
}
}
if ( V_82 -> V_96 > 2 ) {
V_39 = F_32 ( V_74 , & V_74 -> V_100 ,
V_82 -> V_101 ,
V_86 ,
V_82 -> V_90 ,
V_26 , 3 ) ;
if ( V_39 ) {
F_3 ( L_21 , V_39 ) ;
goto V_102;
}
}
V_74 -> V_82 = * V_82 ;
return V_74 ;
V_102:
F_8 ( & V_74 -> V_97 ) ;
V_99:
F_8 ( & V_74 -> V_93 ) ;
V_95:
F_8 ( & V_74 -> V_91 ) ;
V_49:
F_36 ( V_26 -> V_44 , V_74 -> V_43 ) ;
F_18 ( V_26 -> V_44 , V_74 -> V_43 , V_54 ) ;
V_47:
F_9 ( V_74 ) ;
return NULL ;
}
V_7 F_37 ( struct V_73 * V_74 , V_7 V_55 )
{
V_7 V_34 ;
struct V_81 * V_103 = & V_74 -> V_82 ;
F_36 ( V_74 -> V_26 -> V_44 , V_74 -> V_43 ) ;
V_34 = F_18 ( V_74 -> V_26 -> V_44 , V_74 -> V_43 , V_55 ) ;
if ( V_34 != V_46 )
return V_34 ;
F_8 ( & V_74 -> V_91 ) ;
F_8 ( & V_74 -> V_93 ) ;
if ( V_103 -> V_96 > 1 )
F_8 ( & V_74 -> V_97 ) ;
if ( V_103 -> V_96 > 2 )
F_8 ( & V_74 -> V_100 ) ;
F_9 ( V_74 ) ;
return V_34 ;
}
int F_38 ( struct V_73 * V_74 )
{
V_7 V_34 , V_57 , V_58 ;
if ( ! V_74 )
return 0 ;
F_21 ( & V_74 -> V_45 ) ;
V_34 = F_37 ( V_74 , V_59 ) ;
if ( V_34 == V_60 ) {
F_22 ( V_74 -> V_26 , V_74 -> V_43 , & V_57 , & V_58 ) ;
V_34 = F_37 ( V_74 , V_54 ) ;
}
if ( V_34 != V_46 ) {
F_3 ( L_22 ) ;
return - V_61 ;
}
return 0 ;
}
static inline int F_39 ( unsigned long V_13 , unsigned long V_104 )
{
return ( V_13 >> V_104 ) & V_105 ;
}
static inline int F_40 ( struct V_106 * V_106 ,
int V_107 )
{
if ( ! V_106 -> V_107 [ V_107 ] ) {
V_106 -> V_107 [ V_107 ] =
F_11 ( sizeof( struct V_108 ) , V_17 ) ;
if ( ! V_106 -> V_107 [ V_107 ] )
return - V_18 ;
}
return 0 ;
}
static inline int F_41 ( struct V_109 * V_109 , int V_110 , int V_107 )
{
if ( ! V_109 -> V_110 [ V_110 ] ) {
V_109 -> V_110 [ V_110 ] =
F_11 ( sizeof( struct V_106 ) , V_17 ) ;
if ( ! V_109 -> V_110 [ V_110 ] )
return - V_18 ;
}
return F_40 ( V_109 -> V_110 [ V_110 ] , V_107 ) ;
}
static void F_42 ( void )
{
V_7 V_111 = V_112 ;
int V_110 , V_107 , V_113 ;
for ( V_110 = 0 ; V_110 < V_114 ; V_110 ++ ) {
struct V_106 * V_115 ;
int V_116 = 0 ;
if ( ! V_109 -> V_110 [ V_110 ] )
continue;
V_115 = V_109 -> V_110 [ V_110 ] ;
for ( V_107 = 0 ; V_107 < V_114 ; V_107 ++ ) {
struct V_108 * V_117 ;
int V_118 = 0 ;
if ( ! V_115 -> V_107 [ V_107 ] )
continue;
V_116 ++ ;
V_117 = V_115 -> V_107 [ V_107 ] ;
for ( V_113 = 0 ; V_113 < V_114 ; V_113 ++ ) {
if ( ! V_117 -> V_119 [ V_113 ] )
continue;
V_118 ++ ;
V_117 -> V_119 [ V_113 ] = V_111 ;
V_111 += V_120 ;
}
if ( ! V_118 ) {
V_115 -> V_107 [ V_107 ] = NULL ;
F_9 ( V_117 ) ;
}
}
if ( ! V_116 ) {
V_109 -> V_110 [ V_110 ] = NULL ;
F_9 ( V_115 ) ;
}
}
}
static int F_43 ( unsigned long V_121 , unsigned long V_23 , int V_122 )
{
unsigned long V_13 , V_123 , V_124 ;
if ( ! V_23 )
return 0 ;
if ( ! V_109 ) {
V_109 = F_11 ( sizeof( struct V_109 ) , V_17 ) ;
if ( ! V_109 )
return - V_18 ;
}
V_123 = ( V_121 * V_12 ) / V_120 ;
V_124 = V_123 + ( ( V_23 * V_12 ) / V_120 ) ;
for ( V_13 = V_123 ; V_13 < V_124 ; V_13 ++ ) {
V_7 V_125 ;
int V_110 = F_39 ( V_13 , V_126 ) ;
int V_107 = F_39 ( V_13 , V_127 ) ;
int V_113 = V_13 & V_105 ;
if ( V_122 ) {
int V_39 = F_41 ( V_109 , V_110 , V_107 ) ;
if ( V_39 )
return V_39 ;
V_125 = 1 ;
V_128 += V_120 ;
} else {
if ( ! V_109 -> V_110 [ V_110 ] )
continue;
if ( ! V_109 -> V_110 [ V_110 ] -> V_107 [ V_107 ] )
continue;
V_125 = 0 ;
V_128 -= V_120 ;
}
V_109 -> V_110 [ V_110 ] -> V_107 [ V_107 ] -> V_119 [ V_113 ] = V_125 ;
}
F_42 () ;
return 0 ;
}
int F_44 ( unsigned long V_121 , unsigned long V_23 )
{
int V_39 ;
F_45 ( & V_129 ) ;
V_39 = F_43 ( V_121 , V_23 , V_130 ) ;
F_46 ( & V_129 ) ;
return V_39 ;
}
int F_47 ( unsigned long V_121 , unsigned long V_23 )
{
int V_39 ;
F_45 ( & V_129 ) ;
V_39 = F_43 ( V_121 , V_23 , V_131 ) ;
F_46 ( & V_129 ) ;
return V_39 ;
}
static int F_48 ( unsigned long V_121 )
{
int V_132 ;
if ( V_121 & V_133 )
return 0 ;
V_132 = F_49 ( F_50 ( V_121 ) ) ;
if ( V_132 + V_134 != V_135 )
return 0 ;
return 1 ;
}
static int F_51 ( unsigned long V_136 ,
unsigned long V_137 , void * V_138 )
{
int V_39 ;
unsigned long V_121 , V_139 , V_140 , V_23 ;
if ( ( V_137 * V_12 ) < V_141 )
return F_43 ( V_136 , V_137 ,
V_130 ) ;
V_139 = V_136 ;
V_140 = V_136 + V_137 ;
V_121 = V_139 ;
while ( V_121 < V_140 ) {
if ( F_48 ( V_121 ) ) {
V_23 = V_121 - V_139 ;
V_39 = F_43 ( V_139 , V_23 ,
V_130 ) ;
if ( V_39 )
return V_39 ;
V_121 += ( V_141 / V_12 ) ;
V_139 = V_121 ;
} else
V_121 += ( V_120 / V_12 ) ;
}
V_23 = V_121 - V_139 ;
return F_43 ( V_139 , V_23 , V_130 ) ;
}
int F_52 ( void )
{
int V_39 ;
F_45 ( & V_129 ) ;
V_128 = 0 ;
V_39 = F_53 ( 0 , 1ULL << V_142 , NULL ,
F_51 ) ;
F_46 ( & V_129 ) ;
return V_39 ;
}
void F_54 ( void )
{
int V_110 , V_107 ;
F_45 ( & V_129 ) ;
if ( ! V_109 )
goto V_143;
for ( V_110 = 0 ; V_110 < V_114 ; V_110 ++ ) {
if ( ! V_109 -> V_110 [ V_110 ] )
continue;
for ( V_107 = 0 ; V_107 < V_114 ; V_107 ++ ) {
if ( ! V_109 -> V_110 [ V_110 ] -> V_107 [ V_107 ] )
continue;
F_9 ( V_109 -> V_110 [ V_110 ] -> V_107 [ V_107 ] ) ;
}
F_9 ( V_109 -> V_110 [ V_110 ] ) ;
}
F_9 ( V_109 ) ;
V_109 = NULL ;
V_143:
F_46 ( & V_129 ) ;
}
V_7 F_55 ( void * V_144 )
{
int V_110 , V_107 , V_113 ;
unsigned long V_145 , V_146 ;
if ( ! V_109 )
return V_147 ;
V_145 = F_13 ( V_144 ) >> V_148 ;
V_110 = ( V_145 >> V_126 ) & V_105 ;
if ( ! V_109 -> V_110 [ V_110 ] )
return V_147 ;
V_107 = ( V_145 >> V_127 ) & V_105 ;
if ( ! V_109 -> V_110 [ V_110 ] -> V_107 [ V_107 ] )
return V_147 ;
V_113 = V_145 & V_105 ;
if ( ! V_109 -> V_110 [ V_110 ] -> V_107 [ V_107 ] -> V_119 [ V_113 ] )
return V_147 ;
V_146 = ( unsigned long ) V_144 & ( V_120 - 1 ) ;
return V_109 -> V_110 [ V_110 ] -> V_107 [ V_107 ] -> V_119 [ V_113 ] | V_146 ;
}
static inline void * F_56 ( int V_110 , int V_107 , int V_113 )
{
unsigned long V_39 = V_113 ;
V_39 |= V_107 << V_127 ;
V_39 |= V_110 << V_126 ;
return F_57 ( V_39 << V_148 ) ;
}
static V_7 F_58 ( int V_110 , int V_107 , int V_113 , V_7 * V_149 ,
struct V_25 * V_26 ,
struct V_150 * V_151 )
{
void * V_152 ;
V_7 V_153 , V_154 , V_34 ;
unsigned long V_14 = 0 ;
V_7 V_155 = F_13 ( V_149 ) ;
void * V_156 = F_56 ( V_110 , V_107 , V_113 ) ;
for ( V_153 = 0 ; V_153 < ( V_157 / V_158 ) ; V_153 ++ ) {
for ( V_154 = 0 ; V_154 < V_158 ; V_154 ++ ) {
V_152 = V_156 + ( ( V_14 ++ ) * V_8 ) ;
V_149 [ V_154 ] = F_13 ( V_152 ) ;
}
V_34 = F_59 ( V_26 -> V_44 , V_151 -> V_44 , 0 ,
0 , V_155 , V_158 ) ;
if ( ( V_34 != V_46 ) &&
( V_34 != V_52 ) ) {
F_18 ( V_26 -> V_44 , V_151 -> V_44 ,
V_54 ) ;
F_3 ( L_23 ) ;
return V_34 ;
}
}
return V_34 ;
}
static V_7 F_60 ( int V_110 , int V_107 , V_7 * V_149 ,
struct V_25 * V_26 ,
struct V_150 * V_151 )
{
V_7 V_34 = V_46 ;
int V_113 ;
for ( V_113 = 0 ; V_113 < V_114 ; V_113 ++ ) {
if ( ! V_109 -> V_110 [ V_110 ] -> V_107 [ V_107 ] -> V_119 [ V_113 ] )
continue;
V_34 = F_58 ( V_110 , V_107 , V_113 , V_149 , V_26 , V_151 ) ;
if ( ( V_34 != V_46 ) && ( V_34 != V_52 ) )
return V_34 ;
}
return V_34 ;
}
static V_7 F_61 ( int V_110 , V_7 * V_149 ,
struct V_25 * V_26 ,
struct V_150 * V_151 )
{
V_7 V_34 = V_46 ;
int V_107 ;
for ( V_107 = 0 ; V_107 < V_114 ; V_107 ++ ) {
if ( ! V_109 -> V_110 [ V_110 ] -> V_107 [ V_107 ] )
continue;
V_34 = F_60 ( V_110 , V_107 , V_149 , V_26 , V_151 ) ;
if ( ( V_34 != V_46 ) && ( V_34 != V_52 ) )
return V_34 ;
}
return V_34 ;
}
int F_62 ( struct V_25 * V_26 , struct V_150 * V_151 )
{
int V_39 ;
V_7 * V_149 ;
V_7 V_34 ;
T_1 V_159 = V_160 ;
unsigned long V_110 ;
V_149 = ( void * ) F_6 ( V_17 ) ;
if ( ! V_149 ) {
F_3 ( L_24 ) ;
V_39 = - V_18 ;
goto V_161;
}
V_34 = F_63 ( V_26 -> V_44 , V_112 ,
V_128 , V_159 , V_26 -> V_80 ,
& V_151 -> V_44 , & V_151 -> V_162 ) ;
if ( V_34 != V_46 ) {
F_3 ( L_25 ) ;
V_39 = - V_61 ;
goto V_161;
}
if ( ! V_109 ) {
F_18 ( V_26 -> V_44 , V_151 -> V_44 , V_54 ) ;
F_3 ( L_26 ) ;
V_39 = - V_61 ;
goto V_161;
}
for ( V_110 = 0 ; V_110 < V_114 ; V_110 ++ ) {
if ( ! V_109 -> V_110 [ V_110 ] )
continue;
V_34 = F_61 ( V_110 , V_149 , V_26 , V_151 ) ;
if( ( V_34 != V_52 ) && ( V_34 != V_46 ) )
break;
}
if ( V_34 != V_46 ) {
F_18 ( V_26 -> V_44 , V_151 -> V_44 , V_54 ) ;
F_3 ( L_27 ) ;
V_39 = - V_61 ;
goto V_161;
}
V_151 -> V_111 = V_112 ;
V_151 -> V_26 = V_26 ;
V_39 = 0 ;
V_161:
F_7 ( ( unsigned long ) V_149 ) ;
return V_39 ;
}
int F_64 ( struct V_150 * V_151 )
{
V_7 V_34 ;
if ( ! V_151 || ! V_151 -> V_26 )
return - V_15 ;
V_34 = F_18 ( V_151 -> V_26 -> V_44 , V_151 -> V_44 ,
V_54 ) ;
if ( V_34 != V_46 ) {
F_3 ( L_28 ) ;
return - V_61 ;
}
return 0 ;
}
int F_65 ( struct V_25 * V_26 , struct V_150 * V_163 ,
struct V_150 * V_164 )
{
V_7 V_34 ;
V_34 = F_66 ( V_26 -> V_44 , V_163 -> V_44 ,
V_163 -> V_111 , V_160 ,
V_26 -> V_80 , V_164 ) ;
if ( V_34 != V_46 )
return - V_61 ;
V_164 -> V_26 = V_26 ;
return 0 ;
}
void F_67 ( V_7 * V_165 )
{
int V_166 ;
V_7 type = F_68 ( V_167 , V_165 [ 2 ] ) ;
V_7 V_168 = V_165 [ 1 ] ;
V_166 = F_68 ( V_169 , V_165 [ 0 ] ) ;
if ( V_166 > V_8 )
V_166 = V_8 ;
if ( type == V_170 )
F_3 ( L_29 ,
V_168 , V_165 [ 6 ] , V_165 [ 12 ] , V_165 [ 22 ] ) ;
else if ( type == V_171 )
F_3 ( L_30 ,
V_168 , V_165 [ 6 ] ) ;
else if ( type == V_172 )
F_3 ( L_31 ,
V_168 , V_165 [ 6 ] ) ;
F_69 ( V_165 , V_166 , L_32 ) ;
}
V_7 F_22 ( struct V_25 * V_26 , V_7 V_173 ,
V_7 * V_57 , V_7 * V_58 )
{
unsigned long V_39 ;
V_7 * V_174 ;
V_7 type = 0 ;
V_174 = ( void * ) F_6 ( V_17 ) ;
if ( ! V_174 ) {
F_3 ( L_33 ) ;
goto V_161;
}
V_39 = F_70 ( V_26 -> V_44 , V_173 , V_174 ) ;
if ( V_39 == V_46 ) {
type = F_68 ( V_167 , V_174 [ 2 ] ) ;
* V_57 = V_174 [ 6 ] ;
* V_58 = V_174 [ 12 ] ;
F_67 ( V_174 ) ;
} else if ( V_39 == V_60 ) {
F_3 ( L_34 , V_173 ) ;
} else
F_3 ( L_35 , V_173 ) ;
F_7 ( ( unsigned long ) V_174 ) ;
V_161:
return type ;
}

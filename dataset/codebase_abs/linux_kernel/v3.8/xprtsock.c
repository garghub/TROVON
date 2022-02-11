static void F_1 ( char * V_1 , T_1 * V_2 , unsigned int V_3 )
{
T_2 * V_4 = ( T_2 * ) V_2 ;
int V_5 ;
F_2 ( L_1 , V_1 ) ;
for ( V_5 = 0 ; V_5 < V_3 && V_5 < 128 ; V_5 += 4 ) {
if ( ! ( V_5 & 31 ) ) {
if ( V_5 )
F_2 ( L_2 ) ;
F_2 ( L_3 , V_5 ) ;
}
F_2 ( L_4 ,
V_4 [ V_5 ] , V_4 [ V_5 + 1 ] , V_4 [ V_5 + 2 ] , V_4 [ V_5 + 3 ] ) ;
}
F_2 ( L_2 ) ;
}
static inline void F_1 ( char * V_1 , T_1 * V_2 , unsigned int V_3 )
{
}
static inline struct V_6 * F_3 ( struct V_7 * V_8 )
{
return (struct V_6 * ) & V_8 -> V_9 ;
}
static inline struct V_10 * F_4 ( struct V_7 * V_8 )
{
return (struct V_10 * ) & V_8 -> V_9 ;
}
static inline struct V_11 * F_5 ( struct V_7 * V_8 )
{
return (struct V_11 * ) & V_8 -> V_9 ;
}
static inline struct V_12 * F_6 ( struct V_7 * V_8 )
{
return (struct V_12 * ) & V_8 -> V_9 ;
}
static void F_7 ( struct V_7 * V_8 )
{
struct V_6 * V_13 = F_3 ( V_8 ) ;
struct V_12 * V_14 ;
struct V_11 * sin ;
struct V_10 * V_15 ;
char V_4 [ 128 ] ;
switch ( V_13 -> V_16 ) {
case V_17 :
V_15 = F_4 ( V_8 ) ;
F_8 ( V_4 , V_15 -> V_18 , sizeof( V_4 ) ) ;
V_8 -> V_19 [ V_20 ] =
F_9 ( V_4 , V_21 ) ;
break;
case V_22 :
( void ) F_10 ( V_13 , V_4 , sizeof( V_4 ) ) ;
V_8 -> V_19 [ V_20 ] =
F_9 ( V_4 , V_21 ) ;
sin = F_5 ( V_8 ) ;
snprintf ( V_4 , sizeof( V_4 ) , L_5 , F_11 ( sin -> V_23 . V_24 ) ) ;
break;
case V_25 :
( void ) F_10 ( V_13 , V_4 , sizeof( V_4 ) ) ;
V_8 -> V_19 [ V_20 ] =
F_9 ( V_4 , V_21 ) ;
V_14 = F_6 ( V_8 ) ;
snprintf ( V_4 , sizeof( V_4 ) , L_6 , & V_14 -> V_26 ) ;
break;
default:
F_12 () ;
}
V_8 -> V_19 [ V_27 ] = F_9 ( V_4 , V_21 ) ;
}
static void F_13 ( struct V_7 * V_8 )
{
struct V_6 * V_13 = F_3 ( V_8 ) ;
char V_4 [ 128 ] ;
snprintf ( V_4 , sizeof( V_4 ) , L_7 , F_14 ( V_13 ) ) ;
V_8 -> V_19 [ V_28 ] = F_9 ( V_4 , V_21 ) ;
snprintf ( V_4 , sizeof( V_4 ) , L_8 , F_14 ( V_13 ) ) ;
V_8 -> V_19 [ V_29 ] = F_9 ( V_4 , V_21 ) ;
}
static void F_15 ( struct V_7 * V_8 ,
const char * V_30 ,
const char * V_31 )
{
V_8 -> V_19 [ V_32 ] = V_30 ;
V_8 -> V_19 [ V_33 ] = V_31 ;
F_7 ( V_8 ) ;
F_13 ( V_8 ) ;
}
static void F_16 ( struct V_7 * V_8 )
{
F_17 ( V_8 -> V_19 [ V_29 ] ) ;
F_17 ( V_8 -> V_19 [ V_28 ] ) ;
F_13 ( V_8 ) ;
}
static void F_18 ( struct V_7 * V_8 )
{
unsigned int V_34 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ )
switch ( V_34 ) {
case V_32 :
case V_33 :
continue;
default:
F_17 ( V_8 -> V_19 [ V_34 ] ) ;
}
}
static int F_19 ( struct V_36 * V_37 , struct V_6 * V_9 , int V_38 , struct V_39 * V_40 , unsigned int V_41 , int V_42 )
{
struct V_43 V_1 = {
. V_44 = V_9 ,
. V_45 = V_38 ,
. V_46 = V_47 | ( V_42 ? V_48 : 0 ) ,
} ;
struct V_39 V_49 = {
. V_50 = V_40 -> V_50 + V_41 ,
. V_51 = V_40 -> V_51 - V_41 ,
} ;
if ( V_49 . V_51 != 0 )
return F_20 ( V_37 , & V_1 , & V_49 , 1 , V_49 . V_51 ) ;
return F_20 ( V_37 , & V_1 , NULL , 0 , 0 ) ;
}
static int F_21 ( struct V_36 * V_37 , struct V_52 * V_53 , unsigned int V_41 , int V_42 )
{
struct V_54 * * V_55 ;
unsigned int V_56 ;
int V_57 , V_58 = 0 ;
V_56 = V_53 -> V_59 - V_41 ;
V_41 += V_53 -> V_60 ;
V_55 = V_53 -> V_61 + ( V_41 >> V_62 ) ;
V_41 &= ~ V_63 ;
for(; ; ) {
unsigned int V_64 = F_22 (unsigned int, PAGE_SIZE - base, remainder) ;
int V_65 = V_47 ;
V_56 -= V_64 ;
if ( V_56 != 0 || V_42 )
V_65 |= V_48 ;
V_57 = V_37 -> V_66 -> V_67 ( V_37 , * V_55 , V_41 , V_64 , V_65 ) ;
if ( V_56 == 0 || V_57 != V_64 )
break;
V_58 += V_57 ;
V_55 ++ ;
V_41 = 0 ;
}
if ( V_58 == 0 )
return V_57 ;
if ( V_57 > 0 )
V_58 += V_57 ;
return V_58 ;
}
static int F_23 ( struct V_36 * V_37 , struct V_6 * V_9 , int V_38 , struct V_52 * V_53 , unsigned int V_41 )
{
unsigned int V_56 = V_53 -> V_64 - V_41 ;
int V_57 , V_58 = 0 ;
if ( F_24 ( ! V_37 ) )
return - V_68 ;
F_25 ( V_69 , & V_37 -> V_65 ) ;
if ( V_41 != 0 ) {
V_9 = NULL ;
V_38 = 0 ;
}
if ( V_41 < V_53 -> V_70 [ 0 ] . V_51 || V_9 != NULL ) {
unsigned int V_64 = V_53 -> V_70 [ 0 ] . V_51 - V_41 ;
V_56 -= V_64 ;
V_57 = F_19 ( V_37 , V_9 , V_38 , & V_53 -> V_70 [ 0 ] , V_41 , V_56 != 0 ) ;
if ( V_56 == 0 || V_57 != V_64 )
goto V_71;
V_58 += V_57 ;
V_41 = 0 ;
} else
V_41 -= V_53 -> V_70 [ 0 ] . V_51 ;
if ( V_41 < V_53 -> V_59 ) {
unsigned int V_64 = V_53 -> V_59 - V_41 ;
V_56 -= V_64 ;
V_57 = F_21 ( V_37 , V_53 , V_41 , V_56 != 0 ) ;
if ( V_56 == 0 || V_57 != V_64 )
goto V_71;
V_58 += V_57 ;
V_41 = 0 ;
} else
V_41 -= V_53 -> V_59 ;
if ( V_41 >= V_53 -> V_72 [ 0 ] . V_51 )
return V_58 ;
V_57 = F_19 ( V_37 , NULL , 0 , & V_53 -> V_72 [ 0 ] , V_41 , 0 ) ;
V_71:
if ( V_58 == 0 )
return V_57 ;
if ( V_57 > 0 )
V_58 += V_57 ;
return V_58 ;
}
static void F_26 ( struct V_73 * V_74 )
{
struct V_75 * V_76 = F_27 ( V_74 -> V_77 -> V_78 , struct V_75 , V_8 ) ;
V_76 -> V_79 -> V_80 -- ;
F_25 ( V_69 , & V_76 -> V_37 -> V_65 ) ;
}
static int F_28 ( struct V_73 * V_74 )
{
struct V_81 * V_82 = V_74 -> V_77 ;
struct V_7 * V_8 = V_82 -> V_78 ;
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
int V_83 = - V_84 ;
F_2 ( L_9 ,
V_74 -> V_85 , V_82 -> V_86 - V_82 -> V_87 ,
V_82 -> V_86 ) ;
F_29 ( & V_8 -> V_88 ) ;
if ( F_30 ( V_8 ) ) {
if ( F_31 ( V_69 , & V_76 -> V_37 -> V_65 ) ) {
F_32 ( V_89 , & V_76 -> V_37 -> V_65 ) ;
V_76 -> V_79 -> V_80 ++ ;
F_33 ( V_74 , F_26 ) ;
}
} else {
F_25 ( V_69 , & V_76 -> V_37 -> V_65 ) ;
V_83 = - V_90 ;
}
F_34 ( & V_8 -> V_88 ) ;
return V_83 ;
}
static inline void F_35 ( struct V_52 * V_4 )
{
T_1 V_91 = V_4 -> V_64 - sizeof( V_92 ) ;
V_92 * V_41 = V_4 -> V_70 [ 0 ] . V_50 ;
* V_41 = F_36 ( V_93 | V_91 ) ;
}
static int F_37 ( struct V_73 * V_74 )
{
struct V_81 * V_82 = V_74 -> V_77 ;
struct V_7 * V_8 = V_82 -> V_78 ;
struct V_75 * V_76 =
F_27 ( V_8 , struct V_75 , V_8 ) ;
struct V_52 * V_53 = & V_82 -> V_94 ;
int V_95 ;
F_35 ( & V_82 -> V_94 ) ;
F_1 ( L_10 ,
V_82 -> V_96 -> V_50 , V_82 -> V_96 -> V_51 ) ;
V_95 = F_23 ( V_76 -> V_37 , NULL , 0 ,
V_53 , V_82 -> V_87 ) ;
F_2 ( L_11 ,
V_97 , V_53 -> V_64 - V_82 -> V_87 , V_95 ) ;
if ( F_38 ( V_95 >= 0 ) ) {
V_82 -> V_87 += V_95 ;
V_82 -> V_98 += V_95 ;
if ( F_38 ( V_82 -> V_87 >= V_82 -> V_86 ) ) {
V_82 -> V_87 = 0 ;
return 0 ;
}
V_95 = - V_84 ;
}
switch ( V_95 ) {
case - V_84 :
V_95 = F_28 ( V_74 ) ;
break;
default:
F_2 ( L_12 ,
- V_95 ) ;
case - V_99 :
F_39 ( V_8 ) ;
V_95 = - V_90 ;
}
return V_95 ;
}
static int F_40 ( struct V_73 * V_74 )
{
struct V_81 * V_82 = V_74 -> V_77 ;
struct V_7 * V_8 = V_82 -> V_78 ;
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
struct V_52 * V_53 = & V_82 -> V_94 ;
int V_95 ;
F_1 ( L_10 ,
V_82 -> V_96 -> V_50 ,
V_82 -> V_96 -> V_51 ) ;
if ( ! F_41 ( V_8 ) )
return - V_90 ;
V_95 = F_23 ( V_76 -> V_37 ,
F_3 ( V_8 ) ,
V_8 -> V_38 , V_53 ,
V_82 -> V_87 ) ;
F_2 ( L_13 ,
V_53 -> V_64 - V_82 -> V_87 , V_95 ) ;
if ( V_95 >= 0 ) {
V_82 -> V_98 += V_95 ;
if ( V_95 >= V_82 -> V_86 )
return 0 ;
V_95 = - V_84 ;
}
switch ( V_95 ) {
case - V_68 :
V_95 = - V_90 ;
break;
case - V_84 :
V_95 = F_28 ( V_74 ) ;
break;
default:
F_2 ( L_12 ,
- V_95 ) ;
case - V_100 :
case - V_99 :
case - V_101 :
F_25 ( V_69 , & V_76 -> V_37 -> V_65 ) ;
}
return V_95 ;
}
static void F_42 ( struct V_7 * V_8 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
struct V_36 * V_37 = V_76 -> V_37 ;
if ( V_37 != NULL )
F_43 ( V_37 , V_102 ) ;
}
static int F_44 ( struct V_73 * V_74 )
{
struct V_81 * V_82 = V_74 -> V_77 ;
struct V_7 * V_8 = V_82 -> V_78 ;
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
struct V_52 * V_53 = & V_82 -> V_94 ;
int V_95 ;
F_35 ( & V_82 -> V_94 ) ;
F_1 ( L_10 ,
V_82 -> V_96 -> V_50 ,
V_82 -> V_96 -> V_51 ) ;
while ( 1 ) {
V_95 = F_23 ( V_76 -> V_37 ,
NULL , 0 , V_53 , V_82 -> V_87 ) ;
F_2 ( L_14 ,
V_53 -> V_64 - V_82 -> V_87 , V_95 ) ;
if ( F_24 ( V_95 < 0 ) )
break;
V_82 -> V_87 += V_95 ;
V_82 -> V_98 += V_95 ;
if ( F_38 ( V_82 -> V_87 >= V_82 -> V_86 ) ) {
V_82 -> V_87 = 0 ;
return 0 ;
}
if ( V_95 != 0 )
continue;
V_95 = - V_84 ;
break;
}
switch ( V_95 ) {
case - V_68 :
V_95 = - V_90 ;
break;
case - V_84 :
V_95 = F_28 ( V_74 ) ;
break;
default:
F_2 ( L_12 ,
- V_95 ) ;
case - V_103 :
F_42 ( V_8 ) ;
case - V_101 :
case - V_90 :
case - V_99 :
F_25 ( V_69 , & V_76 -> V_37 -> V_65 ) ;
}
return V_95 ;
}
static void F_45 ( struct V_7 * V_8 , struct V_73 * V_74 )
{
struct V_81 * V_82 ;
if ( V_74 != V_8 -> V_104 )
return;
if ( V_74 == NULL )
goto V_105;
V_82 = V_74 -> V_77 ;
if ( V_82 == NULL )
goto V_105;
if ( V_82 -> V_87 == 0 )
goto V_105;
if ( V_82 -> V_87 == V_82 -> V_94 . V_64 )
goto V_105;
F_32 ( V_106 , & V_74 -> V_107 -> V_108 ) ;
V_105:
F_46 ( V_8 , V_74 ) ;
}
static void F_47 ( struct V_75 * V_76 , struct V_37 * V_109 )
{
V_76 -> V_110 = V_109 -> V_111 ;
V_76 -> V_112 = V_109 -> V_113 ;
V_76 -> V_114 = V_109 -> V_115 ;
}
static void F_48 ( struct V_75 * V_76 , struct V_37 * V_109 )
{
V_109 -> V_111 = V_76 -> V_110 ;
V_109 -> V_113 = V_76 -> V_112 ;
V_109 -> V_115 = V_76 -> V_114 ;
}
static void F_49 ( struct V_75 * V_76 )
{
struct V_36 * V_37 = V_76 -> V_37 ;
struct V_37 * V_109 = V_76 -> V_79 ;
if ( V_109 == NULL )
return;
V_76 -> V_116 = 0 ;
F_50 ( & V_109 -> V_117 ) ;
V_76 -> V_79 = NULL ;
V_76 -> V_37 = NULL ;
V_109 -> V_118 = NULL ;
F_48 ( V_76 , V_109 ) ;
F_51 ( & V_109 -> V_117 ) ;
V_109 -> V_119 = 0 ;
F_52 ( V_37 ) ;
}
static void F_39 ( struct V_7 * V_8 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
F_2 ( L_15 , V_8 ) ;
F_49 ( V_76 ) ;
V_8 -> V_120 = 0 ;
F_53 () ;
F_25 ( V_121 , & V_8 -> V_108 ) ;
F_25 ( V_106 , & V_8 -> V_108 ) ;
F_25 ( V_122 , & V_8 -> V_108 ) ;
F_54 () ;
F_55 ( V_8 ) ;
}
static void F_56 ( struct V_7 * V_8 )
{
if ( F_57 ( V_123 , & V_8 -> V_108 ) )
F_39 ( V_8 ) ;
else
F_42 ( V_8 ) ;
}
static void F_58 ( struct V_7 * V_8 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
F_2 ( L_16 , V_8 ) ;
F_59 ( & V_76 -> V_124 ) ;
F_39 ( V_8 ) ;
F_18 ( V_8 ) ;
F_60 ( V_8 ) ;
F_61 ( V_125 ) ;
}
static inline struct V_7 * F_62 ( struct V_37 * V_109 )
{
return (struct V_7 * ) V_109 -> V_118 ;
}
static int F_63 ( struct V_52 * V_53 , struct V_126 * V_127 )
{
struct V_128 V_129 = {
. V_127 = V_127 ,
. V_130 = sizeof( V_92 ) ,
. V_3 = V_127 -> V_64 - sizeof( V_92 ) ,
} ;
if ( F_64 ( V_53 , 0 , & V_129 , V_131 ) < 0 )
return - 1 ;
if ( V_129 . V_3 )
return - 1 ;
return 0 ;
}
static void F_65 ( struct V_37 * V_109 , int V_64 )
{
struct V_73 * V_74 ;
struct V_7 * V_8 ;
struct V_81 * V_132 ;
struct V_126 * V_127 ;
int V_57 , V_133 , V_134 ;
T_1 V_135 ;
T_3 * V_136 ;
F_66 ( & V_109 -> V_117 ) ;
F_2 ( L_17 , V_97 ) ;
V_8 = F_62 ( V_109 ) ;
if ( V_8 == NULL )
goto V_71;
V_127 = F_67 ( V_109 , 0 , 1 , & V_57 ) ;
if ( V_127 == NULL )
goto V_71;
V_133 = V_127 -> V_64 - sizeof( V_92 ) ;
if ( V_133 < 4 ) {
F_2 ( L_18 , V_133 ) ;
goto V_137;
}
V_136 = F_68 ( V_127 , sizeof( V_92 ) , sizeof( V_135 ) , & V_135 ) ;
if ( V_136 == NULL )
goto V_137;
F_69 ( & V_8 -> V_88 ) ;
V_132 = F_70 ( V_8 , * V_136 ) ;
if ( ! V_132 )
goto V_138;
V_74 = V_132 -> V_139 ;
V_134 = V_132 -> V_140 . V_141 ;
if ( V_134 > V_133 )
V_134 = V_133 ;
if ( F_63 ( & V_132 -> V_140 , V_127 ) ) {
F_2 ( L_19 ) ;
goto V_138;
}
F_71 ( V_74 , V_134 ) ;
V_138:
F_72 ( & V_8 -> V_88 ) ;
V_137:
F_73 ( V_109 , V_127 ) ;
V_71:
F_74 ( & V_109 -> V_117 ) ;
}
static void F_75 ( struct V_37 * V_109 , int V_64 )
{
struct V_73 * V_74 ;
struct V_7 * V_8 ;
struct V_81 * V_132 ;
struct V_126 * V_127 ;
int V_57 , V_133 , V_134 ;
T_1 V_135 ;
T_3 * V_136 ;
F_66 ( & V_109 -> V_117 ) ;
F_2 ( L_20 ) ;
if ( ! ( V_8 = F_62 ( V_109 ) ) )
goto V_71;
if ( ( V_127 = F_67 ( V_109 , 0 , 1 , & V_57 ) ) == NULL )
goto V_71;
V_133 = V_127 -> V_64 - sizeof( struct V_142 ) ;
if ( V_133 < 4 ) {
F_2 ( L_21 , V_133 ) ;
goto V_137;
}
V_136 = F_68 ( V_127 , sizeof( struct V_142 ) ,
sizeof( V_135 ) , & V_135 ) ;
if ( V_136 == NULL )
goto V_137;
F_69 ( & V_8 -> V_88 ) ;
V_132 = F_70 ( V_8 , * V_136 ) ;
if ( ! V_132 )
goto V_138;
V_74 = V_132 -> V_139 ;
if ( ( V_134 = V_132 -> V_140 . V_141 ) > V_133 )
V_134 = V_133 ;
if ( F_76 ( & V_132 -> V_140 , V_127 ) ) {
F_77 ( V_109 , V_143 ) ;
goto V_138;
}
F_77 ( V_109 , V_144 ) ;
F_78 ( V_74 , V_134 ) ;
F_71 ( V_74 , V_134 ) ;
V_138:
F_72 ( & V_8 -> V_88 ) ;
V_137:
F_73 ( V_109 , V_127 ) ;
V_71:
F_74 ( & V_109 -> V_117 ) ;
}
static void F_79 ( struct V_7 * V_8 )
{
F_32 ( V_123 , & V_8 -> V_108 ) ;
F_80 ( V_8 ) ;
}
static inline void F_81 ( struct V_7 * V_8 , struct V_128 * V_129 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
T_4 V_64 , V_145 ;
char * V_146 ;
V_146 = ( ( char * ) & V_76 -> V_147 ) + V_76 -> V_148 ;
V_64 = sizeof( V_76 -> V_147 ) - V_76 -> V_148 ;
V_145 = V_131 ( V_129 , V_146 , V_64 ) ;
V_76 -> V_148 += V_145 ;
if ( V_145 != V_64 )
return;
V_76 -> V_149 = F_11 ( V_76 -> V_147 ) ;
if ( V_76 -> V_149 & V_93 )
V_76 -> V_150 |= V_151 ;
else
V_76 -> V_150 &= ~ V_151 ;
V_76 -> V_149 &= V_152 ;
V_76 -> V_150 &= ~ V_153 ;
V_76 -> V_148 = 0 ;
if ( F_24 ( V_76 -> V_149 < 8 ) ) {
F_2 ( L_22 ) ;
F_79 ( V_8 ) ;
return;
}
F_2 ( L_23 ,
V_76 -> V_149 ) ;
}
static void F_82 ( struct V_75 * V_76 )
{
if ( V_76 -> V_148 == V_76 -> V_149 ) {
V_76 -> V_150 |= V_153 ;
V_76 -> V_148 = 0 ;
if ( V_76 -> V_150 & V_151 ) {
V_76 -> V_150 &= ~ V_154 ;
V_76 -> V_150 |= V_155 ;
V_76 -> V_156 = 0 ;
}
}
}
static inline void F_83 ( struct V_75 * V_76 , struct V_128 * V_129 )
{
T_4 V_64 , V_145 ;
char * V_146 ;
V_64 = sizeof( V_76 -> V_157 ) - V_76 -> V_148 ;
F_2 ( L_24 , V_64 ) ;
V_146 = ( ( char * ) & V_76 -> V_157 ) + V_76 -> V_148 ;
V_145 = V_131 ( V_129 , V_146 , V_64 ) ;
V_76 -> V_148 += V_145 ;
if ( V_145 != V_64 )
return;
V_76 -> V_150 &= ~ V_155 ;
V_76 -> V_150 |= V_158 ;
V_76 -> V_156 = 4 ;
F_2 ( L_25 ,
( V_76 -> V_150 & V_159 ) ? L_26
: L_27 ,
F_11 ( V_76 -> V_157 ) ) ;
F_82 ( V_76 ) ;
}
static inline void F_84 ( struct V_75 * V_76 ,
struct V_128 * V_129 )
{
T_4 V_64 , V_145 ;
T_1 V_130 ;
char * V_146 ;
V_130 = V_76 -> V_148 - sizeof( V_76 -> V_157 ) ;
V_64 = sizeof( V_76 -> V_160 ) - V_130 ;
F_2 ( L_28 , V_64 ) ;
V_146 = ( ( char * ) & V_76 -> V_160 ) + V_130 ;
V_145 = V_131 ( V_129 , V_146 , V_64 ) ;
V_76 -> V_148 += V_145 ;
if ( V_145 != V_64 )
return;
V_76 -> V_150 &= ~ V_158 ;
switch ( F_11 ( V_76 -> V_160 ) ) {
case V_161 :
V_76 -> V_150 |= V_162 ;
V_76 -> V_150 |= V_154 ;
V_76 -> V_150 |= V_159 ;
break;
case V_163 :
V_76 -> V_150 |= V_162 ;
V_76 -> V_150 |= V_154 ;
V_76 -> V_150 &= ~ V_159 ;
break;
default:
F_2 ( L_29 ) ;
F_79 ( & V_76 -> V_8 ) ;
}
F_82 ( V_76 ) ;
}
static inline void F_85 ( struct V_7 * V_8 ,
struct V_128 * V_129 ,
struct V_81 * V_82 )
{
struct V_75 * V_76 =
F_27 ( V_8 , struct V_75 , V_8 ) ;
struct V_52 * V_164 ;
T_4 V_64 ;
T_5 V_165 ;
V_164 = & V_82 -> V_140 ;
if ( V_76 -> V_150 & V_162 ) {
memcpy ( V_164 -> V_70 [ 0 ] . V_50 + V_76 -> V_156 ,
& V_76 -> V_160 ,
sizeof( V_76 -> V_160 ) ) ;
V_76 -> V_156 += sizeof( V_76 -> V_160 ) ;
V_76 -> V_150 &= ~ V_162 ;
}
V_64 = V_129 -> V_3 ;
if ( V_64 > V_76 -> V_149 - V_76 -> V_148 ) {
struct V_128 V_166 ;
V_64 = V_76 -> V_149 - V_76 -> V_148 ;
memcpy ( & V_166 , V_129 , sizeof( V_166 ) ) ;
V_166 . V_3 = V_64 ;
V_165 = F_64 ( V_164 , V_76 -> V_156 ,
& V_166 , V_131 ) ;
V_129 -> V_3 -= V_165 ;
V_129 -> V_130 += V_165 ;
} else
V_165 = F_64 ( V_164 , V_76 -> V_156 ,
V_129 , V_131 ) ;
if ( V_165 > 0 ) {
V_76 -> V_156 += V_165 ;
V_76 -> V_148 += V_165 ;
}
if ( V_165 != V_64 ) {
V_76 -> V_150 &= ~ V_154 ;
F_2 ( L_30 ,
F_11 ( V_76 -> V_157 ) ) ;
F_2 ( L_31
L_32 ,
V_8 , V_76 -> V_156 ,
V_76 -> V_148 , V_76 -> V_149 ) ;
return;
}
F_2 ( L_33 ,
F_11 ( V_76 -> V_157 ) , V_165 ) ;
F_2 ( L_34
L_35 , V_8 , V_76 -> V_156 ,
V_76 -> V_148 , V_76 -> V_149 ) ;
if ( V_76 -> V_156 == V_82 -> V_140 . V_141 )
V_76 -> V_150 &= ~ V_154 ;
else if ( V_76 -> V_148 == V_76 -> V_149 ) {
if ( V_76 -> V_150 & V_151 )
V_76 -> V_150 &= ~ V_154 ;
}
}
static inline int F_86 ( struct V_7 * V_8 ,
struct V_128 * V_129 )
{
struct V_75 * V_76 =
F_27 ( V_8 , struct V_75 , V_8 ) ;
struct V_81 * V_82 ;
F_2 ( L_36 , F_11 ( V_76 -> V_157 ) ) ;
F_69 ( & V_8 -> V_88 ) ;
V_82 = F_70 ( V_8 , V_76 -> V_157 ) ;
if ( ! V_82 ) {
F_2 ( L_37 ,
F_11 ( V_76 -> V_157 ) ) ;
F_72 ( & V_8 -> V_88 ) ;
return - 1 ;
}
F_85 ( V_8 , V_129 , V_82 ) ;
if ( ! ( V_76 -> V_150 & V_154 ) )
F_71 ( V_82 -> V_139 , V_76 -> V_156 ) ;
F_72 ( & V_8 -> V_88 ) ;
return 0 ;
}
static inline int F_87 ( struct V_7 * V_8 ,
struct V_128 * V_129 )
{
struct V_75 * V_76 =
F_27 ( V_8 , struct V_75 , V_8 ) ;
struct V_81 * V_82 ;
V_82 = F_88 ( V_8 ) ;
if ( V_82 == NULL ) {
F_89 ( V_167 L_38 ) ;
F_80 ( V_8 ) ;
return - 1 ;
}
V_82 -> V_168 = V_76 -> V_157 ;
F_2 ( L_39 , F_11 ( V_82 -> V_168 ) ) ;
F_85 ( V_8 , V_129 , V_82 ) ;
if ( ! ( V_76 -> V_150 & V_154 ) ) {
struct V_169 * V_170 = V_8 -> V_170 ;
F_2 ( L_40 ) ;
F_69 ( & V_170 -> V_171 ) ;
F_90 ( & V_82 -> V_172 , & V_170 -> V_173 ) ;
F_72 ( & V_170 -> V_171 ) ;
F_91 ( & V_170 -> V_174 ) ;
}
V_82 -> V_140 . V_64 = V_76 -> V_156 ;
return 0 ;
}
static inline int F_92 ( struct V_7 * V_8 ,
struct V_128 * V_129 )
{
struct V_75 * V_76 =
F_27 ( V_8 , struct V_75 , V_8 ) ;
return ( V_76 -> V_150 & V_159 ) ?
F_86 ( V_8 , V_129 ) :
F_87 ( V_8 , V_129 ) ;
}
static inline int F_92 ( struct V_7 * V_8 ,
struct V_128 * V_129 )
{
return F_86 ( V_8 , V_129 ) ;
}
static void F_93 ( struct V_7 * V_8 ,
struct V_128 * V_129 )
{
struct V_75 * V_76 =
F_27 ( V_8 , struct V_75 , V_8 ) ;
if ( F_92 ( V_8 , V_129 ) == 0 )
F_82 ( V_76 ) ;
else {
V_76 -> V_150 &= ~ V_154 ;
}
}
static inline void F_94 ( struct V_75 * V_76 , struct V_128 * V_129 )
{
T_4 V_64 ;
V_64 = V_76 -> V_149 - V_76 -> V_148 ;
if ( V_64 > V_129 -> V_3 )
V_64 = V_129 -> V_3 ;
V_129 -> V_3 -= V_64 ;
V_129 -> V_130 += V_64 ;
V_76 -> V_148 += V_64 ;
F_2 ( L_41 , V_64 ) ;
F_82 ( V_76 ) ;
}
static int F_95 ( T_6 * V_175 , struct V_126 * V_127 , unsigned int V_130 , T_4 V_64 )
{
struct V_7 * V_8 = V_175 -> V_176 . V_177 ;
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
struct V_128 V_129 = {
. V_127 = V_127 ,
. V_130 = V_130 ,
. V_3 = V_64 ,
} ;
F_2 ( L_42 ) ;
do {
if ( V_76 -> V_150 & V_153 ) {
F_81 ( V_8 , & V_129 ) ;
continue;
}
if ( V_76 -> V_150 & V_155 ) {
F_83 ( V_76 , & V_129 ) ;
continue;
}
if ( V_76 -> V_150 & V_158 ) {
F_84 ( V_76 , & V_129 ) ;
continue;
}
if ( V_76 -> V_150 & V_154 ) {
F_93 ( V_8 , & V_129 ) ;
continue;
}
F_94 ( V_76 , & V_129 ) ;
} while ( V_129 . V_3 );
F_2 ( L_43 ) ;
return V_64 - V_129 . V_3 ;
}
static void F_96 ( struct V_37 * V_109 , int V_178 )
{
struct V_7 * V_8 ;
T_6 V_175 ;
int V_179 ;
F_2 ( L_44 ) ;
F_66 ( & V_109 -> V_117 ) ;
if ( ! ( V_8 = F_62 ( V_109 ) ) )
goto V_71;
if ( V_8 -> V_120 )
V_8 -> V_120 = 0 ;
V_175 . V_176 . V_177 = V_8 ;
do {
V_175 . V_3 = 65536 ;
V_179 = F_97 ( V_109 , & V_175 , F_95 ) ;
} while ( V_179 > 0 );
V_71:
F_74 ( & V_109 -> V_117 ) ;
}
static void F_98 ( struct V_7 * V_8 ,
unsigned long V_180 )
{
struct V_75 * V_76 ;
if ( F_99 ( V_8 ) )
return;
F_32 ( V_121 , & V_8 -> V_108 ) ;
V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
F_100 ( V_181 , & V_76 -> V_124 ,
V_180 ) ;
}
static void F_101 ( struct V_7 * V_8 )
{
struct V_75 * V_76 ;
V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
if ( ! F_31 ( V_121 , & V_8 -> V_108 ) ||
! F_102 ( & V_76 -> V_124 ) )
return;
F_25 ( V_121 , & V_8 -> V_108 ) ;
F_103 ( V_8 ) ;
}
static void F_104 ( struct V_7 * V_8 )
{
F_53 () ;
F_25 ( V_121 , & V_8 -> V_108 ) ;
F_25 ( V_123 , & V_8 -> V_108 ) ;
F_25 ( V_106 , & V_8 -> V_108 ) ;
F_25 ( V_122 , & V_8 -> V_108 ) ;
F_54 () ;
}
static void F_105 ( struct V_7 * V_8 )
{
F_104 ( V_8 ) ;
F_55 ( V_8 ) ;
}
static void F_106 ( struct V_37 * V_109 )
{
struct V_7 * V_8 ;
F_66 ( & V_109 -> V_117 ) ;
if ( ! ( V_8 = F_62 ( V_109 ) ) )
goto V_71;
F_2 ( L_45 , V_8 ) ;
F_2 ( L_46 ,
V_109 -> V_182 , F_30 ( V_8 ) ,
F_107 ( V_109 , V_183 ) ,
F_107 ( V_109 , V_184 ) ,
V_109 -> V_185 ) ;
switch ( V_109 -> V_182 ) {
case V_186 :
F_69 ( & V_8 -> V_88 ) ;
if ( ! F_108 ( V_8 ) ) {
struct V_75 * V_76 = F_27 ( V_8 ,
struct V_75 , V_8 ) ;
V_76 -> V_148 = 0 ;
V_76 -> V_149 = 0 ;
V_76 -> V_156 = 0 ;
V_76 -> V_150 =
V_153 | V_155 ;
F_109 ( V_8 , - V_84 ) ;
}
F_72 ( & V_8 -> V_88 ) ;
break;
case V_187 :
V_8 -> V_188 ++ ;
V_8 -> V_120 = 0 ;
F_32 ( V_122 , & V_8 -> V_108 ) ;
F_53 () ;
F_25 ( V_189 , & V_8 -> V_108 ) ;
F_25 ( V_106 , & V_8 -> V_108 ) ;
F_54 () ;
F_98 ( V_8 , V_190 ) ;
break;
case V_191 :
V_8 -> V_188 ++ ;
F_25 ( V_189 , & V_8 -> V_108 ) ;
F_79 ( V_8 ) ;
case V_192 :
if ( V_8 -> V_120 < V_193 )
V_8 -> V_120 = V_193 ;
break;
case V_194 :
F_32 ( V_122 , & V_8 -> V_108 ) ;
F_98 ( V_8 , V_190 ) ;
F_53 () ;
F_25 ( V_189 , & V_8 -> V_108 ) ;
F_54 () ;
break;
case V_195 :
F_101 ( V_8 ) ;
F_105 ( V_8 ) ;
}
V_71:
F_74 ( & V_109 -> V_117 ) ;
}
static void F_110 ( struct V_37 * V_109 )
{
struct V_36 * V_37 ;
struct V_7 * V_8 ;
if ( F_24 ( ! ( V_37 = V_109 -> V_196 ) ) )
return;
F_25 ( V_89 , & V_37 -> V_65 ) ;
if ( F_24 ( ! ( V_8 = F_62 ( V_109 ) ) ) )
return;
if ( F_57 ( V_69 , & V_37 -> V_65 ) == 0 )
return;
F_111 ( V_8 ) ;
}
static void F_112 ( struct V_37 * V_109 )
{
F_66 ( & V_109 -> V_117 ) ;
if ( F_113 ( V_109 ) )
F_110 ( V_109 ) ;
F_74 ( & V_109 -> V_117 ) ;
}
static void F_114 ( struct V_37 * V_109 )
{
F_66 ( & V_109 -> V_117 ) ;
if ( F_115 ( V_109 ) >= F_116 ( V_109 ) )
F_110 ( V_109 ) ;
F_74 ( & V_109 -> V_117 ) ;
}
static void F_117 ( struct V_7 * V_8 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
struct V_37 * V_109 = V_76 -> V_79 ;
if ( V_76 -> V_197 ) {
V_109 -> V_198 |= V_199 ;
V_109 -> V_200 = V_76 -> V_197 * V_8 -> V_201 * 2 ;
}
if ( V_76 -> V_202 ) {
V_109 -> V_198 |= V_203 ;
V_109 -> V_204 = V_76 -> V_202 * V_8 -> V_201 * 2 ;
V_109 -> V_115 ( V_109 ) ;
}
}
static void F_118 ( struct V_7 * V_8 , T_4 V_202 , T_4 V_197 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
V_76 -> V_202 = 0 ;
if ( V_202 )
V_76 -> V_202 = V_202 + 1024 ;
V_76 -> V_197 = 0 ;
if ( V_197 )
V_76 -> V_197 = V_197 + 1024 ;
F_117 ( V_8 ) ;
}
static void F_119 ( struct V_73 * V_74 )
{
F_78 ( V_74 , - V_205 ) ;
}
static unsigned short F_120 ( void )
{
unsigned short V_206 = V_207 - V_208 ;
unsigned short rand = ( unsigned short ) F_121 () % V_206 ;
return rand + V_208 ;
}
static void F_122 ( struct V_7 * V_8 , unsigned short V_209 )
{
F_2 ( L_47 , V_8 , V_209 ) ;
F_123 ( F_3 ( V_8 ) , V_209 ) ;
F_16 ( V_8 ) ;
}
static unsigned short F_124 ( struct V_75 * V_76 )
{
unsigned short V_209 = V_76 -> V_116 ;
if ( V_209 == 0 && V_76 -> V_8 . V_210 )
V_209 = F_120 () ;
return V_209 ;
}
static unsigned short F_125 ( struct V_75 * V_76 , unsigned short V_209 )
{
if ( V_76 -> V_116 != 0 )
V_76 -> V_116 = 0 ;
if ( ! V_76 -> V_8 . V_210 )
return 0 ;
if ( V_209 <= V_208 || V_209 > V_207 )
return V_207 ;
return -- V_209 ;
}
static int F_126 ( struct V_75 * V_76 , struct V_36 * V_37 )
{
struct V_211 V_212 ;
int V_57 , V_213 = 0 ;
unsigned short V_209 = F_124 ( V_76 ) ;
unsigned short V_214 ;
memcpy ( & V_212 , & V_76 -> V_215 , V_76 -> V_8 . V_38 ) ;
do {
F_123 ( (struct V_6 * ) & V_212 , V_209 ) ;
V_57 = F_127 ( V_37 , (struct V_6 * ) & V_212 ,
V_76 -> V_8 . V_38 ) ;
if ( V_209 == 0 )
break;
if ( V_57 == 0 ) {
V_76 -> V_116 = V_209 ;
break;
}
V_214 = V_209 ;
V_209 = F_125 ( V_76 , V_209 ) ;
if ( V_209 > V_214 )
V_213 ++ ;
} while ( V_57 == - V_216 && V_213 != 2 );
if ( V_212 . V_217 == V_22 )
F_2 ( L_48 , V_97 ,
& ( (struct V_11 * ) & V_212 ) -> V_23 ,
V_209 , V_57 ? L_49 : L_50 , V_57 ) ;
else
F_2 ( L_51 , V_97 ,
& ( (struct V_12 * ) & V_212 ) -> V_26 ,
V_209 , V_57 ? L_49 : L_50 , V_57 ) ;
return V_57 ;
}
static void F_128 ( struct V_73 * V_74 )
{
F_129 ( V_74 -> V_107 ) ;
}
static void F_130 ( struct V_7 * V_8 , unsigned short V_209 )
{
}
static inline void F_131 ( struct V_36 * V_37 )
{
struct V_37 * V_109 = V_37 -> V_109 ;
F_132 ( V_109 , L_52 ,
& V_218 [ 1 ] , L_53 , & V_219 [ 1 ] ) ;
}
static inline void F_133 ( struct V_36 * V_37 )
{
struct V_37 * V_109 = V_37 -> V_109 ;
F_132 ( V_109 , L_54 ,
& V_218 [ 0 ] , L_55 , & V_219 [ 0 ] ) ;
}
static inline void F_134 ( struct V_36 * V_37 )
{
struct V_37 * V_109 = V_37 -> V_109 ;
F_132 ( V_109 , L_56 ,
& V_218 [ 1 ] , L_57 , & V_219 [ 1 ] ) ;
}
static inline void F_135 ( int V_220 , struct V_36 * V_37 )
{
F_136 ( F_137 ( V_37 -> V_109 ) ) ;
if ( F_137 ( V_37 -> V_109 ) )
return;
switch ( V_220 ) {
case V_17 :
F_131 ( V_37 ) ;
break;
case V_22 :
F_133 ( V_37 ) ;
break;
case V_25 :
F_134 ( V_37 ) ;
break;
}
}
static inline void F_131 ( struct V_36 * V_37 )
{
}
static inline void F_133 ( struct V_36 * V_37 )
{
}
static inline void F_134 ( struct V_36 * V_37 )
{
}
static inline void F_135 ( int V_220 , struct V_36 * V_37 )
{
}
static struct V_36 * F_138 ( struct V_7 * V_8 ,
struct V_75 * V_76 , int V_220 , int type , int V_30 )
{
struct V_36 * V_37 ;
int V_57 ;
V_57 = F_139 ( V_8 -> V_221 , V_220 , type , V_30 , & V_37 , 1 ) ;
if ( V_57 < 0 ) {
F_2 ( L_58 ,
V_30 , - V_57 ) ;
goto V_71;
}
F_135 ( V_220 , V_37 ) ;
V_57 = F_126 ( V_76 , V_37 ) ;
if ( V_57 ) {
F_52 ( V_37 ) ;
goto V_71;
}
return V_37 ;
V_71:
return F_140 ( V_57 ) ;
}
static int F_141 ( struct V_7 * V_8 ,
struct V_36 * V_37 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 ,
V_8 ) ;
if ( ! V_76 -> V_79 ) {
struct V_37 * V_109 = V_37 -> V_109 ;
F_50 ( & V_109 -> V_117 ) ;
F_47 ( V_76 , V_109 ) ;
V_109 -> V_118 = V_8 ;
V_109 -> V_111 = F_65 ;
V_109 -> V_115 = F_112 ;
V_109 -> V_222 = V_223 ;
F_142 ( V_8 ) ;
V_76 -> V_37 = V_37 ;
V_76 -> V_79 = V_109 ;
F_51 ( & V_109 -> V_117 ) ;
}
V_8 -> V_224 . V_225 ++ ;
V_8 -> V_224 . V_226 = V_227 ;
return F_143 ( V_37 , F_3 ( V_8 ) , V_8 -> V_38 , 0 ) ;
}
static void F_144 ( struct V_228 * V_229 )
{
struct V_75 * V_76 =
F_27 ( V_229 , struct V_75 , V_124 . V_229 ) ;
struct V_7 * V_8 = & V_76 -> V_8 ;
struct V_36 * V_37 ;
int V_95 = - V_230 ;
V_231 -> V_65 |= V_232 ;
F_25 ( V_121 , & V_8 -> V_108 ) ;
V_95 = F_139 ( V_8 -> V_221 , V_17 ,
V_233 , 0 , & V_37 , 1 ) ;
if ( V_95 < 0 ) {
F_2 ( L_59
L_60 , - V_95 ) ;
goto V_71;
}
F_131 ( V_37 ) ;
F_2 ( L_61 ,
V_8 , V_8 -> V_19 [ V_20 ] ) ;
V_95 = F_141 ( V_8 , V_37 ) ;
switch ( V_95 ) {
case 0 :
F_2 ( L_62 ,
V_8 , V_8 -> V_19 [ V_20 ] ) ;
F_145 ( V_8 ) ;
break;
case - V_234 :
F_2 ( L_63 ,
V_8 , V_8 -> V_19 [ V_20 ] ) ;
break;
case - V_101 :
F_2 ( L_64 ,
V_8 , V_8 -> V_19 [ V_20 ] ) ;
break;
default:
F_89 ( V_235 L_65 ,
V_97 , - V_95 ,
V_8 -> V_19 [ V_20 ] ) ;
}
V_71:
F_103 ( V_8 ) ;
F_109 ( V_8 , V_95 ) ;
V_231 -> V_65 &= ~ V_232 ;
}
static void F_146 ( struct V_7 * V_8 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 ,
V_8 ) ;
if ( V_8 -> V_236 )
F_147 ( V_76 -> V_79 ) ;
}
int F_148 ( struct V_7 * V_8 , int V_237 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 ,
V_8 ) ;
int V_57 = 0 ;
if ( V_237 ) {
V_8 -> V_236 ++ ;
F_146 ( V_8 ) ;
} else if ( V_8 -> V_236 ) {
V_8 -> V_236 -- ;
F_149 ( V_76 -> V_79 ) ;
}
return V_57 ;
}
static void F_146 ( struct V_7 * V_8 )
{
}
static void F_150 ( struct V_7 * V_8 , struct V_36 * V_37 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
if ( ! V_76 -> V_79 ) {
struct V_37 * V_109 = V_37 -> V_109 ;
F_50 ( & V_109 -> V_117 ) ;
F_47 ( V_76 , V_109 ) ;
V_109 -> V_118 = V_8 ;
V_109 -> V_111 = F_75 ;
V_109 -> V_115 = F_112 ;
V_109 -> V_119 = V_238 ;
V_109 -> V_222 = V_223 ;
F_145 ( V_8 ) ;
V_76 -> V_37 = V_37 ;
V_76 -> V_79 = V_109 ;
F_146 ( V_8 ) ;
F_51 ( & V_109 -> V_117 ) ;
}
F_117 ( V_8 ) ;
}
static void F_151 ( struct V_228 * V_229 )
{
struct V_75 * V_76 =
F_27 ( V_229 , struct V_75 , V_124 . V_229 ) ;
struct V_7 * V_8 = & V_76 -> V_8 ;
struct V_36 * V_37 = V_76 -> V_37 ;
int V_95 = - V_230 ;
V_231 -> V_65 |= V_232 ;
F_49 ( V_76 ) ;
V_37 = F_138 ( V_8 , V_76 ,
F_3 ( V_8 ) -> V_16 , V_239 , V_240 ) ;
if ( F_152 ( V_37 ) )
goto V_71;
F_2 ( L_66
L_67 , V_8 ,
V_8 -> V_19 [ V_32 ] ,
V_8 -> V_19 [ V_20 ] ,
V_8 -> V_19 [ V_28 ] ) ;
F_150 ( V_8 , V_37 ) ;
V_95 = 0 ;
V_71:
F_103 ( V_8 ) ;
F_109 ( V_8 , V_95 ) ;
V_231 -> V_65 &= ~ V_232 ;
}
static void F_153 ( struct V_75 * V_76 )
{
int V_241 ;
struct V_6 V_242 ;
F_2 ( L_68 , V_76 ) ;
memset ( & V_242 , 0 , sizeof( V_242 ) ) ;
V_242 . V_16 = V_243 ;
V_241 = F_143 ( V_76 -> V_37 , & V_242 , sizeof( V_242 ) , 0 ) ;
if ( ! V_241 )
F_104 ( & V_76 -> V_8 ) ;
F_2 ( L_69 , V_241 ) ;
}
static void F_154 ( struct V_75 * V_76 )
{
unsigned int V_108 = V_76 -> V_79 -> V_182 ;
if ( V_108 == V_195 && V_76 -> V_37 -> V_108 == V_244 ) {
if ( V_76 -> V_79 -> V_185 == 0 )
return;
F_2 ( L_70 ,
V_97 , V_76 -> V_79 -> V_185 ) ;
}
if ( ( 1 << V_108 ) & ( V_245 | V_246 ) ) {
if ( V_76 -> V_79 -> V_185 == 0 )
return;
F_2 ( L_71
L_72 ,
V_97 , V_76 -> V_79 -> V_185 ) ;
}
F_153 ( V_76 ) ;
}
static int F_155 ( struct V_7 * V_8 , struct V_36 * V_37 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
int V_83 = - V_90 ;
if ( ! V_76 -> V_79 ) {
struct V_37 * V_109 = V_37 -> V_109 ;
F_50 ( & V_109 -> V_117 ) ;
F_47 ( V_76 , V_109 ) ;
V_109 -> V_118 = V_8 ;
V_109 -> V_111 = F_96 ;
V_109 -> V_113 = F_106 ;
V_109 -> V_115 = F_114 ;
V_109 -> V_222 = V_223 ;
V_109 -> V_198 |= V_247 ;
F_156 ( V_109 , V_248 ) ;
F_157 ( V_109 ) -> V_249 = 0 ;
F_157 ( V_109 ) -> V_250 |= V_251 ;
F_142 ( V_8 ) ;
V_76 -> V_37 = V_37 ;
V_76 -> V_79 = V_109 ;
F_51 ( & V_109 -> V_117 ) ;
}
if ( ! F_41 ( V_8 ) )
goto V_71;
F_146 ( V_8 ) ;
V_8 -> V_224 . V_225 ++ ;
V_8 -> V_224 . V_226 = V_227 ;
V_83 = F_143 ( V_37 , F_3 ( V_8 ) , V_8 -> V_38 , V_252 ) ;
switch ( V_83 ) {
case 0 :
case - V_253 :
V_8 -> V_188 ++ ;
if ( V_8 -> V_120 < V_193 )
V_8 -> V_120 = V_193 ;
}
V_71:
return V_83 ;
}
static void F_158 ( struct V_228 * V_229 )
{
struct V_75 * V_76 =
F_27 ( V_229 , struct V_75 , V_124 . V_229 ) ;
struct V_36 * V_37 = V_76 -> V_37 ;
struct V_7 * V_8 = & V_76 -> V_8 ;
int V_95 = - V_230 ;
V_231 -> V_65 |= V_232 ;
if ( ! V_37 ) {
F_25 ( V_121 , & V_8 -> V_108 ) ;
V_37 = F_138 ( V_8 , V_76 ,
F_3 ( V_8 ) -> V_16 , V_233 , V_254 ) ;
if ( F_152 ( V_37 ) ) {
V_95 = F_159 ( V_37 ) ;
goto V_71;
}
} else {
int V_255 ;
V_255 = F_57 ( V_121 ,
& V_8 -> V_108 ) ;
F_154 ( V_76 ) ;
if ( V_255 )
goto V_256;
}
F_2 ( L_66
L_67 , V_8 ,
V_8 -> V_19 [ V_32 ] ,
V_8 -> V_19 [ V_20 ] ,
V_8 -> V_19 [ V_28 ] ) ;
V_95 = F_155 ( V_8 , V_37 ) ;
F_2 ( L_73 ,
V_8 , - V_95 , F_30 ( V_8 ) ,
V_37 -> V_109 -> V_182 ) ;
switch ( V_95 ) {
default:
F_89 ( L_74 ,
V_97 , V_95 ) ;
case - V_257 :
F_79 ( V_8 ) ;
break;
case - V_101 :
case - V_103 :
case - V_100 :
case 0 :
case - V_253 :
case - V_258 :
F_103 ( V_8 ) ;
V_231 -> V_65 &= ~ V_232 ;
return;
case - V_259 :
goto V_71;
}
V_256:
V_95 = - V_84 ;
V_71:
F_103 ( V_8 ) ;
F_109 ( V_8 , V_95 ) ;
V_231 -> V_65 &= ~ V_232 ;
}
static void F_160 ( struct V_73 * V_74 )
{
struct V_7 * V_8 = V_74 -> V_107 ;
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
if ( V_76 -> V_37 != NULL && ! F_161 ( V_74 ) ) {
F_2 ( L_75
L_76 ,
V_8 , V_8 -> V_120 / V_260 ) ;
F_100 ( V_181 ,
& V_76 -> V_124 ,
V_8 -> V_120 ) ;
V_8 -> V_120 <<= 1 ;
if ( V_8 -> V_120 < V_193 )
V_8 -> V_120 = V_193 ;
if ( V_8 -> V_120 > V_261 )
V_8 -> V_120 = V_261 ;
} else {
F_2 ( L_77 , V_8 ) ;
F_100 ( V_181 ,
& V_76 -> V_124 , 0 ) ;
}
}
static void F_162 ( struct V_7 * V_8 , struct V_262 * V_263 )
{
long V_264 = 0 ;
if ( F_30 ( V_8 ) )
V_264 = ( long ) ( V_227 - V_8 -> V_265 ) / V_260 ;
F_163 ( V_263 , L_78
L_79 ,
V_8 -> V_224 . V_266 ,
V_8 -> V_224 . V_225 ,
V_8 -> V_224 . V_267 ,
V_264 ,
V_8 -> V_224 . V_268 ,
V_8 -> V_224 . V_269 ,
V_8 -> V_224 . V_270 ,
V_8 -> V_224 . V_271 ,
V_8 -> V_224 . V_272 ,
V_8 -> V_224 . V_273 ,
V_8 -> V_224 . V_274 ,
V_8 -> V_224 . V_275 ) ;
}
static void F_164 ( struct V_7 * V_8 , struct V_262 * V_263 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
F_163 ( V_263 , L_80
L_81 ,
V_76 -> V_116 ,
V_8 -> V_224 . V_266 ,
V_8 -> V_224 . V_268 ,
V_8 -> V_224 . V_269 ,
V_8 -> V_224 . V_270 ,
V_8 -> V_224 . V_271 ,
V_8 -> V_224 . V_272 ,
V_8 -> V_224 . V_273 ,
V_8 -> V_224 . V_274 ,
V_8 -> V_224 . V_275 ) ;
}
static void F_165 ( struct V_7 * V_8 , struct V_262 * V_263 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
long V_264 = 0 ;
if ( F_30 ( V_8 ) )
V_264 = ( long ) ( V_227 - V_8 -> V_265 ) / V_260 ;
F_163 ( V_263 , L_82
L_79 ,
V_76 -> V_116 ,
V_8 -> V_224 . V_266 ,
V_8 -> V_224 . V_225 ,
V_8 -> V_224 . V_267 ,
V_264 ,
V_8 -> V_224 . V_268 ,
V_8 -> V_224 . V_269 ,
V_8 -> V_224 . V_270 ,
V_8 -> V_224 . V_271 ,
V_8 -> V_224 . V_272 ,
V_8 -> V_224 . V_273 ,
V_8 -> V_224 . V_274 ,
V_8 -> V_224 . V_275 ) ;
}
static void * F_166 ( struct V_73 * V_74 , T_4 V_276 )
{
struct V_54 * V_54 ;
struct V_277 * V_4 ;
F_136 ( V_276 > V_278 - sizeof( struct V_277 ) ) ;
if ( V_276 > V_278 - sizeof( struct V_277 ) )
return NULL ;
V_54 = F_167 ( V_21 ) ;
if ( ! V_54 )
return NULL ;
V_4 = F_168 ( V_54 ) ;
V_4 -> V_64 = V_278 ;
return V_4 -> V_177 ;
}
static void F_169 ( void * V_279 )
{
struct V_277 * V_4 ;
if ( ! V_279 )
return;
V_4 = F_27 ( V_279 , struct V_277 , V_177 ) ;
F_170 ( ( unsigned long ) V_4 ) ;
}
static int F_171 ( struct V_81 * V_82 )
{
int V_64 ;
struct V_52 * V_280 = & V_82 -> V_94 ;
struct V_7 * V_8 = V_82 -> V_78 ;
struct V_75 * V_76 =
F_27 ( V_8 , struct V_75 , V_8 ) ;
struct V_36 * V_37 = V_76 -> V_37 ;
unsigned long V_281 ;
unsigned long V_282 ;
F_35 ( V_280 ) ;
V_282 = ( unsigned long ) V_280 -> V_72 [ 0 ] . V_50 & ~ V_63 ;
V_281 = ( unsigned long ) V_280 -> V_70 [ 0 ] . V_50 & ~ V_63 ;
V_64 = F_172 ( V_37 , V_280 ,
F_173 ( V_280 -> V_70 [ 0 ] . V_50 ) , V_281 ,
V_280 -> V_72 [ 0 ] . V_50 , V_282 ) ;
if ( V_64 != V_280 -> V_64 ) {
F_89 ( V_283 L_83 ) ;
V_64 = - V_84 ;
}
return V_64 ;
}
static int F_174 ( struct V_73 * V_74 )
{
struct V_81 * V_82 = V_74 -> V_77 ;
struct V_284 * V_8 ;
T_1 V_64 ;
F_2 ( L_84 , F_11 ( V_82 -> V_168 ) ) ;
V_8 = V_82 -> V_78 -> V_285 ;
if ( ! F_175 ( & V_8 -> V_286 ) ) {
F_176 ( & V_8 -> V_287 , V_74 , NULL ) ;
if ( ! F_175 ( & V_8 -> V_286 ) )
return - V_84 ;
F_177 ( & V_8 -> V_287 , V_74 ) ;
}
if ( F_31 ( V_288 , & V_8 -> V_289 ) )
V_64 = - V_90 ;
else
V_64 = F_171 ( V_82 ) ;
F_178 ( & V_8 -> V_286 ) ;
if ( V_64 > 0 )
V_64 = 0 ;
return V_64 ;
}
static void F_179 ( struct V_7 * V_8 )
{
}
static void F_180 ( struct V_7 * V_8 )
{
}
static int F_181 ( const int V_220 , struct V_6 * V_13 )
{
static const struct V_11 sin = {
. V_290 = V_22 ,
. V_23 . V_24 = F_182 ( V_291 ) ,
} ;
static const struct V_12 V_14 = {
. V_292 = V_25 ,
. V_26 = V_293 ,
} ;
switch ( V_220 ) {
case V_17 :
break;
case V_22 :
memcpy ( V_13 , & sin , sizeof( sin ) ) ;
break;
case V_25 :
memcpy ( V_13 , & V_14 , sizeof( V_14 ) ) ;
break;
default:
F_2 ( L_85 , V_97 ) ;
return - V_294 ;
}
return 0 ;
}
static struct V_7 * F_183 ( struct V_295 * args ,
unsigned int V_296 ,
unsigned int V_297 )
{
struct V_7 * V_8 ;
struct V_75 * V_298 ;
if ( args -> V_38 > sizeof( V_8 -> V_9 ) ) {
F_2 ( L_86 ) ;
return F_140 ( - V_299 ) ;
}
V_8 = F_184 ( args -> V_300 , sizeof( * V_298 ) , V_296 ,
V_297 ) ;
if ( V_8 == NULL ) {
F_2 ( L_87
L_88 ) ;
return F_140 ( - V_301 ) ;
}
V_298 = F_27 ( V_8 , struct V_75 , V_8 ) ;
memcpy ( & V_8 -> V_9 , args -> V_302 , args -> V_38 ) ;
V_8 -> V_38 = args -> V_38 ;
if ( args -> V_215 )
memcpy ( & V_298 -> V_215 , args -> V_215 , args -> V_38 ) ;
else {
int V_57 ;
V_57 = F_181 ( args -> V_302 -> V_16 ,
(struct V_6 * ) & V_298 -> V_215 ) ;
if ( V_57 != 0 ) {
F_60 ( V_8 ) ;
return F_140 ( V_57 ) ;
}
}
return V_8 ;
}
static struct V_7 * F_185 ( struct V_295 * args )
{
struct V_10 * V_15 = (struct V_10 * ) args -> V_302 ;
struct V_75 * V_76 ;
struct V_7 * V_8 ;
struct V_7 * V_83 ;
V_8 = F_183 ( args , V_303 ,
V_304 ) ;
if ( F_152 ( V_8 ) )
return V_8 ;
V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
V_8 -> V_305 = 0 ;
V_8 -> V_306 = sizeof( V_92 ) / sizeof( T_1 ) ;
V_8 -> V_307 = V_308 ;
V_8 -> V_309 = V_310 ;
V_8 -> V_120 = V_193 ;
V_8 -> V_311 = V_312 ;
V_8 -> V_66 = & V_313 ;
V_8 -> V_180 = & V_314 ;
switch ( V_15 -> V_315 ) {
case V_17 :
if ( V_15 -> V_18 [ 0 ] != '/' ) {
F_2 ( L_89 ,
V_15 -> V_18 ) ;
V_83 = F_140 ( - V_259 ) ;
goto V_316;
}
F_129 ( V_8 ) ;
F_186 ( & V_76 -> V_124 ,
F_144 ) ;
F_15 ( V_8 , L_90 , V_317 ) ;
break;
default:
V_83 = F_140 ( - V_294 ) ;
goto V_316;
}
F_2 ( L_91 ,
V_8 -> V_19 [ V_20 ] ) ;
if ( F_187 ( V_125 ) )
return V_8 ;
V_83 = F_140 ( - V_259 ) ;
V_316:
F_60 ( V_8 ) ;
return V_83 ;
}
static struct V_7 * F_188 ( struct V_295 * args )
{
struct V_6 * V_9 = args -> V_302 ;
struct V_7 * V_8 ;
struct V_75 * V_76 ;
struct V_7 * V_83 ;
V_8 = F_183 ( args , V_318 ,
V_318 ) ;
if ( F_152 ( V_8 ) )
return V_8 ;
V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
V_8 -> V_305 = V_240 ;
V_8 -> V_306 = 0 ;
V_8 -> V_307 = ( 1U << 16 ) - ( V_319 << 3 ) ;
V_8 -> V_309 = V_310 ;
V_8 -> V_120 = V_320 ;
V_8 -> V_311 = V_312 ;
V_8 -> V_66 = & V_321 ;
V_8 -> V_180 = & V_322 ;
switch ( V_9 -> V_16 ) {
case V_22 :
if ( ( (struct V_11 * ) V_9 ) -> V_323 != F_189 ( 0 ) )
F_129 ( V_8 ) ;
F_186 ( & V_76 -> V_124 ,
F_151 ) ;
F_15 ( V_8 , L_92 , V_324 ) ;
break;
case V_25 :
if ( ( (struct V_12 * ) V_9 ) -> V_325 != F_189 ( 0 ) )
F_129 ( V_8 ) ;
F_186 ( & V_76 -> V_124 ,
F_151 ) ;
F_15 ( V_8 , L_92 , V_326 ) ;
break;
default:
V_83 = F_140 ( - V_294 ) ;
goto V_316;
}
if ( F_41 ( V_8 ) )
F_2 ( L_93 ,
V_8 -> V_19 [ V_20 ] ,
V_8 -> V_19 [ V_28 ] ,
V_8 -> V_19 [ V_32 ] ) ;
else
F_2 ( L_94 ,
V_8 -> V_19 [ V_20 ] ,
V_8 -> V_19 [ V_32 ] ) ;
if ( F_187 ( V_125 ) )
return V_8 ;
V_83 = F_140 ( - V_259 ) ;
V_316:
F_60 ( V_8 ) ;
return V_83 ;
}
static struct V_7 * F_190 ( struct V_295 * args )
{
struct V_6 * V_9 = args -> V_302 ;
struct V_7 * V_8 ;
struct V_75 * V_76 ;
struct V_7 * V_83 ;
V_8 = F_183 ( args , V_303 ,
V_304 ) ;
if ( F_152 ( V_8 ) )
return V_8 ;
V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
V_8 -> V_305 = V_254 ;
V_8 -> V_306 = sizeof( V_92 ) / sizeof( T_1 ) ;
V_8 -> V_307 = V_308 ;
V_8 -> V_309 = V_310 ;
V_8 -> V_120 = V_193 ;
V_8 -> V_311 = V_312 ;
V_8 -> V_66 = & V_327 ;
V_8 -> V_180 = & V_328 ;
switch ( V_9 -> V_16 ) {
case V_22 :
if ( ( (struct V_11 * ) V_9 ) -> V_323 != F_189 ( 0 ) )
F_129 ( V_8 ) ;
F_186 ( & V_76 -> V_124 ,
F_158 ) ;
F_15 ( V_8 , L_95 , V_329 ) ;
break;
case V_25 :
if ( ( (struct V_12 * ) V_9 ) -> V_325 != F_189 ( 0 ) )
F_129 ( V_8 ) ;
F_186 ( & V_76 -> V_124 ,
F_158 ) ;
F_15 ( V_8 , L_95 , V_330 ) ;
break;
default:
V_83 = F_140 ( - V_294 ) ;
goto V_316;
}
if ( F_41 ( V_8 ) )
F_2 ( L_93 ,
V_8 -> V_19 [ V_20 ] ,
V_8 -> V_19 [ V_28 ] ,
V_8 -> V_19 [ V_32 ] ) ;
else
F_2 ( L_94 ,
V_8 -> V_19 [ V_20 ] ,
V_8 -> V_19 [ V_32 ] ) ;
if ( F_187 ( V_125 ) )
return V_8 ;
V_83 = F_140 ( - V_259 ) ;
V_316:
F_60 ( V_8 ) ;
return V_83 ;
}
static struct V_7 * F_191 ( struct V_295 * args )
{
struct V_6 * V_9 = args -> V_302 ;
struct V_7 * V_8 ;
struct V_75 * V_76 ;
struct V_331 * V_332 ;
struct V_7 * V_83 ;
if ( args -> V_285 -> V_333 ) {
return args -> V_285 -> V_333 ;
}
V_8 = F_183 ( args , V_303 ,
V_303 ) ;
if ( F_152 ( V_8 ) )
return V_8 ;
V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
V_8 -> V_305 = V_254 ;
V_8 -> V_306 = sizeof( V_92 ) / sizeof( T_1 ) ;
V_8 -> V_307 = V_308 ;
V_8 -> V_180 = & V_328 ;
F_129 ( V_8 ) ;
V_8 -> V_309 = 0 ;
V_8 -> V_120 = 0 ;
V_8 -> V_311 = 0 ;
V_8 -> V_66 = & V_334 ;
switch ( V_9 -> V_16 ) {
case V_22 :
F_15 ( V_8 , L_95 ,
V_329 ) ;
break;
case V_25 :
F_15 ( V_8 , L_95 ,
V_330 ) ;
break;
default:
V_83 = F_140 ( - V_294 ) ;
goto V_316;
}
F_2 ( L_93 ,
V_8 -> V_19 [ V_20 ] ,
V_8 -> V_19 [ V_28 ] ,
V_8 -> V_19 [ V_32 ] ) ;
F_192 ( V_8 ) ;
args -> V_285 -> V_333 = V_8 ;
V_8 -> V_285 = args -> V_285 ;
V_332 = F_27 ( args -> V_285 , struct V_331 , V_335 ) ;
V_76 -> V_37 = V_332 -> V_336 ;
V_76 -> V_79 = V_332 -> V_337 ;
F_145 ( V_8 ) ;
if ( F_187 ( V_125 ) )
return V_8 ;
F_193 ( V_8 ) ;
V_83 = F_140 ( - V_259 ) ;
V_316:
F_60 ( V_8 ) ;
return V_83 ;
}
int F_194 ( void )
{
#ifdef F_195
if ( ! V_338 )
V_338 = F_196 ( V_339 ) ;
#endif
F_197 ( & V_340 ) ;
F_197 ( & V_341 ) ;
F_197 ( & V_342 ) ;
F_197 ( & V_343 ) ;
return 0 ;
}
void F_198 ( void )
{
#ifdef F_195
if ( V_338 ) {
F_199 ( V_338 ) ;
V_338 = NULL ;
}
#endif
F_200 ( & V_340 ) ;
F_200 ( & V_341 ) ;
F_200 ( & V_342 ) ;
F_200 ( & V_343 ) ;
}
static int F_201 ( const char * V_344 ,
const struct V_345 * V_346 ,
unsigned int V_347 , unsigned int V_348 )
{
unsigned long V_349 ;
int V_83 ;
if ( ! V_344 )
return - V_259 ;
V_83 = F_202 ( V_344 , 0 , & V_349 ) ;
if ( V_83 == - V_259 || V_349 < V_347 || V_349 > V_348 )
return - V_259 ;
* ( ( unsigned int * ) V_346 -> V_176 ) = V_349 ;
return 0 ;
}
static int F_203 ( const char * V_344 , const struct V_345 * V_346 )
{
return F_201 ( V_344 , V_346 ,
V_350 ,
V_351 ) ;
}
static int F_204 ( const char * V_344 ,
const struct V_345 * V_346 )
{
return F_201 ( V_344 , V_346 ,
V_352 ,
V_353 ) ;
}
static int F_205 ( const char * V_344 ,
const struct V_345 * V_346 )
{
return F_201 ( V_344 , V_346 ,
V_352 ,
V_354 ) ;
}

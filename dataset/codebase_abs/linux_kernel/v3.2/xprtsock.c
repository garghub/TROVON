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
case - V_99 :
F_42 ( V_8 ) ;
case - V_101 :
case - V_90 :
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
V_76 -> V_116 = V_109 -> V_117 ;
}
static void F_48 ( struct V_75 * V_76 , struct V_37 * V_109 )
{
V_109 -> V_111 = V_76 -> V_110 ;
V_109 -> V_113 = V_76 -> V_112 ;
V_109 -> V_115 = V_76 -> V_114 ;
V_109 -> V_117 = V_76 -> V_116 ;
}
static void F_49 ( struct V_75 * V_76 )
{
struct V_36 * V_37 = V_76 -> V_37 ;
struct V_37 * V_109 = V_76 -> V_79 ;
if ( V_109 == NULL )
return;
V_76 -> V_118 = 0 ;
F_50 ( & V_109 -> V_119 ) ;
V_76 -> V_79 = NULL ;
V_76 -> V_37 = NULL ;
V_109 -> V_120 = NULL ;
F_48 ( V_76 , V_109 ) ;
F_51 ( & V_109 -> V_119 ) ;
V_109 -> V_121 = 0 ;
F_52 ( V_37 ) ;
}
static void F_39 ( struct V_7 * V_8 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
F_2 ( L_15 , V_8 ) ;
F_49 ( V_76 ) ;
V_8 -> V_122 = 0 ;
F_53 () ;
F_25 ( V_123 , & V_8 -> V_108 ) ;
F_25 ( V_106 , & V_8 -> V_108 ) ;
F_25 ( V_124 , & V_8 -> V_108 ) ;
F_54 () ;
F_55 ( V_8 ) ;
}
static void F_56 ( struct V_7 * V_8 )
{
if ( F_57 ( V_125 , & V_8 -> V_108 ) )
F_39 ( V_8 ) ;
else
F_42 ( V_8 ) ;
}
static void F_58 ( struct V_7 * V_8 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
F_2 ( L_16 , V_8 ) ;
F_59 ( & V_76 -> V_126 ) ;
F_39 ( V_8 ) ;
F_18 ( V_8 ) ;
F_60 ( V_8 ) ;
F_61 ( V_127 ) ;
}
static inline struct V_7 * F_62 ( struct V_37 * V_109 )
{
return (struct V_7 * ) V_109 -> V_120 ;
}
static int F_63 ( struct V_52 * V_53 , struct V_128 * V_129 )
{
struct V_130 V_131 = {
. V_129 = V_129 ,
. V_132 = sizeof( V_92 ) ,
. V_3 = V_129 -> V_64 - sizeof( V_92 ) ,
} ;
if ( F_64 ( V_53 , 0 , & V_131 , V_133 ) < 0 )
return - 1 ;
if ( V_131 . V_3 )
return - 1 ;
return 0 ;
}
static void F_65 ( struct V_37 * V_109 , int V_64 )
{
struct V_73 * V_74 ;
struct V_7 * V_8 ;
struct V_81 * V_134 ;
struct V_128 * V_129 ;
int V_57 , V_135 , V_136 ;
T_1 V_137 ;
T_3 * V_138 ;
F_66 ( & V_109 -> V_119 ) ;
F_2 ( L_17 , V_97 ) ;
V_8 = F_62 ( V_109 ) ;
if ( V_8 == NULL )
goto V_71;
V_129 = F_67 ( V_109 , 0 , 1 , & V_57 ) ;
if ( V_129 == NULL )
goto V_71;
if ( V_8 -> V_139 )
goto V_140;
V_135 = V_129 -> V_64 - sizeof( V_92 ) ;
if ( V_135 < 4 ) {
F_2 ( L_18 , V_135 ) ;
goto V_140;
}
V_138 = F_68 ( V_129 , sizeof( V_92 ) , sizeof( V_137 ) , & V_137 ) ;
if ( V_138 == NULL )
goto V_140;
F_69 ( & V_8 -> V_88 ) ;
V_134 = F_70 ( V_8 , * V_138 ) ;
if ( ! V_134 )
goto V_141;
V_74 = V_134 -> V_142 ;
V_136 = V_134 -> V_143 . V_144 ;
if ( V_136 > V_135 )
V_136 = V_135 ;
if ( F_63 ( & V_134 -> V_143 , V_129 ) ) {
F_2 ( L_19 ) ;
goto V_141;
}
F_71 ( V_74 , V_136 ) ;
V_141:
F_72 ( & V_8 -> V_88 ) ;
V_140:
F_73 ( V_109 , V_129 ) ;
V_71:
F_74 ( & V_109 -> V_119 ) ;
}
static void F_75 ( struct V_37 * V_109 , int V_64 )
{
struct V_73 * V_74 ;
struct V_7 * V_8 ;
struct V_81 * V_134 ;
struct V_128 * V_129 ;
int V_57 , V_135 , V_136 ;
T_1 V_137 ;
T_3 * V_138 ;
F_66 ( & V_109 -> V_119 ) ;
F_2 ( L_20 ) ;
if ( ! ( V_8 = F_62 ( V_109 ) ) )
goto V_71;
if ( ( V_129 = F_67 ( V_109 , 0 , 1 , & V_57 ) ) == NULL )
goto V_71;
if ( V_8 -> V_139 )
goto V_140;
V_135 = V_129 -> V_64 - sizeof( struct V_145 ) ;
if ( V_135 < 4 ) {
F_2 ( L_21 , V_135 ) ;
goto V_140;
}
V_138 = F_68 ( V_129 , sizeof( struct V_145 ) ,
sizeof( V_137 ) , & V_137 ) ;
if ( V_138 == NULL )
goto V_140;
F_69 ( & V_8 -> V_88 ) ;
V_134 = F_70 ( V_8 , * V_138 ) ;
if ( ! V_134 )
goto V_141;
V_74 = V_134 -> V_142 ;
if ( ( V_136 = V_134 -> V_143 . V_144 ) > V_135 )
V_136 = V_135 ;
if ( F_76 ( & V_134 -> V_143 , V_129 ) ) {
F_77 ( V_109 , V_146 ) ;
goto V_141;
}
F_77 ( V_109 , V_147 ) ;
F_78 ( F_79 ( V_129 ) ) ;
F_80 ( V_74 , V_136 ) ;
F_71 ( V_74 , V_136 ) ;
V_141:
F_72 ( & V_8 -> V_88 ) ;
V_140:
F_73 ( V_109 , V_129 ) ;
V_71:
F_74 ( & V_109 -> V_119 ) ;
}
static inline void F_81 ( struct V_7 * V_8 , struct V_130 * V_131 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
T_4 V_64 , V_148 ;
char * V_149 ;
V_149 = ( ( char * ) & V_76 -> V_150 ) + V_76 -> V_151 ;
V_64 = sizeof( V_76 -> V_150 ) - V_76 -> V_151 ;
V_148 = V_133 ( V_131 , V_149 , V_64 ) ;
V_76 -> V_151 += V_148 ;
if ( V_148 != V_64 )
return;
V_76 -> V_152 = F_11 ( V_76 -> V_150 ) ;
if ( V_76 -> V_152 & V_93 )
V_76 -> V_153 |= V_154 ;
else
V_76 -> V_153 &= ~ V_154 ;
V_76 -> V_152 &= V_155 ;
V_76 -> V_153 &= ~ V_156 ;
V_76 -> V_151 = 0 ;
if ( F_24 ( V_76 -> V_152 < 8 ) ) {
F_2 ( L_22 ) ;
F_82 ( V_8 ) ;
return;
}
F_2 ( L_23 ,
V_76 -> V_152 ) ;
}
static void F_83 ( struct V_75 * V_76 )
{
if ( V_76 -> V_151 == V_76 -> V_152 ) {
V_76 -> V_153 |= V_156 ;
V_76 -> V_151 = 0 ;
if ( V_76 -> V_153 & V_154 ) {
V_76 -> V_153 &= ~ V_157 ;
V_76 -> V_153 |= V_158 ;
V_76 -> V_159 = 0 ;
}
}
}
static inline void F_84 ( struct V_75 * V_76 , struct V_130 * V_131 )
{
T_4 V_64 , V_148 ;
char * V_149 ;
V_64 = sizeof( V_76 -> V_160 ) - V_76 -> V_151 ;
F_2 ( L_24 , V_64 ) ;
V_149 = ( ( char * ) & V_76 -> V_160 ) + V_76 -> V_151 ;
V_148 = V_133 ( V_131 , V_149 , V_64 ) ;
V_76 -> V_151 += V_148 ;
if ( V_148 != V_64 )
return;
V_76 -> V_153 &= ~ V_158 ;
V_76 -> V_153 |= V_161 ;
V_76 -> V_159 = 4 ;
F_2 ( L_25 ,
( V_76 -> V_153 & V_162 ) ? L_26
: L_27 ,
F_11 ( V_76 -> V_160 ) ) ;
F_83 ( V_76 ) ;
}
static inline void F_85 ( struct V_75 * V_76 ,
struct V_130 * V_131 )
{
T_4 V_64 , V_148 ;
T_1 V_132 ;
char * V_149 ;
V_132 = V_76 -> V_151 - sizeof( V_76 -> V_160 ) ;
V_64 = sizeof( V_76 -> V_163 ) - V_132 ;
F_2 ( L_28 , V_64 ) ;
V_149 = ( ( char * ) & V_76 -> V_163 ) + V_132 ;
V_148 = V_133 ( V_131 , V_149 , V_64 ) ;
V_76 -> V_151 += V_148 ;
if ( V_148 != V_64 )
return;
V_76 -> V_153 &= ~ V_161 ;
switch ( F_11 ( V_76 -> V_163 ) ) {
case V_164 :
V_76 -> V_153 |= V_165 ;
V_76 -> V_153 |= V_157 ;
V_76 -> V_153 |= V_162 ;
break;
case V_166 :
V_76 -> V_153 |= V_165 ;
V_76 -> V_153 |= V_157 ;
V_76 -> V_153 &= ~ V_162 ;
break;
default:
F_2 ( L_29 ) ;
F_82 ( & V_76 -> V_8 ) ;
}
F_83 ( V_76 ) ;
}
static inline void F_86 ( struct V_7 * V_8 ,
struct V_130 * V_131 ,
struct V_81 * V_82 )
{
struct V_75 * V_76 =
F_27 ( V_8 , struct V_75 , V_8 ) ;
struct V_52 * V_167 ;
T_4 V_64 ;
T_5 V_168 ;
V_167 = & V_82 -> V_143 ;
if ( V_76 -> V_153 & V_165 ) {
memcpy ( V_167 -> V_70 [ 0 ] . V_50 + V_76 -> V_159 ,
& V_76 -> V_163 ,
sizeof( V_76 -> V_163 ) ) ;
V_76 -> V_159 += sizeof( V_76 -> V_163 ) ;
V_76 -> V_153 &= ~ V_165 ;
}
V_64 = V_131 -> V_3 ;
if ( V_64 > V_76 -> V_152 - V_76 -> V_151 ) {
struct V_130 V_169 ;
V_64 = V_76 -> V_152 - V_76 -> V_151 ;
memcpy ( & V_169 , V_131 , sizeof( V_169 ) ) ;
V_169 . V_3 = V_64 ;
V_168 = F_64 ( V_167 , V_76 -> V_159 ,
& V_169 , V_133 ) ;
V_131 -> V_3 -= V_168 ;
V_131 -> V_132 += V_168 ;
} else
V_168 = F_64 ( V_167 , V_76 -> V_159 ,
V_131 , V_133 ) ;
if ( V_168 > 0 ) {
V_76 -> V_159 += V_168 ;
V_76 -> V_151 += V_168 ;
}
if ( V_168 != V_64 ) {
V_76 -> V_153 &= ~ V_157 ;
F_2 ( L_30 ,
F_11 ( V_76 -> V_160 ) ) ;
F_2 ( L_31
L_32 ,
V_8 , V_76 -> V_159 ,
V_76 -> V_151 , V_76 -> V_152 ) ;
return;
}
F_2 ( L_33 ,
F_11 ( V_76 -> V_160 ) , V_168 ) ;
F_2 ( L_34
L_35 , V_8 , V_76 -> V_159 ,
V_76 -> V_151 , V_76 -> V_152 ) ;
if ( V_76 -> V_159 == V_82 -> V_143 . V_144 )
V_76 -> V_153 &= ~ V_157 ;
else if ( V_76 -> V_151 == V_76 -> V_152 ) {
if ( V_76 -> V_153 & V_154 )
V_76 -> V_153 &= ~ V_157 ;
}
}
static inline int F_87 ( struct V_7 * V_8 ,
struct V_130 * V_131 )
{
struct V_75 * V_76 =
F_27 ( V_8 , struct V_75 , V_8 ) ;
struct V_81 * V_82 ;
F_2 ( L_36 , F_11 ( V_76 -> V_160 ) ) ;
F_69 ( & V_8 -> V_88 ) ;
V_82 = F_70 ( V_8 , V_76 -> V_160 ) ;
if ( ! V_82 ) {
F_2 ( L_37 ,
F_11 ( V_76 -> V_160 ) ) ;
F_72 ( & V_8 -> V_88 ) ;
return - 1 ;
}
F_86 ( V_8 , V_131 , V_82 ) ;
if ( ! ( V_76 -> V_153 & V_157 ) )
F_71 ( V_82 -> V_142 , V_76 -> V_159 ) ;
F_72 ( & V_8 -> V_88 ) ;
return 0 ;
}
static inline int F_88 ( struct V_7 * V_8 ,
struct V_130 * V_131 )
{
struct V_75 * V_76 =
F_27 ( V_8 , struct V_75 , V_8 ) ;
struct V_81 * V_82 ;
V_82 = F_89 ( V_8 ) ;
if ( V_82 == NULL ) {
F_90 ( V_170 L_38 ) ;
F_82 ( V_8 ) ;
return - 1 ;
}
V_82 -> V_171 = V_76 -> V_160 ;
F_2 ( L_39 , F_11 ( V_82 -> V_171 ) ) ;
F_86 ( V_8 , V_131 , V_82 ) ;
if ( ! ( V_76 -> V_153 & V_157 ) ) {
struct V_172 * V_173 = V_8 -> V_173 ;
F_2 ( L_40 ) ;
F_69 ( & V_173 -> V_174 ) ;
F_91 ( & V_82 -> V_175 , & V_173 -> V_176 ) ;
F_72 ( & V_173 -> V_174 ) ;
F_92 ( & V_173 -> V_177 ) ;
}
V_82 -> V_143 . V_64 = V_76 -> V_159 ;
return 0 ;
}
static inline int F_93 ( struct V_7 * V_8 ,
struct V_130 * V_131 )
{
struct V_75 * V_76 =
F_27 ( V_8 , struct V_75 , V_8 ) ;
return ( V_76 -> V_153 & V_162 ) ?
F_87 ( V_8 , V_131 ) :
F_88 ( V_8 , V_131 ) ;
}
static inline int F_93 ( struct V_7 * V_8 ,
struct V_130 * V_131 )
{
return F_87 ( V_8 , V_131 ) ;
}
static void F_94 ( struct V_7 * V_8 ,
struct V_130 * V_131 )
{
struct V_75 * V_76 =
F_27 ( V_8 , struct V_75 , V_8 ) ;
if ( F_93 ( V_8 , V_131 ) == 0 )
F_83 ( V_76 ) ;
else {
V_76 -> V_153 &= ~ V_157 ;
}
}
static inline void F_95 ( struct V_75 * V_76 , struct V_130 * V_131 )
{
T_4 V_64 ;
V_64 = V_76 -> V_152 - V_76 -> V_151 ;
if ( V_64 > V_131 -> V_3 )
V_64 = V_131 -> V_3 ;
V_131 -> V_3 -= V_64 ;
V_131 -> V_132 += V_64 ;
V_76 -> V_151 += V_64 ;
F_2 ( L_41 , V_64 ) ;
F_83 ( V_76 ) ;
}
static int F_96 ( T_6 * V_178 , struct V_128 * V_129 , unsigned int V_132 , T_4 V_64 )
{
struct V_7 * V_8 = V_178 -> V_179 . V_180 ;
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
struct V_130 V_131 = {
. V_129 = V_129 ,
. V_132 = V_132 ,
. V_3 = V_64 ,
} ;
F_2 ( L_42 ) ;
do {
if ( V_76 -> V_153 & V_156 ) {
F_81 ( V_8 , & V_131 ) ;
continue;
}
if ( V_76 -> V_153 & V_158 ) {
F_84 ( V_76 , & V_131 ) ;
continue;
}
if ( V_76 -> V_153 & V_161 ) {
F_85 ( V_76 , & V_131 ) ;
continue;
}
if ( V_76 -> V_153 & V_157 ) {
F_94 ( V_8 , & V_131 ) ;
continue;
}
F_95 ( V_76 , & V_131 ) ;
} while ( V_131 . V_3 );
F_2 ( L_43 ) ;
return V_64 - V_131 . V_3 ;
}
static void F_97 ( struct V_37 * V_109 , int V_181 )
{
struct V_7 * V_8 ;
T_6 V_178 ;
int V_182 ;
F_2 ( L_44 ) ;
F_66 ( & V_109 -> V_119 ) ;
if ( ! ( V_8 = F_62 ( V_109 ) ) )
goto V_71;
if ( V_8 -> V_139 )
goto V_71;
if ( V_8 -> V_122 )
V_8 -> V_122 = 0 ;
V_178 . V_179 . V_180 = V_8 ;
do {
V_178 . V_3 = 65536 ;
V_182 = F_98 ( V_109 , & V_178 , F_96 ) ;
} while ( V_182 > 0 );
V_71:
F_74 ( & V_109 -> V_119 ) ;
}
static void F_99 ( struct V_7 * V_8 ,
unsigned long V_183 )
{
struct V_75 * V_76 ;
if ( F_100 ( V_8 ) )
return;
F_32 ( V_123 , & V_8 -> V_108 ) ;
V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
F_101 ( V_184 , & V_76 -> V_126 ,
V_183 ) ;
}
static void F_102 ( struct V_7 * V_8 )
{
struct V_75 * V_76 ;
V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
if ( ! F_31 ( V_123 , & V_8 -> V_108 ) ||
! F_103 ( & V_76 -> V_126 ) )
return;
F_25 ( V_123 , & V_8 -> V_108 ) ;
F_104 ( V_8 ) ;
}
static void F_105 ( struct V_7 * V_8 )
{
F_53 () ;
F_25 ( V_106 , & V_8 -> V_108 ) ;
F_25 ( V_124 , & V_8 -> V_108 ) ;
F_54 () ;
F_55 ( V_8 ) ;
}
static void F_106 ( struct V_37 * V_109 )
{
struct V_7 * V_8 ;
F_66 ( & V_109 -> V_119 ) ;
if ( ! ( V_8 = F_62 ( V_109 ) ) )
goto V_71;
F_2 ( L_45 , V_8 ) ;
F_2 ( L_46 ,
V_109 -> V_185 , F_30 ( V_8 ) ,
F_107 ( V_109 , V_186 ) ,
F_107 ( V_109 , V_187 ) ,
V_109 -> V_188 ) ;
switch ( V_109 -> V_185 ) {
case V_189 :
F_69 ( & V_8 -> V_88 ) ;
if ( ! F_108 ( V_8 ) ) {
struct V_75 * V_76 = F_27 ( V_8 ,
struct V_75 , V_8 ) ;
V_76 -> V_151 = 0 ;
V_76 -> V_152 = 0 ;
V_76 -> V_159 = 0 ;
V_76 -> V_153 =
V_156 | V_158 ;
F_109 ( V_8 , - V_84 ) ;
}
F_72 ( & V_8 -> V_88 ) ;
break;
case V_190 :
V_8 -> V_191 ++ ;
V_8 -> V_122 = 0 ;
F_32 ( V_124 , & V_8 -> V_108 ) ;
F_53 () ;
F_25 ( V_192 , & V_8 -> V_108 ) ;
F_25 ( V_106 , & V_8 -> V_108 ) ;
F_54 () ;
F_99 ( V_8 , V_193 ) ;
break;
case V_194 :
F_82 ( V_8 ) ;
V_8 -> V_191 ++ ;
case V_195 :
if ( V_8 -> V_122 < V_196 )
V_8 -> V_122 = V_196 ;
break;
case V_197 :
F_32 ( V_124 , & V_8 -> V_108 ) ;
F_99 ( V_8 , V_193 ) ;
F_53 () ;
F_25 ( V_192 , & V_8 -> V_108 ) ;
F_54 () ;
break;
case V_198 :
F_102 ( V_8 ) ;
F_105 ( V_8 ) ;
}
V_71:
F_74 ( & V_109 -> V_119 ) ;
}
static void F_110 ( struct V_37 * V_109 )
{
struct V_7 * V_8 ;
F_66 ( & V_109 -> V_119 ) ;
if ( ! ( V_8 = F_62 ( V_109 ) ) )
goto V_71;
F_2 ( L_47
L_48 ,
V_97 , V_8 , V_109 -> V_199 ) ;
F_109 ( V_8 , - V_84 ) ;
V_71:
F_74 ( & V_109 -> V_119 ) ;
}
static void F_111 ( struct V_37 * V_109 )
{
struct V_36 * V_37 ;
struct V_7 * V_8 ;
if ( F_24 ( ! ( V_37 = V_109 -> V_200 ) ) )
return;
F_25 ( V_89 , & V_37 -> V_65 ) ;
if ( F_24 ( ! ( V_8 = F_62 ( V_109 ) ) ) )
return;
if ( F_57 ( V_69 , & V_37 -> V_65 ) == 0 )
return;
F_112 ( V_8 ) ;
}
static void F_113 ( struct V_37 * V_109 )
{
F_66 ( & V_109 -> V_119 ) ;
if ( F_114 ( V_109 ) )
F_111 ( V_109 ) ;
F_74 ( & V_109 -> V_119 ) ;
}
static void F_115 ( struct V_37 * V_109 )
{
F_66 ( & V_109 -> V_119 ) ;
if ( F_116 ( V_109 ) >= F_117 ( V_109 ) )
F_111 ( V_109 ) ;
F_74 ( & V_109 -> V_119 ) ;
}
static void F_118 ( struct V_7 * V_8 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
struct V_37 * V_109 = V_76 -> V_79 ;
if ( V_76 -> V_201 ) {
V_109 -> V_202 |= V_203 ;
V_109 -> V_204 = V_76 -> V_201 * V_8 -> V_205 * 2 ;
}
if ( V_76 -> V_206 ) {
V_109 -> V_202 |= V_207 ;
V_109 -> V_208 = V_76 -> V_206 * V_8 -> V_205 * 2 ;
V_109 -> V_115 ( V_109 ) ;
}
}
static void F_119 ( struct V_7 * V_8 , T_4 V_206 , T_4 V_201 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
V_76 -> V_206 = 0 ;
if ( V_206 )
V_76 -> V_206 = V_206 + 1024 ;
V_76 -> V_201 = 0 ;
if ( V_201 )
V_76 -> V_201 = V_201 + 1024 ;
F_118 ( V_8 ) ;
}
static void F_120 ( struct V_73 * V_74 )
{
F_80 ( V_74 , - V_209 ) ;
}
static unsigned short F_121 ( void )
{
unsigned short V_210 = V_211 - V_212 ;
unsigned short rand = ( unsigned short ) F_122 () % V_210 ;
return rand + V_212 ;
}
static void F_123 ( struct V_7 * V_8 , unsigned short V_213 )
{
F_2 ( L_49 , V_8 , V_213 ) ;
F_124 ( F_3 ( V_8 ) , V_213 ) ;
F_16 ( V_8 ) ;
}
static unsigned short F_125 ( struct V_75 * V_76 )
{
unsigned short V_213 = V_76 -> V_118 ;
if ( V_213 == 0 && V_76 -> V_8 . V_214 )
V_213 = F_121 () ;
return V_213 ;
}
static unsigned short F_126 ( struct V_75 * V_76 , unsigned short V_213 )
{
if ( V_76 -> V_118 != 0 )
V_76 -> V_118 = 0 ;
if ( ! V_76 -> V_8 . V_214 )
return 0 ;
if ( V_213 <= V_212 || V_213 > V_211 )
return V_211 ;
return -- V_213 ;
}
static int F_127 ( struct V_75 * V_76 , struct V_36 * V_37 )
{
struct V_215 V_216 ;
int V_57 , V_217 = 0 ;
unsigned short V_213 = F_125 ( V_76 ) ;
unsigned short V_218 ;
memcpy ( & V_216 , & V_76 -> V_219 , V_76 -> V_8 . V_38 ) ;
do {
F_124 ( (struct V_6 * ) & V_216 , V_213 ) ;
V_57 = F_128 ( V_37 , (struct V_6 * ) & V_216 ,
V_76 -> V_8 . V_38 ) ;
if ( V_213 == 0 )
break;
if ( V_57 == 0 ) {
V_76 -> V_118 = V_213 ;
break;
}
V_218 = V_213 ;
V_213 = F_126 ( V_76 , V_213 ) ;
if ( V_213 > V_218 )
V_217 ++ ;
} while ( V_57 == - V_220 && V_217 != 2 );
if ( V_216 . V_221 == V_22 )
F_2 ( L_50 , V_97 ,
& ( (struct V_11 * ) & V_216 ) -> V_23 ,
V_213 , V_57 ? L_51 : L_52 , V_57 ) ;
else
F_2 ( L_53 , V_97 ,
& ( (struct V_12 * ) & V_216 ) -> V_26 ,
V_213 , V_57 ? L_51 : L_52 , V_57 ) ;
return V_57 ;
}
static void F_129 ( struct V_73 * V_74 )
{
F_130 ( V_74 -> V_107 ) ;
}
static void F_131 ( struct V_7 * V_8 , unsigned short V_213 )
{
}
static inline void F_132 ( struct V_36 * V_37 )
{
struct V_37 * V_109 = V_37 -> V_109 ;
F_133 ( F_134 ( V_109 ) ) ;
F_135 ( V_109 , L_54 ,
& V_222 [ 1 ] , L_55 , & V_223 [ 1 ] ) ;
}
static inline void F_136 ( struct V_36 * V_37 )
{
struct V_37 * V_109 = V_37 -> V_109 ;
F_133 ( F_134 ( V_109 ) ) ;
F_135 ( V_109 , L_56 ,
& V_222 [ 0 ] , L_57 , & V_223 [ 0 ] ) ;
}
static inline void F_137 ( struct V_36 * V_37 )
{
struct V_37 * V_109 = V_37 -> V_109 ;
F_133 ( F_134 ( V_109 ) ) ;
F_135 ( V_109 , L_58 ,
& V_222 [ 1 ] , L_59 , & V_223 [ 1 ] ) ;
}
static inline void F_138 ( int V_224 , struct V_36 * V_37 )
{
switch ( V_224 ) {
case V_17 :
F_132 ( V_37 ) ;
break;
case V_22 :
F_136 ( V_37 ) ;
break;
case V_25 :
F_137 ( V_37 ) ;
break;
}
}
static inline void F_132 ( struct V_36 * V_37 )
{
}
static inline void F_136 ( struct V_36 * V_37 )
{
}
static inline void F_137 ( struct V_36 * V_37 )
{
}
static inline void F_138 ( int V_224 , struct V_36 * V_37 )
{
}
static struct V_36 * F_139 ( struct V_7 * V_8 ,
struct V_75 * V_76 , int V_224 , int type , int V_30 )
{
struct V_36 * V_37 ;
int V_57 ;
V_57 = F_140 ( V_8 -> V_225 , V_224 , type , V_30 , & V_37 , 1 ) ;
if ( V_57 < 0 ) {
F_2 ( L_60 ,
V_30 , - V_57 ) ;
goto V_71;
}
F_138 ( V_224 , V_37 ) ;
V_57 = F_127 ( V_76 , V_37 ) ;
if ( V_57 ) {
F_52 ( V_37 ) ;
goto V_71;
}
return V_37 ;
V_71:
return F_141 ( V_57 ) ;
}
static int F_142 ( struct V_7 * V_8 ,
struct V_36 * V_37 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 ,
V_8 ) ;
if ( ! V_76 -> V_79 ) {
struct V_37 * V_109 = V_37 -> V_109 ;
F_50 ( & V_109 -> V_119 ) ;
F_47 ( V_76 , V_109 ) ;
V_109 -> V_120 = V_8 ;
V_109 -> V_111 = F_65 ;
V_109 -> V_115 = F_113 ;
V_109 -> V_117 = F_110 ;
V_109 -> V_226 = V_227 ;
F_143 ( V_8 ) ;
V_76 -> V_37 = V_37 ;
V_76 -> V_79 = V_109 ;
F_51 ( & V_109 -> V_119 ) ;
}
V_8 -> V_228 . V_229 ++ ;
V_8 -> V_228 . V_230 = V_231 ;
return F_144 ( V_37 , F_3 ( V_8 ) , V_8 -> V_38 , 0 ) ;
}
static void F_145 ( struct V_232 * V_233 )
{
struct V_75 * V_76 =
F_27 ( V_233 , struct V_75 , V_126 . V_233 ) ;
struct V_7 * V_8 = & V_76 -> V_8 ;
struct V_36 * V_37 ;
int V_95 = - V_234 ;
if ( V_8 -> V_139 )
goto V_71;
F_25 ( V_123 , & V_8 -> V_108 ) ;
V_95 = F_140 ( V_8 -> V_225 , V_17 ,
V_235 , 0 , & V_37 , 1 ) ;
if ( V_95 < 0 ) {
F_2 ( L_61
L_62 , - V_95 ) ;
goto V_71;
}
F_132 ( V_37 ) ;
F_2 ( L_63 ,
V_8 , V_8 -> V_19 [ V_20 ] ) ;
V_95 = F_142 ( V_8 , V_37 ) ;
switch ( V_95 ) {
case 0 :
F_2 ( L_64 ,
V_8 , V_8 -> V_19 [ V_20 ] ) ;
F_146 ( V_8 ) ;
break;
case - V_236 :
F_2 ( L_65 ,
V_8 , V_8 -> V_19 [ V_20 ] ) ;
break;
default:
F_90 ( V_237 L_66 ,
V_97 , - V_95 ,
V_8 -> V_19 [ V_20 ] ) ;
}
V_71:
F_104 ( V_8 ) ;
F_109 ( V_8 , V_95 ) ;
}
static void F_147 ( struct V_7 * V_8 , struct V_36 * V_37 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
if ( ! V_76 -> V_79 ) {
struct V_37 * V_109 = V_37 -> V_109 ;
F_50 ( & V_109 -> V_119 ) ;
F_47 ( V_76 , V_109 ) ;
V_109 -> V_120 = V_8 ;
V_109 -> V_111 = F_75 ;
V_109 -> V_115 = F_113 ;
V_109 -> V_117 = F_110 ;
V_109 -> V_121 = V_238 ;
V_109 -> V_226 = V_227 ;
F_146 ( V_8 ) ;
V_76 -> V_37 = V_37 ;
V_76 -> V_79 = V_109 ;
F_51 ( & V_109 -> V_119 ) ;
}
F_118 ( V_8 ) ;
}
static void F_148 ( struct V_232 * V_233 )
{
struct V_75 * V_76 =
F_27 ( V_233 , struct V_75 , V_126 . V_233 ) ;
struct V_7 * V_8 = & V_76 -> V_8 ;
struct V_36 * V_37 = V_76 -> V_37 ;
int V_95 = - V_234 ;
if ( V_8 -> V_139 )
goto V_71;
F_49 ( V_76 ) ;
V_37 = F_139 ( V_8 , V_76 ,
F_3 ( V_8 ) -> V_16 , V_239 , V_240 ) ;
if ( F_149 ( V_37 ) )
goto V_71;
F_2 ( L_67
L_68 , V_8 ,
V_8 -> V_19 [ V_32 ] ,
V_8 -> V_19 [ V_20 ] ,
V_8 -> V_19 [ V_28 ] ) ;
F_147 ( V_8 , V_37 ) ;
V_95 = 0 ;
V_71:
F_104 ( V_8 ) ;
F_109 ( V_8 , V_95 ) ;
}
static void F_150 ( struct V_75 * V_76 )
{
int V_241 ;
struct V_6 V_242 ;
F_2 ( L_69 , V_76 ) ;
memset ( & V_242 , 0 , sizeof( V_242 ) ) ;
V_242 . V_16 = V_243 ;
V_241 = F_144 ( V_76 -> V_37 , & V_242 , sizeof( V_242 ) , 0 ) ;
if ( ! V_241 )
F_105 ( & V_76 -> V_8 ) ;
else
F_2 ( L_70 ,
V_241 ) ;
}
static void F_151 ( struct V_75 * V_76 )
{
unsigned int V_108 = V_76 -> V_79 -> V_185 ;
if ( V_108 == V_198 && V_76 -> V_37 -> V_108 == V_244 ) {
if ( V_76 -> V_79 -> V_188 == 0 )
return;
F_2 ( L_71 ,
V_97 , V_76 -> V_79 -> V_188 ) ;
}
if ( ( 1 << V_108 ) & ( V_245 | V_246 ) ) {
if ( V_76 -> V_79 -> V_188 == 0 )
return;
F_2 ( L_72
L_73 ,
V_97 , V_76 -> V_79 -> V_188 ) ;
}
F_150 ( V_76 ) ;
}
static int F_152 ( struct V_7 * V_8 , struct V_36 * V_37 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
int V_83 = - V_90 ;
if ( ! V_76 -> V_79 ) {
struct V_37 * V_109 = V_37 -> V_109 ;
F_50 ( & V_109 -> V_119 ) ;
F_47 ( V_76 , V_109 ) ;
V_109 -> V_120 = V_8 ;
V_109 -> V_111 = F_97 ;
V_109 -> V_113 = F_106 ;
V_109 -> V_115 = F_115 ;
V_109 -> V_117 = F_110 ;
V_109 -> V_226 = V_227 ;
V_109 -> V_202 |= V_247 ;
F_153 ( V_109 , V_248 ) ;
F_154 ( V_109 ) -> V_249 = 0 ;
F_154 ( V_109 ) -> V_250 |= V_251 ;
F_143 ( V_8 ) ;
V_76 -> V_37 = V_37 ;
V_76 -> V_79 = V_109 ;
F_51 ( & V_109 -> V_119 ) ;
}
if ( ! F_41 ( V_8 ) )
goto V_71;
V_8 -> V_228 . V_229 ++ ;
V_8 -> V_228 . V_230 = V_231 ;
V_83 = F_144 ( V_37 , F_3 ( V_8 ) , V_8 -> V_38 , V_252 ) ;
switch ( V_83 ) {
case 0 :
case - V_253 :
V_8 -> V_191 ++ ;
if ( V_8 -> V_122 < V_196 )
V_8 -> V_122 = V_196 ;
}
V_71:
return V_83 ;
}
static void F_155 ( struct V_232 * V_233 )
{
struct V_75 * V_76 =
F_27 ( V_233 , struct V_75 , V_126 . V_233 ) ;
struct V_36 * V_37 = V_76 -> V_37 ;
struct V_7 * V_8 = & V_76 -> V_8 ;
int V_95 = - V_234 ;
if ( V_8 -> V_139 )
goto V_71;
if ( ! V_37 ) {
F_25 ( V_123 , & V_8 -> V_108 ) ;
V_37 = F_139 ( V_8 , V_76 ,
F_3 ( V_8 ) -> V_16 , V_235 , V_254 ) ;
if ( F_149 ( V_37 ) ) {
V_95 = F_156 ( V_37 ) ;
goto V_71;
}
} else {
int V_255 ;
V_255 = F_57 ( V_123 ,
& V_8 -> V_108 ) ;
F_151 ( V_76 ) ;
if ( V_255 )
goto V_256;
}
F_2 ( L_67
L_68 , V_8 ,
V_8 -> V_19 [ V_32 ] ,
V_8 -> V_19 [ V_20 ] ,
V_8 -> V_19 [ V_28 ] ) ;
V_95 = F_152 ( V_8 , V_37 ) ;
F_2 ( L_74 ,
V_8 , - V_95 , F_30 ( V_8 ) ,
V_37 -> V_109 -> V_185 ) ;
switch ( V_95 ) {
default:
F_90 ( L_75 ,
V_97 , V_95 ) ;
case - V_257 :
F_32 ( V_125 , & V_8 -> V_108 ) ;
F_82 ( V_8 ) ;
break;
case - V_101 :
case - V_103 :
case - V_100 :
case 0 :
case - V_253 :
case - V_258 :
F_104 ( V_8 ) ;
return;
case - V_259 :
goto V_71;
}
V_256:
V_95 = - V_84 ;
V_71:
F_104 ( V_8 ) ;
F_109 ( V_8 , V_95 ) ;
}
static void F_157 ( struct V_73 * V_74 )
{
struct V_7 * V_8 = V_74 -> V_107 ;
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
if ( V_76 -> V_37 != NULL && ! F_158 ( V_74 ) ) {
F_2 ( L_76
L_77 ,
V_8 , V_8 -> V_122 / V_260 ) ;
F_101 ( V_184 ,
& V_76 -> V_126 ,
V_8 -> V_122 ) ;
V_8 -> V_122 <<= 1 ;
if ( V_8 -> V_122 < V_196 )
V_8 -> V_122 = V_196 ;
if ( V_8 -> V_122 > V_261 )
V_8 -> V_122 = V_261 ;
} else {
F_2 ( L_78 , V_8 ) ;
F_101 ( V_184 ,
& V_76 -> V_126 , 0 ) ;
}
}
static void F_159 ( struct V_7 * V_8 , struct V_262 * V_263 )
{
long V_264 = 0 ;
if ( F_30 ( V_8 ) )
V_264 = ( long ) ( V_231 - V_8 -> V_265 ) / V_260 ;
F_160 ( V_263 , L_79
L_80 ,
V_8 -> V_228 . V_266 ,
V_8 -> V_228 . V_229 ,
V_8 -> V_228 . V_267 ,
V_264 ,
V_8 -> V_228 . V_268 ,
V_8 -> V_228 . V_269 ,
V_8 -> V_228 . V_270 ,
V_8 -> V_228 . V_271 ,
V_8 -> V_228 . V_272 ) ;
}
static void F_161 ( struct V_7 * V_8 , struct V_262 * V_263 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
F_160 ( V_263 , L_81 ,
V_76 -> V_118 ,
V_8 -> V_228 . V_266 ,
V_8 -> V_228 . V_268 ,
V_8 -> V_228 . V_269 ,
V_8 -> V_228 . V_270 ,
V_8 -> V_228 . V_271 ,
V_8 -> V_228 . V_272 ) ;
}
static void F_162 ( struct V_7 * V_8 , struct V_262 * V_263 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
long V_264 = 0 ;
if ( F_30 ( V_8 ) )
V_264 = ( long ) ( V_231 - V_8 -> V_265 ) / V_260 ;
F_160 ( V_263 , L_82 ,
V_76 -> V_118 ,
V_8 -> V_228 . V_266 ,
V_8 -> V_228 . V_229 ,
V_8 -> V_228 . V_267 ,
V_264 ,
V_8 -> V_228 . V_268 ,
V_8 -> V_228 . V_269 ,
V_8 -> V_228 . V_270 ,
V_8 -> V_228 . V_271 ,
V_8 -> V_228 . V_272 ) ;
}
static void * F_163 ( struct V_73 * V_74 , T_4 V_273 )
{
struct V_54 * V_54 ;
struct V_274 * V_4 ;
F_133 ( V_273 > V_275 - sizeof( struct V_274 ) ) ;
V_54 = F_164 ( V_21 ) ;
if ( ! V_54 )
return NULL ;
V_4 = F_165 ( V_54 ) ;
V_4 -> V_64 = V_275 ;
return V_4 -> V_180 ;
}
static void F_166 ( void * V_276 )
{
struct V_274 * V_4 ;
if ( ! V_276 )
return;
V_4 = F_27 ( V_276 , struct V_274 , V_180 ) ;
F_167 ( ( unsigned long ) V_4 ) ;
}
static int F_168 ( struct V_81 * V_82 )
{
int V_64 ;
struct V_52 * V_277 = & V_82 -> V_94 ;
struct V_7 * V_8 = V_82 -> V_78 ;
struct V_75 * V_76 =
F_27 ( V_8 , struct V_75 , V_8 ) ;
struct V_36 * V_37 = V_76 -> V_37 ;
unsigned long V_278 ;
unsigned long V_279 ;
F_35 ( V_277 ) ;
V_279 = ( unsigned long ) V_277 -> V_72 [ 0 ] . V_50 & ~ V_63 ;
V_278 = ( unsigned long ) V_277 -> V_70 [ 0 ] . V_50 & ~ V_63 ;
V_64 = F_169 ( V_37 , V_277 ,
F_170 ( V_277 -> V_70 [ 0 ] . V_50 ) , V_278 ,
V_277 -> V_72 [ 0 ] . V_50 , V_279 ) ;
if ( V_64 != V_277 -> V_64 ) {
F_90 ( V_280 L_83 ) ;
V_64 = - V_84 ;
}
return V_64 ;
}
static int F_171 ( struct V_73 * V_74 )
{
struct V_81 * V_82 = V_74 -> V_77 ;
struct V_281 * V_8 ;
struct V_282 * V_283 ;
T_1 V_64 ;
F_2 ( L_84 , F_11 ( V_82 -> V_171 ) ) ;
V_8 = V_82 -> V_78 -> V_284 ;
V_283 = F_27 ( V_8 , struct V_282 , V_285 ) ;
if ( ! F_172 ( & V_8 -> V_286 ) ) {
F_173 ( & V_8 -> V_287 , V_74 , NULL ) ;
if ( ! F_172 ( & V_8 -> V_286 ) )
return - V_84 ;
F_174 ( & V_8 -> V_287 , V_74 ) ;
}
if ( F_31 ( V_288 , & V_8 -> V_289 ) )
V_64 = - V_90 ;
else
V_64 = F_168 ( V_82 ) ;
F_175 ( & V_8 -> V_286 ) ;
if ( V_64 > 0 )
V_64 = 0 ;
return V_64 ;
}
static void F_176 ( struct V_7 * V_8 )
{
}
static void F_177 ( struct V_7 * V_8 )
{
}
static int F_178 ( const int V_224 , struct V_6 * V_13 )
{
static const struct V_11 sin = {
. V_290 = V_22 ,
. V_23 . V_24 = F_179 ( V_291 ) ,
} ;
static const struct V_12 V_14 = {
. V_292 = V_25 ,
. V_26 = V_293 ,
} ;
switch ( V_224 ) {
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
static struct V_7 * F_180 ( struct V_295 * args ,
unsigned int V_296 ,
unsigned int V_297 )
{
struct V_7 * V_8 ;
struct V_75 * V_298 ;
if ( args -> V_38 > sizeof( V_8 -> V_9 ) ) {
F_2 ( L_86 ) ;
return F_141 ( - V_299 ) ;
}
V_8 = F_181 ( args -> V_300 , sizeof( * V_298 ) , V_296 ,
V_297 ) ;
if ( V_8 == NULL ) {
F_2 ( L_87
L_88 ) ;
return F_141 ( - V_301 ) ;
}
V_298 = F_27 ( V_8 , struct V_75 , V_8 ) ;
memcpy ( & V_8 -> V_9 , args -> V_302 , args -> V_38 ) ;
V_8 -> V_38 = args -> V_38 ;
if ( args -> V_219 )
memcpy ( & V_298 -> V_219 , args -> V_219 , args -> V_38 ) ;
else {
int V_57 ;
V_57 = F_178 ( args -> V_302 -> V_16 ,
(struct V_6 * ) & V_298 -> V_219 ) ;
if ( V_57 != 0 ) {
F_60 ( V_8 ) ;
return F_141 ( V_57 ) ;
}
}
return V_8 ;
}
static struct V_7 * F_182 ( struct V_295 * args )
{
struct V_10 * V_15 = (struct V_10 * ) args -> V_302 ;
struct V_75 * V_76 ;
struct V_7 * V_8 ;
struct V_7 * V_83 ;
V_8 = F_180 ( args , V_303 ,
V_304 ) ;
if ( F_149 ( V_8 ) )
return V_8 ;
V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
V_8 -> V_305 = 0 ;
V_8 -> V_306 = sizeof( V_92 ) / sizeof( T_1 ) ;
V_8 -> V_307 = V_308 ;
V_8 -> V_309 = V_310 ;
V_8 -> V_122 = V_196 ;
V_8 -> V_311 = V_312 ;
V_8 -> V_66 = & V_313 ;
V_8 -> V_183 = & V_314 ;
switch ( V_15 -> V_315 ) {
case V_17 :
if ( V_15 -> V_18 [ 0 ] != '/' ) {
F_2 ( L_89 ,
V_15 -> V_18 ) ;
V_83 = F_141 ( - V_259 ) ;
goto V_316;
}
F_130 ( V_8 ) ;
F_183 ( & V_76 -> V_126 ,
F_145 ) ;
F_15 ( V_8 , L_90 , V_317 ) ;
break;
default:
V_83 = F_141 ( - V_294 ) ;
goto V_316;
}
F_2 ( L_91 ,
V_8 -> V_19 [ V_20 ] ) ;
if ( F_184 ( V_127 ) )
return V_8 ;
V_83 = F_141 ( - V_259 ) ;
V_316:
F_60 ( V_8 ) ;
return V_83 ;
}
static struct V_7 * F_185 ( struct V_295 * args )
{
struct V_6 * V_9 = args -> V_302 ;
struct V_7 * V_8 ;
struct V_75 * V_76 ;
struct V_7 * V_83 ;
V_8 = F_180 ( args , V_318 ,
V_318 ) ;
if ( F_149 ( V_8 ) )
return V_8 ;
V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
V_8 -> V_305 = V_240 ;
V_8 -> V_306 = 0 ;
V_8 -> V_307 = ( 1U << 16 ) - ( V_319 << 3 ) ;
V_8 -> V_309 = V_310 ;
V_8 -> V_122 = V_320 ;
V_8 -> V_311 = V_312 ;
V_8 -> V_66 = & V_321 ;
V_8 -> V_183 = & V_322 ;
switch ( V_9 -> V_16 ) {
case V_22 :
if ( ( (struct V_11 * ) V_9 ) -> V_323 != F_186 ( 0 ) )
F_130 ( V_8 ) ;
F_183 ( & V_76 -> V_126 ,
F_148 ) ;
F_15 ( V_8 , L_92 , V_324 ) ;
break;
case V_25 :
if ( ( (struct V_12 * ) V_9 ) -> V_325 != F_186 ( 0 ) )
F_130 ( V_8 ) ;
F_183 ( & V_76 -> V_126 ,
F_148 ) ;
F_15 ( V_8 , L_92 , V_326 ) ;
break;
default:
V_83 = F_141 ( - V_294 ) ;
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
if ( F_184 ( V_127 ) )
return V_8 ;
V_83 = F_141 ( - V_259 ) ;
V_316:
F_60 ( V_8 ) ;
return V_83 ;
}
static struct V_7 * F_187 ( struct V_295 * args )
{
struct V_6 * V_9 = args -> V_302 ;
struct V_7 * V_8 ;
struct V_75 * V_76 ;
struct V_7 * V_83 ;
V_8 = F_180 ( args , V_303 ,
V_304 ) ;
if ( F_149 ( V_8 ) )
return V_8 ;
V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
V_8 -> V_305 = V_254 ;
V_8 -> V_306 = sizeof( V_92 ) / sizeof( T_1 ) ;
V_8 -> V_307 = V_308 ;
V_8 -> V_309 = V_310 ;
V_8 -> V_122 = V_196 ;
V_8 -> V_311 = V_312 ;
V_8 -> V_66 = & V_327 ;
V_8 -> V_183 = & V_328 ;
switch ( V_9 -> V_16 ) {
case V_22 :
if ( ( (struct V_11 * ) V_9 ) -> V_323 != F_186 ( 0 ) )
F_130 ( V_8 ) ;
F_183 ( & V_76 -> V_126 ,
F_155 ) ;
F_15 ( V_8 , L_95 , V_329 ) ;
break;
case V_25 :
if ( ( (struct V_12 * ) V_9 ) -> V_325 != F_186 ( 0 ) )
F_130 ( V_8 ) ;
F_183 ( & V_76 -> V_126 ,
F_155 ) ;
F_15 ( V_8 , L_95 , V_330 ) ;
break;
default:
V_83 = F_141 ( - V_294 ) ;
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
if ( F_184 ( V_127 ) )
return V_8 ;
V_83 = F_141 ( - V_259 ) ;
V_316:
F_60 ( V_8 ) ;
return V_83 ;
}
static struct V_7 * F_188 ( struct V_295 * args )
{
struct V_6 * V_9 = args -> V_302 ;
struct V_7 * V_8 ;
struct V_75 * V_76 ;
struct V_282 * V_331 ;
struct V_7 * V_83 ;
if ( args -> V_284 -> V_332 ) {
return args -> V_284 -> V_332 ;
}
V_8 = F_180 ( args , V_303 ,
V_303 ) ;
if ( F_149 ( V_8 ) )
return V_8 ;
V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
V_8 -> V_305 = V_254 ;
V_8 -> V_306 = sizeof( V_92 ) / sizeof( T_1 ) ;
V_8 -> V_307 = V_308 ;
V_8 -> V_183 = & V_328 ;
F_130 ( V_8 ) ;
V_8 -> V_309 = 0 ;
V_8 -> V_122 = 0 ;
V_8 -> V_311 = 0 ;
V_8 -> V_66 = & V_333 ;
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
V_83 = F_141 ( - V_294 ) ;
goto V_316;
}
F_2 ( L_93 ,
V_8 -> V_19 [ V_20 ] ,
V_8 -> V_19 [ V_28 ] ,
V_8 -> V_19 [ V_32 ] ) ;
F_189 ( V_8 ) ;
args -> V_284 -> V_332 = V_8 ;
V_8 -> V_284 = args -> V_284 ;
V_331 = F_27 ( args -> V_284 , struct V_282 , V_285 ) ;
V_76 -> V_37 = V_331 -> V_334 ;
V_76 -> V_79 = V_331 -> V_335 ;
F_146 ( V_8 ) ;
if ( F_184 ( V_127 ) )
return V_8 ;
F_190 ( V_8 ) ;
V_83 = F_141 ( - V_259 ) ;
V_316:
F_60 ( V_8 ) ;
return V_83 ;
}
int F_191 ( void )
{
#ifdef F_192
if ( ! V_336 )
V_336 = F_193 ( V_337 ) ;
#endif
F_194 ( & V_338 ) ;
F_194 ( & V_339 ) ;
F_194 ( & V_340 ) ;
F_194 ( & V_341 ) ;
return 0 ;
}
void F_195 ( void )
{
#ifdef F_192
if ( V_336 ) {
F_196 ( V_336 ) ;
V_336 = NULL ;
}
#endif
F_197 ( & V_338 ) ;
F_197 ( & V_339 ) ;
F_197 ( & V_340 ) ;
F_197 ( & V_341 ) ;
}
static int F_198 ( const char * V_342 ,
const struct V_343 * V_344 ,
unsigned int V_345 , unsigned int V_346 )
{
unsigned long V_347 ;
int V_83 ;
if ( ! V_342 )
return - V_259 ;
V_83 = F_199 ( V_342 , 0 , & V_347 ) ;
if ( V_83 == - V_259 || V_347 < V_345 || V_347 > V_346 )
return - V_259 ;
* ( ( unsigned int * ) V_344 -> V_179 ) = V_347 ;
return 0 ;
}
static int F_200 ( const char * V_342 , const struct V_343 * V_344 )
{
return F_198 ( V_342 , V_344 ,
V_348 ,
V_349 ) ;
}
static int F_201 ( const char * V_342 ,
const struct V_343 * V_344 )
{
return F_198 ( V_342 , V_344 ,
V_350 ,
V_351 ) ;
}
static int F_202 ( const char * V_342 ,
const struct V_343 * V_344 )
{
return F_198 ( V_342 , V_344 ,
V_350 ,
V_352 ) ;
}

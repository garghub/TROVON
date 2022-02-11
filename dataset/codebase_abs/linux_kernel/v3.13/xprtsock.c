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
static int F_21 ( struct V_36 * V_37 , struct V_52 * V_53 , unsigned int V_41 , int V_42 , bool V_54 )
{
T_3 (* F_22)( struct V_36 * V_37 , struct V_55 * V_55 ,
int V_56 , T_4 V_57 , int V_58 );
struct V_55 * * V_59 ;
unsigned int V_60 ;
int V_61 , V_62 = 0 ;
V_60 = V_53 -> V_63 - V_41 ;
V_41 += V_53 -> V_64 ;
V_59 = V_53 -> V_65 + ( V_41 >> V_66 ) ;
V_41 &= ~ V_67 ;
F_22 = V_37 -> V_68 -> V_69 ;
if ( ! V_54 )
F_22 = V_70 ;
for(; ; ) {
unsigned int V_71 = F_23 (unsigned int, PAGE_SIZE - base, remainder) ;
int V_58 = V_47 ;
V_60 -= V_71 ;
if ( V_60 != 0 || V_42 )
V_58 |= V_48 ;
V_61 = F_22 ( V_37 , * V_59 , V_41 , V_71 , V_58 ) ;
if ( V_60 == 0 || V_61 != V_71 )
break;
V_62 += V_61 ;
V_59 ++ ;
V_41 = 0 ;
}
if ( V_62 == 0 )
return V_61 ;
if ( V_61 > 0 )
V_62 += V_61 ;
return V_62 ;
}
static int F_24 ( struct V_36 * V_37 , struct V_6 * V_9 , int V_38 , struct V_52 * V_53 , unsigned int V_41 , bool V_54 )
{
unsigned int V_60 = V_53 -> V_71 - V_41 ;
int V_61 , V_62 = 0 ;
if ( F_25 ( ! V_37 ) )
return - V_72 ;
F_26 ( V_73 , & V_37 -> V_58 ) ;
if ( V_41 != 0 ) {
V_9 = NULL ;
V_38 = 0 ;
}
if ( V_41 < V_53 -> V_74 [ 0 ] . V_51 || V_9 != NULL ) {
unsigned int V_71 = V_53 -> V_74 [ 0 ] . V_51 - V_41 ;
V_60 -= V_71 ;
V_61 = F_19 ( V_37 , V_9 , V_38 , & V_53 -> V_74 [ 0 ] , V_41 , V_60 != 0 ) ;
if ( V_60 == 0 || V_61 != V_71 )
goto V_75;
V_62 += V_61 ;
V_41 = 0 ;
} else
V_41 -= V_53 -> V_74 [ 0 ] . V_51 ;
if ( V_41 < V_53 -> V_63 ) {
unsigned int V_71 = V_53 -> V_63 - V_41 ;
V_60 -= V_71 ;
V_61 = F_21 ( V_37 , V_53 , V_41 , V_60 != 0 , V_54 ) ;
if ( V_60 == 0 || V_61 != V_71 )
goto V_75;
V_62 += V_61 ;
V_41 = 0 ;
} else
V_41 -= V_53 -> V_63 ;
if ( V_41 >= V_53 -> V_76 [ 0 ] . V_51 )
return V_62 ;
V_61 = F_19 ( V_37 , NULL , 0 , & V_53 -> V_76 [ 0 ] , V_41 , 0 ) ;
V_75:
if ( V_62 == 0 )
return V_61 ;
if ( V_61 > 0 )
V_62 += V_61 ;
return V_62 ;
}
static void F_27 ( struct V_77 * V_78 )
{
struct V_79 * V_80 = F_28 ( V_78 -> V_81 -> V_82 , struct V_79 , V_8 ) ;
V_80 -> V_83 -> V_84 -- ;
F_26 ( V_73 , & V_80 -> V_37 -> V_58 ) ;
}
static int F_29 ( struct V_77 * V_78 )
{
struct V_85 * V_86 = V_78 -> V_81 ;
struct V_7 * V_8 = V_86 -> V_82 ;
struct V_79 * V_80 = F_28 ( V_8 , struct V_79 , V_8 ) ;
int V_87 = - V_88 ;
F_2 ( L_9 ,
V_78 -> V_89 , V_86 -> V_90 - V_86 -> V_91 ,
V_86 -> V_90 ) ;
F_30 ( & V_8 -> V_92 ) ;
if ( F_31 ( V_8 ) ) {
if ( F_32 ( V_73 , & V_80 -> V_37 -> V_58 ) ) {
F_33 ( V_93 , & V_80 -> V_37 -> V_58 ) ;
V_80 -> V_83 -> V_84 ++ ;
F_34 ( V_78 , F_27 ) ;
}
} else {
F_26 ( V_73 , & V_80 -> V_37 -> V_58 ) ;
V_87 = - V_94 ;
}
F_35 ( & V_8 -> V_92 ) ;
return V_87 ;
}
static inline void F_36 ( struct V_52 * V_4 )
{
T_1 V_95 = V_4 -> V_71 - sizeof( V_96 ) ;
V_96 * V_41 = V_4 -> V_74 [ 0 ] . V_50 ;
* V_41 = F_37 ( V_97 | V_95 ) ;
}
static int F_38 ( struct V_77 * V_78 )
{
struct V_85 * V_86 = V_78 -> V_81 ;
struct V_7 * V_8 = V_86 -> V_82 ;
struct V_79 * V_80 =
F_28 ( V_8 , struct V_79 , V_8 ) ;
struct V_52 * V_53 = & V_86 -> V_98 ;
int V_99 ;
F_36 ( & V_86 -> V_98 ) ;
F_1 ( L_10 ,
V_86 -> V_100 -> V_50 , V_86 -> V_100 -> V_51 ) ;
V_99 = F_24 ( V_80 -> V_37 , NULL , 0 ,
V_53 , V_86 -> V_91 , true ) ;
F_2 ( L_11 ,
V_101 , V_53 -> V_71 - V_86 -> V_91 , V_99 ) ;
if ( F_39 ( V_99 >= 0 ) ) {
V_86 -> V_91 += V_99 ;
V_86 -> V_102 += V_99 ;
if ( F_39 ( V_86 -> V_91 >= V_86 -> V_90 ) ) {
V_86 -> V_91 = 0 ;
return 0 ;
}
V_99 = - V_88 ;
}
switch ( V_99 ) {
case - V_88 :
V_99 = F_29 ( V_78 ) ;
break;
default:
F_2 ( L_12 ,
- V_99 ) ;
case - V_103 :
F_40 ( V_8 ) ;
V_99 = - V_94 ;
}
return V_99 ;
}
static int F_41 ( struct V_77 * V_78 )
{
struct V_85 * V_86 = V_78 -> V_81 ;
struct V_7 * V_8 = V_86 -> V_82 ;
struct V_79 * V_80 = F_28 ( V_8 , struct V_79 , V_8 ) ;
struct V_52 * V_53 = & V_86 -> V_98 ;
int V_99 ;
F_1 ( L_10 ,
V_86 -> V_100 -> V_50 ,
V_86 -> V_100 -> V_51 ) ;
if ( ! F_42 ( V_8 ) )
return - V_94 ;
V_99 = F_24 ( V_80 -> V_37 ,
F_3 ( V_8 ) ,
V_8 -> V_38 , V_53 ,
V_86 -> V_91 , true ) ;
F_2 ( L_13 ,
V_53 -> V_71 - V_86 -> V_91 , V_99 ) ;
if ( V_99 >= 0 ) {
V_86 -> V_102 += V_99 ;
if ( V_99 >= V_86 -> V_90 )
return 0 ;
V_99 = - V_88 ;
}
switch ( V_99 ) {
case - V_72 :
V_99 = - V_94 ;
break;
case - V_88 :
V_99 = F_29 ( V_78 ) ;
break;
default:
F_2 ( L_12 ,
- V_99 ) ;
case - V_104 :
case - V_103 :
case - V_105 :
F_26 ( V_73 , & V_80 -> V_37 -> V_58 ) ;
}
return V_99 ;
}
static void F_43 ( struct V_7 * V_8 )
{
struct V_79 * V_80 = F_28 ( V_8 , struct V_79 , V_8 ) ;
struct V_36 * V_37 = V_80 -> V_37 ;
if ( V_37 != NULL ) {
F_44 ( V_37 , V_106 ) ;
F_45 ( V_8 , V_37 ) ;
}
}
static int F_46 ( struct V_77 * V_78 )
{
struct V_85 * V_86 = V_78 -> V_81 ;
struct V_7 * V_8 = V_86 -> V_82 ;
struct V_79 * V_80 = F_28 ( V_8 , struct V_79 , V_8 ) ;
struct V_52 * V_53 = & V_86 -> V_98 ;
bool V_54 = true ;
int V_99 ;
F_36 ( & V_86 -> V_98 ) ;
F_1 ( L_10 ,
V_86 -> V_100 -> V_50 ,
V_86 -> V_100 -> V_51 ) ;
if ( V_78 -> V_107 & V_108 )
V_54 = false ;
while ( 1 ) {
V_99 = F_24 ( V_80 -> V_37 ,
NULL , 0 , V_53 , V_86 -> V_91 ,
V_54 ) ;
F_2 ( L_14 ,
V_53 -> V_71 - V_86 -> V_91 , V_99 ) ;
if ( F_25 ( V_99 < 0 ) )
break;
V_86 -> V_91 += V_99 ;
V_86 -> V_102 += V_99 ;
if ( F_39 ( V_86 -> V_91 >= V_86 -> V_90 ) ) {
V_86 -> V_91 = 0 ;
return 0 ;
}
if ( V_99 != 0 )
continue;
V_99 = - V_88 ;
break;
}
switch ( V_99 ) {
case - V_72 :
V_99 = - V_94 ;
break;
case - V_88 :
V_99 = F_29 ( V_78 ) ;
break;
default:
F_2 ( L_12 ,
- V_99 ) ;
case - V_109 :
F_43 ( V_8 ) ;
case - V_105 :
case - V_94 :
case - V_103 :
F_26 ( V_73 , & V_80 -> V_37 -> V_58 ) ;
}
return V_99 ;
}
static void F_47 ( struct V_7 * V_8 , struct V_77 * V_78 )
{
struct V_85 * V_86 ;
if ( V_78 != V_8 -> V_110 )
return;
if ( V_78 == NULL )
goto V_111;
V_86 = V_78 -> V_81 ;
if ( V_86 == NULL )
goto V_111;
if ( V_86 -> V_91 == 0 )
goto V_111;
if ( V_86 -> V_91 == V_86 -> V_98 . V_71 )
goto V_111;
F_33 ( V_112 , & V_8 -> V_113 ) ;
V_111:
F_48 ( V_8 , V_78 ) ;
}
static void F_49 ( struct V_79 * V_80 , struct V_37 * V_114 )
{
V_80 -> V_115 = V_114 -> V_116 ;
V_80 -> V_117 = V_114 -> V_118 ;
V_80 -> V_119 = V_114 -> V_120 ;
}
static void F_50 ( struct V_79 * V_80 , struct V_37 * V_114 )
{
V_114 -> V_116 = V_80 -> V_115 ;
V_114 -> V_118 = V_80 -> V_117 ;
V_114 -> V_120 = V_80 -> V_119 ;
}
static void F_51 ( struct V_79 * V_80 )
{
struct V_36 * V_37 = V_80 -> V_37 ;
struct V_37 * V_114 = V_80 -> V_83 ;
if ( V_114 == NULL )
return;
V_80 -> V_121 = 0 ;
F_52 ( & V_114 -> V_122 ) ;
V_80 -> V_83 = NULL ;
V_80 -> V_37 = NULL ;
V_114 -> V_123 = NULL ;
F_50 ( V_80 , V_114 ) ;
F_53 ( & V_114 -> V_122 ) ;
V_114 -> V_124 = 0 ;
F_54 ( & V_80 -> V_8 , V_37 ) ;
F_55 ( V_37 ) ;
}
static void F_40 ( struct V_7 * V_8 )
{
struct V_79 * V_80 = F_28 ( V_8 , struct V_79 , V_8 ) ;
F_2 ( L_15 , V_8 ) ;
F_56 ( & V_80 -> V_125 ) ;
F_51 ( V_80 ) ;
V_8 -> V_126 = 0 ;
F_57 () ;
F_26 ( V_127 , & V_8 -> V_113 ) ;
F_26 ( V_112 , & V_8 -> V_113 ) ;
F_26 ( V_128 , & V_8 -> V_113 ) ;
F_58 () ;
F_59 ( V_8 ) ;
}
static void F_60 ( struct V_7 * V_8 )
{
if ( F_61 ( V_129 , & V_8 -> V_113 ) )
F_40 ( V_8 ) ;
else
F_43 ( V_8 ) ;
}
static void F_62 ( struct V_7 * V_8 )
{
F_2 ( L_16 , V_8 ) ;
F_40 ( V_8 ) ;
F_18 ( V_8 ) ;
F_63 ( V_8 ) ;
F_64 ( V_130 ) ;
}
static inline struct V_7 * F_65 ( struct V_37 * V_114 )
{
return (struct V_7 * ) V_114 -> V_123 ;
}
static int F_66 ( struct V_52 * V_53 , struct V_131 * V_132 )
{
struct V_133 V_134 = {
. V_132 = V_132 ,
. V_56 = sizeof( V_96 ) ,
. V_3 = V_132 -> V_71 - sizeof( V_96 ) ,
} ;
if ( F_67 ( V_53 , 0 , & V_134 , V_135 ) < 0 )
return - 1 ;
if ( V_134 . V_3 )
return - 1 ;
return 0 ;
}
static void F_68 ( struct V_37 * V_114 , int V_71 )
{
struct V_77 * V_78 ;
struct V_7 * V_8 ;
struct V_85 * V_136 ;
struct V_131 * V_132 ;
int V_61 , V_137 , V_138 ;
T_1 V_139 ;
T_5 * V_140 ;
F_69 ( & V_114 -> V_122 ) ;
F_2 ( L_17 , V_101 ) ;
V_8 = F_65 ( V_114 ) ;
if ( V_8 == NULL )
goto V_75;
V_132 = F_70 ( V_114 , 0 , 1 , & V_61 ) ;
if ( V_132 == NULL )
goto V_75;
V_137 = V_132 -> V_71 - sizeof( V_96 ) ;
if ( V_137 < 4 ) {
F_2 ( L_18 , V_137 ) ;
goto V_141;
}
V_140 = F_71 ( V_132 , sizeof( V_96 ) , sizeof( V_139 ) , & V_139 ) ;
if ( V_140 == NULL )
goto V_141;
F_72 ( & V_8 -> V_92 ) ;
V_136 = F_73 ( V_8 , * V_140 ) ;
if ( ! V_136 )
goto V_142;
V_78 = V_136 -> V_143 ;
V_138 = V_136 -> V_144 . V_145 ;
if ( V_138 > V_137 )
V_138 = V_137 ;
if ( F_66 ( & V_136 -> V_144 , V_132 ) ) {
F_2 ( L_19 ) ;
goto V_142;
}
F_74 ( V_78 , V_138 ) ;
V_142:
F_75 ( & V_8 -> V_92 ) ;
V_141:
F_76 ( V_114 , V_132 ) ;
V_75:
F_77 ( & V_114 -> V_122 ) ;
}
static void F_78 ( struct V_37 * V_114 , int V_71 )
{
struct V_77 * V_78 ;
struct V_7 * V_8 ;
struct V_85 * V_136 ;
struct V_131 * V_132 ;
int V_61 , V_137 , V_138 ;
T_1 V_139 ;
T_5 * V_140 ;
F_69 ( & V_114 -> V_122 ) ;
F_2 ( L_20 ) ;
if ( ! ( V_8 = F_65 ( V_114 ) ) )
goto V_75;
if ( ( V_132 = F_70 ( V_114 , 0 , 1 , & V_61 ) ) == NULL )
goto V_75;
V_137 = V_132 -> V_71 - sizeof( struct V_146 ) ;
if ( V_137 < 4 ) {
F_2 ( L_21 , V_137 ) ;
goto V_141;
}
V_140 = F_71 ( V_132 , sizeof( struct V_146 ) ,
sizeof( V_139 ) , & V_139 ) ;
if ( V_140 == NULL )
goto V_141;
F_72 ( & V_8 -> V_92 ) ;
V_136 = F_73 ( V_8 , * V_140 ) ;
if ( ! V_136 )
goto V_142;
V_78 = V_136 -> V_143 ;
if ( ( V_138 = V_136 -> V_144 . V_145 ) > V_137 )
V_138 = V_137 ;
if ( F_79 ( & V_136 -> V_144 , V_132 ) ) {
F_80 ( V_114 , V_147 ) ;
goto V_142;
}
F_80 ( V_114 , V_148 ) ;
F_81 ( V_8 , V_78 , V_138 ) ;
F_74 ( V_78 , V_138 ) ;
V_142:
F_75 ( & V_8 -> V_92 ) ;
V_141:
F_76 ( V_114 , V_132 ) ;
V_75:
F_77 ( & V_114 -> V_122 ) ;
}
static void F_82 ( struct V_7 * V_8 )
{
F_33 ( V_129 , & V_8 -> V_113 ) ;
F_83 ( V_8 ) ;
}
static inline void F_84 ( struct V_7 * V_8 , struct V_133 * V_134 )
{
struct V_79 * V_80 = F_28 ( V_8 , struct V_79 , V_8 ) ;
T_4 V_71 , V_149 ;
char * V_150 ;
V_150 = ( ( char * ) & V_80 -> V_151 ) + V_80 -> V_152 ;
V_71 = sizeof( V_80 -> V_151 ) - V_80 -> V_152 ;
V_149 = V_135 ( V_134 , V_150 , V_71 ) ;
V_80 -> V_152 += V_149 ;
if ( V_149 != V_71 )
return;
V_80 -> V_153 = F_11 ( V_80 -> V_151 ) ;
if ( V_80 -> V_153 & V_97 )
V_80 -> V_154 |= V_155 ;
else
V_80 -> V_154 &= ~ V_155 ;
V_80 -> V_153 &= V_156 ;
V_80 -> V_154 &= ~ V_157 ;
V_80 -> V_152 = 0 ;
if ( F_25 ( V_80 -> V_153 < 8 ) ) {
F_2 ( L_22 ) ;
F_82 ( V_8 ) ;
return;
}
F_2 ( L_23 ,
V_80 -> V_153 ) ;
}
static void F_85 ( struct V_79 * V_80 )
{
if ( V_80 -> V_152 == V_80 -> V_153 ) {
V_80 -> V_154 |= V_157 ;
V_80 -> V_152 = 0 ;
if ( V_80 -> V_154 & V_155 ) {
V_80 -> V_154 &= ~ V_158 ;
V_80 -> V_154 |= V_159 ;
V_80 -> V_160 = 0 ;
}
}
}
static inline void F_86 ( struct V_79 * V_80 , struct V_133 * V_134 )
{
T_4 V_71 , V_149 ;
char * V_150 ;
V_71 = sizeof( V_80 -> V_161 ) - V_80 -> V_152 ;
F_2 ( L_24 , V_71 ) ;
V_150 = ( ( char * ) & V_80 -> V_161 ) + V_80 -> V_152 ;
V_149 = V_135 ( V_134 , V_150 , V_71 ) ;
V_80 -> V_152 += V_149 ;
if ( V_149 != V_71 )
return;
V_80 -> V_154 &= ~ V_159 ;
V_80 -> V_154 |= V_162 ;
V_80 -> V_160 = 4 ;
F_2 ( L_25 ,
( V_80 -> V_154 & V_163 ) ? L_26
: L_27 ,
F_11 ( V_80 -> V_161 ) ) ;
F_85 ( V_80 ) ;
}
static inline void F_87 ( struct V_79 * V_80 ,
struct V_133 * V_134 )
{
T_4 V_71 , V_149 ;
T_1 V_56 ;
char * V_150 ;
V_56 = V_80 -> V_152 - sizeof( V_80 -> V_161 ) ;
V_71 = sizeof( V_80 -> V_164 ) - V_56 ;
F_2 ( L_28 , V_71 ) ;
V_150 = ( ( char * ) & V_80 -> V_164 ) + V_56 ;
V_149 = V_135 ( V_134 , V_150 , V_71 ) ;
V_80 -> V_152 += V_149 ;
if ( V_149 != V_71 )
return;
V_80 -> V_154 &= ~ V_162 ;
switch ( F_11 ( V_80 -> V_164 ) ) {
case V_165 :
V_80 -> V_154 |= V_166 ;
V_80 -> V_154 |= V_158 ;
V_80 -> V_154 |= V_163 ;
break;
case V_167 :
V_80 -> V_154 |= V_166 ;
V_80 -> V_154 |= V_158 ;
V_80 -> V_154 &= ~ V_163 ;
break;
default:
F_2 ( L_29 ) ;
F_82 ( & V_80 -> V_8 ) ;
}
F_85 ( V_80 ) ;
}
static inline void F_88 ( struct V_7 * V_8 ,
struct V_133 * V_134 ,
struct V_85 * V_86 )
{
struct V_79 * V_80 =
F_28 ( V_8 , struct V_79 , V_8 ) ;
struct V_52 * V_168 ;
T_4 V_71 ;
T_3 V_169 ;
V_168 = & V_86 -> V_144 ;
if ( V_80 -> V_154 & V_166 ) {
memcpy ( V_168 -> V_74 [ 0 ] . V_50 + V_80 -> V_160 ,
& V_80 -> V_164 ,
sizeof( V_80 -> V_164 ) ) ;
V_80 -> V_160 += sizeof( V_80 -> V_164 ) ;
V_80 -> V_154 &= ~ V_166 ;
}
V_71 = V_134 -> V_3 ;
if ( V_71 > V_80 -> V_153 - V_80 -> V_152 ) {
struct V_133 V_170 ;
V_71 = V_80 -> V_153 - V_80 -> V_152 ;
memcpy ( & V_170 , V_134 , sizeof( V_170 ) ) ;
V_170 . V_3 = V_71 ;
V_169 = F_67 ( V_168 , V_80 -> V_160 ,
& V_170 , V_135 ) ;
V_134 -> V_3 -= V_169 ;
V_134 -> V_56 += V_169 ;
} else
V_169 = F_67 ( V_168 , V_80 -> V_160 ,
V_134 , V_135 ) ;
if ( V_169 > 0 ) {
V_80 -> V_160 += V_169 ;
V_80 -> V_152 += V_169 ;
}
if ( V_169 != V_71 ) {
V_80 -> V_154 &= ~ V_158 ;
F_2 ( L_30 ,
F_11 ( V_80 -> V_161 ) ) ;
F_2 ( L_31
L_32 ,
V_8 , V_80 -> V_160 ,
V_80 -> V_152 , V_80 -> V_153 ) ;
return;
}
F_2 ( L_33 ,
F_11 ( V_80 -> V_161 ) , V_169 ) ;
F_2 ( L_34
L_35 , V_8 , V_80 -> V_160 ,
V_80 -> V_152 , V_80 -> V_153 ) ;
if ( V_80 -> V_160 == V_86 -> V_144 . V_145 )
V_80 -> V_154 &= ~ V_158 ;
else if ( V_80 -> V_152 == V_80 -> V_153 ) {
if ( V_80 -> V_154 & V_155 )
V_80 -> V_154 &= ~ V_158 ;
}
}
static inline int F_89 ( struct V_7 * V_8 ,
struct V_133 * V_134 )
{
struct V_79 * V_80 =
F_28 ( V_8 , struct V_79 , V_8 ) ;
struct V_85 * V_86 ;
F_2 ( L_36 , F_11 ( V_80 -> V_161 ) ) ;
F_72 ( & V_8 -> V_92 ) ;
V_86 = F_73 ( V_8 , V_80 -> V_161 ) ;
if ( ! V_86 ) {
F_2 ( L_37 ,
F_11 ( V_80 -> V_161 ) ) ;
F_75 ( & V_8 -> V_92 ) ;
return - 1 ;
}
F_88 ( V_8 , V_134 , V_86 ) ;
if ( ! ( V_80 -> V_154 & V_158 ) )
F_74 ( V_86 -> V_143 , V_80 -> V_160 ) ;
F_75 ( & V_8 -> V_92 ) ;
return 0 ;
}
static inline int F_90 ( struct V_7 * V_8 ,
struct V_133 * V_134 )
{
struct V_79 * V_80 =
F_28 ( V_8 , struct V_79 , V_8 ) ;
struct V_85 * V_86 ;
V_86 = F_91 ( V_8 ) ;
if ( V_86 == NULL ) {
F_92 ( V_171 L_38 ) ;
F_83 ( V_8 ) ;
return - 1 ;
}
V_86 -> V_172 = V_80 -> V_161 ;
F_2 ( L_39 , F_11 ( V_86 -> V_172 ) ) ;
F_88 ( V_8 , V_134 , V_86 ) ;
if ( ! ( V_80 -> V_154 & V_158 ) ) {
struct V_173 * V_174 = V_8 -> V_174 ;
F_2 ( L_40 ) ;
F_72 ( & V_174 -> V_175 ) ;
F_93 ( & V_86 -> V_176 , & V_174 -> V_177 ) ;
F_75 ( & V_174 -> V_175 ) ;
F_94 ( & V_174 -> V_178 ) ;
}
V_86 -> V_144 . V_71 = V_80 -> V_160 ;
return 0 ;
}
static inline int F_95 ( struct V_7 * V_8 ,
struct V_133 * V_134 )
{
struct V_79 * V_80 =
F_28 ( V_8 , struct V_79 , V_8 ) ;
return ( V_80 -> V_154 & V_163 ) ?
F_89 ( V_8 , V_134 ) :
F_90 ( V_8 , V_134 ) ;
}
static inline int F_95 ( struct V_7 * V_8 ,
struct V_133 * V_134 )
{
return F_89 ( V_8 , V_134 ) ;
}
static void F_96 ( struct V_7 * V_8 ,
struct V_133 * V_134 )
{
struct V_79 * V_80 =
F_28 ( V_8 , struct V_79 , V_8 ) ;
if ( F_95 ( V_8 , V_134 ) == 0 )
F_85 ( V_80 ) ;
else {
V_80 -> V_154 &= ~ V_158 ;
}
}
static inline void F_97 ( struct V_79 * V_80 , struct V_133 * V_134 )
{
T_4 V_71 ;
V_71 = V_80 -> V_153 - V_80 -> V_152 ;
if ( V_71 > V_134 -> V_3 )
V_71 = V_134 -> V_3 ;
V_134 -> V_3 -= V_71 ;
V_134 -> V_56 += V_71 ;
V_80 -> V_152 += V_71 ;
F_2 ( L_41 , V_71 ) ;
F_85 ( V_80 ) ;
}
static int F_98 ( T_6 * V_179 , struct V_131 * V_132 , unsigned int V_56 , T_4 V_71 )
{
struct V_7 * V_8 = V_179 -> V_180 . V_181 ;
struct V_79 * V_80 = F_28 ( V_8 , struct V_79 , V_8 ) ;
struct V_133 V_134 = {
. V_132 = V_132 ,
. V_56 = V_56 ,
. V_3 = V_71 ,
} ;
F_2 ( L_42 ) ;
do {
if ( V_80 -> V_154 & V_157 ) {
F_84 ( V_8 , & V_134 ) ;
continue;
}
if ( V_80 -> V_154 & V_159 ) {
F_86 ( V_80 , & V_134 ) ;
continue;
}
if ( V_80 -> V_154 & V_162 ) {
F_87 ( V_80 , & V_134 ) ;
continue;
}
if ( V_80 -> V_154 & V_158 ) {
F_96 ( V_8 , & V_134 ) ;
continue;
}
F_97 ( V_80 , & V_134 ) ;
} while ( V_134 . V_3 );
F_2 ( L_43 ) ;
return V_71 - V_134 . V_3 ;
}
static void F_99 ( struct V_37 * V_114 , int V_182 )
{
struct V_7 * V_8 ;
T_6 V_179 ;
int V_183 ;
F_2 ( L_44 ) ;
F_69 ( & V_114 -> V_122 ) ;
if ( ! ( V_8 = F_65 ( V_114 ) ) )
goto V_75;
if ( V_8 -> V_126 )
V_8 -> V_126 = 0 ;
V_179 . V_180 . V_181 = V_8 ;
do {
V_179 . V_3 = 65536 ;
V_183 = F_100 ( V_114 , & V_179 , F_98 ) ;
} while ( V_183 > 0 );
V_75:
F_77 ( & V_114 -> V_122 ) ;
}
static void F_101 ( struct V_7 * V_8 ,
unsigned long V_184 )
{
struct V_79 * V_80 ;
if ( F_102 ( V_8 ) )
return;
F_33 ( V_127 , & V_8 -> V_113 ) ;
V_80 = F_28 ( V_8 , struct V_79 , V_8 ) ;
F_103 ( V_185 , & V_80 -> V_125 ,
V_184 ) ;
}
static void F_104 ( struct V_7 * V_8 )
{
struct V_79 * V_80 ;
V_80 = F_28 ( V_8 , struct V_79 , V_8 ) ;
if ( ! F_32 ( V_127 , & V_8 -> V_113 ) ||
! F_105 ( & V_80 -> V_125 ) )
return;
F_26 ( V_127 , & V_8 -> V_113 ) ;
F_106 ( V_8 ) ;
}
static void F_107 ( struct V_7 * V_8 )
{
F_57 () ;
F_26 ( V_127 , & V_8 -> V_113 ) ;
F_26 ( V_129 , & V_8 -> V_113 ) ;
F_26 ( V_112 , & V_8 -> V_113 ) ;
F_26 ( V_128 , & V_8 -> V_113 ) ;
F_58 () ;
}
static void F_108 ( struct V_7 * V_8 )
{
F_107 ( V_8 ) ;
F_59 ( V_8 ) ;
}
static void F_109 ( struct V_37 * V_114 )
{
struct V_7 * V_8 ;
F_69 ( & V_114 -> V_122 ) ;
if ( ! ( V_8 = F_65 ( V_114 ) ) )
goto V_75;
F_2 ( L_45 , V_8 ) ;
F_2 ( L_46 ,
V_114 -> V_186 , F_31 ( V_8 ) ,
F_110 ( V_114 , V_187 ) ,
F_110 ( V_114 , V_188 ) ,
V_114 -> V_189 ) ;
F_111 ( V_8 , V_114 -> V_190 ) ;
switch ( V_114 -> V_186 ) {
case V_191 :
F_72 ( & V_8 -> V_92 ) ;
if ( ! F_112 ( V_8 ) ) {
struct V_79 * V_80 = F_28 ( V_8 ,
struct V_79 , V_8 ) ;
V_80 -> V_152 = 0 ;
V_80 -> V_153 = 0 ;
V_80 -> V_160 = 0 ;
V_80 -> V_154 =
V_157 | V_159 ;
V_8 -> V_192 ++ ;
F_113 ( V_8 , - V_88 ) ;
}
F_75 ( & V_8 -> V_92 ) ;
break;
case V_193 :
V_8 -> V_192 ++ ;
V_8 -> V_126 = 0 ;
F_33 ( V_128 , & V_8 -> V_113 ) ;
F_57 () ;
F_26 ( V_194 , & V_8 -> V_113 ) ;
F_26 ( V_112 , & V_8 -> V_113 ) ;
F_58 () ;
F_101 ( V_8 , V_195 ) ;
break;
case V_196 :
V_8 -> V_192 ++ ;
F_26 ( V_194 , & V_8 -> V_113 ) ;
F_82 ( V_8 ) ;
case V_197 :
if ( V_8 -> V_126 < V_198 )
V_8 -> V_126 = V_198 ;
break;
case V_199 :
F_33 ( V_128 , & V_8 -> V_113 ) ;
F_101 ( V_8 , V_195 ) ;
F_57 () ;
F_26 ( V_194 , & V_8 -> V_113 ) ;
F_58 () ;
break;
case V_200 :
F_104 ( V_8 ) ;
F_108 ( V_8 ) ;
}
V_75:
F_77 ( & V_114 -> V_122 ) ;
}
static void F_114 ( struct V_37 * V_114 )
{
struct V_36 * V_37 ;
struct V_7 * V_8 ;
if ( F_25 ( ! ( V_37 = V_114 -> V_190 ) ) )
return;
F_26 ( V_93 , & V_37 -> V_58 ) ;
if ( F_25 ( ! ( V_8 = F_65 ( V_114 ) ) ) )
return;
if ( F_61 ( V_73 , & V_37 -> V_58 ) == 0 )
return;
F_115 ( V_8 ) ;
}
static void F_116 ( struct V_37 * V_114 )
{
F_69 ( & V_114 -> V_122 ) ;
if ( F_117 ( V_114 ) )
F_114 ( V_114 ) ;
F_77 ( & V_114 -> V_122 ) ;
}
static void F_118 ( struct V_37 * V_114 )
{
F_69 ( & V_114 -> V_122 ) ;
if ( F_119 ( V_114 ) )
F_114 ( V_114 ) ;
F_77 ( & V_114 -> V_122 ) ;
}
static void F_120 ( struct V_7 * V_8 )
{
struct V_79 * V_80 = F_28 ( V_8 , struct V_79 , V_8 ) ;
struct V_37 * V_114 = V_80 -> V_83 ;
if ( V_80 -> V_201 ) {
V_114 -> V_202 |= V_203 ;
V_114 -> V_204 = V_80 -> V_201 * V_8 -> V_205 * 2 ;
}
if ( V_80 -> V_206 ) {
V_114 -> V_202 |= V_207 ;
V_114 -> V_208 = V_80 -> V_206 * V_8 -> V_205 * 2 ;
V_114 -> V_120 ( V_114 ) ;
}
}
static void F_121 ( struct V_7 * V_8 , T_4 V_206 , T_4 V_201 )
{
struct V_79 * V_80 = F_28 ( V_8 , struct V_79 , V_8 ) ;
V_80 -> V_206 = 0 ;
if ( V_206 )
V_80 -> V_206 = V_206 + 1024 ;
V_80 -> V_201 = 0 ;
if ( V_201 )
V_80 -> V_201 = V_201 + 1024 ;
F_120 ( V_8 ) ;
}
static void F_122 ( struct V_7 * V_8 , struct V_77 * V_78 )
{
F_81 ( V_8 , V_78 , - V_209 ) ;
}
static unsigned short F_123 ( void )
{
unsigned short V_210 = V_211 - V_212 ;
unsigned short rand = ( unsigned short ) F_124 () % V_210 ;
return rand + V_212 ;
}
static void F_125 ( struct V_7 * V_8 , unsigned short V_213 )
{
F_2 ( L_47 , V_8 , V_213 ) ;
F_126 ( F_3 ( V_8 ) , V_213 ) ;
F_16 ( V_8 ) ;
}
static unsigned short F_127 ( struct V_79 * V_80 )
{
unsigned short V_213 = V_80 -> V_121 ;
if ( V_213 == 0 && V_80 -> V_8 . V_214 )
V_213 = F_123 () ;
return V_213 ;
}
static unsigned short F_128 ( struct V_79 * V_80 , unsigned short V_213 )
{
if ( V_80 -> V_121 != 0 )
V_80 -> V_121 = 0 ;
if ( ! V_80 -> V_8 . V_214 )
return 0 ;
if ( V_213 <= V_212 || V_213 > V_211 )
return V_211 ;
return -- V_213 ;
}
static int F_129 ( struct V_79 * V_80 , struct V_36 * V_37 )
{
struct V_215 V_216 ;
int V_61 , V_217 = 0 ;
unsigned short V_213 = F_127 ( V_80 ) ;
unsigned short V_218 ;
memcpy ( & V_216 , & V_80 -> V_219 , V_80 -> V_8 . V_38 ) ;
do {
F_126 ( (struct V_6 * ) & V_216 , V_213 ) ;
V_61 = F_130 ( V_37 , (struct V_6 * ) & V_216 ,
V_80 -> V_8 . V_38 ) ;
if ( V_213 == 0 )
break;
if ( V_61 == 0 ) {
V_80 -> V_121 = V_213 ;
break;
}
V_218 = V_213 ;
V_213 = F_128 ( V_80 , V_213 ) ;
if ( V_213 > V_218 )
V_217 ++ ;
} while ( V_61 == - V_220 && V_217 != 2 );
if ( V_216 . V_221 == V_22 )
F_2 ( L_48 , V_101 ,
& ( (struct V_11 * ) & V_216 ) -> V_23 ,
V_213 , V_61 ? L_49 : L_50 , V_61 ) ;
else
F_2 ( L_51 , V_101 ,
& ( (struct V_12 * ) & V_216 ) -> V_26 ,
V_213 , V_61 ? L_49 : L_50 , V_61 ) ;
return V_61 ;
}
static void F_131 ( struct V_77 * V_78 )
{
F_132 () ;
F_133 ( F_134 ( V_78 -> V_222 -> V_223 ) ) ;
F_135 () ;
}
static void F_136 ( struct V_7 * V_8 , unsigned short V_213 )
{
}
static inline void F_137 ( struct V_36 * V_37 )
{
struct V_37 * V_114 = V_37 -> V_114 ;
F_138 ( V_114 , L_52 ,
& V_224 [ 1 ] , L_53 , & V_225 [ 1 ] ) ;
}
static inline void F_139 ( struct V_36 * V_37 )
{
struct V_37 * V_114 = V_37 -> V_114 ;
F_138 ( V_114 , L_54 ,
& V_224 [ 0 ] , L_55 , & V_225 [ 0 ] ) ;
}
static inline void F_140 ( struct V_36 * V_37 )
{
struct V_37 * V_114 = V_37 -> V_114 ;
F_138 ( V_114 , L_56 ,
& V_224 [ 1 ] , L_57 , & V_225 [ 1 ] ) ;
}
static inline void F_141 ( int V_226 , struct V_36 * V_37 )
{
F_142 ( F_143 ( V_37 -> V_114 ) ) ;
if ( F_143 ( V_37 -> V_114 ) )
return;
switch ( V_226 ) {
case V_17 :
F_137 ( V_37 ) ;
break;
case V_22 :
F_139 ( V_37 ) ;
break;
case V_25 :
F_140 ( V_37 ) ;
break;
}
}
static inline void F_137 ( struct V_36 * V_37 )
{
}
static inline void F_139 ( struct V_36 * V_37 )
{
}
static inline void F_140 ( struct V_36 * V_37 )
{
}
static inline void F_141 ( int V_226 , struct V_36 * V_37 )
{
}
static void F_144 ( struct V_227 * V_228 )
{
}
static struct V_36 * F_145 ( struct V_7 * V_8 ,
struct V_79 * V_80 , int V_226 , int type , int V_30 )
{
struct V_36 * V_37 ;
int V_61 ;
V_61 = F_146 ( V_8 -> V_229 , V_226 , type , V_30 , & V_37 , 1 ) ;
if ( V_61 < 0 ) {
F_2 ( L_58 ,
V_30 , - V_61 ) ;
goto V_75;
}
F_141 ( V_226 , V_37 ) ;
V_61 = F_129 ( V_80 , V_37 ) ;
if ( V_61 ) {
F_55 ( V_37 ) ;
goto V_75;
}
return V_37 ;
V_75:
return F_147 ( V_61 ) ;
}
static int F_148 ( struct V_7 * V_8 ,
struct V_36 * V_37 )
{
struct V_79 * V_80 = F_28 ( V_8 , struct V_79 ,
V_8 ) ;
if ( ! V_80 -> V_83 ) {
struct V_37 * V_114 = V_37 -> V_114 ;
F_52 ( & V_114 -> V_122 ) ;
F_49 ( V_80 , V_114 ) ;
V_114 -> V_123 = V_8 ;
V_114 -> V_116 = F_68 ;
V_114 -> V_120 = F_116 ;
V_114 -> V_230 = V_231 ;
F_149 ( V_8 ) ;
V_80 -> V_37 = V_37 ;
V_80 -> V_83 = V_114 ;
F_53 ( & V_114 -> V_122 ) ;
}
V_8 -> V_232 . V_233 ++ ;
V_8 -> V_232 . V_234 = V_235 ;
return F_150 ( V_37 , F_3 ( V_8 ) , V_8 -> V_38 , 0 ) ;
}
static int F_151 ( struct V_79 * V_80 )
{
struct V_7 * V_8 = & V_80 -> V_8 ;
struct V_36 * V_37 ;
int V_99 = - V_236 ;
V_237 -> V_58 |= V_238 ;
F_26 ( V_127 , & V_8 -> V_113 ) ;
V_99 = F_146 ( V_8 -> V_229 , V_17 ,
V_239 , 0 , & V_37 , 1 ) ;
if ( V_99 < 0 ) {
F_2 ( L_59
L_60 , - V_99 ) ;
goto V_75;
}
F_137 ( V_37 ) ;
F_2 ( L_61 ,
V_8 , V_8 -> V_19 [ V_20 ] ) ;
V_99 = F_148 ( V_8 , V_37 ) ;
F_152 ( V_8 , V_37 , V_99 ) ;
switch ( V_99 ) {
case 0 :
F_2 ( L_62 ,
V_8 , V_8 -> V_19 [ V_20 ] ) ;
F_153 ( V_8 ) ;
break;
case - V_240 :
F_2 ( L_63 ,
V_8 , V_8 -> V_19 [ V_20 ] ) ;
break;
case - V_105 :
F_2 ( L_64 ,
V_8 , V_8 -> V_19 [ V_20 ] ) ;
break;
default:
F_92 ( V_241 L_65 ,
V_101 , - V_99 ,
V_8 -> V_19 [ V_20 ] ) ;
}
V_75:
F_106 ( V_8 ) ;
F_113 ( V_8 , V_99 ) ;
V_237 -> V_58 &= ~ V_238 ;
return V_99 ;
}
static void F_154 ( struct V_7 * V_8 , struct V_77 * V_78 )
{
struct V_79 * V_80 = F_28 ( V_8 , struct V_79 , V_8 ) ;
int V_87 ;
if ( F_155 ( V_78 ) ) {
F_156 ( V_78 , - V_94 ) ;
return;
}
V_87 = F_151 ( V_80 ) ;
if ( V_87 && ! F_157 ( V_78 ) )
F_158 ( 15000 ) ;
}
static void F_159 ( struct V_7 * V_8 )
{
struct V_79 * V_80 = F_28 ( V_8 , struct V_79 ,
V_8 ) ;
if ( V_8 -> V_242 )
F_160 ( V_80 -> V_83 ) ;
}
int F_161 ( struct V_7 * V_8 , int V_243 )
{
struct V_79 * V_80 = F_28 ( V_8 , struct V_79 ,
V_8 ) ;
int V_61 = 0 ;
if ( V_243 ) {
V_8 -> V_242 ++ ;
F_159 ( V_8 ) ;
} else if ( V_8 -> V_242 ) {
V_8 -> V_242 -- ;
F_162 ( V_80 -> V_83 ) ;
}
return V_61 ;
}
static void F_159 ( struct V_7 * V_8 )
{
}
static void F_163 ( struct V_7 * V_8 , struct V_36 * V_37 )
{
struct V_79 * V_80 = F_28 ( V_8 , struct V_79 , V_8 ) ;
if ( ! V_80 -> V_83 ) {
struct V_37 * V_114 = V_37 -> V_114 ;
F_52 ( & V_114 -> V_122 ) ;
F_49 ( V_80 , V_114 ) ;
V_114 -> V_123 = V_8 ;
V_114 -> V_116 = F_78 ;
V_114 -> V_120 = F_116 ;
V_114 -> V_124 = V_244 ;
V_114 -> V_230 = V_231 ;
F_153 ( V_8 ) ;
V_80 -> V_37 = V_37 ;
V_80 -> V_83 = V_114 ;
F_159 ( V_8 ) ;
F_53 ( & V_114 -> V_122 ) ;
}
F_120 ( V_8 ) ;
}
static void F_164 ( struct V_227 * V_228 )
{
struct V_79 * V_80 =
F_28 ( V_228 , struct V_79 , V_125 . V_228 ) ;
struct V_7 * V_8 = & V_80 -> V_8 ;
struct V_36 * V_37 = V_80 -> V_37 ;
int V_99 = - V_236 ;
V_237 -> V_58 |= V_238 ;
F_51 ( V_80 ) ;
V_37 = F_145 ( V_8 , V_80 ,
F_3 ( V_8 ) -> V_16 , V_245 , V_246 ) ;
if ( F_165 ( V_37 ) )
goto V_75;
F_2 ( L_66
L_67 , V_8 ,
V_8 -> V_19 [ V_32 ] ,
V_8 -> V_19 [ V_20 ] ,
V_8 -> V_19 [ V_28 ] ) ;
F_163 ( V_8 , V_37 ) ;
F_152 ( V_8 , V_37 , 0 ) ;
V_99 = 0 ;
V_75:
F_106 ( V_8 ) ;
F_113 ( V_8 , V_99 ) ;
V_237 -> V_58 &= ~ V_238 ;
}
static void F_166 ( struct V_79 * V_80 )
{
int V_247 ;
struct V_6 V_248 ;
F_2 ( L_68 , V_80 ) ;
memset ( & V_248 , 0 , sizeof( V_248 ) ) ;
V_248 . V_16 = V_249 ;
V_247 = F_150 ( V_80 -> V_37 , & V_248 , sizeof( V_248 ) , 0 ) ;
F_167 ( & V_80 -> V_8 ,
V_80 -> V_37 , V_247 ) ;
if ( ! V_247 )
F_107 ( & V_80 -> V_8 ) ;
F_2 ( L_69 , V_247 ) ;
}
static void F_168 ( struct V_79 * V_80 )
{
unsigned int V_113 = V_80 -> V_83 -> V_186 ;
if ( V_113 == V_200 && V_80 -> V_37 -> V_113 == V_250 ) {
if ( V_80 -> V_83 -> V_189 == 0 )
return;
F_2 ( L_70 ,
V_101 , V_80 -> V_83 -> V_189 ) ;
}
if ( ( 1 << V_113 ) & ( V_251 | V_252 ) ) {
if ( V_80 -> V_83 -> V_189 == 0 )
return;
F_2 ( L_71
L_72 ,
V_101 , V_80 -> V_83 -> V_189 ) ;
}
F_166 ( V_80 ) ;
}
static int F_169 ( struct V_7 * V_8 , struct V_36 * V_37 )
{
struct V_79 * V_80 = F_28 ( V_8 , struct V_79 , V_8 ) ;
int V_87 = - V_94 ;
if ( ! V_80 -> V_83 ) {
struct V_37 * V_114 = V_37 -> V_114 ;
unsigned int V_253 = V_8 -> V_184 -> V_254 / V_255 ;
unsigned int V_256 = V_8 -> V_184 -> V_257 + 1 ;
unsigned int V_258 = 1 ;
F_170 ( V_37 , V_259 , V_260 ,
( char * ) & V_258 , sizeof( V_258 ) ) ;
F_170 ( V_37 , V_261 , V_262 ,
( char * ) & V_253 , sizeof( V_253 ) ) ;
F_170 ( V_37 , V_261 , V_263 ,
( char * ) & V_253 , sizeof( V_253 ) ) ;
F_170 ( V_37 , V_261 , V_264 ,
( char * ) & V_256 , sizeof( V_256 ) ) ;
F_52 ( & V_114 -> V_122 ) ;
F_49 ( V_80 , V_114 ) ;
V_114 -> V_123 = V_8 ;
V_114 -> V_116 = F_99 ;
V_114 -> V_118 = F_109 ;
V_114 -> V_120 = F_118 ;
V_114 -> V_230 = V_231 ;
V_114 -> V_202 |= V_265 ;
F_171 ( V_114 , V_266 ) ;
F_172 ( V_114 ) -> V_267 = 0 ;
F_172 ( V_114 ) -> V_268 |= V_269 ;
F_149 ( V_8 ) ;
V_80 -> V_37 = V_37 ;
V_80 -> V_83 = V_114 ;
F_53 ( & V_114 -> V_122 ) ;
}
if ( ! F_42 ( V_8 ) )
goto V_75;
F_159 ( V_8 ) ;
V_8 -> V_232 . V_233 ++ ;
V_8 -> V_232 . V_234 = V_235 ;
V_87 = F_150 ( V_37 , F_3 ( V_8 ) , V_8 -> V_38 , V_270 ) ;
switch ( V_87 ) {
case 0 :
case - V_271 :
if ( V_8 -> V_126 < V_198 )
V_8 -> V_126 = V_198 ;
}
V_75:
return V_87 ;
}
static void F_173 ( struct V_227 * V_228 )
{
struct V_79 * V_80 =
F_28 ( V_228 , struct V_79 , V_125 . V_228 ) ;
struct V_36 * V_37 = V_80 -> V_37 ;
struct V_7 * V_8 = & V_80 -> V_8 ;
int V_99 = - V_236 ;
V_237 -> V_58 |= V_238 ;
if ( ! V_37 ) {
F_26 ( V_127 , & V_8 -> V_113 ) ;
V_37 = F_145 ( V_8 , V_80 ,
F_3 ( V_8 ) -> V_16 , V_239 , V_272 ) ;
if ( F_165 ( V_37 ) ) {
V_99 = F_174 ( V_37 ) ;
goto V_75;
}
} else {
int V_273 ;
V_273 = F_61 ( V_127 ,
& V_8 -> V_113 ) ;
F_168 ( V_80 ) ;
if ( V_273 )
goto V_274;
}
F_2 ( L_66
L_67 , V_8 ,
V_8 -> V_19 [ V_32 ] ,
V_8 -> V_19 [ V_20 ] ,
V_8 -> V_19 [ V_28 ] ) ;
V_99 = F_169 ( V_8 , V_37 ) ;
F_152 ( V_8 , V_37 , V_99 ) ;
F_2 ( L_73 ,
V_8 , - V_99 , F_31 ( V_8 ) ,
V_37 -> V_114 -> V_186 ) ;
switch ( V_99 ) {
default:
F_92 ( L_74 ,
V_101 , V_99 ) ;
case - V_275 :
F_82 ( V_8 ) ;
break;
case 0 :
case - V_271 :
case - V_276 :
F_106 ( V_8 ) ;
V_237 -> V_58 &= ~ V_238 ;
return;
case - V_277 :
case - V_105 :
case - V_109 :
case - V_104 :
goto V_75;
}
V_274:
V_99 = - V_88 ;
V_75:
F_106 ( V_8 ) ;
F_113 ( V_8 , V_99 ) ;
V_237 -> V_58 &= ~ V_238 ;
}
static void F_175 ( struct V_7 * V_8 , struct V_77 * V_78 )
{
struct V_79 * V_80 = F_28 ( V_8 , struct V_79 , V_8 ) ;
if ( V_80 -> V_37 != NULL && ! F_157 ( V_78 ) ) {
F_2 ( L_75
L_76 ,
V_8 , V_8 -> V_126 / V_255 ) ;
F_103 ( V_185 ,
& V_80 -> V_125 ,
V_8 -> V_126 ) ;
V_8 -> V_126 <<= 1 ;
if ( V_8 -> V_126 < V_198 )
V_8 -> V_126 = V_198 ;
if ( V_8 -> V_126 > V_278 )
V_8 -> V_126 = V_278 ;
} else {
F_2 ( L_77 , V_8 ) ;
F_103 ( V_185 ,
& V_80 -> V_125 , 0 ) ;
}
}
static void F_176 ( struct V_7 * V_8 , struct V_279 * V_280 )
{
long V_281 = 0 ;
if ( F_31 ( V_8 ) )
V_281 = ( long ) ( V_235 - V_8 -> V_282 ) / V_255 ;
F_177 ( V_280 , L_78
L_79 ,
V_8 -> V_232 . V_283 ,
V_8 -> V_232 . V_233 ,
V_8 -> V_232 . V_284 ,
V_281 ,
V_8 -> V_232 . V_285 ,
V_8 -> V_232 . V_286 ,
V_8 -> V_232 . V_287 ,
V_8 -> V_232 . V_288 ,
V_8 -> V_232 . V_289 ,
V_8 -> V_232 . V_290 ,
V_8 -> V_232 . V_291 ,
V_8 -> V_232 . V_292 ) ;
}
static void F_178 ( struct V_7 * V_8 , struct V_279 * V_280 )
{
struct V_79 * V_80 = F_28 ( V_8 , struct V_79 , V_8 ) ;
F_177 ( V_280 , L_80
L_81 ,
V_80 -> V_121 ,
V_8 -> V_232 . V_283 ,
V_8 -> V_232 . V_285 ,
V_8 -> V_232 . V_286 ,
V_8 -> V_232 . V_287 ,
V_8 -> V_232 . V_288 ,
V_8 -> V_232 . V_289 ,
V_8 -> V_232 . V_290 ,
V_8 -> V_232 . V_291 ,
V_8 -> V_232 . V_292 ) ;
}
static void F_179 ( struct V_7 * V_8 , struct V_279 * V_280 )
{
struct V_79 * V_80 = F_28 ( V_8 , struct V_79 , V_8 ) ;
long V_281 = 0 ;
if ( F_31 ( V_8 ) )
V_281 = ( long ) ( V_235 - V_8 -> V_282 ) / V_255 ;
F_177 ( V_280 , L_82
L_79 ,
V_80 -> V_121 ,
V_8 -> V_232 . V_283 ,
V_8 -> V_232 . V_233 ,
V_8 -> V_232 . V_284 ,
V_281 ,
V_8 -> V_232 . V_285 ,
V_8 -> V_232 . V_286 ,
V_8 -> V_232 . V_287 ,
V_8 -> V_232 . V_288 ,
V_8 -> V_232 . V_289 ,
V_8 -> V_232 . V_290 ,
V_8 -> V_232 . V_291 ,
V_8 -> V_232 . V_292 ) ;
}
static void * F_180 ( struct V_77 * V_78 , T_4 V_57 )
{
struct V_55 * V_55 ;
struct V_293 * V_4 ;
F_142 ( V_57 > V_294 - sizeof( struct V_293 ) ) ;
if ( V_57 > V_294 - sizeof( struct V_293 ) )
return NULL ;
V_55 = F_181 ( V_21 ) ;
if ( ! V_55 )
return NULL ;
V_4 = F_182 ( V_55 ) ;
V_4 -> V_71 = V_294 ;
return V_4 -> V_181 ;
}
static void F_183 ( void * V_295 )
{
struct V_293 * V_4 ;
if ( ! V_295 )
return;
V_4 = F_28 ( V_295 , struct V_293 , V_181 ) ;
F_184 ( ( unsigned long ) V_4 ) ;
}
static int F_185 ( struct V_85 * V_86 )
{
int V_71 ;
struct V_52 * V_296 = & V_86 -> V_98 ;
struct V_7 * V_8 = V_86 -> V_82 ;
struct V_79 * V_80 =
F_28 ( V_8 , struct V_79 , V_8 ) ;
struct V_36 * V_37 = V_80 -> V_37 ;
unsigned long V_297 ;
unsigned long V_298 ;
F_36 ( V_296 ) ;
V_298 = ( unsigned long ) V_296 -> V_76 [ 0 ] . V_50 & ~ V_67 ;
V_297 = ( unsigned long ) V_296 -> V_74 [ 0 ] . V_50 & ~ V_67 ;
V_71 = F_186 ( V_37 , V_296 ,
F_187 ( V_296 -> V_74 [ 0 ] . V_50 ) , V_297 ,
V_296 -> V_76 [ 0 ] . V_50 , V_298 ) ;
if ( V_71 != V_296 -> V_71 ) {
F_92 ( V_299 L_83 ) ;
V_71 = - V_88 ;
}
return V_71 ;
}
static int F_188 ( struct V_77 * V_78 )
{
struct V_85 * V_86 = V_78 -> V_81 ;
struct V_300 * V_8 ;
T_1 V_71 ;
F_2 ( L_84 , F_11 ( V_86 -> V_172 ) ) ;
V_8 = V_86 -> V_82 -> V_301 ;
if ( ! F_189 ( & V_8 -> V_302 ) ) {
F_190 ( & V_8 -> V_303 , V_78 , NULL ) ;
if ( ! F_189 ( & V_8 -> V_302 ) )
return - V_88 ;
F_191 ( & V_8 -> V_303 , V_78 ) ;
}
if ( F_32 ( V_304 , & V_8 -> V_305 ) )
V_71 = - V_94 ;
else
V_71 = F_185 ( V_86 ) ;
F_192 ( & V_8 -> V_302 ) ;
if ( V_71 > 0 )
V_71 = 0 ;
return V_71 ;
}
static void F_193 ( struct V_7 * V_8 )
{
}
static void F_194 ( struct V_7 * V_8 )
{
}
static int F_195 ( const int V_226 , struct V_6 * V_13 )
{
static const struct V_11 sin = {
. V_306 = V_22 ,
. V_23 . V_24 = F_196 ( V_307 ) ,
} ;
static const struct V_12 V_14 = {
. V_308 = V_25 ,
. V_26 = V_309 ,
} ;
switch ( V_226 ) {
case V_17 :
break;
case V_22 :
memcpy ( V_13 , & sin , sizeof( sin ) ) ;
break;
case V_25 :
memcpy ( V_13 , & V_14 , sizeof( V_14 ) ) ;
break;
default:
F_2 ( L_85 , V_101 ) ;
return - V_310 ;
}
return 0 ;
}
static struct V_7 * F_197 ( struct V_311 * args ,
unsigned int V_312 ,
unsigned int V_313 )
{
struct V_7 * V_8 ;
struct V_79 * V_314 ;
if ( args -> V_38 > sizeof( V_8 -> V_9 ) ) {
F_2 ( L_86 ) ;
return F_147 ( - V_315 ) ;
}
V_8 = F_198 ( args -> V_316 , sizeof( * V_314 ) , V_312 ,
V_313 ) ;
if ( V_8 == NULL ) {
F_2 ( L_87
L_88 ) ;
return F_147 ( - V_317 ) ;
}
V_314 = F_28 ( V_8 , struct V_79 , V_8 ) ;
memcpy ( & V_8 -> V_9 , args -> V_318 , args -> V_38 ) ;
V_8 -> V_38 = args -> V_38 ;
if ( args -> V_219 )
memcpy ( & V_314 -> V_219 , args -> V_219 , args -> V_38 ) ;
else {
int V_61 ;
V_61 = F_195 ( args -> V_318 -> V_16 ,
(struct V_6 * ) & V_314 -> V_219 ) ;
if ( V_61 != 0 ) {
F_63 ( V_8 ) ;
return F_147 ( V_61 ) ;
}
}
return V_8 ;
}
static struct V_7 * F_199 ( struct V_311 * args )
{
struct V_10 * V_15 = (struct V_10 * ) args -> V_318 ;
struct V_79 * V_80 ;
struct V_7 * V_8 ;
struct V_7 * V_87 ;
V_8 = F_197 ( args , V_319 ,
V_320 ) ;
if ( F_165 ( V_8 ) )
return V_8 ;
V_80 = F_28 ( V_8 , struct V_79 , V_8 ) ;
V_8 -> V_321 = 0 ;
V_8 -> V_322 = sizeof( V_96 ) / sizeof( T_1 ) ;
V_8 -> V_323 = V_324 ;
V_8 -> V_325 = V_326 ;
V_8 -> V_126 = V_198 ;
V_8 -> V_327 = V_328 ;
V_8 -> V_68 = & V_329 ;
V_8 -> V_184 = & V_330 ;
F_200 ( & V_80 -> V_125 ,
F_144 ) ;
switch ( V_15 -> V_331 ) {
case V_17 :
if ( V_15 -> V_18 [ 0 ] != '/' ) {
F_2 ( L_89 ,
V_15 -> V_18 ) ;
V_87 = F_147 ( - V_277 ) ;
goto V_332;
}
F_133 ( V_8 ) ;
F_15 ( V_8 , L_90 , V_333 ) ;
V_87 = F_147 ( F_151 ( V_80 ) ) ;
if ( V_87 )
goto V_332;
break;
default:
V_87 = F_147 ( - V_310 ) ;
goto V_332;
}
F_2 ( L_91 ,
V_8 -> V_19 [ V_20 ] ) ;
if ( F_201 ( V_130 ) )
return V_8 ;
V_87 = F_147 ( - V_277 ) ;
V_332:
F_63 ( V_8 ) ;
return V_87 ;
}
static struct V_7 * F_202 ( struct V_311 * args )
{
struct V_6 * V_9 = args -> V_318 ;
struct V_7 * V_8 ;
struct V_79 * V_80 ;
struct V_7 * V_87 ;
V_8 = F_197 ( args , V_334 ,
V_334 ) ;
if ( F_165 ( V_8 ) )
return V_8 ;
V_80 = F_28 ( V_8 , struct V_79 , V_8 ) ;
V_8 -> V_321 = V_246 ;
V_8 -> V_322 = 0 ;
V_8 -> V_323 = ( 1U << 16 ) - ( V_335 << 3 ) ;
V_8 -> V_325 = V_326 ;
V_8 -> V_126 = V_336 ;
V_8 -> V_327 = V_328 ;
V_8 -> V_68 = & V_337 ;
V_8 -> V_184 = & V_338 ;
switch ( V_9 -> V_16 ) {
case V_22 :
if ( ( (struct V_11 * ) V_9 ) -> V_339 != F_203 ( 0 ) )
F_133 ( V_8 ) ;
F_200 ( & V_80 -> V_125 ,
F_164 ) ;
F_15 ( V_8 , L_92 , V_340 ) ;
break;
case V_25 :
if ( ( (struct V_12 * ) V_9 ) -> V_341 != F_203 ( 0 ) )
F_133 ( V_8 ) ;
F_200 ( & V_80 -> V_125 ,
F_164 ) ;
F_15 ( V_8 , L_92 , V_342 ) ;
break;
default:
V_87 = F_147 ( - V_310 ) ;
goto V_332;
}
if ( F_42 ( V_8 ) )
F_2 ( L_93 ,
V_8 -> V_19 [ V_20 ] ,
V_8 -> V_19 [ V_28 ] ,
V_8 -> V_19 [ V_32 ] ) ;
else
F_2 ( L_94 ,
V_8 -> V_19 [ V_20 ] ,
V_8 -> V_19 [ V_32 ] ) ;
if ( F_201 ( V_130 ) )
return V_8 ;
V_87 = F_147 ( - V_277 ) ;
V_332:
F_63 ( V_8 ) ;
return V_87 ;
}
static struct V_7 * F_204 ( struct V_311 * args )
{
struct V_6 * V_9 = args -> V_318 ;
struct V_7 * V_8 ;
struct V_79 * V_80 ;
struct V_7 * V_87 ;
unsigned int V_313 = V_320 ;
if ( args -> V_58 & V_343 )
V_313 = V_344 ;
V_8 = F_197 ( args , V_319 ,
V_313 ) ;
if ( F_165 ( V_8 ) )
return V_8 ;
V_80 = F_28 ( V_8 , struct V_79 , V_8 ) ;
V_8 -> V_321 = V_272 ;
V_8 -> V_322 = sizeof( V_96 ) / sizeof( T_1 ) ;
V_8 -> V_323 = V_324 ;
V_8 -> V_325 = V_326 ;
V_8 -> V_126 = V_198 ;
V_8 -> V_327 = V_328 ;
V_8 -> V_68 = & V_345 ;
V_8 -> V_184 = & V_346 ;
switch ( V_9 -> V_16 ) {
case V_22 :
if ( ( (struct V_11 * ) V_9 ) -> V_339 != F_203 ( 0 ) )
F_133 ( V_8 ) ;
F_200 ( & V_80 -> V_125 ,
F_173 ) ;
F_15 ( V_8 , L_95 , V_347 ) ;
break;
case V_25 :
if ( ( (struct V_12 * ) V_9 ) -> V_341 != F_203 ( 0 ) )
F_133 ( V_8 ) ;
F_200 ( & V_80 -> V_125 ,
F_173 ) ;
F_15 ( V_8 , L_95 , V_348 ) ;
break;
default:
V_87 = F_147 ( - V_310 ) ;
goto V_332;
}
if ( F_42 ( V_8 ) )
F_2 ( L_93 ,
V_8 -> V_19 [ V_20 ] ,
V_8 -> V_19 [ V_28 ] ,
V_8 -> V_19 [ V_32 ] ) ;
else
F_2 ( L_94 ,
V_8 -> V_19 [ V_20 ] ,
V_8 -> V_19 [ V_32 ] ) ;
if ( F_201 ( V_130 ) )
return V_8 ;
V_87 = F_147 ( - V_277 ) ;
V_332:
F_63 ( V_8 ) ;
return V_87 ;
}
static struct V_7 * F_205 ( struct V_311 * args )
{
struct V_6 * V_9 = args -> V_318 ;
struct V_7 * V_8 ;
struct V_79 * V_80 ;
struct V_349 * V_350 ;
struct V_7 * V_87 ;
if ( args -> V_301 -> V_351 ) {
return args -> V_301 -> V_351 ;
}
V_8 = F_197 ( args , V_319 ,
V_319 ) ;
if ( F_165 ( V_8 ) )
return V_8 ;
V_80 = F_28 ( V_8 , struct V_79 , V_8 ) ;
V_8 -> V_321 = V_272 ;
V_8 -> V_322 = sizeof( V_96 ) / sizeof( T_1 ) ;
V_8 -> V_323 = V_324 ;
V_8 -> V_184 = & V_346 ;
F_133 ( V_8 ) ;
V_8 -> V_325 = 0 ;
V_8 -> V_126 = 0 ;
V_8 -> V_327 = 0 ;
V_8 -> V_68 = & V_352 ;
switch ( V_9 -> V_16 ) {
case V_22 :
F_15 ( V_8 , L_95 ,
V_347 ) ;
break;
case V_25 :
F_15 ( V_8 , L_95 ,
V_348 ) ;
break;
default:
V_87 = F_147 ( - V_310 ) ;
goto V_332;
}
F_2 ( L_93 ,
V_8 -> V_19 [ V_20 ] ,
V_8 -> V_19 [ V_28 ] ,
V_8 -> V_19 [ V_32 ] ) ;
F_206 ( V_8 ) ;
args -> V_301 -> V_351 = V_8 ;
V_8 -> V_301 = args -> V_301 ;
V_350 = F_28 ( args -> V_301 , struct V_349 , V_353 ) ;
V_80 -> V_37 = V_350 -> V_354 ;
V_80 -> V_83 = V_350 -> V_355 ;
F_153 ( V_8 ) ;
if ( F_201 ( V_130 ) )
return V_8 ;
F_207 ( V_8 ) ;
V_87 = F_147 ( - V_277 ) ;
V_332:
F_63 ( V_8 ) ;
return V_87 ;
}
int F_208 ( void )
{
#ifdef F_209
if ( ! V_356 )
V_356 = F_210 ( V_357 ) ;
#endif
F_211 ( & V_358 ) ;
F_211 ( & V_359 ) ;
F_211 ( & V_360 ) ;
F_211 ( & V_361 ) ;
return 0 ;
}
void F_212 ( void )
{
#ifdef F_209
if ( V_356 ) {
F_213 ( V_356 ) ;
V_356 = NULL ;
}
#endif
F_214 ( & V_358 ) ;
F_214 ( & V_359 ) ;
F_214 ( & V_360 ) ;
F_214 ( & V_361 ) ;
}
static int F_215 ( const char * V_362 ,
const struct V_363 * V_364 ,
unsigned int V_365 , unsigned int V_366 )
{
unsigned long V_367 ;
int V_87 ;
if ( ! V_362 )
return - V_277 ;
V_87 = F_216 ( V_362 , 0 , & V_367 ) ;
if ( V_87 == - V_277 || V_367 < V_365 || V_367 > V_366 )
return - V_277 ;
* ( ( unsigned int * ) V_364 -> V_180 ) = V_367 ;
return 0 ;
}
static int F_217 ( const char * V_362 , const struct V_363 * V_364 )
{
return F_215 ( V_362 , V_364 ,
V_368 ,
V_369 ) ;
}
static int F_218 ( const char * V_362 ,
const struct V_363 * V_364 )
{
return F_215 ( V_362 , V_364 ,
V_370 ,
V_371 ) ;
}
static int F_219 ( const char * V_362 ,
const struct V_363 * V_364 )
{
return F_215 ( V_362 , V_364 ,
V_370 ,
V_344 ) ;
}

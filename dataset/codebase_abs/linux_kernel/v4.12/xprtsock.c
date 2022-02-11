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
return (struct V_6 * ) V_8 -> V_9 ;
}
static inline struct V_10 * F_4 ( struct V_6 * V_11 )
{
return (struct V_10 * ) & V_11 -> V_12 ;
}
static inline struct V_13 * F_5 ( struct V_6 * V_11 )
{
return (struct V_13 * ) & V_11 -> V_12 ;
}
static inline struct V_14 * F_6 ( struct V_6 * V_11 )
{
return (struct V_14 * ) & V_11 -> V_12 ;
}
static inline struct V_15 * F_7 ( struct V_6 * V_11 )
{
return (struct V_15 * ) & V_11 -> V_12 ;
}
static void F_8 ( struct V_6 * V_11 )
{
struct V_10 * V_16 = F_4 ( V_11 ) ;
struct V_15 * V_17 ;
struct V_14 * sin ;
struct V_13 * V_18 ;
char V_4 [ 128 ] ;
switch ( V_16 -> V_19 ) {
case V_20 :
V_18 = F_5 ( V_11 ) ;
F_9 ( V_4 , V_18 -> V_21 , sizeof( V_4 ) ) ;
V_11 -> V_22 [ V_23 ] =
F_10 ( V_4 , V_24 ) ;
break;
case V_25 :
( void ) F_11 ( V_16 , V_4 , sizeof( V_4 ) ) ;
V_11 -> V_22 [ V_23 ] =
F_10 ( V_4 , V_24 ) ;
sin = F_6 ( V_11 ) ;
snprintf ( V_4 , sizeof( V_4 ) , L_5 , F_12 ( sin -> V_26 . V_27 ) ) ;
break;
case V_28 :
( void ) F_11 ( V_16 , V_4 , sizeof( V_4 ) ) ;
V_11 -> V_22 [ V_23 ] =
F_10 ( V_4 , V_24 ) ;
V_17 = F_7 ( V_11 ) ;
snprintf ( V_4 , sizeof( V_4 ) , L_6 , & V_17 -> V_29 ) ;
break;
default:
F_13 () ;
}
V_11 -> V_22 [ V_30 ] = F_10 ( V_4 , V_24 ) ;
}
static void F_14 ( struct V_6 * V_11 )
{
struct V_10 * V_16 = F_4 ( V_11 ) ;
char V_4 [ 128 ] ;
snprintf ( V_4 , sizeof( V_4 ) , L_7 , F_15 ( V_16 ) ) ;
V_11 -> V_22 [ V_31 ] = F_10 ( V_4 , V_24 ) ;
snprintf ( V_4 , sizeof( V_4 ) , L_8 , F_15 ( V_16 ) ) ;
V_11 -> V_22 [ V_32 ] = F_10 ( V_4 , V_24 ) ;
}
static void F_16 ( struct V_6 * V_11 ,
const char * V_33 ,
const char * V_34 )
{
V_11 -> V_22 [ V_35 ] = V_33 ;
V_11 -> V_22 [ V_36 ] = V_34 ;
F_8 ( V_11 ) ;
F_14 ( V_11 ) ;
}
static void F_17 ( struct V_6 * V_11 )
{
F_18 ( V_11 -> V_22 [ V_32 ] ) ;
F_18 ( V_11 -> V_22 [ V_31 ] ) ;
F_14 ( V_11 ) ;
}
static void F_19 ( struct V_6 * V_11 )
{
unsigned int V_37 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ )
switch ( V_37 ) {
case V_35 :
case V_36 :
continue;
default:
F_18 ( V_11 -> V_22 [ V_37 ] ) ;
}
}
static int F_20 ( struct V_39 * V_7 , struct V_10 * V_12 , int V_40 , struct V_41 * V_42 , unsigned int V_43 , int V_44 )
{
struct V_45 V_1 = {
. V_46 = V_12 ,
. V_47 = V_40 ,
. V_48 = V_49 | ( V_44 ? V_50 : 0 ) ,
} ;
struct V_41 V_51 = {
. V_52 = V_42 -> V_52 + V_43 ,
. V_53 = V_42 -> V_53 - V_43 ,
} ;
if ( V_51 . V_53 != 0 )
return F_21 ( V_7 , & V_1 , & V_51 , 1 , V_51 . V_53 ) ;
return F_21 ( V_7 , & V_1 , NULL , 0 , 0 ) ;
}
static int F_22 ( struct V_39 * V_7 , struct V_54 * V_55 , unsigned int V_43 , int V_44 , bool V_56 , int * V_57 )
{
T_3 (* F_23)( struct V_39 * V_7 , struct V_58 * V_58 ,
int V_59 , T_4 V_60 , int V_61 );
struct V_58 * * V_62 ;
unsigned int V_63 ;
int V_64 ;
V_63 = V_55 -> V_65 - V_43 ;
V_43 += V_55 -> V_66 ;
V_62 = V_55 -> V_67 + ( V_43 >> V_68 ) ;
V_43 &= ~ V_69 ;
F_23 = V_7 -> V_70 -> V_71 ;
if ( ! V_56 )
F_23 = V_72 ;
for(; ; ) {
unsigned int V_73 = F_24 (unsigned int, PAGE_SIZE - base, remainder) ;
int V_61 = V_49 ;
V_63 -= V_73 ;
if ( V_44 )
V_61 |= V_50 ;
if ( V_63 != 0 )
V_61 |= V_74 | V_50 ;
V_64 = F_23 ( V_7 , * V_62 , V_43 , V_73 , V_61 ) ;
if ( V_63 == 0 || V_64 != V_73 )
break;
* V_57 += V_64 ;
V_62 ++ ;
V_43 = 0 ;
}
if ( V_64 > 0 ) {
* V_57 += V_64 ;
V_64 = 0 ;
}
return V_64 ;
}
static int F_25 ( struct V_39 * V_7 , struct V_10 * V_12 , int V_40 , struct V_54 * V_55 , unsigned int V_43 , bool V_56 , int * V_57 )
{
unsigned int V_63 = V_55 -> V_73 - V_43 ;
int V_64 = 0 ;
int V_75 = 0 ;
if ( F_26 ( ! V_7 ) )
return - V_76 ;
if ( V_43 != 0 ) {
V_12 = NULL ;
V_40 = 0 ;
}
if ( V_43 < V_55 -> V_77 [ 0 ] . V_53 || V_12 != NULL ) {
unsigned int V_73 = V_55 -> V_77 [ 0 ] . V_53 - V_43 ;
V_63 -= V_73 ;
V_64 = F_20 ( V_7 , V_12 , V_40 , & V_55 -> V_77 [ 0 ] , V_43 , V_63 != 0 ) ;
if ( V_63 == 0 || V_64 != V_73 )
goto V_78;
* V_57 += V_64 ;
V_43 = 0 ;
} else
V_43 -= V_55 -> V_77 [ 0 ] . V_53 ;
if ( V_43 < V_55 -> V_65 ) {
unsigned int V_73 = V_55 -> V_65 - V_43 ;
V_63 -= V_73 ;
V_64 = F_22 ( V_7 , V_55 , V_43 , V_63 != 0 , V_56 , & V_75 ) ;
* V_57 += V_75 ;
if ( V_63 == 0 || V_75 != V_73 )
goto V_78;
V_43 = 0 ;
} else
V_43 -= V_55 -> V_65 ;
if ( V_43 >= V_55 -> V_79 [ 0 ] . V_53 )
return 0 ;
V_64 = F_20 ( V_7 , NULL , 0 , & V_55 -> V_79 [ 0 ] , V_43 , 0 ) ;
V_78:
if ( V_64 > 0 ) {
* V_57 += V_64 ;
V_64 = 0 ;
}
return V_64 ;
}
static void F_27 ( struct V_80 * V_81 )
{
struct V_82 * V_83 = F_28 ( V_81 -> V_84 -> V_85 , struct V_82 , V_11 ) ;
V_83 -> V_86 -> V_87 -- ;
}
static int F_29 ( struct V_80 * V_81 )
{
struct V_88 * V_89 = V_81 -> V_84 ;
struct V_6 * V_11 = V_89 -> V_85 ;
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_7 * V_8 = V_83 -> V_86 ;
int V_90 = - V_91 ;
F_2 ( L_9 ,
V_81 -> V_92 , V_89 -> V_93 - V_89 -> V_94 ,
V_89 -> V_93 ) ;
F_30 ( & V_11 -> V_95 ) ;
if ( F_31 ( V_11 ) ) {
V_8 -> V_87 ++ ;
F_32 ( V_81 , F_27 ) ;
} else
V_90 = - V_96 ;
F_33 ( & V_11 -> V_95 ) ;
if ( V_90 == - V_91 ) {
struct V_97 * V_98 ;
F_34 () ;
V_98 = F_35 ( V_8 -> V_99 ) ;
F_36 ( V_100 , & V_98 -> V_61 ) ;
F_37 () ;
V_8 -> V_101 ( V_8 ) ;
}
return V_90 ;
}
static inline void F_38 ( struct V_54 * V_4 )
{
T_1 V_102 = V_4 -> V_73 - sizeof( V_103 ) ;
V_103 * V_43 = V_4 -> V_77 [ 0 ] . V_52 ;
* V_43 = F_39 ( V_104 | V_102 ) ;
}
static int F_40 ( struct V_80 * V_81 )
{
struct V_88 * V_89 = V_81 -> V_84 ;
struct V_6 * V_11 = V_89 -> V_85 ;
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_54 * V_55 = & V_89 -> V_105 ;
int V_106 ;
int V_75 = 0 ;
F_38 ( & V_89 -> V_105 ) ;
F_1 ( L_10 ,
V_89 -> V_107 -> V_52 , V_89 -> V_107 -> V_53 ) ;
V_106 = F_25 ( V_83 -> V_7 , NULL , 0 , V_55 , V_89 -> V_94 ,
true , & V_75 ) ;
F_2 ( L_11 ,
V_108 , V_55 -> V_73 - V_89 -> V_94 , V_106 ) ;
if ( V_106 == - V_91 && F_41 ( V_83 -> V_86 ) )
V_106 = - V_109 ;
if ( F_42 ( V_75 > 0 ) || V_106 == 0 ) {
V_89 -> V_94 += V_75 ;
V_89 -> V_110 += V_75 ;
if ( F_42 ( V_89 -> V_94 >= V_89 -> V_93 ) ) {
V_89 -> V_94 = 0 ;
return 0 ;
}
V_106 = - V_91 ;
}
switch ( V_106 ) {
case - V_109 :
break;
case - V_91 :
V_106 = F_29 ( V_81 ) ;
break;
default:
F_2 ( L_12 ,
- V_106 ) ;
case - V_111 :
F_43 ( V_11 ) ;
V_106 = - V_96 ;
}
return V_106 ;
}
static int F_44 ( struct V_80 * V_81 )
{
struct V_88 * V_89 = V_81 -> V_84 ;
struct V_6 * V_11 = V_89 -> V_85 ;
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_54 * V_55 = & V_89 -> V_105 ;
int V_75 = 0 ;
int V_106 ;
F_1 ( L_10 ,
V_89 -> V_107 -> V_52 ,
V_89 -> V_107 -> V_53 ) ;
if ( ! F_45 ( V_11 ) )
return - V_96 ;
V_106 = F_25 ( V_83 -> V_7 , F_4 ( V_11 ) , V_11 -> V_40 ,
V_55 , V_89 -> V_94 , true , & V_75 ) ;
F_2 ( L_13 ,
V_55 -> V_73 - V_89 -> V_94 , V_106 ) ;
if ( V_106 == - V_112 )
goto V_113;
if ( V_106 == - V_91 && F_41 ( V_83 -> V_86 ) )
V_106 = - V_109 ;
if ( V_75 > 0 || V_106 == 0 ) {
V_89 -> V_110 += V_75 ;
if ( V_75 >= V_89 -> V_93 )
return 0 ;
V_106 = - V_91 ;
}
V_113:
switch ( V_106 ) {
case - V_76 :
V_106 = - V_96 ;
break;
case - V_91 :
V_106 = F_29 ( V_81 ) ;
break;
case - V_114 :
case - V_109 :
case - V_111 :
case - V_115 :
case - V_112 :
break;
default:
F_2 ( L_12 ,
- V_106 ) ;
}
return V_106 ;
}
static int F_46 ( struct V_80 * V_81 )
{
struct V_88 * V_89 = V_81 -> V_84 ;
struct V_6 * V_11 = V_89 -> V_85 ;
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_54 * V_55 = & V_89 -> V_105 ;
bool V_56 = true ;
bool V_116 = false ;
int V_106 ;
int V_75 ;
F_38 ( & V_89 -> V_105 ) ;
F_1 ( L_10 ,
V_89 -> V_107 -> V_52 ,
V_89 -> V_107 -> V_53 ) ;
if ( V_81 -> V_117 & V_118 )
V_56 = false ;
if ( F_47 ( V_119 , & V_83 -> V_120 ) )
F_48 ( V_11 , V_83 -> V_7 ) ;
while ( 1 ) {
V_75 = 0 ;
V_106 = F_25 ( V_83 -> V_7 , NULL , 0 , V_55 ,
V_89 -> V_94 , V_56 , & V_75 ) ;
F_2 ( L_14 ,
V_55 -> V_73 - V_89 -> V_94 , V_106 ) ;
V_89 -> V_94 += V_75 ;
V_89 -> V_110 += V_75 ;
if ( F_42 ( V_89 -> V_94 >= V_89 -> V_93 ) ) {
V_89 -> V_94 = 0 ;
return 0 ;
}
F_49 ( V_75 == 0 && V_106 == 0 ) ;
if ( V_106 == - V_91 ) {
if ( F_47 ( V_121 , & V_83 -> V_7 -> V_61 ) )
break;
if ( V_75 == 0 ) {
V_106 = - V_109 ;
if ( V_116 )
break;
V_116 = true ;
}
continue;
}
if ( V_106 < 0 )
break;
V_116 = false ;
}
switch ( V_106 ) {
case - V_76 :
V_106 = - V_96 ;
break;
case - V_91 :
V_106 = F_29 ( V_81 ) ;
break;
case - V_122 :
case - V_115 :
case - V_96 :
case - V_123 :
case - V_109 :
case - V_111 :
break;
default:
F_2 ( L_12 ,
- V_106 ) ;
}
return V_106 ;
}
static void F_50 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
struct V_88 * V_89 ;
if ( V_81 != V_11 -> V_124 )
return;
if ( V_81 == NULL )
goto V_125;
V_89 = V_81 -> V_84 ;
if ( V_89 == NULL )
goto V_125;
if ( V_89 -> V_94 == 0 )
goto V_125;
if ( V_89 -> V_94 == V_89 -> V_105 . V_73 )
goto V_125;
F_36 ( V_126 , & V_11 -> V_127 ) ;
V_125:
F_51 ( V_11 , V_81 ) ;
}
static void F_52 ( struct V_82 * V_83 , struct V_7 * V_8 )
{
V_83 -> V_128 = V_8 -> V_129 ;
V_83 -> V_130 = V_8 -> V_131 ;
V_83 -> V_132 = V_8 -> V_101 ;
V_83 -> V_133 = V_8 -> V_134 ;
}
static void F_53 ( struct V_82 * V_83 , struct V_7 * V_8 )
{
V_8 -> V_129 = V_83 -> V_128 ;
V_8 -> V_131 = V_83 -> V_130 ;
V_8 -> V_101 = V_83 -> V_132 ;
V_8 -> V_134 = V_83 -> V_133 ;
}
static void F_54 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
F_55 ( V_135 , & V_83 -> V_120 ) ;
}
static void F_56 ( struct V_6 * V_11 )
{
F_57 () ;
F_55 ( V_126 , & V_11 -> V_127 ) ;
F_55 ( V_136 , & V_11 -> V_127 ) ;
F_54 ( V_11 ) ;
F_58 () ;
}
static void F_59 ( struct V_6 * V_11 )
{
F_56 ( V_11 ) ;
F_60 ( V_11 ) ;
}
static void F_61 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
int V_64 ;
F_62 ( & V_8 -> V_137 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_78;
V_64 = - V_8 -> V_138 ;
if ( V_64 == 0 )
goto V_78;
if ( V_8 -> V_139 == V_140 )
F_59 ( V_11 ) ;
F_2 ( L_15 ,
V_11 , - V_64 ) ;
F_63 ( V_11 , V_8 -> V_141 , V_64 ) ;
F_64 ( V_11 , V_64 ) ;
V_78:
F_65 ( & V_8 -> V_137 ) ;
}
static void F_66 ( struct V_82 * V_83 )
{
struct V_39 * V_7 = V_83 -> V_7 ;
struct V_7 * V_8 = V_83 -> V_86 ;
struct V_6 * V_11 = & V_83 -> V_11 ;
if ( V_8 == NULL )
return;
if ( F_67 ( & V_83 -> V_11 . V_142 ) )
F_68 ( V_8 ) ;
F_69 ( V_7 , V_143 ) ;
F_70 ( & V_83 -> V_144 ) ;
F_71 ( & V_8 -> V_137 ) ;
V_83 -> V_86 = NULL ;
V_83 -> V_7 = NULL ;
V_8 -> V_9 = NULL ;
F_53 ( V_83 , V_8 ) ;
F_72 ( V_11 ) ;
F_73 ( & V_8 -> V_137 ) ;
F_56 ( V_11 ) ;
F_74 ( & V_83 -> V_144 ) ;
F_75 ( V_11 , V_7 ) ;
F_76 ( V_7 ) ;
}
static void F_43 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
F_2 ( L_16 , V_11 ) ;
F_66 ( V_83 ) ;
V_11 -> V_145 = 0 ;
F_60 ( V_11 ) ;
}
static void F_77 ( struct V_6 * V_11 )
{
F_2 ( L_17 ,
V_11 ) ;
F_60 ( V_11 ) ;
}
static void F_78 ( struct V_6 * V_11 )
{
F_19 ( V_11 ) ;
F_79 ( V_11 ) ;
}
static void F_80 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_28 ( V_11 ,
struct V_82 , V_11 ) ;
F_2 ( L_18 , V_11 ) ;
F_81 ( & V_83 -> V_146 ) ;
F_43 ( V_11 ) ;
F_82 ( & V_83 -> V_147 ) ;
F_78 ( V_11 ) ;
F_83 ( V_148 ) ;
}
static int F_84 ( struct V_54 * V_55 , struct V_149 * V_150 )
{
struct V_151 V_152 = {
. V_150 = V_150 ,
. V_59 = sizeof( V_103 ) ,
. V_3 = V_150 -> V_73 - sizeof( V_103 ) ,
} ;
if ( F_85 ( V_55 , 0 , & V_152 , V_153 ) < 0 )
return - 1 ;
if ( V_152 . V_3 )
return - 1 ;
return 0 ;
}
static void F_86 ( struct V_6 * V_11 ,
struct V_7 * V_8 ,
struct V_149 * V_150 )
{
struct V_80 * V_81 ;
struct V_88 * V_154 ;
int V_155 , V_156 ;
T_1 V_157 ;
T_5 * V_158 ;
V_155 = V_150 -> V_73 - sizeof( V_103 ) ;
if ( V_155 < 4 ) {
F_2 ( L_19 , V_155 ) ;
return;
}
V_158 = F_87 ( V_150 , sizeof( V_103 ) , sizeof( V_157 ) , & V_157 ) ;
if ( V_158 == NULL )
return;
F_30 ( & V_11 -> V_95 ) ;
V_154 = F_88 ( V_11 , * V_158 ) ;
if ( ! V_154 )
goto V_159;
V_81 = V_154 -> V_160 ;
V_156 = V_154 -> V_161 . V_162 ;
if ( V_156 > V_155 )
V_156 = V_155 ;
if ( F_84 ( & V_154 -> V_161 , V_150 ) ) {
F_2 ( L_20 ) ;
goto V_159;
}
F_89 ( V_81 , V_156 ) ;
V_159:
F_33 ( & V_11 -> V_95 ) ;
}
static void F_90 ( struct V_82 * V_83 )
{
struct V_149 * V_150 ;
struct V_7 * V_8 ;
int V_64 ;
F_70 ( & V_83 -> V_144 ) ;
V_8 = V_83 -> V_86 ;
if ( V_8 == NULL )
goto V_78;
for (; ; ) {
V_150 = F_91 ( V_8 , 0 , 1 , & V_64 ) ;
if ( V_150 != NULL ) {
F_86 ( & V_83 -> V_11 , V_8 , V_150 ) ;
F_92 ( V_8 , V_150 ) ;
continue;
}
if ( ! F_93 ( V_135 , & V_83 -> V_120 ) )
break;
}
V_78:
F_74 ( & V_83 -> V_144 ) ;
}
static void F_94 ( struct V_163 * V_164 )
{
struct V_82 * V_83 =
F_28 ( V_164 , struct V_82 , V_147 ) ;
F_90 ( V_83 ) ;
}
static void F_95 ( struct V_6 * V_11 ,
struct V_7 * V_8 ,
struct V_149 * V_150 )
{
struct V_80 * V_81 ;
struct V_88 * V_154 ;
int V_155 , V_156 ;
T_1 V_157 ;
T_5 * V_158 ;
V_155 = V_150 -> V_73 ;
if ( V_155 < 4 ) {
F_2 ( L_21 , V_155 ) ;
return;
}
V_158 = F_87 ( V_150 , 0 , sizeof( V_157 ) , & V_157 ) ;
if ( V_158 == NULL )
return;
F_30 ( & V_11 -> V_95 ) ;
V_154 = F_88 ( V_11 , * V_158 ) ;
if ( ! V_154 )
goto V_159;
V_81 = V_154 -> V_160 ;
if ( ( V_156 = V_154 -> V_161 . V_162 ) > V_155 )
V_156 = V_155 ;
if ( F_96 ( & V_154 -> V_161 , V_150 ) ) {
F_97 ( V_8 , V_165 ) ;
goto V_159;
}
F_97 ( V_8 , V_166 ) ;
F_98 ( V_11 , V_81 , V_156 ) ;
F_89 ( V_81 , V_156 ) ;
V_159:
F_33 ( & V_11 -> V_95 ) ;
}
static void F_99 ( struct V_82 * V_83 )
{
struct V_149 * V_150 ;
struct V_7 * V_8 ;
int V_64 ;
F_70 ( & V_83 -> V_144 ) ;
V_8 = V_83 -> V_86 ;
if ( V_8 == NULL )
goto V_78;
for (; ; ) {
V_150 = F_100 ( V_8 , 0 , 1 , & V_64 ) ;
if ( V_150 != NULL ) {
F_95 ( & V_83 -> V_11 , V_8 , V_150 ) ;
F_101 ( V_150 ) ;
continue;
}
if ( ! F_93 ( V_135 , & V_83 -> V_120 ) )
break;
}
V_78:
F_74 ( & V_83 -> V_144 ) ;
}
static void F_102 ( struct V_163 * V_164 )
{
struct V_82 * V_83 =
F_28 ( V_164 , struct V_82 , V_147 ) ;
F_99 ( V_83 ) ;
}
static void F_103 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
F_62 ( & V_8 -> V_137 ) ;
F_2 ( L_22 ) ;
V_11 = F_3 ( V_8 ) ;
if ( V_11 != NULL ) {
struct V_82 * V_83 = F_28 ( V_11 ,
struct V_82 , V_11 ) ;
V_83 -> V_128 ( V_8 ) ;
if ( V_11 -> V_145 )
V_11 -> V_145 = 0 ;
if ( ! F_104 ( V_135 , & V_83 -> V_120 ) )
F_105 ( V_167 , & V_83 -> V_147 ) ;
}
F_65 ( & V_8 -> V_137 ) ;
}
static void F_106 ( struct V_6 * V_11 )
{
F_107 ( V_11 ) ;
}
static inline void F_108 ( struct V_6 * V_11 , struct V_151 * V_152 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
T_4 V_73 , V_168 ;
char * V_169 ;
V_169 = ( ( char * ) & V_83 -> V_170 ) + V_83 -> V_171 ;
V_73 = sizeof( V_83 -> V_170 ) - V_83 -> V_171 ;
V_168 = V_153 ( V_152 , V_169 , V_73 ) ;
V_83 -> V_171 += V_168 ;
if ( V_168 != V_73 )
return;
V_83 -> V_172 = F_12 ( V_83 -> V_170 ) ;
if ( V_83 -> V_172 & V_104 )
V_83 -> V_173 |= V_174 ;
else
V_83 -> V_173 &= ~ V_174 ;
V_83 -> V_172 &= V_175 ;
V_83 -> V_173 &= ~ V_176 ;
V_83 -> V_171 = 0 ;
if ( F_26 ( V_83 -> V_172 < 8 ) ) {
F_2 ( L_23 ) ;
F_106 ( V_11 ) ;
return;
}
F_2 ( L_24 ,
V_83 -> V_172 ) ;
}
static void F_109 ( struct V_82 * V_83 )
{
if ( V_83 -> V_171 == V_83 -> V_172 ) {
V_83 -> V_173 |= V_176 ;
V_83 -> V_171 = 0 ;
if ( V_83 -> V_173 & V_174 ) {
V_83 -> V_173 &= ~ V_177 ;
V_83 -> V_173 |= V_178 ;
V_83 -> V_179 = 0 ;
}
}
}
static inline void F_110 ( struct V_82 * V_83 , struct V_151 * V_152 )
{
T_4 V_73 , V_168 ;
char * V_169 ;
V_73 = sizeof( V_83 -> V_180 ) - V_83 -> V_171 ;
F_2 ( L_25 , V_73 ) ;
V_169 = ( ( char * ) & V_83 -> V_180 ) + V_83 -> V_171 ;
V_168 = V_153 ( V_152 , V_169 , V_73 ) ;
V_83 -> V_171 += V_168 ;
if ( V_168 != V_73 )
return;
V_83 -> V_173 &= ~ V_178 ;
V_83 -> V_173 |= V_181 ;
V_83 -> V_179 = 4 ;
F_2 ( L_26 ,
( V_83 -> V_173 & V_182 ) ? L_27
: L_28 ,
F_12 ( V_83 -> V_180 ) ) ;
F_109 ( V_83 ) ;
}
static inline void F_111 ( struct V_82 * V_83 ,
struct V_151 * V_152 )
{
T_4 V_73 , V_168 ;
T_1 V_59 ;
char * V_169 ;
V_59 = V_83 -> V_171 - sizeof( V_83 -> V_180 ) ;
V_73 = sizeof( V_83 -> V_183 ) - V_59 ;
F_2 ( L_29 , V_73 ) ;
V_169 = ( ( char * ) & V_83 -> V_183 ) + V_59 ;
V_168 = V_153 ( V_152 , V_169 , V_73 ) ;
V_83 -> V_171 += V_168 ;
if ( V_168 != V_73 )
return;
V_83 -> V_173 &= ~ V_181 ;
switch ( F_12 ( V_83 -> V_183 ) ) {
case V_184 :
V_83 -> V_173 |= V_185 ;
V_83 -> V_173 |= V_177 ;
V_83 -> V_173 |= V_182 ;
break;
case V_186 :
V_83 -> V_173 |= V_185 ;
V_83 -> V_173 |= V_177 ;
V_83 -> V_173 &= ~ V_182 ;
break;
default:
F_2 ( L_30 ) ;
F_106 ( & V_83 -> V_11 ) ;
}
F_109 ( V_83 ) ;
}
static inline void F_112 ( struct V_6 * V_11 ,
struct V_151 * V_152 ,
struct V_88 * V_89 )
{
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_54 * V_187 ;
T_4 V_73 ;
T_3 V_188 ;
V_187 = & V_89 -> V_161 ;
if ( V_83 -> V_173 & V_185 ) {
memcpy ( V_187 -> V_77 [ 0 ] . V_52 + V_83 -> V_179 ,
& V_83 -> V_183 ,
sizeof( V_83 -> V_183 ) ) ;
V_83 -> V_179 += sizeof( V_83 -> V_183 ) ;
V_83 -> V_173 &= ~ V_185 ;
}
V_73 = V_152 -> V_3 ;
if ( V_73 > V_83 -> V_172 - V_83 -> V_171 ) {
struct V_151 V_189 ;
V_73 = V_83 -> V_172 - V_83 -> V_171 ;
memcpy ( & V_189 , V_152 , sizeof( V_189 ) ) ;
V_189 . V_3 = V_73 ;
V_188 = F_85 ( V_187 , V_83 -> V_179 ,
& V_189 , V_153 ) ;
V_152 -> V_3 -= V_188 ;
V_152 -> V_59 += V_188 ;
} else
V_188 = F_85 ( V_187 , V_83 -> V_179 ,
V_152 , V_153 ) ;
if ( V_188 > 0 ) {
V_83 -> V_179 += V_188 ;
V_83 -> V_171 += V_188 ;
}
if ( V_188 != V_73 ) {
V_83 -> V_173 &= ~ V_177 ;
F_2 ( L_31 ,
F_12 ( V_83 -> V_180 ) ) ;
F_2 ( L_32
L_33 ,
V_11 , V_83 -> V_179 ,
V_83 -> V_171 , V_83 -> V_172 ) ;
return;
}
F_2 ( L_34 ,
F_12 ( V_83 -> V_180 ) , V_188 ) ;
F_2 ( L_35
L_36 , V_11 , V_83 -> V_179 ,
V_83 -> V_171 , V_83 -> V_172 ) ;
if ( V_83 -> V_179 == V_89 -> V_161 . V_162 )
V_83 -> V_173 &= ~ V_177 ;
else if ( V_83 -> V_171 == V_83 -> V_172 ) {
if ( V_83 -> V_173 & V_174 )
V_83 -> V_173 &= ~ V_177 ;
}
}
static inline int F_113 ( struct V_6 * V_11 ,
struct V_151 * V_152 )
{
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_88 * V_89 ;
F_2 ( L_37 , F_12 ( V_83 -> V_180 ) ) ;
F_30 ( & V_11 -> V_95 ) ;
V_89 = F_88 ( V_11 , V_83 -> V_180 ) ;
if ( ! V_89 ) {
F_2 ( L_38 ,
F_12 ( V_83 -> V_180 ) ) ;
F_33 ( & V_11 -> V_95 ) ;
return - 1 ;
}
F_112 ( V_11 , V_152 , V_89 ) ;
if ( ! ( V_83 -> V_173 & V_177 ) )
F_89 ( V_89 -> V_160 , V_83 -> V_179 ) ;
F_33 ( & V_11 -> V_95 ) ;
return 0 ;
}
static int F_114 ( struct V_6 * V_11 ,
struct V_151 * V_152 )
{
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_88 * V_89 ;
F_30 ( & V_11 -> V_95 ) ;
V_89 = F_115 ( V_11 , V_83 -> V_180 ) ;
if ( V_89 == NULL ) {
F_33 ( & V_11 -> V_95 ) ;
F_116 ( V_190 L_39 ) ;
F_107 ( V_11 ) ;
return - 1 ;
}
F_2 ( L_40 , F_12 ( V_89 -> V_191 ) ) ;
F_112 ( V_11 , V_152 , V_89 ) ;
if ( ! ( V_83 -> V_173 & V_177 ) )
F_117 ( V_89 , V_83 -> V_179 ) ;
F_33 ( & V_11 -> V_95 ) ;
return 0 ;
}
static inline int F_118 ( struct V_6 * V_11 ,
struct V_151 * V_152 )
{
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
return ( V_83 -> V_173 & V_182 ) ?
F_113 ( V_11 , V_152 ) :
F_114 ( V_11 , V_152 ) ;
}
static int F_119 ( struct V_192 * V_193 , struct V_194 * V_194 )
{
int V_90 ;
V_90 = F_120 ( V_193 , L_41 , V_194 , V_195 , 0 ,
V_196 ) ;
if ( V_90 < 0 )
return V_90 ;
return 0 ;
}
static T_4 F_121 ( struct V_6 * V_11 )
{
return V_197 ;
}
static inline int F_118 ( struct V_6 * V_11 ,
struct V_151 * V_152 )
{
return F_113 ( V_11 , V_152 ) ;
}
static void F_122 ( struct V_6 * V_11 ,
struct V_151 * V_152 )
{
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
if ( F_118 ( V_11 , V_152 ) == 0 )
F_109 ( V_83 ) ;
else {
V_83 -> V_173 &= ~ V_177 ;
}
}
static inline void F_123 ( struct V_82 * V_83 , struct V_151 * V_152 )
{
T_4 V_73 ;
V_73 = V_83 -> V_172 - V_83 -> V_171 ;
if ( V_73 > V_152 -> V_3 )
V_73 = V_152 -> V_3 ;
V_152 -> V_3 -= V_73 ;
V_152 -> V_59 += V_73 ;
V_83 -> V_171 += V_73 ;
F_2 ( L_42 , V_73 ) ;
F_109 ( V_83 ) ;
}
static int F_124 ( T_6 * V_198 , struct V_149 * V_150 , unsigned int V_59 , T_4 V_73 )
{
struct V_6 * V_11 = V_198 -> V_199 . V_200 ;
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_151 V_152 = {
. V_150 = V_150 ,
. V_59 = V_59 ,
. V_3 = V_73 ,
} ;
F_2 ( L_43 ) ;
do {
F_125 ( V_83 ) ;
if ( V_83 -> V_173 & V_176 ) {
F_108 ( V_11 , & V_152 ) ;
continue;
}
if ( V_83 -> V_173 & V_178 ) {
F_110 ( V_83 , & V_152 ) ;
continue;
}
if ( V_83 -> V_173 & V_181 ) {
F_111 ( V_83 , & V_152 ) ;
continue;
}
if ( V_83 -> V_173 & V_177 ) {
F_122 ( V_11 , & V_152 ) ;
continue;
}
F_123 ( V_83 , & V_152 ) ;
} while ( V_152 . V_3 );
F_125 ( V_83 ) ;
F_2 ( L_44 ) ;
return V_73 - V_152 . V_3 ;
}
static void F_126 ( struct V_82 * V_83 )
{
struct V_6 * V_11 = & V_83 -> V_11 ;
struct V_7 * V_8 ;
T_6 V_198 = {
. V_3 = 2 * 1024 * 1024 ,
. V_199 . V_200 = V_11 ,
} ;
unsigned long V_201 = 0 ;
int V_202 = 0 ;
F_70 ( & V_83 -> V_144 ) ;
V_8 = V_83 -> V_86 ;
if ( V_8 == NULL )
goto V_78;
for (; ; ) {
F_127 ( V_8 ) ;
V_202 = F_128 ( V_8 , & V_198 , F_124 ) ;
if ( V_202 <= 0 ) {
F_55 ( V_135 , & V_83 -> V_120 ) ;
F_129 ( V_8 ) ;
if ( ! F_47 ( V_135 , & V_83 -> V_120 ) )
break;
} else {
F_129 ( V_8 ) ;
V_201 += V_202 ;
}
V_198 . V_3 = 65536 ;
}
V_78:
F_74 ( & V_83 -> V_144 ) ;
F_130 ( V_11 , V_202 , V_201 ) ;
}
static void F_131 ( struct V_163 * V_164 )
{
struct V_82 * V_83 =
F_28 ( V_164 , struct V_82 , V_147 ) ;
F_126 ( V_83 ) ;
}
static void F_132 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
struct V_82 * V_83 ;
F_62 ( & V_8 -> V_137 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_78;
F_2 ( L_45 , V_11 ) ;
F_2 ( L_46 ,
V_8 -> V_139 , F_31 ( V_11 ) ,
F_133 ( V_8 , V_203 ) ,
F_133 ( V_8 , V_204 ) ,
V_8 -> V_205 ) ;
V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
F_134 ( V_11 , V_8 -> V_141 ) ;
switch ( V_8 -> V_139 ) {
case V_206 :
F_135 ( & V_11 -> V_95 ) ;
if ( ! F_136 ( V_11 ) ) {
V_83 -> V_171 = 0 ;
V_83 -> V_172 = 0 ;
V_83 -> V_179 = 0 ;
V_83 -> V_173 =
V_176 | V_178 ;
V_11 -> V_207 ++ ;
F_55 ( V_208 , & V_83 -> V_120 ) ;
F_137 ( V_11 ) ;
F_64 ( V_11 , - V_91 ) ;
}
F_138 ( & V_11 -> V_95 ) ;
break;
case V_209 :
V_11 -> V_207 ++ ;
V_11 -> V_145 = 0 ;
F_36 ( V_136 , & V_11 -> V_127 ) ;
F_57 () ;
F_55 ( V_210 , & V_11 -> V_127 ) ;
F_55 ( V_126 , & V_11 -> V_127 ) ;
F_58 () ;
break;
case V_211 :
V_11 -> V_207 ++ ;
F_55 ( V_210 , & V_11 -> V_127 ) ;
F_106 ( V_11 ) ;
case V_212 :
if ( V_11 -> V_145 < V_213 )
V_11 -> V_145 = V_213 ;
break;
case V_214 :
F_36 ( V_136 , & V_11 -> V_127 ) ;
F_57 () ;
F_55 ( V_210 , & V_11 -> V_127 ) ;
F_58 () ;
break;
case V_140 :
if ( F_93 ( V_208 ,
& V_83 -> V_120 ) )
F_137 ( V_11 ) ;
F_59 ( V_11 ) ;
}
V_78:
F_65 ( & V_8 -> V_137 ) ;
}
static void F_139 ( struct V_7 * V_8 )
{
struct V_97 * V_98 ;
struct V_6 * V_11 ;
if ( ! V_8 -> V_141 )
return;
F_55 ( V_121 , & V_8 -> V_141 -> V_61 ) ;
if ( F_26 ( ! ( V_11 = F_3 ( V_8 ) ) ) )
return;
F_34 () ;
V_98 = F_35 ( V_8 -> V_99 ) ;
if ( ! V_98 || F_93 ( V_100 , & V_98 -> V_61 ) == 0 )
goto V_78;
F_140 ( V_11 ) ;
V_78:
F_37 () ;
}
static void F_141 ( struct V_7 * V_8 )
{
F_62 ( & V_8 -> V_137 ) ;
if ( F_41 ( V_8 ) )
F_139 ( V_8 ) ;
F_65 ( & V_8 -> V_137 ) ;
}
static void F_142 ( struct V_7 * V_8 )
{
F_62 ( & V_8 -> V_137 ) ;
if ( F_143 ( V_8 ) )
F_139 ( V_8 ) ;
F_65 ( & V_8 -> V_137 ) ;
}
static void F_144 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_7 * V_8 = V_83 -> V_86 ;
if ( V_83 -> V_215 ) {
V_8 -> V_216 |= V_217 ;
V_8 -> V_218 = V_83 -> V_215 * V_11 -> V_219 * 2 ;
}
if ( V_83 -> V_220 ) {
V_8 -> V_216 |= V_221 ;
V_8 -> V_222 = V_83 -> V_220 * V_11 -> V_219 * 2 ;
V_8 -> V_101 ( V_8 ) ;
}
}
static void F_145 ( struct V_6 * V_11 , T_4 V_220 , T_4 V_215 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
V_83 -> V_220 = 0 ;
if ( V_220 )
V_83 -> V_220 = V_220 + 1024 ;
V_83 -> V_215 = 0 ;
if ( V_215 )
V_83 -> V_215 = V_215 + 1024 ;
F_144 ( V_11 ) ;
}
static void F_146 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
F_30 ( & V_11 -> V_95 ) ;
F_98 ( V_11 , V_81 , - V_223 ) ;
F_33 ( & V_11 -> V_95 ) ;
}
static unsigned short F_147 ( void )
{
unsigned short V_224 = V_225 - V_226 + 1 ;
unsigned short rand = ( unsigned short ) F_148 () % V_224 ;
return rand + V_226 ;
}
static void F_149 ( struct V_39 * V_7 )
{
int V_227 = 1 ;
F_150 ( V_7 , V_228 , V_229 ,
( char * ) & V_227 , sizeof( V_227 ) ) ;
}
static unsigned short F_151 ( struct V_39 * V_7 )
{
struct V_230 V_4 ;
int V_162 ;
unsigned short V_231 = 0 ;
if ( F_152 ( V_7 , (struct V_10 * ) & V_4 , & V_162 ) < 0 )
goto V_78;
switch ( V_4 . V_232 ) {
case V_28 :
V_231 = F_153 ( ( (struct V_15 * ) & V_4 ) -> V_233 ) ;
break;
case V_25 :
V_231 = F_153 ( ( (struct V_14 * ) & V_4 ) -> V_234 ) ;
}
V_78:
return V_231 ;
}
static void F_154 ( struct V_6 * V_11 , unsigned short V_231 )
{
F_2 ( L_47 , V_11 , V_231 ) ;
F_155 ( F_4 ( V_11 ) , V_231 ) ;
F_17 ( V_11 ) ;
}
static void F_156 ( struct V_82 * V_83 , struct V_39 * V_7 )
{
if ( V_83 -> V_235 == 0 )
V_83 -> V_235 = F_151 ( V_7 ) ;
}
static unsigned short F_157 ( struct V_82 * V_83 )
{
unsigned short V_231 = V_83 -> V_235 ;
if ( V_231 == 0 && V_83 -> V_11 . V_236 )
V_231 = F_147 () ;
return V_231 ;
}
static unsigned short F_158 ( struct V_82 * V_83 , unsigned short V_231 )
{
if ( V_83 -> V_235 != 0 )
V_83 -> V_235 = 0 ;
if ( ! V_83 -> V_11 . V_236 )
return 0 ;
if ( V_231 <= V_226 || V_231 > V_225 )
return V_225 ;
return -- V_231 ;
}
static int F_159 ( struct V_82 * V_83 , struct V_39 * V_7 )
{
struct V_230 V_237 ;
int V_64 , V_238 = 0 ;
unsigned short V_231 = F_157 ( V_83 ) ;
unsigned short V_239 ;
if ( V_231 == 0 )
return 0 ;
memcpy ( & V_237 , & V_83 -> V_240 , V_83 -> V_11 . V_40 ) ;
do {
F_155 ( (struct V_10 * ) & V_237 , V_231 ) ;
V_64 = F_160 ( V_7 , (struct V_10 * ) & V_237 ,
V_83 -> V_11 . V_40 ) ;
if ( V_64 == 0 ) {
V_83 -> V_235 = V_231 ;
break;
}
V_239 = V_231 ;
V_231 = F_158 ( V_83 , V_231 ) ;
if ( V_231 > V_239 )
V_238 ++ ;
} while ( V_64 == - V_123 && V_238 != 2 );
if ( V_237 . V_232 == V_25 )
F_2 ( L_48 , V_108 ,
& ( (struct V_14 * ) & V_237 ) -> V_26 ,
V_231 , V_64 ? L_49 : L_50 , V_64 ) ;
else
F_2 ( L_51 , V_108 ,
& ( (struct V_15 * ) & V_237 ) -> V_29 ,
V_231 , V_64 ? L_49 : L_50 , V_64 ) ;
return V_64 ;
}
static void F_161 ( struct V_80 * V_81 )
{
F_162 ( V_81 -> V_241 ) ;
}
static void F_163 ( struct V_6 * V_11 , unsigned short V_231 )
{
}
static inline void F_164 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_165 ( V_8 , L_52 ,
& V_242 [ 1 ] , L_53 , & V_243 [ 1 ] ) ;
}
static inline void F_166 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_165 ( V_8 , L_54 ,
& V_242 [ 0 ] , L_55 , & V_243 [ 0 ] ) ;
}
static inline void F_167 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_165 ( V_8 , L_56 ,
& V_242 [ 1 ] , L_57 , & V_243 [ 1 ] ) ;
}
static inline void F_168 ( int V_244 , struct V_39 * V_7 )
{
if ( F_49 ( ! F_169 ( V_7 -> V_8 ) ) )
return;
switch ( V_244 ) {
case V_20 :
F_164 ( V_7 ) ;
break;
case V_25 :
F_166 ( V_7 ) ;
break;
case V_28 :
F_167 ( V_7 ) ;
break;
}
}
static inline void F_168 ( int V_244 , struct V_39 * V_7 )
{
}
static void F_170 ( struct V_163 * V_164 )
{
}
static struct V_39 * F_171 ( struct V_6 * V_11 ,
struct V_82 * V_83 , int V_244 , int type ,
int V_33 , bool V_245 )
{
struct V_39 * V_7 ;
int V_64 ;
V_64 = F_172 ( V_11 -> V_246 , V_244 , type , V_33 , & V_7 , 1 ) ;
if ( V_64 < 0 ) {
F_2 ( L_58 ,
V_33 , - V_64 ) ;
goto V_78;
}
F_168 ( V_244 , V_7 ) ;
if ( V_245 )
F_149 ( V_7 ) ;
V_64 = F_159 ( V_83 , V_7 ) ;
if ( V_64 ) {
F_76 ( V_7 ) ;
goto V_78;
}
return V_7 ;
V_78:
return F_173 ( V_64 ) ;
}
static int F_174 ( struct V_6 * V_11 ,
struct V_39 * V_7 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 ,
V_11 ) ;
if ( ! V_83 -> V_86 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
F_71 ( & V_8 -> V_137 ) ;
F_52 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_129 = F_103 ;
V_8 -> V_101 = F_141 ;
F_175 ( V_8 , V_247 ) ;
V_8 -> V_134 = F_61 ;
V_8 -> V_248 = V_249 ;
F_72 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_73 ( & V_8 -> V_137 ) ;
}
V_11 -> V_250 . V_251 ++ ;
V_11 -> V_250 . V_252 = V_253 ;
return F_176 ( V_7 , F_4 ( V_11 ) , V_11 -> V_40 , 0 ) ;
}
static int F_177 ( struct V_82 * V_83 )
{
struct V_6 * V_11 = & V_83 -> V_11 ;
struct V_39 * V_7 ;
int V_106 = - V_254 ;
V_106 = F_172 ( V_11 -> V_246 , V_20 ,
V_255 , 0 , & V_7 , 1 ) ;
if ( V_106 < 0 ) {
F_2 ( L_59
L_60 , - V_106 ) ;
goto V_78;
}
F_168 ( V_20 , V_7 ) ;
F_2 ( L_61 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
V_106 = F_174 ( V_11 , V_7 ) ;
F_178 ( V_11 , V_7 , V_106 ) ;
switch ( V_106 ) {
case 0 :
F_2 ( L_62 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
F_179 ( V_11 ) ;
case - V_109 :
break;
case - V_256 :
F_2 ( L_63 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
break;
case - V_115 :
F_2 ( L_64 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
break;
default:
F_116 ( V_257 L_65 ,
V_108 , - V_106 ,
V_11 -> V_22 [ V_23 ] ) ;
}
V_78:
F_137 ( V_11 ) ;
F_64 ( V_11 , V_106 ) ;
return V_106 ;
}
static void F_180 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
int V_90 ;
if ( F_181 ( V_81 ) ) {
F_182 ( V_81 , - V_96 ) ;
return;
}
V_90 = F_177 ( V_83 ) ;
if ( V_90 && ! F_183 ( V_81 ) )
F_184 ( 15000 ) ;
}
static void F_185 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 ,
V_11 ) ;
if ( ! V_83 -> V_86 )
return;
if ( F_67 ( & V_11 -> V_142 ) )
F_186 ( V_83 -> V_86 ) ;
}
static int
F_187 ( struct V_6 * V_11 )
{
struct V_82 * V_258 = F_28 ( V_11 , struct V_82 , V_11 ) ;
if ( F_188 ( & V_11 -> V_142 ) != 1 )
return 0 ;
if ( F_189 ( & V_11 -> V_127 , V_259 , V_260 ) )
return - V_261 ;
if ( V_258 -> V_86 )
F_186 ( V_258 -> V_86 ) ;
F_51 ( V_11 , NULL ) ;
return 0 ;
}
static void
F_190 ( struct V_6 * V_11 )
{
struct V_82 * V_258 = F_28 ( V_11 , struct V_82 , V_11 ) ;
if ( ! F_191 ( & V_11 -> V_142 ) )
return;
if ( F_189 ( & V_11 -> V_127 , V_259 , V_260 ) )
return;
if ( V_258 -> V_86 )
F_68 ( V_258 -> V_86 ) ;
F_51 ( V_11 , NULL ) ;
}
static void F_185 ( struct V_6 * V_11 )
{
}
static int
F_187 ( struct V_6 * V_11 )
{
return - V_262 ;
}
static void
F_190 ( struct V_6 * V_11 )
{
}
static void F_192 ( struct V_6 * V_11 , struct V_39 * V_7 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
if ( ! V_83 -> V_86 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
F_71 ( & V_8 -> V_137 ) ;
F_52 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_129 = F_103 ;
V_8 -> V_101 = F_141 ;
F_175 ( V_8 , V_247 ) ;
V_8 -> V_248 = V_249 ;
F_179 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_185 ( V_11 ) ;
F_73 ( & V_8 -> V_137 ) ;
}
F_144 ( V_11 ) ;
V_11 -> V_250 . V_252 = V_253 ;
}
static void F_193 ( struct V_163 * V_164 )
{
struct V_82 * V_83 =
F_28 ( V_164 , struct V_82 , V_146 . V_164 ) ;
struct V_6 * V_11 = & V_83 -> V_11 ;
struct V_39 * V_7 = V_83 -> V_7 ;
int V_106 = - V_254 ;
V_7 = F_171 ( V_11 , V_83 ,
F_4 ( V_11 ) -> V_19 , V_263 ,
V_264 , false ) ;
if ( F_194 ( V_7 ) )
goto V_78;
F_2 ( L_66
L_67 , V_11 ,
V_11 -> V_22 [ V_35 ] ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ) ;
F_192 ( V_11 , V_7 ) ;
F_178 ( V_11 , V_7 , 0 ) ;
V_106 = 0 ;
V_78:
F_195 ( V_11 , V_83 ) ;
F_137 ( V_11 ) ;
F_64 ( V_11 , V_106 ) ;
}
static void F_196 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
if ( V_7 == NULL )
return;
if ( F_31 ( V_11 ) ) {
F_69 ( V_7 , V_143 ) ;
F_197 ( V_11 , V_7 ) ;
} else
F_66 ( V_83 ) ;
}
static void F_48 ( struct V_6 * V_11 ,
struct V_39 * V_7 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
unsigned int V_265 ;
unsigned int V_266 ;
unsigned int V_267 = 1 ;
unsigned int V_268 ;
F_30 ( & V_11 -> V_95 ) ;
V_265 = F_198 ( V_11 -> V_269 -> V_270 , V_271 ) ;
V_266 = V_11 -> V_269 -> V_272 + 1 ;
V_268 = F_199 ( V_11 -> V_269 -> V_270 ) *
( V_11 -> V_269 -> V_272 + 1 ) ;
F_55 ( V_119 , & V_83 -> V_120 ) ;
F_33 ( & V_11 -> V_95 ) ;
F_150 ( V_7 , V_228 , V_273 ,
( char * ) & V_267 , sizeof( V_267 ) ) ;
F_150 ( V_7 , V_274 , V_275 ,
( char * ) & V_265 , sizeof( V_265 ) ) ;
F_150 ( V_7 , V_274 , V_276 ,
( char * ) & V_265 , sizeof( V_265 ) ) ;
F_150 ( V_7 , V_274 , V_277 ,
( char * ) & V_266 , sizeof( V_266 ) ) ;
F_150 ( V_7 , V_274 , V_278 ,
( char * ) & V_268 , sizeof( V_268 ) ) ;
}
static void F_200 ( struct V_6 * V_11 ,
unsigned long V_279 ,
unsigned long V_280 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_281 V_282 ;
unsigned long V_283 ;
F_30 ( & V_11 -> V_95 ) ;
if ( V_280 < V_11 -> V_284 )
V_11 -> V_284 = V_280 ;
if ( V_279 < V_11 -> V_279 ) {
memcpy ( & V_282 , V_11 -> V_269 , sizeof( V_282 ) ) ;
V_283 = F_198 ( V_279 , V_282 . V_272 + 1 ) ;
if ( V_283 < V_213 << 1 )
V_283 = V_213 << 1 ;
V_282 . V_270 = V_283 ;
V_282 . V_285 = V_283 ;
memcpy ( & V_83 -> V_286 , & V_282 ,
sizeof( V_83 -> V_286 ) ) ;
V_11 -> V_269 = & V_83 -> V_286 ;
V_11 -> V_279 = V_279 ;
}
F_36 ( V_119 , & V_83 -> V_120 ) ;
F_33 ( & V_11 -> V_95 ) ;
}
static int F_201 ( struct V_6 * V_11 , struct V_39 * V_7 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
int V_90 = - V_96 ;
if ( ! V_83 -> V_86 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
unsigned int V_287 = V_288 ;
F_150 ( V_7 , V_289 , V_290 ,
( char * ) & V_287 , sizeof( V_287 ) ) ;
F_48 ( V_11 , V_7 ) ;
F_71 ( & V_8 -> V_137 ) ;
F_52 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_129 = F_103 ;
V_8 -> V_131 = F_132 ;
V_8 -> V_101 = F_142 ;
F_175 ( V_8 , V_247 ) ;
V_8 -> V_134 = F_61 ;
V_8 -> V_248 = V_249 ;
F_202 ( V_8 , V_291 ) ;
F_203 ( V_8 ) -> V_292 |= V_293 ;
F_72 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_73 ( & V_8 -> V_137 ) ;
}
if ( ! F_45 ( V_11 ) )
goto V_78;
F_185 ( V_11 ) ;
V_11 -> V_250 . V_251 ++ ;
V_11 -> V_250 . V_252 = V_253 ;
F_36 ( V_208 , & V_83 -> V_120 ) ;
V_90 = F_176 ( V_7 , F_4 ( V_11 ) , V_11 -> V_40 , V_294 ) ;
switch ( V_90 ) {
case 0 :
F_156 ( V_83 , V_7 ) ;
case - V_295 :
if ( V_11 -> V_145 < V_213 )
V_11 -> V_145 = V_213 ;
break;
case - V_296 :
V_83 -> V_235 = 0 ;
}
V_78:
return V_90 ;
}
static void F_204 ( struct V_163 * V_164 )
{
struct V_82 * V_83 =
F_28 ( V_164 , struct V_82 , V_146 . V_164 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
struct V_6 * V_11 = & V_83 -> V_11 ;
int V_106 = - V_254 ;
if ( ! V_7 ) {
V_7 = F_171 ( V_11 , V_83 ,
F_4 ( V_11 ) -> V_19 , V_255 ,
V_297 , true ) ;
if ( F_194 ( V_7 ) ) {
V_106 = F_205 ( V_7 ) ;
goto V_78;
}
}
F_2 ( L_66
L_67 , V_11 ,
V_11 -> V_22 [ V_35 ] ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ) ;
V_106 = F_201 ( V_11 , V_7 ) ;
F_178 ( V_11 , V_7 , V_106 ) ;
F_2 ( L_68 ,
V_11 , - V_106 , F_31 ( V_11 ) ,
V_7 -> V_8 -> V_139 ) ;
switch ( V_106 ) {
default:
F_116 ( L_69 ,
V_108 , V_106 ) ;
case - V_296 :
F_106 ( V_11 ) ;
break;
case 0 :
case - V_295 :
case - V_298 :
F_195 ( V_11 , V_83 ) ;
return;
case - V_262 :
case - V_115 :
case - V_122 :
case - V_114 :
case - V_123 :
case - V_109 :
F_64 ( V_11 , V_106 ) ;
F_106 ( V_11 ) ;
goto V_78;
}
V_106 = - V_91 ;
V_78:
F_195 ( V_11 , V_83 ) ;
F_137 ( V_11 ) ;
F_64 ( V_11 , V_106 ) ;
}
static unsigned long F_206 ( const struct V_6 * V_11 )
{
unsigned long V_299 , V_300 = V_253 ;
V_299 = V_11 -> V_250 . V_252 + V_11 -> V_145 ;
if ( F_207 ( V_299 , V_300 ) )
return V_299 - V_300 ;
return 0 ;
}
static void F_208 ( struct V_6 * V_11 )
{
V_11 -> V_145 <<= 1 ;
if ( V_11 -> V_145 > V_11 -> V_284 )
V_11 -> V_145 = V_11 -> V_284 ;
if ( V_11 -> V_145 < V_213 )
V_11 -> V_145 = V_213 ;
}
static void F_209 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
unsigned long V_301 = 0 ;
F_49 ( ! F_210 ( V_11 , V_81 , V_83 ) ) ;
if ( V_83 -> V_7 != NULL ) {
F_2 ( L_70
L_71 ,
V_11 , V_11 -> V_145 / V_271 ) ;
F_66 ( V_83 ) ;
V_301 = F_206 ( V_11 ) ;
F_208 ( V_11 ) ;
} else
F_2 ( L_72 , V_11 ) ;
F_211 ( V_167 ,
& V_83 -> V_146 ,
V_301 ) ;
}
static void F_212 ( struct V_6 * V_11 , struct V_302 * V_303 )
{
long V_304 = 0 ;
if ( F_31 ( V_11 ) )
V_304 = ( long ) ( V_253 - V_11 -> V_305 ) / V_271 ;
F_213 ( V_303 , L_73
L_74 ,
V_11 -> V_250 . V_306 ,
V_11 -> V_250 . V_251 ,
V_11 -> V_250 . V_307 ,
V_304 ,
V_11 -> V_250 . V_308 ,
V_11 -> V_250 . V_309 ,
V_11 -> V_250 . V_310 ,
V_11 -> V_250 . V_311 ,
V_11 -> V_250 . V_312 ,
V_11 -> V_250 . V_313 ,
V_11 -> V_250 . V_314 ,
V_11 -> V_250 . V_315 ) ;
}
static void F_214 ( struct V_6 * V_11 , struct V_302 * V_303 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
F_213 ( V_303 , L_75
L_76 ,
V_83 -> V_235 ,
V_11 -> V_250 . V_306 ,
V_11 -> V_250 . V_308 ,
V_11 -> V_250 . V_309 ,
V_11 -> V_250 . V_310 ,
V_11 -> V_250 . V_311 ,
V_11 -> V_250 . V_312 ,
V_11 -> V_250 . V_313 ,
V_11 -> V_250 . V_314 ,
V_11 -> V_250 . V_315 ) ;
}
static void F_215 ( struct V_6 * V_11 , struct V_302 * V_303 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
long V_304 = 0 ;
if ( F_31 ( V_11 ) )
V_304 = ( long ) ( V_253 - V_11 -> V_305 ) / V_271 ;
F_213 ( V_303 , L_77
L_74 ,
V_83 -> V_235 ,
V_11 -> V_250 . V_306 ,
V_11 -> V_250 . V_251 ,
V_11 -> V_250 . V_307 ,
V_304 ,
V_11 -> V_250 . V_308 ,
V_11 -> V_250 . V_309 ,
V_11 -> V_250 . V_310 ,
V_11 -> V_250 . V_311 ,
V_11 -> V_250 . V_312 ,
V_11 -> V_250 . V_313 ,
V_11 -> V_250 . V_314 ,
V_11 -> V_250 . V_315 ) ;
}
static int F_216 ( struct V_80 * V_81 )
{
struct V_88 * V_316 = V_81 -> V_84 ;
T_4 V_60 = V_316 -> V_317 ;
struct V_58 * V_58 ;
struct V_318 * V_4 ;
if ( V_60 > V_197 - sizeof( struct V_318 ) ) {
F_217 ( 1 , L_78 ,
V_60 ) ;
return - V_262 ;
}
V_58 = F_218 ( V_24 ) ;
if ( ! V_58 )
return - V_319 ;
V_4 = F_219 ( V_58 ) ;
V_4 -> V_73 = V_197 ;
V_316 -> V_320 = V_4 -> V_200 ;
V_316 -> V_321 = ( char * ) V_316 -> V_320 + V_316 -> V_317 ;
return 0 ;
}
static void F_220 ( struct V_80 * V_81 )
{
void * V_322 = V_81 -> V_84 -> V_320 ;
struct V_318 * V_4 ;
V_4 = F_28 ( V_322 , struct V_318 , V_200 ) ;
F_221 ( ( unsigned long ) V_4 ) ;
}
static int F_222 ( struct V_88 * V_89 )
{
int V_73 ;
struct V_54 * V_323 = & V_89 -> V_105 ;
struct V_6 * V_11 = V_89 -> V_85 ;
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
unsigned long V_324 ;
unsigned long V_325 ;
F_38 ( V_323 ) ;
V_325 = ( unsigned long ) V_323 -> V_79 [ 0 ] . V_52 & ~ V_69 ;
V_324 = ( unsigned long ) V_323 -> V_77 [ 0 ] . V_52 & ~ V_69 ;
V_73 = F_223 ( V_7 , V_323 ,
F_224 ( V_323 -> V_77 [ 0 ] . V_52 ) , V_324 ,
V_323 -> V_79 [ 0 ] . V_52 , V_325 ) ;
if ( V_73 != V_323 -> V_73 ) {
F_116 ( V_326 L_79 ) ;
V_73 = - V_91 ;
}
return V_73 ;
}
static int F_225 ( struct V_80 * V_81 )
{
struct V_88 * V_89 = V_81 -> V_84 ;
struct V_327 * V_11 ;
int V_73 ;
F_2 ( L_80 , F_12 ( V_89 -> V_191 ) ) ;
V_11 = V_89 -> V_85 -> V_328 ;
if ( ! F_226 ( & V_11 -> V_329 ) ) {
F_227 ( & V_11 -> V_330 , V_81 , NULL ) ;
if ( ! F_226 ( & V_11 -> V_329 ) )
return - V_91 ;
F_228 ( & V_11 -> V_330 , V_81 ) ;
}
if ( F_47 ( V_331 , & V_11 -> V_332 ) )
V_73 = - V_96 ;
else
V_73 = F_222 ( V_89 ) ;
F_74 ( & V_11 -> V_329 ) ;
if ( V_73 > 0 )
V_73 = 0 ;
return V_73 ;
}
static void F_229 ( struct V_6 * V_11 )
{
}
static void F_230 ( struct V_6 * V_11 )
{
F_2 ( L_81 , V_11 ) ;
F_78 ( V_11 ) ;
F_83 ( V_148 ) ;
}
static int F_231 ( const int V_244 , struct V_10 * V_16 )
{
static const struct V_14 sin = {
. V_333 = V_25 ,
. V_26 . V_27 = F_232 ( V_334 ) ,
} ;
static const struct V_15 V_17 = {
. V_335 = V_28 ,
. V_29 = V_336 ,
} ;
switch ( V_244 ) {
case V_20 :
break;
case V_25 :
memcpy ( V_16 , & sin , sizeof( sin ) ) ;
break;
case V_28 :
memcpy ( V_16 , & V_17 , sizeof( V_17 ) ) ;
break;
default:
F_2 ( L_82 , V_108 ) ;
return - V_337 ;
}
return 0 ;
}
static struct V_6 * F_233 ( struct V_338 * args ,
unsigned int V_339 ,
unsigned int V_340 )
{
struct V_6 * V_11 ;
struct V_82 * V_341 ;
if ( args -> V_40 > sizeof( V_11 -> V_12 ) ) {
F_2 ( L_83 ) ;
return F_173 ( - V_342 ) ;
}
V_11 = F_234 ( args -> V_194 , sizeof( * V_341 ) , V_339 ,
V_340 ) ;
if ( V_11 == NULL ) {
F_2 ( L_84
L_85 ) ;
return F_173 ( - V_319 ) ;
}
V_341 = F_28 ( V_11 , struct V_82 , V_11 ) ;
F_235 ( & V_341 -> V_144 ) ;
memcpy ( & V_11 -> V_12 , args -> V_343 , args -> V_40 ) ;
V_11 -> V_40 = args -> V_40 ;
if ( args -> V_240 )
memcpy ( & V_341 -> V_240 , args -> V_240 , args -> V_40 ) ;
else {
int V_64 ;
V_64 = F_231 ( args -> V_343 -> V_19 ,
(struct V_10 * ) & V_341 -> V_240 ) ;
if ( V_64 != 0 ) {
F_79 ( V_11 ) ;
return F_173 ( V_64 ) ;
}
}
return V_11 ;
}
static struct V_6 * F_236 ( struct V_338 * args )
{
struct V_13 * V_18 = (struct V_13 * ) args -> V_343 ;
struct V_82 * V_83 ;
struct V_6 * V_11 ;
struct V_6 * V_90 ;
V_11 = F_233 ( args , V_344 ,
V_345 ) ;
if ( F_194 ( V_11 ) )
return V_11 ;
V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_346 = 0 ;
V_11 -> V_347 = sizeof( V_103 ) / sizeof( T_1 ) ;
V_11 -> V_348 = V_349 ;
V_11 -> V_350 = V_351 ;
V_11 -> V_145 = V_213 ;
V_11 -> V_352 = V_353 ;
V_11 -> V_70 = & V_354 ;
V_11 -> V_269 = & V_355 ;
F_237 ( & V_83 -> V_147 , F_94 ) ;
F_238 ( & V_83 -> V_146 ,
F_170 ) ;
switch ( V_18 -> V_356 ) {
case V_20 :
if ( V_18 -> V_21 [ 0 ] != '/' ) {
F_2 ( L_86 ,
V_18 -> V_21 ) ;
V_90 = F_173 ( - V_262 ) ;
goto V_357;
}
F_162 ( V_11 ) ;
F_16 ( V_11 , L_87 , V_358 ) ;
V_90 = F_173 ( F_177 ( V_83 ) ) ;
if ( V_90 )
goto V_357;
break;
default:
V_90 = F_173 ( - V_337 ) ;
goto V_357;
}
F_2 ( L_88 ,
V_11 -> V_22 [ V_23 ] ) ;
if ( F_239 ( V_148 ) )
return V_11 ;
V_90 = F_173 ( - V_262 ) ;
V_357:
F_78 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_240 ( struct V_338 * args )
{
struct V_10 * V_12 = args -> V_343 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_6 * V_90 ;
V_11 = F_233 ( args , V_359 ,
V_359 ) ;
if ( F_194 ( V_11 ) )
return V_11 ;
V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_346 = V_264 ;
V_11 -> V_347 = 0 ;
V_11 -> V_348 = ( 1U << 16 ) - ( V_360 << 3 ) ;
V_11 -> V_350 = V_351 ;
V_11 -> V_145 = V_361 ;
V_11 -> V_352 = V_353 ;
V_11 -> V_70 = & V_362 ;
V_11 -> V_269 = & V_363 ;
F_237 ( & V_83 -> V_147 , F_102 ) ;
F_238 ( & V_83 -> V_146 , F_193 ) ;
switch ( V_12 -> V_19 ) {
case V_25 :
if ( ( (struct V_14 * ) V_12 ) -> V_234 != F_241 ( 0 ) )
F_162 ( V_11 ) ;
F_16 ( V_11 , L_89 , V_364 ) ;
break;
case V_28 :
if ( ( (struct V_15 * ) V_12 ) -> V_233 != F_241 ( 0 ) )
F_162 ( V_11 ) ;
F_16 ( V_11 , L_89 , V_365 ) ;
break;
default:
V_90 = F_173 ( - V_337 ) ;
goto V_357;
}
if ( F_45 ( V_11 ) )
F_2 ( L_90 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
else
F_2 ( L_91 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_35 ] ) ;
if ( F_239 ( V_148 ) )
return V_11 ;
V_90 = F_173 ( - V_262 ) ;
V_357:
F_78 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_242 ( struct V_338 * args )
{
struct V_10 * V_12 = args -> V_343 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_6 * V_90 ;
unsigned int V_340 = V_345 ;
if ( args -> V_61 & V_366 )
V_340 = V_367 ;
V_11 = F_233 ( args , V_344 ,
V_340 ) ;
if ( F_194 ( V_11 ) )
return V_11 ;
V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_346 = V_297 ;
V_11 -> V_347 = sizeof( V_103 ) / sizeof( T_1 ) ;
V_11 -> V_348 = V_349 ;
V_11 -> V_350 = V_351 ;
V_11 -> V_145 = V_213 ;
V_11 -> V_352 = V_353 ;
V_11 -> V_70 = & V_368 ;
V_11 -> V_269 = & V_369 ;
V_11 -> V_284 = V_11 -> V_269 -> V_285 ;
V_11 -> V_279 = V_11 -> V_269 -> V_270 *
( V_11 -> V_269 -> V_272 + 1 ) ;
F_237 ( & V_83 -> V_147 , F_131 ) ;
F_238 ( & V_83 -> V_146 , F_204 ) ;
switch ( V_12 -> V_19 ) {
case V_25 :
if ( ( (struct V_14 * ) V_12 ) -> V_234 != F_241 ( 0 ) )
F_162 ( V_11 ) ;
F_16 ( V_11 , L_92 , V_370 ) ;
break;
case V_28 :
if ( ( (struct V_15 * ) V_12 ) -> V_233 != F_241 ( 0 ) )
F_162 ( V_11 ) ;
F_16 ( V_11 , L_92 , V_371 ) ;
break;
default:
V_90 = F_173 ( - V_337 ) ;
goto V_357;
}
if ( F_45 ( V_11 ) )
F_2 ( L_90 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
else
F_2 ( L_91 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_35 ] ) ;
if ( F_239 ( V_148 ) )
return V_11 ;
V_90 = F_173 ( - V_262 ) ;
V_357:
F_78 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_243 ( struct V_338 * args )
{
struct V_10 * V_12 = args -> V_343 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_372 * V_373 ;
struct V_6 * V_90 ;
V_11 = F_233 ( args , V_344 ,
V_344 ) ;
if ( F_194 ( V_11 ) )
return V_11 ;
V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_346 = V_297 ;
V_11 -> V_347 = sizeof( V_103 ) / sizeof( T_1 ) ;
V_11 -> V_348 = V_349 ;
V_11 -> V_269 = & V_369 ;
F_162 ( V_11 ) ;
V_11 -> V_350 = 0 ;
V_11 -> V_145 = 0 ;
V_11 -> V_352 = 0 ;
V_11 -> V_70 = & V_374 ;
switch ( V_12 -> V_19 ) {
case V_25 :
F_16 ( V_11 , L_92 ,
V_370 ) ;
break;
case V_28 :
F_16 ( V_11 , L_92 ,
V_371 ) ;
break;
default:
V_90 = F_173 ( - V_337 ) ;
goto V_357;
}
F_2 ( L_90 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
F_244 ( V_11 ) ;
args -> V_328 -> V_375 = V_11 ;
V_11 -> V_328 = args -> V_328 ;
V_373 = F_28 ( args -> V_328 , struct V_372 , V_376 ) ;
V_83 -> V_7 = V_373 -> V_377 ;
V_83 -> V_86 = V_373 -> V_378 ;
F_179 ( V_11 ) ;
if ( F_239 ( V_148 ) )
return V_11 ;
args -> V_328 -> V_375 = NULL ;
args -> V_328 -> V_379 = NULL ;
F_245 ( V_11 ) ;
V_90 = F_173 ( - V_262 ) ;
V_357:
F_78 ( V_11 ) ;
return V_90 ;
}
int F_246 ( void )
{
#if F_247 ( V_380 )
if ( ! V_381 )
V_381 = F_248 ( V_382 ) ;
#endif
F_249 ( & V_383 ) ;
F_249 ( & V_384 ) ;
F_249 ( & V_385 ) ;
F_249 ( & V_386 ) ;
return 0 ;
}
void F_250 ( void )
{
#if F_247 ( V_380 )
if ( V_381 ) {
F_251 ( V_381 ) ;
V_381 = NULL ;
}
#endif
F_252 ( & V_383 ) ;
F_252 ( & V_384 ) ;
F_252 ( & V_385 ) ;
F_252 ( & V_386 ) ;
}
static int F_253 ( const char * V_387 ,
const struct V_388 * V_389 ,
unsigned int V_390 , unsigned int V_391 )
{
unsigned int V_392 ;
int V_90 ;
if ( ! V_387 )
return - V_262 ;
V_90 = F_254 ( V_387 , 0 , & V_392 ) ;
if ( V_90 )
return V_90 ;
if ( V_392 < V_390 || V_392 > V_391 )
return - V_262 ;
* ( ( unsigned int * ) V_389 -> V_199 ) = V_392 ;
return 0 ;
}
static int F_255 ( const char * V_387 , const struct V_388 * V_389 )
{
if ( V_389 -> V_199 == & V_226 )
return F_253 ( V_387 , V_389 ,
V_393 ,
V_225 ) ;
return F_253 ( V_387 , V_389 ,
V_226 ,
V_394 ) ;
}
static int F_256 ( const char * V_387 ,
const struct V_388 * V_389 )
{
return F_253 ( V_387 , V_389 ,
V_395 ,
V_396 ) ;
}
static int F_257 ( const char * V_387 ,
const struct V_388 * V_389 )
{
return F_253 ( V_387 , V_389 ,
V_395 ,
V_367 ) ;
}

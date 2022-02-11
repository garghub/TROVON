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
F_47 ( V_75 == 0 && V_106 == 0 ) ;
if ( V_106 == - V_91 ) {
if ( F_48 ( V_119 , & V_83 -> V_7 -> V_61 ) )
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
case - V_120 :
case - V_115 :
case - V_96 :
case - V_121 :
case - V_109 :
case - V_111 :
break;
default:
F_2 ( L_12 ,
- V_106 ) ;
}
return V_106 ;
}
static void F_49 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
struct V_88 * V_89 ;
if ( V_81 != V_11 -> V_122 )
return;
if ( V_81 == NULL )
goto V_123;
V_89 = V_81 -> V_84 ;
if ( V_89 == NULL )
goto V_123;
if ( V_89 -> V_94 == 0 )
goto V_123;
if ( V_89 -> V_94 == V_89 -> V_105 . V_73 )
goto V_123;
F_36 ( V_124 , & V_11 -> V_125 ) ;
V_123:
F_50 ( V_11 , V_81 ) ;
}
static void F_51 ( struct V_82 * V_83 , struct V_7 * V_8 )
{
V_83 -> V_126 = V_8 -> V_127 ;
V_83 -> V_128 = V_8 -> V_129 ;
V_83 -> V_130 = V_8 -> V_101 ;
V_83 -> V_131 = V_8 -> V_132 ;
}
static void F_52 ( struct V_82 * V_83 , struct V_7 * V_8 )
{
V_8 -> V_127 = V_83 -> V_126 ;
V_8 -> V_129 = V_83 -> V_128 ;
V_8 -> V_101 = V_83 -> V_130 ;
V_8 -> V_132 = V_83 -> V_131 ;
}
static void F_53 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
F_54 ( V_133 , & V_83 -> V_134 ) ;
}
static void F_55 ( struct V_6 * V_11 )
{
F_56 () ;
F_54 ( V_124 , & V_11 -> V_125 ) ;
F_54 ( V_135 , & V_11 -> V_125 ) ;
F_53 ( V_11 ) ;
F_57 () ;
}
static void F_58 ( struct V_6 * V_11 )
{
F_55 ( V_11 ) ;
F_59 ( V_11 ) ;
}
static void F_60 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
int V_64 ;
F_61 ( & V_8 -> V_136 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_78;
V_64 = - V_8 -> V_137 ;
if ( V_64 == 0 )
goto V_78;
if ( V_8 -> V_138 == V_139 )
F_58 ( V_11 ) ;
F_2 ( L_15 ,
V_11 , - V_64 ) ;
F_62 ( V_11 , V_8 -> V_140 , V_64 ) ;
F_63 ( V_11 , V_64 ) ;
V_78:
F_64 ( & V_8 -> V_136 ) ;
}
static void F_65 ( struct V_82 * V_83 )
{
struct V_39 * V_7 = V_83 -> V_7 ;
struct V_7 * V_8 = V_83 -> V_86 ;
struct V_6 * V_11 = & V_83 -> V_11 ;
if ( V_8 == NULL )
return;
if ( F_66 ( & V_83 -> V_11 . V_141 ) )
F_67 ( V_8 ) ;
F_68 ( V_7 , V_142 ) ;
F_69 ( & V_83 -> V_143 ) ;
F_70 ( & V_8 -> V_136 ) ;
V_83 -> V_86 = NULL ;
V_83 -> V_7 = NULL ;
V_8 -> V_9 = NULL ;
F_52 ( V_83 , V_8 ) ;
F_71 ( V_11 ) ;
F_72 ( & V_8 -> V_136 ) ;
F_55 ( V_11 ) ;
F_73 ( & V_83 -> V_143 ) ;
F_74 ( V_11 , V_7 ) ;
F_75 ( V_7 ) ;
}
static void F_43 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
F_2 ( L_16 , V_11 ) ;
F_65 ( V_83 ) ;
V_11 -> V_144 = 0 ;
F_59 ( V_11 ) ;
}
static void F_76 ( struct V_6 * V_11 )
{
F_2 ( L_17 ,
V_11 ) ;
F_59 ( V_11 ) ;
}
static void F_77 ( struct V_6 * V_11 )
{
F_19 ( V_11 ) ;
F_78 ( V_11 ) ;
}
static void F_79 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_28 ( V_11 ,
struct V_82 , V_11 ) ;
F_2 ( L_18 , V_11 ) ;
F_80 ( & V_83 -> V_145 ) ;
F_43 ( V_11 ) ;
F_81 ( & V_83 -> V_146 ) ;
F_77 ( V_11 ) ;
F_82 ( V_147 ) ;
}
static int F_83 ( struct V_54 * V_55 , struct V_148 * V_149 )
{
struct V_150 V_151 = {
. V_149 = V_149 ,
. V_59 = sizeof( V_103 ) ,
. V_3 = V_149 -> V_73 - sizeof( V_103 ) ,
} ;
if ( F_84 ( V_55 , 0 , & V_151 , V_152 ) < 0 )
return - 1 ;
if ( V_151 . V_3 )
return - 1 ;
return 0 ;
}
static void F_85 ( struct V_6 * V_11 ,
struct V_7 * V_8 ,
struct V_148 * V_149 )
{
struct V_80 * V_81 ;
struct V_88 * V_153 ;
int V_154 , V_155 ;
T_1 V_156 ;
T_5 * V_157 ;
V_154 = V_149 -> V_73 - sizeof( V_103 ) ;
if ( V_154 < 4 ) {
F_2 ( L_19 , V_154 ) ;
return;
}
V_157 = F_86 ( V_149 , sizeof( V_103 ) , sizeof( V_156 ) , & V_156 ) ;
if ( V_157 == NULL )
return;
F_30 ( & V_11 -> V_95 ) ;
V_153 = F_87 ( V_11 , * V_157 ) ;
if ( ! V_153 )
goto V_158;
V_81 = V_153 -> V_159 ;
V_155 = V_153 -> V_160 . V_161 ;
if ( V_155 > V_154 )
V_155 = V_154 ;
if ( F_83 ( & V_153 -> V_160 , V_149 ) ) {
F_2 ( L_20 ) ;
goto V_158;
}
F_88 ( V_81 , V_155 ) ;
V_158:
F_33 ( & V_11 -> V_95 ) ;
}
static void F_89 ( struct V_82 * V_83 )
{
struct V_148 * V_149 ;
struct V_7 * V_8 ;
int V_64 ;
F_69 ( & V_83 -> V_143 ) ;
V_8 = V_83 -> V_86 ;
if ( V_8 == NULL )
goto V_78;
for (; ; ) {
V_149 = F_90 ( V_8 , 0 , 1 , & V_64 ) ;
if ( V_149 != NULL ) {
F_85 ( & V_83 -> V_11 , V_8 , V_149 ) ;
F_91 ( V_8 , V_149 ) ;
continue;
}
if ( ! F_92 ( V_133 , & V_83 -> V_134 ) )
break;
}
V_78:
F_73 ( & V_83 -> V_143 ) ;
}
static void F_93 ( struct V_162 * V_163 )
{
struct V_82 * V_83 =
F_28 ( V_163 , struct V_82 , V_146 ) ;
F_89 ( V_83 ) ;
}
static void F_94 ( struct V_6 * V_11 ,
struct V_7 * V_8 ,
struct V_148 * V_149 )
{
struct V_80 * V_81 ;
struct V_88 * V_153 ;
int V_154 , V_155 ;
T_1 V_156 ;
T_5 * V_157 ;
V_154 = V_149 -> V_73 ;
if ( V_154 < 4 ) {
F_2 ( L_21 , V_154 ) ;
return;
}
V_157 = F_86 ( V_149 , 0 , sizeof( V_156 ) , & V_156 ) ;
if ( V_157 == NULL )
return;
F_30 ( & V_11 -> V_95 ) ;
V_153 = F_87 ( V_11 , * V_157 ) ;
if ( ! V_153 )
goto V_158;
V_81 = V_153 -> V_159 ;
if ( ( V_155 = V_153 -> V_160 . V_161 ) > V_154 )
V_155 = V_154 ;
if ( F_95 ( & V_153 -> V_160 , V_149 ) ) {
F_96 ( V_8 , V_164 ) ;
goto V_158;
}
F_96 ( V_8 , V_165 ) ;
F_97 ( V_11 , V_81 , V_155 ) ;
F_88 ( V_81 , V_155 ) ;
V_158:
F_33 ( & V_11 -> V_95 ) ;
}
static void F_98 ( struct V_82 * V_83 )
{
struct V_148 * V_149 ;
struct V_7 * V_8 ;
int V_64 ;
F_69 ( & V_83 -> V_143 ) ;
V_8 = V_83 -> V_86 ;
if ( V_8 == NULL )
goto V_78;
for (; ; ) {
V_149 = F_99 ( V_8 , 0 , 1 , & V_64 ) ;
if ( V_149 != NULL ) {
F_94 ( & V_83 -> V_11 , V_8 , V_149 ) ;
F_100 ( V_149 ) ;
continue;
}
if ( ! F_92 ( V_133 , & V_83 -> V_134 ) )
break;
}
V_78:
F_73 ( & V_83 -> V_143 ) ;
}
static void F_101 ( struct V_162 * V_163 )
{
struct V_82 * V_83 =
F_28 ( V_163 , struct V_82 , V_146 ) ;
F_98 ( V_83 ) ;
}
static void F_102 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
F_61 ( & V_8 -> V_136 ) ;
F_2 ( L_22 ) ;
V_11 = F_3 ( V_8 ) ;
if ( V_11 != NULL ) {
struct V_82 * V_83 = F_28 ( V_11 ,
struct V_82 , V_11 ) ;
V_83 -> V_126 ( V_8 ) ;
if ( V_11 -> V_144 )
V_11 -> V_144 = 0 ;
if ( ! F_103 ( V_133 , & V_83 -> V_134 ) )
F_104 ( V_166 , & V_83 -> V_146 ) ;
}
F_64 ( & V_8 -> V_136 ) ;
}
static void F_105 ( struct V_6 * V_11 )
{
F_106 ( V_11 ) ;
}
static inline void F_107 ( struct V_6 * V_11 , struct V_150 * V_151 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
T_4 V_73 , V_167 ;
char * V_168 ;
V_168 = ( ( char * ) & V_83 -> V_169 ) + V_83 -> V_170 ;
V_73 = sizeof( V_83 -> V_169 ) - V_83 -> V_170 ;
V_167 = V_152 ( V_151 , V_168 , V_73 ) ;
V_83 -> V_170 += V_167 ;
if ( V_167 != V_73 )
return;
V_83 -> V_171 = F_12 ( V_83 -> V_169 ) ;
if ( V_83 -> V_171 & V_104 )
V_83 -> V_172 |= V_173 ;
else
V_83 -> V_172 &= ~ V_173 ;
V_83 -> V_171 &= V_174 ;
V_83 -> V_172 &= ~ V_175 ;
V_83 -> V_170 = 0 ;
if ( F_26 ( V_83 -> V_171 < 8 ) ) {
F_2 ( L_23 ) ;
F_105 ( V_11 ) ;
return;
}
F_2 ( L_24 ,
V_83 -> V_171 ) ;
}
static void F_108 ( struct V_82 * V_83 )
{
if ( V_83 -> V_170 == V_83 -> V_171 ) {
V_83 -> V_172 |= V_175 ;
V_83 -> V_170 = 0 ;
if ( V_83 -> V_172 & V_173 ) {
V_83 -> V_172 &= ~ V_176 ;
V_83 -> V_172 |= V_177 ;
V_83 -> V_178 = 0 ;
}
}
}
static inline void F_109 ( struct V_82 * V_83 , struct V_150 * V_151 )
{
T_4 V_73 , V_167 ;
char * V_168 ;
V_73 = sizeof( V_83 -> V_179 ) - V_83 -> V_170 ;
F_2 ( L_25 , V_73 ) ;
V_168 = ( ( char * ) & V_83 -> V_179 ) + V_83 -> V_170 ;
V_167 = V_152 ( V_151 , V_168 , V_73 ) ;
V_83 -> V_170 += V_167 ;
if ( V_167 != V_73 )
return;
V_83 -> V_172 &= ~ V_177 ;
V_83 -> V_172 |= V_180 ;
V_83 -> V_178 = 4 ;
F_2 ( L_26 ,
( V_83 -> V_172 & V_181 ) ? L_27
: L_28 ,
F_12 ( V_83 -> V_179 ) ) ;
F_108 ( V_83 ) ;
}
static inline void F_110 ( struct V_82 * V_83 ,
struct V_150 * V_151 )
{
T_4 V_73 , V_167 ;
T_1 V_59 ;
char * V_168 ;
V_59 = V_83 -> V_170 - sizeof( V_83 -> V_179 ) ;
V_73 = sizeof( V_83 -> V_182 ) - V_59 ;
F_2 ( L_29 , V_73 ) ;
V_168 = ( ( char * ) & V_83 -> V_182 ) + V_59 ;
V_167 = V_152 ( V_151 , V_168 , V_73 ) ;
V_83 -> V_170 += V_167 ;
if ( V_167 != V_73 )
return;
V_83 -> V_172 &= ~ V_180 ;
switch ( F_12 ( V_83 -> V_182 ) ) {
case V_183 :
V_83 -> V_172 |= V_184 ;
V_83 -> V_172 |= V_176 ;
V_83 -> V_172 |= V_181 ;
break;
case V_185 :
V_83 -> V_172 |= V_184 ;
V_83 -> V_172 |= V_176 ;
V_83 -> V_172 &= ~ V_181 ;
break;
default:
F_2 ( L_30 ) ;
F_105 ( & V_83 -> V_11 ) ;
}
F_108 ( V_83 ) ;
}
static inline void F_111 ( struct V_6 * V_11 ,
struct V_150 * V_151 ,
struct V_88 * V_89 )
{
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_54 * V_186 ;
T_4 V_73 ;
T_3 V_187 ;
V_186 = & V_89 -> V_160 ;
if ( V_83 -> V_172 & V_184 ) {
memcpy ( V_186 -> V_77 [ 0 ] . V_52 + V_83 -> V_178 ,
& V_83 -> V_182 ,
sizeof( V_83 -> V_182 ) ) ;
V_83 -> V_178 += sizeof( V_83 -> V_182 ) ;
V_83 -> V_172 &= ~ V_184 ;
}
V_73 = V_151 -> V_3 ;
if ( V_73 > V_83 -> V_171 - V_83 -> V_170 ) {
struct V_150 V_188 ;
V_73 = V_83 -> V_171 - V_83 -> V_170 ;
memcpy ( & V_188 , V_151 , sizeof( V_188 ) ) ;
V_188 . V_3 = V_73 ;
V_187 = F_84 ( V_186 , V_83 -> V_178 ,
& V_188 , V_152 ) ;
V_151 -> V_3 -= V_187 ;
V_151 -> V_59 += V_187 ;
} else
V_187 = F_84 ( V_186 , V_83 -> V_178 ,
V_151 , V_152 ) ;
if ( V_187 > 0 ) {
V_83 -> V_178 += V_187 ;
V_83 -> V_170 += V_187 ;
}
if ( V_187 != V_73 ) {
V_83 -> V_172 &= ~ V_176 ;
F_2 ( L_31 ,
F_12 ( V_83 -> V_179 ) ) ;
F_2 ( L_32
L_33 ,
V_11 , V_83 -> V_178 ,
V_83 -> V_170 , V_83 -> V_171 ) ;
return;
}
F_2 ( L_34 ,
F_12 ( V_83 -> V_179 ) , V_187 ) ;
F_2 ( L_35
L_36 , V_11 , V_83 -> V_178 ,
V_83 -> V_170 , V_83 -> V_171 ) ;
if ( V_83 -> V_178 == V_89 -> V_160 . V_161 )
V_83 -> V_172 &= ~ V_176 ;
else if ( V_83 -> V_170 == V_83 -> V_171 ) {
if ( V_83 -> V_172 & V_173 )
V_83 -> V_172 &= ~ V_176 ;
}
}
static inline int F_112 ( struct V_6 * V_11 ,
struct V_150 * V_151 )
{
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_88 * V_89 ;
F_2 ( L_37 , F_12 ( V_83 -> V_179 ) ) ;
F_30 ( & V_11 -> V_95 ) ;
V_89 = F_87 ( V_11 , V_83 -> V_179 ) ;
if ( ! V_89 ) {
F_2 ( L_38 ,
F_12 ( V_83 -> V_179 ) ) ;
F_33 ( & V_11 -> V_95 ) ;
return - 1 ;
}
F_111 ( V_11 , V_151 , V_89 ) ;
if ( ! ( V_83 -> V_172 & V_176 ) )
F_88 ( V_89 -> V_159 , V_83 -> V_178 ) ;
F_33 ( & V_11 -> V_95 ) ;
return 0 ;
}
static int F_113 ( struct V_6 * V_11 ,
struct V_150 * V_151 )
{
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_88 * V_89 ;
F_30 ( & V_11 -> V_95 ) ;
V_89 = F_114 ( V_11 , V_83 -> V_179 ) ;
if ( V_89 == NULL ) {
F_33 ( & V_11 -> V_95 ) ;
F_115 ( V_189 L_39 ) ;
F_106 ( V_11 ) ;
return - 1 ;
}
F_2 ( L_40 , F_12 ( V_89 -> V_190 ) ) ;
F_111 ( V_11 , V_151 , V_89 ) ;
if ( ! ( V_83 -> V_172 & V_176 ) )
F_116 ( V_89 , V_83 -> V_178 ) ;
F_33 ( & V_11 -> V_95 ) ;
return 0 ;
}
static inline int F_117 ( struct V_6 * V_11 ,
struct V_150 * V_151 )
{
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
return ( V_83 -> V_172 & V_181 ) ?
F_112 ( V_11 , V_151 ) :
F_113 ( V_11 , V_151 ) ;
}
static int F_118 ( struct V_191 * V_192 , struct V_193 * V_193 )
{
int V_90 ;
V_90 = F_119 ( V_192 , L_41 , V_193 , V_194 , 0 ,
V_195 ) ;
if ( V_90 < 0 )
return V_90 ;
return 0 ;
}
static T_4 F_120 ( struct V_6 * V_11 )
{
return V_196 ;
}
static inline int F_117 ( struct V_6 * V_11 ,
struct V_150 * V_151 )
{
return F_112 ( V_11 , V_151 ) ;
}
static void F_121 ( struct V_6 * V_11 ,
struct V_150 * V_151 )
{
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
if ( F_117 ( V_11 , V_151 ) == 0 )
F_108 ( V_83 ) ;
else {
V_83 -> V_172 &= ~ V_176 ;
}
}
static inline void F_122 ( struct V_82 * V_83 , struct V_150 * V_151 )
{
T_4 V_73 ;
V_73 = V_83 -> V_171 - V_83 -> V_170 ;
if ( V_73 > V_151 -> V_3 )
V_73 = V_151 -> V_3 ;
V_151 -> V_3 -= V_73 ;
V_151 -> V_59 += V_73 ;
V_83 -> V_170 += V_73 ;
F_2 ( L_42 , V_73 ) ;
F_108 ( V_83 ) ;
}
static int F_123 ( T_6 * V_197 , struct V_148 * V_149 , unsigned int V_59 , T_4 V_73 )
{
struct V_6 * V_11 = V_197 -> V_198 . V_199 ;
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_150 V_151 = {
. V_149 = V_149 ,
. V_59 = V_59 ,
. V_3 = V_73 ,
} ;
F_2 ( L_43 ) ;
do {
F_124 ( V_83 ) ;
if ( V_83 -> V_172 & V_175 ) {
F_107 ( V_11 , & V_151 ) ;
continue;
}
if ( V_83 -> V_172 & V_177 ) {
F_109 ( V_83 , & V_151 ) ;
continue;
}
if ( V_83 -> V_172 & V_180 ) {
F_110 ( V_83 , & V_151 ) ;
continue;
}
if ( V_83 -> V_172 & V_176 ) {
F_121 ( V_11 , & V_151 ) ;
continue;
}
F_122 ( V_83 , & V_151 ) ;
} while ( V_151 . V_3 );
F_124 ( V_83 ) ;
F_2 ( L_44 ) ;
return V_73 - V_151 . V_3 ;
}
static void F_125 ( struct V_82 * V_83 )
{
struct V_6 * V_11 = & V_83 -> V_11 ;
struct V_7 * V_8 ;
T_6 V_197 = {
. V_3 = 2 * 1024 * 1024 ,
. V_198 . V_199 = V_11 ,
} ;
unsigned long V_200 = 0 ;
int V_201 = 0 ;
F_69 ( & V_83 -> V_143 ) ;
V_8 = V_83 -> V_86 ;
if ( V_8 == NULL )
goto V_78;
for (; ; ) {
F_126 ( V_8 ) ;
V_201 = F_127 ( V_8 , & V_197 , F_123 ) ;
if ( V_201 <= 0 ) {
F_54 ( V_133 , & V_83 -> V_134 ) ;
F_128 ( V_8 ) ;
if ( ! F_48 ( V_133 , & V_83 -> V_134 ) )
break;
} else {
F_128 ( V_8 ) ;
V_200 += V_201 ;
}
V_197 . V_3 = 65536 ;
}
V_78:
F_73 ( & V_83 -> V_143 ) ;
F_129 ( V_11 , V_201 , V_200 ) ;
}
static void F_130 ( struct V_162 * V_163 )
{
struct V_82 * V_83 =
F_28 ( V_163 , struct V_82 , V_146 ) ;
F_125 ( V_83 ) ;
}
static void F_131 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
struct V_82 * V_83 ;
F_61 ( & V_8 -> V_136 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_78;
F_2 ( L_45 , V_11 ) ;
F_2 ( L_46 ,
V_8 -> V_138 , F_31 ( V_11 ) ,
F_132 ( V_8 , V_202 ) ,
F_132 ( V_8 , V_203 ) ,
V_8 -> V_204 ) ;
V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
F_133 ( V_11 , V_8 -> V_140 ) ;
switch ( V_8 -> V_138 ) {
case V_205 :
F_134 ( & V_11 -> V_95 ) ;
if ( ! F_135 ( V_11 ) ) {
V_83 -> V_170 = 0 ;
V_83 -> V_171 = 0 ;
V_83 -> V_178 = 0 ;
V_83 -> V_172 =
V_175 | V_177 ;
V_11 -> V_206 ++ ;
F_54 ( V_207 , & V_83 -> V_134 ) ;
F_136 ( V_11 ) ;
F_63 ( V_11 , - V_91 ) ;
}
F_137 ( & V_11 -> V_95 ) ;
break;
case V_208 :
V_11 -> V_206 ++ ;
V_11 -> V_144 = 0 ;
F_36 ( V_135 , & V_11 -> V_125 ) ;
F_56 () ;
F_54 ( V_209 , & V_11 -> V_125 ) ;
F_54 ( V_124 , & V_11 -> V_125 ) ;
F_57 () ;
break;
case V_210 :
V_11 -> V_206 ++ ;
F_54 ( V_209 , & V_11 -> V_125 ) ;
F_105 ( V_11 ) ;
case V_211 :
if ( V_11 -> V_144 < V_212 )
V_11 -> V_144 = V_212 ;
break;
case V_213 :
F_36 ( V_135 , & V_11 -> V_125 ) ;
F_56 () ;
F_54 ( V_209 , & V_11 -> V_125 ) ;
F_57 () ;
break;
case V_139 :
if ( F_92 ( V_207 ,
& V_83 -> V_134 ) )
F_136 ( V_11 ) ;
F_58 ( V_11 ) ;
}
V_78:
F_64 ( & V_8 -> V_136 ) ;
}
static void F_138 ( struct V_7 * V_8 )
{
struct V_97 * V_98 ;
struct V_6 * V_11 ;
if ( ! V_8 -> V_140 )
return;
F_54 ( V_119 , & V_8 -> V_140 -> V_61 ) ;
if ( F_26 ( ! ( V_11 = F_3 ( V_8 ) ) ) )
return;
F_34 () ;
V_98 = F_35 ( V_8 -> V_99 ) ;
if ( ! V_98 || F_92 ( V_100 , & V_98 -> V_61 ) == 0 )
goto V_78;
F_139 ( V_11 ) ;
V_78:
F_37 () ;
}
static void F_140 ( struct V_7 * V_8 )
{
F_61 ( & V_8 -> V_136 ) ;
if ( F_41 ( V_8 ) )
F_138 ( V_8 ) ;
F_64 ( & V_8 -> V_136 ) ;
}
static void F_141 ( struct V_7 * V_8 )
{
F_61 ( & V_8 -> V_136 ) ;
if ( F_142 ( V_8 ) )
F_138 ( V_8 ) ;
F_64 ( & V_8 -> V_136 ) ;
}
static void F_143 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_7 * V_8 = V_83 -> V_86 ;
if ( V_83 -> V_214 ) {
V_8 -> V_215 |= V_216 ;
V_8 -> V_217 = V_83 -> V_214 * V_11 -> V_218 * 2 ;
}
if ( V_83 -> V_219 ) {
V_8 -> V_215 |= V_220 ;
V_8 -> V_221 = V_83 -> V_219 * V_11 -> V_218 * 2 ;
V_8 -> V_101 ( V_8 ) ;
}
}
static void F_144 ( struct V_6 * V_11 , T_4 V_219 , T_4 V_214 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
V_83 -> V_219 = 0 ;
if ( V_219 )
V_83 -> V_219 = V_219 + 1024 ;
V_83 -> V_214 = 0 ;
if ( V_214 )
V_83 -> V_214 = V_214 + 1024 ;
F_143 ( V_11 ) ;
}
static void F_145 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
F_97 ( V_11 , V_81 , - V_222 ) ;
}
static unsigned short F_146 ( void )
{
unsigned short V_223 = V_224 - V_225 + 1 ;
unsigned short rand = ( unsigned short ) F_147 () % V_223 ;
return rand + V_225 ;
}
static void F_148 ( struct V_39 * V_7 )
{
int V_226 = 1 ;
F_149 ( V_7 , V_227 , V_228 ,
( char * ) & V_226 , sizeof( V_226 ) ) ;
}
static unsigned short F_150 ( struct V_39 * V_7 )
{
struct V_229 V_4 ;
int V_161 ;
unsigned short V_230 = 0 ;
if ( F_151 ( V_7 , (struct V_10 * ) & V_4 , & V_161 ) < 0 )
goto V_78;
switch ( V_4 . V_231 ) {
case V_28 :
V_230 = F_152 ( ( (struct V_15 * ) & V_4 ) -> V_232 ) ;
break;
case V_25 :
V_230 = F_152 ( ( (struct V_14 * ) & V_4 ) -> V_233 ) ;
}
V_78:
return V_230 ;
}
static void F_153 ( struct V_6 * V_11 , unsigned short V_230 )
{
F_2 ( L_47 , V_11 , V_230 ) ;
F_154 ( F_4 ( V_11 ) , V_230 ) ;
F_17 ( V_11 ) ;
}
static void F_155 ( struct V_82 * V_83 , struct V_39 * V_7 )
{
if ( V_83 -> V_234 == 0 )
V_83 -> V_234 = F_150 ( V_7 ) ;
}
static unsigned short F_156 ( struct V_82 * V_83 )
{
unsigned short V_230 = V_83 -> V_234 ;
if ( V_230 == 0 && V_83 -> V_11 . V_235 )
V_230 = F_146 () ;
return V_230 ;
}
static unsigned short F_157 ( struct V_82 * V_83 , unsigned short V_230 )
{
if ( V_83 -> V_234 != 0 )
V_83 -> V_234 = 0 ;
if ( ! V_83 -> V_11 . V_235 )
return 0 ;
if ( V_230 <= V_225 || V_230 > V_224 )
return V_224 ;
return -- V_230 ;
}
static int F_158 ( struct V_82 * V_83 , struct V_39 * V_7 )
{
struct V_229 V_236 ;
int V_64 , V_237 = 0 ;
unsigned short V_230 = F_156 ( V_83 ) ;
unsigned short V_238 ;
if ( V_230 == 0 )
return 0 ;
memcpy ( & V_236 , & V_83 -> V_239 , V_83 -> V_11 . V_40 ) ;
do {
F_154 ( (struct V_10 * ) & V_236 , V_230 ) ;
V_64 = F_159 ( V_7 , (struct V_10 * ) & V_236 ,
V_83 -> V_11 . V_40 ) ;
if ( V_64 == 0 ) {
V_83 -> V_234 = V_230 ;
break;
}
V_238 = V_230 ;
V_230 = F_157 ( V_83 , V_230 ) ;
if ( V_230 > V_238 )
V_237 ++ ;
} while ( V_64 == - V_121 && V_237 != 2 );
if ( V_236 . V_231 == V_25 )
F_2 ( L_48 , V_108 ,
& ( (struct V_14 * ) & V_236 ) -> V_26 ,
V_230 , V_64 ? L_49 : L_50 , V_64 ) ;
else
F_2 ( L_51 , V_108 ,
& ( (struct V_15 * ) & V_236 ) -> V_29 ,
V_230 , V_64 ? L_49 : L_50 , V_64 ) ;
return V_64 ;
}
static void F_160 ( struct V_80 * V_81 )
{
F_161 ( V_81 -> V_240 ) ;
}
static void F_162 ( struct V_6 * V_11 , unsigned short V_230 )
{
}
static inline void F_163 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_164 ( V_8 , L_52 ,
& V_241 [ 1 ] , L_53 , & V_242 [ 1 ] ) ;
}
static inline void F_165 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_164 ( V_8 , L_54 ,
& V_241 [ 0 ] , L_55 , & V_242 [ 0 ] ) ;
}
static inline void F_166 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_164 ( V_8 , L_56 ,
& V_241 [ 1 ] , L_57 , & V_242 [ 1 ] ) ;
}
static inline void F_167 ( int V_243 , struct V_39 * V_7 )
{
if ( F_47 ( ! F_168 ( V_7 -> V_8 ) ) )
return;
switch ( V_243 ) {
case V_20 :
F_163 ( V_7 ) ;
break;
case V_25 :
F_165 ( V_7 ) ;
break;
case V_28 :
F_166 ( V_7 ) ;
break;
}
}
static inline void F_167 ( int V_243 , struct V_39 * V_7 )
{
}
static void F_169 ( struct V_162 * V_163 )
{
}
static struct V_39 * F_170 ( struct V_6 * V_11 ,
struct V_82 * V_83 , int V_243 , int type ,
int V_33 , bool V_244 )
{
struct V_39 * V_7 ;
int V_64 ;
V_64 = F_171 ( V_11 -> V_245 , V_243 , type , V_33 , & V_7 , 1 ) ;
if ( V_64 < 0 ) {
F_2 ( L_58 ,
V_33 , - V_64 ) ;
goto V_78;
}
F_167 ( V_243 , V_7 ) ;
if ( V_244 )
F_148 ( V_7 ) ;
V_64 = F_158 ( V_83 , V_7 ) ;
if ( V_64 ) {
F_75 ( V_7 ) ;
goto V_78;
}
return V_7 ;
V_78:
return F_172 ( V_64 ) ;
}
static int F_173 ( struct V_6 * V_11 ,
struct V_39 * V_7 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 ,
V_11 ) ;
if ( ! V_83 -> V_86 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
F_70 ( & V_8 -> V_136 ) ;
F_51 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_127 = F_102 ;
V_8 -> V_101 = F_140 ;
F_174 ( V_8 , V_246 ) ;
V_8 -> V_132 = F_60 ;
V_8 -> V_247 = V_248 ;
F_71 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_72 ( & V_8 -> V_136 ) ;
}
V_11 -> V_249 . V_250 ++ ;
V_11 -> V_249 . V_251 = V_252 ;
return F_175 ( V_7 , F_4 ( V_11 ) , V_11 -> V_40 , 0 ) ;
}
static int F_176 ( struct V_82 * V_83 )
{
struct V_6 * V_11 = & V_83 -> V_11 ;
struct V_39 * V_7 ;
int V_106 = - V_253 ;
V_106 = F_171 ( V_11 -> V_245 , V_20 ,
V_254 , 0 , & V_7 , 1 ) ;
if ( V_106 < 0 ) {
F_2 ( L_59
L_60 , - V_106 ) ;
goto V_78;
}
F_167 ( V_20 , V_7 ) ;
F_2 ( L_61 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
V_106 = F_173 ( V_11 , V_7 ) ;
F_177 ( V_11 , V_7 , V_106 ) ;
switch ( V_106 ) {
case 0 :
F_2 ( L_62 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
F_178 ( V_11 ) ;
case - V_109 :
break;
case - V_255 :
F_2 ( L_63 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
break;
case - V_115 :
F_2 ( L_64 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
break;
default:
F_115 ( V_256 L_65 ,
V_108 , - V_106 ,
V_11 -> V_22 [ V_23 ] ) ;
}
V_78:
F_136 ( V_11 ) ;
F_63 ( V_11 , V_106 ) ;
return V_106 ;
}
static void F_179 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
int V_90 ;
if ( F_180 ( V_81 ) ) {
F_181 ( V_81 , - V_96 ) ;
return;
}
V_90 = F_176 ( V_83 ) ;
if ( V_90 && ! F_182 ( V_81 ) )
F_183 ( 15000 ) ;
}
static void F_184 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 ,
V_11 ) ;
if ( ! V_83 -> V_86 )
return;
if ( F_66 ( & V_11 -> V_141 ) )
F_185 ( V_83 -> V_86 ) ;
}
static int
F_186 ( struct V_6 * V_11 )
{
struct V_82 * V_257 = F_28 ( V_11 , struct V_82 , V_11 ) ;
if ( F_187 ( & V_11 -> V_141 ) != 1 )
return 0 ;
if ( F_188 ( & V_11 -> V_125 , V_258 , V_259 ) )
return - V_260 ;
if ( V_257 -> V_86 )
F_185 ( V_257 -> V_86 ) ;
F_50 ( V_11 , NULL ) ;
return 0 ;
}
static void
F_189 ( struct V_6 * V_11 )
{
struct V_82 * V_257 = F_28 ( V_11 , struct V_82 , V_11 ) ;
if ( ! F_190 ( & V_11 -> V_141 ) )
return;
if ( F_188 ( & V_11 -> V_125 , V_258 , V_259 ) )
return;
if ( V_257 -> V_86 )
F_67 ( V_257 -> V_86 ) ;
F_50 ( V_11 , NULL ) ;
}
static void F_184 ( struct V_6 * V_11 )
{
}
static int
F_186 ( struct V_6 * V_11 )
{
return - V_261 ;
}
static void
F_189 ( struct V_6 * V_11 )
{
}
static void F_191 ( struct V_6 * V_11 , struct V_39 * V_7 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
if ( ! V_83 -> V_86 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
F_70 ( & V_8 -> V_136 ) ;
F_51 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_127 = F_102 ;
V_8 -> V_101 = F_140 ;
F_174 ( V_8 , V_246 ) ;
V_8 -> V_247 = V_248 ;
F_178 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_184 ( V_11 ) ;
F_72 ( & V_8 -> V_136 ) ;
}
F_143 ( V_11 ) ;
V_11 -> V_249 . V_251 = V_252 ;
}
static void F_192 ( struct V_162 * V_163 )
{
struct V_82 * V_83 =
F_28 ( V_163 , struct V_82 , V_145 . V_163 ) ;
struct V_6 * V_11 = & V_83 -> V_11 ;
struct V_39 * V_7 = V_83 -> V_7 ;
int V_106 = - V_253 ;
V_7 = F_170 ( V_11 , V_83 ,
F_4 ( V_11 ) -> V_19 , V_262 ,
V_263 , false ) ;
if ( F_193 ( V_7 ) )
goto V_78;
F_2 ( L_66
L_67 , V_11 ,
V_11 -> V_22 [ V_35 ] ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ) ;
F_191 ( V_11 , V_7 ) ;
F_177 ( V_11 , V_7 , 0 ) ;
V_106 = 0 ;
V_78:
F_194 ( V_11 , V_83 ) ;
F_136 ( V_11 ) ;
F_63 ( V_11 , V_106 ) ;
}
static void F_195 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
if ( V_7 == NULL )
return;
if ( F_31 ( V_11 ) ) {
F_68 ( V_7 , V_142 ) ;
F_196 ( V_11 , V_7 ) ;
} else
F_65 ( V_83 ) ;
}
static int F_197 ( struct V_6 * V_11 , struct V_39 * V_7 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
int V_90 = - V_96 ;
if ( ! V_83 -> V_86 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
unsigned int V_264 = V_11 -> V_265 -> V_266 / V_267 ;
unsigned int V_268 = V_11 -> V_265 -> V_269 + 1 ;
unsigned int V_270 = 1 ;
unsigned int V_271 ;
unsigned int V_272 = V_273 ;
F_149 ( V_7 , V_227 , V_274 ,
( char * ) & V_270 , sizeof( V_270 ) ) ;
F_149 ( V_7 , V_275 , V_276 ,
( char * ) & V_264 , sizeof( V_264 ) ) ;
F_149 ( V_7 , V_275 , V_277 ,
( char * ) & V_264 , sizeof( V_264 ) ) ;
F_149 ( V_7 , V_275 , V_278 ,
( char * ) & V_268 , sizeof( V_268 ) ) ;
F_149 ( V_7 , V_279 , V_280 ,
( char * ) & V_272 , sizeof( V_272 ) ) ;
V_271 = F_198 ( V_11 -> V_265 -> V_266 ) *
( V_11 -> V_265 -> V_269 + 1 ) ;
F_149 ( V_7 , V_275 , V_281 ,
( char * ) & V_271 , sizeof( V_271 ) ) ;
F_70 ( & V_8 -> V_136 ) ;
F_51 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_127 = F_102 ;
V_8 -> V_129 = F_131 ;
V_8 -> V_101 = F_141 ;
F_174 ( V_8 , V_246 ) ;
V_8 -> V_132 = F_60 ;
V_8 -> V_247 = V_248 ;
F_199 ( V_8 , V_282 ) ;
F_200 ( V_8 ) -> V_283 |= V_284 ;
F_71 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_72 ( & V_8 -> V_136 ) ;
}
if ( ! F_45 ( V_11 ) )
goto V_78;
F_184 ( V_11 ) ;
V_11 -> V_249 . V_250 ++ ;
V_11 -> V_249 . V_251 = V_252 ;
F_36 ( V_207 , & V_83 -> V_134 ) ;
V_90 = F_175 ( V_7 , F_4 ( V_11 ) , V_11 -> V_40 , V_285 ) ;
switch ( V_90 ) {
case 0 :
F_155 ( V_83 , V_7 ) ;
case - V_286 :
if ( V_11 -> V_144 < V_212 )
V_11 -> V_144 = V_212 ;
break;
case - V_287 :
V_83 -> V_234 = 0 ;
}
V_78:
return V_90 ;
}
static void F_201 ( struct V_162 * V_163 )
{
struct V_82 * V_83 =
F_28 ( V_163 , struct V_82 , V_145 . V_163 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
struct V_6 * V_11 = & V_83 -> V_11 ;
int V_106 = - V_253 ;
if ( ! V_7 ) {
V_7 = F_170 ( V_11 , V_83 ,
F_4 ( V_11 ) -> V_19 , V_254 ,
V_288 , true ) ;
if ( F_193 ( V_7 ) ) {
V_106 = F_202 ( V_7 ) ;
goto V_78;
}
}
F_2 ( L_66
L_67 , V_11 ,
V_11 -> V_22 [ V_35 ] ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ) ;
V_106 = F_197 ( V_11 , V_7 ) ;
F_177 ( V_11 , V_7 , V_106 ) ;
F_2 ( L_68 ,
V_11 , - V_106 , F_31 ( V_11 ) ,
V_7 -> V_8 -> V_138 ) ;
switch ( V_106 ) {
default:
F_115 ( L_69 ,
V_108 , V_106 ) ;
case - V_287 :
F_105 ( V_11 ) ;
break;
case 0 :
case - V_286 :
case - V_289 :
F_194 ( V_11 , V_83 ) ;
return;
case - V_261 :
case - V_115 :
case - V_120 :
case - V_114 :
case - V_121 :
case - V_109 :
F_105 ( V_11 ) ;
goto V_78;
}
V_106 = - V_91 ;
V_78:
F_194 ( V_11 , V_83 ) ;
F_136 ( V_11 ) ;
F_63 ( V_11 , V_106 ) ;
}
static unsigned long F_203 ( const struct V_6 * V_11 )
{
unsigned long V_290 , V_291 = V_252 ;
V_290 = V_11 -> V_249 . V_251 + V_11 -> V_144 ;
if ( F_204 ( V_290 , V_291 ) )
return V_290 - V_291 ;
return 0 ;
}
static void F_205 ( struct V_6 * V_11 )
{
V_11 -> V_144 <<= 1 ;
if ( V_11 -> V_144 > V_11 -> V_292 )
V_11 -> V_144 = V_11 -> V_292 ;
if ( V_11 -> V_144 < V_212 )
V_11 -> V_144 = V_212 ;
}
static void F_206 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
unsigned long V_293 = 0 ;
F_47 ( ! F_207 ( V_11 , V_81 , V_83 ) ) ;
if ( V_83 -> V_7 != NULL ) {
F_2 ( L_70
L_71 ,
V_11 , V_11 -> V_144 / V_267 ) ;
F_65 ( V_83 ) ;
V_293 = F_203 ( V_11 ) ;
F_205 ( V_11 ) ;
} else
F_2 ( L_72 , V_11 ) ;
F_208 ( V_166 ,
& V_83 -> V_145 ,
V_293 ) ;
}
static void F_209 ( struct V_6 * V_11 , struct V_294 * V_295 )
{
long V_296 = 0 ;
if ( F_31 ( V_11 ) )
V_296 = ( long ) ( V_252 - V_11 -> V_297 ) / V_267 ;
F_210 ( V_295 , L_73
L_74 ,
V_11 -> V_249 . V_298 ,
V_11 -> V_249 . V_250 ,
V_11 -> V_249 . V_299 ,
V_296 ,
V_11 -> V_249 . V_300 ,
V_11 -> V_249 . V_301 ,
V_11 -> V_249 . V_302 ,
V_11 -> V_249 . V_303 ,
V_11 -> V_249 . V_304 ,
V_11 -> V_249 . V_305 ,
V_11 -> V_249 . V_306 ,
V_11 -> V_249 . V_307 ) ;
}
static void F_211 ( struct V_6 * V_11 , struct V_294 * V_295 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
F_210 ( V_295 , L_75
L_76 ,
V_83 -> V_234 ,
V_11 -> V_249 . V_298 ,
V_11 -> V_249 . V_300 ,
V_11 -> V_249 . V_301 ,
V_11 -> V_249 . V_302 ,
V_11 -> V_249 . V_303 ,
V_11 -> V_249 . V_304 ,
V_11 -> V_249 . V_305 ,
V_11 -> V_249 . V_306 ,
V_11 -> V_249 . V_307 ) ;
}
static void F_212 ( struct V_6 * V_11 , struct V_294 * V_295 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
long V_296 = 0 ;
if ( F_31 ( V_11 ) )
V_296 = ( long ) ( V_252 - V_11 -> V_297 ) / V_267 ;
F_210 ( V_295 , L_77
L_74 ,
V_83 -> V_234 ,
V_11 -> V_249 . V_298 ,
V_11 -> V_249 . V_250 ,
V_11 -> V_249 . V_299 ,
V_296 ,
V_11 -> V_249 . V_300 ,
V_11 -> V_249 . V_301 ,
V_11 -> V_249 . V_302 ,
V_11 -> V_249 . V_303 ,
V_11 -> V_249 . V_304 ,
V_11 -> V_249 . V_305 ,
V_11 -> V_249 . V_306 ,
V_11 -> V_249 . V_307 ) ;
}
static int F_213 ( struct V_80 * V_81 )
{
struct V_88 * V_308 = V_81 -> V_84 ;
T_4 V_60 = V_308 -> V_309 ;
struct V_58 * V_58 ;
struct V_310 * V_4 ;
if ( V_60 > V_196 - sizeof( struct V_310 ) ) {
F_214 ( 1 , L_78 ,
V_60 ) ;
return - V_261 ;
}
V_58 = F_215 ( V_24 ) ;
if ( ! V_58 )
return - V_311 ;
V_4 = F_216 ( V_58 ) ;
V_4 -> V_73 = V_196 ;
V_308 -> V_312 = V_4 -> V_199 ;
V_308 -> V_313 = ( char * ) V_308 -> V_312 + V_308 -> V_309 ;
return 0 ;
}
static void F_217 ( struct V_80 * V_81 )
{
void * V_314 = V_81 -> V_84 -> V_312 ;
struct V_310 * V_4 ;
V_4 = F_28 ( V_314 , struct V_310 , V_199 ) ;
F_218 ( ( unsigned long ) V_4 ) ;
}
static int F_219 ( struct V_88 * V_89 )
{
int V_73 ;
struct V_54 * V_315 = & V_89 -> V_105 ;
struct V_6 * V_11 = V_89 -> V_85 ;
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
unsigned long V_316 ;
unsigned long V_317 ;
F_38 ( V_315 ) ;
V_317 = ( unsigned long ) V_315 -> V_79 [ 0 ] . V_52 & ~ V_69 ;
V_316 = ( unsigned long ) V_315 -> V_77 [ 0 ] . V_52 & ~ V_69 ;
V_73 = F_220 ( V_7 , V_315 ,
F_221 ( V_315 -> V_77 [ 0 ] . V_52 ) , V_316 ,
V_315 -> V_79 [ 0 ] . V_52 , V_317 ) ;
if ( V_73 != V_315 -> V_73 ) {
F_115 ( V_318 L_79 ) ;
V_73 = - V_91 ;
}
return V_73 ;
}
static int F_222 ( struct V_80 * V_81 )
{
struct V_88 * V_89 = V_81 -> V_84 ;
struct V_319 * V_11 ;
int V_73 ;
F_2 ( L_80 , F_12 ( V_89 -> V_190 ) ) ;
V_11 = V_89 -> V_85 -> V_320 ;
if ( ! F_223 ( & V_11 -> V_321 ) ) {
F_224 ( & V_11 -> V_322 , V_81 , NULL ) ;
if ( ! F_223 ( & V_11 -> V_321 ) )
return - V_91 ;
F_225 ( & V_11 -> V_322 , V_81 ) ;
}
if ( F_48 ( V_323 , & V_11 -> V_324 ) )
V_73 = - V_96 ;
else
V_73 = F_219 ( V_89 ) ;
F_73 ( & V_11 -> V_321 ) ;
if ( V_73 > 0 )
V_73 = 0 ;
return V_73 ;
}
static void F_226 ( struct V_6 * V_11 )
{
}
static void F_227 ( struct V_6 * V_11 )
{
F_2 ( L_81 , V_11 ) ;
F_77 ( V_11 ) ;
F_82 ( V_147 ) ;
}
static int F_228 ( const int V_243 , struct V_10 * V_16 )
{
static const struct V_14 sin = {
. V_325 = V_25 ,
. V_26 . V_27 = F_229 ( V_326 ) ,
} ;
static const struct V_15 V_17 = {
. V_327 = V_28 ,
. V_29 = V_328 ,
} ;
switch ( V_243 ) {
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
return - V_329 ;
}
return 0 ;
}
static struct V_6 * F_230 ( struct V_330 * args ,
unsigned int V_331 ,
unsigned int V_332 )
{
struct V_6 * V_11 ;
struct V_82 * V_333 ;
if ( args -> V_40 > sizeof( V_11 -> V_12 ) ) {
F_2 ( L_83 ) ;
return F_172 ( - V_334 ) ;
}
V_11 = F_231 ( args -> V_193 , sizeof( * V_333 ) , V_331 ,
V_332 ) ;
if ( V_11 == NULL ) {
F_2 ( L_84
L_85 ) ;
return F_172 ( - V_311 ) ;
}
V_333 = F_28 ( V_11 , struct V_82 , V_11 ) ;
F_232 ( & V_333 -> V_143 ) ;
memcpy ( & V_11 -> V_12 , args -> V_335 , args -> V_40 ) ;
V_11 -> V_40 = args -> V_40 ;
if ( args -> V_239 )
memcpy ( & V_333 -> V_239 , args -> V_239 , args -> V_40 ) ;
else {
int V_64 ;
V_64 = F_228 ( args -> V_335 -> V_19 ,
(struct V_10 * ) & V_333 -> V_239 ) ;
if ( V_64 != 0 ) {
F_78 ( V_11 ) ;
return F_172 ( V_64 ) ;
}
}
return V_11 ;
}
static struct V_6 * F_233 ( struct V_330 * args )
{
struct V_13 * V_18 = (struct V_13 * ) args -> V_335 ;
struct V_82 * V_83 ;
struct V_6 * V_11 ;
struct V_6 * V_90 ;
V_11 = F_230 ( args , V_336 ,
V_337 ) ;
if ( F_193 ( V_11 ) )
return V_11 ;
V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_338 = 0 ;
V_11 -> V_339 = sizeof( V_103 ) / sizeof( T_1 ) ;
V_11 -> V_340 = V_341 ;
V_11 -> V_342 = V_343 ;
V_11 -> V_144 = V_212 ;
V_11 -> V_344 = V_345 ;
V_11 -> V_70 = & V_346 ;
V_11 -> V_265 = & V_347 ;
F_234 ( & V_83 -> V_146 , F_93 ) ;
F_235 ( & V_83 -> V_145 ,
F_169 ) ;
switch ( V_18 -> V_348 ) {
case V_20 :
if ( V_18 -> V_21 [ 0 ] != '/' ) {
F_2 ( L_86 ,
V_18 -> V_21 ) ;
V_90 = F_172 ( - V_261 ) ;
goto V_349;
}
F_161 ( V_11 ) ;
F_16 ( V_11 , L_87 , V_350 ) ;
V_90 = F_172 ( F_176 ( V_83 ) ) ;
if ( V_90 )
goto V_349;
break;
default:
V_90 = F_172 ( - V_329 ) ;
goto V_349;
}
F_2 ( L_88 ,
V_11 -> V_22 [ V_23 ] ) ;
if ( F_236 ( V_147 ) )
return V_11 ;
V_90 = F_172 ( - V_261 ) ;
V_349:
F_77 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_237 ( struct V_330 * args )
{
struct V_10 * V_12 = args -> V_335 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_6 * V_90 ;
V_11 = F_230 ( args , V_351 ,
V_351 ) ;
if ( F_193 ( V_11 ) )
return V_11 ;
V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_338 = V_263 ;
V_11 -> V_339 = 0 ;
V_11 -> V_340 = ( 1U << 16 ) - ( V_352 << 3 ) ;
V_11 -> V_342 = V_343 ;
V_11 -> V_144 = V_353 ;
V_11 -> V_344 = V_345 ;
V_11 -> V_70 = & V_354 ;
V_11 -> V_265 = & V_355 ;
F_234 ( & V_83 -> V_146 , F_101 ) ;
F_235 ( & V_83 -> V_145 , F_192 ) ;
switch ( V_12 -> V_19 ) {
case V_25 :
if ( ( (struct V_14 * ) V_12 ) -> V_233 != F_238 ( 0 ) )
F_161 ( V_11 ) ;
F_16 ( V_11 , L_89 , V_356 ) ;
break;
case V_28 :
if ( ( (struct V_15 * ) V_12 ) -> V_232 != F_238 ( 0 ) )
F_161 ( V_11 ) ;
F_16 ( V_11 , L_89 , V_357 ) ;
break;
default:
V_90 = F_172 ( - V_329 ) ;
goto V_349;
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
if ( F_236 ( V_147 ) )
return V_11 ;
V_90 = F_172 ( - V_261 ) ;
V_349:
F_77 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_239 ( struct V_330 * args )
{
struct V_10 * V_12 = args -> V_335 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_6 * V_90 ;
unsigned int V_332 = V_337 ;
if ( args -> V_61 & V_358 )
V_332 = V_359 ;
V_11 = F_230 ( args , V_336 ,
V_332 ) ;
if ( F_193 ( V_11 ) )
return V_11 ;
V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_338 = V_288 ;
V_11 -> V_339 = sizeof( V_103 ) / sizeof( T_1 ) ;
V_11 -> V_340 = V_341 ;
V_11 -> V_342 = V_343 ;
V_11 -> V_144 = V_212 ;
V_11 -> V_344 = V_345 ;
V_11 -> V_70 = & V_360 ;
V_11 -> V_265 = & V_361 ;
V_11 -> V_292 = V_11 -> V_265 -> V_362 ;
F_234 ( & V_83 -> V_146 , F_130 ) ;
F_235 ( & V_83 -> V_145 , F_201 ) ;
switch ( V_12 -> V_19 ) {
case V_25 :
if ( ( (struct V_14 * ) V_12 ) -> V_233 != F_238 ( 0 ) )
F_161 ( V_11 ) ;
F_16 ( V_11 , L_92 , V_363 ) ;
break;
case V_28 :
if ( ( (struct V_15 * ) V_12 ) -> V_232 != F_238 ( 0 ) )
F_161 ( V_11 ) ;
F_16 ( V_11 , L_92 , V_364 ) ;
break;
default:
V_90 = F_172 ( - V_329 ) ;
goto V_349;
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
if ( F_236 ( V_147 ) )
return V_11 ;
V_90 = F_172 ( - V_261 ) ;
V_349:
F_77 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_240 ( struct V_330 * args )
{
struct V_10 * V_12 = args -> V_335 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_365 * V_366 ;
struct V_6 * V_90 ;
V_11 = F_230 ( args , V_336 ,
V_336 ) ;
if ( F_193 ( V_11 ) )
return V_11 ;
V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_338 = V_288 ;
V_11 -> V_339 = sizeof( V_103 ) / sizeof( T_1 ) ;
V_11 -> V_340 = V_341 ;
V_11 -> V_265 = & V_361 ;
F_161 ( V_11 ) ;
V_11 -> V_342 = 0 ;
V_11 -> V_144 = 0 ;
V_11 -> V_344 = 0 ;
V_11 -> V_70 = & V_367 ;
switch ( V_12 -> V_19 ) {
case V_25 :
F_16 ( V_11 , L_92 ,
V_363 ) ;
break;
case V_28 :
F_16 ( V_11 , L_92 ,
V_364 ) ;
break;
default:
V_90 = F_172 ( - V_329 ) ;
goto V_349;
}
F_2 ( L_90 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
F_241 ( V_11 ) ;
args -> V_320 -> V_368 = V_11 ;
V_11 -> V_320 = args -> V_320 ;
V_366 = F_28 ( args -> V_320 , struct V_365 , V_369 ) ;
V_83 -> V_7 = V_366 -> V_370 ;
V_83 -> V_86 = V_366 -> V_371 ;
F_178 ( V_11 ) ;
if ( F_236 ( V_147 ) )
return V_11 ;
args -> V_320 -> V_368 = NULL ;
args -> V_320 -> V_372 = NULL ;
F_242 ( V_11 ) ;
V_90 = F_172 ( - V_261 ) ;
V_349:
F_77 ( V_11 ) ;
return V_90 ;
}
int F_243 ( void )
{
#if F_244 ( V_373 )
if ( ! V_374 )
V_374 = F_245 ( V_375 ) ;
#endif
F_246 ( & V_376 ) ;
F_246 ( & V_377 ) ;
F_246 ( & V_378 ) ;
F_246 ( & V_379 ) ;
return 0 ;
}
void F_247 ( void )
{
#if F_244 ( V_373 )
if ( V_374 ) {
F_248 ( V_374 ) ;
V_374 = NULL ;
}
#endif
F_249 ( & V_376 ) ;
F_249 ( & V_377 ) ;
F_249 ( & V_378 ) ;
F_249 ( & V_379 ) ;
}
static int F_250 ( const char * V_380 ,
const struct V_381 * V_382 ,
unsigned int V_383 , unsigned int V_384 )
{
unsigned int V_385 ;
int V_90 ;
if ( ! V_380 )
return - V_261 ;
V_90 = F_251 ( V_380 , 0 , & V_385 ) ;
if ( V_90 == - V_261 || V_385 < V_383 || V_385 > V_384 )
return - V_261 ;
* ( ( unsigned int * ) V_382 -> V_198 ) = V_385 ;
return 0 ;
}
static int F_252 ( const char * V_380 , const struct V_381 * V_382 )
{
if ( V_382 -> V_198 == & V_225 )
return F_250 ( V_380 , V_382 ,
V_386 ,
V_224 ) ;
return F_250 ( V_380 , V_382 ,
V_225 ,
V_387 ) ;
}
static int F_253 ( const char * V_380 ,
const struct V_381 * V_382 )
{
return F_250 ( V_380 , V_382 ,
V_388 ,
V_389 ) ;
}
static int F_254 ( const char * V_380 ,
const struct V_381 * V_382 )
{
return F_250 ( V_380 , V_382 ,
V_388 ,
V_359 ) ;
}

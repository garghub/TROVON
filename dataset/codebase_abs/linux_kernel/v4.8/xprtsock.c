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
V_8 -> V_97 ( V_8 ) ;
return V_90 ;
}
static inline void F_34 ( struct V_54 * V_4 )
{
T_1 V_98 = V_4 -> V_73 - sizeof( V_99 ) ;
V_99 * V_43 = V_4 -> V_77 [ 0 ] . V_52 ;
* V_43 = F_35 ( V_100 | V_98 ) ;
}
static int F_36 ( struct V_80 * V_81 )
{
struct V_88 * V_89 = V_81 -> V_84 ;
struct V_6 * V_11 = V_89 -> V_85 ;
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_54 * V_55 = & V_89 -> V_101 ;
int V_102 ;
int V_75 = 0 ;
F_34 ( & V_89 -> V_101 ) ;
F_1 ( L_10 ,
V_89 -> V_103 -> V_52 , V_89 -> V_103 -> V_53 ) ;
V_102 = F_25 ( V_83 -> V_7 , NULL , 0 , V_55 , V_89 -> V_94 ,
true , & V_75 ) ;
F_2 ( L_11 ,
V_104 , V_55 -> V_73 - V_89 -> V_94 , V_102 ) ;
if ( V_102 == - V_91 && F_37 ( V_83 -> V_86 ) )
V_102 = - V_105 ;
if ( F_38 ( V_75 > 0 ) || V_102 == 0 ) {
V_89 -> V_94 += V_75 ;
V_89 -> V_106 += V_75 ;
if ( F_38 ( V_89 -> V_94 >= V_89 -> V_93 ) ) {
V_89 -> V_94 = 0 ;
return 0 ;
}
V_102 = - V_91 ;
}
switch ( V_102 ) {
case - V_105 :
break;
case - V_91 :
V_102 = F_29 ( V_81 ) ;
break;
default:
F_2 ( L_12 ,
- V_102 ) ;
case - V_107 :
F_39 ( V_11 ) ;
V_102 = - V_96 ;
}
return V_102 ;
}
static int F_40 ( struct V_80 * V_81 )
{
struct V_88 * V_89 = V_81 -> V_84 ;
struct V_6 * V_11 = V_89 -> V_85 ;
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_54 * V_55 = & V_89 -> V_101 ;
int V_75 = 0 ;
int V_102 ;
F_1 ( L_10 ,
V_89 -> V_103 -> V_52 ,
V_89 -> V_103 -> V_53 ) ;
if ( ! F_41 ( V_11 ) )
return - V_96 ;
V_102 = F_25 ( V_83 -> V_7 , F_4 ( V_11 ) , V_11 -> V_40 ,
V_55 , V_89 -> V_94 , true , & V_75 ) ;
F_2 ( L_13 ,
V_55 -> V_73 - V_89 -> V_94 , V_102 ) ;
if ( V_102 == - V_108 )
goto V_109;
if ( V_102 == - V_91 && F_37 ( V_83 -> V_86 ) )
V_102 = - V_105 ;
if ( V_75 > 0 || V_102 == 0 ) {
V_89 -> V_106 += V_75 ;
if ( V_75 >= V_89 -> V_93 )
return 0 ;
V_102 = - V_91 ;
}
V_109:
switch ( V_102 ) {
case - V_76 :
V_102 = - V_96 ;
break;
case - V_91 :
V_102 = F_29 ( V_81 ) ;
break;
case - V_110 :
case - V_105 :
case - V_107 :
case - V_111 :
case - V_108 :
break;
default:
F_2 ( L_12 ,
- V_102 ) ;
}
return V_102 ;
}
static int F_42 ( struct V_80 * V_81 )
{
struct V_88 * V_89 = V_81 -> V_84 ;
struct V_6 * V_11 = V_89 -> V_85 ;
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_54 * V_55 = & V_89 -> V_101 ;
bool V_56 = true ;
bool V_112 = false ;
int V_102 ;
int V_75 ;
F_34 ( & V_89 -> V_101 ) ;
F_1 ( L_10 ,
V_89 -> V_103 -> V_52 ,
V_89 -> V_103 -> V_53 ) ;
if ( V_81 -> V_113 & V_114 )
V_56 = false ;
while ( 1 ) {
V_75 = 0 ;
V_102 = F_25 ( V_83 -> V_7 , NULL , 0 , V_55 ,
V_89 -> V_94 , V_56 , & V_75 ) ;
F_2 ( L_14 ,
V_55 -> V_73 - V_89 -> V_94 , V_102 ) ;
V_89 -> V_94 += V_75 ;
V_89 -> V_106 += V_75 ;
if ( F_38 ( V_89 -> V_94 >= V_89 -> V_93 ) ) {
V_89 -> V_94 = 0 ;
return 0 ;
}
F_43 ( V_75 == 0 && V_102 == 0 ) ;
if ( V_102 == - V_91 ) {
if ( F_44 ( V_115 , & V_83 -> V_7 -> V_61 ) )
break;
if ( V_75 == 0 ) {
V_102 = - V_105 ;
if ( V_112 )
break;
V_112 = true ;
}
continue;
}
if ( V_102 < 0 )
break;
V_112 = false ;
}
switch ( V_102 ) {
case - V_76 :
V_102 = - V_96 ;
break;
case - V_91 :
V_102 = F_29 ( V_81 ) ;
break;
case - V_116 :
case - V_111 :
case - V_96 :
case - V_117 :
case - V_105 :
case - V_107 :
break;
default:
F_2 ( L_12 ,
- V_102 ) ;
}
return V_102 ;
}
static void F_45 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
struct V_88 * V_89 ;
if ( V_81 != V_11 -> V_118 )
return;
if ( V_81 == NULL )
goto V_119;
V_89 = V_81 -> V_84 ;
if ( V_89 == NULL )
goto V_119;
if ( V_89 -> V_94 == 0 )
goto V_119;
if ( V_89 -> V_94 == V_89 -> V_101 . V_73 )
goto V_119;
F_46 ( V_120 , & V_11 -> V_121 ) ;
V_119:
F_47 ( V_11 , V_81 ) ;
}
static void F_48 ( struct V_82 * V_83 , struct V_7 * V_8 )
{
V_83 -> V_122 = V_8 -> V_123 ;
V_83 -> V_124 = V_8 -> V_125 ;
V_83 -> V_126 = V_8 -> V_97 ;
V_83 -> V_127 = V_8 -> V_128 ;
}
static void F_49 ( struct V_82 * V_83 , struct V_7 * V_8 )
{
V_8 -> V_123 = V_83 -> V_122 ;
V_8 -> V_125 = V_83 -> V_124 ;
V_8 -> V_97 = V_83 -> V_126 ;
V_8 -> V_128 = V_83 -> V_127 ;
}
static void F_50 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
F_51 ( V_129 , & V_83 -> V_130 ) ;
}
static void F_52 ( struct V_6 * V_11 )
{
F_53 () ;
F_51 ( V_120 , & V_11 -> V_121 ) ;
F_51 ( V_131 , & V_11 -> V_121 ) ;
F_50 ( V_11 ) ;
F_54 () ;
}
static void F_55 ( struct V_6 * V_11 )
{
F_52 ( V_11 ) ;
F_56 ( V_11 ) ;
}
static void F_57 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
int V_64 ;
F_58 ( & V_8 -> V_132 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_78;
V_64 = - V_8 -> V_133 ;
if ( V_64 == 0 )
goto V_78;
if ( V_8 -> V_134 == V_135 )
F_55 ( V_11 ) ;
F_2 ( L_15 ,
V_11 , - V_64 ) ;
F_59 ( V_11 , V_8 -> V_136 , V_64 ) ;
F_60 ( V_11 , V_64 ) ;
V_78:
F_61 ( & V_8 -> V_132 ) ;
}
static void F_62 ( struct V_82 * V_83 )
{
struct V_39 * V_7 = V_83 -> V_7 ;
struct V_7 * V_8 = V_83 -> V_86 ;
struct V_6 * V_11 = & V_83 -> V_11 ;
if ( V_8 == NULL )
return;
if ( F_63 ( & V_83 -> V_11 . V_137 ) )
F_64 ( V_8 ) ;
F_65 ( V_7 , V_138 ) ;
F_66 ( & V_83 -> V_139 ) ;
F_67 ( & V_8 -> V_132 ) ;
V_83 -> V_86 = NULL ;
V_83 -> V_7 = NULL ;
V_8 -> V_9 = NULL ;
F_49 ( V_83 , V_8 ) ;
F_68 ( V_11 ) ;
F_69 ( & V_8 -> V_132 ) ;
F_52 ( V_11 ) ;
F_70 ( & V_83 -> V_139 ) ;
F_71 ( V_11 , V_7 ) ;
F_72 ( V_7 ) ;
}
static void F_39 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
F_2 ( L_16 , V_11 ) ;
F_62 ( V_83 ) ;
V_11 -> V_140 = 0 ;
F_56 ( V_11 ) ;
}
static void F_73 ( struct V_6 * V_11 )
{
F_2 ( L_17 ,
V_11 ) ;
F_56 ( V_11 ) ;
}
static void F_74 ( struct V_6 * V_11 )
{
F_19 ( V_11 ) ;
F_75 ( V_11 ) ;
}
static void F_76 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_28 ( V_11 ,
struct V_82 , V_11 ) ;
F_2 ( L_18 , V_11 ) ;
F_77 ( & V_83 -> V_141 ) ;
F_39 ( V_11 ) ;
F_78 ( & V_83 -> V_142 ) ;
F_74 ( V_11 ) ;
F_79 ( V_143 ) ;
}
static int F_80 ( struct V_54 * V_55 , struct V_144 * V_145 )
{
struct V_146 V_147 = {
. V_145 = V_145 ,
. V_59 = sizeof( V_99 ) ,
. V_3 = V_145 -> V_73 - sizeof( V_99 ) ,
} ;
if ( F_81 ( V_55 , 0 , & V_147 , V_148 ) < 0 )
return - 1 ;
if ( V_147 . V_3 )
return - 1 ;
return 0 ;
}
static void F_82 ( struct V_6 * V_11 ,
struct V_7 * V_8 ,
struct V_144 * V_145 )
{
struct V_80 * V_81 ;
struct V_88 * V_149 ;
int V_150 , V_151 ;
T_1 V_152 ;
T_5 * V_153 ;
V_150 = V_145 -> V_73 - sizeof( V_99 ) ;
if ( V_150 < 4 ) {
F_2 ( L_19 , V_150 ) ;
return;
}
V_153 = F_83 ( V_145 , sizeof( V_99 ) , sizeof( V_152 ) , & V_152 ) ;
if ( V_153 == NULL )
return;
F_30 ( & V_11 -> V_95 ) ;
V_149 = F_84 ( V_11 , * V_153 ) ;
if ( ! V_149 )
goto V_154;
V_81 = V_149 -> V_155 ;
V_151 = V_149 -> V_156 . V_157 ;
if ( V_151 > V_150 )
V_151 = V_150 ;
if ( F_80 ( & V_149 -> V_156 , V_145 ) ) {
F_2 ( L_20 ) ;
goto V_154;
}
F_85 ( V_81 , V_151 ) ;
V_154:
F_33 ( & V_11 -> V_95 ) ;
}
static void F_86 ( struct V_82 * V_83 )
{
struct V_144 * V_145 ;
struct V_7 * V_8 ;
int V_64 ;
F_66 ( & V_83 -> V_139 ) ;
V_8 = V_83 -> V_86 ;
if ( V_8 == NULL )
goto V_78;
for (; ; ) {
V_145 = F_87 ( V_8 , 0 , 1 , & V_64 ) ;
if ( V_145 != NULL ) {
F_82 ( & V_83 -> V_11 , V_8 , V_145 ) ;
F_88 ( V_8 , V_145 ) ;
continue;
}
if ( ! F_89 ( V_129 , & V_83 -> V_130 ) )
break;
}
V_78:
F_70 ( & V_83 -> V_139 ) ;
}
static void F_90 ( struct V_158 * V_159 )
{
struct V_82 * V_83 =
F_28 ( V_159 , struct V_82 , V_142 ) ;
F_86 ( V_83 ) ;
}
static void F_91 ( struct V_6 * V_11 ,
struct V_7 * V_8 ,
struct V_144 * V_145 )
{
struct V_80 * V_81 ;
struct V_88 * V_149 ;
int V_150 , V_151 ;
T_1 V_152 ;
T_5 * V_153 ;
V_150 = V_145 -> V_73 ;
if ( V_150 < 4 ) {
F_2 ( L_21 , V_150 ) ;
return;
}
V_153 = F_83 ( V_145 , 0 , sizeof( V_152 ) , & V_152 ) ;
if ( V_153 == NULL )
return;
F_30 ( & V_11 -> V_95 ) ;
V_149 = F_84 ( V_11 , * V_153 ) ;
if ( ! V_149 )
goto V_154;
V_81 = V_149 -> V_155 ;
if ( ( V_151 = V_149 -> V_156 . V_157 ) > V_150 )
V_151 = V_150 ;
if ( F_92 ( & V_149 -> V_156 , V_145 ) ) {
F_93 ( V_8 , V_160 ) ;
goto V_154;
}
F_93 ( V_8 , V_161 ) ;
F_94 ( V_11 , V_81 , V_151 ) ;
F_85 ( V_81 , V_151 ) ;
V_154:
F_33 ( & V_11 -> V_95 ) ;
}
static void F_95 ( struct V_82 * V_83 )
{
struct V_144 * V_145 ;
struct V_7 * V_8 ;
int V_64 ;
F_66 ( & V_83 -> V_139 ) ;
V_8 = V_83 -> V_86 ;
if ( V_8 == NULL )
goto V_78;
for (; ; ) {
V_145 = F_87 ( V_8 , 0 , 1 , & V_64 ) ;
if ( V_145 != NULL ) {
F_91 ( & V_83 -> V_11 , V_8 , V_145 ) ;
F_96 ( V_8 , V_145 ) ;
continue;
}
if ( ! F_89 ( V_129 , & V_83 -> V_130 ) )
break;
}
V_78:
F_70 ( & V_83 -> V_139 ) ;
}
static void F_97 ( struct V_158 * V_159 )
{
struct V_82 * V_83 =
F_28 ( V_159 , struct V_82 , V_142 ) ;
F_95 ( V_83 ) ;
}
static void F_98 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
F_58 ( & V_8 -> V_132 ) ;
F_2 ( L_22 ) ;
V_11 = F_3 ( V_8 ) ;
if ( V_11 != NULL ) {
struct V_82 * V_83 = F_28 ( V_11 ,
struct V_82 , V_11 ) ;
V_83 -> V_122 ( V_8 ) ;
if ( V_11 -> V_140 )
V_11 -> V_140 = 0 ;
if ( ! F_99 ( V_129 , & V_83 -> V_130 ) )
F_100 ( V_162 , & V_83 -> V_142 ) ;
}
F_61 ( & V_8 -> V_132 ) ;
}
static void F_101 ( struct V_6 * V_11 )
{
F_102 ( V_11 ) ;
}
static inline void F_103 ( struct V_6 * V_11 , struct V_146 * V_147 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
T_4 V_73 , V_163 ;
char * V_164 ;
V_164 = ( ( char * ) & V_83 -> V_165 ) + V_83 -> V_166 ;
V_73 = sizeof( V_83 -> V_165 ) - V_83 -> V_166 ;
V_163 = V_148 ( V_147 , V_164 , V_73 ) ;
V_83 -> V_166 += V_163 ;
if ( V_163 != V_73 )
return;
V_83 -> V_167 = F_12 ( V_83 -> V_165 ) ;
if ( V_83 -> V_167 & V_100 )
V_83 -> V_168 |= V_169 ;
else
V_83 -> V_168 &= ~ V_169 ;
V_83 -> V_167 &= V_170 ;
V_83 -> V_168 &= ~ V_171 ;
V_83 -> V_166 = 0 ;
if ( F_26 ( V_83 -> V_167 < 8 ) ) {
F_2 ( L_23 ) ;
F_101 ( V_11 ) ;
return;
}
F_2 ( L_24 ,
V_83 -> V_167 ) ;
}
static void F_104 ( struct V_82 * V_83 )
{
if ( V_83 -> V_166 == V_83 -> V_167 ) {
V_83 -> V_168 |= V_171 ;
V_83 -> V_166 = 0 ;
if ( V_83 -> V_168 & V_169 ) {
V_83 -> V_168 &= ~ V_172 ;
V_83 -> V_168 |= V_173 ;
V_83 -> V_174 = 0 ;
}
}
}
static inline void F_105 ( struct V_82 * V_83 , struct V_146 * V_147 )
{
T_4 V_73 , V_163 ;
char * V_164 ;
V_73 = sizeof( V_83 -> V_175 ) - V_83 -> V_166 ;
F_2 ( L_25 , V_73 ) ;
V_164 = ( ( char * ) & V_83 -> V_175 ) + V_83 -> V_166 ;
V_163 = V_148 ( V_147 , V_164 , V_73 ) ;
V_83 -> V_166 += V_163 ;
if ( V_163 != V_73 )
return;
V_83 -> V_168 &= ~ V_173 ;
V_83 -> V_168 |= V_176 ;
V_83 -> V_174 = 4 ;
F_2 ( L_26 ,
( V_83 -> V_168 & V_177 ) ? L_27
: L_28 ,
F_12 ( V_83 -> V_175 ) ) ;
F_104 ( V_83 ) ;
}
static inline void F_106 ( struct V_82 * V_83 ,
struct V_146 * V_147 )
{
T_4 V_73 , V_163 ;
T_1 V_59 ;
char * V_164 ;
V_59 = V_83 -> V_166 - sizeof( V_83 -> V_175 ) ;
V_73 = sizeof( V_83 -> V_178 ) - V_59 ;
F_2 ( L_29 , V_73 ) ;
V_164 = ( ( char * ) & V_83 -> V_178 ) + V_59 ;
V_163 = V_148 ( V_147 , V_164 , V_73 ) ;
V_83 -> V_166 += V_163 ;
if ( V_163 != V_73 )
return;
V_83 -> V_168 &= ~ V_176 ;
switch ( F_12 ( V_83 -> V_178 ) ) {
case V_179 :
V_83 -> V_168 |= V_180 ;
V_83 -> V_168 |= V_172 ;
V_83 -> V_168 |= V_177 ;
break;
case V_181 :
V_83 -> V_168 |= V_180 ;
V_83 -> V_168 |= V_172 ;
V_83 -> V_168 &= ~ V_177 ;
break;
default:
F_2 ( L_30 ) ;
F_101 ( & V_83 -> V_11 ) ;
}
F_104 ( V_83 ) ;
}
static inline void F_107 ( struct V_6 * V_11 ,
struct V_146 * V_147 ,
struct V_88 * V_89 )
{
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_54 * V_182 ;
T_4 V_73 ;
T_3 V_183 ;
V_182 = & V_89 -> V_156 ;
if ( V_83 -> V_168 & V_180 ) {
memcpy ( V_182 -> V_77 [ 0 ] . V_52 + V_83 -> V_174 ,
& V_83 -> V_178 ,
sizeof( V_83 -> V_178 ) ) ;
V_83 -> V_174 += sizeof( V_83 -> V_178 ) ;
V_83 -> V_168 &= ~ V_180 ;
}
V_73 = V_147 -> V_3 ;
if ( V_73 > V_83 -> V_167 - V_83 -> V_166 ) {
struct V_146 V_184 ;
V_73 = V_83 -> V_167 - V_83 -> V_166 ;
memcpy ( & V_184 , V_147 , sizeof( V_184 ) ) ;
V_184 . V_3 = V_73 ;
V_183 = F_81 ( V_182 , V_83 -> V_174 ,
& V_184 , V_148 ) ;
V_147 -> V_3 -= V_183 ;
V_147 -> V_59 += V_183 ;
} else
V_183 = F_81 ( V_182 , V_83 -> V_174 ,
V_147 , V_148 ) ;
if ( V_183 > 0 ) {
V_83 -> V_174 += V_183 ;
V_83 -> V_166 += V_183 ;
}
if ( V_183 != V_73 ) {
V_83 -> V_168 &= ~ V_172 ;
F_2 ( L_31 ,
F_12 ( V_83 -> V_175 ) ) ;
F_2 ( L_32
L_33 ,
V_11 , V_83 -> V_174 ,
V_83 -> V_166 , V_83 -> V_167 ) ;
return;
}
F_2 ( L_34 ,
F_12 ( V_83 -> V_175 ) , V_183 ) ;
F_2 ( L_35
L_36 , V_11 , V_83 -> V_174 ,
V_83 -> V_166 , V_83 -> V_167 ) ;
if ( V_83 -> V_174 == V_89 -> V_156 . V_157 )
V_83 -> V_168 &= ~ V_172 ;
else if ( V_83 -> V_166 == V_83 -> V_167 ) {
if ( V_83 -> V_168 & V_169 )
V_83 -> V_168 &= ~ V_172 ;
}
}
static inline int F_108 ( struct V_6 * V_11 ,
struct V_146 * V_147 )
{
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_88 * V_89 ;
F_2 ( L_37 , F_12 ( V_83 -> V_175 ) ) ;
F_30 ( & V_11 -> V_95 ) ;
V_89 = F_84 ( V_11 , V_83 -> V_175 ) ;
if ( ! V_89 ) {
F_2 ( L_38 ,
F_12 ( V_83 -> V_175 ) ) ;
F_33 ( & V_11 -> V_95 ) ;
return - 1 ;
}
F_107 ( V_11 , V_147 , V_89 ) ;
if ( ! ( V_83 -> V_168 & V_172 ) )
F_85 ( V_89 -> V_155 , V_83 -> V_174 ) ;
F_33 ( & V_11 -> V_95 ) ;
return 0 ;
}
static int F_109 ( struct V_6 * V_11 ,
struct V_146 * V_147 )
{
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_88 * V_89 ;
F_30 ( & V_11 -> V_95 ) ;
V_89 = F_110 ( V_11 , V_83 -> V_175 ) ;
if ( V_89 == NULL ) {
F_33 ( & V_11 -> V_95 ) ;
F_111 ( V_185 L_39 ) ;
F_102 ( V_11 ) ;
return - 1 ;
}
F_2 ( L_40 , F_12 ( V_89 -> V_186 ) ) ;
F_107 ( V_11 , V_147 , V_89 ) ;
if ( ! ( V_83 -> V_168 & V_172 ) )
F_112 ( V_89 , V_83 -> V_174 ) ;
F_33 ( & V_11 -> V_95 ) ;
return 0 ;
}
static inline int F_113 ( struct V_6 * V_11 ,
struct V_146 * V_147 )
{
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
return ( V_83 -> V_168 & V_177 ) ?
F_108 ( V_11 , V_147 ) :
F_109 ( V_11 , V_147 ) ;
}
static int F_114 ( struct V_187 * V_188 , struct V_189 * V_189 )
{
int V_90 ;
V_90 = F_115 ( V_188 , L_41 , V_189 , V_190 , 0 ,
V_191 ) ;
if ( V_90 < 0 )
return V_90 ;
return 0 ;
}
static T_4 F_116 ( struct V_6 * V_11 )
{
return V_192 ;
}
static inline int F_113 ( struct V_6 * V_11 ,
struct V_146 * V_147 )
{
return F_108 ( V_11 , V_147 ) ;
}
static void F_117 ( struct V_6 * V_11 ,
struct V_146 * V_147 )
{
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
if ( F_113 ( V_11 , V_147 ) == 0 )
F_104 ( V_83 ) ;
else {
V_83 -> V_168 &= ~ V_172 ;
}
}
static inline void F_118 ( struct V_82 * V_83 , struct V_146 * V_147 )
{
T_4 V_73 ;
V_73 = V_83 -> V_167 - V_83 -> V_166 ;
if ( V_73 > V_147 -> V_3 )
V_73 = V_147 -> V_3 ;
V_147 -> V_3 -= V_73 ;
V_147 -> V_59 += V_73 ;
V_83 -> V_166 += V_73 ;
F_2 ( L_42 , V_73 ) ;
F_104 ( V_83 ) ;
}
static int F_119 ( T_6 * V_193 , struct V_144 * V_145 , unsigned int V_59 , T_4 V_73 )
{
struct V_6 * V_11 = V_193 -> V_194 . V_195 ;
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_146 V_147 = {
. V_145 = V_145 ,
. V_59 = V_59 ,
. V_3 = V_73 ,
} ;
F_2 ( L_43 ) ;
do {
F_120 ( V_83 ) ;
if ( V_83 -> V_168 & V_171 ) {
F_103 ( V_11 , & V_147 ) ;
continue;
}
if ( V_83 -> V_168 & V_173 ) {
F_105 ( V_83 , & V_147 ) ;
continue;
}
if ( V_83 -> V_168 & V_176 ) {
F_106 ( V_83 , & V_147 ) ;
continue;
}
if ( V_83 -> V_168 & V_172 ) {
F_117 ( V_11 , & V_147 ) ;
continue;
}
F_118 ( V_83 , & V_147 ) ;
} while ( V_147 . V_3 );
F_120 ( V_83 ) ;
F_2 ( L_44 ) ;
return V_73 - V_147 . V_3 ;
}
static void F_121 ( struct V_82 * V_83 )
{
struct V_6 * V_11 = & V_83 -> V_11 ;
struct V_7 * V_8 ;
T_6 V_193 = {
. V_3 = 2 * 1024 * 1024 ,
. V_194 . V_195 = V_11 ,
} ;
unsigned long V_196 = 0 ;
int V_197 = 0 ;
F_66 ( & V_83 -> V_139 ) ;
V_8 = V_83 -> V_86 ;
if ( V_8 == NULL )
goto V_78;
for (; ; ) {
F_122 ( V_8 ) ;
V_197 = F_123 ( V_8 , & V_193 , F_119 ) ;
if ( V_197 <= 0 ) {
F_51 ( V_129 , & V_83 -> V_130 ) ;
F_124 ( V_8 ) ;
if ( ! F_44 ( V_129 , & V_83 -> V_130 ) )
break;
} else {
F_124 ( V_8 ) ;
V_196 += V_197 ;
}
V_193 . V_3 = 65536 ;
}
V_78:
F_70 ( & V_83 -> V_139 ) ;
F_125 ( V_11 , V_197 , V_196 ) ;
}
static void F_126 ( struct V_158 * V_159 )
{
struct V_82 * V_83 =
F_28 ( V_159 , struct V_82 , V_142 ) ;
F_121 ( V_83 ) ;
}
static void F_127 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
struct V_82 * V_83 ;
F_58 ( & V_8 -> V_132 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_78;
F_2 ( L_45 , V_11 ) ;
F_2 ( L_46 ,
V_8 -> V_134 , F_31 ( V_11 ) ,
F_128 ( V_8 , V_198 ) ,
F_128 ( V_8 , V_199 ) ,
V_8 -> V_200 ) ;
V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
F_129 ( V_11 , V_8 -> V_136 ) ;
switch ( V_8 -> V_134 ) {
case V_201 :
F_130 ( & V_11 -> V_95 ) ;
if ( ! F_131 ( V_11 ) ) {
V_83 -> V_166 = 0 ;
V_83 -> V_167 = 0 ;
V_83 -> V_174 = 0 ;
V_83 -> V_168 =
V_171 | V_173 ;
V_11 -> V_202 ++ ;
F_51 ( V_203 , & V_83 -> V_130 ) ;
F_132 ( V_11 ) ;
F_60 ( V_11 , - V_91 ) ;
}
F_133 ( & V_11 -> V_95 ) ;
break;
case V_204 :
V_11 -> V_202 ++ ;
V_11 -> V_140 = 0 ;
F_46 ( V_131 , & V_11 -> V_121 ) ;
F_53 () ;
F_51 ( V_205 , & V_11 -> V_121 ) ;
F_51 ( V_120 , & V_11 -> V_121 ) ;
F_54 () ;
break;
case V_206 :
V_11 -> V_202 ++ ;
F_51 ( V_205 , & V_11 -> V_121 ) ;
F_101 ( V_11 ) ;
case V_207 :
if ( V_11 -> V_140 < V_208 )
V_11 -> V_140 = V_208 ;
break;
case V_209 :
F_46 ( V_131 , & V_11 -> V_121 ) ;
F_53 () ;
F_51 ( V_205 , & V_11 -> V_121 ) ;
F_54 () ;
break;
case V_135 :
if ( F_89 ( V_203 ,
& V_83 -> V_130 ) )
F_132 ( V_11 ) ;
F_55 ( V_11 ) ;
}
V_78:
F_61 ( & V_8 -> V_132 ) ;
}
static void F_134 ( struct V_7 * V_8 )
{
struct V_210 * V_211 ;
struct V_6 * V_11 ;
if ( ! V_8 -> V_136 )
return;
F_51 ( V_115 , & V_8 -> V_136 -> V_61 ) ;
if ( F_26 ( ! ( V_11 = F_3 ( V_8 ) ) ) )
return;
F_135 () ;
V_211 = F_136 ( V_8 -> V_212 ) ;
if ( ! V_211 || F_89 ( V_213 , & V_211 -> V_61 ) == 0 )
goto V_78;
F_137 ( V_11 ) ;
V_78:
F_138 () ;
}
static void F_139 ( struct V_7 * V_8 )
{
F_58 ( & V_8 -> V_132 ) ;
if ( F_37 ( V_8 ) )
F_134 ( V_8 ) ;
F_61 ( & V_8 -> V_132 ) ;
}
static void F_140 ( struct V_7 * V_8 )
{
F_58 ( & V_8 -> V_132 ) ;
if ( F_141 ( V_8 ) )
F_134 ( V_8 ) ;
F_61 ( & V_8 -> V_132 ) ;
}
static void F_142 ( struct V_6 * V_11 )
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
V_8 -> V_97 ( V_8 ) ;
}
}
static void F_143 ( struct V_6 * V_11 , T_4 V_219 , T_4 V_214 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
V_83 -> V_219 = 0 ;
if ( V_219 )
V_83 -> V_219 = V_219 + 1024 ;
V_83 -> V_214 = 0 ;
if ( V_214 )
V_83 -> V_214 = V_214 + 1024 ;
F_142 ( V_11 ) ;
}
static void F_144 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
F_94 ( V_11 , V_81 , - V_222 ) ;
}
static unsigned short F_145 ( void )
{
unsigned short V_223 = V_224 - V_225 + 1 ;
unsigned short rand = ( unsigned short ) F_146 () % V_223 ;
return rand + V_225 ;
}
static void F_147 ( struct V_39 * V_7 )
{
int V_226 = 1 ;
F_148 ( V_7 , V_227 , V_228 ,
( char * ) & V_226 , sizeof( V_226 ) ) ;
}
static unsigned short F_149 ( struct V_39 * V_7 )
{
struct V_229 V_4 ;
int V_157 ;
unsigned short V_230 = 0 ;
if ( F_150 ( V_7 , (struct V_10 * ) & V_4 , & V_157 ) < 0 )
goto V_78;
switch ( V_4 . V_231 ) {
case V_28 :
V_230 = F_151 ( ( (struct V_15 * ) & V_4 ) -> V_232 ) ;
break;
case V_25 :
V_230 = F_151 ( ( (struct V_14 * ) & V_4 ) -> V_233 ) ;
}
V_78:
return V_230 ;
}
static void F_152 ( struct V_6 * V_11 , unsigned short V_230 )
{
F_2 ( L_47 , V_11 , V_230 ) ;
F_153 ( F_4 ( V_11 ) , V_230 ) ;
F_17 ( V_11 ) ;
}
static void F_154 ( struct V_82 * V_83 , struct V_39 * V_7 )
{
if ( V_83 -> V_234 == 0 )
V_83 -> V_234 = F_149 ( V_7 ) ;
}
static unsigned short F_155 ( struct V_82 * V_83 )
{
unsigned short V_230 = V_83 -> V_234 ;
if ( V_230 == 0 && V_83 -> V_11 . V_235 )
V_230 = F_145 () ;
return V_230 ;
}
static unsigned short F_156 ( struct V_82 * V_83 , unsigned short V_230 )
{
if ( V_83 -> V_234 != 0 )
V_83 -> V_234 = 0 ;
if ( ! V_83 -> V_11 . V_235 )
return 0 ;
if ( V_230 <= V_225 || V_230 > V_224 )
return V_224 ;
return -- V_230 ;
}
static int F_157 ( struct V_82 * V_83 , struct V_39 * V_7 )
{
struct V_229 V_236 ;
int V_64 , V_237 = 0 ;
unsigned short V_230 = F_155 ( V_83 ) ;
unsigned short V_238 ;
if ( V_230 == 0 )
return 0 ;
memcpy ( & V_236 , & V_83 -> V_239 , V_83 -> V_11 . V_40 ) ;
do {
F_153 ( (struct V_10 * ) & V_236 , V_230 ) ;
V_64 = F_158 ( V_7 , (struct V_10 * ) & V_236 ,
V_83 -> V_11 . V_40 ) ;
if ( V_64 == 0 ) {
V_83 -> V_234 = V_230 ;
break;
}
V_238 = V_230 ;
V_230 = F_156 ( V_83 , V_230 ) ;
if ( V_230 > V_238 )
V_237 ++ ;
} while ( V_64 == - V_117 && V_237 != 2 );
if ( V_236 . V_231 == V_25 )
F_2 ( L_48 , V_104 ,
& ( (struct V_14 * ) & V_236 ) -> V_26 ,
V_230 , V_64 ? L_49 : L_50 , V_64 ) ;
else
F_2 ( L_51 , V_104 ,
& ( (struct V_15 * ) & V_236 ) -> V_29 ,
V_230 , V_64 ? L_49 : L_50 , V_64 ) ;
return V_64 ;
}
static void F_159 ( struct V_80 * V_81 )
{
F_160 ( V_81 -> V_240 ) ;
}
static void F_161 ( struct V_6 * V_11 , unsigned short V_230 )
{
}
static inline void F_162 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_163 ( V_8 , L_52 ,
& V_241 [ 1 ] , L_53 , & V_242 [ 1 ] ) ;
}
static inline void F_164 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_163 ( V_8 , L_54 ,
& V_241 [ 0 ] , L_55 , & V_242 [ 0 ] ) ;
}
static inline void F_165 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_163 ( V_8 , L_56 ,
& V_241 [ 1 ] , L_57 , & V_242 [ 1 ] ) ;
}
static inline void F_166 ( int V_243 , struct V_39 * V_7 )
{
if ( F_43 ( ! F_167 ( V_7 -> V_8 ) ) )
return;
switch ( V_243 ) {
case V_20 :
F_162 ( V_7 ) ;
break;
case V_25 :
F_164 ( V_7 ) ;
break;
case V_28 :
F_165 ( V_7 ) ;
break;
}
}
static inline void F_166 ( int V_243 , struct V_39 * V_7 )
{
}
static void F_168 ( struct V_158 * V_159 )
{
}
static struct V_39 * F_169 ( struct V_6 * V_11 ,
struct V_82 * V_83 , int V_243 , int type ,
int V_33 , bool V_244 )
{
struct V_39 * V_7 ;
int V_64 ;
V_64 = F_170 ( V_11 -> V_245 , V_243 , type , V_33 , & V_7 , 1 ) ;
if ( V_64 < 0 ) {
F_2 ( L_58 ,
V_33 , - V_64 ) ;
goto V_78;
}
F_166 ( V_243 , V_7 ) ;
if ( V_244 )
F_147 ( V_7 ) ;
V_64 = F_157 ( V_83 , V_7 ) ;
if ( V_64 ) {
F_72 ( V_7 ) ;
goto V_78;
}
return V_7 ;
V_78:
return F_171 ( V_64 ) ;
}
static int F_172 ( struct V_6 * V_11 ,
struct V_39 * V_7 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 ,
V_11 ) ;
if ( ! V_83 -> V_86 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
F_67 ( & V_8 -> V_132 ) ;
F_48 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_123 = F_98 ;
V_8 -> V_97 = F_139 ;
F_173 ( V_8 , V_246 ) ;
V_8 -> V_128 = F_57 ;
V_8 -> V_247 = V_248 ;
F_68 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_69 ( & V_8 -> V_132 ) ;
}
V_11 -> V_249 . V_250 ++ ;
V_11 -> V_249 . V_251 = V_252 ;
return F_174 ( V_7 , F_4 ( V_11 ) , V_11 -> V_40 , 0 ) ;
}
static int F_175 ( struct V_82 * V_83 )
{
struct V_6 * V_11 = & V_83 -> V_11 ;
struct V_39 * V_7 ;
int V_102 = - V_253 ;
V_102 = F_170 ( V_11 -> V_245 , V_20 ,
V_254 , 0 , & V_7 , 1 ) ;
if ( V_102 < 0 ) {
F_2 ( L_59
L_60 , - V_102 ) ;
goto V_78;
}
F_166 ( V_20 , V_7 ) ;
F_2 ( L_61 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
V_102 = F_172 ( V_11 , V_7 ) ;
F_176 ( V_11 , V_7 , V_102 ) ;
switch ( V_102 ) {
case 0 :
F_2 ( L_62 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
F_177 ( V_11 ) ;
case - V_105 :
break;
case - V_255 :
F_2 ( L_63 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
break;
case - V_111 :
F_2 ( L_64 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
break;
default:
F_111 ( V_256 L_65 ,
V_104 , - V_102 ,
V_11 -> V_22 [ V_23 ] ) ;
}
V_78:
F_132 ( V_11 ) ;
F_60 ( V_11 , V_102 ) ;
return V_102 ;
}
static void F_178 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
int V_90 ;
if ( F_179 ( V_81 ) ) {
F_180 ( V_81 , - V_96 ) ;
return;
}
V_90 = F_175 ( V_83 ) ;
if ( V_90 && ! F_181 ( V_81 ) )
F_182 ( 15000 ) ;
}
static void F_183 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 ,
V_11 ) ;
if ( ! V_83 -> V_86 )
return;
if ( F_63 ( & V_11 -> V_137 ) )
F_184 ( V_83 -> V_86 ) ;
}
static int
F_185 ( struct V_6 * V_11 )
{
struct V_82 * V_257 = F_28 ( V_11 , struct V_82 , V_11 ) ;
if ( F_186 ( & V_11 -> V_137 ) != 1 )
return 0 ;
if ( F_187 ( & V_11 -> V_121 , V_258 , V_259 ) )
return - V_260 ;
if ( V_257 -> V_86 )
F_184 ( V_257 -> V_86 ) ;
F_47 ( V_11 , NULL ) ;
return 0 ;
}
static void
F_188 ( struct V_6 * V_11 )
{
struct V_82 * V_257 = F_28 ( V_11 , struct V_82 , V_11 ) ;
if ( ! F_189 ( & V_11 -> V_137 ) )
return;
if ( F_187 ( & V_11 -> V_121 , V_258 , V_259 ) )
return;
if ( V_257 -> V_86 )
F_64 ( V_257 -> V_86 ) ;
F_47 ( V_11 , NULL ) ;
}
static void F_183 ( struct V_6 * V_11 )
{
}
static int
F_185 ( struct V_6 * V_11 )
{
return - V_261 ;
}
static void
F_188 ( struct V_6 * V_11 )
{
}
static void F_190 ( struct V_6 * V_11 , struct V_39 * V_7 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
if ( ! V_83 -> V_86 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
F_67 ( & V_8 -> V_132 ) ;
F_48 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_123 = F_98 ;
V_8 -> V_97 = F_139 ;
F_173 ( V_8 , V_246 ) ;
V_8 -> V_247 = V_248 ;
F_177 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_183 ( V_11 ) ;
F_69 ( & V_8 -> V_132 ) ;
}
F_142 ( V_11 ) ;
V_11 -> V_249 . V_251 = V_252 ;
}
static void F_191 ( struct V_158 * V_159 )
{
struct V_82 * V_83 =
F_28 ( V_159 , struct V_82 , V_141 . V_159 ) ;
struct V_6 * V_11 = & V_83 -> V_11 ;
struct V_39 * V_7 = V_83 -> V_7 ;
int V_102 = - V_253 ;
V_7 = F_169 ( V_11 , V_83 ,
F_4 ( V_11 ) -> V_19 , V_262 ,
V_263 , false ) ;
if ( F_192 ( V_7 ) )
goto V_78;
F_2 ( L_66
L_67 , V_11 ,
V_11 -> V_22 [ V_35 ] ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ) ;
F_190 ( V_11 , V_7 ) ;
F_176 ( V_11 , V_7 , 0 ) ;
V_102 = 0 ;
V_78:
F_193 ( V_11 , V_83 ) ;
F_132 ( V_11 ) ;
F_60 ( V_11 , V_102 ) ;
}
static void F_194 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
if ( V_7 == NULL )
return;
if ( F_31 ( V_11 ) ) {
F_65 ( V_7 , V_138 ) ;
F_195 ( V_11 , V_7 ) ;
} else
F_62 ( V_83 ) ;
}
static int F_196 ( struct V_6 * V_11 , struct V_39 * V_7 )
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
F_148 ( V_7 , V_227 , V_274 ,
( char * ) & V_270 , sizeof( V_270 ) ) ;
F_148 ( V_7 , V_275 , V_276 ,
( char * ) & V_264 , sizeof( V_264 ) ) ;
F_148 ( V_7 , V_275 , V_277 ,
( char * ) & V_264 , sizeof( V_264 ) ) ;
F_148 ( V_7 , V_275 , V_278 ,
( char * ) & V_268 , sizeof( V_268 ) ) ;
F_148 ( V_7 , V_279 , V_280 ,
( char * ) & V_272 , sizeof( V_272 ) ) ;
V_271 = F_197 ( V_11 -> V_265 -> V_266 ) *
( V_11 -> V_265 -> V_269 + 1 ) ;
F_148 ( V_7 , V_275 , V_281 ,
( char * ) & V_271 , sizeof( V_271 ) ) ;
F_67 ( & V_8 -> V_132 ) ;
F_48 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_123 = F_98 ;
V_8 -> V_125 = F_127 ;
V_8 -> V_97 = F_140 ;
F_173 ( V_8 , V_246 ) ;
V_8 -> V_128 = F_57 ;
V_8 -> V_247 = V_248 ;
F_198 ( V_8 , V_282 ) ;
F_199 ( V_8 ) -> V_283 |= V_284 ;
F_68 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_69 ( & V_8 -> V_132 ) ;
}
if ( ! F_41 ( V_11 ) )
goto V_78;
F_183 ( V_11 ) ;
V_11 -> V_249 . V_250 ++ ;
V_11 -> V_249 . V_251 = V_252 ;
F_46 ( V_203 , & V_83 -> V_130 ) ;
V_90 = F_174 ( V_7 , F_4 ( V_11 ) , V_11 -> V_40 , V_285 ) ;
switch ( V_90 ) {
case 0 :
F_154 ( V_83 , V_7 ) ;
case - V_286 :
if ( V_11 -> V_140 < V_208 )
V_11 -> V_140 = V_208 ;
break;
case - V_287 :
V_83 -> V_234 = 0 ;
}
V_78:
return V_90 ;
}
static void F_200 ( struct V_158 * V_159 )
{
struct V_82 * V_83 =
F_28 ( V_159 , struct V_82 , V_141 . V_159 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
struct V_6 * V_11 = & V_83 -> V_11 ;
int V_102 = - V_253 ;
if ( ! V_7 ) {
V_7 = F_169 ( V_11 , V_83 ,
F_4 ( V_11 ) -> V_19 , V_254 ,
V_288 , true ) ;
if ( F_192 ( V_7 ) ) {
V_102 = F_201 ( V_7 ) ;
goto V_78;
}
}
F_2 ( L_66
L_67 , V_11 ,
V_11 -> V_22 [ V_35 ] ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ) ;
V_102 = F_196 ( V_11 , V_7 ) ;
F_176 ( V_11 , V_7 , V_102 ) ;
F_2 ( L_68 ,
V_11 , - V_102 , F_31 ( V_11 ) ,
V_7 -> V_8 -> V_134 ) ;
switch ( V_102 ) {
default:
F_111 ( L_69 ,
V_104 , V_102 ) ;
case - V_287 :
F_101 ( V_11 ) ;
break;
case 0 :
case - V_286 :
case - V_289 :
F_193 ( V_11 , V_83 ) ;
return;
case - V_261 :
case - V_111 :
case - V_116 :
case - V_110 :
case - V_117 :
case - V_105 :
F_101 ( V_11 ) ;
goto V_78;
}
V_102 = - V_91 ;
V_78:
F_193 ( V_11 , V_83 ) ;
F_132 ( V_11 ) ;
F_60 ( V_11 , V_102 ) ;
}
static unsigned long F_202 ( const struct V_6 * V_11 )
{
unsigned long V_290 , V_291 = V_252 ;
V_290 = V_11 -> V_249 . V_251 + V_11 -> V_140 ;
if ( F_203 ( V_290 , V_291 ) )
return V_290 - V_291 ;
return 0 ;
}
static void F_204 ( struct V_6 * V_11 )
{
V_11 -> V_140 <<= 1 ;
if ( V_11 -> V_140 > V_11 -> V_292 )
V_11 -> V_140 = V_11 -> V_292 ;
if ( V_11 -> V_140 < V_208 )
V_11 -> V_140 = V_208 ;
}
static void F_205 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
unsigned long V_293 = 0 ;
F_43 ( ! F_206 ( V_11 , V_81 , V_83 ) ) ;
if ( V_83 -> V_7 != NULL ) {
F_2 ( L_70
L_71 ,
V_11 , V_11 -> V_140 / V_267 ) ;
F_62 ( V_83 ) ;
V_293 = F_202 ( V_11 ) ;
F_204 ( V_11 ) ;
} else
F_2 ( L_72 , V_11 ) ;
F_207 ( V_162 ,
& V_83 -> V_141 ,
V_293 ) ;
}
static void F_208 ( struct V_6 * V_11 , struct V_294 * V_295 )
{
long V_296 = 0 ;
if ( F_31 ( V_11 ) )
V_296 = ( long ) ( V_252 - V_11 -> V_297 ) / V_267 ;
F_209 ( V_295 , L_73
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
static void F_210 ( struct V_6 * V_11 , struct V_294 * V_295 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
F_209 ( V_295 , L_75
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
static void F_211 ( struct V_6 * V_11 , struct V_294 * V_295 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
long V_296 = 0 ;
if ( F_31 ( V_11 ) )
V_296 = ( long ) ( V_252 - V_11 -> V_297 ) / V_267 ;
F_209 ( V_295 , L_77
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
static void * F_212 ( struct V_80 * V_81 , T_4 V_60 )
{
struct V_58 * V_58 ;
struct V_308 * V_4 ;
F_43 ( V_60 > V_192 - sizeof( struct V_308 ) ) ;
if ( V_60 > V_192 - sizeof( struct V_308 ) )
return NULL ;
V_58 = F_213 ( V_24 ) ;
if ( ! V_58 )
return NULL ;
V_4 = F_214 ( V_58 ) ;
V_4 -> V_73 = V_192 ;
return V_4 -> V_195 ;
}
static void F_215 ( void * V_309 )
{
struct V_308 * V_4 ;
if ( ! V_309 )
return;
V_4 = F_28 ( V_309 , struct V_308 , V_195 ) ;
F_216 ( ( unsigned long ) V_4 ) ;
}
static int F_217 ( struct V_88 * V_89 )
{
int V_73 ;
struct V_54 * V_310 = & V_89 -> V_101 ;
struct V_6 * V_11 = V_89 -> V_85 ;
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
unsigned long V_311 ;
unsigned long V_312 ;
F_34 ( V_310 ) ;
V_312 = ( unsigned long ) V_310 -> V_79 [ 0 ] . V_52 & ~ V_69 ;
V_311 = ( unsigned long ) V_310 -> V_77 [ 0 ] . V_52 & ~ V_69 ;
V_73 = F_218 ( V_7 , V_310 ,
F_219 ( V_310 -> V_77 [ 0 ] . V_52 ) , V_311 ,
V_310 -> V_79 [ 0 ] . V_52 , V_312 ) ;
if ( V_73 != V_310 -> V_73 ) {
F_111 ( V_313 L_78 ) ;
V_73 = - V_91 ;
}
return V_73 ;
}
static int F_220 ( struct V_80 * V_81 )
{
struct V_88 * V_89 = V_81 -> V_84 ;
struct V_314 * V_11 ;
int V_73 ;
F_2 ( L_79 , F_12 ( V_89 -> V_186 ) ) ;
V_11 = V_89 -> V_85 -> V_315 ;
if ( ! F_221 ( & V_11 -> V_316 ) ) {
F_222 ( & V_11 -> V_317 , V_81 , NULL ) ;
if ( ! F_221 ( & V_11 -> V_316 ) )
return - V_91 ;
F_223 ( & V_11 -> V_317 , V_81 ) ;
}
if ( F_44 ( V_318 , & V_11 -> V_319 ) )
V_73 = - V_96 ;
else
V_73 = F_217 ( V_89 ) ;
F_70 ( & V_11 -> V_316 ) ;
if ( V_73 > 0 )
V_73 = 0 ;
return V_73 ;
}
static void F_224 ( struct V_6 * V_11 )
{
}
static void F_225 ( struct V_6 * V_11 )
{
F_2 ( L_80 , V_11 ) ;
F_74 ( V_11 ) ;
F_79 ( V_143 ) ;
}
static int F_226 ( const int V_243 , struct V_10 * V_16 )
{
static const struct V_14 sin = {
. V_320 = V_25 ,
. V_26 . V_27 = F_227 ( V_321 ) ,
} ;
static const struct V_15 V_17 = {
. V_322 = V_28 ,
. V_29 = V_323 ,
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
F_2 ( L_81 , V_104 ) ;
return - V_324 ;
}
return 0 ;
}
static struct V_6 * F_228 ( struct V_325 * args ,
unsigned int V_326 ,
unsigned int V_327 )
{
struct V_6 * V_11 ;
struct V_82 * V_328 ;
if ( args -> V_40 > sizeof( V_11 -> V_12 ) ) {
F_2 ( L_82 ) ;
return F_171 ( - V_329 ) ;
}
V_11 = F_229 ( args -> V_189 , sizeof( * V_328 ) , V_326 ,
V_327 ) ;
if ( V_11 == NULL ) {
F_2 ( L_83
L_84 ) ;
return F_171 ( - V_330 ) ;
}
V_328 = F_28 ( V_11 , struct V_82 , V_11 ) ;
F_230 ( & V_328 -> V_139 ) ;
memcpy ( & V_11 -> V_12 , args -> V_331 , args -> V_40 ) ;
V_11 -> V_40 = args -> V_40 ;
if ( args -> V_239 )
memcpy ( & V_328 -> V_239 , args -> V_239 , args -> V_40 ) ;
else {
int V_64 ;
V_64 = F_226 ( args -> V_331 -> V_19 ,
(struct V_10 * ) & V_328 -> V_239 ) ;
if ( V_64 != 0 ) {
F_75 ( V_11 ) ;
return F_171 ( V_64 ) ;
}
}
return V_11 ;
}
static struct V_6 * F_231 ( struct V_325 * args )
{
struct V_13 * V_18 = (struct V_13 * ) args -> V_331 ;
struct V_82 * V_83 ;
struct V_6 * V_11 ;
struct V_6 * V_90 ;
V_11 = F_228 ( args , V_332 ,
V_333 ) ;
if ( F_192 ( V_11 ) )
return V_11 ;
V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_334 = 0 ;
V_11 -> V_335 = sizeof( V_99 ) / sizeof( T_1 ) ;
V_11 -> V_336 = V_337 ;
V_11 -> V_338 = V_339 ;
V_11 -> V_140 = V_208 ;
V_11 -> V_340 = V_341 ;
V_11 -> V_70 = & V_342 ;
V_11 -> V_265 = & V_343 ;
F_232 ( & V_83 -> V_142 , F_90 ) ;
F_233 ( & V_83 -> V_141 ,
F_168 ) ;
switch ( V_18 -> V_344 ) {
case V_20 :
if ( V_18 -> V_21 [ 0 ] != '/' ) {
F_2 ( L_85 ,
V_18 -> V_21 ) ;
V_90 = F_171 ( - V_261 ) ;
goto V_345;
}
F_160 ( V_11 ) ;
F_16 ( V_11 , L_86 , V_346 ) ;
V_90 = F_171 ( F_175 ( V_83 ) ) ;
if ( V_90 )
goto V_345;
break;
default:
V_90 = F_171 ( - V_324 ) ;
goto V_345;
}
F_2 ( L_87 ,
V_11 -> V_22 [ V_23 ] ) ;
if ( F_234 ( V_143 ) )
return V_11 ;
V_90 = F_171 ( - V_261 ) ;
V_345:
F_74 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_235 ( struct V_325 * args )
{
struct V_10 * V_12 = args -> V_331 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_6 * V_90 ;
V_11 = F_228 ( args , V_347 ,
V_347 ) ;
if ( F_192 ( V_11 ) )
return V_11 ;
V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_334 = V_263 ;
V_11 -> V_335 = 0 ;
V_11 -> V_336 = ( 1U << 16 ) - ( V_348 << 3 ) ;
V_11 -> V_338 = V_339 ;
V_11 -> V_140 = V_349 ;
V_11 -> V_340 = V_341 ;
V_11 -> V_70 = & V_350 ;
V_11 -> V_265 = & V_351 ;
F_232 ( & V_83 -> V_142 , F_97 ) ;
F_233 ( & V_83 -> V_141 , F_191 ) ;
switch ( V_12 -> V_19 ) {
case V_25 :
if ( ( (struct V_14 * ) V_12 ) -> V_233 != F_236 ( 0 ) )
F_160 ( V_11 ) ;
F_16 ( V_11 , L_88 , V_352 ) ;
break;
case V_28 :
if ( ( (struct V_15 * ) V_12 ) -> V_232 != F_236 ( 0 ) )
F_160 ( V_11 ) ;
F_16 ( V_11 , L_88 , V_353 ) ;
break;
default:
V_90 = F_171 ( - V_324 ) ;
goto V_345;
}
if ( F_41 ( V_11 ) )
F_2 ( L_89 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
else
F_2 ( L_90 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_35 ] ) ;
if ( F_234 ( V_143 ) )
return V_11 ;
V_90 = F_171 ( - V_261 ) ;
V_345:
F_74 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_237 ( struct V_325 * args )
{
struct V_10 * V_12 = args -> V_331 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_6 * V_90 ;
unsigned int V_327 = V_333 ;
if ( args -> V_61 & V_354 )
V_327 = V_355 ;
V_11 = F_228 ( args , V_332 ,
V_327 ) ;
if ( F_192 ( V_11 ) )
return V_11 ;
V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_334 = V_288 ;
V_11 -> V_335 = sizeof( V_99 ) / sizeof( T_1 ) ;
V_11 -> V_336 = V_337 ;
V_11 -> V_338 = V_339 ;
V_11 -> V_140 = V_208 ;
V_11 -> V_340 = V_341 ;
V_11 -> V_70 = & V_356 ;
V_11 -> V_265 = & V_357 ;
V_11 -> V_292 = V_11 -> V_265 -> V_358 ;
F_232 ( & V_83 -> V_142 , F_126 ) ;
F_233 ( & V_83 -> V_141 , F_200 ) ;
switch ( V_12 -> V_19 ) {
case V_25 :
if ( ( (struct V_14 * ) V_12 ) -> V_233 != F_236 ( 0 ) )
F_160 ( V_11 ) ;
F_16 ( V_11 , L_91 , V_359 ) ;
break;
case V_28 :
if ( ( (struct V_15 * ) V_12 ) -> V_232 != F_236 ( 0 ) )
F_160 ( V_11 ) ;
F_16 ( V_11 , L_91 , V_360 ) ;
break;
default:
V_90 = F_171 ( - V_324 ) ;
goto V_345;
}
if ( F_41 ( V_11 ) )
F_2 ( L_89 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
else
F_2 ( L_90 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_35 ] ) ;
if ( F_234 ( V_143 ) )
return V_11 ;
V_90 = F_171 ( - V_261 ) ;
V_345:
F_74 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_238 ( struct V_325 * args )
{
struct V_10 * V_12 = args -> V_331 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_361 * V_362 ;
struct V_6 * V_90 ;
V_11 = F_228 ( args , V_332 ,
V_332 ) ;
if ( F_192 ( V_11 ) )
return V_11 ;
V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_334 = V_288 ;
V_11 -> V_335 = sizeof( V_99 ) / sizeof( T_1 ) ;
V_11 -> V_336 = V_337 ;
V_11 -> V_265 = & V_357 ;
F_160 ( V_11 ) ;
V_11 -> V_338 = 0 ;
V_11 -> V_140 = 0 ;
V_11 -> V_340 = 0 ;
V_11 -> V_70 = & V_363 ;
switch ( V_12 -> V_19 ) {
case V_25 :
F_16 ( V_11 , L_91 ,
V_359 ) ;
break;
case V_28 :
F_16 ( V_11 , L_91 ,
V_360 ) ;
break;
default:
V_90 = F_171 ( - V_324 ) ;
goto V_345;
}
F_2 ( L_89 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
F_239 ( V_11 ) ;
args -> V_315 -> V_364 = V_11 ;
V_11 -> V_315 = args -> V_315 ;
V_362 = F_28 ( args -> V_315 , struct V_361 , V_365 ) ;
V_83 -> V_7 = V_362 -> V_366 ;
V_83 -> V_86 = V_362 -> V_367 ;
F_177 ( V_11 ) ;
if ( F_234 ( V_143 ) )
return V_11 ;
args -> V_315 -> V_364 = NULL ;
args -> V_315 -> V_368 = NULL ;
F_240 ( V_11 ) ;
V_90 = F_171 ( - V_261 ) ;
V_345:
F_74 ( V_11 ) ;
return V_90 ;
}
int F_241 ( void )
{
#if F_242 ( V_369 )
if ( ! V_370 )
V_370 = F_243 ( V_371 ) ;
#endif
F_244 ( & V_372 ) ;
F_244 ( & V_373 ) ;
F_244 ( & V_374 ) ;
F_244 ( & V_375 ) ;
return 0 ;
}
void F_245 ( void )
{
#if F_242 ( V_369 )
if ( V_370 ) {
F_246 ( V_370 ) ;
V_370 = NULL ;
}
#endif
F_247 ( & V_372 ) ;
F_247 ( & V_373 ) ;
F_247 ( & V_374 ) ;
F_247 ( & V_375 ) ;
}
static int F_248 ( const char * V_376 ,
const struct V_377 * V_378 ,
unsigned int V_379 , unsigned int V_380 )
{
unsigned int V_381 ;
int V_90 ;
if ( ! V_376 )
return - V_261 ;
V_90 = F_249 ( V_376 , 0 , & V_381 ) ;
if ( V_90 == - V_261 || V_381 < V_379 || V_381 > V_380 )
return - V_261 ;
* ( ( unsigned int * ) V_378 -> V_194 ) = V_381 ;
return 0 ;
}
static int F_250 ( const char * V_376 , const struct V_377 * V_378 )
{
if ( V_378 -> V_194 == & V_225 )
return F_248 ( V_376 , V_378 ,
V_382 ,
V_224 ) ;
return F_248 ( V_376 , V_378 ,
V_225 ,
V_383 ) ;
}
static int F_251 ( const char * V_376 ,
const struct V_377 * V_378 )
{
return F_248 ( V_376 , V_378 ,
V_384 ,
V_385 ) ;
}
static int F_252 ( const char * V_376 ,
const struct V_377 * V_378 )
{
return F_248 ( V_376 , V_378 ,
V_384 ,
V_355 ) ;
}

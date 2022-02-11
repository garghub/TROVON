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
int V_102 ;
int V_75 ;
F_34 ( & V_89 -> V_101 ) ;
F_1 ( L_10 ,
V_89 -> V_103 -> V_52 ,
V_89 -> V_103 -> V_53 ) ;
if ( V_81 -> V_112 & V_113 )
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
if ( V_102 < 0 )
break;
if ( V_75 == 0 ) {
V_102 = - V_91 ;
break;
}
}
if ( V_102 == - V_91 && F_43 ( V_83 -> V_86 ) )
V_102 = - V_105 ;
switch ( V_102 ) {
case - V_76 :
V_102 = - V_96 ;
break;
case - V_91 :
V_102 = F_29 ( V_81 ) ;
break;
case - V_114 :
case - V_111 :
case - V_96 :
case - V_115 :
case - V_105 :
case - V_107 :
break;
default:
F_2 ( L_12 ,
- V_102 ) ;
}
return V_102 ;
}
static void F_44 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
struct V_88 * V_89 ;
if ( V_81 != V_11 -> V_116 )
return;
if ( V_81 == NULL )
goto V_117;
V_89 = V_81 -> V_84 ;
if ( V_89 == NULL )
goto V_117;
if ( V_89 -> V_94 == 0 )
goto V_117;
if ( V_89 -> V_94 == V_89 -> V_101 . V_73 )
goto V_117;
F_45 ( V_118 , & V_11 -> V_119 ) ;
V_117:
F_46 ( V_11 , V_81 ) ;
}
static void F_47 ( struct V_82 * V_83 , struct V_7 * V_8 )
{
V_83 -> V_120 = V_8 -> V_121 ;
V_83 -> V_122 = V_8 -> V_123 ;
V_83 -> V_124 = V_8 -> V_97 ;
V_83 -> V_125 = V_8 -> V_126 ;
}
static void F_48 ( struct V_82 * V_83 , struct V_7 * V_8 )
{
V_8 -> V_121 = V_83 -> V_120 ;
V_8 -> V_123 = V_83 -> V_122 ;
V_8 -> V_97 = V_83 -> V_124 ;
V_8 -> V_126 = V_83 -> V_125 ;
}
static void F_49 ( struct V_6 * V_11 )
{
F_50 () ;
F_51 ( V_118 , & V_11 -> V_119 ) ;
F_51 ( V_127 , & V_11 -> V_119 ) ;
F_52 () ;
}
static void F_53 ( struct V_6 * V_11 )
{
F_49 ( V_11 ) ;
F_54 ( V_11 ) ;
}
static void F_55 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
int V_64 ;
F_56 ( & V_8 -> V_128 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_78;
V_64 = - V_8 -> V_129 ;
if ( V_64 == 0 )
goto V_78;
if ( V_8 -> V_130 == V_131 )
F_53 ( V_11 ) ;
F_2 ( L_15 ,
V_11 , - V_64 ) ;
F_57 ( V_11 , V_8 -> V_132 , V_64 ) ;
F_58 ( V_11 , V_64 ) ;
V_78:
F_59 ( & V_8 -> V_128 ) ;
}
static void F_60 ( struct V_82 * V_83 )
{
struct V_39 * V_7 = V_83 -> V_7 ;
struct V_7 * V_8 = V_83 -> V_86 ;
struct V_6 * V_11 = & V_83 -> V_11 ;
if ( V_8 == NULL )
return;
if ( F_61 ( & V_83 -> V_11 . V_133 ) )
F_62 ( V_8 ) ;
F_63 ( V_7 , V_134 ) ;
F_64 ( & V_83 -> V_135 ) ;
F_65 ( & V_8 -> V_128 ) ;
V_83 -> V_86 = NULL ;
V_83 -> V_7 = NULL ;
V_8 -> V_9 = NULL ;
F_48 ( V_83 , V_8 ) ;
F_66 ( V_11 ) ;
F_67 ( & V_8 -> V_128 ) ;
F_49 ( V_11 ) ;
F_68 ( & V_83 -> V_135 ) ;
F_69 ( V_11 , V_7 ) ;
F_70 ( V_7 ) ;
}
static void F_39 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
F_2 ( L_16 , V_11 ) ;
F_60 ( V_83 ) ;
V_11 -> V_136 = 0 ;
F_54 ( V_11 ) ;
}
static void F_71 ( struct V_6 * V_11 )
{
F_2 ( L_17 ,
V_11 ) ;
F_54 ( V_11 ) ;
}
static void F_72 ( struct V_6 * V_11 )
{
F_19 ( V_11 ) ;
F_73 ( V_11 ) ;
}
static void F_74 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_28 ( V_11 ,
struct V_82 , V_11 ) ;
F_2 ( L_18 , V_11 ) ;
F_75 ( & V_83 -> V_137 ) ;
F_39 ( V_11 ) ;
F_76 ( & V_83 -> V_138 ) ;
F_72 ( V_11 ) ;
F_77 ( V_139 ) ;
}
static int F_78 ( struct V_54 * V_55 , struct V_140 * V_141 )
{
struct V_142 V_143 = {
. V_141 = V_141 ,
. V_59 = sizeof( V_99 ) ,
. V_3 = V_141 -> V_73 - sizeof( V_99 ) ,
} ;
if ( F_79 ( V_55 , 0 , & V_143 , V_144 ) < 0 )
return - 1 ;
if ( V_143 . V_3 )
return - 1 ;
return 0 ;
}
static void F_80 ( struct V_6 * V_11 ,
struct V_7 * V_8 ,
struct V_140 * V_141 )
{
struct V_80 * V_81 ;
struct V_88 * V_145 ;
int V_146 , V_147 ;
T_1 V_148 ;
T_5 * V_149 ;
V_146 = V_141 -> V_73 - sizeof( V_99 ) ;
if ( V_146 < 4 ) {
F_2 ( L_19 , V_146 ) ;
return;
}
V_149 = F_81 ( V_141 , sizeof( V_99 ) , sizeof( V_148 ) , & V_148 ) ;
if ( V_149 == NULL )
return;
F_30 ( & V_11 -> V_95 ) ;
V_145 = F_82 ( V_11 , * V_149 ) ;
if ( ! V_145 )
goto V_150;
V_81 = V_145 -> V_151 ;
V_147 = V_145 -> V_152 . V_153 ;
if ( V_147 > V_146 )
V_147 = V_146 ;
if ( F_78 ( & V_145 -> V_152 , V_141 ) ) {
F_2 ( L_20 ) ;
goto V_150;
}
F_83 ( V_81 , V_147 ) ;
V_150:
F_33 ( & V_11 -> V_95 ) ;
}
static void F_84 ( struct V_82 * V_83 )
{
struct V_140 * V_141 ;
struct V_7 * V_8 ;
int V_64 ;
F_64 ( & V_83 -> V_135 ) ;
V_8 = V_83 -> V_86 ;
if ( V_8 == NULL )
goto V_78;
for (; ; ) {
V_141 = F_85 ( V_8 , 0 , 1 , & V_64 ) ;
if ( V_141 == NULL )
break;
F_80 ( & V_83 -> V_11 , V_8 , V_141 ) ;
F_86 ( V_8 , V_141 ) ;
}
V_78:
F_68 ( & V_83 -> V_135 ) ;
}
static void F_87 ( struct V_154 * V_155 )
{
struct V_82 * V_83 =
F_28 ( V_155 , struct V_82 , V_138 ) ;
F_84 ( V_83 ) ;
}
static void F_88 ( struct V_6 * V_11 ,
struct V_7 * V_8 ,
struct V_140 * V_141 )
{
struct V_80 * V_81 ;
struct V_88 * V_145 ;
int V_146 , V_147 ;
T_1 V_148 ;
T_5 * V_149 ;
V_146 = V_141 -> V_73 - sizeof( struct V_156 ) ;
if ( V_146 < 4 ) {
F_2 ( L_21 , V_146 ) ;
return;
}
V_149 = F_81 ( V_141 , sizeof( struct V_156 ) ,
sizeof( V_148 ) , & V_148 ) ;
if ( V_149 == NULL )
return;
F_30 ( & V_11 -> V_95 ) ;
V_145 = F_82 ( V_11 , * V_149 ) ;
if ( ! V_145 )
goto V_150;
V_81 = V_145 -> V_151 ;
if ( ( V_147 = V_145 -> V_152 . V_153 ) > V_146 )
V_147 = V_146 ;
if ( F_89 ( & V_145 -> V_152 , V_141 ) ) {
F_90 ( V_8 , V_157 ) ;
goto V_150;
}
F_90 ( V_8 , V_158 ) ;
F_91 ( V_11 , V_81 , V_147 ) ;
F_83 ( V_81 , V_147 ) ;
V_150:
F_33 ( & V_11 -> V_95 ) ;
}
static void F_92 ( struct V_82 * V_83 )
{
struct V_140 * V_141 ;
struct V_7 * V_8 ;
int V_64 ;
F_64 ( & V_83 -> V_135 ) ;
V_8 = V_83 -> V_86 ;
if ( V_8 == NULL )
goto V_78;
for (; ; ) {
V_141 = F_85 ( V_8 , 0 , 1 , & V_64 ) ;
if ( V_141 == NULL )
break;
F_88 ( & V_83 -> V_11 , V_8 , V_141 ) ;
F_86 ( V_8 , V_141 ) ;
}
V_78:
F_68 ( & V_83 -> V_135 ) ;
}
static void F_93 ( struct V_154 * V_155 )
{
struct V_82 * V_83 =
F_28 ( V_155 , struct V_82 , V_138 ) ;
F_92 ( V_83 ) ;
}
static void F_94 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
F_56 ( & V_8 -> V_128 ) ;
F_2 ( L_22 ) ;
V_11 = F_3 ( V_8 ) ;
if ( V_11 != NULL ) {
struct V_82 * V_83 = F_28 ( V_11 ,
struct V_82 , V_11 ) ;
F_95 ( V_159 , & V_83 -> V_138 ) ;
}
F_59 ( & V_8 -> V_128 ) ;
}
static void F_96 ( struct V_6 * V_11 )
{
F_97 ( V_11 ) ;
}
static inline void F_98 ( struct V_6 * V_11 , struct V_142 * V_143 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
T_4 V_73 , V_160 ;
char * V_161 ;
V_161 = ( ( char * ) & V_83 -> V_162 ) + V_83 -> V_163 ;
V_73 = sizeof( V_83 -> V_162 ) - V_83 -> V_163 ;
V_160 = V_144 ( V_143 , V_161 , V_73 ) ;
V_83 -> V_163 += V_160 ;
if ( V_160 != V_73 )
return;
V_83 -> V_164 = F_12 ( V_83 -> V_162 ) ;
if ( V_83 -> V_164 & V_100 )
V_83 -> V_165 |= V_166 ;
else
V_83 -> V_165 &= ~ V_166 ;
V_83 -> V_164 &= V_167 ;
V_83 -> V_165 &= ~ V_168 ;
V_83 -> V_163 = 0 ;
if ( F_26 ( V_83 -> V_164 < 8 ) ) {
F_2 ( L_23 ) ;
F_96 ( V_11 ) ;
return;
}
F_2 ( L_24 ,
V_83 -> V_164 ) ;
}
static void F_99 ( struct V_82 * V_83 )
{
if ( V_83 -> V_163 == V_83 -> V_164 ) {
V_83 -> V_165 |= V_168 ;
V_83 -> V_163 = 0 ;
if ( V_83 -> V_165 & V_166 ) {
V_83 -> V_165 &= ~ V_169 ;
V_83 -> V_165 |= V_170 ;
V_83 -> V_171 = 0 ;
}
}
}
static inline void F_100 ( struct V_82 * V_83 , struct V_142 * V_143 )
{
T_4 V_73 , V_160 ;
char * V_161 ;
V_73 = sizeof( V_83 -> V_172 ) - V_83 -> V_163 ;
F_2 ( L_25 , V_73 ) ;
V_161 = ( ( char * ) & V_83 -> V_172 ) + V_83 -> V_163 ;
V_160 = V_144 ( V_143 , V_161 , V_73 ) ;
V_83 -> V_163 += V_160 ;
if ( V_160 != V_73 )
return;
V_83 -> V_165 &= ~ V_170 ;
V_83 -> V_165 |= V_173 ;
V_83 -> V_171 = 4 ;
F_2 ( L_26 ,
( V_83 -> V_165 & V_174 ) ? L_27
: L_28 ,
F_12 ( V_83 -> V_172 ) ) ;
F_99 ( V_83 ) ;
}
static inline void F_101 ( struct V_82 * V_83 ,
struct V_142 * V_143 )
{
T_4 V_73 , V_160 ;
T_1 V_59 ;
char * V_161 ;
V_59 = V_83 -> V_163 - sizeof( V_83 -> V_172 ) ;
V_73 = sizeof( V_83 -> V_175 ) - V_59 ;
F_2 ( L_29 , V_73 ) ;
V_161 = ( ( char * ) & V_83 -> V_175 ) + V_59 ;
V_160 = V_144 ( V_143 , V_161 , V_73 ) ;
V_83 -> V_163 += V_160 ;
if ( V_160 != V_73 )
return;
V_83 -> V_165 &= ~ V_173 ;
switch ( F_12 ( V_83 -> V_175 ) ) {
case V_176 :
V_83 -> V_165 |= V_177 ;
V_83 -> V_165 |= V_169 ;
V_83 -> V_165 |= V_174 ;
break;
case V_178 :
V_83 -> V_165 |= V_177 ;
V_83 -> V_165 |= V_169 ;
V_83 -> V_165 &= ~ V_174 ;
break;
default:
F_2 ( L_30 ) ;
F_96 ( & V_83 -> V_11 ) ;
}
F_99 ( V_83 ) ;
}
static inline void F_102 ( struct V_6 * V_11 ,
struct V_142 * V_143 ,
struct V_88 * V_89 )
{
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_54 * V_179 ;
T_4 V_73 ;
T_3 V_180 ;
V_179 = & V_89 -> V_152 ;
if ( V_83 -> V_165 & V_177 ) {
memcpy ( V_179 -> V_77 [ 0 ] . V_52 + V_83 -> V_171 ,
& V_83 -> V_175 ,
sizeof( V_83 -> V_175 ) ) ;
V_83 -> V_171 += sizeof( V_83 -> V_175 ) ;
V_83 -> V_165 &= ~ V_177 ;
}
V_73 = V_143 -> V_3 ;
if ( V_73 > V_83 -> V_164 - V_83 -> V_163 ) {
struct V_142 V_181 ;
V_73 = V_83 -> V_164 - V_83 -> V_163 ;
memcpy ( & V_181 , V_143 , sizeof( V_181 ) ) ;
V_181 . V_3 = V_73 ;
V_180 = F_79 ( V_179 , V_83 -> V_171 ,
& V_181 , V_144 ) ;
V_143 -> V_3 -= V_180 ;
V_143 -> V_59 += V_180 ;
} else
V_180 = F_79 ( V_179 , V_83 -> V_171 ,
V_143 , V_144 ) ;
if ( V_180 > 0 ) {
V_83 -> V_171 += V_180 ;
V_83 -> V_163 += V_180 ;
}
if ( V_180 != V_73 ) {
V_83 -> V_165 &= ~ V_169 ;
F_2 ( L_31 ,
F_12 ( V_83 -> V_172 ) ) ;
F_2 ( L_32
L_33 ,
V_11 , V_83 -> V_171 ,
V_83 -> V_163 , V_83 -> V_164 ) ;
return;
}
F_2 ( L_34 ,
F_12 ( V_83 -> V_172 ) , V_180 ) ;
F_2 ( L_35
L_36 , V_11 , V_83 -> V_171 ,
V_83 -> V_163 , V_83 -> V_164 ) ;
if ( V_83 -> V_171 == V_89 -> V_152 . V_153 )
V_83 -> V_165 &= ~ V_169 ;
else if ( V_83 -> V_163 == V_83 -> V_164 ) {
if ( V_83 -> V_165 & V_166 )
V_83 -> V_165 &= ~ V_169 ;
}
}
static inline int F_103 ( struct V_6 * V_11 ,
struct V_142 * V_143 )
{
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_88 * V_89 ;
F_2 ( L_37 , F_12 ( V_83 -> V_172 ) ) ;
F_30 ( & V_11 -> V_95 ) ;
V_89 = F_82 ( V_11 , V_83 -> V_172 ) ;
if ( ! V_89 ) {
F_2 ( L_38 ,
F_12 ( V_83 -> V_172 ) ) ;
F_33 ( & V_11 -> V_95 ) ;
return - 1 ;
}
F_102 ( V_11 , V_143 , V_89 ) ;
if ( ! ( V_83 -> V_165 & V_169 ) )
F_83 ( V_89 -> V_151 , V_83 -> V_171 ) ;
F_33 ( & V_11 -> V_95 ) ;
return 0 ;
}
static int F_104 ( struct V_6 * V_11 ,
struct V_142 * V_143 )
{
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_88 * V_89 ;
F_30 ( & V_11 -> V_95 ) ;
V_89 = F_105 ( V_11 , V_83 -> V_172 ) ;
if ( V_89 == NULL ) {
F_33 ( & V_11 -> V_95 ) ;
F_106 ( V_182 L_39 ) ;
F_97 ( V_11 ) ;
return - 1 ;
}
F_2 ( L_40 , F_12 ( V_89 -> V_183 ) ) ;
F_102 ( V_11 , V_143 , V_89 ) ;
if ( ! ( V_83 -> V_165 & V_169 ) )
F_107 ( V_89 , V_83 -> V_171 ) ;
F_33 ( & V_11 -> V_95 ) ;
return 0 ;
}
static inline int F_108 ( struct V_6 * V_11 ,
struct V_142 * V_143 )
{
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
return ( V_83 -> V_165 & V_174 ) ?
F_103 ( V_11 , V_143 ) :
F_104 ( V_11 , V_143 ) ;
}
static int F_109 ( struct V_184 * V_185 , struct V_186 * V_186 )
{
int V_90 ;
V_90 = F_110 ( V_185 , L_41 , V_186 , V_187 , 0 ,
V_188 ) ;
if ( V_90 < 0 )
return V_90 ;
return 0 ;
}
static inline int F_108 ( struct V_6 * V_11 ,
struct V_142 * V_143 )
{
return F_103 ( V_11 , V_143 ) ;
}
static void F_111 ( struct V_6 * V_11 ,
struct V_142 * V_143 )
{
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
if ( F_108 ( V_11 , V_143 ) == 0 )
F_99 ( V_83 ) ;
else {
V_83 -> V_165 &= ~ V_169 ;
}
}
static inline void F_112 ( struct V_82 * V_83 , struct V_142 * V_143 )
{
T_4 V_73 ;
V_73 = V_83 -> V_164 - V_83 -> V_163 ;
if ( V_73 > V_143 -> V_3 )
V_73 = V_143 -> V_3 ;
V_143 -> V_3 -= V_73 ;
V_143 -> V_59 += V_73 ;
V_83 -> V_163 += V_73 ;
F_2 ( L_42 , V_73 ) ;
F_99 ( V_83 ) ;
}
static int F_113 ( T_6 * V_189 , struct V_140 * V_141 , unsigned int V_59 , T_4 V_73 )
{
struct V_6 * V_11 = V_189 -> V_190 . V_191 ;
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_142 V_143 = {
. V_141 = V_141 ,
. V_59 = V_59 ,
. V_3 = V_73 ,
} ;
F_2 ( L_43 ) ;
do {
F_114 ( V_83 ) ;
if ( V_83 -> V_165 & V_168 ) {
F_98 ( V_11 , & V_143 ) ;
continue;
}
if ( V_83 -> V_165 & V_170 ) {
F_100 ( V_83 , & V_143 ) ;
continue;
}
if ( V_83 -> V_165 & V_173 ) {
F_101 ( V_83 , & V_143 ) ;
continue;
}
if ( V_83 -> V_165 & V_169 ) {
F_111 ( V_11 , & V_143 ) ;
continue;
}
F_112 ( V_83 , & V_143 ) ;
} while ( V_143 . V_3 );
F_114 ( V_83 ) ;
F_2 ( L_44 ) ;
return V_73 - V_143 . V_3 ;
}
static void F_115 ( struct V_82 * V_83 )
{
struct V_6 * V_11 = & V_83 -> V_11 ;
struct V_7 * V_8 ;
T_6 V_189 = {
. V_3 = 2 * 1024 * 1024 ,
. V_190 . V_191 = V_11 ,
} ;
unsigned long V_192 = 0 ;
int V_193 = 0 ;
F_64 ( & V_83 -> V_135 ) ;
V_8 = V_83 -> V_86 ;
if ( V_8 == NULL )
goto V_78;
for (; ; ) {
F_116 ( V_8 ) ;
V_193 = F_117 ( V_8 , & V_189 , F_113 ) ;
F_118 ( V_8 ) ;
if ( V_193 <= 0 )
break;
V_192 += V_193 ;
V_189 . V_3 = 65536 ;
}
V_78:
F_68 ( & V_83 -> V_135 ) ;
F_119 ( V_11 , V_193 , V_192 ) ;
}
static void F_120 ( struct V_154 * V_155 )
{
struct V_82 * V_83 =
F_28 ( V_155 , struct V_82 , V_138 ) ;
F_115 ( V_83 ) ;
}
static void F_121 ( struct V_7 * V_8 )
{
struct V_82 * V_83 ;
struct V_6 * V_11 ;
F_2 ( L_45 ) ;
F_56 ( & V_8 -> V_128 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_78;
V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
if ( V_11 -> V_136 )
V_11 -> V_136 = 0 ;
F_95 ( V_159 , & V_83 -> V_138 ) ;
V_78:
F_59 ( & V_8 -> V_128 ) ;
}
static void F_122 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
struct V_82 * V_83 ;
F_56 ( & V_8 -> V_128 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_78;
F_2 ( L_46 , V_11 ) ;
F_2 ( L_47 ,
V_8 -> V_130 , F_31 ( V_11 ) ,
F_123 ( V_8 , V_194 ) ,
F_123 ( V_8 , V_195 ) ,
V_8 -> V_196 ) ;
V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
F_124 ( V_11 , V_8 -> V_132 ) ;
switch ( V_8 -> V_130 ) {
case V_197 :
F_125 ( & V_11 -> V_95 ) ;
if ( ! F_126 ( V_11 ) ) {
V_83 -> V_163 = 0 ;
V_83 -> V_164 = 0 ;
V_83 -> V_171 = 0 ;
V_83 -> V_165 =
V_168 | V_170 ;
V_11 -> V_198 ++ ;
F_51 ( V_199 , & V_83 -> V_200 ) ;
F_127 ( V_11 ) ;
F_58 ( V_11 , - V_91 ) ;
}
F_128 ( & V_11 -> V_95 ) ;
break;
case V_201 :
V_11 -> V_198 ++ ;
V_11 -> V_136 = 0 ;
F_45 ( V_127 , & V_11 -> V_119 ) ;
F_50 () ;
F_51 ( V_202 , & V_11 -> V_119 ) ;
F_51 ( V_118 , & V_11 -> V_119 ) ;
F_52 () ;
break;
case V_203 :
V_11 -> V_198 ++ ;
F_51 ( V_202 , & V_11 -> V_119 ) ;
F_96 ( V_11 ) ;
case V_204 :
if ( V_11 -> V_136 < V_205 )
V_11 -> V_136 = V_205 ;
break;
case V_206 :
F_45 ( V_127 , & V_11 -> V_119 ) ;
F_50 () ;
F_51 ( V_202 , & V_11 -> V_119 ) ;
F_52 () ;
break;
case V_131 :
if ( F_129 ( V_199 ,
& V_83 -> V_200 ) )
F_127 ( V_11 ) ;
F_53 ( V_11 ) ;
}
V_78:
F_59 ( & V_8 -> V_128 ) ;
}
static void F_130 ( struct V_7 * V_8 )
{
struct V_207 * V_208 ;
struct V_6 * V_11 ;
if ( ! V_8 -> V_132 )
return;
F_51 ( V_209 , & V_8 -> V_132 -> V_61 ) ;
if ( F_26 ( ! ( V_11 = F_3 ( V_8 ) ) ) )
return;
F_131 () ;
V_208 = F_132 ( V_8 -> V_210 ) ;
if ( ! V_208 || F_129 ( V_211 , & V_208 -> V_61 ) == 0 )
goto V_78;
F_133 ( V_11 ) ;
V_78:
F_134 () ;
}
static void F_135 ( struct V_7 * V_8 )
{
F_56 ( & V_8 -> V_128 ) ;
if ( F_37 ( V_8 ) )
F_130 ( V_8 ) ;
F_59 ( & V_8 -> V_128 ) ;
}
static void F_136 ( struct V_7 * V_8 )
{
F_56 ( & V_8 -> V_128 ) ;
if ( F_43 ( V_8 ) )
F_130 ( V_8 ) ;
F_59 ( & V_8 -> V_128 ) ;
}
static void F_137 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_7 * V_8 = V_83 -> V_86 ;
if ( V_83 -> V_212 ) {
V_8 -> V_213 |= V_214 ;
V_8 -> V_215 = V_83 -> V_212 * V_11 -> V_216 * 2 ;
}
if ( V_83 -> V_217 ) {
V_8 -> V_213 |= V_218 ;
V_8 -> V_219 = V_83 -> V_217 * V_11 -> V_216 * 2 ;
V_8 -> V_97 ( V_8 ) ;
}
}
static void F_138 ( struct V_6 * V_11 , T_4 V_217 , T_4 V_212 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
V_83 -> V_217 = 0 ;
if ( V_217 )
V_83 -> V_217 = V_217 + 1024 ;
V_83 -> V_212 = 0 ;
if ( V_212 )
V_83 -> V_212 = V_212 + 1024 ;
F_137 ( V_11 ) ;
}
static void F_139 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
F_91 ( V_11 , V_81 , - V_220 ) ;
}
static unsigned short F_140 ( void )
{
unsigned short V_221 = V_222 - V_223 ;
unsigned short rand = ( unsigned short ) F_141 () % V_221 ;
return rand + V_223 ;
}
static void F_142 ( struct V_39 * V_7 )
{
int V_224 = 1 ;
F_143 ( V_7 , V_225 , V_226 ,
( char * ) & V_224 , sizeof( V_224 ) ) ;
}
static unsigned short F_144 ( struct V_39 * V_7 )
{
struct V_227 V_4 ;
int V_153 ;
unsigned short V_228 = 0 ;
if ( F_145 ( V_7 , (struct V_10 * ) & V_4 , & V_153 ) < 0 )
goto V_78;
switch ( V_4 . V_229 ) {
case V_28 :
V_228 = F_146 ( ( (struct V_15 * ) & V_4 ) -> V_230 ) ;
break;
case V_25 :
V_228 = F_146 ( ( (struct V_14 * ) & V_4 ) -> V_231 ) ;
}
V_78:
return V_228 ;
}
static void F_147 ( struct V_6 * V_11 , unsigned short V_228 )
{
F_2 ( L_48 , V_11 , V_228 ) ;
F_148 ( F_4 ( V_11 ) , V_228 ) ;
F_17 ( V_11 ) ;
}
static void F_149 ( struct V_82 * V_83 , struct V_39 * V_7 )
{
if ( V_83 -> V_232 == 0 )
V_83 -> V_232 = F_144 ( V_7 ) ;
}
static unsigned short F_150 ( struct V_82 * V_83 )
{
unsigned short V_228 = V_83 -> V_232 ;
if ( V_228 == 0 && V_83 -> V_11 . V_233 )
V_228 = F_140 () ;
return V_228 ;
}
static unsigned short F_151 ( struct V_82 * V_83 , unsigned short V_228 )
{
if ( V_83 -> V_232 != 0 )
V_83 -> V_232 = 0 ;
if ( ! V_83 -> V_11 . V_233 )
return 0 ;
if ( V_228 <= V_223 || V_228 > V_222 )
return V_222 ;
return -- V_228 ;
}
static int F_152 ( struct V_82 * V_83 , struct V_39 * V_7 )
{
struct V_227 V_234 ;
int V_64 , V_235 = 0 ;
unsigned short V_228 = F_150 ( V_83 ) ;
unsigned short V_236 ;
if ( V_228 == 0 )
return 0 ;
memcpy ( & V_234 , & V_83 -> V_237 , V_83 -> V_11 . V_40 ) ;
do {
F_148 ( (struct V_10 * ) & V_234 , V_228 ) ;
V_64 = F_153 ( V_7 , (struct V_10 * ) & V_234 ,
V_83 -> V_11 . V_40 ) ;
if ( V_64 == 0 ) {
V_83 -> V_232 = V_228 ;
break;
}
V_236 = V_228 ;
V_228 = F_151 ( V_83 , V_228 ) ;
if ( V_228 > V_236 )
V_235 ++ ;
} while ( V_64 == - V_115 && V_235 != 2 );
if ( V_234 . V_229 == V_25 )
F_2 ( L_49 , V_104 ,
& ( (struct V_14 * ) & V_234 ) -> V_26 ,
V_228 , V_64 ? L_50 : L_51 , V_64 ) ;
else
F_2 ( L_52 , V_104 ,
& ( (struct V_15 * ) & V_234 ) -> V_29 ,
V_228 , V_64 ? L_50 : L_51 , V_64 ) ;
return V_64 ;
}
static void F_154 ( struct V_80 * V_81 )
{
F_155 ( V_81 -> V_238 ) ;
}
static void F_156 ( struct V_6 * V_11 , unsigned short V_228 )
{
}
static inline void F_157 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_158 ( V_8 , L_53 ,
& V_239 [ 1 ] , L_54 , & V_240 [ 1 ] ) ;
}
static inline void F_159 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_158 ( V_8 , L_55 ,
& V_239 [ 0 ] , L_56 , & V_240 [ 0 ] ) ;
}
static inline void F_160 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_158 ( V_8 , L_57 ,
& V_239 [ 1 ] , L_58 , & V_240 [ 1 ] ) ;
}
static inline void F_161 ( int V_241 , struct V_39 * V_7 )
{
F_162 ( F_163 ( V_7 -> V_8 ) ) ;
if ( F_163 ( V_7 -> V_8 ) )
return;
switch ( V_241 ) {
case V_20 :
F_157 ( V_7 ) ;
break;
case V_25 :
F_159 ( V_7 ) ;
break;
case V_28 :
F_160 ( V_7 ) ;
break;
}
}
static inline void F_161 ( int V_241 , struct V_39 * V_7 )
{
}
static void F_164 ( struct V_154 * V_155 )
{
}
static struct V_39 * F_165 ( struct V_6 * V_11 ,
struct V_82 * V_83 , int V_241 , int type ,
int V_33 , bool V_242 )
{
struct V_39 * V_7 ;
int V_64 ;
V_64 = F_166 ( V_11 -> V_243 , V_241 , type , V_33 , & V_7 , 1 ) ;
if ( V_64 < 0 ) {
F_2 ( L_59 ,
V_33 , - V_64 ) ;
goto V_78;
}
F_161 ( V_241 , V_7 ) ;
if ( V_242 )
F_142 ( V_7 ) ;
V_64 = F_152 ( V_83 , V_7 ) ;
if ( V_64 ) {
F_70 ( V_7 ) ;
goto V_78;
}
return V_7 ;
V_78:
return F_167 ( V_64 ) ;
}
static int F_168 ( struct V_6 * V_11 ,
struct V_39 * V_7 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 ,
V_11 ) ;
if ( ! V_83 -> V_86 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
F_65 ( & V_8 -> V_128 ) ;
F_47 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_121 = F_94 ;
V_8 -> V_97 = F_135 ;
V_8 -> V_126 = F_55 ;
V_8 -> V_244 = V_245 ;
F_66 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_67 ( & V_8 -> V_128 ) ;
}
V_11 -> V_246 . V_247 ++ ;
V_11 -> V_246 . V_248 = V_249 ;
return F_169 ( V_7 , F_4 ( V_11 ) , V_11 -> V_40 , 0 ) ;
}
static int F_170 ( struct V_82 * V_83 )
{
struct V_6 * V_11 = & V_83 -> V_11 ;
struct V_39 * V_7 ;
int V_102 = - V_250 ;
V_102 = F_166 ( V_11 -> V_243 , V_20 ,
V_251 , 0 , & V_7 , 1 ) ;
if ( V_102 < 0 ) {
F_2 ( L_60
L_61 , - V_102 ) ;
goto V_78;
}
F_161 ( V_20 , V_7 ) ;
F_2 ( L_62 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
V_102 = F_168 ( V_11 , V_7 ) ;
F_171 ( V_11 , V_7 , V_102 ) ;
switch ( V_102 ) {
case 0 :
F_2 ( L_63 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
F_172 ( V_11 ) ;
case - V_105 :
break;
case - V_252 :
F_2 ( L_64 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
break;
case - V_111 :
F_2 ( L_65 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
break;
default:
F_106 ( V_253 L_66 ,
V_104 , - V_102 ,
V_11 -> V_22 [ V_23 ] ) ;
}
V_78:
F_127 ( V_11 ) ;
F_58 ( V_11 , V_102 ) ;
return V_102 ;
}
static void F_173 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
int V_90 ;
if ( F_174 ( V_81 ) ) {
F_175 ( V_81 , - V_96 ) ;
return;
}
V_90 = F_170 ( V_83 ) ;
if ( V_90 && ! F_176 ( V_81 ) )
F_177 ( 15000 ) ;
}
static void F_178 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 ,
V_11 ) ;
if ( ! V_83 -> V_86 )
return;
if ( F_61 ( & V_11 -> V_133 ) )
F_179 ( V_83 -> V_86 ) ;
}
static int
F_180 ( struct V_6 * V_11 )
{
struct V_82 * V_254 = F_28 ( V_11 , struct V_82 , V_11 ) ;
if ( F_181 ( & V_11 -> V_133 ) != 1 )
return 0 ;
if ( F_182 ( & V_11 -> V_119 , V_255 , V_256 ) )
return - V_257 ;
if ( V_254 -> V_86 )
F_179 ( V_254 -> V_86 ) ;
F_46 ( V_11 , NULL ) ;
return 0 ;
}
static void
F_183 ( struct V_6 * V_11 )
{
struct V_82 * V_254 = F_28 ( V_11 , struct V_82 , V_11 ) ;
if ( ! F_184 ( & V_11 -> V_133 ) )
return;
if ( F_182 ( & V_11 -> V_119 , V_255 , V_256 ) )
return;
if ( V_254 -> V_86 )
F_62 ( V_254 -> V_86 ) ;
F_46 ( V_11 , NULL ) ;
}
static void F_178 ( struct V_6 * V_11 )
{
}
static int
F_180 ( struct V_6 * V_11 )
{
return - V_258 ;
}
static void
F_183 ( struct V_6 * V_11 )
{
}
static void F_185 ( struct V_6 * V_11 , struct V_39 * V_7 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
if ( ! V_83 -> V_86 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
F_65 ( & V_8 -> V_128 ) ;
F_47 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_121 = F_94 ;
V_8 -> V_97 = F_135 ;
V_8 -> V_244 = V_245 ;
F_172 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_178 ( V_11 ) ;
F_67 ( & V_8 -> V_128 ) ;
}
F_137 ( V_11 ) ;
}
static void F_186 ( struct V_154 * V_155 )
{
struct V_82 * V_83 =
F_28 ( V_155 , struct V_82 , V_137 . V_155 ) ;
struct V_6 * V_11 = & V_83 -> V_11 ;
struct V_39 * V_7 = V_83 -> V_7 ;
int V_102 = - V_250 ;
V_7 = F_165 ( V_11 , V_83 ,
F_4 ( V_11 ) -> V_19 , V_259 ,
V_260 , false ) ;
if ( F_187 ( V_7 ) )
goto V_78;
F_2 ( L_67
L_68 , V_11 ,
V_11 -> V_22 [ V_35 ] ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ) ;
F_185 ( V_11 , V_7 ) ;
F_171 ( V_11 , V_7 , 0 ) ;
V_102 = 0 ;
V_78:
F_188 ( V_11 , V_83 ) ;
F_127 ( V_11 ) ;
F_58 ( V_11 , V_102 ) ;
}
static void F_189 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
if ( V_7 == NULL )
return;
if ( F_31 ( V_11 ) ) {
F_63 ( V_7 , V_134 ) ;
F_190 ( V_11 , V_7 ) ;
} else
F_60 ( V_83 ) ;
}
static int F_191 ( struct V_6 * V_11 , struct V_39 * V_7 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
int V_90 = - V_96 ;
if ( ! V_83 -> V_86 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
unsigned int V_261 = V_11 -> V_262 -> V_263 / V_264 ;
unsigned int V_265 = V_11 -> V_262 -> V_266 + 1 ;
unsigned int V_267 = 1 ;
unsigned int V_268 ;
F_143 ( V_7 , V_225 , V_269 ,
( char * ) & V_267 , sizeof( V_267 ) ) ;
F_143 ( V_7 , V_270 , V_271 ,
( char * ) & V_261 , sizeof( V_261 ) ) ;
F_143 ( V_7 , V_270 , V_272 ,
( char * ) & V_261 , sizeof( V_261 ) ) ;
F_143 ( V_7 , V_270 , V_273 ,
( char * ) & V_265 , sizeof( V_265 ) ) ;
V_268 = F_192 ( V_11 -> V_262 -> V_263 ) *
( V_11 -> V_262 -> V_266 + 1 ) ;
F_143 ( V_7 , V_270 , V_274 ,
( char * ) & V_268 , sizeof( V_268 ) ) ;
F_65 ( & V_8 -> V_128 ) ;
F_47 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_121 = F_121 ;
V_8 -> V_123 = F_122 ;
V_8 -> V_97 = F_136 ;
V_8 -> V_126 = F_55 ;
V_8 -> V_244 = V_245 ;
F_193 ( V_8 , V_275 ) ;
F_194 ( V_8 ) -> V_276 |= V_277 ;
F_66 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_67 ( & V_8 -> V_128 ) ;
}
if ( ! F_41 ( V_11 ) )
goto V_78;
F_178 ( V_11 ) ;
V_11 -> V_246 . V_247 ++ ;
V_11 -> V_246 . V_248 = V_249 ;
F_45 ( V_199 , & V_83 -> V_200 ) ;
V_90 = F_169 ( V_7 , F_4 ( V_11 ) , V_11 -> V_40 , V_278 ) ;
switch ( V_90 ) {
case 0 :
F_149 ( V_83 , V_7 ) ;
case - V_279 :
if ( V_11 -> V_136 < V_205 )
V_11 -> V_136 = V_205 ;
}
V_78:
return V_90 ;
}
static void F_195 ( struct V_154 * V_155 )
{
struct V_82 * V_83 =
F_28 ( V_155 , struct V_82 , V_137 . V_155 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
struct V_6 * V_11 = & V_83 -> V_11 ;
int V_102 = - V_250 ;
if ( ! V_7 ) {
V_7 = F_165 ( V_11 , V_83 ,
F_4 ( V_11 ) -> V_19 , V_251 ,
V_280 , true ) ;
if ( F_187 ( V_7 ) ) {
V_102 = F_196 ( V_7 ) ;
goto V_78;
}
}
F_2 ( L_67
L_68 , V_11 ,
V_11 -> V_22 [ V_35 ] ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ) ;
V_102 = F_191 ( V_11 , V_7 ) ;
F_171 ( V_11 , V_7 , V_102 ) ;
F_2 ( L_69 ,
V_11 , - V_102 , F_31 ( V_11 ) ,
V_7 -> V_8 -> V_130 ) ;
switch ( V_102 ) {
default:
F_106 ( L_70 ,
V_104 , V_102 ) ;
case - V_281 :
F_96 ( V_11 ) ;
break;
case 0 :
case - V_279 :
case - V_282 :
F_188 ( V_11 , V_83 ) ;
return;
case - V_258 :
case - V_111 :
case - V_114 :
case - V_110 :
case - V_115 :
case - V_105 :
F_96 ( V_11 ) ;
goto V_78;
}
V_102 = - V_91 ;
V_78:
F_188 ( V_11 , V_83 ) ;
F_127 ( V_11 ) ;
F_58 ( V_11 , V_102 ) ;
}
static void F_197 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
F_162 ( ! F_198 ( V_11 , V_81 , V_83 ) ) ;
if ( V_83 -> V_7 != NULL ) {
F_2 ( L_71
L_72 ,
V_11 , V_11 -> V_136 / V_264 ) ;
F_60 ( V_83 ) ;
F_199 ( V_159 ,
& V_83 -> V_137 ,
V_11 -> V_136 ) ;
V_11 -> V_136 <<= 1 ;
if ( V_11 -> V_136 < V_205 )
V_11 -> V_136 = V_205 ;
if ( V_11 -> V_136 > V_283 )
V_11 -> V_136 = V_283 ;
} else {
F_2 ( L_73 , V_11 ) ;
F_199 ( V_159 ,
& V_83 -> V_137 , 0 ) ;
}
}
static void F_200 ( struct V_6 * V_11 , struct V_284 * V_285 )
{
long V_286 = 0 ;
if ( F_31 ( V_11 ) )
V_286 = ( long ) ( V_249 - V_11 -> V_287 ) / V_264 ;
F_201 ( V_285 , L_74
L_75 ,
V_11 -> V_246 . V_288 ,
V_11 -> V_246 . V_247 ,
V_11 -> V_246 . V_289 ,
V_286 ,
V_11 -> V_246 . V_290 ,
V_11 -> V_246 . V_291 ,
V_11 -> V_246 . V_292 ,
V_11 -> V_246 . V_293 ,
V_11 -> V_246 . V_294 ,
V_11 -> V_246 . V_295 ,
V_11 -> V_246 . V_296 ,
V_11 -> V_246 . V_297 ) ;
}
static void F_202 ( struct V_6 * V_11 , struct V_284 * V_285 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
F_201 ( V_285 , L_76
L_77 ,
V_83 -> V_232 ,
V_11 -> V_246 . V_288 ,
V_11 -> V_246 . V_290 ,
V_11 -> V_246 . V_291 ,
V_11 -> V_246 . V_292 ,
V_11 -> V_246 . V_293 ,
V_11 -> V_246 . V_294 ,
V_11 -> V_246 . V_295 ,
V_11 -> V_246 . V_296 ,
V_11 -> V_246 . V_297 ) ;
}
static void F_203 ( struct V_6 * V_11 , struct V_284 * V_285 )
{
struct V_82 * V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
long V_286 = 0 ;
if ( F_31 ( V_11 ) )
V_286 = ( long ) ( V_249 - V_11 -> V_287 ) / V_264 ;
F_201 ( V_285 , L_78
L_75 ,
V_83 -> V_232 ,
V_11 -> V_246 . V_288 ,
V_11 -> V_246 . V_247 ,
V_11 -> V_246 . V_289 ,
V_286 ,
V_11 -> V_246 . V_290 ,
V_11 -> V_246 . V_291 ,
V_11 -> V_246 . V_292 ,
V_11 -> V_246 . V_293 ,
V_11 -> V_246 . V_294 ,
V_11 -> V_246 . V_295 ,
V_11 -> V_246 . V_296 ,
V_11 -> V_246 . V_297 ) ;
}
static void * F_204 ( struct V_80 * V_81 , T_4 V_60 )
{
struct V_58 * V_58 ;
struct V_298 * V_4 ;
F_162 ( V_60 > V_299 - sizeof( struct V_298 ) ) ;
if ( V_60 > V_299 - sizeof( struct V_298 ) )
return NULL ;
V_58 = F_205 ( V_24 ) ;
if ( ! V_58 )
return NULL ;
V_4 = F_206 ( V_58 ) ;
V_4 -> V_73 = V_299 ;
return V_4 -> V_191 ;
}
static void F_207 ( void * V_300 )
{
struct V_298 * V_4 ;
if ( ! V_300 )
return;
V_4 = F_28 ( V_300 , struct V_298 , V_191 ) ;
F_208 ( ( unsigned long ) V_4 ) ;
}
static int F_209 ( struct V_88 * V_89 )
{
int V_73 ;
struct V_54 * V_301 = & V_89 -> V_101 ;
struct V_6 * V_11 = V_89 -> V_85 ;
struct V_82 * V_83 =
F_28 ( V_11 , struct V_82 , V_11 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
unsigned long V_302 ;
unsigned long V_303 ;
F_34 ( V_301 ) ;
V_303 = ( unsigned long ) V_301 -> V_79 [ 0 ] . V_52 & ~ V_69 ;
V_302 = ( unsigned long ) V_301 -> V_77 [ 0 ] . V_52 & ~ V_69 ;
V_73 = F_210 ( V_7 , V_301 ,
F_211 ( V_301 -> V_77 [ 0 ] . V_52 ) , V_302 ,
V_301 -> V_79 [ 0 ] . V_52 , V_303 ) ;
if ( V_73 != V_301 -> V_73 ) {
F_106 ( V_304 L_79 ) ;
V_73 = - V_91 ;
}
return V_73 ;
}
static int F_212 ( struct V_80 * V_81 )
{
struct V_88 * V_89 = V_81 -> V_84 ;
struct V_305 * V_11 ;
int V_73 ;
F_2 ( L_80 , F_12 ( V_89 -> V_183 ) ) ;
V_11 = V_89 -> V_85 -> V_306 ;
if ( ! F_213 ( & V_11 -> V_307 ) ) {
F_214 ( & V_11 -> V_308 , V_81 , NULL ) ;
if ( ! F_213 ( & V_11 -> V_307 ) )
return - V_91 ;
F_215 ( & V_11 -> V_308 , V_81 ) ;
}
if ( F_216 ( V_309 , & V_11 -> V_310 ) )
V_73 = - V_96 ;
else
V_73 = F_209 ( V_89 ) ;
F_68 ( & V_11 -> V_307 ) ;
if ( V_73 > 0 )
V_73 = 0 ;
return V_73 ;
}
static void F_217 ( struct V_6 * V_11 )
{
}
static void F_218 ( struct V_6 * V_11 )
{
F_2 ( L_81 , V_11 ) ;
F_72 ( V_11 ) ;
F_77 ( V_139 ) ;
}
static int F_219 ( const int V_241 , struct V_10 * V_16 )
{
static const struct V_14 sin = {
. V_311 = V_25 ,
. V_26 . V_27 = F_220 ( V_312 ) ,
} ;
static const struct V_15 V_17 = {
. V_313 = V_28 ,
. V_29 = V_314 ,
} ;
switch ( V_241 ) {
case V_20 :
break;
case V_25 :
memcpy ( V_16 , & sin , sizeof( sin ) ) ;
break;
case V_28 :
memcpy ( V_16 , & V_17 , sizeof( V_17 ) ) ;
break;
default:
F_2 ( L_82 , V_104 ) ;
return - V_315 ;
}
return 0 ;
}
static struct V_6 * F_221 ( struct V_316 * args ,
unsigned int V_317 ,
unsigned int V_318 )
{
struct V_6 * V_11 ;
struct V_82 * V_319 ;
if ( args -> V_40 > sizeof( V_11 -> V_12 ) ) {
F_2 ( L_83 ) ;
return F_167 ( - V_320 ) ;
}
V_11 = F_222 ( args -> V_186 , sizeof( * V_319 ) , V_317 ,
V_318 ) ;
if ( V_11 == NULL ) {
F_2 ( L_84
L_85 ) ;
return F_167 ( - V_321 ) ;
}
V_319 = F_28 ( V_11 , struct V_82 , V_11 ) ;
F_223 ( & V_319 -> V_135 ) ;
memcpy ( & V_11 -> V_12 , args -> V_322 , args -> V_40 ) ;
V_11 -> V_40 = args -> V_40 ;
if ( args -> V_237 )
memcpy ( & V_319 -> V_237 , args -> V_237 , args -> V_40 ) ;
else {
int V_64 ;
V_64 = F_219 ( args -> V_322 -> V_19 ,
(struct V_10 * ) & V_319 -> V_237 ) ;
if ( V_64 != 0 ) {
F_73 ( V_11 ) ;
return F_167 ( V_64 ) ;
}
}
return V_11 ;
}
static struct V_6 * F_224 ( struct V_316 * args )
{
struct V_13 * V_18 = (struct V_13 * ) args -> V_322 ;
struct V_82 * V_83 ;
struct V_6 * V_11 ;
struct V_6 * V_90 ;
V_11 = F_221 ( args , V_323 ,
V_324 ) ;
if ( F_187 ( V_11 ) )
return V_11 ;
V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_325 = 0 ;
V_11 -> V_326 = sizeof( V_99 ) / sizeof( T_1 ) ;
V_11 -> V_327 = V_328 ;
V_11 -> V_329 = V_330 ;
V_11 -> V_136 = V_205 ;
V_11 -> V_331 = V_332 ;
V_11 -> V_70 = & V_333 ;
V_11 -> V_262 = & V_334 ;
F_225 ( & V_83 -> V_138 , F_87 ) ;
F_226 ( & V_83 -> V_137 ,
F_164 ) ;
switch ( V_18 -> V_335 ) {
case V_20 :
if ( V_18 -> V_21 [ 0 ] != '/' ) {
F_2 ( L_86 ,
V_18 -> V_21 ) ;
V_90 = F_167 ( - V_258 ) ;
goto V_336;
}
F_155 ( V_11 ) ;
F_16 ( V_11 , L_87 , V_337 ) ;
V_90 = F_167 ( F_170 ( V_83 ) ) ;
if ( V_90 )
goto V_336;
break;
default:
V_90 = F_167 ( - V_315 ) ;
goto V_336;
}
F_2 ( L_88 ,
V_11 -> V_22 [ V_23 ] ) ;
if ( F_227 ( V_139 ) )
return V_11 ;
V_90 = F_167 ( - V_258 ) ;
V_336:
F_72 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_228 ( struct V_316 * args )
{
struct V_10 * V_12 = args -> V_322 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_6 * V_90 ;
V_11 = F_221 ( args , V_338 ,
V_338 ) ;
if ( F_187 ( V_11 ) )
return V_11 ;
V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_325 = V_260 ;
V_11 -> V_326 = 0 ;
V_11 -> V_327 = ( 1U << 16 ) - ( V_339 << 3 ) ;
V_11 -> V_329 = V_330 ;
V_11 -> V_136 = V_340 ;
V_11 -> V_331 = V_332 ;
V_11 -> V_70 = & V_341 ;
V_11 -> V_262 = & V_342 ;
F_225 ( & V_83 -> V_138 , F_93 ) ;
F_226 ( & V_83 -> V_137 , F_186 ) ;
switch ( V_12 -> V_19 ) {
case V_25 :
if ( ( (struct V_14 * ) V_12 ) -> V_231 != F_229 ( 0 ) )
F_155 ( V_11 ) ;
F_16 ( V_11 , L_89 , V_343 ) ;
break;
case V_28 :
if ( ( (struct V_15 * ) V_12 ) -> V_230 != F_229 ( 0 ) )
F_155 ( V_11 ) ;
F_16 ( V_11 , L_89 , V_344 ) ;
break;
default:
V_90 = F_167 ( - V_315 ) ;
goto V_336;
}
if ( F_41 ( V_11 ) )
F_2 ( L_90 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
else
F_2 ( L_91 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_35 ] ) ;
if ( F_227 ( V_139 ) )
return V_11 ;
V_90 = F_167 ( - V_258 ) ;
V_336:
F_72 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_230 ( struct V_316 * args )
{
struct V_10 * V_12 = args -> V_322 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_6 * V_90 ;
unsigned int V_318 = V_324 ;
if ( args -> V_61 & V_345 )
V_318 = V_346 ;
V_11 = F_221 ( args , V_323 ,
V_318 ) ;
if ( F_187 ( V_11 ) )
return V_11 ;
V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_325 = V_280 ;
V_11 -> V_326 = sizeof( V_99 ) / sizeof( T_1 ) ;
V_11 -> V_327 = V_328 ;
V_11 -> V_329 = V_330 ;
V_11 -> V_136 = V_205 ;
V_11 -> V_331 = V_332 ;
V_11 -> V_70 = & V_347 ;
V_11 -> V_262 = & V_348 ;
F_225 ( & V_83 -> V_138 , F_120 ) ;
F_226 ( & V_83 -> V_137 , F_195 ) ;
switch ( V_12 -> V_19 ) {
case V_25 :
if ( ( (struct V_14 * ) V_12 ) -> V_231 != F_229 ( 0 ) )
F_155 ( V_11 ) ;
F_16 ( V_11 , L_92 , V_349 ) ;
break;
case V_28 :
if ( ( (struct V_15 * ) V_12 ) -> V_230 != F_229 ( 0 ) )
F_155 ( V_11 ) ;
F_16 ( V_11 , L_92 , V_350 ) ;
break;
default:
V_90 = F_167 ( - V_315 ) ;
goto V_336;
}
if ( F_41 ( V_11 ) )
F_2 ( L_90 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
else
F_2 ( L_91 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_35 ] ) ;
if ( F_227 ( V_139 ) )
return V_11 ;
V_90 = F_167 ( - V_258 ) ;
V_336:
F_72 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_231 ( struct V_316 * args )
{
struct V_10 * V_12 = args -> V_322 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_351 * V_352 ;
struct V_6 * V_90 ;
V_11 = F_221 ( args , V_323 ,
V_323 ) ;
if ( F_187 ( V_11 ) )
return V_11 ;
V_83 = F_28 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_325 = V_280 ;
V_11 -> V_326 = sizeof( V_99 ) / sizeof( T_1 ) ;
V_11 -> V_327 = V_328 ;
V_11 -> V_262 = & V_348 ;
F_155 ( V_11 ) ;
V_11 -> V_329 = 0 ;
V_11 -> V_136 = 0 ;
V_11 -> V_331 = 0 ;
V_11 -> V_70 = & V_353 ;
switch ( V_12 -> V_19 ) {
case V_25 :
F_16 ( V_11 , L_92 ,
V_349 ) ;
break;
case V_28 :
F_16 ( V_11 , L_92 ,
V_350 ) ;
break;
default:
V_90 = F_167 ( - V_315 ) ;
goto V_336;
}
F_2 ( L_90 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
F_232 ( V_11 ) ;
args -> V_306 -> V_354 = V_11 ;
V_11 -> V_306 = args -> V_306 ;
V_352 = F_28 ( args -> V_306 , struct V_351 , V_355 ) ;
V_83 -> V_7 = V_352 -> V_356 ;
V_83 -> V_86 = V_352 -> V_357 ;
F_172 ( V_11 ) ;
if ( F_227 ( V_139 ) )
return V_11 ;
args -> V_306 -> V_354 = NULL ;
F_233 ( V_11 ) ;
V_90 = F_167 ( - V_258 ) ;
V_336:
F_72 ( V_11 ) ;
return V_90 ;
}
int F_234 ( void )
{
#if F_235 ( V_358 )
if ( ! V_359 )
V_359 = F_236 ( V_360 ) ;
#endif
F_237 ( & V_361 ) ;
F_237 ( & V_362 ) ;
F_237 ( & V_363 ) ;
F_237 ( & V_364 ) ;
return 0 ;
}
void F_238 ( void )
{
#if F_235 ( V_358 )
if ( V_359 ) {
F_239 ( V_359 ) ;
V_359 = NULL ;
}
#endif
F_240 ( & V_361 ) ;
F_240 ( & V_362 ) ;
F_240 ( & V_363 ) ;
F_240 ( & V_364 ) ;
}
static int F_241 ( const char * V_365 ,
const struct V_366 * V_367 ,
unsigned int V_368 , unsigned int V_369 )
{
unsigned int V_370 ;
int V_90 ;
if ( ! V_365 )
return - V_258 ;
V_90 = F_242 ( V_365 , 0 , & V_370 ) ;
if ( V_90 == - V_258 || V_370 < V_368 || V_370 > V_369 )
return - V_258 ;
* ( ( unsigned int * ) V_367 -> V_190 ) = V_370 ;
return 0 ;
}
static int F_243 ( const char * V_365 , const struct V_366 * V_367 )
{
return F_241 ( V_365 , V_367 ,
V_371 ,
V_372 ) ;
}
static int F_244 ( const char * V_365 ,
const struct V_366 * V_367 )
{
return F_241 ( V_365 , V_367 ,
V_373 ,
V_374 ) ;
}
static int F_245 ( const char * V_365 ,
const struct V_366 * V_367 )
{
return F_241 ( V_365 , V_367 ,
V_373 ,
V_346 ) ;
}

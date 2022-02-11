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
F_27 ( V_77 , & V_7 -> V_61 ) ;
if ( V_43 != 0 ) {
V_12 = NULL ;
V_40 = 0 ;
}
if ( V_43 < V_55 -> V_78 [ 0 ] . V_53 || V_12 != NULL ) {
unsigned int V_73 = V_55 -> V_78 [ 0 ] . V_53 - V_43 ;
V_63 -= V_73 ;
V_64 = F_20 ( V_7 , V_12 , V_40 , & V_55 -> V_78 [ 0 ] , V_43 , V_63 != 0 ) ;
if ( V_63 == 0 || V_64 != V_73 )
goto V_79;
* V_57 += V_64 ;
V_43 = 0 ;
} else
V_43 -= V_55 -> V_78 [ 0 ] . V_53 ;
if ( V_43 < V_55 -> V_65 ) {
unsigned int V_73 = V_55 -> V_65 - V_43 ;
V_63 -= V_73 ;
V_64 = F_22 ( V_7 , V_55 , V_43 , V_63 != 0 , V_56 , & V_75 ) ;
* V_57 += V_75 ;
if ( V_63 == 0 || V_75 != V_73 )
goto V_79;
V_43 = 0 ;
} else
V_43 -= V_55 -> V_65 ;
if ( V_43 >= V_55 -> V_80 [ 0 ] . V_53 )
return 0 ;
V_64 = F_20 ( V_7 , NULL , 0 , & V_55 -> V_80 [ 0 ] , V_43 , 0 ) ;
V_79:
if ( V_64 > 0 ) {
* V_57 += V_64 ;
V_64 = 0 ;
}
return V_64 ;
}
static void F_28 ( struct V_81 * V_82 )
{
struct V_83 * V_84 = F_29 ( V_82 -> V_85 -> V_86 , struct V_83 , V_11 ) ;
V_84 -> V_87 -> V_88 -- ;
F_27 ( V_77 , & V_84 -> V_7 -> V_61 ) ;
}
static int F_30 ( struct V_81 * V_82 )
{
struct V_89 * V_90 = V_82 -> V_85 ;
struct V_6 * V_11 = V_90 -> V_86 ;
struct V_83 * V_84 = F_29 ( V_11 , struct V_83 , V_11 ) ;
struct V_7 * V_8 = V_84 -> V_87 ;
int V_91 = - V_92 ;
F_2 ( L_9 ,
V_82 -> V_93 , V_90 -> V_94 - V_90 -> V_95 ,
V_90 -> V_94 ) ;
F_31 ( & V_11 -> V_96 ) ;
if ( F_32 ( V_11 ) ) {
if ( F_33 ( V_77 , & V_84 -> V_7 -> V_61 ) ) {
F_34 ( V_97 , & V_84 -> V_7 -> V_61 ) ;
V_8 -> V_88 ++ ;
F_35 ( V_82 , F_28 ) ;
}
} else {
F_27 ( V_77 , & V_84 -> V_7 -> V_61 ) ;
V_91 = - V_98 ;
}
F_36 ( & V_11 -> V_96 ) ;
V_8 -> V_99 ( V_8 ) ;
return V_91 ;
}
static inline void F_37 ( struct V_54 * V_4 )
{
T_1 V_100 = V_4 -> V_73 - sizeof( V_101 ) ;
V_101 * V_43 = V_4 -> V_78 [ 0 ] . V_52 ;
* V_43 = F_38 ( V_102 | V_100 ) ;
}
static int F_39 ( struct V_81 * V_82 )
{
struct V_89 * V_90 = V_82 -> V_85 ;
struct V_6 * V_11 = V_90 -> V_86 ;
struct V_83 * V_84 =
F_29 ( V_11 , struct V_83 , V_11 ) ;
struct V_54 * V_55 = & V_90 -> V_103 ;
int V_104 ;
int V_75 = 0 ;
F_37 ( & V_90 -> V_103 ) ;
F_1 ( L_10 ,
V_90 -> V_105 -> V_52 , V_90 -> V_105 -> V_53 ) ;
V_104 = F_25 ( V_84 -> V_7 , NULL , 0 , V_55 , V_90 -> V_95 ,
true , & V_75 ) ;
F_2 ( L_11 ,
V_106 , V_55 -> V_73 - V_90 -> V_95 , V_104 ) ;
if ( V_104 == - V_92 && F_40 ( V_84 -> V_87 ) )
V_104 = - V_107 ;
if ( F_41 ( V_75 > 0 ) || V_104 == 0 ) {
V_90 -> V_95 += V_75 ;
V_90 -> V_108 += V_75 ;
if ( F_41 ( V_90 -> V_95 >= V_90 -> V_94 ) ) {
V_90 -> V_95 = 0 ;
return 0 ;
}
V_104 = - V_92 ;
}
switch ( V_104 ) {
case - V_107 :
break;
case - V_92 :
V_104 = F_30 ( V_82 ) ;
break;
default:
F_2 ( L_12 ,
- V_104 ) ;
case - V_109 :
F_42 ( V_11 ) ;
V_104 = - V_98 ;
}
return V_104 ;
}
static int F_43 ( struct V_81 * V_82 )
{
struct V_89 * V_90 = V_82 -> V_85 ;
struct V_6 * V_11 = V_90 -> V_86 ;
struct V_83 * V_84 = F_29 ( V_11 , struct V_83 , V_11 ) ;
struct V_54 * V_55 = & V_90 -> V_103 ;
int V_75 = 0 ;
int V_104 ;
F_1 ( L_10 ,
V_90 -> V_105 -> V_52 ,
V_90 -> V_105 -> V_53 ) ;
if ( ! F_44 ( V_11 ) )
return - V_98 ;
V_104 = F_25 ( V_84 -> V_7 , F_4 ( V_11 ) , V_11 -> V_40 ,
V_55 , V_90 -> V_95 , true , & V_75 ) ;
F_2 ( L_13 ,
V_55 -> V_73 - V_90 -> V_95 , V_104 ) ;
if ( V_104 == - V_110 )
goto V_111;
if ( V_104 == - V_92 && F_40 ( V_84 -> V_87 ) )
V_104 = - V_107 ;
if ( V_75 > 0 || V_104 == 0 ) {
V_90 -> V_108 += V_75 ;
if ( V_75 >= V_90 -> V_94 )
return 0 ;
V_104 = - V_92 ;
}
V_111:
switch ( V_104 ) {
case - V_76 :
V_104 = - V_98 ;
break;
case - V_92 :
V_104 = F_30 ( V_82 ) ;
break;
default:
F_2 ( L_12 ,
- V_104 ) ;
case - V_112 :
case - V_107 :
case - V_109 :
case - V_113 :
case - V_110 :
F_27 ( V_77 , & V_84 -> V_7 -> V_61 ) ;
}
return V_104 ;
}
static int F_45 ( struct V_81 * V_82 )
{
struct V_89 * V_90 = V_82 -> V_85 ;
struct V_6 * V_11 = V_90 -> V_86 ;
struct V_83 * V_84 = F_29 ( V_11 , struct V_83 , V_11 ) ;
struct V_54 * V_55 = & V_90 -> V_103 ;
bool V_56 = true ;
int V_104 ;
int V_75 ;
F_37 ( & V_90 -> V_103 ) ;
F_1 ( L_10 ,
V_90 -> V_105 -> V_52 ,
V_90 -> V_105 -> V_53 ) ;
if ( V_82 -> V_114 & V_115 )
V_56 = false ;
while ( 1 ) {
V_75 = 0 ;
V_104 = F_25 ( V_84 -> V_7 , NULL , 0 , V_55 ,
V_90 -> V_95 , V_56 , & V_75 ) ;
F_2 ( L_14 ,
V_55 -> V_73 - V_90 -> V_95 , V_104 ) ;
V_90 -> V_95 += V_75 ;
V_90 -> V_108 += V_75 ;
if ( F_41 ( V_90 -> V_95 >= V_90 -> V_94 ) ) {
V_90 -> V_95 = 0 ;
return 0 ;
}
if ( V_104 < 0 )
break;
if ( V_75 == 0 ) {
V_104 = - V_92 ;
break;
}
}
if ( V_104 == - V_92 && F_46 ( V_84 -> V_87 ) )
V_104 = - V_107 ;
switch ( V_104 ) {
case - V_76 :
V_104 = - V_98 ;
break;
case - V_92 :
V_104 = F_30 ( V_82 ) ;
break;
default:
F_2 ( L_12 ,
- V_104 ) ;
case - V_116 :
case - V_113 :
case - V_98 :
case - V_117 :
case - V_107 :
case - V_109 :
F_27 ( V_77 , & V_84 -> V_7 -> V_61 ) ;
}
return V_104 ;
}
static void F_47 ( struct V_6 * V_11 , struct V_81 * V_82 )
{
struct V_89 * V_90 ;
if ( V_82 != V_11 -> V_118 )
return;
if ( V_82 == NULL )
goto V_119;
V_90 = V_82 -> V_85 ;
if ( V_90 == NULL )
goto V_119;
if ( V_90 -> V_95 == 0 )
goto V_119;
if ( V_90 -> V_95 == V_90 -> V_103 . V_73 )
goto V_119;
F_34 ( V_120 , & V_11 -> V_121 ) ;
V_119:
F_48 ( V_11 , V_82 ) ;
}
static void F_49 ( struct V_83 * V_84 , struct V_7 * V_8 )
{
V_84 -> V_122 = V_8 -> V_123 ;
V_84 -> V_124 = V_8 -> V_125 ;
V_84 -> V_126 = V_8 -> V_99 ;
V_84 -> V_127 = V_8 -> V_128 ;
}
static void F_50 ( struct V_83 * V_84 , struct V_7 * V_8 )
{
V_8 -> V_123 = V_84 -> V_122 ;
V_8 -> V_125 = V_84 -> V_124 ;
V_8 -> V_99 = V_84 -> V_126 ;
V_8 -> V_128 = V_84 -> V_127 ;
}
static void F_51 ( struct V_6 * V_11 )
{
F_52 () ;
F_27 ( V_120 , & V_11 -> V_121 ) ;
F_27 ( V_129 , & V_11 -> V_121 ) ;
F_53 () ;
}
static void F_54 ( struct V_6 * V_11 )
{
F_51 ( V_11 ) ;
F_55 ( V_11 ) ;
}
static void F_56 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
int V_64 ;
F_57 ( & V_8 -> V_130 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_79;
V_64 = - V_8 -> V_131 ;
if ( V_64 == 0 )
goto V_79;
if ( V_8 -> V_132 == V_133 )
F_54 ( V_11 ) ;
F_2 ( L_15 ,
V_11 , - V_64 ) ;
F_58 ( V_11 , V_8 -> V_134 , V_64 ) ;
F_59 ( V_11 , V_64 ) ;
V_79:
F_60 ( & V_8 -> V_130 ) ;
}
static void F_61 ( struct V_83 * V_84 )
{
struct V_39 * V_7 = V_84 -> V_7 ;
struct V_7 * V_8 = V_84 -> V_87 ;
struct V_6 * V_11 = & V_84 -> V_11 ;
if ( V_8 == NULL )
return;
if ( F_62 ( & V_84 -> V_11 . V_135 ) )
F_63 ( V_8 ) ;
F_64 ( V_7 , V_136 ) ;
F_65 ( & V_84 -> V_137 ) ;
F_66 ( & V_8 -> V_130 ) ;
V_84 -> V_87 = NULL ;
V_84 -> V_7 = NULL ;
V_8 -> V_9 = NULL ;
F_50 ( V_84 , V_8 ) ;
F_67 ( V_11 ) ;
F_68 ( & V_8 -> V_130 ) ;
F_51 ( V_11 ) ;
F_69 ( & V_84 -> V_137 ) ;
F_70 ( V_11 , V_7 ) ;
F_71 ( V_7 ) ;
}
static void F_42 ( struct V_6 * V_11 )
{
struct V_83 * V_84 = F_29 ( V_11 , struct V_83 , V_11 ) ;
F_2 ( L_16 , V_11 ) ;
F_61 ( V_84 ) ;
V_11 -> V_138 = 0 ;
F_55 ( V_11 ) ;
}
static void F_72 ( struct V_6 * V_11 )
{
F_2 ( L_17 ,
V_11 ) ;
F_55 ( V_11 ) ;
}
static void F_73 ( struct V_6 * V_11 )
{
F_19 ( V_11 ) ;
F_74 ( V_11 ) ;
}
static void F_75 ( struct V_6 * V_11 )
{
struct V_83 * V_84 = F_29 ( V_11 ,
struct V_83 , V_11 ) ;
F_2 ( L_18 , V_11 ) ;
F_76 ( & V_84 -> V_139 ) ;
F_42 ( V_11 ) ;
F_77 ( & V_84 -> V_140 ) ;
F_73 ( V_11 ) ;
F_78 ( V_141 ) ;
}
static int F_79 ( struct V_54 * V_55 , struct V_142 * V_143 )
{
struct V_144 V_145 = {
. V_143 = V_143 ,
. V_59 = sizeof( V_101 ) ,
. V_3 = V_143 -> V_73 - sizeof( V_101 ) ,
} ;
if ( F_80 ( V_55 , 0 , & V_145 , V_146 ) < 0 )
return - 1 ;
if ( V_145 . V_3 )
return - 1 ;
return 0 ;
}
static void F_81 ( struct V_6 * V_11 ,
struct V_7 * V_8 ,
struct V_142 * V_143 )
{
struct V_81 * V_82 ;
struct V_89 * V_147 ;
int V_148 , V_149 ;
T_1 V_150 ;
T_5 * V_151 ;
V_148 = V_143 -> V_73 - sizeof( V_101 ) ;
if ( V_148 < 4 ) {
F_2 ( L_19 , V_148 ) ;
return;
}
V_151 = F_82 ( V_143 , sizeof( V_101 ) , sizeof( V_150 ) , & V_150 ) ;
if ( V_151 == NULL )
return;
F_31 ( & V_11 -> V_96 ) ;
V_147 = F_83 ( V_11 , * V_151 ) ;
if ( ! V_147 )
goto V_152;
V_82 = V_147 -> V_153 ;
V_149 = V_147 -> V_154 . V_155 ;
if ( V_149 > V_148 )
V_149 = V_148 ;
if ( F_79 ( & V_147 -> V_154 , V_143 ) ) {
F_2 ( L_20 ) ;
goto V_152;
}
F_84 ( V_82 , V_149 ) ;
V_152:
F_36 ( & V_11 -> V_96 ) ;
}
static void F_85 ( struct V_83 * V_84 )
{
struct V_142 * V_143 ;
struct V_7 * V_8 ;
int V_64 ;
F_65 ( & V_84 -> V_137 ) ;
V_8 = V_84 -> V_87 ;
if ( V_8 == NULL )
goto V_79;
for (; ; ) {
V_143 = F_86 ( V_8 , 0 , 1 , & V_64 ) ;
if ( V_143 == NULL )
break;
F_81 ( & V_84 -> V_11 , V_8 , V_143 ) ;
F_87 ( V_8 , V_143 ) ;
}
V_79:
F_69 ( & V_84 -> V_137 ) ;
}
static void F_88 ( struct V_156 * V_157 )
{
struct V_83 * V_84 =
F_29 ( V_157 , struct V_83 , V_140 ) ;
F_85 ( V_84 ) ;
}
static void F_89 ( struct V_6 * V_11 ,
struct V_7 * V_8 ,
struct V_142 * V_143 )
{
struct V_81 * V_82 ;
struct V_89 * V_147 ;
int V_148 , V_149 ;
T_1 V_150 ;
T_5 * V_151 ;
V_148 = V_143 -> V_73 - sizeof( struct V_158 ) ;
if ( V_148 < 4 ) {
F_2 ( L_21 , V_148 ) ;
return;
}
V_151 = F_82 ( V_143 , sizeof( struct V_158 ) ,
sizeof( V_150 ) , & V_150 ) ;
if ( V_151 == NULL )
return;
F_31 ( & V_11 -> V_96 ) ;
V_147 = F_83 ( V_11 , * V_151 ) ;
if ( ! V_147 )
goto V_152;
V_82 = V_147 -> V_153 ;
if ( ( V_149 = V_147 -> V_154 . V_155 ) > V_148 )
V_149 = V_148 ;
if ( F_90 ( & V_147 -> V_154 , V_143 ) ) {
F_91 ( V_8 , V_159 ) ;
goto V_152;
}
F_91 ( V_8 , V_160 ) ;
F_92 ( V_11 , V_82 , V_149 ) ;
F_84 ( V_82 , V_149 ) ;
V_152:
F_36 ( & V_11 -> V_96 ) ;
}
static void F_93 ( struct V_83 * V_84 )
{
struct V_142 * V_143 ;
struct V_7 * V_8 ;
int V_64 ;
F_65 ( & V_84 -> V_137 ) ;
V_8 = V_84 -> V_87 ;
if ( V_8 == NULL )
goto V_79;
for (; ; ) {
V_143 = F_86 ( V_8 , 0 , 1 , & V_64 ) ;
if ( V_143 == NULL )
break;
F_89 ( & V_84 -> V_11 , V_8 , V_143 ) ;
F_87 ( V_8 , V_143 ) ;
}
V_79:
F_69 ( & V_84 -> V_137 ) ;
}
static void F_94 ( struct V_156 * V_157 )
{
struct V_83 * V_84 =
F_29 ( V_157 , struct V_83 , V_140 ) ;
F_93 ( V_84 ) ;
}
static void F_95 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
F_57 ( & V_8 -> V_130 ) ;
F_2 ( L_22 ) ;
V_11 = F_3 ( V_8 ) ;
if ( V_11 != NULL ) {
struct V_83 * V_84 = F_29 ( V_11 ,
struct V_83 , V_11 ) ;
F_96 ( V_161 , & V_84 -> V_140 ) ;
}
F_60 ( & V_8 -> V_130 ) ;
}
static void F_97 ( struct V_6 * V_11 )
{
F_98 ( V_11 ) ;
}
static inline void F_99 ( struct V_6 * V_11 , struct V_144 * V_145 )
{
struct V_83 * V_84 = F_29 ( V_11 , struct V_83 , V_11 ) ;
T_4 V_73 , V_162 ;
char * V_163 ;
V_163 = ( ( char * ) & V_84 -> V_164 ) + V_84 -> V_165 ;
V_73 = sizeof( V_84 -> V_164 ) - V_84 -> V_165 ;
V_162 = V_146 ( V_145 , V_163 , V_73 ) ;
V_84 -> V_165 += V_162 ;
if ( V_162 != V_73 )
return;
V_84 -> V_166 = F_12 ( V_84 -> V_164 ) ;
if ( V_84 -> V_166 & V_102 )
V_84 -> V_167 |= V_168 ;
else
V_84 -> V_167 &= ~ V_168 ;
V_84 -> V_166 &= V_169 ;
V_84 -> V_167 &= ~ V_170 ;
V_84 -> V_165 = 0 ;
if ( F_26 ( V_84 -> V_166 < 8 ) ) {
F_2 ( L_23 ) ;
F_97 ( V_11 ) ;
return;
}
F_2 ( L_24 ,
V_84 -> V_166 ) ;
}
static void F_100 ( struct V_83 * V_84 )
{
if ( V_84 -> V_165 == V_84 -> V_166 ) {
V_84 -> V_167 |= V_170 ;
V_84 -> V_165 = 0 ;
if ( V_84 -> V_167 & V_168 ) {
V_84 -> V_167 &= ~ V_171 ;
V_84 -> V_167 |= V_172 ;
V_84 -> V_173 = 0 ;
}
}
}
static inline void F_101 ( struct V_83 * V_84 , struct V_144 * V_145 )
{
T_4 V_73 , V_162 ;
char * V_163 ;
V_73 = sizeof( V_84 -> V_174 ) - V_84 -> V_165 ;
F_2 ( L_25 , V_73 ) ;
V_163 = ( ( char * ) & V_84 -> V_174 ) + V_84 -> V_165 ;
V_162 = V_146 ( V_145 , V_163 , V_73 ) ;
V_84 -> V_165 += V_162 ;
if ( V_162 != V_73 )
return;
V_84 -> V_167 &= ~ V_172 ;
V_84 -> V_167 |= V_175 ;
V_84 -> V_173 = 4 ;
F_2 ( L_26 ,
( V_84 -> V_167 & V_176 ) ? L_27
: L_28 ,
F_12 ( V_84 -> V_174 ) ) ;
F_100 ( V_84 ) ;
}
static inline void F_102 ( struct V_83 * V_84 ,
struct V_144 * V_145 )
{
T_4 V_73 , V_162 ;
T_1 V_59 ;
char * V_163 ;
V_59 = V_84 -> V_165 - sizeof( V_84 -> V_174 ) ;
V_73 = sizeof( V_84 -> V_177 ) - V_59 ;
F_2 ( L_29 , V_73 ) ;
V_163 = ( ( char * ) & V_84 -> V_177 ) + V_59 ;
V_162 = V_146 ( V_145 , V_163 , V_73 ) ;
V_84 -> V_165 += V_162 ;
if ( V_162 != V_73 )
return;
V_84 -> V_167 &= ~ V_175 ;
switch ( F_12 ( V_84 -> V_177 ) ) {
case V_178 :
V_84 -> V_167 |= V_179 ;
V_84 -> V_167 |= V_171 ;
V_84 -> V_167 |= V_176 ;
break;
case V_180 :
V_84 -> V_167 |= V_179 ;
V_84 -> V_167 |= V_171 ;
V_84 -> V_167 &= ~ V_176 ;
break;
default:
F_2 ( L_30 ) ;
F_97 ( & V_84 -> V_11 ) ;
}
F_100 ( V_84 ) ;
}
static inline void F_103 ( struct V_6 * V_11 ,
struct V_144 * V_145 ,
struct V_89 * V_90 )
{
struct V_83 * V_84 =
F_29 ( V_11 , struct V_83 , V_11 ) ;
struct V_54 * V_181 ;
T_4 V_73 ;
T_3 V_182 ;
V_181 = & V_90 -> V_154 ;
if ( V_84 -> V_167 & V_179 ) {
memcpy ( V_181 -> V_78 [ 0 ] . V_52 + V_84 -> V_173 ,
& V_84 -> V_177 ,
sizeof( V_84 -> V_177 ) ) ;
V_84 -> V_173 += sizeof( V_84 -> V_177 ) ;
V_84 -> V_167 &= ~ V_179 ;
}
V_73 = V_145 -> V_3 ;
if ( V_73 > V_84 -> V_166 - V_84 -> V_165 ) {
struct V_144 V_183 ;
V_73 = V_84 -> V_166 - V_84 -> V_165 ;
memcpy ( & V_183 , V_145 , sizeof( V_183 ) ) ;
V_183 . V_3 = V_73 ;
V_182 = F_80 ( V_181 , V_84 -> V_173 ,
& V_183 , V_146 ) ;
V_145 -> V_3 -= V_182 ;
V_145 -> V_59 += V_182 ;
} else
V_182 = F_80 ( V_181 , V_84 -> V_173 ,
V_145 , V_146 ) ;
if ( V_182 > 0 ) {
V_84 -> V_173 += V_182 ;
V_84 -> V_165 += V_182 ;
}
if ( V_182 != V_73 ) {
V_84 -> V_167 &= ~ V_171 ;
F_2 ( L_31 ,
F_12 ( V_84 -> V_174 ) ) ;
F_2 ( L_32
L_33 ,
V_11 , V_84 -> V_173 ,
V_84 -> V_165 , V_84 -> V_166 ) ;
return;
}
F_2 ( L_34 ,
F_12 ( V_84 -> V_174 ) , V_182 ) ;
F_2 ( L_35
L_36 , V_11 , V_84 -> V_173 ,
V_84 -> V_165 , V_84 -> V_166 ) ;
if ( V_84 -> V_173 == V_90 -> V_154 . V_155 )
V_84 -> V_167 &= ~ V_171 ;
else if ( V_84 -> V_165 == V_84 -> V_166 ) {
if ( V_84 -> V_167 & V_168 )
V_84 -> V_167 &= ~ V_171 ;
}
}
static inline int F_104 ( struct V_6 * V_11 ,
struct V_144 * V_145 )
{
struct V_83 * V_84 =
F_29 ( V_11 , struct V_83 , V_11 ) ;
struct V_89 * V_90 ;
F_2 ( L_37 , F_12 ( V_84 -> V_174 ) ) ;
F_31 ( & V_11 -> V_96 ) ;
V_90 = F_83 ( V_11 , V_84 -> V_174 ) ;
if ( ! V_90 ) {
F_2 ( L_38 ,
F_12 ( V_84 -> V_174 ) ) ;
F_36 ( & V_11 -> V_96 ) ;
return - 1 ;
}
F_103 ( V_11 , V_145 , V_90 ) ;
if ( ! ( V_84 -> V_167 & V_171 ) )
F_84 ( V_90 -> V_153 , V_84 -> V_173 ) ;
F_36 ( & V_11 -> V_96 ) ;
return 0 ;
}
static int F_105 ( struct V_6 * V_11 ,
struct V_144 * V_145 )
{
struct V_83 * V_84 =
F_29 ( V_11 , struct V_83 , V_11 ) ;
struct V_89 * V_90 ;
F_31 ( & V_11 -> V_96 ) ;
V_90 = F_106 ( V_11 , V_84 -> V_174 ) ;
if ( V_90 == NULL ) {
F_36 ( & V_11 -> V_96 ) ;
F_107 ( V_184 L_39 ) ;
F_98 ( V_11 ) ;
return - 1 ;
}
F_2 ( L_40 , F_12 ( V_90 -> V_185 ) ) ;
F_103 ( V_11 , V_145 , V_90 ) ;
if ( ! ( V_84 -> V_167 & V_171 ) )
F_108 ( V_90 , V_84 -> V_173 ) ;
F_36 ( & V_11 -> V_96 ) ;
return 0 ;
}
static inline int F_109 ( struct V_6 * V_11 ,
struct V_144 * V_145 )
{
struct V_83 * V_84 =
F_29 ( V_11 , struct V_83 , V_11 ) ;
return ( V_84 -> V_167 & V_176 ) ?
F_104 ( V_11 , V_145 ) :
F_105 ( V_11 , V_145 ) ;
}
static int F_110 ( struct V_186 * V_187 , struct V_188 * V_188 )
{
int V_91 ;
V_91 = F_111 ( V_187 , L_41 , V_188 , V_189 , 0 ,
V_190 ) ;
if ( V_91 < 0 )
return V_91 ;
return 0 ;
}
static inline int F_109 ( struct V_6 * V_11 ,
struct V_144 * V_145 )
{
return F_104 ( V_11 , V_145 ) ;
}
static void F_112 ( struct V_6 * V_11 ,
struct V_144 * V_145 )
{
struct V_83 * V_84 =
F_29 ( V_11 , struct V_83 , V_11 ) ;
if ( F_109 ( V_11 , V_145 ) == 0 )
F_100 ( V_84 ) ;
else {
V_84 -> V_167 &= ~ V_171 ;
}
}
static inline void F_113 ( struct V_83 * V_84 , struct V_144 * V_145 )
{
T_4 V_73 ;
V_73 = V_84 -> V_166 - V_84 -> V_165 ;
if ( V_73 > V_145 -> V_3 )
V_73 = V_145 -> V_3 ;
V_145 -> V_3 -= V_73 ;
V_145 -> V_59 += V_73 ;
V_84 -> V_165 += V_73 ;
F_2 ( L_42 , V_73 ) ;
F_100 ( V_84 ) ;
}
static int F_114 ( T_6 * V_191 , struct V_142 * V_143 , unsigned int V_59 , T_4 V_73 )
{
struct V_6 * V_11 = V_191 -> V_192 . V_193 ;
struct V_83 * V_84 = F_29 ( V_11 , struct V_83 , V_11 ) ;
struct V_144 V_145 = {
. V_143 = V_143 ,
. V_59 = V_59 ,
. V_3 = V_73 ,
} ;
F_2 ( L_43 ) ;
do {
F_115 ( V_84 ) ;
if ( V_84 -> V_167 & V_170 ) {
F_99 ( V_11 , & V_145 ) ;
continue;
}
if ( V_84 -> V_167 & V_172 ) {
F_101 ( V_84 , & V_145 ) ;
continue;
}
if ( V_84 -> V_167 & V_175 ) {
F_102 ( V_84 , & V_145 ) ;
continue;
}
if ( V_84 -> V_167 & V_171 ) {
F_112 ( V_11 , & V_145 ) ;
continue;
}
F_113 ( V_84 , & V_145 ) ;
} while ( V_145 . V_3 );
F_115 ( V_84 ) ;
F_2 ( L_44 ) ;
return V_73 - V_145 . V_3 ;
}
static void F_116 ( struct V_83 * V_84 )
{
struct V_6 * V_11 = & V_84 -> V_11 ;
struct V_7 * V_8 ;
T_6 V_191 = {
. V_3 = 2 * 1024 * 1024 ,
. V_192 . V_193 = V_11 ,
} ;
unsigned long V_194 = 0 ;
int V_195 = 0 ;
F_65 ( & V_84 -> V_137 ) ;
V_8 = V_84 -> V_87 ;
if ( V_8 == NULL )
goto V_79;
for (; ; ) {
F_117 ( V_8 ) ;
V_195 = F_118 ( V_8 , & V_191 , F_114 ) ;
F_119 ( V_8 ) ;
if ( V_195 <= 0 )
break;
V_194 += V_195 ;
V_191 . V_3 = 65536 ;
}
V_79:
F_69 ( & V_84 -> V_137 ) ;
F_120 ( V_11 , V_195 , V_194 ) ;
}
static void F_121 ( struct V_156 * V_157 )
{
struct V_83 * V_84 =
F_29 ( V_157 , struct V_83 , V_140 ) ;
F_116 ( V_84 ) ;
}
static void F_122 ( struct V_7 * V_8 )
{
struct V_83 * V_84 ;
struct V_6 * V_11 ;
F_2 ( L_45 ) ;
F_57 ( & V_8 -> V_130 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_79;
V_84 = F_29 ( V_11 , struct V_83 , V_11 ) ;
if ( V_11 -> V_138 )
V_11 -> V_138 = 0 ;
F_96 ( V_161 , & V_84 -> V_140 ) ;
V_79:
F_60 ( & V_8 -> V_130 ) ;
}
static void F_123 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
struct V_83 * V_84 ;
F_57 ( & V_8 -> V_130 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_79;
F_2 ( L_46 , V_11 ) ;
F_2 ( L_47 ,
V_8 -> V_132 , F_32 ( V_11 ) ,
F_124 ( V_8 , V_196 ) ,
F_124 ( V_8 , V_197 ) ,
V_8 -> V_198 ) ;
V_84 = F_29 ( V_11 , struct V_83 , V_11 ) ;
F_125 ( V_11 , V_8 -> V_134 ) ;
switch ( V_8 -> V_132 ) {
case V_199 :
F_126 ( & V_11 -> V_96 ) ;
if ( ! F_127 ( V_11 ) ) {
V_84 -> V_165 = 0 ;
V_84 -> V_166 = 0 ;
V_84 -> V_173 = 0 ;
V_84 -> V_167 =
V_170 | V_172 ;
V_11 -> V_200 ++ ;
F_27 ( V_201 , & V_84 -> V_202 ) ;
F_128 ( V_11 ) ;
F_59 ( V_11 , - V_92 ) ;
}
F_129 ( & V_11 -> V_96 ) ;
break;
case V_203 :
V_11 -> V_200 ++ ;
V_11 -> V_138 = 0 ;
F_34 ( V_129 , & V_11 -> V_121 ) ;
F_52 () ;
F_27 ( V_204 , & V_11 -> V_121 ) ;
F_27 ( V_120 , & V_11 -> V_121 ) ;
F_53 () ;
break;
case V_205 :
V_11 -> V_200 ++ ;
F_27 ( V_204 , & V_11 -> V_121 ) ;
F_97 ( V_11 ) ;
case V_206 :
if ( V_11 -> V_138 < V_207 )
V_11 -> V_138 = V_207 ;
break;
case V_208 :
F_34 ( V_129 , & V_11 -> V_121 ) ;
F_52 () ;
F_27 ( V_204 , & V_11 -> V_121 ) ;
F_53 () ;
break;
case V_133 :
if ( F_130 ( V_201 ,
& V_84 -> V_202 ) )
F_128 ( V_11 ) ;
F_54 ( V_11 ) ;
}
V_79:
F_60 ( & V_8 -> V_130 ) ;
}
static void F_131 ( struct V_7 * V_8 )
{
struct V_39 * V_7 ;
struct V_6 * V_11 ;
if ( F_26 ( ! ( V_7 = V_8 -> V_134 ) ) )
return;
F_27 ( V_97 , & V_7 -> V_61 ) ;
if ( F_26 ( ! ( V_11 = F_3 ( V_8 ) ) ) )
return;
if ( F_130 ( V_77 , & V_7 -> V_61 ) == 0 )
return;
F_132 ( V_11 ) ;
}
static void F_133 ( struct V_7 * V_8 )
{
F_57 ( & V_8 -> V_130 ) ;
if ( F_40 ( V_8 ) )
F_131 ( V_8 ) ;
F_60 ( & V_8 -> V_130 ) ;
}
static void F_134 ( struct V_7 * V_8 )
{
F_57 ( & V_8 -> V_130 ) ;
if ( F_46 ( V_8 ) )
F_131 ( V_8 ) ;
F_60 ( & V_8 -> V_130 ) ;
}
static void F_135 ( struct V_6 * V_11 )
{
struct V_83 * V_84 = F_29 ( V_11 , struct V_83 , V_11 ) ;
struct V_7 * V_8 = V_84 -> V_87 ;
if ( V_84 -> V_209 ) {
V_8 -> V_210 |= V_211 ;
V_8 -> V_212 = V_84 -> V_209 * V_11 -> V_213 * 2 ;
}
if ( V_84 -> V_214 ) {
V_8 -> V_210 |= V_215 ;
V_8 -> V_216 = V_84 -> V_214 * V_11 -> V_213 * 2 ;
V_8 -> V_99 ( V_8 ) ;
}
}
static void F_136 ( struct V_6 * V_11 , T_4 V_214 , T_4 V_209 )
{
struct V_83 * V_84 = F_29 ( V_11 , struct V_83 , V_11 ) ;
V_84 -> V_214 = 0 ;
if ( V_214 )
V_84 -> V_214 = V_214 + 1024 ;
V_84 -> V_209 = 0 ;
if ( V_209 )
V_84 -> V_209 = V_209 + 1024 ;
F_135 ( V_11 ) ;
}
static void F_137 ( struct V_6 * V_11 , struct V_81 * V_82 )
{
F_92 ( V_11 , V_82 , - V_217 ) ;
}
static unsigned short F_138 ( void )
{
unsigned short V_218 = V_219 - V_220 ;
unsigned short rand = ( unsigned short ) F_139 () % V_218 ;
return rand + V_220 ;
}
static void F_140 ( struct V_39 * V_7 )
{
int V_221 = 1 ;
F_141 ( V_7 , V_222 , V_223 ,
( char * ) & V_221 , sizeof( V_221 ) ) ;
}
static unsigned short F_142 ( struct V_39 * V_7 )
{
struct V_224 V_4 ;
int V_155 ;
unsigned short V_225 = 0 ;
if ( F_143 ( V_7 , (struct V_10 * ) & V_4 , & V_155 ) < 0 )
goto V_79;
switch ( V_4 . V_226 ) {
case V_28 :
V_225 = F_144 ( ( (struct V_15 * ) & V_4 ) -> V_227 ) ;
break;
case V_25 :
V_225 = F_144 ( ( (struct V_14 * ) & V_4 ) -> V_228 ) ;
}
V_79:
return V_225 ;
}
static void F_145 ( struct V_6 * V_11 , unsigned short V_225 )
{
F_2 ( L_48 , V_11 , V_225 ) ;
F_146 ( F_4 ( V_11 ) , V_225 ) ;
F_17 ( V_11 ) ;
}
static void F_147 ( struct V_83 * V_84 , struct V_39 * V_7 )
{
if ( V_84 -> V_229 == 0 )
V_84 -> V_229 = F_142 ( V_7 ) ;
}
static unsigned short F_148 ( struct V_83 * V_84 )
{
unsigned short V_225 = V_84 -> V_229 ;
if ( V_225 == 0 && V_84 -> V_11 . V_230 )
V_225 = F_138 () ;
return V_225 ;
}
static unsigned short F_149 ( struct V_83 * V_84 , unsigned short V_225 )
{
if ( V_84 -> V_229 != 0 )
V_84 -> V_229 = 0 ;
if ( ! V_84 -> V_11 . V_230 )
return 0 ;
if ( V_225 <= V_220 || V_225 > V_219 )
return V_219 ;
return -- V_225 ;
}
static int F_150 ( struct V_83 * V_84 , struct V_39 * V_7 )
{
struct V_224 V_231 ;
int V_64 , V_232 = 0 ;
unsigned short V_225 = F_148 ( V_84 ) ;
unsigned short V_233 ;
if ( V_225 == 0 )
return 0 ;
memcpy ( & V_231 , & V_84 -> V_234 , V_84 -> V_11 . V_40 ) ;
do {
F_146 ( (struct V_10 * ) & V_231 , V_225 ) ;
V_64 = F_151 ( V_7 , (struct V_10 * ) & V_231 ,
V_84 -> V_11 . V_40 ) ;
if ( V_64 == 0 ) {
V_84 -> V_229 = V_225 ;
break;
}
V_233 = V_225 ;
V_225 = F_149 ( V_84 , V_225 ) ;
if ( V_225 > V_233 )
V_232 ++ ;
} while ( V_64 == - V_117 && V_232 != 2 );
if ( V_231 . V_226 == V_25 )
F_2 ( L_49 , V_106 ,
& ( (struct V_14 * ) & V_231 ) -> V_26 ,
V_225 , V_64 ? L_50 : L_51 , V_64 ) ;
else
F_2 ( L_52 , V_106 ,
& ( (struct V_15 * ) & V_231 ) -> V_29 ,
V_225 , V_64 ? L_50 : L_51 , V_64 ) ;
return V_64 ;
}
static void F_152 ( struct V_81 * V_82 )
{
F_153 () ;
F_154 ( F_155 ( V_82 -> V_235 -> V_236 ) ) ;
F_156 () ;
}
static void F_157 ( struct V_6 * V_11 , unsigned short V_225 )
{
}
static inline void F_158 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_159 ( V_8 , L_53 ,
& V_237 [ 1 ] , L_54 , & V_238 [ 1 ] ) ;
}
static inline void F_160 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_159 ( V_8 , L_55 ,
& V_237 [ 0 ] , L_56 , & V_238 [ 0 ] ) ;
}
static inline void F_161 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_159 ( V_8 , L_57 ,
& V_237 [ 1 ] , L_58 , & V_238 [ 1 ] ) ;
}
static inline void F_162 ( int V_239 , struct V_39 * V_7 )
{
F_163 ( F_164 ( V_7 -> V_8 ) ) ;
if ( F_164 ( V_7 -> V_8 ) )
return;
switch ( V_239 ) {
case V_20 :
F_158 ( V_7 ) ;
break;
case V_25 :
F_160 ( V_7 ) ;
break;
case V_28 :
F_161 ( V_7 ) ;
break;
}
}
static inline void F_158 ( struct V_39 * V_7 )
{
}
static inline void F_160 ( struct V_39 * V_7 )
{
}
static inline void F_161 ( struct V_39 * V_7 )
{
}
static inline void F_162 ( int V_239 , struct V_39 * V_7 )
{
}
static void F_165 ( struct V_156 * V_157 )
{
}
static struct V_39 * F_166 ( struct V_6 * V_11 ,
struct V_83 * V_84 , int V_239 , int type ,
int V_33 , bool V_240 )
{
struct V_39 * V_7 ;
int V_64 ;
V_64 = F_167 ( V_11 -> V_241 , V_239 , type , V_33 , & V_7 , 1 ) ;
if ( V_64 < 0 ) {
F_2 ( L_59 ,
V_33 , - V_64 ) ;
goto V_79;
}
F_162 ( V_239 , V_7 ) ;
if ( V_240 )
F_140 ( V_7 ) ;
V_64 = F_150 ( V_84 , V_7 ) ;
if ( V_64 ) {
F_71 ( V_7 ) ;
goto V_79;
}
return V_7 ;
V_79:
return F_168 ( V_64 ) ;
}
static int F_169 ( struct V_6 * V_11 ,
struct V_39 * V_7 )
{
struct V_83 * V_84 = F_29 ( V_11 , struct V_83 ,
V_11 ) ;
if ( ! V_84 -> V_87 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
F_66 ( & V_8 -> V_130 ) ;
F_49 ( V_84 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_123 = F_95 ;
V_8 -> V_99 = F_133 ;
V_8 -> V_128 = F_56 ;
V_8 -> V_242 = V_243 ;
F_67 ( V_11 ) ;
V_84 -> V_7 = V_7 ;
V_84 -> V_87 = V_8 ;
F_68 ( & V_8 -> V_130 ) ;
}
V_11 -> V_244 . V_245 ++ ;
V_11 -> V_244 . V_246 = V_247 ;
return F_170 ( V_7 , F_4 ( V_11 ) , V_11 -> V_40 , 0 ) ;
}
static int F_171 ( struct V_83 * V_84 )
{
struct V_6 * V_11 = & V_84 -> V_11 ;
struct V_39 * V_7 ;
int V_104 = - V_248 ;
V_104 = F_167 ( V_11 -> V_241 , V_20 ,
V_249 , 0 , & V_7 , 1 ) ;
if ( V_104 < 0 ) {
F_2 ( L_60
L_61 , - V_104 ) ;
goto V_79;
}
F_158 ( V_7 ) ;
F_2 ( L_62 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
V_104 = F_169 ( V_11 , V_7 ) ;
F_172 ( V_11 , V_7 , V_104 ) ;
switch ( V_104 ) {
case 0 :
F_2 ( L_63 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
F_173 ( V_11 ) ;
case - V_107 :
break;
case - V_250 :
F_2 ( L_64 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
break;
case - V_113 :
F_2 ( L_65 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
break;
default:
F_107 ( V_251 L_66 ,
V_106 , - V_104 ,
V_11 -> V_22 [ V_23 ] ) ;
}
V_79:
F_128 ( V_11 ) ;
F_59 ( V_11 , V_104 ) ;
return V_104 ;
}
static void F_174 ( struct V_6 * V_11 , struct V_81 * V_82 )
{
struct V_83 * V_84 = F_29 ( V_11 , struct V_83 , V_11 ) ;
int V_91 ;
if ( F_175 ( V_82 ) ) {
F_176 ( V_82 , - V_98 ) ;
return;
}
V_91 = F_171 ( V_84 ) ;
if ( V_91 && ! F_177 ( V_82 ) )
F_178 ( 15000 ) ;
}
static void F_179 ( struct V_6 * V_11 )
{
struct V_83 * V_84 = F_29 ( V_11 , struct V_83 ,
V_11 ) ;
if ( ! V_84 -> V_87 )
return;
if ( F_62 ( & V_11 -> V_135 ) )
F_180 ( V_84 -> V_87 ) ;
}
static int
F_181 ( struct V_6 * V_11 )
{
struct V_83 * V_252 = F_29 ( V_11 , struct V_83 , V_11 ) ;
if ( F_182 ( & V_11 -> V_135 ) != 1 )
return 0 ;
if ( F_183 ( & V_11 -> V_121 , V_253 , V_254 ) )
return - V_255 ;
if ( V_252 -> V_87 )
F_180 ( V_252 -> V_87 ) ;
F_48 ( V_11 , NULL ) ;
return 0 ;
}
static void
F_184 ( struct V_6 * V_11 )
{
struct V_83 * V_252 = F_29 ( V_11 , struct V_83 , V_11 ) ;
if ( ! F_185 ( & V_11 -> V_135 ) )
return;
if ( F_183 ( & V_11 -> V_121 , V_253 , V_254 ) )
return;
if ( V_252 -> V_87 )
F_63 ( V_252 -> V_87 ) ;
F_48 ( V_11 , NULL ) ;
}
static void F_179 ( struct V_6 * V_11 )
{
}
static int
F_181 ( struct V_6 * V_11 )
{
return - V_256 ;
}
static void
F_184 ( struct V_6 * V_11 )
{
}
static void F_186 ( struct V_6 * V_11 , struct V_39 * V_7 )
{
struct V_83 * V_84 = F_29 ( V_11 , struct V_83 , V_11 ) ;
if ( ! V_84 -> V_87 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
F_66 ( & V_8 -> V_130 ) ;
F_49 ( V_84 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_123 = F_95 ;
V_8 -> V_99 = F_133 ;
V_8 -> V_242 = V_243 ;
F_173 ( V_11 ) ;
V_84 -> V_7 = V_7 ;
V_84 -> V_87 = V_8 ;
F_179 ( V_11 ) ;
F_68 ( & V_8 -> V_130 ) ;
}
F_135 ( V_11 ) ;
}
static void F_187 ( struct V_156 * V_157 )
{
struct V_83 * V_84 =
F_29 ( V_157 , struct V_83 , V_139 . V_157 ) ;
struct V_6 * V_11 = & V_84 -> V_11 ;
struct V_39 * V_7 = V_84 -> V_7 ;
int V_104 = - V_248 ;
V_7 = F_166 ( V_11 , V_84 ,
F_4 ( V_11 ) -> V_19 , V_257 ,
V_258 , false ) ;
if ( F_188 ( V_7 ) )
goto V_79;
F_2 ( L_67
L_68 , V_11 ,
V_11 -> V_22 [ V_35 ] ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ) ;
F_186 ( V_11 , V_7 ) ;
F_172 ( V_11 , V_7 , 0 ) ;
V_104 = 0 ;
V_79:
F_189 ( V_11 , V_84 ) ;
F_128 ( V_11 ) ;
F_59 ( V_11 , V_104 ) ;
}
static void F_190 ( struct V_6 * V_11 )
{
struct V_83 * V_84 = F_29 ( V_11 , struct V_83 , V_11 ) ;
struct V_39 * V_7 = V_84 -> V_7 ;
if ( V_7 == NULL )
return;
if ( F_32 ( V_11 ) ) {
F_64 ( V_7 , V_136 ) ;
F_191 ( V_11 , V_7 ) ;
} else
F_61 ( V_84 ) ;
}
static int F_192 ( struct V_6 * V_11 , struct V_39 * V_7 )
{
struct V_83 * V_84 = F_29 ( V_11 , struct V_83 , V_11 ) ;
int V_91 = - V_98 ;
if ( ! V_84 -> V_87 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
unsigned int V_259 = V_11 -> V_260 -> V_261 / V_262 ;
unsigned int V_263 = V_11 -> V_260 -> V_264 + 1 ;
unsigned int V_265 = 1 ;
unsigned int V_266 ;
F_141 ( V_7 , V_222 , V_267 ,
( char * ) & V_265 , sizeof( V_265 ) ) ;
F_141 ( V_7 , V_268 , V_269 ,
( char * ) & V_259 , sizeof( V_259 ) ) ;
F_141 ( V_7 , V_268 , V_270 ,
( char * ) & V_259 , sizeof( V_259 ) ) ;
F_141 ( V_7 , V_268 , V_271 ,
( char * ) & V_263 , sizeof( V_263 ) ) ;
V_266 = F_193 ( V_11 -> V_260 -> V_261 ) *
( V_11 -> V_260 -> V_264 + 1 ) ;
F_141 ( V_7 , V_268 , V_272 ,
( char * ) & V_266 , sizeof( V_266 ) ) ;
F_66 ( & V_8 -> V_130 ) ;
F_49 ( V_84 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_123 = F_122 ;
V_8 -> V_125 = F_123 ;
V_8 -> V_99 = F_134 ;
V_8 -> V_128 = F_56 ;
V_8 -> V_242 = V_243 ;
F_194 ( V_8 , V_273 ) ;
F_195 ( V_8 ) -> V_274 |= V_275 ;
F_67 ( V_11 ) ;
V_84 -> V_7 = V_7 ;
V_84 -> V_87 = V_8 ;
F_68 ( & V_8 -> V_130 ) ;
}
if ( ! F_44 ( V_11 ) )
goto V_79;
F_179 ( V_11 ) ;
V_11 -> V_244 . V_245 ++ ;
V_11 -> V_244 . V_246 = V_247 ;
F_34 ( V_201 , & V_84 -> V_202 ) ;
V_91 = F_170 ( V_7 , F_4 ( V_11 ) , V_11 -> V_40 , V_276 ) ;
switch ( V_91 ) {
case 0 :
F_147 ( V_84 , V_7 ) ;
case - V_277 :
if ( V_11 -> V_138 < V_207 )
V_11 -> V_138 = V_207 ;
}
V_79:
return V_91 ;
}
static void F_196 ( struct V_156 * V_157 )
{
struct V_83 * V_84 =
F_29 ( V_157 , struct V_83 , V_139 . V_157 ) ;
struct V_39 * V_7 = V_84 -> V_7 ;
struct V_6 * V_11 = & V_84 -> V_11 ;
int V_104 = - V_248 ;
if ( ! V_7 ) {
V_7 = F_166 ( V_11 , V_84 ,
F_4 ( V_11 ) -> V_19 , V_249 ,
V_278 , true ) ;
if ( F_188 ( V_7 ) ) {
V_104 = F_197 ( V_7 ) ;
goto V_79;
}
}
F_2 ( L_67
L_68 , V_11 ,
V_11 -> V_22 [ V_35 ] ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ) ;
V_104 = F_192 ( V_11 , V_7 ) ;
F_172 ( V_11 , V_7 , V_104 ) ;
F_2 ( L_69 ,
V_11 , - V_104 , F_32 ( V_11 ) ,
V_7 -> V_8 -> V_132 ) ;
switch ( V_104 ) {
default:
F_107 ( L_70 ,
V_106 , V_104 ) ;
case - V_279 :
F_97 ( V_11 ) ;
break;
case 0 :
case - V_277 :
case - V_280 :
F_189 ( V_11 , V_84 ) ;
return;
case - V_256 :
case - V_113 :
case - V_116 :
case - V_112 :
case - V_117 :
case - V_107 :
F_97 ( V_11 ) ;
goto V_79;
}
V_104 = - V_92 ;
V_79:
F_189 ( V_11 , V_84 ) ;
F_128 ( V_11 ) ;
F_59 ( V_11 , V_104 ) ;
}
static void F_198 ( struct V_6 * V_11 , struct V_81 * V_82 )
{
struct V_83 * V_84 = F_29 ( V_11 , struct V_83 , V_11 ) ;
F_163 ( ! F_199 ( V_11 , V_82 , V_84 ) ) ;
if ( V_84 -> V_7 != NULL ) {
F_2 ( L_71
L_72 ,
V_11 , V_11 -> V_138 / V_262 ) ;
F_61 ( V_84 ) ;
F_200 ( V_161 ,
& V_84 -> V_139 ,
V_11 -> V_138 ) ;
V_11 -> V_138 <<= 1 ;
if ( V_11 -> V_138 < V_207 )
V_11 -> V_138 = V_207 ;
if ( V_11 -> V_138 > V_281 )
V_11 -> V_138 = V_281 ;
} else {
F_2 ( L_73 , V_11 ) ;
F_200 ( V_161 ,
& V_84 -> V_139 , 0 ) ;
}
}
static void F_201 ( struct V_6 * V_11 , struct V_282 * V_283 )
{
long V_284 = 0 ;
if ( F_32 ( V_11 ) )
V_284 = ( long ) ( V_247 - V_11 -> V_285 ) / V_262 ;
F_202 ( V_283 , L_74
L_75 ,
V_11 -> V_244 . V_286 ,
V_11 -> V_244 . V_245 ,
V_11 -> V_244 . V_287 ,
V_284 ,
V_11 -> V_244 . V_288 ,
V_11 -> V_244 . V_289 ,
V_11 -> V_244 . V_290 ,
V_11 -> V_244 . V_291 ,
V_11 -> V_244 . V_292 ,
V_11 -> V_244 . V_293 ,
V_11 -> V_244 . V_294 ,
V_11 -> V_244 . V_295 ) ;
}
static void F_203 ( struct V_6 * V_11 , struct V_282 * V_283 )
{
struct V_83 * V_84 = F_29 ( V_11 , struct V_83 , V_11 ) ;
F_202 ( V_283 , L_76
L_77 ,
V_84 -> V_229 ,
V_11 -> V_244 . V_286 ,
V_11 -> V_244 . V_288 ,
V_11 -> V_244 . V_289 ,
V_11 -> V_244 . V_290 ,
V_11 -> V_244 . V_291 ,
V_11 -> V_244 . V_292 ,
V_11 -> V_244 . V_293 ,
V_11 -> V_244 . V_294 ,
V_11 -> V_244 . V_295 ) ;
}
static void F_204 ( struct V_6 * V_11 , struct V_282 * V_283 )
{
struct V_83 * V_84 = F_29 ( V_11 , struct V_83 , V_11 ) ;
long V_284 = 0 ;
if ( F_32 ( V_11 ) )
V_284 = ( long ) ( V_247 - V_11 -> V_285 ) / V_262 ;
F_202 ( V_283 , L_78
L_75 ,
V_84 -> V_229 ,
V_11 -> V_244 . V_286 ,
V_11 -> V_244 . V_245 ,
V_11 -> V_244 . V_287 ,
V_284 ,
V_11 -> V_244 . V_288 ,
V_11 -> V_244 . V_289 ,
V_11 -> V_244 . V_290 ,
V_11 -> V_244 . V_291 ,
V_11 -> V_244 . V_292 ,
V_11 -> V_244 . V_293 ,
V_11 -> V_244 . V_294 ,
V_11 -> V_244 . V_295 ) ;
}
static void * F_205 ( struct V_81 * V_82 , T_4 V_60 )
{
struct V_58 * V_58 ;
struct V_296 * V_4 ;
F_163 ( V_60 > V_297 - sizeof( struct V_296 ) ) ;
if ( V_60 > V_297 - sizeof( struct V_296 ) )
return NULL ;
V_58 = F_206 ( V_24 ) ;
if ( ! V_58 )
return NULL ;
V_4 = F_207 ( V_58 ) ;
V_4 -> V_73 = V_297 ;
return V_4 -> V_193 ;
}
static void F_208 ( void * V_298 )
{
struct V_296 * V_4 ;
if ( ! V_298 )
return;
V_4 = F_29 ( V_298 , struct V_296 , V_193 ) ;
F_209 ( ( unsigned long ) V_4 ) ;
}
static int F_210 ( struct V_89 * V_90 )
{
int V_73 ;
struct V_54 * V_299 = & V_90 -> V_103 ;
struct V_6 * V_11 = V_90 -> V_86 ;
struct V_83 * V_84 =
F_29 ( V_11 , struct V_83 , V_11 ) ;
struct V_39 * V_7 = V_84 -> V_7 ;
unsigned long V_300 ;
unsigned long V_301 ;
F_37 ( V_299 ) ;
V_301 = ( unsigned long ) V_299 -> V_80 [ 0 ] . V_52 & ~ V_69 ;
V_300 = ( unsigned long ) V_299 -> V_78 [ 0 ] . V_52 & ~ V_69 ;
V_73 = F_211 ( V_7 , V_299 ,
F_212 ( V_299 -> V_78 [ 0 ] . V_52 ) , V_300 ,
V_299 -> V_80 [ 0 ] . V_52 , V_301 ) ;
if ( V_73 != V_299 -> V_73 ) {
F_107 ( V_302 L_79 ) ;
V_73 = - V_92 ;
}
return V_73 ;
}
static int F_213 ( struct V_81 * V_82 )
{
struct V_89 * V_90 = V_82 -> V_85 ;
struct V_303 * V_11 ;
int V_73 ;
F_2 ( L_80 , F_12 ( V_90 -> V_185 ) ) ;
V_11 = V_90 -> V_86 -> V_304 ;
if ( ! F_214 ( & V_11 -> V_305 ) ) {
F_215 ( & V_11 -> V_306 , V_82 , NULL ) ;
if ( ! F_214 ( & V_11 -> V_305 ) )
return - V_92 ;
F_216 ( & V_11 -> V_306 , V_82 ) ;
}
if ( F_33 ( V_307 , & V_11 -> V_308 ) )
V_73 = - V_98 ;
else
V_73 = F_210 ( V_90 ) ;
F_69 ( & V_11 -> V_305 ) ;
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
F_73 ( V_11 ) ;
F_78 ( V_141 ) ;
}
static int F_219 ( const int V_239 , struct V_10 * V_16 )
{
static const struct V_14 sin = {
. V_309 = V_25 ,
. V_26 . V_27 = F_220 ( V_310 ) ,
} ;
static const struct V_15 V_17 = {
. V_311 = V_28 ,
. V_29 = V_312 ,
} ;
switch ( V_239 ) {
case V_20 :
break;
case V_25 :
memcpy ( V_16 , & sin , sizeof( sin ) ) ;
break;
case V_28 :
memcpy ( V_16 , & V_17 , sizeof( V_17 ) ) ;
break;
default:
F_2 ( L_82 , V_106 ) ;
return - V_313 ;
}
return 0 ;
}
static struct V_6 * F_221 ( struct V_314 * args ,
unsigned int V_315 ,
unsigned int V_316 )
{
struct V_6 * V_11 ;
struct V_83 * V_317 ;
if ( args -> V_40 > sizeof( V_11 -> V_12 ) ) {
F_2 ( L_83 ) ;
return F_168 ( - V_318 ) ;
}
V_11 = F_222 ( args -> V_188 , sizeof( * V_317 ) , V_315 ,
V_316 ) ;
if ( V_11 == NULL ) {
F_2 ( L_84
L_85 ) ;
return F_168 ( - V_319 ) ;
}
V_317 = F_29 ( V_11 , struct V_83 , V_11 ) ;
F_223 ( & V_317 -> V_137 ) ;
memcpy ( & V_11 -> V_12 , args -> V_320 , args -> V_40 ) ;
V_11 -> V_40 = args -> V_40 ;
if ( args -> V_234 )
memcpy ( & V_317 -> V_234 , args -> V_234 , args -> V_40 ) ;
else {
int V_64 ;
V_64 = F_219 ( args -> V_320 -> V_19 ,
(struct V_10 * ) & V_317 -> V_234 ) ;
if ( V_64 != 0 ) {
F_74 ( V_11 ) ;
return F_168 ( V_64 ) ;
}
}
return V_11 ;
}
static struct V_6 * F_224 ( struct V_314 * args )
{
struct V_13 * V_18 = (struct V_13 * ) args -> V_320 ;
struct V_83 * V_84 ;
struct V_6 * V_11 ;
struct V_6 * V_91 ;
V_11 = F_221 ( args , V_321 ,
V_322 ) ;
if ( F_188 ( V_11 ) )
return V_11 ;
V_84 = F_29 ( V_11 , struct V_83 , V_11 ) ;
V_11 -> V_323 = 0 ;
V_11 -> V_324 = sizeof( V_101 ) / sizeof( T_1 ) ;
V_11 -> V_325 = V_326 ;
V_11 -> V_327 = V_328 ;
V_11 -> V_138 = V_207 ;
V_11 -> V_329 = V_330 ;
V_11 -> V_70 = & V_331 ;
V_11 -> V_260 = & V_332 ;
F_225 ( & V_84 -> V_140 , F_88 ) ;
F_226 ( & V_84 -> V_139 ,
F_165 ) ;
switch ( V_18 -> V_333 ) {
case V_20 :
if ( V_18 -> V_21 [ 0 ] != '/' ) {
F_2 ( L_86 ,
V_18 -> V_21 ) ;
V_91 = F_168 ( - V_256 ) ;
goto V_334;
}
F_154 ( V_11 ) ;
F_16 ( V_11 , L_87 , V_335 ) ;
V_91 = F_168 ( F_171 ( V_84 ) ) ;
if ( V_91 )
goto V_334;
break;
default:
V_91 = F_168 ( - V_313 ) ;
goto V_334;
}
F_2 ( L_88 ,
V_11 -> V_22 [ V_23 ] ) ;
if ( F_227 ( V_141 ) )
return V_11 ;
V_91 = F_168 ( - V_256 ) ;
V_334:
F_73 ( V_11 ) ;
return V_91 ;
}
static struct V_6 * F_228 ( struct V_314 * args )
{
struct V_10 * V_12 = args -> V_320 ;
struct V_6 * V_11 ;
struct V_83 * V_84 ;
struct V_6 * V_91 ;
V_11 = F_221 ( args , V_336 ,
V_336 ) ;
if ( F_188 ( V_11 ) )
return V_11 ;
V_84 = F_29 ( V_11 , struct V_83 , V_11 ) ;
V_11 -> V_323 = V_258 ;
V_11 -> V_324 = 0 ;
V_11 -> V_325 = ( 1U << 16 ) - ( V_337 << 3 ) ;
V_11 -> V_327 = V_328 ;
V_11 -> V_138 = V_338 ;
V_11 -> V_329 = V_330 ;
V_11 -> V_70 = & V_339 ;
V_11 -> V_260 = & V_340 ;
F_225 ( & V_84 -> V_140 , F_94 ) ;
F_226 ( & V_84 -> V_139 , F_187 ) ;
switch ( V_12 -> V_19 ) {
case V_25 :
if ( ( (struct V_14 * ) V_12 ) -> V_228 != F_229 ( 0 ) )
F_154 ( V_11 ) ;
F_16 ( V_11 , L_89 , V_341 ) ;
break;
case V_28 :
if ( ( (struct V_15 * ) V_12 ) -> V_227 != F_229 ( 0 ) )
F_154 ( V_11 ) ;
F_16 ( V_11 , L_89 , V_342 ) ;
break;
default:
V_91 = F_168 ( - V_313 ) ;
goto V_334;
}
if ( F_44 ( V_11 ) )
F_2 ( L_90 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
else
F_2 ( L_91 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_35 ] ) ;
if ( F_227 ( V_141 ) )
return V_11 ;
V_91 = F_168 ( - V_256 ) ;
V_334:
F_73 ( V_11 ) ;
return V_91 ;
}
static struct V_6 * F_230 ( struct V_314 * args )
{
struct V_10 * V_12 = args -> V_320 ;
struct V_6 * V_11 ;
struct V_83 * V_84 ;
struct V_6 * V_91 ;
unsigned int V_316 = V_322 ;
if ( args -> V_61 & V_343 )
V_316 = V_344 ;
V_11 = F_221 ( args , V_321 ,
V_316 ) ;
if ( F_188 ( V_11 ) )
return V_11 ;
V_84 = F_29 ( V_11 , struct V_83 , V_11 ) ;
V_11 -> V_323 = V_278 ;
V_11 -> V_324 = sizeof( V_101 ) / sizeof( T_1 ) ;
V_11 -> V_325 = V_326 ;
V_11 -> V_327 = V_328 ;
V_11 -> V_138 = V_207 ;
V_11 -> V_329 = V_330 ;
V_11 -> V_70 = & V_345 ;
V_11 -> V_260 = & V_346 ;
F_225 ( & V_84 -> V_140 , F_121 ) ;
F_226 ( & V_84 -> V_139 , F_196 ) ;
switch ( V_12 -> V_19 ) {
case V_25 :
if ( ( (struct V_14 * ) V_12 ) -> V_228 != F_229 ( 0 ) )
F_154 ( V_11 ) ;
F_16 ( V_11 , L_92 , V_347 ) ;
break;
case V_28 :
if ( ( (struct V_15 * ) V_12 ) -> V_227 != F_229 ( 0 ) )
F_154 ( V_11 ) ;
F_16 ( V_11 , L_92 , V_348 ) ;
break;
default:
V_91 = F_168 ( - V_313 ) ;
goto V_334;
}
if ( F_44 ( V_11 ) )
F_2 ( L_90 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
else
F_2 ( L_91 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_35 ] ) ;
if ( F_227 ( V_141 ) )
return V_11 ;
V_91 = F_168 ( - V_256 ) ;
V_334:
F_73 ( V_11 ) ;
return V_91 ;
}
static struct V_6 * F_231 ( struct V_314 * args )
{
struct V_10 * V_12 = args -> V_320 ;
struct V_6 * V_11 ;
struct V_83 * V_84 ;
struct V_349 * V_350 ;
struct V_6 * V_91 ;
V_11 = F_221 ( args , V_321 ,
V_321 ) ;
if ( F_188 ( V_11 ) )
return V_11 ;
V_84 = F_29 ( V_11 , struct V_83 , V_11 ) ;
V_11 -> V_323 = V_278 ;
V_11 -> V_324 = sizeof( V_101 ) / sizeof( T_1 ) ;
V_11 -> V_325 = V_326 ;
V_11 -> V_260 = & V_346 ;
F_154 ( V_11 ) ;
V_11 -> V_327 = 0 ;
V_11 -> V_138 = 0 ;
V_11 -> V_329 = 0 ;
V_11 -> V_70 = & V_351 ;
switch ( V_12 -> V_19 ) {
case V_25 :
F_16 ( V_11 , L_92 ,
V_347 ) ;
break;
case V_28 :
F_16 ( V_11 , L_92 ,
V_348 ) ;
break;
default:
V_91 = F_168 ( - V_313 ) ;
goto V_334;
}
F_2 ( L_90 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
F_232 ( V_11 ) ;
args -> V_304 -> V_352 = V_11 ;
V_11 -> V_304 = args -> V_304 ;
V_350 = F_29 ( args -> V_304 , struct V_349 , V_353 ) ;
V_84 -> V_7 = V_350 -> V_354 ;
V_84 -> V_87 = V_350 -> V_355 ;
F_173 ( V_11 ) ;
if ( F_227 ( V_141 ) )
return V_11 ;
args -> V_304 -> V_352 = NULL ;
F_233 ( V_11 ) ;
V_91 = F_168 ( - V_256 ) ;
V_334:
F_73 ( V_11 ) ;
return V_91 ;
}
int F_234 ( void )
{
#if F_235 ( V_356 )
if ( ! V_357 )
V_357 = F_236 ( V_358 ) ;
#endif
F_237 ( & V_359 ) ;
F_237 ( & V_360 ) ;
F_237 ( & V_361 ) ;
F_237 ( & V_362 ) ;
return 0 ;
}
void F_238 ( void )
{
#if F_235 ( V_356 )
if ( V_357 ) {
F_239 ( V_357 ) ;
V_357 = NULL ;
}
#endif
F_240 ( & V_359 ) ;
F_240 ( & V_360 ) ;
F_240 ( & V_361 ) ;
F_240 ( & V_362 ) ;
}
static int F_241 ( const char * V_363 ,
const struct V_364 * V_365 ,
unsigned int V_366 , unsigned int V_367 )
{
unsigned int V_368 ;
int V_91 ;
if ( ! V_363 )
return - V_256 ;
V_91 = F_242 ( V_363 , 0 , & V_368 ) ;
if ( V_91 == - V_256 || V_368 < V_366 || V_368 > V_367 )
return - V_256 ;
* ( ( unsigned int * ) V_365 -> V_192 ) = V_368 ;
return 0 ;
}
static int F_243 ( const char * V_363 , const struct V_364 * V_365 )
{
return F_241 ( V_363 , V_365 ,
V_369 ,
V_370 ) ;
}
static int F_244 ( const char * V_363 ,
const struct V_364 * V_365 )
{
return F_241 ( V_363 , V_365 ,
V_371 ,
V_372 ) ;
}
static int F_245 ( const char * V_363 ,
const struct V_364 * V_365 )
{
return F_241 ( V_363 , V_365 ,
V_371 ,
V_344 ) ;
}

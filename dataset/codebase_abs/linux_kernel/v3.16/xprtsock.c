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
static int F_22 ( struct V_39 * V_7 , struct V_54 * V_55 , unsigned int V_43 , int V_44 , bool V_56 )
{
T_3 (* F_23)( struct V_39 * V_7 , struct V_57 * V_57 ,
int V_58 , T_4 V_59 , int V_60 );
struct V_57 * * V_61 ;
unsigned int V_62 ;
int V_63 , V_64 = 0 ;
V_62 = V_55 -> V_65 - V_43 ;
V_43 += V_55 -> V_66 ;
V_61 = V_55 -> V_67 + ( V_43 >> V_68 ) ;
V_43 &= ~ V_69 ;
F_23 = V_7 -> V_70 -> V_71 ;
if ( ! V_56 )
F_23 = V_72 ;
for(; ; ) {
unsigned int V_73 = F_24 (unsigned int, PAGE_SIZE - base, remainder) ;
int V_60 = V_49 ;
V_62 -= V_73 ;
if ( V_62 != 0 || V_44 )
V_60 |= V_50 ;
V_63 = F_23 ( V_7 , * V_61 , V_43 , V_73 , V_60 ) ;
if ( V_62 == 0 || V_63 != V_73 )
break;
V_64 += V_63 ;
V_61 ++ ;
V_43 = 0 ;
}
if ( V_64 == 0 )
return V_63 ;
if ( V_63 > 0 )
V_64 += V_63 ;
return V_64 ;
}
static int F_25 ( struct V_39 * V_7 , struct V_10 * V_12 , int V_40 , struct V_54 * V_55 , unsigned int V_43 , bool V_56 )
{
unsigned int V_62 = V_55 -> V_73 - V_43 ;
int V_63 , V_64 = 0 ;
if ( F_26 ( ! V_7 ) )
return - V_74 ;
F_27 ( V_75 , & V_7 -> V_60 ) ;
if ( V_43 != 0 ) {
V_12 = NULL ;
V_40 = 0 ;
}
if ( V_43 < V_55 -> V_76 [ 0 ] . V_53 || V_12 != NULL ) {
unsigned int V_73 = V_55 -> V_76 [ 0 ] . V_53 - V_43 ;
V_62 -= V_73 ;
V_63 = F_20 ( V_7 , V_12 , V_40 , & V_55 -> V_76 [ 0 ] , V_43 , V_62 != 0 ) ;
if ( V_62 == 0 || V_63 != V_73 )
goto V_77;
V_64 += V_63 ;
V_43 = 0 ;
} else
V_43 -= V_55 -> V_76 [ 0 ] . V_53 ;
if ( V_43 < V_55 -> V_65 ) {
unsigned int V_73 = V_55 -> V_65 - V_43 ;
V_62 -= V_73 ;
V_63 = F_22 ( V_7 , V_55 , V_43 , V_62 != 0 , V_56 ) ;
if ( V_62 == 0 || V_63 != V_73 )
goto V_77;
V_64 += V_63 ;
V_43 = 0 ;
} else
V_43 -= V_55 -> V_65 ;
if ( V_43 >= V_55 -> V_78 [ 0 ] . V_53 )
return V_64 ;
V_63 = F_20 ( V_7 , NULL , 0 , & V_55 -> V_78 [ 0 ] , V_43 , 0 ) ;
V_77:
if ( V_64 == 0 )
return V_63 ;
if ( V_63 > 0 )
V_64 += V_63 ;
return V_64 ;
}
static void F_28 ( struct V_79 * V_80 )
{
struct V_81 * V_82 = F_29 ( V_80 -> V_83 -> V_84 , struct V_81 , V_11 ) ;
V_82 -> V_85 -> V_86 -- ;
F_27 ( V_75 , & V_82 -> V_7 -> V_60 ) ;
}
static int F_30 ( struct V_79 * V_80 )
{
struct V_87 * V_88 = V_80 -> V_83 ;
struct V_6 * V_11 = V_88 -> V_84 ;
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
struct V_7 * V_8 = V_82 -> V_85 ;
int V_89 = - V_90 ;
F_2 ( L_9 ,
V_80 -> V_91 , V_88 -> V_92 - V_88 -> V_93 ,
V_88 -> V_92 ) ;
F_31 ( & V_11 -> V_94 ) ;
if ( F_32 ( V_11 ) ) {
if ( F_33 ( V_75 , & V_82 -> V_7 -> V_60 ) ) {
F_34 ( V_95 , & V_82 -> V_7 -> V_60 ) ;
V_8 -> V_86 ++ ;
F_35 ( V_80 , F_28 ) ;
}
} else {
F_27 ( V_75 , & V_82 -> V_7 -> V_60 ) ;
V_89 = - V_96 ;
}
F_36 ( & V_11 -> V_94 ) ;
V_8 -> V_97 ( V_8 ) ;
return V_89 ;
}
static inline void F_37 ( struct V_54 * V_4 )
{
T_1 V_98 = V_4 -> V_73 - sizeof( V_99 ) ;
V_99 * V_43 = V_4 -> V_76 [ 0 ] . V_52 ;
* V_43 = F_38 ( V_100 | V_98 ) ;
}
static int F_39 ( struct V_79 * V_80 )
{
struct V_87 * V_88 = V_80 -> V_83 ;
struct V_6 * V_11 = V_88 -> V_84 ;
struct V_81 * V_82 =
F_29 ( V_11 , struct V_81 , V_11 ) ;
struct V_54 * V_55 = & V_88 -> V_101 ;
int V_102 ;
F_37 ( & V_88 -> V_101 ) ;
F_1 ( L_10 ,
V_88 -> V_103 -> V_52 , V_88 -> V_103 -> V_53 ) ;
V_102 = F_25 ( V_82 -> V_7 , NULL , 0 ,
V_55 , V_88 -> V_93 , true ) ;
F_2 ( L_11 ,
V_104 , V_55 -> V_73 - V_88 -> V_93 , V_102 ) ;
if ( F_40 ( V_102 >= 0 ) ) {
V_88 -> V_93 += V_102 ;
V_88 -> V_105 += V_102 ;
if ( F_40 ( V_88 -> V_93 >= V_88 -> V_92 ) ) {
V_88 -> V_93 = 0 ;
return 0 ;
}
V_102 = - V_90 ;
}
switch ( V_102 ) {
case - V_90 :
V_102 = F_30 ( V_80 ) ;
break;
default:
F_2 ( L_12 ,
- V_102 ) ;
case - V_106 :
F_41 ( V_11 ) ;
V_102 = - V_96 ;
}
return V_102 ;
}
static int F_42 ( struct V_79 * V_80 )
{
struct V_87 * V_88 = V_80 -> V_83 ;
struct V_6 * V_11 = V_88 -> V_84 ;
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
struct V_54 * V_55 = & V_88 -> V_101 ;
int V_102 ;
F_1 ( L_10 ,
V_88 -> V_103 -> V_52 ,
V_88 -> V_103 -> V_53 ) ;
if ( ! F_43 ( V_11 ) )
return - V_96 ;
V_102 = F_25 ( V_82 -> V_7 ,
F_4 ( V_11 ) ,
V_11 -> V_40 , V_55 ,
V_88 -> V_93 , true ) ;
F_2 ( L_13 ,
V_55 -> V_73 - V_88 -> V_93 , V_102 ) ;
if ( V_102 >= 0 ) {
V_88 -> V_105 += V_102 ;
if ( V_102 >= V_88 -> V_92 )
return 0 ;
V_102 = - V_90 ;
}
switch ( V_102 ) {
case - V_74 :
V_102 = - V_96 ;
break;
case - V_90 :
V_102 = F_30 ( V_80 ) ;
break;
default:
F_2 ( L_12 ,
- V_102 ) ;
case - V_107 :
case - V_106 :
case - V_108 :
F_27 ( V_75 , & V_82 -> V_7 -> V_60 ) ;
}
return V_102 ;
}
static void F_44 ( struct V_6 * V_11 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
struct V_39 * V_7 = V_82 -> V_7 ;
if ( V_7 != NULL ) {
F_45 ( V_7 , V_109 ) ;
F_46 ( V_11 , V_7 ) ;
}
}
static int F_47 ( struct V_79 * V_80 )
{
struct V_87 * V_88 = V_80 -> V_83 ;
struct V_6 * V_11 = V_88 -> V_84 ;
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
struct V_54 * V_55 = & V_88 -> V_101 ;
bool V_56 = true ;
int V_102 ;
F_37 ( & V_88 -> V_101 ) ;
F_1 ( L_10 ,
V_88 -> V_103 -> V_52 ,
V_88 -> V_103 -> V_53 ) ;
if ( V_80 -> V_110 & V_111 )
V_56 = false ;
while ( 1 ) {
V_102 = F_25 ( V_82 -> V_7 ,
NULL , 0 , V_55 , V_88 -> V_93 ,
V_56 ) ;
F_2 ( L_14 ,
V_55 -> V_73 - V_88 -> V_93 , V_102 ) ;
if ( F_26 ( V_102 < 0 ) )
break;
V_88 -> V_93 += V_102 ;
V_88 -> V_105 += V_102 ;
if ( F_40 ( V_88 -> V_93 >= V_88 -> V_92 ) ) {
V_88 -> V_93 = 0 ;
return 0 ;
}
if ( V_102 != 0 )
continue;
V_102 = - V_90 ;
break;
}
switch ( V_102 ) {
case - V_74 :
V_102 = - V_96 ;
break;
case - V_90 :
V_102 = F_30 ( V_80 ) ;
break;
default:
F_2 ( L_12 ,
- V_102 ) ;
case - V_112 :
F_44 ( V_11 ) ;
case - V_108 :
case - V_96 :
case - V_106 :
F_27 ( V_75 , & V_82 -> V_7 -> V_60 ) ;
}
return V_102 ;
}
static void F_48 ( struct V_6 * V_11 , struct V_79 * V_80 )
{
struct V_87 * V_88 ;
if ( V_80 != V_11 -> V_113 )
return;
if ( V_80 == NULL )
goto V_114;
V_88 = V_80 -> V_83 ;
if ( V_88 == NULL )
goto V_114;
if ( V_88 -> V_93 == 0 )
goto V_114;
if ( V_88 -> V_93 == V_88 -> V_101 . V_73 )
goto V_114;
F_34 ( V_115 , & V_11 -> V_116 ) ;
V_114:
F_49 ( V_11 , V_80 ) ;
}
static void F_50 ( struct V_81 * V_82 , struct V_7 * V_8 )
{
V_82 -> V_117 = V_8 -> V_118 ;
V_82 -> V_119 = V_8 -> V_120 ;
V_82 -> V_121 = V_8 -> V_97 ;
V_82 -> V_122 = V_8 -> V_123 ;
}
static void F_51 ( struct V_81 * V_82 , struct V_7 * V_8 )
{
V_8 -> V_118 = V_82 -> V_117 ;
V_8 -> V_120 = V_82 -> V_119 ;
V_8 -> V_97 = V_82 -> V_121 ;
V_8 -> V_123 = V_82 -> V_122 ;
}
static void F_52 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
int V_63 ;
F_53 ( & V_8 -> V_124 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_77;
V_63 = - V_8 -> V_125 ;
if ( V_63 == 0 )
goto V_77;
F_2 ( L_15 ,
V_11 , - V_63 ) ;
F_54 ( V_11 , V_8 -> V_126 , V_63 ) ;
F_55 ( V_11 , V_63 ) ;
V_77:
F_56 ( & V_8 -> V_124 ) ;
}
static void F_57 ( struct V_81 * V_82 )
{
struct V_39 * V_7 = V_82 -> V_7 ;
struct V_7 * V_8 = V_82 -> V_85 ;
if ( V_8 == NULL )
return;
V_82 -> V_127 = 0 ;
F_58 ( & V_8 -> V_124 ) ;
V_82 -> V_85 = NULL ;
V_82 -> V_7 = NULL ;
V_8 -> V_9 = NULL ;
F_51 ( V_82 , V_8 ) ;
F_59 ( & V_8 -> V_124 ) ;
F_60 ( & V_82 -> V_11 , V_7 ) ;
F_61 ( V_7 ) ;
}
static void F_41 ( struct V_6 * V_11 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
F_2 ( L_16 , V_11 ) ;
F_62 ( & V_82 -> V_128 ) ;
F_57 ( V_82 ) ;
V_11 -> V_129 = 0 ;
F_63 () ;
F_27 ( V_130 , & V_11 -> V_116 ) ;
F_27 ( V_115 , & V_11 -> V_116 ) ;
F_27 ( V_131 , & V_11 -> V_116 ) ;
F_64 () ;
F_65 ( V_11 ) ;
}
static void F_66 ( struct V_6 * V_11 )
{
if ( F_67 ( V_132 , & V_11 -> V_116 ) )
F_41 ( V_11 ) ;
else
F_44 ( V_11 ) ;
}
static void F_68 ( struct V_6 * V_11 )
{
F_19 ( V_11 ) ;
F_69 ( V_11 ) ;
}
static void F_70 ( struct V_6 * V_11 )
{
F_2 ( L_17 , V_11 ) ;
F_41 ( V_11 ) ;
F_68 ( V_11 ) ;
F_71 ( V_133 ) ;
}
static int F_72 ( struct V_54 * V_55 , struct V_134 * V_135 )
{
struct V_136 V_137 = {
. V_135 = V_135 ,
. V_58 = sizeof( V_99 ) ,
. V_3 = V_135 -> V_73 - sizeof( V_99 ) ,
} ;
if ( F_73 ( V_55 , 0 , & V_137 , V_138 ) < 0 )
return - 1 ;
if ( V_137 . V_3 )
return - 1 ;
return 0 ;
}
static void F_74 ( struct V_7 * V_8 )
{
struct V_79 * V_80 ;
struct V_6 * V_11 ;
struct V_87 * V_139 ;
struct V_134 * V_135 ;
int V_63 , V_140 , V_141 ;
T_1 V_142 ;
T_5 * V_143 ;
F_53 ( & V_8 -> V_124 ) ;
F_2 ( L_18 , V_104 ) ;
V_11 = F_3 ( V_8 ) ;
if ( V_11 == NULL )
goto V_77;
V_135 = F_75 ( V_8 , 0 , 1 , & V_63 ) ;
if ( V_135 == NULL )
goto V_77;
V_140 = V_135 -> V_73 - sizeof( V_99 ) ;
if ( V_140 < 4 ) {
F_2 ( L_19 , V_140 ) ;
goto V_144;
}
V_143 = F_76 ( V_135 , sizeof( V_99 ) , sizeof( V_142 ) , & V_142 ) ;
if ( V_143 == NULL )
goto V_144;
F_77 ( & V_11 -> V_94 ) ;
V_139 = F_78 ( V_11 , * V_143 ) ;
if ( ! V_139 )
goto V_145;
V_80 = V_139 -> V_146 ;
V_141 = V_139 -> V_147 . V_148 ;
if ( V_141 > V_140 )
V_141 = V_140 ;
if ( F_72 ( & V_139 -> V_147 , V_135 ) ) {
F_2 ( L_20 ) ;
goto V_145;
}
F_79 ( V_80 , V_141 ) ;
V_145:
F_80 ( & V_11 -> V_94 ) ;
V_144:
F_81 ( V_8 , V_135 ) ;
V_77:
F_56 ( & V_8 -> V_124 ) ;
}
static void F_82 ( struct V_7 * V_8 )
{
struct V_79 * V_80 ;
struct V_6 * V_11 ;
struct V_87 * V_139 ;
struct V_134 * V_135 ;
int V_63 , V_140 , V_141 ;
T_1 V_142 ;
T_5 * V_143 ;
F_53 ( & V_8 -> V_124 ) ;
F_2 ( L_21 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_77;
if ( ( V_135 = F_75 ( V_8 , 0 , 1 , & V_63 ) ) == NULL )
goto V_77;
V_140 = V_135 -> V_73 - sizeof( struct V_149 ) ;
if ( V_140 < 4 ) {
F_2 ( L_22 , V_140 ) ;
goto V_144;
}
V_143 = F_76 ( V_135 , sizeof( struct V_149 ) ,
sizeof( V_142 ) , & V_142 ) ;
if ( V_143 == NULL )
goto V_144;
F_77 ( & V_11 -> V_94 ) ;
V_139 = F_78 ( V_11 , * V_143 ) ;
if ( ! V_139 )
goto V_145;
V_80 = V_139 -> V_146 ;
if ( ( V_141 = V_139 -> V_147 . V_148 ) > V_140 )
V_141 = V_140 ;
if ( F_83 ( & V_139 -> V_147 , V_135 ) ) {
F_84 ( V_8 , V_150 ) ;
goto V_145;
}
F_84 ( V_8 , V_151 ) ;
F_85 ( V_11 , V_80 , V_141 ) ;
F_79 ( V_80 , V_141 ) ;
V_145:
F_80 ( & V_11 -> V_94 ) ;
V_144:
F_81 ( V_8 , V_135 ) ;
V_77:
F_56 ( & V_8 -> V_124 ) ;
}
static void F_86 ( struct V_6 * V_11 )
{
F_34 ( V_132 , & V_11 -> V_116 ) ;
F_87 ( V_11 ) ;
}
static inline void F_88 ( struct V_6 * V_11 , struct V_136 * V_137 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
T_4 V_73 , V_152 ;
char * V_153 ;
V_153 = ( ( char * ) & V_82 -> V_154 ) + V_82 -> V_155 ;
V_73 = sizeof( V_82 -> V_154 ) - V_82 -> V_155 ;
V_152 = V_138 ( V_137 , V_153 , V_73 ) ;
V_82 -> V_155 += V_152 ;
if ( V_152 != V_73 )
return;
V_82 -> V_156 = F_12 ( V_82 -> V_154 ) ;
if ( V_82 -> V_156 & V_100 )
V_82 -> V_157 |= V_158 ;
else
V_82 -> V_157 &= ~ V_158 ;
V_82 -> V_156 &= V_159 ;
V_82 -> V_157 &= ~ V_160 ;
V_82 -> V_155 = 0 ;
if ( F_26 ( V_82 -> V_156 < 8 ) ) {
F_2 ( L_23 ) ;
F_86 ( V_11 ) ;
return;
}
F_2 ( L_24 ,
V_82 -> V_156 ) ;
}
static void F_89 ( struct V_81 * V_82 )
{
if ( V_82 -> V_155 == V_82 -> V_156 ) {
V_82 -> V_157 |= V_160 ;
V_82 -> V_155 = 0 ;
if ( V_82 -> V_157 & V_158 ) {
V_82 -> V_157 &= ~ V_161 ;
V_82 -> V_157 |= V_162 ;
V_82 -> V_163 = 0 ;
}
}
}
static inline void F_90 ( struct V_81 * V_82 , struct V_136 * V_137 )
{
T_4 V_73 , V_152 ;
char * V_153 ;
V_73 = sizeof( V_82 -> V_164 ) - V_82 -> V_155 ;
F_2 ( L_25 , V_73 ) ;
V_153 = ( ( char * ) & V_82 -> V_164 ) + V_82 -> V_155 ;
V_152 = V_138 ( V_137 , V_153 , V_73 ) ;
V_82 -> V_155 += V_152 ;
if ( V_152 != V_73 )
return;
V_82 -> V_157 &= ~ V_162 ;
V_82 -> V_157 |= V_165 ;
V_82 -> V_163 = 4 ;
F_2 ( L_26 ,
( V_82 -> V_157 & V_166 ) ? L_27
: L_28 ,
F_12 ( V_82 -> V_164 ) ) ;
F_89 ( V_82 ) ;
}
static inline void F_91 ( struct V_81 * V_82 ,
struct V_136 * V_137 )
{
T_4 V_73 , V_152 ;
T_1 V_58 ;
char * V_153 ;
V_58 = V_82 -> V_155 - sizeof( V_82 -> V_164 ) ;
V_73 = sizeof( V_82 -> V_167 ) - V_58 ;
F_2 ( L_29 , V_73 ) ;
V_153 = ( ( char * ) & V_82 -> V_167 ) + V_58 ;
V_152 = V_138 ( V_137 , V_153 , V_73 ) ;
V_82 -> V_155 += V_152 ;
if ( V_152 != V_73 )
return;
V_82 -> V_157 &= ~ V_165 ;
switch ( F_12 ( V_82 -> V_167 ) ) {
case V_168 :
V_82 -> V_157 |= V_169 ;
V_82 -> V_157 |= V_161 ;
V_82 -> V_157 |= V_166 ;
break;
case V_170 :
V_82 -> V_157 |= V_169 ;
V_82 -> V_157 |= V_161 ;
V_82 -> V_157 &= ~ V_166 ;
break;
default:
F_2 ( L_30 ) ;
F_86 ( & V_82 -> V_11 ) ;
}
F_89 ( V_82 ) ;
}
static inline void F_92 ( struct V_6 * V_11 ,
struct V_136 * V_137 ,
struct V_87 * V_88 )
{
struct V_81 * V_82 =
F_29 ( V_11 , struct V_81 , V_11 ) ;
struct V_54 * V_171 ;
T_4 V_73 ;
T_3 V_172 ;
V_171 = & V_88 -> V_147 ;
if ( V_82 -> V_157 & V_169 ) {
memcpy ( V_171 -> V_76 [ 0 ] . V_52 + V_82 -> V_163 ,
& V_82 -> V_167 ,
sizeof( V_82 -> V_167 ) ) ;
V_82 -> V_163 += sizeof( V_82 -> V_167 ) ;
V_82 -> V_157 &= ~ V_169 ;
}
V_73 = V_137 -> V_3 ;
if ( V_73 > V_82 -> V_156 - V_82 -> V_155 ) {
struct V_136 V_173 ;
V_73 = V_82 -> V_156 - V_82 -> V_155 ;
memcpy ( & V_173 , V_137 , sizeof( V_173 ) ) ;
V_173 . V_3 = V_73 ;
V_172 = F_73 ( V_171 , V_82 -> V_163 ,
& V_173 , V_138 ) ;
V_137 -> V_3 -= V_172 ;
V_137 -> V_58 += V_172 ;
} else
V_172 = F_73 ( V_171 , V_82 -> V_163 ,
V_137 , V_138 ) ;
if ( V_172 > 0 ) {
V_82 -> V_163 += V_172 ;
V_82 -> V_155 += V_172 ;
}
if ( V_172 != V_73 ) {
V_82 -> V_157 &= ~ V_161 ;
F_2 ( L_31 ,
F_12 ( V_82 -> V_164 ) ) ;
F_2 ( L_32
L_33 ,
V_11 , V_82 -> V_163 ,
V_82 -> V_155 , V_82 -> V_156 ) ;
return;
}
F_2 ( L_34 ,
F_12 ( V_82 -> V_164 ) , V_172 ) ;
F_2 ( L_35
L_36 , V_11 , V_82 -> V_163 ,
V_82 -> V_155 , V_82 -> V_156 ) ;
if ( V_82 -> V_163 == V_88 -> V_147 . V_148 )
V_82 -> V_157 &= ~ V_161 ;
else if ( V_82 -> V_155 == V_82 -> V_156 ) {
if ( V_82 -> V_157 & V_158 )
V_82 -> V_157 &= ~ V_161 ;
}
}
static inline int F_93 ( struct V_6 * V_11 ,
struct V_136 * V_137 )
{
struct V_81 * V_82 =
F_29 ( V_11 , struct V_81 , V_11 ) ;
struct V_87 * V_88 ;
F_2 ( L_37 , F_12 ( V_82 -> V_164 ) ) ;
F_77 ( & V_11 -> V_94 ) ;
V_88 = F_78 ( V_11 , V_82 -> V_164 ) ;
if ( ! V_88 ) {
F_2 ( L_38 ,
F_12 ( V_82 -> V_164 ) ) ;
F_80 ( & V_11 -> V_94 ) ;
return - 1 ;
}
F_92 ( V_11 , V_137 , V_88 ) ;
if ( ! ( V_82 -> V_157 & V_161 ) )
F_79 ( V_88 -> V_146 , V_82 -> V_163 ) ;
F_80 ( & V_11 -> V_94 ) ;
return 0 ;
}
static int F_94 ( struct V_6 * V_11 ,
struct V_136 * V_137 )
{
struct V_81 * V_82 =
F_29 ( V_11 , struct V_81 , V_11 ) ;
struct V_87 * V_88 ;
F_77 ( & V_11 -> V_94 ) ;
V_88 = F_95 ( V_11 , V_82 -> V_164 ) ;
if ( V_88 == NULL ) {
F_80 ( & V_11 -> V_94 ) ;
F_96 ( V_174 L_39 ) ;
F_87 ( V_11 ) ;
return - 1 ;
}
F_2 ( L_40 , F_12 ( V_88 -> V_175 ) ) ;
F_92 ( V_11 , V_137 , V_88 ) ;
if ( ! ( V_82 -> V_157 & V_161 ) )
F_97 ( V_88 , V_82 -> V_163 ) ;
F_80 ( & V_11 -> V_94 ) ;
return 0 ;
}
static inline int F_98 ( struct V_6 * V_11 ,
struct V_136 * V_137 )
{
struct V_81 * V_82 =
F_29 ( V_11 , struct V_81 , V_11 ) ;
return ( V_82 -> V_157 & V_166 ) ?
F_93 ( V_11 , V_137 ) :
F_94 ( V_11 , V_137 ) ;
}
static inline int F_98 ( struct V_6 * V_11 ,
struct V_136 * V_137 )
{
return F_93 ( V_11 , V_137 ) ;
}
static void F_99 ( struct V_6 * V_11 ,
struct V_136 * V_137 )
{
struct V_81 * V_82 =
F_29 ( V_11 , struct V_81 , V_11 ) ;
if ( F_98 ( V_11 , V_137 ) == 0 )
F_89 ( V_82 ) ;
else {
V_82 -> V_157 &= ~ V_161 ;
}
}
static inline void F_100 ( struct V_81 * V_82 , struct V_136 * V_137 )
{
T_4 V_73 ;
V_73 = V_82 -> V_156 - V_82 -> V_155 ;
if ( V_73 > V_137 -> V_3 )
V_73 = V_137 -> V_3 ;
V_137 -> V_3 -= V_73 ;
V_137 -> V_58 += V_73 ;
V_82 -> V_155 += V_73 ;
F_2 ( L_41 , V_73 ) ;
F_89 ( V_82 ) ;
}
static int F_101 ( T_6 * V_176 , struct V_134 * V_135 , unsigned int V_58 , T_4 V_73 )
{
struct V_6 * V_11 = V_176 -> V_177 . V_178 ;
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
struct V_136 V_137 = {
. V_135 = V_135 ,
. V_58 = V_58 ,
. V_3 = V_73 ,
} ;
F_2 ( L_42 ) ;
do {
if ( V_82 -> V_157 & V_160 ) {
F_88 ( V_11 , & V_137 ) ;
continue;
}
if ( V_82 -> V_157 & V_162 ) {
F_90 ( V_82 , & V_137 ) ;
continue;
}
if ( V_82 -> V_157 & V_165 ) {
F_91 ( V_82 , & V_137 ) ;
continue;
}
if ( V_82 -> V_157 & V_161 ) {
F_99 ( V_11 , & V_137 ) ;
continue;
}
F_100 ( V_82 , & V_137 ) ;
} while ( V_137 . V_3 );
F_2 ( L_43 ) ;
return V_73 - V_137 . V_3 ;
}
static void F_102 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
T_6 V_176 ;
int V_179 ;
F_2 ( L_44 ) ;
F_53 ( & V_8 -> V_124 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_77;
if ( V_11 -> V_129 )
V_11 -> V_129 = 0 ;
V_176 . V_177 . V_178 = V_11 ;
do {
V_176 . V_3 = 65536 ;
V_179 = F_103 ( V_8 , & V_176 , F_101 ) ;
} while ( V_179 > 0 );
V_77:
F_56 ( & V_8 -> V_124 ) ;
}
static void F_104 ( struct V_6 * V_11 ,
unsigned long V_180 )
{
struct V_81 * V_82 ;
if ( F_105 ( V_11 ) )
return;
F_34 ( V_130 , & V_11 -> V_116 ) ;
V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
F_106 ( V_181 , & V_82 -> V_128 ,
V_180 ) ;
}
static void F_107 ( struct V_6 * V_11 )
{
struct V_81 * V_82 ;
V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
if ( ! F_33 ( V_130 , & V_11 -> V_116 ) ||
! F_108 ( & V_82 -> V_128 ) )
return;
F_27 ( V_130 , & V_11 -> V_116 ) ;
F_109 ( V_11 ) ;
}
static void F_110 ( struct V_6 * V_11 )
{
F_63 () ;
F_27 ( V_130 , & V_11 -> V_116 ) ;
F_27 ( V_132 , & V_11 -> V_116 ) ;
F_27 ( V_115 , & V_11 -> V_116 ) ;
F_27 ( V_131 , & V_11 -> V_116 ) ;
F_64 () ;
}
static void F_111 ( struct V_6 * V_11 )
{
F_110 ( V_11 ) ;
F_65 ( V_11 ) ;
}
static void F_112 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
F_53 ( & V_8 -> V_124 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_77;
F_2 ( L_45 , V_11 ) ;
F_2 ( L_46 ,
V_8 -> V_182 , F_32 ( V_11 ) ,
F_113 ( V_8 , V_183 ) ,
F_113 ( V_8 , V_184 ) ,
V_8 -> V_185 ) ;
F_114 ( V_11 , V_8 -> V_126 ) ;
switch ( V_8 -> V_182 ) {
case V_186 :
F_77 ( & V_11 -> V_94 ) ;
if ( ! F_115 ( V_11 ) ) {
struct V_81 * V_82 = F_29 ( V_11 ,
struct V_81 , V_11 ) ;
V_82 -> V_155 = 0 ;
V_82 -> V_156 = 0 ;
V_82 -> V_163 = 0 ;
V_82 -> V_157 =
V_160 | V_162 ;
V_11 -> V_187 ++ ;
F_55 ( V_11 , - V_90 ) ;
}
F_80 ( & V_11 -> V_94 ) ;
break;
case V_188 :
V_11 -> V_187 ++ ;
V_11 -> V_129 = 0 ;
F_34 ( V_131 , & V_11 -> V_116 ) ;
F_63 () ;
F_27 ( V_189 , & V_11 -> V_116 ) ;
F_27 ( V_115 , & V_11 -> V_116 ) ;
F_64 () ;
F_104 ( V_11 , V_190 ) ;
break;
case V_191 :
V_11 -> V_187 ++ ;
F_27 ( V_189 , & V_11 -> V_116 ) ;
F_86 ( V_11 ) ;
case V_192 :
if ( V_11 -> V_129 < V_193 )
V_11 -> V_129 = V_193 ;
break;
case V_194 :
F_34 ( V_131 , & V_11 -> V_116 ) ;
F_104 ( V_11 , V_190 ) ;
F_63 () ;
F_27 ( V_189 , & V_11 -> V_116 ) ;
F_64 () ;
break;
case V_195 :
F_107 ( V_11 ) ;
F_111 ( V_11 ) ;
}
V_77:
F_56 ( & V_8 -> V_124 ) ;
}
static void F_116 ( struct V_7 * V_8 )
{
struct V_39 * V_7 ;
struct V_6 * V_11 ;
if ( F_26 ( ! ( V_7 = V_8 -> V_126 ) ) )
return;
F_27 ( V_95 , & V_7 -> V_60 ) ;
if ( F_26 ( ! ( V_11 = F_3 ( V_8 ) ) ) )
return;
if ( F_67 ( V_75 , & V_7 -> V_60 ) == 0 )
return;
F_117 ( V_11 ) ;
}
static void F_118 ( struct V_7 * V_8 )
{
F_53 ( & V_8 -> V_124 ) ;
if ( F_119 ( V_8 ) )
F_116 ( V_8 ) ;
F_56 ( & V_8 -> V_124 ) ;
}
static void F_120 ( struct V_7 * V_8 )
{
F_53 ( & V_8 -> V_124 ) ;
if ( F_121 ( V_8 ) )
F_116 ( V_8 ) ;
F_56 ( & V_8 -> V_124 ) ;
}
static void F_122 ( struct V_6 * V_11 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
struct V_7 * V_8 = V_82 -> V_85 ;
if ( V_82 -> V_196 ) {
V_8 -> V_197 |= V_198 ;
V_8 -> V_199 = V_82 -> V_196 * V_11 -> V_200 * 2 ;
}
if ( V_82 -> V_201 ) {
V_8 -> V_197 |= V_202 ;
V_8 -> V_203 = V_82 -> V_201 * V_11 -> V_200 * 2 ;
V_8 -> V_97 ( V_8 ) ;
}
}
static void F_123 ( struct V_6 * V_11 , T_4 V_201 , T_4 V_196 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
V_82 -> V_201 = 0 ;
if ( V_201 )
V_82 -> V_201 = V_201 + 1024 ;
V_82 -> V_196 = 0 ;
if ( V_196 )
V_82 -> V_196 = V_196 + 1024 ;
F_122 ( V_11 ) ;
}
static void F_124 ( struct V_6 * V_11 , struct V_79 * V_80 )
{
F_85 ( V_11 , V_80 , - V_204 ) ;
}
static unsigned short F_125 ( void )
{
unsigned short V_205 = V_206 - V_207 ;
unsigned short rand = ( unsigned short ) F_126 () % V_205 ;
return rand + V_207 ;
}
static void F_127 ( struct V_6 * V_11 , unsigned short V_208 )
{
F_2 ( L_47 , V_11 , V_208 ) ;
F_128 ( F_4 ( V_11 ) , V_208 ) ;
F_17 ( V_11 ) ;
}
static unsigned short F_129 ( struct V_81 * V_82 )
{
unsigned short V_208 = V_82 -> V_127 ;
if ( V_208 == 0 && V_82 -> V_11 . V_209 )
V_208 = F_125 () ;
return V_208 ;
}
static unsigned short F_130 ( struct V_81 * V_82 , unsigned short V_208 )
{
if ( V_82 -> V_127 != 0 )
V_82 -> V_127 = 0 ;
if ( ! V_82 -> V_11 . V_209 )
return 0 ;
if ( V_208 <= V_207 || V_208 > V_206 )
return V_206 ;
return -- V_208 ;
}
static int F_131 ( struct V_81 * V_82 , struct V_39 * V_7 )
{
struct V_210 V_211 ;
int V_63 , V_212 = 0 ;
unsigned short V_208 = F_129 ( V_82 ) ;
unsigned short V_213 ;
memcpy ( & V_211 , & V_82 -> V_214 , V_82 -> V_11 . V_40 ) ;
do {
F_128 ( (struct V_10 * ) & V_211 , V_208 ) ;
V_63 = F_132 ( V_7 , (struct V_10 * ) & V_211 ,
V_82 -> V_11 . V_40 ) ;
if ( V_208 == 0 )
break;
if ( V_63 == 0 ) {
V_82 -> V_127 = V_208 ;
break;
}
V_213 = V_208 ;
V_208 = F_130 ( V_82 , V_208 ) ;
if ( V_208 > V_213 )
V_212 ++ ;
} while ( V_63 == - V_215 && V_212 != 2 );
if ( V_211 . V_216 == V_25 )
F_2 ( L_48 , V_104 ,
& ( (struct V_14 * ) & V_211 ) -> V_26 ,
V_208 , V_63 ? L_49 : L_50 , V_63 ) ;
else
F_2 ( L_51 , V_104 ,
& ( (struct V_15 * ) & V_211 ) -> V_29 ,
V_208 , V_63 ? L_49 : L_50 , V_63 ) ;
return V_63 ;
}
static void F_133 ( struct V_79 * V_80 )
{
F_134 () ;
F_135 ( F_136 ( V_80 -> V_217 -> V_218 ) ) ;
F_137 () ;
}
static void F_138 ( struct V_6 * V_11 , unsigned short V_208 )
{
}
static inline void F_139 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_140 ( V_8 , L_52 ,
& V_219 [ 1 ] , L_53 , & V_220 [ 1 ] ) ;
}
static inline void F_141 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_140 ( V_8 , L_54 ,
& V_219 [ 0 ] , L_55 , & V_220 [ 0 ] ) ;
}
static inline void F_142 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_140 ( V_8 , L_56 ,
& V_219 [ 1 ] , L_57 , & V_220 [ 1 ] ) ;
}
static inline void F_143 ( int V_221 , struct V_39 * V_7 )
{
F_144 ( F_145 ( V_7 -> V_8 ) ) ;
if ( F_145 ( V_7 -> V_8 ) )
return;
switch ( V_221 ) {
case V_20 :
F_139 ( V_7 ) ;
break;
case V_25 :
F_141 ( V_7 ) ;
break;
case V_28 :
F_142 ( V_7 ) ;
break;
}
}
static inline void F_139 ( struct V_39 * V_7 )
{
}
static inline void F_141 ( struct V_39 * V_7 )
{
}
static inline void F_142 ( struct V_39 * V_7 )
{
}
static inline void F_143 ( int V_221 , struct V_39 * V_7 )
{
}
static void F_146 ( struct V_222 * V_223 )
{
}
static struct V_39 * F_147 ( struct V_6 * V_11 ,
struct V_81 * V_82 , int V_221 , int type , int V_33 )
{
struct V_39 * V_7 ;
int V_63 ;
V_63 = F_148 ( V_11 -> V_224 , V_221 , type , V_33 , & V_7 , 1 ) ;
if ( V_63 < 0 ) {
F_2 ( L_58 ,
V_33 , - V_63 ) ;
goto V_77;
}
F_143 ( V_221 , V_7 ) ;
V_63 = F_131 ( V_82 , V_7 ) ;
if ( V_63 ) {
F_61 ( V_7 ) ;
goto V_77;
}
return V_7 ;
V_77:
return F_149 ( V_63 ) ;
}
static int F_150 ( struct V_6 * V_11 ,
struct V_39 * V_7 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 ,
V_11 ) ;
if ( ! V_82 -> V_85 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
F_58 ( & V_8 -> V_124 ) ;
F_50 ( V_82 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_118 = F_74 ;
V_8 -> V_97 = F_118 ;
V_8 -> V_123 = F_52 ;
V_8 -> V_225 = V_226 ;
F_151 ( V_11 ) ;
V_82 -> V_7 = V_7 ;
V_82 -> V_85 = V_8 ;
F_59 ( & V_8 -> V_124 ) ;
}
V_11 -> V_227 . V_228 ++ ;
V_11 -> V_227 . V_229 = V_230 ;
return F_152 ( V_7 , F_4 ( V_11 ) , V_11 -> V_40 , 0 ) ;
}
static int F_153 ( struct V_81 * V_82 )
{
struct V_6 * V_11 = & V_82 -> V_11 ;
struct V_39 * V_7 ;
int V_102 = - V_231 ;
V_232 -> V_60 |= V_233 ;
F_27 ( V_130 , & V_11 -> V_116 ) ;
V_102 = F_148 ( V_11 -> V_224 , V_20 ,
V_234 , 0 , & V_7 , 1 ) ;
if ( V_102 < 0 ) {
F_2 ( L_59
L_60 , - V_102 ) ;
goto V_77;
}
F_139 ( V_7 ) ;
F_2 ( L_61 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
V_102 = F_150 ( V_11 , V_7 ) ;
F_154 ( V_11 , V_7 , V_102 ) ;
switch ( V_102 ) {
case 0 :
F_2 ( L_62 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
F_155 ( V_11 ) ;
break;
case - V_235 :
F_2 ( L_63 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
break;
case - V_108 :
F_2 ( L_64 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
break;
default:
F_96 ( V_236 L_65 ,
V_104 , - V_102 ,
V_11 -> V_22 [ V_23 ] ) ;
}
V_77:
F_109 ( V_11 ) ;
F_55 ( V_11 , V_102 ) ;
V_232 -> V_60 &= ~ V_233 ;
return V_102 ;
}
static void F_156 ( struct V_6 * V_11 , struct V_79 * V_80 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
int V_89 ;
if ( F_157 ( V_80 ) ) {
F_158 ( V_80 , - V_96 ) ;
return;
}
V_89 = F_153 ( V_82 ) ;
if ( V_89 && ! F_159 ( V_80 ) )
F_160 ( 15000 ) ;
}
static void F_161 ( struct V_6 * V_11 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 ,
V_11 ) ;
if ( V_11 -> V_237 )
F_162 ( V_82 -> V_85 ) ;
}
int F_163 ( struct V_6 * V_11 , int V_238 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 ,
V_11 ) ;
int V_63 = 0 ;
if ( V_238 ) {
V_11 -> V_237 ++ ;
F_161 ( V_11 ) ;
} else if ( V_11 -> V_237 ) {
V_11 -> V_237 -- ;
F_164 ( V_82 -> V_85 ) ;
}
return V_63 ;
}
static void F_161 ( struct V_6 * V_11 )
{
}
static void F_165 ( struct V_6 * V_11 , struct V_39 * V_7 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
if ( ! V_82 -> V_85 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
F_58 ( & V_8 -> V_124 ) ;
F_50 ( V_82 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_118 = F_82 ;
V_8 -> V_97 = F_118 ;
V_8 -> V_225 = V_226 ;
F_155 ( V_11 ) ;
V_82 -> V_7 = V_7 ;
V_82 -> V_85 = V_8 ;
F_161 ( V_11 ) ;
F_59 ( & V_8 -> V_124 ) ;
}
F_122 ( V_11 ) ;
}
static void F_166 ( struct V_222 * V_223 )
{
struct V_81 * V_82 =
F_29 ( V_223 , struct V_81 , V_128 . V_223 ) ;
struct V_6 * V_11 = & V_82 -> V_11 ;
struct V_39 * V_7 = V_82 -> V_7 ;
int V_102 = - V_231 ;
V_232 -> V_60 |= V_233 ;
F_57 ( V_82 ) ;
V_7 = F_147 ( V_11 , V_82 ,
F_4 ( V_11 ) -> V_19 , V_239 , V_240 ) ;
if ( F_167 ( V_7 ) )
goto V_77;
F_2 ( L_66
L_67 , V_11 ,
V_11 -> V_22 [ V_35 ] ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ) ;
F_165 ( V_11 , V_7 ) ;
F_154 ( V_11 , V_7 , 0 ) ;
V_102 = 0 ;
V_77:
F_109 ( V_11 ) ;
F_55 ( V_11 , V_102 ) ;
V_232 -> V_60 &= ~ V_233 ;
}
static void F_168 ( struct V_81 * V_82 )
{
int V_241 ;
struct V_10 V_242 ;
F_2 ( L_68 , V_82 ) ;
memset ( & V_242 , 0 , sizeof( V_242 ) ) ;
V_242 . V_19 = V_243 ;
V_241 = F_152 ( V_82 -> V_7 , & V_242 , sizeof( V_242 ) , 0 ) ;
F_169 ( & V_82 -> V_11 ,
V_82 -> V_7 , V_241 ) ;
if ( ! V_241 )
F_110 ( & V_82 -> V_11 ) ;
F_2 ( L_69 , V_241 ) ;
}
static void F_170 ( struct V_81 * V_82 )
{
unsigned int V_116 = V_82 -> V_85 -> V_182 ;
if ( V_116 == V_195 && V_82 -> V_7 -> V_116 == V_244 ) {
if ( V_82 -> V_85 -> V_185 == 0 )
return;
F_2 ( L_70 ,
V_104 , V_82 -> V_85 -> V_185 ) ;
}
if ( ( 1 << V_116 ) & ( V_245 | V_246 ) ) {
if ( V_82 -> V_85 -> V_185 == 0 )
return;
F_2 ( L_71
L_72 ,
V_104 , V_82 -> V_85 -> V_185 ) ;
}
F_168 ( V_82 ) ;
}
static int F_171 ( struct V_6 * V_11 , struct V_39 * V_7 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
int V_89 = - V_96 ;
if ( ! V_82 -> V_85 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
unsigned int V_247 = V_11 -> V_180 -> V_248 / V_249 ;
unsigned int V_250 = V_11 -> V_180 -> V_251 + 1 ;
unsigned int V_252 = 1 ;
F_172 ( V_7 , V_253 , V_254 ,
( char * ) & V_252 , sizeof( V_252 ) ) ;
F_172 ( V_7 , V_255 , V_256 ,
( char * ) & V_247 , sizeof( V_247 ) ) ;
F_172 ( V_7 , V_255 , V_257 ,
( char * ) & V_247 , sizeof( V_247 ) ) ;
F_172 ( V_7 , V_255 , V_258 ,
( char * ) & V_250 , sizeof( V_250 ) ) ;
F_58 ( & V_8 -> V_124 ) ;
F_50 ( V_82 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_118 = F_102 ;
V_8 -> V_120 = F_112 ;
V_8 -> V_97 = F_120 ;
V_8 -> V_123 = F_52 ;
V_8 -> V_225 = V_226 ;
V_8 -> V_197 |= V_259 ;
F_173 ( V_8 , V_260 ) ;
F_174 ( V_8 ) -> V_261 = 0 ;
F_174 ( V_8 ) -> V_262 |= V_263 ;
F_151 ( V_11 ) ;
V_82 -> V_7 = V_7 ;
V_82 -> V_85 = V_8 ;
F_59 ( & V_8 -> V_124 ) ;
}
if ( ! F_43 ( V_11 ) )
goto V_77;
F_161 ( V_11 ) ;
V_11 -> V_227 . V_228 ++ ;
V_11 -> V_227 . V_229 = V_230 ;
V_89 = F_152 ( V_7 , F_4 ( V_11 ) , V_11 -> V_40 , V_264 ) ;
switch ( V_89 ) {
case 0 :
case - V_265 :
if ( V_11 -> V_129 < V_193 )
V_11 -> V_129 = V_193 ;
}
V_77:
return V_89 ;
}
static void F_175 ( struct V_222 * V_223 )
{
struct V_81 * V_82 =
F_29 ( V_223 , struct V_81 , V_128 . V_223 ) ;
struct V_39 * V_7 = V_82 -> V_7 ;
struct V_6 * V_11 = & V_82 -> V_11 ;
int V_102 = - V_231 ;
V_232 -> V_60 |= V_233 ;
if ( ! V_7 ) {
F_27 ( V_130 , & V_11 -> V_116 ) ;
V_7 = F_147 ( V_11 , V_82 ,
F_4 ( V_11 ) -> V_19 , V_234 , V_266 ) ;
if ( F_167 ( V_7 ) ) {
V_102 = F_176 ( V_7 ) ;
goto V_77;
}
} else {
int V_267 ;
V_267 = F_67 ( V_130 ,
& V_11 -> V_116 ) ;
F_170 ( V_82 ) ;
if ( V_267 )
goto V_268;
}
F_2 ( L_66
L_67 , V_11 ,
V_11 -> V_22 [ V_35 ] ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ) ;
V_102 = F_171 ( V_11 , V_7 ) ;
F_154 ( V_11 , V_7 , V_102 ) ;
F_2 ( L_73 ,
V_11 , - V_102 , F_32 ( V_11 ) ,
V_7 -> V_8 -> V_182 ) ;
switch ( V_102 ) {
default:
F_96 ( L_74 ,
V_104 , V_102 ) ;
case - V_269 :
F_86 ( V_11 ) ;
break;
case 0 :
case - V_265 :
case - V_270 :
F_109 ( V_11 ) ;
V_232 -> V_60 &= ~ V_233 ;
return;
case - V_271 :
case - V_108 :
case - V_112 :
case - V_107 :
goto V_77;
}
V_268:
V_102 = - V_90 ;
V_77:
F_109 ( V_11 ) ;
F_55 ( V_11 , V_102 ) ;
V_232 -> V_60 &= ~ V_233 ;
}
static void F_177 ( struct V_6 * V_11 , struct V_79 * V_80 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
if ( V_82 -> V_7 != NULL && ! F_159 ( V_80 ) ) {
F_2 ( L_75
L_76 ,
V_11 , V_11 -> V_129 / V_249 ) ;
F_106 ( V_181 ,
& V_82 -> V_128 ,
V_11 -> V_129 ) ;
V_11 -> V_129 <<= 1 ;
if ( V_11 -> V_129 < V_193 )
V_11 -> V_129 = V_193 ;
if ( V_11 -> V_129 > V_272 )
V_11 -> V_129 = V_272 ;
} else {
F_2 ( L_77 , V_11 ) ;
F_106 ( V_181 ,
& V_82 -> V_128 , 0 ) ;
}
}
static void F_178 ( struct V_6 * V_11 , struct V_273 * V_274 )
{
long V_275 = 0 ;
if ( F_32 ( V_11 ) )
V_275 = ( long ) ( V_230 - V_11 -> V_276 ) / V_249 ;
F_179 ( V_274 , L_78
L_79 ,
V_11 -> V_227 . V_277 ,
V_11 -> V_227 . V_228 ,
V_11 -> V_227 . V_278 ,
V_275 ,
V_11 -> V_227 . V_279 ,
V_11 -> V_227 . V_280 ,
V_11 -> V_227 . V_281 ,
V_11 -> V_227 . V_282 ,
V_11 -> V_227 . V_283 ,
V_11 -> V_227 . V_284 ,
V_11 -> V_227 . V_285 ,
V_11 -> V_227 . V_286 ) ;
}
static void F_180 ( struct V_6 * V_11 , struct V_273 * V_274 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
F_179 ( V_274 , L_80
L_81 ,
V_82 -> V_127 ,
V_11 -> V_227 . V_277 ,
V_11 -> V_227 . V_279 ,
V_11 -> V_227 . V_280 ,
V_11 -> V_227 . V_281 ,
V_11 -> V_227 . V_282 ,
V_11 -> V_227 . V_283 ,
V_11 -> V_227 . V_284 ,
V_11 -> V_227 . V_285 ,
V_11 -> V_227 . V_286 ) ;
}
static void F_181 ( struct V_6 * V_11 , struct V_273 * V_274 )
{
struct V_81 * V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
long V_275 = 0 ;
if ( F_32 ( V_11 ) )
V_275 = ( long ) ( V_230 - V_11 -> V_276 ) / V_249 ;
F_179 ( V_274 , L_82
L_79 ,
V_82 -> V_127 ,
V_11 -> V_227 . V_277 ,
V_11 -> V_227 . V_228 ,
V_11 -> V_227 . V_278 ,
V_275 ,
V_11 -> V_227 . V_279 ,
V_11 -> V_227 . V_280 ,
V_11 -> V_227 . V_281 ,
V_11 -> V_227 . V_282 ,
V_11 -> V_227 . V_283 ,
V_11 -> V_227 . V_284 ,
V_11 -> V_227 . V_285 ,
V_11 -> V_227 . V_286 ) ;
}
static void * F_182 ( struct V_79 * V_80 , T_4 V_59 )
{
struct V_57 * V_57 ;
struct V_287 * V_4 ;
F_144 ( V_59 > V_288 - sizeof( struct V_287 ) ) ;
if ( V_59 > V_288 - sizeof( struct V_287 ) )
return NULL ;
V_57 = F_183 ( V_24 ) ;
if ( ! V_57 )
return NULL ;
V_4 = F_184 ( V_57 ) ;
V_4 -> V_73 = V_288 ;
return V_4 -> V_178 ;
}
static void F_185 ( void * V_289 )
{
struct V_287 * V_4 ;
if ( ! V_289 )
return;
V_4 = F_29 ( V_289 , struct V_287 , V_178 ) ;
F_186 ( ( unsigned long ) V_4 ) ;
}
static int F_187 ( struct V_87 * V_88 )
{
int V_73 ;
struct V_54 * V_290 = & V_88 -> V_101 ;
struct V_6 * V_11 = V_88 -> V_84 ;
struct V_81 * V_82 =
F_29 ( V_11 , struct V_81 , V_11 ) ;
struct V_39 * V_7 = V_82 -> V_7 ;
unsigned long V_291 ;
unsigned long V_292 ;
F_37 ( V_290 ) ;
V_292 = ( unsigned long ) V_290 -> V_78 [ 0 ] . V_52 & ~ V_69 ;
V_291 = ( unsigned long ) V_290 -> V_76 [ 0 ] . V_52 & ~ V_69 ;
V_73 = F_188 ( V_7 , V_290 ,
F_189 ( V_290 -> V_76 [ 0 ] . V_52 ) , V_291 ,
V_290 -> V_78 [ 0 ] . V_52 , V_292 ) ;
if ( V_73 != V_290 -> V_73 ) {
F_96 ( V_293 L_83 ) ;
V_73 = - V_90 ;
}
return V_73 ;
}
static int F_190 ( struct V_79 * V_80 )
{
struct V_87 * V_88 = V_80 -> V_83 ;
struct V_294 * V_11 ;
T_1 V_73 ;
F_2 ( L_84 , F_12 ( V_88 -> V_175 ) ) ;
V_11 = V_88 -> V_84 -> V_295 ;
if ( ! F_191 ( & V_11 -> V_296 ) ) {
F_192 ( & V_11 -> V_297 , V_80 , NULL ) ;
if ( ! F_191 ( & V_11 -> V_296 ) )
return - V_90 ;
F_193 ( & V_11 -> V_297 , V_80 ) ;
}
if ( F_33 ( V_298 , & V_11 -> V_299 ) )
V_73 = - V_96 ;
else
V_73 = F_187 ( V_88 ) ;
F_194 ( & V_11 -> V_296 ) ;
if ( V_73 > 0 )
V_73 = 0 ;
return V_73 ;
}
static void F_195 ( struct V_6 * V_11 )
{
}
static void F_196 ( struct V_6 * V_11 )
{
F_2 ( L_85 , V_11 ) ;
F_68 ( V_11 ) ;
F_71 ( V_133 ) ;
}
static int F_197 ( const int V_221 , struct V_10 * V_16 )
{
static const struct V_14 sin = {
. V_300 = V_25 ,
. V_26 . V_27 = F_198 ( V_301 ) ,
} ;
static const struct V_15 V_17 = {
. V_302 = V_28 ,
. V_29 = V_303 ,
} ;
switch ( V_221 ) {
case V_20 :
break;
case V_25 :
memcpy ( V_16 , & sin , sizeof( sin ) ) ;
break;
case V_28 :
memcpy ( V_16 , & V_17 , sizeof( V_17 ) ) ;
break;
default:
F_2 ( L_86 , V_104 ) ;
return - V_304 ;
}
return 0 ;
}
static struct V_6 * F_199 ( struct V_305 * args ,
unsigned int V_306 ,
unsigned int V_307 )
{
struct V_6 * V_11 ;
struct V_81 * V_308 ;
if ( args -> V_40 > sizeof( V_11 -> V_12 ) ) {
F_2 ( L_87 ) ;
return F_149 ( - V_309 ) ;
}
V_11 = F_200 ( args -> V_310 , sizeof( * V_308 ) , V_306 ,
V_307 ) ;
if ( V_11 == NULL ) {
F_2 ( L_88
L_89 ) ;
return F_149 ( - V_311 ) ;
}
V_308 = F_29 ( V_11 , struct V_81 , V_11 ) ;
memcpy ( & V_11 -> V_12 , args -> V_312 , args -> V_40 ) ;
V_11 -> V_40 = args -> V_40 ;
if ( args -> V_214 )
memcpy ( & V_308 -> V_214 , args -> V_214 , args -> V_40 ) ;
else {
int V_63 ;
V_63 = F_197 ( args -> V_312 -> V_19 ,
(struct V_10 * ) & V_308 -> V_214 ) ;
if ( V_63 != 0 ) {
F_69 ( V_11 ) ;
return F_149 ( V_63 ) ;
}
}
return V_11 ;
}
static struct V_6 * F_201 ( struct V_305 * args )
{
struct V_13 * V_18 = (struct V_13 * ) args -> V_312 ;
struct V_81 * V_82 ;
struct V_6 * V_11 ;
struct V_6 * V_89 ;
V_11 = F_199 ( args , V_313 ,
V_314 ) ;
if ( F_167 ( V_11 ) )
return V_11 ;
V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
V_11 -> V_315 = 0 ;
V_11 -> V_316 = sizeof( V_99 ) / sizeof( T_1 ) ;
V_11 -> V_317 = V_318 ;
V_11 -> V_319 = V_320 ;
V_11 -> V_129 = V_193 ;
V_11 -> V_321 = V_322 ;
V_11 -> V_70 = & V_323 ;
V_11 -> V_180 = & V_324 ;
F_202 ( & V_82 -> V_128 ,
F_146 ) ;
switch ( V_18 -> V_325 ) {
case V_20 :
if ( V_18 -> V_21 [ 0 ] != '/' ) {
F_2 ( L_90 ,
V_18 -> V_21 ) ;
V_89 = F_149 ( - V_271 ) ;
goto V_326;
}
F_135 ( V_11 ) ;
F_16 ( V_11 , L_91 , V_327 ) ;
V_89 = F_149 ( F_153 ( V_82 ) ) ;
if ( V_89 )
goto V_326;
break;
default:
V_89 = F_149 ( - V_304 ) ;
goto V_326;
}
F_2 ( L_92 ,
V_11 -> V_22 [ V_23 ] ) ;
if ( F_203 ( V_133 ) )
return V_11 ;
V_89 = F_149 ( - V_271 ) ;
V_326:
F_68 ( V_11 ) ;
return V_89 ;
}
static struct V_6 * F_204 ( struct V_305 * args )
{
struct V_10 * V_12 = args -> V_312 ;
struct V_6 * V_11 ;
struct V_81 * V_82 ;
struct V_6 * V_89 ;
V_11 = F_199 ( args , V_328 ,
V_328 ) ;
if ( F_167 ( V_11 ) )
return V_11 ;
V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
V_11 -> V_315 = V_240 ;
V_11 -> V_316 = 0 ;
V_11 -> V_317 = ( 1U << 16 ) - ( V_329 << 3 ) ;
V_11 -> V_319 = V_320 ;
V_11 -> V_129 = V_330 ;
V_11 -> V_321 = V_322 ;
V_11 -> V_70 = & V_331 ;
V_11 -> V_180 = & V_332 ;
switch ( V_12 -> V_19 ) {
case V_25 :
if ( ( (struct V_14 * ) V_12 ) -> V_333 != F_205 ( 0 ) )
F_135 ( V_11 ) ;
F_202 ( & V_82 -> V_128 ,
F_166 ) ;
F_16 ( V_11 , L_93 , V_334 ) ;
break;
case V_28 :
if ( ( (struct V_15 * ) V_12 ) -> V_335 != F_205 ( 0 ) )
F_135 ( V_11 ) ;
F_202 ( & V_82 -> V_128 ,
F_166 ) ;
F_16 ( V_11 , L_93 , V_336 ) ;
break;
default:
V_89 = F_149 ( - V_304 ) ;
goto V_326;
}
if ( F_43 ( V_11 ) )
F_2 ( L_94 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
else
F_2 ( L_95 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_35 ] ) ;
if ( F_203 ( V_133 ) )
return V_11 ;
V_89 = F_149 ( - V_271 ) ;
V_326:
F_68 ( V_11 ) ;
return V_89 ;
}
static struct V_6 * F_206 ( struct V_305 * args )
{
struct V_10 * V_12 = args -> V_312 ;
struct V_6 * V_11 ;
struct V_81 * V_82 ;
struct V_6 * V_89 ;
unsigned int V_307 = V_314 ;
if ( args -> V_60 & V_337 )
V_307 = V_338 ;
V_11 = F_199 ( args , V_313 ,
V_307 ) ;
if ( F_167 ( V_11 ) )
return V_11 ;
V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
V_11 -> V_315 = V_266 ;
V_11 -> V_316 = sizeof( V_99 ) / sizeof( T_1 ) ;
V_11 -> V_317 = V_318 ;
V_11 -> V_319 = V_320 ;
V_11 -> V_129 = V_193 ;
V_11 -> V_321 = V_322 ;
V_11 -> V_70 = & V_339 ;
V_11 -> V_180 = & V_340 ;
switch ( V_12 -> V_19 ) {
case V_25 :
if ( ( (struct V_14 * ) V_12 ) -> V_333 != F_205 ( 0 ) )
F_135 ( V_11 ) ;
F_202 ( & V_82 -> V_128 ,
F_175 ) ;
F_16 ( V_11 , L_96 , V_341 ) ;
break;
case V_28 :
if ( ( (struct V_15 * ) V_12 ) -> V_335 != F_205 ( 0 ) )
F_135 ( V_11 ) ;
F_202 ( & V_82 -> V_128 ,
F_175 ) ;
F_16 ( V_11 , L_96 , V_342 ) ;
break;
default:
V_89 = F_149 ( - V_304 ) ;
goto V_326;
}
if ( F_43 ( V_11 ) )
F_2 ( L_94 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
else
F_2 ( L_95 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_35 ] ) ;
if ( F_203 ( V_133 ) )
return V_11 ;
V_89 = F_149 ( - V_271 ) ;
V_326:
F_68 ( V_11 ) ;
return V_89 ;
}
static struct V_6 * F_207 ( struct V_305 * args )
{
struct V_10 * V_12 = args -> V_312 ;
struct V_6 * V_11 ;
struct V_81 * V_82 ;
struct V_343 * V_344 ;
struct V_6 * V_89 ;
V_11 = F_199 ( args , V_313 ,
V_313 ) ;
if ( F_167 ( V_11 ) )
return V_11 ;
V_82 = F_29 ( V_11 , struct V_81 , V_11 ) ;
V_11 -> V_315 = V_266 ;
V_11 -> V_316 = sizeof( V_99 ) / sizeof( T_1 ) ;
V_11 -> V_317 = V_318 ;
V_11 -> V_180 = & V_340 ;
F_135 ( V_11 ) ;
V_11 -> V_319 = 0 ;
V_11 -> V_129 = 0 ;
V_11 -> V_321 = 0 ;
V_11 -> V_70 = & V_345 ;
switch ( V_12 -> V_19 ) {
case V_25 :
F_16 ( V_11 , L_96 ,
V_341 ) ;
break;
case V_28 :
F_16 ( V_11 , L_96 ,
V_342 ) ;
break;
default:
V_89 = F_149 ( - V_304 ) ;
goto V_326;
}
F_2 ( L_94 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
F_208 ( V_11 ) ;
args -> V_295 -> V_346 = V_11 ;
V_11 -> V_295 = args -> V_295 ;
V_344 = F_29 ( args -> V_295 , struct V_343 , V_347 ) ;
V_82 -> V_7 = V_344 -> V_348 ;
V_82 -> V_85 = V_344 -> V_349 ;
F_155 ( V_11 ) ;
if ( F_203 ( V_133 ) )
return V_11 ;
args -> V_295 -> V_346 = NULL ;
F_209 ( V_11 ) ;
V_89 = F_149 ( - V_271 ) ;
V_326:
F_68 ( V_11 ) ;
return V_89 ;
}
int F_210 ( void )
{
#ifdef F_211
if ( ! V_350 )
V_350 = F_212 ( V_351 ) ;
#endif
F_213 ( & V_352 ) ;
F_213 ( & V_353 ) ;
F_213 ( & V_354 ) ;
F_213 ( & V_355 ) ;
return 0 ;
}
void F_214 ( void )
{
#ifdef F_211
if ( V_350 ) {
F_215 ( V_350 ) ;
V_350 = NULL ;
}
#endif
F_216 ( & V_352 ) ;
F_216 ( & V_353 ) ;
F_216 ( & V_354 ) ;
F_216 ( & V_355 ) ;
}
static int F_217 ( const char * V_356 ,
const struct V_357 * V_358 ,
unsigned int V_359 , unsigned int V_360 )
{
unsigned long V_361 ;
int V_89 ;
if ( ! V_356 )
return - V_271 ;
V_89 = F_218 ( V_356 , 0 , & V_361 ) ;
if ( V_89 == - V_271 || V_361 < V_359 || V_361 > V_360 )
return - V_271 ;
* ( ( unsigned int * ) V_358 -> V_177 ) = V_361 ;
return 0 ;
}
static int F_219 ( const char * V_356 , const struct V_357 * V_358 )
{
return F_217 ( V_356 , V_358 ,
V_362 ,
V_363 ) ;
}
static int F_220 ( const char * V_356 ,
const struct V_357 * V_358 )
{
return F_217 ( V_356 , V_358 ,
V_364 ,
V_365 ) ;
}
static int F_221 ( const char * V_356 ,
const struct V_357 * V_358 )
{
return F_217 ( V_356 , V_358 ,
V_364 ,
V_338 ) ;
}

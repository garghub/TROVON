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
if ( V_63 != 0 || V_44 )
V_61 |= V_50 ;
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
int V_74 = 0 ;
if ( F_26 ( ! V_7 ) )
return - V_75 ;
F_27 ( V_76 , & V_7 -> V_61 ) ;
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
V_64 = F_22 ( V_7 , V_55 , V_43 , V_63 != 0 , V_56 , & V_74 ) ;
* V_57 += V_74 ;
if ( V_63 == 0 || V_74 != V_73 )
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
static void F_28 ( struct V_80 * V_81 )
{
struct V_82 * V_83 = F_29 ( V_81 -> V_84 -> V_85 , struct V_82 , V_11 ) ;
V_83 -> V_86 -> V_87 -- ;
F_27 ( V_76 , & V_83 -> V_7 -> V_61 ) ;
}
static int F_30 ( struct V_80 * V_81 )
{
struct V_88 * V_89 = V_81 -> V_84 ;
struct V_6 * V_11 = V_89 -> V_85 ;
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_7 * V_8 = V_83 -> V_86 ;
int V_90 = - V_91 ;
F_2 ( L_9 ,
V_81 -> V_92 , V_89 -> V_93 - V_89 -> V_94 ,
V_89 -> V_93 ) ;
F_31 ( & V_11 -> V_95 ) ;
if ( F_32 ( V_11 ) ) {
if ( F_33 ( V_76 , & V_83 -> V_7 -> V_61 ) ) {
F_34 ( V_96 , & V_83 -> V_7 -> V_61 ) ;
V_8 -> V_87 ++ ;
F_35 ( V_81 , F_28 ) ;
}
} else {
F_27 ( V_76 , & V_83 -> V_7 -> V_61 ) ;
V_90 = - V_97 ;
}
F_36 ( & V_11 -> V_95 ) ;
V_8 -> V_98 ( V_8 ) ;
return V_90 ;
}
static inline void F_37 ( struct V_54 * V_4 )
{
T_1 V_99 = V_4 -> V_73 - sizeof( V_100 ) ;
V_100 * V_43 = V_4 -> V_77 [ 0 ] . V_52 ;
* V_43 = F_38 ( V_101 | V_99 ) ;
}
static int F_39 ( struct V_80 * V_81 )
{
struct V_88 * V_89 = V_81 -> V_84 ;
struct V_6 * V_11 = V_89 -> V_85 ;
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_54 * V_55 = & V_89 -> V_102 ;
int V_103 ;
int V_74 = 0 ;
F_37 ( & V_89 -> V_102 ) ;
F_1 ( L_10 ,
V_89 -> V_104 -> V_52 , V_89 -> V_104 -> V_53 ) ;
V_103 = F_25 ( V_83 -> V_7 , NULL , 0 , V_55 , V_89 -> V_94 ,
true , & V_74 ) ;
F_2 ( L_11 ,
V_105 , V_55 -> V_73 - V_89 -> V_94 , V_103 ) ;
if ( F_40 ( V_74 > 0 ) || V_103 == 0 ) {
V_89 -> V_94 += V_74 ;
V_89 -> V_106 += V_74 ;
if ( F_40 ( V_89 -> V_94 >= V_89 -> V_93 ) ) {
V_89 -> V_94 = 0 ;
return 0 ;
}
V_103 = - V_91 ;
}
switch ( V_103 ) {
case - V_107 :
case - V_91 :
V_103 = F_30 ( V_81 ) ;
break;
default:
F_2 ( L_12 ,
- V_103 ) ;
case - V_108 :
F_41 ( V_11 ) ;
V_103 = - V_97 ;
}
return V_103 ;
}
static int F_42 ( struct V_80 * V_81 )
{
struct V_88 * V_89 = V_81 -> V_84 ;
struct V_6 * V_11 = V_89 -> V_85 ;
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_54 * V_55 = & V_89 -> V_102 ;
int V_74 = 0 ;
int V_103 ;
F_1 ( L_10 ,
V_89 -> V_104 -> V_52 ,
V_89 -> V_104 -> V_53 ) ;
if ( ! F_43 ( V_11 ) )
return - V_97 ;
V_103 = F_25 ( V_83 -> V_7 , F_4 ( V_11 ) , V_11 -> V_40 ,
V_55 , V_89 -> V_94 , true , & V_74 ) ;
F_2 ( L_13 ,
V_55 -> V_73 - V_89 -> V_94 , V_103 ) ;
if ( V_103 == - V_109 )
goto V_110;
if ( V_74 > 0 || V_103 == 0 ) {
V_89 -> V_106 += V_74 ;
if ( V_74 >= V_89 -> V_93 )
return 0 ;
V_103 = - V_91 ;
}
V_110:
switch ( V_103 ) {
case - V_75 :
V_103 = - V_97 ;
break;
case - V_91 :
V_103 = F_30 ( V_81 ) ;
break;
default:
F_2 ( L_12 ,
- V_103 ) ;
case - V_111 :
case - V_107 :
case - V_108 :
case - V_112 :
case - V_109 :
F_27 ( V_76 , & V_83 -> V_7 -> V_61 ) ;
}
return V_103 ;
}
static void F_44 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
if ( V_7 != NULL ) {
F_45 ( V_7 , V_113 ) ;
F_46 ( V_11 , V_7 ) ;
}
}
static int F_47 ( struct V_80 * V_81 )
{
struct V_88 * V_89 = V_81 -> V_84 ;
struct V_6 * V_11 = V_89 -> V_85 ;
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_54 * V_55 = & V_89 -> V_102 ;
bool V_56 = true ;
int V_103 ;
int V_74 ;
F_37 ( & V_89 -> V_102 ) ;
F_1 ( L_10 ,
V_89 -> V_104 -> V_52 ,
V_89 -> V_104 -> V_53 ) ;
if ( V_81 -> V_114 & V_115 )
V_56 = false ;
while ( 1 ) {
V_74 = 0 ;
V_103 = F_25 ( V_83 -> V_7 , NULL , 0 , V_55 ,
V_89 -> V_94 , V_56 , & V_74 ) ;
F_2 ( L_14 ,
V_55 -> V_73 - V_89 -> V_94 , V_103 ) ;
if ( F_26 ( V_74 == 0 && V_103 < 0 ) )
break;
V_89 -> V_94 += V_74 ;
V_89 -> V_106 += V_74 ;
if ( F_40 ( V_89 -> V_94 >= V_89 -> V_93 ) ) {
V_89 -> V_94 = 0 ;
return 0 ;
}
if ( V_74 != 0 )
continue;
V_103 = - V_91 ;
break;
}
switch ( V_103 ) {
case - V_75 :
V_103 = - V_97 ;
break;
case - V_107 :
case - V_91 :
V_103 = F_30 ( V_81 ) ;
break;
default:
F_2 ( L_12 ,
- V_103 ) ;
case - V_116 :
F_44 ( V_11 ) ;
case - V_112 :
case - V_97 :
case - V_108 :
F_27 ( V_76 , & V_83 -> V_7 -> V_61 ) ;
}
return V_103 ;
}
static void F_48 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
struct V_88 * V_89 ;
if ( V_81 != V_11 -> V_117 )
return;
if ( V_81 == NULL )
goto V_118;
V_89 = V_81 -> V_84 ;
if ( V_89 == NULL )
goto V_118;
if ( V_89 -> V_94 == 0 )
goto V_118;
if ( V_89 -> V_94 == V_89 -> V_102 . V_73 )
goto V_118;
F_34 ( V_119 , & V_11 -> V_120 ) ;
V_118:
F_49 ( V_11 , V_81 ) ;
}
static void F_50 ( struct V_82 * V_83 , struct V_7 * V_8 )
{
V_83 -> V_121 = V_8 -> V_122 ;
V_83 -> V_123 = V_8 -> V_124 ;
V_83 -> V_125 = V_8 -> V_98 ;
V_83 -> V_126 = V_8 -> V_127 ;
}
static void F_51 ( struct V_82 * V_83 , struct V_7 * V_8 )
{
V_8 -> V_122 = V_83 -> V_121 ;
V_8 -> V_124 = V_83 -> V_123 ;
V_8 -> V_98 = V_83 -> V_125 ;
V_8 -> V_127 = V_83 -> V_126 ;
}
static void F_52 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
int V_64 ;
F_53 ( & V_8 -> V_128 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_78;
V_64 = - V_8 -> V_129 ;
if ( V_64 == 0 )
goto V_78;
F_2 ( L_15 ,
V_11 , - V_64 ) ;
F_54 ( V_11 , V_8 -> V_130 , V_64 ) ;
if ( F_33 ( V_131 , & V_11 -> V_120 ) )
goto V_78;
F_55 ( V_11 , V_64 ) ;
V_78:
F_56 ( & V_8 -> V_128 ) ;
}
static void F_57 ( struct V_82 * V_83 )
{
struct V_39 * V_7 = V_83 -> V_7 ;
struct V_7 * V_8 = V_83 -> V_86 ;
if ( V_8 == NULL )
return;
V_83 -> V_132 = 0 ;
F_58 ( & V_8 -> V_128 ) ;
V_83 -> V_86 = NULL ;
V_83 -> V_7 = NULL ;
V_8 -> V_9 = NULL ;
F_51 ( V_83 , V_8 ) ;
F_59 ( & V_8 -> V_128 ) ;
F_60 ( & V_83 -> V_11 , V_7 ) ;
F_61 ( V_7 ) ;
}
static void F_41 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
F_2 ( L_16 , V_11 ) ;
F_62 ( & V_83 -> V_133 ) ;
F_57 ( V_83 ) ;
V_11 -> V_134 = 0 ;
F_63 () ;
F_27 ( V_135 , & V_11 -> V_120 ) ;
F_27 ( V_119 , & V_11 -> V_120 ) ;
F_27 ( V_136 , & V_11 -> V_120 ) ;
F_64 () ;
F_65 ( V_11 ) ;
}
static void F_66 ( struct V_6 * V_11 )
{
if ( F_67 ( V_137 , & V_11 -> V_120 ) )
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
F_71 ( V_138 ) ;
}
static int F_72 ( struct V_54 * V_55 , struct V_139 * V_140 )
{
struct V_141 V_142 = {
. V_140 = V_140 ,
. V_59 = sizeof( V_100 ) ,
. V_3 = V_140 -> V_73 - sizeof( V_100 ) ,
} ;
if ( F_73 ( V_55 , 0 , & V_142 , V_143 ) < 0 )
return - 1 ;
if ( V_142 . V_3 )
return - 1 ;
return 0 ;
}
static void F_74 ( struct V_7 * V_8 )
{
struct V_80 * V_81 ;
struct V_6 * V_11 ;
struct V_88 * V_144 ;
struct V_139 * V_140 ;
int V_64 , V_145 , V_146 ;
T_1 V_147 ;
T_5 * V_148 ;
F_53 ( & V_8 -> V_128 ) ;
F_2 ( L_18 , V_105 ) ;
V_11 = F_3 ( V_8 ) ;
if ( V_11 == NULL )
goto V_78;
V_140 = F_75 ( V_8 , 0 , 1 , & V_64 ) ;
if ( V_140 == NULL )
goto V_78;
V_145 = V_140 -> V_73 - sizeof( V_100 ) ;
if ( V_145 < 4 ) {
F_2 ( L_19 , V_145 ) ;
goto V_149;
}
V_148 = F_76 ( V_140 , sizeof( V_100 ) , sizeof( V_147 ) , & V_147 ) ;
if ( V_148 == NULL )
goto V_149;
F_77 ( & V_11 -> V_95 ) ;
V_144 = F_78 ( V_11 , * V_148 ) ;
if ( ! V_144 )
goto V_150;
V_81 = V_144 -> V_151 ;
V_146 = V_144 -> V_152 . V_153 ;
if ( V_146 > V_145 )
V_146 = V_145 ;
if ( F_72 ( & V_144 -> V_152 , V_140 ) ) {
F_2 ( L_20 ) ;
goto V_150;
}
F_79 ( V_81 , V_146 ) ;
V_150:
F_80 ( & V_11 -> V_95 ) ;
V_149:
F_81 ( V_8 , V_140 ) ;
V_78:
F_56 ( & V_8 -> V_128 ) ;
}
static void F_82 ( struct V_7 * V_8 )
{
struct V_80 * V_81 ;
struct V_6 * V_11 ;
struct V_88 * V_144 ;
struct V_139 * V_140 ;
int V_64 , V_145 , V_146 ;
T_1 V_147 ;
T_5 * V_148 ;
F_53 ( & V_8 -> V_128 ) ;
F_2 ( L_21 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_78;
if ( ( V_140 = F_75 ( V_8 , 0 , 1 , & V_64 ) ) == NULL )
goto V_78;
V_145 = V_140 -> V_73 - sizeof( struct V_154 ) ;
if ( V_145 < 4 ) {
F_2 ( L_22 , V_145 ) ;
goto V_149;
}
V_148 = F_76 ( V_140 , sizeof( struct V_154 ) ,
sizeof( V_147 ) , & V_147 ) ;
if ( V_148 == NULL )
goto V_149;
F_77 ( & V_11 -> V_95 ) ;
V_144 = F_78 ( V_11 , * V_148 ) ;
if ( ! V_144 )
goto V_150;
V_81 = V_144 -> V_151 ;
if ( ( V_146 = V_144 -> V_152 . V_153 ) > V_145 )
V_146 = V_145 ;
if ( F_83 ( & V_144 -> V_152 , V_140 ) ) {
F_84 ( V_8 , V_155 ) ;
goto V_150;
}
F_84 ( V_8 , V_156 ) ;
F_85 ( V_11 , V_81 , V_146 ) ;
F_79 ( V_81 , V_146 ) ;
V_150:
F_80 ( & V_11 -> V_95 ) ;
V_149:
F_81 ( V_8 , V_140 ) ;
V_78:
F_56 ( & V_8 -> V_128 ) ;
}
static void F_86 ( struct V_6 * V_11 )
{
F_34 ( V_137 , & V_11 -> V_120 ) ;
F_87 ( V_11 ) ;
}
static inline void F_88 ( struct V_6 * V_11 , struct V_141 * V_142 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
T_4 V_73 , V_157 ;
char * V_158 ;
V_158 = ( ( char * ) & V_83 -> V_159 ) + V_83 -> V_160 ;
V_73 = sizeof( V_83 -> V_159 ) - V_83 -> V_160 ;
V_157 = V_143 ( V_142 , V_158 , V_73 ) ;
V_83 -> V_160 += V_157 ;
if ( V_157 != V_73 )
return;
V_83 -> V_161 = F_12 ( V_83 -> V_159 ) ;
if ( V_83 -> V_161 & V_101 )
V_83 -> V_162 |= V_163 ;
else
V_83 -> V_162 &= ~ V_163 ;
V_83 -> V_161 &= V_164 ;
V_83 -> V_162 &= ~ V_165 ;
V_83 -> V_160 = 0 ;
if ( F_26 ( V_83 -> V_161 < 8 ) ) {
F_2 ( L_23 ) ;
F_86 ( V_11 ) ;
return;
}
F_2 ( L_24 ,
V_83 -> V_161 ) ;
}
static void F_89 ( struct V_82 * V_83 )
{
if ( V_83 -> V_160 == V_83 -> V_161 ) {
V_83 -> V_162 |= V_165 ;
V_83 -> V_160 = 0 ;
if ( V_83 -> V_162 & V_163 ) {
V_83 -> V_162 &= ~ V_166 ;
V_83 -> V_162 |= V_167 ;
V_83 -> V_168 = 0 ;
}
}
}
static inline void F_90 ( struct V_82 * V_83 , struct V_141 * V_142 )
{
T_4 V_73 , V_157 ;
char * V_158 ;
V_73 = sizeof( V_83 -> V_169 ) - V_83 -> V_160 ;
F_2 ( L_25 , V_73 ) ;
V_158 = ( ( char * ) & V_83 -> V_169 ) + V_83 -> V_160 ;
V_157 = V_143 ( V_142 , V_158 , V_73 ) ;
V_83 -> V_160 += V_157 ;
if ( V_157 != V_73 )
return;
V_83 -> V_162 &= ~ V_167 ;
V_83 -> V_162 |= V_170 ;
V_83 -> V_168 = 4 ;
F_2 ( L_26 ,
( V_83 -> V_162 & V_171 ) ? L_27
: L_28 ,
F_12 ( V_83 -> V_169 ) ) ;
F_89 ( V_83 ) ;
}
static inline void F_91 ( struct V_82 * V_83 ,
struct V_141 * V_142 )
{
T_4 V_73 , V_157 ;
T_1 V_59 ;
char * V_158 ;
V_59 = V_83 -> V_160 - sizeof( V_83 -> V_169 ) ;
V_73 = sizeof( V_83 -> V_172 ) - V_59 ;
F_2 ( L_29 , V_73 ) ;
V_158 = ( ( char * ) & V_83 -> V_172 ) + V_59 ;
V_157 = V_143 ( V_142 , V_158 , V_73 ) ;
V_83 -> V_160 += V_157 ;
if ( V_157 != V_73 )
return;
V_83 -> V_162 &= ~ V_170 ;
switch ( F_12 ( V_83 -> V_172 ) ) {
case V_173 :
V_83 -> V_162 |= V_174 ;
V_83 -> V_162 |= V_166 ;
V_83 -> V_162 |= V_171 ;
break;
case V_175 :
V_83 -> V_162 |= V_174 ;
V_83 -> V_162 |= V_166 ;
V_83 -> V_162 &= ~ V_171 ;
break;
default:
F_2 ( L_30 ) ;
F_86 ( & V_83 -> V_11 ) ;
}
F_89 ( V_83 ) ;
}
static inline void F_92 ( struct V_6 * V_11 ,
struct V_141 * V_142 ,
struct V_88 * V_89 )
{
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_54 * V_176 ;
T_4 V_73 ;
T_3 V_177 ;
V_176 = & V_89 -> V_152 ;
if ( V_83 -> V_162 & V_174 ) {
memcpy ( V_176 -> V_77 [ 0 ] . V_52 + V_83 -> V_168 ,
& V_83 -> V_172 ,
sizeof( V_83 -> V_172 ) ) ;
V_83 -> V_168 += sizeof( V_83 -> V_172 ) ;
V_83 -> V_162 &= ~ V_174 ;
}
V_73 = V_142 -> V_3 ;
if ( V_73 > V_83 -> V_161 - V_83 -> V_160 ) {
struct V_141 V_178 ;
V_73 = V_83 -> V_161 - V_83 -> V_160 ;
memcpy ( & V_178 , V_142 , sizeof( V_178 ) ) ;
V_178 . V_3 = V_73 ;
V_177 = F_73 ( V_176 , V_83 -> V_168 ,
& V_178 , V_143 ) ;
V_142 -> V_3 -= V_177 ;
V_142 -> V_59 += V_177 ;
} else
V_177 = F_73 ( V_176 , V_83 -> V_168 ,
V_142 , V_143 ) ;
if ( V_177 > 0 ) {
V_83 -> V_168 += V_177 ;
V_83 -> V_160 += V_177 ;
}
if ( V_177 != V_73 ) {
V_83 -> V_162 &= ~ V_166 ;
F_2 ( L_31 ,
F_12 ( V_83 -> V_169 ) ) ;
F_2 ( L_32
L_33 ,
V_11 , V_83 -> V_168 ,
V_83 -> V_160 , V_83 -> V_161 ) ;
return;
}
F_2 ( L_34 ,
F_12 ( V_83 -> V_169 ) , V_177 ) ;
F_2 ( L_35
L_36 , V_11 , V_83 -> V_168 ,
V_83 -> V_160 , V_83 -> V_161 ) ;
if ( V_83 -> V_168 == V_89 -> V_152 . V_153 )
V_83 -> V_162 &= ~ V_166 ;
else if ( V_83 -> V_160 == V_83 -> V_161 ) {
if ( V_83 -> V_162 & V_163 )
V_83 -> V_162 &= ~ V_166 ;
}
}
static inline int F_93 ( struct V_6 * V_11 ,
struct V_141 * V_142 )
{
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_88 * V_89 ;
F_2 ( L_37 , F_12 ( V_83 -> V_169 ) ) ;
F_77 ( & V_11 -> V_95 ) ;
V_89 = F_78 ( V_11 , V_83 -> V_169 ) ;
if ( ! V_89 ) {
F_2 ( L_38 ,
F_12 ( V_83 -> V_169 ) ) ;
F_80 ( & V_11 -> V_95 ) ;
return - 1 ;
}
F_92 ( V_11 , V_142 , V_89 ) ;
if ( ! ( V_83 -> V_162 & V_166 ) )
F_79 ( V_89 -> V_151 , V_83 -> V_168 ) ;
F_80 ( & V_11 -> V_95 ) ;
return 0 ;
}
static int F_94 ( struct V_6 * V_11 ,
struct V_141 * V_142 )
{
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_88 * V_89 ;
F_77 ( & V_11 -> V_95 ) ;
V_89 = F_95 ( V_11 , V_83 -> V_169 ) ;
if ( V_89 == NULL ) {
F_80 ( & V_11 -> V_95 ) ;
F_96 ( V_179 L_39 ) ;
F_87 ( V_11 ) ;
return - 1 ;
}
F_2 ( L_40 , F_12 ( V_89 -> V_180 ) ) ;
F_92 ( V_11 , V_142 , V_89 ) ;
if ( ! ( V_83 -> V_162 & V_166 ) )
F_97 ( V_89 , V_83 -> V_168 ) ;
F_80 ( & V_11 -> V_95 ) ;
return 0 ;
}
static inline int F_98 ( struct V_6 * V_11 ,
struct V_141 * V_142 )
{
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
return ( V_83 -> V_162 & V_171 ) ?
F_93 ( V_11 , V_142 ) :
F_94 ( V_11 , V_142 ) ;
}
static inline int F_98 ( struct V_6 * V_11 ,
struct V_141 * V_142 )
{
return F_93 ( V_11 , V_142 ) ;
}
static void F_99 ( struct V_6 * V_11 ,
struct V_141 * V_142 )
{
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
if ( F_98 ( V_11 , V_142 ) == 0 )
F_89 ( V_83 ) ;
else {
V_83 -> V_162 &= ~ V_166 ;
}
}
static inline void F_100 ( struct V_82 * V_83 , struct V_141 * V_142 )
{
T_4 V_73 ;
V_73 = V_83 -> V_161 - V_83 -> V_160 ;
if ( V_73 > V_142 -> V_3 )
V_73 = V_142 -> V_3 ;
V_142 -> V_3 -= V_73 ;
V_142 -> V_59 += V_73 ;
V_83 -> V_160 += V_73 ;
F_2 ( L_41 , V_73 ) ;
F_89 ( V_83 ) ;
}
static int F_101 ( T_6 * V_181 , struct V_139 * V_140 , unsigned int V_59 , T_4 V_73 )
{
struct V_6 * V_11 = V_181 -> V_182 . V_183 ;
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_141 V_142 = {
. V_140 = V_140 ,
. V_59 = V_59 ,
. V_3 = V_73 ,
} ;
F_2 ( L_42 ) ;
do {
if ( V_83 -> V_162 & V_165 ) {
F_88 ( V_11 , & V_142 ) ;
continue;
}
if ( V_83 -> V_162 & V_167 ) {
F_90 ( V_83 , & V_142 ) ;
continue;
}
if ( V_83 -> V_162 & V_170 ) {
F_91 ( V_83 , & V_142 ) ;
continue;
}
if ( V_83 -> V_162 & V_166 ) {
F_99 ( V_11 , & V_142 ) ;
continue;
}
F_100 ( V_83 , & V_142 ) ;
} while ( V_142 . V_3 );
F_2 ( L_43 ) ;
return V_73 - V_142 . V_3 ;
}
static void F_102 ( struct V_7 * V_8 )
{
struct V_6 * V_11 ;
T_6 V_181 ;
int V_184 ;
F_2 ( L_44 ) ;
F_53 ( & V_8 -> V_128 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_78;
if ( V_11 -> V_134 )
V_11 -> V_134 = 0 ;
V_181 . V_182 . V_183 = V_11 ;
do {
V_181 . V_3 = 65536 ;
V_184 = F_103 ( V_8 , & V_181 , F_101 ) ;
} while ( V_184 > 0 );
V_78:
F_56 ( & V_8 -> V_128 ) ;
}
static void F_104 ( struct V_6 * V_11 ,
unsigned long V_185 )
{
struct V_82 * V_83 ;
if ( F_105 ( V_11 ) )
return;
F_34 ( V_135 , & V_11 -> V_120 ) ;
V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
F_106 ( V_186 , & V_83 -> V_133 ,
V_185 ) ;
}
static void F_107 ( struct V_6 * V_11 )
{
struct V_82 * V_83 ;
V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
if ( ! F_33 ( V_135 , & V_11 -> V_120 ) ||
! F_108 ( & V_83 -> V_133 ) )
return;
F_27 ( V_135 , & V_11 -> V_120 ) ;
F_109 ( V_11 ) ;
}
static void F_110 ( struct V_6 * V_11 )
{
F_63 () ;
F_27 ( V_135 , & V_11 -> V_120 ) ;
F_27 ( V_137 , & V_11 -> V_120 ) ;
F_27 ( V_119 , & V_11 -> V_120 ) ;
F_27 ( V_136 , & V_11 -> V_120 ) ;
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
F_53 ( & V_8 -> V_128 ) ;
if ( ! ( V_11 = F_3 ( V_8 ) ) )
goto V_78;
F_2 ( L_45 , V_11 ) ;
F_2 ( L_46 ,
V_8 -> V_187 , F_32 ( V_11 ) ,
F_113 ( V_8 , V_188 ) ,
F_113 ( V_8 , V_189 ) ,
V_8 -> V_190 ) ;
F_114 ( V_11 , V_8 -> V_130 ) ;
switch ( V_8 -> V_187 ) {
case V_191 :
F_77 ( & V_11 -> V_95 ) ;
if ( ! F_115 ( V_11 ) ) {
struct V_82 * V_83 = F_29 ( V_11 ,
struct V_82 , V_11 ) ;
V_83 -> V_160 = 0 ;
V_83 -> V_161 = 0 ;
V_83 -> V_168 = 0 ;
V_83 -> V_162 =
V_165 | V_167 ;
V_11 -> V_192 ++ ;
F_55 ( V_11 , - V_91 ) ;
}
F_80 ( & V_11 -> V_95 ) ;
break;
case V_193 :
V_11 -> V_192 ++ ;
V_11 -> V_134 = 0 ;
F_34 ( V_136 , & V_11 -> V_120 ) ;
F_63 () ;
F_27 ( V_194 , & V_11 -> V_120 ) ;
F_27 ( V_119 , & V_11 -> V_120 ) ;
F_64 () ;
F_104 ( V_11 , V_195 ) ;
break;
case V_196 :
V_11 -> V_192 ++ ;
F_27 ( V_194 , & V_11 -> V_120 ) ;
F_86 ( V_11 ) ;
case V_197 :
if ( V_11 -> V_134 < V_198 )
V_11 -> V_134 = V_198 ;
break;
case V_199 :
F_34 ( V_136 , & V_11 -> V_120 ) ;
F_104 ( V_11 , V_195 ) ;
F_63 () ;
F_27 ( V_194 , & V_11 -> V_120 ) ;
F_64 () ;
break;
case V_200 :
F_107 ( V_11 ) ;
F_111 ( V_11 ) ;
}
V_78:
F_56 ( & V_8 -> V_128 ) ;
}
static void F_116 ( struct V_7 * V_8 )
{
struct V_39 * V_7 ;
struct V_6 * V_11 ;
if ( F_26 ( ! ( V_7 = V_8 -> V_130 ) ) )
return;
F_27 ( V_96 , & V_7 -> V_61 ) ;
if ( F_26 ( ! ( V_11 = F_3 ( V_8 ) ) ) )
return;
if ( F_67 ( V_76 , & V_7 -> V_61 ) == 0 )
return;
F_117 ( V_11 ) ;
}
static void F_118 ( struct V_7 * V_8 )
{
F_53 ( & V_8 -> V_128 ) ;
if ( F_119 ( V_8 ) )
F_116 ( V_8 ) ;
F_56 ( & V_8 -> V_128 ) ;
}
static void F_120 ( struct V_7 * V_8 )
{
F_53 ( & V_8 -> V_128 ) ;
if ( F_121 ( V_8 ) )
F_116 ( V_8 ) ;
F_56 ( & V_8 -> V_128 ) ;
}
static void F_122 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_7 * V_8 = V_83 -> V_86 ;
if ( V_83 -> V_201 ) {
V_8 -> V_202 |= V_203 ;
V_8 -> V_204 = V_83 -> V_201 * V_11 -> V_205 * 2 ;
}
if ( V_83 -> V_206 ) {
V_8 -> V_202 |= V_207 ;
V_8 -> V_208 = V_83 -> V_206 * V_11 -> V_205 * 2 ;
V_8 -> V_98 ( V_8 ) ;
}
}
static void F_123 ( struct V_6 * V_11 , T_4 V_206 , T_4 V_201 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
V_83 -> V_206 = 0 ;
if ( V_206 )
V_83 -> V_206 = V_206 + 1024 ;
V_83 -> V_201 = 0 ;
if ( V_201 )
V_83 -> V_201 = V_201 + 1024 ;
F_122 ( V_11 ) ;
}
static void F_124 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
F_85 ( V_11 , V_81 , - V_209 ) ;
}
static unsigned short F_125 ( void )
{
unsigned short V_210 = V_211 - V_212 ;
unsigned short rand = ( unsigned short ) F_126 () % V_210 ;
return rand + V_212 ;
}
static void F_127 ( struct V_6 * V_11 , unsigned short V_213 )
{
F_2 ( L_47 , V_11 , V_213 ) ;
F_128 ( F_4 ( V_11 ) , V_213 ) ;
F_17 ( V_11 ) ;
}
static unsigned short F_129 ( struct V_82 * V_83 )
{
unsigned short V_213 = V_83 -> V_132 ;
if ( V_213 == 0 && V_83 -> V_11 . V_214 )
V_213 = F_125 () ;
return V_213 ;
}
static unsigned short F_130 ( struct V_82 * V_83 , unsigned short V_213 )
{
if ( V_83 -> V_132 != 0 )
V_83 -> V_132 = 0 ;
if ( ! V_83 -> V_11 . V_214 )
return 0 ;
if ( V_213 <= V_212 || V_213 > V_211 )
return V_211 ;
return -- V_213 ;
}
static int F_131 ( struct V_82 * V_83 , struct V_39 * V_7 )
{
struct V_215 V_216 ;
int V_64 , V_217 = 0 ;
unsigned short V_213 = F_129 ( V_83 ) ;
unsigned short V_218 ;
if ( V_213 == 0 )
return 0 ;
memcpy ( & V_216 , & V_83 -> V_219 , V_83 -> V_11 . V_40 ) ;
do {
F_128 ( (struct V_10 * ) & V_216 , V_213 ) ;
V_64 = F_132 ( V_7 , (struct V_10 * ) & V_216 ,
V_83 -> V_11 . V_40 ) ;
if ( V_64 == 0 ) {
V_83 -> V_132 = V_213 ;
break;
}
V_218 = V_213 ;
V_213 = F_130 ( V_83 , V_213 ) ;
if ( V_213 > V_218 )
V_217 ++ ;
} while ( V_64 == - V_220 && V_217 != 2 );
if ( V_216 . V_221 == V_25 )
F_2 ( L_48 , V_105 ,
& ( (struct V_14 * ) & V_216 ) -> V_26 ,
V_213 , V_64 ? L_49 : L_50 , V_64 ) ;
else
F_2 ( L_51 , V_105 ,
& ( (struct V_15 * ) & V_216 ) -> V_29 ,
V_213 , V_64 ? L_49 : L_50 , V_64 ) ;
return V_64 ;
}
static void F_133 ( struct V_80 * V_81 )
{
F_134 () ;
F_135 ( F_136 ( V_81 -> V_222 -> V_223 ) ) ;
F_137 () ;
}
static void F_138 ( struct V_6 * V_11 , unsigned short V_213 )
{
}
static inline void F_139 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_140 ( V_8 , L_52 ,
& V_224 [ 1 ] , L_53 , & V_225 [ 1 ] ) ;
}
static inline void F_141 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_140 ( V_8 , L_54 ,
& V_224 [ 0 ] , L_55 , & V_225 [ 0 ] ) ;
}
static inline void F_142 ( struct V_39 * V_7 )
{
struct V_7 * V_8 = V_7 -> V_8 ;
F_140 ( V_8 , L_56 ,
& V_224 [ 1 ] , L_57 , & V_225 [ 1 ] ) ;
}
static inline void F_143 ( int V_226 , struct V_39 * V_7 )
{
F_144 ( F_145 ( V_7 -> V_8 ) ) ;
if ( F_145 ( V_7 -> V_8 ) )
return;
switch ( V_226 ) {
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
static inline void F_143 ( int V_226 , struct V_39 * V_7 )
{
}
static void F_146 ( struct V_227 * V_228 )
{
}
static struct V_39 * F_147 ( struct V_6 * V_11 ,
struct V_82 * V_83 , int V_226 , int type , int V_33 )
{
struct V_39 * V_7 ;
int V_64 ;
V_64 = F_148 ( V_11 -> V_229 , V_226 , type , V_33 , & V_7 , 1 ) ;
if ( V_64 < 0 ) {
F_2 ( L_58 ,
V_33 , - V_64 ) ;
goto V_78;
}
F_143 ( V_226 , V_7 ) ;
V_64 = F_131 ( V_83 , V_7 ) ;
if ( V_64 ) {
F_61 ( V_7 ) ;
goto V_78;
}
return V_7 ;
V_78:
return F_149 ( V_64 ) ;
}
static int F_150 ( struct V_6 * V_11 ,
struct V_39 * V_7 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 ,
V_11 ) ;
if ( ! V_83 -> V_86 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
F_58 ( & V_8 -> V_128 ) ;
F_50 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_122 = F_74 ;
V_8 -> V_98 = F_118 ;
V_8 -> V_127 = F_52 ;
V_8 -> V_230 = V_231 ;
F_151 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_59 ( & V_8 -> V_128 ) ;
}
V_11 -> V_232 . V_233 ++ ;
V_11 -> V_232 . V_234 = V_235 ;
return F_152 ( V_7 , F_4 ( V_11 ) , V_11 -> V_40 , 0 ) ;
}
static int F_153 ( struct V_82 * V_83 )
{
struct V_6 * V_11 = & V_83 -> V_11 ;
struct V_39 * V_7 ;
int V_103 = - V_236 ;
F_27 ( V_135 , & V_11 -> V_120 ) ;
V_103 = F_148 ( V_11 -> V_229 , V_20 ,
V_237 , 0 , & V_7 , 1 ) ;
if ( V_103 < 0 ) {
F_2 ( L_59
L_60 , - V_103 ) ;
goto V_78;
}
F_139 ( V_7 ) ;
F_2 ( L_61 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
V_103 = F_150 ( V_11 , V_7 ) ;
F_154 ( V_11 , V_7 , V_103 ) ;
switch ( V_103 ) {
case 0 :
F_2 ( L_62 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
F_155 ( V_11 ) ;
case - V_107 :
break;
case - V_238 :
F_2 ( L_63 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
break;
case - V_112 :
F_2 ( L_64 ,
V_11 , V_11 -> V_22 [ V_23 ] ) ;
break;
default:
F_96 ( V_239 L_65 ,
V_105 , - V_103 ,
V_11 -> V_22 [ V_23 ] ) ;
}
V_78:
F_109 ( V_11 ) ;
F_55 ( V_11 , V_103 ) ;
return V_103 ;
}
static void F_156 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
int V_90 ;
if ( F_157 ( V_81 ) ) {
F_158 ( V_81 , - V_97 ) ;
return;
}
V_90 = F_153 ( V_83 ) ;
if ( V_90 && ! F_159 ( V_81 ) )
F_160 ( 15000 ) ;
}
static void F_161 ( struct V_6 * V_11 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 ,
V_11 ) ;
if ( V_11 -> V_240 )
F_162 ( V_83 -> V_86 ) ;
}
int F_163 ( struct V_6 * V_11 , int V_241 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 ,
V_11 ) ;
int V_64 = 0 ;
if ( V_241 ) {
V_11 -> V_240 ++ ;
F_161 ( V_11 ) ;
} else if ( V_11 -> V_240 ) {
V_11 -> V_240 -- ;
F_164 ( V_83 -> V_86 ) ;
}
return V_64 ;
}
static void F_161 ( struct V_6 * V_11 )
{
}
static void F_165 ( struct V_6 * V_11 , struct V_39 * V_7 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
if ( ! V_83 -> V_86 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
F_58 ( & V_8 -> V_128 ) ;
F_50 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_122 = F_82 ;
V_8 -> V_98 = F_118 ;
V_8 -> V_230 = V_231 ;
F_155 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_161 ( V_11 ) ;
F_59 ( & V_8 -> V_128 ) ;
}
F_122 ( V_11 ) ;
}
static void F_166 ( struct V_227 * V_228 )
{
struct V_82 * V_83 =
F_29 ( V_228 , struct V_82 , V_133 . V_228 ) ;
struct V_6 * V_11 = & V_83 -> V_11 ;
struct V_39 * V_7 = V_83 -> V_7 ;
int V_103 = - V_236 ;
F_57 ( V_83 ) ;
V_7 = F_147 ( V_11 , V_83 ,
F_4 ( V_11 ) -> V_19 , V_242 , V_243 ) ;
if ( F_167 ( V_7 ) )
goto V_78;
F_2 ( L_66
L_67 , V_11 ,
V_11 -> V_22 [ V_35 ] ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ) ;
F_165 ( V_11 , V_7 ) ;
F_154 ( V_11 , V_7 , 0 ) ;
V_103 = 0 ;
V_78:
F_109 ( V_11 ) ;
F_55 ( V_11 , V_103 ) ;
}
static void F_168 ( struct V_82 * V_83 )
{
int V_244 ;
struct V_10 V_245 ;
F_2 ( L_68 , V_83 ) ;
memset ( & V_245 , 0 , sizeof( V_245 ) ) ;
V_245 . V_19 = V_246 ;
V_244 = F_152 ( V_83 -> V_7 , & V_245 , sizeof( V_245 ) , 0 ) ;
F_169 ( & V_83 -> V_11 ,
V_83 -> V_7 , V_244 ) ;
if ( ! V_244 )
F_110 ( & V_83 -> V_11 ) ;
F_2 ( L_69 , V_244 ) ;
}
static void F_170 ( struct V_82 * V_83 )
{
unsigned int V_120 = V_83 -> V_86 -> V_187 ;
if ( V_120 == V_200 && V_83 -> V_7 -> V_120 == V_247 ) {
if ( V_83 -> V_86 -> V_190 == 0 )
return;
F_2 ( L_70 ,
V_105 , V_83 -> V_86 -> V_190 ) ;
}
if ( ( 1 << V_120 ) & ( V_248 | V_249 ) ) {
if ( V_83 -> V_86 -> V_190 == 0 )
return;
F_2 ( L_71
L_72 ,
V_105 , V_83 -> V_86 -> V_190 ) ;
}
F_168 ( V_83 ) ;
}
static int F_171 ( struct V_6 * V_11 , struct V_39 * V_7 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
int V_90 = - V_97 ;
if ( ! V_83 -> V_86 ) {
struct V_7 * V_8 = V_7 -> V_8 ;
unsigned int V_250 = V_11 -> V_185 -> V_251 / V_252 ;
unsigned int V_253 = V_11 -> V_185 -> V_254 + 1 ;
unsigned int V_255 = 1 ;
F_172 ( V_7 , V_256 , V_257 ,
( char * ) & V_255 , sizeof( V_255 ) ) ;
F_172 ( V_7 , V_258 , V_259 ,
( char * ) & V_250 , sizeof( V_250 ) ) ;
F_172 ( V_7 , V_258 , V_260 ,
( char * ) & V_250 , sizeof( V_250 ) ) ;
F_172 ( V_7 , V_258 , V_261 ,
( char * ) & V_253 , sizeof( V_253 ) ) ;
F_58 ( & V_8 -> V_128 ) ;
F_50 ( V_83 , V_8 ) ;
V_8 -> V_9 = V_11 ;
V_8 -> V_122 = F_102 ;
V_8 -> V_124 = F_112 ;
V_8 -> V_98 = F_120 ;
V_8 -> V_127 = F_52 ;
V_8 -> V_230 = V_231 ;
V_8 -> V_202 |= V_262 ;
F_173 ( V_8 , V_263 ) ;
F_174 ( V_8 ) -> V_264 = 0 ;
F_174 ( V_8 ) -> V_265 |= V_266 ;
F_151 ( V_11 ) ;
V_83 -> V_7 = V_7 ;
V_83 -> V_86 = V_8 ;
F_59 ( & V_8 -> V_128 ) ;
}
if ( ! F_43 ( V_11 ) )
goto V_78;
F_161 ( V_11 ) ;
V_11 -> V_232 . V_233 ++ ;
V_11 -> V_232 . V_234 = V_235 ;
V_90 = F_152 ( V_7 , F_4 ( V_11 ) , V_11 -> V_40 , V_267 ) ;
switch ( V_90 ) {
case 0 :
case - V_268 :
if ( V_11 -> V_134 < V_198 )
V_11 -> V_134 = V_198 ;
}
V_78:
return V_90 ;
}
static void F_175 ( struct V_227 * V_228 )
{
struct V_82 * V_83 =
F_29 ( V_228 , struct V_82 , V_133 . V_228 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
struct V_6 * V_11 = & V_83 -> V_11 ;
int V_103 = - V_236 ;
if ( ! V_7 ) {
F_27 ( V_135 , & V_11 -> V_120 ) ;
V_7 = F_147 ( V_11 , V_83 ,
F_4 ( V_11 ) -> V_19 , V_237 , V_269 ) ;
if ( F_167 ( V_7 ) ) {
V_103 = F_176 ( V_7 ) ;
goto V_78;
}
} else {
int V_270 ;
V_270 = F_67 ( V_135 ,
& V_11 -> V_120 ) ;
F_34 ( V_131 , & V_11 -> V_120 ) ;
F_170 ( V_83 ) ;
F_27 ( V_131 , & V_11 -> V_120 ) ;
if ( V_270 )
goto V_271;
}
F_2 ( L_66
L_67 , V_11 ,
V_11 -> V_22 [ V_35 ] ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ) ;
V_103 = F_171 ( V_11 , V_7 ) ;
F_154 ( V_11 , V_7 , V_103 ) ;
F_2 ( L_73 ,
V_11 , - V_103 , F_32 ( V_11 ) ,
V_7 -> V_8 -> V_187 ) ;
switch ( V_103 ) {
default:
F_96 ( L_74 ,
V_105 , V_103 ) ;
case - V_272 :
F_86 ( V_11 ) ;
break;
case 0 :
case - V_268 :
case - V_273 :
F_109 ( V_11 ) ;
return;
case - V_274 :
case - V_112 :
case - V_116 :
case - V_111 :
case - V_107 :
goto V_78;
}
V_271:
V_103 = - V_91 ;
V_78:
F_109 ( V_11 ) ;
F_55 ( V_11 , V_103 ) ;
}
static void F_177 ( struct V_6 * V_11 , struct V_80 * V_81 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
if ( V_83 -> V_7 != NULL && ! F_159 ( V_81 ) ) {
F_2 ( L_75
L_76 ,
V_11 , V_11 -> V_134 / V_252 ) ;
F_106 ( V_186 ,
& V_83 -> V_133 ,
V_11 -> V_134 ) ;
V_11 -> V_134 <<= 1 ;
if ( V_11 -> V_134 < V_198 )
V_11 -> V_134 = V_198 ;
if ( V_11 -> V_134 > V_275 )
V_11 -> V_134 = V_275 ;
} else {
F_2 ( L_77 , V_11 ) ;
F_106 ( V_186 ,
& V_83 -> V_133 , 0 ) ;
}
}
static void F_178 ( struct V_6 * V_11 , struct V_276 * V_277 )
{
long V_278 = 0 ;
if ( F_32 ( V_11 ) )
V_278 = ( long ) ( V_235 - V_11 -> V_279 ) / V_252 ;
F_179 ( V_277 , L_78
L_79 ,
V_11 -> V_232 . V_280 ,
V_11 -> V_232 . V_233 ,
V_11 -> V_232 . V_281 ,
V_278 ,
V_11 -> V_232 . V_282 ,
V_11 -> V_232 . V_283 ,
V_11 -> V_232 . V_284 ,
V_11 -> V_232 . V_285 ,
V_11 -> V_232 . V_286 ,
V_11 -> V_232 . V_287 ,
V_11 -> V_232 . V_288 ,
V_11 -> V_232 . V_289 ) ;
}
static void F_180 ( struct V_6 * V_11 , struct V_276 * V_277 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
F_179 ( V_277 , L_80
L_81 ,
V_83 -> V_132 ,
V_11 -> V_232 . V_280 ,
V_11 -> V_232 . V_282 ,
V_11 -> V_232 . V_283 ,
V_11 -> V_232 . V_284 ,
V_11 -> V_232 . V_285 ,
V_11 -> V_232 . V_286 ,
V_11 -> V_232 . V_287 ,
V_11 -> V_232 . V_288 ,
V_11 -> V_232 . V_289 ) ;
}
static void F_181 ( struct V_6 * V_11 , struct V_276 * V_277 )
{
struct V_82 * V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
long V_278 = 0 ;
if ( F_32 ( V_11 ) )
V_278 = ( long ) ( V_235 - V_11 -> V_279 ) / V_252 ;
F_179 ( V_277 , L_82
L_79 ,
V_83 -> V_132 ,
V_11 -> V_232 . V_280 ,
V_11 -> V_232 . V_233 ,
V_11 -> V_232 . V_281 ,
V_278 ,
V_11 -> V_232 . V_282 ,
V_11 -> V_232 . V_283 ,
V_11 -> V_232 . V_284 ,
V_11 -> V_232 . V_285 ,
V_11 -> V_232 . V_286 ,
V_11 -> V_232 . V_287 ,
V_11 -> V_232 . V_288 ,
V_11 -> V_232 . V_289 ) ;
}
static void * F_182 ( struct V_80 * V_81 , T_4 V_60 )
{
struct V_58 * V_58 ;
struct V_290 * V_4 ;
F_144 ( V_60 > V_291 - sizeof( struct V_290 ) ) ;
if ( V_60 > V_291 - sizeof( struct V_290 ) )
return NULL ;
V_58 = F_183 ( V_24 ) ;
if ( ! V_58 )
return NULL ;
V_4 = F_184 ( V_58 ) ;
V_4 -> V_73 = V_291 ;
return V_4 -> V_183 ;
}
static void F_185 ( void * V_292 )
{
struct V_290 * V_4 ;
if ( ! V_292 )
return;
V_4 = F_29 ( V_292 , struct V_290 , V_183 ) ;
F_186 ( ( unsigned long ) V_4 ) ;
}
static int F_187 ( struct V_88 * V_89 )
{
int V_73 ;
struct V_54 * V_293 = & V_89 -> V_102 ;
struct V_6 * V_11 = V_89 -> V_85 ;
struct V_82 * V_83 =
F_29 ( V_11 , struct V_82 , V_11 ) ;
struct V_39 * V_7 = V_83 -> V_7 ;
unsigned long V_294 ;
unsigned long V_295 ;
F_37 ( V_293 ) ;
V_295 = ( unsigned long ) V_293 -> V_79 [ 0 ] . V_52 & ~ V_69 ;
V_294 = ( unsigned long ) V_293 -> V_77 [ 0 ] . V_52 & ~ V_69 ;
V_73 = F_188 ( V_7 , V_293 ,
F_189 ( V_293 -> V_77 [ 0 ] . V_52 ) , V_294 ,
V_293 -> V_79 [ 0 ] . V_52 , V_295 ) ;
if ( V_73 != V_293 -> V_73 ) {
F_96 ( V_296 L_83 ) ;
V_73 = - V_91 ;
}
return V_73 ;
}
static int F_190 ( struct V_80 * V_81 )
{
struct V_88 * V_89 = V_81 -> V_84 ;
struct V_297 * V_11 ;
T_1 V_73 ;
F_2 ( L_84 , F_12 ( V_89 -> V_180 ) ) ;
V_11 = V_89 -> V_85 -> V_298 ;
if ( ! F_191 ( & V_11 -> V_299 ) ) {
F_192 ( & V_11 -> V_300 , V_81 , NULL ) ;
if ( ! F_191 ( & V_11 -> V_299 ) )
return - V_91 ;
F_193 ( & V_11 -> V_300 , V_81 ) ;
}
if ( F_33 ( V_301 , & V_11 -> V_302 ) )
V_73 = - V_97 ;
else
V_73 = F_187 ( V_89 ) ;
F_194 ( & V_11 -> V_299 ) ;
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
F_71 ( V_138 ) ;
}
static int F_197 ( const int V_226 , struct V_10 * V_16 )
{
static const struct V_14 sin = {
. V_303 = V_25 ,
. V_26 . V_27 = F_198 ( V_304 ) ,
} ;
static const struct V_15 V_17 = {
. V_305 = V_28 ,
. V_29 = V_306 ,
} ;
switch ( V_226 ) {
case V_20 :
break;
case V_25 :
memcpy ( V_16 , & sin , sizeof( sin ) ) ;
break;
case V_28 :
memcpy ( V_16 , & V_17 , sizeof( V_17 ) ) ;
break;
default:
F_2 ( L_86 , V_105 ) ;
return - V_307 ;
}
return 0 ;
}
static struct V_6 * F_199 ( struct V_308 * args ,
unsigned int V_309 ,
unsigned int V_310 )
{
struct V_6 * V_11 ;
struct V_82 * V_311 ;
if ( args -> V_40 > sizeof( V_11 -> V_12 ) ) {
F_2 ( L_87 ) ;
return F_149 ( - V_312 ) ;
}
V_11 = F_200 ( args -> V_313 , sizeof( * V_311 ) , V_309 ,
V_310 ) ;
if ( V_11 == NULL ) {
F_2 ( L_88
L_89 ) ;
return F_149 ( - V_314 ) ;
}
V_311 = F_29 ( V_11 , struct V_82 , V_11 ) ;
memcpy ( & V_11 -> V_12 , args -> V_315 , args -> V_40 ) ;
V_11 -> V_40 = args -> V_40 ;
if ( args -> V_219 )
memcpy ( & V_311 -> V_219 , args -> V_219 , args -> V_40 ) ;
else {
int V_64 ;
V_64 = F_197 ( args -> V_315 -> V_19 ,
(struct V_10 * ) & V_311 -> V_219 ) ;
if ( V_64 != 0 ) {
F_69 ( V_11 ) ;
return F_149 ( V_64 ) ;
}
}
return V_11 ;
}
static struct V_6 * F_201 ( struct V_308 * args )
{
struct V_13 * V_18 = (struct V_13 * ) args -> V_315 ;
struct V_82 * V_83 ;
struct V_6 * V_11 ;
struct V_6 * V_90 ;
V_11 = F_199 ( args , V_316 ,
V_317 ) ;
if ( F_167 ( V_11 ) )
return V_11 ;
V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_318 = 0 ;
V_11 -> V_319 = sizeof( V_100 ) / sizeof( T_1 ) ;
V_11 -> V_320 = V_321 ;
V_11 -> V_322 = V_323 ;
V_11 -> V_134 = V_198 ;
V_11 -> V_324 = V_325 ;
V_11 -> V_70 = & V_326 ;
V_11 -> V_185 = & V_327 ;
F_202 ( & V_83 -> V_133 ,
F_146 ) ;
switch ( V_18 -> V_328 ) {
case V_20 :
if ( V_18 -> V_21 [ 0 ] != '/' ) {
F_2 ( L_90 ,
V_18 -> V_21 ) ;
V_90 = F_149 ( - V_274 ) ;
goto V_329;
}
F_135 ( V_11 ) ;
F_16 ( V_11 , L_91 , V_330 ) ;
V_90 = F_149 ( F_153 ( V_83 ) ) ;
if ( V_90 )
goto V_329;
break;
default:
V_90 = F_149 ( - V_307 ) ;
goto V_329;
}
F_2 ( L_92 ,
V_11 -> V_22 [ V_23 ] ) ;
if ( F_203 ( V_138 ) )
return V_11 ;
V_90 = F_149 ( - V_274 ) ;
V_329:
F_68 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_204 ( struct V_308 * args )
{
struct V_10 * V_12 = args -> V_315 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_6 * V_90 ;
V_11 = F_199 ( args , V_331 ,
V_331 ) ;
if ( F_167 ( V_11 ) )
return V_11 ;
V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_318 = V_243 ;
V_11 -> V_319 = 0 ;
V_11 -> V_320 = ( 1U << 16 ) - ( V_332 << 3 ) ;
V_11 -> V_322 = V_323 ;
V_11 -> V_134 = V_333 ;
V_11 -> V_324 = V_325 ;
V_11 -> V_70 = & V_334 ;
V_11 -> V_185 = & V_335 ;
switch ( V_12 -> V_19 ) {
case V_25 :
if ( ( (struct V_14 * ) V_12 ) -> V_336 != F_205 ( 0 ) )
F_135 ( V_11 ) ;
F_202 ( & V_83 -> V_133 ,
F_166 ) ;
F_16 ( V_11 , L_93 , V_337 ) ;
break;
case V_28 :
if ( ( (struct V_15 * ) V_12 ) -> V_338 != F_205 ( 0 ) )
F_135 ( V_11 ) ;
F_202 ( & V_83 -> V_133 ,
F_166 ) ;
F_16 ( V_11 , L_93 , V_339 ) ;
break;
default:
V_90 = F_149 ( - V_307 ) ;
goto V_329;
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
if ( F_203 ( V_138 ) )
return V_11 ;
V_90 = F_149 ( - V_274 ) ;
V_329:
F_68 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_206 ( struct V_308 * args )
{
struct V_10 * V_12 = args -> V_315 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_6 * V_90 ;
unsigned int V_310 = V_317 ;
if ( args -> V_61 & V_340 )
V_310 = V_341 ;
V_11 = F_199 ( args , V_316 ,
V_310 ) ;
if ( F_167 ( V_11 ) )
return V_11 ;
V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_318 = V_269 ;
V_11 -> V_319 = sizeof( V_100 ) / sizeof( T_1 ) ;
V_11 -> V_320 = V_321 ;
V_11 -> V_322 = V_323 ;
V_11 -> V_134 = V_198 ;
V_11 -> V_324 = V_325 ;
V_11 -> V_70 = & V_342 ;
V_11 -> V_185 = & V_343 ;
switch ( V_12 -> V_19 ) {
case V_25 :
if ( ( (struct V_14 * ) V_12 ) -> V_336 != F_205 ( 0 ) )
F_135 ( V_11 ) ;
F_202 ( & V_83 -> V_133 ,
F_175 ) ;
F_16 ( V_11 , L_96 , V_344 ) ;
break;
case V_28 :
if ( ( (struct V_15 * ) V_12 ) -> V_338 != F_205 ( 0 ) )
F_135 ( V_11 ) ;
F_202 ( & V_83 -> V_133 ,
F_175 ) ;
F_16 ( V_11 , L_96 , V_345 ) ;
break;
default:
V_90 = F_149 ( - V_307 ) ;
goto V_329;
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
if ( F_203 ( V_138 ) )
return V_11 ;
V_90 = F_149 ( - V_274 ) ;
V_329:
F_68 ( V_11 ) ;
return V_90 ;
}
static struct V_6 * F_207 ( struct V_308 * args )
{
struct V_10 * V_12 = args -> V_315 ;
struct V_6 * V_11 ;
struct V_82 * V_83 ;
struct V_346 * V_347 ;
struct V_6 * V_90 ;
V_11 = F_199 ( args , V_316 ,
V_316 ) ;
if ( F_167 ( V_11 ) )
return V_11 ;
V_83 = F_29 ( V_11 , struct V_82 , V_11 ) ;
V_11 -> V_318 = V_269 ;
V_11 -> V_319 = sizeof( V_100 ) / sizeof( T_1 ) ;
V_11 -> V_320 = V_321 ;
V_11 -> V_185 = & V_343 ;
F_135 ( V_11 ) ;
V_11 -> V_322 = 0 ;
V_11 -> V_134 = 0 ;
V_11 -> V_324 = 0 ;
V_11 -> V_70 = & V_348 ;
switch ( V_12 -> V_19 ) {
case V_25 :
F_16 ( V_11 , L_96 ,
V_344 ) ;
break;
case V_28 :
F_16 ( V_11 , L_96 ,
V_345 ) ;
break;
default:
V_90 = F_149 ( - V_307 ) ;
goto V_329;
}
F_2 ( L_94 ,
V_11 -> V_22 [ V_23 ] ,
V_11 -> V_22 [ V_31 ] ,
V_11 -> V_22 [ V_35 ] ) ;
F_208 ( V_11 ) ;
args -> V_298 -> V_349 = V_11 ;
V_11 -> V_298 = args -> V_298 ;
V_347 = F_29 ( args -> V_298 , struct V_346 , V_350 ) ;
V_83 -> V_7 = V_347 -> V_351 ;
V_83 -> V_86 = V_347 -> V_352 ;
F_155 ( V_11 ) ;
if ( F_203 ( V_138 ) )
return V_11 ;
args -> V_298 -> V_349 = NULL ;
F_209 ( V_11 ) ;
V_90 = F_149 ( - V_274 ) ;
V_329:
F_68 ( V_11 ) ;
return V_90 ;
}
int F_210 ( void )
{
#ifdef F_211
if ( ! V_353 )
V_353 = F_212 ( V_354 ) ;
#endif
F_213 ( & V_355 ) ;
F_213 ( & V_356 ) ;
F_213 ( & V_357 ) ;
F_213 ( & V_358 ) ;
return 0 ;
}
void F_214 ( void )
{
#ifdef F_211
if ( V_353 ) {
F_215 ( V_353 ) ;
V_353 = NULL ;
}
#endif
F_216 ( & V_355 ) ;
F_216 ( & V_356 ) ;
F_216 ( & V_357 ) ;
F_216 ( & V_358 ) ;
}
static int F_217 ( const char * V_359 ,
const struct V_360 * V_361 ,
unsigned int V_362 , unsigned int V_363 )
{
unsigned int V_364 ;
int V_90 ;
if ( ! V_359 )
return - V_274 ;
V_90 = F_218 ( V_359 , 0 , & V_364 ) ;
if ( V_90 == - V_274 || V_364 < V_362 || V_364 > V_363 )
return - V_274 ;
* ( ( unsigned int * ) V_361 -> V_182 ) = V_364 ;
return 0 ;
}
static int F_219 ( const char * V_359 , const struct V_360 * V_361 )
{
return F_217 ( V_359 , V_361 ,
V_365 ,
V_366 ) ;
}
static int F_220 ( const char * V_359 ,
const struct V_360 * V_361 )
{
return F_217 ( V_359 , V_361 ,
V_367 ,
V_368 ) ;
}
static int F_221 ( const char * V_359 ,
const struct V_360 * V_361 )
{
return F_217 ( V_359 , V_361 ,
V_367 ,
V_341 ) ;
}

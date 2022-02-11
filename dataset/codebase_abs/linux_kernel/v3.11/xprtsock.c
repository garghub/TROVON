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
F_32 ( V_106 , & V_8 -> V_107 ) ;
V_105:
F_46 ( V_8 , V_74 ) ;
}
static void F_47 ( struct V_75 * V_76 , struct V_37 * V_108 )
{
V_76 -> V_109 = V_108 -> V_110 ;
V_76 -> V_111 = V_108 -> V_112 ;
V_76 -> V_113 = V_108 -> V_114 ;
}
static void F_48 ( struct V_75 * V_76 , struct V_37 * V_108 )
{
V_108 -> V_110 = V_76 -> V_109 ;
V_108 -> V_112 = V_76 -> V_111 ;
V_108 -> V_114 = V_76 -> V_113 ;
}
static void F_49 ( struct V_75 * V_76 )
{
struct V_36 * V_37 = V_76 -> V_37 ;
struct V_37 * V_108 = V_76 -> V_79 ;
if ( V_108 == NULL )
return;
V_76 -> V_115 = 0 ;
F_50 ( & V_108 -> V_116 ) ;
V_76 -> V_79 = NULL ;
V_76 -> V_37 = NULL ;
V_108 -> V_117 = NULL ;
F_48 ( V_76 , V_108 ) ;
F_51 ( & V_108 -> V_116 ) ;
V_108 -> V_118 = 0 ;
F_52 ( V_37 ) ;
}
static void F_39 ( struct V_7 * V_8 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
F_2 ( L_15 , V_8 ) ;
F_49 ( V_76 ) ;
V_8 -> V_119 = 0 ;
F_53 () ;
F_25 ( V_120 , & V_8 -> V_107 ) ;
F_25 ( V_106 , & V_8 -> V_107 ) ;
F_25 ( V_121 , & V_8 -> V_107 ) ;
F_54 () ;
F_55 ( V_8 ) ;
}
static void F_56 ( struct V_7 * V_8 )
{
if ( F_57 ( V_122 , & V_8 -> V_107 ) )
F_39 ( V_8 ) ;
else
F_42 ( V_8 ) ;
}
static void F_58 ( struct V_7 * V_8 )
{
F_39 ( V_8 ) ;
F_18 ( V_8 ) ;
F_59 ( V_8 ) ;
F_60 ( V_123 ) ;
}
static void F_61 ( struct V_7 * V_8 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
F_2 ( L_16 , V_8 ) ;
F_62 ( & V_76 -> V_124 ) ;
F_58 ( V_8 ) ;
}
static inline struct V_7 * F_63 ( struct V_37 * V_108 )
{
return (struct V_7 * ) V_108 -> V_117 ;
}
static int F_64 ( struct V_52 * V_53 , struct V_125 * V_126 )
{
struct V_127 V_128 = {
. V_126 = V_126 ,
. V_129 = sizeof( V_92 ) ,
. V_3 = V_126 -> V_64 - sizeof( V_92 ) ,
} ;
if ( F_65 ( V_53 , 0 , & V_128 , V_130 ) < 0 )
return - 1 ;
if ( V_128 . V_3 )
return - 1 ;
return 0 ;
}
static void F_66 ( struct V_37 * V_108 , int V_64 )
{
struct V_73 * V_74 ;
struct V_7 * V_8 ;
struct V_81 * V_131 ;
struct V_125 * V_126 ;
int V_57 , V_132 , V_133 ;
T_1 V_134 ;
T_3 * V_135 ;
F_67 ( & V_108 -> V_116 ) ;
F_2 ( L_17 , V_97 ) ;
V_8 = F_63 ( V_108 ) ;
if ( V_8 == NULL )
goto V_71;
V_126 = F_68 ( V_108 , 0 , 1 , & V_57 ) ;
if ( V_126 == NULL )
goto V_71;
V_132 = V_126 -> V_64 - sizeof( V_92 ) ;
if ( V_132 < 4 ) {
F_2 ( L_18 , V_132 ) ;
goto V_136;
}
V_135 = F_69 ( V_126 , sizeof( V_92 ) , sizeof( V_134 ) , & V_134 ) ;
if ( V_135 == NULL )
goto V_136;
F_70 ( & V_8 -> V_88 ) ;
V_131 = F_71 ( V_8 , * V_135 ) ;
if ( ! V_131 )
goto V_137;
V_74 = V_131 -> V_138 ;
V_133 = V_131 -> V_139 . V_140 ;
if ( V_133 > V_132 )
V_133 = V_132 ;
if ( F_64 ( & V_131 -> V_139 , V_126 ) ) {
F_2 ( L_19 ) ;
goto V_137;
}
F_72 ( V_74 , V_133 ) ;
V_137:
F_73 ( & V_8 -> V_88 ) ;
V_136:
F_74 ( V_108 , V_126 ) ;
V_71:
F_75 ( & V_108 -> V_116 ) ;
}
static void F_76 ( struct V_37 * V_108 , int V_64 )
{
struct V_73 * V_74 ;
struct V_7 * V_8 ;
struct V_81 * V_131 ;
struct V_125 * V_126 ;
int V_57 , V_132 , V_133 ;
T_1 V_134 ;
T_3 * V_135 ;
F_67 ( & V_108 -> V_116 ) ;
F_2 ( L_20 ) ;
if ( ! ( V_8 = F_63 ( V_108 ) ) )
goto V_71;
if ( ( V_126 = F_68 ( V_108 , 0 , 1 , & V_57 ) ) == NULL )
goto V_71;
V_132 = V_126 -> V_64 - sizeof( struct V_141 ) ;
if ( V_132 < 4 ) {
F_2 ( L_21 , V_132 ) ;
goto V_136;
}
V_135 = F_69 ( V_126 , sizeof( struct V_141 ) ,
sizeof( V_134 ) , & V_134 ) ;
if ( V_135 == NULL )
goto V_136;
F_70 ( & V_8 -> V_88 ) ;
V_131 = F_71 ( V_8 , * V_135 ) ;
if ( ! V_131 )
goto V_137;
V_74 = V_131 -> V_138 ;
if ( ( V_133 = V_131 -> V_139 . V_140 ) > V_132 )
V_133 = V_132 ;
if ( F_77 ( & V_131 -> V_139 , V_126 ) ) {
F_78 ( V_108 , V_142 ) ;
goto V_137;
}
F_78 ( V_108 , V_143 ) ;
F_79 ( V_8 , V_74 , V_133 ) ;
F_72 ( V_74 , V_133 ) ;
V_137:
F_73 ( & V_8 -> V_88 ) ;
V_136:
F_74 ( V_108 , V_126 ) ;
V_71:
F_75 ( & V_108 -> V_116 ) ;
}
static void F_80 ( struct V_7 * V_8 )
{
F_32 ( V_122 , & V_8 -> V_107 ) ;
F_81 ( V_8 ) ;
}
static inline void F_82 ( struct V_7 * V_8 , struct V_127 * V_128 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
T_4 V_64 , V_144 ;
char * V_145 ;
V_145 = ( ( char * ) & V_76 -> V_146 ) + V_76 -> V_147 ;
V_64 = sizeof( V_76 -> V_146 ) - V_76 -> V_147 ;
V_144 = V_130 ( V_128 , V_145 , V_64 ) ;
V_76 -> V_147 += V_144 ;
if ( V_144 != V_64 )
return;
V_76 -> V_148 = F_11 ( V_76 -> V_146 ) ;
if ( V_76 -> V_148 & V_93 )
V_76 -> V_149 |= V_150 ;
else
V_76 -> V_149 &= ~ V_150 ;
V_76 -> V_148 &= V_151 ;
V_76 -> V_149 &= ~ V_152 ;
V_76 -> V_147 = 0 ;
if ( F_24 ( V_76 -> V_148 < 8 ) ) {
F_2 ( L_22 ) ;
F_80 ( V_8 ) ;
return;
}
F_2 ( L_23 ,
V_76 -> V_148 ) ;
}
static void F_83 ( struct V_75 * V_76 )
{
if ( V_76 -> V_147 == V_76 -> V_148 ) {
V_76 -> V_149 |= V_152 ;
V_76 -> V_147 = 0 ;
if ( V_76 -> V_149 & V_150 ) {
V_76 -> V_149 &= ~ V_153 ;
V_76 -> V_149 |= V_154 ;
V_76 -> V_155 = 0 ;
}
}
}
static inline void F_84 ( struct V_75 * V_76 , struct V_127 * V_128 )
{
T_4 V_64 , V_144 ;
char * V_145 ;
V_64 = sizeof( V_76 -> V_156 ) - V_76 -> V_147 ;
F_2 ( L_24 , V_64 ) ;
V_145 = ( ( char * ) & V_76 -> V_156 ) + V_76 -> V_147 ;
V_144 = V_130 ( V_128 , V_145 , V_64 ) ;
V_76 -> V_147 += V_144 ;
if ( V_144 != V_64 )
return;
V_76 -> V_149 &= ~ V_154 ;
V_76 -> V_149 |= V_157 ;
V_76 -> V_155 = 4 ;
F_2 ( L_25 ,
( V_76 -> V_149 & V_158 ) ? L_26
: L_27 ,
F_11 ( V_76 -> V_156 ) ) ;
F_83 ( V_76 ) ;
}
static inline void F_85 ( struct V_75 * V_76 ,
struct V_127 * V_128 )
{
T_4 V_64 , V_144 ;
T_1 V_129 ;
char * V_145 ;
V_129 = V_76 -> V_147 - sizeof( V_76 -> V_156 ) ;
V_64 = sizeof( V_76 -> V_159 ) - V_129 ;
F_2 ( L_28 , V_64 ) ;
V_145 = ( ( char * ) & V_76 -> V_159 ) + V_129 ;
V_144 = V_130 ( V_128 , V_145 , V_64 ) ;
V_76 -> V_147 += V_144 ;
if ( V_144 != V_64 )
return;
V_76 -> V_149 &= ~ V_157 ;
switch ( F_11 ( V_76 -> V_159 ) ) {
case V_160 :
V_76 -> V_149 |= V_161 ;
V_76 -> V_149 |= V_153 ;
V_76 -> V_149 |= V_158 ;
break;
case V_162 :
V_76 -> V_149 |= V_161 ;
V_76 -> V_149 |= V_153 ;
V_76 -> V_149 &= ~ V_158 ;
break;
default:
F_2 ( L_29 ) ;
F_80 ( & V_76 -> V_8 ) ;
}
F_83 ( V_76 ) ;
}
static inline void F_86 ( struct V_7 * V_8 ,
struct V_127 * V_128 ,
struct V_81 * V_82 )
{
struct V_75 * V_76 =
F_27 ( V_8 , struct V_75 , V_8 ) ;
struct V_52 * V_163 ;
T_4 V_64 ;
T_5 V_164 ;
V_163 = & V_82 -> V_139 ;
if ( V_76 -> V_149 & V_161 ) {
memcpy ( V_163 -> V_70 [ 0 ] . V_50 + V_76 -> V_155 ,
& V_76 -> V_159 ,
sizeof( V_76 -> V_159 ) ) ;
V_76 -> V_155 += sizeof( V_76 -> V_159 ) ;
V_76 -> V_149 &= ~ V_161 ;
}
V_64 = V_128 -> V_3 ;
if ( V_64 > V_76 -> V_148 - V_76 -> V_147 ) {
struct V_127 V_165 ;
V_64 = V_76 -> V_148 - V_76 -> V_147 ;
memcpy ( & V_165 , V_128 , sizeof( V_165 ) ) ;
V_165 . V_3 = V_64 ;
V_164 = F_65 ( V_163 , V_76 -> V_155 ,
& V_165 , V_130 ) ;
V_128 -> V_3 -= V_164 ;
V_128 -> V_129 += V_164 ;
} else
V_164 = F_65 ( V_163 , V_76 -> V_155 ,
V_128 , V_130 ) ;
if ( V_164 > 0 ) {
V_76 -> V_155 += V_164 ;
V_76 -> V_147 += V_164 ;
}
if ( V_164 != V_64 ) {
V_76 -> V_149 &= ~ V_153 ;
F_2 ( L_30 ,
F_11 ( V_76 -> V_156 ) ) ;
F_2 ( L_31
L_32 ,
V_8 , V_76 -> V_155 ,
V_76 -> V_147 , V_76 -> V_148 ) ;
return;
}
F_2 ( L_33 ,
F_11 ( V_76 -> V_156 ) , V_164 ) ;
F_2 ( L_34
L_35 , V_8 , V_76 -> V_155 ,
V_76 -> V_147 , V_76 -> V_148 ) ;
if ( V_76 -> V_155 == V_82 -> V_139 . V_140 )
V_76 -> V_149 &= ~ V_153 ;
else if ( V_76 -> V_147 == V_76 -> V_148 ) {
if ( V_76 -> V_149 & V_150 )
V_76 -> V_149 &= ~ V_153 ;
}
}
static inline int F_87 ( struct V_7 * V_8 ,
struct V_127 * V_128 )
{
struct V_75 * V_76 =
F_27 ( V_8 , struct V_75 , V_8 ) ;
struct V_81 * V_82 ;
F_2 ( L_36 , F_11 ( V_76 -> V_156 ) ) ;
F_70 ( & V_8 -> V_88 ) ;
V_82 = F_71 ( V_8 , V_76 -> V_156 ) ;
if ( ! V_82 ) {
F_2 ( L_37 ,
F_11 ( V_76 -> V_156 ) ) ;
F_73 ( & V_8 -> V_88 ) ;
return - 1 ;
}
F_86 ( V_8 , V_128 , V_82 ) ;
if ( ! ( V_76 -> V_149 & V_153 ) )
F_72 ( V_82 -> V_138 , V_76 -> V_155 ) ;
F_73 ( & V_8 -> V_88 ) ;
return 0 ;
}
static inline int F_88 ( struct V_7 * V_8 ,
struct V_127 * V_128 )
{
struct V_75 * V_76 =
F_27 ( V_8 , struct V_75 , V_8 ) ;
struct V_81 * V_82 ;
V_82 = F_89 ( V_8 ) ;
if ( V_82 == NULL ) {
F_90 ( V_166 L_38 ) ;
F_81 ( V_8 ) ;
return - 1 ;
}
V_82 -> V_167 = V_76 -> V_156 ;
F_2 ( L_39 , F_11 ( V_82 -> V_167 ) ) ;
F_86 ( V_8 , V_128 , V_82 ) ;
if ( ! ( V_76 -> V_149 & V_153 ) ) {
struct V_168 * V_169 = V_8 -> V_169 ;
F_2 ( L_40 ) ;
F_70 ( & V_169 -> V_170 ) ;
F_91 ( & V_82 -> V_171 , & V_169 -> V_172 ) ;
F_73 ( & V_169 -> V_170 ) ;
F_92 ( & V_169 -> V_173 ) ;
}
V_82 -> V_139 . V_64 = V_76 -> V_155 ;
return 0 ;
}
static inline int F_93 ( struct V_7 * V_8 ,
struct V_127 * V_128 )
{
struct V_75 * V_76 =
F_27 ( V_8 , struct V_75 , V_8 ) ;
return ( V_76 -> V_149 & V_158 ) ?
F_87 ( V_8 , V_128 ) :
F_88 ( V_8 , V_128 ) ;
}
static inline int F_93 ( struct V_7 * V_8 ,
struct V_127 * V_128 )
{
return F_87 ( V_8 , V_128 ) ;
}
static void F_94 ( struct V_7 * V_8 ,
struct V_127 * V_128 )
{
struct V_75 * V_76 =
F_27 ( V_8 , struct V_75 , V_8 ) ;
if ( F_93 ( V_8 , V_128 ) == 0 )
F_83 ( V_76 ) ;
else {
V_76 -> V_149 &= ~ V_153 ;
}
}
static inline void F_95 ( struct V_75 * V_76 , struct V_127 * V_128 )
{
T_4 V_64 ;
V_64 = V_76 -> V_148 - V_76 -> V_147 ;
if ( V_64 > V_128 -> V_3 )
V_64 = V_128 -> V_3 ;
V_128 -> V_3 -= V_64 ;
V_128 -> V_129 += V_64 ;
V_76 -> V_147 += V_64 ;
F_2 ( L_41 , V_64 ) ;
F_83 ( V_76 ) ;
}
static int F_96 ( T_6 * V_174 , struct V_125 * V_126 , unsigned int V_129 , T_4 V_64 )
{
struct V_7 * V_8 = V_174 -> V_175 . V_176 ;
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
struct V_127 V_128 = {
. V_126 = V_126 ,
. V_129 = V_129 ,
. V_3 = V_64 ,
} ;
F_2 ( L_42 ) ;
do {
if ( V_76 -> V_149 & V_152 ) {
F_82 ( V_8 , & V_128 ) ;
continue;
}
if ( V_76 -> V_149 & V_154 ) {
F_84 ( V_76 , & V_128 ) ;
continue;
}
if ( V_76 -> V_149 & V_157 ) {
F_85 ( V_76 , & V_128 ) ;
continue;
}
if ( V_76 -> V_149 & V_153 ) {
F_94 ( V_8 , & V_128 ) ;
continue;
}
F_95 ( V_76 , & V_128 ) ;
} while ( V_128 . V_3 );
F_2 ( L_43 ) ;
return V_64 - V_128 . V_3 ;
}
static void F_97 ( struct V_37 * V_108 , int V_177 )
{
struct V_7 * V_8 ;
T_6 V_174 ;
int V_178 ;
F_2 ( L_44 ) ;
F_67 ( & V_108 -> V_116 ) ;
if ( ! ( V_8 = F_63 ( V_108 ) ) )
goto V_71;
if ( V_8 -> V_119 )
V_8 -> V_119 = 0 ;
V_174 . V_175 . V_176 = V_8 ;
do {
V_174 . V_3 = 65536 ;
V_178 = F_98 ( V_108 , & V_174 , F_96 ) ;
} while ( V_178 > 0 );
V_71:
F_75 ( & V_108 -> V_116 ) ;
}
static void F_99 ( struct V_7 * V_8 ,
unsigned long V_179 )
{
struct V_75 * V_76 ;
if ( F_100 ( V_8 ) )
return;
F_32 ( V_120 , & V_8 -> V_107 ) ;
V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
F_101 ( V_180 , & V_76 -> V_124 ,
V_179 ) ;
}
static void F_102 ( struct V_7 * V_8 )
{
struct V_75 * V_76 ;
V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
if ( ! F_31 ( V_120 , & V_8 -> V_107 ) ||
! F_103 ( & V_76 -> V_124 ) )
return;
F_25 ( V_120 , & V_8 -> V_107 ) ;
F_104 ( V_8 ) ;
}
static void F_105 ( struct V_7 * V_8 )
{
F_53 () ;
F_25 ( V_120 , & V_8 -> V_107 ) ;
F_25 ( V_122 , & V_8 -> V_107 ) ;
F_25 ( V_106 , & V_8 -> V_107 ) ;
F_25 ( V_121 , & V_8 -> V_107 ) ;
F_54 () ;
}
static void F_106 ( struct V_7 * V_8 )
{
F_105 ( V_8 ) ;
F_55 ( V_8 ) ;
}
static void F_107 ( struct V_37 * V_108 )
{
struct V_7 * V_8 ;
F_67 ( & V_108 -> V_116 ) ;
if ( ! ( V_8 = F_63 ( V_108 ) ) )
goto V_71;
F_2 ( L_45 , V_8 ) ;
F_2 ( L_46 ,
V_108 -> V_181 , F_30 ( V_8 ) ,
F_108 ( V_108 , V_182 ) ,
F_108 ( V_108 , V_183 ) ,
V_108 -> V_184 ) ;
switch ( V_108 -> V_181 ) {
case V_185 :
F_70 ( & V_8 -> V_88 ) ;
if ( ! F_109 ( V_8 ) ) {
struct V_75 * V_76 = F_27 ( V_8 ,
struct V_75 , V_8 ) ;
V_76 -> V_147 = 0 ;
V_76 -> V_148 = 0 ;
V_76 -> V_155 = 0 ;
V_76 -> V_149 =
V_152 | V_154 ;
F_110 ( V_8 , - V_84 ) ;
}
F_73 ( & V_8 -> V_88 ) ;
break;
case V_186 :
V_8 -> V_187 ++ ;
V_8 -> V_119 = 0 ;
F_32 ( V_121 , & V_8 -> V_107 ) ;
F_53 () ;
F_25 ( V_188 , & V_8 -> V_107 ) ;
F_25 ( V_106 , & V_8 -> V_107 ) ;
F_54 () ;
F_99 ( V_8 , V_189 ) ;
break;
case V_190 :
V_8 -> V_187 ++ ;
F_25 ( V_188 , & V_8 -> V_107 ) ;
F_80 ( V_8 ) ;
case V_191 :
if ( V_8 -> V_119 < V_192 )
V_8 -> V_119 = V_192 ;
break;
case V_193 :
F_32 ( V_121 , & V_8 -> V_107 ) ;
F_99 ( V_8 , V_189 ) ;
F_53 () ;
F_25 ( V_188 , & V_8 -> V_107 ) ;
F_54 () ;
break;
case V_194 :
F_102 ( V_8 ) ;
F_106 ( V_8 ) ;
}
V_71:
F_75 ( & V_108 -> V_116 ) ;
}
static void F_111 ( struct V_37 * V_108 )
{
struct V_36 * V_37 ;
struct V_7 * V_8 ;
if ( F_24 ( ! ( V_37 = V_108 -> V_195 ) ) )
return;
F_25 ( V_89 , & V_37 -> V_65 ) ;
if ( F_24 ( ! ( V_8 = F_63 ( V_108 ) ) ) )
return;
if ( F_57 ( V_69 , & V_37 -> V_65 ) == 0 )
return;
F_112 ( V_8 ) ;
}
static void F_113 ( struct V_37 * V_108 )
{
F_67 ( & V_108 -> V_116 ) ;
if ( F_114 ( V_108 ) )
F_111 ( V_108 ) ;
F_75 ( & V_108 -> V_116 ) ;
}
static void F_115 ( struct V_37 * V_108 )
{
F_67 ( & V_108 -> V_116 ) ;
if ( F_116 ( V_108 ) >= F_117 ( V_108 ) )
F_111 ( V_108 ) ;
F_75 ( & V_108 -> V_116 ) ;
}
static void F_118 ( struct V_7 * V_8 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
struct V_37 * V_108 = V_76 -> V_79 ;
if ( V_76 -> V_196 ) {
V_108 -> V_197 |= V_198 ;
V_108 -> V_199 = V_76 -> V_196 * V_8 -> V_200 * 2 ;
}
if ( V_76 -> V_201 ) {
V_108 -> V_197 |= V_202 ;
V_108 -> V_203 = V_76 -> V_201 * V_8 -> V_200 * 2 ;
V_108 -> V_114 ( V_108 ) ;
}
}
static void F_119 ( struct V_7 * V_8 , T_4 V_201 , T_4 V_196 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
V_76 -> V_201 = 0 ;
if ( V_201 )
V_76 -> V_201 = V_201 + 1024 ;
V_76 -> V_196 = 0 ;
if ( V_196 )
V_76 -> V_196 = V_196 + 1024 ;
F_118 ( V_8 ) ;
}
static void F_120 ( struct V_7 * V_8 , struct V_73 * V_74 )
{
F_79 ( V_8 , V_74 , - V_204 ) ;
}
static unsigned short F_121 ( void )
{
unsigned short V_205 = V_206 - V_207 ;
unsigned short rand = ( unsigned short ) F_122 () % V_205 ;
return rand + V_207 ;
}
static void F_123 ( struct V_7 * V_8 , unsigned short V_208 )
{
F_2 ( L_47 , V_8 , V_208 ) ;
F_124 ( F_3 ( V_8 ) , V_208 ) ;
F_16 ( V_8 ) ;
}
static unsigned short F_125 ( struct V_75 * V_76 )
{
unsigned short V_208 = V_76 -> V_115 ;
if ( V_208 == 0 && V_76 -> V_8 . V_209 )
V_208 = F_121 () ;
return V_208 ;
}
static unsigned short F_126 ( struct V_75 * V_76 , unsigned short V_208 )
{
if ( V_76 -> V_115 != 0 )
V_76 -> V_115 = 0 ;
if ( ! V_76 -> V_8 . V_209 )
return 0 ;
if ( V_208 <= V_207 || V_208 > V_206 )
return V_206 ;
return -- V_208 ;
}
static int F_127 ( struct V_75 * V_76 , struct V_36 * V_37 )
{
struct V_210 V_211 ;
int V_57 , V_212 = 0 ;
unsigned short V_208 = F_125 ( V_76 ) ;
unsigned short V_213 ;
memcpy ( & V_211 , & V_76 -> V_214 , V_76 -> V_8 . V_38 ) ;
do {
F_124 ( (struct V_6 * ) & V_211 , V_208 ) ;
V_57 = F_128 ( V_37 , (struct V_6 * ) & V_211 ,
V_76 -> V_8 . V_38 ) ;
if ( V_208 == 0 )
break;
if ( V_57 == 0 ) {
V_76 -> V_115 = V_208 ;
break;
}
V_213 = V_208 ;
V_208 = F_126 ( V_76 , V_208 ) ;
if ( V_208 > V_213 )
V_212 ++ ;
} while ( V_57 == - V_215 && V_212 != 2 );
if ( V_211 . V_216 == V_22 )
F_2 ( L_48 , V_97 ,
& ( (struct V_11 * ) & V_211 ) -> V_23 ,
V_208 , V_57 ? L_49 : L_50 , V_57 ) ;
else
F_2 ( L_51 , V_97 ,
& ( (struct V_12 * ) & V_211 ) -> V_26 ,
V_208 , V_57 ? L_49 : L_50 , V_57 ) ;
return V_57 ;
}
static void F_129 ( struct V_73 * V_74 )
{
F_130 () ;
F_131 ( F_132 ( V_74 -> V_217 -> V_218 ) ) ;
F_133 () ;
}
static void F_134 ( struct V_7 * V_8 , unsigned short V_208 )
{
}
static inline void F_135 ( struct V_36 * V_37 )
{
struct V_37 * V_108 = V_37 -> V_108 ;
F_136 ( V_108 , L_52 ,
& V_219 [ 1 ] , L_53 , & V_220 [ 1 ] ) ;
}
static inline void F_137 ( struct V_36 * V_37 )
{
struct V_37 * V_108 = V_37 -> V_108 ;
F_136 ( V_108 , L_54 ,
& V_219 [ 0 ] , L_55 , & V_220 [ 0 ] ) ;
}
static inline void F_138 ( struct V_36 * V_37 )
{
struct V_37 * V_108 = V_37 -> V_108 ;
F_136 ( V_108 , L_56 ,
& V_219 [ 1 ] , L_57 , & V_220 [ 1 ] ) ;
}
static inline void F_139 ( int V_221 , struct V_36 * V_37 )
{
F_140 ( F_141 ( V_37 -> V_108 ) ) ;
if ( F_141 ( V_37 -> V_108 ) )
return;
switch ( V_221 ) {
case V_17 :
F_135 ( V_37 ) ;
break;
case V_22 :
F_137 ( V_37 ) ;
break;
case V_25 :
F_138 ( V_37 ) ;
break;
}
}
static inline void F_135 ( struct V_36 * V_37 )
{
}
static inline void F_137 ( struct V_36 * V_37 )
{
}
static inline void F_138 ( struct V_36 * V_37 )
{
}
static inline void F_139 ( int V_221 , struct V_36 * V_37 )
{
}
static struct V_36 * F_142 ( struct V_7 * V_8 ,
struct V_75 * V_76 , int V_221 , int type , int V_30 )
{
struct V_36 * V_37 ;
int V_57 ;
V_57 = F_143 ( V_8 -> V_222 , V_221 , type , V_30 , & V_37 , 1 ) ;
if ( V_57 < 0 ) {
F_2 ( L_58 ,
V_30 , - V_57 ) ;
goto V_71;
}
F_139 ( V_221 , V_37 ) ;
V_57 = F_127 ( V_76 , V_37 ) ;
if ( V_57 ) {
F_52 ( V_37 ) ;
goto V_71;
}
return V_37 ;
V_71:
return F_144 ( V_57 ) ;
}
static int F_145 ( struct V_7 * V_8 ,
struct V_36 * V_37 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 ,
V_8 ) ;
if ( ! V_76 -> V_79 ) {
struct V_37 * V_108 = V_37 -> V_108 ;
F_50 ( & V_108 -> V_116 ) ;
F_47 ( V_76 , V_108 ) ;
V_108 -> V_117 = V_8 ;
V_108 -> V_110 = F_66 ;
V_108 -> V_114 = F_113 ;
V_108 -> V_223 = V_224 ;
F_146 ( V_8 ) ;
V_76 -> V_37 = V_37 ;
V_76 -> V_79 = V_108 ;
F_51 ( & V_108 -> V_116 ) ;
}
V_8 -> V_225 . V_226 ++ ;
V_8 -> V_225 . V_227 = V_228 ;
return F_147 ( V_37 , F_3 ( V_8 ) , V_8 -> V_38 , 0 ) ;
}
static int F_148 ( struct V_75 * V_76 )
{
struct V_7 * V_8 = & V_76 -> V_8 ;
struct V_36 * V_37 ;
int V_95 = - V_229 ;
V_230 -> V_65 |= V_231 ;
F_25 ( V_120 , & V_8 -> V_107 ) ;
V_95 = F_143 ( V_8 -> V_222 , V_17 ,
V_232 , 0 , & V_37 , 1 ) ;
if ( V_95 < 0 ) {
F_2 ( L_59
L_60 , - V_95 ) ;
goto V_71;
}
F_135 ( V_37 ) ;
F_2 ( L_61 ,
V_8 , V_8 -> V_19 [ V_20 ] ) ;
V_95 = F_145 ( V_8 , V_37 ) ;
switch ( V_95 ) {
case 0 :
F_2 ( L_62 ,
V_8 , V_8 -> V_19 [ V_20 ] ) ;
F_149 ( V_8 ) ;
break;
case - V_233 :
F_2 ( L_63 ,
V_8 , V_8 -> V_19 [ V_20 ] ) ;
break;
case - V_101 :
F_2 ( L_64 ,
V_8 , V_8 -> V_19 [ V_20 ] ) ;
break;
default:
F_90 ( V_234 L_65 ,
V_97 , - V_95 ,
V_8 -> V_19 [ V_20 ] ) ;
}
V_71:
F_104 ( V_8 ) ;
F_110 ( V_8 , V_95 ) ;
V_230 -> V_65 &= ~ V_231 ;
return V_95 ;
}
static void F_150 ( struct V_7 * V_8 , struct V_73 * V_74 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
int V_83 ;
if ( F_151 ( V_74 ) ) {
F_152 ( V_74 , - V_90 ) ;
return;
}
V_83 = F_148 ( V_76 ) ;
if ( V_83 && ! F_153 ( V_74 ) )
F_154 ( 15000 ) ;
}
static void F_155 ( struct V_7 * V_8 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 ,
V_8 ) ;
if ( V_8 -> V_235 )
F_156 ( V_76 -> V_79 ) ;
}
int F_157 ( struct V_7 * V_8 , int V_236 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 ,
V_8 ) ;
int V_57 = 0 ;
if ( V_236 ) {
V_8 -> V_235 ++ ;
F_155 ( V_8 ) ;
} else if ( V_8 -> V_235 ) {
V_8 -> V_235 -- ;
F_158 ( V_76 -> V_79 ) ;
}
return V_57 ;
}
static void F_155 ( struct V_7 * V_8 )
{
}
static void F_159 ( struct V_7 * V_8 , struct V_36 * V_37 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
if ( ! V_76 -> V_79 ) {
struct V_37 * V_108 = V_37 -> V_108 ;
F_50 ( & V_108 -> V_116 ) ;
F_47 ( V_76 , V_108 ) ;
V_108 -> V_117 = V_8 ;
V_108 -> V_110 = F_76 ;
V_108 -> V_114 = F_113 ;
V_108 -> V_118 = V_237 ;
V_108 -> V_223 = V_224 ;
F_149 ( V_8 ) ;
V_76 -> V_37 = V_37 ;
V_76 -> V_79 = V_108 ;
F_155 ( V_8 ) ;
F_51 ( & V_108 -> V_116 ) ;
}
F_118 ( V_8 ) ;
}
static void F_160 ( struct V_238 * V_239 )
{
struct V_75 * V_76 =
F_27 ( V_239 , struct V_75 , V_124 . V_239 ) ;
struct V_7 * V_8 = & V_76 -> V_8 ;
struct V_36 * V_37 = V_76 -> V_37 ;
int V_95 = - V_229 ;
V_230 -> V_65 |= V_231 ;
F_49 ( V_76 ) ;
V_37 = F_142 ( V_8 , V_76 ,
F_3 ( V_8 ) -> V_16 , V_240 , V_241 ) ;
if ( F_161 ( V_37 ) )
goto V_71;
F_2 ( L_66
L_67 , V_8 ,
V_8 -> V_19 [ V_32 ] ,
V_8 -> V_19 [ V_20 ] ,
V_8 -> V_19 [ V_28 ] ) ;
F_159 ( V_8 , V_37 ) ;
V_95 = 0 ;
V_71:
F_104 ( V_8 ) ;
F_110 ( V_8 , V_95 ) ;
V_230 -> V_65 &= ~ V_231 ;
}
static void F_162 ( struct V_75 * V_76 )
{
int V_242 ;
struct V_6 V_243 ;
F_2 ( L_68 , V_76 ) ;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
V_243 . V_16 = V_244 ;
V_242 = F_147 ( V_76 -> V_37 , & V_243 , sizeof( V_243 ) , 0 ) ;
if ( ! V_242 )
F_105 ( & V_76 -> V_8 ) ;
F_2 ( L_69 , V_242 ) ;
}
static void F_163 ( struct V_75 * V_76 )
{
unsigned int V_107 = V_76 -> V_79 -> V_181 ;
if ( V_107 == V_194 && V_76 -> V_37 -> V_107 == V_245 ) {
if ( V_76 -> V_79 -> V_184 == 0 )
return;
F_2 ( L_70 ,
V_97 , V_76 -> V_79 -> V_184 ) ;
}
if ( ( 1 << V_107 ) & ( V_246 | V_247 ) ) {
if ( V_76 -> V_79 -> V_184 == 0 )
return;
F_2 ( L_71
L_72 ,
V_97 , V_76 -> V_79 -> V_184 ) ;
}
F_162 ( V_76 ) ;
}
static int F_164 ( struct V_7 * V_8 , struct V_36 * V_37 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
int V_83 = - V_90 ;
if ( ! V_76 -> V_79 ) {
struct V_37 * V_108 = V_37 -> V_108 ;
F_50 ( & V_108 -> V_116 ) ;
F_47 ( V_76 , V_108 ) ;
V_108 -> V_117 = V_8 ;
V_108 -> V_110 = F_97 ;
V_108 -> V_112 = F_107 ;
V_108 -> V_114 = F_115 ;
V_108 -> V_223 = V_224 ;
V_108 -> V_197 |= V_248 ;
F_165 ( V_108 , V_249 ) ;
F_166 ( V_108 ) -> V_250 = 0 ;
F_166 ( V_108 ) -> V_251 |= V_252 ;
F_146 ( V_8 ) ;
V_76 -> V_37 = V_37 ;
V_76 -> V_79 = V_108 ;
F_51 ( & V_108 -> V_116 ) ;
}
if ( ! F_41 ( V_8 ) )
goto V_71;
F_155 ( V_8 ) ;
V_8 -> V_225 . V_226 ++ ;
V_8 -> V_225 . V_227 = V_228 ;
V_83 = F_147 ( V_37 , F_3 ( V_8 ) , V_8 -> V_38 , V_253 ) ;
switch ( V_83 ) {
case 0 :
case - V_254 :
V_8 -> V_187 ++ ;
if ( V_8 -> V_119 < V_192 )
V_8 -> V_119 = V_192 ;
}
V_71:
return V_83 ;
}
static void F_167 ( struct V_238 * V_239 )
{
struct V_75 * V_76 =
F_27 ( V_239 , struct V_75 , V_124 . V_239 ) ;
struct V_36 * V_37 = V_76 -> V_37 ;
struct V_7 * V_8 = & V_76 -> V_8 ;
int V_95 = - V_229 ;
V_230 -> V_65 |= V_231 ;
if ( ! V_37 ) {
F_25 ( V_120 , & V_8 -> V_107 ) ;
V_37 = F_142 ( V_8 , V_76 ,
F_3 ( V_8 ) -> V_16 , V_232 , V_255 ) ;
if ( F_161 ( V_37 ) ) {
V_95 = F_168 ( V_37 ) ;
goto V_71;
}
} else {
int V_256 ;
V_256 = F_57 ( V_120 ,
& V_8 -> V_107 ) ;
F_163 ( V_76 ) ;
if ( V_256 )
goto V_257;
}
F_2 ( L_66
L_67 , V_8 ,
V_8 -> V_19 [ V_32 ] ,
V_8 -> V_19 [ V_20 ] ,
V_8 -> V_19 [ V_28 ] ) ;
V_95 = F_164 ( V_8 , V_37 ) ;
F_2 ( L_73 ,
V_8 , - V_95 , F_30 ( V_8 ) ,
V_37 -> V_108 -> V_181 ) ;
switch ( V_95 ) {
default:
F_90 ( L_74 ,
V_97 , V_95 ) ;
case - V_258 :
F_80 ( V_8 ) ;
break;
case 0 :
case - V_254 :
case - V_259 :
F_104 ( V_8 ) ;
V_230 -> V_65 &= ~ V_231 ;
return;
case - V_260 :
case - V_101 :
case - V_103 :
case - V_100 :
goto V_71;
}
V_257:
V_95 = - V_84 ;
V_71:
F_104 ( V_8 ) ;
F_110 ( V_8 , V_95 ) ;
V_230 -> V_65 &= ~ V_231 ;
}
static void F_169 ( struct V_7 * V_8 , struct V_73 * V_74 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
if ( V_76 -> V_37 != NULL && ! F_153 ( V_74 ) ) {
F_2 ( L_75
L_76 ,
V_8 , V_8 -> V_119 / V_261 ) ;
F_101 ( V_180 ,
& V_76 -> V_124 ,
V_8 -> V_119 ) ;
V_8 -> V_119 <<= 1 ;
if ( V_8 -> V_119 < V_192 )
V_8 -> V_119 = V_192 ;
if ( V_8 -> V_119 > V_262 )
V_8 -> V_119 = V_262 ;
} else {
F_2 ( L_77 , V_8 ) ;
F_101 ( V_180 ,
& V_76 -> V_124 , 0 ) ;
}
}
static void F_170 ( struct V_7 * V_8 , struct V_263 * V_264 )
{
long V_265 = 0 ;
if ( F_30 ( V_8 ) )
V_265 = ( long ) ( V_228 - V_8 -> V_266 ) / V_261 ;
F_171 ( V_264 , L_78
L_79 ,
V_8 -> V_225 . V_267 ,
V_8 -> V_225 . V_226 ,
V_8 -> V_225 . V_268 ,
V_265 ,
V_8 -> V_225 . V_269 ,
V_8 -> V_225 . V_270 ,
V_8 -> V_225 . V_271 ,
V_8 -> V_225 . V_272 ,
V_8 -> V_225 . V_273 ,
V_8 -> V_225 . V_274 ,
V_8 -> V_225 . V_275 ,
V_8 -> V_225 . V_276 ) ;
}
static void F_172 ( struct V_7 * V_8 , struct V_263 * V_264 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
F_171 ( V_264 , L_80
L_81 ,
V_76 -> V_115 ,
V_8 -> V_225 . V_267 ,
V_8 -> V_225 . V_269 ,
V_8 -> V_225 . V_270 ,
V_8 -> V_225 . V_271 ,
V_8 -> V_225 . V_272 ,
V_8 -> V_225 . V_273 ,
V_8 -> V_225 . V_274 ,
V_8 -> V_225 . V_275 ,
V_8 -> V_225 . V_276 ) ;
}
static void F_173 ( struct V_7 * V_8 , struct V_263 * V_264 )
{
struct V_75 * V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
long V_265 = 0 ;
if ( F_30 ( V_8 ) )
V_265 = ( long ) ( V_228 - V_8 -> V_266 ) / V_261 ;
F_171 ( V_264 , L_82
L_79 ,
V_76 -> V_115 ,
V_8 -> V_225 . V_267 ,
V_8 -> V_225 . V_226 ,
V_8 -> V_225 . V_268 ,
V_265 ,
V_8 -> V_225 . V_269 ,
V_8 -> V_225 . V_270 ,
V_8 -> V_225 . V_271 ,
V_8 -> V_225 . V_272 ,
V_8 -> V_225 . V_273 ,
V_8 -> V_225 . V_274 ,
V_8 -> V_225 . V_275 ,
V_8 -> V_225 . V_276 ) ;
}
static void * F_174 ( struct V_73 * V_74 , T_4 V_277 )
{
struct V_54 * V_54 ;
struct V_278 * V_4 ;
F_140 ( V_277 > V_279 - sizeof( struct V_278 ) ) ;
if ( V_277 > V_279 - sizeof( struct V_278 ) )
return NULL ;
V_54 = F_175 ( V_21 ) ;
if ( ! V_54 )
return NULL ;
V_4 = F_176 ( V_54 ) ;
V_4 -> V_64 = V_279 ;
return V_4 -> V_176 ;
}
static void F_177 ( void * V_280 )
{
struct V_278 * V_4 ;
if ( ! V_280 )
return;
V_4 = F_27 ( V_280 , struct V_278 , V_176 ) ;
F_178 ( ( unsigned long ) V_4 ) ;
}
static int F_179 ( struct V_81 * V_82 )
{
int V_64 ;
struct V_52 * V_281 = & V_82 -> V_94 ;
struct V_7 * V_8 = V_82 -> V_78 ;
struct V_75 * V_76 =
F_27 ( V_8 , struct V_75 , V_8 ) ;
struct V_36 * V_37 = V_76 -> V_37 ;
unsigned long V_282 ;
unsigned long V_283 ;
F_35 ( V_281 ) ;
V_283 = ( unsigned long ) V_281 -> V_72 [ 0 ] . V_50 & ~ V_63 ;
V_282 = ( unsigned long ) V_281 -> V_70 [ 0 ] . V_50 & ~ V_63 ;
V_64 = F_180 ( V_37 , V_281 ,
F_181 ( V_281 -> V_70 [ 0 ] . V_50 ) , V_282 ,
V_281 -> V_72 [ 0 ] . V_50 , V_283 ) ;
if ( V_64 != V_281 -> V_64 ) {
F_90 ( V_284 L_83 ) ;
V_64 = - V_84 ;
}
return V_64 ;
}
static int F_182 ( struct V_73 * V_74 )
{
struct V_81 * V_82 = V_74 -> V_77 ;
struct V_285 * V_8 ;
T_1 V_64 ;
F_2 ( L_84 , F_11 ( V_82 -> V_167 ) ) ;
V_8 = V_82 -> V_78 -> V_286 ;
if ( ! F_183 ( & V_8 -> V_287 ) ) {
F_184 ( & V_8 -> V_288 , V_74 , NULL ) ;
if ( ! F_183 ( & V_8 -> V_287 ) )
return - V_84 ;
F_185 ( & V_8 -> V_288 , V_74 ) ;
}
if ( F_31 ( V_289 , & V_8 -> V_290 ) )
V_64 = - V_90 ;
else
V_64 = F_179 ( V_82 ) ;
F_186 ( & V_8 -> V_287 ) ;
if ( V_64 > 0 )
V_64 = 0 ;
return V_64 ;
}
static void F_187 ( struct V_7 * V_8 )
{
}
static void F_188 ( struct V_7 * V_8 )
{
}
static int F_189 ( const int V_221 , struct V_6 * V_13 )
{
static const struct V_11 sin = {
. V_291 = V_22 ,
. V_23 . V_24 = F_190 ( V_292 ) ,
} ;
static const struct V_12 V_14 = {
. V_293 = V_25 ,
. V_26 = V_294 ,
} ;
switch ( V_221 ) {
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
return - V_295 ;
}
return 0 ;
}
static struct V_7 * F_191 ( struct V_296 * args ,
unsigned int V_297 ,
unsigned int V_298 )
{
struct V_7 * V_8 ;
struct V_75 * V_299 ;
if ( args -> V_38 > sizeof( V_8 -> V_9 ) ) {
F_2 ( L_86 ) ;
return F_144 ( - V_300 ) ;
}
V_8 = F_192 ( args -> V_301 , sizeof( * V_299 ) , V_297 ,
V_298 ) ;
if ( V_8 == NULL ) {
F_2 ( L_87
L_88 ) ;
return F_144 ( - V_302 ) ;
}
V_299 = F_27 ( V_8 , struct V_75 , V_8 ) ;
memcpy ( & V_8 -> V_9 , args -> V_303 , args -> V_38 ) ;
V_8 -> V_38 = args -> V_38 ;
if ( args -> V_214 )
memcpy ( & V_299 -> V_214 , args -> V_214 , args -> V_38 ) ;
else {
int V_57 ;
V_57 = F_189 ( args -> V_303 -> V_16 ,
(struct V_6 * ) & V_299 -> V_214 ) ;
if ( V_57 != 0 ) {
F_59 ( V_8 ) ;
return F_144 ( V_57 ) ;
}
}
return V_8 ;
}
static struct V_7 * F_193 ( struct V_296 * args )
{
struct V_10 * V_15 = (struct V_10 * ) args -> V_303 ;
struct V_75 * V_76 ;
struct V_7 * V_8 ;
struct V_7 * V_83 ;
V_8 = F_191 ( args , V_304 ,
V_305 ) ;
if ( F_161 ( V_8 ) )
return V_8 ;
V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
V_8 -> V_306 = 0 ;
V_8 -> V_307 = sizeof( V_92 ) / sizeof( T_1 ) ;
V_8 -> V_308 = V_309 ;
V_8 -> V_310 = V_311 ;
V_8 -> V_119 = V_192 ;
V_8 -> V_312 = V_313 ;
V_8 -> V_66 = & V_314 ;
V_8 -> V_179 = & V_315 ;
switch ( V_15 -> V_316 ) {
case V_17 :
if ( V_15 -> V_18 [ 0 ] != '/' ) {
F_2 ( L_89 ,
V_15 -> V_18 ) ;
V_83 = F_144 ( - V_260 ) ;
goto V_317;
}
F_131 ( V_8 ) ;
F_15 ( V_8 , L_90 , V_318 ) ;
V_83 = F_144 ( F_148 ( V_76 ) ) ;
if ( V_83 )
goto V_317;
break;
default:
V_83 = F_144 ( - V_295 ) ;
goto V_317;
}
F_2 ( L_91 ,
V_8 -> V_19 [ V_20 ] ) ;
if ( F_194 ( V_123 ) )
return V_8 ;
V_83 = F_144 ( - V_260 ) ;
V_317:
F_59 ( V_8 ) ;
return V_83 ;
}
static struct V_7 * F_195 ( struct V_296 * args )
{
struct V_6 * V_9 = args -> V_303 ;
struct V_7 * V_8 ;
struct V_75 * V_76 ;
struct V_7 * V_83 ;
V_8 = F_191 ( args , V_319 ,
V_319 ) ;
if ( F_161 ( V_8 ) )
return V_8 ;
V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
V_8 -> V_306 = V_241 ;
V_8 -> V_307 = 0 ;
V_8 -> V_308 = ( 1U << 16 ) - ( V_320 << 3 ) ;
V_8 -> V_310 = V_311 ;
V_8 -> V_119 = V_321 ;
V_8 -> V_312 = V_313 ;
V_8 -> V_66 = & V_322 ;
V_8 -> V_179 = & V_323 ;
switch ( V_9 -> V_16 ) {
case V_22 :
if ( ( (struct V_11 * ) V_9 ) -> V_324 != F_196 ( 0 ) )
F_131 ( V_8 ) ;
F_197 ( & V_76 -> V_124 ,
F_160 ) ;
F_15 ( V_8 , L_92 , V_325 ) ;
break;
case V_25 :
if ( ( (struct V_12 * ) V_9 ) -> V_326 != F_196 ( 0 ) )
F_131 ( V_8 ) ;
F_197 ( & V_76 -> V_124 ,
F_160 ) ;
F_15 ( V_8 , L_92 , V_327 ) ;
break;
default:
V_83 = F_144 ( - V_295 ) ;
goto V_317;
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
if ( F_194 ( V_123 ) )
return V_8 ;
V_83 = F_144 ( - V_260 ) ;
V_317:
F_59 ( V_8 ) ;
return V_83 ;
}
static struct V_7 * F_198 ( struct V_296 * args )
{
struct V_6 * V_9 = args -> V_303 ;
struct V_7 * V_8 ;
struct V_75 * V_76 ;
struct V_7 * V_83 ;
unsigned int V_298 = V_305 ;
if ( args -> V_65 & V_328 )
V_298 = V_329 ;
V_8 = F_191 ( args , V_304 ,
V_298 ) ;
if ( F_161 ( V_8 ) )
return V_8 ;
V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
V_8 -> V_306 = V_255 ;
V_8 -> V_307 = sizeof( V_92 ) / sizeof( T_1 ) ;
V_8 -> V_308 = V_309 ;
V_8 -> V_310 = V_311 ;
V_8 -> V_119 = V_192 ;
V_8 -> V_312 = V_313 ;
V_8 -> V_66 = & V_330 ;
V_8 -> V_179 = & V_331 ;
switch ( V_9 -> V_16 ) {
case V_22 :
if ( ( (struct V_11 * ) V_9 ) -> V_324 != F_196 ( 0 ) )
F_131 ( V_8 ) ;
F_197 ( & V_76 -> V_124 ,
F_167 ) ;
F_15 ( V_8 , L_95 , V_332 ) ;
break;
case V_25 :
if ( ( (struct V_12 * ) V_9 ) -> V_326 != F_196 ( 0 ) )
F_131 ( V_8 ) ;
F_197 ( & V_76 -> V_124 ,
F_167 ) ;
F_15 ( V_8 , L_95 , V_333 ) ;
break;
default:
V_83 = F_144 ( - V_295 ) ;
goto V_317;
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
if ( F_194 ( V_123 ) )
return V_8 ;
V_83 = F_144 ( - V_260 ) ;
V_317:
F_59 ( V_8 ) ;
return V_83 ;
}
static struct V_7 * F_199 ( struct V_296 * args )
{
struct V_6 * V_9 = args -> V_303 ;
struct V_7 * V_8 ;
struct V_75 * V_76 ;
struct V_334 * V_335 ;
struct V_7 * V_83 ;
if ( args -> V_286 -> V_336 ) {
return args -> V_286 -> V_336 ;
}
V_8 = F_191 ( args , V_304 ,
V_304 ) ;
if ( F_161 ( V_8 ) )
return V_8 ;
V_76 = F_27 ( V_8 , struct V_75 , V_8 ) ;
V_8 -> V_306 = V_255 ;
V_8 -> V_307 = sizeof( V_92 ) / sizeof( T_1 ) ;
V_8 -> V_308 = V_309 ;
V_8 -> V_179 = & V_331 ;
F_131 ( V_8 ) ;
V_8 -> V_310 = 0 ;
V_8 -> V_119 = 0 ;
V_8 -> V_312 = 0 ;
V_8 -> V_66 = & V_337 ;
switch ( V_9 -> V_16 ) {
case V_22 :
F_15 ( V_8 , L_95 ,
V_332 ) ;
break;
case V_25 :
F_15 ( V_8 , L_95 ,
V_333 ) ;
break;
default:
V_83 = F_144 ( - V_295 ) ;
goto V_317;
}
F_2 ( L_93 ,
V_8 -> V_19 [ V_20 ] ,
V_8 -> V_19 [ V_28 ] ,
V_8 -> V_19 [ V_32 ] ) ;
F_200 ( V_8 ) ;
args -> V_286 -> V_336 = V_8 ;
V_8 -> V_286 = args -> V_286 ;
V_335 = F_27 ( args -> V_286 , struct V_334 , V_338 ) ;
V_76 -> V_37 = V_335 -> V_339 ;
V_76 -> V_79 = V_335 -> V_340 ;
F_149 ( V_8 ) ;
if ( F_194 ( V_123 ) )
return V_8 ;
F_201 ( V_8 ) ;
V_83 = F_144 ( - V_260 ) ;
V_317:
F_59 ( V_8 ) ;
return V_83 ;
}
int F_202 ( void )
{
#ifdef F_203
if ( ! V_341 )
V_341 = F_204 ( V_342 ) ;
#endif
F_205 ( & V_343 ) ;
F_205 ( & V_344 ) ;
F_205 ( & V_345 ) ;
F_205 ( & V_346 ) ;
return 0 ;
}
void F_206 ( void )
{
#ifdef F_203
if ( V_341 ) {
F_207 ( V_341 ) ;
V_341 = NULL ;
}
#endif
F_208 ( & V_343 ) ;
F_208 ( & V_344 ) ;
F_208 ( & V_345 ) ;
F_208 ( & V_346 ) ;
}
static int F_209 ( const char * V_347 ,
const struct V_348 * V_349 ,
unsigned int V_350 , unsigned int V_351 )
{
unsigned long V_352 ;
int V_83 ;
if ( ! V_347 )
return - V_260 ;
V_83 = F_210 ( V_347 , 0 , & V_352 ) ;
if ( V_83 == - V_260 || V_352 < V_350 || V_352 > V_351 )
return - V_260 ;
* ( ( unsigned int * ) V_349 -> V_175 ) = V_352 ;
return 0 ;
}
static int F_211 ( const char * V_347 , const struct V_348 * V_349 )
{
return F_209 ( V_347 , V_349 ,
V_353 ,
V_354 ) ;
}
static int F_212 ( const char * V_347 ,
const struct V_348 * V_349 )
{
return F_209 ( V_347 , V_349 ,
V_355 ,
V_356 ) ;
}
static int F_213 ( const char * V_347 ,
const struct V_348 * V_349 )
{
return F_209 ( V_347 , V_349 ,
V_355 ,
V_329 ) ;
}

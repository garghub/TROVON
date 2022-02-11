static inline void F_1 ( struct V_1 T_1 * V_2 , int V_3 )
{
struct V_4 T_1 * V_5 ;
unsigned long V_6 ;
if ( ! V_3 ) {
F_2 ( V_2 , V_7 , 0xf8 ) ;
return;
}
V_5 = (struct V_4 T_1 * ) V_2 ;
F_3 ( V_6 ) ;
F_4 ( V_5 , V_8 ) ;
F_4 ( V_5 , V_9 ) ;
F_4 ( V_5 , V_10 ) ;
F_5 ( V_5 , V_11 , 0x57 ) ;
F_5 ( V_5 , V_11 , 0x17 ) ;
F_5 ( V_5 , V_11 , 0x57 ) ;
F_5 ( V_5 , V_11 , 0x57 ) ;
F_6 ( V_6 ) ;
}
static inline int F_7 ( struct V_1 T_1 * V_2 )
{
unsigned long V_6 ;
F_3 ( V_6 ) ;
F_2 ( V_2 , V_12 , 0xf5 ) ;
if ( F_8 ( V_2 , V_12 ) != 0xf5 )
goto V_13;
F_2 ( V_2 , V_12 , 0xf6 ) ;
if ( F_8 ( V_2 , V_12 ) != 0xf6 )
goto V_13;
F_2 ( V_2 , V_12 , 0xf7 ) ;
if ( F_8 ( V_2 , V_12 ) != 0xf7 )
goto V_13;
F_6 ( V_6 ) ;
return 1 ;
V_13:
F_6 ( V_6 ) ;
return 0 ;
}
static inline void F_9 ( struct V_1 T_1 * V_2 , int V_14 )
{
F_2 ( V_2 , V_12 , V_15 ) ;
F_10 ( V_14 & 0x100 ) ;
F_2 ( V_2 , V_12 , V_14 & V_16 ) ;
}
static inline void F_11 ( struct V_1 T_1 * V_2 , int V_17 )
{
unsigned long V_6 ;
F_3 ( V_6 ) ;
F_9 ( V_2 , V_17 ) ;
F_12 ( 1 ) ;
F_2 ( V_2 , V_12 , ( V_18 << 4 ) | V_18 ) ;
F_12 ( 1 ) ;
F_2 ( V_2 , V_12 , ( V_18 << 4 ) | ( ( ~ V_18 ) & 0x0F ) ) ;
F_12 ( 1 ) ;
F_6 ( V_6 ) ;
}
static inline int F_13 ( struct V_1 T_1 * V_2 , int V_19 )
{
int V_20 ;
F_9 ( V_2 , V_19 ) ;
F_12 ( 10 ) ;
V_20 = F_8 ( V_2 , V_21 ) ;
return ( V_20 & V_22 ) == 0 ;
}
static inline void F_14 ( struct V_1 T_1 * V_2 ,
enum V_23 V_24 )
{
if ( V_24 == V_25 ) {
F_2 ( V_2 , V_7 , V_26 ) ;
F_2 ( V_2 , V_27 , V_25 ) ;
} else if ( V_24 == V_26 ) {
F_2 ( V_2 , V_7 , V_25 ) ;
F_2 ( V_2 , V_27 , V_26 ) ;
}
}
static inline void F_15 ( struct V_1 T_1 * V_2 ,
enum V_28 V_17 )
{
if ( V_17 == V_29 ) {
int V_30 ;
F_11 ( V_2 , V_31 ) ;
for ( V_30 = 0 ; V_30 < 2 * V_32 ; V_30 ++ ) {
F_9 ( V_2 , V_15 ) ;
if ( F_13 ( V_2 , V_31 ) )
break;
V_33 -> V_34 = V_35 ;
F_16 ( 1 ) ;
}
} else if ( V_17 == V_36 ) {
F_11 ( V_2 , V_37 ) ;
F_9 ( V_2 , V_15 ) ;
}
}
static inline void F_17 ( struct V_1 T_1 * V_2 )
{
int V_30 ;
F_11 ( V_2 , V_38 ) ;
for ( V_30 = 0 ; V_30 < 2 * V_32 ; V_30 ++ ) {
F_9 ( V_2 , V_15 ) ;
if ( ! F_13 ( V_2 , V_39 ) )
break;
V_33 -> V_34 = V_35 ;
F_16 ( 1 ) ;
}
F_9 ( V_2 , V_15 ) ;
}
static inline void F_18 ( struct V_1 T_1 * V_2 , enum V_40 V_40 )
{
if ( V_40 == V_41 )
F_9 ( V_2 , V_42 ) ;
else if ( V_40 == V_43 )
F_9 ( V_2 , V_44 ) ;
}
static inline int F_19 ( struct V_1 T_1 * V_2 )
{
int V_45 ;
F_11 ( V_2 , V_46 ) ;
for ( V_45 = 0 ; V_45 < V_32 ; V_45 ++ ) {
V_33 -> V_34 = V_35 ;
F_16 ( 1 ) ;
F_9 ( V_2 , V_15 ) ;
if ( ! F_13 ( V_2 , V_46 ) )
return 0 ;
}
return - 1 ;
}
static inline int F_20 ( struct V_1 T_1 * V_2 )
{
int V_47 ;
F_11 ( V_2 , V_48 ) ;
for ( V_47 = 0 ; V_47 < 100 ; V_47 ++ ) {
F_9 ( V_2 , V_15 ) ;
if ( F_13 ( V_2 , V_49 ) )
break;
if ( F_19 ( V_2 ) )
return - 1 ;
}
if ( F_13 ( V_2 , V_49 ) )
return 0 ;
return - 1 ;
}
static inline int F_21 ( struct V_1 T_1 * V_2 , int V_50 )
{
if ( V_50 == 0 )
return 0 ;
if ( V_50 < 0 ) {
F_11 ( V_2 , V_48 ) ;
V_50 = - V_50 ;
} else
F_11 ( V_2 , V_51 ) ;
for ( ; V_50 > 0 ; V_50 -- ) {
if ( F_19 ( V_2 ) )
return - 1 ;
}
return 0 ;
}
static inline int F_22 ( struct V_52 * V_53 , int V_54 )
{
struct V_1 T_1 * V_2 = V_53 -> V_55 -> V_2 ;
int V_56 ;
V_56 = F_21 ( V_2 , V_54 - V_53 -> V_54 ) ;
if ( V_56 == 0 )
V_53 -> V_54 = V_54 ;
else {
F_20 ( V_2 ) ;
V_53 -> V_54 = 0 ;
}
return V_56 ;
}
static int F_23 ( struct V_52 * V_53 )
{
struct V_1 T_1 * V_2 = V_53 -> V_55 -> V_2 ;
F_14 ( V_2 , V_53 -> V_24 ) ;
F_15 ( V_2 , V_36 ) ;
F_17 ( V_2 ) ;
V_53 -> V_57 = 0 ;
V_53 -> V_58 = 1 ;
return 0 ;
}
static inline int F_24 ( struct V_52 * V_53 ,
int V_59 , int V_54 ,
int V_60 , unsigned char * V_61 )
{
struct V_1 T_1 * V_2 = V_53 -> V_55 -> V_2 ;
unsigned long V_6 ;
struct V_62 V_63 ;
int V_56 = - 1 ;
short V_30 ;
F_22 ( V_53 , V_54 ) ;
F_2 ( V_2 , V_27 , V_64 ) ;
F_18 ( V_2 , V_59 ) ;
F_2 ( V_2 , V_7 , V_59 ) ;
F_3 ( V_6 ) ;
for ( V_30 = 0 ; V_30 < 36 ; V_30 ++ ) {
V_56 = F_25 ( V_2 , & V_63 ) ;
if ( ! V_56 && ( V_63 . V_60 == V_60 ) ) {
V_56 = F_26 ( V_2 , V_61 ) ;
break;
}
}
F_6 ( V_6 ) ;
F_2 ( V_2 , V_7 , V_64 ) ;
if ( ( V_63 . V_59 != V_59 ) || ( V_63 . V_54 != V_54 ) ||
( V_63 . V_60 != V_60 ) )
return 0 ;
return V_56 ;
}
static int F_27 ( struct V_52 * V_53 ,
int V_65 , int V_66 ,
unsigned char * V_61 )
{
struct V_1 T_1 * V_2 = V_53 -> V_55 -> V_2 ;
int V_56 ;
int V_59 , V_54 , V_60 ;
int V_30 , V_47 ;
F_14 ( V_2 , V_53 -> V_24 ) ;
for ( V_30 = V_65 ; V_30 < V_65 + V_66 ; V_30 ++ ) {
int V_67 ;
V_54 = V_30 / V_53 -> V_68 ;
V_67 = V_30 % V_53 -> V_68 ;
V_59 = V_67 / V_53 -> V_69 ;
V_60 = V_67 % V_53 -> V_69 + 1 ;
V_47 = 5 ;
do {
V_56 = F_24 ( V_53 , V_59 , V_54 , V_60 ,
V_61 ) ;
if ( V_47 -- == 0 )
return - V_70 ;
} while ( V_56 != 512 );
V_61 += V_56 ;
}
return 0 ;
}
static void F_28 ( struct V_71 * V_72 )
{
struct V_73 * V_74 ;
struct V_52 * V_53 ;
V_74 = F_29 ( V_72 ) ;
while ( V_74 ) {
int V_75 = - V_70 ;
V_53 = V_74 -> V_76 -> V_77 ;
if ( F_30 ( V_74 ) >= V_53 -> V_78 )
goto V_79;
if ( ! V_53 -> V_57 )
goto V_79;
if ( F_31 ( V_74 ) == V_80 && V_53 -> V_81 )
goto V_79;
switch ( F_31 ( V_74 ) ) {
case V_80 :
break;
case V_82 :
V_75 = F_27 ( V_53 , F_30 ( V_74 ) ,
F_32 ( V_74 ) ,
V_74 -> V_61 ) ;
break;
}
V_79:
if ( ! F_33 ( V_74 , V_75 ) )
V_74 = F_29 ( V_72 ) ;
}
}
static void F_34 ( struct V_71 * V_72 )
{
F_28 ( V_72 ) ;
}
static int F_35 ( struct V_52 * V_53 , int type ,
struct V_83 * * V_84 )
{
if ( type >= F_36 ( V_85 ) )
return - V_86 ;
if ( type )
* V_84 = & V_85 [ type ] ;
else if ( V_53 -> type == V_87 )
* V_84 = & V_85 [ 3 ] ;
else if ( V_53 -> V_88 == 2 )
* V_84 = & V_85 [ 2 ] ;
else
* V_84 = & V_85 [ 1 ] ;
return 0 ;
}
static void F_37 ( struct V_52 * V_53 )
{
struct V_1 T_1 * V_2 = V_53 -> V_55 -> V_2 ;
if ( F_13 ( V_2 , V_39 ) ) {
struct V_83 * V_84 ;
V_53 -> V_57 = 1 ;
V_53 -> V_81 = F_13 ( V_2 , V_89 ) ;
V_53 -> type = F_13 ( V_2 , V_90 ) ;
if ( F_20 ( V_2 ) )
F_38 ( V_91
L_1 ) ;
F_20 ( V_2 ) ;
F_35 ( V_53 , 0 , & V_84 ) ;
V_53 -> V_78 = V_84 -> V_92 ;
V_53 -> V_68 = V_84 -> V_40 * V_84 -> V_93 ;
V_53 -> V_69 = V_84 -> V_93 ;
V_53 -> V_54 = 0 ;
} else {
V_53 -> V_57 = 0 ;
}
}
static int F_39 ( struct V_94 * V_95 , T_2 V_96 )
{
struct V_52 * V_53 = V_95 -> V_97 -> V_77 ;
struct V_1 T_1 * V_2 = V_53 -> V_55 -> V_2 ;
int V_75 ;
if ( V_53 -> V_98 == - 1 || ( V_53 -> V_98 && V_96 & V_99 ) )
return - V_100 ;
if ( V_96 & V_99 )
V_53 -> V_98 = - 1 ;
else
V_53 -> V_98 ++ ;
F_2 ( V_2 , V_101 , V_102 | V_103 ) ;
F_12 ( 10 ) ;
F_14 ( V_2 , V_25 ) ;
F_15 ( V_2 , V_29 ) ;
F_11 ( V_2 , V_104 ) ;
if ( V_53 -> V_58 )
F_37 ( V_53 ) ;
if ( ! V_53 -> V_57 ) {
V_75 = - V_105 ;
goto V_106;
}
if ( V_96 & V_107 )
return 0 ;
if ( V_96 & ( V_108 | V_109 ) ) {
F_40 ( V_95 ) ;
if ( ( V_96 & V_109 ) && V_53 -> V_81 ) {
V_75 = - V_110 ;
goto V_106;
}
}
return 0 ;
V_106:
if ( V_53 -> V_98 < 0 )
V_53 -> V_98 = 0 ;
else if ( V_53 -> V_98 > 0 )
-- V_53 -> V_98 ;
if ( V_53 -> V_98 == 0 )
F_15 ( V_2 , V_36 ) ;
return V_75 ;
}
static int F_41 ( struct V_94 * V_95 , T_2 V_96 )
{
int V_56 ;
F_42 ( & V_111 ) ;
V_56 = F_39 ( V_95 , V_96 ) ;
F_43 ( & V_111 ) ;
return V_56 ;
}
static void F_44 ( struct V_112 * V_113 , T_2 V_96 )
{
struct V_52 * V_53 = V_113 -> V_77 ;
struct V_1 T_1 * V_2 = V_53 -> V_55 -> V_2 ;
F_42 ( & V_111 ) ;
if ( V_53 -> V_98 < 0 )
V_53 -> V_98 = 0 ;
else if ( V_53 -> V_98 > 0 )
-- V_53 -> V_98 ;
if ( V_53 -> V_98 == 0 )
F_15 ( V_2 , V_36 ) ;
F_43 ( & V_111 ) ;
}
static int F_45 ( struct V_94 * V_95 , T_2 V_96 ,
unsigned int V_114 , unsigned long V_115 )
{
struct V_52 * V_53 = V_95 -> V_97 -> V_77 ;
int V_75 ;
if ( ( V_114 & 0x80 ) && ! F_46 ( V_116 ) )
return - V_117 ;
switch ( V_114 ) {
case V_118 :
if ( V_53 -> V_98 != 1 )
return - V_100 ;
F_42 ( & V_111 ) ;
V_75 = F_23 ( V_53 ) ;
F_43 ( & V_111 ) ;
return V_75 ;
case V_119 :
if ( F_47 ( ( void V_120 * ) V_115 , ( void * ) & V_85 ,
sizeof( struct V_83 ) ) )
return - V_121 ;
break;
default:
F_38 ( V_122 L_2 ,
V_114 ) ;
return - V_123 ;
}
return 0 ;
}
static int F_48 ( struct V_94 * V_95 , struct V_124 * V_125 )
{
struct V_52 * V_53 = V_95 -> V_97 -> V_77 ;
struct V_83 * V_84 ;
int V_56 ;
V_56 = F_35 ( V_53 , 0 , & V_84 ) ;
if ( V_56 )
return V_56 ;
V_125 -> V_126 = V_84 -> V_40 ;
V_125 -> V_127 = V_84 -> V_93 ;
V_125 -> V_128 = V_84 -> V_54 ;
return 0 ;
}
static unsigned int F_49 ( struct V_112 * V_113 ,
unsigned int V_129 )
{
struct V_52 * V_53 = V_113 -> V_77 ;
return V_53 -> V_58 ? V_130 : 0 ;
}
static int F_50 ( struct V_112 * V_113 )
{
struct V_52 * V_53 = V_113 -> V_77 ;
struct V_1 T_1 * V_2 = V_53 -> V_55 -> V_2 ;
F_14 ( V_2 , V_53 -> V_24 ) ;
if ( V_53 -> V_58 )
F_37 ( V_53 ) ;
if ( ! V_53 -> V_57 )
F_15 ( V_2 , V_36 ) ;
else
V_53 -> V_58 = 0 ;
return ! V_53 -> V_57 ;
}
static struct V_131 * F_51 ( T_3 V_132 , int * V_133 , void * V_134 )
{
struct V_135 * V_55 = V_134 ;
int V_136 = ( * V_133 & 3 ) ;
if ( V_136 > V_55 -> V_137 )
return NULL ;
* V_133 = 0 ;
return F_52 ( V_55 -> V_138 [ V_136 ] . V_113 ) ;
}
static int F_53 ( struct V_135 * V_55 , enum V_23 V_24 )
{
struct V_52 * V_53 = & V_55 -> V_138 [ V_55 -> V_137 ] ;
struct V_1 T_1 * V_2 = V_55 -> V_2 ;
V_53 -> V_24 = V_24 ;
F_14 ( V_2 , V_24 ) ;
F_15 ( V_2 , V_36 ) ;
if ( F_13 ( V_2 , V_139 ) )
V_53 -> V_88 = 1 ;
else
V_53 -> V_88 = 2 ;
V_53 -> V_98 = 0 ;
V_53 -> V_58 = 1 ;
V_55 -> V_137 ++ ;
return 0 ;
}
static int F_54 ( struct V_135 * V_55 )
{
int V_75 ;
int V_136 ;
struct V_1 T_1 * V_2 = V_55 -> V_2 ;
F_14 ( V_2 , V_25 ) ;
if ( F_13 ( V_2 , V_140 ) )
F_53 ( V_55 , V_25 ) ;
F_14 ( V_2 , V_26 ) ;
if ( F_13 ( V_2 , V_140 ) )
F_53 ( V_55 , V_26 ) ;
V_75 = F_55 ( V_141 , L_3 ) ;
if ( V_75 ) {
F_38 ( V_91 L_4 ,
V_141 ) ;
return - V_100 ;
}
for ( V_136 = 0 ; V_136 < V_55 -> V_137 ; V_136 ++ ) {
V_55 -> V_138 [ V_136 ] . V_113 = F_56 ( 1 ) ;
if ( V_55 -> V_138 [ V_136 ] . V_113 == NULL ) {
V_75 = - V_142 ;
goto V_143;
}
V_55 -> V_138 [ V_136 ] . V_55 = V_55 ;
}
F_57 ( & V_55 -> V_144 ) ;
V_55 -> V_145 = F_58 ( F_34 , & V_55 -> V_144 ) ;
if ( ! V_55 -> V_145 ) {
V_75 = - V_142 ;
goto V_143;
}
for ( V_136 = 0 ; V_136 < V_55 -> V_137 ; V_136 ++ ) {
V_55 -> V_138 [ V_136 ] . V_113 -> V_6 = V_146 ;
V_55 -> V_138 [ V_136 ] . V_113 -> V_147 = V_141 ;
V_55 -> V_138 [ V_136 ] . V_113 -> V_148 = V_136 ;
sprintf ( V_55 -> V_138 [ V_136 ] . V_113 -> V_149 , L_5 , V_136 ) ;
V_55 -> V_138 [ V_136 ] . V_113 -> V_150 = & V_151 ;
V_55 -> V_138 [ V_136 ] . V_113 -> V_77 = & V_55 -> V_138 [ V_136 ] ;
V_55 -> V_138 [ V_136 ] . V_113 -> V_145 = V_55 -> V_145 ;
F_59 ( V_55 -> V_138 [ V_136 ] . V_113 , 2880 ) ;
F_60 ( V_55 -> V_138 [ V_136 ] . V_113 ) ;
}
F_61 ( F_62 ( V_141 , 0 ) , 256 , V_152 ,
F_51 , NULL , V_55 ) ;
return 0 ;
V_143:
F_63 ( V_141 , L_3 ) ;
while ( V_136 -- )
F_64 ( V_55 -> V_138 [ V_136 ] . V_113 ) ;
return V_75 ;
}
static int F_65 ( struct V_153 * V_132 )
{
struct V_154 * V_155 ;
struct V_1 T_1 * V_156 ;
struct V_135 * V_55 ;
int V_56 ;
V_155 = F_66 ( V_132 , V_157 , 0 ) ;
if ( ! V_155 ) {
V_56 = - V_158 ;
goto V_106;
}
if ( ! F_67 ( V_155 -> V_159 , F_68 ( V_155 ) , V_160 ) ) {
V_56 = - V_100 ;
goto V_106;
}
V_156 = F_69 ( V_155 -> V_159 , F_68 ( V_155 ) ) ;
if ( ! V_156 ) {
V_56 = - V_142 ;
goto V_161;
}
F_1 ( V_156 , 1 ) ;
if ( ! F_7 ( V_156 ) ) {
F_38 ( V_162 L_6 ) ;
V_56 = - V_158 ;
goto V_163;
}
V_55 = F_70 ( sizeof( struct V_135 ) , V_164 ) ;
if ( ! V_55 ) {
V_56 = - V_142 ;
goto V_163;
}
F_71 ( V_132 , V_55 ) ;
V_55 -> V_2 = V_156 ;
V_56 = F_54 ( V_55 ) ;
if ( V_56 )
goto V_165;
return 0 ;
V_165:
F_71 ( V_132 , NULL ) ;
F_72 ( V_55 ) ;
V_163:
F_73 ( V_156 ) ;
V_161:
F_74 ( V_155 -> V_159 , F_68 ( V_155 ) ) ;
V_106:
return V_56 ;
}
static int F_75 ( struct V_153 * V_132 )
{
struct V_135 * V_55 = F_76 ( V_132 ) ;
int V_136 ;
struct V_154 * V_155 ;
F_77 ( F_62 ( V_141 , 0 ) , 256 ) ;
for ( V_136 = 0 ; V_136 < V_55 -> V_137 ; V_136 ++ ) {
F_78 ( V_55 -> V_138 [ V_136 ] . V_113 ) ;
F_64 ( V_55 -> V_138 [ V_136 ] . V_113 ) ;
}
F_63 ( V_141 , L_3 ) ;
F_79 ( V_55 -> V_145 ) ;
for ( V_136 = 0 ; V_136 < V_55 -> V_137 ; V_136 ++ )
F_23 ( & V_55 -> V_138 [ V_136 ] ) ;
F_73 ( V_55 -> V_2 ) ;
V_155 = F_66 ( V_132 , V_157 , 0 ) ;
if ( V_155 )
F_74 ( V_155 -> V_159 , F_68 ( V_155 ) ) ;
F_71 ( V_132 , NULL ) ;
F_72 ( V_55 ) ;
return 0 ;
}
static int T_4 F_80 ( void )
{
F_38 ( V_162 L_7 , V_166 ) ;
return F_81 ( & V_167 ) ;
}
static void T_5 F_82 ( void )
{
F_83 ( & V_167 ) ;
}

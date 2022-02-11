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
static struct V_71 * F_28 ( struct V_72 * V_55 )
{
struct V_73 * V_74 ;
struct V_71 * V_75 ;
int V_76 = V_55 -> V_77 ;
do {
V_74 = V_55 -> V_78 [ V_55 -> V_77 ] . V_79 -> V_80 ;
if ( ++ V_55 -> V_77 == V_55 -> V_81 )
V_55 -> V_77 = 0 ;
if ( V_74 ) {
V_75 = F_29 ( V_74 ) ;
if ( V_75 )
return V_75 ;
}
} while ( V_55 -> V_77 != V_76 );
return NULL ;
}
static void F_30 ( struct V_73 * V_74 )
{
struct V_72 * V_55 = V_74 -> V_82 ;
struct V_71 * V_83 ;
struct V_52 * V_53 ;
V_83 = F_28 ( V_55 ) ;
while ( V_83 ) {
int V_84 = - V_70 ;
V_53 = V_83 -> V_85 -> V_86 ;
if ( F_31 ( V_83 ) >= V_53 -> V_87 )
goto V_88;
if ( ! V_53 -> V_57 )
goto V_88;
if ( F_32 ( V_83 ) == V_89 && V_53 -> V_90 )
goto V_88;
switch ( F_32 ( V_83 ) ) {
case V_89 :
break;
case V_91 :
V_84 = F_27 ( V_53 , F_31 ( V_83 ) ,
F_33 ( V_83 ) ,
F_34 ( V_83 -> V_92 ) ) ;
break;
}
V_88:
if ( ! F_35 ( V_83 , V_84 ) )
V_83 = F_28 ( V_55 ) ;
}
}
static int F_36 ( struct V_52 * V_53 , int type ,
struct V_93 * * V_94 )
{
if ( type >= F_37 ( V_95 ) )
return - V_96 ;
if ( type )
* V_94 = & V_95 [ type ] ;
else if ( V_53 -> type == V_97 )
* V_94 = & V_95 [ 3 ] ;
else if ( V_53 -> V_98 == 2 )
* V_94 = & V_95 [ 2 ] ;
else
* V_94 = & V_95 [ 1 ] ;
return 0 ;
}
static void F_38 ( struct V_52 * V_53 )
{
struct V_1 T_1 * V_2 = V_53 -> V_55 -> V_2 ;
if ( F_13 ( V_2 , V_39 ) ) {
struct V_93 * V_94 ;
V_53 -> V_57 = 1 ;
V_53 -> V_90 = F_13 ( V_2 , V_99 ) ;
V_53 -> type = F_13 ( V_2 , V_100 ) ;
if ( F_20 ( V_2 ) )
F_39 ( V_101
L_1 ) ;
F_20 ( V_2 ) ;
F_36 ( V_53 , 0 , & V_94 ) ;
V_53 -> V_87 = V_94 -> V_102 ;
V_53 -> V_68 = V_94 -> V_40 * V_94 -> V_103 ;
V_53 -> V_69 = V_94 -> V_103 ;
V_53 -> V_54 = 0 ;
} else {
V_53 -> V_57 = 0 ;
}
}
static int F_40 ( struct V_104 * V_105 , T_2 V_106 )
{
struct V_52 * V_53 = V_105 -> V_107 -> V_86 ;
struct V_1 T_1 * V_2 = V_53 -> V_55 -> V_2 ;
int V_84 ;
if ( V_53 -> V_108 == - 1 || ( V_53 -> V_108 && V_106 & V_109 ) )
return - V_110 ;
if ( V_106 & V_109 )
V_53 -> V_108 = - 1 ;
else
V_53 -> V_108 ++ ;
F_2 ( V_2 , V_111 , V_112 | V_113 ) ;
F_12 ( 10 ) ;
F_14 ( V_2 , V_25 ) ;
F_15 ( V_2 , V_29 ) ;
F_11 ( V_2 , V_114 ) ;
if ( V_53 -> V_58 )
F_38 ( V_53 ) ;
if ( ! V_53 -> V_57 ) {
V_84 = - V_115 ;
goto V_116;
}
if ( V_106 & V_117 )
return 0 ;
if ( V_106 & ( V_118 | V_119 ) ) {
F_41 ( V_105 ) ;
if ( ( V_106 & V_119 ) && V_53 -> V_90 ) {
V_84 = - V_120 ;
goto V_116;
}
}
return 0 ;
V_116:
if ( V_53 -> V_108 < 0 )
V_53 -> V_108 = 0 ;
else if ( V_53 -> V_108 > 0 )
-- V_53 -> V_108 ;
if ( V_53 -> V_108 == 0 )
F_15 ( V_2 , V_36 ) ;
return V_84 ;
}
static int F_42 ( struct V_104 * V_105 , T_2 V_106 )
{
int V_56 ;
F_43 ( & V_121 ) ;
V_56 = F_40 ( V_105 , V_106 ) ;
F_44 ( & V_121 ) ;
return V_56 ;
}
static void F_45 ( struct V_122 * V_79 , T_2 V_106 )
{
struct V_52 * V_53 = V_79 -> V_86 ;
struct V_1 T_1 * V_2 = V_53 -> V_55 -> V_2 ;
F_43 ( & V_121 ) ;
if ( V_53 -> V_108 < 0 )
V_53 -> V_108 = 0 ;
else if ( V_53 -> V_108 > 0 )
-- V_53 -> V_108 ;
if ( V_53 -> V_108 == 0 )
F_15 ( V_2 , V_36 ) ;
F_44 ( & V_121 ) ;
}
static int F_46 ( struct V_104 * V_105 , T_2 V_106 ,
unsigned int V_123 , unsigned long V_124 )
{
struct V_52 * V_53 = V_105 -> V_107 -> V_86 ;
int V_84 ;
if ( ( V_123 & 0x80 ) && ! F_47 ( V_125 ) )
return - V_126 ;
switch ( V_123 ) {
case V_127 :
if ( V_53 -> V_108 != 1 )
return - V_110 ;
F_43 ( & V_121 ) ;
V_84 = F_23 ( V_53 ) ;
F_44 ( & V_121 ) ;
return V_84 ;
case V_128 :
if ( F_48 ( ( void V_129 * ) V_124 , ( void * ) & V_95 ,
sizeof( struct V_93 ) ) )
return - V_130 ;
break;
default:
F_39 ( V_131 L_2 ,
V_123 ) ;
return - V_132 ;
}
return 0 ;
}
static int F_49 ( struct V_104 * V_105 , struct V_133 * V_134 )
{
struct V_52 * V_53 = V_105 -> V_107 -> V_86 ;
struct V_93 * V_94 ;
int V_56 ;
V_56 = F_36 ( V_53 , 0 , & V_94 ) ;
if ( V_56 )
return V_56 ;
V_134 -> V_135 = V_94 -> V_40 ;
V_134 -> V_136 = V_94 -> V_103 ;
V_134 -> V_137 = V_94 -> V_54 ;
return 0 ;
}
static unsigned int F_50 ( struct V_122 * V_79 ,
unsigned int V_138 )
{
struct V_52 * V_53 = V_79 -> V_86 ;
return V_53 -> V_58 ? V_139 : 0 ;
}
static int F_51 ( struct V_122 * V_79 )
{
struct V_52 * V_53 = V_79 -> V_86 ;
struct V_1 T_1 * V_2 = V_53 -> V_55 -> V_2 ;
F_14 ( V_2 , V_53 -> V_24 ) ;
if ( V_53 -> V_58 )
F_38 ( V_53 ) ;
if ( ! V_53 -> V_57 )
F_15 ( V_2 , V_36 ) ;
else
V_53 -> V_58 = 0 ;
return ! V_53 -> V_57 ;
}
static struct V_140 * F_52 ( T_3 V_141 , int * V_142 , void * V_143 )
{
struct V_72 * V_55 = V_143 ;
int V_144 = ( * V_142 & 3 ) ;
if ( V_144 > V_55 -> V_81 )
return NULL ;
* V_142 = 0 ;
return F_53 ( V_55 -> V_78 [ V_144 ] . V_79 ) ;
}
static int F_54 ( struct V_72 * V_55 , enum V_23 V_24 )
{
struct V_52 * V_53 = & V_55 -> V_78 [ V_55 -> V_81 ] ;
struct V_1 T_1 * V_2 = V_55 -> V_2 ;
V_53 -> V_24 = V_24 ;
F_14 ( V_2 , V_24 ) ;
F_15 ( V_2 , V_36 ) ;
if ( F_13 ( V_2 , V_145 ) )
V_53 -> V_98 = 1 ;
else
V_53 -> V_98 = 2 ;
V_53 -> V_108 = 0 ;
V_53 -> V_58 = 1 ;
V_55 -> V_81 ++ ;
return 0 ;
}
static int F_55 ( struct V_72 * V_55 )
{
int V_84 ;
int V_144 ;
struct V_1 T_1 * V_2 = V_55 -> V_2 ;
F_14 ( V_2 , V_25 ) ;
if ( F_13 ( V_2 , V_146 ) )
F_54 ( V_55 , V_25 ) ;
F_14 ( V_2 , V_26 ) ;
if ( F_13 ( V_2 , V_146 ) )
F_54 ( V_55 , V_26 ) ;
V_84 = F_56 ( V_147 , L_3 ) ;
if ( V_84 ) {
F_39 ( V_101 L_4 ,
V_147 ) ;
return - V_110 ;
}
F_57 ( & V_55 -> V_148 ) ;
for ( V_144 = 0 ; V_144 < V_55 -> V_81 ; V_144 ++ ) {
V_55 -> V_78 [ V_144 ] . V_79 = F_58 ( 1 ) ;
if ( V_55 -> V_78 [ V_144 ] . V_79 == NULL ) {
V_84 = - V_149 ;
goto V_150;
}
V_55 -> V_78 [ V_144 ] . V_79 -> V_80 = F_59 ( F_30 ,
& V_55 -> V_148 ) ;
if ( ! V_55 -> V_78 [ V_144 ] . V_79 -> V_80 ) {
V_84 = - V_149 ;
F_60 ( V_55 -> V_78 [ V_144 ] . V_79 ) ;
goto V_150;
}
V_55 -> V_78 [ V_144 ] . V_79 -> V_80 -> V_82 = V_55 ;
V_55 -> V_78 [ V_144 ] . V_55 = V_55 ;
}
for ( V_144 = 0 ; V_144 < V_55 -> V_81 ; V_144 ++ ) {
V_55 -> V_78 [ V_144 ] . V_79 -> V_6 = V_151 ;
V_55 -> V_78 [ V_144 ] . V_79 -> V_152 = V_147 ;
V_55 -> V_78 [ V_144 ] . V_79 -> V_153 = V_144 ;
sprintf ( V_55 -> V_78 [ V_144 ] . V_79 -> V_154 , L_5 , V_144 ) ;
V_55 -> V_78 [ V_144 ] . V_79 -> V_155 = & V_156 ;
V_55 -> V_78 [ V_144 ] . V_79 -> V_86 = & V_55 -> V_78 [ V_144 ] ;
F_61 ( V_55 -> V_78 [ V_144 ] . V_79 , 2880 ) ;
F_62 ( V_55 -> V_78 [ V_144 ] . V_79 ) ;
}
F_63 ( F_64 ( V_147 , 0 ) , 256 , V_157 ,
F_52 , NULL , V_55 ) ;
return 0 ;
V_150:
F_65 ( V_147 , L_3 ) ;
while ( V_144 -- )
F_60 ( V_55 -> V_78 [ V_144 ] . V_79 ) ;
return V_84 ;
}
static int F_66 ( struct V_158 * V_141 )
{
struct V_159 * V_160 ;
struct V_1 T_1 * V_161 ;
struct V_72 * V_55 ;
int V_56 ;
V_160 = F_67 ( V_141 , V_162 , 0 ) ;
if ( ! V_160 ) {
V_56 = - V_163 ;
goto V_116;
}
if ( ! F_68 ( V_160 -> V_164 , F_69 ( V_160 ) , V_165 ) ) {
V_56 = - V_110 ;
goto V_116;
}
V_161 = F_70 ( V_160 -> V_164 , F_69 ( V_160 ) ) ;
if ( ! V_161 ) {
V_56 = - V_149 ;
goto V_166;
}
F_1 ( V_161 , 1 ) ;
if ( ! F_7 ( V_161 ) ) {
F_39 ( V_167 L_6 ) ;
V_56 = - V_163 ;
goto V_168;
}
V_55 = F_71 ( sizeof( struct V_72 ) , V_169 ) ;
if ( ! V_55 ) {
V_56 = - V_149 ;
goto V_168;
}
F_72 ( V_141 , V_55 ) ;
V_55 -> V_2 = V_161 ;
V_56 = F_55 ( V_55 ) ;
if ( V_56 )
goto V_170;
return 0 ;
V_170:
F_73 ( V_55 ) ;
V_168:
F_74 ( V_161 ) ;
V_166:
F_75 ( V_160 -> V_164 , F_69 ( V_160 ) ) ;
V_116:
return V_56 ;
}
static int F_76 ( struct V_158 * V_141 )
{
struct V_72 * V_55 = F_77 ( V_141 ) ;
int V_144 ;
struct V_159 * V_160 ;
F_78 ( F_64 ( V_147 , 0 ) , 256 ) ;
for ( V_144 = 0 ; V_144 < V_55 -> V_81 ; V_144 ++ ) {
F_79 ( V_55 -> V_78 [ V_144 ] . V_79 ) ;
F_80 ( V_55 -> V_78 [ V_144 ] . V_79 -> V_80 ) ;
F_60 ( V_55 -> V_78 [ V_144 ] . V_79 ) ;
}
F_65 ( V_147 , L_3 ) ;
for ( V_144 = 0 ; V_144 < V_55 -> V_81 ; V_144 ++ )
F_23 ( & V_55 -> V_78 [ V_144 ] ) ;
F_74 ( V_55 -> V_2 ) ;
V_160 = F_67 ( V_141 , V_162 , 0 ) ;
if ( V_160 )
F_75 ( V_160 -> V_164 , F_69 ( V_160 ) ) ;
F_73 ( V_55 ) ;
return 0 ;
}
static int T_4 F_81 ( void )
{
F_39 ( V_167 L_7 , V_171 ) ;
return F_82 ( & V_172 ) ;
}
static void T_5 F_83 ( void )
{
F_84 ( & V_172 ) ;
}

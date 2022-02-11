static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 , V_6 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_7 -> V_8 ; ++ V_5 ) {
if ( V_4 -> V_7 -> V_9 )
V_6 = V_4 -> V_7 -> V_8 - V_5 - 1 ;
else
V_6 = V_5 ;
F_3 ( & V_4 -> V_7 -> V_10 , 0 ,
V_6 , V_11 , 1 ) ;
}
F_4 ( V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_12 * V_13 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
if ( ! F_6 ( V_4 -> V_7 ) )
goto V_14;
V_13 = F_7 ( V_4 -> V_7 , 0 , 0 , V_4 -> V_15 ) ;
if ( V_13 ) {
F_8 ( V_13 ) ;
F_9 ( V_13 ) ;
}
F_10 ( V_4 -> V_7 ) ;
V_14:
F_4 ( V_4 ) ;
}
static inline T_1 F_11 ( T_2 V_16 , T_2 V_17 )
{
T_1 V_18 ;
V_18 = ( ( V_16 << 8 ) | V_17 ) ;
return V_18 ;
}
static inline struct V_19 * F_12 (
struct V_20 * V_21 )
{
struct V_19 * V_22 ;
V_22 = F_13 ( V_21 ) ;
if ( V_22 && V_22 -> V_23 )
V_22 = NULL ;
return V_22 ;
}
static inline void F_14 ( struct V_19 * V_24 )
{
V_24 -> V_25 = true ;
F_15 ( V_24 -> V_26 ,
F_16 ( & V_24 -> V_27 ) == 0 ) ;
V_24 -> V_25 = false ;
}
static inline struct V_19 * F_17 (
struct V_20 * V_21 )
{
struct V_19 * V_22 ;
V_22 = F_13 ( V_21 ) ;
if ( ! V_22 )
goto V_28;
if ( V_22 -> V_23 &&
( F_16 ( & V_22 -> V_27 ) == 0 ) )
V_22 = NULL ;
V_28:
return V_22 ;
}
static void F_18 ( struct V_29 * V_30 ,
unsigned int V_31 )
{
int V_32 ;
struct V_33 * V_34 ;
for ( V_32 = 0 ; V_32 < V_31 ; V_32 ++ ) {
V_34 = F_19 ( ( & V_30 [ V_32 ] ) ) ;
if ( V_34 != NULL )
F_20 ( V_34 ) ;
}
F_4 ( V_30 ) ;
}
static int F_21 ( struct V_29 * V_30 , unsigned int V_31 )
{
int V_32 ;
if ( V_31 < 2 )
return - 1 ;
for ( V_32 = 0 ; V_32 < V_31 ; V_32 ++ ) {
if ( V_32 == 0 ) {
if ( V_30 [ V_32 ] . V_35 + V_30 [ V_32 ] . V_36 != V_37 )
return V_32 ;
} else if ( V_32 == V_31 - 1 ) {
if ( V_30 [ V_32 ] . V_35 != 0 )
return V_32 ;
} else {
if ( V_30 [ V_32 ] . V_36 != V_37 || V_30 [ V_32 ] . V_35 != 0 )
return V_32 ;
}
}
return - 1 ;
}
static struct V_29 * F_22 ( struct V_29 * V_30 ,
unsigned int V_31 ,
unsigned int V_38 ,
int V_39 )
{
int V_32 ;
int V_40 ;
struct V_29 * V_41 ;
struct V_33 * V_34 ;
unsigned int V_42 = ( ( V_39 == V_43 ) ? 0 : V_37 ) ;
V_40 = F_23 ( V_38 , V_37 ) >> V_44 ;
V_41 = F_24 ( V_40 , sizeof( struct V_29 ) , V_45 ) ;
if ( ! V_41 )
return NULL ;
for ( V_32 = 0 ; V_32 < V_40 ; V_32 ++ ) {
V_34 = F_25 ( V_45 ) ;
if ( ! V_34 )
goto V_46;
F_26 ( & V_41 [ V_32 ] , V_34 , V_42 , 0 ) ;
}
return V_41 ;
V_46:
F_18 ( V_41 , V_40 ) ;
return NULL ;
}
static inline unsigned long F_27 ( struct V_29 * V_30 , int V_47 )
{
void * V_48 = F_28 ( F_19 ( V_30 + V_47 ) ) ;
return ( unsigned long ) V_48 ;
}
static inline void F_29 ( unsigned long V_48 )
{
F_30 ( ( void * ) V_48 ) ;
}
static unsigned int F_31 ( struct V_29 * V_49 ,
struct V_29 * V_41 ,
unsigned int V_50 ,
unsigned int V_51 )
{
int V_32 ;
int V_52 = 0 ;
unsigned long V_53 , V_54 ;
unsigned int V_55 , V_56 , V_57 ;
unsigned int V_58 = 0 ;
unsigned long V_59 = 0 ;
unsigned long V_60 = 0 ;
unsigned long V_61 ;
F_32 ( V_61 ) ;
for ( V_32 = 0 ; V_32 < V_50 ; V_32 ++ ) {
V_60 = F_27 ( V_49 , V_32 ) + V_49 [ V_32 ] . V_35 ;
V_54 = V_60 ;
V_56 = V_49 [ V_32 ] . V_36 ;
if ( V_59 == 0 )
V_59 = F_27 ( V_41 , V_52 ) ;
while ( V_56 ) {
V_53 = V_59 + V_41 [ V_52 ] . V_35 ;
V_55 = V_41 [ V_52 ] . V_36 - V_41 [ V_52 ] . V_35 ;
V_57 = F_33 ( V_55 , V_56 ) ;
memcpy ( ( void * ) V_54 , ( void * ) V_53 , V_57 ) ;
V_58 += V_57 ;
V_41 [ V_52 ] . V_35 += V_57 ;
V_56 -= V_57 ;
V_54 += V_57 ;
if ( V_41 [ V_52 ] . V_35 == V_41 [ V_52 ] . V_36 ) {
F_29 ( V_59 ) ;
V_52 ++ ;
if ( V_52 == V_51 ) {
F_29 ( V_60 - V_49 [ V_32 ] . V_35 ) ;
F_34 ( V_61 ) ;
return V_58 ;
}
if ( V_56 || V_32 != V_50 - 1 )
V_59 = F_27 ( V_41 , V_52 ) ;
} else if ( V_56 == 0 && V_32 == V_50 - 1 ) {
F_29 ( V_59 ) ;
}
}
F_29 ( V_60 - V_49 [ V_32 ] . V_35 ) ;
}
F_34 ( V_61 ) ;
return V_58 ;
}
static unsigned int F_35 ( struct V_29 * V_49 ,
struct V_29 * V_41 ,
unsigned int V_50 )
{
int V_32 ;
int V_52 = 0 ;
unsigned long V_53 , V_54 ;
unsigned int V_55 , V_56 , V_57 ;
unsigned int V_58 = 0 ;
unsigned long V_59 = 0 ;
unsigned long V_62 = 0 ;
unsigned long V_61 ;
F_32 ( V_61 ) ;
for ( V_32 = 0 ; V_32 < V_50 ; V_32 ++ ) {
V_62 = F_27 ( V_49 , V_32 ) + V_49 [ V_32 ] . V_35 ;
V_53 = V_62 ;
V_55 = V_49 [ V_32 ] . V_36 ;
if ( V_59 == 0 )
V_59 = F_27 ( V_41 , V_52 ) ;
while ( V_55 ) {
V_54 = V_59 + V_41 [ V_52 ] . V_36 ;
V_56 = V_37 - V_41 [ V_52 ] . V_36 ;
V_57 = F_33 ( V_55 , V_56 ) ;
memcpy ( ( void * ) V_54 , ( void * ) V_53 , V_57 ) ;
V_58 += V_57 ;
V_41 [ V_52 ] . V_36 += V_57 ;
V_55 -= V_57 ;
V_53 += V_57 ;
if ( V_41 [ V_52 ] . V_36 == V_37 ) {
F_29 ( V_59 ) ;
V_52 ++ ;
if ( V_55 || V_32 != V_50 - 1 )
V_59 = F_27 ( V_41 , V_52 ) ;
} else if ( V_55 == 0 && V_32 == V_50 - 1 ) {
F_29 ( V_59 ) ;
}
}
F_29 ( V_62 - V_49 [ V_32 ] . V_35 ) ;
}
F_34 ( V_61 ) ;
return V_58 ;
}
static int F_36 ( struct V_20 * V_21 )
{
struct V_19 * V_22 ;
struct V_63 * V_64 ;
struct V_65 * V_65 ;
int V_66 , V_67 ;
V_22 = F_12 ( V_21 ) ;
if ( ! V_22 )
return - V_68 ;
V_64 = & V_22 -> V_69 ;
V_65 = & V_64 -> V_65 ;
memset ( V_64 , 0 , sizeof( struct V_63 ) ) ;
F_37 ( & V_64 -> F_15 ) ;
V_65 -> V_70 = V_71 ;
V_65 -> V_61 = V_72 ;
V_66 = F_38 ( V_21 -> V_73 , V_65 ,
sizeof( struct V_65 ) ,
( unsigned long ) V_64 ,
V_74 ,
V_75 ) ;
if ( V_66 != 0 )
goto V_46;
V_67 = F_39 ( & V_64 -> F_15 , 5 * V_76 ) ;
if ( V_67 == 0 ) {
V_66 = - V_77 ;
goto V_46;
}
if ( V_65 -> V_70 != V_78 ||
V_65 -> V_79 != 0 )
goto V_46;
memset ( V_65 , 0 , sizeof( struct V_65 ) ) ;
V_65 -> V_70 = V_80 ;
V_65 -> V_61 = V_72 ;
V_65 -> V_18 . V_81 =
F_11 ( V_82 , V_83 ) ;
V_65 -> V_18 . V_84 = 0 ;
V_66 = F_38 ( V_21 -> V_73 , V_65 ,
sizeof( struct V_65 ) ,
( unsigned long ) V_64 ,
V_74 ,
V_75 ) ;
if ( V_66 != 0 )
goto V_46;
V_67 = F_39 ( & V_64 -> F_15 , 5 * V_76 ) ;
if ( V_67 == 0 ) {
V_66 = - V_77 ;
goto V_46;
}
if ( V_65 -> V_70 != V_78 ||
V_65 -> V_79 != 0 )
goto V_46;
memset ( V_65 , 0 , sizeof( struct V_65 ) ) ;
V_65 -> V_70 = V_85 ;
V_65 -> V_61 = V_72 ;
V_65 -> V_86 . V_87 =
V_22 -> V_87 ;
V_66 = F_38 ( V_21 -> V_73 , V_65 ,
sizeof( struct V_65 ) ,
( unsigned long ) V_64 ,
V_74 ,
V_75 ) ;
if ( V_66 != 0 )
goto V_46;
V_67 = F_39 ( & V_64 -> F_15 , 5 * V_76 ) ;
if ( V_67 == 0 ) {
V_66 = - V_77 ;
goto V_46;
}
if ( V_65 -> V_70 != V_78 ||
V_65 -> V_79 != 0 )
goto V_46;
V_22 -> V_88 = V_65 -> V_86 . V_88 ;
V_22 -> V_89
= V_65 -> V_86 . V_89 ;
memset ( V_65 , 0 , sizeof( struct V_65 ) ) ;
V_65 -> V_70 = V_90 ;
V_65 -> V_61 = V_72 ;
V_66 = F_38 ( V_21 -> V_73 , V_65 ,
sizeof( struct V_65 ) ,
( unsigned long ) V_64 ,
V_74 ,
V_75 ) ;
if ( V_66 != 0 )
goto V_46;
V_67 = F_39 ( & V_64 -> F_15 , 5 * V_76 ) ;
if ( V_67 == 0 ) {
V_66 = - V_77 ;
goto V_46;
}
if ( V_65 -> V_70 != V_78 ||
V_65 -> V_79 != 0 )
goto V_46;
V_46:
return V_66 ;
}
static void F_40 ( struct V_63 * V_91 )
{
struct V_92 * V_93 = V_91 -> V_94 ;
struct V_95 * V_96 = F_41 ( V_93 -> V_21 -> V_7 ) ;
void (* F_42)( struct V_92 * );
struct V_97 V_98 ;
struct V_99 * V_100 ;
struct V_3 * V_4 ;
struct V_101 * V_102 = V_93 -> V_21 -> V_103 ;
V_100 = & V_91 -> V_65 . V_100 ;
if ( V_91 -> V_51 ) {
if ( V_100 -> V_104 == V_105 )
F_31 ( F_43 ( V_93 ) ,
V_91 -> V_41 ,
F_44 ( V_93 ) ,
V_91 -> V_51 ) ;
F_18 ( V_91 -> V_41 ,
V_91 -> V_51 ) ;
}
if ( V_100 -> V_106 == V_107 )
V_93 -> V_108 = V_109 << 16 ;
else
V_93 -> V_108 = V_100 -> V_110 ;
if ( V_100 -> V_106 == V_111 ) {
struct V_19 * V_112 ;
struct V_20 * V_24 = V_96 -> V_24 ;
struct V_113 * V_7 ;
V_112 = F_17 ( V_24 ) ;
V_7 = V_112 -> V_7 ;
V_4 = F_45 ( sizeof( struct V_3 ) ,
V_45 ) ;
if ( ! V_4 ) {
V_93 -> V_108 = V_109 << 16 ;
} else {
V_4 -> V_7 = V_7 ;
V_4 -> V_15 = V_100 -> V_15 ;
F_46 ( & V_4 -> V_2 , F_5 ) ;
F_47 ( & V_4 -> V_2 ) ;
}
}
if ( V_93 -> V_108 ) {
if ( F_48 ( V_93 -> V_114 ,
V_115 , & V_98 ) )
F_49 ( L_1 , & V_98 ) ;
}
F_50 ( V_93 ,
V_91 -> V_116 . V_38 -
V_100 -> V_117 ) ;
F_42 = V_93 -> V_118 ;
V_93 -> V_119 = NULL ;
V_93 -> V_118 = NULL ;
F_42 ( V_93 ) ;
F_51 ( V_91 , V_102 -> V_120 ) ;
}
static void F_52 ( struct V_20 * V_21 ,
struct V_65 * V_65 ,
struct V_63 * V_64 )
{
struct V_19 * V_22 ;
struct V_65 * V_121 ;
V_22 = F_13 ( V_21 ) ;
V_121 = & V_64 -> V_65 ;
if ( ( V_121 -> V_100 . V_122 [ 0 ] == V_123 ) ||
( V_121 -> V_100 . V_122 [ 0 ] == V_124 ) ) {
V_65 -> V_100 . V_110 = 0 ;
V_65 -> V_100 . V_106 = V_125 ;
}
V_121 -> V_100 . V_110 = V_65 -> V_100 . V_110 ;
V_121 -> V_100 . V_106 = V_65 -> V_100 . V_106 ;
V_121 -> V_100 . V_126 =
V_65 -> V_100 . V_126 ;
if ( V_65 -> V_100 . V_110 != 0 ||
V_65 -> V_100 . V_106 != V_125 ) {
F_53 ( & V_21 -> V_21 ,
L_2 ,
V_121 -> V_100 . V_122 [ 0 ] ,
V_65 -> V_100 . V_110 ,
V_65 -> V_100 . V_106 ) ;
}
if ( ( V_65 -> V_100 . V_110 & 0xFF ) == 0x02 ) {
if ( V_65 -> V_100 . V_106 &
V_127 ) {
F_53 ( & V_21 -> V_21 ,
L_3 ,
V_64 ,
V_65 -> V_100 . V_126 ) ;
memcpy ( V_64 -> V_114 ,
V_65 -> V_100 . V_128 ,
V_65 -> V_100 . V_126 ) ;
}
}
V_121 -> V_100 . V_117 =
V_65 -> V_100 . V_117 ;
F_40 ( V_64 ) ;
if ( F_54 ( & V_22 -> V_27 ) &&
V_22 -> V_25 )
F_55 ( & V_22 -> V_26 ) ;
}
static void F_56 ( struct V_20 * V_21 ,
struct V_65 * V_65 ,
struct V_63 * V_64 )
{
struct V_3 * V_2 ;
struct V_19 * V_22 ;
switch ( V_65 -> V_70 ) {
case V_78 :
F_52 ( V_21 , V_65 , V_64 ) ;
break;
case V_129 :
case V_130 :
V_22 = F_17 ( V_21 ) ;
V_2 = F_45 ( sizeof( struct V_3 ) , V_45 ) ;
if ( ! V_2 )
return;
F_46 ( & V_2 -> V_2 , F_1 ) ;
V_2 -> V_7 = V_22 -> V_7 ;
F_47 ( & V_2 -> V_2 ) ;
break;
default:
break;
}
}
static void F_57 ( void * V_131 )
{
struct V_20 * V_21 = (struct V_20 * ) V_131 ;
struct V_19 * V_22 ;
T_3 V_132 ;
T_4 V_133 ;
unsigned char V_134 [ F_23 ( sizeof( struct V_65 ) , 8 ) ] ;
struct V_63 * V_64 ;
int V_66 ;
V_22 = F_17 ( V_21 ) ;
if ( ! V_22 )
return;
do {
V_66 = F_58 ( V_21 -> V_73 , V_134 ,
F_23 ( sizeof( struct V_65 ) , 8 ) ,
& V_132 , & V_133 ) ;
if ( V_66 == 0 && V_132 > 0 ) {
V_64 = (struct V_63 * )
( unsigned long ) V_133 ;
if ( ( V_64 == & V_22 -> V_69 ) ||
( V_64 == & V_22 -> V_135 ) ) {
memcpy ( & V_64 -> V_65 , V_134 ,
sizeof( struct V_65 ) ) ;
F_59 ( & V_64 -> F_15 ) ;
} else {
F_56 ( V_21 ,
(struct V_65 * ) V_134 ,
V_64 ) ;
}
} else {
break;
}
} while ( 1 );
return;
}
static int F_60 ( struct V_20 * V_21 , T_3 V_136 )
{
struct V_137 V_138 ;
int V_66 ;
memset ( & V_138 , 0 , sizeof( struct V_137 ) ) ;
V_66 = F_61 ( V_21 -> V_73 ,
V_136 ,
V_136 ,
( void * ) & V_138 ,
sizeof( struct V_137 ) ,
F_57 , V_21 ) ;
if ( V_66 != 0 )
return V_66 ;
V_66 = F_36 ( V_21 ) ;
return V_66 ;
}
static int F_62 ( struct V_20 * V_21 )
{
struct V_19 * V_22 ;
unsigned long V_61 ;
V_22 = F_13 ( V_21 ) ;
F_63 ( & V_21 -> V_73 -> V_139 , V_61 ) ;
V_22 -> V_23 = true ;
F_64 ( & V_21 -> V_73 -> V_139 , V_61 ) ;
F_14 ( V_22 ) ;
F_63 ( & V_21 -> V_73 -> V_139 , V_61 ) ;
F_65 ( V_21 , NULL ) ;
F_64 ( & V_21 -> V_73 -> V_139 , V_61 ) ;
F_66 ( V_21 -> V_73 ) ;
F_4 ( V_22 ) ;
return 0 ;
}
static int F_67 ( struct V_20 * V_21 ,
struct V_63 * V_64 )
{
struct V_19 * V_22 ;
struct V_65 * V_65 ;
int V_66 = 0 ;
V_65 = & V_64 -> V_65 ;
V_22 = F_12 ( V_21 ) ;
if ( ! V_22 )
return - V_68 ;
V_64 -> V_21 = V_21 ;
V_65 -> V_61 |= V_72 ;
V_65 -> V_100 . V_36 = sizeof( struct V_99 ) ;
V_65 -> V_100 . V_126 = V_140 ;
V_65 -> V_100 . V_117 =
V_64 -> V_116 . V_38 ;
V_65 -> V_70 = V_141 ;
if ( V_64 -> V_116 . V_38 ) {
V_66 = F_68 ( V_21 -> V_73 ,
& V_64 -> V_116 ,
V_65 ,
sizeof( struct V_65 ) ,
( unsigned long ) V_64 ) ;
} else {
V_66 = F_38 ( V_21 -> V_73 , V_65 ,
sizeof( struct V_65 ) ,
( unsigned long ) V_64 ,
V_74 ,
V_75 ) ;
}
if ( V_66 != 0 )
return V_66 ;
F_69 ( & V_22 -> V_27 ) ;
return V_66 ;
}
static int F_70 ( struct V_12 * V_142 )
{
struct V_101 * V_102 ;
int V_143 = V_144 ;
V_102 = F_71 ( sizeof( struct V_101 ) , V_145 ) ;
if ( ! V_102 )
return - V_146 ;
V_102 -> V_147 =
F_72 ( F_73 ( & V_142 -> V_148 ) ,
sizeof( struct V_63 ) , 0 ,
V_149 , NULL ) ;
if ( ! V_102 -> V_147 )
goto V_150;
V_102 -> V_120 = F_74 ( V_143 , V_151 ,
V_152 ,
V_102 -> V_147 ) ;
if ( ! V_102 -> V_120 )
goto V_153;
V_142 -> V_103 = V_102 ;
return 0 ;
V_153:
F_75 ( V_102 -> V_147 ) ;
V_150:
F_4 ( V_102 ) ;
return - V_146 ;
}
static void F_76 ( struct V_12 * V_142 )
{
struct V_101 * V_102 = V_142 -> V_103 ;
F_77 ( V_102 -> V_120 ) ;
F_75 ( V_102 -> V_147 ) ;
F_4 ( V_102 ) ;
V_142 -> V_103 = NULL ;
}
static int F_78 ( struct V_12 * V_142 )
{
F_79 ( V_142 , V_154 ,
V_155 ) ;
F_80 ( V_142 -> V_156 , V_37 ) ;
F_81 ( V_142 -> V_156 , V_157 ) ;
return 0 ;
}
static int F_82 ( struct V_12 * V_13 , struct V_158 * V_159 ,
T_5 V_160 , int * V_161 )
{
T_5 V_162 = V_160 ;
T_5 V_163 = V_162 ;
int V_164 , V_165 ;
V_164 = 0xff ;
V_165 = 0x3f ;
F_83 ( V_163 , V_164 * V_165 ) ;
if ( ( T_5 ) ( V_163 + 1 ) * V_164 * V_165 < V_162 )
V_163 = 0xffff ;
V_161 [ 0 ] = V_164 ;
V_161 [ 1 ] = V_165 ;
V_161 [ 2 ] = ( int ) V_163 ;
return 0 ;
}
static int F_84 ( struct V_92 * V_93 )
{
struct V_95 * V_96 = F_41 ( V_93 -> V_21 -> V_7 ) ;
struct V_20 * V_21 = V_96 -> V_24 ;
struct V_19 * V_22 ;
struct V_63 * V_64 ;
struct V_65 * V_65 ;
int V_66 , V_67 ;
V_22 = F_12 ( V_21 ) ;
if ( ! V_22 )
return V_166 ;
V_64 = & V_22 -> V_135 ;
V_65 = & V_64 -> V_65 ;
F_37 ( & V_64 -> F_15 ) ;
V_65 -> V_70 = V_167 ;
V_65 -> V_61 = V_72 ;
V_65 -> V_100 . V_88 = V_22 -> V_88 ;
V_66 = F_38 ( V_21 -> V_73 , V_65 ,
sizeof( struct V_65 ) ,
( unsigned long ) & V_22 -> V_135 ,
V_74 ,
V_75 ) ;
if ( V_66 != 0 )
return V_166 ;
V_67 = F_39 ( & V_64 -> F_15 , 5 * V_76 ) ;
if ( V_67 == 0 )
return V_168 ;
return V_169 ;
}
static bool F_85 ( struct V_92 * V_93 )
{
bool V_170 = true ;
T_2 V_171 = V_93 -> V_172 [ 0 ] ;
switch ( V_171 ) {
case V_173 :
V_93 -> V_108 = V_174 << 16 ;
V_170 = false ;
break;
default:
break;
}
return V_170 ;
}
static int F_86 ( struct V_113 * V_7 , struct V_92 * V_93 )
{
int V_66 ;
struct V_95 * V_96 = F_41 ( V_7 ) ;
struct V_20 * V_24 = V_96 -> V_24 ;
struct V_63 * V_91 ;
unsigned int V_175 = 0 ;
int V_32 ;
struct V_29 * V_30 ;
unsigned int V_31 = 0 ;
struct V_99 * V_100 ;
struct V_101 * V_102 = V_93 -> V_21 -> V_103 ;
if ( ! F_85 ( V_93 ) ) {
V_93 -> V_118 ( V_93 ) ;
return 0 ;
}
V_175 = sizeof( struct V_63 ) ;
V_91 = F_87 ( V_102 -> V_120 ,
V_45 ) ;
if ( ! V_91 )
return V_176 ;
memset ( V_91 , 0 , sizeof( struct V_63 ) ) ;
V_91 -> V_94 = V_93 ;
V_93 -> V_119 = ( unsigned char * ) V_91 ;
V_100 = & V_91 -> V_65 . V_100 ;
switch ( V_93 -> V_177 ) {
case V_178 :
V_100 -> V_104 = V_43 ;
break;
case V_179 :
V_100 -> V_104 = V_105 ;
break;
default:
V_100 -> V_104 = V_180 ;
break;
}
V_100 -> V_87 = V_96 -> V_181 ;
V_100 -> V_88 = V_93 -> V_21 -> V_73 ;
V_100 -> V_89 = V_93 -> V_21 -> V_5 ;
V_100 -> V_15 = V_93 -> V_21 -> V_15 ;
V_100 -> V_182 = V_93 -> V_183 ;
memcpy ( V_100 -> V_122 , V_93 -> V_172 , V_100 -> V_182 ) ;
V_91 -> V_114 = V_93 -> V_114 ;
V_91 -> V_116 . V_38 = F_88 ( V_93 ) ;
if ( F_44 ( V_93 ) ) {
V_30 = (struct V_29 * ) F_43 ( V_93 ) ;
V_31 = F_44 ( V_93 ) ;
if ( F_21 ( V_30 , F_44 ( V_93 ) ) != - 1 ) {
V_91 -> V_41 =
F_22 ( V_30 , F_44 ( V_93 ) ,
F_88 ( V_93 ) ,
V_100 -> V_104 ) ;
if ( ! V_91 -> V_41 ) {
V_66 = V_184 ;
goto V_185;
}
V_91 -> V_51 =
F_23 ( F_88 ( V_93 ) , V_37 ) >>
V_44 ;
if ( V_100 -> V_104 == V_43 )
F_35 ( V_30 ,
V_91 -> V_41 ,
F_44 ( V_93 ) ) ;
V_30 = V_91 -> V_41 ;
V_31 = V_91 -> V_51 ;
}
V_91 -> V_116 . V_35 = V_30 [ 0 ] . V_35 ;
for ( V_32 = 0 ; V_32 < V_31 ; V_32 ++ )
V_91 -> V_116 . V_186 [ V_32 ] =
F_89 ( F_19 ( ( & V_30 [ V_32 ] ) ) ) ;
} else if ( F_43 ( V_93 ) ) {
V_91 -> V_116 . V_35 =
F_90 ( F_43 ( V_93 ) ) & ( V_37 - 1 ) ;
V_91 -> V_116 . V_186 [ 0 ] =
F_90 ( F_43 ( V_93 ) ) >> V_44 ;
}
V_66 = F_67 ( V_24 , V_91 ) ;
if ( V_66 == - V_187 ) {
if ( V_91 -> V_51 ) {
F_18 ( V_91 -> V_41 ,
V_91 -> V_51 ) ;
V_66 = V_176 ;
goto V_185;
}
}
return 0 ;
V_185:
F_51 ( V_91 , V_102 -> V_120 ) ;
V_93 -> V_119 = NULL ;
return V_66 ;
}
static int F_91 ( struct V_20 * V_21 ,
const struct V_188 * V_189 )
{
int V_66 ;
struct V_113 * V_7 ;
struct V_95 * V_96 ;
bool V_190 = ( ( V_189 -> V_191 == V_192 ) ? true : false ) ;
int V_193 = 0 ;
struct V_19 * V_22 ;
V_7 = F_92 ( & V_194 ,
sizeof( struct V_95 ) ) ;
if ( ! V_7 )
return - V_146 ;
V_96 = F_41 ( V_7 ) ;
memset ( V_96 , 0 , sizeof( struct V_95 ) ) ;
V_96 -> V_181 = V_7 -> V_195 ;
V_96 -> V_24 = V_21 ;
V_22 = F_71 ( sizeof( struct V_19 ) , V_145 ) ;
if ( ! V_22 ) {
V_66 = - V_146 ;
goto V_196;
}
V_22 -> V_23 = false ;
F_93 ( & V_22 -> V_26 ) ;
V_22 -> V_21 = V_21 ;
V_22 -> V_7 = V_7 ;
F_65 ( V_21 , V_22 ) ;
V_22 -> V_87 = V_7 -> V_195 ;
V_66 = F_60 ( V_21 , V_197 ) ;
if ( V_66 )
goto V_198;
V_96 -> V_199 = V_22 -> V_88 ;
V_96 -> V_193 = V_22 -> V_89 ;
V_7 -> V_200 = V_201 ;
V_7 -> V_8 = V_202 ;
V_7 -> V_203 = V_204 - 1 ;
V_7 -> V_205 = V_206 ;
V_66 = F_94 ( V_7 , & V_21 -> V_21 ) ;
if ( V_66 != 0 )
goto V_207;
if ( ! V_190 ) {
F_95 ( V_7 ) ;
} else {
V_193 = ( V_21 -> V_208 . V_209 [ 5 ] << 8 |
V_21 -> V_208 . V_209 [ 4 ] ) ;
V_66 = F_96 ( V_7 , 0 , V_193 , 0 ) ;
if ( V_66 ) {
F_97 ( V_7 ) ;
goto V_207;
}
}
return 0 ;
V_207:
F_62 ( V_21 ) ;
goto V_196;
V_198:
F_4 ( V_22 ) ;
V_196:
F_10 ( V_7 ) ;
return V_66 ;
}
static int F_98 ( struct V_20 * V_24 )
{
struct V_19 * V_22 = F_13 ( V_24 ) ;
struct V_113 * V_7 = V_22 -> V_7 ;
F_97 ( V_7 ) ;
F_62 ( V_24 ) ;
F_10 ( V_7 ) ;
return 0 ;
}
static int T_6 F_99 ( void )
{
T_3 V_210 ;
V_210 =
( ( V_197 - V_37 ) /
F_23 ( V_211 +
sizeof( struct V_65 ) + sizeof( T_4 ) ,
sizeof( T_4 ) ) ) ;
if ( V_210 <
V_155 )
return - V_212 ;
return F_100 ( & V_213 ) ;
}
static void T_7 F_101 ( void )
{
F_102 ( & V_213 ) ;
}

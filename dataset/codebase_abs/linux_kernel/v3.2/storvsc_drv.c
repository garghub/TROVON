static inline struct V_1 * F_1 (
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_3 ) ;
if ( V_4 && V_4 -> V_5 )
V_4 = NULL ;
return V_4 ;
}
static inline void F_3 ( struct V_1 * V_6 )
{
V_6 -> V_7 = true ;
F_4 ( V_6 -> V_8 ,
F_5 ( & V_6 -> V_9 ) == 0 ) ;
V_6 -> V_7 = false ;
}
static inline struct V_1 * F_6 (
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 )
goto V_10;
if ( V_4 -> V_5 &&
( F_5 ( & V_4 -> V_9 ) == 0 ) )
V_4 = NULL ;
V_10:
return V_4 ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_11 * V_12 ;
struct V_13 * V_13 ;
int V_14 , V_15 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return - V_16 ;
V_12 = & V_4 -> V_17 ;
V_13 = & V_12 -> V_13 ;
memset ( V_12 , 0 , sizeof( struct V_11 ) ) ;
F_8 ( & V_12 -> F_4 ) ;
V_13 -> V_18 = V_19 ;
V_13 -> V_20 = V_21 ;
V_14 = F_9 ( V_3 -> V_22 , V_13 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_12 ,
V_23 ,
V_24 ) ;
if ( V_14 != 0 )
goto V_25;
V_15 = F_10 ( & V_12 -> F_4 , 5 * V_26 ) ;
if ( V_15 == 0 ) {
V_14 = - V_27 ;
goto V_25;
}
if ( V_13 -> V_18 != V_28 ||
V_13 -> V_29 != 0 )
goto V_25;
memset ( V_13 , 0 , sizeof( struct V_13 ) ) ;
V_13 -> V_18 = V_30 ;
V_13 -> V_20 = V_21 ;
V_13 -> V_31 . V_32 = V_33 ;
F_11 ( V_13 -> V_31 . V_34 ) ;
V_14 = F_9 ( V_3 -> V_22 , V_13 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_12 ,
V_23 ,
V_24 ) ;
if ( V_14 != 0 )
goto V_25;
V_15 = F_10 ( & V_12 -> F_4 , 5 * V_26 ) ;
if ( V_15 == 0 ) {
V_14 = - V_27 ;
goto V_25;
}
if ( V_13 -> V_18 != V_28 ||
V_13 -> V_29 != 0 )
goto V_25;
memset ( V_13 , 0 , sizeof( struct V_13 ) ) ;
V_13 -> V_18 = V_35 ;
V_13 -> V_20 = V_21 ;
V_13 -> V_36 . V_37 =
V_4 -> V_37 ;
V_14 = F_9 ( V_3 -> V_22 , V_13 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_12 ,
V_23 ,
V_24 ) ;
if ( V_14 != 0 )
goto V_25;
V_15 = F_10 ( & V_12 -> F_4 , 5 * V_26 ) ;
if ( V_15 == 0 ) {
V_14 = - V_27 ;
goto V_25;
}
if ( V_13 -> V_18 != V_28 ||
V_13 -> V_29 != 0 )
goto V_25;
V_4 -> V_38 = V_13 -> V_36 . V_38 ;
V_4 -> V_39
= V_13 -> V_36 . V_39 ;
memset ( V_13 , 0 , sizeof( struct V_13 ) ) ;
V_13 -> V_18 = V_40 ;
V_13 -> V_20 = V_21 ;
V_14 = F_9 ( V_3 -> V_22 , V_13 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_12 ,
V_23 ,
V_24 ) ;
if ( V_14 != 0 )
goto V_25;
V_15 = F_10 ( & V_12 -> F_4 , 5 * V_26 ) ;
if ( V_15 == 0 ) {
V_14 = - V_27 ;
goto V_25;
}
if ( V_13 -> V_18 != V_28 ||
V_13 -> V_29 != 0 )
goto V_25;
V_25:
return V_14 ;
}
static void F_12 ( struct V_2 * V_3 ,
struct V_13 * V_13 ,
struct V_11 * V_12 )
{
struct V_1 * V_4 ;
struct V_13 * V_41 ;
V_4 = F_2 ( V_3 ) ;
V_41 = & V_12 -> V_13 ;
if ( ( V_41 -> V_42 . V_43 [ 0 ] == V_44 ) ||
( V_41 -> V_42 . V_43 [ 0 ] == V_45 ) ) {
V_13 -> V_42 . V_46 = 0 ;
V_13 -> V_42 . V_47 = 0x1 ;
}
V_41 -> V_42 . V_46 = V_13 -> V_42 . V_46 ;
V_41 -> V_42 . V_47 = V_13 -> V_42 . V_47 ;
V_41 -> V_42 . V_48 =
V_13 -> V_42 . V_48 ;
if ( V_13 -> V_42 . V_46 != 0 ||
V_13 -> V_42 . V_47 != 1 ) {
F_13 ( & V_3 -> V_3 ,
L_1 ,
V_41 -> V_42 . V_43 [ 0 ] ,
V_13 -> V_42 . V_46 ,
V_13 -> V_42 . V_47 ) ;
}
if ( ( V_13 -> V_42 . V_46 & 0xFF ) == 0x02 ) {
if ( V_13 -> V_42 . V_47 & 0x80 ) {
F_13 ( & V_3 -> V_3 ,
L_2 ,
V_12 ,
V_13 -> V_42 . V_48 ) ;
memcpy ( V_12 -> V_49 ,
V_13 -> V_42 . V_50 ,
V_13 -> V_42 . V_48 ) ;
}
}
V_41 -> V_42 . V_51 =
V_13 -> V_42 . V_51 ;
V_12 -> V_52 ( V_12 ) ;
if ( F_14 ( & V_4 -> V_9 ) &&
V_4 -> V_7 )
F_15 ( & V_4 -> V_8 ) ;
}
static void F_16 ( struct V_2 * V_3 ,
struct V_13 * V_13 ,
struct V_11 * V_12 )
{
switch ( V_13 -> V_18 ) {
case V_28 :
F_12 ( V_3 , V_13 , V_12 ) ;
break;
case V_53 :
default:
break;
}
}
static void F_17 ( void * V_54 )
{
struct V_2 * V_3 = (struct V_2 * ) V_54 ;
struct V_1 * V_4 ;
T_1 V_55 ;
T_2 V_56 ;
unsigned char V_57 [ F_18 ( sizeof( struct V_13 ) , 8 ) ] ;
struct V_11 * V_12 ;
int V_14 ;
V_4 = F_6 ( V_3 ) ;
if ( ! V_4 )
return;
do {
V_14 = F_19 ( V_3 -> V_22 , V_57 ,
F_18 ( sizeof( struct V_13 ) , 8 ) ,
& V_55 , & V_56 ) ;
if ( V_14 == 0 && V_55 > 0 ) {
V_12 = (struct V_11 * )
( unsigned long ) V_56 ;
if ( ( V_12 == & V_4 -> V_17 ) ||
( V_12 == & V_4 -> V_58 ) ) {
memcpy ( & V_12 -> V_13 , V_57 ,
sizeof( struct V_13 ) ) ;
F_20 ( & V_12 -> F_4 ) ;
} else {
F_16 ( V_3 ,
(struct V_13 * ) V_57 ,
V_12 ) ;
}
} else {
break;
}
} while ( 1 );
return;
}
static int F_21 ( struct V_2 * V_3 , T_1 V_59 )
{
struct V_60 V_61 ;
int V_14 ;
memset ( & V_61 , 0 , sizeof( struct V_60 ) ) ;
V_14 = F_22 ( V_3 -> V_22 ,
V_59 ,
V_59 ,
( void * ) & V_61 ,
sizeof( struct V_60 ) ,
F_17 , V_3 ) ;
if ( V_14 != 0 )
return V_14 ;
V_14 = F_7 ( V_3 ) ;
return V_14 ;
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_20 ;
V_4 = F_2 ( V_3 ) ;
F_24 ( & V_3 -> V_22 -> V_62 , V_20 ) ;
V_4 -> V_5 = true ;
F_25 ( & V_3 -> V_22 -> V_62 , V_20 ) ;
F_3 ( V_4 ) ;
F_24 ( & V_3 -> V_22 -> V_62 , V_20 ) ;
F_26 ( V_3 , NULL ) ;
F_25 ( & V_3 -> V_22 -> V_62 , V_20 ) ;
F_27 ( V_3 -> V_22 ) ;
F_28 ( V_4 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 ,
struct V_11 * V_12 )
{
struct V_1 * V_4 ;
struct V_13 * V_13 ;
int V_14 = 0 ;
V_13 = & V_12 -> V_13 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return - V_16 ;
V_12 -> V_3 = V_3 ;
V_13 -> V_20 |= V_21 ;
V_13 -> V_42 . V_63 = sizeof( struct V_64 ) ;
V_13 -> V_42 . V_48 = V_65 ;
V_13 -> V_42 . V_51 =
V_12 -> V_66 . V_67 ;
V_13 -> V_18 = V_68 ;
if ( V_12 -> V_66 . V_67 ) {
V_14 = F_30 ( V_3 -> V_22 ,
& V_12 -> V_66 ,
V_13 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_12 ) ;
} else {
V_14 = F_9 ( V_3 -> V_22 , V_13 ,
sizeof( struct V_13 ) ,
( unsigned long ) V_12 ,
V_23 ,
V_24 ) ;
}
if ( V_14 != 0 )
return V_14 ;
F_31 ( & V_4 -> V_9 ) ;
return V_14 ;
}
static void F_32 ( struct V_2 * V_6 , int * V_69 , int * V_70 )
{
* V_69 =
V_6 -> V_71 . V_72 [ 5 ] << 8 | V_6 -> V_71 . V_72 [ 4 ] ;
* V_70 =
V_6 -> V_71 . V_72 [ 3 ] << 24 |
V_6 -> V_71 . V_72 [ 2 ] << 16 |
V_6 -> V_71 . V_72 [ 1 ] << 8 | V_6 -> V_71 . V_72 [ 0 ] ;
}
static int F_33 ( struct V_73 * V_74 )
{
V_74 -> V_75 |= V_76 | V_77 ;
return 0 ;
}
static int F_34 ( struct V_78 * V_79 ,
struct V_80 * V_81 , struct V_82 * V_83 )
{
return V_83 -> V_84 ;
}
static int F_35 ( struct V_73 * V_74 )
{
F_36 ( V_74 , V_85 ,
V_86 ) ;
F_37 ( V_74 -> V_78 , V_87 ) ;
F_38 ( V_74 -> V_78 , F_34 ) ;
F_39 ( V_74 -> V_78 , V_88 ) ;
return 0 ;
}
static void F_40 ( struct V_89 * V_90 ,
unsigned int V_91 )
{
int V_92 ;
struct V_93 * V_94 ;
for ( V_92 = 0 ; V_92 < V_91 ; V_92 ++ ) {
V_94 = F_41 ( ( & V_90 [ V_92 ] ) ) ;
if ( V_94 != NULL )
F_42 ( V_94 ) ;
}
F_28 ( V_90 ) ;
}
static int F_43 ( struct V_89 * V_90 , unsigned int V_91 )
{
int V_92 ;
if ( V_91 < 2 )
return - 1 ;
for ( V_92 = 0 ; V_92 < V_91 ; V_92 ++ ) {
if ( V_92 == 0 ) {
if ( V_90 [ V_92 ] . V_95 + V_90 [ V_92 ] . V_63 != V_87 )
return V_92 ;
} else if ( V_92 == V_91 - 1 ) {
if ( V_90 [ V_92 ] . V_95 != 0 )
return V_92 ;
} else {
if ( V_90 [ V_92 ] . V_63 != V_87 || V_90 [ V_92 ] . V_95 != 0 )
return V_92 ;
}
}
return - 1 ;
}
static struct V_89 * F_44 ( struct V_89 * V_90 ,
unsigned int V_91 ,
unsigned int V_67 )
{
int V_92 ;
int V_96 ;
struct V_89 * V_97 ;
struct V_93 * V_94 ;
V_96 = F_18 ( V_67 , V_87 ) >> V_98 ;
V_97 = F_45 ( V_96 , sizeof( struct V_89 ) , V_99 ) ;
if ( ! V_97 )
return NULL ;
for ( V_92 = 0 ; V_92 < V_96 ; V_92 ++ ) {
V_94 = F_46 ( V_99 ) ;
if ( ! V_94 )
goto V_25;
F_47 ( & V_97 [ V_92 ] , V_94 , 0 , 0 ) ;
}
return V_97 ;
V_25:
F_40 ( V_97 , V_96 ) ;
return NULL ;
}
static unsigned int F_48 ( struct V_89 * V_100 ,
struct V_89 * V_97 ,
unsigned int V_101 )
{
int V_92 ;
int V_102 = 0 ;
unsigned long V_103 , V_104 ;
unsigned int V_105 , V_106 , V_107 ;
unsigned int V_108 = 0 ;
unsigned long V_109 = 0 ;
unsigned long V_110 = 0 ;
unsigned long V_20 ;
F_49 ( V_20 ) ;
for ( V_92 = 0 ; V_92 < V_101 ; V_92 ++ ) {
V_110 = ( unsigned long ) F_50 ( F_41 ( ( & V_100 [ V_92 ] ) ) ,
V_111 ) + V_100 [ V_92 ] . V_95 ;
V_104 = V_110 ;
V_106 = V_100 [ V_92 ] . V_63 ;
if ( V_109 == 0 )
V_109 =
( unsigned long ) F_50 ( F_41 ( ( & V_97 [ V_102 ] ) ) ,
V_111 ) ;
while ( V_106 ) {
V_103 = V_109 + V_97 [ V_102 ] . V_95 ;
V_105 = V_97 [ V_102 ] . V_63 - V_97 [ V_102 ] . V_95 ;
V_107 = F_51 ( V_105 , V_106 ) ;
memcpy ( ( void * ) V_104 , ( void * ) V_103 , V_107 ) ;
V_108 += V_107 ;
V_97 [ V_102 ] . V_95 += V_107 ;
V_106 -= V_107 ;
V_104 += V_107 ;
if ( V_97 [ V_102 ] . V_95 == V_97 [ V_102 ] . V_63 ) {
F_52 ( ( void * ) V_109 , V_111 ) ;
V_102 ++ ;
if ( V_106 || V_92 != V_101 - 1 )
V_109 =
( unsigned long ) F_50 (
F_41 ( ( & V_97 [ V_102 ] ) ) , V_111 ) ;
} else if ( V_106 == 0 && V_92 == V_101 - 1 ) {
F_52 ( ( void * ) V_109 , V_111 ) ;
}
}
F_52 ( ( void * ) ( V_110 - V_100 [ V_92 ] . V_95 ) ,
V_111 ) ;
}
F_53 ( V_20 ) ;
return V_108 ;
}
static unsigned int F_54 ( struct V_89 * V_100 ,
struct V_89 * V_97 ,
unsigned int V_101 )
{
int V_92 ;
int V_102 = 0 ;
unsigned long V_103 , V_104 ;
unsigned int V_105 , V_106 , V_107 ;
unsigned int V_108 = 0 ;
unsigned long V_109 = 0 ;
unsigned long V_112 = 0 ;
unsigned long V_20 ;
F_49 ( V_20 ) ;
for ( V_92 = 0 ; V_92 < V_101 ; V_92 ++ ) {
V_112 = ( unsigned long ) F_50 ( F_41 ( ( & V_100 [ V_92 ] ) ) ,
V_111 ) + V_100 [ V_92 ] . V_95 ;
V_103 = V_112 ;
V_105 = V_100 [ V_92 ] . V_63 ;
if ( V_109 == 0 )
V_109 =
( unsigned long ) F_50 ( F_41 ( ( & V_97 [ V_102 ] ) ) ,
V_111 ) ;
while ( V_105 ) {
V_104 = V_109 + V_97 [ V_102 ] . V_63 ;
V_106 = V_87 - V_97 [ V_102 ] . V_63 ;
V_107 = F_51 ( V_105 , V_106 ) ;
memcpy ( ( void * ) V_104 , ( void * ) V_103 , V_107 ) ;
V_108 += V_107 ;
V_97 [ V_102 ] . V_63 += V_107 ;
V_105 -= V_107 ;
V_103 += V_107 ;
if ( V_97 [ V_102 ] . V_63 == V_87 ) {
F_52 ( ( void * ) V_109 , V_111 ) ;
V_102 ++ ;
if ( V_105 || V_92 != V_101 - 1 )
V_109 =
( unsigned long ) F_50 (
F_41 ( ( & V_97 [ V_102 ] ) ) , V_111 ) ;
} else if ( V_105 == 0 && V_92 == V_101 - 1 ) {
F_52 ( ( void * ) V_109 , V_111 ) ;
}
}
F_52 ( ( void * ) ( V_112 - V_100 [ V_92 ] . V_95 ) , V_111 ) ;
}
F_53 ( V_20 ) ;
return V_108 ;
}
static int F_55 ( struct V_2 * V_6 )
{
struct V_1 * V_4 = F_2 ( V_6 ) ;
struct V_113 * V_114 = V_4 -> V_114 ;
struct V_115 * V_116 =
(struct V_115 * ) V_114 -> V_117 ;
F_56 ( V_114 ) ;
F_57 ( V_114 ) ;
F_23 ( V_6 ) ;
if ( V_116 -> V_118 ) {
F_58 ( V_116 -> V_118 ) ;
V_116 -> V_118 = NULL ;
}
return 0 ;
}
static int F_59 ( struct V_73 * V_119 , struct V_120 * V_121 ,
T_3 V_122 , int * V_123 )
{
T_3 V_124 = V_122 ;
T_3 V_125 = V_124 ;
int V_126 , V_127 ;
V_126 = 0xff ;
V_127 = 0x3f ;
F_60 ( V_125 , V_126 * V_127 ) ;
if ( ( T_3 ) ( V_125 + 1 ) * V_126 * V_127 < V_124 )
V_125 = 0xffff ;
V_123 [ 0 ] = V_126 ;
V_123 [ 1 ] = V_127 ;
V_123 [ 2 ] = ( int ) V_125 ;
return 0 ;
}
static int F_61 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_11 * V_12 ;
struct V_13 * V_13 ;
int V_14 , V_15 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return - V_16 ;
V_12 = & V_4 -> V_58 ;
V_13 = & V_12 -> V_13 ;
F_8 ( & V_12 -> F_4 ) ;
V_13 -> V_18 = V_128 ;
V_13 -> V_20 = V_21 ;
V_13 -> V_42 . V_38 = V_4 -> V_38 ;
V_14 = F_9 ( V_3 -> V_22 , V_13 ,
sizeof( struct V_13 ) ,
( unsigned long ) & V_4 -> V_58 ,
V_23 ,
V_24 ) ;
if ( V_14 != 0 )
goto V_25;
V_15 = F_10 ( & V_12 -> F_4 , 5 * V_26 ) ;
if ( V_15 == 0 ) {
V_14 = - V_27 ;
goto V_25;
}
V_25:
return V_14 ;
}
static int F_62 ( struct V_129 * V_130 )
{
int V_14 ;
struct V_115 * V_116 =
(struct V_115 * ) V_130 -> V_3 -> V_114 -> V_117 ;
struct V_2 * V_6 = V_116 -> V_6 ;
V_14 = F_61 ( V_6 ) ;
if ( V_14 != 0 )
return V_14 ;
return V_14 ;
}
static void F_63 ( struct V_11 * V_12 )
{
struct V_131 * V_132 =
(struct V_131 * ) V_12 -> V_54 ;
struct V_129 * V_130 = V_132 -> V_133 ;
struct V_115 * V_116 =
(struct V_115 * ) V_130 -> V_3 -> V_114 -> V_117 ;
void (* F_64)( struct V_129 * );
struct V_134 V_135 ;
struct V_64 * V_42 ;
V_42 = & V_12 -> V_13 . V_42 ;
if ( V_132 -> V_136 ) {
if ( V_42 -> V_137 == V_138 ) {
F_48 ( F_65 ( V_130 ) ,
V_132 -> V_97 ,
F_66 ( V_130 ) ) ;
F_40 ( V_132 -> V_97 ,
V_132 -> V_136 ) ;
}
}
if ( V_42 -> V_47 == 0x4 )
V_130 -> V_139 = V_140 << 16 ;
else
V_130 -> V_139 = V_42 -> V_46 ;
if ( V_130 -> V_139 ) {
if ( F_67 ( V_130 -> V_49 ,
V_141 , & V_135 ) )
F_68 ( L_3 , & V_135 ) ;
}
F_69 ( V_130 ,
V_12 -> V_66 . V_67 -
V_42 -> V_51 ) ;
F_64 = V_130 -> V_142 ;
V_130 -> V_143 = NULL ;
V_130 -> V_142 = NULL ;
F_64 ( V_130 ) ;
F_70 ( V_116 -> V_118 , V_132 ) ;
}
static bool F_71 ( struct V_129 * V_130 )
{
bool V_144 = true ;
T_4 V_145 = V_130 -> V_146 [ 0 ] ;
switch ( V_145 ) {
case V_147 :
V_130 -> V_139 = V_148 << 16 ;
V_144 = false ;
break;
default:
break;
}
return V_144 ;
}
static int F_72 ( struct V_129 * V_130 ,
void (* F_73)( struct V_129 * ) )
{
int V_14 ;
struct V_115 * V_116 =
(struct V_115 * ) V_130 -> V_3 -> V_114 -> V_117 ;
struct V_2 * V_6 = V_116 -> V_6 ;
struct V_11 * V_12 ;
struct V_131 * V_132 ;
unsigned int V_149 = 0 ;
int V_92 ;
struct V_89 * V_90 ;
unsigned int V_91 = 0 ;
struct V_64 * V_42 ;
if ( F_71 ( V_130 ) == false ) {
F_73 ( V_130 ) ;
return 0 ;
}
if ( V_130 -> V_143 ) {
V_132 =
(struct V_131 * ) V_130 -> V_143 ;
goto V_150;
}
V_130 -> V_142 = F_73 ;
V_149 = sizeof( struct V_131 ) ;
V_132 = F_74 ( V_116 -> V_118 ,
V_99 ) ;
if ( ! V_132 ) {
V_130 -> V_142 = NULL ;
return V_151 ;
}
V_132 -> V_136 = 0 ;
V_132 -> V_97 = NULL ;
V_132 -> V_133 = V_130 ;
V_130 -> V_143 = ( unsigned char * ) V_132 ;
V_12 = & V_132 -> V_12 ;
V_42 = & V_12 -> V_13 . V_42 ;
switch ( V_130 -> V_152 ) {
case V_153 :
V_42 -> V_137 = V_154 ;
break;
case V_155 :
V_42 -> V_137 = V_138 ;
break;
default:
V_42 -> V_137 = V_156 ;
break;
}
V_12 -> V_52 = F_63 ;
V_12 -> V_54 = V_132 ;
V_42 -> V_37 = V_116 -> V_157 ;
V_42 -> V_38 = V_130 -> V_3 -> V_22 ;
V_42 -> V_39 = V_130 -> V_3 -> V_158 ;
V_42 -> V_159 = V_130 -> V_3 -> V_159 ;
V_42 -> V_160 = V_130 -> V_161 ;
memcpy ( V_42 -> V_43 , V_130 -> V_146 , V_42 -> V_160 ) ;
V_12 -> V_49 = V_130 -> V_49 ;
V_12 -> V_66 . V_67 = F_75 ( V_130 ) ;
if ( F_66 ( V_130 ) ) {
V_90 = (struct V_89 * ) F_65 ( V_130 ) ;
V_91 = F_66 ( V_130 ) ;
if ( F_43 ( V_90 , F_66 ( V_130 ) ) != - 1 ) {
V_132 -> V_97 =
F_44 ( V_90 , F_66 ( V_130 ) ,
F_75 ( V_130 ) ) ;
if ( ! V_132 -> V_97 ) {
V_130 -> V_142 = NULL ;
V_130 -> V_143 = NULL ;
F_70 ( V_116 -> V_118 ,
V_132 ) ;
return V_162 ;
}
V_132 -> V_136 =
F_18 ( F_75 ( V_130 ) , V_87 ) >>
V_98 ;
if ( V_42 -> V_137 == V_154 )
F_54 ( V_90 ,
V_132 -> V_97 ,
F_66 ( V_130 ) ) ;
V_90 = V_132 -> V_97 ;
V_91 = V_132 -> V_136 ;
}
V_12 -> V_66 . V_95 = V_90 [ 0 ] . V_95 ;
for ( V_92 = 0 ; V_92 < V_91 ; V_92 ++ )
V_12 -> V_66 . V_163 [ V_92 ] =
F_76 ( F_41 ( ( & V_90 [ V_92 ] ) ) ) ;
} else if ( F_65 ( V_130 ) ) {
V_12 -> V_66 . V_95 =
F_77 ( F_65 ( V_130 ) ) & ( V_87 - 1 ) ;
V_12 -> V_66 . V_163 [ 0 ] =
F_77 ( F_65 ( V_130 ) ) >> V_98 ;
}
V_150:
V_14 = F_29 ( V_6 , & V_132 -> V_12 ) ;
if ( V_14 == - V_164 ) {
if ( V_132 -> V_136 )
F_40 ( V_132 -> V_97 ,
V_132 -> V_136 ) ;
F_70 ( V_116 -> V_118 , V_132 ) ;
V_130 -> V_142 = NULL ;
V_130 -> V_143 = NULL ;
V_14 = V_151 ;
}
return V_14 ;
}
static int F_78 ( struct V_2 * V_3 ,
const struct V_165 * V_166 )
{
int V_14 ;
struct V_113 * V_114 ;
struct V_115 * V_116 ;
bool V_167 = ( ( V_166 -> V_168 == V_169 ) ? true : false ) ;
int V_70 = 0 ;
int V_69 = 0 ;
struct V_1 * V_4 ;
V_114 = F_79 ( & V_170 ,
sizeof( struct V_115 ) ) ;
if ( ! V_114 )
return - V_171 ;
V_116 = (struct V_115 * ) V_114 -> V_117 ;
memset ( V_116 , 0 , sizeof( struct V_115 ) ) ;
V_116 -> V_157 = V_114 -> V_172 ;
V_116 -> V_6 = V_3 ;
V_116 -> V_118 =
F_80 ( F_81 ( & V_3 -> V_3 ) ,
sizeof( struct V_131 ) , 0 ,
V_173 , NULL ) ;
if ( ! V_116 -> V_118 ) {
F_57 ( V_114 ) ;
return - V_171 ;
}
V_4 = F_82 ( sizeof( struct V_1 ) , V_174 ) ;
if ( ! V_4 ) {
F_58 ( V_116 -> V_118 ) ;
F_57 ( V_114 ) ;
return - V_171 ;
}
V_4 -> V_5 = false ;
F_83 ( & V_4 -> V_8 ) ;
V_4 -> V_3 = V_3 ;
V_4 -> V_114 = V_114 ;
F_26 ( V_3 , V_4 ) ;
V_4 -> V_37 = V_114 -> V_172 ;
V_14 = F_21 ( V_3 , V_175 ) ;
if ( V_14 ) {
F_58 ( V_116 -> V_118 ) ;
F_57 ( V_114 ) ;
F_28 ( V_4 ) ;
return V_14 ;
}
if ( V_167 )
F_32 ( V_3 , & V_69 , & V_70 ) ;
V_116 -> V_70 = V_4 -> V_38 ;
V_116 -> V_69 = V_4 -> V_39 ;
V_114 -> V_176 = V_177 ;
V_114 -> V_178 = V_179 ;
V_114 -> V_180 = V_181 - 1 ;
V_114 -> V_182 = V_183 ;
V_14 = F_84 ( V_114 , & V_3 -> V_3 ) ;
if ( V_14 != 0 )
goto V_184;
if ( ! V_167 ) {
F_85 ( V_114 ) ;
return 0 ;
}
V_14 = F_86 ( V_114 , 0 , V_69 , 0 ) ;
if ( V_14 ) {
F_56 ( V_114 ) ;
goto V_184;
}
return 0 ;
V_184:
F_23 ( V_3 ) ;
F_58 ( V_116 -> V_118 ) ;
F_57 ( V_114 ) ;
return - V_16 ;
}
static int T_5 F_87 ( void )
{
T_1 V_185 ;
V_185 =
( ( V_175 - V_87 ) /
F_18 ( V_186 +
sizeof( struct V_13 ) + sizeof( T_2 ) ,
sizeof( T_2 ) ) ) ;
if ( V_185 <
V_86 )
return - V_187 ;
return F_88 ( & V_188 ) ;
}
static void T_6 F_89 ( void )
{
F_90 ( & V_188 ) ;
}

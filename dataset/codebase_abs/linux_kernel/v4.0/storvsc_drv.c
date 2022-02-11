static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 ;
struct V_6 * V_7 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
V_5 = V_4 -> V_5 ;
V_7 = F_3 ( V_4 -> V_8 , 0 , 0 , V_5 ) ;
if ( ! V_7 )
goto V_9;
F_4 ( & V_7 -> V_10 ) ;
F_5 ( V_7 ) ;
V_9:
F_6 ( V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_11 * V_8 ;
struct V_6 * V_7 ;
unsigned long V_12 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
V_8 = V_4 -> V_8 ;
F_8 ( & V_8 -> V_13 ) ;
F_9 ( V_8 -> V_14 , V_12 ) ;
F_10 (sdev, &host->__devices, siblings) {
F_11 ( V_8 -> V_14 , V_12 ) ;
F_12 ( V_7 , 1 , 1 , NULL ) ;
F_9 ( V_8 -> V_14 , V_12 ) ;
continue;
}
F_11 ( V_8 -> V_14 , V_12 ) ;
F_13 ( & V_8 -> V_13 ) ;
F_14 ( V_8 ) ;
F_6 ( V_4 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_6 * V_7 ;
V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
if ( ! F_16 ( V_4 -> V_8 ) )
goto V_9;
V_7 = F_3 ( V_4 -> V_8 , 0 , 0 , V_4 -> V_5 ) ;
if ( V_7 ) {
F_17 ( V_7 ) ;
F_5 ( V_7 ) ;
}
F_18 ( V_4 -> V_8 ) ;
V_9:
F_6 ( V_4 ) ;
}
static inline T_2 F_19 ( T_3 V_15 , T_3 V_16 )
{
T_2 V_17 ;
V_17 = ( ( V_15 << 8 ) | V_16 ) ;
return V_17 ;
}
static inline struct V_18 * F_20 (
struct V_19 * V_20 )
{
struct V_18 * V_21 ;
V_21 = F_21 ( V_20 ) ;
if ( V_21 && V_21 -> V_22 )
V_21 = NULL ;
return V_21 ;
}
static inline void F_22 ( struct V_18 * V_23 )
{
V_23 -> V_24 = true ;
F_23 ( V_23 -> V_25 ,
F_24 ( & V_23 -> V_26 ) == 0 ) ;
V_23 -> V_24 = false ;
}
static inline struct V_18 * F_25 (
struct V_19 * V_20 )
{
struct V_18 * V_21 ;
V_21 = F_21 ( V_20 ) ;
if ( ! V_21 )
goto V_27;
if ( V_21 -> V_22 &&
( F_24 ( & V_21 -> V_26 ) == 0 ) )
V_21 = NULL ;
V_27:
return V_21 ;
}
static void F_26 ( struct V_28 * V_29 ,
unsigned int V_30 )
{
int V_31 ;
struct V_32 * V_33 ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ ) {
V_33 = F_27 ( ( & V_29 [ V_31 ] ) ) ;
if ( V_33 != NULL )
F_28 ( V_33 ) ;
}
F_6 ( V_29 ) ;
}
static int F_29 ( struct V_28 * V_29 , unsigned int V_30 )
{
int V_31 ;
if ( V_30 < 2 )
return - 1 ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ ) {
if ( V_31 == 0 ) {
if ( V_29 [ V_31 ] . V_34 + V_29 [ V_31 ] . V_35 != V_36 )
return V_31 ;
} else if ( V_31 == V_30 - 1 ) {
if ( V_29 [ V_31 ] . V_34 != 0 )
return V_31 ;
} else {
if ( V_29 [ V_31 ] . V_35 != V_36 || V_29 [ V_31 ] . V_34 != 0 )
return V_31 ;
}
}
return - 1 ;
}
static struct V_28 * F_30 ( struct V_28 * V_29 ,
unsigned int V_30 ,
unsigned int V_37 ,
int V_38 )
{
int V_31 ;
int V_39 ;
struct V_28 * V_40 ;
struct V_32 * V_33 ;
unsigned int V_41 = ( ( V_38 == V_42 ) ? 0 : V_36 ) ;
V_39 = F_31 ( V_37 , V_36 ) >> V_43 ;
V_40 = F_32 ( V_39 , sizeof( struct V_28 ) , V_44 ) ;
if ( ! V_40 )
return NULL ;
F_33 ( V_40 , V_39 ) ;
for ( V_31 = 0 ; V_31 < V_39 ; V_31 ++ ) {
V_33 = F_34 ( V_44 ) ;
if ( ! V_33 )
goto V_45;
F_35 ( & V_40 [ V_31 ] , V_33 , V_41 , 0 ) ;
}
return V_40 ;
V_45:
F_26 ( V_40 , V_39 ) ;
return NULL ;
}
static inline unsigned long F_36 ( struct V_28 * V_29 , int V_46 )
{
void * V_47 = F_37 ( F_27 ( V_29 + V_46 ) ) ;
return ( unsigned long ) V_47 ;
}
static inline void F_38 ( unsigned long V_47 )
{
F_39 ( ( void * ) V_47 ) ;
}
static unsigned int F_40 ( struct V_28 * V_48 ,
struct V_28 * V_40 ,
unsigned int V_49 ,
unsigned int V_50 )
{
int V_31 ;
int V_51 = 0 ;
unsigned long V_52 , V_53 ;
unsigned int V_54 , V_55 , V_56 ;
unsigned int V_57 = 0 ;
unsigned long V_58 = 0 ;
unsigned long V_59 = 0 ;
unsigned long V_12 ;
F_41 ( V_12 ) ;
for ( V_31 = 0 ; V_31 < V_49 ; V_31 ++ ) {
V_59 = F_36 ( V_48 , V_31 ) + V_48 [ V_31 ] . V_34 ;
V_53 = V_59 ;
V_55 = V_48 [ V_31 ] . V_35 ;
if ( V_58 == 0 )
V_58 = F_36 ( V_40 , V_51 ) ;
while ( V_55 ) {
V_52 = V_58 + V_40 [ V_51 ] . V_34 ;
V_54 = V_40 [ V_51 ] . V_35 - V_40 [ V_51 ] . V_34 ;
V_56 = F_42 ( V_54 , V_55 ) ;
memcpy ( ( void * ) V_53 , ( void * ) V_52 , V_56 ) ;
V_57 += V_56 ;
V_40 [ V_51 ] . V_34 += V_56 ;
V_55 -= V_56 ;
V_53 += V_56 ;
if ( V_40 [ V_51 ] . V_34 == V_40 [ V_51 ] . V_35 ) {
F_38 ( V_58 ) ;
V_51 ++ ;
if ( V_51 == V_50 ) {
F_38 ( V_59 - V_48 [ V_31 ] . V_34 ) ;
F_43 ( V_12 ) ;
return V_57 ;
}
if ( V_55 || V_31 != V_49 - 1 )
V_58 = F_36 ( V_40 , V_51 ) ;
} else if ( V_55 == 0 && V_31 == V_49 - 1 ) {
F_38 ( V_58 ) ;
}
}
F_38 ( V_59 - V_48 [ V_31 ] . V_34 ) ;
}
F_43 ( V_12 ) ;
return V_57 ;
}
static unsigned int F_44 ( struct V_28 * V_48 ,
struct V_28 * V_40 ,
unsigned int V_49 )
{
int V_31 ;
int V_51 = 0 ;
unsigned long V_52 , V_53 ;
unsigned int V_54 , V_55 , V_56 ;
unsigned int V_57 = 0 ;
unsigned long V_58 = 0 ;
unsigned long V_60 = 0 ;
unsigned long V_12 ;
F_41 ( V_12 ) ;
for ( V_31 = 0 ; V_31 < V_49 ; V_31 ++ ) {
V_60 = F_36 ( V_48 , V_31 ) + V_48 [ V_31 ] . V_34 ;
V_52 = V_60 ;
V_54 = V_48 [ V_31 ] . V_35 ;
if ( V_58 == 0 )
V_58 = F_36 ( V_40 , V_51 ) ;
while ( V_54 ) {
V_53 = V_58 + V_40 [ V_51 ] . V_35 ;
V_55 = V_36 - V_40 [ V_51 ] . V_35 ;
V_56 = F_42 ( V_54 , V_55 ) ;
memcpy ( ( void * ) V_53 , ( void * ) V_52 , V_56 ) ;
V_57 += V_56 ;
V_40 [ V_51 ] . V_35 += V_56 ;
V_54 -= V_56 ;
V_52 += V_56 ;
if ( V_40 [ V_51 ] . V_35 == V_36 ) {
F_38 ( V_58 ) ;
V_51 ++ ;
if ( V_54 || V_31 != V_49 - 1 )
V_58 = F_36 ( V_40 , V_51 ) ;
} else if ( V_54 == 0 && V_31 == V_49 - 1 ) {
F_38 ( V_58 ) ;
}
}
F_38 ( V_60 - V_48 [ V_31 ] . V_34 ) ;
}
F_43 ( V_12 ) ;
return V_57 ;
}
static void F_45 ( struct V_61 * V_62 )
{
struct V_19 * V_20 = V_62 -> V_63 -> V_64 ;
struct V_18 * V_21 ;
struct V_65 V_66 ;
V_21 = F_20 ( V_20 ) ;
if ( ! V_21 )
return;
if ( V_21 -> V_67 == false )
return;
memset ( & V_66 , 0 , sizeof( struct V_65 ) ) ;
F_46 ( V_62 ,
V_68 ,
V_68 ,
( void * ) & V_66 ,
sizeof( struct V_65 ) ,
V_69 , V_62 ) ;
}
static void F_47 ( struct V_19 * V_20 , int V_70 )
{
struct V_18 * V_21 ;
int V_71 = F_48 () ;
int V_72 ;
struct V_73 * V_74 ;
struct V_75 * V_75 ;
int V_76 , V_77 ;
V_72 = ( ( V_70 > V_71 ) ? V_71 : V_70 ) ;
V_21 = F_20 ( V_20 ) ;
if ( ! V_21 )
return;
V_74 = & V_21 -> V_78 ;
V_75 = & V_74 -> V_75 ;
V_21 -> V_67 = true ;
F_49 ( V_20 -> V_79 , F_45 ) ;
if ( F_50 ( V_20 -> V_79 ) )
return;
V_21 -> V_67 = false ;
memset ( V_74 , 0 , sizeof( struct V_73 ) ) ;
F_51 ( & V_74 -> F_23 ) ;
V_75 -> V_80 = V_81 ;
V_75 -> V_12 = V_82 ;
V_75 -> V_83 = V_72 ;
V_76 = F_52 ( V_20 -> V_79 , V_75 ,
( sizeof( struct V_75 ) -
V_84 ) ,
( unsigned long ) V_74 ,
V_85 ,
V_86 ) ;
if ( V_76 != 0 )
return;
V_77 = F_53 ( & V_74 -> F_23 , 10 * V_87 ) ;
if ( V_77 == 0 )
return;
if ( V_75 -> V_80 != V_88 ||
V_75 -> V_89 != 0 )
return;
V_21 -> V_67 = true ;
F_50 ( V_20 -> V_79 ) ;
}
static int F_54 ( struct V_19 * V_20 )
{
struct V_18 * V_21 ;
struct V_73 * V_74 ;
struct V_75 * V_75 ;
int V_76 , V_77 ;
int V_70 ;
bool V_90 = false ;
V_21 = F_20 ( V_20 ) ;
if ( ! V_21 )
return - V_91 ;
V_74 = & V_21 -> V_78 ;
V_75 = & V_74 -> V_75 ;
memset ( V_74 , 0 , sizeof( struct V_73 ) ) ;
F_51 ( & V_74 -> F_23 ) ;
V_75 -> V_80 = V_92 ;
V_75 -> V_12 = V_82 ;
V_76 = F_52 ( V_20 -> V_79 , V_75 ,
( sizeof( struct V_75 ) -
V_84 ) ,
( unsigned long ) V_74 ,
V_85 ,
V_86 ) ;
if ( V_76 != 0 )
goto V_45;
V_77 = F_53 ( & V_74 -> F_23 , 5 * V_87 ) ;
if ( V_77 == 0 ) {
V_76 = - V_93 ;
goto V_45;
}
if ( V_75 -> V_80 != V_88 ||
V_75 -> V_89 != 0 )
goto V_45;
memset ( V_75 , 0 , sizeof( struct V_75 ) ) ;
V_75 -> V_80 = V_94 ;
V_75 -> V_12 = V_82 ;
V_75 -> V_17 . V_95 =
F_19 ( V_96 , V_97 ) ;
V_75 -> V_17 . V_98 = 0 ;
V_76 = F_52 ( V_20 -> V_79 , V_75 ,
( sizeof( struct V_75 ) -
V_84 ) ,
( unsigned long ) V_74 ,
V_85 ,
V_86 ) ;
if ( V_76 != 0 )
goto V_45;
V_77 = F_53 ( & V_74 -> F_23 , 5 * V_87 ) ;
if ( V_77 == 0 ) {
V_76 = - V_93 ;
goto V_45;
}
if ( V_75 -> V_80 != V_88 ||
V_75 -> V_89 != 0 )
goto V_45;
memset ( V_75 , 0 , sizeof( struct V_75 ) ) ;
V_75 -> V_80 = V_99 ;
V_75 -> V_12 = V_82 ;
V_76 = F_52 ( V_20 -> V_79 , V_75 ,
( sizeof( struct V_75 ) -
V_84 ) ,
( unsigned long ) V_74 ,
V_85 ,
V_86 ) ;
if ( V_76 != 0 )
goto V_45;
V_77 = F_53 ( & V_74 -> F_23 , 5 * V_87 ) ;
if ( V_77 == 0 ) {
V_76 = - V_93 ;
goto V_45;
}
if ( V_75 -> V_80 != V_88 ||
V_75 -> V_89 != 0 )
goto V_45;
V_70 = V_75 -> V_100 . V_101 ;
if ( ( V_102 != V_103 ) &&
( V_102 != V_104 ) ) {
if ( V_75 -> V_100 . V_12 &
V_105 )
V_90 = true ;
}
memset ( V_75 , 0 , sizeof( struct V_75 ) ) ;
V_75 -> V_80 = V_106 ;
V_75 -> V_12 = V_82 ;
V_76 = F_52 ( V_20 -> V_79 , V_75 ,
( sizeof( struct V_75 ) -
V_84 ) ,
( unsigned long ) V_74 ,
V_85 ,
V_86 ) ;
if ( V_76 != 0 )
goto V_45;
V_77 = F_53 ( & V_74 -> F_23 , 5 * V_87 ) ;
if ( V_77 == 0 ) {
V_76 = - V_93 ;
goto V_45;
}
if ( V_75 -> V_80 != V_88 ||
V_75 -> V_89 != 0 )
goto V_45;
if ( V_90 )
F_47 ( V_20 , V_70 ) ;
V_45:
return V_76 ;
}
static void F_55 ( struct V_107 * V_108 ,
struct V_109 * V_110 ,
struct V_11 * V_8 ,
T_3 V_111 , T_3 V_112 )
{
struct V_3 * V_4 ;
void (* F_56)( struct V_1 * V_2 );
bool V_113 = false ;
switch ( V_108 -> V_114 ) {
case V_115 :
switch ( V_110 -> V_116 [ 0 ] ) {
case V_117 :
case V_118 :
F_57 ( V_110 , V_119 ) ;
break;
case V_120 :
break;
default:
F_57 ( V_110 , V_121 ) ;
}
break;
case V_122 :
V_113 = true ;
F_56 = F_15 ;
break;
case ( V_123 | V_124 ) :
if ( ( V_111 == 0x2a ) && ( V_112 == 0x9 ) ) {
V_113 = true ;
F_56 = F_1 ;
F_57 ( V_110 , V_125 ) ;
}
break;
}
if ( ! V_113 )
return;
V_4 = F_58 ( sizeof( struct V_3 ) , V_44 ) ;
if ( ! V_4 ) {
F_57 ( V_110 , V_121 ) ;
return;
}
V_4 -> V_8 = V_8 ;
V_4 -> V_5 = V_108 -> V_5 ;
F_59 ( & V_4 -> V_2 , F_56 ) ;
F_60 ( & V_4 -> V_2 ) ;
}
static void F_61 ( struct V_73 * V_126 )
{
struct V_109 * V_110 = V_126 -> V_127 ;
struct V_128 * V_129 = F_62 ( V_110 -> V_20 -> V_8 ) ;
struct V_130 V_131 ;
struct V_107 * V_108 ;
struct V_11 * V_8 ;
struct V_18 * V_132 ;
struct V_19 * V_23 = V_129 -> V_23 ;
V_132 = F_25 ( V_23 ) ;
V_8 = V_132 -> V_8 ;
V_108 = & V_126 -> V_75 . V_108 ;
if ( V_126 -> V_50 ) {
if ( V_108 -> V_133 == V_134 )
F_40 ( F_63 ( V_110 ) ,
V_126 -> V_40 ,
F_64 ( V_110 ) ,
V_126 -> V_50 ) ;
F_26 ( V_126 -> V_40 ,
V_126 -> V_50 ) ;
}
V_110 -> V_135 = V_108 -> V_136 ;
if ( V_110 -> V_135 ) {
if ( F_65 ( V_110 -> V_137 ,
V_138 , & V_131 ) )
F_66 ( V_110 -> V_20 , L_1 ,
& V_131 ) ;
}
if ( V_108 -> V_114 != V_139 )
F_55 ( V_108 , V_110 , V_8 , V_131 . V_111 ,
V_131 . V_112 ) ;
F_67 ( V_110 ,
V_126 -> V_140 . V_37 -
V_108 -> V_141 ) ;
V_110 -> V_142 ( V_110 ) ;
}
static void F_68 ( struct V_19 * V_20 ,
struct V_75 * V_75 ,
struct V_73 * V_74 )
{
struct V_18 * V_21 ;
struct V_75 * V_143 ;
V_21 = F_21 ( V_20 ) ;
V_143 = & V_74 -> V_75 ;
if ( ( V_143 -> V_108 . V_144 [ 0 ] == V_145 ) ||
( V_143 -> V_108 . V_144 [ 0 ] == V_146 ) ) {
V_75 -> V_108 . V_136 = 0 ;
V_75 -> V_108 . V_114 = V_139 ;
}
V_143 -> V_108 . V_136 = V_75 -> V_108 . V_136 ;
V_143 -> V_108 . V_114 = V_75 -> V_108 . V_114 ;
V_143 -> V_108 . V_147 =
V_75 -> V_108 . V_147 ;
if ( ( V_75 -> V_108 . V_136 & 0xFF ) == 0x02 ) {
if ( V_75 -> V_108 . V_114 &
V_124 ) {
memcpy ( V_74 -> V_127 -> V_137 ,
V_75 -> V_108 . V_148 ,
V_75 -> V_108 . V_147 ) ;
}
}
V_143 -> V_108 . V_141 =
V_75 -> V_108 . V_141 ;
F_61 ( V_74 ) ;
if ( F_69 ( & V_21 -> V_26 ) &&
V_21 -> V_24 )
F_70 ( & V_21 -> V_25 ) ;
}
static void F_71 ( struct V_19 * V_20 ,
struct V_75 * V_75 ,
struct V_73 * V_74 )
{
struct V_3 * V_2 ;
struct V_18 * V_21 ;
switch ( V_75 -> V_80 ) {
case V_88 :
F_68 ( V_20 , V_75 , V_74 ) ;
break;
case V_149 :
case V_150 :
V_21 = F_25 ( V_20 ) ;
V_2 = F_58 ( sizeof( struct V_3 ) , V_44 ) ;
if ( ! V_2 )
return;
F_59 ( & V_2 -> V_2 , F_7 ) ;
V_2 -> V_8 = V_21 -> V_8 ;
F_60 ( & V_2 -> V_2 ) ;
break;
default:
break;
}
}
static void V_69 ( void * V_151 )
{
struct V_61 * V_79 = (struct V_61 * ) V_151 ;
struct V_19 * V_20 ;
struct V_18 * V_21 ;
T_4 V_152 ;
T_5 V_153 ;
unsigned char V_154 [ F_31 ( sizeof( struct V_75 ) , 8 ) ] ;
struct V_73 * V_74 ;
int V_76 ;
if ( V_79 -> V_63 != NULL )
V_20 = V_79 -> V_63 -> V_64 ;
else
V_20 = V_79 -> V_64 ;
V_21 = F_25 ( V_20 ) ;
if ( ! V_21 )
return;
do {
V_76 = F_72 ( V_79 , V_154 ,
F_31 ( ( sizeof( struct V_75 ) -
V_84 ) , 8 ) ,
& V_152 , & V_153 ) ;
if ( V_76 == 0 && V_152 > 0 ) {
V_74 = (struct V_73 * )
( unsigned long ) V_153 ;
if ( ( V_74 == & V_21 -> V_78 ) ||
( V_74 == & V_21 -> V_155 ) ) {
memcpy ( & V_74 -> V_75 , V_154 ,
( sizeof( struct V_75 ) -
V_84 ) ) ;
F_73 ( & V_74 -> F_23 ) ;
} else {
F_71 ( V_20 ,
(struct V_75 * ) V_154 ,
V_74 ) ;
}
} else {
break;
}
} while ( 1 );
return;
}
static int F_74 ( struct V_19 * V_20 , T_4 V_156 )
{
struct V_65 V_66 ;
int V_76 ;
memset ( & V_66 , 0 , sizeof( struct V_65 ) ) ;
V_76 = F_46 ( V_20 -> V_79 ,
V_156 ,
V_156 ,
( void * ) & V_66 ,
sizeof( struct V_65 ) ,
V_69 , V_20 -> V_79 ) ;
if ( V_76 != 0 )
return V_76 ;
V_76 = F_54 ( V_20 ) ;
return V_76 ;
}
static int F_75 ( struct V_19 * V_20 )
{
struct V_18 * V_21 ;
unsigned long V_12 ;
V_21 = F_21 ( V_20 ) ;
F_9 ( & V_20 -> V_79 -> V_157 , V_12 ) ;
V_21 -> V_22 = true ;
F_11 ( & V_20 -> V_79 -> V_157 , V_12 ) ;
F_22 ( V_21 ) ;
F_9 ( & V_20 -> V_79 -> V_157 , V_12 ) ;
F_76 ( V_20 , NULL ) ;
F_11 ( & V_20 -> V_79 -> V_157 , V_12 ) ;
F_77 ( V_20 -> V_79 ) ;
F_6 ( V_21 ) ;
return 0 ;
}
static int F_78 ( struct V_19 * V_20 ,
struct V_73 * V_74 )
{
struct V_18 * V_21 ;
struct V_75 * V_75 ;
struct V_61 * V_158 ;
int V_76 = 0 ;
V_75 = & V_74 -> V_75 ;
V_21 = F_20 ( V_20 ) ;
if ( ! V_21 )
return - V_91 ;
V_74 -> V_20 = V_20 ;
V_158 = F_79 ( V_20 -> V_79 ) ;
V_75 -> V_12 |= V_82 ;
V_75 -> V_108 . V_35 = ( sizeof( struct V_107 ) -
V_84 ) ;
V_75 -> V_108 . V_147 = V_159 ;
V_75 -> V_108 . V_141 =
V_74 -> V_140 . V_37 ;
V_75 -> V_80 = V_160 ;
if ( V_74 -> V_140 . V_37 ) {
V_76 = F_80 ( V_158 ,
& V_74 -> V_140 ,
V_75 ,
( sizeof( struct V_75 ) -
V_84 ) ,
( unsigned long ) V_74 ) ;
} else {
V_76 = F_52 ( V_20 -> V_79 , V_75 ,
( sizeof( struct V_75 ) -
V_84 ) ,
( unsigned long ) V_74 ,
V_85 ,
V_86 ) ;
}
if ( V_76 != 0 )
return V_76 ;
F_81 ( & V_21 -> V_26 ) ;
return V_76 ;
}
static int F_82 ( struct V_6 * V_161 )
{
F_83 ( V_161 , V_162 ) ;
F_84 ( V_161 -> V_163 , V_36 ) ;
F_85 ( V_161 -> V_163 , V_164 ) ;
F_86 ( V_161 -> V_163 , ( V_165 * V_87 ) ) ;
V_161 -> V_166 = 1 ;
V_161 -> V_167 |= V_168 ;
if ( ! strncmp ( V_161 -> V_169 , L_2 , 4 ) ) {
switch ( V_102 ) {
case V_170 :
case V_171 :
V_161 -> V_172 = V_173 ;
break;
}
}
return 0 ;
}
static int F_87 ( struct V_6 * V_7 , struct V_174 * V_175 ,
T_6 V_176 , int * V_177 )
{
T_6 V_178 = V_176 ;
T_6 V_179 = V_178 ;
int V_180 , V_181 ;
V_180 = 0xff ;
V_181 = 0x3f ;
F_88 ( V_179 , V_180 * V_181 ) ;
if ( ( T_6 ) ( V_179 + 1 ) * V_180 * V_181 < V_178 )
V_179 = 0xffff ;
V_177 [ 0 ] = V_180 ;
V_177 [ 1 ] = V_181 ;
V_177 [ 2 ] = ( int ) V_179 ;
return 0 ;
}
static int F_89 ( struct V_109 * V_110 )
{
struct V_128 * V_129 = F_62 ( V_110 -> V_20 -> V_8 ) ;
struct V_19 * V_20 = V_129 -> V_23 ;
struct V_18 * V_21 ;
struct V_73 * V_74 ;
struct V_75 * V_75 ;
int V_76 , V_77 ;
V_21 = F_20 ( V_20 ) ;
if ( ! V_21 )
return V_182 ;
V_74 = & V_21 -> V_155 ;
V_75 = & V_74 -> V_75 ;
F_51 ( & V_74 -> F_23 ) ;
V_75 -> V_80 = V_183 ;
V_75 -> V_12 = V_82 ;
V_75 -> V_108 . V_184 = V_21 -> V_184 ;
V_76 = F_52 ( V_20 -> V_79 , V_75 ,
( sizeof( struct V_75 ) -
V_84 ) ,
( unsigned long ) & V_21 -> V_155 ,
V_85 ,
V_86 ) ;
if ( V_76 != 0 )
return V_182 ;
V_77 = F_53 ( & V_74 -> F_23 , 5 * V_87 ) ;
if ( V_77 == 0 )
return V_185 ;
F_22 ( V_21 ) ;
return V_186 ;
}
static enum V_187 F_90 ( struct V_109 * V_110 )
{
return V_188 ;
}
static bool F_91 ( struct V_109 * V_110 )
{
bool V_189 = true ;
T_3 V_190 = V_110 -> V_116 [ 0 ] ;
switch ( V_190 ) {
case V_191 :
case V_192 :
V_110 -> V_135 = V_193 << 16 ;
V_189 = false ;
break;
default:
break;
}
return V_189 ;
}
static int F_92 ( struct V_11 * V_8 , struct V_109 * V_110 )
{
int V_76 ;
struct V_128 * V_129 = F_62 ( V_8 ) ;
struct V_19 * V_23 = V_129 -> V_23 ;
struct V_73 * V_126 = F_93 ( V_110 ) ;
int V_31 ;
struct V_28 * V_29 ;
unsigned int V_30 = 0 ;
struct V_107 * V_108 ;
if ( V_96 <= V_194 ) {
if ( ! F_91 ( V_110 ) ) {
V_110 -> V_142 ( V_110 ) ;
return 0 ;
}
}
V_126 -> V_127 = V_110 ;
V_108 = & V_126 -> V_75 . V_108 ;
V_108 -> V_195 . V_196 = 60 ;
V_108 -> V_195 . V_197 |=
( V_198 |
V_199 ) ;
switch ( V_110 -> V_200 ) {
case V_201 :
V_108 -> V_133 = V_42 ;
V_108 -> V_195 . V_197 |= V_202 ;
break;
case V_203 :
V_108 -> V_133 = V_134 ;
V_108 -> V_195 . V_197 |= V_204 ;
break;
default:
V_108 -> V_133 = V_205 ;
V_108 -> V_195 . V_197 |= ( V_204 |
V_202 ) ;
break;
}
V_108 -> V_206 = V_129 -> V_207 ;
V_108 -> V_184 = V_110 -> V_20 -> V_79 ;
V_108 -> V_208 = V_110 -> V_20 -> V_209 ;
V_108 -> V_5 = V_110 -> V_20 -> V_5 ;
V_108 -> V_210 = V_110 -> V_211 ;
memcpy ( V_108 -> V_144 , V_110 -> V_116 , V_108 -> V_210 ) ;
V_126 -> V_140 . V_37 = F_94 ( V_110 ) ;
if ( F_64 ( V_110 ) ) {
V_29 = (struct V_28 * ) F_63 ( V_110 ) ;
V_30 = F_64 ( V_110 ) ;
if ( F_29 ( V_29 , F_64 ( V_110 ) ) != - 1 ) {
V_126 -> V_40 =
F_30 ( V_29 , F_64 ( V_110 ) ,
F_94 ( V_110 ) ,
V_108 -> V_133 ) ;
if ( ! V_126 -> V_40 )
return V_212 ;
V_126 -> V_50 =
F_31 ( F_94 ( V_110 ) , V_36 ) >>
V_43 ;
if ( V_108 -> V_133 == V_42 )
F_44 ( V_29 ,
V_126 -> V_40 ,
F_64 ( V_110 ) ) ;
V_29 = V_126 -> V_40 ;
V_30 = V_126 -> V_50 ;
}
V_126 -> V_140 . V_34 = V_29 [ 0 ] . V_34 ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ )
V_126 -> V_140 . V_213 [ V_31 ] =
F_95 ( F_27 ( ( & V_29 [ V_31 ] ) ) ) ;
} else if ( F_63 ( V_110 ) ) {
V_126 -> V_140 . V_34 =
F_96 ( F_63 ( V_110 ) ) & ( V_36 - 1 ) ;
V_126 -> V_140 . V_213 [ 0 ] =
F_96 ( F_63 ( V_110 ) ) >> V_43 ;
}
V_76 = F_78 ( V_23 , V_126 ) ;
if ( V_76 == - V_214 ) {
if ( V_126 -> V_50 )
F_26 ( V_126 -> V_40 ,
V_126 -> V_50 ) ;
return V_215 ;
}
return 0 ;
}
static int F_97 ( struct V_19 * V_20 ,
const struct V_216 * V_217 )
{
int V_76 ;
struct V_11 * V_8 ;
struct V_128 * V_129 ;
bool V_218 = ( ( V_217 -> V_219 == V_220 ) ? true : false ) ;
int V_221 = 0 ;
struct V_18 * V_21 ;
int V_222 ;
int V_223 ;
int V_224 ;
switch ( V_102 ) {
case V_104 :
case V_103 :
V_159 = V_225 ;
V_84 = sizeof( struct V_226 ) ;
V_96 = V_227 ;
V_97 = V_228 ;
V_222 = V_229 ;
V_223 = V_230 ;
V_224 = V_231 ;
break;
default:
V_159 = V_232 ;
V_84 = 0 ;
V_96 = V_194 ;
V_97 = V_233 ;
V_222 = V_234 ;
V_223 = V_235 ;
V_224 = V_236 ;
break;
}
if ( V_217 -> V_219 == V_237 )
V_238 . V_239 = ( V_162 *
V_240 ) ;
V_8 = F_98 ( & V_238 ,
sizeof( struct V_128 ) ) ;
if ( ! V_8 )
return - V_241 ;
V_129 = F_62 ( V_8 ) ;
memset ( V_129 , 0 , sizeof( struct V_128 ) ) ;
V_129 -> V_207 = V_8 -> V_242 ;
V_129 -> V_23 = V_20 ;
V_21 = F_99 ( sizeof( struct V_18 ) , V_243 ) ;
if ( ! V_21 ) {
V_76 = - V_241 ;
goto V_244;
}
V_21 -> V_22 = false ;
V_21 -> V_67 = false ;
F_100 ( & V_21 -> V_25 ) ;
V_21 -> V_20 = V_20 ;
V_21 -> V_8 = V_8 ;
F_76 ( V_20 , V_21 ) ;
V_21 -> V_206 = V_8 -> V_242 ;
V_76 = F_74 ( V_20 , V_68 ) ;
if ( V_76 )
goto V_245;
V_129 -> V_246 = V_21 -> V_184 ;
V_129 -> V_221 = V_21 -> V_208 ;
switch ( V_217 -> V_219 ) {
case V_237 :
V_8 -> V_247 = V_248 ;
V_8 -> V_249 = V_240 ;
V_8 -> V_250 = V_251 - 1 ;
break;
case V_252 :
V_8 -> V_247 = V_222 ;
V_8 -> V_249 = V_223 ;
V_8 -> V_250 = V_224 - 1 ;
break;
default:
V_8 -> V_247 = V_229 ;
V_8 -> V_249 = V_230 ;
V_8 -> V_250 = V_231 - 1 ;
break;
}
V_8 -> V_253 = V_254 ;
V_76 = F_101 ( V_8 , & V_20 -> V_20 ) ;
if ( V_76 != 0 )
goto V_255;
if ( ! V_218 ) {
F_14 ( V_8 ) ;
} else {
V_221 = ( V_20 -> V_256 . V_257 [ 5 ] << 8 |
V_20 -> V_256 . V_257 [ 4 ] ) ;
V_76 = F_102 ( V_8 , 0 , V_221 , 0 ) ;
if ( V_76 ) {
F_103 ( V_8 ) ;
goto V_255;
}
}
return 0 ;
V_255:
F_75 ( V_20 ) ;
goto V_244;
V_245:
F_6 ( V_21 ) ;
V_244:
F_18 ( V_8 ) ;
return V_76 ;
}
static int F_104 ( struct V_19 * V_23 )
{
struct V_18 * V_21 = F_21 ( V_23 ) ;
struct V_11 * V_8 = V_21 -> V_8 ;
F_103 ( V_8 ) ;
F_75 ( V_23 ) ;
F_18 ( V_8 ) ;
return 0 ;
}
static int T_7 F_105 ( void )
{
T_4 V_258 ;
V_258 =
( ( V_68 - V_36 ) /
F_31 ( V_259 +
sizeof( struct V_75 ) + sizeof( T_5 ) -
V_84 ,
sizeof( T_5 ) ) ) ;
if ( V_258 <
V_162 )
return - V_260 ;
return F_106 ( & V_261 ) ;
}
static void T_8 F_107 ( void )
{
F_108 ( & V_261 ) ;
}

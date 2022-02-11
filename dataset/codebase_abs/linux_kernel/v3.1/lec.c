static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
if ( F_4 ( & V_2 -> V_3 ) )
F_5 ( V_2 ) ;
}
static void F_6 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
char * V_8 ;
struct V_9 * V_10 ;
V_8 = V_5 -> V_11 + V_5 -> V_7 -> V_12 ;
if ( * V_8 ++ == 0x42 && * V_8 ++ == 0x42 && * V_8 ++ == 0x03 ) {
struct V_13 * V_14 ;
struct V_4 * V_15 ;
struct V_16 * V_17 ;
V_15 = F_7 ( sizeof( struct V_16 ) , V_18 ) ;
if ( V_15 == NULL )
return;
V_15 -> V_19 = sizeof( struct V_16 ) ;
V_17 = (struct V_16 * ) V_15 -> V_11 ;
V_17 -> type = V_20 ;
V_8 += 4 ;
V_17 -> V_21 . V_22 . V_23 = * V_8 & 0x01 ;
V_10 = F_8 ( V_7 ) ;
F_9 ( V_10 -> V_24 , V_15 -> V_25 ) ;
V_14 = F_10 ( V_10 -> V_24 ) ;
F_11 ( & V_14 -> V_26 , V_15 ) ;
V_14 -> V_27 ( V_14 , V_15 -> V_19 ) ;
}
}
static unsigned char * F_12 ( unsigned char * V_28 , unsigned char * V_29 )
{
struct V_30 * V_31 ;
unsigned int V_32 , V_33 ;
V_31 = (struct V_30 * ) V_28 ;
if ( V_31 -> V_34 [ 0 ] & ( V_35 ) 0x80 )
return V_36 ;
if ( V_31 -> V_37 [ 0 ] & V_38 ) {
V_32 = ( F_13 ( V_31 -> V_39 ) & V_40 ) >> 8 ;
if ( ( F_13 ( V_31 -> V_39 ) >> 13 ) != 0 )
return V_36 ;
} else
return V_31 -> V_34 ;
if ( V_32 < 6 )
return V_31 -> V_34 ;
V_33 = ( V_32 / 2 ) - 1 ;
memset ( V_29 , 0 , V_41 ) ;
if ( V_31 -> V_39 & F_14 ( ( V_42 ) V_43 ) )
memcpy ( & V_29 [ 4 ] , & V_31 -> V_44 [ V_33 - 2 ] , sizeof( V_45 ) ) ;
else {
memcpy ( & V_29 [ 4 ] , & V_31 -> V_44 [ 1 ] , sizeof( V_45 ) ) ;
V_29 [ 5 ] = ( ( F_13 ( V_31 -> V_44 [ 0 ] ) & 0x000f ) | ( V_29 [ 5 ] & 0xf0 ) ) ;
}
return NULL ;
}
static int F_15 ( struct V_6 * V_7 )
{
F_16 ( V_7 ) ;
return 0 ;
}
static void
F_17 ( struct V_46 * V_47 , struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
F_18 ( V_5 ) -> V_47 = V_47 ;
F_18 ( V_5 ) -> V_48 = V_47 -> V_48 ;
F_19 ( V_5 -> V_25 , & F_10 ( V_47 ) -> V_49 ) ;
if ( V_47 -> V_50 ( V_47 , V_5 ) < 0 ) {
V_7 -> V_51 . V_52 ++ ;
return;
}
V_7 -> V_51 . V_53 ++ ;
V_7 -> V_51 . V_54 += V_5 -> V_19 ;
}
static void F_20 ( struct V_6 * V_7 )
{
F_21 ( L_1 , V_7 -> V_55 ) ;
V_7 -> V_56 = V_57 ;
F_22 ( V_7 ) ;
}
static T_1 F_23 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_4 * V_15 ;
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_58 * V_59 ;
struct V_46 * V_47 ;
struct V_1 * V_2 ;
unsigned char * V_60 ;
int V_61 ;
#ifdef F_24
unsigned char V_29 [ V_41 ] ;
#endif
int V_62 ;
F_25 ( L_2 ) ;
if ( ! V_10 -> V_24 ) {
F_21 ( L_3 , V_7 -> V_55 ) ;
V_7 -> V_51 . V_63 ++ ;
F_26 ( V_7 ) ;
F_27 ( V_5 ) ;
return V_64 ;
}
F_25 ( L_4 ,
( long ) V_5 -> V_65 , ( long ) V_5 -> V_11 , ( long ) F_28 ( V_5 ) ,
( long ) F_29 ( V_5 ) ) ;
#if F_30 ( V_66 ) || F_30 ( V_67 )
if ( memcmp ( V_5 -> V_11 , V_68 , sizeof( V_68 ) ) == 0 )
F_6 ( V_5 , V_7 ) ;
#endif
if ( F_31 ( V_5 ) < 2 ) {
F_25 ( L_5 ) ;
V_15 = F_32 ( V_5 , V_69 ) ;
F_27 ( V_5 ) ;
if ( V_15 == NULL )
return V_64 ;
V_5 = V_15 ;
}
F_33 ( V_5 , 2 ) ;
V_59 = (struct V_58 * ) V_5 -> V_11 ;
V_59 -> V_70 = F_14 ( V_10 -> V_71 ) ;
#ifdef F_24
if ( V_10 -> V_72 ) {
V_15 = F_32 ( V_5 , V_69 ) ;
F_27 ( V_5 ) ;
if ( V_15 == NULL )
return V_64 ;
V_5 = V_15 ;
}
#endif
#if V_73 >= 2
#define F_34 99
#elif V_73 >= 1
#define F_34 30
#endif
#if V_73 >= 1
F_35 ( V_74 L_6 ,
V_7 -> V_55 , V_5 -> V_19 , V_10 -> V_71 ) ;
F_36 ( V_74 , L_7 , V_75 , 16 , 1 ,
V_5 -> V_11 , F_37 ( V_5 -> V_19 , F_34 ) , true ) ;
#endif
#ifdef F_24
if ( V_10 -> V_72 )
V_61 = V_76 ;
else
#endif
V_61 = V_77 ;
if ( V_5 -> V_19 < V_61 ) {
if ( ( V_5 -> V_19 + F_38 ( V_5 ) ) < V_61 ) {
V_15 = F_39 ( V_5 , 0 ,
V_61 - V_5 -> V_25 ,
V_18 ) ;
F_40 ( V_5 ) ;
if ( V_15 == NULL ) {
V_7 -> V_51 . V_52 ++ ;
return V_64 ;
}
V_5 = V_15 ;
}
F_41 ( V_5 , V_61 - V_5 -> V_19 ) ;
}
V_62 = 0 ;
V_60 = V_59 -> V_78 ;
#ifdef F_24
if ( V_10 -> V_72 ) {
V_60 = F_12 ( V_5 -> V_11 + 2 , V_29 ) ;
if ( V_60 == NULL ) {
V_60 = V_29 ;
V_62 = 1 ;
}
}
#endif
V_2 = NULL ;
V_47 = F_42 ( V_10 , V_60 , V_62 , & V_2 ) ;
F_25 ( L_8 ,
V_7 -> V_55 , V_47 , V_47 ? V_47 -> V_79 : 0 , V_2 ) ;
if ( ! V_47 || ! F_43 ( V_80 , & V_47 -> V_79 ) ) {
if ( V_2 && ( V_2 -> V_81 . V_82 < V_83 ) ) {
F_25 ( L_9 ,
V_7 -> V_55 , V_59 -> V_78 ) ;
F_11 ( & V_2 -> V_81 , V_5 ) ;
} else {
F_25 ( L_10 ,
V_7 -> V_55 , V_59 -> V_78 ) ;
V_7 -> V_51 . V_52 ++ ;
F_40 ( V_5 ) ;
}
goto V_84;
}
#if V_73 > 0
F_35 ( V_74 L_11 ,
V_7 -> V_55 , V_47 -> V_85 , V_47 -> V_86 ) ;
#endif
while ( V_2 && ( V_15 = F_44 ( & V_2 -> V_81 ) ) ) {
F_25 ( L_12 , V_59 -> V_78 ) ;
F_17 ( V_47 , V_15 ) ;
}
F_17 ( V_47 , V_5 ) ;
if ( ! F_45 ( V_47 , 0 ) ) {
struct V_87 * V_88 = F_46 ( V_47 ) ;
V_88 -> V_89 = 1 ;
F_26 ( V_7 ) ;
if ( F_45 ( V_47 , 0 ) )
F_22 ( V_7 ) ;
}
V_84:
if ( V_2 )
F_3 ( V_2 ) ;
V_7 -> V_56 = V_57 ;
return V_64 ;
}
static int F_47 ( struct V_6 * V_7 )
{
F_26 ( V_7 ) ;
return 0 ;
}
static int F_48 ( struct V_46 * V_47 , struct V_4 * V_5 )
{
unsigned long V_79 ;
struct V_6 * V_7 = (struct V_6 * ) V_47 -> V_90 ;
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
int V_91 ;
char * V_92 ;
F_49 ( V_5 -> V_25 , & F_10 ( V_47 ) -> V_49 ) ;
V_17 = (struct V_16 * ) V_5 -> V_11 ;
V_92 = V_5 -> V_11 ;
V_92 += sizeof( struct V_16 ) ;
F_25 ( L_13 , V_7 -> V_55 , V_17 -> type ) ;
switch ( V_17 -> type ) {
case V_93 :
for ( V_91 = 0 ; V_91 < 6 ; V_91 ++ )
V_7 -> V_94 [ V_91 ] = V_17 -> V_21 . V_22 . V_95 [ V_91 ] ;
break;
case V_96 :
for ( V_91 = 0 ; V_91 < 6 ; V_91 ++ )
V_7 -> V_94 [ V_91 ] = 0 ;
break;
case V_97 :
F_50 ( V_10 , V_17 -> V_21 . V_22 . V_98 ,
V_17 -> V_21 . V_22 . V_23 ) ;
break;
case V_20 :
V_10 -> V_99 = V_17 -> V_21 . V_22 . V_23 ;
break;
case V_100 :
F_51 ( V_10 , V_17 -> V_21 . V_22 . V_23 ) ;
break;
case V_101 :
F_52 ( & V_10 -> V_102 , V_79 ) ;
V_2 = F_53 ( V_10 , V_17 -> V_21 . V_22 . V_95 ) ;
F_54 ( V_10 , V_2 ) ;
F_55 ( & V_10 -> V_102 , V_79 ) ;
if ( V_17 -> V_21 . V_22 . V_103 )
break;
case V_104 :
F_56 ( V_10 , V_17 -> V_21 . V_22 . V_95 ,
V_17 -> V_21 . V_22 . V_98 ,
V_17 -> V_21 . V_22 . V_23 ,
V_17 -> V_21 . V_22 . V_105 ) ;
F_25 ( L_14 ) ;
if ( V_17 -> V_106 != 0 ) {
F_25 ( L_15 ,
V_17 -> V_106 ) ;
F_57 ( V_7 , V_17 -> V_21 . V_22 . V_95 ,
V_92 , V_17 -> V_106 ) ;
}
break;
case V_107 :
V_10 -> V_108 =
V_17 -> V_21 . V_109 . V_108 ;
V_10 -> V_110 =
( V_17 -> V_21 . V_109 . V_110 * V_111 ) ;
V_10 -> V_112 = V_17 -> V_21 . V_109 . V_112 ;
V_10 -> V_113 = ( V_17 -> V_21 . V_109 . V_113 * V_111 ) ;
V_10 -> V_114 =
( V_17 -> V_21 . V_109 . V_114 * V_111 ) ;
V_10 -> V_115 =
( V_17 -> V_21 . V_109 . V_115 * V_111 ) ;
V_10 -> V_116 = ( V_17 -> V_21 . V_109 . V_116 * V_111 ) ;
V_10 -> V_117 =
( V_17 -> V_21 . V_109 . V_117 * V_111 ) ;
V_10 -> V_118 = V_17 -> V_21 . V_109 . V_118 ;
V_10 -> V_119 = NULL ;
if ( V_10 -> V_118 > 1 )
V_10 -> V_119 = & V_119 ;
if ( F_58 ( V_7 , V_17 -> V_21 . V_109 . V_120 ) )
F_21 ( L_16 ,
V_7 -> V_55 , V_17 -> V_21 . V_109 . V_120 ) ;
V_10 -> V_121 = V_17 -> V_21 . V_109 . V_121 ;
break;
case V_122 :
F_59 ( V_10 , V_17 -> V_21 . V_22 . V_98 ,
V_17 -> V_21 . V_22 . V_23 ) ;
break;
case V_123 :
V_10 -> V_71 =
( unsigned short ) ( 0xffff & V_17 -> V_21 . V_22 . V_23 ) ;
break;
case V_124 :
#if F_30 ( V_66 ) || F_30 ( V_67 )
{
F_25 ( L_17 ,
V_7 -> V_55 , V_17 -> V_21 . V_125 . V_95 ) ;
if ( V_126 == NULL )
break;
if ( V_126 ( V_7 , V_17 -> V_21 . V_125 . V_95 ) ) {
struct V_4 * V_15 ;
struct V_13 * V_14 ;
F_25 ( L_18 ,
V_7 -> V_55 ) ;
V_15 = F_7 ( sizeof( struct V_16 ) , V_18 ) ;
if ( V_15 == NULL )
break;
V_15 -> V_19 = sizeof( struct V_16 ) ;
F_60 ( V_15 , V_17 , sizeof( * V_17 ) ) ;
F_9 ( V_10 -> V_24 , V_15 -> V_25 ) ;
V_14 = F_10 ( V_10 -> V_24 ) ;
F_11 ( & V_14 -> V_26 , V_15 ) ;
V_14 -> V_27 ( V_14 , V_15 -> V_19 ) ;
}
}
#endif
break;
default:
F_21 ( L_19 , V_7 -> V_55 , V_17 -> type ) ;
F_40 ( V_5 ) ;
return - V_127 ;
}
F_40 ( V_5 ) ;
return 0 ;
}
static void F_61 ( struct V_46 * V_47 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 = (struct V_6 * ) V_47 -> V_90 ;
struct V_9 * V_10 = F_8 ( V_7 ) ;
V_10 -> V_24 = NULL ;
F_26 ( V_7 ) ;
F_62 ( V_10 ) ;
if ( F_63 ( & F_10 ( V_47 ) -> V_26 ) )
F_21 ( L_20 , V_7 -> V_55 ) ;
while ( ( V_5 = F_44 ( & F_10 ( V_47 ) -> V_26 ) ) ) {
F_64 ( V_47 , V_5 -> V_25 ) ;
F_40 ( V_5 ) ;
}
F_21 ( L_21 , V_7 -> V_55 ) ;
F_65 ( V_128 ) ;
}
static int
F_66 ( struct V_9 * V_10 , T_2 type ,
const unsigned char * V_95 , const unsigned char * V_98 ,
struct V_4 * V_11 )
{
struct V_13 * V_14 ;
struct V_4 * V_5 ;
struct V_16 * V_17 ;
if ( ! V_10 || ! V_10 -> V_24 )
return - 1 ;
V_5 = F_7 ( sizeof( struct V_16 ) , V_18 ) ;
if ( ! V_5 )
return - 1 ;
V_5 -> V_19 = sizeof( struct V_16 ) ;
V_17 = (struct V_16 * ) V_5 -> V_11 ;
memset ( V_17 , 0 , sizeof( struct V_16 ) ) ;
V_17 -> type = type ;
if ( V_11 != NULL )
V_17 -> V_106 = V_11 -> V_19 ;
if ( V_95 )
memcpy ( & V_17 -> V_21 . V_22 . V_95 , V_95 , V_41 ) ;
else
V_17 -> V_21 . V_22 . V_105 = 1 ;
if ( V_98 )
memcpy ( & V_17 -> V_21 . V_22 . V_98 , V_98 , V_129 ) ;
F_9 ( V_10 -> V_24 , V_5 -> V_25 ) ;
V_14 = F_10 ( V_10 -> V_24 ) ;
F_11 ( & V_14 -> V_26 , V_5 ) ;
V_14 -> V_27 ( V_14 , V_5 -> V_19 ) ;
if ( V_11 != NULL ) {
F_25 ( L_22 , V_11 -> V_19 ) ;
F_9 ( V_10 -> V_24 , V_11 -> V_25 ) ;
F_11 ( & V_14 -> V_26 , V_11 ) ;
V_14 -> V_27 ( V_14 , V_5 -> V_19 ) ;
}
return 0 ;
}
static int F_67 ( struct V_6 * V_7 , int V_130 )
{
if ( ( V_130 < 68 ) || ( V_130 > 18190 ) )
return - V_127 ;
V_7 -> V_120 = V_130 ;
return 0 ;
}
static void F_68 ( struct V_6 * V_7 )
{
}
static int F_69 ( struct V_46 * V_47 )
{
return ( ( V_47 -> V_131 . V_132 [ 0 ] . V_133 . V_134 . V_135 [ 4 ] == V_136 ) ||
( V_47 -> V_131 . V_132 [ 0 ] . V_133 . V_134 . V_135 [ 4 ] == V_137 ) ) ;
}
static void F_70 ( struct V_46 * V_47 , struct V_4 * V_5 )
{
unsigned long V_79 ;
struct V_6 * V_7 = (struct V_6 * ) V_47 -> V_90 ;
struct V_9 * V_10 = F_8 ( V_7 ) ;
#if V_73 > 0
F_35 ( V_74 L_23 ,
V_7 -> V_55 , V_47 -> V_85 , V_47 -> V_86 ) ;
#endif
if ( ! V_5 ) {
F_25 ( L_24 , V_7 -> V_55 ) ;
F_71 ( V_10 , V_47 ) ;
return;
}
#if V_73 >= 2
#define F_72 99
#elif V_73 >= 1
#define F_72 30
#endif
#if V_73 > 0
F_35 ( V_74 L_25 ,
V_7 -> V_55 , V_5 -> V_19 , V_10 -> V_71 ) ;
F_36 ( V_74 , L_7 , V_75 , 16 , 1 ,
V_5 -> V_11 , F_37 ( F_72 , V_5 -> V_19 ) , true ) ;
#endif
if ( memcmp ( V_5 -> V_11 , V_138 , 4 ) == 0 ) {
struct V_13 * V_14 = F_10 ( V_47 ) ;
F_25 ( L_26 , V_7 -> V_55 ) ;
F_11 ( & V_14 -> V_26 , V_5 ) ;
V_14 -> V_27 ( V_14 , V_5 -> V_19 ) ;
} else {
struct V_1 * V_2 ;
unsigned char * V_139 , * V_60 ;
F_64 ( V_47 , V_5 -> V_25 ) ;
if ( * ( V_45 * ) V_5 -> V_11 == F_14 ( V_10 -> V_71 ) ||
! V_10 -> V_24 || ! ( V_7 -> V_79 & V_140 ) ) {
F_25 ( L_27 ) ;
F_40 ( V_5 ) ;
return;
}
#ifdef F_24
if ( V_10 -> V_72 )
V_60 = ( (struct V_141 * ) V_5 -> V_11 ) -> V_78 ;
else
#endif
V_60 = ( (struct V_58 * ) V_5 -> V_11 ) -> V_78 ;
F_52 ( & V_10 -> V_102 , V_79 ) ;
if ( F_69 ( V_47 ) ) {
#ifdef F_24
if ( V_10 -> V_72 )
V_139 =
( (struct V_141 * ) V_5 -> V_11 ) ->
V_142 ;
else
#endif
V_139 =
( (struct V_58 * ) V_5 -> V_11 ) ->
V_142 ;
V_2 = F_53 ( V_10 , V_139 ) ;
if ( V_2 && V_2 -> V_47 != V_47 ) {
F_54 ( V_10 , V_2 ) ;
F_3 ( V_2 ) ;
}
}
F_55 ( & V_10 -> V_102 , V_79 ) ;
if ( ! ( V_60 [ 0 ] & 0x01 ) &&
! V_10 -> V_121 &&
memcmp ( V_60 , V_7 -> V_94 , V_7 -> V_143 ) ) {
F_40 ( V_5 ) ;
return;
}
if ( ! F_73 ( & V_10 -> V_144 ) )
F_74 ( V_10 , V_47 , V_5 ) ;
F_75 ( V_5 , 2 ) ;
#ifdef F_24
if ( V_10 -> V_72 )
V_5 -> V_145 = F_76 ( V_5 , V_7 ) ;
else
#endif
V_5 -> V_145 = F_77 ( V_5 , V_7 ) ;
V_7 -> V_51 . V_146 ++ ;
V_7 -> V_51 . V_147 += V_5 -> V_19 ;
memset ( F_18 ( V_5 ) , 0 , sizeof( struct V_148 ) ) ;
F_78 ( V_5 ) ;
}
}
static void F_79 ( struct V_46 * V_47 , struct V_4 * V_5 )
{
struct V_87 * V_88 = F_46 ( V_47 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
if ( V_88 == NULL ) {
F_21 ( L_28 ) ;
return;
}
V_88 -> V_149 ( V_47 , V_5 ) ;
if ( V_88 -> V_89 && F_45 ( V_47 , 0 ) ) {
V_88 -> V_89 = 0 ;
if ( F_80 ( V_7 ) && F_81 ( V_7 ) )
F_22 ( V_7 ) ;
}
}
static int F_82 ( struct V_46 * V_47 , void T_3 * V_150 )
{
struct V_87 * V_88 ;
int V_151 ;
struct V_152 V_153 ;
V_151 = F_83 ( & V_153 , V_150 , sizeof( struct V_152 ) ) ;
if ( V_151 != 0 )
F_21 ( L_29 , V_151 ) ;
if ( V_153 . V_154 < 0 || V_153 . V_154 >= V_155 ||
! V_156 [ V_153 . V_154 ] )
return - V_127 ;
V_88 = F_84 ( sizeof( struct V_87 ) , V_157 ) ;
if ( ! V_88 )
return - V_158 ;
V_88 -> V_89 = 0 ;
V_88 -> V_149 = V_47 -> V_159 ;
V_47 -> V_160 = V_88 ;
V_47 -> V_159 = F_79 ;
F_85 ( F_8 ( V_156 [ V_153 . V_154 ] ) ,
& V_153 , V_47 , V_47 -> V_161 ) ;
V_47 -> V_90 = V_156 [ V_153 . V_154 ] ;
V_47 -> V_161 = F_70 ;
return 0 ;
}
static int F_86 ( struct V_46 * V_47 , int V_150 )
{
if ( V_150 < 0 || V_150 >= V_155 || ! V_156 [ V_150 ] )
return - V_127 ;
V_47 -> V_90 = V_156 [ V_150 ] ;
return F_87 ( F_8 ( V_156 [ V_150 ] ) , V_47 ) ;
}
static int F_88 ( struct V_46 * V_47 , int V_150 )
{
int V_91 ;
struct V_9 * V_10 ;
if ( V_150 < 0 )
V_91 = 0 ;
else
V_91 = V_150 ;
#ifdef F_24
if ( V_150 >= V_155 )
return - V_127 ;
#else
if ( V_150 >= ( V_155 - V_162 ) )
return - V_127 ;
#endif
if ( ! V_156 [ V_91 ] ) {
int V_72 , V_163 ;
V_72 = 0 ;
if ( V_91 >= ( V_155 - V_162 ) )
V_72 = 1 ;
V_163 = sizeof( struct V_9 ) ;
#ifdef F_24
if ( V_72 )
V_156 [ V_91 ] = F_89 ( V_163 ) ;
else
#endif
V_156 [ V_91 ] = F_90 ( V_163 ) ;
if ( ! V_156 [ V_91 ] )
return - V_158 ;
V_156 [ V_91 ] -> V_164 = & V_165 ;
snprintf ( V_156 [ V_91 ] -> V_55 , V_166 , L_30 , V_91 ) ;
if ( F_91 ( V_156 [ V_91 ] ) ) {
F_92 ( V_156 [ V_91 ] ) ;
return - V_127 ;
}
V_10 = F_8 ( V_156 [ V_91 ] ) ;
V_10 -> V_72 = V_72 ;
} else {
V_10 = F_8 ( V_156 [ V_91 ] ) ;
if ( V_10 -> V_24 )
return - V_167 ;
}
F_93 ( V_10 ) ;
V_10 -> V_168 = V_91 ;
V_10 -> V_24 = V_47 ;
V_47 -> V_7 = & V_169 ;
F_94 ( F_10 ( V_47 ) ) ;
V_47 -> V_90 = V_156 [ V_91 ] ;
F_95 ( V_170 , & V_47 -> V_79 ) ;
F_95 ( V_80 , & V_47 -> V_79 ) ;
V_10 -> V_108 = 1 ;
V_10 -> V_110 = ( 1 * V_111 ) ;
V_10 -> V_171 = ( 1200 * V_111 ) ;
V_10 -> V_112 = 1 ;
V_10 -> V_113 = ( 300 * V_111 ) ;
V_10 -> V_114 = ( 15 * V_111 ) ;
V_10 -> V_99 = 0 ;
V_10 -> V_115 = ( 1 * V_111 ) ;
V_10 -> V_116 = ( 4 * V_111 ) ;
V_10 -> V_117 = ( 6 * V_111 ) ;
if ( V_156 [ V_91 ] -> V_79 & V_140 )
F_16 ( V_156 [ V_91 ] ) ;
F_96 ( V_128 ) ;
return V_91 ;
}
static const char * F_97 ( unsigned char V_172 )
{
static const char * const V_173 [] = {
L_31 ,
L_32 ,
L_33 ,
L_34 ,
L_35 ,
L_36
} ;
if ( V_172 > V_174 )
V_172 = 3 ;
return V_173 [ V_172 ] ;
}
static void F_98 ( struct V_175 * V_176 , struct V_1 * V_2 )
{
int V_91 ;
for ( V_91 = 0 ; V_91 < V_41 ; V_91 ++ )
F_99 ( V_176 , L_37 , V_2 -> V_95 [ V_91 ] & 0xff ) ;
F_99 ( V_176 , L_38 ) ;
for ( V_91 = 0 ; V_91 < V_129 ; V_91 ++ )
F_99 ( V_176 , L_37 , V_2 -> V_98 [ V_91 ] & 0xff ) ;
F_99 ( V_176 , L_39 , F_97 ( V_2 -> V_172 ) ,
V_2 -> V_79 & 0xffff ) ;
if ( V_2 -> V_47 )
F_99 ( V_176 , L_40 , V_2 -> V_47 -> V_85 , V_2 -> V_47 -> V_86 ) ;
else
F_99 ( V_176 , L_41 ) ;
if ( V_2 -> V_177 ) {
F_99 ( V_176 , L_42 , V_2 -> V_177 -> V_85 ,
V_2 -> V_177 -> V_86 ) ;
}
F_100 ( V_176 , '\n' ) ;
}
static void * F_101 ( struct V_178 * V_179 , struct V_180 * V_181 ,
T_4 * V_182 )
{
struct V_183 * V_184 = V_179 -> V_185 ;
struct V_1 * V_92 ;
if ( ! V_184 )
V_184 = V_181 -> V_186 ;
if ( V_184 == V_187 ) {
V_184 = V_181 -> V_186 ;
-- * V_182 ;
}
F_102 (tmp, e, next) {
if ( -- * V_182 < 0 )
break;
}
V_179 -> V_185 = V_184 ;
return ( * V_182 < 0 ) ? V_179 : NULL ;
}
static void * F_103 ( struct V_178 * V_179 , T_4 * V_182 ,
struct V_9 * V_10 )
{
void * V_188 = NULL ;
int V_189 ;
for ( V_189 = V_179 -> V_190 ; V_189 < V_191 ; V_189 ++ ) {
V_188 = F_101 ( V_179 , & V_10 -> V_192 [ V_189 ] , V_182 ) ;
if ( V_188 )
break;
}
V_179 -> V_190 = V_189 ;
return V_188 ;
}
static void * F_104 ( struct V_178 * V_179 , T_4 * V_182 ,
struct V_9 * V_10 )
{
struct V_180 * V_193 [] = {
& V_10 -> V_144 ,
& V_10 -> V_194 ,
& V_10 -> V_195
} ;
void * V_188 = NULL ;
int V_196 ;
for ( V_196 = V_179 -> V_197 ; V_196 < F_105 ( V_193 ) ; V_196 ++ ) {
V_188 = F_101 ( V_179 , V_193 [ V_196 ] , V_182 ) ;
if ( V_188 )
break;
}
V_179 -> V_197 = V_196 ;
return V_188 ;
}
static void * F_106 ( struct V_178 * V_179 , T_4 * V_182 ,
struct V_9 * V_10 )
{
if ( ! V_179 -> V_198 ) {
V_179 -> V_198 = V_10 ;
F_52 ( & V_10 -> V_102 , V_179 -> V_79 ) ;
}
if ( ! F_103 ( V_179 , V_182 , V_10 ) && ! F_104 ( V_179 , V_182 , V_10 ) ) {
F_55 ( & V_10 -> V_102 , V_179 -> V_79 ) ;
V_179 -> V_198 = NULL ;
V_179 -> V_190 = V_179 -> V_197 = 0 ;
}
return V_179 -> V_198 ;
}
static void * F_107 ( struct V_178 * V_179 , T_4 * V_182 )
{
struct V_6 * V_7 ;
void * V_188 ;
V_7 = V_179 -> V_7 ? V_179 -> V_7 : V_156 [ V_179 -> V_199 ] ;
V_188 = ( V_7 && F_8 ( V_7 ) ) ?
F_106 ( V_179 , V_182 , F_8 ( V_7 ) ) : NULL ;
if ( ! V_188 && V_7 ) {
F_108 ( V_7 ) ;
V_7 = NULL ;
}
V_179 -> V_7 = V_7 ;
return V_188 ;
}
static void * F_109 ( struct V_178 * V_179 , T_4 V_182 )
{
void * V_188 = NULL ;
for (; V_179 -> V_199 < V_155 ; V_179 -> V_199 ++ ) {
V_188 = F_107 ( V_179 , & V_182 ) ;
if ( V_188 )
break;
}
return V_188 ;
}
static void * F_110 ( struct V_175 * V_176 , T_4 * V_200 )
{
struct V_178 * V_179 = V_176 -> V_201 ;
V_179 -> V_199 = 0 ;
V_179 -> V_7 = NULL ;
V_179 -> V_198 = NULL ;
V_179 -> V_190 = 0 ;
V_179 -> V_197 = 0 ;
V_179 -> V_185 = V_187 ;
return * V_200 ? F_109 ( V_179 , * V_200 ) : V_187 ;
}
static void F_111 ( struct V_175 * V_176 , void * V_188 )
{
struct V_178 * V_179 = V_176 -> V_201 ;
if ( V_179 -> V_7 ) {
F_55 ( & V_179 -> V_198 -> V_102 ,
V_179 -> V_79 ) ;
F_108 ( V_179 -> V_7 ) ;
}
}
static void * F_112 ( struct V_175 * V_176 , void * V_188 , T_4 * V_200 )
{
struct V_178 * V_179 = V_176 -> V_201 ;
V_188 = F_109 ( V_179 , 1 ) ;
* V_200 += ! ! F_113 ( V_188 ) ;
return V_188 ;
}
static int F_114 ( struct V_175 * V_176 , void * V_188 )
{
static const char V_202 [] =
L_43
L_44
L_45 ;
if ( V_188 == V_187 )
F_115 ( V_176 , V_202 ) ;
else {
struct V_178 * V_179 = V_176 -> V_201 ;
struct V_6 * V_7 = V_179 -> V_7 ;
struct V_1 * V_2 = F_116 ( V_179 -> V_185 ,
struct V_1 ,
V_203 ) ;
F_99 ( V_176 , L_46 , V_7 -> V_55 ) ;
F_98 ( V_176 , V_2 ) ;
}
return 0 ;
}
static int F_117 ( struct V_204 * V_204 , struct V_205 * V_205 )
{
return F_118 ( V_205 , & V_206 , sizeof( struct V_178 ) ) ;
}
static int F_119 ( struct V_207 * V_13 , unsigned int V_208 , unsigned long V_150 )
{
struct V_46 * V_47 = F_120 ( V_13 ) ;
int V_209 = 0 ;
switch ( V_208 ) {
case V_210 :
case V_211 :
case V_212 :
if ( ! F_121 ( V_213 ) )
return - V_214 ;
break;
default:
return - V_215 ;
}
switch ( V_208 ) {
case V_210 :
V_209 = F_88 ( V_47 , ( int ) V_150 ) ;
if ( V_209 >= 0 )
V_13 -> V_179 = V_216 ;
break;
case V_211 :
V_209 = F_86 ( V_47 , ( int ) V_150 ) ;
break;
case V_212 :
V_209 = F_82 ( V_47 , ( void T_3 * ) V_150 ) ;
break;
}
return V_209 ;
}
static int T_5 F_122 ( void )
{
#ifdef F_123
struct V_217 * V_189 ;
V_189 = F_124 ( L_47 , V_218 , V_219 , & V_220 ) ;
if ( ! V_189 ) {
F_125 ( L_48 ) ;
return - V_158 ;
}
#endif
F_126 ( & V_221 ) ;
F_21 ( L_49 ) ;
return 0 ;
}
static void T_6 F_127 ( void )
{
int V_91 ;
F_128 ( L_47 , V_219 ) ;
F_129 ( & V_221 ) ;
for ( V_91 = 0 ; V_91 < V_155 ; V_91 ++ ) {
if ( V_156 [ V_91 ] != NULL ) {
F_130 ( V_156 [ V_91 ] ) ;
F_92 ( V_156 [ V_91 ] ) ;
V_156 [ V_91 ] = NULL ;
}
}
}
static int F_131 ( struct V_6 * V_7 , const T_7 * V_222 , int V_223 ,
T_7 * * V_224 , T_8 * V_106 )
{
unsigned long V_79 ;
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_1 * V_225 ;
struct V_4 * V_5 ;
int V_226 ;
if ( V_223 == 0 ) {
F_52 ( & V_10 -> V_102 , V_79 ) ;
V_225 = F_53 ( V_10 , V_222 ) ;
F_55 ( & V_10 -> V_102 , V_79 ) ;
if ( V_225 == NULL )
return - 1 ;
* V_224 = F_132 ( V_225 -> V_224 , V_225 -> V_106 , V_18 ) ;
if ( * V_224 == NULL )
return - 1 ;
* V_106 = V_225 -> V_106 ;
return 0 ;
}
if ( V_106 == NULL )
V_226 = F_66 ( V_10 , V_227 , V_222 , NULL , NULL ) ;
else {
V_5 = F_7 ( * V_106 , V_18 ) ;
if ( V_5 == NULL )
return - 1 ;
V_5 -> V_19 = * V_106 ;
F_60 ( V_5 , * V_224 , * V_106 ) ;
V_226 = F_66 ( V_10 , V_227 , V_222 , NULL , V_5 ) ;
}
return V_226 ;
}
static int F_133 ( struct V_6 * V_7 , const T_7 * V_228 ,
const T_7 * V_224 , T_8 V_106 )
{
int V_226 ;
struct V_4 * V_5 ;
struct V_9 * V_10 = F_8 ( V_7 ) ;
if ( F_134 ( V_228 , V_7 -> V_94 ) )
return 0 ;
F_5 ( V_10 -> V_224 ) ;
V_10 -> V_224 = F_132 ( V_224 , V_106 , V_157 ) ;
if ( V_10 -> V_224 == NULL )
return 0 ;
V_10 -> V_106 = V_106 ;
V_5 = F_7 ( V_106 , V_18 ) ;
if ( V_5 == NULL )
return 0 ;
V_5 -> V_19 = V_106 ;
F_60 ( V_5 , V_224 , V_106 ) ;
V_226 = F_66 ( V_10 , V_229 , NULL , NULL , V_5 ) ;
if ( V_226 != 0 )
F_21 ( L_50 ) ;
return 1 ;
}
static void F_57 ( struct V_6 * V_7 , const T_7 * V_95 ,
const T_7 * V_224 , T_8 V_106 )
{
#if 0
int i = 0;
#endif
struct V_9 * V_10 = F_8 ( V_7 ) ;
#if 0
struct lec_arp_table *entry = lec_arp_find(priv, mac_addr);
if (entry == NULL)
return;
kfree(entry->tlvs);
entry->tlvs = kmemdup(tlvs, sizeoftlvs, GFP_KERNEL);
if (entry->tlvs == NULL)
return;
entry->sizeoftlvs = sizeoftlvs;
#endif
#if 0
pr_info("\n");
pr_info("dump of tlvs, sizeoftlvs=%d\n", sizeoftlvs);
while (i < sizeoftlvs)
pr_cont("%02x ", tlvs[i++]);
pr_cont("\n");
#endif
if ( V_10 -> V_119 && V_10 -> V_119 -> V_230 ) {
V_10 -> V_119 -> V_230 ( V_7 , V_95 ,
V_224 , V_106 ) ;
}
}
static void F_93 ( struct V_9 * V_10 )
{
unsigned short V_91 ;
for ( V_91 = 0 ; V_91 < V_191 ; V_91 ++ )
F_135 ( & V_10 -> V_192 [ V_91 ] ) ;
F_135 ( & V_10 -> V_144 ) ;
F_135 ( & V_10 -> V_194 ) ;
F_135 ( & V_10 -> V_195 ) ;
F_136 ( & V_10 -> V_102 ) ;
F_137 ( & V_10 -> V_231 , V_232 ) ;
F_138 ( & V_10 -> V_231 , V_233 ) ;
}
static void F_139 ( struct V_1 * V_2 )
{
if ( V_2 -> V_47 ) {
struct V_46 * V_47 = V_2 -> V_47 ;
struct V_87 * V_88 = F_46 ( V_47 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_47 -> V_90 ;
V_47 -> V_159 = V_88 -> V_149 ;
if ( V_88 -> V_89 )
F_22 ( V_7 ) ;
F_5 ( V_88 ) ;
V_47 -> V_160 = NULL ;
V_47 -> V_161 = V_2 -> V_234 ;
F_140 ( V_47 , - V_235 ) ;
V_2 -> V_47 = NULL ;
}
if ( V_2 -> V_177 ) {
V_2 -> V_177 -> V_161 = V_2 -> V_236 ;
F_140 ( V_2 -> V_177 , - V_235 ) ;
V_2 -> V_177 = NULL ;
}
}
static inline void
F_141 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
struct V_180 * V_92 ;
V_92 = & V_10 -> V_192 [ F_142 ( V_2 -> V_95 [ V_41 - 1 ] ) ] ;
F_143 ( & V_2 -> V_203 , V_92 ) ;
F_25 ( L_51 , V_2 -> V_95 ) ;
}
static int
F_54 ( struct V_9 * V_10 , struct V_1 * V_237 )
{
struct V_183 * V_185 ;
struct V_1 * V_2 ;
int V_91 , V_238 = 1 ;
if ( ! V_237 )
return - 1 ;
F_144 ( & V_237 -> V_203 ) ;
F_145 ( & V_237 -> V_239 ) ;
if ( V_237 -> V_172 >= V_240 ) {
for ( V_91 = 0 ; V_91 < V_191 ; V_91 ++ ) {
F_146 (entry, node,
&priv->lec_arp_tables[i], next) {
if ( memcmp ( V_237 -> V_98 ,
V_2 -> V_98 , V_129 ) == 0 ) {
V_238 = 0 ;
break;
}
}
}
if ( V_238 )
F_139 ( V_237 ) ;
}
F_147 ( & V_237 -> V_81 ) ;
F_25 ( L_52 , V_237 -> V_95 ) ;
return 0 ;
}
static const char * F_148 ( unsigned char V_241 )
{
switch ( V_241 ) {
case V_242 :
return L_53 ;
case V_243 :
return L_54 ;
case V_244 :
return L_55 ;
case V_240 :
return L_56 ;
case V_174 :
return L_36 ;
}
return L_57 ;
}
static void F_149 ( struct V_9 * V_10 )
{
struct V_183 * V_185 ;
struct V_1 * V_245 ;
char V_246 [ 256 ] ;
int V_91 , V_247 , V_248 ;
F_21 ( L_58 , V_10 ) ;
for ( V_91 = 0 ; V_91 < V_191 ; V_91 ++ ) {
F_146 (rulla, node,
&priv->lec_arp_tables[i], next) {
V_248 = 0 ;
V_248 += sprintf ( V_246 , L_59 , V_91 , V_245 ) ;
V_248 += sprintf ( V_246 + V_248 , L_60 ,
V_245 -> V_95 ) ;
V_248 += sprintf ( V_246 + V_248 , L_61 ) ;
for ( V_247 = 0 ; V_247 < V_129 ; V_247 ++ ) {
V_248 += sprintf ( V_246 + V_248 ,
L_62 ,
V_245 -> V_98 [ V_247 ] & 0xff ) ;
}
V_248 += sprintf ( V_246 + V_248 ,
L_63 ,
V_245 -> V_47 ? V_245 -> V_47 -> V_85 : 0 ,
V_245 -> V_47 ? V_245 -> V_47 -> V_86 : 0 ,
V_245 -> V_177 ? V_245 -> V_177 ->
V_85 : 0 ,
V_245 -> V_177 ? V_245 -> V_177 ->
V_86 : 0 , V_245 -> V_249 ,
V_245 -> V_250 , V_245 -> V_251 ) ;
V_248 +=
sprintf ( V_246 + V_248 ,
L_64 ,
V_245 -> V_79 , V_245 -> V_252 ,
F_148 ( V_245 -> V_172 ) ) ;
F_21 ( L_1 , V_246 ) ;
}
}
if ( ! F_73 ( & V_10 -> V_194 ) )
F_21 ( L_65 ) ;
F_146 (rulla, node, &priv->lec_no_forward, next) {
V_248 = 0 ;
V_248 += sprintf ( V_246 + V_248 , L_60 , V_245 -> V_95 ) ;
V_248 += sprintf ( V_246 + V_248 , L_61 ) ;
for ( V_247 = 0 ; V_247 < V_129 ; V_247 ++ ) {
V_248 += sprintf ( V_246 + V_248 , L_62 ,
V_245 -> V_98 [ V_247 ] & 0xff ) ;
}
V_248 += sprintf ( V_246 + V_248 ,
L_63 ,
V_245 -> V_47 ? V_245 -> V_47 -> V_85 : 0 ,
V_245 -> V_47 ? V_245 -> V_47 -> V_86 : 0 ,
V_245 -> V_177 ? V_245 -> V_177 -> V_85 : 0 ,
V_245 -> V_177 ? V_245 -> V_177 -> V_86 : 0 ,
V_245 -> V_249 ,
V_245 -> V_250 , V_245 -> V_251 ) ;
V_248 += sprintf ( V_246 + V_248 ,
L_64 ,
V_245 -> V_79 , V_245 -> V_252 ,
F_148 ( V_245 -> V_172 ) ) ;
F_21 ( L_1 , V_246 ) ;
}
if ( ! F_73 ( & V_10 -> V_144 ) )
F_21 ( L_66 ) ;
F_146 (rulla, node, &priv->lec_arp_empty_ones, next) {
V_248 = 0 ;
V_248 += sprintf ( V_246 + V_248 , L_60 , V_245 -> V_95 ) ;
V_248 += sprintf ( V_246 + V_248 , L_61 ) ;
for ( V_247 = 0 ; V_247 < V_129 ; V_247 ++ ) {
V_248 += sprintf ( V_246 + V_248 , L_62 ,
V_245 -> V_98 [ V_247 ] & 0xff ) ;
}
V_248 += sprintf ( V_246 + V_248 ,
L_63 ,
V_245 -> V_47 ? V_245 -> V_47 -> V_85 : 0 ,
V_245 -> V_47 ? V_245 -> V_47 -> V_86 : 0 ,
V_245 -> V_177 ? V_245 -> V_177 -> V_85 : 0 ,
V_245 -> V_177 ? V_245 -> V_177 -> V_86 : 0 ,
V_245 -> V_249 ,
V_245 -> V_250 , V_245 -> V_251 ) ;
V_248 += sprintf ( V_246 + V_248 ,
L_64 ,
V_245 -> V_79 , V_245 -> V_252 ,
F_148 ( V_245 -> V_172 ) ) ;
F_21 ( L_67 , V_246 ) ;
}
if ( ! F_73 ( & V_10 -> V_195 ) )
F_21 ( L_68 ) ;
F_146 (rulla, node, &priv->mcast_fwds, next) {
V_248 = 0 ;
V_248 += sprintf ( V_246 + V_248 , L_60 , V_245 -> V_95 ) ;
V_248 += sprintf ( V_246 + V_248 , L_61 ) ;
for ( V_247 = 0 ; V_247 < V_129 ; V_247 ++ ) {
V_248 += sprintf ( V_246 + V_248 , L_62 ,
V_245 -> V_98 [ V_247 ] & 0xff ) ;
}
V_248 += sprintf ( V_246 + V_248 ,
L_63 ,
V_245 -> V_47 ? V_245 -> V_47 -> V_85 : 0 ,
V_245 -> V_47 ? V_245 -> V_47 -> V_86 : 0 ,
V_245 -> V_177 ? V_245 -> V_177 -> V_85 : 0 ,
V_245 -> V_177 ? V_245 -> V_177 -> V_86 : 0 ,
V_245 -> V_249 ,
V_245 -> V_250 , V_245 -> V_251 ) ;
V_248 += sprintf ( V_246 + V_248 ,
L_64 ,
V_245 -> V_79 , V_245 -> V_252 ,
F_148 ( V_245 -> V_172 ) ) ;
F_21 ( L_1 , V_246 ) ;
}
}
static void F_62 ( struct V_9 * V_10 )
{
unsigned long V_79 ;
struct V_183 * V_185 , * V_203 ;
struct V_1 * V_2 ;
int V_91 ;
F_150 ( & V_10 -> V_231 ) ;
F_52 ( & V_10 -> V_102 , V_79 ) ;
for ( V_91 = 0 ; V_91 < V_191 ; V_91 ++ ) {
F_151 (entry, node, next,
&priv->lec_arp_tables[i], next) {
F_54 ( V_10 , V_2 ) ;
F_3 ( V_2 ) ;
}
F_135 ( & V_10 -> V_192 [ V_91 ] ) ;
}
F_151 (entry, node, next,
&priv->lec_arp_empty_ones, next) {
F_152 ( & V_2 -> V_239 ) ;
F_139 ( V_2 ) ;
F_144 ( & V_2 -> V_203 ) ;
F_3 ( V_2 ) ;
}
F_135 ( & V_10 -> V_144 ) ;
F_151 (entry, node, next,
&priv->lec_no_forward, next) {
F_152 ( & V_2 -> V_239 ) ;
F_139 ( V_2 ) ;
F_144 ( & V_2 -> V_203 ) ;
F_3 ( V_2 ) ;
}
F_135 ( & V_10 -> V_194 ) ;
F_151 (entry, node, next, &priv->mcast_fwds, next) {
F_139 ( V_2 ) ;
F_144 ( & V_2 -> V_203 ) ;
F_3 ( V_2 ) ;
}
F_135 ( & V_10 -> V_195 ) ;
V_10 -> V_253 = NULL ;
F_55 ( & V_10 -> V_102 , V_79 ) ;
}
static struct V_1 * F_53 ( struct V_9 * V_10 ,
const unsigned char * V_95 )
{
struct V_183 * V_185 ;
struct V_180 * V_65 ;
struct V_1 * V_2 ;
F_25 ( L_69 , V_95 ) ;
V_65 = & V_10 -> V_192 [ F_142 ( V_95 [ V_41 - 1 ] ) ] ;
F_146 (entry, node, head, next) {
if ( ! F_134 ( V_95 , V_2 -> V_95 ) )
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_153 ( struct V_9 * V_10 ,
const unsigned char * V_95 )
{
struct V_1 * V_254 ;
V_254 = F_154 ( sizeof( struct V_1 ) , V_18 ) ;
if ( ! V_254 ) {
F_21 ( L_70 ) ;
return NULL ;
}
memcpy ( V_254 -> V_95 , V_95 , V_41 ) ;
F_155 ( & V_254 -> V_203 ) ;
F_156 ( & V_254 -> V_239 , V_255 ,
( unsigned long ) V_254 ) ;
V_254 -> V_249 = V_57 ;
V_254 -> V_10 = V_10 ;
F_157 ( & V_254 -> V_81 ) ;
F_158 ( & V_254 -> V_3 , 1 ) ;
return V_254 ;
}
static void V_255 ( unsigned long V_11 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_11 ;
F_25 ( L_71 ) ;
if ( V_2 -> V_172 == V_243 ) {
if ( V_2 -> V_251 <= V_2 -> V_10 -> V_112 ) {
if ( V_2 -> V_62 )
F_66 ( V_2 -> V_10 , V_256 ,
V_2 -> V_95 , NULL , NULL ) ;
else
F_66 ( V_2 -> V_10 , V_227 ,
V_2 -> V_95 , NULL , NULL ) ;
V_2 -> V_251 ++ ;
}
F_159 ( & V_2 -> V_239 , V_57 + ( 1 * V_111 ) ) ;
}
}
static void F_160 ( unsigned long V_11 )
{
unsigned long V_79 ;
struct V_1 * V_237 = (struct V_1 * ) V_11 ;
struct V_9 * V_10 = (struct V_9 * ) V_237 -> V_10 ;
F_145 ( & V_237 -> V_239 ) ;
F_25 ( L_72 ,
V_237 , V_10 ,
V_237 -> V_47 ? V_237 -> V_177 -> V_85 : 0 ,
V_237 -> V_47 ? V_237 -> V_177 -> V_86 : 0 ) ;
F_52 ( & V_10 -> V_102 , V_79 ) ;
F_144 ( & V_237 -> V_203 ) ;
F_55 ( & V_10 -> V_102 , V_79 ) ;
F_139 ( V_237 ) ;
F_3 ( V_237 ) ;
}
static bool F_161 ( struct V_1 * V_2 ,
unsigned long V_257 ,
struct V_9 * V_10 )
{
unsigned long V_258 ;
if ( ( V_2 -> V_79 ) & V_259 && V_10 -> V_99 )
V_258 = V_10 -> V_114 ;
else
V_258 = V_10 -> V_113 ;
F_25 ( L_73 ,
V_257 , V_2 -> V_249 , V_258 ) ;
if ( F_162 ( V_257 , V_2 -> V_249 + V_258 ) &&
! ( V_2 -> V_79 & V_260 ) &&
! ( V_2 -> V_95 [ 0 ] & 0x01 ) ) {
F_25 ( L_74 ) ;
F_54 ( V_10 , V_2 ) ;
F_3 ( V_2 ) ;
} else {
if ( ( V_2 -> V_172 == V_244 ||
V_2 -> V_172 == V_243 ) &&
F_163 ( V_257 , V_2 -> V_250 +
V_10 -> V_110 ) ) {
V_2 -> V_250 = V_57 ;
V_2 -> V_252 = 0 ;
if ( V_2 -> V_172 == V_244 )
F_66 ( V_10 , V_261 ,
V_2 -> V_95 ,
V_2 -> V_98 ,
NULL ) ;
}
if ( V_2 -> V_172 == V_240 &&
F_163 ( V_257 , V_2 -> V_250 +
V_10 -> V_117 ) ) {
F_1 ( V_2 ) ;
return true ;
}
}
return false ;
}
static void V_232 ( struct V_262 * V_263 )
{
unsigned long V_79 ;
struct V_9 * V_10 =
F_164 ( V_263 , struct V_9 , V_231 . V_263 ) ;
struct V_183 * V_185 , * V_203 ;
struct V_1 * V_2 ;
unsigned long V_257 ;
int V_91 ;
F_25 ( L_75 , V_10 ) ;
V_257 = V_57 ;
V_264:
F_52 ( & V_10 -> V_102 , V_79 ) ;
for ( V_91 = 0 ; V_91 < V_191 ; V_91 ++ ) {
F_151 (entry, node, next,
&priv->lec_arp_tables[i], next) {
if ( F_161 ( V_2 , V_257 , V_10 ) ) {
struct V_4 * V_5 ;
struct V_46 * V_47 = V_2 -> V_47 ;
F_55 ( & V_10 -> V_102 ,
V_79 ) ;
while ( ( V_5 = F_44 ( & V_2 -> V_81 ) ) )
F_17 ( V_47 , V_5 ) ;
V_2 -> V_249 = V_57 ;
V_2 -> V_172 = V_174 ;
F_3 ( V_2 ) ;
goto V_264;
}
}
}
F_55 ( & V_10 -> V_102 , V_79 ) ;
F_138 ( & V_10 -> V_231 , V_233 ) ;
}
static struct V_46 * F_42 ( struct V_9 * V_10 ,
const unsigned char * V_265 ,
int V_62 ,
struct V_1 * * V_266 )
{
unsigned long V_79 ;
struct V_1 * V_2 ;
struct V_46 * V_267 ;
if ( V_265 [ 0 ] & 0x01 ) {
switch ( V_10 -> V_118 ) {
case 1 :
return V_10 -> V_253 ;
case 2 :
if ( ! F_134 ( V_265 , V_36 ) )
return V_10 -> V_253 ;
break;
default:
break;
}
}
F_52 ( & V_10 -> V_102 , V_79 ) ;
V_2 = F_53 ( V_10 , V_265 ) ;
if ( V_2 ) {
if ( V_2 -> V_172 == V_174 ) {
V_2 -> V_249 = V_57 ;
F_1 ( V_2 ) ;
* V_266 = V_2 ;
V_267 = V_2 -> V_47 ;
goto V_84;
}
if ( V_2 -> V_172 == V_243 )
V_2 -> V_251 = 0 ;
if ( V_2 -> V_172 != V_240 &&
V_2 -> V_252 <
V_10 -> V_108 ) {
V_2 -> V_252 ++ ;
F_25 ( L_76 ) ;
V_267 = V_10 -> V_253 ;
goto V_84;
}
F_1 ( V_2 ) ;
* V_266 = V_2 ;
F_25 ( L_77 , V_2 -> V_172 ,
V_2 -> V_47 ) ;
V_267 = NULL ;
} else {
V_2 = F_153 ( V_10 , V_265 ) ;
F_25 ( L_78 ) ;
if ( ! V_2 ) {
V_267 = V_10 -> V_253 ;
goto V_84;
}
F_141 ( V_10 , V_2 ) ;
V_2 -> V_252 = 1 ;
V_2 -> V_172 = V_243 ;
V_2 -> V_251 = 1 ;
V_2 -> V_249 = V_2 -> V_250 = V_57 ;
V_2 -> V_62 = V_62 ;
if ( V_2 -> V_62 )
F_66 ( V_10 , V_256 , V_265 , NULL ,
NULL ) ;
else
F_66 ( V_10 , V_227 , V_265 , NULL , NULL ) ;
V_2 -> V_239 . V_268 = V_57 + ( 1 * V_111 ) ;
V_2 -> V_239 . V_269 = V_255 ;
F_165 ( & V_2 -> V_239 ) ;
V_267 = V_10 -> V_253 ;
}
V_84:
F_55 ( & V_10 -> V_102 , V_79 ) ;
return V_267 ;
}
static int
F_50 ( struct V_9 * V_10 , const unsigned char * V_98 ,
unsigned long V_270 )
{
unsigned long V_79 ;
struct V_183 * V_185 , * V_203 ;
struct V_1 * V_2 ;
int V_91 ;
F_25 ( L_71 ) ;
F_52 ( & V_10 -> V_102 , V_79 ) ;
for ( V_91 = 0 ; V_91 < V_191 ; V_91 ++ ) {
F_151 (entry, node, next,
&priv->lec_arp_tables[i], next) {
if ( ! memcmp ( V_98 , V_2 -> V_98 , V_129 ) &&
( V_270 ||
! ( V_2 -> V_79 & V_260 ) ) ) {
F_54 ( V_10 , V_2 ) ;
F_3 ( V_2 ) ;
}
F_55 ( & V_10 -> V_102 , V_79 ) ;
return 0 ;
}
}
F_55 ( & V_10 -> V_102 , V_79 ) ;
return - 1 ;
}
static void
F_56 ( struct V_9 * V_10 , const unsigned char * V_95 ,
const unsigned char * V_98 , unsigned long V_271 ,
unsigned int V_105 )
{
unsigned long V_79 ;
struct V_183 * V_185 , * V_203 ;
struct V_1 * V_2 , * V_92 ;
int V_91 ;
F_25 ( L_79 ,
( V_105 ) ? L_80 : L_7 , V_95 ) ;
F_52 ( & V_10 -> V_102 , V_79 ) ;
V_2 = F_53 ( V_10 , V_95 ) ;
if ( V_2 == NULL && V_105 )
goto V_84;
if ( ! F_73 ( & V_10 -> V_144 ) ) {
F_151 (entry, node, next,
&priv->lec_arp_empty_ones, next) {
if ( memcmp ( V_2 -> V_98 , V_98 , V_129 ) == 0 ) {
F_144 ( & V_2 -> V_203 ) ;
F_145 ( & V_2 -> V_239 ) ;
V_92 = F_53 ( V_10 , V_95 ) ;
if ( V_92 ) {
F_145 ( & V_92 -> V_239 ) ;
V_92 -> V_172 = V_174 ;
memcpy ( V_92 -> V_98 , V_98 , V_129 ) ;
V_92 -> V_47 = V_2 -> V_47 ;
V_92 -> V_234 = V_2 -> V_234 ;
V_92 -> V_249 = V_57 ;
F_145 ( & V_2 -> V_239 ) ;
F_3 ( V_2 ) ;
V_2 = V_92 ;
} else {
V_2 -> V_172 = V_174 ;
memcpy ( V_2 -> V_95 , V_95 , V_41 ) ;
V_2 -> V_249 = V_57 ;
F_141 ( V_10 , V_2 ) ;
}
if ( V_271 )
V_2 -> V_79 |= V_259 ;
else
V_2 -> V_79 &= ~ V_259 ;
F_25 ( L_81 ) ;
F_149 ( V_10 ) ;
goto V_84;
}
}
}
V_2 = F_53 ( V_10 , V_95 ) ;
if ( ! V_2 ) {
V_2 = F_153 ( V_10 , V_95 ) ;
if ( ! V_2 )
goto V_84;
V_2 -> V_172 = V_242 ;
F_141 ( V_10 , V_2 ) ;
}
memcpy ( V_2 -> V_98 , V_98 , V_129 ) ;
F_145 ( & V_2 -> V_239 ) ;
for ( V_91 = 0 ; V_91 < V_191 ; V_91 ++ ) {
F_146 (tmp, node,
&priv->lec_arp_tables[i], next) {
if ( V_2 != V_92 &&
! memcmp ( V_92 -> V_98 , V_98 , V_129 ) ) {
if ( V_92 -> V_172 > V_244 ) {
V_2 -> V_47 = V_92 -> V_47 ;
V_2 -> V_234 = V_92 -> V_234 ;
}
V_2 -> V_172 = V_92 -> V_172 ;
break;
}
}
}
if ( V_271 )
V_2 -> V_79 |= V_259 ;
else
V_2 -> V_79 &= ~ V_259 ;
if ( V_2 -> V_172 == V_243 || V_2 -> V_172 == V_242 ) {
V_2 -> V_172 = V_244 ;
F_66 ( V_10 , V_261 , V_2 -> V_95 , V_98 , NULL ) ;
}
F_25 ( L_82 ) ;
F_149 ( V_10 ) ;
V_84:
F_55 ( & V_10 -> V_102 , V_79 ) ;
}
static void
F_85 ( struct V_9 * V_10 , const struct V_152 * V_153 ,
struct V_46 * V_47 ,
void (* V_234) ( struct V_46 * V_47 , struct V_4 * V_5 ) )
{
unsigned long V_79 ;
struct V_183 * V_185 ;
struct V_1 * V_2 ;
int V_91 , V_272 = 0 ;
F_52 ( & V_10 -> V_102 , V_79 ) ;
if ( V_153 -> V_273 == 2 ) {
F_25 ( L_83 ) ;
#if 0
entry = lec_arp_find(priv, bus_mac);
if (!entry) {
pr_info("LEC_ARP: Multicast entry not found!\n");
goto out;
}
memcpy(entry->atm_addr, ioc_data->atm_addr, ATM_ESA_LEN);
entry->recv_vcc = vcc;
entry->old_recv_push = old_push;
#endif
V_2 = F_153 ( V_10 , V_36 ) ;
if ( V_2 == NULL )
goto V_84;
F_145 ( & V_2 -> V_239 ) ;
memcpy ( V_2 -> V_98 , V_153 -> V_98 , V_129 ) ;
V_2 -> V_177 = V_47 ;
V_2 -> V_236 = V_234 ;
F_143 ( & V_2 -> V_203 , & V_10 -> V_195 ) ;
goto V_84;
} else if ( V_153 -> V_273 == 1 ) {
F_25 ( L_84 ,
V_153 -> V_98 [ 0 ] , V_153 -> V_98 [ 1 ] ,
V_153 -> V_98 [ 2 ] , V_153 -> V_98 [ 3 ] ,
V_153 -> V_98 [ 4 ] , V_153 -> V_98 [ 5 ] ,
V_153 -> V_98 [ 6 ] , V_153 -> V_98 [ 7 ] ,
V_153 -> V_98 [ 8 ] , V_153 -> V_98 [ 9 ] ,
V_153 -> V_98 [ 10 ] , V_153 -> V_98 [ 11 ] ,
V_153 -> V_98 [ 12 ] , V_153 -> V_98 [ 13 ] ,
V_153 -> V_98 [ 14 ] , V_153 -> V_98 [ 15 ] ,
V_153 -> V_98 [ 16 ] , V_153 -> V_98 [ 17 ] ,
V_153 -> V_98 [ 18 ] , V_153 -> V_98 [ 19 ] ) ;
V_2 = F_153 ( V_10 , V_36 ) ;
if ( V_2 == NULL )
goto V_84;
memcpy ( V_2 -> V_98 , V_153 -> V_98 , V_129 ) ;
memset ( V_2 -> V_95 , 0 , V_41 ) ;
V_2 -> V_177 = V_47 ;
V_2 -> V_236 = V_234 ;
V_2 -> V_172 = V_242 ;
V_2 -> V_239 . V_268 = V_57 + V_10 -> V_171 ;
V_2 -> V_239 . V_269 = F_160 ;
F_143 ( & V_2 -> V_203 , & V_10 -> V_194 ) ;
F_165 ( & V_2 -> V_239 ) ;
F_149 ( V_10 ) ;
goto V_84;
}
F_25 ( L_85 ,
V_153 -> V_98 [ 0 ] , V_153 -> V_98 [ 1 ] ,
V_153 -> V_98 [ 2 ] , V_153 -> V_98 [ 3 ] ,
V_153 -> V_98 [ 4 ] , V_153 -> V_98 [ 5 ] ,
V_153 -> V_98 [ 6 ] , V_153 -> V_98 [ 7 ] ,
V_153 -> V_98 [ 8 ] , V_153 -> V_98 [ 9 ] ,
V_153 -> V_98 [ 10 ] , V_153 -> V_98 [ 11 ] ,
V_153 -> V_98 [ 12 ] , V_153 -> V_98 [ 13 ] ,
V_153 -> V_98 [ 14 ] , V_153 -> V_98 [ 15 ] ,
V_153 -> V_98 [ 16 ] , V_153 -> V_98 [ 17 ] ,
V_153 -> V_98 [ 18 ] , V_153 -> V_98 [ 19 ] ) ;
for ( V_91 = 0 ; V_91 < V_191 ; V_91 ++ ) {
F_146 (entry, node,
&priv->lec_arp_tables[i], next) {
if ( memcmp
( V_153 -> V_98 , V_2 -> V_98 ,
V_129 ) == 0 ) {
F_25 ( L_86 ) ;
F_25 ( L_87 ,
V_2 -> V_47 ? V_2 -> V_47 -> V_86 : 0 ,
V_2 -> V_177 ? V_2 -> V_177 ->
V_86 : 0 ) ;
V_272 = 1 ;
F_145 ( & V_2 -> V_239 ) ;
V_2 -> V_47 = V_47 ;
V_2 -> V_234 = V_234 ;
if ( V_2 -> V_172 == V_244 ) {
if ( V_10 -> V_108
== 0 )
V_2 -> V_172 =
V_174 ;
else {
V_2 -> V_250 = V_57 ;
V_2 -> V_172 =
V_240 ;
#if 0
send_to_lecd(priv, l_flush_xmt,
NULL,
entry->atm_addr,
NULL);
#endif
}
} else {
;
}
}
}
}
if ( V_272 ) {
F_25 ( L_88 ) ;
F_149 ( V_10 ) ;
goto V_84;
}
V_2 = F_153 ( V_10 , V_36 ) ;
if ( ! V_2 )
goto V_84;
V_2 -> V_47 = V_47 ;
V_2 -> V_234 = V_234 ;
memcpy ( V_2 -> V_98 , V_153 -> V_98 , V_129 ) ;
memset ( V_2 -> V_95 , 0 , V_41 ) ;
V_2 -> V_172 = V_242 ;
F_143 ( & V_2 -> V_203 , & V_10 -> V_144 ) ;
V_2 -> V_239 . V_268 = V_57 + V_10 -> V_171 ;
V_2 -> V_239 . V_269 = F_160 ;
F_165 ( & V_2 -> V_239 ) ;
F_25 ( L_88 ) ;
F_149 ( V_10 ) ;
V_84:
F_55 ( & V_10 -> V_102 , V_79 ) ;
}
static void F_51 ( struct V_9 * V_10 , unsigned long V_274 )
{
unsigned long V_79 ;
struct V_183 * V_185 ;
struct V_1 * V_2 ;
int V_91 ;
F_25 ( L_89 , V_274 ) ;
V_264:
F_52 ( & V_10 -> V_102 , V_79 ) ;
for ( V_91 = 0 ; V_91 < V_191 ; V_91 ++ ) {
F_146 (entry, node,
&priv->lec_arp_tables[i], next) {
if ( V_2 -> V_275 == V_274 &&
V_2 -> V_172 == V_240 ) {
struct V_4 * V_5 ;
struct V_46 * V_47 = V_2 -> V_47 ;
F_1 ( V_2 ) ;
F_55 ( & V_10 -> V_102 ,
V_79 ) ;
while ( ( V_5 = F_44 ( & V_2 -> V_81 ) ) )
F_17 ( V_47 , V_5 ) ;
V_2 -> V_249 = V_57 ;
V_2 -> V_172 = V_174 ;
F_3 ( V_2 ) ;
F_25 ( L_90 ) ;
goto V_264;
}
}
}
F_55 ( & V_10 -> V_102 , V_79 ) ;
F_149 ( V_10 ) ;
}
static void
F_59 ( struct V_9 * V_10 ,
const unsigned char * V_98 , unsigned long V_274 )
{
unsigned long V_79 ;
struct V_183 * V_185 ;
struct V_1 * V_2 ;
int V_91 ;
F_52 ( & V_10 -> V_102 , V_79 ) ;
for ( V_91 = 0 ; V_91 < V_191 ; V_91 ++ )
F_146 (entry, node,
&priv->lec_arp_tables[i], next) {
if ( ! memcmp ( V_98 , V_2 -> V_98 , V_129 ) ) {
V_2 -> V_275 = V_274 ;
F_25 ( L_91 ,
V_274 , V_2 ) ;
}
}
F_55 ( & V_10 -> V_102 , V_79 ) ;
}
static int F_87 ( struct V_9 * V_10 , struct V_46 * V_47 )
{
unsigned long V_79 ;
unsigned char V_95 [] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff
} ;
struct V_1 * V_276 ;
struct V_87 * V_88 ;
int V_209 = 0 ;
V_88 = F_84 ( sizeof( struct V_87 ) , V_157 ) ;
if ( ! V_88 )
return - V_158 ;
V_88 -> V_89 = 0 ;
V_88 -> V_149 = V_47 -> V_159 ;
V_47 -> V_160 = V_88 ;
V_47 -> V_159 = F_79 ;
F_52 ( & V_10 -> V_102 , V_79 ) ;
V_276 = F_153 ( V_10 , V_95 ) ;
if ( ! V_276 ) {
V_47 -> V_159 = V_88 -> V_149 ;
F_5 ( V_88 ) ;
V_209 = - V_158 ;
goto V_84;
}
memcpy ( V_276 -> V_98 , V_47 -> V_277 . V_278 . V_279 , V_129 ) ;
V_276 -> V_172 = V_174 ;
V_276 -> V_79 |= V_260 ;
V_276 -> V_47 = V_47 ;
V_276 -> V_234 = V_47 -> V_161 ;
V_47 -> V_161 = F_70 ;
V_10 -> V_253 = V_47 ;
F_141 ( V_10 , V_276 ) ;
V_84:
F_55 ( & V_10 -> V_102 , V_79 ) ;
return V_209 ;
}
static void F_71 ( struct V_9 * V_10 , struct V_46 * V_47 )
{
unsigned long V_79 ;
struct V_183 * V_185 , * V_203 ;
struct V_1 * V_2 ;
int V_91 ;
F_25 ( L_92 , V_47 -> V_85 , V_47 -> V_86 ) ;
F_149 ( V_10 ) ;
F_52 ( & V_10 -> V_102 , V_79 ) ;
for ( V_91 = 0 ; V_91 < V_191 ; V_91 ++ ) {
F_151 (entry, node, next,
&priv->lec_arp_tables[i], next) {
if ( V_47 == V_2 -> V_47 ) {
F_54 ( V_10 , V_2 ) ;
F_3 ( V_2 ) ;
if ( V_10 -> V_253 == V_47 )
V_10 -> V_253 = NULL ;
}
}
}
F_151 (entry, node, next,
&priv->lec_arp_empty_ones, next) {
if ( V_2 -> V_47 == V_47 ) {
F_139 ( V_2 ) ;
F_145 ( & V_2 -> V_239 ) ;
F_144 ( & V_2 -> V_203 ) ;
F_3 ( V_2 ) ;
}
}
F_151 (entry, node, next,
&priv->lec_no_forward, next) {
if ( V_2 -> V_177 == V_47 ) {
F_139 ( V_2 ) ;
F_145 ( & V_2 -> V_239 ) ;
F_144 ( & V_2 -> V_203 ) ;
F_3 ( V_2 ) ;
}
}
F_151 (entry, node, next, &priv->mcast_fwds, next) {
if ( V_2 -> V_177 == V_47 ) {
F_139 ( V_2 ) ;
F_144 ( & V_2 -> V_203 ) ;
F_3 ( V_2 ) ;
}
}
F_55 ( & V_10 -> V_102 , V_79 ) ;
F_149 ( V_10 ) ;
}
static void
F_74 ( struct V_9 * V_10 ,
struct V_46 * V_47 , struct V_4 * V_5 )
{
unsigned long V_79 ;
struct V_183 * V_185 , * V_203 ;
struct V_1 * V_2 , * V_92 ;
struct V_58 * V_280 = (struct V_58 * ) V_5 -> V_11 ;
unsigned char * V_139 ;
#ifdef F_24
struct V_141 * V_281 = (struct V_141 * ) V_5 -> V_11 ;
if ( V_10 -> V_72 )
V_139 = V_281 -> V_142 ;
else
#endif
V_139 = V_280 -> V_142 ;
F_52 ( & V_10 -> V_102 , V_79 ) ;
F_151 (entry, node, next,
&priv->lec_arp_empty_ones, next) {
if ( V_47 == V_2 -> V_47 ) {
F_145 ( & V_2 -> V_239 ) ;
memcpy ( V_2 -> V_95 , V_139 , V_41 ) ;
V_2 -> V_172 = V_174 ;
V_2 -> V_249 = V_57 ;
V_92 = F_53 ( V_10 , V_139 ) ;
if ( V_92 ) {
F_54 ( V_10 , V_92 ) ;
F_3 ( V_92 ) ;
}
F_144 ( & V_2 -> V_203 ) ;
F_141 ( V_10 , V_2 ) ;
goto V_84;
}
}
F_25 ( L_93 ) ;
V_84:
F_55 ( & V_10 -> V_102 , V_79 ) ;
}

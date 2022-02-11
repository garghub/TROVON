static inline void F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_2 -> V_4 . V_5 && V_2 -> V_4 . V_5 -> V_6 . V_7 . F_1 )
V_2 -> V_4 . V_5 -> V_6 . V_7 . F_1 ( V_2 -> V_4 . V_5 , V_3 ) ;
}
static inline void F_2 ( struct V_1 * V_2 ,
int V_8 , int V_9 )
{
char * V_10 = L_1 ;
switch ( V_9 ) {
case - V_11 :
V_10 = L_2 ;
break;
case - V_12 :
V_10 = L_3 ;
break;
case - V_13 :
V_10 = L_4 ;
break;
case - V_14 :
V_10 = L_5 ;
break;
case - V_15 :
V_10 = L_6 ;
break;
case - V_16 :
V_10 = L_7 ;
break;
case - V_17 :
V_10 = L_8 ;
break;
case - V_18 :
V_10 = L_9 ;
break;
}
if ( V_8 < 0 ) {
F_3 ( L_10 , V_9 , V_10 ) ;
} else {
F_3 ( L_11 ,
V_8 , V_9 , V_10 ) ;
}
}
static int F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 & V_20 ) {
F_5 ( L_12 ) ;
return - V_21 ;
}
if ( V_2 -> V_19 & V_22 ) {
F_5 ( L_13
L_14 ) ;
return - V_23 ;
}
return 0 ;
}
static void F_6 ( struct V_24 * V_24 )
{
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_1 * V_2 = F_7 ( V_26 , struct V_1 , V_28 ) ;
unsigned long V_29 = 0 ;
int V_30 ;
switch ( V_24 -> V_9 ) {
case 0 :
case - V_31 :
break;
case - V_12 :
case - V_11 :
case - V_32 :
F_3 ( L_15 ) ;
return;
default:
F_3 ( L_16 , V_24 -> V_9 ) ;
break;
}
F_8 ( & V_2 -> V_33 , V_29 ) ;
V_2 -> V_34 . V_35 ( V_2 , V_24 ) ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
for ( V_30 = 0 ; V_30 < V_24 -> V_36 ; V_30 ++ ) {
V_24 -> V_37 [ V_30 ] . V_9 = 0 ;
V_24 -> V_37 [ V_30 ] . V_38 = 0 ;
}
V_24 -> V_9 = 0 ;
V_24 -> V_9 = F_10 ( V_24 , V_39 ) ;
if ( V_24 -> V_9 ) {
F_3 ( L_17 ,
V_24 -> V_9 ) ;
}
V_2 -> V_40 = V_41 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_24 * V_24 ;
int V_30 ;
F_3 ( L_18 ) ;
V_2 -> V_34 . V_42 = - 1 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_34 . V_43 ; V_30 ++ ) {
V_24 = V_2 -> V_34 . V_24 [ V_30 ] ;
if ( V_24 ) {
if ( ! F_12 () )
F_13 ( V_24 ) ;
else
F_14 ( V_24 ) ;
if ( V_2 -> V_34 . V_44 [ V_30 ] ) {
F_15 ( V_2 -> V_45 ,
V_24 -> V_46 ,
V_2 -> V_34 . V_44 [ V_30 ] ,
V_24 -> V_47 ) ;
}
F_16 ( V_24 ) ;
V_2 -> V_34 . V_24 [ V_30 ] = NULL ;
}
V_2 -> V_34 . V_44 [ V_30 ] = NULL ;
}
F_17 ( V_2 -> V_34 . V_24 ) ;
F_17 ( V_2 -> V_34 . V_44 ) ;
V_2 -> V_34 . V_24 = NULL ;
V_2 -> V_34 . V_44 = NULL ;
V_2 -> V_34 . V_43 = 0 ;
V_2 -> V_40 = V_48 ;
}
static int F_18 ( struct V_1 * V_2 , int V_49 ,
int V_43 , int V_50 ,
int (* V_35) ( struct V_1 * V_2 , struct V_24 * V_24 ) )
{
struct V_25 * V_26 = & V_2 -> V_28 ;
int V_30 ;
int V_51 , V_52 ;
struct V_24 * V_24 ;
int V_53 , V_54 ;
int V_55 ;
F_3 ( L_19 ) ;
V_2 -> V_34 . V_35 = V_35 ;
V_2 -> V_34 . V_43 = V_43 ;
V_2 -> V_34 . V_24 = F_19 ( sizeof( void * ) * V_43 , V_56 ) ;
if ( ! V_2 -> V_34 . V_24 ) {
F_3 ( L_20 ) ;
return - V_57 ;
}
V_2 -> V_34 . V_44 = F_19 ( sizeof( void * ) * V_43 ,
V_56 ) ;
if ( ! V_2 -> V_34 . V_44 ) {
F_3 ( L_21 ) ;
F_17 ( V_2 -> V_34 . V_24 ) ;
return - V_57 ;
}
V_2 -> V_34 . V_50 = V_50 ;
V_2 -> V_34 . V_58 = NULL ;
V_51 = V_49 * V_2 -> V_34 . V_50 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_34 . V_43 ; V_30 ++ ) {
V_24 = F_20 ( V_49 , V_56 ) ;
if ( ! V_24 ) {
F_3 ( L_22 , V_30 ) ;
F_11 ( V_2 ) ;
return - V_57 ;
}
V_2 -> V_34 . V_24 [ V_30 ] = V_24 ;
V_2 -> V_34 . V_44 [ V_30 ] = F_21 ( V_2 -> V_45 ,
V_51 , V_56 , & V_24 -> V_47 ) ;
if ( ! V_2 -> V_34 . V_44 [ V_30 ] ) {
F_22 ( L_23
L_24 ,
V_51 , V_30 ,
F_23 () ? L_25 : L_26 ) ;
F_11 ( V_2 ) ;
return - V_57 ;
}
memset ( V_2 -> V_34 . V_44 [ V_30 ] , 0 , V_51 ) ;
V_52 = F_24 ( V_2 -> V_45 ,
V_2 -> V_59 ) ,
F_25 ( V_24 , V_2 -> V_45 , V_52 ,
V_2 -> V_34 . V_44 [ V_30 ] , V_51 ,
F_6 , V_26 , 1 ) ;
V_24 -> V_36 = V_49 ;
V_24 -> V_60 = V_61 | V_62 ;
V_54 = 0 ;
for ( V_53 = 0 ; V_53 < V_49 ; V_53 ++ ) {
V_24 -> V_37 [ V_53 ] . V_63 = V_54 ;
V_24 -> V_37 [ V_53 ] . V_64 =
V_2 -> V_34 . V_50 ;
V_54 += V_2 -> V_34 . V_50 ;
}
}
for ( V_30 = 0 ; V_30 < V_2 -> V_34 . V_43 ; V_30 ++ ) {
V_55 = F_10 ( V_2 -> V_34 . V_24 [ V_30 ] , V_39 ) ;
if ( V_55 ) {
F_3 ( L_27 ,
V_30 , V_55 ) ;
F_11 ( V_2 ) ;
return V_55 ;
}
}
return 0 ;
}
static inline void F_26 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_65 * V_58 )
{
struct V_66 * V_67 = & V_58 -> V_67 ;
struct V_68 * V_69 = V_67 -> V_70 . V_68 ;
F_3 ( L_28 , V_58 , V_58 -> V_71 ) ;
if ( V_69 -> type == V_72 )
V_67 -> V_73 = V_2 -> V_74 ++ ;
else
V_67 -> V_73 = V_2 -> V_75 ++ ;
V_67 -> V_76 = V_77 ;
V_67 -> V_70 . V_78 = F_27 () ;
F_28 ( & V_67 -> V_70 , V_79 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_65 * V_58 ,
unsigned char * V_80 ,
unsigned char * V_81 , unsigned long V_82 )
{
void * V_83 , * V_84 , * V_85 ;
int V_86 , V_87 , V_63 , V_88 , V_89 ;
int V_90 = V_2 -> V_91 << 1 ;
if ( V_82 == 0 )
return;
if ( V_26 -> V_92 + V_82 > V_58 -> V_64 )
V_82 = V_58 -> V_64 - V_26 -> V_92 ;
V_85 = V_80 ;
V_89 = V_82 ;
if ( V_58 -> V_71 )
V_83 = V_81 ;
else
V_83 = V_81 + V_90 ;
V_86 = V_26 -> V_92 / V_90 ;
V_87 = V_26 -> V_92 % V_90 ;
V_63 = V_86 * V_90 * 2 + V_87 ;
V_84 = V_83 + V_63 ;
V_88 = V_90 - V_87 ;
V_88 = V_88 > V_89 ? V_89 : V_88 ;
if ( ( char * ) V_84 + V_88 > ( char * ) V_81 + V_58 -> V_64 ) {
F_3 ( L_29 ,
( ( char * ) V_84 + V_88 ) -
( ( char * ) V_81 + V_58 -> V_64 ) ) ;
V_89 = ( char * ) V_81 + V_58 -> V_64 - ( char * ) V_84 ;
V_88 = V_89 ;
}
if ( V_88 <= 0 )
return;
memcpy ( V_84 , V_85 , V_88 ) ;
V_89 -= V_88 ;
while ( V_89 > 0 ) {
V_84 += V_88 + V_90 ;
V_85 += V_88 ;
if ( V_90 > V_89 )
V_88 = V_89 ;
else
V_88 = V_90 ;
if ( ( char * ) V_84 + V_88 > ( char * ) V_81 +
V_58 -> V_64 ) {
F_3 ( L_30 ,
( ( char * ) V_84 + V_88 ) -
( ( char * ) V_81 + V_58 -> V_64 ) ) ;
V_88 = V_89 = ( char * ) V_81 + V_58 -> V_64 -
( char * ) V_84 ;
}
if ( V_88 <= 0 )
break;
memcpy ( V_84 , V_85 , V_88 ) ;
V_89 -= V_88 ;
}
if ( V_63 > 1440 ) {
if ( V_81 [ 0 ] < 0x60 && V_81 [ 1440 ] < 0x60 )
V_2 -> V_93 = 1 ;
}
V_26 -> V_92 += V_82 ;
}
static inline void F_30 ( struct V_25 * V_26 ,
struct V_65 * * V_58 )
{
struct V_1 * V_2 = F_7 ( V_26 , struct V_1 , V_28 ) ;
if ( F_31 ( & V_26 -> V_94 ) ) {
F_3 ( L_31 ) ;
V_2 -> V_34 . V_58 = NULL ;
* V_58 = NULL ;
return;
}
* V_58 = F_32 ( V_26 -> V_94 . V_95 , struct V_65 , V_96 ) ;
F_33 ( & ( * V_58 ) -> V_96 ) ;
V_26 -> V_92 = 0 ;
( * V_58 ) -> V_97 = ( * V_58 ) -> V_98 ;
V_2 -> V_34 . V_58 = * V_58 ;
return;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_65 * V_58 ,
unsigned char * V_80 ,
unsigned char * V_81 , unsigned long V_82 )
{
unsigned char * V_84 , * V_85 ;
int V_90 ;
int V_30 , V_53 = 0 ;
if ( V_2 == NULL ) {
F_3 ( L_32 ) ;
return;
}
if ( V_26 == NULL ) {
F_3 ( L_33 ) ;
return;
}
if ( V_58 == NULL )
return;
if ( V_80 == NULL ) {
F_3 ( L_34 ) ;
return;
}
if ( V_81 == NULL ) {
F_3 ( L_35 ) ;
return;
}
V_90 = V_2 -> V_99 ;
if ( V_26 -> V_92 + V_82 > V_58 -> V_64 )
V_82 = V_58 -> V_64 - V_26 -> V_92 ;
V_85 = V_80 ;
V_84 = V_81 + ( V_26 -> V_92 / 2 ) ;
if ( V_58 -> V_71 == 0 )
V_84 += V_90 * V_2 -> V_100 ;
for ( V_30 = 0 ; V_30 < V_82 ; V_30 += 2 )
V_84 [ V_53 ++ ] = V_85 [ V_30 + 1 ] ;
V_26 -> V_92 += V_82 ;
}
static inline void F_35 ( struct V_25 * V_26 ,
struct V_65 * * V_58 )
{
struct V_1 * V_2 = F_7 ( V_26 , struct V_1 , V_101 ) ;
if ( F_31 ( & V_26 -> V_94 ) ) {
F_3 ( L_31 ) ;
V_2 -> V_34 . V_102 = NULL ;
* V_58 = NULL ;
return;
}
* V_58 = F_32 ( V_26 -> V_94 . V_95 , struct V_65 , V_96 ) ;
F_33 ( & ( * V_58 ) -> V_96 ) ;
V_26 -> V_92 = 0 ;
( * V_58 ) -> V_97 = ( * V_58 ) -> V_98 ;
V_2 -> V_34 . V_102 = * V_58 ;
return;
}
static inline int F_36 ( struct V_1 * V_2 , struct V_24 * V_24 )
{
struct V_65 * V_58 ;
struct V_65 * V_102 ;
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_25 * V_103 = & V_2 -> V_101 ;
unsigned char * V_81 = NULL ;
unsigned char * V_104 = NULL ;
int V_30 , V_82 = 0 , V_55 = 1 ;
unsigned char * V_80 ;
unsigned char V_105 ;
unsigned int V_106 ;
unsigned int V_89 , V_88 ;
if ( ! V_2 )
return 0 ;
if ( ( V_2 -> V_19 & V_20 ) ||
( V_2 -> V_19 & V_22 ) )
return 0 ;
if ( V_24 -> V_9 < 0 ) {
F_2 ( V_2 , - 1 , V_24 -> V_9 ) ;
if ( V_24 -> V_9 == - V_11 )
return 0 ;
}
V_58 = V_2 -> V_34 . V_58 ;
if ( V_58 != NULL )
V_81 = F_37 ( & V_58 -> V_67 . V_70 , 0 ) ;
V_102 = V_2 -> V_34 . V_102 ;
if ( V_102 != NULL )
V_104 = F_37 ( & V_102 -> V_67 . V_70 , 0 ) ;
for ( V_30 = 0 ; V_30 < V_24 -> V_36 ; V_30 ++ ) {
int V_9 = V_24 -> V_37 [ V_30 ] . V_9 ;
if ( V_9 < 0 ) {
F_2 ( V_2 , V_30 , V_9 ) ;
if ( V_24 -> V_37 [ V_30 ] . V_9 != - V_16 )
continue;
}
if ( V_24 -> V_37 [ V_30 ] . V_38 <= 0 )
continue;
if ( V_24 -> V_37 [ V_30 ] . V_38 >
V_2 -> V_50 ) {
F_3 ( L_36 ) ;
continue;
}
V_80 = V_24 -> V_44 + V_24 -> V_37 [ V_30 ] . V_63 ;
V_105 = V_80 [ 0 ] ;
V_82 = V_24 -> V_37 [ V_30 ] . V_38 - 4 ;
V_80 += 4 ;
if ( V_105 & 0x80 ) {
V_82 -= 4 ;
V_80 += 4 ;
F_3 ( L_37 ,
( V_105 & 0x40 ) ? L_38 : L_39 ) ;
if ( V_105 & 0x40 ) {
if ( V_102 != NULL )
F_26 ( V_2 , V_103 , V_102 ) ;
F_35 ( V_103 , & V_102 ) ;
if ( V_102 == NULL )
V_104 = NULL ;
else
V_104 = F_37 (
& V_102 -> V_67 . V_70 , 0 ) ;
if ( V_58 != NULL )
F_26 ( V_2 , V_26 , V_58 ) ;
F_30 ( V_26 , & V_58 ) ;
if ( V_58 == NULL )
V_81 = NULL ;
else
V_81 = F_37 (
& V_58 -> V_67 . V_70 , 0 ) ;
if ( V_2 -> V_107 )
F_38 ( & V_2 -> V_108 ,
V_109 + ( V_110 / 10 ) ) ;
if ( V_2 -> V_111 )
F_38 ( & V_2 -> V_112 ,
V_109 + ( V_110 / 10 ) ) ;
}
if ( V_58 != NULL ) {
if ( V_105 & 0x40 )
V_58 -> V_71 = 1 ;
else
V_58 -> V_71 = 0 ;
}
if ( V_102 != NULL ) {
if ( V_105 & 0x40 )
V_102 -> V_71 = 1 ;
else
V_102 -> V_71 = 0 ;
}
V_2 -> V_113 = 0 ;
V_103 -> V_92 = 0 ;
V_26 -> V_92 = 0 ;
}
V_106 = V_2 -> V_99 * V_2 -> V_100 * 2 ;
if ( V_2 -> V_113 < V_106 ) {
V_89 = V_106 - V_2 -> V_113 ;
if ( V_82 < V_89 )
V_88 = V_82 ;
else
V_88 = V_89 ;
if ( V_102 != NULL )
F_34 ( V_2 , V_103 , V_102 , V_80 ,
V_104 , V_82 ) ;
V_82 -= V_88 ;
V_80 += V_88 ;
V_2 -> V_113 += V_88 ;
}
if ( V_2 -> V_113 >= V_106 && V_58 != NULL )
F_29 ( V_2 , V_26 , V_58 , V_80 , V_81 , V_82 ) ;
}
return V_55 ;
}
static int F_39 ( struct V_1 * V_2 )
{
#ifdef F_40
struct V_114 * V_115 = V_2 -> V_116 ;
struct V_117 * V_118 ;
struct V_119 * V_120 , * V_121 = NULL ;
int V_122 , V_123 = 0 ;
if ( ! V_115 || ! V_2 -> V_124 )
return 0 ;
F_41 (link, &dev->decoder->links, list) {
if ( V_120 -> V_125 -> V_126 == V_2 -> V_124 ) {
V_121 = V_120 ;
if ( V_120 -> V_29 & V_127 )
V_123 ++ ;
break;
}
}
if ( V_123 == 1 || ! V_121 )
return 0 ;
V_118 = V_121 -> V_118 -> V_126 ;
F_41 (link, &source->links, list) {
struct V_117 * V_125 ;
int V_29 = 0 ;
V_125 = V_120 -> V_125 -> V_126 ;
if ( V_125 == V_2 -> V_124 )
V_29 = V_127 ;
V_122 = F_42 ( V_120 , V_29 ) ;
if ( V_122 ) {
F_43 (
L_40 ,
V_118 -> V_128 , V_125 -> V_128 ,
V_29 ? L_41 : L_42 ,
V_122 ) ;
return V_122 ;
} else
F_3 (
L_43 ,
V_118 -> V_128 , V_125 -> V_128 ,
V_29 ? L_44 : L_42 ) ;
}
#endif
return 0 ;
}
static int F_44 ( struct V_68 * V_129 ,
unsigned int * V_130 , unsigned int * V_131 ,
unsigned int V_132 [] , void * V_133 [] )
{
struct V_1 * V_2 = F_45 ( V_129 ) ;
unsigned long V_134 = V_2 -> V_135 * V_2 -> V_90 ;
if ( * V_131 )
return V_132 [ 0 ] < V_134 ? - V_136 : 0 ;
* V_131 = 1 ;
V_132 [ 0 ] = V_134 ;
F_39 ( V_2 ) ;
return 0 ;
}
static int
F_46 ( struct V_137 * V_67 )
{
struct V_66 * V_138 = F_47 ( V_67 ) ;
struct V_65 * V_58 = F_7 ( V_138 ,
struct V_65 , V_67 ) ;
struct V_1 * V_2 = F_45 ( V_67 -> V_68 ) ;
V_58 -> V_64 = V_2 -> V_135 * V_2 -> V_90 ;
if ( F_48 ( V_67 , 0 ) < V_58 -> V_64 ) {
F_43 ( L_45 ,
V_139 , F_48 ( V_67 , 0 ) , V_58 -> V_64 ) ;
return - V_136 ;
}
F_49 ( & V_58 -> V_67 . V_70 , 0 , V_58 -> V_64 ) ;
return 0 ;
}
static void
F_50 ( struct V_137 * V_67 )
{
struct V_66 * V_138 = F_47 ( V_67 ) ;
struct V_65 * V_58 = F_7 ( V_138 ,
struct V_65 ,
V_67 ) ;
struct V_1 * V_2 = F_45 ( V_67 -> V_68 ) ;
struct V_25 * V_28 = & V_2 -> V_28 ;
unsigned long V_29 = 0 ;
V_58 -> V_98 = F_37 ( V_67 , 0 ) ;
V_58 -> V_64 = F_48 ( V_67 , 0 ) ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
F_51 ( & V_58 -> V_96 , & V_28 -> V_94 ) ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
F_53 ( V_2 , V_140 , 0x01 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_141 )
{
struct V_142 * V_143 ;
int V_122 , V_144 , V_145 ;
F_55 ( 1 , L_46 ) ;
V_143 = F_56 ( V_141 -> V_45 , 0 ) ;
if ( V_143 && V_143 -> V_146 -> V_147 . V_148 != 5 ) {
F_55 ( 1 , L_47 ) ;
V_122 = F_57 ( V_141 -> V_45 , 0 , 5 ) ;
if ( V_122 < 0 ) {
F_5 ( L_48 ) ;
return - V_149 ;
}
}
V_144 = V_141 -> V_135 / 2 + 2 ;
V_145 = V_141 -> V_91 * 2 ;
F_53 ( V_141 , V_150 , 0x00 ) ;
F_53 ( V_141 , 0x106 , 0x00 ) ;
F_53 ( V_141 , 0x110 , 0x00 ) ;
F_53 ( V_141 , 0x111 , 0x00 ) ;
F_53 ( V_141 , 0x114 , V_145 & 0xff ) ;
F_53 ( V_141 , 0x115 , V_145 >> 8 ) ;
F_53 ( V_141 , 0x112 , 0x00 ) ;
F_53 ( V_141 , 0x113 , 0x00 ) ;
F_53 ( V_141 , 0x116 , V_144 & 0xff ) ;
F_53 ( V_141 , 0x117 , V_144 >> 8 ) ;
F_53 ( V_141 , V_151 , 0xb3 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_141 )
{
F_55 ( 1 , L_49 ) ;
F_53 ( V_141 , V_151 , 0x0 ) ;
return 0 ;
}
static void F_59 ( struct V_1 * V_2 )
{
F_55 ( 1 , L_50 ) ;
F_53 ( V_2 , V_151 , 0x0 ) ;
F_60 ( 30 ) ;
F_53 ( V_2 , V_151 , 0xb3 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_122 = 0 ;
V_2 -> V_40 = V_152 ;
if ( V_2 -> V_19 == V_20 )
return - V_21 ;
else if ( V_122 ) {
V_2 -> V_19 = V_22 ;
F_55 ( 1 , L_51 , V_139 ) ;
return V_122 ;
}
return 0 ;
}
int F_62 ( struct V_68 * V_129 , unsigned int V_153 )
{
struct V_1 * V_2 = F_45 ( V_129 ) ;
int V_55 = 0 ;
F_55 ( 1 , L_52 ,
V_2 -> V_154 ) ;
if ( V_129 -> type == V_72 )
V_2 -> V_74 = 0 ;
else
V_2 -> V_75 = 0 ;
if ( V_2 -> V_154 == 0 ) {
F_52 ( V_2 ) ;
V_55 = F_18 ( V_2 , V_155 ,
V_156 , V_2 -> V_50 ,
F_36 ) ;
if ( V_55 < 0 ) {
F_5 ( L_53 ) ;
return V_55 ;
}
if ( V_129 -> type == V_72 ) {
F_63 ( & V_2 -> V_157 , 0 , V_158 ,
V_159 , 1 ) ;
V_2 -> V_107 = 1 ;
F_38 ( & V_2 -> V_108 , V_109 + ( V_110 / 10 ) ) ;
} else if ( V_129 -> type == V_160 ) {
V_2 -> V_111 = 1 ;
F_38 ( & V_2 -> V_112 , V_109 + ( V_110 / 10 ) ) ;
}
}
V_2 -> V_154 ++ ;
return V_55 ;
}
static void F_64 ( struct V_68 * V_129 )
{
struct V_1 * V_2 = F_45 ( V_129 ) ;
struct V_25 * V_28 = & V_2 -> V_28 ;
unsigned long V_29 = 0 ;
F_55 ( 1 , L_54 , V_2 -> V_154 ) ;
if ( V_2 -> V_154 -- == 1 )
F_11 ( V_2 ) ;
F_63 ( & V_2 -> V_157 , 0 , V_158 , V_159 , 0 ) ;
V_2 -> V_107 = 0 ;
F_65 ( & V_2 -> V_108 ) ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_34 . V_58 != NULL ) {
F_28 ( & V_2 -> V_34 . V_58 -> V_67 . V_70 ,
V_161 ) ;
V_2 -> V_34 . V_58 = NULL ;
}
while ( ! F_31 ( & V_28 -> V_94 ) ) {
struct V_65 * V_58 ;
V_58 = F_32 ( V_28 -> V_94 . V_95 , struct V_65 , V_96 ) ;
F_28 ( & V_58 -> V_67 . V_70 , V_161 ) ;
F_33 ( & V_58 -> V_96 ) ;
}
F_9 ( & V_2 -> V_33 , V_29 ) ;
}
void F_66 ( struct V_68 * V_129 )
{
struct V_1 * V_2 = F_45 ( V_129 ) ;
struct V_25 * V_101 = & V_2 -> V_101 ;
unsigned long V_29 = 0 ;
F_55 ( 1 , L_55 ,
V_2 -> V_154 ) ;
if ( V_2 -> V_154 -- == 1 )
F_11 ( V_2 ) ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_34 . V_102 != NULL ) {
F_28 ( & V_2 -> V_34 . V_102 -> V_67 . V_70 ,
V_161 ) ;
V_2 -> V_34 . V_102 = NULL ;
}
while ( ! F_31 ( & V_101 -> V_94 ) ) {
struct V_65 * V_58 ;
V_58 = F_32 ( V_101 -> V_94 . V_95 , struct V_65 , V_96 ) ;
F_33 ( & V_58 -> V_96 ) ;
F_28 ( & V_58 -> V_67 . V_70 , V_161 ) ;
}
F_9 ( & V_2 -> V_33 , V_29 ) ;
V_2 -> V_111 = 0 ;
F_65 ( & V_2 -> V_112 ) ;
}
void F_67 ( struct V_1 * V_2 )
{
F_55 ( 1 , L_56 ) ;
F_68 ( & V_162 ) ;
F_69 ( & V_2 -> V_163 ) ;
F_69 ( & V_2 -> V_164 ) ;
F_70 ( & V_162 ) ;
}
static void F_71 ( unsigned long V_165 )
{
struct V_1 * V_2 = (struct V_1 * ) V_165 ;
struct V_25 * V_26 = & V_2 -> V_28 ;
struct V_65 * V_58 ;
unsigned char * V_166 ;
unsigned long V_29 = 0 ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
V_58 = V_2 -> V_34 . V_58 ;
if ( V_58 != NULL ) {
V_166 = F_37 ( & V_58 -> V_67 . V_70 , 0 ) ;
memset ( V_166 , 0x00 , V_58 -> V_64 ) ;
F_26 ( V_2 , V_26 , V_58 ) ;
}
F_30 ( V_26 , & V_58 ) ;
if ( V_2 -> V_107 == 1 )
F_38 ( & V_2 -> V_108 , V_109 + ( V_110 / 10 ) ) ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
}
static void F_72 ( unsigned long V_165 )
{
struct V_1 * V_2 = (struct V_1 * ) V_165 ;
struct V_25 * V_26 = & V_2 -> V_101 ;
struct V_65 * V_58 ;
unsigned char * V_167 ;
unsigned long V_29 = 0 ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
V_58 = V_2 -> V_34 . V_102 ;
if ( V_58 != NULL ) {
V_167 = F_37 ( & V_58 -> V_67 . V_70 , 0 ) ;
memset ( V_167 , 0x00 , V_58 -> V_64 ) ;
F_26 ( V_2 , V_26 , V_58 ) ;
}
F_35 ( V_26 , & V_58 ) ;
if ( V_2 -> V_111 == 1 )
F_38 ( & V_2 -> V_112 , V_109 + ( V_110 / 10 ) ) ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
}
static int F_73 ( struct V_168 * V_169 )
{
struct V_1 * V_2 = F_74 ( V_169 ) ;
int V_122 ;
F_55 ( 1 ,
L_57 ,
V_139 , V_2 -> V_170 , V_2 -> V_19 ,
V_2 -> V_154 , V_2 -> V_171 ) ;
if ( F_75 ( & V_2 -> V_172 ) )
return - V_173 ;
V_122 = F_76 ( V_169 ) ;
if ( V_122 ) {
F_3 ( L_58 ,
V_139 , V_122 ) ;
F_70 ( & V_2 -> V_172 ) ;
return V_122 ;
}
if ( V_2 -> V_171 == 0 ) {
F_54 ( V_2 ) ;
F_59 ( V_2 ) ;
V_2 -> V_40 = V_48 ;
V_2 -> V_19 |= V_174 ;
}
V_2 -> V_171 ++ ;
F_70 ( & V_2 -> V_172 ) ;
return V_122 ;
}
static int F_77 ( struct V_168 * V_169 )
{
int V_122 ;
struct V_1 * V_2 = F_74 ( V_169 ) ;
struct V_175 * V_163 = F_78 ( V_169 ) ;
F_55 ( 1 ,
L_57 ,
V_139 , V_2 -> V_170 , V_2 -> V_19 ,
V_2 -> V_154 , V_2 -> V_171 ) ;
F_68 ( & V_2 -> V_172 ) ;
if ( V_163 -> V_176 == V_177 && V_2 -> V_107 ) {
V_2 -> V_107 = 0 ;
F_65 ( & V_2 -> V_108 ) ;
} else if ( V_163 -> V_176 == V_178 &&
V_2 -> V_111 ) {
V_2 -> V_111 = 0 ;
F_65 ( & V_2 -> V_112 ) ;
}
if ( V_2 -> V_19 == V_20 )
goto V_179;
if ( V_2 -> V_171 == 1 ) {
F_63 ( & V_2 -> V_157 , 0 , V_180 , V_181 , 0 ) ;
V_2 -> V_170 = 0 ;
V_122 = F_57 ( V_2 -> V_45 , 0 , 0 ) ;
if ( V_122 < 0 )
F_5 ( L_59 ) ;
}
V_179:
F_79 ( V_169 , NULL ) ;
V_2 -> V_171 -- ;
F_70 ( & V_2 -> V_172 ) ;
return 0 ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_182 V_183 = {
. V_184 = V_2 -> V_185 ,
. type = V_186 ,
} ;
F_55 ( 1 , L_60 , V_139 ,
V_2 -> V_170 , V_2 -> V_19 ) ;
if ( V_2 -> V_170 )
return;
V_2 -> V_170 = 1 ;
F_1 ( V_2 , 1 ) ;
F_63 ( & V_2 -> V_157 , 0 , V_158 , V_187 , V_2 -> V_188 ) ;
F_63 ( & V_2 -> V_157 , 0 , V_189 , V_190 , & V_183 ) ;
F_1 ( V_2 , 0 ) ;
}
static int F_81 ( struct V_1 * V_2 , unsigned int V_191 ,
struct V_192 * V_193 )
{
int V_122 ;
int V_91 = V_193 -> V_194 . V_195 . V_91 ;
int V_135 = V_193 -> V_194 . V_195 . V_135 ;
if ( V_193 -> V_194 . V_195 . V_196 != V_197 )
return - V_136 ;
if ( V_91 != 720 )
V_91 = 720 ;
if ( V_135 != 480 )
V_135 = 480 ;
V_193 -> V_194 . V_195 . V_91 = V_91 ;
V_193 -> V_194 . V_195 . V_135 = V_135 ;
V_193 -> V_194 . V_195 . V_196 = V_197 ;
V_193 -> V_194 . V_195 . V_90 = V_91 * 2 ;
V_193 -> V_194 . V_195 . V_198 = V_91 * V_135 * 2 ;
V_193 -> V_194 . V_195 . V_199 = V_200 ;
V_193 -> V_194 . V_195 . V_76 = V_77 ;
V_193 -> V_194 . V_195 . V_201 = 0 ;
if ( V_191 == V_202 )
return 0 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_135 = V_135 ;
V_2 -> V_203 = V_91 * V_135 * 2 ;
V_2 -> V_204 = V_91 * V_135 ;
V_2 -> V_90 = V_91 * 2 ;
if ( V_2 -> V_40 == V_41 ) {
F_55 ( 1 , L_61 ) ;
V_122 = F_61 ( V_2 ) ;
if ( V_122 != 0 ) {
F_55 ( 1 , L_62 ) ;
return V_122 ;
}
}
F_54 ( V_2 ) ;
return 0 ;
}
static int F_82 ( struct V_168 * V_168 , void * V_201 ,
struct V_205 * V_206 )
{
struct V_175 * V_163 = F_78 ( V_168 ) ;
struct V_1 * V_2 = F_74 ( V_168 ) ;
F_55 ( 1 , L_60 , V_139 ,
V_2 -> V_170 , V_2 -> V_19 ) ;
F_83 ( V_206 -> V_207 , L_63 , sizeof( V_206 -> V_207 ) ) ;
F_83 ( V_206 -> V_208 , V_2 -> V_209 . V_128 , sizeof( V_206 -> V_208 ) ) ;
F_84 ( V_2 -> V_45 , V_206 -> V_210 , sizeof( V_206 -> V_210 ) ) ;
V_206 -> V_211 = V_212 |
V_213 |
V_214 |
V_215 ;
if ( V_163 -> V_176 == V_177 )
V_206 -> V_211 |= V_216 ;
else
V_206 -> V_211 |= V_217 ;
V_206 -> V_218 = V_206 -> V_211 | V_219 |
V_217 | V_216 ;
return 0 ;
}
static int F_85 ( struct V_168 * V_168 , void * V_201 ,
struct V_220 * V_183 )
{
if ( V_183 -> V_221 )
return - V_136 ;
F_55 ( 1 , L_64 , V_139 ) ;
V_183 -> type = V_72 ;
strcpy ( V_183 -> V_222 , L_65 ) ;
V_183 -> V_29 = 0 ;
V_183 -> V_196 = V_197 ;
return 0 ;
}
static int F_86 ( struct V_168 * V_168 , void * V_201 ,
struct V_192 * V_183 )
{
struct V_1 * V_2 = F_74 ( V_168 ) ;
F_55 ( 1 , L_60 , V_139 ,
V_2 -> V_170 , V_2 -> V_19 ) ;
V_183 -> V_194 . V_195 . V_91 = V_2 -> V_91 ;
V_183 -> V_194 . V_195 . V_135 = V_2 -> V_135 ;
V_183 -> V_194 . V_195 . V_196 = V_197 ;
V_183 -> V_194 . V_195 . V_90 = V_2 -> V_90 ;
V_183 -> V_194 . V_195 . V_198 = V_2 -> V_203 ;
V_183 -> V_194 . V_195 . V_199 = V_200 ;
V_183 -> V_194 . V_195 . V_76 = V_77 ;
V_183 -> V_194 . V_195 . V_201 = 0 ;
return 0 ;
}
static int F_87 ( struct V_168 * V_168 , void * V_201 ,
struct V_192 * V_183 )
{
struct V_1 * V_2 = F_74 ( V_168 ) ;
F_55 ( 1 , L_60 , V_139 ,
V_2 -> V_170 , V_2 -> V_19 ) ;
return F_81 ( V_2 , V_202 , V_183 ) ;
}
static int F_88 ( struct V_168 * V_168 , void * V_201 ,
struct V_192 * V_183 )
{
struct V_1 * V_2 = F_74 ( V_168 ) ;
int V_55 ;
F_55 ( 1 , L_60 , V_139 ,
V_2 -> V_170 , V_2 -> V_19 ) ;
V_55 = F_4 ( V_2 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( F_89 ( & V_2 -> V_223 ) ) {
F_5 ( L_66 , V_139 ) ;
V_55 = - V_149 ;
goto V_224;
}
V_55 = F_81 ( V_2 , V_225 , V_183 ) ;
V_224:
return V_55 ;
}
static int F_90 ( struct V_168 * V_168 , void * V_201 , T_1 V_226 )
{
struct V_1 * V_2 = F_74 ( V_168 ) ;
F_55 ( 1 , L_60 , V_139 ,
V_2 -> V_170 , V_2 -> V_19 ) ;
if ( V_226 == V_2 -> V_188 )
return 0 ;
if ( V_2 -> V_154 > 0 )
return - V_149 ;
V_2 -> V_188 = V_226 ;
F_80 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_63 ( & V_2 -> V_157 , 0 , V_158 , V_187 , V_226 ) ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int F_91 ( struct V_168 * V_168 , void * V_201 , T_1 * V_226 )
{
struct V_1 * V_2 = F_74 ( V_168 ) ;
F_55 ( 1 , L_60 , V_139 ,
V_2 -> V_170 , V_2 -> V_19 ) ;
* V_226 = V_2 -> V_188 ;
return 0 ;
}
static int F_92 ( struct V_168 * V_168 , void * V_201 ,
struct V_227 * V_228 )
{
struct V_1 * V_2 = F_74 ( V_168 ) ;
unsigned int V_229 ;
static const char * V_230 [] = {
[ V_231 ] = L_67 ,
[ V_232 ] = L_68 ,
[ V_233 ] = L_69 ,
[ V_234 ] = L_70 ,
[ V_235 ] = L_71 ,
[ V_236 ] = L_72 ,
[ V_237 ] = L_73
} ;
F_55 ( 1 , L_60 , V_139 ,
V_2 -> V_170 , V_2 -> V_19 ) ;
V_229 = V_228 -> V_221 ;
if ( V_229 >= V_238 )
return - V_136 ;
if ( F_93 ( V_229 ) . type == 0 )
return - V_136 ;
V_228 -> V_221 = V_229 ;
strcpy ( V_228 -> V_128 , V_230 [ F_93 ( V_229 ) . type ] ) ;
if ( ( F_93 ( V_229 ) . type == V_235 ) ||
( F_93 ( V_229 ) . type == V_234 ) ) {
V_228 -> type |= V_239 ;
V_228 -> V_240 = 1 ;
} else {
V_228 -> type |= V_241 ;
V_228 -> V_240 = 2 ;
}
V_228 -> V_188 = V_2 -> V_163 . V_242 ;
return 0 ;
}
static int F_94 ( struct V_168 * V_168 , void * V_201 , unsigned int * V_30 )
{
struct V_1 * V_2 = F_74 ( V_168 ) ;
F_55 ( 1 , L_60 , V_139 ,
V_2 -> V_170 , V_2 -> V_19 ) ;
* V_30 = V_2 -> V_243 ;
return 0 ;
}
static void F_95 ( struct V_1 * V_2 , int V_221 )
{
int V_30 ;
F_55 ( 1 , L_60 , V_139 ,
V_2 -> V_170 , V_2 -> V_19 ) ;
switch ( F_93 ( V_221 ) . type ) {
case V_233 :
V_2 -> V_244 = V_233 ;
V_2 -> V_245 = 1 ;
break;
case V_232 :
V_2 -> V_244 = V_232 ;
V_2 -> V_245 = 1 ;
break;
case V_235 :
V_2 -> V_244 = V_235 ;
V_2 -> V_245 = 0 ;
break;
default:
F_55 ( 1 , L_74 ,
F_93 ( V_221 ) . type ) ;
break;
}
F_63 ( & V_2 -> V_157 , 0 , V_158 , V_246 ,
F_93 ( V_221 ) . V_247 , 0 , 0 ) ;
for ( V_30 = 0 ; V_30 < V_238 ; V_30 ++ ) {
int V_248 = 0 ;
if ( F_93 ( V_30 ) . V_249 == NULL )
continue;
if ( V_30 == V_221 )
V_248 = 1 ;
else
V_248 = 0 ;
if ( V_248 ) {
( F_93 ( V_30 ) . V_249 ) ( V_2 , V_248 ) ;
} else {
if ( ( F_93 ( V_30 ) . V_249 ) !=
( ( F_93 ( V_221 ) . V_249 ) ) ) {
( F_93 ( V_30 ) . V_249 ) ( V_2 , V_248 ) ;
}
}
}
F_63 ( & V_2 -> V_157 , 0 , V_250 , V_246 ,
F_93 ( V_221 ) . V_251 , 0 , 0 ) ;
}
static int F_96 ( struct V_168 * V_168 , void * V_201 , unsigned int V_221 )
{
struct V_1 * V_2 = F_74 ( V_168 ) ;
F_55 ( 1 , L_75 , V_139 ,
V_221 ) ;
if ( V_221 >= V_238 )
return - V_136 ;
if ( F_93 ( V_221 ) . type == 0 )
return - V_136 ;
V_2 -> V_243 = V_221 ;
F_95 ( V_2 , V_221 ) ;
return 0 ;
}
static int F_97 ( struct V_168 * V_168 , void * V_201 , struct V_252 * V_253 )
{
if ( V_253 -> V_221 > 1 )
return - V_136 ;
F_55 ( 1 , L_64 , V_139 ) ;
if ( V_253 -> V_221 == 0 )
strcpy ( V_253 -> V_128 , L_71 ) ;
else
strcpy ( V_253 -> V_128 , L_76 ) ;
V_253 -> V_254 = V_255 ;
return 0 ;
}
static int F_98 ( struct V_168 * V_168 , void * V_201 , struct V_252 * V_253 )
{
struct V_1 * V_2 = F_74 ( V_168 ) ;
F_55 ( 1 , L_60 , V_139 ,
V_2 -> V_170 , V_2 -> V_19 ) ;
V_253 -> V_221 = V_2 -> V_245 ;
if ( V_253 -> V_221 == 0 )
strcpy ( V_253 -> V_128 , L_71 ) ;
else
strcpy ( V_253 -> V_128 , L_76 ) ;
V_253 -> V_254 = V_255 ;
return 0 ;
}
static int F_99 ( struct V_168 * V_168 , void * V_201 , const struct V_252 * V_253 )
{
struct V_1 * V_2 = F_74 ( V_168 ) ;
if ( V_253 -> V_221 != V_2 -> V_245 )
return - V_136 ;
F_55 ( 1 , L_60 , V_139 ,
V_2 -> V_170 , V_2 -> V_19 ) ;
return 0 ;
}
static int F_100 ( struct V_168 * V_168 , void * V_201 , struct V_256 * V_257 )
{
struct V_1 * V_2 = F_74 ( V_168 ) ;
if ( V_257 -> V_221 != 0 )
return - V_136 ;
F_55 ( 1 , L_60 , V_139 ,
V_2 -> V_170 , V_2 -> V_19 ) ;
strcpy ( V_257 -> V_128 , L_77 ) ;
F_80 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_63 ( & V_2 -> V_157 , 0 , V_189 , V_258 , V_257 ) ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int F_101 ( struct V_168 * V_168 , void * V_201 ,
const struct V_256 * V_257 )
{
struct V_1 * V_2 = F_74 ( V_168 ) ;
if ( V_257 -> V_221 != 0 )
return - V_136 ;
F_55 ( 1 , L_60 , V_139 ,
V_2 -> V_170 , V_2 -> V_19 ) ;
F_80 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_63 ( & V_2 -> V_157 , 0 , V_189 , V_259 , V_257 ) ;
F_1 ( V_2 , 0 ) ;
F_55 ( 1 , L_78 , V_257 -> signal ,
V_257 -> V_260 ) ;
return 0 ;
}
static int F_102 ( struct V_168 * V_168 , void * V_201 ,
struct V_182 * V_261 )
{
struct V_1 * V_2 = F_74 ( V_168 ) ;
if ( V_261 -> V_189 != 0 )
return - V_136 ;
F_55 ( 1 , L_60 , V_139 ,
V_2 -> V_170 , V_2 -> V_19 ) ;
V_261 -> V_184 = V_2 -> V_185 ;
return 0 ;
}
static int F_103 ( struct V_168 * V_168 , void * V_201 ,
const struct V_182 * V_261 )
{
struct V_1 * V_2 = F_74 ( V_168 ) ;
struct V_182 V_262 = * V_261 ;
if ( V_261 -> V_189 != 0 )
return - V_136 ;
F_55 ( 1 , L_60 , V_139 ,
V_2 -> V_170 , V_2 -> V_19 ) ;
F_80 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_63 ( & V_2 -> V_157 , 0 , V_189 , V_190 , V_261 ) ;
F_63 ( & V_2 -> V_157 , 0 , V_189 , V_263 , & V_262 ) ;
V_2 -> V_185 = V_262 . V_184 ;
F_1 ( V_2 , 0 ) ;
F_59 ( V_2 ) ;
return 0 ;
}
static int F_104 ( struct V_168 * V_168 , void * V_201 ,
struct V_192 * V_193 )
{
struct V_1 * V_2 = F_74 ( V_168 ) ;
F_55 ( 1 , L_60 , V_139 ,
V_2 -> V_170 , V_2 -> V_19 ) ;
V_193 -> V_194 . V_264 . V_265 = V_2 -> V_99 ;
V_193 -> V_194 . V_264 . V_266 = V_267 ;
V_193 -> V_194 . V_264 . V_63 = 0 ;
V_193 -> V_194 . V_264 . V_29 = 0 ;
V_193 -> V_194 . V_264 . V_268 = 6750000 * 4 / 2 ;
V_193 -> V_194 . V_264 . V_153 [ 0 ] = V_2 -> V_100 ;
V_193 -> V_194 . V_264 . V_153 [ 1 ] = V_2 -> V_100 ;
V_193 -> V_194 . V_264 . V_269 [ 0 ] = 21 ;
V_193 -> V_194 . V_264 . V_269 [ 1 ] = 284 ;
memset ( V_193 -> V_194 . V_264 . V_270 , 0 , sizeof( V_193 -> V_194 . V_264 . V_270 ) ) ;
return 0 ;
}
static int F_105 ( struct V_168 * V_168 , void * V_201 ,
struct V_271 * V_272 )
{
struct V_1 * V_2 = F_74 ( V_168 ) ;
if ( V_272 -> type != V_72 )
return - V_136 ;
F_55 ( 1 , L_60 , V_139 ,
V_2 -> V_170 , V_2 -> V_19 ) ;
V_272 -> V_273 . V_274 = 0 ;
V_272 -> V_273 . V_275 = 0 ;
V_272 -> V_273 . V_91 = V_2 -> V_91 ;
V_272 -> V_273 . V_135 = V_2 -> V_135 ;
V_272 -> V_276 = V_272 -> V_273 ;
V_272 -> V_277 . V_278 = 54 ;
V_272 -> V_277 . V_279 = 59 ;
return 0 ;
}
static int F_106 ( struct V_168 * V_168 , void * V_201 ,
struct V_280 * V_281 )
{
struct V_1 * V_2 = F_74 ( V_168 ) ;
F_55 ( 1 , L_60 , V_139 ,
V_2 -> V_170 , V_2 -> V_19 ) ;
V_281 -> V_3 = F_107 ( V_2 , V_281 -> V_281 ) ;
V_281 -> V_134 = 1 ;
return 0 ;
}
static int F_108 ( struct V_168 * V_168 , void * V_201 ,
const struct V_280 * V_281 )
{
struct V_1 * V_2 = F_74 ( V_168 ) ;
F_55 ( 1 , L_60 , V_139 ,
V_2 -> V_170 , V_2 -> V_19 ) ;
return F_53 ( V_2 , V_281 -> V_281 , V_281 -> V_3 ) ;
}
static int F_109 ( struct V_168 * V_168 , void * V_282 )
{
struct V_175 * V_163 = F_78 ( V_168 ) ;
F_55 ( 1 , L_64 , V_139 ) ;
F_110 ( V_168 , V_282 ) ;
F_63 ( V_163 -> V_157 , 0 , V_180 , V_283 ) ;
return 0 ;
}
void F_111 ( struct V_1 * V_2 )
{
struct V_24 * V_24 ;
int V_30 ;
F_5 ( L_79 ) ;
if ( V_2 -> V_40 == V_41 ) {
F_5 ( L_80 ) ;
F_58 ( V_2 ) ;
for ( V_30 = 0 ; V_30 < V_2 -> V_34 . V_43 ; V_30 ++ ) {
V_24 = V_2 -> V_34 . V_24 [ V_30 ] ;
if ( V_24 ) {
if ( ! F_12 () )
F_13 ( V_24 ) ;
else
F_14 ( V_24 ) ;
}
}
}
if ( V_2 -> V_107 )
F_65 ( & V_2 -> V_108 ) ;
if ( V_2 -> V_111 )
F_65 ( & V_2 -> V_112 ) ;
}
void F_112 ( struct V_1 * V_2 )
{
int V_30 , V_55 ;
F_5 ( L_81 ) ;
if ( V_2 -> V_40 == V_41 ) {
F_61 ( V_2 ) ;
F_80 ( V_2 ) ;
}
if ( V_2 -> V_107 )
F_38 ( & V_2 -> V_108 , V_109 + ( V_110 / 10 ) ) ;
if ( V_2 -> V_111 )
F_38 ( & V_2 -> V_112 , V_109 + ( V_110 / 10 ) ) ;
F_52 ( V_2 ) ;
F_54 ( V_2 ) ;
if ( ! ( V_2 -> V_40 == V_41 ) ) {
F_59 ( V_2 ) ;
for ( V_30 = 0 ; V_30 < V_2 -> V_34 . V_43 ; V_30 ++ ) {
V_55 = F_10 ( V_2 -> V_34 . V_24 [ V_30 ] , V_39 ) ;
if ( V_55 ) {
F_3 ( L_27 ,
V_30 , V_55 ) ;
F_11 ( V_2 ) ;
}
}
}
}
static int F_113 ( struct V_1 * V_2 )
{
int V_55 ;
struct V_68 * V_69 ;
V_69 = & V_2 -> V_223 ;
V_69 -> type = V_72 ;
V_69 -> V_284 = V_285 | V_286 | V_287 | V_288 ;
V_69 -> V_289 = V_290 ;
V_69 -> V_291 = V_2 ;
V_69 -> V_292 = sizeof( struct V_65 ) ;
V_69 -> V_6 = & V_293 ;
V_69 -> V_294 = & V_295 ;
V_55 = F_114 ( V_69 ) ;
if ( V_55 < 0 )
return V_55 ;
V_69 = & V_2 -> V_296 ;
V_69 -> type = V_160 ;
V_69 -> V_284 = V_285 | V_286 | V_287 | V_288 ;
V_69 -> V_289 = V_290 ;
V_69 -> V_291 = V_2 ;
V_69 -> V_292 = sizeof( struct V_65 ) ;
V_69 -> V_6 = & V_297 ;
V_69 -> V_294 = & V_295 ;
V_55 = F_114 ( V_69 ) ;
if ( V_55 < 0 )
return V_55 ;
return 0 ;
}
static void F_115 ( struct V_1 * V_2 )
{
#if F_116 ( F_40 )
static const char * const V_230 [] = {
[ V_232 ] = L_68 ,
[ V_233 ] = L_69 ,
[ V_234 ] = L_70 ,
[ V_235 ] = L_71 ,
[ V_236 ] = L_72 ,
[ V_237 ] = L_73
} ;
int V_122 , V_30 ;
V_2 -> V_298 . V_29 = V_299 ;
V_122 = F_117 ( & V_2 -> V_163 . V_126 , 1 , & V_2 -> V_298 ) ;
if ( V_122 < 0 )
F_43 ( L_82 ) ;
V_2 -> V_300 . V_29 = V_299 ;
V_122 = F_117 ( & V_2 -> V_164 . V_126 , 1 , & V_2 -> V_300 ) ;
if ( V_122 < 0 )
F_43 ( L_83 ) ;
for ( V_30 = 0 ; V_30 < V_238 ; V_30 ++ ) {
struct V_117 * V_301 = & V_2 -> V_302 [ V_30 ] ;
if ( F_93 ( V_30 ) . type == V_231 )
break;
V_301 -> V_128 = V_230 [ F_93 ( V_30 ) . type ] ;
V_301 -> V_29 = V_303 ;
V_2 -> V_304 [ V_30 ] . V_29 = V_305 ;
switch ( F_93 ( V_30 ) . type ) {
case V_232 :
V_301 -> V_306 = V_307 ;
break;
case V_233 :
V_301 -> V_306 = V_308 ;
break;
case V_234 :
case V_235 :
case V_236 :
V_301 -> V_306 = V_309 ;
break;
default:
continue;
}
V_122 = F_117 ( V_301 , 1 , & V_2 -> V_304 [ V_30 ] ) ;
if ( V_122 < 0 )
F_43 ( L_84 , V_30 ) ;
V_122 = F_118 ( V_2 -> V_116 , V_301 ) ;
if ( V_122 < 0 )
F_43 ( L_85 , V_30 ) ;
}
#endif
}
int F_119 ( struct V_1 * V_2 ,
struct V_142 * V_310 )
{
int V_311 = - V_57 ;
struct V_312 * V_313 ;
struct V_314 * V_315 ;
int V_30 , V_122 ;
F_55 ( 1 , L_86 ,
V_310 -> V_146 -> V_147 . V_316 ) ;
V_311 = F_57 ( V_2 -> V_45 ,
V_310 -> V_146 -> V_147 . V_316 , 5 ) ;
if ( V_311 != 0 ) {
F_5 ( L_87 ) ;
return V_311 ;
}
V_313 = V_310 -> V_146 ;
for ( V_30 = 0 ; V_30 < V_313 -> V_147 . V_317 ; V_30 ++ ) {
V_315 = & V_313 -> V_315 [ V_30 ] . V_147 ;
if ( ( ( V_315 -> V_318 & V_319 )
== V_320 ) &&
( ( V_315 -> V_321 & V_322 )
== V_323 ) ) {
T_2 V_229 = F_120 ( V_315 -> V_324 ) ;
V_2 -> V_50 = ( V_229 & 0x07ff ) *
( ( ( V_229 & 0x1800 ) >> 11 ) + 1 ) ;
V_2 -> V_59 = V_315 -> V_318 ;
F_55 ( 1 ,
L_88 ,
V_2 -> V_59 , V_2 -> V_50 ) ;
}
}
if ( ! ( V_2 -> V_59 ) ) {
F_5 ( L_89 ) ;
return - V_21 ;
}
F_121 ( & V_2 -> V_325 ) ;
F_122 ( & V_2 -> V_33 ) ;
F_123 ( & V_2 -> V_28 . V_94 ) ;
F_123 ( & V_2 -> V_101 . V_94 ) ;
F_124 ( & V_2 -> V_108 , F_71 ,
( unsigned long ) V_2 ) ;
F_124 ( & V_2 -> V_112 , F_72 ,
( unsigned long ) V_2 ) ;
V_2 -> V_91 = V_326 ;
V_2 -> V_135 = V_327 ;
V_2 -> V_204 = V_2 -> V_91 * V_2 -> V_135 ;
V_2 -> V_203 = V_2 -> V_204 << 1 ;
V_2 -> V_90 = V_2 -> V_91 << 1 ;
V_2 -> V_99 = 720 ;
V_2 -> V_100 = 1 ;
V_2 -> V_245 = 0 ;
V_2 -> V_185 = 960 ;
V_2 -> V_188 = V_328 ;
F_95 ( V_2 , 0 ) ;
F_125 ( & V_2 -> V_329 ) ;
F_125 ( & V_2 -> V_330 ) ;
V_2 -> V_163 = V_331 ;
V_2 -> V_163 . V_157 = & V_2 -> V_157 ;
V_2 -> V_163 . V_172 = & V_2 -> V_172 ;
V_2 -> V_163 . V_332 = & V_2 -> V_223 ;
V_2 -> V_163 . V_332 -> V_172 = & V_2 -> V_329 ;
strcpy ( V_2 -> V_163 . V_128 , L_90 ) ;
V_2 -> V_164 = V_331 ;
V_2 -> V_164 . V_157 = & V_2 -> V_157 ;
V_2 -> V_164 . V_172 = & V_2 -> V_172 ;
V_2 -> V_164 . V_332 = & V_2 -> V_296 ;
V_2 -> V_164 . V_332 -> V_172 = & V_2 -> V_330 ;
strcpy ( V_2 -> V_164 . V_128 , L_91 ) ;
F_115 ( V_2 ) ;
V_311 = F_113 ( V_2 ) ;
if ( V_311 != 0 ) {
F_55 ( 1 , L_92 ,
V_311 ) ;
return - V_21 ;
}
F_126 ( & V_2 -> V_163 , V_2 ) ;
V_311 = F_127 ( & V_2 -> V_163 , V_177 , - 1 ) ;
if ( V_311 != 0 ) {
F_55 ( 1 , L_93 ,
V_311 ) ;
V_122 = - V_21 ;
goto V_333;
}
F_126 ( & V_2 -> V_164 , V_2 ) ;
V_311 = F_127 ( & V_2 -> V_164 , V_178 , - 1 ) ;
if ( V_311 != 0 ) {
F_55 ( 1 , L_94 ,
V_311 ) ;
V_122 = - V_21 ;
goto V_334;
}
F_55 ( 1 , L_95 , V_139 ) ;
return 0 ;
V_334:
F_69 ( & V_2 -> V_163 ) ;
V_333:
F_128 ( & V_2 -> V_223 ) ;
F_128 ( & V_2 -> V_296 ) ;
return V_122 ;
}

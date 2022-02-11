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
if ( F_5 ( V_19 , & V_2 -> V_20 ) ) {
F_6 ( L_12 ) ;
return - V_21 ;
}
if ( F_5 ( V_22 , & V_2 -> V_20 ) ) {
F_6 ( L_13 ) ;
return - V_23 ;
}
return 0 ;
}
static void F_7 ( struct V_24 * V_24 )
{
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_1 * V_2 = F_8 ( V_26 , struct V_1 , V_28 ) ;
unsigned long V_29 = 0 ;
int V_30 ;
switch ( V_24 -> V_9 ) {
case 0 :
case - V_31 :
break;
case - V_12 :
case - V_11 :
case - V_32 :
F_3 ( L_14 ) ;
return;
default:
F_3 ( L_15 , V_24 -> V_9 ) ;
break;
}
F_9 ( & V_2 -> V_33 , V_29 ) ;
V_2 -> V_34 . V_35 ( V_2 , V_24 ) ;
F_10 ( & V_2 -> V_33 , V_29 ) ;
for ( V_30 = 0 ; V_30 < V_24 -> V_36 ; V_30 ++ ) {
V_24 -> V_37 [ V_30 ] . V_9 = 0 ;
V_24 -> V_37 [ V_30 ] . V_38 = 0 ;
}
V_24 -> V_9 = 0 ;
V_24 -> V_9 = F_11 ( V_24 , V_39 ) ;
if ( V_24 -> V_9 ) {
F_3 ( L_16 ,
V_24 -> V_9 ) ;
}
V_2 -> V_40 = V_41 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_24 * V_24 ;
int V_30 ;
F_3 ( L_17 ) ;
V_2 -> V_34 . V_42 = - 1 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_34 . V_43 ; V_30 ++ ) {
V_24 = V_2 -> V_34 . V_24 [ V_30 ] ;
if ( V_24 ) {
if ( ! F_13 () )
F_14 ( V_24 ) ;
else
F_15 ( V_24 ) ;
if ( V_2 -> V_34 . V_44 [ V_30 ] ) {
F_16 ( V_2 -> V_45 ,
V_24 -> V_46 ,
V_2 -> V_34 . V_44 [ V_30 ] ,
V_24 -> V_47 ) ;
}
F_17 ( V_24 ) ;
V_2 -> V_34 . V_24 [ V_30 ] = NULL ;
}
V_2 -> V_34 . V_44 [ V_30 ] = NULL ;
}
F_18 ( V_2 -> V_34 . V_24 ) ;
F_18 ( V_2 -> V_34 . V_44 ) ;
V_2 -> V_34 . V_24 = NULL ;
V_2 -> V_34 . V_44 = NULL ;
V_2 -> V_34 . V_43 = 0 ;
V_2 -> V_40 = V_48 ;
}
static int F_19 ( struct V_1 * V_2 , int V_49 ,
int V_43 , int V_50 ,
int (* V_35) ( struct V_1 * V_2 , struct V_24 * V_24 ) )
{
struct V_25 * V_26 = & V_2 -> V_28 ;
int V_30 ;
int V_51 , V_52 ;
struct V_24 * V_24 ;
int V_53 , V_54 ;
int V_55 ;
F_3 ( L_18 ) ;
V_2 -> V_34 . V_35 = V_35 ;
V_2 -> V_34 . V_43 = V_43 ;
V_2 -> V_34 . V_24 = F_20 ( sizeof( void * ) * V_43 , V_56 ) ;
if ( ! V_2 -> V_34 . V_24 ) {
F_3 ( L_19 ) ;
return - V_57 ;
}
V_2 -> V_34 . V_44 = F_20 ( sizeof( void * ) * V_43 ,
V_56 ) ;
if ( ! V_2 -> V_34 . V_44 ) {
F_3 ( L_20 ) ;
F_18 ( V_2 -> V_34 . V_24 ) ;
return - V_57 ;
}
V_2 -> V_34 . V_50 = V_50 ;
V_2 -> V_34 . V_58 = NULL ;
V_51 = V_49 * V_2 -> V_34 . V_50 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_34 . V_43 ; V_30 ++ ) {
V_24 = F_21 ( V_49 , V_56 ) ;
if ( ! V_24 ) {
F_3 ( L_21 , V_30 ) ;
F_12 ( V_2 ) ;
return - V_57 ;
}
V_2 -> V_34 . V_24 [ V_30 ] = V_24 ;
V_2 -> V_34 . V_44 [ V_30 ] = F_22 ( V_2 -> V_45 ,
V_51 , V_56 , & V_24 -> V_47 ) ;
if ( ! V_2 -> V_34 . V_44 [ V_30 ] ) {
F_23 ( L_22
L_23 ,
V_51 , V_30 ,
F_24 () ? L_24 : L_25 ) ;
F_12 ( V_2 ) ;
return - V_57 ;
}
memset ( V_2 -> V_34 . V_44 [ V_30 ] , 0 , V_51 ) ;
V_52 = F_25 ( V_2 -> V_45 ,
V_2 -> V_59 ) ,
F_26 ( V_24 , V_2 -> V_45 , V_52 ,
V_2 -> V_34 . V_44 [ V_30 ] , V_51 ,
F_7 , V_26 , 1 ) ;
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
V_55 = F_11 ( V_2 -> V_34 . V_24 [ V_30 ] , V_39 ) ;
if ( V_55 ) {
F_3 ( L_26 ,
V_30 , V_55 ) ;
F_12 ( V_2 ) ;
return V_55 ;
}
}
return 0 ;
}
static inline void F_27 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_65 * V_58 )
{
struct V_66 * V_67 = & V_58 -> V_67 ;
struct V_68 * V_69 = V_67 -> V_70 . V_68 ;
F_3 ( L_27 , V_58 , V_58 -> V_71 ) ;
if ( V_69 -> type == V_72 )
V_67 -> V_73 = V_2 -> V_74 ++ ;
else
V_67 -> V_73 = V_2 -> V_75 ++ ;
V_67 -> V_76 = V_77 ;
V_67 -> V_70 . V_78 = F_28 () ;
F_29 ( & V_67 -> V_70 , V_79 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
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
F_3 ( L_28 ,
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
F_3 ( L_29 ,
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
static inline void F_31 ( struct V_25 * V_26 ,
struct V_65 * * V_58 )
{
struct V_1 * V_2 = F_8 ( V_26 , struct V_1 , V_28 ) ;
if ( F_32 ( & V_26 -> V_94 ) ) {
F_3 ( L_30 ) ;
V_2 -> V_34 . V_58 = NULL ;
* V_58 = NULL ;
return;
}
* V_58 = F_33 ( V_26 -> V_94 . V_95 , struct V_65 , V_96 ) ;
F_34 ( & ( * V_58 ) -> V_96 ) ;
V_26 -> V_92 = 0 ;
( * V_58 ) -> V_97 = ( * V_58 ) -> V_98 ;
V_2 -> V_34 . V_58 = * V_58 ;
return;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_65 * V_58 ,
unsigned char * V_80 ,
unsigned char * V_81 , unsigned long V_82 )
{
unsigned char * V_84 , * V_85 ;
int V_90 ;
int V_30 , V_53 = 0 ;
if ( V_2 == NULL ) {
F_3 ( L_31 ) ;
return;
}
if ( V_26 == NULL ) {
F_3 ( L_32 ) ;
return;
}
if ( V_58 == NULL )
return;
if ( V_80 == NULL ) {
F_3 ( L_33 ) ;
return;
}
if ( V_81 == NULL ) {
F_3 ( L_34 ) ;
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
static inline void F_36 ( struct V_25 * V_26 ,
struct V_65 * * V_58 )
{
struct V_1 * V_2 = F_8 ( V_26 , struct V_1 , V_101 ) ;
if ( F_32 ( & V_26 -> V_94 ) ) {
F_3 ( L_30 ) ;
V_2 -> V_34 . V_102 = NULL ;
* V_58 = NULL ;
return;
}
* V_58 = F_33 ( V_26 -> V_94 . V_95 , struct V_65 , V_96 ) ;
F_34 ( & ( * V_58 ) -> V_96 ) ;
V_26 -> V_92 = 0 ;
( * V_58 ) -> V_97 = ( * V_58 ) -> V_98 ;
V_2 -> V_34 . V_102 = * V_58 ;
return;
}
static inline int F_37 ( struct V_1 * V_2 , struct V_24 * V_24 )
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
if ( F_5 ( V_19 , & V_2 -> V_20 ) ||
F_5 ( V_22 , & V_2 -> V_20 ) )
return 0 ;
if ( V_24 -> V_9 < 0 ) {
F_2 ( V_2 , - 1 , V_24 -> V_9 ) ;
if ( V_24 -> V_9 == - V_11 )
return 0 ;
}
V_58 = V_2 -> V_34 . V_58 ;
if ( V_58 != NULL )
V_81 = F_38 ( & V_58 -> V_67 . V_70 , 0 ) ;
V_102 = V_2 -> V_34 . V_102 ;
if ( V_102 != NULL )
V_104 = F_38 ( & V_102 -> V_67 . V_70 , 0 ) ;
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
F_3 ( L_35 ) ;
continue;
}
V_80 = V_24 -> V_44 + V_24 -> V_37 [ V_30 ] . V_63 ;
V_105 = V_80 [ 0 ] ;
V_82 = V_24 -> V_37 [ V_30 ] . V_38 - 4 ;
V_80 += 4 ;
if ( V_105 & 0x80 ) {
V_82 -= 4 ;
V_80 += 4 ;
F_3 ( L_36 ,
( V_105 & 0x40 ) ? L_37 : L_38 ) ;
if ( V_105 & 0x40 ) {
if ( V_102 != NULL )
F_27 ( V_2 , V_103 , V_102 ) ;
F_36 ( V_103 , & V_102 ) ;
if ( V_102 == NULL )
V_104 = NULL ;
else
V_104 = F_38 (
& V_102 -> V_67 . V_70 , 0 ) ;
if ( V_58 != NULL )
F_27 ( V_2 , V_26 , V_58 ) ;
F_31 ( V_26 , & V_58 ) ;
if ( V_58 == NULL )
V_81 = NULL ;
else
V_81 = F_38 (
& V_58 -> V_67 . V_70 , 0 ) ;
if ( V_2 -> V_107 )
F_39 ( & V_2 -> V_108 ,
V_109 + ( V_110 / 10 ) ) ;
if ( V_2 -> V_111 )
F_39 ( & V_2 -> V_112 ,
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
F_35 ( V_2 , V_103 , V_102 , V_80 ,
V_104 , V_82 ) ;
V_82 -= V_88 ;
V_80 += V_88 ;
V_2 -> V_113 += V_88 ;
}
if ( V_2 -> V_113 >= V_106 && V_58 != NULL )
F_30 ( V_2 , V_26 , V_58 , V_80 , V_81 , V_82 ) ;
}
return V_55 ;
}
void F_40 ( struct V_1 * V_2 )
{
#ifdef F_41
int V_30 ;
for ( V_30 = 0 ; V_30 < V_114 ; V_30 ++ ) {
if ( F_42 ( V_30 ) . type == V_115 )
return;
F_43 ( & V_2 -> V_116 [ V_30 ] ) ;
}
#endif
}
static void F_44 ( struct V_117 * V_118 )
{
struct V_1 * V_2 =
F_8 ( V_118 , struct V_1 , V_118 ) ;
F_45 ( & V_2 -> V_119 ) ;
F_46 ( & V_2 -> V_118 ) ;
F_40 ( V_2 ) ;
F_47 ( V_2 ) ;
}
int F_48 ( struct V_120 * V_121 ,
struct V_1 * V_2 )
{
int V_122 ;
if ( F_42 ( 0 ) . type == V_115 )
return 0 ;
#ifdef F_41
V_2 -> V_118 . V_123 = V_2 -> V_124 ;
#endif
V_122 = F_49 ( & V_121 -> V_2 , & V_2 -> V_118 ) ;
if ( V_122 ) {
F_50 ( L_39 ,
V_125 ) ;
return V_122 ;
}
V_2 -> V_118 . V_126 = F_44 ;
V_122 = F_51 ( & V_2 -> V_119 , 4 ) ;
if ( V_122 ) {
F_50 ( L_40 ,
V_125 ) ;
return V_122 ;
}
V_2 -> V_118 . V_127 = & V_2 -> V_119 ;
return 0 ;
}
static int F_52 ( struct V_68 * V_128 ,
unsigned int * V_129 , unsigned int * V_130 ,
unsigned int V_131 [] , struct V_132 * V_133 [] )
{
struct V_1 * V_2 = F_53 ( V_128 ) ;
unsigned long V_134 = V_2 -> V_135 * V_2 -> V_90 ;
if ( * V_130 )
return V_131 [ 0 ] < V_134 ? - V_136 : 0 ;
* V_130 = 1 ;
V_131 [ 0 ] = V_134 ;
return 0 ;
}
static int
F_54 ( struct V_137 * V_67 )
{
struct V_66 * V_138 = F_55 ( V_67 ) ;
struct V_65 * V_58 = F_8 ( V_138 ,
struct V_65 , V_67 ) ;
struct V_1 * V_2 = F_53 ( V_67 -> V_68 ) ;
V_58 -> V_64 = V_2 -> V_135 * V_2 -> V_90 ;
if ( F_56 ( V_67 , 0 ) < V_58 -> V_64 ) {
F_50 ( L_41 ,
V_125 , F_56 ( V_67 , 0 ) , V_58 -> V_64 ) ;
return - V_136 ;
}
F_57 ( & V_58 -> V_67 . V_70 , 0 , V_58 -> V_64 ) ;
return 0 ;
}
static void
F_58 ( struct V_137 * V_67 )
{
struct V_66 * V_138 = F_55 ( V_67 ) ;
struct V_65 * V_58 = F_8 ( V_138 ,
struct V_65 ,
V_67 ) ;
struct V_1 * V_2 = F_53 ( V_67 -> V_68 ) ;
struct V_25 * V_28 = & V_2 -> V_28 ;
unsigned long V_29 = 0 ;
V_58 -> V_98 = F_38 ( V_67 , 0 ) ;
V_58 -> V_64 = F_56 ( V_67 , 0 ) ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
F_59 ( & V_58 -> V_96 , & V_28 -> V_94 ) ;
F_10 ( & V_2 -> V_33 , V_29 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
F_61 ( V_2 , V_139 , 0x01 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_140 )
{
struct V_120 * V_141 ;
int V_142 , V_143 , V_144 ;
F_63 ( 1 , L_42 ) ;
V_141 = F_64 ( V_140 -> V_45 , 0 ) ;
if ( V_141 && V_141 -> V_145 -> V_146 . V_147 != 5 ) {
F_63 ( 1 , L_43 ) ;
V_142 = F_65 ( V_140 -> V_45 , 0 , 5 ) ;
if ( V_142 < 0 ) {
F_6 ( L_44 ) ;
return - V_148 ;
}
}
V_143 = V_140 -> V_135 / 2 + 2 ;
V_144 = V_140 -> V_91 * 2 ;
F_61 ( V_140 , V_149 , 0x00 ) ;
F_61 ( V_140 , 0x106 , 0x00 ) ;
F_61 ( V_140 , 0x110 , 0x00 ) ;
F_61 ( V_140 , 0x111 , 0x00 ) ;
F_61 ( V_140 , 0x114 , V_144 & 0xff ) ;
F_61 ( V_140 , 0x115 , V_144 >> 8 ) ;
F_61 ( V_140 , 0x112 , 0x00 ) ;
F_61 ( V_140 , 0x113 , 0x00 ) ;
F_61 ( V_140 , 0x116 , V_143 & 0xff ) ;
F_61 ( V_140 , 0x117 , V_143 >> 8 ) ;
F_61 ( V_140 , V_150 , 0xb3 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_140 )
{
F_63 ( 1 , L_45 ) ;
F_61 ( V_140 , V_150 , 0x0 ) ;
return 0 ;
}
static void F_67 ( struct V_1 * V_2 )
{
F_63 ( 1 , L_46 ) ;
F_61 ( V_2 , V_150 , 0x0 ) ;
F_68 ( 30 ) ;
F_61 ( V_2 , V_150 , 0xb3 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
int V_142 = 0 ;
V_2 -> V_40 = V_151 ;
if ( F_5 ( V_19 , & V_2 -> V_20 ) )
return - V_21 ;
else if ( V_142 ) {
F_70 ( V_22 , & V_2 -> V_20 ) ;
F_63 ( 1 , L_47 , V_125 ) ;
return V_142 ;
}
return 0 ;
}
int F_71 ( struct V_68 * V_128 , unsigned int V_152 )
{
struct V_1 * V_2 = F_53 ( V_128 ) ;
int V_55 = 0 ;
F_63 ( 1 , L_48 ,
V_2 -> V_153 ) ;
if ( V_128 -> type == V_72 )
V_2 -> V_74 = 0 ;
else
V_2 -> V_75 = 0 ;
if ( V_2 -> V_153 == 0 ) {
F_60 ( V_2 ) ;
V_55 = F_19 ( V_2 , V_154 ,
V_155 , V_2 -> V_50 ,
F_37 ) ;
if ( V_55 < 0 ) {
F_6 ( L_49 ) ;
return V_55 ;
}
if ( V_128 -> type == V_72 ) {
F_72 ( & V_2 -> V_118 , 0 , V_156 ,
V_157 , 1 ) ;
V_2 -> V_107 = 1 ;
F_39 ( & V_2 -> V_108 , V_109 + ( V_110 / 10 ) ) ;
} else if ( V_128 -> type == V_158 ) {
V_2 -> V_111 = 1 ;
F_39 ( & V_2 -> V_112 , V_109 + ( V_110 / 10 ) ) ;
}
}
V_2 -> V_153 ++ ;
return V_55 ;
}
static void F_73 ( struct V_68 * V_128 )
{
struct V_1 * V_2 = F_53 ( V_128 ) ;
struct V_25 * V_28 = & V_2 -> V_28 ;
unsigned long V_29 = 0 ;
F_63 ( 1 , L_50 , V_2 -> V_153 ) ;
if ( V_2 -> V_153 -- == 1 )
F_12 ( V_2 ) ;
F_72 ( & V_2 -> V_118 , 0 , V_156 , V_157 , 0 ) ;
V_2 -> V_107 = 0 ;
F_74 ( & V_2 -> V_108 ) ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_34 . V_58 != NULL ) {
F_29 ( & V_2 -> V_34 . V_58 -> V_67 . V_70 ,
V_159 ) ;
V_2 -> V_34 . V_58 = NULL ;
}
while ( ! F_32 ( & V_28 -> V_94 ) ) {
struct V_65 * V_58 ;
V_58 = F_33 ( V_28 -> V_94 . V_95 , struct V_65 , V_96 ) ;
F_29 ( & V_58 -> V_67 . V_70 , V_159 ) ;
F_34 ( & V_58 -> V_96 ) ;
}
F_10 ( & V_2 -> V_33 , V_29 ) ;
}
void F_75 ( struct V_68 * V_128 )
{
struct V_1 * V_2 = F_53 ( V_128 ) ;
struct V_25 * V_101 = & V_2 -> V_101 ;
unsigned long V_29 = 0 ;
F_63 ( 1 , L_51 ,
V_2 -> V_153 ) ;
if ( V_2 -> V_153 -- == 1 )
F_12 ( V_2 ) ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_34 . V_102 != NULL ) {
F_29 ( & V_2 -> V_34 . V_102 -> V_67 . V_70 ,
V_159 ) ;
V_2 -> V_34 . V_102 = NULL ;
}
while ( ! F_32 ( & V_101 -> V_94 ) ) {
struct V_65 * V_58 ;
V_58 = F_33 ( V_101 -> V_94 . V_95 , struct V_65 , V_96 ) ;
F_34 ( & V_58 -> V_96 ) ;
F_29 ( & V_58 -> V_67 . V_70 , V_159 ) ;
}
F_10 ( & V_2 -> V_33 , V_29 ) ;
V_2 -> V_111 = 0 ;
F_74 ( & V_2 -> V_112 ) ;
}
int F_76 ( struct V_1 * V_2 )
{
F_63 ( 1 , L_52 ) ;
if ( F_42 ( 0 ) . type == V_115 )
return 0 ;
F_77 ( & V_160 ) ;
F_78 ( & V_2 -> V_161 ) ;
F_78 ( & V_2 -> V_162 ) ;
F_79 ( & V_160 ) ;
F_80 ( & V_2 -> V_118 ) ;
F_81 ( & V_2 -> V_118 ) ;
return 1 ;
}
static void F_82 ( unsigned long V_163 )
{
struct V_1 * V_2 = (struct V_1 * ) V_163 ;
struct V_25 * V_26 = & V_2 -> V_28 ;
struct V_65 * V_58 ;
unsigned char * V_164 ;
unsigned long V_29 = 0 ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
V_58 = V_2 -> V_34 . V_58 ;
if ( V_58 != NULL ) {
V_164 = F_38 ( & V_58 -> V_67 . V_70 , 0 ) ;
memset ( V_164 , 0x00 , V_58 -> V_64 ) ;
F_27 ( V_2 , V_26 , V_58 ) ;
}
F_31 ( V_26 , & V_58 ) ;
if ( V_2 -> V_107 == 1 )
F_39 ( & V_2 -> V_108 , V_109 + ( V_110 / 10 ) ) ;
F_10 ( & V_2 -> V_33 , V_29 ) ;
}
static void F_83 ( unsigned long V_163 )
{
struct V_1 * V_2 = (struct V_1 * ) V_163 ;
struct V_25 * V_26 = & V_2 -> V_101 ;
struct V_65 * V_58 ;
unsigned char * V_165 ;
unsigned long V_29 = 0 ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
V_58 = V_2 -> V_34 . V_102 ;
if ( V_58 != NULL ) {
V_165 = F_38 ( & V_58 -> V_67 . V_70 , 0 ) ;
memset ( V_165 , 0x00 , V_58 -> V_64 ) ;
F_27 ( V_2 , V_26 , V_58 ) ;
}
F_36 ( V_26 , & V_58 ) ;
if ( V_2 -> V_111 == 1 )
F_39 ( & V_2 -> V_112 , V_109 + ( V_110 / 10 ) ) ;
F_10 ( & V_2 -> V_33 , V_29 ) ;
}
static int F_84 ( struct V_166 * V_167 )
{
struct V_1 * V_2 = F_85 ( V_167 ) ;
int V_142 ;
F_63 ( 1 ,
L_53 ,
V_125 , V_2 -> V_168 , V_2 -> V_20 ,
V_2 -> V_153 , V_2 -> V_169 ) ;
if ( F_86 ( & V_2 -> V_170 ) )
return - V_171 ;
V_142 = F_87 ( V_167 ) ;
if ( V_142 ) {
F_3 ( L_54 ,
V_125 , V_142 ) ;
F_79 ( & V_2 -> V_170 ) ;
return V_142 ;
}
if ( V_2 -> V_169 == 0 ) {
F_62 ( V_2 ) ;
F_67 ( V_2 ) ;
V_2 -> V_40 = V_48 ;
F_70 ( V_172 , & V_2 -> V_20 ) ;
}
V_2 -> V_169 ++ ;
F_79 ( & V_2 -> V_170 ) ;
return V_142 ;
}
static int F_88 ( struct V_166 * V_167 )
{
int V_142 ;
struct V_1 * V_2 = F_85 ( V_167 ) ;
struct V_173 * V_161 = F_89 ( V_167 ) ;
F_63 ( 1 ,
L_53 ,
V_125 , V_2 -> V_168 , V_2 -> V_20 ,
V_2 -> V_153 , V_2 -> V_169 ) ;
F_77 ( & V_2 -> V_170 ) ;
if ( V_161 -> V_174 == V_175 && V_2 -> V_107 ) {
V_2 -> V_107 = 0 ;
F_74 ( & V_2 -> V_108 ) ;
} else if ( V_161 -> V_174 == V_176 &&
V_2 -> V_111 ) {
V_2 -> V_111 = 0 ;
F_74 ( & V_2 -> V_112 ) ;
}
if ( F_5 ( V_19 , & V_2 -> V_20 ) )
goto V_177;
if ( V_2 -> V_169 == 1 ) {
V_142 = F_90 ( V_161 ) ;
if ( V_142 == 0 )
F_72 ( & V_2 -> V_118 , 0 , V_178 ,
V_179 , 0 ) ;
V_2 -> V_168 = 0 ;
V_142 = F_65 ( V_2 -> V_45 , 0 , 0 ) ;
if ( V_142 < 0 )
F_6 ( L_55 ) ;
}
V_177:
F_91 ( V_167 , NULL ) ;
V_2 -> V_169 -- ;
F_79 ( & V_2 -> V_170 ) ;
return 0 ;
}
static void F_92 ( struct V_1 * V_2 )
{
struct V_180 V_181 = {
. V_182 = V_2 -> V_183 ,
. type = V_184 ,
} ;
F_63 ( 1 , L_56 , V_125 ,
V_2 -> V_168 , V_2 -> V_20 ) ;
if ( V_2 -> V_168 )
return;
V_2 -> V_168 = 1 ;
F_1 ( V_2 , 1 ) ;
F_72 ( & V_2 -> V_118 , 0 , V_156 , V_185 , V_2 -> V_186 ) ;
F_72 ( & V_2 -> V_118 , 0 , V_187 , V_188 , & V_181 ) ;
F_1 ( V_2 , 0 ) ;
}
static int F_93 ( struct V_1 * V_2 , unsigned int V_189 ,
struct V_190 * V_191 )
{
int V_142 ;
int V_91 = V_191 -> V_192 . V_193 . V_91 ;
int V_135 = V_191 -> V_192 . V_193 . V_135 ;
if ( V_191 -> V_192 . V_193 . V_194 != V_195 )
return - V_136 ;
if ( V_91 != 720 )
V_91 = 720 ;
if ( V_135 != 480 )
V_135 = 480 ;
V_191 -> V_192 . V_193 . V_91 = V_91 ;
V_191 -> V_192 . V_193 . V_135 = V_135 ;
V_191 -> V_192 . V_193 . V_194 = V_195 ;
V_191 -> V_192 . V_193 . V_90 = V_91 * 2 ;
V_191 -> V_192 . V_193 . V_196 = V_91 * V_135 * 2 ;
V_191 -> V_192 . V_193 . V_197 = V_198 ;
V_191 -> V_192 . V_193 . V_76 = V_77 ;
V_191 -> V_192 . V_193 . V_199 = 0 ;
if ( V_189 == V_200 )
return 0 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_135 = V_135 ;
V_2 -> V_201 = V_91 * V_135 * 2 ;
V_2 -> V_202 = V_91 * V_135 ;
V_2 -> V_90 = V_91 * 2 ;
if ( V_2 -> V_40 == V_41 ) {
F_63 ( 1 , L_57 ) ;
V_142 = F_69 ( V_2 ) ;
if ( V_142 != 0 ) {
F_63 ( 1 , L_58 ) ;
return V_142 ;
}
}
F_62 ( V_2 ) ;
return 0 ;
}
static int F_94 ( struct V_166 * V_166 , void * V_199 ,
struct V_203 * V_204 )
{
struct V_173 * V_161 = F_89 ( V_166 ) ;
struct V_1 * V_2 = F_85 ( V_166 ) ;
F_63 ( 1 , L_56 , V_125 ,
V_2 -> V_168 , V_2 -> V_20 ) ;
F_95 ( V_204 -> V_205 , L_59 , sizeof( V_204 -> V_205 ) ) ;
F_95 ( V_204 -> V_206 , V_2 -> V_207 . V_208 , sizeof( V_204 -> V_206 ) ) ;
F_96 ( V_2 -> V_45 , V_204 -> V_209 , sizeof( V_204 -> V_209 ) ) ;
V_204 -> V_210 = V_211 |
V_212 |
V_213 |
V_214 ;
if ( V_161 -> V_174 == V_175 )
V_204 -> V_210 |= V_215 ;
else
V_204 -> V_210 |= V_216 ;
V_204 -> V_217 = V_204 -> V_210 | V_218 |
V_216 | V_215 ;
return 0 ;
}
static int F_97 ( struct V_166 * V_166 , void * V_199 ,
struct V_219 * V_181 )
{
if ( V_181 -> V_220 )
return - V_136 ;
F_63 ( 1 , L_60 , V_125 ) ;
V_181 -> type = V_72 ;
strcpy ( V_181 -> V_221 , L_61 ) ;
V_181 -> V_29 = 0 ;
V_181 -> V_194 = V_195 ;
return 0 ;
}
static int F_98 ( struct V_166 * V_166 , void * V_199 ,
struct V_190 * V_181 )
{
struct V_1 * V_2 = F_85 ( V_166 ) ;
F_63 ( 1 , L_56 , V_125 ,
V_2 -> V_168 , V_2 -> V_20 ) ;
V_181 -> V_192 . V_193 . V_91 = V_2 -> V_91 ;
V_181 -> V_192 . V_193 . V_135 = V_2 -> V_135 ;
V_181 -> V_192 . V_193 . V_194 = V_195 ;
V_181 -> V_192 . V_193 . V_90 = V_2 -> V_90 ;
V_181 -> V_192 . V_193 . V_196 = V_2 -> V_201 ;
V_181 -> V_192 . V_193 . V_197 = V_198 ;
V_181 -> V_192 . V_193 . V_76 = V_77 ;
V_181 -> V_192 . V_193 . V_199 = 0 ;
return 0 ;
}
static int F_99 ( struct V_166 * V_166 , void * V_199 ,
struct V_190 * V_181 )
{
struct V_1 * V_2 = F_85 ( V_166 ) ;
F_63 ( 1 , L_56 , V_125 ,
V_2 -> V_168 , V_2 -> V_20 ) ;
return F_93 ( V_2 , V_200 , V_181 ) ;
}
static int F_100 ( struct V_166 * V_166 , void * V_199 ,
struct V_190 * V_181 )
{
struct V_1 * V_2 = F_85 ( V_166 ) ;
int V_55 ;
F_63 ( 1 , L_56 , V_125 ,
V_2 -> V_168 , V_2 -> V_20 ) ;
V_55 = F_4 ( V_2 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( F_101 ( & V_2 -> V_222 ) ) {
F_6 ( L_62 , V_125 ) ;
V_55 = - V_148 ;
goto V_223;
}
V_55 = F_93 ( V_2 , V_224 , V_181 ) ;
V_223:
return V_55 ;
}
static int F_102 ( struct V_166 * V_166 , void * V_199 , T_1 V_225 )
{
struct V_1 * V_2 = F_85 ( V_166 ) ;
F_63 ( 1 , L_56 , V_125 ,
V_2 -> V_168 , V_2 -> V_20 ) ;
if ( V_225 == V_2 -> V_186 )
return 0 ;
if ( V_2 -> V_153 > 0 )
return - V_148 ;
V_2 -> V_186 = V_225 ;
F_92 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_72 ( & V_2 -> V_118 , 0 , V_156 , V_185 , V_225 ) ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int F_103 ( struct V_166 * V_166 , void * V_199 , T_1 * V_225 )
{
struct V_1 * V_2 = F_85 ( V_166 ) ;
F_63 ( 1 , L_56 , V_125 ,
V_2 -> V_168 , V_2 -> V_20 ) ;
* V_225 = V_2 -> V_186 ;
return 0 ;
}
static int F_104 ( struct V_166 * V_166 , void * V_199 ,
struct V_226 * V_227 )
{
struct V_1 * V_2 = F_85 ( V_166 ) ;
unsigned int V_228 ;
static const char * V_229 [] = {
[ V_115 ] = L_63 ,
[ V_230 ] = L_64 ,
[ V_231 ] = L_65 ,
[ V_232 ] = L_66 ,
[ V_233 ] = L_67 ,
[ V_234 ] = L_68 ,
} ;
F_63 ( 1 , L_56 , V_125 ,
V_2 -> V_168 , V_2 -> V_20 ) ;
V_228 = V_227 -> V_220 ;
if ( V_228 >= V_114 )
return - V_136 ;
if ( F_42 ( V_228 ) . type == 0 )
return - V_136 ;
V_227 -> V_220 = V_228 ;
strcpy ( V_227 -> V_208 , V_229 [ F_42 ( V_228 ) . type ] ) ;
if ( ( F_42 ( V_228 ) . type == V_233 ) ||
( F_42 ( V_228 ) . type == V_232 ) ) {
V_227 -> type |= V_235 ;
V_227 -> V_236 = 1 ;
} else {
V_227 -> type |= V_237 ;
V_227 -> V_236 = 2 ;
}
V_227 -> V_186 = V_2 -> V_161 . V_238 ;
return 0 ;
}
static int F_105 ( struct V_166 * V_166 , void * V_199 , unsigned int * V_30 )
{
struct V_1 * V_2 = F_85 ( V_166 ) ;
F_63 ( 1 , L_56 , V_125 ,
V_2 -> V_168 , V_2 -> V_20 ) ;
* V_30 = V_2 -> V_239 ;
return 0 ;
}
static void F_106 ( struct V_1 * V_2 , int V_220 )
{
int V_30 ;
F_63 ( 1 , L_56 , V_125 ,
V_2 -> V_168 , V_2 -> V_20 ) ;
switch ( F_42 ( V_220 ) . type ) {
case V_231 :
V_2 -> V_240 = V_231 ;
V_2 -> V_241 = 1 ;
break;
case V_230 :
V_2 -> V_240 = V_230 ;
V_2 -> V_241 = 1 ;
break;
case V_233 :
V_2 -> V_240 = V_233 ;
V_2 -> V_241 = 0 ;
break;
default:
F_63 ( 1 , L_69 ,
F_42 ( V_220 ) . type ) ;
return;
}
V_2 -> V_239 = V_220 ;
F_72 ( & V_2 -> V_118 , 0 , V_156 , V_242 ,
F_42 ( V_220 ) . V_243 , 0 , 0 ) ;
for ( V_30 = 0 ; V_30 < V_114 ; V_30 ++ ) {
int V_244 = 0 ;
if ( F_42 ( V_30 ) . V_245 == NULL )
continue;
if ( V_30 == V_220 )
V_244 = 1 ;
else
V_244 = 0 ;
if ( V_244 ) {
( F_42 ( V_30 ) . V_245 ) ( V_2 , V_244 ) ;
} else {
if ( ( F_42 ( V_30 ) . V_245 ) !=
( ( F_42 ( V_220 ) . V_245 ) ) ) {
( F_42 ( V_30 ) . V_245 ) ( V_2 , V_244 ) ;
}
}
}
F_72 ( & V_2 -> V_118 , 0 , V_246 , V_242 ,
F_42 ( V_220 ) . V_247 , 0 , 0 ) ;
}
static int F_107 ( struct V_166 * V_166 , void * V_199 , unsigned int V_220 )
{
struct V_1 * V_2 = F_85 ( V_166 ) ;
struct V_173 * V_248 = F_89 ( V_166 ) ;
F_63 ( 1 , L_70 , V_125 ,
V_220 ) ;
if ( V_220 >= V_114 )
return - V_136 ;
if ( F_42 ( V_220 ) . type == 0 )
return - V_136 ;
if ( V_2 -> V_239 == V_220 )
return 0 ;
F_106 ( V_2 , V_220 ) ;
F_108 ( V_248 ) ;
return F_90 ( V_248 ) ;
}
static int F_109 ( struct V_166 * V_166 , void * V_199 , struct V_249 * V_250 )
{
if ( V_250 -> V_220 > 1 )
return - V_136 ;
F_63 ( 1 , L_60 , V_125 ) ;
if ( V_250 -> V_220 == 0 )
strcpy ( V_250 -> V_208 , L_67 ) ;
else
strcpy ( V_250 -> V_208 , L_71 ) ;
V_250 -> V_251 = V_252 ;
return 0 ;
}
static int F_110 ( struct V_166 * V_166 , void * V_199 , struct V_249 * V_250 )
{
struct V_1 * V_2 = F_85 ( V_166 ) ;
F_63 ( 1 , L_56 , V_125 ,
V_2 -> V_168 , V_2 -> V_20 ) ;
V_250 -> V_220 = V_2 -> V_241 ;
if ( V_250 -> V_220 == 0 )
strcpy ( V_250 -> V_208 , L_67 ) ;
else
strcpy ( V_250 -> V_208 , L_71 ) ;
V_250 -> V_251 = V_252 ;
return 0 ;
}
static int F_111 ( struct V_166 * V_166 , void * V_199 , const struct V_249 * V_250 )
{
struct V_1 * V_2 = F_85 ( V_166 ) ;
if ( V_250 -> V_220 != V_2 -> V_241 )
return - V_136 ;
F_63 ( 1 , L_56 , V_125 ,
V_2 -> V_168 , V_2 -> V_20 ) ;
return 0 ;
}
static int F_112 ( struct V_166 * V_166 , void * V_199 , struct V_253 * V_254 )
{
struct V_1 * V_2 = F_85 ( V_166 ) ;
struct V_173 * V_248 = F_89 ( V_166 ) ;
int V_142 ;
if ( V_254 -> V_220 != 0 )
return - V_136 ;
V_142 = F_90 ( V_248 ) ;
if ( V_142 )
return V_142 ;
F_63 ( 1 , L_56 , V_125 ,
V_2 -> V_168 , V_2 -> V_20 ) ;
strcpy ( V_254 -> V_208 , L_72 ) ;
F_92 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_72 ( & V_2 -> V_118 , 0 , V_187 , V_255 , V_254 ) ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int F_113 ( struct V_166 * V_166 , void * V_199 ,
const struct V_253 * V_254 )
{
struct V_1 * V_2 = F_85 ( V_166 ) ;
if ( V_254 -> V_220 != 0 )
return - V_136 ;
F_63 ( 1 , L_56 , V_125 ,
V_2 -> V_168 , V_2 -> V_20 ) ;
F_92 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_72 ( & V_2 -> V_118 , 0 , V_187 , V_256 , V_254 ) ;
F_1 ( V_2 , 0 ) ;
F_63 ( 1 , L_73 , V_254 -> signal ,
V_254 -> V_257 ) ;
return 0 ;
}
static int F_114 ( struct V_166 * V_166 , void * V_199 ,
struct V_180 * V_258 )
{
struct V_1 * V_2 = F_85 ( V_166 ) ;
if ( V_258 -> V_187 != 0 )
return - V_136 ;
F_63 ( 1 , L_56 , V_125 ,
V_2 -> V_168 , V_2 -> V_20 ) ;
V_258 -> V_182 = V_2 -> V_183 ;
return 0 ;
}
static int F_115 ( struct V_166 * V_166 , void * V_199 ,
const struct V_180 * V_258 )
{
struct V_1 * V_2 = F_85 ( V_166 ) ;
struct V_180 V_259 = * V_258 ;
if ( V_258 -> V_187 != 0 )
return - V_136 ;
F_63 ( 1 , L_56 , V_125 ,
V_2 -> V_168 , V_2 -> V_20 ) ;
F_92 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_72 ( & V_2 -> V_118 , 0 , V_187 , V_188 , V_258 ) ;
F_72 ( & V_2 -> V_118 , 0 , V_187 , V_260 , & V_259 ) ;
V_2 -> V_183 = V_259 . V_182 ;
F_1 ( V_2 , 0 ) ;
F_67 ( V_2 ) ;
return 0 ;
}
static int F_116 ( struct V_166 * V_166 , void * V_199 ,
struct V_190 * V_191 )
{
struct V_1 * V_2 = F_85 ( V_166 ) ;
F_63 ( 1 , L_56 , V_125 ,
V_2 -> V_168 , V_2 -> V_20 ) ;
V_191 -> V_192 . V_261 . V_262 = V_2 -> V_99 ;
V_191 -> V_192 . V_261 . V_263 = V_264 ;
V_191 -> V_192 . V_261 . V_63 = 0 ;
V_191 -> V_192 . V_261 . V_29 = 0 ;
V_191 -> V_192 . V_261 . V_265 = 6750000 * 4 / 2 ;
V_191 -> V_192 . V_261 . V_152 [ 0 ] = V_2 -> V_100 ;
V_191 -> V_192 . V_261 . V_152 [ 1 ] = V_2 -> V_100 ;
V_191 -> V_192 . V_261 . V_266 [ 0 ] = 21 ;
V_191 -> V_192 . V_261 . V_266 [ 1 ] = 284 ;
memset ( V_191 -> V_192 . V_261 . V_267 , 0 , sizeof( V_191 -> V_192 . V_261 . V_267 ) ) ;
return 0 ;
}
static int F_117 ( struct V_166 * V_166 , void * V_199 ,
struct V_268 * V_269 )
{
struct V_1 * V_2 = F_85 ( V_166 ) ;
if ( V_269 -> type != V_72 )
return - V_136 ;
F_63 ( 1 , L_56 , V_125 ,
V_2 -> V_168 , V_2 -> V_20 ) ;
V_269 -> V_270 . V_271 = 0 ;
V_269 -> V_270 . V_272 = 0 ;
V_269 -> V_270 . V_91 = V_2 -> V_91 ;
V_269 -> V_270 . V_135 = V_2 -> V_135 ;
V_269 -> V_273 = V_269 -> V_270 ;
V_269 -> V_274 . V_275 = 54 ;
V_269 -> V_274 . V_276 = 59 ;
return 0 ;
}
static int F_118 ( struct V_166 * V_166 , void * V_199 ,
struct V_277 * V_278 )
{
struct V_1 * V_2 = F_85 ( V_166 ) ;
F_63 ( 1 , L_56 , V_125 ,
V_2 -> V_168 , V_2 -> V_20 ) ;
V_278 -> V_3 = F_119 ( V_2 , V_278 -> V_278 ) ;
V_278 -> V_134 = 1 ;
return 0 ;
}
static int F_120 ( struct V_166 * V_166 , void * V_199 ,
const struct V_277 * V_278 )
{
struct V_1 * V_2 = F_85 ( V_166 ) ;
F_63 ( 1 , L_56 , V_125 ,
V_2 -> V_168 , V_2 -> V_20 ) ;
return F_61 ( V_2 , V_278 -> V_278 , V_278 -> V_3 ) ;
}
static int F_121 ( struct V_166 * V_166 , void * V_279 )
{
struct V_173 * V_161 = F_89 ( V_166 ) ;
F_63 ( 1 , L_60 , V_125 ) ;
F_122 ( V_166 , V_279 ) ;
F_72 ( V_161 -> V_118 , 0 , V_178 , V_280 ) ;
return 0 ;
}
void F_123 ( struct V_1 * V_2 )
{
struct V_24 * V_24 ;
int V_30 ;
F_6 ( L_74 ) ;
if ( V_2 -> V_40 == V_41 ) {
F_6 ( L_75 ) ;
F_66 ( V_2 ) ;
for ( V_30 = 0 ; V_30 < V_2 -> V_34 . V_43 ; V_30 ++ ) {
V_24 = V_2 -> V_34 . V_24 [ V_30 ] ;
if ( V_24 ) {
if ( ! F_13 () )
F_14 ( V_24 ) ;
else
F_15 ( V_24 ) ;
}
}
}
if ( V_2 -> V_107 )
F_74 ( & V_2 -> V_108 ) ;
if ( V_2 -> V_111 )
F_74 ( & V_2 -> V_112 ) ;
}
void F_124 ( struct V_1 * V_2 )
{
int V_30 , V_55 ;
F_6 ( L_76 ) ;
if ( V_2 -> V_40 == V_41 ) {
F_69 ( V_2 ) ;
F_92 ( V_2 ) ;
}
if ( V_2 -> V_107 )
F_39 ( & V_2 -> V_108 , V_109 + ( V_110 / 10 ) ) ;
if ( V_2 -> V_111 )
F_39 ( & V_2 -> V_112 , V_109 + ( V_110 / 10 ) ) ;
F_60 ( V_2 ) ;
F_62 ( V_2 ) ;
if ( ! ( V_2 -> V_40 == V_41 ) ) {
F_67 ( V_2 ) ;
for ( V_30 = 0 ; V_30 < V_2 -> V_34 . V_43 ; V_30 ++ ) {
V_55 = F_11 ( V_2 -> V_34 . V_24 [ V_30 ] , V_39 ) ;
if ( V_55 ) {
F_3 ( L_26 ,
V_30 , V_55 ) ;
F_12 ( V_2 ) ;
}
}
}
}
static int F_125 ( struct V_1 * V_2 )
{
int V_55 ;
struct V_68 * V_69 ;
V_69 = & V_2 -> V_222 ;
V_69 -> type = V_72 ;
V_69 -> V_281 = V_282 | V_283 | V_284 | V_285 ;
V_69 -> V_286 = V_287 ;
V_69 -> V_288 = V_2 ;
V_69 -> V_289 = sizeof( struct V_65 ) ;
V_69 -> V_6 = & V_290 ;
V_69 -> V_291 = & V_292 ;
V_55 = F_126 ( V_69 ) ;
if ( V_55 < 0 )
return V_55 ;
V_69 = & V_2 -> V_293 ;
V_69 -> type = V_158 ;
V_69 -> V_281 = V_282 | V_283 | V_284 | V_285 ;
V_69 -> V_286 = V_287 ;
V_69 -> V_288 = V_2 ;
V_69 -> V_289 = sizeof( struct V_65 ) ;
V_69 -> V_6 = & V_294 ;
V_69 -> V_291 = & V_292 ;
V_55 = F_126 ( V_69 ) ;
if ( V_55 < 0 )
return V_55 ;
return 0 ;
}
static void F_127 ( struct V_1 * V_2 )
{
#if F_128 ( F_41 )
static const char * const V_229 [] = {
[ V_230 ] = L_64 ,
[ V_231 ] = L_65 ,
[ V_232 ] = L_66 ,
[ V_233 ] = L_67 ,
[ V_234 ] = L_68 ,
} ;
int V_142 , V_30 ;
V_2 -> V_295 . V_29 = V_296 ;
V_142 = F_129 ( & V_2 -> V_161 . V_297 , 1 , & V_2 -> V_295 ) ;
if ( V_142 < 0 )
F_50 ( L_77 ) ;
V_2 -> V_298 . V_29 = V_296 ;
V_142 = F_129 ( & V_2 -> V_162 . V_297 , 1 , & V_2 -> V_298 ) ;
if ( V_142 < 0 )
F_50 ( L_78 ) ;
for ( V_30 = 0 ; V_30 < V_114 ; V_30 ++ ) {
struct V_299 * V_300 = & V_2 -> V_116 [ V_30 ] ;
if ( F_42 ( V_30 ) . type == V_115 )
break;
V_300 -> V_208 = V_229 [ F_42 ( V_30 ) . type ] ;
V_300 -> V_29 = V_301 ;
V_2 -> V_302 [ V_30 ] . V_29 = V_303 ;
switch ( F_42 ( V_30 ) . type ) {
case V_230 :
V_300 -> V_304 = V_305 ;
break;
case V_231 :
V_300 -> V_304 = V_306 ;
break;
case V_232 :
case V_233 :
case V_234 :
default:
V_300 -> V_304 = V_307 ;
break;
}
V_142 = F_129 ( V_300 , 1 , & V_2 -> V_302 [ V_30 ] ) ;
if ( V_142 < 0 )
F_50 ( L_79 , V_30 ) ;
V_142 = F_130 ( V_2 -> V_124 , V_300 ) ;
if ( V_142 < 0 )
F_50 ( L_80 , V_30 ) ;
}
#endif
}
int F_131 ( struct V_1 * V_2 ,
struct V_120 * V_121 )
{
int V_122 = - V_57 ;
struct V_308 * V_309 ;
struct V_310 * V_311 ;
int V_30 , V_142 ;
F_63 ( 1 , L_81 ,
V_121 -> V_145 -> V_146 . V_312 ) ;
if ( F_42 ( 0 ) . type == V_115 )
return 0 ;
V_122 = F_65 ( V_2 -> V_45 ,
V_121 -> V_145 -> V_146 . V_312 , 5 ) ;
if ( V_122 != 0 ) {
F_6 ( L_82 ) ;
return V_122 ;
}
V_309 = V_121 -> V_145 ;
for ( V_30 = 0 ; V_30 < V_309 -> V_146 . V_313 ; V_30 ++ ) {
V_311 = & V_309 -> V_311 [ V_30 ] . V_146 ;
if ( ( ( V_311 -> V_314 & V_315 )
== V_316 ) &&
( ( V_311 -> V_317 & V_318 )
== V_319 ) ) {
T_2 V_228 = F_132 ( V_311 -> V_320 ) ;
V_2 -> V_50 = ( V_228 & 0x07ff ) *
( ( ( V_228 & 0x1800 ) >> 11 ) + 1 ) ;
V_2 -> V_59 = V_311 -> V_314 ;
F_63 ( 1 ,
L_83 ,
V_2 -> V_59 , V_2 -> V_50 ) ;
}
}
if ( ! ( V_2 -> V_59 ) ) {
F_6 ( L_84 ) ;
return - V_21 ;
}
F_133 ( & V_2 -> V_321 ) ;
F_134 ( & V_2 -> V_33 ) ;
F_135 ( & V_2 -> V_28 . V_94 ) ;
F_135 ( & V_2 -> V_101 . V_94 ) ;
F_136 ( & V_2 -> V_108 , F_82 ,
( unsigned long ) V_2 ) ;
F_136 ( & V_2 -> V_112 , F_83 ,
( unsigned long ) V_2 ) ;
V_2 -> V_91 = V_322 ;
V_2 -> V_135 = V_323 ;
V_2 -> V_202 = V_2 -> V_91 * V_2 -> V_135 ;
V_2 -> V_201 = V_2 -> V_202 << 1 ;
V_2 -> V_90 = V_2 -> V_91 << 1 ;
V_2 -> V_99 = 720 ;
V_2 -> V_100 = 1 ;
V_2 -> V_241 = 0 ;
V_2 -> V_183 = 960 ;
V_2 -> V_186 = V_324 ;
F_106 ( V_2 , 0 ) ;
F_137 ( & V_2 -> V_325 ) ;
F_137 ( & V_2 -> V_326 ) ;
V_2 -> V_161 = V_327 ;
V_2 -> V_161 . V_118 = & V_2 -> V_118 ;
V_2 -> V_161 . V_170 = & V_2 -> V_170 ;
V_2 -> V_161 . V_328 = & V_2 -> V_222 ;
V_2 -> V_161 . V_328 -> V_170 = & V_2 -> V_325 ;
strcpy ( V_2 -> V_161 . V_208 , L_85 ) ;
V_2 -> V_162 = V_327 ;
V_2 -> V_162 . V_118 = & V_2 -> V_118 ;
V_2 -> V_162 . V_170 = & V_2 -> V_170 ;
V_2 -> V_162 . V_328 = & V_2 -> V_293 ;
V_2 -> V_162 . V_328 -> V_170 = & V_2 -> V_326 ;
strcpy ( V_2 -> V_162 . V_208 , L_86 ) ;
F_127 ( V_2 ) ;
V_122 = F_125 ( V_2 ) ;
if ( V_122 != 0 ) {
F_63 ( 1 , L_87 ,
V_122 ) ;
return - V_21 ;
}
F_138 ( & V_2 -> V_161 , V_2 ) ;
V_122 = F_139 ( & V_2 -> V_161 , V_175 , - 1 ) ;
if ( V_122 != 0 ) {
F_63 ( 1 , L_88 ,
V_122 ) ;
V_142 = - V_21 ;
goto V_329;
}
F_138 ( & V_2 -> V_162 , V_2 ) ;
V_122 = F_139 ( & V_2 -> V_162 , V_176 , - 1 ) ;
if ( V_122 != 0 ) {
F_63 ( 1 , L_89 ,
V_122 ) ;
V_142 = - V_21 ;
goto V_330;
}
#ifdef F_41
V_122 = F_140 ( V_2 -> V_124 ) ;
if ( V_122 ) {
F_50 ( L_90 ,
V_125 ) ;
V_142 = - V_21 ;
goto V_330;
}
#endif
F_63 ( 1 , L_91 , V_125 ) ;
return 0 ;
V_330:
F_78 ( & V_2 -> V_161 ) ;
V_329:
F_141 ( & V_2 -> V_222 ) ;
F_141 ( & V_2 -> V_293 ) ;
return V_142 ;
}

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
F_27 ( & V_67 -> V_78 ) ;
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
static int F_39 ( struct V_68 * V_114 , const void * V_115 ,
unsigned int * V_116 , unsigned int * V_117 ,
unsigned int V_118 [] , void * V_119 [] )
{
const struct V_120 * V_121 = V_115 ;
struct V_1 * V_2 = F_40 ( V_114 ) ;
unsigned long V_122 = V_2 -> V_123 * V_2 -> V_90 ;
unsigned long V_124 ;
V_124 = V_121 ? V_121 -> V_121 . V_125 . V_126 : V_122 ;
if ( V_124 < V_122 )
return - V_127 ;
* V_117 = 1 ;
V_118 [ 0 ] = V_124 ;
return 0 ;
}
static int
F_41 ( struct V_128 * V_67 )
{
struct V_66 * V_129 = F_42 ( V_67 ) ;
struct V_65 * V_58 = F_7 ( V_129 ,
struct V_65 , V_67 ) ;
struct V_1 * V_2 = F_40 ( V_67 -> V_68 ) ;
V_58 -> V_64 = V_2 -> V_123 * V_2 -> V_90 ;
if ( F_43 ( V_67 , 0 ) < V_58 -> V_64 ) {
F_44 ( L_40 ,
V_130 , F_43 ( V_67 , 0 ) , V_58 -> V_64 ) ;
return - V_127 ;
}
F_45 ( & V_58 -> V_67 . V_70 , 0 , V_58 -> V_64 ) ;
return 0 ;
}
static void
F_46 ( struct V_128 * V_67 )
{
struct V_66 * V_129 = F_42 ( V_67 ) ;
struct V_65 * V_58 = F_7 ( V_129 ,
struct V_65 ,
V_67 ) ;
struct V_1 * V_2 = F_40 ( V_67 -> V_68 ) ;
struct V_25 * V_28 = & V_2 -> V_28 ;
unsigned long V_29 = 0 ;
V_58 -> V_98 = F_37 ( V_67 , 0 ) ;
V_58 -> V_64 = F_43 ( V_67 , 0 ) ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
F_47 ( & V_58 -> V_96 , & V_28 -> V_94 ) ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
F_49 ( V_2 , V_131 , 0x01 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_132 )
{
struct V_133 * V_134 ;
int V_135 , V_136 , V_137 ;
F_51 ( 1 , L_41 ) ;
V_134 = F_52 ( V_132 -> V_45 , 0 ) ;
if ( V_134 && V_134 -> V_138 -> V_139 . V_140 != 5 ) {
F_51 ( 1 , L_42 ) ;
V_135 = F_53 ( V_132 -> V_45 , 0 , 5 ) ;
if ( V_135 < 0 ) {
F_5 ( L_43 ) ;
return - V_141 ;
}
}
V_136 = V_132 -> V_123 / 2 + 2 ;
V_137 = V_132 -> V_91 * 2 ;
F_49 ( V_132 , V_142 , 0x00 ) ;
F_49 ( V_132 , 0x106 , 0x00 ) ;
F_49 ( V_132 , 0x110 , 0x00 ) ;
F_49 ( V_132 , 0x111 , 0x00 ) ;
F_49 ( V_132 , 0x114 , V_137 & 0xff ) ;
F_49 ( V_132 , 0x115 , V_137 >> 8 ) ;
F_49 ( V_132 , 0x112 , 0x00 ) ;
F_49 ( V_132 , 0x113 , 0x00 ) ;
F_49 ( V_132 , 0x116 , V_136 & 0xff ) ;
F_49 ( V_132 , 0x117 , V_136 >> 8 ) ;
F_49 ( V_132 , V_143 , 0xb3 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_132 )
{
F_51 ( 1 , L_44 ) ;
F_49 ( V_132 , V_143 , 0x0 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_51 ( 1 , L_45 ) ;
F_49 ( V_2 , V_143 , 0x0 ) ;
F_56 ( 30 ) ;
F_49 ( V_2 , V_143 , 0xb3 ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
int V_135 = 0 ;
V_2 -> V_40 = V_144 ;
if ( V_2 -> V_19 == V_20 )
return - V_21 ;
else if ( V_135 ) {
V_2 -> V_19 = V_22 ;
F_51 ( 1 , L_46 , V_130 ) ;
return V_135 ;
}
return 0 ;
}
int F_58 ( struct V_68 * V_114 , unsigned int V_145 )
{
struct V_1 * V_2 = F_40 ( V_114 ) ;
int V_55 = 0 ;
F_51 ( 1 , L_47 ,
V_2 -> V_146 ) ;
if ( V_114 -> type == V_72 )
V_2 -> V_74 = 0 ;
else
V_2 -> V_75 = 0 ;
if ( V_2 -> V_146 == 0 ) {
F_48 ( V_2 ) ;
V_55 = F_18 ( V_2 , V_147 ,
V_148 , V_2 -> V_50 ,
F_36 ) ;
if ( V_55 < 0 ) {
F_5 ( L_48 ) ;
return V_55 ;
}
if ( V_114 -> type == V_72 ) {
F_59 ( & V_2 -> V_149 , 0 , V_150 ,
V_151 , 1 ) ;
V_2 -> V_107 = 1 ;
F_38 ( & V_2 -> V_108 , V_109 + ( V_110 / 10 ) ) ;
} else if ( V_114 -> type == V_152 ) {
V_2 -> V_111 = 1 ;
F_38 ( & V_2 -> V_112 , V_109 + ( V_110 / 10 ) ) ;
}
}
V_2 -> V_146 ++ ;
return V_55 ;
}
static void F_60 ( struct V_68 * V_114 )
{
struct V_1 * V_2 = F_40 ( V_114 ) ;
struct V_25 * V_28 = & V_2 -> V_28 ;
unsigned long V_29 = 0 ;
F_51 ( 1 , L_49 , V_2 -> V_146 ) ;
if ( V_2 -> V_146 -- == 1 )
F_11 ( V_2 ) ;
F_59 ( & V_2 -> V_149 , 0 , V_150 , V_151 , 0 ) ;
V_2 -> V_107 = 0 ;
F_61 ( & V_2 -> V_108 ) ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_34 . V_58 != NULL ) {
F_28 ( & V_2 -> V_34 . V_58 -> V_67 . V_70 ,
V_153 ) ;
V_2 -> V_34 . V_58 = NULL ;
}
while ( ! F_31 ( & V_28 -> V_94 ) ) {
struct V_65 * V_58 ;
V_58 = F_32 ( V_28 -> V_94 . V_95 , struct V_65 , V_96 ) ;
F_28 ( & V_58 -> V_67 . V_70 , V_153 ) ;
F_33 ( & V_58 -> V_96 ) ;
}
F_9 ( & V_2 -> V_33 , V_29 ) ;
}
void F_62 ( struct V_68 * V_114 )
{
struct V_1 * V_2 = F_40 ( V_114 ) ;
struct V_25 * V_101 = & V_2 -> V_101 ;
unsigned long V_29 = 0 ;
F_51 ( 1 , L_50 ,
V_2 -> V_146 ) ;
if ( V_2 -> V_146 -- == 1 )
F_11 ( V_2 ) ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_34 . V_102 != NULL ) {
F_28 ( & V_2 -> V_34 . V_102 -> V_67 . V_70 ,
V_153 ) ;
V_2 -> V_34 . V_102 = NULL ;
}
while ( ! F_31 ( & V_101 -> V_94 ) ) {
struct V_65 * V_58 ;
V_58 = F_32 ( V_101 -> V_94 . V_95 , struct V_65 , V_96 ) ;
F_33 ( & V_58 -> V_96 ) ;
F_28 ( & V_58 -> V_67 . V_70 , V_153 ) ;
}
F_9 ( & V_2 -> V_33 , V_29 ) ;
V_2 -> V_111 = 0 ;
F_61 ( & V_2 -> V_112 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
F_51 ( 1 , L_51 ) ;
F_64 ( & V_154 ) ;
F_65 ( & V_2 -> V_155 ) ;
F_65 ( & V_2 -> V_156 ) ;
F_66 ( & V_154 ) ;
}
static void F_67 ( unsigned long V_157 )
{
struct V_1 * V_2 = (struct V_1 * ) V_157 ;
struct V_25 * V_26 = & V_2 -> V_28 ;
struct V_65 * V_58 ;
unsigned char * V_158 ;
unsigned long V_29 = 0 ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
V_58 = V_2 -> V_34 . V_58 ;
if ( V_58 != NULL ) {
V_158 = F_37 ( & V_58 -> V_67 . V_70 , 0 ) ;
memset ( V_158 , 0x00 , V_58 -> V_64 ) ;
F_26 ( V_2 , V_26 , V_58 ) ;
}
F_30 ( V_26 , & V_58 ) ;
if ( V_2 -> V_107 == 1 )
F_38 ( & V_2 -> V_108 , V_109 + ( V_110 / 10 ) ) ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
}
static void F_68 ( unsigned long V_157 )
{
struct V_1 * V_2 = (struct V_1 * ) V_157 ;
struct V_25 * V_26 = & V_2 -> V_101 ;
struct V_65 * V_58 ;
unsigned char * V_159 ;
unsigned long V_29 = 0 ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
V_58 = V_2 -> V_34 . V_102 ;
if ( V_58 != NULL ) {
V_159 = F_37 ( & V_58 -> V_67 . V_70 , 0 ) ;
memset ( V_159 , 0x00 , V_58 -> V_64 ) ;
F_26 ( V_2 , V_26 , V_58 ) ;
}
F_35 ( V_26 , & V_58 ) ;
if ( V_2 -> V_111 == 1 )
F_38 ( & V_2 -> V_112 , V_109 + ( V_110 / 10 ) ) ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
}
static int F_69 ( struct V_160 * V_161 )
{
struct V_1 * V_2 = F_70 ( V_161 ) ;
int V_135 ;
F_51 ( 1 ,
L_52 ,
V_130 , V_2 -> V_162 , V_2 -> V_19 ,
V_2 -> V_146 , V_2 -> V_163 ) ;
if ( F_71 ( & V_2 -> V_164 ) )
return - V_165 ;
V_135 = F_72 ( V_161 ) ;
if ( V_135 ) {
F_3 ( L_53 ,
V_130 , V_135 ) ;
F_66 ( & V_2 -> V_164 ) ;
return V_135 ;
}
if ( V_2 -> V_163 == 0 ) {
F_50 ( V_2 ) ;
F_55 ( V_2 ) ;
V_2 -> V_40 = V_48 ;
V_2 -> V_19 |= V_166 ;
}
V_2 -> V_163 ++ ;
F_66 ( & V_2 -> V_164 ) ;
return V_135 ;
}
static int F_73 ( struct V_160 * V_161 )
{
int V_135 ;
struct V_1 * V_2 = F_70 ( V_161 ) ;
struct V_167 * V_155 = F_74 ( V_161 ) ;
F_51 ( 1 ,
L_52 ,
V_130 , V_2 -> V_162 , V_2 -> V_19 ,
V_2 -> V_146 , V_2 -> V_163 ) ;
F_64 ( & V_2 -> V_164 ) ;
if ( V_155 -> V_168 == V_169 && V_2 -> V_107 ) {
V_2 -> V_107 = 0 ;
F_61 ( & V_2 -> V_108 ) ;
} else if ( V_155 -> V_168 == V_170 &&
V_2 -> V_111 ) {
V_2 -> V_111 = 0 ;
F_61 ( & V_2 -> V_112 ) ;
}
if ( V_2 -> V_19 == V_20 )
goto V_171;
if ( V_2 -> V_163 == 1 ) {
F_59 ( & V_2 -> V_149 , 0 , V_172 , V_173 , 0 ) ;
V_2 -> V_162 = 0 ;
V_135 = F_53 ( V_2 -> V_45 , 0 , 0 ) ;
if ( V_135 < 0 )
F_5 ( L_54 ) ;
}
V_171:
F_75 ( V_161 , NULL ) ;
V_2 -> V_163 -- ;
F_66 ( & V_2 -> V_164 ) ;
return 0 ;
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_174 V_175 = {
. V_176 = V_2 -> V_177 ,
. type = V_178 ,
} ;
F_51 ( 1 , L_55 , V_130 ,
V_2 -> V_162 , V_2 -> V_19 ) ;
if ( V_2 -> V_162 )
return;
V_2 -> V_162 = 1 ;
F_1 ( V_2 , 1 ) ;
F_59 ( & V_2 -> V_149 , 0 , V_150 , V_179 , V_2 -> V_180 ) ;
F_59 ( & V_2 -> V_149 , 0 , V_181 , V_182 , & V_175 ) ;
F_1 ( V_2 , 0 ) ;
}
static int F_77 ( struct V_1 * V_2 , unsigned int V_183 ,
struct V_120 * V_184 )
{
int V_135 ;
int V_91 = V_184 -> V_121 . V_125 . V_91 ;
int V_123 = V_184 -> V_121 . V_125 . V_123 ;
if ( V_184 -> V_121 . V_125 . V_185 != V_186 )
return - V_127 ;
if ( V_91 != 720 )
V_91 = 720 ;
if ( V_123 != 480 )
V_123 = 480 ;
V_184 -> V_121 . V_125 . V_91 = V_91 ;
V_184 -> V_121 . V_125 . V_123 = V_123 ;
V_184 -> V_121 . V_125 . V_185 = V_186 ;
V_184 -> V_121 . V_125 . V_90 = V_91 * 2 ;
V_184 -> V_121 . V_125 . V_126 = V_91 * V_123 * 2 ;
V_184 -> V_121 . V_125 . V_187 = V_188 ;
V_184 -> V_121 . V_125 . V_76 = V_77 ;
V_184 -> V_121 . V_125 . V_189 = 0 ;
if ( V_183 == V_190 )
return 0 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_123 = V_123 ;
V_2 -> V_191 = V_91 * V_123 * 2 ;
V_2 -> V_192 = V_91 * V_123 ;
V_2 -> V_90 = V_91 * 2 ;
if ( V_2 -> V_40 == V_41 ) {
F_51 ( 1 , L_56 ) ;
V_135 = F_57 ( V_2 ) ;
if ( V_135 != 0 ) {
F_51 ( 1 , L_57 ) ;
return V_135 ;
}
}
F_50 ( V_2 ) ;
return 0 ;
}
static int F_78 ( struct V_160 * V_160 , void * V_189 ,
struct V_193 * V_194 )
{
struct V_167 * V_155 = F_74 ( V_160 ) ;
struct V_1 * V_2 = F_70 ( V_160 ) ;
F_51 ( 1 , L_55 , V_130 ,
V_2 -> V_162 , V_2 -> V_19 ) ;
F_79 ( V_194 -> V_195 , L_58 , sizeof( V_194 -> V_195 ) ) ;
F_79 ( V_194 -> V_196 , V_2 -> V_197 . V_198 , sizeof( V_194 -> V_196 ) ) ;
F_80 ( V_2 -> V_45 , V_194 -> V_199 , sizeof( V_194 -> V_199 ) ) ;
V_194 -> V_200 = V_201 |
V_202 |
V_203 |
V_204 ;
if ( V_155 -> V_168 == V_169 )
V_194 -> V_200 |= V_205 ;
else
V_194 -> V_200 |= V_206 ;
V_194 -> V_207 = V_194 -> V_200 | V_208 |
V_206 | V_205 ;
return 0 ;
}
static int F_81 ( struct V_160 * V_160 , void * V_189 ,
struct V_209 * V_175 )
{
if ( V_175 -> V_210 )
return - V_127 ;
F_51 ( 1 , L_59 , V_130 ) ;
V_175 -> type = V_72 ;
strcpy ( V_175 -> V_211 , L_60 ) ;
V_175 -> V_29 = 0 ;
V_175 -> V_185 = V_186 ;
return 0 ;
}
static int F_82 ( struct V_160 * V_160 , void * V_189 ,
struct V_120 * V_175 )
{
struct V_1 * V_2 = F_70 ( V_160 ) ;
F_51 ( 1 , L_55 , V_130 ,
V_2 -> V_162 , V_2 -> V_19 ) ;
V_175 -> V_121 . V_125 . V_91 = V_2 -> V_91 ;
V_175 -> V_121 . V_125 . V_123 = V_2 -> V_123 ;
V_175 -> V_121 . V_125 . V_185 = V_186 ;
V_175 -> V_121 . V_125 . V_90 = V_2 -> V_90 ;
V_175 -> V_121 . V_125 . V_126 = V_2 -> V_191 ;
V_175 -> V_121 . V_125 . V_187 = V_188 ;
V_175 -> V_121 . V_125 . V_76 = V_77 ;
V_175 -> V_121 . V_125 . V_189 = 0 ;
return 0 ;
}
static int F_83 ( struct V_160 * V_160 , void * V_189 ,
struct V_120 * V_175 )
{
struct V_1 * V_2 = F_70 ( V_160 ) ;
F_51 ( 1 , L_55 , V_130 ,
V_2 -> V_162 , V_2 -> V_19 ) ;
return F_77 ( V_2 , V_190 , V_175 ) ;
}
static int F_84 ( struct V_160 * V_160 , void * V_189 ,
struct V_120 * V_175 )
{
struct V_1 * V_2 = F_70 ( V_160 ) ;
int V_55 ;
F_51 ( 1 , L_55 , V_130 ,
V_2 -> V_162 , V_2 -> V_19 ) ;
V_55 = F_4 ( V_2 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( F_85 ( & V_2 -> V_212 ) ) {
F_5 ( L_61 , V_130 ) ;
V_55 = - V_141 ;
goto V_213;
}
V_55 = F_77 ( V_2 , V_214 , V_175 ) ;
V_213:
return V_55 ;
}
static int F_86 ( struct V_160 * V_160 , void * V_189 , T_1 V_215 )
{
struct V_1 * V_2 = F_70 ( V_160 ) ;
F_51 ( 1 , L_55 , V_130 ,
V_2 -> V_162 , V_2 -> V_19 ) ;
if ( V_215 == V_2 -> V_180 )
return 0 ;
if ( V_2 -> V_146 > 0 )
return - V_141 ;
V_2 -> V_180 = V_215 ;
F_76 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_59 ( & V_2 -> V_149 , 0 , V_150 , V_179 , V_215 ) ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int F_87 ( struct V_160 * V_160 , void * V_189 , T_1 * V_215 )
{
struct V_1 * V_2 = F_70 ( V_160 ) ;
F_51 ( 1 , L_55 , V_130 ,
V_2 -> V_162 , V_2 -> V_19 ) ;
* V_215 = V_2 -> V_180 ;
return 0 ;
}
static int F_88 ( struct V_160 * V_160 , void * V_189 ,
struct V_216 * V_217 )
{
struct V_1 * V_2 = F_70 ( V_160 ) ;
unsigned int V_218 ;
static const char * V_219 [] = {
[ V_220 ] = L_62 ,
[ V_221 ] = L_63 ,
[ V_222 ] = L_64 ,
[ V_223 ] = L_65 ,
[ V_224 ] = L_66 ,
[ V_225 ] = L_67 ,
[ V_226 ] = L_68
} ;
F_51 ( 1 , L_55 , V_130 ,
V_2 -> V_162 , V_2 -> V_19 ) ;
V_218 = V_217 -> V_210 ;
if ( V_218 >= V_227 )
return - V_127 ;
if ( F_89 ( V_218 ) . type == 0 )
return - V_127 ;
V_217 -> V_210 = V_218 ;
strcpy ( V_217 -> V_198 , V_219 [ F_89 ( V_218 ) . type ] ) ;
if ( ( F_89 ( V_218 ) . type == V_224 ) ||
( F_89 ( V_218 ) . type == V_223 ) ) {
V_217 -> type |= V_228 ;
V_217 -> V_229 = 1 ;
} else {
V_217 -> type |= V_230 ;
V_217 -> V_229 = 2 ;
}
V_217 -> V_180 = V_2 -> V_155 . V_231 ;
return 0 ;
}
static int F_90 ( struct V_160 * V_160 , void * V_189 , unsigned int * V_30 )
{
struct V_1 * V_2 = F_70 ( V_160 ) ;
F_51 ( 1 , L_55 , V_130 ,
V_2 -> V_162 , V_2 -> V_19 ) ;
* V_30 = V_2 -> V_232 ;
return 0 ;
}
static void F_91 ( struct V_1 * V_2 , int V_210 )
{
int V_30 ;
F_51 ( 1 , L_55 , V_130 ,
V_2 -> V_162 , V_2 -> V_19 ) ;
switch ( F_89 ( V_210 ) . type ) {
case V_222 :
V_2 -> V_233 = V_222 ;
V_2 -> V_234 = 1 ;
break;
case V_221 :
V_2 -> V_233 = V_221 ;
V_2 -> V_234 = 1 ;
break;
case V_224 :
V_2 -> V_233 = V_224 ;
V_2 -> V_234 = 0 ;
break;
default:
F_51 ( 1 , L_69 ,
F_89 ( V_210 ) . type ) ;
break;
}
F_59 ( & V_2 -> V_149 , 0 , V_150 , V_235 ,
F_89 ( V_210 ) . V_236 , 0 , 0 ) ;
for ( V_30 = 0 ; V_30 < V_227 ; V_30 ++ ) {
int V_237 = 0 ;
if ( F_89 ( V_30 ) . V_238 == NULL )
continue;
if ( V_30 == V_210 )
V_237 = 1 ;
else
V_237 = 0 ;
if ( V_237 ) {
( F_89 ( V_30 ) . V_238 ) ( V_2 , V_237 ) ;
} else {
if ( ( F_89 ( V_30 ) . V_238 ) !=
( ( F_89 ( V_210 ) . V_238 ) ) ) {
( F_89 ( V_30 ) . V_238 ) ( V_2 , V_237 ) ;
}
}
}
F_59 ( & V_2 -> V_149 , 0 , V_239 , V_235 ,
F_89 ( V_210 ) . V_240 , 0 , 0 ) ;
}
static int F_92 ( struct V_160 * V_160 , void * V_189 , unsigned int V_210 )
{
struct V_1 * V_2 = F_70 ( V_160 ) ;
F_51 ( 1 , L_70 , V_130 ,
V_210 ) ;
if ( V_210 >= V_227 )
return - V_127 ;
if ( F_89 ( V_210 ) . type == 0 )
return - V_127 ;
V_2 -> V_232 = V_210 ;
F_91 ( V_2 , V_210 ) ;
return 0 ;
}
static int F_93 ( struct V_160 * V_160 , void * V_189 , struct V_241 * V_242 )
{
if ( V_242 -> V_210 > 1 )
return - V_127 ;
F_51 ( 1 , L_59 , V_130 ) ;
if ( V_242 -> V_210 == 0 )
strcpy ( V_242 -> V_198 , L_66 ) ;
else
strcpy ( V_242 -> V_198 , L_71 ) ;
V_242 -> V_243 = V_244 ;
return 0 ;
}
static int F_94 ( struct V_160 * V_160 , void * V_189 , struct V_241 * V_242 )
{
struct V_1 * V_2 = F_70 ( V_160 ) ;
F_51 ( 1 , L_55 , V_130 ,
V_2 -> V_162 , V_2 -> V_19 ) ;
V_242 -> V_210 = V_2 -> V_234 ;
if ( V_242 -> V_210 == 0 )
strcpy ( V_242 -> V_198 , L_66 ) ;
else
strcpy ( V_242 -> V_198 , L_71 ) ;
V_242 -> V_243 = V_244 ;
return 0 ;
}
static int F_95 ( struct V_160 * V_160 , void * V_189 , const struct V_241 * V_242 )
{
struct V_1 * V_2 = F_70 ( V_160 ) ;
if ( V_242 -> V_210 != V_2 -> V_234 )
return - V_127 ;
F_51 ( 1 , L_55 , V_130 ,
V_2 -> V_162 , V_2 -> V_19 ) ;
return 0 ;
}
static int F_96 ( struct V_160 * V_160 , void * V_189 , struct V_245 * V_246 )
{
struct V_1 * V_2 = F_70 ( V_160 ) ;
if ( V_246 -> V_210 != 0 )
return - V_127 ;
F_51 ( 1 , L_55 , V_130 ,
V_2 -> V_162 , V_2 -> V_19 ) ;
strcpy ( V_246 -> V_198 , L_72 ) ;
F_76 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_59 ( & V_2 -> V_149 , 0 , V_181 , V_247 , V_246 ) ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int F_97 ( struct V_160 * V_160 , void * V_189 ,
const struct V_245 * V_246 )
{
struct V_1 * V_2 = F_70 ( V_160 ) ;
if ( V_246 -> V_210 != 0 )
return - V_127 ;
F_51 ( 1 , L_55 , V_130 ,
V_2 -> V_162 , V_2 -> V_19 ) ;
F_76 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_59 ( & V_2 -> V_149 , 0 , V_181 , V_248 , V_246 ) ;
F_1 ( V_2 , 0 ) ;
F_51 ( 1 , L_73 , V_246 -> signal ,
V_246 -> V_249 ) ;
return 0 ;
}
static int F_98 ( struct V_160 * V_160 , void * V_189 ,
struct V_174 * V_250 )
{
struct V_1 * V_2 = F_70 ( V_160 ) ;
if ( V_250 -> V_181 != 0 )
return - V_127 ;
F_51 ( 1 , L_55 , V_130 ,
V_2 -> V_162 , V_2 -> V_19 ) ;
V_250 -> V_176 = V_2 -> V_177 ;
return 0 ;
}
static int F_99 ( struct V_160 * V_160 , void * V_189 ,
const struct V_174 * V_250 )
{
struct V_1 * V_2 = F_70 ( V_160 ) ;
struct V_174 V_251 = * V_250 ;
if ( V_250 -> V_181 != 0 )
return - V_127 ;
F_51 ( 1 , L_55 , V_130 ,
V_2 -> V_162 , V_2 -> V_19 ) ;
F_76 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_59 ( & V_2 -> V_149 , 0 , V_181 , V_182 , V_250 ) ;
F_59 ( & V_2 -> V_149 , 0 , V_181 , V_252 , & V_251 ) ;
V_2 -> V_177 = V_251 . V_176 ;
F_1 ( V_2 , 0 ) ;
F_55 ( V_2 ) ;
return 0 ;
}
static int F_100 ( struct V_160 * V_160 , void * V_189 ,
struct V_120 * V_184 )
{
struct V_1 * V_2 = F_70 ( V_160 ) ;
F_51 ( 1 , L_55 , V_130 ,
V_2 -> V_162 , V_2 -> V_19 ) ;
V_184 -> V_121 . V_253 . V_254 = V_2 -> V_99 ;
V_184 -> V_121 . V_253 . V_255 = V_256 ;
V_184 -> V_121 . V_253 . V_63 = 0 ;
V_184 -> V_121 . V_253 . V_29 = 0 ;
V_184 -> V_121 . V_253 . V_257 = 6750000 * 4 / 2 ;
V_184 -> V_121 . V_253 . V_145 [ 0 ] = V_2 -> V_100 ;
V_184 -> V_121 . V_253 . V_145 [ 1 ] = V_2 -> V_100 ;
V_184 -> V_121 . V_253 . V_258 [ 0 ] = 21 ;
V_184 -> V_121 . V_253 . V_258 [ 1 ] = 284 ;
memset ( V_184 -> V_121 . V_253 . V_259 , 0 , sizeof( V_184 -> V_121 . V_253 . V_259 ) ) ;
return 0 ;
}
static int F_101 ( struct V_160 * V_160 , void * V_189 ,
struct V_260 * V_261 )
{
struct V_1 * V_2 = F_70 ( V_160 ) ;
if ( V_261 -> type != V_72 )
return - V_127 ;
F_51 ( 1 , L_55 , V_130 ,
V_2 -> V_162 , V_2 -> V_19 ) ;
V_261 -> V_262 . V_263 = 0 ;
V_261 -> V_262 . V_264 = 0 ;
V_261 -> V_262 . V_91 = V_2 -> V_91 ;
V_261 -> V_262 . V_123 = V_2 -> V_123 ;
V_261 -> V_265 = V_261 -> V_262 ;
V_261 -> V_266 . V_267 = 54 ;
V_261 -> V_266 . V_268 = 59 ;
return 0 ;
}
static int F_102 ( struct V_160 * V_160 , void * V_189 ,
struct V_269 * V_270 )
{
struct V_1 * V_2 = F_70 ( V_160 ) ;
F_51 ( 1 , L_55 , V_130 ,
V_2 -> V_162 , V_2 -> V_19 ) ;
V_270 -> V_3 = F_103 ( V_2 , V_270 -> V_270 ) ;
V_270 -> V_124 = 1 ;
return 0 ;
}
static int F_104 ( struct V_160 * V_160 , void * V_189 ,
const struct V_269 * V_270 )
{
struct V_1 * V_2 = F_70 ( V_160 ) ;
F_51 ( 1 , L_55 , V_130 ,
V_2 -> V_162 , V_2 -> V_19 ) ;
return F_49 ( V_2 , V_270 -> V_270 , V_270 -> V_3 ) ;
}
static int F_105 ( struct V_160 * V_160 , void * V_271 )
{
struct V_167 * V_155 = F_74 ( V_160 ) ;
F_51 ( 1 , L_59 , V_130 ) ;
F_106 ( V_160 , V_271 ) ;
F_59 ( V_155 -> V_149 , 0 , V_172 , V_272 ) ;
return 0 ;
}
void F_107 ( struct V_1 * V_2 )
{
struct V_24 * V_24 ;
int V_30 ;
F_5 ( L_74 ) ;
if ( V_2 -> V_40 == V_41 ) {
F_5 ( L_75 ) ;
F_54 ( V_2 ) ;
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
F_61 ( & V_2 -> V_108 ) ;
if ( V_2 -> V_111 )
F_61 ( & V_2 -> V_112 ) ;
}
void F_108 ( struct V_1 * V_2 )
{
int V_30 , V_55 ;
F_5 ( L_76 ) ;
if ( V_2 -> V_40 == V_41 ) {
F_57 ( V_2 ) ;
F_76 ( V_2 ) ;
}
if ( V_2 -> V_107 )
F_38 ( & V_2 -> V_108 , V_109 + ( V_110 / 10 ) ) ;
if ( V_2 -> V_111 )
F_38 ( & V_2 -> V_112 , V_109 + ( V_110 / 10 ) ) ;
F_48 ( V_2 ) ;
F_50 ( V_2 ) ;
if ( ! ( V_2 -> V_40 == V_41 ) ) {
F_55 ( V_2 ) ;
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
static int F_109 ( struct V_1 * V_2 )
{
int V_55 ;
struct V_68 * V_69 ;
V_69 = & V_2 -> V_212 ;
V_69 -> type = V_72 ;
V_69 -> V_273 = V_274 | V_275 | V_276 | V_277 ;
V_69 -> V_278 = V_279 ;
V_69 -> V_280 = V_2 ;
V_69 -> V_281 = sizeof( struct V_65 ) ;
V_69 -> V_6 = & V_282 ;
V_69 -> V_283 = & V_284 ;
V_55 = F_110 ( V_69 ) ;
if ( V_55 < 0 )
return V_55 ;
V_69 = & V_2 -> V_285 ;
V_69 -> type = V_152 ;
V_69 -> V_273 = V_274 | V_275 | V_276 | V_277 ;
V_69 -> V_278 = V_279 ;
V_69 -> V_280 = V_2 ;
V_69 -> V_281 = sizeof( struct V_65 ) ;
V_69 -> V_6 = & V_286 ;
V_69 -> V_283 = & V_284 ;
V_55 = F_110 ( V_69 ) ;
if ( V_55 < 0 )
return V_55 ;
return 0 ;
}
int F_111 ( struct V_1 * V_2 ,
struct V_133 * V_287 )
{
int V_288 = - V_57 ;
struct V_289 * V_290 ;
struct V_291 * V_292 ;
int V_30 , V_135 ;
F_51 ( 1 , L_77 ,
V_287 -> V_138 -> V_139 . V_293 ) ;
V_288 = F_53 ( V_2 -> V_45 ,
V_287 -> V_138 -> V_139 . V_293 , 5 ) ;
if ( V_288 != 0 ) {
F_5 ( L_78 ) ;
return V_288 ;
}
V_290 = V_287 -> V_138 ;
for ( V_30 = 0 ; V_30 < V_290 -> V_139 . V_294 ; V_30 ++ ) {
V_292 = & V_290 -> V_292 [ V_30 ] . V_139 ;
if ( ( ( V_292 -> V_295 & V_296 )
== V_297 ) &&
( ( V_292 -> V_298 & V_299 )
== V_300 ) ) {
T_2 V_218 = F_112 ( V_292 -> V_301 ) ;
V_2 -> V_50 = ( V_218 & 0x07ff ) *
( ( ( V_218 & 0x1800 ) >> 11 ) + 1 ) ;
V_2 -> V_59 = V_292 -> V_295 ;
F_51 ( 1 ,
L_79 ,
V_2 -> V_59 , V_2 -> V_50 ) ;
}
}
if ( ! ( V_2 -> V_59 ) ) {
F_5 ( L_80 ) ;
return - V_21 ;
}
F_113 ( & V_2 -> V_302 ) ;
F_114 ( & V_2 -> V_33 ) ;
F_115 ( & V_2 -> V_28 . V_94 ) ;
F_115 ( & V_2 -> V_101 . V_94 ) ;
F_116 ( & V_2 -> V_108 , F_67 ,
( unsigned long ) V_2 ) ;
F_116 ( & V_2 -> V_112 , F_68 ,
( unsigned long ) V_2 ) ;
V_2 -> V_91 = V_303 ;
V_2 -> V_123 = V_304 ;
V_2 -> V_192 = V_2 -> V_91 * V_2 -> V_123 ;
V_2 -> V_191 = V_2 -> V_192 << 1 ;
V_2 -> V_90 = V_2 -> V_91 << 1 ;
V_2 -> V_99 = 720 ;
V_2 -> V_100 = 1 ;
V_2 -> V_234 = 0 ;
V_2 -> V_177 = 960 ;
V_2 -> V_180 = V_305 ;
F_91 ( V_2 , 0 ) ;
F_117 ( & V_2 -> V_306 ) ;
F_117 ( & V_2 -> V_307 ) ;
V_2 -> V_155 = V_308 ;
V_2 -> V_155 . V_149 = & V_2 -> V_149 ;
V_2 -> V_155 . V_164 = & V_2 -> V_164 ;
V_2 -> V_155 . V_309 = & V_2 -> V_212 ;
V_2 -> V_155 . V_309 -> V_164 = & V_2 -> V_306 ;
strcpy ( V_2 -> V_155 . V_198 , L_81 ) ;
V_2 -> V_156 = V_308 ;
V_2 -> V_156 . V_149 = & V_2 -> V_149 ;
V_2 -> V_156 . V_164 = & V_2 -> V_164 ;
V_2 -> V_156 . V_309 = & V_2 -> V_285 ;
V_2 -> V_156 . V_309 -> V_164 = & V_2 -> V_307 ;
strcpy ( V_2 -> V_156 . V_198 , L_82 ) ;
V_288 = F_109 ( V_2 ) ;
if ( V_288 != 0 ) {
F_51 ( 1 , L_83 ,
V_288 ) ;
return - V_21 ;
}
F_118 ( & V_2 -> V_155 , V_2 ) ;
V_288 = F_119 ( & V_2 -> V_155 , V_169 , - 1 ) ;
if ( V_288 != 0 ) {
F_51 ( 1 , L_84 ,
V_288 ) ;
V_135 = - V_21 ;
goto V_310;
}
F_118 ( & V_2 -> V_156 , V_2 ) ;
V_288 = F_119 ( & V_2 -> V_156 , V_170 , - 1 ) ;
if ( V_288 != 0 ) {
F_51 ( 1 , L_85 ,
V_288 ) ;
V_135 = - V_21 ;
goto V_311;
}
F_51 ( 1 , L_86 , V_130 ) ;
return 0 ;
V_311:
F_65 ( & V_2 -> V_155 ) ;
V_310:
F_120 ( & V_2 -> V_212 ) ;
F_120 ( & V_2 -> V_285 ) ;
return V_135 ;
}

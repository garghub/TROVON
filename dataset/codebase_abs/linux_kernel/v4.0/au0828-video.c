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
F_3 ( L_28 , V_58 , V_58 -> V_66 ) ;
V_58 -> V_67 . V_68 . V_69 = V_2 -> V_70 ++ ;
V_58 -> V_67 . V_68 . V_71 = V_72 ;
F_27 ( & V_58 -> V_67 . V_68 . V_73 ) ;
F_28 ( & V_58 -> V_67 , V_74 ) ;
}
static inline void F_29 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_65 * V_58 )
{
F_3 ( L_28 , V_58 , V_58 -> V_66 ) ;
V_58 -> V_67 . V_68 . V_69 = V_2 -> V_75 ++ ;
V_58 -> V_67 . V_68 . V_71 = V_72 ;
F_27 ( & V_58 -> V_67 . V_68 . V_73 ) ;
F_28 ( & V_58 -> V_67 , V_74 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_65 * V_58 ,
unsigned char * V_76 ,
unsigned char * V_77 , unsigned long V_78 )
{
void * V_79 , * V_80 , * V_81 ;
int V_82 , V_83 , V_63 , V_84 , V_85 ;
int V_86 = V_2 -> V_87 << 1 ;
if ( V_78 == 0 )
return;
if ( V_26 -> V_88 + V_78 > V_58 -> V_64 )
V_78 = V_58 -> V_64 - V_26 -> V_88 ;
V_81 = V_76 ;
V_85 = V_78 ;
if ( V_58 -> V_66 )
V_79 = V_77 ;
else
V_79 = V_77 + V_86 ;
V_82 = V_26 -> V_88 / V_86 ;
V_83 = V_26 -> V_88 % V_86 ;
V_63 = V_82 * V_86 * 2 + V_83 ;
V_80 = V_79 + V_63 ;
V_84 = V_86 - V_83 ;
V_84 = V_84 > V_85 ? V_85 : V_84 ;
if ( ( char * ) V_80 + V_84 > ( char * ) V_77 + V_58 -> V_64 ) {
F_3 ( L_29 ,
( ( char * ) V_80 + V_84 ) -
( ( char * ) V_77 + V_58 -> V_64 ) ) ;
V_85 = ( char * ) V_77 + V_58 -> V_64 - ( char * ) V_80 ;
V_84 = V_85 ;
}
if ( V_84 <= 0 )
return;
memcpy ( V_80 , V_81 , V_84 ) ;
V_85 -= V_84 ;
while ( V_85 > 0 ) {
V_80 += V_84 + V_86 ;
V_81 += V_84 ;
if ( V_86 > V_85 )
V_84 = V_85 ;
else
V_84 = V_86 ;
if ( ( char * ) V_80 + V_84 > ( char * ) V_77 +
V_58 -> V_64 ) {
F_3 ( L_30 ,
( ( char * ) V_80 + V_84 ) -
( ( char * ) V_77 + V_58 -> V_64 ) ) ;
V_84 = V_85 = ( char * ) V_77 + V_58 -> V_64 -
( char * ) V_80 ;
}
if ( V_84 <= 0 )
break;
memcpy ( V_80 , V_81 , V_84 ) ;
V_85 -= V_84 ;
}
if ( V_63 > 1440 ) {
if ( V_77 [ 0 ] < 0x60 && V_77 [ 1440 ] < 0x60 )
V_2 -> V_89 = 1 ;
}
V_26 -> V_88 += V_78 ;
}
static inline void F_31 ( struct V_25 * V_26 ,
struct V_65 * * V_58 )
{
struct V_1 * V_2 = F_7 ( V_26 , struct V_1 , V_28 ) ;
if ( F_32 ( & V_26 -> V_90 ) ) {
F_3 ( L_31 ) ;
V_2 -> V_34 . V_58 = NULL ;
* V_58 = NULL ;
return;
}
* V_58 = F_33 ( V_26 -> V_90 . V_91 , struct V_65 , V_92 ) ;
F_34 ( & ( * V_58 ) -> V_92 ) ;
V_26 -> V_88 = 0 ;
( * V_58 ) -> V_93 = ( * V_58 ) -> V_94 ;
V_2 -> V_34 . V_58 = * V_58 ;
return;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_65 * V_58 ,
unsigned char * V_76 ,
unsigned char * V_77 , unsigned long V_78 )
{
unsigned char * V_80 , * V_81 ;
int V_86 ;
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
if ( V_76 == NULL ) {
F_3 ( L_34 ) ;
return;
}
if ( V_77 == NULL ) {
F_3 ( L_35 ) ;
return;
}
V_86 = V_2 -> V_95 ;
if ( V_26 -> V_88 + V_78 > V_58 -> V_64 )
V_78 = V_58 -> V_64 - V_26 -> V_88 ;
V_81 = V_76 ;
V_80 = V_77 + ( V_26 -> V_88 / 2 ) ;
if ( V_58 -> V_66 == 0 )
V_80 += V_86 * V_2 -> V_96 ;
for ( V_30 = 0 ; V_30 < V_78 ; V_30 += 2 )
V_80 [ V_53 ++ ] = V_81 [ V_30 + 1 ] ;
V_26 -> V_88 += V_78 ;
}
static inline void F_36 ( struct V_25 * V_26 ,
struct V_65 * * V_58 )
{
struct V_1 * V_2 = F_7 ( V_26 , struct V_1 , V_97 ) ;
if ( F_32 ( & V_26 -> V_90 ) ) {
F_3 ( L_31 ) ;
V_2 -> V_34 . V_98 = NULL ;
* V_58 = NULL ;
return;
}
* V_58 = F_33 ( V_26 -> V_90 . V_91 , struct V_65 , V_92 ) ;
F_34 ( & ( * V_58 ) -> V_92 ) ;
V_26 -> V_88 = 0 ;
( * V_58 ) -> V_93 = ( * V_58 ) -> V_94 ;
V_2 -> V_34 . V_98 = * V_58 ;
return;
}
static inline int F_37 ( struct V_1 * V_2 , struct V_24 * V_24 )
{
struct V_65 * V_58 ;
struct V_65 * V_98 ;
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_25 * V_99 = & V_2 -> V_97 ;
unsigned char * V_77 = NULL ;
unsigned char * V_100 = NULL ;
int V_30 , V_78 = 0 , V_55 = 1 ;
unsigned char * V_76 ;
unsigned char V_101 ;
unsigned int V_102 ;
unsigned int V_85 , V_84 ;
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
V_77 = F_38 ( & V_58 -> V_67 , 0 ) ;
V_98 = V_2 -> V_34 . V_98 ;
if ( V_98 != NULL )
V_100 = F_38 ( & V_98 -> V_67 , 0 ) ;
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
V_76 = V_24 -> V_44 + V_24 -> V_37 [ V_30 ] . V_63 ;
V_101 = V_76 [ 0 ] ;
V_78 = V_24 -> V_37 [ V_30 ] . V_38 - 4 ;
V_76 += 4 ;
if ( V_101 & 0x80 ) {
V_78 -= 4 ;
V_76 += 4 ;
F_3 ( L_37 ,
( V_101 & 0x40 ) ? L_38 : L_39 ) ;
if ( V_101 & 0x40 ) {
if ( V_98 != NULL )
F_29 ( V_2 ,
V_99 ,
V_98 ) ;
F_36 ( V_99 , & V_98 ) ;
if ( V_98 == NULL )
V_100 = NULL ;
else
V_100 = F_38 (
& V_98 -> V_67 , 0 ) ;
if ( V_58 != NULL )
F_26 ( V_2 , V_26 , V_58 ) ;
F_31 ( V_26 , & V_58 ) ;
if ( V_58 == NULL )
V_77 = NULL ;
else
V_77 = F_38 ( & V_58 -> V_67 , 0 ) ;
if ( V_2 -> V_103 )
F_39 ( & V_2 -> V_104 ,
V_105 + ( V_106 / 10 ) ) ;
if ( V_2 -> V_107 )
F_39 ( & V_2 -> V_108 ,
V_105 + ( V_106 / 10 ) ) ;
}
if ( V_58 != NULL ) {
if ( V_101 & 0x40 )
V_58 -> V_66 = 1 ;
else
V_58 -> V_66 = 0 ;
}
if ( V_98 != NULL ) {
if ( V_101 & 0x40 )
V_98 -> V_66 = 1 ;
else
V_98 -> V_66 = 0 ;
}
V_2 -> V_109 = 0 ;
V_99 -> V_88 = 0 ;
V_26 -> V_88 = 0 ;
}
V_102 = V_2 -> V_95 * V_2 -> V_96 * 2 ;
if ( V_2 -> V_109 < V_102 ) {
V_85 = V_102 - V_2 -> V_109 ;
if ( V_78 < V_85 )
V_84 = V_78 ;
else
V_84 = V_85 ;
if ( V_98 != NULL )
F_35 ( V_2 , V_99 , V_98 , V_76 ,
V_100 , V_78 ) ;
V_78 -= V_84 ;
V_76 += V_84 ;
V_2 -> V_109 += V_84 ;
}
if ( V_2 -> V_109 >= V_102 && V_58 != NULL )
F_30 ( V_2 , V_26 , V_58 , V_76 , V_77 , V_78 ) ;
}
return V_55 ;
}
static int F_40 ( struct V_110 * V_111 , const struct V_112 * V_113 ,
unsigned int * V_114 , unsigned int * V_115 ,
unsigned int V_116 [] , void * V_117 [] )
{
struct V_1 * V_2 = F_41 ( V_111 ) ;
unsigned long V_118 = V_2 -> V_119 * V_2 -> V_86 ;
unsigned long V_120 ;
V_120 = V_113 ? V_113 -> V_113 . V_121 . V_122 : V_118 ;
if ( V_120 < V_118 )
return - V_123 ;
* V_115 = 1 ;
V_116 [ 0 ] = V_120 ;
return 0 ;
}
static int
F_42 ( struct V_124 * V_67 )
{
struct V_65 * V_58 = F_7 ( V_67 , struct V_65 , V_67 ) ;
struct V_1 * V_2 = F_41 ( V_67 -> V_110 ) ;
V_58 -> V_64 = V_2 -> V_119 * V_2 -> V_86 ;
if ( F_43 ( V_67 , 0 ) < V_58 -> V_64 ) {
F_44 ( L_40 ,
V_125 , F_43 ( V_67 , 0 ) , V_58 -> V_64 ) ;
return - V_123 ;
}
F_45 ( & V_58 -> V_67 , 0 , V_58 -> V_64 ) ;
return 0 ;
}
static void
F_46 ( struct V_124 * V_67 )
{
struct V_65 * V_58 = F_7 ( V_67 ,
struct V_65 ,
V_67 ) ;
struct V_1 * V_2 = F_41 ( V_67 -> V_110 ) ;
struct V_25 * V_28 = & V_2 -> V_28 ;
unsigned long V_29 = 0 ;
V_58 -> V_94 = F_38 ( V_67 , 0 ) ;
V_58 -> V_64 = F_43 ( V_67 , 0 ) ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
F_47 ( & V_58 -> V_92 , & V_28 -> V_90 ) ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
F_49 ( V_2 , V_126 , 0x01 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_127 )
{
struct V_128 * V_129 ;
int V_130 , V_131 , V_132 ;
F_51 ( 1 , L_41 ) ;
V_129 = F_52 ( V_127 -> V_45 , 0 ) ;
if ( V_129 && V_129 -> V_133 -> V_134 . V_135 != 5 ) {
F_51 ( 1 , L_42 ) ;
V_130 = F_53 ( V_127 -> V_45 , 0 , 5 ) ;
if ( V_130 < 0 ) {
F_5 ( L_43 ) ;
return - V_136 ;
}
}
V_131 = V_127 -> V_119 / 2 + 2 ;
V_132 = V_127 -> V_87 * 2 ;
F_49 ( V_127 , V_137 , 0x00 ) ;
F_49 ( V_127 , 0x106 , 0x00 ) ;
F_49 ( V_127 , 0x110 , 0x00 ) ;
F_49 ( V_127 , 0x111 , 0x00 ) ;
F_49 ( V_127 , 0x114 , V_132 & 0xff ) ;
F_49 ( V_127 , 0x115 , V_132 >> 8 ) ;
F_49 ( V_127 , 0x112 , 0x00 ) ;
F_49 ( V_127 , 0x113 , 0x00 ) ;
F_49 ( V_127 , 0x116 , V_131 & 0xff ) ;
F_49 ( V_127 , 0x117 , V_131 >> 8 ) ;
F_49 ( V_127 , V_138 , 0xb3 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_127 )
{
F_51 ( 1 , L_44 ) ;
F_49 ( V_127 , V_138 , 0x0 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_51 ( 1 , L_45 ) ;
F_49 ( V_2 , V_138 , 0x0 ) ;
F_56 ( 30 ) ;
F_49 ( V_2 , V_138 , 0xb3 ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
int V_130 = 0 ;
V_2 -> V_40 = V_139 ;
if ( V_2 -> V_19 == V_20 )
return - V_21 ;
else if ( V_130 ) {
V_2 -> V_19 = V_22 ;
F_51 ( 1 , L_46 , V_125 ) ;
return V_130 ;
}
return 0 ;
}
int F_58 ( struct V_110 * V_111 , unsigned int V_140 )
{
struct V_1 * V_2 = F_41 ( V_111 ) ;
int V_55 = 0 ;
F_51 ( 1 , L_47 ,
V_2 -> V_141 ) ;
if ( V_111 -> type == V_142 )
V_2 -> V_70 = 0 ;
else
V_2 -> V_75 = 0 ;
if ( V_2 -> V_141 == 0 ) {
F_48 ( V_2 ) ;
V_55 = F_18 ( V_2 , V_143 ,
V_144 , V_2 -> V_50 ,
F_37 ) ;
if ( V_55 < 0 ) {
F_5 ( L_48 ) ;
return V_55 ;
}
if ( V_111 -> type == V_142 ) {
F_59 ( & V_2 -> V_145 , 0 , V_146 ,
V_147 , 1 ) ;
V_2 -> V_103 = 1 ;
F_39 ( & V_2 -> V_104 , V_105 + ( V_106 / 10 ) ) ;
} else if ( V_111 -> type == V_148 ) {
V_2 -> V_107 = 1 ;
F_39 ( & V_2 -> V_108 , V_105 + ( V_106 / 10 ) ) ;
}
}
V_2 -> V_141 ++ ;
return V_55 ;
}
static void F_60 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = F_41 ( V_111 ) ;
struct V_25 * V_28 = & V_2 -> V_28 ;
unsigned long V_29 = 0 ;
F_51 ( 1 , L_49 , V_2 -> V_141 ) ;
if ( V_2 -> V_141 -- == 1 )
F_11 ( V_2 ) ;
F_59 ( & V_2 -> V_145 , 0 , V_146 , V_147 , 0 ) ;
V_2 -> V_103 = 0 ;
F_61 ( & V_2 -> V_104 ) ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_34 . V_58 != NULL ) {
F_28 ( & V_2 -> V_34 . V_58 -> V_67 , V_149 ) ;
V_2 -> V_34 . V_58 = NULL ;
}
while ( ! F_32 ( & V_28 -> V_90 ) ) {
struct V_65 * V_58 ;
V_58 = F_33 ( V_28 -> V_90 . V_91 , struct V_65 , V_92 ) ;
F_28 ( & V_58 -> V_67 , V_149 ) ;
F_34 ( & V_58 -> V_92 ) ;
}
F_9 ( & V_2 -> V_33 , V_29 ) ;
}
void F_62 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = F_41 ( V_111 ) ;
struct V_25 * V_97 = & V_2 -> V_97 ;
unsigned long V_29 = 0 ;
F_51 ( 1 , L_50 ,
V_2 -> V_141 ) ;
if ( V_2 -> V_141 -- == 1 )
F_11 ( V_2 ) ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_34 . V_98 != NULL ) {
F_28 ( & V_2 -> V_34 . V_98 -> V_67 ,
V_149 ) ;
V_2 -> V_34 . V_98 = NULL ;
}
while ( ! F_32 ( & V_97 -> V_90 ) ) {
struct V_65 * V_58 ;
V_58 = F_33 ( V_97 -> V_90 . V_91 , struct V_65 , V_92 ) ;
F_34 ( & V_58 -> V_92 ) ;
F_28 ( & V_58 -> V_67 , V_149 ) ;
}
F_9 ( & V_2 -> V_33 , V_29 ) ;
V_2 -> V_107 = 0 ;
F_61 ( & V_2 -> V_108 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
F_51 ( 1 , L_51 ) ;
F_64 ( & V_150 ) ;
if ( V_2 -> V_151 )
F_65 ( V_2 -> V_151 ) ;
if ( V_2 -> V_152 )
F_65 ( V_2 -> V_152 ) ;
F_66 ( & V_150 ) ;
}
static void F_67 ( unsigned long V_153 )
{
struct V_1 * V_2 = (struct V_1 * ) V_153 ;
struct V_25 * V_26 = & V_2 -> V_28 ;
struct V_65 * V_58 ;
unsigned char * V_154 ;
unsigned long V_29 = 0 ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
V_58 = V_2 -> V_34 . V_58 ;
if ( V_58 != NULL ) {
V_154 = F_38 ( & V_58 -> V_67 , 0 ) ;
memset ( V_154 , 0x00 , V_58 -> V_64 ) ;
F_26 ( V_2 , V_26 , V_58 ) ;
}
F_31 ( V_26 , & V_58 ) ;
if ( V_2 -> V_103 == 1 )
F_39 ( & V_2 -> V_104 , V_105 + ( V_106 / 10 ) ) ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
}
static void F_68 ( unsigned long V_153 )
{
struct V_1 * V_2 = (struct V_1 * ) V_153 ;
struct V_25 * V_26 = & V_2 -> V_97 ;
struct V_65 * V_58 ;
unsigned char * V_155 ;
unsigned long V_29 = 0 ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
V_58 = V_2 -> V_34 . V_98 ;
if ( V_58 != NULL ) {
V_155 = F_38 ( & V_58 -> V_67 , 0 ) ;
memset ( V_155 , 0x00 , V_58 -> V_64 ) ;
F_29 ( V_2 , V_26 , V_58 ) ;
}
F_36 ( V_26 , & V_58 ) ;
if ( V_2 -> V_107 == 1 )
F_39 ( & V_2 -> V_108 , V_105 + ( V_106 / 10 ) ) ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
}
static int F_69 ( struct V_156 * V_157 )
{
struct V_1 * V_2 = F_70 ( V_157 ) ;
int V_130 ;
F_51 ( 1 ,
L_52 ,
V_125 , V_2 -> V_158 , V_2 -> V_19 ,
V_2 -> V_141 , V_2 -> V_159 ) ;
if ( F_71 ( & V_2 -> V_160 ) )
return - V_161 ;
V_130 = F_72 ( V_157 ) ;
if ( V_130 ) {
F_3 ( L_53 ,
V_125 , V_130 ) ;
F_66 ( & V_2 -> V_160 ) ;
return V_130 ;
}
if ( V_2 -> V_159 == 0 ) {
F_50 ( V_2 ) ;
F_55 ( V_2 ) ;
V_2 -> V_40 = V_48 ;
V_2 -> V_19 |= V_162 ;
}
V_2 -> V_159 ++ ;
F_66 ( & V_2 -> V_160 ) ;
return V_130 ;
}
static int F_73 ( struct V_156 * V_157 )
{
int V_130 ;
struct V_1 * V_2 = F_70 ( V_157 ) ;
struct V_163 * V_151 = F_74 ( V_157 ) ;
F_51 ( 1 ,
L_52 ,
V_125 , V_2 -> V_158 , V_2 -> V_19 ,
V_2 -> V_141 , V_2 -> V_159 ) ;
F_64 ( & V_2 -> V_160 ) ;
if ( V_151 -> V_164 == V_165 && V_2 -> V_103 ) {
V_2 -> V_103 = 0 ;
F_61 ( & V_2 -> V_104 ) ;
} else if ( V_151 -> V_164 == V_166 &&
V_2 -> V_107 ) {
V_2 -> V_107 = 0 ;
F_61 ( & V_2 -> V_108 ) ;
}
if ( V_2 -> V_19 == V_20 )
goto V_167;
if ( V_2 -> V_159 == 1 ) {
F_59 ( & V_2 -> V_145 , 0 , V_168 , V_169 , 0 ) ;
V_2 -> V_158 = 0 ;
V_130 = F_53 ( V_2 -> V_45 , 0 , 0 ) ;
if ( V_130 < 0 )
F_5 ( L_54 ) ;
}
V_167:
F_75 ( V_157 , NULL ) ;
V_2 -> V_159 -- ;
F_66 ( & V_2 -> V_160 ) ;
return 0 ;
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_170 V_171 = {
. V_172 = V_2 -> V_173 ,
. type = V_174 ,
} ;
F_51 ( 1 , L_55 , V_125 ,
V_2 -> V_158 , V_2 -> V_19 ) ;
if ( V_2 -> V_158 )
return;
V_2 -> V_158 = 1 ;
F_1 ( V_2 , 1 ) ;
F_59 ( & V_2 -> V_145 , 0 , V_146 , V_175 , V_2 -> V_176 ) ;
F_59 ( & V_2 -> V_145 , 0 , V_177 , V_178 , & V_171 ) ;
F_1 ( V_2 , 0 ) ;
}
static int F_77 ( struct V_1 * V_2 , unsigned int V_179 ,
struct V_112 * V_180 )
{
int V_130 ;
int V_87 = V_180 -> V_113 . V_121 . V_87 ;
int V_119 = V_180 -> V_113 . V_121 . V_119 ;
if ( V_180 -> V_113 . V_121 . V_181 != V_182 )
return - V_123 ;
if ( V_87 != 720 )
V_87 = 720 ;
if ( V_119 != 480 )
V_119 = 480 ;
V_180 -> V_113 . V_121 . V_87 = V_87 ;
V_180 -> V_113 . V_121 . V_119 = V_119 ;
V_180 -> V_113 . V_121 . V_181 = V_182 ;
V_180 -> V_113 . V_121 . V_86 = V_87 * 2 ;
V_180 -> V_113 . V_121 . V_122 = V_87 * V_119 * 2 ;
V_180 -> V_113 . V_121 . V_183 = V_184 ;
V_180 -> V_113 . V_121 . V_71 = V_72 ;
V_180 -> V_113 . V_121 . V_185 = 0 ;
if ( V_179 == V_186 )
return 0 ;
V_2 -> V_87 = V_87 ;
V_2 -> V_119 = V_119 ;
V_2 -> V_187 = V_87 * V_119 * 2 ;
V_2 -> V_188 = V_87 * V_119 ;
V_2 -> V_86 = V_87 * 2 ;
if ( V_2 -> V_40 == V_41 ) {
F_51 ( 1 , L_56 ) ;
V_130 = F_57 ( V_2 ) ;
if ( V_130 != 0 ) {
F_51 ( 1 , L_57 ) ;
return V_130 ;
}
}
F_50 ( V_2 ) ;
return 0 ;
}
static int F_78 ( struct V_156 * V_156 , void * V_185 ,
struct V_189 * V_190 )
{
struct V_163 * V_151 = F_74 ( V_156 ) ;
struct V_1 * V_2 = F_70 ( V_156 ) ;
F_51 ( 1 , L_55 , V_125 ,
V_2 -> V_158 , V_2 -> V_19 ) ;
F_79 ( V_190 -> V_191 , L_58 , sizeof( V_190 -> V_191 ) ) ;
F_79 ( V_190 -> V_192 , V_2 -> V_193 . V_194 , sizeof( V_190 -> V_192 ) ) ;
F_80 ( V_2 -> V_45 , V_190 -> V_195 , sizeof( V_190 -> V_195 ) ) ;
V_190 -> V_196 = V_197 |
V_198 |
V_199 |
V_200 ;
if ( V_151 -> V_164 == V_165 )
V_190 -> V_196 |= V_201 ;
else
V_190 -> V_196 |= V_202 ;
V_190 -> V_203 = V_190 -> V_196 | V_204 |
V_202 | V_201 ;
return 0 ;
}
static int F_81 ( struct V_156 * V_156 , void * V_185 ,
struct V_205 * V_171 )
{
if ( V_171 -> V_206 )
return - V_123 ;
F_51 ( 1 , L_59 , V_125 ) ;
V_171 -> type = V_142 ;
strcpy ( V_171 -> V_207 , L_60 ) ;
V_171 -> V_29 = 0 ;
V_171 -> V_181 = V_182 ;
return 0 ;
}
static int F_82 ( struct V_156 * V_156 , void * V_185 ,
struct V_112 * V_171 )
{
struct V_1 * V_2 = F_70 ( V_156 ) ;
F_51 ( 1 , L_55 , V_125 ,
V_2 -> V_158 , V_2 -> V_19 ) ;
V_171 -> V_113 . V_121 . V_87 = V_2 -> V_87 ;
V_171 -> V_113 . V_121 . V_119 = V_2 -> V_119 ;
V_171 -> V_113 . V_121 . V_181 = V_182 ;
V_171 -> V_113 . V_121 . V_86 = V_2 -> V_86 ;
V_171 -> V_113 . V_121 . V_122 = V_2 -> V_187 ;
V_171 -> V_113 . V_121 . V_183 = V_184 ;
V_171 -> V_113 . V_121 . V_71 = V_72 ;
V_171 -> V_113 . V_121 . V_185 = 0 ;
return 0 ;
}
static int F_83 ( struct V_156 * V_156 , void * V_185 ,
struct V_112 * V_171 )
{
struct V_1 * V_2 = F_70 ( V_156 ) ;
F_51 ( 1 , L_55 , V_125 ,
V_2 -> V_158 , V_2 -> V_19 ) ;
return F_77 ( V_2 , V_186 , V_171 ) ;
}
static int F_84 ( struct V_156 * V_156 , void * V_185 ,
struct V_112 * V_171 )
{
struct V_1 * V_2 = F_70 ( V_156 ) ;
int V_55 ;
F_51 ( 1 , L_55 , V_125 ,
V_2 -> V_158 , V_2 -> V_19 ) ;
V_55 = F_4 ( V_2 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( F_85 ( & V_2 -> V_208 ) ) {
F_5 ( L_61 , V_125 ) ;
V_55 = - V_136 ;
goto V_209;
}
V_55 = F_77 ( V_2 , V_210 , V_171 ) ;
V_209:
return V_55 ;
}
static int F_86 ( struct V_156 * V_156 , void * V_185 , T_1 V_211 )
{
struct V_1 * V_2 = F_70 ( V_156 ) ;
F_51 ( 1 , L_55 , V_125 ,
V_2 -> V_158 , V_2 -> V_19 ) ;
if ( V_211 == V_2 -> V_176 )
return 0 ;
if ( V_2 -> V_141 > 0 )
return - V_136 ;
V_2 -> V_176 = V_211 ;
F_76 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_59 ( & V_2 -> V_145 , 0 , V_146 , V_175 , V_211 ) ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int F_87 ( struct V_156 * V_156 , void * V_185 , T_1 * V_211 )
{
struct V_1 * V_2 = F_70 ( V_156 ) ;
F_51 ( 1 , L_55 , V_125 ,
V_2 -> V_158 , V_2 -> V_19 ) ;
* V_211 = V_2 -> V_176 ;
return 0 ;
}
static int F_88 ( struct V_156 * V_156 , void * V_185 ,
struct V_212 * V_213 )
{
struct V_1 * V_2 = F_70 ( V_156 ) ;
unsigned int V_214 ;
static const char * V_215 [] = {
[ V_216 ] = L_62 ,
[ V_217 ] = L_63 ,
[ V_218 ] = L_64 ,
[ V_219 ] = L_65 ,
[ V_220 ] = L_66 ,
[ V_221 ] = L_67 ,
[ V_222 ] = L_68
} ;
F_51 ( 1 , L_55 , V_125 ,
V_2 -> V_158 , V_2 -> V_19 ) ;
V_214 = V_213 -> V_206 ;
if ( V_214 >= V_223 )
return - V_123 ;
if ( F_89 ( V_214 ) . type == 0 )
return - V_123 ;
V_213 -> V_206 = V_214 ;
strcpy ( V_213 -> V_194 , V_215 [ F_89 ( V_214 ) . type ] ) ;
if ( ( F_89 ( V_214 ) . type == V_220 ) ||
( F_89 ( V_214 ) . type == V_219 ) ) {
V_213 -> type |= V_224 ;
V_213 -> V_225 = 1 ;
} else {
V_213 -> type |= V_226 ;
V_213 -> V_225 = 2 ;
}
V_213 -> V_176 = V_2 -> V_151 -> V_227 ;
return 0 ;
}
static int F_90 ( struct V_156 * V_156 , void * V_185 , unsigned int * V_30 )
{
struct V_1 * V_2 = F_70 ( V_156 ) ;
F_51 ( 1 , L_55 , V_125 ,
V_2 -> V_158 , V_2 -> V_19 ) ;
* V_30 = V_2 -> V_228 ;
return 0 ;
}
static void F_91 ( struct V_1 * V_2 , int V_206 )
{
int V_30 ;
F_51 ( 1 , L_55 , V_125 ,
V_2 -> V_158 , V_2 -> V_19 ) ;
switch ( F_89 ( V_206 ) . type ) {
case V_218 :
V_2 -> V_229 = V_218 ;
V_2 -> V_230 = 1 ;
break;
case V_217 :
V_2 -> V_229 = V_217 ;
V_2 -> V_230 = 1 ;
break;
case V_220 :
V_2 -> V_229 = V_220 ;
V_2 -> V_230 = 0 ;
break;
default:
F_51 ( 1 , L_69 ,
F_89 ( V_206 ) . type ) ;
break;
}
F_59 ( & V_2 -> V_145 , 0 , V_146 , V_231 ,
F_89 ( V_206 ) . V_232 , 0 , 0 ) ;
for ( V_30 = 0 ; V_30 < V_223 ; V_30 ++ ) {
int V_233 = 0 ;
if ( F_89 ( V_30 ) . V_234 == NULL )
continue;
if ( V_30 == V_206 )
V_233 = 1 ;
else
V_233 = 0 ;
if ( V_233 ) {
( F_89 ( V_30 ) . V_234 ) ( V_2 , V_233 ) ;
} else {
if ( ( F_89 ( V_30 ) . V_234 ) !=
( ( F_89 ( V_206 ) . V_234 ) ) ) {
( F_89 ( V_30 ) . V_234 ) ( V_2 , V_233 ) ;
}
}
}
F_59 ( & V_2 -> V_145 , 0 , V_235 , V_231 ,
F_89 ( V_206 ) . V_236 , 0 , 0 ) ;
}
static int F_92 ( struct V_156 * V_156 , void * V_185 , unsigned int V_206 )
{
struct V_1 * V_2 = F_70 ( V_156 ) ;
F_51 ( 1 , L_70 , V_125 ,
V_206 ) ;
if ( V_206 >= V_223 )
return - V_123 ;
if ( F_89 ( V_206 ) . type == 0 )
return - V_123 ;
V_2 -> V_228 = V_206 ;
F_91 ( V_2 , V_206 ) ;
return 0 ;
}
static int F_93 ( struct V_156 * V_156 , void * V_185 , struct V_237 * V_238 )
{
if ( V_238 -> V_206 > 1 )
return - V_123 ;
F_51 ( 1 , L_59 , V_125 ) ;
if ( V_238 -> V_206 == 0 )
strcpy ( V_238 -> V_194 , L_66 ) ;
else
strcpy ( V_238 -> V_194 , L_71 ) ;
V_238 -> V_239 = V_240 ;
return 0 ;
}
static int F_94 ( struct V_156 * V_156 , void * V_185 , struct V_237 * V_238 )
{
struct V_1 * V_2 = F_70 ( V_156 ) ;
F_51 ( 1 , L_55 , V_125 ,
V_2 -> V_158 , V_2 -> V_19 ) ;
V_238 -> V_206 = V_2 -> V_230 ;
if ( V_238 -> V_206 == 0 )
strcpy ( V_238 -> V_194 , L_66 ) ;
else
strcpy ( V_238 -> V_194 , L_71 ) ;
V_238 -> V_239 = V_240 ;
return 0 ;
}
static int F_95 ( struct V_156 * V_156 , void * V_185 , const struct V_237 * V_238 )
{
struct V_1 * V_2 = F_70 ( V_156 ) ;
if ( V_238 -> V_206 != V_2 -> V_230 )
return - V_123 ;
F_51 ( 1 , L_55 , V_125 ,
V_2 -> V_158 , V_2 -> V_19 ) ;
return 0 ;
}
static int F_96 ( struct V_156 * V_156 , void * V_185 , struct V_241 * V_242 )
{
struct V_1 * V_2 = F_70 ( V_156 ) ;
if ( V_242 -> V_206 != 0 )
return - V_123 ;
F_51 ( 1 , L_55 , V_125 ,
V_2 -> V_158 , V_2 -> V_19 ) ;
strcpy ( V_242 -> V_194 , L_72 ) ;
F_76 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_59 ( & V_2 -> V_145 , 0 , V_177 , V_243 , V_242 ) ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int F_97 ( struct V_156 * V_156 , void * V_185 ,
const struct V_241 * V_242 )
{
struct V_1 * V_2 = F_70 ( V_156 ) ;
if ( V_242 -> V_206 != 0 )
return - V_123 ;
F_51 ( 1 , L_55 , V_125 ,
V_2 -> V_158 , V_2 -> V_19 ) ;
F_76 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_59 ( & V_2 -> V_145 , 0 , V_177 , V_244 , V_242 ) ;
F_1 ( V_2 , 0 ) ;
F_51 ( 1 , L_73 , V_242 -> signal ,
V_242 -> V_245 ) ;
return 0 ;
}
static int F_98 ( struct V_156 * V_156 , void * V_185 ,
struct V_170 * V_246 )
{
struct V_1 * V_2 = F_70 ( V_156 ) ;
if ( V_246 -> V_177 != 0 )
return - V_123 ;
F_51 ( 1 , L_55 , V_125 ,
V_2 -> V_158 , V_2 -> V_19 ) ;
V_246 -> V_172 = V_2 -> V_173 ;
return 0 ;
}
static int F_99 ( struct V_156 * V_156 , void * V_185 ,
const struct V_170 * V_246 )
{
struct V_1 * V_2 = F_70 ( V_156 ) ;
struct V_170 V_247 = * V_246 ;
if ( V_246 -> V_177 != 0 )
return - V_123 ;
F_51 ( 1 , L_55 , V_125 ,
V_2 -> V_158 , V_2 -> V_19 ) ;
F_76 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_59 ( & V_2 -> V_145 , 0 , V_177 , V_178 , V_246 ) ;
F_59 ( & V_2 -> V_145 , 0 , V_177 , V_248 , & V_247 ) ;
V_2 -> V_173 = V_247 . V_172 ;
F_1 ( V_2 , 0 ) ;
F_55 ( V_2 ) ;
return 0 ;
}
static int F_100 ( struct V_156 * V_156 , void * V_185 ,
struct V_112 * V_180 )
{
struct V_1 * V_2 = F_70 ( V_156 ) ;
F_51 ( 1 , L_55 , V_125 ,
V_2 -> V_158 , V_2 -> V_19 ) ;
V_180 -> V_113 . V_249 . V_250 = V_2 -> V_95 ;
V_180 -> V_113 . V_249 . V_251 = V_252 ;
V_180 -> V_113 . V_249 . V_63 = 0 ;
V_180 -> V_113 . V_249 . V_29 = 0 ;
V_180 -> V_113 . V_249 . V_253 = 6750000 * 4 / 2 ;
V_180 -> V_113 . V_249 . V_140 [ 0 ] = V_2 -> V_96 ;
V_180 -> V_113 . V_249 . V_140 [ 1 ] = V_2 -> V_96 ;
V_180 -> V_113 . V_249 . V_254 [ 0 ] = 21 ;
V_180 -> V_113 . V_249 . V_254 [ 1 ] = 284 ;
memset ( V_180 -> V_113 . V_249 . V_255 , 0 , sizeof( V_180 -> V_113 . V_249 . V_255 ) ) ;
return 0 ;
}
static int F_101 ( struct V_156 * V_156 , void * V_185 ,
struct V_256 * V_257 )
{
struct V_1 * V_2 = F_70 ( V_156 ) ;
if ( V_257 -> type != V_142 )
return - V_123 ;
F_51 ( 1 , L_55 , V_125 ,
V_2 -> V_158 , V_2 -> V_19 ) ;
V_257 -> V_258 . V_259 = 0 ;
V_257 -> V_258 . V_260 = 0 ;
V_257 -> V_258 . V_87 = V_2 -> V_87 ;
V_257 -> V_258 . V_119 = V_2 -> V_119 ;
V_257 -> V_261 = V_257 -> V_258 ;
V_257 -> V_262 . V_263 = 54 ;
V_257 -> V_262 . V_264 = 59 ;
return 0 ;
}
static int F_102 ( struct V_156 * V_156 , void * V_185 ,
struct V_265 * V_266 )
{
struct V_1 * V_2 = F_70 ( V_156 ) ;
F_51 ( 1 , L_55 , V_125 ,
V_2 -> V_158 , V_2 -> V_19 ) ;
V_266 -> V_3 = F_103 ( V_2 , V_266 -> V_266 ) ;
V_266 -> V_120 = 1 ;
return 0 ;
}
static int F_104 ( struct V_156 * V_156 , void * V_185 ,
const struct V_265 * V_266 )
{
struct V_1 * V_2 = F_70 ( V_156 ) ;
F_51 ( 1 , L_55 , V_125 ,
V_2 -> V_158 , V_2 -> V_19 ) ;
return F_49 ( V_2 , V_266 -> V_266 , V_266 -> V_3 ) ;
}
static int F_105 ( struct V_156 * V_156 , void * V_267 )
{
struct V_163 * V_151 = F_74 ( V_156 ) ;
F_51 ( 1 , L_59 , V_125 ) ;
F_106 ( V_156 , V_267 ) ;
F_59 ( V_151 -> V_145 , 0 , V_168 , V_268 ) ;
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
if ( V_2 -> V_103 )
F_61 ( & V_2 -> V_104 ) ;
if ( V_2 -> V_107 )
F_61 ( & V_2 -> V_108 ) ;
}
void F_108 ( struct V_1 * V_2 )
{
int V_30 , V_55 ;
F_5 ( L_76 ) ;
if ( V_2 -> V_40 == V_41 ) {
F_57 ( V_2 ) ;
F_76 ( V_2 ) ;
}
if ( V_2 -> V_103 )
F_39 ( & V_2 -> V_104 , V_105 + ( V_106 / 10 ) ) ;
if ( V_2 -> V_107 )
F_39 ( & V_2 -> V_108 , V_105 + ( V_106 / 10 ) ) ;
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
struct V_110 * V_269 ;
V_269 = & V_2 -> V_208 ;
V_269 -> type = V_142 ;
V_269 -> V_270 = V_271 | V_272 | V_273 | V_274 ;
V_269 -> V_275 = V_276 ;
V_269 -> V_277 = V_2 ;
V_269 -> V_278 = sizeof( struct V_65 ) ;
V_269 -> V_6 = & V_279 ;
V_269 -> V_280 = & V_281 ;
V_55 = F_110 ( V_269 ) ;
if ( V_55 < 0 )
return V_55 ;
V_269 = & V_2 -> V_282 ;
V_269 -> type = V_148 ;
V_269 -> V_270 = V_271 | V_272 | V_273 | V_274 ;
V_269 -> V_275 = V_276 ;
V_269 -> V_277 = V_2 ;
V_269 -> V_278 = sizeof( struct V_65 ) ;
V_269 -> V_6 = & V_283 ;
V_269 -> V_280 = & V_281 ;
V_55 = F_110 ( V_269 ) ;
if ( V_55 < 0 )
return V_55 ;
return 0 ;
}
int F_111 ( struct V_1 * V_2 ,
struct V_128 * V_284 )
{
int V_285 = - V_57 ;
struct V_286 * V_287 ;
struct V_288 * V_289 ;
int V_30 , V_130 ;
F_51 ( 1 , L_77 ,
V_284 -> V_133 -> V_134 . V_290 ) ;
V_285 = F_53 ( V_2 -> V_45 ,
V_284 -> V_133 -> V_134 . V_290 , 5 ) ;
if ( V_285 != 0 ) {
F_5 ( L_78 ) ;
return V_285 ;
}
V_287 = V_284 -> V_133 ;
for ( V_30 = 0 ; V_30 < V_287 -> V_134 . V_291 ; V_30 ++ ) {
V_289 = & V_287 -> V_289 [ V_30 ] . V_134 ;
if ( ( ( V_289 -> V_292 & V_293 )
== V_294 ) &&
( ( V_289 -> V_295 & V_296 )
== V_297 ) ) {
T_2 V_214 = F_112 ( V_289 -> V_298 ) ;
V_2 -> V_50 = ( V_214 & 0x07ff ) *
( ( ( V_214 & 0x1800 ) >> 11 ) + 1 ) ;
V_2 -> V_59 = V_289 -> V_292 ;
F_51 ( 1 ,
L_79 ,
V_2 -> V_59 , V_2 -> V_50 ) ;
}
}
if ( ! ( V_2 -> V_59 ) ) {
F_5 ( L_80 ) ;
return - V_21 ;
}
F_113 ( & V_2 -> V_299 ) ;
F_114 ( & V_2 -> V_33 ) ;
F_115 ( & V_2 -> V_28 . V_90 ) ;
F_115 ( & V_2 -> V_97 . V_90 ) ;
F_116 ( & V_2 -> V_104 , F_67 ,
( unsigned long ) V_2 ) ;
F_116 ( & V_2 -> V_108 , F_68 ,
( unsigned long ) V_2 ) ;
V_2 -> V_87 = V_300 ;
V_2 -> V_119 = V_301 ;
V_2 -> V_188 = V_2 -> V_87 * V_2 -> V_119 ;
V_2 -> V_187 = V_2 -> V_188 << 1 ;
V_2 -> V_86 = V_2 -> V_87 << 1 ;
V_2 -> V_95 = 720 ;
V_2 -> V_96 = 1 ;
V_2 -> V_230 = 0 ;
V_2 -> V_173 = 960 ;
V_2 -> V_176 = V_302 ;
F_91 ( V_2 , 0 ) ;
V_2 -> V_151 = F_117 () ;
if ( NULL == V_2 -> V_151 ) {
F_51 ( 1 , L_81 ) ;
return - V_57 ;
}
V_2 -> V_152 = F_117 () ;
if ( NULL == V_2 -> V_152 ) {
F_51 ( 1 , L_82 ) ;
V_130 = - V_57 ;
goto V_303;
}
F_118 ( & V_2 -> V_304 ) ;
F_118 ( & V_2 -> V_305 ) ;
* V_2 -> V_151 = V_306 ;
V_2 -> V_151 -> V_145 = & V_2 -> V_145 ;
V_2 -> V_151 -> V_160 = & V_2 -> V_160 ;
V_2 -> V_151 -> V_307 = & V_2 -> V_208 ;
V_2 -> V_151 -> V_307 -> V_160 = & V_2 -> V_304 ;
strcpy ( V_2 -> V_151 -> V_194 , L_83 ) ;
* V_2 -> V_152 = V_306 ;
V_2 -> V_152 -> V_145 = & V_2 -> V_145 ;
V_2 -> V_152 -> V_160 = & V_2 -> V_160 ;
V_2 -> V_152 -> V_307 = & V_2 -> V_282 ;
V_2 -> V_152 -> V_307 -> V_160 = & V_2 -> V_305 ;
strcpy ( V_2 -> V_152 -> V_194 , L_84 ) ;
V_285 = F_109 ( V_2 ) ;
if ( V_285 != 0 ) {
F_51 ( 1 , L_85 ,
V_285 ) ;
V_130 = - V_21 ;
goto V_308;
}
F_119 ( V_2 -> V_151 , V_2 ) ;
V_285 = F_120 ( V_2 -> V_151 , V_165 , - 1 ) ;
if ( V_285 != 0 ) {
F_51 ( 1 , L_86 ,
V_285 ) ;
V_130 = - V_21 ;
goto V_309;
}
F_119 ( V_2 -> V_152 , V_2 ) ;
V_285 = F_120 ( V_2 -> V_152 , V_166 , - 1 ) ;
if ( V_285 != 0 ) {
F_51 ( 1 , L_87 ,
V_285 ) ;
V_130 = - V_21 ;
goto V_310;
}
F_51 ( 1 , L_88 , V_125 ) ;
return 0 ;
V_310:
F_65 ( V_2 -> V_151 ) ;
V_309:
F_121 ( & V_2 -> V_208 ) ;
F_121 ( & V_2 -> V_282 ) ;
V_308:
F_122 ( V_2 -> V_152 ) ;
V_303:
F_122 ( V_2 -> V_151 ) ;
return V_130 ;
}

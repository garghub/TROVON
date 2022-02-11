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
F_11 ( V_2 ) ;
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
F_26 ( & V_26 -> V_65 ) ;
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
static inline void F_27 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_66 * V_58 )
{
F_3 ( L_28 , V_58 , V_58 -> V_67 . V_30 ) ;
V_58 -> V_67 . V_68 = V_69 ;
V_58 -> V_67 . V_70 ++ ;
F_28 ( & V_58 -> V_67 . V_71 ) ;
V_2 -> V_34 . V_58 = NULL ;
F_29 ( & V_58 -> V_67 . V_72 ) ;
F_30 ( & V_58 -> V_67 . V_73 ) ;
}
static inline void F_31 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_66 * V_58 )
{
F_3 ( L_28 , V_58 , V_58 -> V_67 . V_30 ) ;
V_58 -> V_67 . V_68 = V_69 ;
V_58 -> V_67 . V_70 ++ ;
F_28 ( & V_58 -> V_67 . V_71 ) ;
V_2 -> V_34 . V_74 = NULL ;
F_29 ( & V_58 -> V_67 . V_72 ) ;
F_30 ( & V_58 -> V_67 . V_73 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_66 * V_58 ,
unsigned char * V_75 ,
unsigned char * V_76 , unsigned long V_77 )
{
void * V_78 , * V_79 , * V_80 ;
int V_81 , V_82 , V_63 , V_83 , V_84 ;
int V_85 = V_2 -> V_86 << 1 ;
if ( V_77 == 0 )
return;
if ( V_26 -> V_87 + V_77 > V_58 -> V_67 . V_88 )
V_77 = V_58 -> V_67 . V_88 - V_26 -> V_87 ;
V_80 = V_75 ;
V_84 = V_77 ;
if ( V_58 -> V_89 )
V_78 = V_76 ;
else
V_78 = V_76 + V_85 ;
V_81 = V_26 -> V_87 / V_85 ;
V_82 = V_26 -> V_87 % V_85 ;
V_63 = V_81 * V_85 * 2 + V_82 ;
V_79 = V_78 + V_63 ;
V_83 = V_85 - V_82 ;
V_83 = V_83 > V_84 ? V_84 : V_83 ;
if ( ( char * ) V_79 + V_83 > ( char * ) V_76 + V_58 -> V_67 . V_88 ) {
F_3 ( L_29 ,
( ( char * ) V_79 + V_83 ) -
( ( char * ) V_76 + V_58 -> V_67 . V_88 ) ) ;
V_84 = ( char * ) V_76 + V_58 -> V_67 . V_88 - ( char * ) V_79 ;
V_83 = V_84 ;
}
if ( V_83 <= 0 )
return;
memcpy ( V_79 , V_80 , V_83 ) ;
V_84 -= V_83 ;
while ( V_84 > 0 ) {
V_79 += V_83 + V_85 ;
V_80 += V_83 ;
if ( V_85 > V_84 )
V_83 = V_84 ;
else
V_83 = V_85 ;
if ( ( char * ) V_79 + V_83 > ( char * ) V_76 +
V_58 -> V_67 . V_88 ) {
F_3 ( L_30 ,
( ( char * ) V_79 + V_83 ) -
( ( char * ) V_76 + V_58 -> V_67 . V_88 ) ) ;
V_83 = V_84 = ( char * ) V_76 + V_58 -> V_67 . V_88 -
( char * ) V_79 ;
}
if ( V_83 <= 0 )
break;
memcpy ( V_79 , V_80 , V_83 ) ;
V_84 -= V_83 ;
}
if ( V_63 > 1440 ) {
if ( V_76 [ 0 ] < 0x60 && V_76 [ 1440 ] < 0x60 )
V_2 -> V_90 = 1 ;
}
V_26 -> V_87 += V_77 ;
}
static inline void F_33 ( struct V_25 * V_26 ,
struct V_66 * * V_58 )
{
struct V_1 * V_2 = F_7 ( V_26 , struct V_1 , V_28 ) ;
if ( F_34 ( & V_26 -> V_91 ) ) {
F_3 ( L_31 ) ;
V_2 -> V_34 . V_58 = NULL ;
* V_58 = NULL ;
return;
}
* V_58 = F_35 ( V_26 -> V_91 . V_92 , struct V_66 , V_67 . V_72 ) ;
V_2 -> V_34 . V_58 = * V_58 ;
return;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_66 * V_58 ,
unsigned char * V_75 ,
unsigned char * V_76 , unsigned long V_77 )
{
unsigned char * V_79 , * V_80 ;
int V_85 ;
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
if ( V_75 == NULL ) {
F_3 ( L_34 ) ;
return;
}
if ( V_76 == NULL ) {
F_3 ( L_35 ) ;
return;
}
V_85 = V_2 -> V_93 ;
if ( V_26 -> V_87 + V_77 > V_58 -> V_67 . V_88 )
V_77 = V_58 -> V_67 . V_88 - V_26 -> V_87 ;
V_80 = V_75 ;
V_79 = V_76 + ( V_26 -> V_87 / 2 ) ;
if ( V_58 -> V_89 == 0 )
V_79 += V_85 * V_2 -> V_94 ;
for ( V_30 = 0 ; V_30 < V_77 ; V_30 += 2 )
V_79 [ V_53 ++ ] = V_80 [ V_30 + 1 ] ;
V_26 -> V_87 += V_77 ;
}
static inline void F_37 ( struct V_25 * V_26 ,
struct V_66 * * V_58 )
{
struct V_1 * V_2 = F_7 ( V_26 , struct V_1 , V_95 ) ;
char * V_76 ;
if ( F_34 ( & V_26 -> V_91 ) ) {
F_3 ( L_31 ) ;
V_2 -> V_34 . V_74 = NULL ;
* V_58 = NULL ;
return;
}
* V_58 = F_35 ( V_26 -> V_91 . V_92 , struct V_66 , V_67 . V_72 ) ;
V_76 = F_38 ( & ( * V_58 ) -> V_67 ) ;
memset ( V_76 , 0x00 , ( * V_58 ) -> V_67 . V_88 ) ;
V_2 -> V_34 . V_74 = * V_58 ;
return;
}
static inline int F_39 ( struct V_1 * V_2 , struct V_24 * V_24 )
{
struct V_66 * V_58 ;
struct V_66 * V_74 ;
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_25 * V_96 = & V_2 -> V_95 ;
unsigned char * V_76 = NULL ;
unsigned char * V_97 = NULL ;
int V_30 , V_77 = 0 , V_55 = 1 ;
unsigned char * V_75 ;
unsigned char V_98 ;
unsigned int V_99 ;
unsigned int V_84 , V_83 ;
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
V_76 = F_38 ( & V_58 -> V_67 ) ;
V_74 = V_2 -> V_34 . V_74 ;
if ( V_74 != NULL )
V_97 = F_38 ( & V_74 -> V_67 ) ;
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
V_75 = V_24 -> V_44 + V_24 -> V_37 [ V_30 ] . V_63 ;
V_98 = V_75 [ 0 ] ;
V_77 = V_24 -> V_37 [ V_30 ] . V_38 - 4 ;
V_75 += 4 ;
if ( V_98 & 0x80 ) {
V_77 -= 4 ;
V_75 += 4 ;
F_3 ( L_37 ,
( V_98 & 0x40 ) ? L_38 : L_39 ) ;
if ( V_98 & 0x40 ) {
if ( V_74 != NULL )
F_31 ( V_2 ,
V_96 ,
V_74 ) ;
F_37 ( V_96 , & V_74 ) ;
if ( V_74 == NULL )
V_97 = NULL ;
else
V_97 = F_38 (
& V_74 -> V_67 ) ;
if ( V_58 != NULL )
F_27 ( V_2 , V_26 , V_58 ) ;
F_33 ( V_26 , & V_58 ) ;
if ( V_58 == NULL )
V_76 = NULL ;
else
V_76 = F_38 ( & V_58 -> V_67 ) ;
if ( V_2 -> V_100 )
F_40 ( & V_2 -> V_101 ,
V_102 + ( V_103 / 10 ) ) ;
if ( V_2 -> V_104 )
F_40 ( & V_2 -> V_105 ,
V_102 + ( V_103 / 10 ) ) ;
}
if ( V_58 != NULL ) {
if ( V_98 & 0x40 )
V_58 -> V_89 = 1 ;
else
V_58 -> V_89 = 0 ;
}
if ( V_74 != NULL ) {
if ( V_98 & 0x40 )
V_74 -> V_89 = 1 ;
else
V_74 -> V_89 = 0 ;
}
V_2 -> V_106 = 0 ;
V_96 -> V_87 = 0 ;
V_26 -> V_87 = 0 ;
}
V_99 = V_2 -> V_93 * V_2 -> V_94 * 2 ;
if ( V_2 -> V_106 < V_99 ) {
V_84 = V_99 - V_2 -> V_106 ;
if ( V_77 < V_84 )
V_83 = V_77 ;
else
V_83 = V_84 ;
if ( V_74 != NULL )
F_36 ( V_2 , V_96 , V_74 , V_75 ,
V_97 , V_77 ) ;
V_77 -= V_83 ;
V_75 += V_83 ;
V_2 -> V_106 += V_83 ;
}
if ( V_2 -> V_106 >= V_99 && V_58 != NULL )
F_32 ( V_2 , V_26 , V_58 , V_75 , V_76 , V_77 ) ;
}
return V_55 ;
}
static int
F_41 ( struct V_107 * V_108 , unsigned int * V_109 ,
unsigned int * V_88 )
{
struct V_110 * V_111 = V_108 -> V_112 ;
* V_88 = ( V_111 -> V_2 -> V_86 * V_111 -> V_2 -> V_113 * 16 + 7 ) >> 3 ;
if ( 0 == * V_109 )
* V_109 = V_114 ;
if ( * V_109 < V_115 )
* V_109 = V_115 ;
return 0 ;
}
static void F_42 ( struct V_107 * V_108 , struct V_66 * V_58 )
{
struct V_110 * V_111 = V_108 -> V_112 ;
struct V_1 * V_2 = V_111 -> V_2 ;
unsigned long V_29 = 0 ;
if ( F_23 () )
F_43 () ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_34 . V_58 == V_58 )
V_2 -> V_34 . V_58 = NULL ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
F_44 ( & V_58 -> V_67 ) ;
V_58 -> V_67 . V_68 = V_116 ;
}
static int
F_45 ( struct V_107 * V_108 , struct V_117 * V_67 ,
enum V_118 V_119 )
{
struct V_110 * V_111 = V_108 -> V_112 ;
struct V_66 * V_58 = F_7 ( V_67 , struct V_66 , V_67 ) ;
struct V_1 * V_2 = V_111 -> V_2 ;
int V_55 = 0 , V_120 = 0 ;
V_58 -> V_67 . V_88 = ( V_111 -> V_2 -> V_86 * V_111 -> V_2 -> V_113 * 16 + 7 ) >> 3 ;
if ( 0 != V_58 -> V_67 . V_121 && V_58 -> V_67 . V_122 < V_58 -> V_67 . V_88 )
return - V_123 ;
V_58 -> V_67 . V_86 = V_2 -> V_86 ;
V_58 -> V_67 . V_113 = V_2 -> V_113 ;
V_58 -> V_67 . V_119 = V_119 ;
if ( V_116 == V_58 -> V_67 . V_68 ) {
V_55 = F_46 ( V_108 , & V_58 -> V_67 , NULL ) ;
if ( V_55 < 0 ) {
F_5 ( L_40 ) ;
goto V_124;
}
}
if ( ! V_2 -> V_34 . V_43 )
V_120 = 1 ;
if ( V_120 ) {
V_55 = F_18 ( V_2 , V_125 ,
V_126 , V_2 -> V_50 ,
F_39 ) ;
if ( V_55 < 0 ) {
F_5 ( L_41 ) ;
goto V_124;
}
}
V_58 -> V_67 . V_68 = V_127 ;
return 0 ;
V_124:
F_42 ( V_108 , V_58 ) ;
return V_55 ;
}
static void
F_47 ( struct V_107 * V_108 , struct V_117 * V_67 )
{
struct V_66 * V_58 = F_7 ( V_67 ,
struct V_66 ,
V_67 ) ;
struct V_110 * V_111 = V_108 -> V_112 ;
struct V_1 * V_2 = V_111 -> V_2 ;
struct V_25 * V_28 = & V_2 -> V_28 ;
V_58 -> V_67 . V_68 = V_128 ;
F_48 ( & V_58 -> V_67 . V_72 , & V_28 -> V_91 ) ;
}
static void F_49 ( struct V_107 * V_108 ,
struct V_117 * V_67 )
{
struct V_66 * V_58 = F_7 ( V_67 ,
struct V_66 ,
V_67 ) ;
F_42 ( V_108 , V_58 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
F_51 ( V_2 , V_129 , 0x01 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_130 )
{
struct V_131 * V_132 ;
int V_133 , V_134 , V_135 ;
F_53 ( 1 , L_42 ) ;
V_132 = F_54 ( V_130 -> V_45 , 0 ) ;
if ( V_132 && V_132 -> V_136 -> V_137 . V_138 != 5 ) {
F_53 ( 1 , L_43 ) ;
V_133 = F_55 ( V_130 -> V_45 , 0 , 5 ) ;
if ( V_133 < 0 ) {
F_5 ( L_44 ) ;
return - V_139 ;
}
}
V_134 = V_130 -> V_113 / 2 + 2 ;
V_135 = V_130 -> V_86 * 2 ;
F_51 ( V_130 , V_140 , 0x00 ) ;
F_51 ( V_130 , 0x106 , 0x00 ) ;
F_51 ( V_130 , 0x110 , 0x00 ) ;
F_51 ( V_130 , 0x111 , 0x00 ) ;
F_51 ( V_130 , 0x114 , V_135 & 0xff ) ;
F_51 ( V_130 , 0x115 , V_135 >> 8 ) ;
F_51 ( V_130 , 0x112 , 0x00 ) ;
F_51 ( V_130 , 0x113 , 0x00 ) ;
F_51 ( V_130 , 0x116 , V_134 & 0xff ) ;
F_51 ( V_130 , 0x117 , V_134 >> 8 ) ;
F_51 ( V_130 , V_141 , 0xb3 ) ;
return 0 ;
}
int F_56 ( struct V_1 * V_130 )
{
F_53 ( 1 , L_45 ) ;
F_51 ( V_130 , V_141 , 0x0 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_53 ( 1 , L_46 ) ;
F_51 ( V_2 , V_141 , 0x0 ) ;
F_58 ( 30 ) ;
F_51 ( V_2 , V_141 , 0xb3 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
int V_133 = 0 ;
V_2 -> V_40 = V_142 ;
if ( V_2 -> V_19 == V_20 )
return - V_21 ;
else if ( V_133 ) {
V_2 -> V_19 = V_22 ;
F_53 ( 1 , L_47 , V_143 ) ;
return V_133 ;
}
return 0 ;
}
void F_60 ( struct V_1 * V_2 )
{
F_53 ( 1 , L_48 ) ;
F_61 ( & V_144 ) ;
if ( V_2 -> V_145 )
F_62 ( V_2 -> V_145 ) ;
if ( V_2 -> V_146 )
F_62 ( V_2 -> V_146 ) ;
F_63 ( & V_144 ) ;
}
static int F_64 ( struct V_110 * V_111 , unsigned int V_147 )
{
struct V_1 * V_2 = V_111 -> V_2 ;
if ( V_111 -> V_148 & V_147 )
return 1 ;
if ( V_2 -> V_148 & V_147 ) {
return 0 ;
}
V_111 -> V_148 |= V_147 ;
V_2 -> V_148 |= V_147 ;
F_53 ( 1 , L_49 , V_147 ) ;
return 1 ;
}
static int F_65 ( struct V_110 * V_111 , unsigned int V_147 )
{
return V_111 -> V_148 & V_147 ;
}
static int F_66 ( struct V_1 * V_2 , unsigned int V_147 )
{
return V_2 -> V_148 & V_147 ;
}
static void F_67 ( struct V_110 * V_111 , unsigned int V_149 )
{
struct V_1 * V_2 = V_111 -> V_2 ;
F_68 ( ( V_111 -> V_148 & V_149 ) != V_149 ) ;
V_111 -> V_148 &= ~ V_149 ;
V_2 -> V_148 &= ~ V_149 ;
F_53 ( 1 , L_50 , V_149 ) ;
}
static int F_69 ( struct V_110 * V_111 )
{
switch ( V_111 -> type ) {
case V_150 :
return V_151 ;
case V_152 :
return V_153 ;
default:
F_43 () ;
return 0 ;
}
}
static void F_70 ( unsigned long V_154 )
{
struct V_1 * V_2 = (struct V_1 * ) V_154 ;
struct V_25 * V_26 = & V_2 -> V_28 ;
struct V_66 * V_58 ;
unsigned char * V_155 ;
unsigned long V_29 = 0 ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
V_58 = V_2 -> V_34 . V_58 ;
if ( V_58 != NULL ) {
V_155 = F_38 ( & V_58 -> V_67 ) ;
memset ( V_155 , 0x00 , V_58 -> V_67 . V_88 ) ;
F_27 ( V_2 , V_26 , V_58 ) ;
}
F_33 ( V_26 , & V_58 ) ;
if ( V_2 -> V_100 == 1 )
F_40 ( & V_2 -> V_101 , V_102 + ( V_103 / 10 ) ) ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
}
static void F_71 ( unsigned long V_154 )
{
struct V_1 * V_2 = (struct V_1 * ) V_154 ;
struct V_25 * V_26 = & V_2 -> V_95 ;
struct V_66 * V_58 ;
unsigned char * V_156 ;
unsigned long V_29 = 0 ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
V_58 = V_2 -> V_34 . V_74 ;
if ( V_58 != NULL ) {
V_156 = F_38 ( & V_58 -> V_67 ) ;
memset ( V_156 , 0x00 , V_58 -> V_67 . V_88 ) ;
F_31 ( V_2 , V_26 , V_58 ) ;
}
F_37 ( V_26 , & V_58 ) ;
if ( V_2 -> V_104 == 1 )
F_40 ( & V_2 -> V_105 , V_102 + ( V_103 / 10 ) ) ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
}
static int F_72 ( struct V_157 * V_158 )
{
int V_133 = 0 ;
struct V_159 * V_145 = F_73 ( V_158 ) ;
struct V_1 * V_2 = F_74 ( V_158 ) ;
struct V_110 * V_111 ;
int type ;
switch ( V_145 -> V_160 ) {
case V_161 :
type = V_150 ;
break;
case V_162 :
type = V_152 ;
break;
default:
return - V_123 ;
}
V_111 = F_19 ( sizeof( struct V_110 ) , V_56 ) ;
if ( NULL == V_111 ) {
F_53 ( 1 , L_51 ) ;
return - V_57 ;
}
V_111 -> type = type ;
V_111 -> V_2 = V_2 ;
F_75 ( & V_111 -> V_111 , V_145 ) ;
V_158 -> V_163 = V_111 ;
if ( F_76 ( & V_2 -> V_164 ) ) {
F_17 ( V_111 ) ;
return - V_165 ;
}
if ( V_2 -> V_166 == 0 ) {
F_52 ( V_2 ) ;
F_57 ( V_2 ) ;
F_50 ( V_2 ) ;
V_2 -> V_40 = V_48 ;
V_2 -> V_19 |= V_167 ;
}
V_2 -> V_166 ++ ;
F_63 ( & V_2 -> V_164 ) ;
F_77 ( & V_111 -> V_168 , & V_169 ,
NULL , & V_2 -> V_33 ,
V_150 ,
V_170 ,
sizeof( struct V_66 ) , V_111 ,
& V_2 -> V_164 ) ;
F_77 ( & V_111 -> V_171 , & V_172 ,
NULL , & V_2 -> V_33 ,
V_152 ,
V_173 ,
sizeof( struct V_66 ) , V_111 ,
& V_2 -> V_164 ) ;
F_78 ( & V_111 -> V_111 ) ;
return V_133 ;
}
static int F_79 ( struct V_157 * V_158 )
{
int V_133 ;
struct V_110 * V_111 = V_158 -> V_163 ;
struct V_1 * V_2 = V_111 -> V_2 ;
F_80 ( & V_111 -> V_111 ) ;
F_81 ( & V_111 -> V_111 ) ;
F_61 ( & V_2 -> V_164 ) ;
if ( F_65 ( V_111 , V_151 ) ) {
V_2 -> V_100 = 0 ;
F_82 ( & V_2 -> V_101 ) ;
F_83 ( & V_111 -> V_168 ) ;
F_67 ( V_111 , V_151 ) ;
}
if ( F_65 ( V_111 , V_153 ) ) {
V_2 -> V_104 = 0 ;
F_82 ( & V_2 -> V_105 ) ;
F_83 ( & V_111 -> V_171 ) ;
F_67 ( V_111 , V_153 ) ;
}
if ( V_2 -> V_166 == 1 && F_84 ( F_73 ( V_158 ) ) ) {
F_56 ( V_2 ) ;
F_11 ( V_2 ) ;
F_85 ( & V_2 -> V_174 , 0 , V_175 , V_176 , 0 ) ;
V_2 -> V_177 = 0 ;
V_133 = F_55 ( V_2 -> V_45 , 0 , 0 ) ;
if ( V_133 < 0 )
F_5 ( L_52 ) ;
}
F_63 ( & V_2 -> V_164 ) ;
F_86 ( & V_111 -> V_168 ) ;
F_86 ( & V_111 -> V_171 ) ;
F_17 ( V_111 ) ;
V_2 -> V_166 -- ;
F_87 ( & V_2 -> V_178 , 1 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_179 V_180 = {
. V_181 = V_2 -> V_182 ,
. type = V_183 ,
} ;
if ( V_2 -> V_177 )
return;
V_2 -> V_177 = 1 ;
F_1 ( V_2 , 1 ) ;
F_85 ( & V_2 -> V_174 , 0 , V_184 , V_185 , V_2 -> V_186 ) ;
F_85 ( & V_2 -> V_174 , 0 , V_187 , V_188 , & V_180 ) ;
F_1 ( V_2 , 0 ) ;
}
static T_1 F_89 ( struct V_157 * V_158 , char T_2 * V_58 ,
T_3 V_109 , T_4 * V_87 )
{
struct V_110 * V_111 = V_158 -> V_163 ;
struct V_1 * V_2 = V_111 -> V_2 ;
int V_55 ;
V_55 = F_4 ( V_2 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( F_76 ( & V_2 -> V_164 ) )
return - V_165 ;
F_88 ( V_2 ) ;
F_63 ( & V_2 -> V_164 ) ;
if ( V_111 -> type == V_150 ) {
if ( F_66 ( V_2 , V_151 ) )
return - V_139 ;
return F_90 ( & V_111 -> V_168 , V_58 , V_109 , V_87 , 0 ,
V_158 -> V_189 & V_190 ) ;
}
if ( V_111 -> type == V_152 ) {
if ( ! F_64 ( V_111 , V_153 ) )
return - V_139 ;
if ( V_2 -> V_104 == 0 ) {
V_2 -> V_104 = 1 ;
F_40 ( & V_2 -> V_105 , V_102 + ( V_103 / 10 ) ) ;
}
return F_90 ( & V_111 -> V_171 , V_58 , V_109 , V_87 , 0 ,
V_158 -> V_189 & V_190 ) ;
}
return 0 ;
}
static unsigned int F_91 ( struct V_157 * V_158 , T_5 * V_191 )
{
struct V_110 * V_111 = V_158 -> V_163 ;
struct V_1 * V_2 = V_111 -> V_2 ;
unsigned long V_192 = F_92 ( V_191 ) ;
unsigned int V_193 ;
if ( F_4 ( V_2 ) < 0 )
return V_194 ;
V_193 = F_93 ( V_158 , V_191 ) ;
if ( ! ( V_192 & ( V_195 | V_196 ) ) )
return V_193 ;
if ( F_76 ( & V_2 -> V_164 ) )
return - V_165 ;
F_88 ( V_2 ) ;
F_63 ( & V_2 -> V_164 ) ;
if ( V_111 -> type == V_150 ) {
if ( ! F_64 ( V_111 , V_151 ) )
return V_194 ;
return V_193 | F_94 ( V_158 , & V_111 -> V_168 , V_191 ) ;
}
if ( V_111 -> type == V_152 ) {
if ( ! F_64 ( V_111 , V_153 ) )
return V_194 ;
return V_193 | F_94 ( V_158 , & V_111 -> V_171 , V_191 ) ;
}
return V_194 ;
}
static int F_95 ( struct V_157 * V_158 , struct V_197 * V_198 )
{
struct V_110 * V_111 = V_158 -> V_163 ;
struct V_1 * V_2 = V_111 -> V_2 ;
int V_55 ;
V_55 = F_4 ( V_2 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_111 -> type == V_150 )
V_55 = F_96 ( & V_111 -> V_168 , V_198 ) ;
else if ( V_111 -> type == V_152 )
V_55 = F_96 ( & V_111 -> V_171 , V_198 ) ;
return V_55 ;
}
static int F_97 ( struct V_1 * V_2 , unsigned int V_199 ,
struct V_200 * V_201 )
{
int V_133 ;
int V_86 = V_201 -> V_202 . V_203 . V_86 ;
int V_113 = V_201 -> V_202 . V_203 . V_113 ;
if ( V_201 -> V_202 . V_203 . V_204 != V_205 )
return - V_123 ;
if ( V_86 != 720 )
V_86 = 720 ;
if ( V_113 != 480 )
V_113 = 480 ;
V_201 -> V_202 . V_203 . V_86 = V_86 ;
V_201 -> V_202 . V_203 . V_113 = V_113 ;
V_201 -> V_202 . V_203 . V_204 = V_205 ;
V_201 -> V_202 . V_203 . V_85 = V_86 * 2 ;
V_201 -> V_202 . V_203 . V_206 = V_86 * V_113 * 2 ;
V_201 -> V_202 . V_203 . V_207 = V_208 ;
V_201 -> V_202 . V_203 . V_119 = V_170 ;
V_201 -> V_202 . V_203 . V_209 = 0 ;
if ( V_199 == V_210 )
return 0 ;
V_2 -> V_86 = V_86 ;
V_2 -> V_113 = V_113 ;
V_2 -> V_211 = V_86 * V_113 * 2 ;
V_2 -> V_212 = V_86 * V_113 ;
V_2 -> V_85 = V_86 * 2 ;
if ( V_2 -> V_40 == V_41 ) {
F_53 ( 1 , L_53 ) ;
V_133 = F_59 ( V_2 ) ;
if ( V_133 != 0 ) {
F_53 ( 1 , L_54 ) ;
return V_133 ;
}
}
F_52 ( V_2 ) ;
return 0 ;
}
static int F_98 ( struct V_157 * V_157 , void * V_209 ,
struct V_213 * V_214 )
{
struct V_159 * V_145 = F_73 ( V_157 ) ;
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
F_99 ( V_214 -> V_215 , L_55 , sizeof( V_214 -> V_215 ) ) ;
F_99 ( V_214 -> V_216 , V_2 -> V_217 . V_218 , sizeof( V_214 -> V_216 ) ) ;
F_100 ( V_2 -> V_45 , V_214 -> V_219 , sizeof( V_214 -> V_219 ) ) ;
V_214 -> V_220 = V_221 |
V_222 |
V_223 |
V_224 ;
if ( V_145 -> V_160 == V_161 )
V_214 -> V_220 |= V_225 ;
else
V_214 -> V_220 |= V_226 ;
V_214 -> V_227 = V_214 -> V_220 | V_228 |
V_226 | V_225 ;
return 0 ;
}
static int F_101 ( struct V_157 * V_157 , void * V_209 ,
struct V_229 * V_180 )
{
if ( V_180 -> V_230 )
return - V_123 ;
V_180 -> type = V_150 ;
strcpy ( V_180 -> V_231 , L_56 ) ;
V_180 -> V_29 = 0 ;
V_180 -> V_204 = V_205 ;
return 0 ;
}
static int F_102 ( struct V_157 * V_157 , void * V_209 ,
struct V_200 * V_180 )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
V_180 -> V_202 . V_203 . V_86 = V_2 -> V_86 ;
V_180 -> V_202 . V_203 . V_113 = V_2 -> V_113 ;
V_180 -> V_202 . V_203 . V_204 = V_205 ;
V_180 -> V_202 . V_203 . V_85 = V_2 -> V_85 ;
V_180 -> V_202 . V_203 . V_206 = V_2 -> V_211 ;
V_180 -> V_202 . V_203 . V_207 = V_208 ;
V_180 -> V_202 . V_203 . V_119 = V_170 ;
V_180 -> V_202 . V_203 . V_209 = 0 ;
return 0 ;
}
static int F_103 ( struct V_157 * V_157 , void * V_209 ,
struct V_200 * V_180 )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
return F_97 ( V_2 , V_210 , V_180 ) ;
}
static int F_104 ( struct V_157 * V_157 , void * V_209 ,
struct V_200 * V_180 )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
int V_55 ;
V_55 = F_4 ( V_2 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( F_105 ( & V_111 -> V_168 ) ) {
F_5 ( L_57 , V_143 ) ;
V_55 = - V_139 ;
goto V_232;
}
V_55 = F_97 ( V_2 , V_233 , V_180 ) ;
V_232:
return V_55 ;
}
static int F_106 ( struct V_157 * V_157 , void * V_209 , T_6 V_234 )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
V_2 -> V_186 = V_234 ;
F_88 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_85 ( & V_2 -> V_174 , 0 , V_184 , V_185 , V_234 ) ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int F_107 ( struct V_157 * V_157 , void * V_209 , T_6 * V_234 )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
* V_234 = V_2 -> V_186 ;
return 0 ;
}
static int F_108 ( struct V_157 * V_157 , void * V_209 ,
struct V_235 * V_236 )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
unsigned int V_237 ;
static const char * V_238 [] = {
[ V_239 ] = L_58 ,
[ V_240 ] = L_59 ,
[ V_241 ] = L_60 ,
[ V_242 ] = L_61 ,
[ V_243 ] = L_62 ,
[ V_244 ] = L_63 ,
[ V_245 ] = L_64
} ;
V_237 = V_236 -> V_230 ;
if ( V_237 >= V_246 )
return - V_123 ;
if ( F_109 ( V_237 ) . type == 0 )
return - V_123 ;
V_236 -> V_230 = V_237 ;
strcpy ( V_236 -> V_218 , V_238 [ F_109 ( V_237 ) . type ] ) ;
if ( ( F_109 ( V_237 ) . type == V_243 ) ||
( F_109 ( V_237 ) . type == V_242 ) ) {
V_236 -> type |= V_247 ;
V_236 -> V_248 = 1 ;
} else {
V_236 -> type |= V_249 ;
V_236 -> V_248 = 2 ;
}
V_236 -> V_186 = V_2 -> V_145 -> V_250 ;
return 0 ;
}
static int F_110 ( struct V_157 * V_157 , void * V_209 , unsigned int * V_30 )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
* V_30 = V_2 -> V_251 ;
return 0 ;
}
static void F_111 ( struct V_1 * V_2 , int V_230 )
{
int V_30 ;
switch ( F_109 ( V_230 ) . type ) {
case V_241 :
V_2 -> V_252 = V_241 ;
V_2 -> V_253 = 1 ;
break;
case V_240 :
V_2 -> V_252 = V_240 ;
V_2 -> V_253 = 1 ;
break;
case V_243 :
V_2 -> V_252 = V_243 ;
V_2 -> V_253 = 0 ;
break;
default:
F_53 ( 1 , L_65 ,
F_109 ( V_230 ) . type ) ;
break;
}
F_85 ( & V_2 -> V_174 , 0 , V_184 , V_254 ,
F_109 ( V_230 ) . V_255 , 0 , 0 ) ;
for ( V_30 = 0 ; V_30 < V_246 ; V_30 ++ ) {
int V_256 = 0 ;
if ( F_109 ( V_30 ) . V_257 == NULL )
continue;
if ( V_30 == V_230 )
V_256 = 1 ;
else
V_256 = 0 ;
if ( V_256 ) {
( F_109 ( V_30 ) . V_257 ) ( V_2 , V_256 ) ;
} else {
if ( ( F_109 ( V_30 ) . V_257 ) !=
( ( F_109 ( V_230 ) . V_257 ) ) ) {
( F_109 ( V_30 ) . V_257 ) ( V_2 , V_256 ) ;
}
}
}
F_85 ( & V_2 -> V_174 , 0 , V_258 , V_254 ,
F_109 ( V_230 ) . V_259 , 0 , 0 ) ;
}
static int F_112 ( struct V_157 * V_157 , void * V_209 , unsigned int V_230 )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
F_53 ( 1 , L_66 , V_143 ,
V_230 ) ;
if ( V_230 >= V_246 )
return - V_123 ;
if ( F_109 ( V_230 ) . type == 0 )
return - V_123 ;
V_2 -> V_251 = V_230 ;
F_111 ( V_2 , V_230 ) ;
return 0 ;
}
static int F_113 ( struct V_157 * V_157 , void * V_209 , struct V_260 * V_261 )
{
if ( V_261 -> V_230 > 1 )
return - V_123 ;
if ( V_261 -> V_230 == 0 )
strcpy ( V_261 -> V_218 , L_62 ) ;
else
strcpy ( V_261 -> V_218 , L_67 ) ;
V_261 -> V_262 = V_263 ;
return 0 ;
}
static int F_114 ( struct V_157 * V_157 , void * V_209 , struct V_260 * V_261 )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
V_261 -> V_230 = V_2 -> V_253 ;
if ( V_261 -> V_230 == 0 )
strcpy ( V_261 -> V_218 , L_62 ) ;
else
strcpy ( V_261 -> V_218 , L_67 ) ;
V_261 -> V_262 = V_263 ;
return 0 ;
}
static int F_115 ( struct V_157 * V_157 , void * V_209 , const struct V_260 * V_261 )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
if ( V_261 -> V_230 != V_2 -> V_253 )
return - V_123 ;
return 0 ;
}
static int F_116 ( struct V_157 * V_157 , void * V_209 , struct V_264 * V_265 )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
if ( V_265 -> V_230 != 0 )
return - V_123 ;
strcpy ( V_265 -> V_218 , L_68 ) ;
F_88 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_85 ( & V_2 -> V_174 , 0 , V_187 , V_266 , V_265 ) ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int F_117 ( struct V_157 * V_157 , void * V_209 ,
const struct V_264 * V_265 )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
if ( V_265 -> V_230 != 0 )
return - V_123 ;
F_88 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_85 ( & V_2 -> V_174 , 0 , V_187 , V_267 , V_265 ) ;
F_1 ( V_2 , 0 ) ;
F_53 ( 1 , L_69 , V_265 -> signal ,
V_265 -> V_268 ) ;
return 0 ;
}
static int F_118 ( struct V_157 * V_157 , void * V_209 ,
struct V_179 * V_269 )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
if ( V_269 -> V_187 != 0 )
return - V_123 ;
V_269 -> V_181 = V_2 -> V_182 ;
return 0 ;
}
static int F_119 ( struct V_157 * V_157 , void * V_209 ,
const struct V_179 * V_269 )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
struct V_179 V_270 = * V_269 ;
if ( V_269 -> V_187 != 0 )
return - V_123 ;
F_88 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_85 ( & V_2 -> V_174 , 0 , V_187 , V_188 , V_269 ) ;
F_85 ( & V_2 -> V_174 , 0 , V_187 , V_271 , & V_270 ) ;
V_2 -> V_182 = V_270 . V_181 ;
F_1 ( V_2 , 0 ) ;
F_57 ( V_2 ) ;
return 0 ;
}
static int F_120 ( struct V_157 * V_157 , void * V_209 ,
struct V_200 * V_201 )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
V_201 -> V_202 . V_272 . V_273 = V_2 -> V_93 ;
V_201 -> V_202 . V_272 . V_274 = V_275 ;
V_201 -> V_202 . V_272 . V_63 = 0 ;
V_201 -> V_202 . V_272 . V_29 = 0 ;
V_201 -> V_202 . V_272 . V_276 = 6750000 * 4 / 2 ;
V_201 -> V_202 . V_272 . V_109 [ 0 ] = V_2 -> V_94 ;
V_201 -> V_202 . V_272 . V_109 [ 1 ] = V_2 -> V_94 ;
V_201 -> V_202 . V_272 . V_277 [ 0 ] = 21 ;
V_201 -> V_202 . V_272 . V_277 [ 1 ] = 284 ;
memset ( V_201 -> V_202 . V_272 . V_278 , 0 , sizeof( V_201 -> V_202 . V_272 . V_278 ) ) ;
return 0 ;
}
static int F_121 ( struct V_157 * V_157 , void * V_209 ,
struct V_279 * V_280 )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
if ( V_280 -> type != V_150 )
return - V_123 ;
V_280 -> V_281 . V_282 = 0 ;
V_280 -> V_281 . V_283 = 0 ;
V_280 -> V_281 . V_86 = V_2 -> V_86 ;
V_280 -> V_281 . V_113 = V_2 -> V_113 ;
V_280 -> V_284 = V_280 -> V_281 ;
V_280 -> V_285 . V_286 = 54 ;
V_280 -> V_285 . V_287 = 59 ;
return 0 ;
}
static int F_122 ( struct V_157 * V_157 , void * V_209 ,
enum V_288 type )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
int V_55 = - V_123 ;
V_55 = F_4 ( V_2 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( F_123 ( type != V_111 -> type ) )
return - V_123 ;
F_53 ( 1 , L_70 ,
V_111 , type , V_111 -> V_148 , V_2 -> V_148 ) ;
if ( F_123 ( ! F_64 ( V_111 , F_69 ( V_111 ) ) ) )
return - V_139 ;
F_88 ( V_2 ) ;
if ( type == V_150 ) {
F_52 ( V_2 ) ;
F_85 ( & V_2 -> V_174 , 0 , V_184 , V_289 , 1 ) ;
}
if ( V_111 -> type == V_150 ) {
V_55 = F_124 ( & V_111 -> V_168 ) ;
V_2 -> V_100 = 1 ;
F_40 ( & V_2 -> V_101 , V_102 + ( V_103 / 10 ) ) ;
} else if ( V_111 -> type == V_152 ) {
V_55 = F_124 ( & V_111 -> V_171 ) ;
V_2 -> V_104 = 1 ;
F_40 ( & V_2 -> V_105 , V_102 + ( V_103 / 10 ) ) ;
}
return V_55 ;
}
static int F_125 ( struct V_157 * V_157 , void * V_209 ,
enum V_288 type )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
int V_55 ;
int V_30 ;
V_55 = F_4 ( V_2 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_111 -> type != V_150 &&
V_111 -> type != V_152 )
return - V_123 ;
if ( type != V_111 -> type )
return - V_123 ;
F_53 ( 1 , L_71 ,
V_111 , type , V_111 -> V_148 , V_2 -> V_148 ) ;
if ( V_111 -> type == V_150 ) {
V_2 -> V_100 = 0 ;
F_82 ( & V_2 -> V_101 ) ;
F_56 ( V_2 ) ;
F_85 ( & V_2 -> V_174 , 0 , V_184 , V_289 , 0 ) ;
V_55 = F_59 ( V_2 ) ;
if ( V_55 != 0 )
return V_55 ;
for ( V_30 = 0 ; V_30 < V_246 ; V_30 ++ ) {
if ( F_109 ( V_30 ) . V_257 == NULL )
continue;
( F_109 ( V_30 ) . V_257 ) ( V_2 , 0 ) ;
}
if ( F_65 ( V_111 , V_151 ) ) {
F_126 ( & V_111 -> V_168 ) ;
F_67 ( V_111 , V_151 ) ;
}
} else if ( V_111 -> type == V_152 ) {
V_2 -> V_104 = 0 ;
F_82 ( & V_2 -> V_105 ) ;
if ( F_65 ( V_111 , V_153 ) ) {
F_126 ( & V_111 -> V_171 ) ;
F_67 ( V_111 , V_153 ) ;
}
}
return 0 ;
}
static int F_127 ( struct V_157 * V_157 , void * V_209 ,
struct V_290 * V_291 )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
V_291 -> V_3 = F_128 ( V_2 , V_291 -> V_291 ) ;
V_291 -> V_88 = 1 ;
return 0 ;
}
static int F_129 ( struct V_157 * V_157 , void * V_209 ,
const struct V_290 * V_291 )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
return F_51 ( V_2 , V_291 -> V_291 , V_291 -> V_3 ) ;
}
static int F_130 ( struct V_157 * V_157 , void * V_111 )
{
struct V_159 * V_145 = F_73 ( V_157 ) ;
F_131 ( V_157 , V_111 ) ;
F_85 ( V_145 -> V_174 , 0 , V_175 , V_292 ) ;
return 0 ;
}
static int F_132 ( struct V_157 * V_157 , void * V_209 ,
struct V_293 * V_294 )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
int V_55 ;
V_55 = F_4 ( V_2 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_111 -> type == V_150 )
V_55 = F_133 ( & V_111 -> V_168 , V_294 ) ;
else if ( V_111 -> type == V_152 )
V_55 = F_133 ( & V_111 -> V_171 , V_294 ) ;
return V_55 ;
}
static int F_134 ( struct V_157 * V_157 , void * V_209 ,
struct V_295 * V_296 )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
int V_55 ;
V_55 = F_4 ( V_2 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_111 -> type == V_150 )
V_55 = F_135 ( & V_111 -> V_168 , V_296 ) ;
else if ( V_111 -> type == V_152 )
V_55 = F_135 ( & V_111 -> V_171 , V_296 ) ;
return V_55 ;
}
static int F_136 ( struct V_157 * V_157 , void * V_209 , struct V_295 * V_296 )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
int V_55 ;
V_55 = F_4 ( V_2 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_111 -> type == V_150 )
V_55 = F_137 ( & V_111 -> V_168 , V_296 ) ;
else if ( V_111 -> type == V_152 )
V_55 = F_137 ( & V_111 -> V_171 , V_296 ) ;
return V_55 ;
}
static int F_138 ( struct V_157 * V_157 , void * V_209 , struct V_295 * V_296 )
{
struct V_110 * V_111 = V_209 ;
struct V_1 * V_2 = V_111 -> V_2 ;
int V_55 ;
V_55 = F_4 ( V_2 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_2 -> V_90 == 1 ) {
F_53 ( 1 , L_72 ) ;
F_57 ( V_2 ) ;
V_2 -> V_90 = 0 ;
}
if ( V_111 -> type == V_150 )
V_55 = F_139 ( & V_111 -> V_168 , V_296 , V_157 -> V_189 & V_190 ) ;
else if ( V_111 -> type == V_152 )
V_55 = F_139 ( & V_111 -> V_171 , V_296 , V_157 -> V_189 & V_190 ) ;
return V_55 ;
}
void F_140 ( struct V_1 * V_2 )
{
struct V_24 * V_24 ;
int V_30 ;
F_5 ( L_73 ) ;
if ( V_2 -> V_40 == V_41 ) {
F_5 ( L_74 ) ;
F_56 ( V_2 ) ;
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
if ( V_2 -> V_100 )
F_82 ( & V_2 -> V_101 ) ;
if ( V_2 -> V_104 )
F_82 ( & V_2 -> V_105 ) ;
}
void F_141 ( struct V_1 * V_2 )
{
int V_30 , V_55 ;
F_5 ( L_75 ) ;
if ( V_2 -> V_40 == V_41 ) {
F_59 ( V_2 ) ;
F_88 ( V_2 ) ;
}
if ( V_2 -> V_100 )
F_40 ( & V_2 -> V_101 , V_102 + ( V_103 / 10 ) ) ;
if ( V_2 -> V_104 )
F_40 ( & V_2 -> V_105 , V_102 + ( V_103 / 10 ) ) ;
F_50 ( V_2 ) ;
F_52 ( V_2 ) ;
if ( ! ( V_2 -> V_40 == V_41 ) ) {
F_57 ( V_2 ) ;
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
int F_142 ( struct V_1 * V_2 ,
struct V_131 * V_297 )
{
int V_298 = - V_57 ;
struct V_299 * V_300 ;
struct V_301 * V_302 ;
int V_30 , V_133 ;
F_53 ( 1 , L_76 ,
V_297 -> V_136 -> V_137 . V_303 ) ;
V_298 = F_55 ( V_2 -> V_45 ,
V_297 -> V_136 -> V_137 . V_303 , 5 ) ;
if ( V_298 != 0 ) {
F_5 ( L_77 ) ;
return V_298 ;
}
V_300 = V_297 -> V_136 ;
for ( V_30 = 0 ; V_30 < V_300 -> V_137 . V_304 ; V_30 ++ ) {
V_302 = & V_300 -> V_302 [ V_30 ] . V_137 ;
if ( ( ( V_302 -> V_305 & V_306 )
== V_307 ) &&
( ( V_302 -> V_308 & V_309 )
== V_310 ) ) {
T_7 V_237 = F_143 ( V_302 -> V_311 ) ;
V_2 -> V_50 = ( V_237 & 0x07ff ) *
( ( ( V_237 & 0x1800 ) >> 11 ) + 1 ) ;
V_2 -> V_59 = V_302 -> V_305 ;
F_53 ( 1 ,
L_78 ,
V_2 -> V_59 , V_2 -> V_50 ) ;
}
}
if ( ! ( V_2 -> V_59 ) ) {
F_5 ( L_79 ) ;
F_17 ( V_2 ) ;
return - V_21 ;
}
F_26 ( & V_2 -> V_178 ) ;
F_144 ( & V_2 -> V_33 ) ;
F_145 ( & V_2 -> V_28 . V_91 ) ;
F_145 ( & V_2 -> V_28 . V_312 ) ;
F_145 ( & V_2 -> V_95 . V_91 ) ;
F_145 ( & V_2 -> V_95 . V_312 ) ;
V_2 -> V_101 . V_313 = F_70 ;
V_2 -> V_101 . V_154 = ( unsigned long ) V_2 ;
F_146 ( & V_2 -> V_101 ) ;
V_2 -> V_105 . V_313 = F_71 ;
V_2 -> V_105 . V_154 = ( unsigned long ) V_2 ;
F_146 ( & V_2 -> V_105 ) ;
V_2 -> V_86 = V_314 ;
V_2 -> V_113 = V_315 ;
V_2 -> V_212 = V_2 -> V_86 * V_2 -> V_113 ;
V_2 -> V_211 = V_2 -> V_212 << 1 ;
V_2 -> V_85 = V_2 -> V_86 << 1 ;
V_2 -> V_93 = 720 ;
V_2 -> V_94 = 1 ;
V_2 -> V_253 = 0 ;
V_2 -> V_182 = 960 ;
V_2 -> V_186 = V_316 ;
F_111 ( V_2 , 0 ) ;
V_2 -> V_145 = F_147 () ;
if ( NULL == V_2 -> V_145 ) {
F_53 ( 1 , L_80 ) ;
return - V_57 ;
}
V_2 -> V_146 = F_147 () ;
if ( NULL == V_2 -> V_146 ) {
F_53 ( 1 , L_81 ) ;
V_133 = - V_57 ;
goto V_317;
}
* V_2 -> V_145 = V_318 ;
V_2 -> V_145 -> V_174 = & V_2 -> V_174 ;
V_2 -> V_145 -> V_164 = & V_2 -> V_164 ;
strcpy ( V_2 -> V_145 -> V_218 , L_82 ) ;
* V_2 -> V_146 = V_318 ;
V_2 -> V_146 -> V_174 = & V_2 -> V_174 ;
V_2 -> V_146 -> V_164 = & V_2 -> V_164 ;
strcpy ( V_2 -> V_146 -> V_218 , L_83 ) ;
F_148 ( V_2 -> V_145 , V_2 ) ;
V_298 = F_149 ( V_2 -> V_145 , V_161 , - 1 ) ;
if ( V_298 != 0 ) {
F_53 ( 1 , L_84 ,
V_298 ) ;
V_133 = - V_21 ;
goto V_319;
}
F_148 ( V_2 -> V_146 , V_2 ) ;
V_298 = F_149 ( V_2 -> V_146 , V_162 , - 1 ) ;
if ( V_298 != 0 ) {
F_53 ( 1 , L_85 ,
V_298 ) ;
V_133 = - V_21 ;
goto V_319;
}
F_53 ( 1 , L_86 , V_143 ) ;
return 0 ;
V_319:
F_150 ( V_2 -> V_146 ) ;
V_317:
F_150 ( V_2 -> V_145 ) ;
return V_133 ;
}

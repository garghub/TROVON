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
F_5 ( V_21 L_12 ) ;
return - V_22 ;
}
if ( V_2 -> V_19 & V_23 ) {
F_5 ( V_21 L_13
L_14 ) ;
return - V_24 ;
}
return 0 ;
}
static void F_6 ( struct V_25 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_1 * V_2 = F_7 ( V_27 , struct V_1 , V_29 ) ;
unsigned long V_30 = 0 ;
int V_31 ;
switch ( V_25 -> V_9 ) {
case 0 :
case - V_32 :
break;
case - V_12 :
case - V_11 :
case - V_33 :
F_3 ( L_15 ) ;
return;
default:
F_3 ( L_16 , V_25 -> V_9 ) ;
break;
}
F_8 ( & V_2 -> V_34 , V_30 ) ;
V_2 -> V_35 . V_36 ( V_2 , V_25 ) ;
F_9 ( & V_2 -> V_34 , V_30 ) ;
for ( V_31 = 0 ; V_31 < V_25 -> V_37 ; V_31 ++ ) {
V_25 -> V_38 [ V_31 ] . V_9 = 0 ;
V_25 -> V_38 [ V_31 ] . V_39 = 0 ;
}
V_25 -> V_9 = 0 ;
V_25 -> V_9 = F_10 ( V_25 , V_40 ) ;
if ( V_25 -> V_9 ) {
F_3 ( L_17 ,
V_25 -> V_9 ) ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_25 * V_25 ;
int V_31 ;
F_3 ( L_18 ) ;
V_2 -> V_35 . V_41 = - 1 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_35 . V_42 ; V_31 ++ ) {
V_25 = V_2 -> V_35 . V_25 [ V_31 ] ;
if ( V_25 ) {
if ( ! F_12 () )
F_13 ( V_25 ) ;
else
F_14 ( V_25 ) ;
if ( V_2 -> V_35 . V_43 [ V_31 ] ) {
F_15 ( V_2 -> V_44 ,
V_25 -> V_45 ,
V_2 -> V_35 . V_43 [ V_31 ] ,
V_25 -> V_46 ) ;
}
F_16 ( V_25 ) ;
V_2 -> V_35 . V_25 [ V_31 ] = NULL ;
}
V_2 -> V_35 . V_43 [ V_31 ] = NULL ;
}
F_17 ( V_2 -> V_35 . V_25 ) ;
F_17 ( V_2 -> V_35 . V_43 ) ;
V_2 -> V_35 . V_25 = NULL ;
V_2 -> V_35 . V_43 = NULL ;
V_2 -> V_35 . V_42 = 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_47 ,
int V_42 , int V_48 ,
int (* V_36) ( struct V_1 * V_2 , struct V_25 * V_25 ) )
{
struct V_26 * V_27 = & V_2 -> V_29 ;
int V_31 ;
int V_49 , V_50 ;
struct V_25 * V_25 ;
int V_51 , V_52 ;
int V_53 ;
F_3 ( L_19 ) ;
F_11 ( V_2 ) ;
V_2 -> V_35 . V_36 = V_36 ;
V_2 -> V_35 . V_42 = V_42 ;
V_2 -> V_35 . V_25 = F_19 ( sizeof( void * ) * V_42 , V_54 ) ;
if ( ! V_2 -> V_35 . V_25 ) {
F_3 ( L_20 ) ;
return - V_55 ;
}
V_2 -> V_35 . V_43 = F_19 ( sizeof( void * ) * V_42 ,
V_54 ) ;
if ( ! V_2 -> V_35 . V_43 ) {
F_3 ( L_21 ) ;
F_17 ( V_2 -> V_35 . V_25 ) ;
return - V_55 ;
}
V_2 -> V_35 . V_48 = V_48 ;
V_2 -> V_35 . V_56 = NULL ;
V_49 = V_47 * V_2 -> V_35 . V_48 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_35 . V_42 ; V_31 ++ ) {
V_25 = F_20 ( V_47 , V_54 ) ;
if ( ! V_25 ) {
F_3 ( L_22 , V_31 ) ;
F_11 ( V_2 ) ;
return - V_55 ;
}
V_2 -> V_35 . V_25 [ V_31 ] = V_25 ;
V_2 -> V_35 . V_43 [ V_31 ] = F_21 ( V_2 -> V_44 ,
V_49 , V_54 , & V_25 -> V_46 ) ;
if ( ! V_2 -> V_35 . V_43 [ V_31 ] ) {
F_5 ( L_23
L_24 ,
V_49 , V_31 ,
F_22 () ? L_25 : L_26 ) ;
F_11 ( V_2 ) ;
return - V_55 ;
}
memset ( V_2 -> V_35 . V_43 [ V_31 ] , 0 , V_49 ) ;
V_50 = F_23 ( V_2 -> V_44 ,
V_2 -> V_57 ) ,
F_24 ( V_25 , V_2 -> V_44 , V_50 ,
V_2 -> V_35 . V_43 [ V_31 ] , V_49 ,
F_6 , V_27 , 1 ) ;
V_25 -> V_37 = V_47 ;
V_25 -> V_58 = V_59 | V_60 ;
V_52 = 0 ;
for ( V_51 = 0 ; V_51 < V_47 ; V_51 ++ ) {
V_25 -> V_38 [ V_51 ] . V_61 = V_52 ;
V_25 -> V_38 [ V_51 ] . V_62 =
V_2 -> V_35 . V_48 ;
V_52 += V_2 -> V_35 . V_48 ;
}
}
F_25 ( & V_27 -> V_63 ) ;
for ( V_31 = 0 ; V_31 < V_2 -> V_35 . V_42 ; V_31 ++ ) {
V_53 = F_10 ( V_2 -> V_35 . V_25 [ V_31 ] , V_40 ) ;
if ( V_53 ) {
F_3 ( L_27 ,
V_31 , V_53 ) ;
F_11 ( V_2 ) ;
return V_53 ;
}
}
return 0 ;
}
static inline void F_26 ( struct V_1 * V_2 ,
struct V_26 * V_27 ,
struct V_64 * V_56 )
{
F_3 ( L_28 , V_56 , V_56 -> V_65 . V_31 ) ;
V_56 -> V_65 . V_66 = V_67 ;
V_56 -> V_65 . V_68 ++ ;
F_27 ( & V_56 -> V_65 . V_69 ) ;
V_2 -> V_35 . V_56 = NULL ;
F_28 ( & V_56 -> V_65 . V_70 ) ;
F_29 ( & V_56 -> V_65 . V_71 ) ;
}
static inline void F_30 ( struct V_1 * V_2 ,
struct V_26 * V_27 ,
struct V_64 * V_56 )
{
F_3 ( L_28 , V_56 , V_56 -> V_65 . V_31 ) ;
V_56 -> V_65 . V_66 = V_67 ;
V_56 -> V_65 . V_68 ++ ;
F_27 ( & V_56 -> V_65 . V_69 ) ;
V_2 -> V_35 . V_72 = NULL ;
F_28 ( & V_56 -> V_65 . V_70 ) ;
F_29 ( & V_56 -> V_65 . V_71 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_26 * V_27 ,
struct V_64 * V_56 ,
unsigned char * V_73 ,
unsigned char * V_74 , unsigned long V_75 )
{
void * V_76 , * V_77 , * V_78 ;
int V_79 , V_80 , V_61 , V_81 , V_82 ;
int V_83 = V_2 -> V_84 << 1 ;
if ( V_75 == 0 )
return;
if ( V_27 -> V_85 + V_75 > V_56 -> V_65 . V_86 )
V_75 = V_56 -> V_65 . V_86 - V_27 -> V_85 ;
V_78 = V_73 ;
V_82 = V_75 ;
if ( V_56 -> V_87 )
V_76 = V_74 ;
else
V_76 = V_74 + V_83 ;
V_79 = V_27 -> V_85 / V_83 ;
V_80 = V_27 -> V_85 % V_83 ;
V_61 = V_79 * V_83 * 2 + V_80 ;
V_77 = V_76 + V_61 ;
V_81 = V_83 - V_80 ;
V_81 = V_81 > V_82 ? V_82 : V_81 ;
if ( ( char * ) V_77 + V_81 > ( char * ) V_74 + V_56 -> V_65 . V_86 ) {
F_3 ( L_29 ,
( ( char * ) V_77 + V_81 ) -
( ( char * ) V_74 + V_56 -> V_65 . V_86 ) ) ;
V_82 = ( char * ) V_74 + V_56 -> V_65 . V_86 - ( char * ) V_77 ;
V_81 = V_82 ;
}
if ( V_81 <= 0 )
return;
memcpy ( V_77 , V_78 , V_81 ) ;
V_82 -= V_81 ;
while ( V_82 > 0 ) {
V_77 += V_81 + V_83 ;
V_78 += V_81 ;
if ( V_83 > V_82 )
V_81 = V_82 ;
else
V_81 = V_83 ;
if ( ( char * ) V_77 + V_81 > ( char * ) V_74 +
V_56 -> V_65 . V_86 ) {
F_3 ( L_30 ,
( ( char * ) V_77 + V_81 ) -
( ( char * ) V_74 + V_56 -> V_65 . V_86 ) ) ;
V_81 = V_82 = ( char * ) V_74 + V_56 -> V_65 . V_86 -
( char * ) V_77 ;
}
if ( V_81 <= 0 )
break;
memcpy ( V_77 , V_78 , V_81 ) ;
V_82 -= V_81 ;
}
if ( V_61 > 1440 ) {
if ( V_74 [ 0 ] < 0x60 && V_74 [ 1440 ] < 0x60 )
V_2 -> V_88 = 1 ;
}
V_27 -> V_85 += V_75 ;
}
static inline void F_32 ( struct V_26 * V_27 ,
struct V_64 * * V_56 )
{
struct V_1 * V_2 = F_7 ( V_27 , struct V_1 , V_29 ) ;
if ( F_33 ( & V_27 -> V_89 ) ) {
F_3 ( L_31 ) ;
V_2 -> V_35 . V_56 = NULL ;
* V_56 = NULL ;
return;
}
* V_56 = F_34 ( V_27 -> V_89 . V_90 , struct V_64 , V_65 . V_70 ) ;
V_2 -> V_35 . V_56 = * V_56 ;
return;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_26 * V_27 ,
struct V_64 * V_56 ,
unsigned char * V_73 ,
unsigned char * V_74 , unsigned long V_75 )
{
unsigned char * V_77 , * V_78 ;
int V_83 ;
int V_31 , V_51 = 0 ;
if ( V_2 == NULL ) {
F_3 ( L_32 ) ;
return;
}
if ( V_27 == NULL ) {
F_3 ( L_33 ) ;
return;
}
if ( V_56 == NULL )
return;
if ( V_73 == NULL ) {
F_3 ( L_34 ) ;
return;
}
if ( V_74 == NULL ) {
F_3 ( L_35 ) ;
return;
}
V_83 = V_2 -> V_91 ;
if ( V_27 -> V_85 + V_75 > V_56 -> V_65 . V_86 )
V_75 = V_56 -> V_65 . V_86 - V_27 -> V_85 ;
V_78 = V_73 ;
V_77 = V_74 + ( V_27 -> V_85 / 2 ) ;
if ( V_56 -> V_87 == 0 )
V_77 += V_83 * V_2 -> V_92 ;
for ( V_31 = 0 ; V_31 < V_75 ; V_31 += 2 )
V_77 [ V_51 ++ ] = V_78 [ V_31 + 1 ] ;
V_27 -> V_85 += V_75 ;
}
static inline void F_36 ( struct V_26 * V_27 ,
struct V_64 * * V_56 )
{
struct V_1 * V_2 = F_7 ( V_27 , struct V_1 , V_93 ) ;
char * V_74 ;
if ( F_33 ( & V_27 -> V_89 ) ) {
F_3 ( L_31 ) ;
V_2 -> V_35 . V_72 = NULL ;
* V_56 = NULL ;
return;
}
* V_56 = F_34 ( V_27 -> V_89 . V_90 , struct V_64 , V_65 . V_70 ) ;
V_74 = F_37 ( & ( * V_56 ) -> V_65 ) ;
memset ( V_74 , 0x00 , ( * V_56 ) -> V_65 . V_86 ) ;
V_2 -> V_35 . V_72 = * V_56 ;
return;
}
static inline int F_38 ( struct V_1 * V_2 , struct V_25 * V_25 )
{
struct V_64 * V_56 ;
struct V_64 * V_72 ;
struct V_26 * V_27 = V_25 -> V_28 ;
struct V_26 * V_94 = & V_2 -> V_93 ;
unsigned char * V_74 = NULL ;
unsigned char * V_95 = NULL ;
int V_31 , V_75 = 0 , V_53 = 1 ;
unsigned char * V_73 ;
unsigned char V_96 ;
unsigned int V_97 ;
unsigned int V_82 , V_81 ;
if ( ! V_2 )
return 0 ;
if ( ( V_2 -> V_19 & V_20 ) ||
( V_2 -> V_19 & V_23 ) )
return 0 ;
if ( V_25 -> V_9 < 0 ) {
F_2 ( V_2 , - 1 , V_25 -> V_9 ) ;
if ( V_25 -> V_9 == - V_11 )
return 0 ;
}
V_56 = V_2 -> V_35 . V_56 ;
if ( V_56 != NULL )
V_74 = F_37 ( & V_56 -> V_65 ) ;
V_72 = V_2 -> V_35 . V_72 ;
if ( V_72 != NULL )
V_95 = F_37 ( & V_72 -> V_65 ) ;
for ( V_31 = 0 ; V_31 < V_25 -> V_37 ; V_31 ++ ) {
int V_9 = V_25 -> V_38 [ V_31 ] . V_9 ;
if ( V_9 < 0 ) {
F_2 ( V_2 , V_31 , V_9 ) ;
if ( V_25 -> V_38 [ V_31 ] . V_9 != - V_16 )
continue;
}
if ( V_25 -> V_38 [ V_31 ] . V_39 <= 0 )
continue;
if ( V_25 -> V_38 [ V_31 ] . V_39 >
V_2 -> V_48 ) {
F_3 ( L_36 ) ;
continue;
}
V_73 = V_25 -> V_43 + V_25 -> V_38 [ V_31 ] . V_61 ;
V_96 = V_73 [ 0 ] ;
V_75 = V_25 -> V_38 [ V_31 ] . V_39 - 4 ;
V_73 += 4 ;
if ( V_96 & 0x80 ) {
V_75 -= 4 ;
V_73 += 4 ;
F_3 ( L_37 ,
( V_96 & 0x40 ) ? L_38 : L_39 ) ;
if ( V_96 & 0x40 ) {
if ( V_72 != NULL )
F_30 ( V_2 ,
V_94 ,
V_72 ) ;
F_36 ( V_94 , & V_72 ) ;
if ( V_72 == NULL )
V_95 = NULL ;
else
V_95 = F_37 (
& V_72 -> V_65 ) ;
if ( V_56 != NULL )
F_26 ( V_2 , V_27 , V_56 ) ;
F_32 ( V_27 , & V_56 ) ;
if ( V_56 == NULL )
V_74 = NULL ;
else
V_74 = F_37 ( & V_56 -> V_65 ) ;
if ( V_2 -> V_98 )
F_39 ( & V_2 -> V_99 ,
V_100 + ( V_101 / 10 ) ) ;
if ( V_2 -> V_102 )
F_39 ( & V_2 -> V_103 ,
V_100 + ( V_101 / 10 ) ) ;
}
if ( V_56 != NULL ) {
if ( V_96 & 0x40 )
V_56 -> V_87 = 1 ;
else
V_56 -> V_87 = 0 ;
}
if ( V_72 != NULL ) {
if ( V_96 & 0x40 )
V_72 -> V_87 = 1 ;
else
V_72 -> V_87 = 0 ;
}
V_2 -> V_104 = 0 ;
V_94 -> V_85 = 0 ;
V_27 -> V_85 = 0 ;
}
V_97 = V_2 -> V_91 * V_2 -> V_92 * 2 ;
if ( V_2 -> V_104 < V_97 ) {
V_82 = V_97 - V_2 -> V_104 ;
if ( V_75 < V_82 )
V_81 = V_75 ;
else
V_81 = V_82 ;
if ( V_72 != NULL )
F_35 ( V_2 , V_94 , V_72 , V_73 ,
V_95 , V_75 ) ;
V_75 -= V_81 ;
V_73 += V_81 ;
V_2 -> V_104 += V_81 ;
}
if ( V_2 -> V_104 >= V_97 && V_56 != NULL )
F_31 ( V_2 , V_27 , V_56 , V_73 , V_74 , V_75 ) ;
}
return V_53 ;
}
static int
F_40 ( struct V_105 * V_106 , unsigned int * V_107 ,
unsigned int * V_86 )
{
struct V_108 * V_109 = V_106 -> V_110 ;
* V_86 = ( V_109 -> V_2 -> V_84 * V_109 -> V_2 -> V_111 * 16 + 7 ) >> 3 ;
if ( 0 == * V_107 )
* V_107 = V_112 ;
if ( * V_107 < V_113 )
* V_107 = V_113 ;
return 0 ;
}
static void F_41 ( struct V_105 * V_106 , struct V_64 * V_56 )
{
struct V_108 * V_109 = V_106 -> V_110 ;
struct V_1 * V_2 = V_109 -> V_2 ;
unsigned long V_30 = 0 ;
if ( F_22 () )
F_42 () ;
F_8 ( & V_2 -> V_34 , V_30 ) ;
if ( V_2 -> V_35 . V_56 == V_56 )
V_2 -> V_35 . V_56 = NULL ;
F_9 ( & V_2 -> V_34 , V_30 ) ;
F_43 ( & V_56 -> V_65 ) ;
V_56 -> V_65 . V_66 = V_114 ;
}
static int
F_44 ( struct V_105 * V_106 , struct V_115 * V_65 ,
enum V_116 V_117 )
{
struct V_108 * V_109 = V_106 -> V_110 ;
struct V_64 * V_56 = F_7 ( V_65 , struct V_64 , V_65 ) ;
struct V_1 * V_2 = V_109 -> V_2 ;
int V_53 = 0 , V_118 = 0 ;
V_56 -> V_65 . V_86 = ( V_109 -> V_2 -> V_84 * V_109 -> V_2 -> V_111 * 16 + 7 ) >> 3 ;
if ( 0 != V_56 -> V_65 . V_119 && V_56 -> V_65 . V_120 < V_56 -> V_65 . V_86 )
return - V_121 ;
V_56 -> V_65 . V_84 = V_2 -> V_84 ;
V_56 -> V_65 . V_111 = V_2 -> V_111 ;
V_56 -> V_65 . V_117 = V_117 ;
if ( V_114 == V_56 -> V_65 . V_66 ) {
V_53 = F_45 ( V_106 , & V_56 -> V_65 , NULL ) ;
if ( V_53 < 0 ) {
F_5 ( V_21 L_40 ) ;
goto V_122;
}
}
if ( ! V_2 -> V_35 . V_42 )
V_118 = 1 ;
if ( V_118 ) {
V_53 = F_18 ( V_2 , V_123 ,
V_124 , V_2 -> V_48 ,
F_38 ) ;
if ( V_53 < 0 ) {
F_5 ( V_21 L_41 ) ;
goto V_122;
}
}
V_56 -> V_65 . V_66 = V_125 ;
return 0 ;
V_122:
F_41 ( V_106 , V_56 ) ;
return V_53 ;
}
static void
F_46 ( struct V_105 * V_106 , struct V_115 * V_65 )
{
struct V_64 * V_56 = F_7 ( V_65 ,
struct V_64 ,
V_65 ) ;
struct V_108 * V_109 = V_106 -> V_110 ;
struct V_1 * V_2 = V_109 -> V_2 ;
struct V_26 * V_29 = & V_2 -> V_29 ;
V_56 -> V_65 . V_66 = V_126 ;
F_47 ( & V_56 -> V_65 . V_70 , & V_29 -> V_89 ) ;
}
static void F_48 ( struct V_105 * V_106 ,
struct V_115 * V_65 )
{
struct V_64 * V_56 = F_7 ( V_65 ,
struct V_64 ,
V_65 ) ;
F_41 ( V_106 , V_56 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
F_50 ( V_2 , V_127 , 0x01 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_128 )
{
struct V_129 * V_130 ;
int V_131 , V_132 , V_133 ;
F_52 ( 1 , L_42 ) ;
V_130 = F_53 ( V_128 -> V_44 , 0 ) ;
if ( V_130 && V_130 -> V_134 -> V_135 . V_136 != 5 ) {
F_52 ( 1 , L_43 ) ;
V_131 = F_54 ( V_128 -> V_44 , 0 , 5 ) ;
if ( V_131 < 0 ) {
F_5 ( V_21 L_44 ) ;
return - V_137 ;
}
}
V_132 = V_128 -> V_111 / 2 + 2 ;
V_133 = V_128 -> V_84 * 2 ;
F_50 ( V_128 , V_138 , 0x00 ) ;
F_50 ( V_128 , 0x106 , 0x00 ) ;
F_50 ( V_128 , 0x110 , 0x00 ) ;
F_50 ( V_128 , 0x111 , 0x00 ) ;
F_50 ( V_128 , 0x114 , V_133 & 0xff ) ;
F_50 ( V_128 , 0x115 , V_133 >> 8 ) ;
F_50 ( V_128 , 0x112 , 0x00 ) ;
F_50 ( V_128 , 0x113 , 0x00 ) ;
F_50 ( V_128 , 0x116 , V_132 & 0xff ) ;
F_50 ( V_128 , 0x117 , V_132 >> 8 ) ;
F_50 ( V_128 , V_139 , 0xb3 ) ;
return 0 ;
}
int F_55 ( struct V_1 * V_128 )
{
F_52 ( 1 , L_45 ) ;
F_50 ( V_128 , V_139 , 0x0 ) ;
return 0 ;
}
static void F_56 ( struct V_1 * V_2 )
{
F_52 ( 1 , L_46 ) ;
F_50 ( V_2 , V_139 , 0x0 ) ;
F_57 ( 30 ) ;
F_50 ( V_2 , V_139 , 0xb3 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_131 = 0 ;
V_2 -> V_140 = V_141 ;
if ( V_2 -> V_19 == V_20 )
return - V_22 ;
else if ( V_131 ) {
V_2 -> V_19 = V_23 ;
F_52 ( 1 , L_47 , V_142 ) ;
return V_131 ;
}
return 0 ;
}
void F_59 ( struct V_1 * V_2 )
{
F_52 ( 1 , L_48 ) ;
F_60 ( & V_143 ) ;
if ( V_2 -> V_144 )
F_61 ( V_2 -> V_144 ) ;
if ( V_2 -> V_145 )
F_61 ( V_2 -> V_145 ) ;
F_62 ( & V_143 ) ;
}
static int F_63 ( struct V_108 * V_109 , unsigned int V_146 )
{
struct V_1 * V_2 = V_109 -> V_2 ;
if ( V_109 -> V_147 & V_146 )
return 1 ;
if ( V_2 -> V_147 & V_146 ) {
return 0 ;
}
V_109 -> V_147 |= V_146 ;
V_2 -> V_147 |= V_146 ;
F_52 ( 1 , L_49 , V_146 ) ;
return 1 ;
}
static int F_64 ( struct V_108 * V_109 , unsigned int V_146 )
{
return V_109 -> V_147 & V_146 ;
}
static int F_65 ( struct V_1 * V_2 , unsigned int V_146 )
{
return V_2 -> V_147 & V_146 ;
}
static void F_66 ( struct V_108 * V_109 , unsigned int V_148 )
{
struct V_1 * V_2 = V_109 -> V_2 ;
F_67 ( ( V_109 -> V_147 & V_148 ) != V_148 ) ;
V_109 -> V_147 &= ~ V_148 ;
V_2 -> V_147 &= ~ V_148 ;
F_52 ( 1 , L_50 , V_148 ) ;
}
static int F_68 ( struct V_108 * V_109 )
{
switch ( V_109 -> type ) {
case V_149 :
return V_150 ;
case V_151 :
return V_152 ;
default:
F_42 () ;
return 0 ;
}
}
static void F_69 ( unsigned long V_153 )
{
struct V_1 * V_2 = (struct V_1 * ) V_153 ;
struct V_26 * V_27 = & V_2 -> V_29 ;
struct V_64 * V_56 ;
unsigned char * V_154 ;
unsigned long V_30 = 0 ;
F_8 ( & V_2 -> V_34 , V_30 ) ;
V_56 = V_2 -> V_35 . V_56 ;
if ( V_56 != NULL ) {
V_154 = F_37 ( & V_56 -> V_65 ) ;
memset ( V_154 , 0x00 , V_56 -> V_65 . V_86 ) ;
F_26 ( V_2 , V_27 , V_56 ) ;
}
F_32 ( V_27 , & V_56 ) ;
if ( V_2 -> V_98 == 1 )
F_39 ( & V_2 -> V_99 , V_100 + ( V_101 / 10 ) ) ;
F_9 ( & V_2 -> V_34 , V_30 ) ;
}
static void F_70 ( unsigned long V_153 )
{
struct V_1 * V_2 = (struct V_1 * ) V_153 ;
struct V_26 * V_27 = & V_2 -> V_93 ;
struct V_64 * V_56 ;
unsigned char * V_155 ;
unsigned long V_30 = 0 ;
F_8 ( & V_2 -> V_34 , V_30 ) ;
V_56 = V_2 -> V_35 . V_72 ;
if ( V_56 != NULL ) {
V_155 = F_37 ( & V_56 -> V_65 ) ;
memset ( V_155 , 0x00 , V_56 -> V_65 . V_86 ) ;
F_30 ( V_2 , V_27 , V_56 ) ;
}
F_36 ( V_27 , & V_56 ) ;
if ( V_2 -> V_102 == 1 )
F_39 ( & V_2 -> V_103 , V_100 + ( V_101 / 10 ) ) ;
F_9 ( & V_2 -> V_34 , V_30 ) ;
}
static int F_71 ( struct V_156 * V_157 )
{
int V_131 = 0 ;
struct V_158 * V_144 = F_72 ( V_157 ) ;
struct V_1 * V_2 = F_73 ( V_157 ) ;
struct V_108 * V_109 ;
int type ;
switch ( V_144 -> V_159 ) {
case V_160 :
type = V_149 ;
break;
case V_161 :
type = V_151 ;
break;
default:
return - V_121 ;
}
V_109 = F_19 ( sizeof( struct V_108 ) , V_54 ) ;
if ( NULL == V_109 ) {
F_52 ( 1 , L_51 ) ;
return - V_55 ;
}
V_109 -> type = type ;
V_109 -> V_2 = V_2 ;
F_74 ( & V_109 -> V_109 , V_144 ) ;
V_157 -> V_162 = V_109 ;
if ( F_75 ( & V_2 -> V_163 ) ) {
F_17 ( V_109 ) ;
return - V_164 ;
}
if ( V_2 -> V_165 == 0 ) {
F_51 ( V_2 ) ;
F_56 ( V_2 ) ;
F_49 ( V_2 ) ;
V_2 -> V_140 = V_166 ;
V_2 -> V_19 |= V_167 ;
}
V_2 -> V_165 ++ ;
F_62 ( & V_2 -> V_163 ) ;
F_76 ( & V_109 -> V_168 , & V_169 ,
NULL , & V_2 -> V_34 ,
V_149 ,
V_170 ,
sizeof( struct V_64 ) , V_109 ,
& V_2 -> V_163 ) ;
F_76 ( & V_109 -> V_171 , & V_172 ,
NULL , & V_2 -> V_34 ,
V_151 ,
V_173 ,
sizeof( struct V_64 ) , V_109 ,
& V_2 -> V_163 ) ;
F_77 ( & V_109 -> V_109 ) ;
return V_131 ;
}
static int F_78 ( struct V_156 * V_157 )
{
int V_131 ;
struct V_108 * V_109 = V_157 -> V_162 ;
struct V_1 * V_2 = V_109 -> V_2 ;
F_79 ( & V_109 -> V_109 ) ;
F_80 ( & V_109 -> V_109 ) ;
F_60 ( & V_2 -> V_163 ) ;
if ( F_64 ( V_109 , V_150 ) ) {
V_2 -> V_98 = 0 ;
F_81 ( & V_2 -> V_99 ) ;
F_82 ( & V_109 -> V_168 ) ;
F_66 ( V_109 , V_150 ) ;
}
if ( F_64 ( V_109 , V_152 ) ) {
V_2 -> V_102 = 0 ;
F_81 ( & V_2 -> V_103 ) ;
F_82 ( & V_109 -> V_171 ) ;
F_66 ( V_109 , V_152 ) ;
}
if ( V_2 -> V_165 == 1 && F_83 ( F_72 ( V_157 ) ) ) {
F_55 ( V_2 ) ;
F_11 ( V_2 ) ;
F_84 ( & V_2 -> V_174 , 0 , V_175 , V_176 , 0 ) ;
V_2 -> V_177 = 0 ;
V_131 = F_54 ( V_2 -> V_44 , 0 , 0 ) ;
if ( V_131 < 0 )
F_5 ( V_21 L_52 ) ;
}
F_62 ( & V_2 -> V_163 ) ;
F_85 ( & V_109 -> V_168 ) ;
F_85 ( & V_109 -> V_171 ) ;
F_17 ( V_109 ) ;
V_2 -> V_165 -- ;
F_86 ( & V_2 -> V_178 , 1 ) ;
return 0 ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_179 V_180 = {
. V_181 = V_2 -> V_182 ,
. type = V_183 ,
} ;
if ( V_2 -> V_177 )
return;
V_2 -> V_177 = 1 ;
F_1 ( V_2 , 1 ) ;
F_84 ( & V_2 -> V_174 , 0 , V_184 , V_185 , V_2 -> V_186 ) ;
F_84 ( & V_2 -> V_174 , 0 , V_187 , V_188 , & V_180 ) ;
F_1 ( V_2 , 0 ) ;
}
static T_1 F_88 ( struct V_156 * V_157 , char T_2 * V_56 ,
T_3 V_107 , T_4 * V_85 )
{
struct V_108 * V_109 = V_157 -> V_162 ;
struct V_1 * V_2 = V_109 -> V_2 ;
int V_53 ;
V_53 = F_4 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( F_75 ( & V_2 -> V_163 ) )
return - V_164 ;
F_87 ( V_2 ) ;
F_62 ( & V_2 -> V_163 ) ;
if ( V_109 -> type == V_149 ) {
if ( F_65 ( V_2 , V_150 ) )
return - V_137 ;
return F_89 ( & V_109 -> V_168 , V_56 , V_107 , V_85 , 0 ,
V_157 -> V_189 & V_190 ) ;
}
if ( V_109 -> type == V_151 ) {
if ( ! F_63 ( V_109 , V_152 ) )
return - V_137 ;
if ( V_2 -> V_102 == 0 ) {
V_2 -> V_102 = 1 ;
F_39 ( & V_2 -> V_103 , V_100 + ( V_101 / 10 ) ) ;
}
return F_89 ( & V_109 -> V_171 , V_56 , V_107 , V_85 , 0 ,
V_157 -> V_189 & V_190 ) ;
}
return 0 ;
}
static unsigned int F_90 ( struct V_156 * V_157 , T_5 * V_191 )
{
struct V_108 * V_109 = V_157 -> V_162 ;
struct V_1 * V_2 = V_109 -> V_2 ;
unsigned long V_192 = F_91 ( V_191 ) ;
unsigned int V_193 ;
if ( F_4 ( V_2 ) < 0 )
return V_194 ;
V_193 = F_92 ( V_157 , V_191 ) ;
if ( ! ( V_192 & ( V_195 | V_196 ) ) )
return V_193 ;
if ( F_75 ( & V_2 -> V_163 ) )
return - V_164 ;
F_87 ( V_2 ) ;
F_62 ( & V_2 -> V_163 ) ;
if ( V_109 -> type == V_149 ) {
if ( ! F_63 ( V_109 , V_150 ) )
return V_194 ;
return V_193 | F_93 ( V_157 , & V_109 -> V_168 , V_191 ) ;
}
if ( V_109 -> type == V_151 ) {
if ( ! F_63 ( V_109 , V_152 ) )
return V_194 ;
return V_193 | F_93 ( V_157 , & V_109 -> V_171 , V_191 ) ;
}
return V_194 ;
}
static int F_94 ( struct V_156 * V_157 , struct V_197 * V_198 )
{
struct V_108 * V_109 = V_157 -> V_162 ;
struct V_1 * V_2 = V_109 -> V_2 ;
int V_53 ;
V_53 = F_4 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_109 -> type == V_149 )
V_53 = F_95 ( & V_109 -> V_168 , V_198 ) ;
else if ( V_109 -> type == V_151 )
V_53 = F_95 ( & V_109 -> V_171 , V_198 ) ;
return V_53 ;
}
static int F_96 ( struct V_1 * V_2 , unsigned int V_199 ,
struct V_200 * V_201 )
{
int V_131 ;
int V_84 = V_201 -> V_202 . V_203 . V_84 ;
int V_111 = V_201 -> V_202 . V_203 . V_111 ;
if ( V_201 -> V_202 . V_203 . V_204 != V_205 )
return - V_121 ;
if ( V_84 != 720 )
V_84 = 720 ;
if ( V_111 != 480 )
V_111 = 480 ;
V_201 -> V_202 . V_203 . V_84 = V_84 ;
V_201 -> V_202 . V_203 . V_111 = V_111 ;
V_201 -> V_202 . V_203 . V_204 = V_205 ;
V_201 -> V_202 . V_203 . V_83 = V_84 * 2 ;
V_201 -> V_202 . V_203 . V_206 = V_84 * V_111 * 2 ;
V_201 -> V_202 . V_203 . V_207 = V_208 ;
V_201 -> V_202 . V_203 . V_117 = V_170 ;
V_201 -> V_202 . V_203 . V_209 = 0 ;
if ( V_199 == V_210 )
return 0 ;
V_2 -> V_84 = V_84 ;
V_2 -> V_111 = V_111 ;
V_2 -> V_211 = V_84 * V_111 * 2 ;
V_2 -> V_212 = V_84 * V_111 ;
V_2 -> V_83 = V_84 * 2 ;
if ( V_2 -> V_140 == V_213 ) {
F_52 ( 1 , L_53 ) ;
V_131 = F_58 ( V_2 ) ;
if ( V_131 != 0 ) {
F_52 ( 1 , L_54 ) ;
return V_131 ;
}
}
F_51 ( V_2 ) ;
return 0 ;
}
static int F_97 ( struct V_156 * V_156 , void * V_209 ,
struct V_214 * V_215 )
{
struct V_158 * V_144 = F_72 ( V_156 ) ;
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
F_98 ( V_215 -> V_216 , L_55 , sizeof( V_215 -> V_216 ) ) ;
F_98 ( V_215 -> V_217 , V_2 -> V_218 . V_219 , sizeof( V_215 -> V_217 ) ) ;
F_99 ( V_2 -> V_44 , V_215 -> V_220 , sizeof( V_215 -> V_220 ) ) ;
V_215 -> V_221 = V_222 |
V_223 |
V_224 |
V_225 ;
if ( V_144 -> V_159 == V_160 )
V_215 -> V_221 |= V_226 ;
else
V_215 -> V_221 |= V_227 ;
V_215 -> V_228 = V_215 -> V_221 | V_229 |
V_227 | V_226 ;
return 0 ;
}
static int F_100 ( struct V_156 * V_156 , void * V_209 ,
struct V_230 * V_180 )
{
if ( V_180 -> V_231 )
return - V_121 ;
V_180 -> type = V_149 ;
strcpy ( V_180 -> V_232 , L_56 ) ;
V_180 -> V_30 = 0 ;
V_180 -> V_204 = V_205 ;
return 0 ;
}
static int F_101 ( struct V_156 * V_156 , void * V_209 ,
struct V_200 * V_180 )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
V_180 -> V_202 . V_203 . V_84 = V_2 -> V_84 ;
V_180 -> V_202 . V_203 . V_111 = V_2 -> V_111 ;
V_180 -> V_202 . V_203 . V_204 = V_205 ;
V_180 -> V_202 . V_203 . V_83 = V_2 -> V_83 ;
V_180 -> V_202 . V_203 . V_206 = V_2 -> V_211 ;
V_180 -> V_202 . V_203 . V_207 = V_208 ;
V_180 -> V_202 . V_203 . V_117 = V_170 ;
V_180 -> V_202 . V_203 . V_209 = 0 ;
return 0 ;
}
static int F_102 ( struct V_156 * V_156 , void * V_209 ,
struct V_200 * V_180 )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
return F_96 ( V_2 , V_210 , V_180 ) ;
}
static int F_103 ( struct V_156 * V_156 , void * V_209 ,
struct V_200 * V_180 )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
int V_53 ;
V_53 = F_4 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( F_104 ( & V_109 -> V_168 ) ) {
F_5 ( V_21 L_57 , V_142 ) ;
V_53 = - V_137 ;
goto V_233;
}
V_53 = F_96 ( V_2 , V_234 , V_180 ) ;
V_233:
return V_53 ;
}
static int F_105 ( struct V_156 * V_156 , void * V_209 , T_6 V_235 )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
V_2 -> V_186 = V_235 ;
F_87 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_84 ( & V_2 -> V_174 , 0 , V_184 , V_185 , V_235 ) ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int F_106 ( struct V_156 * V_156 , void * V_209 , T_6 * V_235 )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
* V_235 = V_2 -> V_186 ;
return 0 ;
}
static int F_107 ( struct V_156 * V_156 , void * V_209 ,
struct V_236 * V_237 )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
unsigned int V_238 ;
static const char * V_239 [] = {
[ V_240 ] = L_58 ,
[ V_241 ] = L_59 ,
[ V_242 ] = L_60 ,
[ V_243 ] = L_61 ,
[ V_244 ] = L_62 ,
[ V_245 ] = L_63 ,
[ V_246 ] = L_64
} ;
V_238 = V_237 -> V_231 ;
if ( V_238 >= V_247 )
return - V_121 ;
if ( F_108 ( V_238 ) . type == 0 )
return - V_121 ;
V_237 -> V_231 = V_238 ;
strcpy ( V_237 -> V_219 , V_239 [ F_108 ( V_238 ) . type ] ) ;
if ( ( F_108 ( V_238 ) . type == V_244 ) ||
( F_108 ( V_238 ) . type == V_243 ) ) {
V_237 -> type |= V_248 ;
V_237 -> V_249 = 1 ;
} else {
V_237 -> type |= V_250 ;
V_237 -> V_249 = 2 ;
}
V_237 -> V_186 = V_2 -> V_144 -> V_251 ;
return 0 ;
}
static int F_109 ( struct V_156 * V_156 , void * V_209 , unsigned int * V_31 )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
* V_31 = V_2 -> V_252 ;
return 0 ;
}
static void F_110 ( struct V_1 * V_2 , int V_231 )
{
int V_31 ;
switch ( F_108 ( V_231 ) . type ) {
case V_242 :
V_2 -> V_253 = V_242 ;
V_2 -> V_254 = 1 ;
break;
case V_241 :
V_2 -> V_253 = V_241 ;
V_2 -> V_254 = 1 ;
break;
case V_244 :
V_2 -> V_253 = V_244 ;
V_2 -> V_254 = 0 ;
break;
default:
F_52 ( 1 , L_65 ,
F_108 ( V_231 ) . type ) ;
break;
}
F_84 ( & V_2 -> V_174 , 0 , V_184 , V_255 ,
F_108 ( V_231 ) . V_256 , 0 , 0 ) ;
for ( V_31 = 0 ; V_31 < V_247 ; V_31 ++ ) {
int V_257 = 0 ;
if ( F_108 ( V_31 ) . V_258 == NULL )
continue;
if ( V_31 == V_231 )
V_257 = 1 ;
else
V_257 = 0 ;
if ( V_257 ) {
( F_108 ( V_31 ) . V_258 ) ( V_2 , V_257 ) ;
} else {
if ( ( F_108 ( V_31 ) . V_258 ) !=
( ( F_108 ( V_231 ) . V_258 ) ) ) {
( F_108 ( V_31 ) . V_258 ) ( V_2 , V_257 ) ;
}
}
}
F_84 ( & V_2 -> V_174 , 0 , V_259 , V_255 ,
F_108 ( V_231 ) . V_260 , 0 , 0 ) ;
}
static int F_111 ( struct V_156 * V_156 , void * V_209 , unsigned int V_231 )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
F_52 ( 1 , L_66 , V_142 ,
V_231 ) ;
if ( V_231 >= V_247 )
return - V_121 ;
if ( F_108 ( V_231 ) . type == 0 )
return - V_121 ;
V_2 -> V_252 = V_231 ;
F_110 ( V_2 , V_231 ) ;
return 0 ;
}
static int F_112 ( struct V_156 * V_156 , void * V_209 , struct V_261 * V_262 )
{
if ( V_262 -> V_231 > 1 )
return - V_121 ;
if ( V_262 -> V_231 == 0 )
strcpy ( V_262 -> V_219 , L_62 ) ;
else
strcpy ( V_262 -> V_219 , L_67 ) ;
V_262 -> V_263 = V_264 ;
return 0 ;
}
static int F_113 ( struct V_156 * V_156 , void * V_209 , struct V_261 * V_262 )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
V_262 -> V_231 = V_2 -> V_254 ;
if ( V_262 -> V_231 == 0 )
strcpy ( V_262 -> V_219 , L_62 ) ;
else
strcpy ( V_262 -> V_219 , L_67 ) ;
V_262 -> V_263 = V_264 ;
return 0 ;
}
static int F_114 ( struct V_156 * V_156 , void * V_209 , const struct V_261 * V_262 )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
if ( V_262 -> V_231 != V_2 -> V_254 )
return - V_121 ;
return 0 ;
}
static int F_115 ( struct V_156 * V_156 , void * V_209 , struct V_265 * V_266 )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
if ( V_266 -> V_231 != 0 )
return - V_121 ;
strcpy ( V_266 -> V_219 , L_68 ) ;
F_87 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_84 ( & V_2 -> V_174 , 0 , V_187 , V_267 , V_266 ) ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int F_116 ( struct V_156 * V_156 , void * V_209 ,
const struct V_265 * V_266 )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
if ( V_266 -> V_231 != 0 )
return - V_121 ;
F_87 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_84 ( & V_2 -> V_174 , 0 , V_187 , V_268 , V_266 ) ;
F_1 ( V_2 , 0 ) ;
F_52 ( 1 , L_69 , V_266 -> signal ,
V_266 -> V_269 ) ;
return 0 ;
}
static int F_117 ( struct V_156 * V_156 , void * V_209 ,
struct V_179 * V_270 )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
if ( V_270 -> V_187 != 0 )
return - V_121 ;
V_270 -> V_181 = V_2 -> V_182 ;
return 0 ;
}
static int F_118 ( struct V_156 * V_156 , void * V_209 ,
const struct V_179 * V_270 )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
struct V_179 V_271 = * V_270 ;
if ( V_270 -> V_187 != 0 )
return - V_121 ;
F_87 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_84 ( & V_2 -> V_174 , 0 , V_187 , V_188 , V_270 ) ;
F_84 ( & V_2 -> V_174 , 0 , V_187 , V_272 , & V_271 ) ;
V_2 -> V_182 = V_271 . V_181 ;
F_1 ( V_2 , 0 ) ;
F_56 ( V_2 ) ;
return 0 ;
}
static int F_119 ( struct V_156 * V_156 , void * V_209 ,
struct V_200 * V_201 )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
V_201 -> V_202 . V_273 . V_274 = V_2 -> V_91 ;
V_201 -> V_202 . V_273 . V_275 = V_276 ;
V_201 -> V_202 . V_273 . V_61 = 0 ;
V_201 -> V_202 . V_273 . V_30 = 0 ;
V_201 -> V_202 . V_273 . V_277 = 6750000 * 4 / 2 ;
V_201 -> V_202 . V_273 . V_107 [ 0 ] = V_2 -> V_92 ;
V_201 -> V_202 . V_273 . V_107 [ 1 ] = V_2 -> V_92 ;
V_201 -> V_202 . V_273 . V_278 [ 0 ] = 21 ;
V_201 -> V_202 . V_273 . V_278 [ 1 ] = 284 ;
memset ( V_201 -> V_202 . V_273 . V_279 , 0 , sizeof( V_201 -> V_202 . V_273 . V_279 ) ) ;
return 0 ;
}
static int F_120 ( struct V_156 * V_156 , void * V_209 ,
struct V_280 * V_281 )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
if ( V_281 -> type != V_149 )
return - V_121 ;
V_281 -> V_282 . V_283 = 0 ;
V_281 -> V_282 . V_284 = 0 ;
V_281 -> V_282 . V_84 = V_2 -> V_84 ;
V_281 -> V_282 . V_111 = V_2 -> V_111 ;
V_281 -> V_285 = V_281 -> V_282 ;
V_281 -> V_286 . V_287 = 54 ;
V_281 -> V_286 . V_288 = 59 ;
return 0 ;
}
static int F_121 ( struct V_156 * V_156 , void * V_209 ,
enum V_289 type )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
int V_53 = - V_121 ;
V_53 = F_4 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( F_122 ( type != V_109 -> type ) )
return - V_121 ;
F_52 ( 1 , L_70 ,
V_109 , type , V_109 -> V_147 , V_2 -> V_147 ) ;
if ( F_122 ( ! F_63 ( V_109 , F_68 ( V_109 ) ) ) )
return - V_137 ;
F_87 ( V_2 ) ;
if ( type == V_149 ) {
F_51 ( V_2 ) ;
F_84 ( & V_2 -> V_174 , 0 , V_184 , V_290 , 1 ) ;
}
if ( V_109 -> type == V_149 ) {
V_53 = F_123 ( & V_109 -> V_168 ) ;
V_2 -> V_98 = 1 ;
F_39 ( & V_2 -> V_99 , V_100 + ( V_101 / 10 ) ) ;
} else if ( V_109 -> type == V_151 ) {
V_53 = F_123 ( & V_109 -> V_171 ) ;
V_2 -> V_102 = 1 ;
F_39 ( & V_2 -> V_103 , V_100 + ( V_101 / 10 ) ) ;
}
return V_53 ;
}
static int F_124 ( struct V_156 * V_156 , void * V_209 ,
enum V_289 type )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
int V_53 ;
int V_31 ;
V_53 = F_4 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_109 -> type != V_149 &&
V_109 -> type != V_151 )
return - V_121 ;
if ( type != V_109 -> type )
return - V_121 ;
F_52 ( 1 , L_71 ,
V_109 , type , V_109 -> V_147 , V_2 -> V_147 ) ;
if ( V_109 -> type == V_149 ) {
V_2 -> V_98 = 0 ;
F_81 ( & V_2 -> V_99 ) ;
F_55 ( V_2 ) ;
F_84 ( & V_2 -> V_174 , 0 , V_184 , V_290 , 0 ) ;
V_53 = F_58 ( V_2 ) ;
if ( V_53 != 0 )
return V_53 ;
for ( V_31 = 0 ; V_31 < V_247 ; V_31 ++ ) {
if ( F_108 ( V_31 ) . V_258 == NULL )
continue;
( F_108 ( V_31 ) . V_258 ) ( V_2 , 0 ) ;
}
if ( F_64 ( V_109 , V_150 ) ) {
F_125 ( & V_109 -> V_168 ) ;
F_66 ( V_109 , V_150 ) ;
}
} else if ( V_109 -> type == V_151 ) {
V_2 -> V_102 = 0 ;
F_81 ( & V_2 -> V_103 ) ;
if ( F_64 ( V_109 , V_152 ) ) {
F_125 ( & V_109 -> V_171 ) ;
F_66 ( V_109 , V_152 ) ;
}
}
return 0 ;
}
static int F_126 ( struct V_156 * V_156 , void * V_209 ,
struct V_291 * V_292 )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
V_292 -> V_3 = F_127 ( V_2 , V_292 -> V_292 ) ;
V_292 -> V_86 = 1 ;
return 0 ;
}
static int F_128 ( struct V_156 * V_156 , void * V_209 ,
const struct V_291 * V_292 )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
return F_50 ( V_2 , V_292 -> V_292 , V_292 -> V_3 ) ;
}
static int F_129 ( struct V_156 * V_156 , void * V_109 )
{
struct V_158 * V_144 = F_72 ( V_156 ) ;
F_130 ( V_156 , V_109 ) ;
F_84 ( V_144 -> V_174 , 0 , V_175 , V_293 ) ;
return 0 ;
}
static int F_131 ( struct V_156 * V_156 , void * V_209 ,
struct V_294 * V_295 )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
int V_53 ;
V_53 = F_4 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_109 -> type == V_149 )
V_53 = F_132 ( & V_109 -> V_168 , V_295 ) ;
else if ( V_109 -> type == V_151 )
V_53 = F_132 ( & V_109 -> V_171 , V_295 ) ;
return V_53 ;
}
static int F_133 ( struct V_156 * V_156 , void * V_209 ,
struct V_296 * V_297 )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
int V_53 ;
V_53 = F_4 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_109 -> type == V_149 )
V_53 = F_134 ( & V_109 -> V_168 , V_297 ) ;
else if ( V_109 -> type == V_151 )
V_53 = F_134 ( & V_109 -> V_171 , V_297 ) ;
return V_53 ;
}
static int F_135 ( struct V_156 * V_156 , void * V_209 , struct V_296 * V_297 )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
int V_53 ;
V_53 = F_4 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_109 -> type == V_149 )
V_53 = F_136 ( & V_109 -> V_168 , V_297 ) ;
else if ( V_109 -> type == V_151 )
V_53 = F_136 ( & V_109 -> V_171 , V_297 ) ;
return V_53 ;
}
static int F_137 ( struct V_156 * V_156 , void * V_209 , struct V_296 * V_297 )
{
struct V_108 * V_109 = V_209 ;
struct V_1 * V_2 = V_109 -> V_2 ;
int V_53 ;
V_53 = F_4 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_2 -> V_88 == 1 ) {
F_52 ( 1 , L_72 ) ;
F_56 ( V_2 ) ;
V_2 -> V_88 = 0 ;
}
if ( V_109 -> type == V_149 )
V_53 = F_138 ( & V_109 -> V_168 , V_297 , V_156 -> V_189 & V_190 ) ;
else if ( V_109 -> type == V_151 )
V_53 = F_138 ( & V_109 -> V_171 , V_297 , V_156 -> V_189 & V_190 ) ;
return V_53 ;
}
int F_139 ( struct V_1 * V_2 ,
struct V_129 * V_298 )
{
int V_299 = - V_55 ;
struct V_300 * V_301 ;
struct V_302 * V_303 ;
int V_31 , V_131 ;
F_52 ( 1 , L_73 ,
V_298 -> V_134 -> V_135 . V_304 ) ;
V_299 = F_54 ( V_2 -> V_44 ,
V_298 -> V_134 -> V_135 . V_304 , 5 ) ;
if ( V_299 != 0 ) {
F_5 ( V_21 L_74 ) ;
return V_299 ;
}
V_301 = V_298 -> V_134 ;
for ( V_31 = 0 ; V_31 < V_301 -> V_135 . V_305 ; V_31 ++ ) {
V_303 = & V_301 -> V_303 [ V_31 ] . V_135 ;
if ( ( ( V_303 -> V_306 & V_307 )
== V_308 ) &&
( ( V_303 -> V_309 & V_310 )
== V_311 ) ) {
T_7 V_238 = F_140 ( V_303 -> V_312 ) ;
V_2 -> V_48 = ( V_238 & 0x07ff ) *
( ( ( V_238 & 0x1800 ) >> 11 ) + 1 ) ;
V_2 -> V_57 = V_303 -> V_306 ;
F_52 ( 1 ,
L_75 ,
V_2 -> V_57 , V_2 -> V_48 ) ;
}
}
if ( ! ( V_2 -> V_57 ) ) {
F_5 ( V_21 L_76 ) ;
F_17 ( V_2 ) ;
return - V_22 ;
}
F_25 ( & V_2 -> V_178 ) ;
F_141 ( & V_2 -> V_34 ) ;
F_142 ( & V_2 -> V_29 . V_89 ) ;
F_142 ( & V_2 -> V_29 . V_313 ) ;
F_142 ( & V_2 -> V_93 . V_89 ) ;
F_142 ( & V_2 -> V_93 . V_313 ) ;
V_2 -> V_99 . V_314 = F_69 ;
V_2 -> V_99 . V_153 = ( unsigned long ) V_2 ;
F_143 ( & V_2 -> V_99 ) ;
V_2 -> V_103 . V_314 = F_70 ;
V_2 -> V_103 . V_153 = ( unsigned long ) V_2 ;
F_143 ( & V_2 -> V_103 ) ;
V_2 -> V_84 = V_315 ;
V_2 -> V_111 = V_316 ;
V_2 -> V_212 = V_2 -> V_84 * V_2 -> V_111 ;
V_2 -> V_211 = V_2 -> V_212 << 1 ;
V_2 -> V_83 = V_2 -> V_84 << 1 ;
V_2 -> V_91 = 720 ;
V_2 -> V_92 = 1 ;
V_2 -> V_254 = 0 ;
V_2 -> V_182 = 960 ;
V_2 -> V_186 = V_317 ;
F_110 ( V_2 , 0 ) ;
V_2 -> V_144 = F_144 () ;
if ( NULL == V_2 -> V_144 ) {
F_52 ( 1 , L_77 ) ;
return - V_55 ;
}
V_2 -> V_145 = F_144 () ;
if ( NULL == V_2 -> V_145 ) {
F_52 ( 1 , L_78 ) ;
V_131 = - V_55 ;
goto V_318;
}
* V_2 -> V_144 = V_319 ;
V_2 -> V_144 -> V_174 = & V_2 -> V_174 ;
V_2 -> V_144 -> V_163 = & V_2 -> V_163 ;
strcpy ( V_2 -> V_144 -> V_219 , L_79 ) ;
* V_2 -> V_145 = V_319 ;
V_2 -> V_145 -> V_174 = & V_2 -> V_174 ;
V_2 -> V_145 -> V_163 = & V_2 -> V_163 ;
strcpy ( V_2 -> V_145 -> V_219 , L_80 ) ;
F_145 ( V_2 -> V_144 , V_2 ) ;
V_299 = F_146 ( V_2 -> V_144 , V_160 , - 1 ) ;
if ( V_299 != 0 ) {
F_52 ( 1 , L_81 ,
V_299 ) ;
V_131 = - V_22 ;
goto V_320;
}
F_145 ( V_2 -> V_145 , V_2 ) ;
V_299 = F_146 ( V_2 -> V_145 , V_161 , - 1 ) ;
if ( V_299 != 0 ) {
F_52 ( 1 , L_82 ,
V_299 ) ;
V_131 = - V_22 ;
goto V_320;
}
F_52 ( 1 , L_83 , V_142 ) ;
return 0 ;
V_320:
F_147 ( V_2 -> V_145 ) ;
V_318:
F_147 ( V_2 -> V_144 ) ;
return V_131 ;
}

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
F_52 ( 1 , L_42 ) ;
F_50 ( V_128 , V_129 , 0x00 ) ;
F_50 ( V_128 , 0x106 , 0x00 ) ;
F_50 ( V_128 , 0x110 , 0x00 ) ;
F_50 ( V_128 , 0x111 , 0x00 ) ;
F_50 ( V_128 , 0x114 , 0xa0 ) ;
F_50 ( V_128 , 0x115 , 0x05 ) ;
F_50 ( V_128 , 0x112 , 0x00 ) ;
F_50 ( V_128 , 0x113 , 0x00 ) ;
F_50 ( V_128 , 0x116 , 0xf2 ) ;
F_50 ( V_128 , 0x117 , 0x00 ) ;
F_50 ( V_128 , V_130 , 0xb3 ) ;
return 0 ;
}
int F_53 ( struct V_1 * V_128 )
{
F_52 ( 1 , L_43 ) ;
F_50 ( V_128 , V_130 , 0x0 ) ;
return 0 ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_52 ( 1 , L_44 ) ;
F_50 ( V_2 , V_130 , 0x0 ) ;
F_55 ( 30 ) ;
F_50 ( V_2 , V_130 , 0xb3 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_131 = 0 ;
V_2 -> V_132 = V_133 ;
if ( V_2 -> V_19 == V_20 )
return - V_22 ;
else if ( V_131 ) {
V_2 -> V_19 = V_23 ;
F_52 ( 1 , L_45 , V_134 ) ;
return V_131 ;
}
return 0 ;
}
void F_57 ( struct V_1 * V_2 )
{
F_52 ( 1 , L_46 ) ;
F_58 ( & V_135 ) ;
if ( V_2 -> V_136 )
F_59 ( V_2 -> V_136 ) ;
if ( V_2 -> V_137 )
F_59 ( V_2 -> V_137 ) ;
F_60 ( & V_135 ) ;
}
static int F_61 ( struct V_108 * V_109 , unsigned int V_138 )
{
struct V_1 * V_2 = V_109 -> V_2 ;
if ( V_109 -> V_139 & V_138 )
return 1 ;
if ( V_2 -> V_139 & V_138 ) {
return 0 ;
}
V_109 -> V_139 |= V_138 ;
V_2 -> V_139 |= V_138 ;
F_52 ( 1 , L_47 , V_138 ) ;
return 1 ;
}
static int F_62 ( struct V_108 * V_109 , unsigned int V_138 )
{
return V_109 -> V_139 & V_138 ;
}
static int F_63 ( struct V_1 * V_2 , unsigned int V_138 )
{
return V_2 -> V_139 & V_138 ;
}
static void F_64 ( struct V_108 * V_109 , unsigned int V_140 )
{
struct V_1 * V_2 = V_109 -> V_2 ;
F_65 ( ( V_109 -> V_139 & V_140 ) != V_140 ) ;
V_109 -> V_139 &= ~ V_140 ;
V_2 -> V_139 &= ~ V_140 ;
F_52 ( 1 , L_48 , V_140 ) ;
}
static int F_66 ( struct V_108 * V_109 )
{
switch ( V_109 -> type ) {
case V_141 :
return V_142 ;
case V_143 :
return V_144 ;
default:
F_42 () ;
return 0 ;
}
}
static void F_67 ( unsigned long V_145 )
{
struct V_1 * V_2 = (struct V_1 * ) V_145 ;
struct V_26 * V_27 = & V_2 -> V_29 ;
struct V_64 * V_56 ;
unsigned char * V_146 ;
unsigned long V_30 = 0 ;
F_8 ( & V_2 -> V_34 , V_30 ) ;
V_56 = V_2 -> V_35 . V_56 ;
if ( V_56 != NULL ) {
V_146 = F_37 ( & V_56 -> V_65 ) ;
memset ( V_146 , 0x00 , V_56 -> V_65 . V_86 ) ;
F_26 ( V_2 , V_27 , V_56 ) ;
}
F_32 ( V_27 , & V_56 ) ;
if ( V_2 -> V_98 == 1 )
F_39 ( & V_2 -> V_99 , V_100 + ( V_101 / 10 ) ) ;
F_9 ( & V_2 -> V_34 , V_30 ) ;
}
static void F_68 ( unsigned long V_145 )
{
struct V_1 * V_2 = (struct V_1 * ) V_145 ;
struct V_26 * V_27 = & V_2 -> V_93 ;
struct V_64 * V_56 ;
unsigned char * V_147 ;
unsigned long V_30 = 0 ;
F_8 ( & V_2 -> V_34 , V_30 ) ;
V_56 = V_2 -> V_35 . V_72 ;
if ( V_56 != NULL ) {
V_147 = F_37 ( & V_56 -> V_65 ) ;
memset ( V_147 , 0x00 , V_56 -> V_65 . V_86 ) ;
F_30 ( V_2 , V_27 , V_56 ) ;
}
F_36 ( V_27 , & V_56 ) ;
if ( V_2 -> V_102 == 1 )
F_39 ( & V_2 -> V_103 , V_100 + ( V_101 / 10 ) ) ;
F_9 ( & V_2 -> V_34 , V_30 ) ;
}
static int F_69 ( struct V_148 * V_149 )
{
int V_131 = 0 ;
struct V_150 * V_136 = F_70 ( V_149 ) ;
struct V_1 * V_2 = F_71 ( V_149 ) ;
struct V_108 * V_109 ;
int type ;
switch ( V_136 -> V_151 ) {
case V_152 :
type = V_141 ;
break;
case V_153 :
type = V_143 ;
break;
default:
return - V_121 ;
}
V_109 = F_19 ( sizeof( struct V_108 ) , V_54 ) ;
if ( NULL == V_109 ) {
F_52 ( 1 , L_49 ) ;
return - V_55 ;
}
V_109 -> type = type ;
V_109 -> V_2 = V_2 ;
F_72 ( & V_109 -> V_109 , V_136 ) ;
V_149 -> V_154 = V_109 ;
if ( F_73 ( & V_2 -> V_155 ) ) {
F_17 ( V_109 ) ;
return - V_156 ;
}
if ( V_2 -> V_157 == 0 ) {
V_131 = F_74 ( V_2 -> V_44 , 0 , 5 ) ;
if ( V_131 < 0 ) {
F_60 ( & V_2 -> V_155 ) ;
F_5 ( V_21 L_50 ) ;
F_17 ( V_109 ) ;
return - V_158 ;
}
F_51 ( V_2 ) ;
F_54 ( V_2 ) ;
F_49 ( V_2 ) ;
V_2 -> V_132 = V_159 ;
V_2 -> V_19 |= V_160 ;
}
V_2 -> V_157 ++ ;
F_60 ( & V_2 -> V_155 ) ;
F_75 ( & V_109 -> V_161 , & V_162 ,
NULL , & V_2 -> V_34 ,
V_141 ,
V_163 ,
sizeof( struct V_64 ) , V_109 ,
& V_2 -> V_155 ) ;
F_75 ( & V_109 -> V_164 , & V_165 ,
NULL , & V_2 -> V_34 ,
V_143 ,
V_166 ,
sizeof( struct V_64 ) , V_109 ,
& V_2 -> V_155 ) ;
F_76 ( & V_109 -> V_109 ) ;
return V_131 ;
}
static int F_77 ( struct V_148 * V_149 )
{
int V_131 ;
struct V_108 * V_109 = V_149 -> V_154 ;
struct V_1 * V_2 = V_109 -> V_2 ;
F_78 ( & V_109 -> V_109 ) ;
F_79 ( & V_109 -> V_109 ) ;
F_58 ( & V_2 -> V_155 ) ;
if ( F_62 ( V_109 , V_142 ) ) {
V_2 -> V_98 = 0 ;
F_80 ( & V_2 -> V_99 ) ;
F_81 ( & V_109 -> V_161 ) ;
F_64 ( V_109 , V_142 ) ;
}
if ( F_62 ( V_109 , V_144 ) ) {
V_2 -> V_102 = 0 ;
F_80 ( & V_2 -> V_103 ) ;
F_81 ( & V_109 -> V_164 ) ;
F_64 ( V_109 , V_144 ) ;
}
if ( V_2 -> V_157 == 1 && F_82 ( F_70 ( V_149 ) ) ) {
F_53 ( V_2 ) ;
F_11 ( V_2 ) ;
F_83 ( & V_2 -> V_167 , 0 , V_168 , V_169 , 0 ) ;
V_2 -> V_170 = 0 ;
V_131 = F_74 ( V_2 -> V_44 , 0 , 0 ) ;
if ( V_131 < 0 )
F_5 ( V_21 L_51 ) ;
}
F_60 ( & V_2 -> V_155 ) ;
F_84 ( & V_109 -> V_161 ) ;
F_84 ( & V_109 -> V_164 ) ;
F_17 ( V_109 ) ;
V_2 -> V_157 -- ;
F_85 ( & V_2 -> V_171 , 1 ) ;
return 0 ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_172 V_173 = {
. V_174 = V_2 -> V_175 ,
. type = V_176 ,
} ;
if ( V_2 -> V_170 )
return;
V_2 -> V_170 = 1 ;
F_1 ( V_2 , 1 ) ;
F_83 ( & V_2 -> V_167 , 0 , V_177 , V_178 , V_2 -> V_179 ) ;
F_83 ( & V_2 -> V_167 , 0 , V_180 , V_181 , & V_173 ) ;
F_1 ( V_2 , 0 ) ;
}
static T_1 F_87 ( struct V_148 * V_149 , char T_2 * V_56 ,
T_3 V_107 , T_4 * V_85 )
{
struct V_108 * V_109 = V_149 -> V_154 ;
struct V_1 * V_2 = V_109 -> V_2 ;
int V_53 ;
V_53 = F_4 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( F_73 ( & V_2 -> V_155 ) )
return - V_156 ;
F_86 ( V_2 ) ;
F_60 ( & V_2 -> V_155 ) ;
if ( V_109 -> type == V_141 ) {
if ( F_63 ( V_2 , V_142 ) )
return - V_158 ;
return F_88 ( & V_109 -> V_161 , V_56 , V_107 , V_85 , 0 ,
V_149 -> V_182 & V_183 ) ;
}
if ( V_109 -> type == V_143 ) {
if ( ! F_61 ( V_109 , V_144 ) )
return - V_158 ;
if ( V_2 -> V_102 == 0 ) {
V_2 -> V_102 = 1 ;
F_39 ( & V_2 -> V_103 , V_100 + ( V_101 / 10 ) ) ;
}
return F_88 ( & V_109 -> V_164 , V_56 , V_107 , V_85 , 0 ,
V_149 -> V_182 & V_183 ) ;
}
return 0 ;
}
static unsigned int F_89 ( struct V_148 * V_149 , T_5 * V_184 )
{
struct V_108 * V_109 = V_149 -> V_154 ;
struct V_1 * V_2 = V_109 -> V_2 ;
unsigned long V_185 = F_90 ( V_184 ) ;
unsigned int V_186 ;
if ( F_4 ( V_2 ) < 0 )
return V_187 ;
V_186 = F_91 ( V_149 , V_184 ) ;
if ( ! ( V_185 & ( V_188 | V_189 ) ) )
return V_186 ;
if ( F_73 ( & V_2 -> V_155 ) )
return - V_156 ;
F_86 ( V_2 ) ;
F_60 ( & V_2 -> V_155 ) ;
if ( V_109 -> type == V_141 ) {
if ( ! F_61 ( V_109 , V_142 ) )
return V_187 ;
return V_186 | F_92 ( V_149 , & V_109 -> V_161 , V_184 ) ;
}
if ( V_109 -> type == V_143 ) {
if ( ! F_61 ( V_109 , V_144 ) )
return V_187 ;
return V_186 | F_92 ( V_149 , & V_109 -> V_164 , V_184 ) ;
}
return V_187 ;
}
static int F_93 ( struct V_148 * V_149 , struct V_190 * V_191 )
{
struct V_108 * V_109 = V_149 -> V_154 ;
struct V_1 * V_2 = V_109 -> V_2 ;
int V_53 ;
V_53 = F_4 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_109 -> type == V_141 )
V_53 = F_94 ( & V_109 -> V_161 , V_191 ) ;
else if ( V_109 -> type == V_143 )
V_53 = F_94 ( & V_109 -> V_164 , V_191 ) ;
return V_53 ;
}
static int F_95 ( struct V_1 * V_2 , unsigned int V_192 ,
struct V_193 * V_194 )
{
int V_131 ;
int V_84 = V_194 -> V_195 . V_196 . V_84 ;
int V_111 = V_194 -> V_195 . V_196 . V_111 ;
if ( V_194 -> V_195 . V_196 . V_197 != V_198 )
return - V_121 ;
if ( V_84 != 720 )
V_84 = 720 ;
if ( V_111 != 480 )
V_111 = 480 ;
V_194 -> V_195 . V_196 . V_84 = V_84 ;
V_194 -> V_195 . V_196 . V_111 = V_111 ;
V_194 -> V_195 . V_196 . V_197 = V_198 ;
V_194 -> V_195 . V_196 . V_83 = V_84 * 2 ;
V_194 -> V_195 . V_196 . V_199 = V_84 * V_111 * 2 ;
V_194 -> V_195 . V_196 . V_200 = V_201 ;
V_194 -> V_195 . V_196 . V_117 = V_163 ;
V_194 -> V_195 . V_196 . V_202 = 0 ;
if ( V_192 == V_203 )
return 0 ;
V_2 -> V_84 = V_84 ;
V_2 -> V_111 = V_111 ;
V_2 -> V_204 = V_84 * V_111 * 2 ;
V_2 -> V_205 = V_84 * V_111 ;
V_2 -> V_83 = V_84 * 2 ;
if ( V_2 -> V_132 == V_206 ) {
F_52 ( 1 , L_52 ) ;
V_131 = F_56 ( V_2 ) ;
if ( V_131 != 0 ) {
F_52 ( 1 , L_53 ) ;
return V_131 ;
}
}
V_131 = F_74 ( V_2 -> V_44 , 0 , 5 ) ;
if ( V_131 < 0 ) {
F_5 ( V_21 L_54 ) ;
return - V_158 ;
}
F_51 ( V_2 ) ;
return 0 ;
}
static int F_96 ( struct V_148 * V_148 , void * V_202 ,
struct V_207 * V_208 )
{
struct V_150 * V_136 = F_70 ( V_148 ) ;
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
F_97 ( V_208 -> V_209 , L_55 , sizeof( V_208 -> V_209 ) ) ;
F_97 ( V_208 -> V_210 , V_2 -> V_211 . V_212 , sizeof( V_208 -> V_210 ) ) ;
F_98 ( V_2 -> V_44 , V_208 -> V_213 , sizeof( V_208 -> V_213 ) ) ;
V_208 -> V_214 = V_215 |
V_216 |
V_217 |
V_218 ;
if ( V_136 -> V_151 == V_152 )
V_208 -> V_214 |= V_219 ;
else
V_208 -> V_214 |= V_220 ;
V_208 -> V_221 = V_208 -> V_214 | V_222 |
V_220 | V_219 ;
return 0 ;
}
static int F_99 ( struct V_148 * V_148 , void * V_202 ,
struct V_223 * V_173 )
{
if ( V_173 -> V_224 )
return - V_121 ;
V_173 -> type = V_141 ;
strcpy ( V_173 -> V_225 , L_56 ) ;
V_173 -> V_30 = 0 ;
V_173 -> V_197 = V_198 ;
return 0 ;
}
static int F_100 ( struct V_148 * V_148 , void * V_202 ,
struct V_193 * V_173 )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
V_173 -> V_195 . V_196 . V_84 = V_2 -> V_84 ;
V_173 -> V_195 . V_196 . V_111 = V_2 -> V_111 ;
V_173 -> V_195 . V_196 . V_197 = V_198 ;
V_173 -> V_195 . V_196 . V_83 = V_2 -> V_83 ;
V_173 -> V_195 . V_196 . V_199 = V_2 -> V_204 ;
V_173 -> V_195 . V_196 . V_200 = V_201 ;
V_173 -> V_195 . V_196 . V_117 = V_163 ;
V_173 -> V_195 . V_196 . V_202 = 0 ;
return 0 ;
}
static int F_101 ( struct V_148 * V_148 , void * V_202 ,
struct V_193 * V_173 )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
return F_95 ( V_2 , V_203 , V_173 ) ;
}
static int F_102 ( struct V_148 * V_148 , void * V_202 ,
struct V_193 * V_173 )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
int V_53 ;
V_53 = F_4 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( F_103 ( & V_109 -> V_161 ) ) {
F_5 ( V_21 L_57 , V_134 ) ;
V_53 = - V_158 ;
goto V_226;
}
V_53 = F_95 ( V_2 , V_227 , V_173 ) ;
V_226:
return V_53 ;
}
static int F_104 ( struct V_148 * V_148 , void * V_202 , T_6 V_228 )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
V_2 -> V_179 = V_228 ;
F_86 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_83 ( & V_2 -> V_167 , 0 , V_177 , V_178 , V_228 ) ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int F_105 ( struct V_148 * V_148 , void * V_202 , T_6 * V_228 )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
* V_228 = V_2 -> V_179 ;
return 0 ;
}
static int F_106 ( struct V_148 * V_148 , void * V_202 ,
struct V_229 * V_230 )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
unsigned int V_231 ;
static const char * V_232 [] = {
[ V_233 ] = L_58 ,
[ V_234 ] = L_59 ,
[ V_235 ] = L_60 ,
[ V_236 ] = L_61 ,
[ V_237 ] = L_62 ,
[ V_238 ] = L_63 ,
[ V_239 ] = L_64
} ;
V_231 = V_230 -> V_224 ;
if ( V_231 >= V_240 )
return - V_121 ;
if ( F_107 ( V_231 ) . type == 0 )
return - V_121 ;
V_230 -> V_224 = V_231 ;
strcpy ( V_230 -> V_212 , V_232 [ F_107 ( V_231 ) . type ] ) ;
if ( ( F_107 ( V_231 ) . type == V_237 ) ||
( F_107 ( V_231 ) . type == V_236 ) ) {
V_230 -> type |= V_241 ;
V_230 -> V_242 = 1 ;
} else {
V_230 -> type |= V_243 ;
V_230 -> V_242 = 2 ;
}
V_230 -> V_179 = V_2 -> V_136 -> V_244 ;
return 0 ;
}
static int F_108 ( struct V_148 * V_148 , void * V_202 , unsigned int * V_31 )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
* V_31 = V_2 -> V_245 ;
return 0 ;
}
static void F_109 ( struct V_1 * V_2 , int V_224 )
{
int V_31 ;
switch ( F_107 ( V_224 ) . type ) {
case V_235 :
V_2 -> V_246 = V_235 ;
V_2 -> V_247 = 1 ;
break;
case V_234 :
V_2 -> V_246 = V_234 ;
V_2 -> V_247 = 1 ;
break;
case V_237 :
V_2 -> V_246 = V_237 ;
V_2 -> V_247 = 0 ;
break;
default:
F_52 ( 1 , L_65 ,
F_107 ( V_224 ) . type ) ;
break;
}
F_83 ( & V_2 -> V_167 , 0 , V_177 , V_248 ,
F_107 ( V_224 ) . V_249 , 0 , 0 ) ;
for ( V_31 = 0 ; V_31 < V_240 ; V_31 ++ ) {
int V_250 = 0 ;
if ( F_107 ( V_31 ) . V_251 == NULL )
continue;
if ( V_31 == V_224 )
V_250 = 1 ;
else
V_250 = 0 ;
if ( V_250 ) {
( F_107 ( V_31 ) . V_251 ) ( V_2 , V_250 ) ;
} else {
if ( ( F_107 ( V_31 ) . V_251 ) !=
( ( F_107 ( V_224 ) . V_251 ) ) ) {
( F_107 ( V_31 ) . V_251 ) ( V_2 , V_250 ) ;
}
}
}
F_83 ( & V_2 -> V_167 , 0 , V_252 , V_248 ,
F_107 ( V_224 ) . V_253 , 0 , 0 ) ;
}
static int F_110 ( struct V_148 * V_148 , void * V_202 , unsigned int V_224 )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
F_52 ( 1 , L_66 , V_134 ,
V_224 ) ;
if ( V_224 >= V_240 )
return - V_121 ;
if ( F_107 ( V_224 ) . type == 0 )
return - V_121 ;
V_2 -> V_245 = V_224 ;
F_109 ( V_2 , V_224 ) ;
return 0 ;
}
static int F_111 ( struct V_148 * V_148 , void * V_202 , struct V_254 * V_255 )
{
if ( V_255 -> V_224 > 1 )
return - V_121 ;
if ( V_255 -> V_224 == 0 )
strcpy ( V_255 -> V_212 , L_62 ) ;
else
strcpy ( V_255 -> V_212 , L_67 ) ;
V_255 -> V_256 = V_257 ;
return 0 ;
}
static int F_112 ( struct V_148 * V_148 , void * V_202 , struct V_254 * V_255 )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
V_255 -> V_224 = V_2 -> V_247 ;
if ( V_255 -> V_224 == 0 )
strcpy ( V_255 -> V_212 , L_62 ) ;
else
strcpy ( V_255 -> V_212 , L_67 ) ;
V_255 -> V_256 = V_257 ;
return 0 ;
}
static int F_113 ( struct V_148 * V_148 , void * V_202 , const struct V_254 * V_255 )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
if ( V_255 -> V_224 != V_2 -> V_247 )
return - V_121 ;
return 0 ;
}
static int F_114 ( struct V_148 * V_148 , void * V_202 , struct V_258 * V_259 )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
if ( V_259 -> V_224 != 0 )
return - V_121 ;
strcpy ( V_259 -> V_212 , L_68 ) ;
F_86 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_83 ( & V_2 -> V_167 , 0 , V_180 , V_260 , V_259 ) ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int F_115 ( struct V_148 * V_148 , void * V_202 ,
const struct V_258 * V_259 )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
if ( V_259 -> V_224 != 0 )
return - V_121 ;
F_86 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_83 ( & V_2 -> V_167 , 0 , V_180 , V_261 , V_259 ) ;
F_1 ( V_2 , 0 ) ;
F_52 ( 1 , L_69 , V_259 -> signal ,
V_259 -> V_262 ) ;
return 0 ;
}
static int F_116 ( struct V_148 * V_148 , void * V_202 ,
struct V_172 * V_263 )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
if ( V_263 -> V_180 != 0 )
return - V_121 ;
V_263 -> V_174 = V_2 -> V_175 ;
return 0 ;
}
static int F_117 ( struct V_148 * V_148 , void * V_202 ,
const struct V_172 * V_263 )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
struct V_172 V_264 = * V_263 ;
if ( V_263 -> V_180 != 0 )
return - V_121 ;
F_86 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_83 ( & V_2 -> V_167 , 0 , V_180 , V_181 , V_263 ) ;
F_83 ( & V_2 -> V_167 , 0 , V_180 , V_265 , & V_264 ) ;
V_2 -> V_175 = V_264 . V_174 ;
F_1 ( V_2 , 0 ) ;
F_54 ( V_2 ) ;
return 0 ;
}
static int F_118 ( struct V_148 * V_148 , void * V_202 ,
struct V_193 * V_194 )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
V_194 -> V_195 . V_266 . V_267 = V_2 -> V_91 ;
V_194 -> V_195 . V_266 . V_268 = V_269 ;
V_194 -> V_195 . V_266 . V_61 = 0 ;
V_194 -> V_195 . V_266 . V_30 = 0 ;
V_194 -> V_195 . V_266 . V_270 = 6750000 * 4 / 2 ;
V_194 -> V_195 . V_266 . V_107 [ 0 ] = V_2 -> V_92 ;
V_194 -> V_195 . V_266 . V_107 [ 1 ] = V_2 -> V_92 ;
V_194 -> V_195 . V_266 . V_271 [ 0 ] = 21 ;
V_194 -> V_195 . V_266 . V_271 [ 1 ] = 284 ;
memset ( V_194 -> V_195 . V_266 . V_272 , 0 , sizeof( V_194 -> V_195 . V_266 . V_272 ) ) ;
return 0 ;
}
static int F_119 ( struct V_148 * V_148 , void * V_202 ,
struct V_273 * V_274 )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
if ( V_274 -> type != V_141 )
return - V_121 ;
V_274 -> V_275 . V_276 = 0 ;
V_274 -> V_275 . V_277 = 0 ;
V_274 -> V_275 . V_84 = V_2 -> V_84 ;
V_274 -> V_275 . V_111 = V_2 -> V_111 ;
V_274 -> V_278 = V_274 -> V_275 ;
V_274 -> V_279 . V_280 = 54 ;
V_274 -> V_279 . V_281 = 59 ;
return 0 ;
}
static int F_120 ( struct V_148 * V_148 , void * V_202 ,
enum V_282 type )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
int V_53 = - V_121 ;
V_53 = F_4 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( F_121 ( type != V_109 -> type ) )
return - V_121 ;
F_52 ( 1 , L_70 ,
V_109 , type , V_109 -> V_139 , V_2 -> V_139 ) ;
if ( F_121 ( ! F_61 ( V_109 , F_66 ( V_109 ) ) ) )
return - V_158 ;
F_86 ( V_2 ) ;
if ( type == V_141 ) {
F_51 ( V_2 ) ;
F_83 ( & V_2 -> V_167 , 0 , V_177 , V_283 , 1 ) ;
}
if ( V_109 -> type == V_141 ) {
V_53 = F_122 ( & V_109 -> V_161 ) ;
V_2 -> V_98 = 1 ;
F_39 ( & V_2 -> V_99 , V_100 + ( V_101 / 10 ) ) ;
} else if ( V_109 -> type == V_143 ) {
V_53 = F_122 ( & V_109 -> V_164 ) ;
V_2 -> V_102 = 1 ;
F_39 ( & V_2 -> V_103 , V_100 + ( V_101 / 10 ) ) ;
}
return V_53 ;
}
static int F_123 ( struct V_148 * V_148 , void * V_202 ,
enum V_282 type )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
int V_53 ;
int V_31 ;
V_53 = F_4 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_109 -> type != V_141 &&
V_109 -> type != V_143 )
return - V_121 ;
if ( type != V_109 -> type )
return - V_121 ;
F_52 ( 1 , L_71 ,
V_109 , type , V_109 -> V_139 , V_2 -> V_139 ) ;
if ( V_109 -> type == V_141 ) {
V_2 -> V_98 = 0 ;
F_80 ( & V_2 -> V_99 ) ;
F_83 ( & V_2 -> V_167 , 0 , V_177 , V_283 , 0 ) ;
V_53 = F_56 ( V_2 ) ;
if ( V_53 != 0 )
return V_53 ;
for ( V_31 = 0 ; V_31 < V_240 ; V_31 ++ ) {
if ( F_107 ( V_31 ) . V_251 == NULL )
continue;
( F_107 ( V_31 ) . V_251 ) ( V_2 , 0 ) ;
}
if ( F_62 ( V_109 , V_142 ) ) {
F_124 ( & V_109 -> V_161 ) ;
F_64 ( V_109 , V_142 ) ;
}
} else if ( V_109 -> type == V_143 ) {
V_2 -> V_102 = 0 ;
F_80 ( & V_2 -> V_103 ) ;
if ( F_62 ( V_109 , V_144 ) ) {
F_124 ( & V_109 -> V_164 ) ;
F_64 ( V_109 , V_144 ) ;
}
}
return 0 ;
}
static int F_125 ( struct V_148 * V_148 , void * V_202 ,
struct V_284 * V_285 )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
V_285 -> V_3 = F_126 ( V_2 , V_285 -> V_285 ) ;
V_285 -> V_86 = 1 ;
return 0 ;
}
static int F_127 ( struct V_148 * V_148 , void * V_202 ,
const struct V_284 * V_285 )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
return F_50 ( V_2 , V_285 -> V_285 , V_285 -> V_3 ) ;
}
static int F_128 ( struct V_148 * V_148 , void * V_109 )
{
struct V_150 * V_136 = F_70 ( V_148 ) ;
F_129 ( V_148 , V_109 ) ;
F_83 ( V_136 -> V_167 , 0 , V_168 , V_286 ) ;
return 0 ;
}
static int F_130 ( struct V_148 * V_148 , void * V_202 ,
struct V_287 * V_288 )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
int V_53 ;
V_53 = F_4 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_109 -> type == V_141 )
V_53 = F_131 ( & V_109 -> V_161 , V_288 ) ;
else if ( V_109 -> type == V_143 )
V_53 = F_131 ( & V_109 -> V_164 , V_288 ) ;
return V_53 ;
}
static int F_132 ( struct V_148 * V_148 , void * V_202 ,
struct V_289 * V_290 )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
int V_53 ;
V_53 = F_4 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_109 -> type == V_141 )
V_53 = F_133 ( & V_109 -> V_161 , V_290 ) ;
else if ( V_109 -> type == V_143 )
V_53 = F_133 ( & V_109 -> V_164 , V_290 ) ;
return V_53 ;
}
static int F_134 ( struct V_148 * V_148 , void * V_202 , struct V_289 * V_290 )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
int V_53 ;
V_53 = F_4 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_109 -> type == V_141 )
V_53 = F_135 ( & V_109 -> V_161 , V_290 ) ;
else if ( V_109 -> type == V_143 )
V_53 = F_135 ( & V_109 -> V_164 , V_290 ) ;
return V_53 ;
}
static int F_136 ( struct V_148 * V_148 , void * V_202 , struct V_289 * V_290 )
{
struct V_108 * V_109 = V_202 ;
struct V_1 * V_2 = V_109 -> V_2 ;
int V_53 ;
V_53 = F_4 ( V_2 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( V_2 -> V_88 == 1 ) {
F_52 ( 1 , L_72 ) ;
F_54 ( V_2 ) ;
V_2 -> V_88 = 0 ;
}
if ( V_109 -> type == V_141 )
V_53 = F_137 ( & V_109 -> V_161 , V_290 , V_148 -> V_182 & V_183 ) ;
else if ( V_109 -> type == V_143 )
V_53 = F_137 ( & V_109 -> V_164 , V_290 , V_148 -> V_182 & V_183 ) ;
return V_53 ;
}
int F_138 ( struct V_1 * V_2 ,
struct V_291 * V_292 )
{
int V_293 = - V_55 ;
struct V_294 * V_295 ;
struct V_296 * V_297 ;
int V_31 , V_131 ;
F_52 ( 1 , L_73 ) ;
V_293 = F_74 ( V_2 -> V_44 ,
V_292 -> V_298 -> V_299 . V_300 , 5 ) ;
if ( V_293 != 0 ) {
F_5 ( V_21 L_74 ) ;
return V_293 ;
}
V_295 = V_292 -> V_298 ;
for ( V_31 = 0 ; V_31 < V_295 -> V_299 . V_301 ; V_31 ++ ) {
V_297 = & V_295 -> V_297 [ V_31 ] . V_299 ;
if ( ( ( V_297 -> V_302 & V_303 )
== V_304 ) &&
( ( V_297 -> V_305 & V_306 )
== V_307 ) ) {
T_7 V_231 = F_139 ( V_297 -> V_308 ) ;
V_2 -> V_48 = ( V_231 & 0x07ff ) *
( ( ( V_231 & 0x1800 ) >> 11 ) + 1 ) ;
V_2 -> V_57 = V_297 -> V_302 ;
}
}
if ( ! ( V_2 -> V_57 ) ) {
F_5 ( V_21 L_75 ) ;
F_17 ( V_2 ) ;
return - V_22 ;
}
F_25 ( & V_2 -> V_171 ) ;
F_140 ( & V_2 -> V_34 ) ;
F_141 ( & V_2 -> V_29 . V_89 ) ;
F_141 ( & V_2 -> V_29 . V_309 ) ;
F_141 ( & V_2 -> V_93 . V_89 ) ;
F_141 ( & V_2 -> V_93 . V_309 ) ;
V_2 -> V_99 . V_310 = F_67 ;
V_2 -> V_99 . V_145 = ( unsigned long ) V_2 ;
F_142 ( & V_2 -> V_99 ) ;
V_2 -> V_103 . V_310 = F_68 ;
V_2 -> V_103 . V_145 = ( unsigned long ) V_2 ;
F_142 ( & V_2 -> V_103 ) ;
V_2 -> V_84 = V_311 ;
V_2 -> V_111 = V_312 ;
V_2 -> V_205 = V_2 -> V_84 * V_2 -> V_111 ;
V_2 -> V_204 = V_2 -> V_205 << 1 ;
V_2 -> V_83 = V_2 -> V_84 << 1 ;
V_2 -> V_91 = 720 ;
V_2 -> V_92 = 1 ;
V_2 -> V_247 = 0 ;
V_2 -> V_175 = 960 ;
V_2 -> V_179 = V_313 ;
F_109 ( V_2 , 0 ) ;
V_2 -> V_136 = F_143 () ;
if ( NULL == V_2 -> V_136 ) {
F_52 ( 1 , L_76 ) ;
return - V_55 ;
}
V_2 -> V_137 = F_143 () ;
if ( NULL == V_2 -> V_137 ) {
F_52 ( 1 , L_77 ) ;
V_131 = - V_55 ;
goto V_314;
}
* V_2 -> V_136 = V_315 ;
V_2 -> V_136 -> V_167 = & V_2 -> V_167 ;
V_2 -> V_136 -> V_155 = & V_2 -> V_155 ;
F_144 ( V_316 , & V_2 -> V_136 -> V_30 ) ;
strcpy ( V_2 -> V_136 -> V_212 , L_78 ) ;
* V_2 -> V_137 = V_315 ;
V_2 -> V_137 -> V_167 = & V_2 -> V_167 ;
V_2 -> V_137 -> V_155 = & V_2 -> V_155 ;
F_144 ( V_316 , & V_2 -> V_137 -> V_30 ) ;
strcpy ( V_2 -> V_137 -> V_212 , L_79 ) ;
F_145 ( V_2 -> V_136 , V_2 ) ;
V_293 = F_146 ( V_2 -> V_136 , V_152 , - 1 ) ;
if ( V_293 != 0 ) {
F_52 ( 1 , L_80 ,
V_293 ) ;
V_131 = - V_22 ;
goto V_317;
}
F_145 ( V_2 -> V_137 , V_2 ) ;
V_293 = F_146 ( V_2 -> V_137 , V_153 , - 1 ) ;
if ( V_293 != 0 ) {
F_52 ( 1 , L_81 ,
V_293 ) ;
V_131 = - V_22 ;
goto V_317;
}
F_52 ( 1 , L_82 , V_134 ) ;
return 0 ;
V_317:
F_147 ( V_2 -> V_137 ) ;
V_314:
F_147 ( V_2 -> V_136 ) ;
return V_131 ;
}

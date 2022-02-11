static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
if ( ! V_6 )
return;
V_2 -> V_4 = F_3 ( V_2 ) ;
if ( ( V_2 -> V_4 & V_8 ) && ( ( V_3 & V_8 ) == 0 ) )
F_4 ( & V_2 -> V_7 . V_9 ) ;
if ( ( V_3 & V_8 ) && ( ( V_2 -> V_4 & V_8 ) == 0 ) )
if ( V_2 -> V_7 . V_10 & V_11 )
F_5 ( V_6 ) ;
F_6 ( V_6 ) ;
}
static int T_1 F_7 ( struct V_12 * V_13 , char * * V_14 )
{
char * V_15 ;
unsigned int V_16 ;
F_8 ( L_1 , V_13 , V_14 ) ;
if ( ( V_14 [ 0 ] == NULL ) || ( * V_14 [ 0 ] == 0 ) )
return 0 ;
for ( V_15 = V_14 [ 0 ] , V_16 = 0 ; ( * V_15 != 0 ) && ( V_16 < 25 ) ; V_15 ++ , V_16 ++ )
* V_15 = tolower ( * V_15 ) ;
for ( V_16 = 0 ; V_16 < F_9 ( V_17 ) ; V_16 ++ )
if ( strcmp ( V_17 [ V_16 ] . V_18 , V_14 [ 0 ] ) == 0 )
break;
if ( V_16 == F_9 ( V_17 ) ) {
F_10 ( L_2 , V_14 [ 0 ] ) ;
return 0 ;
}
V_13 -> V_19 = V_17 [ V_16 ] . type ;
V_16 = 1 ;
if ( ( V_14 [ V_16 ] != NULL ) && ( * V_14 [ V_16 ] != 0 ) )
V_13 -> V_20 = F_11 ( V_14 [ V_16 ] , NULL , 0 ) ;
V_16 ++ ;
if ( V_13 -> V_19 == V_21 ) {
if ( ( V_14 [ V_16 ] != NULL ) && ( * V_14 [ V_16 ] != 0 ) )
V_13 -> V_22 = F_11 ( V_14 [ V_16 ] , NULL , 0 ) ;
V_16 ++ ;
}
if ( ( V_14 [ V_16 ] != NULL ) && ( * V_14 [ V_16 ] != 0 ) )
V_13 -> V_23 = F_11 ( V_14 [ V_16 ] , NULL , 0 ) ;
return 1 ;
}
static struct V_24 * F_12 ( void )
{
struct V_24 * V_25 ;
V_25 = F_13 ( sizeof( struct V_24 ) , V_26 ) ;
if ( ! V_25 ) {
F_10 ( L_3 ,
sizeof( struct V_24 ) ) ;
return NULL ;
}
V_25 -> V_27 = V_28 ;
return V_25 ;
}
static int F_14 ( struct V_29 * V_7 , struct V_5 * V_6 )
{
struct V_1 * V_2 = F_15 ( V_7 , struct V_1 , V_7 ) ;
if ( ! V_2 -> V_30 . V_31 ) {
V_2 -> V_30 . V_31 = F_16 ( V_32 , V_26 ) ;
if ( ! V_2 -> V_30 . V_31 )
return - V_33 ;
V_2 -> V_30 . V_34 = V_2 -> V_30 . V_31 ;
V_2 -> V_30 . V_35 = V_2 -> V_30 . V_31 ;
}
F_17 ( V_2 , V_6 -> V_36 ) ;
V_2 -> V_4 = F_3 ( V_2 ) ;
F_18 ( V_2 , 1 , 1 ) ;
F_19 ( V_2 , 1 , 1 ) ;
F_20 ( V_2 , 1 , 0 ) ;
return 0 ;
}
static int F_21 ( struct V_5 * V_6 , struct V_37 * V_38 )
{
struct V_1 * V_2 ;
struct V_24 * V_25 ;
unsigned int V_39 , V_40 , V_41 ;
int V_42 ;
F_8 ( L_4 , V_6 , V_38 , V_6 -> V_18 ) ;
V_39 = V_6 -> V_43 ;
V_40 = F_22 ( V_39 ) ;
if ( V_40 >= V_44 )
return - V_45 ;
V_25 = V_46 [ V_40 ] ;
if ( V_25 == NULL )
return - V_45 ;
V_39 = F_23 ( V_39 ) ;
for ( V_42 = - 1 , V_41 = 0 ; V_41 < V_47 ; V_41 ++ ) {
if ( V_25 -> V_48 [ V_41 ] == NULL )
break;
if ( V_39 < V_25 -> V_48 [ V_41 ] -> V_49 ) {
V_42 = V_39 ;
break;
}
V_39 -= V_25 -> V_48 [ V_41 ] -> V_49 ;
}
if ( V_42 < 0 )
return - V_45 ;
V_2 = V_25 -> V_48 [ V_41 ] -> V_50 [ V_42 ] ;
if ( V_2 == NULL )
return - V_45 ;
V_6 -> V_51 = V_2 ;
return F_24 ( & V_2 -> V_7 , V_6 , V_38 ) ;
}
static int F_25 ( struct V_29 * V_7 )
{
struct V_1 * V_2 = F_15 ( V_7 , struct V_1 , V_7 ) ;
return ( V_2 -> V_4 & V_8 ) ? 1 : 0 ;
}
static void F_26 ( struct V_29 * V_7 , int V_52 )
{
struct V_1 * V_2 = F_15 ( V_7 , struct V_1 , V_7 ) ;
F_18 ( V_2 , V_52 , V_52 ) ;
}
static void F_27 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_8 ( L_5 , V_6 ) ;
V_2 = V_6 -> V_51 ;
if ( V_2 == NULL )
return;
F_28 ( V_2 ) ;
F_29 ( V_6 ) ;
}
static void F_30 ( struct V_5 * V_6 , int V_53 )
{
struct V_1 * V_2 ;
unsigned long V_54 ;
F_8 ( L_6 , V_6 , V_53 ) ;
V_2 = V_6 -> V_51 ;
if ( V_2 == NULL )
return;
if ( V_53 == 0 )
V_53 = V_55 ;
V_54 = V_56 + V_53 ;
while ( F_31 ( V_2 ) ) {
if ( F_32 ( V_57 ) )
break;
F_33 ( 20 ) ;
if ( F_34 ( V_56 , V_54 ) )
break;
}
}
static void F_35 ( struct V_29 * V_7 )
{
struct V_1 * V_2 = F_15 ( V_7 , struct V_1 , V_7 ) ;
F_36 ( V_2 ) ;
F_19 ( V_2 , 0 , 0 ) ;
F_28 ( V_2 ) ;
V_2 -> V_58 = 0 ;
if ( V_2 -> V_30 . V_31 != NULL ) {
F_37 ( V_2 -> V_30 . V_31 ) ;
V_2 -> V_30 . V_31 = NULL ;
V_2 -> V_30 . V_34 = NULL ;
V_2 -> V_30 . V_35 = NULL ;
}
}
static void F_38 ( struct V_5 * V_6 , struct V_37 * V_38 )
{
struct V_1 * V_2 ;
F_8 ( L_7 , V_6 , V_38 ) ;
V_2 = V_6 -> V_51 ;
if( V_2 == NULL )
return;
F_39 ( & V_2 -> V_7 , V_6 , V_38 ) ;
}
static int F_40 ( struct V_5 * V_6 , const unsigned char * V_31 , int V_59 )
{
struct V_1 * V_2 ;
unsigned int V_60 , V_61 ;
unsigned char * V_62 ;
char * V_34 , * V_35 ;
F_8 ( L_8 , V_6 , V_31 , V_59 ) ;
V_2 = V_6 -> V_51 ;
if ( V_2 == NULL )
return 0 ;
if ( V_2 -> V_30 . V_31 == NULL )
return 0 ;
V_62 = ( unsigned char * ) V_31 ;
V_34 = V_2 -> V_30 . V_34 ;
V_35 = V_2 -> V_30 . V_35 ;
if ( V_34 >= V_35 ) {
V_60 = V_32 - ( V_34 - V_35 ) - 1 ;
V_61 = V_32 - ( V_34 - V_2 -> V_30 . V_31 ) ;
} else {
V_60 = V_35 - V_34 - 1 ;
V_61 = V_60 ;
}
V_60 = F_41 ( V_60 , ( unsigned int ) V_59 ) ;
V_59 = 0 ;
while ( V_60 > 0 ) {
V_61 = F_41 ( V_60 , V_61 ) ;
memcpy ( V_34 , V_62 , V_61 ) ;
V_60 -= V_61 ;
V_62 += V_61 ;
V_59 += V_61 ;
V_34 += V_61 ;
if ( V_34 >= ( V_2 -> V_30 . V_31 + V_32 ) ) {
V_34 = V_2 -> V_30 . V_31 ;
V_61 = V_35 - V_34 ;
}
}
V_2 -> V_30 . V_34 = V_34 ;
F_42 ( V_63 , & V_2 -> V_58 ) ;
F_20 ( V_2 , - 1 , 1 ) ;
return V_59 ;
}
static int F_43 ( struct V_5 * V_6 , unsigned char V_64 )
{
struct V_1 * V_2 ;
unsigned int V_60 ;
char * V_34 , * V_35 ;
F_8 ( L_9 , V_6 , V_64 ) ;
V_2 = V_6 -> V_51 ;
if ( V_2 == NULL )
return - V_65 ;
if ( V_2 -> V_30 . V_31 == NULL )
return - V_65 ;
V_34 = V_2 -> V_30 . V_34 ;
V_35 = V_2 -> V_30 . V_35 ;
V_60 = ( V_34 >= V_35 ) ? ( V_32 - ( V_34 - V_35 ) ) : ( V_35 - V_34 ) ;
V_60 -- ;
if ( V_60 > 0 ) {
* V_34 ++ = V_64 ;
if ( V_34 >= ( V_2 -> V_30 . V_31 + V_32 ) )
V_34 = V_2 -> V_30 . V_31 ;
}
V_2 -> V_30 . V_34 = V_34 ;
return 0 ;
}
static void F_44 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_8 ( L_10 , V_6 ) ;
V_2 = V_6 -> V_51 ;
if ( V_2 == NULL )
return;
if ( V_2 -> V_30 . V_31 == NULL )
return;
F_20 ( V_2 , - 1 , 1 ) ;
}
static int F_45 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
char * V_34 , * V_35 ;
F_8 ( L_11 , V_6 ) ;
V_2 = V_6 -> V_51 ;
if ( V_2 == NULL )
return 0 ;
if ( V_2 -> V_30 . V_31 == NULL )
return 0 ;
V_34 = V_2 -> V_30 . V_34 ;
V_35 = V_2 -> V_30 . V_35 ;
return ( V_34 >= V_35 ) ? ( V_32 - ( V_34 - V_35 ) - 1 ) : ( V_35 - V_34 - 1 ) ;
}
static int F_46 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
unsigned int V_66 ;
char * V_34 , * V_35 ;
F_8 ( L_12 , V_6 ) ;
V_2 = V_6 -> V_51 ;
if ( V_2 == NULL )
return 0 ;
if ( V_2 -> V_30 . V_31 == NULL )
return 0 ;
V_34 = V_2 -> V_30 . V_34 ;
V_35 = V_2 -> V_30 . V_35 ;
V_66 = ( V_34 >= V_35 ) ? ( V_34 - V_35 ) : ( V_32 - ( V_35 - V_34 ) ) ;
if ( ( V_66 == 0 ) && F_47 ( V_67 , & V_2 -> V_58 ) )
V_66 = 1 ;
return V_66 ;
}
static int F_48 ( struct V_1 * V_2 , struct V_68 T_2 * V_15 )
{
struct V_68 V_69 ;
struct V_24 * V_25 ;
F_8 ( L_13 , V_2 , V_15 ) ;
memset ( & V_69 , 0 , sizeof( struct V_68 ) ) ;
F_49 ( & V_2 -> V_7 . V_70 ) ;
V_69 . line = V_2 -> V_42 ;
V_69 . V_7 = V_2 -> V_71 ;
V_69 . V_10 = V_2 -> V_7 . V_10 ;
V_69 . V_72 = V_2 -> V_72 ;
V_69 . V_73 = V_2 -> V_73 ;
V_69 . V_74 = V_2 -> V_74 ;
V_69 . V_75 = V_2 -> V_75 ;
V_69 . V_76 = 0 ;
if ( V_2 -> V_77 == & V_78 ) {
V_69 . type = V_79 ;
V_69 . V_80 = V_81 ;
} else {
V_69 . type = V_82 ;
V_69 . V_80 = V_83 ;
}
V_25 = V_46 [ V_2 -> V_40 ] ;
if ( V_25 != NULL )
V_69 . V_23 = V_25 -> V_23 ;
F_50 ( & V_2 -> V_7 . V_70 ) ;
return F_51 ( V_15 , & V_69 , sizeof( struct V_68 ) ) ? - V_84 : 0 ;
}
static int F_52 ( struct V_5 * V_6 , struct V_68 T_2 * V_15 )
{
struct V_1 * V_2 = V_6 -> V_51 ;
struct V_68 V_69 ;
F_8 ( L_14 , V_2 , V_15 ) ;
if ( F_53 ( & V_69 , V_15 , sizeof( struct V_68 ) ) )
return - V_84 ;
F_49 ( & V_2 -> V_7 . V_70 ) ;
if ( ! F_54 ( V_85 ) ) {
if ( ( V_69 . V_72 != V_2 -> V_72 ) ||
( V_69 . V_73 != V_2 -> V_73 ) ||
( ( V_69 . V_10 & ~ V_86 ) !=
( V_2 -> V_7 . V_10 & ~ V_86 ) ) ) {
F_50 ( & V_2 -> V_7 . V_70 ) ;
return - V_87 ;
}
}
V_2 -> V_7 . V_10 = ( V_2 -> V_7 . V_10 & ~ V_86 ) |
( V_69 . V_10 & V_86 ) ;
V_2 -> V_72 = V_69 . V_72 ;
V_2 -> V_73 = V_69 . V_73 ;
V_2 -> V_74 = V_69 . V_74 ;
V_2 -> V_75 = V_69 . V_75 ;
F_50 ( & V_2 -> V_7 . V_70 ) ;
F_17 ( V_2 , V_6 -> V_36 ) ;
return 0 ;
}
static int F_55 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
V_2 = V_6 -> V_51 ;
if ( V_2 == NULL )
return - V_45 ;
if ( V_6 -> V_10 & ( 1 << V_88 ) )
return - V_89 ;
return F_3 ( V_2 ) ;
}
static int F_56 ( struct V_5 * V_6 ,
unsigned int V_90 , unsigned int V_91 )
{
struct V_1 * V_2 ;
int V_92 = - 1 , V_93 = - 1 ;
V_2 = V_6 -> V_51 ;
if ( V_2 == NULL )
return - V_45 ;
if ( V_6 -> V_10 & ( 1 << V_88 ) )
return - V_89 ;
if ( V_90 & V_94 )
V_92 = 1 ;
if ( V_90 & V_95 )
V_93 = 1 ;
if ( V_91 & V_94 )
V_92 = 0 ;
if ( V_91 & V_95 )
V_93 = 0 ;
F_18 ( V_2 , V_93 , V_92 ) ;
return 0 ;
}
static int F_57 ( struct V_5 * V_6 , unsigned int V_96 , unsigned long V_97 )
{
struct V_1 * V_2 ;
int V_98 ;
void T_2 * V_14 = ( void T_2 * ) V_97 ;
F_8 ( L_15 , V_6 , V_96 , V_97 ) ;
V_2 = V_6 -> V_51 ;
if ( V_2 == NULL )
return - V_45 ;
if ( ( V_96 != V_99 ) && ( V_96 != V_100 ) &&
( V_96 != V_101 ) && ( V_96 != V_102 ) )
if ( V_6 -> V_10 & ( 1 << V_88 ) )
return - V_89 ;
V_98 = 0 ;
switch ( V_96 ) {
case V_99 :
V_98 = F_48 ( V_2 , V_14 ) ;
break;
case V_100 :
V_98 = F_52 ( V_6 , V_14 ) ;
break;
case V_101 :
V_98 = F_58 ( V_6 , V_2 , V_14 ) ;
break;
case V_102 :
V_98 = F_59 ( V_2 , V_14 ) ;
break;
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
default:
V_98 = - V_110 ;
break;
}
return V_98 ;
}
static void F_60 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_8 ( L_16 , V_6 ) ;
V_2 = V_6 -> V_51 ;
if ( V_2 == NULL )
return;
F_20 ( V_2 , - 1 , 1 ) ;
}
static void F_61 ( struct V_5 * V_6 , struct V_111 * V_112 )
{
struct V_1 * V_2 ;
struct V_111 * V_113 ;
F_8 ( L_17 , V_6 , V_112 ) ;
V_2 = V_6 -> V_51 ;
if ( V_2 == NULL )
return;
V_113 = V_6 -> V_36 ;
if ( ( V_113 -> V_114 == V_112 -> V_114 ) &&
( V_113 -> V_115 == V_112 -> V_115 ) )
return;
F_17 ( V_2 , V_113 ) ;
F_18 ( V_2 , ( ( V_113 -> V_114 & ( V_116 & ~ V_117 ) ) ? 1 : 0 ) ,
- 1 ) ;
if ( ( V_112 -> V_114 & V_118 ) && ( ( V_113 -> V_114 & V_118 ) == 0 ) ) {
V_6 -> V_119 = 0 ;
F_60 ( V_6 ) ;
}
if ( ( ( V_112 -> V_114 & V_120 ) == 0 ) && ( V_113 -> V_114 & V_120 ) )
F_4 ( & V_2 -> V_7 . V_9 ) ;
}
static void F_62 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_8 ( L_18 , V_6 ) ;
V_2 = V_6 -> V_51 ;
if ( V_2 == NULL )
return;
F_63 ( V_2 , 0 ) ;
}
static void F_64 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_8 ( L_19 , V_6 ) ;
V_2 = V_6 -> V_51 ;
if ( V_2 == NULL )
return;
F_63 ( V_2 , 1 ) ;
}
static void F_65 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_8 ( L_20 , V_6 ) ;
V_2 = V_6 -> V_51 ;
if ( V_2 == NULL )
return;
F_20 ( V_2 , - 1 , 0 ) ;
}
static void F_66 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_51 ;
F_8 ( L_21 , V_6 ) ;
if ( V_2 == NULL )
return;
F_67 ( & V_2 -> V_7 ) ;
}
static int F_68 ( struct V_5 * V_6 , int V_121 )
{
struct V_1 * V_2 ;
F_8 ( L_22 , V_6 , V_121 ) ;
V_2 = V_6 -> V_51 ;
if ( V_2 == NULL )
return - V_65 ;
F_69 ( V_2 , ( ( V_121 == - 1 ) ? 1 : 2 ) ) ;
return 0 ;
}
static void F_70 ( struct V_5 * V_6 , char V_64 )
{
struct V_1 * V_2 ;
F_8 ( L_23 , V_6 , V_64 ) ;
V_2 = V_6 -> V_51 ;
if ( V_2 == NULL )
return;
if ( V_64 == F_71 ( V_6 ) )
F_72 ( V_2 , 0 ) ;
else if ( V_64 == F_73 ( V_6 ) )
F_72 ( V_2 , 1 ) ;
else
F_43 ( V_6 , V_64 ) ;
}
static void F_74 ( struct V_122 * V_123 , struct V_1 * V_2 , int V_42 )
{
int V_4 ;
char V_124 ;
F_75 ( V_123 , L_24 ,
V_42 , ( V_2 -> V_125 == 1 ) ? L_25 : L_26 ,
( int ) V_2 -> V_126 . V_127 , ( int ) V_2 -> V_126 . V_128 ) ;
if ( V_2 -> V_126 . V_129 )
F_75 ( V_123 , L_27 , ( int ) V_2 -> V_126 . V_129 ) ;
if ( V_2 -> V_126 . V_130 )
F_75 ( V_123 , L_28 , ( int ) V_2 -> V_126 . V_130 ) ;
if ( V_2 -> V_126 . V_131 )
F_75 ( V_123 , L_29 , ( int ) V_2 -> V_126 . V_131 ) ;
if ( V_2 -> V_126 . V_132 )
F_75 ( V_123 , L_30 , ( int ) V_2 -> V_126 . V_132 ) ;
V_4 = F_3 ( V_2 ) ;
V_124 = ' ' ;
if ( V_4 & V_94 ) {
F_75 ( V_123 , L_31 , V_124 , L_32 ) ;
V_124 = '|' ;
}
if ( V_4 & V_133 ) {
F_75 ( V_123 , L_31 , V_124 , L_33 ) ;
V_124 = '|' ;
}
if ( V_4 & V_95 ) {
F_75 ( V_123 , L_31 , V_124 , L_34 ) ;
V_124 = '|' ;
}
if ( V_4 & V_8 ) {
F_75 ( V_123 , L_31 , V_124 , L_35 ) ;
V_124 = '|' ;
}
if ( V_4 & V_134 ) {
F_75 ( V_123 , L_31 , V_124 , L_36 ) ;
V_124 = '|' ;
}
F_76 ( V_123 , '\n' ) ;
}
static int F_77 ( struct V_122 * V_123 , void * V_135 )
{
struct V_24 * V_25 ;
struct V_136 * V_137 ;
struct V_1 * V_2 ;
unsigned int V_40 , V_41 , V_42 ;
int V_138 ;
V_138 = 0 ;
F_75 ( V_123 , L_37 , V_139 , V_140 ) ;
for ( V_40 = 0 ; V_40 < V_44 ; V_40 ++ ) {
V_25 = V_46 [ V_40 ] ;
if ( V_25 == NULL )
continue;
if ( V_25 -> V_121 == 0 )
continue;
V_138 = V_40 * V_141 ;
for ( V_41 = 0 ; V_41 < V_25 -> V_142 ; V_41 ++ ) {
V_137 = V_25 -> V_48 [ V_41 ] ;
if ( V_137 == NULL )
continue;
for ( V_42 = 0 ; V_42 < V_137 -> V_49 ; V_42 ++ ,
V_138 ++ ) {
V_2 = V_137 -> V_50 [ V_42 ] ;
if ( V_2 == NULL )
continue;
F_74 ( V_123 , V_2 , V_138 ) ;
}
}
}
return 0 ;
}
static int F_78 ( struct V_143 * V_143 , struct V_37 * V_37 )
{
return F_79 ( V_37 , F_77 , NULL ) ;
}
static T_3 F_80 ( int V_23 , void * V_144 )
{
struct V_24 * V_25 = V_144 ;
F_8 ( L_38 , V_25 , V_25 -> V_23 ) ;
return F_81 ( (* V_25 -> V_145 )( V_25 ) ) ;
}
static int F_82 ( struct V_24 * V_25 )
{
struct V_136 * V_137 ;
unsigned int V_146 ;
int V_147 = 0 ;
F_83 ( & V_148 ) ;
V_137 = V_25 -> V_48 [ 0 ] ;
V_146 = V_137 -> V_146 ;
while ( F_84 ( V_25 -> V_149 ) & V_150 ) {
V_147 = 1 ;
(* V_137 -> V_145 )( V_137 , V_146 ) ;
}
F_85 ( & V_148 ) ;
return V_147 ;
}
static int F_86 ( struct V_24 * V_25 )
{
struct V_136 * V_137 ;
unsigned int V_71 , V_151 ;
int V_147 = 0 ;
F_87 ( ( V_25 -> V_152 | V_153 ) , V_25 -> V_154 ) ;
while ( F_84 ( V_25 -> V_149 ) & V_155 ) {
V_147 = 1 ;
for ( V_151 = 0 ; V_151 < V_25 -> V_156 ; V_151 ++ ) {
V_71 = V_25 -> V_157 [ V_151 ] ;
if ( F_84 ( V_71 ) & V_158 ) {
V_137 = V_25 -> V_159 [ V_151 ] ;
(* V_137 -> V_145 )( V_137 , ( V_71 & 0xfffc ) ) ;
}
}
}
F_87 ( ( V_25 -> V_152 | V_160 ) , V_25 -> V_154 ) ;
return V_147 ;
}
static int F_88 ( struct V_24 * V_25 )
{
struct V_136 * V_137 ;
unsigned int V_71 , V_151 ;
int V_147 = 0 ;
while ( F_84 ( V_25 -> V_149 ) & V_155 ) {
V_147 = 1 ;
for ( V_151 = 0 ; V_151 < V_25 -> V_156 ; V_151 ++ ) {
V_71 = V_25 -> V_157 [ V_151 ] ;
if ( F_84 ( V_71 ) & V_158 ) {
V_137 = V_25 -> V_159 [ V_151 ] ;
(* V_137 -> V_145 )( V_137 , ( V_71 & 0xfffc ) ) ;
}
}
}
return V_147 ;
}
static int F_89 ( struct V_24 * V_25 )
{
struct V_136 * V_137 ;
unsigned int V_71 , V_151 , V_161 ;
int V_147 = 0 ;
while ( 1 ) {
V_161 = 0 ;
for ( V_151 = 0 ; V_151 < V_25 -> V_156 ; V_151 ++ ) {
F_87 ( V_25 -> V_162 [ V_151 ] , V_25 -> V_154 ) ;
V_71 = V_25 -> V_157 [ V_151 ] ;
if ( F_84 ( V_71 ) & V_158 ) {
V_137 = V_25 -> V_159 [ V_151 ] ;
(* V_137 -> V_145 )( V_137 , ( V_71 & 0xfffc ) ) ;
V_161 ++ ;
V_147 = 1 ;
}
}
if ( ! V_161 )
break;
}
return V_147 ;
}
static int F_90 ( struct V_24 * V_25 )
{
struct V_136 * V_137 ;
unsigned int V_71 , V_151 ;
int V_147 = 0 ;
while ( F_84 ( V_25 -> V_154 ) & 0x1 ) {
V_147 = 1 ;
for ( V_151 = 0 ; V_151 < V_25 -> V_156 ; V_151 ++ ) {
V_71 = V_25 -> V_157 [ V_151 ] ;
if ( F_84 ( V_71 ) & V_158 ) {
V_137 = V_25 -> V_159 [ V_151 ] ;
(* V_137 -> V_145 )( V_137 , ( V_71 & 0xfffc ) ) ;
}
}
}
return V_147 ;
}
static int T_4 F_91 ( struct V_24 * V_25 , struct V_136 * V_137 )
{
struct V_1 * V_2 ;
unsigned int V_16 ;
int V_163 ;
F_8 ( L_39 , V_25 , V_137 ) ;
V_163 = F_92 ( V_25 , V_137 ) ;
for ( V_16 = 0 ; V_16 < V_137 -> V_49 ; V_16 ++ ) {
V_2 = F_13 ( sizeof( struct V_1 ) , V_26 ) ;
if ( ! V_2 ) {
F_10 ( L_40
L_41 , sizeof( struct V_1 ) ) ;
break;
}
F_93 ( & V_2 -> V_7 ) ;
V_2 -> V_7 . V_164 = & V_165 ;
V_2 -> V_27 = V_166 ;
V_2 -> V_42 = V_16 ;
V_2 -> V_40 = V_137 -> V_40 ;
V_2 -> V_41 = V_137 -> V_41 ;
V_2 -> V_77 = V_137 -> V_77 ;
V_2 -> V_167 = V_25 -> V_167 ;
V_2 -> V_72 = V_168 ;
V_2 -> V_73 = V_169 ;
V_2 -> V_74 = 30 * V_55 ;
F_94 ( & V_2 -> V_7 . V_9 ) ;
F_94 ( & V_2 -> V_7 . V_170 ) ;
V_2 -> V_126 . V_171 = V_2 -> V_40 ;
V_2 -> V_126 . V_172 = V_2 -> V_41 ;
V_2 -> V_126 . V_7 = V_2 -> V_42 ;
V_137 -> V_50 [ V_16 ] = V_2 ;
F_95 ( V_25 , V_137 , V_2 ) ;
}
return 0 ;
}
static void F_96 ( struct V_24 * V_25 )
{
struct V_136 * V_137 ;
struct V_1 * V_2 ;
unsigned int V_173 , V_174 ;
struct V_5 * V_6 ;
for ( V_173 = 0 ; V_173 < V_47 ; V_173 ++ ) {
V_137 = V_25 -> V_48 [ V_173 ] ;
if ( V_137 == NULL )
continue;
for ( V_174 = 0 ; V_174 < V_175 ; V_174 ++ ) {
V_2 = V_137 -> V_50 [ V_174 ] ;
if ( V_2 == NULL )
continue;
V_6 = F_2 ( & V_2 -> V_7 ) ;
if ( V_6 != NULL ) {
F_66 ( V_6 ) ;
F_6 ( V_6 ) ;
}
F_37 ( V_2 -> V_30 . V_31 ) ;
F_37 ( V_2 ) ;
}
F_37 ( V_137 ) ;
}
}
static int T_4 F_97 ( struct V_24 * V_25 )
{
struct V_136 * V_137 ;
unsigned int V_176 ;
char * V_18 ;
int V_177 ;
F_8 ( L_42 , V_25 ) ;
V_25 -> V_154 = V_25 -> V_20 + 1 ;
V_25 -> V_149 = V_25 -> V_20 + 2 ;
V_176 = F_84 ( V_25 -> V_149 ) ;
if ( ( V_176 & V_178 ) == V_179 )
V_25 -> V_154 ++ ;
if ( V_25 -> V_19 == V_180 ) {
V_25 -> V_181 = 0x80 ;
V_25 -> V_182 = 0x80 ;
V_18 = L_43 ;
F_87 ( 0x41 , ( V_25 -> V_22 + 0x4c ) ) ;
} else {
V_25 -> V_181 = 8 ;
V_18 = L_44 ;
if ( ( V_25 -> V_23 < 0 ) || ( V_25 -> V_23 > 15 ) ||
( V_183 [ V_25 -> V_23 ] == ( unsigned char ) 0xff ) ) {
F_10 ( L_45 ,
V_25 -> V_23 , V_25 -> V_40 ) ;
V_177 = - V_65 ;
goto V_184;
}
F_87 ( ( V_183 [ V_25 -> V_23 ] | V_185 |
( ( V_25 -> V_186 ) ? V_187 : V_188 ) ) ,
V_25 -> V_154 ) ;
}
V_177 = - V_189 ;
if ( ! F_98 ( V_25 -> V_20 , V_25 -> V_181 , V_18 ) ) {
F_10 ( V_190 L_46
L_47 , V_25 -> V_40 ,
V_25 -> V_20 ) ;
goto V_184;
}
if ( V_25 -> V_182 > 0 )
if ( ! F_98 ( V_25 -> V_22 , V_25 -> V_182 , V_18 ) ) {
F_10 ( V_190 L_48
L_49 ,
V_25 -> V_40 , V_25 -> V_22 ) ;
F_10 ( V_190 L_50
L_51 ,
V_25 -> V_40 , V_25 -> V_20 ) ;
goto V_191;
}
V_25 -> V_167 = V_192 ;
V_25 -> V_145 = F_82 ;
V_177 = - V_45 ;
switch ( V_176 & V_178 ) {
case V_193 :
V_25 -> V_167 = V_194 ;
case V_195 :
case V_196 :
V_25 -> V_49 = 8 ;
break;
case V_197 :
V_25 -> V_49 = 4 ;
break;
case V_179 :
switch ( V_176 & V_198 ) {
case V_199 :
V_25 -> V_49 = 4 ;
break;
case V_200 :
V_25 -> V_49 = 8 ;
break;
case V_201 :
V_25 -> V_49 = 16 ;
break;
default:
goto V_202;
}
break;
default:
goto V_202;
}
V_137 = F_13 ( sizeof( struct V_136 ) , V_26 ) ;
if ( ! V_137 ) {
F_10 ( V_190 L_40
L_41 , sizeof( struct V_136 ) ) ;
V_177 = - V_33 ;
goto V_202;
}
V_137 -> V_27 = V_203 ;
V_137 -> V_40 = V_25 -> V_40 ;
V_137 -> V_41 = 0 ;
V_137 -> V_49 = V_25 -> V_49 ;
V_137 -> V_146 = V_25 -> V_20 ;
V_137 -> V_125 = V_176 ;
if ( ( V_176 & V_178 ) == V_179 ) {
V_137 -> V_77 = & V_204 ;
V_137 -> V_145 = V_205 ;
} else {
V_137 -> V_77 = & V_78 ;
V_137 -> V_145 = V_206 ;
}
V_25 -> V_48 [ 0 ] = V_137 ;
V_25 -> V_142 = 1 ;
V_25 -> V_121 |= V_207 ;
V_25 -> V_125 = V_176 ;
if ( F_99 ( V_25 -> V_23 , F_80 , V_208 , V_18 , V_25 ) != 0 ) {
F_10 ( L_52
L_53 , V_18 , V_25 -> V_23 ) ;
V_177 = - V_45 ;
goto V_209;
}
return 0 ;
V_209:
F_96 ( V_25 ) ;
V_202:
if ( V_25 -> V_182 > 0 )
F_100 ( V_25 -> V_22 , V_25 -> V_182 ) ;
V_191:
F_100 ( V_25 -> V_20 , V_25 -> V_181 ) ;
V_184:
return V_177 ;
}
static int T_4 F_101 ( struct V_24 * V_25 )
{
struct V_136 * V_137 ;
unsigned int V_176 , V_210 , V_71 , V_211 , V_41 , V_212 , V_16 ;
int V_177 ;
char * V_18 ;
F_8 ( L_54 , V_25 ) ;
V_176 = 0 ;
V_211 = 0 ;
switch ( V_25 -> V_19 ) {
case V_21 :
V_25 -> V_145 = F_86 ;
V_25 -> V_154 = V_25 -> V_20 + 1 ;
V_25 -> V_149 = V_25 -> V_20 + 1 ;
V_176 = F_84 ( V_25 -> V_149 ) ;
if ( ( V_176 & V_213 ) != V_214 ) {
V_177 = - V_45 ;
goto V_184;
}
if ( ( V_25 -> V_23 < 0 ) || ( V_25 -> V_23 > 15 ) ||
( V_183 [ V_25 -> V_23 ] == ( unsigned char ) 0xff ) ) {
F_10 ( L_45 ,
V_25 -> V_23 , V_25 -> V_40 ) ;
V_177 = - V_65 ;
goto V_184;
}
V_176 = ( ( V_25 -> V_22 & V_215 ) >> 1 ) ;
V_176 |= ( V_183 [ V_25 -> V_23 ] << 1 ) ;
F_87 ( ( V_176 | V_216 ) , V_25 -> V_20 ) ;
V_25 -> V_152 = V_217 |
( ( V_25 -> V_186 ) ? V_218 : V_219 ) ;
for ( V_16 = 0 ; V_16 < 10 ; V_16 ++ )
F_87 ( ( V_25 -> V_152 | V_153 ) , V_25 -> V_154 ) ;
V_25 -> V_181 = 2 ;
V_25 -> V_182 = 32 ;
V_18 = L_55 ;
F_87 ( V_176 , V_25 -> V_20 ) ;
break;
case V_220 :
V_25 -> V_145 = F_88 ;
V_25 -> V_154 = V_25 -> V_20 + 0x20 ;
V_25 -> V_149 = V_25 -> V_154 ;
V_176 = F_84 ( V_25 -> V_149 ) ;
if ( ( V_176 & V_213 ) != V_214 ) {
V_177 = - V_45 ;
goto V_184;
}
if ( ( V_25 -> V_23 < 0 ) || ( V_25 -> V_23 > 15 ) ||
( V_183 [ V_25 -> V_23 ] == ( unsigned char ) 0xff ) ) {
F_10 ( L_45 ,
V_25 -> V_23 , V_25 -> V_40 ) ;
V_177 = - V_65 ;
goto V_184;
}
F_87 ( V_221 , V_25 -> V_154 ) ;
F_87 ( V_222 , V_25 -> V_154 ) ;
V_25 -> V_181 = 64 ;
V_18 = L_56 ;
break;
case V_223 :
V_25 -> V_145 = F_89 ;
V_25 -> V_154 = V_25 -> V_20 + 2 ;
V_25 -> V_181 = 4 ;
V_25 -> V_182 = 8 ;
V_18 = L_57 ;
break;
case V_224 :
V_25 -> V_145 = F_90 ;
V_25 -> V_154 = V_25 -> V_22 + 0x40 ;
F_87 ( 0x43 , ( V_25 -> V_20 + 0x4c ) ) ;
V_25 -> V_181 = 0x80 ;
V_25 -> V_182 = 0x80 ;
V_18 = L_58 ;
break;
default:
F_10 ( L_59 , V_25 -> V_19 ) ;
V_177 = - V_65 ;
goto V_184;
}
V_177 = - V_189 ;
if ( ! F_98 ( V_25 -> V_20 , V_25 -> V_181 , V_18 ) ) {
F_10 ( V_190 L_46
L_47 , V_25 -> V_40 ,
V_25 -> V_20 ) ;
goto V_184;
}
if ( V_25 -> V_182 > 0 )
if ( ! F_98 ( V_25 -> V_22 , V_25 -> V_182 , V_18 ) ) {
F_10 ( V_190 L_48
L_49 ,
V_25 -> V_40 , V_25 -> V_22 ) ;
F_10 ( V_190 L_50
L_51 ,
V_25 -> V_40 , V_25 -> V_20 ) ;
goto V_191;
}
V_25 -> V_167 = V_192 ;
V_25 -> V_125 = V_176 ;
V_71 = V_25 -> V_22 ;
V_212 = 0 ;
V_41 = 0 ;
V_210 = 0 ;
for ( V_16 = 0 ; V_16 < V_47 ; V_16 ++ ) {
if ( V_25 -> V_19 == V_223 ) {
F_87 ( V_210 , V_25 -> V_154 ) ;
V_71 = V_25 -> V_22 ;
}
V_176 = F_84 ( V_71 + V_225 ) ;
if ( ( V_176 & V_226 ) != V_210 )
break;
V_137 = F_13 ( sizeof( struct V_136 ) , V_26 ) ;
if ( ! V_137 ) {
F_10 ( L_40
L_41 , sizeof( struct V_136 ) ) ;
V_177 = - V_33 ;
goto V_209;
}
V_137 -> V_27 = V_203 ;
V_137 -> V_40 = V_25 -> V_40 ;
V_137 -> V_41 = V_41 ;
V_137 -> V_146 = V_71 ;
V_137 -> V_227 = V_210 ;
V_137 -> V_125 = V_176 ;
V_25 -> V_159 [ V_212 ] = V_137 ;
V_25 -> V_162 [ V_212 ] = V_210 ;
V_25 -> V_157 [ V_212 ++ ] = V_71 + V_225 ;
if ( V_176 & V_228 ) {
V_137 -> V_77 = & V_204 ;
V_137 -> V_145 = V_205 ;
if ( V_176 & V_229 ) {
V_137 -> V_49 = 16 ;
V_25 -> V_159 [ V_212 ] = V_137 ;
V_25 -> V_162 [ V_212 ] = V_210 ;
V_25 -> V_157 [ V_212 ++ ] = V_71 + 4 +
V_225 ;
} else
V_137 -> V_49 = 8 ;
} else {
V_137 -> V_77 = & V_78 ;
V_137 -> V_145 = V_230 ;
if ( V_176 & V_229 ) {
V_137 -> V_49 = 16 ;
V_137 -> V_231 = 0x80 ;
if ( V_25 -> V_19 != V_223 )
V_71 += V_232 ;
V_25 -> V_159 [ V_212 ] = V_137 ;
V_25 -> V_162 [ V_212 ] = ++ V_210 ;
V_25 -> V_157 [ V_212 ++ ] = V_71 +
V_225 ;
} else {
V_137 -> V_49 = 8 ;
V_137 -> V_231 = 0xc0 ;
}
}
V_210 ++ ;
V_71 += V_232 ;
V_25 -> V_49 += V_137 -> V_49 ;
V_25 -> V_48 [ V_41 ++ ] = V_137 ;
if ( ( V_25 -> V_19 != V_223 ) &&
( V_71 >= ( V_25 -> V_22 + V_25 -> V_182 ) ) ) {
V_177 = - V_65 ;
goto V_209;
}
}
V_25 -> V_142 = V_41 ;
V_25 -> V_156 = V_212 ;
if ( V_25 -> V_19 == V_21 )
F_87 ( ( V_25 -> V_152 | V_160 ) , V_25 -> V_154 ) ;
V_25 -> V_121 |= V_207 ;
if ( F_99 ( V_25 -> V_23 , F_80 , V_208 , V_18 , V_25 ) != 0 ) {
F_10 ( L_52
L_53 , V_18 , V_25 -> V_23 ) ;
V_177 = - V_45 ;
goto V_209;
}
return 0 ;
V_209:
F_96 ( V_25 ) ;
if ( V_25 -> V_182 > 0 )
F_100 ( V_25 -> V_22 , V_25 -> V_182 ) ;
V_191:
F_100 ( V_25 -> V_20 , V_25 -> V_181 ) ;
V_184:
return V_177 ;
}
static int T_4 F_102 ( struct V_24 * V_25 )
{
int V_16 , V_177 ;
F_8 ( L_60 , V_25 ) ;
switch ( V_25 -> V_19 ) {
case V_233 :
case V_180 :
V_177 = F_97 ( V_25 ) ;
if ( V_177 )
goto V_184;
break;
case V_21 :
case V_220 :
case V_223 :
case V_224 :
V_177 = F_101 ( V_25 ) ;
if ( V_177 )
goto V_184;
break;
default:
F_10 ( L_61 ,
V_25 -> V_40 , V_25 -> V_19 ) ;
V_177 = - V_45 ;
goto V_184;
}
if ( ( V_25 -> V_121 & V_207 ) == 0 ) {
F_10 ( L_62 ,
V_234 [ V_25 -> V_19 ] , V_25 -> V_40 ,
V_25 -> V_20 , V_25 -> V_23 ) ;
goto V_235;
}
for ( V_16 = 0 ; V_16 < V_47 ; V_16 ++ )
if ( V_25 -> V_48 [ V_16 ] != NULL )
F_91 ( V_25 , V_25 -> V_48 [ V_16 ] ) ;
F_10 ( L_63
L_64 , V_234 [ V_25 -> V_19 ] ,
V_25 -> V_40 , V_25 -> V_20 , V_25 -> V_23 , V_25 -> V_142 ,
V_25 -> V_49 ) ;
return 0 ;
V_235:
F_103 ( V_25 -> V_23 , V_25 ) ;
F_96 ( V_25 ) ;
F_100 ( V_25 -> V_20 , V_25 -> V_181 ) ;
if ( V_25 -> V_182 > 0 )
F_100 ( V_25 -> V_22 , V_25 -> V_182 ) ;
V_184:
return V_177 ;
}
static int T_4 F_104 ( void )
{
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < V_236 ; V_16 ++ )
if ( V_46 [ V_16 ] == NULL ) {
if ( V_16 >= V_44 )
V_44 = V_16 + 1 ;
return V_16 ;
}
return - 1 ;
}
static int T_4 F_105 ( struct V_237 * V_238 ,
const struct V_239 * V_240 )
{
struct V_24 * V_25 ;
unsigned int V_16 , V_19 = V_240 -> V_51 ;
int V_40 , V_177 = - V_45 ;
if ( ( V_238 -> V_241 >> 8 ) == V_242 )
goto V_184;
V_177 = F_106 ( V_238 ) ;
if ( V_177 )
goto V_184;
V_25 = F_12 () ;
if ( V_25 == NULL ) {
V_177 = - V_33 ;
goto V_184;
}
F_49 ( & V_243 ) ;
V_40 = F_104 () ;
if ( V_40 < 0 ) {
F_107 ( & V_238 -> V_244 , L_65
L_66 , V_236 ) ;
F_50 ( & V_243 ) ;
V_177 = - V_45 ;
goto V_209;
}
V_25 -> V_40 = ( unsigned int ) V_40 ;
V_46 [ V_25 -> V_40 ] = V_25 ;
F_50 ( & V_243 ) ;
V_25 -> V_19 = V_19 ;
V_25 -> V_121 |= V_245 ;
switch ( V_19 ) {
case V_223 :
V_25 -> V_22 = F_108 ( V_238 , 0 ) ;
V_25 -> V_20 = F_108 ( V_238 , 1 ) ;
break;
case V_224 :
V_25 -> V_22 = F_108 ( V_238 , 2 ) ;
V_25 -> V_20 = F_108 ( V_238 , 1 ) ;
break;
case V_180 :
V_25 -> V_20 = F_108 ( V_238 , 2 ) ;
V_25 -> V_22 = F_108 ( V_238 , 1 ) ;
break;
default:
F_107 ( & V_238 -> V_244 , L_67 , V_19 ) ;
break;
}
V_25 -> V_23 = V_238 -> V_23 ;
V_177 = F_102 ( V_25 ) ;
if ( V_177 )
goto V_246;
F_109 ( V_238 , V_25 ) ;
for ( V_16 = 0 ; V_16 < V_25 -> V_49 ; V_16 ++ )
F_110 ( V_247 ,
V_25 -> V_40 * V_141 + V_16 , & V_238 -> V_244 ) ;
return 0 ;
V_246:
V_46 [ V_25 -> V_40 ] = NULL ;
V_209:
F_37 ( V_25 ) ;
V_184:
return V_177 ;
}
static void T_5 F_111 ( struct V_237 * V_238 )
{
struct V_24 * V_25 = F_112 ( V_238 ) ;
unsigned int V_16 ;
F_103 ( V_25 -> V_23 , V_25 ) ;
F_96 ( V_25 ) ;
F_100 ( V_25 -> V_20 , V_25 -> V_181 ) ;
if ( V_25 -> V_182 > 0 )
F_100 ( V_25 -> V_22 , V_25 -> V_182 ) ;
for ( V_16 = 0 ; V_16 < V_25 -> V_49 ; V_16 ++ )
F_113 ( V_247 ,
V_25 -> V_40 * V_141 + V_16 ) ;
V_46 [ V_25 -> V_40 ] = NULL ;
F_37 ( V_25 ) ;
}
static int F_114 ( T_6 T_2 * V_248 )
{
T_6 V_249 ;
struct V_24 * V_25 ;
struct V_136 * V_137 ;
unsigned int V_16 ;
if ( F_53 ( & V_249 , V_248 , sizeof( T_6 ) ) )
return - V_84 ;
if ( V_249 . V_171 >= V_236 )
return - V_45 ;
V_25 = V_46 [ V_249 . V_171 ] ;
if ( V_25 == NULL )
return - V_45 ;
memset ( & V_249 , 0 , sizeof( T_6 ) ) ;
V_249 . V_171 = V_25 -> V_40 ;
V_249 . type = V_25 -> V_19 ;
V_249 . V_125 = V_25 -> V_125 ;
V_249 . V_121 = V_25 -> V_121 ;
V_249 . V_71 = V_25 -> V_20 ;
V_249 . V_22 = V_25 -> V_22 ;
V_249 . V_23 = V_25 -> V_23 ;
V_249 . V_142 = V_25 -> V_142 ;
V_249 . V_49 = V_25 -> V_49 ;
for ( V_16 = 0 ; V_16 < V_25 -> V_142 ; V_16 ++ ) {
V_137 = V_25 -> V_48 [ V_16 ] ;
V_249 . V_48 [ V_16 ] . V_172 = V_16 ;
V_249 . V_48 [ V_16 ] . V_125 = V_137 -> V_125 ;
V_249 . V_48 [ V_16 ] . V_49 = V_137 -> V_49 ;
}
return F_51 ( V_248 , & V_249 , sizeof( T_6 ) ) ? - V_84 : 0 ;
}
static struct V_1 * F_115 ( int V_40 , int V_41 , int V_42 )
{
struct V_24 * V_25 ;
struct V_136 * V_137 ;
if ( V_40 < 0 || V_40 >= V_236 )
return NULL ;
V_25 = V_46 [ V_40 ] ;
if ( V_25 == NULL )
return NULL ;
if ( V_41 < 0 || ( unsigned int ) V_41 >= V_25 -> V_142 )
return NULL ;
V_137 = V_25 -> V_48 [ V_41 ] ;
if ( V_137 == NULL )
return NULL ;
if ( V_42 < 0 || ( unsigned int ) V_42 >= V_137 -> V_49 )
return NULL ;
return V_137 -> V_50 [ V_42 ] ;
}
static int F_58 ( struct V_5 * V_6 , struct V_1 * V_2 , T_7 T_2 * V_250 )
{
T_7 V_251 ;
unsigned char * V_34 , * V_35 ;
unsigned long V_10 ;
if ( ! V_2 ) {
if ( F_53 ( & V_251 , V_250 , sizeof( T_7 ) ) )
return - V_84 ;
V_2 = F_115 ( V_251 . V_171 , V_251 . V_172 ,
V_251 . V_7 ) ;
if ( V_2 == NULL )
return - V_45 ;
}
F_49 ( & V_2 -> V_7 . V_70 ) ;
V_2 -> V_126 . V_121 = V_2 -> V_58 ;
V_2 -> V_126 . V_10 = V_2 -> V_7 . V_10 ;
V_2 -> V_126 . V_125 = V_2 -> V_125 ;
V_2 -> V_126 . V_252 = 0 ;
V_2 -> V_126 . V_253 = 0 ;
V_2 -> V_126 . V_254 = 0 ;
V_2 -> V_126 . V_255 = 0 ;
V_2 -> V_126 . V_256 = 0 ;
V_2 -> V_126 . V_257 = 0 ;
F_116 ( & V_258 , V_10 ) ;
if ( V_6 != NULL && V_2 -> V_7 . V_6 == V_6 ) {
V_2 -> V_126 . V_252 = V_6 -> V_10 ;
V_2 -> V_126 . V_257 = 1 ;
if ( V_6 -> V_36 != NULL ) {
V_2 -> V_126 . V_253 = V_6 -> V_36 -> V_114 ;
V_2 -> V_126 . V_254 = V_6 -> V_36 -> V_115 ;
V_2 -> V_126 . V_255 = V_6 -> V_36 -> V_259 ;
V_2 -> V_126 . V_256 = V_6 -> V_36 -> V_260 ;
}
}
F_117 ( & V_258 , V_10 ) ;
V_34 = V_2 -> V_30 . V_34 ;
V_35 = V_2 -> V_30 . V_35 ;
V_2 -> V_126 . V_261 = ( V_34 >= V_35 ) ? ( V_34 - V_35 ) :
( V_32 - ( V_35 - V_34 ) ) ;
V_2 -> V_126 . V_262 = ( unsigned long ) F_3 ( V_2 ) ;
F_50 ( & V_2 -> V_7 . V_70 ) ;
return F_51 ( V_250 , & V_2 -> V_126 ,
sizeof( T_7 ) ) ? - V_84 : 0 ;
}
static int F_59 ( struct V_1 * V_2 , T_7 T_2 * V_250 )
{
T_7 V_251 ;
if ( ! V_2 ) {
if ( F_53 ( & V_251 , V_250 , sizeof( T_7 ) ) )
return - V_84 ;
V_2 = F_115 ( V_251 . V_171 , V_251 . V_172 ,
V_251 . V_7 ) ;
if ( V_2 == NULL )
return - V_45 ;
}
F_49 ( & V_2 -> V_7 . V_70 ) ;
memset ( & V_2 -> V_126 , 0 , sizeof( T_7 ) ) ;
V_2 -> V_126 . V_171 = V_2 -> V_40 ;
V_2 -> V_126 . V_172 = V_2 -> V_41 ;
V_2 -> V_126 . V_7 = V_2 -> V_42 ;
F_50 ( & V_2 -> V_7 . V_70 ) ;
return F_51 ( V_250 , & V_2 -> V_126 ,
sizeof( T_7 ) ) ? - V_84 : 0 ;
}
static int F_118 ( struct V_1 T_2 * V_97 )
{
struct V_1 V_263 ;
struct V_1 * V_2 ;
if ( F_53 ( & V_263 , V_97 , sizeof( struct V_1 ) ) )
return - V_84 ;
V_2 = F_115 ( V_263 . V_40 , V_263 . V_41 ,
V_263 . V_42 ) ;
if ( ! V_2 )
return - V_45 ;
return F_51 ( V_97 , V_2 , sizeof( struct V_1 ) ) ? - V_84 : 0 ;
}
static int F_119 ( struct V_24 T_2 * V_97 )
{
struct V_24 V_264 ;
struct V_24 * V_25 ;
if ( F_53 ( & V_264 , V_97 , sizeof( struct V_24 ) ) )
return - V_84 ;
if ( V_264 . V_40 >= V_236 )
return - V_45 ;
V_25 = V_46 [ V_264 . V_40 ] ;
if ( ! V_25 )
return - V_45 ;
return F_51 ( V_97 , V_25 , sizeof( struct V_24 ) ) ? - V_84 : 0 ;
}
static long F_120 ( struct V_37 * V_265 , unsigned int V_96 , unsigned long V_97 )
{
int V_40 , V_98 ;
void T_2 * V_14 = ( void T_2 * ) V_97 ;
F_8 ( L_68 , V_265 , V_96 , V_97 ) ;
V_40 = F_121 ( V_265 -> V_266 -> V_267 ) ;
if ( V_40 >= V_236 )
return - V_45 ;
V_98 = 0 ;
switch ( V_96 ) {
case V_101 :
V_98 = F_58 ( NULL , NULL , V_14 ) ;
break;
case V_102 :
V_98 = F_59 ( NULL , V_14 ) ;
break;
case V_268 :
V_98 = F_114 ( V_14 ) ;
break;
case V_269 :
V_98 = F_118 ( V_14 ) ;
break;
case V_270 :
V_98 = F_119 ( V_14 ) ;
break;
default:
V_98 = - V_110 ;
break;
}
return V_98 ;
}
static int F_122 ( struct V_1 * V_2 , int V_271 )
{
F_87 ( ( V_271 + V_2 -> V_272 ) , V_2 -> V_71 ) ;
return F_84 ( V_2 -> V_71 + V_273 ) ;
}
static void F_123 ( struct V_1 * V_2 , int V_271 , int V_274 )
{
F_87 ( V_271 + V_2 -> V_272 , V_2 -> V_71 ) ;
F_87 ( V_274 , V_2 -> V_71 + V_273 ) ;
}
static int F_124 ( struct V_1 * V_2 , int V_271 , int V_274 )
{
F_87 ( V_271 + V_2 -> V_272 , V_2 -> V_71 ) ;
if ( F_84 ( V_2 -> V_71 + V_273 ) != V_274 ) {
F_87 ( V_274 , V_2 -> V_71 + V_273 ) ;
return 1 ;
}
return 0 ;
}
static int F_125 ( struct V_24 * V_25 , struct V_136 * V_137 )
{
unsigned int V_275 ;
int V_163 , V_16 , V_173 ;
int V_276 , V_272 , V_71 ;
unsigned long V_10 ;
F_8 ( L_69 , V_25 , V_137 ) ;
F_116 ( & V_148 , V_10 ) ;
F_126 ( V_137 -> V_40 , V_137 -> V_227 ) ;
V_163 = 0 ;
V_276 = V_137 -> V_49 / V_277 ;
for ( V_16 = 0 ; V_16 < V_276 ; V_16 ++ ) {
if ( V_25 -> V_19 == V_223 ) {
F_87 ( ( V_137 -> V_227 + ( V_16 >> 1 ) ) , V_25 -> V_154 ) ;
V_71 = V_137 -> V_146 ;
} else
V_71 = V_137 -> V_146 + ( V_232 * ( V_16 >> 1 ) ) ;
V_272 = ( V_16 & 0x01 ) ? 0x080 : 0 ;
F_87 ( ( V_278 + V_272 ) , V_71 ) ;
F_87 ( 0 , ( V_71 + V_273 ) ) ;
F_87 ( ( V_279 + V_272 ) , V_71 ) ;
F_87 ( V_280 , ( V_71 + V_273 ) ) ;
F_87 ( V_280 , ( V_71 + V_273 ) ) ;
F_87 ( ( V_278 + V_272 ) , V_71 ) ;
for ( V_173 = 0 ; V_173 < V_281 ; V_173 ++ )
if ( ( V_275 = F_84 ( V_71 + V_273 ) ) != 0 )
break;
if ( ( V_173 >= V_281 ) || ( V_275 < 0x40 ) || ( V_275 > 0x60 ) ) {
F_10 ( L_70
L_71 ,
V_137 -> V_40 , V_137 -> V_41 , V_16 ) ;
continue;
}
V_163 |= ( 0x1 << V_16 ) ;
F_87 ( ( V_282 + V_272 ) , V_71 ) ;
F_87 ( V_283 , ( V_71 + V_273 ) ) ;
}
F_127 ( V_137 -> V_40 ) ;
F_117 ( & V_148 , V_10 ) ;
return V_163 ;
}
static void F_128 ( struct V_24 * V_25 , struct V_136 * V_137 , struct V_1 * V_2 )
{
unsigned long V_10 ;
F_8 ( L_72 , V_25 ,
V_137 , V_2 ) ;
if ( ( V_25 == NULL ) || ( V_137 == NULL ) ||
( V_2 == NULL ) )
return;
F_116 ( & V_148 , V_10 ) ;
V_2 -> V_71 = V_137 -> V_146 + ( ( ( V_25 -> V_19 == V_223 ) ||
( V_2 -> V_42 < 8 ) ) ? 0 : V_232 ) ;
V_2 -> V_272 = ( V_2 -> V_42 & 0x04 ) << 5 ;
V_2 -> V_227 = V_137 -> V_227 + ( V_2 -> V_42 >> 3 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
F_123 ( V_2 , V_284 , ( V_2 -> V_42 & 0x03 ) ) ;
F_123 ( V_2 , V_285 , ( V_2 -> V_42 << 3 ) ) ;
V_2 -> V_125 = F_122 ( V_2 , V_278 ) ;
F_127 ( V_2 -> V_40 ) ;
F_117 ( & V_148 , V_10 ) ;
}
static void F_129 ( struct V_1 * V_2 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_281 ; V_16 ++ )
if ( F_122 ( V_2 , V_279 ) == 0 )
return;
F_10 ( L_73 ,
V_2 -> V_42 , V_2 -> V_41 , V_2 -> V_40 ) ;
}
static void F_130 ( struct V_1 * V_2 , struct V_111 * V_113 )
{
struct V_24 * V_25 ;
unsigned long V_10 ;
unsigned int V_286 , V_287 ;
unsigned char V_288 , V_289 , V_290 ;
unsigned char V_291 , V_292 , V_293 ;
unsigned char V_294 , V_295 , V_296 ;
unsigned char V_297 , V_298 , V_299 ;
unsigned char V_167 , div ;
V_288 = 0 ;
V_289 = 0 ;
V_290 = 0 ;
V_291 = 0 ;
V_292 = 0 ;
V_293 = 0 ;
V_299 = 0 ;
V_167 = 0 ;
div = 0 ;
V_297 = 0 ;
V_298 = 0 ;
V_295 = 0 ;
V_296 = 0 ;
V_25 = V_46 [ V_2 -> V_40 ] ;
if ( V_25 == NULL )
return;
V_2 -> V_300 = 0 ;
if ( V_113 -> V_115 & V_301 ) {
V_2 -> V_300 |= ( V_302 | V_303 | V_304 ) ;
V_288 |= V_305 ;
}
if ( V_113 -> V_115 & V_306 ) {
V_2 -> V_300 |= V_307 ;
V_291 |= V_308 ;
}
V_2 -> V_309 = V_304 ;
if ( V_113 -> V_115 & ( V_310 | V_311 ) )
V_2 -> V_309 |= ( V_302 | V_303 ) ;
if ( V_113 -> V_115 & V_312 )
V_2 -> V_309 |= V_307 ;
switch ( V_113 -> V_114 & V_313 ) {
case V_314 :
V_288 |= V_315 ;
break;
case V_316 :
V_288 |= V_317 ;
break;
case V_318 :
V_288 |= V_319 ;
break;
default:
V_288 |= V_320 ;
break;
}
if ( V_113 -> V_114 & V_321 )
V_288 |= V_322 ;
else
V_288 |= V_323 ;
if ( V_113 -> V_114 & V_324 ) {
if ( V_113 -> V_114 & V_325 )
V_288 |= ( V_326 | V_327 ) ;
else
V_288 |= ( V_326 | V_328 ) ;
} else {
V_288 |= V_329 ;
}
V_290 |= V_330 ;
V_299 = 2 ;
V_287 = V_113 -> V_114 & V_116 ;
if ( V_287 & V_117 ) {
V_287 &= ~ V_117 ;
if ( ( V_287 < 1 ) || ( V_287 > 4 ) )
V_113 -> V_114 &= ~ V_117 ;
else
V_287 += 15 ;
}
V_287 = V_331 [ V_287 ] ;
if ( ( V_113 -> V_114 & V_116 ) == V_332 ) {
if ( ( V_2 -> V_7 . V_10 & V_333 ) == V_334 )
V_287 = 57600 ;
else if ( ( V_2 -> V_7 . V_10 & V_333 ) == V_335 )
V_287 = 115200 ;
else if ( ( V_2 -> V_7 . V_10 & V_333 ) == V_336 )
V_287 = 230400 ;
else if ( ( V_2 -> V_7 . V_10 & V_333 ) == V_337 )
V_287 = 460800 ;
else if ( ( V_2 -> V_7 . V_10 & V_333 ) == V_338 )
V_287 = ( V_2 -> V_72 / V_2 -> V_75 ) ;
}
if ( V_287 > V_339 )
V_287 = V_339 ;
if ( V_287 > 0 ) {
for ( V_167 = 0 ; V_167 < V_340 ; V_167 ++ ) {
V_286 = ( V_2 -> V_167 / V_341 [ V_167 ] ) / V_287 ;
if ( V_286 < 0x100 )
break;
}
div = ( unsigned char ) V_286 ;
}
if ( ( V_113 -> V_114 & V_120 ) == 0 ) {
V_297 |= V_342 ;
V_298 |= V_343 ;
V_295 |= V_344 ;
V_2 -> V_7 . V_10 |= V_11 ;
} else
V_2 -> V_7 . V_10 &= ~ V_11 ;
if ( V_113 -> V_115 & V_345 ) {
V_289 |= V_346 ;
V_290 |= V_347 ;
if ( V_113 -> V_115 & V_348 )
V_289 |= V_349 ;
}
if ( V_113 -> V_114 & V_118 ) {
V_289 |= V_350 ;
V_297 |= V_351 ;
}
F_8 ( L_74 ,
V_2 -> V_42 , V_2 -> V_41 , V_2 -> V_40 ) ;
F_8 ( L_75 ,
V_288 , V_289 , V_290 , V_291 , V_292 ) ;
F_8 ( L_76 ,
V_297 , V_298 , V_299 , V_295 , V_296 ) ;
F_8 ( L_77 , V_167 , div , V_167 , div ) ;
F_8 ( L_78 ,
V_113 -> V_352 [ V_353 ] , V_113 -> V_352 [ V_354 ] ,
V_113 -> V_352 [ V_353 ] , V_113 -> V_352 [ V_354 ] ) ;
F_116 ( & V_148 , V_10 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
F_123 ( V_2 , V_284 , ( V_2 -> V_42 & 0x3 ) ) ;
V_294 = F_122 ( V_2 , V_355 ) ;
F_123 ( V_2 , V_355 , 0 ) ;
if ( F_124 ( V_2 , V_356 , V_288 ) )
V_293 = 1 ;
if ( F_124 ( V_2 , V_357 , V_289 ) )
V_293 = 1 ;
if ( F_124 ( V_2 , V_358 , V_290 ) )
V_293 = 1 ;
if ( V_293 ) {
F_129 ( V_2 ) ;
F_123 ( V_2 , V_279 , V_359 ) ;
}
F_123 ( V_2 , V_360 , V_291 ) ;
F_123 ( V_2 , V_361 , V_292 ) ;
F_123 ( V_2 , V_362 , V_297 ) ;
F_123 ( V_2 , V_363 , V_298 ) ;
if ( V_287 > 0 ) {
F_123 ( V_2 , V_364 , V_167 ) ;
F_123 ( V_2 , V_365 , div ) ;
F_123 ( V_2 , V_366 , V_167 ) ;
F_123 ( V_2 , V_367 , div ) ;
}
F_123 ( V_2 , V_368 , V_113 -> V_352 [ V_353 ] ) ;
F_123 ( V_2 , V_369 , V_113 -> V_352 [ V_354 ] ) ;
F_123 ( V_2 , V_370 , V_113 -> V_352 [ V_353 ] ) ;
F_123 ( V_2 , V_371 , V_113 -> V_352 [ V_354 ] ) ;
F_123 ( V_2 , V_372 , V_299 ) ;
V_297 = F_122 ( V_2 , V_373 ) ;
if ( V_297 & V_374 )
V_2 -> V_4 |= V_8 ;
else
V_2 -> V_4 &= ~ V_8 ;
F_123 ( V_2 , V_355 , ( ( V_294 & ~ V_296 ) | V_295 ) ) ;
F_127 ( V_2 -> V_40 ) ;
F_117 ( & V_148 , V_10 ) ;
}
static void F_131 ( struct V_1 * V_2 , int V_93 , int V_92 )
{
unsigned char V_375 , V_376 ;
unsigned long V_10 ;
F_8 ( L_79 ,
V_2 , V_93 , V_92 ) ;
V_375 = 0 ;
V_376 = 0 ;
if ( V_93 > 0 )
V_375 = V_377 ;
if ( V_92 > 0 )
V_376 = V_378 ;
F_116 ( & V_148 , V_10 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
F_123 ( V_2 , V_284 , ( V_2 -> V_42 & 0x03 ) ) ;
if ( V_92 >= 0 )
F_123 ( V_2 , V_379 , V_376 ) ;
if ( V_93 >= 0 )
F_123 ( V_2 , V_373 , V_375 ) ;
F_127 ( V_2 -> V_40 ) ;
F_117 ( & V_148 , V_10 ) ;
}
static int F_132 ( struct V_1 * V_2 )
{
unsigned char V_375 , V_376 ;
unsigned long V_10 ;
int V_4 ;
F_8 ( L_80 , V_2 ) ;
F_116 ( & V_148 , V_10 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
F_123 ( V_2 , V_284 , ( V_2 -> V_42 & 0x03 ) ) ;
V_375 = F_122 ( V_2 , V_373 ) ;
V_376 = F_122 ( V_2 , V_379 ) ;
F_127 ( V_2 -> V_40 ) ;
F_117 ( & V_148 , V_10 ) ;
V_4 = 0 ;
V_4 |= ( V_375 & V_374 ) ? V_8 : 0 ;
V_4 |= ( V_375 & V_380 ) ? V_133 : 0 ;
V_4 |= ( V_375 & V_377 ) ? V_95 : 0 ;
V_4 |= ( V_376 & V_378 ) ? V_94 : 0 ;
#if 0
sigs |= (msvr1 & MSVR1_RI) ? TIOCM_RI : 0;
sigs |= (msvr1 & MSVR1_DSR) ? TIOCM_DSR : 0;
#else
V_4 |= V_134 ;
#endif
return V_4 ;
}
static void F_133 ( struct V_1 * V_2 , int V_381 , int V_30 )
{
unsigned char V_293 ;
unsigned long V_10 ;
F_8 ( L_81 , V_2 , V_381 , V_30 ) ;
V_293 = 0 ;
if ( V_30 == 0 )
V_293 |= V_382 ;
else if ( V_30 > 0 )
V_293 |= V_383 ;
if ( V_381 == 0 )
V_293 |= V_384 ;
else if ( V_381 > 0 )
V_293 |= V_385 ;
F_116 ( & V_148 , V_10 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
F_123 ( V_2 , V_284 , ( V_2 -> V_42 & 0x03 ) ) ;
F_129 ( V_2 ) ;
F_123 ( V_2 , V_279 , V_293 ) ;
F_129 ( V_2 ) ;
F_127 ( V_2 -> V_40 ) ;
F_117 ( & V_148 , V_10 ) ;
}
static void F_134 ( struct V_1 * V_2 , int V_381 , int V_30 )
{
unsigned char V_295 , V_296 ;
unsigned long V_10 ;
F_8 ( L_82 , V_2 , V_381 , V_30 ) ;
V_295 = 0 ;
V_296 = 0 ;
if ( V_30 == 0 )
V_296 |= ( V_386 | V_387 ) ;
else if ( V_30 == 1 )
V_295 |= V_386 ;
else if ( V_30 >= 2 )
V_295 |= V_387 ;
if ( V_381 == 0 )
V_296 |= V_388 ;
else if ( V_381 > 0 )
V_295 |= V_388 ;
F_116 ( & V_148 , V_10 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
F_123 ( V_2 , V_284 , ( V_2 -> V_42 & 0x03 ) ) ;
F_123 ( V_2 , V_355 ,
( ( F_122 ( V_2 , V_355 ) & ~ V_296 ) | V_295 ) ) ;
F_127 ( V_2 -> V_40 ) ;
if ( V_30 > 0 )
F_135 ( V_67 , & V_2 -> V_58 ) ;
F_117 ( & V_148 , V_10 ) ;
}
static void F_136 ( struct V_1 * V_2 )
{
unsigned long V_10 ;
F_8 ( L_83 , V_2 ) ;
F_116 ( & V_148 , V_10 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
F_123 ( V_2 , V_284 , ( V_2 -> V_42 & 0x03 ) ) ;
F_123 ( V_2 , V_355 , 0 ) ;
F_127 ( V_2 -> V_40 ) ;
F_117 ( & V_148 , V_10 ) ;
}
static void F_137 ( struct V_1 * V_2 , int V_60 )
{
unsigned long V_10 ;
F_8 ( L_84 , V_2 , V_60 ) ;
F_116 ( & V_148 , V_10 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
F_123 ( V_2 , V_284 , ( V_2 -> V_42 & 0x03 ) ) ;
F_123 ( V_2 , V_355 ,
( ( F_122 ( V_2 , V_355 ) & ~ V_386 ) |
V_387 ) ) ;
F_127 ( V_2 -> V_40 ) ;
V_2 -> V_389 = V_60 ;
if ( V_60 == 1 )
V_2 -> V_126 . V_390 ++ ;
F_117 ( & V_148 , V_10 ) ;
}
static void F_138 ( struct V_1 * V_2 , int V_121 )
{
struct V_5 * V_6 ;
unsigned long V_10 ;
F_8 ( L_85 , V_2 , V_121 ) ;
if ( V_2 == NULL )
return;
V_6 = F_2 ( & V_2 -> V_7 ) ;
if ( V_6 == NULL )
return;
F_116 ( & V_148 , V_10 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
F_123 ( V_2 , V_284 , ( V_2 -> V_42 & 0x03 ) ) ;
if ( V_121 ) {
if ( V_6 -> V_36 -> V_115 & V_391 ) {
F_129 ( V_2 ) ;
F_123 ( V_2 , V_279 , V_392 ) ;
V_2 -> V_126 . V_393 ++ ;
F_129 ( V_2 ) ;
}
if ( V_6 -> V_36 -> V_114 & V_118 ) {
F_123 ( V_2 , V_362 ,
( F_122 ( V_2 , V_362 ) |
V_351 ) ) ;
F_123 ( V_2 , V_379 , V_378 ) ;
V_2 -> V_126 . V_394 ++ ;
}
} else {
if ( V_6 -> V_36 -> V_115 & V_391 ) {
F_129 ( V_2 ) ;
F_123 ( V_2 , V_279 , V_395 ) ;
V_2 -> V_126 . V_396 ++ ;
F_129 ( V_2 ) ;
}
if ( V_6 -> V_36 -> V_114 & V_118 ) {
F_123 ( V_2 , V_362 ,
( F_122 ( V_2 , V_362 ) & 0xf0 ) ) ;
F_123 ( V_2 , V_379 , 0 ) ;
V_2 -> V_126 . V_397 ++ ;
}
}
F_127 ( V_2 -> V_40 ) ;
F_117 ( & V_148 , V_10 ) ;
F_6 ( V_6 ) ;
}
static void F_139 ( struct V_1 * V_2 , int V_121 )
{
struct V_5 * V_6 ;
unsigned long V_10 ;
F_8 ( L_86 , V_2 , V_121 ) ;
if ( V_2 == NULL )
return;
V_6 = F_2 ( & V_2 -> V_7 ) ;
if ( V_6 == NULL )
return;
F_116 ( & V_148 , V_10 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
F_123 ( V_2 , V_284 , ( V_2 -> V_42 & 0x03 ) ) ;
if ( V_121 ) {
F_129 ( V_2 ) ;
F_123 ( V_2 , V_279 , V_392 ) ;
V_2 -> V_126 . V_393 ++ ;
F_129 ( V_2 ) ;
} else {
F_129 ( V_2 ) ;
F_123 ( V_2 , V_279 , V_395 ) ;
V_2 -> V_126 . V_396 ++ ;
F_129 ( V_2 ) ;
}
F_127 ( V_2 -> V_40 ) ;
F_117 ( & V_148 , V_10 ) ;
F_6 ( V_6 ) ;
}
static void F_140 ( struct V_1 * V_2 )
{
unsigned long V_10 ;
F_8 ( L_87 , V_2 ) ;
if ( V_2 == NULL )
return;
F_116 ( & V_148 , V_10 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
F_123 ( V_2 , V_284 , ( V_2 -> V_42 & 0x03 ) ) ;
F_129 ( V_2 ) ;
F_123 ( V_2 , V_279 , V_398 ) ;
F_129 ( V_2 ) ;
V_2 -> V_30 . V_35 = V_2 -> V_30 . V_34 ;
F_127 ( V_2 -> V_40 ) ;
F_117 ( & V_148 , V_10 ) ;
}
static int F_141 ( struct V_1 * V_2 )
{
F_8 ( L_88 , V_2 ) ;
if ( V_2 == NULL )
return 0 ;
return F_47 ( V_67 , & V_2 -> V_58 ) ? 1 : 0 ;
}
static void V_206 ( struct V_136 * V_137 , unsigned int V_146 )
{
unsigned char V_399 ;
F_8 ( L_89 , V_137 , V_146 ) ;
F_83 ( & V_148 ) ;
F_87 ( V_400 , V_146 ) ;
V_399 = F_84 ( V_146 + V_273 ) ;
if ( V_137 -> V_49 > 4 ) {
F_87 ( ( V_400 + 0x80 ) , V_146 ) ;
V_399 |= F_84 ( V_146 + V_273 ) ;
}
if ( V_399 & V_401 )
F_142 ( V_137 , V_146 ) ;
else if ( V_399 & V_402 )
F_143 ( V_137 , V_146 ) ;
else if ( V_399 & V_403 )
F_144 ( V_137 , V_146 ) ;
F_85 ( & V_148 ) ;
}
static void V_230 ( struct V_136 * V_137 , unsigned int V_146 )
{
unsigned char V_399 ;
F_8 ( L_90 , V_137 , V_146 ) ;
F_87 ( V_400 , V_146 ) ;
V_399 = F_84 ( V_146 + V_273 ) ;
F_87 ( ( V_400 + 0x80 ) , V_146 ) ;
V_399 |= F_84 ( V_146 + V_273 ) ;
if ( V_399 & V_401 )
F_142 ( V_137 , V_146 ) ;
else if ( V_399 & V_402 )
F_143 ( V_137 , V_146 ) ;
else if ( V_399 & V_403 )
F_144 ( V_137 , V_146 ) ;
}
static int F_145 ( struct V_1 * V_2 , int V_71 )
{
if ( V_2 -> V_389 == 1 ) {
F_87 ( ( V_357 + V_2 -> V_272 ) , V_71 ) ;
F_87 ( ( F_84 ( V_71 + V_273 ) | V_404 ) ,
( V_71 + V_273 ) ) ;
F_87 ( ( V_405 + V_2 -> V_272 ) , V_71 ) ;
F_87 ( V_406 , ( V_71 + V_273 ) ) ;
F_87 ( V_407 , ( V_71 + V_273 ) ) ;
F_87 ( ( V_355 + V_2 -> V_272 ) , V_71 ) ;
F_87 ( ( F_84 ( V_71 + V_273 ) & ~ ( V_386 | V_387 ) ) ,
( V_71 + V_273 ) ) ;
return 1 ;
} else if ( V_2 -> V_389 > 1 ) {
F_87 ( ( V_405 + V_2 -> V_272 ) , V_71 ) ;
F_87 ( V_406 , ( V_71 + V_273 ) ) ;
F_87 ( V_408 , ( V_71 + V_273 ) ) ;
V_2 -> V_389 = - 1 ;
return 1 ;
} else {
F_87 ( ( V_357 + V_2 -> V_272 ) , V_71 ) ;
F_87 ( ( F_84 ( V_71 + V_273 ) & ~ V_404 ) ,
( V_71 + V_273 ) ) ;
V_2 -> V_389 = 0 ;
}
return 0 ;
}
static void F_143 ( struct V_136 * V_137 , int V_71 )
{
struct V_1 * V_2 ;
int V_60 , V_61 ;
char * V_34 , * V_35 ;
unsigned char V_409 , V_294 ;
struct V_5 * V_6 ;
F_8 ( L_91 , V_137 , V_71 ) ;
V_409 = F_84 ( V_71 + V_410 ) ;
if ( ( ( V_409 & V_137 -> V_231 ) != 0 ) ||
( ( V_409 & V_411 ) != V_412 ) ) {
F_10 ( L_92 , V_409 ) ;
return;
}
V_2 = V_137 -> V_50 [ ( V_409 >> 3 ) ] ;
if ( V_2 -> V_389 != 0 )
if ( F_145 ( V_2 , V_71 ) )
goto V_413;
V_34 = V_2 -> V_30 . V_34 ;
V_35 = V_2 -> V_30 . V_35 ;
V_60 = ( V_34 >= V_35 ) ? ( V_34 - V_35 ) : ( V_32 - ( V_35 - V_34 ) ) ;
if ( ( V_60 == 0 ) || ( ( V_60 < V_414 ) &&
( F_47 ( V_63 , & V_2 -> V_58 ) == 0 ) ) ) {
F_135 ( V_63 , & V_2 -> V_58 ) ;
V_6 = F_2 ( & V_2 -> V_7 ) ;
if ( V_6 ) {
F_29 ( V_6 ) ;
F_6 ( V_6 ) ;
}
}
if ( V_60 == 0 ) {
F_87 ( ( V_355 + V_2 -> V_272 ) , V_71 ) ;
V_294 = F_84 ( V_71 + V_273 ) ;
if ( V_294 & V_386 ) {
V_294 = ( V_294 & ~ V_386 ) | V_387 ;
} else {
V_294 &= ~ ( V_386 | V_387 ) ;
F_42 ( V_67 , & V_2 -> V_58 ) ;
}
F_87 ( V_294 , ( V_71 + V_273 ) ) ;
} else {
V_60 = F_41 ( V_60 , V_81 ) ;
V_2 -> V_126 . V_127 += V_60 ;
V_61 = F_146 (unsigned int, len,
(portp->tx.buf + STL_TXBUFSIZE) - tail) ;
F_87 ( ( V_405 + V_2 -> V_272 ) , V_71 ) ;
F_147 ( ( V_71 + V_273 ) , V_35 , V_61 ) ;
V_60 -= V_61 ;
V_35 += V_61 ;
if ( V_35 >= ( V_2 -> V_30 . V_31 + V_32 ) )
V_35 = V_2 -> V_30 . V_31 ;
if ( V_60 > 0 ) {
F_147 ( ( V_71 + V_273 ) , V_35 , V_60 ) ;
V_35 += V_60 ;
}
V_2 -> V_30 . V_35 = V_35 ;
}
V_413:
F_87 ( ( V_415 + V_2 -> V_272 ) , V_71 ) ;
F_87 ( 0 , ( V_71 + V_273 ) ) ;
}
static void F_142 ( struct V_136 * V_137 , int V_71 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
unsigned int V_409 , V_60 , V_416 ;
unsigned char V_176 ;
char V_64 ;
F_8 ( L_93 , V_137 , V_71 ) ;
V_409 = F_84 ( V_71 + V_417 ) ;
if ( ( V_409 & V_137 -> V_231 ) != 0 ) {
F_10 ( L_94 , V_409 ) ;
return;
}
V_2 = V_137 -> V_50 [ ( V_409 >> 3 ) ] ;
V_6 = F_2 ( & V_2 -> V_7 ) ;
if ( ( V_409 & V_411 ) == V_418 ) {
F_87 ( ( V_419 + V_2 -> V_272 ) , V_71 ) ;
V_60 = F_84 ( V_71 + V_273 ) ;
if ( V_6 == NULL || ( V_416 = F_148 ( V_6 , V_60 ) ) == 0 ) {
V_60 = F_146 (unsigned int, len, sizeof(stl_unwanted)) ;
F_87 ( ( V_420 + V_2 -> V_272 ) , V_71 ) ;
F_149 ( ( V_71 + V_273 ) , & V_421 [ 0 ] , V_60 ) ;
V_2 -> V_126 . V_422 += V_60 ;
V_2 -> V_126 . V_128 += V_60 ;
} else {
V_60 = F_41 ( V_60 , V_416 ) ;
if ( V_60 > 0 ) {
unsigned char * V_423 ;
F_87 ( ( V_420 + V_2 -> V_272 ) , V_71 ) ;
F_150 ( V_6 , & V_423 , V_60 ) ;
F_149 ( ( V_71 + V_273 ) , V_423 , V_60 ) ;
F_151 ( V_6 ) ;
V_2 -> V_126 . V_128 += V_60 ;
}
}
} else if ( ( V_409 & V_411 ) == V_424 ) {
F_87 ( ( V_420 + V_2 -> V_272 ) , V_71 ) ;
V_176 = F_84 ( V_71 + V_273 ) ;
V_64 = F_84 ( V_71 + V_273 ) ;
if ( V_176 & V_302 )
V_2 -> V_126 . V_130 ++ ;
if ( V_176 & V_303 )
V_2 -> V_126 . V_129 ++ ;
if ( V_176 & V_304 )
V_2 -> V_126 . V_132 ++ ;
if ( V_176 & V_307 )
V_2 -> V_126 . V_131 ++ ;
if ( V_176 & V_425 ) {
if ( ( V_176 & V_425 ) == V_426 )
V_2 -> V_126 . V_427 ++ ;
if ( ( V_176 & V_425 ) == V_428 )
V_2 -> V_126 . V_429 ++ ;
goto V_430;
}
if ( V_6 != NULL && ( V_2 -> V_300 & V_176 ) == 0 ) {
if ( V_2 -> V_309 & V_176 ) {
if ( V_176 & V_307 ) {
V_176 = V_431 ;
if ( V_2 -> V_7 . V_10 & V_432 ) {
F_152 ( V_6 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
}
} else if ( V_176 & V_302 )
V_176 = V_433 ;
else if ( V_176 & V_303 )
V_176 = V_434 ;
else if( V_176 & V_304 )
V_176 = V_435 ;
else
V_176 = 0 ;
} else
V_176 = 0 ;
F_153 ( V_6 , V_64 , V_176 ) ;
F_151 ( V_6 ) ;
}
} else {
F_10 ( L_94 , V_409 ) ;
F_6 ( V_6 ) ;
return;
}
V_430:
F_6 ( V_6 ) ;
F_87 ( ( V_415 + V_2 -> V_272 ) , V_71 ) ;
F_87 ( 0 , ( V_71 + V_273 ) ) ;
}
static void F_144 ( struct V_136 * V_137 , int V_71 )
{
struct V_1 * V_2 ;
unsigned int V_409 ;
unsigned char V_436 ;
F_8 ( L_95 , V_137 ) ;
V_409 = F_84 ( V_71 + V_437 ) ;
if ( ( ( V_409 & V_137 -> V_231 ) != 0 ) ||
( ( V_409 & V_411 ) != V_438 ) ) {
F_10 ( L_96 , V_409 ) ;
return;
}
V_2 = V_137 -> V_50 [ ( V_409 >> 3 ) ] ;
F_87 ( ( V_439 + V_2 -> V_272 ) , V_71 ) ;
V_436 = F_84 ( V_71 + V_273 ) ;
if ( V_436 & V_440 ) {
F_1 ( V_2 ) ;
V_2 -> V_126 . V_441 ++ ;
}
F_87 ( ( V_415 + V_2 -> V_272 ) , V_71 ) ;
F_87 ( 0 , ( V_71 + V_273 ) ) ;
}
static int F_154 ( struct V_1 * V_2 , int V_271 )
{
F_87 ( ( V_271 | V_2 -> V_272 ) , ( V_2 -> V_71 + V_442 ) ) ;
return F_84 ( V_2 -> V_71 + V_443 ) ;
}
static void F_155 ( struct V_1 * V_2 , int V_271 , int V_274 )
{
F_87 ( ( V_271 | V_2 -> V_272 ) , ( V_2 -> V_71 + V_442 ) ) ;
F_87 ( V_274 , ( V_2 -> V_71 + V_443 ) ) ;
}
static int F_156 ( struct V_1 * V_2 , int V_271 , int V_274 )
{
F_87 ( ( V_271 | V_2 -> V_272 ) , ( V_2 -> V_71 + V_442 ) ) ;
if ( F_84 ( V_2 -> V_71 + V_443 ) != V_274 ) {
F_87 ( V_274 , ( V_2 -> V_71 + V_443 ) ) ;
return 1 ;
}
return 0 ;
}
static int F_157 ( struct V_1 * V_2 , int V_271 )
{
F_87 ( V_271 , ( V_2 -> V_71 + V_442 ) ) ;
return F_84 ( V_2 -> V_71 + V_443 ) ;
}
static int F_158 ( struct V_24 * V_25 , struct V_136 * V_137 )
{
int V_163 , V_16 ;
int V_276 , V_71 ;
F_8 ( L_97 , V_25 , V_137 ) ;
F_126 ( V_137 -> V_40 , V_137 -> V_227 ) ;
V_163 = 0 ;
V_276 = ( V_137 -> V_49 + 4 ) / V_444 ;
if ( V_25 -> V_19 == V_223 )
F_87 ( V_137 -> V_227 , V_25 -> V_154 ) ;
for ( V_16 = 0 ; V_16 < V_276 ; V_16 ++ ) {
V_71 = V_137 -> V_146 + ( V_16 * 4 ) ;
F_87 ( V_445 , ( V_71 + V_442 ) ) ;
F_87 ( V_446 , ( V_71 + V_443 ) ) ;
F_87 ( V_447 , ( V_71 + V_442 ) ) ;
if ( F_84 ( V_71 + V_443 ) != 0 ) {
F_10 ( L_98
L_71 ,
V_137 -> V_40 , V_137 -> V_41 , V_16 ) ;
continue;
}
V_163 |= ( 0x1 << V_16 ) ;
F_87 ( V_448 , ( V_71 + V_442 ) ) ;
F_87 ( V_449 , ( V_71 + V_443 ) ) ;
F_87 ( V_450 , ( V_71 + V_442 ) ) ;
F_87 ( 0xff , ( V_71 + V_443 ) ) ;
}
F_127 ( V_137 -> V_40 ) ;
return V_163 ;
}
static void F_159 ( struct V_24 * V_25 , struct V_136 * V_137 , struct V_1 * V_2 )
{
F_8 ( L_99 , V_25 ,
V_137 , V_2 ) ;
if ( ( V_25 == NULL ) || ( V_137 == NULL ) ||
( V_2 == NULL ) )
return;
V_2 -> V_71 = V_137 -> V_146 + ( ( V_2 -> V_42 < 8 ) ? 0 : 4 ) ;
V_2 -> V_272 = ( V_2 -> V_42 & 0x07 ) << 4 ;
V_2 -> V_227 = V_137 -> V_227 ;
V_2 -> V_125 = 0x1 ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
F_155 ( V_2 , V_451 , V_452 ) ;
F_127 ( V_2 -> V_40 ) ;
}
static void F_160 ( struct V_1 * V_2 , struct V_111 * V_113 )
{
struct V_24 * V_25 ;
unsigned long V_10 ;
unsigned int V_287 ;
unsigned char V_453 , V_454 , V_455 , V_167 ;
unsigned char V_456 , V_457 , V_458 , V_459 ;
V_453 = 0 ;
V_454 = 0 ;
V_455 = 0 ;
V_167 = 0 ;
V_458 = 0 ;
V_456 = 0 ;
V_457 = 0 ;
V_25 = V_46 [ V_2 -> V_40 ] ;
if ( V_25 == NULL )
return;
V_2 -> V_300 = 0 ;
if ( V_113 -> V_115 & V_301 )
V_2 -> V_300 |= ( V_460 | V_461 |
V_462 ) ;
if ( V_113 -> V_115 & V_306 )
V_2 -> V_300 |= V_463 ;
V_2 -> V_309 = V_462 ;
if ( V_113 -> V_115 & ( V_310 | V_311 ) )
V_2 -> V_309 |= ( V_460 | V_461 ) ;
if ( V_113 -> V_115 & V_312 )
V_2 -> V_309 |= V_463 ;
switch ( V_113 -> V_114 & V_313 ) {
case V_314 :
V_454 |= V_464 ;
break;
case V_316 :
V_454 |= V_465 ;
break;
case V_318 :
V_454 |= V_466 ;
break;
default:
V_454 |= V_467 ;
break;
}
if ( V_113 -> V_114 & V_321 )
V_455 |= V_468 ;
else
V_455 |= V_469 ;
if ( V_113 -> V_114 & V_324 ) {
if ( V_113 -> V_114 & V_325 )
V_454 |= ( V_470 | V_471 ) ;
else
V_454 |= ( V_470 | V_472 ) ;
} else
V_454 |= V_473 ;
V_454 |= V_474 ;
V_455 |= V_475 ;
V_287 = V_113 -> V_114 & V_116 ;
if ( V_287 & V_117 ) {
V_287 &= ~ V_117 ;
if ( ( V_287 < 1 ) || ( V_287 > 4 ) )
V_113 -> V_114 &= ~ V_117 ;
else
V_287 += 15 ;
}
V_287 = V_331 [ V_287 ] ;
if ( ( V_113 -> V_114 & V_116 ) == V_332 ) {
if ( ( V_2 -> V_7 . V_10 & V_333 ) == V_334 )
V_287 = 57600 ;
else if ( ( V_2 -> V_7 . V_10 & V_333 ) == V_335 )
V_287 = 115200 ;
else if ( ( V_2 -> V_7 . V_10 & V_333 ) == V_336 )
V_287 = 230400 ;
else if ( ( V_2 -> V_7 . V_10 & V_333 ) == V_337 )
V_287 = 460800 ;
else if ( ( V_2 -> V_7 . V_10 & V_333 ) == V_338 )
V_287 = ( V_2 -> V_72 / V_2 -> V_75 ) ;
}
if ( V_287 > V_476 )
V_287 = V_476 ;
if ( V_287 > 0 )
for ( V_167 = 0 ; V_167 < V_477 ; V_167 ++ )
if ( V_287 <= V_478 [ V_167 ] )
break;
if ( V_113 -> V_114 & V_120 ) {
V_2 -> V_7 . V_10 &= ~ V_11 ;
} else {
V_458 |= V_479 ;
V_456 |= V_480 ;
V_2 -> V_7 . V_10 |= V_11 ;
}
if ( V_113 -> V_115 & V_345 ) {
V_453 |= V_481 | V_482 ;
V_456 |= V_483 ;
} else
V_457 |= V_483 ;
if ( V_113 -> V_115 & V_391 )
V_453 |= V_484 ;
if ( V_113 -> V_114 & V_118 ) {
V_455 |= V_485 ;
V_454 |= V_486 ;
}
F_8 ( L_74 ,
V_2 -> V_42 , V_2 -> V_41 , V_2 -> V_40 ) ;
F_8 ( L_100 , V_453 , V_454 , V_455 , V_167 ) ;
F_8 ( L_101 , V_458 , V_456 , V_457 ) ;
F_8 ( L_78 ,
V_113 -> V_352 [ V_353 ] , V_113 -> V_352 [ V_354 ] ,
V_113 -> V_352 [ V_353 ] , V_113 -> V_352 [ V_354 ] ) ;
F_116 ( & V_148 , V_10 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
F_155 ( V_2 , V_487 , 0 ) ;
F_156 ( V_2 , V_488 , V_453 ) ;
F_156 ( V_2 , V_489 , V_454 ) ;
F_155 ( V_2 , V_445 , V_490 ) ;
F_156 ( V_2 , V_491 , V_455 ) ;
F_156 ( V_2 , V_492 ,
( ( F_154 ( V_2 , V_492 ) & ~ V_493 ) | V_458 ) ) ;
if ( V_287 > 0 ) {
F_155 ( V_2 , V_494 , V_167 ) ;
F_155 ( V_2 , V_495 , V_167 ) ;
}
F_155 ( V_2 , V_496 , V_113 -> V_352 [ V_353 ] ) ;
F_155 ( V_2 , V_497 , V_113 -> V_352 [ V_354 ] ) ;
V_459 = F_154 ( V_2 , V_498 ) ;
if ( V_459 & V_499 )
V_2 -> V_4 &= ~ V_8 ;
else
V_2 -> V_4 |= V_8 ;
V_2 -> V_500 = ( V_2 -> V_500 & ~ V_457 ) | V_456 ;
F_155 ( V_2 , V_487 , V_2 -> V_500 ) ;
F_127 ( V_2 -> V_40 ) ;
F_117 ( & V_148 , V_10 ) ;
}
static void F_161 ( struct V_1 * V_2 , int V_93 , int V_92 )
{
unsigned char V_501 , V_502 ;
unsigned long V_10 ;
F_8 ( L_102 , V_2 ,
V_93 , V_92 ) ;
V_501 = 0 ;
V_502 = 0 ;
if ( V_93 == 0 )
V_502 |= V_503 ;
else if ( V_93 > 0 )
V_501 |= V_503 ;
if ( V_92 == 0 )
V_502 |= V_504 ;
else if ( V_92 > 0 )
V_501 |= V_504 ;
F_116 ( & V_148 , V_10 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
F_155 ( V_2 , V_492 ,
( ( F_154 ( V_2 , V_492 ) & ~ V_502 ) | V_501 ) ) ;
F_127 ( V_2 -> V_40 ) ;
F_117 ( & V_148 , V_10 ) ;
}
static int F_162 ( struct V_1 * V_2 )
{
unsigned char V_459 ;
unsigned long V_10 ;
int V_4 ;
F_8 ( L_103 , V_2 ) ;
F_116 ( & V_148 , V_10 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
V_459 = F_154 ( V_2 , V_498 ) ;
F_127 ( V_2 -> V_40 ) ;
F_117 ( & V_148 , V_10 ) ;
V_4 = 0 ;
V_4 |= ( V_459 & V_499 ) ? 0 : V_8 ;
V_4 |= ( V_459 & V_505 ) ? 0 : V_133 ;
V_4 |= ( V_459 & V_503 ) ? 0 : V_95 ;
V_4 |= ( V_459 & V_504 ) ? 0 : V_94 ;
V_4 |= V_134 ;
return V_4 ;
}
static void F_163 ( struct V_1 * V_2 , int V_381 , int V_30 )
{
unsigned char V_293 ;
unsigned long V_10 ;
F_8 ( L_104 , V_2 , V_381 , V_30 ) ;
V_293 = V_2 -> V_506 ;
if ( V_30 == 0 )
V_293 &= ~ V_507 ;
else if ( V_30 > 0 )
V_293 |= V_507 ;
if ( V_381 == 0 )
V_293 &= ~ V_508 ;
else if ( V_381 > 0 )
V_293 |= V_508 ;
F_116 ( & V_148 , V_10 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
F_155 ( V_2 , V_445 , V_293 ) ;
F_127 ( V_2 -> V_40 ) ;
V_2 -> V_506 = V_293 ;
F_117 ( & V_148 , V_10 ) ;
}
static void F_164 ( struct V_1 * V_2 , int V_381 , int V_30 )
{
unsigned char V_500 ;
unsigned long V_10 ;
F_8 ( L_105 , V_2 , V_381 , V_30 ) ;
V_500 = V_2 -> V_500 ;
if ( V_30 == 0 )
V_500 &= ~ V_509 ;
else if ( V_30 == 1 )
V_500 |= V_509 ;
if ( V_381 == 0 )
V_500 &= ~ ( V_510 | V_511 | V_512 ) ;
else if ( V_381 > 0 )
V_500 |= V_510 | V_511 | V_512 ;
F_116 ( & V_148 , V_10 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
F_155 ( V_2 , V_487 , V_500 ) ;
F_127 ( V_2 -> V_40 ) ;
V_2 -> V_500 = V_500 ;
if ( V_30 > 0 )
F_135 ( V_67 , & V_2 -> V_58 ) ;
F_117 ( & V_148 , V_10 ) ;
}
static void F_165 ( struct V_1 * V_2 )
{
unsigned long V_10 ;
F_8 ( L_106 , V_2 ) ;
F_116 ( & V_148 , V_10 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
V_2 -> V_500 = 0 ;
F_155 ( V_2 , V_487 , 0 ) ;
F_127 ( V_2 -> V_40 ) ;
F_117 ( & V_148 , V_10 ) ;
}
static void F_166 ( struct V_1 * V_2 , int V_60 )
{
unsigned long V_10 ;
F_8 ( L_107 , V_2 , V_60 ) ;
F_116 ( & V_148 , V_10 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
if ( V_60 == 1 ) {
F_155 ( V_2 , V_445 , V_513 ) ;
V_2 -> V_126 . V_390 ++ ;
} else
F_155 ( V_2 , V_445 , V_514 ) ;
F_127 ( V_2 -> V_40 ) ;
F_117 ( & V_148 , V_10 ) ;
}
static void F_167 ( struct V_1 * V_2 , int V_121 )
{
struct V_5 * V_6 ;
unsigned long V_10 ;
unsigned char V_453 ;
F_8 ( L_108 , V_2 , V_121 ) ;
if ( V_2 == NULL )
return;
V_6 = F_2 ( & V_2 -> V_7 ) ;
if ( V_6 == NULL )
return;
F_116 ( & V_148 , V_10 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
if ( V_121 ) {
if ( V_6 -> V_36 -> V_115 & V_391 ) {
V_453 = F_154 ( V_2 , V_488 ) ;
F_155 ( V_2 , V_488 , ( V_453 & ~ V_515 ) ) ;
F_155 ( V_2 , V_445 , V_516 ) ;
V_453 |= V_484 ;
V_2 -> V_126 . V_393 ++ ;
F_168 ( V_2 ) ;
F_155 ( V_2 , V_488 , V_453 ) ;
}
if ( V_6 -> V_36 -> V_114 & V_118 ) {
F_155 ( V_2 , V_489 ,
( F_154 ( V_2 , V_489 ) | V_486 ) ) ;
F_155 ( V_2 , V_492 ,
( F_154 ( V_2 , V_492 ) | V_517 ) ) ;
V_2 -> V_126 . V_394 ++ ;
}
} else {
if ( V_6 -> V_36 -> V_115 & V_391 ) {
V_453 = F_154 ( V_2 , V_488 ) ;
F_155 ( V_2 , V_488 , ( V_453 & ~ V_515 ) ) ;
F_155 ( V_2 , V_445 , V_518 ) ;
V_453 &= ~ V_484 ;
V_2 -> V_126 . V_396 ++ ;
F_168 ( V_2 ) ;
F_155 ( V_2 , V_488 , V_453 ) ;
}
if ( V_6 -> V_36 -> V_114 & V_118 ) {
F_155 ( V_2 , V_489 ,
( F_154 ( V_2 , V_489 ) & ~ V_486 ) ) ;
F_155 ( V_2 , V_492 ,
( F_154 ( V_2 , V_492 ) & ~ V_517 ) ) ;
V_2 -> V_126 . V_397 ++ ;
}
}
F_127 ( V_2 -> V_40 ) ;
F_117 ( & V_148 , V_10 ) ;
F_6 ( V_6 ) ;
}
static void F_169 ( struct V_1 * V_2 , int V_121 )
{
struct V_5 * V_6 ;
unsigned long V_10 ;
unsigned char V_453 ;
F_8 ( L_109 , V_2 , V_121 ) ;
if ( V_2 == NULL )
return;
V_6 = F_2 ( & V_2 -> V_7 ) ;
if ( V_6 == NULL )
return;
F_116 ( & V_148 , V_10 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
if ( V_121 ) {
V_453 = F_154 ( V_2 , V_488 ) ;
F_155 ( V_2 , V_488 , ( V_453 & ~ V_515 ) ) ;
F_155 ( V_2 , V_445 , V_516 ) ;
V_453 |= V_484 ;
V_2 -> V_126 . V_393 ++ ;
F_168 ( V_2 ) ;
F_155 ( V_2 , V_488 , V_453 ) ;
} else {
V_453 = F_154 ( V_2 , V_488 ) ;
F_155 ( V_2 , V_488 , ( V_453 & ~ V_515 ) ) ;
F_155 ( V_2 , V_445 , V_518 ) ;
V_453 &= ~ V_484 ;
V_2 -> V_126 . V_396 ++ ;
F_168 ( V_2 ) ;
F_155 ( V_2 , V_488 , V_453 ) ;
}
F_127 ( V_2 -> V_40 ) ;
F_117 ( & V_148 , V_10 ) ;
F_6 ( V_6 ) ;
}
static void F_170 ( struct V_1 * V_2 )
{
unsigned long V_10 ;
F_8 ( L_110 , V_2 ) ;
if ( V_2 == NULL )
return;
F_116 ( & V_148 , V_10 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
F_155 ( V_2 , V_445 , V_519 ) ;
F_155 ( V_2 , V_445 , V_2 -> V_506 ) ;
F_127 ( V_2 -> V_40 ) ;
V_2 -> V_30 . V_35 = V_2 -> V_30 . V_34 ;
F_117 ( & V_148 , V_10 ) ;
}
static int F_171 ( struct V_1 * V_2 )
{
unsigned long V_10 ;
unsigned char V_520 ;
F_8 ( L_111 , V_2 ) ;
if ( V_2 == NULL )
return 0 ;
if ( F_47 ( V_67 , & V_2 -> V_58 ) )
return 1 ;
F_116 ( & V_148 , V_10 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
V_520 = F_154 ( V_2 , V_521 ) ;
F_127 ( V_2 -> V_40 ) ;
F_117 ( & V_148 , V_10 ) ;
return ( V_520 & V_522 ) ? 0 : 1 ;
}
static void F_168 ( struct V_1 * V_2 )
{
int V_16 ;
F_8 ( L_112 , V_2 ) ;
if ( V_2 == NULL )
return;
for ( V_16 = 0 ; V_16 < 20 ; V_16 ++ )
F_157 ( V_2 , V_447 ) ;
}
static void F_172 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
unsigned char V_453 ;
V_453 = F_154 ( V_2 , V_488 ) ;
F_155 ( V_2 , V_488 , ( V_453 & ~ V_515 ) ) ;
F_155 ( V_2 , V_445 , V_523 ) ;
F_168 ( V_2 ) ;
F_155 ( V_2 , V_488 , V_453 ) ;
F_42 ( V_524 , & V_2 -> V_58 ) ;
}
static void V_205 ( struct V_136 * V_137 , unsigned int V_146 )
{
struct V_1 * V_2 ;
unsigned int V_525 ;
F_83 ( & V_148 ) ;
F_87 ( 0 , ( V_146 + 1 ) ) ;
V_525 = F_84 ( V_146 + V_526 ) ;
V_2 = V_137 -> V_50 [ ( V_525 & V_527 ) + ( ( V_146 & 0x4 ) << 1 ) ] ;
if ( V_525 & V_528 )
F_173 ( V_2 , V_525 ) ;
else if ( V_525 & V_529 )
F_174 ( V_2 ) ;
else
F_175 ( V_2 , V_525 ) ;
F_85 ( & V_148 ) ;
}
static void F_174 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
unsigned int V_71 ;
unsigned char V_453 ;
int V_60 , V_61 ;
char * V_34 , * V_35 ;
F_8 ( L_113 , V_2 ) ;
V_71 = V_2 -> V_71 ;
V_34 = V_2 -> V_30 . V_34 ;
V_35 = V_2 -> V_30 . V_35 ;
V_60 = ( V_34 >= V_35 ) ? ( V_34 - V_35 ) : ( V_32 - ( V_35 - V_34 ) ) ;
if ( ( V_60 == 0 ) || ( ( V_60 < V_414 ) &&
( F_47 ( V_63 , & V_2 -> V_58 ) == 0 ) ) ) {
F_135 ( V_63 , & V_2 -> V_58 ) ;
V_6 = F_2 ( & V_2 -> V_7 ) ;
if ( V_6 ) {
F_29 ( V_6 ) ;
F_6 ( V_6 ) ;
}
}
if ( V_60 == 0 ) {
F_87 ( ( V_488 | V_2 -> V_272 ) , ( V_71 + V_442 ) ) ;
V_453 = F_84 ( V_71 + V_443 ) ;
if ( ( V_453 & V_530 ) == V_531 ) {
V_2 -> V_500 &= ~ V_509 ;
F_87 ( ( V_487 | V_2 -> V_272 ) , ( V_71 + V_442 ) ) ;
F_87 ( V_2 -> V_500 , ( V_71 + V_443 ) ) ;
F_42 ( V_67 , & V_2 -> V_58 ) ;
} else {
V_453 |= ( ( V_453 & ~ V_530 ) | V_531 ) ;
F_87 ( V_453 , ( V_71 + V_443 ) ) ;
}
} else {
V_60 = F_41 ( V_60 , V_83 ) ;
V_2 -> V_126 . V_127 += V_60 ;
V_61 = F_146 (unsigned int, len,
(portp->tx.buf + STL_TXBUFSIZE) - tail) ;
F_87 ( V_532 , ( V_71 + V_442 ) ) ;
F_147 ( ( V_71 + V_443 ) , V_35 , V_61 ) ;
V_60 -= V_61 ;
V_35 += V_61 ;
if ( V_35 >= ( V_2 -> V_30 . V_31 + V_32 ) )
V_35 = V_2 -> V_30 . V_31 ;
if ( V_60 > 0 ) {
F_147 ( ( V_71 + V_443 ) , V_35 , V_60 ) ;
V_35 += V_60 ;
}
V_2 -> V_30 . V_35 = V_35 ;
}
}
static void F_173 ( struct V_1 * V_2 , unsigned int V_525 )
{
struct V_5 * V_6 ;
unsigned int V_60 , V_416 , V_71 ;
F_8 ( L_114 , V_2 , V_525 ) ;
V_6 = F_2 ( & V_2 -> V_7 ) ;
V_71 = V_2 -> V_71 ;
F_87 ( V_533 , ( V_71 + V_442 ) ) ;
V_60 = F_84 ( V_71 + V_443 ) + 1 ;
if ( ( V_525 & V_534 ) == V_528 ) {
if ( V_6 == NULL || ( V_416 = F_148 ( V_6 , V_60 ) ) == 0 ) {
V_60 = F_146 (unsigned int, len, sizeof(stl_unwanted)) ;
F_87 ( V_535 , ( V_71 + V_442 ) ) ;
F_149 ( ( V_71 + V_443 ) , & V_421 [ 0 ] , V_60 ) ;
V_2 -> V_126 . V_422 += V_60 ;
V_2 -> V_126 . V_128 += V_60 ;
} else {
V_60 = F_41 ( V_60 , V_416 ) ;
if ( V_60 > 0 ) {
unsigned char * V_423 ;
F_87 ( V_535 , ( V_71 + V_442 ) ) ;
F_150 ( V_6 , & V_423 , V_60 ) ;
F_149 ( ( V_71 + V_443 ) , V_423 , V_60 ) ;
F_151 ( V_6 ) ;
V_2 -> V_126 . V_128 += V_60 ;
}
}
} else {
F_176 ( V_2 ) ;
}
if ( F_47 ( V_524 , & V_2 -> V_58 ) ) {
if ( ( V_6 != NULL ) &&
( V_6 -> V_36 != NULL ) &&
( V_6 -> V_36 -> V_115 & V_348 ) ) {
F_172 ( V_2 , V_6 ) ;
}
}
F_6 ( V_6 ) ;
}
static void F_177 ( struct V_1 * V_2 , unsigned char V_176 , char V_64 )
{
struct V_5 * V_6 ;
unsigned int V_71 ;
V_6 = F_2 ( & V_2 -> V_7 ) ;
V_71 = V_2 -> V_71 ;
if ( V_176 & V_460 )
V_2 -> V_126 . V_130 ++ ;
if ( V_176 & V_461 )
V_2 -> V_126 . V_129 ++ ;
if ( V_176 & V_462 )
V_2 -> V_126 . V_132 ++ ;
if ( V_176 & V_463 )
V_2 -> V_126 . V_131 ++ ;
if ( ( V_6 != NULL ) &&
( ( V_2 -> V_300 & V_176 ) == 0 ) ) {
if ( V_2 -> V_309 & V_176 ) {
if ( V_176 & V_463 ) {
V_176 = V_431 ;
if ( V_2 -> V_7 . V_10 & V_432 ) {
F_152 ( V_6 ) ;
F_126 ( V_2 -> V_40 , V_2 -> V_227 ) ;
}
} else if ( V_176 & V_460 )
V_176 = V_433 ;
else if ( V_176 & V_461 )
V_176 = V_434 ;
else if( V_176 & V_462 )
V_176 = V_435 ;
else
V_176 = 0 ;
} else
V_176 = 0 ;
F_153 ( V_6 , V_64 , V_176 ) ;
F_151 ( V_6 ) ;
if ( V_176 == 0 )
V_2 -> V_126 . V_128 ++ ;
}
F_6 ( V_6 ) ;
}
static void F_176 ( struct V_1 * V_2 )
{
unsigned char V_176 , V_454 ;
char V_64 ;
V_454 = F_154 ( V_2 , V_489 ) ;
F_155 ( V_2 , V_489 , ( V_454 & ~ V_474 ) ) ;
while ( ( V_176 = F_154 ( V_2 , V_521 ) ) & V_536 ) {
F_155 ( V_2 , V_445 , V_537 ) ;
V_64 = F_154 ( V_2 , V_538 ) ;
F_177 ( V_2 , V_176 , V_64 ) ;
}
F_155 ( V_2 , V_489 , V_454 ) ;
}
static void F_175 ( struct V_1 * V_2 , unsigned int V_525 )
{
unsigned char V_539 , V_459 , V_540 ;
F_8 ( L_115 , V_2 , V_525 ) ;
V_539 = F_157 ( V_2 , V_541 ) ;
switch ( V_539 & V_542 ) {
case V_543 :
V_459 = F_154 ( V_2 , V_498 ) ;
if ( V_459 & V_544 ) {
F_1 ( V_2 ) ;
V_2 -> V_126 . V_441 ++ ;
}
break;
case V_545 :
V_540 = F_154 ( V_2 , V_546 ) ;
if ( V_540 & V_547 ) {
F_135 ( V_524 , & V_2 -> V_58 ) ;
V_2 -> V_126 . V_429 ++ ;
}
if ( V_540 & V_548 ) {
F_42 ( V_524 , & V_2 -> V_58 ) ;
V_2 -> V_126 . V_427 ++ ;
}
break;
case V_549 :
F_155 ( V_2 , V_445 , V_550 ) ;
F_176 ( V_2 ) ;
break;
default:
break;
}
}
static void F_178 ( void )
{
struct V_24 * V_25 ;
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < V_44 ; V_16 ++ ) {
if ( ( V_25 = V_46 [ V_16 ] ) == NULL || ( V_25 -> V_121 & V_245 ) )
continue;
F_103 ( V_25 -> V_23 , V_25 ) ;
F_96 ( V_25 ) ;
F_100 ( V_25 -> V_20 , V_25 -> V_181 ) ;
if ( V_25 -> V_182 > 0 )
F_100 ( V_25 -> V_22 , V_25 -> V_182 ) ;
F_37 ( V_25 ) ;
V_46 [ V_16 ] = NULL ;
}
}
static int T_1 F_179 ( void )
{
struct V_24 * V_25 ;
struct V_12 V_551 ;
unsigned int V_16 , V_173 ;
int V_177 ;
F_10 ( V_552 L_37 , V_139 , V_140 ) ;
F_180 ( & V_258 ) ;
F_180 ( & V_148 ) ;
V_247 = F_181 ( V_236 * V_141 ) ;
if ( ! V_247 ) {
V_177 = - V_33 ;
goto V_184;
}
V_247 -> V_553 = V_554 ;
V_247 -> V_555 = V_556 ;
V_247 -> V_18 = L_116 ;
V_247 -> V_557 = V_558 ;
V_247 -> V_559 = 0 ;
V_247 -> type = V_560 ;
V_247 -> V_561 = V_562 ;
V_247 -> V_563 = V_564 ;
V_247 -> V_10 = V_565 | V_566 ;
F_182 ( V_247 , & V_567 ) ;
V_177 = F_183 ( V_247 ) ;
if ( V_177 ) {
F_10 ( L_117 ) ;
goto V_568;
}
for ( V_16 = V_44 ; V_16 < V_569 ; V_16 ++ ) {
memset ( & V_551 , 0 , sizeof( V_551 ) ) ;
if ( F_7 ( & V_551 , V_570 [ V_16 ] ) == 0 )
continue;
if ( ( V_25 = F_12 () ) == NULL )
continue;
V_25 -> V_40 = V_16 ;
V_25 -> V_19 = V_551 . V_19 ;
V_25 -> V_20 = V_551 . V_20 ;
V_25 -> V_22 = V_551 . V_22 ;
V_25 -> V_23 = V_551 . V_23 ;
V_25 -> V_186 = V_551 . V_186 ;
V_46 [ V_25 -> V_40 ] = V_25 ;
if ( F_102 ( V_25 ) ) {
V_46 [ V_25 -> V_40 ] = NULL ;
F_37 ( V_25 ) ;
} else {
for ( V_173 = 0 ; V_173 < V_25 -> V_49 ; V_173 ++ )
F_110 ( V_247 ,
V_25 -> V_40 * V_141 + V_173 , NULL ) ;
V_44 = V_16 + 1 ;
}
}
V_177 = F_184 ( & V_571 ) ;
if ( V_177 && V_44 == 0 ) {
F_10 ( V_572 L_118 ) ;
goto V_573;
}
if ( F_185 ( V_574 , L_119 , & V_575 ) )
F_10 ( L_120 ) ;
V_576 = F_186 ( V_554 , L_119 ) ;
if ( F_187 ( V_576 ) )
F_10 ( L_121 ) ;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ )
F_188 ( V_576 , NULL , F_189 ( V_574 , V_16 ) ,
NULL , L_122 , V_16 ) ;
return 0 ;
V_573:
F_190 ( V_247 ) ;
V_568:
F_191 ( V_247 ) ;
V_184:
return V_177 ;
}
static void T_8 F_192 ( void )
{
struct V_24 * V_25 ;
unsigned int V_16 , V_173 ;
F_8 ( L_123 ) ;
F_10 ( V_552 L_124 , V_139 ,
V_140 ) ;
for ( V_16 = 0 ; V_16 < V_44 ; V_16 ++ ) {
if ( ( V_25 = V_46 [ V_16 ] ) == NULL || ( V_25 -> V_121 & V_245 ) )
continue;
for ( V_173 = 0 ; V_173 < V_25 -> V_49 ; V_173 ++ )
F_113 ( V_247 ,
V_25 -> V_40 * V_141 + V_173 ) ;
}
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ )
F_193 ( V_576 , F_189 ( V_574 , V_16 ) ) ;
F_194 ( V_574 , L_119 ) ;
F_195 ( V_576 ) ;
F_196 ( & V_571 ) ;
F_178 () ;
F_190 ( V_247 ) ;
F_191 ( V_247 ) ;
}

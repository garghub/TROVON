static int F_1 ( const char * V_1 )
{
return ! regexec ( & V_2 , V_1 , 0 , NULL , 0 ) ;
}
static void F_2 ( void )
{
char V_3 [ 128 ] ;
int V_4 ;
V_4 = regcomp ( & V_2 , V_5 ,
V_6 | V_7 ) ;
if ( V_4 ) {
regerror ( V_4 , & V_2 , V_3 , sizeof( V_3 ) ) ;
F_3 ( L_1 , V_3 ) ;
}
}
static const char * F_4 ( unsigned type )
{
static const char * const V_8 [] = {
#define F_5 ( T_1 ) [X] = #X
F_5 ( V_9 ) ,
F_5 ( V_10 ) ,
F_5 ( V_11 ) ,
F_5 ( V_12 ) ,
F_5 ( V_13 ) ,
F_5 ( V_14 ) ,
F_5 ( V_15 ) ,
F_5 ( V_16 ) ,
F_5 ( V_17 ) ,
F_5 ( V_18 ) ,
F_5 ( V_19 ) ,
F_5 ( V_20 ) ,
F_5 ( V_21 ) ,
F_5 ( V_22 ) ,
F_5 ( V_23 ) ,
F_5 ( V_24 ) ,
F_5 ( V_25 ) ,
F_5 ( V_26 ) ,
#undef F_5
} ;
const char * V_27 = L_2 ;
if ( type < F_6 ( V_8 ) && V_8 [ type ] )
V_27 = V_8 [ type ] ;
return V_27 ;
}
static const char * F_7 ( unsigned V_28 )
{
const char * V_29 ;
const char * V_27 ;
V_29 = V_30 [ V_31 . V_32 ] . V_33 ;
if ( V_28 < V_31 . V_34 )
V_27 = V_29 + V_30 [ V_28 ] . V_35 . V_36 ;
else if ( V_28 == V_37 )
V_27 = L_3 ;
else if ( V_28 == V_38 )
V_27 = L_4 ;
else
V_27 = L_5 ;
return V_27 ;
}
static struct V_39 * F_8 ( const char * V_40 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_31 . V_34 ; V_41 ++ )
if ( strcmp ( V_40 , F_7 ( V_41 ) ) == 0 )
return & V_30 [ V_41 ] ;
return NULL ;
}
static const char * V_1 ( const char * V_42 , T_2 * V_43 )
{
const char * V_27 ;
if ( V_43 -> V_44 )
V_27 = V_42 + V_43 -> V_44 ;
else
V_27 = F_7 ( V_43 -> V_45 ) ;
return V_27 ;
}
static T_3 F_9 ( T_3 V_46 )
{
if ( V_31 . V_47 [ V_48 ] == V_49 )
return F_10 ( V_46 ) ;
else
return F_11 ( V_46 ) ;
}
static T_4 F_12 ( T_4 V_46 )
{
if ( V_31 . V_47 [ V_48 ] == V_49 )
return F_13 ( V_46 ) ;
else
return F_14 ( V_46 ) ;
}
static T_4 F_15 ( T_4 V_46 )
{
if ( V_31 . V_47 [ V_48 ] == V_49 )
return F_16 ( V_46 ) ;
else
return F_17 ( V_46 ) ;
}
static T_5 F_18 ( T_5 V_46 )
{
if ( V_31 . V_47 [ V_48 ] == V_49 )
return F_19 ( V_46 ) ;
else
return F_20 ( V_46 ) ;
}
static void F_21 ( T_6 * V_50 )
{
if ( fread ( & V_31 , sizeof( V_31 ) , 1 , V_50 ) != 1 )
F_3 ( L_6 , strerror ( V_51 ) ) ;
if ( memcmp ( V_31 . V_47 , V_52 , V_53 ) != 0 )
F_3 ( L_7 ) ;
if ( V_31 . V_47 [ V_54 ] != V_55 )
F_3 ( L_8 , V_56 ) ;
if ( ( V_31 . V_47 [ V_48 ] != V_49 ) &&
( V_31 . V_47 [ V_48 ] != V_57 ) )
F_3 ( L_9 ) ;
if ( V_31 . V_47 [ V_58 ] != V_59 )
F_3 ( L_10 ) ;
V_31 . V_60 = F_22 ( V_31 . V_60 ) ;
V_31 . V_61 = F_22 ( V_31 . V_61 ) ;
V_31 . V_62 = F_23 ( V_31 . V_62 ) ;
V_31 . V_63 = F_24 ( V_31 . V_63 ) ;
V_31 . V_64 = F_25 ( V_31 . V_64 ) ;
V_31 . V_65 = F_25 ( V_31 . V_65 ) ;
V_31 . V_66 = F_23 ( V_31 . V_66 ) ;
V_31 . V_67 = F_22 ( V_31 . V_67 ) ;
V_31 . V_68 = F_22 ( V_31 . V_68 ) ;
V_31 . V_69 = F_22 ( V_31 . V_69 ) ;
V_31 . V_70 = F_22 ( V_31 . V_70 ) ;
V_31 . V_34 = F_22 ( V_31 . V_34 ) ;
V_31 . V_32 = F_22 ( V_31 . V_32 ) ;
if ( ( V_31 . V_60 != V_71 ) && ( V_31 . V_60 != V_72 ) )
F_3 ( L_11 ) ;
if ( V_31 . V_61 != V_73 )
F_3 ( L_12 , V_74 ) ;
if ( V_31 . V_62 != V_59 )
F_3 ( L_10 ) ;
if ( V_31 . V_67 != sizeof( V_75 ) )
F_3 ( L_13 ) ;
if ( V_31 . V_68 != sizeof( V_76 ) )
F_3 ( L_14 ) ;
if ( V_31 . V_70 != sizeof( V_77 ) )
F_3 ( L_15 ) ;
if ( V_31 . V_32 >= V_31 . V_34 )
F_3 ( L_16 ) ;
}
static void F_26 ( T_6 * V_50 )
{
int V_41 ;
V_77 V_35 ;
V_30 = calloc ( V_31 . V_34 , sizeof( struct V_39 ) ) ;
if ( ! V_30 )
F_3 ( L_17 , V_31 . V_34 ) ;
if ( fseek ( V_50 , V_31 . V_65 , V_78 ) < 0 )
F_3 ( L_18 , V_31 . V_65 , strerror ( V_51 ) ) ;
for ( V_41 = 0 ; V_41 < V_31 . V_34 ; V_41 ++ ) {
struct V_39 * V_79 = & V_30 [ V_41 ] ;
V_79 -> V_80 = ftell ( V_50 ) ;
if ( fread ( & V_35 , sizeof( V_35 ) , 1 , V_50 ) != 1 )
F_3 ( L_19 ,
V_41 , V_31 . V_34 , strerror ( V_51 ) ) ;
V_79 -> V_35 . V_36 = F_23 ( V_35 . V_36 ) ;
V_79 -> V_35 . V_81 = F_23 ( V_35 . V_81 ) ;
V_79 -> V_35 . V_82 = F_27 ( V_35 . V_82 ) ;
V_79 -> V_35 . V_83 = F_24 ( V_35 . V_83 ) ;
V_79 -> V_35 . V_84 = F_25 ( V_35 . V_84 ) ;
V_79 -> V_35 . V_85 = F_27 ( V_35 . V_85 ) ;
V_79 -> V_35 . V_86 = F_23 ( V_35 . V_86 ) ;
V_79 -> V_35 . V_87 = F_23 ( V_35 . V_87 ) ;
V_79 -> V_35 . V_88 = F_27 ( V_35 . V_88 ) ;
V_79 -> V_35 . V_89 = F_27 ( V_35 . V_89 ) ;
if ( V_79 -> V_35 . V_86 < V_31 . V_34 )
V_79 -> V_90 = & V_30 [ V_79 -> V_35 . V_86 ] ;
}
}
static void F_28 ( T_6 * V_50 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_31 . V_34 ; V_41 ++ ) {
struct V_39 * V_79 = & V_30 [ V_41 ] ;
if ( V_79 -> V_35 . V_81 != V_91 )
continue;
V_79 -> V_33 = malloc ( V_79 -> V_35 . V_85 ) ;
if ( ! V_79 -> V_33 )
F_3 ( L_20 ,
V_79 -> V_35 . V_85 ) ;
if ( fseek ( V_50 , V_79 -> V_35 . V_84 , V_78 ) < 0 )
F_3 ( L_18 ,
V_79 -> V_35 . V_84 , strerror ( V_51 ) ) ;
if ( fread ( V_79 -> V_33 , 1 , V_79 -> V_35 . V_85 , V_50 ) !=
V_79 -> V_35 . V_85 )
F_3 ( L_21 , strerror ( V_51 ) ) ;
}
}
static void F_29 ( T_6 * V_50 )
{
int V_41 , V_92 ;
for ( V_41 = 0 ; V_41 < V_31 . V_34 ; V_41 ++ ) {
struct V_39 * V_79 = & V_30 [ V_41 ] ;
if ( V_79 -> V_35 . V_81 != V_93 )
continue;
V_79 -> V_94 = malloc ( V_79 -> V_35 . V_85 ) ;
if ( ! V_79 -> V_94 )
F_3 ( L_22 ,
V_79 -> V_35 . V_85 ) ;
if ( fseek ( V_50 , V_79 -> V_35 . V_84 , V_78 ) < 0 )
F_3 ( L_18 ,
V_79 -> V_35 . V_84 , strerror ( V_51 ) ) ;
if ( fread ( V_79 -> V_94 , 1 , V_79 -> V_35 . V_85 , V_50 ) !=
V_79 -> V_35 . V_85 )
F_3 ( L_21 , strerror ( V_51 ) ) ;
for ( V_92 = 0 ; V_92 < V_79 -> V_35 . V_85 / sizeof( T_2 ) ; V_92 ++ ) {
T_2 * V_43 = & V_79 -> V_94 [ V_92 ] ;
V_43 -> V_44 = F_23 ( V_43 -> V_44 ) ;
V_43 -> V_95 = F_24 ( V_43 -> V_95 ) ;
V_43 -> V_96 = F_27 ( V_43 -> V_96 ) ;
V_43 -> V_45 = F_22 ( V_43 -> V_45 ) ;
}
}
}
static void F_30 ( T_6 * V_50 )
{
static unsigned long V_97 = 0 ;
int V_41 , V_92 ;
if ( ! V_97 ) {
struct V_39 * V_79 = F_8 ( L_23 ) ;
if ( ! V_79 )
F_3 ( L_24 ) ;
V_97 = V_79 -> V_35 . V_83 ;
}
for ( V_41 = 0 ; V_41 < V_31 . V_34 ; V_41 ++ ) {
struct V_39 * V_79 = & V_30 [ V_41 ] ;
if ( V_79 -> V_35 . V_81 != V_98 )
continue;
V_79 -> V_99 = malloc ( V_79 -> V_35 . V_85 ) ;
if ( ! V_79 -> V_99 )
F_3 ( L_25 ,
V_79 -> V_35 . V_85 ) ;
if ( fseek ( V_50 , V_79 -> V_35 . V_84 , V_78 ) < 0 )
F_3 ( L_18 ,
V_79 -> V_35 . V_84 , strerror ( V_51 ) ) ;
if ( fread ( V_79 -> V_99 , 1 , V_79 -> V_35 . V_85 , V_50 ) !=
V_79 -> V_35 . V_85 )
F_3 ( L_21 , strerror ( V_51 ) ) ;
for ( V_92 = 0 ; V_92 < V_79 -> V_35 . V_85 / sizeof( V_100 ) ; V_92 ++ ) {
V_100 * V_101 = & V_79 -> V_99 [ V_92 ] ;
V_101 -> V_102 = F_24 ( V_101 -> V_102 ) ;
V_101 -> V_102 -= V_97 ;
#if ( V_56 == 32 )
V_101 -> V_103 = F_27 ( V_101 -> V_103 ) ;
#else
V_101 -> V_103 = V_101 -> V_103 ;
F_31 ( V_101 -> V_103 ) = F_12 ( F_31 ( V_101 -> V_103 ) ) ;
#endif
#if ( V_98 == V_104 )
V_101 -> V_105 = F_27 ( V_101 -> V_105 ) ;
#endif
}
}
}
static void F_32 ( T_6 * V_50 )
{
int V_41 ;
V_77 V_35 ;
for ( V_41 = 0 ; V_41 < V_31 . V_34 ; V_41 ++ ) {
struct V_39 * V_79 = & V_30 [ V_41 ] ;
if ( V_79 -> V_35 . V_81 != V_98 )
continue;
if ( fseek ( V_50 , V_79 -> V_80 , V_78 ) < 0 )
F_3 ( L_18 ,
V_79 -> V_80 , strerror ( V_51 ) ) ;
if ( fread ( & V_35 , sizeof( V_35 ) , 1 , V_50 ) != 1 )
F_3 ( L_19 ,
V_41 , V_31 . V_34 , strerror ( V_51 ) ) ;
V_35 . V_85 = 0 ;
if ( fseek ( V_50 , V_79 -> V_80 , V_78 ) < 0 )
F_3 ( L_18 ,
V_79 -> V_80 , strerror ( V_51 ) ) ;
if ( fwrite ( & V_35 , sizeof( V_35 ) , 1 , V_50 ) != 1 )
F_3 ( L_26 ,
V_41 , V_31 . V_34 , strerror ( V_51 ) ) ;
}
}
static void F_33 ( struct V_106 * V_107 , T_4 V_108 , unsigned type )
{
V_108 >>= 2 ;
if ( V_108 > 0x00FFFFFF )
F_3 ( L_27 ) ;
V_108 = ( V_108 & 0x00FFFFFF ) | ( ( type & 0xFF ) << 24 ) ;
if ( V_107 -> V_109 == V_107 -> V_110 ) {
unsigned long V_111 = V_107 -> V_110 + 50000 ;
void * V_112 = realloc ( V_107 -> V_108 , V_111 * sizeof( V_107 -> V_108 [ 0 ] ) ) ;
if ( ! V_112 )
F_3 ( L_28 ) ;
V_107 -> V_108 = V_112 ;
V_107 -> V_110 = V_111 ;
}
V_107 -> V_108 [ V_107 -> V_109 ++ ] = V_108 ;
}
static void F_34 ( int (* F_35)( struct V_39 * V_79 , V_100 * V_101 ,
T_2 * V_43 , const char * V_113 ) )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_31 . V_34 ; V_41 ++ ) {
char * V_42 ;
T_2 * V_114 ;
struct V_39 * V_115 , * V_116 ;
int V_92 ;
struct V_39 * V_79 = & V_30 [ V_41 ] ;
if ( V_79 -> V_35 . V_81 != V_98 )
continue;
V_116 = V_79 -> V_90 ;
V_115 = & V_30 [ V_79 -> V_35 . V_87 ] ;
if ( ! ( V_115 -> V_35 . V_82 & V_117 ) )
continue;
V_114 = V_116 -> V_94 ;
V_42 = V_116 -> V_90 -> V_33 ;
for ( V_92 = 0 ; V_92 < V_79 -> V_35 . V_85 / sizeof( V_100 ) ; V_92 ++ ) {
V_100 * V_101 = & V_79 -> V_99 [ V_92 ] ;
T_2 * V_43 = & V_114 [ F_31 ( V_101 -> V_103 ) ] ;
const char * V_113 = V_1 ( V_42 , V_43 ) ;
F_35 ( V_79 , V_101 , V_43 , V_113 ) ;
}
}
}
static int F_36 ( struct V_39 * V_79 , V_100 * V_101 , T_2 * V_43 ,
const char * V_113 )
{
unsigned V_118 = F_37 ( V_101 -> V_103 ) ;
unsigned V_119 = F_38 ( V_43 -> V_120 ) ;
if ( ( V_119 == V_121 ) && ( V_43 -> V_95 == 0 ) ) {
return 0 ;
}
if ( F_1 ( V_113 ) )
return 0 ;
switch ( V_118 ) {
case V_9 :
case V_12 :
case V_19 :
case V_25 :
case V_26 :
case V_24 :
case V_23 :
case V_15 :
break;
case V_22 :
case V_11 :
case V_13 :
case V_14 :
F_33 ( & V_106 , V_101 -> V_102 , V_118 ) ;
break;
default:
F_3 ( L_29 ,
F_4 ( V_118 ) , V_118 ) ;
break;
}
return 0 ;
}
static int F_39 ( T_4 V_122 , T_6 * V_123 )
{
unsigned char V_124 [ 4 ] ;
V_122 = F_15 ( V_122 ) ;
memcpy ( V_124 , & V_122 , sizeof( T_4 ) ) ;
return fwrite ( V_124 , 1 , 4 , V_123 ) ;
}
static int F_40 ( T_4 V_122 , T_6 * V_123 )
{
int V_125 ;
V_125 = fprintf ( V_123 , L_30 V_126 L_31 , V_122 ) ;
if ( V_125 < 0 )
return V_125 ;
else
return sizeof( T_4 ) ;
}
static void F_41 ( int V_127 , int V_128 , T_6 * V_129 )
{
int V_41 ;
int (* F_42)( T_4 , T_6 * ) = F_39 ;
int V_110 = 0 ;
int V_130 ;
struct V_39 * V_131 ;
V_131 = F_8 ( L_32 ) ;
if ( ! V_131 )
F_3 ( L_33 ) ;
V_130 = V_131 -> V_35 . V_85 ;
F_34 ( F_36 ) ;
if ( V_127 ) {
printf ( L_34 ) ;
printf ( L_35 ) ;
F_42 = F_40 ;
V_129 = stdout ;
} else if ( V_128 ) {
V_129 = stdout ;
} else {
if ( fseek ( V_129 , V_131 -> V_35 . V_84 , V_78 ) < 0 ) {
F_3 ( L_18 ,
V_131 -> V_35 . V_84 , strerror ( V_51 ) ) ;
}
}
for ( V_41 = 0 ; V_41 < V_106 . V_109 ; V_41 ++ )
V_110 += F_42 ( V_106 . V_108 [ V_41 ] , V_129 ) ;
if ( V_110 )
V_110 += F_42 ( 0 , V_129 ) ;
if ( V_110 > V_130 )
F_3 ( L_36 \
L_37 \
L_38 , ( V_110 + 0x1000 ) & ~ 0xFFF ) ;
}
static void F_43 ( void )
{
printf ( L_39 ,
L_40 ,
L_41 ,
L_42 ,
L_43 ,
L_44 ) ;
F_34 ( V_132 ) ;
}
void F_35 ( T_6 * V_50 , int V_127 , int V_128 ,
int V_133 , int V_134 )
{
F_2 () ;
F_21 ( V_50 ) ;
F_26 ( V_50 ) ;
F_28 ( V_50 ) ;
F_29 ( V_50 ) ;
F_30 ( V_50 ) ;
if ( V_133 ) {
F_43 () ;
return;
}
F_41 ( V_127 , V_128 , V_50 ) ;
if ( ! V_134 )
F_32 ( V_50 ) ;
}

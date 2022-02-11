static struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 ;
V_3 = V_4 ;
while ( V_3 != NULL ) {
if ( V_3 -> V_5 == V_2 )
return V_3 ;
V_3 = V_3 -> V_6 ;
}
return NULL ;
}
static struct V_1 * F_2 ( struct V_7 * V_8 )
{
struct V_1 * V_3 ;
V_3 = V_4 ;
while ( V_3 != NULL ) {
if ( V_3 -> V_9 == V_8 )
return V_3 ;
V_3 = V_3 -> V_6 ;
}
return NULL ;
}
static struct V_1 * F_3 ( struct V_10 * V_11 )
{
struct V_1 * V_3 ;
V_3 = V_4 ;
while ( V_3 != NULL ) {
if ( V_3 -> V_11 == V_11 )
return V_3 ;
V_3 = V_3 -> V_6 ;
}
return NULL ;
}
struct V_12 * F_4 ( T_1 V_13 , struct V_14 * V_15 )
{
struct V_12 * V_16 ;
V_16 = F_5 ( V_13 ) ;
if ( V_16 != NULL ) {
V_16 -> V_15 = * V_15 ;
return V_16 ;
}
V_16 = F_6 ( sizeof( struct V_12 ) , V_17 ) ;
if ( V_16 == NULL ) {
F_7 ( L_1 ) ;
return V_16 ;
}
V_16 -> V_18 = V_13 ;
V_16 -> V_15 = * V_15 ;
V_16 -> V_6 = V_19 ;
V_19 = V_16 ;
return V_16 ;
}
struct V_12 * F_5 ( T_1 V_13 )
{
struct V_12 * V_15 ;
V_15 = V_19 ;
while ( V_15 ) {
if ( V_15 -> V_18 == V_13 )
break;
V_15 = V_15 -> V_6 ;
}
return V_15 ;
}
int F_8 ( struct V_12 * V_16 )
{
struct V_12 * V_20 ;
if ( V_16 == NULL )
return 0 ;
if ( V_16 == V_19 ) {
V_19 = V_19 -> V_6 ;
F_9 ( V_16 ) ;
return 1 ;
}
V_20 = V_19 ;
while ( V_20 != NULL ) {
if ( V_20 -> V_6 == V_16 ) {
V_20 -> V_6 = V_16 -> V_6 ;
F_9 ( V_16 ) ;
return 1 ;
}
V_20 = V_20 -> V_6 ;
}
return 0 ;
}
void F_10 ( struct V_21 * V_22 )
{
struct V_12 * V_15 ;
V_15 = V_19 ;
F_11 ( V_22 , L_2 ) ;
F_11 ( V_22 , L_3 ) ;
while ( V_15 != NULL ) {
F_11 ( V_22 , L_4 ,
& V_15 -> V_18 ,
V_15 -> V_15 . V_23 . V_24 ,
V_15 -> V_15 . V_23 . V_25 ,
V_15 -> V_15 . V_23 . V_26 ,
V_15 -> V_15 . V_23 . V_27 ,
V_15 -> V_15 . V_23 . V_28 ,
V_15 -> V_15 . V_29 . V_24 ,
V_15 -> V_15 . V_29 . V_25 ,
V_15 -> V_15 . V_29 . V_26 ,
V_15 -> V_15 . V_29 . V_27 ,
V_15 -> V_15 . V_29 . V_28 ) ;
V_15 = V_15 -> V_6 ;
}
}
static struct V_10 * F_12 ( int V_2 )
{
struct V_10 * V_11 ;
char V_30 [ V_31 ] ;
sprintf ( V_30 , L_5 , V_2 ) ;
V_11 = F_13 ( & V_32 , V_30 ) ;
return V_11 ;
}
static struct V_1 * F_14 ( void )
{
struct V_1 * V_3 ;
V_3 = F_15 ( sizeof( struct V_1 ) , V_17 ) ;
if ( V_3 == NULL )
return NULL ;
F_16 ( & V_3 -> V_33 ) ;
F_16 ( & V_3 -> V_34 ) ;
V_3 -> V_6 = V_4 ;
F_17 ( V_3 ) ;
V_3 -> V_35 . V_36 = V_37 ;
V_3 -> V_35 . V_38 = V_39 ;
memset ( V_3 -> V_35 . V_40 , 0 , sizeof( V_3 -> V_35 . V_40 ) ) ;
V_3 -> V_35 . V_41 = V_42 ;
V_3 -> V_35 . V_43 = V_44 ;
V_3 -> V_35 . V_45 = V_46 ;
V_4 = V_3 ;
return V_3 ;
}
static void F_18 ( struct V_1 * V_3 , struct V_10 * V_11 )
{
F_19 ( L_6 , V_3 -> V_11 -> V_30 ) ;
if ( ! V_11 -> V_47 )
F_7 ( L_7 , V_11 -> V_30 ) ;
else {
V_3 -> V_48 = V_11 -> V_47 ;
V_3 -> V_49 = * V_3 -> V_48 ;
V_3 -> V_49 . V_50 = V_51 ;
V_11 -> V_47 = & V_3 -> V_49 ;
}
}
static void F_20 ( struct V_1 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_11 ;
F_19 ( L_8 , V_3 -> V_11 -> V_30 ) ;
if ( V_11 -> V_47 != & V_3 -> V_49 ) {
F_21 ( L_9 ) ;
return;
}
F_21 ( L_10 ) ;
V_11 -> V_47 = V_3 -> V_48 ;
V_3 -> V_48 = NULL ;
}
static const char * F_22 ( char type )
{
switch ( type ) {
case V_52 :
return L_11 ;
case V_53 :
return L_12 ;
case V_54 :
return L_13 ;
case V_55 :
return L_14 ;
}
return L_15 ;
}
static void F_23 ( struct V_10 * V_11 , const T_2 * V_56 ,
const T_2 * V_57 , T_3 V_58 )
{
T_4 type ;
T_5 V_59 , V_60 , V_61 ;
const T_5 * V_62 ;
struct V_1 * V_3 ;
V_60 = V_61 = 0 ;
F_19 ( L_16 , V_11 -> V_30 ) ;
F_19 ( L_17 , V_58 ) ;
V_3 = F_3 ( V_11 ) ;
if ( V_3 == NULL ) {
F_7 ( L_18 , V_11 -> V_30 ) ;
return;
}
V_62 = V_57 + V_58 ;
while ( V_62 - V_57 >= 5 ) {
type = ( ( V_57 [ 0 ] << 24 ) | ( V_57 [ 1 ] << 16 ) |
( V_57 [ 2 ] << 8 ) | V_57 [ 3 ] ) ;
V_59 = V_57 [ 4 ] ;
V_57 += 5 ;
F_19 ( L_19 , type , V_59 ) ;
if ( V_57 + V_59 > V_62 ) {
F_7 ( L_20 ) ;
return;
}
if ( type == 0 ) {
F_7 ( L_21 ,
V_11 -> V_30 ) ;
return;
}
if ( type != V_63 ) {
V_57 += V_59 ;
continue;
}
V_60 = * V_57 ++ ;
V_61 = * V_57 ++ ;
F_19 ( L_22 ,
V_11 -> V_30 , F_22 ( V_60 ) ) ;
if ( V_60 == V_55 &&
V_59 < ( 42 + V_61 * V_64 ) ) {
F_7 ( L_23 ,
V_11 -> V_30 ) ;
continue;
}
if ( ( V_60 == V_53 || V_60 == V_54 ) &&
V_59 < 22 + V_61 * V_64 ) {
F_7 ( L_23 , V_11 -> V_30 ) ;
continue;
}
if ( V_60 != V_53 &&
V_60 != V_55 ) {
F_19 ( L_24 ) ;
if ( V_60 == V_54 )
V_57 += 20 ;
continue;
}
if ( V_61 == 0 &&
V_60 == V_55 ) {
F_7 ( L_25 , V_11 -> V_30 ) ;
continue;
}
F_21 ( L_26 ,
V_61 ) ;
F_24 ( V_57 , V_3 ) ;
V_57 = F_25 ( V_3 , V_56 , V_57 ,
V_61 , V_60 ) ;
if ( V_57 == NULL )
return;
}
if ( V_62 - V_57 != 0 )
F_7 ( L_27 ,
V_11 -> V_30 , V_62 - V_57 ) ;
}
static const T_5 * F_25 ( struct V_1 * V_3 ,
const T_5 * V_65 ,
const T_5 * V_57 , T_5 V_66 ,
T_5 V_67 )
{
int V_68 ;
V_68 = ( V_66 > 1 ) ? V_66 : 1 ;
if ( V_3 -> V_61 != V_68 ) {
if ( V_3 -> V_61 != 0 )
F_9 ( V_3 -> V_66 ) ;
V_3 -> V_61 = 0 ;
V_3 -> V_66 = F_6 ( V_68 * V_64 , V_17 ) ;
if ( V_3 -> V_66 == NULL ) {
F_7 ( L_28 , V_3 -> V_11 -> V_30 ) ;
return NULL ;
}
}
F_26 ( V_3 -> V_66 , V_65 ) ;
V_57 += 20 ; if ( V_67 == V_55 ) V_57 += 20 ;
if ( V_66 > 0 )
memcpy ( V_3 -> V_66 , V_57 , V_66 * V_64 ) ;
V_57 += V_66 * V_64 ;
V_3 -> V_61 = V_68 ;
return V_57 ;
}
static int F_27 ( struct V_69 * V_70 , struct V_1 * V_3 )
{
T_6 * V_16 ;
struct V_71 * V_72 ;
char * V_73 ;
T_1 V_18 = 0 ;
static struct {
struct V_74 V_75 ;
T_1 V_76 ;
} V_77 = {
{ 0xaa , 0xaa , 0x03 , { 0x00 , 0x00 , 0x00 } , { 0x88 , 0x4c } } ,
0
} ;
V_73 = V_70 -> V_78 + V_3 -> V_11 -> V_79 ;
V_72 = (struct V_71 * ) V_73 ;
V_18 = V_72 -> V_80 ;
F_28 ( L_29 ,
V_3 -> V_11 -> V_30 , V_18 ) ;
V_16 = V_3 -> V_81 -> V_82 ( V_18 , V_3 ) ;
if ( V_16 == NULL ) {
V_16 = V_3 -> V_81 -> V_83 ( V_18 , V_3 ) ;
if ( V_16 != NULL )
V_3 -> V_81 -> V_84 ( V_16 ) ;
return 1 ;
}
if ( V_3 -> V_81 -> V_85 ( V_16 , V_3 ) != V_86 ) {
F_28 ( L_30 ,
V_3 -> V_11 -> V_30 ) ;
V_3 -> V_81 -> V_84 ( V_16 ) ;
return 1 ;
}
F_28 ( L_31 ,
V_3 -> V_11 -> V_30 ) ;
if ( V_72 -> V_87 <= 1 ) {
F_28 ( L_32 ,
V_3 -> V_11 -> V_30 , V_72 -> V_87 ) ;
V_3 -> V_81 -> V_84 ( V_16 ) ;
return 1 ;
}
V_72 -> V_87 -- ;
V_72 -> V_88 = 0 ;
V_72 -> V_88 = F_29 ( ( unsigned char * ) V_72 , V_72 -> V_89 ) ;
if ( V_16 -> V_90 . V_76 != 0 ) {
F_28 ( L_33 ,
V_3 -> V_11 -> V_30 , V_16 -> V_90 . V_76 ) ;
V_77 . V_76 = V_16 -> V_90 . V_76 ;
F_30 ( V_70 , V_91 ) ;
F_31 ( V_70 , sizeof( V_77 ) ) ;
F_32 ( V_70 , & V_77 ,
sizeof( V_77 ) ) ;
} else {
F_30 ( V_70 , V_91 ) ;
F_31 ( V_70 , sizeof( struct V_74 ) ) ;
F_32 ( V_70 , & V_92 ,
sizeof( struct V_74 ) ) ;
}
F_33 ( V_70 -> V_93 , & F_34 ( V_16 -> V_94 ) -> V_95 ) ;
F_35 ( V_70 ) -> V_96 = V_16 -> V_94 -> V_96 ;
V_16 -> V_94 -> V_97 ( V_16 -> V_94 , V_70 ) ;
V_16 -> V_98 ++ ;
V_3 -> V_81 -> V_84 ( V_16 ) ;
return 0 ;
}
static T_7 V_51 ( struct V_69 * V_70 ,
struct V_10 * V_11 )
{
struct V_1 * V_3 ;
struct V_99 * V_100 ;
int V_101 = 0 ;
V_3 = F_3 ( V_11 ) ;
if ( V_3 == NULL ) {
F_7 ( L_34 , V_11 -> V_30 ) ;
goto V_102;
}
V_100 = (struct V_99 * ) V_70 -> V_78 ;
if ( V_100 -> V_103 != F_36 ( V_104 ) )
goto V_102;
if ( V_70 -> V_105 < V_91 + sizeof( struct V_71 ) )
goto V_102;
F_37 ( V_70 , V_91 ) ;
if ( V_70 -> V_105 < V_91 + F_38 ( V_70 ) -> V_89 * 4 || F_38 ( V_70 ) -> V_89 < 5 )
goto V_102;
while ( V_101 < V_3 -> V_61 ) {
if ( F_39 ( V_100 -> V_106 , V_3 -> V_66 + V_101 * V_64 ) )
if ( F_27 ( V_70 , V_3 ) == 0 )
return V_107 ;
V_101 ++ ;
}
V_102:
return V_3 -> V_48 -> V_50 ( V_70 , V_11 ) ;
}
static int F_40 ( struct V_7 * V_8 , void T_8 * V_108 )
{
int V_109 ;
struct V_1 * V_3 ;
struct V_110 V_111 ;
T_6 * V_112 ;
T_1 V_18 ;
V_109 = F_41 ( & V_111 , V_108 , sizeof( struct V_110 ) ) ;
if ( V_109 != 0 ) {
F_7 ( L_35 ,
V_109 ) ;
return - V_113 ;
}
V_18 = V_111 . V_18 ;
if ( V_111 . V_5 < 0 || V_111 . V_5 >= V_114 )
return - V_115 ;
V_3 = F_1 ( V_111 . V_5 ) ;
if ( V_3 == NULL )
return - V_115 ;
if ( V_111 . type == V_116 ) {
V_112 = V_3 -> V_81 -> V_82 ( V_18 , V_3 ) ;
if ( V_112 == NULL ||
V_112 -> V_117 < V_118 ) {
F_7 ( L_36 ,
V_3 -> V_11 -> V_30 ) ;
if ( V_112 != NULL )
V_3 -> V_81 -> V_84 ( V_112 ) ;
return - V_115 ;
}
F_7 ( L_37 ,
V_3 -> V_11 -> V_30 , & V_112 -> V_90 . V_119 ) ;
V_112 -> V_94 = V_8 ;
V_3 -> V_81 -> V_84 ( V_112 ) ;
} else {
F_7 ( L_38 , V_3 -> V_11 -> V_30 ) ;
}
V_8 -> V_120 = V_3 -> V_11 ;
V_8 -> V_121 = V_122 ;
return 0 ;
}
static void F_42 ( struct V_7 * V_8 , struct V_10 * V_11 )
{
struct V_1 * V_3 ;
T_6 * V_112 ;
T_9 * V_123 ;
V_3 = F_3 ( V_11 ) ;
if ( V_3 == NULL ) {
F_7 ( L_39 , V_11 -> V_30 ) ;
return;
}
F_19 ( L_6 , V_11 -> V_30 ) ;
V_112 = V_3 -> V_81 -> V_124 ( V_8 , V_3 ) ;
if ( V_112 ) {
F_19 ( L_40 ,
V_3 -> V_11 -> V_30 , & V_112 -> V_90 . V_119 ) ;
V_112 -> V_94 = NULL ;
V_3 -> V_81 -> V_84 ( V_112 ) ;
}
V_123 = V_3 -> V_125 -> V_124 ( V_8 , V_3 ) ;
if ( V_123 ) {
F_19 ( L_41 , V_3 -> V_11 -> V_30 ) ;
V_123 -> V_94 = NULL ;
V_3 -> V_125 -> V_84 ( V_123 ) ;
}
if ( V_112 == NULL && V_123 == NULL )
F_19 ( L_42 , V_11 -> V_30 ) ;
}
static void V_122 ( struct V_7 * V_8 , struct V_69 * V_70 )
{
struct V_10 * V_11 = (struct V_10 * ) V_8 -> V_120 ;
struct V_69 * V_126 ;
T_9 * V_127 ;
struct V_1 * V_3 ;
T_1 V_76 ;
char * V_128 ;
F_28 ( L_6 , V_11 -> V_30 ) ;
if ( V_70 == NULL ) {
F_19 ( L_43 , V_11 -> V_30 ) ;
F_42 ( V_8 , V_11 ) ;
return;
}
V_70 -> V_11 = V_11 ;
if ( memcmp ( V_70 -> V_78 , & V_129 ,
sizeof( struct V_74 ) ) == 0 ) {
struct V_130 * V_131 = F_34 ( V_8 ) ;
F_19 ( L_44 , V_11 -> V_30 ) ;
F_43 ( & V_131 -> V_132 , V_70 ) ;
V_131 -> V_133 ( V_131 ) ;
return;
}
F_44 ( V_8 , V_70 -> V_93 ) ;
V_3 = F_3 ( V_11 ) ;
if ( V_3 == NULL ) {
F_7 ( L_45 , V_11 -> V_30 ) ;
return;
}
if ( memcmp ( V_70 -> V_78 , & V_134 ,
sizeof( struct V_74 ) ) == 0 ) {
F_28 ( L_46 , V_11 -> V_30 ) ;
} else if ( memcmp ( V_70 -> V_78 , & V_92 ,
sizeof( struct V_74 ) ) == 0 ) {
F_7 ( L_47 ,
V_11 -> V_30 ) ;
F_45 ( V_70 ) ;
return;
} else {
F_7 ( L_48 , V_11 -> V_30 ) ;
F_45 ( V_70 ) ;
return;
}
V_128 = V_70 -> V_78 + sizeof( struct V_74 ) ;
V_76 = * ( T_1 * ) V_128 ;
V_127 = V_3 -> V_125 -> V_135 ( V_76 , V_3 ) ;
if ( V_127 == NULL ) {
F_7 ( L_49 ,
V_11 -> V_30 , V_76 ) ;
F_46 ( V_8 , NULL ) ;
F_45 ( V_70 ) ;
return;
}
if ( V_127 -> V_94 == NULL ) {
V_127 -> V_94 = V_8 ;
F_7 ( L_50 , V_11 -> V_30 ) ;
}
F_30 ( V_70 , sizeof( struct V_74 ) + sizeof( V_76 ) ) ;
V_126 = F_47 ( V_70 , V_127 -> V_90 . V_136 ) ;
F_45 ( V_70 ) ;
if ( V_126 == NULL ) {
V_3 -> V_125 -> V_84 ( V_127 ) ;
return;
}
F_31 ( V_126 , V_127 -> V_90 . V_136 ) ;
F_32 ( V_126 , V_127 -> V_90 . V_137 ,
V_127 -> V_90 . V_136 ) ;
V_126 -> V_138 = F_48 ( V_126 , V_11 ) ;
F_49 ( V_126 ) ;
V_127 -> V_139 = F_38 ( V_126 ) -> V_140 ;
V_127 -> V_141 ++ ;
V_3 -> V_125 -> V_84 ( V_127 ) ;
memset ( F_35 ( V_126 ) , 0 , sizeof( struct V_142 ) ) ;
F_50 ( V_126 ) ;
}
static int F_51 ( struct V_7 * V_8 , int V_108 )
{
struct V_1 * V_3 ;
struct V_143 * V_144 ;
int V_145 ;
if ( V_4 == NULL ) {
F_52 ( & V_146 ) ;
F_53 () ;
V_145 = F_54 ( & V_147 ) ;
if ( V_145 < 0 ) {
F_55 ( & V_146 ) ;
return V_145 ;
}
}
V_3 = F_1 ( V_108 ) ;
if ( V_3 == NULL ) {
F_19 ( L_51 , V_108 ) ;
V_3 = F_14 () ;
if ( V_3 == NULL )
return - V_148 ;
V_3 -> V_5 = V_108 ;
V_3 -> V_11 = F_12 ( V_108 ) ;
}
if ( V_3 -> V_9 ) {
F_7 ( L_52 , V_108 ) ;
return - V_149 ;
}
if ( V_3 -> V_11 ) {
V_144 = F_56 ( V_3 -> V_11 ) ;
if ( V_144 -> V_150 < 2 ) {
F_57 ( V_3 -> V_11 ) ;
V_3 -> V_11 = NULL ;
} else
V_144 -> V_151 -> V_152 = F_23 ;
}
V_3 -> V_9 = V_8 ;
V_8 -> V_11 = & V_153 ;
F_58 ( F_34 ( V_8 ) ) ;
F_59 ( V_154 , & V_8 -> V_155 ) ;
F_59 ( V_156 , & V_8 -> V_155 ) ;
if ( V_3 -> V_11 ) {
char V_157 [ V_158 ] ;
memset ( V_157 , 0 , V_158 ) ;
F_18 ( V_3 , V_3 -> V_11 ) ;
if ( memcmp ( V_3 -> V_159 , V_157 , V_158 ) != 0 )
F_24 ( V_3 -> V_159 , V_3 ) ;
}
F_60 ( V_160 ) ;
return V_108 ;
}
static void F_24 ( const char * V_161 , struct V_1 * V_3 )
{
struct V_162 V_163 ;
memcpy ( V_3 -> V_159 , V_161 , V_158 ) ;
V_163 . type = V_164 ;
memcpy ( V_163 . V_165 , V_161 , V_158 ) ;
F_61 ( & V_163 , V_3 ) ;
}
static void F_62 ( struct V_7 * V_8 )
{
struct V_1 * V_3 ;
struct V_69 * V_70 ;
V_3 = F_2 ( V_8 ) ;
if ( V_3 == NULL ) {
F_7 ( L_53 ) ;
return;
}
if ( ! V_3 -> V_9 ) {
F_7 ( L_54 ) ;
return;
}
V_3 -> V_9 = NULL ;
if ( V_3 -> V_11 ) {
struct V_143 * V_144 = F_56 ( V_3 -> V_11 ) ;
V_144 -> V_151 -> V_152 = NULL ;
F_20 ( V_3 ) ;
F_57 ( V_3 -> V_11 ) ;
}
V_3 -> V_81 -> V_166 ( V_3 ) ;
V_3 -> V_125 -> V_166 ( V_3 ) ;
while ( ( V_70 = F_63 ( & F_34 ( V_8 ) -> V_132 ) ) ) {
F_44 ( V_8 , V_70 -> V_93 ) ;
F_64 ( V_70 ) ;
}
F_7 ( L_55 ,
( V_3 -> V_11 ) ? V_3 -> V_11 -> V_30 : L_56 ) ;
F_65 ( V_160 ) ;
}
static int F_66 ( struct V_7 * V_8 , struct V_69 * V_70 )
{
struct V_1 * V_3 = F_2 ( V_8 ) ;
struct V_162 * V_163 = (struct V_162 * ) V_70 -> V_78 ;
F_67 ( V_70 -> V_93 , & F_34 ( V_8 ) -> V_95 ) ;
if ( V_3 == NULL ) {
F_7 ( L_57 ) ;
return 0 ;
}
F_19 ( L_8 , V_3 -> V_11 ? V_3 -> V_11 -> V_30 : L_56 ) ;
switch ( V_163 -> type ) {
case V_167 :
F_21 ( L_58 ) ;
F_68 ( V_163 , V_3 ) ;
break;
case V_168 :
F_21 ( L_59 ) ;
F_69 ( V_163 , V_3 ) ;
break;
case V_169 :
F_21 ( L_60 ) ;
F_70 ( V_163 , V_3 ) ;
break;
case V_170 :
F_21 ( L_61 ) ;
F_71 ( V_163 , V_3 ) ;
break;
case V_171 :
F_21 ( L_62 ) ;
F_72 ( V_163 , V_3 ) ;
break;
case V_172 :
F_21 ( L_63 ) ;
F_73 ( V_163 , V_3 ) ;
break;
case V_173 :
F_21 ( L_64 ) ;
F_74 ( V_163 , V_3 ) ;
break;
case V_174 :
F_21 ( L_65 ) ;
F_75 ( V_163 , V_3 ) ;
break;
case V_175 :
F_21 ( L_66 ) ;
F_76 ( V_163 , V_3 , V_176 ) ;
break;
case V_177 :
F_21 ( L_67 ) ;
F_76 ( V_163 , V_3 , V_177 ) ;
break;
case V_178 :
F_21 ( L_68 ) ;
V_3 -> V_35 = V_163 -> V_179 . V_180 ;
break;
default:
F_21 ( L_69 , V_163 -> type ) ;
break;
}
F_64 ( V_70 ) ;
return 0 ;
}
int F_61 ( struct V_162 * V_163 , struct V_1 * V_3 )
{
struct V_69 * V_70 ;
struct V_130 * V_131 ;
if ( V_3 == NULL || ! V_3 -> V_9 ) {
F_7 ( L_70 , V_163 -> type ) ;
return - V_181 ;
}
V_70 = F_77 ( sizeof( struct V_162 ) , V_182 ) ;
if ( V_70 == NULL )
return - V_148 ;
F_78 ( V_70 , sizeof( struct V_162 ) ) ;
F_32 ( V_70 , V_163 , sizeof( * V_163 ) ) ;
F_79 ( V_3 -> V_9 , V_70 -> V_93 ) ;
V_131 = F_34 ( V_3 -> V_9 ) ;
F_43 ( & V_131 -> V_132 , V_70 ) ;
V_131 -> V_133 ( V_131 ) ;
return 0 ;
}
static int F_80 ( struct V_183 * V_147 ,
unsigned long V_184 , void * V_185 )
{
struct V_10 * V_11 = F_81 ( V_185 ) ;
struct V_1 * V_3 ;
struct V_143 * V_144 ;
if ( ! F_82 ( F_83 ( V_11 ) , & V_32 ) )
return V_186 ;
if ( V_11 -> V_30 == NULL || strncmp ( V_11 -> V_30 , L_71 , 3 ) )
return V_186 ;
switch ( V_184 ) {
case V_187 :
V_144 = F_56 ( V_11 ) ;
if ( V_144 -> V_150 < 2 )
break;
V_144 -> V_151 -> V_152 = F_23 ;
V_3 = F_1 ( V_144 -> V_188 ) ;
if ( V_3 == NULL ) {
F_19 ( L_72 , V_11 -> V_30 ) ;
V_3 = F_14 () ;
if ( V_3 == NULL ) {
F_7 ( L_73 ) ;
break;
}
}
V_3 -> V_5 = V_144 -> V_188 ;
V_3 -> V_11 = V_11 ;
F_84 ( V_11 ) ;
F_19 ( L_74 , V_11 -> V_30 ) ;
break;
case V_189 :
V_3 = F_3 ( V_11 ) ;
if ( V_3 == NULL )
break;
F_19 ( L_75 , V_11 -> V_30 ) ;
F_20 ( V_3 ) ;
F_57 ( V_3 -> V_11 ) ;
V_3 -> V_11 = NULL ;
break;
case V_190 :
V_3 = F_3 ( V_11 ) ;
if ( V_3 == NULL )
break;
if ( V_3 -> V_9 != NULL )
F_18 ( V_3 , V_11 ) ;
break;
case V_191 :
V_3 = F_3 ( V_11 ) ;
if ( V_3 == NULL )
break;
if ( V_3 -> V_9 != NULL )
F_20 ( V_3 ) ;
break;
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
break;
default:
break;
}
return V_186 ;
}
static void F_69 ( struct V_162 * V_197 , struct V_1 * V_3 )
{
T_1 V_13 = V_197 -> V_179 . V_198 . V_119 ;
T_6 * V_16 ;
V_16 = V_3 -> V_81 -> V_82 ( V_13 , V_3 ) ;
if ( V_16 == NULL ) {
V_16 = V_3 -> V_81 -> V_83 ( V_13 , V_3 ) ;
V_16 -> V_117 = V_199 ;
V_197 -> type = V_200 ;
V_197 -> V_179 . V_198 = V_16 -> V_90 ;
F_61 ( V_197 , V_3 ) ;
F_85 ( & ( V_16 -> V_201 ) ) ;
V_3 -> V_81 -> V_84 ( V_16 ) ;
return;
}
if ( V_16 -> V_117 == V_202 ) {
V_16 -> V_117 = V_199 ;
V_197 -> type = V_200 ;
V_197 -> V_179 . V_198 = V_16 -> V_90 ;
F_61 ( V_197 , V_3 ) ;
F_85 ( & ( V_16 -> V_201 ) ) ;
V_3 -> V_81 -> V_84 ( V_16 ) ;
return;
}
F_7 ( L_76 ,
( V_3 -> V_11 ) ? V_3 -> V_11 -> V_30 : L_56 ) ;
V_3 -> V_81 -> V_84 ( V_16 ) ;
}
static void F_86 ( struct V_162 * V_197 ,
struct V_1 * V_203 ,
T_6 * V_16 )
{
T_1 V_13 = V_197 -> V_179 . V_198 . V_119 ;
struct V_12 * V_15 = F_5 ( V_13 ) ;
T_9 * V_123 = V_203 -> V_125 -> V_204 ( V_13 , V_203 ) ;
if ( V_123 && V_123 -> V_94 ) {
if ( V_123 -> V_94 -> V_15 . V_23 . V_205 &
V_197 -> V_15 . V_23 . V_205 &
( V_15 ? V_15 -> V_15 . V_23 . V_205 : V_206 | V_207 ) ) {
if ( V_123 -> V_94 -> V_15 . V_23 . V_205 == V_206 )
V_16 -> V_94 = V_123 -> V_94 ;
else if ( V_123 -> V_94 -> V_15 . V_23 . V_24 > 0 )
V_16 -> V_94 = V_123 -> V_94 ;
}
if ( V_16 -> V_94 ) {
F_19 ( L_77 ,
V_203 -> V_11 -> V_30 , & V_13 ) ;
V_203 -> V_125 -> V_84 ( V_123 ) ;
return;
}
}
if ( V_123 != NULL )
V_203 -> V_125 -> V_84 ( V_123 ) ;
V_197 -> type = V_208 ;
if ( V_15 &&
( V_15 -> V_15 . V_23 . V_205 == V_197 -> V_15 . V_23 . V_205 ) ) {
V_197 -> V_15 = V_15 -> V_15 ;
F_7 ( L_78 ,
V_203 -> V_11 -> V_30 ) ;
} else
memset ( & V_197 -> V_15 , 0 , sizeof( struct V_14 ) ) ;
F_61 ( V_197 , V_203 ) ;
}
static void F_68 ( struct V_162 * V_197 , struct V_1 * V_3 )
{
T_1 V_13 = V_197 -> V_179 . V_198 . V_119 ;
T_6 * V_16 = V_3 -> V_81 -> V_82 ( V_13 , V_3 ) ;
F_19 ( L_79 ,
V_3 -> V_11 -> V_30 , & V_13 ) ;
F_28 ( L_80 ,
V_3 -> V_11 -> V_30 , V_16 ) ;
if ( V_16 == NULL ) {
F_7 ( L_81 ,
V_3 -> V_11 -> V_30 ) ;
return;
}
F_87 ( L_82 , V_16 -> V_117 ) ;
if ( V_16 -> V_117 == V_118 ) {
F_7 ( L_83 , V_3 -> V_11 -> V_30 ) ;
V_3 -> V_81 -> V_84 ( V_16 ) ;
return;
}
V_16 -> V_90 = V_197 -> V_179 . V_198 ;
F_85 ( & ( V_16 -> V_209 ) ) ;
F_85 ( & ( V_16 -> V_201 ) ) ;
V_16 -> V_210 = 0 ;
F_87 ( L_84 , V_16 -> V_94 ) ;
if ( V_16 -> V_117 == V_199 &&
V_16 -> V_94 != NULL ) {
V_16 -> V_117 = V_118 ;
V_3 -> V_81 -> V_84 ( V_16 ) ;
return;
}
if ( V_16 -> V_94 != NULL ) {
F_7 ( L_85 ,
V_3 -> V_11 -> V_30 ) ;
V_3 -> V_81 -> V_84 ( V_16 ) ;
return;
}
F_86 ( V_197 , V_3 , V_16 ) ;
V_16 -> V_117 = V_118 ;
V_3 -> V_81 -> V_84 ( V_16 ) ;
return;
}
static void F_70 ( struct V_162 * V_197 , struct V_1 * V_3 )
{
T_1 V_13 = V_197 -> V_179 . V_198 . V_119 ;
T_1 V_211 = V_197 -> V_212 ;
T_6 * V_16 = V_3 -> V_81 -> V_213 ( V_13 , V_3 , V_211 ) ;
if ( V_16 == NULL ) {
F_7 ( L_86 ,
V_3 -> V_11 -> V_30 , & V_13 ) ;
return;
}
do {
F_19 ( L_87 ,
V_3 -> V_11 -> V_30 , & V_13 ) ;
F_88 ( & V_3 -> V_33 ) ;
V_3 -> V_81 -> V_214 ( V_16 , V_3 ) ;
F_89 ( & V_3 -> V_33 ) ;
V_3 -> V_81 -> V_84 ( V_16 ) ;
V_16 = V_3 -> V_81 -> V_213 ( V_13 , V_3 , V_211 ) ;
} while ( V_16 != NULL );
}
static void F_71 ( struct V_162 * V_197 , struct V_1 * V_3 )
{
T_1 V_215 = V_197 -> V_179 . V_216 . V_215 ;
T_9 * V_16 = V_3 -> V_125 -> V_217 ( V_215 , V_3 ) ;
if ( V_16 == NULL ) {
F_19 ( L_88 ,
V_3 -> V_11 -> V_30 ) ;
return;
}
F_90 ( & V_3 -> V_34 ) ;
V_3 -> V_125 -> V_214 ( V_16 , V_3 ) ;
F_91 ( & V_3 -> V_34 ) ;
V_3 -> V_125 -> V_84 ( V_16 ) ;
}
static void F_46 ( struct V_7 * V_8 , T_9 * V_16 )
{
struct V_130 * V_131 ;
struct V_162 * V_218 ;
struct V_69 * V_70 ;
F_19 ( L_89 ) ;
if ( V_8 == NULL ) {
F_7 ( L_90 ) ;
return;
}
V_70 = F_77 ( sizeof( struct V_162 ) , V_182 ) ;
if ( V_70 == NULL ) {
F_7 ( L_91 ) ;
return;
}
F_78 ( V_70 , sizeof( struct V_162 ) ) ;
memset ( V_70 -> V_78 , 0 , sizeof( struct V_162 ) ) ;
V_218 = (struct V_162 * ) V_70 -> V_78 ;
V_218 -> type = V_219 ;
if ( V_16 != NULL )
V_218 -> V_179 . V_216 = V_16 -> V_90 ;
F_79 ( V_8 , V_70 -> V_93 ) ;
V_131 = F_34 ( V_8 ) ;
F_43 ( & V_131 -> V_132 , V_70 ) ;
V_131 -> V_133 ( V_131 ) ;
F_19 ( L_92 ) ;
}
static void F_72 ( struct V_162 * V_197 , struct V_1 * V_3 )
{
T_9 * V_16 ;
F_19 ( L_6 , V_3 -> V_11 -> V_30 ) ;
if ( memcmp ( V_197 -> V_165 , V_3 -> V_159 , V_158 ) ) {
F_7 ( L_93 , V_3 -> V_11 -> V_30 ) ;
return;
}
F_92 ( & V_3 -> V_34 ) ;
V_16 = V_3 -> V_220 ;
while ( V_16 != NULL ) {
F_46 ( V_16 -> V_94 , V_16 ) ;
V_16 = V_16 -> V_6 ;
}
F_93 ( & V_3 -> V_34 ) ;
V_3 -> V_81 -> V_166 ( V_3 ) ;
V_3 -> V_125 -> V_166 ( V_3 ) ;
}
static void F_73 ( struct V_162 * V_197 ,
struct V_1 * V_3 )
{
T_10 V_221 ;
T_9 * V_16 = V_3 -> V_125 -> V_217 ( V_197 -> V_179 . V_216 . V_215 , V_3 ) ;
V_221 = V_197 -> V_179 . V_216 . V_221 ;
F_19 ( L_94 ,
V_3 -> V_11 -> V_30 , V_16 , V_221 ) ;
if ( V_16 == NULL && V_221 ) {
V_16 = V_3 -> V_125 -> V_83 ( V_197 , V_3 ) ;
V_3 -> V_125 -> V_84 ( V_16 ) ;
return;
}
if ( V_221 ) {
V_3 -> V_125 -> V_222 ( V_16 , V_221 ) ;
return;
}
F_90 ( & V_3 -> V_34 ) ;
V_3 -> V_125 -> V_214 ( V_16 , V_3 ) ;
F_91 ( & V_3 -> V_34 ) ;
V_3 -> V_125 -> V_84 ( V_16 ) ;
}
static void F_74 ( struct V_162 * V_163 ,
struct V_1 * V_3 )
{
struct V_143 * V_144 ;
int V_101 , V_223 ;
T_5 V_224 [ 4 + 1 + 1 + 1 + V_158 ] ;
V_224 [ 0 ] = 00 ; V_224 [ 1 ] = 0xa0 ; V_224 [ 2 ] = 0x3e ; V_224 [ 3 ] = 0x2a ;
V_224 [ 4 ] = 1 + 1 + V_158 ;
V_224 [ 5 ] = 0x02 ;
V_224 [ 6 ] = 0x00 ;
memcpy ( & V_224 [ 7 ] , V_163 -> V_165 , V_158 ) ;
memcpy ( V_3 -> V_225 , V_163 -> V_165 , V_158 ) ;
F_19 ( L_95 ,
V_3 -> V_11 ? V_3 -> V_11 -> V_30 : L_56 ) ;
for ( V_101 = 7 ; V_101 < sizeof( V_224 ) ; V_101 ++ )
F_21 ( L_96 , V_224 [ V_101 ] ) ;
F_21 ( L_10 ) ;
if ( V_3 -> V_11 ) {
V_144 = F_56 ( V_3 -> V_11 ) ;
V_223 = V_144 -> V_151 -> V_226 ( V_3 -> V_11 ,
V_3 -> V_11 -> V_227 ,
V_224 , sizeof( V_224 ) ) ;
if ( V_223 == 0 )
F_7 ( L_97 ,
V_3 -> V_11 -> V_30 ) ;
V_223 = V_144 -> V_151 -> V_228 ( V_3 -> V_11 , NULL , 1 , NULL , NULL ) ;
if ( V_223 < 0 )
F_7 ( L_98 ,
V_3 -> V_11 -> V_30 ) ;
}
}
static void F_75 ( struct V_162 * V_197 ,
struct V_1 * V_203 )
{
if ( V_203 -> V_61 )
F_9 ( V_203 -> V_66 ) ;
V_203 -> V_61 = 0 ;
V_203 -> V_66 = F_94 ( V_197 -> V_165 , V_64 , V_17 ) ;
if ( V_203 -> V_66 == NULL ) {
F_7 ( L_91 ) ;
return;
}
V_203 -> V_61 = 1 ;
}
static void F_76 ( struct V_162 * V_197 , struct V_1 * V_3 , int V_229 )
{
T_9 * V_16 ;
V_197 -> type = V_230 ;
F_92 ( & V_3 -> V_34 ) ;
V_16 = V_3 -> V_220 ;
while ( V_16 != NULL ) {
V_197 -> V_179 . V_216 = V_16 -> V_90 ;
F_19 ( L_99 , V_16 -> V_90 . V_215 ) ;
F_61 ( V_197 , V_3 ) ;
V_16 = V_16 -> V_6 ;
}
F_93 ( & V_3 -> V_34 ) ;
V_197 -> type = V_229 ;
F_61 ( V_197 , V_3 ) ;
}
static void F_53 ( void )
{
V_146 . V_231 = V_232 + ( V_39 * V_233 ) ;
V_146 . V_78 = V_146 . V_231 ;
V_146 . V_234 = V_235 ;
F_95 ( & V_146 ) ;
}
static void V_235 ( unsigned long V_236 )
{
struct V_1 * V_3 = V_4 ;
static unsigned long V_237 ;
static unsigned long V_238 ;
while ( V_3 != NULL ) {
V_3 -> V_81 -> V_239 ( V_3 ) ;
V_3 -> V_125 -> V_240 ( V_3 ) ;
if ( V_236 - V_237 >
V_3 -> V_35 . V_41 * V_233 ) {
V_3 -> V_81 -> V_241 ( V_3 ) ;
V_237 = V_236 ;
}
if ( V_236 - V_238 >
V_3 -> V_35 . V_43 * V_233 ) {
V_3 -> V_81 -> V_242 ( V_3 ) ;
V_238 = V_236 ;
}
V_3 = V_3 -> V_6 ;
}
F_53 () ;
}
static int F_96 ( struct V_243 * V_130 , unsigned int V_244 ,
unsigned long V_108 )
{
int V_145 = 0 ;
struct V_7 * V_8 = F_97 ( V_130 ) ;
if ( V_244 != V_245 && V_244 != V_246 )
return - V_247 ;
if ( ! F_98 ( V_248 ) )
return - V_249 ;
switch ( V_244 ) {
case V_245 :
V_145 = F_51 ( V_8 , ( int ) V_108 ) ;
if ( V_145 >= 0 )
V_130 -> V_250 = V_251 ;
break;
case V_246 :
V_145 = F_40 ( V_8 , ( void T_8 * ) V_108 ) ;
break;
default:
break;
}
return V_145 ;
}
static T_11 int F_99 ( void )
{
F_100 ( & V_252 ) ;
if ( F_101 () != 0 )
F_7 ( L_100 ) ;
F_7 ( L_101 ) ;
return 0 ;
}
static void T_12 F_102 ( void )
{
struct V_1 * V_3 , * V_128 ;
struct V_12 * V_15 , * V_253 ;
struct V_143 * V_144 ;
F_103 () ;
F_104 ( & V_146 ) ;
F_105 ( & V_147 ) ;
F_106 ( & V_252 ) ;
V_3 = V_4 ;
V_4 = NULL ;
while ( V_3 != NULL ) {
V_128 = V_3 -> V_6 ;
if ( V_3 -> V_11 != NULL ) {
F_20 ( V_3 ) ;
V_144 = F_56 ( V_3 -> V_11 ) ;
if ( V_144 -> V_151 != NULL )
V_144 -> V_151 -> V_152 = NULL ;
}
F_28 ( L_102 ) ;
V_3 -> V_81 -> V_166 ( V_3 ) ;
V_3 -> V_125 -> V_166 ( V_3 ) ;
F_28 ( L_103 ) ;
F_9 ( V_3 -> V_66 ) ;
memset ( V_3 , 0 , sizeof( struct V_1 ) ) ;
F_28 ( L_104 , V_3 ) ;
F_9 ( V_3 ) ;
F_28 ( L_105 , V_128 ) ;
V_3 = V_128 ;
}
V_15 = V_19 ;
V_19 = NULL ;
while ( V_15 != NULL ) {
V_253 = V_15 -> V_6 ;
F_19 ( L_106 , V_15 ) ;
F_9 ( V_15 ) ;
V_15 = V_253 ;
}
}

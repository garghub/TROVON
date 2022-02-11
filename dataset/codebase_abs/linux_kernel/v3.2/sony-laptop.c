static void F_1 ( unsigned long V_1 )
{
struct V_2 V_3 ;
unsigned long V_4 ;
F_2 ( & V_5 . V_6 , V_4 ) ;
if ( F_3 ( & V_5 . V_7 ,
( unsigned char * ) & V_3 , sizeof( V_3 ) ) == sizeof( V_3 ) ) {
F_4 ( V_3 . V_8 , V_3 . V_9 , 0 ) ;
F_5 ( V_3 . V_8 ) ;
}
if ( F_6 ( & V_5 . V_7 ) != 0 )
F_7 ( & V_5 . V_10 ,
V_11 + F_8 ( 10 ) ) ;
F_9 ( & V_5 . V_6 , V_4 ) ;
}
static void F_10 ( T_1 V_12 )
{
struct V_13 * V_14 = V_5 . V_14 ;
struct V_13 * V_15 = V_5 . V_15 ;
struct V_2 V_3 = { NULL } ;
if ( V_12 == V_16 ||
V_12 == V_17 ) {
return;
}
switch ( V_12 ) {
case V_18 :
case V_19 :
F_11 ( V_14 , V_20 , 1 ) ;
F_5 ( V_14 ) ;
return;
case V_21 :
case V_22 :
F_11 ( V_14 , V_20 , - 1 ) ;
F_5 ( V_14 ) ;
return;
case V_23 :
V_3 . V_9 = V_24 ;
V_3 . V_8 = V_14 ;
break;
default:
if ( V_12 >= F_12 ( V_25 ) ) {
F_13 ( L_1 , V_12 ) ;
break;
}
if ( V_25 [ V_12 ] != - 1 ) {
V_3 . V_9 = V_26 [ V_25 [ V_12 ] ] ;
if ( V_3 . V_9 != V_27 )
V_3 . V_8 = V_15 ;
}
break;
}
if ( V_3 . V_8 ) {
F_4 ( V_3 . V_8 , V_3 . V_9 , 1 ) ;
F_14 ( V_3 . V_8 , V_28 , V_29 , V_12 ) ;
F_5 ( V_3 . V_8 ) ;
F_15 ( & V_5 . V_7 ,
( unsigned char * ) & V_3 , sizeof( V_3 ) ,
& V_5 . V_6 ) ;
F_7 ( & V_5 . V_10 ,
V_11 + F_8 ( 10 ) ) ;
} else
F_13 ( L_2 , V_12 ) ;
}
static int F_16 ( struct V_30 * V_30 )
{
struct V_13 * V_14 ;
struct V_13 * V_15 ;
int V_31 ;
int error ;
if ( F_17 ( 1 , & V_5 . V_32 ) > 1 )
return 0 ;
F_18 ( & V_5 . V_6 ) ;
error = F_19 ( & V_5 . V_7 ,
V_33 , V_34 ) ;
if ( error ) {
F_20 ( L_3 ) ;
goto V_35;
}
F_21 ( & V_5 . V_10 ,
F_1 , 0 ) ;
V_15 = F_22 () ;
if ( ! V_15 ) {
error = - V_36 ;
goto V_37;
}
V_15 -> V_38 = L_4 ;
V_15 -> V_39 . V_40 = V_41 ;
V_15 -> V_39 . V_42 = V_43 ;
V_15 -> V_8 . V_44 = & V_30 -> V_8 ;
F_23 ( V_15 , V_28 , V_29 ) ;
F_24 ( V_45 , V_15 -> V_46 ) ;
V_15 -> V_47 = sizeof( V_26 [ 0 ] ) ;
V_15 -> V_48 = F_12 ( V_26 ) ;
V_15 -> V_49 = & V_26 ;
for ( V_31 = 0 ; V_31 < F_12 ( V_26 ) ; V_31 ++ )
F_24 ( V_26 [ V_31 ] , V_15 -> V_50 ) ;
F_25 ( V_51 , V_15 -> V_50 ) ;
error = F_26 ( V_15 ) ;
if ( error )
goto V_52;
V_5 . V_15 = V_15 ;
V_14 = F_22 () ;
if ( ! V_14 ) {
error = - V_36 ;
goto V_53;
}
V_14 -> V_38 = L_5 ;
V_14 -> V_39 . V_40 = V_41 ;
V_14 -> V_39 . V_42 = V_43 ;
V_15 -> V_8 . V_44 = & V_30 -> V_8 ;
F_23 ( V_14 , V_45 , V_24 ) ;
F_23 ( V_14 , V_54 , V_20 ) ;
error = F_26 ( V_14 ) ;
if ( error )
goto V_55;
V_5 . V_14 = V_14 ;
return 0 ;
V_55:
F_27 ( V_14 ) ;
V_53:
F_28 ( V_15 ) ;
V_15 = NULL ;
V_52:
F_27 ( V_15 ) ;
V_37:
F_29 ( & V_5 . V_7 ) ;
V_35:
F_30 ( & V_5 . V_32 ) ;
return error ;
}
static void F_31 ( void )
{
struct V_2 V_3 = { NULL } ;
if ( ! F_32 ( & V_5 . V_32 ) )
return;
F_33 ( & V_5 . V_10 ) ;
while ( F_3 ( & V_5 . V_7 ,
( unsigned char * ) & V_3 , sizeof( V_3 ) ) == sizeof( V_3 ) ) {
F_4 ( V_3 . V_8 , V_3 . V_9 , 0 ) ;
F_5 ( V_3 . V_8 ) ;
}
F_28 ( V_5 . V_15 ) ;
V_5 . V_15 = NULL ;
if ( V_5 . V_14 ) {
F_28 ( V_5 . V_14 ) ;
V_5 . V_14 = NULL ;
}
F_29 ( & V_5 . V_7 ) ;
}
static int F_34 ( void )
{
int V_56 = 0 ;
if ( F_17 ( 1 , & V_57 ) > 1 )
return 0 ;
V_56 = F_35 ( & V_58 ) ;
if ( V_56 )
goto V_59;
V_60 = F_36 ( L_6 , - 1 ) ;
if ( ! V_60 ) {
V_56 = - V_36 ;
goto V_61;
}
V_56 = F_37 ( V_60 ) ;
if ( V_56 )
goto V_62;
return 0 ;
V_62:
F_38 ( V_60 ) ;
V_60 = NULL ;
V_61:
F_39 ( & V_58 ) ;
V_59:
F_30 ( & V_57 ) ;
return V_56 ;
}
static void F_40 ( void )
{
if ( ! F_32 ( & V_57 ) )
return;
F_41 ( V_60 ) ;
F_39 ( & V_58 ) ;
}
static int F_42 ( T_2 V_63 , char * V_38 , int * V_64 )
{
struct V_65 V_66 ;
union V_67 V_68 ;
T_3 V_69 ;
V_66 . V_70 = sizeof( V_68 ) ;
V_66 . V_71 = & V_68 ;
V_69 = F_43 ( V_63 , V_38 , NULL , & V_66 ) ;
if ( ( V_69 == V_72 ) && ( V_68 . type == V_73 ) ) {
* V_64 = V_68 . integer . V_74 ;
return 0 ;
}
F_44 ( L_7 ) ;
return - 1 ;
}
static int F_45 ( T_2 V_63 , char * V_38 , int V_74 ,
int * V_64 )
{
struct V_75 V_76 ;
union V_67 V_77 ;
struct V_65 V_66 ;
union V_67 V_68 ;
T_3 V_69 ;
V_76 . V_78 = 1 ;
V_76 . V_71 = & V_77 ;
V_77 . type = V_73 ;
V_77 . integer . V_74 = V_74 ;
V_66 . V_70 = sizeof( V_68 ) ;
V_66 . V_71 = & V_68 ;
V_69 = F_43 ( V_63 , V_38 , & V_76 , & V_66 ) ;
if ( V_69 == V_72 ) {
if ( V_64 != NULL ) {
if ( V_68 . type != V_73 ) {
F_44 ( L_8 ) ;
return - 1 ;
}
* V_64 = V_68 . integer . V_74 ;
}
return 0 ;
}
F_44 ( L_9 ) ;
return - 1 ;
}
static T_4 F_46 ( struct V_79 * V_8 ,
struct V_80 * V_81 , char * V_82 )
{
T_4 V_83 = 0 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < F_12 ( V_84 -> V_85 ) ; V_31 ++ ) {
V_83 += snprintf ( V_82 + V_83 , V_86 - V_83 , L_10 ,
V_84 -> V_85 [ V_31 ] ) ;
}
V_83 += snprintf ( V_82 + V_83 , V_86 - V_83 , L_11 ) ;
return V_83 ;
}
static int F_47 ( struct V_87 * V_88 )
{
int V_31 ;
int V_64 ;
V_84 = F_48 ( sizeof( * V_84 ) , V_34 ) ;
if ( ! V_84 )
return - V_36 ;
for ( V_31 = 0 ; V_31 < F_12 ( V_84 -> V_85 ) ; V_31 ++ ) {
if ( ! F_45 ( V_89 ,
L_12 , V_31 + 0x20 , & V_64 ) ) {
F_13 ( L_13 ,
V_64 , V_31 ) ;
V_84 -> V_85 [ V_31 ] = V_64 ;
}
}
if ( V_90 ) {
F_49 ( & V_84 -> V_91 . V_81 ) ;
V_84 -> V_91 . V_81 . V_38 = L_14 ;
V_84 -> V_91 . V_81 . V_92 = V_93 ;
V_84 -> V_91 . V_94 = F_46 ;
if ( F_50 ( & V_88 -> V_8 , & V_84 -> V_91 ) ) {
F_51 ( V_84 ) ;
V_84 = NULL ;
return - 1 ;
}
}
return 0 ;
}
static int F_52 ( struct V_87 * V_88 )
{
if ( V_84 ) {
if ( V_90 )
F_53 ( & V_88 -> V_8 , & V_84 -> V_91 ) ;
F_51 ( V_84 ) ;
V_84 = NULL ;
}
return 0 ;
}
static int F_54 ( int V_63 )
{
int V_31 ;
if ( ! V_84 )
return - 1 ;
for ( V_31 = 0 ; V_31 < 0x10 ; V_31 ++ ) {
if ( V_84 -> V_85 [ V_31 ] == V_63 ) {
F_13 ( L_15 ,
V_63 , V_31 ) ;
return V_31 ;
}
}
F_13 ( L_16 , V_63 ) ;
return - 1 ;
}
static int F_55 ( int V_63 , int V_95 , int * V_64 )
{
int V_56 = 0 ;
int V_96 = F_54 ( V_63 ) ;
if ( V_96 < 0 )
return - 1 ;
V_56 = F_45 ( V_89 , L_17 , V_96 | V_95 ,
V_64 ) ;
F_13 ( L_18 , V_96 | V_95 ,
* V_64 ) ;
return V_56 ;
}
static int F_56 ( const int V_97 , const int V_74 )
{
switch ( V_97 ) {
case V_98 :
return V_74 - 1 ;
case V_99 :
if ( V_74 >= 0 && V_74 < V_100 )
return V_74 + 1 ;
}
return - V_101 ;
}
static int F_57 ( const int V_97 , const int V_74 )
{
if ( V_97 == V_99 ) {
if ( V_74 != 0 && V_74 != 1 )
return - V_101 ;
}
return V_74 ;
}
static T_4 F_58 ( struct V_79 * V_8 , struct V_80 * V_81 ,
char * V_82 )
{
int V_74 ;
struct V_102 * V_103 =
F_59 ( V_81 , struct V_102 , V_91 ) ;
if ( ! * V_103 -> V_104 )
return - V_105 ;
if ( F_42 ( V_89 , * V_103 -> V_104 , & V_74 ) < 0 )
return - V_105 ;
if ( V_103 -> V_106 )
V_74 = V_103 -> V_106 ( V_98 , V_74 ) ;
return snprintf ( V_82 , V_86 , L_19 , V_74 ) ;
}
static T_4 F_60 ( struct V_79 * V_8 ,
struct V_80 * V_81 ,
const char * V_82 , T_5 V_78 )
{
int V_74 ;
struct V_102 * V_103 =
F_59 ( V_81 , struct V_102 , V_91 ) ;
if ( ! V_103 -> V_107 )
return - V_105 ;
if ( V_78 > 31 )
return - V_101 ;
V_74 = F_61 ( V_82 , NULL , 10 ) ;
if ( V_103 -> V_106 )
V_74 = V_103 -> V_106 ( V_99 , V_74 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( F_45 ( V_89 , * V_103 -> V_107 , V_74 , NULL ) < 0 )
return - V_105 ;
V_103 -> V_74 = V_74 ;
V_103 -> V_108 = 1 ;
return V_78 ;
}
static int F_62 ( struct V_109 * V_110 )
{
return F_45 ( V_89 , L_20 ,
V_110 -> V_111 . V_112 + 1 , NULL ) ;
}
static int F_63 ( struct V_109 * V_110 )
{
int V_74 ;
if ( F_42 ( V_89 , L_21 , & V_74 ) )
return 0 ;
return V_74 - 1 ;
}
static int F_64 ( struct V_109 * V_110 )
{
int V_64 ;
struct V_113 * V_114 =
(struct V_113 * ) F_65 ( V_110 ) ;
F_55 ( V_114 -> V_63 , 0x0200 , & V_64 ) ;
return ( V_64 & 0xff ) - V_114 -> V_96 ;
}
static int F_66 ( struct V_109 * V_110 )
{
int V_74 , V_64 ;
struct V_113 * V_114 =
(struct V_113 * ) F_65 ( V_110 ) ;
V_74 = V_110 -> V_111 . V_112 + V_114 -> V_96 ;
if ( F_55 ( V_114 -> V_63 , 0x0100 | ( V_74 << 16 ) , & V_64 ) )
return - V_105 ;
return V_74 ;
}
static void F_67 ( struct V_30 * V_79 , T_6 V_12 )
{
T_6 V_115 = V_12 ;
if ( V_115 >= 0x90 ) {
int V_64 ;
int V_116 = 0 ;
V_115 -= 0x90 ;
if ( F_54 ( 0x100 ) == V_115 )
V_116 = 0x100 ;
if ( F_54 ( 0x127 ) == V_115 )
V_116 = 0x127 ;
if ( V_116 ) {
struct V_117 * V_118 ;
if ( F_55 ( V_116 , 0x200 , & V_64 ) ) {
F_13 ( L_22
L_23 , V_116 ,
V_115 ) ;
V_115 = V_12 ;
} else {
V_115 = V_64 & 0xFF ;
if ( V_116 == 0x100 )
V_118 = V_119 ;
else
V_118 = V_120 ;
for (; V_118 -> V_121 ; V_118 ++ ) {
if ( V_118 -> V_121 == V_115 ) {
V_115 = V_118 -> V_12 ;
break;
}
}
if ( ! V_118 -> V_121 )
F_68 ( L_24 ,
V_116 , V_115 ) ;
else
F_10 ( V_115 ) ;
}
} else if ( F_54 ( V_122 ) == V_115 ) {
F_69 () ;
return;
}
} else
F_10 ( V_115 ) ;
F_13 ( L_25 , V_115 ) ;
F_70 ( V_123 , 1 , V_115 ) ;
}
static T_3 F_71 ( T_2 V_63 , T_6 V_124 ,
void * V_125 , void * * V_126 )
{
struct V_127 * V_128 ;
if ( F_72 ( F_73 ( V_63 , & V_128 ) ) ) {
F_44 ( L_26 ,
( char * ) & V_128 -> V_38 , V_128 -> V_129 ) ;
F_51 ( V_128 ) ;
}
return V_72 ;
}
static int F_74 ( struct V_30 * V_79 )
{
int V_64 ;
F_45 ( V_89 , L_27 , 0xffff , & V_64 ) ;
F_55 ( 0x0100 , 0 , & V_64 ) ;
F_55 ( 0x0101 , 0 , & V_64 ) ;
F_55 ( 0x0102 , 0x100 , & V_64 ) ;
F_55 ( 0x0127 , 0 , & V_64 ) ;
return 0 ;
}
static int F_75 ( struct V_30 * V_79 )
{
struct V_102 * V_103 ;
T_2 V_63 ;
for ( V_103 = V_130 ; V_103 -> V_38 ; V_103 ++ ) {
int V_56 ;
if ( ! V_103 -> V_108 )
continue;
V_56 = F_45 ( V_89 , * V_103 -> V_107 ,
V_103 -> V_74 , NULL ) ;
if ( V_56 < 0 ) {
F_20 ( L_28 , V_131 , V_56 ) ;
break;
}
}
if ( F_72 ( F_76 ( V_89 , L_29 ,
& V_63 ) ) ) {
if ( F_45 ( V_89 , L_29 , 1 , NULL ) )
F_13 ( L_30 ) ;
}
if ( F_72 ( F_76 ( V_89 , L_12 ,
& V_63 ) ) ) {
F_13 ( L_31 ) ;
F_74 ( V_79 ) ;
}
F_69 () ;
F_77 () ;
return 0 ;
}
static void F_78 ( void )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_132 ; V_31 ++ ) {
if ( V_133 [ V_31 ] ) {
F_79 ( V_133 [ V_31 ] ) ;
F_80 ( V_133 [ V_31 ] ) ;
}
}
}
static int F_81 ( void * V_121 , bool V_134 )
{
int V_64 ;
int V_95 = V_135 [ ( long ) V_121 ] + 0x100 ;
if ( ! V_134 )
V_95 |= 0xff0000 ;
return F_55 ( V_122 , V_95 , & V_64 ) ;
}
static int F_82 ( struct V_30 * V_79 ,
enum V_136 V_137 )
{
int V_138 = 0 ;
struct V_139 * V_140 ;
enum V_141 type ;
const char * V_38 ;
int V_64 ;
bool V_142 ;
switch ( V_137 ) {
case V_143 :
type = V_144 ;
V_38 = L_32 ;
break;
case V_145 :
type = V_146 ;
V_38 = L_33 ;
break;
case V_147 :
type = V_148 ;
V_38 = L_34 ;
break;
case V_149 :
type = V_150 ;
V_38 = L_35 ;
break;
default:
return - V_101 ;
}
V_140 = F_83 ( V_38 , & V_79 -> V_8 , type ,
& V_151 , ( void * ) V_137 ) ;
if ( ! V_140 )
return - V_36 ;
F_55 ( V_122 , 0x200 , & V_64 ) ;
V_142 = ! ( V_64 & 0x1 ) ;
F_84 ( V_140 , V_142 ) ;
V_138 = F_85 ( V_140 ) ;
if ( V_138 ) {
F_80 ( V_140 ) ;
return V_138 ;
}
V_133 [ V_137 ] = V_140 ;
return V_138 ;
}
static void F_69 ( void )
{
enum V_136 V_31 ;
int V_64 ;
bool V_142 ;
F_55 ( V_122 , 0x200 , & V_64 ) ;
V_142 = ! ( V_64 & 0x1 ) ;
for ( V_31 = 0 ; V_31 < V_132 ; V_31 ++ ) {
int V_95 = V_135 [ V_31 ] ;
if ( ! V_133 [ V_31 ] )
continue;
if ( V_142 ) {
if ( F_84 ( V_133 [ V_31 ] , true ) ) {
}
continue;
}
F_55 ( V_122 , V_95 , & V_64 ) ;
F_86 ( V_133 [ V_31 ] ,
! ( V_64 & 0xf ) , false ) ;
}
}
static void F_87 ( struct V_30 * V_79 )
{
int V_96 ;
T_1 V_152 , V_31 ;
T_3 V_69 ;
struct V_75 V_76 ;
union V_67 V_77 ;
union V_67 * V_153 ;
struct V_65 V_82 = { V_154 , NULL } ;
V_96 = F_54 ( 0x124 ) ;
if ( V_96 == - 1 ) {
V_96 = F_54 ( 0x135 ) ;
if ( V_96 == - 1 )
return;
else
V_122 = 0x135 ;
} else
V_122 = 0x124 ;
F_13 ( L_36 , V_122 ) ;
V_76 . V_78 = 1 ;
V_76 . V_71 = & V_77 ;
V_77 . type = V_73 ;
V_77 . integer . V_74 = V_96 ;
V_69 = F_43 ( V_89 , L_37 , & V_76 ,
& V_82 ) ;
if ( F_88 ( V_69 ) ) {
F_13 ( L_38 ) ;
return;
}
V_153 = (union V_67 * ) V_82 . V_71 ;
if ( ! V_153 ) {
F_20 ( L_39 ) ;
goto V_155;
}
if ( V_153 -> type != V_156 ) {
F_20 ( L_40 ,
V_153 -> type ) ;
goto V_155;
}
for ( V_31 = 0 ; V_31 < V_153 -> V_82 . V_70 ; V_31 ++ ) {
V_152 = * ( V_153 -> V_82 . V_71 + V_31 ) ;
if ( V_152 == 0xff )
break;
F_13 ( L_41 , V_152 ) ;
if ( V_152 == 0 && ! V_133 [ V_143 ] )
F_82 ( V_79 , V_143 ) ;
if ( V_152 == 0x10 && ! V_133 [ V_145 ] )
F_82 ( V_79 , V_145 ) ;
if ( ( 0xf0 & V_152 ) == 0x20 &&
! V_133 [ V_147 ] )
F_82 ( V_79 , V_147 ) ;
if ( V_152 == 0x30 && ! V_133 [ V_149 ] )
F_82 ( V_79 , V_149 ) ;
}
V_155:
F_51 ( V_82 . V_71 ) ;
return;
}
static T_4 F_89 ( T_1 V_74 )
{
int V_64 ;
if ( V_74 > 1 )
return - V_101 ;
if ( F_55 ( V_157 ,
( V_74 << 0x10 ) | V_158 , & V_64 ) )
return - V_105 ;
F_55 ( V_157 , ( V_74 << 0x10 ) | V_159 ,
& V_64 ) ;
V_160 -> V_92 = V_74 ;
return 0 ;
}
static T_4 F_90 ( struct V_79 * V_8 ,
struct V_80 * V_81 ,
const char * V_82 , T_5 V_78 )
{
int V_56 = 0 ;
unsigned long V_74 ;
if ( V_78 > 31 )
return - V_101 ;
if ( F_91 ( V_82 , 10 , & V_74 ) )
return - V_101 ;
V_56 = F_89 ( V_74 ) ;
if ( V_56 < 0 )
return V_56 ;
return V_78 ;
}
static T_4 F_92 ( struct V_79 * V_8 ,
struct V_80 * V_81 , char * V_82 )
{
T_4 V_78 = 0 ;
V_78 = snprintf ( V_82 , V_86 , L_19 , V_160 -> V_92 ) ;
return V_78 ;
}
static int F_93 ( T_1 V_74 )
{
int V_64 ;
if ( V_74 > 3 )
return - V_101 ;
if ( F_55 ( V_157 ,
( V_74 << 0x10 ) | V_161 , & V_64 ) )
return - V_105 ;
V_160 -> V_162 = V_74 ;
return 0 ;
}
static T_4 F_94 ( struct V_79 * V_8 ,
struct V_80 * V_81 ,
const char * V_82 , T_5 V_78 )
{
int V_56 = 0 ;
unsigned long V_74 ;
if ( V_78 > 31 )
return - V_101 ;
if ( F_91 ( V_82 , 10 , & V_74 ) )
return - V_101 ;
V_56 = F_93 ( V_74 ) ;
if ( V_56 < 0 )
return V_56 ;
return V_78 ;
}
static T_4 F_95 ( struct V_79 * V_8 ,
struct V_80 * V_81 , char * V_82 )
{
T_4 V_78 = 0 ;
V_78 = snprintf ( V_82 , V_86 , L_19 , V_160 -> V_162 ) ;
return V_78 ;
}
static int F_96 ( struct V_87 * V_88 )
{
int V_64 ;
if ( F_55 ( V_157 , V_163 , & V_64 ) )
return 0 ;
if ( ! ( V_64 & 0x02 ) )
return 0 ;
V_160 = F_48 ( sizeof( * V_160 ) , V_34 ) ;
if ( ! V_160 )
return - V_36 ;
F_49 ( & V_160 -> V_164 . V_81 ) ;
V_160 -> V_164 . V_81 . V_38 = L_42 ;
V_160 -> V_164 . V_81 . V_92 = V_93 | V_165 ;
V_160 -> V_164 . V_94 = F_92 ;
V_160 -> V_164 . V_166 = F_90 ;
F_49 ( & V_160 -> V_167 . V_81 ) ;
V_160 -> V_167 . V_81 . V_38 = L_43 ;
V_160 -> V_167 . V_81 . V_92 = V_93 | V_165 ;
V_160 -> V_167 . V_94 = F_95 ;
V_160 -> V_167 . V_166 = F_94 ;
if ( F_50 ( & V_88 -> V_8 , & V_160 -> V_164 ) )
goto V_168;
if ( F_50 ( & V_88 -> V_8 , & V_160 -> V_167 ) )
goto V_169;
F_89 ( V_170 ) ;
F_93 ( V_171 ) ;
return 0 ;
V_169:
F_53 ( & V_88 -> V_8 , & V_160 -> V_164 ) ;
V_168:
F_51 ( V_160 ) ;
V_160 = NULL ;
return - 1 ;
}
static int F_97 ( struct V_87 * V_88 )
{
if ( V_160 ) {
int V_64 ;
F_53 ( & V_88 -> V_8 , & V_160 -> V_164 ) ;
F_53 ( & V_88 -> V_8 , & V_160 -> V_167 ) ;
F_55 ( V_157 , 0x1000 | V_158 , & V_64 ) ;
F_55 ( V_157 , V_161 , & V_64 ) ;
F_51 ( V_160 ) ;
}
return 0 ;
}
static void F_77 ( void )
{
int V_172 = 0 ;
if ( ! V_160 )
return;
if ( V_160 -> V_92 == 0 )
F_55 ( V_157 , V_158 , & V_172 ) ;
if ( V_160 -> V_162 != 0 )
F_55 ( V_157 ,
( V_160 -> V_162 << 0x10 ) | V_161 ,
& V_172 ) ;
}
static void F_98 ( int V_63 ,
struct V_113 * V_111 )
{
int V_96 ;
T_3 V_69 ;
T_1 V_173 , V_31 ;
T_1 V_174 = 0xff , V_175 = 0x00 ;
struct V_75 V_76 ;
union V_67 V_77 ;
union V_67 * V_176 ;
struct V_65 V_82 = { V_154 , NULL } ;
V_111 -> V_63 = V_63 ;
V_111 -> V_96 = 0 ;
V_111 -> V_177 = 0xff ;
V_96 = F_54 ( V_63 ) ;
if ( V_96 < 0 )
return;
V_76 . V_78 = 1 ;
V_76 . V_71 = & V_77 ;
V_77 . type = V_73 ;
V_77 . integer . V_74 = V_96 ;
V_69 = F_43 ( V_89 , L_37 , & V_76 ,
& V_82 ) ;
if ( F_88 ( V_69 ) )
return;
V_176 = (union V_67 * ) V_82 . V_71 ;
if ( ! V_176 ) {
F_20 ( L_44 ) ;
return;
}
if ( V_176 -> type != V_156 ) {
F_20 ( L_40 ,
V_176 -> type ) ;
goto V_178;
}
for ( V_31 = 0 ; V_31 < 9 && V_31 < V_176 -> V_82 . V_70 ; V_31 ++ ) {
V_173 = * ( V_176 -> V_82 . V_71 + V_31 ) ;
F_13 ( L_45 , V_173 ) ;
if ( ! V_173 )
break;
if ( V_173 > V_175 )
V_175 = V_173 ;
if ( V_173 < V_174 )
V_174 = V_173 ;
}
V_111 -> V_96 = V_174 ;
V_111 -> V_177 = V_175 ;
F_13 ( L_46 , V_111 -> V_96 ,
V_111 -> V_177 ) ;
V_178:
F_51 ( V_82 . V_71 ) ;
return;
}
static void F_99 ( void )
{
T_2 V_1 ;
int V_179 = 0 ;
const struct V_180 * V_181 = NULL ;
struct V_182 V_111 ;
if ( F_54 ( 0x12f ) != - 1 ) {
V_181 = & V_183 ;
F_98 ( 0x12f , & V_184 ) ;
V_179 = V_184 . V_177 - V_184 . V_96 ;
} else if ( F_54 ( 0x137 ) != - 1 ) {
V_181 = & V_183 ;
F_98 ( 0x137 , & V_184 ) ;
V_179 = V_184 . V_177 - V_184 . V_96 ;
} else if ( F_72 ( F_76 ( V_89 , L_21 ,
& V_1 ) ) ) {
V_181 = & V_185 ;
V_179 = V_100 - 1 ;
} else
return;
memset ( & V_111 , 0 , sizeof( struct V_182 ) ) ;
V_111 . type = V_186 ;
V_111 . V_179 = V_179 ;
V_184 . V_8 = F_100 ( L_47 , NULL ,
& V_184 ,
V_181 , & V_111 ) ;
if ( F_101 ( V_184 . V_8 ) ) {
F_44 ( L_48 ) ;
V_184 . V_8 = NULL ;
} else
V_184 . V_8 -> V_111 . V_112 =
V_181 -> V_187 ( V_184 . V_8 ) ;
}
static void F_102 ( void )
{
if ( V_184 . V_8 )
F_103 ( V_184 . V_8 ) ;
}
static int F_104 ( struct V_30 * V_79 )
{
T_3 V_69 ;
int V_64 = 0 ;
T_2 V_63 ;
struct V_102 * V_103 ;
F_68 ( L_49 , V_188 , V_189 ) ;
V_123 = V_79 ;
strcpy ( F_105 ( V_79 ) , L_50 ) ;
V_89 = V_79 -> V_63 ;
V_64 = F_106 ( V_79 ) ;
if ( ! V_64 && ! V_79 -> V_69 . V_190 ) {
F_13 ( L_51 ) ;
V_64 = - V_191 ;
goto V_192;
}
V_64 = F_34 () ;
if ( V_64 )
goto V_193;
if ( V_90 ) {
V_69 = F_107 ( V_194 ,
V_89 , 1 , F_71 ,
NULL , NULL , NULL ) ;
if ( F_88 ( V_69 ) ) {
F_44 ( L_52 ) ;
V_64 = - V_191 ;
goto V_193;
}
}
if ( F_72 ( F_76 ( V_89 , L_29 ,
& V_63 ) ) ) {
if ( F_45 ( V_89 , L_29 , 1 , NULL ) )
F_13 ( L_30 ) ;
}
if ( F_72 ( F_76 ( V_89 , L_12 ,
& V_63 ) ) ) {
F_13 ( L_31 ) ;
V_64 = F_47 ( V_60 ) ;
if ( V_64 )
goto V_193;
V_64 = F_96 ( V_60 ) ;
if ( V_64 )
goto V_195;
F_74 ( V_79 ) ;
F_87 ( V_79 ) ;
}
V_64 = F_16 ( V_79 ) ;
if ( V_64 ) {
F_20 ( L_53 ) ;
goto V_196;
}
if ( F_108 () ) {
F_68 ( L_54 ) ;
} else {
F_99 () ;
}
for ( V_103 = V_130 ; V_103 -> V_38 ; ++ V_103 ) {
if ( ! V_90 && V_103 -> V_90 )
continue;
for (; V_103 -> V_104 && * V_103 -> V_104 ; ++ V_103 -> V_104 ) {
if ( F_72 ( F_76 ( V_89 ,
* V_103 -> V_104 ,
& V_63 ) ) ) {
F_13 ( L_55 ,
V_103 -> V_38 , * V_103 -> V_104 ) ;
V_103 -> V_91 . V_81 . V_92 |= V_93 ;
break;
}
}
for (; V_103 -> V_107 && * V_103 -> V_107 ; ++ V_103 -> V_107 ) {
if ( F_72 ( F_76 ( V_89 ,
* V_103 -> V_107 ,
& V_63 ) ) ) {
F_13 ( L_56 ,
V_103 -> V_38 , * V_103 -> V_107 ) ;
V_103 -> V_91 . V_81 . V_92 |= V_165 ;
break;
}
}
if ( V_103 -> V_91 . V_81 . V_92 != 0 ) {
V_64 =
F_50 ( & V_60 -> V_8 ,
& V_103 -> V_91 ) ;
if ( V_64 )
goto V_197;
}
}
return 0 ;
V_197:
for ( V_103 = V_130 ; V_103 -> V_38 ; ++ V_103 ) {
F_53 ( & V_60 -> V_8 , & V_103 -> V_91 ) ;
}
F_102 () ;
F_31 () ;
V_196:
F_97 ( V_60 ) ;
V_195:
F_52 ( V_60 ) ;
V_193:
F_40 () ;
V_192:
F_78 () ;
return V_64 ;
}
static int F_109 ( struct V_30 * V_79 , int type )
{
struct V_102 * V_103 ;
F_102 () ;
V_123 = NULL ;
for ( V_103 = V_130 ; V_103 -> V_38 ; ++ V_103 ) {
F_53 ( & V_60 -> V_8 , & V_103 -> V_91 ) ;
}
F_97 ( V_60 ) ;
F_52 ( V_60 ) ;
F_40 () ;
F_31 () ;
F_78 () ;
F_13 ( V_188 L_57 ) ;
return 0 ;
}
static T_1 F_110 ( T_1 V_8 )
{
T_1 V_198 , V_199 ;
F_111 ( F_112 ( V_200 . V_201 -> V_202 . V_203 + 4 ) & 2 ,
V_204 ) ;
F_113 ( V_8 , V_200 . V_201 -> V_202 . V_203 + 4 ) ;
V_198 = F_112 ( V_200 . V_201 -> V_202 . V_203 + 4 ) ;
V_199 = F_112 ( V_200 . V_201 -> V_202 . V_203 ) ;
F_13 ( L_58 , V_8 , ( V_199 << 8 ) | V_198 ) ;
return V_199 ;
}
static T_1 F_114 ( T_1 V_8 , T_1 V_205 )
{
T_1 V_198 ;
F_111 ( F_112 ( V_200 . V_201 -> V_202 . V_203 + 4 ) & 2 ,
V_204 ) ;
F_113 ( V_8 , V_200 . V_201 -> V_202 . V_203 + 4 ) ;
F_111 ( F_112 ( V_200 . V_201 -> V_202 . V_203 + 4 ) & 2 ,
V_204 ) ;
F_113 ( V_205 , V_200 . V_201 -> V_202 . V_203 ) ;
V_198 = F_112 ( V_200 . V_201 -> V_202 . V_203 ) ;
F_13 ( L_59 , V_8 , V_205 , V_198 ) ;
return V_198 ;
}
static T_1 F_115 ( T_1 V_8 , T_1 V_205 , T_1 V_206 )
{
T_1 V_198 ;
F_111 ( F_112 ( V_200 . V_201 -> V_202 . V_203 + 4 ) & 2 , V_204 ) ;
F_113 ( V_8 , V_200 . V_201 -> V_202 . V_203 + 4 ) ;
F_111 ( F_112 ( V_200 . V_201 -> V_202 . V_203 + 4 ) & 2 , V_204 ) ;
F_113 ( V_205 , V_200 . V_201 -> V_202 . V_203 ) ;
F_111 ( F_112 ( V_200 . V_201 -> V_202 . V_203 + 4 ) & 2 , V_204 ) ;
F_113 ( V_206 , V_200 . V_201 -> V_202 . V_203 ) ;
V_198 = F_112 ( V_200 . V_201 -> V_202 . V_203 ) ;
F_13 ( L_60 ,
V_8 , V_205 , V_206 , V_198 ) ;
return V_198 ;
}
static int F_116 ( const T_1 V_207 , const T_1 V_115 )
{
if ( V_207 == 0x31 ) {
if ( V_115 == 0x5c || V_115 == 0x5f )
F_110 ( 0xA0 ) ;
else if ( V_115 == 0x61 )
F_110 ( 0xB3 ) ;
return 0 ;
}
return 1 ;
}
static void F_117 ( struct V_208 * V_8 )
{
struct V_209 * V_210 ;
V_210 = F_118 ( V_211 ,
V_212 , NULL ) ;
if ( V_210 ) {
V_8 -> V_213 = V_214 ;
V_8 -> V_215 = V_216 ;
V_8 -> V_217 = V_218 ;
goto V_59;
}
V_210 = F_118 ( V_211 ,
V_219 , NULL ) ;
if ( V_210 ) {
V_8 -> V_213 = V_220 ;
V_8 -> V_215 = V_221 ;
V_8 -> V_217 = V_222 ;
goto V_59;
}
V_210 = F_118 ( V_211 ,
V_223 , NULL ) ;
if ( V_210 ) {
V_8 -> V_213 = V_224 ;
V_8 -> V_225 = F_116 ;
V_8 -> V_215 = V_226 ;
V_8 -> V_217 = V_227 ;
goto V_59;
}
V_210 = F_118 ( V_211 ,
V_228 , NULL ) ;
if ( V_210 ) {
V_8 -> V_213 = V_224 ;
V_8 -> V_225 = F_116 ;
V_8 -> V_215 = V_226 ;
V_8 -> V_217 = V_227 ;
goto V_59;
}
V_210 = F_118 ( V_211 ,
V_229 , NULL ) ;
if ( V_210 ) {
V_8 -> V_213 = V_224 ;
V_8 -> V_225 = F_116 ;
V_8 -> V_215 = V_226 ;
V_8 -> V_217 = V_227 ;
goto V_59;
}
V_8 -> V_213 = V_220 ;
V_8 -> V_215 = V_221 ;
V_8 -> V_217 = V_222 ;
V_59:
if ( V_210 )
F_119 ( V_210 ) ;
F_68 ( L_61 ,
V_8 -> V_213 == V_214 ? 1 :
V_8 -> V_213 == V_220 ? 2 : 3 ) ;
}
static int F_120 ( void )
{
T_1 V_206 ;
V_206 = F_114 ( 0x8f , V_230 ) ;
return ( V_206 != 0xff && ( V_206 & V_231 ) ) ;
}
static int F_121 ( void )
{
if ( ! V_232 ) {
F_44 ( L_62 ) ;
return - V_191 ;
}
F_111 ( F_115 ( 0x90 , V_233 ,
V_234 ) ,
V_235 ) ;
if ( V_200 . V_236 ) {
F_114 ( 0x91 , 0 ) ;
V_200 . V_236 = 0 ;
}
return 0 ;
}
static int F_122 ( void )
{
int V_31 , V_237 , V_238 ;
if ( ! V_232 ) {
F_44 ( L_62 ) ;
return - V_191 ;
}
if ( V_200 . V_236 )
return 0 ;
for ( V_237 = 5 ; V_237 > 0 ; V_237 -- ) {
for ( V_238 = 0 ; V_238 < 100 && F_114 ( 0x91 , 0x1 ) ; V_238 ++ )
F_123 ( 10 ) ;
F_110 ( 0x93 ) ;
for ( V_31 = 400 ; V_31 > 0 ; V_31 -- ) {
if ( F_120 () )
break;
F_123 ( 10 ) ;
}
if ( V_31 )
break;
}
if ( V_237 == 0 ) {
F_44 ( L_63 ) ;
return - V_191 ;
}
F_111 ( F_115 ( 0x90 , V_239 ,
0x5a ) ,
V_235 ) ;
V_200 . V_236 = 1 ;
return 0 ;
}
int F_124 ( int V_240 , T_1 V_74 )
{
if ( ! V_232 )
return - V_105 ;
F_125 ( & V_200 . V_241 ) ;
switch ( V_240 ) {
case V_242 :
if ( V_74 )
F_122 () ;
else
F_121 () ;
break;
case V_243 :
F_111 ( F_115 ( 0x90 , V_244 , V_74 ) ,
V_235 ) ;
break;
case V_245 :
F_111 ( F_115 ( 0x90 , V_246 , V_74 ) ,
V_235 ) ;
break;
case V_247 :
F_111 ( F_115 ( 0x90 , V_248 , V_74 ) ,
V_235 ) ;
break;
case V_249 :
F_111 ( F_115 ( 0x90 , V_250 , V_74 ) ,
V_235 ) ;
break;
case V_251 :
F_111 ( F_115 ( 0x90 , V_252 , V_74 ) ,
V_235 ) ;
break;
case V_253 :
F_111 ( F_115 ( 0x90 , V_233 , V_74 ) ,
V_235 ) ;
break;
case V_254 :
F_111 ( F_115 ( 0x90 , V_255 , V_74 ) ,
V_235 ) ;
break;
default:
F_20 ( L_64 , V_240 ) ;
break;
}
F_126 ( & V_200 . V_241 ) ;
return 0 ;
}
static void F_127 ( T_1 V_256 )
{
V_256 = ! ! V_256 ;
if ( V_200 . V_257 == V_256 )
return;
F_114 ( 0xB0 , V_256 ) ;
F_110 ( 0x82 ) ;
V_200 . V_257 = V_256 ;
}
static T_4 F_128 ( struct V_79 * V_8 ,
struct V_80 * V_81 ,
const char * V_82 , T_5 V_78 )
{
unsigned long V_74 ;
if ( V_78 > 31 )
return - V_101 ;
V_74 = F_61 ( V_82 , NULL , 10 ) ;
F_125 ( & V_200 . V_241 ) ;
F_127 ( V_74 ) ;
F_126 ( & V_200 . V_241 ) ;
return V_78 ;
}
static T_4 F_129 ( struct V_79 * V_8 ,
struct V_80 * V_81 , char * V_82 )
{
T_4 V_78 ;
F_125 ( & V_200 . V_241 ) ;
V_78 = snprintf ( V_82 , V_86 , L_19 , V_200 . V_257 ) ;
F_126 ( & V_200 . V_241 ) ;
return V_78 ;
}
static void F_130 ( T_1 V_256 )
{
V_256 = ! ! V_256 ;
if ( V_200 . V_258 == V_256 )
return;
F_114 ( 0x96 , V_256 ) ;
F_110 ( 0x82 ) ;
V_200 . V_258 = V_256 ;
}
static T_4 F_131 ( struct V_79 * V_8 ,
struct V_80 * V_81 ,
const char * V_82 , T_5 V_78 )
{
unsigned long V_74 ;
if ( V_78 > 31 )
return - V_101 ;
V_74 = F_61 ( V_82 , NULL , 10 ) ;
F_125 ( & V_200 . V_241 ) ;
F_130 ( V_74 ) ;
F_126 ( & V_200 . V_241 ) ;
return V_78 ;
}
static T_4 F_132 ( struct V_79 * V_8 ,
struct V_80 * V_81 , char * V_82 )
{
T_4 V_78 = 0 ;
F_125 ( & V_200 . V_241 ) ;
V_78 = snprintf ( V_82 , V_86 , L_19 , V_200 . V_258 ) ;
F_126 ( & V_200 . V_241 ) ;
return V_78 ;
}
static int F_133 ( unsigned long V_74 )
{
return F_134 ( V_259 , V_74 ) ;
}
static int F_135 ( T_1 * V_74 )
{
return F_136 ( V_259 , V_74 ) ;
}
static T_4 F_137 ( struct V_79 * V_8 ,
struct V_80 * V_81 ,
const char * V_82 , T_5 V_78 )
{
unsigned long V_74 ;
if ( V_78 > 31 )
return - V_101 ;
V_74 = F_61 ( V_82 , NULL , 10 ) ;
if ( F_133 ( V_74 ) )
return - V_105 ;
return V_78 ;
}
static T_4 F_138 ( struct V_79 * V_8 ,
struct V_80 * V_81 , char * V_82 )
{
T_1 V_74 = 0 ;
if ( F_135 ( & V_74 ) )
return - V_105 ;
return snprintf ( V_82 , V_86 , L_19 , V_74 ) ;
}
static int F_139 ( int V_260 , struct V_261 * V_262 , int V_263 )
{
return F_140 ( V_260 , V_262 , V_263 , & V_264 . V_265 ) ;
}
static int F_141 ( struct V_266 * V_266 , struct V_261 * V_261 )
{
F_30 ( & V_264 . V_267 ) ;
return 0 ;
}
static int F_142 ( struct V_266 * V_266 , struct V_261 * V_261 )
{
unsigned long V_4 ;
F_2 ( & V_264 . V_6 , V_4 ) ;
if ( F_143 ( & V_264 . V_267 ) == 1 )
F_144 ( & V_264 . V_7 ) ;
F_9 ( & V_264 . V_6 , V_4 ) ;
return 0 ;
}
static T_4 F_145 ( struct V_261 * V_261 , char T_7 * V_268 ,
T_5 V_78 , T_8 * V_269 )
{
T_4 V_56 ;
unsigned char V_270 ;
if ( ( F_6 ( & V_264 . V_7 ) == 0 ) &&
( V_261 -> V_271 & V_272 ) )
return - V_273 ;
V_56 = F_146 ( V_264 . V_274 ,
F_6 ( & V_264 . V_7 ) != 0 ) ;
if ( V_56 )
return V_56 ;
while ( V_56 < V_78 &&
( F_147 ( & V_264 . V_7 , & V_270 , sizeof( V_270 ) ,
& V_264 . V_6 ) == sizeof( V_270 ) ) ) {
if ( F_148 ( V_270 , V_268 ++ ) )
return - V_275 ;
V_56 ++ ;
}
if ( V_56 > 0 ) {
struct V_266 * V_266 = V_261 -> V_276 . V_277 -> V_278 ;
V_266 -> V_279 = F_149 ( V_266 -> V_280 ) ;
}
return V_56 ;
}
static unsigned int F_150 ( struct V_261 * V_261 , T_9 * V_281 )
{
F_151 ( V_261 , & V_264 . V_274 , V_281 ) ;
if ( F_6 ( & V_264 . V_7 ) )
return V_282 | V_283 ;
return 0 ;
}
static int F_152 ( T_1 V_284 , T_10 * V_74 )
{
T_1 V_285 , V_286 ;
if ( F_136 ( V_284 , & V_285 ) )
return - 1 ;
if ( F_136 ( V_284 + 1 , & V_286 ) )
return - 1 ;
* V_74 = V_285 | ( V_286 << 8 ) ;
return 0 ;
}
static long F_153 ( struct V_261 * V_287 , unsigned int V_288 ,
unsigned long V_289 )
{
int V_56 = 0 ;
void T_7 * V_290 = ( void T_7 * ) V_289 ;
T_1 V_291 ;
T_10 V_292 ;
int V_74 ;
F_125 ( & V_200 . V_241 ) ;
switch ( V_288 ) {
case V_293 :
if ( V_184 . V_8 == NULL ) {
V_56 = - V_105 ;
break;
}
if ( F_42 ( V_89 , L_21 , & V_74 ) ) {
V_56 = - V_105 ;
break;
}
V_291 = ( ( V_74 & 0xff ) - 1 ) << 5 ;
if ( F_154 ( V_290 , & V_291 , sizeof( V_291 ) ) )
V_56 = - V_275 ;
break;
case V_294 :
if ( V_184 . V_8 == NULL ) {
V_56 = - V_105 ;
break;
}
if ( F_155 ( & V_291 , V_290 , sizeof( V_291 ) ) ) {
V_56 = - V_275 ;
break;
}
if ( F_45 ( V_89 , L_20 ,
( V_291 >> 5 ) + 1 , NULL ) ) {
V_56 = - V_105 ;
break;
}
V_184 . V_8 -> V_111 . V_112 =
F_63 ( V_184 . V_8 ) ;
break;
case V_295 :
if ( F_152 ( V_296 , & V_292 ) ) {
V_56 = - V_105 ;
break;
}
if ( F_154 ( V_290 , & V_292 , sizeof( V_292 ) ) )
V_56 = - V_275 ;
break;
case V_297 :
if ( F_152 ( V_298 , & V_292 ) ) {
V_56 = - V_105 ;
break;
}
if ( F_154 ( V_290 , & V_292 , sizeof( V_292 ) ) )
V_56 = - V_275 ;
break;
case V_299 :
if ( F_152 ( V_300 , & V_292 ) ) {
V_56 = - V_105 ;
break;
}
if ( F_154 ( V_290 , & V_292 , sizeof( V_292 ) ) )
V_56 = - V_275 ;
break;
case V_301 :
if ( F_152 ( V_302 , & V_292 ) ) {
V_56 = - V_105 ;
break;
}
if ( F_154 ( V_290 , & V_292 , sizeof( V_292 ) ) )
V_56 = - V_275 ;
break;
case V_303 :
if ( F_136 ( V_304 , & V_291 ) ) {
V_56 = - V_105 ;
break;
}
V_291 &= 0x07 ;
if ( F_154 ( V_290 , & V_291 , sizeof( V_291 ) ) )
V_56 = - V_275 ;
break;
case V_305 :
V_291 = V_200 . V_258 ;
if ( F_154 ( V_290 , & V_291 , sizeof( V_291 ) ) )
V_56 = - V_275 ;
break;
case V_306 :
if ( F_155 ( & V_291 , V_290 , sizeof( V_291 ) ) ) {
V_56 = - V_275 ;
break;
}
F_130 ( V_291 ) ;
break;
case V_307 :
if ( F_135 ( & V_291 ) ) {
V_56 = - V_105 ;
break;
}
if ( F_154 ( V_290 , & V_291 , sizeof( V_291 ) ) )
V_56 = - V_275 ;
break;
case V_308 :
if ( F_155 ( & V_291 , V_290 , sizeof( V_291 ) ) ) {
V_56 = - V_275 ;
break;
}
if ( F_133 ( V_291 ) )
V_56 = - V_105 ;
break;
case V_309 :
if ( F_136 ( V_310 , & V_291 ) ) {
V_56 = - V_105 ;
break;
}
if ( F_154 ( V_290 , & V_291 , sizeof( V_291 ) ) )
V_56 = - V_275 ;
break;
default:
V_56 = - V_101 ;
}
F_126 ( & V_200 . V_241 ) ;
return V_56 ;
}
static void F_156 ( T_1 V_12 )
{
F_15 ( & V_264 . V_7 , ( unsigned char * ) & V_12 ,
sizeof( V_12 ) , & V_264 . V_6 ) ;
F_157 ( & V_264 . V_265 , V_311 , V_312 ) ;
F_158 ( & V_264 . V_274 ) ;
}
static int F_159 ( void )
{
int error ;
F_18 ( & V_264 . V_6 ) ;
error =
F_19 ( & V_264 . V_7 , V_33 , V_34 ) ;
if ( error ) {
F_20 ( L_3 ) ;
return error ;
}
F_160 ( & V_264 . V_274 ) ;
if ( V_313 != - 1 )
V_314 . V_313 = V_313 ;
error = F_161 ( & V_314 ) ;
if ( error ) {
F_20 ( L_65 ) ;
goto V_37;
}
if ( V_313 == - 1 )
F_68 ( L_66 ,
V_314 . V_313 ) ;
return 0 ;
V_37:
F_29 ( & V_264 . V_7 ) ;
return error ;
}
static void F_162 ( void )
{
F_163 ( & V_314 ) ;
F_29 ( & V_264 . V_7 ) ;
}
static int F_159 ( void ) { return 0 ; }
static void F_162 ( void ) { }
static void F_156 ( T_1 V_12 ) { }
static T_3
F_164 ( struct V_315 * V_316 , void * V_125 )
{
T_6 V_31 ;
struct V_208 * V_8 = (struct V_208 * ) V_125 ;
switch ( V_316 -> type ) {
case V_317 :
{
struct V_318 * V_319 = F_48 ( sizeof( * V_319 ) , V_34 ) ;
if ( ! V_319 )
return V_320 ;
F_165 ( & V_319 -> V_321 , & V_8 -> V_322 ) ;
return V_72 ;
}
case V_323 :
return V_72 ;
case V_324 :
{
struct V_325 * V_326 = & V_316 -> V_121 . V_327 ;
struct V_328 * V_329 = NULL ;
if ( ! V_326 || ! V_326 -> V_330 ) {
F_13 ( L_67 ) ;
return V_72 ;
}
for ( V_31 = 0 ; V_31 < V_326 -> V_330 ; V_31 ++ ) {
if ( ! V_326 -> V_331 [ V_31 ] ) {
F_44 ( L_68 ,
V_326 -> V_331 [ V_31 ] ) ;
continue;
}
V_329 = F_48 ( sizeof( * V_329 ) ,
V_34 ) ;
if ( ! V_329 )
return V_320 ;
F_165 ( & V_329 -> V_321 , & V_8 -> V_331 ) ;
V_329 -> V_327 . V_332 = V_326 -> V_332 ;
V_329 -> V_327 . V_333 = V_326 -> V_333 ;
V_329 -> V_327 . V_334 = V_326 -> V_334 ;
V_329 -> V_327 . V_330 = 1 ;
V_329 -> V_327 . V_331 [ 0 ] = V_326 -> V_331 [ V_31 ] ;
}
return V_72 ;
}
case V_335 :
{
struct V_336 * V_337 = & V_316 -> V_121 . V_337 ;
struct V_318 * V_319 =
F_166 ( & V_8 -> V_322 , struct V_318 , V_321 ) ;
if ( ! V_337 ) {
F_13 ( L_69 ) ;
return V_72 ;
}
if ( ! V_319 -> V_202 . V_203 ) {
memcpy ( & V_319 -> V_202 , V_337 , sizeof( * V_337 ) ) ;
F_13 ( L_70 , V_319 -> V_202 . V_203 ,
V_319 -> V_202 . V_338 ) ;
}
else if ( ! V_319 -> V_339 . V_203 ) {
memcpy ( & V_319 -> V_339 , V_337 , sizeof( * V_337 ) ) ;
F_13 ( L_71 , V_319 -> V_339 . V_203 ,
V_319 -> V_339 . V_338 ) ;
}
else {
F_20 ( L_72 ) ;
return V_320 ;
}
return V_72 ;
}
default:
F_13 ( L_73 ,
V_316 -> type ) ;
case V_340 :
return V_72 ;
}
return V_341 ;
}
static int F_167 ( struct V_30 * V_79 )
{
int V_64 = 0 ;
T_3 V_69 = V_72 ;
if ( ! V_79 )
return - V_101 ;
F_13 ( L_74 ) ;
V_64 = F_106 ( V_79 ) ;
if ( V_64 ) {
F_44 ( L_75 ) ;
goto V_342;
}
if ( ! V_79 -> V_69 . V_343 )
F_13 ( L_76 ) ;
else
F_13 ( L_77 ) ;
F_13 ( L_78 , V_344 ) ;
V_69 = F_168 ( V_79 -> V_63 , V_344 ,
F_164 , & V_200 ) ;
if ( F_88 ( V_69 ) ) {
F_44 ( L_79 , V_344 ) ;
V_64 = - V_191 ;
}
V_342:
return V_64 ;
}
static int F_169 ( struct V_30 * V_79 )
{
T_3 V_56 = F_43 ( V_79 -> V_63 , L_80 , NULL ,
NULL ) ;
if ( F_88 ( V_56 ) && V_56 != V_345 )
return - V_346 ;
F_13 ( L_76 ) ;
return 0 ;
}
static int F_170 ( struct V_30 * V_79 ,
struct V_318 * V_319 , struct V_328 * V_327 )
{
T_3 V_69 ;
int V_64 = 0 ;
struct {
struct V_315 V_347 ;
struct V_315 V_348 ;
struct V_315 V_349 ;
struct V_315 V_350 ;
} * V_316 ;
struct V_65 V_82 = { 0 , NULL } ;
if ( ! V_319 || ! V_327 )
return - V_101 ;
V_316 = F_48 ( sizeof( * V_316 ) + 1 , V_34 ) ;
if ( ! V_316 )
return - V_36 ;
V_82 . V_70 = sizeof( * V_316 ) + 1 ;
V_82 . V_71 = V_316 ;
if ( V_200 . V_213 == V_214 ) {
V_316 -> V_347 . type = V_335 ;
V_316 -> V_347 . V_70 = sizeof( struct V_315 ) ;
memcpy ( & V_316 -> V_347 . V_121 . V_337 , & V_319 -> V_202 ,
sizeof( struct V_336 ) ) ;
V_316 -> V_348 . type = V_335 ;
V_316 -> V_348 . V_70 = sizeof( struct V_315 ) ;
memcpy ( & V_316 -> V_348 . V_121 . V_337 , & V_319 -> V_339 ,
sizeof( struct V_336 ) ) ;
V_316 -> V_349 . type = V_324 ;
V_316 -> V_349 . V_70 = sizeof( struct V_315 ) ;
memcpy ( & V_316 -> V_349 . V_121 . V_327 , & V_327 -> V_327 ,
sizeof( struct V_325 ) ) ;
V_316 -> V_349 . V_121 . V_327 . V_334 = V_351 ;
V_316 -> V_350 . type = V_340 ;
}
else {
V_316 -> V_347 . type = V_335 ;
V_316 -> V_347 . V_70 = sizeof( struct V_315 ) ;
memcpy ( & V_316 -> V_347 . V_121 . V_337 , & V_319 -> V_202 ,
sizeof( struct V_336 ) ) ;
V_316 -> V_348 . type = V_324 ;
V_316 -> V_348 . V_70 = sizeof( struct V_315 ) ;
memcpy ( & V_316 -> V_348 . V_121 . V_327 , & V_327 -> V_327 ,
sizeof( struct V_325 ) ) ;
V_316 -> V_348 . V_121 . V_327 . V_334 = V_351 ;
V_316 -> V_349 . type = V_340 ;
}
F_13 ( L_81 ) ;
V_69 = F_171 ( V_79 -> V_63 , & V_82 ) ;
if ( F_88 ( V_69 ) ) {
F_20 ( L_82 ) ;
V_64 = - V_191 ;
goto V_342;
}
F_110 ( 0x82 ) ;
F_114 ( 0x81 , 0xff ) ;
F_110 ( V_352 ? 0x92 : 0x82 ) ;
V_342:
F_51 ( V_316 ) ;
return V_64 ;
}
static T_11 V_328 ( int V_327 , void * V_353 )
{
int V_31 , V_237 ;
T_1 V_115 = 0 ;
T_1 V_207 = 0 ;
T_1 V_354 = 0 ;
struct V_208 * V_8 = (struct V_208 * ) V_353 ;
V_115 = F_112 ( V_8 -> V_201 -> V_202 . V_203 ) ;
if ( V_8 -> V_201 -> V_339 . V_203 )
V_207 = F_112 ( V_8 -> V_201 -> V_339 . V_203 ) ;
else
V_207 = F_112 ( V_8 -> V_201 -> V_202 . V_203 +
V_8 -> V_215 ) ;
F_13 ( L_83 ,
V_115 , V_207 , V_8 -> V_201 -> V_202 . V_203 ,
V_8 -> V_215 ) ;
if ( V_115 == 0x00 || V_115 == 0xff )
return V_355 ;
for ( V_31 = 0 ; V_8 -> V_217 [ V_31 ] . V_356 ; V_31 ++ ) {
if ( ( V_207 & V_8 -> V_217 [ V_31 ] . V_121 ) !=
V_8 -> V_217 [ V_31 ] . V_121 )
continue;
if ( ! ( V_356 & V_8 -> V_217 [ V_31 ] . V_356 ) )
continue;
for ( V_237 = 0 ; V_8 -> V_217 [ V_31 ] . V_357 [ V_237 ] . V_12 ; V_237 ++ ) {
if ( V_115 == V_8 -> V_217 [ V_31 ] . V_357 [ V_237 ] . V_121 ) {
V_354 =
V_8 -> V_217 [ V_31 ] . V_357 [ V_237 ] . V_12 ;
if ( ! V_354 )
return V_355 ;
goto V_358;
}
}
}
if ( V_8 -> V_225 && V_8 -> V_225 ( V_207 , V_115 ) == 0 )
return V_355 ;
F_13 ( L_84 ,
V_115 , V_207 , V_8 -> V_201 -> V_202 . V_203 ,
V_8 -> V_215 ) ;
return V_355 ;
V_358:
F_10 ( V_354 ) ;
F_70 ( V_8 -> V_359 , 1 , V_354 ) ;
F_156 ( V_354 ) ;
return V_355 ;
}
static int F_172 ( struct V_30 * V_79 , int type )
{
struct V_318 * V_337 , * V_360 ;
struct V_328 * V_327 , * V_361 ;
if ( F_169 ( V_79 ) ) {
F_20 ( L_85 ) ;
return - V_346 ;
}
F_173 ( V_200 . V_362 -> V_327 . V_331 [ 0 ] , & V_200 ) ;
F_174 ( V_200 . V_201 -> V_202 . V_203 ,
V_200 . V_201 -> V_202 . V_338 ) ;
if ( V_200 . V_201 -> V_339 . V_203 )
F_174 ( V_200 . V_201 -> V_339 . V_203 ,
V_200 . V_201 -> V_339 . V_338 ) ;
F_162 () ;
F_31 () ;
F_175 ( & V_60 -> V_8 . V_363 , & V_364 ) ;
F_40 () ;
F_176 (io, tmp_io, &spic_dev.ioports, list) {
F_177 ( & V_337 -> V_321 ) ;
F_51 ( V_337 ) ;
}
F_176 (irq, tmp_irq, &spic_dev.interrupts, list) {
F_177 ( & V_327 -> V_321 ) ;
F_51 ( V_327 ) ;
}
V_200 . V_201 = NULL ;
V_200 . V_362 = NULL ;
F_13 ( V_365 L_57 ) ;
return 0 ;
}
static int F_178 ( struct V_30 * V_79 )
{
int V_64 ;
struct V_318 * V_337 , * V_360 ;
struct V_328 * V_327 , * V_361 ;
F_68 ( L_49 , V_365 , V_189 ) ;
V_200 . V_359 = V_79 ;
strcpy ( F_105 ( V_79 ) , L_50 ) ;
F_117 ( & V_200 ) ;
F_179 ( & V_200 . V_241 ) ;
V_64 = F_167 ( V_79 ) ;
if ( V_64 ) {
F_20 ( L_86 ) ;
goto V_366;
}
V_64 = F_16 ( V_79 ) ;
if ( V_64 ) {
F_20 ( L_53 ) ;
goto V_366;
}
if ( F_159 () )
goto V_367;
F_180 (io, &spic_dev.ioports, list) {
if ( F_181 ( V_337 -> V_202 . V_203 , V_337 -> V_202 . V_338 ,
L_87 ) ) {
F_13 ( L_88 ,
V_337 -> V_202 . V_203 , V_337 -> V_202 . V_368 ,
V_337 -> V_202 . V_338 ) ;
if ( V_337 -> V_339 . V_203 ) {
if ( F_181 ( V_337 -> V_339 . V_203 ,
V_337 -> V_339 . V_338 ,
L_87 ) ) {
F_13 ( L_89 ,
V_337 -> V_339 . V_203 , V_337 -> V_339 . V_368 ,
V_337 -> V_339 . V_338 ) ;
V_200 . V_201 = V_337 ;
break;
}
else {
F_13 ( L_90
L_91 ,
V_337 -> V_339 . V_203 , V_337 -> V_339 . V_368 ,
V_337 -> V_339 . V_338 ) ;
F_174 ( V_337 -> V_202 . V_203 ,
V_337 -> V_202 . V_338 ) ;
}
}
else {
V_200 . V_201 = V_337 ;
break;
}
}
}
if ( ! V_200 . V_201 ) {
F_20 ( L_92 ) ;
V_64 = - V_191 ;
goto V_369;
}
F_180 (irq, &spic_dev.interrupts, list) {
if ( ! F_182 ( V_327 -> V_327 . V_331 [ 0 ] , V_328 ,
0 , L_6 , & V_200 ) ) {
F_13 ( L_93
L_94 ,
V_327 -> V_327 . V_331 [ 0 ] ,
V_327 -> V_327 . V_332 ,
V_327 -> V_327 . V_333 ,
V_327 -> V_327 . V_334 ) ;
V_200 . V_362 = V_327 ;
break;
}
}
if ( ! V_200 . V_362 ) {
F_20 ( L_95 ) ;
V_64 = - V_191 ;
goto V_370;
}
V_64 = F_170 ( V_79 , V_200 . V_201 , V_200 . V_362 ) ;
if ( V_64 ) {
F_20 ( L_96 ) ;
goto V_371;
}
V_200 . V_258 = - 1 ;
V_64 = F_34 () ;
if ( V_64 )
goto V_372;
V_64 = F_183 ( & V_60 -> V_8 . V_363 , & V_364 ) ;
if ( V_64 )
goto V_373;
return 0 ;
V_373:
F_40 () ;
V_372:
F_169 ( V_79 ) ;
V_371:
F_173 ( V_200 . V_362 -> V_327 . V_331 [ 0 ] , & V_200 ) ;
V_370:
F_174 ( V_200 . V_201 -> V_202 . V_203 ,
V_200 . V_201 -> V_202 . V_338 ) ;
if ( V_200 . V_201 -> V_339 . V_203 )
F_174 ( V_200 . V_201 -> V_339 . V_203 ,
V_200 . V_201 -> V_339 . V_338 ) ;
V_369:
F_162 () ;
V_367:
F_31 () ;
V_366:
F_176 (io, tmp_io, &spic_dev.ioports, list) {
F_177 ( & V_337 -> V_321 ) ;
F_51 ( V_337 ) ;
}
F_176 (irq, tmp_irq, &spic_dev.interrupts, list) {
F_177 ( & V_327 -> V_321 ) ;
F_51 ( V_327 ) ;
}
V_200 . V_201 = NULL ;
V_200 . V_362 = NULL ;
return V_64 ;
}
static int F_184 ( struct V_30 * V_79 , T_12 V_256 )
{
if ( F_169 ( V_79 ) )
return - V_346 ;
return 0 ;
}
static int F_185 ( struct V_30 * V_79 )
{
F_170 ( V_79 , V_200 . V_201 , V_200 . V_362 ) ;
return 0 ;
}
static int T_13 F_186 ( void )
{
int V_64 ;
if ( ! V_374 && F_187 ( V_375 ) ) {
V_64 = F_188 ( & V_376 ) ;
if ( V_64 ) {
F_20 ( L_97 ) ;
goto V_59;
}
V_377 = 1 ;
}
V_64 = F_188 ( & V_378 ) ;
if ( V_64 ) {
F_20 ( L_98 ) ;
goto V_379;
}
return 0 ;
V_379:
if ( V_377 )
F_189 ( & V_376 ) ;
V_59:
return V_64 ;
}
static void T_14 F_190 ( void )
{
F_189 ( & V_378 ) ;
if ( V_377 )
F_189 ( & V_376 ) ;
}

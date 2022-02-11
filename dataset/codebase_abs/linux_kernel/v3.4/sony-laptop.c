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
int V_16 = - 1 ;
if ( V_12 == V_17 ||
V_12 == V_18 ) {
return;
}
switch ( V_12 ) {
case V_19 :
case V_20 :
F_11 ( V_14 , V_21 , 1 ) ;
F_5 ( V_14 ) ;
return;
case V_22 :
case V_23 :
F_11 ( V_14 , V_21 , - 1 ) ;
F_5 ( V_14 ) ;
return;
case V_24 :
V_3 . V_9 = V_25 ;
V_3 . V_8 = V_14 ;
break;
default:
if ( V_12 >= F_12 ( V_26 ) ) {
F_13 ( L_1 , V_12 ) ;
break;
}
if ( ( V_16 = V_26 [ V_12 ] ) != - 1 ) {
V_3 . V_9 = V_27 [ V_16 ] ;
if ( V_3 . V_9 != V_28 )
V_3 . V_8 = V_15 ;
}
break;
}
if ( V_3 . V_8 ) {
if ( V_16 != - 1 )
F_14 ( V_3 . V_8 , V_29 , V_30 , V_16 ) ;
F_4 ( V_3 . V_8 , V_3 . V_9 , 1 ) ;
F_5 ( V_3 . V_8 ) ;
F_15 ( & V_5 . V_7 ,
( unsigned char * ) & V_3 , sizeof( V_3 ) ,
& V_5 . V_6 ) ;
F_7 ( & V_5 . V_10 ,
V_11 + F_8 ( 10 ) ) ;
} else
F_13 ( L_2 , V_12 ) ;
}
static int F_16 ( struct V_31 * V_31 )
{
struct V_13 * V_14 ;
struct V_13 * V_15 ;
int V_32 ;
int error ;
if ( F_17 ( 1 , & V_5 . V_33 ) > 1 )
return 0 ;
F_18 ( & V_5 . V_6 ) ;
error = F_19 ( & V_5 . V_7 ,
V_34 , V_35 ) ;
if ( error ) {
F_20 ( L_3 ) ;
goto V_36;
}
F_21 ( & V_5 . V_10 ,
F_1 , 0 ) ;
V_15 = F_22 () ;
if ( ! V_15 ) {
error = - V_37 ;
goto V_38;
}
V_15 -> V_39 = L_4 ;
V_15 -> V_40 . V_41 = V_42 ;
V_15 -> V_40 . V_43 = V_44 ;
V_15 -> V_8 . V_45 = & V_31 -> V_8 ;
F_23 ( V_15 , V_29 , V_30 ) ;
F_24 ( V_46 , V_15 -> V_47 ) ;
V_15 -> V_48 = sizeof( V_27 [ 0 ] ) ;
V_15 -> V_49 = F_12 ( V_27 ) ;
V_15 -> V_50 = & V_27 ;
for ( V_32 = 0 ; V_32 < F_12 ( V_27 ) ; V_32 ++ )
F_24 ( V_27 [ V_32 ] , V_15 -> V_51 ) ;
F_25 ( V_52 , V_15 -> V_51 ) ;
error = F_26 ( V_15 ) ;
if ( error )
goto V_53;
V_5 . V_15 = V_15 ;
V_14 = F_22 () ;
if ( ! V_14 ) {
error = - V_37 ;
goto V_54;
}
V_14 -> V_39 = L_5 ;
V_14 -> V_40 . V_41 = V_42 ;
V_14 -> V_40 . V_43 = V_44 ;
V_14 -> V_8 . V_45 = & V_31 -> V_8 ;
F_23 ( V_14 , V_46 , V_25 ) ;
F_23 ( V_14 , V_55 , V_21 ) ;
error = F_26 ( V_14 ) ;
if ( error )
goto V_56;
V_5 . V_14 = V_14 ;
return 0 ;
V_56:
F_27 ( V_14 ) ;
V_54:
F_28 ( V_15 ) ;
V_15 = NULL ;
V_53:
F_27 ( V_15 ) ;
V_38:
F_29 ( & V_5 . V_7 ) ;
V_36:
F_30 ( & V_5 . V_33 ) ;
return error ;
}
static void F_31 ( void )
{
struct V_2 V_3 = { NULL } ;
if ( ! F_32 ( & V_5 . V_33 ) )
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
int V_57 = 0 ;
if ( F_17 ( 1 , & V_58 ) > 1 )
return 0 ;
V_57 = F_35 ( & V_59 ) ;
if ( V_57 )
goto V_60;
V_61 = F_36 ( L_6 , - 1 ) ;
if ( ! V_61 ) {
V_57 = - V_37 ;
goto V_62;
}
V_57 = F_37 ( V_61 ) ;
if ( V_57 )
goto V_63;
return 0 ;
V_63:
F_38 ( V_61 ) ;
V_61 = NULL ;
V_62:
F_39 ( & V_59 ) ;
V_60:
F_30 ( & V_58 ) ;
return V_57 ;
}
static void F_40 ( void )
{
if ( ! F_32 ( & V_58 ) )
return;
F_41 ( V_61 ) ;
F_39 ( & V_59 ) ;
}
static int F_42 ( T_2 V_64 , char * V_39 , int * V_65 )
{
struct V_66 V_67 ;
union V_68 V_69 ;
T_3 V_70 ;
V_67 . V_71 = sizeof( V_69 ) ;
V_67 . V_72 = & V_69 ;
V_70 = F_43 ( V_64 , V_39 , NULL , & V_67 ) ;
if ( ( V_70 == V_73 ) && ( V_69 . type == V_74 ) ) {
* V_65 = V_69 . integer . V_75 ;
return 0 ;
}
F_44 ( L_7 ) ;
return - 1 ;
}
static int F_45 ( T_2 V_64 , char * V_39 , int V_75 ,
int * V_65 )
{
struct V_76 V_77 ;
union V_68 V_78 ;
struct V_66 V_67 ;
union V_68 V_69 ;
T_3 V_70 ;
V_77 . V_79 = 1 ;
V_77 . V_72 = & V_78 ;
V_78 . type = V_74 ;
V_78 . integer . V_75 = V_75 ;
V_67 . V_71 = sizeof( V_69 ) ;
V_67 . V_72 = & V_69 ;
V_70 = F_43 ( V_64 , V_39 , & V_77 , & V_67 ) ;
if ( V_70 == V_73 ) {
if ( V_65 != NULL ) {
if ( V_69 . type != V_74 ) {
F_44 ( L_8 ) ;
return - 1 ;
}
* V_65 = V_69 . integer . V_75 ;
}
return 0 ;
}
F_44 ( L_9 ) ;
return - 1 ;
}
static T_4 F_46 ( struct V_80 * V_8 ,
struct V_81 * V_82 , char * V_83 )
{
T_4 V_84 = 0 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < F_12 ( V_85 -> V_86 ) ; V_32 ++ ) {
V_84 += snprintf ( V_83 + V_84 , V_87 - V_84 , L_10 ,
V_85 -> V_86 [ V_32 ] ) ;
}
V_84 += snprintf ( V_83 + V_84 , V_87 - V_84 , L_11 ) ;
return V_84 ;
}
static int F_47 ( struct V_88 * V_89 )
{
int V_32 ;
int V_65 ;
V_85 = F_48 ( sizeof( * V_85 ) , V_35 ) ;
if ( ! V_85 )
return - V_37 ;
for ( V_32 = 0 ; V_32 < F_12 ( V_85 -> V_86 ) ; V_32 ++ ) {
if ( ! F_45 ( V_90 ,
L_12 , V_32 + 0x20 , & V_65 ) ) {
F_13 ( L_13 ,
V_65 , V_32 ) ;
V_85 -> V_86 [ V_32 ] = V_65 ;
}
}
if ( V_91 ) {
F_49 ( & V_85 -> V_92 . V_82 ) ;
V_85 -> V_92 . V_82 . V_39 = L_14 ;
V_85 -> V_92 . V_82 . V_93 = V_94 ;
V_85 -> V_92 . V_95 = F_46 ;
if ( F_50 ( & V_89 -> V_8 , & V_85 -> V_92 ) ) {
F_51 ( V_85 ) ;
V_85 = NULL ;
return - 1 ;
}
}
return 0 ;
}
static int F_52 ( struct V_88 * V_89 )
{
if ( V_85 ) {
if ( V_91 )
F_53 ( & V_89 -> V_8 , & V_85 -> V_92 ) ;
F_51 ( V_85 ) ;
V_85 = NULL ;
}
return 0 ;
}
static int F_54 ( int V_64 )
{
int V_32 ;
if ( ! V_85 )
return - 1 ;
for ( V_32 = 0 ; V_32 < 0x10 ; V_32 ++ ) {
if ( V_85 -> V_86 [ V_32 ] == V_64 ) {
F_13 ( L_15 ,
V_64 , V_32 ) ;
return V_32 ;
}
}
F_13 ( L_16 , V_64 ) ;
return - 1 ;
}
static int F_55 ( int V_64 , int V_96 , int * V_65 )
{
int V_57 = 0 ;
int V_97 = F_54 ( V_64 ) ;
if ( V_97 < 0 )
return - 1 ;
V_57 = F_45 ( V_90 , L_17 , V_97 | V_96 ,
V_65 ) ;
F_13 ( L_18 , V_97 | V_96 ,
* V_65 ) ;
return V_57 ;
}
static int F_56 ( const int V_98 , const int V_75 )
{
switch ( V_98 ) {
case V_99 :
return V_75 - 1 ;
case V_100 :
if ( V_75 >= 0 && V_75 < V_101 )
return V_75 + 1 ;
}
return - V_102 ;
}
static int F_57 ( const int V_98 , const int V_75 )
{
if ( V_98 == V_100 ) {
if ( V_75 != 0 && V_75 != 1 )
return - V_102 ;
}
return V_75 ;
}
static T_4 F_58 ( struct V_80 * V_8 , struct V_81 * V_82 ,
char * V_83 )
{
int V_75 ;
struct V_103 * V_104 =
F_59 ( V_82 , struct V_103 , V_92 ) ;
if ( ! * V_104 -> V_105 )
return - V_106 ;
if ( F_42 ( V_90 , * V_104 -> V_105 , & V_75 ) < 0 )
return - V_106 ;
if ( V_104 -> V_107 )
V_75 = V_104 -> V_107 ( V_99 , V_75 ) ;
return snprintf ( V_83 , V_87 , L_19 , V_75 ) ;
}
static T_4 F_60 ( struct V_80 * V_8 ,
struct V_81 * V_82 ,
const char * V_83 , T_5 V_79 )
{
int V_75 ;
struct V_103 * V_104 =
F_59 ( V_82 , struct V_103 , V_92 ) ;
if ( ! V_104 -> V_108 )
return - V_106 ;
if ( V_79 > 31 )
return - V_102 ;
V_75 = F_61 ( V_83 , NULL , 10 ) ;
if ( V_104 -> V_107 )
V_75 = V_104 -> V_107 ( V_100 , V_75 ) ;
if ( V_75 < 0 )
return V_75 ;
if ( F_45 ( V_90 , * V_104 -> V_108 , V_75 , NULL ) < 0 )
return - V_106 ;
V_104 -> V_75 = V_75 ;
V_104 -> V_109 = 1 ;
return V_79 ;
}
static int F_62 ( struct V_110 * V_111 )
{
return F_45 ( V_90 , L_20 ,
V_111 -> V_112 . V_113 + 1 , NULL ) ;
}
static int F_63 ( struct V_110 * V_111 )
{
int V_75 ;
if ( F_42 ( V_90 , L_21 , & V_75 ) )
return 0 ;
return V_75 - 1 ;
}
static int F_64 ( struct V_110 * V_111 )
{
int V_65 ;
struct V_114 * V_115 =
(struct V_114 * ) F_65 ( V_111 ) ;
F_55 ( V_115 -> V_64 , 0x0200 , & V_65 ) ;
return ( V_65 & 0xff ) - V_115 -> V_97 ;
}
static int F_66 ( struct V_110 * V_111 )
{
int V_75 , V_65 ;
struct V_114 * V_115 =
(struct V_114 * ) F_65 ( V_111 ) ;
V_75 = V_111 -> V_112 . V_113 + V_115 -> V_97 ;
if ( F_55 ( V_115 -> V_64 , 0x0100 | ( V_75 << 16 ) , & V_65 ) )
return - V_106 ;
return V_75 ;
}
static void F_67 ( struct V_31 * V_80 , T_6 V_12 )
{
T_6 V_116 = V_12 ;
if ( V_116 >= 0x90 ) {
int V_65 ;
int V_117 = 0 ;
V_116 -= 0x90 ;
if ( F_54 ( 0x100 ) == V_116 )
V_117 = 0x100 ;
if ( F_54 ( 0x127 ) == V_116 )
V_117 = 0x127 ;
if ( V_117 ) {
struct V_118 * V_119 ;
if ( F_55 ( V_117 , 0x200 , & V_65 ) ) {
F_13 ( L_22
L_23 , V_117 ,
V_116 ) ;
V_116 = V_12 ;
} else {
V_116 = V_65 & 0xFF ;
if ( V_117 == 0x100 )
V_119 = V_120 ;
else
V_119 = V_121 ;
for (; V_119 -> V_122 ; V_119 ++ ) {
if ( V_119 -> V_122 == V_116 ) {
V_116 = V_119 -> V_12 ;
break;
}
}
if ( ! V_119 -> V_122 )
F_68 ( L_24 ,
V_117 , V_116 ) ;
else
F_10 ( V_116 ) ;
}
} else if ( F_54 ( V_123 ) == V_116 ) {
F_69 () ;
return;
}
} else
F_10 ( V_116 ) ;
F_13 ( L_25 , V_116 ) ;
F_70 ( V_124 , 1 , V_116 ) ;
}
static T_3 F_71 ( T_2 V_64 , T_6 V_125 ,
void * V_126 , void * * V_127 )
{
struct V_128 * V_129 ;
if ( F_72 ( F_73 ( V_64 , & V_129 ) ) ) {
F_44 ( L_26 ,
( char * ) & V_129 -> V_39 , V_129 -> V_130 ) ;
F_51 ( V_129 ) ;
}
return V_73 ;
}
static int F_74 ( struct V_31 * V_80 )
{
int V_65 ;
F_45 ( V_90 , L_27 , 0xffff , & V_65 ) ;
F_55 ( 0x0100 , 0 , & V_65 ) ;
F_55 ( 0x0101 , 0 , & V_65 ) ;
F_55 ( 0x0102 , 0x100 , & V_65 ) ;
F_55 ( 0x0127 , 0 , & V_65 ) ;
return 0 ;
}
static int F_75 ( struct V_31 * V_80 )
{
struct V_103 * V_104 ;
T_2 V_64 ;
for ( V_104 = V_131 ; V_104 -> V_39 ; V_104 ++ ) {
int V_57 ;
if ( ! V_104 -> V_109 )
continue;
V_57 = F_45 ( V_90 , * V_104 -> V_108 ,
V_104 -> V_75 , NULL ) ;
if ( V_57 < 0 ) {
F_20 ( L_28 , V_132 , V_57 ) ;
break;
}
}
if ( F_72 ( F_76 ( V_90 , L_29 ,
& V_64 ) ) ) {
if ( F_45 ( V_90 , L_29 , 1 , NULL ) )
F_13 ( L_30 ) ;
}
if ( F_72 ( F_76 ( V_90 , L_12 ,
& V_64 ) ) ) {
F_13 ( L_31 ) ;
F_74 ( V_80 ) ;
}
F_69 () ;
F_77 () ;
return 0 ;
}
static void F_78 ( void )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_133 ; V_32 ++ ) {
if ( V_134 [ V_32 ] ) {
F_79 ( V_134 [ V_32 ] ) ;
F_80 ( V_134 [ V_32 ] ) ;
}
}
}
static int F_81 ( void * V_122 , bool V_135 )
{
int V_65 ;
int V_96 = V_136 [ ( long ) V_122 ] + 0x100 ;
if ( ! V_135 )
V_96 |= 0xff0000 ;
return F_55 ( V_123 , V_96 , & V_65 ) ;
}
static int F_82 ( struct V_31 * V_80 ,
enum V_137 V_138 )
{
int V_139 = 0 ;
struct V_140 * V_141 ;
enum V_142 type ;
const char * V_39 ;
int V_65 ;
bool V_143 ;
switch ( V_138 ) {
case V_144 :
type = V_145 ;
V_39 = L_32 ;
break;
case V_146 :
type = V_147 ;
V_39 = L_33 ;
break;
case V_148 :
type = V_149 ;
V_39 = L_34 ;
break;
case V_150 :
type = V_151 ;
V_39 = L_35 ;
break;
default:
return - V_102 ;
}
V_141 = F_83 ( V_39 , & V_80 -> V_8 , type ,
& V_152 , ( void * ) V_138 ) ;
if ( ! V_141 )
return - V_37 ;
F_55 ( V_123 , 0x200 , & V_65 ) ;
V_143 = ! ( V_65 & 0x1 ) ;
F_84 ( V_141 , V_143 ) ;
V_139 = F_85 ( V_141 ) ;
if ( V_139 ) {
F_80 ( V_141 ) ;
return V_139 ;
}
V_134 [ V_138 ] = V_141 ;
return V_139 ;
}
static void F_69 ( void )
{
enum V_137 V_32 ;
int V_65 ;
bool V_143 ;
F_55 ( V_123 , 0x200 , & V_65 ) ;
V_143 = ! ( V_65 & 0x1 ) ;
for ( V_32 = 0 ; V_32 < V_133 ; V_32 ++ ) {
int V_96 = V_136 [ V_32 ] ;
if ( ! V_134 [ V_32 ] )
continue;
if ( V_143 ) {
if ( F_84 ( V_134 [ V_32 ] , true ) ) {
}
continue;
}
F_55 ( V_123 , V_96 , & V_65 ) ;
F_86 ( V_134 [ V_32 ] ,
! ( V_65 & 0xf ) , false ) ;
}
}
static void F_87 ( struct V_31 * V_80 )
{
int V_97 ;
T_1 V_153 , V_32 ;
T_3 V_70 ;
struct V_76 V_77 ;
union V_68 V_78 ;
union V_68 * V_154 ;
struct V_66 V_83 = { V_155 , NULL } ;
V_97 = F_54 ( 0x124 ) ;
if ( V_97 == - 1 ) {
V_97 = F_54 ( 0x135 ) ;
if ( V_97 == - 1 )
return;
else
V_123 = 0x135 ;
} else
V_123 = 0x124 ;
F_13 ( L_36 , V_123 ) ;
V_77 . V_79 = 1 ;
V_77 . V_72 = & V_78 ;
V_78 . type = V_74 ;
V_78 . integer . V_75 = V_97 ;
V_70 = F_43 ( V_90 , L_37 , & V_77 ,
& V_83 ) ;
if ( F_88 ( V_70 ) ) {
F_13 ( L_38 ) ;
return;
}
V_154 = (union V_68 * ) V_83 . V_72 ;
if ( ! V_154 ) {
F_20 ( L_39 ) ;
goto V_156;
}
if ( V_154 -> type != V_157 ) {
F_20 ( L_40 ,
V_154 -> type ) ;
goto V_156;
}
for ( V_32 = 0 ; V_32 < V_154 -> V_83 . V_71 ; V_32 ++ ) {
V_153 = * ( V_154 -> V_83 . V_72 + V_32 ) ;
if ( V_153 == 0xff )
break;
F_13 ( L_41 , V_153 ) ;
if ( V_153 == 0 && ! V_134 [ V_144 ] )
F_82 ( V_80 , V_144 ) ;
if ( V_153 == 0x10 && ! V_134 [ V_146 ] )
F_82 ( V_80 , V_146 ) ;
if ( ( 0xf0 & V_153 ) == 0x20 &&
! V_134 [ V_148 ] )
F_82 ( V_80 , V_148 ) ;
if ( V_153 == 0x30 && ! V_134 [ V_150 ] )
F_82 ( V_80 , V_150 ) ;
}
V_156:
F_51 ( V_83 . V_72 ) ;
return;
}
static T_4 F_89 ( T_1 V_75 )
{
int V_65 ;
if ( V_75 > 1 )
return - V_102 ;
if ( F_55 ( V_158 ,
( V_75 << 0x10 ) | V_159 , & V_65 ) )
return - V_106 ;
F_55 ( V_158 , ( V_75 << 0x10 ) | V_160 ,
& V_65 ) ;
V_161 -> V_93 = V_75 ;
return 0 ;
}
static T_4 F_90 ( struct V_80 * V_8 ,
struct V_81 * V_82 ,
const char * V_83 , T_5 V_79 )
{
int V_57 = 0 ;
unsigned long V_75 ;
if ( V_79 > 31 )
return - V_102 ;
if ( F_91 ( V_83 , 10 , & V_75 ) )
return - V_102 ;
V_57 = F_89 ( V_75 ) ;
if ( V_57 < 0 )
return V_57 ;
return V_79 ;
}
static T_4 F_92 ( struct V_80 * V_8 ,
struct V_81 * V_82 , char * V_83 )
{
T_4 V_79 = 0 ;
V_79 = snprintf ( V_83 , V_87 , L_19 , V_161 -> V_93 ) ;
return V_79 ;
}
static int F_93 ( T_1 V_75 )
{
int V_65 ;
if ( V_75 > 3 )
return - V_102 ;
if ( F_55 ( V_158 ,
( V_75 << 0x10 ) | V_162 , & V_65 ) )
return - V_106 ;
V_161 -> V_163 = V_75 ;
return 0 ;
}
static T_4 F_94 ( struct V_80 * V_8 ,
struct V_81 * V_82 ,
const char * V_83 , T_5 V_79 )
{
int V_57 = 0 ;
unsigned long V_75 ;
if ( V_79 > 31 )
return - V_102 ;
if ( F_91 ( V_83 , 10 , & V_75 ) )
return - V_102 ;
V_57 = F_93 ( V_75 ) ;
if ( V_57 < 0 )
return V_57 ;
return V_79 ;
}
static T_4 F_95 ( struct V_80 * V_8 ,
struct V_81 * V_82 , char * V_83 )
{
T_4 V_79 = 0 ;
V_79 = snprintf ( V_83 , V_87 , L_19 , V_161 -> V_163 ) ;
return V_79 ;
}
static int F_96 ( struct V_88 * V_89 )
{
int V_65 ;
if ( F_55 ( V_158 , V_164 , & V_65 ) )
return 0 ;
if ( ! ( V_65 & 0x02 ) )
return 0 ;
V_161 = F_48 ( sizeof( * V_161 ) , V_35 ) ;
if ( ! V_161 )
return - V_37 ;
F_49 ( & V_161 -> V_165 . V_82 ) ;
V_161 -> V_165 . V_82 . V_39 = L_42 ;
V_161 -> V_165 . V_82 . V_93 = V_94 | V_166 ;
V_161 -> V_165 . V_95 = F_92 ;
V_161 -> V_165 . V_167 = F_90 ;
F_49 ( & V_161 -> V_168 . V_82 ) ;
V_161 -> V_168 . V_82 . V_39 = L_43 ;
V_161 -> V_168 . V_82 . V_93 = V_94 | V_166 ;
V_161 -> V_168 . V_95 = F_95 ;
V_161 -> V_168 . V_167 = F_94 ;
if ( F_50 ( & V_89 -> V_8 , & V_161 -> V_165 ) )
goto V_169;
if ( F_50 ( & V_89 -> V_8 , & V_161 -> V_168 ) )
goto V_170;
F_89 ( V_171 ) ;
F_93 ( V_172 ) ;
return 0 ;
V_170:
F_53 ( & V_89 -> V_8 , & V_161 -> V_165 ) ;
V_169:
F_51 ( V_161 ) ;
V_161 = NULL ;
return - 1 ;
}
static int F_97 ( struct V_88 * V_89 )
{
if ( V_161 ) {
int V_65 ;
F_53 ( & V_89 -> V_8 , & V_161 -> V_165 ) ;
F_53 ( & V_89 -> V_8 , & V_161 -> V_168 ) ;
F_55 ( V_158 , 0x1000 | V_159 , & V_65 ) ;
F_55 ( V_158 , V_162 , & V_65 ) ;
F_51 ( V_161 ) ;
}
return 0 ;
}
static void F_77 ( void )
{
int V_173 = 0 ;
if ( ! V_161 )
return;
if ( V_161 -> V_93 == 0 )
F_55 ( V_158 , V_159 , & V_173 ) ;
if ( V_161 -> V_163 != 0 )
F_55 ( V_158 ,
( V_161 -> V_163 << 0x10 ) | V_162 ,
& V_173 ) ;
}
static void F_98 ( int V_64 ,
struct V_114 * V_112 )
{
int V_97 ;
T_3 V_70 ;
T_1 V_174 , V_32 ;
T_1 V_175 = 0xff , V_176 = 0x00 ;
struct V_76 V_77 ;
union V_68 V_78 ;
union V_68 * V_177 ;
struct V_66 V_83 = { V_155 , NULL } ;
V_112 -> V_64 = V_64 ;
V_112 -> V_97 = 0 ;
V_112 -> V_178 = 0xff ;
V_97 = F_54 ( V_64 ) ;
if ( V_97 < 0 )
return;
V_77 . V_79 = 1 ;
V_77 . V_72 = & V_78 ;
V_78 . type = V_74 ;
V_78 . integer . V_75 = V_97 ;
V_70 = F_43 ( V_90 , L_37 , & V_77 ,
& V_83 ) ;
if ( F_88 ( V_70 ) )
return;
V_177 = (union V_68 * ) V_83 . V_72 ;
if ( ! V_177 ) {
F_20 ( L_44 ) ;
return;
}
if ( V_177 -> type != V_157 ) {
F_20 ( L_40 ,
V_177 -> type ) ;
goto V_179;
}
for ( V_32 = 0 ; V_32 < 9 && V_32 < V_177 -> V_83 . V_71 ; V_32 ++ ) {
V_174 = * ( V_177 -> V_83 . V_72 + V_32 ) ;
F_13 ( L_45 , V_174 ) ;
if ( ! V_174 )
break;
if ( V_174 > V_176 )
V_176 = V_174 ;
if ( V_174 < V_175 )
V_175 = V_174 ;
}
V_112 -> V_97 = V_175 ;
V_112 -> V_178 = V_176 ;
F_13 ( L_46 , V_112 -> V_97 ,
V_112 -> V_178 ) ;
V_179:
F_51 ( V_83 . V_72 ) ;
return;
}
static void F_99 ( void )
{
T_2 V_1 ;
int V_180 = 0 ;
const struct V_181 * V_182 = NULL ;
struct V_183 V_112 ;
if ( F_54 ( 0x12f ) != - 1 ) {
V_182 = & V_184 ;
F_98 ( 0x12f , & V_185 ) ;
V_180 = V_185 . V_178 - V_185 . V_97 ;
} else if ( F_54 ( 0x137 ) != - 1 ) {
V_182 = & V_184 ;
F_98 ( 0x137 , & V_185 ) ;
V_180 = V_185 . V_178 - V_185 . V_97 ;
} else if ( F_72 ( F_76 ( V_90 , L_21 ,
& V_1 ) ) ) {
V_182 = & V_186 ;
V_180 = V_101 - 1 ;
} else
return;
memset ( & V_112 , 0 , sizeof( struct V_183 ) ) ;
V_112 . type = V_187 ;
V_112 . V_180 = V_180 ;
V_185 . V_8 = F_100 ( L_47 , NULL ,
& V_185 ,
V_182 , & V_112 ) ;
if ( F_101 ( V_185 . V_8 ) ) {
F_44 ( L_48 ) ;
V_185 . V_8 = NULL ;
} else
V_185 . V_8 -> V_112 . V_113 =
V_182 -> V_188 ( V_185 . V_8 ) ;
}
static void F_102 ( void )
{
if ( V_185 . V_8 )
F_103 ( V_185 . V_8 ) ;
}
static int F_104 ( struct V_31 * V_80 )
{
T_3 V_70 ;
int V_65 = 0 ;
T_2 V_64 ;
struct V_103 * V_104 ;
F_68 ( L_49 , V_189 , V_190 ) ;
V_124 = V_80 ;
strcpy ( F_105 ( V_80 ) , L_50 ) ;
V_90 = V_80 -> V_64 ;
V_65 = F_106 ( V_80 ) ;
if ( ! V_65 && ! V_80 -> V_70 . V_191 ) {
F_13 ( L_51 ) ;
V_65 = - V_192 ;
goto V_193;
}
V_65 = F_34 () ;
if ( V_65 )
goto V_194;
if ( V_91 ) {
V_70 = F_107 ( V_195 ,
V_90 , 1 , F_71 ,
NULL , NULL , NULL ) ;
if ( F_88 ( V_70 ) ) {
F_44 ( L_52 ) ;
V_65 = - V_192 ;
goto V_194;
}
}
if ( F_72 ( F_76 ( V_90 , L_29 ,
& V_64 ) ) ) {
if ( F_45 ( V_90 , L_29 , 1 , NULL ) )
F_13 ( L_30 ) ;
}
if ( F_72 ( F_76 ( V_90 , L_12 ,
& V_64 ) ) ) {
F_13 ( L_31 ) ;
V_65 = F_47 ( V_61 ) ;
if ( V_65 )
goto V_194;
V_65 = F_96 ( V_61 ) ;
if ( V_65 )
goto V_196;
F_74 ( V_80 ) ;
F_87 ( V_80 ) ;
}
V_65 = F_16 ( V_80 ) ;
if ( V_65 ) {
F_20 ( L_53 ) ;
goto V_197;
}
if ( F_108 () ) {
F_68 ( L_54 ) ;
} else {
F_99 () ;
}
for ( V_104 = V_131 ; V_104 -> V_39 ; ++ V_104 ) {
if ( ! V_91 && V_104 -> V_91 )
continue;
for (; V_104 -> V_105 && * V_104 -> V_105 ; ++ V_104 -> V_105 ) {
if ( F_72 ( F_76 ( V_90 ,
* V_104 -> V_105 ,
& V_64 ) ) ) {
F_13 ( L_55 ,
V_104 -> V_39 , * V_104 -> V_105 ) ;
V_104 -> V_92 . V_82 . V_93 |= V_94 ;
break;
}
}
for (; V_104 -> V_108 && * V_104 -> V_108 ; ++ V_104 -> V_108 ) {
if ( F_72 ( F_76 ( V_90 ,
* V_104 -> V_108 ,
& V_64 ) ) ) {
F_13 ( L_56 ,
V_104 -> V_39 , * V_104 -> V_108 ) ;
V_104 -> V_92 . V_82 . V_93 |= V_166 ;
break;
}
}
if ( V_104 -> V_92 . V_82 . V_93 != 0 ) {
V_65 =
F_50 ( & V_61 -> V_8 ,
& V_104 -> V_92 ) ;
if ( V_65 )
goto V_198;
}
}
return 0 ;
V_198:
for ( V_104 = V_131 ; V_104 -> V_39 ; ++ V_104 ) {
F_53 ( & V_61 -> V_8 , & V_104 -> V_92 ) ;
}
F_102 () ;
F_31 () ;
V_197:
F_97 ( V_61 ) ;
V_196:
F_52 ( V_61 ) ;
V_194:
F_40 () ;
V_193:
F_78 () ;
return V_65 ;
}
static int F_109 ( struct V_31 * V_80 , int type )
{
struct V_103 * V_104 ;
F_102 () ;
V_124 = NULL ;
for ( V_104 = V_131 ; V_104 -> V_39 ; ++ V_104 ) {
F_53 ( & V_61 -> V_8 , & V_104 -> V_92 ) ;
}
F_97 ( V_61 ) ;
F_52 ( V_61 ) ;
F_40 () ;
F_31 () ;
F_78 () ;
F_13 ( V_189 L_57 ) ;
return 0 ;
}
static T_1 F_110 ( T_1 V_8 )
{
T_1 V_199 , V_200 ;
F_111 ( F_112 ( V_201 . V_202 -> V_203 . V_204 + 4 ) & 2 ,
V_205 ) ;
F_113 ( V_8 , V_201 . V_202 -> V_203 . V_204 + 4 ) ;
V_199 = F_112 ( V_201 . V_202 -> V_203 . V_204 + 4 ) ;
V_200 = F_112 ( V_201 . V_202 -> V_203 . V_204 ) ;
F_13 ( L_58 , V_8 , ( V_200 << 8 ) | V_199 ) ;
return V_200 ;
}
static T_1 F_114 ( T_1 V_8 , T_1 V_206 )
{
T_1 V_199 ;
F_111 ( F_112 ( V_201 . V_202 -> V_203 . V_204 + 4 ) & 2 ,
V_205 ) ;
F_113 ( V_8 , V_201 . V_202 -> V_203 . V_204 + 4 ) ;
F_111 ( F_112 ( V_201 . V_202 -> V_203 . V_204 + 4 ) & 2 ,
V_205 ) ;
F_113 ( V_206 , V_201 . V_202 -> V_203 . V_204 ) ;
V_199 = F_112 ( V_201 . V_202 -> V_203 . V_204 ) ;
F_13 ( L_59 , V_8 , V_206 , V_199 ) ;
return V_199 ;
}
static T_1 F_115 ( T_1 V_8 , T_1 V_206 , T_1 V_207 )
{
T_1 V_199 ;
F_111 ( F_112 ( V_201 . V_202 -> V_203 . V_204 + 4 ) & 2 , V_205 ) ;
F_113 ( V_8 , V_201 . V_202 -> V_203 . V_204 + 4 ) ;
F_111 ( F_112 ( V_201 . V_202 -> V_203 . V_204 + 4 ) & 2 , V_205 ) ;
F_113 ( V_206 , V_201 . V_202 -> V_203 . V_204 ) ;
F_111 ( F_112 ( V_201 . V_202 -> V_203 . V_204 + 4 ) & 2 , V_205 ) ;
F_113 ( V_207 , V_201 . V_202 -> V_203 . V_204 ) ;
V_199 = F_112 ( V_201 . V_202 -> V_203 . V_204 ) ;
F_13 ( L_60 ,
V_8 , V_206 , V_207 , V_199 ) ;
return V_199 ;
}
static int F_116 ( const T_1 V_208 , const T_1 V_116 )
{
if ( V_208 == 0x31 ) {
if ( V_116 == 0x5c || V_116 == 0x5f )
F_110 ( 0xA0 ) ;
else if ( V_116 == 0x61 )
F_110 ( 0xB3 ) ;
return 0 ;
}
return 1 ;
}
static void F_117 ( struct V_209 * V_8 )
{
struct V_210 * V_211 ;
V_211 = F_118 ( V_212 ,
V_213 , NULL ) ;
if ( V_211 ) {
V_8 -> V_214 = V_215 ;
V_8 -> V_216 = V_217 ;
V_8 -> V_218 = V_219 ;
goto V_60;
}
V_211 = F_118 ( V_212 ,
V_220 , NULL ) ;
if ( V_211 ) {
V_8 -> V_214 = V_221 ;
V_8 -> V_216 = V_222 ;
V_8 -> V_218 = V_223 ;
goto V_60;
}
V_211 = F_118 ( V_212 ,
V_224 , NULL ) ;
if ( V_211 ) {
V_8 -> V_214 = V_225 ;
V_8 -> V_226 = F_116 ;
V_8 -> V_216 = V_227 ;
V_8 -> V_218 = V_228 ;
goto V_60;
}
V_211 = F_118 ( V_212 ,
V_229 , NULL ) ;
if ( V_211 ) {
V_8 -> V_214 = V_225 ;
V_8 -> V_226 = F_116 ;
V_8 -> V_216 = V_227 ;
V_8 -> V_218 = V_228 ;
goto V_60;
}
V_211 = F_118 ( V_212 ,
V_230 , NULL ) ;
if ( V_211 ) {
V_8 -> V_214 = V_225 ;
V_8 -> V_226 = F_116 ;
V_8 -> V_216 = V_227 ;
V_8 -> V_218 = V_228 ;
goto V_60;
}
V_8 -> V_214 = V_221 ;
V_8 -> V_216 = V_222 ;
V_8 -> V_218 = V_223 ;
V_60:
if ( V_211 )
F_119 ( V_211 ) ;
F_68 ( L_61 ,
V_8 -> V_214 == V_215 ? 1 :
V_8 -> V_214 == V_221 ? 2 : 3 ) ;
}
static int F_120 ( void )
{
T_1 V_207 ;
V_207 = F_114 ( 0x8f , V_231 ) ;
return ( V_207 != 0xff && ( V_207 & V_232 ) ) ;
}
static int F_121 ( void )
{
if ( ! V_233 ) {
F_44 ( L_62 ) ;
return - V_192 ;
}
F_111 ( F_115 ( 0x90 , V_234 ,
V_235 ) ,
V_236 ) ;
if ( V_201 . V_237 ) {
F_114 ( 0x91 , 0 ) ;
V_201 . V_237 = 0 ;
}
return 0 ;
}
static int F_122 ( void )
{
int V_32 , V_238 , V_239 ;
if ( ! V_233 ) {
F_44 ( L_62 ) ;
return - V_192 ;
}
if ( V_201 . V_237 )
return 0 ;
for ( V_238 = 5 ; V_238 > 0 ; V_238 -- ) {
for ( V_239 = 0 ; V_239 < 100 && F_114 ( 0x91 , 0x1 ) ; V_239 ++ )
F_123 ( 10 ) ;
F_110 ( 0x93 ) ;
for ( V_32 = 400 ; V_32 > 0 ; V_32 -- ) {
if ( F_120 () )
break;
F_123 ( 10 ) ;
}
if ( V_32 )
break;
}
if ( V_238 == 0 ) {
F_44 ( L_63 ) ;
return - V_192 ;
}
F_111 ( F_115 ( 0x90 , V_240 ,
0x5a ) ,
V_236 ) ;
V_201 . V_237 = 1 ;
return 0 ;
}
int F_124 ( int V_241 , T_1 V_75 )
{
if ( ! V_233 )
return - V_106 ;
F_125 ( & V_201 . V_242 ) ;
switch ( V_241 ) {
case V_243 :
if ( V_75 )
F_122 () ;
else
F_121 () ;
break;
case V_244 :
F_111 ( F_115 ( 0x90 , V_245 , V_75 ) ,
V_236 ) ;
break;
case V_246 :
F_111 ( F_115 ( 0x90 , V_247 , V_75 ) ,
V_236 ) ;
break;
case V_248 :
F_111 ( F_115 ( 0x90 , V_249 , V_75 ) ,
V_236 ) ;
break;
case V_250 :
F_111 ( F_115 ( 0x90 , V_251 , V_75 ) ,
V_236 ) ;
break;
case V_252 :
F_111 ( F_115 ( 0x90 , V_253 , V_75 ) ,
V_236 ) ;
break;
case V_254 :
F_111 ( F_115 ( 0x90 , V_234 , V_75 ) ,
V_236 ) ;
break;
case V_255 :
F_111 ( F_115 ( 0x90 , V_256 , V_75 ) ,
V_236 ) ;
break;
default:
F_20 ( L_64 , V_241 ) ;
break;
}
F_126 ( & V_201 . V_242 ) ;
return 0 ;
}
static void F_127 ( T_1 V_257 )
{
V_257 = ! ! V_257 ;
if ( V_201 . V_258 == V_257 )
return;
F_114 ( 0xB0 , V_257 ) ;
F_110 ( 0x82 ) ;
V_201 . V_258 = V_257 ;
}
static T_4 F_128 ( struct V_80 * V_8 ,
struct V_81 * V_82 ,
const char * V_83 , T_5 V_79 )
{
unsigned long V_75 ;
if ( V_79 > 31 )
return - V_102 ;
V_75 = F_61 ( V_83 , NULL , 10 ) ;
F_125 ( & V_201 . V_242 ) ;
F_127 ( V_75 ) ;
F_126 ( & V_201 . V_242 ) ;
return V_79 ;
}
static T_4 F_129 ( struct V_80 * V_8 ,
struct V_81 * V_82 , char * V_83 )
{
T_4 V_79 ;
F_125 ( & V_201 . V_242 ) ;
V_79 = snprintf ( V_83 , V_87 , L_19 , V_201 . V_258 ) ;
F_126 ( & V_201 . V_242 ) ;
return V_79 ;
}
static void F_130 ( T_1 V_257 )
{
V_257 = ! ! V_257 ;
if ( V_201 . V_259 == V_257 )
return;
F_114 ( 0x96 , V_257 ) ;
F_110 ( 0x82 ) ;
V_201 . V_259 = V_257 ;
}
static T_4 F_131 ( struct V_80 * V_8 ,
struct V_81 * V_82 ,
const char * V_83 , T_5 V_79 )
{
unsigned long V_75 ;
if ( V_79 > 31 )
return - V_102 ;
V_75 = F_61 ( V_83 , NULL , 10 ) ;
F_125 ( & V_201 . V_242 ) ;
F_130 ( V_75 ) ;
F_126 ( & V_201 . V_242 ) ;
return V_79 ;
}
static T_4 F_132 ( struct V_80 * V_8 ,
struct V_81 * V_82 , char * V_83 )
{
T_4 V_79 = 0 ;
F_125 ( & V_201 . V_242 ) ;
V_79 = snprintf ( V_83 , V_87 , L_19 , V_201 . V_259 ) ;
F_126 ( & V_201 . V_242 ) ;
return V_79 ;
}
static int F_133 ( unsigned long V_75 )
{
return F_134 ( V_260 , V_75 ) ;
}
static int F_135 ( T_1 * V_75 )
{
return F_136 ( V_260 , V_75 ) ;
}
static T_4 F_137 ( struct V_80 * V_8 ,
struct V_81 * V_82 ,
const char * V_83 , T_5 V_79 )
{
unsigned long V_75 ;
if ( V_79 > 31 )
return - V_102 ;
V_75 = F_61 ( V_83 , NULL , 10 ) ;
if ( F_133 ( V_75 ) )
return - V_106 ;
return V_79 ;
}
static T_4 F_138 ( struct V_80 * V_8 ,
struct V_81 * V_82 , char * V_83 )
{
T_1 V_75 = 0 ;
if ( F_135 ( & V_75 ) )
return - V_106 ;
return snprintf ( V_83 , V_87 , L_19 , V_75 ) ;
}
static int F_139 ( int V_261 , struct V_262 * V_263 , int V_264 )
{
return F_140 ( V_261 , V_263 , V_264 , & V_265 . V_266 ) ;
}
static int F_141 ( struct V_267 * V_267 , struct V_262 * V_262 )
{
F_30 ( & V_265 . V_268 ) ;
return 0 ;
}
static int F_142 ( struct V_267 * V_267 , struct V_262 * V_262 )
{
unsigned long V_4 ;
F_2 ( & V_265 . V_6 , V_4 ) ;
if ( F_143 ( & V_265 . V_268 ) == 1 )
F_144 ( & V_265 . V_7 ) ;
F_9 ( & V_265 . V_6 , V_4 ) ;
return 0 ;
}
static T_4 F_145 ( struct V_262 * V_262 , char T_7 * V_269 ,
T_5 V_79 , T_8 * V_270 )
{
T_4 V_57 ;
unsigned char V_271 ;
if ( ( F_6 ( & V_265 . V_7 ) == 0 ) &&
( V_262 -> V_272 & V_273 ) )
return - V_274 ;
V_57 = F_146 ( V_265 . V_275 ,
F_6 ( & V_265 . V_7 ) != 0 ) ;
if ( V_57 )
return V_57 ;
while ( V_57 < V_79 &&
( F_147 ( & V_265 . V_7 , & V_271 , sizeof( V_271 ) ,
& V_265 . V_6 ) == sizeof( V_271 ) ) ) {
if ( F_148 ( V_271 , V_269 ++ ) )
return - V_276 ;
V_57 ++ ;
}
if ( V_57 > 0 ) {
struct V_267 * V_267 = V_262 -> V_277 . V_278 -> V_279 ;
V_267 -> V_280 = F_149 ( V_267 -> V_281 ) ;
}
return V_57 ;
}
static unsigned int F_150 ( struct V_262 * V_262 , T_9 * V_282 )
{
F_151 ( V_262 , & V_265 . V_275 , V_282 ) ;
if ( F_6 ( & V_265 . V_7 ) )
return V_283 | V_284 ;
return 0 ;
}
static int F_152 ( T_1 V_285 , T_10 * V_75 )
{
T_1 V_286 , V_287 ;
if ( F_136 ( V_285 , & V_286 ) )
return - 1 ;
if ( F_136 ( V_285 + 1 , & V_287 ) )
return - 1 ;
* V_75 = V_286 | ( V_287 << 8 ) ;
return 0 ;
}
static long F_153 ( struct V_262 * V_288 , unsigned int V_289 ,
unsigned long V_290 )
{
int V_57 = 0 ;
void T_7 * V_291 = ( void T_7 * ) V_290 ;
T_1 V_292 ;
T_10 V_293 ;
int V_75 ;
F_125 ( & V_201 . V_242 ) ;
switch ( V_289 ) {
case V_294 :
if ( V_185 . V_8 == NULL ) {
V_57 = - V_106 ;
break;
}
if ( F_42 ( V_90 , L_21 , & V_75 ) ) {
V_57 = - V_106 ;
break;
}
V_292 = ( ( V_75 & 0xff ) - 1 ) << 5 ;
if ( F_154 ( V_291 , & V_292 , sizeof( V_292 ) ) )
V_57 = - V_276 ;
break;
case V_295 :
if ( V_185 . V_8 == NULL ) {
V_57 = - V_106 ;
break;
}
if ( F_155 ( & V_292 , V_291 , sizeof( V_292 ) ) ) {
V_57 = - V_276 ;
break;
}
if ( F_45 ( V_90 , L_20 ,
( V_292 >> 5 ) + 1 , NULL ) ) {
V_57 = - V_106 ;
break;
}
V_185 . V_8 -> V_112 . V_113 =
F_63 ( V_185 . V_8 ) ;
break;
case V_296 :
if ( F_152 ( V_297 , & V_293 ) ) {
V_57 = - V_106 ;
break;
}
if ( F_154 ( V_291 , & V_293 , sizeof( V_293 ) ) )
V_57 = - V_276 ;
break;
case V_298 :
if ( F_152 ( V_299 , & V_293 ) ) {
V_57 = - V_106 ;
break;
}
if ( F_154 ( V_291 , & V_293 , sizeof( V_293 ) ) )
V_57 = - V_276 ;
break;
case V_300 :
if ( F_152 ( V_301 , & V_293 ) ) {
V_57 = - V_106 ;
break;
}
if ( F_154 ( V_291 , & V_293 , sizeof( V_293 ) ) )
V_57 = - V_276 ;
break;
case V_302 :
if ( F_152 ( V_303 , & V_293 ) ) {
V_57 = - V_106 ;
break;
}
if ( F_154 ( V_291 , & V_293 , sizeof( V_293 ) ) )
V_57 = - V_276 ;
break;
case V_304 :
if ( F_136 ( V_305 , & V_292 ) ) {
V_57 = - V_106 ;
break;
}
V_292 &= 0x07 ;
if ( F_154 ( V_291 , & V_292 , sizeof( V_292 ) ) )
V_57 = - V_276 ;
break;
case V_306 :
V_292 = V_201 . V_259 ;
if ( F_154 ( V_291 , & V_292 , sizeof( V_292 ) ) )
V_57 = - V_276 ;
break;
case V_307 :
if ( F_155 ( & V_292 , V_291 , sizeof( V_292 ) ) ) {
V_57 = - V_276 ;
break;
}
F_130 ( V_292 ) ;
break;
case V_308 :
if ( F_135 ( & V_292 ) ) {
V_57 = - V_106 ;
break;
}
if ( F_154 ( V_291 , & V_292 , sizeof( V_292 ) ) )
V_57 = - V_276 ;
break;
case V_309 :
if ( F_155 ( & V_292 , V_291 , sizeof( V_292 ) ) ) {
V_57 = - V_276 ;
break;
}
if ( F_133 ( V_292 ) )
V_57 = - V_106 ;
break;
case V_310 :
if ( F_136 ( V_311 , & V_292 ) ) {
V_57 = - V_106 ;
break;
}
if ( F_154 ( V_291 , & V_292 , sizeof( V_292 ) ) )
V_57 = - V_276 ;
break;
default:
V_57 = - V_102 ;
}
F_126 ( & V_201 . V_242 ) ;
return V_57 ;
}
static void F_156 ( T_1 V_12 )
{
F_15 ( & V_265 . V_7 , ( unsigned char * ) & V_12 ,
sizeof( V_12 ) , & V_265 . V_6 ) ;
F_157 ( & V_265 . V_266 , V_312 , V_313 ) ;
F_158 ( & V_265 . V_275 ) ;
}
static int F_159 ( void )
{
int error ;
F_18 ( & V_265 . V_6 ) ;
error =
F_19 ( & V_265 . V_7 , V_34 , V_35 ) ;
if ( error ) {
F_20 ( L_3 ) ;
return error ;
}
F_160 ( & V_265 . V_275 ) ;
if ( V_314 != - 1 )
V_315 . V_314 = V_314 ;
error = F_161 ( & V_315 ) ;
if ( error ) {
F_20 ( L_65 ) ;
goto V_38;
}
if ( V_314 == - 1 )
F_68 ( L_66 ,
V_315 . V_314 ) ;
return 0 ;
V_38:
F_29 ( & V_265 . V_7 ) ;
return error ;
}
static void F_162 ( void )
{
F_163 ( & V_315 ) ;
F_29 ( & V_265 . V_7 ) ;
}
static int F_159 ( void ) { return 0 ; }
static void F_162 ( void ) { }
static void F_156 ( T_1 V_12 ) { }
static T_3
F_164 ( struct V_316 * V_317 , void * V_126 )
{
T_6 V_32 ;
struct V_209 * V_8 = (struct V_209 * ) V_126 ;
switch ( V_317 -> type ) {
case V_318 :
{
struct V_319 * V_320 = F_48 ( sizeof( * V_320 ) , V_35 ) ;
if ( ! V_320 )
return V_321 ;
F_165 ( & V_320 -> V_322 , & V_8 -> V_323 ) ;
return V_73 ;
}
case V_324 :
return V_73 ;
case V_325 :
{
struct V_326 * V_327 = & V_317 -> V_122 . V_328 ;
struct V_329 * V_330 = NULL ;
if ( ! V_327 || ! V_327 -> V_331 ) {
F_13 ( L_67 ) ;
return V_73 ;
}
for ( V_32 = 0 ; V_32 < V_327 -> V_331 ; V_32 ++ ) {
if ( ! V_327 -> V_332 [ V_32 ] ) {
F_44 ( L_68 ,
V_327 -> V_332 [ V_32 ] ) ;
continue;
}
V_330 = F_48 ( sizeof( * V_330 ) ,
V_35 ) ;
if ( ! V_330 )
return V_321 ;
F_165 ( & V_330 -> V_322 , & V_8 -> V_332 ) ;
V_330 -> V_328 . V_333 = V_327 -> V_333 ;
V_330 -> V_328 . V_334 = V_327 -> V_334 ;
V_330 -> V_328 . V_335 = V_327 -> V_335 ;
V_330 -> V_328 . V_331 = 1 ;
V_330 -> V_328 . V_332 [ 0 ] = V_327 -> V_332 [ V_32 ] ;
}
return V_73 ;
}
case V_336 :
{
struct V_337 * V_338 = & V_317 -> V_122 . V_338 ;
struct V_319 * V_320 =
F_166 ( & V_8 -> V_323 , struct V_319 , V_322 ) ;
if ( ! V_338 ) {
F_13 ( L_69 ) ;
return V_73 ;
}
if ( ! V_320 -> V_203 . V_204 ) {
memcpy ( & V_320 -> V_203 , V_338 , sizeof( * V_338 ) ) ;
F_13 ( L_70 , V_320 -> V_203 . V_204 ,
V_320 -> V_203 . V_339 ) ;
}
else if ( ! V_320 -> V_340 . V_204 ) {
memcpy ( & V_320 -> V_340 , V_338 , sizeof( * V_338 ) ) ;
F_13 ( L_71 , V_320 -> V_340 . V_204 ,
V_320 -> V_340 . V_339 ) ;
}
else {
F_20 ( L_72 ) ;
return V_321 ;
}
return V_73 ;
}
default:
F_13 ( L_73 ,
V_317 -> type ) ;
case V_341 :
return V_73 ;
}
return V_342 ;
}
static int F_167 ( struct V_31 * V_80 )
{
int V_65 = 0 ;
T_3 V_70 = V_73 ;
if ( ! V_80 )
return - V_102 ;
F_13 ( L_74 ) ;
V_65 = F_106 ( V_80 ) ;
if ( V_65 ) {
F_44 ( L_75 ) ;
goto V_343;
}
if ( ! V_80 -> V_70 . V_344 )
F_13 ( L_76 ) ;
else
F_13 ( L_77 ) ;
F_13 ( L_78 , V_345 ) ;
V_70 = F_168 ( V_80 -> V_64 , V_345 ,
F_164 , & V_201 ) ;
if ( F_88 ( V_70 ) ) {
F_44 ( L_79 , V_345 ) ;
V_65 = - V_192 ;
}
V_343:
return V_65 ;
}
static int F_169 ( struct V_31 * V_80 )
{
T_3 V_57 = F_43 ( V_80 -> V_64 , L_80 , NULL ,
NULL ) ;
if ( F_88 ( V_57 ) && V_57 != V_346 )
return - V_347 ;
F_13 ( L_76 ) ;
return 0 ;
}
static int F_170 ( struct V_31 * V_80 ,
struct V_319 * V_320 , struct V_329 * V_328 )
{
T_3 V_70 ;
int V_65 = 0 ;
struct {
struct V_316 V_348 ;
struct V_316 V_349 ;
struct V_316 V_350 ;
struct V_316 V_351 ;
} * V_317 ;
struct V_66 V_83 = { 0 , NULL } ;
if ( ! V_320 || ! V_328 )
return - V_102 ;
V_317 = F_48 ( sizeof( * V_317 ) + 1 , V_35 ) ;
if ( ! V_317 )
return - V_37 ;
V_83 . V_71 = sizeof( * V_317 ) + 1 ;
V_83 . V_72 = V_317 ;
if ( V_201 . V_214 == V_215 ) {
V_317 -> V_348 . type = V_336 ;
V_317 -> V_348 . V_71 = sizeof( struct V_316 ) ;
memcpy ( & V_317 -> V_348 . V_122 . V_338 , & V_320 -> V_203 ,
sizeof( struct V_337 ) ) ;
V_317 -> V_349 . type = V_336 ;
V_317 -> V_349 . V_71 = sizeof( struct V_316 ) ;
memcpy ( & V_317 -> V_349 . V_122 . V_338 , & V_320 -> V_340 ,
sizeof( struct V_337 ) ) ;
V_317 -> V_350 . type = V_325 ;
V_317 -> V_350 . V_71 = sizeof( struct V_316 ) ;
memcpy ( & V_317 -> V_350 . V_122 . V_328 , & V_328 -> V_328 ,
sizeof( struct V_326 ) ) ;
V_317 -> V_350 . V_122 . V_328 . V_335 = V_352 ;
V_317 -> V_351 . type = V_341 ;
}
else {
V_317 -> V_348 . type = V_336 ;
V_317 -> V_348 . V_71 = sizeof( struct V_316 ) ;
memcpy ( & V_317 -> V_348 . V_122 . V_338 , & V_320 -> V_203 ,
sizeof( struct V_337 ) ) ;
V_317 -> V_349 . type = V_325 ;
V_317 -> V_349 . V_71 = sizeof( struct V_316 ) ;
memcpy ( & V_317 -> V_349 . V_122 . V_328 , & V_328 -> V_328 ,
sizeof( struct V_326 ) ) ;
V_317 -> V_349 . V_122 . V_328 . V_335 = V_352 ;
V_317 -> V_350 . type = V_341 ;
}
F_13 ( L_81 ) ;
V_70 = F_171 ( V_80 -> V_64 , & V_83 ) ;
if ( F_88 ( V_70 ) ) {
F_20 ( L_82 ) ;
V_65 = - V_192 ;
goto V_343;
}
F_110 ( 0x82 ) ;
F_114 ( 0x81 , 0xff ) ;
F_110 ( V_353 ? 0x92 : 0x82 ) ;
V_343:
F_51 ( V_317 ) ;
return V_65 ;
}
static T_11 V_329 ( int V_328 , void * V_354 )
{
int V_32 , V_238 ;
T_1 V_116 = 0 ;
T_1 V_208 = 0 ;
T_1 V_355 = 0 ;
struct V_209 * V_8 = (struct V_209 * ) V_354 ;
V_116 = F_112 ( V_8 -> V_202 -> V_203 . V_204 ) ;
if ( V_8 -> V_202 -> V_340 . V_204 )
V_208 = F_112 ( V_8 -> V_202 -> V_340 . V_204 ) ;
else
V_208 = F_112 ( V_8 -> V_202 -> V_203 . V_204 +
V_8 -> V_216 ) ;
F_13 ( L_83 ,
V_116 , V_208 , V_8 -> V_202 -> V_203 . V_204 ,
V_8 -> V_216 ) ;
if ( V_116 == 0x00 || V_116 == 0xff )
return V_356 ;
for ( V_32 = 0 ; V_8 -> V_218 [ V_32 ] . V_357 ; V_32 ++ ) {
if ( ( V_208 & V_8 -> V_218 [ V_32 ] . V_122 ) !=
V_8 -> V_218 [ V_32 ] . V_122 )
continue;
if ( ! ( V_357 & V_8 -> V_218 [ V_32 ] . V_357 ) )
continue;
for ( V_238 = 0 ; V_8 -> V_218 [ V_32 ] . V_358 [ V_238 ] . V_12 ; V_238 ++ ) {
if ( V_116 == V_8 -> V_218 [ V_32 ] . V_358 [ V_238 ] . V_122 ) {
V_355 =
V_8 -> V_218 [ V_32 ] . V_358 [ V_238 ] . V_12 ;
if ( ! V_355 )
return V_356 ;
goto V_359;
}
}
}
if ( V_8 -> V_226 && V_8 -> V_226 ( V_208 , V_116 ) == 0 )
return V_356 ;
F_13 ( L_84 ,
V_116 , V_208 , V_8 -> V_202 -> V_203 . V_204 ,
V_8 -> V_216 ) ;
return V_356 ;
V_359:
F_10 ( V_355 ) ;
F_70 ( V_8 -> V_360 , 1 , V_355 ) ;
F_156 ( V_355 ) ;
return V_356 ;
}
static int F_172 ( struct V_31 * V_80 , int type )
{
struct V_319 * V_338 , * V_361 ;
struct V_329 * V_328 , * V_362 ;
if ( F_169 ( V_80 ) ) {
F_20 ( L_85 ) ;
return - V_347 ;
}
F_173 ( V_201 . V_363 -> V_328 . V_332 [ 0 ] , & V_201 ) ;
F_174 ( V_201 . V_202 -> V_203 . V_204 ,
V_201 . V_202 -> V_203 . V_339 ) ;
if ( V_201 . V_202 -> V_340 . V_204 )
F_174 ( V_201 . V_202 -> V_340 . V_204 ,
V_201 . V_202 -> V_340 . V_339 ) ;
F_162 () ;
F_31 () ;
F_175 ( & V_61 -> V_8 . V_364 , & V_365 ) ;
F_40 () ;
F_176 (io, tmp_io, &spic_dev.ioports, list) {
F_177 ( & V_338 -> V_322 ) ;
F_51 ( V_338 ) ;
}
F_176 (irq, tmp_irq, &spic_dev.interrupts, list) {
F_177 ( & V_328 -> V_322 ) ;
F_51 ( V_328 ) ;
}
V_201 . V_202 = NULL ;
V_201 . V_363 = NULL ;
F_13 ( V_366 L_57 ) ;
return 0 ;
}
static int F_178 ( struct V_31 * V_80 )
{
int V_65 ;
struct V_319 * V_338 , * V_361 ;
struct V_329 * V_328 , * V_362 ;
F_68 ( L_49 , V_366 , V_190 ) ;
V_201 . V_360 = V_80 ;
strcpy ( F_105 ( V_80 ) , L_50 ) ;
F_117 ( & V_201 ) ;
F_179 ( & V_201 . V_242 ) ;
V_65 = F_167 ( V_80 ) ;
if ( V_65 ) {
F_20 ( L_86 ) ;
goto V_367;
}
V_65 = F_16 ( V_80 ) ;
if ( V_65 ) {
F_20 ( L_53 ) ;
goto V_367;
}
if ( F_159 () )
goto V_368;
F_180 (io, &spic_dev.ioports, list) {
if ( F_181 ( V_338 -> V_203 . V_204 , V_338 -> V_203 . V_339 ,
L_87 ) ) {
F_13 ( L_88 ,
V_338 -> V_203 . V_204 , V_338 -> V_203 . V_369 ,
V_338 -> V_203 . V_339 ) ;
if ( V_338 -> V_340 . V_204 ) {
if ( F_181 ( V_338 -> V_340 . V_204 ,
V_338 -> V_340 . V_339 ,
L_87 ) ) {
F_13 ( L_89 ,
V_338 -> V_340 . V_204 , V_338 -> V_340 . V_369 ,
V_338 -> V_340 . V_339 ) ;
V_201 . V_202 = V_338 ;
break;
}
else {
F_13 ( L_90
L_91 ,
V_338 -> V_340 . V_204 , V_338 -> V_340 . V_369 ,
V_338 -> V_340 . V_339 ) ;
F_174 ( V_338 -> V_203 . V_204 ,
V_338 -> V_203 . V_339 ) ;
}
}
else {
V_201 . V_202 = V_338 ;
break;
}
}
}
if ( ! V_201 . V_202 ) {
F_20 ( L_92 ) ;
V_65 = - V_192 ;
goto V_370;
}
F_180 (irq, &spic_dev.interrupts, list) {
if ( ! F_182 ( V_328 -> V_328 . V_332 [ 0 ] , V_329 ,
0 , L_6 , & V_201 ) ) {
F_13 ( L_93
L_94 ,
V_328 -> V_328 . V_332 [ 0 ] ,
V_328 -> V_328 . V_333 ,
V_328 -> V_328 . V_334 ,
V_328 -> V_328 . V_335 ) ;
V_201 . V_363 = V_328 ;
break;
}
}
if ( ! V_201 . V_363 ) {
F_20 ( L_95 ) ;
V_65 = - V_192 ;
goto V_371;
}
V_65 = F_170 ( V_80 , V_201 . V_202 , V_201 . V_363 ) ;
if ( V_65 ) {
F_20 ( L_96 ) ;
goto V_372;
}
V_201 . V_259 = - 1 ;
V_65 = F_34 () ;
if ( V_65 )
goto V_373;
V_65 = F_183 ( & V_61 -> V_8 . V_364 , & V_365 ) ;
if ( V_65 )
goto V_374;
return 0 ;
V_374:
F_40 () ;
V_373:
F_169 ( V_80 ) ;
V_372:
F_173 ( V_201 . V_363 -> V_328 . V_332 [ 0 ] , & V_201 ) ;
V_371:
F_174 ( V_201 . V_202 -> V_203 . V_204 ,
V_201 . V_202 -> V_203 . V_339 ) ;
if ( V_201 . V_202 -> V_340 . V_204 )
F_174 ( V_201 . V_202 -> V_340 . V_204 ,
V_201 . V_202 -> V_340 . V_339 ) ;
V_370:
F_162 () ;
V_368:
F_31 () ;
V_367:
F_176 (io, tmp_io, &spic_dev.ioports, list) {
F_177 ( & V_338 -> V_322 ) ;
F_51 ( V_338 ) ;
}
F_176 (irq, tmp_irq, &spic_dev.interrupts, list) {
F_177 ( & V_328 -> V_322 ) ;
F_51 ( V_328 ) ;
}
V_201 . V_202 = NULL ;
V_201 . V_363 = NULL ;
return V_65 ;
}
static int F_184 ( struct V_31 * V_80 , T_12 V_257 )
{
if ( F_169 ( V_80 ) )
return - V_347 ;
return 0 ;
}
static int F_185 ( struct V_31 * V_80 )
{
F_170 ( V_80 , V_201 . V_202 , V_201 . V_363 ) ;
return 0 ;
}
static int T_13 F_186 ( void )
{
int V_65 ;
if ( ! V_375 && F_187 ( V_376 ) ) {
V_65 = F_188 ( & V_377 ) ;
if ( V_65 ) {
F_20 ( L_97 ) ;
goto V_60;
}
V_378 = 1 ;
}
V_65 = F_188 ( & V_379 ) ;
if ( V_65 ) {
F_20 ( L_98 ) ;
goto V_380;
}
return 0 ;
V_380:
if ( V_378 )
F_189 ( & V_377 ) ;
V_60:
return V_65 ;
}
static void T_14 F_190 ( void )
{
F_189 ( & V_379 ) ;
if ( V_378 )
F_189 ( & V_377 ) ;
}

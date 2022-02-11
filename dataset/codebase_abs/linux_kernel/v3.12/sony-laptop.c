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
static union V_64 * F_42 ( T_2 V_65 , char * V_66 ,
T_3 * V_67 )
{
union V_64 * V_68 = NULL ;
struct V_69 V_70 = { V_71 , NULL } ;
T_4 V_72 ;
if ( V_67 ) {
struct V_73 V_74 ;
union V_64 V_75 ;
V_75 . type = V_76 ;
V_75 . integer . V_67 = * V_67 ;
V_74 . V_77 = 1 ;
V_74 . V_78 = & V_75 ;
V_72 = F_43 ( V_65 , V_66 , & V_74 , & V_70 ) ;
F_13 ( L_7 , V_66 ,
( unsigned int ) ( * V_67 >> 32 ) ,
( unsigned int ) * V_67 & 0xffffffff ) ;
} else {
V_72 = F_43 ( V_65 , V_66 , NULL , & V_70 ) ;
F_13 ( L_8 , V_66 ) ;
}
if ( F_44 ( V_72 ) ) {
F_20 ( L_9 , V_66 ) ;
return NULL ;
}
V_68 = (union V_64 * ) V_70 . V_78 ;
if ( ! V_68 )
F_13 ( L_10 , V_66 ) ;
return V_68 ;
}
static int F_45 ( T_2 V_65 , char * V_39 , int * V_67 ,
int * V_68 )
{
union V_64 * V_79 = NULL ;
if ( V_67 ) {
T_3 V_80 = * V_67 ;
V_79 = F_42 ( V_65 , V_39 , & V_80 ) ;
} else
V_79 = F_42 ( V_65 , V_39 , NULL ) ;
if ( ! V_79 )
return - V_81 ;
if ( V_79 -> type != V_76 ) {
F_46 ( L_11 ,
V_76 , V_79 -> type ) ;
F_47 ( V_79 ) ;
return - V_81 ;
}
if ( V_68 )
* V_68 = V_79 -> integer . V_67 ;
F_47 ( V_79 ) ;
return 0 ;
}
static int F_48 ( T_2 V_65 , char * V_39 , T_3 * V_67 ,
void * V_82 , T_5 V_83 )
{
int V_57 = 0 ;
T_5 V_84 = V_84 ;
union V_64 * V_79 = F_42 ( V_65 , V_39 , V_67 ) ;
if ( ! V_79 )
return - V_81 ;
if ( V_79 -> type == V_85 ) {
V_84 = F_49 ( V_83 , V_79 -> V_82 . V_86 ) ;
memcpy ( V_82 , V_79 -> V_82 . V_78 , V_84 ) ;
} else if ( V_79 -> type == V_76 ) {
V_84 = F_49 ( V_83 , sizeof( V_79 -> integer . V_67 ) ) ;
memcpy ( V_82 , & V_79 -> integer . V_67 , V_84 ) ;
} else {
F_46 ( L_11 ,
V_85 , V_79 -> type ) ;
V_57 = - V_81 ;
}
F_47 ( V_79 ) ;
return V_57 ;
}
static T_6 F_50 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
T_6 V_84 = 0 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < F_12 ( V_90 -> V_91 ) ; V_32 ++ ) {
V_84 += snprintf ( V_82 + V_84 , V_92 - V_84 , L_12 ,
V_90 -> V_91 [ V_32 ] ) ;
}
V_84 += snprintf ( V_82 + V_84 , V_92 - V_84 , L_13 ) ;
return V_84 ;
}
static int F_51 ( struct V_93 * V_94 )
{
int V_32 , V_95 , V_68 , V_96 ;
V_90 = F_52 ( sizeof( * V_90 ) , V_35 ) ;
if ( ! V_90 )
return - V_37 ;
for ( V_32 = 0 ; V_32 < F_12 ( V_90 -> V_91 ) ; V_32 ++ ) {
V_96 = V_32 + 0x20 ;
V_95 = F_45 ( V_97 , L_14 , & V_96 ,
& V_68 ) ;
if ( ! V_95 ) {
F_13 ( L_15 ,
V_68 , V_32 ) ;
V_90 -> V_91 [ V_32 ] = V_68 ;
}
}
if ( V_98 ) {
F_53 ( & V_90 -> V_99 . V_89 ) ;
V_90 -> V_99 . V_89 . V_39 = L_16 ;
V_90 -> V_99 . V_89 . V_100 = V_101 ;
V_90 -> V_99 . V_102 = F_50 ;
if ( F_54 ( & V_94 -> V_8 , & V_90 -> V_99 ) ) {
F_47 ( V_90 ) ;
V_90 = NULL ;
return - 1 ;
}
}
return 0 ;
}
static int F_55 ( struct V_93 * V_94 )
{
if ( V_90 ) {
if ( V_98 )
F_56 ( & V_94 -> V_8 , & V_90 -> V_99 ) ;
F_47 ( V_90 ) ;
V_90 = NULL ;
}
return 0 ;
}
static int F_57 ( int V_65 )
{
int V_32 ;
if ( ! V_90 || ! V_65 )
return - V_81 ;
for ( V_32 = 0 ; V_32 < 0x10 ; V_32 ++ ) {
if ( V_90 -> V_91 [ V_32 ] == V_65 ) {
F_13 ( L_17 ,
V_65 , V_32 ) ;
return V_32 ;
}
}
F_13 ( L_18 , V_65 ) ;
return - V_81 ;
}
static int F_58 ( int V_65 , int V_103 , int * V_68 )
{
int V_96 , V_57 = 0 ;
int V_104 = F_57 ( V_65 ) ;
if ( V_104 < 0 )
return V_104 ;
V_96 = V_104 | V_103 ;
V_57 = F_45 ( V_97 , L_19 , & V_96 , V_68 ) ;
F_13 ( L_20 , V_96 , * V_68 ) ;
return V_57 ;
}
static int F_59 ( const int V_105 , const int V_67 )
{
switch ( V_105 ) {
case V_106 :
return V_67 - 1 ;
case V_107 :
if ( V_67 >= 0 && V_67 < V_108 )
return V_67 + 1 ;
}
return - V_81 ;
}
static int F_60 ( const int V_105 , const int V_67 )
{
if ( V_105 == V_107 ) {
if ( V_67 != 0 && V_67 != 1 )
return - V_81 ;
}
return V_67 ;
}
static T_6 F_61 ( struct V_87 * V_8 , struct V_88 * V_89 ,
char * V_82 )
{
int V_67 , V_57 = 0 ;
struct V_109 * V_110 =
F_62 ( V_89 , struct V_109 , V_99 ) ;
if ( ! * V_110 -> V_111 )
return - V_112 ;
V_57 = F_45 ( V_97 , * V_110 -> V_111 , NULL ,
& V_67 ) ;
if ( V_57 < 0 )
return - V_112 ;
if ( V_110 -> V_113 )
V_67 = V_110 -> V_113 ( V_106 , V_67 ) ;
return snprintf ( V_82 , V_92 , L_21 , V_67 ) ;
}
static T_6 F_63 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
int V_67 ;
int V_57 = 0 ;
struct V_109 * V_110 =
F_62 ( V_89 , struct V_109 , V_99 ) ;
if ( ! V_110 -> V_114 )
return - V_112 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_64 ( V_82 , 10 , & V_67 ) )
return - V_81 ;
if ( V_110 -> V_113 )
V_67 = V_110 -> V_113 ( V_107 , V_67 ) ;
if ( V_67 < 0 )
return V_67 ;
V_57 = F_45 ( V_97 , * V_110 -> V_114 ,
& V_67 , NULL ) ;
if ( V_57 < 0 )
return - V_112 ;
V_110 -> V_67 = V_67 ;
V_110 -> V_115 = 1 ;
return V_77 ;
}
static int F_65 ( struct V_116 * V_117 )
{
int V_96 = V_117 -> V_118 . V_119 + 1 ;
return F_45 ( V_97 , L_22 , & V_96 , NULL ) ;
}
static int F_66 ( struct V_116 * V_117 )
{
int V_67 ;
if ( F_45 ( V_97 , L_23 , NULL , & V_67 ) )
return 0 ;
return V_67 - 1 ;
}
static int F_67 ( struct V_116 * V_117 )
{
int V_68 ;
struct V_120 * V_121 =
(struct V_120 * ) F_68 ( V_117 ) ;
F_58 ( V_121 -> V_65 , V_121 -> V_122 + 0x100 , & V_68 ) ;
return ( V_68 & 0xff ) - V_121 -> V_104 ;
}
static int F_69 ( struct V_116 * V_117 )
{
int V_67 , V_68 ;
struct V_120 * V_121 =
(struct V_120 * ) F_68 ( V_117 ) ;
V_67 = V_117 -> V_118 . V_119 + V_121 -> V_104 ;
if ( F_58 ( V_121 -> V_65 , V_121 -> V_122 | ( V_67 << 0x10 ) ,
& V_68 ) )
return - V_112 ;
return V_67 ;
}
static int F_70 ( T_7 V_12 , unsigned int V_65 )
{
int V_57 = - V_81 ;
unsigned int V_68 = 0 ;
struct V_123 * V_124 ;
if ( F_58 ( V_65 , 0x200 , & V_68 ) ) {
F_13 ( L_24 , V_65 ,
V_12 ) ;
return - V_81 ;
}
V_68 &= 0xFF ;
if ( V_65 == 0x0100 )
V_124 = V_125 ;
else
V_124 = V_126 ;
for (; V_124 -> V_127 ; V_124 ++ ) {
if ( V_124 -> V_127 == V_68 ) {
V_57 = V_124 -> V_12 ;
break;
}
}
if ( ! V_124 -> V_127 )
F_71 ( L_25 ,
V_12 , V_68 , V_65 ) ;
return V_57 ;
}
static void F_72 ( struct V_31 * V_87 , T_7 V_12 )
{
T_7 V_128 = V_12 ;
T_1 V_129 = 0 ;
F_13 ( L_26 , V_12 ) ;
if ( V_12 >= 0x90 ) {
unsigned int V_68 = 0 ;
unsigned int V_96 = 0 ;
unsigned int V_65 = 0 ;
unsigned int V_104 = V_12 - 0x90 ;
if ( V_104 >= F_12 ( V_90 -> V_91 ) ) {
F_20 ( L_27 ,
V_12 ) ;
return;
}
V_65 = V_90 -> V_91 [ V_104 ] ;
switch ( V_65 ) {
case 0x0100 :
case 0x0127 :
V_129 = V_130 ;
V_128 = F_70 ( V_12 , V_65 ) ;
if ( V_128 > 0 )
F_10 ( V_128 ) ;
else
V_128 = V_12 ;
break;
case 0x0124 :
case 0x0135 :
V_129 = V_131 ;
F_58 ( V_65 , 0x0100 , & V_68 ) ;
V_128 = V_68 & 0x03 ;
if ( V_128 == 1 )
F_73 () ;
break;
case 0x0128 :
case 0x0146 :
F_58 ( V_65 , 0x0000 , & V_68 ) ;
F_13 ( L_28 ,
( V_68 == 0x1 ) ? L_29 :
( V_68 == 0x2 ) ? L_30 :
( V_68 == 0x3 ) ? L_30 :
L_31 ) ;
V_129 = V_132 ;
V_128 = F_74 () ;
break;
case 0x015B :
V_129 = V_132 ;
V_128 = F_74 () ;
break;
default:
F_13 ( L_32 ,
V_12 , V_65 ) ;
break;
}
V_96 = 1 << V_104 ;
F_45 ( V_97 , L_33 , & V_96 , & V_68 ) ;
} else {
V_129 = V_130 ;
F_10 ( V_128 ) ;
}
F_75 ( V_133 -> V_134 . V_135 ,
F_76 ( & V_133 -> V_8 ) , V_129 , V_128 ) ;
}
static T_4 F_77 ( T_2 V_65 , T_7 V_136 ,
void * V_137 , void * * V_138 )
{
struct V_139 * V_140 ;
if ( F_78 ( F_79 ( V_65 , & V_140 ) ) ) {
F_46 ( L_34 ,
( char * ) & V_140 -> V_39 , V_140 -> V_141 ) ;
F_47 ( V_140 ) ;
}
return V_142 ;
}
static void F_80 ( struct V_31 * V_87 ,
struct V_93 * V_143 )
{
unsigned int V_32 , V_68 , V_144 , V_96 ;
if ( ! V_90 )
return;
for ( V_32 = 0 ; V_32 < F_12 ( V_90 -> V_91 ) ; V_32 ++ ) {
unsigned int V_65 = V_90 -> V_91 [ V_32 ] ;
if ( ! V_65 )
continue;
F_13 ( L_35 , V_65 ) ;
switch ( V_65 ) {
case 0x0100 :
case 0x0101 :
case 0x0127 :
F_58 ( V_65 , 0 , & V_68 ) ;
break;
case 0x0102 :
F_58 ( V_65 , 0x100 , & V_68 ) ;
break;
case 0x0105 :
case 0x0148 :
V_68 = F_81 ( V_143 , V_65 ) ;
if ( V_68 )
F_20 ( L_36 ,
V_68 ) ;
break;
case 0x0115 :
case 0x0136 :
case 0x013f :
V_68 = F_82 ( V_143 , V_65 ) ;
if ( V_68 )
F_20 ( L_37 ,
V_68 ) ;
break;
case 0x0119 :
V_68 = F_83 ( V_143 ) ;
if ( V_68 )
F_20 ( L_38 ,
V_68 ) ;
break;
case 0x0122 :
V_68 = F_84 ( V_143 ) ;
if ( V_68 )
F_20 ( L_39 ,
V_68 ) ;
break;
case 0x0128 :
case 0x0146 :
case 0x015B :
V_68 = F_85 ( V_143 , V_65 ) ;
if ( V_68 )
F_20 ( L_40 ,
V_68 ) ;
break;
case 0x0131 :
V_68 = F_86 ( V_143 ) ;
if ( V_68 )
F_20 ( L_41 ,
V_68 ) ;
break;
case 0x0124 :
case 0x0135 :
V_68 = F_87 ( V_87 , V_65 ) ;
if ( V_68 )
F_20 ( L_42 ,
V_68 ) ;
break;
case 0x0137 :
case 0x0143 :
case 0x014b :
case 0x014c :
case 0x0163 :
V_68 = F_88 ( V_143 , V_65 ) ;
if ( V_68 )
F_20 ( L_43 ,
V_68 ) ;
break;
default:
continue;
}
}
V_96 = 0x10 ;
if ( ! F_45 ( V_97 , L_14 , & V_96 , & V_144 ) )
F_45 ( V_97 , L_44 , & V_144 ,
& V_68 ) ;
}
static void F_89 ( struct V_93 * V_94 )
{
unsigned int V_32 , V_68 , V_144 , V_65 ;
F_45 ( V_97 , L_45 , NULL , & V_144 ) ;
F_45 ( V_97 , L_46 , & V_144 , & V_68 ) ;
for ( V_32 = 0 ; V_32 < F_12 ( V_90 -> V_91 ) ; V_32 ++ ) {
V_65 = V_90 -> V_91 [ V_32 ] ;
if ( ! V_65 )
continue;
switch ( V_65 ) {
case 0x0105 :
case 0x0148 :
F_90 ( V_94 ) ;
break;
case 0x0115 :
case 0x0136 :
case 0x013f :
F_91 ( V_94 ) ;
break;
case 0x0119 :
F_92 ( V_94 ) ;
break;
case 0x0122 :
F_93 ( V_94 ) ;
break;
case 0x0128 :
case 0x0146 :
case 0x015B :
F_94 ( V_94 ) ;
break;
case 0x0131 :
F_95 ( V_94 ) ;
break;
case 0x0124 :
case 0x0135 :
F_96 () ;
break;
case 0x0137 :
case 0x0143 :
case 0x014b :
case 0x014c :
case 0x0163 :
F_97 ( V_94 ) ;
break;
default:
continue;
}
}
F_55 ( V_94 ) ;
}
static void F_98 ( void )
{
unsigned int V_32 , V_68 , V_144 , V_96 ;
F_13 ( L_47 ) ;
for ( V_32 = 0 ; V_32 < F_12 ( V_90 -> V_91 ) ; V_32 ++ ) {
unsigned int V_65 = V_90 -> V_91 [ V_32 ] ;
if ( ! V_65 )
continue;
switch ( V_65 ) {
case 0x0100 :
case 0x0101 :
case 0x0127 :
F_58 ( V_65 , 0 , & V_68 ) ;
break;
case 0x0102 :
F_58 ( V_65 , 0x100 , & V_68 ) ;
break;
case 0x0122 :
F_99 () ;
break;
case 0x0124 :
case 0x0135 :
F_73 () ;
break;
case 0x0137 :
case 0x0143 :
case 0x014b :
case 0x014c :
case 0x0163 :
F_100 () ;
break;
default:
continue;
}
}
V_96 = 0x10 ;
if ( ! F_45 ( V_97 , L_14 , & V_96 , & V_144 ) )
F_45 ( V_97 , L_44 , & V_144 ,
& V_68 ) ;
}
static int F_101 ( struct V_87 * V_8 )
{
struct V_109 * V_110 ;
T_2 V_65 ;
for ( V_110 = V_145 ; V_110 -> V_39 ; V_110 ++ ) {
int V_57 ;
if ( ! V_110 -> V_115 )
continue;
V_57 = F_45 ( V_97 , * V_110 -> V_114 ,
& V_110 -> V_67 , NULL ) ;
if ( V_57 < 0 ) {
F_20 ( L_48 , V_146 , V_57 ) ;
break;
}
}
if ( F_78 ( F_102 ( V_97 , L_49 ,
& V_65 ) ) ) {
int V_96 = 1 ;
if ( F_45 ( V_97 , L_49 , & V_96 , NULL ) )
F_13 ( L_50 ) ;
}
if ( F_78 ( F_102 ( V_97 , L_14 ,
& V_65 ) ) )
F_98 () ;
return 0 ;
}
static void F_96 ( void )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_147 ; V_32 ++ ) {
if ( V_148 [ V_32 ] ) {
F_103 ( V_148 [ V_32 ] ) ;
F_104 ( V_148 [ V_32 ] ) ;
}
}
}
static int F_105 ( void * V_127 , bool V_149 )
{
int V_68 ;
int V_103 = V_150 [ ( long ) V_127 ] + 0x100 ;
if ( ! V_149 )
V_103 |= 0x070000 ;
return F_58 ( V_151 , V_103 , & V_68 ) ;
}
static int F_106 ( struct V_31 * V_87 ,
enum V_152 V_153 )
{
int V_154 = 0 ;
struct V_155 * V_156 ;
enum V_157 type ;
const char * V_39 ;
int V_68 ;
bool V_158 , V_159 ;
switch ( V_153 ) {
case V_160 :
type = V_161 ;
V_39 = L_51 ;
break;
case V_162 :
type = V_163 ;
V_39 = L_52 ;
break;
case V_164 :
type = V_165 ;
V_39 = L_53 ;
break;
case V_166 :
type = V_167 ;
V_39 = L_54 ;
break;
default:
return - V_81 ;
}
V_156 = F_107 ( V_39 , & V_87 -> V_8 , type ,
& V_168 , ( void * ) V_153 ) ;
if ( ! V_156 )
return - V_37 ;
if ( F_58 ( V_151 , 0x200 , & V_68 ) < 0 ) {
F_104 ( V_156 ) ;
return - 1 ;
}
V_158 = ! ( V_68 & 0x1 ) ;
if ( F_58 ( V_151 ,
V_150 [ V_153 ] ,
& V_68 ) < 0 ) {
F_104 ( V_156 ) ;
return - 1 ;
}
V_159 = ! ( V_68 & 0x2 ) ;
F_108 ( V_156 , V_159 ) ;
F_109 ( V_156 , V_158 ) ;
V_154 = F_110 ( V_156 ) ;
if ( V_154 ) {
F_104 ( V_156 ) ;
return V_154 ;
}
V_148 [ V_153 ] = V_156 ;
return V_154 ;
}
static void F_73 ( void )
{
enum V_152 V_32 ;
int V_68 ;
bool V_158 ;
F_58 ( V_151 , 0x200 , & V_68 ) ;
V_158 = ! ( V_68 & 0x1 ) ;
for ( V_32 = 0 ; V_32 < V_147 ; V_32 ++ ) {
int V_103 = V_150 [ V_32 ] ;
if ( ! V_148 [ V_32 ] )
continue;
if ( V_158 ) {
if ( F_109 ( V_148 [ V_32 ] , true ) ) {
}
continue;
}
F_58 ( V_151 , V_103 , & V_68 ) ;
F_111 ( V_148 [ V_32 ] ,
! ( V_68 & 0x2 ) , false ) ;
}
}
static int F_87 ( struct V_31 * V_87 ,
unsigned int V_65 )
{
T_3 V_104 ;
int V_32 ;
unsigned char V_82 [ 32 ] = { 0 } ;
V_104 = F_57 ( V_65 ) ;
V_151 = V_65 ;
V_32 = F_48 ( V_97 , L_55 , & V_104 , V_82 ,
32 ) ;
if ( V_32 < 0 )
return V_32 ;
for ( V_32 = 0 ; V_32 < F_12 ( V_82 ) ; V_32 ++ ) {
if ( V_82 [ V_32 ] == 0xff )
break;
F_13 ( L_56 , V_82 [ V_32 ] ) ;
if ( V_82 [ V_32 ] == 0 && ! V_148 [ V_160 ] )
F_106 ( V_87 , V_160 ) ;
if ( V_82 [ V_32 ] == 0x10 && ! V_148 [ V_162 ] )
F_106 ( V_87 , V_162 ) ;
if ( ( ( 0xf0 & V_82 [ V_32 ] ) == 0x20 ||
( 0xf0 & V_82 [ V_32 ] ) == 0x50 ) &&
! V_148 [ V_164 ] )
F_106 ( V_87 , V_164 ) ;
if ( V_82 [ V_32 ] == 0x30 && ! V_148 [ V_166 ] )
F_106 ( V_87 , V_166 ) ;
}
return 0 ;
}
static T_6 F_112 ( T_1 V_67 )
{
int V_68 ;
if ( V_67 > 1 )
return - V_81 ;
if ( F_58 ( V_169 -> V_65 ,
( V_67 << 0x10 ) | ( V_169 -> V_170 ) , & V_68 ) )
return - V_112 ;
F_58 ( V_169 -> V_65 ,
( V_67 << 0x10 ) | ( V_169 -> V_170 + 0x100 ) , & V_68 ) ;
V_169 -> V_100 = V_67 ;
return 0 ;
}
static T_6 F_113 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
int V_57 = 0 ;
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_114 ( V_82 , 10 , & V_67 ) )
return - V_81 ;
V_57 = F_112 ( V_67 ) ;
if ( V_57 < 0 )
return V_57 ;
return V_77 ;
}
static T_6 F_115 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
T_6 V_77 = 0 ;
V_77 = snprintf ( V_82 , V_92 , L_21 , V_169 -> V_100 ) ;
return V_77 ;
}
static int F_116 ( T_1 V_67 )
{
int V_68 ;
if ( V_67 > 3 )
return - V_81 ;
if ( F_58 ( V_169 -> V_65 , ( V_67 << 0x10 ) |
( V_169 -> V_170 + 0x200 ) , & V_68 ) )
return - V_112 ;
V_169 -> V_171 = V_67 ;
return 0 ;
}
static T_6 F_117 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
int V_57 = 0 ;
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_114 ( V_82 , 10 , & V_67 ) )
return - V_81 ;
V_57 = F_116 ( V_67 ) ;
if ( V_57 < 0 )
return V_57 ;
return V_77 ;
}
static T_6 F_118 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
T_6 V_77 = 0 ;
V_77 = snprintf ( V_82 , V_92 , L_21 , V_169 -> V_171 ) ;
return V_77 ;
}
static int F_88 ( struct V_93 * V_94 ,
unsigned int V_65 )
{
int V_68 ;
int V_57 = 0 ;
V_57 = F_58 ( V_65 , V_65 == 0x0137 ? 0x0B00 : 0x0100 ,
& V_68 ) ;
if ( V_57 )
return V_57 ;
if ( ( V_65 == 0x0137 && ! ( V_68 & 0x02 ) ) ||
! ( V_68 & 0x01 ) ) {
F_13 ( L_57 ) ;
return 0 ;
}
V_169 = F_52 ( sizeof( * V_169 ) , V_35 ) ;
if ( ! V_169 )
return - V_37 ;
V_169 -> V_100 = V_172 ;
V_169 -> V_171 = V_173 ;
V_169 -> V_65 = V_65 ;
if ( V_65 == 0x0137 )
V_169 -> V_170 = 0x0C00 ;
else
V_169 -> V_170 = 0x4000 ;
F_53 ( & V_169 -> V_174 . V_89 ) ;
V_169 -> V_174 . V_89 . V_39 = L_58 ;
V_169 -> V_174 . V_89 . V_100 = V_101 | V_175 ;
V_169 -> V_174 . V_102 = F_115 ;
V_169 -> V_174 . V_176 = F_113 ;
F_53 ( & V_169 -> V_177 . V_89 ) ;
V_169 -> V_177 . V_89 . V_39 = L_59 ;
V_169 -> V_177 . V_89 . V_100 = V_101 | V_175 ;
V_169 -> V_177 . V_102 = F_118 ;
V_169 -> V_177 . V_176 = F_117 ;
V_57 = F_54 ( & V_94 -> V_8 , & V_169 -> V_174 ) ;
if ( V_57 )
goto V_178;
V_57 = F_54 ( & V_94 -> V_8 , & V_169 -> V_177 ) ;
if ( V_57 )
goto V_179;
F_112 ( V_169 -> V_100 ) ;
F_116 ( V_169 -> V_171 ) ;
return 0 ;
V_179:
F_56 ( & V_94 -> V_8 , & V_169 -> V_174 ) ;
V_178:
F_47 ( V_169 ) ;
V_169 = NULL ;
return V_57 ;
}
static void F_97 ( struct V_93 * V_94 )
{
if ( V_169 ) {
F_56 ( & V_94 -> V_8 , & V_169 -> V_174 ) ;
F_56 ( & V_94 -> V_8 , & V_169 -> V_177 ) ;
F_47 ( V_169 ) ;
V_169 = NULL ;
}
}
static void F_100 ( void )
{
int V_180 = 0 ;
if ( ! V_169 )
return;
if ( V_169 -> V_100 == 0 )
F_58 ( V_169 -> V_65 , V_169 -> V_170 ,
& V_180 ) ;
if ( V_169 -> V_171 != 0 )
F_58 ( V_169 -> V_65 ,
( V_169 -> V_170 + 0x200 ) |
( V_169 -> V_171 << 0x10 ) , & V_180 ) ;
}
static T_6 F_119 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
unsigned int V_68 , V_181 ;
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_114 ( V_82 , 10 , & V_67 ) )
return - V_81 ;
V_181 = 0 ;
if ( V_67 > 0 ) {
if ( V_67 <= 50 )
V_181 = 0x20 ;
else if ( V_67 <= 80 )
V_181 = 0x10 ;
else if ( V_67 <= 100 )
V_181 = 0x30 ;
else
return - V_81 ;
if ( V_182 -> V_65 != 0x013f )
V_181 = V_181 | ( V_181 << 2 ) ;
V_181 = ( V_181 | 0x1 ) << 0x10 ;
}
if ( F_58 ( V_182 -> V_65 , V_181 | 0x0100 , & V_68 ) )
return - V_112 ;
return V_77 ;
}
static T_6 F_120 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
unsigned int V_68 , V_72 ;
if ( F_58 ( V_182 -> V_65 , 0x0000 , & V_68 ) )
return - V_112 ;
V_72 = ( V_68 & 0x01 ) ? ( ( V_68 & 0x30 ) >> 0x04 ) : 0 ;
switch ( V_72 ) {
case 1 :
V_72 = 80 ;
break;
case 2 :
V_72 = 50 ;
break;
case 3 :
V_72 = 100 ;
break;
default:
V_72 = 0 ;
break;
}
return snprintf ( V_82 , V_92 , L_21 , V_72 ) ;
}
static T_6 F_121 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
T_6 V_77 = 0 ;
unsigned int V_183 ;
if ( F_58 ( V_182 -> V_65 , 0x0200 , & V_183 ) )
return - V_112 ;
V_77 = snprintf ( V_82 , V_92 , L_21 , V_183 & 0xff ) ;
return V_77 ;
}
static int F_82 ( struct V_93 * V_94 ,
unsigned int V_65 )
{
int V_57 = 0 ;
V_182 = F_52 ( sizeof( struct V_184 ) , V_35 ) ;
if ( ! V_182 )
return - V_37 ;
V_182 -> V_65 = V_65 ;
F_53 ( & V_182 -> V_185 [ 0 ] . V_89 ) ;
V_182 -> V_185 [ 0 ] . V_89 . V_39 = L_60 ;
V_182 -> V_185 [ 0 ] . V_89 . V_100 = V_101 | V_175 ;
V_182 -> V_185 [ 0 ] . V_102 = F_120 ;
V_182 -> V_185 [ 0 ] . V_176 = F_119 ;
V_57 = F_54 ( & V_94 -> V_8 , & V_182 -> V_185 [ 0 ] ) ;
if ( V_57 )
goto V_178;
if ( V_65 == 0x0115 )
return 0 ;
F_53 ( & V_182 -> V_185 [ 1 ] . V_89 ) ;
V_182 -> V_185 [ 1 ] . V_89 . V_39 = L_61 ;
V_182 -> V_185 [ 1 ] . V_89 . V_100 = V_101 ;
V_182 -> V_185 [ 1 ] . V_102 = F_121 ;
V_57 = F_54 ( & V_94 -> V_8 , & V_182 -> V_185 [ 1 ] ) ;
if ( V_57 )
goto V_186;
return 0 ;
V_186:
F_56 ( & V_94 -> V_8 , & V_182 -> V_185 [ 0 ] ) ;
V_178:
F_47 ( V_182 ) ;
V_182 = NULL ;
return V_57 ;
}
static void F_91 ( struct V_93 * V_94 )
{
if ( V_182 ) {
F_56 ( & V_94 -> V_8 , & V_182 -> V_185 [ 0 ] ) ;
if ( V_182 -> V_65 != 0x0115 )
F_56 ( & V_94 -> V_8 , & V_182 -> V_185 [ 1 ] ) ;
F_47 ( V_182 ) ;
V_182 = NULL ;
}
}
static int F_122 ( unsigned short V_100 )
{
unsigned int V_68 ;
if ( ( V_100 && ! ( V_187 -> V_188 & V_100 ) ) || V_100 >= V_189 )
return - V_81 ;
if ( F_58 ( 0x0122 , V_100 << 0x10 | 0x0200 , & V_68 ) )
return - V_112 ;
V_187 -> V_100 = V_100 ;
return 0 ;
}
static int F_123 ( void )
{
unsigned int V_68 ;
if ( F_58 ( 0x0122 , 0x0100 , & V_68 ) )
return - V_112 ;
return V_68 & 0xff ;
}
static T_6 F_124 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
short V_190 ;
T_5 V_191 = 0 ;
for ( V_190 = 0 ; V_190 < V_189 ; V_190 ++ ) {
if ( ! V_190 || ( V_187 -> V_188 & V_190 ) )
V_191 += snprintf ( V_82 + V_191 , V_92 - V_191 , L_62 ,
V_192 [ V_190 ] ) ;
}
V_191 += snprintf ( V_82 + V_191 , V_92 - V_191 , L_13 ) ;
return V_191 ;
}
static T_6 F_125 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
unsigned short V_181 ;
T_5 V_84 = V_77 ;
if ( V_77 == 0 )
return - V_81 ;
if ( V_82 [ V_84 - 1 ] == '\n' )
V_84 -- ;
for ( V_181 = 0 ; V_181 < V_189 ; V_181 ++ )
if ( strncmp ( V_82 , V_192 [ V_181 ] , V_84 ) == 0 )
break;
if ( F_122 ( V_181 ) )
return - V_112 ;
return V_77 ;
}
static T_6 F_126 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
T_6 V_77 = 0 ;
int V_100 = F_123 () ;
if ( V_100 < 0 )
return V_100 ;
V_77 = snprintf ( V_82 , V_92 , L_63 , V_192 [ V_100 ] ) ;
return V_77 ;
}
static int F_84 ( struct V_93 * V_94 )
{
int V_57 = 0 ;
V_187 = F_52 ( sizeof( struct V_193 ) , V_35 ) ;
if ( ! V_187 )
return - V_37 ;
V_57 = F_58 ( 0x0122 , 0x0000 , & V_187 -> V_188 ) ;
if ( V_57 ) {
F_46 ( L_64 ) ;
goto V_178;
}
V_57 = F_123 () ;
if ( V_57 < 0 ) {
F_46 ( L_65 ) ;
goto V_178;
}
V_187 -> V_100 = V_57 ;
F_53 ( & V_187 -> V_194 . V_89 ) ;
V_187 -> V_194 . V_89 . V_39 = L_66 ;
V_187 -> V_194 . V_89 . V_100 = V_101 ;
V_187 -> V_194 . V_102 = F_124 ;
F_53 ( & V_187 -> V_174 . V_89 ) ;
V_187 -> V_174 . V_89 . V_39 = L_67 ;
V_187 -> V_174 . V_89 . V_100 = V_101 | V_175 ;
V_187 -> V_174 . V_102 = F_126 ;
V_187 -> V_174 . V_176 = F_125 ;
V_57 = F_54 ( & V_94 -> V_8 , & V_187 -> V_194 ) ;
if ( V_57 )
goto V_178;
V_57 = F_54 ( & V_94 -> V_8 , & V_187 -> V_174 ) ;
if ( V_57 )
goto V_195;
return 0 ;
V_195:
F_56 ( & V_94 -> V_8 , & V_187 -> V_194 ) ;
V_178:
F_47 ( V_187 ) ;
V_187 = NULL ;
return V_57 ;
}
static void F_93 ( struct V_93 * V_94 )
{
if ( V_187 ) {
F_56 ( & V_94 -> V_8 , & V_187 -> V_194 ) ;
F_56 ( & V_94 -> V_8 , & V_187 -> V_174 ) ;
F_47 ( V_187 ) ;
V_187 = NULL ;
}
}
static void F_99 ( void )
{
unsigned int V_72 = F_123 () ;
if ( V_72 != V_187 -> V_100 )
F_122 ( V_187 -> V_100 ) ;
}
static T_6 F_127 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
unsigned int V_68 , V_196 ;
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_114 ( V_82 , 10 , & V_67 ) || V_67 > 1 )
return - V_81 ;
if ( strcmp ( V_89 -> V_89 . V_39 , L_68 ) == 0 )
V_196 = 2 ;
else if ( strcmp ( V_89 -> V_89 . V_39 , L_69 ) == 0 )
V_196 = 1 ;
else if ( strcmp ( V_89 -> V_89 . V_39 , L_70 ) == 0 )
V_196 = 0 ;
else
return - V_81 ;
if ( V_67 )
V_67 = V_197 -> V_72 | ( 1 << V_196 ) ;
else
V_67 = V_197 -> V_72 & ~ ( 1 << V_196 ) ;
if ( F_58 ( 0x0119 , V_67 << 0x10 | 0x0100 , & V_68 ) )
return - V_112 ;
V_197 -> V_72 = V_67 ;
return V_77 ;
}
static T_6 F_128 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
unsigned int V_196 ;
if ( strcmp ( V_89 -> V_89 . V_39 , L_68 ) == 0 )
V_196 = 2 ;
else if ( strcmp ( V_89 -> V_89 . V_39 , L_69 ) == 0 )
V_196 = 1 ;
else if ( strcmp ( V_89 -> V_89 . V_39 , L_70 ) == 0 )
V_196 = 0 ;
else
return - V_81 ;
return snprintf ( V_82 , V_92 , L_21 ,
( V_197 -> V_72 >> V_196 ) & 0x01 ) ;
}
static int F_83 ( struct V_93 * V_94 )
{
unsigned int V_68 ;
int V_32 ;
if ( F_58 ( 0x0119 , 0x0000 , & V_68 ) )
return - V_112 ;
V_197 = F_52 ( sizeof( struct V_198 ) , V_35 ) ;
if ( ! V_197 )
return - V_37 ;
V_197 -> V_72 = V_68 & 0x7 ;
F_53 ( & V_197 -> V_185 [ 0 ] . V_89 ) ;
V_197 -> V_185 [ 0 ] . V_89 . V_39 = L_68 ;
V_197 -> V_185 [ 0 ] . V_89 . V_100 = V_101 | V_175 ;
V_197 -> V_185 [ 0 ] . V_102 = F_128 ;
V_197 -> V_185 [ 0 ] . V_176 = F_127 ;
F_53 ( & V_197 -> V_185 [ 1 ] . V_89 ) ;
V_197 -> V_185 [ 1 ] . V_89 . V_39 = L_69 ;
V_197 -> V_185 [ 1 ] . V_89 . V_100 = V_101 | V_175 ;
V_197 -> V_185 [ 1 ] . V_102 = F_128 ;
V_197 -> V_185 [ 1 ] . V_176 = F_127 ;
F_53 ( & V_197 -> V_185 [ 2 ] . V_89 ) ;
V_197 -> V_185 [ 2 ] . V_89 . V_39 = L_70 ;
V_197 -> V_185 [ 2 ] . V_89 . V_100 = V_101 | V_175 ;
V_197 -> V_185 [ 2 ] . V_102 = F_128 ;
V_197 -> V_185 [ 2 ] . V_176 = F_127 ;
for ( V_32 = 0 ; V_32 < 3 ; V_32 ++ ) {
V_68 = F_54 ( & V_94 -> V_8 , & V_197 -> V_185 [ V_32 ] ) ;
if ( V_68 )
goto V_199;
}
return 0 ;
V_199:
for ( V_32 -- ; V_32 >= 0 ; V_32 -- )
F_56 ( & V_94 -> V_8 , & V_197 -> V_185 [ V_32 ] ) ;
F_47 ( V_197 ) ;
V_197 = NULL ;
return V_68 ;
}
static void F_92 ( struct V_93 * V_94 )
{
int V_32 ;
if ( V_197 ) {
for ( V_32 = 0 ; V_32 < 3 ; V_32 ++ )
F_56 ( & V_94 -> V_8 , & V_197 -> V_185 [ V_32 ] ) ;
F_47 ( V_197 ) ;
V_197 = NULL ;
}
}
static int F_74 ( void )
{
unsigned int V_68 ;
if ( F_58 ( V_200 -> V_65 ,
V_200 -> V_65 == 0x015B ? 0x0000 : 0x0100 ,
& V_68 ) )
return - V_112 ;
switch ( V_200 -> V_65 ) {
case 0x0146 :
return V_68 & 0x1 ? V_201 : V_202 ;
break;
case 0x015B :
return V_68 & 0x1 ? V_202 : V_201 ;
break;
case 0x0128 :
F_13 ( L_71 , V_68 ) ;
return V_68 & 0x80 ? AUTO :
V_68 & 0x02 ? V_202 : V_201 ;
break;
}
return - V_81 ;
}
static T_6 F_129 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
char * V_82 )
{
int V_196 = F_74 () ;
if ( V_196 < 0 )
return V_196 ;
return snprintf ( V_82 , V_92 , L_63 ,
V_196 == V_201 ? L_72 :
V_196 == V_202 ? L_73 :
V_196 == AUTO ? L_74 : L_75 ) ;
}
static int F_85 ( struct V_93 * V_94 ,
unsigned int V_65 )
{
unsigned int V_68 ;
V_200 = F_52 ( sizeof( struct V_203 ) , V_35 ) ;
if ( ! V_200 )
return - V_37 ;
V_200 -> V_65 = V_65 ;
F_53 ( & V_200 -> V_89 . V_89 ) ;
V_200 -> V_89 . V_89 . V_39 = L_76 ;
V_200 -> V_89 . V_89 . V_100 = V_101 ;
V_200 -> V_89 . V_102 = F_129 ;
V_68 = F_54 ( & V_94 -> V_8 , & V_200 -> V_89 ) ;
if ( V_68 )
goto V_204;
return 0 ;
V_204:
F_47 ( V_200 ) ;
V_200 = NULL ;
return V_68 ;
}
static void F_94 ( struct V_93 * V_94 )
{
if ( V_200 ) {
F_56 ( & V_94 -> V_8 , & V_200 -> V_89 ) ;
F_47 ( V_200 ) ;
V_200 = NULL ;
}
}
static T_6 F_130 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
unsigned int V_68 ;
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_114 ( V_82 , 10 , & V_67 ) || V_67 > 1 )
return - V_81 ;
if ( F_58 ( 0x0131 , V_67 << 0x10 | 0x0200 , & V_68 ) )
return - V_112 ;
return V_77 ;
}
static T_6 F_131 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
unsigned int V_68 ;
if ( F_58 ( 0x0131 , 0x0100 , & V_68 ) )
return - V_112 ;
return snprintf ( V_82 , V_92 , L_21 , V_68 & 0x01 ) ;
}
static int F_86 ( struct V_93 * V_94 )
{
unsigned int V_68 ;
if ( F_58 ( 0x0131 , 0x0000 , & V_68 ) || ! ( V_68 & 0x01 ) ) {
F_71 ( L_77 ) ;
return 0 ;
}
V_205 = F_52 ( sizeof( struct V_88 ) , V_35 ) ;
if ( ! V_205 )
return - V_37 ;
F_53 ( & V_205 -> V_89 ) ;
V_205 -> V_89 . V_39 = L_78 ;
V_205 -> V_89 . V_100 = V_101 | V_175 ;
V_205 -> V_102 = F_131 ;
V_205 -> V_176 = F_130 ;
V_68 = F_54 ( & V_94 -> V_8 , V_205 ) ;
if ( V_68 ) {
F_47 ( V_205 ) ;
V_205 = NULL ;
return V_68 ;
}
return 0 ;
}
static void F_95 ( struct V_93 * V_94 )
{
if ( V_205 ) {
F_56 ( & V_94 -> V_8 , V_205 ) ;
F_47 ( V_205 ) ;
V_205 = NULL ;
}
}
static T_6 F_132 ( struct V_87 * V_8 ,
struct V_88 * V_89 , const char * V_82 , T_5 V_77 )
{
unsigned int V_68 ;
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_114 ( V_82 , 10 , & V_67 ) || V_67 > 1 )
return - V_81 ;
if ( F_58 ( V_206 -> V_65 ,
( ! V_67 << 0x10 ) | 0x100 , & V_68 ) )
return - V_112 ;
return V_77 ;
}
static T_6 F_133 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
unsigned int V_68 ;
if ( F_58 ( V_206 -> V_65 , 0x000 , & V_68 ) )
return - V_81 ;
return snprintf ( V_82 , V_92 , L_21 , ! ( V_68 & 0x01 ) ) ;
}
static int F_81 ( struct V_93 * V_94 ,
unsigned int V_65 )
{
int V_57 = 0 ;
V_206 = F_52 ( sizeof( struct V_207 ) , V_35 ) ;
if ( ! V_206 )
return - V_37 ;
V_206 -> V_65 = V_65 ;
F_53 ( & V_206 -> V_89 . V_89 ) ;
V_206 -> V_89 . V_89 . V_39 = L_79 ;
V_206 -> V_89 . V_89 . V_100 = V_101 | V_175 ;
V_206 -> V_89 . V_102 = F_133 ;
V_206 -> V_89 . V_176 = F_132 ;
V_57 = F_54 ( & V_94 -> V_8 , & V_206 -> V_89 ) ;
if ( V_57 ) {
F_47 ( V_206 ) ;
V_206 = NULL ;
}
return V_57 ;
}
static void F_90 ( struct V_93 * V_94 )
{
if ( V_206 ) {
F_56 ( & V_94 -> V_8 , & V_206 -> V_89 ) ;
F_47 ( V_206 ) ;
V_206 = NULL ;
}
}
static void F_134 ( int V_65 ,
struct V_120 * V_118 )
{
T_3 V_104 ;
int V_32 ;
int V_208 = 0 ;
T_1 V_209 = 0xff , V_210 = 0x00 ;
unsigned char V_82 [ 32 ] = { 0 } ;
V_118 -> V_65 = V_65 ;
V_118 -> V_104 = 0 ;
V_118 -> V_211 = 0xff ;
V_104 = F_57 ( V_65 ) ;
V_32 = F_48 ( V_97 , L_55 , & V_104 , V_82 ,
32 ) ;
if ( V_32 < 0 )
return;
switch ( V_65 ) {
case 0x012f :
case 0x0137 :
V_208 = 9 ;
break;
case 0x143 :
case 0x14b :
case 0x14c :
V_208 = 16 ;
break;
}
for ( V_32 = 0 ; V_32 < V_208 && V_32 < F_12 ( V_82 ) ; V_32 ++ ) {
F_13 ( L_80 , V_82 [ V_32 ] ) ;
if ( ! V_82 [ V_32 ] )
break;
if ( V_82 [ V_32 ] > V_210 )
V_210 = V_82 [ V_32 ] ;
if ( V_82 [ V_32 ] < V_209 )
V_209 = V_82 [ V_32 ] ;
}
V_118 -> V_104 = V_209 ;
V_118 -> V_211 = V_210 ;
F_13 ( L_81 , V_118 -> V_104 ,
V_118 -> V_211 ) ;
}
static void F_135 ( void )
{
T_2 V_1 ;
int V_212 = 0 ;
const struct V_213 * V_214 = NULL ;
struct V_215 V_118 ;
if ( F_57 ( 0x12f ) >= 0 ) {
V_214 = & V_216 ;
V_217 . V_122 = 0x0100 ;
F_134 ( 0x12f , & V_217 ) ;
V_212 = V_217 . V_211 - V_217 . V_104 ;
} else if ( F_57 ( 0x137 ) >= 0 ) {
V_214 = & V_216 ;
V_217 . V_122 = 0x0100 ;
F_134 ( 0x137 , & V_217 ) ;
V_212 = V_217 . V_211 - V_217 . V_104 ;
} else if ( F_57 ( 0x143 ) >= 0 ) {
V_214 = & V_216 ;
V_217 . V_122 = 0x3000 ;
F_134 ( 0x143 , & V_217 ) ;
V_212 = V_217 . V_211 - V_217 . V_104 ;
} else if ( F_57 ( 0x14b ) >= 0 ) {
V_214 = & V_216 ;
V_217 . V_122 = 0x3000 ;
F_134 ( 0x14b , & V_217 ) ;
V_212 = V_217 . V_211 - V_217 . V_104 ;
} else if ( F_57 ( 0x14c ) >= 0 ) {
V_214 = & V_216 ;
V_217 . V_122 = 0x3000 ;
F_134 ( 0x14c , & V_217 ) ;
V_212 = V_217 . V_211 - V_217 . V_104 ;
} else if ( F_78 ( F_102 ( V_97 , L_23 ,
& V_1 ) ) ) {
V_214 = & V_218 ;
V_212 = V_108 - 1 ;
} else
return;
memset ( & V_118 , 0 , sizeof( struct V_215 ) ) ;
V_118 . type = V_219 ;
V_118 . V_212 = V_212 ;
V_217 . V_8 = F_136 ( L_82 , NULL ,
& V_217 ,
V_214 , & V_118 ) ;
if ( F_137 ( V_217 . V_8 ) ) {
F_46 ( L_83 ) ;
V_217 . V_8 = NULL ;
} else
V_217 . V_8 -> V_118 . V_119 =
V_214 -> V_220 ( V_217 . V_8 ) ;
}
static void F_138 ( void )
{
if ( V_217 . V_8 )
F_139 ( V_217 . V_8 ) ;
}
static int F_140 ( struct V_31 * V_87 )
{
T_4 V_72 ;
int V_68 = 0 ;
T_2 V_65 ;
struct V_109 * V_110 ;
F_71 ( L_84 , V_221 , V_222 ) ;
V_133 = V_87 ;
strcpy ( F_141 ( V_87 ) , L_85 ) ;
V_97 = V_87 -> V_65 ;
V_68 = F_142 ( V_87 ) ;
if ( ! V_68 && ! V_87 -> V_72 . V_223 ) {
F_13 ( L_86 ) ;
V_68 = - V_224 ;
goto V_225;
}
V_68 = F_34 () ;
if ( V_68 )
goto V_226;
if ( V_98 ) {
V_72 = F_143 ( V_227 ,
V_97 , 1 , F_77 ,
NULL , NULL , NULL ) ;
if ( F_44 ( V_72 ) ) {
F_46 ( L_87 ) ;
V_68 = - V_224 ;
goto V_226;
}
}
V_68 = F_16 ( V_87 ) ;
if ( V_68 ) {
F_20 ( L_88 ) ;
goto V_228;
}
if ( F_78 ( F_102 ( V_97 , L_49 ,
& V_65 ) ) ) {
int V_96 = 1 ;
if ( F_45 ( V_97 , L_49 , & V_96 , NULL ) )
F_13 ( L_50 ) ;
}
if ( F_78 ( F_102 ( V_97 , L_14 ,
& V_65 ) ) ) {
F_13 ( L_89 ) ;
V_68 = F_51 ( V_61 ) ;
if ( ! V_68 )
F_80 ( V_87 , V_61 ) ;
}
if ( F_144 () ) {
F_71 ( L_90 ) ;
} else {
F_135 () ;
}
for ( V_110 = V_145 ; V_110 -> V_39 ; ++ V_110 ) {
if ( ! V_98 && V_110 -> V_98 )
continue;
for (; V_110 -> V_111 && * V_110 -> V_111 ; ++ V_110 -> V_111 ) {
if ( F_78 ( F_102 ( V_97 ,
* V_110 -> V_111 ,
& V_65 ) ) ) {
F_13 ( L_91 ,
V_110 -> V_39 , * V_110 -> V_111 ) ;
V_110 -> V_99 . V_89 . V_100 |= V_101 ;
break;
}
}
for (; V_110 -> V_114 && * V_110 -> V_114 ; ++ V_110 -> V_114 ) {
if ( F_78 ( F_102 ( V_97 ,
* V_110 -> V_114 ,
& V_65 ) ) ) {
F_13 ( L_92 ,
V_110 -> V_39 , * V_110 -> V_114 ) ;
V_110 -> V_99 . V_89 . V_100 |= V_175 ;
break;
}
}
if ( V_110 -> V_99 . V_89 . V_100 != 0 ) {
V_68 =
F_54 ( & V_61 -> V_8 ,
& V_110 -> V_99 ) ;
if ( V_68 )
goto V_229;
}
}
return 0 ;
V_229:
for ( V_110 = V_145 ; V_110 -> V_39 ; ++ V_110 ) {
F_56 ( & V_61 -> V_8 , & V_110 -> V_99 ) ;
}
F_138 () ;
F_89 ( V_61 ) ;
F_55 ( V_61 ) ;
V_228:
F_31 () ;
V_226:
F_40 () ;
V_225:
F_96 () ;
return V_68 ;
}
static int F_145 ( struct V_31 * V_87 )
{
struct V_109 * V_110 ;
F_138 () ;
V_133 = NULL ;
for ( V_110 = V_145 ; V_110 -> V_39 ; ++ V_110 ) {
F_56 ( & V_61 -> V_8 , & V_110 -> V_99 ) ;
}
F_89 ( V_61 ) ;
F_55 ( V_61 ) ;
F_40 () ;
F_31 () ;
F_13 ( V_221 L_93 ) ;
return 0 ;
}
static T_1 F_146 ( T_1 V_8 )
{
T_1 V_230 , V_231 ;
F_147 ( F_148 ( V_232 . V_233 -> V_234 . V_235 + 4 ) & 2 ,
V_236 ) ;
F_149 ( V_8 , V_232 . V_233 -> V_234 . V_235 + 4 ) ;
V_230 = F_148 ( V_232 . V_233 -> V_234 . V_235 + 4 ) ;
V_231 = F_148 ( V_232 . V_233 -> V_234 . V_235 ) ;
F_13 ( L_94 , V_8 , ( V_231 << 8 ) | V_230 ) ;
return V_231 ;
}
static T_1 F_150 ( T_1 V_8 , T_1 V_237 )
{
T_1 V_230 ;
F_147 ( F_148 ( V_232 . V_233 -> V_234 . V_235 + 4 ) & 2 ,
V_236 ) ;
F_149 ( V_8 , V_232 . V_233 -> V_234 . V_235 + 4 ) ;
F_147 ( F_148 ( V_232 . V_233 -> V_234 . V_235 + 4 ) & 2 ,
V_236 ) ;
F_149 ( V_237 , V_232 . V_233 -> V_234 . V_235 ) ;
V_230 = F_148 ( V_232 . V_233 -> V_234 . V_235 ) ;
F_13 ( L_95 , V_8 , V_237 , V_230 ) ;
return V_230 ;
}
static T_1 F_151 ( T_1 V_8 , T_1 V_237 , T_1 V_80 )
{
T_1 V_230 ;
F_147 ( F_148 ( V_232 . V_233 -> V_234 . V_235 + 4 ) & 2 , V_236 ) ;
F_149 ( V_8 , V_232 . V_233 -> V_234 . V_235 + 4 ) ;
F_147 ( F_148 ( V_232 . V_233 -> V_234 . V_235 + 4 ) & 2 , V_236 ) ;
F_149 ( V_237 , V_232 . V_233 -> V_234 . V_235 ) ;
F_147 ( F_148 ( V_232 . V_233 -> V_234 . V_235 + 4 ) & 2 , V_236 ) ;
F_149 ( V_80 , V_232 . V_233 -> V_234 . V_235 ) ;
V_230 = F_148 ( V_232 . V_233 -> V_234 . V_235 ) ;
F_13 ( L_96 ,
V_8 , V_237 , V_80 , V_230 ) ;
return V_230 ;
}
static int F_152 ( const T_1 V_238 , const T_1 V_239 )
{
if ( V_238 == 0x31 ) {
if ( V_239 == 0x5c || V_239 == 0x5f )
F_146 ( 0xA0 ) ;
else if ( V_239 == 0x61 )
F_146 ( 0xB3 ) ;
return 0 ;
}
return 1 ;
}
static void F_153 ( struct V_240 * V_8 )
{
struct V_241 * V_242 ;
V_242 = F_154 ( V_243 ,
V_244 , NULL ) ;
if ( V_242 ) {
V_8 -> V_245 = V_246 ;
V_8 -> V_247 = V_248 ;
V_8 -> V_249 = V_250 ;
goto V_60;
}
V_242 = F_154 ( V_243 ,
V_251 , NULL ) ;
if ( V_242 ) {
V_8 -> V_245 = V_252 ;
V_8 -> V_247 = V_253 ;
V_8 -> V_249 = V_254 ;
goto V_60;
}
V_242 = F_154 ( V_243 ,
V_255 , NULL ) ;
if ( V_242 ) {
V_8 -> V_245 = V_256 ;
V_8 -> V_257 = F_152 ;
V_8 -> V_247 = V_258 ;
V_8 -> V_249 = V_259 ;
goto V_60;
}
V_242 = F_154 ( V_243 ,
V_260 , NULL ) ;
if ( V_242 ) {
V_8 -> V_245 = V_256 ;
V_8 -> V_257 = F_152 ;
V_8 -> V_247 = V_258 ;
V_8 -> V_249 = V_259 ;
goto V_60;
}
V_242 = F_154 ( V_243 ,
V_261 , NULL ) ;
if ( V_242 ) {
V_8 -> V_245 = V_256 ;
V_8 -> V_257 = F_152 ;
V_8 -> V_247 = V_258 ;
V_8 -> V_249 = V_259 ;
goto V_60;
}
V_8 -> V_245 = V_252 ;
V_8 -> V_247 = V_253 ;
V_8 -> V_249 = V_254 ;
V_60:
if ( V_242 )
F_155 ( V_242 ) ;
F_71 ( L_97 ,
V_8 -> V_245 == V_246 ? 1 :
V_8 -> V_245 == V_252 ? 2 : 3 ) ;
}
static int F_156 ( void )
{
T_1 V_80 ;
V_80 = F_150 ( 0x8f , V_262 ) ;
return ( V_80 != 0xff && ( V_80 & V_263 ) ) ;
}
static int F_157 ( void )
{
if ( ! V_264 ) {
F_46 ( L_98 ) ;
return - V_224 ;
}
F_147 ( F_151 ( 0x90 , V_265 ,
V_266 ) ,
V_267 ) ;
if ( V_232 . V_268 ) {
F_150 ( 0x91 , 0 ) ;
V_232 . V_268 = 0 ;
}
return 0 ;
}
static int F_158 ( void )
{
int V_32 , V_269 , V_270 ;
if ( ! V_264 ) {
F_46 ( L_98 ) ;
return - V_224 ;
}
if ( V_232 . V_268 )
return 0 ;
for ( V_269 = 5 ; V_269 > 0 ; V_269 -- ) {
for ( V_270 = 0 ; V_270 < 100 && F_150 ( 0x91 , 0x1 ) ; V_270 ++ )
F_159 ( 10 ) ;
F_146 ( 0x93 ) ;
for ( V_32 = 400 ; V_32 > 0 ; V_32 -- ) {
if ( F_156 () )
break;
F_159 ( 10 ) ;
}
if ( V_32 )
break;
}
if ( V_269 == 0 ) {
F_46 ( L_99 ) ;
return - V_224 ;
}
F_147 ( F_151 ( 0x90 , V_271 ,
0x5a ) ,
V_267 ) ;
V_232 . V_268 = 1 ;
return 0 ;
}
int F_160 ( int V_272 , T_1 V_67 )
{
if ( ! V_264 )
return - V_112 ;
F_161 ( & V_232 . V_273 ) ;
switch ( V_272 ) {
case V_274 :
if ( V_67 )
F_158 () ;
else
F_157 () ;
break;
case V_275 :
F_147 ( F_151 ( 0x90 , V_276 , V_67 ) ,
V_267 ) ;
break;
case V_277 :
F_147 ( F_151 ( 0x90 , V_278 , V_67 ) ,
V_267 ) ;
break;
case V_279 :
F_147 ( F_151 ( 0x90 , V_280 , V_67 ) ,
V_267 ) ;
break;
case V_281 :
F_147 ( F_151 ( 0x90 , V_282 , V_67 ) ,
V_267 ) ;
break;
case V_283 :
F_147 ( F_151 ( 0x90 , V_284 , V_67 ) ,
V_267 ) ;
break;
case V_285 :
F_147 ( F_151 ( 0x90 , V_265 , V_67 ) ,
V_267 ) ;
break;
case V_286 :
F_147 ( F_151 ( 0x90 , V_287 , V_67 ) ,
V_267 ) ;
break;
default:
F_20 ( L_100 , V_272 ) ;
break;
}
F_162 ( & V_232 . V_273 ) ;
return 0 ;
}
static void F_163 ( T_1 V_288 )
{
V_288 = ! ! V_288 ;
if ( V_232 . V_289 == V_288 )
return;
F_150 ( 0xB0 , V_288 ) ;
F_146 ( 0x82 ) ;
V_232 . V_289 = V_288 ;
}
static T_6 F_164 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_114 ( V_82 , 10 , & V_67 ) )
return - V_81 ;
F_161 ( & V_232 . V_273 ) ;
F_163 ( V_67 ) ;
F_162 ( & V_232 . V_273 ) ;
return V_77 ;
}
static T_6 F_165 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
T_6 V_77 ;
F_161 ( & V_232 . V_273 ) ;
V_77 = snprintf ( V_82 , V_92 , L_21 , V_232 . V_289 ) ;
F_162 ( & V_232 . V_273 ) ;
return V_77 ;
}
static void F_166 ( T_1 V_288 )
{
V_288 = ! ! V_288 ;
if ( V_232 . V_290 == V_288 )
return;
F_150 ( 0x96 , V_288 ) ;
F_146 ( 0x82 ) ;
V_232 . V_290 = V_288 ;
}
static T_6 F_167 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_114 ( V_82 , 10 , & V_67 ) )
return - V_81 ;
F_161 ( & V_232 . V_273 ) ;
F_166 ( V_67 ) ;
F_162 ( & V_232 . V_273 ) ;
return V_77 ;
}
static T_6 F_168 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
T_6 V_77 = 0 ;
F_161 ( & V_232 . V_273 ) ;
V_77 = snprintf ( V_82 , V_92 , L_21 , V_232 . V_290 ) ;
F_162 ( & V_232 . V_273 ) ;
return V_77 ;
}
static int F_169 ( unsigned long V_67 )
{
return F_170 ( V_291 , V_67 ) ;
}
static int F_171 ( T_1 * V_67 )
{
return F_172 ( V_291 , V_67 ) ;
}
static T_6 F_173 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_114 ( V_82 , 10 , & V_67 ) )
return - V_81 ;
if ( F_169 ( V_67 ) )
return - V_112 ;
return V_77 ;
}
static T_6 F_174 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
T_1 V_67 = 0 ;
if ( F_171 ( & V_67 ) )
return - V_112 ;
return snprintf ( V_82 , V_92 , L_21 , V_67 ) ;
}
static int F_175 ( int V_292 , struct V_293 * V_294 , int V_295 )
{
return F_176 ( V_292 , V_294 , V_295 , & V_296 . V_297 ) ;
}
static int F_177 ( struct V_298 * V_298 , struct V_293 * V_293 )
{
F_30 ( & V_296 . V_299 ) ;
return 0 ;
}
static int F_178 ( struct V_298 * V_298 , struct V_293 * V_293 )
{
unsigned long V_4 ;
F_2 ( & V_296 . V_6 , V_4 ) ;
if ( F_179 ( & V_296 . V_299 ) == 1 )
F_180 ( & V_296 . V_7 ) ;
F_9 ( & V_296 . V_6 , V_4 ) ;
return 0 ;
}
static T_6 F_181 ( struct V_293 * V_293 , char T_8 * V_300 ,
T_5 V_77 , T_9 * V_196 )
{
T_6 V_57 ;
unsigned char V_301 ;
if ( ( F_6 ( & V_296 . V_7 ) == 0 ) &&
( V_293 -> V_302 & V_303 ) )
return - V_304 ;
V_57 = F_182 ( V_296 . V_305 ,
F_6 ( & V_296 . V_7 ) != 0 ) ;
if ( V_57 )
return V_57 ;
while ( V_57 < V_77 &&
( F_183 ( & V_296 . V_7 , & V_301 , sizeof( V_301 ) ,
& V_296 . V_6 ) == sizeof( V_301 ) ) ) {
if ( F_184 ( V_301 , V_300 ++ ) )
return - V_306 ;
V_57 ++ ;
}
if ( V_57 > 0 ) {
struct V_298 * V_298 = F_185 ( V_293 ) ;
V_298 -> V_307 = F_186 ( V_298 -> V_308 ) ;
}
return V_57 ;
}
static unsigned int F_187 ( struct V_293 * V_293 , T_10 * V_309 )
{
F_188 ( V_293 , & V_296 . V_305 , V_309 ) ;
if ( F_6 ( & V_296 . V_7 ) )
return V_310 | V_311 ;
return 0 ;
}
static int F_189 ( T_1 V_312 , T_11 * V_67 )
{
T_1 V_313 , V_314 ;
if ( F_172 ( V_312 , & V_313 ) )
return - 1 ;
if ( F_172 ( V_312 + 1 , & V_314 ) )
return - 1 ;
* V_67 = V_313 | ( V_314 << 8 ) ;
return 0 ;
}
static long F_190 ( struct V_293 * V_315 , unsigned int V_181 ,
unsigned long V_96 )
{
int V_57 = 0 ;
void T_8 * V_316 = ( void T_8 * ) V_96 ;
T_1 V_317 ;
T_11 V_318 ;
int V_67 ;
F_161 ( & V_232 . V_273 ) ;
switch ( V_181 ) {
case V_319 :
if ( V_217 . V_8 == NULL ) {
V_57 = - V_112 ;
break;
}
if ( F_45 ( V_97 , L_23 , NULL ,
& V_67 ) ) {
V_57 = - V_112 ;
break;
}
V_317 = ( ( V_67 & 0xff ) - 1 ) << 5 ;
if ( F_191 ( V_316 , & V_317 , sizeof( V_317 ) ) )
V_57 = - V_306 ;
break;
case V_320 :
if ( V_217 . V_8 == NULL ) {
V_57 = - V_112 ;
break;
}
if ( F_192 ( & V_317 , V_316 , sizeof( V_317 ) ) ) {
V_57 = - V_306 ;
break;
}
V_67 = ( V_317 >> 5 ) + 1 ;
if ( F_45 ( V_97 , L_22 , & V_67 ,
NULL ) ) {
V_57 = - V_112 ;
break;
}
V_217 . V_8 -> V_118 . V_119 =
F_66 ( V_217 . V_8 ) ;
break;
case V_321 :
if ( F_189 ( V_322 , & V_318 ) ) {
V_57 = - V_112 ;
break;
}
if ( F_191 ( V_316 , & V_318 , sizeof( V_318 ) ) )
V_57 = - V_306 ;
break;
case V_323 :
if ( F_189 ( V_324 , & V_318 ) ) {
V_57 = - V_112 ;
break;
}
if ( F_191 ( V_316 , & V_318 , sizeof( V_318 ) ) )
V_57 = - V_306 ;
break;
case V_325 :
if ( F_189 ( V_326 , & V_318 ) ) {
V_57 = - V_112 ;
break;
}
if ( F_191 ( V_316 , & V_318 , sizeof( V_318 ) ) )
V_57 = - V_306 ;
break;
case V_327 :
if ( F_189 ( V_328 , & V_318 ) ) {
V_57 = - V_112 ;
break;
}
if ( F_191 ( V_316 , & V_318 , sizeof( V_318 ) ) )
V_57 = - V_306 ;
break;
case V_329 :
if ( F_172 ( V_330 , & V_317 ) ) {
V_57 = - V_112 ;
break;
}
V_317 &= 0x07 ;
if ( F_191 ( V_316 , & V_317 , sizeof( V_317 ) ) )
V_57 = - V_306 ;
break;
case V_331 :
V_317 = V_232 . V_290 ;
if ( F_191 ( V_316 , & V_317 , sizeof( V_317 ) ) )
V_57 = - V_306 ;
break;
case V_332 :
if ( F_192 ( & V_317 , V_316 , sizeof( V_317 ) ) ) {
V_57 = - V_306 ;
break;
}
F_166 ( V_317 ) ;
break;
case V_333 :
if ( F_171 ( & V_317 ) ) {
V_57 = - V_112 ;
break;
}
if ( F_191 ( V_316 , & V_317 , sizeof( V_317 ) ) )
V_57 = - V_306 ;
break;
case V_334 :
if ( F_192 ( & V_317 , V_316 , sizeof( V_317 ) ) ) {
V_57 = - V_306 ;
break;
}
if ( F_169 ( V_317 ) )
V_57 = - V_112 ;
break;
case V_335 :
if ( F_172 ( V_336 , & V_317 ) ) {
V_57 = - V_112 ;
break;
}
if ( F_191 ( V_316 , & V_317 , sizeof( V_317 ) ) )
V_57 = - V_306 ;
break;
default:
V_57 = - V_81 ;
}
F_162 ( & V_232 . V_273 ) ;
return V_57 ;
}
static void F_193 ( T_1 V_12 )
{
F_15 ( & V_296 . V_7 , ( unsigned char * ) & V_12 ,
sizeof( V_12 ) , & V_296 . V_6 ) ;
F_194 ( & V_296 . V_297 , V_337 , V_338 ) ;
F_195 ( & V_296 . V_305 ) ;
}
static int F_196 ( void )
{
int error ;
F_18 ( & V_296 . V_6 ) ;
error =
F_19 ( & V_296 . V_7 , V_34 , V_35 ) ;
if ( error ) {
F_20 ( L_3 ) ;
return error ;
}
F_197 ( & V_296 . V_305 ) ;
if ( V_339 != - 1 )
V_340 . V_339 = V_339 ;
error = F_198 ( & V_340 ) ;
if ( error ) {
F_20 ( L_101 ) ;
goto V_38;
}
if ( V_339 == - 1 )
F_71 ( L_102 ,
V_340 . V_339 ) ;
return 0 ;
V_38:
F_29 ( & V_296 . V_7 ) ;
return error ;
}
static void F_199 ( void )
{
F_200 ( & V_340 ) ;
F_29 ( & V_296 . V_7 ) ;
}
static int F_196 ( void ) { return 0 ; }
static void F_199 ( void ) { }
static void F_193 ( T_1 V_12 ) { }
static T_4
F_201 ( struct V_341 * V_342 , void * V_137 )
{
T_7 V_32 ;
struct V_240 * V_8 = (struct V_240 * ) V_137 ;
switch ( V_342 -> type ) {
case V_343 :
{
struct V_344 * V_345 = F_52 ( sizeof( * V_345 ) , V_35 ) ;
if ( ! V_345 )
return V_346 ;
F_202 ( & V_345 -> V_347 , & V_8 -> V_348 ) ;
return V_142 ;
}
case V_349 :
return V_142 ;
case V_350 :
{
struct V_351 * V_352 = & V_342 -> V_127 . V_353 ;
struct V_354 * V_355 = NULL ;
if ( ! V_352 || ! V_352 -> V_356 ) {
F_13 ( L_103 ) ;
return V_142 ;
}
for ( V_32 = 0 ; V_32 < V_352 -> V_356 ; V_32 ++ ) {
if ( ! V_352 -> V_357 [ V_32 ] ) {
F_46 ( L_104 ,
V_352 -> V_357 [ V_32 ] ) ;
continue;
}
V_355 = F_52 ( sizeof( * V_355 ) ,
V_35 ) ;
if ( ! V_355 )
return V_346 ;
F_202 ( & V_355 -> V_347 , & V_8 -> V_357 ) ;
V_355 -> V_353 . V_358 = V_352 -> V_358 ;
V_355 -> V_353 . V_359 = V_352 -> V_359 ;
V_355 -> V_353 . V_360 = V_352 -> V_360 ;
V_355 -> V_353 . V_356 = 1 ;
V_355 -> V_353 . V_357 [ 0 ] = V_352 -> V_357 [ V_32 ] ;
}
return V_142 ;
}
case V_361 :
{
struct V_362 * V_363 = & V_342 -> V_127 . V_363 ;
struct V_344 * V_345 =
F_203 ( & V_8 -> V_348 , struct V_344 , V_347 ) ;
if ( ! V_363 ) {
F_13 ( L_105 ) ;
return V_142 ;
}
if ( ! V_345 -> V_234 . V_235 ) {
memcpy ( & V_345 -> V_234 , V_363 , sizeof( * V_363 ) ) ;
F_13 ( L_106 , V_345 -> V_234 . V_235 ,
V_345 -> V_234 . V_364 ) ;
}
else if ( ! V_345 -> V_365 . V_235 ) {
memcpy ( & V_345 -> V_365 , V_363 , sizeof( * V_363 ) ) ;
F_13 ( L_107 , V_345 -> V_365 . V_235 ,
V_345 -> V_365 . V_364 ) ;
}
else {
F_20 ( L_108 ) ;
return V_346 ;
}
return V_142 ;
}
default:
F_13 ( L_109 ,
V_342 -> type ) ;
case V_366 :
return V_142 ;
}
return V_367 ;
}
static int F_204 ( struct V_31 * V_87 )
{
int V_68 = 0 ;
T_4 V_72 = V_142 ;
if ( ! V_87 )
return - V_81 ;
F_13 ( L_110 ) ;
V_68 = F_142 ( V_87 ) ;
if ( V_68 ) {
F_46 ( L_111 ) ;
goto V_368;
}
if ( ! V_87 -> V_72 . V_369 )
F_13 ( L_112 ) ;
else
F_13 ( L_113 ) ;
F_13 ( L_114 , V_370 ) ;
V_72 = F_205 ( V_87 -> V_65 , V_370 ,
F_201 , & V_232 ) ;
if ( F_44 ( V_72 ) ) {
F_46 ( L_115 , V_370 ) ;
V_68 = - V_224 ;
}
V_368:
return V_68 ;
}
static int F_206 ( struct V_31 * V_87 )
{
T_4 V_57 = F_43 ( V_87 -> V_65 , L_116 , NULL ,
NULL ) ;
if ( F_44 ( V_57 ) && V_57 != V_371 )
return - V_372 ;
F_13 ( L_112 ) ;
return 0 ;
}
static int F_207 ( struct V_31 * V_87 ,
struct V_344 * V_345 , struct V_354 * V_353 )
{
T_4 V_72 ;
int V_68 = 0 ;
struct {
struct V_341 V_373 ;
struct V_341 V_374 ;
struct V_341 V_375 ;
struct V_341 V_376 ;
} * V_342 ;
struct V_69 V_82 = { 0 , NULL } ;
if ( ! V_345 || ! V_353 )
return - V_81 ;
V_342 = F_52 ( sizeof( * V_342 ) + 1 , V_35 ) ;
if ( ! V_342 )
return - V_37 ;
V_82 . V_86 = sizeof( * V_342 ) + 1 ;
V_82 . V_78 = V_342 ;
if ( V_232 . V_245 == V_246 ) {
V_342 -> V_373 . type = V_361 ;
V_342 -> V_373 . V_86 = sizeof( struct V_341 ) ;
memcpy ( & V_342 -> V_373 . V_127 . V_363 , & V_345 -> V_234 ,
sizeof( struct V_362 ) ) ;
V_342 -> V_374 . type = V_361 ;
V_342 -> V_374 . V_86 = sizeof( struct V_341 ) ;
memcpy ( & V_342 -> V_374 . V_127 . V_363 , & V_345 -> V_365 ,
sizeof( struct V_362 ) ) ;
V_342 -> V_375 . type = V_350 ;
V_342 -> V_375 . V_86 = sizeof( struct V_341 ) ;
memcpy ( & V_342 -> V_375 . V_127 . V_353 , & V_353 -> V_353 ,
sizeof( struct V_351 ) ) ;
V_342 -> V_375 . V_127 . V_353 . V_360 = V_377 ;
V_342 -> V_376 . type = V_366 ;
V_342 -> V_376 . V_86 = sizeof( struct V_341 ) ;
}
else {
V_342 -> V_373 . type = V_361 ;
V_342 -> V_373 . V_86 = sizeof( struct V_341 ) ;
memcpy ( & V_342 -> V_373 . V_127 . V_363 , & V_345 -> V_234 ,
sizeof( struct V_362 ) ) ;
V_342 -> V_374 . type = V_350 ;
V_342 -> V_374 . V_86 = sizeof( struct V_341 ) ;
memcpy ( & V_342 -> V_374 . V_127 . V_353 , & V_353 -> V_353 ,
sizeof( struct V_351 ) ) ;
V_342 -> V_374 . V_127 . V_353 . V_360 = V_377 ;
V_342 -> V_375 . type = V_366 ;
V_342 -> V_375 . V_86 = sizeof( struct V_341 ) ;
}
F_13 ( L_117 ) ;
V_72 = F_208 ( V_87 -> V_65 , & V_82 ) ;
if ( F_44 ( V_72 ) ) {
F_20 ( L_118 ) ;
V_68 = - V_224 ;
goto V_368;
}
F_146 ( 0x82 ) ;
F_150 ( 0x81 , 0xff ) ;
F_146 ( V_378 ? 0x92 : 0x82 ) ;
V_368:
F_47 ( V_342 ) ;
return V_68 ;
}
static T_12 V_354 ( int V_353 , void * V_379 )
{
int V_32 , V_269 ;
T_1 V_239 = 0 ;
T_1 V_238 = 0 ;
T_1 V_380 = 0 ;
struct V_240 * V_8 = (struct V_240 * ) V_379 ;
V_239 = F_148 ( V_8 -> V_233 -> V_234 . V_235 ) ;
if ( V_8 -> V_233 -> V_365 . V_235 )
V_238 = F_148 ( V_8 -> V_233 -> V_365 . V_235 ) ;
else
V_238 = F_148 ( V_8 -> V_233 -> V_234 . V_235 +
V_8 -> V_247 ) ;
F_13 ( L_119 ,
V_239 , V_238 , V_8 -> V_233 -> V_234 . V_235 ,
V_8 -> V_247 ) ;
if ( V_239 == 0x00 || V_239 == 0xff )
return V_381 ;
for ( V_32 = 0 ; V_8 -> V_249 [ V_32 ] . V_382 ; V_32 ++ ) {
if ( ( V_238 & V_8 -> V_249 [ V_32 ] . V_127 ) !=
V_8 -> V_249 [ V_32 ] . V_127 )
continue;
if ( ! ( V_382 & V_8 -> V_249 [ V_32 ] . V_382 ) )
continue;
for ( V_269 = 0 ; V_8 -> V_249 [ V_32 ] . V_383 [ V_269 ] . V_12 ; V_269 ++ ) {
if ( V_239 == V_8 -> V_249 [ V_32 ] . V_383 [ V_269 ] . V_127 ) {
V_380 =
V_8 -> V_249 [ V_32 ] . V_383 [ V_269 ] . V_12 ;
if ( ! V_380 )
return V_381 ;
goto V_384;
}
}
}
if ( V_8 -> V_257 && V_8 -> V_257 ( V_238 , V_239 ) == 0 )
return V_381 ;
F_13 ( L_120 ,
V_239 , V_238 , V_8 -> V_233 -> V_234 . V_235 ,
V_8 -> V_247 ) ;
return V_381 ;
V_384:
F_10 ( V_380 ) ;
F_193 ( V_380 ) ;
return V_381 ;
}
static int F_209 ( struct V_31 * V_87 )
{
struct V_344 * V_363 , * V_385 ;
struct V_354 * V_353 , * V_386 ;
if ( F_206 ( V_87 ) ) {
F_20 ( L_121 ) ;
return - V_372 ;
}
F_210 ( V_232 . V_387 -> V_353 . V_357 [ 0 ] , & V_232 ) ;
F_211 ( V_232 . V_233 -> V_234 . V_235 ,
V_232 . V_233 -> V_234 . V_364 ) ;
if ( V_232 . V_233 -> V_365 . V_235 )
F_211 ( V_232 . V_233 -> V_365 . V_235 ,
V_232 . V_233 -> V_365 . V_364 ) ;
F_199 () ;
F_31 () ;
F_212 ( & V_61 -> V_8 . V_388 , & V_389 ) ;
F_40 () ;
F_213 (io, tmp_io, &spic_dev.ioports, list) {
F_214 ( & V_363 -> V_347 ) ;
F_47 ( V_363 ) ;
}
F_213 (irq, tmp_irq, &spic_dev.interrupts, list) {
F_214 ( & V_353 -> V_347 ) ;
F_47 ( V_353 ) ;
}
V_232 . V_233 = NULL ;
V_232 . V_387 = NULL ;
F_13 ( V_390 L_93 ) ;
return 0 ;
}
static int F_215 ( struct V_31 * V_87 )
{
int V_68 ;
struct V_344 * V_363 , * V_385 ;
struct V_354 * V_353 , * V_386 ;
F_71 ( L_84 , V_390 , V_222 ) ;
V_232 . V_391 = V_87 ;
strcpy ( F_141 ( V_87 ) , L_85 ) ;
F_153 ( & V_232 ) ;
F_216 ( & V_232 . V_273 ) ;
V_68 = F_204 ( V_87 ) ;
if ( V_68 ) {
F_20 ( L_122 ) ;
goto V_392;
}
V_68 = F_16 ( V_87 ) ;
if ( V_68 ) {
F_20 ( L_88 ) ;
goto V_392;
}
V_68 = F_196 () ;
if ( V_68 )
goto V_393;
F_217 (io, &spic_dev.ioports, list) {
if ( F_218 ( V_363 -> V_234 . V_235 , V_363 -> V_234 . V_364 ,
L_123 ) ) {
F_13 ( L_124 ,
V_363 -> V_234 . V_235 , V_363 -> V_234 . V_394 ,
V_363 -> V_234 . V_364 ) ;
if ( V_363 -> V_365 . V_235 ) {
if ( F_218 ( V_363 -> V_365 . V_235 ,
V_363 -> V_365 . V_364 ,
L_123 ) ) {
F_13 ( L_125 ,
V_363 -> V_365 . V_235 , V_363 -> V_365 . V_394 ,
V_363 -> V_365 . V_364 ) ;
V_232 . V_233 = V_363 ;
break;
}
else {
F_13 ( L_126
L_127 ,
V_363 -> V_365 . V_235 , V_363 -> V_365 . V_394 ,
V_363 -> V_365 . V_364 ) ;
F_211 ( V_363 -> V_234 . V_235 ,
V_363 -> V_234 . V_364 ) ;
}
}
else {
V_232 . V_233 = V_363 ;
break;
}
}
}
if ( ! V_232 . V_233 ) {
F_20 ( L_128 ) ;
V_68 = - V_224 ;
goto V_395;
}
F_217 (irq, &spic_dev.interrupts, list) {
if ( ! F_219 ( V_353 -> V_353 . V_357 [ 0 ] , V_354 ,
0 , L_6 , & V_232 ) ) {
F_13 ( L_129
L_130 ,
V_353 -> V_353 . V_357 [ 0 ] ,
V_353 -> V_353 . V_358 ,
V_353 -> V_353 . V_359 ,
V_353 -> V_353 . V_360 ) ;
V_232 . V_387 = V_353 ;
break;
}
}
if ( ! V_232 . V_387 ) {
F_20 ( L_131 ) ;
V_68 = - V_224 ;
goto V_396;
}
V_68 = F_207 ( V_87 , V_232 . V_233 , V_232 . V_387 ) ;
if ( V_68 ) {
F_20 ( L_132 ) ;
goto V_397;
}
V_232 . V_290 = - 1 ;
V_68 = F_34 () ;
if ( V_68 )
goto V_398;
V_68 = F_220 ( & V_61 -> V_8 . V_388 , & V_389 ) ;
if ( V_68 )
goto V_399;
return 0 ;
V_399:
F_40 () ;
V_398:
F_206 ( V_87 ) ;
V_397:
F_210 ( V_232 . V_387 -> V_353 . V_357 [ 0 ] , & V_232 ) ;
V_396:
F_211 ( V_232 . V_233 -> V_234 . V_235 ,
V_232 . V_233 -> V_234 . V_364 ) ;
if ( V_232 . V_233 -> V_365 . V_235 )
F_211 ( V_232 . V_233 -> V_365 . V_235 ,
V_232 . V_233 -> V_365 . V_364 ) ;
V_395:
F_199 () ;
V_393:
F_31 () ;
V_392:
F_213 (io, tmp_io, &spic_dev.ioports, list) {
F_214 ( & V_363 -> V_347 ) ;
F_47 ( V_363 ) ;
}
F_213 (irq, tmp_irq, &spic_dev.interrupts, list) {
F_214 ( & V_353 -> V_347 ) ;
F_47 ( V_353 ) ;
}
V_232 . V_233 = NULL ;
V_232 . V_387 = NULL ;
return V_68 ;
}
static int F_221 ( struct V_87 * V_8 )
{
if ( F_206 ( F_222 ( V_8 ) ) )
return - V_372 ;
return 0 ;
}
static int F_223 ( struct V_87 * V_8 )
{
F_207 ( F_222 ( V_8 ) ,
V_232 . V_233 , V_232 . V_387 ) ;
return 0 ;
}
static int T_13 F_224 ( void )
{
int V_68 ;
if ( ! V_400 && F_225 ( V_401 ) ) {
V_68 = F_226 ( & V_402 ) ;
if ( V_68 ) {
F_20 ( L_133 ) ;
goto V_60;
}
V_403 = 1 ;
}
V_68 = F_226 ( & V_404 ) ;
if ( V_68 ) {
F_20 ( L_134 ) ;
goto V_405;
}
return 0 ;
V_405:
if ( V_403 )
F_227 ( & V_402 ) ;
V_60:
return V_68 ;
}
static void T_14 F_228 ( void )
{
F_227 ( & V_404 ) ;
if ( V_403 )
F_227 ( & V_402 ) ;
}

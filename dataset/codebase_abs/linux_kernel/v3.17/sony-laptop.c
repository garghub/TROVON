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
T_5 V_84 ;
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
case 0x015D :
V_68 = F_83 ( V_143 , V_65 ) ;
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
case 0x0121 :
V_68 = F_89 ( V_143 ) ;
if ( V_68 )
F_20 ( L_44 ,
V_68 ) ;
break;
case 0x0149 :
V_68 = F_90 ( V_143 ) ;
if ( V_68 )
F_20 ( L_45 ,
V_68 ) ;
break;
case 0x0155 :
V_68 = F_91 ( V_143 ) ;
if ( V_68 )
F_20 ( L_46 ,
V_68 ) ;
break;
case 0x011D :
V_68 = F_92 ( V_143 ) ;
if ( V_68 )
F_20 ( L_47 ,
V_68 ) ;
break;
case 0x0168 :
V_68 = F_93 ( V_143 ) ;
if ( V_68 )
F_20 ( L_48 ,
V_68 ) ;
break;
default:
continue;
}
}
V_96 = 0x10 ;
if ( ! F_45 ( V_97 , L_14 , & V_96 , & V_144 ) )
F_45 ( V_97 , L_49 , & V_144 ,
& V_68 ) ;
}
static void F_94 ( struct V_93 * V_94 )
{
unsigned int V_32 , V_68 , V_144 , V_65 ;
F_45 ( V_97 , L_50 , NULL , & V_144 ) ;
F_45 ( V_97 , L_51 , & V_144 , & V_68 ) ;
for ( V_32 = 0 ; V_32 < F_12 ( V_90 -> V_91 ) ; V_32 ++ ) {
V_65 = V_90 -> V_91 [ V_32 ] ;
if ( ! V_65 )
continue;
switch ( V_65 ) {
case 0x0105 :
case 0x0148 :
F_95 ( V_94 ) ;
break;
case 0x0115 :
case 0x0136 :
case 0x013f :
F_96 ( V_94 ) ;
break;
case 0x0119 :
case 0x015D :
F_97 ( V_94 ) ;
break;
case 0x0122 :
F_98 ( V_94 ) ;
break;
case 0x0128 :
case 0x0146 :
case 0x015B :
F_99 ( V_94 ) ;
break;
case 0x0131 :
F_100 ( V_94 ) ;
break;
case 0x0124 :
case 0x0135 :
F_101 () ;
break;
case 0x0137 :
case 0x0143 :
case 0x014b :
case 0x014c :
case 0x0163 :
F_102 ( V_94 , V_65 ) ;
break;
case 0x0121 :
F_103 ( V_94 ) ;
break;
case 0x0149 :
F_104 ( V_94 ) ;
break;
case 0x0155 :
F_105 ( V_94 ) ;
break;
case 0x011D :
F_106 ( V_94 ) ;
break;
case 0x0168 :
F_107 ( V_94 ) ;
break;
default:
continue;
}
}
F_55 ( V_94 ) ;
}
static void F_108 ( void )
{
unsigned int V_32 , V_68 , V_144 , V_96 ;
F_13 ( L_52 ) ;
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
F_109 () ;
break;
case 0x0124 :
case 0x0135 :
F_73 () ;
break;
default:
continue;
}
}
V_96 = 0x10 ;
if ( ! F_45 ( V_97 , L_14 , & V_96 , & V_144 ) )
F_45 ( V_97 , L_49 , & V_144 ,
& V_68 ) ;
}
static int F_110 ( struct V_87 * V_8 )
{
struct V_109 * V_110 ;
for ( V_110 = V_145 ; V_110 -> V_39 ; V_110 ++ ) {
int V_57 ;
if ( ! V_110 -> V_115 )
continue;
V_57 = F_45 ( V_97 , * V_110 -> V_114 ,
& V_110 -> V_67 , NULL ) ;
if ( V_57 < 0 ) {
F_20 ( L_53 , V_146 , V_57 ) ;
break;
}
}
if ( F_111 ( V_97 , L_54 ) ) {
int V_96 = 1 ;
if ( F_45 ( V_97 , L_54 , & V_96 , NULL ) )
F_13 ( L_55 ) ;
}
if ( F_111 ( V_97 , L_14 ) )
F_108 () ;
return 0 ;
}
static void F_101 ( void )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_147 ; V_32 ++ ) {
if ( V_148 [ V_32 ] ) {
F_112 ( V_148 [ V_32 ] ) ;
F_113 ( V_148 [ V_32 ] ) ;
}
}
}
static int F_114 ( void * V_127 , bool V_149 )
{
int V_68 ;
int V_103 = V_150 [ ( long ) V_127 ] + 0x100 ;
if ( ! V_149 )
V_103 |= 0x070000 ;
return F_58 ( V_151 , V_103 , & V_68 ) ;
}
static int F_115 ( struct V_31 * V_87 ,
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
V_39 = L_56 ;
break;
case V_162 :
type = V_163 ;
V_39 = L_57 ;
break;
case V_164 :
type = V_165 ;
V_39 = L_58 ;
break;
case V_166 :
type = V_167 ;
V_39 = L_59 ;
break;
default:
return - V_81 ;
}
V_156 = F_116 ( V_39 , & V_87 -> V_8 , type ,
& V_168 , ( void * ) V_153 ) ;
if ( ! V_156 )
return - V_37 ;
if ( F_58 ( V_151 , 0x200 , & V_68 ) < 0 ) {
F_113 ( V_156 ) ;
return - 1 ;
}
V_158 = ! ( V_68 & 0x1 ) ;
if ( F_58 ( V_151 ,
V_150 [ V_153 ] ,
& V_68 ) < 0 ) {
F_113 ( V_156 ) ;
return - 1 ;
}
V_159 = ! ( V_68 & 0x2 ) ;
F_117 ( V_156 , V_159 ) ;
F_118 ( V_156 , V_158 ) ;
V_154 = F_119 ( V_156 ) ;
if ( V_154 ) {
F_113 ( V_156 ) ;
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
if ( F_118 ( V_148 [ V_32 ] , true ) ) {
}
continue;
}
F_58 ( V_151 , V_103 , & V_68 ) ;
F_120 ( V_148 [ V_32 ] ,
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
V_32 = F_48 ( V_97 , L_60 , & V_104 , V_82 ,
32 ) ;
if ( V_32 < 0 )
return V_32 ;
for ( V_32 = 0 ; V_32 < F_12 ( V_82 ) ; V_32 ++ ) {
if ( V_82 [ V_32 ] == 0xff )
break;
F_13 ( L_61 , V_82 [ V_32 ] ) ;
if ( V_82 [ V_32 ] == 0 && ! V_148 [ V_160 ] )
F_115 ( V_87 , V_160 ) ;
if ( V_82 [ V_32 ] == 0x10 && ! V_148 [ V_162 ] )
F_115 ( V_87 , V_162 ) ;
if ( ( ( 0xf0 & V_82 [ V_32 ] ) == 0x20 ||
( 0xf0 & V_82 [ V_32 ] ) == 0x50 ) &&
! V_148 [ V_164 ] )
F_115 ( V_87 , V_164 ) ;
if ( V_82 [ V_32 ] == 0x30 && ! V_148 [ V_166 ] )
F_115 ( V_87 , V_166 ) ;
}
return 0 ;
}
static T_6 F_121 ( T_1 V_67 )
{
int V_68 ;
if ( V_67 > 2 )
return - V_81 ;
if ( F_58 ( V_169 -> V_65 ,
( V_67 << 0x10 ) | ( V_169 -> V_170 ) , & V_68 ) )
return - V_112 ;
if ( V_67 != 1 )
F_58 ( V_169 -> V_65 ,
( V_67 << 0x0f ) | ( V_169 -> V_170 + 0x100 ) ,
& V_68 ) ;
V_169 -> V_100 = V_67 ;
return 0 ;
}
static T_6 F_122 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
int V_57 = 0 ;
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_123 ( V_82 , 10 , & V_67 ) )
return - V_81 ;
V_57 = F_121 ( V_67 ) ;
if ( V_57 < 0 )
return V_57 ;
return V_77 ;
}
static T_6 F_124 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
T_6 V_77 = 0 ;
V_77 = snprintf ( V_82 , V_92 , L_21 , V_169 -> V_100 ) ;
return V_77 ;
}
static int F_125 ( T_1 V_67 )
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
static T_6 F_126 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
int V_57 = 0 ;
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_123 ( V_82 , 10 , & V_67 ) )
return - V_81 ;
V_57 = F_125 ( V_67 ) ;
if ( V_57 < 0 )
return V_57 ;
return V_77 ;
}
static T_6 F_127 ( struct V_87 * V_8 ,
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
if ( V_169 ) {
F_46 ( L_62 ,
V_65 , V_169 -> V_65 ) ;
return - V_172 ;
}
V_57 = F_58 ( V_65 , V_65 == 0x0137 ? 0x0B00 : 0x0100 ,
& V_68 ) ;
if ( V_57 )
return V_57 ;
if ( ( V_65 == 0x0137 && ! ( V_68 & 0x02 ) ) ||
! ( V_68 & 0x01 ) ) {
F_13 ( L_63 ) ;
return 0 ;
}
V_169 = F_52 ( sizeof( * V_169 ) , V_35 ) ;
if ( ! V_169 )
return - V_37 ;
V_169 -> V_100 = V_173 ;
V_169 -> V_171 = V_174 ;
V_169 -> V_65 = V_65 ;
if ( V_65 == 0x0137 )
V_169 -> V_170 = 0x0C00 ;
else
V_169 -> V_170 = 0x4000 ;
F_53 ( & V_169 -> V_175 . V_89 ) ;
V_169 -> V_175 . V_89 . V_39 = L_64 ;
V_169 -> V_175 . V_89 . V_100 = V_101 | V_176 ;
V_169 -> V_175 . V_102 = F_124 ;
V_169 -> V_175 . V_177 = F_122 ;
F_53 ( & V_169 -> V_178 . V_89 ) ;
V_169 -> V_178 . V_89 . V_39 = L_65 ;
V_169 -> V_178 . V_89 . V_100 = V_101 | V_176 ;
V_169 -> V_178 . V_102 = F_127 ;
V_169 -> V_178 . V_177 = F_126 ;
V_57 = F_54 ( & V_94 -> V_8 , & V_169 -> V_175 ) ;
if ( V_57 )
goto V_179;
V_57 = F_54 ( & V_94 -> V_8 , & V_169 -> V_178 ) ;
if ( V_57 )
goto V_180;
F_121 ( V_169 -> V_100 ) ;
F_125 ( V_169 -> V_171 ) ;
return 0 ;
V_180:
F_56 ( & V_94 -> V_8 , & V_169 -> V_175 ) ;
V_179:
F_47 ( V_169 ) ;
V_169 = NULL ;
return V_57 ;
}
static void F_102 ( struct V_93 * V_94 ,
unsigned int V_65 )
{
if ( V_169 && V_65 == V_169 -> V_65 ) {
F_56 ( & V_94 -> V_8 , & V_169 -> V_175 ) ;
F_56 ( & V_94 -> V_8 , & V_169 -> V_178 ) ;
F_47 ( V_169 ) ;
V_169 = NULL ;
}
}
static T_6 F_128 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
unsigned int V_68 , V_181 ;
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_123 ( V_82 , 10 , & V_67 ) )
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
static T_6 F_129 ( struct V_87 * V_8 ,
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
static T_6 F_130 ( struct V_87 * V_8 ,
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
V_182 -> V_185 [ 0 ] . V_89 . V_39 = L_66 ;
V_182 -> V_185 [ 0 ] . V_89 . V_100 = V_101 | V_176 ;
V_182 -> V_185 [ 0 ] . V_102 = F_129 ;
V_182 -> V_185 [ 0 ] . V_177 = F_128 ;
V_57 = F_54 ( & V_94 -> V_8 , & V_182 -> V_185 [ 0 ] ) ;
if ( V_57 )
goto V_179;
if ( V_65 == 0x0115 )
return 0 ;
F_53 ( & V_182 -> V_185 [ 1 ] . V_89 ) ;
V_182 -> V_185 [ 1 ] . V_89 . V_39 = L_67 ;
V_182 -> V_185 [ 1 ] . V_89 . V_100 = V_101 ;
V_182 -> V_185 [ 1 ] . V_102 = F_130 ;
V_57 = F_54 ( & V_94 -> V_8 , & V_182 -> V_185 [ 1 ] ) ;
if ( V_57 )
goto V_186;
return 0 ;
V_186:
F_56 ( & V_94 -> V_8 , & V_182 -> V_185 [ 0 ] ) ;
V_179:
F_47 ( V_182 ) ;
V_182 = NULL ;
return V_57 ;
}
static void F_96 ( struct V_93 * V_94 )
{
if ( V_182 ) {
F_56 ( & V_94 -> V_8 , & V_182 -> V_185 [ 0 ] ) ;
if ( V_182 -> V_65 != 0x0115 )
F_56 ( & V_94 -> V_8 , & V_182 -> V_185 [ 1 ] ) ;
F_47 ( V_182 ) ;
V_182 = NULL ;
}
}
static int F_131 ( unsigned short V_100 )
{
unsigned int V_68 ;
if ( ( V_100 && ! ( V_187 -> V_188 & V_100 ) ) || V_100 >= V_189 )
return - V_81 ;
if ( F_58 ( 0x0122 , V_100 << 0x10 | 0x0200 , & V_68 ) )
return - V_112 ;
V_187 -> V_100 = V_100 ;
return 0 ;
}
static int F_132 ( void )
{
unsigned int V_68 ;
if ( F_58 ( 0x0122 , 0x0100 , & V_68 ) )
return - V_112 ;
return V_68 & 0xff ;
}
static T_6 F_133 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
short V_190 ;
T_5 V_191 = 0 ;
for ( V_190 = 0 ; V_190 < V_189 ; V_190 ++ ) {
if ( ! V_190 || ( V_187 -> V_188 & V_190 ) )
V_191 += snprintf ( V_82 + V_191 , V_92 - V_191 , L_68 ,
V_192 [ V_190 ] ) ;
}
V_191 += snprintf ( V_82 + V_191 , V_92 - V_191 , L_13 ) ;
return V_191 ;
}
static T_6 F_134 ( struct V_87 * V_8 ,
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
if ( F_131 ( V_181 ) )
return - V_112 ;
return V_77 ;
}
static T_6 F_135 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
T_6 V_77 = 0 ;
int V_100 = F_132 () ;
if ( V_100 < 0 )
return V_100 ;
V_77 = snprintf ( V_82 , V_92 , L_69 , V_192 [ V_100 ] ) ;
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
F_46 ( L_70 ) ;
goto V_179;
}
V_57 = F_132 () ;
if ( V_57 < 0 ) {
F_46 ( L_71 ) ;
goto V_179;
}
V_187 -> V_100 = V_57 ;
F_53 ( & V_187 -> V_194 . V_89 ) ;
V_187 -> V_194 . V_89 . V_39 = L_72 ;
V_187 -> V_194 . V_89 . V_100 = V_101 ;
V_187 -> V_194 . V_102 = F_133 ;
F_53 ( & V_187 -> V_175 . V_89 ) ;
V_187 -> V_175 . V_89 . V_39 = L_73 ;
V_187 -> V_175 . V_89 . V_100 = V_101 | V_176 ;
V_187 -> V_175 . V_102 = F_135 ;
V_187 -> V_175 . V_177 = F_134 ;
V_57 = F_54 ( & V_94 -> V_8 , & V_187 -> V_194 ) ;
if ( V_57 )
goto V_179;
V_57 = F_54 ( & V_94 -> V_8 , & V_187 -> V_175 ) ;
if ( V_57 )
goto V_195;
return 0 ;
V_195:
F_56 ( & V_94 -> V_8 , & V_187 -> V_194 ) ;
V_179:
F_47 ( V_187 ) ;
V_187 = NULL ;
return V_57 ;
}
static void F_98 ( struct V_93 * V_94 )
{
if ( V_187 ) {
F_56 ( & V_94 -> V_8 , & V_187 -> V_194 ) ;
F_56 ( & V_94 -> V_8 , & V_187 -> V_175 ) ;
F_47 ( V_187 ) ;
V_187 = NULL ;
}
}
static void F_109 ( void )
{
unsigned int V_72 = F_132 () ;
if ( V_72 != V_187 -> V_100 )
F_131 ( V_187 -> V_100 ) ;
}
static T_6 F_136 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
unsigned int V_68 ;
unsigned long V_67 ;
unsigned int V_196 = V_197 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_123 ( V_82 , 10 , & V_67 ) || V_67 > 1 )
return - V_81 ;
while ( V_196 < V_198 ) {
if ( & V_199 -> V_185 [ V_196 ] . V_89 == & V_89 -> V_89 )
break;
V_196 ++ ;
}
if ( V_196 == V_198 )
return - V_81 ;
if ( V_67 )
V_67 = V_199 -> V_72 | ( 1 << V_196 ) ;
else
V_67 = V_199 -> V_72 & ~ ( 1 << V_196 ) ;
if ( F_58 ( V_199 -> V_65 , V_67 << 0x10 | 0x0100 ,
& V_68 ) )
return - V_112 ;
V_199 -> V_72 = V_67 ;
return V_77 ;
}
static T_6 F_137 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
char * V_82 )
{
unsigned int V_196 = V_197 ;
while ( V_196 < V_198 ) {
if ( & V_199 -> V_185 [ V_196 ] . V_89 == & V_89 -> V_89 )
return snprintf ( V_82 , V_92 , L_21 ,
( V_199 -> V_72 >> V_196 ) & 0x01 ) ;
V_196 ++ ;
}
return - V_81 ;
}
static int F_83 ( struct V_93 * V_94 ,
unsigned int V_65 )
{
unsigned int V_68 ;
int V_32 ;
if ( F_58 ( V_65 , 0x0000 , & V_68 ) )
return - V_112 ;
V_199 = F_52 ( sizeof( struct V_200 ) , V_35 ) ;
if ( ! V_199 )
return - V_37 ;
V_199 -> V_72 = V_68 & 0x7 ;
V_199 -> V_65 = V_65 ;
F_53 ( & V_199 -> V_185 [ 0 ] . V_89 ) ;
V_199 -> V_185 [ V_197 ] . V_89 . V_39 = L_74 ;
V_199 -> V_185 [ V_197 ] . V_89 . V_100 = V_101 | V_176 ;
V_199 -> V_185 [ V_197 ] . V_102 = F_137 ;
V_199 -> V_185 [ V_197 ] . V_177 = F_136 ;
if ( V_65 == 0x0119 ) {
F_53 ( & V_199 -> V_185 [ 1 ] . V_89 ) ;
V_199 -> V_185 [ V_201 ] . V_89 . V_39 = L_75 ;
V_199 -> V_185 [ V_201 ] . V_89 . V_100 = V_101 | V_176 ;
V_199 -> V_185 [ V_201 ] . V_102 = F_137 ;
V_199 -> V_185 [ V_201 ] . V_177 = F_136 ;
F_53 ( & V_199 -> V_185 [ 2 ] . V_89 ) ;
V_199 -> V_185 [ V_202 ] . V_89 . V_39 = L_76 ;
V_199 -> V_185 [ V_202 ] . V_89 . V_100 = V_101 | V_176 ;
V_199 -> V_185 [ V_202 ] . V_102 = F_137 ;
V_199 -> V_185 [ V_202 ] . V_177 = F_136 ;
}
for ( V_32 = 0 ; V_32 < V_198 &&
V_199 -> V_185 [ V_32 ] . V_89 . V_39 ; V_32 ++ ) {
V_68 = F_54 ( & V_94 -> V_8 , & V_199 -> V_185 [ V_32 ] ) ;
if ( V_68 )
goto V_203;
}
return 0 ;
V_203:
for ( V_32 -- ; V_32 >= 0 ; V_32 -- )
F_56 ( & V_94 -> V_8 , & V_199 -> V_185 [ V_32 ] ) ;
F_47 ( V_199 ) ;
V_199 = NULL ;
return V_68 ;
}
static void F_97 ( struct V_93 * V_94 )
{
int V_32 ;
if ( V_199 ) {
for ( V_32 = 0 ; V_32 < V_198 ; V_32 ++ ) {
if ( ! V_199 -> V_185 [ V_32 ] . V_89 . V_39 )
break;
F_56 ( & V_94 -> V_8 , & V_199 -> V_185 [ V_32 ] ) ;
}
F_47 ( V_199 ) ;
V_199 = NULL ;
}
}
static int F_74 ( void )
{
unsigned int V_68 ;
if ( F_58 ( V_204 -> V_65 ,
V_204 -> V_65 == 0x015B ? 0x0000 : 0x0100 ,
& V_68 ) )
return - V_112 ;
switch ( V_204 -> V_65 ) {
case 0x0146 :
return V_68 & 0x1 ? V_205 : V_206 ;
break;
case 0x015B :
return V_68 & 0x1 ? V_206 : V_205 ;
break;
case 0x0128 :
F_13 ( L_77 , V_68 ) ;
return V_68 & 0x80 ? AUTO :
V_68 & 0x02 ? V_206 : V_205 ;
break;
}
return - V_81 ;
}
static T_6 F_138 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
char * V_82 )
{
int V_196 = F_74 () ;
if ( V_196 < 0 )
return V_196 ;
return snprintf ( V_82 , V_92 , L_69 ,
V_196 == V_205 ? L_78 :
V_196 == V_206 ? L_79 :
V_196 == AUTO ? L_80 : L_81 ) ;
}
static int F_85 ( struct V_93 * V_94 ,
unsigned int V_65 )
{
unsigned int V_68 ;
V_204 = F_52 ( sizeof( struct V_207 ) , V_35 ) ;
if ( ! V_204 )
return - V_37 ;
V_204 -> V_65 = V_65 ;
F_53 ( & V_204 -> V_89 . V_89 ) ;
V_204 -> V_89 . V_89 . V_39 = L_82 ;
V_204 -> V_89 . V_89 . V_100 = V_101 ;
V_204 -> V_89 . V_102 = F_138 ;
V_68 = F_54 ( & V_94 -> V_8 , & V_204 -> V_89 ) ;
if ( V_68 )
goto V_208;
return 0 ;
V_208:
F_47 ( V_204 ) ;
V_204 = NULL ;
return V_68 ;
}
static void F_99 ( struct V_93 * V_94 )
{
if ( V_204 ) {
F_56 ( & V_94 -> V_8 , & V_204 -> V_89 ) ;
F_47 ( V_204 ) ;
V_204 = NULL ;
}
}
static T_6 F_139 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
unsigned int V_68 ;
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_123 ( V_82 , 10 , & V_67 ) || V_67 > 1 )
return - V_81 ;
if ( F_58 ( 0x0131 , V_67 << 0x10 | 0x0200 , & V_68 ) )
return - V_112 ;
return V_77 ;
}
static T_6 F_140 ( struct V_87 * V_8 ,
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
F_71 ( L_83 ) ;
return 0 ;
}
V_209 = F_52 ( sizeof( struct V_88 ) , V_35 ) ;
if ( ! V_209 )
return - V_37 ;
F_53 ( & V_209 -> V_89 ) ;
V_209 -> V_89 . V_39 = L_84 ;
V_209 -> V_89 . V_100 = V_101 | V_176 ;
V_209 -> V_102 = F_140 ;
V_209 -> V_177 = F_139 ;
V_68 = F_54 ( & V_94 -> V_8 , V_209 ) ;
if ( V_68 ) {
F_47 ( V_209 ) ;
V_209 = NULL ;
return V_68 ;
}
return 0 ;
}
static void F_100 ( struct V_93 * V_94 )
{
if ( V_209 ) {
F_56 ( & V_94 -> V_8 , V_209 ) ;
F_47 ( V_209 ) ;
V_209 = NULL ;
}
}
static T_6 F_141 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
unsigned int V_68 ;
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_123 ( V_82 , 10 , & V_67 ) || V_67 > 1 )
return - V_81 ;
if ( F_58 ( 0x0121 , V_67 << 8 , & V_68 ) )
return - V_112 ;
return V_77 ;
}
static T_6 F_142 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
unsigned int V_68 ;
if ( F_58 ( 0x0121 , 0x0200 , & V_68 ) )
return - V_112 ;
return snprintf ( V_82 , V_92 , L_21 , V_68 & 1 ) ;
}
static int F_89 ( struct V_93 * V_94 )
{
unsigned int V_68 ;
V_210 = F_52 ( sizeof( struct V_88 ) , V_35 ) ;
if ( ! V_210 )
return - V_37 ;
F_53 ( & V_210 -> V_89 ) ;
V_210 -> V_89 . V_39 = L_85 ;
V_210 -> V_89 . V_100 = V_101 | V_176 ;
V_210 -> V_102 = F_142 ;
V_210 -> V_177 = F_141 ;
V_68 = F_54 ( & V_94 -> V_8 , V_210 ) ;
if ( V_68 ) {
F_47 ( V_210 ) ;
V_210 = NULL ;
return V_68 ;
}
return 0 ;
}
static void F_103 ( struct V_93 * V_94 )
{
if ( V_210 ) {
F_56 ( & V_94 -> V_8 , V_210 ) ;
F_47 ( V_210 ) ;
V_210 = NULL ;
}
}
static T_6 F_143 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
unsigned int V_68 ;
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_123 ( V_82 , 10 , & V_67 ) || V_67 > 1 )
return - V_81 ;
if ( F_58 ( 0x0149 , V_67 << 0x10 | 0x0200 , & V_68 ) )
return - V_112 ;
return V_77 ;
}
static T_6 F_144 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
unsigned int V_68 ;
if ( F_58 ( 0x0149 , 0x0100 , & V_68 ) )
return - V_112 ;
return snprintf ( V_82 , V_92 , L_21 , V_68 & 0x01 ) ;
}
static T_6 F_145 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
unsigned int V_68 ;
if ( F_58 ( 0x0149 , 0x0300 , & V_68 ) )
return - V_112 ;
return snprintf ( V_82 , V_92 , L_21 , V_68 & 0xff ) ;
}
static int F_90 ( struct V_93 * V_94 )
{
unsigned int V_68 ;
V_211 = F_52 ( sizeof( struct V_88 ) , V_35 ) ;
if ( ! V_211 )
return - V_37 ;
V_212 = F_52 ( sizeof( struct V_88 ) , V_35 ) ;
if ( ! V_212 ) {
V_68 = - V_37 ;
goto V_213;
}
F_53 ( & V_211 -> V_89 ) ;
V_211 -> V_89 . V_39 = L_86 ;
V_211 -> V_89 . V_100 = V_101 ;
V_211 -> V_102 = F_145 ;
V_211 -> V_177 = NULL ;
F_53 ( & V_212 -> V_89 ) ;
V_212 -> V_89 . V_39 = L_87 ;
V_212 -> V_89 . V_100 = V_101 | V_176 ;
V_212 -> V_102 = F_144 ;
V_212 -> V_177 = F_143 ;
V_68 = F_54 ( & V_94 -> V_8 , V_211 ) ;
if ( V_68 )
goto V_214;
V_68 = F_54 ( & V_94 -> V_8 , V_212 ) ;
if ( V_68 )
goto V_215;
return 0 ;
V_215:
F_56 ( & V_94 -> V_8 , V_211 ) ;
V_214:
F_47 ( V_212 ) ;
V_212 = NULL ;
V_213:
F_47 ( V_211 ) ;
V_211 = NULL ;
return V_68 ;
}
static void F_104 ( struct V_93 * V_94 )
{
if ( V_211 ) {
F_56 ( & V_94 -> V_8 , V_211 ) ;
F_47 ( V_211 ) ;
V_211 = NULL ;
}
if ( V_212 ) {
F_56 ( & V_94 -> V_8 , V_212 ) ;
F_47 ( V_212 ) ;
V_212 = NULL ;
}
}
static T_6 F_146 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
unsigned int V_68 ;
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_123 ( V_82 , 10 , & V_67 ) || V_67 > 1 )
return - V_81 ;
if ( F_58 ( 0x0155 , V_67 << 0x10 | 0x0100 , & V_68 ) )
return - V_112 ;
return V_77 ;
}
static T_6 F_147 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
unsigned int V_68 ;
if ( F_58 ( 0x0155 , 0x0000 , & V_68 ) )
return - V_112 ;
return snprintf ( V_82 , V_92 , L_21 , V_68 & 0x01 ) ;
}
static int F_91 ( struct V_93 * V_94 )
{
unsigned int V_68 ;
if ( F_58 ( 0x0155 , 0x0000 , & V_68 ) || ! ( V_68 & 0x01 ) ) {
F_71 ( L_88 ) ;
return 0 ;
}
V_216 = F_52 ( sizeof( struct V_88 ) , V_35 ) ;
if ( ! V_216 )
return - V_37 ;
F_53 ( & V_216 -> V_89 ) ;
V_216 -> V_89 . V_39 = L_89 ;
V_216 -> V_89 . V_100 = V_101 | V_176 ;
V_216 -> V_102 = F_147 ;
V_216 -> V_177 = F_146 ;
V_68 = F_54 ( & V_94 -> V_8 , V_216 ) ;
if ( V_68 ) {
F_47 ( V_216 ) ;
V_216 = NULL ;
return V_68 ;
}
return 0 ;
}
static void F_105 ( struct V_93 * V_94 )
{
if ( V_216 ) {
F_56 ( & V_94 -> V_8 , V_216 ) ;
F_47 ( V_216 ) ;
V_216 = NULL ;
}
}
static T_6 F_148 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
unsigned int V_68 ;
if ( F_58 ( 0x011D , 0x0000 , & V_68 ) )
return - V_112 ;
return snprintf ( V_82 , V_92 , L_21 , V_68 ) ;
}
static int F_92 ( struct V_93 * V_94 )
{
unsigned int V_68 ;
V_217 = F_52 ( sizeof( struct V_88 ) , V_35 ) ;
if ( ! V_217 )
return - V_37 ;
F_53 ( & V_217 -> V_89 ) ;
V_217 -> V_89 . V_39 = L_90 ;
V_217 -> V_89 . V_100 = V_101 ;
V_217 -> V_102 = F_148 ;
V_217 -> V_177 = NULL ;
V_68 = F_54 ( & V_94 -> V_8 , V_217 ) ;
if ( V_68 ) {
F_47 ( V_217 ) ;
V_217 = NULL ;
return V_68 ;
}
return 0 ;
}
static void F_106 ( struct V_93 * V_94 )
{
if ( V_217 ) {
F_56 ( & V_94 -> V_8 , V_217 ) ;
F_47 ( V_217 ) ;
V_217 = NULL ;
}
}
static T_6 F_149 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
unsigned int V_68 ;
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_123 ( V_82 , 10 , & V_67 ) || V_67 > 1 )
return - V_81 ;
if ( F_58 ( 0x0168 , V_67 << 0x10 , & V_68 ) )
return - V_112 ;
return V_77 ;
}
static int F_93 ( struct V_93 * V_94 )
{
unsigned int V_68 ;
V_218 = F_52 ( sizeof( struct V_88 ) , V_35 ) ;
if ( ! V_218 )
return - V_37 ;
F_53 ( & V_218 -> V_89 ) ;
V_218 -> V_89 . V_39 = L_91 ;
V_218 -> V_89 . V_100 = V_176 ;
V_218 -> V_102 = NULL ;
V_218 -> V_177 = F_149 ;
V_68 = F_54 ( & V_94 -> V_8 , V_218 ) ;
if ( V_68 ) {
F_47 ( V_218 ) ;
V_218 = NULL ;
return V_68 ;
}
return 0 ;
}
static void F_107 ( struct V_93 * V_94 )
{
if ( V_218 ) {
F_56 ( & V_94 -> V_8 , V_218 ) ;
F_47 ( V_218 ) ;
V_218 = NULL ;
}
}
static T_6 F_150 ( struct V_87 * V_8 ,
struct V_88 * V_89 , const char * V_82 , T_5 V_77 )
{
unsigned int V_68 ;
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_123 ( V_82 , 10 , & V_67 ) || V_67 > 1 )
return - V_81 ;
if ( F_58 ( V_219 -> V_65 ,
( ! V_67 << 0x10 ) | 0x100 , & V_68 ) )
return - V_112 ;
return V_77 ;
}
static T_6 F_151 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
unsigned int V_68 ;
if ( F_58 ( V_219 -> V_65 , 0x000 , & V_68 ) )
return - V_81 ;
return snprintf ( V_82 , V_92 , L_21 , ! ( V_68 & 0x01 ) ) ;
}
static int F_81 ( struct V_93 * V_94 ,
unsigned int V_65 )
{
int V_57 = 0 ;
V_219 = F_52 ( sizeof( struct V_220 ) , V_35 ) ;
if ( ! V_219 )
return - V_37 ;
V_219 -> V_65 = V_65 ;
F_53 ( & V_219 -> V_89 . V_89 ) ;
V_219 -> V_89 . V_89 . V_39 = L_92 ;
V_219 -> V_89 . V_89 . V_100 = V_101 | V_176 ;
V_219 -> V_89 . V_102 = F_151 ;
V_219 -> V_89 . V_177 = F_150 ;
V_57 = F_54 ( & V_94 -> V_8 , & V_219 -> V_89 ) ;
if ( V_57 ) {
F_47 ( V_219 ) ;
V_219 = NULL ;
}
return V_57 ;
}
static void F_95 ( struct V_93 * V_94 )
{
if ( V_219 ) {
F_56 ( & V_94 -> V_8 , & V_219 -> V_89 ) ;
F_47 ( V_219 ) ;
V_219 = NULL ;
}
}
static void F_152 ( int V_65 ,
struct V_120 * V_118 )
{
T_3 V_104 ;
int V_32 ;
int V_221 = 0 ;
T_1 V_222 = 0xff , V_223 = 0x00 ;
unsigned char V_82 [ 32 ] = { 0 } ;
V_118 -> V_65 = V_65 ;
V_118 -> V_104 = 0 ;
V_118 -> V_224 = 0xff ;
V_104 = F_57 ( V_65 ) ;
V_32 = F_48 ( V_97 , L_60 , & V_104 , V_82 ,
32 ) ;
if ( V_32 < 0 )
return;
switch ( V_65 ) {
case 0x012f :
case 0x0137 :
V_221 = 9 ;
break;
case 0x143 :
case 0x14b :
case 0x14c :
V_221 = 16 ;
break;
}
for ( V_32 = 0 ; V_32 < V_221 && V_32 < F_12 ( V_82 ) ; V_32 ++ ) {
F_13 ( L_93 , V_82 [ V_32 ] ) ;
if ( ! V_82 [ V_32 ] )
break;
if ( V_82 [ V_32 ] > V_223 )
V_223 = V_82 [ V_32 ] ;
if ( V_82 [ V_32 ] < V_222 )
V_222 = V_82 [ V_32 ] ;
}
V_118 -> V_104 = V_222 ;
V_118 -> V_224 = V_223 ;
F_13 ( L_94 , V_118 -> V_104 ,
V_118 -> V_224 ) ;
}
static void F_153 ( void )
{
int V_225 = 0 ;
const struct V_226 * V_227 = NULL ;
struct V_228 V_118 ;
if ( F_57 ( 0x12f ) >= 0 ) {
V_227 = & V_229 ;
V_230 . V_122 = 0x0100 ;
F_152 ( 0x12f , & V_230 ) ;
V_225 = V_230 . V_224 - V_230 . V_104 ;
} else if ( F_57 ( 0x137 ) >= 0 ) {
V_227 = & V_229 ;
V_230 . V_122 = 0x0100 ;
F_152 ( 0x137 , & V_230 ) ;
V_225 = V_230 . V_224 - V_230 . V_104 ;
} else if ( F_57 ( 0x143 ) >= 0 ) {
V_227 = & V_229 ;
V_230 . V_122 = 0x3000 ;
F_152 ( 0x143 , & V_230 ) ;
V_225 = V_230 . V_224 - V_230 . V_104 ;
} else if ( F_57 ( 0x14b ) >= 0 ) {
V_227 = & V_229 ;
V_230 . V_122 = 0x3000 ;
F_152 ( 0x14b , & V_230 ) ;
V_225 = V_230 . V_224 - V_230 . V_104 ;
} else if ( F_57 ( 0x14c ) >= 0 ) {
V_227 = & V_229 ;
V_230 . V_122 = 0x3000 ;
F_152 ( 0x14c , & V_230 ) ;
V_225 = V_230 . V_224 - V_230 . V_104 ;
} else if ( F_111 ( V_97 , L_23 ) ) {
V_227 = & V_231 ;
V_225 = V_108 - 1 ;
} else
return;
memset ( & V_118 , 0 , sizeof( struct V_228 ) ) ;
V_118 . type = V_232 ;
V_118 . V_225 = V_225 ;
V_230 . V_8 = F_154 ( L_95 , NULL ,
& V_230 ,
V_227 , & V_118 ) ;
if ( F_155 ( V_230 . V_8 ) ) {
F_46 ( L_96 ) ;
V_230 . V_8 = NULL ;
} else
V_230 . V_8 -> V_118 . V_119 =
V_227 -> V_233 ( V_230 . V_8 ) ;
}
static void F_156 ( void )
{
if ( V_230 . V_8 )
F_157 ( V_230 . V_8 ) ;
}
static int F_158 ( struct V_31 * V_87 )
{
T_4 V_72 ;
int V_68 = 0 ;
struct V_109 * V_110 ;
V_133 = V_87 ;
strcpy ( F_159 ( V_87 ) , L_97 ) ;
V_97 = V_87 -> V_65 ;
V_68 = F_160 ( V_87 ) ;
if ( ! V_68 && ! V_87 -> V_72 . V_234 ) {
F_13 ( L_98 ) ;
V_68 = - V_235 ;
goto V_236;
}
V_68 = F_34 () ;
if ( V_68 )
goto V_237;
if ( V_98 ) {
V_72 = F_161 ( V_238 ,
V_97 , 1 , F_77 ,
NULL , NULL , NULL ) ;
if ( F_44 ( V_72 ) ) {
F_46 ( L_99 ) ;
V_68 = - V_235 ;
goto V_237;
}
}
V_68 = F_16 ( V_87 ) ;
if ( V_68 ) {
F_20 ( L_100 ) ;
goto V_239;
}
if ( F_111 ( V_97 , L_54 ) ) {
int V_96 = 1 ;
if ( F_45 ( V_97 , L_54 , & V_96 , NULL ) )
F_13 ( L_55 ) ;
}
if ( F_111 ( V_97 , L_14 ) ) {
F_13 ( L_101 ) ;
V_68 = F_51 ( V_61 ) ;
if ( ! V_68 )
F_80 ( V_87 , V_61 ) ;
}
if ( F_162 () ) {
F_71 ( L_102 ) ;
} else {
F_153 () ;
}
for ( V_110 = V_145 ; V_110 -> V_39 ; ++ V_110 ) {
if ( ! V_98 && V_110 -> V_98 )
continue;
for (; V_110 -> V_111 && * V_110 -> V_111 ; ++ V_110 -> V_111 ) {
if ( F_111 ( V_97 ,
* V_110 -> V_111 ) ) {
F_13 ( L_103 ,
V_110 -> V_39 , * V_110 -> V_111 ) ;
V_110 -> V_99 . V_89 . V_100 |= V_101 ;
break;
}
}
for (; V_110 -> V_114 && * V_110 -> V_114 ; ++ V_110 -> V_114 ) {
if ( F_111 ( V_97 ,
* V_110 -> V_114 ) ) {
F_13 ( L_104 ,
V_110 -> V_39 , * V_110 -> V_114 ) ;
V_110 -> V_99 . V_89 . V_100 |= V_176 ;
break;
}
}
if ( V_110 -> V_99 . V_89 . V_100 != 0 ) {
V_68 =
F_54 ( & V_61 -> V_8 ,
& V_110 -> V_99 ) ;
if ( V_68 )
goto V_240;
}
}
F_71 ( L_105 ) ;
return 0 ;
V_240:
for ( V_110 = V_145 ; V_110 -> V_39 ; ++ V_110 ) {
F_56 ( & V_61 -> V_8 , & V_110 -> V_99 ) ;
}
F_156 () ;
F_94 ( V_61 ) ;
F_55 ( V_61 ) ;
V_239:
F_31 () ;
V_237:
F_40 () ;
V_236:
F_101 () ;
return V_68 ;
}
static int F_163 ( struct V_31 * V_87 )
{
struct V_109 * V_110 ;
F_156 () ;
V_133 = NULL ;
for ( V_110 = V_145 ; V_110 -> V_39 ; ++ V_110 ) {
F_56 ( & V_61 -> V_8 , & V_110 -> V_99 ) ;
}
F_94 ( V_61 ) ;
F_55 ( V_61 ) ;
F_40 () ;
F_31 () ;
F_13 ( V_241 L_106 ) ;
return 0 ;
}
static T_1 F_164 ( T_1 V_8 )
{
T_1 V_242 , V_243 ;
F_165 ( F_166 ( V_244 . V_245 -> V_246 . V_247 + 4 ) & 2 ,
V_248 ) ;
F_167 ( V_8 , V_244 . V_245 -> V_246 . V_247 + 4 ) ;
V_242 = F_166 ( V_244 . V_245 -> V_246 . V_247 + 4 ) ;
V_243 = F_166 ( V_244 . V_245 -> V_246 . V_247 ) ;
F_13 ( L_107 , V_8 , ( V_243 << 8 ) | V_242 ) ;
return V_243 ;
}
static T_1 F_168 ( T_1 V_8 , T_1 V_249 )
{
T_1 V_242 ;
F_165 ( F_166 ( V_244 . V_245 -> V_246 . V_247 + 4 ) & 2 ,
V_248 ) ;
F_167 ( V_8 , V_244 . V_245 -> V_246 . V_247 + 4 ) ;
F_165 ( F_166 ( V_244 . V_245 -> V_246 . V_247 + 4 ) & 2 ,
V_248 ) ;
F_167 ( V_249 , V_244 . V_245 -> V_246 . V_247 ) ;
V_242 = F_166 ( V_244 . V_245 -> V_246 . V_247 ) ;
F_13 ( L_108 , V_8 , V_249 , V_242 ) ;
return V_242 ;
}
static T_1 F_169 ( T_1 V_8 , T_1 V_249 , T_1 V_80 )
{
T_1 V_242 ;
F_165 ( F_166 ( V_244 . V_245 -> V_246 . V_247 + 4 ) & 2 , V_248 ) ;
F_167 ( V_8 , V_244 . V_245 -> V_246 . V_247 + 4 ) ;
F_165 ( F_166 ( V_244 . V_245 -> V_246 . V_247 + 4 ) & 2 , V_248 ) ;
F_167 ( V_249 , V_244 . V_245 -> V_246 . V_247 ) ;
F_165 ( F_166 ( V_244 . V_245 -> V_246 . V_247 + 4 ) & 2 , V_248 ) ;
F_167 ( V_80 , V_244 . V_245 -> V_246 . V_247 ) ;
V_242 = F_166 ( V_244 . V_245 -> V_246 . V_247 ) ;
F_13 ( L_109 ,
V_8 , V_249 , V_80 , V_242 ) ;
return V_242 ;
}
static int F_170 ( const T_1 V_250 , const T_1 V_251 )
{
if ( V_250 == 0x31 ) {
if ( V_251 == 0x5c || V_251 == 0x5f )
F_164 ( 0xA0 ) ;
else if ( V_251 == 0x61 )
F_164 ( 0xB3 ) ;
return 0 ;
}
return 1 ;
}
static void F_171 ( struct V_252 * V_8 )
{
struct V_253 * V_254 ;
V_254 = F_172 ( V_255 ,
V_256 , NULL ) ;
if ( V_254 ) {
V_8 -> V_257 = V_258 ;
V_8 -> V_259 = V_260 ;
V_8 -> V_261 = V_262 ;
goto V_60;
}
V_254 = F_172 ( V_255 ,
V_263 , NULL ) ;
if ( V_254 ) {
V_8 -> V_257 = V_264 ;
V_8 -> V_259 = V_265 ;
V_8 -> V_261 = V_266 ;
goto V_60;
}
V_254 = F_172 ( V_255 ,
V_267 , NULL ) ;
if ( V_254 ) {
V_8 -> V_257 = V_268 ;
V_8 -> V_269 = F_170 ;
V_8 -> V_259 = V_270 ;
V_8 -> V_261 = V_271 ;
goto V_60;
}
V_254 = F_172 ( V_255 ,
V_272 , NULL ) ;
if ( V_254 ) {
V_8 -> V_257 = V_268 ;
V_8 -> V_269 = F_170 ;
V_8 -> V_259 = V_270 ;
V_8 -> V_261 = V_271 ;
goto V_60;
}
V_254 = F_172 ( V_255 ,
V_273 , NULL ) ;
if ( V_254 ) {
V_8 -> V_257 = V_268 ;
V_8 -> V_269 = F_170 ;
V_8 -> V_259 = V_270 ;
V_8 -> V_261 = V_271 ;
goto V_60;
}
V_8 -> V_257 = V_264 ;
V_8 -> V_259 = V_265 ;
V_8 -> V_261 = V_266 ;
V_60:
if ( V_254 )
F_173 ( V_254 ) ;
F_71 ( L_110 ,
V_8 -> V_257 == V_258 ? 1 :
V_8 -> V_257 == V_264 ? 2 : 3 ) ;
}
static int F_174 ( void )
{
T_1 V_80 ;
V_80 = F_168 ( 0x8f , V_274 ) ;
return ( V_80 != 0xff && ( V_80 & V_275 ) ) ;
}
static int F_175 ( void )
{
if ( ! V_276 ) {
F_46 ( L_111 ) ;
return - V_235 ;
}
F_165 ( F_169 ( 0x90 , V_277 ,
V_278 ) ,
V_279 ) ;
if ( V_244 . V_280 ) {
F_168 ( 0x91 , 0 ) ;
V_244 . V_280 = 0 ;
}
return 0 ;
}
static int F_176 ( void )
{
int V_32 , V_281 , V_282 ;
if ( ! V_276 ) {
F_46 ( L_111 ) ;
return - V_235 ;
}
if ( V_244 . V_280 )
return 0 ;
for ( V_281 = 5 ; V_281 > 0 ; V_281 -- ) {
for ( V_282 = 0 ; V_282 < 100 && F_168 ( 0x91 , 0x1 ) ; V_282 ++ )
F_177 ( 10 ) ;
F_164 ( 0x93 ) ;
for ( V_32 = 400 ; V_32 > 0 ; V_32 -- ) {
if ( F_174 () )
break;
F_177 ( 10 ) ;
}
if ( V_32 )
break;
}
if ( V_281 == 0 ) {
F_46 ( L_112 ) ;
return - V_235 ;
}
F_165 ( F_169 ( 0x90 , V_283 ,
0x5a ) ,
V_279 ) ;
V_244 . V_280 = 1 ;
return 0 ;
}
int F_178 ( int V_284 , T_1 V_67 )
{
if ( ! V_276 )
return - V_112 ;
F_179 ( & V_244 . V_285 ) ;
switch ( V_284 ) {
case V_286 :
if ( V_67 )
F_176 () ;
else
F_175 () ;
break;
case V_287 :
F_165 ( F_169 ( 0x90 , V_288 , V_67 ) ,
V_279 ) ;
break;
case V_289 :
F_165 ( F_169 ( 0x90 , V_290 , V_67 ) ,
V_279 ) ;
break;
case V_291 :
F_165 ( F_169 ( 0x90 , V_292 , V_67 ) ,
V_279 ) ;
break;
case V_293 :
F_165 ( F_169 ( 0x90 , V_294 , V_67 ) ,
V_279 ) ;
break;
case V_295 :
F_165 ( F_169 ( 0x90 , V_296 , V_67 ) ,
V_279 ) ;
break;
case V_297 :
F_165 ( F_169 ( 0x90 , V_277 , V_67 ) ,
V_279 ) ;
break;
case V_298 :
F_165 ( F_169 ( 0x90 , V_299 , V_67 ) ,
V_279 ) ;
break;
default:
F_20 ( L_113 , V_284 ) ;
break;
}
F_180 ( & V_244 . V_285 ) ;
return 0 ;
}
static void F_181 ( T_1 V_300 )
{
V_300 = ! ! V_300 ;
if ( V_244 . V_301 == V_300 )
return;
F_168 ( 0xB0 , V_300 ) ;
F_164 ( 0x82 ) ;
V_244 . V_301 = V_300 ;
}
static T_6 F_182 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_123 ( V_82 , 10 , & V_67 ) )
return - V_81 ;
F_179 ( & V_244 . V_285 ) ;
F_181 ( V_67 ) ;
F_180 ( & V_244 . V_285 ) ;
return V_77 ;
}
static T_6 F_183 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
T_6 V_77 ;
F_179 ( & V_244 . V_285 ) ;
V_77 = snprintf ( V_82 , V_92 , L_21 , V_244 . V_301 ) ;
F_180 ( & V_244 . V_285 ) ;
return V_77 ;
}
static void F_184 ( T_1 V_300 )
{
V_300 = ! ! V_300 ;
if ( V_244 . V_302 == V_300 )
return;
F_168 ( 0x96 , V_300 ) ;
F_164 ( 0x82 ) ;
V_244 . V_302 = V_300 ;
}
static T_6 F_185 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_123 ( V_82 , 10 , & V_67 ) )
return - V_81 ;
F_179 ( & V_244 . V_285 ) ;
F_184 ( V_67 ) ;
F_180 ( & V_244 . V_285 ) ;
return V_77 ;
}
static T_6 F_186 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
T_6 V_77 = 0 ;
F_179 ( & V_244 . V_285 ) ;
V_77 = snprintf ( V_82 , V_92 , L_21 , V_244 . V_302 ) ;
F_180 ( & V_244 . V_285 ) ;
return V_77 ;
}
static int F_187 ( unsigned long V_67 )
{
return F_188 ( V_303 , V_67 ) ;
}
static int F_189 ( T_1 * V_67 )
{
return F_190 ( V_303 , V_67 ) ;
}
static T_6 F_191 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_123 ( V_82 , 10 , & V_67 ) )
return - V_81 ;
if ( F_187 ( V_67 ) )
return - V_112 ;
return V_77 ;
}
static T_6 F_192 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
T_1 V_67 = 0 ;
if ( F_189 ( & V_67 ) )
return - V_112 ;
return snprintf ( V_82 , V_92 , L_21 , V_67 ) ;
}
static int F_193 ( int V_304 , struct V_305 * V_306 , int V_307 )
{
return F_194 ( V_304 , V_306 , V_307 , & V_308 . V_309 ) ;
}
static int F_195 ( struct V_310 * V_310 , struct V_305 * V_305 )
{
F_30 ( & V_308 . V_311 ) ;
return 0 ;
}
static int F_196 ( struct V_310 * V_310 , struct V_305 * V_305 )
{
unsigned long V_4 ;
F_2 ( & V_308 . V_6 , V_4 ) ;
if ( F_197 ( & V_308 . V_311 ) == 1 )
F_198 ( & V_308 . V_7 ) ;
F_9 ( & V_308 . V_6 , V_4 ) ;
return 0 ;
}
static T_6 F_199 ( struct V_305 * V_305 , char T_8 * V_312 ,
T_5 V_77 , T_9 * V_196 )
{
T_6 V_57 ;
unsigned char V_313 ;
if ( ( F_6 ( & V_308 . V_7 ) == 0 ) &&
( V_305 -> V_314 & V_315 ) )
return - V_316 ;
V_57 = F_200 ( V_308 . V_317 ,
F_6 ( & V_308 . V_7 ) != 0 ) ;
if ( V_57 )
return V_57 ;
while ( V_57 < V_77 &&
( F_201 ( & V_308 . V_7 , & V_313 , sizeof( V_313 ) ,
& V_308 . V_6 ) == sizeof( V_313 ) ) ) {
if ( F_202 ( V_313 , V_312 ++ ) )
return - V_318 ;
V_57 ++ ;
}
if ( V_57 > 0 ) {
struct V_310 * V_310 = F_203 ( V_305 ) ;
V_310 -> V_319 = F_204 ( V_310 -> V_320 ) ;
}
return V_57 ;
}
static unsigned int F_205 ( struct V_305 * V_305 , T_10 * V_321 )
{
F_206 ( V_305 , & V_308 . V_317 , V_321 ) ;
if ( F_6 ( & V_308 . V_7 ) )
return V_322 | V_323 ;
return 0 ;
}
static int F_207 ( T_1 V_324 , T_11 * V_67 )
{
T_1 V_325 , V_326 ;
if ( F_190 ( V_324 , & V_325 ) )
return - 1 ;
if ( F_190 ( V_324 + 1 , & V_326 ) )
return - 1 ;
* V_67 = V_325 | ( V_326 << 8 ) ;
return 0 ;
}
static long F_208 ( struct V_305 * V_327 , unsigned int V_181 ,
unsigned long V_96 )
{
int V_57 = 0 ;
void T_8 * V_328 = ( void T_8 * ) V_96 ;
T_1 V_329 ;
T_11 V_330 ;
int V_67 ;
F_179 ( & V_244 . V_285 ) ;
switch ( V_181 ) {
case V_331 :
if ( V_230 . V_8 == NULL ) {
V_57 = - V_112 ;
break;
}
if ( F_45 ( V_97 , L_23 , NULL ,
& V_67 ) ) {
V_57 = - V_112 ;
break;
}
V_329 = ( ( V_67 & 0xff ) - 1 ) << 5 ;
if ( F_209 ( V_328 , & V_329 , sizeof( V_329 ) ) )
V_57 = - V_318 ;
break;
case V_332 :
if ( V_230 . V_8 == NULL ) {
V_57 = - V_112 ;
break;
}
if ( F_210 ( & V_329 , V_328 , sizeof( V_329 ) ) ) {
V_57 = - V_318 ;
break;
}
V_67 = ( V_329 >> 5 ) + 1 ;
if ( F_45 ( V_97 , L_22 , & V_67 ,
NULL ) ) {
V_57 = - V_112 ;
break;
}
V_230 . V_8 -> V_118 . V_119 =
F_66 ( V_230 . V_8 ) ;
break;
case V_333 :
if ( F_207 ( V_334 , & V_330 ) ) {
V_57 = - V_112 ;
break;
}
if ( F_209 ( V_328 , & V_330 , sizeof( V_330 ) ) )
V_57 = - V_318 ;
break;
case V_335 :
if ( F_207 ( V_336 , & V_330 ) ) {
V_57 = - V_112 ;
break;
}
if ( F_209 ( V_328 , & V_330 , sizeof( V_330 ) ) )
V_57 = - V_318 ;
break;
case V_337 :
if ( F_207 ( V_338 , & V_330 ) ) {
V_57 = - V_112 ;
break;
}
if ( F_209 ( V_328 , & V_330 , sizeof( V_330 ) ) )
V_57 = - V_318 ;
break;
case V_339 :
if ( F_207 ( V_340 , & V_330 ) ) {
V_57 = - V_112 ;
break;
}
if ( F_209 ( V_328 , & V_330 , sizeof( V_330 ) ) )
V_57 = - V_318 ;
break;
case V_341 :
if ( F_190 ( V_342 , & V_329 ) ) {
V_57 = - V_112 ;
break;
}
V_329 &= 0x07 ;
if ( F_209 ( V_328 , & V_329 , sizeof( V_329 ) ) )
V_57 = - V_318 ;
break;
case V_343 :
V_329 = V_244 . V_302 ;
if ( F_209 ( V_328 , & V_329 , sizeof( V_329 ) ) )
V_57 = - V_318 ;
break;
case V_344 :
if ( F_210 ( & V_329 , V_328 , sizeof( V_329 ) ) ) {
V_57 = - V_318 ;
break;
}
F_184 ( V_329 ) ;
break;
case V_345 :
if ( F_189 ( & V_329 ) ) {
V_57 = - V_112 ;
break;
}
if ( F_209 ( V_328 , & V_329 , sizeof( V_329 ) ) )
V_57 = - V_318 ;
break;
case V_346 :
if ( F_210 ( & V_329 , V_328 , sizeof( V_329 ) ) ) {
V_57 = - V_318 ;
break;
}
if ( F_187 ( V_329 ) )
V_57 = - V_112 ;
break;
case V_347 :
if ( F_190 ( V_348 , & V_329 ) ) {
V_57 = - V_112 ;
break;
}
if ( F_209 ( V_328 , & V_329 , sizeof( V_329 ) ) )
V_57 = - V_318 ;
break;
default:
V_57 = - V_81 ;
}
F_180 ( & V_244 . V_285 ) ;
return V_57 ;
}
static void F_211 ( T_1 V_12 )
{
F_15 ( & V_308 . V_7 , ( unsigned char * ) & V_12 ,
sizeof( V_12 ) , & V_308 . V_6 ) ;
F_212 ( & V_308 . V_309 , V_349 , V_350 ) ;
F_213 ( & V_308 . V_317 ) ;
}
static int F_214 ( void )
{
int error ;
F_18 ( & V_308 . V_6 ) ;
error =
F_19 ( & V_308 . V_7 , V_34 , V_35 ) ;
if ( error ) {
F_20 ( L_3 ) ;
return error ;
}
F_215 ( & V_308 . V_317 ) ;
if ( V_351 != - 1 )
V_352 . V_351 = V_351 ;
error = F_216 ( & V_352 ) ;
if ( error ) {
F_20 ( L_114 ) ;
goto V_38;
}
if ( V_351 == - 1 )
F_71 ( L_115 ,
V_352 . V_351 ) ;
return 0 ;
V_38:
F_29 ( & V_308 . V_7 ) ;
return error ;
}
static void F_217 ( void )
{
F_218 ( & V_352 ) ;
F_29 ( & V_308 . V_7 ) ;
}
static int F_214 ( void ) { return 0 ; }
static void F_217 ( void ) { }
static void F_211 ( T_1 V_12 ) { }
static T_4
F_219 ( struct V_353 * V_354 , void * V_137 )
{
T_7 V_32 ;
struct V_252 * V_8 = (struct V_252 * ) V_137 ;
switch ( V_354 -> type ) {
case V_355 :
{
struct V_356 * V_357 = F_52 ( sizeof( * V_357 ) , V_35 ) ;
if ( ! V_357 )
return V_358 ;
F_220 ( & V_357 -> V_359 , & V_8 -> V_360 ) ;
return V_142 ;
}
case V_361 :
return V_142 ;
case V_362 :
{
struct V_363 * V_364 = & V_354 -> V_127 . V_365 ;
struct V_366 * V_367 = NULL ;
if ( ! V_364 || ! V_364 -> V_368 ) {
F_13 ( L_116 ) ;
return V_142 ;
}
for ( V_32 = 0 ; V_32 < V_364 -> V_368 ; V_32 ++ ) {
if ( ! V_364 -> V_369 [ V_32 ] ) {
F_46 ( L_117 ,
V_364 -> V_369 [ V_32 ] ) ;
continue;
}
V_367 = F_52 ( sizeof( * V_367 ) ,
V_35 ) ;
if ( ! V_367 )
return V_358 ;
F_220 ( & V_367 -> V_359 , & V_8 -> V_369 ) ;
V_367 -> V_365 . V_370 = V_364 -> V_370 ;
V_367 -> V_365 . V_371 = V_364 -> V_371 ;
V_367 -> V_365 . V_372 = V_364 -> V_372 ;
V_367 -> V_365 . V_368 = 1 ;
V_367 -> V_365 . V_369 [ 0 ] = V_364 -> V_369 [ V_32 ] ;
}
return V_142 ;
}
case V_373 :
{
struct V_374 * V_375 = & V_354 -> V_127 . V_375 ;
struct V_356 * V_357 =
F_221 ( & V_8 -> V_360 , struct V_356 , V_359 ) ;
if ( ! V_375 ) {
F_13 ( L_118 ) ;
return V_142 ;
}
if ( ! V_357 -> V_246 . V_247 ) {
memcpy ( & V_357 -> V_246 , V_375 , sizeof( * V_375 ) ) ;
F_13 ( L_119 , V_357 -> V_246 . V_247 ,
V_357 -> V_246 . V_376 ) ;
}
else if ( ! V_357 -> V_377 . V_247 ) {
memcpy ( & V_357 -> V_377 , V_375 , sizeof( * V_375 ) ) ;
F_13 ( L_120 , V_357 -> V_377 . V_247 ,
V_357 -> V_377 . V_376 ) ;
}
else {
F_20 ( L_121 ) ;
return V_358 ;
}
return V_142 ;
}
default:
F_13 ( L_122 ,
V_354 -> type ) ;
case V_378 :
return V_142 ;
}
return V_379 ;
}
static int F_222 ( struct V_31 * V_87 )
{
int V_68 = 0 ;
T_4 V_72 = V_142 ;
if ( ! V_87 )
return - V_81 ;
F_13 ( L_123 ) ;
V_68 = F_160 ( V_87 ) ;
if ( V_68 ) {
F_46 ( L_124 ) ;
goto V_380;
}
if ( ! V_87 -> V_72 . V_381 )
F_13 ( L_125 ) ;
else
F_13 ( L_126 ) ;
F_13 ( L_127 , V_382 ) ;
V_72 = F_223 ( V_87 -> V_65 , V_382 ,
F_219 , & V_244 ) ;
if ( F_44 ( V_72 ) ) {
F_46 ( L_128 , V_382 ) ;
V_68 = - V_235 ;
}
V_380:
return V_68 ;
}
static int F_224 ( struct V_31 * V_87 )
{
T_4 V_57 = F_43 ( V_87 -> V_65 , L_129 , NULL ,
NULL ) ;
if ( F_44 ( V_57 ) && V_57 != V_383 )
return - V_384 ;
F_13 ( L_125 ) ;
return 0 ;
}
static int F_225 ( struct V_31 * V_87 ,
struct V_356 * V_357 , struct V_366 * V_365 )
{
T_4 V_72 ;
int V_68 = 0 ;
struct {
struct V_353 V_385 ;
struct V_353 V_386 ;
struct V_353 V_387 ;
struct V_353 V_388 ;
} * V_354 ;
struct V_69 V_82 = { 0 , NULL } ;
if ( ! V_357 || ! V_365 )
return - V_81 ;
V_354 = F_52 ( sizeof( * V_354 ) + 1 , V_35 ) ;
if ( ! V_354 )
return - V_37 ;
V_82 . V_86 = sizeof( * V_354 ) + 1 ;
V_82 . V_78 = V_354 ;
if ( V_244 . V_257 == V_258 ) {
V_354 -> V_385 . type = V_373 ;
V_354 -> V_385 . V_86 = sizeof( struct V_353 ) ;
memcpy ( & V_354 -> V_385 . V_127 . V_375 , & V_357 -> V_246 ,
sizeof( struct V_374 ) ) ;
V_354 -> V_386 . type = V_373 ;
V_354 -> V_386 . V_86 = sizeof( struct V_353 ) ;
memcpy ( & V_354 -> V_386 . V_127 . V_375 , & V_357 -> V_377 ,
sizeof( struct V_374 ) ) ;
V_354 -> V_387 . type = V_362 ;
V_354 -> V_387 . V_86 = sizeof( struct V_353 ) ;
memcpy ( & V_354 -> V_387 . V_127 . V_365 , & V_365 -> V_365 ,
sizeof( struct V_363 ) ) ;
V_354 -> V_387 . V_127 . V_365 . V_372 = V_389 ;
V_354 -> V_388 . type = V_378 ;
V_354 -> V_388 . V_86 = sizeof( struct V_353 ) ;
}
else {
V_354 -> V_385 . type = V_373 ;
V_354 -> V_385 . V_86 = sizeof( struct V_353 ) ;
memcpy ( & V_354 -> V_385 . V_127 . V_375 , & V_357 -> V_246 ,
sizeof( struct V_374 ) ) ;
V_354 -> V_386 . type = V_362 ;
V_354 -> V_386 . V_86 = sizeof( struct V_353 ) ;
memcpy ( & V_354 -> V_386 . V_127 . V_365 , & V_365 -> V_365 ,
sizeof( struct V_363 ) ) ;
V_354 -> V_386 . V_127 . V_365 . V_372 = V_389 ;
V_354 -> V_387 . type = V_378 ;
V_354 -> V_387 . V_86 = sizeof( struct V_353 ) ;
}
F_13 ( L_130 ) ;
V_72 = F_226 ( V_87 -> V_65 , & V_82 ) ;
if ( F_44 ( V_72 ) ) {
F_20 ( L_131 ) ;
V_68 = - V_235 ;
goto V_380;
}
F_164 ( 0x82 ) ;
F_168 ( 0x81 , 0xff ) ;
F_164 ( V_390 ? 0x92 : 0x82 ) ;
V_380:
F_47 ( V_354 ) ;
return V_68 ;
}
static T_12 V_366 ( int V_365 , void * V_391 )
{
int V_32 , V_281 ;
T_1 V_251 = 0 ;
T_1 V_250 = 0 ;
T_1 V_392 = 0 ;
struct V_252 * V_8 = (struct V_252 * ) V_391 ;
V_251 = F_166 ( V_8 -> V_245 -> V_246 . V_247 ) ;
if ( V_8 -> V_245 -> V_377 . V_247 )
V_250 = F_166 ( V_8 -> V_245 -> V_377 . V_247 ) ;
else
V_250 = F_166 ( V_8 -> V_245 -> V_246 . V_247 +
V_8 -> V_259 ) ;
F_13 ( L_132 ,
V_251 , V_250 , V_8 -> V_245 -> V_246 . V_247 ,
V_8 -> V_259 ) ;
if ( V_251 == 0x00 || V_251 == 0xff )
return V_393 ;
for ( V_32 = 0 ; V_8 -> V_261 [ V_32 ] . V_394 ; V_32 ++ ) {
if ( ( V_250 & V_8 -> V_261 [ V_32 ] . V_127 ) !=
V_8 -> V_261 [ V_32 ] . V_127 )
continue;
if ( ! ( V_394 & V_8 -> V_261 [ V_32 ] . V_394 ) )
continue;
for ( V_281 = 0 ; V_8 -> V_261 [ V_32 ] . V_395 [ V_281 ] . V_12 ; V_281 ++ ) {
if ( V_251 == V_8 -> V_261 [ V_32 ] . V_395 [ V_281 ] . V_127 ) {
V_392 =
V_8 -> V_261 [ V_32 ] . V_395 [ V_281 ] . V_12 ;
if ( ! V_392 )
return V_393 ;
goto V_396;
}
}
}
if ( V_8 -> V_269 && V_8 -> V_269 ( V_250 , V_251 ) == 0 )
return V_393 ;
F_13 ( L_133 ,
V_251 , V_250 , V_8 -> V_245 -> V_246 . V_247 ,
V_8 -> V_259 ) ;
return V_393 ;
V_396:
F_10 ( V_392 ) ;
F_211 ( V_392 ) ;
return V_393 ;
}
static int F_227 ( struct V_31 * V_87 )
{
struct V_356 * V_375 , * V_397 ;
struct V_366 * V_365 , * V_398 ;
if ( F_224 ( V_87 ) ) {
F_20 ( L_134 ) ;
return - V_384 ;
}
F_228 ( V_244 . V_399 -> V_365 . V_369 [ 0 ] , & V_244 ) ;
F_229 ( V_244 . V_245 -> V_246 . V_247 ,
V_244 . V_245 -> V_246 . V_376 ) ;
if ( V_244 . V_245 -> V_377 . V_247 )
F_229 ( V_244 . V_245 -> V_377 . V_247 ,
V_244 . V_245 -> V_377 . V_376 ) ;
F_217 () ;
F_31 () ;
F_230 ( & V_61 -> V_8 . V_400 , & V_401 ) ;
F_40 () ;
F_231 (io, tmp_io, &spic_dev.ioports, list) {
F_232 ( & V_375 -> V_359 ) ;
F_47 ( V_375 ) ;
}
F_231 (irq, tmp_irq, &spic_dev.interrupts, list) {
F_232 ( & V_365 -> V_359 ) ;
F_47 ( V_365 ) ;
}
V_244 . V_245 = NULL ;
V_244 . V_399 = NULL ;
F_13 ( V_402 L_106 ) ;
return 0 ;
}
static int F_233 ( struct V_31 * V_87 )
{
int V_68 ;
struct V_356 * V_375 , * V_397 ;
struct V_366 * V_365 , * V_398 ;
V_244 . V_403 = V_87 ;
strcpy ( F_159 ( V_87 ) , L_97 ) ;
F_171 ( & V_244 ) ;
F_234 ( & V_244 . V_285 ) ;
V_68 = F_222 ( V_87 ) ;
if ( V_68 ) {
F_20 ( L_135 ) ;
goto V_404;
}
V_68 = F_16 ( V_87 ) ;
if ( V_68 ) {
F_20 ( L_100 ) ;
goto V_404;
}
V_68 = F_214 () ;
if ( V_68 )
goto V_405;
F_235 (io, &spic_dev.ioports, list) {
if ( F_236 ( V_375 -> V_246 . V_247 , V_375 -> V_246 . V_376 ,
L_136 ) ) {
F_13 ( L_137 ,
V_375 -> V_246 . V_247 , V_375 -> V_246 . V_406 ,
V_375 -> V_246 . V_376 ) ;
if ( V_375 -> V_377 . V_247 ) {
if ( F_236 ( V_375 -> V_377 . V_247 ,
V_375 -> V_377 . V_376 ,
L_136 ) ) {
F_13 ( L_138 ,
V_375 -> V_377 . V_247 , V_375 -> V_377 . V_406 ,
V_375 -> V_377 . V_376 ) ;
V_244 . V_245 = V_375 ;
break;
}
else {
F_13 ( L_139
L_140 ,
V_375 -> V_377 . V_247 , V_375 -> V_377 . V_406 ,
V_375 -> V_377 . V_376 ) ;
F_229 ( V_375 -> V_246 . V_247 ,
V_375 -> V_246 . V_376 ) ;
}
}
else {
V_244 . V_245 = V_375 ;
break;
}
}
}
if ( ! V_244 . V_245 ) {
F_20 ( L_141 ) ;
V_68 = - V_235 ;
goto V_407;
}
F_235 (irq, &spic_dev.interrupts, list) {
if ( ! F_237 ( V_365 -> V_365 . V_369 [ 0 ] , V_366 ,
0 , L_6 , & V_244 ) ) {
F_13 ( L_142
L_143 ,
V_365 -> V_365 . V_369 [ 0 ] ,
V_365 -> V_365 . V_370 ,
V_365 -> V_365 . V_371 ,
V_365 -> V_365 . V_372 ) ;
V_244 . V_399 = V_365 ;
break;
}
}
if ( ! V_244 . V_399 ) {
F_20 ( L_144 ) ;
V_68 = - V_235 ;
goto V_408;
}
V_68 = F_225 ( V_87 , V_244 . V_245 , V_244 . V_399 ) ;
if ( V_68 ) {
F_20 ( L_145 ) ;
goto V_409;
}
V_244 . V_302 = - 1 ;
V_68 = F_34 () ;
if ( V_68 )
goto V_410;
V_68 = F_238 ( & V_61 -> V_8 . V_400 , & V_401 ) ;
if ( V_68 )
goto V_411;
F_71 ( L_146 ) ;
return 0 ;
V_411:
F_40 () ;
V_410:
F_224 ( V_87 ) ;
V_409:
F_228 ( V_244 . V_399 -> V_365 . V_369 [ 0 ] , & V_244 ) ;
V_408:
F_229 ( V_244 . V_245 -> V_246 . V_247 ,
V_244 . V_245 -> V_246 . V_376 ) ;
if ( V_244 . V_245 -> V_377 . V_247 )
F_229 ( V_244 . V_245 -> V_377 . V_247 ,
V_244 . V_245 -> V_377 . V_376 ) ;
V_407:
F_217 () ;
V_405:
F_31 () ;
V_404:
F_231 (io, tmp_io, &spic_dev.ioports, list) {
F_232 ( & V_375 -> V_359 ) ;
F_47 ( V_375 ) ;
}
F_231 (irq, tmp_irq, &spic_dev.interrupts, list) {
F_232 ( & V_365 -> V_359 ) ;
F_47 ( V_365 ) ;
}
V_244 . V_245 = NULL ;
V_244 . V_399 = NULL ;
return V_68 ;
}
static int F_239 ( struct V_87 * V_8 )
{
if ( F_224 ( F_240 ( V_8 ) ) )
return - V_384 ;
return 0 ;
}
static int F_241 ( struct V_87 * V_8 )
{
F_225 ( F_240 ( V_8 ) ,
V_244 . V_245 , V_244 . V_399 ) ;
return 0 ;
}
static int T_13 F_242 ( void )
{
int V_68 ;
if ( ! V_412 && F_243 ( V_413 ) ) {
V_68 = F_244 ( & V_414 ) ;
if ( V_68 ) {
F_20 ( L_147 ) ;
goto V_60;
}
V_415 = 1 ;
}
V_68 = F_244 ( & V_416 ) ;
if ( V_68 ) {
F_20 ( L_148 ) ;
goto V_417;
}
return 0 ;
V_417:
if ( V_415 )
F_245 ( & V_414 ) ;
V_60:
return V_68 ;
}
static void T_14 F_246 ( void )
{
F_245 ( & V_416 ) ;
if ( V_415 )
F_245 ( & V_414 ) ;
}

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
T_5 V_84 = V_84 ;
union V_64 * V_79 = F_42 ( V_65 , V_39 , V_67 ) ;
if ( ! V_79 )
return - V_81 ;
if ( V_79 -> type == V_85 )
V_84 = F_49 ( V_83 , V_79 -> V_82 . V_86 ) ;
else if ( V_79 -> type == V_76 )
V_84 = F_49 ( V_83 , sizeof( V_79 -> integer . V_67 ) ) ;
else {
F_46 ( L_11 ,
V_85 , V_79 -> type ) ;
F_47 ( V_79 ) ;
return - V_81 ;
}
memcpy ( V_82 , V_79 -> V_82 . V_78 , V_84 ) ;
F_47 ( V_79 ) ;
return 0 ;
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
( V_68 & 0x01 ) ?
L_29 : L_30 ) ;
F_58 ( V_65 , 0x0100 , & V_68 ) ;
V_129 = V_132 ;
V_128 = V_68 & 0xff ;
break;
default:
F_13 ( L_31 ,
V_12 , V_65 ) ;
break;
}
V_96 = 1 << V_104 ;
F_45 ( V_97 , L_32 , & V_96 , & V_68 ) ;
} else {
V_129 = V_130 ;
F_10 ( V_128 ) ;
}
F_74 ( V_133 , V_129 , V_128 ) ;
F_75 ( V_133 -> V_134 . V_135 ,
F_76 ( & V_133 -> V_8 ) , V_129 , V_128 ) ;
}
static T_4 F_77 ( T_2 V_65 , T_7 V_136 ,
void * V_137 , void * * V_138 )
{
struct V_139 * V_140 ;
if ( F_78 ( F_79 ( V_65 , & V_140 ) ) ) {
F_46 ( L_33 ,
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
F_13 ( L_34 , V_65 ) ;
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
F_20 ( L_35 ,
V_68 ) ;
break;
case 0x0115 :
case 0x0136 :
case 0x013f :
V_68 = F_82 ( V_143 , V_65 ) ;
if ( V_68 )
F_20 ( L_36 ,
V_68 ) ;
break;
case 0x0119 :
V_68 = F_83 ( V_143 ) ;
if ( V_68 )
F_20 ( L_37 ,
V_68 ) ;
break;
case 0x0122 :
V_68 = F_84 ( V_143 ) ;
if ( V_68 )
F_20 ( L_38 ,
V_68 ) ;
break;
case 0x0131 :
V_68 = F_85 ( V_143 ) ;
if ( V_68 )
F_20 ( L_39 ,
V_68 ) ;
break;
case 0x0124 :
case 0x0135 :
V_68 = F_86 ( V_87 , V_65 ) ;
if ( V_68 )
F_20 ( L_40 ,
V_68 ) ;
break;
case 0x0137 :
case 0x0143 :
V_68 = F_87 ( V_143 , V_65 ) ;
if ( V_68 )
F_20 ( L_41 ,
V_68 ) ;
break;
default:
continue;
}
}
V_96 = 0x10 ;
if ( ! F_45 ( V_97 , L_14 , & V_96 , & V_144 ) )
F_45 ( V_97 , L_42 , & V_144 ,
& V_68 ) ;
}
static void F_88 ( struct V_93 * V_94 )
{
unsigned int V_32 , V_68 , V_144 , V_65 ;
F_45 ( V_97 , L_43 , NULL , & V_144 ) ;
F_45 ( V_97 , L_44 , & V_144 , & V_68 ) ;
for ( V_32 = 0 ; V_32 < F_12 ( V_90 -> V_91 ) ; V_32 ++ ) {
V_65 = V_90 -> V_91 [ V_32 ] ;
if ( ! V_65 )
continue;
switch ( V_65 ) {
case 0x0105 :
case 0x0148 :
F_89 ( V_94 ) ;
break;
case 0x0115 :
case 0x0136 :
case 0x013f :
F_90 ( V_94 ) ;
break;
case 0x0119 :
F_91 ( V_94 ) ;
break;
case 0x0122 :
F_92 ( V_94 ) ;
break;
case 0x0131 :
F_93 ( V_94 ) ;
break;
case 0x0124 :
case 0x0135 :
F_94 () ;
break;
case 0x0137 :
case 0x0143 :
F_95 ( V_94 ) ;
break;
default:
continue;
}
}
F_55 ( V_94 ) ;
}
static void F_96 ( void )
{
unsigned int V_32 , V_68 , V_144 , V_96 ;
F_13 ( L_45 ) ;
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
F_97 () ;
break;
case 0x0124 :
case 0x0135 :
F_73 () ;
break;
case 0x0137 :
case 0x0143 :
F_98 () ;
break;
default:
continue;
}
}
V_96 = 0x10 ;
if ( ! F_45 ( V_97 , L_14 , & V_96 , & V_144 ) )
F_45 ( V_97 , L_42 , & V_144 ,
& V_68 ) ;
}
static int F_99 ( struct V_31 * V_87 )
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
F_20 ( L_46 , V_146 , V_57 ) ;
break;
}
}
if ( F_78 ( F_100 ( V_97 , L_47 ,
& V_65 ) ) ) {
int V_96 = 1 ;
if ( F_45 ( V_97 , L_47 , & V_96 , NULL ) )
F_13 ( L_48 ) ;
}
if ( F_78 ( F_100 ( V_97 , L_14 ,
& V_65 ) ) )
F_96 () ;
return 0 ;
}
static void F_94 ( void )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_147 ; V_32 ++ ) {
if ( V_148 [ V_32 ] ) {
F_101 ( V_148 [ V_32 ] ) ;
F_102 ( V_148 [ V_32 ] ) ;
}
}
}
static int F_103 ( void * V_127 , bool V_149 )
{
int V_68 ;
int V_103 = V_150 [ ( long ) V_127 ] + 0x100 ;
if ( ! V_149 )
V_103 |= 0x030000 ;
return F_58 ( V_151 , V_103 , & V_68 ) ;
}
static int F_104 ( struct V_31 * V_87 ,
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
V_39 = L_49 ;
break;
case V_162 :
type = V_163 ;
V_39 = L_50 ;
break;
case V_164 :
type = V_165 ;
V_39 = L_51 ;
break;
case V_166 :
type = V_167 ;
V_39 = L_52 ;
break;
default:
return - V_81 ;
}
V_156 = F_105 ( V_39 , & V_87 -> V_8 , type ,
& V_168 , ( void * ) V_153 ) ;
if ( ! V_156 )
return - V_37 ;
if ( F_58 ( V_151 , 0x200 , & V_68 ) < 0 ) {
F_102 ( V_156 ) ;
return - 1 ;
}
V_158 = ! ( V_68 & 0x1 ) ;
if ( F_58 ( V_151 ,
V_150 [ V_153 ] ,
& V_68 ) < 0 ) {
F_102 ( V_156 ) ;
return - 1 ;
}
V_159 = ! ( V_68 & 0x2 ) ;
F_106 ( V_156 , V_159 ) ;
F_107 ( V_156 , V_158 ) ;
V_154 = F_108 ( V_156 ) ;
if ( V_154 ) {
F_102 ( V_156 ) ;
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
if ( F_107 ( V_148 [ V_32 ] , true ) ) {
}
continue;
}
F_58 ( V_151 , V_103 , & V_68 ) ;
F_109 ( V_148 [ V_32 ] ,
! ( V_68 & 0x2 ) , false ) ;
}
}
static int F_86 ( struct V_31 * V_87 ,
unsigned int V_65 )
{
T_3 V_104 ;
int V_32 ;
unsigned char V_82 [ 32 ] = { 0 } ;
V_104 = F_57 ( V_65 ) ;
V_151 = V_65 ;
V_32 = F_48 ( V_97 , L_53 , & V_104 , V_82 ,
32 ) ;
if ( V_32 < 0 )
return V_32 ;
for ( V_32 = 0 ; V_32 < F_12 ( V_82 ) ; V_32 ++ ) {
if ( V_82 [ V_32 ] == 0xff )
break;
F_13 ( L_54 , V_82 [ V_32 ] ) ;
if ( V_82 [ V_32 ] == 0 && ! V_148 [ V_160 ] )
F_104 ( V_87 , V_160 ) ;
if ( V_82 [ V_32 ] == 0x10 && ! V_148 [ V_162 ] )
F_104 ( V_87 , V_162 ) ;
if ( ( ( 0xf0 & V_82 [ V_32 ] ) == 0x20 ||
( 0xf0 & V_82 [ V_32 ] ) == 0x50 ) &&
! V_148 [ V_164 ] )
F_104 ( V_87 , V_164 ) ;
if ( V_82 [ V_32 ] == 0x30 && ! V_148 [ V_166 ] )
F_104 ( V_87 , V_166 ) ;
}
return 0 ;
}
static T_6 F_110 ( T_1 V_67 )
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
static T_6 F_111 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
int V_57 = 0 ;
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_112 ( V_82 , 10 , & V_67 ) )
return - V_81 ;
V_57 = F_110 ( V_67 ) ;
if ( V_57 < 0 )
return V_57 ;
return V_77 ;
}
static T_6 F_113 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
T_6 V_77 = 0 ;
V_77 = snprintf ( V_82 , V_92 , L_21 , V_169 -> V_100 ) ;
return V_77 ;
}
static int F_114 ( T_1 V_67 )
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
static T_6 F_115 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
int V_57 = 0 ;
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_112 ( V_82 , 10 , & V_67 ) )
return - V_81 ;
V_57 = F_114 ( V_67 ) ;
if ( V_57 < 0 )
return V_57 ;
return V_77 ;
}
static T_6 F_116 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
T_6 V_77 = 0 ;
V_77 = snprintf ( V_82 , V_92 , L_21 , V_169 -> V_171 ) ;
return V_77 ;
}
static int F_87 ( struct V_93 * V_94 ,
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
F_13 ( L_55 ) ;
return 0 ;
}
V_169 = F_52 ( sizeof( * V_169 ) , V_35 ) ;
if ( ! V_169 )
return - V_37 ;
V_169 -> V_65 = V_65 ;
if ( V_65 == 0x0137 )
V_169 -> V_170 = 0x0C00 ;
else
V_169 -> V_170 = 0x4000 ;
F_53 ( & V_169 -> V_172 . V_89 ) ;
V_169 -> V_172 . V_89 . V_39 = L_56 ;
V_169 -> V_172 . V_89 . V_100 = V_101 | V_173 ;
V_169 -> V_172 . V_102 = F_113 ;
V_169 -> V_172 . V_174 = F_111 ;
F_53 ( & V_169 -> V_175 . V_89 ) ;
V_169 -> V_175 . V_89 . V_39 = L_57 ;
V_169 -> V_175 . V_89 . V_100 = V_101 | V_173 ;
V_169 -> V_175 . V_102 = F_116 ;
V_169 -> V_175 . V_174 = F_115 ;
V_57 = F_54 ( & V_94 -> V_8 , & V_169 -> V_172 ) ;
if ( V_57 )
goto V_176;
V_57 = F_54 ( & V_94 -> V_8 , & V_169 -> V_175 ) ;
if ( V_57 )
goto V_177;
F_110 ( V_178 ) ;
F_114 ( V_179 ) ;
return 0 ;
V_177:
F_56 ( & V_94 -> V_8 , & V_169 -> V_172 ) ;
V_176:
F_47 ( V_169 ) ;
V_169 = NULL ;
return V_57 ;
}
static void F_95 ( struct V_93 * V_94 )
{
if ( V_169 ) {
int V_68 ;
F_56 ( & V_94 -> V_8 , & V_169 -> V_172 ) ;
F_56 ( & V_94 -> V_8 , & V_169 -> V_175 ) ;
F_58 ( V_169 -> V_65 ,
V_169 -> V_170 | 0x10000 , & V_68 ) ;
F_58 ( V_169 -> V_65 ,
V_169 -> V_170 + 0x200 , & V_68 ) ;
F_47 ( V_169 ) ;
V_169 = NULL ;
}
}
static void F_98 ( void )
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
static T_6 F_117 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
unsigned int V_68 , V_181 ;
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_112 ( V_82 , 10 , & V_67 ) )
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
static T_6 F_118 ( struct V_87 * V_8 ,
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
static T_6 F_119 ( struct V_87 * V_8 ,
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
V_182 -> V_185 [ 0 ] . V_89 . V_39 = L_58 ;
V_182 -> V_185 [ 0 ] . V_89 . V_100 = V_101 | V_173 ;
V_182 -> V_185 [ 0 ] . V_102 = F_118 ;
V_182 -> V_185 [ 0 ] . V_174 = F_117 ;
V_57 = F_54 ( & V_94 -> V_8 , & V_182 -> V_185 [ 0 ] ) ;
if ( V_57 )
goto V_176;
if ( V_65 == 0x0115 )
return 0 ;
F_53 ( & V_182 -> V_185 [ 1 ] . V_89 ) ;
V_182 -> V_185 [ 1 ] . V_89 . V_39 = L_59 ;
V_182 -> V_185 [ 1 ] . V_89 . V_100 = V_101 ;
V_182 -> V_185 [ 1 ] . V_102 = F_119 ;
V_57 = F_54 ( & V_94 -> V_8 , & V_182 -> V_185 [ 1 ] ) ;
if ( V_57 )
goto V_186;
return 0 ;
V_186:
F_56 ( & V_94 -> V_8 , & V_182 -> V_185 [ 0 ] ) ;
V_176:
F_47 ( V_182 ) ;
V_182 = NULL ;
return V_57 ;
}
static void F_90 ( struct V_93 * V_94 )
{
if ( V_182 ) {
F_56 ( & V_94 -> V_8 , & V_182 -> V_185 [ 0 ] ) ;
if ( V_182 -> V_65 != 0x0115 )
F_56 ( & V_94 -> V_8 , & V_182 -> V_185 [ 1 ] ) ;
F_47 ( V_182 ) ;
V_182 = NULL ;
}
}
static int F_120 ( unsigned short V_100 )
{
unsigned int V_68 ;
if ( ( V_100 && ! ( V_187 -> V_188 & V_100 ) ) || V_100 >= V_189 )
return - V_81 ;
if ( F_58 ( 0x0122 , V_100 << 0x10 | 0x0200 , & V_68 ) )
return - V_112 ;
V_187 -> V_100 = V_100 ;
return 0 ;
}
static int F_121 ( void )
{
unsigned int V_68 ;
if ( F_58 ( 0x0122 , 0x0100 , & V_68 ) )
return - V_112 ;
return V_68 & 0xff ;
}
static T_6 F_122 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
short V_190 ;
T_5 V_191 = 0 ;
for ( V_190 = 0 ; V_190 < V_189 ; V_190 ++ ) {
if ( ! V_190 || ( V_187 -> V_188 & V_190 ) )
V_191 += snprintf ( V_82 + V_191 , V_92 - V_191 , L_60 ,
V_192 [ V_190 ] ) ;
}
V_191 += snprintf ( V_82 + V_191 , V_92 - V_191 , L_13 ) ;
return V_191 ;
}
static T_6 F_123 ( struct V_87 * V_8 ,
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
if ( F_120 ( V_181 ) )
return - V_112 ;
return V_77 ;
}
static T_6 F_124 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
T_6 V_77 = 0 ;
int V_100 = F_121 () ;
if ( V_100 < 0 )
return V_100 ;
V_77 = snprintf ( V_82 , V_92 , L_61 , V_192 [ V_100 ] ) ;
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
F_46 ( L_62 ) ;
goto V_176;
}
V_57 = F_121 () ;
if ( V_57 < 0 ) {
F_46 ( L_63 ) ;
goto V_176;
}
V_187 -> V_100 = V_57 ;
F_53 ( & V_187 -> V_194 . V_89 ) ;
V_187 -> V_194 . V_89 . V_39 = L_64 ;
V_187 -> V_194 . V_89 . V_100 = V_101 ;
V_187 -> V_194 . V_102 = F_122 ;
F_53 ( & V_187 -> V_172 . V_89 ) ;
V_187 -> V_172 . V_89 . V_39 = L_65 ;
V_187 -> V_172 . V_89 . V_100 = V_101 | V_173 ;
V_187 -> V_172 . V_102 = F_124 ;
V_187 -> V_172 . V_174 = F_123 ;
V_57 = F_54 ( & V_94 -> V_8 , & V_187 -> V_194 ) ;
if ( V_57 )
goto V_176;
V_57 = F_54 ( & V_94 -> V_8 , & V_187 -> V_172 ) ;
if ( V_57 )
goto V_195;
return 0 ;
V_195:
F_56 ( & V_94 -> V_8 , & V_187 -> V_194 ) ;
V_176:
F_47 ( V_187 ) ;
V_187 = NULL ;
return V_57 ;
}
static void F_92 ( struct V_93 * V_94 )
{
if ( V_187 ) {
F_56 ( & V_94 -> V_8 , & V_187 -> V_194 ) ;
F_56 ( & V_94 -> V_8 , & V_187 -> V_172 ) ;
F_47 ( V_187 ) ;
V_187 = NULL ;
}
}
static void F_97 ( void )
{
unsigned int V_72 = F_121 () ;
if ( V_72 != V_187 -> V_100 )
F_120 ( V_187 -> V_100 ) ;
}
static T_6 F_125 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
unsigned int V_68 , V_196 ;
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_112 ( V_82 , 10 , & V_67 ) || V_67 > 1 )
return - V_81 ;
if ( strcmp ( V_89 -> V_89 . V_39 , L_66 ) == 0 )
V_196 = 2 ;
else if ( strcmp ( V_89 -> V_89 . V_39 , L_67 ) == 0 )
V_196 = 1 ;
else if ( strcmp ( V_89 -> V_89 . V_39 , L_68 ) == 0 )
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
static T_6 F_126 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
unsigned int V_196 ;
if ( strcmp ( V_89 -> V_89 . V_39 , L_66 ) == 0 )
V_196 = 2 ;
else if ( strcmp ( V_89 -> V_89 . V_39 , L_67 ) == 0 )
V_196 = 1 ;
else if ( strcmp ( V_89 -> V_89 . V_39 , L_68 ) == 0 )
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
V_197 -> V_185 [ 0 ] . V_89 . V_39 = L_66 ;
V_197 -> V_185 [ 0 ] . V_89 . V_100 = V_101 | V_173 ;
V_197 -> V_185 [ 0 ] . V_102 = F_126 ;
V_197 -> V_185 [ 0 ] . V_174 = F_125 ;
F_53 ( & V_197 -> V_185 [ 1 ] . V_89 ) ;
V_197 -> V_185 [ 1 ] . V_89 . V_39 = L_67 ;
V_197 -> V_185 [ 1 ] . V_89 . V_100 = V_101 | V_173 ;
V_197 -> V_185 [ 1 ] . V_102 = F_126 ;
V_197 -> V_185 [ 1 ] . V_174 = F_125 ;
F_53 ( & V_197 -> V_185 [ 2 ] . V_89 ) ;
V_197 -> V_185 [ 2 ] . V_89 . V_39 = L_68 ;
V_197 -> V_185 [ 2 ] . V_89 . V_100 = V_101 | V_173 ;
V_197 -> V_185 [ 2 ] . V_102 = F_126 ;
V_197 -> V_185 [ 2 ] . V_174 = F_125 ;
for ( V_32 = 0 ; V_32 < 3 ; V_32 ++ ) {
V_68 = F_54 ( & V_94 -> V_8 , & V_197 -> V_185 [ V_32 ] ) ;
if ( V_68 )
goto V_199;
}
return 0 ;
V_199:
for (; V_32 > 0 ; V_32 -- )
F_56 ( & V_94 -> V_8 , & V_197 -> V_185 [ V_32 ] ) ;
F_47 ( V_197 ) ;
V_197 = NULL ;
return V_68 ;
}
static void F_91 ( struct V_93 * V_94 )
{
int V_32 ;
if ( V_197 ) {
for ( V_32 = 0 ; V_32 < 3 ; V_32 ++ )
F_56 ( & V_94 -> V_8 , & V_197 -> V_185 [ V_32 ] ) ;
F_47 ( V_197 ) ;
V_197 = NULL ;
}
}
static T_6 F_127 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
unsigned int V_68 ;
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_112 ( V_82 , 10 , & V_67 ) || V_67 > 1 )
return - V_81 ;
if ( F_58 ( 0x0131 , V_67 << 0x10 | 0x0200 , & V_68 ) )
return - V_112 ;
return V_77 ;
}
static T_6 F_128 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
unsigned int V_68 ;
if ( F_58 ( 0x0131 , 0x0100 , & V_68 ) )
return - V_112 ;
return snprintf ( V_82 , V_92 , L_21 , V_68 & 0x01 ) ;
}
static int F_85 ( struct V_93 * V_94 )
{
unsigned int V_68 ;
if ( F_58 ( 0x0131 , 0x0000 , & V_68 ) || ! ( V_68 & 0x01 ) ) {
F_71 ( L_69 ) ;
return 0 ;
}
V_200 = F_52 ( sizeof( struct V_88 ) , V_35 ) ;
if ( ! V_200 )
return - V_37 ;
F_53 ( & V_200 -> V_89 ) ;
V_200 -> V_89 . V_39 = L_70 ;
V_200 -> V_89 . V_100 = V_101 | V_173 ;
V_200 -> V_102 = F_128 ;
V_200 -> V_174 = F_127 ;
V_68 = F_54 ( & V_94 -> V_8 , V_200 ) ;
if ( V_68 ) {
F_47 ( V_200 ) ;
V_200 = NULL ;
return V_68 ;
}
return 0 ;
}
static void F_93 ( struct V_93 * V_94 )
{
if ( V_200 ) {
F_56 ( & V_94 -> V_8 , V_200 ) ;
F_47 ( V_200 ) ;
V_200 = NULL ;
}
}
static T_6 F_129 ( struct V_87 * V_8 ,
struct V_88 * V_89 , const char * V_82 , T_5 V_77 )
{
unsigned int V_68 ;
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_112 ( V_82 , 10 , & V_67 ) || V_67 > 1 )
return - V_81 ;
if ( F_58 ( V_201 -> V_65 ,
( ! V_67 << 0x10 ) | 0x100 , & V_68 ) )
return - V_112 ;
return V_77 ;
}
static T_6 F_130 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
unsigned int V_68 ;
if ( F_58 ( V_201 -> V_65 , 0x000 , & V_68 ) )
return - V_81 ;
return snprintf ( V_82 , V_92 , L_21 , ! ( V_68 & 0x01 ) ) ;
}
static int F_81 ( struct V_93 * V_94 ,
unsigned int V_65 )
{
int V_57 = 0 ;
V_201 = F_52 ( sizeof( struct V_202 ) , V_35 ) ;
if ( ! V_201 )
return - V_37 ;
V_201 -> V_65 = V_65 ;
F_53 ( & V_201 -> V_89 . V_89 ) ;
V_201 -> V_89 . V_89 . V_39 = L_71 ;
V_201 -> V_89 . V_89 . V_100 = V_101 | V_173 ;
V_201 -> V_89 . V_102 = F_130 ;
V_201 -> V_89 . V_174 = F_129 ;
V_57 = F_54 ( & V_94 -> V_8 , & V_201 -> V_89 ) ;
if ( V_57 ) {
F_47 ( V_201 ) ;
V_201 = NULL ;
}
return V_57 ;
}
static void F_89 ( struct V_93 * V_94 )
{
if ( V_201 ) {
F_56 ( & V_94 -> V_8 , & V_201 -> V_89 ) ;
F_47 ( V_201 ) ;
V_201 = NULL ;
}
}
static void F_131 ( int V_65 ,
struct V_120 * V_118 )
{
T_3 V_104 ;
int V_32 ;
int V_203 = 0 ;
T_1 V_204 = 0xff , V_205 = 0x00 ;
unsigned char V_82 [ 32 ] = { 0 } ;
V_118 -> V_65 = V_65 ;
V_118 -> V_104 = 0 ;
V_118 -> V_206 = 0xff ;
V_104 = F_57 ( V_65 ) ;
V_32 = F_48 ( V_97 , L_53 , & V_104 , V_82 ,
32 ) ;
if ( V_32 < 0 )
return;
switch ( V_65 ) {
case 0x012f :
case 0x0137 :
V_203 = 9 ;
break;
case 0x143 :
V_203 = 16 ;
break;
}
for ( V_32 = 0 ; V_32 < V_203 && V_32 < F_12 ( V_82 ) ; V_32 ++ ) {
F_13 ( L_72 , V_82 [ V_32 ] ) ;
if ( ! V_82 [ V_32 ] )
break;
if ( V_82 [ V_32 ] > V_205 )
V_205 = V_82 [ V_32 ] ;
if ( V_82 [ V_32 ] < V_204 )
V_204 = V_82 [ V_32 ] ;
}
V_118 -> V_104 = V_204 ;
V_118 -> V_206 = V_205 ;
F_13 ( L_73 , V_118 -> V_104 ,
V_118 -> V_206 ) ;
}
static void F_132 ( void )
{
T_2 V_1 ;
int V_207 = 0 ;
const struct V_208 * V_209 = NULL ;
struct V_210 V_118 ;
if ( F_57 ( 0x12f ) >= 0 ) {
V_209 = & V_211 ;
V_212 . V_122 = 0x0100 ;
F_131 ( 0x12f , & V_212 ) ;
V_207 = V_212 . V_206 - V_212 . V_104 ;
} else if ( F_57 ( 0x137 ) >= 0 ) {
V_209 = & V_211 ;
V_212 . V_122 = 0x0100 ;
F_131 ( 0x137 , & V_212 ) ;
V_207 = V_212 . V_206 - V_212 . V_104 ;
} else if ( F_57 ( 0x143 ) >= 0 ) {
V_209 = & V_211 ;
V_212 . V_122 = 0x3000 ;
F_131 ( 0x143 , & V_212 ) ;
V_207 = V_212 . V_206 - V_212 . V_104 ;
} else if ( F_78 ( F_100 ( V_97 , L_23 ,
& V_1 ) ) ) {
V_209 = & V_213 ;
V_207 = V_108 - 1 ;
} else
return;
memset ( & V_118 , 0 , sizeof( struct V_210 ) ) ;
V_118 . type = V_214 ;
V_118 . V_207 = V_207 ;
V_212 . V_8 = F_133 ( L_74 , NULL ,
& V_212 ,
V_209 , & V_118 ) ;
if ( F_134 ( V_212 . V_8 ) ) {
F_46 ( L_75 ) ;
V_212 . V_8 = NULL ;
} else
V_212 . V_8 -> V_118 . V_119 =
V_209 -> V_215 ( V_212 . V_8 ) ;
}
static void F_135 ( void )
{
if ( V_212 . V_8 )
F_136 ( V_212 . V_8 ) ;
}
static int F_137 ( struct V_31 * V_87 )
{
T_4 V_72 ;
int V_68 = 0 ;
T_2 V_65 ;
struct V_109 * V_110 ;
F_71 ( L_76 , V_216 , V_217 ) ;
V_133 = V_87 ;
strcpy ( F_138 ( V_87 ) , L_77 ) ;
V_97 = V_87 -> V_65 ;
V_68 = F_139 ( V_87 ) ;
if ( ! V_68 && ! V_87 -> V_72 . V_218 ) {
F_13 ( L_78 ) ;
V_68 = - V_219 ;
goto V_220;
}
V_68 = F_34 () ;
if ( V_68 )
goto V_221;
if ( V_98 ) {
V_72 = F_140 ( V_222 ,
V_97 , 1 , F_77 ,
NULL , NULL , NULL ) ;
if ( F_44 ( V_72 ) ) {
F_46 ( L_79 ) ;
V_68 = - V_219 ;
goto V_221;
}
}
V_68 = F_16 ( V_87 ) ;
if ( V_68 ) {
F_20 ( L_80 ) ;
goto V_223;
}
if ( F_78 ( F_100 ( V_97 , L_47 ,
& V_65 ) ) ) {
int V_96 = 1 ;
if ( F_45 ( V_97 , L_47 , & V_96 , NULL ) )
F_13 ( L_48 ) ;
}
if ( F_78 ( F_100 ( V_97 , L_14 ,
& V_65 ) ) ) {
F_13 ( L_81 ) ;
V_68 = F_51 ( V_61 ) ;
if ( ! V_68 )
F_80 ( V_87 , V_61 ) ;
}
if ( F_141 () ) {
F_71 ( L_82 ) ;
} else {
F_132 () ;
}
for ( V_110 = V_145 ; V_110 -> V_39 ; ++ V_110 ) {
if ( ! V_98 && V_110 -> V_98 )
continue;
for (; V_110 -> V_111 && * V_110 -> V_111 ; ++ V_110 -> V_111 ) {
if ( F_78 ( F_100 ( V_97 ,
* V_110 -> V_111 ,
& V_65 ) ) ) {
F_13 ( L_83 ,
V_110 -> V_39 , * V_110 -> V_111 ) ;
V_110 -> V_99 . V_89 . V_100 |= V_101 ;
break;
}
}
for (; V_110 -> V_114 && * V_110 -> V_114 ; ++ V_110 -> V_114 ) {
if ( F_78 ( F_100 ( V_97 ,
* V_110 -> V_114 ,
& V_65 ) ) ) {
F_13 ( L_84 ,
V_110 -> V_39 , * V_110 -> V_114 ) ;
V_110 -> V_99 . V_89 . V_100 |= V_173 ;
break;
}
}
if ( V_110 -> V_99 . V_89 . V_100 != 0 ) {
V_68 =
F_54 ( & V_61 -> V_8 ,
& V_110 -> V_99 ) ;
if ( V_68 )
goto V_224;
}
}
return 0 ;
V_224:
for ( V_110 = V_145 ; V_110 -> V_39 ; ++ V_110 ) {
F_56 ( & V_61 -> V_8 , & V_110 -> V_99 ) ;
}
F_135 () ;
F_88 ( V_61 ) ;
F_55 ( V_61 ) ;
V_223:
F_31 () ;
V_221:
F_40 () ;
V_220:
F_94 () ;
return V_68 ;
}
static int F_142 ( struct V_31 * V_87 , int type )
{
struct V_109 * V_110 ;
F_135 () ;
V_133 = NULL ;
for ( V_110 = V_145 ; V_110 -> V_39 ; ++ V_110 ) {
F_56 ( & V_61 -> V_8 , & V_110 -> V_99 ) ;
}
F_88 ( V_61 ) ;
F_55 ( V_61 ) ;
F_40 () ;
F_31 () ;
F_13 ( V_216 L_85 ) ;
return 0 ;
}
static T_1 F_143 ( T_1 V_8 )
{
T_1 V_225 , V_226 ;
F_144 ( F_145 ( V_227 . V_228 -> V_229 . V_230 + 4 ) & 2 ,
V_231 ) ;
F_146 ( V_8 , V_227 . V_228 -> V_229 . V_230 + 4 ) ;
V_225 = F_145 ( V_227 . V_228 -> V_229 . V_230 + 4 ) ;
V_226 = F_145 ( V_227 . V_228 -> V_229 . V_230 ) ;
F_13 ( L_86 , V_8 , ( V_226 << 8 ) | V_225 ) ;
return V_226 ;
}
static T_1 F_147 ( T_1 V_8 , T_1 V_232 )
{
T_1 V_225 ;
F_144 ( F_145 ( V_227 . V_228 -> V_229 . V_230 + 4 ) & 2 ,
V_231 ) ;
F_146 ( V_8 , V_227 . V_228 -> V_229 . V_230 + 4 ) ;
F_144 ( F_145 ( V_227 . V_228 -> V_229 . V_230 + 4 ) & 2 ,
V_231 ) ;
F_146 ( V_232 , V_227 . V_228 -> V_229 . V_230 ) ;
V_225 = F_145 ( V_227 . V_228 -> V_229 . V_230 ) ;
F_13 ( L_87 , V_8 , V_232 , V_225 ) ;
return V_225 ;
}
static T_1 F_148 ( T_1 V_8 , T_1 V_232 , T_1 V_80 )
{
T_1 V_225 ;
F_144 ( F_145 ( V_227 . V_228 -> V_229 . V_230 + 4 ) & 2 , V_231 ) ;
F_146 ( V_8 , V_227 . V_228 -> V_229 . V_230 + 4 ) ;
F_144 ( F_145 ( V_227 . V_228 -> V_229 . V_230 + 4 ) & 2 , V_231 ) ;
F_146 ( V_232 , V_227 . V_228 -> V_229 . V_230 ) ;
F_144 ( F_145 ( V_227 . V_228 -> V_229 . V_230 + 4 ) & 2 , V_231 ) ;
F_146 ( V_80 , V_227 . V_228 -> V_229 . V_230 ) ;
V_225 = F_145 ( V_227 . V_228 -> V_229 . V_230 ) ;
F_13 ( L_88 ,
V_8 , V_232 , V_80 , V_225 ) ;
return V_225 ;
}
static int F_149 ( const T_1 V_233 , const T_1 V_234 )
{
if ( V_233 == 0x31 ) {
if ( V_234 == 0x5c || V_234 == 0x5f )
F_143 ( 0xA0 ) ;
else if ( V_234 == 0x61 )
F_143 ( 0xB3 ) ;
return 0 ;
}
return 1 ;
}
static void F_150 ( struct V_235 * V_8 )
{
struct V_236 * V_237 ;
V_237 = F_151 ( V_238 ,
V_239 , NULL ) ;
if ( V_237 ) {
V_8 -> V_240 = V_241 ;
V_8 -> V_242 = V_243 ;
V_8 -> V_244 = V_245 ;
goto V_60;
}
V_237 = F_151 ( V_238 ,
V_246 , NULL ) ;
if ( V_237 ) {
V_8 -> V_240 = V_247 ;
V_8 -> V_242 = V_248 ;
V_8 -> V_244 = V_249 ;
goto V_60;
}
V_237 = F_151 ( V_238 ,
V_250 , NULL ) ;
if ( V_237 ) {
V_8 -> V_240 = V_251 ;
V_8 -> V_252 = F_149 ;
V_8 -> V_242 = V_253 ;
V_8 -> V_244 = V_254 ;
goto V_60;
}
V_237 = F_151 ( V_238 ,
V_255 , NULL ) ;
if ( V_237 ) {
V_8 -> V_240 = V_251 ;
V_8 -> V_252 = F_149 ;
V_8 -> V_242 = V_253 ;
V_8 -> V_244 = V_254 ;
goto V_60;
}
V_237 = F_151 ( V_238 ,
V_256 , NULL ) ;
if ( V_237 ) {
V_8 -> V_240 = V_251 ;
V_8 -> V_252 = F_149 ;
V_8 -> V_242 = V_253 ;
V_8 -> V_244 = V_254 ;
goto V_60;
}
V_8 -> V_240 = V_247 ;
V_8 -> V_242 = V_248 ;
V_8 -> V_244 = V_249 ;
V_60:
if ( V_237 )
F_152 ( V_237 ) ;
F_71 ( L_89 ,
V_8 -> V_240 == V_241 ? 1 :
V_8 -> V_240 == V_247 ? 2 : 3 ) ;
}
static int F_153 ( void )
{
T_1 V_80 ;
V_80 = F_147 ( 0x8f , V_257 ) ;
return ( V_80 != 0xff && ( V_80 & V_258 ) ) ;
}
static int F_154 ( void )
{
if ( ! V_259 ) {
F_46 ( L_90 ) ;
return - V_219 ;
}
F_144 ( F_148 ( 0x90 , V_260 ,
V_261 ) ,
V_262 ) ;
if ( V_227 . V_263 ) {
F_147 ( 0x91 , 0 ) ;
V_227 . V_263 = 0 ;
}
return 0 ;
}
static int F_155 ( void )
{
int V_32 , V_264 , V_265 ;
if ( ! V_259 ) {
F_46 ( L_90 ) ;
return - V_219 ;
}
if ( V_227 . V_263 )
return 0 ;
for ( V_264 = 5 ; V_264 > 0 ; V_264 -- ) {
for ( V_265 = 0 ; V_265 < 100 && F_147 ( 0x91 , 0x1 ) ; V_265 ++ )
F_156 ( 10 ) ;
F_143 ( 0x93 ) ;
for ( V_32 = 400 ; V_32 > 0 ; V_32 -- ) {
if ( F_153 () )
break;
F_156 ( 10 ) ;
}
if ( V_32 )
break;
}
if ( V_264 == 0 ) {
F_46 ( L_91 ) ;
return - V_219 ;
}
F_144 ( F_148 ( 0x90 , V_266 ,
0x5a ) ,
V_262 ) ;
V_227 . V_263 = 1 ;
return 0 ;
}
int F_157 ( int V_267 , T_1 V_67 )
{
if ( ! V_259 )
return - V_112 ;
F_158 ( & V_227 . V_268 ) ;
switch ( V_267 ) {
case V_269 :
if ( V_67 )
F_155 () ;
else
F_154 () ;
break;
case V_270 :
F_144 ( F_148 ( 0x90 , V_271 , V_67 ) ,
V_262 ) ;
break;
case V_272 :
F_144 ( F_148 ( 0x90 , V_273 , V_67 ) ,
V_262 ) ;
break;
case V_274 :
F_144 ( F_148 ( 0x90 , V_275 , V_67 ) ,
V_262 ) ;
break;
case V_276 :
F_144 ( F_148 ( 0x90 , V_277 , V_67 ) ,
V_262 ) ;
break;
case V_278 :
F_144 ( F_148 ( 0x90 , V_279 , V_67 ) ,
V_262 ) ;
break;
case V_280 :
F_144 ( F_148 ( 0x90 , V_260 , V_67 ) ,
V_262 ) ;
break;
case V_281 :
F_144 ( F_148 ( 0x90 , V_282 , V_67 ) ,
V_262 ) ;
break;
default:
F_20 ( L_92 , V_267 ) ;
break;
}
F_159 ( & V_227 . V_268 ) ;
return 0 ;
}
static void F_160 ( T_1 V_283 )
{
V_283 = ! ! V_283 ;
if ( V_227 . V_284 == V_283 )
return;
F_147 ( 0xB0 , V_283 ) ;
F_143 ( 0x82 ) ;
V_227 . V_284 = V_283 ;
}
static T_6 F_161 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_112 ( V_82 , 10 , & V_67 ) )
return - V_81 ;
F_158 ( & V_227 . V_268 ) ;
F_160 ( V_67 ) ;
F_159 ( & V_227 . V_268 ) ;
return V_77 ;
}
static T_6 F_162 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
T_6 V_77 ;
F_158 ( & V_227 . V_268 ) ;
V_77 = snprintf ( V_82 , V_92 , L_21 , V_227 . V_284 ) ;
F_159 ( & V_227 . V_268 ) ;
return V_77 ;
}
static void F_163 ( T_1 V_283 )
{
V_283 = ! ! V_283 ;
if ( V_227 . V_285 == V_283 )
return;
F_147 ( 0x96 , V_283 ) ;
F_143 ( 0x82 ) ;
V_227 . V_285 = V_283 ;
}
static T_6 F_164 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_112 ( V_82 , 10 , & V_67 ) )
return - V_81 ;
F_158 ( & V_227 . V_268 ) ;
F_163 ( V_67 ) ;
F_159 ( & V_227 . V_268 ) ;
return V_77 ;
}
static T_6 F_165 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
T_6 V_77 = 0 ;
F_158 ( & V_227 . V_268 ) ;
V_77 = snprintf ( V_82 , V_92 , L_21 , V_227 . V_285 ) ;
F_159 ( & V_227 . V_268 ) ;
return V_77 ;
}
static int F_166 ( unsigned long V_67 )
{
return F_167 ( V_286 , V_67 ) ;
}
static int F_168 ( T_1 * V_67 )
{
return F_169 ( V_286 , V_67 ) ;
}
static T_6 F_170 ( struct V_87 * V_8 ,
struct V_88 * V_89 ,
const char * V_82 , T_5 V_77 )
{
unsigned long V_67 ;
if ( V_77 > 31 )
return - V_81 ;
if ( F_112 ( V_82 , 10 , & V_67 ) )
return - V_81 ;
if ( F_166 ( V_67 ) )
return - V_112 ;
return V_77 ;
}
static T_6 F_171 ( struct V_87 * V_8 ,
struct V_88 * V_89 , char * V_82 )
{
T_1 V_67 = 0 ;
if ( F_168 ( & V_67 ) )
return - V_112 ;
return snprintf ( V_82 , V_92 , L_21 , V_67 ) ;
}
static int F_172 ( int V_287 , struct V_288 * V_289 , int V_290 )
{
return F_173 ( V_287 , V_289 , V_290 , & V_291 . V_292 ) ;
}
static int F_174 ( struct V_293 * V_293 , struct V_288 * V_288 )
{
F_30 ( & V_291 . V_294 ) ;
return 0 ;
}
static int F_175 ( struct V_293 * V_293 , struct V_288 * V_288 )
{
unsigned long V_4 ;
F_2 ( & V_291 . V_6 , V_4 ) ;
if ( F_176 ( & V_291 . V_294 ) == 1 )
F_177 ( & V_291 . V_7 ) ;
F_9 ( & V_291 . V_6 , V_4 ) ;
return 0 ;
}
static T_6 F_178 ( struct V_288 * V_288 , char T_8 * V_295 ,
T_5 V_77 , T_9 * V_196 )
{
T_6 V_57 ;
unsigned char V_296 ;
if ( ( F_6 ( & V_291 . V_7 ) == 0 ) &&
( V_288 -> V_297 & V_298 ) )
return - V_299 ;
V_57 = F_179 ( V_291 . V_300 ,
F_6 ( & V_291 . V_7 ) != 0 ) ;
if ( V_57 )
return V_57 ;
while ( V_57 < V_77 &&
( F_180 ( & V_291 . V_7 , & V_296 , sizeof( V_296 ) ,
& V_291 . V_6 ) == sizeof( V_296 ) ) ) {
if ( F_181 ( V_296 , V_295 ++ ) )
return - V_301 ;
V_57 ++ ;
}
if ( V_57 > 0 ) {
struct V_293 * V_293 = V_288 -> V_302 . V_303 -> V_304 ;
V_293 -> V_305 = F_182 ( V_293 -> V_306 ) ;
}
return V_57 ;
}
static unsigned int F_183 ( struct V_288 * V_288 , T_10 * V_307 )
{
F_184 ( V_288 , & V_291 . V_300 , V_307 ) ;
if ( F_6 ( & V_291 . V_7 ) )
return V_308 | V_309 ;
return 0 ;
}
static int F_185 ( T_1 V_310 , T_11 * V_67 )
{
T_1 V_311 , V_312 ;
if ( F_169 ( V_310 , & V_311 ) )
return - 1 ;
if ( F_169 ( V_310 + 1 , & V_312 ) )
return - 1 ;
* V_67 = V_311 | ( V_312 << 8 ) ;
return 0 ;
}
static long F_186 ( struct V_288 * V_313 , unsigned int V_181 ,
unsigned long V_96 )
{
int V_57 = 0 ;
void T_8 * V_314 = ( void T_8 * ) V_96 ;
T_1 V_315 ;
T_11 V_316 ;
int V_67 ;
F_158 ( & V_227 . V_268 ) ;
switch ( V_181 ) {
case V_317 :
if ( V_212 . V_8 == NULL ) {
V_57 = - V_112 ;
break;
}
if ( F_45 ( V_97 , L_23 , NULL ,
& V_67 ) ) {
V_57 = - V_112 ;
break;
}
V_315 = ( ( V_67 & 0xff ) - 1 ) << 5 ;
if ( F_187 ( V_314 , & V_315 , sizeof( V_315 ) ) )
V_57 = - V_301 ;
break;
case V_318 :
if ( V_212 . V_8 == NULL ) {
V_57 = - V_112 ;
break;
}
if ( F_188 ( & V_315 , V_314 , sizeof( V_315 ) ) ) {
V_57 = - V_301 ;
break;
}
V_67 = ( V_315 >> 5 ) + 1 ;
if ( F_45 ( V_97 , L_22 , & V_67 ,
NULL ) ) {
V_57 = - V_112 ;
break;
}
V_212 . V_8 -> V_118 . V_119 =
F_66 ( V_212 . V_8 ) ;
break;
case V_319 :
if ( F_185 ( V_320 , & V_316 ) ) {
V_57 = - V_112 ;
break;
}
if ( F_187 ( V_314 , & V_316 , sizeof( V_316 ) ) )
V_57 = - V_301 ;
break;
case V_321 :
if ( F_185 ( V_322 , & V_316 ) ) {
V_57 = - V_112 ;
break;
}
if ( F_187 ( V_314 , & V_316 , sizeof( V_316 ) ) )
V_57 = - V_301 ;
break;
case V_323 :
if ( F_185 ( V_324 , & V_316 ) ) {
V_57 = - V_112 ;
break;
}
if ( F_187 ( V_314 , & V_316 , sizeof( V_316 ) ) )
V_57 = - V_301 ;
break;
case V_325 :
if ( F_185 ( V_326 , & V_316 ) ) {
V_57 = - V_112 ;
break;
}
if ( F_187 ( V_314 , & V_316 , sizeof( V_316 ) ) )
V_57 = - V_301 ;
break;
case V_327 :
if ( F_169 ( V_328 , & V_315 ) ) {
V_57 = - V_112 ;
break;
}
V_315 &= 0x07 ;
if ( F_187 ( V_314 , & V_315 , sizeof( V_315 ) ) )
V_57 = - V_301 ;
break;
case V_329 :
V_315 = V_227 . V_285 ;
if ( F_187 ( V_314 , & V_315 , sizeof( V_315 ) ) )
V_57 = - V_301 ;
break;
case V_330 :
if ( F_188 ( & V_315 , V_314 , sizeof( V_315 ) ) ) {
V_57 = - V_301 ;
break;
}
F_163 ( V_315 ) ;
break;
case V_331 :
if ( F_168 ( & V_315 ) ) {
V_57 = - V_112 ;
break;
}
if ( F_187 ( V_314 , & V_315 , sizeof( V_315 ) ) )
V_57 = - V_301 ;
break;
case V_332 :
if ( F_188 ( & V_315 , V_314 , sizeof( V_315 ) ) ) {
V_57 = - V_301 ;
break;
}
if ( F_166 ( V_315 ) )
V_57 = - V_112 ;
break;
case V_333 :
if ( F_169 ( V_334 , & V_315 ) ) {
V_57 = - V_112 ;
break;
}
if ( F_187 ( V_314 , & V_315 , sizeof( V_315 ) ) )
V_57 = - V_301 ;
break;
default:
V_57 = - V_81 ;
}
F_159 ( & V_227 . V_268 ) ;
return V_57 ;
}
static void F_189 ( T_1 V_12 )
{
F_15 ( & V_291 . V_7 , ( unsigned char * ) & V_12 ,
sizeof( V_12 ) , & V_291 . V_6 ) ;
F_190 ( & V_291 . V_292 , V_335 , V_336 ) ;
F_191 ( & V_291 . V_300 ) ;
}
static int F_192 ( void )
{
int error ;
F_18 ( & V_291 . V_6 ) ;
error =
F_19 ( & V_291 . V_7 , V_34 , V_35 ) ;
if ( error ) {
F_20 ( L_3 ) ;
return error ;
}
F_193 ( & V_291 . V_300 ) ;
if ( V_337 != - 1 )
V_338 . V_337 = V_337 ;
error = F_194 ( & V_338 ) ;
if ( error ) {
F_20 ( L_93 ) ;
goto V_38;
}
if ( V_337 == - 1 )
F_71 ( L_94 ,
V_338 . V_337 ) ;
return 0 ;
V_38:
F_29 ( & V_291 . V_7 ) ;
return error ;
}
static void F_195 ( void )
{
F_196 ( & V_338 ) ;
F_29 ( & V_291 . V_7 ) ;
}
static int F_192 ( void ) { return 0 ; }
static void F_195 ( void ) { }
static void F_189 ( T_1 V_12 ) { }
static T_4
F_197 ( struct V_339 * V_340 , void * V_137 )
{
T_7 V_32 ;
struct V_235 * V_8 = (struct V_235 * ) V_137 ;
switch ( V_340 -> type ) {
case V_341 :
{
struct V_342 * V_343 = F_52 ( sizeof( * V_343 ) , V_35 ) ;
if ( ! V_343 )
return V_344 ;
F_198 ( & V_343 -> V_345 , & V_8 -> V_346 ) ;
return V_142 ;
}
case V_347 :
return V_142 ;
case V_348 :
{
struct V_349 * V_350 = & V_340 -> V_127 . V_351 ;
struct V_352 * V_353 = NULL ;
if ( ! V_350 || ! V_350 -> V_354 ) {
F_13 ( L_95 ) ;
return V_142 ;
}
for ( V_32 = 0 ; V_32 < V_350 -> V_354 ; V_32 ++ ) {
if ( ! V_350 -> V_355 [ V_32 ] ) {
F_46 ( L_96 ,
V_350 -> V_355 [ V_32 ] ) ;
continue;
}
V_353 = F_52 ( sizeof( * V_353 ) ,
V_35 ) ;
if ( ! V_353 )
return V_344 ;
F_198 ( & V_353 -> V_345 , & V_8 -> V_355 ) ;
V_353 -> V_351 . V_356 = V_350 -> V_356 ;
V_353 -> V_351 . V_357 = V_350 -> V_357 ;
V_353 -> V_351 . V_358 = V_350 -> V_358 ;
V_353 -> V_351 . V_354 = 1 ;
V_353 -> V_351 . V_355 [ 0 ] = V_350 -> V_355 [ V_32 ] ;
}
return V_142 ;
}
case V_359 :
{
struct V_360 * V_361 = & V_340 -> V_127 . V_361 ;
struct V_342 * V_343 =
F_199 ( & V_8 -> V_346 , struct V_342 , V_345 ) ;
if ( ! V_361 ) {
F_13 ( L_97 ) ;
return V_142 ;
}
if ( ! V_343 -> V_229 . V_230 ) {
memcpy ( & V_343 -> V_229 , V_361 , sizeof( * V_361 ) ) ;
F_13 ( L_98 , V_343 -> V_229 . V_230 ,
V_343 -> V_229 . V_362 ) ;
}
else if ( ! V_343 -> V_363 . V_230 ) {
memcpy ( & V_343 -> V_363 , V_361 , sizeof( * V_361 ) ) ;
F_13 ( L_99 , V_343 -> V_363 . V_230 ,
V_343 -> V_363 . V_362 ) ;
}
else {
F_20 ( L_100 ) ;
return V_344 ;
}
return V_142 ;
}
default:
F_13 ( L_101 ,
V_340 -> type ) ;
case V_364 :
return V_142 ;
}
return V_365 ;
}
static int F_200 ( struct V_31 * V_87 )
{
int V_68 = 0 ;
T_4 V_72 = V_142 ;
if ( ! V_87 )
return - V_81 ;
F_13 ( L_102 ) ;
V_68 = F_139 ( V_87 ) ;
if ( V_68 ) {
F_46 ( L_103 ) ;
goto V_366;
}
if ( ! V_87 -> V_72 . V_367 )
F_13 ( L_104 ) ;
else
F_13 ( L_105 ) ;
F_13 ( L_106 , V_368 ) ;
V_72 = F_201 ( V_87 -> V_65 , V_368 ,
F_197 , & V_227 ) ;
if ( F_44 ( V_72 ) ) {
F_46 ( L_107 , V_368 ) ;
V_68 = - V_219 ;
}
V_366:
return V_68 ;
}
static int F_202 ( struct V_31 * V_87 )
{
T_4 V_57 = F_43 ( V_87 -> V_65 , L_108 , NULL ,
NULL ) ;
if ( F_44 ( V_57 ) && V_57 != V_369 )
return - V_370 ;
F_13 ( L_104 ) ;
return 0 ;
}
static int F_203 ( struct V_31 * V_87 ,
struct V_342 * V_343 , struct V_352 * V_351 )
{
T_4 V_72 ;
int V_68 = 0 ;
struct {
struct V_339 V_371 ;
struct V_339 V_372 ;
struct V_339 V_373 ;
struct V_339 V_374 ;
} * V_340 ;
struct V_69 V_82 = { 0 , NULL } ;
if ( ! V_343 || ! V_351 )
return - V_81 ;
V_340 = F_52 ( sizeof( * V_340 ) + 1 , V_35 ) ;
if ( ! V_340 )
return - V_37 ;
V_82 . V_86 = sizeof( * V_340 ) + 1 ;
V_82 . V_78 = V_340 ;
if ( V_227 . V_240 == V_241 ) {
V_340 -> V_371 . type = V_359 ;
V_340 -> V_371 . V_86 = sizeof( struct V_339 ) ;
memcpy ( & V_340 -> V_371 . V_127 . V_361 , & V_343 -> V_229 ,
sizeof( struct V_360 ) ) ;
V_340 -> V_372 . type = V_359 ;
V_340 -> V_372 . V_86 = sizeof( struct V_339 ) ;
memcpy ( & V_340 -> V_372 . V_127 . V_361 , & V_343 -> V_363 ,
sizeof( struct V_360 ) ) ;
V_340 -> V_373 . type = V_348 ;
V_340 -> V_373 . V_86 = sizeof( struct V_339 ) ;
memcpy ( & V_340 -> V_373 . V_127 . V_351 , & V_351 -> V_351 ,
sizeof( struct V_349 ) ) ;
V_340 -> V_373 . V_127 . V_351 . V_358 = V_375 ;
V_340 -> V_374 . type = V_364 ;
}
else {
V_340 -> V_371 . type = V_359 ;
V_340 -> V_371 . V_86 = sizeof( struct V_339 ) ;
memcpy ( & V_340 -> V_371 . V_127 . V_361 , & V_343 -> V_229 ,
sizeof( struct V_360 ) ) ;
V_340 -> V_372 . type = V_348 ;
V_340 -> V_372 . V_86 = sizeof( struct V_339 ) ;
memcpy ( & V_340 -> V_372 . V_127 . V_351 , & V_351 -> V_351 ,
sizeof( struct V_349 ) ) ;
V_340 -> V_372 . V_127 . V_351 . V_358 = V_375 ;
V_340 -> V_373 . type = V_364 ;
}
F_13 ( L_109 ) ;
V_72 = F_204 ( V_87 -> V_65 , & V_82 ) ;
if ( F_44 ( V_72 ) ) {
F_20 ( L_110 ) ;
V_68 = - V_219 ;
goto V_366;
}
F_143 ( 0x82 ) ;
F_147 ( 0x81 , 0xff ) ;
F_143 ( V_376 ? 0x92 : 0x82 ) ;
V_366:
F_47 ( V_340 ) ;
return V_68 ;
}
static T_12 V_352 ( int V_351 , void * V_377 )
{
int V_32 , V_264 ;
T_1 V_234 = 0 ;
T_1 V_233 = 0 ;
T_1 V_378 = 0 ;
struct V_235 * V_8 = (struct V_235 * ) V_377 ;
V_234 = F_145 ( V_8 -> V_228 -> V_229 . V_230 ) ;
if ( V_8 -> V_228 -> V_363 . V_230 )
V_233 = F_145 ( V_8 -> V_228 -> V_363 . V_230 ) ;
else
V_233 = F_145 ( V_8 -> V_228 -> V_229 . V_230 +
V_8 -> V_242 ) ;
F_13 ( L_111 ,
V_234 , V_233 , V_8 -> V_228 -> V_229 . V_230 ,
V_8 -> V_242 ) ;
if ( V_234 == 0x00 || V_234 == 0xff )
return V_379 ;
for ( V_32 = 0 ; V_8 -> V_244 [ V_32 ] . V_380 ; V_32 ++ ) {
if ( ( V_233 & V_8 -> V_244 [ V_32 ] . V_127 ) !=
V_8 -> V_244 [ V_32 ] . V_127 )
continue;
if ( ! ( V_380 & V_8 -> V_244 [ V_32 ] . V_380 ) )
continue;
for ( V_264 = 0 ; V_8 -> V_244 [ V_32 ] . V_381 [ V_264 ] . V_12 ; V_264 ++ ) {
if ( V_234 == V_8 -> V_244 [ V_32 ] . V_381 [ V_264 ] . V_127 ) {
V_378 =
V_8 -> V_244 [ V_32 ] . V_381 [ V_264 ] . V_12 ;
if ( ! V_378 )
return V_379 ;
goto V_382;
}
}
}
if ( V_8 -> V_252 && V_8 -> V_252 ( V_233 , V_234 ) == 0 )
return V_379 ;
F_13 ( L_112 ,
V_234 , V_233 , V_8 -> V_228 -> V_229 . V_230 ,
V_8 -> V_242 ) ;
return V_379 ;
V_382:
F_10 ( V_378 ) ;
F_74 ( V_8 -> V_383 , 1 , V_378 ) ;
F_189 ( V_378 ) ;
return V_379 ;
}
static int F_205 ( struct V_31 * V_87 , int type )
{
struct V_342 * V_361 , * V_384 ;
struct V_352 * V_351 , * V_385 ;
if ( F_202 ( V_87 ) ) {
F_20 ( L_113 ) ;
return - V_370 ;
}
F_206 ( V_227 . V_386 -> V_351 . V_355 [ 0 ] , & V_227 ) ;
F_207 ( V_227 . V_228 -> V_229 . V_230 ,
V_227 . V_228 -> V_229 . V_362 ) ;
if ( V_227 . V_228 -> V_363 . V_230 )
F_207 ( V_227 . V_228 -> V_363 . V_230 ,
V_227 . V_228 -> V_363 . V_362 ) ;
F_195 () ;
F_31 () ;
F_208 ( & V_61 -> V_8 . V_387 , & V_388 ) ;
F_40 () ;
F_209 (io, tmp_io, &spic_dev.ioports, list) {
F_210 ( & V_361 -> V_345 ) ;
F_47 ( V_361 ) ;
}
F_209 (irq, tmp_irq, &spic_dev.interrupts, list) {
F_210 ( & V_351 -> V_345 ) ;
F_47 ( V_351 ) ;
}
V_227 . V_228 = NULL ;
V_227 . V_386 = NULL ;
F_13 ( V_389 L_85 ) ;
return 0 ;
}
static int F_211 ( struct V_31 * V_87 )
{
int V_68 ;
struct V_342 * V_361 , * V_384 ;
struct V_352 * V_351 , * V_385 ;
F_71 ( L_76 , V_389 , V_217 ) ;
V_227 . V_383 = V_87 ;
strcpy ( F_138 ( V_87 ) , L_77 ) ;
F_150 ( & V_227 ) ;
F_212 ( & V_227 . V_268 ) ;
V_68 = F_200 ( V_87 ) ;
if ( V_68 ) {
F_20 ( L_114 ) ;
goto V_390;
}
V_68 = F_16 ( V_87 ) ;
if ( V_68 ) {
F_20 ( L_80 ) ;
goto V_390;
}
if ( F_192 () )
goto V_391;
F_213 (io, &spic_dev.ioports, list) {
if ( F_214 ( V_361 -> V_229 . V_230 , V_361 -> V_229 . V_362 ,
L_115 ) ) {
F_13 ( L_116 ,
V_361 -> V_229 . V_230 , V_361 -> V_229 . V_392 ,
V_361 -> V_229 . V_362 ) ;
if ( V_361 -> V_363 . V_230 ) {
if ( F_214 ( V_361 -> V_363 . V_230 ,
V_361 -> V_363 . V_362 ,
L_115 ) ) {
F_13 ( L_117 ,
V_361 -> V_363 . V_230 , V_361 -> V_363 . V_392 ,
V_361 -> V_363 . V_362 ) ;
V_227 . V_228 = V_361 ;
break;
}
else {
F_13 ( L_118
L_119 ,
V_361 -> V_363 . V_230 , V_361 -> V_363 . V_392 ,
V_361 -> V_363 . V_362 ) ;
F_207 ( V_361 -> V_229 . V_230 ,
V_361 -> V_229 . V_362 ) ;
}
}
else {
V_227 . V_228 = V_361 ;
break;
}
}
}
if ( ! V_227 . V_228 ) {
F_20 ( L_120 ) ;
V_68 = - V_219 ;
goto V_393;
}
F_213 (irq, &spic_dev.interrupts, list) {
if ( ! F_215 ( V_351 -> V_351 . V_355 [ 0 ] , V_352 ,
0 , L_6 , & V_227 ) ) {
F_13 ( L_121
L_122 ,
V_351 -> V_351 . V_355 [ 0 ] ,
V_351 -> V_351 . V_356 ,
V_351 -> V_351 . V_357 ,
V_351 -> V_351 . V_358 ) ;
V_227 . V_386 = V_351 ;
break;
}
}
if ( ! V_227 . V_386 ) {
F_20 ( L_123 ) ;
V_68 = - V_219 ;
goto V_394;
}
V_68 = F_203 ( V_87 , V_227 . V_228 , V_227 . V_386 ) ;
if ( V_68 ) {
F_20 ( L_124 ) ;
goto V_395;
}
V_227 . V_285 = - 1 ;
V_68 = F_34 () ;
if ( V_68 )
goto V_396;
V_68 = F_216 ( & V_61 -> V_8 . V_387 , & V_388 ) ;
if ( V_68 )
goto V_397;
return 0 ;
V_397:
F_40 () ;
V_396:
F_202 ( V_87 ) ;
V_395:
F_206 ( V_227 . V_386 -> V_351 . V_355 [ 0 ] , & V_227 ) ;
V_394:
F_207 ( V_227 . V_228 -> V_229 . V_230 ,
V_227 . V_228 -> V_229 . V_362 ) ;
if ( V_227 . V_228 -> V_363 . V_230 )
F_207 ( V_227 . V_228 -> V_363 . V_230 ,
V_227 . V_228 -> V_363 . V_362 ) ;
V_393:
F_195 () ;
V_391:
F_31 () ;
V_390:
F_209 (io, tmp_io, &spic_dev.ioports, list) {
F_210 ( & V_361 -> V_345 ) ;
F_47 ( V_361 ) ;
}
F_209 (irq, tmp_irq, &spic_dev.interrupts, list) {
F_210 ( & V_351 -> V_345 ) ;
F_47 ( V_351 ) ;
}
V_227 . V_228 = NULL ;
V_227 . V_386 = NULL ;
return V_68 ;
}
static int F_217 ( struct V_31 * V_87 , T_13 V_283 )
{
if ( F_202 ( V_87 ) )
return - V_370 ;
return 0 ;
}
static int F_218 ( struct V_31 * V_87 )
{
F_203 ( V_87 , V_227 . V_228 , V_227 . V_386 ) ;
return 0 ;
}
static int T_14 F_219 ( void )
{
int V_68 ;
if ( ! V_398 && F_220 ( V_399 ) ) {
V_68 = F_221 ( & V_400 ) ;
if ( V_68 ) {
F_20 ( L_125 ) ;
goto V_60;
}
V_401 = 1 ;
}
V_68 = F_221 ( & V_402 ) ;
if ( V_68 ) {
F_20 ( L_126 ) ;
goto V_403;
}
return 0 ;
V_403:
if ( V_401 )
F_222 ( & V_400 ) ;
V_60:
return V_68 ;
}
static void T_15 F_223 ( void )
{
F_222 ( & V_402 ) ;
if ( V_401 )
F_222 ( & V_400 ) ;
}

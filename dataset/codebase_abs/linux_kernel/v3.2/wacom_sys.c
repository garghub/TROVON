static int F_1 ( struct V_1 * V_2 , T_1 type , T_1 V_3 ,
void * V_4 , T_2 V_5 , unsigned int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_9 ;
do {
V_9 = F_3 ( V_8 , F_4 ( V_8 , 0 ) ,
V_10 ,
V_11 | V_12 ,
( type << 8 ) + V_3 ,
V_2 -> V_13 [ 0 ] . V_14 . V_15 ,
V_4 , V_5 , 100 ) ;
} while ( ( V_9 == - V_16 || V_9 == - V_17 ) && -- V_6 );
return V_9 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 type , T_1 V_3 ,
void * V_4 , T_2 V_5 , unsigned int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_9 ;
do {
V_9 = F_3 ( V_8 , F_6 ( V_8 , 0 ) ,
V_18 ,
V_11 | V_12 ,
( type << 8 ) + V_3 ,
V_2 -> V_13 [ 0 ] . V_14 . V_15 ,
V_4 , V_5 , 1000 ) ;
} while ( ( V_9 == - V_16 || V_9 == - V_17 ) && -- V_6 );
return V_9 ;
}
static void F_7 ( struct V_19 * V_19 )
{
struct V_20 * V_20 = V_19 -> V_21 ;
int V_9 ;
switch ( V_19 -> V_22 ) {
case 0 :
break;
case - V_23 :
case - V_24 :
case - V_25 :
F_8 ( L_1 , V_26 , V_19 -> V_22 ) ;
return;
default:
F_8 ( L_2 , V_26 , V_19 -> V_22 ) ;
goto exit;
}
F_9 ( & V_20 -> V_27 , V_19 -> V_28 ) ;
exit:
F_10 ( V_20 -> V_29 ) ;
V_9 = F_11 ( V_19 , V_30 ) ;
if ( V_9 )
F_12 ( L_3 ,
V_26 , V_9 ) ;
}
static int F_13 ( struct V_31 * V_8 )
{
struct V_20 * V_20 = F_14 ( V_8 ) ;
int V_9 = 0 ;
if ( F_15 ( V_20 -> V_2 ) < 0 )
return - V_32 ;
F_16 ( & V_20 -> V_33 ) ;
if ( F_11 ( V_20 -> V_34 , V_35 ) ) {
V_9 = - V_32 ;
goto V_36;
}
V_20 -> V_37 = true ;
V_20 -> V_2 -> V_38 = 1 ;
V_36:
F_17 ( & V_20 -> V_33 ) ;
F_18 ( V_20 -> V_2 ) ;
return V_9 ;
}
static void F_19 ( struct V_31 * V_8 )
{
struct V_20 * V_20 = F_14 ( V_8 ) ;
int V_39 ;
V_39 = F_15 ( V_20 -> V_2 ) ;
F_16 ( & V_20 -> V_33 ) ;
F_20 ( V_20 -> V_34 ) ;
V_20 -> V_37 = false ;
V_20 -> V_2 -> V_38 = 0 ;
F_17 ( & V_20 -> V_33 ) ;
if ( ! V_39 )
F_18 ( V_20 -> V_2 ) ;
}
static int F_21 ( struct V_1 * V_2 , struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
char V_44 = 0 ;
int V_45 = 0 ;
int V_46 = 0 , V_47 = V_48 , V_49 = 0 , V_50 = 0 ;
unsigned char * V_51 ;
V_51 = F_22 ( V_41 -> V_52 , V_35 ) ;
if ( ! V_51 )
return - V_53 ;
do {
V_45 = F_3 ( V_8 , F_4 ( V_8 , 0 ) ,
V_54 ,
V_12 | V_55 ,
V_56 << 8 ,
V_2 -> V_13 [ 0 ] . V_14 . V_15 ,
V_51 ,
V_41 -> V_52 ,
5000 ) ;
} while ( V_45 < 0 && V_44 ++ < V_57 );
if ( V_45 < 0 )
goto V_36;
for ( V_46 = 0 ; V_46 < V_41 -> V_52 ; V_46 ++ ) {
switch ( V_51 [ V_46 ] ) {
case V_58 :
switch ( V_51 [ V_46 + 1 ] ) {
case V_59 :
V_47 = V_60 ;
V_46 ++ ;
break;
case V_61 :
V_47 = V_62 ;
V_46 ++ ;
break;
}
break;
case V_63 :
switch ( V_51 [ V_46 + 1 ] ) {
case V_64 :
if ( V_47 == V_62 ) {
if ( V_49 ) {
V_43 -> V_65 = V_66 ;
if ( V_43 -> type == V_67 ) {
V_43 -> V_68 = V_69 ;
V_43 -> V_65 = V_70 ;
}
if ( V_43 -> type == V_71 ) {
V_43 -> V_68 = V_72 ;
V_43 -> V_65 = V_70 ;
V_43 -> V_73 =
F_23 ( & V_51 [ V_46 + 5 ] ) ;
V_43 -> V_74 =
F_23 ( & V_51 [ V_46 + 8 ] ) ;
V_46 += 15 ;
} else {
V_43 -> V_74 =
F_23 ( & V_51 [ V_46 + 3 ] ) ;
V_43 -> V_73 =
F_23 ( & V_51 [ V_46 + 6 ] ) ;
V_43 -> V_75 = V_51 [ V_46 + 9 ] ;
V_43 -> V_76 = V_51 [ V_46 + 11 ] ;
V_46 += 12 ;
}
} else if ( V_50 ) {
if ( V_43 -> type == V_67 )
V_43 -> V_68 = V_77 ;
if ( V_43 -> type == V_71 )
V_43 -> V_68 = V_78 ;
V_43 -> V_65 = V_79 ;
V_43 -> V_74 =
F_23 ( & V_51 [ V_46 + 3 ] ) ;
V_46 += 4 ;
}
}
break;
case V_80 :
if ( V_47 == V_62 ) {
if ( V_49 ) {
V_43 -> V_65 = V_66 ;
if ( V_43 -> type == V_67 ) {
V_43 -> V_68 = V_69 ;
V_43 -> V_65 = V_70 ;
V_43 -> V_81 =
F_23 ( & V_51 [ V_46 + 3 ] ) ;
V_43 -> V_82 =
F_23 ( & V_51 [ V_46 + 6 ] ) ;
V_46 += 7 ;
} else if ( V_43 -> type == V_71 ) {
V_43 -> V_68 = V_72 ;
V_43 -> V_65 = V_70 ;
V_43 -> V_82 =
F_23 ( & V_51 [ V_46 + 3 ] ) ;
V_43 -> V_81 =
F_23 ( & V_51 [ V_46 + 6 ] ) ;
V_46 += 12 ;
} else {
V_43 -> V_81 =
V_43 -> V_74 ;
V_43 -> V_82 =
F_23 ( & V_51 [ V_46 + 3 ] ) ;
V_46 += 4 ;
}
} else if ( V_50 ) {
if ( V_43 -> type == V_67 )
V_43 -> V_68 = V_77 ;
if ( V_43 -> type == V_71 )
V_43 -> V_68 = V_78 ;
V_43 -> V_65 = V_79 ;
V_43 -> V_81 =
F_23 ( & V_51 [ V_46 + 3 ] ) ;
V_46 += 4 ;
}
}
break;
case V_83 :
V_49 = 1 ;
V_46 ++ ;
break;
case V_84 :
V_50 = 1 ;
V_46 ++ ;
break;
}
break;
case V_85 :
V_49 = V_47 = 0 ;
break;
}
}
V_36:
V_45 = 0 ;
F_24 ( V_51 ) ;
return V_45 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
unsigned char * V_86 ;
int V_44 = 0 , V_87 = 2 ;
int error = - V_53 ;
V_86 = F_26 ( 4 , V_35 ) ;
if ( ! V_86 )
return error ;
if ( V_43 -> type == V_67 ) {
do {
V_86 [ 0 ] = 3 ;
V_86 [ 1 ] = 4 ;
V_86 [ 2 ] = 0 ;
V_86 [ 3 ] = 0 ;
V_87 = 3 ;
error = F_5 ( V_2 , V_88 ,
V_87 , V_86 , 4 , 1 ) ;
if ( error >= 0 )
error = F_1 ( V_2 ,
V_88 ,
V_87 , V_86 , 4 , 1 ) ;
} while ( ( error < 0 || V_86 [ 1 ] != 4 ) && V_44 ++ < V_57 );
} else if ( V_43 -> type != V_89 ) {
do {
V_86 [ 0 ] = 2 ;
V_86 [ 1 ] = 2 ;
error = F_5 ( V_2 , V_88 ,
V_87 , V_86 , 2 , 1 ) ;
if ( error >= 0 )
error = F_1 ( V_2 ,
V_88 ,
V_87 , V_86 , 2 , 1 ) ;
} while ( ( error < 0 || V_86 [ 1 ] != 2 ) && V_44 ++ < V_57 );
}
F_24 ( V_86 ) ;
return error < 0 ? error : 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
int error = 0 ;
struct V_90 * V_91 = V_2 -> V_92 ;
struct V_40 * V_41 ;
V_43 -> V_65 = V_79 ;
V_43 -> V_93 = 4 ;
V_43 -> V_94 = 4 ;
V_43 -> V_95 = 0 ;
V_43 -> V_96 = 0 ;
if ( ( V_43 -> type != V_89 ) && ( V_43 -> type != V_67 ) &&
( V_43 -> type != V_71 ) )
goto V_36;
if ( F_28 ( V_91 , V_97 , & V_41 ) ) {
if ( F_28 ( & V_91 -> V_98 [ 0 ] ,
V_56 , & V_41 ) ) {
F_29 ( L_4 ) ;
error = 1 ;
goto V_36;
}
}
error = F_21 ( V_2 , V_41 , V_43 ) ;
if ( error )
goto V_36;
V_36:
return error ;
}
static struct V_99 * F_30 ( struct V_7 * V_8 )
{
struct V_99 * V_100 ;
F_31 (data, &wacom_udev_list, list) {
if ( V_100 -> V_8 == V_8 ) {
F_32 ( & V_100 -> V_101 ) ;
return V_100 ;
}
}
return NULL ;
}
static int F_33 ( struct V_27 * V_20 ,
struct V_7 * V_8 )
{
struct V_99 * V_100 ;
int V_9 = 0 ;
F_16 ( & V_102 ) ;
V_100 = F_30 ( V_8 ) ;
if ( ! V_100 ) {
V_100 = F_22 ( sizeof( struct V_99 ) , V_35 ) ;
if ( ! V_100 ) {
V_9 = - V_53 ;
goto V_36;
}
F_34 ( & V_100 -> V_101 ) ;
V_100 -> V_8 = V_8 ;
F_35 ( & V_100 -> V_103 , & V_104 ) ;
}
V_20 -> V_105 = & V_100 -> V_105 ;
V_36:
F_17 ( & V_102 ) ;
return V_9 ;
}
static void F_36 ( struct V_101 * V_101 )
{
struct V_99 * V_100 =
F_37 ( V_101 , struct V_99 , V_101 ) ;
F_16 ( & V_102 ) ;
F_38 ( & V_100 -> V_103 ) ;
F_17 ( & V_102 ) ;
F_24 ( V_100 ) ;
}
static void F_39 ( struct V_27 * V_20 )
{
struct V_99 * V_100 ;
if ( V_20 -> V_105 ) {
V_100 = F_37 ( V_20 -> V_105 , struct V_99 , V_105 ) ;
F_40 ( & V_100 -> V_101 , F_36 ) ;
V_20 -> V_105 = NULL ;
}
}
static int F_41 ( struct V_20 * V_20 )
{
unsigned char * V_4 ;
int V_9 , V_106 = 0 ;
V_4 = F_22 ( 9 , V_35 ) ;
if ( ! V_4 )
return - V_53 ;
if ( V_20 -> V_27 . V_43 . type == V_107 )
V_106 = ( V_20 -> V_106 . V_108 [ 1 ] << 4 ) | 0x40 ;
V_106 |= V_20 -> V_106 . V_108 [ 0 ] | 0x4 ;
V_4 [ 0 ] = V_109 ;
V_4 [ 1 ] = V_106 ;
V_4 [ 2 ] = V_20 -> V_106 . V_110 ;
V_4 [ 3 ] = V_20 -> V_106 . V_111 ;
V_4 [ 4 ] = V_20 -> V_106 . V_112 ;
V_9 = F_5 ( V_20 -> V_2 , 0x03 , V_109 ,
V_4 , 9 , V_113 ) ;
F_24 ( V_4 ) ;
return V_9 ;
}
static int F_42 ( struct V_20 * V_20 , int V_114 , const void * V_115 )
{
unsigned char * V_4 ;
int V_46 , V_9 ;
V_4 = F_22 ( 259 , V_35 ) ;
if ( ! V_4 )
return - V_53 ;
V_4 [ 0 ] = V_116 ;
V_4 [ 1 ] = 1 ;
V_9 = F_5 ( V_20 -> V_2 , 0x03 , V_116 ,
V_4 , 2 , V_113 ) ;
if ( V_9 < 0 )
goto V_36;
V_4 [ 0 ] = V_117 ;
V_4 [ 1 ] = V_114 & 0x07 ;
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_4 [ 2 ] = V_46 ;
memcpy ( V_4 + 3 , V_115 + V_46 * 256 , 256 ) ;
V_9 = F_5 ( V_20 -> V_2 , 0x03 , V_117 ,
V_4 , 259 , V_113 ) ;
if ( V_9 < 0 )
break;
}
V_4 [ 0 ] = V_116 ;
V_4 [ 1 ] = 0 ;
F_5 ( V_20 -> V_2 , 0x03 , V_116 ,
V_4 , 2 , V_113 ) ;
V_36:
F_24 ( V_4 ) ;
return V_9 ;
}
static T_3 F_43 ( struct V_118 * V_8 , int V_119 ,
const char * V_4 , T_2 V_120 )
{
struct V_20 * V_20 = F_44 ( V_8 ) ;
unsigned int V_3 ;
int F_12 ;
F_12 = F_45 ( V_4 , 10 , & V_3 ) ;
if ( F_12 )
return F_12 ;
F_16 ( & V_20 -> V_33 ) ;
V_20 -> V_106 . V_108 [ V_119 ] = V_3 & 0x3 ;
F_12 = F_41 ( V_20 ) ;
F_17 ( & V_20 -> V_33 ) ;
return F_12 < 0 ? F_12 : V_120 ;
}
static T_3 F_46 ( struct V_20 * V_20 , T_1 * V_121 ,
const char * V_4 , T_2 V_120 )
{
unsigned int V_122 ;
int F_12 ;
F_12 = F_45 ( V_4 , 10 , & V_122 ) ;
if ( F_12 )
return F_12 ;
F_16 ( & V_20 -> V_33 ) ;
* V_121 = V_122 & 0x7f ;
F_12 = F_41 ( V_20 ) ;
F_17 ( & V_20 -> V_33 ) ;
return F_12 < 0 ? F_12 : V_120 ;
}
static T_3 F_47 ( struct V_118 * V_8 , int V_114 ,
const char * V_4 , T_2 V_120 )
{
struct V_20 * V_20 = F_44 ( V_8 ) ;
int F_12 ;
if ( V_120 != 1024 )
return - V_123 ;
F_16 ( & V_20 -> V_33 ) ;
F_12 = F_42 ( V_20 , V_114 , V_4 ) ;
F_17 ( & V_20 -> V_33 ) ;
return F_12 < 0 ? F_12 : V_120 ;
}
static int F_48 ( struct V_20 * V_20 )
{
int error ;
switch ( V_20 -> V_27 . V_43 . type ) {
case V_124 :
case V_125 :
V_20 -> V_106 . V_108 [ 0 ] = 0 ;
V_20 -> V_106 . V_108 [ 1 ] = 0 ;
V_20 -> V_106 . V_110 = 10 ;
V_20 -> V_106 . V_111 = 20 ;
V_20 -> V_106 . V_112 = 10 ;
error = F_49 ( & V_20 -> V_2 -> V_8 . V_126 ,
& V_127 ) ;
break;
case V_107 :
V_20 -> V_106 . V_108 [ 0 ] = 0 ;
V_20 -> V_106 . V_108 [ 1 ] = 0 ;
V_20 -> V_106 . V_110 = 0 ;
V_20 -> V_106 . V_111 = 0 ;
V_20 -> V_106 . V_112 = 0 ;
error = F_49 ( & V_20 -> V_2 -> V_8 . V_126 ,
& V_128 ) ;
break;
default:
return 0 ;
}
if ( error ) {
F_50 ( & V_20 -> V_2 -> V_8 ,
L_5 , error ) ;
return error ;
}
F_41 ( V_20 ) ;
return 0 ;
}
static void F_51 ( struct V_20 * V_20 )
{
switch ( V_20 -> V_27 . V_43 . type ) {
case V_124 :
case V_125 :
F_52 ( & V_20 -> V_2 -> V_8 . V_126 ,
& V_127 ) ;
break;
case V_107 :
F_52 ( & V_20 -> V_2 -> V_8 . V_126 ,
& V_128 ) ;
break;
}
}
static int F_53 ( struct V_1 * V_2 , const struct V_129 * V_3 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_130 * V_98 ;
struct V_20 * V_20 ;
struct V_27 * V_27 ;
struct V_42 * V_43 ;
struct V_31 * V_31 ;
int error ;
if ( ! V_3 -> V_131 )
return - V_123 ;
V_20 = F_22 ( sizeof( struct V_20 ) , V_35 ) ;
V_31 = F_54 () ;
if ( ! V_20 || ! V_31 ) {
error = - V_53 ;
goto V_132;
}
V_27 = & V_20 -> V_27 ;
V_27 -> V_43 = * ( (struct V_42 * ) V_3 -> V_131 ) ;
V_43 = & V_27 -> V_43 ;
if ( V_43 -> V_68 > V_133 ) {
error = - V_123 ;
goto V_132;
}
V_27 -> V_100 = F_55 ( V_8 , V_133 ,
V_35 , & V_20 -> V_134 ) ;
if ( ! V_27 -> V_100 ) {
error = - V_53 ;
goto V_132;
}
V_20 -> V_34 = F_56 ( 0 , V_35 ) ;
if ( ! V_20 -> V_34 ) {
error = - V_53 ;
goto V_135;
}
V_20 -> V_29 = V_8 ;
V_20 -> V_2 = V_2 ;
F_57 ( & V_20 -> V_33 ) ;
F_58 ( V_8 , V_20 -> V_136 , sizeof( V_20 -> V_136 ) ) ;
F_59 ( V_20 -> V_136 , L_6 , sizeof( V_20 -> V_136 ) ) ;
V_27 -> V_137 = V_31 ;
V_98 = & V_2 -> V_92 -> V_98 [ 0 ] . V_14 ;
error = F_27 ( V_2 , V_43 ) ;
if ( error )
goto V_138;
F_60 ( V_43 ) ;
F_61 ( V_27 -> V_139 , V_43 -> V_139 , sizeof( V_27 -> V_139 ) ) ;
if ( V_43 -> V_140 & V_141 ) {
F_59 ( V_27 -> V_139 ,
V_43 -> V_65 == V_79 ?
L_7 : L_8 ,
sizeof( V_27 -> V_139 ) ) ;
error = F_33 ( V_27 , V_8 ) ;
if ( error )
goto V_138;
}
V_31 -> V_139 = V_27 -> V_139 ;
V_31 -> V_8 . V_142 = & V_2 -> V_8 ;
V_31 -> V_37 = F_13 ;
V_31 -> V_143 = F_19 ;
F_62 ( V_8 , & V_31 -> V_3 ) ;
F_63 ( V_31 , V_20 ) ;
F_64 ( V_31 , V_27 ) ;
F_65 ( V_20 -> V_34 , V_8 ,
F_66 ( V_8 , V_98 -> V_144 ) ,
V_27 -> V_100 , V_43 -> V_68 ,
F_7 , V_20 , V_98 -> V_145 ) ;
V_20 -> V_34 -> V_146 = V_20 -> V_134 ;
V_20 -> V_34 -> V_147 |= V_148 ;
error = F_48 ( V_20 ) ;
if ( error )
goto V_149;
error = F_67 ( V_31 ) ;
if ( error )
goto V_150;
F_25 ( V_2 , V_43 ) ;
F_68 ( V_2 , V_20 ) ;
return 0 ;
V_150: F_51 ( V_20 ) ;
V_149: F_39 ( V_27 ) ;
V_138: F_69 ( V_20 -> V_34 ) ;
V_135: F_70 ( V_8 , V_133 , V_27 -> V_100 , V_20 -> V_134 ) ;
V_132: F_71 ( V_31 ) ;
F_24 ( V_20 ) ;
return error ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_20 * V_20 = F_73 ( V_2 ) ;
F_68 ( V_2 , NULL ) ;
F_20 ( V_20 -> V_34 ) ;
F_74 ( V_20 -> V_27 . V_137 ) ;
F_51 ( V_20 ) ;
F_69 ( V_20 -> V_34 ) ;
F_70 ( F_2 ( V_2 ) , V_133 ,
V_20 -> V_27 . V_100 , V_20 -> V_134 ) ;
F_39 ( & V_20 -> V_27 ) ;
F_24 ( V_20 ) ;
}
static int F_75 ( struct V_1 * V_2 , T_4 V_151 )
{
struct V_20 * V_20 = F_73 ( V_2 ) ;
F_16 ( & V_20 -> V_33 ) ;
F_20 ( V_20 -> V_34 ) ;
F_17 ( & V_20 -> V_33 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_20 * V_20 = F_73 ( V_2 ) ;
struct V_42 * V_43 = & V_20 -> V_27 . V_43 ;
int V_152 = 0 ;
F_16 ( & V_20 -> V_33 ) ;
F_25 ( V_2 , V_43 ) ;
F_41 ( V_20 ) ;
if ( V_20 -> V_37 && F_11 ( V_20 -> V_34 , V_153 ) < 0 )
V_152 = - V_32 ;
F_17 ( & V_20 -> V_33 ) ;
return V_152 ;
}
static int F_77 ( struct V_1 * V_2 )
{
return F_76 ( V_2 ) ;
}
static int T_5 F_78 ( void )
{
int V_45 ;
V_45 = F_79 ( & V_154 ) ;
if ( V_45 == 0 )
F_29 (KERN_INFO KBUILD_MODNAME L_9 DRIVER_VERSION L_10
DRIVER_DESC L_11 ) ;
return V_45 ;
}
static void T_6 F_80 ( void )
{
F_81 ( & V_154 ) ;
}

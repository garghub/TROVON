static int F_1 ( struct V_1 * V_2 , T_1 type , T_1 V_3 ,
void * V_4 , T_2 V_5 , unsigned int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_9 ;
do {
V_9 = F_3 ( V_8 , F_4 ( V_8 , 0 ) ,
V_10 ,
V_11 | V_12 |
V_13 ,
( type << 8 ) + V_3 ,
V_2 -> V_14 [ 0 ] . V_15 . V_16 ,
V_4 , V_5 , 100 ) ;
} while ( ( V_9 == - V_17 || V_9 == - V_18 ) && -- V_6 );
return V_9 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 type , T_1 V_3 ,
void * V_4 , T_2 V_5 , unsigned int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_9 ;
do {
V_9 = F_3 ( V_8 , F_6 ( V_8 , 0 ) ,
V_19 ,
V_12 | V_13 ,
( type << 8 ) + V_3 ,
V_2 -> V_14 [ 0 ] . V_15 . V_16 ,
V_4 , V_5 , 1000 ) ;
} while ( ( V_9 == - V_17 || V_9 == - V_18 ) && -- V_6 );
return V_9 ;
}
static void F_7 ( struct V_20 * V_20 )
{
struct V_21 * V_21 = V_20 -> V_22 ;
int V_9 ;
switch ( V_20 -> V_23 ) {
case 0 :
break;
case - V_24 :
case - V_25 :
case - V_26 :
F_8 ( L_1 , V_27 , V_20 -> V_23 ) ;
return;
default:
F_8 ( L_2 , V_27 , V_20 -> V_23 ) ;
goto exit;
}
F_9 ( & V_21 -> V_28 , V_20 -> V_29 ) ;
exit:
F_10 ( V_21 -> V_30 ) ;
V_9 = F_11 ( V_20 , V_31 ) ;
if ( V_9 )
F_12 ( L_3 ,
V_27 , V_9 ) ;
}
static int F_13 ( struct V_32 * V_8 )
{
struct V_21 * V_21 = F_14 ( V_8 ) ;
int V_9 = 0 ;
if ( F_15 ( V_21 -> V_2 ) < 0 )
return - V_33 ;
F_16 ( & V_21 -> V_34 ) ;
if ( F_11 ( V_21 -> V_35 , V_36 ) ) {
V_9 = - V_33 ;
goto V_37;
}
V_21 -> V_38 = true ;
V_21 -> V_2 -> V_39 = 1 ;
V_37:
F_17 ( & V_21 -> V_34 ) ;
F_18 ( V_21 -> V_2 ) ;
return V_9 ;
}
static void F_19 ( struct V_32 * V_8 )
{
struct V_21 * V_21 = F_14 ( V_8 ) ;
int V_40 ;
V_40 = F_15 ( V_21 -> V_2 ) ;
F_16 ( & V_21 -> V_34 ) ;
F_20 ( V_21 -> V_35 ) ;
V_21 -> V_38 = false ;
V_21 -> V_2 -> V_39 = 0 ;
F_17 ( & V_21 -> V_34 ) ;
if ( ! V_40 )
F_18 ( V_21 -> V_2 ) ;
}
static int F_21 ( unsigned char * V_41 ,
struct V_42 * V_43 )
{
int V_44 = 0 ;
if ( V_43 -> type == V_45 ) {
V_43 -> V_46 = V_47 ;
V_43 -> V_48 = V_49 ;
V_43 -> V_50 =
( V_43 -> V_51 * V_43 -> V_52 ) / 100 ;
V_43 -> V_53 =
( V_43 -> V_54 * V_43 -> V_55 ) / 100 ;
V_43 -> V_51 = V_43 -> V_54 =
F_22 ( & V_41 [ 10 ] ) ;
V_44 = 11 ;
}
return V_44 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_56 * V_57 ,
struct V_42 * V_43 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
char V_58 = 0 ;
int V_59 = 0 ;
int V_60 = 0 , V_61 = V_62 , V_63 = 0 , V_64 = 0 ;
unsigned char * V_41 ;
V_41 = F_24 ( V_57 -> V_65 , V_36 ) ;
if ( ! V_41 )
return - V_66 ;
do {
V_59 = F_3 ( V_8 , F_4 ( V_8 , 0 ) ,
V_67 ,
V_13 | V_11 ,
V_68 << 8 ,
V_2 -> V_14 [ 0 ] . V_15 . V_16 ,
V_41 ,
V_57 -> V_65 ,
5000 ) ;
} while ( V_59 < 0 && V_58 ++ < V_69 );
if ( V_59 < 0 )
goto V_37;
for ( V_60 = 0 ; V_60 < V_57 -> V_65 ; V_60 ++ ) {
switch ( V_41 [ V_60 ] ) {
case V_70 :
switch ( V_41 [ V_60 + 1 ] ) {
case V_71 :
V_61 = V_72 ;
V_60 ++ ;
break;
case V_73 :
V_61 = V_74 ;
V_60 ++ ;
break;
}
break;
case V_75 :
switch ( V_41 [ V_60 + 1 ] ) {
case V_76 :
if ( V_61 == V_74 ) {
if ( V_63 ) {
V_43 -> V_48 = V_77 ;
if ( V_43 -> type == V_78 ) {
V_43 -> V_46 = V_79 ;
V_43 -> V_48 = V_49 ;
}
if ( V_43 -> type == V_45 ) {
V_43 -> V_46 = V_80 ;
V_43 -> V_48 = V_49 ;
V_43 -> V_50 =
F_22 ( & V_41 [ V_60 + 5 ] ) ;
V_43 -> V_51 =
F_22 ( & V_41 [ V_60 + 8 ] ) ;
V_60 += 15 ;
} else {
V_43 -> V_51 =
F_22 ( & V_41 [ V_60 + 3 ] ) ;
V_43 -> V_50 =
F_22 ( & V_41 [ V_60 + 6 ] ) ;
V_43 -> V_81 = V_41 [ V_60 + 9 ] ;
V_43 -> V_82 = V_41 [ V_60 + 11 ] ;
V_60 += 12 ;
}
} else if ( V_64 ) {
if ( V_43 -> type == V_78 )
V_43 -> V_46 = V_83 ;
V_43 -> V_48 = V_84 ;
V_43 -> V_51 =
F_22 ( & V_41 [ V_60 + 3 ] ) ;
V_60 += 4 ;
}
}
break;
case V_85 :
if ( V_61 == V_74 ) {
if ( V_63 ) {
V_43 -> V_48 = V_77 ;
if ( V_43 -> type == V_78 ) {
V_43 -> V_46 = V_79 ;
V_43 -> V_48 = V_49 ;
V_43 -> V_54 =
F_22 ( & V_41 [ V_60 + 3 ] ) ;
V_43 -> V_53 =
F_22 ( & V_41 [ V_60 + 6 ] ) ;
V_60 += 7 ;
} else if ( V_43 -> type == V_45 ) {
V_43 -> V_46 = V_80 ;
V_43 -> V_48 = V_49 ;
V_43 -> V_53 =
F_22 ( & V_41 [ V_60 + 3 ] ) ;
V_43 -> V_54 =
F_22 ( & V_41 [ V_60 + 6 ] ) ;
V_60 += 12 ;
} else {
V_43 -> V_54 =
V_43 -> V_51 ;
V_43 -> V_53 =
F_22 ( & V_41 [ V_60 + 3 ] ) ;
V_60 += 4 ;
}
} else if ( V_64 ) {
if ( V_43 -> type == V_78 )
V_43 -> V_46 = V_83 ;
V_43 -> V_48 = V_84 ;
V_43 -> V_54 =
F_22 ( & V_41 [ V_60 + 3 ] ) ;
V_60 += 4 ;
}
}
break;
case V_86 :
V_63 = 1 ;
V_60 ++ ;
break;
case V_87 :
V_64 = 1 ;
V_60 ++ ;
break;
}
break;
case V_88 :
V_63 = V_61 = 0 ;
break;
case V_89 :
V_60 ++ ;
switch ( V_41 [ V_60 ] ) {
case V_90 :
V_60 += F_21 ( & V_41 [ V_60 ] ,
V_43 ) ;
break;
}
break;
}
}
V_37:
V_59 = 0 ;
F_25 ( V_41 ) ;
return V_59 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
unsigned char * V_91 ;
int V_58 = 0 , V_92 = 2 ;
int error = - V_66 ;
V_91 = F_27 ( 4 , V_36 ) ;
if ( ! V_91 )
return error ;
if ( V_43 -> type == V_78 ) {
do {
V_91 [ 0 ] = 3 ;
V_91 [ 1 ] = 4 ;
V_91 [ 2 ] = 0 ;
V_91 [ 3 ] = 0 ;
V_92 = 3 ;
error = F_5 ( V_2 , V_93 ,
V_92 , V_91 , 4 , 1 ) ;
if ( error >= 0 )
error = F_1 ( V_2 ,
V_93 ,
V_92 , V_91 , 4 , 1 ) ;
} while ( ( error < 0 || V_91 [ 1 ] != 4 ) && V_58 ++ < V_69 );
} else if ( V_43 -> type != V_94 &&
V_43 -> V_48 == V_84 ) {
do {
V_91 [ 0 ] = 2 ;
V_91 [ 1 ] = 2 ;
error = F_5 ( V_2 , V_93 ,
V_92 , V_91 , 2 , 1 ) ;
if ( error >= 0 )
error = F_1 ( V_2 ,
V_93 ,
V_92 , V_91 , 2 , 1 ) ;
} while ( ( error < 0 || V_91 [ 1 ] != 2 ) && V_58 ++ < V_69 );
}
F_25 ( V_91 ) ;
return error < 0 ? error : 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
int error = 0 ;
struct V_95 * V_96 = V_2 -> V_97 ;
struct V_56 * V_57 ;
V_43 -> V_48 = V_84 ;
V_43 -> V_98 = 4 ;
V_43 -> V_99 = 4 ;
V_43 -> V_100 = 0 ;
V_43 -> V_101 = 0 ;
if ( ( V_43 -> type != V_94 ) && ( V_43 -> type != V_78 ) &&
( V_43 -> type != V_45 ) )
goto V_37;
if ( F_29 ( V_96 , V_102 , & V_57 ) ) {
if ( F_29 ( & V_96 -> V_103 [ 0 ] ,
V_68 , & V_57 ) ) {
F_30 ( L_4 ) ;
error = 1 ;
goto V_37;
}
}
error = F_23 ( V_2 , V_57 , V_43 ) ;
if ( error )
goto V_37;
V_37:
return error ;
}
static struct V_104 * F_31 ( struct V_7 * V_8 )
{
struct V_104 * V_105 ;
F_32 (data, &wacom_udev_list, list) {
if ( V_105 -> V_8 == V_8 ) {
F_33 ( & V_105 -> V_106 ) ;
return V_105 ;
}
}
return NULL ;
}
static int F_34 ( struct V_28 * V_21 ,
struct V_7 * V_8 )
{
struct V_104 * V_105 ;
int V_9 = 0 ;
F_16 ( & V_107 ) ;
V_105 = F_31 ( V_8 ) ;
if ( ! V_105 ) {
V_105 = F_24 ( sizeof( struct V_104 ) , V_36 ) ;
if ( ! V_105 ) {
V_9 = - V_66 ;
goto V_37;
}
F_35 ( & V_105 -> V_106 ) ;
V_105 -> V_8 = V_8 ;
F_36 ( & V_105 -> V_108 , & V_109 ) ;
}
V_21 -> V_110 = & V_105 -> V_110 ;
V_37:
F_17 ( & V_107 ) ;
return V_9 ;
}
static void F_37 ( struct V_106 * V_106 )
{
struct V_104 * V_105 =
F_38 ( V_106 , struct V_104 , V_106 ) ;
F_16 ( & V_107 ) ;
F_39 ( & V_105 -> V_108 ) ;
F_17 ( & V_107 ) ;
F_25 ( V_105 ) ;
}
static void F_40 ( struct V_28 * V_21 )
{
struct V_104 * V_105 ;
if ( V_21 -> V_110 ) {
V_105 = F_38 ( V_21 -> V_110 , struct V_104 , V_110 ) ;
F_41 ( & V_105 -> V_106 , F_37 ) ;
V_21 -> V_110 = NULL ;
}
}
static int F_42 ( struct V_21 * V_21 )
{
unsigned char * V_4 ;
int V_9 , V_111 = 0 ;
V_4 = F_24 ( 9 , V_36 ) ;
if ( ! V_4 )
return - V_66 ;
if ( V_21 -> V_28 . V_43 . type == V_112 ||
V_21 -> V_28 . V_43 . type == V_113 )
V_111 = ( V_21 -> V_111 . V_114 [ 1 ] << 4 ) | 0x40 ;
V_111 |= V_21 -> V_111 . V_114 [ 0 ] | 0x4 ;
V_4 [ 0 ] = V_115 ;
V_4 [ 1 ] = V_111 ;
V_4 [ 2 ] = V_21 -> V_111 . V_116 ;
V_4 [ 3 ] = V_21 -> V_111 . V_117 ;
V_4 [ 4 ] = V_21 -> V_111 . V_118 ;
V_9 = F_5 ( V_21 -> V_2 , 0x03 , V_115 ,
V_4 , 9 , V_119 ) ;
F_25 ( V_4 ) ;
return V_9 ;
}
static int F_43 ( struct V_21 * V_21 , int V_120 , const void * V_121 )
{
unsigned char * V_4 ;
int V_60 , V_9 ;
V_4 = F_24 ( 259 , V_36 ) ;
if ( ! V_4 )
return - V_66 ;
V_4 [ 0 ] = V_122 ;
V_4 [ 1 ] = 1 ;
V_9 = F_5 ( V_21 -> V_2 , 0x03 , V_122 ,
V_4 , 2 , V_119 ) ;
if ( V_9 < 0 )
goto V_37;
V_4 [ 0 ] = V_123 ;
V_4 [ 1 ] = V_120 & 0x07 ;
for ( V_60 = 0 ; V_60 < 4 ; V_60 ++ ) {
V_4 [ 2 ] = V_60 ;
memcpy ( V_4 + 3 , V_121 + V_60 * 256 , 256 ) ;
V_9 = F_5 ( V_21 -> V_2 , 0x03 , V_123 ,
V_4 , 259 , V_119 ) ;
if ( V_9 < 0 )
break;
}
V_4 [ 0 ] = V_122 ;
V_4 [ 1 ] = 0 ;
F_5 ( V_21 -> V_2 , 0x03 , V_122 ,
V_4 , 2 , V_119 ) ;
V_37:
F_25 ( V_4 ) ;
return V_9 ;
}
static T_3 F_44 ( struct V_124 * V_8 , int V_125 ,
const char * V_4 , T_2 V_126 )
{
struct V_21 * V_21 = F_45 ( V_8 ) ;
unsigned int V_3 ;
int F_12 ;
F_12 = F_46 ( V_4 , 10 , & V_3 ) ;
if ( F_12 )
return F_12 ;
F_16 ( & V_21 -> V_34 ) ;
V_21 -> V_111 . V_114 [ V_125 ] = V_3 & 0x3 ;
F_12 = F_42 ( V_21 ) ;
F_17 ( & V_21 -> V_34 ) ;
return F_12 < 0 ? F_12 : V_126 ;
}
static T_3 F_47 ( struct V_21 * V_21 , T_1 * V_127 ,
const char * V_4 , T_2 V_126 )
{
unsigned int V_128 ;
int F_12 ;
F_12 = F_46 ( V_4 , 10 , & V_128 ) ;
if ( F_12 )
return F_12 ;
F_16 ( & V_21 -> V_34 ) ;
* V_127 = V_128 & 0x7f ;
F_12 = F_42 ( V_21 ) ;
F_17 ( & V_21 -> V_34 ) ;
return F_12 < 0 ? F_12 : V_126 ;
}
static T_3 F_48 ( struct V_124 * V_8 , int V_120 ,
const char * V_4 , T_2 V_126 )
{
struct V_21 * V_21 = F_45 ( V_8 ) ;
int F_12 ;
if ( V_126 != 1024 )
return - V_129 ;
F_16 ( & V_21 -> V_34 ) ;
F_12 = F_43 ( V_21 , V_120 , V_4 ) ;
F_17 ( & V_21 -> V_34 ) ;
return F_12 < 0 ? F_12 : V_126 ;
}
static int F_49 ( struct V_21 * V_21 )
{
int error ;
switch ( V_21 -> V_28 . V_43 . type ) {
case V_130 :
case V_131 :
V_21 -> V_111 . V_114 [ 0 ] = 0 ;
V_21 -> V_111 . V_114 [ 1 ] = 0 ;
V_21 -> V_111 . V_116 = 10 ;
V_21 -> V_111 . V_117 = 20 ;
V_21 -> V_111 . V_118 = 10 ;
error = F_50 ( & V_21 -> V_2 -> V_8 . V_132 ,
& V_133 ) ;
break;
case V_113 :
case V_112 :
V_21 -> V_111 . V_114 [ 0 ] = 0 ;
V_21 -> V_111 . V_114 [ 1 ] = 0 ;
V_21 -> V_111 . V_116 = 0 ;
V_21 -> V_111 . V_117 = 0 ;
V_21 -> V_111 . V_118 = 0 ;
error = F_50 ( & V_21 -> V_2 -> V_8 . V_132 ,
& V_134 ) ;
break;
default:
return 0 ;
}
if ( error ) {
F_51 ( & V_21 -> V_2 -> V_8 ,
L_5 , error ) ;
return error ;
}
F_42 ( V_21 ) ;
return 0 ;
}
static void F_52 ( struct V_21 * V_21 )
{
switch ( V_21 -> V_28 . V_43 . type ) {
case V_130 :
case V_131 :
F_53 ( & V_21 -> V_2 -> V_8 . V_132 ,
& V_133 ) ;
break;
case V_113 :
case V_112 :
F_53 ( & V_21 -> V_2 -> V_8 . V_132 ,
& V_134 ) ;
break;
}
}
static int F_54 ( struct V_1 * V_2 , const struct V_135 * V_3 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_136 * V_103 ;
struct V_21 * V_21 ;
struct V_28 * V_28 ;
struct V_42 * V_43 ;
struct V_32 * V_32 ;
int error ;
if ( ! V_3 -> V_137 )
return - V_129 ;
V_21 = F_24 ( sizeof( struct V_21 ) , V_36 ) ;
V_32 = F_55 () ;
if ( ! V_21 || ! V_32 ) {
error = - V_66 ;
goto V_138;
}
V_28 = & V_21 -> V_28 ;
V_28 -> V_43 = * ( (struct V_42 * ) V_3 -> V_137 ) ;
V_43 = & V_28 -> V_43 ;
if ( V_43 -> V_46 > V_139 ) {
error = - V_129 ;
goto V_138;
}
V_28 -> V_105 = F_56 ( V_8 , V_139 ,
V_36 , & V_21 -> V_140 ) ;
if ( ! V_28 -> V_105 ) {
error = - V_66 ;
goto V_138;
}
V_21 -> V_35 = F_57 ( 0 , V_36 ) ;
if ( ! V_21 -> V_35 ) {
error = - V_66 ;
goto V_141;
}
V_21 -> V_30 = V_8 ;
V_21 -> V_2 = V_2 ;
F_58 ( & V_21 -> V_34 ) ;
F_59 ( V_8 , V_21 -> V_142 , sizeof( V_21 -> V_142 ) ) ;
F_60 ( V_21 -> V_142 , L_6 , sizeof( V_21 -> V_142 ) ) ;
V_28 -> V_143 = V_32 ;
V_103 = & V_2 -> V_97 -> V_103 [ 0 ] . V_15 ;
error = F_28 ( V_2 , V_43 ) ;
if ( error )
goto V_144;
F_61 ( V_43 ) ;
F_62 ( V_28 -> V_145 , V_43 -> V_145 , sizeof( V_28 -> V_145 ) ) ;
if ( V_43 -> V_146 & V_147 ) {
F_60 ( V_28 -> V_145 ,
V_43 -> V_48 == V_84 ?
L_7 : L_8 ,
sizeof( V_28 -> V_145 ) ) ;
error = F_34 ( V_28 , V_8 ) ;
if ( error )
goto V_144;
}
V_32 -> V_145 = V_28 -> V_145 ;
V_32 -> V_8 . V_148 = & V_2 -> V_8 ;
V_32 -> V_38 = F_13 ;
V_32 -> V_149 = F_19 ;
F_63 ( V_8 , & V_32 -> V_3 ) ;
F_64 ( V_32 , V_21 ) ;
F_65 ( V_32 , V_28 ) ;
F_66 ( V_21 -> V_35 , V_8 ,
F_67 ( V_8 , V_103 -> V_150 ) ,
V_28 -> V_105 , V_43 -> V_46 ,
F_7 , V_21 , V_103 -> V_151 ) ;
V_21 -> V_35 -> V_152 = V_21 -> V_140 ;
V_21 -> V_35 -> V_153 |= V_154 ;
error = F_49 ( V_21 ) ;
if ( error )
goto V_155;
error = F_68 ( V_32 ) ;
if ( error )
goto V_156;
F_26 ( V_2 , V_43 ) ;
F_69 ( V_2 , V_21 ) ;
return 0 ;
V_156: F_52 ( V_21 ) ;
V_155: F_40 ( V_28 ) ;
V_144: F_70 ( V_21 -> V_35 ) ;
V_141: F_71 ( V_8 , V_139 , V_28 -> V_105 , V_21 -> V_140 ) ;
V_138: F_72 ( V_32 ) ;
F_25 ( V_21 ) ;
return error ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_21 * V_21 = F_74 ( V_2 ) ;
F_69 ( V_2 , NULL ) ;
F_20 ( V_21 -> V_35 ) ;
F_75 ( V_21 -> V_28 . V_143 ) ;
F_52 ( V_21 ) ;
F_70 ( V_21 -> V_35 ) ;
F_71 ( F_2 ( V_2 ) , V_139 ,
V_21 -> V_28 . V_105 , V_21 -> V_140 ) ;
F_40 ( & V_21 -> V_28 ) ;
F_25 ( V_21 ) ;
}
static int F_76 ( struct V_1 * V_2 , T_4 V_157 )
{
struct V_21 * V_21 = F_74 ( V_2 ) ;
F_16 ( & V_21 -> V_34 ) ;
F_20 ( V_21 -> V_35 ) ;
F_17 ( & V_21 -> V_34 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_21 * V_21 = F_74 ( V_2 ) ;
struct V_42 * V_43 = & V_21 -> V_28 . V_43 ;
int V_158 = 0 ;
F_16 ( & V_21 -> V_34 ) ;
F_26 ( V_2 , V_43 ) ;
F_42 ( V_21 ) ;
if ( V_21 -> V_38 && F_11 ( V_21 -> V_35 , V_159 ) < 0 )
V_158 = - V_33 ;
F_17 ( & V_21 -> V_34 ) ;
return V_158 ;
}
static int F_78 ( struct V_1 * V_2 )
{
return F_77 ( V_2 ) ;
}

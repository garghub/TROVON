static T_1 F_1 ( T_2 V_1 )
{
if ( V_1 == 128 )
V_1 = 0 ;
return ( T_1 ) V_1 ;
}
static void F_2 ( struct V_2 * V_3 ,
struct V_4 * V_4 )
{
int V_5 ;
if ( ! V_3 -> V_6 )
return;
V_5 = F_3 ( V_4 -> V_5 ) +
sizeof( * V_4 ) ;
F_4 ( V_3 -> V_6 , V_4 , V_5 ) ;
}
int F_5 ( struct V_2 * V_3 , struct V_7 * V_8 ,
struct V_9 * V_10 , T_3 V_11 )
{
struct V_12 * V_13 = V_3 -> V_14 ;
T_2 V_15 , * V_16 , * V_17 = ( T_2 * ) V_8 ;
struct V_18 V_19 ;
struct V_20 V_21 ;
struct V_4 * V_22 ;
struct V_23 * V_24 ;
int V_25 = V_10 -> V_26 ;
int V_27 ;
T_4 V_28 , V_5 , V_29 = V_13 -> V_30 -> V_31 -> V_32 ;
enum V_33 V_34 ;
if ( V_10 -> V_35 != V_36 &&
V_10 -> V_35 != V_37 &&
V_10 -> V_35 != V_38 )
return 0 ;
V_24 = ( (struct V_23 * ) & V_17 [ V_25 ] ) - 1 ;
if ( ! ( V_24 -> V_39 & V_40 ) )
return 0 ;
V_34 = F_6 ( & V_3 -> V_41 -> V_42 . V_43 ) ;
if ( ( V_34 == V_44 ) ||
( V_34 == V_45 ) ) {
V_28 = V_46 ;
V_15 = V_47 ;
V_16 = ( T_2 * ) V_21 . V_48 ;
} else {
V_28 = V_49 ;
V_15 = V_50 ;
V_16 = ( T_2 * ) V_19 . V_48 ;
}
if ( ( V_25 > V_28 + 2 ) || ( V_25 < V_28 - 1 ) )
return 1 ;
switch ( V_25 - V_28 ) {
case 0 :
memcpy ( V_16 , V_17 , V_15 ) ;
break;
case - 1 :
memcpy ( & V_16 [ 1 ] , V_17 , V_15 - 1 ) ;
V_16 [ 0 ] = V_17 [ 0 ] ;
break;
case 2 :
memcpy ( V_16 , V_17 , 30 ) ;
V_16 [ 30 ] = V_17 [ 31 ] ;
memcpy ( & V_16 [ 31 ] , & V_17 [ 33 ] , V_15 - 31 ) ;
break;
case 1 :
V_16 [ 0 ] = V_17 [ 0 ] ;
memcpy ( & V_16 [ 1 ] , V_17 , 30 ) ;
V_16 [ 31 ] = V_17 [ 31 ] ;
memcpy ( & V_16 [ 32 ] , & V_17 [ 33 ] , V_15 - 32 ) ;
break;
default:
return 1 ;
}
V_27 = V_15 / 2 ;
V_16 [ V_27 ] = ( V_16 [ V_27 + 1 ] + V_16 [ V_27 - 1 ] ) / 2 ;
if ( ( V_34 == V_44 ) ||
( V_34 == V_45 ) ) {
T_1 V_51 , V_52 ;
T_5 V_53 ;
T_2 V_54 , V_55 ;
T_2 V_56 , V_57 ;
T_4 V_58 , V_59 ;
struct V_60 * V_61 = V_13 -> V_61 ;
struct V_62 * V_63 ;
if ( V_61 )
V_53 = F_7 ( V_13 , V_13 -> V_30 ,
V_61 -> V_64 [ 3 ] . V_65 ) ;
else
V_53 = V_66 ;
V_5 = sizeof( V_21 ) - sizeof( struct V_4 ) ;
V_21 . V_22 . type = V_67 ;
V_21 . V_22 . V_5 = F_8 ( V_5 ) ;
V_21 . V_29 = F_8 ( V_29 ) ;
V_21 . V_68 = V_34 ;
if ( V_34 == V_45 ) {
V_51 = F_1 ( V_10 -> V_69 [ 0 ] ) ;
V_52 = F_1 ( V_10 -> V_70 [ 0 ] ) ;
V_21 . V_71 = V_13 -> V_72 ;
V_21 . V_73 = V_53 ;
} else {
V_51 = F_1 ( V_10 -> V_70 [ 0 ] ) ;
V_52 = F_1 ( V_10 -> V_69 [ 0 ] ) ;
V_21 . V_71 = V_53 ;
V_21 . V_73 = V_13 -> V_72 ;
}
V_21 . V_51 = V_51 ;
V_21 . V_52 = V_52 ;
V_63 = ( (struct V_62 * ) V_24 ) - 1 ;
V_58 = F_9 ( V_63 -> V_74 ) ;
V_59 = F_9 ( V_63 -> V_75 ) ;
V_21 . V_76 = F_8 ( V_58 ) ;
V_21 . V_77 = F_8 ( V_59 ) ;
V_54 = F_10 ( V_63 -> V_74 ) ;
V_55 = F_10 ( V_63 -> V_75 ) ;
V_21 . V_54 = V_54 ;
V_21 . V_55 = V_55 ;
V_56 = F_11 ( V_63 -> V_74 ) ;
V_57 = F_11 ( V_63 -> V_75 ) ;
V_21 . V_78 = V_56 ;
V_21 . V_79 = V_57 ;
V_21 . V_80 = V_63 -> V_80 & 0xf ;
V_21 . V_11 = F_12 ( V_11 ) ;
V_22 = (struct V_4 * ) & V_21 ;
} else {
T_2 V_81 , V_82 ;
T_4 V_83 ;
struct V_84 * V_63 ;
V_5 = sizeof( V_19 ) - sizeof( struct V_4 ) ;
V_19 . V_22 . type = V_85 ;
V_19 . V_22 . V_5 = F_8 ( V_5 ) ;
V_19 . V_29 = F_8 ( V_29 ) ;
V_19 . V_86 = F_1 ( V_10 -> V_69 [ 0 ] ) ;
V_19 . V_72 = V_13 -> V_72 ;
V_63 = ( (struct V_84 * ) V_24 ) - 1 ;
V_83 = F_9 ( V_63 -> V_87 ) ;
V_19 . V_88 = F_8 ( V_83 ) ;
V_81 = F_10 ( V_63 -> V_87 ) ;
V_19 . V_81 = V_81 ;
V_82 = F_11 ( V_63 -> V_87 ) ;
V_19 . V_89 = V_82 ;
V_19 . V_80 = V_63 -> V_80 & 0xf ;
V_19 . V_11 = F_12 ( V_11 ) ;
V_22 = (struct V_4 * ) & V_19 ;
}
F_2 ( V_3 , V_22 ) ;
return 1 ;
}
static T_6 F_13 ( struct V_90 * V_90 , char T_7 * V_91 ,
T_8 V_92 , T_9 * V_93 )
{
struct V_2 * V_3 = V_90 -> V_94 ;
char * V_95 = L_1 ;
unsigned int V_25 ;
switch ( V_3 -> V_96 ) {
case V_97 :
V_95 = L_2 ;
break;
case V_98 :
V_95 = L_3 ;
break;
case V_99 :
V_95 = L_4 ;
break;
case V_100 :
V_95 = L_5 ;
break;
}
V_25 = strlen ( V_95 ) ;
return F_14 ( V_91 , V_92 , V_93 , V_95 , V_25 ) ;
}
static T_6 F_15 ( struct V_90 * V_90 ,
const char T_7 * V_91 ,
T_8 V_92 , T_9 * V_93 )
{
struct V_2 * V_3 = V_90 -> V_94 ;
struct V_101 * V_102 = F_16 ( V_3 -> V_14 ) ;
char V_103 [ 32 ] ;
T_6 V_25 ;
if ( F_17 ( V_104 ) )
return - V_105 ;
V_25 = F_18 ( V_92 , sizeof( V_103 ) - 1 ) ;
if ( F_19 ( V_103 , V_91 , V_25 ) )
return - V_106 ;
V_103 [ V_25 ] = '\0' ;
if ( strncmp ( L_6 , V_103 , 7 ) == 0 ) {
F_20 ( V_3 -> V_41 ) ;
} else if ( strncmp ( L_3 , V_103 , 10 ) == 0 ) {
F_21 ( V_3 -> V_41 , V_98 ) ;
F_22 ( V_102 , V_107 , L_7 ) ;
} else if ( strncmp ( L_4 , V_103 , 8 ) == 0 ) {
F_21 ( V_3 -> V_41 , V_99 ) ;
F_22 ( V_102 , V_107 , L_8 ) ;
} else if ( strncmp ( L_5 , V_103 , 6 ) == 0 ) {
F_21 ( V_3 -> V_41 , V_100 ) ;
F_22 ( V_102 , V_107 , L_9 ) ;
} else if ( strncmp ( L_2 , V_103 , 7 ) == 0 ) {
F_21 ( V_3 -> V_41 , V_97 ) ;
F_22 ( V_102 , V_107 , L_10 ) ;
} else {
return - V_108 ;
}
return V_92 ;
}
static T_6 F_23 ( struct V_90 * V_90 ,
char T_7 * V_91 ,
T_8 V_92 , T_9 * V_93 )
{
struct V_2 * V_3 = V_90 -> V_94 ;
char V_103 [ 32 ] ;
unsigned int V_25 ;
V_25 = sprintf ( V_103 , L_11 , V_3 -> V_109 . V_110 ) ;
return F_14 ( V_91 , V_92 , V_93 , V_103 , V_25 ) ;
}
static T_6 F_24 ( struct V_90 * V_90 ,
const char T_7 * V_91 ,
T_8 V_92 , T_9 * V_93 )
{
struct V_2 * V_3 = V_90 -> V_94 ;
unsigned long V_111 ;
char V_103 [ 32 ] ;
T_6 V_25 ;
V_25 = F_18 ( V_92 , sizeof( V_103 ) - 1 ) ;
if ( F_19 ( V_103 , V_91 , V_25 ) )
return - V_106 ;
V_103 [ V_25 ] = '\0' ;
if ( F_25 ( V_103 , 0 , & V_111 ) )
return - V_108 ;
if ( V_111 > 1 )
return - V_108 ;
V_3 -> V_109 . V_110 = V_111 ;
return V_92 ;
}
static T_6 F_26 ( struct V_90 * V_90 ,
char T_7 * V_91 ,
T_8 V_92 , T_9 * V_93 )
{
struct V_2 * V_3 = V_90 -> V_94 ;
char V_103 [ 32 ] ;
unsigned int V_25 ;
V_25 = sprintf ( V_103 , L_11 , V_3 -> V_109 . V_92 ) ;
return F_14 ( V_91 , V_92 , V_93 , V_103 , V_25 ) ;
}
static T_6 F_27 ( struct V_90 * V_90 ,
const char T_7 * V_91 ,
T_8 V_92 , T_9 * V_93 )
{
struct V_2 * V_3 = V_90 -> V_94 ;
unsigned long V_111 ;
char V_103 [ 32 ] ;
T_6 V_25 ;
V_25 = F_18 ( V_92 , sizeof( V_103 ) - 1 ) ;
if ( F_19 ( V_103 , V_91 , V_25 ) )
return - V_106 ;
V_103 [ V_25 ] = '\0' ;
if ( F_25 ( V_103 , 0 , & V_111 ) )
return - V_108 ;
if ( V_111 > 255 )
return - V_108 ;
V_3 -> V_109 . V_92 = V_111 ;
return V_92 ;
}
static T_6 F_28 ( struct V_90 * V_90 ,
char T_7 * V_91 ,
T_8 V_92 , T_9 * V_93 )
{
struct V_2 * V_3 = V_90 -> V_94 ;
char V_103 [ 32 ] ;
unsigned int V_25 ;
V_25 = sprintf ( V_103 , L_11 , V_3 -> V_109 . V_112 ) ;
return F_14 ( V_91 , V_92 , V_93 , V_103 , V_25 ) ;
}
static T_6 F_29 ( struct V_90 * V_90 ,
const char T_7 * V_91 ,
T_8 V_92 , T_9 * V_93 )
{
struct V_2 * V_3 = V_90 -> V_94 ;
unsigned long V_111 ;
char V_103 [ 32 ] ;
T_6 V_25 ;
V_25 = F_18 ( V_92 , sizeof( V_103 ) - 1 ) ;
if ( F_19 ( V_103 , V_91 , V_25 ) )
return - V_106 ;
V_103 [ V_25 ] = '\0' ;
if ( F_25 ( V_103 , 0 , & V_111 ) )
return - V_108 ;
if ( V_111 > 255 )
return - V_108 ;
V_3 -> V_109 . V_112 = V_111 ;
return V_92 ;
}
static T_6 F_30 ( struct V_90 * V_90 ,
char T_7 * V_91 ,
T_8 V_92 , T_9 * V_93 )
{
struct V_2 * V_3 = V_90 -> V_94 ;
char V_103 [ 32 ] ;
unsigned int V_25 ;
V_25 = sprintf ( V_103 , L_11 , V_3 -> V_109 . V_113 ) ;
return F_14 ( V_91 , V_92 , V_93 , V_103 , V_25 ) ;
}
static T_6 F_31 ( struct V_90 * V_90 ,
const char T_7 * V_91 ,
T_8 V_92 , T_9 * V_93 )
{
struct V_2 * V_3 = V_90 -> V_94 ;
unsigned long V_111 ;
char V_103 [ 32 ] ;
T_6 V_25 ;
V_25 = F_18 ( V_92 , sizeof( V_103 ) - 1 ) ;
if ( F_19 ( V_103 , V_91 , V_25 ) )
return - V_106 ;
V_103 [ V_25 ] = '\0' ;
if ( F_25 ( V_103 , 0 , & V_111 ) )
return - V_108 ;
if ( V_111 > 15 )
return - V_108 ;
V_3 -> V_109 . V_113 = V_111 ;
return V_92 ;
}
static struct V_114 * F_32 ( const char * V_115 ,
struct V_114 * V_116 ,
T_10 V_95 ,
struct V_117 * V_103 ,
int * V_118 )
{
struct V_114 * V_119 ;
V_119 = F_33 ( V_115 , V_95 , V_116 , V_103 ,
& V_120 ) ;
* V_118 = 1 ;
return V_119 ;
}
static int F_34 ( struct V_114 * V_114 )
{
F_35 ( V_114 ) ;
return 0 ;
}
void F_36 ( struct V_2 * V_3 )
{
if ( F_17 ( V_121 ) && V_3 -> V_6 ) {
F_37 ( V_3 -> V_6 ) ;
V_3 -> V_6 = NULL ;
}
}
void F_38 ( struct V_2 * V_3 )
{
V_3 -> V_6 = F_39 ( L_12 ,
V_3 -> V_122 . V_123 ,
1024 , 256 , & V_124 ,
NULL ) ;
F_33 ( L_13 ,
V_125 | V_126 ,
V_3 -> V_122 . V_123 , V_3 ,
& V_127 ) ;
F_33 ( L_14 ,
V_125 | V_126 ,
V_3 -> V_122 . V_123 , V_3 ,
& V_128 ) ;
F_33 ( L_15 ,
V_125 | V_126 ,
V_3 -> V_122 . V_123 , V_3 ,
& V_129 ) ;
F_33 ( L_16 ,
V_125 | V_126 ,
V_3 -> V_122 . V_123 , V_3 ,
& V_130 ) ;
F_33 ( L_17 ,
V_125 | V_126 ,
V_3 -> V_122 . V_123 , V_3 ,
& V_131 ) ;
}

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
struct V_12 * V_13 = V_3 -> V_13 ;
struct V_14 * V_15 = F_6 ( V_3 -> V_13 ) ;
T_2 V_16 , * V_17 , * V_18 = ( T_2 * ) V_8 ;
struct V_19 V_20 ;
struct V_21 V_22 ;
struct V_4 * V_23 ;
struct V_24 * V_25 ;
int V_26 = V_10 -> V_27 ;
int V_28 ;
T_4 V_29 , V_5 , V_30 = V_13 -> V_31 -> V_32 -> V_33 ;
enum V_34 V_35 ;
if ( V_10 -> V_36 != V_37 &&
V_10 -> V_36 != V_38 &&
V_10 -> V_36 != V_39 )
return 0 ;
V_25 = ( (struct V_24 * ) & V_18 [ V_26 ] ) - 1 ;
if ( ! ( V_25 -> V_40 & V_41 ) )
return 0 ;
V_35 = F_7 ( & V_15 -> V_42 -> V_43 . V_44 ) ;
if ( ( V_35 == V_45 ) ||
( V_35 == V_46 ) ) {
V_29 = V_47 ;
V_16 = V_48 ;
V_17 = ( T_2 * ) V_22 . V_49 ;
} else {
V_29 = V_50 ;
V_16 = V_51 ;
V_17 = ( T_2 * ) V_20 . V_49 ;
}
if ( ( V_26 > V_29 + 2 ) || ( V_26 < V_29 - 1 ) )
return 1 ;
switch ( V_26 - V_29 ) {
case 0 :
memcpy ( V_17 , V_18 , V_16 ) ;
break;
case - 1 :
memcpy ( & V_17 [ 1 ] , V_18 , V_16 - 1 ) ;
V_17 [ 0 ] = V_18 [ 0 ] ;
break;
case 2 :
memcpy ( V_17 , V_18 , 30 ) ;
V_17 [ 30 ] = V_18 [ 31 ] ;
memcpy ( & V_17 [ 31 ] , & V_18 [ 33 ] , V_16 - 31 ) ;
break;
case 1 :
V_17 [ 0 ] = V_18 [ 0 ] ;
memcpy ( & V_17 [ 1 ] , V_18 , 30 ) ;
V_17 [ 31 ] = V_18 [ 31 ] ;
memcpy ( & V_17 [ 32 ] , & V_18 [ 33 ] , V_16 - 32 ) ;
break;
default:
return 1 ;
}
V_28 = V_16 / 2 ;
V_17 [ V_28 ] = ( V_17 [ V_28 + 1 ] + V_17 [ V_28 - 1 ] ) / 2 ;
if ( ( V_35 == V_45 ) ||
( V_35 == V_46 ) ) {
T_1 V_52 , V_53 ;
T_5 V_54 ;
T_2 V_55 , V_56 ;
T_2 V_57 , V_58 ;
T_4 V_59 , V_60 ;
struct V_61 * V_62 = V_13 -> V_62 ;
struct V_63 * V_64 ;
if ( V_62 )
V_54 = F_8 ( V_13 , V_13 -> V_31 ,
V_62 -> V_65 [ 3 ] . V_66 ) ;
else
V_54 = V_67 ;
V_5 = sizeof( V_22 ) - sizeof( struct V_4 ) ;
V_22 . V_23 . type = V_68 ;
V_22 . V_23 . V_5 = F_9 ( V_5 ) ;
V_22 . V_30 = F_9 ( V_30 ) ;
V_22 . V_69 = V_35 ;
if ( V_35 == V_46 ) {
V_52 = F_1 ( V_10 -> V_70 [ 0 ] ) ;
V_53 = F_1 ( V_10 -> V_71 [ 0 ] ) ;
V_22 . V_72 = V_13 -> V_73 ;
V_22 . V_74 = V_54 ;
} else {
V_52 = F_1 ( V_10 -> V_71 [ 0 ] ) ;
V_53 = F_1 ( V_10 -> V_70 [ 0 ] ) ;
V_22 . V_72 = V_54 ;
V_22 . V_74 = V_13 -> V_73 ;
}
V_22 . V_52 = V_52 ;
V_22 . V_53 = V_53 ;
V_64 = ( (struct V_63 * ) V_25 ) - 1 ;
V_59 = F_10 ( V_64 -> V_75 ) ;
V_60 = F_10 ( V_64 -> V_76 ) ;
V_22 . V_77 = F_9 ( V_59 ) ;
V_22 . V_78 = F_9 ( V_60 ) ;
V_55 = F_11 ( V_64 -> V_75 ) ;
V_56 = F_11 ( V_64 -> V_76 ) ;
V_22 . V_55 = V_55 ;
V_22 . V_56 = V_56 ;
V_57 = F_12 ( V_64 -> V_75 ) ;
V_58 = F_12 ( V_64 -> V_76 ) ;
V_22 . V_79 = V_57 ;
V_22 . V_80 = V_58 ;
V_22 . V_81 = V_64 -> V_81 & 0xf ;
V_22 . V_11 = F_13 ( V_11 ) ;
V_23 = (struct V_4 * ) & V_22 ;
} else {
T_2 V_82 , V_83 ;
T_4 V_84 ;
struct V_85 * V_64 ;
V_5 = sizeof( V_20 ) - sizeof( struct V_4 ) ;
V_20 . V_23 . type = V_86 ;
V_20 . V_23 . V_5 = F_9 ( V_5 ) ;
V_20 . V_30 = F_9 ( V_30 ) ;
V_20 . V_87 = F_1 ( V_10 -> V_70 [ 0 ] ) ;
V_20 . V_73 = V_13 -> V_73 ;
V_64 = ( (struct V_85 * ) V_25 ) - 1 ;
V_84 = F_10 ( V_64 -> V_88 ) ;
V_20 . V_89 = F_9 ( V_84 ) ;
V_82 = F_11 ( V_64 -> V_88 ) ;
V_20 . V_82 = V_82 ;
V_83 = F_12 ( V_64 -> V_88 ) ;
V_20 . V_90 = V_83 ;
V_20 . V_81 = V_64 -> V_81 & 0xf ;
V_20 . V_11 = F_13 ( V_11 ) ;
V_23 = (struct V_4 * ) & V_20 ;
}
F_2 ( V_3 , V_23 ) ;
return 1 ;
}
static T_6 F_14 ( struct V_91 * V_91 , char T_7 * V_92 ,
T_8 V_93 , T_9 * V_94 )
{
struct V_2 * V_3 = V_91 -> V_95 ;
char * V_96 = L_1 ;
unsigned int V_26 ;
switch ( V_3 -> V_97 ) {
case V_98 :
V_96 = L_2 ;
break;
case V_99 :
V_96 = L_3 ;
break;
case V_100 :
V_96 = L_4 ;
break;
case V_101 :
V_96 = L_5 ;
break;
}
V_26 = strlen ( V_96 ) ;
return F_15 ( V_92 , V_93 , V_94 , V_96 , V_26 ) ;
}
void F_16 ( struct V_14 * V_15 ,
struct V_2 * V_3 )
{
struct V_12 * V_13 = V_3 -> V_13 ;
T_10 V_102 ;
if ( F_17 ( V_103 ) )
return;
if ( ! F_18 ( V_13 ) -> V_104 ) {
F_19 ( V_15 , L_6 ) ;
return;
}
F_20 ( V_15 ) -> F_21 ( V_15 ) ;
V_102 = F_22 ( V_13 ) ;
F_23 ( V_13 , V_102 |
V_105 |
V_106 ) ;
F_24 ( V_15 , V_3 , V_3 -> V_97 ) ;
F_18 ( V_13 ) -> V_104 ( V_13 ) ;
F_20 ( V_15 ) -> F_25 ( V_15 ) ;
}
int F_24 ( struct V_14 * V_15 ,
struct V_2 * V_3 ,
enum V_97 V_97 )
{
struct V_12 * V_13 = V_3 -> V_13 ;
if ( ! F_18 ( V_13 ) -> V_104 ) {
F_19 ( V_15 , L_6 ) ;
return - 1 ;
}
switch ( V_97 ) {
case V_98 :
V_3 -> V_107 . V_108 = 0 ;
break;
case V_99 :
V_3 -> V_107 . V_109 = 1 ;
V_3 -> V_107 . V_108 = 1 ;
break;
case V_100 :
case V_101 :
V_3 -> V_107 . V_109 = 0 ;
V_3 -> V_107 . V_108 = 1 ;
break;
default:
return - 1 ;
}
F_20 ( V_15 ) -> F_21 ( V_15 ) ;
F_18 ( V_13 ) -> F_26 ( V_13 , & V_3 -> V_107 ) ;
F_20 ( V_15 ) -> F_25 ( V_15 ) ;
V_3 -> V_97 = V_97 ;
return 0 ;
}
static T_6 F_27 ( struct V_91 * V_91 ,
const char T_7 * V_92 ,
T_8 V_93 , T_9 * V_94 )
{
struct V_2 * V_3 = V_91 -> V_95 ;
struct V_14 * V_15 = F_6 ( V_3 -> V_13 ) ;
char V_110 [ 32 ] ;
T_6 V_26 ;
if ( F_17 ( V_103 ) )
return - V_111 ;
V_26 = F_28 ( V_93 , sizeof( V_110 ) - 1 ) ;
if ( F_29 ( V_110 , V_92 , V_26 ) )
return - V_112 ;
V_110 [ V_26 ] = '\0' ;
if ( strncmp ( L_7 , V_110 , 7 ) == 0 ) {
F_16 ( V_15 , V_3 ) ;
} else if ( strncmp ( L_3 , V_110 , 10 ) == 0 ) {
F_24 ( V_15 , V_3 , V_99 ) ;
F_30 ( V_15 , V_113 , L_8 ) ;
} else if ( strncmp ( L_4 , V_110 , 8 ) == 0 ) {
F_24 ( V_15 , V_3 , V_100 ) ;
F_30 ( V_15 , V_113 , L_9 ) ;
} else if ( strncmp ( L_5 , V_110 , 6 ) == 0 ) {
F_24 ( V_15 , V_3 , V_101 ) ;
F_30 ( V_15 , V_113 , L_10 ) ;
} else if ( strncmp ( L_2 , V_110 , 7 ) == 0 ) {
F_24 ( V_15 , V_3 , V_98 ) ;
F_30 ( V_15 , V_113 , L_11 ) ;
} else {
return - V_114 ;
}
return V_93 ;
}
static T_6 F_31 ( struct V_91 * V_91 ,
char T_7 * V_92 ,
T_8 V_93 , T_9 * V_94 )
{
struct V_2 * V_3 = V_91 -> V_95 ;
char V_110 [ 32 ] ;
unsigned int V_26 ;
V_26 = sprintf ( V_110 , L_12 , V_3 -> V_107 . V_115 ) ;
return F_15 ( V_92 , V_93 , V_94 , V_110 , V_26 ) ;
}
static T_6 F_32 ( struct V_91 * V_91 ,
const char T_7 * V_92 ,
T_8 V_93 , T_9 * V_94 )
{
struct V_2 * V_3 = V_91 -> V_95 ;
unsigned long V_116 ;
char V_110 [ 32 ] ;
T_6 V_26 ;
V_26 = F_28 ( V_93 , sizeof( V_110 ) - 1 ) ;
if ( F_29 ( V_110 , V_92 , V_26 ) )
return - V_112 ;
V_110 [ V_26 ] = '\0' ;
if ( F_33 ( V_110 , 0 , & V_116 ) )
return - V_114 ;
if ( V_116 > 1 )
return - V_114 ;
V_3 -> V_107 . V_115 = V_116 ;
return V_93 ;
}
static T_6 F_34 ( struct V_91 * V_91 ,
char T_7 * V_92 ,
T_8 V_93 , T_9 * V_94 )
{
struct V_2 * V_3 = V_91 -> V_95 ;
char V_110 [ 32 ] ;
unsigned int V_26 ;
V_26 = sprintf ( V_110 , L_12 , V_3 -> V_107 . V_93 ) ;
return F_15 ( V_92 , V_93 , V_94 , V_110 , V_26 ) ;
}
static T_6 F_35 ( struct V_91 * V_91 ,
const char T_7 * V_92 ,
T_8 V_93 , T_9 * V_94 )
{
struct V_2 * V_3 = V_91 -> V_95 ;
unsigned long V_116 ;
char V_110 [ 32 ] ;
T_6 V_26 ;
V_26 = F_28 ( V_93 , sizeof( V_110 ) - 1 ) ;
if ( F_29 ( V_110 , V_92 , V_26 ) )
return - V_112 ;
V_110 [ V_26 ] = '\0' ;
if ( F_33 ( V_110 , 0 , & V_116 ) )
return - V_114 ;
if ( V_116 > 255 )
return - V_114 ;
V_3 -> V_107 . V_93 = V_116 ;
return V_93 ;
}
static T_6 F_36 ( struct V_91 * V_91 ,
char T_7 * V_92 ,
T_8 V_93 , T_9 * V_94 )
{
struct V_2 * V_3 = V_91 -> V_95 ;
char V_110 [ 32 ] ;
unsigned int V_26 ;
V_26 = sprintf ( V_110 , L_12 , V_3 -> V_107 . V_117 ) ;
return F_15 ( V_92 , V_93 , V_94 , V_110 , V_26 ) ;
}
static T_6 F_37 ( struct V_91 * V_91 ,
const char T_7 * V_92 ,
T_8 V_93 , T_9 * V_94 )
{
struct V_2 * V_3 = V_91 -> V_95 ;
unsigned long V_116 ;
char V_110 [ 32 ] ;
T_6 V_26 ;
V_26 = F_28 ( V_93 , sizeof( V_110 ) - 1 ) ;
if ( F_29 ( V_110 , V_92 , V_26 ) )
return - V_112 ;
V_110 [ V_26 ] = '\0' ;
if ( F_33 ( V_110 , 0 , & V_116 ) )
return - V_114 ;
if ( V_116 > 255 )
return - V_114 ;
V_3 -> V_107 . V_117 = V_116 ;
return V_93 ;
}
static T_6 F_38 ( struct V_91 * V_91 ,
char T_7 * V_92 ,
T_8 V_93 , T_9 * V_94 )
{
struct V_2 * V_3 = V_91 -> V_95 ;
char V_110 [ 32 ] ;
unsigned int V_26 ;
V_26 = sprintf ( V_110 , L_12 , V_3 -> V_107 . V_118 ) ;
return F_15 ( V_92 , V_93 , V_94 , V_110 , V_26 ) ;
}
static T_6 F_39 ( struct V_91 * V_91 ,
const char T_7 * V_92 ,
T_8 V_93 , T_9 * V_94 )
{
struct V_2 * V_3 = V_91 -> V_95 ;
unsigned long V_116 ;
char V_110 [ 32 ] ;
T_6 V_26 ;
V_26 = F_28 ( V_93 , sizeof( V_110 ) - 1 ) ;
if ( F_29 ( V_110 , V_92 , V_26 ) )
return - V_112 ;
V_110 [ V_26 ] = '\0' ;
if ( F_33 ( V_110 , 0 , & V_116 ) )
return - V_114 ;
if ( V_116 > 15 )
return - V_114 ;
V_3 -> V_107 . V_118 = V_116 ;
return V_93 ;
}
static struct V_119 * F_40 ( const char * V_120 ,
struct V_119 * V_121 ,
T_11 V_96 ,
struct V_122 * V_110 ,
int * V_123 )
{
struct V_119 * V_124 ;
V_124 = F_41 ( V_120 , V_96 , V_121 , V_110 ,
& V_125 ) ;
* V_123 = 1 ;
return V_124 ;
}
static int F_42 ( struct V_119 * V_119 )
{
F_43 ( V_119 ) ;
return 0 ;
}
void F_44 ( struct V_2 * V_3 )
{
if ( F_17 ( V_126 ) && V_3 -> V_6 ) {
F_45 ( V_3 -> V_6 ) ;
V_3 -> V_6 = NULL ;
}
}
void F_46 ( struct V_2 * V_3 ,
struct V_119 * V_127 )
{
V_3 -> V_6 = F_47 ( L_13 ,
V_127 ,
1024 , 256 , & V_128 ,
NULL ) ;
F_41 ( L_14 ,
V_129 | V_130 ,
V_127 , V_3 ,
& V_131 ) ;
F_41 ( L_15 ,
V_129 | V_130 ,
V_127 , V_3 ,
& V_132 ) ;
F_41 ( L_16 ,
V_129 | V_130 ,
V_127 , V_3 ,
& V_133 ) ;
F_41 ( L_17 ,
V_129 | V_130 ,
V_127 , V_3 ,
& V_134 ) ;
F_41 ( L_18 ,
V_129 | V_130 ,
V_127 , V_3 ,
& V_135 ) ;
}

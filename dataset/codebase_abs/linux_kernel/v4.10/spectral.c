static void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_3 )
{
int V_4 ;
if ( ! V_2 -> V_5 . V_6 )
return;
V_4 = F_2 ( V_3 -> V_4 ) +
sizeof( * V_3 ) ;
F_3 ( V_2 -> V_5 . V_6 , V_3 , V_4 ) ;
}
static T_1 F_4 ( T_2 V_7 , T_3 V_8 , T_4 V_9 ,
T_5 * V_10 )
{
int V_11 ;
T_5 V_12 ;
V_11 = V_9 / 2 ;
if ( V_11 < V_7 || - V_11 >= V_7 )
return 0 ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
if ( V_10 [ V_11 + V_7 ] == ( V_8 >> V_12 ) )
break;
}
if ( V_10 [ V_11 + V_7 ] != ( V_8 >> V_12 ) )
return 0 ;
return V_12 ;
}
int F_5 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
const struct V_15 * V_16 ,
T_4 V_9 , T_6 V_17 )
{
struct V_18 * V_19 ;
T_5 V_20 [ sizeof( * V_19 ) + V_21 ] ;
T_3 V_22 , V_23 , V_24 , V_25 , V_4 , V_26 ;
T_7 V_27 , V_28 ;
T_5 V_29 , * V_30 ;
int V_11 ;
V_19 = (struct V_18 * ) & V_20 ;
if ( V_9 < 64 || V_9 > V_21 )
return - V_31 ;
if ( V_9 == 68 )
V_9 -= 4 ;
V_27 = F_6 ( V_16 -> V_27 ) ;
V_28 = F_6 ( V_16 -> V_28 ) ;
V_4 = sizeof( * V_19 ) - sizeof( struct V_3 ) + V_9 ;
V_19 -> V_32 . type = V_33 ;
V_19 -> V_32 . V_4 = F_7 ( V_4 ) ;
switch ( V_14 -> V_34 ) {
case 20 :
V_19 -> V_34 = 22 ;
break;
case 40 :
V_19 -> V_34 = 44 ;
break;
case 80 :
if ( V_9 == 64 )
return - V_31 ;
V_19 -> V_34 = 88 ;
break;
default:
V_19 -> V_34 = V_14 -> V_34 ;
}
V_19 -> V_35 = F_8 ( V_28 , V_36 ) ;
V_19 -> V_37 = F_8 ( V_28 , V_38 ) ;
V_26 = F_8 ( V_28 , V_39 ) ;
V_19 -> V_8 = F_7 ( V_26 ) ;
V_19 -> V_7 = F_8 ( V_27 , V_40 ) ;
V_19 -> V_41 = V_14 -> V_42 ;
V_24 = F_8 ( V_27 , V_43 ) ;
V_25 = F_8 ( V_27 , V_44 ) ;
V_19 -> V_24 = F_7 ( V_24 ) ;
V_19 -> V_25 = F_7 ( V_25 ) ;
V_22 = V_14 -> V_22 ;
V_23 = V_14 -> V_23 ;
V_19 -> V_22 = F_7 ( V_22 ) ;
V_19 -> V_23 = F_7 ( V_23 ) ;
V_29 = F_8 ( V_27 , V_45 ) ;
V_19 -> V_46 = F_7 ( V_14 -> V_47 [ V_29 ] ) ;
V_30 = ( T_5 * ) V_16 ;
V_30 += sizeof( * V_16 ) ;
V_19 -> V_17 = F_9 ( V_17 ) ;
V_19 -> V_12 = F_4 ( V_19 -> V_7 , V_26 ,
V_9 , V_30 ) ;
memcpy ( V_19 -> V_10 , V_30 , V_9 ) ;
V_11 = V_9 / 2 ;
V_19 -> V_10 [ V_11 ] = ( V_19 -> V_10 [ V_11 + 1 ] +
V_19 -> V_10 [ V_11 - 1 ] ) / 2 ;
F_1 ( V_2 , & V_19 -> V_32 ) ;
return 0 ;
}
static struct V_48 * F_10 ( struct V_1 * V_2 )
{
struct V_48 * V_49 ;
F_11 ( & V_2 -> V_50 ) ;
if ( F_12 ( & V_2 -> V_51 ) )
return NULL ;
F_13 (arvif, &ar->arvifs, list)
if ( V_49 -> V_52 )
return V_49 ;
return F_14 ( & V_2 -> V_51 , F_15 ( * V_49 ) , V_53 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_48 * V_49 ;
int V_54 ;
int V_55 ;
F_11 ( & V_2 -> V_50 ) ;
V_49 = F_10 ( V_2 ) ;
if ( ! V_49 )
return - V_56 ;
V_55 = V_49 -> V_55 ;
if ( V_2 -> V_5 . V_57 == V_58 )
return 0 ;
V_54 = F_17 ( V_2 , V_55 ,
V_59 ,
V_60 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_17 ( V_2 , V_55 ,
V_61 ,
V_60 ) ;
if ( V_54 < 0 )
return V_54 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
enum V_62 V_57 )
{
struct V_63 V_64 ;
struct V_48 * V_49 ;
int V_55 , V_65 , V_54 = 0 ;
F_11 ( & V_2 -> V_50 ) ;
V_49 = F_10 ( V_2 ) ;
if ( ! V_49 )
return - V_56 ;
V_55 = V_49 -> V_55 ;
V_49 -> V_52 = ( V_57 != V_58 ) ;
V_2 -> V_5 . V_57 = V_57 ;
V_54 = F_17 ( V_2 , V_55 ,
V_59 ,
V_66 ) ;
if ( V_54 < 0 ) {
F_19 ( V_2 , L_1 , V_54 ) ;
return V_54 ;
}
if ( V_57 == V_58 )
return 0 ;
if ( V_57 == V_67 )
V_65 = V_68 ;
else
V_65 = F_20 ( T_5 , 1 , V_2 -> V_5 . V_69 . V_65 ) ;
V_64 . V_55 = V_55 ;
V_64 . V_70 = V_65 ;
V_64 . V_71 = V_72 ;
V_64 . V_73 = V_74 ;
V_64 . V_75 = V_2 -> V_5 . V_69 . V_76 ;
V_64 . V_77 = V_78 ;
V_64 . V_79 = V_80 ;
V_64 . V_81 = V_82 ;
V_64 . V_83 = V_84 ;
V_64 . V_85 = V_86 ;
V_64 . V_87 = V_88 ;
V_64 . V_89 = V_90 ;
V_64 . V_91 = V_92 ;
V_64 . V_93 = V_94 ;
V_64 . V_95 = V_96 ;
V_64 . V_97 = V_98 ;
V_64 . V_99 = V_100 ;
V_64 . V_101 = V_102 ;
V_64 . V_103 = V_104 ;
V_54 = F_21 ( V_2 , & V_64 ) ;
if ( V_54 < 0 ) {
F_19 ( V_2 , L_2 , V_54 ) ;
return V_54 ;
}
return 0 ;
}
static T_8 F_22 ( struct V_105 * V_105 , char T_9 * V_106 ,
T_4 V_65 , T_10 * V_107 )
{
struct V_1 * V_2 = V_105 -> V_108 ;
char * V_57 = L_3 ;
unsigned int V_109 ;
enum V_62 V_110 ;
F_23 ( & V_2 -> V_50 ) ;
V_110 = V_2 -> V_5 . V_57 ;
F_24 ( & V_2 -> V_50 ) ;
switch ( V_110 ) {
case V_58 :
V_57 = L_4 ;
break;
case V_67 :
V_57 = L_5 ;
break;
case V_111 :
V_57 = L_6 ;
break;
}
V_109 = strlen ( V_57 ) ;
return F_25 ( V_106 , V_65 , V_107 , V_57 , V_109 ) ;
}
static T_8 F_26 ( struct V_105 * V_105 ,
const char T_9 * V_106 ,
T_4 V_65 , T_10 * V_107 )
{
struct V_1 * V_2 = V_105 -> V_108 ;
char V_20 [ 32 ] ;
T_8 V_109 ;
int V_54 ;
V_109 = F_27 ( V_65 , sizeof( V_20 ) - 1 ) ;
if ( F_28 ( V_20 , V_106 , V_109 ) )
return - V_112 ;
V_20 [ V_109 ] = '\0' ;
F_23 ( & V_2 -> V_50 ) ;
if ( strncmp ( L_7 , V_20 , 7 ) == 0 ) {
if ( V_2 -> V_5 . V_57 == V_111 ||
V_2 -> V_5 . V_57 == V_67 ) {
V_54 = F_18 ( V_2 ,
V_2 -> V_5 . V_57 ) ;
if ( V_54 < 0 ) {
F_19 ( V_2 , L_8 ,
V_54 ) ;
}
V_54 = F_16 ( V_2 ) ;
if ( V_54 < 0 ) {
F_19 ( V_2 , L_9 ,
V_54 ) ;
}
} else {
V_54 = - V_31 ;
}
} else if ( strncmp ( L_5 , V_20 , 10 ) == 0 ) {
V_54 = F_18 ( V_2 , V_67 ) ;
} else if ( strncmp ( L_6 , V_20 , 6 ) == 0 ) {
V_54 = F_18 ( V_2 , V_111 ) ;
} else if ( strncmp ( L_4 , V_20 , 7 ) == 0 ) {
V_54 = F_18 ( V_2 , V_58 ) ;
} else {
V_54 = - V_31 ;
}
F_24 ( & V_2 -> V_50 ) ;
if ( V_54 < 0 )
return V_54 ;
return V_65 ;
}
static T_8 F_29 ( struct V_105 * V_105 ,
char T_9 * V_106 ,
T_4 V_65 , T_10 * V_107 )
{
struct V_1 * V_2 = V_105 -> V_108 ;
char V_20 [ 32 ] ;
unsigned int V_109 ;
T_5 V_113 ;
F_23 ( & V_2 -> V_50 ) ;
V_113 = V_2 -> V_5 . V_69 . V_65 ;
F_24 ( & V_2 -> V_50 ) ;
V_109 = sprintf ( V_20 , L_10 , V_113 ) ;
return F_25 ( V_106 , V_65 , V_107 , V_20 , V_109 ) ;
}
static T_8 F_30 ( struct V_105 * V_105 ,
const char T_9 * V_106 ,
T_4 V_65 , T_10 * V_107 )
{
struct V_1 * V_2 = V_105 -> V_108 ;
unsigned long V_114 ;
char V_20 [ 32 ] ;
T_8 V_109 ;
V_109 = F_27 ( V_65 , sizeof( V_20 ) - 1 ) ;
if ( F_28 ( V_20 , V_106 , V_109 ) )
return - V_112 ;
V_20 [ V_109 ] = '\0' ;
if ( F_31 ( V_20 , 0 , & V_114 ) )
return - V_31 ;
if ( V_114 < 0 || V_114 > 255 )
return - V_31 ;
F_23 ( & V_2 -> V_50 ) ;
V_2 -> V_5 . V_69 . V_65 = V_114 ;
F_24 ( & V_2 -> V_50 ) ;
return V_65 ;
}
static T_8 F_32 ( struct V_105 * V_105 ,
char T_9 * V_106 ,
T_4 V_65 , T_10 * V_107 )
{
struct V_1 * V_2 = V_105 -> V_108 ;
char V_20 [ 32 ] ;
unsigned int V_109 , V_30 , V_76 , V_115 ;
F_23 ( & V_2 -> V_50 ) ;
V_76 = V_2 -> V_5 . V_69 . V_76 ;
V_115 = V_100 ;
V_30 = 1 << ( V_76 - V_115 ) ;
F_24 ( & V_2 -> V_50 ) ;
V_109 = sprintf ( V_20 , L_10 , V_30 ) ;
return F_25 ( V_106 , V_65 , V_107 , V_20 , V_109 ) ;
}
static T_8 F_33 ( struct V_105 * V_105 ,
const char T_9 * V_106 ,
T_4 V_65 , T_10 * V_107 )
{
struct V_1 * V_2 = V_105 -> V_108 ;
unsigned long V_114 ;
char V_20 [ 32 ] ;
T_8 V_109 ;
V_109 = F_27 ( V_65 , sizeof( V_20 ) - 1 ) ;
if ( F_28 ( V_20 , V_106 , V_109 ) )
return - V_112 ;
V_20 [ V_109 ] = '\0' ;
if ( F_31 ( V_20 , 0 , & V_114 ) )
return - V_31 ;
if ( V_114 < 64 || V_114 > V_21 )
return - V_31 ;
if ( ! F_34 ( V_114 ) )
return - V_31 ;
F_23 ( & V_2 -> V_50 ) ;
V_2 -> V_5 . V_69 . V_76 = F_35 ( V_114 ) ;
V_2 -> V_5 . V_69 . V_76 += V_100 ;
F_24 ( & V_2 -> V_50 ) ;
return V_65 ;
}
static struct V_116 * F_36 ( const char * V_117 ,
struct V_116 * V_118 ,
T_11 V_57 ,
struct V_119 * V_20 ,
int * V_120 )
{
struct V_116 * V_121 ;
V_121 = F_37 ( V_117 , V_57 , V_118 , V_20 ,
& V_122 ) ;
* V_120 = 1 ;
return V_121 ;
}
static int F_38 ( struct V_116 * V_116 )
{
F_39 ( V_116 ) ;
return 0 ;
}
int F_40 ( struct V_1 * V_2 )
{
struct V_48 * V_49 ;
F_11 ( & V_2 -> V_50 ) ;
F_13 (arvif, &ar->arvifs, list)
V_49 -> V_52 = 0 ;
V_2 -> V_5 . V_57 = V_58 ;
V_2 -> V_5 . V_69 . V_65 = V_68 ;
V_2 -> V_5 . V_69 . V_76 = V_123 ;
return 0 ;
}
int F_41 ( struct V_48 * V_49 )
{
if ( ! V_49 -> V_52 )
return 0 ;
return F_18 ( V_49 -> V_2 , V_58 ) ;
}
int F_42 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_6 = F_43 ( L_11 ,
V_2 -> V_124 . V_125 ,
1140 , 2500 ,
& V_126 , NULL ) ;
F_37 ( L_12 ,
V_127 | V_128 ,
V_2 -> V_124 . V_125 , V_2 ,
& V_129 ) ;
F_37 ( L_13 ,
V_127 | V_128 ,
V_2 -> V_124 . V_125 , V_2 ,
& V_130 ) ;
F_37 ( L_14 ,
V_127 | V_128 ,
V_2 -> V_124 . V_125 , V_2 ,
& V_131 ) ;
return 0 ;
}
void F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_6 ) {
F_45 ( V_2 -> V_5 . V_6 ) ;
V_2 -> V_5 . V_6 = NULL ;
}
}

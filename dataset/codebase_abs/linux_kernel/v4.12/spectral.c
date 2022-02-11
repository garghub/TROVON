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
static inline T_4 F_5 ( struct V_1 * V_2 ,
T_4 V_9 )
{
if ( ! F_6 ( V_9 ) )
V_9 -= V_2 -> V_13 . V_14 ;
return V_9 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 ,
T_4 V_9 , T_6 V_19 )
{
struct V_20 * V_21 ;
T_5 V_22 [ sizeof( * V_21 ) + V_23 ] ;
T_3 V_24 , V_25 , V_26 , V_27 , V_4 , V_28 ;
T_7 V_29 , V_30 ;
T_5 V_31 , * V_32 ;
int V_11 ;
V_21 = (struct V_20 * ) & V_22 ;
V_9 = F_5 ( V_2 , V_9 ) ;
if ( V_9 < 64 || V_9 > V_23 )
return - V_33 ;
V_29 = F_8 ( V_18 -> V_29 ) ;
V_30 = F_8 ( V_18 -> V_30 ) ;
V_4 = sizeof( * V_21 ) - sizeof( struct V_3 ) + V_9 ;
V_21 -> V_34 . type = V_35 ;
V_21 -> V_34 . V_4 = F_9 ( V_4 ) ;
switch ( V_16 -> V_36 ) {
case 20 :
V_21 -> V_36 = 22 ;
break;
case 40 :
V_21 -> V_36 = 44 ;
break;
case 80 :
if ( V_9 == 64 )
return - V_33 ;
V_21 -> V_36 = 88 ;
break;
default:
V_21 -> V_36 = V_16 -> V_36 ;
}
V_21 -> V_37 = F_10 ( V_30 , V_38 ) ;
V_21 -> V_39 = F_10 ( V_30 , V_40 ) ;
V_28 = F_10 ( V_30 , V_41 ) ;
V_21 -> V_8 = F_9 ( V_28 ) ;
V_21 -> V_7 = F_10 ( V_29 , V_42 ) ;
V_21 -> V_43 = V_16 -> V_44 ;
V_26 = F_10 ( V_29 , V_45 ) ;
V_27 = F_10 ( V_29 , V_46 ) ;
V_21 -> V_26 = F_9 ( V_26 ) ;
V_21 -> V_27 = F_9 ( V_27 ) ;
V_24 = V_16 -> V_24 ;
V_25 = V_16 -> V_25 ;
V_21 -> V_24 = F_9 ( V_24 ) ;
V_21 -> V_25 = F_9 ( V_25 ) ;
V_31 = F_10 ( V_29 , V_47 ) ;
V_21 -> V_48 = F_9 ( V_16 -> V_49 [ V_31 ] ) ;
V_32 = ( T_5 * ) V_18 ;
V_32 += sizeof( * V_18 ) ;
V_21 -> V_19 = F_11 ( V_19 ) ;
V_21 -> V_12 = F_4 ( V_21 -> V_7 , V_28 ,
V_9 , V_32 ) ;
memcpy ( V_21 -> V_10 , V_32 , V_9 ) ;
V_11 = V_9 / 2 ;
V_21 -> V_10 [ V_11 ] = ( V_21 -> V_10 [ V_11 + 1 ] +
V_21 -> V_10 [ V_11 - 1 ] ) / 2 ;
F_1 ( V_2 , & V_21 -> V_34 ) ;
return 0 ;
}
static struct V_50 * F_12 ( struct V_1 * V_2 )
{
struct V_50 * V_51 ;
F_13 ( & V_2 -> V_52 ) ;
if ( F_14 ( & V_2 -> V_53 ) )
return NULL ;
F_15 (arvif, &ar->arvifs, list)
if ( V_51 -> V_54 )
return V_51 ;
return F_16 ( & V_2 -> V_53 , F_17 ( * V_51 ) , V_55 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_50 * V_51 ;
int V_56 ;
int V_57 ;
F_13 ( & V_2 -> V_52 ) ;
V_51 = F_12 ( V_2 ) ;
if ( ! V_51 )
return - V_58 ;
V_57 = V_51 -> V_57 ;
if ( V_2 -> V_5 . V_59 == V_60 )
return 0 ;
V_56 = F_19 ( V_2 , V_57 ,
V_61 ,
V_62 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_19 ( V_2 , V_57 ,
V_63 ,
V_62 ) ;
if ( V_56 < 0 )
return V_56 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
enum V_64 V_59 )
{
struct V_65 V_66 ;
struct V_50 * V_51 ;
int V_57 , V_67 , V_56 = 0 ;
F_13 ( & V_2 -> V_52 ) ;
V_51 = F_12 ( V_2 ) ;
if ( ! V_51 )
return - V_58 ;
V_57 = V_51 -> V_57 ;
V_51 -> V_54 = ( V_59 != V_60 ) ;
V_2 -> V_5 . V_59 = V_59 ;
V_56 = F_19 ( V_2 , V_57 ,
V_61 ,
V_68 ) ;
if ( V_56 < 0 ) {
F_21 ( V_2 , L_1 , V_56 ) ;
return V_56 ;
}
if ( V_59 == V_60 )
return 0 ;
if ( V_59 == V_69 )
V_67 = V_70 ;
else
V_67 = F_22 ( T_5 , 1 , V_2 -> V_5 . V_71 . V_67 ) ;
V_66 . V_57 = V_57 ;
V_66 . V_72 = V_67 ;
V_66 . V_73 = V_74 ;
V_66 . V_75 = V_76 ;
V_66 . V_77 = V_2 -> V_5 . V_71 . V_78 ;
V_66 . V_79 = V_80 ;
V_66 . V_81 = V_82 ;
V_66 . V_83 = V_84 ;
V_66 . V_85 = V_86 ;
V_66 . V_87 = V_88 ;
V_66 . V_89 = V_90 ;
V_66 . V_91 = V_92 ;
V_66 . V_93 = V_94 ;
V_66 . V_95 = V_96 ;
V_66 . V_97 = V_98 ;
V_66 . V_99 = V_100 ;
V_66 . V_101 = V_102 ;
V_66 . V_103 = V_104 ;
V_66 . V_105 = V_106 ;
V_56 = F_23 ( V_2 , & V_66 ) ;
if ( V_56 < 0 ) {
F_21 ( V_2 , L_2 , V_56 ) ;
return V_56 ;
}
return 0 ;
}
static T_8 F_24 ( struct V_107 * V_107 , char T_9 * V_108 ,
T_4 V_67 , T_10 * V_109 )
{
struct V_1 * V_2 = V_107 -> V_110 ;
char * V_59 = L_3 ;
T_4 V_111 ;
enum V_64 V_112 ;
F_25 ( & V_2 -> V_52 ) ;
V_112 = V_2 -> V_5 . V_59 ;
F_26 ( & V_2 -> V_52 ) ;
switch ( V_112 ) {
case V_60 :
V_59 = L_4 ;
break;
case V_69 :
V_59 = L_5 ;
break;
case V_113 :
V_59 = L_6 ;
break;
}
V_111 = strlen ( V_59 ) ;
return F_27 ( V_108 , V_67 , V_109 , V_59 , V_111 ) ;
}
static T_8 F_28 ( struct V_107 * V_107 ,
const char T_9 * V_108 ,
T_4 V_67 , T_10 * V_109 )
{
struct V_1 * V_2 = V_107 -> V_110 ;
char V_22 [ 32 ] ;
T_8 V_111 ;
int V_56 ;
V_111 = F_29 ( V_67 , sizeof( V_22 ) - 1 ) ;
if ( F_30 ( V_22 , V_108 , V_111 ) )
return - V_114 ;
V_22 [ V_111 ] = '\0' ;
F_25 ( & V_2 -> V_52 ) ;
if ( strncmp ( L_7 , V_22 , 7 ) == 0 ) {
if ( V_2 -> V_5 . V_59 == V_113 ||
V_2 -> V_5 . V_59 == V_69 ) {
V_56 = F_20 ( V_2 ,
V_2 -> V_5 . V_59 ) ;
if ( V_56 < 0 ) {
F_21 ( V_2 , L_8 ,
V_56 ) ;
}
V_56 = F_18 ( V_2 ) ;
if ( V_56 < 0 ) {
F_21 ( V_2 , L_9 ,
V_56 ) ;
}
} else {
V_56 = - V_33 ;
}
} else if ( strncmp ( L_5 , V_22 , 10 ) == 0 ) {
V_56 = F_20 ( V_2 , V_69 ) ;
} else if ( strncmp ( L_6 , V_22 , 6 ) == 0 ) {
V_56 = F_20 ( V_2 , V_113 ) ;
} else if ( strncmp ( L_4 , V_22 , 7 ) == 0 ) {
V_56 = F_20 ( V_2 , V_60 ) ;
} else {
V_56 = - V_33 ;
}
F_26 ( & V_2 -> V_52 ) ;
if ( V_56 < 0 )
return V_56 ;
return V_67 ;
}
static T_8 F_31 ( struct V_107 * V_107 ,
char T_9 * V_108 ,
T_4 V_67 , T_10 * V_109 )
{
struct V_1 * V_2 = V_107 -> V_110 ;
char V_22 [ 32 ] ;
T_4 V_111 ;
T_5 V_115 ;
F_25 ( & V_2 -> V_52 ) ;
V_115 = V_2 -> V_5 . V_71 . V_67 ;
F_26 ( & V_2 -> V_52 ) ;
V_111 = sprintf ( V_22 , L_10 , V_115 ) ;
return F_27 ( V_108 , V_67 , V_109 , V_22 , V_111 ) ;
}
static T_8 F_32 ( struct V_107 * V_107 ,
const char T_9 * V_108 ,
T_4 V_67 , T_10 * V_109 )
{
struct V_1 * V_2 = V_107 -> V_110 ;
unsigned long V_116 ;
char V_22 [ 32 ] ;
T_8 V_111 ;
V_111 = F_29 ( V_67 , sizeof( V_22 ) - 1 ) ;
if ( F_30 ( V_22 , V_108 , V_111 ) )
return - V_114 ;
V_22 [ V_111 ] = '\0' ;
if ( F_33 ( V_22 , 0 , & V_116 ) )
return - V_33 ;
if ( V_116 < 0 || V_116 > 255 )
return - V_33 ;
F_25 ( & V_2 -> V_52 ) ;
V_2 -> V_5 . V_71 . V_67 = V_116 ;
F_26 ( & V_2 -> V_52 ) ;
return V_67 ;
}
static T_8 F_34 ( struct V_107 * V_107 ,
char T_9 * V_108 ,
T_4 V_67 , T_10 * V_109 )
{
struct V_1 * V_2 = V_107 -> V_110 ;
char V_22 [ 32 ] ;
unsigned int V_32 , V_78 , V_117 ;
T_4 V_111 ;
F_25 ( & V_2 -> V_52 ) ;
V_78 = V_2 -> V_5 . V_71 . V_78 ;
V_117 = V_102 ;
V_32 = 1 << ( V_78 - V_117 ) ;
F_26 ( & V_2 -> V_52 ) ;
V_111 = sprintf ( V_22 , L_10 , V_32 ) ;
return F_27 ( V_108 , V_67 , V_109 , V_22 , V_111 ) ;
}
static T_8 F_35 ( struct V_107 * V_107 ,
const char T_9 * V_108 ,
T_4 V_67 , T_10 * V_109 )
{
struct V_1 * V_2 = V_107 -> V_110 ;
unsigned long V_116 ;
char V_22 [ 32 ] ;
T_8 V_111 ;
V_111 = F_29 ( V_67 , sizeof( V_22 ) - 1 ) ;
if ( F_30 ( V_22 , V_108 , V_111 ) )
return - V_114 ;
V_22 [ V_111 ] = '\0' ;
if ( F_33 ( V_22 , 0 , & V_116 ) )
return - V_33 ;
if ( V_116 < 64 || V_116 > V_23 )
return - V_33 ;
if ( ! F_6 ( V_116 ) )
return - V_33 ;
F_25 ( & V_2 -> V_52 ) ;
V_2 -> V_5 . V_71 . V_78 = F_36 ( V_116 ) ;
V_2 -> V_5 . V_71 . V_78 += V_102 ;
F_26 ( & V_2 -> V_52 ) ;
return V_67 ;
}
static struct V_118 * F_37 ( const char * V_119 ,
struct V_118 * V_120 ,
T_11 V_59 ,
struct V_121 * V_22 ,
int * V_122 )
{
struct V_118 * V_123 ;
V_123 = F_38 ( V_119 , V_59 , V_120 , V_22 ,
& V_124 ) ;
* V_122 = 1 ;
return V_123 ;
}
static int F_39 ( struct V_118 * V_118 )
{
F_40 ( V_118 ) ;
return 0 ;
}
int F_41 ( struct V_1 * V_2 )
{
struct V_50 * V_51 ;
F_13 ( & V_2 -> V_52 ) ;
F_15 (arvif, &ar->arvifs, list)
V_51 -> V_54 = 0 ;
V_2 -> V_5 . V_59 = V_60 ;
V_2 -> V_5 . V_71 . V_67 = V_70 ;
V_2 -> V_5 . V_71 . V_78 = V_125 ;
return 0 ;
}
int F_42 ( struct V_50 * V_51 )
{
if ( ! V_51 -> V_54 )
return 0 ;
return F_20 ( V_51 -> V_2 , V_60 ) ;
}
int F_43 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_6 = F_44 ( L_11 ,
V_2 -> V_126 . V_127 ,
1140 , 2500 ,
& V_128 , NULL ) ;
F_38 ( L_12 ,
0600 ,
V_2 -> V_126 . V_127 , V_2 ,
& V_129 ) ;
F_38 ( L_13 ,
0600 ,
V_2 -> V_126 . V_127 , V_2 ,
& V_130 ) ;
F_38 ( L_14 ,
0600 ,
V_2 -> V_126 . V_127 , V_2 ,
& V_131 ) ;
return 0 ;
}
void F_45 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_6 ) {
F_46 ( V_2 -> V_5 . V_6 ) ;
V_2 -> V_5 . V_6 = NULL ;
}
}

static int F_1 ( struct V_1 * V_1 , struct V_2 T_1 * V_3 )
{
struct V_2 V_4 ;
int error ;
if ( F_2 ( & V_4 , V_3 , sizeof( struct V_2 ) ) )
return - V_5 ;
V_4 . V_6 [ V_7 - 1 ] = 0 ;
error = F_3 ( V_1 , V_4 . V_6 , V_4 . V_8 ) ;
if ( error )
return error ;
if ( F_4 ( V_3 , & V_4 , sizeof( struct V_2 ) ) )
return - V_5 ;
return 0 ;
}
int F_5 ( unsigned int V_9 , T_2 * V_10 )
{
if ( V_9 >= V_11 )
return - V_12 ;
V_13 [ V_9 ] = V_10 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_1 , char T_1 * V_3 )
{
struct V_14 V_15 ;
struct V_16 * V_17 ;
char T_1 * V_18 ;
int V_19 ;
int V_20 ;
int V_21 ;
if ( F_2 ( & V_15 , V_3 , sizeof( struct V_14 ) ) )
return - V_5 ;
V_18 = V_15 . V_22 ;
V_19 = V_15 . V_23 ;
V_20 = 0 ;
F_7 (net, dev) {
for ( V_21 = 0 ; V_21 < V_11 ; V_21 ++ ) {
if ( V_13 [ V_21 ] ) {
int V_24 ;
if ( ! V_18 )
V_24 = V_13 [ V_21 ] ( V_17 , NULL , 0 ) ;
else
V_24 = V_13 [ V_21 ] ( V_17 , V_18 + V_20 ,
V_19 - V_20 ) ;
if ( V_24 < 0 )
return - V_5 ;
V_20 += V_24 ;
}
}
}
V_15 . V_23 = V_20 ;
return F_4 ( V_3 , & V_15 , sizeof( struct V_14 ) ) ? - V_5 : 0 ;
}
static int F_8 ( struct V_1 * V_1 , struct V_2 * V_4 , unsigned int V_25 )
{
int V_26 ;
struct V_16 * V_17 = F_9 ( V_1 , V_4 -> V_6 ) ;
if ( ! V_17 )
return - V_27 ;
switch ( V_25 ) {
case V_28 :
V_4 -> V_29 = ( short ) F_10 ( V_17 ) ;
return 0 ;
case V_30 :
V_4 -> V_31 = 0 ;
return 0 ;
case V_32 :
V_4 -> V_33 = V_17 -> V_34 ;
return 0 ;
case V_35 :
if ( ! V_17 -> V_36 )
memset ( V_4 -> V_37 . V_38 , 0 ,
sizeof( V_4 -> V_37 . V_38 ) ) ;
else
memcpy ( V_4 -> V_37 . V_38 , V_17 -> V_39 ,
F_11 ( sizeof( V_4 -> V_37 . V_38 ) ,
( V_40 ) V_17 -> V_36 ) ) ;
V_4 -> V_37 . V_41 = V_17 -> type ;
return 0 ;
case V_42 :
V_26 = - V_12 ;
break;
case V_43 :
V_4 -> V_44 . V_45 = V_17 -> V_45 ;
V_4 -> V_44 . V_46 = V_17 -> V_46 ;
V_4 -> V_44 . V_47 = V_17 -> V_47 ;
V_4 -> V_44 . V_48 = V_17 -> V_48 ;
V_4 -> V_44 . V_49 = V_17 -> V_49 ;
V_4 -> V_44 . V_50 = V_17 -> V_51 ;
return 0 ;
case V_52 :
V_4 -> V_8 = V_17 -> V_53 ;
return 0 ;
case V_54 :
V_4 -> V_55 = V_17 -> V_56 ;
return 0 ;
default:
F_12 ( 1 ) ;
V_26 = - V_57 ;
break;
}
return V_26 ;
}
static int F_13 ( struct V_2 * V_4 )
{
struct V_58 V_59 ;
enum V_60 V_61 ;
enum V_62 V_63 ;
int V_64 = 0 ;
int V_65 = 0 ;
if ( F_2 ( & V_59 , V_4 -> V_66 , sizeof( V_59 ) ) )
return - V_5 ;
if ( V_59 . V_67 )
return - V_12 ;
V_61 = V_59 . V_61 ;
V_63 = V_59 . V_63 ;
switch ( V_61 ) {
case V_68 :
case V_69 :
case V_70 :
V_64 = 1 ;
break;
}
switch ( V_63 ) {
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
V_65 = 1 ;
break;
}
if ( ! V_64 || ! V_65 )
return - V_87 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_1 , struct V_2 * V_4 , unsigned int V_25 )
{
int V_26 ;
struct V_16 * V_17 = F_15 ( V_1 , V_4 -> V_6 ) ;
const struct V_88 * V_89 ;
if ( ! V_17 )
return - V_27 ;
V_89 = V_17 -> V_90 ;
switch ( V_25 ) {
case V_91 :
return F_16 ( V_17 , V_4 -> V_29 ) ;
case V_92 :
return - V_93 ;
case V_94 :
return F_17 ( V_17 , V_4 -> V_33 ) ;
case V_95 :
if ( V_17 -> V_36 > sizeof( struct V_96 ) )
return - V_12 ;
return F_18 ( V_17 , & V_4 -> V_37 ) ;
case V_97 :
if ( V_4 -> V_37 . V_41 != V_17 -> type )
return - V_12 ;
memcpy ( V_17 -> V_98 , V_4 -> V_37 . V_38 ,
F_11 ( sizeof( V_4 -> V_37 . V_38 ) ,
( V_40 ) V_17 -> V_36 ) ) ;
F_19 ( V_99 , V_17 ) ;
return 0 ;
case V_100 :
if ( V_89 -> V_101 ) {
if ( ! F_20 ( V_17 ) )
return - V_27 ;
return V_89 -> V_101 ( V_17 , & V_4 -> V_44 ) ;
}
return - V_93 ;
case V_102 :
if ( ! V_89 -> V_103 ||
V_4 -> V_37 . V_41 != V_104 )
return - V_12 ;
if ( ! F_20 ( V_17 ) )
return - V_27 ;
return F_21 ( V_17 , V_4 -> V_37 . V_38 ) ;
case V_105 :
if ( ! V_89 -> V_103 ||
V_4 -> V_37 . V_41 != V_104 )
return - V_12 ;
if ( ! F_20 ( V_17 ) )
return - V_27 ;
return F_22 ( V_17 , V_4 -> V_37 . V_38 ) ;
case V_106 :
if ( V_4 -> V_55 < 0 )
return - V_12 ;
if ( V_17 -> V_56 ^ V_4 -> V_55 ) {
unsigned int V_107 = V_17 -> V_56 ;
V_17 -> V_56 = V_4 -> V_55 ;
V_26 = F_19 (
V_108 , V_17 ) ;
V_26 = F_23 ( V_26 ) ;
if ( V_26 ) {
V_17 -> V_56 = V_107 ;
return V_26 ;
}
}
return 0 ;
case V_109 :
V_4 -> V_110 [ V_7 - 1 ] = '\0' ;
return F_24 ( V_17 , V_4 -> V_110 ) ;
case V_111 :
V_26 = F_13 ( V_4 ) ;
if ( V_26 )
return V_26 ;
default:
if ( ( V_25 >= V_112 &&
V_25 <= V_112 + 15 ) ||
V_25 == V_113 ||
V_25 == V_114 ||
V_25 == V_115 ||
V_25 == V_116 ||
V_25 == V_117 ||
V_25 == V_118 ||
V_25 == V_119 ||
V_25 == V_120 ||
V_25 == V_121 ||
V_25 == V_122 ||
V_25 == V_123 ||
V_25 == V_111 ||
V_25 == V_124 ||
V_25 == V_125 ) {
V_26 = - V_93 ;
if ( V_89 -> V_126 ) {
if ( F_20 ( V_17 ) )
V_26 = V_89 -> V_126 ( V_17 , V_4 , V_25 ) ;
else
V_26 = - V_27 ;
}
} else
V_26 = - V_12 ;
}
return V_26 ;
}
void F_25 ( struct V_1 * V_1 , const char * V_127 )
{
struct V_16 * V_17 ;
int V_128 ;
F_26 () ;
V_17 = F_9 ( V_1 , V_127 ) ;
F_27 () ;
V_128 = ! V_17 ;
if ( V_128 && F_28 ( V_129 ) )
V_128 = F_29 ( L_1 , V_127 ) ;
if ( V_128 && F_28 ( V_130 ) )
F_29 ( L_2 , V_127 ) ;
}
int F_30 ( struct V_1 * V_1 , unsigned int V_25 , void T_1 * V_3 )
{
struct V_2 V_4 ;
int V_131 ;
char * V_132 ;
if ( V_25 == V_133 ) {
F_31 () ;
V_131 = F_6 ( V_1 , ( char T_1 * ) V_3 ) ;
F_32 () ;
return V_131 ;
}
if ( V_25 == V_134 )
return F_1 ( V_1 , (struct V_2 T_1 * ) V_3 ) ;
if ( V_25 >= V_135 && V_25 <= V_136 ) {
struct V_137 V_138 ;
if ( F_2 ( & V_138 , V_3 , sizeof( V_138 ) ) )
return - V_5 ;
V_138 . V_6 [ sizeof( V_138 . V_6 ) - 1 ] = 0 ;
return F_33 ( V_1 , & V_138 , V_25 , V_3 ) ;
}
if ( F_2 ( & V_4 , V_3 , sizeof( struct V_2 ) ) )
return - V_5 ;
V_4 . V_6 [ V_7 - 1 ] = 0 ;
V_132 = strchr ( V_4 . V_6 , ':' ) ;
if ( V_132 )
* V_132 = 0 ;
switch ( V_25 ) {
case V_28 :
case V_30 :
case V_32 :
case V_35 :
case V_42 :
case V_43 :
case V_52 :
case V_54 :
F_25 ( V_1 , V_4 . V_6 ) ;
F_26 () ;
V_131 = F_8 ( V_1 , & V_4 , V_25 ) ;
F_27 () ;
if ( ! V_131 ) {
if ( V_132 )
* V_132 = ':' ;
if ( F_4 ( V_3 , & V_4 ,
sizeof( struct V_2 ) ) )
V_131 = - V_5 ;
}
return V_131 ;
case V_139 :
F_25 ( V_1 , V_4 . V_6 ) ;
F_31 () ;
V_131 = F_34 ( V_1 , & V_4 ) ;
F_32 () ;
if ( ! V_131 ) {
if ( V_132 )
* V_132 = ':' ;
if ( F_4 ( V_3 , & V_4 ,
sizeof( struct V_2 ) ) )
V_131 = - V_5 ;
}
return V_131 ;
case V_119 :
case V_120 :
case V_109 :
if ( ! F_35 ( V_1 -> V_140 , V_129 ) )
return - V_141 ;
F_25 ( V_1 , V_4 . V_6 ) ;
F_31 () ;
V_131 = F_14 ( V_1 , & V_4 , V_25 ) ;
F_32 () ;
if ( ! V_131 ) {
if ( V_132 )
* V_132 = ':' ;
if ( F_4 ( V_3 , & V_4 ,
sizeof( struct V_2 ) ) )
V_131 = - V_5 ;
}
return V_131 ;
case V_100 :
case V_106 :
if ( ! F_28 ( V_129 ) )
return - V_141 ;
case V_91 :
case V_92 :
case V_94 :
case V_95 :
case V_142 :
case V_102 :
case V_105 :
case V_97 :
case V_121 :
case V_113 :
case V_114 :
case V_115 :
case V_118 :
case V_122 :
case V_123 :
case V_111 :
if ( ! F_35 ( V_1 -> V_140 , V_129 ) )
return - V_141 ;
case V_116 :
case V_117 :
F_25 ( V_1 , V_4 . V_6 ) ;
F_31 () ;
V_131 = F_14 ( V_1 , & V_4 , V_25 ) ;
F_32 () ;
return V_131 ;
case V_143 :
case V_144 :
case V_145 :
return - V_57 ;
default:
if ( V_25 == V_125 ||
V_25 == V_124 ||
( V_25 >= V_112 &&
V_25 <= V_112 + 15 ) ) {
F_25 ( V_1 , V_4 . V_6 ) ;
F_31 () ;
V_131 = F_14 ( V_1 , & V_4 , V_25 ) ;
F_32 () ;
if ( ! V_131 && F_4 ( V_3 , & V_4 ,
sizeof( struct V_2 ) ) )
V_131 = - V_5 ;
return V_131 ;
}
return - V_57 ;
}
}

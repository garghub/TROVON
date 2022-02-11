static int F_1 ( struct V_1 * V_1 , struct V_2 T_1 * V_3 )
{
struct V_2 V_4 ;
int error ;
if ( F_2 ( & V_4 , V_3 , sizeof( struct V_2 ) ) )
return - V_5 ;
error = F_3 ( V_1 , V_4 . V_6 , V_4 . V_7 ) ;
if ( error )
return error ;
if ( F_4 ( V_3 , & V_4 , sizeof( struct V_2 ) ) )
return - V_5 ;
return 0 ;
}
int F_5 ( unsigned int V_8 , T_2 * V_9 )
{
if ( V_8 >= V_10 )
return - V_11 ;
V_12 [ V_8 ] = V_9 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_1 , char T_1 * V_3 )
{
struct V_13 V_14 ;
struct V_15 * V_16 ;
char T_1 * V_17 ;
int V_18 ;
int V_19 ;
int V_20 ;
if ( F_2 ( & V_14 , V_3 , sizeof( struct V_13 ) ) )
return - V_5 ;
V_17 = V_14 . V_21 ;
V_18 = V_14 . V_22 ;
V_19 = 0 ;
F_7 (net, dev) {
for ( V_20 = 0 ; V_20 < V_10 ; V_20 ++ ) {
if ( V_12 [ V_20 ] ) {
int V_23 ;
if ( ! V_17 )
V_23 = V_12 [ V_20 ] ( V_16 , NULL , 0 ) ;
else
V_23 = V_12 [ V_20 ] ( V_16 , V_17 + V_19 ,
V_18 - V_19 ) ;
if ( V_23 < 0 )
return - V_5 ;
V_19 += V_23 ;
}
}
}
V_14 . V_22 = V_19 ;
return F_4 ( V_3 , & V_14 , sizeof( struct V_13 ) ) ? - V_5 : 0 ;
}
static int F_8 ( struct V_1 * V_1 , struct V_2 * V_4 , unsigned int V_24 )
{
int V_25 ;
struct V_15 * V_16 = F_9 ( V_1 , V_4 -> V_6 ) ;
if ( ! V_16 )
return - V_26 ;
switch ( V_24 ) {
case V_27 :
V_4 -> V_28 = ( short ) F_10 ( V_16 ) ;
return 0 ;
case V_29 :
V_4 -> V_30 = 0 ;
return 0 ;
case V_31 :
V_4 -> V_32 = V_16 -> V_33 ;
return 0 ;
case V_34 :
if ( ! V_16 -> V_35 )
memset ( V_4 -> V_36 . V_37 , 0 , sizeof V_4 -> V_36 . V_37 ) ;
else
memcpy ( V_4 -> V_36 . V_37 , V_16 -> V_38 ,
F_11 ( sizeof V_4 -> V_36 . V_37 , ( V_39 ) V_16 -> V_35 ) ) ;
V_4 -> V_36 . V_40 = V_16 -> type ;
return 0 ;
case V_41 :
V_25 = - V_11 ;
break;
case V_42 :
V_4 -> V_43 . V_44 = V_16 -> V_44 ;
V_4 -> V_43 . V_45 = V_16 -> V_45 ;
V_4 -> V_43 . V_46 = V_16 -> V_46 ;
V_4 -> V_43 . V_47 = V_16 -> V_47 ;
V_4 -> V_43 . V_48 = V_16 -> V_48 ;
V_4 -> V_43 . V_49 = V_16 -> V_50 ;
return 0 ;
case V_51 :
V_4 -> V_7 = V_16 -> V_52 ;
return 0 ;
case V_53 :
V_4 -> V_54 = V_16 -> V_55 ;
return 0 ;
default:
F_12 ( 1 ) ;
V_25 = - V_56 ;
break;
}
return V_25 ;
}
static int F_13 ( struct V_2 * V_4 )
{
struct V_57 V_58 ;
enum V_59 V_60 ;
enum V_61 V_62 ;
int V_63 = 0 ;
int V_64 = 0 ;
if ( F_2 ( & V_58 , V_4 -> V_65 , sizeof( V_58 ) ) )
return - V_5 ;
if ( V_58 . V_66 )
return - V_11 ;
V_60 = V_58 . V_60 ;
V_62 = V_58 . V_62 ;
switch ( V_60 ) {
case V_67 :
case V_68 :
case V_69 :
V_63 = 1 ;
break;
}
switch ( V_62 ) {
case V_70 :
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
V_64 = 1 ;
break;
}
if ( ! V_63 || ! V_64 )
return - V_85 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_1 , struct V_2 * V_4 , unsigned int V_24 )
{
int V_25 ;
struct V_15 * V_16 = F_15 ( V_1 , V_4 -> V_6 ) ;
const struct V_86 * V_87 ;
if ( ! V_16 )
return - V_26 ;
V_87 = V_16 -> V_88 ;
switch ( V_24 ) {
case V_89 :
return F_16 ( V_16 , V_4 -> V_28 ) ;
case V_90 :
return - V_91 ;
case V_92 :
return F_17 ( V_16 , V_4 -> V_32 ) ;
case V_93 :
return F_18 ( V_16 , & V_4 -> V_36 ) ;
case V_94 :
if ( V_4 -> V_36 . V_40 != V_16 -> type )
return - V_11 ;
memcpy ( V_16 -> V_95 , V_4 -> V_36 . V_37 ,
F_11 ( sizeof V_4 -> V_36 . V_37 , ( V_39 ) V_16 -> V_35 ) ) ;
F_19 ( V_96 , V_16 ) ;
return 0 ;
case V_97 :
if ( V_87 -> V_98 ) {
if ( ! F_20 ( V_16 ) )
return - V_26 ;
return V_87 -> V_98 ( V_16 , & V_4 -> V_43 ) ;
}
return - V_91 ;
case V_99 :
if ( ! V_87 -> V_100 ||
V_4 -> V_36 . V_40 != V_101 )
return - V_11 ;
if ( ! F_20 ( V_16 ) )
return - V_26 ;
return F_21 ( V_16 , V_4 -> V_36 . V_37 ) ;
case V_102 :
if ( ! V_87 -> V_100 ||
V_4 -> V_36 . V_40 != V_101 )
return - V_11 ;
if ( ! F_20 ( V_16 ) )
return - V_26 ;
return F_22 ( V_16 , V_4 -> V_36 . V_37 ) ;
case V_103 :
if ( V_4 -> V_54 < 0 )
return - V_11 ;
V_16 -> V_55 = V_4 -> V_54 ;
return 0 ;
case V_104 :
V_4 -> V_105 [ V_106 - 1 ] = '\0' ;
return F_23 ( V_16 , V_4 -> V_105 ) ;
case V_107 :
V_25 = F_13 ( V_4 ) ;
if ( V_25 )
return V_25 ;
default:
if ( ( V_24 >= V_108 &&
V_24 <= V_108 + 15 ) ||
V_24 == V_109 ||
V_24 == V_110 ||
V_24 == V_111 ||
V_24 == V_112 ||
V_24 == V_113 ||
V_24 == V_114 ||
V_24 == V_115 ||
V_24 == V_116 ||
V_24 == V_117 ||
V_24 == V_118 ||
V_24 == V_119 ||
V_24 == V_107 ||
V_24 == V_120 ) {
V_25 = - V_91 ;
if ( V_87 -> V_121 ) {
if ( F_20 ( V_16 ) )
V_25 = V_87 -> V_121 ( V_16 , V_4 , V_24 ) ;
else
V_25 = - V_26 ;
}
} else
V_25 = - V_11 ;
}
return V_25 ;
}
void F_24 ( struct V_1 * V_1 , const char * V_122 )
{
struct V_15 * V_16 ;
int V_123 ;
F_25 () ;
V_16 = F_9 ( V_1 , V_122 ) ;
F_26 () ;
V_123 = ! V_16 ;
if ( V_123 && F_27 ( V_124 ) )
V_123 = F_28 ( L_1 , V_122 ) ;
if ( V_123 && F_27 ( V_125 ) ) {
if ( ! F_28 ( L_2 , V_122 ) )
F_29 ( L_3 ,
V_122 ) ;
}
}
int F_30 ( struct V_1 * V_1 , unsigned int V_24 , void T_1 * V_3 )
{
struct V_2 V_4 ;
int V_126 ;
char * V_127 ;
if ( V_24 == V_128 ) {
F_31 () ;
V_126 = F_6 ( V_1 , ( char T_1 * ) V_3 ) ;
F_32 () ;
return V_126 ;
}
if ( V_24 == V_129 )
return F_1 ( V_1 , (struct V_2 T_1 * ) V_3 ) ;
if ( F_2 ( & V_4 , V_3 , sizeof( struct V_2 ) ) )
return - V_5 ;
V_4 . V_6 [ V_106 - 1 ] = 0 ;
V_127 = strchr ( V_4 . V_6 , ':' ) ;
if ( V_127 )
* V_127 = 0 ;
switch ( V_24 ) {
case V_27 :
case V_29 :
case V_31 :
case V_34 :
case V_41 :
case V_42 :
case V_51 :
case V_53 :
F_24 ( V_1 , V_4 . V_6 ) ;
F_25 () ;
V_126 = F_8 ( V_1 , & V_4 , V_24 ) ;
F_26 () ;
if ( ! V_126 ) {
if ( V_127 )
* V_127 = ':' ;
if ( F_4 ( V_3 , & V_4 ,
sizeof( struct V_2 ) ) )
V_126 = - V_5 ;
}
return V_126 ;
case V_130 :
F_24 ( V_1 , V_4 . V_6 ) ;
F_31 () ;
V_126 = F_33 ( V_1 , & V_4 ) ;
F_32 () ;
if ( ! V_126 ) {
if ( V_127 )
* V_127 = ':' ;
if ( F_4 ( V_3 , & V_4 ,
sizeof( struct V_2 ) ) )
V_126 = - V_5 ;
}
return V_126 ;
case V_115 :
case V_116 :
case V_104 :
if ( ! F_34 ( V_1 -> V_131 , V_124 ) )
return - V_132 ;
F_24 ( V_1 , V_4 . V_6 ) ;
F_31 () ;
V_126 = F_14 ( V_1 , & V_4 , V_24 ) ;
F_32 () ;
if ( ! V_126 ) {
if ( V_127 )
* V_127 = ':' ;
if ( F_4 ( V_3 , & V_4 ,
sizeof( struct V_2 ) ) )
V_126 = - V_5 ;
}
return V_126 ;
case V_97 :
case V_103 :
if ( ! F_27 ( V_124 ) )
return - V_132 ;
case V_89 :
case V_90 :
case V_92 :
case V_93 :
case V_133 :
case V_99 :
case V_102 :
case V_94 :
case V_117 :
case V_109 :
case V_110 :
case V_111 :
case V_114 :
case V_118 :
case V_119 :
case V_107 :
if ( ! F_34 ( V_1 -> V_131 , V_124 ) )
return - V_132 ;
case V_112 :
case V_113 :
F_24 ( V_1 , V_4 . V_6 ) ;
F_31 () ;
V_126 = F_14 ( V_1 , & V_4 , V_24 ) ;
F_32 () ;
return V_126 ;
case V_134 :
case V_135 :
case V_136 :
return - V_56 ;
default:
if ( V_24 == V_120 ||
( V_24 >= V_108 &&
V_24 <= V_108 + 15 ) ) {
F_24 ( V_1 , V_4 . V_6 ) ;
F_31 () ;
V_126 = F_14 ( V_1 , & V_4 , V_24 ) ;
F_32 () ;
if ( ! V_126 && F_4 ( V_3 , & V_4 ,
sizeof( struct V_2 ) ) )
V_126 = - V_5 ;
return V_126 ;
}
if ( V_24 >= V_137 && V_24 <= V_138 )
return F_35 ( V_1 , & V_4 , V_24 , V_3 ) ;
return - V_56 ;
}
}

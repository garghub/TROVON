static int F_1 ( struct V_1 * V_1 , struct V_2 T_1 * V_3 )
{
struct V_4 * V_5 ;
struct V_2 V_6 ;
unsigned V_7 ;
if ( F_2 ( & V_6 , V_3 , sizeof( struct V_2 ) ) )
return - V_8 ;
V_9:
V_7 = F_3 ( & V_10 ) ;
F_4 () ;
V_5 = F_5 ( V_1 , V_6 . V_11 ) ;
if ( ! V_5 ) {
F_6 () ;
return - V_12 ;
}
strcpy ( V_6 . V_13 , V_5 -> V_14 ) ;
F_6 () ;
if ( F_7 ( & V_10 , V_7 ) )
goto V_9;
if ( F_8 ( V_3 , & V_6 , sizeof( struct V_2 ) ) )
return - V_8 ;
return 0 ;
}
int F_9 ( unsigned int V_15 , T_2 * V_16 )
{
if ( V_15 >= V_17 )
return - V_18 ;
V_19 [ V_15 ] = V_16 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 , char T_1 * V_3 )
{
struct V_20 V_21 ;
struct V_4 * V_5 ;
char T_1 * V_22 ;
int V_23 ;
int V_24 ;
int V_25 ;
if ( F_2 ( & V_21 , V_3 , sizeof( struct V_20 ) ) )
return - V_8 ;
V_22 = V_21 . V_26 ;
V_23 = V_21 . V_27 ;
V_24 = 0 ;
F_11 (net, dev) {
for ( V_25 = 0 ; V_25 < V_17 ; V_25 ++ ) {
if ( V_19 [ V_25 ] ) {
int V_28 ;
if ( ! V_22 )
V_28 = V_19 [ V_25 ] ( V_5 , NULL , 0 ) ;
else
V_28 = V_19 [ V_25 ] ( V_5 , V_22 + V_24 ,
V_23 - V_24 ) ;
if ( V_28 < 0 )
return - V_8 ;
V_24 += V_28 ;
}
}
}
V_21 . V_27 = V_24 ;
return F_8 ( V_3 , & V_21 , sizeof( struct V_20 ) ) ? - V_8 : 0 ;
}
static int F_12 ( struct V_1 * V_1 , struct V_2 * V_6 , unsigned int V_29 )
{
int V_30 ;
struct V_4 * V_5 = F_13 ( V_1 , V_6 -> V_13 ) ;
if ( ! V_5 )
return - V_12 ;
switch ( V_29 ) {
case V_31 :
V_6 -> V_32 = ( short ) F_14 ( V_5 ) ;
return 0 ;
case V_33 :
V_6 -> V_34 = 0 ;
return 0 ;
case V_35 :
V_6 -> V_36 = V_5 -> V_37 ;
return 0 ;
case V_38 :
if ( ! V_5 -> V_39 )
memset ( V_6 -> V_40 . V_41 , 0 , sizeof V_6 -> V_40 . V_41 ) ;
else
memcpy ( V_6 -> V_40 . V_41 , V_5 -> V_42 ,
F_15 ( sizeof V_6 -> V_40 . V_41 , ( V_43 ) V_5 -> V_39 ) ) ;
V_6 -> V_40 . V_44 = V_5 -> type ;
return 0 ;
case V_45 :
V_30 = - V_18 ;
break;
case V_46 :
V_6 -> V_47 . V_48 = V_5 -> V_48 ;
V_6 -> V_47 . V_49 = V_5 -> V_49 ;
V_6 -> V_47 . V_50 = V_5 -> V_50 ;
V_6 -> V_47 . V_51 = V_5 -> V_51 ;
V_6 -> V_47 . V_52 = V_5 -> V_52 ;
V_6 -> V_47 . V_53 = V_5 -> V_54 ;
return 0 ;
case V_55 :
V_6 -> V_11 = V_5 -> V_56 ;
return 0 ;
case V_57 :
V_6 -> V_58 = V_5 -> V_59 ;
return 0 ;
default:
F_16 ( 1 ) ;
V_30 = - V_60 ;
break;
}
return V_30 ;
}
static int F_17 ( struct V_2 * V_6 )
{
struct V_61 V_62 ;
enum V_63 V_64 ;
enum V_65 V_66 ;
int V_67 = 0 ;
int V_68 = 0 ;
if ( F_2 ( & V_62 , V_6 -> V_69 , sizeof( V_62 ) ) )
return - V_8 ;
if ( V_62 . V_70 )
return - V_18 ;
V_64 = V_62 . V_64 ;
V_66 = V_62 . V_66 ;
switch ( V_64 ) {
case V_71 :
case V_72 :
case V_73 :
V_67 = 1 ;
break;
}
switch ( V_66 ) {
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
case V_87 :
case V_88 :
V_68 = 1 ;
break;
}
if ( ! V_67 || ! V_68 )
return - V_89 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_1 , struct V_2 * V_6 , unsigned int V_29 )
{
int V_30 ;
struct V_4 * V_5 = F_19 ( V_1 , V_6 -> V_13 ) ;
const struct V_90 * V_91 ;
if ( ! V_5 )
return - V_12 ;
V_91 = V_5 -> V_92 ;
switch ( V_29 ) {
case V_93 :
return F_20 ( V_5 , V_6 -> V_32 ) ;
case V_94 :
return - V_95 ;
case V_96 :
return F_21 ( V_5 , V_6 -> V_36 ) ;
case V_97 :
return F_22 ( V_5 , & V_6 -> V_40 ) ;
case V_98 :
if ( V_6 -> V_40 . V_44 != V_5 -> type )
return - V_18 ;
memcpy ( V_5 -> V_99 , V_6 -> V_40 . V_41 ,
F_15 ( sizeof V_6 -> V_40 . V_41 , ( V_43 ) V_5 -> V_39 ) ) ;
F_23 ( V_100 , V_5 ) ;
return 0 ;
case V_101 :
if ( V_91 -> V_102 ) {
if ( ! F_24 ( V_5 ) )
return - V_12 ;
return V_91 -> V_102 ( V_5 , & V_6 -> V_47 ) ;
}
return - V_95 ;
case V_103 :
if ( ! V_91 -> V_104 ||
V_6 -> V_40 . V_44 != V_105 )
return - V_18 ;
if ( ! F_24 ( V_5 ) )
return - V_12 ;
return F_25 ( V_5 , V_6 -> V_40 . V_41 ) ;
case V_106 :
if ( ! V_91 -> V_104 ||
V_6 -> V_40 . V_44 != V_105 )
return - V_18 ;
if ( ! F_24 ( V_5 ) )
return - V_12 ;
return F_26 ( V_5 , V_6 -> V_40 . V_41 ) ;
case V_107 :
if ( V_6 -> V_58 < 0 )
return - V_18 ;
V_5 -> V_59 = V_6 -> V_58 ;
return 0 ;
case V_108 :
V_6 -> V_109 [ V_110 - 1 ] = '\0' ;
return F_27 ( V_5 , V_6 -> V_109 ) ;
case V_111 :
V_30 = F_17 ( V_6 ) ;
if ( V_30 )
return V_30 ;
default:
if ( ( V_29 >= V_112 &&
V_29 <= V_112 + 15 ) ||
V_29 == V_113 ||
V_29 == V_114 ||
V_29 == V_115 ||
V_29 == V_116 ||
V_29 == V_117 ||
V_29 == V_118 ||
V_29 == V_119 ||
V_29 == V_120 ||
V_29 == V_121 ||
V_29 == V_122 ||
V_29 == V_123 ||
V_29 == V_111 ||
V_29 == V_124 ) {
V_30 = - V_95 ;
if ( V_91 -> V_125 ) {
if ( F_24 ( V_5 ) )
V_30 = V_91 -> V_125 ( V_5 , V_6 , V_29 ) ;
else
V_30 = - V_12 ;
}
} else
V_30 = - V_18 ;
}
return V_30 ;
}
void F_28 ( struct V_1 * V_1 , const char * V_14 )
{
struct V_4 * V_5 ;
int V_126 ;
F_4 () ;
V_5 = F_13 ( V_1 , V_14 ) ;
F_6 () ;
V_126 = ! V_5 ;
if ( V_126 && F_29 ( V_127 ) )
V_126 = F_30 ( L_1 , V_14 ) ;
if ( V_126 && F_29 ( V_128 ) ) {
if ( ! F_30 ( L_2 , V_14 ) )
F_31 ( L_3 ,
V_14 ) ;
}
}
int F_32 ( struct V_1 * V_1 , unsigned int V_29 , void T_1 * V_3 )
{
struct V_2 V_6 ;
int V_129 ;
char * V_130 ;
if ( V_29 == V_131 ) {
F_33 () ;
V_129 = F_10 ( V_1 , ( char T_1 * ) V_3 ) ;
F_34 () ;
return V_129 ;
}
if ( V_29 == V_132 )
return F_1 ( V_1 , (struct V_2 T_1 * ) V_3 ) ;
if ( F_2 ( & V_6 , V_3 , sizeof( struct V_2 ) ) )
return - V_8 ;
V_6 . V_13 [ V_110 - 1 ] = 0 ;
V_130 = strchr ( V_6 . V_13 , ':' ) ;
if ( V_130 )
* V_130 = 0 ;
switch ( V_29 ) {
case V_31 :
case V_33 :
case V_35 :
case V_38 :
case V_45 :
case V_46 :
case V_55 :
case V_57 :
F_28 ( V_1 , V_6 . V_13 ) ;
F_4 () ;
V_129 = F_12 ( V_1 , & V_6 , V_29 ) ;
F_6 () ;
if ( ! V_129 ) {
if ( V_130 )
* V_130 = ':' ;
if ( F_8 ( V_3 , & V_6 ,
sizeof( struct V_2 ) ) )
V_129 = - V_8 ;
}
return V_129 ;
case V_133 :
F_28 ( V_1 , V_6 . V_13 ) ;
F_33 () ;
V_129 = F_35 ( V_1 , & V_6 ) ;
F_34 () ;
if ( ! V_129 ) {
if ( V_130 )
* V_130 = ':' ;
if ( F_8 ( V_3 , & V_6 ,
sizeof( struct V_2 ) ) )
V_129 = - V_8 ;
}
return V_129 ;
case V_119 :
case V_120 :
case V_108 :
if ( ! F_36 ( V_1 -> V_134 , V_127 ) )
return - V_135 ;
F_28 ( V_1 , V_6 . V_13 ) ;
F_33 () ;
V_129 = F_18 ( V_1 , & V_6 , V_29 ) ;
F_34 () ;
if ( ! V_129 ) {
if ( V_130 )
* V_130 = ':' ;
if ( F_8 ( V_3 , & V_6 ,
sizeof( struct V_2 ) ) )
V_129 = - V_8 ;
}
return V_129 ;
case V_101 :
case V_107 :
if ( ! F_29 ( V_127 ) )
return - V_135 ;
case V_93 :
case V_94 :
case V_96 :
case V_97 :
case V_136 :
case V_103 :
case V_106 :
case V_98 :
case V_121 :
case V_113 :
case V_114 :
case V_115 :
case V_118 :
case V_122 :
case V_123 :
case V_111 :
if ( ! F_36 ( V_1 -> V_134 , V_127 ) )
return - V_135 ;
case V_116 :
case V_117 :
F_28 ( V_1 , V_6 . V_13 ) ;
F_33 () ;
V_129 = F_18 ( V_1 , & V_6 , V_29 ) ;
F_34 () ;
return V_129 ;
case V_137 :
case V_138 :
case V_139 :
return - V_60 ;
default:
if ( V_29 == V_124 ||
( V_29 >= V_112 &&
V_29 <= V_112 + 15 ) ) {
F_28 ( V_1 , V_6 . V_13 ) ;
F_33 () ;
V_129 = F_18 ( V_1 , & V_6 , V_29 ) ;
F_34 () ;
if ( ! V_129 && F_8 ( V_3 , & V_6 ,
sizeof( struct V_2 ) ) )
V_129 = - V_8 ;
return V_129 ;
}
if ( V_29 >= V_140 && V_29 <= V_141 )
return F_37 ( V_1 , & V_6 , V_29 , V_3 ) ;
return - V_60 ;
}
}

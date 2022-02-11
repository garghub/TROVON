struct V_1 *
F_1 ( struct V_2 * V_3 )
{
const struct V_4 * V_5 = V_3 -> V_6 ;
struct V_7 * V_8 = V_7 ( V_3 -> V_9 ) ;
struct V_10 * V_9 = V_3 -> V_9 ;
struct V_1 * V_11 , * V_12 = NULL ;
int V_13 = 0 , V_14 = 0 , V_15 = 0 ;
F_2 (mode, &connector->probed_modes, head) {
V_11 -> V_16 = F_3 ( V_11 ) ;
if ( V_5 -> V_17 ( V_3 , V_11 ) != V_18 ||
( V_11 -> V_19 & V_20 ) )
continue;
if ( V_11 -> type & V_21 ) {
F_4 ( V_8 , L_1 ) ;
return F_5 ( V_9 , V_11 ) ;
}
if ( V_11 -> V_22 < V_13 )
continue;
if ( V_11 -> V_22 == V_13 && V_11 -> V_23 < V_14 )
continue;
if ( V_11 -> V_22 == V_13 && V_11 -> V_23 == V_14 &&
V_11 -> V_16 < V_15 )
continue;
V_13 = V_11 -> V_22 ;
V_14 = V_11 -> V_23 ;
V_15 = V_11 -> V_16 ;
V_12 = V_11 ;
}
F_4 ( V_8 , L_2 ,
V_13 , V_14 , V_15 ) ;
return V_12 ? F_5 ( V_9 , V_12 ) : NULL ;
}
int
F_6 ( struct V_2 * V_3 ,
const struct V_24 * V_25 ,
struct V_26 * V_27 , T_1 * V_28 )
{
struct V_29 * V_30 = V_29 ( V_25 ) ;
struct V_31 * V_32 = V_31 ( V_3 -> V_9 ) ;
struct V_10 * V_9 = V_3 -> V_9 ;
if ( V_27 == V_9 -> V_33 . V_34 )
* V_28 = V_30 -> V_35 . V_11 ;
else if ( V_27 == V_32 -> V_36 )
* V_28 = V_30 -> V_35 . V_37 . V_11 ;
else if ( V_27 == V_32 -> V_38 )
* V_28 = V_30 -> V_35 . V_37 . V_39 ;
else if ( V_27 == V_32 -> V_40 )
* V_28 = V_30 -> V_35 . V_37 . V_41 ;
else if ( V_27 == V_32 -> V_42 )
* V_28 = V_30 -> V_43 . V_11 ;
else if ( V_27 == V_32 -> V_44 )
* V_28 = V_30 -> V_43 . V_45 ;
else if ( V_27 == V_32 -> V_46 )
* V_28 = V_30 -> V_47 . V_48 ;
else if ( V_27 == V_32 -> V_49 )
* V_28 = V_30 -> V_47 . V_50 ;
else
return - V_51 ;
return 0 ;
}
int
F_7 ( struct V_2 * V_3 ,
struct V_24 * V_25 ,
struct V_26 * V_27 , T_1 V_28 )
{
struct V_10 * V_9 = V_3 -> V_9 ;
struct V_29 * V_30 = V_29 ( V_25 ) ;
struct V_31 * V_32 = V_31 ( V_9 ) ;
if ( V_27 == V_9 -> V_33 . V_34 ) {
switch ( V_28 ) {
case V_52 :
switch ( V_3 -> V_53 ) {
case V_54 :
case V_55 :
if ( V_32 -> V_32 . V_56 < V_57 )
return - V_51 ;
break;
default:
break;
}
case V_58 :
case V_59 :
case V_60 :
break;
default:
return - V_51 ;
}
if ( V_30 -> V_35 . V_11 != V_28 ) {
V_30 -> V_35 . V_11 = V_28 ;
V_30 -> V_61 . V_35 = true ;
}
} else
if ( V_27 == V_32 -> V_36 ) {
if ( V_30 -> V_35 . V_37 . V_11 != V_28 ) {
V_30 -> V_35 . V_37 . V_11 = V_28 ;
V_30 -> V_61 . V_35 = true ;
}
} else
if ( V_27 == V_32 -> V_38 ) {
if ( V_30 -> V_35 . V_37 . V_39 != V_28 ) {
V_30 -> V_35 . V_37 . V_39 = V_28 ;
V_30 -> V_61 . V_35 = true ;
}
} else
if ( V_27 == V_32 -> V_40 ) {
if ( V_30 -> V_35 . V_37 . V_41 != V_28 ) {
V_30 -> V_35 . V_37 . V_41 = V_28 ;
V_30 -> V_61 . V_35 = true ;
}
} else
if ( V_27 == V_32 -> V_42 ) {
if ( V_30 -> V_43 . V_11 != V_28 ) {
V_30 -> V_43 . V_11 = V_28 ;
V_30 -> V_61 . V_43 = true ;
}
} else
if ( V_27 == V_32 -> V_44 ) {
if ( V_30 -> V_43 . V_11 != V_28 ) {
V_30 -> V_43 . V_45 = V_28 ;
V_30 -> V_61 . V_43 = true ;
}
} else
if ( V_27 == V_32 -> V_46 ) {
if ( V_30 -> V_47 . V_48 != V_28 ) {
V_30 -> V_47 . V_48 = V_28 ;
V_30 -> V_61 . V_47 = true ;
}
} else
if ( V_27 == V_32 -> V_49 ) {
if ( V_30 -> V_47 . V_50 != V_28 ) {
V_30 -> V_47 . V_50 = V_28 ;
V_30 -> V_61 . V_47 = true ;
}
} else {
return - V_51 ;
}
return 0 ;
}
void
F_8 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_29 * V_30 = V_29 ( V_25 ) ;
F_9 ( & V_30 -> V_25 ) ;
F_10 ( V_30 ) ;
}
struct V_24 *
F_11 ( struct V_2 * V_3 )
{
struct V_29 * V_62 = V_29 ( V_3 -> V_25 ) ;
struct V_29 * V_30 ;
if ( ! ( V_30 = F_12 ( sizeof( * V_30 ) , V_63 ) ) )
return NULL ;
F_13 ( V_3 , & V_30 -> V_25 ) ;
V_30 -> V_43 = V_62 -> V_43 ;
V_30 -> V_35 = V_62 -> V_35 ;
V_30 -> V_47 = V_62 -> V_47 ;
V_30 -> V_61 . V_64 = 0 ;
return & V_30 -> V_25 ;
}
void
F_14 ( struct V_2 * V_3 )
{
struct V_29 * V_30 ;
if ( F_15 ( ! ( V_30 = F_16 ( sizeof( * V_30 ) , V_63 ) ) ) )
return;
if ( V_3 -> V_25 )
F_9 ( V_3 -> V_25 ) ;
F_17 ( V_3 , & V_30 -> V_25 ) ;
V_30 -> V_43 . V_11 = V_65 ;
V_30 -> V_43 . V_45 = V_66 ;
V_30 -> V_35 . V_11 = V_52 ;
V_30 -> V_35 . V_37 . V_11 = V_67 ;
V_30 -> V_47 . V_50 = 150 ;
V_30 -> V_47 . V_48 = 90 ;
if ( V_31 ( V_3 -> V_9 ) -> V_32 . V_56 < V_57 ) {
switch ( V_3 -> V_53 ) {
case V_54 :
V_30 -> V_35 . V_11 = V_58 ;
break;
default:
break;
}
}
}
void
F_18 ( struct V_2 * V_3 )
{
struct V_10 * V_9 = V_3 -> V_9 ;
struct V_29 * V_62 = V_29 ( V_3 -> V_25 ) ;
struct V_31 * V_32 = V_31 ( V_9 ) ;
if ( V_3 -> V_53 == V_68 )
F_19 ( & V_3 -> V_69 , V_9 -> V_33 .
V_70 , 0 ) ;
if ( V_32 -> V_36 &&
( V_3 -> V_53 == V_71 ||
V_3 -> V_53 == V_68 ||
V_3 -> V_53 == V_72 ||
V_3 -> V_53 == V_73 ) ) {
F_19 ( & V_3 -> V_69 ,
V_32 -> V_36 ,
V_67 ) ;
F_19 ( & V_3 -> V_69 ,
V_32 -> V_38 , 0 ) ;
F_19 ( & V_3 -> V_69 ,
V_32 -> V_40 , 0 ) ;
}
if ( V_32 -> V_46 )
F_19 ( & V_3 -> V_69 ,
V_32 -> V_46 ,
V_62 -> V_47 . V_48 ) ;
if ( V_32 -> V_49 )
F_19 ( & V_3 -> V_69 ,
V_32 -> V_49 ,
V_62 -> V_47 . V_50 ) ;
switch ( V_3 -> V_53 ) {
case V_74 :
break;
case V_75 :
if ( V_32 -> V_32 . V_56 < V_57 )
break;
default:
F_19 ( & V_3 -> V_69 , V_9 -> V_33 .
V_34 ,
V_62 -> V_35 . V_11 ) ;
break;
}
switch ( V_3 -> V_53 ) {
case V_74 :
case V_75 :
break;
default:
if ( V_32 -> V_42 ) {
F_19 ( & V_3 -> V_69 ,
V_32 -> V_42 ,
V_62 -> V_43 . V_11 ) ;
}
if ( V_32 -> V_44 ) {
F_19 ( & V_3 -> V_69 ,
V_32 -> V_44 ,
V_62 -> V_43 . V_45 ) ;
}
break;
}
}
struct V_76 *
F_20 ( struct V_2 * V_3 , int type )
{
struct V_10 * V_9 = V_3 -> V_9 ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
int V_80 , V_81 ;
for ( V_80 = 0 ; V_80 < V_82 ; V_80 ++ ) {
V_81 = V_3 -> V_83 [ V_80 ] ;
if ( ! V_81 )
break;
V_79 = F_21 ( V_9 , V_81 ) ;
if ( ! V_79 )
continue;
V_77 = V_76 ( V_79 ) ;
if ( type == V_84 ||
( V_77 -> V_85 && V_77 -> V_85 -> type == type ) )
return V_77 ;
}
return NULL ;
}
struct V_86 *
F_22 ( struct V_76 * V_87 )
{
struct V_10 * V_9 = F_23 ( V_87 ) -> V_9 ;
struct V_2 * V_2 ;
F_2 (drm_connector, &dev->mode_config.connector_list, head) {
if ( V_2 -> V_87 == F_23 ( V_87 ) )
return V_86 ( V_2 ) ;
}
return NULL ;
}
static void
F_24 ( struct V_2 * V_3 )
{
struct V_86 * V_88 = V_86 ( V_3 ) ;
F_25 ( & V_88 -> V_89 ) ;
F_10 ( V_88 -> V_90 ) ;
F_26 ( V_3 ) ;
F_27 ( V_3 ) ;
if ( V_88 -> V_91 . V_92 )
F_28 ( & V_88 -> V_91 ) ;
F_10 ( V_3 ) ;
}
static struct V_76 *
F_29 ( struct V_2 * V_3 )
{
struct V_10 * V_9 = V_3 -> V_9 ;
struct V_86 * V_88 = V_86 ( V_3 ) ;
struct V_7 * V_8 = V_7 ( V_9 ) ;
struct V_93 * V_94 = F_30 ( & V_8 -> V_95 ) ;
struct V_76 * V_77 ;
struct V_78 * V_87 ;
int V_80 , V_96 = - V_97 ;
if ( V_88 -> type == V_98 ) {
V_96 = F_31 ( V_94 , 0 , V_99 , 0xff ) ;
if ( V_96 == 0 ) {
F_32 ( V_94 , 0 , V_99 , 0xff , 1 ) ;
F_33 ( 300 ) ;
}
}
for ( V_80 = 0 ; V_77 = NULL , V_80 < V_82 ; V_80 ++ ) {
int V_81 = V_3 -> V_83 [ V_80 ] ;
if ( V_81 == 0 )
break;
V_87 = F_21 ( V_9 , V_81 ) ;
if ( ! V_87 )
continue;
V_77 = V_76 ( V_87 ) ;
if ( V_77 -> V_85 -> type == V_100 ) {
int V_101 = F_34 ( V_77 ) ;
if ( V_101 == V_102 )
return NULL ;
if ( V_101 == V_103 )
break;
} else
if ( ( F_35 () &
V_104 ) &&
V_77 -> V_85 -> type == V_105 &&
V_77 -> V_106 ) {
int V_101 ;
F_36 ( V_9 -> V_107 ) ;
V_101 = F_37 ( V_77 -> V_106 , 0x50 ) ;
F_38 ( V_9 -> V_107 ) ;
if ( V_101 )
break;
} else
if ( V_77 -> V_106 ) {
if ( F_37 ( V_77 -> V_106 , 0x50 ) )
break;
}
}
if ( ! V_77 && V_96 == 0 )
F_32 ( V_94 , 0 , V_99 , 0xff , V_96 ) ;
return V_77 ;
}
static struct V_76 *
F_39 ( struct V_2 * V_3 )
{
#ifdef F_40
struct V_10 * V_9 = V_3 -> V_9 ;
struct V_86 * V_88 = V_86 ( V_3 ) ;
struct V_76 * V_77 ;
struct V_108 * V_109 , * V_110 = F_41 ( V_9 -> V_107 ) ;
if ( ! V_110 ||
! ( ( V_77 = F_20 ( V_3 , V_111 ) ) ||
( V_77 = F_20 ( V_3 , V_112 ) ) ) )
return NULL ;
F_42 (dn, cn) {
const char * V_113 = F_43 ( V_109 , L_3 , NULL ) ;
const void * V_90 = F_43 ( V_109 , L_4 , NULL ) ;
int V_114 = V_113 ? V_113 [ strlen ( V_113 ) - 1 ] - 'A' : 0 ;
if ( V_77 -> V_85 -> V_115 == V_114 && V_90 ) {
V_88 -> V_90 =
F_44 ( V_90 , V_116 , V_63 ) ;
F_45 ( V_109 ) ;
return V_77 ;
}
}
#endif
return NULL ;
}
static void
F_46 ( struct V_2 * V_3 ,
struct V_76 * V_77 )
{
struct V_86 * V_88 = V_86 ( V_3 ) ;
struct V_7 * V_8 = V_7 ( V_3 -> V_9 ) ;
struct V_10 * V_9 = V_3 -> V_9 ;
if ( V_88 -> V_117 == V_77 )
return;
V_88 -> V_117 = V_77 ;
if ( V_8 -> V_95 . V_118 . V_119 >= V_120 ) {
V_3 -> V_121 = true ;
V_3 -> V_122 = true ;
} else
if ( V_77 -> V_85 -> type == V_105 ||
V_77 -> V_85 -> type == V_111 ) {
V_3 -> V_122 = false ;
V_3 -> V_121 = false ;
} else {
V_3 -> V_122 = true ;
if ( V_8 -> V_95 . V_118 . V_119 == V_123 ||
( V_8 -> V_95 . V_118 . V_119 == V_124 &&
( V_9 -> V_107 -> V_95 & 0x0ff0 ) != 0x0100 &&
( V_9 -> V_107 -> V_95 & 0x0ff0 ) != 0x0150 ) )
V_3 -> V_121 = false ;
else
V_3 -> V_121 = true ;
}
if ( V_88 -> type == V_125 ) {
F_47 ( & V_3 -> V_69 ,
V_9 -> V_33 . V_70 ,
V_77 -> V_85 -> type == V_111 ?
V_126 :
V_127 ) ;
}
}
static enum V_128
F_48 ( struct V_2 * V_3 , bool V_129 )
{
struct V_10 * V_9 = V_3 -> V_9 ;
struct V_7 * V_8 = V_7 ( V_9 ) ;
struct V_86 * V_88 = V_86 ( V_3 ) ;
struct V_76 * V_77 = NULL ;
struct V_76 * V_130 ;
struct V_131 * V_106 ;
int type ;
int V_101 ;
enum V_128 V_132 = V_133 ;
if ( V_88 -> V_90 ) {
F_49 ( V_3 , NULL ) ;
F_10 ( V_88 -> V_90 ) ;
V_88 -> V_90 = NULL ;
}
V_101 = F_50 ( V_3 -> V_9 -> V_9 ) ;
if ( V_101 < 0 && V_101 != - V_134 )
return V_132 ;
V_77 = F_29 ( V_3 ) ;
if ( V_77 && ( V_106 = V_77 -> V_106 ) != NULL ) {
if ( ( F_35 () &
V_104 ) &&
V_88 -> type == V_135 )
V_88 -> V_90 = F_51 ( V_3 ,
V_106 ) ;
else
V_88 -> V_90 = F_52 ( V_3 , V_106 ) ;
F_49 ( V_3 ,
V_88 -> V_90 ) ;
if ( ! V_88 -> V_90 ) {
F_53 ( V_8 , L_5 ,
V_3 -> V_113 ) ;
goto V_136;
}
V_130 = NULL ;
if ( V_77 -> V_85 -> type == V_111 )
V_130 = F_20 ( V_3 , V_112 ) ;
if ( V_77 -> V_85 -> type == V_112 )
V_130 = F_20 ( V_3 , V_111 ) ;
if ( V_130 && ( ( V_77 -> V_85 -> type == V_112 &&
V_130 -> V_85 -> type == V_111 ) ||
( V_77 -> V_85 -> type == V_111 &&
V_130 -> V_85 -> type == V_112 ) ) ) {
if ( V_88 -> V_90 -> V_137 & V_138 )
type = V_111 ;
else
type = V_112 ;
V_77 = F_20 ( V_3 , type ) ;
}
F_46 ( V_3 , V_77 ) ;
V_132 = V_139 ;
goto V_140;
}
V_77 = F_39 ( V_3 ) ;
if ( V_77 ) {
F_46 ( V_3 , V_77 ) ;
V_132 = V_139 ;
goto V_140;
}
V_136:
V_77 = F_20 ( V_3 , V_112 ) ;
if ( ! V_77 && ! V_141 )
V_77 = F_20 ( V_3 , V_142 ) ;
if ( V_77 && V_129 ) {
struct V_78 * V_87 = F_23 ( V_77 ) ;
const struct V_143 * V_5 =
V_87 -> V_6 ;
if ( V_5 -> V_144 ( V_87 , V_3 ) ==
V_139 ) {
F_46 ( V_3 , V_77 ) ;
V_132 = V_139 ;
goto V_140;
}
}
V_140:
F_54 ( V_3 -> V_9 -> V_9 ) ;
F_55 ( V_3 -> V_9 -> V_9 ) ;
return V_132 ;
}
static enum V_128
F_56 ( struct V_2 * V_3 , bool V_129 )
{
struct V_10 * V_9 = V_3 -> V_9 ;
struct V_7 * V_8 = V_7 ( V_9 ) ;
struct V_86 * V_88 = V_86 ( V_3 ) ;
struct V_76 * V_77 = NULL ;
enum V_128 V_145 = V_133 ;
if ( V_88 -> V_90 ) {
F_49 ( V_3 , NULL ) ;
F_10 ( V_88 -> V_90 ) ;
V_88 -> V_90 = NULL ;
}
V_77 = F_20 ( V_3 , V_105 ) ;
if ( ! V_77 )
return V_133 ;
if ( ! V_8 -> V_146 . V_147 ) {
V_145 = F_48 ( V_3 , V_129 ) ;
if ( V_145 == V_139 )
goto V_140;
}
if ( V_77 -> V_85 -> V_148 . V_149 ) {
if ( ( V_88 -> V_90 = F_57 ( V_9 , V_3 ) ) ) {
V_145 = V_139 ;
goto V_140;
}
}
if ( F_58 ( V_9 , NULL ) && ( V_8 -> V_146 . V_147 ||
V_77 -> V_85 -> V_148 . V_150 ) ) {
V_145 = V_139 ;
goto V_140;
}
if ( ! V_8 -> V_146 . V_147 ) {
struct V_90 * V_90 =
(struct V_90 * ) F_59 ( V_9 ) ;
if ( V_90 ) {
V_88 -> V_90 =
F_44 ( V_90 , V_116 , V_63 ) ;
if ( V_88 -> V_90 )
V_145 = V_139 ;
}
}
V_140:
#if F_60 ( V_151 ) || \
( F_60 ( V_152 ) && F_60 ( V_153 ) )
if ( V_145 == V_139 &&
! V_154 && ! F_61 () )
V_145 = V_155 ;
#endif
F_49 ( V_3 , V_88 -> V_90 ) ;
F_46 ( V_3 , V_77 ) ;
return V_145 ;
}
static void
F_62 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_7 ( V_3 -> V_9 ) ;
struct V_86 * V_88 = V_86 ( V_3 ) ;
struct V_76 * V_77 ;
int type ;
if ( V_88 -> type == V_125 ) {
if ( V_3 -> V_129 == V_156 )
type = V_111 ;
else
type = V_112 ;
} else
type = V_84 ;
V_77 = F_20 ( V_3 , type ) ;
if ( ! V_77 ) {
F_53 ( V_8 , L_6 ,
V_3 -> V_113 ) ;
V_3 -> V_145 = V_133 ;
return;
}
F_46 ( V_3 , V_77 ) ;
}
static int
F_63 ( struct V_2 * V_3 ,
struct V_26 * V_27 , T_2 V_157 )
{
struct V_29 * V_30 = V_29 ( V_3 -> V_25 ) ;
struct V_86 * V_88 = V_86 ( V_3 ) ;
struct V_76 * V_77 = V_88 -> V_117 ;
struct V_78 * V_87 = F_23 ( V_77 ) ;
int V_101 ;
if ( V_3 -> V_9 -> V_33 . V_158 -> V_159 )
return F_64 ( V_3 , V_27 , V_157 ) ;
V_101 = V_3 -> V_158 -> V_160 ( & V_88 -> V_69 ,
& V_30 -> V_25 ,
V_27 , V_157 ) ;
if ( V_101 ) {
if ( V_77 && V_77 -> V_85 -> type == V_142 )
return F_65 ( V_87 ) -> F_66 (
V_87 , V_3 , V_27 , V_157 ) ;
return V_101 ;
}
V_88 -> V_161 = V_30 -> V_35 . V_11 ;
V_88 -> V_42 = V_30 -> V_43 . V_11 ;
if ( V_3 -> V_87 && V_3 -> V_87 -> V_162 ) {
V_101 = F_67 ( V_3 -> V_87 -> V_162 ,
& V_3 -> V_87 -> V_162 -> V_11 ,
V_3 -> V_87 -> V_162 -> V_163 ,
V_3 -> V_87 -> V_162 -> V_164 ,
NULL ) ;
if ( ! V_101 )
return - V_51 ;
}
return 0 ;
}
static int
F_68 ( struct V_2 * V_3 )
{
struct V_86 * V_88 = V_86 ( V_3 ) ;
struct V_1 * V_165 = V_88 -> V_166 , * V_167 ;
struct V_10 * V_9 = V_3 -> V_9 ;
struct V_168 * V_11 = & V_169 [ 0 ] ;
int V_170 = 0 ;
if ( ! V_165 )
return 0 ;
while ( V_11 -> V_22 ) {
if ( V_11 -> V_22 <= V_165 -> V_22 &&
V_11 -> V_23 <= V_165 -> V_23 &&
( V_11 -> V_22 != V_165 -> V_22 ||
V_11 -> V_23 != V_165 -> V_23 ) ) {
V_167 = F_69 ( V_9 , V_11 -> V_22 , V_11 -> V_23 ,
F_3 ( V_165 ) , false ,
false , false ) ;
if ( ! V_167 )
continue;
F_70 ( V_3 , V_167 ) ;
V_170 ++ ;
}
V_11 ++ ;
}
return V_170 ;
}
static void
F_71 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_7 ( V_3 -> V_9 ) ;
struct V_86 * V_88 = V_86 ( V_3 ) ;
struct V_76 * V_77 = V_88 -> V_117 ;
struct V_171 * V_172 = & V_8 -> V_146 ;
struct V_1 * V_11 = V_88 -> V_166 ;
bool V_173 ;
if ( V_88 -> V_90 && V_3 -> V_174 . V_175 )
return;
if ( V_88 -> type == V_98 ) {
V_3 -> V_174 . V_175 = 6 ;
return;
}
if ( V_77 -> V_85 -> type != V_105 ) {
V_3 -> V_174 . V_175 = 8 ;
return;
}
V_3 -> V_174 . V_175 = 6 ;
if ( V_172 -> V_147 ) {
if ( V_172 -> V_176 . V_177 )
V_3 -> V_174 . V_175 = 8 ;
return;
}
if ( V_88 -> V_90 &&
V_88 -> type == V_178 )
V_173 = ( ( V_179 * ) V_88 -> V_90 ) [ 121 ] == 2 ;
else
V_173 = V_11 -> clock >= V_172 -> V_176 . V_180 ;
if ( ( ! V_173 && ( V_172 -> V_176 . V_181 & 1 ) ) ||
( V_173 && ( V_172 -> V_176 . V_181 & 2 ) ) )
V_3 -> V_174 . V_175 = 8 ;
}
static int
F_72 ( struct V_2 * V_3 )
{
struct V_10 * V_9 = V_3 -> V_9 ;
struct V_7 * V_8 = V_7 ( V_9 ) ;
struct V_86 * V_88 = V_86 ( V_3 ) ;
struct V_76 * V_77 = V_88 -> V_117 ;
struct V_78 * V_87 = F_23 ( V_77 ) ;
int V_101 = 0 ;
if ( V_88 -> V_166 ) {
F_73 ( V_9 , V_88 -> V_166 ) ;
V_88 -> V_166 = NULL ;
}
if ( V_88 -> V_90 )
V_101 = F_74 ( V_3 , V_88 -> V_90 ) ;
else
if ( V_77 -> V_85 -> type == V_105 &&
( V_77 -> V_85 -> V_148 . V_150 ||
V_8 -> V_146 . V_147 ) && F_58 ( V_9 , NULL ) ) {
struct V_1 V_11 ;
F_58 ( V_9 , & V_11 ) ;
V_88 -> V_166 = F_5 ( V_9 , & V_11 ) ;
}
if ( V_3 -> V_53 != V_54 )
F_71 ( V_3 ) ;
if ( ! V_88 -> V_166 )
V_88 -> V_166 = F_1 ( V_3 ) ;
if ( V_101 == 0 && V_88 -> V_166 ) {
struct V_1 * V_11 ;
V_11 = F_5 ( V_9 , V_88 -> V_166 ) ;
F_70 ( V_3 , V_11 ) ;
V_101 = 1 ;
}
if ( V_3 -> V_53 == V_54 )
F_71 ( V_3 ) ;
if ( V_77 -> V_85 -> type == V_142 )
V_101 = F_65 ( V_87 ) -> F_75 ( V_87 , V_3 ) ;
if ( V_88 -> type == V_135 ||
V_88 -> type == V_178 ||
V_88 -> type == V_98 )
V_101 += F_68 ( V_3 ) ;
return V_101 ;
}
static unsigned
F_76 ( struct V_2 * V_3 , bool V_182 )
{
struct V_86 * V_88 = V_86 ( V_3 ) ;
struct V_7 * V_8 = V_7 ( V_3 -> V_9 ) ;
struct V_183 * V_85 = V_88 -> V_117 -> V_85 ;
if ( V_182 ) {
if ( V_184 > 0 )
return V_184 * 1000 ;
if ( V_8 -> V_95 . V_118 . V_119 >= V_185 )
return 297000 ;
if ( V_8 -> V_95 . V_118 . V_119 >= V_186 )
return 225000 ;
}
if ( V_85 -> V_187 != V_188 ||
V_8 -> V_95 . V_118 . V_189 >= 0x46 )
return 165000 ;
else if ( V_8 -> V_95 . V_118 . V_189 >= 0x40 )
return 155000 ;
else if ( V_8 -> V_95 . V_118 . V_189 >= 0x18 )
return 135000 ;
else
return 112000 ;
}
static int
F_77 ( struct V_2 * V_3 ,
struct V_1 * V_11 )
{
struct V_86 * V_88 = V_86 ( V_3 ) ;
struct V_76 * V_77 = V_88 -> V_117 ;
struct V_78 * V_87 = F_23 ( V_77 ) ;
unsigned V_190 = 25000 , V_191 = V_190 ;
unsigned clock = V_11 -> clock ;
bool V_182 ;
switch ( V_77 -> V_85 -> type ) {
case V_105 :
if ( V_88 -> V_166 &&
( V_11 -> V_22 > V_88 -> V_166 -> V_22 ||
V_11 -> V_23 > V_88 -> V_166 -> V_23 ) )
return V_192 ;
V_190 = 0 ;
V_191 = 400000 ;
break;
case V_111 :
V_182 = F_78 ( V_88 -> V_90 ) ;
V_191 = F_76 ( V_3 , V_182 ) ;
if ( ! V_182 && V_193 &&
V_77 -> V_85 -> V_194 )
V_191 *= 2 ;
break;
case V_112 :
V_191 = V_77 -> V_85 -> V_195 . V_196 ;
if ( ! V_191 )
V_191 = 350000 ;
break;
case V_142 :
return F_65 ( V_87 ) -> V_17 ( V_87 , V_11 ) ;
case V_100 :
V_191 = V_77 -> V_197 . V_198 ;
V_191 *= V_77 -> V_197 . V_199 ;
clock = clock * ( V_3 -> V_174 . V_175 * 3 ) / 10 ;
break;
default:
F_79 ( 1 ) ;
return V_200 ;
}
if ( clock < V_190 )
return V_201 ;
if ( clock > V_191 )
return V_202 ;
return V_18 ;
}
static struct V_78 *
F_80 ( struct V_2 * V_3 )
{
struct V_86 * V_88 = V_86 ( V_3 ) ;
if ( V_88 -> V_117 )
return F_23 ( V_88 -> V_117 ) ;
return NULL ;
}
static int
F_81 ( struct V_2 * V_3 , int V_11 )
{
if ( V_3 -> V_9 -> V_33 . V_158 -> V_159 )
return F_82 ( V_3 , V_11 ) ;
return F_83 ( V_3 , V_11 ) ;
}
static int
F_84 ( struct V_203 * V_204 )
{
struct V_86 * V_88 =
F_85 ( V_204 , F_86 ( * V_88 ) , V_89 ) ;
struct V_2 * V_3 = & V_88 -> V_69 ;
struct V_7 * V_8 = V_7 ( V_3 -> V_9 ) ;
const struct V_205 * V_206 = V_204 -> V_207 ;
const char * V_113 = V_3 -> V_113 ;
struct V_76 * V_77 ;
if ( V_206 -> V_64 & V_208 ) {
F_4 ( V_8 , L_7 , V_113 ) ;
if ( ( V_77 = F_20 ( V_3 , V_100 ) ) )
F_87 ( V_77 -> V_197 . V_209 ) ;
} else {
bool V_210 = ( V_206 -> V_64 != V_211 ) ;
F_4 ( V_8 , L_8 , V_210 ? L_9 : L_10 , V_113 ) ;
if ( ( V_77 = F_20 ( V_3 , V_100 ) ) ) {
if ( ! V_210 )
F_88 ( V_77 -> V_197 . V_209 ) ;
}
F_89 ( V_3 -> V_9 ) ;
}
return V_212 ;
}
static T_3
F_90 ( struct V_213 * V_214 , struct V_215 * V_216 )
{
struct V_86 * V_88 =
F_85 ( V_214 , F_86 ( * V_88 ) , V_91 ) ;
struct V_76 * V_77 ;
struct V_217 * V_91 ;
int V_101 ;
V_77 = F_20 ( & V_88 -> V_69 , V_100 ) ;
if ( ! V_77 || ! ( V_91 = V_77 -> V_91 ) )
return - V_97 ;
if ( F_15 ( V_216 -> V_218 > 16 ) )
return - V_219 ;
if ( V_216 -> V_218 == 0 )
return V_216 -> V_218 ;
V_101 = F_91 ( V_91 ) ;
if ( V_101 )
return V_101 ;
V_101 = F_92 ( V_91 , false , V_216 -> V_220 , V_216 -> V_221 ,
V_216 -> V_222 , V_216 -> V_218 ) ;
F_93 ( V_91 ) ;
if ( V_101 >= 0 ) {
V_216 -> V_223 = V_101 ;
return V_216 -> V_218 ;
}
return V_101 ;
}
static int
F_94 ( enum V_224 V_85 )
{
switch ( V_85 ) {
case V_225 : return V_75 ;
case V_226 :
case V_227 :
case V_228 : return V_74 ;
case V_229 :
case V_230 :
case V_125 : return V_68 ;
case V_231 : return V_71 ;
case V_135 :
case V_178 : return V_54 ;
case V_232 :
case V_233 :
case V_234 : return V_73 ;
case V_98 : return V_55 ;
case V_235 :
case V_236 :
case V_237 : return V_72 ;
default:
break;
}
return V_238 ;
}
struct V_2 *
F_95 ( struct V_10 * V_9 , int V_239 )
{
const struct V_240 * V_158 = & V_241 ;
struct V_7 * V_8 = V_7 ( V_9 ) ;
struct V_31 * V_32 = V_31 ( V_9 ) ;
struct V_86 * V_88 = NULL ;
struct V_2 * V_3 ;
int type , V_101 = 0 ;
bool V_242 ;
F_2 (connector, &dev->mode_config.connector_list, head) {
V_88 = V_86 ( V_3 ) ;
if ( V_88 -> V_239 == V_239 )
return V_3 ;
}
V_88 = F_16 ( sizeof( * V_88 ) , V_63 ) ;
if ( ! V_88 )
return F_96 ( - V_243 ) ;
V_3 = & V_88 -> V_69 ;
V_88 -> V_239 = V_239 ;
V_88 -> V_85 = F_97 ( V_9 , V_239 ) ;
if ( V_88 -> V_85 ) {
T_4 V_244 = F_98 ( V_88 -> V_85 [ 0 ] ) ;
if ( F_99 ( V_9 ) [ 3 ] >= 4 )
V_244 |= ( T_4 ) F_98 ( V_88 -> V_85 [ 2 ] ) << 16 ;
V_88 -> type = V_88 -> V_85 [ 0 ] ;
if ( F_94 ( V_88 -> type ) ==
V_238 ) {
F_100 ( V_8 , L_11 ,
V_88 -> type ) ;
V_88 -> type = V_245 ;
}
if ( F_101 ( V_9 , 0x0421 , 0x1458 , 0x344c ) ) {
if ( V_88 -> type == V_236 )
V_88 -> type = V_125 ;
}
if ( F_101 ( V_9 , 0x0402 , 0x1458 , 0x3455 ) ) {
if ( V_88 -> type == V_236 )
V_88 -> type = V_125 ;
}
} else {
V_88 -> type = V_245 ;
}
if ( V_88 -> type == V_245 ) {
struct V_7 * V_8 = V_7 ( V_9 ) ;
struct V_246 * V_247 = & V_8 -> V_146 . V_85 ;
T_4 V_248 = 0 ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_247 -> V_249 ; V_80 ++ ) {
if ( V_247 -> V_244 [ V_80 ] . V_3 == V_88 -> V_239 )
V_248 |= ( 1 << V_247 -> V_244 [ V_80 ] . type ) ;
}
if ( V_248 & ( 1 << V_100 ) ) {
if ( V_248 & ( 1 << V_111 ) )
V_88 -> type = V_234 ;
else
V_88 -> type = V_98 ;
} else
if ( V_248 & ( 1 << V_111 ) ) {
if ( V_248 & ( 1 << V_112 ) )
V_88 -> type = V_125 ;
else
V_88 -> type = V_231 ;
} else
if ( V_248 & ( 1 << V_112 ) ) {
V_88 -> type = V_225 ;
} else
if ( V_248 & ( 1 << V_105 ) ) {
V_88 -> type = V_135 ;
} else
if ( V_248 & ( 1 << V_142 ) ) {
V_88 -> type = V_226 ;
}
}
switch ( ( type = F_94 ( V_88 -> type ) ) ) {
case V_54 :
V_101 = F_102 ( V_9 , 0 , & V_242 , & V_242 ) ;
if ( V_101 ) {
F_53 ( V_8 , L_12 ) ;
F_10 ( V_88 ) ;
return F_96 ( V_101 ) ;
}
V_158 = & V_250 ;
break;
case V_73 :
case V_55 :
V_88 -> V_91 . V_9 = V_9 -> V_9 ;
V_88 -> V_91 . V_92 = F_90 ;
V_101 = F_103 ( & V_88 -> V_91 ) ;
if ( V_101 ) {
F_53 ( V_8 , L_13 ) ;
F_10 ( V_88 ) ;
return F_96 ( V_101 ) ;
}
V_158 = & V_241 ;
break;
default:
V_158 = & V_241 ;
break;
}
V_3 -> V_121 = false ;
V_3 -> V_122 = false ;
F_104 ( V_9 , V_3 , V_158 , type ) ;
F_105 ( V_3 , & V_251 ) ;
V_3 -> V_158 -> V_252 ( V_3 ) ;
F_18 ( V_3 ) ;
switch ( V_88 -> type ) {
case V_135 :
case V_178 :
case V_98 :
if ( V_32 -> V_32 . V_56 < V_57 ) {
V_88 -> V_161 = V_58 ;
break;
}
V_88 -> V_161 = V_52 ;
break;
default:
V_88 -> V_161 = V_52 ;
break;
}
switch ( V_88 -> type ) {
case V_226 :
case V_227 :
case V_228 :
case V_225 :
break;
default:
V_88 -> V_42 = V_65 ;
break;
}
V_101 = F_106 (&disp->disp, nouveau_connector_hotplug, true,
NV04_DISP_NTFY_CONN,
&(struct nvif_notify_conn_req_v0) {
.mask = NVIF_NOTIFY_CONN_V0_ANY,
.conn = index,
},
sizeof(struct nvif_notify_conn_req_v0),
sizeof(struct nvif_notify_conn_rep_v0),
&nv_connector->hpd) ;
if ( V_101 )
V_3 -> V_253 = V_254 ;
else
V_3 -> V_253 = V_255 ;
F_107 ( V_3 ) ;
return V_3 ;
}

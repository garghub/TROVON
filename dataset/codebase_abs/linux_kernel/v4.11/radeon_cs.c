static void F_1 ( struct V_1 * V_2 )
{
unsigned V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
F_2 ( & V_2 -> V_5 [ V_3 ] ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_6 * V_7 , unsigned V_8 )
{
F_4 ( V_7 , & V_2 -> V_5 [ F_5 ( V_8 , V_9 ) ] ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_6 * V_10 )
{
unsigned V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_7 ( & V_2 -> V_5 [ V_3 ] , V_10 ) ;
}
}
static int F_8 ( struct V_11 * V_12 )
{
struct V_13 * V_14 ;
struct V_1 V_15 ;
unsigned V_3 ;
bool V_16 = false ;
int V_17 ;
if ( V_12 -> V_18 == NULL ) {
return 0 ;
}
V_14 = V_12 -> V_18 ;
V_12 -> V_19 = 0 ;
V_12 -> V_20 = V_14 -> V_21 / 4 ;
V_12 -> V_22 = F_9 ( V_12 -> V_20 , sizeof( struct V_23 ) ) ;
if ( V_12 -> V_22 == NULL ) {
return - V_24 ;
}
F_1 ( & V_15 ) ;
for ( V_3 = 0 ; V_3 < V_12 -> V_20 ; V_3 ++ ) {
struct V_25 * V_17 ;
struct V_26 * V_27 ;
unsigned V_8 ;
V_17 = (struct V_25 * ) & V_14 -> V_28 [ V_3 * 4 ] ;
V_27 = F_10 ( V_12 -> V_29 , V_17 -> V_30 ) ;
if ( V_27 == NULL ) {
F_11 ( L_1 ,
V_17 -> V_30 ) ;
return - V_31 ;
}
V_12 -> V_22 [ V_3 ] . V_32 = F_12 ( V_27 ) ;
V_8 = ( V_17 -> V_33 & V_34 ) * 2
+ ! ! V_17 -> V_35 ;
if ( V_12 -> V_36 == V_37 &&
( V_3 == 0 || F_13 ( V_12 -> V_38 -> V_39 -> V_40 ,
V_41 ) ||
V_12 -> V_38 -> V_42 == V_43 ||
V_12 -> V_38 -> V_42 == V_44 ) ) {
V_12 -> V_22 [ V_3 ] . V_45 =
V_46 ;
V_12 -> V_22 [ V_3 ] . V_47 =
V_46 ;
V_8 = V_9 ;
} else {
T_1 V_48 = V_17 -> V_35 ?
V_17 -> V_35 : V_17 -> V_49 ;
if ( V_48 & V_50 ) {
F_11 ( L_2
L_3 ) ;
return - V_51 ;
}
V_12 -> V_22 [ V_3 ] . V_45 = V_48 ;
if ( V_48 == V_46 )
V_48 |= V_52 ;
V_12 -> V_22 [ V_3 ] . V_47 = V_48 ;
}
if ( F_14 ( V_12 -> V_22 [ V_3 ] . V_32 -> V_53 . V_54 ) ) {
T_1 V_48 = V_12 -> V_22 [ V_3 ] . V_45 ;
if ( ! ( V_48 & V_52 ) ) {
F_11 ( L_4
L_5 ) ;
return - V_51 ;
}
V_16 = true ;
V_48 = V_52 ;
V_12 -> V_22 [ V_3 ] . V_45 = V_48 ;
V_12 -> V_22 [ V_3 ] . V_47 = V_48 ;
}
V_12 -> V_22 [ V_3 ] . V_55 . V_56 = & V_12 -> V_22 [ V_3 ] . V_32 -> V_53 ;
V_12 -> V_22 [ V_3 ] . V_55 . V_57 = ! V_17 -> V_35 ;
F_3 ( & V_15 , & V_12 -> V_22 [ V_3 ] . V_55 . V_58 ,
V_8 ) ;
}
F_6 ( & V_15 , & V_12 -> V_59 ) ;
if ( V_12 -> V_60 & V_61 )
V_12 -> V_62 = F_15 ( V_12 -> V_38 , V_12 -> V_63 . V_64 ,
& V_12 -> V_59 ) ;
if ( V_16 )
F_16 ( & V_65 -> V_66 -> V_67 ) ;
V_17 = F_17 ( V_12 -> V_38 , & V_12 -> V_68 , & V_12 -> V_59 , V_12 -> V_36 ) ;
if ( V_16 )
F_18 ( & V_65 -> V_66 -> V_67 ) ;
return V_17 ;
}
static int F_19 ( struct V_11 * V_12 , T_2 V_36 , T_3 V_8 )
{
V_12 -> V_8 = V_8 ;
switch ( V_36 ) {
default:
F_11 ( L_6 , V_36 ) ;
return - V_51 ;
case V_69 :
V_12 -> V_36 = V_70 ;
break;
case V_71 :
if ( V_12 -> V_38 -> V_42 >= V_72 ) {
if ( V_12 -> V_8 > 0 )
V_12 -> V_36 = V_73 ;
else
V_12 -> V_36 = V_74 ;
} else
V_12 -> V_36 = V_70 ;
break;
case V_75 :
if ( V_12 -> V_38 -> V_42 >= V_76 ) {
if ( V_12 -> V_8 > 0 )
V_12 -> V_36 = V_77 ;
else
V_12 -> V_36 = V_78 ;
} else if ( V_12 -> V_38 -> V_42 >= V_79 ) {
V_12 -> V_36 = V_77 ;
} else {
return - V_51 ;
}
break;
case V_80 :
V_12 -> V_36 = V_37 ;
break;
case V_81 :
V_12 -> V_36 = V_82 ;
break;
}
return 0 ;
}
static int F_20 ( struct V_11 * V_12 )
{
struct V_23 * V_83 ;
int V_17 ;
F_21 (reloc, &p->validated, tv.head) {
struct V_84 * V_85 ;
V_85 = V_83 -> V_32 -> V_53 . V_85 ;
V_17 = F_22 ( V_12 -> V_38 , & V_12 -> V_63 . V_86 , V_85 ,
V_83 -> V_55 . V_57 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
int F_23 ( struct V_11 * V_12 , void * V_87 )
{
struct V_88 * V_89 = V_87 ;
T_4 * V_90 ;
unsigned V_91 , V_3 ;
T_2 V_36 = V_69 ;
T_3 V_8 = 0 ;
F_2 ( & V_12 -> V_59 ) ;
if ( ! V_89 -> V_92 ) {
return 0 ;
}
V_12 -> V_93 = 0 ;
V_12 -> V_63 . V_94 = NULL ;
V_12 -> V_95 . V_94 = NULL ;
V_12 -> V_96 = NULL ;
V_12 -> V_18 = NULL ;
V_12 -> V_97 = NULL ;
V_12 -> V_98 = NULL ;
V_12 -> V_99 = F_24 ( V_89 -> V_92 , sizeof( T_4 ) , V_100 ) ;
if ( V_12 -> V_99 == NULL ) {
return - V_24 ;
}
V_90 = ( T_4 * ) ( unsigned long ) ( V_89 -> V_101 ) ;
if ( F_25 ( V_12 -> V_99 , V_90 ,
sizeof( T_4 ) * V_89 -> V_92 ) ) {
return - V_102 ;
}
V_12 -> V_60 = 0 ;
V_12 -> V_103 = V_89 -> V_92 ;
V_12 -> V_101 = F_24 ( V_12 -> V_103 , sizeof( struct V_13 ) , V_100 ) ;
if ( V_12 -> V_101 == NULL ) {
return - V_24 ;
}
for ( V_3 = 0 ; V_3 < V_12 -> V_103 ; V_3 ++ ) {
struct V_104 T_5 * * V_105 = NULL ;
struct V_104 V_106 ;
T_1 T_5 * V_107 ;
V_105 = ( void T_5 * ) ( unsigned long ) V_12 -> V_99 [ V_3 ] ;
if ( F_25 ( & V_106 , V_105 ,
sizeof( struct V_104 ) ) ) {
return - V_102 ;
}
V_12 -> V_101 [ V_3 ] . V_21 = V_106 . V_21 ;
if ( V_106 . V_108 == V_109 ) {
V_12 -> V_18 = & V_12 -> V_101 [ V_3 ] ;
}
if ( V_106 . V_108 == V_110 ) {
V_12 -> V_96 = & V_12 -> V_101 [ V_3 ] ;
if ( V_12 -> V_101 [ V_3 ] . V_21 == 0 )
return - V_51 ;
}
if ( V_106 . V_108 == V_111 ) {
V_12 -> V_98 = & V_12 -> V_101 [ V_3 ] ;
if ( V_12 -> V_101 [ V_3 ] . V_21 == 0 )
return - V_51 ;
}
if ( V_106 . V_108 == V_112 ) {
V_12 -> V_97 = & V_12 -> V_101 [ V_3 ] ;
if ( V_12 -> V_101 [ V_3 ] . V_21 == 0 )
return - V_51 ;
}
V_91 = V_12 -> V_101 [ V_3 ] . V_21 ;
V_107 = ( void T_5 * ) ( unsigned long ) V_106 . V_113 ;
V_12 -> V_101 [ V_3 ] . V_114 = V_107 ;
if ( V_106 . V_108 == V_111 )
continue;
if ( V_106 . V_108 == V_110 ) {
if ( ! V_12 -> V_38 || ! ( V_12 -> V_38 -> V_33 & V_115 ) )
continue;
}
V_12 -> V_101 [ V_3 ] . V_28 = F_26 ( V_91 , sizeof( T_1 ) ) ;
V_91 *= sizeof( T_1 ) ;
if ( V_12 -> V_101 [ V_3 ] . V_28 == NULL ) {
return - V_24 ;
}
if ( F_25 ( V_12 -> V_101 [ V_3 ] . V_28 , V_107 , V_91 ) ) {
return - V_102 ;
}
if ( V_106 . V_108 == V_112 ) {
V_12 -> V_60 = V_12 -> V_101 [ V_3 ] . V_28 [ 0 ] ;
if ( V_12 -> V_101 [ V_3 ] . V_21 > 1 )
V_36 = V_12 -> V_101 [ V_3 ] . V_28 [ 1 ] ;
if ( V_12 -> V_101 [ V_3 ] . V_21 > 2 )
V_8 = ( T_3 ) V_12 -> V_101 [ V_3 ] . V_28 [ 2 ] ;
}
}
if ( V_12 -> V_38 ) {
if ( ( V_12 -> V_60 & V_61 ) &&
! V_12 -> V_38 -> V_116 . V_117 ) {
F_11 ( L_7 ) ;
return - V_51 ;
}
if ( F_19 ( V_12 , V_36 , V_8 ) )
return - V_51 ;
if ( ( V_12 -> V_60 & V_61 ) == 0 ) {
if ( V_12 -> V_38 -> V_118 -> V_36 [ V_12 -> V_36 ] -> V_119 == NULL ) {
F_11 ( L_8 , V_12 -> V_36 ) ;
return - V_51 ;
}
} else {
if ( V_12 -> V_38 -> V_118 -> V_36 [ V_12 -> V_36 ] -> V_120 == NULL ) {
F_11 ( L_9 ,
V_12 -> V_36 ) ;
return - V_51 ;
}
}
}
return 0 ;
}
static int F_27 ( void * V_121 , struct V_6 * V_122 ,
struct V_6 * V_2 )
{
struct V_23 * V_123 = F_28 ( V_122 , struct V_23 , V_55 . V_58 ) ;
struct V_23 * V_124 = F_28 ( V_2 , struct V_23 , V_55 . V_58 ) ;
return ( int ) V_123 -> V_32 -> V_53 . V_125 - ( int ) V_124 -> V_32 -> V_53 . V_125 ;
}
static void F_29 ( struct V_11 * V_126 , int error , bool V_127 )
{
unsigned V_3 ;
if ( ! error ) {
F_30 ( NULL , & V_126 -> V_59 , F_27 ) ;
F_31 ( & V_126 -> V_68 ,
& V_126 -> V_59 ,
& V_126 -> V_63 . V_128 -> V_129 ) ;
} else if ( V_127 ) {
F_32 ( & V_126 -> V_68 ,
& V_126 -> V_59 ) ;
}
if ( V_126 -> V_22 != NULL ) {
for ( V_3 = 0 ; V_3 < V_126 -> V_20 ; V_3 ++ ) {
struct V_130 * V_56 = V_126 -> V_22 [ V_3 ] . V_32 ;
if ( V_56 == NULL )
continue;
F_33 ( & V_56 -> V_131 ) ;
}
}
F_34 ( V_126 -> V_132 ) ;
F_35 ( V_126 -> V_22 ) ;
F_35 ( V_126 -> V_62 ) ;
for ( V_3 = 0 ; V_3 < V_126 -> V_103 ; V_3 ++ )
F_35 ( V_126 -> V_101 [ V_3 ] . V_28 ) ;
F_34 ( V_126 -> V_101 ) ;
F_34 ( V_126 -> V_99 ) ;
F_36 ( V_126 -> V_38 , & V_126 -> V_63 ) ;
F_36 ( V_126 -> V_38 , & V_126 -> V_95 ) ;
}
static int F_37 ( struct V_133 * V_38 ,
struct V_11 * V_126 )
{
int V_17 ;
if ( V_126 -> V_96 == NULL )
return 0 ;
if ( V_126 -> V_60 & V_61 )
return 0 ;
V_17 = F_38 ( V_38 , V_126 -> V_36 , V_126 ) ;
if ( V_17 || V_126 -> V_134 ) {
F_11 ( L_10 ) ;
return V_17 ;
}
V_17 = F_20 ( V_126 ) ;
if ( V_17 ) {
if ( V_17 != - V_135 )
F_11 ( L_11 , V_17 ) ;
return V_17 ;
}
if ( V_126 -> V_36 == V_37 )
F_39 ( V_38 ) ;
else if ( ( V_126 -> V_36 == V_82 ) ||
( V_126 -> V_36 == V_136 ) )
F_40 ( V_38 ) ;
V_17 = F_41 ( V_38 , & V_126 -> V_63 , NULL , true ) ;
if ( V_17 ) {
F_11 ( L_12 ) ;
}
return V_17 ;
}
static int F_42 ( struct V_11 * V_12 ,
struct V_137 * V_64 )
{
struct V_133 * V_38 = V_12 -> V_38 ;
struct V_138 * V_139 ;
int V_3 , V_17 ;
V_17 = F_43 ( V_38 , V_64 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_44 ( V_38 , V_64 ) ;
if ( V_17 )
return V_17 ;
if ( V_64 -> V_140 == NULL ) {
F_11 ( L_13 ) ;
return - V_51 ;
}
V_17 = F_45 ( V_38 , V_64 -> V_140 ,
& V_38 -> V_141 . V_56 -> V_53 . V_142 ) ;
if ( V_17 )
return V_17 ;
for ( V_3 = 0 ; V_3 < V_12 -> V_20 ; V_3 ++ ) {
struct V_130 * V_56 ;
V_56 = V_12 -> V_22 [ V_3 ] . V_32 ;
V_139 = F_46 ( V_64 , V_56 ) ;
if ( V_139 == NULL ) {
F_47 ( V_38 -> V_143 , L_14 , V_56 , V_64 ) ;
return - V_51 ;
}
V_17 = F_45 ( V_38 , V_139 , & V_56 -> V_53 . V_142 ) ;
if ( V_17 )
return V_17 ;
F_48 ( & V_12 -> V_63 . V_86 , V_139 -> V_144 ) ;
}
return F_49 ( V_38 , V_64 ) ;
}
static int F_50 ( struct V_133 * V_38 ,
struct V_11 * V_126 )
{
struct V_145 * V_146 = V_126 -> V_29 -> V_147 ;
struct V_137 * V_64 = & V_146 -> V_64 ;
int V_17 ;
if ( V_126 -> V_96 == NULL )
return 0 ;
if ( ( V_126 -> V_60 & V_61 ) == 0 )
return 0 ;
if ( V_126 -> V_95 . V_21 ) {
V_17 = F_51 ( V_38 , V_126 -> V_36 , & V_126 -> V_95 ) ;
if ( V_17 ) {
return V_17 ;
}
}
V_17 = F_51 ( V_38 , V_126 -> V_36 , & V_126 -> V_63 ) ;
if ( V_17 ) {
return V_17 ;
}
if ( V_126 -> V_36 == V_37 )
F_39 ( V_38 ) ;
F_52 ( & V_64 -> V_148 ) ;
V_17 = F_42 ( V_126 , V_64 ) ;
if ( V_17 ) {
goto V_149;
}
V_17 = F_20 ( V_126 ) ;
if ( V_17 ) {
if ( V_17 != - V_135 )
F_11 ( L_11 , V_17 ) ;
goto V_149;
}
if ( ( V_38 -> V_42 >= V_72 ) &&
( V_126 -> V_98 != NULL ) ) {
V_17 = F_41 ( V_38 , & V_126 -> V_63 , & V_126 -> V_95 , true ) ;
} else {
V_17 = F_41 ( V_38 , & V_126 -> V_63 , NULL , true ) ;
}
V_149:
F_53 ( & V_64 -> V_148 ) ;
return V_17 ;
}
static int F_54 ( struct V_133 * V_38 , int V_17 )
{
if ( V_17 == - V_150 ) {
V_17 = F_55 ( V_38 ) ;
if ( ! V_17 )
V_17 = - V_151 ;
}
return V_17 ;
}
static int F_56 ( struct V_133 * V_38 , struct V_11 * V_126 )
{
struct V_13 * V_152 ;
struct V_137 * V_64 = NULL ;
int V_17 ;
if ( V_126 -> V_96 == NULL )
return 0 ;
if ( V_126 -> V_60 & V_61 ) {
struct V_145 * V_146 = V_126 -> V_29 -> V_147 ;
V_64 = & V_146 -> V_64 ;
if ( ( V_38 -> V_42 >= V_72 ) &&
( V_126 -> V_98 != NULL ) ) {
V_152 = V_126 -> V_98 ;
if ( V_152 -> V_21 > V_153 ) {
F_11 ( L_15 , V_152 -> V_21 ) ;
return - V_51 ;
}
V_17 = F_57 ( V_38 , V_126 -> V_36 , & V_126 -> V_95 ,
V_64 , V_152 -> V_21 * 4 ) ;
if ( V_17 ) {
F_11 ( L_16 ) ;
return V_17 ;
}
V_126 -> V_95 . V_154 = true ;
V_126 -> V_95 . V_21 = V_152 -> V_21 ;
if ( F_25 ( V_126 -> V_95 . V_155 ,
V_152 -> V_114 ,
V_152 -> V_21 * 4 ) )
return - V_102 ;
}
V_152 = V_126 -> V_96 ;
if ( V_152 -> V_21 > V_153 ) {
F_11 ( L_17 , V_152 -> V_21 ) ;
return - V_51 ;
}
}
V_152 = V_126 -> V_96 ;
V_17 = F_57 ( V_38 , V_126 -> V_36 , & V_126 -> V_63 ,
V_64 , V_152 -> V_21 * 4 ) ;
if ( V_17 ) {
F_11 ( L_18 ) ;
return V_17 ;
}
V_126 -> V_63 . V_21 = V_152 -> V_21 ;
if ( V_152 -> V_28 )
memcpy ( V_126 -> V_63 . V_155 , V_152 -> V_28 , V_152 -> V_21 * 4 ) ;
else if ( F_25 ( V_126 -> V_63 . V_155 , V_152 -> V_114 , V_152 -> V_21 * 4 ) )
return - V_102 ;
return 0 ;
}
int F_58 ( struct V_156 * V_143 , void * V_87 , struct V_157 * V_29 )
{
struct V_133 * V_38 = V_143 -> V_158 ;
struct V_11 V_126 ;
int V_17 ;
F_16 ( & V_38 -> V_159 ) ;
if ( ! V_38 -> V_160 ) {
F_18 ( & V_38 -> V_159 ) ;
return - V_161 ;
}
if ( V_38 -> V_162 ) {
F_18 ( & V_38 -> V_159 ) ;
V_17 = F_55 ( V_38 ) ;
if ( ! V_17 )
V_17 = - V_151 ;
return V_17 ;
}
memset ( & V_126 , 0 , sizeof( struct V_11 ) ) ;
V_126 . V_29 = V_29 ;
V_126 . V_38 = V_38 ;
V_126 . V_143 = V_38 -> V_143 ;
V_126 . V_42 = V_38 -> V_42 ;
V_17 = F_23 ( & V_126 , V_87 ) ;
if ( V_17 ) {
F_11 ( L_19 ) ;
F_29 ( & V_126 , V_17 , false ) ;
F_18 ( & V_38 -> V_159 ) ;
V_17 = F_54 ( V_38 , V_17 ) ;
return V_17 ;
}
V_17 = F_56 ( V_38 , & V_126 ) ;
if ( ! V_17 ) {
V_17 = F_8 ( & V_126 ) ;
if ( V_17 && V_17 != - V_135 )
F_11 ( L_20 , V_17 ) ;
}
if ( V_17 ) {
F_29 ( & V_126 , V_17 , false ) ;
F_18 ( & V_38 -> V_159 ) ;
V_17 = F_54 ( V_38 , V_17 ) ;
return V_17 ;
}
F_59 ( & V_126 ) ;
V_17 = F_37 ( V_38 , & V_126 ) ;
if ( V_17 ) {
goto V_149;
}
V_17 = F_50 ( V_38 , & V_126 ) ;
if ( V_17 ) {
goto V_149;
}
V_149:
F_29 ( & V_126 , V_17 , true ) ;
F_18 ( & V_38 -> V_159 ) ;
V_17 = F_54 ( V_38 , V_17 ) ;
return V_17 ;
}
int F_60 ( struct V_11 * V_12 ,
struct V_163 * V_164 ,
unsigned V_93 )
{
struct V_13 * V_152 = V_12 -> V_96 ;
struct V_133 * V_38 = V_12 -> V_38 ;
T_1 V_165 ;
int V_166 = 0 , V_3 ;
if ( V_93 >= V_152 -> V_21 ) {
F_11 ( L_21 ,
V_93 , V_152 -> V_21 ) ;
return - V_51 ;
}
V_165 = F_61 ( V_12 , V_93 ) ;
V_164 -> V_93 = V_93 ;
V_164 -> type = F_62 ( V_165 ) ;
V_164 -> V_167 = F_63 ( V_165 ) ;
V_164 -> V_168 = 0 ;
switch ( V_164 -> type ) {
case V_169 :
if ( V_38 -> V_42 < V_170 ) {
V_164 -> V_171 = F_64 ( V_165 ) ;
V_164 -> V_168 =
F_65 ( V_165 ) ;
} else
V_164 -> V_171 = F_66 ( V_165 ) ;
break;
case V_172 :
V_164 -> V_173 = F_67 ( V_165 ) ;
break;
case V_174 :
V_164 -> V_167 = - 1 ;
break;
default:
F_11 ( L_22 , V_164 -> type , V_93 ) ;
V_166 = - V_51 ;
goto V_175;
}
if ( ( V_164 -> V_167 + 1 + V_164 -> V_93 ) >= V_152 -> V_21 ) {
F_11 ( L_23 ,
V_164 -> V_93 , V_164 -> type , V_164 -> V_167 , V_152 -> V_21 ) ;
V_166 = - V_51 ;
goto V_175;
}
return 0 ;
V_175:
for ( V_3 = 0 ; V_3 < V_152 -> V_21 ; V_3 ++ ) {
if ( V_3 == V_93 )
F_68 ( L_24 , F_61 ( V_12 , V_3 ) ) ;
else
F_68 ( L_25 , F_61 ( V_12 , V_3 ) ) ;
}
return V_166 ;
}
bool F_69 ( struct V_11 * V_12 )
{
struct V_163 V_176 ;
int V_17 ;
V_17 = F_60 ( V_12 , & V_176 , V_12 -> V_93 ) ;
if ( V_17 )
return false ;
if ( V_176 . type != V_172 )
return false ;
if ( V_176 . V_173 != V_177 )
return false ;
return true ;
}
void F_70 ( struct V_11 * V_12 ,
struct V_163 * V_164 )
{
volatile T_1 * V_63 ;
unsigned V_3 ;
unsigned V_93 ;
V_63 = V_12 -> V_63 . V_155 ;
V_93 = V_164 -> V_93 ;
for ( V_3 = 0 ; V_3 <= ( V_164 -> V_167 + 1 ) ; V_3 ++ , V_93 ++ )
F_71 ( L_26 , V_93 , V_63 [ V_93 ] ) ;
}
int F_72 ( struct V_11 * V_12 ,
struct V_23 * * V_178 ,
int V_179 )
{
struct V_13 * V_180 ;
struct V_163 V_176 ;
unsigned V_93 ;
int V_17 ;
if ( V_12 -> V_18 == NULL ) {
F_11 ( L_27 ) ;
return - V_51 ;
}
* V_178 = NULL ;
V_180 = V_12 -> V_18 ;
V_17 = F_60 ( V_12 , & V_176 , V_12 -> V_93 ) ;
if ( V_17 )
return V_17 ;
V_12 -> V_93 += V_176 . V_167 + 2 ;
if ( V_176 . type != V_172 ||
V_176 . V_173 != V_177 ) {
F_11 ( L_28 ,
V_176 . V_93 ) ;
F_70 ( V_12 , & V_176 ) ;
return - V_51 ;
}
V_93 = F_61 ( V_12 , V_176 . V_93 + 1 ) ;
if ( V_93 >= V_180 -> V_21 ) {
F_11 ( L_29 ,
V_93 , V_180 -> V_21 ) ;
F_70 ( V_12 , & V_176 ) ;
return - V_51 ;
}
if ( V_179 ) {
* V_178 = V_12 -> V_22 ;
( * V_178 ) -> V_181 =
( V_182 ) V_180 -> V_28 [ V_93 + 3 ] << 32 ;
( * V_178 ) -> V_181 |= V_180 -> V_28 [ V_93 + 0 ] ;
} else
* V_178 = & V_12 -> V_22 [ ( V_93 / 4 ) ] ;
return 0 ;
}

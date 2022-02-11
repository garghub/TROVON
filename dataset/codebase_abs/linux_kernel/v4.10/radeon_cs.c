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
( V_3 == 0 || F_13 ( V_12 -> V_38 -> V_39 ) ||
V_12 -> V_38 -> V_40 == V_41 ||
V_12 -> V_38 -> V_40 == V_42 ) ) {
V_12 -> V_22 [ V_3 ] . V_43 =
V_44 ;
V_12 -> V_22 [ V_3 ] . V_45 =
V_44 ;
V_8 = V_9 ;
} else {
T_1 V_46 = V_17 -> V_35 ?
V_17 -> V_35 : V_17 -> V_47 ;
if ( V_46 & V_48 ) {
F_11 ( L_2
L_3 ) ;
return - V_49 ;
}
V_12 -> V_22 [ V_3 ] . V_43 = V_46 ;
if ( V_46 == V_44 )
V_46 |= V_50 ;
V_12 -> V_22 [ V_3 ] . V_45 = V_46 ;
}
if ( F_14 ( V_12 -> V_22 [ V_3 ] . V_32 -> V_51 . V_52 ) ) {
T_1 V_46 = V_12 -> V_22 [ V_3 ] . V_43 ;
if ( ! ( V_46 & V_50 ) ) {
F_11 ( L_4
L_5 ) ;
return - V_49 ;
}
V_16 = true ;
V_46 = V_50 ;
V_12 -> V_22 [ V_3 ] . V_43 = V_46 ;
V_12 -> V_22 [ V_3 ] . V_45 = V_46 ;
}
V_12 -> V_22 [ V_3 ] . V_53 . V_54 = & V_12 -> V_22 [ V_3 ] . V_32 -> V_51 ;
V_12 -> V_22 [ V_3 ] . V_53 . V_55 = ! V_17 -> V_35 ;
F_3 ( & V_15 , & V_12 -> V_22 [ V_3 ] . V_53 . V_56 ,
V_8 ) ;
}
F_6 ( & V_15 , & V_12 -> V_57 ) ;
if ( V_12 -> V_58 & V_59 )
V_12 -> V_60 = F_15 ( V_12 -> V_38 , V_12 -> V_61 . V_62 ,
& V_12 -> V_57 ) ;
if ( V_16 )
F_16 ( & V_63 -> V_64 -> V_65 ) ;
V_17 = F_17 ( V_12 -> V_38 , & V_12 -> V_66 , & V_12 -> V_57 , V_12 -> V_36 ) ;
if ( V_16 )
F_18 ( & V_63 -> V_64 -> V_65 ) ;
return V_17 ;
}
static int F_19 ( struct V_11 * V_12 , T_2 V_36 , T_3 V_8 )
{
V_12 -> V_8 = V_8 ;
switch ( V_36 ) {
default:
F_11 ( L_6 , V_36 ) ;
return - V_49 ;
case V_67 :
V_12 -> V_36 = V_68 ;
break;
case V_69 :
if ( V_12 -> V_38 -> V_40 >= V_70 ) {
if ( V_12 -> V_8 > 0 )
V_12 -> V_36 = V_71 ;
else
V_12 -> V_36 = V_72 ;
} else
V_12 -> V_36 = V_68 ;
break;
case V_73 :
if ( V_12 -> V_38 -> V_40 >= V_74 ) {
if ( V_12 -> V_8 > 0 )
V_12 -> V_36 = V_75 ;
else
V_12 -> V_36 = V_76 ;
} else if ( V_12 -> V_38 -> V_40 >= V_77 ) {
V_12 -> V_36 = V_75 ;
} else {
return - V_49 ;
}
break;
case V_78 :
V_12 -> V_36 = V_37 ;
break;
case V_79 :
V_12 -> V_36 = V_80 ;
break;
}
return 0 ;
}
static int F_20 ( struct V_11 * V_12 )
{
struct V_23 * V_81 ;
int V_17 ;
F_21 (reloc, &p->validated, tv.head) {
struct V_82 * V_83 ;
V_83 = V_81 -> V_32 -> V_51 . V_83 ;
V_17 = F_22 ( V_12 -> V_38 , & V_12 -> V_61 . V_84 , V_83 ,
V_81 -> V_53 . V_55 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
int F_23 ( struct V_11 * V_12 , void * V_85 )
{
struct V_86 * V_87 = V_85 ;
T_4 * V_88 ;
unsigned V_89 , V_3 ;
T_2 V_36 = V_67 ;
T_3 V_8 = 0 ;
F_2 ( & V_12 -> V_57 ) ;
if ( ! V_87 -> V_90 ) {
return 0 ;
}
V_12 -> V_91 = 0 ;
V_12 -> V_61 . V_92 = NULL ;
V_12 -> V_93 . V_92 = NULL ;
V_12 -> V_94 = NULL ;
V_12 -> V_18 = NULL ;
V_12 -> V_95 = NULL ;
V_12 -> V_96 = NULL ;
V_12 -> V_97 = F_24 ( V_87 -> V_90 , sizeof( T_4 ) , V_98 ) ;
if ( V_12 -> V_97 == NULL ) {
return - V_24 ;
}
V_88 = ( T_4 * ) ( unsigned long ) ( V_87 -> V_99 ) ;
if ( F_25 ( V_12 -> V_97 , V_88 ,
sizeof( T_4 ) * V_87 -> V_90 ) ) {
return - V_100 ;
}
V_12 -> V_58 = 0 ;
V_12 -> V_101 = V_87 -> V_90 ;
V_12 -> V_99 = F_24 ( V_12 -> V_101 , sizeof( struct V_13 ) , V_98 ) ;
if ( V_12 -> V_99 == NULL ) {
return - V_24 ;
}
for ( V_3 = 0 ; V_3 < V_12 -> V_101 ; V_3 ++ ) {
struct V_102 T_5 * * V_103 = NULL ;
struct V_102 V_104 ;
T_1 T_5 * V_105 ;
V_103 = ( void T_5 * ) ( unsigned long ) V_12 -> V_97 [ V_3 ] ;
if ( F_25 ( & V_104 , V_103 ,
sizeof( struct V_102 ) ) ) {
return - V_100 ;
}
V_12 -> V_99 [ V_3 ] . V_21 = V_104 . V_21 ;
if ( V_104 . V_106 == V_107 ) {
V_12 -> V_18 = & V_12 -> V_99 [ V_3 ] ;
}
if ( V_104 . V_106 == V_108 ) {
V_12 -> V_94 = & V_12 -> V_99 [ V_3 ] ;
if ( V_12 -> V_99 [ V_3 ] . V_21 == 0 )
return - V_49 ;
}
if ( V_104 . V_106 == V_109 ) {
V_12 -> V_96 = & V_12 -> V_99 [ V_3 ] ;
if ( V_12 -> V_99 [ V_3 ] . V_21 == 0 )
return - V_49 ;
}
if ( V_104 . V_106 == V_110 ) {
V_12 -> V_95 = & V_12 -> V_99 [ V_3 ] ;
if ( V_12 -> V_99 [ V_3 ] . V_21 == 0 )
return - V_49 ;
}
V_89 = V_12 -> V_99 [ V_3 ] . V_21 ;
V_105 = ( void T_5 * ) ( unsigned long ) V_104 . V_111 ;
V_12 -> V_99 [ V_3 ] . V_112 = V_105 ;
if ( V_104 . V_106 == V_109 )
continue;
if ( V_104 . V_106 == V_108 ) {
if ( ! V_12 -> V_38 || ! ( V_12 -> V_38 -> V_33 & V_113 ) )
continue;
}
V_12 -> V_99 [ V_3 ] . V_28 = F_26 ( V_89 , sizeof( T_1 ) ) ;
V_89 *= sizeof( T_1 ) ;
if ( V_12 -> V_99 [ V_3 ] . V_28 == NULL ) {
return - V_24 ;
}
if ( F_25 ( V_12 -> V_99 [ V_3 ] . V_28 , V_105 , V_89 ) ) {
return - V_100 ;
}
if ( V_104 . V_106 == V_110 ) {
V_12 -> V_58 = V_12 -> V_99 [ V_3 ] . V_28 [ 0 ] ;
if ( V_12 -> V_99 [ V_3 ] . V_21 > 1 )
V_36 = V_12 -> V_99 [ V_3 ] . V_28 [ 1 ] ;
if ( V_12 -> V_99 [ V_3 ] . V_21 > 2 )
V_8 = ( T_3 ) V_12 -> V_99 [ V_3 ] . V_28 [ 2 ] ;
}
}
if ( V_12 -> V_38 ) {
if ( ( V_12 -> V_58 & V_59 ) &&
! V_12 -> V_38 -> V_114 . V_115 ) {
F_11 ( L_7 ) ;
return - V_49 ;
}
if ( F_19 ( V_12 , V_36 , V_8 ) )
return - V_49 ;
if ( ( V_12 -> V_58 & V_59 ) == 0 ) {
if ( V_12 -> V_38 -> V_116 -> V_36 [ V_12 -> V_36 ] -> V_117 == NULL ) {
F_11 ( L_8 , V_12 -> V_36 ) ;
return - V_49 ;
}
} else {
if ( V_12 -> V_38 -> V_116 -> V_36 [ V_12 -> V_36 ] -> V_118 == NULL ) {
F_11 ( L_9 ,
V_12 -> V_36 ) ;
return - V_49 ;
}
}
}
return 0 ;
}
static int F_27 ( void * V_119 , struct V_6 * V_120 ,
struct V_6 * V_2 )
{
struct V_23 * V_121 = F_28 ( V_120 , struct V_23 , V_53 . V_56 ) ;
struct V_23 * V_122 = F_28 ( V_2 , struct V_23 , V_53 . V_56 ) ;
return ( int ) V_121 -> V_32 -> V_51 . V_123 - ( int ) V_122 -> V_32 -> V_51 . V_123 ;
}
static void F_29 ( struct V_11 * V_124 , int error , bool V_125 )
{
unsigned V_3 ;
if ( ! error ) {
F_30 ( NULL , & V_124 -> V_57 , F_27 ) ;
F_31 ( & V_124 -> V_66 ,
& V_124 -> V_57 ,
& V_124 -> V_61 . V_126 -> V_127 ) ;
} else if ( V_125 ) {
F_32 ( & V_124 -> V_66 ,
& V_124 -> V_57 ) ;
}
if ( V_124 -> V_22 != NULL ) {
for ( V_3 = 0 ; V_3 < V_124 -> V_20 ; V_3 ++ ) {
struct V_128 * V_54 = V_124 -> V_22 [ V_3 ] . V_32 ;
if ( V_54 == NULL )
continue;
F_33 ( & V_54 -> V_129 ) ;
}
}
F_34 ( V_124 -> V_130 ) ;
F_35 ( V_124 -> V_22 ) ;
F_35 ( V_124 -> V_60 ) ;
for ( V_3 = 0 ; V_3 < V_124 -> V_101 ; V_3 ++ )
F_35 ( V_124 -> V_99 [ V_3 ] . V_28 ) ;
F_34 ( V_124 -> V_99 ) ;
F_34 ( V_124 -> V_97 ) ;
F_36 ( V_124 -> V_38 , & V_124 -> V_61 ) ;
F_36 ( V_124 -> V_38 , & V_124 -> V_93 ) ;
}
static int F_37 ( struct V_131 * V_38 ,
struct V_11 * V_124 )
{
int V_17 ;
if ( V_124 -> V_94 == NULL )
return 0 ;
if ( V_124 -> V_58 & V_59 )
return 0 ;
V_17 = F_38 ( V_38 , V_124 -> V_36 , V_124 ) ;
if ( V_17 || V_124 -> V_132 ) {
F_11 ( L_10 ) ;
return V_17 ;
}
V_17 = F_20 ( V_124 ) ;
if ( V_17 ) {
if ( V_17 != - V_133 )
F_11 ( L_11 , V_17 ) ;
return V_17 ;
}
if ( V_124 -> V_36 == V_37 )
F_39 ( V_38 ) ;
else if ( ( V_124 -> V_36 == V_80 ) ||
( V_124 -> V_36 == V_134 ) )
F_40 ( V_38 ) ;
V_17 = F_41 ( V_38 , & V_124 -> V_61 , NULL , true ) ;
if ( V_17 ) {
F_11 ( L_12 ) ;
}
return V_17 ;
}
static int F_42 ( struct V_11 * V_12 ,
struct V_135 * V_62 )
{
struct V_131 * V_38 = V_12 -> V_38 ;
struct V_136 * V_137 ;
int V_3 , V_17 ;
V_17 = F_43 ( V_38 , V_62 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_44 ( V_38 , V_62 ) ;
if ( V_17 )
return V_17 ;
if ( V_62 -> V_138 == NULL ) {
F_11 ( L_13 ) ;
return - V_49 ;
}
V_17 = F_45 ( V_38 , V_62 -> V_138 ,
& V_38 -> V_139 . V_54 -> V_51 . V_140 ) ;
if ( V_17 )
return V_17 ;
for ( V_3 = 0 ; V_3 < V_12 -> V_20 ; V_3 ++ ) {
struct V_128 * V_54 ;
V_54 = V_12 -> V_22 [ V_3 ] . V_32 ;
V_137 = F_46 ( V_62 , V_54 ) ;
if ( V_137 == NULL ) {
F_47 ( V_38 -> V_141 , L_14 , V_54 , V_62 ) ;
return - V_49 ;
}
V_17 = F_45 ( V_38 , V_137 , & V_54 -> V_51 . V_140 ) ;
if ( V_17 )
return V_17 ;
F_48 ( & V_12 -> V_61 . V_84 , V_137 -> V_142 ) ;
}
return F_49 ( V_38 , V_62 ) ;
}
static int F_50 ( struct V_131 * V_38 ,
struct V_11 * V_124 )
{
struct V_143 * V_144 = V_124 -> V_29 -> V_145 ;
struct V_135 * V_62 = & V_144 -> V_62 ;
int V_17 ;
if ( V_124 -> V_94 == NULL )
return 0 ;
if ( ( V_124 -> V_58 & V_59 ) == 0 )
return 0 ;
if ( V_124 -> V_93 . V_21 ) {
V_17 = F_51 ( V_38 , V_124 -> V_36 , & V_124 -> V_93 ) ;
if ( V_17 ) {
return V_17 ;
}
}
V_17 = F_51 ( V_38 , V_124 -> V_36 , & V_124 -> V_61 ) ;
if ( V_17 ) {
return V_17 ;
}
if ( V_124 -> V_36 == V_37 )
F_39 ( V_38 ) ;
F_52 ( & V_62 -> V_146 ) ;
V_17 = F_42 ( V_124 , V_62 ) ;
if ( V_17 ) {
goto V_147;
}
V_17 = F_20 ( V_124 ) ;
if ( V_17 ) {
if ( V_17 != - V_133 )
F_11 ( L_11 , V_17 ) ;
goto V_147;
}
if ( ( V_38 -> V_40 >= V_70 ) &&
( V_124 -> V_96 != NULL ) ) {
V_17 = F_41 ( V_38 , & V_124 -> V_61 , & V_124 -> V_93 , true ) ;
} else {
V_17 = F_41 ( V_38 , & V_124 -> V_61 , NULL , true ) ;
}
V_147:
F_53 ( & V_62 -> V_146 ) ;
return V_17 ;
}
static int F_54 ( struct V_131 * V_38 , int V_17 )
{
if ( V_17 == - V_148 ) {
V_17 = F_55 ( V_38 ) ;
if ( ! V_17 )
V_17 = - V_149 ;
}
return V_17 ;
}
static int F_56 ( struct V_131 * V_38 , struct V_11 * V_124 )
{
struct V_13 * V_150 ;
struct V_135 * V_62 = NULL ;
int V_17 ;
if ( V_124 -> V_94 == NULL )
return 0 ;
if ( V_124 -> V_58 & V_59 ) {
struct V_143 * V_144 = V_124 -> V_29 -> V_145 ;
V_62 = & V_144 -> V_62 ;
if ( ( V_38 -> V_40 >= V_70 ) &&
( V_124 -> V_96 != NULL ) ) {
V_150 = V_124 -> V_96 ;
if ( V_150 -> V_21 > V_151 ) {
F_11 ( L_15 , V_150 -> V_21 ) ;
return - V_49 ;
}
V_17 = F_57 ( V_38 , V_124 -> V_36 , & V_124 -> V_93 ,
V_62 , V_150 -> V_21 * 4 ) ;
if ( V_17 ) {
F_11 ( L_16 ) ;
return V_17 ;
}
V_124 -> V_93 . V_152 = true ;
V_124 -> V_93 . V_21 = V_150 -> V_21 ;
if ( F_25 ( V_124 -> V_93 . V_153 ,
V_150 -> V_112 ,
V_150 -> V_21 * 4 ) )
return - V_100 ;
}
V_150 = V_124 -> V_94 ;
if ( V_150 -> V_21 > V_151 ) {
F_11 ( L_17 , V_150 -> V_21 ) ;
return - V_49 ;
}
}
V_150 = V_124 -> V_94 ;
V_17 = F_57 ( V_38 , V_124 -> V_36 , & V_124 -> V_61 ,
V_62 , V_150 -> V_21 * 4 ) ;
if ( V_17 ) {
F_11 ( L_18 ) ;
return V_17 ;
}
V_124 -> V_61 . V_21 = V_150 -> V_21 ;
if ( V_150 -> V_28 )
memcpy ( V_124 -> V_61 . V_153 , V_150 -> V_28 , V_150 -> V_21 * 4 ) ;
else if ( F_25 ( V_124 -> V_61 . V_153 , V_150 -> V_112 , V_150 -> V_21 * 4 ) )
return - V_100 ;
return 0 ;
}
int F_58 ( struct V_154 * V_141 , void * V_85 , struct V_155 * V_29 )
{
struct V_131 * V_38 = V_141 -> V_156 ;
struct V_11 V_124 ;
int V_17 ;
F_16 ( & V_38 -> V_157 ) ;
if ( ! V_38 -> V_158 ) {
F_18 ( & V_38 -> V_157 ) ;
return - V_159 ;
}
if ( V_38 -> V_160 ) {
F_18 ( & V_38 -> V_157 ) ;
V_17 = F_55 ( V_38 ) ;
if ( ! V_17 )
V_17 = - V_149 ;
return V_17 ;
}
memset ( & V_124 , 0 , sizeof( struct V_11 ) ) ;
V_124 . V_29 = V_29 ;
V_124 . V_38 = V_38 ;
V_124 . V_141 = V_38 -> V_141 ;
V_124 . V_40 = V_38 -> V_40 ;
V_17 = F_23 ( & V_124 , V_85 ) ;
if ( V_17 ) {
F_11 ( L_19 ) ;
F_29 ( & V_124 , V_17 , false ) ;
F_18 ( & V_38 -> V_157 ) ;
V_17 = F_54 ( V_38 , V_17 ) ;
return V_17 ;
}
V_17 = F_56 ( V_38 , & V_124 ) ;
if ( ! V_17 ) {
V_17 = F_8 ( & V_124 ) ;
if ( V_17 && V_17 != - V_133 )
F_11 ( L_20 , V_17 ) ;
}
if ( V_17 ) {
F_29 ( & V_124 , V_17 , false ) ;
F_18 ( & V_38 -> V_157 ) ;
V_17 = F_54 ( V_38 , V_17 ) ;
return V_17 ;
}
F_59 ( & V_124 ) ;
V_17 = F_37 ( V_38 , & V_124 ) ;
if ( V_17 ) {
goto V_147;
}
V_17 = F_50 ( V_38 , & V_124 ) ;
if ( V_17 ) {
goto V_147;
}
V_147:
F_29 ( & V_124 , V_17 , true ) ;
F_18 ( & V_38 -> V_157 ) ;
V_17 = F_54 ( V_38 , V_17 ) ;
return V_17 ;
}
int F_60 ( struct V_11 * V_12 ,
struct V_161 * V_162 ,
unsigned V_91 )
{
struct V_13 * V_150 = V_12 -> V_94 ;
struct V_131 * V_38 = V_12 -> V_38 ;
T_1 V_163 ;
int V_164 = 0 , V_3 ;
if ( V_91 >= V_150 -> V_21 ) {
F_11 ( L_21 ,
V_91 , V_150 -> V_21 ) ;
return - V_49 ;
}
V_163 = F_61 ( V_12 , V_91 ) ;
V_162 -> V_91 = V_91 ;
V_162 -> type = F_62 ( V_163 ) ;
V_162 -> V_165 = F_63 ( V_163 ) ;
V_162 -> V_166 = 0 ;
switch ( V_162 -> type ) {
case V_167 :
if ( V_38 -> V_40 < V_168 ) {
V_162 -> V_169 = F_64 ( V_163 ) ;
V_162 -> V_166 =
F_65 ( V_163 ) ;
} else
V_162 -> V_169 = F_66 ( V_163 ) ;
break;
case V_170 :
V_162 -> V_171 = F_67 ( V_163 ) ;
break;
case V_172 :
V_162 -> V_165 = - 1 ;
break;
default:
F_11 ( L_22 , V_162 -> type , V_91 ) ;
V_164 = - V_49 ;
goto V_173;
}
if ( ( V_162 -> V_165 + 1 + V_162 -> V_91 ) >= V_150 -> V_21 ) {
F_11 ( L_23 ,
V_162 -> V_91 , V_162 -> type , V_162 -> V_165 , V_150 -> V_21 ) ;
V_164 = - V_49 ;
goto V_173;
}
return 0 ;
V_173:
for ( V_3 = 0 ; V_3 < V_150 -> V_21 ; V_3 ++ ) {
if ( V_3 == V_91 )
F_68 ( L_24 , F_61 ( V_12 , V_3 ) ) ;
else
F_68 ( L_25 , F_61 ( V_12 , V_3 ) ) ;
}
return V_164 ;
}
bool F_69 ( struct V_11 * V_12 )
{
struct V_161 V_174 ;
int V_17 ;
V_17 = F_60 ( V_12 , & V_174 , V_12 -> V_91 ) ;
if ( V_17 )
return false ;
if ( V_174 . type != V_170 )
return false ;
if ( V_174 . V_171 != V_175 )
return false ;
return true ;
}
void F_70 ( struct V_11 * V_12 ,
struct V_161 * V_162 )
{
volatile T_1 * V_61 ;
unsigned V_3 ;
unsigned V_91 ;
V_61 = V_12 -> V_61 . V_153 ;
V_91 = V_162 -> V_91 ;
for ( V_3 = 0 ; V_3 <= ( V_162 -> V_165 + 1 ) ; V_3 ++ , V_91 ++ )
F_71 ( L_26 , V_91 , V_61 [ V_91 ] ) ;
}
int F_72 ( struct V_11 * V_12 ,
struct V_23 * * V_176 ,
int V_177 )
{
struct V_13 * V_178 ;
struct V_161 V_174 ;
unsigned V_91 ;
int V_17 ;
if ( V_12 -> V_18 == NULL ) {
F_11 ( L_27 ) ;
return - V_49 ;
}
* V_176 = NULL ;
V_178 = V_12 -> V_18 ;
V_17 = F_60 ( V_12 , & V_174 , V_12 -> V_91 ) ;
if ( V_17 )
return V_17 ;
V_12 -> V_91 += V_174 . V_165 + 2 ;
if ( V_174 . type != V_170 ||
V_174 . V_171 != V_175 ) {
F_11 ( L_28 ,
V_174 . V_91 ) ;
F_70 ( V_12 , & V_174 ) ;
return - V_49 ;
}
V_91 = F_61 ( V_12 , V_174 . V_91 + 1 ) ;
if ( V_91 >= V_178 -> V_21 ) {
F_11 ( L_29 ,
V_91 , V_178 -> V_21 ) ;
F_70 ( V_12 , & V_174 ) ;
return - V_49 ;
}
if ( V_177 ) {
* V_176 = V_12 -> V_22 ;
( * V_176 ) -> V_179 =
( V_180 ) V_178 -> V_28 [ V_91 + 3 ] << 32 ;
( * V_176 ) -> V_179 |= V_178 -> V_28 [ V_91 + 0 ] ;
} else
* V_176 = & V_12 -> V_22 [ ( V_91 / 4 ) ] ;
return 0 ;
}

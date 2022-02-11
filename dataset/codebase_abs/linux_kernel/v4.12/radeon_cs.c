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
( V_3 <= 0 || F_13 ( V_12 -> V_38 -> V_39 -> V_40 ,
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
if ( V_12 -> V_22 [ V_3 ] . V_32 -> V_55 ) {
V_12 -> V_22 [ V_3 ] . V_47 &= ~ V_46 ;
if ( ! V_12 -> V_22 [ V_3 ] . V_47 ) {
F_11 ( L_6
L_7 ) ;
return - V_51 ;
}
}
V_12 -> V_22 [ V_3 ] . V_56 . V_57 = & V_12 -> V_22 [ V_3 ] . V_32 -> V_53 ;
V_12 -> V_22 [ V_3 ] . V_56 . V_58 = ! V_17 -> V_35 ;
F_3 ( & V_15 , & V_12 -> V_22 [ V_3 ] . V_56 . V_59 ,
V_8 ) ;
}
F_6 ( & V_15 , & V_12 -> V_60 ) ;
if ( V_12 -> V_61 & V_62 )
V_12 -> V_63 = F_15 ( V_12 -> V_38 , V_12 -> V_64 . V_65 ,
& V_12 -> V_60 ) ;
if ( V_16 )
F_16 ( & V_66 -> V_67 -> V_68 ) ;
V_17 = F_17 ( V_12 -> V_38 , & V_12 -> V_69 , & V_12 -> V_60 , V_12 -> V_36 ) ;
if ( V_16 )
F_18 ( & V_66 -> V_67 -> V_68 ) ;
return V_17 ;
}
static int F_19 ( struct V_11 * V_12 , T_2 V_36 , T_3 V_8 )
{
V_12 -> V_8 = V_8 ;
switch ( V_36 ) {
default:
F_11 ( L_8 , V_36 ) ;
return - V_51 ;
case V_70 :
V_12 -> V_36 = V_71 ;
break;
case V_72 :
if ( V_12 -> V_38 -> V_42 >= V_73 ) {
if ( V_12 -> V_8 > 0 )
V_12 -> V_36 = V_74 ;
else
V_12 -> V_36 = V_75 ;
} else
V_12 -> V_36 = V_71 ;
break;
case V_76 :
if ( V_12 -> V_38 -> V_42 >= V_77 ) {
if ( V_12 -> V_8 > 0 )
V_12 -> V_36 = V_78 ;
else
V_12 -> V_36 = V_79 ;
} else if ( V_12 -> V_38 -> V_42 >= V_80 ) {
V_12 -> V_36 = V_78 ;
} else {
return - V_51 ;
}
break;
case V_81 :
V_12 -> V_36 = V_37 ;
break;
case V_82 :
V_12 -> V_36 = V_83 ;
break;
}
return 0 ;
}
static int F_20 ( struct V_11 * V_12 )
{
struct V_23 * V_84 ;
int V_17 ;
F_21 (reloc, &p->validated, tv.head) {
struct V_85 * V_86 ;
V_86 = V_84 -> V_32 -> V_53 . V_86 ;
V_17 = F_22 ( V_12 -> V_38 , & V_12 -> V_64 . V_87 , V_86 ,
V_84 -> V_56 . V_58 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
int F_23 ( struct V_11 * V_12 , void * V_88 )
{
struct V_89 * V_90 = V_88 ;
T_4 * V_91 ;
unsigned V_92 , V_3 ;
T_2 V_36 = V_70 ;
T_3 V_8 = 0 ;
F_2 ( & V_12 -> V_60 ) ;
if ( ! V_90 -> V_93 ) {
return 0 ;
}
V_12 -> V_94 = 0 ;
V_12 -> V_64 . V_95 = NULL ;
V_12 -> V_96 . V_95 = NULL ;
V_12 -> V_97 = NULL ;
V_12 -> V_18 = NULL ;
V_12 -> V_98 = NULL ;
V_12 -> V_99 = NULL ;
V_12 -> V_100 = F_24 ( V_90 -> V_93 , sizeof( T_4 ) , V_101 ) ;
if ( V_12 -> V_100 == NULL ) {
return - V_24 ;
}
V_91 = ( T_4 * ) ( unsigned long ) ( V_90 -> V_102 ) ;
if ( F_25 ( V_12 -> V_100 , V_91 ,
sizeof( T_4 ) * V_90 -> V_93 ) ) {
return - V_103 ;
}
V_12 -> V_61 = 0 ;
V_12 -> V_104 = V_90 -> V_93 ;
V_12 -> V_102 = F_24 ( V_12 -> V_104 , sizeof( struct V_13 ) , V_101 ) ;
if ( V_12 -> V_102 == NULL ) {
return - V_24 ;
}
for ( V_3 = 0 ; V_3 < V_12 -> V_104 ; V_3 ++ ) {
struct V_105 T_5 * * V_106 = NULL ;
struct V_105 V_107 ;
T_1 T_5 * V_108 ;
V_106 = ( void T_5 * ) ( unsigned long ) V_12 -> V_100 [ V_3 ] ;
if ( F_25 ( & V_107 , V_106 ,
sizeof( struct V_105 ) ) ) {
return - V_103 ;
}
V_12 -> V_102 [ V_3 ] . V_21 = V_107 . V_21 ;
if ( V_107 . V_109 == V_110 ) {
V_12 -> V_18 = & V_12 -> V_102 [ V_3 ] ;
}
if ( V_107 . V_109 == V_111 ) {
V_12 -> V_97 = & V_12 -> V_102 [ V_3 ] ;
if ( V_12 -> V_102 [ V_3 ] . V_21 == 0 )
return - V_51 ;
}
if ( V_107 . V_109 == V_112 ) {
V_12 -> V_99 = & V_12 -> V_102 [ V_3 ] ;
if ( V_12 -> V_102 [ V_3 ] . V_21 == 0 )
return - V_51 ;
}
if ( V_107 . V_109 == V_113 ) {
V_12 -> V_98 = & V_12 -> V_102 [ V_3 ] ;
if ( V_12 -> V_102 [ V_3 ] . V_21 == 0 )
return - V_51 ;
}
V_92 = V_12 -> V_102 [ V_3 ] . V_21 ;
V_108 = ( void T_5 * ) ( unsigned long ) V_107 . V_114 ;
V_12 -> V_102 [ V_3 ] . V_115 = V_108 ;
if ( V_107 . V_109 == V_112 )
continue;
if ( V_107 . V_109 == V_111 ) {
if ( ! V_12 -> V_38 || ! ( V_12 -> V_38 -> V_33 & V_116 ) )
continue;
}
V_12 -> V_102 [ V_3 ] . V_28 = F_26 ( V_92 , sizeof( T_1 ) ) ;
V_92 *= sizeof( T_1 ) ;
if ( V_12 -> V_102 [ V_3 ] . V_28 == NULL ) {
return - V_24 ;
}
if ( F_25 ( V_12 -> V_102 [ V_3 ] . V_28 , V_108 , V_92 ) ) {
return - V_103 ;
}
if ( V_107 . V_109 == V_113 ) {
V_12 -> V_61 = V_12 -> V_102 [ V_3 ] . V_28 [ 0 ] ;
if ( V_12 -> V_102 [ V_3 ] . V_21 > 1 )
V_36 = V_12 -> V_102 [ V_3 ] . V_28 [ 1 ] ;
if ( V_12 -> V_102 [ V_3 ] . V_21 > 2 )
V_8 = ( T_3 ) V_12 -> V_102 [ V_3 ] . V_28 [ 2 ] ;
}
}
if ( V_12 -> V_38 ) {
if ( ( V_12 -> V_61 & V_62 ) &&
! V_12 -> V_38 -> V_117 . V_118 ) {
F_11 ( L_9 ) ;
return - V_51 ;
}
if ( F_19 ( V_12 , V_36 , V_8 ) )
return - V_51 ;
if ( ( V_12 -> V_61 & V_62 ) == 0 ) {
if ( V_12 -> V_38 -> V_119 -> V_36 [ V_12 -> V_36 ] -> V_120 == NULL ) {
F_11 ( L_10 , V_12 -> V_36 ) ;
return - V_51 ;
}
} else {
if ( V_12 -> V_38 -> V_119 -> V_36 [ V_12 -> V_36 ] -> V_121 == NULL ) {
F_11 ( L_11 ,
V_12 -> V_36 ) ;
return - V_51 ;
}
}
}
return 0 ;
}
static int F_27 ( void * V_122 , struct V_6 * V_123 ,
struct V_6 * V_2 )
{
struct V_23 * V_124 = F_28 ( V_123 , struct V_23 , V_56 . V_59 ) ;
struct V_23 * V_125 = F_28 ( V_2 , struct V_23 , V_56 . V_59 ) ;
return ( int ) V_124 -> V_32 -> V_53 . V_126 - ( int ) V_125 -> V_32 -> V_53 . V_126 ;
}
static void F_29 ( struct V_11 * V_127 , int error , bool V_128 )
{
unsigned V_3 ;
if ( ! error ) {
F_30 ( NULL , & V_127 -> V_60 , F_27 ) ;
F_31 ( & V_127 -> V_69 ,
& V_127 -> V_60 ,
& V_127 -> V_64 . V_129 -> V_130 ) ;
} else if ( V_128 ) {
F_32 ( & V_127 -> V_69 ,
& V_127 -> V_60 ) ;
}
if ( V_127 -> V_22 != NULL ) {
for ( V_3 = 0 ; V_3 < V_127 -> V_20 ; V_3 ++ ) {
struct V_131 * V_57 = V_127 -> V_22 [ V_3 ] . V_32 ;
if ( V_57 == NULL )
continue;
F_33 ( & V_57 -> V_132 ) ;
}
}
F_34 ( V_127 -> V_133 ) ;
F_35 ( V_127 -> V_22 ) ;
F_35 ( V_127 -> V_63 ) ;
for ( V_3 = 0 ; V_3 < V_127 -> V_104 ; V_3 ++ )
F_35 ( V_127 -> V_102 [ V_3 ] . V_28 ) ;
F_34 ( V_127 -> V_102 ) ;
F_34 ( V_127 -> V_100 ) ;
F_36 ( V_127 -> V_38 , & V_127 -> V_64 ) ;
F_36 ( V_127 -> V_38 , & V_127 -> V_96 ) ;
}
static int F_37 ( struct V_134 * V_38 ,
struct V_11 * V_127 )
{
int V_17 ;
if ( V_127 -> V_97 == NULL )
return 0 ;
if ( V_127 -> V_61 & V_62 )
return 0 ;
V_17 = F_38 ( V_38 , V_127 -> V_36 , V_127 ) ;
if ( V_17 || V_127 -> V_135 ) {
F_11 ( L_12 ) ;
return V_17 ;
}
V_17 = F_20 ( V_127 ) ;
if ( V_17 ) {
if ( V_17 != - V_136 )
F_11 ( L_13 , V_17 ) ;
return V_17 ;
}
if ( V_127 -> V_36 == V_37 )
F_39 ( V_38 ) ;
else if ( ( V_127 -> V_36 == V_83 ) ||
( V_127 -> V_36 == V_137 ) )
F_40 ( V_38 ) ;
V_17 = F_41 ( V_38 , & V_127 -> V_64 , NULL , true ) ;
if ( V_17 ) {
F_11 ( L_14 ) ;
}
return V_17 ;
}
static int F_42 ( struct V_11 * V_12 ,
struct V_138 * V_65 )
{
struct V_134 * V_38 = V_12 -> V_38 ;
struct V_139 * V_140 ;
int V_3 , V_17 ;
V_17 = F_43 ( V_38 , V_65 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_44 ( V_38 , V_65 ) ;
if ( V_17 )
return V_17 ;
if ( V_65 -> V_141 == NULL ) {
F_11 ( L_15 ) ;
return - V_51 ;
}
V_17 = F_45 ( V_38 , V_65 -> V_141 ,
& V_38 -> V_142 . V_57 -> V_53 . V_143 ) ;
if ( V_17 )
return V_17 ;
for ( V_3 = 0 ; V_3 < V_12 -> V_20 ; V_3 ++ ) {
struct V_131 * V_57 ;
V_57 = V_12 -> V_22 [ V_3 ] . V_32 ;
V_140 = F_46 ( V_65 , V_57 ) ;
if ( V_140 == NULL ) {
F_47 ( V_38 -> V_144 , L_16 , V_57 , V_65 ) ;
return - V_51 ;
}
V_17 = F_45 ( V_38 , V_140 , & V_57 -> V_53 . V_143 ) ;
if ( V_17 )
return V_17 ;
F_48 ( & V_12 -> V_64 . V_87 , V_140 -> V_145 ) ;
}
return F_49 ( V_38 , V_65 ) ;
}
static int F_50 ( struct V_134 * V_38 ,
struct V_11 * V_127 )
{
struct V_146 * V_147 = V_127 -> V_29 -> V_148 ;
struct V_138 * V_65 = & V_147 -> V_65 ;
int V_17 ;
if ( V_127 -> V_97 == NULL )
return 0 ;
if ( ( V_127 -> V_61 & V_62 ) == 0 )
return 0 ;
if ( V_127 -> V_96 . V_21 ) {
V_17 = F_51 ( V_38 , V_127 -> V_36 , & V_127 -> V_96 ) ;
if ( V_17 ) {
return V_17 ;
}
}
V_17 = F_51 ( V_38 , V_127 -> V_36 , & V_127 -> V_64 ) ;
if ( V_17 ) {
return V_17 ;
}
if ( V_127 -> V_36 == V_37 )
F_39 ( V_38 ) ;
F_52 ( & V_65 -> V_149 ) ;
V_17 = F_42 ( V_127 , V_65 ) ;
if ( V_17 ) {
goto V_150;
}
V_17 = F_20 ( V_127 ) ;
if ( V_17 ) {
if ( V_17 != - V_136 )
F_11 ( L_13 , V_17 ) ;
goto V_150;
}
if ( ( V_38 -> V_42 >= V_73 ) &&
( V_127 -> V_99 != NULL ) ) {
V_17 = F_41 ( V_38 , & V_127 -> V_64 , & V_127 -> V_96 , true ) ;
} else {
V_17 = F_41 ( V_38 , & V_127 -> V_64 , NULL , true ) ;
}
V_150:
F_53 ( & V_65 -> V_149 ) ;
return V_17 ;
}
static int F_54 ( struct V_134 * V_38 , int V_17 )
{
if ( V_17 == - V_151 ) {
V_17 = F_55 ( V_38 ) ;
if ( ! V_17 )
V_17 = - V_152 ;
}
return V_17 ;
}
static int F_56 ( struct V_134 * V_38 , struct V_11 * V_127 )
{
struct V_13 * V_153 ;
struct V_138 * V_65 = NULL ;
int V_17 ;
if ( V_127 -> V_97 == NULL )
return 0 ;
if ( V_127 -> V_61 & V_62 ) {
struct V_146 * V_147 = V_127 -> V_29 -> V_148 ;
V_65 = & V_147 -> V_65 ;
if ( ( V_38 -> V_42 >= V_73 ) &&
( V_127 -> V_99 != NULL ) ) {
V_153 = V_127 -> V_99 ;
if ( V_153 -> V_21 > V_154 ) {
F_11 ( L_17 , V_153 -> V_21 ) ;
return - V_51 ;
}
V_17 = F_57 ( V_38 , V_127 -> V_36 , & V_127 -> V_96 ,
V_65 , V_153 -> V_21 * 4 ) ;
if ( V_17 ) {
F_11 ( L_18 ) ;
return V_17 ;
}
V_127 -> V_96 . V_155 = true ;
V_127 -> V_96 . V_21 = V_153 -> V_21 ;
if ( F_25 ( V_127 -> V_96 . V_156 ,
V_153 -> V_115 ,
V_153 -> V_21 * 4 ) )
return - V_103 ;
}
V_153 = V_127 -> V_97 ;
if ( V_153 -> V_21 > V_154 ) {
F_11 ( L_19 , V_153 -> V_21 ) ;
return - V_51 ;
}
}
V_153 = V_127 -> V_97 ;
V_17 = F_57 ( V_38 , V_127 -> V_36 , & V_127 -> V_64 ,
V_65 , V_153 -> V_21 * 4 ) ;
if ( V_17 ) {
F_11 ( L_20 ) ;
return V_17 ;
}
V_127 -> V_64 . V_21 = V_153 -> V_21 ;
if ( V_153 -> V_28 )
memcpy ( V_127 -> V_64 . V_156 , V_153 -> V_28 , V_153 -> V_21 * 4 ) ;
else if ( F_25 ( V_127 -> V_64 . V_156 , V_153 -> V_115 , V_153 -> V_21 * 4 ) )
return - V_103 ;
return 0 ;
}
int F_58 ( struct V_157 * V_144 , void * V_88 , struct V_158 * V_29 )
{
struct V_134 * V_38 = V_144 -> V_159 ;
struct V_11 V_127 ;
int V_17 ;
F_16 ( & V_38 -> V_160 ) ;
if ( ! V_38 -> V_161 ) {
F_18 ( & V_38 -> V_160 ) ;
return - V_162 ;
}
if ( V_38 -> V_163 ) {
F_18 ( & V_38 -> V_160 ) ;
V_17 = F_55 ( V_38 ) ;
if ( ! V_17 )
V_17 = - V_152 ;
return V_17 ;
}
memset ( & V_127 , 0 , sizeof( struct V_11 ) ) ;
V_127 . V_29 = V_29 ;
V_127 . V_38 = V_38 ;
V_127 . V_144 = V_38 -> V_144 ;
V_127 . V_42 = V_38 -> V_42 ;
V_17 = F_23 ( & V_127 , V_88 ) ;
if ( V_17 ) {
F_11 ( L_21 ) ;
F_29 ( & V_127 , V_17 , false ) ;
F_18 ( & V_38 -> V_160 ) ;
V_17 = F_54 ( V_38 , V_17 ) ;
return V_17 ;
}
V_17 = F_56 ( V_38 , & V_127 ) ;
if ( ! V_17 ) {
V_17 = F_8 ( & V_127 ) ;
if ( V_17 && V_17 != - V_136 )
F_11 ( L_22 , V_17 ) ;
}
if ( V_17 ) {
F_29 ( & V_127 , V_17 , false ) ;
F_18 ( & V_38 -> V_160 ) ;
V_17 = F_54 ( V_38 , V_17 ) ;
return V_17 ;
}
F_59 ( & V_127 ) ;
V_17 = F_37 ( V_38 , & V_127 ) ;
if ( V_17 ) {
goto V_150;
}
V_17 = F_50 ( V_38 , & V_127 ) ;
if ( V_17 ) {
goto V_150;
}
V_150:
F_29 ( & V_127 , V_17 , true ) ;
F_18 ( & V_38 -> V_160 ) ;
V_17 = F_54 ( V_38 , V_17 ) ;
return V_17 ;
}
int F_60 ( struct V_11 * V_12 ,
struct V_164 * V_165 ,
unsigned V_94 )
{
struct V_13 * V_153 = V_12 -> V_97 ;
struct V_134 * V_38 = V_12 -> V_38 ;
T_1 V_166 ;
int V_167 = 0 , V_3 ;
if ( V_94 >= V_153 -> V_21 ) {
F_11 ( L_23 ,
V_94 , V_153 -> V_21 ) ;
return - V_51 ;
}
V_166 = F_61 ( V_12 , V_94 ) ;
V_165 -> V_94 = V_94 ;
V_165 -> type = F_62 ( V_166 ) ;
V_165 -> V_168 = F_63 ( V_166 ) ;
V_165 -> V_169 = 0 ;
switch ( V_165 -> type ) {
case V_170 :
if ( V_38 -> V_42 < V_171 ) {
V_165 -> V_172 = F_64 ( V_166 ) ;
V_165 -> V_169 =
F_65 ( V_166 ) ;
} else
V_165 -> V_172 = F_66 ( V_166 ) ;
break;
case V_173 :
V_165 -> V_174 = F_67 ( V_166 ) ;
break;
case V_175 :
V_165 -> V_168 = - 1 ;
break;
default:
F_11 ( L_24 , V_165 -> type , V_94 ) ;
V_167 = - V_51 ;
goto V_176;
}
if ( ( V_165 -> V_168 + 1 + V_165 -> V_94 ) >= V_153 -> V_21 ) {
F_11 ( L_25 ,
V_165 -> V_94 , V_165 -> type , V_165 -> V_168 , V_153 -> V_21 ) ;
V_167 = - V_51 ;
goto V_176;
}
return 0 ;
V_176:
for ( V_3 = 0 ; V_3 < V_153 -> V_21 ; V_3 ++ ) {
if ( V_3 == V_94 )
F_68 ( L_26 , F_61 ( V_12 , V_3 ) ) ;
else
F_68 ( L_27 , F_61 ( V_12 , V_3 ) ) ;
}
return V_167 ;
}
bool F_69 ( struct V_11 * V_12 )
{
struct V_164 V_177 ;
int V_17 ;
V_17 = F_60 ( V_12 , & V_177 , V_12 -> V_94 ) ;
if ( V_17 )
return false ;
if ( V_177 . type != V_173 )
return false ;
if ( V_177 . V_174 != V_178 )
return false ;
return true ;
}
void F_70 ( struct V_11 * V_12 ,
struct V_164 * V_165 )
{
volatile T_1 * V_64 ;
unsigned V_3 ;
unsigned V_94 ;
V_64 = V_12 -> V_64 . V_156 ;
V_94 = V_165 -> V_94 ;
for ( V_3 = 0 ; V_3 <= ( V_165 -> V_168 + 1 ) ; V_3 ++ , V_94 ++ )
F_71 ( L_28 , V_94 , V_64 [ V_94 ] ) ;
}
int F_72 ( struct V_11 * V_12 ,
struct V_23 * * V_179 ,
int V_180 )
{
struct V_13 * V_181 ;
struct V_164 V_177 ;
unsigned V_94 ;
int V_17 ;
if ( V_12 -> V_18 == NULL ) {
F_11 ( L_29 ) ;
return - V_51 ;
}
* V_179 = NULL ;
V_181 = V_12 -> V_18 ;
V_17 = F_60 ( V_12 , & V_177 , V_12 -> V_94 ) ;
if ( V_17 )
return V_17 ;
V_12 -> V_94 += V_177 . V_168 + 2 ;
if ( V_177 . type != V_173 ||
V_177 . V_174 != V_178 ) {
F_11 ( L_30 ,
V_177 . V_94 ) ;
F_70 ( V_12 , & V_177 ) ;
return - V_51 ;
}
V_94 = F_61 ( V_12 , V_177 . V_94 + 1 ) ;
if ( V_94 >= V_181 -> V_21 ) {
F_11 ( L_31 ,
V_94 , V_181 -> V_21 ) ;
F_70 ( V_12 , & V_177 ) ;
return - V_51 ;
}
if ( V_180 ) {
* V_179 = V_12 -> V_22 ;
( * V_179 ) -> V_182 =
( V_183 ) V_181 -> V_28 [ V_94 + 3 ] << 32 ;
( * V_179 ) -> V_182 |= V_181 -> V_28 [ V_94 + 0 ] ;
} else
* V_179 = & V_12 -> V_22 [ ( V_94 / 4 ) ] ;
return 0 ;
}

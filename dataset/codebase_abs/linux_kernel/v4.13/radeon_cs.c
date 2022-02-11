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
V_12 -> V_22 = F_9 ( V_12 -> V_20 , sizeof( struct V_23 ) ,
V_24 | V_25 ) ;
if ( V_12 -> V_22 == NULL ) {
return - V_26 ;
}
F_1 ( & V_15 ) ;
for ( V_3 = 0 ; V_3 < V_12 -> V_20 ; V_3 ++ ) {
struct V_27 * V_17 ;
struct V_28 * V_29 ;
unsigned V_8 ;
V_17 = (struct V_27 * ) & V_14 -> V_30 [ V_3 * 4 ] ;
V_29 = F_10 ( V_12 -> V_31 , V_17 -> V_32 ) ;
if ( V_29 == NULL ) {
F_11 ( L_1 ,
V_17 -> V_32 ) ;
return - V_33 ;
}
V_12 -> V_22 [ V_3 ] . V_34 = F_12 ( V_29 ) ;
V_8 = ( V_17 -> V_35 & V_36 ) * 2
+ ! ! V_17 -> V_37 ;
if ( V_12 -> V_38 == V_39 &&
( V_3 <= 0 || F_13 ( V_12 -> V_40 -> V_41 -> V_42 ,
V_43 ) ||
V_12 -> V_40 -> V_44 == V_45 ||
V_12 -> V_40 -> V_44 == V_46 ) ) {
V_12 -> V_22 [ V_3 ] . V_47 =
V_48 ;
V_12 -> V_22 [ V_3 ] . V_49 =
V_48 ;
V_8 = V_9 ;
} else {
T_1 V_50 = V_17 -> V_37 ?
V_17 -> V_37 : V_17 -> V_51 ;
if ( V_50 & V_52 ) {
F_11 ( L_2
L_3 ) ;
return - V_53 ;
}
V_12 -> V_22 [ V_3 ] . V_47 = V_50 ;
if ( V_50 == V_48 )
V_50 |= V_54 ;
V_12 -> V_22 [ V_3 ] . V_49 = V_50 ;
}
if ( F_14 ( V_12 -> V_22 [ V_3 ] . V_34 -> V_55 . V_56 ) ) {
T_1 V_50 = V_12 -> V_22 [ V_3 ] . V_47 ;
if ( ! ( V_50 & V_54 ) ) {
F_11 ( L_4
L_5 ) ;
return - V_53 ;
}
V_16 = true ;
V_50 = V_54 ;
V_12 -> V_22 [ V_3 ] . V_47 = V_50 ;
V_12 -> V_22 [ V_3 ] . V_49 = V_50 ;
}
if ( V_12 -> V_22 [ V_3 ] . V_34 -> V_57 ) {
V_12 -> V_22 [ V_3 ] . V_49 &= ~ V_48 ;
if ( ! V_12 -> V_22 [ V_3 ] . V_49 ) {
F_11 ( L_6
L_7 ) ;
return - V_53 ;
}
}
V_12 -> V_22 [ V_3 ] . V_58 . V_59 = & V_12 -> V_22 [ V_3 ] . V_34 -> V_55 ;
V_12 -> V_22 [ V_3 ] . V_58 . V_60 = ! V_17 -> V_37 ;
F_3 ( & V_15 , & V_12 -> V_22 [ V_3 ] . V_58 . V_61 ,
V_8 ) ;
}
F_6 ( & V_15 , & V_12 -> V_62 ) ;
if ( V_12 -> V_63 & V_64 )
V_12 -> V_65 = F_15 ( V_12 -> V_40 , V_12 -> V_66 . V_67 ,
& V_12 -> V_62 ) ;
if ( V_16 )
F_16 ( & V_68 -> V_69 -> V_70 ) ;
V_17 = F_17 ( V_12 -> V_40 , & V_12 -> V_71 , & V_12 -> V_62 , V_12 -> V_38 ) ;
if ( V_16 )
F_18 ( & V_68 -> V_69 -> V_70 ) ;
return V_17 ;
}
static int F_19 ( struct V_11 * V_12 , T_2 V_38 , T_3 V_8 )
{
V_12 -> V_8 = V_8 ;
switch ( V_38 ) {
default:
F_11 ( L_8 , V_38 ) ;
return - V_53 ;
case V_72 :
V_12 -> V_38 = V_73 ;
break;
case V_74 :
if ( V_12 -> V_40 -> V_44 >= V_75 ) {
if ( V_12 -> V_8 > 0 )
V_12 -> V_38 = V_76 ;
else
V_12 -> V_38 = V_77 ;
} else
V_12 -> V_38 = V_73 ;
break;
case V_78 :
if ( V_12 -> V_40 -> V_44 >= V_79 ) {
if ( V_12 -> V_8 > 0 )
V_12 -> V_38 = V_80 ;
else
V_12 -> V_38 = V_81 ;
} else if ( V_12 -> V_40 -> V_44 >= V_82 ) {
V_12 -> V_38 = V_80 ;
} else {
return - V_53 ;
}
break;
case V_83 :
V_12 -> V_38 = V_39 ;
break;
case V_84 :
V_12 -> V_38 = V_85 ;
break;
}
return 0 ;
}
static int F_20 ( struct V_11 * V_12 )
{
struct V_23 * V_86 ;
int V_17 ;
F_21 (reloc, &p->validated, tv.head) {
struct V_87 * V_88 ;
V_88 = V_86 -> V_34 -> V_55 . V_88 ;
V_17 = F_22 ( V_12 -> V_40 , & V_12 -> V_66 . V_89 , V_88 ,
V_86 -> V_58 . V_60 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
int F_23 ( struct V_11 * V_12 , void * V_90 )
{
struct V_91 * V_92 = V_90 ;
T_4 * V_93 ;
unsigned V_94 , V_3 ;
T_2 V_38 = V_72 ;
T_3 V_8 = 0 ;
F_2 ( & V_12 -> V_62 ) ;
if ( ! V_92 -> V_95 ) {
return 0 ;
}
V_12 -> V_96 = 0 ;
V_12 -> V_66 . V_97 = NULL ;
V_12 -> V_98 . V_97 = NULL ;
V_12 -> V_99 = NULL ;
V_12 -> V_18 = NULL ;
V_12 -> V_100 = NULL ;
V_12 -> V_101 = NULL ;
V_12 -> V_102 = F_24 ( V_92 -> V_95 , sizeof( T_4 ) , V_24 ) ;
if ( V_12 -> V_102 == NULL ) {
return - V_26 ;
}
V_93 = ( T_4 * ) ( unsigned long ) ( V_92 -> V_103 ) ;
if ( F_25 ( V_12 -> V_102 , V_93 ,
sizeof( T_4 ) * V_92 -> V_95 ) ) {
return - V_104 ;
}
V_12 -> V_63 = 0 ;
V_12 -> V_105 = V_92 -> V_95 ;
V_12 -> V_103 = F_24 ( V_12 -> V_105 , sizeof( struct V_13 ) , V_24 ) ;
if ( V_12 -> V_103 == NULL ) {
return - V_26 ;
}
for ( V_3 = 0 ; V_3 < V_12 -> V_105 ; V_3 ++ ) {
struct V_106 T_5 * * V_107 = NULL ;
struct V_106 V_108 ;
T_1 T_5 * V_109 ;
V_107 = ( void T_5 * ) ( unsigned long ) V_12 -> V_102 [ V_3 ] ;
if ( F_25 ( & V_108 , V_107 ,
sizeof( struct V_106 ) ) ) {
return - V_104 ;
}
V_12 -> V_103 [ V_3 ] . V_21 = V_108 . V_21 ;
if ( V_108 . V_110 == V_111 ) {
V_12 -> V_18 = & V_12 -> V_103 [ V_3 ] ;
}
if ( V_108 . V_110 == V_112 ) {
V_12 -> V_99 = & V_12 -> V_103 [ V_3 ] ;
if ( V_12 -> V_103 [ V_3 ] . V_21 == 0 )
return - V_53 ;
}
if ( V_108 . V_110 == V_113 ) {
V_12 -> V_101 = & V_12 -> V_103 [ V_3 ] ;
if ( V_12 -> V_103 [ V_3 ] . V_21 == 0 )
return - V_53 ;
}
if ( V_108 . V_110 == V_114 ) {
V_12 -> V_100 = & V_12 -> V_103 [ V_3 ] ;
if ( V_12 -> V_103 [ V_3 ] . V_21 == 0 )
return - V_53 ;
}
V_94 = V_12 -> V_103 [ V_3 ] . V_21 ;
V_109 = ( void T_5 * ) ( unsigned long ) V_108 . V_115 ;
V_12 -> V_103 [ V_3 ] . V_116 = V_109 ;
if ( V_108 . V_110 == V_113 )
continue;
if ( V_108 . V_110 == V_112 ) {
if ( ! V_12 -> V_40 || ! ( V_12 -> V_40 -> V_35 & V_117 ) )
continue;
}
V_12 -> V_103 [ V_3 ] . V_30 = F_9 ( V_94 , sizeof( T_1 ) , V_24 ) ;
V_94 *= sizeof( T_1 ) ;
if ( V_12 -> V_103 [ V_3 ] . V_30 == NULL ) {
return - V_26 ;
}
if ( F_25 ( V_12 -> V_103 [ V_3 ] . V_30 , V_109 , V_94 ) ) {
return - V_104 ;
}
if ( V_108 . V_110 == V_114 ) {
V_12 -> V_63 = V_12 -> V_103 [ V_3 ] . V_30 [ 0 ] ;
if ( V_12 -> V_103 [ V_3 ] . V_21 > 1 )
V_38 = V_12 -> V_103 [ V_3 ] . V_30 [ 1 ] ;
if ( V_12 -> V_103 [ V_3 ] . V_21 > 2 )
V_8 = ( T_3 ) V_12 -> V_103 [ V_3 ] . V_30 [ 2 ] ;
}
}
if ( V_12 -> V_40 ) {
if ( ( V_12 -> V_63 & V_64 ) &&
! V_12 -> V_40 -> V_118 . V_119 ) {
F_11 ( L_9 ) ;
return - V_53 ;
}
if ( F_19 ( V_12 , V_38 , V_8 ) )
return - V_53 ;
if ( ( V_12 -> V_63 & V_64 ) == 0 ) {
if ( V_12 -> V_40 -> V_120 -> V_38 [ V_12 -> V_38 ] -> V_121 == NULL ) {
F_11 ( L_10 , V_12 -> V_38 ) ;
return - V_53 ;
}
} else {
if ( V_12 -> V_40 -> V_120 -> V_38 [ V_12 -> V_38 ] -> V_122 == NULL ) {
F_11 ( L_11 ,
V_12 -> V_38 ) ;
return - V_53 ;
}
}
}
return 0 ;
}
static int F_26 ( void * V_123 , struct V_6 * V_124 ,
struct V_6 * V_2 )
{
struct V_23 * V_125 = F_27 ( V_124 , struct V_23 , V_58 . V_61 ) ;
struct V_23 * V_126 = F_27 ( V_2 , struct V_23 , V_58 . V_61 ) ;
return ( int ) V_125 -> V_34 -> V_55 . V_127 - ( int ) V_126 -> V_34 -> V_55 . V_127 ;
}
static void F_28 ( struct V_11 * V_128 , int error , bool V_129 )
{
unsigned V_3 ;
if ( ! error ) {
F_29 ( NULL , & V_128 -> V_62 , F_26 ) ;
F_30 ( & V_128 -> V_71 ,
& V_128 -> V_62 ,
& V_128 -> V_66 . V_130 -> V_131 ) ;
} else if ( V_129 ) {
F_31 ( & V_128 -> V_71 ,
& V_128 -> V_62 ) ;
}
if ( V_128 -> V_22 != NULL ) {
for ( V_3 = 0 ; V_3 < V_128 -> V_20 ; V_3 ++ ) {
struct V_132 * V_59 = V_128 -> V_22 [ V_3 ] . V_34 ;
if ( V_59 == NULL )
continue;
F_32 ( & V_59 -> V_133 ) ;
}
}
F_33 ( V_128 -> V_134 ) ;
F_34 ( V_128 -> V_22 ) ;
F_34 ( V_128 -> V_65 ) ;
for ( V_3 = 0 ; V_3 < V_128 -> V_105 ; V_3 ++ )
F_34 ( V_128 -> V_103 [ V_3 ] . V_30 ) ;
F_33 ( V_128 -> V_103 ) ;
F_33 ( V_128 -> V_102 ) ;
F_35 ( V_128 -> V_40 , & V_128 -> V_66 ) ;
F_35 ( V_128 -> V_40 , & V_128 -> V_98 ) ;
}
static int F_36 ( struct V_135 * V_40 ,
struct V_11 * V_128 )
{
int V_17 ;
if ( V_128 -> V_99 == NULL )
return 0 ;
if ( V_128 -> V_63 & V_64 )
return 0 ;
V_17 = F_37 ( V_40 , V_128 -> V_38 , V_128 ) ;
if ( V_17 || V_128 -> V_136 ) {
F_11 ( L_12 ) ;
return V_17 ;
}
V_17 = F_20 ( V_128 ) ;
if ( V_17 ) {
if ( V_17 != - V_137 )
F_11 ( L_13 , V_17 ) ;
return V_17 ;
}
if ( V_128 -> V_38 == V_39 )
F_38 ( V_40 ) ;
else if ( ( V_128 -> V_38 == V_85 ) ||
( V_128 -> V_38 == V_138 ) )
F_39 ( V_40 ) ;
V_17 = F_40 ( V_40 , & V_128 -> V_66 , NULL , true ) ;
if ( V_17 ) {
F_11 ( L_14 ) ;
}
return V_17 ;
}
static int F_41 ( struct V_11 * V_12 ,
struct V_139 * V_67 )
{
struct V_135 * V_40 = V_12 -> V_40 ;
struct V_140 * V_141 ;
int V_3 , V_17 ;
V_17 = F_42 ( V_40 , V_67 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_43 ( V_40 , V_67 ) ;
if ( V_17 )
return V_17 ;
if ( V_67 -> V_142 == NULL ) {
F_11 ( L_15 ) ;
return - V_53 ;
}
V_17 = F_44 ( V_40 , V_67 -> V_142 ,
& V_40 -> V_143 . V_59 -> V_55 . V_144 ) ;
if ( V_17 )
return V_17 ;
for ( V_3 = 0 ; V_3 < V_12 -> V_20 ; V_3 ++ ) {
struct V_132 * V_59 ;
V_59 = V_12 -> V_22 [ V_3 ] . V_34 ;
V_141 = F_45 ( V_67 , V_59 ) ;
if ( V_141 == NULL ) {
F_46 ( V_40 -> V_145 , L_16 , V_59 , V_67 ) ;
return - V_53 ;
}
V_17 = F_44 ( V_40 , V_141 , & V_59 -> V_55 . V_144 ) ;
if ( V_17 )
return V_17 ;
F_47 ( & V_12 -> V_66 . V_89 , V_141 -> V_146 ) ;
}
return F_48 ( V_40 , V_67 ) ;
}
static int F_49 ( struct V_135 * V_40 ,
struct V_11 * V_128 )
{
struct V_147 * V_148 = V_128 -> V_31 -> V_149 ;
struct V_139 * V_67 = & V_148 -> V_67 ;
int V_17 ;
if ( V_128 -> V_99 == NULL )
return 0 ;
if ( ( V_128 -> V_63 & V_64 ) == 0 )
return 0 ;
if ( V_128 -> V_98 . V_21 ) {
V_17 = F_50 ( V_40 , V_128 -> V_38 , & V_128 -> V_98 ) ;
if ( V_17 ) {
return V_17 ;
}
}
V_17 = F_50 ( V_40 , V_128 -> V_38 , & V_128 -> V_66 ) ;
if ( V_17 ) {
return V_17 ;
}
if ( V_128 -> V_38 == V_39 )
F_38 ( V_40 ) ;
F_51 ( & V_67 -> V_150 ) ;
V_17 = F_41 ( V_128 , V_67 ) ;
if ( V_17 ) {
goto V_151;
}
V_17 = F_20 ( V_128 ) ;
if ( V_17 ) {
if ( V_17 != - V_137 )
F_11 ( L_13 , V_17 ) ;
goto V_151;
}
if ( ( V_40 -> V_44 >= V_75 ) &&
( V_128 -> V_101 != NULL ) ) {
V_17 = F_40 ( V_40 , & V_128 -> V_66 , & V_128 -> V_98 , true ) ;
} else {
V_17 = F_40 ( V_40 , & V_128 -> V_66 , NULL , true ) ;
}
V_151:
F_52 ( & V_67 -> V_150 ) ;
return V_17 ;
}
static int F_53 ( struct V_135 * V_40 , int V_17 )
{
if ( V_17 == - V_152 ) {
V_17 = F_54 ( V_40 ) ;
if ( ! V_17 )
V_17 = - V_153 ;
}
return V_17 ;
}
static int F_55 ( struct V_135 * V_40 , struct V_11 * V_128 )
{
struct V_13 * V_154 ;
struct V_139 * V_67 = NULL ;
int V_17 ;
if ( V_128 -> V_99 == NULL )
return 0 ;
if ( V_128 -> V_63 & V_64 ) {
struct V_147 * V_148 = V_128 -> V_31 -> V_149 ;
V_67 = & V_148 -> V_67 ;
if ( ( V_40 -> V_44 >= V_75 ) &&
( V_128 -> V_101 != NULL ) ) {
V_154 = V_128 -> V_101 ;
if ( V_154 -> V_21 > V_155 ) {
F_11 ( L_17 , V_154 -> V_21 ) ;
return - V_53 ;
}
V_17 = F_56 ( V_40 , V_128 -> V_38 , & V_128 -> V_98 ,
V_67 , V_154 -> V_21 * 4 ) ;
if ( V_17 ) {
F_11 ( L_18 ) ;
return V_17 ;
}
V_128 -> V_98 . V_156 = true ;
V_128 -> V_98 . V_21 = V_154 -> V_21 ;
if ( F_25 ( V_128 -> V_98 . V_157 ,
V_154 -> V_116 ,
V_154 -> V_21 * 4 ) )
return - V_104 ;
}
V_154 = V_128 -> V_99 ;
if ( V_154 -> V_21 > V_155 ) {
F_11 ( L_19 , V_154 -> V_21 ) ;
return - V_53 ;
}
}
V_154 = V_128 -> V_99 ;
V_17 = F_56 ( V_40 , V_128 -> V_38 , & V_128 -> V_66 ,
V_67 , V_154 -> V_21 * 4 ) ;
if ( V_17 ) {
F_11 ( L_20 ) ;
return V_17 ;
}
V_128 -> V_66 . V_21 = V_154 -> V_21 ;
if ( V_154 -> V_30 )
memcpy ( V_128 -> V_66 . V_157 , V_154 -> V_30 , V_154 -> V_21 * 4 ) ;
else if ( F_25 ( V_128 -> V_66 . V_157 , V_154 -> V_116 , V_154 -> V_21 * 4 ) )
return - V_104 ;
return 0 ;
}
int F_57 ( struct V_158 * V_145 , void * V_90 , struct V_159 * V_31 )
{
struct V_135 * V_40 = V_145 -> V_160 ;
struct V_11 V_128 ;
int V_17 ;
F_16 ( & V_40 -> V_161 ) ;
if ( ! V_40 -> V_162 ) {
F_18 ( & V_40 -> V_161 ) ;
return - V_163 ;
}
if ( V_40 -> V_164 ) {
F_18 ( & V_40 -> V_161 ) ;
V_17 = F_54 ( V_40 ) ;
if ( ! V_17 )
V_17 = - V_153 ;
return V_17 ;
}
memset ( & V_128 , 0 , sizeof( struct V_11 ) ) ;
V_128 . V_31 = V_31 ;
V_128 . V_40 = V_40 ;
V_128 . V_145 = V_40 -> V_145 ;
V_128 . V_44 = V_40 -> V_44 ;
V_17 = F_23 ( & V_128 , V_90 ) ;
if ( V_17 ) {
F_11 ( L_21 ) ;
F_28 ( & V_128 , V_17 , false ) ;
F_18 ( & V_40 -> V_161 ) ;
V_17 = F_53 ( V_40 , V_17 ) ;
return V_17 ;
}
V_17 = F_55 ( V_40 , & V_128 ) ;
if ( ! V_17 ) {
V_17 = F_8 ( & V_128 ) ;
if ( V_17 && V_17 != - V_137 )
F_11 ( L_22 , V_17 ) ;
}
if ( V_17 ) {
F_28 ( & V_128 , V_17 , false ) ;
F_18 ( & V_40 -> V_161 ) ;
V_17 = F_53 ( V_40 , V_17 ) ;
return V_17 ;
}
F_58 ( & V_128 ) ;
V_17 = F_36 ( V_40 , & V_128 ) ;
if ( V_17 ) {
goto V_151;
}
V_17 = F_49 ( V_40 , & V_128 ) ;
if ( V_17 ) {
goto V_151;
}
V_151:
F_28 ( & V_128 , V_17 , true ) ;
F_18 ( & V_40 -> V_161 ) ;
V_17 = F_53 ( V_40 , V_17 ) ;
return V_17 ;
}
int F_59 ( struct V_11 * V_12 ,
struct V_165 * V_166 ,
unsigned V_96 )
{
struct V_13 * V_154 = V_12 -> V_99 ;
struct V_135 * V_40 = V_12 -> V_40 ;
T_1 V_167 ;
int V_168 = 0 , V_3 ;
if ( V_96 >= V_154 -> V_21 ) {
F_11 ( L_23 ,
V_96 , V_154 -> V_21 ) ;
return - V_53 ;
}
V_167 = F_60 ( V_12 , V_96 ) ;
V_166 -> V_96 = V_96 ;
V_166 -> type = F_61 ( V_167 ) ;
V_166 -> V_169 = F_62 ( V_167 ) ;
V_166 -> V_170 = 0 ;
switch ( V_166 -> type ) {
case V_171 :
if ( V_40 -> V_44 < V_172 ) {
V_166 -> V_173 = F_63 ( V_167 ) ;
V_166 -> V_170 =
F_64 ( V_167 ) ;
} else
V_166 -> V_173 = F_65 ( V_167 ) ;
break;
case V_174 :
V_166 -> V_175 = F_66 ( V_167 ) ;
break;
case V_176 :
V_166 -> V_169 = - 1 ;
break;
default:
F_11 ( L_24 , V_166 -> type , V_96 ) ;
V_168 = - V_53 ;
goto V_177;
}
if ( ( V_166 -> V_169 + 1 + V_166 -> V_96 ) >= V_154 -> V_21 ) {
F_11 ( L_25 ,
V_166 -> V_96 , V_166 -> type , V_166 -> V_169 , V_154 -> V_21 ) ;
V_168 = - V_53 ;
goto V_177;
}
return 0 ;
V_177:
for ( V_3 = 0 ; V_3 < V_154 -> V_21 ; V_3 ++ ) {
if ( V_3 == V_96 )
F_67 ( L_26 , F_60 ( V_12 , V_3 ) ) ;
else
F_67 ( L_27 , F_60 ( V_12 , V_3 ) ) ;
}
return V_168 ;
}
bool F_68 ( struct V_11 * V_12 )
{
struct V_165 V_178 ;
int V_17 ;
V_17 = F_59 ( V_12 , & V_178 , V_12 -> V_96 ) ;
if ( V_17 )
return false ;
if ( V_178 . type != V_174 )
return false ;
if ( V_178 . V_175 != V_179 )
return false ;
return true ;
}
void F_69 ( struct V_11 * V_12 ,
struct V_165 * V_166 )
{
volatile T_1 * V_66 ;
unsigned V_3 ;
unsigned V_96 ;
V_66 = V_12 -> V_66 . V_157 ;
V_96 = V_166 -> V_96 ;
for ( V_3 = 0 ; V_3 <= ( V_166 -> V_169 + 1 ) ; V_3 ++ , V_96 ++ )
F_70 ( L_28 , V_96 , V_66 [ V_96 ] ) ;
}
int F_71 ( struct V_11 * V_12 ,
struct V_23 * * V_180 ,
int V_181 )
{
struct V_13 * V_182 ;
struct V_165 V_178 ;
unsigned V_96 ;
int V_17 ;
if ( V_12 -> V_18 == NULL ) {
F_11 ( L_29 ) ;
return - V_53 ;
}
* V_180 = NULL ;
V_182 = V_12 -> V_18 ;
V_17 = F_59 ( V_12 , & V_178 , V_12 -> V_96 ) ;
if ( V_17 )
return V_17 ;
V_12 -> V_96 += V_178 . V_169 + 2 ;
if ( V_178 . type != V_174 ||
V_178 . V_175 != V_179 ) {
F_11 ( L_30 ,
V_178 . V_96 ) ;
F_69 ( V_12 , & V_178 ) ;
return - V_53 ;
}
V_96 = F_60 ( V_12 , V_178 . V_96 + 1 ) ;
if ( V_96 >= V_182 -> V_21 ) {
F_11 ( L_31 ,
V_96 , V_182 -> V_21 ) ;
F_69 ( V_12 , & V_178 ) ;
return - V_53 ;
}
if ( V_181 ) {
* V_180 = V_12 -> V_22 ;
( * V_180 ) -> V_183 =
( V_184 ) V_182 -> V_30 [ V_96 + 3 ] << 32 ;
( * V_180 ) -> V_183 |= V_182 -> V_30 [ V_96 + 0 ] ;
} else
* V_180 = & V_12 -> V_22 [ ( V_96 / 4 ) ] ;
return 0 ;
}

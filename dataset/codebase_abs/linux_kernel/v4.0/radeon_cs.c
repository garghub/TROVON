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
struct V_13 * V_14 = V_12 -> V_15 -> V_14 ;
struct V_16 * V_17 ;
struct V_1 V_18 ;
unsigned V_3 ;
bool V_19 = false ;
int V_20 ;
if ( V_12 -> V_21 == NULL ) {
return 0 ;
}
V_17 = V_12 -> V_21 ;
V_12 -> V_22 = 0 ;
V_12 -> V_23 = V_17 -> V_24 / 4 ;
V_12 -> V_25 = F_9 ( V_12 -> V_23 , sizeof( struct V_26 ) , V_27 ) ;
if ( V_12 -> V_25 == NULL ) {
return - V_28 ;
}
F_1 ( & V_18 ) ;
for ( V_3 = 0 ; V_3 < V_12 -> V_23 ; V_3 ++ ) {
struct V_29 * V_20 ;
struct V_30 * V_31 ;
unsigned V_8 ;
V_20 = (struct V_29 * ) & V_17 -> V_32 [ V_3 * 4 ] ;
V_31 = F_10 ( V_14 , V_12 -> V_33 , V_20 -> V_34 ) ;
if ( V_31 == NULL ) {
F_11 ( L_1 ,
V_20 -> V_34 ) ;
return - V_35 ;
}
V_12 -> V_25 [ V_3 ] . V_36 = F_12 ( V_31 ) ;
V_8 = ( V_20 -> V_37 & V_38 ) * 2
+ ! ! V_20 -> V_39 ;
if ( V_12 -> V_40 == V_41 &&
( V_3 == 0 || F_13 ( V_12 -> V_15 -> V_14 ) ||
V_12 -> V_15 -> V_42 == V_43 ||
V_12 -> V_15 -> V_42 == V_44 ) ) {
V_12 -> V_25 [ V_3 ] . V_45 =
V_46 ;
V_12 -> V_25 [ V_3 ] . V_47 =
V_46 ;
V_8 = V_9 ;
} else {
T_1 V_48 = V_20 -> V_39 ?
V_20 -> V_39 : V_20 -> V_49 ;
if ( V_48 & V_50 ) {
F_11 ( L_2
L_3 ) ;
return - V_51 ;
}
V_12 -> V_25 [ V_3 ] . V_45 = V_48 ;
if ( V_48 == V_46 )
V_48 |= V_52 ;
V_12 -> V_25 [ V_3 ] . V_47 = V_48 ;
}
if ( F_14 ( V_12 -> V_25 [ V_3 ] . V_36 -> V_53 . V_54 ) ) {
T_1 V_48 = V_12 -> V_25 [ V_3 ] . V_45 ;
if ( ! ( V_48 & V_52 ) ) {
F_11 ( L_4
L_5 ) ;
return - V_51 ;
}
V_19 = true ;
V_48 = V_52 ;
V_12 -> V_25 [ V_3 ] . V_45 = V_48 ;
V_12 -> V_25 [ V_3 ] . V_47 = V_48 ;
}
V_12 -> V_25 [ V_3 ] . V_55 . V_56 = & V_12 -> V_25 [ V_3 ] . V_36 -> V_53 ;
V_12 -> V_25 [ V_3 ] . V_55 . V_57 = ! V_20 -> V_39 ;
F_3 ( & V_18 , & V_12 -> V_25 [ V_3 ] . V_55 . V_58 ,
V_8 ) ;
}
F_6 ( & V_18 , & V_12 -> V_59 ) ;
if ( V_12 -> V_60 & V_61 )
V_12 -> V_62 = F_15 ( V_12 -> V_15 , V_12 -> V_63 . V_64 ,
& V_12 -> V_59 ) ;
if ( V_19 )
F_16 ( & V_65 -> V_66 -> V_67 ) ;
V_20 = F_17 ( V_12 -> V_15 , & V_12 -> V_68 , & V_12 -> V_59 , V_12 -> V_40 ) ;
if ( V_19 )
F_18 ( & V_65 -> V_66 -> V_67 ) ;
return V_20 ;
}
static int F_19 ( struct V_11 * V_12 , T_2 V_40 , T_3 V_8 )
{
V_12 -> V_8 = V_8 ;
switch ( V_40 ) {
default:
F_11 ( L_6 , V_40 ) ;
return - V_51 ;
case V_69 :
V_12 -> V_40 = V_70 ;
break;
case V_71 :
if ( V_12 -> V_15 -> V_42 >= V_72 ) {
if ( V_12 -> V_8 > 0 )
V_12 -> V_40 = V_73 ;
else
V_12 -> V_40 = V_74 ;
} else
V_12 -> V_40 = V_70 ;
break;
case V_75 :
if ( V_12 -> V_15 -> V_42 >= V_76 ) {
if ( V_12 -> V_8 > 0 )
V_12 -> V_40 = V_77 ;
else
V_12 -> V_40 = V_78 ;
} else if ( V_12 -> V_15 -> V_42 >= V_79 ) {
V_12 -> V_40 = V_77 ;
} else {
return - V_51 ;
}
break;
case V_80 :
V_12 -> V_40 = V_41 ;
break;
case V_81 :
V_12 -> V_40 = V_82 ;
break;
}
return 0 ;
}
static int F_20 ( struct V_11 * V_12 )
{
struct V_26 * V_83 ;
int V_20 ;
F_21 (reloc, &p->validated, tv.head) {
struct V_84 * V_85 ;
V_85 = V_83 -> V_36 -> V_53 . V_85 ;
V_20 = F_22 ( V_12 -> V_15 , & V_12 -> V_63 . V_86 , V_85 ,
V_83 -> V_55 . V_57 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
int F_23 ( struct V_11 * V_12 , void * V_87 )
{
struct V_88 * V_89 = V_87 ;
T_4 * V_90 ;
unsigned V_91 , V_3 ;
T_2 V_40 = V_69 ;
T_3 V_8 = 0 ;
F_2 ( & V_12 -> V_59 ) ;
if ( ! V_89 -> V_92 ) {
return 0 ;
}
V_12 -> V_93 = 0 ;
V_12 -> V_63 . V_94 = NULL ;
V_12 -> V_95 . V_94 = NULL ;
V_12 -> V_96 = NULL ;
V_12 -> V_21 = NULL ;
V_12 -> V_97 = NULL ;
V_12 -> V_98 = NULL ;
V_12 -> V_99 = F_9 ( V_89 -> V_92 , sizeof( T_4 ) , V_27 ) ;
if ( V_12 -> V_99 == NULL ) {
return - V_28 ;
}
V_90 = ( T_4 * ) ( unsigned long ) ( V_89 -> V_100 ) ;
if ( F_24 ( V_12 -> V_99 , V_90 ,
sizeof( T_4 ) * V_89 -> V_92 ) ) {
return - V_101 ;
}
V_12 -> V_60 = 0 ;
V_12 -> V_102 = V_89 -> V_92 ;
V_12 -> V_100 = F_9 ( V_12 -> V_102 , sizeof( struct V_16 ) , V_27 ) ;
if ( V_12 -> V_100 == NULL ) {
return - V_28 ;
}
for ( V_3 = 0 ; V_3 < V_12 -> V_102 ; V_3 ++ ) {
struct V_103 T_5 * * V_104 = NULL ;
struct V_103 V_105 ;
T_1 T_5 * V_106 ;
V_104 = ( void T_5 * ) ( unsigned long ) V_12 -> V_99 [ V_3 ] ;
if ( F_24 ( & V_105 , V_104 ,
sizeof( struct V_103 ) ) ) {
return - V_101 ;
}
V_12 -> V_100 [ V_3 ] . V_24 = V_105 . V_24 ;
if ( V_105 . V_107 == V_108 ) {
V_12 -> V_21 = & V_12 -> V_100 [ V_3 ] ;
}
if ( V_105 . V_107 == V_109 ) {
V_12 -> V_96 = & V_12 -> V_100 [ V_3 ] ;
if ( V_12 -> V_100 [ V_3 ] . V_24 == 0 )
return - V_51 ;
}
if ( V_105 . V_107 == V_110 ) {
V_12 -> V_98 = & V_12 -> V_100 [ V_3 ] ;
if ( V_12 -> V_100 [ V_3 ] . V_24 == 0 )
return - V_51 ;
}
if ( V_105 . V_107 == V_111 ) {
V_12 -> V_97 = & V_12 -> V_100 [ V_3 ] ;
if ( V_12 -> V_100 [ V_3 ] . V_24 == 0 )
return - V_51 ;
}
V_91 = V_12 -> V_100 [ V_3 ] . V_24 ;
V_106 = ( void T_5 * ) ( unsigned long ) V_105 . V_112 ;
V_12 -> V_100 [ V_3 ] . V_113 = V_106 ;
if ( V_105 . V_107 == V_110 )
continue;
if ( V_105 . V_107 == V_109 ) {
if ( ! V_12 -> V_15 || ! ( V_12 -> V_15 -> V_37 & V_114 ) )
continue;
}
V_12 -> V_100 [ V_3 ] . V_32 = F_25 ( V_91 , sizeof( T_1 ) ) ;
V_91 *= sizeof( T_1 ) ;
if ( V_12 -> V_100 [ V_3 ] . V_32 == NULL ) {
return - V_28 ;
}
if ( F_24 ( V_12 -> V_100 [ V_3 ] . V_32 , V_106 , V_91 ) ) {
return - V_101 ;
}
if ( V_105 . V_107 == V_111 ) {
V_12 -> V_60 = V_12 -> V_100 [ V_3 ] . V_32 [ 0 ] ;
if ( V_12 -> V_100 [ V_3 ] . V_24 > 1 )
V_40 = V_12 -> V_100 [ V_3 ] . V_32 [ 1 ] ;
if ( V_12 -> V_100 [ V_3 ] . V_24 > 2 )
V_8 = ( T_3 ) V_12 -> V_100 [ V_3 ] . V_32 [ 2 ] ;
}
}
if ( V_12 -> V_15 ) {
if ( ( V_12 -> V_60 & V_61 ) &&
! V_12 -> V_15 -> V_115 . V_116 ) {
F_11 ( L_7 ) ;
return - V_51 ;
}
if ( F_19 ( V_12 , V_40 , V_8 ) )
return - V_51 ;
if ( ( V_12 -> V_60 & V_61 ) == 0 ) {
if ( V_12 -> V_15 -> V_117 -> V_40 [ V_12 -> V_40 ] -> V_118 == NULL ) {
F_11 ( L_8 , V_12 -> V_40 ) ;
return - V_51 ;
}
} else {
if ( V_12 -> V_15 -> V_117 -> V_40 [ V_12 -> V_40 ] -> V_119 == NULL ) {
F_11 ( L_9 ,
V_12 -> V_40 ) ;
return - V_51 ;
}
}
}
return 0 ;
}
static int F_26 ( void * V_120 , struct V_6 * V_121 ,
struct V_6 * V_2 )
{
struct V_26 * V_122 = F_27 ( V_121 , struct V_26 , V_55 . V_58 ) ;
struct V_26 * V_123 = F_27 ( V_2 , struct V_26 , V_55 . V_58 ) ;
return ( int ) V_122 -> V_36 -> V_53 . V_124 - ( int ) V_123 -> V_36 -> V_53 . V_124 ;
}
static void F_28 ( struct V_11 * V_125 , int error , bool V_126 )
{
unsigned V_3 ;
if ( ! error ) {
F_29 ( NULL , & V_125 -> V_59 , F_26 ) ;
F_30 ( & V_125 -> V_68 ,
& V_125 -> V_59 ,
& V_125 -> V_63 . V_127 -> V_128 ) ;
} else if ( V_126 ) {
F_31 ( & V_125 -> V_68 ,
& V_125 -> V_59 ) ;
}
if ( V_125 -> V_25 != NULL ) {
for ( V_3 = 0 ; V_3 < V_125 -> V_23 ; V_3 ++ ) {
struct V_129 * V_56 = V_125 -> V_25 [ V_3 ] . V_36 ;
if ( V_56 == NULL )
continue;
F_32 ( & V_56 -> V_130 ) ;
}
}
F_33 ( V_125 -> V_131 ) ;
F_33 ( V_125 -> V_25 ) ;
F_34 ( V_125 -> V_62 ) ;
for ( V_3 = 0 ; V_3 < V_125 -> V_102 ; V_3 ++ )
F_34 ( V_125 -> V_100 [ V_3 ] . V_32 ) ;
F_33 ( V_125 -> V_100 ) ;
F_33 ( V_125 -> V_99 ) ;
F_35 ( V_125 -> V_15 , & V_125 -> V_63 ) ;
F_35 ( V_125 -> V_15 , & V_125 -> V_95 ) ;
}
static int F_36 ( struct V_132 * V_15 ,
struct V_11 * V_125 )
{
int V_20 ;
if ( V_125 -> V_96 == NULL )
return 0 ;
if ( V_125 -> V_60 & V_61 )
return 0 ;
V_20 = F_37 ( V_15 , V_125 -> V_40 , V_125 ) ;
if ( V_20 || V_125 -> V_133 ) {
F_11 ( L_10 ) ;
return V_20 ;
}
V_20 = F_20 ( V_125 ) ;
if ( V_20 ) {
if ( V_20 != - V_134 )
F_11 ( L_11 , V_20 ) ;
return V_20 ;
}
if ( V_125 -> V_40 == V_41 )
F_38 ( V_15 ) ;
else if ( ( V_125 -> V_40 == V_82 ) ||
( V_125 -> V_40 == V_135 ) )
F_39 ( V_15 ) ;
V_20 = F_40 ( V_15 , & V_125 -> V_63 , NULL , true ) ;
if ( V_20 ) {
F_11 ( L_12 ) ;
}
return V_20 ;
}
static int F_41 ( struct V_11 * V_12 ,
struct V_136 * V_64 )
{
struct V_132 * V_15 = V_12 -> V_15 ;
struct V_137 * V_138 ;
int V_3 , V_20 ;
V_20 = F_42 ( V_15 , V_64 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_43 ( V_15 , V_64 ) ;
if ( V_20 )
return V_20 ;
if ( V_64 -> V_139 == NULL ) {
F_11 ( L_13 ) ;
return - V_51 ;
}
V_20 = F_44 ( V_15 , V_64 -> V_139 ,
& V_15 -> V_140 . V_56 -> V_53 . V_141 ) ;
if ( V_20 )
return V_20 ;
for ( V_3 = 0 ; V_3 < V_12 -> V_23 ; V_3 ++ ) {
struct V_129 * V_56 ;
V_56 = V_12 -> V_25 [ V_3 ] . V_36 ;
V_138 = F_45 ( V_64 , V_56 ) ;
if ( V_138 == NULL ) {
F_46 ( V_15 -> V_142 , L_14 , V_56 , V_64 ) ;
return - V_51 ;
}
V_20 = F_44 ( V_15 , V_138 , & V_56 -> V_53 . V_141 ) ;
if ( V_20 )
return V_20 ;
F_47 ( & V_12 -> V_63 . V_86 , V_138 -> V_143 ) ;
}
return F_48 ( V_15 , V_64 ) ;
}
static int F_49 ( struct V_132 * V_15 ,
struct V_11 * V_125 )
{
struct V_144 * V_145 = V_125 -> V_33 -> V_146 ;
struct V_136 * V_64 = & V_145 -> V_64 ;
int V_20 ;
if ( V_125 -> V_96 == NULL )
return 0 ;
if ( ( V_125 -> V_60 & V_61 ) == 0 )
return 0 ;
if ( V_125 -> V_95 . V_24 ) {
V_20 = F_50 ( V_15 , V_125 -> V_40 , & V_125 -> V_95 ) ;
if ( V_20 ) {
return V_20 ;
}
}
V_20 = F_50 ( V_15 , V_125 -> V_40 , & V_125 -> V_63 ) ;
if ( V_20 ) {
return V_20 ;
}
if ( V_125 -> V_40 == V_41 )
F_38 ( V_15 ) ;
F_51 ( & V_64 -> V_147 ) ;
V_20 = F_41 ( V_125 , V_64 ) ;
if ( V_20 ) {
goto V_148;
}
V_20 = F_20 ( V_125 ) ;
if ( V_20 ) {
if ( V_20 != - V_134 )
F_11 ( L_11 , V_20 ) ;
goto V_148;
}
if ( ( V_15 -> V_42 >= V_72 ) &&
( V_125 -> V_98 != NULL ) ) {
V_20 = F_40 ( V_15 , & V_125 -> V_63 , & V_125 -> V_95 , true ) ;
} else {
V_20 = F_40 ( V_15 , & V_125 -> V_63 , NULL , true ) ;
}
V_148:
F_52 ( & V_64 -> V_147 ) ;
return V_20 ;
}
static int F_53 ( struct V_132 * V_15 , int V_20 )
{
if ( V_20 == - V_149 ) {
V_20 = F_54 ( V_15 ) ;
if ( ! V_20 )
V_20 = - V_150 ;
}
return V_20 ;
}
static int F_55 ( struct V_132 * V_15 , struct V_11 * V_125 )
{
struct V_16 * V_151 ;
struct V_136 * V_64 = NULL ;
int V_20 ;
if ( V_125 -> V_96 == NULL )
return 0 ;
if ( V_125 -> V_60 & V_61 ) {
struct V_144 * V_145 = V_125 -> V_33 -> V_146 ;
V_64 = & V_145 -> V_64 ;
if ( ( V_15 -> V_42 >= V_72 ) &&
( V_125 -> V_98 != NULL ) ) {
V_151 = V_125 -> V_98 ;
if ( V_151 -> V_24 > V_152 ) {
F_11 ( L_15 , V_151 -> V_24 ) ;
return - V_51 ;
}
V_20 = F_56 ( V_15 , V_125 -> V_40 , & V_125 -> V_95 ,
V_64 , V_151 -> V_24 * 4 ) ;
if ( V_20 ) {
F_11 ( L_16 ) ;
return V_20 ;
}
V_125 -> V_95 . V_153 = true ;
V_125 -> V_95 . V_24 = V_151 -> V_24 ;
if ( F_24 ( V_125 -> V_95 . V_154 ,
V_151 -> V_113 ,
V_151 -> V_24 * 4 ) )
return - V_101 ;
}
V_151 = V_125 -> V_96 ;
if ( V_151 -> V_24 > V_152 ) {
F_11 ( L_17 , V_151 -> V_24 ) ;
return - V_51 ;
}
}
V_151 = V_125 -> V_96 ;
V_20 = F_56 ( V_15 , V_125 -> V_40 , & V_125 -> V_63 ,
V_64 , V_151 -> V_24 * 4 ) ;
if ( V_20 ) {
F_11 ( L_18 ) ;
return V_20 ;
}
V_125 -> V_63 . V_24 = V_151 -> V_24 ;
if ( V_151 -> V_32 )
memcpy ( V_125 -> V_63 . V_154 , V_151 -> V_32 , V_151 -> V_24 * 4 ) ;
else if ( F_24 ( V_125 -> V_63 . V_154 , V_151 -> V_113 , V_151 -> V_24 * 4 ) )
return - V_101 ;
return 0 ;
}
int F_57 ( struct V_13 * V_142 , void * V_87 , struct V_155 * V_33 )
{
struct V_132 * V_15 = V_142 -> V_156 ;
struct V_11 V_125 ;
int V_20 ;
F_16 ( & V_15 -> V_157 ) ;
if ( ! V_15 -> V_158 ) {
F_18 ( & V_15 -> V_157 ) ;
return - V_159 ;
}
if ( V_15 -> V_160 ) {
F_18 ( & V_15 -> V_157 ) ;
V_20 = F_54 ( V_15 ) ;
if ( ! V_20 )
V_20 = - V_150 ;
return V_20 ;
}
memset ( & V_125 , 0 , sizeof( struct V_11 ) ) ;
V_125 . V_33 = V_33 ;
V_125 . V_15 = V_15 ;
V_125 . V_142 = V_15 -> V_142 ;
V_125 . V_42 = V_15 -> V_42 ;
V_20 = F_23 ( & V_125 , V_87 ) ;
if ( V_20 ) {
F_11 ( L_19 ) ;
F_28 ( & V_125 , V_20 , false ) ;
F_18 ( & V_15 -> V_157 ) ;
V_20 = F_53 ( V_15 , V_20 ) ;
return V_20 ;
}
V_20 = F_55 ( V_15 , & V_125 ) ;
if ( ! V_20 ) {
V_20 = F_8 ( & V_125 ) ;
if ( V_20 && V_20 != - V_134 )
F_11 ( L_20 , V_20 ) ;
}
if ( V_20 ) {
F_28 ( & V_125 , V_20 , false ) ;
F_18 ( & V_15 -> V_157 ) ;
V_20 = F_53 ( V_15 , V_20 ) ;
return V_20 ;
}
F_58 ( & V_125 ) ;
V_20 = F_36 ( V_15 , & V_125 ) ;
if ( V_20 ) {
goto V_148;
}
V_20 = F_49 ( V_15 , & V_125 ) ;
if ( V_20 ) {
goto V_148;
}
V_148:
F_28 ( & V_125 , V_20 , true ) ;
F_18 ( & V_15 -> V_157 ) ;
V_20 = F_53 ( V_15 , V_20 ) ;
return V_20 ;
}
int F_59 ( struct V_11 * V_12 ,
struct V_161 * V_162 ,
unsigned V_93 )
{
struct V_16 * V_151 = V_12 -> V_96 ;
struct V_132 * V_15 = V_12 -> V_15 ;
T_1 V_163 ;
int V_164 = 0 , V_3 ;
if ( V_93 >= V_151 -> V_24 ) {
F_11 ( L_21 ,
V_93 , V_151 -> V_24 ) ;
return - V_51 ;
}
V_163 = F_60 ( V_12 , V_93 ) ;
V_162 -> V_93 = V_93 ;
V_162 -> type = F_61 ( V_163 ) ;
V_162 -> V_165 = F_62 ( V_163 ) ;
V_162 -> V_166 = 0 ;
switch ( V_162 -> type ) {
case V_167 :
if ( V_15 -> V_42 < V_168 ) {
V_162 -> V_169 = F_63 ( V_163 ) ;
V_162 -> V_166 =
F_64 ( V_163 ) ;
} else
V_162 -> V_169 = F_65 ( V_163 ) ;
break;
case V_170 :
V_162 -> V_171 = F_66 ( V_163 ) ;
break;
case V_172 :
V_162 -> V_165 = - 1 ;
break;
default:
F_11 ( L_22 , V_162 -> type , V_93 ) ;
V_164 = - V_51 ;
goto V_173;
}
if ( ( V_162 -> V_165 + 1 + V_162 -> V_93 ) >= V_151 -> V_24 ) {
F_11 ( L_23 ,
V_162 -> V_93 , V_162 -> type , V_162 -> V_165 , V_151 -> V_24 ) ;
V_164 = - V_51 ;
goto V_173;
}
return 0 ;
V_173:
for ( V_3 = 0 ; V_3 < V_151 -> V_24 ; V_3 ++ ) {
if ( V_3 == V_93 )
F_67 ( L_24 , F_60 ( V_12 , V_3 ) ) ;
else
F_67 ( L_25 , F_60 ( V_12 , V_3 ) ) ;
}
return V_164 ;
}
bool F_68 ( struct V_11 * V_12 )
{
struct V_161 V_174 ;
int V_20 ;
V_20 = F_59 ( V_12 , & V_174 , V_12 -> V_93 ) ;
if ( V_20 )
return false ;
if ( V_174 . type != V_170 )
return false ;
if ( V_174 . V_171 != V_175 )
return false ;
return true ;
}
void F_69 ( struct V_11 * V_12 ,
struct V_161 * V_162 )
{
volatile T_1 * V_63 ;
unsigned V_3 ;
unsigned V_93 ;
V_63 = V_12 -> V_63 . V_154 ;
V_93 = V_162 -> V_93 ;
for ( V_3 = 0 ; V_3 <= ( V_162 -> V_165 + 1 ) ; V_3 ++ , V_93 ++ )
F_70 ( L_26 , V_93 , V_63 [ V_93 ] ) ;
}
int F_71 ( struct V_11 * V_12 ,
struct V_26 * * V_176 ,
int V_177 )
{
struct V_16 * V_178 ;
struct V_161 V_174 ;
unsigned V_93 ;
int V_20 ;
if ( V_12 -> V_21 == NULL ) {
F_11 ( L_27 ) ;
return - V_51 ;
}
* V_176 = NULL ;
V_178 = V_12 -> V_21 ;
V_20 = F_59 ( V_12 , & V_174 , V_12 -> V_93 ) ;
if ( V_20 )
return V_20 ;
V_12 -> V_93 += V_174 . V_165 + 2 ;
if ( V_174 . type != V_170 ||
V_174 . V_171 != V_175 ) {
F_11 ( L_28 ,
V_174 . V_93 ) ;
F_69 ( V_12 , & V_174 ) ;
return - V_51 ;
}
V_93 = F_60 ( V_12 , V_174 . V_93 + 1 ) ;
if ( V_93 >= V_178 -> V_24 ) {
F_11 ( L_29 ,
V_93 , V_178 -> V_24 ) ;
F_69 ( V_12 , & V_174 ) ;
return - V_51 ;
}
if ( V_177 ) {
* V_176 = V_12 -> V_25 ;
( * V_176 ) -> V_179 =
( V_180 ) V_178 -> V_32 [ V_93 + 3 ] << 32 ;
( * V_176 ) -> V_179 |= V_178 -> V_32 [ V_93 + 0 ] ;
} else
* V_176 = & V_12 -> V_25 [ ( V_93 / 4 ) ] ;
return 0 ;
}

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
unsigned V_3 , V_19 ;
bool V_20 ;
if ( V_12 -> V_21 == - 1 ) {
return 0 ;
}
V_17 = & V_12 -> V_22 [ V_12 -> V_21 ] ;
V_12 -> V_23 = 0 ;
V_12 -> V_24 = V_17 -> V_25 / 4 ;
V_12 -> V_26 = F_9 ( V_12 -> V_24 , sizeof( void * ) , V_27 ) ;
if ( V_12 -> V_26 == NULL ) {
return - V_28 ;
}
V_12 -> V_29 = F_9 ( V_12 -> V_24 , sizeof( struct V_30 ) , V_27 ) ;
if ( V_12 -> V_29 == NULL ) {
return - V_28 ;
}
F_1 ( & V_18 ) ;
for ( V_3 = 0 ; V_3 < V_12 -> V_24 ; V_3 ++ ) {
struct V_31 * V_32 ;
unsigned V_8 ;
V_20 = false ;
V_32 = (struct V_31 * ) & V_17 -> V_33 [ V_3 * 4 ] ;
for ( V_19 = 0 ; V_19 < V_3 ; V_19 ++ ) {
if ( V_32 -> V_34 == V_12 -> V_29 [ V_19 ] . V_34 ) {
V_12 -> V_26 [ V_3 ] = & V_12 -> V_29 [ V_19 ] ;
V_20 = true ;
break;
}
}
if ( V_20 ) {
V_12 -> V_29 [ V_3 ] . V_34 = 0 ;
continue;
}
V_12 -> V_29 [ V_3 ] . V_35 = F_10 ( V_14 , V_12 -> V_36 ,
V_32 -> V_34 ) ;
if ( V_12 -> V_29 [ V_3 ] . V_35 == NULL ) {
F_11 ( L_1 ,
V_32 -> V_34 ) ;
return - V_37 ;
}
V_12 -> V_26 [ V_3 ] = & V_12 -> V_29 [ V_3 ] ;
V_12 -> V_29 [ V_3 ] . V_38 = F_12 ( V_12 -> V_29 [ V_3 ] . V_35 ) ;
V_8 = ( V_32 -> V_39 & V_40 ) * 2
+ ! ! V_32 -> V_41 ;
if ( V_12 -> V_42 == V_43 &&
( V_3 == 0 || F_13 ( V_12 -> V_15 -> V_14 ) ) ) {
V_12 -> V_29 [ V_3 ] . V_44 =
V_45 ;
V_12 -> V_29 [ V_3 ] . V_46 =
V_45 ;
V_8 = V_9 ;
} else {
T_1 V_47 = V_32 -> V_41 ?
V_32 -> V_41 : V_32 -> V_48 ;
if ( V_47 & V_49 ) {
F_11 ( L_2
L_3 ) ;
return - V_50 ;
}
V_12 -> V_29 [ V_3 ] . V_44 = V_47 ;
if ( V_47 == V_45 )
V_47 |= V_51 ;
V_12 -> V_29 [ V_3 ] . V_46 = V_47 ;
}
V_12 -> V_29 [ V_3 ] . V_52 . V_53 = & V_12 -> V_29 [ V_3 ] . V_38 -> V_54 ;
V_12 -> V_29 [ V_3 ] . V_34 = V_32 -> V_34 ;
F_3 ( & V_18 , & V_12 -> V_29 [ V_3 ] . V_52 . V_55 ,
V_8 ) ;
}
F_6 ( & V_18 , & V_12 -> V_56 ) ;
if ( V_12 -> V_57 & V_58 )
V_12 -> V_59 = F_14 ( V_12 -> V_15 , V_12 -> V_60 . V_61 ,
& V_12 -> V_56 ) ;
return F_15 ( V_12 -> V_15 , & V_12 -> V_62 , & V_12 -> V_56 , V_12 -> V_42 ) ;
}
static int F_16 ( struct V_11 * V_12 , T_2 V_42 , T_3 V_8 )
{
V_12 -> V_8 = V_8 ;
switch ( V_42 ) {
default:
F_11 ( L_4 , V_42 ) ;
return - V_50 ;
case V_63 :
V_12 -> V_42 = V_64 ;
break;
case V_65 :
if ( V_12 -> V_15 -> V_66 >= V_67 ) {
if ( V_12 -> V_8 > 0 )
V_12 -> V_42 = V_68 ;
else
V_12 -> V_42 = V_69 ;
} else
V_12 -> V_42 = V_64 ;
break;
case V_70 :
if ( V_12 -> V_15 -> V_66 >= V_71 ) {
if ( V_12 -> V_8 > 0 )
V_12 -> V_42 = V_72 ;
else
V_12 -> V_42 = V_73 ;
} else if ( V_12 -> V_15 -> V_66 >= V_74 ) {
V_12 -> V_42 = V_72 ;
} else {
return - V_50 ;
}
break;
case V_75 :
V_12 -> V_42 = V_43 ;
break;
case V_76 :
V_12 -> V_42 = V_77 ;
break;
}
return 0 ;
}
static void F_17 ( struct V_11 * V_12 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_12 -> V_24 ; V_3 ++ ) {
if ( ! V_12 -> V_29 [ V_3 ] . V_38 )
continue;
F_18 ( V_12 -> V_60 . V_78 ,
V_12 -> V_29 [ V_3 ] . V_38 -> V_54 . V_79 ) ;
}
}
int F_19 ( struct V_11 * V_12 , void * V_80 )
{
struct V_81 * V_82 = V_80 ;
T_4 * V_83 ;
unsigned V_84 , V_3 ;
T_2 V_42 = V_63 ;
T_3 V_8 = 0 ;
if ( ! V_82 -> V_85 ) {
return 0 ;
}
F_2 ( & V_12 -> V_56 ) ;
V_12 -> V_86 = 0 ;
V_12 -> V_60 . V_87 = NULL ;
V_12 -> V_60 . V_78 = NULL ;
V_12 -> V_88 . V_87 = NULL ;
V_12 -> V_88 . V_78 = NULL ;
V_12 -> V_89 = - 1 ;
V_12 -> V_21 = - 1 ;
V_12 -> V_90 = - 1 ;
V_12 -> V_91 = - 1 ;
V_12 -> V_92 = F_9 ( V_82 -> V_85 , sizeof( T_4 ) , V_27 ) ;
if ( V_12 -> V_92 == NULL ) {
return - V_28 ;
}
V_83 = ( T_4 * ) ( unsigned long ) ( V_82 -> V_22 ) ;
if ( F_20 ( V_12 -> V_92 , V_83 ,
sizeof( T_4 ) * V_82 -> V_85 ) ) {
return - V_93 ;
}
V_12 -> V_57 = 0 ;
V_12 -> V_94 = V_82 -> V_85 ;
V_12 -> V_22 = F_9 ( V_12 -> V_94 , sizeof( struct V_16 ) , V_27 ) ;
if ( V_12 -> V_22 == NULL ) {
return - V_28 ;
}
for ( V_3 = 0 ; V_3 < V_12 -> V_94 ; V_3 ++ ) {
struct V_95 T_5 * * V_96 = NULL ;
struct V_95 V_97 ;
T_1 T_5 * V_98 ;
V_96 = ( void T_5 * ) ( unsigned long ) V_12 -> V_92 [ V_3 ] ;
if ( F_20 ( & V_97 , V_96 ,
sizeof( struct V_95 ) ) ) {
return - V_93 ;
}
V_12 -> V_22 [ V_3 ] . V_25 = V_97 . V_25 ;
V_12 -> V_22 [ V_3 ] . V_99 = V_97 . V_99 ;
if ( V_12 -> V_22 [ V_3 ] . V_99 == V_100 ) {
V_12 -> V_21 = V_3 ;
}
if ( V_12 -> V_22 [ V_3 ] . V_99 == V_101 ) {
V_12 -> V_89 = V_3 ;
if ( V_12 -> V_22 [ V_3 ] . V_25 == 0 )
return - V_50 ;
}
if ( V_12 -> V_22 [ V_3 ] . V_99 == V_102 ) {
V_12 -> V_91 = V_3 ;
if ( V_12 -> V_22 [ V_3 ] . V_25 == 0 )
return - V_50 ;
}
if ( V_12 -> V_22 [ V_3 ] . V_99 == V_103 ) {
V_12 -> V_90 = V_3 ;
if ( V_12 -> V_22 [ V_3 ] . V_25 == 0 )
return - V_50 ;
}
V_84 = V_12 -> V_22 [ V_3 ] . V_25 ;
V_98 = ( void T_5 * ) ( unsigned long ) V_97 . V_104 ;
V_12 -> V_22 [ V_3 ] . V_105 = V_98 ;
if ( V_12 -> V_22 [ V_3 ] . V_99 == V_102 )
continue;
if ( V_12 -> V_22 [ V_3 ] . V_99 == V_101 ) {
if ( ! V_12 -> V_15 || ! ( V_12 -> V_15 -> V_39 & V_106 ) )
continue;
}
V_12 -> V_22 [ V_3 ] . V_33 = F_21 ( V_84 , sizeof( T_1 ) ) ;
V_84 *= sizeof( T_1 ) ;
if ( V_12 -> V_22 [ V_3 ] . V_33 == NULL ) {
return - V_28 ;
}
if ( F_20 ( V_12 -> V_22 [ V_3 ] . V_33 , V_98 , V_84 ) ) {
return - V_93 ;
}
if ( V_12 -> V_22 [ V_3 ] . V_99 == V_103 ) {
V_12 -> V_57 = V_12 -> V_22 [ V_3 ] . V_33 [ 0 ] ;
if ( V_12 -> V_22 [ V_3 ] . V_25 > 1 )
V_42 = V_12 -> V_22 [ V_3 ] . V_33 [ 1 ] ;
if ( V_12 -> V_22 [ V_3 ] . V_25 > 2 )
V_8 = ( T_3 ) V_12 -> V_22 [ V_3 ] . V_33 [ 2 ] ;
}
}
if ( V_12 -> V_15 ) {
if ( ( V_12 -> V_57 & V_58 ) &&
! V_12 -> V_15 -> V_107 . V_108 ) {
F_11 ( L_5 ) ;
return - V_50 ;
}
if ( F_16 ( V_12 , V_42 , V_8 ) )
return - V_50 ;
if ( ( V_12 -> V_57 & V_58 ) == 0 ) {
if ( V_12 -> V_15 -> V_109 -> V_42 [ V_12 -> V_42 ] -> V_110 == NULL ) {
F_11 ( L_6 , V_12 -> V_42 ) ;
return - V_50 ;
}
} else {
if ( V_12 -> V_15 -> V_109 -> V_42 [ V_12 -> V_42 ] -> V_111 == NULL ) {
F_11 ( L_7 ,
V_12 -> V_42 ) ;
return - V_50 ;
}
}
}
return 0 ;
}
static int F_22 ( void * V_112 , struct V_6 * V_113 ,
struct V_6 * V_2 )
{
struct V_30 * V_114 = F_23 ( V_113 , struct V_30 , V_52 . V_55 ) ;
struct V_30 * V_115 = F_23 ( V_2 , struct V_30 , V_52 . V_55 ) ;
return ( int ) V_114 -> V_38 -> V_54 . V_116 - ( int ) V_115 -> V_38 -> V_54 . V_116 ;
}
static void F_24 ( struct V_11 * V_117 , int error , bool V_118 )
{
unsigned V_3 ;
if ( ! error ) {
F_25 ( NULL , & V_117 -> V_56 , F_22 ) ;
F_26 ( & V_117 -> V_62 ,
& V_117 -> V_56 ,
V_117 -> V_60 . V_119 ) ;
} else if ( V_118 ) {
F_27 ( & V_117 -> V_62 ,
& V_117 -> V_56 ) ;
}
if ( V_117 -> V_29 != NULL ) {
for ( V_3 = 0 ; V_3 < V_117 -> V_24 ; V_3 ++ ) {
if ( V_117 -> V_29 [ V_3 ] . V_35 )
F_28 ( V_117 -> V_29 [ V_3 ] . V_35 ) ;
}
}
F_29 ( V_117 -> V_120 ) ;
F_29 ( V_117 -> V_29 ) ;
F_29 ( V_117 -> V_26 ) ;
F_29 ( V_117 -> V_59 ) ;
for ( V_3 = 0 ; V_3 < V_117 -> V_94 ; V_3 ++ )
F_30 ( V_117 -> V_22 [ V_3 ] . V_33 ) ;
F_29 ( V_117 -> V_22 ) ;
F_29 ( V_117 -> V_92 ) ;
F_31 ( V_117 -> V_15 , & V_117 -> V_60 ) ;
F_31 ( V_117 -> V_15 , & V_117 -> V_88 ) ;
}
static int F_32 ( struct V_121 * V_15 ,
struct V_11 * V_117 )
{
int V_32 ;
if ( V_117 -> V_89 == - 1 )
return 0 ;
if ( V_117 -> V_57 & V_58 )
return 0 ;
V_32 = F_33 ( V_15 , V_117 -> V_42 , V_117 ) ;
if ( V_32 || V_117 -> V_122 ) {
F_11 ( L_8 ) ;
return V_32 ;
}
if ( V_117 -> V_42 == V_43 )
F_34 ( V_15 ) ;
else if ( ( V_117 -> V_42 == V_77 ) ||
( V_117 -> V_42 == V_123 ) )
F_35 ( V_15 ) ;
F_17 ( V_117 ) ;
V_32 = F_36 ( V_15 , & V_117 -> V_60 , NULL , true ) ;
if ( V_32 ) {
F_11 ( L_9 ) ;
}
return V_32 ;
}
static int F_37 ( struct V_11 * V_12 ,
struct V_124 * V_61 )
{
struct V_121 * V_15 = V_12 -> V_15 ;
struct V_125 * V_126 ;
int V_3 , V_32 ;
V_32 = F_38 ( V_15 , V_61 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_39 ( V_15 , V_61 ) ;
if ( V_32 )
return V_32 ;
if ( V_61 -> V_127 == NULL ) {
F_11 ( L_10 ) ;
return - V_50 ;
}
V_32 = F_40 ( V_15 , V_61 -> V_127 ,
& V_15 -> V_128 . V_53 -> V_54 . V_129 ) ;
if ( V_32 )
return V_32 ;
for ( V_3 = 0 ; V_3 < V_12 -> V_24 ; V_3 ++ ) {
struct V_130 * V_53 ;
if ( V_12 -> V_26 [ V_3 ] != & V_12 -> V_29 [ V_3 ] )
continue;
V_53 = V_12 -> V_29 [ V_3 ] . V_38 ;
V_126 = F_41 ( V_61 , V_53 ) ;
if ( V_126 == NULL ) {
F_42 ( V_15 -> V_131 , L_11 , V_53 , V_61 ) ;
return - V_50 ;
}
V_32 = F_40 ( V_15 , V_126 , & V_53 -> V_54 . V_129 ) ;
if ( V_32 )
return V_32 ;
}
return F_43 ( V_15 , V_61 ) ;
}
static int F_44 ( struct V_121 * V_15 ,
struct V_11 * V_117 )
{
struct V_132 * V_133 = V_117 -> V_36 -> V_134 ;
struct V_124 * V_61 = & V_133 -> V_61 ;
int V_32 ;
if ( V_117 -> V_89 == - 1 )
return 0 ;
if ( ( V_117 -> V_57 & V_58 ) == 0 )
return 0 ;
if ( V_117 -> V_88 . V_25 ) {
V_32 = F_45 ( V_15 , V_117 -> V_42 , & V_117 -> V_88 ) ;
if ( V_32 ) {
return V_32 ;
}
}
V_32 = F_45 ( V_15 , V_117 -> V_42 , & V_117 -> V_60 ) ;
if ( V_32 ) {
return V_32 ;
}
if ( V_117 -> V_42 == V_43 )
F_34 ( V_15 ) ;
F_46 ( & V_61 -> V_135 ) ;
V_32 = F_37 ( V_117 , V_61 ) ;
if ( V_32 ) {
goto V_136;
}
F_17 ( V_117 ) ;
F_18 ( V_117 -> V_60 . V_78 , V_61 -> V_119 ) ;
if ( ( V_15 -> V_66 >= V_67 ) &&
( V_117 -> V_91 != - 1 ) ) {
V_32 = F_36 ( V_15 , & V_117 -> V_60 , & V_117 -> V_88 , true ) ;
} else {
V_32 = F_36 ( V_15 , & V_117 -> V_60 , NULL , true ) ;
}
V_136:
F_47 ( & V_61 -> V_135 ) ;
return V_32 ;
}
static int F_48 ( struct V_121 * V_15 , int V_32 )
{
if ( V_32 == - V_137 ) {
V_32 = F_49 ( V_15 ) ;
if ( ! V_32 )
V_32 = - V_138 ;
}
return V_32 ;
}
static int F_50 ( struct V_121 * V_15 , struct V_11 * V_117 )
{
struct V_16 * V_139 ;
struct V_124 * V_61 = NULL ;
int V_32 ;
if ( V_117 -> V_89 == - 1 )
return 0 ;
if ( V_117 -> V_57 & V_58 ) {
struct V_132 * V_133 = V_117 -> V_36 -> V_134 ;
V_61 = & V_133 -> V_61 ;
if ( ( V_15 -> V_66 >= V_67 ) &&
( V_117 -> V_91 != - 1 ) ) {
V_139 = & V_117 -> V_22 [ V_117 -> V_91 ] ;
if ( V_139 -> V_25 > V_140 ) {
F_11 ( L_12 , V_139 -> V_25 ) ;
return - V_50 ;
}
V_32 = F_51 ( V_15 , V_117 -> V_42 , & V_117 -> V_88 ,
V_61 , V_139 -> V_25 * 4 ) ;
if ( V_32 ) {
F_11 ( L_13 ) ;
return V_32 ;
}
V_117 -> V_88 . V_141 = true ;
V_117 -> V_88 . V_25 = V_139 -> V_25 ;
if ( F_20 ( V_117 -> V_88 . V_142 ,
V_139 -> V_105 ,
V_139 -> V_25 * 4 ) )
return - V_93 ;
}
V_139 = & V_117 -> V_22 [ V_117 -> V_89 ] ;
if ( V_139 -> V_25 > V_140 ) {
F_11 ( L_14 , V_139 -> V_25 ) ;
return - V_50 ;
}
}
V_139 = & V_117 -> V_22 [ V_117 -> V_89 ] ;
V_32 = F_51 ( V_15 , V_117 -> V_42 , & V_117 -> V_60 ,
V_61 , V_139 -> V_25 * 4 ) ;
if ( V_32 ) {
F_11 ( L_15 ) ;
return V_32 ;
}
V_117 -> V_60 . V_25 = V_139 -> V_25 ;
if ( V_139 -> V_33 )
memcpy ( V_117 -> V_60 . V_142 , V_139 -> V_33 , V_139 -> V_25 * 4 ) ;
else if ( F_20 ( V_117 -> V_60 . V_142 , V_139 -> V_105 , V_139 -> V_25 * 4 ) )
return - V_93 ;
return 0 ;
}
int F_52 ( struct V_13 * V_131 , void * V_80 , struct V_143 * V_36 )
{
struct V_121 * V_15 = V_131 -> V_144 ;
struct V_11 V_117 ;
int V_32 ;
F_53 ( & V_15 -> V_145 ) ;
if ( ! V_15 -> V_146 ) {
F_54 ( & V_15 -> V_145 ) ;
return - V_147 ;
}
memset ( & V_117 , 0 , sizeof( struct V_11 ) ) ;
V_117 . V_36 = V_36 ;
V_117 . V_15 = V_15 ;
V_117 . V_131 = V_15 -> V_131 ;
V_117 . V_66 = V_15 -> V_66 ;
V_32 = F_19 ( & V_117 , V_80 ) ;
if ( V_32 ) {
F_11 ( L_16 ) ;
F_24 ( & V_117 , V_32 , false ) ;
F_54 ( & V_15 -> V_145 ) ;
V_32 = F_48 ( V_15 , V_32 ) ;
return V_32 ;
}
V_32 = F_50 ( V_15 , & V_117 ) ;
if ( ! V_32 ) {
V_32 = F_8 ( & V_117 ) ;
if ( V_32 && V_32 != - V_148 )
F_11 ( L_17 , V_32 ) ;
}
if ( V_32 ) {
F_24 ( & V_117 , V_32 , false ) ;
F_54 ( & V_15 -> V_145 ) ;
V_32 = F_48 ( V_15 , V_32 ) ;
return V_32 ;
}
F_55 ( & V_117 ) ;
V_32 = F_32 ( V_15 , & V_117 ) ;
if ( V_32 ) {
goto V_136;
}
V_32 = F_44 ( V_15 , & V_117 ) ;
if ( V_32 ) {
goto V_136;
}
V_136:
F_24 ( & V_117 , V_32 , true ) ;
F_54 ( & V_15 -> V_145 ) ;
V_32 = F_48 ( V_15 , V_32 ) ;
return V_32 ;
}
int F_56 ( struct V_11 * V_12 ,
struct V_149 * V_150 ,
unsigned V_86 )
{
struct V_16 * V_139 = & V_12 -> V_22 [ V_12 -> V_89 ] ;
struct V_121 * V_15 = V_12 -> V_15 ;
T_1 V_151 ;
if ( V_86 >= V_139 -> V_25 ) {
F_11 ( L_18 ,
V_86 , V_139 -> V_25 ) ;
return - V_50 ;
}
V_151 = F_57 ( V_12 , V_86 ) ;
V_150 -> V_86 = V_86 ;
V_150 -> type = F_58 ( V_151 ) ;
V_150 -> V_152 = F_59 ( V_151 ) ;
V_150 -> V_153 = 0 ;
switch ( V_150 -> type ) {
case V_154 :
if ( V_15 -> V_66 < V_155 ) {
V_150 -> V_156 = F_60 ( V_151 ) ;
V_150 -> V_153 =
F_61 ( V_151 ) ;
} else
V_150 -> V_156 = F_62 ( V_151 ) ;
break;
case V_157 :
V_150 -> V_158 = F_63 ( V_151 ) ;
break;
case V_159 :
V_150 -> V_152 = - 1 ;
break;
default:
F_11 ( L_19 , V_150 -> type , V_86 ) ;
return - V_50 ;
}
if ( ( V_150 -> V_152 + 1 + V_150 -> V_86 ) >= V_139 -> V_25 ) {
F_11 ( L_20 ,
V_150 -> V_86 , V_150 -> type , V_150 -> V_152 , V_139 -> V_25 ) ;
return - V_50 ;
}
return 0 ;
}
bool F_64 ( struct V_11 * V_12 )
{
struct V_149 V_160 ;
int V_32 ;
V_32 = F_56 ( V_12 , & V_160 , V_12 -> V_86 ) ;
if ( V_32 )
return false ;
if ( V_160 . type != V_157 )
return false ;
if ( V_160 . V_158 != V_161 )
return false ;
return true ;
}
void F_65 ( struct V_11 * V_12 ,
struct V_149 * V_150 )
{
volatile T_1 * V_60 ;
unsigned V_3 ;
unsigned V_86 ;
V_60 = V_12 -> V_60 . V_142 ;
V_86 = V_150 -> V_86 ;
for ( V_3 = 0 ; V_3 <= ( V_150 -> V_152 + 1 ) ; V_3 ++ , V_86 ++ )
F_66 ( L_21 , V_86 , V_60 [ V_86 ] ) ;
}
int F_67 ( struct V_11 * V_12 ,
struct V_30 * * V_162 ,
int V_163 )
{
struct V_16 * V_164 ;
struct V_149 V_160 ;
unsigned V_86 ;
int V_32 ;
if ( V_12 -> V_21 == - 1 ) {
F_11 ( L_22 ) ;
return - V_50 ;
}
* V_162 = NULL ;
V_164 = & V_12 -> V_22 [ V_12 -> V_21 ] ;
V_32 = F_56 ( V_12 , & V_160 , V_12 -> V_86 ) ;
if ( V_32 )
return V_32 ;
V_12 -> V_86 += V_160 . V_152 + 2 ;
if ( V_160 . type != V_157 ||
V_160 . V_158 != V_161 ) {
F_11 ( L_23 ,
V_160 . V_86 ) ;
F_65 ( V_12 , & V_160 ) ;
return - V_50 ;
}
V_86 = F_57 ( V_12 , V_160 . V_86 + 1 ) ;
if ( V_86 >= V_164 -> V_25 ) {
F_11 ( L_24 ,
V_86 , V_164 -> V_25 ) ;
F_65 ( V_12 , & V_160 ) ;
return - V_50 ;
}
if ( V_163 ) {
* V_162 = V_12 -> V_29 ;
( * V_162 ) -> V_165 =
( V_166 ) V_164 -> V_33 [ V_86 + 3 ] << 32 ;
( * V_162 ) -> V_165 |= V_164 -> V_33 [ V_86 + 0 ] ;
} else
* V_162 = V_12 -> V_26 [ ( V_86 / 4 ) ] ;
return 0 ;
}

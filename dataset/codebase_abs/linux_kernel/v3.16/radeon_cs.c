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
V_8 = ( V_32 -> V_39 & 0xf ) * 2 + ! ! V_32 -> V_40 ;
if ( V_12 -> V_41 == V_42 &&
( V_3 == 0 || F_13 ( V_12 -> V_15 -> V_14 ) ) ) {
V_12 -> V_29 [ V_3 ] . V_43 =
V_44 ;
V_12 -> V_29 [ V_3 ] . V_45 =
V_44 ;
V_8 = V_9 ;
} else {
T_1 V_46 = V_32 -> V_40 ?
V_32 -> V_40 : V_32 -> V_47 ;
if ( V_46 & V_48 ) {
F_11 ( L_2
L_3 ) ;
return - V_49 ;
}
V_12 -> V_29 [ V_3 ] . V_43 = V_46 ;
if ( V_46 == V_44 )
V_46 |= V_50 ;
V_12 -> V_29 [ V_3 ] . V_45 = V_46 ;
}
V_12 -> V_29 [ V_3 ] . V_51 . V_52 = & V_12 -> V_29 [ V_3 ] . V_38 -> V_53 ;
V_12 -> V_29 [ V_3 ] . V_34 = V_32 -> V_34 ;
F_3 ( & V_18 , & V_12 -> V_29 [ V_3 ] . V_51 . V_54 ,
V_8 ) ;
}
F_6 ( & V_18 , & V_12 -> V_55 ) ;
if ( V_12 -> V_56 & V_57 )
V_12 -> V_58 = F_14 ( V_12 -> V_15 , V_12 -> V_59 . V_60 ,
& V_12 -> V_55 ) ;
return F_15 ( V_12 -> V_15 , & V_12 -> V_61 , & V_12 -> V_55 , V_12 -> V_41 ) ;
}
static int F_16 ( struct V_11 * V_12 , T_2 V_41 , T_3 V_8 )
{
V_12 -> V_8 = V_8 ;
switch ( V_41 ) {
default:
F_11 ( L_4 , V_41 ) ;
return - V_49 ;
case V_62 :
V_12 -> V_41 = V_63 ;
break;
case V_64 :
if ( V_12 -> V_15 -> V_65 >= V_66 ) {
if ( V_12 -> V_8 > 0 )
V_12 -> V_41 = V_67 ;
else
V_12 -> V_41 = V_68 ;
} else
V_12 -> V_41 = V_63 ;
break;
case V_69 :
if ( V_12 -> V_15 -> V_65 >= V_70 ) {
if ( V_12 -> V_8 > 0 )
V_12 -> V_41 = V_71 ;
else
V_12 -> V_41 = V_72 ;
} else if ( V_12 -> V_15 -> V_65 >= V_73 ) {
V_12 -> V_41 = V_71 ;
} else {
return - V_49 ;
}
break;
case V_74 :
V_12 -> V_41 = V_42 ;
break;
case V_75 :
V_12 -> V_41 = V_76 ;
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
F_18 ( V_12 -> V_59 . V_77 ,
V_12 -> V_29 [ V_3 ] . V_38 -> V_53 . V_78 ) ;
}
}
int F_19 ( struct V_11 * V_12 , void * V_79 )
{
struct V_80 * V_81 = V_79 ;
T_4 * V_82 ;
unsigned V_83 , V_3 ;
T_2 V_41 = V_62 ;
T_3 V_8 = 0 ;
if ( ! V_81 -> V_84 ) {
return 0 ;
}
F_2 ( & V_12 -> V_55 ) ;
V_12 -> V_85 = 0 ;
V_12 -> V_59 . V_86 = NULL ;
V_12 -> V_59 . V_77 = NULL ;
V_12 -> V_87 . V_86 = NULL ;
V_12 -> V_87 . V_77 = NULL ;
V_12 -> V_88 = - 1 ;
V_12 -> V_21 = - 1 ;
V_12 -> V_89 = - 1 ;
V_12 -> V_90 = - 1 ;
V_12 -> V_91 = F_9 ( V_81 -> V_84 , sizeof( T_4 ) , V_27 ) ;
if ( V_12 -> V_91 == NULL ) {
return - V_28 ;
}
V_82 = ( T_4 * ) ( unsigned long ) ( V_81 -> V_22 ) ;
if ( F_20 ( V_12 -> V_91 , V_82 ,
sizeof( T_4 ) * V_81 -> V_84 ) ) {
return - V_92 ;
}
V_12 -> V_56 = 0 ;
V_12 -> V_93 = V_81 -> V_84 ;
V_12 -> V_22 = F_9 ( V_12 -> V_93 , sizeof( struct V_16 ) , V_27 ) ;
if ( V_12 -> V_22 == NULL ) {
return - V_28 ;
}
for ( V_3 = 0 ; V_3 < V_12 -> V_93 ; V_3 ++ ) {
struct V_94 T_5 * * V_95 = NULL ;
struct V_94 V_96 ;
T_1 T_5 * V_97 ;
V_95 = ( void T_5 * ) ( unsigned long ) V_12 -> V_91 [ V_3 ] ;
if ( F_20 ( & V_96 , V_95 ,
sizeof( struct V_94 ) ) ) {
return - V_92 ;
}
V_12 -> V_22 [ V_3 ] . V_25 = V_96 . V_25 ;
V_12 -> V_22 [ V_3 ] . V_98 = V_96 . V_98 ;
if ( V_12 -> V_22 [ V_3 ] . V_98 == V_99 ) {
V_12 -> V_21 = V_3 ;
}
if ( V_12 -> V_22 [ V_3 ] . V_98 == V_100 ) {
V_12 -> V_88 = V_3 ;
if ( V_12 -> V_22 [ V_3 ] . V_25 == 0 )
return - V_49 ;
}
if ( V_12 -> V_22 [ V_3 ] . V_98 == V_101 ) {
V_12 -> V_90 = V_3 ;
if ( V_12 -> V_22 [ V_3 ] . V_25 == 0 )
return - V_49 ;
}
if ( V_12 -> V_22 [ V_3 ] . V_98 == V_102 ) {
V_12 -> V_89 = V_3 ;
if ( V_12 -> V_22 [ V_3 ] . V_25 == 0 )
return - V_49 ;
}
V_83 = V_12 -> V_22 [ V_3 ] . V_25 ;
V_97 = ( void T_5 * ) ( unsigned long ) V_96 . V_103 ;
V_12 -> V_22 [ V_3 ] . V_104 = V_97 ;
if ( V_12 -> V_22 [ V_3 ] . V_98 == V_101 )
continue;
if ( V_12 -> V_22 [ V_3 ] . V_98 == V_100 ) {
if ( ! V_12 -> V_15 || ! ( V_12 -> V_15 -> V_39 & V_105 ) )
continue;
}
V_12 -> V_22 [ V_3 ] . V_33 = F_21 ( V_83 , sizeof( T_1 ) ) ;
V_83 *= sizeof( T_1 ) ;
if ( V_12 -> V_22 [ V_3 ] . V_33 == NULL ) {
return - V_28 ;
}
if ( F_20 ( V_12 -> V_22 [ V_3 ] . V_33 , V_97 , V_83 ) ) {
return - V_92 ;
}
if ( V_12 -> V_22 [ V_3 ] . V_98 == V_102 ) {
V_12 -> V_56 = V_12 -> V_22 [ V_3 ] . V_33 [ 0 ] ;
if ( V_12 -> V_22 [ V_3 ] . V_25 > 1 )
V_41 = V_12 -> V_22 [ V_3 ] . V_33 [ 1 ] ;
if ( V_12 -> V_22 [ V_3 ] . V_25 > 2 )
V_8 = ( T_3 ) V_12 -> V_22 [ V_3 ] . V_33 [ 2 ] ;
}
}
if ( V_12 -> V_15 ) {
if ( ( V_12 -> V_56 & V_57 ) &&
! V_12 -> V_15 -> V_106 . V_107 ) {
F_11 ( L_5 ) ;
return - V_49 ;
}
if ( F_16 ( V_12 , V_41 , V_8 ) )
return - V_49 ;
if ( ( V_12 -> V_56 & V_57 ) == 0 ) {
if ( V_12 -> V_15 -> V_108 -> V_41 [ V_12 -> V_41 ] -> V_109 == NULL ) {
F_11 ( L_6 , V_12 -> V_41 ) ;
return - V_49 ;
}
} else {
if ( V_12 -> V_15 -> V_108 -> V_41 [ V_12 -> V_41 ] -> V_110 == NULL ) {
F_11 ( L_7 ,
V_12 -> V_41 ) ;
return - V_49 ;
}
}
}
return 0 ;
}
static int F_22 ( void * V_111 , struct V_6 * V_112 ,
struct V_6 * V_2 )
{
struct V_30 * V_113 = F_23 ( V_112 , struct V_30 , V_51 . V_54 ) ;
struct V_30 * V_114 = F_23 ( V_2 , struct V_30 , V_51 . V_54 ) ;
return ( int ) V_113 -> V_38 -> V_53 . V_115 - ( int ) V_114 -> V_38 -> V_53 . V_115 ;
}
static void F_24 ( struct V_11 * V_116 , int error , bool V_117 )
{
unsigned V_3 ;
if ( ! error ) {
F_25 ( NULL , & V_116 -> V_55 , F_22 ) ;
F_26 ( & V_116 -> V_61 ,
& V_116 -> V_55 ,
V_116 -> V_59 . V_118 ) ;
} else if ( V_117 ) {
F_27 ( & V_116 -> V_61 ,
& V_116 -> V_55 ) ;
}
if ( V_116 -> V_29 != NULL ) {
for ( V_3 = 0 ; V_3 < V_116 -> V_24 ; V_3 ++ ) {
if ( V_116 -> V_29 [ V_3 ] . V_35 )
F_28 ( V_116 -> V_29 [ V_3 ] . V_35 ) ;
}
}
F_29 ( V_116 -> V_119 ) ;
F_29 ( V_116 -> V_29 ) ;
F_29 ( V_116 -> V_26 ) ;
F_29 ( V_116 -> V_58 ) ;
for ( V_3 = 0 ; V_3 < V_116 -> V_93 ; V_3 ++ )
F_30 ( V_116 -> V_22 [ V_3 ] . V_33 ) ;
F_29 ( V_116 -> V_22 ) ;
F_29 ( V_116 -> V_91 ) ;
F_31 ( V_116 -> V_15 , & V_116 -> V_59 ) ;
F_31 ( V_116 -> V_15 , & V_116 -> V_87 ) ;
}
static int F_32 ( struct V_120 * V_15 ,
struct V_11 * V_116 )
{
int V_32 ;
if ( V_116 -> V_88 == - 1 )
return 0 ;
if ( V_116 -> V_56 & V_57 )
return 0 ;
V_32 = F_33 ( V_15 , V_116 -> V_41 , V_116 ) ;
if ( V_32 || V_116 -> V_121 ) {
F_11 ( L_8 ) ;
return V_32 ;
}
if ( V_116 -> V_41 == V_42 )
F_34 ( V_15 ) ;
else if ( ( V_116 -> V_41 == V_76 ) ||
( V_116 -> V_41 == V_122 ) )
F_35 ( V_15 ) ;
F_17 ( V_116 ) ;
V_32 = F_36 ( V_15 , & V_116 -> V_59 , NULL ) ;
if ( V_32 ) {
F_11 ( L_9 ) ;
}
return V_32 ;
}
static int F_37 ( struct V_11 * V_12 ,
struct V_123 * V_60 )
{
struct V_120 * V_15 = V_12 -> V_15 ;
struct V_124 * V_125 ;
int V_3 , V_32 ;
V_32 = F_38 ( V_15 , V_60 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_39 ( V_15 , V_60 ) ;
if ( V_32 )
return V_32 ;
if ( V_60 -> V_126 == NULL ) {
F_11 ( L_10 ) ;
return - V_49 ;
}
V_32 = F_40 ( V_15 , V_60 -> V_126 ,
& V_15 -> V_127 . V_52 -> V_53 . V_128 ) ;
if ( V_32 )
return V_32 ;
for ( V_3 = 0 ; V_3 < V_12 -> V_24 ; V_3 ++ ) {
struct V_129 * V_52 ;
if ( V_12 -> V_26 [ V_3 ] != & V_12 -> V_29 [ V_3 ] )
continue;
V_52 = V_12 -> V_29 [ V_3 ] . V_38 ;
V_125 = F_41 ( V_60 , V_52 ) ;
if ( V_125 == NULL ) {
F_42 ( V_15 -> V_130 , L_11 , V_52 , V_60 ) ;
return - V_49 ;
}
V_32 = F_40 ( V_15 , V_125 , & V_52 -> V_53 . V_128 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
static int F_43 ( struct V_120 * V_15 ,
struct V_11 * V_116 )
{
struct V_131 * V_132 = V_116 -> V_36 -> V_133 ;
struct V_123 * V_60 = & V_132 -> V_60 ;
int V_32 ;
if ( V_116 -> V_88 == - 1 )
return 0 ;
if ( ( V_116 -> V_56 & V_57 ) == 0 )
return 0 ;
if ( V_116 -> V_87 . V_25 ) {
V_32 = F_44 ( V_15 , V_116 -> V_41 , & V_116 -> V_87 ) ;
if ( V_32 ) {
return V_32 ;
}
}
V_32 = F_44 ( V_15 , V_116 -> V_41 , & V_116 -> V_59 ) ;
if ( V_32 ) {
return V_32 ;
}
if ( V_116 -> V_41 == V_42 )
F_34 ( V_15 ) ;
F_45 ( & V_60 -> V_134 ) ;
V_32 = F_37 ( V_116 , V_60 ) ;
if ( V_32 ) {
goto V_135;
}
F_17 ( V_116 ) ;
F_18 ( V_116 -> V_59 . V_77 , V_60 -> V_118 ) ;
if ( ( V_15 -> V_65 >= V_66 ) &&
( V_116 -> V_90 != - 1 ) ) {
V_32 = F_36 ( V_15 , & V_116 -> V_59 , & V_116 -> V_87 ) ;
} else {
V_32 = F_36 ( V_15 , & V_116 -> V_59 , NULL ) ;
}
V_135:
F_46 ( & V_60 -> V_134 ) ;
return V_32 ;
}
static int F_47 ( struct V_120 * V_15 , int V_32 )
{
if ( V_32 == - V_136 ) {
V_32 = F_48 ( V_15 ) ;
if ( ! V_32 )
V_32 = - V_137 ;
}
return V_32 ;
}
static int F_49 ( struct V_120 * V_15 , struct V_11 * V_116 )
{
struct V_16 * V_138 ;
struct V_123 * V_60 = NULL ;
int V_32 ;
if ( V_116 -> V_88 == - 1 )
return 0 ;
if ( V_116 -> V_56 & V_57 ) {
struct V_131 * V_132 = V_116 -> V_36 -> V_133 ;
V_60 = & V_132 -> V_60 ;
if ( ( V_15 -> V_65 >= V_66 ) &&
( V_116 -> V_90 != - 1 ) ) {
V_138 = & V_116 -> V_22 [ V_116 -> V_90 ] ;
if ( V_138 -> V_25 > V_139 ) {
F_11 ( L_12 , V_138 -> V_25 ) ;
return - V_49 ;
}
V_32 = F_50 ( V_15 , V_116 -> V_41 , & V_116 -> V_87 ,
V_60 , V_138 -> V_25 * 4 ) ;
if ( V_32 ) {
F_11 ( L_13 ) ;
return V_32 ;
}
V_116 -> V_87 . V_140 = true ;
V_116 -> V_87 . V_25 = V_138 -> V_25 ;
if ( F_20 ( V_116 -> V_87 . V_141 ,
V_138 -> V_104 ,
V_138 -> V_25 * 4 ) )
return - V_92 ;
}
V_138 = & V_116 -> V_22 [ V_116 -> V_88 ] ;
if ( V_138 -> V_25 > V_139 ) {
F_11 ( L_14 , V_138 -> V_25 ) ;
return - V_49 ;
}
}
V_138 = & V_116 -> V_22 [ V_116 -> V_88 ] ;
V_32 = F_50 ( V_15 , V_116 -> V_41 , & V_116 -> V_59 ,
V_60 , V_138 -> V_25 * 4 ) ;
if ( V_32 ) {
F_11 ( L_15 ) ;
return V_32 ;
}
V_116 -> V_59 . V_25 = V_138 -> V_25 ;
if ( V_138 -> V_33 )
memcpy ( V_116 -> V_59 . V_141 , V_138 -> V_33 , V_138 -> V_25 * 4 ) ;
else if ( F_20 ( V_116 -> V_59 . V_141 , V_138 -> V_104 , V_138 -> V_25 * 4 ) )
return - V_92 ;
return 0 ;
}
int F_51 ( struct V_13 * V_130 , void * V_79 , struct V_142 * V_36 )
{
struct V_120 * V_15 = V_130 -> V_143 ;
struct V_11 V_116 ;
int V_32 ;
F_52 ( & V_15 -> V_144 ) ;
if ( ! V_15 -> V_145 ) {
F_53 ( & V_15 -> V_144 ) ;
return - V_146 ;
}
memset ( & V_116 , 0 , sizeof( struct V_11 ) ) ;
V_116 . V_36 = V_36 ;
V_116 . V_15 = V_15 ;
V_116 . V_130 = V_15 -> V_130 ;
V_116 . V_65 = V_15 -> V_65 ;
V_32 = F_19 ( & V_116 , V_79 ) ;
if ( V_32 ) {
F_11 ( L_16 ) ;
F_24 ( & V_116 , V_32 , false ) ;
F_53 ( & V_15 -> V_144 ) ;
V_32 = F_47 ( V_15 , V_32 ) ;
return V_32 ;
}
V_32 = F_49 ( V_15 , & V_116 ) ;
if ( ! V_32 ) {
V_32 = F_8 ( & V_116 ) ;
if ( V_32 && V_32 != - V_147 )
F_11 ( L_17 , V_32 ) ;
}
if ( V_32 ) {
F_24 ( & V_116 , V_32 , false ) ;
F_53 ( & V_15 -> V_144 ) ;
V_32 = F_47 ( V_15 , V_32 ) ;
return V_32 ;
}
F_54 ( & V_116 ) ;
V_32 = F_32 ( V_15 , & V_116 ) ;
if ( V_32 ) {
goto V_135;
}
V_32 = F_43 ( V_15 , & V_116 ) ;
if ( V_32 ) {
goto V_135;
}
V_135:
F_24 ( & V_116 , V_32 , true ) ;
F_53 ( & V_15 -> V_144 ) ;
V_32 = F_47 ( V_15 , V_32 ) ;
return V_32 ;
}
int F_55 ( struct V_11 * V_12 ,
struct V_148 * V_149 ,
unsigned V_85 )
{
struct V_16 * V_138 = & V_12 -> V_22 [ V_12 -> V_88 ] ;
struct V_120 * V_15 = V_12 -> V_15 ;
T_1 V_150 ;
if ( V_85 >= V_138 -> V_25 ) {
F_11 ( L_18 ,
V_85 , V_138 -> V_25 ) ;
return - V_49 ;
}
V_150 = F_56 ( V_12 , V_85 ) ;
V_149 -> V_85 = V_85 ;
V_149 -> type = F_57 ( V_150 ) ;
V_149 -> V_151 = F_58 ( V_150 ) ;
V_149 -> V_152 = 0 ;
switch ( V_149 -> type ) {
case V_153 :
if ( V_15 -> V_65 < V_154 ) {
V_149 -> V_155 = F_59 ( V_150 ) ;
V_149 -> V_152 =
F_60 ( V_150 ) ;
} else
V_149 -> V_155 = F_61 ( V_150 ) ;
break;
case V_156 :
V_149 -> V_157 = F_62 ( V_150 ) ;
break;
case V_158 :
V_149 -> V_151 = - 1 ;
break;
default:
F_11 ( L_19 , V_149 -> type , V_85 ) ;
return - V_49 ;
}
if ( ( V_149 -> V_151 + 1 + V_149 -> V_85 ) >= V_138 -> V_25 ) {
F_11 ( L_20 ,
V_149 -> V_85 , V_149 -> type , V_149 -> V_151 , V_138 -> V_25 ) ;
return - V_49 ;
}
return 0 ;
}
bool F_63 ( struct V_11 * V_12 )
{
struct V_148 V_159 ;
int V_32 ;
V_32 = F_55 ( V_12 , & V_159 , V_12 -> V_85 ) ;
if ( V_32 )
return false ;
if ( V_159 . type != V_156 )
return false ;
if ( V_159 . V_157 != V_160 )
return false ;
return true ;
}
void F_64 ( struct V_11 * V_12 ,
struct V_148 * V_149 )
{
volatile T_1 * V_59 ;
unsigned V_3 ;
unsigned V_85 ;
V_59 = V_12 -> V_59 . V_141 ;
V_85 = V_149 -> V_85 ;
for ( V_3 = 0 ; V_3 <= ( V_149 -> V_151 + 1 ) ; V_3 ++ , V_85 ++ )
F_65 ( L_21 , V_85 , V_59 [ V_85 ] ) ;
}
int F_66 ( struct V_11 * V_12 ,
struct V_30 * * V_161 ,
int V_162 )
{
struct V_16 * V_163 ;
struct V_148 V_159 ;
unsigned V_85 ;
int V_32 ;
if ( V_12 -> V_21 == - 1 ) {
F_11 ( L_22 ) ;
return - V_49 ;
}
* V_161 = NULL ;
V_163 = & V_12 -> V_22 [ V_12 -> V_21 ] ;
V_32 = F_55 ( V_12 , & V_159 , V_12 -> V_85 ) ;
if ( V_32 )
return V_32 ;
V_12 -> V_85 += V_159 . V_151 + 2 ;
if ( V_159 . type != V_156 ||
V_159 . V_157 != V_160 ) {
F_11 ( L_23 ,
V_159 . V_85 ) ;
F_64 ( V_12 , & V_159 ) ;
return - V_49 ;
}
V_85 = F_56 ( V_12 , V_159 . V_85 + 1 ) ;
if ( V_85 >= V_163 -> V_25 ) {
F_11 ( L_24 ,
V_85 , V_163 -> V_25 ) ;
F_64 ( V_12 , & V_159 ) ;
return - V_49 ;
}
if ( V_162 ) {
* V_161 = V_12 -> V_29 ;
( * V_161 ) -> V_164 =
( V_165 ) V_163 -> V_33 [ V_85 + 3 ] << 32 ;
( * V_161 ) -> V_164 |= V_163 -> V_33 [ V_85 + 0 ] ;
} else
* V_161 = V_12 -> V_26 [ ( V_85 / 4 ) ] ;
return 0 ;
}

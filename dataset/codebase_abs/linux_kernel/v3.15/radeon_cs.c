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
T_1 V_43 = V_32 -> V_40 ?
V_32 -> V_40 : V_32 -> V_46 ;
if ( V_43 & V_47 ) {
F_11 ( L_2
L_3 ) ;
return - V_48 ;
}
V_12 -> V_29 [ V_3 ] . V_43 = V_43 ;
if ( V_43 == V_44 )
V_43 |= V_49 ;
V_12 -> V_29 [ V_3 ] . V_45 = V_43 ;
}
V_12 -> V_29 [ V_3 ] . V_50 . V_51 = & V_12 -> V_29 [ V_3 ] . V_38 -> V_52 ;
V_12 -> V_29 [ V_3 ] . V_34 = V_32 -> V_34 ;
F_3 ( & V_18 , & V_12 -> V_29 [ V_3 ] . V_50 . V_53 ,
V_8 ) ;
}
F_6 ( & V_18 , & V_12 -> V_54 ) ;
if ( V_12 -> V_55 & V_56 )
V_12 -> V_57 = F_14 ( V_12 -> V_15 , V_12 -> V_58 . V_59 ,
& V_12 -> V_54 ) ;
return F_15 ( V_12 -> V_15 , & V_12 -> V_60 , & V_12 -> V_54 , V_12 -> V_41 ) ;
}
static int F_16 ( struct V_11 * V_12 , T_2 V_41 , T_3 V_8 )
{
V_12 -> V_8 = V_8 ;
switch ( V_41 ) {
default:
F_11 ( L_4 , V_41 ) ;
return - V_48 ;
case V_61 :
V_12 -> V_41 = V_62 ;
break;
case V_63 :
if ( V_12 -> V_15 -> V_64 >= V_65 ) {
if ( V_12 -> V_8 > 0 )
V_12 -> V_41 = V_66 ;
else
V_12 -> V_41 = V_67 ;
} else
V_12 -> V_41 = V_62 ;
break;
case V_68 :
if ( V_12 -> V_15 -> V_64 >= V_69 ) {
if ( V_12 -> V_8 > 0 )
V_12 -> V_41 = V_70 ;
else
V_12 -> V_41 = V_71 ;
} else if ( V_12 -> V_15 -> V_64 >= V_72 ) {
V_12 -> V_41 = V_70 ;
} else {
return - V_48 ;
}
break;
case V_73 :
V_12 -> V_41 = V_42 ;
break;
case V_74 :
V_12 -> V_41 = V_75 ;
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
F_18 ( V_12 -> V_58 . V_76 ,
V_12 -> V_29 [ V_3 ] . V_38 -> V_52 . V_77 ) ;
}
}
int F_19 ( struct V_11 * V_12 , void * V_78 )
{
struct V_79 * V_80 = V_78 ;
T_4 * V_81 ;
unsigned V_82 , V_3 ;
T_2 V_41 = V_61 ;
T_3 V_8 = 0 ;
if ( ! V_80 -> V_83 ) {
return 0 ;
}
F_2 ( & V_12 -> V_54 ) ;
V_12 -> V_84 = 0 ;
V_12 -> V_58 . V_85 = NULL ;
V_12 -> V_58 . V_76 = NULL ;
V_12 -> V_86 . V_85 = NULL ;
V_12 -> V_86 . V_76 = NULL ;
V_12 -> V_87 = - 1 ;
V_12 -> V_21 = - 1 ;
V_12 -> V_88 = - 1 ;
V_12 -> V_89 = - 1 ;
V_12 -> V_90 = F_9 ( V_80 -> V_83 , sizeof( T_4 ) , V_27 ) ;
if ( V_12 -> V_90 == NULL ) {
return - V_28 ;
}
V_81 = ( T_4 * ) ( unsigned long ) ( V_80 -> V_22 ) ;
if ( F_20 ( V_12 -> V_90 , V_81 ,
sizeof( T_4 ) * V_80 -> V_83 ) ) {
return - V_91 ;
}
V_12 -> V_55 = 0 ;
V_12 -> V_92 = V_80 -> V_83 ;
V_12 -> V_22 = F_9 ( V_12 -> V_92 , sizeof( struct V_16 ) , V_27 ) ;
if ( V_12 -> V_22 == NULL ) {
return - V_28 ;
}
for ( V_3 = 0 ; V_3 < V_12 -> V_92 ; V_3 ++ ) {
struct V_93 T_5 * * V_94 = NULL ;
struct V_93 V_95 ;
T_1 T_5 * V_96 ;
V_94 = ( void T_5 * ) ( unsigned long ) V_12 -> V_90 [ V_3 ] ;
if ( F_20 ( & V_95 , V_94 ,
sizeof( struct V_93 ) ) ) {
return - V_91 ;
}
V_12 -> V_22 [ V_3 ] . V_25 = V_95 . V_25 ;
V_12 -> V_22 [ V_3 ] . V_97 = V_95 . V_97 ;
if ( V_12 -> V_22 [ V_3 ] . V_97 == V_98 ) {
V_12 -> V_21 = V_3 ;
}
if ( V_12 -> V_22 [ V_3 ] . V_97 == V_99 ) {
V_12 -> V_87 = V_3 ;
if ( V_12 -> V_22 [ V_3 ] . V_25 == 0 )
return - V_48 ;
}
if ( V_12 -> V_22 [ V_3 ] . V_97 == V_100 ) {
V_12 -> V_89 = V_3 ;
if ( V_12 -> V_22 [ V_3 ] . V_25 == 0 )
return - V_48 ;
}
if ( V_12 -> V_22 [ V_3 ] . V_97 == V_101 ) {
V_12 -> V_88 = V_3 ;
if ( V_12 -> V_22 [ V_3 ] . V_25 == 0 )
return - V_48 ;
}
V_82 = V_12 -> V_22 [ V_3 ] . V_25 ;
V_96 = ( void T_5 * ) ( unsigned long ) V_95 . V_102 ;
V_12 -> V_22 [ V_3 ] . V_103 = V_96 ;
if ( V_12 -> V_22 [ V_3 ] . V_97 == V_100 )
continue;
if ( V_12 -> V_22 [ V_3 ] . V_97 == V_99 ) {
if ( ! V_12 -> V_15 || ! ( V_12 -> V_15 -> V_39 & V_104 ) )
continue;
}
V_12 -> V_22 [ V_3 ] . V_33 = F_21 ( V_82 , sizeof( T_1 ) ) ;
V_82 *= sizeof( T_1 ) ;
if ( V_12 -> V_22 [ V_3 ] . V_33 == NULL ) {
return - V_28 ;
}
if ( F_20 ( V_12 -> V_22 [ V_3 ] . V_33 , V_96 , V_82 ) ) {
return - V_91 ;
}
if ( V_12 -> V_22 [ V_3 ] . V_97 == V_101 ) {
V_12 -> V_55 = V_12 -> V_22 [ V_3 ] . V_33 [ 0 ] ;
if ( V_12 -> V_22 [ V_3 ] . V_25 > 1 )
V_41 = V_12 -> V_22 [ V_3 ] . V_33 [ 1 ] ;
if ( V_12 -> V_22 [ V_3 ] . V_25 > 2 )
V_8 = ( T_3 ) V_12 -> V_22 [ V_3 ] . V_33 [ 2 ] ;
}
}
if ( V_12 -> V_15 ) {
if ( ( V_12 -> V_55 & V_56 ) &&
! V_12 -> V_15 -> V_105 . V_106 ) {
F_11 ( L_5 ) ;
return - V_48 ;
}
if ( F_16 ( V_12 , V_41 , V_8 ) )
return - V_48 ;
if ( ( V_12 -> V_55 & V_56 ) == 0 ) {
if ( V_12 -> V_15 -> V_107 -> V_41 [ V_12 -> V_41 ] -> V_108 == NULL ) {
F_11 ( L_6 , V_12 -> V_41 ) ;
return - V_48 ;
}
} else {
if ( V_12 -> V_15 -> V_107 -> V_41 [ V_12 -> V_41 ] -> V_109 == NULL ) {
F_11 ( L_7 ,
V_12 -> V_41 ) ;
return - V_48 ;
}
}
}
return 0 ;
}
static int F_22 ( void * V_110 , struct V_6 * V_111 ,
struct V_6 * V_2 )
{
struct V_30 * V_112 = F_23 ( V_111 , struct V_30 , V_50 . V_53 ) ;
struct V_30 * V_113 = F_23 ( V_2 , struct V_30 , V_50 . V_53 ) ;
return ( int ) V_112 -> V_38 -> V_52 . V_114 - ( int ) V_113 -> V_38 -> V_52 . V_114 ;
}
static void F_24 ( struct V_11 * V_115 , int error , bool V_116 )
{
unsigned V_3 ;
if ( ! error ) {
F_25 ( NULL , & V_115 -> V_54 , F_22 ) ;
F_26 ( & V_115 -> V_60 ,
& V_115 -> V_54 ,
V_115 -> V_58 . V_117 ) ;
} else if ( V_116 ) {
F_27 ( & V_115 -> V_60 ,
& V_115 -> V_54 ) ;
}
if ( V_115 -> V_29 != NULL ) {
for ( V_3 = 0 ; V_3 < V_115 -> V_24 ; V_3 ++ ) {
if ( V_115 -> V_29 [ V_3 ] . V_35 )
F_28 ( V_115 -> V_29 [ V_3 ] . V_35 ) ;
}
}
F_29 ( V_115 -> V_118 ) ;
F_29 ( V_115 -> V_29 ) ;
F_29 ( V_115 -> V_26 ) ;
F_29 ( V_115 -> V_57 ) ;
for ( V_3 = 0 ; V_3 < V_115 -> V_92 ; V_3 ++ )
F_30 ( V_115 -> V_22 [ V_3 ] . V_33 ) ;
F_29 ( V_115 -> V_22 ) ;
F_29 ( V_115 -> V_90 ) ;
F_31 ( V_115 -> V_15 , & V_115 -> V_58 ) ;
F_31 ( V_115 -> V_15 , & V_115 -> V_86 ) ;
}
static int F_32 ( struct V_119 * V_15 ,
struct V_11 * V_115 )
{
int V_32 ;
if ( V_115 -> V_87 == - 1 )
return 0 ;
if ( V_115 -> V_55 & V_56 )
return 0 ;
V_32 = F_33 ( V_15 , V_115 -> V_41 , V_115 ) ;
if ( V_32 || V_115 -> V_120 ) {
F_11 ( L_8 ) ;
return V_32 ;
}
if ( V_115 -> V_41 == V_42 )
F_34 ( V_15 ) ;
else if ( ( V_115 -> V_41 == V_75 ) ||
( V_115 -> V_41 == V_121 ) )
F_35 ( V_15 ) ;
F_17 ( V_115 ) ;
V_32 = F_36 ( V_15 , & V_115 -> V_58 , NULL ) ;
if ( V_32 ) {
F_11 ( L_9 ) ;
}
return V_32 ;
}
static int F_37 ( struct V_11 * V_12 ,
struct V_122 * V_59 )
{
struct V_119 * V_15 = V_12 -> V_15 ;
int V_3 , V_32 ;
V_32 = F_38 ( V_15 , V_59 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_39 ( V_15 , V_59 , V_15 -> V_123 . V_51 ,
& V_15 -> V_123 . V_51 -> V_52 . V_124 ) ;
if ( V_32 )
return V_32 ;
for ( V_3 = 0 ; V_3 < V_12 -> V_24 ; V_3 ++ ) {
struct V_125 * V_51 ;
if ( V_12 -> V_26 [ V_3 ] != & V_12 -> V_29 [ V_3 ] )
continue;
V_51 = V_12 -> V_29 [ V_3 ] . V_38 ;
V_32 = F_39 ( V_15 , V_59 , V_51 , & V_51 -> V_52 . V_124 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
static int F_40 ( struct V_119 * V_15 ,
struct V_11 * V_115 )
{
struct V_126 * V_127 = V_115 -> V_36 -> V_128 ;
struct V_122 * V_59 = & V_127 -> V_59 ;
int V_32 ;
if ( V_115 -> V_87 == - 1 )
return 0 ;
if ( ( V_115 -> V_55 & V_56 ) == 0 )
return 0 ;
if ( V_115 -> V_86 . V_25 ) {
V_32 = F_41 ( V_15 , V_115 -> V_41 , & V_115 -> V_86 ) ;
if ( V_32 ) {
return V_32 ;
}
}
V_32 = F_41 ( V_15 , V_115 -> V_41 , & V_115 -> V_58 ) ;
if ( V_32 ) {
return V_32 ;
}
if ( V_115 -> V_41 == V_42 )
F_34 ( V_15 ) ;
F_42 ( & V_59 -> V_129 ) ;
V_32 = F_37 ( V_115 , V_59 ) ;
if ( V_32 ) {
goto V_130;
}
F_17 ( V_115 ) ;
F_18 ( V_115 -> V_58 . V_76 , V_59 -> V_117 ) ;
if ( ( V_15 -> V_64 >= V_65 ) &&
( V_115 -> V_89 != - 1 ) ) {
V_32 = F_36 ( V_15 , & V_115 -> V_58 , & V_115 -> V_86 ) ;
} else {
V_32 = F_36 ( V_15 , & V_115 -> V_58 , NULL ) ;
}
V_130:
F_43 ( & V_59 -> V_129 ) ;
return V_32 ;
}
static int F_44 ( struct V_119 * V_15 , int V_32 )
{
if ( V_32 == - V_131 ) {
V_32 = F_45 ( V_15 ) ;
if ( ! V_32 )
V_32 = - V_132 ;
}
return V_32 ;
}
static int F_46 ( struct V_119 * V_15 , struct V_11 * V_115 )
{
struct V_16 * V_133 ;
struct V_122 * V_59 = NULL ;
int V_32 ;
if ( V_115 -> V_87 == - 1 )
return 0 ;
if ( V_115 -> V_55 & V_56 ) {
struct V_126 * V_127 = V_115 -> V_36 -> V_128 ;
V_59 = & V_127 -> V_59 ;
if ( ( V_15 -> V_64 >= V_65 ) &&
( V_115 -> V_89 != - 1 ) ) {
V_133 = & V_115 -> V_22 [ V_115 -> V_89 ] ;
if ( V_133 -> V_25 > V_134 ) {
F_11 ( L_10 , V_133 -> V_25 ) ;
return - V_48 ;
}
V_32 = F_47 ( V_15 , V_115 -> V_41 , & V_115 -> V_86 ,
V_59 , V_133 -> V_25 * 4 ) ;
if ( V_32 ) {
F_11 ( L_11 ) ;
return V_32 ;
}
V_115 -> V_86 . V_135 = true ;
V_115 -> V_86 . V_25 = V_133 -> V_25 ;
if ( F_20 ( V_115 -> V_86 . V_136 ,
V_133 -> V_103 ,
V_133 -> V_25 * 4 ) )
return - V_91 ;
}
V_133 = & V_115 -> V_22 [ V_115 -> V_87 ] ;
if ( V_133 -> V_25 > V_134 ) {
F_11 ( L_12 , V_133 -> V_25 ) ;
return - V_48 ;
}
}
V_133 = & V_115 -> V_22 [ V_115 -> V_87 ] ;
V_32 = F_47 ( V_15 , V_115 -> V_41 , & V_115 -> V_58 ,
V_59 , V_133 -> V_25 * 4 ) ;
if ( V_32 ) {
F_11 ( L_13 ) ;
return V_32 ;
}
V_115 -> V_58 . V_25 = V_133 -> V_25 ;
if ( V_133 -> V_33 )
memcpy ( V_115 -> V_58 . V_136 , V_133 -> V_33 , V_133 -> V_25 * 4 ) ;
else if ( F_20 ( V_115 -> V_58 . V_136 , V_133 -> V_103 , V_133 -> V_25 * 4 ) )
return - V_91 ;
return 0 ;
}
int F_48 ( struct V_13 * V_137 , void * V_78 , struct V_138 * V_36 )
{
struct V_119 * V_15 = V_137 -> V_139 ;
struct V_11 V_115 ;
int V_32 ;
F_49 ( & V_15 -> V_140 ) ;
if ( ! V_15 -> V_141 ) {
F_50 ( & V_15 -> V_140 ) ;
return - V_142 ;
}
memset ( & V_115 , 0 , sizeof( struct V_11 ) ) ;
V_115 . V_36 = V_36 ;
V_115 . V_15 = V_15 ;
V_115 . V_137 = V_15 -> V_137 ;
V_115 . V_64 = V_15 -> V_64 ;
V_32 = F_19 ( & V_115 , V_78 ) ;
if ( V_32 ) {
F_11 ( L_14 ) ;
F_24 ( & V_115 , V_32 , false ) ;
F_50 ( & V_15 -> V_140 ) ;
V_32 = F_44 ( V_15 , V_32 ) ;
return V_32 ;
}
V_32 = F_46 ( V_15 , & V_115 ) ;
if ( ! V_32 ) {
V_32 = F_8 ( & V_115 ) ;
if ( V_32 && V_32 != - V_143 )
F_11 ( L_15 , V_32 ) ;
}
if ( V_32 ) {
F_24 ( & V_115 , V_32 , false ) ;
F_50 ( & V_15 -> V_140 ) ;
V_32 = F_44 ( V_15 , V_32 ) ;
return V_32 ;
}
F_51 ( & V_115 ) ;
V_32 = F_32 ( V_15 , & V_115 ) ;
if ( V_32 ) {
goto V_130;
}
V_32 = F_40 ( V_15 , & V_115 ) ;
if ( V_32 ) {
goto V_130;
}
V_130:
F_24 ( & V_115 , V_32 , true ) ;
F_50 ( & V_15 -> V_140 ) ;
V_32 = F_44 ( V_15 , V_32 ) ;
return V_32 ;
}
int F_52 ( struct V_11 * V_12 ,
struct V_144 * V_145 ,
unsigned V_84 )
{
struct V_16 * V_133 = & V_12 -> V_22 [ V_12 -> V_87 ] ;
struct V_119 * V_15 = V_12 -> V_15 ;
T_1 V_146 ;
if ( V_84 >= V_133 -> V_25 ) {
F_11 ( L_16 ,
V_84 , V_133 -> V_25 ) ;
return - V_48 ;
}
V_146 = F_53 ( V_12 , V_84 ) ;
V_145 -> V_84 = V_84 ;
V_145 -> type = F_54 ( V_146 ) ;
V_145 -> V_147 = F_55 ( V_146 ) ;
V_145 -> V_148 = 0 ;
switch ( V_145 -> type ) {
case V_149 :
if ( V_15 -> V_64 < V_150 ) {
V_145 -> V_151 = F_56 ( V_146 ) ;
V_145 -> V_148 =
F_57 ( V_146 ) ;
} else
V_145 -> V_151 = F_58 ( V_146 ) ;
break;
case V_152 :
V_145 -> V_153 = F_59 ( V_146 ) ;
break;
case V_154 :
V_145 -> V_147 = - 1 ;
break;
default:
F_11 ( L_17 , V_145 -> type , V_84 ) ;
return - V_48 ;
}
if ( ( V_145 -> V_147 + 1 + V_145 -> V_84 ) >= V_133 -> V_25 ) {
F_11 ( L_18 ,
V_145 -> V_84 , V_145 -> type , V_145 -> V_147 , V_133 -> V_25 ) ;
return - V_48 ;
}
return 0 ;
}
bool F_60 ( struct V_11 * V_12 )
{
struct V_144 V_155 ;
int V_32 ;
V_32 = F_52 ( V_12 , & V_155 , V_12 -> V_84 ) ;
if ( V_32 )
return false ;
if ( V_155 . type != V_152 )
return false ;
if ( V_155 . V_153 != V_156 )
return false ;
return true ;
}
void F_61 ( struct V_11 * V_12 ,
struct V_144 * V_145 )
{
volatile T_1 * V_58 ;
unsigned V_3 ;
unsigned V_84 ;
V_58 = V_12 -> V_58 . V_136 ;
V_84 = V_145 -> V_84 ;
for ( V_3 = 0 ; V_3 <= ( V_145 -> V_147 + 1 ) ; V_3 ++ , V_84 ++ )
F_62 ( L_19 , V_84 , V_58 [ V_84 ] ) ;
}
int F_63 ( struct V_11 * V_12 ,
struct V_30 * * V_157 ,
int V_158 )
{
struct V_16 * V_159 ;
struct V_144 V_155 ;
unsigned V_84 ;
int V_32 ;
if ( V_12 -> V_21 == - 1 ) {
F_11 ( L_20 ) ;
return - V_48 ;
}
* V_157 = NULL ;
V_159 = & V_12 -> V_22 [ V_12 -> V_21 ] ;
V_32 = F_52 ( V_12 , & V_155 , V_12 -> V_84 ) ;
if ( V_32 )
return V_32 ;
V_12 -> V_84 += V_155 . V_147 + 2 ;
if ( V_155 . type != V_152 ||
V_155 . V_153 != V_156 ) {
F_11 ( L_21 ,
V_155 . V_84 ) ;
F_61 ( V_12 , & V_155 ) ;
return - V_48 ;
}
V_84 = F_53 ( V_12 , V_155 . V_84 + 1 ) ;
if ( V_84 >= V_159 -> V_25 ) {
F_11 ( L_22 ,
V_84 , V_159 -> V_25 ) ;
F_61 ( V_12 , & V_155 ) ;
return - V_48 ;
}
if ( V_158 ) {
* V_157 = V_12 -> V_29 ;
( * V_157 ) -> V_160 =
( V_161 ) V_159 -> V_33 [ V_84 + 3 ] << 32 ;
( * V_157 ) -> V_160 |= V_159 -> V_33 [ V_84 + 0 ] ;
} else
* V_157 = V_12 -> V_26 [ ( V_84 / 4 ) ] ;
return 0 ;
}

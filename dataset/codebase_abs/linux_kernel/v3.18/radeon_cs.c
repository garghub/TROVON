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
bool V_20 , V_21 = false ;
int V_22 ;
if ( V_12 -> V_23 == - 1 ) {
return 0 ;
}
V_17 = & V_12 -> V_24 [ V_12 -> V_23 ] ;
V_12 -> V_25 = 0 ;
V_12 -> V_26 = V_17 -> V_27 / 4 ;
V_12 -> V_28 = F_9 ( V_12 -> V_26 , sizeof( void * ) , V_29 ) ;
if ( V_12 -> V_28 == NULL ) {
return - V_30 ;
}
V_12 -> V_31 = F_9 ( V_12 -> V_26 , sizeof( struct V_32 ) , V_29 ) ;
if ( V_12 -> V_31 == NULL ) {
return - V_30 ;
}
F_1 ( & V_18 ) ;
for ( V_3 = 0 ; V_3 < V_12 -> V_26 ; V_3 ++ ) {
struct V_33 * V_22 ;
unsigned V_8 ;
V_20 = false ;
V_22 = (struct V_33 * ) & V_17 -> V_34 [ V_3 * 4 ] ;
for ( V_19 = 0 ; V_19 < V_3 ; V_19 ++ ) {
if ( V_22 -> V_35 == V_12 -> V_31 [ V_19 ] . V_35 ) {
V_12 -> V_28 [ V_3 ] = & V_12 -> V_31 [ V_19 ] ;
V_20 = true ;
break;
}
}
if ( V_20 ) {
V_12 -> V_31 [ V_3 ] . V_35 = 0 ;
continue;
}
V_12 -> V_31 [ V_3 ] . V_36 = F_10 ( V_14 , V_12 -> V_37 ,
V_22 -> V_35 ) ;
if ( V_12 -> V_31 [ V_3 ] . V_36 == NULL ) {
F_11 ( L_1 ,
V_22 -> V_35 ) ;
return - V_38 ;
}
V_12 -> V_28 [ V_3 ] = & V_12 -> V_31 [ V_3 ] ;
V_12 -> V_31 [ V_3 ] . V_39 = F_12 ( V_12 -> V_31 [ V_3 ] . V_36 ) ;
V_8 = ( V_22 -> V_40 & V_41 ) * 2
+ ! ! V_22 -> V_42 ;
if ( V_12 -> V_43 == V_44 &&
( V_3 == 0 || F_13 ( V_12 -> V_15 -> V_14 ) ||
V_12 -> V_15 -> V_45 == V_46 ||
V_12 -> V_15 -> V_45 == V_47 ) ) {
V_12 -> V_31 [ V_3 ] . V_48 =
V_49 ;
V_12 -> V_31 [ V_3 ] . V_50 =
V_49 ;
V_8 = V_9 ;
} else {
T_1 V_51 = V_22 -> V_42 ?
V_22 -> V_42 : V_22 -> V_52 ;
if ( V_51 & V_53 ) {
F_11 ( L_2
L_3 ) ;
return - V_54 ;
}
V_12 -> V_31 [ V_3 ] . V_48 = V_51 ;
if ( V_51 == V_49 )
V_51 |= V_55 ;
V_12 -> V_31 [ V_3 ] . V_50 = V_51 ;
}
if ( F_14 ( V_12 -> V_31 [ V_3 ] . V_39 -> V_56 . V_57 ) ) {
T_1 V_51 = V_12 -> V_31 [ V_3 ] . V_48 ;
if ( ! ( V_51 & V_55 ) ) {
F_11 ( L_4
L_5 ) ;
return - V_54 ;
}
V_21 = true ;
V_51 = V_55 ;
V_12 -> V_31 [ V_3 ] . V_48 = V_51 ;
V_12 -> V_31 [ V_3 ] . V_50 = V_51 ;
}
V_12 -> V_31 [ V_3 ] . V_58 . V_59 = & V_12 -> V_31 [ V_3 ] . V_39 -> V_56 ;
V_12 -> V_31 [ V_3 ] . V_58 . V_60 = ! V_22 -> V_42 ;
V_12 -> V_31 [ V_3 ] . V_35 = V_22 -> V_35 ;
F_3 ( & V_18 , & V_12 -> V_31 [ V_3 ] . V_58 . V_61 ,
V_8 ) ;
}
F_6 ( & V_18 , & V_12 -> V_62 ) ;
if ( V_12 -> V_63 & V_64 )
V_12 -> V_65 = F_15 ( V_12 -> V_15 , V_12 -> V_66 . V_67 ,
& V_12 -> V_62 ) ;
if ( V_21 )
F_16 ( & V_68 -> V_69 -> V_70 ) ;
V_22 = F_17 ( V_12 -> V_15 , & V_12 -> V_71 , & V_12 -> V_62 , V_12 -> V_43 ) ;
if ( V_21 )
F_18 ( & V_68 -> V_69 -> V_70 ) ;
return V_22 ;
}
static int F_19 ( struct V_11 * V_12 , T_2 V_43 , T_3 V_8 )
{
V_12 -> V_8 = V_8 ;
switch ( V_43 ) {
default:
F_11 ( L_6 , V_43 ) ;
return - V_54 ;
case V_72 :
V_12 -> V_43 = V_73 ;
break;
case V_74 :
if ( V_12 -> V_15 -> V_45 >= V_75 ) {
if ( V_12 -> V_8 > 0 )
V_12 -> V_43 = V_76 ;
else
V_12 -> V_43 = V_77 ;
} else
V_12 -> V_43 = V_73 ;
break;
case V_78 :
if ( V_12 -> V_15 -> V_45 >= V_79 ) {
if ( V_12 -> V_8 > 0 )
V_12 -> V_43 = V_80 ;
else
V_12 -> V_43 = V_81 ;
} else if ( V_12 -> V_15 -> V_45 >= V_82 ) {
V_12 -> V_43 = V_80 ;
} else {
return - V_54 ;
}
break;
case V_83 :
V_12 -> V_43 = V_44 ;
break;
case V_84 :
V_12 -> V_43 = V_85 ;
break;
}
return 0 ;
}
static int F_20 ( struct V_11 * V_12 )
{
struct V_32 * V_86 ;
int V_22 ;
F_21 (reloc, &p->validated, tv.head) {
struct V_87 * V_88 ;
V_88 = V_86 -> V_39 -> V_56 . V_88 ;
V_22 = F_22 ( V_12 -> V_15 , V_12 -> V_66 . V_89 , V_88 ,
V_86 -> V_58 . V_60 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
int F_23 ( struct V_11 * V_12 , void * V_90 )
{
struct V_91 * V_92 = V_90 ;
T_4 * V_93 ;
unsigned V_94 , V_3 ;
T_2 V_43 = V_72 ;
T_3 V_8 = 0 ;
if ( ! V_92 -> V_95 ) {
return 0 ;
}
F_2 ( & V_12 -> V_62 ) ;
V_12 -> V_96 = 0 ;
V_12 -> V_66 . V_97 = NULL ;
V_12 -> V_66 . V_89 = NULL ;
V_12 -> V_98 . V_97 = NULL ;
V_12 -> V_98 . V_89 = NULL ;
V_12 -> V_99 = - 1 ;
V_12 -> V_23 = - 1 ;
V_12 -> V_100 = - 1 ;
V_12 -> V_101 = - 1 ;
V_12 -> V_102 = F_9 ( V_92 -> V_95 , sizeof( T_4 ) , V_29 ) ;
if ( V_12 -> V_102 == NULL ) {
return - V_30 ;
}
V_93 = ( T_4 * ) ( unsigned long ) ( V_92 -> V_24 ) ;
if ( F_24 ( V_12 -> V_102 , V_93 ,
sizeof( T_4 ) * V_92 -> V_95 ) ) {
return - V_103 ;
}
V_12 -> V_63 = 0 ;
V_12 -> V_104 = V_92 -> V_95 ;
V_12 -> V_24 = F_9 ( V_12 -> V_104 , sizeof( struct V_16 ) , V_29 ) ;
if ( V_12 -> V_24 == NULL ) {
return - V_30 ;
}
for ( V_3 = 0 ; V_3 < V_12 -> V_104 ; V_3 ++ ) {
struct V_105 T_5 * * V_106 = NULL ;
struct V_105 V_107 ;
T_1 T_5 * V_108 ;
V_106 = ( void T_5 * ) ( unsigned long ) V_12 -> V_102 [ V_3 ] ;
if ( F_24 ( & V_107 , V_106 ,
sizeof( struct V_105 ) ) ) {
return - V_103 ;
}
V_12 -> V_24 [ V_3 ] . V_27 = V_107 . V_27 ;
V_12 -> V_24 [ V_3 ] . V_109 = V_107 . V_109 ;
if ( V_12 -> V_24 [ V_3 ] . V_109 == V_110 ) {
V_12 -> V_23 = V_3 ;
}
if ( V_12 -> V_24 [ V_3 ] . V_109 == V_111 ) {
V_12 -> V_99 = V_3 ;
if ( V_12 -> V_24 [ V_3 ] . V_27 == 0 )
return - V_54 ;
}
if ( V_12 -> V_24 [ V_3 ] . V_109 == V_112 ) {
V_12 -> V_101 = V_3 ;
if ( V_12 -> V_24 [ V_3 ] . V_27 == 0 )
return - V_54 ;
}
if ( V_12 -> V_24 [ V_3 ] . V_109 == V_113 ) {
V_12 -> V_100 = V_3 ;
if ( V_12 -> V_24 [ V_3 ] . V_27 == 0 )
return - V_54 ;
}
V_94 = V_12 -> V_24 [ V_3 ] . V_27 ;
V_108 = ( void T_5 * ) ( unsigned long ) V_107 . V_114 ;
V_12 -> V_24 [ V_3 ] . V_115 = V_108 ;
if ( V_12 -> V_24 [ V_3 ] . V_109 == V_112 )
continue;
if ( V_12 -> V_24 [ V_3 ] . V_109 == V_111 ) {
if ( ! V_12 -> V_15 || ! ( V_12 -> V_15 -> V_40 & V_116 ) )
continue;
}
V_12 -> V_24 [ V_3 ] . V_34 = F_25 ( V_94 , sizeof( T_1 ) ) ;
V_94 *= sizeof( T_1 ) ;
if ( V_12 -> V_24 [ V_3 ] . V_34 == NULL ) {
return - V_30 ;
}
if ( F_24 ( V_12 -> V_24 [ V_3 ] . V_34 , V_108 , V_94 ) ) {
return - V_103 ;
}
if ( V_12 -> V_24 [ V_3 ] . V_109 == V_113 ) {
V_12 -> V_63 = V_12 -> V_24 [ V_3 ] . V_34 [ 0 ] ;
if ( V_12 -> V_24 [ V_3 ] . V_27 > 1 )
V_43 = V_12 -> V_24 [ V_3 ] . V_34 [ 1 ] ;
if ( V_12 -> V_24 [ V_3 ] . V_27 > 2 )
V_8 = ( T_3 ) V_12 -> V_24 [ V_3 ] . V_34 [ 2 ] ;
}
}
if ( V_12 -> V_15 ) {
if ( ( V_12 -> V_63 & V_64 ) &&
! V_12 -> V_15 -> V_117 . V_118 ) {
F_11 ( L_7 ) ;
return - V_54 ;
}
if ( F_19 ( V_12 , V_43 , V_8 ) )
return - V_54 ;
if ( ( V_12 -> V_63 & V_64 ) == 0 ) {
if ( V_12 -> V_15 -> V_119 -> V_43 [ V_12 -> V_43 ] -> V_120 == NULL ) {
F_11 ( L_8 , V_12 -> V_43 ) ;
return - V_54 ;
}
} else {
if ( V_12 -> V_15 -> V_119 -> V_43 [ V_12 -> V_43 ] -> V_121 == NULL ) {
F_11 ( L_9 ,
V_12 -> V_43 ) ;
return - V_54 ;
}
}
}
return 0 ;
}
static int F_26 ( void * V_122 , struct V_6 * V_123 ,
struct V_6 * V_2 )
{
struct V_32 * V_124 = F_27 ( V_123 , struct V_32 , V_58 . V_61 ) ;
struct V_32 * V_125 = F_27 ( V_2 , struct V_32 , V_58 . V_61 ) ;
return ( int ) V_124 -> V_39 -> V_56 . V_126 - ( int ) V_125 -> V_39 -> V_56 . V_126 ;
}
static void F_28 ( struct V_11 * V_127 , int error , bool V_128 )
{
unsigned V_3 ;
if ( ! error ) {
F_29 ( NULL , & V_127 -> V_62 , F_26 ) ;
F_30 ( & V_127 -> V_71 ,
& V_127 -> V_62 ,
& V_127 -> V_66 . V_129 -> V_130 ) ;
} else if ( V_128 ) {
F_31 ( & V_127 -> V_71 ,
& V_127 -> V_62 ) ;
}
if ( V_127 -> V_31 != NULL ) {
for ( V_3 = 0 ; V_3 < V_127 -> V_26 ; V_3 ++ ) {
if ( V_127 -> V_31 [ V_3 ] . V_36 )
F_32 ( V_127 -> V_31 [ V_3 ] . V_36 ) ;
}
}
F_33 ( V_127 -> V_131 ) ;
F_33 ( V_127 -> V_31 ) ;
F_33 ( V_127 -> V_28 ) ;
F_34 ( V_127 -> V_65 ) ;
for ( V_3 = 0 ; V_3 < V_127 -> V_104 ; V_3 ++ )
F_34 ( V_127 -> V_24 [ V_3 ] . V_34 ) ;
F_33 ( V_127 -> V_24 ) ;
F_33 ( V_127 -> V_102 ) ;
F_35 ( V_127 -> V_15 , & V_127 -> V_66 ) ;
F_35 ( V_127 -> V_15 , & V_127 -> V_98 ) ;
}
static int F_36 ( struct V_132 * V_15 ,
struct V_11 * V_127 )
{
int V_22 ;
if ( V_127 -> V_99 == - 1 )
return 0 ;
if ( V_127 -> V_63 & V_64 )
return 0 ;
V_22 = F_37 ( V_15 , V_127 -> V_43 , V_127 ) ;
if ( V_22 || V_127 -> V_133 ) {
F_11 ( L_10 ) ;
return V_22 ;
}
V_22 = F_20 ( V_127 ) ;
if ( V_22 ) {
if ( V_22 != - V_134 )
F_11 ( L_11 , V_22 ) ;
return V_22 ;
}
if ( V_127 -> V_43 == V_44 )
F_38 ( V_15 ) ;
else if ( ( V_127 -> V_43 == V_85 ) ||
( V_127 -> V_43 == V_135 ) )
F_39 ( V_15 ) ;
V_22 = F_40 ( V_15 , & V_127 -> V_66 , NULL , true ) ;
if ( V_22 ) {
F_11 ( L_12 ) ;
}
return V_22 ;
}
static int F_41 ( struct V_11 * V_12 ,
struct V_136 * V_67 )
{
struct V_132 * V_15 = V_12 -> V_15 ;
struct V_137 * V_138 ;
int V_3 , V_22 ;
V_22 = F_42 ( V_15 , V_67 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_43 ( V_15 , V_67 ) ;
if ( V_22 )
return V_22 ;
if ( V_67 -> V_139 == NULL ) {
F_11 ( L_13 ) ;
return - V_54 ;
}
V_22 = F_44 ( V_15 , V_67 -> V_139 ,
& V_15 -> V_140 . V_59 -> V_56 . V_141 ) ;
if ( V_22 )
return V_22 ;
for ( V_3 = 0 ; V_3 < V_12 -> V_26 ; V_3 ++ ) {
struct V_142 * V_59 ;
if ( V_12 -> V_28 [ V_3 ] != & V_12 -> V_31 [ V_3 ] )
continue;
V_59 = V_12 -> V_31 [ V_3 ] . V_39 ;
V_138 = F_45 ( V_67 , V_59 ) ;
if ( V_138 == NULL ) {
F_46 ( V_15 -> V_143 , L_14 , V_59 , V_67 ) ;
return - V_54 ;
}
V_22 = F_44 ( V_15 , V_138 , & V_59 -> V_56 . V_141 ) ;
if ( V_22 )
return V_22 ;
}
return F_47 ( V_15 , V_67 ) ;
}
static int F_48 ( struct V_132 * V_15 ,
struct V_11 * V_127 )
{
struct V_144 * V_145 = V_127 -> V_37 -> V_146 ;
struct V_136 * V_67 = & V_145 -> V_67 ;
int V_22 ;
if ( V_127 -> V_99 == - 1 )
return 0 ;
if ( ( V_127 -> V_63 & V_64 ) == 0 )
return 0 ;
if ( V_127 -> V_98 . V_27 ) {
V_22 = F_49 ( V_15 , V_127 -> V_43 , & V_127 -> V_98 ) ;
if ( V_22 ) {
return V_22 ;
}
}
V_22 = F_49 ( V_15 , V_127 -> V_43 , & V_127 -> V_66 ) ;
if ( V_22 ) {
return V_22 ;
}
if ( V_127 -> V_43 == V_44 )
F_38 ( V_15 ) ;
F_50 ( & V_67 -> V_147 ) ;
V_22 = F_41 ( V_127 , V_67 ) ;
if ( V_22 ) {
goto V_148;
}
V_22 = F_20 ( V_127 ) ;
if ( V_22 ) {
if ( V_22 != - V_134 )
F_11 ( L_11 , V_22 ) ;
goto V_148;
}
F_51 ( V_127 -> V_66 . V_89 , V_67 -> V_129 ) ;
if ( ( V_15 -> V_45 >= V_75 ) &&
( V_127 -> V_101 != - 1 ) ) {
V_22 = F_40 ( V_15 , & V_127 -> V_66 , & V_127 -> V_98 , true ) ;
} else {
V_22 = F_40 ( V_15 , & V_127 -> V_66 , NULL , true ) ;
}
V_148:
F_52 ( & V_67 -> V_147 ) ;
return V_22 ;
}
static int F_53 ( struct V_132 * V_15 , int V_22 )
{
if ( V_22 == - V_149 ) {
V_22 = F_54 ( V_15 ) ;
if ( ! V_22 )
V_22 = - V_150 ;
}
return V_22 ;
}
static int F_55 ( struct V_132 * V_15 , struct V_11 * V_127 )
{
struct V_16 * V_151 ;
struct V_136 * V_67 = NULL ;
int V_22 ;
if ( V_127 -> V_99 == - 1 )
return 0 ;
if ( V_127 -> V_63 & V_64 ) {
struct V_144 * V_145 = V_127 -> V_37 -> V_146 ;
V_67 = & V_145 -> V_67 ;
if ( ( V_15 -> V_45 >= V_75 ) &&
( V_127 -> V_101 != - 1 ) ) {
V_151 = & V_127 -> V_24 [ V_127 -> V_101 ] ;
if ( V_151 -> V_27 > V_152 ) {
F_11 ( L_15 , V_151 -> V_27 ) ;
return - V_54 ;
}
V_22 = F_56 ( V_15 , V_127 -> V_43 , & V_127 -> V_98 ,
V_67 , V_151 -> V_27 * 4 ) ;
if ( V_22 ) {
F_11 ( L_16 ) ;
return V_22 ;
}
V_127 -> V_98 . V_153 = true ;
V_127 -> V_98 . V_27 = V_151 -> V_27 ;
if ( F_24 ( V_127 -> V_98 . V_154 ,
V_151 -> V_115 ,
V_151 -> V_27 * 4 ) )
return - V_103 ;
}
V_151 = & V_127 -> V_24 [ V_127 -> V_99 ] ;
if ( V_151 -> V_27 > V_152 ) {
F_11 ( L_17 , V_151 -> V_27 ) ;
return - V_54 ;
}
}
V_151 = & V_127 -> V_24 [ V_127 -> V_99 ] ;
V_22 = F_56 ( V_15 , V_127 -> V_43 , & V_127 -> V_66 ,
V_67 , V_151 -> V_27 * 4 ) ;
if ( V_22 ) {
F_11 ( L_18 ) ;
return V_22 ;
}
V_127 -> V_66 . V_27 = V_151 -> V_27 ;
if ( V_151 -> V_34 )
memcpy ( V_127 -> V_66 . V_154 , V_151 -> V_34 , V_151 -> V_27 * 4 ) ;
else if ( F_24 ( V_127 -> V_66 . V_154 , V_151 -> V_115 , V_151 -> V_27 * 4 ) )
return - V_103 ;
return 0 ;
}
int F_57 ( struct V_13 * V_143 , void * V_90 , struct V_155 * V_37 )
{
struct V_132 * V_15 = V_143 -> V_156 ;
struct V_11 V_127 ;
int V_22 ;
F_16 ( & V_15 -> V_157 ) ;
if ( ! V_15 -> V_158 ) {
F_18 ( & V_15 -> V_157 ) ;
return - V_159 ;
}
if ( V_15 -> V_160 ) {
F_18 ( & V_15 -> V_157 ) ;
V_22 = F_54 ( V_15 ) ;
if ( ! V_22 )
V_22 = - V_150 ;
return V_22 ;
}
memset ( & V_127 , 0 , sizeof( struct V_11 ) ) ;
V_127 . V_37 = V_37 ;
V_127 . V_15 = V_15 ;
V_127 . V_143 = V_15 -> V_143 ;
V_127 . V_45 = V_15 -> V_45 ;
V_22 = F_23 ( & V_127 , V_90 ) ;
if ( V_22 ) {
F_11 ( L_19 ) ;
F_28 ( & V_127 , V_22 , false ) ;
F_18 ( & V_15 -> V_157 ) ;
V_22 = F_53 ( V_15 , V_22 ) ;
return V_22 ;
}
V_22 = F_55 ( V_15 , & V_127 ) ;
if ( ! V_22 ) {
V_22 = F_8 ( & V_127 ) ;
if ( V_22 && V_22 != - V_134 )
F_11 ( L_20 , V_22 ) ;
}
if ( V_22 ) {
F_28 ( & V_127 , V_22 , false ) ;
F_18 ( & V_15 -> V_157 ) ;
V_22 = F_53 ( V_15 , V_22 ) ;
return V_22 ;
}
F_58 ( & V_127 ) ;
V_22 = F_36 ( V_15 , & V_127 ) ;
if ( V_22 ) {
goto V_148;
}
V_22 = F_48 ( V_15 , & V_127 ) ;
if ( V_22 ) {
goto V_148;
}
V_148:
F_28 ( & V_127 , V_22 , true ) ;
F_18 ( & V_15 -> V_157 ) ;
V_22 = F_53 ( V_15 , V_22 ) ;
return V_22 ;
}
int F_59 ( struct V_11 * V_12 ,
struct V_161 * V_162 ,
unsigned V_96 )
{
struct V_16 * V_151 = & V_12 -> V_24 [ V_12 -> V_99 ] ;
struct V_132 * V_15 = V_12 -> V_15 ;
T_1 V_163 ;
if ( V_96 >= V_151 -> V_27 ) {
F_11 ( L_21 ,
V_96 , V_151 -> V_27 ) ;
return - V_54 ;
}
V_163 = F_60 ( V_12 , V_96 ) ;
V_162 -> V_96 = V_96 ;
V_162 -> type = F_61 ( V_163 ) ;
V_162 -> V_164 = F_62 ( V_163 ) ;
V_162 -> V_165 = 0 ;
switch ( V_162 -> type ) {
case V_166 :
if ( V_15 -> V_45 < V_167 ) {
V_162 -> V_168 = F_63 ( V_163 ) ;
V_162 -> V_165 =
F_64 ( V_163 ) ;
} else
V_162 -> V_168 = F_65 ( V_163 ) ;
break;
case V_169 :
V_162 -> V_170 = F_66 ( V_163 ) ;
break;
case V_171 :
V_162 -> V_164 = - 1 ;
break;
default:
F_11 ( L_22 , V_162 -> type , V_96 ) ;
return - V_54 ;
}
if ( ( V_162 -> V_164 + 1 + V_162 -> V_96 ) >= V_151 -> V_27 ) {
F_11 ( L_23 ,
V_162 -> V_96 , V_162 -> type , V_162 -> V_164 , V_151 -> V_27 ) ;
return - V_54 ;
}
return 0 ;
}
bool F_67 ( struct V_11 * V_12 )
{
struct V_161 V_172 ;
int V_22 ;
V_22 = F_59 ( V_12 , & V_172 , V_12 -> V_96 ) ;
if ( V_22 )
return false ;
if ( V_172 . type != V_169 )
return false ;
if ( V_172 . V_170 != V_173 )
return false ;
return true ;
}
void F_68 ( struct V_11 * V_12 ,
struct V_161 * V_162 )
{
volatile T_1 * V_66 ;
unsigned V_3 ;
unsigned V_96 ;
V_66 = V_12 -> V_66 . V_154 ;
V_96 = V_162 -> V_96 ;
for ( V_3 = 0 ; V_3 <= ( V_162 -> V_164 + 1 ) ; V_3 ++ , V_96 ++ )
F_69 ( L_24 , V_96 , V_66 [ V_96 ] ) ;
}
int F_70 ( struct V_11 * V_12 ,
struct V_32 * * V_174 ,
int V_175 )
{
struct V_16 * V_176 ;
struct V_161 V_172 ;
unsigned V_96 ;
int V_22 ;
if ( V_12 -> V_23 == - 1 ) {
F_11 ( L_25 ) ;
return - V_54 ;
}
* V_174 = NULL ;
V_176 = & V_12 -> V_24 [ V_12 -> V_23 ] ;
V_22 = F_59 ( V_12 , & V_172 , V_12 -> V_96 ) ;
if ( V_22 )
return V_22 ;
V_12 -> V_96 += V_172 . V_164 + 2 ;
if ( V_172 . type != V_169 ||
V_172 . V_170 != V_173 ) {
F_11 ( L_26 ,
V_172 . V_96 ) ;
F_68 ( V_12 , & V_172 ) ;
return - V_54 ;
}
V_96 = F_60 ( V_12 , V_172 . V_96 + 1 ) ;
if ( V_96 >= V_176 -> V_27 ) {
F_11 ( L_27 ,
V_96 , V_176 -> V_27 ) ;
F_68 ( V_12 , & V_172 ) ;
return - V_54 ;
}
if ( V_175 ) {
* V_174 = V_12 -> V_31 ;
( * V_174 ) -> V_177 =
( V_178 ) V_176 -> V_34 [ V_96 + 3 ] << 32 ;
( * V_174 ) -> V_177 |= V_176 -> V_34 [ V_96 + 0 ] ;
} else
* V_174 = V_12 -> V_28 [ ( V_96 / 4 ) ] ;
return 0 ;
}

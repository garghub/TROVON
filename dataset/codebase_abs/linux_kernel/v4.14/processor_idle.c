static int F_1 ( void )
{
return V_1 == V_2 ||
V_1 == V_3 ;
}
static int F_2 ( const struct V_4 * V_5 )
{
if ( V_6 > V_7 )
return 0 ;
F_3 ( L_1
L_2 , V_5 -> V_8 ,
( long ) V_5 -> V_9 , V_7 + 1 ) ;
V_6 = ( long ) V_5 -> V_9 ;
return 0 ;
}
static void T_1 F_4 ( void )
{
if ( ! F_5 () ) {
F_6 () ;
F_7 () ;
}
}
static void F_8 ( int V_10 , struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_12 -> V_17 ;
T_2 type = V_18 ? V_19 : V_20 ;
if ( F_9 ( & F_10 ( V_12 -> V_5 ) , V_21 ) )
return;
if ( F_11 ( V_22 ) )
type = V_23 ;
if ( V_16 -> V_24 < V_10 )
return;
if ( V_14 -> type >= type )
V_12 -> V_17 . V_24 = V_10 ;
}
static void F_12 ( void * V_25 )
{
struct V_11 * V_12 = (struct V_11 * ) V_25 ;
if ( V_12 -> V_17 . V_24 < V_26 )
F_13 () ;
else
F_14 () ;
}
static void F_15 ( struct V_11 * V_12 )
{
F_16 ( V_12 -> V_5 , F_12 ,
( void * ) V_12 , 1 ) ;
}
static void F_17 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
int V_27 )
{
int V_10 = V_14 - V_12 -> V_17 . V_28 ;
if ( V_10 >= V_12 -> V_17 . V_24 ) {
if ( V_27 )
F_18 () ;
else
F_19 () ;
}
}
static void F_8 ( int V_10 , struct V_11 * V_12 ,
struct V_13 * V_29 ) { }
static void F_15 ( struct V_11 * V_12 ) { }
static void F_17 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
int V_27 )
{
}
static void F_20 ( int V_10 )
{
switch ( V_30 . V_31 ) {
case V_32 :
case V_33 :
if ( F_21 ( V_34 ) )
return;
default:
if ( V_10 > V_23 )
F_22 ( L_3 ) ;
}
}
static void F_20 ( int V_10 ) { return; }
static int F_23 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_35 )
return - V_36 ;
V_12 -> V_17 . V_28 [ V_20 ] . type = V_20 ;
V_12 -> V_17 . V_28 [ V_19 ] . type = V_19 ;
#ifndef F_24
if ( ( F_25 () > 1 ) &&
! ( V_37 . V_38 & V_39 ) )
return - V_36 ;
#endif
V_12 -> V_17 . V_28 [ V_20 ] . V_40 = V_12 -> V_35 + 4 ;
V_12 -> V_17 . V_28 [ V_19 ] . V_40 = V_12 -> V_35 + 5 ;
V_12 -> V_17 . V_28 [ V_20 ] . V_41 = V_37 . V_42 ;
V_12 -> V_17 . V_28 [ V_19 ] . V_41 = V_37 . V_43 ;
if ( V_37 . V_42 > V_44 ) {
F_26 ( ( V_45 ,
L_4 , V_37 . V_42 ) ) ;
V_12 -> V_17 . V_28 [ V_20 ] . V_40 = 0 ;
}
if ( V_37 . V_43 > V_46 ) {
F_26 ( ( V_45 ,
L_5 , V_37 . V_43 ) ) ;
V_12 -> V_17 . V_28 [ V_19 ] . V_40 = 0 ;
}
F_26 ( ( V_45 ,
L_6 ,
V_12 -> V_17 . V_28 [ V_20 ] . V_40 ,
V_12 -> V_17 . V_28 [ V_19 ] . V_40 ) ) ;
return 0 ;
}
static int F_27 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_17 . V_28 [ V_23 ] . V_47 ) {
V_12 -> V_17 . V_28 [ V_23 ] . type = V_23 ;
V_12 -> V_17 . V_28 [ V_23 ] . V_47 = 1 ;
V_12 -> V_17 . V_28 [ V_23 ] . V_48 = V_49 ;
}
V_12 -> V_17 . V_28 [ V_50 ] . V_47 = 1 ;
return 0 ;
}
static int F_28 ( struct V_11 * V_12 )
{
T_3 V_51 ;
T_4 V_52 ;
int V_53 ;
int V_54 , V_55 = 0 ;
struct V_56 V_57 = { V_58 , NULL } ;
union V_59 * V_60 ;
if ( V_61 )
return - V_36 ;
V_53 = 0 ;
V_51 = F_29 ( V_12 -> V_62 , L_7 , NULL , & V_57 ) ;
if ( F_30 ( V_51 ) ) {
F_26 ( ( V_45 , L_8 ) ) ;
return - V_36 ;
}
V_60 = V_57 . V_63 ;
if ( ! V_60 || ( V_60 -> type != V_64 ) || V_60 -> V_65 . V_52 < 2 ) {
F_31 ( L_9 ) ;
V_55 = - V_66 ;
goto V_67;
}
V_52 = V_60 -> V_65 . V_68 [ 0 ] . integer . V_69 ;
if ( V_52 < 1 || V_52 != V_60 -> V_65 . V_52 - 1 ) {
F_31 ( L_10 ) ;
V_55 = - V_66 ;
goto V_67;
}
V_12 -> V_38 . V_70 = 1 ;
for ( V_54 = 1 ; V_54 <= V_52 ; V_54 ++ ) {
union V_59 * V_71 ;
union V_59 * V_72 ;
struct V_73 * V_74 ;
struct V_13 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_71 = & ( V_60 -> V_65 . V_68 [ V_54 ] ) ;
if ( V_71 -> type != V_64 )
continue;
if ( V_71 -> V_65 . V_52 != 4 )
continue;
V_72 = & ( V_71 -> V_65 . V_68 [ 0 ] ) ;
if ( V_72 -> type != V_75 )
continue;
V_74 = (struct V_73 * ) V_72 -> V_57 . V_63 ;
if ( V_74 -> V_76 != V_77 &&
( V_74 -> V_76 != V_78 ) )
continue;
V_72 = & ( V_71 -> V_65 . V_68 [ 1 ] ) ;
if ( V_72 -> type != V_79 )
continue;
V_14 . type = V_72 -> integer . V_69 ;
if ( V_54 == 1 && V_14 . type != V_23 )
V_53 ++ ;
V_14 . V_40 = V_74 -> V_40 ;
V_14 . V_80 = V_53 + 1 ;
V_14 . V_48 = V_81 ;
if ( V_74 -> V_76 == V_78 ) {
if ( F_32
( V_12 -> V_5 , & V_14 , V_74 ) == 0 ) {
V_14 . V_48 = V_82 ;
} else if ( V_14 . type == V_23 ) {
V_14 . V_48 = V_49 ;
snprintf ( V_14 . V_83 , V_84 , L_11 ) ;
} else {
continue;
}
if ( V_14 . type == V_23 &&
( V_1 == V_85 ) ) {
V_14 . V_48 = V_49 ;
snprintf ( V_14 . V_83 , V_84 , L_11 ) ;
}
} else {
snprintf ( V_14 . V_83 , V_84 , L_12 ,
V_14 . V_40 ) ;
}
if ( V_14 . type == V_23 ) {
V_14 . V_47 = 1 ;
}
V_72 = & ( V_71 -> V_65 . V_68 [ 2 ] ) ;
if ( V_72 -> type != V_79 )
continue;
V_14 . V_41 = V_72 -> integer . V_69 ;
V_72 = & ( V_71 -> V_65 . V_68 [ 3 ] ) ;
if ( V_72 -> type != V_79 )
continue;
V_53 ++ ;
memcpy ( & ( V_12 -> V_17 . V_28 [ V_53 ] ) , & V_14 , sizeof( V_14 ) ) ;
if ( V_53 >= ( V_7 - 1 ) ) {
F_33 ( L_13 ,
V_7 ) ;
F_33 ( L_14 ) ;
break;
}
}
F_26 ( ( V_45 , L_15 ,
V_53 ) ) ;
if ( V_53 < 2 )
V_55 = - V_66 ;
V_67:
F_34 ( V_57 . V_63 ) ;
return V_55 ;
}
static void F_35 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
static int V_86 = - 1 ;
static int V_87 = - 1 ;
if ( ! V_14 -> V_40 )
return;
else if ( V_88 . V_89 . V_90 ) {
F_26 ( ( V_45 ,
L_16 ) ) ;
return;
}
if ( V_86 == - 1 ) {
F_36 ( & ( V_12 -> V_38 ) , V_12 -> V_5 ) ;
V_86 = V_12 -> V_38 . V_91 ;
V_87 = V_12 -> V_38 . V_92 ;
} else {
V_12 -> V_38 . V_91 = V_86 ;
V_12 -> V_38 . V_92 = V_87 ;
}
if ( V_12 -> V_38 . V_91 ) {
if ( ! V_12 -> V_38 . V_92 ) {
if ( V_12 -> V_38 . V_70 != 1 ) {
F_26 ( ( V_45 ,
L_17 ) ) ;
return;
} else {
F_26 ( ( V_45 ,
L_18 ) ) ;
}
}
} else {
if ( ! ( V_37 . V_38 & V_93 ) ) {
F_26 ( ( V_45 ,
L_19
L_20 ) ) ;
return;
}
}
V_14 -> V_47 = 1 ;
F_37 ( V_94 , 1 ) ;
return;
}
static int F_38 ( struct V_11 * V_12 )
{
unsigned int V_54 ;
unsigned int V_95 = 0 ;
V_12 -> V_17 . V_24 = V_26 ;
for ( V_54 = 1 ; V_54 < V_7 && V_54 <= V_6 ; V_54 ++ ) {
struct V_13 * V_14 = & V_12 -> V_17 . V_28 [ V_54 ] ;
switch ( V_14 -> type ) {
case V_23 :
V_14 -> V_47 = 1 ;
break;
case V_20 :
if ( ! V_14 -> V_40 )
break;
V_14 -> V_47 = 1 ;
break;
case V_19 :
F_35 ( V_12 , V_14 ) ;
break;
}
if ( ! V_14 -> V_47 )
continue;
F_8 ( V_54 , V_12 , V_14 ) ;
F_20 ( V_14 -> type ) ;
V_95 ++ ;
}
F_15 ( V_12 ) ;
return ( V_95 ) ;
}
static int F_39 ( struct V_11 * V_12 )
{
unsigned int V_54 ;
int V_96 ;
memset ( V_12 -> V_17 . V_28 , 0 , sizeof( V_12 -> V_17 . V_28 ) ) ;
V_96 = F_28 ( V_12 ) ;
if ( V_96 == - V_36 )
V_96 = F_23 ( V_12 ) ;
if ( V_96 )
return V_96 ;
F_27 ( V_12 ) ;
V_12 -> V_17 . V_52 = F_38 ( V_12 ) ;
for ( V_54 = 1 ; V_54 < V_7 ; V_54 ++ ) {
if ( V_12 -> V_17 . V_28 [ V_54 ] . V_47 ) {
V_12 -> V_17 . V_52 = V_54 ;
if ( V_12 -> V_17 . V_28 [ V_54 ] . type >= V_20 )
V_12 -> V_38 . V_17 = 1 ;
}
}
return 0 ;
}
static int F_40 ( void )
{
T_5 V_97 = 0 ;
if ( V_98 )
return 0 ;
F_41 ( V_99 , & V_97 ) ;
if ( V_97 )
F_37 ( V_99 , 1 ) ;
else if ( V_88 . V_89 . V_100 ) {
if ( ( F_42 ( V_88 . V_89 . V_100 + 0x02 ) & 0x01 )
|| ( F_42 ( V_88 . V_89 . V_100 + 0x0A ) & 0x01 ) )
V_97 = 1 ;
}
return V_97 ;
}
static void T_1 F_43 ( struct V_13 * V_14 )
{
if ( V_14 -> V_48 == V_82 ) {
F_44 ( V_14 ) ;
} else if ( V_14 -> V_48 == V_49 ) {
F_4 () ;
} else {
F_45 ( V_14 -> V_40 ) ;
F_46 ( V_37 . V_101 . V_40 ) ;
}
}
static int F_47 ( struct V_102 * V_103 , int V_80 )
{
struct V_13 * V_14 = F_48 ( V_104 [ V_80 ] , V_103 -> V_105 ) ;
F_49 () ;
while ( 1 ) {
if ( V_14 -> V_48 == V_49 )
F_6 () ;
else if ( V_14 -> V_48 == V_81 ) {
F_45 ( V_14 -> V_40 ) ;
F_46 ( V_37 . V_101 . V_40 ) ;
} else
return - V_36 ;
}
return 0 ;
}
static bool F_50 ( struct V_11 * V_12 )
{
return F_51 ( F_24 ) && ! V_12 -> V_38 . V_70 &&
! ( V_37 . V_38 & V_39 ) ;
}
static void F_52 ( struct V_11 * V_12 ,
struct V_13 * V_14 , bool V_106 )
{
F_53 ( F_54 () ) ;
if ( V_106 )
F_17 ( V_12 , V_14 , 1 ) ;
if ( V_12 -> V_38 . V_92 ) {
F_55 ( & V_107 ) ;
V_108 ++ ;
if ( V_108 == F_25 () )
F_37 ( V_109 , 1 ) ;
F_56 ( & V_107 ) ;
}
F_43 ( V_14 ) ;
if ( V_12 -> V_38 . V_92 ) {
F_55 ( & V_107 ) ;
F_37 ( V_109 , 0 ) ;
V_108 -- ;
F_56 ( & V_107 ) ;
}
if ( V_106 )
F_17 ( V_12 , V_14 , 0 ) ;
}
static int F_57 ( struct V_102 * V_103 ,
struct V_110 * V_111 , int V_80 )
{
struct V_13 * V_14 = F_48 ( V_104 [ V_80 ] , V_103 -> V_105 ) ;
struct V_11 * V_12 ;
V_12 = F_58 ( V_112 ) ;
if ( F_59 ( ! V_12 ) )
return - V_113 ;
if ( V_14 -> type != V_23 ) {
if ( F_50 ( V_12 ) && F_25 () > 1 ) {
V_80 = V_114 ;
V_14 = F_48 ( V_104 [ V_80 ] , V_103 -> V_105 ) ;
} else if ( V_14 -> type == V_19 && V_12 -> V_38 . V_91 ) {
if ( V_14 -> V_115 || ! F_40 () ) {
F_52 ( V_12 , V_14 , true ) ;
return V_80 ;
} else if ( V_111 -> V_116 >= 0 ) {
V_80 = V_111 -> V_116 ;
V_14 = F_48 ( V_104 [ V_80 ] , V_103 -> V_105 ) ;
} else {
F_4 () ;
return - V_117 ;
}
}
}
F_17 ( V_12 , V_14 , 1 ) ;
if ( V_14 -> type == V_19 )
F_49 () ;
F_43 ( V_14 ) ;
F_17 ( V_12 , V_14 , 0 ) ;
return V_80 ;
}
static void F_60 ( struct V_102 * V_103 ,
struct V_110 * V_111 , int V_80 )
{
struct V_13 * V_14 = F_48 ( V_104 [ V_80 ] , V_103 -> V_105 ) ;
if ( V_14 -> type == V_19 ) {
struct V_11 * V_12 = F_58 ( V_112 ) ;
if ( F_59 ( ! V_12 ) )
return;
if ( V_12 -> V_38 . V_91 ) {
F_52 ( V_12 , V_14 , false ) ;
return;
} else {
F_49 () ;
}
}
F_43 ( V_14 ) ;
}
static int F_61 ( struct V_11 * V_12 ,
struct V_102 * V_103 )
{
int V_54 , V_52 = V_114 ;
struct V_13 * V_14 ;
if ( V_6 == 0 )
V_6 = 1 ;
for ( V_54 = 1 ; V_54 < V_7 && V_54 <= V_6 ; V_54 ++ ) {
V_14 = & V_12 -> V_17 . V_28 [ V_54 ] ;
if ( ! V_14 -> V_47 )
continue;
F_48 ( V_104 [ V_52 ] , V_103 -> V_105 ) = V_14 ;
V_52 ++ ;
if ( V_52 == V_118 )
break;
}
if ( ! V_52 )
return - V_113 ;
return 0 ;
}
static int F_62 ( struct V_11 * V_12 )
{
int V_54 , V_52 ;
struct V_13 * V_14 ;
struct V_119 * V_10 ;
struct V_110 * V_111 = & V_120 ;
if ( V_6 == 0 )
V_6 = 1 ;
if ( F_51 ( V_121 ) ) {
F_63 ( V_111 ) ;
V_52 = 1 ;
} else {
V_52 = 0 ;
}
for ( V_54 = 1 ; V_54 < V_7 && V_54 <= V_6 ; V_54 ++ ) {
V_14 = & V_12 -> V_17 . V_28 [ V_54 ] ;
if ( ! V_14 -> V_47 )
continue;
V_10 = & V_111 -> V_28 [ V_52 ] ;
snprintf ( V_10 -> V_122 , V_123 , L_21 , V_54 ) ;
F_64 ( V_10 -> V_83 , V_14 -> V_83 , V_124 ) ;
V_10 -> V_125 = V_14 -> V_41 ;
V_10 -> V_126 = V_14 -> V_41 * V_127 ;
V_10 -> V_128 = F_57 ;
V_10 -> V_38 = 0 ;
if ( V_14 -> type == V_23 || V_14 -> type == V_20 ) {
V_10 -> V_129 = F_47 ;
V_111 -> V_116 = V_52 ;
}
if ( V_14 -> type != V_23 && ! F_50 ( V_12 ) )
V_10 -> V_130 = F_60 ;
V_52 ++ ;
if ( V_52 == V_118 )
break;
}
V_111 -> V_131 = V_52 ;
if ( ! V_52 )
return - V_113 ;
return 0 ;
}
static inline void F_65 ( void )
{
T_3 V_51 ;
static int V_132 ;
if ( V_132 )
return;
F_66 ( V_133 ) ;
V_6 = F_67 ( V_6 ) ;
if ( V_6 < V_134 )
F_3 ( L_22 ,
V_6 ) ;
V_132 ++ ;
if ( V_37 . V_135 && ! V_61 ) {
V_51 = F_68 ( V_37 . V_136 ,
V_37 . V_135 , 8 ) ;
if ( F_30 ( V_51 ) )
F_69 ( ( V_137 , V_51 ,
L_23 ) ) ;
}
}
static inline int F_1 ( void ) { return 0 ; }
static inline void F_65 ( void ) { }
static int F_39 ( struct V_11 * V_12 )
{
return - V_36 ;
}
static int F_61 ( struct V_11 * V_12 ,
struct V_102 * V_103 )
{
return - V_113 ;
}
static int F_62 ( struct V_11 * V_12 )
{
return - V_113 ;
}
static int F_70 ( union V_59 * V_72 , T_5 * V_69 )
{
if ( V_72 -> type != V_79 )
return - V_113 ;
* V_69 = V_72 -> integer . V_69 ;
return 0 ;
}
static int F_71 ( T_6 V_62 ,
struct V_138 * V_139 )
{
T_3 V_51 ;
int V_55 = 0 ;
int V_140 , V_141 = 1 , V_142 ;
struct V_56 V_57 = { V_58 , NULL } ;
union V_59 * V_143 ;
struct V_144 * V_145 ;
V_51 = F_29 ( V_62 , L_24 , NULL , & V_57 ) ;
if ( F_30 ( V_51 ) ) {
F_26 ( ( V_45 , L_25 ) ) ;
return - V_36 ;
}
V_143 = V_57 . V_63 ;
if ( ! V_143 || V_143 -> type != V_64 ||
V_143 -> V_65 . V_52 < 4 ) {
F_72 ( L_26 ) ;
V_55 = - V_146 ;
goto V_67;
}
V_140 = V_143 -> V_65 . V_68 [ 2 ] . integer . V_69 ;
if ( V_140 < 1 || V_140 != V_143 -> V_65 . V_52 - 3 ) {
F_72 ( L_27 ) ;
V_55 = - V_146 ;
goto V_67;
}
V_145 = F_73 ( V_140 , sizeof( * V_145 ) , V_147 ) ;
if ( ! V_145 ) {
V_55 = - V_148 ;
goto V_67;
}
V_139 -> V_149 = V_140 ;
V_139 -> V_150 = V_145 ;
for ( V_142 = 3 ; V_141 <= V_140 ; V_142 ++ , V_141 ++ , V_145 ++ ) {
union V_59 * V_71 , * V_151 , * V_72 ;
V_71 = & V_143 -> V_65 . V_68 [ V_142 ] ;
if ( V_71 -> type != V_64 || V_71 -> V_65 . V_52 < 7 )
continue;
V_151 = V_71 -> V_65 . V_68 ;
V_72 = V_151 + 6 ;
if ( V_72 -> type == V_75 ) {
struct V_73 * V_74 ;
V_74 = (struct V_73 * ) V_72 -> V_57 . V_63 ;
if ( V_74 -> V_76 != V_77 &&
V_74 -> V_76 != V_78 )
continue;
V_145 -> V_40 = V_74 -> V_40 ;
V_145 -> V_48 =
V_74 -> V_76 == V_78 ?
V_82 : V_81 ;
} else if ( V_72 -> type == V_79 ) {
V_145 -> V_48 = V_152 ;
V_145 -> V_40 = V_72 -> integer . V_69 ;
} else {
continue;
}
V_72 = V_151 + 9 ;
if ( V_72 -> type == V_153 )
F_64 ( V_145 -> V_83 , V_72 -> string . V_63 ,
V_84 ) ;
V_145 -> V_80 = V_141 ;
if ( F_70 ( V_151 + 0 , & V_145 -> V_154 ) ) {
F_72 ( L_28 ) ;
V_145 -> V_154 = 10 ;
}
if ( F_70 ( V_151 + 1 , & V_145 -> V_155 ) ) {
F_72 ( L_29 ) ;
V_145 -> V_155 = 10 ;
}
if ( F_70 ( V_151 + 2 , & V_145 -> V_38 ) )
V_145 -> V_38 = 0 ;
if ( F_70 ( V_151 + 3 , & V_145 -> V_156 ) )
V_145 -> V_156 = 0 ;
if ( F_70 ( V_151 + 4 , & V_145 -> V_157 ) )
V_145 -> V_157 = 1 ;
if ( F_70 ( V_151 + 5 , & V_145 -> V_158 ) )
V_145 -> V_158 = 0 ;
}
F_74 ( V_62 , L_15 , V_141 ) ;
V_67:
F_34 ( V_57 . V_63 ) ;
return V_55 ;
}
static bool F_75 ( struct V_144 * V_159 ,
struct V_144 * V_160 ,
struct V_144 * V_96 )
{
if ( V_160 -> V_48 == V_152 ) {
if ( ! V_160 -> V_40 )
return false ;
V_96 -> V_40 = V_159 -> V_40 + V_160 -> V_40 ;
} else {
V_96 -> V_40 = V_160 -> V_40 ;
}
V_96 -> V_154 = F_76 ( V_159 -> V_154 , V_160 -> V_154 ) ;
V_96 -> V_155 = V_159 -> V_155 + V_160 -> V_155 ;
V_96 -> V_158 = V_160 -> V_158 ;
V_96 -> V_48 = V_159 -> V_48 ;
V_96 -> V_38 = V_160 -> V_38 ;
V_96 -> V_156 = V_160 -> V_156 ;
V_96 -> V_80 = V_160 -> V_80 ;
F_64 ( V_96 -> V_83 , V_159 -> V_83 , V_84 ) ;
F_77 ( V_96 -> V_83 , L_30 , V_84 ) ;
F_77 ( V_96 -> V_83 , V_160 -> V_83 , V_84 ) ;
return true ;
}
static void F_78 ( struct V_138 * V_161 ,
struct V_144 * V_162 )
{
V_161 -> V_163 [ V_161 -> V_164 ++ ] = V_162 ;
}
static int F_79 ( struct V_11 * V_12 ,
struct V_138 * V_161 ,
struct V_138 * V_165 )
{
int V_54 , V_166 , V_131 = V_161 -> V_149 ;
struct V_144 * V_167 , * V_162 = V_161 -> V_150 ;
V_161 -> V_164 = 0 ;
for ( V_166 = 0 ; V_166 < V_131 ; V_166 ++ , V_162 ++ ) {
struct V_144 * V_168 ;
if ( ! ( V_162 -> V_38 & V_169 ) )
continue;
if ( V_170 >= V_7 ) {
F_33 ( L_31 ,
V_7 ) ;
F_33 ( L_14 ) ;
break;
}
V_168 = & V_12 -> V_17 . V_171 [ V_170 ] ;
if ( ! V_165 ) {
memcpy ( V_168 , V_162 , sizeof( * V_162 ) ) ;
F_78 ( V_161 , V_168 ) ;
V_170 ++ ;
continue;
}
for ( V_54 = 0 ; V_54 < V_165 -> V_164 ; V_54 ++ ) {
V_167 = V_165 -> V_163 [ V_54 ] ;
if ( V_162 -> V_80 <= V_167 -> V_158 &&
F_75 ( V_167 , V_162 , V_168 ) ) {
F_78 ( V_161 , V_168 ) ;
V_170 ++ ;
V_168 ++ ;
}
}
}
F_34 ( V_161 -> V_150 ) ;
return 0 ;
}
static int F_80 ( struct V_11 * V_12 )
{
int V_55 , V_54 ;
T_3 V_51 ;
T_6 V_62 = V_12 -> V_62 , V_172 ;
struct V_173 * V_174 = NULL ;
struct V_138 V_139 [ 2 ] , * V_175 , * V_176 , * V_177 ;
if ( ! V_178 )
return - V_179 ;
if ( ! F_81 ( V_62 , L_24 ) )
return - V_113 ;
V_170 = 0 ;
V_176 = & V_139 [ 0 ] ;
V_177 = & V_139 [ 1 ] ;
V_62 = V_12 -> V_62 ;
V_55 = F_71 ( V_62 , V_176 ) ;
if ( V_55 )
return V_55 ;
F_79 ( V_12 , V_176 , NULL ) ;
V_51 = F_82 ( V_62 , & V_172 ) ;
while ( F_83 ( V_51 ) ) {
F_84 ( V_172 , & V_174 ) ;
V_62 = V_172 ;
if ( strcmp ( F_85 ( V_174 ) , V_180 ) )
break;
if ( ! F_81 ( V_62 , L_24 ) )
break;
V_55 = F_71 ( V_62 , V_177 ) ;
if ( V_55 )
break;
F_79 ( V_12 , V_177 , V_176 ) ;
V_175 = V_176 , V_176 = V_177 , V_177 = V_175 ;
V_51 = F_82 ( V_62 , & V_172 ) ;
}
V_12 -> V_17 . V_52 = V_170 ;
for ( V_54 = 0 ; V_54 < V_12 -> V_17 . V_52 ; V_54 ++ )
V_12 -> V_17 . V_171 [ V_54 ] . V_80 = V_54 ;
V_12 -> V_38 . V_181 = 1 ;
V_12 -> V_38 . V_17 = 1 ;
return 0 ;
}
int __weak F_86 ( unsigned int V_105 )
{
return - V_36 ;
}
int __weak F_87 ( struct V_144 * V_182 )
{
return - V_36 ;
}
static int F_88 ( struct V_102 * V_103 ,
struct V_110 * V_111 , int V_80 )
{
struct V_11 * V_12 ;
struct V_144 * V_182 ;
V_12 = F_58 ( V_112 ) ;
if ( F_59 ( ! V_12 ) )
return - V_113 ;
V_182 = & V_12 -> V_17 . V_171 [ V_80 ] ;
if ( V_182 -> V_48 == V_82 )
return F_87 ( V_182 ) ;
return - V_113 ;
}
static int F_89 ( struct V_11 * V_12 )
{
int V_54 ;
struct V_144 * V_182 ;
struct V_119 * V_10 ;
struct V_110 * V_111 = & V_120 ;
if ( ! V_12 -> V_38 . V_181 )
return - V_179 ;
for ( V_54 = 0 ; V_54 < V_12 -> V_17 . V_52 && V_54 < V_118 ; V_54 ++ ) {
V_182 = & V_12 -> V_17 . V_171 [ V_54 ] ;
V_10 = & V_111 -> V_28 [ V_54 ] ;
snprintf ( V_10 -> V_122 , V_123 , L_32 , V_54 ) ;
F_64 ( V_10 -> V_83 , V_182 -> V_83 , V_124 ) ;
V_10 -> V_125 = V_182 -> V_155 ;
V_10 -> V_126 = V_182 -> V_154 ;
if ( V_182 -> V_156 )
V_10 -> V_38 |= V_183 ;
V_10 -> V_128 = F_88 ;
V_111 -> V_116 = V_54 ;
}
V_111 -> V_131 = V_54 ;
return 0 ;
}
static int F_90 ( struct V_11 * V_12 )
{
int V_54 ;
struct V_110 * V_111 = & V_120 ;
if ( ! V_12 -> V_38 . V_184 || ! V_12 -> V_38 . V_17 )
return - V_113 ;
V_111 -> V_116 = - 1 ;
for ( V_54 = V_114 ; V_54 < V_118 ; V_54 ++ ) {
V_111 -> V_28 [ V_54 ] . V_122 [ 0 ] = '\0' ;
V_111 -> V_28 [ V_54 ] . V_83 [ 0 ] = '\0' ;
}
if ( V_12 -> V_38 . V_181 )
return F_89 ( V_12 ) ;
return F_62 ( V_12 ) ;
}
static int F_91 ( struct V_11 * V_12 ,
struct V_102 * V_103 )
{
if ( ! V_12 -> V_38 . V_184 || ! V_12 -> V_38 . V_17 || ! V_103 )
return - V_113 ;
V_103 -> V_105 = V_12 -> V_5 ;
if ( V_12 -> V_38 . V_181 )
return F_86 ( V_12 -> V_5 ) ;
return F_61 ( V_12 , V_103 ) ;
}
static int F_92 ( struct V_11 * V_12 )
{
int V_55 ;
V_55 = F_80 ( V_12 ) ;
if ( V_55 )
V_55 = F_39 ( V_12 ) ;
return V_55 ;
}
int F_93 ( struct V_11 * V_12 )
{
int V_55 = 0 ;
struct V_102 * V_103 ;
if ( F_1 () )
return 0 ;
if ( ! V_12 -> V_38 . V_184 )
return - V_36 ;
V_103 = F_48 ( V_185 , V_12 -> V_5 ) ;
F_94 () ;
F_95 ( V_103 ) ;
V_55 = F_92 ( V_12 ) ;
if ( ! V_55 && V_12 -> V_38 . V_17 ) {
F_91 ( V_12 , V_103 ) ;
V_55 = F_96 ( V_103 ) ;
}
F_97 () ;
return V_55 ;
}
int F_98 ( struct V_11 * V_12 )
{
int V_105 ;
struct V_11 * V_186 ;
struct V_102 * V_103 ;
if ( F_1 () )
return 0 ;
if ( ! V_12 -> V_38 . V_184 )
return - V_36 ;
if ( V_12 -> V_5 == 0 && F_99 () == & V_120 ) {
F_100 () ;
F_94 () ;
F_101 (cpu) {
V_186 = F_48 ( V_112 , V_105 ) ;
if ( ! V_186 || ! V_186 -> V_38 . V_184 )
continue;
V_103 = F_48 ( V_185 , V_105 ) ;
F_95 ( V_103 ) ;
}
F_92 ( V_12 ) ;
F_90 ( V_12 ) ;
F_101 (cpu) {
V_186 = F_48 ( V_112 , V_105 ) ;
if ( ! V_186 || ! V_186 -> V_38 . V_184 )
continue;
F_92 ( V_186 ) ;
if ( V_186 -> V_38 . V_17 ) {
V_103 = F_48 ( V_185 , V_105 ) ;
F_91 ( V_186 , V_103 ) ;
F_96 ( V_103 ) ;
}
}
F_97 () ;
F_102 () ;
}
return 0 ;
}
int F_103 ( struct V_11 * V_12 )
{
int V_187 ;
struct V_102 * V_103 ;
if ( F_1 () )
return 0 ;
F_65 () ;
if ( ! F_92 ( V_12 ) )
V_12 -> V_38 . V_184 = 1 ;
if ( V_12 -> V_38 . V_17 ) {
if ( ! V_188 ) {
F_90 ( V_12 ) ;
V_187 = F_104 ( & V_120 ) ;
if ( V_187 )
return V_187 ;
F_72 ( L_33 ,
V_120 . V_122 ) ;
}
V_103 = F_105 ( sizeof( * V_103 ) , V_147 ) ;
if ( ! V_103 )
return - V_148 ;
F_48 ( V_185 , V_12 -> V_5 ) = V_103 ;
F_91 ( V_12 , V_103 ) ;
V_187 = F_106 ( V_103 ) ;
if ( V_187 ) {
if ( V_188 == 0 )
F_107 ( & V_120 ) ;
return V_187 ;
}
V_188 ++ ;
}
return 0 ;
}
int F_108 ( struct V_11 * V_12 )
{
struct V_102 * V_103 = F_48 ( V_185 , V_12 -> V_5 ) ;
if ( F_1 () )
return 0 ;
if ( V_12 -> V_38 . V_17 ) {
F_109 ( V_103 ) ;
V_188 -- ;
if ( V_188 == 0 )
F_107 ( & V_120 ) ;
}
V_12 -> V_38 . V_184 = 0 ;
return 0 ;
}

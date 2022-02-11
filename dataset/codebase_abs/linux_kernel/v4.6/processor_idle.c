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
static void F_4 ( void )
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
T_1 type = V_18 ? V_19 : V_20 ;
if ( F_9 ( & F_10 ( V_12 -> V_5 ) , V_21 ) )
return;
if ( V_22 )
type = V_23 ;
if ( V_16 -> V_24 < V_10 )
return;
if ( V_14 -> type >= type )
V_12 -> V_17 . V_24 = V_10 ;
}
static void F_11 ( void * V_25 )
{
struct V_11 * V_12 = (struct V_11 * ) V_25 ;
if ( V_12 -> V_17 . V_24 < V_26 )
F_12 () ;
else
F_13 () ;
}
static void F_14 ( struct V_11 * V_12 )
{
F_15 ( V_12 -> V_5 , F_11 ,
( void * ) V_12 , 1 ) ;
}
static void F_16 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
int V_27 )
{
int V_10 = V_14 - V_12 -> V_17 . V_28 ;
if ( V_10 >= V_12 -> V_17 . V_24 ) {
if ( V_27 )
F_17 () ;
else
F_18 () ;
}
}
static void F_8 ( int V_10 , struct V_11 * V_12 ,
struct V_13 * V_29 ) { }
static void F_14 ( struct V_11 * V_12 ) { }
static void F_16 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
int V_27 )
{
}
static void F_19 ( int V_10 )
{
switch ( V_30 . V_31 ) {
case V_32 :
case V_33 :
if ( F_20 ( V_34 ) )
return;
default:
if ( V_10 > V_23 )
F_21 ( L_3 ) ;
}
}
static void F_19 ( int V_10 ) { return; }
static int F_22 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_35 )
return - V_36 ;
V_12 -> V_17 . V_28 [ V_20 ] . type = V_20 ;
V_12 -> V_17 . V_28 [ V_19 ] . type = V_19 ;
#ifndef F_23
if ( ( F_24 () > 1 ) &&
! ( V_37 . V_38 & V_39 ) )
return - V_36 ;
#endif
V_12 -> V_17 . V_28 [ V_20 ] . V_40 = V_12 -> V_35 + 4 ;
V_12 -> V_17 . V_28 [ V_19 ] . V_40 = V_12 -> V_35 + 5 ;
V_12 -> V_17 . V_28 [ V_20 ] . V_41 = V_37 . V_42 ;
V_12 -> V_17 . V_28 [ V_19 ] . V_41 = V_37 . V_43 ;
if ( V_37 . V_42 > V_44 ) {
F_25 ( ( V_45 ,
L_4 , V_37 . V_42 ) ) ;
V_12 -> V_17 . V_28 [ V_20 ] . V_40 = 0 ;
}
if ( V_37 . V_43 > V_46 ) {
F_25 ( ( V_45 ,
L_5 , V_37 . V_43 ) ) ;
V_12 -> V_17 . V_28 [ V_19 ] . V_40 = 0 ;
}
F_25 ( ( V_45 ,
L_6 ,
V_12 -> V_17 . V_28 [ V_20 ] . V_40 ,
V_12 -> V_17 . V_28 [ V_19 ] . V_40 ) ) ;
return 0 ;
}
static int F_26 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_17 . V_28 [ V_23 ] . V_47 ) {
V_12 -> V_17 . V_28 [ V_23 ] . type = V_23 ;
V_12 -> V_17 . V_28 [ V_23 ] . V_47 = 1 ;
V_12 -> V_17 . V_28 [ V_23 ] . V_48 = V_49 ;
}
V_12 -> V_17 . V_28 [ V_50 ] . V_47 = 1 ;
return 0 ;
}
static int F_27 ( struct V_11 * V_12 )
{
T_2 V_51 ;
T_3 V_52 ;
int V_53 ;
int V_54 , V_55 = 0 ;
struct V_56 V_57 = { V_58 , NULL } ;
union V_59 * V_60 ;
if ( V_61 )
return - V_36 ;
V_53 = 0 ;
V_51 = F_28 ( V_12 -> V_62 , L_7 , NULL , & V_57 ) ;
if ( F_29 ( V_51 ) ) {
F_25 ( ( V_45 , L_8 ) ) ;
return - V_36 ;
}
V_60 = V_57 . V_63 ;
if ( ! V_60 || ( V_60 -> type != V_64 ) || V_60 -> V_65 . V_52 < 2 ) {
F_30 ( L_9 ) ;
V_55 = - V_66 ;
goto V_67;
}
V_52 = V_60 -> V_65 . V_68 [ 0 ] . integer . V_69 ;
if ( V_52 < 1 || V_52 != V_60 -> V_65 . V_52 - 1 ) {
F_30 ( L_10 ) ;
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
if ( F_31
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
F_32 ( L_13 ,
V_7 ) ;
F_32 ( L_14 ) ;
break;
}
}
F_25 ( ( V_45 , L_15 ,
V_53 ) ) ;
if ( V_53 < 2 )
V_55 = - V_66 ;
V_67:
F_33 ( V_57 . V_63 ) ;
return V_55 ;
}
static void F_34 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
static int V_86 = - 1 ;
static int V_87 = - 1 ;
if ( ! V_14 -> V_40 )
return;
else if ( V_88 . V_89 . V_90 ) {
F_25 ( ( V_45 ,
L_16 ) ) ;
return;
}
if ( V_86 == - 1 ) {
F_35 ( & ( V_12 -> V_38 ) , V_12 -> V_5 ) ;
V_86 = V_12 -> V_38 . V_91 ;
V_87 = V_12 -> V_38 . V_92 ;
} else {
V_12 -> V_38 . V_91 = V_86 ;
V_12 -> V_38 . V_92 = V_87 ;
}
if ( V_12 -> V_38 . V_91 ) {
if ( ! V_12 -> V_38 . V_92 ) {
if ( V_12 -> V_38 . V_70 != 1 ) {
F_25 ( ( V_45 ,
L_17 ) ) ;
return;
} else {
F_25 ( ( V_45 ,
L_18 ) ) ;
}
}
} else {
if ( ! ( V_37 . V_38 & V_93 ) ) {
F_25 ( ( V_45 ,
L_19
L_20 ) ) ;
return;
}
}
V_14 -> V_47 = 1 ;
F_36 ( V_94 , 1 ) ;
return;
}
static int F_37 ( struct V_11 * V_12 )
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
F_34 ( V_12 , V_14 ) ;
break;
}
if ( ! V_14 -> V_47 )
continue;
F_8 ( V_54 , V_12 , V_14 ) ;
F_19 ( V_14 -> type ) ;
V_95 ++ ;
}
F_14 ( V_12 ) ;
return ( V_95 ) ;
}
static int F_38 ( struct V_11 * V_12 )
{
unsigned int V_54 ;
int V_96 ;
memset ( V_12 -> V_17 . V_28 , 0 , sizeof( V_12 -> V_17 . V_28 ) ) ;
V_96 = F_27 ( V_12 ) ;
if ( V_96 == - V_36 )
V_96 = F_22 ( V_12 ) ;
if ( V_96 )
return V_96 ;
F_26 ( V_12 ) ;
V_12 -> V_17 . V_52 = F_37 ( V_12 ) ;
for ( V_54 = 1 ; V_54 < V_7 ; V_54 ++ ) {
if ( V_12 -> V_17 . V_28 [ V_54 ] . V_47 ) {
V_12 -> V_17 . V_52 = V_54 ;
if ( V_12 -> V_17 . V_28 [ V_54 ] . type >= V_20 )
V_12 -> V_38 . V_17 = 1 ;
}
}
return 0 ;
}
static int F_39 ( void )
{
T_4 V_97 = 0 ;
if ( V_98 )
return 0 ;
F_40 ( V_99 , & V_97 ) ;
if ( V_97 )
F_36 ( V_99 , 1 ) ;
else if ( V_88 . V_89 . V_100 ) {
if ( ( F_41 ( V_88 . V_89 . V_100 + 0x02 ) & 0x01 )
|| ( F_41 ( V_88 . V_89 . V_100 + 0x0A ) & 0x01 ) )
V_97 = 1 ;
}
return V_97 ;
}
static void F_42 ( struct V_13 * V_14 )
{
if ( V_14 -> V_48 == V_82 ) {
F_43 ( V_14 ) ;
} else if ( V_14 -> V_48 == V_49 ) {
F_4 () ;
} else {
F_44 ( V_14 -> V_40 ) ;
F_45 ( V_37 . V_101 . V_40 ) ;
}
}
static int F_46 ( struct V_102 * V_103 , int V_80 )
{
struct V_13 * V_14 = F_47 ( V_104 [ V_80 ] , V_103 -> V_105 ) ;
F_48 () ;
while ( 1 ) {
if ( V_14 -> V_48 == V_49 )
F_6 () ;
else if ( V_14 -> V_48 == V_81 ) {
F_44 ( V_14 -> V_40 ) ;
F_45 ( V_37 . V_101 . V_40 ) ;
} else
return - V_36 ;
}
return 0 ;
}
static bool F_49 ( struct V_11 * V_12 )
{
return F_50 ( F_23 ) && ! V_12 -> V_38 . V_70 &&
! ( V_37 . V_38 & V_39 ) ;
}
static void F_51 ( struct V_11 * V_12 ,
struct V_13 * V_14 , bool V_106 )
{
F_52 ( F_53 () ) ;
if ( V_106 )
F_16 ( V_12 , V_14 , 1 ) ;
if ( V_12 -> V_38 . V_92 ) {
F_54 ( & V_107 ) ;
V_108 ++ ;
if ( V_108 == F_24 () )
F_36 ( V_109 , 1 ) ;
F_55 ( & V_107 ) ;
}
F_42 ( V_14 ) ;
if ( V_12 -> V_38 . V_92 ) {
F_54 ( & V_107 ) ;
F_36 ( V_109 , 0 ) ;
V_108 -- ;
F_55 ( & V_107 ) ;
}
if ( V_106 )
F_16 ( V_12 , V_14 , 0 ) ;
}
static int F_56 ( struct V_102 * V_103 ,
struct V_110 * V_111 , int V_80 )
{
struct V_13 * V_14 = F_47 ( V_104 [ V_80 ] , V_103 -> V_105 ) ;
struct V_11 * V_12 ;
V_12 = F_57 ( V_112 ) ;
if ( F_58 ( ! V_12 ) )
return - V_113 ;
if ( V_14 -> type != V_23 ) {
if ( F_49 ( V_12 ) && F_24 () > 1 ) {
V_80 = V_114 ;
V_14 = F_47 ( V_104 [ V_80 ] , V_103 -> V_105 ) ;
} else if ( V_14 -> type == V_19 && V_12 -> V_38 . V_91 ) {
if ( V_14 -> V_115 || ! F_39 () ) {
F_51 ( V_12 , V_14 , true ) ;
return V_80 ;
} else if ( V_111 -> V_116 >= 0 ) {
V_80 = V_111 -> V_116 ;
V_14 = F_47 ( V_104 [ V_80 ] , V_103 -> V_105 ) ;
} else {
F_4 () ;
return - V_117 ;
}
}
}
F_16 ( V_12 , V_14 , 1 ) ;
if ( V_14 -> type == V_19 )
F_48 () ;
F_42 ( V_14 ) ;
F_16 ( V_12 , V_14 , 0 ) ;
return V_80 ;
}
static void F_59 ( struct V_102 * V_103 ,
struct V_110 * V_111 , int V_80 )
{
struct V_13 * V_14 = F_47 ( V_104 [ V_80 ] , V_103 -> V_105 ) ;
if ( V_14 -> type == V_19 ) {
struct V_11 * V_12 = F_57 ( V_112 ) ;
if ( F_58 ( ! V_12 ) )
return;
if ( V_12 -> V_38 . V_91 ) {
F_51 ( V_12 , V_14 , false ) ;
return;
} else {
F_48 () ;
}
}
F_42 ( V_14 ) ;
}
static int F_60 ( struct V_11 * V_12 ,
struct V_102 * V_103 )
{
int V_54 , V_52 = V_114 ;
struct V_13 * V_14 ;
if ( ! V_12 -> V_38 . V_118 )
return - V_113 ;
if ( V_12 -> V_38 . V_17 == 0 ) {
return - V_113 ;
}
if ( ! V_103 )
return - V_113 ;
V_103 -> V_105 = V_12 -> V_5 ;
if ( V_6 == 0 )
V_6 = 1 ;
for ( V_54 = 1 ; V_54 < V_7 && V_54 <= V_6 ; V_54 ++ ) {
V_14 = & V_12 -> V_17 . V_28 [ V_54 ] ;
if ( ! V_14 -> V_47 )
continue;
F_47 ( V_104 [ V_52 ] , V_103 -> V_105 ) = V_14 ;
V_52 ++ ;
if ( V_52 == V_119 )
break;
}
if ( ! V_52 )
return - V_113 ;
return 0 ;
}
static int F_61 ( struct V_11 * V_12 )
{
int V_54 , V_52 = V_114 ;
struct V_13 * V_14 ;
struct V_120 * V_10 ;
struct V_110 * V_111 = & V_121 ;
if ( ! V_12 -> V_38 . V_118 )
return - V_113 ;
if ( V_12 -> V_38 . V_17 == 0 )
return - V_113 ;
V_111 -> V_116 = - 1 ;
for ( V_54 = V_114 ; V_54 < V_119 ; V_54 ++ ) {
V_111 -> V_28 [ V_54 ] . V_122 [ 0 ] = '\0' ;
V_111 -> V_28 [ V_54 ] . V_83 [ 0 ] = '\0' ;
}
if ( V_6 == 0 )
V_6 = 1 ;
for ( V_54 = 1 ; V_54 < V_7 && V_54 <= V_6 ; V_54 ++ ) {
V_14 = & V_12 -> V_17 . V_28 [ V_54 ] ;
if ( ! V_14 -> V_47 )
continue;
V_10 = & V_111 -> V_28 [ V_52 ] ;
snprintf ( V_10 -> V_122 , V_123 , L_21 , V_54 ) ;
strncpy ( V_10 -> V_83 , V_14 -> V_83 , V_124 ) ;
V_10 -> V_125 = V_14 -> V_41 ;
V_10 -> V_126 = V_14 -> V_41 * V_127 ;
V_10 -> V_128 = F_56 ;
V_10 -> V_38 = 0 ;
if ( V_14 -> type == V_23 || V_14 -> type == V_20 ) {
V_10 -> V_129 = F_46 ;
V_111 -> V_116 = V_52 ;
}
if ( V_14 -> type != V_23 && ! F_49 ( V_12 ) )
V_10 -> V_130 = F_59 ;
V_52 ++ ;
if ( V_52 == V_119 )
break;
}
V_111 -> V_131 = V_52 ;
if ( ! V_52 )
return - V_113 ;
return 0 ;
}
int F_62 ( struct V_11 * V_12 )
{
int V_55 = 0 ;
struct V_102 * V_103 ;
if ( F_1 () )
return 0 ;
if ( V_61 )
return - V_36 ;
if ( ! V_12 -> V_38 . V_118 )
return - V_36 ;
V_103 = F_47 ( V_132 , V_12 -> V_5 ) ;
F_63 () ;
F_64 ( V_103 ) ;
F_38 ( V_12 ) ;
if ( V_12 -> V_38 . V_17 ) {
F_60 ( V_12 , V_103 ) ;
V_55 = F_65 ( V_103 ) ;
}
F_66 () ;
return V_55 ;
}
int F_67 ( struct V_11 * V_12 )
{
int V_105 ;
struct V_11 * V_133 ;
struct V_102 * V_103 ;
if ( F_1 () )
return 0 ;
if ( V_61 )
return - V_36 ;
if ( ! V_12 -> V_38 . V_118 )
return - V_36 ;
if ( V_12 -> V_5 == 0 && F_68 () == & V_121 ) {
F_69 () ;
F_63 () ;
F_70 (cpu) {
V_133 = F_47 ( V_112 , V_105 ) ;
if ( ! V_133 || ! V_133 -> V_38 . V_118 )
continue;
V_103 = F_47 ( V_132 , V_105 ) ;
F_64 ( V_103 ) ;
}
F_38 ( V_12 ) ;
F_61 ( V_12 ) ;
F_70 (cpu) {
V_133 = F_47 ( V_112 , V_105 ) ;
if ( ! V_133 || ! V_133 -> V_38 . V_118 )
continue;
F_38 ( V_133 ) ;
if ( V_133 -> V_38 . V_17 ) {
V_103 = F_47 ( V_132 , V_105 ) ;
F_60 ( V_133 , V_103 ) ;
F_65 ( V_103 ) ;
}
}
F_66 () ;
F_71 () ;
}
return 0 ;
}
int F_72 ( struct V_11 * V_12 )
{
T_2 V_51 ;
int V_134 ;
struct V_102 * V_103 ;
static int V_135 ;
if ( F_1 () )
return 0 ;
if ( ! V_135 ) {
F_73 ( V_136 ) ;
V_6 = F_74 ( V_6 ) ;
if ( V_6 < V_137 )
F_75 ( V_138
L_22 ,
V_6 ) ;
V_135 ++ ;
}
if ( V_37 . V_139 && ! V_61 ) {
V_51 =
F_76 ( V_37 . V_140 , V_37 . V_139 , 8 ) ;
if ( F_29 ( V_51 ) ) {
F_77 ( ( V_141 , V_51 ,
L_23 ) ) ;
}
}
F_38 ( V_12 ) ;
V_12 -> V_38 . V_118 = 1 ;
if ( V_12 -> V_38 . V_17 ) {
if ( ! V_142 ) {
F_61 ( V_12 ) ;
V_134 = F_78 ( & V_121 ) ;
if ( V_134 )
return V_134 ;
F_79 ( L_24 ,
V_121 . V_122 ) ;
}
V_103 = F_80 ( sizeof( * V_103 ) , V_143 ) ;
if ( ! V_103 )
return - V_144 ;
F_47 ( V_132 , V_12 -> V_5 ) = V_103 ;
F_60 ( V_12 , V_103 ) ;
V_134 = F_81 ( V_103 ) ;
if ( V_134 ) {
if ( V_142 == 0 )
F_82 ( & V_121 ) ;
return V_134 ;
}
V_142 ++ ;
}
return 0 ;
}
int F_83 ( struct V_11 * V_12 )
{
struct V_102 * V_103 = F_47 ( V_132 , V_12 -> V_5 ) ;
if ( F_1 () )
return 0 ;
if ( V_12 -> V_38 . V_17 ) {
F_84 ( V_103 ) ;
V_142 -- ;
if ( V_142 == 0 )
F_82 ( & V_121 ) ;
}
V_12 -> V_38 . V_118 = 0 ;
return 0 ;
}

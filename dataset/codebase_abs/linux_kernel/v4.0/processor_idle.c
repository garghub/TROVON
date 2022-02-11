static int F_1 ( void )
{
return V_1 == V_2 ||
V_1 == V_3 ;
}
static int F_2 ( const struct V_4 * V_5 )
{
if ( V_6 > V_7 )
return 0 ;
F_3 (KERN_NOTICE PREFIX L_1
L_2 , id->ident,
(long)id->driver_data, ACPI_PROCESSOR_MAX_POWER + 1 ) ;
V_6 = ( long ) V_5 -> V_8 ;
return 0 ;
}
static void F_4 ( void )
{
if ( ! F_5 () ) {
F_6 () ;
F_7 () ;
}
}
static void F_8 ( int V_9 , struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = & V_11 -> V_16 ;
T_1 type = V_17 ? V_18 : V_19 ;
if ( F_9 ( & F_10 ( V_11 -> V_5 ) , V_20 ) )
return;
if ( V_21 )
type = V_22 ;
if ( V_15 -> V_23 < V_9 )
return;
if ( V_13 -> type >= type )
V_11 -> V_16 . V_23 = V_9 ;
}
static void F_11 ( void * V_24 )
{
struct V_10 * V_11 = (struct V_10 * ) V_24 ;
unsigned long V_25 ;
V_25 = V_11 -> V_16 . V_23 < V_26 ?
V_27 : V_28 ;
F_12 ( V_25 , & V_11 -> V_5 ) ;
}
static void F_13 ( struct V_10 * V_11 )
{
F_14 ( V_11 -> V_5 , F_11 ,
( void * ) V_11 , 1 ) ;
}
static void F_15 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
int V_29 )
{
int V_9 = V_13 - V_11 -> V_16 . V_30 ;
if ( V_9 >= V_11 -> V_16 . V_23 ) {
unsigned long V_25 ;
V_25 = V_29 ? V_31 :
V_32 ;
F_12 ( V_25 , & V_11 -> V_5 ) ;
}
}
static void F_8 ( int V_9 , struct V_10 * V_11 ,
struct V_12 * V_33 ) { }
static void F_13 ( struct V_10 * V_11 ) { }
static void F_15 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
int V_29 )
{
}
static int F_16 ( void )
{
F_17 ( V_34 , & V_35 ) ;
return 0 ;
}
static void F_18 ( void )
{
T_2 V_36 = 0 ;
F_17 ( V_34 , & V_36 ) ;
if ( V_36 == V_35 )
return;
F_19 ( V_34 , V_35 ) ;
}
void F_20 ( void )
{
F_21 ( & V_37 ) ;
}
void F_22 ( void )
{
F_23 ( & V_37 ) ;
}
static void F_24 ( int V_9 )
{
switch ( V_38 . V_39 ) {
case V_40 :
case V_41 :
if ( F_25 ( V_42 ) )
return;
default:
if ( V_9 > V_22 )
F_26 ( L_3 ) ;
}
}
static void F_24 ( int V_9 ) { return; }
static int F_27 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_43 )
return - V_44 ;
V_11 -> V_16 . V_30 [ V_19 ] . type = V_19 ;
V_11 -> V_16 . V_30 [ V_18 ] . type = V_18 ;
#ifndef F_28
if ( ( F_29 () > 1 ) &&
! ( V_45 . V_46 & V_47 ) )
return - V_44 ;
#endif
V_11 -> V_16 . V_30 [ V_19 ] . V_48 = V_11 -> V_43 + 4 ;
V_11 -> V_16 . V_30 [ V_18 ] . V_48 = V_11 -> V_43 + 5 ;
V_11 -> V_16 . V_30 [ V_19 ] . V_49 = V_45 . V_50 ;
V_11 -> V_16 . V_30 [ V_18 ] . V_49 = V_45 . V_51 ;
if ( V_45 . V_50 > V_52 ) {
F_30 ( ( V_53 ,
L_4 , V_45 . V_50 ) ) ;
V_11 -> V_16 . V_30 [ V_19 ] . V_48 = 0 ;
}
if ( V_45 . V_51 > V_54 ) {
F_30 ( ( V_53 ,
L_5 , V_45 . V_51 ) ) ;
V_11 -> V_16 . V_30 [ V_18 ] . V_48 = 0 ;
}
F_30 ( ( V_53 ,
L_6 ,
V_11 -> V_16 . V_30 [ V_19 ] . V_48 ,
V_11 -> V_16 . V_30 [ V_18 ] . V_48 ) ) ;
return 0 ;
}
static int F_31 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_16 . V_30 [ V_22 ] . V_55 ) {
V_11 -> V_16 . V_30 [ V_22 ] . type = V_22 ;
V_11 -> V_16 . V_30 [ V_22 ] . V_55 = 1 ;
V_11 -> V_16 . V_30 [ V_22 ] . V_56 = V_57 ;
}
V_11 -> V_16 . V_30 [ V_58 ] . V_55 = 1 ;
return 0 ;
}
static int F_32 ( struct V_10 * V_11 )
{
T_3 V_59 ;
T_4 V_60 ;
int V_61 ;
int V_62 , V_63 = 0 ;
struct V_64 V_65 = { V_66 , NULL } ;
union V_67 * V_68 ;
if ( V_69 )
return - V_44 ;
V_61 = 0 ;
V_59 = F_33 ( V_11 -> V_70 , L_7 , NULL , & V_65 ) ;
if ( F_34 ( V_59 ) ) {
F_30 ( ( V_53 , L_8 ) ) ;
return - V_44 ;
}
V_68 = V_65 . V_71 ;
if ( ! V_68 || ( V_68 -> type != V_72 ) || V_68 -> V_73 . V_60 < 2 ) {
F_3 (KERN_ERR PREFIX L_9 ) ;
V_63 = - V_74 ;
goto V_75;
}
V_60 = V_68 -> V_73 . V_76 [ 0 ] . integer . V_77 ;
if ( V_60 < 1 || V_60 != V_68 -> V_73 . V_60 - 1 ) {
F_3 (KERN_ERR PREFIX L_10 ) ;
V_63 = - V_74 ;
goto V_75;
}
V_11 -> V_46 . V_78 = 1 ;
for ( V_62 = 1 ; V_62 <= V_60 ; V_62 ++ ) {
union V_67 * V_79 ;
union V_67 * V_80 ;
struct V_81 * V_82 ;
struct V_12 V_13 ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_79 = & ( V_68 -> V_73 . V_76 [ V_62 ] ) ;
if ( V_79 -> type != V_72 )
continue;
if ( V_79 -> V_73 . V_60 != 4 )
continue;
V_80 = & ( V_79 -> V_73 . V_76 [ 0 ] ) ;
if ( V_80 -> type != V_83 )
continue;
V_82 = (struct V_81 * ) V_80 -> V_65 . V_71 ;
if ( V_82 -> V_84 != V_85 &&
( V_82 -> V_84 != V_86 ) )
continue;
V_80 = & ( V_79 -> V_73 . V_76 [ 1 ] ) ;
if ( V_80 -> type != V_87 )
continue;
V_13 . type = V_80 -> integer . V_77 ;
if ( V_62 == 1 && V_13 . type != V_22 )
V_61 ++ ;
V_13 . V_48 = V_82 -> V_48 ;
V_13 . V_88 = V_61 + 1 ;
V_13 . V_56 = V_89 ;
if ( V_82 -> V_84 == V_86 ) {
if ( F_35
( V_11 -> V_5 , & V_13 , V_82 ) == 0 ) {
V_13 . V_56 = V_90 ;
} else if ( V_13 . type == V_22 ) {
V_13 . V_56 = V_57 ;
snprintf ( V_13 . V_91 , V_92 , L_11 ) ;
} else {
continue;
}
if ( V_13 . type == V_22 &&
( V_1 == V_93 ) ) {
V_13 . V_56 = V_57 ;
snprintf ( V_13 . V_91 , V_92 , L_11 ) ;
}
} else {
snprintf ( V_13 . V_91 , V_92 , L_12 ,
V_13 . V_48 ) ;
}
if ( V_13 . type == V_22 ) {
V_13 . V_55 = 1 ;
}
V_80 = & ( V_79 -> V_73 . V_76 [ 2 ] ) ;
if ( V_80 -> type != V_87 )
continue;
V_13 . V_49 = V_80 -> integer . V_77 ;
V_80 = & ( V_79 -> V_73 . V_76 [ 3 ] ) ;
if ( V_80 -> type != V_87 )
continue;
V_61 ++ ;
memcpy ( & ( V_11 -> V_16 . V_30 [ V_61 ] ) , & V_13 , sizeof( V_13 ) ) ;
if ( V_61 >= ( V_7 - 1 ) ) {
F_3 ( V_94
L_13 ,
V_7 ) ;
F_3 ( V_94
L_14 ) ;
break;
}
}
F_30 ( ( V_53 , L_15 ,
V_61 ) ) ;
if ( V_61 < 2 )
V_63 = - V_74 ;
V_75:
F_36 ( V_65 . V_71 ) ;
return V_63 ;
}
static void F_37 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
static int V_95 = - 1 ;
static int V_96 = - 1 ;
if ( ! V_13 -> V_48 )
return;
else if ( V_97 . V_98 . V_99 ) {
F_30 ( ( V_53 ,
L_16 ) ) ;
return;
}
if ( V_95 == - 1 ) {
F_38 ( & ( V_11 -> V_46 ) , V_11 -> V_5 ) ;
V_95 = V_11 -> V_46 . V_100 ;
V_96 = V_11 -> V_46 . V_101 ;
} else {
V_11 -> V_46 . V_100 = V_95 ;
V_11 -> V_46 . V_101 = V_96 ;
}
if ( V_11 -> V_46 . V_100 ) {
if ( ! V_11 -> V_46 . V_101 ) {
if ( V_11 -> V_46 . V_78 != 1 ) {
F_30 ( ( V_53 ,
L_17 ) ) ;
return;
} else {
F_30 ( ( V_53 ,
L_18 ) ) ;
}
}
} else {
if ( ! ( V_45 . V_46 & V_102 ) ) {
F_30 ( ( V_53 ,
L_19
L_20 ) ) ;
return;
}
}
V_13 -> V_55 = 1 ;
F_19 ( V_34 , 1 ) ;
return;
}
static int F_39 ( struct V_10 * V_11 )
{
unsigned int V_62 ;
unsigned int V_103 = 0 ;
V_11 -> V_16 . V_23 = V_26 ;
for ( V_62 = 1 ; V_62 < V_7 && V_62 <= V_6 ; V_62 ++ ) {
struct V_12 * V_13 = & V_11 -> V_16 . V_30 [ V_62 ] ;
switch ( V_13 -> type ) {
case V_22 :
V_13 -> V_55 = 1 ;
break;
case V_19 :
if ( ! V_13 -> V_48 )
break;
V_13 -> V_55 = 1 ;
break;
case V_18 :
F_37 ( V_11 , V_13 ) ;
break;
}
if ( ! V_13 -> V_55 )
continue;
F_8 ( V_62 , V_11 , V_13 ) ;
F_24 ( V_13 -> type ) ;
V_103 ++ ;
}
F_13 ( V_11 ) ;
return ( V_103 ) ;
}
static int F_40 ( struct V_10 * V_11 )
{
unsigned int V_62 ;
int V_104 ;
memset ( V_11 -> V_16 . V_30 , 0 , sizeof( V_11 -> V_16 . V_30 ) ) ;
V_104 = F_32 ( V_11 ) ;
if ( V_104 == - V_44 )
V_104 = F_27 ( V_11 ) ;
if ( V_104 )
return V_104 ;
F_31 ( V_11 ) ;
V_11 -> V_16 . V_60 = F_39 ( V_11 ) ;
for ( V_62 = 1 ; V_62 < V_7 ; V_62 ++ ) {
if ( V_11 -> V_16 . V_30 [ V_62 ] . V_55 ) {
V_11 -> V_16 . V_60 = V_62 ;
if ( V_11 -> V_16 . V_30 [ V_62 ] . type >= V_19 )
V_11 -> V_46 . V_16 = 1 ;
}
}
return 0 ;
}
static int F_41 ( void )
{
T_2 V_105 = 0 ;
if ( V_106 )
return 0 ;
F_17 ( V_107 , & V_105 ) ;
if ( V_105 )
F_19 ( V_107 , 1 ) ;
else if ( V_97 . V_98 . V_108 ) {
if ( ( F_42 ( V_97 . V_98 . V_108 + 0x02 ) & 0x01 )
|| ( F_42 ( V_97 . V_98 . V_108 + 0x0A ) & 0x01 ) )
V_105 = 1 ;
}
return V_105 ;
}
static void F_43 ( struct V_12 * V_13 )
{
if ( V_13 -> V_56 == V_90 ) {
F_44 ( V_13 ) ;
} else if ( V_13 -> V_56 == V_57 ) {
F_4 () ;
} else {
F_45 ( V_13 -> V_48 ) ;
F_46 ( V_45 . V_109 . V_48 ) ;
}
}
static int F_47 ( struct V_110 * V_111 , int V_88 )
{
struct V_12 * V_13 = F_48 ( V_112 [ V_88 ] , V_111 -> V_113 ) ;
F_49 () ;
while ( 1 ) {
if ( V_13 -> V_56 == V_57 )
F_6 () ;
else if ( V_13 -> V_56 == V_89 ) {
F_45 ( V_13 -> V_48 ) ;
F_46 ( V_45 . V_109 . V_48 ) ;
} else
return - V_44 ;
}
return 0 ;
}
static bool F_50 ( struct V_10 * V_11 )
{
return F_51 ( F_28 ) && ! V_11 -> V_46 . V_78 &&
! ( V_45 . V_46 & V_47 ) ;
}
static void F_52 ( struct V_10 * V_11 ,
struct V_12 * V_13 , bool V_114 )
{
F_53 ( F_54 () ) ;
if ( V_114 )
F_15 ( V_11 , V_13 , 1 ) ;
if ( V_11 -> V_46 . V_101 ) {
F_55 ( & V_115 ) ;
V_116 ++ ;
if ( V_116 == F_29 () )
F_19 ( V_117 , 1 ) ;
F_56 ( & V_115 ) ;
}
F_43 ( V_13 ) ;
if ( V_11 -> V_46 . V_101 ) {
F_55 ( & V_115 ) ;
F_19 ( V_117 , 0 ) ;
V_116 -- ;
F_56 ( & V_115 ) ;
}
if ( V_114 )
F_15 ( V_11 , V_13 , 0 ) ;
}
static int F_57 ( struct V_110 * V_111 ,
struct V_118 * V_119 , int V_88 )
{
struct V_12 * V_13 = F_48 ( V_112 [ V_88 ] , V_111 -> V_113 ) ;
struct V_10 * V_11 ;
V_11 = F_58 ( V_120 ) ;
if ( F_59 ( ! V_11 ) )
return - V_121 ;
if ( V_13 -> type != V_22 ) {
if ( F_50 ( V_11 ) && F_29 () > 1 ) {
V_88 = V_122 ;
V_13 = F_48 ( V_112 [ V_88 ] , V_111 -> V_113 ) ;
} else if ( V_13 -> type == V_18 && V_11 -> V_46 . V_100 ) {
if ( V_13 -> V_123 || ! F_41 () ) {
F_52 ( V_11 , V_13 , true ) ;
return V_88 ;
} else if ( V_119 -> V_124 >= 0 ) {
V_88 = V_119 -> V_124 ;
V_13 = F_48 ( V_112 [ V_88 ] , V_111 -> V_113 ) ;
} else {
F_4 () ;
return - V_125 ;
}
}
}
F_15 ( V_11 , V_13 , 1 ) ;
if ( V_13 -> type == V_18 )
F_49 () ;
F_43 ( V_13 ) ;
F_15 ( V_11 , V_13 , 0 ) ;
return V_88 ;
}
static void F_60 ( struct V_110 * V_111 ,
struct V_118 * V_119 , int V_88 )
{
struct V_12 * V_13 = F_48 ( V_112 [ V_88 ] , V_111 -> V_113 ) ;
if ( V_13 -> type == V_18 ) {
struct V_10 * V_11 = F_58 ( V_120 ) ;
if ( F_59 ( ! V_11 ) )
return;
if ( V_11 -> V_46 . V_100 ) {
F_52 ( V_11 , V_13 , false ) ;
return;
} else {
F_49 () ;
}
}
F_43 ( V_13 ) ;
}
static int F_61 ( struct V_10 * V_11 ,
struct V_110 * V_111 )
{
int V_62 , V_60 = V_122 ;
struct V_12 * V_13 ;
if ( ! V_11 -> V_46 . V_126 )
return - V_121 ;
if ( V_11 -> V_46 . V_16 == 0 ) {
return - V_121 ;
}
if ( ! V_111 )
return - V_121 ;
V_111 -> V_113 = V_11 -> V_5 ;
if ( V_6 == 0 )
V_6 = 1 ;
for ( V_62 = 1 ; V_62 < V_7 && V_62 <= V_6 ; V_62 ++ ) {
V_13 = & V_11 -> V_16 . V_30 [ V_62 ] ;
if ( ! V_13 -> V_55 )
continue;
F_48 ( V_112 [ V_60 ] , V_111 -> V_113 ) = V_13 ;
V_60 ++ ;
if ( V_60 == V_127 )
break;
}
if ( ! V_60 )
return - V_121 ;
return 0 ;
}
static int F_62 ( struct V_10 * V_11 )
{
int V_62 , V_60 = V_122 ;
struct V_12 * V_13 ;
struct V_128 * V_9 ;
struct V_118 * V_119 = & V_129 ;
if ( ! V_11 -> V_46 . V_126 )
return - V_121 ;
if ( V_11 -> V_46 . V_16 == 0 )
return - V_121 ;
V_119 -> V_124 = - 1 ;
for ( V_62 = V_122 ; V_62 < V_127 ; V_62 ++ ) {
V_119 -> V_30 [ V_62 ] . V_130 [ 0 ] = '\0' ;
V_119 -> V_30 [ V_62 ] . V_91 [ 0 ] = '\0' ;
}
if ( V_6 == 0 )
V_6 = 1 ;
for ( V_62 = 1 ; V_62 < V_7 && V_62 <= V_6 ; V_62 ++ ) {
V_13 = & V_11 -> V_16 . V_30 [ V_62 ] ;
if ( ! V_13 -> V_55 )
continue;
V_9 = & V_119 -> V_30 [ V_60 ] ;
snprintf ( V_9 -> V_130 , V_131 , L_21 , V_62 ) ;
strncpy ( V_9 -> V_91 , V_13 -> V_91 , V_132 ) ;
V_9 -> V_133 = V_13 -> V_49 ;
V_9 -> V_134 = V_13 -> V_49 * V_135 ;
V_9 -> V_136 = F_57 ;
V_9 -> V_46 = 0 ;
if ( V_13 -> type == V_22 || V_13 -> type == V_19 ) {
V_9 -> V_137 = F_47 ;
V_119 -> V_124 = V_60 ;
}
if ( V_13 -> type != V_22 && ! F_50 ( V_11 ) )
V_9 -> V_138 = F_60 ;
V_60 ++ ;
if ( V_60 == V_127 )
break;
}
V_119 -> V_139 = V_60 ;
if ( ! V_60 )
return - V_121 ;
return 0 ;
}
int F_63 ( struct V_10 * V_11 )
{
int V_63 = 0 ;
struct V_110 * V_111 ;
if ( F_1 () )
return 0 ;
if ( V_69 )
return - V_44 ;
if ( ! V_11 -> V_46 . V_126 )
return - V_44 ;
V_111 = F_48 ( V_140 , V_11 -> V_5 ) ;
F_64 () ;
F_65 ( V_111 ) ;
F_40 ( V_11 ) ;
if ( V_11 -> V_46 . V_16 ) {
F_61 ( V_11 , V_111 ) ;
V_63 = F_66 ( V_111 ) ;
}
F_67 () ;
return V_63 ;
}
int F_68 ( struct V_10 * V_11 )
{
int V_113 ;
struct V_10 * V_141 ;
struct V_110 * V_111 ;
if ( F_1 () )
return 0 ;
if ( V_69 )
return - V_44 ;
if ( ! V_11 -> V_46 . V_126 )
return - V_44 ;
if ( V_11 -> V_5 == 0 && F_69 () == & V_129 ) {
F_70 () ;
F_64 () ;
F_71 (cpu) {
V_141 = F_48 ( V_120 , V_113 ) ;
if ( ! V_141 || ! V_141 -> V_46 . V_126 )
continue;
V_111 = F_48 ( V_140 , V_113 ) ;
F_65 ( V_111 ) ;
}
F_40 ( V_11 ) ;
F_62 ( V_11 ) ;
F_71 (cpu) {
V_141 = F_48 ( V_120 , V_113 ) ;
if ( ! V_141 || ! V_141 -> V_46 . V_126 )
continue;
F_40 ( V_141 ) ;
if ( V_141 -> V_46 . V_16 ) {
V_111 = F_48 ( V_140 , V_113 ) ;
F_61 ( V_141 , V_111 ) ;
F_66 ( V_111 ) ;
}
}
F_67 () ;
F_72 () ;
}
return 0 ;
}
int F_73 ( struct V_10 * V_11 )
{
T_3 V_59 ;
int V_142 ;
struct V_110 * V_111 ;
static int V_143 ;
if ( F_1 () )
return 0 ;
if ( ! V_143 ) {
F_74 ( V_144 ) ;
V_6 = F_75 ( V_6 ) ;
if ( V_6 < V_145 )
F_3 ( V_146
L_22 ,
V_6 ) ;
V_143 ++ ;
}
if ( V_45 . V_147 && ! V_69 ) {
V_59 =
F_76 ( V_45 . V_148 , V_45 . V_147 , 8 ) ;
if ( F_34 ( V_59 ) ) {
F_77 ( ( V_149 , V_59 ,
L_23 ) ) ;
}
}
F_40 ( V_11 ) ;
V_11 -> V_46 . V_126 = 1 ;
if ( V_11 -> V_46 . V_16 ) {
if ( ! V_150 ) {
F_62 ( V_11 ) ;
V_142 = F_78 ( & V_129 ) ;
if ( V_142 )
return V_142 ;
F_3 ( V_151 L_24 ,
V_129 . V_130 ) ;
}
V_111 = F_79 ( sizeof( * V_111 ) , V_152 ) ;
if ( ! V_111 )
return - V_153 ;
F_48 ( V_140 , V_11 -> V_5 ) = V_111 ;
F_61 ( V_11 , V_111 ) ;
V_142 = F_80 ( V_111 ) ;
if ( V_142 ) {
if ( V_150 == 0 )
F_81 ( & V_129 ) ;
return V_142 ;
}
V_150 ++ ;
}
return 0 ;
}
int F_82 ( struct V_10 * V_11 )
{
struct V_110 * V_111 = F_48 ( V_140 , V_11 -> V_5 ) ;
if ( F_1 () )
return 0 ;
if ( V_11 -> V_46 . V_16 ) {
F_83 ( V_111 ) ;
V_150 -- ;
if ( V_150 == 0 )
F_81 ( & V_129 ) ;
}
V_11 -> V_46 . V_126 = 0 ;
return 0 ;
}

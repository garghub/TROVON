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
if ( V_11 -> V_16 . V_23 < V_25 )
F_12 () ;
else
F_13 () ;
}
static void F_14 ( struct V_10 * V_11 )
{
F_15 ( V_11 -> V_5 , F_11 ,
( void * ) V_11 , 1 ) ;
}
static void F_16 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
int V_26 )
{
int V_9 = V_13 - V_11 -> V_16 . V_27 ;
if ( V_9 >= V_11 -> V_16 . V_23 ) {
if ( V_26 )
F_17 () ;
else
F_18 () ;
}
}
static void F_8 ( int V_9 , struct V_10 * V_11 ,
struct V_12 * V_28 ) { }
static void F_14 ( struct V_10 * V_11 ) { }
static void F_16 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
int V_26 )
{
}
static int F_19 ( void )
{
F_20 ( V_29 , & V_30 ) ;
return 0 ;
}
static void F_21 ( void )
{
T_2 V_31 = 0 ;
F_20 ( V_29 , & V_31 ) ;
if ( V_31 == V_30 )
return;
F_22 ( V_29 , V_30 ) ;
}
void F_23 ( void )
{
F_24 ( & V_32 ) ;
}
void F_25 ( void )
{
F_26 ( & V_32 ) ;
}
static void F_27 ( int V_9 )
{
switch ( V_33 . V_34 ) {
case V_35 :
case V_36 :
if ( F_28 ( V_37 ) )
return;
default:
if ( V_9 > V_22 )
F_29 ( L_3 ) ;
}
}
static void F_27 ( int V_9 ) { return; }
static int F_30 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_38 )
return - V_39 ;
V_11 -> V_16 . V_27 [ V_19 ] . type = V_19 ;
V_11 -> V_16 . V_27 [ V_18 ] . type = V_18 ;
#ifndef F_31
if ( ( F_32 () > 1 ) &&
! ( V_40 . V_41 & V_42 ) )
return - V_39 ;
#endif
V_11 -> V_16 . V_27 [ V_19 ] . V_43 = V_11 -> V_38 + 4 ;
V_11 -> V_16 . V_27 [ V_18 ] . V_43 = V_11 -> V_38 + 5 ;
V_11 -> V_16 . V_27 [ V_19 ] . V_44 = V_40 . V_45 ;
V_11 -> V_16 . V_27 [ V_18 ] . V_44 = V_40 . V_46 ;
if ( V_40 . V_45 > V_47 ) {
F_33 ( ( V_48 ,
L_4 , V_40 . V_45 ) ) ;
V_11 -> V_16 . V_27 [ V_19 ] . V_43 = 0 ;
}
if ( V_40 . V_46 > V_49 ) {
F_33 ( ( V_48 ,
L_5 , V_40 . V_46 ) ) ;
V_11 -> V_16 . V_27 [ V_18 ] . V_43 = 0 ;
}
F_33 ( ( V_48 ,
L_6 ,
V_11 -> V_16 . V_27 [ V_19 ] . V_43 ,
V_11 -> V_16 . V_27 [ V_18 ] . V_43 ) ) ;
return 0 ;
}
static int F_34 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_16 . V_27 [ V_22 ] . V_50 ) {
V_11 -> V_16 . V_27 [ V_22 ] . type = V_22 ;
V_11 -> V_16 . V_27 [ V_22 ] . V_50 = 1 ;
V_11 -> V_16 . V_27 [ V_22 ] . V_51 = V_52 ;
}
V_11 -> V_16 . V_27 [ V_53 ] . V_50 = 1 ;
return 0 ;
}
static int F_35 ( struct V_10 * V_11 )
{
T_3 V_54 ;
T_4 V_55 ;
int V_56 ;
int V_57 , V_58 = 0 ;
struct V_59 V_60 = { V_61 , NULL } ;
union V_62 * V_63 ;
if ( V_64 )
return - V_39 ;
V_56 = 0 ;
V_54 = F_36 ( V_11 -> V_65 , L_7 , NULL , & V_60 ) ;
if ( F_37 ( V_54 ) ) {
F_33 ( ( V_48 , L_8 ) ) ;
return - V_39 ;
}
V_63 = V_60 . V_66 ;
if ( ! V_63 || ( V_63 -> type != V_67 ) || V_63 -> V_68 . V_55 < 2 ) {
F_3 (KERN_ERR PREFIX L_9 ) ;
V_58 = - V_69 ;
goto V_70;
}
V_55 = V_63 -> V_68 . V_71 [ 0 ] . integer . V_72 ;
if ( V_55 < 1 || V_55 != V_63 -> V_68 . V_55 - 1 ) {
F_3 (KERN_ERR PREFIX L_10 ) ;
V_58 = - V_69 ;
goto V_70;
}
V_11 -> V_41 . V_73 = 1 ;
for ( V_57 = 1 ; V_57 <= V_55 ; V_57 ++ ) {
union V_62 * V_74 ;
union V_62 * V_75 ;
struct V_76 * V_77 ;
struct V_12 V_13 ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_74 = & ( V_63 -> V_68 . V_71 [ V_57 ] ) ;
if ( V_74 -> type != V_67 )
continue;
if ( V_74 -> V_68 . V_55 != 4 )
continue;
V_75 = & ( V_74 -> V_68 . V_71 [ 0 ] ) ;
if ( V_75 -> type != V_78 )
continue;
V_77 = (struct V_76 * ) V_75 -> V_60 . V_66 ;
if ( V_77 -> V_79 != V_80 &&
( V_77 -> V_79 != V_81 ) )
continue;
V_75 = & ( V_74 -> V_68 . V_71 [ 1 ] ) ;
if ( V_75 -> type != V_82 )
continue;
V_13 . type = V_75 -> integer . V_72 ;
if ( V_57 == 1 && V_13 . type != V_22 )
V_56 ++ ;
V_13 . V_43 = V_77 -> V_43 ;
V_13 . V_83 = V_56 + 1 ;
V_13 . V_51 = V_84 ;
if ( V_77 -> V_79 == V_81 ) {
if ( F_38
( V_11 -> V_5 , & V_13 , V_77 ) == 0 ) {
V_13 . V_51 = V_85 ;
} else if ( V_13 . type == V_22 ) {
V_13 . V_51 = V_52 ;
snprintf ( V_13 . V_86 , V_87 , L_11 ) ;
} else {
continue;
}
if ( V_13 . type == V_22 &&
( V_1 == V_88 ) ) {
V_13 . V_51 = V_52 ;
snprintf ( V_13 . V_86 , V_87 , L_11 ) ;
}
} else {
snprintf ( V_13 . V_86 , V_87 , L_12 ,
V_13 . V_43 ) ;
}
if ( V_13 . type == V_22 ) {
V_13 . V_50 = 1 ;
}
V_75 = & ( V_74 -> V_68 . V_71 [ 2 ] ) ;
if ( V_75 -> type != V_82 )
continue;
V_13 . V_44 = V_75 -> integer . V_72 ;
V_75 = & ( V_74 -> V_68 . V_71 [ 3 ] ) ;
if ( V_75 -> type != V_82 )
continue;
V_56 ++ ;
memcpy ( & ( V_11 -> V_16 . V_27 [ V_56 ] ) , & V_13 , sizeof( V_13 ) ) ;
if ( V_56 >= ( V_7 - 1 ) ) {
F_3 ( V_89
L_13 ,
V_7 ) ;
F_3 ( V_89
L_14 ) ;
break;
}
}
F_33 ( ( V_48 , L_15 ,
V_56 ) ) ;
if ( V_56 < 2 )
V_58 = - V_69 ;
V_70:
F_39 ( V_60 . V_66 ) ;
return V_58 ;
}
static void F_40 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
static int V_90 = - 1 ;
static int V_91 = - 1 ;
if ( ! V_13 -> V_43 )
return;
else if ( V_92 . V_93 . V_94 ) {
F_33 ( ( V_48 ,
L_16 ) ) ;
return;
}
if ( V_90 == - 1 ) {
F_41 ( & ( V_11 -> V_41 ) , V_11 -> V_5 ) ;
V_90 = V_11 -> V_41 . V_95 ;
V_91 = V_11 -> V_41 . V_96 ;
} else {
V_11 -> V_41 . V_95 = V_90 ;
V_11 -> V_41 . V_96 = V_91 ;
}
if ( V_11 -> V_41 . V_95 ) {
if ( ! V_11 -> V_41 . V_96 ) {
if ( V_11 -> V_41 . V_73 != 1 ) {
F_33 ( ( V_48 ,
L_17 ) ) ;
return;
} else {
F_33 ( ( V_48 ,
L_18 ) ) ;
}
}
} else {
if ( ! ( V_40 . V_41 & V_97 ) ) {
F_33 ( ( V_48 ,
L_19
L_20 ) ) ;
return;
}
}
V_13 -> V_50 = 1 ;
F_22 ( V_29 , 1 ) ;
return;
}
static int F_42 ( struct V_10 * V_11 )
{
unsigned int V_57 ;
unsigned int V_98 = 0 ;
V_11 -> V_16 . V_23 = V_25 ;
for ( V_57 = 1 ; V_57 < V_7 && V_57 <= V_6 ; V_57 ++ ) {
struct V_12 * V_13 = & V_11 -> V_16 . V_27 [ V_57 ] ;
switch ( V_13 -> type ) {
case V_22 :
V_13 -> V_50 = 1 ;
break;
case V_19 :
if ( ! V_13 -> V_43 )
break;
V_13 -> V_50 = 1 ;
break;
case V_18 :
F_40 ( V_11 , V_13 ) ;
break;
}
if ( ! V_13 -> V_50 )
continue;
F_8 ( V_57 , V_11 , V_13 ) ;
F_27 ( V_13 -> type ) ;
V_98 ++ ;
}
F_14 ( V_11 ) ;
return ( V_98 ) ;
}
static int F_43 ( struct V_10 * V_11 )
{
unsigned int V_57 ;
int V_99 ;
memset ( V_11 -> V_16 . V_27 , 0 , sizeof( V_11 -> V_16 . V_27 ) ) ;
V_99 = F_35 ( V_11 ) ;
if ( V_99 == - V_39 )
V_99 = F_30 ( V_11 ) ;
if ( V_99 )
return V_99 ;
F_34 ( V_11 ) ;
V_11 -> V_16 . V_55 = F_42 ( V_11 ) ;
for ( V_57 = 1 ; V_57 < V_7 ; V_57 ++ ) {
if ( V_11 -> V_16 . V_27 [ V_57 ] . V_50 ) {
V_11 -> V_16 . V_55 = V_57 ;
if ( V_11 -> V_16 . V_27 [ V_57 ] . type >= V_19 )
V_11 -> V_41 . V_16 = 1 ;
}
}
return 0 ;
}
static int F_44 ( void )
{
T_2 V_100 = 0 ;
if ( V_101 )
return 0 ;
F_20 ( V_102 , & V_100 ) ;
if ( V_100 )
F_22 ( V_102 , 1 ) ;
else if ( V_92 . V_93 . V_103 ) {
if ( ( F_45 ( V_92 . V_93 . V_103 + 0x02 ) & 0x01 )
|| ( F_45 ( V_92 . V_93 . V_103 + 0x0A ) & 0x01 ) )
V_100 = 1 ;
}
return V_100 ;
}
static void F_46 ( struct V_12 * V_13 )
{
if ( V_13 -> V_51 == V_85 ) {
F_47 ( V_13 ) ;
} else if ( V_13 -> V_51 == V_52 ) {
F_4 () ;
} else {
F_48 ( V_13 -> V_43 ) ;
F_49 ( V_40 . V_104 . V_43 ) ;
}
}
static int F_50 ( struct V_105 * V_106 , int V_83 )
{
struct V_12 * V_13 = F_51 ( V_107 [ V_83 ] , V_106 -> V_108 ) ;
F_52 () ;
while ( 1 ) {
if ( V_13 -> V_51 == V_52 )
F_6 () ;
else if ( V_13 -> V_51 == V_84 ) {
F_48 ( V_13 -> V_43 ) ;
F_49 ( V_40 . V_104 . V_43 ) ;
} else
return - V_39 ;
}
return 0 ;
}
static bool F_53 ( struct V_10 * V_11 )
{
return F_54 ( F_31 ) && ! V_11 -> V_41 . V_73 &&
! ( V_40 . V_41 & V_42 ) ;
}
static void F_55 ( struct V_10 * V_11 ,
struct V_12 * V_13 , bool V_109 )
{
F_56 ( F_57 () ) ;
if ( V_109 )
F_16 ( V_11 , V_13 , 1 ) ;
if ( V_11 -> V_41 . V_96 ) {
F_58 ( & V_110 ) ;
V_111 ++ ;
if ( V_111 == F_32 () )
F_22 ( V_112 , 1 ) ;
F_59 ( & V_110 ) ;
}
F_46 ( V_13 ) ;
if ( V_11 -> V_41 . V_96 ) {
F_58 ( & V_110 ) ;
F_22 ( V_112 , 0 ) ;
V_111 -- ;
F_59 ( & V_110 ) ;
}
if ( V_109 )
F_16 ( V_11 , V_13 , 0 ) ;
}
static int F_60 ( struct V_105 * V_106 ,
struct V_113 * V_114 , int V_83 )
{
struct V_12 * V_13 = F_51 ( V_107 [ V_83 ] , V_106 -> V_108 ) ;
struct V_10 * V_11 ;
V_11 = F_61 ( V_115 ) ;
if ( F_62 ( ! V_11 ) )
return - V_116 ;
if ( V_13 -> type != V_22 ) {
if ( F_53 ( V_11 ) && F_32 () > 1 ) {
V_83 = V_117 ;
V_13 = F_51 ( V_107 [ V_83 ] , V_106 -> V_108 ) ;
} else if ( V_13 -> type == V_18 && V_11 -> V_41 . V_95 ) {
if ( V_13 -> V_118 || ! F_44 () ) {
F_55 ( V_11 , V_13 , true ) ;
return V_83 ;
} else if ( V_114 -> V_119 >= 0 ) {
V_83 = V_114 -> V_119 ;
V_13 = F_51 ( V_107 [ V_83 ] , V_106 -> V_108 ) ;
} else {
F_4 () ;
return - V_120 ;
}
}
}
F_16 ( V_11 , V_13 , 1 ) ;
if ( V_13 -> type == V_18 )
F_52 () ;
F_46 ( V_13 ) ;
F_16 ( V_11 , V_13 , 0 ) ;
return V_83 ;
}
static void F_63 ( struct V_105 * V_106 ,
struct V_113 * V_114 , int V_83 )
{
struct V_12 * V_13 = F_51 ( V_107 [ V_83 ] , V_106 -> V_108 ) ;
if ( V_13 -> type == V_18 ) {
struct V_10 * V_11 = F_61 ( V_115 ) ;
if ( F_62 ( ! V_11 ) )
return;
if ( V_11 -> V_41 . V_95 ) {
F_55 ( V_11 , V_13 , false ) ;
return;
} else {
F_52 () ;
}
}
F_46 ( V_13 ) ;
}
static int F_64 ( struct V_10 * V_11 ,
struct V_105 * V_106 )
{
int V_57 , V_55 = V_117 ;
struct V_12 * V_13 ;
if ( ! V_11 -> V_41 . V_121 )
return - V_116 ;
if ( V_11 -> V_41 . V_16 == 0 ) {
return - V_116 ;
}
if ( ! V_106 )
return - V_116 ;
V_106 -> V_108 = V_11 -> V_5 ;
if ( V_6 == 0 )
V_6 = 1 ;
for ( V_57 = 1 ; V_57 < V_7 && V_57 <= V_6 ; V_57 ++ ) {
V_13 = & V_11 -> V_16 . V_27 [ V_57 ] ;
if ( ! V_13 -> V_50 )
continue;
F_51 ( V_107 [ V_55 ] , V_106 -> V_108 ) = V_13 ;
V_55 ++ ;
if ( V_55 == V_122 )
break;
}
if ( ! V_55 )
return - V_116 ;
return 0 ;
}
static int F_65 ( struct V_10 * V_11 )
{
int V_57 , V_55 = V_117 ;
struct V_12 * V_13 ;
struct V_123 * V_9 ;
struct V_113 * V_114 = & V_124 ;
if ( ! V_11 -> V_41 . V_121 )
return - V_116 ;
if ( V_11 -> V_41 . V_16 == 0 )
return - V_116 ;
V_114 -> V_119 = - 1 ;
for ( V_57 = V_117 ; V_57 < V_122 ; V_57 ++ ) {
V_114 -> V_27 [ V_57 ] . V_125 [ 0 ] = '\0' ;
V_114 -> V_27 [ V_57 ] . V_86 [ 0 ] = '\0' ;
}
if ( V_6 == 0 )
V_6 = 1 ;
for ( V_57 = 1 ; V_57 < V_7 && V_57 <= V_6 ; V_57 ++ ) {
V_13 = & V_11 -> V_16 . V_27 [ V_57 ] ;
if ( ! V_13 -> V_50 )
continue;
V_9 = & V_114 -> V_27 [ V_55 ] ;
snprintf ( V_9 -> V_125 , V_126 , L_21 , V_57 ) ;
strncpy ( V_9 -> V_86 , V_13 -> V_86 , V_127 ) ;
V_9 -> V_128 = V_13 -> V_44 ;
V_9 -> V_129 = V_13 -> V_44 * V_130 ;
V_9 -> V_131 = F_60 ;
V_9 -> V_41 = 0 ;
if ( V_13 -> type == V_22 || V_13 -> type == V_19 ) {
V_9 -> V_132 = F_50 ;
V_114 -> V_119 = V_55 ;
}
if ( V_13 -> type != V_22 && ! F_53 ( V_11 ) )
V_9 -> V_133 = F_63 ;
V_55 ++ ;
if ( V_55 == V_122 )
break;
}
V_114 -> V_134 = V_55 ;
if ( ! V_55 )
return - V_116 ;
return 0 ;
}
int F_66 ( struct V_10 * V_11 )
{
int V_58 = 0 ;
struct V_105 * V_106 ;
if ( F_1 () )
return 0 ;
if ( V_64 )
return - V_39 ;
if ( ! V_11 -> V_41 . V_121 )
return - V_39 ;
V_106 = F_51 ( V_135 , V_11 -> V_5 ) ;
F_67 () ;
F_68 ( V_106 ) ;
F_43 ( V_11 ) ;
if ( V_11 -> V_41 . V_16 ) {
F_64 ( V_11 , V_106 ) ;
V_58 = F_69 ( V_106 ) ;
}
F_70 () ;
return V_58 ;
}
int F_71 ( struct V_10 * V_11 )
{
int V_108 ;
struct V_10 * V_136 ;
struct V_105 * V_106 ;
if ( F_1 () )
return 0 ;
if ( V_64 )
return - V_39 ;
if ( ! V_11 -> V_41 . V_121 )
return - V_39 ;
if ( V_11 -> V_5 == 0 && F_72 () == & V_124 ) {
F_73 () ;
F_67 () ;
F_74 (cpu) {
V_136 = F_51 ( V_115 , V_108 ) ;
if ( ! V_136 || ! V_136 -> V_41 . V_121 )
continue;
V_106 = F_51 ( V_135 , V_108 ) ;
F_68 ( V_106 ) ;
}
F_43 ( V_11 ) ;
F_65 ( V_11 ) ;
F_74 (cpu) {
V_136 = F_51 ( V_115 , V_108 ) ;
if ( ! V_136 || ! V_136 -> V_41 . V_121 )
continue;
F_43 ( V_136 ) ;
if ( V_136 -> V_41 . V_16 ) {
V_106 = F_51 ( V_135 , V_108 ) ;
F_64 ( V_136 , V_106 ) ;
F_69 ( V_106 ) ;
}
}
F_70 () ;
F_75 () ;
}
return 0 ;
}
int F_76 ( struct V_10 * V_11 )
{
T_3 V_54 ;
int V_137 ;
struct V_105 * V_106 ;
static int V_138 ;
if ( F_1 () )
return 0 ;
if ( ! V_138 ) {
F_77 ( V_139 ) ;
V_6 = F_78 ( V_6 ) ;
if ( V_6 < V_140 )
F_3 ( V_141
L_22 ,
V_6 ) ;
V_138 ++ ;
}
if ( V_40 . V_142 && ! V_64 ) {
V_54 =
F_79 ( V_40 . V_143 , V_40 . V_142 , 8 ) ;
if ( F_37 ( V_54 ) ) {
F_80 ( ( V_144 , V_54 ,
L_23 ) ) ;
}
}
F_43 ( V_11 ) ;
V_11 -> V_41 . V_121 = 1 ;
if ( V_11 -> V_41 . V_16 ) {
if ( ! V_145 ) {
F_65 ( V_11 ) ;
V_137 = F_81 ( & V_124 ) ;
if ( V_137 )
return V_137 ;
F_3 ( V_146 L_24 ,
V_124 . V_125 ) ;
}
V_106 = F_82 ( sizeof( * V_106 ) , V_147 ) ;
if ( ! V_106 )
return - V_148 ;
F_51 ( V_135 , V_11 -> V_5 ) = V_106 ;
F_64 ( V_11 , V_106 ) ;
V_137 = F_83 ( V_106 ) ;
if ( V_137 ) {
if ( V_145 == 0 )
F_84 ( & V_124 ) ;
return V_137 ;
}
V_145 ++ ;
}
return 0 ;
}
int F_85 ( struct V_10 * V_11 )
{
struct V_105 * V_106 = F_51 ( V_135 , V_11 -> V_5 ) ;
if ( F_1 () )
return 0 ;
if ( V_11 -> V_41 . V_16 ) {
F_86 ( V_106 ) ;
V_145 -- ;
if ( V_145 == 0 )
F_84 ( & V_124 ) ;
}
V_11 -> V_41 . V_121 = 0 ;
return 0 ;
}

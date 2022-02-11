static int F_1 ( void )
{
return V_1 == V_2 ||
V_1 == V_3 ||
V_1 == V_4 ;
}
static int F_2 ( const struct V_5 * V_6 )
{
if ( V_7 > V_8 )
return 0 ;
F_3 (KERN_NOTICE PREFIX L_1
L_2 , id->ident,
(long)id->driver_data, ACPI_PROCESSOR_MAX_POWER + 1 ) ;
V_7 = ( long ) V_6 -> V_9 ;
return 0 ;
}
static void F_4 ( void )
{
F_5 () -> V_10 &= ~ V_11 ;
F_6 () ;
if ( ! F_7 () ) {
F_8 () ;
F_9 () ;
}
F_5 () -> V_10 |= V_11 ;
}
static void F_10 ( int V_12 , struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_14 -> V_19 ;
T_1 type = V_20 ? V_21 : V_22 ;
if ( F_11 ( & F_12 ( V_14 -> V_6 ) , V_23 ) )
return;
if ( V_24 )
type = V_25 ;
if ( V_18 -> V_26 < V_12 )
return;
if ( V_16 -> type >= type )
V_14 -> V_19 . V_26 = V_12 ;
}
static void F_13 ( void * V_27 )
{
struct V_13 * V_14 = (struct V_13 * ) V_27 ;
unsigned long V_28 ;
V_28 = V_14 -> V_19 . V_26 < V_29 ?
V_30 : V_31 ;
F_14 ( V_28 , & V_14 -> V_6 ) ;
}
static void F_15 ( struct V_13 * V_14 )
{
F_16 ( V_14 -> V_6 , F_13 ,
( void * ) V_14 , 1 ) ;
}
static void F_17 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
int V_32 )
{
int V_12 = V_16 - V_14 -> V_19 . V_33 ;
if ( V_12 >= V_14 -> V_19 . V_26 ) {
unsigned long V_28 ;
V_28 = V_32 ? V_34 :
V_35 ;
F_14 ( V_28 , & V_14 -> V_6 ) ;
}
}
static void F_10 ( int V_12 , struct V_13 * V_14 ,
struct V_15 * V_36 ) { }
static void F_15 ( struct V_13 * V_14 ) { }
static void F_17 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
int V_32 )
{
}
static void F_18 ( void )
{
F_19 ( V_37 , & V_38 ) ;
}
static void F_20 ( void )
{
T_2 V_39 ;
F_19 ( V_37 , & V_39 ) ;
if ( V_39 != V_38 )
F_21 ( V_37 , V_38 ) ;
}
int F_22 ( struct V_40 * V_41 , T_3 V_12 )
{
if ( V_42 == 1 )
return 0 ;
F_18 () ;
V_42 = 1 ;
return 0 ;
}
int F_23 ( struct V_40 * V_41 )
{
if ( V_42 == 0 )
return 0 ;
F_20 () ;
V_42 = 0 ;
return 0 ;
}
static void F_24 ( int V_12 )
{
switch ( V_43 . V_44 ) {
case V_45 :
case V_46 :
if ( F_25 ( V_47 ) )
return;
default:
if ( V_12 > V_25 )
F_26 ( L_3 ) ;
}
}
static void F_24 ( int V_12 ) { return; }
static int F_27 ( struct V_13 * V_14 )
{
if ( ! V_14 )
return - V_48 ;
if ( ! V_14 -> V_49 )
return - V_50 ;
V_14 -> V_19 . V_33 [ V_22 ] . type = V_22 ;
V_14 -> V_19 . V_33 [ V_21 ] . type = V_21 ;
#ifndef F_28
if ( ( F_29 () > 1 ) &&
! ( V_51 . V_52 & V_53 ) )
return - V_50 ;
#endif
V_14 -> V_19 . V_33 [ V_22 ] . V_54 = V_14 -> V_49 + 4 ;
V_14 -> V_19 . V_33 [ V_21 ] . V_54 = V_14 -> V_49 + 5 ;
V_14 -> V_19 . V_33 [ V_22 ] . V_55 = V_51 . V_56 ;
V_14 -> V_19 . V_33 [ V_21 ] . V_55 = V_51 . V_57 ;
if ( V_51 . V_56 > V_58 ) {
F_30 ( ( V_59 ,
L_4 , V_51 . V_56 ) ) ;
V_14 -> V_19 . V_33 [ V_22 ] . V_54 = 0 ;
}
if ( V_51 . V_57 > V_60 ) {
F_30 ( ( V_59 ,
L_5 , V_51 . V_57 ) ) ;
V_14 -> V_19 . V_33 [ V_21 ] . V_54 = 0 ;
}
F_30 ( ( V_59 ,
L_6 ,
V_14 -> V_19 . V_33 [ V_22 ] . V_54 ,
V_14 -> V_19 . V_33 [ V_21 ] . V_54 ) ) ;
return 0 ;
}
static int F_31 ( struct V_13 * V_14 )
{
if ( ! V_14 -> V_19 . V_33 [ V_25 ] . V_61 ) {
V_14 -> V_19 . V_33 [ V_25 ] . type = V_25 ;
V_14 -> V_19 . V_33 [ V_25 ] . V_61 = 1 ;
V_14 -> V_19 . V_33 [ V_25 ] . V_62 = V_63 ;
}
V_14 -> V_19 . V_33 [ V_64 ] . V_61 = 1 ;
return 0 ;
}
static int F_32 ( struct V_13 * V_14 )
{
T_4 V_10 = 0 ;
T_5 V_65 ;
int V_66 ;
int V_67 ;
struct V_68 V_69 = { V_70 , NULL } ;
union V_71 * V_72 ;
if ( V_73 )
return - V_50 ;
V_66 = 0 ;
V_10 = F_33 ( V_14 -> V_74 , L_7 , NULL , & V_69 ) ;
if ( F_34 ( V_10 ) ) {
F_30 ( ( V_59 , L_8 ) ) ;
return - V_50 ;
}
V_72 = V_69 . V_75 ;
if ( ! V_72 || ( V_72 -> type != V_76 ) || V_72 -> V_77 . V_65 < 2 ) {
F_3 (KERN_ERR PREFIX L_9 ) ;
V_10 = - V_78 ;
goto V_79;
}
V_65 = V_72 -> V_77 . V_80 [ 0 ] . integer . V_81 ;
if ( V_65 < 1 || V_65 != V_72 -> V_77 . V_65 - 1 ) {
F_3 (KERN_ERR PREFIX L_10 ) ;
V_10 = - V_78 ;
goto V_79;
}
V_14 -> V_52 . V_82 = 1 ;
for ( V_67 = 1 ; V_67 <= V_65 ; V_67 ++ ) {
union V_71 * V_83 ;
union V_71 * V_84 ;
struct V_85 * V_86 ;
struct V_15 V_16 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_83 = & ( V_72 -> V_77 . V_80 [ V_67 ] ) ;
if ( V_83 -> type != V_76 )
continue;
if ( V_83 -> V_77 . V_65 != 4 )
continue;
V_84 = & ( V_83 -> V_77 . V_80 [ 0 ] ) ;
if ( V_84 -> type != V_87 )
continue;
V_86 = (struct V_85 * ) V_84 -> V_69 . V_75 ;
if ( V_86 -> V_88 != V_89 &&
( V_86 -> V_88 != V_90 ) )
continue;
V_84 = & ( V_83 -> V_77 . V_80 [ 1 ] ) ;
if ( V_84 -> type != V_91 )
continue;
V_16 . type = V_84 -> integer . V_81 ;
if ( V_67 == 1 && V_16 . type != V_25 )
V_66 ++ ;
V_16 . V_54 = V_86 -> V_54 ;
V_16 . V_92 = V_66 + 1 ;
V_16 . V_62 = V_93 ;
if ( V_86 -> V_88 == V_90 ) {
if ( F_35
( V_14 -> V_6 , & V_16 , V_86 ) == 0 ) {
V_16 . V_62 = V_94 ;
} else if ( V_16 . type == V_25 ) {
V_16 . V_62 = V_63 ;
snprintf ( V_16 . V_95 , V_96 , L_11 ) ;
} else {
continue;
}
if ( V_16 . type == V_25 &&
( V_1 == V_97 ) ) {
V_16 . V_62 = V_63 ;
snprintf ( V_16 . V_95 , V_96 , L_11 ) ;
}
} else {
snprintf ( V_16 . V_95 , V_96 , L_12 ,
V_16 . V_54 ) ;
}
if ( V_16 . type == V_25 ) {
V_16 . V_61 = 1 ;
}
V_84 = & ( V_83 -> V_77 . V_80 [ 2 ] ) ;
if ( V_84 -> type != V_91 )
continue;
V_16 . V_55 = V_84 -> integer . V_81 ;
V_84 = & ( V_83 -> V_77 . V_80 [ 3 ] ) ;
if ( V_84 -> type != V_91 )
continue;
V_16 . V_19 = V_84 -> integer . V_81 ;
V_66 ++ ;
memcpy ( & ( V_14 -> V_19 . V_33 [ V_66 ] ) , & V_16 , sizeof( V_16 ) ) ;
if ( V_66 >= ( V_8 - 1 ) ) {
F_3 ( V_98
L_13 ,
V_8 ) ;
F_3 ( V_98
L_14 ) ;
break;
}
}
F_30 ( ( V_59 , L_15 ,
V_66 ) ) ;
if ( V_66 < 2 )
V_10 = - V_78 ;
V_79:
F_36 ( V_69 . V_75 ) ;
return V_10 ;
}
static void F_37 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
static int V_99 = - 1 ;
static int V_100 = - 1 ;
if ( ! V_16 -> V_54 )
return;
else if ( V_101 . V_102 . V_103 ) {
F_30 ( ( V_59 ,
L_16 ) ) ;
return;
}
if ( V_99 == - 1 ) {
F_38 ( & ( V_14 -> V_52 ) , V_14 -> V_6 ) ;
V_99 = V_14 -> V_52 . V_104 ;
V_100 = V_14 -> V_52 . V_105 ;
} else {
V_14 -> V_52 . V_104 = V_99 ;
V_14 -> V_52 . V_105 = V_100 ;
}
if ( V_14 -> V_52 . V_104 ) {
if ( ! V_14 -> V_52 . V_105 ) {
if ( V_14 -> V_52 . V_82 != 1 ) {
F_30 ( ( V_59 ,
L_17 ) ) ;
return;
} else {
F_30 ( ( V_59 ,
L_18 ) ) ;
}
}
} else {
if ( ! ( V_51 . V_52 & V_106 ) ) {
F_30 ( ( V_59 ,
L_19
L_20 ) ) ;
return;
}
}
V_16 -> V_61 = 1 ;
V_16 -> V_107 = V_16 -> V_55 ;
F_21 ( V_37 , 1 ) ;
return;
}
static int F_39 ( struct V_13 * V_14 )
{
unsigned int V_67 ;
unsigned int V_108 = 0 ;
V_14 -> V_19 . V_26 = V_29 ;
for ( V_67 = 1 ; V_67 < V_8 && V_67 <= V_7 ; V_67 ++ ) {
struct V_15 * V_16 = & V_14 -> V_19 . V_33 [ V_67 ] ;
switch ( V_16 -> type ) {
case V_25 :
V_16 -> V_61 = 1 ;
break;
case V_22 :
if ( ! V_16 -> V_54 )
break;
V_16 -> V_61 = 1 ;
V_16 -> V_107 = V_16 -> V_55 ;
break;
case V_21 :
F_37 ( V_14 , V_16 ) ;
break;
}
if ( ! V_16 -> V_61 )
continue;
F_10 ( V_67 , V_14 , V_16 ) ;
F_24 ( V_16 -> type ) ;
V_108 ++ ;
}
F_15 ( V_14 ) ;
return ( V_108 ) ;
}
static int F_40 ( struct V_13 * V_14 )
{
unsigned int V_67 ;
int V_109 ;
memset ( V_14 -> V_19 . V_33 , 0 , sizeof( V_14 -> V_19 . V_33 ) ) ;
V_109 = F_32 ( V_14 ) ;
if ( V_109 == - V_50 )
V_109 = F_27 ( V_14 ) ;
if ( V_109 )
return V_109 ;
F_31 ( V_14 ) ;
V_14 -> V_19 . V_65 = F_39 ( V_14 ) ;
for ( V_67 = 1 ; V_67 < V_8 ; V_67 ++ ) {
if ( V_14 -> V_19 . V_33 [ V_67 ] . V_61 ) {
V_14 -> V_19 . V_65 = V_67 ;
if ( V_14 -> V_19 . V_33 [ V_67 ] . type >= V_22 )
V_14 -> V_52 . V_19 = 1 ;
}
}
return 0 ;
}
static int F_41 ( void )
{
T_2 V_110 = 0 ;
if ( V_111 )
return 0 ;
F_19 ( V_112 , & V_110 ) ;
if ( V_110 )
F_21 ( V_112 , 1 ) ;
else if ( V_101 . V_102 . V_113 ) {
if ( ( F_42 ( V_101 . V_102 . V_113 + 0x02 ) & 0x01 )
|| ( F_42 ( V_101 . V_102 . V_113 + 0x0A ) & 0x01 ) )
V_110 = 1 ;
}
return V_110 ;
}
static inline void F_43 ( struct V_15 * V_16 )
{
F_44 () ;
if ( V_16 -> V_62 == V_94 ) {
F_45 ( V_16 ) ;
} else if ( V_16 -> V_62 == V_63 ) {
F_4 () ;
} else {
F_46 ( V_16 -> V_54 ) ;
F_47 ( V_51 . V_114 . V_54 ) ;
}
F_48 () ;
}
static int F_49 ( struct V_115 * V_116 ,
struct V_117 * V_12 )
{
T_6 V_118 , V_119 ;
T_7 V_120 ;
struct V_13 * V_14 ;
struct V_15 * V_16 = F_50 ( V_12 ) ;
V_14 = F_51 ( V_121 ) ;
if ( F_52 ( ! V_14 ) )
return 0 ;
F_9 () ;
if ( V_42 ) {
F_53 () ;
F_54 () ;
return 0 ;
}
F_17 ( V_14 , V_16 , 1 ) ;
V_118 = F_55 () ;
F_43 ( V_16 ) ;
V_119 = F_55 () ;
V_120 = F_56 ( F_57 ( V_119 , V_118 ) ) ;
F_53 () ;
V_16 -> V_122 ++ ;
F_17 ( V_14 , V_16 , 0 ) ;
return V_120 ;
}
static int F_58 ( struct V_115 * V_116 ,
struct V_117 * V_12 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 = F_50 ( V_12 ) ;
T_6 V_118 , V_119 ;
T_7 V_123 ;
T_7 V_120 ;
V_14 = F_51 ( V_121 ) ;
if ( F_52 ( ! V_14 ) )
return 0 ;
if ( V_42 )
return ( F_49 ( V_116 , V_12 ) ) ;
F_9 () ;
if ( V_16 -> V_62 != V_94 ) {
F_5 () -> V_10 &= ~ V_11 ;
F_6 () ;
if ( F_52 ( F_7 () ) ) {
F_5 () -> V_10 |= V_11 ;
F_53 () ;
return 0 ;
}
}
F_17 ( V_14 , V_16 , 1 ) ;
if ( V_16 -> type == V_21 )
F_59 () ;
V_118 = F_55 () ;
F_60 () ;
F_43 ( V_16 ) ;
V_119 = F_55 () ;
V_123 = F_61 ( F_57 ( V_119 , V_118 ) ) ;
V_120 = V_123 ;
F_62 ( V_120 , V_124 ) ;
F_63 ( V_123 ) ;
F_53 () ;
if ( V_16 -> V_62 != V_94 )
F_5 () -> V_10 |= V_11 ;
V_16 -> V_122 ++ ;
F_17 ( V_14 , V_16 , 0 ) ;
V_16 -> time += V_120 ;
return V_120 ;
}
static int F_64 ( struct V_115 * V_116 ,
struct V_117 * V_12 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 = F_50 ( V_12 ) ;
T_6 V_118 , V_119 ;
T_7 V_123 ;
T_7 V_120 ;
V_14 = F_51 ( V_121 ) ;
if ( F_52 ( ! V_14 ) )
return 0 ;
if ( V_42 )
return ( F_49 ( V_116 , V_12 ) ) ;
if ( ! V_16 -> V_125 && F_41 () ) {
if ( V_116 -> V_126 ) {
V_116 -> V_127 = V_116 -> V_126 ;
return V_116 -> V_126 -> V_128 ( V_116 , V_116 -> V_126 ) ;
} else {
F_9 () ;
F_4 () ;
F_53 () ;
return 0 ;
}
}
F_9 () ;
if ( V_16 -> V_62 != V_94 ) {
F_5 () -> V_10 &= ~ V_11 ;
F_6 () ;
if ( F_52 ( F_7 () ) ) {
F_5 () -> V_10 |= V_11 ;
F_53 () ;
return 0 ;
}
}
F_65 ( F_66 () ) ;
F_60 () ;
F_17 ( V_14 , V_16 , 1 ) ;
V_118 = F_55 () ;
if ( V_14 -> V_52 . V_104 && V_14 -> V_52 . V_105 ) {
F_67 ( & V_129 ) ;
V_130 ++ ;
if ( V_130 == F_29 () )
F_21 ( V_131 , 1 ) ;
F_68 ( & V_129 ) ;
} else if ( ! V_14 -> V_52 . V_104 ) {
F_59 () ;
}
F_43 ( V_16 ) ;
if ( V_14 -> V_52 . V_104 && V_14 -> V_52 . V_105 ) {
F_67 ( & V_129 ) ;
F_21 ( V_131 , 0 ) ;
V_130 -- ;
F_68 ( & V_129 ) ;
}
V_119 = F_55 () ;
V_123 = F_61 ( F_57 ( V_119 , V_118 ) ) ;
V_120 = V_123 ;
F_62 ( V_120 , V_124 ) ;
F_63 ( V_123 ) ;
F_53 () ;
if ( V_16 -> V_62 != V_94 )
F_5 () -> V_10 |= V_11 ;
V_16 -> V_122 ++ ;
F_17 ( V_14 , V_16 , 0 ) ;
V_16 -> time += V_120 ;
return V_120 ;
}
static int F_69 ( struct V_13 * V_14 )
{
int V_67 , V_65 = V_132 ;
struct V_15 * V_16 ;
struct V_117 * V_12 ;
struct V_115 * V_116 = & V_14 -> V_19 . V_116 ;
if ( ! V_14 -> V_52 . V_133 )
return - V_48 ;
if ( V_14 -> V_52 . V_19 == 0 ) {
return - V_48 ;
}
V_116 -> V_134 = V_14 -> V_6 ;
for ( V_67 = 0 ; V_67 < V_135 ; V_67 ++ ) {
V_116 -> V_33 [ V_67 ] . V_136 [ 0 ] = '\0' ;
V_116 -> V_33 [ V_67 ] . V_95 [ 0 ] = '\0' ;
}
if ( V_7 == 0 )
V_7 = 1 ;
for ( V_67 = 1 ; V_67 < V_8 && V_67 <= V_7 ; V_67 ++ ) {
V_16 = & V_14 -> V_19 . V_33 [ V_67 ] ;
V_12 = & V_116 -> V_33 [ V_65 ] ;
if ( ! V_16 -> V_61 )
continue;
#ifdef F_28
if ( ( V_16 -> type != V_25 ) && ( F_29 () > 1 ) &&
! V_14 -> V_52 . V_82 &&
! ( V_51 . V_52 & V_53 ) )
continue;
#endif
F_70 ( V_12 , V_16 ) ;
snprintf ( V_12 -> V_136 , V_137 , L_21 , V_67 ) ;
strncpy ( V_12 -> V_95 , V_16 -> V_95 , V_138 ) ;
V_12 -> V_139 = V_16 -> V_55 ;
V_12 -> V_140 = V_16 -> V_55 * V_141 ;
V_12 -> V_52 = 0 ;
switch ( V_16 -> type ) {
case V_25 :
if ( V_16 -> V_62 == V_94 )
V_12 -> V_52 |= V_142 ;
V_12 -> V_128 = F_49 ;
V_116 -> V_126 = V_12 ;
break;
case V_22 :
V_12 -> V_52 |= V_142 ;
V_12 -> V_128 = F_58 ;
V_116 -> V_126 = V_12 ;
break;
case V_21 :
V_12 -> V_52 |= V_142 ;
V_12 -> V_128 = V_14 -> V_52 . V_104 ?
F_64 :
F_58 ;
break;
}
V_65 ++ ;
if ( V_65 == V_135 )
break;
}
V_116 -> V_143 = V_65 ;
if ( ! V_65 )
return - V_48 ;
return 0 ;
}
int F_71 ( struct V_13 * V_14 )
{
int V_144 = 0 ;
if ( F_1 () )
return 0 ;
if ( ! V_14 )
return - V_48 ;
if ( V_73 ) {
return - V_50 ;
}
if ( ! V_14 -> V_52 . V_133 )
return - V_50 ;
F_72 () ;
F_73 ( & V_14 -> V_19 . V_116 ) ;
F_40 ( V_14 ) ;
if ( V_14 -> V_52 . V_19 ) {
F_69 ( V_14 ) ;
V_144 = F_74 ( & V_14 -> V_19 . V_116 ) ;
}
F_75 () ;
return V_144 ;
}
int T_8 F_76 ( struct V_13 * V_14 ,
struct V_40 * V_41 )
{
T_4 V_10 = 0 ;
static int V_145 ;
if ( F_1 () )
return 0 ;
if ( ! V_145 ) {
F_77 ( V_146 ) ;
V_7 = F_78 ( V_7 ) ;
if ( V_7 < V_147 )
F_3 ( V_148
L_22 ,
V_7 ) ;
V_145 ++ ;
}
if ( ! V_14 )
return - V_48 ;
if ( V_51 . V_149 && ! V_73 ) {
V_10 =
F_79 ( V_51 . V_150 , V_51 . V_149 , 8 ) ;
if ( F_34 ( V_10 ) ) {
F_80 ( ( V_151 , V_10 ,
L_23 ) ) ;
}
}
F_40 ( V_14 ) ;
V_14 -> V_52 . V_133 = 1 ;
if ( V_14 -> V_52 . V_19 ) {
F_69 ( V_14 ) ;
if ( F_81 ( & V_14 -> V_19 . V_116 ) )
return - V_152 ;
}
return 0 ;
}
int F_82 ( struct V_13 * V_14 ,
struct V_40 * V_41 )
{
if ( F_1 () )
return 0 ;
F_83 ( & V_14 -> V_19 . V_116 ) ;
V_14 -> V_52 . V_133 = 0 ;
return 0 ;
}

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
struct V_117 * V_118 , int V_92 )
{
T_6 V_119 , V_120 ;
T_7 V_121 ;
struct V_13 * V_14 ;
struct V_122 * V_123 = & V_116 -> V_124 [ V_92 ] ;
struct V_15 * V_16 = F_50 ( V_123 ) ;
V_14 = F_51 ( V_125 ) ;
V_116 -> V_126 = 0 ;
if ( F_52 ( ! V_14 ) )
return - V_48 ;
F_9 () ;
if ( V_42 ) {
F_53 () ;
F_54 () ;
return - V_127 ;
}
F_17 ( V_14 , V_16 , 1 ) ;
V_119 = F_55 () ;
F_43 ( V_16 ) ;
V_120 = F_55 () ;
V_121 = F_56 ( F_57 ( V_120 , V_119 ) ) ;
V_116 -> V_126 = ( int ) V_121 ;
F_53 () ;
V_16 -> V_128 ++ ;
F_17 ( V_14 , V_16 , 0 ) ;
return V_92 ;
}
static int F_58 ( struct V_115 * V_116 , int V_92 )
{
struct V_122 * V_123 = & V_116 -> V_124 [ V_92 ] ;
struct V_15 * V_16 = F_50 ( V_123 ) ;
F_59 () ;
while ( 1 ) {
if ( V_16 -> V_62 == V_63 )
F_8 () ;
else if ( V_16 -> V_62 == V_93 ) {
F_46 ( V_16 -> V_54 ) ;
F_47 ( V_51 . V_114 . V_54 ) ;
} else
return - V_50 ;
}
return 0 ;
}
static int F_60 ( struct V_115 * V_116 ,
struct V_117 * V_118 , int V_92 )
{
struct V_13 * V_14 ;
struct V_122 * V_123 = & V_116 -> V_124 [ V_92 ] ;
struct V_15 * V_16 = F_50 ( V_123 ) ;
T_6 V_119 , V_120 ;
T_7 V_129 ;
T_7 V_121 ;
V_14 = F_51 ( V_125 ) ;
V_116 -> V_126 = 0 ;
if ( F_52 ( ! V_14 ) )
return - V_48 ;
F_9 () ;
if ( V_42 ) {
F_53 () ;
F_54 () ;
return - V_127 ;
}
if ( V_16 -> V_62 != V_94 ) {
F_5 () -> V_10 &= ~ V_11 ;
F_6 () ;
if ( F_52 ( F_7 () ) ) {
F_5 () -> V_10 |= V_11 ;
F_53 () ;
return - V_48 ;
}
}
F_17 ( V_14 , V_16 , 1 ) ;
if ( V_16 -> type == V_21 )
F_59 () ;
V_119 = F_55 () ;
F_61 () ;
F_43 ( V_16 ) ;
V_120 = F_55 () ;
V_129 = F_62 ( F_57 ( V_120 , V_119 ) ) ;
V_121 = V_129 ;
F_63 ( V_121 , V_130 ) ;
V_116 -> V_126 = ( int ) V_121 ;
F_64 ( V_129 ) ;
F_53 () ;
if ( V_16 -> V_62 != V_94 )
F_5 () -> V_10 |= V_11 ;
V_16 -> V_128 ++ ;
F_17 ( V_14 , V_16 , 0 ) ;
V_16 -> time += V_121 ;
return V_92 ;
}
static int F_65 ( struct V_115 * V_116 ,
struct V_117 * V_118 , int V_92 )
{
struct V_13 * V_14 ;
struct V_122 * V_123 = & V_116 -> V_124 [ V_92 ] ;
struct V_15 * V_16 = F_50 ( V_123 ) ;
T_6 V_119 , V_120 ;
T_7 V_129 ;
T_7 V_121 ;
V_14 = F_51 ( V_125 ) ;
V_116 -> V_126 = 0 ;
if ( F_52 ( ! V_14 ) )
return - V_48 ;
if ( ! V_16 -> V_131 && F_41 () ) {
if ( V_118 -> V_132 >= 0 ) {
return V_118 -> V_33 [ V_118 -> V_132 ] . F_66 ( V_116 ,
V_118 , V_118 -> V_132 ) ;
} else {
F_9 () ;
if ( ! V_42 )
F_4 () ;
F_53 () ;
return - V_127 ;
}
}
F_9 () ;
if ( V_42 ) {
F_53 () ;
F_54 () ;
return - V_127 ;
}
if ( V_16 -> V_62 != V_94 ) {
F_5 () -> V_10 &= ~ V_11 ;
F_6 () ;
if ( F_52 ( F_7 () ) ) {
F_5 () -> V_10 |= V_11 ;
F_53 () ;
return - V_48 ;
}
}
F_67 ( F_68 () ) ;
F_61 () ;
F_17 ( V_14 , V_16 , 1 ) ;
V_119 = F_55 () ;
if ( V_14 -> V_52 . V_104 && V_14 -> V_52 . V_105 ) {
F_69 ( & V_133 ) ;
V_134 ++ ;
if ( V_134 == F_29 () )
F_21 ( V_135 , 1 ) ;
F_70 ( & V_133 ) ;
} else if ( ! V_14 -> V_52 . V_104 ) {
F_59 () ;
}
F_43 ( V_16 ) ;
if ( V_14 -> V_52 . V_104 && V_14 -> V_52 . V_105 ) {
F_69 ( & V_133 ) ;
F_21 ( V_135 , 0 ) ;
V_134 -- ;
F_70 ( & V_133 ) ;
}
V_120 = F_55 () ;
V_129 = F_62 ( F_57 ( V_120 , V_119 ) ) ;
V_121 = V_129 ;
F_63 ( V_121 , V_130 ) ;
V_116 -> V_126 = ( int ) V_121 ;
F_64 ( V_129 ) ;
F_53 () ;
if ( V_16 -> V_62 != V_94 )
F_5 () -> V_10 |= V_11 ;
V_16 -> V_128 ++ ;
F_17 ( V_14 , V_16 , 0 ) ;
V_16 -> time += V_121 ;
return V_92 ;
}
static int F_71 ( struct V_13 * V_14 )
{
int V_67 , V_65 = V_136 ;
struct V_15 * V_16 ;
struct V_122 * V_123 ;
struct V_115 * V_116 = & V_14 -> V_19 . V_116 ;
if ( ! V_14 -> V_52 . V_137 )
return - V_48 ;
if ( V_14 -> V_52 . V_19 == 0 ) {
return - V_48 ;
}
V_116 -> V_138 = V_14 -> V_6 ;
if ( V_7 == 0 )
V_7 = 1 ;
for ( V_67 = 1 ; V_67 < V_8 && V_67 <= V_7 ; V_67 ++ ) {
V_16 = & V_14 -> V_19 . V_33 [ V_67 ] ;
V_123 = & V_116 -> V_124 [ V_65 ] ;
if ( ! V_16 -> V_61 )
continue;
#ifdef F_28
if ( ( V_16 -> type != V_25 ) && ( F_29 () > 1 ) &&
! V_14 -> V_52 . V_82 &&
! ( V_51 . V_52 & V_53 ) )
continue;
#endif
F_72 ( V_123 , V_16 ) ;
V_65 ++ ;
if ( V_65 == V_139 )
break;
}
V_116 -> V_140 = V_65 ;
if ( ! V_65 )
return - V_48 ;
return 0 ;
}
static int F_73 ( struct V_13 * V_14 )
{
int V_67 , V_65 = V_136 ;
struct V_15 * V_16 ;
struct V_141 * V_12 ;
struct V_117 * V_118 = & V_142 ;
if ( ! V_14 -> V_52 . V_137 )
return - V_48 ;
if ( V_14 -> V_52 . V_19 == 0 )
return - V_48 ;
V_118 -> V_132 = - 1 ;
for ( V_67 = 0 ; V_67 < V_139 ; V_67 ++ ) {
V_118 -> V_33 [ V_67 ] . V_143 [ 0 ] = '\0' ;
V_118 -> V_33 [ V_67 ] . V_95 [ 0 ] = '\0' ;
}
if ( V_7 == 0 )
V_7 = 1 ;
for ( V_67 = 1 ; V_67 < V_8 && V_67 <= V_7 ; V_67 ++ ) {
V_16 = & V_14 -> V_19 . V_33 [ V_67 ] ;
if ( ! V_16 -> V_61 )
continue;
#ifdef F_28
if ( ( V_16 -> type != V_25 ) && ( F_29 () > 1 ) &&
! V_14 -> V_52 . V_82 &&
! ( V_51 . V_52 & V_53 ) )
continue;
#endif
V_12 = & V_118 -> V_33 [ V_65 ] ;
snprintf ( V_12 -> V_143 , V_144 , L_21 , V_67 ) ;
strncpy ( V_12 -> V_95 , V_16 -> V_95 , V_145 ) ;
V_12 -> V_146 = V_16 -> V_55 ;
V_12 -> V_147 = V_16 -> V_55 * V_148 ;
V_12 -> V_52 = 0 ;
switch ( V_16 -> type ) {
case V_25 :
if ( V_16 -> V_62 == V_94 )
V_12 -> V_52 |= V_149 ;
V_12 -> F_66 = F_49 ;
V_12 -> V_150 = F_58 ;
V_118 -> V_132 = V_65 ;
break;
case V_22 :
V_12 -> V_52 |= V_149 ;
V_12 -> F_66 = F_60 ;
V_12 -> V_150 = F_58 ;
V_118 -> V_132 = V_65 ;
break;
case V_21 :
V_12 -> V_52 |= V_149 ;
V_12 -> F_66 = V_14 -> V_52 . V_104 ?
F_65 :
F_60 ;
break;
}
V_65 ++ ;
if ( V_65 == V_139 )
break;
}
V_118 -> V_140 = V_65 ;
if ( ! V_65 )
return - V_48 ;
return 0 ;
}
int F_74 ( struct V_13 * V_14 )
{
int V_151 = 0 ;
if ( F_1 () )
return 0 ;
if ( ! V_14 )
return - V_48 ;
if ( V_73 ) {
return - V_50 ;
}
if ( ! V_14 -> V_52 . V_137 )
return - V_50 ;
F_75 () ;
F_76 ( & V_14 -> V_19 . V_116 ) ;
F_40 ( V_14 ) ;
if ( V_14 -> V_52 . V_19 ) {
F_71 ( V_14 ) ;
V_151 = F_77 ( & V_14 -> V_19 . V_116 ) ;
}
F_78 () ;
return V_151 ;
}
int F_79 ( struct V_13 * V_14 )
{
int V_138 ;
struct V_13 * V_152 ;
if ( F_1 () )
return 0 ;
if ( ! V_14 )
return - V_48 ;
if ( V_73 )
return - V_50 ;
if ( ! V_14 -> V_52 . V_137 )
return - V_50 ;
if ( V_14 -> V_6 == 0 && F_80 () == & V_142 ) {
F_75 () ;
F_81 () ;
F_82 (cpu) {
V_152 = F_83 ( V_125 , V_138 ) ;
if ( ! V_152 || ! V_152 -> V_52 . V_137 )
continue;
F_76 ( & V_152 -> V_19 . V_116 ) ;
}
F_73 ( V_14 ) ;
F_82 (cpu) {
V_152 = F_83 ( V_125 , V_138 ) ;
if ( ! V_152 || ! V_152 -> V_52 . V_137 )
continue;
F_40 ( V_152 ) ;
if ( V_152 -> V_52 . V_19 ) {
F_71 ( V_152 ) ;
F_77 ( & V_152 -> V_19 . V_116 ) ;
}
}
F_84 () ;
F_78 () ;
}
return 0 ;
}
int T_8 F_85 ( struct V_13 * V_14 ,
struct V_40 * V_41 )
{
T_4 V_10 = 0 ;
int V_153 ;
static int V_154 ;
if ( F_1 () )
return 0 ;
if ( ! V_154 ) {
F_86 ( V_155 ) ;
V_7 = F_87 ( V_7 ) ;
if ( V_7 < V_156 )
F_3 ( V_157
L_22 ,
V_7 ) ;
V_154 ++ ;
}
if ( ! V_14 )
return - V_48 ;
if ( V_51 . V_158 && ! V_73 ) {
V_10 =
F_88 ( V_51 . V_159 , V_51 . V_158 , 8 ) ;
if ( F_34 ( V_10 ) ) {
F_89 ( ( V_160 , V_10 ,
L_23 ) ) ;
}
}
F_40 ( V_14 ) ;
V_14 -> V_52 . V_137 = 1 ;
if ( V_14 -> V_52 . V_19 ) {
if ( ! V_161 ) {
F_73 ( V_14 ) ;
V_153 = F_90 ( & V_142 ) ;
if ( V_153 )
return V_153 ;
F_3 ( V_162 L_24 ,
V_142 . V_143 ) ;
}
F_71 ( V_14 ) ;
V_153 = F_91 ( & V_14 -> V_19 . V_116 ) ;
if ( V_153 ) {
if ( V_161 == 0 )
F_92 ( & V_142 ) ;
return V_153 ;
}
V_161 ++ ;
}
return 0 ;
}
int F_93 ( struct V_13 * V_14 ,
struct V_40 * V_41 )
{
if ( F_1 () )
return 0 ;
if ( V_14 -> V_52 . V_19 ) {
F_94 ( & V_14 -> V_19 . V_116 ) ;
V_161 -- ;
if ( V_161 == 0 )
F_92 ( & V_142 ) ;
}
V_14 -> V_52 . V_137 = 0 ;
return 0 ;
}

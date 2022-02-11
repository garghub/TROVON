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
F_18 () ;
return 0 ;
}
int F_23 ( struct V_40 * V_41 )
{
F_20 () ;
return 0 ;
}
static void F_24 ( int V_12 )
{
switch ( V_42 . V_43 ) {
case V_44 :
case V_45 :
if ( F_25 ( V_46 ) )
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
return - V_47 ;
if ( ! V_14 -> V_48 )
return - V_49 ;
V_14 -> V_19 . V_33 [ V_22 ] . type = V_22 ;
V_14 -> V_19 . V_33 [ V_21 ] . type = V_21 ;
#ifndef F_28
if ( ( F_29 () > 1 ) &&
! ( V_50 . V_51 & V_52 ) )
return - V_49 ;
#endif
V_14 -> V_19 . V_33 [ V_22 ] . V_53 = V_14 -> V_48 + 4 ;
V_14 -> V_19 . V_33 [ V_21 ] . V_53 = V_14 -> V_48 + 5 ;
V_14 -> V_19 . V_33 [ V_22 ] . V_54 = V_50 . V_55 ;
V_14 -> V_19 . V_33 [ V_21 ] . V_54 = V_50 . V_56 ;
if ( V_50 . V_55 > V_57 ) {
F_30 ( ( V_58 ,
L_4 , V_50 . V_55 ) ) ;
V_14 -> V_19 . V_33 [ V_22 ] . V_53 = 0 ;
}
if ( V_50 . V_56 > V_59 ) {
F_30 ( ( V_58 ,
L_5 , V_50 . V_56 ) ) ;
V_14 -> V_19 . V_33 [ V_21 ] . V_53 = 0 ;
}
F_30 ( ( V_58 ,
L_6 ,
V_14 -> V_19 . V_33 [ V_22 ] . V_53 ,
V_14 -> V_19 . V_33 [ V_21 ] . V_53 ) ) ;
return 0 ;
}
static int F_31 ( struct V_13 * V_14 )
{
if ( ! V_14 -> V_19 . V_33 [ V_25 ] . V_60 ) {
V_14 -> V_19 . V_33 [ V_25 ] . type = V_25 ;
V_14 -> V_19 . V_33 [ V_25 ] . V_60 = 1 ;
V_14 -> V_19 . V_33 [ V_25 ] . V_61 = V_62 ;
}
V_14 -> V_19 . V_33 [ V_63 ] . V_60 = 1 ;
return 0 ;
}
static int F_32 ( struct V_13 * V_14 )
{
T_4 V_10 = 0 ;
T_5 V_64 ;
int V_65 ;
int V_66 ;
struct V_67 V_68 = { V_69 , NULL } ;
union V_70 * V_71 ;
if ( V_72 )
return - V_49 ;
V_65 = 0 ;
V_10 = F_33 ( V_14 -> V_73 , L_7 , NULL , & V_68 ) ;
if ( F_34 ( V_10 ) ) {
F_30 ( ( V_58 , L_8 ) ) ;
return - V_49 ;
}
V_71 = V_68 . V_74 ;
if ( ! V_71 || ( V_71 -> type != V_75 ) || V_71 -> V_76 . V_64 < 2 ) {
F_3 (KERN_ERR PREFIX L_9 ) ;
V_10 = - V_77 ;
goto V_78;
}
V_64 = V_71 -> V_76 . V_79 [ 0 ] . integer . V_80 ;
if ( V_64 < 1 || V_64 != V_71 -> V_76 . V_64 - 1 ) {
F_3 (KERN_ERR PREFIX L_10 ) ;
V_10 = - V_77 ;
goto V_78;
}
V_14 -> V_51 . V_81 = 1 ;
for ( V_66 = 1 ; V_66 <= V_64 ; V_66 ++ ) {
union V_70 * V_82 ;
union V_70 * V_83 ;
struct V_84 * V_85 ;
struct V_15 V_16 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_82 = & ( V_71 -> V_76 . V_79 [ V_66 ] ) ;
if ( V_82 -> type != V_75 )
continue;
if ( V_82 -> V_76 . V_64 != 4 )
continue;
V_83 = & ( V_82 -> V_76 . V_79 [ 0 ] ) ;
if ( V_83 -> type != V_86 )
continue;
V_85 = (struct V_84 * ) V_83 -> V_68 . V_74 ;
if ( V_85 -> V_87 != V_88 &&
( V_85 -> V_87 != V_89 ) )
continue;
V_83 = & ( V_82 -> V_76 . V_79 [ 1 ] ) ;
if ( V_83 -> type != V_90 )
continue;
V_16 . type = V_83 -> integer . V_80 ;
if ( V_66 == 1 && V_16 . type != V_25 )
V_65 ++ ;
V_16 . V_53 = V_85 -> V_53 ;
V_16 . V_91 = V_65 + 1 ;
V_16 . V_61 = V_92 ;
if ( V_85 -> V_87 == V_89 ) {
if ( F_35
( V_14 -> V_6 , & V_16 , V_85 ) == 0 ) {
V_16 . V_61 = V_93 ;
} else if ( V_16 . type == V_25 ) {
V_16 . V_61 = V_62 ;
snprintf ( V_16 . V_94 , V_95 , L_11 ) ;
} else {
continue;
}
if ( V_16 . type == V_25 &&
( V_1 == V_96 ) ) {
V_16 . V_61 = V_62 ;
snprintf ( V_16 . V_94 , V_95 , L_11 ) ;
}
} else {
snprintf ( V_16 . V_94 , V_95 , L_12 ,
V_16 . V_53 ) ;
}
if ( V_16 . type == V_25 ) {
V_16 . V_60 = 1 ;
}
V_83 = & ( V_82 -> V_76 . V_79 [ 2 ] ) ;
if ( V_83 -> type != V_90 )
continue;
V_16 . V_54 = V_83 -> integer . V_80 ;
V_83 = & ( V_82 -> V_76 . V_79 [ 3 ] ) ;
if ( V_83 -> type != V_90 )
continue;
V_16 . V_19 = V_83 -> integer . V_80 ;
V_65 ++ ;
memcpy ( & ( V_14 -> V_19 . V_33 [ V_65 ] ) , & V_16 , sizeof( V_16 ) ) ;
if ( V_65 >= ( V_8 - 1 ) ) {
F_3 ( V_97
L_13 ,
V_8 ) ;
F_3 ( V_97
L_14 ) ;
break;
}
}
F_30 ( ( V_58 , L_15 ,
V_65 ) ) ;
if ( V_65 < 2 )
V_10 = - V_77 ;
V_78:
F_36 ( V_68 . V_74 ) ;
return V_10 ;
}
static void F_37 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
static int V_98 = - 1 ;
static int V_99 = - 1 ;
if ( ! V_16 -> V_53 )
return;
else if ( V_100 . V_101 . V_102 ) {
F_30 ( ( V_58 ,
L_16 ) ) ;
return;
}
if ( V_98 == - 1 ) {
F_38 ( & ( V_14 -> V_51 ) , V_14 -> V_6 ) ;
V_98 = V_14 -> V_51 . V_103 ;
V_99 = V_14 -> V_51 . V_104 ;
} else {
V_14 -> V_51 . V_103 = V_98 ;
V_14 -> V_51 . V_104 = V_99 ;
}
if ( V_14 -> V_51 . V_103 ) {
if ( ! V_14 -> V_51 . V_104 ) {
if ( V_14 -> V_51 . V_81 != 1 ) {
F_30 ( ( V_58 ,
L_17 ) ) ;
return;
} else {
F_30 ( ( V_58 ,
L_18 ) ) ;
}
}
} else {
if ( ! ( V_50 . V_51 & V_105 ) ) {
F_30 ( ( V_58 ,
L_19
L_20 ) ) ;
return;
}
}
V_16 -> V_60 = 1 ;
V_16 -> V_106 = V_16 -> V_54 ;
F_21 ( V_37 , 1 ) ;
return;
}
static int F_39 ( struct V_13 * V_14 )
{
unsigned int V_66 ;
unsigned int V_107 = 0 ;
V_14 -> V_19 . V_26 = V_29 ;
for ( V_66 = 1 ; V_66 < V_8 && V_66 <= V_7 ; V_66 ++ ) {
struct V_15 * V_16 = & V_14 -> V_19 . V_33 [ V_66 ] ;
switch ( V_16 -> type ) {
case V_25 :
V_16 -> V_60 = 1 ;
break;
case V_22 :
if ( ! V_16 -> V_53 )
break;
V_16 -> V_60 = 1 ;
V_16 -> V_106 = V_16 -> V_54 ;
break;
case V_21 :
F_37 ( V_14 , V_16 ) ;
break;
}
if ( ! V_16 -> V_60 )
continue;
F_10 ( V_66 , V_14 , V_16 ) ;
F_24 ( V_16 -> type ) ;
V_107 ++ ;
}
F_15 ( V_14 ) ;
return ( V_107 ) ;
}
static int F_40 ( struct V_13 * V_14 )
{
unsigned int V_66 ;
int V_108 ;
memset ( V_14 -> V_19 . V_33 , 0 , sizeof( V_14 -> V_19 . V_33 ) ) ;
V_108 = F_32 ( V_14 ) ;
if ( V_108 == - V_49 )
V_108 = F_27 ( V_14 ) ;
if ( V_108 )
return V_108 ;
F_31 ( V_14 ) ;
V_14 -> V_19 . V_64 = F_39 ( V_14 ) ;
for ( V_66 = 1 ; V_66 < V_8 ; V_66 ++ ) {
if ( V_14 -> V_19 . V_33 [ V_66 ] . V_60 ) {
V_14 -> V_19 . V_64 = V_66 ;
if ( V_14 -> V_19 . V_33 [ V_66 ] . type >= V_22 )
V_14 -> V_51 . V_19 = 1 ;
}
}
return 0 ;
}
static int F_41 ( void )
{
T_2 V_109 = 0 ;
if ( V_110 )
return 0 ;
F_19 ( V_111 , & V_109 ) ;
if ( V_109 )
F_21 ( V_111 , 1 ) ;
else if ( V_100 . V_101 . V_112 ) {
if ( ( F_42 ( V_100 . V_101 . V_112 + 0x02 ) & 0x01 )
|| ( F_42 ( V_100 . V_101 . V_112 + 0x0A ) & 0x01 ) )
V_109 = 1 ;
}
return V_109 ;
}
static inline void F_43 ( struct V_15 * V_16 )
{
F_44 () ;
if ( V_16 -> V_61 == V_93 ) {
F_45 ( V_16 ) ;
} else if ( V_16 -> V_61 == V_62 ) {
F_4 () ;
} else {
F_46 ( V_16 -> V_53 ) ;
F_47 ( V_50 . V_113 . V_53 ) ;
}
F_48 () ;
}
static int F_49 ( struct V_114 * V_115 ,
struct V_116 * V_117 , int V_91 )
{
T_6 V_118 , V_119 ;
T_7 V_120 ;
struct V_13 * V_14 ;
struct V_121 * V_122 = & V_115 -> V_123 [ V_91 ] ;
struct V_15 * V_16 = F_50 ( V_122 ) ;
V_14 = F_51 ( V_124 ) ;
V_115 -> V_125 = 0 ;
if ( F_52 ( ! V_14 ) )
return - V_47 ;
F_9 () ;
F_17 ( V_14 , V_16 , 1 ) ;
V_118 = F_53 () ;
F_43 ( V_16 ) ;
V_119 = F_53 () ;
V_120 = F_54 ( F_55 ( V_119 , V_118 ) ) ;
V_115 -> V_125 = ( int ) V_120 ;
F_56 () ;
V_16 -> V_126 ++ ;
F_17 ( V_14 , V_16 , 0 ) ;
return V_91 ;
}
static int F_57 ( struct V_114 * V_115 , int V_91 )
{
struct V_121 * V_122 = & V_115 -> V_123 [ V_91 ] ;
struct V_15 * V_16 = F_50 ( V_122 ) ;
F_58 () ;
while ( 1 ) {
if ( V_16 -> V_61 == V_62 )
F_8 () ;
else if ( V_16 -> V_61 == V_92 ) {
F_46 ( V_16 -> V_53 ) ;
F_47 ( V_50 . V_113 . V_53 ) ;
} else
return - V_49 ;
}
return 0 ;
}
static int F_59 ( struct V_114 * V_115 ,
struct V_116 * V_117 , int V_91 )
{
struct V_13 * V_14 ;
struct V_121 * V_122 = & V_115 -> V_123 [ V_91 ] ;
struct V_15 * V_16 = F_50 ( V_122 ) ;
T_6 V_118 , V_119 ;
T_7 V_127 ;
T_7 V_120 ;
V_14 = F_51 ( V_124 ) ;
V_115 -> V_125 = 0 ;
if ( F_52 ( ! V_14 ) )
return - V_47 ;
F_9 () ;
if ( V_16 -> V_61 != V_93 ) {
F_5 () -> V_10 &= ~ V_11 ;
F_6 () ;
if ( F_52 ( F_7 () ) ) {
F_5 () -> V_10 |= V_11 ;
F_56 () ;
return - V_47 ;
}
}
F_17 ( V_14 , V_16 , 1 ) ;
if ( V_16 -> type == V_21 )
F_58 () ;
V_118 = F_53 () ;
F_60 () ;
F_43 ( V_16 ) ;
V_119 = F_53 () ;
V_127 = F_61 ( F_55 ( V_119 , V_118 ) ) ;
V_120 = V_127 ;
F_62 ( V_120 , V_128 ) ;
V_115 -> V_125 = ( int ) V_120 ;
F_63 ( V_127 ) ;
F_56 () ;
if ( V_16 -> V_61 != V_93 )
F_5 () -> V_10 |= V_11 ;
V_16 -> V_126 ++ ;
F_17 ( V_14 , V_16 , 0 ) ;
V_16 -> time += V_120 ;
return V_91 ;
}
static int F_64 ( struct V_114 * V_115 ,
struct V_116 * V_117 , int V_91 )
{
struct V_13 * V_14 ;
struct V_121 * V_122 = & V_115 -> V_123 [ V_91 ] ;
struct V_15 * V_16 = F_50 ( V_122 ) ;
T_6 V_118 , V_119 ;
T_7 V_127 ;
T_7 V_120 ;
V_14 = F_51 ( V_124 ) ;
V_115 -> V_125 = 0 ;
if ( F_52 ( ! V_14 ) )
return - V_47 ;
if ( ! V_16 -> V_129 && F_41 () ) {
if ( V_117 -> V_130 >= 0 ) {
return V_117 -> V_33 [ V_117 -> V_130 ] . F_65 ( V_115 ,
V_117 , V_117 -> V_130 ) ;
} else {
F_9 () ;
F_4 () ;
F_56 () ;
return - V_47 ;
}
}
F_9 () ;
if ( V_16 -> V_61 != V_93 ) {
F_5 () -> V_10 &= ~ V_11 ;
F_6 () ;
if ( F_52 ( F_7 () ) ) {
F_5 () -> V_10 |= V_11 ;
F_56 () ;
return - V_47 ;
}
}
F_66 ( F_67 () ) ;
F_60 () ;
F_17 ( V_14 , V_16 , 1 ) ;
V_118 = F_53 () ;
if ( V_14 -> V_51 . V_103 && V_14 -> V_51 . V_104 ) {
F_68 ( & V_131 ) ;
V_132 ++ ;
if ( V_132 == F_29 () )
F_21 ( V_133 , 1 ) ;
F_69 ( & V_131 ) ;
} else if ( ! V_14 -> V_51 . V_103 ) {
F_58 () ;
}
F_43 ( V_16 ) ;
if ( V_14 -> V_51 . V_103 && V_14 -> V_51 . V_104 ) {
F_68 ( & V_131 ) ;
F_21 ( V_133 , 0 ) ;
V_132 -- ;
F_69 ( & V_131 ) ;
}
V_119 = F_53 () ;
V_127 = F_61 ( F_55 ( V_119 , V_118 ) ) ;
V_120 = V_127 ;
F_62 ( V_120 , V_128 ) ;
V_115 -> V_125 = ( int ) V_120 ;
F_63 ( V_127 ) ;
F_56 () ;
if ( V_16 -> V_61 != V_93 )
F_5 () -> V_10 |= V_11 ;
V_16 -> V_126 ++ ;
F_17 ( V_14 , V_16 , 0 ) ;
V_16 -> time += V_120 ;
return V_91 ;
}
static int F_70 ( struct V_13 * V_14 )
{
int V_66 , V_64 = V_134 ;
struct V_15 * V_16 ;
struct V_121 * V_122 ;
struct V_114 * V_115 = & V_14 -> V_19 . V_115 ;
if ( ! V_14 -> V_51 . V_135 )
return - V_47 ;
if ( V_14 -> V_51 . V_19 == 0 ) {
return - V_47 ;
}
V_115 -> V_136 = V_14 -> V_6 ;
if ( V_7 == 0 )
V_7 = 1 ;
for ( V_66 = 1 ; V_66 < V_8 && V_66 <= V_7 ; V_66 ++ ) {
V_16 = & V_14 -> V_19 . V_33 [ V_66 ] ;
V_122 = & V_115 -> V_123 [ V_64 ] ;
if ( ! V_16 -> V_60 )
continue;
#ifdef F_28
if ( ( V_16 -> type != V_25 ) && ( F_29 () > 1 ) &&
! V_14 -> V_51 . V_81 &&
! ( V_50 . V_51 & V_52 ) )
continue;
#endif
F_71 ( V_122 , V_16 ) ;
V_64 ++ ;
if ( V_64 == V_137 )
break;
}
V_115 -> V_138 = V_64 ;
if ( ! V_64 )
return - V_47 ;
return 0 ;
}
static int F_72 ( struct V_13 * V_14 )
{
int V_66 , V_64 = V_134 ;
struct V_15 * V_16 ;
struct V_139 * V_12 ;
struct V_116 * V_117 = & V_140 ;
if ( ! V_14 -> V_51 . V_135 )
return - V_47 ;
if ( V_14 -> V_51 . V_19 == 0 )
return - V_47 ;
V_117 -> V_130 = - 1 ;
for ( V_66 = 0 ; V_66 < V_137 ; V_66 ++ ) {
V_117 -> V_33 [ V_66 ] . V_141 [ 0 ] = '\0' ;
V_117 -> V_33 [ V_66 ] . V_94 [ 0 ] = '\0' ;
}
if ( V_7 == 0 )
V_7 = 1 ;
for ( V_66 = 1 ; V_66 < V_8 && V_66 <= V_7 ; V_66 ++ ) {
V_16 = & V_14 -> V_19 . V_33 [ V_66 ] ;
if ( ! V_16 -> V_60 )
continue;
#ifdef F_28
if ( ( V_16 -> type != V_25 ) && ( F_29 () > 1 ) &&
! V_14 -> V_51 . V_81 &&
! ( V_50 . V_51 & V_52 ) )
continue;
#endif
V_12 = & V_117 -> V_33 [ V_64 ] ;
snprintf ( V_12 -> V_141 , V_142 , L_21 , V_66 ) ;
strncpy ( V_12 -> V_94 , V_16 -> V_94 , V_143 ) ;
V_12 -> V_144 = V_16 -> V_54 ;
V_12 -> V_145 = V_16 -> V_54 * V_146 ;
V_12 -> V_51 = 0 ;
switch ( V_16 -> type ) {
case V_25 :
if ( V_16 -> V_61 == V_93 )
V_12 -> V_51 |= V_147 ;
V_12 -> F_65 = F_49 ;
V_12 -> V_148 = F_57 ;
V_117 -> V_130 = V_64 ;
break;
case V_22 :
V_12 -> V_51 |= V_147 ;
V_12 -> F_65 = F_59 ;
V_12 -> V_148 = F_57 ;
V_117 -> V_130 = V_64 ;
break;
case V_21 :
V_12 -> V_51 |= V_147 ;
V_12 -> F_65 = V_14 -> V_51 . V_103 ?
F_64 :
F_59 ;
break;
}
V_64 ++ ;
if ( V_64 == V_137 )
break;
}
V_117 -> V_138 = V_64 ;
if ( ! V_64 )
return - V_47 ;
return 0 ;
}
int F_73 ( struct V_13 * V_14 )
{
int V_149 = 0 ;
if ( F_1 () )
return 0 ;
if ( ! V_14 )
return - V_47 ;
if ( V_72 ) {
return - V_49 ;
}
if ( ! V_14 -> V_51 . V_135 )
return - V_49 ;
F_74 () ;
F_75 ( & V_14 -> V_19 . V_115 ) ;
F_40 ( V_14 ) ;
if ( V_14 -> V_51 . V_19 ) {
F_70 ( V_14 ) ;
V_149 = F_76 ( & V_14 -> V_19 . V_115 ) ;
}
F_77 () ;
return V_149 ;
}
int F_78 ( struct V_13 * V_14 )
{
int V_136 ;
struct V_13 * V_150 ;
if ( F_1 () )
return 0 ;
if ( ! V_14 )
return - V_47 ;
if ( V_72 )
return - V_49 ;
if ( ! V_14 -> V_51 . V_135 )
return - V_49 ;
if ( V_14 -> V_6 == 0 && F_79 () == & V_140 ) {
F_74 () ;
F_80 () ;
F_81 (cpu) {
V_150 = F_82 ( V_124 , V_136 ) ;
if ( ! V_150 || ! V_150 -> V_51 . V_135 )
continue;
F_75 ( & V_150 -> V_19 . V_115 ) ;
}
F_72 ( V_14 ) ;
F_81 (cpu) {
V_150 = F_82 ( V_124 , V_136 ) ;
if ( ! V_150 || ! V_150 -> V_51 . V_135 )
continue;
F_40 ( V_150 ) ;
if ( V_150 -> V_51 . V_19 ) {
F_70 ( V_150 ) ;
F_76 ( & V_150 -> V_19 . V_115 ) ;
}
}
F_83 () ;
F_77 () ;
}
return 0 ;
}
int T_8 F_84 ( struct V_13 * V_14 ,
struct V_40 * V_41 )
{
T_4 V_10 = 0 ;
int V_151 ;
static int V_152 ;
if ( F_1 () )
return 0 ;
if ( ! V_152 ) {
F_85 ( V_153 ) ;
V_7 = F_86 ( V_7 ) ;
if ( V_7 < V_154 )
F_3 ( V_155
L_22 ,
V_7 ) ;
V_152 ++ ;
}
if ( ! V_14 )
return - V_47 ;
if ( V_50 . V_156 && ! V_72 ) {
V_10 =
F_87 ( V_50 . V_157 , V_50 . V_156 , 8 ) ;
if ( F_34 ( V_10 ) ) {
F_88 ( ( V_158 , V_10 ,
L_23 ) ) ;
}
}
F_40 ( V_14 ) ;
V_14 -> V_51 . V_135 = 1 ;
if ( V_14 -> V_51 . V_19 ) {
if ( ! V_159 ) {
F_72 ( V_14 ) ;
V_151 = F_89 ( & V_140 ) ;
if ( V_151 )
return V_151 ;
F_3 ( V_160 L_24 ,
V_140 . V_141 ) ;
}
F_70 ( V_14 ) ;
V_151 = F_90 ( & V_14 -> V_19 . V_115 ) ;
if ( V_151 ) {
if ( V_159 == 0 )
F_91 ( & V_140 ) ;
return V_151 ;
}
V_159 ++ ;
}
return 0 ;
}
int F_92 ( struct V_13 * V_14 ,
struct V_40 * V_41 )
{
if ( F_1 () )
return 0 ;
if ( V_14 -> V_51 . V_19 ) {
F_93 ( & V_14 -> V_19 . V_115 ) ;
V_159 -- ;
if ( V_159 == 0 )
F_91 ( & V_140 ) ;
}
V_14 -> V_51 . V_135 = 0 ;
return 0 ;
}

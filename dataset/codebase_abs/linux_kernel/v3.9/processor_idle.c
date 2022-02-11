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
F_5 () -> V_9 &= ~ V_10 ;
F_6 () ;
if ( ! F_7 () ) {
F_8 () ;
F_9 () ;
}
F_5 () -> V_9 |= V_10 ;
}
static void F_10 ( int V_11 , struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = & V_13 -> V_18 ;
T_1 type = V_19 ? V_20 : V_21 ;
if ( F_11 ( & F_12 ( V_13 -> V_5 ) , V_22 ) )
return;
if ( V_23 )
type = V_24 ;
if ( V_17 -> V_25 < V_11 )
return;
if ( V_15 -> type >= type )
V_13 -> V_18 . V_25 = V_11 ;
}
static void F_13 ( void * V_26 )
{
struct V_12 * V_13 = (struct V_12 * ) V_26 ;
unsigned long V_27 ;
V_27 = V_13 -> V_18 . V_25 < V_28 ?
V_29 : V_30 ;
F_14 ( V_27 , & V_13 -> V_5 ) ;
}
static void F_15 ( struct V_12 * V_13 )
{
F_16 ( V_13 -> V_5 , F_13 ,
( void * ) V_13 , 1 ) ;
}
static void F_17 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
int V_31 )
{
int V_11 = V_15 - V_13 -> V_18 . V_32 ;
if ( V_11 >= V_13 -> V_18 . V_25 ) {
unsigned long V_27 ;
V_27 = V_31 ? V_33 :
V_34 ;
F_14 ( V_27 , & V_13 -> V_5 ) ;
}
}
static void F_10 ( int V_11 , struct V_12 * V_13 ,
struct V_14 * V_35 ) { }
static void F_15 ( struct V_12 * V_13 ) { }
static void F_17 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
int V_31 )
{
}
static void F_18 ( void )
{
F_19 ( V_36 , & V_37 ) ;
}
static void F_20 ( void )
{
T_2 V_38 ;
F_19 ( V_36 , & V_38 ) ;
if ( V_38 != V_37 )
F_21 ( V_36 , V_37 ) ;
}
int F_22 ( struct V_39 * V_40 )
{
F_18 () ;
return 0 ;
}
int F_23 ( struct V_39 * V_40 )
{
F_20 () ;
return 0 ;
}
static void F_24 ( int V_11 )
{
switch ( V_41 . V_42 ) {
case V_43 :
case V_44 :
if ( F_25 ( V_45 ) )
return;
default:
if ( V_11 > V_24 )
F_26 ( L_3 ) ;
}
}
static void F_24 ( int V_11 ) { return; }
static int F_27 ( struct V_12 * V_13 )
{
if ( ! V_13 )
return - V_46 ;
if ( ! V_13 -> V_47 )
return - V_48 ;
V_13 -> V_18 . V_32 [ V_21 ] . type = V_21 ;
V_13 -> V_18 . V_32 [ V_20 ] . type = V_20 ;
#ifndef F_28
if ( ( F_29 () > 1 ) &&
! ( V_49 . V_50 & V_51 ) )
return - V_48 ;
#endif
V_13 -> V_18 . V_32 [ V_21 ] . V_52 = V_13 -> V_47 + 4 ;
V_13 -> V_18 . V_32 [ V_20 ] . V_52 = V_13 -> V_47 + 5 ;
V_13 -> V_18 . V_32 [ V_21 ] . V_53 = V_49 . V_54 ;
V_13 -> V_18 . V_32 [ V_20 ] . V_53 = V_49 . V_55 ;
if ( V_49 . V_54 > V_56 ) {
F_30 ( ( V_57 ,
L_4 , V_49 . V_54 ) ) ;
V_13 -> V_18 . V_32 [ V_21 ] . V_52 = 0 ;
}
if ( V_49 . V_55 > V_58 ) {
F_30 ( ( V_57 ,
L_5 , V_49 . V_55 ) ) ;
V_13 -> V_18 . V_32 [ V_20 ] . V_52 = 0 ;
}
F_30 ( ( V_57 ,
L_6 ,
V_13 -> V_18 . V_32 [ V_21 ] . V_52 ,
V_13 -> V_18 . V_32 [ V_20 ] . V_52 ) ) ;
return 0 ;
}
static int F_31 ( struct V_12 * V_13 )
{
if ( ! V_13 -> V_18 . V_32 [ V_24 ] . V_59 ) {
V_13 -> V_18 . V_32 [ V_24 ] . type = V_24 ;
V_13 -> V_18 . V_32 [ V_24 ] . V_59 = 1 ;
V_13 -> V_18 . V_32 [ V_24 ] . V_60 = V_61 ;
}
V_13 -> V_18 . V_32 [ V_62 ] . V_59 = 1 ;
return 0 ;
}
static int F_32 ( struct V_12 * V_13 )
{
T_3 V_9 = 0 ;
T_4 V_63 ;
int V_64 ;
int V_65 ;
struct V_66 V_67 = { V_68 , NULL } ;
union V_69 * V_70 ;
if ( V_71 )
return - V_48 ;
V_64 = 0 ;
V_9 = F_33 ( V_13 -> V_72 , L_7 , NULL , & V_67 ) ;
if ( F_34 ( V_9 ) ) {
F_30 ( ( V_57 , L_8 ) ) ;
return - V_48 ;
}
V_70 = V_67 . V_73 ;
if ( ! V_70 || ( V_70 -> type != V_74 ) || V_70 -> V_75 . V_63 < 2 ) {
F_3 (KERN_ERR PREFIX L_9 ) ;
V_9 = - V_76 ;
goto V_77;
}
V_63 = V_70 -> V_75 . V_78 [ 0 ] . integer . V_79 ;
if ( V_63 < 1 || V_63 != V_70 -> V_75 . V_63 - 1 ) {
F_3 (KERN_ERR PREFIX L_10 ) ;
V_9 = - V_76 ;
goto V_77;
}
V_13 -> V_50 . V_80 = 1 ;
for ( V_65 = 1 ; V_65 <= V_63 ; V_65 ++ ) {
union V_69 * V_81 ;
union V_69 * V_82 ;
struct V_83 * V_84 ;
struct V_14 V_15 ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
V_81 = & ( V_70 -> V_75 . V_78 [ V_65 ] ) ;
if ( V_81 -> type != V_74 )
continue;
if ( V_81 -> V_75 . V_63 != 4 )
continue;
V_82 = & ( V_81 -> V_75 . V_78 [ 0 ] ) ;
if ( V_82 -> type != V_85 )
continue;
V_84 = (struct V_83 * ) V_82 -> V_67 . V_73 ;
if ( V_84 -> V_86 != V_87 &&
( V_84 -> V_86 != V_88 ) )
continue;
V_82 = & ( V_81 -> V_75 . V_78 [ 1 ] ) ;
if ( V_82 -> type != V_89 )
continue;
V_15 . type = V_82 -> integer . V_79 ;
if ( V_65 == 1 && V_15 . type != V_24 )
V_64 ++ ;
V_15 . V_52 = V_84 -> V_52 ;
V_15 . V_90 = V_64 + 1 ;
V_15 . V_60 = V_91 ;
if ( V_84 -> V_86 == V_88 ) {
if ( F_35
( V_13 -> V_5 , & V_15 , V_84 ) == 0 ) {
V_15 . V_60 = V_92 ;
} else if ( V_15 . type == V_24 ) {
V_15 . V_60 = V_61 ;
snprintf ( V_15 . V_93 , V_94 , L_11 ) ;
} else {
continue;
}
if ( V_15 . type == V_24 &&
( V_1 == V_95 ) ) {
V_15 . V_60 = V_61 ;
snprintf ( V_15 . V_93 , V_94 , L_11 ) ;
}
} else {
snprintf ( V_15 . V_93 , V_94 , L_12 ,
V_15 . V_52 ) ;
}
if ( V_15 . type == V_24 ) {
V_15 . V_59 = 1 ;
}
V_82 = & ( V_81 -> V_75 . V_78 [ 2 ] ) ;
if ( V_82 -> type != V_89 )
continue;
V_15 . V_53 = V_82 -> integer . V_79 ;
V_82 = & ( V_81 -> V_75 . V_78 [ 3 ] ) ;
if ( V_82 -> type != V_89 )
continue;
V_64 ++ ;
memcpy ( & ( V_13 -> V_18 . V_32 [ V_64 ] ) , & V_15 , sizeof( V_15 ) ) ;
if ( V_64 >= ( V_7 - 1 ) ) {
F_3 ( V_96
L_13 ,
V_7 ) ;
F_3 ( V_96
L_14 ) ;
break;
}
}
F_30 ( ( V_57 , L_15 ,
V_64 ) ) ;
if ( V_64 < 2 )
V_9 = - V_76 ;
V_77:
F_36 ( V_67 . V_73 ) ;
return V_9 ;
}
static void F_37 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
static int V_97 = - 1 ;
static int V_98 = - 1 ;
if ( ! V_15 -> V_52 )
return;
else if ( V_99 . V_100 . V_101 ) {
F_30 ( ( V_57 ,
L_16 ) ) ;
return;
}
if ( V_97 == - 1 ) {
F_38 ( & ( V_13 -> V_50 ) , V_13 -> V_5 ) ;
V_97 = V_13 -> V_50 . V_102 ;
V_98 = V_13 -> V_50 . V_103 ;
} else {
V_13 -> V_50 . V_102 = V_97 ;
V_13 -> V_50 . V_103 = V_98 ;
}
if ( V_13 -> V_50 . V_102 ) {
if ( ! V_13 -> V_50 . V_103 ) {
if ( V_13 -> V_50 . V_80 != 1 ) {
F_30 ( ( V_57 ,
L_17 ) ) ;
return;
} else {
F_30 ( ( V_57 ,
L_18 ) ) ;
}
}
} else {
if ( ! ( V_49 . V_50 & V_104 ) ) {
F_30 ( ( V_57 ,
L_19
L_20 ) ) ;
return;
}
}
V_15 -> V_59 = 1 ;
F_21 ( V_36 , 1 ) ;
return;
}
static int F_39 ( struct V_12 * V_13 )
{
unsigned int V_65 ;
unsigned int V_105 = 0 ;
V_13 -> V_18 . V_25 = V_28 ;
for ( V_65 = 1 ; V_65 < V_7 && V_65 <= V_6 ; V_65 ++ ) {
struct V_14 * V_15 = & V_13 -> V_18 . V_32 [ V_65 ] ;
switch ( V_15 -> type ) {
case V_24 :
V_15 -> V_59 = 1 ;
break;
case V_21 :
if ( ! V_15 -> V_52 )
break;
V_15 -> V_59 = 1 ;
break;
case V_20 :
F_37 ( V_13 , V_15 ) ;
break;
}
if ( ! V_15 -> V_59 )
continue;
F_10 ( V_65 , V_13 , V_15 ) ;
F_24 ( V_15 -> type ) ;
V_105 ++ ;
}
F_15 ( V_13 ) ;
return ( V_105 ) ;
}
static int F_40 ( struct V_12 * V_13 )
{
unsigned int V_65 ;
int V_106 ;
memset ( V_13 -> V_18 . V_32 , 0 , sizeof( V_13 -> V_18 . V_32 ) ) ;
V_106 = F_32 ( V_13 ) ;
if ( V_106 == - V_48 )
V_106 = F_27 ( V_13 ) ;
if ( V_106 )
return V_106 ;
F_31 ( V_13 ) ;
V_13 -> V_18 . V_63 = F_39 ( V_13 ) ;
for ( V_65 = 1 ; V_65 < V_7 ; V_65 ++ ) {
if ( V_13 -> V_18 . V_32 [ V_65 ] . V_59 ) {
V_13 -> V_18 . V_63 = V_65 ;
if ( V_13 -> V_18 . V_32 [ V_65 ] . type >= V_21 )
V_13 -> V_50 . V_18 = 1 ;
}
}
return 0 ;
}
static int F_41 ( void )
{
T_2 V_107 = 0 ;
if ( V_108 )
return 0 ;
F_19 ( V_109 , & V_107 ) ;
if ( V_107 )
F_21 ( V_109 , 1 ) ;
else if ( V_99 . V_100 . V_110 ) {
if ( ( F_42 ( V_99 . V_100 . V_110 + 0x02 ) & 0x01 )
|| ( F_42 ( V_99 . V_100 . V_110 + 0x0A ) & 0x01 ) )
V_107 = 1 ;
}
return V_107 ;
}
static inline void F_43 ( struct V_14 * V_15 )
{
F_44 () ;
if ( V_15 -> V_60 == V_92 ) {
F_45 ( V_15 ) ;
} else if ( V_15 -> V_60 == V_61 ) {
F_4 () ;
} else {
F_46 ( V_15 -> V_52 ) ;
F_47 ( V_49 . V_111 . V_52 ) ;
}
F_48 () ;
}
static int F_49 ( struct V_112 * V_40 ,
struct V_113 * V_114 , int V_90 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 = F_50 ( V_115 [ V_90 ] , V_40 -> V_116 ) ;
V_13 = F_51 ( V_117 ) ;
if ( F_52 ( ! V_13 ) )
return - V_46 ;
F_17 ( V_13 , V_15 , 1 ) ;
F_43 ( V_15 ) ;
F_17 ( V_13 , V_15 , 0 ) ;
return V_90 ;
}
static int F_53 ( struct V_112 * V_40 , int V_90 )
{
struct V_14 * V_15 = F_50 ( V_115 [ V_90 ] , V_40 -> V_116 ) ;
F_54 () ;
while ( 1 ) {
if ( V_15 -> V_60 == V_61 )
F_8 () ;
else if ( V_15 -> V_60 == V_91 ) {
F_46 ( V_15 -> V_52 ) ;
F_47 ( V_49 . V_111 . V_52 ) ;
} else
return - V_48 ;
}
return 0 ;
}
static int F_55 ( struct V_112 * V_40 ,
struct V_113 * V_114 , int V_90 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 = F_50 ( V_115 [ V_90 ] , V_40 -> V_116 ) ;
V_13 = F_51 ( V_117 ) ;
if ( F_52 ( ! V_13 ) )
return - V_46 ;
if ( V_15 -> V_60 != V_92 ) {
F_5 () -> V_9 &= ~ V_10 ;
F_6 () ;
if ( F_52 ( F_7 () ) ) {
F_5 () -> V_9 |= V_10 ;
return - V_46 ;
}
}
F_17 ( V_13 , V_15 , 1 ) ;
if ( V_15 -> type == V_20 )
F_54 () ;
F_56 () ;
F_43 ( V_15 ) ;
F_57 ( 0 ) ;
if ( V_15 -> V_60 != V_92 )
F_5 () -> V_9 |= V_10 ;
F_17 ( V_13 , V_15 , 0 ) ;
return V_90 ;
}
static int F_58 ( struct V_112 * V_40 ,
struct V_113 * V_114 , int V_90 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 = F_50 ( V_115 [ V_90 ] , V_40 -> V_116 ) ;
V_13 = F_51 ( V_117 ) ;
if ( F_52 ( ! V_13 ) )
return - V_46 ;
if ( ! V_15 -> V_118 && F_41 () ) {
if ( V_114 -> V_119 >= 0 ) {
return V_114 -> V_32 [ V_114 -> V_119 ] . F_59 ( V_40 ,
V_114 , V_114 -> V_119 ) ;
} else {
F_4 () ;
return - V_120 ;
}
}
if ( V_15 -> V_60 != V_92 ) {
F_5 () -> V_9 &= ~ V_10 ;
F_6 () ;
if ( F_52 ( F_7 () ) ) {
F_5 () -> V_9 |= V_10 ;
return - V_46 ;
}
}
F_60 ( F_61 () ) ;
F_56 () ;
F_17 ( V_13 , V_15 , 1 ) ;
if ( V_13 -> V_50 . V_102 && V_13 -> V_50 . V_103 ) {
F_62 ( & V_121 ) ;
V_122 ++ ;
if ( V_122 == F_29 () )
F_21 ( V_123 , 1 ) ;
F_63 ( & V_121 ) ;
} else if ( ! V_13 -> V_50 . V_102 ) {
F_54 () ;
}
F_43 ( V_15 ) ;
if ( V_13 -> V_50 . V_102 && V_13 -> V_50 . V_103 ) {
F_62 ( & V_121 ) ;
F_21 ( V_123 , 0 ) ;
V_122 -- ;
F_63 ( & V_121 ) ;
}
F_57 ( 0 ) ;
if ( V_15 -> V_60 != V_92 )
F_5 () -> V_9 |= V_10 ;
F_17 ( V_13 , V_15 , 0 ) ;
return V_90 ;
}
static int F_64 ( struct V_12 * V_13 ,
struct V_112 * V_40 )
{
int V_65 , V_63 = V_124 ;
struct V_14 * V_15 ;
if ( ! V_13 -> V_50 . V_125 )
return - V_46 ;
if ( V_13 -> V_50 . V_18 == 0 ) {
return - V_46 ;
}
if ( ! V_40 )
return - V_46 ;
V_40 -> V_116 = V_13 -> V_5 ;
if ( V_6 == 0 )
V_6 = 1 ;
for ( V_65 = 1 ; V_65 < V_7 && V_65 <= V_6 ; V_65 ++ ) {
V_15 = & V_13 -> V_18 . V_32 [ V_65 ] ;
if ( ! V_15 -> V_59 )
continue;
#ifdef F_28
if ( ( V_15 -> type != V_24 ) && ( F_29 () > 1 ) &&
! V_13 -> V_50 . V_80 &&
! ( V_49 . V_50 & V_51 ) )
continue;
#endif
F_50 ( V_115 [ V_63 ] , V_40 -> V_116 ) = V_15 ;
V_63 ++ ;
if ( V_63 == V_126 )
break;
}
V_40 -> V_127 = V_63 ;
if ( ! V_63 )
return - V_46 ;
return 0 ;
}
static int F_65 ( struct V_12 * V_13 )
{
int V_65 , V_63 = V_124 ;
struct V_14 * V_15 ;
struct V_128 * V_11 ;
struct V_113 * V_114 = & V_129 ;
if ( ! V_13 -> V_50 . V_125 )
return - V_46 ;
if ( V_13 -> V_50 . V_18 == 0 )
return - V_46 ;
V_114 -> V_119 = - 1 ;
for ( V_65 = 0 ; V_65 < V_126 ; V_65 ++ ) {
V_114 -> V_32 [ V_65 ] . V_130 [ 0 ] = '\0' ;
V_114 -> V_32 [ V_65 ] . V_93 [ 0 ] = '\0' ;
}
if ( V_6 == 0 )
V_6 = 1 ;
for ( V_65 = 1 ; V_65 < V_7 && V_65 <= V_6 ; V_65 ++ ) {
V_15 = & V_13 -> V_18 . V_32 [ V_65 ] ;
if ( ! V_15 -> V_59 )
continue;
#ifdef F_28
if ( ( V_15 -> type != V_24 ) && ( F_29 () > 1 ) &&
! V_13 -> V_50 . V_80 &&
! ( V_49 . V_50 & V_51 ) )
continue;
#endif
V_11 = & V_114 -> V_32 [ V_63 ] ;
snprintf ( V_11 -> V_130 , V_131 , L_21 , V_65 ) ;
strncpy ( V_11 -> V_93 , V_15 -> V_93 , V_132 ) ;
V_11 -> V_133 = V_15 -> V_53 ;
V_11 -> V_134 = V_15 -> V_53 * V_135 ;
V_11 -> V_50 = 0 ;
switch ( V_15 -> type ) {
case V_24 :
if ( V_15 -> V_60 == V_92 )
V_11 -> V_50 |= V_136 ;
V_11 -> F_59 = F_49 ;
V_11 -> V_137 = F_53 ;
V_114 -> V_119 = V_63 ;
break;
case V_21 :
V_11 -> V_50 |= V_136 ;
V_11 -> F_59 = F_55 ;
V_11 -> V_137 = F_53 ;
V_114 -> V_119 = V_63 ;
break;
case V_20 :
V_11 -> V_50 |= V_136 ;
V_11 -> F_59 = V_13 -> V_50 . V_102 ?
F_58 :
F_55 ;
break;
}
V_63 ++ ;
if ( V_63 == V_126 )
break;
}
V_114 -> V_127 = V_63 ;
if ( ! V_63 )
return - V_46 ;
return 0 ;
}
int F_66 ( struct V_12 * V_13 )
{
int V_138 = 0 ;
struct V_112 * V_40 ;
if ( F_1 () )
return 0 ;
if ( ! V_13 )
return - V_46 ;
if ( V_71 ) {
return - V_48 ;
}
if ( ! V_13 -> V_50 . V_125 )
return - V_48 ;
V_40 = F_50 ( V_139 , V_13 -> V_5 ) ;
F_67 () ;
F_68 ( V_40 ) ;
F_40 ( V_13 ) ;
if ( V_13 -> V_50 . V_18 ) {
F_64 ( V_13 , V_40 ) ;
V_138 = F_69 ( V_40 ) ;
}
F_70 () ;
return V_138 ;
}
int F_71 ( struct V_12 * V_13 )
{
int V_116 ;
struct V_12 * V_140 ;
struct V_112 * V_40 ;
if ( F_1 () )
return 0 ;
if ( ! V_13 )
return - V_46 ;
if ( V_71 )
return - V_48 ;
if ( ! V_13 -> V_50 . V_125 )
return - V_48 ;
if ( V_13 -> V_5 == 0 && F_72 () == & V_129 ) {
F_67 () ;
F_73 () ;
F_74 (cpu) {
V_140 = F_50 ( V_117 , V_116 ) ;
if ( ! V_140 || ! V_140 -> V_50 . V_125 )
continue;
V_40 = F_50 ( V_139 , V_116 ) ;
F_68 ( V_40 ) ;
}
F_40 ( V_13 ) ;
F_65 ( V_13 ) ;
F_74 (cpu) {
V_140 = F_50 ( V_117 , V_116 ) ;
if ( ! V_140 || ! V_140 -> V_50 . V_125 )
continue;
F_40 ( V_140 ) ;
if ( V_140 -> V_50 . V_18 ) {
V_40 = F_50 ( V_139 , V_116 ) ;
F_64 ( V_140 , V_40 ) ;
F_69 ( V_40 ) ;
}
}
F_75 () ;
F_70 () ;
}
return 0 ;
}
int T_5 F_76 ( struct V_12 * V_13 )
{
T_3 V_9 = 0 ;
int V_141 ;
struct V_112 * V_40 ;
static int V_142 ;
if ( F_1 () )
return 0 ;
if ( ! V_142 ) {
F_77 ( V_143 ) ;
V_6 = F_78 ( V_6 ) ;
if ( V_6 < V_144 )
F_3 ( V_145
L_22 ,
V_6 ) ;
V_142 ++ ;
}
if ( ! V_13 )
return - V_46 ;
if ( V_49 . V_146 && ! V_71 ) {
V_9 =
F_79 ( V_49 . V_147 , V_49 . V_146 , 8 ) ;
if ( F_34 ( V_9 ) ) {
F_80 ( ( V_148 , V_9 ,
L_23 ) ) ;
}
}
F_40 ( V_13 ) ;
V_13 -> V_50 . V_125 = 1 ;
if ( V_13 -> V_50 . V_18 ) {
if ( ! V_149 ) {
F_65 ( V_13 ) ;
V_141 = F_81 ( & V_129 ) ;
if ( V_141 )
return V_141 ;
F_3 ( V_150 L_24 ,
V_129 . V_130 ) ;
}
V_40 = F_82 ( sizeof( * V_40 ) , V_151 ) ;
if ( ! V_40 )
return - V_152 ;
F_50 ( V_139 , V_13 -> V_5 ) = V_40 ;
F_64 ( V_13 , V_40 ) ;
V_141 = F_83 ( V_40 ) ;
if ( V_141 ) {
if ( V_149 == 0 )
F_84 ( & V_129 ) ;
return V_141 ;
}
V_149 ++ ;
}
return 0 ;
}
int F_85 ( struct V_12 * V_13 )
{
struct V_112 * V_40 = F_50 ( V_139 , V_13 -> V_5 ) ;
if ( F_1 () )
return 0 ;
if ( V_13 -> V_50 . V_18 ) {
F_86 ( V_40 ) ;
V_149 -- ;
if ( V_149 == 0 )
F_84 ( & V_129 ) ;
}
V_13 -> V_50 . V_125 = 0 ;
return 0 ;
}

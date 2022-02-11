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
int F_18 ( void )
{
F_19 ( V_36 , & V_37 ) ;
return 0 ;
}
void F_20 ( void )
{
T_2 V_38 ;
F_19 ( V_36 , & V_38 ) ;
if ( V_38 == V_37 )
return;
F_21 ( V_36 , V_37 ) ;
}
void F_22 ( void )
{
F_23 ( & V_39 ) ;
}
void F_24 ( void )
{
F_25 ( & V_39 ) ;
}
static void F_26 ( int V_11 )
{
switch ( V_40 . V_41 ) {
case V_42 :
case V_43 :
if ( F_27 ( V_44 ) )
return;
default:
if ( V_11 > V_24 )
F_28 ( L_3 ) ;
}
}
static void F_26 ( int V_11 ) { return; }
static int F_29 ( struct V_12 * V_13 )
{
if ( ! V_13 )
return - V_45 ;
if ( ! V_13 -> V_46 )
return - V_47 ;
V_13 -> V_18 . V_32 [ V_21 ] . type = V_21 ;
V_13 -> V_18 . V_32 [ V_20 ] . type = V_20 ;
#ifndef F_30
if ( ( F_31 () > 1 ) &&
! ( V_48 . V_49 & V_50 ) )
return - V_47 ;
#endif
V_13 -> V_18 . V_32 [ V_21 ] . V_51 = V_13 -> V_46 + 4 ;
V_13 -> V_18 . V_32 [ V_20 ] . V_51 = V_13 -> V_46 + 5 ;
V_13 -> V_18 . V_32 [ V_21 ] . V_52 = V_48 . V_53 ;
V_13 -> V_18 . V_32 [ V_20 ] . V_52 = V_48 . V_54 ;
if ( V_48 . V_53 > V_55 ) {
F_32 ( ( V_56 ,
L_4 , V_48 . V_53 ) ) ;
V_13 -> V_18 . V_32 [ V_21 ] . V_51 = 0 ;
}
if ( V_48 . V_54 > V_57 ) {
F_32 ( ( V_56 ,
L_5 , V_48 . V_54 ) ) ;
V_13 -> V_18 . V_32 [ V_20 ] . V_51 = 0 ;
}
F_32 ( ( V_56 ,
L_6 ,
V_13 -> V_18 . V_32 [ V_21 ] . V_51 ,
V_13 -> V_18 . V_32 [ V_20 ] . V_51 ) ) ;
return 0 ;
}
static int F_33 ( struct V_12 * V_13 )
{
if ( ! V_13 -> V_18 . V_32 [ V_24 ] . V_58 ) {
V_13 -> V_18 . V_32 [ V_24 ] . type = V_24 ;
V_13 -> V_18 . V_32 [ V_24 ] . V_58 = 1 ;
V_13 -> V_18 . V_32 [ V_24 ] . V_59 = V_60 ;
}
V_13 -> V_18 . V_32 [ V_61 ] . V_58 = 1 ;
return 0 ;
}
static int F_34 ( struct V_12 * V_13 )
{
T_3 V_9 = 0 ;
T_4 V_62 ;
int V_63 ;
int V_64 ;
struct V_65 V_66 = { V_67 , NULL } ;
union V_68 * V_69 ;
if ( V_70 )
return - V_47 ;
V_63 = 0 ;
V_9 = F_35 ( V_13 -> V_71 , L_7 , NULL , & V_66 ) ;
if ( F_36 ( V_9 ) ) {
F_32 ( ( V_56 , L_8 ) ) ;
return - V_47 ;
}
V_69 = V_66 . V_72 ;
if ( ! V_69 || ( V_69 -> type != V_73 ) || V_69 -> V_74 . V_62 < 2 ) {
F_3 (KERN_ERR PREFIX L_9 ) ;
V_9 = - V_75 ;
goto V_76;
}
V_62 = V_69 -> V_74 . V_77 [ 0 ] . integer . V_78 ;
if ( V_62 < 1 || V_62 != V_69 -> V_74 . V_62 - 1 ) {
F_3 (KERN_ERR PREFIX L_10 ) ;
V_9 = - V_75 ;
goto V_76;
}
V_13 -> V_49 . V_79 = 1 ;
for ( V_64 = 1 ; V_64 <= V_62 ; V_64 ++ ) {
union V_68 * V_80 ;
union V_68 * V_81 ;
struct V_82 * V_83 ;
struct V_14 V_15 ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
V_80 = & ( V_69 -> V_74 . V_77 [ V_64 ] ) ;
if ( V_80 -> type != V_73 )
continue;
if ( V_80 -> V_74 . V_62 != 4 )
continue;
V_81 = & ( V_80 -> V_74 . V_77 [ 0 ] ) ;
if ( V_81 -> type != V_84 )
continue;
V_83 = (struct V_82 * ) V_81 -> V_66 . V_72 ;
if ( V_83 -> V_85 != V_86 &&
( V_83 -> V_85 != V_87 ) )
continue;
V_81 = & ( V_80 -> V_74 . V_77 [ 1 ] ) ;
if ( V_81 -> type != V_88 )
continue;
V_15 . type = V_81 -> integer . V_78 ;
if ( V_64 == 1 && V_15 . type != V_24 )
V_63 ++ ;
V_15 . V_51 = V_83 -> V_51 ;
V_15 . V_89 = V_63 + 1 ;
V_15 . V_59 = V_90 ;
if ( V_83 -> V_85 == V_87 ) {
if ( F_37
( V_13 -> V_5 , & V_15 , V_83 ) == 0 ) {
V_15 . V_59 = V_91 ;
} else if ( V_15 . type == V_24 ) {
V_15 . V_59 = V_60 ;
snprintf ( V_15 . V_92 , V_93 , L_11 ) ;
} else {
continue;
}
if ( V_15 . type == V_24 &&
( V_1 == V_94 ) ) {
V_15 . V_59 = V_60 ;
snprintf ( V_15 . V_92 , V_93 , L_11 ) ;
}
} else {
snprintf ( V_15 . V_92 , V_93 , L_12 ,
V_15 . V_51 ) ;
}
if ( V_15 . type == V_24 ) {
V_15 . V_58 = 1 ;
}
V_81 = & ( V_80 -> V_74 . V_77 [ 2 ] ) ;
if ( V_81 -> type != V_88 )
continue;
V_15 . V_52 = V_81 -> integer . V_78 ;
V_81 = & ( V_80 -> V_74 . V_77 [ 3 ] ) ;
if ( V_81 -> type != V_88 )
continue;
V_63 ++ ;
memcpy ( & ( V_13 -> V_18 . V_32 [ V_63 ] ) , & V_15 , sizeof( V_15 ) ) ;
if ( V_63 >= ( V_7 - 1 ) ) {
F_3 ( V_95
L_13 ,
V_7 ) ;
F_3 ( V_95
L_14 ) ;
break;
}
}
F_32 ( ( V_56 , L_15 ,
V_63 ) ) ;
if ( V_63 < 2 )
V_9 = - V_75 ;
V_76:
F_38 ( V_66 . V_72 ) ;
return V_9 ;
}
static void F_39 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
static int V_96 = - 1 ;
static int V_97 = - 1 ;
if ( ! V_15 -> V_51 )
return;
else if ( V_98 . V_99 . V_100 ) {
F_32 ( ( V_56 ,
L_16 ) ) ;
return;
}
if ( V_96 == - 1 ) {
F_40 ( & ( V_13 -> V_49 ) , V_13 -> V_5 ) ;
V_96 = V_13 -> V_49 . V_101 ;
V_97 = V_13 -> V_49 . V_102 ;
} else {
V_13 -> V_49 . V_101 = V_96 ;
V_13 -> V_49 . V_102 = V_97 ;
}
if ( V_13 -> V_49 . V_101 ) {
if ( ! V_13 -> V_49 . V_102 ) {
if ( V_13 -> V_49 . V_79 != 1 ) {
F_32 ( ( V_56 ,
L_17 ) ) ;
return;
} else {
F_32 ( ( V_56 ,
L_18 ) ) ;
}
}
} else {
if ( ! ( V_48 . V_49 & V_103 ) ) {
F_32 ( ( V_56 ,
L_19
L_20 ) ) ;
return;
}
}
V_15 -> V_58 = 1 ;
F_21 ( V_36 , 1 ) ;
return;
}
static int F_41 ( struct V_12 * V_13 )
{
unsigned int V_64 ;
unsigned int V_104 = 0 ;
V_13 -> V_18 . V_25 = V_28 ;
for ( V_64 = 1 ; V_64 < V_7 && V_64 <= V_6 ; V_64 ++ ) {
struct V_14 * V_15 = & V_13 -> V_18 . V_32 [ V_64 ] ;
switch ( V_15 -> type ) {
case V_24 :
V_15 -> V_58 = 1 ;
break;
case V_21 :
if ( ! V_15 -> V_51 )
break;
V_15 -> V_58 = 1 ;
break;
case V_20 :
F_39 ( V_13 , V_15 ) ;
break;
}
if ( ! V_15 -> V_58 )
continue;
F_10 ( V_64 , V_13 , V_15 ) ;
F_26 ( V_15 -> type ) ;
V_104 ++ ;
}
F_15 ( V_13 ) ;
return ( V_104 ) ;
}
static int F_42 ( struct V_12 * V_13 )
{
unsigned int V_64 ;
int V_105 ;
memset ( V_13 -> V_18 . V_32 , 0 , sizeof( V_13 -> V_18 . V_32 ) ) ;
V_105 = F_34 ( V_13 ) ;
if ( V_105 == - V_47 )
V_105 = F_29 ( V_13 ) ;
if ( V_105 )
return V_105 ;
F_33 ( V_13 ) ;
V_13 -> V_18 . V_62 = F_41 ( V_13 ) ;
for ( V_64 = 1 ; V_64 < V_7 ; V_64 ++ ) {
if ( V_13 -> V_18 . V_32 [ V_64 ] . V_58 ) {
V_13 -> V_18 . V_62 = V_64 ;
if ( V_13 -> V_18 . V_32 [ V_64 ] . type >= V_21 )
V_13 -> V_49 . V_18 = 1 ;
}
}
return 0 ;
}
static int F_43 ( void )
{
T_2 V_106 = 0 ;
if ( V_107 )
return 0 ;
F_19 ( V_108 , & V_106 ) ;
if ( V_106 )
F_21 ( V_108 , 1 ) ;
else if ( V_98 . V_99 . V_109 ) {
if ( ( F_44 ( V_98 . V_99 . V_109 + 0x02 ) & 0x01 )
|| ( F_44 ( V_98 . V_99 . V_109 + 0x0A ) & 0x01 ) )
V_106 = 1 ;
}
return V_106 ;
}
static inline void F_45 ( struct V_14 * V_15 )
{
F_46 () ;
if ( V_15 -> V_59 == V_91 ) {
F_47 ( V_15 ) ;
} else if ( V_15 -> V_59 == V_60 ) {
F_4 () ;
} else {
F_48 ( V_15 -> V_51 ) ;
F_49 ( V_48 . V_110 . V_51 ) ;
}
F_50 () ;
}
static int F_51 ( struct V_111 * V_112 ,
struct V_113 * V_114 , int V_89 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 = F_52 ( V_115 [ V_89 ] , V_112 -> V_116 ) ;
V_13 = F_53 ( V_117 ) ;
if ( F_54 ( ! V_13 ) )
return - V_45 ;
F_17 ( V_13 , V_15 , 1 ) ;
F_45 ( V_15 ) ;
F_17 ( V_13 , V_15 , 0 ) ;
return V_89 ;
}
static int F_55 ( struct V_111 * V_112 , int V_89 )
{
struct V_14 * V_15 = F_52 ( V_115 [ V_89 ] , V_112 -> V_116 ) ;
F_56 () ;
while ( 1 ) {
if ( V_15 -> V_59 == V_60 )
F_8 () ;
else if ( V_15 -> V_59 == V_90 ) {
F_48 ( V_15 -> V_51 ) ;
F_49 ( V_48 . V_110 . V_51 ) ;
} else
return - V_47 ;
}
return 0 ;
}
static int F_57 ( struct V_111 * V_112 ,
struct V_113 * V_114 , int V_89 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 = F_52 ( V_115 [ V_89 ] , V_112 -> V_116 ) ;
V_13 = F_53 ( V_117 ) ;
if ( F_54 ( ! V_13 ) )
return - V_45 ;
if ( V_15 -> V_59 != V_91 ) {
F_5 () -> V_9 &= ~ V_10 ;
F_6 () ;
if ( F_54 ( F_7 () ) ) {
F_5 () -> V_9 |= V_10 ;
return - V_45 ;
}
}
F_17 ( V_13 , V_15 , 1 ) ;
if ( V_15 -> type == V_20 )
F_56 () ;
F_58 () ;
F_45 ( V_15 ) ;
F_59 ( 0 ) ;
if ( V_15 -> V_59 != V_91 )
F_5 () -> V_9 |= V_10 ;
F_17 ( V_13 , V_15 , 0 ) ;
return V_89 ;
}
static int F_60 ( struct V_111 * V_112 ,
struct V_113 * V_114 , int V_89 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 = F_52 ( V_115 [ V_89 ] , V_112 -> V_116 ) ;
V_13 = F_53 ( V_117 ) ;
if ( F_54 ( ! V_13 ) )
return - V_45 ;
if ( ! V_15 -> V_118 && F_43 () ) {
if ( V_114 -> V_119 >= 0 ) {
return V_114 -> V_32 [ V_114 -> V_119 ] . F_61 ( V_112 ,
V_114 , V_114 -> V_119 ) ;
} else {
F_4 () ;
return - V_120 ;
}
}
if ( V_15 -> V_59 != V_91 ) {
F_5 () -> V_9 &= ~ V_10 ;
F_6 () ;
if ( F_54 ( F_7 () ) ) {
F_5 () -> V_9 |= V_10 ;
return - V_45 ;
}
}
F_62 ( F_63 () ) ;
F_58 () ;
F_17 ( V_13 , V_15 , 1 ) ;
if ( V_13 -> V_49 . V_101 && V_13 -> V_49 . V_102 ) {
F_64 ( & V_121 ) ;
V_122 ++ ;
if ( V_122 == F_31 () )
F_21 ( V_123 , 1 ) ;
F_65 ( & V_121 ) ;
} else if ( ! V_13 -> V_49 . V_101 ) {
F_56 () ;
}
F_45 ( V_15 ) ;
if ( V_13 -> V_49 . V_101 && V_13 -> V_49 . V_102 ) {
F_64 ( & V_121 ) ;
F_21 ( V_123 , 0 ) ;
V_122 -- ;
F_65 ( & V_121 ) ;
}
F_59 ( 0 ) ;
if ( V_15 -> V_59 != V_91 )
F_5 () -> V_9 |= V_10 ;
F_17 ( V_13 , V_15 , 0 ) ;
return V_89 ;
}
static int F_66 ( struct V_12 * V_13 ,
struct V_111 * V_112 )
{
int V_64 , V_62 = V_124 ;
struct V_14 * V_15 ;
if ( ! V_13 -> V_49 . V_125 )
return - V_45 ;
if ( V_13 -> V_49 . V_18 == 0 ) {
return - V_45 ;
}
if ( ! V_112 )
return - V_45 ;
V_112 -> V_116 = V_13 -> V_5 ;
if ( V_6 == 0 )
V_6 = 1 ;
for ( V_64 = 1 ; V_64 < V_7 && V_64 <= V_6 ; V_64 ++ ) {
V_15 = & V_13 -> V_18 . V_32 [ V_64 ] ;
if ( ! V_15 -> V_58 )
continue;
#ifdef F_30
if ( ( V_15 -> type != V_24 ) && ( F_31 () > 1 ) &&
! V_13 -> V_49 . V_79 &&
! ( V_48 . V_49 & V_50 ) )
continue;
#endif
F_52 ( V_115 [ V_62 ] , V_112 -> V_116 ) = V_15 ;
V_62 ++ ;
if ( V_62 == V_126 )
break;
}
V_112 -> V_127 = V_62 ;
if ( ! V_62 )
return - V_45 ;
return 0 ;
}
static int F_67 ( struct V_12 * V_13 )
{
int V_64 , V_62 = V_124 ;
struct V_14 * V_15 ;
struct V_128 * V_11 ;
struct V_113 * V_114 = & V_129 ;
if ( ! V_13 -> V_49 . V_125 )
return - V_45 ;
if ( V_13 -> V_49 . V_18 == 0 )
return - V_45 ;
V_114 -> V_119 = - 1 ;
for ( V_64 = 0 ; V_64 < V_126 ; V_64 ++ ) {
V_114 -> V_32 [ V_64 ] . V_130 [ 0 ] = '\0' ;
V_114 -> V_32 [ V_64 ] . V_92 [ 0 ] = '\0' ;
}
if ( V_6 == 0 )
V_6 = 1 ;
for ( V_64 = 1 ; V_64 < V_7 && V_64 <= V_6 ; V_64 ++ ) {
V_15 = & V_13 -> V_18 . V_32 [ V_64 ] ;
if ( ! V_15 -> V_58 )
continue;
#ifdef F_30
if ( ( V_15 -> type != V_24 ) && ( F_31 () > 1 ) &&
! V_13 -> V_49 . V_79 &&
! ( V_48 . V_49 & V_50 ) )
continue;
#endif
V_11 = & V_114 -> V_32 [ V_62 ] ;
snprintf ( V_11 -> V_130 , V_131 , L_21 , V_64 ) ;
strncpy ( V_11 -> V_92 , V_15 -> V_92 , V_132 ) ;
V_11 -> V_133 = V_15 -> V_52 ;
V_11 -> V_134 = V_15 -> V_52 * V_135 ;
V_11 -> V_49 = 0 ;
switch ( V_15 -> type ) {
case V_24 :
if ( V_15 -> V_59 == V_91 )
V_11 -> V_49 |= V_136 ;
V_11 -> F_61 = F_51 ;
V_11 -> V_137 = F_55 ;
V_114 -> V_119 = V_62 ;
break;
case V_21 :
V_11 -> V_49 |= V_136 ;
V_11 -> F_61 = F_57 ;
V_11 -> V_137 = F_55 ;
V_114 -> V_119 = V_62 ;
break;
case V_20 :
V_11 -> V_49 |= V_136 ;
V_11 -> F_61 = V_13 -> V_49 . V_101 ?
F_60 :
F_57 ;
break;
}
V_62 ++ ;
if ( V_62 == V_126 )
break;
}
V_114 -> V_127 = V_62 ;
if ( ! V_62 )
return - V_45 ;
return 0 ;
}
int F_68 ( struct V_12 * V_13 )
{
int V_138 = 0 ;
struct V_111 * V_112 ;
if ( F_1 () )
return 0 ;
if ( ! V_13 )
return - V_45 ;
if ( V_70 ) {
return - V_47 ;
}
if ( ! V_13 -> V_49 . V_125 )
return - V_47 ;
V_112 = F_52 ( V_139 , V_13 -> V_5 ) ;
F_69 () ;
F_70 ( V_112 ) ;
F_42 ( V_13 ) ;
if ( V_13 -> V_49 . V_18 ) {
F_66 ( V_13 , V_112 ) ;
V_138 = F_71 ( V_112 ) ;
}
F_72 () ;
return V_138 ;
}
int F_73 ( struct V_12 * V_13 )
{
int V_116 ;
struct V_12 * V_140 ;
struct V_111 * V_112 ;
if ( F_1 () )
return 0 ;
if ( ! V_13 )
return - V_45 ;
if ( V_70 )
return - V_47 ;
if ( ! V_13 -> V_49 . V_125 )
return - V_47 ;
if ( V_13 -> V_5 == 0 && F_74 () == & V_129 ) {
F_69 () ;
F_75 () ;
F_76 (cpu) {
V_140 = F_52 ( V_117 , V_116 ) ;
if ( ! V_140 || ! V_140 -> V_49 . V_125 )
continue;
V_112 = F_52 ( V_139 , V_116 ) ;
F_70 ( V_112 ) ;
}
F_42 ( V_13 ) ;
F_67 ( V_13 ) ;
F_76 (cpu) {
V_140 = F_52 ( V_117 , V_116 ) ;
if ( ! V_140 || ! V_140 -> V_49 . V_125 )
continue;
F_42 ( V_140 ) ;
if ( V_140 -> V_49 . V_18 ) {
V_112 = F_52 ( V_139 , V_116 ) ;
F_66 ( V_140 , V_112 ) ;
F_71 ( V_112 ) ;
}
}
F_77 () ;
F_72 () ;
}
return 0 ;
}
int T_5 F_78 ( struct V_12 * V_13 )
{
T_3 V_9 = 0 ;
int V_141 ;
struct V_111 * V_112 ;
static int V_142 ;
if ( F_1 () )
return 0 ;
if ( ! V_142 ) {
F_79 ( V_143 ) ;
V_6 = F_80 ( V_6 ) ;
if ( V_6 < V_144 )
F_3 ( V_145
L_22 ,
V_6 ) ;
V_142 ++ ;
}
if ( ! V_13 )
return - V_45 ;
if ( V_48 . V_146 && ! V_70 ) {
V_9 =
F_81 ( V_48 . V_147 , V_48 . V_146 , 8 ) ;
if ( F_36 ( V_9 ) ) {
F_82 ( ( V_148 , V_9 ,
L_23 ) ) ;
}
}
F_42 ( V_13 ) ;
V_13 -> V_49 . V_125 = 1 ;
if ( V_13 -> V_49 . V_18 ) {
if ( ! V_149 ) {
F_67 ( V_13 ) ;
V_141 = F_83 ( & V_129 ) ;
if ( V_141 )
return V_141 ;
F_3 ( V_150 L_24 ,
V_129 . V_130 ) ;
}
V_112 = F_84 ( sizeof( * V_112 ) , V_151 ) ;
if ( ! V_112 )
return - V_152 ;
F_52 ( V_139 , V_13 -> V_5 ) = V_112 ;
F_66 ( V_13 , V_112 ) ;
V_141 = F_85 ( V_112 ) ;
if ( V_141 ) {
if ( V_149 == 0 )
F_86 ( & V_129 ) ;
return V_141 ;
}
V_149 ++ ;
}
return 0 ;
}
int F_87 ( struct V_12 * V_13 )
{
struct V_111 * V_112 = F_52 ( V_139 , V_13 -> V_5 ) ;
if ( F_1 () )
return 0 ;
if ( V_13 -> V_49 . V_18 ) {
F_88 ( V_112 ) ;
V_149 -- ;
if ( V_149 == 0 )
F_86 ( & V_129 ) ;
}
V_13 -> V_49 . V_125 = 0 ;
return 0 ;
}

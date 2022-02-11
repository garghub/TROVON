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
T_3 V_59 = 0 ;
T_4 V_60 ;
int V_61 ;
int V_62 ;
struct V_63 V_64 = { V_65 , NULL } ;
union V_66 * V_67 ;
if ( V_68 )
return - V_44 ;
V_61 = 0 ;
V_59 = F_33 ( V_11 -> V_69 , L_7 , NULL , & V_64 ) ;
if ( F_34 ( V_59 ) ) {
F_30 ( ( V_53 , L_8 ) ) ;
return - V_44 ;
}
V_67 = V_64 . V_70 ;
if ( ! V_67 || ( V_67 -> type != V_71 ) || V_67 -> V_72 . V_60 < 2 ) {
F_3 (KERN_ERR PREFIX L_9 ) ;
V_59 = - V_73 ;
goto V_74;
}
V_60 = V_67 -> V_72 . V_75 [ 0 ] . integer . V_76 ;
if ( V_60 < 1 || V_60 != V_67 -> V_72 . V_60 - 1 ) {
F_3 (KERN_ERR PREFIX L_10 ) ;
V_59 = - V_73 ;
goto V_74;
}
V_11 -> V_46 . V_77 = 1 ;
for ( V_62 = 1 ; V_62 <= V_60 ; V_62 ++ ) {
union V_66 * V_78 ;
union V_66 * V_79 ;
struct V_80 * V_81 ;
struct V_12 V_13 ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_78 = & ( V_67 -> V_72 . V_75 [ V_62 ] ) ;
if ( V_78 -> type != V_71 )
continue;
if ( V_78 -> V_72 . V_60 != 4 )
continue;
V_79 = & ( V_78 -> V_72 . V_75 [ 0 ] ) ;
if ( V_79 -> type != V_82 )
continue;
V_81 = (struct V_80 * ) V_79 -> V_64 . V_70 ;
if ( V_81 -> V_83 != V_84 &&
( V_81 -> V_83 != V_85 ) )
continue;
V_79 = & ( V_78 -> V_72 . V_75 [ 1 ] ) ;
if ( V_79 -> type != V_86 )
continue;
V_13 . type = V_79 -> integer . V_76 ;
if ( V_62 == 1 && V_13 . type != V_22 )
V_61 ++ ;
V_13 . V_48 = V_81 -> V_48 ;
V_13 . V_87 = V_61 + 1 ;
V_13 . V_56 = V_88 ;
if ( V_81 -> V_83 == V_85 ) {
if ( F_35
( V_11 -> V_5 , & V_13 , V_81 ) == 0 ) {
V_13 . V_56 = V_89 ;
} else if ( V_13 . type == V_22 ) {
V_13 . V_56 = V_57 ;
snprintf ( V_13 . V_90 , V_91 , L_11 ) ;
} else {
continue;
}
if ( V_13 . type == V_22 &&
( V_1 == V_92 ) ) {
V_13 . V_56 = V_57 ;
snprintf ( V_13 . V_90 , V_91 , L_11 ) ;
}
} else {
snprintf ( V_13 . V_90 , V_91 , L_12 ,
V_13 . V_48 ) ;
}
if ( V_13 . type == V_22 ) {
V_13 . V_55 = 1 ;
}
V_79 = & ( V_78 -> V_72 . V_75 [ 2 ] ) ;
if ( V_79 -> type != V_86 )
continue;
V_13 . V_49 = V_79 -> integer . V_76 ;
V_79 = & ( V_78 -> V_72 . V_75 [ 3 ] ) ;
if ( V_79 -> type != V_86 )
continue;
V_61 ++ ;
memcpy ( & ( V_11 -> V_16 . V_30 [ V_61 ] ) , & V_13 , sizeof( V_13 ) ) ;
if ( V_61 >= ( V_7 - 1 ) ) {
F_3 ( V_93
L_13 ,
V_7 ) ;
F_3 ( V_93
L_14 ) ;
break;
}
}
F_30 ( ( V_53 , L_15 ,
V_61 ) ) ;
if ( V_61 < 2 )
V_59 = - V_73 ;
V_74:
F_36 ( V_64 . V_70 ) ;
return V_59 ;
}
static void F_37 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
static int V_94 = - 1 ;
static int V_95 = - 1 ;
if ( ! V_13 -> V_48 )
return;
else if ( V_96 . V_97 . V_98 ) {
F_30 ( ( V_53 ,
L_16 ) ) ;
return;
}
if ( V_94 == - 1 ) {
F_38 ( & ( V_11 -> V_46 ) , V_11 -> V_5 ) ;
V_94 = V_11 -> V_46 . V_99 ;
V_95 = V_11 -> V_46 . V_100 ;
} else {
V_11 -> V_46 . V_99 = V_94 ;
V_11 -> V_46 . V_100 = V_95 ;
}
if ( V_11 -> V_46 . V_99 ) {
if ( ! V_11 -> V_46 . V_100 ) {
if ( V_11 -> V_46 . V_77 != 1 ) {
F_30 ( ( V_53 ,
L_17 ) ) ;
return;
} else {
F_30 ( ( V_53 ,
L_18 ) ) ;
}
}
} else {
if ( ! ( V_45 . V_46 & V_101 ) ) {
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
unsigned int V_102 = 0 ;
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
V_102 ++ ;
}
F_13 ( V_11 ) ;
return ( V_102 ) ;
}
static int F_40 ( struct V_10 * V_11 )
{
unsigned int V_62 ;
int V_103 ;
memset ( V_11 -> V_16 . V_30 , 0 , sizeof( V_11 -> V_16 . V_30 ) ) ;
V_103 = F_32 ( V_11 ) ;
if ( V_103 == - V_44 )
V_103 = F_27 ( V_11 ) ;
if ( V_103 )
return V_103 ;
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
T_2 V_104 = 0 ;
if ( V_105 )
return 0 ;
F_17 ( V_106 , & V_104 ) ;
if ( V_104 )
F_19 ( V_106 , 1 ) ;
else if ( V_96 . V_97 . V_107 ) {
if ( ( F_42 ( V_96 . V_97 . V_107 + 0x02 ) & 0x01 )
|| ( F_42 ( V_96 . V_97 . V_107 + 0x0A ) & 0x01 ) )
V_104 = 1 ;
}
return V_104 ;
}
static inline void F_43 ( struct V_12 * V_13 )
{
F_44 () ;
if ( V_13 -> V_56 == V_89 ) {
F_45 ( V_13 ) ;
} else if ( V_13 -> V_56 == V_57 ) {
F_4 () ;
} else {
F_46 ( V_13 -> V_48 ) ;
F_47 ( V_45 . V_108 . V_48 ) ;
}
F_48 () ;
}
static int F_49 ( struct V_109 * V_110 ,
struct V_111 * V_112 , int V_87 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 = F_50 ( V_113 [ V_87 ] , V_110 -> V_114 ) ;
V_11 = F_51 ( V_115 ) ;
if ( F_52 ( ! V_11 ) )
return - V_116 ;
F_15 ( V_11 , V_13 , 1 ) ;
F_43 ( V_13 ) ;
F_15 ( V_11 , V_13 , 0 ) ;
return V_87 ;
}
static int F_53 ( struct V_109 * V_110 , int V_87 )
{
struct V_12 * V_13 = F_50 ( V_113 [ V_87 ] , V_110 -> V_114 ) ;
F_54 () ;
while ( 1 ) {
if ( V_13 -> V_56 == V_57 )
F_6 () ;
else if ( V_13 -> V_56 == V_88 ) {
F_46 ( V_13 -> V_48 ) ;
F_47 ( V_45 . V_108 . V_48 ) ;
} else
return - V_44 ;
}
return 0 ;
}
static int F_55 ( struct V_109 * V_110 ,
struct V_111 * V_112 , int V_87 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 = F_50 ( V_113 [ V_87 ] , V_110 -> V_114 ) ;
V_11 = F_51 ( V_115 ) ;
if ( F_52 ( ! V_11 ) )
return - V_116 ;
#ifdef F_28
if ( ( V_13 -> type != V_22 ) && ( F_29 () > 1 ) &&
! V_11 -> V_46 . V_77 &&
! ( V_45 . V_46 & V_47 ) )
return F_49 ( V_110 , V_112 , V_117 ) ;
#endif
F_15 ( V_11 , V_13 , 1 ) ;
if ( V_13 -> type == V_18 )
F_54 () ;
F_56 () ;
F_43 ( V_13 ) ;
F_57 ( 0 ) ;
F_15 ( V_11 , V_13 , 0 ) ;
return V_87 ;
}
static int F_58 ( struct V_109 * V_110 ,
struct V_111 * V_112 , int V_87 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 = F_50 ( V_113 [ V_87 ] , V_110 -> V_114 ) ;
V_11 = F_51 ( V_115 ) ;
if ( F_52 ( ! V_11 ) )
return - V_116 ;
#ifdef F_28
if ( ( V_13 -> type != V_22 ) && ( F_29 () > 1 ) &&
! V_11 -> V_46 . V_77 &&
! ( V_45 . V_46 & V_47 ) )
return F_49 ( V_110 , V_112 , V_117 ) ;
#endif
if ( ! V_13 -> V_118 && F_41 () ) {
if ( V_112 -> V_119 >= 0 ) {
return V_112 -> V_30 [ V_112 -> V_119 ] . F_59 ( V_110 ,
V_112 , V_112 -> V_119 ) ;
} else {
F_4 () ;
return - V_120 ;
}
}
F_60 ( F_61 () ) ;
F_56 () ;
F_15 ( V_11 , V_13 , 1 ) ;
if ( V_11 -> V_46 . V_99 && V_11 -> V_46 . V_100 ) {
F_62 ( & V_121 ) ;
V_122 ++ ;
if ( V_122 == F_29 () )
F_19 ( V_123 , 1 ) ;
F_63 ( & V_121 ) ;
} else if ( ! V_11 -> V_46 . V_99 ) {
F_54 () ;
}
F_43 ( V_13 ) ;
if ( V_11 -> V_46 . V_99 && V_11 -> V_46 . V_100 ) {
F_62 ( & V_121 ) ;
F_19 ( V_123 , 0 ) ;
V_122 -- ;
F_63 ( & V_121 ) ;
}
F_57 ( 0 ) ;
F_15 ( V_11 , V_13 , 0 ) ;
return V_87 ;
}
static int F_64 ( struct V_10 * V_11 ,
struct V_109 * V_110 )
{
int V_62 , V_60 = V_117 ;
struct V_12 * V_13 ;
if ( ! V_11 -> V_46 . V_124 )
return - V_116 ;
if ( V_11 -> V_46 . V_16 == 0 ) {
return - V_116 ;
}
if ( ! V_110 )
return - V_116 ;
V_110 -> V_114 = V_11 -> V_5 ;
if ( V_6 == 0 )
V_6 = 1 ;
for ( V_62 = 1 ; V_62 < V_7 && V_62 <= V_6 ; V_62 ++ ) {
V_13 = & V_11 -> V_16 . V_30 [ V_62 ] ;
if ( ! V_13 -> V_55 )
continue;
F_50 ( V_113 [ V_60 ] , V_110 -> V_114 ) = V_13 ;
V_60 ++ ;
if ( V_60 == V_125 )
break;
}
if ( ! V_60 )
return - V_116 ;
return 0 ;
}
static int F_65 ( struct V_10 * V_11 )
{
int V_62 , V_60 = V_117 ;
struct V_12 * V_13 ;
struct V_126 * V_9 ;
struct V_111 * V_112 = & V_127 ;
if ( ! V_11 -> V_46 . V_124 )
return - V_116 ;
if ( V_11 -> V_46 . V_16 == 0 )
return - V_116 ;
V_112 -> V_119 = - 1 ;
for ( V_62 = 0 ; V_62 < V_125 ; V_62 ++ ) {
V_112 -> V_30 [ V_62 ] . V_128 [ 0 ] = '\0' ;
V_112 -> V_30 [ V_62 ] . V_90 [ 0 ] = '\0' ;
}
if ( V_6 == 0 )
V_6 = 1 ;
for ( V_62 = 1 ; V_62 < V_7 && V_62 <= V_6 ; V_62 ++ ) {
V_13 = & V_11 -> V_16 . V_30 [ V_62 ] ;
if ( ! V_13 -> V_55 )
continue;
V_9 = & V_112 -> V_30 [ V_60 ] ;
snprintf ( V_9 -> V_128 , V_129 , L_21 , V_62 ) ;
strncpy ( V_9 -> V_90 , V_13 -> V_90 , V_130 ) ;
V_9 -> V_131 = V_13 -> V_49 ;
V_9 -> V_132 = V_13 -> V_49 * V_133 ;
V_9 -> V_46 = 0 ;
switch ( V_13 -> type ) {
case V_22 :
if ( V_13 -> V_56 == V_89 )
V_9 -> V_46 |= V_134 ;
V_9 -> F_59 = F_49 ;
V_9 -> V_135 = F_53 ;
V_112 -> V_119 = V_60 ;
break;
case V_19 :
V_9 -> V_46 |= V_134 ;
V_9 -> F_59 = F_55 ;
V_9 -> V_135 = F_53 ;
V_112 -> V_119 = V_60 ;
break;
case V_18 :
V_9 -> V_46 |= V_134 ;
V_9 -> F_59 = V_11 -> V_46 . V_99 ?
F_58 :
F_55 ;
break;
}
V_60 ++ ;
if ( V_60 == V_125 )
break;
}
V_112 -> V_136 = V_60 ;
if ( ! V_60 )
return - V_116 ;
return 0 ;
}
int F_66 ( struct V_10 * V_11 )
{
int V_137 = 0 ;
struct V_109 * V_110 ;
if ( F_1 () )
return 0 ;
if ( V_68 )
return - V_44 ;
if ( ! V_11 -> V_46 . V_124 )
return - V_44 ;
V_110 = F_50 ( V_138 , V_11 -> V_5 ) ;
F_67 () ;
F_68 ( V_110 ) ;
F_40 ( V_11 ) ;
if ( V_11 -> V_46 . V_16 ) {
F_64 ( V_11 , V_110 ) ;
V_137 = F_69 ( V_110 ) ;
}
F_70 () ;
return V_137 ;
}
int F_71 ( struct V_10 * V_11 )
{
int V_114 ;
struct V_10 * V_139 ;
struct V_109 * V_110 ;
if ( F_1 () )
return 0 ;
if ( V_68 )
return - V_44 ;
if ( ! V_11 -> V_46 . V_124 )
return - V_44 ;
if ( V_11 -> V_5 == 0 && F_72 () == & V_127 ) {
F_67 () ;
F_73 () ;
F_74 (cpu) {
V_139 = F_50 ( V_115 , V_114 ) ;
if ( ! V_139 || ! V_139 -> V_46 . V_124 )
continue;
V_110 = F_50 ( V_138 , V_114 ) ;
F_68 ( V_110 ) ;
}
F_40 ( V_11 ) ;
F_65 ( V_11 ) ;
F_74 (cpu) {
V_139 = F_50 ( V_115 , V_114 ) ;
if ( ! V_139 || ! V_139 -> V_46 . V_124 )
continue;
F_40 ( V_139 ) ;
if ( V_139 -> V_46 . V_16 ) {
V_110 = F_50 ( V_138 , V_114 ) ;
F_64 ( V_139 , V_110 ) ;
F_69 ( V_110 ) ;
}
}
F_75 () ;
F_70 () ;
}
return 0 ;
}
int F_76 ( struct V_10 * V_11 )
{
T_3 V_59 = 0 ;
int V_140 ;
struct V_109 * V_110 ;
static int V_141 ;
if ( F_1 () )
return 0 ;
if ( ! V_141 ) {
F_77 ( V_142 ) ;
V_6 = F_78 ( V_6 ) ;
if ( V_6 < V_143 )
F_3 ( V_144
L_22 ,
V_6 ) ;
V_141 ++ ;
}
if ( V_45 . V_145 && ! V_68 ) {
V_59 =
F_79 ( V_45 . V_146 , V_45 . V_145 , 8 ) ;
if ( F_34 ( V_59 ) ) {
F_80 ( ( V_147 , V_59 ,
L_23 ) ) ;
}
}
F_40 ( V_11 ) ;
V_11 -> V_46 . V_124 = 1 ;
if ( V_11 -> V_46 . V_16 ) {
if ( ! V_148 ) {
F_65 ( V_11 ) ;
V_140 = F_81 ( & V_127 ) ;
if ( V_140 )
return V_140 ;
F_3 ( V_149 L_24 ,
V_127 . V_128 ) ;
}
V_110 = F_82 ( sizeof( * V_110 ) , V_150 ) ;
if ( ! V_110 )
return - V_151 ;
F_50 ( V_138 , V_11 -> V_5 ) = V_110 ;
F_64 ( V_11 , V_110 ) ;
V_140 = F_83 ( V_110 ) ;
if ( V_140 ) {
if ( V_148 == 0 )
F_84 ( & V_127 ) ;
return V_140 ;
}
V_148 ++ ;
}
return 0 ;
}
int F_85 ( struct V_10 * V_11 )
{
struct V_109 * V_110 = F_50 ( V_138 , V_11 -> V_5 ) ;
if ( F_1 () )
return 0 ;
if ( V_11 -> V_46 . V_16 ) {
F_86 ( V_110 ) ;
V_148 -- ;
if ( V_148 == 0 )
F_84 ( & V_127 ) ;
}
V_11 -> V_46 . V_124 = 0 ;
return 0 ;
}

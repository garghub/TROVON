static void F_1 ( T_1 V_1 )
{
T_2 V_2 ;
V_2 = F_2 ( NULL , L_1 , V_1 ) ;
if ( F_3 ( V_2 ) && V_2 != V_3 ) {
F_4 ( V_4 L_2 ) ;
}
}
static int F_5 ( struct V_5 * V_6 ,
unsigned long V_7 , void * V_8 )
{
F_1 ( V_9 ) ;
return V_10 ;
}
static int F_6 ( T_1 V_1 )
{
#ifdef F_7
if ( V_1 == V_11 ) {
if ( ! V_12 )
return - V_13 ;
F_8 ( V_12 ) ;
}
F_9 () ;
#endif
F_4 (KERN_INFO PREFIX L_3 ,
acpi_state) ;
F_10 ( V_1 ) ;
F_11 ( V_1 ) ;
return 0 ;
}
static bool F_12 ( T_3 V_14 )
{
T_2 V_2 ;
T_3 V_15 , V_16 ;
V_2 = F_13 ( V_14 , & V_15 , & V_16 ) ;
return F_14 ( V_2 ) && ( ! V_17
|| ( V_18 . V_19 . V_20
&& V_18 . V_21 . V_20 ) ) ;
}
T_1 F_15 ( void )
{
return V_22 ;
}
void T_4 F_16 ( void )
{
V_23 = true ;
}
void T_4 F_17 ( void )
{
V_24 = true ;
}
static int T_4 F_18 ( const struct V_25 * V_26 )
{
V_24 = false ;
return 0 ;
}
void T_4 F_19 ( void )
{
V_27 = true ;
}
static int T_4 F_20 ( const struct V_25 * V_26 )
{
F_19 () ;
return 0 ;
}
static int T_4 F_21 ( const struct V_25 * V_26 )
{
F_16 () ;
return 0 ;
}
static int T_4 F_22 ( const struct V_25 * V_26 )
{
V_28 = true ;
return 0 ;
}
static void T_4 F_23 ( void )
{
int V_29 ;
if ( F_24 ( V_30 , & V_29 , NULL , NULL ) && V_29 >= 2012 )
F_17 () ;
F_25 ( V_31 ) ;
}
static int F_26 ( void )
{
F_27 () ;
F_28 () ;
F_29 () ;
return 0 ;
}
static int F_30 ( void )
{
F_26 () ;
return F_31 () ;
}
static int F_32 ( void )
{
int error = F_6 ( V_22 ) ;
if ( error )
V_22 = V_32 ;
return error ;
}
static int F_33 ( void )
{
int error = F_32 () ;
if ( ! error )
error = F_30 () ;
return error ;
}
static int F_34 ( struct V_33 * V_34 , void * V_35 )
{
struct V_36 * V_33 = F_35 ( V_34 ) ;
const char * V_37 = F_36 ( V_33 ) ;
return ! strcmp ( V_37 , V_38 ) ;
}
static void F_37 ( void )
{
struct V_33 * V_39 ;
T_1 V_1 = V_22 ;
F_38 () ;
F_39 () ;
if ( V_1 == V_32 )
return;
F_4 (KERN_INFO PREFIX L_4 ,
acpi_state) ;
F_40 ( V_1 ) ;
F_41 ( V_1 ) ;
F_8 ( 0 ) ;
V_22 = V_32 ;
F_42 () ;
if ( ! V_40 )
return;
V_40 = false ;
V_39 = F_43 ( & V_41 , NULL , NULL ,
F_34 ) ;
if ( V_39 ) {
F_44 ( V_39 , 0 ) ;
F_45 ( V_39 ) ;
}
}
static void F_46 ( T_1 V_1 )
{
V_22 = V_1 ;
F_1 ( V_22 ) ;
F_47 () ;
}
static void F_48 ( void )
{
F_49 () ;
F_50 () ;
V_22 = V_32 ;
F_1 ( V_22 ) ;
}
static inline void F_23 ( void ) {}
static int F_51 ( T_5 V_42 )
{
T_1 V_1 = V_43 [ V_42 ] ;
int error ;
error = ( V_23 || V_24 ) ? 0 : F_52 () ;
if ( error )
return error ;
if ( ! V_44 [ V_1 ] ) {
F_53 ( L_5 , V_1 ) ;
return - V_45 ;
}
if ( V_1 > V_46 )
F_54 () ;
F_46 ( V_1 ) ;
return 0 ;
}
static int F_55 ( T_5 V_42 )
{
T_2 V_2 = V_47 ;
T_1 V_1 = V_22 ;
int error ;
F_9 () ;
F_56 ( F_57 ( L_6 ) , V_1 , true ) ;
switch ( V_1 ) {
case V_46 :
F_58 () ;
V_2 = F_59 ( V_1 ) ;
break;
case V_11 :
if ( ! V_48 )
return - V_45 ;
error = V_48 () ;
if ( error )
return error ;
F_60 ( V_49 L_7 ) ;
F_61 () ;
break;
}
F_56 ( F_57 ( L_6 ) , V_1 , false ) ;
F_62 ( V_50 , 1 ) ;
F_63 ( V_1 ) ;
if ( F_14 ( V_2 ) && ( V_1 == V_11 ) ) {
T_6 V_51 = V_52 ;
F_64 ( V_53 , & V_51 ) ;
if ( V_51 & V_54 ) {
F_65 ( V_53 ) ;
V_40 = true ;
}
}
F_27 () ;
F_38 () ;
F_66 () ;
return F_14 ( V_2 ) ? 0 : - V_13 ;
}
static int F_67 ( T_5 V_42 )
{
T_1 V_1 ;
switch ( V_42 ) {
case V_55 :
case V_56 :
case V_57 :
V_1 = V_43 [ V_42 ] ;
return V_44 [ V_1 ] ;
default:
return 0 ;
}
}
static int F_68 ( T_5 V_42 )
{
int error = F_51 ( V_42 ) ;
if ( ! error )
error = F_32 () ;
return error ;
}
static void F_69 ( void )
{
union V_58 * V_59 ;
int V_60 ;
V_59 = F_70 ( V_61 , & V_62 ,
1 , V_63 ,
NULL , V_64 ) ;
F_71 ( V_61 , L_8 ,
V_59 ? L_9 : L_10 ) ;
if ( ! V_59 )
return;
V_65 = F_72 ( V_59 -> V_66 . V_67 ,
sizeof( * V_65 ) ,
V_68 ) ;
if ( ! V_65 )
goto V_69;
F_71 ( V_61 , L_11 ) ;
for ( V_60 = 0 ; V_60 < V_59 -> V_66 . V_67 ; V_60 ++ ) {
struct V_70 * V_71 ;
T_2 V_2 ;
union V_58 * V_66 = & V_59 -> V_66 . V_72 [ V_60 ] ;
struct V_73 V_74 = { } ;
int V_75 = 0 , V_76 ;
if ( ! V_66 )
continue;
for ( V_76 = 0 ; V_76 < V_66 -> V_66 . V_67 ; ++ V_76 ) {
union V_58 * V_77 =
& ( V_66 -> V_66 . V_72 [ V_76 ] ) ;
switch ( V_77 -> type ) {
case V_78 :
V_74 . V_79 = V_77 -> integer . V_80 ;
break;
case V_81 :
V_74 . V_82 = V_77 -> string . V_83 ;
break;
case V_64 :
V_75 = V_77 -> V_66 . V_67 ;
V_74 . V_66 = V_77 -> V_66 . V_72 ;
break;
}
}
if ( ! V_74 . V_79 || ! V_74 . V_66 || ! V_74 . V_82 )
continue;
V_71 = & V_65 [ V_84 ] ;
V_2 = F_73 ( NULL , V_74 . V_82 , & V_71 -> V_85 ) ;
if ( F_3 ( V_2 ) )
continue;
F_71 ( V_61 ,
L_12 , V_60 , V_74 . V_82 ) ;
V_71 -> V_86 = - 1 ;
for ( V_76 = 0 ; V_76 < V_75 ; ++ V_76 ) {
union V_58 * V_87 = & V_74 . V_66 [ V_76 ] ;
union V_58 * V_88 ;
union V_58 * V_89 ;
struct V_90 V_91 ;
switch ( V_87 -> type ) {
case V_78 :
break;
case V_64 :
if ( V_87 -> V_66 . V_67 < 2 )
break;
V_88 = V_87 -> V_66 . V_72 ;
V_89 = & V_88 [ 0 ] ;
V_91 . V_92 = V_89 -> integer . V_80 ;
V_89 = & V_88 [ 1 ] ;
V_91 . V_86 = V_89 -> integer . V_80 ;
F_71 ( V_61 ,
L_13 ,
V_91 . V_92 ,
F_74 ( V_91 . V_86 ) ) ;
V_71 -> V_86 = V_91 . V_86 ;
break;
}
}
if ( V_71 -> V_86 < 0 ) {
F_71 ( V_61 ,
L_14 ) ;
continue;
}
V_84 ++ ;
}
F_71 ( V_61 , L_15 ) ;
V_69:
F_75 ( V_59 ) ;
}
static void F_76 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_84 ; ++ V_60 ) {
struct V_36 * V_93 ;
if ( F_77 ( V_65 [ V_60 ] . V_85 , & V_93 ) )
continue;
F_71 ( V_93 -> V_85 ,
L_16 ,
F_74 ( V_65 [ V_60 ] . V_86 ) ,
F_74 ( V_93 -> V_94 . V_95 ) ) ;
if ( ! V_93 -> V_96 . V_97 ) {
F_78 ( V_93 -> V_85 , L_17 ) ;
continue;
}
if ( V_93 -> V_94 . V_95 < V_65 [ V_60 ] . V_86 )
F_78 ( V_93 -> V_85 ,
L_18 ,
F_74 ( V_65 [ V_60 ] . V_86 ) ,
F_74 ( V_93 -> V_94 . V_95 ) ) ;
}
}
static void F_79 ( unsigned int V_98 )
{
union V_58 * V_59 ;
if ( ! ( V_99 & ( 1 << V_98 ) ) )
return;
V_59 = F_80 ( V_61 , & V_62 , 1 , V_98 , NULL ) ;
F_75 ( V_59 ) ;
F_71 ( V_61 , L_19 ,
V_98 , V_59 ? L_9 : L_10 ) ;
}
static int F_81 ( struct V_36 * V_93 ,
const struct V_100 * V_101 )
{
union V_58 * V_59 ;
if ( V_61 )
return 0 ;
if ( V_28 ) {
F_78 ( V_93 -> V_85 ,
L_20 ) ;
return 0 ;
}
if ( ! ( V_18 . V_96 & V_102 ) )
return 0 ;
F_82 ( V_103 , & V_62 ) ;
V_59 = F_80 ( V_93 -> V_85 , & V_62 , 1 , 0 , NULL ) ;
if ( V_59 && V_59 -> type == V_104 ) {
char V_105 = * ( char * ) V_59 -> V_106 . V_83 ;
if ( ( V_105 & V_107 ) == V_107 ) {
V_99 = V_105 ;
V_61 = V_93 -> V_85 ;
if ( V_108 > V_57 )
V_109 = V_110 ;
}
F_71 ( V_93 -> V_85 , L_21 ,
V_105 ) ;
} else {
F_71 ( V_93 -> V_85 ,
L_22 ) ;
}
F_75 ( V_59 ) ;
F_69 () ;
return 0 ;
}
static int F_83 ( void )
{
F_47 () ;
V_111 = true ;
return 0 ;
}
static int F_84 ( void )
{
if ( V_61 ) {
F_79 ( V_112 ) ;
F_79 ( V_113 ) ;
} else {
F_85 () ;
F_28 () ;
}
if ( F_86 () )
F_87 ( V_114 ) ;
return 0 ;
}
static void F_88 ( void )
{
if ( V_115 )
F_76 () ;
if ( F_86 () &&
! F_89 ( F_90 ( V_114 ) ) ) {
F_91 () ;
V_116 = true ;
}
}
static void F_92 ( void )
{
F_93 () ;
F_28 () ;
V_116 = false ;
}
static void F_94 ( void )
{
if ( F_86 () )
F_95 ( V_114 ) ;
if ( V_61 ) {
F_79 ( V_117 ) ;
F_79 ( V_118 ) ;
} else {
F_96 () ;
}
}
static void F_97 ( void )
{
V_111 = false ;
F_50 () ;
}
static void F_98 ( void )
{
int V_60 ;
for ( V_60 = V_46 ; V_60 < V_119 ; V_60 ++ )
if ( F_12 ( V_60 ) )
V_44 [ V_60 ] = 1 ;
F_99 ( V_27 ?
& V_120 : & V_121 ) ;
F_100 ( & V_122 ) ;
F_101 ( & V_123 ) ;
}
static inline void F_98 ( void ) {}
bool F_102 ( void )
{
return V_116 ;
}
bool F_103 ( void )
{
return ! V_111 || ! V_61 ;
}
static int F_104 ( void )
{
F_105 ( V_124 , & V_125 ) ;
return 0 ;
}
static void F_106 ( void )
{
T_1 V_126 = 0 ;
F_105 ( V_124 , & V_126 ) ;
if ( V_126 == V_125 )
return;
F_62 ( V_124 , V_125 ) ;
}
static void F_107 ( void )
{
F_108 ( & V_127 ) ;
}
static inline void F_107 ( void ) {}
void T_4 F_109 ( void )
{
V_128 = true ;
}
static int F_110 ( void )
{
int error ;
error = V_23 ? 0 : F_52 () ;
if ( ! error )
F_46 ( V_119 ) ;
return error ;
}
static int F_111 ( void )
{
T_2 V_2 = V_47 ;
F_9 () ;
V_2 = F_59 ( V_119 ) ;
F_63 ( V_119 ) ;
return F_14 ( V_2 ) ? 0 : - V_13 ;
}
static void F_112 ( void )
{
F_61 () ;
F_113 () ;
F_63 ( V_119 ) ;
if ( V_129 && V_130 != V_129 -> V_131 )
F_114 ( L_23 ) ;
F_66 () ;
F_38 () ;
}
static void F_115 ( void )
{
F_38 () ;
F_96 () ;
}
static int F_116 ( void )
{
int error ;
F_1 ( V_119 ) ;
error = F_6 ( V_119 ) ;
if ( ! error ) {
if ( ! V_23 )
error = F_52 () ;
if ( ! error ) {
V_22 = V_119 ;
F_47 () ;
}
}
return error ;
}
static void F_117 ( void )
{
if ( ! F_12 ( V_119 ) )
return;
F_118 ( V_27 ?
& V_132 : & V_133 ) ;
V_44 [ V_119 ] = 1 ;
if ( V_128 )
return;
F_119 ( V_134 , 1 , (struct V_135 * * ) & V_129 ) ;
if ( V_129 )
V_130 = V_129 -> V_131 ;
}
static inline void F_117 ( void ) {}
static void F_120 ( void )
{
F_6 ( V_9 ) ;
F_27 () ;
F_28 () ;
}
static void F_121 ( void )
{
F_4 ( V_136 L_24 , V_137 ) ;
F_122 () ;
F_59 ( V_9 ) ;
}
int T_4 F_123 ( void )
{
char V_138 [ V_139 * 3 + 1 ] ;
char * V_140 = V_138 ;
int V_60 ;
F_23 () ;
V_44 [ V_32 ] = 1 ;
F_107 () ;
F_98 () ;
F_117 () ;
if ( F_12 ( V_9 ) ) {
V_44 [ V_9 ] = 1 ;
V_141 = F_120 ;
V_142 = F_121 ;
} else {
V_143 = true ;
}
V_138 [ 0 ] = 0 ;
for ( V_60 = 0 ; V_60 < V_139 ; V_60 ++ ) {
if ( V_44 [ V_60 ] )
V_140 += sprintf ( V_140 , L_25 , V_60 ) ;
}
F_60 ( V_49 L_26 , V_138 ) ;
F_124 ( & V_144 ) ;
return 0 ;
}

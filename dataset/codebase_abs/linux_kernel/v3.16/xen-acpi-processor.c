static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 = {
. V_5 = V_6 ,
. V_7 = V_8 ,
. V_9 . V_10 . V_11 = V_2 -> V_12 ,
. V_9 . V_10 . type = V_13 ,
} ;
struct V_14 * V_15 , * V_16 = NULL ;
struct V_17 * V_18 ;
unsigned int V_19 , V_20 ;
int V_21 = 0 ;
V_16 = F_2 ( V_2 -> V_22 . V_23 ,
sizeof( struct V_14 ) , V_24 ) ;
if ( ! V_16 )
return - V_25 ;
for ( V_20 = 0 , V_19 = 1 ; V_19 <= V_2 -> V_22 . V_23 ; V_19 ++ ) {
V_18 = & V_2 -> V_22 . V_26 [ V_19 ] ;
if ( ! V_18 -> V_27 )
continue;
V_15 = & ( V_16 [ V_20 ++ ] ) ;
V_15 -> V_28 . V_29 = V_30 ;
if ( V_18 -> V_31 == V_32 ) {
V_15 -> V_28 . V_33 = 8 ;
V_15 -> V_28 . V_34 = 0 ;
V_15 -> V_28 . V_35 = 1 ;
} else {
V_15 -> V_28 . V_29 = V_36 ;
if ( V_18 -> V_31 == V_37 ) {
V_15 -> V_28 . V_34 = 2 ;
V_15 -> V_28 . V_33 = 1 ;
}
V_15 -> V_28 . V_35 = 0 ;
}
V_15 -> V_28 . V_38 = V_18 -> V_38 ;
V_15 -> type = V_18 -> type ;
V_15 -> V_39 = V_18 -> V_39 ;
V_15 -> V_40 = 0 ;
F_3 ( V_15 -> V_41 , NULL ) ;
}
if ( ! V_20 ) {
F_4 ( L_1 , V_2 -> V_12 ) ;
F_5 ( V_16 ) ;
return - V_42 ;
}
V_4 . V_9 . V_10 . V_22 . V_23 = V_20 ;
V_4 . V_9 . V_10 . V_22 . V_43 . V_44 = V_2 -> V_43 . V_44 ;
V_4 . V_9 . V_10 . V_22 . V_43 . V_45 = V_2 -> V_43 . V_45 ;
V_4 . V_9 . V_10 . V_22 . V_43 . V_46 = V_2 -> V_43 . V_46 ;
V_4 . V_9 . V_10 . V_22 . V_43 . V_47 =
V_2 -> V_43 . V_47 ;
F_3 ( V_4 . V_9 . V_10 . V_22 . V_26 , V_16 ) ;
if ( ! V_48 )
V_21 = F_6 ( & V_4 ) ;
if ( ! V_21 ) {
F_4 ( L_2 , V_2 -> V_12 ) ;
for ( V_19 = 1 ; V_19 <= V_2 -> V_22 . V_23 ; V_19 ++ ) {
V_18 = & V_2 -> V_22 . V_26 [ V_19 ] ;
if ( ! V_18 -> V_27 )
continue;
F_4 ( L_3 ,
V_18 -> type , V_18 -> V_49 , ( V_50 ) V_18 -> V_39 ) ;
}
} else if ( ( V_21 != - V_42 ) && ( V_21 != - V_51 ) )
F_7 ( L_4 ,
V_21 , V_2 -> V_12 ) ;
F_5 ( V_16 ) ;
return V_21 ;
}
static struct V_52 *
F_8 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
struct V_52 * V_55 = NULL ;
unsigned int V_19 ;
F_9 ( sizeof( struct V_52 ) !=
sizeof( struct V_56 ) ) ;
V_55 = F_2 ( V_2 -> V_57 -> V_58 ,
sizeof( struct V_52 ) , V_24 ) ;
if ( ! V_55 )
return F_10 ( - V_25 ) ;
V_54 -> V_58 = V_2 -> V_57 -> V_58 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_57 -> V_58 ; V_19 ++ ) {
memcpy ( & ( V_55 [ V_19 ] ) , & ( V_2 -> V_57 -> V_26 [ V_19 ] ) ,
sizeof( struct V_56 ) ) ;
}
return V_55 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_53 * V_59 )
{
struct V_60 * V_61 ;
F_9 ( sizeof( struct V_62 ) !=
sizeof( struct V_60 ) ) ;
V_59 -> V_63 = V_2 -> V_57 -> V_63 ;
V_61 = & ( V_2 -> V_57 -> V_64 ) ;
if ( V_61 -> V_65 <= 1 ) {
if ( V_61 -> V_66 == V_67 )
V_59 -> V_63 = V_68 ;
else if ( V_61 -> V_66 == V_69 )
V_59 -> V_63 = V_70 ;
else if ( V_61 -> V_66 == V_71 )
V_59 -> V_63 = V_72 ;
}
memcpy ( & ( V_59 -> V_64 ) , V_61 , sizeof( struct V_60 ) ) ;
return 0 ;
}
static int F_12 ( struct V_73 * V_74 ,
struct V_75 * V_76 )
{
V_76 -> V_77 = V_74 -> V_77 ;
V_76 -> V_78 = V_74 -> V_78 ;
V_76 -> V_29 = V_74 -> V_29 ;
V_76 -> V_33 = V_74 -> V_33 ;
V_76 -> V_34 = V_74 -> V_34 ;
V_76 -> V_79 = V_74 -> V_79 ;
V_76 -> V_38 = V_74 -> V_38 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_21 = 0 ;
struct V_3 V_4 = {
. V_5 = V_6 ,
. V_7 = V_8 ,
. V_9 . V_10 . V_11 = V_2 -> V_12 ,
. V_9 . V_10 . type = V_80 ,
} ;
struct V_53 * V_54 ;
struct V_52 * V_55 = NULL ;
V_54 = & V_4 . V_9 . V_10 . V_81 ;
V_54 -> V_82 = V_2 -> V_83 ;
V_54 -> V_43 |= V_84 ;
F_12 ( & ( V_2 -> V_57 -> V_85 ) ,
& V_54 -> V_85 ) ;
F_12 ( & ( V_2 -> V_57 -> V_86 ) ,
& V_54 -> V_86 ) ;
V_54 -> V_43 |= V_87 ;
V_55 = F_8 ( V_2 , V_54 ) ;
if ( ! F_14 ( V_55 ) ) {
F_3 ( V_54 -> V_26 , V_55 ) ;
V_54 -> V_43 |= V_88 ;
}
if ( ! F_11 ( V_2 , V_54 ) )
V_54 -> V_43 |= V_89 ;
if ( V_54 -> V_43 != ( V_89 | V_88 | V_87 | V_84 ) ) {
F_15 ( L_5 ,
V_2 -> V_12 , V_54 -> V_43 ) ;
V_21 = - V_90 ;
goto V_91;
}
if ( ! V_48 )
V_21 = F_6 ( & V_4 ) ;
if ( ! V_21 ) {
struct V_92 * V_81 ;
unsigned int V_19 ;
V_81 = V_2 -> V_57 ;
F_4 ( L_6 , V_2 -> V_12 ) ;
for ( V_19 = 0 ; V_19 < V_81 -> V_58 ; V_19 ++ ) {
F_4 ( L_7 ,
( V_19 == V_81 -> V_93 ? '*' : ' ' ) , V_19 ,
( V_50 ) V_81 -> V_26 [ V_19 ] . V_94 ,
( V_50 ) V_81 -> V_26 [ V_19 ] . V_22 ,
( V_50 ) V_81 -> V_26 [ V_19 ] . V_95 ) ;
}
} else if ( ( V_21 != - V_42 ) && ( V_21 != - V_51 ) )
F_15 ( L_8 ,
V_21 , V_2 -> V_12 ) ;
V_91:
if ( ! F_14 ( V_55 ) )
F_5 ( V_55 ) ;
return V_21 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_96 = 0 ;
F_17 ( & V_97 ) ;
if ( F_18 ( V_2 -> V_12 , V_98 ) ) {
F_19 ( & V_97 ) ;
return - V_99 ;
}
if ( V_2 -> V_43 . V_22 )
V_96 = F_1 ( V_2 ) ;
if ( V_2 -> V_57 && V_2 -> V_57 -> V_26 )
V_96 |= F_13 ( V_2 ) ;
F_19 ( & V_97 ) ;
return V_96 ;
}
static unsigned int T_1 F_20 ( void )
{
struct V_100 * V_101 ;
struct V_3 V_4 = {
. V_5 = V_102 ,
. V_7 = V_8 ,
} ;
int V_21 = 0 ;
unsigned int V_19 , V_103 , V_104 = 0 ;
V_101 = & V_4 . V_9 . V_105 ;
V_101 -> V_106 = 0 ;
V_21 = F_6 ( & V_4 ) ;
if ( V_21 )
return V_107 ;
V_103 = V_4 . V_9 . V_105 . V_108 ;
for ( V_19 = 0 ; V_19 <= V_103 ; V_19 ++ ) {
V_101 -> V_106 = V_19 ;
V_21 = F_6 ( & V_4 ) ;
if ( V_21 )
continue;
V_104 = F_21 ( V_101 -> V_12 , V_104 ) ;
}
V_104 *= 2 ;
F_4 ( L_9 , V_104 ) ;
return V_104 ;
}
static T_2
F_22 ( T_3 V_109 , V_50 V_110 , void * V_111 , void * * V_112 )
{
V_50 V_12 ;
T_2 V_113 ;
T_4 V_114 ;
unsigned long long V_115 ;
union V_116 V_117 = { 0 } ;
struct V_118 V_119 = { sizeof( union V_116 ) , & V_117 } ;
T_5 V_120 = 0 ;
V_113 = F_23 ( V_109 , & V_114 ) ;
if ( F_24 ( V_113 ) )
return V_121 ;
switch ( V_114 ) {
case V_122 :
V_113 = F_25 ( V_109 , NULL , NULL , & V_119 ) ;
if ( F_24 ( V_113 ) )
return V_121 ;
V_12 = V_117 . V_123 . V_124 ;
V_120 = V_117 . V_123 . V_125 ;
break;
case V_126 :
V_113 = F_26 ( V_109 , L_10 , NULL , & V_115 ) ;
if ( F_24 ( V_113 ) )
return V_121 ;
V_12 = V_115 ;
break;
default:
return V_121 ;
}
if ( V_12 > V_127 ) {
F_4 ( L_11 ,
V_127 , V_12 ) ;
return V_121 ;
}
F_27 ( V_12 , V_128 ) ;
F_4 ( L_12 , V_12 , ( unsigned long ) V_120 ) ;
V_113 = F_25 ( V_109 , L_13 , NULL , & V_119 ) ;
if ( F_24 ( V_113 ) ) {
if ( ! V_120 )
return V_121 ;
}
F_27 ( V_12 , V_129 ) ;
return V_121 ;
}
static int F_28 ( struct V_1 * V_130 )
{
if ( ! V_130 )
return - V_90 ;
if ( V_128 && V_129 )
goto V_131;
V_128 = F_2 ( F_29 ( V_127 ) , sizeof( unsigned long ) , V_24 ) ;
if ( ! V_128 )
return - V_25 ;
V_129 = F_2 ( F_29 ( V_127 ) , sizeof( unsigned long ) , V_24 ) ;
if ( ! V_129 ) {
F_5 ( V_128 ) ;
return - V_25 ;
}
F_30 ( V_122 , V_132 ,
V_133 ,
F_22 , NULL , NULL , NULL ) ;
F_31 ( L_14 , F_22 , NULL , NULL ) ;
V_131:
if ( ! F_32 ( V_128 , V_98 , V_127 ) ) {
unsigned int V_19 ;
F_33 (i, acpi_id_present, nr_acpi_bits) {
V_130 -> V_12 = V_19 ;
V_130 -> V_43 . V_22 = F_34 ( V_19 , V_129 ) ;
( void ) F_16 ( V_130 ) ;
}
}
return 0 ;
}
static int T_1 F_35 ( void )
{
struct V_134 * V_135 = & F_36 ( 0 ) ;
if ( ! F_37 () )
return - V_90 ;
if ( ! V_136 . V_137 )
return - V_90 ;
if ( V_135 -> V_138 == V_139 ) {
if ( ! F_38 ( V_135 , V_140 ) )
return - V_90 ;
return 0 ;
}
if ( V_135 -> V_138 == V_141 ) {
#define F_39 0x80000007
#define F_40 0x00000080
V_50 V_142 , V_143 , V_144 , V_145 ;
F_41 ( F_39 , & V_142 , & V_143 , & V_144 , & V_145 ) ;
if ( ( V_145 & F_40 ) != F_40 )
return - V_90 ;
return 0 ;
}
return - V_90 ;
}
static void F_42 ( void )
{
unsigned int V_19 ;
F_43 (i)
F_44 ( F_45 ( V_146 , V_19 )
-> V_147 ) ;
F_46 ( V_146 ) ;
}
static int F_47 ( void )
{
struct V_1 * V_130 = NULL ;
unsigned int V_19 ;
int V_148 = 0 ;
F_48 ( L_15 ) ;
F_43 (i) {
struct V_1 * V_2 ;
V_2 = F_49 ( V_149 , V_19 ) ;
if ( ! V_2 )
continue;
if ( ! V_130 ) {
V_130 = F_50 ( sizeof( struct V_1 ) , V_24 ) ;
if ( V_130 )
memcpy ( V_130 , V_2 , sizeof( struct V_1 ) ) ;
}
( void ) F_16 ( V_2 ) ;
}
V_148 = F_28 ( V_130 ) ;
F_5 ( V_130 ) ;
return V_148 ;
}
static int F_51 ( struct V_150 * V_151 ,
unsigned long V_152 , void * V_153 )
{
F_52 ( V_98 , V_127 ) ;
return F_47 () ;
}
static int T_1 F_53 ( void )
{
unsigned int V_19 ;
int V_148 = F_35 () ;
if ( V_148 )
return V_148 ;
V_127 = F_20 () + 1 ;
V_98 = F_2 ( F_29 ( V_127 ) , sizeof( unsigned long ) , V_24 ) ;
if ( ! V_98 )
return - V_25 ;
V_146 = F_54 ( struct V_92 ) ;
if ( ! V_146 ) {
F_4 ( L_16 ) ;
F_5 ( V_98 ) ;
return - V_25 ;
}
F_43 (i) {
if ( ! F_55 (
& F_45 ( V_146 , V_19 ) -> V_147 ,
V_24 , F_56 ( V_19 ) ) ) {
V_148 = - V_25 ;
goto V_154;
}
}
( void ) F_57 ( V_146 ) ;
F_43 (i) {
struct V_1 * V_155 ;
struct V_92 * V_81 ;
V_155 = F_49 ( V_149 , V_19 ) ;
V_81 = F_45 ( V_146 , V_19 ) ;
if ( ! V_155 )
continue;
V_155 -> V_57 = V_81 ;
V_148 = F_58 ( V_155 ) ;
if ( V_148 )
goto V_154;
}
V_148 = F_47 () ;
if ( V_148 )
goto V_156;
F_59 ( & V_157 ) ;
return 0 ;
V_156:
F_43 (i) {
struct V_92 * V_81 ;
V_81 = F_45 ( V_146 , V_19 ) ;
F_60 ( V_81 , V_19 ) ;
}
V_154:
F_42 () ;
F_5 ( V_98 ) ;
return V_148 ;
}
static void T_6 F_61 ( void )
{
int V_19 ;
F_62 ( & V_157 ) ;
F_5 ( V_98 ) ;
F_5 ( V_128 ) ;
F_5 ( V_129 ) ;
F_43 (i) {
struct V_92 * V_81 ;
V_81 = F_45 ( V_146 , V_19 ) ;
F_60 ( V_81 , V_19 ) ;
}
F_42 () ;
}

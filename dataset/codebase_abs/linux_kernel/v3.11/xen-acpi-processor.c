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
} else if ( V_21 != - V_42 )
F_7 ( L_4 ,
V_21 , V_2 -> V_12 ) ;
F_5 ( V_16 ) ;
return V_21 ;
}
static struct V_51 *
F_8 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_51 * V_54 = NULL ;
unsigned int V_19 ;
F_9 ( sizeof( struct V_51 ) !=
sizeof( struct V_55 ) ) ;
V_54 = F_2 ( V_2 -> V_56 -> V_57 ,
sizeof( struct V_51 ) , V_24 ) ;
if ( ! V_54 )
return F_10 ( - V_25 ) ;
V_53 -> V_57 = V_2 -> V_56 -> V_57 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_56 -> V_57 ; V_19 ++ ) {
memcpy ( & ( V_54 [ V_19 ] ) , & ( V_2 -> V_56 -> V_26 [ V_19 ] ) ,
sizeof( struct V_55 ) ) ;
}
return V_54 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_52 * V_58 )
{
struct V_59 * V_60 ;
F_9 ( sizeof( struct V_61 ) !=
sizeof( struct V_59 ) ) ;
V_58 -> V_62 = V_2 -> V_56 -> V_62 ;
V_60 = & ( V_2 -> V_56 -> V_63 ) ;
if ( V_60 -> V_64 <= 1 ) {
if ( V_60 -> V_65 == V_66 )
V_58 -> V_62 = V_67 ;
else if ( V_60 -> V_65 == V_68 )
V_58 -> V_62 = V_69 ;
else if ( V_60 -> V_65 == V_70 )
V_58 -> V_62 = V_71 ;
}
memcpy ( & ( V_58 -> V_63 ) , V_60 , sizeof( struct V_59 ) ) ;
return 0 ;
}
static int F_12 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
V_75 -> V_76 = V_73 -> V_76 ;
V_75 -> V_77 = V_73 -> V_77 ;
V_75 -> V_29 = V_73 -> V_29 ;
V_75 -> V_33 = V_73 -> V_33 ;
V_75 -> V_34 = V_73 -> V_34 ;
V_75 -> V_78 = V_73 -> V_78 ;
V_75 -> V_38 = V_73 -> V_38 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_21 = 0 ;
struct V_3 V_4 = {
. V_5 = V_6 ,
. V_7 = V_8 ,
. V_9 . V_10 . V_11 = V_2 -> V_12 ,
. V_9 . V_10 . type = V_79 ,
} ;
struct V_52 * V_53 ;
struct V_51 * V_54 = NULL ;
V_53 = & V_4 . V_9 . V_10 . V_80 ;
V_53 -> V_81 = V_2 -> V_82 ;
V_53 -> V_43 |= V_83 ;
F_12 ( & ( V_2 -> V_56 -> V_84 ) ,
& V_53 -> V_84 ) ;
F_12 ( & ( V_2 -> V_56 -> V_85 ) ,
& V_53 -> V_85 ) ;
V_53 -> V_43 |= V_86 ;
V_54 = F_8 ( V_2 , V_53 ) ;
if ( ! F_14 ( V_54 ) ) {
F_3 ( V_53 -> V_26 , V_54 ) ;
V_53 -> V_43 |= V_87 ;
}
if ( ! F_11 ( V_2 , V_53 ) )
V_53 -> V_43 |= V_88 ;
if ( V_53 -> V_43 != ( V_88 | V_87 | V_86 | V_83 ) ) {
F_15 ( L_5 ,
V_2 -> V_12 , V_53 -> V_43 ) ;
V_21 = - V_89 ;
goto V_90;
}
if ( ! V_48 )
V_21 = F_6 ( & V_4 ) ;
if ( ! V_21 ) {
struct V_91 * V_80 ;
unsigned int V_19 ;
V_80 = V_2 -> V_56 ;
F_4 ( L_6 , V_2 -> V_12 ) ;
for ( V_19 = 0 ; V_19 < V_80 -> V_57 ; V_19 ++ ) {
F_4 ( L_7 ,
( V_19 == V_80 -> V_92 ? '*' : ' ' ) , V_19 ,
( V_50 ) V_80 -> V_26 [ V_19 ] . V_93 ,
( V_50 ) V_80 -> V_26 [ V_19 ] . V_22 ,
( V_50 ) V_80 -> V_26 [ V_19 ] . V_94 ) ;
}
} else if ( V_21 != - V_42 )
F_15 ( L_8 ,
V_21 , V_2 -> V_12 ) ;
V_90:
if ( ! F_14 ( V_54 ) )
F_5 ( V_54 ) ;
return V_21 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_95 = 0 ;
F_17 ( & V_96 ) ;
if ( F_18 ( V_2 -> V_12 , V_97 ) ) {
F_19 ( & V_96 ) ;
return - V_98 ;
}
if ( V_2 -> V_43 . V_22 )
V_95 = F_1 ( V_2 ) ;
if ( V_2 -> V_56 && V_2 -> V_56 -> V_26 )
V_95 |= F_13 ( V_2 ) ;
F_19 ( & V_96 ) ;
return V_95 ;
}
static unsigned int T_1 F_20 ( void )
{
struct V_99 * V_100 ;
struct V_3 V_4 = {
. V_5 = V_101 ,
. V_7 = V_8 ,
} ;
int V_21 = 0 ;
unsigned int V_19 , V_102 , V_103 = 0 ;
V_100 = & V_4 . V_9 . V_104 ;
V_100 -> V_105 = 0 ;
V_21 = F_6 ( & V_4 ) ;
if ( V_21 )
return V_106 ;
V_102 = V_4 . V_9 . V_104 . V_107 ;
for ( V_19 = 0 ; V_19 <= V_102 ; V_19 ++ ) {
V_100 -> V_105 = V_19 ;
V_21 = F_6 ( & V_4 ) ;
if ( V_21 )
continue;
V_103 = F_21 ( V_100 -> V_12 , V_103 ) ;
}
V_103 *= 2 ;
F_4 ( L_9 , V_103 ) ;
return V_103 ;
}
static T_2
F_22 ( T_3 V_108 , V_50 V_109 , void * V_110 , void * * V_111 )
{
V_50 V_12 ;
T_2 V_112 ;
T_4 V_113 ;
unsigned long long V_114 ;
union V_115 V_116 = { 0 } ;
struct V_117 V_118 = { sizeof( union V_115 ) , & V_116 } ;
T_5 V_119 = 0 ;
V_112 = F_23 ( V_108 , & V_113 ) ;
if ( F_24 ( V_112 ) )
return V_120 ;
switch ( V_113 ) {
case V_121 :
V_112 = F_25 ( V_108 , NULL , NULL , & V_118 ) ;
if ( F_24 ( V_112 ) )
return V_120 ;
V_12 = V_116 . V_122 . V_123 ;
V_119 = V_116 . V_122 . V_124 ;
break;
case V_125 :
V_112 = F_26 ( V_108 , L_10 , NULL , & V_114 ) ;
if ( F_24 ( V_112 ) )
return V_120 ;
V_12 = V_114 ;
break;
default:
return V_120 ;
}
if ( V_12 > V_126 ) {
F_4 ( L_11 ,
V_126 , V_12 ) ;
return V_120 ;
}
F_27 ( V_12 , V_127 ) ;
F_4 ( L_12 , V_12 , ( unsigned long ) V_119 ) ;
V_112 = F_25 ( V_108 , L_13 , NULL , & V_118 ) ;
if ( F_24 ( V_112 ) ) {
if ( ! V_119 )
return V_120 ;
}
F_27 ( V_12 , V_128 ) ;
return V_120 ;
}
static int F_28 ( struct V_1 * V_129 )
{
if ( ! V_129 )
return - V_89 ;
if ( V_127 && V_128 )
goto V_130;
V_127 = F_2 ( F_29 ( V_126 ) , sizeof( unsigned long ) , V_24 ) ;
if ( ! V_127 )
return - V_25 ;
V_128 = F_2 ( F_29 ( V_126 ) , sizeof( unsigned long ) , V_24 ) ;
if ( ! V_128 ) {
F_5 ( V_127 ) ;
return - V_25 ;
}
F_30 ( V_121 , V_131 ,
V_132 ,
F_22 , NULL , NULL , NULL ) ;
F_31 ( L_14 , F_22 , NULL , NULL ) ;
V_130:
if ( ! F_32 ( V_127 , V_97 , V_126 ) ) {
unsigned int V_19 ;
F_33 (i, acpi_id_present, nr_acpi_bits) {
V_129 -> V_12 = V_19 ;
V_129 -> V_43 . V_22 = F_34 ( V_19 , V_128 ) ;
( void ) F_16 ( V_129 ) ;
}
}
return 0 ;
}
static int T_1 F_35 ( void )
{
struct V_133 * V_134 = & F_36 ( 0 ) ;
if ( ! F_37 () )
return - V_89 ;
if ( ! V_135 . V_136 )
return - V_89 ;
if ( V_134 -> V_137 == V_138 ) {
if ( ! F_38 ( V_134 , V_139 ) )
return - V_89 ;
return 0 ;
}
if ( V_134 -> V_137 == V_140 ) {
#define F_39 0x80000007
#define F_40 0x00000080
V_50 V_141 , V_142 , V_143 , V_144 ;
F_41 ( F_39 , & V_141 , & V_142 , & V_143 , & V_144 ) ;
if ( ( V_144 & F_40 ) != F_40 )
return - V_89 ;
return 0 ;
}
return - V_89 ;
}
static void F_42 ( void )
{
unsigned int V_19 ;
F_43 (i)
F_44 ( F_45 ( V_145 , V_19 )
-> V_146 ) ;
F_46 ( V_145 ) ;
}
static int F_47 ( void )
{
struct V_1 * V_129 = NULL ;
unsigned int V_19 ;
int V_147 = 0 ;
F_48 ( L_15 ) ;
F_43 (i) {
struct V_1 * V_2 ;
V_2 = F_49 ( V_148 , V_19 ) ;
if ( ! V_2 )
continue;
if ( ! V_129 ) {
V_129 = F_50 ( sizeof( struct V_1 ) , V_24 ) ;
if ( V_129 )
memcpy ( V_129 , V_2 , sizeof( struct V_1 ) ) ;
}
( void ) F_16 ( V_2 ) ;
}
V_147 = F_28 ( V_129 ) ;
F_5 ( V_129 ) ;
return V_147 ;
}
static void F_51 ( void )
{
F_52 ( V_97 , V_126 ) ;
F_47 () ;
}
static int T_1 F_53 ( void )
{
unsigned int V_19 ;
int V_147 = F_35 () ;
if ( V_147 )
return V_147 ;
V_126 = F_20 () + 1 ;
V_97 = F_2 ( F_29 ( V_126 ) , sizeof( unsigned long ) , V_24 ) ;
if ( ! V_97 )
return - V_25 ;
V_145 = F_54 ( struct V_91 ) ;
if ( ! V_145 ) {
F_4 ( L_16 ) ;
F_5 ( V_97 ) ;
return - V_25 ;
}
F_43 (i) {
if ( ! F_55 (
& F_45 ( V_145 , V_19 ) -> V_146 ,
V_24 , F_56 ( V_19 ) ) ) {
V_147 = - V_25 ;
goto V_149;
}
}
( void ) F_57 ( V_145 ) ;
F_43 (i) {
struct V_1 * V_150 ;
struct V_91 * V_80 ;
V_150 = F_49 ( V_148 , V_19 ) ;
V_80 = F_45 ( V_145 , V_19 ) ;
if ( ! V_150 )
continue;
V_150 -> V_56 = V_80 ;
V_147 = F_58 ( V_150 ) ;
if ( V_147 )
goto V_149;
}
V_147 = F_47 () ;
if ( V_147 )
goto V_151;
F_59 ( & V_152 ) ;
return 0 ;
V_151:
F_43 (i) {
struct V_91 * V_80 ;
V_80 = F_45 ( V_145 , V_19 ) ;
F_60 ( V_80 , V_19 ) ;
}
V_149:
F_42 () ;
F_5 ( V_97 ) ;
return V_147 ;
}
static void T_6 F_61 ( void )
{
int V_19 ;
F_62 ( & V_152 ) ;
F_5 ( V_97 ) ;
F_5 ( V_127 ) ;
F_5 ( V_128 ) ;
F_43 (i) {
struct V_91 * V_80 ;
V_80 = F_45 ( V_145 , V_19 ) ;
F_60 ( V_80 , V_19 ) ;
}
F_42 () ;
}

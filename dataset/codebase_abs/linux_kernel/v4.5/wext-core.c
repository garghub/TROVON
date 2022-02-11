void F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_3 ;
F_2 () ;
F_3 (net) {
while ( ( V_2 = F_4 ( & V_3 -> V_4 ) ) )
F_5 ( V_2 , V_3 , 0 , V_5 , NULL ,
V_6 ) ;
}
}
static int F_6 ( struct V_7 * V_8 ,
unsigned long V_9 , void * V_10 )
{
F_1 () ;
return V_11 ;
}
static int T_1 F_7 ( struct V_3 * V_3 )
{
F_8 ( & V_3 -> V_4 ) ;
return 0 ;
}
static void T_2 F_9 ( struct V_3 * V_3 )
{
F_10 ( & V_3 -> V_4 ) ;
}
static int T_3 F_11 ( void )
{
int V_12 = F_12 ( & V_13 ) ;
if ( V_12 )
return V_12 ;
return F_13 ( & V_14 ) ;
}
static void F_14 ( struct V_15 * V_16 )
{
F_15 () ;
F_1 () ;
F_16 () ;
}
static struct V_17 * F_17 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
struct V_20 * V_21 ;
struct V_17 * V_22 ;
V_22 = F_18 ( V_2 , 0 , 0 , V_23 , sizeof( * V_21 ) , 0 ) ;
if ( ! V_22 )
return NULL ;
V_21 = F_19 ( V_22 ) ;
V_21 -> V_24 = V_25 ;
V_21 -> V_26 = 0 ;
V_21 -> V_27 = V_19 -> type ;
V_21 -> V_28 = V_19 -> V_29 ;
V_21 -> V_30 = F_20 ( V_19 ) ;
V_21 -> V_31 = 0 ;
if ( F_21 ( V_2 , V_32 , V_19 -> V_33 ) )
goto V_34;
return V_22 ;
V_34:
F_22 ( V_2 , V_22 ) ;
return NULL ;
}
void F_23 ( struct V_18 * V_19 ,
unsigned int V_35 ,
union V_36 * V_37 ,
const char * V_38 )
{
const struct V_39 * V_40 = NULL ;
int V_41 = 0 ;
struct V_42 * V_43 ;
int V_44 ;
int V_45 ;
int V_46 = 0 ;
unsigned int V_47 ;
struct V_1 * V_2 ;
struct V_17 * V_22 ;
struct V_48 * V_49 ;
#ifdef F_24
struct V_50 * V_51 ;
struct V_52 V_53 ;
struct V_1 * V_54 ;
#endif
if ( F_25 ( V_35 == V_55 && V_38 ) )
V_38 = NULL ;
if ( V_35 <= V_56 ) {
V_47 = F_26 ( V_35 ) ;
if ( V_47 < V_57 )
V_40 = & ( V_58 [ V_47 ] ) ;
} else {
V_47 = F_27 ( V_35 ) ;
if ( V_47 < V_59 )
V_40 = & ( V_60 [ V_47 ] ) ;
}
if ( V_40 == NULL ) {
F_28 ( V_19 , L_1 ,
V_35 ) ;
return;
}
if ( V_40 -> V_61 == V_62 ) {
if ( V_37 -> V_63 . V_64 > V_40 -> V_65 ) {
F_28 ( V_19 , L_2 ,
V_35 , V_37 -> V_63 . V_64 ) ;
return;
}
if ( V_37 -> V_63 . V_64 < V_40 -> V_66 ) {
F_28 ( V_19 , L_3 ,
V_35 , V_37 -> V_63 . V_64 ) ;
return;
}
if ( V_38 != NULL )
V_41 = V_37 -> V_63 . V_64 * V_40 -> V_67 ;
V_46 = V_68 ;
}
V_45 = V_69 [ V_40 -> V_61 ] ;
V_44 = V_45 + V_41 ;
V_2 = F_29 ( V_70 , V_71 ) ;
if ( ! V_2 )
return;
V_22 = F_17 ( V_19 , V_2 ) ;
if ( F_25 ( ! V_22 ) ) {
F_30 ( V_2 ) ;
return;
}
V_49 = F_31 ( V_2 , V_72 , V_44 ) ;
if ( ! V_49 ) {
F_30 ( V_2 ) ;
return;
}
V_43 = F_32 ( V_49 ) ;
memset ( V_43 , 0 , V_45 ) ;
V_43 -> V_73 = V_44 ;
V_43 -> V_35 = V_35 ;
memcpy ( & V_43 -> V_74 , ( ( char * ) V_37 ) + V_46 , V_45 - V_75 ) ;
if ( V_41 )
memcpy ( ( ( char * ) V_43 ) + V_45 , V_38 , V_41 ) ;
F_33 ( V_2 , V_22 ) ;
#ifdef F_24
V_45 = V_76 [ V_40 -> V_61 ] ;
V_44 = V_45 + V_41 ;
V_54 = F_29 ( V_70 , V_71 ) ;
if ( ! V_54 ) {
F_30 ( V_2 ) ;
return;
}
V_22 = F_17 ( V_19 , V_54 ) ;
if ( F_25 ( ! V_22 ) ) {
F_30 ( V_2 ) ;
F_30 ( V_54 ) ;
return;
}
V_49 = F_31 ( V_54 , V_72 , V_44 ) ;
if ( ! V_49 ) {
F_30 ( V_2 ) ;
F_30 ( V_54 ) ;
return;
}
V_51 = F_32 ( V_49 ) ;
V_51 -> V_73 = V_44 ;
V_51 -> V_35 = V_35 ;
if ( V_40 -> V_61 == V_62 ) {
V_53 . V_64 = V_37 -> V_63 . V_64 ;
V_53 . V_77 = V_37 -> V_63 . V_77 ;
memcpy ( & V_51 -> V_78 ,
( ( char * ) & V_53 ) + V_79 ,
V_45 - V_80 ) ;
if ( V_41 )
memcpy ( ( ( char * ) V_51 ) + V_45 ,
V_38 , V_41 ) ;
} else {
memcpy ( & V_51 -> V_78 , V_37 ,
V_45 - V_80 ) ;
}
F_33 ( V_54 , V_22 ) ;
F_34 ( V_2 ) -> V_81 = V_54 ;
#endif
F_35 ( & F_36 ( V_19 ) -> V_4 , V_2 ) ;
F_37 ( & V_82 ) ;
}
struct V_83 * F_38 ( struct V_18 * V_19 )
{
#ifdef F_39
if ( ( V_19 -> V_84 != NULL ) &&
( V_19 -> V_84 -> F_38 != NULL ) )
return V_19 -> V_84 -> F_38 ( V_19 ) ;
#endif
#ifdef F_40
if ( V_19 -> V_85 &&
V_19 -> V_85 -> V_86 &&
V_19 -> V_85 -> V_86 -> V_87 &&
V_19 -> V_85 -> V_86 -> V_87 -> F_38 )
return V_19 -> V_85 -> V_86 -> V_87 -> F_38 ( V_19 ) ;
#endif
return NULL ;
}
static int F_41 ( struct V_18 * V_19 ,
struct V_88 * V_89 ,
union V_36 * V_37 ,
char * V_38 )
{
struct V_83 * V_90 ;
V_90 = F_38 ( V_19 ) ;
if ( V_90 ) {
memcpy ( V_38 , V_90 , sizeof( struct V_83 ) ) ;
V_37 -> V_63 . V_64 = sizeof( struct V_83 ) ;
if ( V_37 -> V_63 . V_77 != 0 )
V_90 -> V_91 . V_92 &= ~ V_93 ;
return 0 ;
} else
return - V_94 ;
}
static T_4 F_42 ( struct V_18 * V_19 , unsigned int V_35 )
{
unsigned int V_95 ;
const struct V_96 * V_97 = NULL ;
#ifdef F_40
if ( V_19 -> V_85 && V_19 -> V_85 -> V_86 )
V_97 = V_19 -> V_85 -> V_86 -> V_87 ;
#endif
#ifdef F_39
if ( V_19 -> V_84 )
V_97 = V_19 -> V_84 ;
#endif
if ( ! V_97 )
return NULL ;
V_95 = F_26 ( V_35 ) ;
if ( V_95 < V_97 -> V_98 )
return V_97 -> V_99 [ V_95 ] ;
#ifdef F_43
V_95 = V_35 - V_100 ;
if ( V_95 < V_97 -> V_101 )
return V_97 -> V_102 [ V_95 ] ;
#endif
return NULL ;
}
static int F_44 ( struct V_103 * V_104 , unsigned int V_35 ,
const struct V_39 * V_40 ,
T_4 V_105 , struct V_18 * V_19 ,
struct V_88 * V_89 )
{
int V_12 , V_106 , V_107 = 0 , V_108 = 0 ;
char * V_38 ;
V_106 = V_40 -> V_65 * V_40 -> V_67 ;
switch ( V_35 ) {
case V_109 :
case V_110 :
case V_111 :
case V_112 :
if ( V_104 -> V_64 == V_40 -> V_65 + 1 )
V_108 = 1 ;
else if ( F_45 ( V_35 ) && ( V_104 -> V_64 != 0 ) ) {
char V_113 [ V_114 + 1 ] ;
unsigned int V_73 ;
V_73 = V_104 -> V_64 * V_40 -> V_67 ;
if ( V_73 > V_114 )
return - V_115 ;
V_12 = F_46 ( V_113 , V_104 -> V_78 , V_73 ) ;
if ( V_12 )
return - V_115 ;
if ( V_113 [ V_104 -> V_64 - 1 ] == '\0' )
V_108 = 1 ;
}
break;
default:
break;
}
V_104 -> V_64 -= V_108 ;
if ( F_45 ( V_35 ) ) {
if ( ! V_104 -> V_78 && V_104 -> V_64 != 0 )
return - V_115 ;
if ( V_104 -> V_64 > V_40 -> V_65 )
return - V_116 ;
if ( V_104 -> V_64 < V_40 -> V_66 )
return - V_117 ;
} else {
if ( ! V_104 -> V_78 )
return - V_115 ;
V_107 = V_104 -> V_64 ;
if ( ( V_40 -> V_77 & V_118 ) &&
( V_107 > V_40 -> V_65 ) ) {
V_106 = V_107 * V_40 -> V_67 ;
}
}
V_38 = F_47 ( V_106 , V_6 ) ;
if ( ! V_38 )
return - V_119 ;
if ( F_45 ( V_35 ) && ( V_104 -> V_64 != 0 ) ) {
if ( F_46 ( V_38 , V_104 -> V_78 ,
V_104 -> V_64 *
V_40 -> V_67 ) ) {
V_12 = - V_115 ;
goto V_120;
}
if ( V_35 == V_121 ) {
struct V_122 * V_123 = ( void * ) V_38 ;
if ( V_104 -> V_64 < sizeof( * V_123 ) + V_123 -> V_124 ) {
V_12 = - V_115 ;
goto V_120;
}
}
}
if ( F_48 ( V_35 ) && ! ( V_40 -> V_77 & V_118 ) ) {
V_104 -> V_64 = V_40 -> V_65 ;
}
V_12 = V_105 ( V_19 , V_89 , (union V_36 * ) V_104 , V_38 ) ;
V_104 -> V_64 += V_108 ;
if ( ! V_12 && F_48 ( V_35 ) ) {
if ( V_107 < V_104 -> V_64 ) {
V_12 = - V_116 ;
goto V_120;
}
if ( F_49 ( V_104 -> V_78 , V_38 ,
V_104 -> V_64 *
V_40 -> V_67 ) ) {
V_12 = - V_115 ;
goto V_120;
}
}
if ( ( V_40 -> V_77 & V_125 ) &&
( ( V_12 == 0 ) || ( V_12 == - V_126 ) ) ) {
union V_36 * V_63 = (union V_36 * ) V_104 ;
if ( V_40 -> V_77 & V_127 )
F_23 ( V_19 , V_35 , V_63 , NULL ) ;
else
F_23 ( V_19 , V_35 , V_63 , V_38 ) ;
}
V_120:
F_50 ( V_38 ) ;
return V_12 ;
}
int F_51 ( struct V_18 * V_19 )
{
#ifdef F_39
if ( ( F_52 ( V_19 ) ) &&
( V_19 -> V_84 -> V_99 [ 0 ] != NULL ) )
return V_19 -> V_84 -> V_99 [ 0 ] ( V_19 , NULL ,
NULL , NULL ) ;
else
return 0 ;
#else
return 0 ;
#endif
}
static int F_53 ( struct V_3 * V_3 , struct V_128 * V_129 ,
unsigned int V_35 ,
struct V_88 * V_89 ,
T_5 V_99 ,
T_5 V_102 )
{
struct V_130 * V_131 = (struct V_130 * ) V_129 ;
struct V_18 * V_19 ;
T_4 V_105 ;
if ( ( V_19 = F_54 ( V_3 , V_129 -> V_132 ) ) == NULL )
return - V_133 ;
if ( V_35 == V_134 )
return V_99 ( V_19 , V_131 , V_35 , V_89 ,
& F_41 ) ;
#ifdef F_43
if ( V_35 == V_135 && V_19 -> V_84 )
return V_99 ( V_19 , V_131 , V_35 , V_89 ,
V_136 ) ;
#endif
if ( ! F_55 ( V_19 ) )
return - V_133 ;
V_105 = F_42 ( V_19 , V_35 ) ;
if ( V_105 ) {
if ( V_35 < V_100 )
return V_99 ( V_19 , V_131 , V_35 , V_89 , V_105 ) ;
else if ( V_102 )
return V_102 ( V_19 , V_131 , V_35 , V_89 , V_105 ) ;
}
if ( V_19 -> V_137 -> V_138 )
return V_19 -> V_137 -> V_138 ( V_19 , V_129 , V_35 ) ;
return - V_94 ;
}
static int F_56 ( unsigned int V_35 )
{
if ( ( F_45 ( V_35 ) || V_35 == V_139 ||
V_35 == V_140 ) &&
! F_57 ( V_141 ) )
return - V_142 ;
return 0 ;
}
static int F_58 ( struct V_3 * V_3 , struct V_128 * V_129 ,
unsigned int V_35 , struct V_88 * V_89 ,
T_5 V_99 ,
T_5 V_102 )
{
int V_143 = F_56 ( V_35 ) ;
if ( V_143 )
return V_143 ;
F_59 ( V_3 , V_129 -> V_132 ) ;
F_15 () ;
V_143 = F_53 ( V_3 , V_129 , V_35 , V_89 , V_99 , V_102 ) ;
F_16 () ;
return V_143 ;
}
static int F_60 ( struct V_18 * V_19 ,
struct V_130 * V_131 ,
unsigned int V_35 ,
struct V_88 * V_89 ,
T_4 V_105 )
{
const struct V_39 * V_40 ;
int V_143 = - V_117 ;
if ( F_26 ( V_35 ) >= V_57 )
return - V_94 ;
V_40 = & ( V_58 [ F_26 ( V_35 ) ] ) ;
if ( V_40 -> V_61 != V_62 ) {
V_143 = V_105 ( V_19 , V_89 , & ( V_131 -> V_74 ) , NULL ) ;
if ( ( V_40 -> V_77 & V_125 ) &&
( ( V_143 == 0 ) || ( V_143 == - V_126 ) ) )
F_23 ( V_19 , V_35 , & ( V_131 -> V_74 ) , NULL ) ;
} else {
V_143 = F_44 ( & V_131 -> V_74 . V_63 , V_35 , V_40 ,
V_105 , V_19 , V_89 ) ;
}
if ( V_143 == - V_126 )
V_143 = F_51 ( V_19 ) ;
return V_143 ;
}
int F_61 ( struct V_3 * V_3 , struct V_128 * V_129 , unsigned int V_35 ,
void T_6 * V_144 )
{
struct V_88 V_89 = { . V_35 = V_35 , . V_77 = 0 } ;
int V_143 ;
V_143 = F_58 ( V_3 , V_129 , V_35 , & V_89 ,
F_60 ,
V_145 ) ;
if ( V_143 >= 0 &&
F_48 ( V_35 ) &&
F_49 ( V_144 , V_129 , sizeof( struct V_130 ) ) )
return - V_115 ;
return V_143 ;
}
static int F_62 ( struct V_18 * V_19 ,
struct V_130 * V_131 ,
unsigned int V_35 ,
struct V_88 * V_89 ,
T_4 V_105 )
{
const struct V_39 * V_40 ;
struct V_52 * V_146 ;
struct V_103 V_104 ;
int V_12 ;
V_40 = V_58 + F_26 ( V_35 ) ;
if ( V_40 -> V_61 != V_62 )
return F_60 ( V_19 , V_131 , V_35 , V_89 , V_105 ) ;
V_146 = (struct V_52 * ) & V_131 -> V_74 . V_63 ;
V_104 . V_78 = F_63 ( V_146 -> V_78 ) ;
V_104 . V_64 = V_146 -> V_64 ;
V_104 . V_77 = V_146 -> V_77 ;
V_12 = F_44 ( & V_104 , V_35 , V_40 , V_105 , V_19 , V_89 ) ;
V_146 -> V_78 = F_64 ( V_104 . V_78 ) ;
V_146 -> V_64 = V_104 . V_64 ;
V_146 -> V_77 = V_104 . V_77 ;
return V_12 ;
}
int F_65 ( struct V_3 * V_3 , unsigned int V_35 ,
unsigned long V_144 )
{
void T_6 * V_147 = ( void T_6 * ) V_144 ;
struct V_88 V_89 ;
struct V_130 V_131 ;
char * V_148 ;
int V_143 ;
if ( F_46 ( & V_131 , V_147 , sizeof( struct V_130 ) ) )
return - V_115 ;
V_131 . V_132 [ V_149 - 1 ] = 0 ;
V_148 = strchr ( V_131 . V_132 , ':' ) ;
if ( V_148 )
* V_148 = 0 ;
V_89 . V_35 = V_35 ;
V_89 . V_77 = V_150 ;
V_143 = F_58 ( V_3 , (struct V_128 * ) & V_131 , V_35 , & V_89 ,
F_62 ,
V_151 ) ;
if ( V_143 >= 0 &&
F_48 ( V_35 ) &&
F_49 ( V_147 , & V_131 , sizeof( struct V_130 ) ) )
return - V_115 ;
return V_143 ;
}

static int T_1 F_1 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_2 ) ;
return 0 ;
}
static void T_2 F_3 ( struct V_1 * V_1 )
{
F_4 ( & V_1 -> V_2 ) ;
}
static int T_3 F_5 ( void )
{
return F_6 ( & V_3 ) ;
}
static void F_7 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_1 * V_1 ;
F_8 () ;
F_9 (net) {
while ( ( V_7 = F_10 ( & V_1 -> V_2 ) ) )
F_11 ( V_7 , V_1 , 0 , V_8 , NULL ,
V_9 ) ;
}
F_12 () ;
}
static struct V_10 * F_13 ( struct V_11 * V_12 ,
struct V_6 * V_7 )
{
struct V_13 * V_14 ;
struct V_10 * V_15 ;
V_15 = F_14 ( V_7 , 0 , 0 , V_16 , sizeof( * V_14 ) , 0 ) ;
if ( ! V_15 )
return NULL ;
V_14 = F_15 ( V_15 ) ;
V_14 -> V_17 = V_18 ;
V_14 -> V_19 = 0 ;
V_14 -> V_20 = V_12 -> type ;
V_14 -> V_21 = V_12 -> V_22 ;
V_14 -> V_23 = F_16 ( V_12 ) ;
V_14 -> V_24 = 0 ;
if ( F_17 ( V_7 , V_25 , V_12 -> V_26 ) )
goto V_27;
return V_15 ;
V_27:
F_18 ( V_7 , V_15 ) ;
return NULL ;
}
void F_19 ( struct V_11 * V_12 ,
unsigned int V_28 ,
union V_29 * V_30 ,
const char * V_31 )
{
const struct V_32 * V_33 = NULL ;
int V_34 = 0 ;
struct V_35 * V_36 ;
int V_37 ;
int V_38 ;
int V_39 = 0 ;
unsigned int V_40 ;
struct V_6 * V_7 ;
struct V_10 * V_15 ;
struct V_41 * V_42 ;
#ifdef F_20
struct V_43 * V_44 ;
struct V_45 V_46 ;
struct V_6 * V_47 ;
#endif
if ( F_21 ( V_28 == V_48 && V_31 ) )
V_31 = NULL ;
if ( V_28 <= V_49 ) {
V_40 = F_22 ( V_28 ) ;
if ( V_40 < V_50 )
V_33 = & ( V_51 [ V_40 ] ) ;
} else {
V_40 = F_23 ( V_28 ) ;
if ( V_40 < V_52 )
V_33 = & ( V_53 [ V_40 ] ) ;
}
if ( V_33 == NULL ) {
F_24 ( V_12 , L_1 ,
V_28 ) ;
return;
}
if ( V_33 -> V_54 == V_55 ) {
if ( V_30 -> V_56 . V_57 > V_33 -> V_58 ) {
F_24 ( V_12 , L_2 ,
V_28 , V_30 -> V_56 . V_57 ) ;
return;
}
if ( V_30 -> V_56 . V_57 < V_33 -> V_59 ) {
F_24 ( V_12 , L_3 ,
V_28 , V_30 -> V_56 . V_57 ) ;
return;
}
if ( V_31 != NULL )
V_34 = V_30 -> V_56 . V_57 * V_33 -> V_60 ;
V_39 = V_61 ;
}
V_38 = V_62 [ V_33 -> V_54 ] ;
V_37 = V_38 + V_34 ;
V_7 = F_25 ( V_63 , V_64 ) ;
if ( ! V_7 )
return;
V_15 = F_13 ( V_12 , V_7 ) ;
if ( F_21 ( ! V_15 ) ) {
F_26 ( V_7 ) ;
return;
}
V_42 = F_27 ( V_7 , V_65 , V_37 ) ;
if ( ! V_42 ) {
F_26 ( V_7 ) ;
return;
}
V_36 = F_28 ( V_42 ) ;
memset ( V_36 , 0 , V_38 ) ;
V_36 -> V_66 = V_37 ;
V_36 -> V_28 = V_28 ;
memcpy ( & V_36 -> V_67 , ( ( char * ) V_30 ) + V_39 , V_38 - V_68 ) ;
if ( V_34 )
memcpy ( ( ( char * ) V_36 ) + V_38 , V_31 , V_34 ) ;
F_29 ( V_7 , V_15 ) ;
#ifdef F_20
V_38 = V_69 [ V_33 -> V_54 ] ;
V_37 = V_38 + V_34 ;
V_47 = F_25 ( V_63 , V_64 ) ;
if ( ! V_47 ) {
F_26 ( V_7 ) ;
return;
}
V_15 = F_13 ( V_12 , V_47 ) ;
if ( F_21 ( ! V_15 ) ) {
F_26 ( V_7 ) ;
F_26 ( V_47 ) ;
return;
}
V_42 = F_27 ( V_47 , V_65 , V_37 ) ;
if ( ! V_42 ) {
F_26 ( V_7 ) ;
F_26 ( V_47 ) ;
return;
}
V_44 = F_28 ( V_42 ) ;
V_44 -> V_66 = V_37 ;
V_44 -> V_28 = V_28 ;
if ( V_33 -> V_54 == V_55 ) {
V_46 . V_57 = V_30 -> V_56 . V_57 ;
V_46 . V_70 = V_30 -> V_56 . V_70 ;
memcpy ( & V_44 -> V_71 ,
( ( char * ) & V_46 ) + V_72 ,
V_38 - V_73 ) ;
if ( V_34 )
memcpy ( ( ( char * ) V_44 ) + V_38 ,
V_31 , V_34 ) ;
} else {
memcpy ( & V_44 -> V_71 , V_30 ,
V_38 - V_73 ) ;
}
F_29 ( V_47 , V_15 ) ;
F_30 ( V_7 ) -> V_74 = V_47 ;
#endif
F_31 ( & F_32 ( V_12 ) -> V_2 , V_7 ) ;
F_33 ( & V_75 ) ;
}
struct V_76 * F_34 ( struct V_11 * V_12 )
{
#ifdef F_35
if ( ( V_12 -> V_77 != NULL ) &&
( V_12 -> V_77 -> F_34 != NULL ) )
return V_12 -> V_77 -> F_34 ( V_12 ) ;
#endif
#ifdef F_36
if ( V_12 -> V_78 &&
V_12 -> V_78 -> V_79 &&
V_12 -> V_78 -> V_79 -> V_80 &&
V_12 -> V_78 -> V_79 -> V_80 -> F_34 )
return V_12 -> V_78 -> V_79 -> V_80 -> F_34 ( V_12 ) ;
#endif
return NULL ;
}
static int F_37 ( struct V_11 * V_12 ,
struct V_81 * V_82 ,
union V_29 * V_30 ,
char * V_31 )
{
struct V_76 * V_83 ;
V_83 = F_34 ( V_12 ) ;
if ( V_83 ) {
memcpy ( V_31 , V_83 , sizeof( struct V_76 ) ) ;
V_30 -> V_56 . V_57 = sizeof( struct V_76 ) ;
if ( V_30 -> V_56 . V_70 != 0 )
V_83 -> V_84 . V_85 &= ~ V_86 ;
return 0 ;
} else
return - V_87 ;
}
static T_4 F_38 ( struct V_11 * V_12 , unsigned int V_28 )
{
unsigned int V_88 ;
const struct V_89 * V_90 = NULL ;
#ifdef F_36
if ( V_12 -> V_78 && V_12 -> V_78 -> V_79 )
V_90 = V_12 -> V_78 -> V_79 -> V_80 ;
#endif
#ifdef F_35
if ( V_12 -> V_77 )
V_90 = V_12 -> V_77 ;
#endif
if ( ! V_90 )
return NULL ;
V_88 = F_22 ( V_28 ) ;
if ( V_88 < V_90 -> V_91 )
return V_90 -> V_92 [ V_88 ] ;
#ifdef F_39
V_88 = V_28 - V_93 ;
if ( V_88 < V_90 -> V_94 )
return V_90 -> V_95 [ V_88 ] ;
#endif
return NULL ;
}
static int F_40 ( struct V_96 * V_97 , unsigned int V_28 ,
const struct V_32 * V_33 ,
T_4 V_98 , struct V_11 * V_12 ,
struct V_81 * V_82 )
{
int V_99 , V_100 , V_101 = 0 , V_102 = 0 ;
char * V_31 ;
V_100 = V_33 -> V_58 * V_33 -> V_60 ;
switch ( V_28 ) {
case V_103 :
case V_104 :
case V_105 :
case V_106 :
if ( V_97 -> V_57 == V_33 -> V_58 + 1 )
V_102 = 1 ;
else if ( F_41 ( V_28 ) && ( V_97 -> V_57 != 0 ) ) {
char V_107 [ V_108 + 1 ] ;
unsigned int V_66 ;
V_66 = V_97 -> V_57 * V_33 -> V_60 ;
if ( V_66 > V_108 )
return - V_109 ;
V_99 = F_42 ( V_107 , V_97 -> V_71 , V_66 ) ;
if ( V_99 )
return - V_109 ;
if ( V_107 [ V_97 -> V_57 - 1 ] == '\0' )
V_102 = 1 ;
}
break;
default:
break;
}
V_97 -> V_57 -= V_102 ;
if ( F_41 ( V_28 ) ) {
if ( ! V_97 -> V_71 && V_97 -> V_57 != 0 )
return - V_109 ;
if ( V_97 -> V_57 > V_33 -> V_58 )
return - V_110 ;
if ( V_97 -> V_57 < V_33 -> V_59 )
return - V_111 ;
} else {
if ( ! V_97 -> V_71 )
return - V_109 ;
V_101 = V_97 -> V_57 ;
if ( ( V_33 -> V_70 & V_112 ) &&
( V_101 > V_33 -> V_58 ) ) {
V_100 = V_101 * V_33 -> V_60 ;
}
}
V_31 = F_43 ( V_100 , V_9 ) ;
if ( ! V_31 )
return - V_113 ;
if ( F_41 ( V_28 ) && ( V_97 -> V_57 != 0 ) ) {
if ( F_42 ( V_31 , V_97 -> V_71 ,
V_97 -> V_57 *
V_33 -> V_60 ) ) {
V_99 = - V_109 ;
goto V_114;
}
if ( V_28 == V_115 ) {
struct V_116 * V_117 = ( void * ) V_31 ;
if ( V_97 -> V_57 < sizeof( * V_117 ) + V_117 -> V_118 ) {
V_99 = - V_109 ;
goto V_114;
}
}
}
if ( F_44 ( V_28 ) && ! ( V_33 -> V_70 & V_112 ) ) {
V_97 -> V_57 = V_33 -> V_58 ;
}
V_99 = V_98 ( V_12 , V_82 , (union V_29 * ) V_97 , V_31 ) ;
V_97 -> V_57 += V_102 ;
if ( ! V_99 && F_44 ( V_28 ) ) {
if ( V_101 < V_97 -> V_57 ) {
V_99 = - V_110 ;
goto V_114;
}
if ( F_45 ( V_97 -> V_71 , V_31 ,
V_97 -> V_57 *
V_33 -> V_60 ) ) {
V_99 = - V_109 ;
goto V_114;
}
}
if ( ( V_33 -> V_70 & V_119 ) &&
( ( V_99 == 0 ) || ( V_99 == - V_120 ) ) ) {
union V_29 * V_56 = (union V_29 * ) V_97 ;
if ( V_33 -> V_70 & V_121 )
F_19 ( V_12 , V_28 , V_56 , NULL ) ;
else
F_19 ( V_12 , V_28 , V_56 , V_31 ) ;
}
V_114:
F_46 ( V_31 ) ;
return V_99 ;
}
int F_47 ( struct V_11 * V_12 )
{
#ifdef F_35
if ( ( F_48 ( V_12 ) ) &&
( V_12 -> V_77 -> V_92 [ 0 ] != NULL ) )
return V_12 -> V_77 -> V_92 [ 0 ] ( V_12 , NULL ,
NULL , NULL ) ;
else
return 0 ;
#else
return 0 ;
#endif
}
static int F_49 ( struct V_1 * V_1 , struct V_122 * V_123 ,
unsigned int V_28 ,
struct V_81 * V_82 ,
T_5 V_92 ,
T_5 V_95 )
{
struct V_124 * V_125 = (struct V_124 * ) V_123 ;
struct V_11 * V_12 ;
T_4 V_98 ;
if ( ( V_12 = F_50 ( V_1 , V_123 -> V_126 ) ) == NULL )
return - V_127 ;
if ( V_28 == V_128 )
return V_92 ( V_12 , V_125 , V_28 , V_82 ,
& F_37 ) ;
#ifdef F_39
if ( V_28 == V_129 && V_12 -> V_77 )
return V_92 ( V_12 , V_125 , V_28 , V_82 ,
V_130 ) ;
#endif
if ( ! F_51 ( V_12 ) )
return - V_127 ;
V_98 = F_38 ( V_12 , V_28 ) ;
if ( V_98 ) {
if ( V_28 < V_93 )
return V_92 ( V_12 , V_125 , V_28 , V_82 , V_98 ) ;
else if ( V_95 )
return V_95 ( V_12 , V_125 , V_28 , V_82 , V_98 ) ;
}
if ( V_12 -> V_131 -> V_132 )
return V_12 -> V_131 -> V_132 ( V_12 , V_123 , V_28 ) ;
return - V_87 ;
}
static int F_52 ( unsigned int V_28 )
{
if ( ( F_41 ( V_28 ) || V_28 == V_133 ||
V_28 == V_134 ) &&
! F_53 ( V_135 ) )
return - V_136 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_1 , struct V_122 * V_123 ,
unsigned int V_28 , struct V_81 * V_82 ,
T_5 V_92 ,
T_5 V_95 )
{
int V_137 = F_52 ( V_28 ) ;
if ( V_137 )
return V_137 ;
F_55 ( V_1 , V_123 -> V_126 ) ;
F_8 () ;
V_137 = F_49 ( V_1 , V_123 , V_28 , V_82 , V_92 , V_95 ) ;
F_12 () ;
return V_137 ;
}
static int F_56 ( struct V_11 * V_12 ,
struct V_124 * V_125 ,
unsigned int V_28 ,
struct V_81 * V_82 ,
T_4 V_98 )
{
const struct V_32 * V_33 ;
int V_137 = - V_111 ;
if ( F_22 ( V_28 ) >= V_50 )
return - V_87 ;
V_33 = & ( V_51 [ F_22 ( V_28 ) ] ) ;
if ( V_33 -> V_54 != V_55 ) {
V_137 = V_98 ( V_12 , V_82 , & ( V_125 -> V_67 ) , NULL ) ;
if ( ( V_33 -> V_70 & V_119 ) &&
( ( V_137 == 0 ) || ( V_137 == - V_120 ) ) )
F_19 ( V_12 , V_28 , & ( V_125 -> V_67 ) , NULL ) ;
} else {
V_137 = F_40 ( & V_125 -> V_67 . V_56 , V_28 , V_33 ,
V_98 , V_12 , V_82 ) ;
}
if ( V_137 == - V_120 )
V_137 = F_47 ( V_12 ) ;
return V_137 ;
}
int F_57 ( struct V_1 * V_1 , struct V_122 * V_123 , unsigned int V_28 ,
void T_6 * V_138 )
{
struct V_81 V_82 = { . V_28 = V_28 , . V_70 = 0 } ;
int V_137 ;
V_137 = F_54 ( V_1 , V_123 , V_28 , & V_82 ,
F_56 ,
V_139 ) ;
if ( V_137 >= 0 &&
F_44 ( V_28 ) &&
F_45 ( V_138 , V_123 , sizeof( struct V_124 ) ) )
return - V_109 ;
return V_137 ;
}
static int F_58 ( struct V_11 * V_12 ,
struct V_124 * V_125 ,
unsigned int V_28 ,
struct V_81 * V_82 ,
T_4 V_98 )
{
const struct V_32 * V_33 ;
struct V_45 * V_140 ;
struct V_96 V_97 ;
int V_99 ;
V_33 = V_51 + F_22 ( V_28 ) ;
if ( V_33 -> V_54 != V_55 )
return F_56 ( V_12 , V_125 , V_28 , V_82 , V_98 ) ;
V_140 = (struct V_45 * ) & V_125 -> V_67 . V_56 ;
V_97 . V_71 = F_59 ( V_140 -> V_71 ) ;
V_97 . V_57 = V_140 -> V_57 ;
V_97 . V_70 = V_140 -> V_70 ;
V_99 = F_40 ( & V_97 , V_28 , V_33 , V_98 , V_12 , V_82 ) ;
V_140 -> V_71 = F_60 ( V_97 . V_71 ) ;
V_140 -> V_57 = V_97 . V_57 ;
V_140 -> V_70 = V_97 . V_70 ;
return V_99 ;
}
int F_61 ( struct V_1 * V_1 , unsigned int V_28 ,
unsigned long V_138 )
{
void T_6 * V_141 = ( void T_6 * ) V_138 ;
struct V_81 V_82 ;
struct V_124 V_125 ;
char * V_142 ;
int V_137 ;
if ( F_42 ( & V_125 , V_141 , sizeof( struct V_124 ) ) )
return - V_109 ;
V_125 . V_126 [ V_143 - 1 ] = 0 ;
V_142 = strchr ( V_125 . V_126 , ':' ) ;
if ( V_142 )
* V_142 = 0 ;
V_82 . V_28 = V_28 ;
V_82 . V_70 = V_144 ;
V_137 = F_54 ( V_1 , (struct V_122 * ) & V_125 , V_28 , & V_82 ,
F_58 ,
V_145 ) ;
if ( V_137 >= 0 &&
F_44 ( V_28 ) &&
F_45 ( V_141 , & V_125 , sizeof( struct V_124 ) ) )
return - V_109 ;
return V_137 ;
}
